# Migration Scripts

## What are migration scripts?

pokeemerald-expansion rewrites existing systems in pokeemerald to improve their efficiency and make them easier to use and implement for developers. If developers were previously using a system that has been deprecated, it can be difficult to manually migrate between systems.

These scripts exist to help developers make the transition between refactored systems.

## Requirements

All migration scripts require [`python3`](https://www.python.org/downloads/) to be installed. Migration scripts are executed by running the following commands from the root directory of a developer's project.

```bash
chmod +x migration_scripts/*.py ; #give permission to make the script executable
python3 migration_scripts/*.py ; #run the migration script
```

`*` will need to be replaced with the name of the appropriate script.

## 1.8.x to 1.9.x+

### Battle Anim Moves

* Filepath [`migration_scripts/1.9/battle_anim_moves_refactor.py`](1.9/battle_anim_moves_refactor.py)
* Introduced in [Refactor move animations #4683](https://github.com/rh-hideout/pokeemerald-expansion/pull/4683)

Refactors all battle animation move scripts, removing the list from `data/battle_anim_scripts.s` and linking them to the moves in `gMovesInfo` for easier maintaining. Only necessary if new moves have been added.

#### [data/battle_anim_scripts.h](../data/battle_anim_scripts.s)
```diff
-    .4byte Move_POUND
```

#### [include/battle_anim_scripts.h](../include/battle_anim_scripts.h)
```diff
+    extern const u8 Move_POUND[];
```

#### [src/data/moves_info.h](../src/data/moves_info.h)
```diff
    [MOVE_POUND] =
    {
        .name = COMPOUND_STRING("Pound"),
        .description = COMPOUND_STRING(
            "Pounds the foe with\n"
            "forelegs or tail."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_POUND,
-        .contestComboMoves = {0}
+        .contestComboMoves = {0},
+        .battleAnimScript = Move_POUND,
    },
```

### Item Icons

* Filepath [`migration_scripts/1.9/convert_item_icons.py`](1.9/convert_item_icons.py)
* Introduced in [Get rid of gItemIconTable #4579](https://github.com/rh-hideout/pokeemerald-expansion/pull/4579)

Moves all information from `gItemIconTable` to `gItemsInfo`.

#### [src/data/item_icon_table.h](..src/data/item_icon_table.h)
```diff
-    [ITEM_POKE_BALL] = {gItemIcon_PokeBall, gItemIconPalette_PokeBall},
```

#### [src/data/items.h](..src/data/items.h)
```diff
    [ITEM_POKE_BALL] =
    {
        .name = _("Poké Ball"),
        .price = 200,
        .description = COMPOUND_STRING(
            "A tool used for\n"
            "catching wild\n"
            "Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_POKE_BALL - FIRST_BALL,
+        .iconSprite = gItemIcon_PokeBall,
+        .iconPalette = gItemIconPalette_PokeBall,
    },
```

### Partner & Trainer Parties

* Filepaths [`migration_scripts/1.9/convert_trainer_parties.py`](1.9/convert_trainer_parties.py) and [`migration_scripts/1.9/convert_partner_parties.py`](1.9/convert_trainer_parties.py)
* Introduced in [Competitive-formatted parties #3545](https://github.com/rh-hideout/pokeemerald-expansion/pull/3545) and [Make trainerproc compatible with partners #4421](https://github.com/rh-hideout/pokeemerald-expansion/pull/4421)

Converts trainer data (for `convert_trainer_parties.py`) and partner data (for `convert_partner_data.py`) to the new `.party` format. Not necessary if `COMPETITIVE_PARTY_SYNTAX` is turned off.

#### [src/data/trainer_parties.h](..src/data/trainer_parties.h)
```diff
-static const struct TrainerMon sParty_Sawyer1[] = {
-    {
-    .lvl = 21,
-    .species = SPECIES_GEODUDE,
-    }
-};
```

#### [src/data/trainers.party](..src/data/trainers.party)
```diff
+=== TRAINER_SAWYER_1 ===
+Name: SAWYER
+Class: Hiker
+Pic: Hiker
+Gender: Male
+Music: Hiker
+Double Battle: No
+AI: Check Bad Move / Try To Faint / Check Viability
+
+Geodude
+Level: 21
+IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe
```

#### [src/data/partner_parties.h](..src/data/partner_parties.h)
```diff
-static const struct TrainerMon sParty_StevenPartner[] = {
-    {
-        .species = SPECIES_METANG,
-        .lvl = 42,
-        .nature = NATURE_BRAVE,
-        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
-        .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
-        .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
-    },
-    {
-        .species = SPECIES_SKARMORY,
-        .lvl = 43,
-        .nature = NATURE_IMPISH,
-        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
-        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
-        .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
-    },
-    {
-        .species = SPECIES_AGGRON,
-        .lvl = 44,
-        .nature = NATURE_ADAMANT,
-        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
-        .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
-        .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
-    }
-};
```

#### [src/data/battle_partners.party](..src/data/battle_partners.party)
```diff
+=== PARTNER_STEVEN ===
+Name: STEVEN
+Class: Rival
+Pic: Steven
+Gender: Male
+Music: Male
+
+Metang
+Brave Nature
+Level: 42
+IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe
+EVs: 252 Atk / 252 Def / 6 SpA
+- Light Screen
+- Psychic
+- Reflect
+- Metal Claw
+
+Skarmory
+Impish Nature
+Level: 43
+IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe
+EVs: 252 HP / 6 SpA / 252 SpD
+- Toxic
+- Aerial Ace
+- Protect
+- Steel Wing
+
+Aggron
+Adamant Nature
+Level: 44
+IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe
+EVs: 252 Atk / 252 SpA / 6 SpD
+- Thunder
+- Protect
+- Solar Beam
+- Dragon Claw
```

### Egg Move Refactor

* Filepaths [`migration_scripts/1.9/egg_move_refactor.py`](1.9/egg_move_refactor.py)
* Introduced in [Egg Move Refactor #4534](https://github.com/rh-hideout/pokeemerald-expansion/pull/4534)

Updates egg moves to the refactored format. Only necessary if new species have been added or if egg moves of an existing species was altered.

#### [src/data/pokemon/egg_moves.h](..src/data/pokemon/egg_moves.h)
```diff
-    egg_moves(BULBASAUR,
-        MOVE_SKULL_BASH,
-        MOVE_CHARM,
-        MOVE_PETAL_DANCE,
-        MOVE_MAGICAL_LEAF,
-        MOVE_GRASS_WHISTLE,
-        MOVE_CURSE,
-        MOVE_INGRAIN,
-        MOVE_NATURE_POWER,
-        MOVE_AMNESIA,
-        MOVE_LEAF_STORM,
-        MOVE_POWER_WHIP,
-        MOVE_SLUDGE,
-        MOVE_ENDURE,
-        MOVE_GIGA_DRAIN,
-        MOVE_GRASSY_TERRAIN),
+static const u16 sBulbasaurEggMoveLearnset[] = {
+    MOVE_SKULL_BASH,
+    MOVE_CHARM,
+    MOVE_PETAL_DANCE,
+    MOVE_MAGICAL_LEAF,
+    MOVE_GRASS_WHISTLE,
+    MOVE_CURSE,
+    MOVE_INGRAIN,
+    MOVE_NATURE_POWER,
+    MOVE_AMNESIA,
+    MOVE_LEAF_STORM,
+    MOVE_POWER_WHIP,
+    MOVE_SLUDGE,
+    MOVE_ENDURE,
+    MOVE_GIGA_DRAIN,
+    MOVE_GRASSY_TERRAIN,
+    MOVE_UNAVAILABLE,
};
```

#### [src/data/pokemon/species_info/gen_1_families.h](..src/data/pokemon/species_info/gen_1_families.h)
```diff
    [SPECIES_BULBASAUR] =
    {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 49,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bulbasaur"),
        .cryId = CRY_BULBASAUR,
        .natDexNum = NATIONAL_DEX_BULBASAUR,
        .categoryName = _("Seed"),
        .height = 7,
        .weight = 69,
        .description = COMPOUND_STRING(
            "Bulbasaur can be seen napping in bright\n"
            "sunlight. There is a seed on its back.\n"
            "By soaking up the sun's rays, the seed\n"
            "grows progressively larger."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bulbasaur,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Bulbasaur,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Bulbasaur,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Bulbasaur,
        .shinyPalette = gMonShinyPalette_Bulbasaur,
        .iconSprite = gMonIcon_Bulbasaur,
        .iconPalIndex = 4,
        FOOTPRINT(Bulbasaur)
        .levelUpLearnset = sBulbasaurLevelUpLearnset,
        .teachableLearnset = sBulbasaurTeachableLearnset,
+       .eggMoveLearnset = sBulbasaurEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_IVYSAUR}),
    },
```

## 1.7.x to 1.8.x+

### Item Balls

* Filepath [`migration_scripts/1.8/item_ball_refactor.py`](1.8/item_ball_refactor.py)
* Introduced in [Item Ball refactor / Pluralize item names for giveitem and finditem #3942](https://github.com/rh-hideout/pokeemerald-expansion/pull/3942)

Modifies all item ball scripts defined using to original Game Freak method to the new refactored method.

#### [data/scripts/item_ball_scripts.inc](../data/scripts/item_ball_scripts.inc)
```diff
- Route102_EventScript_ItemPotion::
-	finditem ITEM_POTION
+ Common_EventScript_FindItem::
+   callnative GetObjectEventTrainerRangeFromTemplate
+   finditem VAR_RESULT
	end
```

#### [data/maps/Route102/map.json](../data/maps/Route102/map.json)
```diff
    {
      "graphics_id": "OBJ_EVENT_GFX_ITEM_BALL",
      "x": 50,
      "y": 5,
      "elevation": 3,
      "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
      "movement_range_x": 1,
      "movement_range_y": 1,
      "trainer_type": "TRAINER_TYPE_NONE",
-      "trainer_sight_or_berry_tree_id": "0",
-      "script": "Route102_EventScript_ItemPotion",
+      "trainer_sight_or_berry_tree_id": "ITEM_POTION",
+      "script": "Common_EventScript_FindItem",
      "flag": "FLAG_ITEM_ROUTE_102_POTION"
    },
```

### Facility Mons

* Filepath [`migration_scripts/1.9/battle_frontier_convert_parties.py`](1.8/battle_frontier_convert_parties.py)
* Introduced in [Adds battle frontier conversion script #5040](https://github.com/rh-hideout/pokeemerald-expansion/pull/5040)
* Original refactor in [Customizable FrontierMon Sets #4313](https://github.com/rh-hideout/pokeemerald-expansion/pull/4313)

Replaces itemTableId with heldItem and evSpread with ev.

#### [src/data/battle_frontier/battle_frontier_mons.h](../src/data/battle_frontier/battle_frontier_mons.h)
```diff
    [FRONTIER_MON_SUNKERN] = {
        .species = SPECIES_SUNKERN,
        .moves = {MOVE_MEGA_DRAIN, MOVE_HELPING_HAND, MOVE_SUNNY_DAY, MOVE_LIGHT_SCREEN},
-        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
+       .heldItem = ITEM_LAX_INCENSE,
-        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
+       .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 0),
        .nature = NATURE_RELAXED
    },
```