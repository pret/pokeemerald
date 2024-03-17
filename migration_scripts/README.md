# Migration Scripts

## What are migration scripts?

pokeemerald-expansion rewrites existing systems in pokeemerald to improve their efficiency and make them easier to use and implement for developers. If developers were previously using a system that has been deprecated, it can be difficult to manually migrate between systems.

These scripts exist to help developers make the transition between refactored systems.

## Requirements

All migration scripts require [`python3`](https://www.python.org/downloads/) to be installed. Migration scripts are executed by running the following commands from the root directory of a developer's project.

```bash
chmod +x migration_scripts/*.py ; #give permision to make the script executable
python3 migration_scripts/*.py ; #run the migration script
```

`*` will need to be replaced with the name of the appropriate script.

### Item Balls

* Filepath [`migration_scripts/item_ball_refactor.py`](item_ball_refactor.py)
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
