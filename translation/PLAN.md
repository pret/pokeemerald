# Master plan: Dutch translation of moves, abilities and items

## Context
(Style rules for the Dutch itself live in `CLAUDE.md`: simple Dutch for kids, short sentences, short words.)

`pokesmaragd/` is a pret pokeemerald decomp that is being translated into Dutch. Birch's intro is already done as a proof of concept.

The next goal is to give these Dutch names **and** descriptions, so a Dutch player understands what they do:
- moves (354)
- abilities (77)
- items (~377, berries included)

These stay English: Pokémon names, character names, and town/route/place names (decided: easy to look up, and the Dutch anime keeps them English too).

No official Dutch Gen 3 names exist, so the names are our own. They have to:
- be consistent everywhere,
- fit hard name-length limits,
- fit pixel-width limits in the UI boxes.

## Approach: glossary files + apply/check scripts, then batches

Work happens in reviewable glossary tables, not by hand-editing hundreds of C strings. Scripts write the tables back into the source and check every string before building.

### Batch 0: tooling (new folder `translation/`, not part of the build)
- `translation/nl/*.tsv` holds one glossary per category: `abilities.tsv`, `moves.tsv`, `items.tsv`, `berries.tsv`, `misc.tsv`.
  - Columns: `key | english | dutch | notes`.
  - The key is the source identifier, e.g. `MOVE_THUNDERBOLT` or `sThunderboltDescription`.
  - Descriptions keep `\n` line breaks in the text.
- `translation/extract.py` fills the TSVs with the current English text from:
  - `src/data/text/move_names.h` (`[MOVE_X] = _("...")`)
  - `src/data/text/move_descriptions.h` (`sXDescription[] = _("l1\n" "l2")`)
  - `src/data/text/abilities.h` (names in `gAbilityNames`, 1-line descriptions)
  - `src/data/items.h` (`.name = _("...")` inside `[ITEM_X] = {` blocks)
  - `src/data/text/item_descriptions.h` (`sXDesc[]`, up to 3 lines)
  - `src/berry.c` (berry `.name` + `sBerryDescriptionPart1_/Part2_`)
- `translation/apply.py` writes every non-empty `dutch` cell back into the matching source string, touching only the string literal. Empty cells stay English, so batches can be partial.
- `translation/check.py` validates every Dutch string before `make`:
  - **Character set:** every character must exist in `charmap.txt`. Braces like `{PKMN}` are allowed.
  - **Name lengths:**
    - moves: max 12 characters
    - abilities: max 12 characters
    - items: max **13** (`ITEM_NAME_LENGTH` 14 includes the terminator)
    - berries: max 6 (`BERRY_NAME_LENGTH`)
  - **Pixel widths:** computed from the glyph tables in `src/fonts.c` (`gFontNormalLatinGlyphWidths`, `gFontNarrowLatinGlyphWidths`) mapped via `charmap.txt`. Limits per string type:

    | String | Font | Limit | Window source |
    |---|---|---|---|
    | Move name in battle menu | narrow | ≤ 64 px | `src/battle_bg.c:192` |
    | Move name in summary screen | normal | ≤ 72 px | `src/pokemon_summary_screen.c:680` |
    | Move description | normal | 2 lines, each ≤ ~154 px | `pokemon_summary_screen.c:698` |
    | Ability description | normal | 1 line ≤ 144 px | `pokemon_summary_screen.c:611` |
    | Item description | normal | 3 lines, each ≤ ~109 px | `src/item_menu.c:404` |
    | Item name in bag list | narrow | fits before the quantity at 119 px | `item_menu.c:975` |
    | TM entry `No01 NAME` | — | must fit the same bag row | |
    | Berry description | normal | each part 1 line ≤ 200 px | `src/berry_tag_screen.c:123` |

  - Output is a list of violations with the measured width, and a non-zero exit code if any.
- Safety net: the default agbcc build uses `-Werror`, so an overlong name array is already a hard build error.
- Run `extract.py` once, commit the English baseline TSVs plus the scripts.

### Translation conventions (apply to all batches)
- **Capitals** as in Gen 3 English: `DONDERFLITS`, `DRANKJE`, `SUPERDRANKJE`.
- **Type words** are translated where they're part of a name (VUUR, WATER, GRAS, ELEKTRISCH…), consistently.
- **Stat words**, used in descriptions:

  | English | Dutch |
  |---|---|
  | ATTACK | AANVAL |
  | DEFENSE | VERDEDIGING |
  | SPEED | SNELHEID |
  | SP. ATK | SP. AANV |
  | SP. DEF | SP. VERD |
  | ACCURACY | PRECISIE |
  | EVASION | ONTWIJKING |

  These are logged in `misc.tsv` as the glossary. If they're too wide, abbreviate them consistently (e.g. VERD.).
- **"POKéMON", "BALL", "TM/HM"** stay as is. POKé BALL stays POKé BALL, and ball names become e.g. SUPERBALL, HYPERBALL, MEESTERBALL.
- **Berries:** names like CHERI stay (proper names). The suffix " BERRY"/" BERRIES" becomes " BES"/" BESSEN".
  - Locations: `src/battle_message.c:483` `sText_BerrySuffix`, `src/strings.c:1819-1821` and `:705`.
  - Respect `STATIC_ASSERT` at `battle_message.c:2310`.
- **Too long?** Choose a shorter synonym first, a clear abbreviation second. Never cut words mid-way silently.

### Batches (each ends with: check.py → make → in-game review → commit)
1. **Abilities**: 77 names + 77 descriptions. This is the smallest set and validates the tooling end-to-end.
2. **Moves A**: `MOVE_POUND` … ~`MOVE_SNORE` (first half), names + descriptions.
3. **Moves B**: remaining moves. Contest effect descriptions (`data/text/contest_strings.inc`, tables in `src/data/contest_text_tables.h`) share the summary-screen window and are translated here too, edited directly since there are few.
4. **Items A**: Poké Balls, medicine, battle items, evolution stones, held items, mail.
5. **Items B**: key items (incl. their descriptions) and TM/HM descriptions. TM names automatically show the Dutch move name.
6. **Berries**: suffix, descriptions, firmness words (`src/strings.c:304+`), "FIRM /" label (`strings.c:300`).
7. **Hardcoded duplicates in C**, so the UI matches the glossary:
   - bag pocket names (`strings.c:283-285`)
   - `gText_PokeBalls` plural (used by `CopyItemNameHandlePlural`, `src/item.c:84`)
   - flute/shard/fossil/DEEPSEA strings (`strings.c:659-678, 746-747, 817-821`)
   - vending machine drinks (`strings.c:648-650`)
   - `sText_EnigmaBerry` (`battle_message.c:482`)
   - "{POKEBLOCK} CASE" (`src/berry_blender.c:290-292`)

**Deliberately deferred to the later dialogue phase:**
- Item and move names written literally inside map scripts and dialogue (~314 item hits in 98 files, ~175 move hits, many of them false positives like "TRICK HOUSE").
- Battle messages ("X used Y!").

Until then dialogue is English text with Dutch names inserted where the game fills them in automatically (`giveitem`/`bufferitemname`), which already reads fine. The glossary TSVs become the reference for that phase.

### Workflow per batch
- Claude fills the `dutch` column of the batch's rows, runs `check.py` and fixes violations, runs `apply.py` + `make`.
- The user reviews:
  - the TSV diff (readable side by side, English | Dutch),
  - a short in-game check.
- Then a commit on branch `nl-translation`, one commit per batch.
- Feedback on wording goes into the TSV and gets re-applied, so changing a name later is a one-cell edit + re-apply.

## Critical files
- **New:** `translation/extract.py`, `apply.py`, `check.py`, `translation/nl/*.tsv`
- **Modified (via apply):**
  - `src/data/text/abilities.h`
  - `src/data/text/move_names.h`
  - `src/data/text/move_descriptions.h`
  - `src/data/items.h`
  - `src/data/text/item_descriptions.h`
  - `src/berry.c`
- **Modified (by hand, batches 3/6/7):**
  - `src/strings.c`
  - `src/battle_message.c`
  - `src/berry_blender.c`
  - `data/text/contest_strings.inc`

## Verification
- **Tooling sanity check:** after batch 0, run `extract.py` → `apply.py` with English only. That must give a zero git diff in `src/`, and `make` must still reproduce the original SHA1. (Stash the Birch intro or compare only the affected files.)
- **Every batch:** `python3 translation/check.py` passes, and `make` succeeds (`-Werror` catches overlong names).
- **In-game checks in mGBA** (new game, or a save with a few Pokémon and items):

  | Batch | What to look at |
  |---|---|
  | Abilities | Summary screen, page 1 (ability name + description) |
  | Moves | Summary moves page (names + descriptions), battle move menu, contest description toggle |
  | Items | Bag (every pocket, incl. the TM/HM pocket `No01 …` rows), a Poké Mart buy list, "obtained X" message |
  | Berries | Berry tag screen (name, firmness, both description lines), berry pocket |

## Status (2026-10-07)
- [x] Batch 0: tooling, CLAUDE.md, glossary
- [x] Batch 1: abilities
- [x] Batch 2+3: moves + contest effect descriptions
- [x] Batch 4+5: items (incl. key items, TM/HM descriptions)
- [x] Batch 6: berries (names stay, "CHERI BES", descriptions, firmness, suffix)
- [x] Batch 7: hardcoded duplicates in `src/strings.c` / `src/battle_message.c` (pockets, flutes, shards, fossils, vending drinks)
- [ ] In-game review by the user
- [x] Battle messages (`battle.tsv`)
- [x] Trainer class names, type names, menus and system text in `src/strings.c`
- [ ] Later: dialogue phase (map scripts, Easy Chat words, decoration names, berry blender text, `{POKEBLOCK} CASE` in dialogue)

## Dialogue progress (area by area)
- [x] Littleroot Town (+ houses, lab), Route 101, Oldale Town, shared texts (Center, Mart, items, PC, save)
- [x] Route 103, Route 102, Petalburg City (+ gym)
- [x] Route 104, Petalburg Woods, Rustboro City (+ gym, DEVON, school)
- [x] Route 116, Rusturf Tunnel, Dewford Town (+ gym), Granite Cave, Routes 105-109
- [~] Slateport, Route 110, Mauville, Verdanturf, Routes 111-115 (partly done; finish with regex `^(SlateportCity|Route110|MauvilleCity|NewMauville|Route117|VerdanturfTown|Route11[1-5])`)
- [ ] Volcano area: `^(FallarborTown|MeteorFalls|MtChimney|JaggedPass|FieryPath|LavaridgeTown|DesertRuins|DesertUnderpass|MirageTower|ScorchedSlab|Route11[89]|Route12[01]|WeatherInstitute)`
- [ ] Fortree/Lilycove: `^(FortreeCity|LilycoveCity|MtPyre|Route12[23]|SafariZone|AquaHideout|MagmaHideout|ShoalCave)`
- [ ] Mossdeep to the League: `^(MossdeepCity|Route12[4-9]|Route13\d|SootopolisCity|CaveOfOrigin|SeafloorCavern|SkyPillar|PacifidlogTown|SealedChamber|EverGrandeCity|VictoryRoad|Underwater|AbandonedShip)`
- [ ] Post-game maps: `^(BattleFrontier|TrainerHill|SouthernIsland|FarawayIsland|BirthIsland|NavelRock|ArtisanCave|IslandCave|AncientTomb|MarineCave|TerraCave|AlteringCave)`
- [ ] Shared texts, one TSV each: `text/tv`, `text/match_call`, `text/apprentice`, other `text/*`, `scripts/*` (see `next_package.py --summary`)
- [ ] Leftover maps: run `next_package.py --summary` and do what's left
