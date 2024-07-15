#include "global.h"
#include "test/test.h"
#include "battle_main.h"
#include "item.h"
#include "text.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"

TEST("Move names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Battle Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 64;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Contest Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 61;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    // All moves explicitly listed here are too big to fit.
    switch (move)
    {
    case MOVE_NATURES_MADNESS:
        EXPECT_GT(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
        break;
    }
}

TEST("Move names fit on TMs & HMs Bag Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 63;
    u32 move = MOVE_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].pocket == POCKET_TM_HM)
        {
            PARAMETRIZE_LABEL("%S", gMovesInfo[gItemsInfo[i].secondaryId].name) { move = gItemsInfo[i].secondaryId; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Move Relearner Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Item names fit on Bag Screen (list)")
{
    u32 i;
    const u32 fontId = FONT_NARROWER;
    const u32 tmHmBerryWidthPx = 71, restWidthPx = 88;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    if (gItemsInfo[item].pocket == POCKET_TM_HM || gItemsInfo[item].pocket == POCKET_BERRIES)
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), tmHmBerryWidthPx);
    else
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), restWidthPx);
}

TEST("Item plural names fit on Bag Screen (left box)")
{
    u32 i;
    // -6 for the question mark in FONT_NORMAL.
    const u32 fontId = FONT_NARROWER, widthPx = 102 - 6;
    u32 item = ITEM_NONE;
    u8 pluralName[ITEM_NAME_PLURAL_LENGTH + 1];
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    CopyItemNameHandlePlural(item, pluralName, 2);
    EXPECT_LE(GetStringWidth(fontId, pluralName, 0), widthPx);
}

TEST("Item plural names fit on PC storage (left box)")
{
    u32 i;
    // -6 for the question mark in FONT_NORMAL.
    const u32 fontId = FONT_NARROWER, widthPx = 104 - 6;
    u32 item = ITEM_NONE;
    u8 pluralName[ITEM_NAME_PLURAL_LENGTH + 1];
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    CopyItemNameHandlePlural(item, pluralName, 2);
    EXPECT_LE(GetStringWidth(fontId, pluralName, 0), widthPx);
}

TEST("Item names fit on Pokemon Storage System")
{
    u32 i;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 50;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].importance) continue;
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    // All items explicitly listed here are too big to fit. The ones
    // with a hold effect are listed at the bottom in case you want to
    // focus on making them fit (they are the most likely to appear on
    // the storage system UI, along with anything that could be held
    // in the wild).
    switch (item)
    {
    case ITEM_ENERGY_POWDER:
    case ITEM_PEWTER_CRUNCHIES:
    case ITEM_RAGE_CANDY_BAR:
    case ITEM_LUMIOSE_GALETTE:
    case ITEM_HEALTH_FEATHER:
    case ITEM_MUSCLE_FEATHER:
    case ITEM_RESIST_FEATHER:
    case ITEM_GENIUS_FEATHER:
    case ITEM_CLEVER_FEATHER:
    case ITEM_ABILITY_CAPSULE:
    case ITEM_DYNAMAX_CANDY:
    case ITEM_MAX_MUSHROOMS:
    case ITEM_GOLD_BOTTLE_CAP:
    case ITEM_PRETTY_FEATHER:
    case ITEM_STRANGE_SOUVENIR:
    case ITEM_FOSSILIZED_BIRD:
    case ITEM_FOSSILIZED_FISH:
    case ITEM_FOSSILIZED_DRAKE:
    case ITEM_FOSSILIZED_DINO:
    case ITEM_SURPRISE_MULCH:
    case ITEM_YELLOW_APRICORN:
    case ITEM_GREEN_APRICORN:
    case ITEM_WHITE_APRICORN:
    case ITEM_BLACK_APRICORN:
    case ITEM_THUNDER_STONE:
    case ITEM_GALARICA_WREATH:
    case ITEM_STRAWBERRY_SWEET:
    case ITEM_AUSPICIOUS_ARMOR:
    case ITEM_BIG_BAMBOO_SHOOT:
    case ITEM_GIMMIGHOUL_COIN:
    case ITEM_LEADERS_CREST:
    case ITEM_MALICIOUS_ARMOR:
    case ITEM_TINY_BAMBOO_SHOOT:
    case ITEM_BUG_TERA_SHARD:
    case ITEM_DARK_TERA_SHARD:
    case ITEM_DRAGON_TERA_SHARD:
    case ITEM_ELECTRIC_TERA_SHARD:
    case ITEM_FAIRY_TERA_SHARD:
    case ITEM_FIGHTING_TERA_SHARD:
    case ITEM_FIRE_TERA_SHARD:
    case ITEM_FLYING_TERA_SHARD:
    case ITEM_GHOST_TERA_SHARD:
    case ITEM_GRASS_TERA_SHARD:
    case ITEM_GROUND_TERA_SHARD:
    case ITEM_ICE_TERA_SHARD:
    case ITEM_NORMAL_TERA_SHARD:
    case ITEM_POISON_TERA_SHARD:
    case ITEM_PSYCHIC_TERA_SHARD:
    case ITEM_ROCK_TERA_SHARD:
    case ITEM_STEEL_TERA_SHARD:
    case ITEM_WATER_TERA_SHARD:
    case ITEM_BLACK_AUGURITE:
    case ITEM_UNREMARKABLE_TEACUP:
    case ITEM_MASTERPIECE_TEACUP:
    case ITEM_FRESH_START_MOCHI:
    case ITEM_STELLAR_TERA_SHARD:
    case ITEM_JUBILIFE_MUFFIN:
    case ITEM_SUPERB_REMEDY:
    case ITEM_AUX_POWERGUARD:
    case ITEM_CHOICE_DUMPLING:
    case ITEM_TWICE_SPICED_RADISH:
    // Items with hold effects:
    case ITEM_ELECTRIC_MEMORY:
    case ITEM_FIGHTING_MEMORY:
    case ITEM_GROUND_MEMORY:
    case ITEM_PSYCHIC_MEMORY:
    case ITEM_DRAGON_MEMORY:
    case ITEM_CHARIZARDITE_X:
    case ITEM_CHARIZARDITE_Y:
    case ITEM_ULTRANECROZIUM_Z:
    case ITEM_DEEP_SEA_SCALE:
    case ITEM_DEEP_SEA_TOOTH:
    case ITEM_NEVER_MELT_ICE:
    case ITEM_WEAKNESS_POLICY:
    case ITEM_SAFETY_GOGGLES:
    case ITEM_ADRENALINE_ORB:
    case ITEM_TERRAIN_EXTENDER:
    case ITEM_PROTECTIVE_PADS:
    case ITEM_HEAVY_DUTY_BOOTS:
    case ITEM_UTILITY_UMBRELLA:
    case ITEM_MARANGA_BERRY:
    case ITEM_PUNCHING_GLOVE:
    case ITEM_BOOSTER_ENERGY:
    case ITEM_ADAMANT_CRYSTAL:
    case ITEM_LUSTROUS_GLOBE:
    case ITEM_CORNERSTONE_MASK:
    case ITEM_WELLSPRING_MASK:
    case ITEM_HEARTHFLAME_MASK:
        EXPECT_GT(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    }
}

TEST("Item names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].importance) continue;
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    // All items explicitly listed here are too big to fit.
    switch (item)
    {
    case ITEM_UNREMARKABLE_TEACUP:
        EXPECT_GT(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    }
}

TEST("Item names fit on Shop Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 84;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
}

TEST("Species names fit on Battle Screen HP box")
{
    u32 i, genderWidthPx;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 55;
    u32 species = SPECIES_NONE;
    genderWidthPx = GetStringWidth(fontId, COMPOUND_STRING("♂"), 0);
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    if (gSpeciesInfo[i].genderRatio != MON_GENDERLESS)
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0) - genderWidthPx, widthPx);
    else
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Party Screen")
{
    u32 i;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 50;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 63;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokedex Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 50;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokedex Screen - Cries")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokemon Storage System")
{
    u32 i;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(FONT_NARROWER, gSpeciesInfo[species].speciesName, 0), 66);
    EXPECT_LE(GetStringWidth(FONT_SHORT_NARROW, gSpeciesInfo[species].speciesName, 0), 60);
}

TEST("Species names fit on Contest Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 50;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Contest Screen - Rankings")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 49;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Battle Dome Screen")
{
    u32 i;
    const u32 fontId = FONT_SHORT_NARROW, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Hall of Fame")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 66;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Naming Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 64;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Condition Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 57;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Condition Search Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Ribbon Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Ribbon List Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Battle Screen HP box for vanilla mons with the default font")
{
    u32 i, genderWidthPx;
    const u32 fontId = FONT_SMALL, widthPx = 55;
    u32 species = SPECIES_NONE;
    genderWidthPx = GetStringWidth(fontId, COMPOUND_STRING("♂"), 0);
    for (i = 1; i < SPECIES_TURTWIG; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    if (gSpeciesInfo[i].genderRatio != MON_GENDERLESS)
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0) - genderWidthPx, widthPx);
    else
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Ability names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NORMAL, widthPx = 144;
    u32 ability = ABILITY_NONE;
    for (i = 1; i < ABILITIES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gAbilitiesInfo[i].name) { ability = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gAbilitiesInfo[ability].name, 0), widthPx);
}

TEST("Ability names fit on Ability Pop-Up")
{
    u32 i;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 76;
    u32 ability = ABILITY_NONE;
    for (i = 1; i < ABILITIES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gAbilitiesInfo[i].name) { ability = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gAbilitiesInfo[ability].name, 0), widthPx);
}

TEST("Type names fit on Battle Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 39;
    u32 type = TYPE_NORMAL;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        PARAMETRIZE_LABEL("%S", gTypesInfo[i].name) { type = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gTypesInfo[type].name, 0), widthPx);
}

TEST("Type names fit on Pokedex Search Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 38;
    u32 type = TYPE_NORMAL;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        PARAMETRIZE_LABEL("%S", gTypesInfo[i].name) { type = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gTypesInfo[type].name, 0), widthPx);
}
