## Day/Night system FAQ

### Q: How do I disable DNS?
A: Set `OW_ENABLE_DNS` to `FALSE` in `include/config/overworld.h`.

### Q: What map changes should be made for DNS?
A: By default, the only Hoenn map changes that need to be made are to edit the Lavaridge Town map to change the metatiles the two old ladies are on in the hot springs to be the normal hot spring water tile. This is to avoid a visual bug from when `OW_OBJECT_VANILLA_SHADOWS` is FALSE.

However, by default no maps have lighting effects of any kind. The rest of this tutorial is to aid in adding lighting effects.

If you intend to use vanilla maps and have not already edited them, revert commit [a5b079d833f18f66ebd53ac77f00227ae4a1f389](https://github.com/rh-hideout/pokeemerald-expansion/pull/6562/commits/a5b079d833f18f66ebd53ac77f00227ae4a1f389). This commit includes a lot of tileset, metatile, and palette changes to accommodate light-blending, and applies `OBJ_EVENT_GFX_LIGHT_SPRITE` where they make sense.

If you _have_ edited vanilla maps, the merge conflicts from reverting that commit will cause problems. If you are using vanilla maps, manually copy some of the tileset changes, `.pal`, and `.pla` files in your branch, and begin rebuilding your metatiles to have windows use the palettes that have a `.pla` for light blending the correct color slots. [Triple-layer metatiles](https://github.com/pret/pokeemerald/wiki/Triple-layer-metatiles) are highly recommended.

WARNING: [As per issue #7034](https://github.com/rh-hideout/pokeemerald-expansion/issues/7034) if you follow this tutorial reverting the previously mentioned commit to use the updated palettes in the Hoenn maps and *after* that you try to follow the [Triple-layer metatiles tutorial](https://github.com/pret/pokeemerald/wiki/Triple-layer-metatiles), you'll encounter an issue when running the script to update old tilesets to support triple-layer metatiles.
Follow the band-aid fix proposed in that issue after this tutorial but before following the triple-layer metatiles tutorial if you want everythign to work properly with light-blended palettes and triple-layer metatiles together.

You will also want to add the lighting object events from that commit.

If you are not using Hoenn maps, the primary concern is that you do not use the exact same palette indices for colors you want to be darkened during night time and colors you want to light up. Err towards not light blending a color if you aren't sure how to avoid conflicts.

When writing scripts, it is important to use the correct fade macro to avoid odd behavior from the GBA with alpha blending. If the current area is outside (and/or impacted by DNS), use `fadescreenswapbuffers` to fade in and out. Otherwise, it is safe to use `fadescreen`.

### Q: How do I make lightbulbs glow?

![Rustboro before adding lamp object events](img/dns/without_lamp.png)
![Rustboro after adding lamp object events](img/dns/with_lamp.png)

A: Making lamps glow is not part of the tileset itself.  Instead, place certain object events on top of where you desire a glowing effect.

These object events should use `OBJ_EVENT_GFX_LIGHT_SPRITE` and then as their `trainer_sight_or_berry_tree_id` (called Sight Radius/Berry Tree ID in porymap), use `LIGHT_TYPE_BALL` for round lights (such as candles or gas lamps), `LIGHT_TYPE_PKMN_CENTER_SIGN` over a Pok&eacute;mon Center sign, or `LIGHT_TYPE_POKE_MART_SIGN` over a Pok&eacute;mart sign.

### Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name. This can be done on any kind of palette, except for palette 0, which is skipped over.
The commit to revert listed up above only applies it to tilesets, but you could easily do it for object events as well. Of note, there is a [commit reverted for being out of scope](https://github.com/rh-hideout/pokeemerald-expansion/pull/6562/commits/348f5967ac8d383c827b415e1040234a3f28626f) to make a follower Ampharos's tail glow. Do note that in order to light-blend the object, a proper `.pal` file is required. Generating a `.gbapal` directly from the image is not enough.

In this file you can enter color indices [0,15]
on separate lines to mark those colors as being light-blended, i.e:

`06.pla:`
```
# A comment
0 # if color 0 is listed, uses it to blend with instead of the default!
1
9
10
```

During the day time, these color indices appear as normal, but will be blended with either yellow or the 0 index at night. These indices should only be used for things you expect to light up. If you are using [porytiles](https://github.com/grunt-lucas/porytiles/wiki), palette overrides and using slight alterations to a color will aid you in avoiding color conflicts where the wrong index is assigned.

![Rustboro gym after light-blending the windows](img/dns/window_lights.png)

The windows appear as normal during the day time (blue) and light up in the night. These use the default color.

### Q: How do I return to using regular shadows?
A: Set `OW_OBJECT_VANILLA_SHADOWS` to `TRUE` in `include/config/overworld.h`.

### Q: What graphical errors are likely to occur while using DNS?
A: If you have `OW_POPUP_GENERATION` set to `GEN_5` and `OW_POPUP_BW_ALPHA_BLEND` set to `TRUE`, you may have color errors during map popups. This is due to the GBA being severely limited in use of color blending and having both the overworld blended and the popup blended is difficult.

If you have `OW_OBJECT_VANILLA_SHADOWS` set to `TRUE`, this will also cause visual errors.

Any other graphical error should be reported.

### Q: How do I disable shadows for certain locations?
A: Shadows can be disabled for certain locations by modifying the `CurrentMapHasShadows` function in `src/overworld.c`.

### Q: How do I change the default light-blend color?
A: The default color is handled by the `#define DEFAULT_LIGHT_COLOR` in `src/palette.c`.

### Q. How do I use alternate nighttime palettes?

In addition to palette tinting, the DNS allows tilesets to define alternate nighttime palettes.
These palettes are automatically blended with their corresponding daytime palettes with the passage of time.

Each tileset has `16` total palette slots. `3` of the BG palettes (`13 - 15`) are reserved for the UI leaving `13` (`0-12`) usable for tilesets. Because primary tilesets load `6` (`NUM_PALS_IN_PRIMARY`) palettes (`0-5`) and secondary Tilesets load `7` palettes (6-12), some slots are unused for each. DNS repurposes these unused slots to store alternate nighttime palettes.

To avoid overlap with active palettes, each nighttime palette is stored in a different slot determined by the formula: `night_pal = (day_pal + 9) % 16`

**Day palette index vs. Night palette index**

| Day | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|-----|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|
| Night | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |


For instance, in a secondary Tileset (slots `6-12`), the nighttime palettes for index `8` would be stored at index `1` (which is unused in a secondary tileset). Slots `0` and `13-15` are not used for blending so the corresponding slots `9` and `6-8` are never used for nighttime palettes.

_Note that palette `0` is not used for blending._

Once the appropriate nighttime `.pal` file has been added, add a `swapPalettes` field to the tileset struct definition in `src/data/tilesets/headers.h`. The macro `SWAP_PAL(x)` is provided for this purpose.

`swapPalettes` is a bitmask so to use nighttime palettes for indices 7 and 9 in the Petalburg Tileset we add a `swapPalettes` with `SWAP_PAL(7) | SWAP_PAL(9)`. 

Note that the palette index to specify here is the palette index that you want to swap at night (**NOT** the corresponding nighttime palette).

```diff
const struct Tileset gTileset_Petalburg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Petalburg,
+   .swapPalettes = SWAP_PAL(7) | SWAP_PAL(9), // Enable nighttime variants for slots 7 and 9
    .palettes = gTilesetPalettes_Petalburg,
    .metatiles = gMetatiles_Petalburg,
    .metatileAttributes = gMetatileAttributes_Petalburg,
    .callback = InitTilesetAnim_Petalburg,
};
```



