# Pokémon Smaragd: Dutch translation of pokeemerald

pret's pokeemerald decomp, translated into Dutch for a Dutch kid (about 8-10 years old).
Build: `make` → PokemonSmaragd.gba. Test in mGBA (start a new game for intro text).
Branch `nl-translation`, one commit per batch. Progress and next package: `translation/PLAN.md` ("Dialogue progress").

## Hard rules
- **Never spawn subagents or parallel agents.** If you think one would help, ask me first. (Each one re-reads a large context and burns tokens.)
- Work sequentially in the main session. Translate one package, then stop and report.
- Do not echo translations back in chat. Write them straight to the output file.
- Read reference files once per session, not per package. Never read whole big TSVs or .inc files; use targeted grep (e.g. in items.tsv / moves.tsv).
- Never hand-edit strings a TSV manages. Edit the TSV (or fill file), then apply. Otherwise the next apply overwrites your change.
- One task per session.

## Workflow per package
A package is one area of the game (a group of maps) or one shared text file.

1. `python3 translation/next_package.py '<regex>' > /tmp/pkg.in.txt` lists untranslated `KEY<TAB>english` lines for maps/keys matching the regex (example: `^(LavaridgeTown|Route112)`).
2. Write Dutch to `/tmp/pkg.out.txt` (`KEY<TAB>dutch`, one line per input key). Append in chunks.
3. `python3 translation/check_fill.py /tmp/pkg.out.txt`. Fix until 0 problems.
4. `python3 translation/fill.py '*/*' /tmp/pkg.out.txt`, then `python3 translation/apply.py`, then `make`.
5. Commit, tick the package in PLAN.md, add new recurring terms to `translation/nl/misc.tsv`.
6. Stop and report. I review the TSV diff and test in mGBA.

For non-dialogue TSVs (items, moves, abilities, berries, battle, strings, types, natures, trainers, contest): fill the dutch column, run `python3 translation/check.py`, fix violations, then `apply.py` and `make`.

## Core style rules
- Simple, everyday Dutch, as you would explain it to a child. Short sentences, one idea each. Short words.
- Address the player with je/jij, never u.
- Translate the meaning, not word for word. Shorter is better if it says the same.
- Use one Dutch term per concept. Check `translation/nl/misc.tsv` before inventing a word.
- Keep every control code (`{PLAYER}`, `{STR_VAR_1}`, `\n`, `\l`, `\p`, `$`) exactly as in the English.
- Pokémon, character, town/route/place names stay English. Dialogue, menus, moves, abilities, items and berry texts get translated.
- Pixel width is authoritative (dialogue lines: as wide as the widest English line of that string, min. 208px). ~33 characters is only a rough guide. `check.py` / `check_fill.py` enforce bytes, characters and pixels, so fix what they report instead of guessing.

## Examples (English → bad → good)
Dialogue:
- `Your POKéMON look tired.\nGo to a POKéMON CENTER.`
  - Bad: `Uw POKéMON zijn zeer vermoeid.\nBegeef u naar een POKéMON CENTER.` (formal, rare words)
  - Good: `Je POKéMON zijn heel moe.\nGa naar een POKéMON CENTER.`
- `{PLAYER}, you're late!\pHurry up!`
  - Good: `{PLAYER}, je bent te laat!\pSnel, kom op!`

Move description (2 lines):
- `A powerful electric attack that may paralyze the foe.`
  - Bad: `Een krachtige elektrische aanval die de tegenstander mogelijk verlamt.` (too long, formal)
  - Good: `Sterke stroomaanval. Kan de\nvijand verlammen.`

Battle message (name first, no possessive 's):
- `{B_ATK_NAME_WITH_PREFIX} gebruikt\n{B_BUFF2}!`

(Examples are illustrative: always let the checker decide whether a line fits.)

## Read before touching other areas
- Wording, vocabulary, what stays English: `translation/docs/style.md`
- battle.tsv / `src/battle_message.c`: `translation/docs/battle.md`
- Moves, abilities, items, berries, UI/menu strings, byte and pixel limits, tooling details: `translation/docs/ui-limits.md`
