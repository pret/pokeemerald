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
#include "save_location.h"

// event scripts
extern const u8 EventScript_WhiteOut[];
extern const u8 EventScript_271862[];

// vars
extern struct MapData *const gMapAttributes[];
extern struct MapHeader *const *const gMapGroups[];
extern const s32 gMaxFlashLevel;

// functions
extern void HealPlayerParty(void);
extern void move_tilemap_camera_to_upper_left_corner(void);
extern void cur_mapheader_run_tileset_funcs_after_some_cpuset(void);
extern void DrawWholeMapView(void);
extern void copy_map_tileset1_tileset2_to_vram(struct MapData *);
extern void apply_map_tileset1_tileset2_palette(struct MapData *);
extern void ResetCyclingRoadChallengeData(void);
extern void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey);
extern void mapheader_run_script_with_tag_x5(void);
extern void ResetFieldTasksArgs(void);
extern void sub_80A0A2C(void);
extern void not_trainer_hill_battle_pyramid(void);
extern void apply_map_tileset2_palette(struct MapData *);
extern void copy_map_tileset2_to_vram_2(struct MapData *);
extern void prev_quest_postbuffer_cursor_backup_reset(void);
extern void ShowMapNamePopup(void);
extern bool32 InTrainerHill(void);
extern void sub_81AA1D8(void);
extern void sub_81D5DF8(void);
extern void sub_80EB218(void);
extern void trainer_hill_map_load_related(void);
extern void battle_pyramid_map_load_related(u8);
extern void UpdateTVScreensOnMap(u32, u32);
extern void sub_80E9238(u8);

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
EWRAM_DATA u8 gUnknown_020322D8 = 0;
EWRAM_DATA struct WarpData gUnknown_020322DC = {0};
EWRAM_DATA struct WarpData gWarpDestination = {0};  // new warp position
EWRAM_DATA struct WarpData gUnknown_020322EC = {0};
EWRAM_DATA struct WarpData gUnknown_020322F4 = {0};
EWRAM_DATA u16 gLastMapSectionId = 0;
EWRAM_DATA struct UnkPlayerStruct gUnknown_02032300 = {0};
EWRAM_DATA u16 sAmbientCrySpecies = 0;
EWRAM_DATA bool8 sIsAmbientCryWaterMon = FALSE;
EWRAM_DATA struct LinkPlayerMapObject gLinkPlayerMapObjects[4] = {0};

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

void sub_8084E14(void)
{
    gWarpDestination = gSaveBlock1Ptr->warp4;
}

void sub_8084E2C(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gUnknown_020322EC, mapGroup, mapNum, warpId, x, y);
}

void warp1_set_to_warp2(void)
{
    gWarpDestination = gUnknown_020322EC;
}

void sub_8084E80(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gUnknown_020322F4, mapGroup, mapNum, warpId, x, y);
}

void sub_8084EBC(s16 x, s16 y)
{
    if (warp_data_is_not_neg_1(&gUnknown_020322F4) == TRUE)
    {
        gWarpDestination = gUnknown_020322DC;
    }
    else
    {
        Overworld_SetWarpDestination(gUnknown_020322F4.mapGroup, gUnknown_020322F4.mapNum, -1, x, y);
    }
}

void warp1_set_to_sav1w(void)
{
    gWarpDestination = gSaveBlock1Ptr->warp1;
}

void sub_8084F2C(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->warp1, mapGroup, mapNum, warpId, x, y);
}

void sub_8084F6C(u8 a1)
{
    const struct HealLocation *warp = GetHealLocationPointer(a1);
    if (warp)
        SetWarpData(&gSaveBlock1Ptr->warp1, warp->group, warp->map, -1, warp->x, warp->y);
}

void sub_8084FAC(void)
{
    gSaveBlock1Ptr->warp1 = gSaveBlock1Ptr->warp2;
}

struct MapConnection *GetMapConnection(u8 dir)
{
    s32 i;
    s32 count = gMapHeader.connections->count;
    struct MapConnection *connection = gMapHeader.connections->connections;

    if (connection == NULL)
        return NULL;

    for(i = 0; i < count; i++, connection++)
        if (connection->direction == dir)
            return connection;

    return NULL;
}

bool8 sub_8084FF8(u8 dir, u16 x, u16 y)
{
    struct MapConnection *connection = GetMapConnection(dir);

    if (connection != NULL)
    {
        Overworld_SetWarpDestination(connection->mapGroup, connection->mapNum, -1, x, y);
    }
    else
    {
        mapheader_run_script_with_tag_x6();
        if (warp_data_is_not_neg_1(&gUnknown_020322EC))
            return FALSE;
        warp1_set_to_warp2();
    }
    return TRUE;
}

bool8 sub_8085058(u16 x, u16 y)
{
    return sub_8084FF8(CONNECTION_EMERGE, x, y);
}

bool8 sub_8085078(u16 x, u16 y)
{
    return sub_8084FF8(CONNECTION_DIVE, x, y);
}

void mliX_load_map(u8 mapGroup, u8 mapNum)
{
    s32 paletteIndex;

    Overworld_SetWarpDestination(mapGroup, mapNum, -1, -1, -1);
    if (gMapHeader.regionMapSectionId != 0x3A)
        sub_8085810();

    ApplyCurrentWarp();
    set_current_map_header_from_sav1_save_old_name();
    LoadMapObjTemplatesFromHeader();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    prev_quest_postbuffer_cursor_backup_reset();
    TryUpdateRandomTrainerRematches(mapGroup, mapNum);
    DoTimeBasedEvents();
    SetSav1WeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    mapheader_run_script_with_tag_x3();
    not_trainer_hill_battle_pyramid();
    copy_map_tileset2_to_vram_2(gMapHeader.mapData);
    apply_map_tileset2_palette(gMapHeader.mapData);

    for (paletteIndex = 6; paletteIndex < 13; paletteIndex++)
        ApplyWeatherGammaShiftToPal(paletteIndex);

    sub_80A0A2C();
    UpdateLocationHistoryForRoamer();
    RoamerMove();
    DoCurrentWeather();
    ResetFieldTasksArgs();
    mapheader_run_script_with_tag_x5();

    if (gMapHeader.regionMapSectionId != 0x3A || gMapHeader.regionMapSectionId != gLastMapSectionId)
        ShowMapNamePopup();
}

void mli0_load_map(u32 a1)
{
    bool8 v2;
    bool8 indoors;

    set_current_map_header_from_sav1_save_old_name();
    if (!(gUnknown_020322D8 & 1))
    {
        if (gMapHeader.mapDataId == 0x169)
            sub_81AA1D8();
        else if (InTrainerHill())
            sub_81D5DF8();
        else
            LoadMapObjTemplatesFromHeader();
    }

    v2 = is_light_level_1_2_3_5_or_6(gMapHeader.mapType);
    indoors = Overworld_MapTypeIsIndoors(gMapHeader.mapType);

    sub_80EB218();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    prev_quest_postbuffer_cursor_backup_reset();
    TryUpdateRandomTrainerRematches(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    if (a1 != 1)
        DoTimeBasedEvents();
    SetSav1WeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    if (v2)
        FlagClear(FLAG_SYS_USE_FLASH);
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    mapheader_run_script_with_tag_x3();
    UpdateLocationHistoryForRoamer();
    RoamerMoveToOtherLocationSet();
    if (gMapHeader.mapDataId == 0x169)
        battle_pyramid_map_load_related(0);
    else if (InTrainerHill())
        trainer_hill_map_load_related();
    else
        not_trainer_hill_battle_pyramid();

    if (a1 != 1 && indoors)
    {
        UpdateTVScreensOnMap(gUnknown_03005DC0.width, gUnknown_03005DC0.height);
        sub_80E9238(1);
    }
}

void player_avatar_init_params_reset(void)
{
    gUnknown_02032300.player_field_1 = 1;
    gUnknown_02032300.player_field_0 = 1;
}

void walkrun_find_lowest_active_bit_in_bitfield(void)
{
    gUnknown_02032300.player_field_1 = player_get_direction_lower_nybble();

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        gUnknown_02032300.player_field_0 = 2;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        gUnknown_02032300.player_field_0 = 4;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        gUnknown_02032300.player_field_0 = 8;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_4))
        gUnknown_02032300.player_field_0 = 16;
    else
        gUnknown_02032300.player_field_0 = 1;
}

struct UnkPlayerStruct *sub_80852D4(void)
{
    struct UnkPlayerStruct playerStruct;
    u8 mapType = Overworld_GetMapTypeOfSaveblockLocation();
    u16 v2 = cur_mapdata_block_role_at_screen_center_acc_to_sav1();
    u8 v4 = sub_808532C(&gUnknown_02032300, v2, mapType);
    playerStruct.player_field_0 = v4;
    playerStruct.player_field_1 = sub_808538C(&gUnknown_02032300, v4, v2, mapType);
    gUnknown_02032300 = playerStruct;
    return &gUnknown_02032300;
}

u8 sub_808532C(struct UnkPlayerStruct *playerStruct, u16 a2, u8 a3)
{
    if (a3 != 8 && FlagGet(FLAG_SYS_CRUISE_MODE))
        return 1;
    if (a3 == 5)
        return 16;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(a2) == 1)
        return 8;
    if (Overworld_IsBikingAllowed() != TRUE)
        return 1;
    if (playerStruct->player_field_0 == 2)
        return 2;
    if (playerStruct->player_field_0 != 4)
        return 1;
    return 4;
}

u8 sub_808538C(struct UnkPlayerStruct *playerStruct, u8 a2, u16 a3, u8 a4)
{
    if (FlagGet(FLAG_SYS_CRUISE_MODE) && a4 == 6)
        return 4;
    if (MetatileBehavior_IsDeepSouthWarp(a3) == TRUE)
        return 2;
    if (MetatileBehavior_IsNonAnimDoor(a3) == TRUE || MetatileBehavior_IsDoor(a3) == TRUE)
        return 1;
    if (MetatileBehavior_IsSouthArrowWarp(a3) == TRUE)
        return 2;
    if (MetatileBehavior_IsNorthArrowWarp(a3) == TRUE)
        return 1;
    if (MetatileBehavior_IsWestArrowWarp(a3) == TRUE)
        return 4;
    if (MetatileBehavior_IsEastArrowWarp(a3) == TRUE)
        return 3;
    if ((playerStruct->player_field_0 == 16 && a2 == 8)
     || (playerStruct->player_field_0 == 8 && a2 == 16))
        return playerStruct->player_field_1;
    if (MetatileBehavior_IsLadder(a3) == TRUE)
        return playerStruct->player_field_1;
    return 1;
}

u16 cur_mapdata_block_role_at_screen_center_acc_to_sav1(void)
{
    return MapGridGetMetatileBehaviorAt(gSaveBlock1Ptr->pos.x + 7, gSaveBlock1Ptr->pos.y + 7);
}

bool32 Overworld_IsBikingAllowed(void)
{
    if (!(gMapHeader.flags & 1))
        return FALSE;
    else
        return TRUE;
}

void SetDefaultFlashLevel(void)
{
    if (!gMapHeader.cave)
        gSaveBlock1Ptr->flashLevel = 0;
    else if (FlagGet(FLAG_SYS_USE_FLASH))
        gSaveBlock1Ptr->flashLevel = 1;
    else
        gSaveBlock1Ptr->flashLevel = gMaxFlashLevel - 1;
}

void Overworld_SetFlashLevel(s32 flashLevel)
{
    if (flashLevel < 0 || flashLevel > gMaxFlashLevel)
        flashLevel = 0;
    gSaveBlock1Ptr->flashLevel = flashLevel;
}

u8 Overworld_GetFlashLevel(void)
{
    return gSaveBlock1Ptr->flashLevel;
}

void sub_8085524(u16 mapDataId)
{
    gSaveBlock1Ptr->mapDataId = mapDataId;
    gMapHeader.mapData = get_mapdata_header();
}

void sub_8085540(u8 var)
{
    gUnknown_020322D8 = var;
}

u8 sub_808554C(void)
{
    return gUnknown_020322D8;
}

bool16 ShouldLegendaryMusicPlayAtLocation(struct WarpData *warp)
{
    if (!FlagGet(FLAG_SYS_WEATHER_CTRL))
        return FALSE;
    if (warp->mapGroup == 0)
    {
        switch (warp->mapNum)
        {
        case MAP_NUM(LILYCOVE_CITY):
        case MAP_NUM(MOSSDEEP_CITY):
        case MAP_NUM(SOOTOPOLIS_CITY):
        case MAP_NUM(EVER_GRANDE_CITY):
        case MAP_NUM(ROUTE124):
        case MAP_NUM(ROUTE125):
        case MAP_NUM(ROUTE126):
        case MAP_NUM(ROUTE127):
        case MAP_NUM(ROUTE128):
            return TRUE;
        default:
            if (VarGet(VAR_0x405E) < 4)
                return FALSE;
            switch (warp->mapNum)
            {
            case MAP_NUM(ROUTE129):
            case MAP_NUM(ROUTE130):
            case MAP_NUM(ROUTE131):
                return TRUE;
            }
        }
    }
    return FALSE;
}

bool16 NoMusicInSotopolisWithLegendaries(struct WarpData *warp)
{
    if (VarGet(VAR_0x40CA) != 1)
        return FALSE;
    if (warp->mapGroup != MAP_GROUP(SOOTOPOLIS_CITY))
        return FALSE;
    if (warp->mapNum == MAP_NUM(SOOTOPOLIS_CITY))
        return TRUE;
    return FALSE;
}

bool16 IsInfiltratedWeatherInstitute(struct WarpData *warp)
{
    if (VarGet(VAR_WEATHER_INSTITUTE_STATE))
        return FALSE;
    if (warp->mapGroup != MAP_GROUP(ROUTE119_WEATHER_INSTITUTE_1F))
        return FALSE;
    if (warp->mapNum == MAP_NUM(ROUTE119_WEATHER_INSTITUTE_1F)
     || warp->mapNum == MAP_NUM(ROUTE119_WEATHER_INSTITUTE_2F))
        return TRUE;
    return FALSE;
}

bool16 IsInflitratedSpaceCenter(struct WarpData *warp)
{
    if (VarGet(VAR_0x405D) == 0)
        return FALSE;
    if (VarGet(VAR_0x405D) > 2)
        return FALSE;
    if (warp->mapGroup != MAP_GROUP(MOSSDEEP_CITY_SPACE_CENTER_1F))
        return FALSE;
    if (warp->mapNum == MAP_NUM(MOSSDEEP_CITY_SPACE_CENTER_1F)
     || warp->mapNum == MAP_NUM(MOSSDEEP_CITY_SPACE_CENTER_2F))
        return TRUE;
    return FALSE;
}

u16 GetLocationMusic(struct WarpData *warp)
{
    if (NoMusicInSotopolisWithLegendaries(warp) == TRUE)
        return 0xFFFF;
    else if (ShouldLegendaryMusicPlayAtLocation(warp) == TRUE)
        return MUS_OOAME;
    else if (IsInflitratedSpaceCenter(warp) == TRUE)
        return MUS_MGM0;
    else if (IsInfiltratedWeatherInstitute(warp) == TRUE)
        return MUS_TOZAN;
    else
        return Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum)->music;
}

u16 GetCurrLocationDefaultMusic(void)
{
    u16 music;

    // Play the desert music only when the sandstorm is active on Route 111.
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE111)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE111)
     && GetSav1Weather() == 8)
        return MUS_ASHROAD;

    music = GetLocationMusic(&gSaveBlock1Ptr->location);
    if (music != 0x7FFF)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1Ptr->pos.x < 24)
            return MUS_DOORO_X1;
        else
            return MUS_GRANROAD;
    }
}

u16 GetWarpDestinationMusic(void)
{
    u16 music = GetLocationMusic(&gWarpDestination);
    if (music != 0x7FFF)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAUVILLE_CITY)
         && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAUVILLE_CITY))
            return MUS_DOORO_X1;
        else
            return MUS_GRANROAD;
    }
}

void Overworld_ResetMapMusic(void)
{
    ResetMapMusic();
}

void Overworld_PlaySpecialMapMusic(void)
{
    u16 music = GetCurrLocationDefaultMusic();

    if (music != MUS_OOAME && music != 0xFFFF)
    {
        if (gSaveBlock1Ptr->savedMusic)
            music = gSaveBlock1Ptr->savedMusic;
        else if (Overworld_GetMapTypeOfSaveblockLocation() == MAP_TYPE_UNDERWATER)
            music = MUS_DEEPDEEP;
        else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
            music = MUS_NAMINORI;
    }

    if (music != GetCurrentMapMusic())
        PlayNewMapMusic(music);
}

void Overworld_SetSavedMusic(u16 songNum)
{
    gSaveBlock1Ptr->savedMusic = songNum;
}

void Overworld_ClearSavedMusic(void)
{
    gSaveBlock1Ptr->savedMusic = 0;
}

void sub_8085810(void)
{
    if (FlagGet(FLAG_SPECIAL_FLAG_0x4001) != TRUE)
    {
        u16 newMusic = GetWarpDestinationMusic();
        u16 currentMusic = GetCurrentMapMusic();
        if (newMusic != MUS_OOAME && newMusic != 0xFFFF)
        {
            if (currentMusic == MUS_DEEPDEEP || currentMusic == MUS_NAMINORI)
                return;
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
                newMusic = MUS_NAMINORI;
        }
        if (newMusic != currentMusic)
        {
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
                FadeOutAndFadeInNewMapMusic(newMusic, 4, 4);
            else
                FadeOutAndPlayNewMapMusic(newMusic, 8);
        }
    }
}

void Overworld_ChangeMusicToDefault(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != GetCurrLocationDefaultMusic())
        FadeOutAndPlayNewMapMusic(GetCurrLocationDefaultMusic(), 8);
}

void Overworld_ChangeMusicTo(u16 newMusic)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != newMusic && currentMusic != MUS_OOAME)
        FadeOutAndPlayNewMapMusic(newMusic, 8);
}

u8 GetMapMusicFadeoutSpeed(void)
{
    struct MapHeader *mapHeader = warp1_get_mapheader();
    if (Overworld_MapTypeIsIndoors(mapHeader->mapType) == TRUE)
        return 2;
    else
        return 4;
}

void music_something(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    u16 warpMusic = GetWarpDestinationMusic();
    if (FlagGet(FLAG_SPECIAL_FLAG_0x4001) != TRUE && warpMusic != GetCurrentMapMusic())
    {
        if (currentMusic == MUS_NAMINORI
            && VarGet(VAR_0x40CA) == 2
            && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && gWarpDestination.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && gWarpDestination.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && gWarpDestination.x == 0x1D
            && gWarpDestination.y == 0x35)
            return;
        FadeOutMapMusic(GetMapMusicFadeoutSpeed());
    }
}

bool8 sub_80859A0(void)
{
    return IsNotWaitingForBGMStop();
}

void Overworld_FadeOutMapMusic(void)
{
    FadeOutMapMusic(4);
}
