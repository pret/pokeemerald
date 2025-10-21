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
- [X] Implement all base stat changes
- [X] Implement evolution changes
- [X] Implement move changes
- [X] Implement level-up learnset changes
- [X] Implement TM learnset changes
- [X] Implement egg move changes
- [X] Dark Physical & Ghost Special
- [X] Buffs to Sandstorm & Hail
- [X] Summary Screen shows Stats affected by nature
- [X] Summary Screen shows evs and ivs
- [X] Buffs to Hold Item Effects

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

10/5/25 - Battle Move Changes
file: src/data/battle_moves.h
- Crush Claw: BP 75->85, PP 10->15
- Dizzy Punch: PP 10->15
- DoubleSlap: ACC 85->100, PP 10->15
- ExtremeSpeed: PP 5->10
- Fury Attack: BP 15->18, ACC 85->100
- Fury Swipes: BP 18->20, ACC 80->100, PP 15->20
- Glare: ACC 75->90
- Hyper Voice: BP 90->100, PP 10->15
- Recover: PP 20->10
- Slam: ACC 75->95
- Sonicboom: ACC 90->100
- Supersonic: ACC 55->70
- Tackle: ACC 95->100
- Take Down: ACC 85->95
- Bullet Seed: BP 10->15
- Giga Drain: BP 60->75, PP 5->10
- Leaf Blade: BP 70->90
- Mega Drain: PP 10->20
- Needle Arm: BP 60->90
- Petal Dance: BP 70->90
- Blaze Kick: BP 85->100, ACC 90->95
- Fire Spin: BP 15->35, ACC 70->100
- Flame Wheel: BP 60->65
- Heat Wave: Chance to burn 10%->30%
- Sunny Day: PP 5->10
- Clamp: ACC 75->100
- Crabhammer: BP 90->110, ACC 85->90, PP 10->15
- Muddy Water: BP 95->100, ACC 85->90, PP 10->15
- Rain Dance: PP 5->10
- Waterfall: BP 80->70, now has 30% chance to cause flinch

10/6/25 - Battle Move Changes
file: src/data/battle_moves.h
- Barrage: BP 15->20, ACC 85->100
- Bind: BP 15->35, ACC 75->100
- Comet Punch: BP 18->25, ACC 85->100, PP 15->25
- Constrict: BP 10->30, chance to lower speed 10%->30%
- Covet: BP 40->60, PP 40->15
- Disable: ACC 55->85
- Flash: ACC 70->100
- Hyper Voice: now has 30% chance to confuse
- Skull Base: BP 100->130
- Smellingsalt: BP 60->75, PP 10->15
- Snore: BP 40->60, PP 15->20
- Thrash: BP 90->100
- Tri Attack: BP 80->85, PP 10->15
- Uproar: BP 50->65, PP 10->20
- Vicegrip: now has 20% chance to lower attack
- Weather Ball: PP 10->20
- Wrap: BP 15->35, ACC 85->100
- Arm Thrust: BP 15->18
- Cross Chop: ACC 80->90, PP 5->10
- Dynamic Punch: ACC 50->70, PP 5->10
- Hi Jump Kick: BP 85->100
- Jump Kick: BP 70->80
- Rock Smash: BP 20->60, chance to lower defense 50%->20%
- Rolling Kick: BP 60->70, ACC 85->100, PP 15->25
- Sky Uppercut: BP 85->90, ACC 90->95
- Submission: BP 80->90, ACC 80->100
- Triple Kick: BP 10->30, ACC 90->100, PP 10->15
- Vital Throw: PP 10->20
- Bubble: BP 20->30
- Dive: BP 60->80, PP 10->15
- Hydro Pump: ACC 80->85
- Octazooka: BP 65->70, ACC 85->100, PP 10->15
- Whirlpool: BP 15->35, ACC 70->100
- Sacred Fire: PP 5->10
- Will-o-Wisp: ACC 75->90
- AncientPower: PP 5->10
- Rock Blast: ACC 80->90, PP 10->15
- Rock Slide: BP 75->90, PP 10->15
- Rock Throw: ACC 90->95, PP 15->25
- Rock Tomb: BP 50->60, ACC 80->90, PP 10->15
- Cut: BP 50->55, PP 30->25, now Bug Type, now high crit ratio
- Leech Life: BP 20->40, PP 15->25
- Pin Missile: BP 14->19, ACC 85->100
- Signal Beam: BP 75->85
- Silver Wind: PP 5->10
- Twineedle: BP 25->40
- Egg Bomb: ACC 75->90, PP 10->15, now Grass Type
- Grasswhistle: ACC 55->75
- Vine Whip: BP 35->40, PP 10->25
- Bone Club: ACC 85->100, PP 20->25
- Bone Rush: ACC 80->100, PP 10->20
- Bonemerang: PP 10->20
- Dig: BP 60->70, PP 10->20
- Mud Slap: BP 20->30, PP 10->15
- Sand Tomb: BP 15->35, ACC 70->100
- Aeroblast: PP 5->10
- Air Cutter: BP 55->65
- Bounce: ACC 85->95, PP 5->15
- Fly: ACC 95->100
- Razor Wind: BP 80->75, ACC 100->95, PP 10->15, now flying type, no longer has charge up turn, now has 30% chance to flinch
- Sky Attack: BP 140->120, PP 5->10, no longer has charge up turn, has 30% chance to cause flinch
- Zap Cannon: ACC 50->70, PP 5->10
- Blizzard: now always hits during hail
- Ice Beam: PP 10->15
- Icicle Spear: BP 10->25, PP 30->25
- Icy Wind: PP 15->20
- Astonish: BP 30->50
- Lick: BP 20->40
- Shadow Punch: BP 60->80
- Beat Up: BP 10->20
- Crunch: chance to lower SPDEF->DEF
- Faint Attack: BP 60->70
- Knock Off: BP 20->50
- Thief: BP 40->60, PP 10->15
- Future Sight: BP 80->120, ACC 90->100
- Luster Purge: PP 5->15
- Mist Ball: PP 5->15
- Psychic: PP 10->15
- Psywave: ACC 80->95
- Poison Fang: BP 50->60
- Poison Gas: ACC 55->70
- Poison Sting: BP 15->30
- Poison Tail: BP 50->80
- Poison Powder: ACC 75->85
- Sludge Bomb: PP 10->15
- Smog: ACC 70->100
- Dragon Claw: BP 80->90
- Dragon Breath: BP 60->70
- Outrage: BP 90->110
- Twister: BP 40->50
- Doom Desire: BP 120->150, ACC 85->100
- Iron Tail: ACC 75->90, has 30%->20% chance to lower defense
- Metal Claw: BP 50->60, has 10%->20% chance to increase attack
- Meteor Mash: ACC 85->90
- Spike Cannon: BP 20->30, now steel type
- Steel Wing: ACC 90->95

10/6/25 - Change move animations
file: data/battle_anim_scrips.s
- Razor Wind now always goes to "unleash" animation as it is no longer a two-turn move
- Sky Attack now always goes to "unleash" animation as it is no longer a two-turn move

10/6/25 - Implementing "blizzard" move effect
files: include/constants/battle_move_effects.h
- added constant for "blizzard" move effect
files: src/battle.tv
- added in "blizzard" effect
files: data/battle_scripts_1.s
- implementing script for "blizzard" effect
files: src/battle_script_commands.c
- make blizzard skip accurary check in hail

10/6/25 - hail & sandstorm defense boosts
files: src/pokemon.c
- Rock Types get 50% SPDEF boost in sandstorm and Ice Types get 50% DEF boost in hail

10/6/25 - making dark physical and ghost special
files: /include/battle.h

10/6/25 - update move descriptions based on changes
files: /src/data/text/move_descriptions.h

10/6/25 - commit made
files: data/battle_anim_scripts.s
       data/battle_scripts.s
       include/battle.h
       include/constants/battle_move_effects.h
       src/battle_script_commands.c
       src/battle_tv.c
       src/pokemon.c
       src/data/battle_moves.h
       src/data/text/move_descriptions.h

10/6/25 - Evolution Changes
files: src/data/pokemon/evolution.h
       src/data/items.h
- Haunter -> Gengar; Trade -> Lv 42
- Kadabra -> Alakazam; Trade -> Lv 42
- Graveler -> Golem; Trade -> Lv 38
- Machoke -> Machamp; Trade -> Lv 38
- Clamperl -> Gorebyss; Trade w/ DeepSeaScale -> Use DeepSeaScale
- Clamperl -> Huntail; Trade w/ DeepSeaTooth -> Use DeepSeaTooth
- Seadra -> Kingdra; Trade w/ Dragon Scale -> Use Dragon Scale
- Poliwhirl -> Politoed; Trade w/ King's Rock -> Use King's Rock
- Slowpoke -> Slowking; Trade w/ King's Rock -> Use King's Rock
- Onix -> Steelix; Trade w/ Metal Coat -> Use Metal Coat
- Scyther -> Scizor; Trade w/ Metal Coat -> Use Metal Coat
- Porygon -> Porygon2; Trade w/ Upgrade -> Use Upgrade
- Goldeen -> Seaking; Lv 33 -> Lv 28
- Spinarak -> Ariados; Lv 22 -> Lv 21
- Pineco -> Forretress; Lv 31 -> Lv 25
- Slugma -> Magcargo; Lv 38 -> Lv 27
- Ralts -> Kirlia; Lv 20 -> Lv 18
- Aron -> Lairon; Lv 32 -> Lv 28
- Meditite -> Medicham; Lv 37 -> Lv 33
- Trapinch -> Vibrava; Lv 35 -> Lv 32
- Vibrava -> Flygon; Lv 45 -> Lv 42
- Snorunt -> Glalie; Lv 42 -> Lv 36

10/7/25 - commit made
files: src/data/pokemon/evolution.h
       src/data/items.h

10/7/25 - Hold Item Buffs
files: src/data/items.h
Buff type damage by 10%->20%
- Silk Scarf
- Miracle Seed
- Soft Sand
- Charcoal
- Mystic Water
- Sharp Beak
- Silver Powder
- Dragon Fang
- Black Belt
- Metal Coat
- Hard Stone
- Twisted Spoon
- Spell Tag
- Black Glasses
- Poison Barb
- Magnet
- Sea Incense (this actually is a buff of 5%->20%)
- NevermeltIce
Buff lax incense
- Lax incense 5%->10% chance to miss

10/7/25 - commit made
files: src/data/items.h

10/10/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Vileplume

10/11/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Kangaskhan

10/13/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Mew

10/13/25 - commit made
files :src/data/pokemon/level_up_learnsets.h

10/13/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Celebi

10/13/25 - commit made
files: src/data/pokemon/level_up_learnsets.h

10/13/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Wailord

10/14/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Slaking

10/15/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Absol

10/16/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Illumise

10/20/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- Learnsets up to Metagross

10/21/25 - Levelup Learnset Edits
files: src/data/pokemon/level_up_learnsets.h
- All learnsets finished

10/21/25 - commit made
files: src/data/pokemon/level_up_learnsets.h

10/21/25 - TM Learnset Changes
files: src/data/pokemon/tmhm_learnsets.h
- All TM/HM learnsets updated

10/21/25 - commit made
files: src/data/pokemon/tmhm_learnsets.h

10/21/25 - Tutor Move review
- Tutor moves were reviewed and no changes were made

10/21/25 - Egg Moves
files: src/data/pokemon/egg_moves.h
- All Egg moves updated

10/21/25 - commit made
files: src/data/pokemon/egg_moves.h

10/21/25 - colors to show nature changes on stats screen
files: src/pokemon_summary_screen.c
- Colors indicate how natures are affected by nature on summary screen

10/21/25 - commit made
files: src/pokemon_summary_screen.c

10/21/25 - show ivs and evs on stat screen
files: graphics/summary_screen/tiles.ping
       src/pokemon_summary_screen.c