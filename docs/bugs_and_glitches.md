
# Bugs and Glitches

These are known bugs and glitches in the original Pokémon Emerald game: code that clearly does not work as intended, or that only works in limited circumstances but has the possibility to fail or crash. Defining the `BUGFIX` and `UBFIX` preprocessor variables will fix some of these automatically. `UBFIX` will already be defined for MODERN builds.

Fixes are written in the `diff` format. If you've used Git before, this should look familiar:

```diff
 this is some code
-delete red - lines
+add green + lines
```

## Contents

- [Scrolling through items in the bag causes the image to flicker](#scrolling-through-items-in-the-bag-causes-the-image-to-flicker)


## Scrolling through items in the bag causes the image to flicker

**Fix:** Add the following function to [src/item_menu_icons.c](https://github.com/pret/pokeemerald/blob/master/src/item_menu_icons.c):
```diff
+void HideBagItemIconSprite(u8 id)
+{
+	u8 *spriteId = &gBagMenu->spriteIds[10];
+	if (spriteIds[id] != 0xFF)
+	{
+		gSprites[spriteIds[id]].invisible = TRUE;
+	}
+}

```

and its corresponding declaration in [include/item_menu_icons.h](https://github.com/pret/pokeemerald/blob/master/include/item_menu_icons.h):

```diff
+void HideBagItemIconSprite(u8 id);

```

Then edit `BagMenu_MoveCursorCallback` in [src/item_menu.c](https://github.com/pret/pokeemerald/blob/master/src/item_menu.c):

```diff
	...
{
-	RemoveBagItemIconSprite(1 ^ gBagMenu->itemIconSlot);
+	HideBagItemIconSprite(gBagMenu->itemIconSlot ^ 1);
+	RemoveBagItemIconSprite(gBagMenu->itemIconSlot);
	if (itemIndex != LIST_CANCEL)
	...
```


Then edit `struct Sprite` in [gflib/sprite.h](https://github.com/pret/pokeemerald/blob/master/gflib/sprite.h):

```diff
       /*0x40*/ u16 sheetTileStart;

       /*0x42*/ u8 subspriteTableNum:6;
                u8 subspriteMode:2;

       /*0x43*/ u8 subpriority;
+		u16 tileTag;
+		u16 paletteTag;
```

and add the following to `CreateSpriteAt` in [gflib/sprite.c](https://github.com/pret/pokeemerald/blob/master/gflib/sprite.c):

```diff
	sprite->template = template;
	sprite->callback = template->callback;
	sprite->x = x;
	sprite->y = y;
+	sprite->tileTag = template->tileTag;
+	sprite->paletteTag = template->paletteTag;
```

Then edit `FreeSpriteTiles` in the same file:

```diff
	#ifdef UBFIX
	if (!sprite || !sprite->template)
	    return;
	#endif

-	if (sprite->template->tileTag != TAG_NONE)
-	    FreeSpriteTilesByTag(sprite->template->tileTag);
+	if (sprite->tileTag != TAG_NONE)
+	    FreeSpriteTilesByTag(sprite->tileTag);
```

as well as `FreeSpritePalette`, also in the same file:

```diff
	#ifdef UBFIX
	if (!sprite || !sprite->template)
	    return;
	#endif

-	FreeSpritePaletteByTag(sprite->template->paletteTag);
+	FreeSpritePaletteByTag(sprite->paletteTag);
```
