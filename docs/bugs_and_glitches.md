
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

**Fix:** Edit `RemoveBagItemIconSprite` in [src/item_menu_icons.c](https://github.com/pret/pokeemerald/blob/master/src/item_menu_icons.c):
```diff
-    RemoveBagSprite(id + ITEMMENUSPRITE_ITEM);
+    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM];
+
+    if (spriteId[id ^ 1] != SPRITE_NONE)
+        gSprites[spriteId[id ^ 1]].invisible = TRUE;
+
+    if (spriteId[id] != SPRITE_NONE)
+    {
+        DestroySpriteAndFreeResources(&gSprites[spriteId[id]]);
+        spriteId[id] = SPRITE_NONE;
+    }
```
