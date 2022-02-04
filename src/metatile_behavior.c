#include "global.h"
#include "metatile_behavior.h"
#include "constants/metatile_behaviors.h"

#define TILE_FLAG_ENCOUNTER_TILE 1
#define TILE_FLAG_SURFABLE 2

#define TILE_ATTRIBUTES(unused, surfable, wildEncounter) (((wildEncounter) ? 1 : 0) | ((surfable) ? 2 : 0) | ((unused) ? 4 : 0))

// wonder what the third flag is supposed to do
static const u8 sTileBitAttributes[] =
{
    [MB_NORMAL] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_WALL] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_TALL_GRASS] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_LONG_GRASS] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_UNUSED_04] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_05] = TILE_ATTRIBUTES(FALSE, FALSE, TRUE),
    [MB_DEEP_SAND] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_SHORT_GRASS] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_CAVE] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_LONG_GRASS_SOUTH_EDGE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_NO_RUNNING] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_INDOOR_ENCOUNTER] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_MOUNTAIN_TOP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BATTLE_PYRAMID_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_MOSSDEEP_GYM_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_MT_PYRE_HOLE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_POND_WATER] = TILE_ATTRIBUTES(TRUE, TRUE, TRUE),
    [MB_SEMI_DEEP_WATER] = TILE_ATTRIBUTES(TRUE, TRUE, TRUE),
    [MB_DEEP_WATER] = TILE_ATTRIBUTES(TRUE, TRUE, TRUE),
    [MB_WATERFALL] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_SOOTOPOLIS_DEEP_WATER] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_OCEAN_WATER] = TILE_ATTRIBUTES(TRUE, TRUE, TRUE),
    [MB_PUDDLE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SHALLOW_WATER] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_SOOTOPOLIS_DEEP_WATER] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_NO_SURFACING] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_STAIRS_OUTSIDE_ABANDONED_SHIP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SHOAL_CAVE_ENTRANCE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_1D] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_1E] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_1F] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_ICE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SAND] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SEAWEED] = TILE_ATTRIBUTES(TRUE, TRUE, TRUE),
    [MB_UNUSED_23] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_ASHGRASS] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_FOOTPRINTS] = TILE_ATTRIBUTES(TRUE, FALSE, TRUE),
    [MB_THIN_ICE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_CRACKED_ICE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_HOT_SPRINGS] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_LAVARIDGE_GYM_B1F_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SEAWEED_NO_SURFACING] = TILE_ATTRIBUTES(TRUE, TRUE, TRUE),
    [MB_REFLECTION_UNDER_BRIDGE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_2C] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_2D] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_2E] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_2F] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_IMPASSABLE_EAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_WEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_NORTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_SOUTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_NORTHEAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_NORTHWEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_SOUTHEAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_SOUTHWEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_JUMP_EAST] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_JUMP_WEST] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_JUMP_NORTH] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_JUMP_SOUTH] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_JUMP_NORTHEAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_JUMP_NORTHWEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_JUMP_SOUTHEAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_JUMP_SOUTHWEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_WALK_EAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_WALK_WEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_WALK_NORTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_WALK_SOUTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SLIDE_EAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SLIDE_WEST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SLIDE_NORTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SLIDE_SOUTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_TRICK_HOUSE_PUZZLE_8_FLOOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_49] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_4A] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_4B] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_4C] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_4D] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_4E] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_4F] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_EASTWARD_CURRENT] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_WESTWARD_CURRENT] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_NORTHWARD_CURRENT] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_SOUTHWARD_CURRENT] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_UNUSED_54] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_55] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_56] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_57] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_58] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_59] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_5A] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_5B] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_5C] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_5D] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_5E] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_5F] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_NON_ANIMATED_DOOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_LADDER] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_EAST_ARROW_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_WEST_ARROW_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_NORTH_ARROW_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SOUTH_ARROW_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_CRACKED_FLOOR_HOLE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_AQUA_HIDEOUT_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_LAVARIDGE_GYM_1F_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_ANIMATED_DOOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UP_ESCALATOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_DOWN_ESCALATOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_WATER_DOOR] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_WATER_SOUTH_ARROW_WARP] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_DEEP_SOUTH_WARP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_6F] = TILE_ATTRIBUTES(TRUE, TRUE, FALSE),
    [MB_BRIDGE_OVER_OCEAN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_LOW] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_MED] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_HIGH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_PACIFIDLOG_VERTICAL_LOG_TOP] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_FORTREE_BRIDGE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_79] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_MED_EDGE_1] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_MED_EDGE_2] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_HIGH_EDGE_1] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BRIDGE_OVER_POND_HIGH_EDGE_2] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_BRIDGE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BIKE_BRIDGE_OVER_BARRIER] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_COUNTER] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_81] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_82] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_PC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_CABLE_BOX_RESULTS_1] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_REGION_MAP] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_TELEVISION] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_POKEBLOCK_FEEDER] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_88] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SLOT_MACHINE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_ROULETTE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_CLOSED_SOOTOPOLIS_DOOR] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_TRICK_HOUSE_PUZZLE_DOOR] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_PETALBURG_GYM_DOOR] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_RUNNING_SHOES_INSTRUCTION] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_QUESTIONNAIRE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_RED_CAVE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_RED_CAVE_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_BROWN_CAVE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_YELLOW_CAVE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_TREE_LEFT] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_SHRUB] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_SHRUB_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_BLUE_CAVE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_TREE_RIGHT] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_9E] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_9F] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_BERRY_TREE_SOIL] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A1] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A2] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A3] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A4] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A5] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A6] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A7] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A8] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_A9] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_AA] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_AB] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_AC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_AD] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_AE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_AF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_PC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_REGISTER_PC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_UNUSED] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BLOCK_DECORATION] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_DECORATION] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_HOLDS_SMALL_DECORATION] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_B6] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_NORTH_WALL] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_BALLOON] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_IMPASSABLE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_GLITTER_MAT] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_JUMP_MAT] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_SPIN_MAT] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_SOUND_MAT] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_BREAKABLE_DOOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_SAND_ORNAMENT] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_IMPASSABLE_SOUTH_AND_NORTH] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_IMPASSABLE_WEST_AND_EAST] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_HOLE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_HOLDS_LARGE_DECORATION] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_TV_SHIELD] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_PLAYER_ROOM_PC_ON] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_SECRET_BASE_DECORATION_BASE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SECRET_BASE_POSTER] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_C8] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_C9] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_CA] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_CB] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_CC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_CD] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_CE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_CF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_MUDDY_SLOPE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_BUMPY_SLOPE] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_CRACKED_FLOOR] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_ISOLATED_VERTICAL_RAIL] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_ISOLATED_HORIZONTAL_RAIL] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_VERTICAL_RAIL] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_HORIZONTAL_RAIL] = TILE_ATTRIBUTES(TRUE, FALSE, FALSE),
    [MB_UNUSED_D7] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_D8] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_D9] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_DA] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_DB] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_DC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_DD] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_DE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_DF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_PICTURE_BOOK_SHELF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_BOOKSHELF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_POKEMON_CENTER_BOOKSHELF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_VASE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_TRASH_CAN] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SHOP_SHELF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_BLUEPRINT] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_CABLE_BOX_RESULTS_2] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_WIRELESS_BOX_RESULTS] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_TRAINER_HILL_TIMER] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_SKY_PILLAR_CLOSED_DOOR] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_EB] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_EC] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_ED] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_EE] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
    [MB_UNUSED_EF] = TILE_ATTRIBUTES(FALSE, FALSE, FALSE),
};

bool8 MetatileBehavior_IsATile(u8 metatileBehavior)
{
    return TRUE;
}

bool8 MetatileBehavior_IsEncounterTile(u8 metatileBehavior)
{
    if ((sTileBitAttributes[metatileBehavior] & TILE_FLAG_ENCOUNTER_TILE))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpEast(u8 metatileBehavior)
{
    if (metatileBehavior == MB_JUMP_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpWest(u8 metatileBehavior)
{
    if (metatileBehavior == MB_JUMP_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpNorth(u8 metatileBehavior)
{
    if (metatileBehavior == MB_JUMP_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpSouth(u8 metatileBehavior)
{
    if (metatileBehavior == MB_JUMP_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPokeGrass(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TALL_GRASS || metatileBehavior == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSandOrDeepSand(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SAND || metatileBehavior == MB_DEEP_SAND)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDeepSand(u8 metatileBehavior)
{
    if (metatileBehavior == MB_DEEP_SAND)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsReflective(u8 metatileBehavior)
{
    if (metatileBehavior == MB_POND_WATER
     || metatileBehavior == MB_PUDDLE
     || metatileBehavior == MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2
     || metatileBehavior == MB_ICE
     || metatileBehavior == MB_SOOTOPOLIS_DEEP_WATER
     || metatileBehavior == MB_REFLECTION_UNDER_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIce(u8 metatileBehavior)
{
    if (metatileBehavior == MB_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWarpDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_ANIMATED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PETALBURG_GYM_DOOR
     || metatileBehavior == MB_ANIMATED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEscalator(u8 metatileBehavior)
{
    if (metatileBehavior == MB_UP_ESCALATOR
     || metatileBehavior == MB_DOWN_ESCALATOR)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehavior_IsUnused04(u8 metatileBehavior)
{
    if (metatileBehavior == MB_UNUSED_04)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLadder(u8 metatileBehavior)
{
    if (metatileBehavior == MB_LADDER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNonAnimDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_NON_ANIMATED_DOOR
     || metatileBehavior == MB_WATER_DOOR
     || metatileBehavior == MB_DEEP_SOUTH_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDeepSouthWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_DEEP_SOUTH_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSurfableWaterOrUnderwater(u8 metatileBehavior)
{
    if ((sTileBitAttributes[metatileBehavior] & TILE_FLAG_SURFABLE))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEastArrowWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_EAST_ARROW_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWestArrowWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WEST_ARROW_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNorthArrowWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_NORTH_ARROW_WARP
     || metatileBehavior == MB_STAIRS_OUTSIDE_ABANDONED_SHIP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSouthArrowWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SOUTH_ARROW_WARP
     || metatileBehavior == MB_WATER_SOUTH_ARROW_WARP
     || metatileBehavior == MB_SHOAL_CAVE_ENTRANCE)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehavior_IsArrowWarp(u8 metatileBehavior)
{
    u8 isArrowWarp = FALSE;

    if (MetatileBehavior_IsEastArrowWarp(metatileBehavior)
     || MetatileBehavior_IsWestArrowWarp(metatileBehavior)
     || MetatileBehavior_IsNorthArrowWarp(metatileBehavior)
     || MetatileBehavior_IsSouthArrowWarp(metatileBehavior))
    {
        isArrowWarp = TRUE;
    }

    return isArrowWarp;
}

bool8 MetatileBehavior_IsForcedMovementTile(u8 metatileBehavior)
{
    if ((metatileBehavior >= MB_WALK_EAST && metatileBehavior <= MB_TRICK_HOUSE_PUZZLE_8_FLOOR)
     || (metatileBehavior >= MB_EASTWARD_CURRENT && metatileBehavior <= MB_SOUTHWARD_CURRENT)
     || metatileBehavior == MB_MUDDY_SLOPE
     || metatileBehavior == MB_CRACKED_FLOOR
     || metatileBehavior == MB_WATERFALL
     || metatileBehavior == MB_ICE
     || metatileBehavior == MB_SECRET_BASE_JUMP_MAT
     || metatileBehavior == MB_SECRET_BASE_SPIN_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIce_2(u8 metatileBehavior)
{
    if (metatileBehavior == MB_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrickHouseSlipperyFloor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TRICK_HOUSE_PUZZLE_8_FLOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehavior_IsUnused05(u8 metatileBehavior)
{
    if (metatileBehavior == MB_UNUSED_05)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkNorth(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WALK_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkSouth(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WALK_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkWest(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WALK_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkEast(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WALK_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNorthwardCurrent(u8 metatileBehavior)
{
    if (metatileBehavior == MB_NORTHWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSouthwardCurrent(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SOUTHWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWestwardCurrent(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WESTWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEastwardCurrent(u8 metatileBehavior)
{
    if (metatileBehavior == MB_EASTWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideNorth(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SLIDE_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideSouth(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SLIDE_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideWest(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SLIDE_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideEast(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SLIDE_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCounter(u8 metatileBehavior)
{
    if (metatileBehavior == MB_COUNTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPlayerFacingTVScreen(u8 metatileBehavior, u8 playerDir)
{
    if (playerDir != DIR_NORTH)
        return FALSE;
    else if (metatileBehavior == MB_TELEVISION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPC(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCableBoxResults1(u8 metatileBehavior)
{
    if (metatileBehavior == MB_CABLE_BOX_RESULTS_1)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsOpenSecretBaseDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SPOT_RED_CAVE_OPEN
     || metatileBehavior == MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN
     || metatileBehavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN
     || metatileBehavior == MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN
     || metatileBehavior == MB_SECRET_BASE_SPOT_SHRUB_OPEN
     || metatileBehavior == MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN
     || metatileBehavior == MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseCave(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SPOT_RED_CAVE
     || metatileBehavior == MB_SECRET_BASE_SPOT_BROWN_CAVE
     || metatileBehavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE
     || metatileBehavior == MB_SECRET_BASE_SPOT_BLUE_CAVE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseTree(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SPOT_TREE_LEFT
     || metatileBehavior == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseShrub(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SPOT_SHRUB)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBasePC(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRecordMixingSecretBasePC(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_REGISTER_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehavior_IsSecretBaseUnused_B2(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_UNUSED)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBlockDecoration(u8 metatileBehavior)
{
    if (metatileBehavior == MB_BLOCK_DECORATION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseImpassable(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_IMPASSABLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseDecorationBase(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_DECORATION_BASE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBasePoster(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_POSTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNormal(u8 metatileBehavior)
{
    if (metatileBehavior == MB_NORMAL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseNorthWall(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_NORTH_WALL)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehavior_IsSecretBaseUnused_B2_2(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_UNUSED)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_HoldsSmallDecoration(u8 metatileBehavior)
{
    if (metatileBehavior == MB_HOLDS_SMALL_DECORATION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_HoldsLargeDecoration(u8 metatileBehavior)
{
    if (metatileBehavior == MB_HOLDS_LARGE_DECORATION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseHole(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseBalloon(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_BALLOON)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseBreakableDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_BREAKABLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseSoundMat(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SOUND_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseGlitterMat(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_GLITTER_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseSandOrnament(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SAND_ORNAMENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseShieldOrToyTV(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_TV_SHIELD)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPlayerRoomPCOn(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PLAYER_ROOM_PC_ON)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_HasRipples(u8 metatileBehavior)
{
    if (metatileBehavior == MB_POND_WATER
     || metatileBehavior == MB_PUDDLE
     || metatileBehavior == MB_SOOTOPOLIS_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPuddle(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PUDDLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTallGrass(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TALL_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLongGrass(u8 metatileBehavior)
{
    if (metatileBehavior == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBerryTreeSoil(u8 metatileBehavior)
{
    if (metatileBehavior == MB_BERRY_TREE_SOIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsAshGrass(u8 metatileBehavior)
{
    if (metatileBehavior == MB_ASHGRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsFootprints(u8 metatileBehavior)
{
    // MB_FOOTPRINTS is not used by any metatiles.
    if (metatileBehavior == MB_FOOTPRINTS)
        return TRUE;
    else
        return FALSE;
}

// For the sections of log bridges that span water / water's edge.
// Note that the rest of the metatiles for these bridges use MB_NORMAL.
// This is used to allow encounters on the water below the bridge.
bool8 MetatileBehavior_IsBridgeOverWater(u8 metatileBehavior)
{
    if ((metatileBehavior == MB_BRIDGE_OVER_OCEAN
      || metatileBehavior == MB_BRIDGE_OVER_POND_LOW
      || metatileBehavior == MB_BRIDGE_OVER_POND_MED
      || metatileBehavior == MB_BRIDGE_OVER_POND_HIGH)
      || (metatileBehavior == MB_BRIDGE_OVER_POND_HIGH_EDGE_1
       || metatileBehavior == MB_BRIDGE_OVER_POND_HIGH_EDGE_2
       || metatileBehavior == MB_UNUSED_BRIDGE
       || metatileBehavior == MB_BIKE_BRIDGE_OVER_BARRIER))
        return TRUE;
    else
        return FALSE;
}

u8 MetatileBehavior_GetBridgeType(u8 metatileBehavior)
{
    // MB_BRIDGE_OVER_OCEAN     --> BRIDGE_TYPE_OCEAN     (Routes 110/119)
    // MB_BRIDGE_OVER_POND_LOW  --> BRIDGE_TYPE_POND_LOW  (Unused)
    // MB_BRIDGE_OVER_POND_MED  --> BRIDGE_TYPE_POND_MED  (Route 120, south)
    // MB_BRIDGE_OVER_POND_HIGH --> BRIDGE_TYPE_POND_HIGH (Route 120, north)
    if (metatileBehavior >= MB_BRIDGE_OVER_OCEAN
     && metatileBehavior <= MB_BRIDGE_OVER_POND_HIGH)
        return metatileBehavior - MB_BRIDGE_OVER_OCEAN;

    if (metatileBehavior >= MB_BRIDGE_OVER_POND_MED_EDGE_1 
     && metatileBehavior <= MB_BRIDGE_OVER_POND_MED_EDGE_2)
        return BRIDGE_TYPE_POND_MED;

    if (metatileBehavior >= MB_BRIDGE_OVER_POND_HIGH_EDGE_1
     && metatileBehavior <= MB_BRIDGE_OVER_POND_HIGH_EDGE_2)
        return BRIDGE_TYPE_POND_HIGH;

    return BRIDGE_TYPE_OCEAN;
}

// Used to allow fishing below the bridge metatiles.
bool8 MetatileBehavior_IsBridgeOverWaterNoEdge(u8 metatileBehavior)
{
    if (metatileBehavior >= MB_BRIDGE_OVER_OCEAN
     && metatileBehavior <= MB_BRIDGE_OVER_POND_HIGH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLandWildEncounter(u8 metatileBehavior)
{
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(metatileBehavior) == FALSE
     && MetatileBehavior_IsEncounterTile(metatileBehavior) == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWaterWildEncounter(u8 metatileBehavior)
{
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(metatileBehavior) == TRUE
     && MetatileBehavior_IsEncounterTile(metatileBehavior) == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIndoorEncounter(u8 metatileBehavior)
{
    if (metatileBehavior == MB_INDOOR_ENCOUNTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMountain(u8 metatileBehavior)
{
    if (metatileBehavior == MB_MOUNTAIN_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDiveable(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SEMI_DEEP_WATER
     || metatileBehavior == MB_DEEP_WATER
     || metatileBehavior == MB_SOOTOPOLIS_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsUnableToEmerge(u8 metatileBehavior)
{
    // BUG: The player is unintentionally able to emerge on water doors.
    // Also the narrower underwater door in the underwater tileset has the wrong metatile behavior. This causes the dive glitch.
    // To fix change the metatile behavior of the narrower water door with porymap's tileset editor.
    if (metatileBehavior == MB_NO_SURFACING
     || metatileBehavior == MB_SEAWEED_NO_SURFACING
     #ifdef BUGFIX
     || metatileBehavior == MB_WATER_DOOR
     #endif
     )
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsShallowFlowingWater(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SHALLOW_WATER
     || metatileBehavior == MB_STAIRS_OUTSIDE_ABANDONED_SHIP
     || metatileBehavior == MB_SHOAL_CAVE_ENTRANCE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsThinIce(u8 metatileBehavior)
{
    if (metatileBehavior == MB_THIN_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCrackedIce(u8 metatileBehavior)
{
    if (metatileBehavior == MB_CRACKED_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDeepOrOceanWater(u8 metatileBehavior)
{
    if (metatileBehavior == MB_OCEAN_WATER
     || metatileBehavior == MB_SEMI_DEEP_WATER
     || metatileBehavior == MB_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehavior_IsUnusedSootopolisWater(u8 metatileBehavior)
{
    if (metatileBehavior == MB_UNUSED_SOOTOPOLIS_DEEP_WATER
     || metatileBehavior == MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSurfableAndNotWaterfall(u8 metatileBehavior)
{
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(metatileBehavior)
     && MetatileBehavior_IsWaterfall(metatileBehavior) == FALSE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEastBlocked(u8 metatileBehavior)
{
    if (metatileBehavior == MB_IMPASSABLE_EAST
     || metatileBehavior == MB_IMPASSABLE_NORTHEAST
     || metatileBehavior == MB_IMPASSABLE_SOUTHEAST
     || metatileBehavior == MB_IMPASSABLE_WEST_AND_EAST
     || metatileBehavior == MB_SECRET_BASE_BREAKABLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWestBlocked(u8 metatileBehavior)
{
    if (metatileBehavior == MB_IMPASSABLE_WEST
     || metatileBehavior == MB_IMPASSABLE_NORTHWEST
     || metatileBehavior == MB_IMPASSABLE_SOUTHWEST
     || metatileBehavior == MB_IMPASSABLE_WEST_AND_EAST
     || metatileBehavior == MB_SECRET_BASE_BREAKABLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNorthBlocked(u8 metatileBehavior)
{
    if (metatileBehavior == MB_IMPASSABLE_NORTH
     || metatileBehavior == MB_IMPASSABLE_NORTHEAST
     || metatileBehavior == MB_IMPASSABLE_NORTHWEST
     || metatileBehavior == MB_IMPASSABLE_SOUTH_AND_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSouthBlocked(u8 metatileBehavior)
{
    if (metatileBehavior == MB_IMPASSABLE_SOUTH
     || metatileBehavior == MB_IMPASSABLE_SOUTHEAST
     || metatileBehavior == MB_IMPASSABLE_SOUTHWEST
     || metatileBehavior == MB_IMPASSABLE_SOUTH_AND_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsShortGrass(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SHORT_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsHotSprings(u8 metatileBehavior)
{
    if (metatileBehavior == MB_HOT_SPRINGS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWaterfall(u8 metatileBehavior)
{
    if (metatileBehavior == MB_WATERFALL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsFortreeBridge(u8 metatileBehavior)
{
    if (metatileBehavior == MB_FORTREE_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifidlogVerticalLogTop(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PACIFIDLOG_VERTICAL_LOG_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifidlogVerticalLogBottom(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifidlogHorizontalLogLeft(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifidlogHorizontalLogRight(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifidlogLog(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PACIFIDLOG_VERTICAL_LOG_TOP
     || metatileBehavior == MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM
     || metatileBehavior == MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT
     || metatileBehavior == MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrickHousePuzzleDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TRICK_HOUSE_PUZZLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRegionMap(u8 metatileBehavior)
{
    if (metatileBehavior == MB_REGION_MAP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsClosedSootopolisDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_CLOSED_SOOTOPOLIS_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSkyPillarClosedDoor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SKY_PILLAR_CLOSED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRoulette(u8 metatileBehavior) // unused
{
    if (metatileBehavior == MB_ROULETTE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPokeblockFeeder(u8 metatileBehavior)
{
    if (metatileBehavior == MB_POKEBLOCK_FEEDER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseJumpMat(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_JUMP_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseSpinMat(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SECRET_BASE_SPIN_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLavaridgeB1FWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_LAVARIDGE_GYM_B1F_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLavaridge1FWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_LAVARIDGE_GYM_1F_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsAquaHideoutWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_AQUA_HIDEOUT_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsUnionRoomWarp(u8 metatileBehavior)
{
    // This metatile behavior is re-used for some reason by
    // the Union Room exit metatile. This function is used to
    // initiate a teleport-style warp.
    if (metatileBehavior == MB_BRIDGE_OVER_OCEAN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMossdeepGymWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_MOSSDEEP_GYM_WARP)
        return TRUE;
    else
        return FALSE;
}


bool8 MetatileBehavior_IsSurfableFishableWater(u8 metatileBehavior)
{
    if (metatileBehavior == MB_POND_WATER
     || metatileBehavior == MB_OCEAN_WATER
     || metatileBehavior == MB_SEMI_DEEP_WATER
     || metatileBehavior == MB_DEEP_WATER
     || metatileBehavior == MB_SOOTOPOLIS_DEEP_WATER
     || (metatileBehavior == MB_EASTWARD_CURRENT
      || metatileBehavior == MB_WESTWARD_CURRENT
      || metatileBehavior == MB_NORTHWARD_CURRENT
      || metatileBehavior == MB_SOUTHWARD_CURRENT))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMtPyreHole(u8 metatileBehavior)
{
    if (metatileBehavior == MB_MT_PYRE_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCrackedFloorHole(u8 metatileBehavior)
{
    if (metatileBehavior == MB_CRACKED_FLOOR_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCrackedFloor(u8 metatileBehavior)
{
    if (metatileBehavior == MB_CRACKED_FLOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMuddySlope(u8 metatileBehavior)
{
    if (metatileBehavior == MB_MUDDY_SLOPE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBumpySlope(u8 metatileBehavior)
{
    if (metatileBehavior == MB_BUMPY_SLOPE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIsolatedVerticalRail(u8 metatileBehavior)
{
    if (metatileBehavior == MB_ISOLATED_VERTICAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIsolatedHorizontalRail(u8 metatileBehavior)
{
    if (metatileBehavior == MB_ISOLATED_HORIZONTAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsVerticalRail(u8 metatileBehavior)
{
    if (metatileBehavior == MB_VERTICAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsHorizontalRail(u8 metatileBehavior)
{
    if (metatileBehavior == MB_HORIZONTAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSeaweed(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SEAWEED || metatileBehavior == MB_SEAWEED_NO_SURFACING)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRunningDisallowed(u8 metatileBehavior)
{
    if (metatileBehavior == MB_NO_RUNNING
     || metatileBehavior == MB_LONG_GRASS
     || metatileBehavior == MB_HOT_SPRINGS
     || MetatileBehavior_IsPacifidlogLog(metatileBehavior) != FALSE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCuttableGrass(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TALL_GRASS
     || metatileBehavior == MB_LONG_GRASS
     || metatileBehavior == MB_ASHGRASS
     || metatileBehavior == MB_LONG_GRASS_SOUTH_EDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRunningShoesManual(u8 metatileBehavior)
{
    if (metatileBehavior == MB_RUNNING_SHOES_INSTRUCTION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPictureBookShelf(u8 metatileBehavior)
{
    if (metatileBehavior == MB_PICTURE_BOOK_SHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBookShelf(u8 metatileBehavior)
{
    if (metatileBehavior == MB_BOOKSHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPokeCenterBookShelf(u8 metatileBehavior)
{
    if (metatileBehavior == MB_POKEMON_CENTER_BOOKSHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsVase(u8 metatileBehavior)
{
    if (metatileBehavior == MB_VASE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrashCan(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TRASH_CAN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsShopShelf(u8 metatileBehavior)
{
    if (metatileBehavior == MB_SHOP_SHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBlueprint(u8 metatileBehavior)
{
    if (metatileBehavior == MB_BLUEPRINT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBattlePyramidWarp(u8 metatileBehavior)
{
    if (metatileBehavior == MB_BATTLE_PYRAMID_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPlayerFacingWirelessBoxResults(u8 tile, u8 playerDir)
{
    if (playerDir != CONNECTION_NORTH) // if the player isn't facing north, forget about it.
        return FALSE;
    else if (tile == MB_WIRELESS_BOX_RESULTS) // is the player's north tile the monitor with results?
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCableBoxResults2(u8 tile, u8 playerDir)
{
    if (playerDir != CONNECTION_NORTH) // if the player isn't facing north, forget about it.
        return FALSE;
    else if (tile == MB_CABLE_BOX_RESULTS_2) // is the player's north tile the monitor with results?
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsQuestionnaire(u8 metatileBehavior)
{
    if (metatileBehavior == MB_QUESTIONNAIRE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLongGrass_Duplicate(u8 metatileBehavior)
{
    if (metatileBehavior == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLongGrassSouthEdge(u8 metatileBehavior)
{
    if (metatileBehavior == MB_LONG_GRASS_SOUTH_EDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrainerHillTimer(u8 metatileBehavior)
{
    if (metatileBehavior == MB_TRAINER_HILL_TIMER)
        return TRUE;
    else
        return FALSE;
}
