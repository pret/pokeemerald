
# How to add new spotted species

PR [#9594](https://github.com/rh-hideout/pokeemerald-expansion/pull/9594) refactored the original code for Spinda spots to make it usable for any Pokemon. This tutorial will briefly cover the process of creating new spotted species. The details of the implementation have been documented fairly well in the code itself.

## Spot graphics

Before you can create spotted species you will need graphics for the spots themselves. This is beyond the scope of this tutorial. Each spot is a `1bpp` image that draws the shape of the spot like [this](https://i.ibb.co/Kp8CR0q3/spot-0.png).

The spot images are added to the code like so:
```c
//NOTE: Gyarados spots are 32x32 so use SpotImage32
static const SpotImage32 sGyaradosSpotImages[4] = {
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_0.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_1.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_2.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_3.1bpp"),
};

```

The Spinda spots that already exist are 16x16 so they use `SpotImage16`.

We will also need to add these files to `graphics_file_rules.mk`:

```diff
diff --git a/graphics_file_rules.mk b/graphics_file_rules.mk
index 4398a629af..6f7600e9da 100644
--- a/graphics_file_rules.mk
+++ b/graphics_file_rules.mk
@@ -21,6 +21,7 @@ POKEDEXGFXDIR := graphics/pokedex
 STARTERGFXDIR := graphics/starter_choose
 NAMINGGFXDIR := graphics/naming_screen
 SPINDAGFXDIR := graphics/pokemon/spinda/spots
+GYARADOSGFXDIR := graphics/pokemon/gyarados/spots
 TITLESCREENGFXDIR := graphics/title_screen
 
 types := none normal fight flying poison ground rock bug ghost steel mystery fire water grass electric psychic ice dragon dark fairy stellar
@@ -678,3 +679,15 @@ $(SPINDAGFXDIR)/spot_2.1bpp: %.1bpp: %.png
 
 $(SPINDAGFXDIR)/spot_3.1bpp: %.1bpp: %.png
 	$(GFX) $< $@ -plain -data_width 2
+
+$(GYARADOSGFXDIR)/spot_0.1bpp: %.1bpp: %.png
+	$(GFX) $< $@ -plain -data_width 4
+
+$(GYARADOSGFXDIR)/spot_1.1bpp: %.1bpp: %.png
+	$(GFX) $< $@ -plain -data_width 4
+
+$(GYARADOSGFXDIR)/spot_2.1bpp: %.1bpp: %.png
+	$(GFX) $< $@ -plain -data_width 4
+
+$(GYARADOSGFXDIR)/spot_3.1bpp: %.1bpp: %.png
+	$(GFX) $< $@ -plain -data_width 4

```
The data width for Gyarados spots is 4 because each spot is 32 pixels wide. A tile is 8 pixels so each row has 4 tiles.

## Adding spots

To add spots to a Pokemon first we must define where the spots go on the Pokemon.

Spots can be of sizes `8x8`, `16x16` or `32x32`
A species can have up to 4 spots.

```c

static const struct MonSpot sGyaradosSpots[] = {
    {.x = 16, .y = 32, .image = sGyaradosSpotImages[0]},
    {.x = 32, .y = 8,  .image = sGyaradosSpotImages[1]},
    {.x = 54, .y = 40, .image = sGyaradosSpotImages[2]},
    {.x = 26, .y = 26, .image = sGyaradosSpotImages[3]},
};

```

Now we define the spot template. This struct contains the spots for the Pokemon and the information needed to draw them.

```c
const struct MonSpotTemplate gGyaradosSpotTemplate = {
    .spots = sGyaradosSpots,
    .count = ARRAY_COUNT(sGyaradosSpots),
    .scale = SCALE_2,
    .xOffsetFrame2 = 4,
    .yOffsetFrame2 = 8,
    .firstColor = 6,
    .lastColor = 8,
    .colorAdjust = 6,
};
```

- Here `scale` is the size of the spot divided by 8 (we only expect square spots). So for Spinda the scale is 2 and for Gyarados it is 4.

- The two frame offsets are used to adjust the spot position when the Pokemon does it's animation.

- `firstColor` and `lastColor` are used to limit the colors on the Pokemon's sprite palette where spots can be drawn. This is used to limit Spinda spots to Spinda's body. `colorAdjust` is determines how much the color is incremented to draw a spot.

For example, if a spot is being drawn on a Gyarados' body which uses color index `6` and the adjust is `6` the spot's color would be `12`.

## Making the spots appear

Now finally, to make the spots actually appear we have to mark this Pokemon as a spotted species. We do this by adding it to the switch statement in `GetSpeciesSpots`:

```diff
diff --git a/src/pokemon_spots.c b/src/pokemon_spots.c
index 166d601f1e..1d2ced034e 100644
--- a/src/pokemon_spots.c
+++ b/src/pokemon_spots.c
 static const struct MonSpotTemplate* GetSpeciesSpots(enum Species species)
@@ -113,6 +138,8 @@ static const struct MonSpotTemplate* GetSpeciesSpots(enum Species species)
     {
         case SPECIES_SPINDA:
             return &gSpindaSpotTemplate;
+        case SPECIES_GYARADOS:
+            return &gGyaradosSpotTemplate;
         default:
             return NULL;
     }

```

And that's it. Your new spotted Pokemon is ready!


