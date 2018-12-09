#include "global.h"
#include "overworld.h"
#include "battle_pyramid.h"
#include "battle_setup.h"
#include "berry.h"
#include "bg.h"
// #include "cable_club.h"
#include "clock.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_fadetransition.h"
#include "event_object_movement.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
// #include "field_special_scene.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
// #include "fldeff_flash.h"
#include "gpu_regs.h"
#include "heal_location.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "alloc.h"
#include "m4a.h"
#include "map_name_popup.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "money.h"
#include "new_game.h"
#include "palette.h"
#include "play_time.h"
#include "random.h"
#include "roamer.h"
// #include "rotating_gate.h"
#include "safari_zone.h"
#include "save.h"
#include "save_location.h"
#include "script.h"
// #include "script_pokemon_80C4.h"
#include "secret_base.h"
#include "sound.h"
#include "start_menu.h"
#include "task.h"
// #include "tileset_anim.h"
#include "time_events.h"
#include "tv.h"
#include "scanline_effect.h"
#include "wild_encounter.h"
#include "frontier_util.h"
#include "constants/abilities.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/species.h"

// event scripts
extern const u8 EventScript_WhiteOut[];
extern const u8 EventScript_271862[];
extern const u8 EventScript_277513[];
extern const u8 EventScript_TradeRoom_TooBusyToNotice[];
extern const u8 EventScript_TradeRoom_ReadTrainerCard1[];
extern const u8 EventScript_TradeRoom_ReadTrainerCard2[];
extern const u8 gUnknown_08277388[];
extern const u8 gUnknown_082773A3[];
extern const u8 gUnknown_082773BE[];
extern const u8 gUnknown_082773D9[];
extern const u8 gUnknown_0827741D[];
extern const u8 gUnknown_08277432[];
extern const u8 gUnknown_08277447[];
extern const u8 gUnknown_0827745C[];
extern const u8 gUnknown_08277374[];
extern const u8 gUnknown_0827737E[];
extern const u8 gUnknown_082773FF[];
extern const u8 gUnknown_082773F5[];
extern const u8 gUnknown_082774EF[];
extern const u8 gUnknown_08277509[];

// vars
extern const struct MapLayout *const gMapLayouts[];
extern const struct MapHeader *const *const gMapGroups[];
extern const s32 gMaxFlashLevel;
extern const u16 gUnknown_82EC7C4[];

// functions
extern void HealPlayerParty(void);
extern void move_tilemap_camera_to_upper_left_corner(void);
extern void cur_mapheader_run_tileset_funcs_after_some_cpuset(void);
extern void DrawWholeMapView(void);
extern void copy_map_tileset1_tileset2_to_vram(const struct MapLayout *);
extern void apply_map_tileset1_tileset2_palette(const struct MapLayout *);
extern void ResetCyclingRoadChallengeData(void);
extern void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey);
extern void mapheader_run_script_with_tag_x5(void);
extern void ResetFieldTasksArgs(void);
extern void sub_80A0A2C(void);
extern void not_trainer_hill_battle_pyramid(void);
extern void apply_map_tileset2_palette(const struct MapLayout *);
extern void copy_map_tileset2_to_vram_2(const struct MapLayout *);
extern void RestartWildEncounterImmunitySteps(void);
extern void ShowMapNamePopup(void);
extern bool32 InTrainerHill(void);
extern bool32 sub_808651C(void);
extern bool8 sub_80AF6A4(void);
extern bool8 sub_80E909C(void);
extern void sub_81AA1D8(void);
extern void c2_change_map(void);
extern void sub_81D5DF8(void);
extern void sub_80EB218(void);
extern void sub_81BE72C(void);
extern void sub_80AF3C8(void);
extern void sub_81971F4(void);
extern void sub_808B578(void);
extern void sub_80AF314(void);
extern void sub_80AF214(void);
extern void sub_80AF188(void);
extern void door_upload_tiles(void);
extern void RotatingGate_InitPuzzleAndGraphics(void);
extern void sub_80AF168(void);
extern void sub_80AF3C8(void);
extern void ExecuteTruckSequence(void);
extern void sub_80A0A38(void);
extern void trainer_hill_map_load_related(void);
extern void sub_8087D74(void);
extern void battle_pyramid_map_load_related(u8);
extern void sub_80B00E8(u8);
extern void sub_80E9238(u8);
extern void sub_81AA2F8(void);
extern void sub_8195E10(void);
extern void sub_80EDB44(void);
extern void sub_81D64C0(void);
extern void sub_81BE6AC(void);
extern void sub_8098128(void);
extern void copy_map_tileset1_to_vram(const struct MapLayout *);
extern void copy_map_tileset2_to_vram(const struct MapLayout *);
extern void FieldUpdateBgTilemapScroll(void);
extern void TransferTilesetAnimsBuffer(void);
extern bool32 sub_81D5F48(void);
extern u8 GetCurrentTrainerHillMapId(void);
extern bool8 warp0_in_pokecenter(void);
extern void ResetAllPicSprites(void);
extern void FieldEffectActiveListClear(void);
extern void SetUpFieldTasks(void);
extern void sub_81BE6B8(void);
extern void sub_80AAFA4(void);
extern void ShowStartMenu(void);
extern void sub_80AEE84(void);
extern void mapldr_default(void);
extern void sub_8088B3C(u16, u16);
extern bool32 sub_800F0B8(void);
extern bool32 sub_8009F3C(void);
extern void sub_8010198(void);
extern u32 sub_800B4DC(void);
extern bool32 sub_80B39D4(u8);
extern const u8* GetInteractedLinkPlayerScript(struct MapPosition *a1, u8, u8);
extern u8 *GetCoordEventScriptAtMapPosition(void*);
extern u8 GetFRLGAvatarGraphicsIdByGender(u8);
extern u8 GetRSAvatarGraphicsIdByGender(u8);
extern void UpdateEventObjectSpriteVisibility(struct Sprite*, u8);

// this file's functions
static void Overworld_ResetStateAfterWhiteOut(void);
static void c2_80567AC(void);
static void CB2_LoadMap2(void);
static void VBlankCB_Field(void);
static void SpriteCB_LinkPlayer(struct Sprite *sprite);
static void ChooseAmbientCrySpecies(void);
static void do_load_map_stuff_loop(u8 *state);
static bool32 map_loading_iteration_3(u8 *state);
static bool32 sub_8086638(u8 *state);
static bool32 load_map_stuff(u8 *state, u32);
static bool32 map_loading_iteration_2_link(u8 *state);
static void mli4_mapscripts_and_other(void);
static void InitOverworldGraphicsRegisters(void);
static u8 sub_8087858(u8);
static u16 sub_80871C0(u32 a1);
static void sub_80867C8(void);
static void sub_80867D8(void);
static void sub_8086AE4(void);
static void sub_80869DC(void);
static void sub_8086B14(void);
static void sub_8086AAC(void);
static void sub_8086988(bool32 arg0);
static void sub_8086A80(void);
static void sub_8086A68(void);
static void sub_8086860(void);
static void sub_8086AC8(void);
static void sub_8086B9C(void);
static void sub_8086C40(void);
static void sub_8086C90(void);
static void sub_8086FA0(u16);
static void sub_8086F38(u16*, s32);
static u8 npc_something3(u8 a1, u8 a2);
static u8 LinkPlayerDetectCollision(u8 selfEventObjId, u8 a2, s16 x, s16 y);
static void CreateLinkPlayerSprite(u8 linkPlayerId, u8 gameVersion);
static void sub_8087878(u8 linkPlayerId, u16 *x, u16 *y);
static u8 sub_80878A0(u8 linkPlayerId);
static u8 sub_80878C0(u8 linkPlayerId);
static s32 sub_80878E4(u8 linkPlayerId);
static u8 GetLinkPlayerIdAt(s16 x, s16 y);
static void sub_808796C(u8 linkPlayerId, u8 a2);
static void ZeroEventObject(struct EventObject *eventObj);
static void SpawnLinkPlayerEventObject(u8 linkPlayerId, s16 x, s16 y, u8 a4);
static void InitLinkPlayerEventObjectPos(struct EventObject *eventObj, s16 x, s16 y);
static void sub_80877DC(u8 linkPlayerId, u8 a2);
static void sub_808780C(u8 linkPlayerId);
static u8 sub_8087858(u8 linkPlayerId);
static void sub_8087584(void);
static u32 sub_8087690(void);
static void ZeroLinkPlayerEventObject(struct LinkPlayerEventObject *linkPlayerEventObj);
static const u8 *sub_80873B4(struct UnkStruct_8054FF8 *a1);
static u16 sub_8087480(const u8 *script);
static void sub_8087510(void);
static void sub_808751C(void);
static void sub_8087530(const u8 *script);
static void sub_808754C(void);
static void sub_8087568(const u8 *script);
static void sub_80872D8(s32 linkPlayerId, s32 a2, struct UnkStruct_8054FF8 *a3);
static bool32 sub_8087340(struct UnkStruct_8054FF8 *a1);
static bool32 sub_8087358(struct UnkStruct_8054FF8 *a1);
static u8 *sub_8087370(struct UnkStruct_8054FF8 *a1);
static bool32 sub_8087388(struct UnkStruct_8054FF8 *a1);
static const u8 *sub_80873B4(struct UnkStruct_8054FF8 *a1);
static u16 sub_808711C(u32);
static u16 sub_8087140(u32);
static void sub_808709C(u16 *a1);
static u16 sub_80870B0(u32 a1);
static u16 sub_80870F8(u32 a1);
static u16 sub_8087068(u16 a1);
static void c1_link_related(void);
static void c1_link_related_func_set(u16 (*func)(u32));
static void SetFieldVBlankCallback(void);
static void FieldClearVBlankHBlankCallbacks(void);
static void sub_8085810(void);
static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *playerStruct, u16 a2, u8 a3);
static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *playerStruct, u8 a2, u16 a3, u8 a4);
static u16 GetCenterScreenMetatileBehavior(void);

// IWRAM bss vars
IWRAM_DATA static void *sUnknown_03000E0C;
IWRAM_DATA static u8 sUnknown_03000E10[4];
IWRAM_DATA static u16 (*sUnknown_03000E14)(u32);
IWRAM_DATA static u8 sUnknown_03000E18;
IWRAM_DATA static u8 sUnknown_03000E19;
IWRAM_DATA static u32 sUnusedVar;

// IWRAM common
u16 *gBGTilemapBuffers1;
u16 *gBGTilemapBuffers2;
u16 *gBGTilemapBuffers3;
u16 gUnknown_03005DA8;
void (*gFieldCallback)(void);
bool8 (*gFieldCallback2)(void);
u8 gUnknown_03005DB4;
u8 gFieldLinkPlayerCount;

// EWRAM vars
EWRAM_DATA static u8 sUnknown_020322D8 = 0;
EWRAM_DATA struct WarpData gLastUsedWarp = {0};
EWRAM_DATA static struct WarpData sWarpDestination = {0};  // new warp position
EWRAM_DATA static struct WarpData gFixedDiveWarp = {0};
EWRAM_DATA static struct WarpData gFixedHoleWarp = {0};
EWRAM_DATA static u16 sLastMapSectionId = 0;
EWRAM_DATA static struct InitialPlayerAvatarState gInitialPlayerAvatarState = {0};
EWRAM_DATA static u16 sAmbientCrySpecies = 0;
EWRAM_DATA static bool8 sIsAmbientCryWaterMon = FALSE;
EWRAM_DATA struct LinkPlayerEventObject gLinkPlayerEventObjects[4] = {0};

// const rom data
static const struct WarpData sDummyWarpData =
{
    .mapGroup = -1,
    .mapNum = -1,
    .warpId = -1,
    .x = -1,
    .y = -1,
};

static const u8 sUnusedData[] =
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

const struct UCoords32 gDirectionToVectors[] =
{
    [DIR_NONE] =
    {
        .x =  0,
        .y =  0,
    },
    [DIR_SOUTH] =
    {
        .x =  0,
        .y =  1,
    },
    [DIR_NORTH] =
    {
        .x =  0,
        .y = -1,
    },
    [DIR_WEST] =
    {
        .x = -1,
        .y =  0,
    },
    [DIR_EAST] =
    {
        .x =  1,
        .y =  0,
    },
    [DIR_SOUTHWEST] =
    {
        .x = -1,
        .y =  1,
    },
    [DIR_SOUTHEAST] =
    {
        .x =  1,
        .y =  1,
    },
    [DIR_NORTHWEST] =
    {
        .x = -1,
        .y = -1,
    },
    [DIR_NORTHEAST] =
    {
        .x =  1,
        .y = -1,
    },
};

static const struct BgTemplate gUnknown_08339DAC[] =
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

static const struct ScanlineEffectParams sFlashEffectParams =
{
    (void *)REG_ADDR_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0,
};

static u8 sub_80879D8(struct LinkPlayerEventObject *, struct EventObject *, u8);
static u8 sub_80879F8(struct LinkPlayerEventObject *, struct EventObject *, u8);
static u8 sub_80879FC(struct LinkPlayerEventObject *, struct EventObject *, u8);

static u8 (*const gUnknown_08339DC8[])(struct LinkPlayerEventObject *, struct EventObject *, u8) =
{
    sub_80879D8,
    sub_80879F8,
    sub_80879FC,
};

static u8 sub_8087A1C(struct LinkPlayerEventObject *, struct EventObject *, u8);
static u8 sub_8087A20(struct LinkPlayerEventObject *, struct EventObject *, u8);
static u8 sub_8087A88(struct LinkPlayerEventObject *, struct EventObject *, u8);

static u8 (*const gUnknown_08339DD4[])(struct LinkPlayerEventObject *, struct EventObject *, u8) =
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

static void sub_8087AA0(struct LinkPlayerEventObject *, struct EventObject *);
static void sub_8087AA8(struct LinkPlayerEventObject *, struct EventObject *);

static void (*const gUnknown_08339E00[])(struct LinkPlayerEventObject *, struct EventObject *) =
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
    WarpIntoMap();
}

void Overworld_ResetStateAfterFly(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
}

void Overworld_ResetStateAfterTeleport(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
    ScriptContext2_RunNewScript(EventScript_271862);
}

void Overworld_ResetStateAfterDigEscRope(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
}

static void Overworld_ResetStateAfterWhiteOut(void)
{
    ResetInitialPlayerAvatarState();
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

static void sub_8084788(void)
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

void LoadEventObjTemplatesFromHeader(void)
{
    // Clear map object templates
    CpuFill32(0, gSaveBlock1Ptr->eventObjectTemplates, sizeof(gSaveBlock1Ptr->eventObjectTemplates));

    // Copy map header events to save block
    CpuCopy32(gMapHeader.events->eventObjects,
              gSaveBlock1Ptr->eventObjectTemplates,
              gMapHeader.events->eventObjectCount * sizeof(struct EventObjectTemplate));
}

void LoadSaveblockEventObjScripts(void)
{
    struct EventObjectTemplate *mapHeaderObjTemplates = gMapHeader.events->eventObjects;
    struct EventObjectTemplate *savObjTemplates = gSaveBlock1Ptr->eventObjectTemplates;
    s32 i;

    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
        savObjTemplates[i].script = mapHeaderObjTemplates[i].script;
}

void Overworld_SetEventObjTemplateCoords(u8 localId, s16 x, s16 y)
{
    s32 i;
    struct EventObjectTemplate *savObjTemplates = gSaveBlock1Ptr->eventObjectTemplates;

    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        struct EventObjectTemplate *eventObjectTemplate = &savObjTemplates[i];
        if (eventObjectTemplate->localId == localId)
        {
            eventObjectTemplate->x = x;
            eventObjectTemplate->y = y;
            return;
        }
    }
}

void Overworld_SetEventObjTemplateMovementType(u8 localId, u8 movementType)
{
    s32 i;

    struct EventObjectTemplate *savObjTemplates = gSaveBlock1Ptr->eventObjectTemplates;
    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        struct EventObjectTemplate *eventObjectTemplate = &savObjTemplates[i];
        if (eventObjectTemplate->localId == localId)
        {
            eventObjectTemplate->movementType = movementType;
            return;
        }
    }
}

static void mapdata_load_assets_to_gpu_and_full_redraw(void)
{
    move_tilemap_camera_to_upper_left_corner();
    copy_map_tileset1_tileset2_to_vram(gMapHeader.mapLayout);
    apply_map_tileset1_tileset2_palette(gMapHeader.mapLayout);
    DrawWholeMapView();
    cur_mapheader_run_tileset_funcs_after_some_cpuset();
}

const struct MapLayout *GetMapLayout(void)
{
    u16 mapLayoutId = gSaveBlock1Ptr->mapLayoutId;
    if (mapLayoutId)
        return gMapLayouts[mapLayoutId - 1];
    return NULL;
}

void ApplyCurrentWarp(void)
{
    gLastUsedWarp = gSaveBlock1Ptr->location;
    gSaveBlock1Ptr->location = sWarpDestination;
    gFixedDiveWarp = sDummyWarpData;
    gFixedHoleWarp = sDummyWarpData;
}

void set_warp2_warp3_to_neg_1(void)
{
    gFixedDiveWarp = sDummyWarpData;
    gFixedHoleWarp = sDummyWarpData;
}

static void SetWarpData(struct WarpData *warp, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp->mapGroup = mapGroup;
    warp->mapNum = mapNum;
    warp->warpId = warpId;
    warp->x = x;
    warp->y = y;
}

static bool32 IsDummyWarp(struct WarpData *warp)
{
    if (warp->mapGroup != -1)
        return FALSE;
    else if (warp->mapNum != -1)
        return FALSE;
    else if (warp->warpId != -1)
        return FALSE;
    else if (warp->x != -1)
        return FALSE;
    else if (warp->y != -1)
        return FALSE;
    else
        return TRUE;
}

struct MapHeader const *const Overworld_GetMapHeaderByGroupAndId(u16 mapGroup, u16 mapNum)
{
    return gMapGroups[mapGroup][mapNum];
}

struct MapHeader const *const GetDestinationWarpMapHeader(void)
{
    return Overworld_GetMapHeaderByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
}

static void LoadCurrentMapData(void)
{
    sLastMapSectionId = gMapHeader.regionMapSectionId;
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gSaveBlock1Ptr->mapLayoutId = gMapHeader.mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout();
}

static void LoadSaveblockMapHeader(void)
{
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gMapHeader.mapLayout = GetMapLayout();
}

static void SetPlayerCoordsFromWarp(void)
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
        gSaveBlock1Ptr->pos.x = gMapHeader.mapLayout->width / 2;
        gSaveBlock1Ptr->pos.y = gMapHeader.mapLayout->height / 2;
    }
}

void WarpIntoMap(void)
{
    ApplyCurrentWarp();
    LoadCurrentMapData();
    SetPlayerCoordsFromWarp();
}

void Overworld_SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sWarpDestination, mapGroup, mapNum, warpId, x, y);
}

void warp1_set_2(s8 mapGroup, s8 mapNum, s8 warpId)
{
    Overworld_SetWarpDestination(mapGroup, mapNum, warpId, -1, -1);
}

void saved_warp2_set(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpData(&gSaveBlock1Ptr->warp2, mapGroup, mapNum, warpId, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
}

void saved_warp2_set_2(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->warp2, mapGroup, mapNum, warpId, x, y);
}

void copy_saved_warp2_bank_and_enter_x_to_warp1(u8 unused)
{
    sWarpDestination = gSaveBlock1Ptr->warp2;
}

void sub_8084CCC(u8 a1)
{
    const struct HealLocation *warp = GetHealLocation(a1);

    if (warp)
        Overworld_SetWarpDestination(warp->group, warp->map, -1, warp->x, warp->y);
}

void Overworld_SetWarpDestToLastHealLoc(void)
{
    sWarpDestination = gSaveBlock1Ptr->lastHealLocation;
}

void Overworld_SetHealLocationWarp(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);

    if (healLocation != NULL)
        SetWarpData(&gSaveBlock1Ptr->lastHealLocation, healLocation->group, healLocation->map, -1, healLocation->x, healLocation->y);
}

void sub_8084D5C(s16 a1, s16 a2)
{
    u8 currMapType = Overworld_GetMapTypeOfSaveblockLocation();
    u8 destMapType = GetMapTypeByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
    if (is_map_type_1_2_3_5_or_6(currMapType) && is_map_type_1_2_3_5_or_6(destMapType) != TRUE)
        sub_8084DD4(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, a1 - 7, a2 - 6);
}

void sub_8084DD4(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->warp4, mapGroup, mapNum, warpId, x, y);
}

void sub_8084E14(void)
{
    sWarpDestination = gSaveBlock1Ptr->warp4;
}

void SetFixedDiveWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gFixedDiveWarp, mapGroup, mapNum, warpId, x, y);
}

static void SetFixedDiveWarpAsDestination(void)
{
    sWarpDestination = gFixedDiveWarp;
}

void SetFixedHoleWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gFixedHoleWarp, mapGroup, mapNum, warpId, x, y);
}

void SetFixedHoleWarpAsDestination(s16 x, s16 y)
{
    if (IsDummyWarp(&gFixedHoleWarp) == TRUE)
        sWarpDestination = gLastUsedWarp;
    else
        Overworld_SetWarpDestination(gFixedHoleWarp.mapGroup, gFixedHoleWarp.mapNum, -1, x, y);
}

void warp1_set_to_sav1w(void)
{
    sWarpDestination = gSaveBlock1Ptr->warp1;
}

void sub_8084F2C(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->warp1, mapGroup, mapNum, warpId, x, y);
}

void sub_8084F6C(u8 a1)
{
    const struct HealLocation *warp = GetHealLocation(a1);
    if (warp)
        SetWarpData(&gSaveBlock1Ptr->warp1, warp->group, warp->map, -1, warp->x, warp->y);
}

void sub_8084FAC(int unused)
{
    gSaveBlock1Ptr->warp1 = gSaveBlock1Ptr->warp2;
}

const struct MapConnection *GetMapConnection(u8 dir)
{
    s32 i;
    s32 count = gMapHeader.connections->count;
    const struct MapConnection *connection = gMapHeader.connections->connections;

    if (connection == NULL)
        return NULL;

    for(i = 0; i < count; i++, connection++)
        if (connection->direction == dir)
            return connection;

    return NULL;
}

static bool8 SetDiveWarp(u8 dir, u16 x, u16 y)
{
    const struct MapConnection *connection = GetMapConnection(dir);

    if (connection != NULL)
    {
        Overworld_SetWarpDestination(connection->mapGroup, connection->mapNum, -1, x, y);
    }
    else
    {
        mapheader_run_script_with_tag_x6();
        if (IsDummyWarp(&gFixedDiveWarp))
            return FALSE;
        SetFixedDiveWarpAsDestination();
    }
    return TRUE;
}

bool8 SetDiveWarpEmerge(u16 x, u16 y)
{
    return SetDiveWarp(CONNECTION_EMERGE, x, y);
}

bool8 SetDiveWarpDive(u16 x, u16 y)
{
    return SetDiveWarp(CONNECTION_DIVE, x, y);
}

void mliX_load_map(u8 mapGroup, u8 mapNum)
{
    s32 paletteIndex;

    Overworld_SetWarpDestination(mapGroup, mapNum, -1, -1, -1);
    if (gMapHeader.regionMapSectionId != 0x3A)
        sub_8085810();

    ApplyCurrentWarp();
    LoadCurrentMapData();
    LoadEventObjTemplatesFromHeader();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    RestartWildEncounterImmunitySteps();
    TryUpdateRandomTrainerRematches(mapGroup, mapNum);
    DoTimeBasedEvents();
    SetSav1WeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    mapheader_run_script_with_tag_x3();
    not_trainer_hill_battle_pyramid();
    copy_map_tileset2_to_vram_2(gMapHeader.mapLayout);
    apply_map_tileset2_palette(gMapHeader.mapLayout);

    for (paletteIndex = 6; paletteIndex < 13; paletteIndex++)
        ApplyWeatherGammaShiftToPal(paletteIndex);

    sub_80A0A2C();
    UpdateLocationHistoryForRoamer();
    RoamerMove();
    DoCurrentWeather();
    ResetFieldTasksArgs();
    mapheader_run_script_with_tag_x5();

    if (gMapHeader.regionMapSectionId != 0x3A || gMapHeader.regionMapSectionId != sLastMapSectionId)
        ShowMapNamePopup();
}

static void mli0_load_map(u32 a1)
{
    bool8 v2;
    bool8 indoors;

    LoadCurrentMapData();
    if (!(sUnknown_020322D8 & 1))
    {
        if (gMapHeader.mapLayoutId == 0x169)
            sub_81AA1D8();
        else if (InTrainerHill())
            sub_81D5DF8();
        else
            LoadEventObjTemplatesFromHeader();
    }

    v2 = is_map_type_1_2_3_5_or_6(gMapHeader.mapType);
    indoors = Overworld_MapTypeIsIndoors(gMapHeader.mapType);

    sub_80EB218();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    RestartWildEncounterImmunitySteps();
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
    if (gMapHeader.mapLayoutId == 0x169)
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

void ResetInitialPlayerAvatarState(void)
{
    gInitialPlayerAvatarState.direction = DIR_SOUTH;
    gInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

void StoreInitialPlayerAvatarState(void)
{
    gInitialPlayerAvatarState.direction = GetPlayerFacingDirection();

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        gInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        gInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ACRO_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        gInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_SURFING;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        gInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_UNDERWATER;
    else
        gInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

static struct InitialPlayerAvatarState *GetInitialPlayerAvatarState(void)
{
    struct InitialPlayerAvatarState playerStruct;
    u8 mapType = Overworld_GetMapTypeOfSaveblockLocation();
    u16 metatileBehavior = GetCenterScreenMetatileBehavior();
    u8 transitionFlags = GetAdjustedInitialTransitionFlags(&gInitialPlayerAvatarState, metatileBehavior, mapType);
    playerStruct.transitionFlags = transitionFlags;
    playerStruct.direction = GetAdjustedInitialDirection(&gInitialPlayerAvatarState, transitionFlags, metatileBehavior, mapType);
    gInitialPlayerAvatarState = playerStruct;
    return &gInitialPlayerAvatarState;
}

static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *playerStruct, u16 metatileBehavior, u8 mapType)
{
    if (mapType != MAP_TYPE_INDOOR && FlagGet(FLAG_SYS_CRUISE_MODE))
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else if (mapType == MAP_TYPE_UNDERWATER)
        return PLAYER_AVATAR_FLAG_UNDERWATER;
    else if (MetatileBehavior_IsSurfableWaterOrUnderwater(metatileBehavior) == TRUE)
        return PLAYER_AVATAR_FLAG_SURFING;
    else if (Overworld_IsBikingAllowed() != TRUE)
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else if (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_MACH_BIKE)
        return PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (playerStruct->transitionFlags != PLAYER_AVATAR_FLAG_ACRO_BIKE)
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else
        return PLAYER_AVATAR_FLAG_ACRO_BIKE;
}

static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *playerStruct, u8 transitionFlags, u16 metatileBehavior, u8 mapType)
{
    if (FlagGet(FLAG_SYS_CRUISE_MODE) && mapType == MAP_TYPE_6)
        return DIR_EAST;
    else if (MetatileBehavior_IsDeepSouthWarp(metatileBehavior) == TRUE)
        return DIR_NORTH;
    else if (MetatileBehavior_IsNonAnimDoor(metatileBehavior) == TRUE || MetatileBehavior_IsDoor(metatileBehavior) == TRUE)
        return DIR_SOUTH;
    else if (MetatileBehavior_IsSouthArrowWarp(metatileBehavior) == TRUE)
        return DIR_NORTH;
    else if (MetatileBehavior_IsNorthArrowWarp(metatileBehavior) == TRUE)
        return DIR_SOUTH;
    else if (MetatileBehavior_IsWestArrowWarp(metatileBehavior) == TRUE)
        return DIR_EAST;
    else if (MetatileBehavior_IsEastArrowWarp(metatileBehavior) == TRUE)
        return DIR_WEST;
    else if ((playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER  && transitionFlags == PLAYER_AVATAR_FLAG_SURFING)
     || (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_SURFING && transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER ))
        return playerStruct->direction;
    else if (MetatileBehavior_IsLadder(metatileBehavior) == TRUE)
        return playerStruct->direction;
    else
        return DIR_SOUTH;
}

static u16 GetCenterScreenMetatileBehavior(void)
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

void sub_8085524(u16 mapLayoutId)
{
    gSaveBlock1Ptr->mapLayoutId = mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout();
}

void sub_8085540(u8 var)
{
    sUnknown_020322D8 = var;
}

u8 sub_808554C(void)
{
    return sUnknown_020322D8;
}

static bool16 ShouldLegendaryMusicPlayAtLocation(struct WarpData *warp)
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

static bool16 NoMusicInSotopolisWithLegendaries(struct WarpData *warp)
{
    if (VarGet(VAR_0x40CA) != 1)
        return FALSE;
    else if (warp->mapGroup != MAP_GROUP(SOOTOPOLIS_CITY))
        return FALSE;
    else if (warp->mapNum == MAP_NUM(SOOTOPOLIS_CITY))
        return TRUE;
    else
        return FALSE;
}

static bool16 IsInfiltratedWeatherInstitute(struct WarpData *warp)
{
    if (VarGet(VAR_WEATHER_INSTITUTE_STATE))
        return FALSE;
    else if (warp->mapGroup != MAP_GROUP(ROUTE119_WEATHER_INSTITUTE_1F))
        return FALSE;
    else if (warp->mapNum == MAP_NUM(ROUTE119_WEATHER_INSTITUTE_1F)
     || warp->mapNum == MAP_NUM(ROUTE119_WEATHER_INSTITUTE_2F))
        return TRUE;
    else
        return FALSE;
}

static bool16 IsInflitratedSpaceCenter(struct WarpData *warp)
{
    if (VarGet(VAR_0x405D) == 0)
        return FALSE;
    else if (VarGet(VAR_0x405D) > 2)
        return FALSE;
    else if (warp->mapGroup != MAP_GROUP(MOSSDEEP_CITY_SPACE_CENTER_1F))
        return FALSE;
    else if (warp->mapNum == MAP_NUM(MOSSDEEP_CITY_SPACE_CENTER_1F)
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
    u16 music = GetLocationMusic(&sWarpDestination);
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

static void sub_8085810(void)
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
    const struct MapHeader *mapHeader = GetDestinationWarpMapHeader();
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
            && sWarpDestination.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && sWarpDestination.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && sWarpDestination.x == 0x1D
            && sWarpDestination.y == 0x35)
            return;
        FadeOutMapMusic(GetMapMusicFadeoutSpeed());
    }
}

bool8 BGMusicStopped(void)
{
    return IsNotWaitingForBGMStop();
}

void Overworld_FadeOutMapMusic(void)
{
    FadeOutMapMusic(4);
}

static void PlayAmbientCry(void)
{
    s16 x, y;
    s8 pan;
    s8 volume;

    PlayerGetDestCoords(&x, &y);
    if (sIsAmbientCryWaterMon == TRUE
     && !MetatileBehavior_IsSurfableWaterOrUnderwater(MapGridGetMetatileBehaviorAt(x, y)))
        return;
    pan = (Random() % 88) + 212;
    volume = (Random() % 30) + 50;
    PlayCry2(sAmbientCrySpecies, pan, volume, 1);
}

void UpdateAmbientCry(s16 *state, u16 *delayCounter)
{
    u8 i, monsCount, divBy;

    switch (*state)
    {
    case 0:
        if (sAmbientCrySpecies == SPECIES_NONE)
            *state = 4;
        else
            *state = 1;
        break;
    case 1:
        *delayCounter = (Random() % 2400) + 1200;
        *state = 3;
        break;
    case 2:
        divBy = 1;
        monsCount = CalculatePlayerPartyCount();
        for (i = 0; i < monsCount; i++)
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_SANITY_BIT3)
                && GetMonAbility(&gPlayerParty[0]) == ABILITY_SWARM)
            {
                divBy = 2;
                break;
            }
        }
        *delayCounter = ((Random() % 1200) + 1200) / divBy;
        *state = 3;
        break;
    case 3:
        (*delayCounter)--;
        if (*delayCounter == 0)
        {
            PlayAmbientCry();
            *state = 2;
        }
        break;
    case 4:
        break;
    }
}

static void ChooseAmbientCrySpecies(void)
{
    if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE130)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE130))
     && !IsMirageIslandPresent())
    {
        // Only play water pokemon cries on this route
        // when Mirage Island is not present
        sIsAmbientCryWaterMon = TRUE;
        sAmbientCrySpecies = GetLocalWaterMon();
    }
    else
    {
        sAmbientCrySpecies = GetLocalWildMon(&sIsAmbientCryWaterMon);
    }
}

u8 GetMapTypeByGroupAndId(s8 mapGroup, s8 mapNum)
{
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->mapType;
}

u8 GetMapTypeByWarpData(struct WarpData *warp)
{
    return GetMapTypeByGroupAndId(warp->mapGroup, warp->mapNum);
}

u8 Overworld_GetMapTypeOfSaveblockLocation(void)
{
    return GetMapTypeByWarpData(&gSaveBlock1Ptr->location);
}

u8 GetLastUsedWarpMapType(void)
{
    return GetMapTypeByWarpData(&gLastUsedWarp);
}

bool8 is_map_type_1_2_3_5_or_6(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_UNDERWATER
     || mapType == MAP_TYPE_CITY
     || mapType == MAP_TYPE_6)
        return TRUE;
    else
        return FALSE;
}

bool8 Overworld_MapTypeAllowsTeleportAndFly(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_6
     || mapType == MAP_TYPE_CITY)
        return TRUE;
    else
        return FALSE;
}

bool8 Overworld_MapTypeIsIndoors(u8 mapType)
{
    if (mapType == MAP_TYPE_INDOOR
     || mapType == MAP_TYPE_SECRET_BASE)
        return TRUE;
    else
        return FALSE;
}

u8 sav1_saved_warp2_map_get_name(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->warp2.mapGroup, gSaveBlock1Ptr->warp2.mapNum)->regionMapSectionId;
}

u8 sav1_map_get_name(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->regionMapSectionId;
}

u8 GetCurrentMapBattleScene(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->battleType;
}

static void overworld_bg_setup(void)
{
    InitBgsFromTemplates(0, gUnknown_08339DAC, ARRAY_COUNT(gUnknown_08339DAC));
    SetBgAttribute(1, BG_CTRL_ATTR_PALETTEMODE, 1);
    SetBgAttribute(2, BG_CTRL_ATTR_PALETTEMODE, 1);
    SetBgAttribute(3, BG_CTRL_ATTR_PALETTEMODE, 1);
    gBGTilemapBuffers2 = AllocZeroed(0x800);
    gBGTilemapBuffers1 = AllocZeroed(0x800);
    gBGTilemapBuffers3 = AllocZeroed(0x800);
    SetBgTilemapBuffer(1, gBGTilemapBuffers2);
    SetBgTilemapBuffer(2, gBGTilemapBuffers1);
    SetBgTilemapBuffer(3, gBGTilemapBuffers3);
    sub_81971D0();
}

void overworld_free_bg_tilemaps(void)
{
    sub_81BE72C();
    sub_81971F4();
    if (gBGTilemapBuffers3 != NULL)
        FREE_AND_SET_NULL(gBGTilemapBuffers3);
    if (gBGTilemapBuffers1 != NULL)
        FREE_AND_SET_NULL(gBGTilemapBuffers1);
    if (gBGTilemapBuffers2 != NULL)
        FREE_AND_SET_NULL(gBGTilemapBuffers2);
}

static void ResetSafariZoneFlag_(void)
{
    ResetSafariZoneFlag();
}

bool32 is_c1_link_related_active(void)
{
    if (gMain.callback1 == c1_link_related)
        return TRUE;
    else
        return FALSE;
}

static void DoCB1_Overworld(u16 newKeys, u16 heldKeys)
{
    struct FieldInput inputStruct;

    sub_808B578();
    FieldClearPlayerInput(&inputStruct);
    FieldGetPlayerInput(&inputStruct, newKeys, heldKeys);
    if (!ScriptContext2_IsEnabled())
    {
        if (ProcessPlayerFieldInput(&inputStruct) == 1)
        {
            ScriptContext2_Enable();
            HideMapNamePopUpWindow();
        }
        else
        {
            player_step(inputStruct.dpadDirection, newKeys, heldKeys);
        }
    }
}

void CB1_Overworld(void)
{
    if (gMain.callback2 == CB2_Overworld)
        DoCB1_Overworld(gMain.newKeys, gMain.heldKeys);
}

static void OverworldBasic(void)
{
    ScriptContext2_RunScript();
    RunTasks();
    AnimateSprites();
    CameraUpdate();
    UpdateCameraPanning();
    BuildOamBuffer();
    UpdatePaletteFade();
    sub_80A0A38();
    do_scheduled_bg_tilemap_copies_to_vram();
}

// This CB2 is used when starting
void CB2_OverworldBasic(void)
{
    OverworldBasic();
}

void CB2_Overworld(void)
{
    bool32 fading = (gPaletteFade.active != 0);
    if (fading)
        SetVBlankCallback(NULL);
    OverworldBasic();
    if (fading)
        SetFieldVBlankCallback();
}

void SetMainCallback1(MainCallback cb)
{
    gMain.callback1 = cb;
}

void sub_8085E94(void *a0)
{
    sUnknown_03000E0C = a0;
}

static bool8 map_post_load_hook_exec(void)
{
    if (gFieldCallback2 != NULL)
    {
        if (!gFieldCallback2())
        {
            return FALSE;
        }
        else
        {
            gFieldCallback2 = NULL;
            gFieldCallback = NULL;
        }
    }
    else
    {
        if (gFieldCallback != NULL)
            gFieldCallback();
        else
            mapldr_default();

        gFieldCallback = NULL;
    }

    return TRUE;
}

void CB2_NewGame(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    NewGameInitData();
    ResetInitialPlayerAvatarState();
    PlayTimeCounter_Start();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    gFieldCallback = ExecuteTruckSequence;
    gFieldCallback2 = NULL;
    do_load_map_stuff_loop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
}

void CB2_WhiteOut(void)
{
    u8 val;

    if (++gMain.state >= 120)
    {
        FieldClearVBlankHBlankCallbacks();
        StopMapMusic();
        ResetSafariZoneFlag_();
        DoWhiteOut();
        ResetInitialPlayerAvatarState();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        gFieldCallback = sub_80AF3C8;
        val = 0;
        do_load_map_stuff_loop(&val);
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_LoadMap(void)
{
    FieldClearVBlankHBlankCallbacks();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    SetMainCallback1(NULL);
    SetMainCallback2(c2_change_map);
    gMain.savedCallback = CB2_LoadMap2;
}

static void CB2_LoadMap2(void)
{
    do_load_map_stuff_loop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
}

void sub_8086024(void)
{
    if (!gMain.state)
    {
        FieldClearVBlankHBlankCallbacks();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        SetMainCallback1(NULL);
    }
    if (load_map_stuff(&gMain.state, 1))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void sub_8086074(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = sub_80AF314;
    SetMainCallback2(c2_80567AC);
}

static void c2_80567AC(void)
{
    if (map_loading_iteration_3(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(c1_link_related);
        sub_8086C2C();
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToField(void)
{
    if (is_c1_link_related_active() == TRUE)
    {
        SetMainCallback2(CB2_ReturnToFieldLink);
    }
    else
    {
        FieldClearVBlankHBlankCallbacks();
        SetMainCallback2(CB2_ReturnToFieldLocal);
    }
}

void CB2_ReturnToFieldLocal(void)
{
    if (sub_8086638(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToFieldLink(void)
{
    if (!sub_8087598() && map_loading_iteration_2_link(&gMain.state))
        SetMainCallback2(CB2_Overworld);
}

void c2_8056854(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    SetMainCallback1(c1_link_related);
    sub_8086C2C();

    if (gWirelessCommType != 0)
        gFieldCallback = sub_80AF314;
    else
        gFieldCallback = sub_80AF214;

    ScriptContext1_Init();
    ScriptContext2_Disable();
    CB2_ReturnToField();
}

void CB2_ReturnToFieldWithOpenMenu(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback2 = sub_80AF6A4;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScript(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = sub_80AF188;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScriptPlayMapMusic(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = sub_80AF168;
    CB2_ReturnToField();
}

void sub_80861E8(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = sub_80AF3C8;
    CB2_ReturnToField();
}

static void sub_8086204(void)
{
    if ((gMapHeader.flags & 0xF8) == 8 && sub_80E909C() == TRUE)
        ShowMapNamePopup();
    sub_80AF3C8();
}

void CB2_ContinueSavedGame(void)
{
    u8 trainerHillMapId;

    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    if (gSaveFileStatus == 0xFF)
        sub_81A3908();

    LoadSaveblockMapHeader();
    set_warp2_warp3_to_neg_1();
    trainerHillMapId = GetCurrentTrainerHillMapId();
    if (gMapHeader.mapLayoutId == 0x169)
        sub_81AA2F8();
    else if (trainerHillMapId != 0 && trainerHillMapId != 6)
        sub_81D5F48();
    else
        LoadSaveblockEventObjScripts();

    UnfreezeEventObjects();
    DoTimeBasedEvents();
    sub_8084788();
    if (gMapHeader.mapLayoutId == 0x169)
        battle_pyramid_map_load_related(1);
    else if (trainerHillMapId != 0)
        trainer_hill_map_load_related();
    else
        sub_8087D74();

    PlayTimeCounter_Start();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    sub_8195E10();
    if (GetSecretBase2Field_9() == 1)
    {
        ClearSecretBase2Field_9();
        warp1_set_to_sav1w();
        WarpIntoMap();
        sub_80EDB44();
        SetMainCallback2(CB2_LoadMap);
    }
    else
    {
        sub_80EDB44();
        gFieldCallback = sub_8086204;
        SetMainCallback1(CB1_Overworld);
        CB2_ReturnToField();
    }
}

static void FieldClearVBlankHBlankCallbacks(void)
{
    if (warp0_in_pokecenter() == TRUE)
        CloseLink();

    if (gWirelessCommType != 0)
    {
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        DisableInterrupts(INTR_FLAG_HBLANK);
    }
    else
    {
        u16 savedIme = REG_IME;
        REG_IME = 0;
        REG_IE &= ~INTR_FLAG_HBLANK;
        REG_IE |= INTR_FLAG_VBLANK;
        REG_IME = savedIme;
    }

    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void SetFieldVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_Field);
}

static void VBlankCB_Field(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
    FieldUpdateBgTilemapScroll();
    TransferPlttBuffer();
    TransferTilesetAnimsBuffer();
}

static void InitCurrentFlashLevelScanlineEffect(void)
{
    u8 flashLevel;

    if (InBattlePyramid_())
    {
        door_upload_tiles();
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
    else if ((flashLevel = Overworld_GetFlashLevel()))
    {
        sub_80B00E8(flashLevel);
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
}

static bool32 map_loading_iteration_3(u8 *state)
{
    switch (*state)
    {
    case 0:
        overworld_bg_setup();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        sub_80867C8();
        sub_80867D8();
        (*state)++;
        break;
    case 1:
        mli0_load_map(1);
        (*state)++;
        break;
    case 2:
        sub_8086988(TRUE);
        (*state)++;
        break;
    case 3:
        sub_8086AE4();
        sub_80869DC();
        sub_8086B14();
        sub_8086AAC();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        sub_8197200();
        (*state)++;
        break;
    case 5:
        move_tilemap_camera_to_upper_left_corner();
        (*state)++;
        break;
    case 6:
        copy_map_tileset1_to_vram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        copy_map_tileset2_to_vram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (free_temp_tile_data_buffers_if_possible() != TRUE)
        {
            apply_map_tileset1_tileset2_palette(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        cur_mapheader_run_tileset_funcs_after_some_cpuset();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (map_post_load_hook_exec())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 load_map_stuff(u8 *state, u32 a2)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        mli0_load_map(a2);
        (*state)++;
        break;
    case 1:
        sub_80867C8();
        sub_80867D8();
        (*state)++;
        break;
    case 2:
        sub_8086988(a2);
        (*state)++;
        break;
    case 3:
        mli4_mapscripts_and_other();
        sub_8086A80();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        sub_8197200();
        (*state)++;
        break;
    case 5:
        move_tilemap_camera_to_upper_left_corner();
        (*state)++;
        break;
    case 6:
        copy_map_tileset1_to_vram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        copy_map_tileset2_to_vram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (free_temp_tile_data_buffers_if_possible() != TRUE)
        {
            apply_map_tileset1_tileset2_palette(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        cur_mapheader_run_tileset_funcs_after_some_cpuset();
        (*state)++;
        break;
    case 11:
        if ((gMapHeader.flags & 0xF8) == 8 && sub_80E909C() == 1)
            ShowMapNamePopup();
        (*state)++;
        break;
    case 12:
        if (map_post_load_hook_exec())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_8086638(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_80867C8();
        sub_80867D8();
        sub_8086988(0);
        sub_8086A68();
        sub_8086A80();
        (*state)++;
        break;
    case 1:
        sub_8086860();
        sub_81D64C0();
        (*state)++;
        break;
    case 2:
        if (map_post_load_hook_exec())
            (*state)++;
        break;
    case 3:
        return TRUE;
    }

    return FALSE;
}

static bool32 map_loading_iteration_2_link(u8 *state)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        sub_80867C8();
        sub_80867D8();
        (*state)++;
        break;
    case 1:
        sub_8086988(1);
        (*state)++;
        break;
    case 2:
        sub_8086B9C();
        sub_8086A68();
        sub_8086AC8();
        (*state)++;
        break;
    case 3:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        sub_8197200();
        (*state)++;
        break;
    case 4:
        move_tilemap_camera_to_upper_left_corner();
        (*state)++;
        break;
    case 5:
        copy_map_tileset1_to_vram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 6:
        copy_map_tileset2_to_vram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        if (free_temp_tile_data_buffers_if_possible() != TRUE)
        {
            apply_map_tileset1_tileset2_palette(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 8:
        DrawWholeMapView();
        (*state)++;
        break;
    case 9:
        cur_mapheader_run_tileset_funcs_after_some_cpuset();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (map_post_load_hook_exec())
            (*state)++;
        break;
    case 10:
        (*state)++;
        break;
    case 13:
        SetFieldVBlankCallback();
        (*state)++;
        return TRUE;
    }

    return FALSE;
}

static void do_load_map_stuff_loop(u8 *state)
{
    while (!load_map_stuff(state, 0));
}

static void sub_80867C8(void)
{
    sub_81BE6AC();
    MoveSaveBlocks_ResetHeap();
}

static void sub_80867D8(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ScanlineEffect_Stop();

    DmaClear16(3, PLTT + 2, PLTT_SIZE - 2);
    DmaFillLarge16(3, 0, (void *)(VRAM + 0x0), 0x18000, 0x1000);
    ResetOamRange(0, 128);
    LoadOam();
}

static void sub_8086860(void)
{
    InitCurrentFlashLevelScanlineEffect();
    InitOverworldGraphicsRegisters();
    sub_8197200();
    mapdata_load_assets_to_gpu_and_full_redraw();
}

static void InitOverworldGraphicsRegisters(void)
{
    clear_scheduled_bg_copies_to_vram();
    reset_temp_tile_data_buffers();
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WININ, 0x1F1F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x101);
    SetGpuReg(REG_OFFSET_WIN0H, 0xFF);
    SetGpuReg(REG_OFFSET_WIN0V, 0xFF);
    SetGpuReg(REG_OFFSET_WIN1H, 0xFFFF);
    SetGpuReg(REG_OFFSET_WIN1V, 0xFFFF);
    SetGpuReg(REG_OFFSET_BLDCNT, gUnknown_82EC7C4[1] | gUnknown_82EC7C4[2] | gUnknown_82EC7C4[3]
                               | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(13, 7));
    overworld_bg_setup();
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON
                                | DISPCNT_OBJ_1D_MAP | DISPCNT_HBLANK_INTERVAL);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    sub_8098128();
}

static void sub_8086988(u32 a1)
{
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    ScanlineEffect_Clear();
    ResetAllPicSprites();
    ResetCameraUpdateInfo();
    InstallCameraPanAheadCallback();
    if (!a1)
        InitEventObjectPalettes(0);
    else
        InitEventObjectPalettes(1);

    FieldEffectActiveListClear();
    sub_80AAFA4();
    sub_80AEE84();
    if (!a1)
        SetUpFieldTasks();
    mapheader_run_script_with_tag_x5();
    sub_81BE6B8();
}

static void sub_80869DC(void)
{
    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetEventObjects();
    TrySpawnEventObjects(0, 0);
    mapheader_run_first_tag4_script_list_match();
}

static void mli4_mapscripts_and_other(void)
{
    s16 x, y;
    struct InitialPlayerAvatarState *player;

    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetEventObjects();
    sav1_camera_get_focus_coords(&x, &y);
    player = GetInitialPlayerAvatarState();
    InitPlayerAvatar(x, y, player->direction, gSaveBlock2Ptr->playerGender);
    SetPlayerAvatarTransitionFlags(player->transitionFlags);
    ResetInitialPlayerAvatarState();
    TrySpawnEventObjects(0, 0);
    mapheader_run_first_tag4_script_list_match();
}

static void sub_8086A68(void)
{
    sub_808E16C(0, 0);
    RotatingGate_InitPuzzleAndGraphics();
    mapheader_run_script_with_tag_x7();
}

static void sub_8086A80(void)
{
    gEventObjects[gPlayerAvatar.eventObjectId].trackedByCamera = 1;
    InitCameraUpdateCallback(gPlayerAvatar.spriteId);
}

static void sub_8086AAC(void)
{
    InitCameraUpdateCallback(sub_8087858(gUnknown_03005DB4));
}

static void sub_8086AC8(void)
{
    InitCameraUpdateCallback(sub_8087858(gUnknown_03005DB4));
}

static void sub_8086AE4(void)
{
    u16 x, y;
    sav1_camera_get_focus_coords(&x, &y);
    sub_8088B3C(x + gUnknown_03005DB4, y);
}

static void sub_8086B14(void)
{
    u16 i;
    u16 x, y;

    sav1_camera_get_focus_coords(&x, &y);
    x -= gUnknown_03005DB4;

    for (i = 0; i < gFieldLinkPlayerCount; i++)
    {
        SpawnLinkPlayerEventObject(i, i + x, y, gLinkPlayers[i].gender);
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
    }

    sub_8086C40();
}

static void sub_8086B9C(void)
{
    u16 i;
    for (i = 0; i < gFieldLinkPlayerCount; i++)
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
}

static void c1_link_related(void)
{
    if (gWirelessCommType == 0 || !sub_800F0B8() || !sub_8009F3C())
    {
        u8 var = gUnknown_03005DB4;
        sub_8086F38(gLinkPartnersHeldKeys, var);
        sub_8086FA0(sUnknown_03000E14(var));
        sub_8086C40();
    }
}

void sub_8086C2C(void)
{
    sub_8086C90();
    c1_link_related_func_set(sub_80870B0);
}

static void sub_8086C40(void)
{
    sub_808709C(gLinkPartnersHeldKeys);
}

static void c1_link_related_func_set(u16 (*func)(u32))
{
    sUnknown_03000E19 = 0;
    sUnknown_03000E14 = func;
}

static void sub_8086C64(void)
{
    if (gWirelessCommType != 0 && ++sUnknown_03000E19 > 60)
        sub_8010198();
}

static void sub_8086C90(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
        sUnknown_03000E10[i] = 0x80;
}

static bool32 sub_8086CA8(u16 a1)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sUnknown_03000E10[i] != a1)
            return FALSE;
    return TRUE;
}

static bool32 sub_8086CE0(u16 a1)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sUnknown_03000E10[i] == a1)
            return TRUE;
    return FALSE;
}

static void sub_8086D18(u32 a1, u16 a2, struct UnkStruct_8054FF8 *a3, u16 *a4)
{
    const u8 *script;

    if (sUnknown_03000E10[a1] == 0x80)
    {
        script = sub_8087370(a3);
        if (script)
        {
            *a4 = sub_8087480(script);
            sUnknown_03000E10[a1] = 0x81;
            if (a3->b)
            {
                c1_link_related_func_set(sub_80870F8);
                sub_8087530(script);
            }
            return;
        }
        if (sub_8086CE0(0x83) == 1)
        {
            sUnknown_03000E10[a1] = 0x81;
            if (a3->b)
            {
                c1_link_related_func_set(sub_80870F8);
                sub_8087584();
            }
            return;
        }
        switch (a2)
        {
        case 24:
            if (sub_8087358(a3))
            {
                sUnknown_03000E10[a1] = 0x81;
                if (a3->b)
                {
                    c1_link_related_func_set(sub_80870F8);
                    sub_808751C();
                }
            }
            break;
        case 18:
            if (sub_8087388(a3) == TRUE)
            {
                sUnknown_03000E10[a1] = 0x81;
                if (a3->b)
                {
                    c1_link_related_func_set(sub_80870F8);
                    sub_808754C();
                }
            }
            break;
        case 25:
            script = sub_80873B4(a3);
            if (script)
            {
                sUnknown_03000E10[a1] = 0x81;
                if (a3->b)
                {
                    c1_link_related_func_set(sub_80870F8);
                    sub_8087568(script);
                }
            }
            break;
        case 27:
            if (sub_8087340(a3))
            {
                sUnknown_03000E10[a1] = 0x81;
                if (a3->b)
                {
                    c1_link_related_func_set(sub_808711C);
                    sub_8087510();
                }
            }
            break;
        case 28:
            if (sub_8087340(a3))
            {
                sUnknown_03000E10[a1] = 0x81;
                if (a3->b)
                {
                    c1_link_related_func_set(sub_8087140);
                    sub_8087510();
                }
            }
            break;
        }
    }

    switch (a2)
    {
    case 23:
        sUnknown_03000E10[a1] = 0x83;
        break;
    case 22:
        sUnknown_03000E10[a1] = 0x82;
        break;
    case 26:
        sUnknown_03000E10[a1] = 0x80;
        if (a3->b)
            c1_link_related_func_set(sub_80870B0);
        break;
    case 29:
        if (sUnknown_03000E10[a1] == 0x82)
            sUnknown_03000E10[a1] = 0x81;
        break;
    }
}

static void sub_8086F38(u16 *a1, s32 a2)
{
    struct UnkStruct_8054FF8 st;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        u8 v5 = a1[i];
        u16 v8 = 0;
        sub_80872D8(i, a2, &st);
        sub_8086D18(i, v5, &st, &v8);
        if (sUnknown_03000E10[i] == 0x80)
            v8 = sub_8087068(v5);
        sub_808796C(i, v8);
    }
}

static void sub_8086FA0(u16 a1)
{
    if (a1 >= 17 && a1 < 30)
        gUnknown_03005DA8 = a1;
    else
        gUnknown_03005DA8 = 17;

    if (gWirelessCommType != 0
        && sub_8087690() > 1
        && is_c1_link_related_active() == TRUE
        && sub_8009F3C() == TRUE)
    {
        switch (a1)
        {
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 24:
        case 25:
            gUnknown_03005DA8 = 0;
            break;
        }
    }
}

static u16 sub_808700C(u32 a1)
{
    if (gMain.heldKeys & DPAD_UP)
        return 19;
    else if (gMain.heldKeys & DPAD_DOWN)
        return 18;
    else if (gMain.heldKeys & DPAD_LEFT)
        return 20;
    else if (gMain.heldKeys & DPAD_RIGHT)
        return 21;
    else if (gMain.newKeys & START_BUTTON)
        return 24;
    else if (gMain.newKeys & A_BUTTON)
        return 25;
    else
        return 17;
}

static u16 sub_8087068(u16 a1)
{
    switch (a1)
    {
    case 21:
        return 4;
    case 20:
        return 3;
    case 19:
        return 1;
    case 18:
        return 2;
    default:
        return 0;
    }
}

static void sub_808709C(u16 *a1)
{
    s32 i;
    for (i = 0; i < 4; i++)
        a1[i] = 17;
}

static u16 sub_80870B0(u32 a1)
{
    if (ScriptContext2_IsEnabled() == 1)
        return 17;
    if (sub_800B4DC() > 4)
        return 27;
    if (sub_8087690() <= 4)
        return sub_808700C(a1);
    return 28;
}

static u16 sub_80870EC(u32 a1)
{
    sub_8086C64();
    return 17;
}

static u16 sub_80870F8(u32 a1)
{
    u16 retVal;
    if (ScriptContext2_IsEnabled() == TRUE)
    {
        retVal = 17;
    }
    else
    {
        retVal = 26;
        c1_link_related_func_set(sub_80870EC);
    }
    return retVal;
}

static u16 sub_808711C(u32 a1)
{
    u16 retVal;
    if (sub_800B4DC() > 2)
    {
        retVal = 17;
    }
    else
    {
        retVal = 26;
        ScriptContext2_Disable();
        c1_link_related_func_set(sub_80870EC);
    }
    return retVal;
}

static u16 sub_8087140(u32 a1)
{
    u16 retVal;
    if (sub_8087690() > 2)
    {
        retVal = 17;
    }
    else
    {
        retVal = 26;
        ScriptContext2_Disable();
        c1_link_related_func_set(sub_80870EC);
    }
    return retVal;
}

static u16 sub_8087164(u32 a1)
{
    sub_8086C64();
    return 17;
}

static u16 sub_8087170(u32 linkPlayerId)
{
    if (sUnknown_03000E10[linkPlayerId] == 0x82)
    {
        if (gMain.newKeys & B_BUTTON)
        {
            c1_link_related_func_set(sub_8087164);
            return 29;
        }
        else
        {
            return 17;
        }
    }
    else
    {
        sub_8086C64();
        return 17;
    }
}

static u16 sub_80871AC(u32 a1)
{
    c1_link_related_func_set(sub_8087170);
    return 22;
}

static u16 sub_80871C0(u32 a1)
{
    return 17;
}

static u16 sub_80871C4(u32 a1)
{
    if (sUnknown_03000E10[a1] != 0x83)
        sub_8086C64();
    if (sub_8086CA8(0x83) == TRUE)
    {
        ScriptContext1_SetupScript(EventScript_277513);
        c1_link_related_func_set(sub_80871C0);
    }
    return 17;
}

static u16 sub_80871FC(u32 a1)
{
    c1_link_related_func_set(sub_80871C4);
    return 23;
}

static u16 sub_8087210(u32 a1)
{
    return 17;
}

u32 sub_8087214(void)
{
    if (sub_8086CE0(0x83) == TRUE)
        return 2;
    if (sUnknown_03000E14 == sub_8087170 && sUnknown_03000E10[gUnknown_03005DB4] != 0x82)
        return 0;
    if (sUnknown_03000E14 == sub_8087164 && sUnknown_03000E10[gUnknown_03005DB4] == 0x81)
        return 2;
    if (sub_8086CA8(0x82) != 0)
        return 1;
    return 0;
}

bool32 sub_808727C(void)
{
    return sub_8086CE0(0x83);
}

u16 sub_8087288(void)
{
    c1_link_related_func_set(sub_80871AC);
    return 0;
}

u16 sub_808729C(void)
{
    c1_link_related_func_set(sub_80870F8);
    return 0;
}

u16 sub_80872B0(void)
{
    c1_link_related_func_set(sub_80871FC);
    return 0;
}

u16 sub_80872C4(void)
{
    c1_link_related_func_set(sub_8087210);
    return 0;
}

static void sub_80872D8(s32 linkPlayerId, s32 a2, struct UnkStruct_8054FF8 *a3)
{
    s16 x, y;

    a3->a = linkPlayerId;
    a3->b = (linkPlayerId == a2) ? 1 : 0;
    a3->c = gLinkPlayerEventObjects[linkPlayerId].mode;
    a3->d = sub_80878A0(linkPlayerId);
    sub_8087878(linkPlayerId, &x, &y);
    a3->sub.x = x;
    a3->sub.y = y;
    a3->sub.height = sub_80878C0(linkPlayerId);
    a3->field_C = MapGridGetMetatileBehaviorAt(x, y);
}

static bool32 sub_8087340(struct UnkStruct_8054FF8 *a1)
{
    u8 v1 = a1->c;
    if (v1 == 2 || v1 == 0)
        return TRUE;
    else
        return FALSE;
}

static bool32 sub_8087358(struct UnkStruct_8054FF8 *a1)
{
    u8 v1 = a1->c;
    if (v1 == 2 || v1 == 0)
        return TRUE;
    else
        return FALSE;
}

static u8 *sub_8087370(struct UnkStruct_8054FF8 *a1)
{
    if (a1->c != 2)
        return 0;
    return GetCoordEventScriptAtMapPosition(&a1->sub);
}

static bool32 sub_8087388(struct UnkStruct_8054FF8 *a1)
{
    if (a1->c != 2 && a1->c != 0)
        return FALSE;
    else if (!MetatileBehavior_IsSouthArrowWarp(a1->field_C))
        return FALSE;
    else if (a1->d != 1)
        return FALSE;
    else
        return TRUE;
}

static const u8 *sub_80873B4(struct UnkStruct_8054FF8 *a1)
{
    struct MapPosition unkStruct;
    u8 linkPlayerId;

    if (a1->c && a1->c != 2)
        return 0;

    unkStruct = a1->sub;
    unkStruct.x += gDirectionToVectors[a1->d].x;
    unkStruct.y += gDirectionToVectors[a1->d].y;
    unkStruct.height = 0;
    linkPlayerId = GetLinkPlayerIdAt(unkStruct.x, unkStruct.y);

    if (linkPlayerId != 4)
    {
        if (!a1->b)
            return EventScript_TradeRoom_TooBusyToNotice;
        else if (sUnknown_03000E10[linkPlayerId] != 0x80)
            return EventScript_TradeRoom_TooBusyToNotice;
        else if (!sub_80B39D4(linkPlayerId))
            return EventScript_TradeRoom_ReadTrainerCard1;
        else
            return EventScript_TradeRoom_ReadTrainerCard2;
    }

    return GetInteractedLinkPlayerScript(&unkStruct, a1->field_C, a1->d);
}

static u16 sub_8087480(const u8 *script)
{
    if (script == gUnknown_08277388)
        return 10;
    else if (script == gUnknown_082773A3)
        return 9;
    else if (script == gUnknown_082773BE)
        return 10;
    else if (script == gUnknown_082773D9)
        return 9;
    else if (script == gUnknown_0827741D)
        return 10;
    else if (script == gUnknown_08277432)
        return 9;
    else if (script == gUnknown_08277447)
        return 10;
    else if (script == gUnknown_0827745C)
        return 9;
    else if (script == gUnknown_08277374)
        return 10;
    else if (script == gUnknown_0827737E)
        return 9;
    else if (script == gUnknown_082773F5)
        return 10;
    else if (script == gUnknown_082773FF)
        return 9;
    else
        return 0;
}

static void sub_8087510(void)
{
    ScriptContext2_Enable();
}

static void sub_808751C(void)
{
    PlaySE(SE_WIN_OPEN);
    ShowStartMenu();
    ScriptContext2_Enable();
}

static void sub_8087530(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext1_SetupScript(script);
    ScriptContext2_Enable();
}

static void sub_808754C(void)
{
    PlaySE(SE_WIN_OPEN);
    ScriptContext1_SetupScript(gUnknown_082774EF);
    ScriptContext2_Enable();
}

static void sub_8087568(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext1_SetupScript(script);
    ScriptContext2_Enable();
}

static void sub_8087584(void)
{
    ScriptContext1_SetupScript(gUnknown_08277509);
    ScriptContext2_Enable();
}

bool32 sub_8087598(void)
{
    if (!is_c1_link_related_active())
        return 0;
    if (sub_800B4DC() >= 3)
        sUnknown_03000E18 = 1;
    else
        sUnknown_03000E18 = 0;
    return sUnknown_03000E18;
}

bool32 sub_80875C8(void)
{
    u8 temp;

    if (sub_800B4DC() < 2)
        return FALSE;
    else if (is_c1_link_related_active() != TRUE)
        return FALSE;
    else if (sub_8009F3C() != TRUE)
        return FALSE;
    else if (sUnknown_03000E14 == sub_808711C)
        return TRUE;
    else if (sUnknown_03000E14 != sub_80870F8)
        return FALSE;

    temp = sUnknown_03000E18;
    sUnknown_03000E18 = 0;

    if (temp == TRUE)
        return TRUE;
    else if (gPaletteFade.active && gPaletteFade.softwareFadeFinishing)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8087634(void)
{
    if (sub_8087690() < 2)
        return FALSE;
    else if (is_c1_link_related_active() != TRUE)
        return FALSE;
    else if (sub_8009F3C() != TRUE)
        return FALSE;
    else if (sUnknown_03000E14 == sub_8087140)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_808766C(void)
{
    if (gWirelessCommType != 0)
        return FALSE;
    else if (!sub_8009F3C())
        return FALSE;
    else
        return TRUE;
}

static u32 sub_8087690(void)
{
    if (gWirelessCommType != 0)
        return gUnknown_03005000.unk_9e8.unk_232;
    else
        return gLink.sendQueue.count;
}

static void ZeroLinkPlayerEventObject(struct LinkPlayerEventObject *linkPlayerEventObj)
{
    memset(linkPlayerEventObj, 0, sizeof(struct LinkPlayerEventObject));
}

void ClearLinkPlayerEventObjects(void)
{
    memset(gLinkPlayerEventObjects, 0, sizeof(gLinkPlayerEventObjects));
}

static void ZeroEventObject(struct EventObject *eventObj)
{
    memset(eventObj, 0, sizeof(struct EventObject));
}

static void SpawnLinkPlayerEventObject(u8 linkPlayerId, s16 x, s16 y, u8 a4)
{
    u8 eventObjId = GetFirstInactiveEventObjectId();
    struct LinkPlayerEventObject *linkPlayerEventObj = &gLinkPlayerEventObjects[linkPlayerId];
    struct EventObject *eventObj = &gEventObjects[eventObjId];

    ZeroLinkPlayerEventObject(linkPlayerEventObj);
    ZeroEventObject(eventObj);

    linkPlayerEventObj->active = 1;
    linkPlayerEventObj->linkPlayerId = linkPlayerId;
    linkPlayerEventObj->eventObjId = eventObjId;
    linkPlayerEventObj->mode = 0;

    eventObj->active = 1;
    eventObj->singleMovementActive = a4;
    eventObj->range.as_byte = 2;
    eventObj->spriteId = 64;

    InitLinkPlayerEventObjectPos(eventObj, x, y);
}

static void InitLinkPlayerEventObjectPos(struct EventObject *eventObj, s16 x, s16 y)
{
    eventObj->currentCoords.x = x;
    eventObj->currentCoords.y = y;
    eventObj->previousCoords.x = x;
    eventObj->previousCoords.y = y;
    sub_8093038(x, y, &eventObj->initialCoords.x, &eventObj->initialCoords.y);
    eventObj->initialCoords.x += 8;
    EventObjectUpdateZCoord(eventObj);
}

static void sub_80877DC(u8 linkPlayerId, u8 a2)
{
    if (gLinkPlayerEventObjects[linkPlayerId].active)
    {
        u8 eventObjId = gLinkPlayerEventObjects[linkPlayerId].eventObjId;
        struct EventObject *eventObj = &gEventObjects[eventObjId];
        eventObj->range.as_byte = a2;
    }
}

static void sub_808780C(u8 linkPlayerId)
{
    struct LinkPlayerEventObject *linkPlayerEventObj = &gLinkPlayerEventObjects[linkPlayerId];
    u8 eventObjId = linkPlayerEventObj->eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    if (eventObj->spriteId != MAX_SPRITES)
        DestroySprite(&gSprites[eventObj->spriteId]);
    linkPlayerEventObj->active = 0;
    eventObj->active = 0;
}

static u8 sub_8087858(u8 linkPlayerId)
{
    u8 eventObjId = gLinkPlayerEventObjects[linkPlayerId].eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    return eventObj->spriteId;
}

static void sub_8087878(u8 linkPlayerId, u16 *x, u16 *y)
{
    u8 eventObjId = gLinkPlayerEventObjects[linkPlayerId].eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    *x = eventObj->currentCoords.x;
    *y = eventObj->currentCoords.y;
}

static u8 sub_80878A0(u8 linkPlayerId)
{
    u8 eventObjId = gLinkPlayerEventObjects[linkPlayerId].eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    return eventObj->range.as_byte;
}

static u8 sub_80878C0(u8 linkPlayerId)
{
    u8 eventObjId = gLinkPlayerEventObjects[linkPlayerId].eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    return eventObj->currentElevation;
}

static s32 sub_80878E4(u8 linkPlayerId)
{
    u8 eventObjId = gLinkPlayerEventObjects[linkPlayerId].eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    return 16 - (s8)eventObj->directionSequenceIndex;
}

static u8 GetLinkPlayerIdAt(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < 4; i++)
    {
        if (gLinkPlayerEventObjects[i].active
         && (gLinkPlayerEventObjects[i].mode == 0 || gLinkPlayerEventObjects[i].mode == 2))
        {
            struct EventObject *eventObj = &gEventObjects[gLinkPlayerEventObjects[i].eventObjId];
            if (eventObj->currentCoords.x == x && eventObj->currentCoords.y == y)
                return i;
        }
    }
    return 4;
}

static void sub_808796C(u8 linkPlayerId, u8 a2)
{
    struct LinkPlayerEventObject *linkPlayerEventObj = &gLinkPlayerEventObjects[linkPlayerId];
    u8 eventObjId = linkPlayerEventObj->eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];

    if (linkPlayerEventObj->active)
    {
        if (a2 > 10)
            eventObj->triggerGroundEffectsOnMove = 1;
        else
            gUnknown_08339E00[gUnknown_08339DC8[linkPlayerEventObj->mode](linkPlayerEventObj, eventObj, a2)](linkPlayerEventObj, eventObj);
    }
}

static u8 sub_80879D8(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj, u8 a3)
{
    return gUnknown_08339DD4[a3](linkPlayerEventObj, eventObj, a3);
}

static u8 sub_80879F8(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj, u8 a3)
{
    return 1;
}

static u8 sub_80879FC(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj, u8 a3)
{
    return gUnknown_08339DD4[a3](linkPlayerEventObj, eventObj, a3);
}

static u8 sub_8087A1C(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj, u8 a3)
{
    return 0;
}

static u8 sub_8087A20(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj, u8 a3)
{
    s16 x, y;

    eventObj->range.as_byte = npc_something3(a3, eventObj->range.as_byte);
    EventObjectMoveDestCoords(eventObj, eventObj->range.as_byte, &x, &y);

    if (LinkPlayerDetectCollision(linkPlayerEventObj->eventObjId, eventObj->range.as_byte, x, y))
    {
        return 0;
    }
    else
    {
        eventObj->directionSequenceIndex = 16;
        ShiftEventObjectCoords(eventObj, x, y);
        EventObjectUpdateZCoord(eventObj);
        return 1;
    }
}

static u8 sub_8087A88(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj, u8 a3)
{
    eventObj->range.as_byte = npc_something3(a3, eventObj->range.as_byte);
    return 0;
}

static void sub_8087AA0(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj)
{
    linkPlayerEventObj->mode = 0;
}

static void sub_8087AA8(struct LinkPlayerEventObject *linkPlayerEventObj, struct EventObject *eventObj)
{
    eventObj->directionSequenceIndex--;
    linkPlayerEventObj->mode = 1;
    MoveCoords(eventObj->range.as_byte, &eventObj->initialCoords.x, &eventObj->initialCoords.y);
    if (!eventObj->directionSequenceIndex)
    {
        ShiftStillEventObjectCoords(eventObj);
        linkPlayerEventObj->mode = 2;
    }
}

static u8 npc_something3(u8 a1, u8 a2)
{
    switch (a1 - 1)
    {
    case 0:
    case 6:
        return 2;
    case 1:
    case 7:
        return 1;
    case 2:
    case 8:
        return 3;
    case 3:
    case 9:
        return 4;
    }
    return a2;
}

static u8 LinkPlayerDetectCollision(u8 selfEventObjId, u8 a2, s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < 16; i++)
    {
        if (i != selfEventObjId)
        {
            if ((gEventObjects[i].currentCoords.x == x && gEventObjects[i].currentCoords.y == y)
             || (gEventObjects[i].previousCoords.x == x && gEventObjects[i].previousCoords.y == y))
            {
                return 1;
            }
        }
    }
    return MapGridIsImpassableAt(x, y);
}

static void CreateLinkPlayerSprite(u8 linkPlayerId, u8 gameVersion)
{
    struct LinkPlayerEventObject *linkPlayerEventObj = &gLinkPlayerEventObjects[linkPlayerId];
    u8 eventObjId = linkPlayerEventObj->eventObjId;
    struct EventObject *eventObj = &gEventObjects[eventObjId];
    struct Sprite *sprite;

    if (linkPlayerEventObj->active)
    {
        switch (gameVersion)
        {
        case VERSION_FIRE_RED:
        case VERSION_LEAF_GREEN:
            eventObj->spriteId = AddPseudoEventObject(GetFRLGAvatarGraphicsIdByGender(eventObj->singleMovementActive), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_RUBY:
        case VERSION_SAPPHIRE:
            eventObj->spriteId = AddPseudoEventObject(GetRSAvatarGraphicsIdByGender(eventObj->singleMovementActive), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_EMERALD:
            eventObj->spriteId = AddPseudoEventObject(GetRivalAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, eventObj->singleMovementActive), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        }

        sprite = &gSprites[eventObj->spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = linkPlayerId;
        eventObj->triggerGroundEffectsOnMove = 0;
    }
}

static void SpriteCB_LinkPlayer(struct Sprite *sprite)
{
    struct LinkPlayerEventObject *linkPlayerEventObj = &gLinkPlayerEventObjects[sprite->data[0]];
    struct EventObject *eventObj = &gEventObjects[linkPlayerEventObj->eventObjId];
    sprite->pos1.x = eventObj->initialCoords.x;
    sprite->pos1.y = eventObj->initialCoords.y;
    SetObjectSubpriorityByZCoord(eventObj->previousElevation, sprite, 1);
    sprite->oam.priority = ZCoordToPriority(eventObj->previousElevation);

    if (!linkPlayerEventObj->mode)
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(eventObj->range.as_byte));
    else
        StartSpriteAnimIfDifferent(sprite, GetMoveDirectionAnimNum(eventObj->range.as_byte));

    UpdateEventObjectSpriteVisibility(sprite, 0);
    if (eventObj->triggerGroundEffectsOnMove)
    {
        sprite->invisible = ((sprite->data[7] & 4) >> 2);
        sprite->data[7]++;
    }
}
