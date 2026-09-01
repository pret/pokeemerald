# Deleting all FRLG maps

A command was added to delete all FRLG maps at once. This doesn't save space in the ROM because the maps are not compiled in the ROM if you are compiling in "emerald mode". This solely exists for users that want to clean up their repo. The command is

```shell
python dev_scripts/delete_frlg_maps.py
```
It will take care of all the map constants in the c files but you will need to fix mention the to fuschia city entrance in the `safari_zone.inc` script.

### Disclaimer: The following is a work-in-progess and the processes described here are not fully tested and will likely break your game! Use at your own risk.

# Deleting vanilla maps

Separately, if you want to delete a singular map, you will need to remove 4 things:
- the map folder in `data/maps/`
- the map folder in `data/layouts`
- the include of the mapscript in `data/event_scripts.s`
- the name of the map in `data/maps/map_groups.json`

After deleting the layout folder, you will need to run
```shell
touch data/layouts/layouts.json
```
in order for some things to update properly during compilation

Because vanilla maps are referenced all over the C code, deleting references to them can prevent the project to compile. To avoid this, mapjson will check if vanilla maps are missing and create dummy values for them.

**NOTE**:
- `mapjson` will _not_ function correctly unless all four of the aforementioned are edited.
- `mapjson` will also modify `heal_locations.json` if one of the deleted map contained a heal_location.
- when creating connections between maps, `mapjson` will check if the connected map exist and will not add a connection for a missing map.

## Known issues

- Some maps may still be referenced in ways that cause compilation issues. Usually, it will be scripts that directly reference the old map names.
- If you try to enter a map that used to be connected to a deleted map, the game will freeze.
