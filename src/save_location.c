#include "global.h"
#include "map_constants.h"

// used to make the list defines a little less ugly.
#define MAP(name) ((MAP_GROUP_##name << 8) + (MAP_ID_##name))

// specialSaveWarp flags
#define POKECENTER_SAVEWARP (1 << 1)
#define LOBBY_SAVEWARP (1 << 2)
#define UNK_SPECIAL_SAVE_WARP_FLAG_3 (1 << 3)

static bool32 IsCurMapInLocationList(const u16 *list)
{
    u16 locSum = (gSaveBlock1Ptr->location.mapGroup << 8) + (gSaveBlock1Ptr->location.mapNum);

    // im sure it was written a different way, but for the love of christ I cant figure out how to write it different where it still matches.
    if (*list != 0xFFFF)
    {
        u16 termValue = 0xFFFF;
        const u16 *localList;
        for (localList = list; *localList != termValue; localList++)
            if (*localList == locSum)
                return TRUE;
    }
    return FALSE;
}

// TODO: Not require a packed u16 array for these lists
static const u16 gSaveLocationPokeCenterList[] =
{
    MAP(OLDALE_TOWN_POKEMON_CENTER_1F),
    MAP(OLDALE_TOWN_POKEMON_CENTER_2F),
    MAP(DEWFORD_TOWN_POKEMON_CENTER_1F),
    MAP(DEWFORD_TOWN_POKEMON_CENTER_2F),
    MAP(LAVARIDGE_TOWN_POKEMON_CENTER_1F),
    MAP(LAVARIDGE_TOWN_POKEMON_CENTER_2F),
    MAP(FALLARBOR_TOWN_POKEMON_CENTER_1F),
    MAP(FALLARBOR_TOWN_POKEMON_CENTER_2F),
    MAP(VERDANTURF_TOWN_POKEMON_CENTER_1F),
    MAP(VERDANTURF_TOWN_POKEMON_CENTER_2F),
    MAP(PACIFIDLOG_TOWN_POKEMON_CENTER_1F),
    MAP(PACIFIDLOG_TOWN_POKEMON_CENTER_2F),
    MAP(PETALBURG_CITY_POKEMON_CENTER_1F),
    MAP(PETALBURG_CITY_POKEMON_CENTER_2F),
    MAP(SLATEPORT_CITY_POKEMON_CENTER_1F),
    MAP(SLATEPORT_CITY_POKEMON_CENTER_2F),
    MAP(MAUVILLE_CITY_POKEMON_CENTER_1F),
    MAP(MAUVILLE_CITY_POKEMON_CENTER_2F),
    MAP(RUSTBORO_CITY_POKEMON_CENTER_1F),
    MAP(RUSTBORO_CITY_POKEMON_CENTER_2F),
    MAP(FORTREE_CITY_POKEMON_CENTER_1F),
    MAP(FORTREE_CITY_POKEMON_CENTER_2F),
    MAP(LILYCOVE_CITY_POKEMON_CENTER_1F),
    MAP(LILYCOVE_CITY_POKEMON_CENTER_2F),
    MAP(MOSSDEEP_CITY_POKEMON_CENTER_1F),
    MAP(MOSSDEEP_CITY_POKEMON_CENTER_2F),
    MAP(SOOTOPOLIS_CITY_POKEMON_CENTER_1F),
    MAP(SOOTOPOLIS_CITY_POKEMON_CENTER_2F),
    MAP(EVER_GRANDE_CITY_POKEMON_CENTER_1F),
    MAP(EVER_GRANDE_CITY_POKEMON_CENTER_2F),
    MAP(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F),
    MAP(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F),
    MAP(BATTLE_FRONTIER_POKEMON_CENTER_1F),
    MAP(BATTLE_FRONTIER_POKEMON_CENTER_2F),
    MAP(SINGLE_BATTLE_COLOSSEUM),
    MAP(TRADE_CENTER),
    MAP(RECORD_CORNER),
    MAP(DOUBLE_BATTLE_COLOSSEUM),
    0xFFFF,
};

static bool32 IsCurMapPokeCenter(void)
{
    return IsCurMapInLocationList(gSaveLocationPokeCenterList);
}

static const u16 gSaveLocationReloadLocList[] = // there's only 1 location, and it's presumed its for the save reload feature for battle tower
{
    MAP(BATTLE_TOWER_LOBBY),
    0xFFFF,
};

static bool32 IsCurMapReloadLocation(void)
{
    return IsCurMapInLocationList(gSaveLocationReloadLocList);
}

// nulled out list. unknown what this would have been
static const u16 gUnknown_0861440E[] =
{
    0xFFFF,
};

bool32 sub_81AFCEC(void)
{
    return IsCurMapInLocationList(gUnknown_0861440E);
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
