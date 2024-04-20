#include "global.h"
#include "overworld.h"
#include "battle_pyramid.h"
#include "battle_setup.h"
#include "berry.h"
#include "bg.h"
#include "cable_club.h"
#include "clock.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_special_scene.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "gpu_regs.h"
#include "heal_location.h"
#include "io_reg.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "map_name_popup.h"
#include "match_call.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "mirage_tower.h"
#include "money.h"
#include "new_game.h"
#include "palette.h"
#include "play_time.h"
#include "random.h"
#include "roamer.h"
#include "rotating_gate.h"
#include "rtc.h"
#include "safari_zone.h"
#include "save.h"
#include "save_location.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "secret_base.h"
#include "sound.h"
#include "start_menu.h"
#include "task.h"
#include "tileset_anims.h"
#include "time_events.h"
#include "trainer_hill.h"
#include "trainer_pokemon_sprites.h"
#include "tv.h"
#include "scanline_effect.h"
#include "wild_encounter.h"
#include "vs_seeker.h"
#include "frontier_util.h"
#include "constants/abilities.h"
#include "constants/layouts.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct CableClubPlayer
{
    u8 playerId;
    u8 isLocalPlayer;
    u8 movementMode;
    u8 facing;
    struct MapPosition pos;
    u16 metatileBehavior;
};

#define PLAYER_LINK_STATE_IDLE 0x80
#define PLAYER_LINK_STATE_BUSY 0x81
#define PLAYER_LINK_STATE_READY 0x82
#define PLAYER_LINK_STATE_EXITING_ROOM 0x83

#define FACING_NONE 0
#define FACING_UP 1
#define FACING_DOWN 2
#define FACING_LEFT 3
#define FACING_RIGHT 4
#define FACING_FORCED_UP 7
#define FACING_FORCED_DOWN 8
#define FACING_FORCED_LEFT 9
#define FACING_FORCED_RIGHT 10

extern const struct MapLayout *const gMapLayouts[];
extern const struct MapHeader *const *const gMapGroups[];

static void Overworld_ResetStateAfterWhiteOut(void);
static void CB2_ReturnToFieldLocal(void);
static void CB2_ReturnToFieldLink(void);
static void CB2_LoadMapOnReturnToFieldCableClub(void);
static void CB2_LoadMap2(void);
static void VBlankCB_Field(void);
static void SpriteCB_LinkPlayer(struct Sprite *);
static void ChooseAmbientCrySpecies(void);
static void DoMapLoadLoop(u8 *);
static bool32 LoadMapInStepsLocal(u8 *, bool32);
static bool32 LoadMapInStepsLink(u8 *);
static bool32 ReturnToFieldLocal(u8 *);
static bool32 ReturnToFieldLink(u8 *);
static void InitObjectEventsLink(void);
static void InitObjectEventsLocal(void);
static void InitOverworldGraphicsRegisters(void);
static u8 GetSpriteForLinkedPlayer(u8);
static u16 KeyInterCB_SendNothing(u32);
static void ResetMirageTowerAndSaveBlockPtrs(void);
static void ResetScreenForMapLoad(void);
static void OffsetCameraFocusByLinkPlayerId(void);
static void SpawnLinkPlayers(void);
static void SetCameraToTrackGuestPlayer(void);
static void ResumeMap(bool32);
static void SetCameraToTrackPlayer(void);
static void InitObjectEventsReturnToField(void);
static void InitViewGraphics(void);
static void SetCameraToTrackGuestPlayer_2(void);
static void CreateLinkPlayerSprites(void);
static void ClearAllPlayerKeys(void);
static void ResetAllPlayerLinkStates(void);
static void UpdateHeldKeyCode(u16);
static void UpdateAllLinkPlayers(u16 *, s32);
static u8 FlipVerticalAndClearForced(u8, u8);
static u8 LinkPlayerGetCollision(u8, u8, s16, s16);
static void CreateLinkPlayerSprite(u8, u8);
static void GetLinkPlayerCoords(u8, s16 *, s16 *);
static u8 GetLinkPlayerFacingDirection(u8);
static u8 GetLinkPlayerElevation(u8);
static u8 GetLinkPlayerIdAt(s16, s16);
static void SetPlayerFacingDirection(u8, u8);
static void ZeroObjectEvent(struct ObjectEvent *);
static void SpawnLinkPlayerObjectEvent(u8, s16, s16, u8);
static void InitLinkPlayerObjectEventPos(struct ObjectEvent *, s16, s16);
static u8 GetSpriteForLinkedPlayer(u8);
static void RunTerminateLinkScript(void);
static u32 GetLinkSendQueueLength(void);
static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *);
static const u8 *TryInteractWithPlayer(struct CableClubPlayer *);
static u16 GetDirectionForEventScript(const u8 *);
static void InitLinkPlayerQueueScript(void);
static void InitLinkRoomStartMenuScript(void);
static void RunInteractLocalPlayerScript(const u8 *);
static void RunConfirmLeaveCableClubScript(void);
static void InitMenuBasedScript(const u8 *);
static void LoadCableClubPlayer(s32, s32, struct CableClubPlayer *);
static bool32 IsCableClubPlayerUnfrozen(struct CableClubPlayer *);
static bool32 CanCableClubPlayerPressStart(struct CableClubPlayer *);
static const u8 *TryGetTileEventScript(struct CableClubPlayer *);
static bool32 PlayerIsAtSouthExit(struct CableClubPlayer *);
static const u8 *TryInteractWithPlayer(struct CableClubPlayer *);
static u16 KeyInterCB_DeferToRecvQueue(u32);
static u16 KeyInterCB_DeferToSendQueue(u32);
static void ResetPlayerHeldKeys(u16 *);
static u16 KeyInterCB_SelfIdle(u32);
static u16 KeyInterCB_DeferToEventScript(u32);
static u16 GetDirectionForDpadKey(u16);
static void CB1_OverworldLink(void);
static void SetKeyInterceptCallback(u16 (*func)(u32));
static void SetFieldVBlankCallback(void);
static void FieldClearVBlankHBlankCallbacks(void);
static void TransitionMapMusic(void);
static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *, u16, u8);
static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *, u8, u16, u8);
static u16 GetCenterScreenMetatileBehavior(void);

static void *sUnusedOverworldCallback;
static u8 sPlayerLinkStates[MAX_LINK_PLAYERS];
// This callback is called with a player's key code. It then returns an
// adjusted key code, effectively intercepting the input before anything
// can process it.
static u16 (*sPlayerKeyInterceptCallback)(u32);
static bool8 sReceivingFromLink;
static u8 sRfuKeepAliveTimer;

u16 *gOverworldTilemapBuffer_Bg2;
u16 *gOverworldTilemapBuffer_Bg1;
u16 *gOverworldTilemapBuffer_Bg3;
u16 gHeldKeyCodeToSend;
void (*gFieldCallback)(void);
bool8 (*gFieldCallback2)(void);
u8 gLocalLinkPlayerId; // This is our player id in a multiplayer mode.
u8 gFieldLinkPlayerCount;

EWRAM_DATA static u8 sObjectEventLoadFlag = 0;
EWRAM_DATA struct WarpData gLastUsedWarp = {0};
EWRAM_DATA static struct WarpData sWarpDestination = {0};  // new warp position
EWRAM_DATA static struct WarpData sFixedDiveWarp = {0};
EWRAM_DATA static struct WarpData sFixedHoleWarp = {0};
EWRAM_DATA static u16 sLastMapSectionId = 0;
EWRAM_DATA static struct InitialPlayerAvatarState sInitialPlayerAvatarState = {0};
EWRAM_DATA static u16 sAmbientCrySpecies = 0;
EWRAM_DATA static bool8 sIsAmbientCryWaterMon = FALSE;
EWRAM_DATA struct LinkPlayerObjectEvent gLinkPlayerObjectEvents[4] = {0};

static const struct WarpData sDummyWarpData =
{
    .mapGroup = MAP_GROUP(UNDEFINED),
    .mapNum = MAP_NUM(UNDEFINED),
    .warpId = WARP_ID_NONE,
    .x = -1,
    .y = -1,
};

static const u32 sUnusedData[] =
{
    1200, 3600, 1200, 2400, 50, 80, -44, 44
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

static const struct BgTemplate sOverworldBgTemplates[] =
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
    &REG_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0,
};

static u8 MovementEventModeCB_Normal(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 MovementEventModeCB_Ignored(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 MovementEventModeCB_Scripted(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);

static u8 (*const sLinkPlayerMovementModes[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8) =
{
    [MOVEMENT_MODE_FREE]     = MovementEventModeCB_Normal,
    [MOVEMENT_MODE_FROZEN]   = MovementEventModeCB_Ignored,
    [MOVEMENT_MODE_SCRIPTED] = MovementEventModeCB_Scripted,
};

static u8 FacingHandler_DoNothing(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 FacingHandler_DpadMovement(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 FacingHandler_ForcedFacingChange(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);

// These handlers return TRUE if the movement was scripted and successful, and FALSE otherwise.
static bool8 (*const sLinkPlayerFacingHandlers[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8) =
{
    FacingHandler_DoNothing,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DoNothing,
    FacingHandler_DoNothing,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
};

static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *, struct ObjectEvent *);
static void MovementStatusHandler_TryAdvanceScript(struct LinkPlayerObjectEvent *, struct ObjectEvent *);

// These handlers are run after an attempted movement.
static void (*const sMovementStatusHandler[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *) =
{
    // FALSE:
    MovementStatusHandler_EnterFreeMode,
    // TRUE:
    MovementStatusHandler_TryAdvanceScript,
};

// code
void DoWhiteOut(void)
{
    RunScriptImmediately(EventScript_WhiteOut);
    if (B_WHITEOUT_MONEY == GEN_3)
        SetMoney(&gSaveBlock1Ptr->money, GetMoney(&gSaveBlock1Ptr->money) / 2);
    HealPlayerParty();
    Overworld_ResetStateAfterWhiteOut();
    SetWarpDestinationToLastHealLocation();
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
    RunScriptImmediately(EventScript_ResetMrBriney);
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

#if B_RESET_FLAGS_VARS_AFTER_WHITEOUT  == TRUE
void Overworld_ResetBattleFlagsAndVars(void)
{
    #if B_VAR_STARTING_STATUS != 0
        VarSet(B_VAR_STARTING_STATUS, 0);
    #endif

    #if B_VAR_STARTING_STATUS_TIMER != 0
        VarSet(B_VAR_STARTING_STATUS_TIMER, 0);
    #endif

    #if B_VAR_WILD_AI_FLAGS != 0
        VarSet(B_VAR_WILD_AI_FLAGS,0);
    #endif

    FlagClear(B_FLAG_INVERSE_BATTLE);
    FlagClear(B_FLAG_FORCE_DOUBLE_WILD);
    FlagClear(B_SMART_WILD_AI_FLAG);
    FlagClear(B_FLAG_NO_BAG_USE);
    FlagClear(B_FLAG_NO_CATCHING);
    FlagClear(B_FLAG_DYNAMAX_BATTLE);
    FlagClear(B_FLAG_SKY_BATTLE);
}
#endif

static void Overworld_ResetStateAfterWhiteOut(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
    if (B_RESET_FLAGS_VARS_AFTER_WHITEOUT == TRUE)
        Overworld_ResetBattleFlagsAndVars();
    // If you were defeated by Kyogre/Groudon and the step counter has
    // maxed out, end the abnormal weather.
    if (VarGet(VAR_SHOULD_END_ABNORMAL_WEATHER) == 1)
    {
        VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 0);
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_NONE);
    }
}

static void UpdateMiscOverworldStates(void)
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

void LoadObjEventTemplatesFromHeader(void)
{
    // Clear map object templates
    CpuFill32(0, gSaveBlock1Ptr->objectEventTemplates, sizeof(gSaveBlock1Ptr->objectEventTemplates));

    // Copy map header events to save block
    CpuCopy32(gMapHeader.events->objectEvents,
              gSaveBlock1Ptr->objectEventTemplates,
              gMapHeader.events->objectEventCount * sizeof(struct ObjectEventTemplate));
}

void LoadSaveblockObjEventScripts(void)
{
    const struct ObjectEventTemplate *mapHeaderObjTemplates = gMapHeader.events->objectEvents;
    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;
    s32 i;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
        savObjTemplates[i].script = mapHeaderObjTemplates[i].script;
}

void SetObjEventTemplateCoords(u8 localId, s16 x, s16 y)
{
    s32 i;
    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *objectEventTemplate = &savObjTemplates[i];
        if (objectEventTemplate->localId == localId)
        {
            objectEventTemplate->x = x;
            objectEventTemplate->y = y;
            return;
        }
    }
}

void SetObjEventTemplateMovementType(u8 localId, u8 movementType)
{
    s32 i;

    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;
    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *objectEventTemplate = &savObjTemplates[i];
        if (objectEventTemplate->localId == localId)
        {
            objectEventTemplate->movementType = movementType;
            return;
        }
    }
}

static void InitMapView(void)
{
    ResetFieldCamera();
    CopyMapTilesetsToVram(gMapHeader.mapLayout);
    LoadMapTilesetPalettes(gMapHeader.mapLayout);
    DrawWholeMapView();
    InitTilesetAnimations();
}

const struct MapLayout *GetMapLayout(u16 mapLayoutId)
{
    return gMapLayouts[mapLayoutId - 1];
}

void ApplyCurrentWarp(void)
{
    gLastUsedWarp = gSaveBlock1Ptr->location;
    gSaveBlock1Ptr->location = sWarpDestination;
    sFixedDiveWarp = sDummyWarpData;
    sFixedHoleWarp = sDummyWarpData;
}

static void ClearDiveAndHoleWarps(void)
{
    sFixedDiveWarp = sDummyWarpData;
    sFixedHoleWarp = sDummyWarpData;
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
    if (warp->mapGroup != (s8)MAP_GROUP(UNDEFINED))
        return FALSE;
    else if (warp->mapNum != (s8)MAP_NUM(UNDEFINED))
        return FALSE;
    else if (warp->warpId != WARP_ID_NONE)
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
    gMapHeader.mapLayout = GetMapLayout(gMapHeader.mapLayoutId);
}

static void LoadSaveblockMapHeader(void)
{
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gMapHeader.mapLayout = GetMapLayout(gMapHeader.mapLayoutId);
}

static void SetPlayerCoordsFromWarp(void)
{
    if (gSaveBlock1Ptr->location.warpId >= 0 && gSaveBlock1Ptr->location.warpId < gMapHeader.events->warpCount)
    {
        // warpId is a valid warp for this map, use the coords of that warp.
        gSaveBlock1Ptr->pos.x = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].x;
        gSaveBlock1Ptr->pos.y = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].y;
    }
    else if (gSaveBlock1Ptr->location.x >= 0 && gSaveBlock1Ptr->location.y >= 0)
    {
        // Invalid warpId given. The given coords are valid, use those instead.
        // WARP_ID_NONE is used to reach this intentionally.
        gSaveBlock1Ptr->pos.x = gSaveBlock1Ptr->location.x;
        gSaveBlock1Ptr->pos.y = gSaveBlock1Ptr->location.y;
    }
    else
    {
        // Invalid warpId and coords given. Put player in center of map.
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

void SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sWarpDestination, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToMapWarp(s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpDestination(mapGroup, mapNum, warpId, -1, -1);
}

void SetDynamicWarp(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpData(&gSaveBlock1Ptr->dynamicWarp, mapGroup, mapNum, warpId, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
}

void SetDynamicWarpWithCoords(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->dynamicWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToDynamicWarp(u8 unusedWarpId)
{
    sWarpDestination = gSaveBlock1Ptr->dynamicWarp;
}

void SetWarpDestinationToHealLocation(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpDestination(healLocation->group, healLocation->map, WARP_ID_NONE, healLocation->x, healLocation->y);
}

void SetWarpDestinationToLastHealLocation(void)
{
    sWarpDestination = gSaveBlock1Ptr->lastHealLocation;
}

void SetLastHealLocationWarp(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpData(&gSaveBlock1Ptr->lastHealLocation, healLocation->group, healLocation->map, WARP_ID_NONE, healLocation->x, healLocation->y);
}

void UpdateEscapeWarp(s16 x, s16 y)
{
    u8 currMapType = GetCurrentMapType();
    u8 destMapType = GetMapTypeByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
    if (IsMapTypeOutdoors(currMapType) && IsMapTypeOutdoors(destMapType) != TRUE)
        SetEscapeWarp(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE, x - MAP_OFFSET, y - MAP_OFFSET + 1);
}

void SetEscapeWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->escapeWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToEscapeWarp(void)
{
    sWarpDestination = gSaveBlock1Ptr->escapeWarp;
}

void SetFixedDiveWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sFixedDiveWarp, mapGroup, mapNum, warpId, x, y);
}

static void SetWarpDestinationToDiveWarp(void)
{
    sWarpDestination = sFixedDiveWarp;
}

void SetFixedHoleWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sFixedHoleWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToFixedHoleWarp(s16 x, s16 y)
{
    if (IsDummyWarp(&sFixedHoleWarp) == TRUE)
        sWarpDestination = gLastUsedWarp;
    else
        SetWarpDestination(sFixedHoleWarp.mapGroup, sFixedHoleWarp.mapNum, WARP_ID_NONE, x, y);
}

static void SetWarpDestinationToContinueGameWarp(void)
{
    sWarpDestination = gSaveBlock1Ptr->continueGameWarp;
}

void SetContinueGameWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->continueGameWarp, mapGroup, mapNum, warpId, x, y);
}

void SetContinueGameWarpToHealLocation(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpData(&gSaveBlock1Ptr->continueGameWarp, healLocation->group, healLocation->map, WARP_ID_NONE, healLocation->x, healLocation->y);
}

void SetContinueGameWarpToDynamicWarp(int unused)
{
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->dynamicWarp;
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
        SetWarpDestination(connection->mapGroup, connection->mapNum, WARP_ID_NONE, x, y);
    }
    else
    {
        RunOnDiveWarpMapScript();
        if (IsDummyWarp(&sFixedDiveWarp))
            return FALSE;
        SetWarpDestinationToDiveWarp();
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

void LoadMapFromCameraTransition(u8 mapGroup, u8 mapNum)
{
    s32 paletteIndex;

    SetWarpDestination(mapGroup, mapNum, WARP_ID_NONE, -1, -1);

    // Dont transition map music between BF Outside West/East
    if (gMapHeader.regionMapSectionId != MAPSEC_BATTLE_FRONTIER)
        TransitionMapMusic();

    ApplyCurrentWarp();
    LoadCurrentMapData();
    LoadObjEventTemplatesFromHeader();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    RestartWildEncounterImmunitySteps();
#if FREE_MATCH_CALL == FALSE
    TryUpdateRandomTrainerRematches(mapGroup, mapNum);
#endif //FREE_MATCH_CALL

if (I_VS_SEEKER_CHARGING != 0)
    MapResetTrainerRematches(mapGroup, mapNum);

    DoTimeBasedEvents();
    SetSavedWeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    RunOnTransitionMapScript();
    InitMap();
    CopySecondaryTilesetToVramUsingHeap(gMapHeader.mapLayout);
    LoadSecondaryTilesetPalette(gMapHeader.mapLayout);

    for (paletteIndex = NUM_PALS_IN_PRIMARY; paletteIndex < NUM_PALS_TOTAL; paletteIndex++)
        ApplyWeatherColorMapToPal(paletteIndex);

    InitSecondaryTilesetAnimation();
    UpdateLocationHistoryForRoamer();
    RoamerMove();
    DoCurrentWeather();
    ResetFieldTasksArgs();
    RunOnResumeMapScript();

    if (OW_HIDE_REPEAT_MAP_POPUP)
    {
        if (gMapHeader.regionMapSectionId != sLastMapSectionId)
            ShowMapNamePopup();
    }
    else
    {
        if (gMapHeader.regionMapSectionId != MAPSEC_BATTLE_FRONTIER
         || gMapHeader.regionMapSectionId != sLastMapSectionId)
            ShowMapNamePopup();
    }
}

static void LoadMapFromWarp(bool32 a1)
{
    bool8 isOutdoors;
    bool8 isIndoors;

    LoadCurrentMapData();
    if (!(sObjectEventLoadFlag & SKIP_OBJECT_EVENT_LOAD))
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            LoadBattlePyramidObjectEventTemplates();
        else if (InTrainerHill())
            LoadTrainerHillObjectEventTemplates();
        else
            LoadObjEventTemplatesFromHeader();
    }

    isOutdoors = IsMapTypeOutdoors(gMapHeader.mapType);
    isIndoors = IsMapTypeIndoors(gMapHeader.mapType);

    CheckLeftFriendsSecretBase();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    RestartWildEncounterImmunitySteps();
#if FREE_MATCH_CALL == FALSE
    TryUpdateRandomTrainerRematches(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
#endif //FREE_MATCH_CALL

if (I_VS_SEEKER_CHARGING != 0)
     MapResetTrainerRematches(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);

    if (a1 != TRUE)
        DoTimeBasedEvents();
    SetSavedWeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    if (isOutdoors)
        FlagClear(FLAG_SYS_USE_FLASH);
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    RunOnTransitionMapScript();
    UpdateLocationHistoryForRoamer();
    RoamerMoveToOtherLocationSet();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        InitBattlePyramidMap(FALSE);
    else if (InTrainerHill())
        InitTrainerHillMap();
    else
        InitMap();

    if (a1 != TRUE && isIndoors)
    {
        UpdateTVScreensOnMap(gBackupMapLayout.width, gBackupMapLayout.height);
        InitSecretBaseAppearance(TRUE);
    }
}

void ResetInitialPlayerAvatarState(void)
{
    sInitialPlayerAvatarState.direction = DIR_SOUTH;
    sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

void StoreInitialPlayerAvatarState(void)
{
    sInitialPlayerAvatarState.direction = GetPlayerFacingDirection();

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ACRO_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_SURFING;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_UNDERWATER;
    else
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

static struct InitialPlayerAvatarState *GetInitialPlayerAvatarState(void)
{
    struct InitialPlayerAvatarState playerStruct;
    u8 mapType = GetCurrentMapType();
    u16 metatileBehavior = GetCenterScreenMetatileBehavior();
    u8 transitionFlags = GetAdjustedInitialTransitionFlags(&sInitialPlayerAvatarState, metatileBehavior, mapType);
    playerStruct.transitionFlags = transitionFlags;
    playerStruct.direction = GetAdjustedInitialDirection(&sInitialPlayerAvatarState, transitionFlags, metatileBehavior, mapType);
    sInitialPlayerAvatarState = playerStruct;
    return &sInitialPlayerAvatarState;
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
    if (FlagGet(FLAG_SYS_CRUISE_MODE) && mapType == MAP_TYPE_OCEAN_ROUTE)
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
          || (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_SURFING && transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER))
        return playerStruct->direction;
    else if (MetatileBehavior_IsLadder(metatileBehavior) == TRUE)
        return playerStruct->direction;
    else
        return DIR_SOUTH;
}

static u16 GetCenterScreenMetatileBehavior(void)
{
    return MapGridGetMetatileBehaviorAt(gSaveBlock1Ptr->pos.x + MAP_OFFSET, gSaveBlock1Ptr->pos.y + MAP_OFFSET);
}

bool32 Overworld_IsBikingAllowed(void)
{
    if (!gMapHeader.allowCycling)
        return FALSE;
    else
        return TRUE;
}

// Flash level of 0 is fully bright
// Flash level of 1 is the largest flash radius
// Flash level of 7 is the smallest flash radius
// Flash level of 8 is fully black
void SetDefaultFlashLevel(void)
{
    if (!gMapHeader.cave)
        gSaveBlock1Ptr->flashLevel = 0;
    else if (FlagGet(FLAG_SYS_USE_FLASH))
        gSaveBlock1Ptr->flashLevel = 1;
    else
        gSaveBlock1Ptr->flashLevel = gMaxFlashLevel - 1;
}

void SetFlashLevel(s32 flashLevel)
{
    if (flashLevel < 0 || flashLevel > gMaxFlashLevel)
        flashLevel = 0;
    gSaveBlock1Ptr->flashLevel = flashLevel;
}

u8 GetFlashLevel(void)
{
    return gSaveBlock1Ptr->flashLevel;
}

void SetCurrentMapLayout(u16 mapLayoutId)
{
    gSaveBlock1Ptr->mapLayoutId = mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout(mapLayoutId);
}

void SetObjectEventLoadFlag(u8 flag)
{
    sObjectEventLoadFlag = flag;
}

// sObjectEventLoadFlag is read directly
static u8 UNUSED GetObjectEventLoadFlag(void)
{
    return sObjectEventLoadFlag;
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
            if (VarGet(VAR_SOOTOPOLIS_CITY_STATE) < 4)
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
    if (VarGet(VAR_SKY_PILLAR_STATE) != 1)
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
    if (VarGet(VAR_MOSSDEEP_CITY_STATE) == 0)
        return FALSE;
    else if (VarGet(VAR_MOSSDEEP_CITY_STATE) > 2)
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
        return MUS_NONE;
    else if (ShouldLegendaryMusicPlayAtLocation(warp) == TRUE)
        return MUS_ABNORMAL_WEATHER;
    else if (IsInflitratedSpaceCenter(warp) == TRUE)
        return MUS_ENCOUNTER_MAGMA;
    else if (IsInfiltratedWeatherInstitute(warp) == TRUE)
        return MUS_MT_CHIMNEY;
    else
        return Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum)->music;
}

u16 GetCurrLocationDefaultMusic(void)
{
    u16 music;

    // Play the desert music only when the sandstorm is active on Route 111.
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE111)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE111)
     && GetSavedWeather() == WEATHER_SANDSTORM)
        return MUS_DESERT;

    music = GetLocationMusic(&gSaveBlock1Ptr->location);
    if (music != MUS_ROUTE118)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1Ptr->pos.x < 24)
            return MUS_ROUTE110;
        else
            return MUS_ROUTE119;
    }
}

u16 GetWarpDestinationMusic(void)
{
    u16 music = GetLocationMusic(&sWarpDestination);
    if (music != MUS_ROUTE118)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAUVILLE_CITY)
         && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAUVILLE_CITY))
            return MUS_ROUTE110;
        else
            return MUS_ROUTE119;
    }
}

void Overworld_ResetMapMusic(void)
{
    ResetMapMusic();
}

void Overworld_PlaySpecialMapMusic(void)
{
    u16 music = GetCurrLocationDefaultMusic();

    if (music != MUS_ABNORMAL_WEATHER && music != MUS_NONE)
    {
        if (gSaveBlock1Ptr->savedMusic)
            music = gSaveBlock1Ptr->savedMusic;
        else if (GetCurrentMapType() == MAP_TYPE_UNDERWATER)
            music = MUS_UNDERWATER;
        else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
            music = MUS_SURF;
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
    gSaveBlock1Ptr->savedMusic = MUS_DUMMY;
}

static void TransitionMapMusic(void)
{
    if (FlagGet(FLAG_DONT_TRANSITION_MUSIC) != TRUE)
    {
        u16 newMusic = GetWarpDestinationMusic();
        u16 currentMusic = GetCurrentMapMusic();
        if (newMusic != MUS_ABNORMAL_WEATHER && newMusic != MUS_NONE)
        {
            if (currentMusic == MUS_UNDERWATER || currentMusic == MUS_SURF)
                return;
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
                newMusic = MUS_SURF;
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
    if (currentMusic != newMusic && currentMusic != MUS_ABNORMAL_WEATHER)
        FadeOutAndPlayNewMapMusic(newMusic, 8);
}

u8 GetMapMusicFadeoutSpeed(void)
{
    const struct MapHeader *mapHeader = GetDestinationWarpMapHeader();
    if (IsMapTypeIndoors(mapHeader->mapType) == TRUE)
        return 2;
    else
        return 4;
}

void TryFadeOutOldMapMusic(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    u16 warpMusic = GetWarpDestinationMusic();
    if (FlagGet(FLAG_DONT_TRANSITION_MUSIC) != TRUE && warpMusic != GetCurrentMapMusic())
    {
        if (currentMusic == MUS_SURF
            && VarGet(VAR_SKY_PILLAR_STATE) == 2
            && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && sWarpDestination.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && sWarpDestination.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && sWarpDestination.x == 29
            && sWarpDestination.y == 53)
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
    PlayCry_NormalNoDucking(sAmbientCrySpecies, pan, volume, CRY_PRIORITY_AMBIENT);
}

// States for UpdateAmbientCry
enum {
    AMB_CRY_INIT,
    AMB_CRY_FIRST,
    AMB_CRY_RESET,
    AMB_CRY_WAIT,
    AMB_CRY_IDLE,
};

void UpdateAmbientCry(s16 *state, u16 *delayCounter)
{
    u8 i, monsCount, divBy;

    switch (*state)
    {
    case AMB_CRY_INIT:
        // This state will be revisited whenever ResetFieldTasksArgs is called (which happens on map transition)
        if (sAmbientCrySpecies == SPECIES_NONE)
            *state = AMB_CRY_IDLE;
        else
            *state = AMB_CRY_FIRST;
        break;
    case AMB_CRY_FIRST:
        // It takes between 1200-3599 frames (~20-60 seconds) to play the first ambient cry after entering a map
        *delayCounter = (Random() % 2400) + 1200;
        *state = AMB_CRY_WAIT;
        break;
    case AMB_CRY_RESET:
        divBy = 1;
        monsCount = CalculatePlayerPartyCount();
        for (i = 0; i < monsCount; i++)
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
                && GetMonAbility(&gPlayerParty[0]) == ABILITY_SWARM)
            {
                divBy = 2;
                break;
            }
        }
        // Ambient cries after the first one take between 1200-2399 frames (~20-40 seconds)
        // If the player has a Pokémon with the ability Swarm in their party, the time is halved to 600-1199 frames (~10-20 seconds)
        *delayCounter = ((Random() % 1200) + 1200) / divBy;
        *state = AMB_CRY_WAIT;
        break;
    case AMB_CRY_WAIT:
        if (--(*delayCounter) == 0)
        {
            PlayAmbientCry();
            *state = AMB_CRY_RESET;
        }
        break;
    case AMB_CRY_IDLE:
        // No land/water Pokémon on this map
        break;
    }
}

static void ChooseAmbientCrySpecies(void)
{
    if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE130)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE130))
     && !IsMirageIslandPresent())
    {
        // Only play water Pokémon cries on this route
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

u8 GetCurrentMapType(void)
{
    return GetMapTypeByWarpData(&gSaveBlock1Ptr->location);
}

u8 GetLastUsedWarpMapType(void)
{
    return GetMapTypeByWarpData(&gLastUsedWarp);
}

bool8 IsMapTypeOutdoors(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_UNDERWATER
     || mapType == MAP_TYPE_CITY
     || mapType == MAP_TYPE_OCEAN_ROUTE)
        return TRUE;
    else
        return FALSE;
}

bool8 Overworld_MapTypeAllowsTeleportAndFly(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_OCEAN_ROUTE
     || mapType == MAP_TYPE_CITY)
        return TRUE;
    else
        return FALSE;
}

bool8 IsMapTypeIndoors(u8 mapType)
{
    if (mapType == MAP_TYPE_INDOOR
     || mapType == MAP_TYPE_SECRET_BASE)
        return TRUE;
    else
        return FALSE;
}

u8 GetSavedWarpRegionMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->dynamicWarp.mapGroup, gSaveBlock1Ptr->dynamicWarp.mapNum)->regionMapSectionId;
}

u8 GetCurrentRegionMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->regionMapSectionId;
}

u8 GetCurrentMapBattleScene(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->battleType;
}

static void InitOverworldBgs(void)
{
    InitBgsFromTemplates(0, sOverworldBgTemplates, ARRAY_COUNT(sOverworldBgTemplates));
    SetBgAttribute(1, BG_ATTR_MOSAIC, 1);
    SetBgAttribute(2, BG_ATTR_MOSAIC, 1);
    SetBgAttribute(3, BG_ATTR_MOSAIC, 1);
    gOverworldTilemapBuffer_Bg1 = AllocZeroed(BG_SCREEN_SIZE);
    gOverworldTilemapBuffer_Bg2 = AllocZeroed(BG_SCREEN_SIZE);
    gOverworldTilemapBuffer_Bg3 = AllocZeroed(BG_SCREEN_SIZE);
    SetBgTilemapBuffer(1, gOverworldTilemapBuffer_Bg1);
    SetBgTilemapBuffer(2, gOverworldTilemapBuffer_Bg2);
    SetBgTilemapBuffer(3, gOverworldTilemapBuffer_Bg3);
    InitStandardTextBoxWindows();
}

void CleanupOverworldWindowsAndTilemaps(void)
{
    ClearMirageTowerPulseBlendEffect();
    FreeAllOverworldWindowBuffers();
    TRY_FREE_AND_SET_NULL(gOverworldTilemapBuffer_Bg3);
    TRY_FREE_AND_SET_NULL(gOverworldTilemapBuffer_Bg2);
    TRY_FREE_AND_SET_NULL(gOverworldTilemapBuffer_Bg1);
}

static void ResetSafariZoneFlag_(void)
{
    ResetSafariZoneFlag();
}

bool32 IsOverworldLinkActive(void)
{
    if (gMain.callback1 == CB1_OverworldLink)
        return TRUE;
    else
        return FALSE;
}

static void DoCB1_Overworld(u16 newKeys, u16 heldKeys)
{
    struct FieldInput inputStruct;

    UpdatePlayerAvatarTransitionState();
    FieldClearPlayerInput(&inputStruct);
    FieldGetPlayerInput(&inputStruct, newKeys, heldKeys);
    if (!ArePlayerFieldControlsLocked())
    {
        if (ProcessPlayerFieldInput(&inputStruct) == 1)
        {
            LockPlayerFieldControls();
            HideMapNamePopUpWindow();
        }
        else
        {
            PlayerStep(inputStruct.dpadDirection, newKeys, heldKeys);
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
    ScriptContext_RunScript();
    RunTasks();
    AnimateSprites();
    CameraUpdate();
    UpdateCameraPanning();
    BuildOamBuffer();
    UpdatePaletteFade();
    UpdateTilesetAnimations();
    DoScheduledBgTilemapCopiesToVram();
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
    {
        SetFieldVBlankCallback();
        return;
    }
}

void SetMainCallback1(MainCallback cb)
{
    gMain.callback1 = cb;
}

// This function is never called.
void SetUnusedCallback(void *func)
{
    sUnusedOverworldCallback = func;
}

static bool8 RunFieldCallback(void)
{
    if (gFieldCallback2)
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
        if (gFieldCallback)
            gFieldCallback();
        else
            FieldCB_DefaultWarpExit();

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
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    gFieldCallback = ExecuteTruckSequence;
    gFieldCallback2 = NULL;
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
}

void CB2_WhiteOut(void)
{
    u8 state;

    if (++gMain.state >= 120)
    {
        FieldClearVBlankHBlankCallbacks();
        StopMapMusic();
        ResetSafariZoneFlag_();
        DoWhiteOut();
        ResetInitialPlayerAvatarState();
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        gFieldCallback = FieldCB_WarpExitFadeFromBlack;
        state = 0;
        DoMapLoadLoop(&state);
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_LoadMap(void)
{
    FieldClearVBlankHBlankCallbacks();
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    SetMainCallback1(NULL);
    SetMainCallback2(CB2_DoChangeMap);
    gMain.savedCallback = CB2_LoadMap2;
}

static void CB2_LoadMap2(void)
{
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
}

void CB2_ReturnToFieldContestHall(void)
{
    if (!gMain.state)
    {
        FieldClearVBlankHBlankCallbacks();
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        SetMainCallback1(NULL);
    }
    if (LoadMapInStepsLocal(&gMain.state, TRUE))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToFieldCableClub(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ReturnToFieldWirelessLink;
    SetMainCallback2(CB2_LoadMapOnReturnToFieldCableClub);
}

static void CB2_LoadMapOnReturnToFieldCableClub(void)
{
    if (LoadMapInStepsLink(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_OverworldLink);
        ResetAllMultiplayerState();
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToField(void)
{
    if (IsOverworldLinkActive() == TRUE)
    {
        SetMainCallback2(CB2_ReturnToFieldLink);
    }
    else
    {
        FieldClearVBlankHBlankCallbacks();
        SetMainCallback2(CB2_ReturnToFieldLocal);
    }
}

static void CB2_ReturnToFieldLocal(void)
{
    if (ReturnToFieldLocal(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback2(CB2_Overworld);
    }
}

static void CB2_ReturnToFieldLink(void)
{
    if (!Overworld_IsRecvQueueAtMax() && ReturnToFieldLink(&gMain.state))
        SetMainCallback2(CB2_Overworld);
}

void CB2_ReturnToFieldFromMultiplayer(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    SetMainCallback1(CB1_OverworldLink);
    ResetAllMultiplayerState();

    if (gWirelessCommType != 0)
        gFieldCallback = FieldCB_ReturnToFieldWirelessLink;
    else
        gFieldCallback = FieldCB_ReturnToFieldCableLink;

    ScriptContext_Init();
    UnlockPlayerFieldControls();
    CB2_ReturnToField();
}

void CB2_ReturnToFieldWithOpenMenu(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback2 = FieldCB_ReturnToFieldOpenStartMenu;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScript(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ContinueScript;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScriptPlayMapMusic(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldFadeFromBlack(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_WarpExitFadeFromBlack;
    CB2_ReturnToField();
}

static void FieldCB_FadeTryShowMapPopup(void)
{
    if (gMapHeader.showMapName == TRUE && SecretBaseMapPopupEnabled() == TRUE)
        ShowMapNamePopup();
    FieldCB_WarpExitFadeFromBlack();
}

void CB2_ContinueSavedGame(void)
{
    u8 trainerHillMapId;

    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    if (gSaveFileStatus == SAVE_STATUS_ERROR)
        ResetWinStreaks();

    LoadSaveblockMapHeader();
    ClearDiveAndHoleWarps();
    trainerHillMapId = GetCurrentTrainerHillMapId();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        LoadBattlePyramidFloorObjectEventScripts();
    else if (trainerHillMapId != 0 && trainerHillMapId != TRAINER_HILL_ENTRANCE)
        LoadTrainerHillFloorObjectEventScripts();
    else
        LoadSaveblockObjEventScripts();

    UnfreezeObjectEvents();
    DoTimeBasedEvents();
    UpdateMiscOverworldStates();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        InitBattlePyramidMap(TRUE);
    else if (trainerHillMapId != 0)
        InitTrainerHillMap();
    else
        InitMapFromSavedGame();

    PlayTimeCounter_Start();
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    InitMatchCallCounters();
    if (UseContinueGameWarp() == TRUE)
    {
        ClearContinueGameWarpStatus();
        SetWarpDestinationToContinueGameWarp();
        WarpIntoMap();
        TryPutTodaysRivalTrainerOnAir();
        SetMainCallback2(CB2_LoadMap);
    }
    else
    {
        TryPutTodaysRivalTrainerOnAir();
        gFieldCallback = FieldCB_FadeTryShowMapPopup;
        SetMainCallback1(CB1_Overworld);
        CB2_ReturnToField();
    }
}

static void FieldClearVBlankHBlankCallbacks(void)
{
    if (UsedPokemonCenterWarp() == TRUE)
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
        WriteBattlePyramidViewScanlineEffectBuffer();
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
    else if ((flashLevel = GetFlashLevel()))
    {
        WriteFlashScanlineEffectBuffer(flashLevel);
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
}

static bool32 LoadMapInStepsLink(u8 *state)
{
    switch (*state)
    {
    case 0:
        InitOverworldBgs();
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        (*state)++;
        break;
    case 1:
        LoadMapFromWarp(TRUE);
        (*state)++;
        break;
    case 2:
        ResumeMap(TRUE);
        (*state)++;
        break;
    case 3:
        OffsetCameraFocusByLinkPlayerId();
        InitObjectEventsLink();
        SpawnLinkPlayers();
        SetCameraToTrackGuestPlayer();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 5:
        ResetFieldCamera();
        (*state)++;
        break;
    case 6:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 LoadMapInStepsLocal(u8 *state, bool32 a2)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        LoadMapFromWarp(a2);
        (*state)++;
        break;
    case 1:
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        (*state)++;
        break;
    case 2:
        ResumeMap(a2);
        (*state)++;
        break;
    case 3:
        InitObjectEventsLocal();
        SetCameraToTrackPlayer();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 5:
        ResetFieldCamera();
        (*state)++;
        break;
    case 6:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gMapHeader.showMapName == TRUE && SecretBaseMapPopupEnabled() == TRUE)
            ShowMapNamePopup();
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 ReturnToFieldLocal(u8 *state)
{
    switch (*state)
    {
    case 0:
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        ResumeMap(FALSE);
        InitObjectEventsReturnToField();
        if (gFieldCallback == FieldCallback_UseFly)
            RemoveFollowingPokemon();
        else
            UpdateFollowingPokemon();
        SetCameraToTrackPlayer();
        (*state)++;
        break;
    case 1:
        InitViewGraphics();
        TryLoadTrainerHillEReaderPalette();
        (*state)++;
        break;
    case 2:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 3:
        return TRUE;
    }

    return FALSE;
}

static bool32 ReturnToFieldLink(u8 *state)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        (*state)++;
        break;
    case 1:
        ResumeMap(TRUE);
        (*state)++;
        break;
    case 2:
        CreateLinkPlayerSprites();
        InitObjectEventsReturnToField();
        SetCameraToTrackGuestPlayer_2();
        (*state)++;
        break;
    case 3:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 4:
        ResetFieldCamera();
        (*state)++;
        break;
    case 5:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 6:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 8:
        DrawWholeMapView();
        (*state)++;
        break;
    case 9:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
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

static void DoMapLoadLoop(u8 *state)
{
    while (!LoadMapInStepsLocal(state, FALSE));
}

static void ResetMirageTowerAndSaveBlockPtrs(void)
{
    ClearMirageTowerPulseBlend();
    MoveSaveBlocks_ResetHeap();
}

static void ResetScreenForMapLoad(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ScanlineEffect_Stop();

    DmaClear16(3, PLTT + 2, PLTT_SIZE - 2);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    ResetOamRange(0, 128);
    LoadOam();
}

static void InitViewGraphics(void)
{
    InitCurrentFlashLevelScanlineEffect();
    InitOverworldGraphicsRegisters();
    InitTextBoxGfxAndPrinters();
    InitMapView();
}

static void InitOverworldGraphicsRegisters(void)
{
    ClearScheduledBgCopiesToVram();
    ResetTempTileDataBuffers();
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WINOBJ_BG0);
    SetGpuReg(REG_OFFSET_WIN0H, 0xFF);
    SetGpuReg(REG_OFFSET_WIN0V, 0xFF);
    SetGpuReg(REG_OFFSET_WIN1H, 0xFFFF);
    SetGpuReg(REG_OFFSET_WIN1V, 0xFFFF);
    SetGpuReg(REG_OFFSET_BLDCNT, gOverworldBackgroundLayerFlags[1] | gOverworldBackgroundLayerFlags[2] | gOverworldBackgroundLayerFlags[3]
                               | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(13, 7));
    InitOverworldBgs();
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON
                                | DISPCNT_OBJ_1D_MAP | DISPCNT_HBLANK_INTERVAL);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    InitFieldMessageBox();
}

static void ResumeMap(bool32 a1)
{
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    ScanlineEffect_Clear();
    ResetAllPicSprites();
    ResetCameraUpdateInfo();
    InstallCameraPanAheadCallback();
    FreeAllSpritePalettes();

    FieldEffectActiveListClear();
    StartWeather();
    ResumePausedWeather();
    if (!a1)
        SetUpFieldTasks();
    RunOnResumeMapScript();
    TryStartMirageTowerPulseBlendEffect();
}

static void InitObjectEventsLink(void)
{
    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetObjectEvents();
    TrySpawnObjectEvents(0, 0);
    TryRunOnWarpIntoMapScript();
}

static void InitObjectEventsLocal(void)
{
    u16 x, y;
    struct InitialPlayerAvatarState *player;

    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetObjectEvents();
    GetCameraFocusCoords(&x, &y);
    player = GetInitialPlayerAvatarState();
    InitPlayerAvatar(x, y, player->direction, gSaveBlock2Ptr->playerGender);
    SetPlayerAvatarTransitionFlags(player->transitionFlags);
    ResetInitialPlayerAvatarState();
    TrySpawnObjectEvents(0, 0);
    UpdateFollowingPokemon();
    TryRunOnWarpIntoMapScript();
}

static void InitObjectEventsReturnToField(void)
{
    SpawnObjectEventsOnReturnToField(0, 0);
    RotatingGate_InitPuzzleAndGraphics();
    RunOnReturnToFieldMapScript();
}

static void SetCameraToTrackPlayer(void)
{
    gObjectEvents[gPlayerAvatar.objectEventId].trackedByCamera = TRUE;
    InitCameraUpdateCallback(gPlayerAvatar.spriteId);
}

static void SetCameraToTrackGuestPlayer(void)
{
    InitCameraUpdateCallback(GetSpriteForLinkedPlayer(gLocalLinkPlayerId));
}

// Duplicate function.
static void SetCameraToTrackGuestPlayer_2(void)
{
    InitCameraUpdateCallback(GetSpriteForLinkedPlayer(gLocalLinkPlayerId));
}

static void OffsetCameraFocusByLinkPlayerId(void)
{
    u16 x, y;
    GetCameraFocusCoords(&x, &y);

    // This is a hack of some kind; it's undone in SpawnLinkPlayers, which is called
    // soon after this function.
    SetCameraFocusCoords(x + gLocalLinkPlayerId, y);
}

static void SpawnLinkPlayers(void)
{
    u16 i;
    u16 x, y;

    GetCameraFocusCoords(&x, &y);
    x -= gLocalLinkPlayerId;

    for (i = 0; i < gFieldLinkPlayerCount; i++)
    {
        SpawnLinkPlayerObjectEvent(i, i + x, y, gLinkPlayers[i].gender);
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
    }

    ClearAllPlayerKeys();
}

static void CreateLinkPlayerSprites(void)
{
    u16 i;
    for (i = 0; i < gFieldLinkPlayerCount; i++)
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
}


static void CB1_OverworldLink(void)
{
    if (gWirelessCommType == 0 || !IsRfuRecvQueueEmpty() || !IsSendingKeysToLink())
    {
        u8 selfId = gLocalLinkPlayerId;
        UpdateAllLinkPlayers(gLinkPartnersHeldKeys, selfId);

        // Note: Because guestId is between 0 and 4, while the smallest key code is
        // LINK_KEY_CODE_EMPTY, this is functionally equivalent to `sPlayerKeyInterceptCallback(0)`.
        // It is expecting the callback to be KeyInterCB_SelfIdle, and that will
        // completely ignore any input parameters.
        //
        // UpdateHeldKeyCode performs a sanity check on its input; if
        // sPlayerKeyInterceptCallback echoes back the argument, which is selfId, then
        // it'll use LINK_KEY_CODE_EMPTY instead.
        //
        // Note 2: There are some key intercept callbacks that treat the key as a player
        // ID. It's so hacky.
        UpdateHeldKeyCode(sPlayerKeyInterceptCallback(selfId));
        ClearAllPlayerKeys();
    }
}

void ResetAllMultiplayerState(void)
{
    ResetAllPlayerLinkStates();
    SetKeyInterceptCallback(KeyInterCB_SelfIdle);
}

static void ClearAllPlayerKeys(void)
{
    ResetPlayerHeldKeys(gLinkPartnersHeldKeys);
}

static void SetKeyInterceptCallback(u16 (*func)(u32))
{
    sRfuKeepAliveTimer = 0;
    sPlayerKeyInterceptCallback = func;
}

// Once every ~60 frames, if the link state hasn't changed (timer reset by calls
// to SetKeyInterceptCallback), it does a bunch of sanity checks on the connection.
// I'm not sure if sRfuKeepAliveTimer is reset in the process, though; rfu stuff is
// still undocumented.
static void CheckRfuKeepAliveTimer(void)
{
    if (gWirelessCommType != 0 && ++sRfuKeepAliveTimer > 60)
        LinkRfu_FatalError();
}

static void ResetAllPlayerLinkStates(void)
{
    s32 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
        sPlayerLinkStates[i] = PLAYER_LINK_STATE_IDLE;
}

// Returns true if all connected players are in state.
static bool32 AreAllPlayersInLinkState(u16 state)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sPlayerLinkStates[i] != state)
            return FALSE;
    return TRUE;
}

static bool32 IsAnyPlayerInLinkState(u16 state)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sPlayerLinkStates[i] == state)
            return TRUE;
    return FALSE;
}

static void HandleLinkPlayerKeyInput(u32 playerId, u16 key, struct CableClubPlayer *trainer, u16 *forceFacing)
{
    const u8 *script;

    if (sPlayerLinkStates[playerId] == PLAYER_LINK_STATE_IDLE)
    {
        script = TryGetTileEventScript(trainer);
        if (script)
        {
            *forceFacing = GetDirectionForEventScript(script);
            sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
            if (trainer->isLocalPlayer)
            {
                SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                RunInteractLocalPlayerScript(script);
            }
            return;
        }
        if (IsAnyPlayerInLinkState(PLAYER_LINK_STATE_EXITING_ROOM) == TRUE)
        {
            sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
            if (trainer->isLocalPlayer)
            {
                SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                RunTerminateLinkScript();
            }
            return;
        }

        switch (key)
        {
        case LINK_KEY_CODE_START_BUTTON:
            if (CanCableClubPlayerPressStart(trainer))
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    InitLinkRoomStartMenuScript();
                }
            }
            break;
        case LINK_KEY_CODE_DPAD_DOWN:
            if (PlayerIsAtSouthExit(trainer) == TRUE)
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    RunConfirmLeaveCableClubScript();
                }
            }
            break;
        case LINK_KEY_CODE_A_BUTTON:
            script = TryInteractWithPlayer(trainer);
            if (script)
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    InitMenuBasedScript(script);
                }
            }
            break;
        case LINK_KEY_CODE_HANDLE_RECV_QUEUE:
            if (IsCableClubPlayerUnfrozen(trainer))
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToRecvQueue);
                    InitLinkPlayerQueueScript();
                }
            }
            break;
        case LINK_KEY_CODE_HANDLE_SEND_QUEUE:
            if (IsCableClubPlayerUnfrozen(trainer))
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToSendQueue);
                    InitLinkPlayerQueueScript();
                }
            }
            break;
        }
    }

    switch (key)
    {
    case LINK_KEY_CODE_EXIT_ROOM:
        sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_EXITING_ROOM;
        break;
    case LINK_KEY_CODE_READY:
        sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_READY;
        break;
    case LINK_KEY_CODE_IDLE:
        sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_IDLE;
        if (trainer->isLocalPlayer)
            SetKeyInterceptCallback(KeyInterCB_SelfIdle);
        break;
    case LINK_KEY_CODE_EXIT_SEAT:
        if (sPlayerLinkStates[playerId] == PLAYER_LINK_STATE_READY)
            sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
        break;
    }
}

static void UpdateAllLinkPlayers(u16 *keys, s32 selfId)
{
    struct CableClubPlayer trainer;
    s32 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        u8 key = keys[i];
        u16 setFacing = FACING_NONE;
        LoadCableClubPlayer(i, selfId, &trainer);
        HandleLinkPlayerKeyInput(i, key, &trainer, &setFacing);
        if (sPlayerLinkStates[i] == PLAYER_LINK_STATE_IDLE)
            setFacing = GetDirectionForDpadKey(key);
        SetPlayerFacingDirection(i, setFacing);
    }
}

static void UpdateHeldKeyCode(u16 key)
{
    if (key >= LINK_KEY_CODE_EMPTY && key < LINK_KEY_CODE_UNK_8)
        gHeldKeyCodeToSend = key;
    else
        gHeldKeyCodeToSend = LINK_KEY_CODE_EMPTY;

    if (gWirelessCommType != 0
        && GetLinkSendQueueLength() > 1
        && IsOverworldLinkActive() == TRUE
        && IsSendingKeysToLink() == TRUE)
    {
        switch (key)
        {
        case LINK_KEY_CODE_EMPTY:
        case LINK_KEY_CODE_DPAD_DOWN:
        case LINK_KEY_CODE_DPAD_UP:
        case LINK_KEY_CODE_DPAD_LEFT:
        case LINK_KEY_CODE_DPAD_RIGHT:
        case LINK_KEY_CODE_START_BUTTON:
        case LINK_KEY_CODE_A_BUTTON:
            gHeldKeyCodeToSend = LINK_KEY_CODE_NULL;
            break;
        }
    }
}

static u16 KeyInterCB_ReadButtons(u32 key)
{
    if (JOY_HELD(DPAD_UP))
        return LINK_KEY_CODE_DPAD_UP;
    if (JOY_HELD(DPAD_DOWN))
        return LINK_KEY_CODE_DPAD_DOWN;
    if (JOY_HELD(DPAD_LEFT))
        return LINK_KEY_CODE_DPAD_LEFT;
    if (JOY_HELD(DPAD_RIGHT))
        return LINK_KEY_CODE_DPAD_RIGHT;
    if (JOY_NEW(START_BUTTON))
        return LINK_KEY_CODE_START_BUTTON;
    if (JOY_NEW(A_BUTTON))
        return LINK_KEY_CODE_A_BUTTON;
    return LINK_KEY_CODE_EMPTY;
}

static u16 GetDirectionForDpadKey(u16 key)
{
    switch (key)
    {
    case LINK_KEY_CODE_DPAD_RIGHT:
        return FACING_RIGHT;
    case LINK_KEY_CODE_DPAD_LEFT:
        return FACING_LEFT;
    case LINK_KEY_CODE_DPAD_UP:
        return FACING_UP;
    case LINK_KEY_CODE_DPAD_DOWN:
        return FACING_DOWN;
    default:
        return FACING_NONE;
    }
}

// Overwrites the keys with 0x11
static void ResetPlayerHeldKeys(u16 *keys)
{
    s32 i;
    for (i = 0; i < 4; i++)
        keys[i] = LINK_KEY_CODE_EMPTY;
}


static u16 KeyInterCB_SelfIdle(u32 key)
{
    if (ArePlayerFieldControlsLocked() == TRUE)
        return LINK_KEY_CODE_EMPTY;
    if (GetLinkRecvQueueLength() > 4)
        return LINK_KEY_CODE_HANDLE_RECV_QUEUE;
    if (GetLinkSendQueueLength() <= 4)
        return KeyInterCB_ReadButtons(key);
    return LINK_KEY_CODE_HANDLE_SEND_QUEUE;
}

static u16 KeyInterCB_Idle(u32 key)
{
    CheckRfuKeepAliveTimer();
    return LINK_KEY_CODE_EMPTY;
}

// Ignore the player's inputs as long as there is an event script being executed.
static u16 KeyInterCB_DeferToEventScript(u32 key)
{
    u16 retVal;
    if (ArePlayerFieldControlsLocked() == TRUE)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_IDLE;
        SetKeyInterceptCallback(KeyInterCB_Idle);
    }
    return retVal;
}

// Ignore the player's inputs as long as there are events being recived.
static u16 KeyInterCB_DeferToRecvQueue(u32 key)
{
    u16 retVal;
    if (GetLinkRecvQueueLength() >= OVERWORLD_RECV_QUEUE_MAX)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_IDLE;
        UnlockPlayerFieldControls();
        SetKeyInterceptCallback(KeyInterCB_Idle);
    }
    return retVal;
}

// Ignore the player's inputs as long as there are events being sent.
static u16 KeyInterCB_DeferToSendQueue(u32 key)
{
    u16 retVal;
    if (GetLinkSendQueueLength() > 2)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_IDLE;
        UnlockPlayerFieldControls();
        SetKeyInterceptCallback(KeyInterCB_Idle);
    }
    return retVal;
}

static u16 KeyInterCB_ExitingSeat(u32 key)
{
    CheckRfuKeepAliveTimer();
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_Ready(u32 keyOrPlayerId)
{
    if (sPlayerLinkStates[keyOrPlayerId] == PLAYER_LINK_STATE_READY)
    {
        if (JOY_NEW(B_BUTTON))
        {
            SetKeyInterceptCallback(KeyInterCB_ExitingSeat);
            return LINK_KEY_CODE_EXIT_SEAT;
        }
        else
        {
            return LINK_KEY_CODE_EMPTY;
        }
    }
    else
    {
        CheckRfuKeepAliveTimer();
        return LINK_KEY_CODE_EMPTY;
    }
}

static u16 KeyInterCB_SetReady(u32 key)
{
    SetKeyInterceptCallback(KeyInterCB_Ready);
    return LINK_KEY_CODE_READY;
}

static u16 KeyInterCB_SendNothing(u32 key)
{
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_WaitForPlayersToExit(u32 keyOrPlayerId)
{
    // keyOrPlayerId could be any keycode. This callback does no sanity checking
    // on the size of the key. It's assuming that it is being called from
    // CB1_OverworldLink.
    if (sPlayerLinkStates[keyOrPlayerId] != PLAYER_LINK_STATE_EXITING_ROOM)
        CheckRfuKeepAliveTimer();
    if (AreAllPlayersInLinkState(PLAYER_LINK_STATE_EXITING_ROOM) == TRUE)
    {
        ScriptContext_SetupScript(EventScript_DoLinkRoomExit);
        SetKeyInterceptCallback(KeyInterCB_SendNothing);
    }
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_SendExitRoomKey(u32 key)
{
    SetKeyInterceptCallback(KeyInterCB_WaitForPlayersToExit);
    return LINK_KEY_CODE_EXIT_ROOM;
}

// Identical to KeyInterCB_SendNothing
static u16 KeyInterCB_InLinkActivity(u32 key)
{
    return LINK_KEY_CODE_EMPTY;
}

u32 GetCableClubPartnersReady(void)
{
    if (IsAnyPlayerInLinkState(PLAYER_LINK_STATE_EXITING_ROOM) == TRUE)
        return CABLE_SEAT_FAILED;
    if (sPlayerKeyInterceptCallback == KeyInterCB_Ready && sPlayerLinkStates[gLocalLinkPlayerId] != PLAYER_LINK_STATE_READY)
        return CABLE_SEAT_WAITING;
    if (sPlayerKeyInterceptCallback == KeyInterCB_ExitingSeat && sPlayerLinkStates[gLocalLinkPlayerId] == PLAYER_LINK_STATE_BUSY)
        return CABLE_SEAT_FAILED;
    if (AreAllPlayersInLinkState(PLAYER_LINK_STATE_READY))
        return CABLE_SEAT_SUCCESS;
    return CABLE_SEAT_WAITING;
}

static bool32 UNUSED IsAnyPlayerExitingCableClub(void)
{
    return IsAnyPlayerInLinkState(PLAYER_LINK_STATE_EXITING_ROOM);
}

u16 SetInCableClubSeat(void)
{
    SetKeyInterceptCallback(KeyInterCB_SetReady);
    return 0;
}

u16 SetLinkWaitingForScript(void)
{
    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
    return 0;
}

// The exit room key will be sent at the next opportunity.
// The return value is meaningless.
u16 QueueExitLinkRoomKey(void)
{
    SetKeyInterceptCallback(KeyInterCB_SendExitRoomKey);
    return 0;
}

u16 SetStartedCableClubActivity(void)
{
    SetKeyInterceptCallback(KeyInterCB_InLinkActivity);
    return 0;
}

static void LoadCableClubPlayer(s32 linkPlayerId, s32 myPlayerId, struct CableClubPlayer *trainer)
{
    s16 x, y;

    trainer->playerId = linkPlayerId;
    trainer->isLocalPlayer = (linkPlayerId == myPlayerId) ? 1 : 0;
    trainer->movementMode = gLinkPlayerObjectEvents[linkPlayerId].movementMode;
    trainer->facing = GetLinkPlayerFacingDirection(linkPlayerId);
    GetLinkPlayerCoords(linkPlayerId, &x, &y);
    trainer->pos.x = x;
    trainer->pos.y = y;
    trainer->pos.elevation = GetLinkPlayerElevation(linkPlayerId);
    trainer->metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
}

static bool32 IsCableClubPlayerUnfrozen(struct CableClubPlayer *player)
{
    u8 mode = player->movementMode;
    if (mode == MOVEMENT_MODE_SCRIPTED || mode == MOVEMENT_MODE_FREE)
        return TRUE;
    else
        return FALSE;
}

// Identical to IsCableClubPlayerUnfrozen
static bool32 CanCableClubPlayerPressStart(struct CableClubPlayer *player)
{
    u8 mode = player->movementMode;
    if (mode == MOVEMENT_MODE_SCRIPTED || mode == MOVEMENT_MODE_FREE)
        return TRUE;
    else
        return FALSE;
}

static const u8 *TryGetTileEventScript(struct CableClubPlayer *player)
{
    if (player->movementMode != MOVEMENT_MODE_SCRIPTED)
        return FACING_NONE;
    return GetCoordEventScriptAtMapPosition(&player->pos);
}

static bool32 PlayerIsAtSouthExit(struct CableClubPlayer *player)
{
    if (player->movementMode != MOVEMENT_MODE_SCRIPTED && player->movementMode != MOVEMENT_MODE_FREE)
        return FALSE;
    else if (!MetatileBehavior_IsSouthArrowWarp(player->metatileBehavior))
        return FALSE;
    else if (player->facing != DIR_SOUTH)
        return FALSE;
    else
        return TRUE;
}

static const u8 *TryInteractWithPlayer(struct CableClubPlayer *player)
{
    struct MapPosition otherPlayerPos;
    u8 linkPlayerId;

    if (player->movementMode != MOVEMENT_MODE_FREE && player->movementMode != MOVEMENT_MODE_SCRIPTED)
        return FACING_NONE;

    otherPlayerPos = player->pos;
    otherPlayerPos.x += gDirectionToVectors[player->facing].x;
    otherPlayerPos.y += gDirectionToVectors[player->facing].y;
    otherPlayerPos.elevation = 0;
    linkPlayerId = GetLinkPlayerIdAt(otherPlayerPos.x, otherPlayerPos.y);

    if (linkPlayerId != MAX_LINK_PLAYERS)
    {
        if (!player->isLocalPlayer)
            return CableClub_EventScript_TooBusyToNotice;
        else if (sPlayerLinkStates[linkPlayerId] != PLAYER_LINK_STATE_IDLE)
            return CableClub_EventScript_TooBusyToNotice;
        else if (!GetLinkTrainerCardColor(linkPlayerId))
            return CableClub_EventScript_ReadTrainerCard;
        else
            return CableClub_EventScript_ReadTrainerCardColored;
    }

    return GetInteractedLinkPlayerScript(&otherPlayerPos, player->metatileBehavior, player->facing);
}

// This returns which direction to force the player to look when one of
// these event scripts runs.
static u16 GetDirectionForEventScript(const u8 *script)
{
    if (script == EventScript_BattleColosseum_4P_PlayerSpot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot2)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot3)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_RecordCenter_Spot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_RecordCenter_Spot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_RecordCenter_Spot2)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_RecordCenter_Spot3)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_BattleColosseum_2P_PlayerSpot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_2P_PlayerSpot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_TradeCenter_Chair0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_TradeCenter_Chair1)
        return FACING_FORCED_LEFT;
    else
        return FACING_NONE;
}

static void InitLinkPlayerQueueScript(void)
{
    LockPlayerFieldControls();
}

static void InitLinkRoomStartMenuScript(void)
{
    PlaySE(SE_WIN_OPEN);
    ShowStartMenu();
    LockPlayerFieldControls();
}

static void RunInteractLocalPlayerScript(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext_SetupScript(script);
    LockPlayerFieldControls();
}

static void RunConfirmLeaveCableClubScript(void)
{
    PlaySE(SE_WIN_OPEN);
    ScriptContext_SetupScript(EventScript_ConfirmLeaveCableClubRoom);
    LockPlayerFieldControls();
}

static void InitMenuBasedScript(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext_SetupScript(script);
    LockPlayerFieldControls();
}

static void RunTerminateLinkScript(void)
{
    ScriptContext_SetupScript(EventScript_TerminateLink);
    LockPlayerFieldControls();
}

bool32 Overworld_IsRecvQueueAtMax(void)
{
    if (!IsOverworldLinkActive())
        return FALSE;
    if (GetLinkRecvQueueLength() >= OVERWORLD_RECV_QUEUE_MAX)
        sReceivingFromLink = TRUE;
    else
        sReceivingFromLink = FALSE;
    return sReceivingFromLink;
}

bool32 Overworld_RecvKeysFromLinkIsRunning(void)
{
    u8 temp;

    if (GetLinkRecvQueueLength() < OVERWORLD_RECV_QUEUE_MAX - 1)
        return FALSE;
    else if (IsOverworldLinkActive() != TRUE)
        return FALSE;
    else if (IsSendingKeysToLink() != TRUE)
        return FALSE;
    else if (sPlayerKeyInterceptCallback == KeyInterCB_DeferToRecvQueue)
        return TRUE;
    else if (sPlayerKeyInterceptCallback != KeyInterCB_DeferToEventScript)
        return FALSE;

    temp = sReceivingFromLink;
    sReceivingFromLink = FALSE;

    if (temp == TRUE)
        return TRUE;
    else if (gPaletteFade.active && gPaletteFade.softwareFadeFinishing)
        return TRUE;
    else
        return FALSE;
}

bool32 Overworld_SendKeysToLinkIsRunning(void)
{
    if (GetLinkSendQueueLength() < 2)
        return FALSE;
    else if (IsOverworldLinkActive() != TRUE)
        return FALSE;
    else if (IsSendingKeysToLink() != TRUE)
        return FALSE;
    else if (sPlayerKeyInterceptCallback == KeyInterCB_DeferToSendQueue)
        return TRUE;
    else
        return FALSE;
}

bool32 IsSendingKeysOverCable(void)
{
    if (gWirelessCommType != 0)
        return FALSE;
    else if (!IsSendingKeysToLink())
        return FALSE;
    else
        return TRUE;
}

static u32 GetLinkSendQueueLength(void)
{
    if (gWirelessCommType != 0)
        return gRfu.sendQueue.count;
    else
        return gLink.sendQueue.count;
}

static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *linkPlayerObjEvent)
{
    memset(linkPlayerObjEvent, 0, sizeof(struct LinkPlayerObjectEvent));
}

void ClearLinkPlayerObjectEvents(void)
{
    memset(gLinkPlayerObjectEvents, 0, sizeof(gLinkPlayerObjectEvents));
}

static void ZeroObjectEvent(struct ObjectEvent *objEvent)
{
    memset(objEvent, 0, sizeof(struct ObjectEvent));
}

// Note: Emerald reuses the direction and range variables during Link mode
// as special gender and direction values. The types and placement
// conflict with the usual Event Object struct, thus the definitions.
#define linkGender(obj) obj->singleMovementActive
// not even one can reference *byte* aligned bitfield members...
#define linkDirection(obj) ((u8 *)obj)[offsetof(typeof(*obj), fieldEffectSpriteId) - 1] // -> rangeX

static void SpawnLinkPlayerObjectEvent(u8 linkPlayerId, s16 x, s16 y, u8 gender)
{
    u8 objEventId = GetFirstInactiveObjectEventId();
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];

    ZeroLinkPlayerObjectEvent(linkPlayerObjEvent);
    ZeroObjectEvent(objEvent);

    linkPlayerObjEvent->active = TRUE;
    linkPlayerObjEvent->linkPlayerId = linkPlayerId;
    linkPlayerObjEvent->objEventId = objEventId;
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;

    objEvent->active = TRUE;
    linkGender(objEvent) = gender;
    linkDirection(objEvent) = DIR_NORTH;
    objEvent->spriteId = MAX_SPRITES;

    InitLinkPlayerObjectEventPos(objEvent, x, y);
}

static void InitLinkPlayerObjectEventPos(struct ObjectEvent *objEvent, s16 x, s16 y)
{
    objEvent->currentCoords.x = x;
    objEvent->currentCoords.y = y;
    objEvent->previousCoords.x = x;
    objEvent->previousCoords.y = y;
    SetSpritePosToMapCoords(x, y, &objEvent->initialCoords.x, &objEvent->initialCoords.y);
    objEvent->initialCoords.x += 8;
    ObjectEventUpdateElevation(objEvent, NULL);
}

static void UNUSED SetLinkPlayerObjectRange(u8 linkPlayerId, u8 dir)
{
    if (gLinkPlayerObjectEvents[linkPlayerId].active)
    {
        u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
        struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
        linkDirection(objEvent) = dir;
    }
}

static void UNUSED DestroyLinkPlayerObject(u8 linkPlayerId)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    if (objEvent->spriteId != MAX_SPRITES)
        DestroySprite(&gSprites[objEvent->spriteId]);
    linkPlayerObjEvent->active = 0;
    objEvent->active = 0;
}

// Returns the spriteId corresponding to this player.
static u8 GetSpriteForLinkedPlayer(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->spriteId;
}

static void GetLinkPlayerCoords(u8 linkPlayerId, s16 *x, s16 *y)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    *x = objEvent->currentCoords.x;
    *y = objEvent->currentCoords.y;
}

static u8 GetLinkPlayerFacingDirection(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return linkDirection(objEvent);
}

static u8 GetLinkPlayerElevation(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->currentElevation;
}

static s32 UNUSED GetLinkPlayerObjectStepTimer(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return 16 - (s8)objEvent->directionSequenceIndex;
}

static u8 GetLinkPlayerIdAt(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayerObjectEvents[i].active
         && (gLinkPlayerObjectEvents[i].movementMode == 0 || gLinkPlayerObjectEvents[i].movementMode == 2))
        {
            struct ObjectEvent *objEvent = &gObjectEvents[gLinkPlayerObjectEvents[i].objEventId];
            if (objEvent->currentCoords.x == x && objEvent->currentCoords.y == y)
                return i;
        }
    }
    return 4;
}

static void SetPlayerFacingDirection(u8 linkPlayerId, u8 facing)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];

    if (linkPlayerObjEvent->active)
    {
        if (facing > FACING_FORCED_RIGHT)
        {
            objEvent->triggerGroundEffectsOnMove = TRUE;
        }
        else
        {
            // This is a hack to split this code onto two separate lines, without declaring a local variable.
            // C++ style inline variables would be nice here.
            #define TEMP sLinkPlayerMovementModes[linkPlayerObjEvent->movementMode](linkPlayerObjEvent, objEvent, facing)

            sMovementStatusHandler[TEMP](linkPlayerObjEvent, objEvent);

            // Clean up the hack.
            #undef TEMP
        }
    }
}


static u8 MovementEventModeCB_Normal(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return sLinkPlayerFacingHandlers[dir](linkPlayerObjEvent, objEvent, dir);
}

static u8 MovementEventModeCB_Ignored(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return FACING_UP;
}

// Identical to MovementEventModeCB_Normal
static u8 MovementEventModeCB_Scripted(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return sLinkPlayerFacingHandlers[dir](linkPlayerObjEvent, objEvent, dir);
}

static bool8 FacingHandler_DoNothing(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return FALSE;
}

static bool8 FacingHandler_DpadMovement(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    s16 x, y;

    linkDirection(objEvent) = FlipVerticalAndClearForced(dir, linkDirection(objEvent));
    ObjectEventMoveDestCoords(objEvent, linkDirection(objEvent), &x, &y);

    if (LinkPlayerGetCollision(linkPlayerObjEvent->objEventId, linkDirection(objEvent), x, y))
    {
        return FALSE;
    }
    else
    {
        objEvent->directionSequenceIndex = 16;
        ShiftObjectEventCoords(objEvent, x, y);
        ObjectEventUpdateElevation(objEvent, NULL);
        return TRUE;
    }
}

static bool8 FacingHandler_ForcedFacingChange(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    linkDirection(objEvent) = FlipVerticalAndClearForced(dir, linkDirection(objEvent));
    return FALSE;
}

// This is called every time a free movement happens. Most of the time it's a No-Op.
static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;
}

static void MovementStatusHandler_TryAdvanceScript(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    objEvent->directionSequenceIndex--;
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FROZEN;
    MoveCoords(linkDirection(objEvent), &objEvent->initialCoords.x, &objEvent->initialCoords.y);
    if (!objEvent->directionSequenceIndex)
    {
        ShiftStillObjectEventCoords(objEvent);
        linkPlayerObjEvent->movementMode = MOVEMENT_MODE_SCRIPTED;
    }
}

// Flip Up/Down facing codes. If newFacing doesn't specify a direction, default
// to oldFacing. Note that this clears also the "FORCED" part of the facing code,
// even for Left/Right codes.
static u8 FlipVerticalAndClearForced(u8 newFacing, u8 oldFacing)
{
    switch (newFacing)
    {
    case FACING_UP:
    case FACING_FORCED_UP:
        return DIR_NORTH;
    case FACING_DOWN:
    case FACING_FORCED_DOWN:
        return DIR_SOUTH;
    case FACING_LEFT:
    case FACING_FORCED_LEFT:
        return DIR_WEST;
    case FACING_RIGHT:
    case FACING_FORCED_RIGHT:
        return DIR_EAST;
    }
    return oldFacing;
}

static u8 LinkPlayerGetCollision(u8 selfObjEventId, u8 direction, s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (i != selfObjEventId)
        {
            if ((gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
             || (gObjectEvents[i].previousCoords.x == x && gObjectEvents[i].previousCoords.y == y))
            {
                return 1;
            }
        }
    }
    return MapGridGetCollisionAt(x, y);
}

static void CreateLinkPlayerSprite(u8 linkPlayerId, u8 gameVersion)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    struct Sprite *sprite;

    if (linkPlayerObjEvent->active)
    {
        switch (gameVersion)
        {
        case VERSION_FIRE_RED:
        case VERSION_LEAF_GREEN:
            objEvent->spriteId = CreateObjectGraphicsSprite(GetFRLGAvatarGraphicsIdByGender(linkGender(objEvent)), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_RUBY:
        case VERSION_SAPPHIRE:
            objEvent->spriteId = CreateObjectGraphicsSprite(GetRSAvatarGraphicsIdByGender(linkGender(objEvent)), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_EMERALD:
            objEvent->spriteId = CreateObjectGraphicsSprite(GetRivalAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, linkGender(objEvent)), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        }

        sprite = &gSprites[objEvent->spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = linkPlayerId;
        objEvent->triggerGroundEffectsOnMove = FALSE;
    }
}

static void SpriteCB_LinkPlayer(struct Sprite *sprite)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[sprite->data[0]];
    struct ObjectEvent *objEvent = &gObjectEvents[linkPlayerObjEvent->objEventId];
    sprite->x = objEvent->initialCoords.x;
    sprite->y = objEvent->initialCoords.y;
    SetObjectSubpriorityByElevation(objEvent->previousElevation, sprite, 1);
    sprite->oam.priority = ElevationToPriority(objEvent->previousElevation);

    if (linkPlayerObjEvent->movementMode == MOVEMENT_MODE_FREE)
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(linkDirection(objEvent)));
    else
        StartSpriteAnimIfDifferent(sprite, GetMoveDirectionAnimNum(linkDirection(objEvent)));

    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    if (objEvent->triggerGroundEffectsOnMove)
    {
        sprite->invisible = ((sprite->data[7] & 4) >> 2);
        sprite->data[7]++;
    }
}
