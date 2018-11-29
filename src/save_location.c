#include "global.h"
#include "save_location.h"
#include "constants/maps.h"

// specialSaveWarp flags
#define POKECENTER_SAVEWARP (1 << 1)
#define LOBBY_SAVEWARP (1 << 2)
#define UNK_SPECIAL_SAVE_WARP_FLAG_3 (1 << 3)

static bool32 IsCurMapInLocationList(const u16 *list)
{
    s32 i;
    u16 locSum = (gSaveBlock1Ptr->location.mapGroup << 8) + (gSaveBlock1Ptr->location.mapNum);

    for (i = 0; list[i] != INVALID_U16; i++)
    {
        if (list[i] == locSum)
            return TRUE;
    }

    return FALSE;
}

static const u16 sSaveLocationPokeCenterList[] =
{
    MAP_OLDALE_TOWN_POKEMON_CENTER_1F,
    MAP_OLDALE_TOWN_POKEMON_CENTER_2F,
    MAP_DEWFORD_TOWN_POKEMON_CENTER_1F,
    MAP_DEWFORD_TOWN_POKEMON_CENTER_2F,
    MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F,
    MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F,
    MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F,
    MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F,
    MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F,
    MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F,
    MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F,
    MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F,
    MAP_PETALBURG_CITY_POKEMON_CENTER_1F,
    MAP_PETALBURG_CITY_POKEMON_CENTER_2F,
    MAP_SLATEPORT_CITY_POKEMON_CENTER_1F,
    MAP_SLATEPORT_CITY_POKEMON_CENTER_2F,
    MAP_MAUVILLE_CITY_POKEMON_CENTER_1F,
    MAP_MAUVILLE_CITY_POKEMON_CENTER_2F,
    MAP_RUSTBORO_CITY_POKEMON_CENTER_1F,
    MAP_RUSTBORO_CITY_POKEMON_CENTER_2F,
    MAP_FORTREE_CITY_POKEMON_CENTER_1F,
    MAP_FORTREE_CITY_POKEMON_CENTER_2F,
    MAP_LILYCOVE_CITY_POKEMON_CENTER_1F,
    MAP_LILYCOVE_CITY_POKEMON_CENTER_2F,
    MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F,
    MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F,
    MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F,
    MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F,
    MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F,
    MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F,
    MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F,
    MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F,
    MAP_BATTLE_FRONTIER_POKEMON_CENTER_1F,
    MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F,
    MAP_SINGLE_BATTLE_COLOSSEUM,
    MAP_TRADE_CENTER,
    MAP_RECORD_CORNER,
    MAP_DOUBLE_BATTLE_COLOSSEUM,
    INVALID_U16,
};

static bool32 IsCurMapPokeCenter(void)
{
    return IsCurMapInLocationList(sSaveLocationPokeCenterList);
}

static const u16 sSaveLocationReloadLocList[] = // There's only 1 location, and it's presumed its for the save reload feature for battle tower.
{
    MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY,
    INVALID_U16,
};

static bool32 IsCurMapReloadLocation(void)
{
    return IsCurMapInLocationList(sSaveLocationReloadLocList);
}

// Nulled out list. Unknown what this would have been.
static const u16 sUnknown_0861440E[] =
{
    INVALID_U16,
};

static bool32 sub_81AFCEC(void)
{
    return IsCurMapInLocationList(sUnknown_0861440E);
}

static void TrySetPokeCenterWarpStatus(void)
{
    if (IsCurMapPokeCenter() == FALSE)
        gSaveBlock2Ptr->specialSaveWarp &= ~(POKECENTER_SAVEWARP);
    else
        gSaveBlock2Ptr->specialSaveWarp |= POKECENTER_SAVEWARP;
}

static void TrySetReloadWarpStatus(void)
{
    if (!IsCurMapReloadLocation())
        gSaveBlock2Ptr->specialSaveWarp &= ~(LOBBY_SAVEWARP);
    else
        gSaveBlock2Ptr->specialSaveWarp |= LOBBY_SAVEWARP;
}

// this function definitely sets a warp status, but because the list is empty, it's unknown what this does yet.
static void sub_81AFD5C(void)
{
    if (!sub_81AFCEC())
        gSaveBlock2Ptr->specialSaveWarp &= ~(UNK_SPECIAL_SAVE_WARP_FLAG_3);
    else
        gSaveBlock2Ptr->specialSaveWarp |= UNK_SPECIAL_SAVE_WARP_FLAG_3;
}

void TrySetMapSaveWarpStatus(void)
{
    TrySetPokeCenterWarpStatus();
    TrySetReloadWarpStatus();
    sub_81AFD5C();
}

void sub_81AFDA0(void)
{
    gSaveBlock2Ptr->field_A8 |= 0x8000;
    gSaveBlock2Ptr->field_A8 |= 0x1;
    gSaveBlock2Ptr->field_A8 |= 0x2;
    gSaveBlock2Ptr->field_A8 |= 0x4;
    gSaveBlock2Ptr->field_A8 |= 0x10;
    gSaveBlock2Ptr->field_A8 |= 0x20;
    gSaveBlock2Ptr->field_A8 |= 0x8;
}

void sub_81AFDD0(void)
{
    gSaveBlock2Ptr->specialSaveWarp |= 0x80;
}
