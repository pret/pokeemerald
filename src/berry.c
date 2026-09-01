#include "global.h"
#include "berry.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"
#include "constants/event_object_movement.h"
#include "constants/items.h"

static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree);
static u8 GetNumStagesWateredByBerryTreeId(u8 id);
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water);
static u8 CalcBerryYield(struct BerryTree *tree);
static u32 GetBerryTreeAge(u8 id, u8 stage);
static u8 GetBerryCountByBerryTreeId(u8 id);
static u16 GetStageDurationByBerryType(u8);
static u8 GetDrainRateByBerryType(u8);
static u8 GetWaterBonusByBerryType(u8);
static u8 GetWeedingBonusByBerryType(u8);
static u8 GetPestsBonusByBerryType(u8);
static void SetTreeMutations(u8 id, u8 berry);
static u8 GetTreeMutationValue(u8 id);
static enum Species GetBerryPestSpecies(u8 berryId);
static void TryForWeeds(struct BerryTree *tree);
static void TryForPests(struct BerryTree *tree);
static void AddTreeBonus(struct BerryTree *tree, u8 bonus);

// Check include/config/overworld.h configs and throw an error if illegal
#if OW_BERRY_GROWTH_RATE < GEN_3 || (OW_BERRY_GROWTH_RATE > GEN_7 && OW_BERRY_GROWTH_RATE != GEN_6_ORAS)
#error "OW_BERRY_GROWTH_RATE must be between GEN_3 and GEN_7!"
#endif

#if OW_BERRY_YIELD_RATE < GEN_3 || (OW_BERRY_YIELD_RATE > GEN_6 && OW_BERRY_YIELD_RATE != GEN_6_ORAS)
#error "OW_BERRY_YIELD_RATE must be between GEN_3 and GEN_6!"
#elif OW_BERRY_YIELD_RATE == GEN_5
#error "OW_BERRY_YIELD_RATE can not be GEN_5!"
#endif

#if OW_BERRY_MOISTURE && OW_BERRY_DRAIN_RATE != GEN_4 && OW_BERRY_DRAIN_RATE != GEN_6_XY && OW_BERRY_DRAIN_RATE != GEN_6_ORAS
#error "OW_BERRY_DRAIN_RATE must be GEN_5, GEN_6_XY or GEN_6_ORAS!"
#endif

#if OW_BERRY_COLORS != GEN_6_XY && OW_BERRY_COLORS != GEN_6_ORAS
#error "OW_BERRY_COLORS must be GEN_6_XY or GEN_6_ORAS!"
#endif

#define GROWTH_DURATION(g3, g4, g5, xy, oras, g7) OW_BERRY_GROWTH_RATE == GEN_3 ? g3 : OW_BERRY_GROWTH_RATE == GEN_4 ? g4 : OW_BERRY_GROWTH_RATE == GEN_5 ? g5 : OW_BERRY_GROWTH_RATE == GEN_6_XY ? xy : OW_BERRY_GROWTH_RATE == GEN_6_ORAS ? oras : g7
#define YIELD_RATE(g3, g4, xy, oras) OW_BERRY_YIELD_RATE == GEN_3 ? g3 : OW_BERRY_YIELD_RATE == GEN_4 ? g4 : OW_BERRY_YIELD_RATE == GEN_6_XY ? xy : oras

const struct Berry gBerries[NUM_BERRIES + 1] =
{
    [BERRY_ID_NONE] = {
        .info = {
            .name = _("?????"),
            .description1 = COMPOUND_STRING("????????"),
            .description2 = COMPOUND_STRING("????????"),
        },
        .berryPic = gBerryPic_Enigma,
        .berryPal =  gBerryPalette_Enigma,
        .berryTreePicTable = gPicTable_DurinBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Durin,
    },
    [BERRY_ID_CHERI] =
    {
        .info = {
            .name = _("Cheri"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_RED,
            .size = 20,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("Blooms with delicate pretty flowers."),
            .description2 = COMPOUND_STRING("The bright red Berry is very spicy."),
            .growthDuration = GROWTH_DURATION(12, 12, 18, 24, 16, 24),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FIRE,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  20,
        .berryPic = gBerryPic_Cheri,
        .berryPal =  gBerryPalette_Cheri,
        .berryTreePicTable = gPicTable_CheriBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Cheri,
    },

    [BERRY_ID_CHESTO] =
    {
        .info = {
            .name = _("Chesto"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 80,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("The Berry's thick skin and fruit are"),
            .description2 = COMPOUND_STRING("very tough. It is dry-tasting all over."),
            .growthDuration = GROWTH_DURATION(12, 12, 18, 24, 16, 24),
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_WATER,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  20,
        .berryPic = gBerryPic_Chesto,
        .berryPal = gBerryPalette_Chesto,
        .berryTreePicTable = gPicTable_ChestoBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Chesto,
    },

    [BERRY_ID_PECHA] =
    {
        .info = {
            .name = _("Pecha"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = BERRY_COLOR_PINK,
            .size = 40,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("Very sweet and delicious."),
            .description2 = COMPOUND_STRING("Also very tender - handle with care."),
            .growthDuration = GROWTH_DURATION(12, 12, 18, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 4,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ELECTRIC,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  20,
        .berryPic = gBerryPic_Pecha,
        .berryPal =  gBerryPalette_Pecha,
        .berryTreePicTable = gPicTable_PechaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Pecha,
    },

    [BERRY_ID_RAWST] =
    {
        .info = {
            .name = _("Rawst"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 32,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("If the leaves grow long and curly,"),
            .description2 = COMPOUND_STRING("the Berry seems to grow very bitter."),
            .growthDuration = GROWTH_DURATION(12, 12, 18, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_GRASS,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  20,
        .berryPic = gBerryPic_Rawst,
        .berryPal =  gBerryPalette_Rawst,
        .berryTreePicTable = gPicTable_RawstBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Rawst,
    },

    [BERRY_ID_ASPEAR] =
    {
        .info = {
            .name = _("Aspear"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_YELLOW,
            .size = 50,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("The hard Berry is dense with a rich"),
            .description2 = COMPOUND_STRING("juice. It is quite sour."),
            .growthDuration = GROWTH_DURATION(12, 12, 18, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 25,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ICE,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  20,
        .berryPic = gBerryPic_Aspear,
        .berryPal = gBerryPalette_Aspear,
        .berryTreePicTable = gPicTable_AspearBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Aspear,
    },

    [BERRY_ID_LEPPA] =
    {
        .info = {
            .name = _("Leppa"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_RED,
            .size = 28,
            .maxYield = YIELD_RATE(3, 5, 15, 22),
            .minYield = YIELD_RATE(2, 2, 2, 2),
            .description1 = COMPOUND_STRING("Grows slower than Cheri and others."),
            .description2 = COMPOUND_STRING("The smaller the Berry, the tastier."),
            .growthDuration = GROWTH_DURATION(16, 16, 24, 24, 16, 24),
            .spicy = 10,
            .dry = 0,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 15,
            .waterBonus = 15,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FIGHTING,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Leppa,
        .berryPal =  gBerryPalette_Leppa,
        .berryTreePicTable = gPicTable_LeppaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Leppa,
    },

    [BERRY_ID_ORAN] =
    {
        .info = {
            .name = _("Oran"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_BLUE,
            .size = 35,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("A peculiar Berry with a mix of flavors."),
            .description2 = COMPOUND_STRING("Berries grow in half a day."),
            .growthDuration = GROWTH_DURATION(12, 16, 24, 24, 16, 24),
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 4,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_POISON,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Oran,
        .berryPal =   gBerryPalette_Oran,
        .berryTreePicTable = gPicTable_OranBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Oran,
    },

    [BERRY_ID_PERSIM] =
    {
        .info = {
            .name = _("Persim"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_PINK,
            .size = 47,
            .maxYield = YIELD_RATE(3, 5, 15, 20),
            .minYield = YIELD_RATE(2, 2, 4, 4),
            .description1 = COMPOUND_STRING("Loves sunlight. The Berry's color"),
            .description2 = COMPOUND_STRING("grows vivid when exposed to the sun."),
            .growthDuration = GROWTH_DURATION(12, 16, 24, 24, 16, 24),
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 15,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_GROUND,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Persim,
        .berryPal = gBerryPalette_Persim,
        .berryTreePicTable = gPicTable_PersimBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Persim,
    },

    [BERRY_ID_LUM] =
    {
        .info = {
            .name = _("Lum"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 34,
            .maxYield = YIELD_RATE(2, 5, 20, 18),
            .minYield = YIELD_RATE(1, 2, 3, 2),
            .description1 = COMPOUND_STRING("Slow to grow. If raised with loving"),
            .description2 = COMPOUND_STRING("care, it may grow two Berries."),
            .growthDuration = GROWTH_DURATION(48, 48, 72, 48, 32, 48),
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 8,
            .waterBonus = 12,
            .weedsBonus = 1,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FLYING,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Lum,
        .berryPal =    gBerryPalette_Lum,
        .berryTreePicTable = gPicTable_LumBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Lum,
    },

    [BERRY_ID_SITRUS] =
    {
        .info = {
            .name = _("Sitrus"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_YELLOW,
            .size = 95,
            .maxYield = YIELD_RATE(3, 5, 20, 27),
            .minYield = YIELD_RATE(2, 2, 3, 3),
            .description1 = COMPOUND_STRING("Closely related to Oran. The large"),
            .description2 = COMPOUND_STRING("Berry has a well-rounded flavor."),
            .growthDuration = GROWTH_DURATION(24, 32, 48, 48, 32, 48),
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 7,
            .waterBonus = 12,
            .weedsBonus = 1,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_PSYCHIC,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Sitrus,
        .berryPal = gBerryPalette_Sitrus,
        .berryTreePicTable = gPicTable_SitrusBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Sitrus,
    },

    [BERRY_ID_FIGY] =
    {
        .info = {
            .name = _("Figy"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_RED,
            .size = 100,
            .maxYield = YIELD_RATE(3, 5, 15, 15),
            .minYield = YIELD_RATE(2, 1, 3, 3),
            .description1 = COMPOUND_STRING("The Berry, which looks chewed up,"),
            .description2 = COMPOUND_STRING("brims with spicy substances."),
            .growthDuration = GROWTH_DURATION(24, 20, 30, 24, 16, 24),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 10,
            .waterBonus = 15,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_BUG,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Figy,
        .berryPal =   gBerryPalette_Figy,
        .berryTreePicTable = gPicTable_FigyBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Figy,
    },

    [BERRY_ID_WIKI] =
    {
        .info = {
            .name = _("Wiki"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 115,
            .maxYield = YIELD_RATE(3, 5, 15, 15),
            .minYield = YIELD_RATE(2, 1, 3, 3),
            .description1 = COMPOUND_STRING("The Berry is said to have grown lumpy"),
            .description2 = COMPOUND_STRING("to help Pokémon grip it."),
            .growthDuration = GROWTH_DURATION(24, 20, 30, 24, 16, 24),
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 10,
            .waterBonus = 15,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ROCK,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Wiki,
        .berryPal =   gBerryPalette_Wiki,
        .berryTreePicTable = gPicTable_WikiBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Wiki,
    },

    [BERRY_ID_MAGO] =
    {
        .info = {
            .name = _("Mago"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_PINK,
            .size = 126,
            .maxYield = YIELD_RATE(3, 5, 15, 15),
            .minYield = YIELD_RATE(2, 1, 3, 3),
            .description1 = COMPOUND_STRING("The Berry turns curvy as it grows."),
            .description2 = COMPOUND_STRING("The curvier, the sweeter and tastier."),
            .growthDuration = GROWTH_DURATION(24, 20, 30, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 10,
            .waterBonus = 15,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_GHOST,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Mago,
        .berryPal =   gBerryPalette_Mago,
        .berryTreePicTable = gPicTable_MagoBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Mago,
    },

    [BERRY_ID_AGUAV] =
    {
        .info = {
            .name = _("Aguav"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 64,
            .maxYield = YIELD_RATE(3, 5, 15, 15),
            .minYield = YIELD_RATE(2, 1, 3, 3),
            .description1 = COMPOUND_STRING("The flower is dainty. It is rare in its"),
            .description2 = COMPOUND_STRING("ability to grow without light."),
            .growthDuration = GROWTH_DURATION(24, 20, 30, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 25,
            .drainRate = 10,
            .waterBonus = 15,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_DRAGON,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Aguav,
        .berryPal =  gBerryPalette_Aguav,
        .berryTreePicTable = gPicTable_AguavBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Aguav,
    },

    [BERRY_ID_IAPAPA] =
    {
        .info = {
            .name = _("Iapapa"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 223,
            .maxYield = YIELD_RATE(3, 5, 15, 15),
            .minYield = YIELD_RATE(2, 1, 3, 3),
            .description1 = COMPOUND_STRING("The Berry is very big and sour."),
            .description2 = COMPOUND_STRING("It takes at least a day to grow."),
            .growthDuration = GROWTH_DURATION(24, 20, 30, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 25,
            .drainRate = 10,
            .waterBonus = 15,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_DARK,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Iapapa,
        .berryPal = gBerryPalette_Iapapa,
        .berryTreePicTable = gPicTable_IapapaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Iapapa,
    },

    [BERRY_ID_RAZZ] =
    {
        .info = {
            .name = _("Razz"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_RED,
            .size = 120,
            .maxYield = YIELD_RATE(6, 10, 15, 20),
            .minYield = YIELD_RATE(3, 2, 3, 4),
            .description1 = COMPOUND_STRING("The red Berry tastes slightly spicy."),
            .description2 = COMPOUND_STRING("It grows quickly in just four hours."),
            .growthDuration = GROWTH_DURATION(4, 8, 12, 24, 16, 24),
            .spicy = 10,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 20,
            .drainRate = 35,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_STEEL,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  70,
        .berryPic = gBerryPic_Razz,
        .berryPal =   gBerryPalette_Razz,
        .berryTreePicTable = gPicTable_RazzBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Razz,
    },

    [BERRY_ID_BLUK] =
    {
        .info = {
            .name = _("Bluk"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 108,
            .maxYield = YIELD_RATE(6, 10, 15, 20),
            .minYield = YIELD_RATE(3, 2, 3, 4),
            .description1 = COMPOUND_STRING("The Berry is blue on the outside, but"),
            .description2 = COMPOUND_STRING("it blackens the mouth when eaten."),
            .growthDuration = GROWTH_DURATION(4, 8, 12, 24, 16, 24),
            .spicy = 0,
            .dry = 10,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 20,
            .drainRate = 35,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FIRE,
        .naturalGiftPower = 90,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  70,
        .berryPic = gBerryPic_Bluk,
        .berryPal =   gBerryPalette_Bluk,
        .berryTreePicTable = gPicTable_RazzBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Razz,
    },

    [BERRY_ID_NANAB] =
    {
        .info = {
            .name = _("Nanab"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_PINK,
            .size = 77,
            .maxYield = YIELD_RATE(6, 10, 15, 20),
            .minYield = YIELD_RATE(3, 2, 3, 4),
            .description1 = COMPOUND_STRING("This Berry was the seventh"),
            .description2 = COMPOUND_STRING("discovered in the world. It is sweet."),
            .growthDuration = GROWTH_DURATION(4, 8, 12, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 10,
            .sour = 0,
            .smoothness = 20,
            .drainRate = 35,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_WATER,
        .naturalGiftPower = 90,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  70,
        .berryPic = gBerryPic_Nanab,
        .berryPal =  gBerryPalette_Nanab,
        .berryTreePicTable = gPicTable_MagoBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Mago,
    },

    [BERRY_ID_WEPEAR] =
    {
        .info = {
            .name = _("Wepear"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 74,
            .maxYield = YIELD_RATE(6, 10, 15, 20),
            .minYield = YIELD_RATE(3, 2, 3, 4),
            .description1 = COMPOUND_STRING("The flower is small and white. It has a"),
            .description2 = COMPOUND_STRING("delicate balance of bitter and sour."),
            .growthDuration = GROWTH_DURATION(4, 8, 12, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 35,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ELECTRIC,
        .naturalGiftPower = 90,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  70,
        .berryPic = gBerryPic_Wepear,
        .berryPal = gBerryPalette_Wepear,
        .berryTreePicTable = gPicTable_WepearBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Wepear,
    },

    [BERRY_ID_PINAP] =
    {
        .info = {
            .name = _("Pinap"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_YELLOW,
            .size = 80,
            .maxYield = YIELD_RATE(6, 10, 15, 20),
            .minYield = YIELD_RATE(3, 2, 3, 4),
            .description1 = COMPOUND_STRING("Weak against wind and cold."),
            .description2 = COMPOUND_STRING("The fruit is spicy and the skin, sour."),
            .growthDuration = GROWTH_DURATION(4, 8, 12, 24, 16, 24),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 35,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_GRASS,
        .naturalGiftPower = 90,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  70,
        .berryPic = gBerryPic_Pinap,
        .berryPal =  gBerryPalette_Pinap,
        .berryTreePicTable = gPicTable_IapapaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Iapapa,
    },

    [BERRY_ID_POMEG] =
    {
        .info = {
            .name = _("Pomeg"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_RED,
            .size = 135,
            .maxYield = YIELD_RATE(6, 5, 20, 26),
            .minYield = YIELD_RATE(2, 1, 1, 2),
            .description1 = COMPOUND_STRING("However much it is watered,"),
            .description2 = COMPOUND_STRING("it only grows up to six Berries."),
            .growthDuration = GROWTH_DURATION(12, 32, 48, 48, 32, 48),
            .spicy = 10,
            .dry = 0,
            .sweet = 10,
            .bitter = 10,
            .sour = 0,
            .smoothness = 20,
            .drainRate = 8,
            .waterBonus = 5,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ICE,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 100,
        .berryCrushPowder = 100,
        .berryPic = gBerryPic_Pomeg,
        .berryPal =  gBerryPalette_Pomeg,
        .berryTreePicTable = gPicTable_PomegBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Pomeg,
    },

    [BERRY_ID_KELPSY] =
    {
        .info = {
            .name = _("Kelpsy"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_BLUE,
            .size = 150,
            .maxYield = YIELD_RATE(6, 5, 20, 26),
            .minYield = YIELD_RATE(2, 1, 1, 2),
            .description1 = COMPOUND_STRING("A rare variety shaped like a root."),
            .description2 = COMPOUND_STRING("Grows a very large flower."),
            .growthDuration = GROWTH_DURATION(12, 32, 48, 48, 32, 48),
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 8,
            .waterBonus = 5,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FIGHTING,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 100,
        .berryCrushPowder = 100,
        .berryPic = gBerryPic_Kelpsy,
        .berryPal = gBerryPalette_Kelpsy,
        .berryTreePicTable = gPicTable_KelpsyBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Kelpsy,
    },

    [BERRY_ID_QUALOT] =
    {
        .info = {
            .name = _("Qualot"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_YELLOW : BERRY_COLOR_PINK,
            .size = 110,
            .maxYield = YIELD_RATE(6, 5, 20, 26),
            .minYield = YIELD_RATE(2, 1, 1, 2),
            .description1 = COMPOUND_STRING("Loves water. Grows strong even in"),
            .description2 = COMPOUND_STRING("locations with constant rainfall."),
            .growthDuration = GROWTH_DURATION(12, 32, 48, 48, 32, 48),
            .spicy = 10,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 8,
            .waterBonus = 5,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_POISON,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 100,
        .berryCrushPowder = 100,
        .berryPic = gBerryPic_Qualot,
        .berryPal = gBerryPalette_Qualot,
        .berryTreePicTable = gPicTable_WepearBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Wepear,
    },

    [BERRY_ID_HONDEW] =
    {
        .info = {
            .name = _("Hondew"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 162,
            .maxYield = YIELD_RATE(6, 5, 20, 26),
            .minYield = YIELD_RATE(2, 1, 1, 2),
            .description1 = COMPOUND_STRING("A Berry that is very valuable and"),
            .description2 = COMPOUND_STRING("rarely seen. It is very delicious."),
            .growthDuration = GROWTH_DURATION(12, 32, 48, 48, 32, 48),
            .spicy = 10,
            .dry = 10,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 20,
            .drainRate = 8,
            .waterBonus = 5,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_GROUND,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 100,
        .berryCrushPowder = 100,
        .berryPic = gBerryPic_Hondew,
        .berryPal = gBerryPalette_Hondew,
        .berryTreePicTable = gPicTable_HondewBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Hondew,
    },

    [BERRY_ID_GREPA] =
    {
        .info = {
            .name = _("Grepa"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 149,
            .maxYield = YIELD_RATE(6, 5, 20, 26),
            .minYield = YIELD_RATE(2, 1, 1, 2),
            .description1 = COMPOUND_STRING("Despite its tenderness and round"),
            .description2 = COMPOUND_STRING("shape, the Berry is unimaginably sour."),
            .growthDuration = GROWTH_DURATION(12, 32, 48, 48, 32, 48),
            .spicy = 0,
            .dry = 10,
            .sweet = 10,
            .bitter = 0,
            .sour = 10,
            .smoothness = 20,
            .drainRate = 8,
            .waterBonus = 5,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FLYING,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 100,
        .berryCrushPowder = 100,
        .berryPic = gBerryPic_Grepa,
        .berryPal =  gBerryPalette_Grepa,
        .berryTreePicTable = gPicTable_GrepaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Grepa,
    },

    [BERRY_ID_TAMATO] =
    {
        .info = {
            .name = _("Tamato"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_RED,
            .size = 200,
            .maxYield = YIELD_RATE(4, 5, 20, 26),
            .minYield = YIELD_RATE(2, 1, 1, 2),
            .description1 = COMPOUND_STRING("The Berry is lip-bendingly spicy."),
            .description2 = COMPOUND_STRING("It takes time to grow."),
            .growthDuration = GROWTH_DURATION(24, 32, 48, 48, 32, 48),
            .spicy = 20,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 8,
            .waterBonus = 5,
            .weedsBonus = 3,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_PSYCHIC,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 150,
        .berryPic = gBerryPic_Tamato,
        .berryPal = gBerryPalette_Tamato,
        .berryTreePicTable = gPicTable_TamatoBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Tamato,
    },

    [BERRY_ID_CORNN] =
    {
        .info = {
            .name = _("Cornn"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 75,
            .maxYield = YIELD_RATE(4, 10, 15, 15),
            .minYield = YIELD_RATE(2, 2, 3, 3),
            .description1 = COMPOUND_STRING("A Berry from an ancient era. May not"),
            .description2 = COMPOUND_STRING("grow unless planted in quantity."),
            .growthDuration = GROWTH_DURATION(24, 24, 36, 24, 16, 24),
            .spicy = 0,
            .dry = 20,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 10,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_BUG,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 150,
        .berryPic = gBerryPic_Cornn,
        .berryPal =  gBerryPalette_Cornn,
        .berryTreePicTable = gPicTable_CornnBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Cornn,
    },

    [BERRY_ID_MAGOST] =
    {
        .info = {
            .name = _("Magost"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_PINK,
            .size = 140,
            .maxYield = YIELD_RATE(4, 10, 15, 15),
            .minYield = YIELD_RATE(2, 2, 3, 3),
            .description1 = COMPOUND_STRING("A Berry that is widely said to have"),
            .description2 = COMPOUND_STRING("a finely balanced flavor."),
            .growthDuration = GROWTH_DURATION(24, 24, 36, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 20,
            .bitter = 10,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 10,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ROCK,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 150,
        .berryPic = gBerryPic_Magost,
        .berryPal = gBerryPalette_Magost,
        .berryTreePicTable = gPicTable_PomegBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Pomeg,
    },

    [BERRY_ID_RABUTA] =
    {
        .info = {
            .name = _("Rabuta"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_GREEN,
            .size = 226,
            .maxYield = YIELD_RATE(4, 10, 15, 15),
            .minYield = YIELD_RATE(2, 2, 3, 3),
            .description1 = COMPOUND_STRING("A rare variety that is overgrown with"),
            .description2 = COMPOUND_STRING("hair. It is quite bitter."),
            .growthDuration = GROWTH_DURATION(24, 24, 36, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 20,
            .sour = 10,
            .smoothness = 30,
            .drainRate = 10,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_GHOST,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 150,
        .berryPic = gBerryPic_Rabuta,
        .berryPal = gBerryPalette_Rabuta,
        .berryTreePicTable = gPicTable_RabutaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Rabuta,
    },

    [BERRY_ID_NOMEL] =
    {
        .info = {
            .name = _("Nomel"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_YELLOW,
            .size = 285,
            .maxYield = YIELD_RATE(4, 10, 15, 15),
            .minYield = YIELD_RATE(2, 2, 3, 3),
            .description1 = COMPOUND_STRING("Quite sour. Just one bite makes it"),
            .description2 = COMPOUND_STRING("impossible to taste for three days."),
            .growthDuration = GROWTH_DURATION(24, 24, 36, 24, 16, 24),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 20,
            .smoothness = 30,
            .drainRate = 10,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_DRAGON,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 150,
        .berryPic = gBerryPic_Nomel,
        .berryPal =  gBerryPalette_Nomel,
        .berryTreePicTable = gPicTable_NomelBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Nomel,
    },

    [BERRY_ID_SPELON] =
    {
        .info = {
            .name = _("Spelon"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_RED : BERRY_COLOR_PINK,
            .size = 133,
            .maxYield = YIELD_RATE(2, 15, 15, 15),
            .minYield = YIELD_RATE(1, 2, 3, 3),
            .description1 = COMPOUND_STRING("The vividly red Berry is very spicy."),
            .description2 = COMPOUND_STRING("Its warts secrete a spicy substance."),
            .growthDuration = GROWTH_DURATION(72, 60, 90, 24, 16, 24),
            .spicy = 40,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 70,
            .drainRate = 8,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_DARK,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Spelon,
        .berryPal = gBerryPalette_Spelon,
        .berryTreePicTable = gPicTable_SpelonBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Spelon,
    },

    [BERRY_ID_PAMTRE] =
    {
        .info = {
            .name = _("Pamtre"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 244,
            .maxYield = YIELD_RATE(2, 15, 15, 15),
            .minYield = YIELD_RATE(1, 3, 3, 3),
            .description1 = COMPOUND_STRING("Drifts on the sea from somewhere."),
            .description2 = COMPOUND_STRING("It is thought to grow elsewhere."),
            .growthDuration = GROWTH_DURATION(72, 60, 90, 24, 16, 24),
            .spicy = 0,
            .dry = 40,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 70,
            .drainRate = 8,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_STEEL,
        .naturalGiftPower = 90,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Pamtre,
        .berryPal = gBerryPalette_Pamtre,
        .berryTreePicTable = gPicTable_PamtreBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Pamtre,
    },

    [BERRY_ID_WATMEL] =
    {
        .info = {
            .name = _("Watmel"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PINK : BERRY_COLOR_GREEN,
            .size = 250,
            .maxYield = YIELD_RATE(2, 15, 15, 15),
            .minYield = YIELD_RATE(1, 2, 3, 3),
            .description1 = COMPOUND_STRING("A huge Berry, with some over 20"),
            .description2 = COMPOUND_STRING("inches discovered. Exceedingly sweet."),
            .growthDuration = GROWTH_DURATION(72, 60, 90, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 40,
            .bitter = 10,
            .sour = 0,
            .smoothness = 70,
            .drainRate = 8,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_FIRE,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Watmel,
        .berryPal = gBerryPalette_Watmel,
        .berryTreePicTable = gPicTable_RabutaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Rabuta,
    },

    [BERRY_ID_DURIN] =
    {
        .info = {
            .name = _("Durin"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 280,
            .maxYield = YIELD_RATE(2, 15, 15, 15),
            .minYield = YIELD_RATE(1, 3, 3, 3),
            .description1 = COMPOUND_STRING("Bitter to even look at. It is so"),
            .description2 = COMPOUND_STRING("bitter, no one has ever eaten it as is."),
            .growthDuration = GROWTH_DURATION(72, 60, 90, 24, 16, 24),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 40,
            .sour = 10,
            .smoothness = 70,
            .drainRate = 8,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_WATER,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Durin,
        .berryPal =  gBerryPalette_Durin,
        .berryTreePicTable = gPicTable_DurinBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Durin,
    },

    [BERRY_ID_BELUE] =
    {
        .info = {
            .name = _("Belue"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 300,
            .maxYield = YIELD_RATE(2, 15, 15, 15),
            .minYield = YIELD_RATE(1, 2, 3, 3),
            .description1 = COMPOUND_STRING("It is glossy and looks delicious, but"),
            .description2 = COMPOUND_STRING("it is awfully sour. Takes time to grow."),
            .growthDuration = GROWTH_DURATION(72, 60, 90, 24, 16, 24),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 40,
            .smoothness = 70,
            .drainRate = 8,
            .waterBonus = 10,
            .weedsBonus = 2,
            .pestsBonus = 6,
        },
        .naturalGiftType = TYPE_ELECTRIC,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Belue,
        .berryPal =  gBerryPalette_Belue,
        .berryTreePicTable = gPicTable_HondewBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Hondew,
    },

    [BERRY_ID_OCCA] =
    {
        .info = {
            .name = _("Occa"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_RED,
            .size = 90,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Said to grow in the tropics once,"),
            .description2 = COMPOUND_STRING("it boasts an intensely hot spiciness."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 15,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_FIRE,
        .naturalGiftPower = 80,
        .berryCrushDifficulty = 100,
        .berryCrushPowder = 100,
        .berryPic = gBerryPic_Occa,
        .berryPal = gBerryPalette_Occa,
        .berryTreePicTable = gPicTable_OccaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Occa,
    },

    [BERRY_ID_PASSHO] =
    {
        .info = {
            .name = _("Passho"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_BLUE,
            .size = 33,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Its flesh is dotted with many tiny"),
            .description2 = COMPOUND_STRING("bubbles that keep it afloat in water."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 15,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_WATER,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Passho,
        .berryPal = gBerryPalette_Passho,
        .berryTreePicTable = gPicTable_CornnBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Cornn,
    },

    [BERRY_ID_WACAN] =
    {
        .info = {
            .name = _("Wacan"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 250,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Energy drawn from lightning strikes"),
            .description2 = COMPOUND_STRING("makes this Berry grow big and rich."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 0,
            .sweet = 15,
            .bitter = 0,
            .sour = 10,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_ELECTRIC,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Wacan,
        .berryPal = gBerryPalette_Wacan,
        .berryTreePicTable = gPicTable_RazzBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Razz,
    },

    [BERRY_ID_RINDO] =
    {
        .info = {
            .name = _("Rindo"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_GREEN,
            .size = 156,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("This berry has a vegetable-like flavor,"),
            .description2 = COMPOUND_STRING("but is rich in health-promoting fiber."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 15,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_GRASS,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Rindo,
        .berryPal = gBerryPalette_Rindo,
        .berryTreePicTable = gPicTable_TamatoBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Tamato,
    },

    [BERRY_ID_YACHE] =
    {
        .info = {
            .name = _("Yache"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_BLUE,
            .size = 135,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("This Berry has a refreshing dry and"),
            .description2 = COMPOUND_STRING("sour flavor. Tastes better chilled."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 15,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_ICE,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Yache,
        .berryPal = gBerryPalette_Yache,
        .berryTreePicTable = gPicTable_YacheBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Yache,
    },

    [BERRY_ID_CHOPLE] =
    {
        .info = {
            .name = _("Chople"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_RED,
            .size = 77,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Contains a substance that generates"),
            .description2 = COMPOUND_STRING("heat. Can even fire up a chilly heart."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 15,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_FIGHTING,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Chople,
        .berryPal = gBerryPalette_Chople,
        .berryTreePicTable = gPicTable_ChopleBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Chople,
    },

    [BERRY_ID_KEBIA] =
    {
        .info = {
            .name = _("Kebia"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 90,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Brilliant green on the outside, inside"),
            .description2 = COMPOUND_STRING("it is packed with black-colored flesh."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 15,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_POISON,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Kebia,
        .berryPal = gBerryPalette_Kebia,
        .berryTreePicTable = gPicTable_KebiaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Kebia,
    },

    [BERRY_ID_SHUCA] =
    {
        .info = {
            .name = _("Shuca"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 42,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("The sweet pulp has just the hint of a"),
            .description2 = COMPOUND_STRING("a hard-edged and fragrant bite to it."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 10,
            .dry = 0,
            .sweet = 15,
            .bitter = 0,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_GROUND,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  20,
        .berryPic = gBerryPic_Shuca,
        .berryPal = gBerryPalette_Shuca,
        .berryTreePicTable = gPicTable_ShucaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Shuca,
    },

    [BERRY_ID_COBA] =
    {
        .info = {
            .name = _("Coba"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_BLUE,
            .size = 278,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("This Berry is said to be a cross of"),
            .description2 = COMPOUND_STRING("two Berries blown in from far away."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 15,
            .sour = 0,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_FLYING,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Coba,
        .berryPal = gBerryPalette_Coba,
        .berryTreePicTable = gPicTable_RawstBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Rawst,
    },

    [BERRY_ID_PAYAPA] =
    {
        .info = {
            .name = _("Payapa"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_RED,
            .size = 252,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Said to sense human emotions, it swells"),
            .description2 = COMPOUND_STRING("roundly when a person approaches."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 15,
            .smoothness = 30,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_PSYCHIC,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Payapa,
        .berryPal = gBerryPalette_Payapa,
        .berryTreePicTable = gPicTable_PayapaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Payapa,
    },

    [BERRY_ID_TANGA] =
    {
        .info = {
            .name = _("Tanga"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = BERRY_COLOR_GREEN,
            .size = 42,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("It grows a flower at the tip that lures"),
            .description2 = COMPOUND_STRING("Bug Pokémon with its stringy petals."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 20,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_BUG,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Tanga,
        .berryPal = gBerryPalette_Tanga,
        .berryTreePicTable = gPicTable_TangaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Tanga,
    },

    [BERRY_ID_CHARTI] =
    {
        .info = {
            .name = _("Charti"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 28,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Often used for pickles because of its"),
            .description2 = COMPOUND_STRING("dry flavor. Sometimes eaten raw."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 10,
            .dry = 20,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_ROCK,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Charti,
        .berryPal = gBerryPalette_Charti,
        .berryTreePicTable = gPicTable_LansatBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Lansat,
    },

    [BERRY_ID_KASIB] =
    {
        .info = {
            .name = _("Kasib"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_PINK,
            .size = 144,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Old superstitions say it has an odd"),
            .description2 = COMPOUND_STRING("power. A popular good-luck charm."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 10,
            .sweet = 20,
            .bitter = 0,
            .sour = 0,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_GHOST,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Kasib,
        .berryPal = gBerryPalette_Kasib,
        .berryTreePicTable = gPicTable_KasibBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Kasib,
    },

    [BERRY_ID_HABAN] =
    {
        .info = {
            .name = _("Haban"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_RED,
            .size = 23,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Less bitter if enough of this Berry"),
            .description2 = COMPOUND_STRING("is boiled down. Makes a good jam."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 20,
            .sour = 0,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_DRAGON,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  50,
        .berryCrushPowder =  30,
        .berryPic = gBerryPic_Haban,
        .berryPal = gBerryPalette_Haban,
        .berryTreePicTable = gPicTable_HabanBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Haban,
    },

    [BERRY_ID_COLBUR] =
    {
        .info = {
            .name = _("Colbur"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_PINK,
            .size = 39,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Tiny hooks on the surface latch onto"),
            .description2 = COMPOUND_STRING("Pokémon to reach far-off places."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 20,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_DARK,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Colbur,
        .berryPal = gBerryPalette_Colbur,
        .berryTreePicTable = gPicTable_ColburBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Colbur,
    },

    [BERRY_ID_BABIRI] =
    {
        .info = {
            .name = _("Babiri"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 265,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("Very tough with a strong flavor. It"),
            .description2 = COMPOUND_STRING("was used to make medicine in the past."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 25,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_STEEL,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Babiri,
        .berryPal = gBerryPalette_Babiri,
        .berryTreePicTable = gPicTable_LiechiBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Liechi,
    },

    [BERRY_ID_CHILAN] =
    {
        .info = {
            .name = _("Chilan"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 34,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("It can be made into a whistle that"),
            .description2 = COMPOUND_STRING("produces an indescribable sound."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 25,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_NORMAL,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  80,
        .berryCrushPowder =  70,
        .berryPic = gBerryPic_Chilan,
        .berryPal = gBerryPalette_Chilan,
        .berryTreePicTable = gPicTable_GrepaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Grepa,
    },

    [BERRY_ID_LIECHI] =
    {
        .info = {
            .name = _("Liechi"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_RED : BERRY_COLOR_YELLOW,
            .size = 111,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("A mysterious Berry. It is rumored to"),
            .description2 = COMPOUND_STRING("contain the power of the sea."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 40,
            .dry = 0,
            .sweet = 40,
            .bitter = 0,
            .sour = 10,
            .smoothness = 80,
            .drainRate = 4,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_GRASS,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 180,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Liechi,
        .berryPal = gBerryPalette_Liechi,
        .berryTreePicTable = gPicTable_LiechiBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Liechi,
    },

    [BERRY_ID_GANLON] =
    {
        .info = {
            .name = _("Ganlon"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_BLUE,
            .size = 33,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("A mysterious Berry. It is rumored to"),
            .description2 = COMPOUND_STRING("contain the power of the land."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 0,
            .dry = 40,
            .sweet = 0,
            .bitter = 40,
            .sour = 0,
            .smoothness = 80,
            .drainRate = 4,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_ICE,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 180,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Ganlon,
        .berryPal = gBerryPalette_Ganlon,
        .berryTreePicTable = gPicTable_HondewBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Hondew,
    },

    [BERRY_ID_SALAC] =
    {
        .info = {
            .name = _("Salac"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 95,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("A mysterious Berry. It is rumored to"),
            .description2 = COMPOUND_STRING("contain the power of the sky."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 0,
            .dry = 0,
            .sweet = 40,
            .bitter = 0,
            .sour = 40,
            .smoothness = 80,
            .drainRate = 4,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_FIGHTING,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 180,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Salac,
        .berryPal =  gBerryPalette_Salac,
        .berryTreePicTable = gPicTable_AguavBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Aguav,
    },

    [BERRY_ID_PETAYA] =
    {
        .info = {
            .name = _("Petaya"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .color = BERRY_COLOR_PINK,
            .size = 237,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("A mysterious Berry. It is rumored to"),
            .description2 = COMPOUND_STRING("contain the power of all living things."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 40,
            .dry = 0,
            .sweet = 0,
            .bitter = 40,
            .sour = 0,
            .smoothness = 80,
            .drainRate = 4,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_POISON,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 180,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Petaya,
        .berryPal = gBerryPalette_Petaya,
        .berryTreePicTable = gPicTable_PomegBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Pomeg,
    },

    [BERRY_ID_APICOT] =
    {
        .info = {
            .name = _("Apicot"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = BERRY_COLOR_BLUE,
            .size = 75,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("A very mystifying Berry. No telling"),
            .description2 = COMPOUND_STRING("what may happen or how it can be used."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 0,
            .dry = 40,
            .sweet = 0,
            .bitter = 0,
            .sour = 40,
            .smoothness = 80,
            .drainRate = 4,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_GROUND,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 180,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Apicot,
        .berryPal = gBerryPalette_Apicot,
        .berryTreePicTable = gPicTable_GrepaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Grepa,
    },

    [BERRY_ID_LANSAT] =
    {
        .info = {
            .name = _("Lansat"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_RED : BERRY_COLOR_PINK,
            .size = 97,
            .maxYield = YIELD_RATE(2, 5, 5, 7),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("Said to be a legendary Berry."),
            .description2 = COMPOUND_STRING("Holding it supposedly brings joy."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 120, 48, 72),
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 30,
            .drainRate = 4,
            .waterBonus = 1,
            .weedsBonus = 0,
            .pestsBonus = 1,
        },
        .naturalGiftType = TYPE_FLYING,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 200,
        .berryCrushPowder = 750,
        .berryPic = gBerryPic_Lansat,
        .berryPal = gBerryPalette_Lansat,
        .berryTreePicTable = gPicTable_LansatBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Lansat,
    },

    [BERRY_ID_STARF] =
    {
        .info = {
            .name = _("Starf"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_GREEN,
            .size = 153,
            .maxYield = YIELD_RATE(2, 5, 5, 7),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("So strong, it was abandoned at the"),
            .description2 = COMPOUND_STRING("world's edge. Considered a mirage."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 120, 48, 72),
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 30,
            .drainRate = 4,
            .waterBonus = 1,
            .weedsBonus = 0,
            .pestsBonus = 1,
        },
        .naturalGiftType = TYPE_PSYCHIC,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 200,
        .berryCrushPowder = 750,
        .berryPic = gBerryPic_Starf,
        .berryPal =  gBerryPalette_Starf,
        .berryTreePicTable = gPicTable_CornnBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Cornn,
    },

    [BERRY_ID_ENIGMA] =
    {
        .info = {
            .name = _("Enigma"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PURPLE : BERRY_COLOR_YELLOW,
            .size = 155,
            .maxYield = YIELD_RATE(2, 5, 5, 13),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("A completely enigmatic Berry."),
            .description2 = COMPOUND_STRING("Appears to have the power of stars."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 72, 48, 72),
            .spicy = 40,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 0,
        },
        .naturalGiftType = TYPE_BUG,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 150,
        .berryCrushPowder = 200,
        .berryPic = gBerryPic_Enigma,
        .berryPal = gBerryPalette_Enigma,
        .berryTreePicTable = gPicTable_DurinBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Durin,
    },

    [BERRY_ID_MICLE] =
    {
        .info = {
            .name = _("Micle"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_GREEN,
            .size = 41,
            .maxYield = YIELD_RATE(2, 5, 5, 13),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("It makes other food eaten at the"),
            .description2 = COMPOUND_STRING("same time taste sweet."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 72, 48, 72),
            .spicy = 0,
            .dry = 40,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 0,
        },
        .naturalGiftType = TYPE_ROCK,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Micle,
        .berryPal = gBerryPalette_Micle,
        .berryTreePicTable = gPicTable_MicleBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Micle,
    },

    [BERRY_ID_CUSTAP] =
    {
        .info = {
            .name = _("Custap"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .color = BERRY_COLOR_RED,
            .size = 267,
            .maxYield = YIELD_RATE(2, 5, 5, 13),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("The flesh underneath the Custap"),
            .description2 = COMPOUND_STRING("Berry's skin is sweet and creamy soft."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 72, 48, 72),
            .spicy = 0,
            .dry = 0,
            .sweet = 40,
            .bitter = 10,
            .sour = 0,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 0,
        },
        .naturalGiftType = TYPE_GHOST,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 200,
        .berryCrushPowder = 750,
        .berryPic = gBerryPic_Custap,
        .berryPal = gBerryPalette_Custap,
        .berryTreePicTable = gPicTable_CustapBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Custap,
    },

    [BERRY_ID_JABOCA] =
    {
        .info = {
            .name = _("Jaboca"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .color = BERRY_COLOR_YELLOW,
            .size = 33,
            .maxYield = YIELD_RATE(2, 5, 5, 13),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("The drupelets that make up this berry"),
            .description2 = COMPOUND_STRING("pop rythmically if handled roughly."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 72, 48, 72),
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 40,
            .sour = 10,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 0,
        },
        .naturalGiftType = TYPE_DRAGON,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Jaboca,
        .berryPal = gBerryPalette_Jaboca,
        .berryTreePicTable = gPicTable_JabocaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Jaboca,
    },

    [BERRY_ID_ROWAP] =
    {
        .info = {
            .name = _("Rowap"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .color = BERRY_COLOR_BLUE,
            .size = 52,
            .maxYield = YIELD_RATE(2, 5, 5, 13),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("People once worked top-shaped pieces"),
            .description2 = COMPOUND_STRING("of this berry free to use as toys."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 72, 48, 72),
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 40,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 0,
        },
        .naturalGiftType = TYPE_DARK,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 130,
        .berryCrushPowder = 250,
        .berryPic = gBerryPic_Rowap,
        .berryPal = gBerryPalette_Rowap,
        .berryTreePicTable = gPicTable_RowapBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Rowap,
    },

    [BERRY_ID_ROSELI] =
    {
        .info = {
            .name = _("Roseli"),
            .firmness = BERRY_FIRMNESS_HARD,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_PINK : BERRY_COLOR_RED,
            .size = 35,
            .maxYield = YIELD_RATE(5, 5, 20, 10),
            .minYield = YIELD_RATE(2, 1, 3, 2),
            .description1 = COMPOUND_STRING("In nature, they grow in wide rings"),
            .description2 = COMPOUND_STRING("for reasons that are still unknown."),
            .growthDuration = GROWTH_DURATION(84, 72, 108, 48, 32, 48),
            .spicy = 0,
            .dry = 0,
            .sweet = 25,
            .bitter = 10,
            .sour = 0,
            .smoothness = 35,
            .drainRate = 6,
            .waterBonus = 10,
            .weedsBonus = 1,
            .pestsBonus = 4,
        },
        .naturalGiftType = TYPE_FAIRY,
        .naturalGiftPower = 80,
        .berryCrushDifficulty =  60,
        .berryCrushPowder =  50,
        .berryPic = gBerryPic_Roseli,
        .berryPal = gBerryPalette_Roseli,
        .berryTreePicTable = gPicTable_RoseliBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Roseli,
    },

    [BERRY_ID_KEE] =
    {
        .info = {
            .name = _("Kee"),
            .firmness = BERRY_FIRMNESS_UNKNOWN,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_YELLOW : BERRY_COLOR_PINK,
            .size = 0,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("A berry that is incredibly spicy at"),
            .description2 = COMPOUND_STRING("first, then extremely bitter."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 30,
            .dry = 30,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_FAIRY,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Kee,
        .berryPal = gBerryPalette_Kee,
        .berryTreePicTable = gPicTable_PechaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Pecha,
    },

    [BERRY_ID_MARANGA] =
    {
        .info = {
            .name = _("Marnga"), // "Maranga" is too long
            .firmness = BERRY_FIRMNESS_UNKNOWN,
            .color = OW_BERRY_COLORS == GEN_6_XY ? BERRY_COLOR_BLUE : BERRY_COLOR_YELLOW,
            .size = 0,
            .maxYield = YIELD_RATE(2, 5, 10, 13),
            .minYield = YIELD_RATE(1, 1, 1, 2),
            .description1 = COMPOUND_STRING("Its outside is very bitter, but its"),
            .description2 = COMPOUND_STRING("inside tastes like a sweet drink."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 96, 48, 72),
            .spicy = 10,
            .dry = 10,
            .sweet = 30,
            .bitter = 30,
            .sour = 10,
            .smoothness = 60,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 2,
        },
        .naturalGiftType = TYPE_DARK,
        .naturalGiftPower = 100,
        .berryCrushDifficulty = 160,
        .berryCrushPowder = 500,
        .berryPic = gBerryPic_Maranga,
        .berryPal = gBerryPalette_Maranga,
        .berryTreePicTable = gPicTable_OccaBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Occa,
    },

    [BERRY_ID_ENGIMA_E_READER] =
    {
        .info = {
            .name = _("Enigma"),
            .firmness = BERRY_FIRMNESS_UNKNOWN,
            .color = BERRY_COLOR_PURPLE,
            .size = 0,
            .maxYield = YIELD_RATE(2, 5, 5, 13),
            .minYield = YIELD_RATE(1, 1, 1, 1),
            .description1 = COMPOUND_STRING("A completely enigmatic Berry."),
            .description2 = COMPOUND_STRING("Appears to have the power of stars."),
            .growthDuration = GROWTH_DURATION(96, 96, 144, 72, 48, 72),
            .spicy = 40,
            .dry = 40,
            .sweet = 40,
            .bitter = 40,
            .sour = 40,
            .smoothness = 40,
            .drainRate = 7,
            .waterBonus = 2,
            .weedsBonus = 0,
            .pestsBonus = 0,
        },
        .berryCrushDifficulty = 150,
        .berryCrushPowder = 200,
        .berryPic = gBerryPic_Enigma,
        .berryPal = gBerryPalette_Enigma,
        .berryTreePicTable = gPicTable_DurinBerryTree,
        .berryTreePaletteSlotTable = gBerryTreePaletteSlotTable_Durin,
    },
};

const struct BerryTree gBlankBerryTree = {};

void SetEnigmaBerry(u8 *src)
{
#if FREE_ENIGMA_BERRY == FALSE
    u32 i;
    u8 *dest = (u8 *)&gSaveBlock1Ptr->enigmaBerry;

    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry); i++)
        dest[i] = src[i];
#endif //FREE_ENIGMA_BERRY
}

#if FREE_ENIGMA_BERRY == FALSE
static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u32 i;
    u32 checksum;
    u8 *dest;

    dest = (u8 *)enigmaBerry;
    checksum = 0;
    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry) - sizeof(gSaveBlock1Ptr->enigmaBerry.checksum); i++)
        checksum += dest[i];

    return checksum;
}
#endif //FREE_ENIGMA_BERRY

bool32 IsEnigmaBerryValid(void)
{
#if FREE_ENIGMA_BERRY == FALSE
    if (!gSaveBlock1Ptr->enigmaBerry.berry.growthDuration)
        return FALSE;
    if (!gSaveBlock1Ptr->enigmaBerry.berry.maxYield)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;
    return TRUE;
#else
    return FALSE;
#endif //FREE_ENIGMA_BERRY
}

const struct BerryInfo *GetBerryInfo(enum BerryId berry)
{
    if (berry == BERRY_ID_ENGIMA_E_READER && IsEnigmaBerryValid())
    {
    #if FREE_ENIGMA_BERRY == FALSE
        return (struct BerryInfo *)(&gSaveBlock1Ptr->enigmaBerry.berry);
    #else
        return &gBerries[BERRY_ID_NONE].info;    //never reached, but will appease the compiler gods
    #endif //FREE_ENIGMA_BERRY
    }
    else
    {
        if (berry == BERRY_ID_NONE || berry > NUM_BERRIES)
            berry = 1;
        return &gBerries[berry].info;
    }
}

struct BerryTree *GetBerryTreeInfo(u8 id)
{
    return &gSaveBlock1Ptr->berryTrees[id];
}

bool32 ObjectEventInteractionWaterBerryTree(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));

    if (OW_BERRY_MOISTURE)
    {
        tree->moistureLevel = 100;
        if (OW_BERRY_ALWAYS_WATERABLE)
        {
            return TRUE;
        }
        AddTreeBonus(tree, GetWaterBonusByBerryType(tree->berry));
    }

    switch (tree->stage)
    {
    case BERRY_STAGE_PLANTED:
        tree->watered |= (1 << 0);
        break;
    case BERRY_STAGE_SPROUTED:
        tree->watered |= (1 << 1);
        break;
    case BERRY_STAGE_TALLER:
    case BERRY_STAGE_TRUNK:
    case BERRY_STAGE_BUDDING:
        tree->watered |= (1 << 2);
        break;
    case BERRY_STAGE_FLOWERING:
        tree->watered |= (1 << 3);
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

bool8 IsPlayerFacingEmptyBerryTreePatch(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() == BerryTreeScript
     && GetStageByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent)) == BERRY_STAGE_NO_BERRY)
        return TRUE;
    else
        return FALSE;
}

bool8 TryToWaterBerryTree(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() != BerryTreeScript)
        return FALSE;
    else
        return ObjectEventInteractionWaterBerryTree();
}

void ClearBerryTrees(void)
{
    int i;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
        gSaveBlock1Ptr->berryTrees[i] = gBlankBerryTree;
}

bool32 BerryTreeGrow(struct BerryTree *tree)
{
    if (tree->stopGrowth)
        return FALSE;

    switch (tree->stage)
    {
    case BERRY_STAGE_NO_BERRY:
        return FALSE;
    case BERRY_STAGE_FLOWERING:
        tree->berryYield = CalcBerryYield(tree);
    case BERRY_STAGE_PLANTED:
    case BERRY_STAGE_SPROUTED:
    case BERRY_STAGE_TRUNK:
        tree->stage++;
        break;
    case BERRY_STAGE_TALLER:
        if (OW_BERRY_SIX_STAGES)
            tree->stage = BERRY_STAGE_TRUNK;
        else
            tree->stage++;
        break;
    case BERRY_STAGE_BUDDING:
        tree->berryYield = CalcBerryYield(tree);
        tree->stage = BERRY_STAGE_BERRIES;
        break;
    case BERRY_STAGE_BERRIES:
        if (OW_BERRY_IMMORTAL)
            break;
        tree->watered = 0;
        tree->berryYield = 0;
        tree->stage = BERRY_STAGE_SPROUTED;
        tree->moistureLevel = 100;
        if (++tree->regrowthCount == ((tree->mulch == ITEM_TO_MULCH(ITEM_GOOEY_MULCH)) ? 15 : 10))
            *tree = gBlankBerryTree;
        break;
    }
    return TRUE;
}

static u16 GetMulchAffectedGrowthRate(u16 berryDuration, u8 mulch, u8 stage)
{
    if (stage == BERRY_STAGE_BERRIES)
        return berryDuration;
    if (mulch == ITEM_TO_MULCH(ITEM_GROWTH_MULCH))
        return berryDuration / 4 * 3;
    if (mulch == ITEM_TO_MULCH(ITEM_DAMP_MULCH))
        return berryDuration / 2 * 3;
    return berryDuration;
}

void BerryTreeTimeUpdate(s32 minutes)
{
    int i;
    u32 drainVal;
    struct BerryTree *tree;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
    {
        tree = &gSaveBlock1Ptr->berryTrees[i];

        if (tree->berry && tree->stage && !tree->stopGrowth && (!OW_BERRY_IMMORTAL || tree->stage != BERRY_STAGE_BERRIES))
        {
            if ((!OW_BERRY_IMMORTAL) && (minutes >= GetStageDurationByBerryType(tree->berry) * 71))
            {
                *tree = gBlankBerryTree;
            }
            else
            {
                s32 time = minutes;

                // Check moisture gradient, pests and weeds
                while (time > 0 && tree->stage != BERRY_STAGE_BERRIES)
                {
                    tree->moistureClock += 1;
                    time -= 1;
                    if (tree->moistureClock % 60 == 0)
                    {
                        if (OW_BERRY_MOISTURE)
                        {
                            drainVal = (OW_BERRY_DRAIN_RATE == GEN_4) ? GetDrainRateByBerryType(tree->berry) : (OW_BERRY_DRAIN_RATE == GEN_6_XY) ? 4 : 25;
                            if (OW_BERRY_MULCH_USAGE)
                            {
                                if (tree->mulch == ITEM_TO_MULCH(ITEM_GROWTH_MULCH))
                                    drainVal *= 2;
                                if (tree->mulch == ITEM_TO_MULCH(ITEM_DAMP_MULCH))
                                    drainVal /= 2;
                                if (tree->mulch == ITEM_TO_MULCH(ITEM_BOOST_MULCH) || tree->mulch == ITEM_TO_MULCH(ITEM_AMAZE_MULCH))
                                    drainVal = 25;
                            }
                            if (OW_BERRY_ALWAYS_WATERABLE && tree->moistureLevel == 0)
                            {
                                if (tree->berryYield > GetBerryInfo(tree->berry)->minYield + GetBerryInfo(tree->berry)->maxYield / 5)
                                    tree->berryYield -= GetBerryInfo(tree->berry)->maxYield / 5;
                                else
                                    tree->berryYield = GetBerryInfo(tree->berry)->minYield;
                            }
                            else if (tree->moistureLevel <= drainVal)
                                tree->moistureLevel = 0;
                            else
                                tree->moistureLevel -= drainVal;
                            if (OW_BERRY_DRAIN_RATE == GEN_6_XY && tree->moistureLevel <= 4) // Without variable drain rate (and without mulches), this needs to trigger after 24 hours, hence the extra check
                                tree->moistureLevel = 0;
                        }
                        if (tree->moistureClock == 120)
                        {
                            TryForWeeds(tree);
                            TryForPests(tree);
                            tree->moistureClock = 0;
                        }
                    }
                }

                // Check Berry growth
                time = minutes;

                while (time != 0)
                {
                    if (tree->minutesUntilNextStage > time)
                    {
                        tree->minutesUntilNextStage -= time;
                        break;
                    }
                    time -= tree->minutesUntilNextStage;
                    tree->minutesUntilNextStage = GetMulchAffectedGrowthRate(GetStageDurationByBerryType(tree->berry), tree->mulch, tree->stage);
                    if (!BerryTreeGrow(tree))
                        break;
                    if (tree->stage == BERRY_STAGE_BERRIES)
                        tree->minutesUntilNextStage = GetStageDurationByBerryType(tree->berry) * ((tree->mulch == ITEM_TO_MULCH(ITEM_STABLE_MULCH)) ? 6 : 4);
                }
            }
        }
    }
}

void PlantBerryTree(u8 id, enum BerryId berry, u8 stage, bool8 allowGrowth)
{
    struct BerryTree *tree = GetBerryTreeInfo(id);

    tree->berry = berry;
    tree->minutesUntilNextStage = GetMulchAffectedGrowthRate(GetStageDurationByBerryType(berry), tree->mulch, stage);
    tree->stage = stage;
    tree->moistureLevel = 100;
    if (OW_BERRY_ALWAYS_WATERABLE)
    {
        // We simulate a tree having grown without water
        u32 berryTreeAge = GetBerryTreeAge(berry, stage);
        if (GetBerryInfo(berry)->maxYield - berryTreeAge * GetBerryInfo(berry)->maxYield / 5 < GetBerryInfo(berry)->minYield)
            tree->berryYield = GetBerryInfo(berry)->minYield;
        else
            tree->berryYield = GetBerryInfo(berry)->maxYield - berryTreeAge * GetBerryInfo(berry)->maxYield / 5;
    }
    else if (stage == BERRY_STAGE_BERRIES)
    {
        tree->berryYield = CalcBerryYield(tree);
        tree->minutesUntilNextStage *= ((tree->mulch == ITEM_TO_MULCH(ITEM_STABLE_MULCH)) ? 6 : 4);
    }

    // Stop growth, to keep tree at this stage until the player has seen it
    // allowGrowth is always true for berry trees the player has planted
    if (!allowGrowth)
        tree->stopGrowth = TRUE;

    SetTreeMutations(id, berry);
}

void RemoveBerryTree(u8 id)
{
    gSaveBlock1Ptr->berryTrees[id] = gBlankBerryTree;
}

u8 GetBerryTypeByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berry;
}

u8 GetStageByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].stage;
}

u8 GetMulchByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].mulch;
}

void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    memcpy(string, GetBerryInfo(berry)->name, BERRY_NAME_LENGTH);
    string[BERRY_NAME_LENGTH] = EOS;
}

void AllowBerryTreeGrowth(u8 id)
{
    GetBerryTreeInfo(id)->stopGrowth = FALSE;
}

static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree)
{
    u8 count = 0;

    if (tree->watered & (1 << 0))
        count++;
    if (tree->watered & (1 << 1))
        count++;
    if (tree->watered & (1 << 2))
        count++;
    if (tree->watered & (1 << 3))
        count++;
    return count;
}

static u8 GetNumStagesWateredByBerryTreeId(u8 id)
{
    return BerryTreeGetNumStagesWatered(GetBerryTreeInfo(id));
}

// Berries can be watered at 4 stages of growth. The distribution is largely
// even but slightly prefers middle berry yields, since it uniformly draws from
// a subset of the total yield range.
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water)
{
    u32 randMin;
    u32 randMax;
    u32 rand;
    u32 extraYield;

    if (water == 0 || OW_BERRY_MOISTURE)
    {
        return min;
    }
    else
    {
        randMin = (max - min) * (water - 1);
        randMax = (max - min) * (water);
        rand = randMin + Random() % (randMax - randMin + 1);

        // Round upwards
        if ((rand % NUM_WATER_STAGES) >= NUM_WATER_STAGES / 2)
            extraYield = rand / NUM_WATER_STAGES + 1;
        else
            extraYield = rand / NUM_WATER_STAGES;
        return extraYield + min;
    }
}

static u8 CalcBerryYield(struct BerryTree *tree)
{
    const struct BerryInfo *berryInfo = GetBerryInfo(tree->berry);
    u8 min = tree->berryYield;
    u8 max = berryInfo->maxYield;
    u8 result;
    if (OW_BERRY_MULCH_USAGE && (tree->mulch == ITEM_TO_MULCH(ITEM_RICH_MULCH) || tree->mulch == ITEM_TO_MULCH(ITEM_AMAZE_MULCH)))
        min += 2;
    if (!(OW_BERRY_MOISTURE && OW_BERRY_ALWAYS_WATERABLE))
        min += berryInfo->minYield;
    if (min >= max)
        result = max;
    else
        result = CalcBerryYieldInternal(max, min, BerryTreeGetNumStagesWatered(tree));

    return result;
}

static u32 GetBerryTreeAge(u8 id, u8 stage)
{
    if (stage == BERRY_STAGE_TRUNK)
        stage = 5;
    else if (stage == BERRY_STAGE_BUDDING)
        stage = 6;
    else if (stage > 0)
        stage -= 1;
    return GetBerryInfo(id)->growthDuration * stage / (OW_BERRY_SIX_STAGES ? 6 : 4);
}

static u8 GetBerryCountByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berryYield;
}

static u16 GetStageDurationByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->growthDuration * 60 / (OW_BERRY_SIX_STAGES ? 6 : 4);
}

static u8 GetDrainRateByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->drainRate;
}

static u8 GetWaterBonusByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->waterBonus;
}

static u8 GetWeedingBonusByBerryType(u8 berry)
{
    u8 bonus = GetBerryInfo(berry)->weedsBonus;
    return (bonus == 0) ? 1 : bonus * 5;
}

static u8 GetPestsBonusByBerryType(u8 berry)
{
    u8 bonus = GetBerryInfo(berry)->pestsBonus;
    return (bonus == 0) ? 2 : bonus * 5;
}

bool8 CanWaterBerryPlot(void)
{
    if (!OW_BERRY_MOISTURE || OW_BERRY_ALWAYS_WATERABLE)
        return TRUE;
    return (gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(gSelectedObjectEvent)].moistureLevel == 0);
}

void ObjectEventInteractionGetBerryTreeData(void)
{
    u8 id;
    u8 berry;
    u8 localId;
    u8 group;
    u8 num;

    id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    berry = GetBerryTypeByBerryTreeId(id);
    AllowBerryTreeGrowth(id);
    localId = gSpecialVar_LastTalked;
    num = gSaveBlock1Ptr->location.mapNum;
    group = gSaveBlock1Ptr->location.mapGroup;
    if (IsBerryTreeSparkling(localId, num, group))
        gSpecialVar_0x8004 = BERRY_STAGE_SPARKLING;
    else
        gSpecialVar_0x8004 = GetStageByBerryTreeId(id);
    gSpecialVar_0x8005 = GetNumStagesWateredByBerryTreeId(id);
    gSpecialVar_0x8006 = GetBerryCountByBerryTreeId(id);
    CopyItemNameHandlePlural(BerryTypeToItemId(berry), gStringVar1, gSpecialVar_0x8006);
}

void ObjectEventInteractionGetBerryName(void)
{
    u8 berryType = GetBerryTypeByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    GetBerryNameByBerryType(berryType, gStringVar1);
}

void ObjectEventInteractionGetBerryCountString(void)
{
    u8 treeId = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(treeId);
    u8 count = GetBerryCountByBerryTreeId(treeId);

    // The strings for growing Berries all refer to a singular berry plant.
    // This ensures that text about planting a Berry and the growing Berry reads correctly.
    if (GetStageByBerryTreeId(treeId) != BERRY_STAGE_BERRIES)
        count = 1;

    gSpecialVar_0x8006 = BerryTypeToItemId(berry);
    CopyItemNameHandlePlural(gSpecialVar_0x8006, gStringVar1, count);
    berry = GetTreeMutationValue(treeId);
    if (berry > 0)
    {
        count = 1;
        CopyItemNameHandlePlural(gSpecialVar_0x8006, gStringVar3, count);
        gSpecialVar_Result = TRUE;
    }
    else
        gSpecialVar_Result = FALSE;
}

void Bag_ChooseBerry(void)
{
    SetMainCallback2(CB2_ChooseBerry);
}

void Bag_ChooseMulch(void)
{
    SetMainCallback2(CB2_ChooseMulch);
}

void ObjectEventInteractionPlantBerryTree(void)
{
    PlantBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent), ItemIdToBerryType(gSpecialVar_ItemId), BERRY_STAGE_PLANTED, TRUE);
    ObjectEventInteractionGetBerryTreeData();
}

void ObjectEventInteractionApplyMulch(void)
{
    u8 mulch = ITEM_TO_MULCH(gSpecialVar_ItemId);

    gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(gSelectedObjectEvent)].mulch = mulch;
    StringExpandPlaceholders(gStringVar1, gItemsInfo[gSpecialVar_ItemId].name);
}

void ObjectEventInteractionPickBerryTree(void)
{
    u8 id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(id);
    u8 mutation = GetTreeMutationValue(id);

    if (!OW_BERRY_MUTATIONS || mutation == 0)
    {
        gSpecialVar_0x8004 = AddBagItem(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id));
        return;
    }
    gSpecialVar_0x8004 = (CheckBagHasSpace(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id)) && CheckBagHasSpace(BerryTypeToItemId(mutation), 1)) + 2;
    if (gSpecialVar_0x8004 == 3)
    {
        AddBagItem(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id));
        AddBagItem(BerryTypeToItemId(mutation), 1);
    }
}

void ObjectEventInteractionRemoveBerryTree(void)
{
    RemoveBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    SetBerryTreeJustPicked(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

void ObjectEventInteractionPullBerryWeed(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    tree->weeds = FALSE;
    AddTreeBonus(tree, GetWeedingBonusByBerryType(tree->berry));
}

void ObjectEventInteractionClearBerryPests(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    tree->pests = FALSE;
    AddTreeBonus(tree, GetPestsBonusByBerryType(tree->berry));
}

bool8 PlayerHasBerries(void)
{
    return IsBagPocketNonEmpty(POCKET_BERRIES);
}

bool8 ObjectEventInteractionBerryHasWeed(void)
{
    return gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(gSelectedObjectEvent)].weeds;
}

bool8 ObjectEventInteractionBerryHasPests(void)
{
    enum Species species;
    if (!OW_BERRY_PESTS || !gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(gSelectedObjectEvent)].pests)
        return FALSE;
    species = GetBerryPestSpecies(gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(gSelectedObjectEvent)].berry);
    if (species == SPECIES_NONE)
        return FALSE;
    CreateScriptedWildMon(species, 14 + Random() % 3, ITEM_NONE);
    gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(gSelectedObjectEvent)].pests = FALSE;
    return TRUE;
}

// Berry tree growth is frozen at their initial stage (usually, fully grown) until the player has seen the tree
// For all berry trees on screen, allow normal growth
void SetBerryTreesSeen(void)
{
    u16 cam_left;
    u16 cam_top;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    int i;

    GetCameraCoords(&cam_left, &cam_top);
    left = cam_left;
    top = cam_top + 3;
    right = cam_left + 14;
    bottom = top + 8;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            s16 x = gObjectEvents[i].currentCoords.x;
            s16 y = gObjectEvents[i].currentCoords.y;
            if (left <= x && x <= right && top <= y && y <= bottom)
                AllowBerryTreeGrowth(gObjectEvents[i].trainerRange_berryTreeId);
        }
    }
}

bool8 PlayerHasMulch(void)
{
    if (!OW_BERRY_MULCH_USAGE)
        return FALSE;
    if (CheckBagHasItem(ITEM_GROWTH_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_DAMP_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_STABLE_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_GOOEY_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_RICH_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_SURPRISE_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_BOOST_MULCH, 1))
        return TRUE;
    if (CheckBagHasItem(ITEM_AMAZE_MULCH, 1))
        return TRUE;
    return FALSE;
}

#if OW_BERRY_MUTATIONS == TRUE
static const u8 sBerryMutations[][3] = {
    {BERRY_ID_IAPAPA, BERRY_ID_MAGO,   BERRY_ID_POMEG},
    {BERRY_ID_CHESTO, BERRY_ID_PERSIM, BERRY_ID_KELPSY},
    {BERRY_ID_ORAN,   BERRY_ID_PECHA,  BERRY_ID_QUALOT},
    {BERRY_ID_CHESTO, BERRY_ID_PERSIM, BERRY_ID_KELPSY},
    {BERRY_ID_ASPEAR, BERRY_ID_LEPPA,  BERRY_ID_HONDEW},
    {BERRY_ID_AGUAV,  BERRY_ID_FIGY,   BERRY_ID_GREPA},
    {BERRY_ID_LUM,    BERRY_ID_SITRUS, BERRY_ID_TAMATO},
    {BERRY_ID_HONDEW, BERRY_ID_YACHE,  BERRY_ID_LIECHI},
    {BERRY_ID_QUALOT, BERRY_ID_TANGA,  BERRY_ID_GANLON},
    {BERRY_ID_GREPA,  BERRY_ID_ROSELI, BERRY_ID_SALAC},
    {BERRY_ID_POMEG,  BERRY_ID_KASIB,  BERRY_ID_PETAYA},
    {BERRY_ID_KELPSY, BERRY_ID_WACAN,  BERRY_ID_APICOT},
    {BERRY_ID_GANLON, BERRY_ID_LIECHI, BERRY_ID_KEE},
    {BERRY_ID_SALAC,  BERRY_ID_PETAYA, BERRY_ID_MARANGA},
    // Up to one more Mutation can be added here for a total of 15 (only 4 bits are allocated)
};

static u8 GetMutationOutcome(u8 berry1, u8 berry2)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sBerryMutations); i++)
    {
        if ((sBerryMutations[i][0] == berry1 && sBerryMutations[i][1] == berry2)
          ||(sBerryMutations[i][0] == berry2 && sBerryMutations[i][1] == berry1))
            return (i + 1);
    }
    return 0;
}

static u8 TryForMutation(u8 berryTreeId, u8 berry)
{
    u8 i, j, mulch;
    s16 x1, x2, y1, y2;

    // Get location of current tree
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].trainerRange_berryTreeId == berryTreeId && gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
            break;
    }
    if (i == OBJECT_EVENTS_COUNT)
        return 0;

    x1 = gObjectEvents[i].currentCoords.x;
    y1 = gObjectEvents[i].currentCoords.y;

    mulch = GetMulchByBerryTreeId(GetObjectEventBerryTreeId(i));

    // Try mutation for each adjacent tree
    for (j = 0; j < OBJECT_EVENTS_COUNT; j++)
    {
        if (gObjectEvents[j].active && gObjectEvents[j].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH && GetStageByBerryTreeId(GetObjectEventBerryTreeId(j)) != BERRY_STAGE_NO_BERRY && j != i)
        {
            x2 = gObjectEvents[j].currentCoords.x;
            y2 = gObjectEvents[j].currentCoords.y;
            u32 rate = OW_BERRY_MUTATION_CHANCE;

            if (mulch == ITEM_TO_MULCH(ITEM_SURPRISE_MULCH) || mulch == ITEM_TO_MULCH(ITEM_AMAZE_MULCH))
                rate *= 2;

            if (Random() % 100 < rate && (
                (x1 == x2 && y1 == y2 - 1) ||
                (x1 == x2 && y1 == y2 + 1) ||
                (x1 == x2 - 1 && y1 == y2) ||
                (x1 == x2 + 1 && y1 == y2)))
                return GetMutationOutcome(berry, gSaveBlock1Ptr->berryTrees[GetObjectEventBerryTreeId(j)].berry);
        }
    }
    return 0;
}
#endif

struct TreeMutationBitfield {
  u8 a: 2;
  u8 b: 2;
  u8 unused: 4;
};

union TreeMutation {
  u8 value;
  struct TreeMutationBitfield asField;
};

static u8 GetTreeMutationValue(u8 id)
{
#if OW_BERRY_MUTATIONS
    struct BerryTree *tree = GetBerryTreeInfo(id);
    union TreeMutation myMutation;
    if (tree->stopGrowth) // Pre-generated trees shouldn't have mutations
        return 0;
    myMutation.asField.a = tree->mutationA;
    myMutation.asField.b = tree->mutationB;
    myMutation.asField.unused = 0;
    if (myMutation.value == 0) // no mutation
        return 0;
    return sBerryMutations[myMutation.value - 1][2];
#else
    return 0;
#endif
}

static void SetTreeMutations(u8 id, u8 berry)
{
#if OW_BERRY_MUTATIONS == TRUE
    struct BerryTree *tree = GetBerryTreeInfo(id);
    union TreeMutation myMutation;

    myMutation.value = TryForMutation(id, berry);
    tree->mutationA = myMutation.asField.a;
    tree->mutationB = myMutation.asField.b;
#endif
}

static enum Species GetBerryPestSpecies(u8 berryId)
{
#if OW_BERRY_PESTS == TRUE
    const struct BerryInfo *berryInfo = GetBerryInfo(berryId);
    switch (berryInfo->color)
    {
    case BERRY_COLOR_RED:
        return P_FAMILY_LEDYBA ? SPECIES_LEDYBA : SPECIES_NONE;
        break;
    case BERRY_COLOR_BLUE:
        return P_FAMILY_VOLBEAT_ILLUMISE ? SPECIES_VOLBEAT : SPECIES_NONE;
        break;
    case BERRY_COLOR_PURPLE:
        return P_FAMILY_VOLBEAT_ILLUMISE ? SPECIES_ILLUMISE : SPECIES_NONE;
        break;
    case BERRY_COLOR_GREEN:
        return P_FAMILY_BURMY ? SPECIES_BURMY_PLANT : SPECIES_NONE;
        break;
    case BERRY_COLOR_YELLOW:
        return P_FAMILY_COMBEE ? SPECIES_COMBEE : SPECIES_NONE;
        break;
    case BERRY_COLOR_PINK:
        return P_FAMILY_SCATTERBUG ? SPECIES_SPEWPA : SPECIES_NONE;
        break;
    }
#endif
    return SPECIES_NONE;
}

#define BERRY_WEEDS_CHANCE 15
#define BERRY_PESTS_CHANCE 15

static void TryForWeeds(struct BerryTree *tree)
{
    if (!OW_BERRY_WEEDS)
        return;
    if (tree->weeds == TRUE)
        return;
    if (Random() % 100 < BERRY_WEEDS_CHANCE)
        tree->weeds = TRUE;
}

static void TryForPests(struct BerryTree *tree)
{
    if (!OW_BERRY_WEEDS)
        return;
    if (tree->pests == TRUE)
        return;
    if (Random() % 100 < BERRY_PESTS_CHANCE && tree->stage > BERRY_STAGE_PLANTED)
        tree->pests = TRUE;
}

static void AddTreeBonus(struct BerryTree *tree, u8 bonus)
{
    if (OW_BERRY_MOISTURE) // use watered field to save track of intermediate bonuses
    {
        tree->watered += bonus;
        while (tree->watered > 10)
        {
            tree->watered -= 10;
            bonus = tree->berryYield + 1;
            if (bonus > GetBerryInfo(tree->berry)->maxYield)
                bonus = GetBerryInfo(tree->berry)->maxYield;
            tree->berryYield = bonus;
        }
    }
    else
    {
        bonus = tree->berryYield + bonus / 10;
        if (bonus > GetBerryInfo(tree->berry)->maxYield)
            bonus = GetBerryInfo(tree->berry)->maxYield;
        tree->berryYield = bonus;
    }
}
