# Pokémon Smaragd: Dutch translation of pokeemerald

This repo is pret's pokeemerald decomp. We are translating the game into **Dutch**.
Build with `make` → `pokeemerald.gba`. Test in mGBA (start a new game for intro text).
Work happens on branch `nl-translation`, one commit per batch.

## Who we write for
The player is a **Dutch kid (about 8–10 years old)**. Every Dutch string must be easy for them to read.

- Use **simple, everyday Dutch**. Write the way you would explain it to a child, not the way a manual is written.
- **Short sentences.** One idea per sentence. Do not add words the English doesn't need.
- **Short words.** Avoid long compound words and formal or rare words.
  - Good: *maakt*, *helpt*, *raakt*, *soms*, *heel*
  - Bad: *bewerkstelligt*, *ondersteunt*, *frequent*, *aanzienlijk*
  - If a compound gets long, split or rephrase it: *kans op een voltreffer*, not *voltreffer­waarschijnlijkheid*.
- Address the player with **je/jij**, never u.
- Translate the **meaning**, not word for word. Shorter is better when it says the same thing.
- **Numbers:** keep them as numbers ("2 tot 5 keer").

## What gets translated and what stays English
| Stays English | Gets translated |
|---|---|
| Pokémon names (CHARIZARD), character names (BIRCH), POKéMON, POKé BALL, TM/HM, berry names (CHERI) | All dialogue and menus |
| Town, route and place names (LITTLEROOT, ROUTE 101, ABANDONED SHIP): easy to look up online, and the Dutch anime keeps them English too | Move names + descriptions |
| | Ability names + descriptions |
| | Item names + descriptions |
| | Berry descriptions, firmness, the word BERRY → BES / BESSEN |

## Style rules
- **Names** of moves, abilities and items are in CAPITALS, like Gen 3 English: `DONDERFLITS`, `DRANKJE`.
- **Inside descriptions and dialogue**, the words POKéMON and stat names are also in capitals, like the English.
- **One Dutch term per concept, everywhere.** The glossary is `translation/nl/misc.tsv` (stats, types, status effects, common words). Check it before inventing a new word, and add new recurring terms to it.
- When a name doesn't fit:
  1. choose a shorter synonym,
  2. else use a clear abbreviation (`SP. AANV`),
  3. never cut a word silently.

## Battle messages (`battle.tsv` → `src/battle_message.c`)
- **Name prefixes are separate strings** glued before `{B_*_NAME_WITH_PREFIX}`:
  - `Wilde `
  - `Vijandige `
  - nothing for your own POKéMON

  So **put the name first** in the sentence: `{B_ATK_NAME_WITH_PREFIX} gebruikt\n{B_BUFF2}` → "Wilde ZIGZAGOON gebruikt TACKLE!".
- `{B_ATK_PREFIX1/2/3}` expand to `jouw team` / `het vijandige team` (lowercase). Never put them at the start of a sentence.
- **No possessive 's.** Use "X van Y", or start with the name.
- **Stat changes** are `{NAME}: {STAT}\n{flink }{omhoog!|omlaag!}`, assembled by the game.
- **Present tense:** "gebruikt", "is verslagen", "gaat naar LV. 5!".
- **Ability messages:** "X laat het regenen met MOTREGEN!". When a line is too long, use "X gebruikt\nTALENT!\p" plus a new sentence.
- **Referee:** `SCHEIDS:`.
- **Control codes:** the Dutch must contain exactly the same `{...}` codes as the English; `check.py` enforces this.
- **Widths:** placeholders are measured at worst case (name with prefix = "Vijandige " + 10 letters). If a line is too wide, break it with `\l`. In the rare case where the worst case can't happen (e.g. a buffer that's always a digit), put `width-ok: <reason>` in the notes column.

## Technical limits (the check script enforces these)
| String | Limit |
|---|---|
| Move names | max 12 bytes |
| Ability names | max 12 bytes |
| Item names | max **13** bytes |
| Berry names | max 6 bytes |
| Move descriptions | 2 lines |
| Item descriptions | 3 lines |
| Ability descriptions | 1 line |
| Berry descriptions | 1 line per part |

- **Bytes, not characters:** most characters are 1 byte, `{PKMN}` is 2.
- Every line must also fit its box **in pixels**. `check.py` measures with the real font widths from `src/fonts.c`.
- **Allowed characters** are only those in `charmap.txt`. Dutch needs ë, ï, é, and these all exist. Do not use `"`, tabs, or curly apostrophes in C strings; use `'`.
- **Dialogue (`.string` in `.inc` files):** keep lines at most ~33 characters. Line-break codes:
  - `\n` starts a new line,
  - `\l` scrolls to the next line,
  - `\p` starts a new text box,
  - `$` ends the text.
- Keep control codes like `{PLAYER}`, `{STR_VAR_1}`, `{KUN}` exactly as they are.

## Translation tooling (`translation/`)
- `translation/nl/*.tsv` are the glossaries, with columns `key<TAB>english<TAB>dutch<TAB>notes`.
  - The `english` column is the source text, raw as it appears in C (with `\n`).
  - An empty `dutch` cell means "not translated yet"; that string stays English.
- `python3 translation/extract.py` refreshes the `english` column from the source and keeps existing `dutch`/`notes`.
- `python3 translation/check.py` validates all Dutch cells (characters, byte length, line count, pixel width). It must pass before building.
- `python3 translation/apply.py` writes the Dutch cells into the source files.
- `python3 translation/fill.py <tsv-name> <file>` bulk-fills Dutch cells from a `KEY<TAB>dutch` text file.
- Which source strings each TSV manages is defined in `SPECS` in `translation/common.py`. It supports both `_("...")` C strings and `.string "...$"` blocks in `.inc` files.
- `contest.tsv` holds the contest move effect descriptions (`data/text/contest_strings.inc`).
- `trainers.tsv` holds trainer class names (max 12 bytes). Team names, ELITE FOUR and Battle Frontier titles stay English.
- `battle.tsv` holds all strings in `src/battle_message.c` (battle messages, battle menu, stat names, Battle Frontier referee).
- `types.tsv` holds the type names (`gTypeNames`, max 6 bytes, e.g. "TYPE/VUUR" in the battle move menu).
- `strings.tsv` holds `src/strings.c` (menus, bag, PC, PokéNav, options, Mystery Gift…).
  - Place and attraction names stay English (BATTLE TOWER, TRADE CENTER, BERRY CRUSH).
  - Character names stay too, except MOM/DAD → MAMA/PAPA.
- **UI text windows are often small.** `check.py` prints `WARN` when narrow English UI text (≤130px) gets wider in Dutch.
  - For each warning, look up the window in the C code: `WindowTemplate .width` × 8px, minus the cursor or x offset. Many menus size themselves via `GetMaxWidthInMenuTable` / `DisplayTextAndGetWidth`.
  - Shorten the text if it doesn't fit, then run `python3 translation/review.py` to mark the remaining warnings `label-ok: reviewed`.
- **Notes-column markers** (in `check.py`):
  - `max:NNN` sets a pixel limit for that string.
  - `width-ok: <reason>` skips the width checks.
  - `label-ok` silences the narrow-window warning.
- **Known tight spots, with short forms in use:**

  | Where | Width | Short forms |
  |---|---|---|
  | Summary stat labels | 36-42px | VERD., SP.AAN, SP.VER, SNELH. |
  | Level-up box | 54px | VERD. |
  | Bag description box | 106px, 3 lines | |
  | PC box messages | 144px, 1 line | |
  | Options values | x=104-198 | TRAAG / NORM / SNEL |
  | Trainer card | value right-aligned at 216px | |

- `check.py` also verifies text fits before a `{CLEAR_TO n}` column.
- **Always edit the TSV, then apply.** Never hand-edit strings that a TSV manages (move/ability/item/berry names and descriptions), or the next apply will overwrite them.

## Workflow per batch
1. Fill the `dutch` column for the batch's rows, following the rules above.
2. Run `check.py`, fix violations, then run `apply.py` and `make`.
3. The user reviews the TSV diff and checks in-game in mGBA.
4. Commit on `nl-translation`.

The master plan with the batch order is in `translation/PLAN.md`.
