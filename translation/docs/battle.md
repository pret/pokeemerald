# Battle messages (battle.tsv → src/battle_message.c)

- Name prefixes are separate strings glued before `{B_*_NAME_WITH_PREFIX}`: "Wilde", "Vijandige", or nothing for your own POKéMON. So put the name first in the sentence: `{B_ATK_NAME_WITH_PREFIX} gebruikt\n{B_BUFF2}` → "Wilde ZIGZAGOON gebruikt TACKLE!".
- `{B_ATK_PREFIX1/2/3}` expand to "jouw team" / "het vijandige team" (lowercase). Never put them at the start of a sentence.
- No possessive 's. Use "X van Y", or start with the name.
- Stat changes are `{NAME}: {STAT}\n{flink }{omhoog!|omlaag!}`, assembled by the game.
- Present tense: "gebruikt", "is verslagen", "gaat naar LV. 5!".
- Ability messages: "X laat het regenen met MOTREGEN!". When a line is too long, use "X gebruikt\nTALENT!\p" plus a new sentence.
- Referee: `SCHEIDS:`.
- Control codes: the Dutch must contain exactly the same `{...}` codes as the English (check.py enforces this).
- Widths: placeholders are measured at worst case (name with prefix = "Vijandige " + 10 letters). If a line is too wide, break it with `\l`. In the rare case where the worst case can't happen (e.g. a buffer that is always a digit), put `width-ok: <reason>` in the notes column.
- battle.tsv holds all strings in src/battle_message.c (messages, battle menu, stat names, Battle Frontier referee).
- types.tsv holds type names (gTypeNames, max 6 bytes, e.g. "TYPE/VUUR" in the battle move menu).
