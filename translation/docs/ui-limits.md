# Limits, UI text and tooling

`check.py` enforces the limits below. Use this page to write correctly the first time, not to re-verify by hand.

## Technical limits
| String | Limit |
|---|---|
| Move names | max 12 bytes |
| Ability names | max 12 bytes |
| Item names | max 13 bytes |
| Berry names | max 6 bytes |
| Move descriptions | 2 lines |
| Item descriptions | 3 lines |
| Ability descriptions | 1 line |
| Berry descriptions | 1 line per part |

- Bytes, not characters: most characters are 1 byte, `{PKMN}` is 2.
- Every line must also fit its box in pixels. check.py measures with the real font widths from src/fonts.c.
- Allowed characters are only those in charmap.txt. ë, ï, é exist. Do not use `"`, tabs or curly apostrophes in C strings; use `'`.
- Dialogue (`.string` in .inc files): line-break codes are `\n` (new line), `\l` (scroll to next line), `\p` (new text box), `$` (end of text). Keep control codes like `{PLAYER}`, `{STR_VAR_1}`, `{KUN}` exactly as they are.
- Dialogue lines may be as wide as the widest English line of the same string (min. 208px).

## Translation tooling (translation/)
`translation/nl/*.tsv` are the glossaries: `key<TAB>english<TAB>dutch<TAB>notes`.
- The english column is the source text, raw as it appears in C (with `\n`).
- An empty dutch cell means "not translated yet"; that string stays English.
- `extract.py` refreshes the english column from the source and keeps existing dutch/notes.
- `check.py` validates all Dutch cells (characters, byte length, line count, pixel width). Must pass before building.
- `apply.py` writes the Dutch cells into the source files.
- `fill.py <tsv-name> <file>` bulk-fills Dutch cells from a `KEY<TAB>dutch` text file. `fill.py '*/*' file.txt` finds each key wherever it lives.
- `check_fill.py <file>` checks a fill file without writing anything.
- Which source strings each TSV manages is defined in SPECS in `translation/common.py` (supports `_("...")` C strings and `.string "...$"` blocks in .inc files).

TSV files:
- `contest.tsv`: contest move effect descriptions (data/text/contest_strings.inc)
- `trainers.tsv`: trainer class names (max 12 bytes)
- `battle.tsv`: see battle.md
- `types.tsv`: type names
- `strings.tsv`: src/strings.c (menus, bag, PC, PokéNav, options, Mystery Gift…)
- `natures.tsv`: nature names (NAÏEF, VROLIJK…)
- Dialogue, one TSV per file, keys are the script labels:
  - `maps/<MapName>.tsv` for data/maps/*/scripts.inc
  - `text/<name>.tsv` for data/text/*.inc (shared texts; `text/trainers.tsv` has every trainer's battle lines)
  - `scripts/<name>.tsv` for data/scripts/*.inc

## UI text windows
UI windows are often small. check.py prints WARN when narrow English UI text (≤130px) gets wider in Dutch.
- For each warning, look up the window in the C code: WindowTemplate `.width` × 8px, minus the cursor or x offset. Many menus size themselves via GetMaxWidthInMenuTable / DisplayTextAndGetWidth.
- Shorten the text if it doesn't fit, then run `python3 translation/review.py` to mark the remaining warnings `label-ok: reviewed`.
- check.py also verifies text fits before a `{CLEAR_TO n}` column.

Notes-column markers (in check.py):
- `max:NNN` sets a pixel limit for that string.
- `width-ok: <reason>` skips the width checks.
- `label-ok` silences the narrow-window warning.

Known tight spots, with short forms in use:
| Where | Width | Short forms |
|---|---|---|
| Summary stat labels | 36-42px | VERD., SP.AAN, SP.VER, SNELH. |
| Level-up box | 54px | VERD. |
| Bag description box | 106px, 3 lines | |
| PC box messages | 144px, 1 line | |
| Options values | x=104-198 | TRAAG / NORM / SNEL |
| Trainer card | value right-aligned at 216px | |
