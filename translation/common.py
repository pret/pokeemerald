"""Shared helpers for the Dutch translation tooling.

Every translatable string is a Source entry: a key, the raw C text (with
literal backslash escapes such as \\n), the file it lives in, and the span of
the `_(...)` contents so it can be rewritten in place.
"""
import csv
import re
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TSV_DIR = ROOT / "translation" / "nl"
TSV_FIELDS = ["key", "english", "dutch", "notes"]


@dataclass
class Kind:
    name: str
    max_bytes: int | None  # encoded length, terminator excluded
    max_lines: int
    limits: list  # (font, max px per line, where it is shown)


# Pixel limits come from the window templates (see translation/PLAN.md) and
# are never below the widest English string, which is known to fit.
KINDS = {
    "move_name": Kind("move_name", 12, 1, [("narrow", 64, "battle move menu"),
                                            ("normal", 72, "summary moves page")]),
    "move_desc": Kind("move_desc", None, 2, [("normal", 154, "summary move description")]),
    "ability_name": Kind("ability_name", 12, 1, [("normal", 144, "summary info page")]),
    "ability_desc": Kind("ability_desc", None, 1, [("normal", 144, "summary info page")]),
    "item_name": Kind("item_name", 13, 1, [("narrow", 112, "bag/shop list"),
                                            ("normal", 80, "summary held item")]),
    "item_desc": Kind("item_desc", None, 3, [("normal", 109, "bag description")]),
    "berry_name": Kind("berry_name", 6, 1, [("normal", 64, "berry tag")]),
    "berry_desc": Kind("berry_desc", None, 1, [("normal", 200, "berry tag")]),
    "contest_desc": Kind("contest_desc", None, 2, [("normal", 154, "summary move description")]),
    "battle_msg": Kind("battle_msg", None, 99, [("normal", 208, "battle text box")]),
    "dialogue": Kind("dialogue", None, 99, [("normal", 208, "text box")]),
    "ui": Kind("ui", None, 99, [("normal", 208, "text box")]),
    "type_name": Kind("type_name", 6, 1, [("normal", 36, "TYPE/ in battle menu")]),
    "trainer_class": Kind("trainer_class", 12, 1, [("normal", 78, "trainer class in messages")]),
    "battle_type_move": Kind("battle_type_move", 16, 1, [("normal", 208, "battle text box")]),
}

LIT = r'"(?:[^"\\]|\\.)*"'
# `_(` + one or more string literals + `)`; group 1 is the inside of the parens
CALL = rf'_\(((?:\s*{LIT})+\s*)\)'


@dataclass
class Spec:
    tsv: str
    kind: str
    path: str
    pattern: str  # group "key" + group "body" (the inside of `_( ... )`, or the .string lines)
    key_fmt: str = "{}"
    style: str = "c"  # "c" for _("...") strings, "inc" for `.string "...$"` lines
    section_end: str | None = None  # only scan the file up to this marker
    exclude: tuple = ()  # file paths a glob `path` must skip


INC_ENTRY = rf'^(?P<key>gText_\w+)::\n(?P<body>(?:\t\.string {LIT}\n)+)'
# any label (`Foo:` or `Foo::`) directly followed by .string lines
INC_LABEL = rf'^(?P<key>\w+)::?\n(?P<body>(?:\t\.string {LIT}\n)+)'


SPECS = [
    Spec("abilities", "ability_name", "src/data/text/abilities.h",
         rf'\[(?P<key>ABILITY_\w+)\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("abilities", "ability_desc", "src/data/text/abilities.h",
         rf'static const u8 (?P<key>s\w+Description)\[\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("moves", "move_name", "src/data/text/move_names.h",
         rf'\[(?P<key>MOVE_\w+)\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("moves", "move_desc", "src/data/text/move_descriptions.h",
         rf'static const u8 (?P<key>s\w+Description)\[\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("items", "item_name", "src/data/items.h",
         rf'\[(?P<key>ITEM_\w+)\] =\s*\{{\s*\.name = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("items", "item_desc", "src/data/text/item_descriptions.h",
         rf'static const u8 (?P<key>s\w+Desc)\[\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("berries", "berry_name", "src/berry.c",
         rf'\[(?P<key>ITEM_\w+) - FIRST_BERRY_INDEX\] =\s*\{{\s*\.name = _\((?P<body>(?:\s*{LIT})+\s*)\)',
         "BERRYNAME_{}"),
    Spec("berries", "berry_desc", "src/berry.c",
         rf'static const u8 (?P<key>sBerryDescriptionPart\d_\w+)\[\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("contest", "contest_desc", "data/text/contest_strings.inc", INC_ENTRY,
         style="inc", section_end="@ Unused move names"),
    Spec("battle", "battle_msg", "src/battle_message.c",
         rf'^(?:static )?const u8 (?P<key>[sg]Text_\w+)\[\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("trainers", "trainer_class", "src/data/text/trainer_class_names.h",
         rf'\[(?P<key>TRAINER_CLASS_\w+)\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("types", "type_name", "src/battle_main.c",
         rf'\[(?P<key>TYPE_\w+)\] = _\((?P<body>(?:\s*{LIT})+\s*)\)', "TYPENAME_{}"),
    Spec("strings", "ui", "src/strings.c",
         rf'^(?:ALIGNED\(4\) )?(?:static )?const u8 (?P<key>(?!gJPText)\w+)\[\] = _\((?P<body>(?:\s*{LIT})+\s*)\)'),
    Spec("maps/{name}", "dialogue", "data/maps/*/scripts.inc", INC_LABEL, style="inc"),
    Spec("text/{name}", "dialogue", "data/text/*.inc", INC_LABEL, style="inc",
         exclude=("data/text/contest_strings.inc",)),
    Spec("scripts/{name}", "dialogue", "data/scripts/*.inc", INC_LABEL, style="inc"),
    Spec("battle", "battle_type_move", "src/battle_message.c",
         rf'\[(?P<key>TYPE_\w+)\]\s*= _\((?P<body>(?:\s*{LIT})+\s*)\)', "MOVETYPE_{}"),
]


@dataclass
class Entry:
    key: str
    text: str
    spec: Spec
    start: int  # span of the body inside the file
    end: int
    path: str = ""  # source file, relative to ROOT
    tsv: str = ""  # TSV name this entry belongs to


def body_to_text(body, style="c"):
    """Join the literals of a body into one raw string (.inc: without the final $)."""
    text = "".join(m[1:-1] for m in re.findall(LIT, body))
    return text[:-1] if style == "inc" and text.endswith("$") else text


def text_to_body(text, old_body, style="c"):
    """Render raw text back as literals, in the same layout as old_body."""
    if style == "inc":
        parts = re.split(r"(?<=\\[nlp])", text + "$")
        return "".join(f'\t.string "{p}"\n' for p in parts if p)
    if "\n" not in old_body:
        return f'"{text}"'
    indent = re.search(r'\n([ \t]*)"', old_body).group(1)
    lines = text.split("\\n")
    lits = [f'"{l}\\n"' for l in lines[:-1]] + [f'"{lines[-1]}"']
    return "".join(f"\n{indent}{l}" for l in lits)


def spec_files(spec):
    """(relative path, tsv name) for every file a spec covers."""
    if "*" not in spec.path:
        return [(spec.path, spec.tsv)]
    out = []
    for f in sorted(ROOT.glob(spec.path)):
        rel = f.relative_to(ROOT).as_posix()
        if rel in spec.exclude:
            continue
        name = f.parent.name if f.name == "scripts.inc" else f.stem
        out.append((rel, spec.tsv.format(name=name)))
    return out


def scan(spec):
    out = []
    for rel, tsv in spec_files(spec):
        src = (ROOT / rel).read_text(encoding="utf-8")
        if spec.section_end:
            src = src[:src.index(spec.section_end)]
        for m in re.finditer(spec.pattern, src, re.M):
            key = spec.key_fmt.format(m["key"])
            text = body_to_text(m["body"], spec.style)
            out.append(Entry(key, text, spec, m.start("body"), m.end("body"), rel, tsv))
    return out


def read_tsv(name):
    path = TSV_DIR / f"{name}.tsv"
    if not path.exists():
        return []
    with path.open(encoding="utf-8", newline="") as f:
        rows = csv.DictReader(f, delimiter="\t", quoting=csv.QUOTE_NONE, quotechar=None)
        return [{k: (v or "") for k, v in r.items()} for r in rows]


def write_tsv(name, rows):
    (TSV_DIR / f"{name}.tsv").parent.mkdir(parents=True, exist_ok=True)
    with (TSV_DIR / f"{name}.tsv").open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, TSV_FIELDS, delimiter="\t", quoting=csv.QUOTE_NONE,
                           quotechar=None, lineterminator="\n")
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in TSV_FIELDS})


# --- charmap + font widths -------------------------------------------------

def load_charmap():
    chars, tokens = {}, {}
    for line in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
        line = line.split("@")[0].strip()
        m = re.match(r"^'(.+)'\s*=\s*([0-9A-Fa-f ]+)$", line)
        if m:
            chars[m[1]] = [int(b, 16) for b in m[2].split()]
            if m[1] == "\\'":  # the apostrophe is written unescaped in C strings
                chars["'"] = chars[m[1]]
            continue
        m = re.match(r"^(\w+)\s*=\s*([0-9A-Fa-f ]+)$", line)
        if m:
            tokens[m[1]] = [int(b, 16) for b in m[2].split()]
    return chars, tokens


def load_widths():
    src = (ROOT / "src/fonts.c").read_text(encoding="utf-8")
    out = {}
    for font, sym in (("normal", "gFontNormalLatinGlyphWidths"),
                      ("narrow", "gFontNarrowLatinGlyphWidths")):
        body = re.search(sym + r"\[\] = \{(.*?)\};", src, re.S)[1]
        out[font] = [int(x) for x in re.findall(r"\d+", body)]
    return out


CHARS, TOKENS = load_charmap()
WIDTHS = load_widths()


def encode(text):
    """Encode raw C text to (bytes, errors). Escapes like \\n become one byte."""
    out, errors, i = [], [], 0
    while i < len(text):
        c = text[i]
        if c == "\\" and i + 1 < len(text):
            esc = "\\" + text[i + 1]
            if esc in CHARS:
                out += CHARS[esc]
            else:
                errors.append(f"unknown escape {esc}")
            i += 2
        elif c == "{":
            j = text.find("}", i)
            tok = text[i + 1:j].split()[0] if j > 0 else ""
            if tok in TOKENS:
                out += TOKENS[tok]
            else:
                errors.append(f"unknown token {{{tok}}}")
            i = j + 1 if j > 0 else len(text)
        else:
            if c in CHARS:
                out += CHARS[c]
            else:
                errors.append(f"character {c!r} not in charmap.txt")
            i += 1
    return out, errors


NAME = "N" * 10
PREFIX = "Vijandige "  # longest battle name prefix (sText_FoePkmnPrefix)


def placeholder_sample(token):
    """Worst-case text a {PLACEHOLDER} can expand to, or "" for formatting codes."""
    name = token.split()[0]
    if "WITH_PREFIX" in name:
        return globals()["PREFIX"] + NAME
    if "_PREFIX" in name:  # B_ATK_PREFIX1..3: the side, "Ally"/"Foe"
        return "het vijandige team"
    if "MOVE" in name or "ABILITY" in name:
        return "N" * 12
    if "ITEM" in name:
        return "N" * 13
    if "CLASS" in name:
        return "N" * 12
    if name in ("PLAYER", "RIVAL") or "PLAYER_NAME" in name or "TRAINER" in name and "NAME" in name \
            or "PARTNER_NAME" in name or "LINK_" in name and "NAME" in name:
        return "N" * 7
    if "NAME" in name or "BUFF" in name or name.startswith("STR_VAR") or name == "DYNAMIC" and token.split()[1:] == ["0"]:
        return NAME
    return ""


def split_lines(text):
    """Split on the line codes \\n, \\l and \\p."""
    return re.split(r"\\[nlp]", text)


def line_widths(text, font):
    """Pixel width of each line. Name placeholders count as their worst case."""
    widths = WIDTHS[font]
    out = []
    for line in split_lines(text):
        px = 0
        for part in re.split(r"(\{[^}]*\})", line):
            if part.startswith("{"):
                part = placeholder_sample(part[1:-1])
            seq = encode(part)[0]
            if seq and seq[0] < 0xF7:
                px += sum(widths[b] for b in seq)
        out.append(px)
    return out


def control_codes(text):
    """Sorted list of the {...} codes in a string."""
    return sorted(re.findall(r"\{[^}]*\}", text))
