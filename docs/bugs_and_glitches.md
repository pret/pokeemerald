
# Bugs and Glitches

These are known bugs and glitches in the original Pokémon Emerald game: code that clearly does not work as intended, or that only works in limited circumstances but has the possibility to fail or crash.

Fixes are written in the `diff` format. If you've used Git before, this should look familiar:

```diff
 this is some code
-delete red - lines
+add green + lines
```

## Contents

- [RNG does not get seeded](#rng-does-not-get-seeded)
- [Scrolling through items in the bag causes the image to flicker](#scrolling-through-items-in-the-bag-causes-the-image-to-flicker)


## RNG does not get seeded

**Fix:** Add the following function to [src/main.c](https://github.com/pret/pokeemerald/blob/master/src/main.c):
```diff
+static void SeedRngWithRtc(void)
+{
+	u32 seed = RtcGetMinuteCount();
+	seed = (seed >> 16) ^ (seed & 0xFFFF);
+	SeedRng(seed);
+}
```

And edit `AgbMain`:

```diff
	...
	RtcInit();
	CheckForFlashMemory();
	InitMainCallbacks();
	InitMapMusic();
+	SeedRngWithRtc();
	ClearDma3Requests();
	...
```

## Scrolling through items in the bag causes the image to flicker

**Fix:** Add the following function to [src/item_menu_icons.c](https://github.com/pret/pokeemerald/blob/master/src/item_menu_icons.c):
```diff
+void HideBagItemIconSprite(u8 id)
+{
+	u8 *spriteId = &gBagMenu->spriteId[10];
+	if (spriteId[id] != 0xFF)
+	{
+		gSprites[spriteId[id]].invisible = TRUE;
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
-	RemoveBagItemIconSprite(1 ^ gBagMenu->unk81B_1);
+	HideBagItemIconSprite(gBagMenu->unk81B_1 ^ 1);
+	RemoveBagItemIconSprite(gBagMenu->unk81B_1);
	if (a != -2)
	...
```
