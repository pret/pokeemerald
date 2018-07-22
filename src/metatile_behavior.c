#include "global.h"
#include "metatile_behavior.h"
#include "metatile_behaviors.h"

#define TILE_FLAG_ENCOUNTER_TILE 1
#define TILE_FLAG_SURFABLE 2

#define TILE_ATTRIBUTES(three, two, one) (((one) ? 1 : 0) | ((two) ? 2 : 0) | ((three) ? 4 : 0))

// wonder what the third flag is supposed to do
static const u8 sTileBitAttributes[] =
{
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_NORMAL 0x00
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x01
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_TALL_GRASS 0x02
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_LONG_GRASS 0x03
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_04 0x04
    TILE_ATTRIBUTES(FALSE, FALSE, TRUE), // MB_05 0x05
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_DEEP_SAND 0x06
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SHORT_GRASS 0x07
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_CAVE 0x08
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_LONG_GRASS_SOUTH_EDGE 0x09
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_NO_RUNNING 0x0A
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_0B 0x0B
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_MOUNTAIN_TOP 0x0C
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_BATTLE_PYRAMID_WARP 0x0D
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_MOSSDEEP_GYM_WARP 0x0E
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_MT_PYRE_HOLE 0x0F
    TILE_ATTRIBUTES(TRUE, TRUE, TRUE), // MB_POND_WATER 0x10
    TILE_ATTRIBUTES(TRUE, TRUE, TRUE), // MB_SEMI_DEEP_WATER 0x11
    TILE_ATTRIBUTES(TRUE, TRUE, TRUE), // MB_DEEP_WATER 0x12
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_WATERFALL 0x13
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_SOOTOPOLIS_DEEP_WATER 0x14
    TILE_ATTRIBUTES(TRUE, TRUE, TRUE), // MB_OCEAN_WATER 0x15
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_PUDDLE 0x16
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SHALLOW_WATER 0x17
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_18 0x18
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_NO_SURFACING 0x19
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_1A 0x1A
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_STAIRS_OUTSIDE_ABANDONED_SHIP 0x1B
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SHOAL_CAVE_ENTRANCE 0x1C
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x1D
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x1E
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x1F
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ICE 0x20
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SAND 0x21
    TILE_ATTRIBUTES(TRUE, TRUE, TRUE), // MB_SEAWEED 0x22
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // ? 0x23
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_ASHGRASS 0x24
    TILE_ATTRIBUTES(TRUE, FALSE, TRUE), // MB_25 0x25
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_THIN_ICE 0x26
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_CRACKED_ICE 0x27
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_HOT_SPRINGS 0x28
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_LAVARIDGE_GYM_B1F_WARP 0x29
    TILE_ATTRIBUTES(TRUE, TRUE, TRUE), // MB_SEAWEED_NO_SURFACING 0x2A
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_REFLECTION_UNDER_BRIDGE 0x2B
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x2C
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x2D
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x2E
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x2F
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_EAST 0x30
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_WEST 0x31
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_NORTH 0x32
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_SOUTH 0x33
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_NORTHEAST 0x34
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_NORTHWEST 0x35
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_SOUTHEAST 0x36
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_IMPASSABLE_SOUTHWEST 0x37
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_JUMP_EAST 0x38
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_JUMP_WEST 0x39
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_JUMP_NORTH 0x3A
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_JUMP_SOUTH 0x3B
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // ? 0x3C
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // ? 0x3D
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_JUMP_SOUTHEAST 0x3E
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_JUMP_SOUTHWEST 0x3F
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_WALK_EAST 0x40
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_WALK_WEST 0x41
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_WALK_NORTH 0x42
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_WALK_SOUTH 0x43
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SLIDE_EAST 0x44
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SLIDE_WEST 0x45
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SLIDE_NORTH 0x46
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SLIDE_SOUTH 0x47
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_TRICK_HOUSE_PUZZLE_8_FLOOR 0x48
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // ? 0x49
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // ? 0x4A
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x4B
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x4C
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x4D
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x4E
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x4F
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_EASTWARD_CURRENT 0x50
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_WESTWARD_CURRENT 0x51
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_NORTHWARD_CURRENT 0x52
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_SOUTHWARD_CURRENT 0x53
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x54
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x55
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x56
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x57
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x58
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x59
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x5A
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x5B
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x5C
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x5D
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x5E
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x5F
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_NON_ANIMATED_DOOR 0x60
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_LADDER 0x61
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_EAST_ARROW_WARP 0x62
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_WEST_ARROW_WARP 0x63
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_NORTH_ARROW_WARP 0x64
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SOUTH_ARROW_WARP 0x65
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_CRACKED_FLOOR_HOLE 0x66
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_AQUA_HIDEOUT_WARP 0x67
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_LAVARIDGE_GYM_1F_WARP 0x68
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ANIMATED_DOOR 0x69
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_UP_ESCALATOR 0x6A
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_DOWN_ESCALATOR 0x6B
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_WATER_DOOR 0x6C
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // MB_WATER_SOUTH_ARROW_WARP 0x6D
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_DEEP_SOUTH_WARP 0x6E
    TILE_ATTRIBUTES(TRUE, TRUE, FALSE), // ? 0x6F
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_WARP_OR_BRIDGE 0x70
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_71 0x71
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE120_NORTH_BRIDGE_1 0x72
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE120_NORTH_BRIDGE_2 0x73
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_PACIFIDLOG_VERTICAL_LOG_1 0x74
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_PACIFIDLOG_VERTICAL_LOG_2 0x75
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_PACIFIDLOG_HORIZONTAL_LOG_1 0x76
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_PACIFIDLOG_HORIZONTAL_LOG_2 0x77
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_FORTREE_BRIDGE 0x78
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x79
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE120_SOUTH_BRIDGE_1 0x7A
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE120_SOUTH_BRIDGE_2 0x7B
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE120_NORTH_BRIDGE_3 0x7C
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE120_NORTH_BRIDGE_4 0x7D
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_7E 0x7E
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ROUTE110_BRIDGE 0x7F
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_COUNTER 0x80
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x81
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x82
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_PC 0x83
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CABLE_BOX_RESULTS_1 0x84
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_REGION_MAP 0x85
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_TELEVISION 0x86
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_POKEBLOCK_FEEDER 0x87
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x88
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SLOT_MACHINE 0x89
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_ROULETTE 0x8A
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CLOSED_SOOTOPOLIS_GYM_DOOR 0x8B
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_TRICK_HOUSE_PUZZLE_DOOR 0x8C
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_8D 0x8D
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_RUNNING_SHOES_INSTRUCTION 0x8E
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_QUESTIONNAIRE 0x8F
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_RED_CAVE 0x90
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_RED_CAVE_OPEN 0x91
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_BROWN_CAVE 0x92
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN 0x93
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_YELLOW_CAVE 0x94
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN 0x95
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_TREE_LEFT 0x96
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN 0x97
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_SHRUB 0x98
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_SHRUB_OPEN 0x99
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_BLUE_CAVE 0x9A
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN 0x9B
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_TREE_RIGHT 0x9C
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN 0x9D
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x9E
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0x9F
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_BERRY_TREE_SOIL 0xA0
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA1
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA2
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA3
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA4
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA5
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA6
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA7
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA8
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xA9
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xAA
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xAB
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xAC
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xAD
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xAE
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xAF  A
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_PC 0xB0
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_REGISTER_PC 0xB1
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_B2 0xB2
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_B3 0xB3
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_B4 0xB4
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_B5 0xB5
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_B6 0xB6
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_B7 0xB7
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SECRET_BASE_BALLOON 0xB8
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_B9 0xB9
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SECRET_BASE_GLITTER_MAT 0xBA
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SECRET_BASE_JUMP_MAT 0xBB
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SECRET_BASE_SPIN_MAT 0xBC
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SECRET_BASE_SOUND_MAT 0xBD
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_BE 0xBE
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_BF 0xBF
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_BED 0xC0
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_C1 0xC1
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_C2 0xC2
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_C3 0xC3
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_SECRET_BASE_TV_SHIELD 0xC4
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_C5 0xC5
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_C6 0xC6
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SECRET_BASE_POSTER 0xC7
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_C8 0xC8
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_C9 0xC9
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CA 0xCA
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CB 0xCB
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CC 0xCC
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CD 0xCD
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CE 0xCE
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CF 0xCF
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_MUDDY_SLOPE 0xD0
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_BUMPY_SLOPE 0xD1
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_CRACKED_FLOOR 0xD2
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ISOLATED_VERTICAL_RAIL 0xD3
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_ISOLATED_HORIZONTAL_RAIL 0xD4
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_VERTICAL_RAIL 0xD5
    TILE_ATTRIBUTES(TRUE, FALSE, FALSE), // MB_HORIZONTAL_RAIL 0xD6
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xD7
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xD8
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xD9
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xDA
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xDB
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xDC
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xDD
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xDE
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xDF
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_PICTURE_BOOK_SHELF 0xE0
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_BOOKSHELF 0xE1
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_POKEMON_CENTER_BOOKSHELF 0xE2
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_VASE 0xE3
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_TRASH_CAN 0xE4
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_SHOP_SHELF 0xE5
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_BLUEPRINT 0xE6
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_CABLE_BOX_RESULTS_2 0xE7
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_WIRELESS_BOX_RESULTS 0xE8
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_TRAINER_HILL_TIMER 0xE9
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // MB_UNKNOWN_CLOSED_DOOR 0xEA
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xEB
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xEC
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xED
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xEE
    TILE_ATTRIBUTES(FALSE, FALSE, FALSE), // ? 0xEF
};

bool8 MetatileBehavior_IsATile(u8 var)
{
    return TRUE;
}

bool8 MetatileBehavior_IsEncounterTile(u8 var)
{
    if ((sTileBitAttributes[var] & TILE_FLAG_ENCOUNTER_TILE) != 0)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpEast(u8 var)
{
    if (var == MB_JUMP_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpWest(u8 var)
{
    if (var == MB_JUMP_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpNorth(u8 var)
{
    if (var == MB_JUMP_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsJumpSouth(u8 var)
{
    if (var == MB_JUMP_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPokeGrass(u8 var)
{
    if (var == MB_TALL_GRASS || var == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSandOrDeepSand(u8 var)
{
    if (var == MB_SAND || var == MB_DEEP_SAND)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDeepSand(u8 var)
{
    if (var == MB_DEEP_SAND)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsReflective(u8 var)
{
    if (var == MB_POND_WATER || var == MB_PUDDLE || var == MB_1A || var == MB_ICE || var == MB_SOOTOPOLIS_DEEP_WATER || var == MB_REFLECTION_UNDER_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIce(u8 var)
{
    if (var == MB_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWarpDoor(u8 var)
{
    if (var == MB_ANIMATED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDoor(u8 var)
{
    if (var == MB_8D || var == MB_ANIMATED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEscalator(u8 var)
{
    if (var == MB_UP_ESCALATOR || var == MB_DOWN_ESCALATOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_04(u8 var) // unused
{
    if (var == MB_04)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLadder(u8 var)
{
    if (var == MB_LADDER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNonAnimDoor(u8 var)
{
    if (var == MB_NON_ANIMATED_DOOR || var == MB_WATER_DOOR || var == MB_DEEP_SOUTH_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDeepSouthWarp(u8 var)
{
    if (var == MB_DEEP_SOUTH_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSurfableWaterOrUnderwater(u8 var)
{
    if ((sTileBitAttributes[var] & TILE_FLAG_SURFABLE) != 0)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEastArrowWarp(u8 var)
{
    if (var == MB_EAST_ARROW_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWestArrowWarp(u8 var)
{
    if (var == MB_WEST_ARROW_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNorthArrowWarp(u8 var)
{
    if (var == MB_NORTH_ARROW_WARP || var == MB_STAIRS_OUTSIDE_ABANDONED_SHIP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSouthArrowWarp(u8 var)
{
    if (var == MB_SOUTH_ARROW_WARP || var == MB_WATER_SOUTH_ARROW_WARP || var == MB_SHOAL_CAVE_ENTRANCE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsArrowWarp(u8 var) // unused
{
    u8 ret = FALSE;

    if (MetatileBehavior_IsEastArrowWarp(var)
        || MetatileBehavior_IsWestArrowWarp(var)
        || MetatileBehavior_IsNorthArrowWarp(var)
        || MetatileBehavior_IsSouthArrowWarp(var))
    {
        ret = TRUE;
    }

    return ret;
}

bool8 MetatileBehavior_IsMoveTile(u8 var)
{
    if ((var >= MB_WALK_EAST && var <= MB_TRICK_HOUSE_PUZZLE_8_FLOOR) || (var >= MB_EASTWARD_CURRENT && var <= MB_SOUTHWARD_CURRENT)
    || var == MB_MUDDY_SLOPE || var == MB_CRACKED_FLOOR || var == MB_WATERFALL || var == MB_ICE || var == MB_SECRET_BASE_JUMP_MAT || var == MB_SECRET_BASE_SPIN_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIce_2(u8 var)
{
    if (var == MB_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrickHouseSlipperyFloor(u8 var)
{
    if (var == MB_TRICK_HOUSE_PUZZLE_8_FLOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_05(u8 var)
{
    if (var == MB_05)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkNorth(u8 var)
{
    if (var == MB_WALK_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkSouth(u8 var)
{
    if (var == MB_WALK_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkWest(u8 var)
{
    if (var == MB_WALK_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWalkEast(u8 var)
{
    if (var == MB_WALK_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNorthwardCurrent(u8 var)
{
    if (var == MB_NORTHWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSouthwardCurrent(u8 var)
{
    if (var == MB_SOUTHWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWestwardCurrent(u8 var)
{
    if (var == MB_WESTWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEastwardCurrent(u8 var)
{
    if (var == MB_EASTWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideNorth(u8 var)
{
    if (var == MB_SLIDE_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideSouth(u8 var)
{
    if (var == MB_SLIDE_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideWest(u8 var)
{
    if (var == MB_SLIDE_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSlideEast(u8 var)
{
    if (var == MB_SLIDE_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCounter(u8 var)
{
    if (var == MB_COUNTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPlayerFacingTVScreen(u8 tile, u8 playerDir)
{
    if (playerDir != CONNECTION_NORTH) // if the player isn't facing north, forget about it.
        return FALSE;
    else if (tile == MB_TELEVISION) // is the player's north tile a TV?
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPC(u8 var)
{
    if (var == MB_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCableBoxResults1(u8 var)
{
    if (var == MB_CABLE_BOX_RESULTS_1)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseOpen(u8 var)
{
    if (var == MB_SECRET_BASE_SPOT_RED_CAVE_OPEN || var == MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN
        || var == MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN || var == MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN
        || var == MB_SECRET_BASE_SPOT_SHRUB_OPEN || var == MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN
        || var == MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseCave(u8 var)
{
    if (var == MB_SECRET_BASE_SPOT_RED_CAVE || var == MB_SECRET_BASE_SPOT_BROWN_CAVE || var == MB_SECRET_BASE_SPOT_YELLOW_CAVE || var == MB_SECRET_BASE_SPOT_BLUE_CAVE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseTree(u8 var)
{
    if (var == MB_SECRET_BASE_SPOT_TREE_LEFT || var == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseShrub(u8 var)
{
    if (var == MB_SECRET_BASE_SPOT_SHRUB)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBasePC(u8 var)
{
    if (var == MB_SECRET_BASE_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseRegisterPC(u8 var)
{
    if (var == MB_SECRET_BASE_REGISTER_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_B2(u8 var) // unused
{
    if (var == MB_B2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_B3(u8 var)
{
    if (var == MB_B3)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_B9(u8 var)
{
    if (var == MB_B9)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_C6(u8 var)
{
    if (var == MB_C6)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBasePoster(u8 var)
{
    if (var == MB_SECRET_BASE_POSTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNormal(u8 var)
{
    if (var == MB_NORMAL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_B7(u8 var)
{
    if (var == MB_B7)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_B2_Duplicate(u8 var) // unused
{
    if (var == MB_B2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_B5(u8 var)
{
    if (var == MB_B5)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_C3(u8 var)
{
    if (var == MB_C3)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_C2(u8 var)
{
    if (var == MB_C2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseBalloon(u8 var)
{
    if (var == MB_SECRET_BASE_BALLOON)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_BE(u8 var)
{
    if (var == MB_BE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseSoundMat(u8 var)
{
    if (var == MB_SECRET_BASE_SOUND_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseGlitterMat(u8 var)
{
    if (var == MB_SECRET_BASE_GLITTER_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_BF(u8 var)
{
    if (var == MB_BF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseTvOrShield(u8 var)
{
    if (var == MB_SECRET_BASE_TV_SHIELD)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_C5(u8 var)
{
    if (var == MB_C5)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_HasRipples(u8 var)
{
    if (var == MB_POND_WATER || var == MB_PUDDLE || var == MB_SOOTOPOLIS_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPuddle(u8 var)
{
    if (var == MB_PUDDLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTallGrass(u8 var)
{
    if (var == MB_TALL_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLongGrass(u8 var)
{
    if (var == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBerryTreeSoil(u8 var)
{
    if (var == MB_BERRY_TREE_SOIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsAshGrass(u8 var)
{
    if (var == MB_ASHGRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsUnusedFootprintMetatile(u8 var)
{
    if (var == MB_25)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBridge(u8 var)
{
    if ((var == MB_WARP_OR_BRIDGE || var == MB_71 || var == MB_ROUTE120_NORTH_BRIDGE_1 || var == MB_ROUTE120_NORTH_BRIDGE_2)
        || (var == MB_ROUTE120_NORTH_BRIDGE_3 || var == MB_ROUTE120_NORTH_BRIDGE_4 || var == MB_7E || var == MB_ROUTE110_BRIDGE))
        return TRUE;
    else
        return FALSE;
}

u8 MetatileBehavior_GetBridgeSth(u8 var)
{
    u8 result = var - MB_WARP_OR_BRIDGE;
    if (result < 4)
        return result;

    result = var - MB_ROUTE120_SOUTH_BRIDGE_1;
    if (result < 2)
        return 2;

    result = var - MB_ROUTE120_NORTH_BRIDGE_3;
    if (result < 2)
        return 3;

    return 0;
}

u8 MetatileBehavior_8089510(u8 var)
{
    u8 result = var - MB_WARP_OR_BRIDGE;

    if (result < 4)
        return 1;
    else
        return 0;
}

bool8 MetatileBehavior_IsLandWildEncounter(u8 var)
{
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(var) == FALSE && MetatileBehavior_IsEncounterTile(var) == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWaterWildEncounter(u8 var)
{
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(var) == TRUE && MetatileBehavior_IsEncounterTile(var) == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_0B(u8 var)
{
    if (var == MB_0B)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMountain(u8 var)
{
    if (var == MB_MOUNTAIN_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDiveable(u8 var)
{
    if (var == MB_SEMI_DEEP_WATER || var == MB_DEEP_WATER || var == MB_SOOTOPOLIS_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsUnableToEmerge(u8 var)
{
    if (var == MB_NO_SURFACING || var == MB_SEAWEED_NO_SURFACING)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsShallowFlowingWater(u8 var)
{
    if (var == MB_SHALLOW_WATER || var == MB_STAIRS_OUTSIDE_ABANDONED_SHIP || var == MB_SHOAL_CAVE_ENTRANCE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsThinIce(u8 var)
{
    if (var == MB_THIN_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCrackedIce(u8 var)
{
    if (var == MB_CRACKED_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsDeepOrOceanWater(u8 var)
{
    if (var == MB_OCEAN_WATER || var == MB_SEMI_DEEP_WATER || var == MB_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMB_18_OrMB_1A(u8 var) // unused
{
    if (var == MB_18 || var == MB_1A)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSurfableAndNotWaterfall(u8 var)
{
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(var) && MetatileBehavior_IsWaterfall(var) == FALSE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsEastBlocked(u8 var)
{
    if (var == MB_IMPASSABLE_EAST || var == MB_IMPASSABLE_NORTHEAST || var == MB_IMPASSABLE_SOUTHEAST || var == MB_C1 || var == MB_BE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWestBlocked(u8 var)
{
    if (var == MB_IMPASSABLE_WEST || var == MB_IMPASSABLE_NORTHWEST || var == MB_IMPASSABLE_SOUTHWEST || var == MB_C1 || var == MB_BE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsNorthBlocked(u8 var)
{
    if (var == MB_IMPASSABLE_NORTH || var == MB_IMPASSABLE_NORTHEAST || var == MB_IMPASSABLE_NORTHWEST || var == MB_BED)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSouthBlocked(u8 var)
{
    if (var == MB_IMPASSABLE_SOUTH || var == MB_IMPASSABLE_SOUTHEAST || var == MB_IMPASSABLE_SOUTHWEST || var == MB_BED)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsShortGrass(u8 var)
{
    if (var == MB_SHORT_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsHotSprings(u8 var)
{
    if (var == MB_HOT_SPRINGS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWaterfall(u8 var)
{
    if (var == MB_WATERFALL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsFortreeBridge(u8 var)
{
    if (var == MB_FORTREE_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifilogVerticalLog1(u8 var)
{
    if (var == MB_PACIFIDLOG_VERTICAL_LOG_1)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifilogVerticalLog2(u8 var)
{
    if (var == MB_PACIFIDLOG_VERTICAL_LOG_2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifilogHorizontalLog1(u8 var)
{
    if (var == MB_PACIFIDLOG_HORIZONTAL_LOG_1)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifilogHorizontalLog2(u8 var)
{
    if (var == MB_PACIFIDLOG_HORIZONTAL_LOG_2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPacifidlogLog(u8 var)
{
    if (var == MB_PACIFIDLOG_VERTICAL_LOG_1 || var == MB_PACIFIDLOG_VERTICAL_LOG_2
        || var == MB_PACIFIDLOG_HORIZONTAL_LOG_1 || var == MB_PACIFIDLOG_HORIZONTAL_LOG_2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrickHousePuzzleDoor(u8 var)
{
    if (var == MB_TRICK_HOUSE_PUZZLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRegionMap(u8 var)
{
    if (var == MB_REGION_MAP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsClosedSootopolisGymDoor(u8 var)
{
    if (var == MB_CLOSED_SOOTOPOLIS_GYM_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsUnknownClosedDoor(u8 var)
{
    if (var == MB_UNKNOWN_CLOSED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRoulette(u8 var) // unused
{
    if (var == MB_ROULETTE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPokeblockFeeder(u8 var)
{
    if (var == MB_POKEBLOCK_FEEDER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseJumpMat(u8 var)
{
    if (var == MB_SECRET_BASE_JUMP_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSecretBaseSpinMat(u8 var)
{
    if (var == MB_SECRET_BASE_SPIN_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLavaridgeB1FWarp(u8 var)
{
    if (var == MB_LAVARIDGE_GYM_B1F_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLavaridge1FWarp(u8 var)
{
    if (var == MB_LAVARIDGE_GYM_1F_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsAquaHideoutWarp(u8 var)
{
    if (var == MB_AQUA_HIDEOUT_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsWarpOrBridge(u8 var)
{
    if (var == MB_WARP_OR_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMossdeepGymWarp(u8 var)
{
    if (var == MB_MOSSDEEP_GYM_WARP)
        return TRUE;
    else
        return FALSE;
}


bool8 MetatileBehavior_IsSurfableFishableWater(u8 var)
{
    if (var == MB_POND_WATER || var == MB_OCEAN_WATER || var == MB_SEMI_DEEP_WATER || var == MB_DEEP_WATER
        || var == MB_SOOTOPOLIS_DEEP_WATER || (var == MB_EASTWARD_CURRENT || var == MB_WESTWARD_CURRENT
        || var == MB_NORTHWARD_CURRENT || var == MB_SOUTHWARD_CURRENT))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMtPyreHole(u8 var)
{
    if (var == MB_MT_PYRE_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCrackedFloorHole(u8 var)
{
    if (var == MB_CRACKED_FLOOR_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCrackedFloor(u8 var)
{
    if (var == MB_CRACKED_FLOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsMuddySlope(u8 var)
{
    if (var == MB_MUDDY_SLOPE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBumpySlope(u8 var)
{
    if (var == MB_BUMPY_SLOPE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIsolatedVerticalRail(u8 var)
{
    if (var == MB_ISOLATED_VERTICAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsIsolatedHorizontalRail(u8 var)
{
    if (var == MB_ISOLATED_HORIZONTAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsVerticalRail(u8 var)
{
    if (var == MB_VERTICAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsHorizontalRail(u8 var)
{
    if (var == MB_HORIZONTAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsSeaweed(u8 var)
{
    if (var == MB_SEAWEED || var == MB_SEAWEED_NO_SURFACING)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRunningDisallowed(u8 var)
{
    if (var == MB_NO_RUNNING || var == MB_LONG_GRASS || var == MB_HOT_SPRINGS || MetatileBehavior_IsPacifidlogLog(var) != FALSE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsCuttableGrass(u8 var)
{
    if (var == MB_TALL_GRASS || var == MB_LONG_GRASS || var == MB_ASHGRASS || var == MB_LONG_GRASS_SOUTH_EDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsRunningShoesInstruction(u8 var)
{
    if (var == MB_RUNNING_SHOES_INSTRUCTION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPictureBookShelf(u8 var)
{
    if (var == MB_PICTURE_BOOK_SHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBookShelf(u8 var)
{
    if (var == MB_BOOKSHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsPokeCenterBookShelf(u8 var)
{
    if (var == MB_POKEMON_CENTER_BOOKSHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsVase(u8 var)
{
    if (var == MB_VASE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrashCan(u8 var)
{
    if (var == MB_TRASH_CAN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsShopShelf(u8 var)
{
    if (var == MB_SHOP_SHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBlueprint(u8 var)
{
    if (var == MB_BLUEPRINT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsBattlePyramidWarp(u8 var)
{
    if (var == MB_BATTLE_PYRAMID_WARP)
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

bool8 MetatileBehavior_IsQuestionnaire(u8 var)
{
    if (var == MB_QUESTIONNAIRE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLongGrass_Duplicate(u8 var)
{
    if (var == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsLongGrassSouthEdge(u8 var)
{
    if (var == MB_LONG_GRASS_SOUTH_EDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehavior_IsTrainerHillTimer(u8 var)
{
    if (var == MB_TRAINER_HILL_TIMER)
        return TRUE;
    else
        return FALSE;
}
