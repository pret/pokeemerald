# Feature Plan: Pokémon Rebalance

## 🧭 Goal
Improve overall gameplay balance by adjusting base stats, movesets, and availability to make more Pokémon viable throughout a standard playthrough of Pokémon Emerald.

---

## 🧩 Scope
This feature will focus on:
- Updating Pokémon **base stats** for balance and variety.
- Revising **level-up movesets** for most Pokemon available in Hoenn Dex
- Tweaking **moves** that are weak or underutilized.
- Adjusting **TM and tutor compatibility** for better type coverage.
- Making the **Hoenn Pokédex fully completable**.

---

## 🗂️ Files Likely to be Modified
| Type | File | Description |
|------|------|-------------|
| Base stats | `src/data/pokemon/species_info.c` | Adjusts Pokémon stat spreads. |
| Movesets | `src/data/pokemon/level_up_learnsets.c` | Defines what moves each Pokémon learns. |
| Moves | `src/data/move_effects.c` and `src/data/battle_moves.h` | Defines move power, accuracy, effects. |
| Constants | `include/constants/pokemon.h` | Needed for new forms or IDs. |
| TM compatibility | `src/data/pokemon/tmhm_learnsets.c` | Defines what TMs Pokémon can learn. |

---

## ⚙️ Implementation Steps
1. Begin with a **small test batch** of Pokémon (e.g., early-game species like Zigzagoon, Lotad, Seedot).
2. Rebuild the ROM after each change and test in an emulator.
3. Document every change in this file as you go.
4. Commit each logical group of edits separately:
   - Base stats
   - Movesets
   - Move tweaks
5. Once stable and tested, merge branch into `master`.

---

## ✅ To-Do
- [ ] Implement all base stat changes
- [ ] Implement evolution changes
- [ ] Implement move changes
- [ ] Implement level-up learnset changes
- [ ] Implement TM learnset changes
- [ ] Implement tutor learnset changes

---

## 🧠 Notes
10/4/25 - Pokemon Base Stat Changes
file: src/data/pokemon/species_info.h
- Ekans: HP 35->40, ATT 60->65, SPD 55->60
- Arbok: HP 60->62, ATT 85->95, SPD 80->90
- Pikachu: DEF 30->40, SPDEF 40->50
- Clefable: SPATT 85->95
- Vulpix: HP 38->45, DEF 40->45, SPATT 50->60, SPDEF 65->70, SPD 65->75
- Ninetales: HP 73->78, ATT 76->71, DEF 75->80, SPATT 81->86
- Wigglytuff: DEF 45->55, SPATT 75->85, SPDEF 45->55
- Oddish: HP 45->50
- Gloom: HP 60->70
- Vileplume: HP 75->90, DEF 85->95
- Venomoth: ATT 65->75, SPATT 90->95, SPD 90->100
- Dugtrio: ATT 80->90
- Ponyta: SPD 90->100
- Rapidash: SPD 105->115
- Dewgong: ATT 70->60, SPATT 70->80
- Shellder: HP 30->35
- Marowak: HP 60->65
- Hitmonlee: DEF 53->58
- Hitmonchan: SPD 76->81
- Weezing: HP 65->75
- Lickitung: HP 90->95, ATT 55->70, DEF 75->85, SPATT 60->75, SPDEF 75->85
- Magmar: HP 65->75, ATT 95->85
- Flareon: SPATT 95->110, SPDEF 110->95
- Bellossom: DEF 85->95
- Marill: SPATT 20->40
- Azumarill: SPATT 50->70
- Slugma: HP 40->50, ATT 40->70, DEF 40->60, SPDEF 40->60
- Magcargo: HP 50->70, ATT 50->80, SPATT 80->90, SPDEF 80->90
- Corsola: HP 55->85, DEF 85->95, SPDEF 85->95

10/5/25 - Pokemon Base Stat Changes
file: src/data/pokemon/species_info.h
- Porygon: HP 65->75, ATT 60->70
- Furret: SPATT 45->55
- Ledian: HP 55->75
- Ariados: SPATT 60->70, SPDEF 60->70
- Togetic: HP 55->85, ATT 40->50
- Sudowoodo: HP 70->80, SPDEF 65->85
- Aipom: HP 55->70, ATT 70->90, DEF 55->65, SPD 85->90, SPDEF 55->65
- Sunflora: SPATT 105->125
- Yanma: HP 65->75, ATT 65->105, DEF 45->65, SPATT 75->65
- Quagsire: SPATT 65->75, SPDEF 65->75
- Murkrow: HP 60->70, ATT 85->105, DEF 42->52, SPD 91->95, SPATT 85->76, SPDEF 42->52
- Misdreavus: ATT 60->50, SPATT 85->95, SPDEF 85->95, SPD 85->90
- Gligar: HP 65->70, ATT 75->85, SPD 85->90
- Qwilfish: HP 65->75, DEF 75->85, SPATT 55->65, SPDEF 55->75
- Sneasel: SPATT 35->70
- Swinub: HP 50->80, ATT 55->65, SPATT 30->65, SPDEF 30->40
- Piloswine: SPATT 60->80, SPDEF 60->70
- Delibird: HP 45->60, ATT 55->75, DEF 45->55, SPATT 65->85, SPD 75->80
- Mantine: ATT 40->50
- Hitmontop: SPD 70->75
- Entei: ATT 115->90, SPATT 90->115
- Sceptile: SPATT 105->110
- Blaziken: SPD 80->85
- Mightyena: HP 70->75, ATT 90->95, DEF 70->75, SPD 70->80
- Linoone: ATT 70->80
- Beautifly: ATT 70->80, SPD 65->75, SPATT 90->100
- Dustox: HP 60->70, DEF 70->80, SPDEF 90->100
- Lombre: ATT 50->60, DEF 50->60, SPATT 60->70, SPDEF 70->80
- Ludicolo: SPD 70->80
- Nuzleaf: ATT 70->80, DEF 40->45, SPATT 60->70, SPDEF 40->45, SPD 60->70
- Shiftry: SPD 80->90
- Kirlia: HP 38->48, DEF 35->45, SPATT 65->75, SPDEF 55->65, SPD 50->60
- Shedinja: SPATT 30->80
- Nosepass: HP 30->60, ATT 45->55, SPATT 45->75
- Delcatty: ATT 65->85, SPATT 55->75
- Sableye: HP 50->60, ATT 75->85, DEF 75->85, SPATT 65->75, SPDEF 65->75
- Mawile: HP 50->60, ATT 85->105, DEF 85->105
- Meditite: HP 30->40, SPATT 40->50
- Medicham: SPATT 60->70
- Roselia: HP 50->55, ATT 60->65, DEF 40->45, SPD 65->70
- Vibrava: HP 50->60, ATT 70->80, DEF 50->60, SPATT 60->70, SPDEF 50->60, SPD 70->80
- Flygon: SPATT 80->90
- Lunatone: SPATT 95->105, SPDEF 85->95
- Solrock: SPATT 55->65, SPDEF 65->75
- Castform: ATT 70->65, DEF 70->60, SPATT 70->90, SPDEF 70->85
- Kecleon: HP 60->75, SPATT 60->70
- Shuppet: ATT 75->63, SPATT 63->75, SPD 45->55
- Banette: ATT 115->83, SPATT 83->115, SPD 65->95
- Duskull: HP 20->30, ATT 40->30, SPATT 30->40
- Dusclops: HP 40->50, SPATT 60->80
- Tropius: HP 99->120, SPATT 72->82
- Chimecho: ATT 50->40, SPATT 95->105, SPDEF 80->100, SPD 65->75
- Absol: SPD 75->95
- Glalie: DEF 80->65, SPATT 80->100, SPDEF 80->75

10/5/25 - Commit made
file: src/data/pokemon/species_info.h