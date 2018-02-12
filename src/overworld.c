#include "global.h"
#include "overworld.h"
#include "battle_setup.h"
#include "berry.h"
// #include "cable_club.h"
#include "clock.h"
#include "event_data.h"
#include "field_camera.h"
// #include "field_control_avatar.h"
#include "field_effect.h"
#include "field_fadetransition.h"
#include "field_ground_effect.h"
#include "field_map_obj.h"
#include "field_map_obj_helpers.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
// #include "field_special_scene.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
// #include "fldeff_flash.h"
#include "heal_location.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "m4a.h"
#include "constants/maps.h"
#include "map_name_popup.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "new_game.h"
#include "palette.h"
#include "play_time.h"
#include "random.h"
#include "roamer.h"
// #include "rotating_gate.h"
#include "safari_zone.h"
#include "script.h"
// #include "script_pokemon_80C4.h"
#include "secret_base.h"
#include "constants/songs.h"
#include "sound.h"
#include "constants/species.h"
#include "start_menu.h"
#include "task.h"
// #include "tileset_anim.h"
#include "time_events.h"
#include "tv.h"
#include "scanline_effect.h"
#include "wild_encounter.h"
#include "bg.h"
#include "money.h"

// event scripts
extern const u8 EventScript_WhiteOut[];
extern const u8 EventScript_271862[];

// vars
extern struct MapData * const gMapAttributes[];
extern struct MapHeader * const * const gMapGroups[];
extern s32 gMaxFlashLevel;

// functions
extern void HealPlayerParty(void);
extern void move_tilemap_camera_to_upper_left_corner(void);
extern void cur_mapheader_run_tileset_funcs_after_some_cpuset(void);
extern void DrawWholeMapView(void);
extern void copy_map_tileset1_tileset2_to_vram(struct MapData *);
extern void apply_map_tileset1_tileset2_palette(struct MapData *);
extern void ResetCyclingRoadChallengeData(void);
extern void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey);

// this file's functions
static void Overworld_ResetStateAfterWhiteOut(void);
void ChooseAmbientCrySpecies(void);

// IWRAM bss vars
IWRAM_DATA void *gUnknown_03000E0C;
IWRAM_DATA u8 gUnknown_03000E10[4];
IWRAM_DATA u8 (*gUnknown_03000E14)(u32);
IWRAM_DATA u8 gUnknown_03000E18;
IWRAM_DATA u8 gUnknown_03000E19;
IWRAM_DATA void *rom4_c_unused_03000e1c;

// EWRAM vars
EWRAM_DATA struct WarpData gUnknown_020322DC = {0};
EWRAM_DATA struct WarpData gWarpDestination = {0};  // new warp position
EWRAM_DATA struct WarpData gUnknown_020322EC = {0};
EWRAM_DATA struct WarpData gUnknown_020322F4 = {0};
EWRAM_DATA u16 gLastMapSectionId = 0;
// EWRAM_DATA struct UnkPlayerStruct gUnknown_02029810 = {0};
// EWRAM_DATA u16 sAmbientCrySpecies = 0;
// EWRAM_DATA bool8 sIsAmbientCryWaterMon = FALSE;
// EWRAM_DATA struct LinkPlayerMapObject gLinkPlayerMapObjects[4] = {0};

// const rom data
const struct WarpData sDummyWarpData =
{
    .mapGroup = -1,
    .mapNum = -1,
    .warpId = -1,
    .x = -1,
    .y = -1,
};

const u8 sUnusedData[] =
{
    0xB0, 0x04, 0x00, 0x00,
    0x10, 0x0E, 0x00, 0x00,
    0xB0, 0x04, 0x00, 0x00,
    0x60, 0x09, 0x00, 0x00,
    0x32, 0x00, 0x00, 0x00,
    0x50, 0x00, 0x00, 0x00,
    0xD4, 0xFF, 0xFF, 0xFF,
    0x2C, 0x00, 0x00, 0x00,
};

const struct UCoords32 gUnknown_08339D64[] =
{
    { 0,  0},
    { 0,  1},
    { 0, -1},
    {-1,  0},
    { 1,  0},
    {-1,  1},
    { 1,  1},
    {-1, -1},
    { 1, -1},
};

const struct BgTemplate gUnknown_08339DAC[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct ScanlineEffectParams gUnknown_08339DBC =
{
    (void *)REG_ADDR_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0,
};

u8 sub_80879D8(struct LinkPlayerMapObject *, struct MapObject *, u8);
u8 sub_80879F8(struct LinkPlayerMapObject *, struct MapObject *, u8);
u8 sub_80879FC(struct LinkPlayerMapObject *, struct MapObject *, u8);

u8 (*const gUnknown_08339DC8[])(struct LinkPlayerMapObject *, struct MapObject *, u8) =
{
    sub_80879D8,
    sub_80879F8,
    sub_80879FC,
};

u8 sub_8087A1C(struct LinkPlayerMapObject *, struct MapObject *, u8);
u8 sub_8087A20(struct LinkPlayerMapObject *, struct MapObject *, u8);
u8 sub_8087A88(struct LinkPlayerMapObject *, struct MapObject *, u8);

u8 (*const gUnknown_08339DD4[])(struct LinkPlayerMapObject *, struct MapObject *, u8) =
{
    sub_8087A1C,
    sub_8087A20,
    sub_8087A20,
    sub_8087A20,
    sub_8087A20,
    sub_8087A1C,
    sub_8087A1C,
    sub_8087A88,
    sub_8087A88,
    sub_8087A88,
    sub_8087A88,
};

void sub_8087AA0(struct LinkPlayerMapObject *, struct MapObject *);
void sub_8087AA8(struct LinkPlayerMapObject *, struct MapObject *);

void (*const gUnknown_08339E00[])(struct LinkPlayerMapObject *, struct MapObject *) =
{
    sub_8087AA0,
    sub_8087AA8,
};

// code
void DoWhiteOut(void)
{
    ScriptContext2_RunNewScript(EventScript_WhiteOut);
    SetMoney(&gSaveBlock1Ptr->money, GetMoney(&gSaveBlock1Ptr->money) / 2);
    HealPlayerParty();
    Overworld_ResetStateAfterWhiteOut();
    Overworld_SetWarpDestToLastHealLoc();
    warp_in();
}

void Overworld_ResetStateAfterFly(void)
{
    player_avatar_init_params_reset();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
}

void Overworld_ResetStateAfterTeleport(void)
{
    player_avatar_init_params_reset();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
    ScriptContext2_RunNewScript(EventScript_271862);
}

void Overworld_ResetStateAfterDigEscRope(void)
{
    player_avatar_init_params_reset();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
}

static void Overworld_ResetStateAfterWhiteOut(void)
{
    player_avatar_init_params_reset();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
    if (VarGet(VAR_0x4039) == 1)
    {
        VarSet(VAR_0x4039, 0);
        VarSet(VAR_0x4037, 0);
    }
}

void sub_8084788(void)
{
    FlagClear(FLAG_SYS_SAFARI_MODE);
    ChooseAmbientCrySpecies();
    ResetCyclingRoadChallengeData();
    UpdateLocationHistoryForRoamer();
    RoamerMoveToOtherLocationSet();
}

void ResetGameStats(void)
{
    s32 i;

    for (i = 0; i < NUM_GAME_STATS; i++)
        SetGameStat(i, 0);
}

void IncrementGameStat(u8 index)
{
    if (index < NUM_USED_GAME_STATS)
    {
        u32 statVal = GetGameStat(index);
        if (statVal < 0xFFFFFF)
            statVal++;
        else
            statVal = 0xFFFFFF;

        SetGameStat(index, statVal);
    }
}

u32 GetGameStat(u8 index)
{
    if (index >= NUM_USED_GAME_STATS)
        return 0;

    return gSaveBlock1Ptr->gameStats[index] ^ gSaveBlock2Ptr->encryptionKey;
}

void SetGameStat(u8 index, u32 value)
{
    if (index < NUM_USED_GAME_STATS)
        gSaveBlock1Ptr->gameStats[index] = value ^ gSaveBlock2Ptr->encryptionKey;
}

void ApplyNewEncryptionKeyToGameStats(u32 newKey)
{
    u8 i;

    for (i = 0; i < NUM_GAME_STATS; i++)
        ApplyNewEncryptionKeyToWord(&gSaveBlock1Ptr->gameStats[i], newKey);
}

void LoadMapObjTemplatesFromHeader(void)
{
    // Clear map object templates
    CpuFill32(0, gSaveBlock1Ptr->mapObjectTemplates, sizeof(gSaveBlock1Ptr->mapObjectTemplates));

    // Copy map header events to save block
    CpuCopy32(gMapHeader.events->mapObjects,
              gSaveBlock1Ptr->mapObjectTemplates,
              gMapHeader.events->mapObjectCount * sizeof(struct MapObjectTemplate));
}

void LoadSaveblockMapObjScripts(void)
{
    struct MapObjectTemplate *mapHeaderObjTemplates = gMapHeader.events->mapObjects;
    struct MapObjectTemplate *savObjTemplates = gSaveBlock1Ptr->mapObjectTemplates;
    s32 i;

    for (i = 0; i < 64; i++)
        savObjTemplates[i].script = mapHeaderObjTemplates[i].script;
}

void Overworld_SetMapObjTemplateCoords(u8 localId, s16 x, s16 y)
{
    s32 i;
    struct MapObjectTemplate *savObjTemplates = gSaveBlock1Ptr->mapObjectTemplates;

    for (i = 0; i < 64; i++)
    {
        struct MapObjectTemplate *mapObjectTemplate = &savObjTemplates[i];
        if (mapObjectTemplate->localId == localId)
        {
            mapObjectTemplate->x = x;
            mapObjectTemplate->y = y;
            return;
        }
    }
}

void Overworld_SetMapObjTemplateMovementType(u8 localId, u8 movementType)
{
    s32 i;

    struct MapObjectTemplate *savObjTemplates = gSaveBlock1Ptr->mapObjectTemplates;
    for (i = 0; i < 64; i++)
    {
        struct MapObjectTemplate *mapObjectTemplate = &savObjTemplates[i];
        if (mapObjectTemplate->localId == localId)
        {
            mapObjectTemplate->movementType = movementType;
            return;
        }
    }
}

void mapdata_load_assets_to_gpu_and_full_redraw(void)
{
    move_tilemap_camera_to_upper_left_corner();
    copy_map_tileset1_tileset2_to_vram(gMapHeader.mapData);
    apply_map_tileset1_tileset2_palette(gMapHeader.mapData);
    DrawWholeMapView();
    cur_mapheader_run_tileset_funcs_after_some_cpuset();
}

struct MapData *get_mapdata_header(void)
{
    u16 mapDataId = gSaveBlock1Ptr->mapDataId;
    if (mapDataId)
        return gMapAttributes[mapDataId - 1];
    return NULL;
}

void ApplyCurrentWarp(void)
{
    gUnknown_020322DC = gSaveBlock1Ptr->location;
    gSaveBlock1Ptr->location = gWarpDestination;
    gUnknown_020322EC = sDummyWarpData;
    gUnknown_020322F4 = sDummyWarpData;
}

void set_warp2_warp3_to_neg_1(void)
{
    gUnknown_020322EC = sDummyWarpData;
    gUnknown_020322F4 = sDummyWarpData;
}

void SetWarpData(struct WarpData *warp, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp->mapGroup = mapGroup;
    warp->mapNum = mapNum;
    warp->warpId = warpId;
    warp->x = x;
    warp->y = y;
}

bool32 warp_data_is_not_neg_1(struct WarpData *warp)
{
    if (warp->mapGroup != -1)
        return FALSE;
    if (warp->mapNum != -1)
        return FALSE;
    if (warp->warpId != -1)
        return FALSE;
    if (warp->x != -1)
        return FALSE;
    if (warp->y != -1)
        return FALSE;
    return TRUE;
}

struct MapHeader *const Overworld_GetMapHeaderByGroupAndId(u16 mapGroup, u16 mapNum)
{
    return gMapGroups[mapGroup][mapNum];
}

struct MapHeader *const warp1_get_mapheader(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gWarpDestination.mapGroup, gWarpDestination.mapNum);
}

void set_current_map_header_from_sav1_save_old_name(void)
{
    gLastMapSectionId = gMapHeader.regionMapSectionId;
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gSaveBlock1Ptr->mapDataId = gMapHeader.mapDataId;
    gMapHeader.mapData = get_mapdata_header();
}

void LoadSaveblockMapHeader(void)
{
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gMapHeader.mapData = get_mapdata_header();
}

void update_camera_pos_from_warpid(void)
{
    if (gSaveBlock1Ptr->location.warpId >= 0 && gSaveBlock1Ptr->location.warpId < gMapHeader.events->warpCount)
    {
        gSaveBlock1Ptr->pos.x = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].x;
        gSaveBlock1Ptr->pos.y = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].y;
    }
    else if (gSaveBlock1Ptr->location.x >= 0 && gSaveBlock1Ptr->location.y >= 0)
    {
        gSaveBlock1Ptr->pos.x = gSaveBlock1Ptr->location.x;
        gSaveBlock1Ptr->pos.y = gSaveBlock1Ptr->location.y;
    }
    else
    {
        gSaveBlock1Ptr->pos.x = gMapHeader.mapData->width / 2;
        gSaveBlock1Ptr->pos.y = gMapHeader.mapData->height / 2;
    }
}

void warp_in(void)
{
    ApplyCurrentWarp();
    set_current_map_header_from_sav1_save_old_name();
    update_camera_pos_from_warpid();
}

void Overworld_SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gWarpDestination, mapGroup, mapNum, warpId, x, y);
}

void warp1_set_2(s8 mapGroup, s8 mapNum, s8 warpId)
{
    Overworld_SetWarpDestination(mapGroup, mapNum, warpId, -1, -1);
}

void saved_warp2_set(int unused, s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpData(&gSaveBlock1Ptr->warp2, mapGroup, mapNum, warpId, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
}

void saved_warp2_set_2(int unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->warp2, mapGroup, mapNum, warpId, x, y);
}

void copy_saved_warp2_bank_and_enter_x_to_warp1(u8 unused)
{
    gWarpDestination = gSaveBlock1Ptr->warp2;
}

void sub_8084CCC(u8 a1)
{
    const struct HealLocation *warp = GetHealLocationPointer(a1);

    if (warp)
        Overworld_SetWarpDestination(warp->group, warp->map, -1, warp->x, warp->y);
}

void Overworld_SetWarpDestToLastHealLoc(void)
{
    gWarpDestination = gSaveBlock1Ptr->lastHealLocation;
}

void Overworld_SetHealLocationWarp(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocationPointer(healLocationId);

    if (healLocation != NULL)
        SetWarpData(&gSaveBlock1Ptr->lastHealLocation, healLocation->group, healLocation->map, -1, healLocation->x, healLocation->y);
}

void sub_8084D5C(s16 a1, s16 a2)
{
    u8 currMapType = Overworld_GetMapTypeOfSaveblockLocation();
    u8 destMapType = GetMapTypeByGroupAndId(gWarpDestination.mapGroup, gWarpDestination.mapNum);
    if (is_light_level_1_2_3_5_or_6(currMapType) && is_light_level_1_2_3_5_or_6(destMapType) != TRUE)
        sub_8084DD4(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, a1 - 7, a2 - 6);
}

void sub_8084DD4(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->warp4, mapGroup, mapNum, warpId, x, y);
}
