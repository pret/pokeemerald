#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "cable_club.h"
#include "data.h"
#include "decoration.h"
#include "diploma.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item_icon.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "mevent.h"
#include "match_call.h"
#include "menu.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "rayquaza_scene.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "slot_machine.h"
#include "sound.h"
#include "starter_choose.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "wallclock.h"
#include "window.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tower.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/mevent.h"
#include "constants/tv.h"
#include "constants/script_menu.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/vars.h"
#include "constants/battle_frontier.h"
#include "constants/weather.h"
#include "constants/metatile_labels.h"
#include "palette.h"

EWRAM_DATA bool8 gBikeCyclingChallenge = FALSE;
EWRAM_DATA u8 gBikeCollisions = 0;
static EWRAM_DATA u32 sBikeCyclingTimer = 0;
static EWRAM_DATA u8 sSlidingDoorNextFrameCounter = 0;
static EWRAM_DATA u8 sSlidingDoorFrame = 0;
static EWRAM_DATA u8 sTutorMoveAndElevatorWindowId = 0;
static EWRAM_DATA u16 sLilycoveDeptStore_NeverRead = 0;
static EWRAM_DATA u16 sLilycoveDeptStore_DefaultFloorChoice = 0;
static EWRAM_DATA struct ListMenuItem *sScrollableMultichoice_ListMenuItem = NULL;
static EWRAM_DATA u16 sScrollableMultichoice_ScrollOffset = 0;
static EWRAM_DATA u16 sFrontierExchangeCorner_NeverRead = 0;
static EWRAM_DATA u8 sScrollableMultichoice_ItemSpriteId = 0;
static EWRAM_DATA u8 sBattlePointsWindowId = 0;
static EWRAM_DATA u8 sFrontierExchangeCorner_ItemIconWindowId = 0;
static EWRAM_DATA u8 sPCBoxToSendMon = 0;
static EWRAM_DATA u32 sBattleTowerMultiBattleTypeFlags = 0;

struct ListMenuTemplate gScrollableMultichoice_ListMenuTemplate;

extern const u16 gObjectEventPalette8[];
extern const u16 gObjectEventPalette17[];
extern const u16 gObjectEventPalette33[];
extern const u16 gObjectEventPalette34[];

void TryLoseFansFromPlayTime(void);
void SetPlayerGotFirstFans(void);
u16 GetNumFansOfPlayerInTrainerFanClub(void);

static void RecordCyclingRoadResults(u32, u8);
static void LoadLinkPartnerObjectEventSpritePalette(u8 graphicsId, u8 localEventId, u8 paletteNum);
static void Task_PetalburgGymSlideOpenRoomDoors(u8 taskId);
static void PetalburgGymSetDoorMetatiles(u8 roomNumber, u16 metatileId);
static void Task_PCTurnOnEffect(u8);
static void PCTurnOnEffect_0(struct Task *);
static void PCTurnOnEffect_1(s16, s8, s8);
static void PCTurnOffEffect(void);
static void Task_LotteryCornerComputerEffect(u8);
static void LotteryCornerComputerEffect(struct Task *);
static void Task_ShakeCamera(u8 taskId);
static void StopCameraShake(u8 taskId);
static void Task_MoveElevator(u8 taskId);
static void MoveElevatorWindowLights(u16 floorDelta, bool8 descending);
static void Task_MoveElevatorWindowLights(u8 taskId);
static void Task_ShowScrollableMultichoice(u8 taskId);
static void FillFrontierExchangeCornerWindowAndItemIcon(u16 menu, u16 selection);
static void ShowBattleFrontierTutorWindow(u8 menu, u16 selection);
static void InitScrollableMultichoice(void);
static void ScrollableMultichoice_ProcessInput(u8 taskId);
static void ScrollableMultichoice_UpdateScrollArrows(u8 taskId);
static void ScrollableMultichoice_MoveCursor(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void HideFrontierExchangeCornerItemIcon(u16 menu, u16 unused);
static void ShowBattleFrontierTutorMoveDescription(u8 menu, u16 selection);
static void CloseScrollableMultichoice(u8 taskId);
static void ScrollableMultichoice_RemoveScrollArrows(u8 taskId);
static void sub_813A600(u8 taskId);
static void sub_813A664(u8 taskId);
static void ShowFrontierExchangeCornerItemIcon(u16 item);
static void Task_DeoxysRockInteraction(u8 taskId);
static void ChangeDeoxysRockLevel(u8 a0);
static void WaitForDeoxysRockMovement(u8 taskId);
static void Task_LinkRetireStatusWithBattleTowerPartner(u8 taskId);
static void Task_LoopWingFlapSE(u8 taskId);
static void Task_CloseBattlePikeCurtain(u8 taskId);
static u8 DidPlayerGetFirstFans(void);
static void SetInitialFansOfPlayer(void);
static u16 PlayerGainRandomTrainerFan(void);
static void BufferFanClubTrainerName_(struct LinkBattleRecords *linkRecords, u8 a, u8 b);

void Special_ShowDiploma(void)
{
    SetMainCallback2(CB2_ShowDiploma);
    ScriptContext2_Enable();
}

void Special_ViewWallClock(void)
{
    gMain.savedCallback = CB2_ReturnToField;
    SetMainCallback2(CB2_ViewWallClock);
    ScriptContext2_Enable();
}

void ResetCyclingRoadChallengeData(void)
{
    gBikeCyclingChallenge = FALSE;
    gBikeCollisions = 0;
    sBikeCyclingTimer = 0;
}

void Special_BeginCyclingRoadChallenge(void)
{
    gBikeCyclingChallenge = TRUE;
    gBikeCollisions = 0;
    sBikeCyclingTimer = gMain.vblankCounter1;
}

u16 GetPlayerAvatarBike(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        return 1;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        return 2;
    return 0;
}

static void DetermineCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
    u8 result;

    if (numBikeCollisions < 100)
    {
        ConvertIntToDecimalStringN(gStringVar1, numBikeCollisions, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(gStringVar1, gText_SpaceTimes);
    }
    else
    {
        StringCopy(gStringVar1, gText_99TimesPlus);
    }

    if (numFrames < 3600)
    {
        ConvertIntToDecimalStringN(gStringVar2, numFrames / 60, STR_CONV_MODE_RIGHT_ALIGN, 2);
        gStringVar2[2] = CHAR_PERIOD;
        ConvertIntToDecimalStringN(&gStringVar2[3], ((numFrames % 60) * 100) / 60, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gStringVar2, gText_SpaceSeconds);
    }
    else
    {
        StringCopy(gStringVar2, gText_1MinutePlus);
    }

    result = 0;
    if (numBikeCollisions == 0)
    {
        result = 5;
    }
    else if (numBikeCollisions < 4)
    {
        result = 4;
    }
    else if (numBikeCollisions < 10)
    {
        result = 3;
    }
    else if (numBikeCollisions < 20)
    {
        result = 2;
    }
    else if (numBikeCollisions < 100)
    {
        result = 1;
    }

    if (numFrames / 60 <= 10)
    {
        result += 5;
    }
    else if (numFrames / 60 <= 15)
    {
        result += 4;
    }
    else if (numFrames / 60 <= 20)
    {
        result += 3;
    }
    else if (numFrames / 60 <= 40)
    {
        result += 2;
    }
    else if (numFrames / 60 < 60)
    {
        result += 1;
    }


    gSpecialVar_Result = result;
}

void FinishCyclingRoadChallenge(void) {
    const u32 numFrames = gMain.vblankCounter1 - sBikeCyclingTimer;

    DetermineCyclingRoadResults(numFrames, gBikeCollisions);
    RecordCyclingRoadResults(numFrames, gBikeCollisions);
}

static void RecordCyclingRoadResults(u32 numFrames, u8 numBikeCollisions) {
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord > numFrames || framesRecord == 0)
    {
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_L, numFrames);
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_H, numFrames >> 16);
        VarSet(VAR_CYCLING_ROAD_RECORD_COLLISIONS, numBikeCollisions);
    }
}

u16 GetRecordedCyclingRoadResults(void) {
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord == 0)
    {
        return FALSE;
    }

    DetermineCyclingRoadResults(framesRecord, VarGet(VAR_CYCLING_ROAD_RECORD_COLLISIONS));
    return TRUE;
}

void UpdateCyclingRoadState(void) {
    if (gLastUsedWarp.mapNum == MAP_NUM(ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE) && gLastUsedWarp.mapGroup == MAP_GROUP(ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE))
    {
        return;
    }

    if (VarGet(VAR_CYCLING_CHALLENGE_STATE) == 2 || VarGet(VAR_CYCLING_CHALLENGE_STATE) == 3)
    {
        VarSet(VAR_CYCLING_CHALLENGE_STATE, 0);
        Overworld_SetSavedMusic(MUS_DUMMY);
    }
}

void SetSSTidalFlag(void)
{
    FlagSet(FLAG_SYS_CRUISE_MODE);
    *GetVarPointer(VAR_CRUISE_STEP_COUNT) = 0;
}

void ResetSSTidalFlag(void)
{
    FlagClear(FLAG_SYS_CRUISE_MODE);
}

// Returns TRUE if the Cruise is over
bool32 CountSSTidalStep(u16 delta)
{
    if (!FlagGet(FLAG_SYS_CRUISE_MODE) || (*GetVarPointer(VAR_CRUISE_STEP_COUNT) += delta) < SS_TIDAL_MAX_STEPS)
    {
        return FALSE;
    }
    return TRUE;
}

u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y)
{
    u16 *varCruiseStepCount = GetVarPointer(VAR_CRUISE_STEP_COUNT);
    switch (*GetVarPointer(VAR_SS_TIDAL_STATE))
    {
        case SS_TIDAL_BOARD_SLATEPORT:
        case SS_TIDAL_LAND_SLATEPORT:
            return SS_TIDAL_LOCATION_SLATEPORT;
        case SS_TIDAL_HALFWAY_LILYCOVE:
        case SS_TIDAL_EXIT_CURRENTS_RIGHT:
            return SS_TIDAL_LOCATION_ROUTE131;
        case SS_TIDAL_LAND_LILYCOVE:
        case SS_TIDAL_BOARD_LILYCOVE:
            return SS_TIDAL_LOCATION_LILYCOVE;
        case SS_TIDAL_DEPART_LILYCOVE:
        case SS_TIDAL_EXIT_CURRENTS_LEFT:
            return SS_TIDAL_LOCATION_ROUTE124;
        case SS_TIDAL_DEPART_SLATEPORT:
            if (*varCruiseStepCount < 60)
            {
                *mapNum = MAP_NUM(ROUTE134);
                *x = *varCruiseStepCount + 19;
            }
            else if (*varCruiseStepCount < 140)
            {
                *mapNum = MAP_NUM(ROUTE133);
                *x = *varCruiseStepCount - 60;
            }
            else
            {
                *mapNum = MAP_NUM(ROUTE132);
                *x = *varCruiseStepCount - 140;
            }
            break;
        case SS_TIDAL_HALFWAY_SLATEPORT:
            if (*varCruiseStepCount < 66)
            {
                *mapNum = MAP_NUM(ROUTE132);
                *x = 65 - *varCruiseStepCount;
            }
            else if (*varCruiseStepCount < 146) {
                *mapNum = MAP_NUM(ROUTE133);
                *x = 145 - *varCruiseStepCount;
            }
            else
            {
                *mapNum = MAP_NUM(ROUTE134);
                *x = 224 - *varCruiseStepCount;
            }
            break;
    }
    *mapGroup = MAP_GROUP(ROUTE132);
    *y = 20;
    return SS_TIDAL_LOCATION_CURRENTS;
}

bool32 ShouldDoWallyCall(void)
{
    if (FlagGet(FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_WALLY_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoScottFortreeCall(void)
{
    if (FlagGet(FLAG_SCOTT_CALL_FORTREE_GYM))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_SCOTT_FORTREE_CALL_STEP_COUNTER)) < 10)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoScottBattleFrontierCall(void)
{
    if (FlagGet(FLAG_SCOTT_CALL_BATTLE_FRONTIER))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_SCOTT_BF_CALL_STEP_COUNTER)) < 10)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRoxanneCall(void)
{
    if (FlagGet(FLAG_ENABLE_ROXANNE_FIRST_CALL))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_ROXANNE_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRivalRayquazaCall(void)
{
    if (FlagGet(FLAG_DEFEATED_MAGMA_SPACE_CENTER))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

u8 GetLinkPartnerNames(void)
{
    u8 i;
    u8 j = 0;
    u8 myLinkPlayerNumber = GetMultiplayerId();
    u8 nLinkPlayers = GetLinkPlayerCount();
    for (i = 0; i < nLinkPlayers; i++)
    {
        if (myLinkPlayerNumber != i)
        {
            StringCopy(gTVStringVarPtrs[j], gLinkPlayers[i].name);
            j++;
        }
    }
    return nLinkPlayers;
}

void SpawnLinkPartnerObjectEvent(void)
{
    u8 j = 0;
    s16 x = 0;
    s16 y = 0;
    u8 movementTypes[] = {
        MOVEMENT_TYPE_FACE_UP, 
        MOVEMENT_TYPE_FACE_LEFT, 
        MOVEMENT_TYPE_FACE_DOWN, 
        MOVEMENT_TYPE_FACE_RIGHT
    };
    s8 coordOffsets[][2] = {
        { 0,  1},
        { 1,  0},
        { 0, -1},
        {-1,  0}
    };
    u8 myLinkPlayerNumber;
    u8 playerFacingDirection;
    u8 linkSpriteId;
    u8 i;

    myLinkPlayerNumber = GetMultiplayerId();
    playerFacingDirection = GetPlayerFacingDirection();
    switch (playerFacingDirection)
    {
        case DIR_WEST:
            j = 2;
            x = gSaveBlock1Ptr->pos.x - 1;
            y = gSaveBlock1Ptr->pos.y;
            break;
        case DIR_NORTH:
            j = 1;
            x = gSaveBlock1Ptr->pos.x;
            y = gSaveBlock1Ptr->pos.y - 1;
            break;
        case DIR_EAST:
            x = gSaveBlock1Ptr->pos.x + 1;
            y = gSaveBlock1Ptr->pos.y;
            break;
        case DIR_SOUTH:
            j = 3;
            x = gSaveBlock1Ptr->pos.x;
            y = gSaveBlock1Ptr->pos.y + 1;
    }
    for (i = 0; i < gSpecialVar_0x8004; i++)
    {
        if (myLinkPlayerNumber != i)
        {
            switch ((u8)gLinkPlayers[i].version)
            {
                case VERSION_RUBY:
                case VERSION_SAPPHIRE:
                    if (gLinkPlayers[i].gender == 0)
                        linkSpriteId = OBJ_EVENT_GFX_LINK_RS_BRENDAN;
                    else
                        linkSpriteId = OBJ_EVENT_GFX_LINK_RS_MAY;
                    break;
                case VERSION_EMERALD:
                    if (gLinkPlayers[i].gender == 0)
                        linkSpriteId = OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL;
                    else
                        linkSpriteId = OBJ_EVENT_GFX_RIVAL_MAY_NORMAL;
                    break;
                default:
                    if (gLinkPlayers[i].gender == 0)
                        linkSpriteId = OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL;
                    else
                        linkSpriteId = OBJ_EVENT_GFX_RIVAL_MAY_NORMAL;
                    break;
            }
            SpawnSpecialObjectEventParameterized(linkSpriteId, movementTypes[j], 240 - i, coordOffsets[j][0] + x + 7, coordOffsets[j][1] + y + 7, 0);
            LoadLinkPartnerObjectEventSpritePalette(linkSpriteId, 240 - i, i);
            j++;
            if (j == MAX_LINK_PLAYERS)
            {
                j = 0;
            }
        }
    }
}

static void LoadLinkPartnerObjectEventSpritePalette(u8 graphicsId, u8 localEventId, u8 paletteNum)
{
    u8 adjustedPaletteNum;
    // Note: This temp var is necessary; paletteNum += 6 doesn't match.
    adjustedPaletteNum = paletteNum + 6;
    if (graphicsId == OBJ_EVENT_GFX_LINK_RS_BRENDAN ||
        graphicsId == OBJ_EVENT_GFX_LINK_RS_MAY ||
        graphicsId == OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL ||
        graphicsId == OBJ_EVENT_GFX_RIVAL_MAY_NORMAL)
    {
        u8 obj = GetObjectEventIdByLocalIdAndMap(localEventId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        if (obj != OBJECT_EVENTS_COUNT)
        {
            u8 spriteId = gObjectEvents[obj].spriteId;
            struct Sprite *sprite = &gSprites[spriteId];
            sprite->oam.paletteNum = adjustedPaletteNum;

            switch (graphicsId)
            {
                case OBJ_EVENT_GFX_LINK_RS_BRENDAN:
                    LoadPalette(gObjectEventPalette33, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
                case OBJ_EVENT_GFX_LINK_RS_MAY:
                    LoadPalette(gObjectEventPalette34, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
                case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL:
                    LoadPalette(gObjectEventPalette8, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
                case OBJ_EVENT_GFX_RIVAL_MAY_NORMAL:
                    LoadPalette(gObjectEventPalette17, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
            }
        }
    }
}

// NOTE: Coordinates are +7, +7 from actual in-map coordinates
static const struct UCoords8 sMauvilleGymSwitchCoords[] =
{
    { 7, 22},
    {11, 19},
    {10, 16},
    {15, 16}
};

// Presses the stepped-on switch and raises the rest
void MauvilleGymPressSwitch(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sMauvilleGymSwitchCoords); i++)
    {
        if (i == gSpecialVar_0x8004)
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_ID(MauvilleGym, PressedSwitch));
        else
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_ID(MauvilleGym, RaisedSwitch));
    }
}

// Sets the gym barriers back to the default state; their alt state is handled by MauvilleCity_Gym_EventScript_SetAltBarriers
void MauvilleGymSetDefaultBarriers(void)
{
    int x, y;
    // All switches/barriers are within these coord ranges -7
    for (y = 12; y < 24; y++)
    {
        for (x = 7; x < 16; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
                case METATILE_ID(MauvilleGym, GreenBeamH1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH1_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH2_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH3_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH3_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH4_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH4_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH1_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH1_On));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH2_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH2_On));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH3_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH3_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH4_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH4_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH1_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH2_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH3_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH3_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH4_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH4_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH1_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH1_On));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH2_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH2_On));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH3_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH3_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH4_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH4_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamV1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleBottom_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamV2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, FloorTile));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamV1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleBottom_Off) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, RedBeamV2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, FloorTile));
                    break;
                case METATILE_ID(MauvilleGym, PoleBottom_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamV1_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, FloorTile):
                    if (MapGridGetMetatileIdAt(x, y - 1) == METATILE_ID(MauvilleGym, GreenBeamV1_On))
                        MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamV2_On) | METATILE_COLLISION_MASK);
                    else
                        MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamV2_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, PoleBottom_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamV1_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, PoleTop_Off):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleTop_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, PoleTop_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleTop_Off));
                    break;
            }
        }
    }
}

// Presses all switches and deactivates all beams.
void MauvilleGymDeactivatePuzzle(void)
{
    int i, x, y;
    const struct UCoords8 *switchCoords = sMauvilleGymSwitchCoords;
    for (i = ARRAY_COUNT(sMauvilleGymSwitchCoords) - 1; i >= 0; i--)
    {
        MapGridSetMetatileIdAt(switchCoords->x, switchCoords->y, METATILE_ID(MauvilleGym, PressedSwitch));
        switchCoords++;
    }
    for (y = 12; y < 24; y++)
    {
        for (x = 7; x < 16; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
                case METATILE_ID(MauvilleGym, GreenBeamH1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH1_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH2_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH3_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH3_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamH4_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, GreenBeamH4_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH1_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH2_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH3_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH3_Off));
                    break;
                case METATILE_ID(MauvilleGym, RedBeamH4_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, RedBeamH4_Off));
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamV1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleBottom_On) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, RedBeamV1_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleBottom_Off) | METATILE_COLLISION_MASK);
                    break;
                case METATILE_ID(MauvilleGym, GreenBeamV2_On):
                case METATILE_ID(MauvilleGym, RedBeamV2_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, FloorTile));
                    break;
                case METATILE_ID(MauvilleGym, PoleTop_On):
                    MapGridSetMetatileIdAt(x, y, METATILE_ID(MauvilleGym, PoleTop_Off));
                    break;
            }
        }
    }
}

static const bool8 sSlidingDoorNextFrameDelay[] = {0, 1, 1, 1, 1};

static const u16 sPetalburgGymSlidingDoorMetatiles[] = {
    METATILE_ID(PetalburgGym, SlidingDoor_Frame0),
    METATILE_ID(PetalburgGym, SlidingDoor_Frame1),
    METATILE_ID(PetalburgGym, SlidingDoor_Frame2),
    METATILE_ID(PetalburgGym, SlidingDoor_Frame3),
    METATILE_ID(PetalburgGym, SlidingDoor_Frame4),
};

void PetalburgGymSlideOpenRoomDoors(void)
{
    sSlidingDoorNextFrameCounter = 0;
    sSlidingDoorFrame = 0;
    PlaySE(SE_KI_GASYAN);
    CreateTask(Task_PetalburgGymSlideOpenRoomDoors, 8);
}

static void Task_PetalburgGymSlideOpenRoomDoors(u8 taskId)
{
    if (sSlidingDoorNextFrameDelay[sSlidingDoorFrame] == sSlidingDoorNextFrameCounter)
    {
        PetalburgGymSetDoorMetatiles(gSpecialVar_0x8004, sPetalburgGymSlidingDoorMetatiles[sSlidingDoorFrame]);
        sSlidingDoorNextFrameCounter = 0;
        if ((++sSlidingDoorFrame) == ARRAY_COUNT(sPetalburgGymSlidingDoorMetatiles))
        {
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
    }
    else
    {
        sSlidingDoorNextFrameCounter++;
    }
}

static void PetalburgGymSetDoorMetatiles(u8 roomNumber, u16 metatileId)
{
    u16 doorCoordsX[4];
    u16 doorCoordsY[4];
    u8 i;
    u8 nDoors = 0;
    switch (roomNumber)
    {
        case 1:
            nDoors = 2;
            doorCoordsX[0] = 1;
            doorCoordsX[1] = 7;
            doorCoordsY[0] = 104;
            doorCoordsY[1] = 104;
            break;
        case 2:
            nDoors = 2;
            doorCoordsX[0] = 1;
            doorCoordsX[1] = 7;
            doorCoordsY[0] = 78;
            doorCoordsY[1] = 78;
            break;
        case 3:
            nDoors = 2;
            doorCoordsX[0] = 1;
            doorCoordsX[1] = 7;
            doorCoordsY[0] = 91;
            doorCoordsY[1] = 91;
            break;
        case 4:
            nDoors = 1;
            doorCoordsX[0] = 7;
            doorCoordsY[0] = 39;
            break;
        case 5:
            nDoors = 2;
            doorCoordsX[0] = 1;
            doorCoordsX[1] = 7;
            doorCoordsY[0] = 52;
            doorCoordsY[1] = 52;
            break;
        case 6:
            nDoors = 1;
            doorCoordsX[0] = 1;
            doorCoordsY[0] = 65;
            break;
        case 7:
            nDoors = 1;
            doorCoordsX[0] = 7;
            doorCoordsY[0] = 13;
            break;
        case 8:
            nDoors = 1;
            doorCoordsX[0] = 1;
            doorCoordsY[0] = 26;
            break;
    }
    for (i = 0; i < nDoors; i++)
    {
        MapGridSetMetatileIdAt(doorCoordsX[i] + 7, doorCoordsY[i] + 7, metatileId | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(doorCoordsX[i] + 7, doorCoordsY[i] + 8, (metatileId + 8) | METATILE_COLLISION_MASK);
    }
    DrawWholeMapView();
}

void PetalburgGymUnlockRoomDoors(void)
{
    PetalburgGymSetDoorMetatiles(gSpecialVar_0x8004, sPetalburgGymSlidingDoorMetatiles[4]);
}

void ShowFieldMessageStringVar4(void)
{
    ShowFieldMessage(gStringVar4);
}

void StorePlayerCoordsInVars(void)
{
    gSpecialVar_0x8004 = gSaveBlock1Ptr->pos.x;
    gSpecialVar_0x8005 = gSaveBlock1Ptr->pos.y;
}

u8 GetPlayerTrainerIdOnesDigit(void)
{
    return (u16)((gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0]) % 10;
}

void GetPlayerBigGuyGirlString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        StringCopy(gStringVar1, gText_BigGuy);
    }
    else
    {
        StringCopy(gStringVar1, gText_BigGirl);
    }
}

void GetRivalSonDaughterString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        StringCopy(gStringVar1, gText_Daughter);
    }
    else
    {
        StringCopy(gStringVar1, gText_Son);
    }
}

u8 GetBattleOutcome(void)
{
    return gBattleOutcome;
}

void CableCarWarp(void)
{
    if (gSpecialVar_0x8004 != 0)
    {
        SetWarpDestination(MAP_GROUP(ROUTE112_CABLE_CAR_STATION), MAP_NUM(ROUTE112_CABLE_CAR_STATION), -1, 6, 4);
    }
    else
    {
        SetWarpDestination(MAP_GROUP(MT_CHIMNEY_CABLE_CAR_STATION), MAP_NUM(MT_CHIMNEY_CABLE_CAR_STATION), -1, 6, 4);
    }
}

void SetHiddenItemFlag(void)
{
    FlagSet(gSpecialVar_0x8004);
}

u16 GetWeekCount(void)
{
    u16 weekCount = gLocalTime.days / 7;
    if (weekCount > 9999)
    {
        weekCount = 9999;
    }
    return weekCount;
}

u8 GetLeadMonFriendshipScore(void)
{
    struct Pokemon *pokemon = &gPlayerParty[GetLeadMonIndex()];
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) == MAX_FRIENDSHIP)
    {
        return 6;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 200)
    {
        return 5;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 150)
    {
        return 4;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 100)
    {
        return 3;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 50)
    {
        return 2;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 1)
    {
        return 1;
    }
    return 0;
}

static void CB2_FieldShowRegionMap(void)
{
    FieldInitRegionMap(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void FieldShowRegionMap(void)
{
    SetMainCallback2(CB2_FieldShowRegionMap);
}

void DoPCTurnOnEffect(void)
{
    if (FuncIsActiveTask(Task_PCTurnOnEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_PCTurnOnEffect, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = taskId;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[4] = 0;
    }
}

static void Task_PCTurnOnEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[0] == 0)
    {
        PCTurnOnEffect_0(task);
    }
}

static void PCTurnOnEffect_0(struct Task *task)
{
    u8 playerDirection;
    s8 dx = 0;
    s8 dy = 0;
    if (task->data[3] == 6)
    {
        task->data[3] = 0;
        playerDirection = GetPlayerFacingDirection();
        switch (playerDirection)
        {
            case DIR_NORTH:
                dx = 0;
                dy = -1;
                break;
            case DIR_WEST:
                dx = -1;
                dy = -1;
                break;
            case DIR_EAST:
                dx = 1;
                dy = -1;
                break;
        }
        PCTurnOnEffect_1(task->data[4], dx, dy);
        DrawWholeMapView();
        task->data[4] ^= 1;
        if ((++task->data[2]) == 5)
        {
            DestroyTask(task->data[1]);
        }
    }
    task->data[3]++;
}

static void PCTurnOnEffect_1(s16 isPcTurnedOn, s8 dx, s8 dy)
{
    u16 tileId = 0;
    if (isPcTurnedOn)
    {
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
        {
            tileId = METATILE_ID(Building, PC_Off);
        }
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
        {
            tileId = METATILE_ID(BrendansMaysHouse, BrendanPC_Off);
        }
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
        {
            tileId = METATILE_ID(BrendansMaysHouse, MayPC_Off);
        }
    }
    else
    {
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
        {
            tileId = METATILE_ID(Building, PC_On);
        }
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
        {
            tileId = METATILE_ID(BrendansMaysHouse, BrendanPC_On);
        }
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
        {
            tileId = METATILE_ID(BrendansMaysHouse, MayPC_On);
        }
    }
    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + 7, gSaveBlock1Ptr->pos.y + dy + 7, tileId | METATILE_COLLISION_MASK);
}

void DoPCTurnOffEffect(void)
{
    PCTurnOffEffect();
}

static void PCTurnOffEffect(void)
{
    s8 dx = 0;
    s8 dy = 0;
    u16 tileId = 0;
    u8 playerDirection = GetPlayerFacingDirection();
    switch (playerDirection)
    {
        case DIR_NORTH:
            dx = 0;
            dy = -1;
            break;
        case DIR_WEST:
            dx = -1;
            dy = -1;
            break;
        case DIR_EAST:
            dx = 1;
            dy = -1;
            break;
    }
    if (gSpecialVar_0x8004 == 0)
    {
        tileId = METATILE_ID(Building, PC_Off);
    }
    else if (gSpecialVar_0x8004 == 1)
    {
        tileId = METATILE_ID(BrendansMaysHouse, BrendanPC_Off);
    }
    else if (gSpecialVar_0x8004 == 2)
    {
        tileId = METATILE_ID(BrendansMaysHouse, MayPC_Off);
    }
    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + 7, gSaveBlock1Ptr->pos.y + dy + 7, tileId | METATILE_COLLISION_MASK);
    DrawWholeMapView();
}

void DoLotteryCornerComputerEffect(void)
{
    if (FuncIsActiveTask(Task_LotteryCornerComputerEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_LotteryCornerComputerEffect, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = taskId;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[4] = 0;
    }
}

static void Task_LotteryCornerComputerEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[0] == 0)
    {
        LotteryCornerComputerEffect(task);
    }
}

static void LotteryCornerComputerEffect(struct Task *task)
{
    if (task->data[3] == 6)
    {
        task->data[3] = 0;
        if (task->data[4] != 0)
        {
            MapGridSetMetatileIdAt(18, 8, METATILE_ID(Shop, Laptop1_Normal) | METATILE_COLLISION_MASK);
            MapGridSetMetatileIdAt(18, 9, METATILE_ID(Shop, Laptop2_Normal) | METATILE_COLLISION_MASK);
        }
        else
        {
            MapGridSetMetatileIdAt(18, 8, METATILE_ID(Shop, Laptop1_Flash) | METATILE_COLLISION_MASK);
            MapGridSetMetatileIdAt(18, 9, METATILE_ID(Shop, Laptop2_Flash) | METATILE_COLLISION_MASK);
        }
        DrawWholeMapView();
        task->data[4] ^= 1;
        if ((++task->data[2]) == 5)
        {
            DestroyTask(task->data[1]);
        }
    }
    task->data[3]++;
}

void EndLotteryCornerComputerEffect(void)
{
    MapGridSetMetatileIdAt(18, 8, METATILE_ID(Shop, Laptop1_Normal) | METATILE_COLLISION_MASK);
    MapGridSetMetatileIdAt(18, 9, METATILE_ID(Shop, Laptop2_Normal) | METATILE_COLLISION_MASK);
    DrawWholeMapView();
}

void SetTrickHouseNuggetFlag(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET;
    *specVar = flag;
    FlagSet(flag);
}

void ResetTrickHouseNuggetFlag(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET;
    *specVar = flag;
    FlagClear(flag);
}

bool8 CheckLeadMonCool(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_COOL) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonBeauty(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_BEAUTY) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonCute(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_CUTE) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonSmart(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_SMART) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonTough(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_TOUGH) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

void IsGrassTypeInParty(void)
{
    u8 i;
    u16 species;
    struct Pokemon *pokemon;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData(pokemon, MON_DATA_SPECIES);
            if (gBaseStats[species].type1 == TYPE_GRASS || gBaseStats[species].type2 == TYPE_GRASS)
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }
    gSpecialVar_Result = FALSE;
}

void SpawnCameraObject(void)
{
    u8 obj = SpawnSpecialObjectEventParameterized(OBJ_EVENT_GFX_BOY_1, MOVEMENT_TYPE_FACE_DOWN, OBJ_EVENT_ID_CAMERA, gSaveBlock1Ptr->pos.x + 7, gSaveBlock1Ptr->pos.y + 7, 3);
    gObjectEvents[obj].invisible = TRUE;
    CameraObjectSetFollowedObjectId(gObjectEvents[obj].spriteId);
}

void RemoveCameraObject(void)
{
    CameraObjectSetFollowedObjectId(GetPlayerAvatarObjectId());
    RemoveObjectEventByLocalIdAndMap(OBJ_EVENT_ID_CAMERA, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

u8 GetPokeblockNameByMonNature(void)
{
    return CopyMonFavoritePokeblockName(GetNature(&gPlayerParty[GetLeadMonIndex()]), gStringVar1);
}

void GetSecretBaseNearbyMapName(void)
{
    GetMapName(gStringVar1, VarGet(VAR_SECRET_BASE_MAP), 0);
}

u16 GetBestBattleTowerStreak(void)
{
    return GetGameStat(GAME_STAT_BATTLE_TOWER_BEST_STREAK);
}

void BufferEReaderTrainerName(void)
{
    GetEreaderTrainerName(gStringVar1);
}

u16 GetSlotMachineId(void)
{
    static const u8 sSlotMachineRandomSeeds[] = {12, 2, 4, 5, 1, 8, 7, 11, 3, 10, 9, 6};
    static const u8 sSlotMachineIds[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    static const u8 sSlotMachineServiceDayIds[] = {3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5};

    u32 rnd = gSaveBlock1Ptr->easyChatPairs[0].unk0_0 + gSaveBlock1Ptr->easyChatPairs[0].unk2 + sSlotMachineRandomSeeds[gSpecialVar_0x8004];
    if (GetPriceReduction(POKENEWS_GAME_CORNER))
    {
        return sSlotMachineServiceDayIds[rnd % SLOT_MACHINE_COUNT];
    }
    return sSlotMachineIds[rnd % SLOT_MACHINE_COUNT];
}

bool8 FoundAbandonedShipRoom1Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 FoundAbandonedShipRoom2Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 FoundAbandonedShipRoom4Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 FoundAbandonedShipRoom6Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 LeadMonHasEffortRibbon(void)
{
    return GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_EFFORT_RIBBON, NULL);
}

void GiveLeadMonEffortRibbon(void)
{
    bool8 ribbonSet;
    struct Pokemon *leadMon;
    IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
    FlagSet(FLAG_SYS_RIBBON_GET);
    ribbonSet = TRUE;
    leadMon = &gPlayerParty[GetLeadMonIndex()];
    SetMonData(leadMon, MON_DATA_EFFORT_RIBBON, &ribbonSet);
    if (GetRibbonCount(leadMon) > NUM_CUTIES_RIBBONS)
    {
        TryPutSpotTheCutiesOnAir(leadMon, 0x47);
    }
}

bool8 Special_AreLeadMonEVsMaxedOut(void)
{
    if (GetMonEVCount(&gPlayerParty[GetLeadMonIndex()]) >= 510)
    {
        return TRUE;
    }
    return FALSE;
}

u8 TryUpdateRusturfTunnelState(void)
{
    if (!FlagGet(FLAG_RUSTURF_TUNNEL_OPENED) 
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(RUSTURF_TUNNEL) 
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(RUSTURF_TUNNEL))
    {
        if (FlagGet(FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1))
        {
            VarSet(VAR_RUSTURF_TUNNEL_STATE, 4);
            return TRUE;
        }
        else if (FlagGet(FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2))
        {
            VarSet(VAR_RUSTURF_TUNNEL_STATE, 5);
            return TRUE;
        }
    }
    return FALSE;
}

void SetShoalItemFlag(u16 unused)
{
    FlagSet(FLAG_SYS_SHOAL_ITEM);
}

void PutZigzagoonInPlayerParty(void)
{
    u16 monData;
    CreateMon(&gPlayerParty[0], SPECIES_ZIGZAGOON, 7, 32, FALSE, 0, OT_ID_PLAYER_ID, 0);
    monData = TRUE;
    SetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM, &monData);
    monData = MOVE_TACKLE;
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE1, &monData);
    monData = MOVE_NONE;
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE2, &monData);
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE3, &monData);
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE4, &monData);
}

bool8 IsStarterInParty(void)
{
    u8 i;
    u16 starter = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == starter)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 ScriptCheckFreePokemonStorageSpace(void)
{
    return CheckFreePokemonStorageSpace();
}

bool8 IsPokerusInParty(void)
{
    if (!CheckPartyPokerus(gPlayerParty, 0x3f))
    {
        return FALSE;
    }
    return TRUE;
}

#define horizontalPan  data[0]
#define delayCounter   data[1]
#define numShakes      data[2]
#define delay          data[3]
#define verticalPan    data[4]

void ShakeCamera(void)
{
    u8 taskId = CreateTask(Task_ShakeCamera, 9);
    gTasks[taskId].horizontalPan = gSpecialVar_0x8005;
    gTasks[taskId].delayCounter = 0;
    gTasks[taskId].numShakes = gSpecialVar_0x8006;
    gTasks[taskId].delay = gSpecialVar_0x8007;
    gTasks[taskId].verticalPan = gSpecialVar_0x8004;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_W070);
}

static void Task_ShakeCamera(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    delayCounter++;
    if (delayCounter % delay == 0)
    {
        delayCounter = 0;
        numShakes--;
        horizontalPan = -horizontalPan;
        verticalPan = -verticalPan;
        SetCameraPanning(horizontalPan, verticalPan);
        if (numShakes == 0)
        {
            StopCameraShake(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void StopCameraShake(u8 taskId)
{
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

#undef horizontalPan
#undef delayCounter
#undef numShakes
#undef delay
#undef verticalPan

bool8 FoundBlackGlasses(void)
{
    return FlagGet(FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES);
}

void SetRoute119Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
    {
        SetSav1Weather(WEATHER_ROUTE119_CYCLE);
    }
}

void SetRoute123Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
    {
        SetSav1Weather(WEATHER_ROUTE123_CYCLE);
    }
}

u8 GetLeadMonIndex(void)
{
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != 0)
        {
            return i;
        }
    }
    return 0;
}

u16 ScriptGetPartyMonSpecies(void)
{
    return GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES2, NULL);
}

// Removed for Emerald
void TryInitBattleTowerAwardManObjectEvent(void)
{
    //TryInitLocalObjectEvent(6);
}

u16 GetDaysUntilPacifidlogTMAvailable(void)
{
    u16 tmReceivedDay = VarGet(VAR_PACIFIDLOG_TM_RECEIVED_DAY);
    if (gLocalTime.days - tmReceivedDay >= 7)
    {
        return 0;
    }
    else if (gLocalTime.days < 0)
    {
        return 8;
    }
    return 7 - (gLocalTime.days - tmReceivedDay);
}

u16 SetPacifidlogTMReceivedDay(void)
{
    VarSet(VAR_PACIFIDLOG_TM_RECEIVED_DAY, gLocalTime.days);
    return gLocalTime.days;
}

bool8 MonOTNameNotPlayer(void)
{
    if (GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LANGUAGE) != GAME_LANGUAGE)
        return TRUE;

    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_OT_NAME, gStringVar1);

    if (!StringCompare(gSaveBlock2Ptr->playerName, gStringVar1))
        return FALSE;

    return TRUE;
}

void BufferLottoTicketNumber(void)
{
    if (gSpecialVar_Result >= 10000)
    {
        TV_PrintIntToStringVar(0, gSpecialVar_Result);
    }
    else if (gSpecialVar_Result >= 1000)
    {
        gStringVar1[0] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 1, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 100)
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 2, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 10)
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        gStringVar1[2] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 3, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        gStringVar1[2] = CHAR_0;
        gStringVar1[3] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 4, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
}

u16 GetMysteryEventCardVal(void)
{
    switch (gSpecialVar_Result)
    {
        case GET_NUM_STAMPS:
            return mevent_081445C0(GET_NUM_STAMPS_INTERNAL);
        case GET_MAX_STAMPS:
            return mevent_081445C0(GET_MAX_STAMPS_INTERNAL);
        case GET_CARD_BATTLES_WON:
            return mevent_081445C0(GET_CARD_BATTLES_WON_INTERNAL);
        case 3: // Never occurs
            return mevent_081445C0(1);
        case 4: // Never occurs
            return mevent_081445C0(2);
        default:
            return 0;
    }
}

bool8 BufferTMHMMoveName(void)
{
    if (gSpecialVar_0x8004 >= ITEM_TM01 && gSpecialVar_0x8004 <= ITEM_HM08)
    {
        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(gSpecialVar_0x8004)]);
        return TRUE;
    }

    return FALSE;
}

bool8 IsBadEggInParty(void)
{
    u8 partyCount = CalculatePlayerPartyCount();
    u8 i;

    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_BAD_EGG) == TRUE)
            return TRUE;
    }

    return FALSE;
}

bool8 InMultiPartnerRoom(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM) &&
        VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_MULTIS)
        return TRUE;
    return FALSE;
}

void OffsetCameraForBattle(void)
{
    SetCameraPanningCallback(NULL);
    SetCameraPanning(8, 0);
}

const struct WindowTemplate gElevatorFloor_WindowTemplate = 
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 1,
    .width = 8,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 8,
};

const u8 *const gDeptStoreFloorNames[] =
{
    [DEPT_STORE_FLOORNUM_B4F] = gText_B4F,
    [DEPT_STORE_FLOORNUM_B3F] = gText_B3F,
    [DEPT_STORE_FLOORNUM_B2F] = gText_B2F,
    [DEPT_STORE_FLOORNUM_B1F] = gText_B1F,
    [DEPT_STORE_FLOORNUM_1F] = gText_1F,
    [DEPT_STORE_FLOORNUM_2F] = gText_2F,
    [DEPT_STORE_FLOORNUM_3F] = gText_3F,
    [DEPT_STORE_FLOORNUM_4F] = gText_4F,
    [DEPT_STORE_FLOORNUM_5F] = gText_5F,
    [DEPT_STORE_FLOORNUM_6F] = gText_6F,
    [DEPT_STORE_FLOORNUM_7F] = gText_7F,
    [DEPT_STORE_FLOORNUM_8F] = gText_8F,
    [DEPT_STORE_FLOORNUM_9F] = gText_9F,
    [DEPT_STORE_FLOORNUM_10F] = gText_10F,
    [DEPT_STORE_FLOORNUM_11F] = gText_11F,
    [DEPT_STORE_FLOORNUM_ROOFTOP] = gText_Rooftop
};

static const u16 sElevatorWindowTiles_Ascending[][3] =
{
    {
        METATILE_ID(BattleFrontier, Elevator_Top0),
        METATILE_ID(BattleFrontier, Elevator_Top1),
        METATILE_ID(BattleFrontier, Elevator_Top2)
    },
    {
        METATILE_ID(BattleFrontier, Elevator_Mid0),
        METATILE_ID(BattleFrontier, Elevator_Mid1),
        METATILE_ID(BattleFrontier, Elevator_Mid2)
    },
    {
        METATILE_ID(BattleFrontier, Elevator_Bottom0),
        METATILE_ID(BattleFrontier, Elevator_Bottom1),
        METATILE_ID(BattleFrontier, Elevator_Bottom2)
    },
};

static const u16 sElevatorWindowTiles_Descending[][3] =
{
    {
        METATILE_ID(BattleFrontier, Elevator_Top0),
        METATILE_ID(BattleFrontier, Elevator_Top2),
        METATILE_ID(BattleFrontier, Elevator_Top1)
    },
    {
        METATILE_ID(BattleFrontier, Elevator_Mid0),
        METATILE_ID(BattleFrontier, Elevator_Mid2),
        METATILE_ID(BattleFrontier, Elevator_Mid1)
    },
    {
        METATILE_ID(BattleFrontier, Elevator_Bottom0),
        METATILE_ID(BattleFrontier, Elevator_Bottom2),
        METATILE_ID(BattleFrontier, Elevator_Bottom1)
    },
};

void SetDeptStoreFloor(void)
{
    u8 deptStoreFloor;
    switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
    {
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_1F):
            deptStoreFloor = DEPT_STORE_FLOORNUM_1F;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_2F):
            deptStoreFloor = DEPT_STORE_FLOORNUM_2F;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_3F):
            deptStoreFloor = DEPT_STORE_FLOORNUM_3F;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_4F):
            deptStoreFloor = DEPT_STORE_FLOORNUM_4F;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_5F):
            deptStoreFloor = DEPT_STORE_FLOORNUM_5F;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP):
            deptStoreFloor = DEPT_STORE_FLOORNUM_ROOFTOP;
            break;
        default:
            deptStoreFloor = DEPT_STORE_FLOORNUM_1F;
            break;
    }
    VarSet(VAR_DEPT_STORE_FLOOR, deptStoreFloor);
}

u16 GetDeptStoreDefaultFloorChoice(void)
{
    sLilycoveDeptStore_NeverRead = 0;
    sLilycoveDeptStore_DefaultFloorChoice = 0;

    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(LILYCOVE_CITY_DEPARTMENT_STORE_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_5F):
                sLilycoveDeptStore_NeverRead = 0;
                sLilycoveDeptStore_DefaultFloorChoice = 0;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_4F):
                sLilycoveDeptStore_NeverRead = 0;
                sLilycoveDeptStore_DefaultFloorChoice = 1;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_3F):
                sLilycoveDeptStore_NeverRead = 0;
                sLilycoveDeptStore_DefaultFloorChoice = 2;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_2F):
                sLilycoveDeptStore_NeverRead = 0;
                sLilycoveDeptStore_DefaultFloorChoice = 3;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_1F):
                sLilycoveDeptStore_NeverRead = 0;
                sLilycoveDeptStore_DefaultFloorChoice = 4;
                break;
        }
    }

    return sLilycoveDeptStore_DefaultFloorChoice;
}

void MoveElevator(void)
{
    static const u8 sElevatorTripLength[] = { 8, 16, 24, 32, 38, 46, 52, 56, 57 };

    s16 *data = gTasks[CreateTask(Task_MoveElevator, 9)].data;
    u16 floorDelta;

    data[1] = 0;
    data[2] = 0;
    data[4] = 1;

    // descending
    if (gSpecialVar_0x8005 > gSpecialVar_0x8006)
    {
        floorDelta = gSpecialVar_0x8005 - gSpecialVar_0x8006;
        data[6] = TRUE;
    }
    else
    {
        floorDelta = gSpecialVar_0x8006 - gSpecialVar_0x8005;
        data[6] = FALSE;
    }

    if (floorDelta > 8)
        floorDelta = 8;

    data[5] = sElevatorTripLength[floorDelta];

    SetCameraPanningCallback(NULL);
    MoveElevatorWindowLights(floorDelta, data[6]);
    PlaySE(SE_ELEBETA);
}

static void Task_MoveElevator(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1]++;
    if (data[1] % 3 == 0)
    {
        data[1] = 0;
        data[2]++;
        data[4] = -data[4];
        SetCameraPanning(0, data[4]);

        // arrived at floor
        if (data[2] == data[5])
        {
            PlaySE(SE_PINPON);
            DestroyTask(taskId);
            EnableBothScriptContexts();
            InstallCameraPanAheadCallback();
        }
    }
}

void ShowDeptStoreElevatorFloorSelect(void)
{
    int xPos;

    sTutorMoveAndElevatorWindowId = AddWindow(&gElevatorFloor_WindowTemplate);
    SetStandardWindowBorderStyle(sTutorMoveAndElevatorWindowId, 0);

    xPos = GetStringCenterAlignXOffset(1, gText_ElevatorNowOn, 64);
    AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, 1, gText_ElevatorNowOn, xPos, 1, TEXT_SPEED_FF, NULL);

    xPos = GetStringCenterAlignXOffset(1, gDeptStoreFloorNames[gSpecialVar_0x8005], 64);
    AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, 1, gDeptStoreFloorNames[gSpecialVar_0x8005], xPos, 17, TEXT_SPEED_FF, NULL);

    PutWindowTilemap(sTutorMoveAndElevatorWindowId);
    CopyWindowToVram(sTutorMoveAndElevatorWindowId, 3);
}

void CloseDeptStoreElevatorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sTutorMoveAndElevatorWindowId, TRUE);
    RemoveWindow(sTutorMoveAndElevatorWindowId);
}

static void MoveElevatorWindowLights(u16 floorDelta, bool8 descending)
{
    static const u8 sElevatorLightCycles[] = { 3, 6, 9, 12, 15, 18, 21, 24, 27 };

    if (FuncIsActiveTask(Task_MoveElevatorWindowLights) != TRUE)
    {
        u8 taskId = CreateTask(Task_MoveElevatorWindowLights, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = descending;
        gTasks[taskId].data[3] = sElevatorLightCycles[floorDelta];
    }
}

static void Task_MoveElevatorWindowLights(u8 taskId)
{
    u8 x, y;
    s16 *data = gTasks[taskId].data;

    if (data[1] == 6)
    {
        data[0]++;

        // ascending
        if (data[2] == FALSE)
        {
            for (y = 0; y < 3; y++)
            {
                for (x = 0; x < 3; x++)
                {
                    MapGridSetMetatileIdAt(x + 8, y + 7, sElevatorWindowTiles_Ascending[y][data[0] % 3] | METATILE_COLLISION_MASK);
                }
            }
        }
        // descending
        else
        {
            for (y = 0; y < 3; y++)
            {
                for (x = 0; x < 3; x++)
                {
                    MapGridSetMetatileIdAt(x + 8, y + 7, sElevatorWindowTiles_Descending[y][data[0] % 3] | METATILE_COLLISION_MASK);
                }
            }
        }
        DrawWholeMapView();
        data[1] = 0;
        if (data[0] == data[3])
        {
            DestroyTask(taskId);
        }
    }
    data[1]++;
}

void BufferVarsForIVRater(void)
{
    u8 i;
    u32 ivStorage[NUM_STATS];

    ivStorage[STAT_HP] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV);
    ivStorage[STAT_ATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV);
    ivStorage[STAT_DEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV);
    ivStorage[STAT_SPEED] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV);
    ivStorage[STAT_SPATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV);
    ivStorage[STAT_SPDEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV);

    gSpecialVar_0x8005 = 0;

    for (i = 0; i < NUM_STATS; i++)
    {
        gSpecialVar_0x8005 += ivStorage[i];
    }

    gSpecialVar_0x8006 = 0;
    gSpecialVar_0x8007 = ivStorage[STAT_HP];

    for (i = 1; i < NUM_STATS; i++)
    {
        if (ivStorage[gSpecialVar_0x8006] < ivStorage[i])
        {
            gSpecialVar_0x8006 = i;
            gSpecialVar_0x8007 = ivStorage[i];
        }
        else if (ivStorage[gSpecialVar_0x8006] == ivStorage[i])
        {
            u16 randomNumber = Random();
            if (randomNumber & 1)
            {
                gSpecialVar_0x8006 = i;
                gSpecialVar_0x8007 = ivStorage[i];
            }
        }
    }
}

bool8 UsedPokemonCenterWarp(void)
{
    static const u16 sPokemonCenters[] = 
    { 
        MAP_OLDALE_TOWN_POKEMON_CENTER_1F, 
        MAP_DEWFORD_TOWN_POKEMON_CENTER_1F, 
        MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F, 
        MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F, 
        MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F, 
        MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F, 
        MAP_PETALBURG_CITY_POKEMON_CENTER_1F, 
        MAP_SLATEPORT_CITY_POKEMON_CENTER_1F, 
        MAP_MAUVILLE_CITY_POKEMON_CENTER_1F, 
        MAP_RUSTBORO_CITY_POKEMON_CENTER_1F, 
        MAP_FORTREE_CITY_POKEMON_CENTER_1F, 
        MAP_LILYCOVE_CITY_POKEMON_CENTER_1F, 
        MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F, 
        MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F, 
        MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F, 
        MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F, 
        MAP_BATTLE_FRONTIER_POKEMON_CENTER_1F, 
        MAP_UNION_ROOM, 
        0xFFFF 
    };

    int i;
    u16 map = (gLastUsedWarp.mapGroup << 8) + gLastUsedWarp.mapNum;

    for (i = 0; sPokemonCenters[i] != 0xFFFF; i++)
    {
        if (sPokemonCenters[i] == map)
            return TRUE;
    }

    return FALSE;
}

bool32 PlayerNotAtTrainerHillEntrance(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(TRAINER_HILL_ENTRANCE) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(TRAINER_HILL_ENTRANCE))
    {
        return FALSE;
    }
    return TRUE;
}

void UpdateFrontierManiac(u16 daysSince)
{
    u16 *var = GetVarPointer(VAR_FRONTIER_MANIAC_FACILITY);
    *var += daysSince;
    *var %= FRONTIER_MANIAC_FACILITY_COUNT;
}

void ShowFrontierManiacMessage(void)
{
    static const u8 *const sFrontierManiacMessages[][FRONTIER_MANIAC_MESSAGE_COUNT] = 
    {
        [FRONTIER_MANIAC_BATTLE_TOWER_SINGLES] =
        { 
            BattleFrontier_Lounge2_Text_SalonMaidenIsThere, 
            BattleFrontier_Lounge2_Text_SalonMaidenSilverMons, 
            BattleFrontier_Lounge2_Text_SalonMaidenGoldMons 
        },
        [FRONTIER_MANIAC_BATTLE_TOWER_DOUBLES] =
        { 
            BattleFrontier_Lounge2_Text_DoubleBattleAdvice1, 
            BattleFrontier_Lounge2_Text_DoubleBattleAdvice2, 
            BattleFrontier_Lounge2_Text_DoubleBattleAdvice3 
        },
        [FRONTIER_MANIAC_BATTLE_TOWER_MULTIS] = 
        { 
            BattleFrontier_Lounge2_Text_MultiBattleAdvice, 
            BattleFrontier_Lounge2_Text_MultiBattleAdvice, 
            BattleFrontier_Lounge2_Text_MultiBattleAdvice 
        },
        [FRONTIER_MANIAC_BATTLE_TOWER_LINK] =
        { 
            BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice, 
            BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice, 
            BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice 
        },
        [FRONTIER_MANIAC_BATTLE_DOME] =
        { 
            BattleFrontier_Lounge2_Text_DomeAceIsThere, 
            BattleFrontier_Lounge2_Text_DomeAceSilverMons, 
            BattleFrontier_Lounge2_Text_DomeAceGoldMons 
        },
        [FRONTIER_MANIAC_BATTLE_FACTORY] =
        { 
            BattleFrontier_Lounge2_Text_FactoryHeadIsThere, 
            BattleFrontier_Lounge2_Text_FactoryHeadSilverMons, 
            BattleFrontier_Lounge2_Text_FactoryHeadGoldMons 
        },
        [FRONTIER_MANIAC_BATTLE_PALACE] =
        { 
            BattleFrontier_Lounge2_Text_PalaceMavenIsThere, 
            BattleFrontier_Lounge2_Text_PalaceMavenSilverMons, 
            BattleFrontier_Lounge2_Text_PalaceMavenGoldMons 
        },
        [FRONTIER_MANIAC_BATTLE_ARENA] =
        { 
            BattleFrontier_Lounge2_Text_ArenaTycoonIsThere, 
            BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons, 
            BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons 
        },
        [FRONTIER_MANIAC_BATTLE_PIKE] = 
        { 
            BattleFrontier_Lounge2_Text_PikeQueenIsThere, 
            BattleFrontier_Lounge2_Text_PikeQueenSilverMons, 
            BattleFrontier_Lounge2_Text_PikeQueenGoldMons 
        },
        [FRONTIER_MANIAC_BATTLE_PYRAMID] =
        { 
            BattleFrontier_Lounge2_Text_PyramidKingIsThere, 
            BattleFrontier_Lounge2_Text_PyramidKingSilverMons, 
            BattleFrontier_Lounge2_Text_PyramidKingGoldMons 
        },
    };

    static const u8 sFrontierManiacStreakThresholds[][FRONTIER_MANIAC_MESSAGE_COUNT - 1] = 
    {
        [FRONTIER_MANIAC_BATTLE_TOWER_SINGLES] = { 21, 56 },
        [FRONTIER_MANIAC_BATTLE_TOWER_DOUBLES] = { 21, 35 },
        [FRONTIER_MANIAC_BATTLE_TOWER_MULTIS]  = { 255, 255 },
        [FRONTIER_MANIAC_BATTLE_TOWER_LINK]    = { 255, 255 },
        [FRONTIER_MANIAC_BATTLE_DOME]          = { 2, 4 },
        [FRONTIER_MANIAC_BATTLE_FACTORY]       = { 7, 21 },
        [FRONTIER_MANIAC_BATTLE_PALACE]        = { 7, 21 },
        [FRONTIER_MANIAC_BATTLE_ARENA]         = { 14, 28 },
        [FRONTIER_MANIAC_BATTLE_PIKE]          = { 13, 112 }, //BUG: 112 (0x70) is probably a mistake; the Pike Queen is battled twice well before that
        [FRONTIER_MANIAC_BATTLE_PYRAMID]       = { 7, 56 }
    };

    u8 i;
    u16 winStreak = 0;
    u16 facility = VarGet(VAR_FRONTIER_MANIAC_FACILITY);

    switch (facility)
    {
        case FRONTIER_MANIAC_BATTLE_TOWER_SINGLES:
        case FRONTIER_MANIAC_BATTLE_TOWER_DOUBLES:
        case FRONTIER_MANIAC_BATTLE_TOWER_MULTIS:
        case FRONTIER_MANIAC_BATTLE_TOWER_LINK:
            if (gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_OPEN];
            }
            break;
        case FRONTIER_MANIAC_BATTLE_DOME:
            if (gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN];
            }
            break;
        case FRONTIER_MANIAC_BATTLE_FACTORY:
            if (gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN];
            }
            break;
        case FRONTIER_MANIAC_BATTLE_PALACE:
            if (gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN];
            }
            break;
        case FRONTIER_MANIAC_BATTLE_ARENA:
            if (gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_OPEN];
            }
            break;
        case FRONTIER_MANIAC_BATTLE_PIKE:
            if (gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_OPEN];
            }
            break;
        case FRONTIER_MANIAC_BATTLE_PYRAMID:
            if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50] 
                >= gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN])
            {
                winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50];
            }
            else
            {
                winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN];
            }
            break;
    }

    for (i = 0; i < FRONTIER_MANIAC_MESSAGE_COUNT - 1 && sFrontierManiacStreakThresholds[facility][i] < winStreak; i++);

    ShowFieldMessage(sFrontierManiacMessages[facility][i]);
}

// gSpecialVar_0x8005 and 0x8006 here are used by MoveElevator
void BufferBattleTowerElevatorFloors(void)
{
    static const u16 sBattleTowerStreakThresholds[] = {
        7, 14, 21, 28, 35, 49, 63, 77, 91, 0
    };

    u8 i;
    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (battleMode == FRONTIER_MODE_MULTIS && !FlagGet(FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER))
    {
        gSpecialVar_0x8005 = 5;
        gSpecialVar_0x8006 = 4;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(sBattleTowerStreakThresholds) - 1; i++)
    {
        if (sBattleTowerStreakThresholds[i] > gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode])
        {
            gSpecialVar_0x8005 = 4;
            gSpecialVar_0x8006 = i + 5;
            return;
        }
    }

    gSpecialVar_0x8005 = 4;
    gSpecialVar_0x8006 = 12;
}

// Scrollable Multichoice task data defines
#define tMaxItemsOnScreen    data[0]
#define tNumItems            data[1]
#define tLeft                data[2]
#define tTop                 data[3]
#define tWidth               data[4]
#define tHeight              data[5]
#define tKeepOpenAfterSelect data[6]
#define tScrollOffset        data[7]
#define tSelectedRow         data[8]
#define tScrollMultiId       data[11]
#define tScrollArrowId       data[12]
#define tWindowId            data[13]
#define tListTaskId          data[14]
#define tTaskId              data[15]
// data[9] and [10] unused

void ShowScrollableMultichoice(void)
{
    u8 taskId = CreateTask(Task_ShowScrollableMultichoice, 8);
    struct Task *task = &gTasks[taskId];
    task->tScrollMultiId = gSpecialVar_0x8004;

    switch (gSpecialVar_0x8004)
    {
        case SCROLL_MULTI_NONE:
            task->tMaxItemsOnScreen = 1;
            task->tNumItems = 1;
            task->tLeft = 1;
            task->tTop = 1;
            task->tWidth = 1;
            task->tHeight = 1;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_GLASS_WORKSHOP_VENDOR:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN - 1;
            task->tNumItems = 8;
            task->tLeft = 1;
            task->tTop = 1;
            task->tWidth = 9;
            task->tHeight = 10;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_POKEMON_FAN_CLUB_RATER:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 12;
            task->tLeft = 1;
            task->tTop = 1;
            task->tWidth = 7;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 11;
            task->tLeft = 14;
            task->tTop = 1;
            task->tWidth = 15;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 6;
            task->tLeft = 14;
            task->tTop = 1;
            task->tWidth = 15;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 7;
            task->tLeft = 14;
            task->tTop = 1;
            task->tWidth = 15;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 10;
            task->tLeft = 14;
            task->tTop = 1;
            task->tWidth = 15;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BERRY_POWDER_VENDOR:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 12;
            task->tLeft = 15;
            task->tTop = 1;
            task->tWidth = 14;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BF_RECEPTIONIST:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 10;
            task->tLeft = 17;
            task->tTop = 1;
            task->tWidth = 11;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BF_MOVE_TUTOR_1:
        case SCROLL_MULTI_BF_MOVE_TUTOR_2:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 11;
            task->tLeft = 15;
            task->tTop = 1;
            task->tWidth = 14;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_SS_TIDAL_DESTINATION:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 7;
            task->tLeft = 19;
            task->tTop = 1;
            task->tWidth = 10;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        case SCROLL_MULTI_BATTLE_TENT_RULES:
            task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
            task->tNumItems = 7;
            task->tLeft = 17;
            task->tTop = 1;
            task->tWidth = 12;
            task->tHeight = 12;
            task->tKeepOpenAfterSelect = FALSE;
            task->tTaskId = taskId;
            break;
        default:
            gSpecialVar_Result = MULTI_B_PRESSED;
            DestroyTask(taskId);
            break;
    }
}

static const u8 *const sScrollableMultichoiceOptions[][MAX_SCROLL_MULTI_LENGTH] = 
{
    [SCROLL_MULTI_NONE] = 
    {
        gText_Exit
    },
    [SCROLL_MULTI_GLASS_WORKSHOP_VENDOR] = 
    {
        gText_BlueFlute,
        gText_YellowFlute,
        gText_RedFlute,
        gText_WhiteFlute,
        gText_BlackFlute,
        gText_PrettyChair,
        gText_PrettyDesk,
        gText_Exit
    },
    [SCROLL_MULTI_POKEMON_FAN_CLUB_RATER] = 
    {
        gText_0Pts,
        gText_10Pts,
        gText_20Pts,
        gText_30Pts,
        gText_40Pts,
        gText_50Pts,
        gText_60Pts,
        gText_70Pts,
        gText_80Pts,
        gText_90Pts,
        gText_100Pts,
        gText_QuestionMark
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1] = 
    {
        gText_KissPoster16BP,
        gText_KissCushion32BP,
        gText_SmoochumDoll32BP,
        gText_TogepiDoll48BP,
        gText_MeowthDoll48BP,
        gText_ClefairyDoll48BP,
        gText_DittoDoll48BP,
        gText_CyndaquilDoll80BP,
        gText_ChikoritaDoll80BP,
        gText_TotodileDoll80BP,
        gText_Exit
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2] =
    {
        gText_LaprasDoll128BP,
        gText_SnorlaxDoll128BP,
        gText_VenusaurDoll256BP,
        gText_CharizardDoll256BP,
        gText_BlastoiseDoll256BP,
        gText_Exit
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR] =
    {
        gText_Protein1BP,
        gText_Calcium1BP,
        gText_Iron1BP,
        gText_Zinc1BP,
        gText_Carbos1BP,
        gText_HpUp1BP,
        gText_Exit
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR] =
    {
        gText_Leftovers48BP,
        gText_WhiteHerb48BP,
        gText_QuickClaw48BP,
        gText_MentalHerb48BP,
        gText_BrightPowder64BP,
        gText_ChoiceBand64BP,
        gText_KingsRock64BP,
        gText_FocusBand64BP,
        gText_ScopeLens64BP,
        gText_Exit
    },
    [SCROLL_MULTI_BERRY_POWDER_VENDOR] =
    {
        gText_EnergyPowder50,
        gText_EnergyRoot80,
        gText_HealPowder50,
        gText_RevivalHerb300,
        gText_Protein1000,
        gText_Iron1000,
        gText_Carbos1000,
        gText_Calcium1000,
        gText_Zinc1000,
        gText_HPUp1000,
        gText_PPUp3000,
        gText_Exit
    },
    [SCROLL_MULTI_BF_RECEPTIONIST] =
    {
        gText_BattleTower2,
        gText_BattleDome,
        gText_BattlePalace,
        gText_BattleArena,
        gText_BattleFactory,
        gText_BattlePike,
        gText_BattlePyramid,
        gText_RankingHall,
        gText_ExchangeService,
        gText_Exit
    },
    [SCROLL_MULTI_BF_MOVE_TUTOR_1] = 
    {
        gText_Softboiled16BP,
        gText_SeismicToss24BP,
        gText_DreamEater24BP,
        gText_MegaPunch24BP,
        gText_MegaKick48BP,
        gText_BodySlam48BP,
        gText_RockSlide48BP,
        gText_Counter48BP,
        gText_ThunderWave48BP,
        gText_SwordsDance48BP,
        gText_Exit
    },
    [SCROLL_MULTI_BF_MOVE_TUTOR_2] = 
    {
        gText_DefenseCurl16BP,
        gText_Snore24BP,
        gText_MudSlap24BP,
        gText_Swift24BP,
        gText_IcyWind24BP,
        gText_Endure48BP,
        gText_PsychUp48BP,
        gText_IcePunch48BP,
        gText_ThunderPunch48BP,
        gText_FirePunch48BP,
        gText_Exit
    },
    [SCROLL_MULTI_SS_TIDAL_DESTINATION] =
    {
        gText_SlateportCity,
        gText_BattleFrontier,
        gText_SouthernIsland,
        gText_NavelRock,
        gText_BirthIsland,
        gText_FarawayIsland,
        gText_Exit
    },
    [SCROLL_MULTI_BATTLE_TENT_RULES] =
    {
        gText_BattleTrainers,
        gText_BattleBasics,
        gText_PokemonNature,
        gText_PokemonMoves,
        gText_Underpowered,
        gText_WhenInDanger,
        gText_Exit
    }
};

static void Task_ShowScrollableMultichoice(u8 taskId)
{
    u32 width;
    u8 i, windowId;
    struct WindowTemplate template;
    struct Task *task = &gTasks[taskId];

    ScriptContext2_Enable();
    sScrollableMultichoice_ScrollOffset = 0;
    sScrollableMultichoice_ItemSpriteId = MAX_SPRITES;
    FillFrontierExchangeCornerWindowAndItemIcon(task->tScrollMultiId, 0);
    ShowBattleFrontierTutorWindow(task->tScrollMultiId, 0);
    sScrollableMultichoice_ListMenuItem = AllocZeroed(task->tNumItems * 8);
    sFrontierExchangeCorner_NeverRead = 0;
    InitScrollableMultichoice();

    for (width = 0, i = 0; i < task->tNumItems; i++)
    {
        const u8 *text = sScrollableMultichoiceOptions[gSpecialVar_0x8004][i];
        sScrollableMultichoice_ListMenuItem[i].name = text;
        sScrollableMultichoice_ListMenuItem[i].id = i;
        width = DisplayTextAndGetWidth(text, width);
    }

    task->tWidth = ConvertPixelWidthToTileWidth(width);

    if (task->tLeft + task->tWidth > MAX_MULTICHOICE_WIDTH + 1)
    {
        int adjustedLeft = MAX_MULTICHOICE_WIDTH + 1 - task->tWidth;
        if (adjustedLeft < 0)
        {
            task->tLeft = 0;
        }
        else
        {
            task->tLeft = adjustedLeft;
        }
    }

    template = CreateWindowTemplate(0, task->tLeft, task->tTop, task->tWidth, task->tHeight, 0xF, 0x64);
    windowId = AddWindow(&template);
    task->tWindowId = windowId;
    SetStandardWindowBorderStyle(windowId, 0);

    gScrollableMultichoice_ListMenuTemplate.totalItems = task->tNumItems;
    gScrollableMultichoice_ListMenuTemplate.maxShowed = task->tMaxItemsOnScreen;
    gScrollableMultichoice_ListMenuTemplate.windowId = task->tWindowId;

    ScrollableMultichoice_UpdateScrollArrows(taskId);
    task->tListTaskId = ListMenuInit(&gScrollableMultichoice_ListMenuTemplate, task->tScrollOffset, task->tSelectedRow);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = ScrollableMultichoice_ProcessInput;
}

static void InitScrollableMultichoice(void)
{
    gScrollableMultichoice_ListMenuTemplate.items = sScrollableMultichoice_ListMenuItem;
    gScrollableMultichoice_ListMenuTemplate.moveCursorFunc = ScrollableMultichoice_MoveCursor;
    gScrollableMultichoice_ListMenuTemplate.itemPrintFunc = NULL;
    gScrollableMultichoice_ListMenuTemplate.totalItems = 1;
    gScrollableMultichoice_ListMenuTemplate.maxShowed = 1;
    gScrollableMultichoice_ListMenuTemplate.windowId = 0;
    gScrollableMultichoice_ListMenuTemplate.header_X = 0;
    gScrollableMultichoice_ListMenuTemplate.item_X = 8;
    gScrollableMultichoice_ListMenuTemplate.cursor_X = 0;
    gScrollableMultichoice_ListMenuTemplate.upText_Y = 1;
    gScrollableMultichoice_ListMenuTemplate.cursorPal = 2;
    gScrollableMultichoice_ListMenuTemplate.fillValue = 1;
    gScrollableMultichoice_ListMenuTemplate.cursorShadowPal = 3;
    gScrollableMultichoice_ListMenuTemplate.lettersSpacing = 0;
    gScrollableMultichoice_ListMenuTemplate.itemVerticalPadding = 0;
    gScrollableMultichoice_ListMenuTemplate.scrollMultiple = 0;
    gScrollableMultichoice_ListMenuTemplate.fontId = 1;
    gScrollableMultichoice_ListMenuTemplate.cursorKind = 0;
}

static void ScrollableMultichoice_MoveCursor(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    u8 taskId;
    PlaySE(SE_SELECT);
    taskId = FindTaskIdByFunc(ScrollableMultichoice_ProcessInput);
    if (taskId != 0xFF)
    {
        u16 selection;
        struct Task *task = &gTasks[taskId];
        ListMenuGetScrollAndRow(task->tListTaskId, &selection, NULL);
        sScrollableMultichoice_ScrollOffset = selection;
        ListMenuGetCurrentItemArrayId(task->tListTaskId, &selection);
        HideFrontierExchangeCornerItemIcon(task->tScrollMultiId, sFrontierExchangeCorner_NeverRead);
        FillFrontierExchangeCornerWindowAndItemIcon(task->tScrollMultiId, selection);
        ShowBattleFrontierTutorMoveDescription(task->tScrollMultiId, selection);
        sFrontierExchangeCorner_NeverRead = selection;
    }
}

static void ScrollableMultichoice_ProcessInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s32 input = ListMenu_ProcessInput(task->tListTaskId);

    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        gSpecialVar_Result = MULTI_B_PRESSED;
        PlaySE(SE_SELECT);
        CloseScrollableMultichoice(taskId);
        break;
    default:
        gSpecialVar_Result = input;
        PlaySE(SE_SELECT);
        if (!task->tKeepOpenAfterSelect)
        {
            CloseScrollableMultichoice(taskId);
        }
        // if selected option was the last one (Exit)
        else if (input == task->tNumItems - 1)
        {
            CloseScrollableMultichoice(taskId);
        }
        else
        {
            ScrollableMultichoice_RemoveScrollArrows(taskId);
            task->func = sub_813A600;
            EnableBothScriptContexts();
        }
        break;
    }
}

static void CloseScrollableMultichoice(u8 taskId)
{
    u16 selection;
    struct Task *task = &gTasks[taskId];
    ListMenuGetCurrentItemArrayId(task->tListTaskId, &selection);
    HideFrontierExchangeCornerItemIcon(task->tScrollMultiId, selection);
    ScrollableMultichoice_RemoveScrollArrows(taskId);
    DestroyListMenuTask(task->tListTaskId, NULL, NULL);
    Free(sScrollableMultichoice_ListMenuItem);
    ClearStdWindowAndFrameToTransparent(task->tWindowId, 1);
    FillWindowPixelBuffer(task->tWindowId, PIXEL_FILL(0));
    CopyWindowToVram(task->tWindowId, 2);
    RemoveWindow(task->tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

// Functionally unused; tKeepOpenAfterSelect is only != 0 in unused functions
static void sub_813A600(u8 taskId)
{
    switch (gTasks[taskId].tKeepOpenAfterSelect)
    {
        case 1:
        default:
            break;
        case 2:
            gTasks[taskId].tKeepOpenAfterSelect = 1;
            gTasks[taskId].func = sub_813A664;
            break;
    }
}

// Never called
void sub_813A630(void)
{
    u8 taskId = FindTaskIdByFunc(sub_813A600);
    if (taskId == 0xFF)
    {
        EnableBothScriptContexts();
    }
    else
    {
        gTasks[taskId].tKeepOpenAfterSelect++;
    }
}

static void sub_813A664(u8 taskId)
{
    ScriptContext2_Enable();
    ScrollableMultichoice_UpdateScrollArrows(taskId);
    gTasks[taskId].func = ScrollableMultichoice_ProcessInput;
}

static void ScrollableMultichoice_UpdateScrollArrows(u8 taskId)
{
    static const struct ScrollArrowsTemplate sScrollableMultichoice_ScrollArrowsTemplate = {
        .firstArrowType = SCROLL_ARROW_UP,
        .firstX = 0,
        .firstY = 0,
        .secondArrowType = SCROLL_ARROW_DOWN,
        .secondX = 0,
        .secondY = 0,
        .fullyUpThreshold = 0,
        .fullyDownThreshold = 0,
        .tileTag = 2000,
        .palTag = 100,
        .palNum = 0
    };

    struct Task *task = &gTasks[taskId];
    struct ScrollArrowsTemplate template = sScrollableMultichoice_ScrollArrowsTemplate;
    if (task->tMaxItemsOnScreen != task->data[1])
    {
        template.firstX = (task->tWidth / 2) * 8 + 12 + (task->tLeft - 1) * 8;
        template.firstY = 8;
        template.secondX = (task->tWidth / 2) * 8 + 12 + (task->tLeft - 1) * 8;
        template.secondY = task->tHeight * 8 + 10;
        template.fullyUpThreshold = 0;
        template.fullyDownThreshold = task->data[1] - task->tMaxItemsOnScreen;
        task->tScrollArrowId = AddScrollIndicatorArrowPair(&template, &sScrollableMultichoice_ScrollOffset);
    }
}

static void ScrollableMultichoice_RemoveScrollArrows(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->tMaxItemsOnScreen != task->data[1])
    {
        RemoveScrollIndicatorArrowPair(task->tScrollArrowId);
    }
}

// Removed for Emerald (replaced by ShowScrollableMultichoice)
void ShowGlassWorkshopMenu(void)
{
    /*
    u8 i;
    ScriptContext2_Enable();
    Menu_DrawStdWindowFrame(0, 0, 10, 11);
    InitMenu(0, 1, 1, 5, 0, 9);
    gUnknown_0203925C = 0;
    ClearVerticalScrollIndicatorPalettes();
    LoadScrollIndicatorPalette();
    sub_810F2B4();
    for (i = 0; i < 5; i++)
    {
        Menu_PrintText(gUnknown_083F83C0[i], 1, 2 * i + 1);
    }
    gUnknown_0203925B = 0;
    gUnknown_0203925A = ARRAY_COUNT(gUnknown_083F83C0);
    CreateTask(sub_810F118, 8);
    */
}

void SetBattleTowerLinkPlayerGfx(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        if (gLinkPlayers[i].gender == MALE)
        {
            VarSet(VAR_OBJ_GFX_ID_F - i, OBJ_EVENT_GFX_BRENDAN_NORMAL);
        }
        else
        {
            VarSet(VAR_OBJ_GFX_ID_F - i, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL);
        }
    }
}

void ShowNatureGirlMessage(void)
{
    static const u8 *const sNatureGirlMessages[] = {
        [NATURE_HARDY]   = BattleFrontier_Lounge5_Text_NatureGirlHardy,
        [NATURE_LONELY]  = BattleFrontier_Lounge5_Text_NatureGirlLonely,
        [NATURE_BRAVE]   = BattleFrontier_Lounge5_Text_NatureGirlBrave,
        [NATURE_ADAMANT] = BattleFrontier_Lounge5_Text_NatureGirlAdamant,
        [NATURE_NAUGHTY] = BattleFrontier_Lounge5_Text_NatureGirlNaughty,
        [NATURE_BOLD]    = BattleFrontier_Lounge5_Text_NatureGirlBold,
        [NATURE_DOCILE]  = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        [NATURE_RELAXED] = BattleFrontier_Lounge5_Text_NatureGirlRelaxed,
        [NATURE_IMPISH]  = BattleFrontier_Lounge5_Text_NatureGirlImpish,
        [NATURE_LAX]     = BattleFrontier_Lounge5_Text_NatureGirlLax,
        [NATURE_TIMID]   = BattleFrontier_Lounge5_Text_NatureGirlTimid,
        [NATURE_HASTY]   = BattleFrontier_Lounge5_Text_NatureGirlHasty,
        [NATURE_SERIOUS] = BattleFrontier_Lounge5_Text_NatureGirlSerious,
        [NATURE_JOLLY]   = BattleFrontier_Lounge5_Text_NatureGirlJolly,
        [NATURE_NAIVE]   = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        [NATURE_MODEST]  = BattleFrontier_Lounge5_Text_NatureGirlModest,
        [NATURE_MILD]    = BattleFrontier_Lounge5_Text_NatureGirlMild,
        [NATURE_QUIET]   = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        [NATURE_BASHFUL] = BattleFrontier_Lounge5_Text_NatureGirlBashful,
        [NATURE_RASH]    = BattleFrontier_Lounge5_Text_NatureGirlRash,
        [NATURE_CALM]    = BattleFrontier_Lounge5_Text_NatureGirlCalm,
        [NATURE_GENTLE]  = BattleFrontier_Lounge5_Text_NatureGirlGentle,
        [NATURE_SASSY]   = BattleFrontier_Lounge5_Text_NatureGirlSassy,
        [NATURE_CAREFUL] = BattleFrontier_Lounge5_Text_NatureGirlCareful,
        [NATURE_QUIRKY]  = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
    };

    u8 nature;

    if (gSpecialVar_0x8004 >= PARTY_SIZE)
    {
        gSpecialVar_0x8004 = 0;
    }

    nature = GetNature(&gPlayerParty[gSpecialVar_0x8004]);
    ShowFieldMessage(sNatureGirlMessages[nature]);
}

void UpdateFrontierGambler(u16 daysSince)
{
    u16 *var = GetVarPointer(VAR_FRONTIER_GAMBLER_CHALLENGE);
    *var += daysSince;
    *var %= FRONTIER_GAMBLER_CHALLENGE_COUNT;
}

void ShowFrontierGamblerLookingMessage(void)
{
    static const u8 *const sFrontierGamblerLookingMessages[] = 
    {
        BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle,
        BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble,
        BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti,
        BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle,
        BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble,
        BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle,
        BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble,
        BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle,
        BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble,
        BattleFrontier_Lounge3_Text_ChallengeBattleArena,
        BattleFrontier_Lounge3_Text_ChallengeBattlePike,
        BattleFrontier_Lounge3_Text_ChallengeBattlePyramid,
    };

    u16 challenge = VarGet(VAR_FRONTIER_GAMBLER_CHALLENGE);
    ShowFieldMessage(sFrontierGamblerLookingMessages[challenge]);
    VarSet(VAR_FRONTIER_GAMBLER_SET_CHALLENGE, challenge);
}

void ShowFrontierGamblerGoMessage(void)
{
    static const u8 *const sFrontierGamblerGoMessages[] = 
    {
        BattleFrontier_Lounge3_Text_GetToBattleTowerSingle,
        BattleFrontier_Lounge3_Text_GetToBattleTowerDouble,
        BattleFrontier_Lounge3_Text_GetToBattleTowerMulti,
        BattleFrontier_Lounge3_Text_GetToBattleDomeSingle,
        BattleFrontier_Lounge3_Text_GetToBattleDomeDouble,
        BattleFrontier_Lounge3_Text_GetToBattleFactorySingle,
        BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble,
        BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle,
        BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble,
        BattleFrontier_Lounge3_Text_GetToBattleArena,
        BattleFrontier_Lounge3_Text_GetToBattlePike,
        BattleFrontier_Lounge3_Text_GetToBattlePyramid,
    };

    ShowFieldMessage(sFrontierGamblerGoMessages[VarGet(VAR_FRONTIER_GAMBLER_SET_CHALLENGE)]);
}

void FrontierGamblerSetWonOrLost(bool8 won)
{
    static const u16 sFrontierChallenges[] = 
    {
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_TOWER,   FRONTIER_MODE_SINGLES),
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_TOWER,   FRONTIER_MODE_DOUBLES),
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_TOWER,   FRONTIER_MODE_MULTIS),
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_DOME,    FRONTIER_MODE_SINGLES),
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_DOME,    FRONTIER_MODE_DOUBLES),
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES), 
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES), 
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_PALACE,  FRONTIER_MODE_SINGLES), 
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_PALACE,  FRONTIER_MODE_DOUBLES), 
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_ARENA,   FRONTIER_MODE_SINGLES), 
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_PIKE,    FRONTIER_MODE_SINGLES), 
        FRONTIER_CHALLENGE(FRONTIER_FACILITY_PYRAMID, FRONTIER_MODE_SINGLES)
    };

    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 challenge = VarGet(VAR_FRONTIER_GAMBLER_SET_CHALLENGE);
    u16 frontierFacilityId = VarGet(VAR_FRONTIER_FACILITY);

    if (VarGet(VAR_FRONTIER_GAMBLER_STATE) == FRONTIER_GAMBLER_PLACED_BET)
    {
        if (sFrontierChallenges[challenge] ==  FRONTIER_CHALLENGE(frontierFacilityId, battleMode))
        {
            if (won)
            {
                VarSet(VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON);
            }
            else
            {
                VarSet(VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_LOST);
            }
        }
    }
}

void UpdateBattlePointsWindow(void)
{
    u8 string[32];
    u32 x;
    StringCopy(ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->frontier.battlePoints, STR_CONV_MODE_RIGHT_ALIGN, 4), gText_BP);
    x = GetStringRightAlignXOffset(1, string, 48);
    AddTextPrinterParameterized(sBattlePointsWindowId, 1, string, x, 1, 0, NULL);
}

void ShowBattlePointsWindow(void)
{
    static const struct WindowTemplate sBattlePoints_WindowTemplate = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 8,
    };

    sBattlePointsWindowId = AddWindow(&sBattlePoints_WindowTemplate);
    SetStandardWindowBorderStyle(sBattlePointsWindowId, 0);
    UpdateBattlePointsWindow();
    CopyWindowToVram(sBattlePointsWindowId, 2);
}

void CloseBattlePointsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sBattlePointsWindowId, TRUE);
    RemoveWindow(sBattlePointsWindowId);
}

void TakeFrontierBattlePoints(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints < gSpecialVar_0x8004)
    {
        gSaveBlock2Ptr->frontier.battlePoints = 0;
    }
    else
    {
        gSaveBlock2Ptr->frontier.battlePoints -= gSpecialVar_0x8004;
    }
}

void GiveFrontierBattlePoints(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004 > MAX_BATTLE_FRONTIER_POINTS)
    {
        gSaveBlock2Ptr->frontier.battlePoints = MAX_BATTLE_FRONTIER_POINTS;
    }
    else
    {
        gSaveBlock2Ptr->frontier.battlePoints = gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004;
    }
}

u16 GetFrontierBattlePoints(void)
{
    return gSaveBlock2Ptr->frontier.battlePoints;
}

void ShowFrontierExchangeCornerItemIconWindow(void)
{
    static const struct WindowTemplate sFrontierExchangeCorner_ItemIconWindowTemplate = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 9,
        .width = 4,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 20,
    };

    sFrontierExchangeCorner_ItemIconWindowId = AddWindow(&sFrontierExchangeCorner_ItemIconWindowTemplate);
    SetStandardWindowBorderStyle(sFrontierExchangeCorner_ItemIconWindowId, 0);
    CopyWindowToVram(sFrontierExchangeCorner_ItemIconWindowId, 2);
}

void CloseFrontierExchangeCornerItemIconWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sFrontierExchangeCorner_ItemIconWindowId, TRUE);
    RemoveWindow(sFrontierExchangeCorner_ItemIconWindowId);
}

static void FillFrontierExchangeCornerWindowAndItemIcon(u16 menu, u16 selection)
{
    #include "data/battle_frontier/battle_frontier_exchange_corner.h"

    if (menu >= SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1 && menu <= SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR)
    {
        FillWindowPixelRect(0, PIXEL_FILL(1), 0, 0, 216, 32);
        switch (menu)
        {
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1:
                AddTextPrinterParameterized2(0, 1, sFrontierExchangeCorner_Decor1Descriptions[selection], 0, NULL, 2, 1, 3);
                if (sFrontierExchangeCorner_Decor1[selection] == 0xFFFF)
                {
                    ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_Decor1[selection]);
                }
                else
                {
                    FreeSpriteTilesByTag(5500);
                    FreeSpritePaletteByTag(5500);
                    sScrollableMultichoice_ItemSpriteId = AddDecorationIconObject(sFrontierExchangeCorner_Decor1[selection], 33, 88, 0, 5500, 5500);
                }
                break;
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2:
                AddTextPrinterParameterized2(0, 1, sFrontierExchangeCorner_Decor2Descriptions[selection], 0, NULL, 2, 1, 3);
                if (sFrontierExchangeCorner_Decor2[selection] == 0xFFFF)
                {
                    ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_Decor2[selection]);
                }
                else
                {
                    FreeSpriteTilesByTag(5500);
                    FreeSpritePaletteByTag(5500);
                    sScrollableMultichoice_ItemSpriteId = AddDecorationIconObject(sFrontierExchangeCorner_Decor2[selection], 33, 88, 0, 5500, 5500);
                }
                break;
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR:
                AddTextPrinterParameterized2(0, 1, sFrontierExchangeCorner_VitaminsDescriptions[selection], 0, NULL, 2, 1, 3);
                ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_Vitamins[selection]);
                break;
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR:
                AddTextPrinterParameterized2(0, 1, sFrontierExchangeCorner_HoldItemsDescriptions[selection], 0, NULL, 2, 1, 3);
                ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_HoldItems[selection]);
                break;
        }
    }
}

static void ShowFrontierExchangeCornerItemIcon(u16 item)
{
    FreeSpriteTilesByTag(5500);
    FreeSpritePaletteByTag(5500);
    sScrollableMultichoice_ItemSpriteId = AddItemIconSprite(5500, 5500, item);

    if (sScrollableMultichoice_ItemSpriteId != MAX_SPRITES)
    {
        gSprites[sScrollableMultichoice_ItemSpriteId].oam.priority = 0;
        gSprites[sScrollableMultichoice_ItemSpriteId].pos1.x = 36;
        gSprites[sScrollableMultichoice_ItemSpriteId].pos1.y = 92;
    }
}

static void HideFrontierExchangeCornerItemIcon(u16 menu, u16 unused)
{
    if (sScrollableMultichoice_ItemSpriteId != MAX_SPRITES)
    {
        switch (menu)
        {
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1:
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2:
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR:
            case SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR:
                DestroySpriteAndFreeResources(&gSprites[sScrollableMultichoice_ItemSpriteId]);
                break;
        }
        sScrollableMultichoice_ItemSpriteId = MAX_SPRITES;
    }
}

static const u16 sBattleFrontier_TutorMoves1[] =
{ 
    MOVE_SOFT_BOILED, 
    MOVE_SEISMIC_TOSS, 
    MOVE_DREAM_EATER, 
    MOVE_MEGA_PUNCH, 
    MOVE_MEGA_KICK, 
    MOVE_BODY_SLAM, 
    MOVE_ROCK_SLIDE, 
    MOVE_COUNTER, 
    MOVE_THUNDER_WAVE, 
    MOVE_SWORDS_DANCE 
};

static const u16 sBattleFrontier_TutorMoves2[] =
{ 
    MOVE_DEFENSE_CURL, 
    MOVE_SNORE, 
    MOVE_MUD_SLAP, 
    MOVE_SWIFT, 
    MOVE_ICY_WIND, 
    MOVE_ENDURE, 
    MOVE_PSYCH_UP, 
    MOVE_ICE_PUNCH, 
    MOVE_THUNDER_PUNCH, 
    MOVE_FIRE_PUNCH 
};

void BufferBattleFrontierTutorMoveName(void)
{
    if (gSpecialVar_0x8005 != 0)
    {
        StringCopy(gStringVar1, gMoveNames[sBattleFrontier_TutorMoves2[gSpecialVar_0x8004]]);
    }
    else
    {
        StringCopy(gStringVar1, gMoveNames[sBattleFrontier_TutorMoves1[gSpecialVar_0x8004]]);
    }
}

static void ShowBattleFrontierTutorWindow(u8 menu, u16 selection)
{
    static const struct WindowTemplate sBattleFrontierTutor_WindowTemplate = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 7,
        .width = 12,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 28,
    };

    if (menu == SCROLL_MULTI_BF_MOVE_TUTOR_1 || menu == SCROLL_MULTI_BF_MOVE_TUTOR_2)
    {
        if (gSpecialVar_0x8006 == 0)
        {
            sTutorMoveAndElevatorWindowId = AddWindow(&sBattleFrontierTutor_WindowTemplate);
            SetStandardWindowBorderStyle(sTutorMoveAndElevatorWindowId, 0);
        }
        ShowBattleFrontierTutorMoveDescription(menu, selection);
    }
}

static void ShowBattleFrontierTutorMoveDescription(u8 menu, u16 selection)
{
    static const u8 *const sBattleFrontier_TutorMoveDescriptions1[] = 
    {
        BattleFrontier_Lounge7_Text_SoftboiledDesc,
        BattleFrontier_Lounge7_Text_SeismicTossDesc,
        BattleFrontier_Lounge7_Text_DreamEaterDesc,
        BattleFrontier_Lounge7_Text_MegaPunchDesc,
        BattleFrontier_Lounge7_Text_MegaKickDesc,
        BattleFrontier_Lounge7_Text_BodySlamDesc,
        BattleFrontier_Lounge7_Text_RockSlideDesc,
        BattleFrontier_Lounge7_Text_CounterDesc,
        BattleFrontier_Lounge7_Text_ThunderWaveDesc,
        BattleFrontier_Lounge7_Text_SwordsDanceDesc,
        gText_Exit,
    };

    static const u8 *const sBattleFrontier_TutorMoveDescriptions2[] = 
    {
        BattleFrontier_Lounge7_Text_DefenseCurlDesc,
        BattleFrontier_Lounge7_Text_SnoreDesc,
        BattleFrontier_Lounge7_Text_MudSlapDesc,
        BattleFrontier_Lounge7_Text_SwiftDesc,
        BattleFrontier_Lounge7_Text_IcyWindDesc,
        BattleFrontier_Lounge7_Text_EndureDesc,
        BattleFrontier_Lounge7_Text_PsychUpDesc,
        BattleFrontier_Lounge7_Text_IcePunchDesc,
        BattleFrontier_Lounge7_Text_ThunderPunchDesc,
        BattleFrontier_Lounge7_Text_FirePunchDesc,
        gText_Exit,
    };

    if (menu == SCROLL_MULTI_BF_MOVE_TUTOR_1 || menu == SCROLL_MULTI_BF_MOVE_TUTOR_2)
    {
        FillWindowPixelRect(sTutorMoveAndElevatorWindowId, PIXEL_FILL(1), 0, 0, 96, 48);
        if (menu == SCROLL_MULTI_BF_MOVE_TUTOR_2)
        {
            AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, 1, sBattleFrontier_TutorMoveDescriptions2[selection], 0, 1, 0, NULL);
        }
        else
        {
            AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, 1, sBattleFrontier_TutorMoveDescriptions1[selection], 0, 1, 0, NULL);
        }
    }
}

void CloseBattleFrontierTutorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sTutorMoveAndElevatorWindowId, TRUE);
    RemoveWindow(sTutorMoveAndElevatorWindowId);
}

// Never called
void sub_813ADD4(void)
{
    u16 scrollOffset, selectedRow;
    u8 i;
    u8 taskId = FindTaskIdByFunc(sub_813A600);
    if (taskId != 0xFF)
    {
        struct Task *task = &gTasks[taskId];
        ListMenuGetScrollAndRow(task->tListTaskId, &scrollOffset, &selectedRow);
        SetStandardWindowBorderStyle(task->tWindowId, 0);

        for (i = 0; i < MAX_SCROLL_MULTI_ON_SCREEN; i++)
        {
            AddTextPrinterParameterized5(task->tWindowId, 1, sScrollableMultichoiceOptions[gSpecialVar_0x8004][scrollOffset + i], 10, i * 16, TEXT_SPEED_FF, NULL, 0, 0);
        }

        AddTextPrinterParameterized(task->tWindowId, 1, gText_SelectorArrow, 0, selectedRow * 16, TEXT_SPEED_FF, NULL);
        PutWindowTilemap(task->tWindowId);
        CopyWindowToVram(task->tWindowId, 3);
    }
}

void GetBattleFrontierTutorMoveIndex(void)
{
    u8 i;
    u16 moveTutor = 0;
    u16 moveIndex = 0;
    gSpecialVar_0x8005 = 0;

    moveTutor = VarGet(VAR_TEMP_E);
    moveIndex = VarGet(VAR_TEMP_D);

    if (moveTutor != 0)
    {
        i = 0;
        do
        {
            if (gTutorMoves[i] == sBattleFrontier_TutorMoves2[moveIndex])
            {
                gSpecialVar_0x8005 = i;
                break;
            }
            i++;
        } while (i < TUTOR_MOVE_COUNT);
    }
    else
    {
        i = 0;
        do
        {
            if (gTutorMoves[i] == sBattleFrontier_TutorMoves1[moveIndex])
            {
                gSpecialVar_0x8005 = i;
                break;
            }
            i++;
        } while (i < TUTOR_MOVE_COUNT);
    }
}

// Never called
void sub_813AF48(void)
{
    u8 taskId = FindTaskIdByFunc(sub_813A600);
    if (taskId != 0xFF)
    {
        struct Task *task = &gTasks[taskId];
        DestroyListMenuTask(task->tListTaskId, NULL, NULL);
        Free(sScrollableMultichoice_ListMenuItem);
        ClearStdWindowAndFrameToTransparent(task->tWindowId, TRUE);
        FillWindowPixelBuffer(task->tWindowId, PIXEL_FILL(0));
        ClearWindowTilemap(task->tWindowId);
        CopyWindowToVram(task->tWindowId, 2);
        RemoveWindow(task->tWindowId);
        DestroyTask(taskId);
    }
}

// Undefine Scrollable Multichoice task data macros
#undef tMaxItemsOnScreen  
#undef tNumItems           
#undef tLeft               
#undef tTop                 
#undef tWidth              
#undef tHeight             
#undef tKeepOpenAfterSelect 
#undef tScrollOffset      
#undef tSelectedRow        
#undef tScrollMultiId       
#undef tScrollArrowId       
#undef tWindowId            
#undef tListTaskId         
#undef tTaskId              

void DoDeoxysRockInteraction(void)
{
    CreateTask(Task_DeoxysRockInteraction, 8);
}

static const u16 sDeoxysRockPalettes[][16] = {
    INCBIN_U16("graphics/misc/deoxys1.gbapal"),
    INCBIN_U16("graphics/misc/deoxys2.gbapal"),
    INCBIN_U16("graphics/misc/deoxys3.gbapal"),
    INCBIN_U16("graphics/misc/deoxys4.gbapal"),
    INCBIN_U16("graphics/misc/deoxys5.gbapal"),
    INCBIN_U16("graphics/misc/deoxys6.gbapal"),
    INCBIN_U16("graphics/misc/deoxys7.gbapal"),
    INCBIN_U16("graphics/misc/deoxys8.gbapal"),
    INCBIN_U16("graphics/misc/deoxys9.gbapal"),
    INCBIN_U16("graphics/misc/deoxys10.gbapal"),
    INCBIN_U16("graphics/misc/deoxys11.gbapal"),
};

static const u8 sDeoxysRockCoords[][2] = {
    { 15, 12 },
    { 11, 14 },
    { 15,  8 },
    { 19, 14 },
    { 12, 11 },
    { 18, 11 },
    { 15, 14 },
    { 11, 14 },
    { 19, 14 },
    { 15, 15 },
    { 15, 10 },
};

static void Task_DeoxysRockInteraction(u8 taskId)
{
    static const u8 sStoneMaxStepCounts[] = { 4, 8, 8, 8, 4, 4, 4, 6, 3, 3 };

    if (FlagGet(FLAG_DEOXYS_ROCK_COMPLETE) == TRUE)
    {
        gSpecialVar_Result = 3;
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
    else
    {
        u16 rockLevel = VarGet(VAR_DEOXYS_ROCK_LEVEL);
        u16 stepCount = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);

        VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        if (rockLevel != 0 && sStoneMaxStepCounts[rockLevel - 1] < stepCount)
        {
            // Player failed to take the shortest path to the stone, so it resets.
            ChangeDeoxysRockLevel(0);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, 0);
            gSpecialVar_Result = 0;
            DestroyTask(taskId);
        }
        else if (rockLevel == 10)
        {
            FlagSet(FLAG_DEOXYS_ROCK_COMPLETE);
            gSpecialVar_Result = 2;
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
        else
        {
            rockLevel++;
            ChangeDeoxysRockLevel(rockLevel);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, rockLevel);
            gSpecialVar_Result = 1;
            DestroyTask(taskId);
        }
    }
}

static void ChangeDeoxysRockLevel(u8 rockLevel)
{
    u8 objectEventId;
    LoadPalette(&sDeoxysRockPalettes[rockLevel], 0x1A0, 8);
    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);

    if (rockLevel == 0)
        PlaySE(SE_W109);
    else
        PlaySE(SE_RG_DEOMOV);

    CreateTask(WaitForDeoxysRockMovement, 8);
    gFieldEffectArguments[0] = 1;
    gFieldEffectArguments[1] = 58;
    gFieldEffectArguments[2] = 26;
    gFieldEffectArguments[3] = sDeoxysRockCoords[rockLevel][0];
    gFieldEffectArguments[4] = sDeoxysRockCoords[rockLevel][1];

    if (rockLevel == 0)
        gFieldEffectArguments[5] = 60;
    else
        gFieldEffectArguments[5] = 5;

    FieldEffectStart(FLDEFF_MOVE_DEOXYS_ROCK);
    Overworld_SetObjEventTemplateCoords(1, sDeoxysRockCoords[rockLevel][0], sDeoxysRockCoords[rockLevel][1]);
}

static void WaitForDeoxysRockMovement(u8 taskId)
{
    if (FieldEffectActiveListContains(FLDEFF_MOVE_DEOXYS_ROCK) == FALSE)
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

void IncrementBirthIslandRockStepCount(void)
{
    u16 var = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(BIRTH_ISLAND_EXTERIOR) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BIRTH_ISLAND_EXTERIOR))
    {
        var++;
        if (var > 99)
        {
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        }
        else
        {
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, var);
        }
    }
}

void SetDeoxysRockPalette(void)
{
    LoadPalette(&sDeoxysRockPalettes[(u8)VarGet(VAR_DEOXYS_ROCK_LEVEL)], 0x1A0, 8);
    BlendPalettes(0x04000000, 16, 0);
}

void SetPCBoxToSendMon(u8 boxId)
{
    sPCBoxToSendMon = boxId;
}

u16 GetPCBoxToSendMon(void)
{
    return sPCBoxToSendMon;
}

bool8 ShouldShowBoxWasFullMessage(void)
{
    if (!FlagGet(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE))
    {
        if (StorageGetCurrentBox() != VarGet(VAR_PC_BOX_TO_SEND_MON))
        {
            FlagSet(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsDestinationBoxFull(void)
{
    int box;
    int i;
    SetPCBoxToSendMon(VarGet(VAR_PC_BOX_TO_SEND_MON));
    box = StorageGetCurrentBox();
    do
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (GetBoxMonData(GetBoxedMonPtr(box, i), MON_DATA_SPECIES, 0) == SPECIES_NONE)
            {
                if (GetPCBoxToSendMon() != box)
                {
                    FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
                }
                VarSet(VAR_PC_BOX_TO_SEND_MON, box);
                return ShouldShowBoxWasFullMessage();
            }
        }

        if (++box == TOTAL_BOXES_COUNT)
        {
            box = 0;
        }
    } while (box != StorageGetCurrentBox());
    return FALSE;
}

void CreateAbnormalWeatherEvent(void)
{
    u16 randomValue = Random();
    VarSet(VAR_ABNORMAL_WEATHER_STEP_COUNTER, 0);

    if (FlagGet(FLAG_DEFEATED_KYOGRE) == TRUE)
    {
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % TERRA_CAVE_LOCATIONS) + TERRA_CAVE_LOCATIONS_START);
    }
    else if (FlagGet(FLAG_DEFEATED_GROUDON) == TRUE)
    {
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % MARINE_CAVE_LOCATIONS) + MARINE_CAVE_LOCATIONS_START);
    }
    else if ((randomValue & 1) == 0)
    {
        randomValue = Random();
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % TERRA_CAVE_LOCATIONS) + TERRA_CAVE_LOCATIONS_START);
    }
    else
    {
        randomValue = Random();
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % MARINE_CAVE_LOCATIONS) + MARINE_CAVE_LOCATIONS_START);
    }
}

// Saves the map name for the current abnormal weather location in gStringVar1, then
// returns TRUE if the weather is for Kyogre, and FALSE if it's for Groudon.
bool32 GetAbnormalWeatherMapNameAndType(void)
{
    static const u8 sAbnormalWeatherMapNumbers[] = {
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE129),
        MAP_NUM(ROUTE129)
    };

    u16 abnormalWeather = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);

    GetMapName(gStringVar1, sAbnormalWeatherMapNumbers[abnormalWeather - 1], 0);

    if (abnormalWeather < MARINE_CAVE_LOCATIONS_START)
        return FALSE;
    else
        return TRUE;
}

bool8 AbnormalWeatherHasExpired(void)
{
    // Duplicate array.
    static const u8 sAbnormalWeatherMapNumbers[] = {
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE129),
        MAP_NUM(ROUTE129)
    };

    u16 steps = VarGet(VAR_ABNORMAL_WEATHER_STEP_COUNTER);
    u16 abnormalWeather = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);

    if (abnormalWeather == ABNORMAL_WEATHER_NONE)
    {
        return FALSE;
    }

    if (++steps > 999)
    {
        VarSet(VAR_ABNORMAL_WEATHER_STEP_COUNTER, 0);
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(UNDERWATER_MARINE_CAVE))
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
                case MAP_NUM(UNDERWATER_MARINE_CAVE):
                case MAP_NUM(MARINE_CAVE_ENTRANCE):
                case MAP_NUM(MARINE_CAVE_END):
                case MAP_NUM(TERRA_CAVE_ENTRANCE):
                case MAP_NUM(TERRA_CAVE_END):
                    VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 1);
                    return FALSE;
                default:
                    break;
            }
        }

        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(UNDERWATER3))
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
                case MAP_NUM(UNDERWATER3):
                case MAP_NUM(UNDERWATER5):
                case MAP_NUM(UNDERWATER6):
                case MAP_NUM(UNDERWATER7):
                    VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 1);
                    return FALSE;
                default:
                    break;
            }
        }

        if (gSaveBlock1Ptr->location.mapNum == sAbnormalWeatherMapNumbers[abnormalWeather - 1] &&
            gSaveBlock1Ptr->location.mapGroup == 0)
        {
            return TRUE;
        }
        else
        {
            VarSet(VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_NONE);
            return FALSE;
        }
    }
    else
    {
        VarSet(VAR_ABNORMAL_WEATHER_STEP_COUNTER, steps);
        return FALSE;
    }
}

void Unused_SetWeatherSunny(void)
{
    SetCurrentAndNextWeather(WEATHER_SUNNY);
}

// Always returns 1
u32 GetMartEmployeeObjectEventId(void)
{
    static const u8 sPokeMarts[][3] =
    {
        { MAP_GROUP(OLDALE_TOWN_MART),     MAP_NUM(OLDALE_TOWN_MART),     1 },
        { MAP_GROUP(LAVARIDGE_TOWN_MART),  MAP_NUM(LAVARIDGE_TOWN_MART),  1 }, 
        { MAP_GROUP(FALLARBOR_TOWN_MART),  MAP_NUM(FALLARBOR_TOWN_MART),  1 },
        { MAP_GROUP(VERDANTURF_TOWN_MART), MAP_NUM(VERDANTURF_TOWN_MART), 1 },
        { MAP_GROUP(PETALBURG_CITY_MART),  MAP_NUM(PETALBURG_CITY_MART),  1 },
        { MAP_GROUP(SLATEPORT_CITY_MART),  MAP_NUM(SLATEPORT_CITY_MART),  1 },
        { MAP_GROUP(MAUVILLE_CITY_MART),   MAP_NUM(MAUVILLE_CITY_MART),   1 },
        { MAP_GROUP(RUSTBORO_CITY_MART),   MAP_NUM(RUSTBORO_CITY_MART),   1 },
        { MAP_GROUP(FORTREE_CITY_MART),    MAP_NUM(FORTREE_CITY_MART),    1 },
        { MAP_GROUP(MOSSDEEP_CITY_MART),   MAP_NUM(MOSSDEEP_CITY_MART),   1 },
        { MAP_GROUP(SOOTOPOLIS_CITY_MART), MAP_NUM(SOOTOPOLIS_CITY_MART), 1 },
        { MAP_GROUP(BATTLE_FRONTIER_MART), MAP_NUM(BATTLE_FRONTIER_MART), 1 }
    };

    u8 i;
    for (i = 0; i < ARRAY_COUNT(sPokeMarts); i++)
    {
        if (gSaveBlock1Ptr->location.mapGroup == sPokeMarts[i][0])
        {
            if (gSaveBlock1Ptr->location.mapNum == sPokeMarts[i][1])
            {
                return sPokeMarts[i][2];
            }
        }
    }
    return 1;
}

bool32 IsTrainerRegistered(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
    {
        if (FlagGet(FLAG_MATCH_CALL_REGISTERED + index) == TRUE)
            return TRUE;
    }
    return FALSE;
}

// Always returns FALSE
bool32 ShouldDistributeEonTicket(void)
{
    if (!VarGet(VAR_DISTRIBUTE_EON_TICKET))
        return FALSE;
    
    return TRUE;
}

void sub_813B534(void)
{
    sBattleTowerMultiBattleTypeFlags = gBattleTypeFlags;
    gBattleTypeFlags = 0;
    if (!gReceivedRemoteLinkPlayers)
    {
        CreateTask(sub_80B3AF8, 5);
    }
}

void LinkRetireStatusWithBattleTowerPartner(void)
{
    CreateTask(Task_LinkRetireStatusWithBattleTowerPartner, 5);
}

static void Task_LinkRetireStatusWithBattleTowerPartner(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (!FuncIsActiveTask(sub_80B3AF8))
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (IsLinkTaskFinished() == TRUE)
            {
                if (GetMultiplayerId() == 0)
                {
                    gTasks[taskId].data[0]++;
                }
                else
                {
                    SendBlock(bitmask_all_link_players_but_self(), &gSpecialVar_0x8004, 2);
                    gTasks[taskId].data[0]++;
                }
            }
            break;
        case 2:
            if ((GetBlockReceivedStatus() & 2) != 0)
            {
                if (GetMultiplayerId() == 0)
                {
                    gSpecialVar_0x8005 = gBlockRecvBuffer[1][0];
                    ResetBlockReceivedFlag(1);
                    if (gSpecialVar_0x8004 == BATTLE_TOWER_LINK_RETIRE 
                     && gSpecialVar_0x8005 == BATTLE_TOWER_LINK_RETIRE)
                    {
                        gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_BOTH_RETIRE;
                    }
                    else if (gSpecialVar_0x8004 == BATTLE_TOWER_LINK_CONTINUE 
                          && gSpecialVar_0x8005 == BATTLE_TOWER_LINK_RETIRE)
                    {
                        gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_PARTNER_RETIRE;
                    }
                    else if (gSpecialVar_0x8004 == BATTLE_TOWER_LINK_RETIRE 
                          && gSpecialVar_0x8005 == BATTLE_TOWER_LINK_CONTINUE)
                    {
                        gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_PLAYER_RETIRE;
                    }
                    else
                    {
                        gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_CONTINUE;
                    }
                }
                gTasks[taskId].data[0]++;
            }
            break;
        case 3:
            if (IsLinkTaskFinished() == TRUE)
            {
                if (GetMultiplayerId() != 0)
                {
                    gTasks[taskId].data[0]++;
                }
                else
                {
                    SendBlock(bitmask_all_link_players_but_self(), &gSpecialVar_Result, 2);
                    gTasks[taskId].data[0]++;
                }
            }
            break;
        case 4:
            if ((GetBlockReceivedStatus() & 1) != 0)
            {
                if (GetMultiplayerId() != 0)
                {
                    gSpecialVar_Result = gBlockRecvBuffer[0][0];
                    ResetBlockReceivedFlag(0);
                    gTasks[taskId].data[0]++;
                }
                else
                {
                    gTasks[taskId].data[0]++;
                }
            }
            break;
        case 5:
            if (GetMultiplayerId() == 0)
            {
                if (gSpecialVar_Result == BATTLE_TOWER_LINKSTAT_PARTNER_RETIRE)
                {
                    ShowFieldAutoScrollMessage(gText_YourPartnerHasRetired);
                }
            }
            else
            {
                if (gSpecialVar_Result == BATTLE_TOWER_LINKSTAT_PLAYER_RETIRE)
                {
                    ShowFieldAutoScrollMessage(gText_YourPartnerHasRetired);
                }
            }
            gTasks[taskId].data[0]++;
            break;
        case 6:
            if (!IsTextPrinterActive(0))
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 7:
            if (IsLinkTaskFinished() == 1)
            {
                sub_800ADF8();
                gTasks[taskId].data[0]++;
            }
            break;
        case 8:
            if (IsLinkTaskFinished() == 1)
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 9:
            if (gWirelessCommType == 0)
            {
                sub_800AC34();
            }
            gBattleTypeFlags = sBattleTowerMultiBattleTypeFlags;
            EnableBothScriptContexts();
            DestroyTask(taskId);
            break;
    }
}

void Script_DoRayquazaScene(void)
{
    if (gSpecialVar_0x8004 == 0)
    {
        DoRayquazaScene(0, TRUE, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else
    {
        DoRayquazaScene(1, FALSE, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

#define playCount data[0]
#define delay     data[1]

void LoopWingFlapSE(void)
{
    CreateTask(Task_LoopWingFlapSE, 8);
    PlaySE(SE_W017);
}

static void Task_LoopWingFlapSE(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    delay++;
    if (delay == gSpecialVar_0x8005)
    {
        playCount++;
        delay = 0;
        PlaySE(SE_W017);
    }

    if (playCount == gSpecialVar_0x8004 - 1)
    {
        DestroyTask(taskId);
    }
}

#undef playCount
#undef delay

void CloseBattlePikeCurtain(void)
{
    u8 taskId = CreateTask(Task_CloseBattlePikeCurtain, 8);
    gTasks[taskId].data[0] = 4;
    gTasks[taskId].data[1] = 4;
    gTasks[taskId].data[2] = 4;
    gTasks[taskId].data[3] = 0;
}

static void Task_CloseBattlePikeCurtain(u8 taskId)
{
    u8 x, y;
    s16 *data = gTasks[taskId].data;

    data[data[3]]--;
    if (data[data[3]] == 0)
    {
        for (y = 0; y < 4; y++)
        {
            for (x = 0; x < 3; x++)
            {
                MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + x + 6, gSaveBlock1Ptr->pos.y + y + 4, x + 513 + y * 8 + data[3] * 32);
            }
        }
        DrawWholeMapView();
        data[3]++;
        if (data[3] == 3)
        {
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
    }
}

void GetBattlePyramidHint(void)
{
    gSpecialVar_Result = gSpecialVar_0x8004 / 7;
    gSpecialVar_Result -= (gSpecialVar_Result / 20) * 20;
}

// Used to avoid a potential softlock if the player respawns on Dewford with no way off
void ResetHealLocationFromDewford(void)
{
    if (gSaveBlock1Ptr->lastHealLocation.mapGroup == MAP_GROUP(DEWFORD_TOWN) && gSaveBlock1Ptr->lastHealLocation.mapNum == MAP_NUM(DEWFORD_TOWN))
    {
        SetLastHealLocationWarp(HEAL_LOCATION_PETALBURG_CITY);
    }
}

bool8 InPokemonCenter(void)
{
    static const u16 sPokemonCenters[] =
    {
        MAP_OLDALE_TOWN_POKEMON_CENTER_1F,
        MAP_DEWFORD_TOWN_POKEMON_CENTER_1F,
        MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F,
        MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F,
        MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F,
        MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F,
        MAP_PETALBURG_CITY_POKEMON_CENTER_1F,
        MAP_SLATEPORT_CITY_POKEMON_CENTER_1F,
        MAP_MAUVILLE_CITY_POKEMON_CENTER_1F,
        MAP_RUSTBORO_CITY_POKEMON_CENTER_1F,
        MAP_FORTREE_CITY_POKEMON_CENTER_1F,
        MAP_LILYCOVE_CITY_POKEMON_CENTER_1F,
        MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F,
        MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F,
        MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F,
        MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F,
        MAP_BATTLE_FRONTIER_POKEMON_CENTER_1F,
        MAP_BATTLE_COLOSSEUM_2P,
        MAP_TRADE_CENTER,
        MAP_RECORD_CORNER,
        MAP_BATTLE_COLOSSEUM_4P,
        0xFFFF
    };

    int i;
    u16 map = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;

    for (i = 0; sPokemonCenters[i] != 0xFFFF; i++)
    {
        if (sPokemonCenters[i] == map)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*  Summary of the Lilycove Trainer Fan Club, because it's a little messy
    
    ## The Fan Club room itself
    There are initially 4 members of the Fan Club (+ an interviewer), none of whom are fans of the player
    After becoming the champion there will be 8 members of the Fan Club, 3 of whom are automatically fans of the player
    After this point, if a club member is a fan of the player they will sit at the front table and comment on the player
    If they are not fans of the player, they will sit at the far table and can make comments about a different trainer (see BufferFanClubTrainerName)
    
    ## Gaining/losing fans
    After every link battle the player will gain a fan if they won, or lose a fan if they lost
    If the player has at least 3 fans, this is the only way to gain fans
    If the player has fewer than 3 fans, they may also gain fans by completing certain tasks enough times (see TryGainNewFanFromCounter)
    If the player has at least 5 fans, they can lose a fan every 12 real-time hours, or more often if the timer variable is reset (see TryLoseFansFromPlayTime)
    If the player has only 1 fan left it cannot be lost

    ## Variables
    VAR_FANCLUB_FAN_COUNTER, a bitfield for tracking the fans
      Bits  1-7: Counter for when to add new fans
      Bit     8: Flag set after receiving the initial 3 fans
      Bits 9-16: Flags for each of the 8 club members, set to 1 when theyre a fan of the player and 0 when theyre not

    VAR_FANCLUB_LOSE_FAN_TIMER, a timer for when to lose fans
      Compared against playTimeHours. When theyre equal, a fan is ready to be lost
      For every fan thats lost this way 12 hours are added to the timer

    VAR_LILYCOVE_FAN_CLUB_STATE
      0: Player is not the champion yet
      1: Player is the champion, ready to meet their initial fans
      2: Player has met their initial fans
*/

#define FANCLUB_BITFIELD (gSaveBlock1Ptr->vars[VAR_FANCLUB_FAN_COUNTER - VARS_START])
#define FANCLUB_COUNTER    0x007F
#define FANCLUB_FAN_FLAGS  0xFF80

#define GET_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD >> (flag) & 1)
#define SET_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD |= 1 << (flag))
#define FLIP_TRAINER_FAN_CLUB_FLAG(flag)(FANCLUB_BITFIELD ^= 1 << (flag))

#define GET_TRAINER_FAN_CLUB_COUNTER        (FANCLUB_BITFIELD & FANCLUB_COUNTER)
#define SET_TRAINER_FAN_CLUB_COUNTER(count) (FANCLUB_BITFIELD = (FANCLUB_BITFIELD & FANCLUB_FAN_FLAGS) | (count))
#define INCR_TRAINER_FAN_CLUB_COUNTER(count)(FANCLUB_BITFIELD += (count))
#define CLEAR_TRAINER_FAN_CLUB_COUNTER      (FANCLUB_BITFIELD &= ~(FANCLUB_COUNTER))

void ResetFanClub(void)
{
    gSaveBlock1Ptr->vars[VAR_FANCLUB_FAN_COUNTER - VARS_START] = 0;
    gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = 0;
}

void TryLoseFansFromPlayTimeAfterLinkBattle(void)
{
    if (DidPlayerGetFirstFans())
    {
        TryLoseFansFromPlayTime();
        gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlock2Ptr->playTimeHours;
    }
}

void UpdateTrainerFanClubGameClear(void)
{
    if (!GET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS))
    {
        SetPlayerGotFirstFans();
        SetInitialFansOfPlayer();
        gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlock2Ptr->playTimeHours;
        FlagClear(FLAG_HIDE_FANCLUB_OLD_LADY);
        FlagClear(FLAG_HIDE_FANCLUB_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LITTLE_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LADY);
        FlagClear(FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER);
        VarSet(VAR_LILYCOVE_FAN_CLUB_STATE, 1);
    }
}

// If the player has < 3 fans, gain a new fan whenever the counter reaches 20+
// Defeating Drake or participating in a Link Contest increments the counter by 2
// Participating at Battle Tower or in a Secret Base battle increments the counter by 1
u8 TryGainNewFanFromCounter(u8 incrementId)
{
    static const u8 sCounterIncrements[] = { 2, 1, 2, 1 };

    if (VarGet(VAR_LILYCOVE_FAN_CLUB_STATE) == 2)
    {
        if (GET_TRAINER_FAN_CLUB_COUNTER + sCounterIncrements[incrementId] > 19)
        {
            if (GetNumFansOfPlayerInTrainerFanClub() < 3)
            {
                PlayerGainRandomTrainerFan();
                CLEAR_TRAINER_FAN_CLUB_COUNTER;
            }
            else
            {
                SET_TRAINER_FAN_CLUB_COUNTER(20);
            }
        }
        else
        {
            INCR_TRAINER_FAN_CLUB_COUNTER(sCounterIncrements[incrementId]);
        }
    }

    return GET_TRAINER_FAN_CLUB_COUNTER;
}


// Loop through the fan club members, and if theyre not a fan of the player there is a 50% chance for them to become a fan
// Stops when a fan is gained
// If no new fan was gained while looping, the last non-fan in the list becomes a fan
// If all the members are already fans of the player then this redundantly sets the first fan in the list to be a fan
static u16 PlayerGainRandomTrainerFan(void)
{
    static const u8 sFanClubMemberIds[NUM_TRAINER_FAN_CLUB_MEMBERS] = 
    { 
        FANCLUB_MEMBER1, 
        FANCLUB_MEMBER2, 
        FANCLUB_MEMBER3, 
        FANCLUB_MEMBER4, 
        FANCLUB_MEMBER5, 
        FANCLUB_MEMBER6,
        FANCLUB_MEMBER7, 
        FANCLUB_MEMBER8 
    };

    u8 i;
    u8 idx = 0;

    for (i = 0; i < ARRAY_COUNT(sFanClubMemberIds); i++)
    {
        if (!GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i]))
        {
            idx = i;
            if (Random() & 1)
            {
                SET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);
                return idx;
            }
        }
    }
    SET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);
    return idx;
}

// Loops through the fan club members, and if theyre a fan of the player there is a 50% chance for them to stop being a fan
// Stops if a fan is removed, or if the player has only one fan left
// If no fan was lost while looping, the last current fan in the list will stop being a fan
static u16 PlayerLoseRandomTrainerFan(void)
{
    static const u8 sFanClubMemberIds[NUM_TRAINER_FAN_CLUB_MEMBERS] = 
    { 
        FANCLUB_MEMBER1, 
        FANCLUB_MEMBER6, 
        FANCLUB_MEMBER7, 
        FANCLUB_MEMBER4, 
        FANCLUB_MEMBER3, 
        FANCLUB_MEMBER5, 
        FANCLUB_MEMBER8, 
        FANCLUB_MEMBER2 
    };

    u8 i;
    u8 idx = 0;

    if (GetNumFansOfPlayerInTrainerFanClub() == 1)
    {
        return 0;
    }

    for (i = 0; i < ARRAY_COUNT(sFanClubMemberIds); i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i]))
        {
            idx = i;
            if (Random() & 1)
            {
                FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);
                return idx;
            }
        }
    }

    if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]))
    {
        FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);
    }

    return idx;
}

u16 GetNumFansOfPlayerInTrainerFanClub(void)
{
    u8 i;
    u8 numFans = 0;

    for (i = 0; i < NUM_TRAINER_FAN_CLUB_MEMBERS; i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(i + FANCLUB_MEMBER1))
            numFans++;
    }

    return numFans;
}

// If the player has > 5 fans in the Trainer Fan Club, then lose 1 fan for every 12 hours since the last fan loss / timer reset
void TryLoseFansFromPlayTime(void)
{
    u8 i = 0;
    if (gSaveBlock2Ptr->playTimeHours < 999)
    {
        while (TRUE)
        {
            if (GetNumFansOfPlayerInTrainerFanClub() < 5)
            {
                gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlock2Ptr->playTimeHours;
                break;
            }
            else if (i == NUM_TRAINER_FAN_CLUB_MEMBERS)
            {
                break;
            }
            else if (gSaveBlock2Ptr->playTimeHours - gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] < 12)
            {
                return;
            }
            PlayerLoseRandomTrainerFan();
            gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] += 12;
            i++;
        }
    }
}

bool8 IsFanClubMemberFanOfPlayer(void)
{
    return GET_TRAINER_FAN_CLUB_FLAG(gSpecialVar_0x8004);
}

static void SetInitialFansOfPlayer(void)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER6);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER1);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER3);
}

void BufferFanClubTrainerName(void)
{
    u8 whichLinkTrainer = 0;
    u8 whichNPCTrainer = 0;
    switch (gSpecialVar_0x8004)
    {
        case FANCLUB_MEMBER1:
            break;
        case FANCLUB_MEMBER2:
            break;
        case FANCLUB_MEMBER3:
            whichLinkTrainer = 0;
            whichNPCTrainer = 3;
            break;
        case FANCLUB_MEMBER4:
            whichLinkTrainer = 0;
            whichNPCTrainer = 1;
            break;
        case FANCLUB_MEMBER5:
            whichLinkTrainer = 1;
            whichNPCTrainer = 0;
            break;
        case FANCLUB_MEMBER6:
            whichLinkTrainer = 0;
            whichNPCTrainer = 4;
            break;
        case FANCLUB_MEMBER7:
            whichLinkTrainer = 1;
            whichNPCTrainer = 5;
            break;
        case FANCLUB_MEMBER8:
            break;
    }
    BufferFanClubTrainerName_(&gSaveBlock1Ptr->linkBattleRecords, whichLinkTrainer, whichNPCTrainer);
}

static void BufferFanClubTrainerName_(struct LinkBattleRecords *linkRecords, u8 whichLinkTrainer, u8 whichNPCTrainer)
{
    struct LinkBattleRecord *record = &linkRecords->entries[whichLinkTrainer];
    if (record->name[0] == EOS)
    {
        switch (whichNPCTrainer)
        {
            case 0:
                StringCopy(gStringVar1, gText_Wallace);
                break;
            case 1:
                StringCopy(gStringVar1, gText_Steven);
                break;
            case 2:
                StringCopy(gStringVar1, gText_Brawly);
                break;
            case 3:
                StringCopy(gStringVar1, gText_Winona);
                break;
            case 4:
                StringCopy(gStringVar1, gText_Phoebe);
                break;
            case 5:
                StringCopy(gStringVar1, gText_Glacia);
                break;
            default:
                StringCopy(gStringVar1, gText_Wallace);
                break;
        }
    }
    else
    {
        StringCopyN(gStringVar1, record->name, PLAYER_NAME_LENGTH);
        gStringVar1[PLAYER_NAME_LENGTH] = EOS;
        ConvertInternationalString(gStringVar1, linkRecords->languages[whichLinkTrainer]);
    }
}

void UpdateTrainerFansAfterLinkBattle(void)
{
    if (VarGet(VAR_LILYCOVE_FAN_CLUB_STATE) == 2)
    {
        TryLoseFansFromPlayTimeAfterLinkBattle();
        if (gBattleOutcome == B_OUTCOME_WON)
            PlayerGainRandomTrainerFan();
        else
            PlayerLoseRandomTrainerFan();
    }
}

static bool8 DidPlayerGetFirstFans(void)
{
    return GET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS);
}

void SetPlayerGotFirstFans(void)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS);
}

// return value is always ignored
u8 Script_TryGainNewFanFromCounter(void)
{
    return TryGainNewFanFromCounter(gSpecialVar_0x8004);
}
