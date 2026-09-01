#include "global.h"
#include "debug.h"
#include "malloc.h"
#include "battle.h"
#include "battle_special.h"
#include "cable_club.h"
#include "data.h"
#include "daycare.h"
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
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "link.h"
#include "list_menu.h"
#include "load_save.h"
#include "mail.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "mystery_gift.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "random.h"
#include "rayquaza_scene.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "starter_choose.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "tilesets.h"
#include "tv.h"
#include "wallclock.h"
#include "window.h"
#include "constants/battle_frontier.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_tower.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/mystery_gift.h"
#include "constants/slot_machine.h"
#include "constants/songs.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/battle_frontier.h"
#include "constants/weather.h"
#include "constants/metatile_labels.h"
#include "constants/rgb.h"
#include "palette.h"
#include "battle_util.h"
#include "naming_screen.h"
#include "chooseboxmon.h"

#define TAG_ITEM_ICON 5500

#define GFXTAG_MULTICHOICE_SCROLL_ARROWS 2000
#define PALTAG_MULTICHOICE_SCROLL_ARROWS 100

#define ELEVATOR_WINDOW_WIDTH  3
#define ELEVATOR_WINDOW_HEIGHT 3
#define ELEVATOR_LIGHT_STAGES  3

EWRAM_DATA bool8 gBikeCyclingChallenge = FALSE;
EWRAM_DATA u8 gBikeCollisions = 0;
static EWRAM_DATA u32 sBikeCyclingTimer = 0;
static EWRAM_DATA u8 sSlidingDoorNextFrameCounter = 0;
static EWRAM_DATA u8 sSlidingDoorFrame = 0;
static EWRAM_DATA u8 sTutorMoveAndElevatorWindowId = 0;
static EWRAM_DATA u16 sLilycoveDeptStore_DefaultFloorChoice = 0;
static EWRAM_DATA struct ListMenuItem *sScrollableMultichoice_ListMenuItem = NULL;

static EWRAM_DATA u16 sFrontierExchangeCorner_NeverRead = 0;
static EWRAM_DATA u8 sScrollableMultichoice_ItemSpriteId = 0;
static EWRAM_DATA u8 sBattlePointsWindowId = 0;
static EWRAM_DATA u8 sFrontierExchangeCorner_ItemIconWindowId = 0;
static EWRAM_DATA u8 sPCBoxToSendMon = 0;
static EWRAM_DATA u32 sBattleTowerMultiBattleTypeFlags = 0;

COMMON_DATA struct ListMenuTemplate gScrollableMultichoice_ListMenuTemplate = {0};
EWRAM_DATA u16 gScrollableMultichoice_ScrollOffset = 0;

static EWRAM_DATA u8 sElevatorCurrentFloorWindowId = 0;
static EWRAM_DATA u16 sElevatorScroll = 0;
static EWRAM_DATA u16 sElevatorCursorPos = 0;
static EWRAM_DATA u8 sBrailleTextCursorSpriteID = 0;

void TryLoseFansFromPlayTime(void);
void SetPlayerGotFirstFans(void);
u16 GetNumFansOfPlayerInTrainerFanClub(void);

static void RecordCyclingRoadResults(u32, u8);
static void LoadLinkPartnerObjectEventSpritePalette(u16, u8, u8);
static void Task_PetalburgGymSlideOpenRoomDoors(u8);
static void PetalburgGymSetDoorMetatiles(u8, u16);
static void Task_PCTurnOnEffect(u8);
static void PCTurnOnEffect(struct Task *);
static void PCTurnOnEffect_SetMetatile(s16, s8, s8);
static void PCTurnOffEffect(void);
static void Task_LotteryCornerComputerEffect(u8);
static void LotteryCornerComputerEffect(struct Task *);
static void Task_ShakeCamera(u8);
static void StopCameraShake(u8);
static void Task_MoveElevator(u8);
static void MoveElevatorWindowLights(u16, bool8);
static void Task_MoveElevatorWindowLights(u8);
static void Task_ShowScrollableMultichoice(u8);
static void FillFrontierExchangeCornerWindowAndItemIcon(enum ScrollMulti, u16);
static void ShowBattleFrontierTutorWindow(enum ScrollMulti, u16);
static void InitScrollableMultichoice(void);
static void ScrollableMultichoice_ProcessInput(u8);
static void ScrollableMultichoice_UpdateScrollArrows(u8);
static void ScrollableMultichoice_MoveCursor(s32, bool8, struct ListMenu *);
static void HideFrontierExchangeCornerItemIcon(enum ScrollMulti, u16);
static void ShowBattleFrontierTutorMoveDescription(enum ScrollMulti, u16);
static void CloseScrollableMultichoice(u8);
static void ScrollableMultichoice_RemoveScrollArrows(u8);
static void Task_ScrollableMultichoice_WaitReturnToList(u8);
static void Task_ScrollableMultichoice_ReturnToList(u8);
static void ShowFrontierExchangeCornerItemIcon(enum Item);
static void Task_DeoxysRockInteraction(u8);
static void ChangeDeoxysRockLevel(u8);
static void WaitForDeoxysRockMovement(u8);
static void Task_LinkRetireStatusWithBattleTowerPartner(u8);
static void Task_LoopWingFlapSE(u8);
static void Task_CloseBattlePikeCurtain(u8);
static u8 DidPlayerGetFirstFans(void);
static void SetInitialFansOfPlayer(void);
static u16 PlayerGainRandomTrainerFan(void);
static void CB2_ReturnToFieldWhileLearningMove(void);
static void Task_ReturnToFieldWhileLearningMove(u8);
#if FREE_LINK_BATTLE_RECORDS == FALSE
static void BufferFanClubTrainerName_(struct LinkBattleRecords *, u8, u8);
#else
static void BufferFanClubTrainerName_(u8 whichLinkTrainer, u8 whichNPCTrainer);
#endif //FREE_LINK_BATTLE_RECORDS
static void Task_ElevatorShake(u8 taskId);
static void AnimateElevatorWindowView(u16 nfloors, bool8 direction);
static void Task_AnimateElevatorWindowView(u8 taskId);
static void Task_RunPokemonLeagueLightingEffect(u8 taskId);
static void Task_CancelPokemonLeagueLightingEffect(u8 taskId);
static enum Species SampleResortGorgeousMon(void);
static u16 SampleResortGorgeousReward(void);
static void Task_ShakeScreen(u8 taskId);
static void Task_EndScreenShake(u8 taskId);

static const u8 sText_BigGuy[] = _("Big guy");
static const u8 sText_BigGirl[] = _("Big girl");
static const u8 sText_Son[] = _("son");
static const u8 sText_Daughter[] = _("daughter");
static const u8 sText_99TimesPlus[] = _("99 times +");
static const u8 sText_1MinutePlus[] = _("1 minute +");
static const u8 sText_SpaceSeconds[] = _(" seconds");
static const u8 sText_SpaceTimes[] = _(" time(s)");

static const u8 sText_Wallace[] = _("WALLACE");
static const u8 sText_Steven[] = _("STEVEN");
static const u8 sText_Brawly[] = _("BRAWLY");
static const u8 sText_Winona[] = _("WINONA");
static const u8 sText_Phoebe[] = _("PHOEBE");
static const u8 sText_Glacia[] = _("GLACIA");

void Special_ShowDiploma(void)
{
    SetMainCallback2(CB2_ShowDiploma);
    LockPlayerFieldControls();
}

void Special_ViewWallClock(void)
{
    gMain.savedCallback = CB2_ReturnToField;
    SetMainCallback2(CB2_ViewWallClock);
    LockPlayerFieldControls();
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
        StringAppend(gStringVar1, sText_SpaceTimes);
    }
    else
    {
        StringCopy(gStringVar1, sText_99TimesPlus);
    }

    if (numFrames < 3600)
    {
        ConvertIntToDecimalStringN(gStringVar2, numFrames / 60, STR_CONV_MODE_RIGHT_ALIGN, 2);
        gStringVar2[2] = CHAR_DEC_SEPARATOR;
        ConvertIntToDecimalStringN(&gStringVar2[3], ((numFrames % 60) * 100) / 60, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gStringVar2, sText_SpaceSeconds);
    }
    else
    {
        StringCopy(gStringVar2, sText_1MinutePlus);
    }

    result = 0;
    if (numBikeCollisions == 0)
        result = 5;
    else if (numBikeCollisions < 4)
        result = 4;
    else if (numBikeCollisions < 10)
        result = 3;
    else if (numBikeCollisions < 20)
        result = 2;
    else if (numBikeCollisions < 100)
        result = 1;

    if (numFrames / 60 <= 10)
        result += 5;
    else if (numFrames / 60 <= 15)
        result += 4;
    else if (numFrames / 60 <= 20)
        result += 3;
    else if (numFrames / 60 <= 40)
        result += 2;
    else if (numFrames / 60 < 60)
        result += 1;

    gSpecialVar_Result = result;
}

void FinishCyclingRoadChallenge(void)
{
    const u32 numFrames = gMain.vblankCounter1 - sBikeCyclingTimer;

    DetermineCyclingRoadResults(numFrames, gBikeCollisions);
    RecordCyclingRoadResults(numFrames, gBikeCollisions);
}

static void RecordCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
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

u16 GetRecordedCyclingRoadResults(void)
{
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord == 0)
        return FALSE;

    DetermineCyclingRoadResults(framesRecord, VarGet(VAR_CYCLING_ROAD_RECORD_COLLISIONS));
    return TRUE;
}

void UpdateCyclingRoadState(void)
{
    if (gLastUsedWarp.mapNum == MAP_NUM(MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE) && gLastUsedWarp.mapGroup == MAP_GROUP(MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE))
        return;

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
        return FALSE;

    return TRUE;
}

enum SSTidalLocation GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y)
{
    u16 *varCruiseStepCount = GetVarPointer(VAR_CRUISE_STEP_COUNT);

    switch ((enum SSTidalState)(*GetVarPointer(VAR_SS_TIDAL_STATE)))
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
            *mapNum = MAP_NUM(MAP_ROUTE134);
            *x = *varCruiseStepCount + 19;
        }
        else if (*varCruiseStepCount < 140)
        {
            *mapNum = MAP_NUM(MAP_ROUTE133);
            *x = *varCruiseStepCount - 60;
        }
        else
        {
            *mapNum = MAP_NUM(MAP_ROUTE132);
            *x = *varCruiseStepCount - 140;
        }
        break;
    case SS_TIDAL_HALFWAY_SLATEPORT:
        if (*varCruiseStepCount < 66)
        {
            *mapNum = MAP_NUM(MAP_ROUTE132);
            *x = 65 - *varCruiseStepCount;
        }
        else if (*varCruiseStepCount < 146)
        {
            *mapNum = MAP_NUM(MAP_ROUTE133);
            *x = 145 - *varCruiseStepCount;
        }
        else
        {
            *mapNum = MAP_NUM(MAP_ROUTE134);
            *x = 224 - *varCruiseStepCount;
        }
        break;
    }
    *mapGroup = MAP_GROUP(MAP_ROUTE132);
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
                return FALSE;
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
                return FALSE;
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
                return FALSE;
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
                return FALSE;
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
                return FALSE;
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
            StringCopy(GetStringVar(j), gLinkPlayers[i].name);
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
    enum Direction playerFacingDirection;
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
    default:
        break;
    }

    for (i = 0; i < gSpecialVar_0x8004; i++)
    {
        if (myLinkPlayerNumber != i)
        {
            enum GameVersion version = (u8)gLinkPlayers[i].version;
            switch (version)
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
            SpawnSpecialObjectEventParameterized(linkSpriteId, movementTypes[j], LOCALID_BERRY_BLENDER_PLAYER_END - i, coordOffsets[j][0] + x + MAP_OFFSET, coordOffsets[j][1] + y + MAP_OFFSET, 0);
            LoadLinkPartnerObjectEventSpritePalette(linkSpriteId, LOCALID_BERRY_BLENDER_PLAYER_END - i, i);
            j++;
            if (j == MAX_LINK_PLAYERS)
                j = 0;
        }
    }
}

static void LoadLinkPartnerObjectEventSpritePalette(u16 graphicsId, u8 localEventId, u8 paletteNum)
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
                LoadPalette(gObjectEventPal_RubySapphireBrendan, OBJ_PLTT_ID(adjustedPaletteNum), PLTT_SIZE_4BPP);
                break;
            case OBJ_EVENT_GFX_LINK_RS_MAY:
                LoadPalette(gObjectEventPal_RubySapphireMay, OBJ_PLTT_ID(adjustedPaletteNum), PLTT_SIZE_4BPP);
                break;
            case OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL:
                LoadPalette(gObjectEventPal_Brendan, OBJ_PLTT_ID(adjustedPaletteNum), PLTT_SIZE_4BPP);
                break;
            case OBJ_EVENT_GFX_RIVAL_MAY_NORMAL:
                LoadPalette(gObjectEventPal_May, OBJ_PLTT_ID(adjustedPaletteNum), PLTT_SIZE_4BPP);
                break;
            }
        }
    }
}

static const struct UCoords8 sMauvilleGymSwitchCoords[] =
{
    { 0 + MAP_OFFSET, 15 + MAP_OFFSET},
    { 4 + MAP_OFFSET, 12 + MAP_OFFSET},
    { 3 + MAP_OFFSET,  9 + MAP_OFFSET},
    { 8 + MAP_OFFSET,  9 + MAP_OFFSET}
};

// Presses the stepped-on switch and raises the rest
void MauvilleGymPressSwitch(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sMauvilleGymSwitchCoords); i++)
    {
        if (i == gSpecialVar_0x8004)
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_MauvilleGym_PressedSwitch);
        else
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_MauvilleGym_RaisedSwitch);
    }
}

// Sets the gym barriers back to the default state; their alt state is handled by MauvilleCity_Gym_EventScript_SetAltBarriers
void MauvilleGymSetDefaultBarriers(void)
{
    int x, y;
    // All switches/barriers are within these coord ranges
    for (y = 5 + MAP_OFFSET; y < 17 + MAP_OFFSET; y++)
    {
        for (x = 0 + MAP_OFFSET; x < 9 + MAP_OFFSET; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
            case METATILE_MauvilleGym_GreenBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH1_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH2_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH3_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH4_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH1_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH1_On);
                break;
            case METATILE_MauvilleGym_GreenBeamH2_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH2_On);
                break;
            case METATILE_MauvilleGym_GreenBeamH3_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH3_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_GreenBeamH4_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH4_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_RedBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH1_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH2_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH3_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH4_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH1_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH1_On);
                break;
            case METATILE_MauvilleGym_RedBeamH2_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH2_On);
                break;
            case METATILE_MauvilleGym_RedBeamH3_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH3_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_RedBeamH4_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH4_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_GreenBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_GreenBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_FloorTile);
                break;
            case METATILE_MauvilleGym_RedBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_Off | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_RedBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_FloorTile);
                break;
            case METATILE_MauvilleGym_PoleBottom_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamV1_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_FloorTile:
                if (MapGridGetMetatileIdAt(x, y - 1) == METATILE_MauvilleGym_GreenBeamV1_On)
                    MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamV2_On | MAPGRID_IMPASSABLE);
                else
                    MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamV2_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_PoleBottom_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamV1_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_PoleTop_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleTop_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_PoleTop_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleTop_Off);
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
        MapGridSetMetatileIdAt(switchCoords->x, switchCoords->y, METATILE_MauvilleGym_PressedSwitch);
        switchCoords++;
    }
    for (y = 5 + MAP_OFFSET; y < 17 + MAP_OFFSET; y++)
    {
        for (x = 0 + MAP_OFFSET; x < 9 + MAP_OFFSET; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
            case METATILE_MauvilleGym_GreenBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH1_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH2_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH3_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH4_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH1_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH2_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH3_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH4_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_On | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_RedBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_Off | MAPGRID_IMPASSABLE);
                break;
            case METATILE_MauvilleGym_GreenBeamV2_On:
            case METATILE_MauvilleGym_RedBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_FloorTile);
                break;
            case METATILE_MauvilleGym_PoleTop_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleTop_Off);
                break;
            }
        }
    }
}

static const bool8 sSlidingDoorNextFrameDelay[] = {0, 1, 1, 1, 1};

static const u16 sPetalburgGymSlidingDoorMetatiles[] = {
    METATILE_PetalburgGym_SlidingDoor_Frame0,
    METATILE_PetalburgGym_SlidingDoor_Frame1,
    METATILE_PetalburgGym_SlidingDoor_Frame2,
    METATILE_PetalburgGym_SlidingDoor_Frame3,
    METATILE_PetalburgGym_SlidingDoor_Frame4,
};

void PetalburgGymSlideOpenRoomDoors(void)
{
    sSlidingDoorNextFrameCounter = 0;
    sSlidingDoorFrame = 0;
    PlaySE(SE_UNLOCK);
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
            ScriptContext_Enable();
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
        MapGridSetMetatileIdAt(doorCoordsX[i] + MAP_OFFSET, doorCoordsY[i] + MAP_OFFSET, metatileId | MAPGRID_IMPASSABLE);
        MapGridSetMetatileIdAt(doorCoordsX[i] + MAP_OFFSET, doorCoordsY[i] + MAP_OFFSET + 1, (metatileId + METATILE_ROW_WIDTH) | MAPGRID_IMPASSABLE);
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
        StringCopy(gStringVar1, sText_BigGuy);
    else
        StringCopy(gStringVar1, sText_BigGirl);
}

void GetRivalSonDaughterString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        StringCopy(gStringVar1, sText_Daughter);
    else
        StringCopy(gStringVar1, sText_Son);
}

u8 GetBattleOutcome(void)
{
    return gBattleOutcome;
}

void CableCarWarp(void)
{
    if (gSpecialVar_0x8004 != 0)
        SetWarpDestination(MAP_GROUP(MAP_ROUTE112_CABLE_CAR_STATION), MAP_NUM(MAP_ROUTE112_CABLE_CAR_STATION), WARP_ID_NONE, 6, 4);
    else
        SetWarpDestination(MAP_GROUP(MAP_MT_CHIMNEY_CABLE_CAR_STATION), MAP_NUM(MAP_MT_CHIMNEY_CABLE_CAR_STATION), WARP_ID_NONE, 6, 4);
}

void SetHiddenItemFlag(void)
{
    FlagSet(gSpecialVar_0x8004);
}

u16 GetWeekCount(void)
{
    u16 weekCount = gLocalTime.days / 7;
    if (weekCount > 9999)
        weekCount = 9999;

    return weekCount;
}

u8 GetLeadMonFriendshipScore(void)
{
    return GetMonFriendshipScore(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()]);
}

static void CB2_FieldShowRegionMap(void)
{
    FieldInitRegionMap(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void FieldShowRegionMap(void)
{
    SetMainCallback2(CB2_FieldShowRegionMap);
}

static bool32 IsBuildingPCTile(u32 tileId)
{
    if (IS_FRLG)
        return FALSE;

    return (MetatileBehavior_IsPC(GetAttributeByMetatileIdAndMapLayout(tileId, METATILE_ATTRIBUTE_BEHAVIOR, FALSE)));
}

static bool32 IsBuildingPCTileFrlg(u32 tileId)
{
    if (IS_FRLG)
        return gMapHeader.mapLayout->primaryTileset == &gTileset_BuildingFrlg && (tileId == METATILE_BuildingFrlg_PCOn || tileId == METATILE_BuildingFrlg_PCOff);

    return FALSE;
}

static bool32 IsPlayerHousePCTile(u32 tileId)
{
    if (IS_FRLG)
        return FALSE;

    return gMapHeader.mapLayout->secondaryTileset == &gTileset_BrendansMaysHouse
        && (tileId == METATILE_BrendansMaysHouse_BrendanPC_On
            || tileId == METATILE_BrendansMaysHouse_BrendanPC_Off
            || tileId == METATILE_BrendansMaysHouse_MayPC_On
            || tileId == METATILE_BrendansMaysHouse_MayPC_Off);
}

static bool32 IsPlayerHousePCTileFrlg(u32 tileId)
{
    if (IS_FRLG)
        return gMapHeader.mapLayout->secondaryTileset == &gTileset_GenericBuilding1
            && (tileId == METATILE_GenericBuilding1_PlayersPCOn || tileId == METATILE_GenericBuilding1_PlayersPCOff);

    return FALSE;
}

static bool8 IsPlayerInFrontOfPC(void)
{
    s16 x, y;
    u32 tileInFront;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tileInFront = MapGridGetMetatileIdAt(x, y);

    return IsBuildingPCTile(tileInFront)
        || IsBuildingPCTileFrlg(tileInFront)
        || IsPlayerHousePCTile(tileInFront)
        || IsPlayerHousePCTileFrlg(tileInFront);
}

// Task data for Task_PCTurnOnEffect and Task_LotteryCornerComputerEffect
#define tPaused       data[0] // Never set
#define tTaskId       data[1]
#define tFlickerCount data[2]
#define tTimer        data[3]
#define tIsScreenOn   data[4]

// For this special, gSpecialVar_0x8004 is expected to be some PC_LOCATION_* value.
void DoPCTurnOnEffect(void)
{
    if (FuncIsActiveTask(Task_PCTurnOnEffect) != TRUE && IsPlayerInFrontOfPC() == TRUE)
    {
        u8 taskId = CreateTask(Task_PCTurnOnEffect, 8);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].tTaskId = taskId;
        gTasks[taskId].tFlickerCount = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tIsScreenOn = FALSE;
    }
}

static void Task_PCTurnOnEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->tPaused)
        PCTurnOnEffect(task);
}

static void PCTurnOnEffect(struct Task *task)
{
    enum Direction playerDirection;
    s8 dx = 0;
    s8 dy = 0;
    if (task->tTimer == 6)
    {
        task->tTimer = 0;

        // Get where the PC should be, depending on where the player is looking.
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
        default:
            break;
        }

        // Update map
        PCTurnOnEffect_SetMetatile(task->tIsScreenOn, dx, dy);
        DrawWholeMapView();

        // Screen flickers 5 times. Odd number and starting with the
        // screen off means the animation ends with the screen on.
        task->tIsScreenOn ^= 1;
        if (++task->tFlickerCount == 5)
            DestroyTask(task->tTaskId);
    }
    task->tTimer++;
}

static void PCTurnOnEffect_SetMetatile(s16 isScreenOn, s8 dx, s8 dy)
{
    u16 metatileId = 0;
    if (isScreenOn)
    {
        // Screen is on, set it off
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
            metatileId = IS_FRLG ? METATILE_BuildingFrlg_PCOff : METATILE_Building_PC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_BrendanPC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_MayPC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_PLAYER_HOUSE_FRLG)
            metatileId = METATILE_GenericBuilding1_PlayersPCOff;
    }
    else
    {
        // Screen is off, set it on
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
            metatileId = IS_FRLG ? METATILE_BuildingFrlg_PCOn : METATILE_Building_PC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_BrendanPC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_MayPC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_PLAYER_HOUSE_FRLG)
            metatileId = METATILE_GenericBuilding1_PlayersPCOn;
    }
    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + MAP_OFFSET, gSaveBlock1Ptr->pos.y + dy + MAP_OFFSET, metatileId | MAPGRID_IMPASSABLE);
}

// For this special, gSpecialVar_0x8004 is expected to be some PC_LOCATION_* value.
void DoPCTurnOffEffect(void)
{
    PCTurnOffEffect();
}

static void PCTurnOffEffect(void)
{
    s8 dx = 0;
    s8 dy = 0;
    u16 metatileId = 0;

    // Get where the PC should be, depending on where the player is looking.
    enum Direction playerDirection = GetPlayerFacingDirection();

    if (IsPlayerInFrontOfPC() == FALSE)
        return;
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
    default:
        break;
    }

    if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
        metatileId = IS_FRLG ? METATILE_BuildingFrlg_PCOff : METATILE_Building_PC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
        metatileId = METATILE_BrendansMaysHouse_BrendanPC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
        metatileId = METATILE_BrendansMaysHouse_MayPC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_PLAYER_HOUSE_FRLG)
        metatileId = METATILE_GenericBuilding1_PlayersPCOff;

    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + MAP_OFFSET, gSaveBlock1Ptr->pos.y + dy + MAP_OFFSET, metatileId | MAPGRID_IMPASSABLE);
    DrawWholeMapView();
}

void DoLotteryCornerComputerEffect(void)
{
    if (FuncIsActiveTask(Task_LotteryCornerComputerEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_LotteryCornerComputerEffect, 8);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].tTaskId = taskId;
        gTasks[taskId].tFlickerCount = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tIsScreenOn = FALSE;
    }
}

static void Task_LotteryCornerComputerEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->tPaused)
        LotteryCornerComputerEffect(task);
}

static void LotteryCornerComputerEffect(struct Task *task)
{
    if (task->tTimer == 6)
    {
        task->tTimer = 0;
        if (task->tIsScreenOn)
        {
            // Screen is on, set it off
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Normal | MAPGRID_IMPASSABLE);
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Normal | MAPGRID_IMPASSABLE);
        }
        else
        {
            // Screen is off, set it on
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Flash | MAPGRID_IMPASSABLE);
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Flash | MAPGRID_IMPASSABLE);
        }
        DrawWholeMapView();

        // Screen flickers 5 times. Odd number and starting with the
        // screen off means the animation ends with the screen on.
        task->tIsScreenOn ^= 1;
        if (++task->tFlickerCount == 5)
            DestroyTask(task->tTaskId);
    }
    task->tTimer++;
}

void EndLotteryCornerComputerEffect(void)
{
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Normal | MAPGRID_IMPASSABLE);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Normal | MAPGRID_IMPASSABLE);
    DrawWholeMapView();
}

#undef tPaused
#undef tTaskId
#undef tFlickerCount
#undef tTimer
#undef tIsScreenOn

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
    if (GetMonData(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()], MON_DATA_COOL) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonBeauty(void)
{
    if (GetMonData(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()], MON_DATA_BEAUTY) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonCute(void)
{
    if (GetMonData(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()], MON_DATA_CUTE) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonSmart(void)
{
    if (GetMonData(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()], MON_DATA_SMART) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonTough(void)
{
    if (GetMonData(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()], MON_DATA_TOUGH) < 200)
        return FALSE;

    return TRUE;
}

void IsGrassTypeInParty(void)
{
    u8 i;
    enum Species species;
    struct Pokemon *pokemon;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gParties[B_TRAINER_PLAYER][i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData(pokemon, MON_DATA_SPECIES);
            if (GetSpeciesType(species, 0) == TYPE_GRASS || GetSpeciesType(species, 1) == TYPE_GRASS)
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
    u8 obj = SpawnSpecialObjectEventParameterized(OBJ_EVENT_GFX_BOY_1,
                                                  MOVEMENT_TYPE_FACE_DOWN,
                                                  LOCALID_CAMERA,
                                                  gSaveBlock1Ptr->pos.x + MAP_OFFSET,
                                                  gSaveBlock1Ptr->pos.y + MAP_OFFSET,
                                                  ELEVATION_DEFAULT);
    gObjectEvents[obj].invisible = TRUE;
    CameraObjectSetFollowedSpriteId(gObjectEvents[obj].spriteId);
}

void RemoveCameraObject(void)
{
    CameraObjectSetFollowedSpriteId(GetPlayerAvatarSpriteId());
    RemoveObjectEventByLocalIdAndMap(LOCALID_CAMERA, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

u8 GetPokeblockNameByMonNature(void)
{
    return CopyMonFavoritePokeblockName(GetNature(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()]), gStringVar1);
}

void GetSecretBaseNearbyMapName(void)
{
    GetMapName(gStringVar1, VarGet(VAR_SECRET_BASE_MAP), 0);
}

u16 GetBattleTowerSinglesStreak(void)
{
    return GetGameStat(GAME_STAT_BATTLE_TOWER_SINGLES_STREAK);
}

void BufferEReaderTrainerName(void)
{
    GetEreaderTrainerName(gStringVar1);
}

u16 GetSlotMachineId(void)
{
    static const u8 sSlotMachineRandomSeeds[SLOT_MACHINE_COUNT] = {12, 2, 4, 5, 1, 8, 7, 11, 3, 10, 9, 6};
    static const u8 sSlotMachineIds[SLOT_MACHINE_COUNT] = {
        SLOT_MACHINE_UNLUCKIEST,
        SLOT_MACHINE_UNLUCKIER,
        SLOT_MACHINE_UNLUCKIER,
        SLOT_MACHINE_UNLUCKY,
        SLOT_MACHINE_UNLUCKY,
        SLOT_MACHINE_UNLUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKIER,
        SLOT_MACHINE_LUCKIER,
        SLOT_MACHINE_LUCKIEST
    };
    static const u8 sSlotMachineServiceDayIds[SLOT_MACHINE_COUNT] = {
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKY,
        SLOT_MACHINE_LUCKIER,
        SLOT_MACHINE_LUCKIER,
        SLOT_MACHINE_LUCKIER,
        SLOT_MACHINE_LUCKIER,
        SLOT_MACHINE_LUCKIEST,
        SLOT_MACHINE_LUCKIEST
    };

    u32 rnd = gSaveBlock1Ptr->dewfordTrends[0].trendiness + gSaveBlock1Ptr->dewfordTrends[0].rand + sSlotMachineRandomSeeds[gSpecialVar_0x8004];
    if (IsPokeNewsActive(POKENEWS_GAME_CORNER))
        return sSlotMachineServiceDayIds[rnd % SLOT_MACHINE_COUNT];

    return sSlotMachineIds[rnd % SLOT_MACHINE_COUNT];
}

bool8 FoundAbandonedShipRoom1Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 FoundAbandonedShipRoom2Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 FoundAbandonedShipRoom4Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 FoundAbandonedShipRoom6Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 LeadMonHasEffortRibbon(void)
{
    return GetMonData(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()], MON_DATA_EFFORT_RIBBON);
}

void GiveLeadMonEffortRibbon(void)
{
    bool8 ribbonSet;
    struct Pokemon *leadMon;
    IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
    FlagSet(FLAG_SYS_RIBBON_GET);
    ribbonSet = TRUE;
    leadMon = &gParties[B_TRAINER_PLAYER][GetLeadMonIndex()];
    SetMonData(leadMon, MON_DATA_EFFORT_RIBBON, &ribbonSet);
    if (GetRibbonCount(leadMon) > NUM_CUTIES_RIBBONS)
        TryPutSpotTheCutiesOnAir(leadMon, MON_DATA_EFFORT_RIBBON);
}

bool8 Special_AreLeadMonEVsMaxedOut(void)
{
    if (GetMonEVCount(&gParties[B_TRAINER_PLAYER][GetLeadMonIndex()]) >= MAX_TOTAL_EVS)
        return TRUE;

    return FALSE;
}

u8 TryUpdateRusturfTunnelState(void)
{
    if (!FlagGet(FLAG_RUSTURF_TUNNEL_OPENED)
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUSTURF_TUNNEL)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_RUSTURF_TUNNEL))
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

void LoadWallyZigzagoon(void)
{
    u16 monData;
    CreateRandomMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_ZIGZAGOON, 7);
    monData = TRUE;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_ABILITY_NUM, &monData);
    monData = MOVE_TACKLE;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1, &monData);
    monData = MOVE_NONE;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE2, &monData);
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE3, &monData);
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4, &monData);
}

bool8 IsStarterInParty(void)
{
    u8 i;
    u16 starter = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) == starter)
            return TRUE;
    }
    return FALSE;
}

bool8 ScriptCheckFreePokemonStorageSpace(void)
{
    return CheckFreePokemonStorageSpace();
}

// Task data for Task_ShakeCamera
#define tHorizontalPan  data[0]
#define tDelayCounter   data[1]
#define tNumShakes      data[2]
#define tDelay          data[3]
#define tVerticalPan    data[4]

void ShakeCamera(void)
{
    u8 taskId = CreateTask(Task_ShakeCamera, 9);
    gTasks[taskId].tHorizontalPan = gSpecialVar_0x8005;
    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tNumShakes = gSpecialVar_0x8006;
    gTasks[taskId].tDelay = gSpecialVar_0x8007;
    gTasks[taskId].tVerticalPan = gSpecialVar_0x8004;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_M_STRENGTH);
}

static void Task_ShakeCamera(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tDelayCounter++;
    if (tDelayCounter % tDelay == 0)
    {
        tDelayCounter = 0;
        tNumShakes--;
        tHorizontalPan = -tHorizontalPan;
        tVerticalPan = -tVerticalPan;
        SetCameraPanning(tHorizontalPan, tVerticalPan);
        if (tNumShakes == 0)
        {
            StopCameraShake(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void StopCameraShake(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#undef tHorizontalPan
#undef tDelayCounter
#undef tNumShakes
#undef tDelay
#undef tVerticalPan

bool8 FoundBlackGlasses(void)
{
    return FlagGet(FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES);
}

void SetRoute119Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
        SetSavedWeather(WEATHER_ROUTE119_CYCLE);
}

void SetRoute123Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
        SetSavedWeather(WEATHER_ROUTE123_CYCLE);
}

u8 GetLeadMonIndex(void)
{
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE)
            return i;
    }
    return 0;
}

enum Species ScriptGetPartyMonSpecies(void)
{
    return GetMonData(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], MON_DATA_SPECIES_OR_EGG, NULL);
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
        return 0;
    else if (gLocalTime.days < 0)
        return 8;

    return 7 - (gLocalTime.days - tmReceivedDay);
}

u16 SetPacifidlogTMReceivedDay(void)
{
    VarSet(VAR_PACIFIDLOG_TM_RECEIVED_DAY, gLocalTime.days);
    return gLocalTime.days;
}

bool8 MonOTNameNotPlayer(void)
{
    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();
    if (GetBoxMonData(boxmon, MON_DATA_LANGUAGE) != GAME_LANGUAGE)
        return TRUE;

    GetBoxMonData(boxmon, MON_DATA_OT_NAME, gStringVar1);

    if (!StringCompare(gSaveBlock2Ptr->playerName, gStringVar1))
        return FALSE;

    return TRUE;
}

void BufferLottoTicketNumber(void)
{
    if (gSpecialVar_Result >= 10000)
    {
        ConvertIntToDecimalString(0, gSpecialVar_Result);
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

u16 GetMysteryGiftCardStat(void)
{
    switch (gSpecialVar_Result)
    {
    case GET_NUM_STAMPS:
        return MysteryGift_GetCardStat(CARD_STAT_NUM_STAMPS);
    case GET_MAX_STAMPS:
        return MysteryGift_GetCardStat(CARD_STAT_MAX_STAMPS);
    case GET_CARD_BATTLES_WON:
        return MysteryGift_GetCardStat(CARD_STAT_BATTLES_WON);
    case GET_CARD_BATTLES_LOST: // Never occurs
        return MysteryGift_GetCardStat(CARD_STAT_BATTLES_LOST);
    case GET_CARD_NUM_TRADES: // Never occurs
        return MysteryGift_GetCardStat(CARD_STAT_NUM_TRADES);
    default:
        return 0;
    }
}

bool8 BufferTMHMMoveName(void)
{
    if (gItemsInfo[gSpecialVar_0x8004].pocket == POCKET_TM_HM)
    {
        StringCopy(gStringVar2, GetMoveName(ItemIdToBattleMoveId(gSpecialVar_0x8004)));
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
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SANITY_IS_BAD_EGG) == TRUE)
            return TRUE;
    }

    return FALSE;
}

bool8 InMultiPartnerRoom(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM) &&
        VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_MULTIS)
        return TRUE;
    return FALSE;
}

void OffsetCameraForBattle(void)
{
    SetCameraPanningCallback(NULL);
    SetCameraPanning(8, 0);
}

static const struct WindowTemplate sWindowTemplate_ElevatorFloor =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 1,
    .width = 8,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 8,
};

static const u8 *const sDeptStoreFloorNames[] =
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

static const u16 sElevatorWindowTiles_Ascending[ELEVATOR_WINDOW_HEIGHT][ELEVATOR_LIGHT_STAGES] =
{
    {
        METATILE_BattleFrontier_Elevator_Top0,
        METATILE_BattleFrontier_Elevator_Top1,
        METATILE_BattleFrontier_Elevator_Top2
    },
    {
        METATILE_BattleFrontier_Elevator_Mid0,
        METATILE_BattleFrontier_Elevator_Mid1,
        METATILE_BattleFrontier_Elevator_Mid2
    },
    {
        METATILE_BattleFrontier_Elevator_Bottom0,
        METATILE_BattleFrontier_Elevator_Bottom1,
        METATILE_BattleFrontier_Elevator_Bottom2
    },
};

static const u16 sElevatorWindowTiles_Descending[ELEVATOR_WINDOW_HEIGHT][ELEVATOR_LIGHT_STAGES] =
{
    {
        METATILE_BattleFrontier_Elevator_Top0,
        METATILE_BattleFrontier_Elevator_Top2,
        METATILE_BattleFrontier_Elevator_Top1
    },
    {
        METATILE_BattleFrontier_Elevator_Mid0,
        METATILE_BattleFrontier_Elevator_Mid2,
        METATILE_BattleFrontier_Elevator_Mid1
    },
    {
        METATILE_BattleFrontier_Elevator_Bottom0,
        METATILE_BattleFrontier_Elevator_Bottom2,
        METATILE_BattleFrontier_Elevator_Bottom1
    },
};

void SetDeptStoreFloor(void)
{
    enum DeptStoreFloorNumber deptStoreFloor;
    switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
    {
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_1F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_2F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_3F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_4F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_5F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP):
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
    sLilycoveDeptStore_DefaultFloorChoice = 0;

    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F):
            sLilycoveDeptStore_DefaultFloorChoice = 0;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F):
            sLilycoveDeptStore_DefaultFloorChoice = 1;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F):
            sLilycoveDeptStore_DefaultFloorChoice = 2;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F):
            sLilycoveDeptStore_DefaultFloorChoice = 3;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F):
            sLilycoveDeptStore_DefaultFloorChoice = 4;
            break;
        }
    }

    return sLilycoveDeptStore_DefaultFloorChoice;
}

// Task data for Task_MoveElevator
#define tTimer       data[1]
#define tMoveCounter data[2]
#define tVerticalPan data[4]
#define tTotalMoves  data[5]
#define tDescending  data[6]

// The maximum considered difference between floors.
// Elevator trips with a larger difference are treated the same
// (i.e. traveling 9 floors and 200 floors would take the same amount of time).
#define MAX_ELEVATOR_TRIP 9

// gSpecialVar_0x8005 here is expected to be the current floor number, and
// gSpecialVar_0x8006 is expected to be the destination floor number.
void MoveElevator(void)
{
    static const u8 sElevatorTripLength[MAX_ELEVATOR_TRIP] = { 8, 16, 24, 32, 38, 46, 52, 56, 57 };

    s16 *data = gTasks[CreateTask(Task_MoveElevator, 9)].data;
    u16 floorDelta;

    tTimer = 0;
    tMoveCounter = 0;
    tVerticalPan = 1;

    if (gSpecialVar_0x8005 > gSpecialVar_0x8006)
    {
        floorDelta = gSpecialVar_0x8005 - gSpecialVar_0x8006;
        tDescending = TRUE;
    }
    else
    {
        floorDelta = gSpecialVar_0x8006 - gSpecialVar_0x8005;
        tDescending = FALSE;
    }

    if (floorDelta > MAX_ELEVATOR_TRIP - 1)
        floorDelta = MAX_ELEVATOR_TRIP - 1;

    tTotalMoves = sElevatorTripLength[floorDelta];

    SetCameraPanningCallback(NULL);
    MoveElevatorWindowLights(floorDelta, tDescending);
    PlaySE(SE_ELEVATOR);
}

static void Task_MoveElevator(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tTimer++;
    if (tTimer % 3 == 0)
    {
        tTimer = 0;
        tMoveCounter++;
        tVerticalPan = -tVerticalPan;
        SetCameraPanning(0, tVerticalPan);

        if (tMoveCounter == tTotalMoves)
        {
            // Arrived at floor
            PlaySE(SE_DING_DONG);
            DestroyTask(taskId);
            ScriptContext_Enable();
            InstallCameraPanAheadCallback();
        }
    }
}

#undef tTimer
#undef tMoveCounter
#undef tVerticalPan
#undef tTotalMoves
#undef tDescending

void ShowDeptStoreElevatorFloorSelect(void)
{
    int xPos;

    sTutorMoveAndElevatorWindowId = AddWindow(&sWindowTemplate_ElevatorFloor);
    SetStandardWindowBorderStyle(sTutorMoveAndElevatorWindowId, FALSE);

    xPos = GetStringCenterAlignXOffset(FONT_NORMAL, gText_ElevatorNowOn, 64);
    AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, FONT_NORMAL, gText_ElevatorNowOn, xPos, 1, TEXT_SKIP_DRAW, NULL);

    xPos = GetStringCenterAlignXOffset(FONT_NORMAL, sDeptStoreFloorNames[gSpecialVar_0x8005], 64);
    AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, FONT_NORMAL, sDeptStoreFloorNames[gSpecialVar_0x8005], xPos, 17, TEXT_SKIP_DRAW, NULL);

    PutWindowTilemap(sTutorMoveAndElevatorWindowId);
    CopyWindowToVram(sTutorMoveAndElevatorWindowId, COPYWIN_FULL);
}

void CloseDeptStoreElevatorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sTutorMoveAndElevatorWindowId, TRUE);
    RemoveWindow(sTutorMoveAndElevatorWindowId);
}

// Task data for Task_MoveElevatorWindowLights
#define tMoveCounter data[0]
#define tTimer       data[1]
#define tDescending  data[2]
#define tTotalMoves  data[3]

static void MoveElevatorWindowLights(u16 floorDelta, bool8 descending)
{
    static const u8 sElevatorLightCycles[MAX_ELEVATOR_TRIP] = { 3, 6, 9, 12, 15, 18, 21, 24, 27 };

    if (FuncIsActiveTask(Task_MoveElevatorWindowLights) != TRUE)
    {
        u8 taskId = CreateTask(Task_MoveElevatorWindowLights, 8);
        gTasks[taskId].tMoveCounter = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tDescending = descending;
        gTasks[taskId].tTotalMoves = sElevatorLightCycles[floorDelta];
    }
}

static void Task_MoveElevatorWindowLights(u8 taskId)
{
    u8 x, y;
    s16 *data = gTasks[taskId].data;

    if (tTimer == 6)
    {
        tMoveCounter++;

        if (!tDescending)
        {
            // Ascending
            for (y = 0; y < ELEVATOR_WINDOW_HEIGHT; y++)
            {
                for (x = 0; x < ELEVATOR_WINDOW_WIDTH; x++)
                    MapGridSetMetatileIdAt(x + MAP_OFFSET + 1, y + MAP_OFFSET, sElevatorWindowTiles_Ascending[y][tMoveCounter % ELEVATOR_LIGHT_STAGES] | MAPGRID_IMPASSABLE);
            }
        }
        else
        {
            // Descending
            for (y = 0; y < ELEVATOR_WINDOW_HEIGHT; y++)
            {
                for (x = 0; x < ELEVATOR_WINDOW_WIDTH; x++)
                    MapGridSetMetatileIdAt(x + MAP_OFFSET + 1, y + MAP_OFFSET, sElevatorWindowTiles_Descending[y][tMoveCounter % ELEVATOR_LIGHT_STAGES] | MAPGRID_IMPASSABLE);
            }
        }
        DrawWholeMapView();
        tTimer = 0;
        if (tMoveCounter == tTotalMoves)
            DestroyTask(taskId);
    }
    tTimer++;
}

#undef tMoveCounter
#undef tTimer
#undef tDescending
#undef tTotalMoves

void BufferVarsForIVRater(void)
{
    u32 i;
    u32 ivStorage[NUM_STATS];

    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();;

    for (i = 0; i < NUM_STATS; i++)
    {
       ivStorage[i] = GetBoxMonData(boxmon, MON_DATA_HP_IV + i);
    }

    gSpecialVar_0x8005 = 0;

    for (i = 0; i < NUM_STATS; i++)
        gSpecialVar_0x8005 += ivStorage[i];

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
        MAP_UNDEFINED
    };

    int i;
    u16 map = (gLastUsedWarp.mapGroup << 8) + gLastUsedWarp.mapNum;

    for (i = 0; sPokemonCenters[i] != MAP_UNDEFINED; i++)
    {
        if (sPokemonCenters[i] == map)
            return TRUE;
    }

    return FALSE;
}

bool32 PlayerNotAtTrainerHillEntrance(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_TRAINER_HILL_ENTRANCE) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_TRAINER_HILL_ENTRANCE))
        return FALSE;

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
        [FRONTIER_MANIAC_TOWER_SINGLES] =
        {
            BattleFrontier_Lounge2_Text_SalonMaidenIsThere,
            BattleFrontier_Lounge2_Text_SalonMaidenSilverMons,
            BattleFrontier_Lounge2_Text_SalonMaidenGoldMons
        },
        [FRONTIER_MANIAC_TOWER_DOUBLES] =
        {
            BattleFrontier_Lounge2_Text_DoubleBattleAdvice1,
            BattleFrontier_Lounge2_Text_DoubleBattleAdvice2,
            BattleFrontier_Lounge2_Text_DoubleBattleAdvice3
        },
        [FRONTIER_MANIAC_TOWER_MULTIS] =
        {
            BattleFrontier_Lounge2_Text_MultiBattleAdvice,
            BattleFrontier_Lounge2_Text_MultiBattleAdvice,
            BattleFrontier_Lounge2_Text_MultiBattleAdvice
        },
        [FRONTIER_MANIAC_TOWER_LINK] =
        {
            BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice,
            BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice,
            BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice
        },
        [FRONTIER_MANIAC_DOME] =
        {
            BattleFrontier_Lounge2_Text_DomeAceIsThere,
            BattleFrontier_Lounge2_Text_DomeAceSilverMons,
            BattleFrontier_Lounge2_Text_DomeAceGoldMons
        },
        [FRONTIER_MANIAC_FACTORY] =
        {
            BattleFrontier_Lounge2_Text_FactoryHeadIsThere,
            BattleFrontier_Lounge2_Text_FactoryHeadSilverMons,
            BattleFrontier_Lounge2_Text_FactoryHeadGoldMons
        },
        [FRONTIER_MANIAC_PALACE] =
        {
            BattleFrontier_Lounge2_Text_PalaceMavenIsThere,
            BattleFrontier_Lounge2_Text_PalaceMavenSilverMons,
            BattleFrontier_Lounge2_Text_PalaceMavenGoldMons
        },
        [FRONTIER_MANIAC_ARENA] =
        {
            BattleFrontier_Lounge2_Text_ArenaTycoonIsThere,
            BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons,
            BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons
        },
        [FRONTIER_MANIAC_PIKE] =
        {
            BattleFrontier_Lounge2_Text_PikeQueenIsThere,
            BattleFrontier_Lounge2_Text_PikeQueenSilverMons,
            BattleFrontier_Lounge2_Text_PikeQueenGoldMons
        },
        [FRONTIER_MANIAC_PYRAMID] =
        {
            BattleFrontier_Lounge2_Text_PyramidKingIsThere,
            BattleFrontier_Lounge2_Text_PyramidKingSilverMons,
            BattleFrontier_Lounge2_Text_PyramidKingGoldMons
        },
    };

    static const u8 sFrontierManiacStreakThresholds[][FRONTIER_MANIAC_MESSAGE_COUNT - 1] =
    {
        [FRONTIER_MANIAC_TOWER_SINGLES] = { 21, 56 },
        [FRONTIER_MANIAC_TOWER_DOUBLES] = { 21, 35 },
        [FRONTIER_MANIAC_TOWER_MULTIS]  = { 255, 255 },
        [FRONTIER_MANIAC_TOWER_LINK]    = { 255, 255 },
        [FRONTIER_MANIAC_DOME]          = { 2, 4 },
        [FRONTIER_MANIAC_FACTORY]       = { 7, 21 },
        [FRONTIER_MANIAC_PALACE]        = { 7, 21 },
        [FRONTIER_MANIAC_ARENA]         = { 14, 28 },
        [FRONTIER_MANIAC_PIKE]          = { 13, 112 }, //BUG: 112 (0x70) is probably a mistake; the Pike Queen is battled twice well before that
        [FRONTIER_MANIAC_PYRAMID]       = { 7, 56 }
    };

    u8 i;
    u16 winStreak = 0;
    u16 facility = VarGet(VAR_FRONTIER_MANIAC_FACILITY);

    switch (facility)
    {
    case FRONTIER_MANIAC_TOWER_SINGLES:
    case FRONTIER_MANIAC_TOWER_DOUBLES:
    case FRONTIER_MANIAC_TOWER_MULTIS:
    case FRONTIER_MANIAC_TOWER_LINK:
        if (gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[facility][FRONTIER_LVL_OPEN];
        break;
    case FRONTIER_MANIAC_DOME:
        if (gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN];
        break;
    case FRONTIER_MANIAC_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN];
        break;
    case FRONTIER_MANIAC_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_OPEN];
        break;
    case FRONTIER_MANIAC_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[FRONTIER_LVL_OPEN];
        break;
    case FRONTIER_MANIAC_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[FRONTIER_LVL_OPEN];
        break;
    case FRONTIER_MANIAC_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50]
            >= gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN])
            winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50];
        else
            winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN];
        break;
    default:
        return;
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
    enum FrontierLevelMode lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

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

    switch ((enum ScrollMulti)gSpecialVar_0x8004)
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
    case SCROLL_MULTI_BADGES:
        task->tMaxItemsOnScreen = 4;
        task->tNumItems = 9;
        task->tLeft = 1;
        task->tTop = 1;
        task->tWidth = 12;
        task->tHeight = 8;
        task->tKeepOpenAfterSelect = FALSE;
        task->tTaskId = taskId;
        break;
    case SCROLL_MULTI_SILPHCO_FLOORS:
        task->tMaxItemsOnScreen = MAX_SCROLL_MULTI_ON_SCREEN;
        task->tNumItems = 12;
        task->tLeft = 1;
        task->tTop = 1;
        task->tWidth = 8;
        task->tHeight = 12;
        task->tKeepOpenAfterSelect = FALSE;
        task->tTaskId = taskId;
        task->tScrollOffset = sElevatorScroll;
        task->tSelectedRow = sElevatorCursorPos;
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
        COMPOUND_STRING("BLUE FLUTE"),
        COMPOUND_STRING("YELLOW FLUTE"),
        COMPOUND_STRING("RED FLUTE"),
        COMPOUND_STRING("WHITE FLUTE"),
        COMPOUND_STRING("BLACK FLUTE"),
        COMPOUND_STRING("PRETTY CHAIR"),
        COMPOUND_STRING("PRETTY DESK"),
        gText_Exit
    },
    [SCROLL_MULTI_POKEMON_FAN_CLUB_RATER] =
    {
        COMPOUND_STRING("0 pts"),
        COMPOUND_STRING("10 pts"),
        COMPOUND_STRING("20 pts"),
        COMPOUND_STRING("30 pts"),
        COMPOUND_STRING("40 pts"),
        COMPOUND_STRING("50 pts"),
        COMPOUND_STRING("60 pts"),
        COMPOUND_STRING("70 pts"),
        COMPOUND_STRING("80 pts"),
        COMPOUND_STRING("90 pts"),
        COMPOUND_STRING("100 pts"),
        COMPOUND_STRING("?")
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1] =
    {
        COMPOUND_STRING("KISS POSTER{CLEAR_TO 94}16BP"),
        COMPOUND_STRING("KISS CUSHION{CLEAR_TO 94}32BP"),
        COMPOUND_STRING("SMOOCHUM DOLL{CLEAR_TO 94}32BP"),
        COMPOUND_STRING("TOGEPI DOLL{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("MEOWTH DOLL{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("CLEFAIRY DOLL{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("DITTO DOLL{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("CYNDAQUIL DOLL{CLEAR_TO 94}80BP"),
        COMPOUND_STRING("CHIKORITA DOLL{CLEAR_TO 94}80BP"),
        COMPOUND_STRING("TOTODILE DOLL{CLEAR_TO 94}80BP"),
        gText_Exit
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2] =
    {
        COMPOUND_STRING("LAPRAS DOLL{CLEAR_TO 88}128BP"),
        COMPOUND_STRING("SNORLAX DOLL{CLEAR_TO 88}128BP"),
        COMPOUND_STRING("VENUSAUR DOLL{CLEAR_TO 88}256BP"),
        COMPOUND_STRING("CHARIZARD DOLL{CLEAR_TO 88}256BP"),
        COMPOUND_STRING("BLASTOISE DOLL{CLEAR_TO 88}256BP"),
        gText_Exit
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR] =
    {
        COMPOUND_STRING("PROTEIN{CLEAR_TO 100}1BP"),
        COMPOUND_STRING("CALCIUM{CLEAR_TO 100}1BP"),
        COMPOUND_STRING("IRON{CLEAR_TO 100}1BP"),
        COMPOUND_STRING("ZINC{CLEAR_TO 100}1BP"),
        COMPOUND_STRING("CARBOS{CLEAR_TO 100}1BP"),
        COMPOUND_STRING("HP UP{CLEAR_TO 100}1BP"),
        gText_Exit
    },
    [SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR] =
    {
        COMPOUND_STRING("LEFTOVERS{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("WHITE HERB{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("QUICK CLAW{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("MENTAL HERB{CLEAR_TO 94}48BP"),
        COMPOUND_STRING("BRIGHTPOWDER{CLEAR_TO 94}64BP"),
        COMPOUND_STRING("CHOICE BAND{CLEAR_TO 94}64BP"),
        COMPOUND_STRING("KING'S ROCK{CLEAR_TO 94}64BP"),
        COMPOUND_STRING("FOCUS BAND{CLEAR_TO 94}64BP"),
        COMPOUND_STRING("SCOPE LENS{CLEAR_TO 94}64BP"),
        gText_Exit
    },
    [SCROLL_MULTI_BERRY_POWDER_VENDOR] =
    {
        COMPOUND_STRING("ENERGYPOWDER{CLEAR_TO 114}{FONT_SMALL}50"),
        COMPOUND_STRING("ENERGY ROOT{CLEAR_TO 114}{FONT_SMALL}80"),
        COMPOUND_STRING("HEAL POWDER{CLEAR_TO 114}{FONT_SMALL}50"),
        COMPOUND_STRING("REVIVAL HERB{CLEAR_TO 108}{FONT_SMALL}300"),
        COMPOUND_STRING("PROTEIN{CLEAR_TO 99}{FONT_SMALL}1,000"),
        COMPOUND_STRING("IRON{CLEAR_TO 99}{FONT_SMALL}1,000"),
        COMPOUND_STRING("CARBOS{CLEAR_TO 99}{FONT_SMALL}1,000"),
        COMPOUND_STRING("CALCIUM{CLEAR_TO 99}{FONT_SMALL}1,000"),
        COMPOUND_STRING("ZINC{CLEAR_TO 99}{FONT_SMALL}1,000"),
        COMPOUND_STRING("HP UP{CLEAR_TO 99}{FONT_SMALL}1,000"),
        COMPOUND_STRING("PP UP{CLEAR_TO 99}{FONT_SMALL}3,000"),
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
        COMPOUND_STRING("SOFTBOILED{CLEAR_TO 78}16BP"),
        COMPOUND_STRING("SEISMIC TOSS{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("DREAM EATER{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("MEGA PUNCH{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("MEGA KICK{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("BODY SLAM{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("ROCK SLIDE{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("COUNTER{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("THUNDER WAVE{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("SWORDS DANCE{CLEAR_TO 78}48BP"),
        gText_Exit
    },
    [SCROLL_MULTI_BF_MOVE_TUTOR_2] =
    {
        COMPOUND_STRING("DEFENSE CURL{CLEAR_TO 78}16BP"),
        COMPOUND_STRING("SNORE{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("MUD-SLAP{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("SWIFT{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("ICY WIND{CLEAR_TO 78}24BP"),
        COMPOUND_STRING("ENDURE{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("PSYCH UP{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("ICE PUNCH{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("THUNDERPUNCH{CLEAR_TO 78}48BP"),
        COMPOUND_STRING("FIRE PUNCH{CLEAR_TO 78}48BP"),
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
    },
    [SCROLL_MULTI_BADGES] =
    {
        gText_Boulderbadge,
        gText_Cascadebadge,
        gText_Thunderbadge,
        gText_Rainbowbadge,
        gText_Soulbadge,
        gText_Marshbadge,
        gText_Volcanobadge,
        gText_Earthbadge,
        gText_Exit,
    },
    [SCROLL_MULTI_SILPHCO_FLOORS] =
    {
        gText_11F,
        gText_10F,
        gText_9F,
        gText_8F,
        gText_7F,
        gText_6F,
        gText_5F,
        gText_4F,
        gText_3F,
        gText_2F,
        gText_1F,
        gText_Exit,
    }
};

static void Task_ShowScrollableMultichoice(u8 taskId)
{
    u32 width;
    u8 i, windowId;
    struct WindowTemplate template;
    struct Task *task = &gTasks[taskId];

    LockPlayerFieldControls();
    gScrollableMultichoice_ScrollOffset = 0;
    sScrollableMultichoice_ItemSpriteId = MAX_SPRITES;
    FillFrontierExchangeCornerWindowAndItemIcon(task->tScrollMultiId, 0);
    ShowBattleFrontierTutorWindow(task->tScrollMultiId, 0);
    sScrollableMultichoice_ListMenuItem = AllocZeroed(task->tNumItems * sizeof(struct ListMenuItem));
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
            task->tLeft = 0;
        else
            task->tLeft = adjustedLeft;
    }

    template = CreateWindowTemplate(0, task->tLeft, task->tTop, task->tWidth, task->tHeight, 0xF, 0x64);
    windowId = AddWindow(&template);
    task->tWindowId = windowId;
    SetStandardWindowBorderStyle(windowId, FALSE);

    gScrollableMultichoice_ListMenuTemplate.totalItems = task->tNumItems;
    gScrollableMultichoice_ListMenuTemplate.maxShowed = task->tMaxItemsOnScreen;
    gScrollableMultichoice_ListMenuTemplate.windowId = task->tWindowId;

    ScrollableMultichoice_UpdateScrollArrows(taskId);
    task->tListTaskId = ListMenuInit(&gScrollableMultichoice_ListMenuTemplate, task->tScrollOffset, task->tSelectedRow);
    ScheduleBgCopyTilemapToVram(0);
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
    gScrollableMultichoice_ListMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    gScrollableMultichoice_ListMenuTemplate.fontId = FONT_NORMAL;
    gScrollableMultichoice_ListMenuTemplate.cursorKind = CURSOR_BLACK_ARROW;
}

static void ScrollableMultichoice_MoveCursor(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    u8 taskId;
    PlaySE(SE_SELECT);
    taskId = FindTaskIdByFunc(ScrollableMultichoice_ProcessInput);
    if (taskId != TASK_NONE)
    {
        u16 selection;
        struct Task *task = &gTasks[taskId];
        ListMenuGetScrollAndRow(task->tListTaskId, &selection, NULL);
        gScrollableMultichoice_ScrollOffset = selection;
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
        else if (input == task->tNumItems - 1)
        {
            // Selected option was the last one (Exit)
            CloseScrollableMultichoice(taskId);
        }
        else
        {
            // Handle selection while keeping the menu open
            ScrollableMultichoice_RemoveScrollArrows(taskId);
            task->func = Task_ScrollableMultichoice_WaitReturnToList;
            ScriptContext_Enable();
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
    ClearStdWindowAndFrameToTransparent(task->tWindowId, TRUE);
    FillWindowPixelBuffer(task->tWindowId, PIXEL_FILL(0));
    CopyWindowToVram(task->tWindowId, COPYWIN_GFX);
    RemoveWindow(task->tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

// Never run, tKeepOpenAfterSelect is FALSE for all scrollable multichoices.
static void Task_ScrollableMultichoice_WaitReturnToList(u8 taskId)
{
    switch (gTasks[taskId].tKeepOpenAfterSelect)
    {
    case 1:
    default:
        break;
    case 2:
        gTasks[taskId].tKeepOpenAfterSelect = 1;
        gTasks[taskId].func = Task_ScrollableMultichoice_ReturnToList;
        break;
    }
}

// Never called
void ScrollableMultichoice_TryReturnToList(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ScrollableMultichoice_WaitReturnToList);
    if (taskId == TASK_NONE)
        ScriptContext_Enable();
    else
        gTasks[taskId].tKeepOpenAfterSelect++; // Return to list
}

static void Task_ScrollableMultichoice_ReturnToList(u8 taskId)
{
    LockPlayerFieldControls();
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
        .tileTag = GFXTAG_MULTICHOICE_SCROLL_ARROWS,
        .palTag = PALTAG_MULTICHOICE_SCROLL_ARROWS,
        .palNum = 0
    };

    struct Task *task = &gTasks[taskId];
    struct ScrollArrowsTemplate template = sScrollableMultichoice_ScrollArrowsTemplate;
    if (task->tMaxItemsOnScreen != task->tNumItems)
    {
        u32 y0 = (8 * (task->tTop - 1));

        template.firstX = (task->tWidth / 2) * 8 + 12 + (task->tLeft - 1) * 8;
        template.firstY = 8 + y0;
        template.secondX = (task->tWidth / 2) * 8 + 12 + (task->tLeft - 1) * 8;
        template.secondY = task->tHeight * 8 + 10 + y0;
        template.fullyUpThreshold = 0;
        template.fullyDownThreshold = task->tNumItems - task->tMaxItemsOnScreen;
        task->tScrollArrowId = AddScrollIndicatorArrowPair(&template, &gScrollableMultichoice_ScrollOffset);
    }
}

static void ScrollableMultichoice_RemoveScrollArrows(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->tMaxItemsOnScreen != task->tNumItems)
        RemoveScrollIndicatorArrowPair(task->tScrollArrowId);
}

// Removed for Emerald (replaced by ShowScrollableMultichoice)
void ShowGlassWorkshopMenu(void)
{

}

void SetBattleTowerLinkPlayerGfx(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        if (gLinkPlayers[i].gender == MALE)
            VarSet(VAR_OBJ_GFX_ID_F - i, PLAYER_AVATAR_GFX_MALE_NORMAL);
        else
            VarSet(VAR_OBJ_GFX_ID_F - i, PLAYER_AVATAR_GFX_FEMALE_NORMAL);
    }
}

void ShowNatureGirlMessage(void)
{
    u32 nature;
    u32 personality;

    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();

    personality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY);
    nature = GetNatureFromPersonality(personality);
    ShowFieldMessage(gNaturesInfo[nature].natureGirlMessage);
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
                VarSet(VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON);
            else
                VarSet(VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_LOST);
        }
    }
}

void UpdateBattlePointsWindow(void)
{
    u8 string[32];
    u32 x;
    StringCopy(ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->frontier.battlePoints, STR_CONV_MODE_RIGHT_ALIGN, 4), gText_BP);
    x = GetStringRightAlignXOffset(FONT_NORMAL, string, 48);
    AddTextPrinterParameterized(sBattlePointsWindowId, FONT_NORMAL, string, x, 1, 0, NULL);
}

void ShowBattlePointsWindow(void)
{
    static const struct WindowTemplate sBattlePoints_WindowTemplate =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 8,
    };

    sBattlePointsWindowId = AddWindow(&sBattlePoints_WindowTemplate);
    SetStandardWindowBorderStyle(sBattlePointsWindowId, FALSE);
    UpdateBattlePointsWindow();
    CopyWindowToVram(sBattlePointsWindowId, COPYWIN_GFX);
}

void CloseBattlePointsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sBattlePointsWindowId, TRUE);
    RemoveWindow(sBattlePointsWindowId);
}

void TakeFrontierBattlePoints(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints < gSpecialVar_0x8004)
        gSaveBlock2Ptr->frontier.battlePoints = 0;
    else
        gSaveBlock2Ptr->frontier.battlePoints -= gSpecialVar_0x8004;
}

void GiveFrontierBattlePoints(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004 > MAX_BATTLE_FRONTIER_POINTS)
        gSaveBlock2Ptr->frontier.battlePoints = MAX_BATTLE_FRONTIER_POINTS;
    else
        gSaveBlock2Ptr->frontier.battlePoints = gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004;
}

u16 GetFrontierBattlePoints(void)
{
    return gSaveBlock2Ptr->frontier.battlePoints;
}

void ShowFrontierExchangeCornerItemIconWindow(void)
{
    static const struct WindowTemplate sFrontierExchangeCorner_ItemIconWindowTemplate =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 9,
        .width = 4,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 20,
    };

    sFrontierExchangeCorner_ItemIconWindowId = AddWindow(&sFrontierExchangeCorner_ItemIconWindowTemplate);
    SetStandardWindowBorderStyle(sFrontierExchangeCorner_ItemIconWindowId, FALSE);
    CopyWindowToVram(sFrontierExchangeCorner_ItemIconWindowId, COPYWIN_GFX);
}

void CloseFrontierExchangeCornerItemIconWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sFrontierExchangeCorner_ItemIconWindowId, TRUE);
    RemoveWindow(sFrontierExchangeCorner_ItemIconWindowId);
}

static void FillFrontierExchangeCornerWindowAndItemIcon(enum ScrollMulti menu, u16 selection)
{
    #include "data/battle_frontier/battle_frontier_exchange_corner.h"

    if (menu >= SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1 && menu <= SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR)
    {
        FillWindowPixelRect(0, PIXEL_FILL(1), 0, 0, 216, 32);
        switch (menu)
        {
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1:
            AddTextPrinterParameterized2(0, FONT_NORMAL, sFrontierExchangeCorner_Decor1Descriptions[selection], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
            if (sFrontierExchangeCorner_Decor1[selection] == ITEM_LIST_END)
            {
                ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_Decor1[selection]);
            }
            else
            {
                FreeSpriteTilesByTag(TAG_ITEM_ICON);
                FreeSpritePaletteByTag(TAG_ITEM_ICON);
                sScrollableMultichoice_ItemSpriteId = AddDecorationIconObject(sFrontierExchangeCorner_Decor1[selection], 33, 88, 0, TAG_ITEM_ICON, TAG_ITEM_ICON);
            }
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2:
            AddTextPrinterParameterized2(0, FONT_NORMAL, sFrontierExchangeCorner_Decor2Descriptions[selection], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
            if (sFrontierExchangeCorner_Decor2[selection] == ITEM_LIST_END)
            {
                ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_Decor2[selection]);
            }
            else
            {
                FreeSpriteTilesByTag(TAG_ITEM_ICON);
                FreeSpritePaletteByTag(TAG_ITEM_ICON);
                sScrollableMultichoice_ItemSpriteId = AddDecorationIconObject(sFrontierExchangeCorner_Decor2[selection], 33, 88, 0, TAG_ITEM_ICON, TAG_ITEM_ICON);
            }
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR:
            AddTextPrinterParameterized2(0, FONT_NORMAL, sFrontierExchangeCorner_VitaminsDescriptions[selection], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
            ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_Vitamins[selection]);
            break;
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR:
            AddTextPrinterParameterized2(0, FONT_NORMAL, sFrontierExchangeCorner_HoldItemsDescriptions[selection], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
            ShowFrontierExchangeCornerItemIcon(sFrontierExchangeCorner_HoldItems[selection]);
            break;
        default:
            break;
        }
    }
}

static void ShowFrontierExchangeCornerItemIcon(enum Item item)
{
    FreeSpriteTilesByTag(TAG_ITEM_ICON);
    FreeSpritePaletteByTag(TAG_ITEM_ICON);
    sScrollableMultichoice_ItemSpriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, item);

    if (sScrollableMultichoice_ItemSpriteId != MAX_SPRITES)
    {
        gSprites[sScrollableMultichoice_ItemSpriteId].oam.priority = 0;
        gSprites[sScrollableMultichoice_ItemSpriteId].x = 36;
        gSprites[sScrollableMultichoice_ItemSpriteId].y = 92;
    }
}

static void HideFrontierExchangeCornerItemIcon(enum ScrollMulti menu, u16 unused)
{
    if (sScrollableMultichoice_ItemSpriteId != MAX_SPRITES)
    {
        switch (menu)
        {
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1:
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2:
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR:
        case SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR:
            // This makes sure deleting the icon will not clear palettes in use by object events
            FieldEffectFreeGraphicsResources(&gSprites[sScrollableMultichoice_ItemSpriteId]);
            break;
        default:
            break;
        }
        sScrollableMultichoice_ItemSpriteId = MAX_SPRITES;
    }
}

void BufferBattleFrontierTutorMoveName(void)
{
    StringCopy(gStringVar1, GetMoveName(gSpecialVar_0x8005));
}

static void ShowBattleFrontierTutorWindow(enum ScrollMulti menu, u16 selection)
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
            SetStandardWindowBorderStyle(sTutorMoveAndElevatorWindowId, FALSE);
        }
        ShowBattleFrontierTutorMoveDescription(menu, selection);
    }
}

static void ShowBattleFrontierTutorMoveDescription(enum ScrollMulti menu, u16 selection)
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
            AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, FONT_NORMAL, sBattleFrontier_TutorMoveDescriptions2[selection], 0, 1, 0, NULL);
        else
            AddTextPrinterParameterized(sTutorMoveAndElevatorWindowId, FONT_NORMAL, sBattleFrontier_TutorMoveDescriptions1[selection], 0, 1, 0, NULL);
    }
}

void CloseBattleFrontierTutorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sTutorMoveAndElevatorWindowId, TRUE);
    RemoveWindow(sTutorMoveAndElevatorWindowId);
}

// Never called
void ScrollableMultichoice_RedrawPersistentMenu(void)
{
    u16 scrollOffset, selectedRow;
    u8 i;
    u8 taskId = FindTaskIdByFunc(Task_ScrollableMultichoice_WaitReturnToList);
    if (taskId != TASK_NONE)
    {
        struct Task *task = &gTasks[taskId];
        ListMenuGetScrollAndRow(task->tListTaskId, &scrollOffset, &selectedRow);
        SetStandardWindowBorderStyle(task->tWindowId, FALSE);

        for (i = 0; i < MAX_SCROLL_MULTI_ON_SCREEN; i++)
            AddTextPrinterParameterized5(task->tWindowId, FONT_NORMAL, sScrollableMultichoiceOptions[gSpecialVar_0x8004][scrollOffset + i], 10, i * 16, TEXT_SKIP_DRAW, NULL, 0, 0);

        AddTextPrinterParameterized(task->tWindowId, FONT_NORMAL, gText_SelectorArrow, 0, selectedRow * 16, TEXT_SKIP_DRAW, NULL);
        PutWindowTilemap(task->tWindowId);
        CopyWindowToVram(task->tWindowId, COPYWIN_FULL);
    }
}

// Never called
// Close a scrollable multichoice that stays open after selection
void ScrollableMultichoice_ClosePersistentMenu(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ScrollableMultichoice_WaitReturnToList);
    if (taskId != TASK_NONE)
    {
        struct Task *task = &gTasks[taskId];
        DestroyListMenuTask(task->tListTaskId, NULL, NULL);
        Free(sScrollableMultichoice_ListMenuItem);
        ClearStdWindowAndFrameToTransparent(task->tWindowId, TRUE);
        FillWindowPixelBuffer(task->tWindowId, PIXEL_FILL(0));
        ClearWindowTilemap(task->tWindowId);
        CopyWindowToVram(task->tWindowId, COPYWIN_GFX);
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

#define DEOXYS_ROCK_LEVELS 11

void DoDeoxysRockInteraction(void)
{
    CreateTask(Task_DeoxysRockInteraction, 8);
}

static const u16 sDeoxysRockPalettes[DEOXYS_ROCK_LEVELS][16] = {
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_1.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_2.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_3.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_4.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_5.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_6.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_7.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_8.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_9.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_10.pal", ".gbapal"),
    INCGFX_U16("graphics/field_effects/palettes/deoxys_rock_11.pal", ".gbapal"),
};

static const u8 sDeoxysRockCoords[DEOXYS_ROCK_LEVELS][2] = {
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
    static const u8 sStoneMaxStepCounts[DEOXYS_ROCK_LEVELS - 1] = { 4, 8, 8, 8, 4, 4, 4, 6, 3, 3 };

    if (FlagGet(FLAG_DEOXYS_ROCK_COMPLETE) == TRUE)
    {
        gSpecialVar_Result = DEOXYS_ROCK_COMPLETE;
        ScriptContext_Enable();
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
            gSpecialVar_Result = DEOXYS_ROCK_FAILED;
            DestroyTask(taskId);
        }
        else if (rockLevel == DEOXYS_ROCK_LEVELS - 1)
        {
            FlagSet(FLAG_DEOXYS_ROCK_COMPLETE);
            gSpecialVar_Result = DEOXYS_ROCK_SOLVED;
            ScriptContext_Enable();
            DestroyTask(taskId);
        }
        else
        {
            rockLevel++;
            ChangeDeoxysRockLevel(rockLevel);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, rockLevel);
            gSpecialVar_Result = DEOXYS_ROCK_PROGRESSED;
            DestroyTask(taskId);
        }
    }
}

static void ChangeDeoxysRockLevel(u8 rockLevel)
{
    u8 paletteNum = IndexOfSpritePaletteTag(OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE);
    LoadPalette(&sDeoxysRockPalettes[rockLevel], OBJ_PLTT_ID(paletteNum), PLTT_SIZEOF(4));
    UpdateSpritePaletteWithWeather(paletteNum, FALSE);

    if (rockLevel == 0)
        PlaySE(SE_M_CONFUSE_RAY); // Failure sound
    else
        PlaySE(SE_RG_DEOXYS_MOVE); // Success sound

    CreateTask(WaitForDeoxysRockMovement, 8);
    gFieldEffectArguments[0] = LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR_FRLG) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR_FRLG))
    {
        gFieldEffectArguments[1] = MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR_FRLG);
        gFieldEffectArguments[2] = MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR_FRLG);
    }
    else
    {
        gFieldEffectArguments[1] = MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR);
        gFieldEffectArguments[2] = MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR);
    }
    gFieldEffectArguments[3] = sDeoxysRockCoords[rockLevel][0];
    gFieldEffectArguments[4] = sDeoxysRockCoords[rockLevel][1];

    // Set number of movement steps.
    // Resetting for failure is slow, successful movement is fast.
    if (rockLevel == 0)
        gFieldEffectArguments[5] = 60;
    else
        gFieldEffectArguments[5] = 5;

    FieldEffectStart(FLDEFF_MOVE_DEOXYS_ROCK);
    SetObjEventTemplateCoords(LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK, sDeoxysRockCoords[rockLevel][0], sDeoxysRockCoords[rockLevel][1]);
}

static void WaitForDeoxysRockMovement(u8 taskId)
{
    if (FieldEffectActiveListContains(FLDEFF_MOVE_DEOXYS_ROCK) == FALSE)
    {
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

void IncrementBirthIslandRockStepCount(void)
{
    u16 stepCount = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);
    if ((gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR))
     || (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR_FRLG) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR_FRLG)))
    {
        if (++stepCount > 99)
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        else
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, stepCount);
    }
}

// called before fade-in
void SetDeoxysRockPalette(void)
{
    u32 paletteNum = IndexOfSpritePaletteTag(OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE);
    LoadPalette(&sDeoxysRockPalettes[(u8)VarGet(VAR_DEOXYS_ROCK_LEVEL)], OBJ_PLTT_ID(paletteNum), PLTT_SIZEOF(4));
    // Set faded to all black, weather blending handled during fade-in
    CpuFill16(RGB_BLACK, &gPlttBufferFaded[OBJ_PLTT_ID(paletteNum)], PLTT_SIZE_4BPP);
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
                    FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
                VarSet(VAR_PC_BOX_TO_SEND_MON, box);
                return ShouldShowBoxWasFullMessage();
            }
        }

        if (++box == TOTAL_BOXES_COUNT)
            box = 0;
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
        MAP_NUM(MAP_ROUTE114),
        MAP_NUM(MAP_ROUTE114),
        MAP_NUM(MAP_ROUTE115),
        MAP_NUM(MAP_ROUTE115),
        MAP_NUM(MAP_ROUTE116),
        MAP_NUM(MAP_ROUTE116),
        MAP_NUM(MAP_ROUTE118),
        MAP_NUM(MAP_ROUTE118),
        MAP_NUM(MAP_ROUTE105),
        MAP_NUM(MAP_ROUTE105),
        MAP_NUM(MAP_ROUTE125),
        MAP_NUM(MAP_ROUTE125),
        MAP_NUM(MAP_ROUTE127),
        MAP_NUM(MAP_ROUTE127),
        MAP_NUM(MAP_ROUTE129),
        MAP_NUM(MAP_ROUTE129)
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
    static const u8 sAbnormalWeatherMapNumbers[] =
    {
        MAP_NUM(MAP_ROUTE114),
        MAP_NUM(MAP_ROUTE114),
        MAP_NUM(MAP_ROUTE115),
        MAP_NUM(MAP_ROUTE115),
        MAP_NUM(MAP_ROUTE116),
        MAP_NUM(MAP_ROUTE116),
        MAP_NUM(MAP_ROUTE118),
        MAP_NUM(MAP_ROUTE118),
        MAP_NUM(MAP_ROUTE105),
        MAP_NUM(MAP_ROUTE105),
        MAP_NUM(MAP_ROUTE125),
        MAP_NUM(MAP_ROUTE125),
        MAP_NUM(MAP_ROUTE127),
        MAP_NUM(MAP_ROUTE127),
        MAP_NUM(MAP_ROUTE129),
        MAP_NUM(MAP_ROUTE129)
    };

    u16 steps = VarGet(VAR_ABNORMAL_WEATHER_STEP_COUNTER);
    u16 abnormalWeather = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);

    if (abnormalWeather == ABNORMAL_WEATHER_NONE)
        return FALSE;

    if (++steps > 999)
    {
        VarSet(VAR_ABNORMAL_WEATHER_STEP_COUNTER, 0);
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_UNDERWATER_MARINE_CAVE))
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
            case MAP_NUM(MAP_UNDERWATER_MARINE_CAVE):
            case MAP_NUM(MAP_MARINE_CAVE_ENTRANCE):
            case MAP_NUM(MAP_MARINE_CAVE_END):
            case MAP_NUM(MAP_TERRA_CAVE_ENTRANCE):
            case MAP_NUM(MAP_TERRA_CAVE_END):
                VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 1);
                return FALSE;
            default:
                break;
            }
        }

        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_UNDERWATER_ROUTE127))
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
            case MAP_NUM(MAP_UNDERWATER_ROUTE127):
            case MAP_NUM(MAP_UNDERWATER_ROUTE129):
            case MAP_NUM(MAP_UNDERWATER_ROUTE105):
            case MAP_NUM(MAP_UNDERWATER_ROUTE125):
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

// All mart employees have a local id of 1, so function always returns 1
u32 GetMartEmployeeObjectEventId(void)
{
    static const u8 sPokeMarts[][3] =
    {
        { MAP_GROUP(MAP_OLDALE_TOWN_MART),     MAP_NUM(MAP_OLDALE_TOWN_MART),     LOCALID_OLDALE_MART_CLERK },
        { MAP_GROUP(MAP_LAVARIDGE_TOWN_MART),  MAP_NUM(MAP_LAVARIDGE_TOWN_MART),  LOCALID_LAVARIDGE_MART_CLERK },
        { MAP_GROUP(MAP_FALLARBOR_TOWN_MART),  MAP_NUM(MAP_FALLARBOR_TOWN_MART),  LOCALID_FALLARBOR_MART_CLERK },
        { MAP_GROUP(MAP_VERDANTURF_TOWN_MART), MAP_NUM(MAP_VERDANTURF_TOWN_MART), LOCALID_VERDANTURF_MART_CLERK },
        { MAP_GROUP(MAP_PETALBURG_CITY_MART),  MAP_NUM(MAP_PETALBURG_CITY_MART),  LOCALID_PETALBURG_MART_CLERK },
        { MAP_GROUP(MAP_SLATEPORT_CITY_MART),  MAP_NUM(MAP_SLATEPORT_CITY_MART),  LOCALID_SLATEPORT_MART_CLERK },
        { MAP_GROUP(MAP_MAUVILLE_CITY_MART),   MAP_NUM(MAP_MAUVILLE_CITY_MART),   LOCALID_MAUVILLE_MART_CLERK },
        { MAP_GROUP(MAP_RUSTBORO_CITY_MART),   MAP_NUM(MAP_RUSTBORO_CITY_MART),   LOCALID_RUSTBORO_MART_CLERK },
        { MAP_GROUP(MAP_FORTREE_CITY_MART),    MAP_NUM(MAP_FORTREE_CITY_MART),    LOCALID_FORTREE_MART_CLERK },
        { MAP_GROUP(MAP_MOSSDEEP_CITY_MART),   MAP_NUM(MAP_MOSSDEEP_CITY_MART),   LOCALID_MOSSDEEP_MART_CLERK },
        { MAP_GROUP(MAP_SOOTOPOLIS_CITY_MART), MAP_NUM(MAP_SOOTOPOLIS_CITY_MART), LOCALID_SOOTOPOLIS_MART_CLERK },
        { MAP_GROUP(MAP_BATTLE_FRONTIER_MART), MAP_NUM(MAP_BATTLE_FRONTIER_MART), LOCALID_FRONTIER_MART_CLERK },
    };

    u8 i;
    for (i = 0; i < ARRAY_COUNT(sPokeMarts); i++)
    {
        if (gSaveBlock1Ptr->location.mapGroup == sPokeMarts[i][0])
        {
            if (gSaveBlock1Ptr->location.mapNum == sPokeMarts[i][1])
                return sPokeMarts[i][2];
        }
    }
    return 1;
}

bool32 IsTrainerRegistered(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
    {
        if (FlagGet(TRAINER_REGISTERED_FLAGS_START + index) == TRUE)
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

#define tState data[0]

void BattleTowerReconnectLink(void)
{
    // Save battle type, restored at end
    // of Task_LinkRetireStatusWithBattleTowerPartner
    sBattleTowerMultiBattleTypeFlags = gBattleTypeFlags;
    gBattleTypeFlags = 0;

    if (!gReceivedRemoteLinkPlayers)
        CreateTask(Task_ReconnectWithLinkPlayers, 5);
}

void LinkRetireStatusWithBattleTowerPartner(void)
{
    CreateTask(Task_LinkRetireStatusWithBattleTowerPartner, 5);
}

// Communicate with a Battle Tower link partner to tell them
// whether or not the player chose to continue or retire,
// and determine what the partner chose to do
// gSpecialVar_0x8004: Player's choice
// gSpecialVar_0x8005: Partner's choice (read from gBlockRecvBuffer[1][0])
static void Task_LinkRetireStatusWithBattleTowerPartner(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gTasks[taskId].tState++;
        break;
    case 1:
        if (IsLinkTaskFinished() == TRUE)
        {
            if (GetMultiplayerId() == 0)
            {
                // Player is link leader, skip sending data
                gTasks[taskId].tState++;
            }
            else
            {
                // Send value of gSpecialVar_0x8004 to leader
                // Will either be BATTLE_TOWER_LINK_CONTINUE or BATTLE_TOWER_LINK_RETIRE
                SendBlock(BitmaskAllOtherLinkPlayers(), &gSpecialVar_0x8004, sizeof(gSpecialVar_0x8004));
                gTasks[taskId].tState++;
            }
        }
        break;
    case 2:
        if (GetBlockReceivedStatus() & 2)
        {
            if (GetMultiplayerId() == 0)
            {
                // Player is leader, read partner's choice
                // and determine if play should continue
                gSpecialVar_0x8005 = gBlockRecvBuffer[1][0];
                ResetBlockReceivedFlag(1);

                if (gSpecialVar_0x8004 == BATTLE_TOWER_LINK_RETIRE
                 && gSpecialVar_0x8005 == BATTLE_TOWER_LINK_RETIRE)
                    gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_BOTH_RETIRE;
                else if (gSpecialVar_0x8004 == BATTLE_TOWER_LINK_CONTINUE
                      && gSpecialVar_0x8005 == BATTLE_TOWER_LINK_RETIRE)
                    gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_MEMBER_RETIRE;
                else if (gSpecialVar_0x8004 == BATTLE_TOWER_LINK_RETIRE
                      && gSpecialVar_0x8005 == BATTLE_TOWER_LINK_CONTINUE)
                    gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_LEADER_RETIRE;
                else
                    gSpecialVar_Result = BATTLE_TOWER_LINKSTAT_CONTINUE;
            }
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished() == TRUE)
        {
            if (GetMultiplayerId() != 0)
            {
                // Player is not link leader, wait for leader's response
                gTasks[taskId].tState++;
            }
            else
            {
                // Send whether or not play should continue
                SendBlock(BitmaskAllOtherLinkPlayers(), &gSpecialVar_Result, sizeof(gSpecialVar_Result));
                gTasks[taskId].tState++;
            }
        }
        break;
    case 4:
        if (GetBlockReceivedStatus() & 1)
        {
            if (GetMultiplayerId() != 0)
            {
                // Player is not link leader, read leader's response
                gSpecialVar_Result = gBlockRecvBuffer[0][0];
                ResetBlockReceivedFlag(0);
                gTasks[taskId].tState++;
            }
            else
            {
                gTasks[taskId].tState++;
            }
        }
        break;
    case 5:
        // Print message if partner chose to retire (and player didn't)
        if (GetMultiplayerId() == 0)
        {
            if (gSpecialVar_Result == BATTLE_TOWER_LINKSTAT_MEMBER_RETIRE)
                ShowFieldAutoScrollMessage(gText_YourPartnerHasRetired);
        }
        else
        {
            if (gSpecialVar_Result == BATTLE_TOWER_LINKSTAT_LEADER_RETIRE)
                ShowFieldAutoScrollMessage(gText_YourPartnerHasRetired);
        }
        gTasks[taskId].tState++;
        break;
    case 6:
        if (!IsTextPrinterActiveOnWindow(0))
            gTasks[taskId].tState++;
        break;
    case 7:
        if (IsLinkTaskFinished() == TRUE)
        {
            SetLinkStandbyCallback();
            gTasks[taskId].tState++;
        }
        break;
    case 8:
        if (IsLinkTaskFinished() == TRUE)
            gTasks[taskId].tState++;
        break;
    case 9:
        if (gWirelessCommType == 0)
            SetCloseLinkCallback();

        gBattleTypeFlags = sBattleTowerMultiBattleTypeFlags;
        ScriptContext_Enable();
        DestroyTask(taskId);
        break;
    }
}

#undef tState

void Script_DoRayquazaScene(void)
{
    if (!gSpecialVar_0x8004)
    {
        // Groudon/Kyogre fight scene
        DoRayquazaScene(0, TRUE, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else
    {
        // Rayquaza arrives scene
        DoRayquazaScene(1, FALSE, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

#define playCount data[0]
#define delay     data[1]

void LoopWingFlapSE(void)
{
    CreateTask(Task_LoopWingFlapSE, 8);
    PlaySE(SE_M_WING_ATTACK);
}

static void Task_LoopWingFlapSE(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    delay++;
    if (delay == gSpecialVar_0x8005)
    {
        playCount++;
        delay = 0;
        PlaySE(SE_M_WING_ATTACK);
    }

    if (playCount == gSpecialVar_0x8004 - 1)
        DestroyTask(taskId);
}

#undef playCount
#undef delay

#define CURTAIN_HEIGHT 4
#define CURTAIN_WIDTH 3
#define tFrameTimer   data
#define tCurrentFrame data[3]

void CloseBattlePikeCurtain(void)
{
    u8 taskId = CreateTask(Task_CloseBattlePikeCurtain, 8);
    gTasks[taskId].tFrameTimer[0] = 4;
    gTasks[taskId].tFrameTimer[1] = 4;
    gTasks[taskId].tFrameTimer[2] = 4;
    gTasks[taskId].tCurrentFrame = 0;
}

static void Task_CloseBattlePikeCurtain(u8 taskId)
{
    u8 x, y;
    s16 *data = gTasks[taskId].data;

    tFrameTimer[tCurrentFrame]--;
    if (tFrameTimer[tCurrentFrame] == 0)
    {
        for (y = 0; y < CURTAIN_HEIGHT; y++)
        {
            for (x = 0; x < CURTAIN_WIDTH; x++)
            {
                MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + x + MAP_OFFSET - 1,
                                       gSaveBlock1Ptr->pos.y + y + MAP_OFFSET - 3,
                                       (x + METATILE_BattlePike_CurtainFrames_Start) + (y * METATILE_ROW_WIDTH) + (tCurrentFrame * CURTAIN_HEIGHT * METATILE_ROW_WIDTH));
            }
        }
        DrawWholeMapView();
        tCurrentFrame++;
        if (tCurrentFrame == 3)
        {
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
    }
}

#undef CURTAIN_HEIGHT
#undef CURTAIN_WIDTH
#undef tFrameTimer
#undef tCurrentFrame

void GetBattlePyramidHint(void)
{
    // gSpecialVar_0x8004 here is expected to be the current Battle Pyramid win streak.
    gSpecialVar_Result = gSpecialVar_0x8004 / FRONTIER_STAGES_PER_CHALLENGE;
    gSpecialVar_Result -= (gSpecialVar_Result / TOTAL_PYRAMID_ROUNDS) * TOTAL_PYRAMID_ROUNDS;
}

// Used to avoid a potential softlock if the player respawns on Dewford with no way off
void ResetHealLocationFromDewford(void)
{
    if (gSaveBlock1Ptr->lastHealLocation.mapGroup == MAP_GROUP(MAP_DEWFORD_TOWN) && gSaveBlock1Ptr->lastHealLocation.mapNum == MAP_NUM(MAP_DEWFORD_TOWN))
        SetLastHealLocationWarp(HEAL_LOCATION_PETALBURG_CITY);
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
        MAP_UNDEFINED
    };

    int i;
    u16 map = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;

    for (i = 0; sPokemonCenters[i] != MAP_UNDEFINED; i++)
    {
        if (sPokemonCenters[i] == map)
            return TRUE;
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

#define GET_TRAINER_FAN_CLUB_FLAG(flag)  (FANCLUB_BITFIELD >> (flag) & 1)
#define SET_TRAINER_FAN_CLUB_FLAG(flag)  (FANCLUB_BITFIELD |= 1 << (flag))
#define FLIP_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD ^= 1 << (flag))

#define GET_TRAINER_FAN_CLUB_COUNTER         (FANCLUB_BITFIELD & FANCLUB_COUNTER)
#define SET_TRAINER_FAN_CLUB_COUNTER(count)  (FANCLUB_BITFIELD = (FANCLUB_BITFIELD & ~FANCLUB_COUNTER) | (count))
#define INCR_TRAINER_FAN_CLUB_COUNTER(count) (FANCLUB_BITFIELD += (count))
#define CLEAR_TRAINER_FAN_CLUB_COUNTER       (FANCLUB_BITFIELD &= ~FANCLUB_COUNTER)

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
// Defeating Drake or participating in a Contest increments the counter by 2
// Participating at Battle Tower or in a Secret Base battle increments the counter by 1
u8 TryGainNewFanFromCounter(u8 incrementId)
{
    static const u8 sCounterIncrements[] =
    {
        [FANCOUNTER_DEFEATED_DRAKE]    = 2,
        [FANCOUNTER_BATTLED_AT_BASE]   = 1,
        [FANCOUNTER_FINISHED_CONTEST]  = 2,
        [FANCOUNTER_USED_BATTLE_TOWER] = 1
    };

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
        return 0;

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
        FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);

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
#if FREE_LINK_BATTLE_RECORDS == FALSE
    BufferFanClubTrainerName_(&gSaveBlock1Ptr->linkBattleRecords, whichLinkTrainer, whichNPCTrainer);
#else
    BufferFanClubTrainerName_(whichLinkTrainer, whichNPCTrainer);
#endif //FREE_LINK_BATTLE_RECORDS
}

#if FREE_LINK_BATTLE_RECORDS == FALSE
static void BufferFanClubTrainerName_(struct LinkBattleRecords *linkRecords, u8 whichLinkTrainer, u8 whichNPCTrainer)
{
    struct LinkBattleRecord *record = &linkRecords->entries[whichLinkTrainer];
    if (record->name[0] == EOS)
    {
        switch (whichNPCTrainer)
        {
        case 0:
            StringCopy(gStringVar1, sText_Wallace);
            break;
        case 1:
            StringCopy(gStringVar1, sText_Steven);
            break;
        case 2:
            StringCopy(gStringVar1, sText_Brawly);
            break;
        case 3:
            StringCopy(gStringVar1, sText_Winona);
            break;
        case 4:
            StringCopy(gStringVar1, sText_Phoebe);
            break;
        case 5:
            StringCopy(gStringVar1, sText_Glacia);
            break;
        default:
            StringCopy(gStringVar1, sText_Wallace);
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
#else
static void BufferFanClubTrainerName_(u8 whichLinkTrainer, u8 whichNPCTrainer)
{
    switch (whichNPCTrainer)
    {
    case 0:
        StringCopy(gStringVar1, sText_Wallace);
        break;
    case 1:
        StringCopy(gStringVar1, sText_Steven);
        break;
    case 2:
        StringCopy(gStringVar1, sText_Brawly);
        break;
    case 3:
        StringCopy(gStringVar1, sText_Winona);
        break;
    case 4:
        StringCopy(gStringVar1, sText_Phoebe);
        break;
    case 5:
        StringCopy(gStringVar1, sText_Glacia);
        break;
    default:
        StringCopy(gStringVar1, sText_Wallace);
        break;
    }
}
#endif //FREE_LINK_BATTLE_RECORDS

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

void TrySkyBattle(void)
{
    int i;

    if (B_VAR_SKY_BATTLE == 0 || B_FLAG_SKY_BATTLE == 0)
    {
        LockPlayerFieldControls();
        ScriptContext_SetupScript(Debug_FlagsAndVarNotSetBattleConfigMessage);
        return;
    }
    for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
        struct Pokemon* pokemon = &gParties[B_TRAINER_PLAYER][i];
        if (CanMonParticipateInSkyBattle(pokemon) && GetMonData(pokemon, MON_DATA_HP) > 0)
        {
            PreparePartyForSkyBattle();
            gSpecialVar_Result = TRUE;
            return;
        }
    }
    gSpecialVar_Result = FALSE;
}

void PreparePartyForSkyBattle(void)
{
    int i, participatingPokemonSlot = 0;
    u8 partyCount = CalculatePlayerPartyCount();

    FlagSet(B_FLAG_SKY_BATTLE);
    SavePlayerParty();

    for (i = 0; i < partyCount; i++)
    {
        struct Pokemon* pokemon = &gParties[B_TRAINER_PLAYER][i];

        if (CanMonParticipateInSkyBattle(pokemon))
            participatingPokemonSlot += 1 << i;
        else
            ZeroMonData(pokemon);
    }
    VarSet(B_VAR_SKY_BATTLE,participatingPokemonSlot);
    CompactPartySlots();
}

void GetObjectPosition(u16* xPointer, u16* yPointer, u32 localId, u32 useTemplate)
{
    u32 objectId;
    struct ObjectEvent* objEvent;

    if (useTemplate)
    {
        const struct ObjectEventTemplate *objTemplate = FindObjectEventTemplateByLocalId(localId, gSaveBlock1Ptr->objectEventTemplates, gMapHeader.events->objectEventCount);
        *xPointer = objTemplate->x;
        *yPointer = objTemplate->y;
        return;
    }

    objectId = GetObjectEventIdByLocalId(localId);
    objEvent = &gObjectEvents[objectId];
    *xPointer = objEvent->currentCoords.x - MAP_OFFSET;
    *yPointer = objEvent->currentCoords.y - MAP_OFFSET;
}

bool32 CheckObjectAtXY(u32 x, u32 y)
{
    u32 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            continue;

        if (gObjectEvents[i].currentCoords.x != x)
            continue;

        if (gObjectEvents[i].currentCoords.y != y)
            continue;
        return TRUE;
    }
    return FALSE;
}

bool32 CheckPartyHasSpecies(enum Species givenSpecies)
{
    u32 partyIndex;

    for (partyIndex = 0; partyIndex < CalculatePlayerPartyCount(); partyIndex++)
        if (GetMonData(&gParties[B_TRAINER_PLAYER][partyIndex], MON_DATA_SPECIES) == givenSpecies)
            return TRUE;

    return FALSE;
}

void UseBlankMessageToCancelPokemonPic(void)
{
    DeactivateSingleTextPrinter(0, WINDOW_TEXT_PRINTER);
    ScriptMenu_HidePokemonPic();
}

static void UIAskConfirmation(void)
{
    DisplayYesNoMenuDefaultYes();
}

static s32 UIWaitConfirmation(void)
{
    return Menu_ProcessInputNoWrapClearOnChoose();
}

static void UIPrintMessage(const u8 *message)
{
    ShowFieldMessage(message);
}

static void UIPlayFanfare(u32 songId)
{
    PlayFanfare(songId);
}

static void UIEndTask(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#define tState         data[0]
#define tPartyIndex    data[1]
#define tMove          data[2]
#define tRecoverPp     data[3]

static void UIShowMoveList(u8 taskId)
{
    gSpecialVar_0x8000 = gTasks[taskId].tPartyIndex;
    gSpecialVar_0x8001 = gTasks[taskId].tMove;
    DestroyTask(taskId);
    ShowSelectMovePokemonSummaryScreen(gParties[B_TRAINER_PLAYER], gTasks[taskId].tPartyIndex, CB2_ReturnToFieldWhileLearningMove, gTasks[taskId].tMove);
}

static const struct MoveLearnUI sMoveLearnUI =
{
    .askConfirmation = UIAskConfirmation,
    .waitConfirmation = UIWaitConfirmation,
    .printMessage = UIPrintMessage,
    .playFanfare = UIPlayFanfare,
    .showMoveList = UIShowMoveList,
    .endTask = UIEndTask
};

static void Task_LearnMove(u8 taskId)
{
    if (IsTextPrinterActiveOnWindow(0))
        return;
    gTasks[taskId].tState = LearnMove(&sMoveLearnUI, taskId);
}

void CanTeachMoveBoxMon(void)
{
    if (gSpecialVar_0x8004 == PARTY_NOTHING_CHOSEN)
    {
        // We want to wait one frame before using ScriptContext_Enable() or the game freezes
        CreateTask(UIEndTask, 1);
        return;
    }
    u32 taskId = CreateTask(Task_LearnMove, 1);
    gTasks[taskId].tState = GetLearnMoveStartState();
    gTasks[taskId].tPartyIndex = gSpecialVar_0x8004;
    gTasks[taskId].tMove = gSpecialVar_0x8005;
    gTasks[taskId].tRecoverPp = TRUE;
}

static void FieldCB_ContinueLearningMove(void)
{
    LockPlayerFieldControls();
    FadeInFromBlack();
    CreateTask(Task_ReturnToFieldWhileLearningMove, 1);
}

static void CB2_ReturnToFieldWhileLearningMove(void)
{
    gFieldCallback = FieldCB_ContinueLearningMove;
    CB2_ReturnToField();
}

static void Task_ReturnToFieldWhileLearningMove(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        gTasks[taskId].func = Task_LearnMove;
        gTasks[taskId].tState = GetLearnMoveResumeAfterSummaryScreenState();
        gTasks[taskId].tPartyIndex = gSpecialVar_0x8000;
        gTasks[taskId].tMove = gSpecialVar_0x8001;
    }
}

#undef tState
#undef tPartyIndex
#undef tMove

void EnterCode(void)
{
    StringCopy(gStringVar2, COMPOUND_STRING(""));
    DoNamingScreen(NAMING_SCREEN_CODE, gStringVar2, 0, 0, 0, CB2_ReturnToFieldContinueScript);
}

void GetCodeFeedback(void)
{
    static const u8 sText_SampleCode[] = _("SampleCode");
    if (!StringCompare(gStringVar2, sText_SampleCode))
        gSpecialVar_Result = 1;
    else
        gSpecialVar_Result = 0;
}

void SetHiddenNature(void)
{
    u32 hiddenNature = gSpecialVar_Result;
    SetMonData(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], MON_DATA_HIDDEN_NATURE, &hiddenNature);
    CalculateMonStats(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004]);
}

void SetAbility(void)
{
    enum Ability ability = gSpecialVar_Result;
    SetMonData(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], MON_DATA_ABILITY_NUM, &ability);
}

void DaisyMassageServices(void)
{
    AdjustFriendship(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], FRIENDSHIP_EVENT_MASSAGE);
    VarSet(VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0);
}

u8 GetLeadMonFriendship(void)
{
    struct Pokemon * pokemon = &gParties[B_TRAINER_PLAYER][GetLeadMonIndex()];
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) == 255)
        return 6;
    else if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 200)
        return 5;
    else if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 150)
        return 4;
    else if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 100)
        return 3;
    else if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 50)
        return 2;
    else if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) > 0)
        return 1;
    else
        return 0;
}

enum Move GetFirstPartnerMove(enum Species species)
{
    switch (species)
    {
    case SPECIES_VENUSAUR:
        return MOVE_FRENZY_PLANT;
    case SPECIES_CHARIZARD:
        return MOVE_BLAST_BURN;
    case SPECIES_BLASTOISE:
        return MOVE_HYDRO_CANNON;
    default:
        return MOVE_NONE;
    }
}

bool8 CapeBrinkGetMoveToTeachLeadPokemon(void)
{
    // Returns:
    //   8005 = Move tutor index
    //   8006 = Num moves known by lead mon
    //   8007 = Index of lead mon
    //   to specialvar = whether a move can be taught in the first place
    u8 i, leadMonSlot, moveCount = 0;
    enum Move moveId;
    u16 tutorFlag;
    struct Pokemon *leadMon;

    leadMonSlot = GetLeadMonIndex();
    leadMon = &gParties[B_TRAINER_PLAYER][leadMonSlot];

    if (GetMonData(leadMon, MON_DATA_FRIENDSHIP) != 255)
        return FALSE;

    moveId = GetFirstPartnerMove(GetMonData(leadMon, MON_DATA_SPECIES_OR_EGG));
    switch (moveId)
    {
    case MOVE_FRENZY_PLANT:
        tutorFlag = FLAG_TUTOR_FRENZY_PLANT;
        break;
    case MOVE_BLAST_BURN:
        tutorFlag = FLAG_TUTOR_BLAST_BURN;
        break;
    case MOVE_HYDRO_CANNON:
        tutorFlag = FLAG_TUTOR_HYDRO_CANNON;
        break;
    default:
        return FALSE;
    }

    StringCopy(gStringVar2, gMovesInfo[moveId].name);
    if (FlagGet(tutorFlag) == TRUE)
        return FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++)
        moveCount += (GetMonData(leadMon, MON_DATA_MOVE1 + i) != MOVE_NONE);

    gSpecialVar_0x8005 = moveId;
    gSpecialVar_0x8006 = moveCount;
    gSpecialVar_0x8007 = leadMonSlot;

    return TRUE;
}

bool8 HasLearnedAllMovesFromCapeBrinkTutor(void)
{
    // 8005 is set by CapeBrinkGetMoveToTeachLeadPokemon
    switch (gSpecialVar_0x8005)
    {
    case MOVE_FRENZY_PLANT:
        FlagSet(FLAG_TUTOR_FRENZY_PLANT);
        break;
    case MOVE_BLAST_BURN:
        FlagSet(FLAG_TUTOR_BLAST_BURN);
        break;
    case MOVE_HYDRO_CANNON:
        FlagSet(FLAG_TUTOR_HYDRO_CANNON);
        break;
    }

    return (FlagGet(FLAG_TUTOR_FRENZY_PLANT) == TRUE)
        && (FlagGet(FLAG_TUTOR_BLAST_BURN) == TRUE)
        && (FlagGet(FLAG_TUTOR_HYDRO_CANNON) == TRUE);
}

void SetSeenMon(void)
{
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(gSpecialVar_0x8004), 2);
}

#define tTimer data[0]
#define tState data[1]
#define tX     data[2]
#define tY     data[3]

static void Task_DrawTeleporterHousing(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTimer == 0)
    {
        // Alternate the teleporter light / brightness of the teleporter door
        if ((tState & 1) == 0)
        {
            MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Light_Yellow | MAPGRID_COLLISION_MASK);
            MapGridSetMetatileIdAt(tX, tY + 2, METATILE_SeaCottage_Teleporter_Door_HalfGlowing | MAPGRID_COLLISION_MASK);
        }
        else
        {
            MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Light_Red | MAPGRID_COLLISION_MASK);
            MapGridSetMetatileIdAt(tX, tY + 2, METATILE_SeaCottage_Teleporter_Door_FullGlowing | MAPGRID_COLLISION_MASK);
        }
        CurrentMapDrawMetatileAt(tX, tY);
        CurrentMapDrawMetatileAt(tX, tY + 2);
    }

    tTimer++;
    if (tTimer != 16)
        return;

    tTimer = 0;
    tState++;
    if (tState != 13)
        return;

    MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Light_Green | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(tX, tY + 2, METATILE_SeaCottage_Teleporter_Door | MAPGRID_COLLISION_MASK);
    CurrentMapDrawMetatileAt(tX, tY);
    CurrentMapDrawMetatileAt(tX, tY + 2);
    DestroyTask(taskId);
}

void AnimateTeleporterHousing(void)
{
    u8 taskId;
    s16 *data;

    taskId = CreateTask(Task_DrawTeleporterHousing, 0);
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tState = 0;
    data = gTasks[taskId].data;
    PlayerGetDestCoords(&tX, &tY);

    // Set the coords of whichever teleporter is being animated
    // 0 for the right teleporter, 1 for the left teleporter
    if (gSpecialVar_0x8004 == 0)
    {
        gTasks[taskId].tX += 6;
        gTasks[taskId].tY -= 5;
    }
    else
    {
        gTasks[taskId].tX -= 1;
        gTasks[taskId].tY -= 5;
    }
}

static void Task_DrawTeleporterCable(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTimer == 0)
    {
        if (tState != 0)
        {
            // Set default cable tiles to clear the ball
            MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Cable_Top | MAPGRID_COLLISION_MASK);
            MapGridSetMetatileIdAt(tX, tY + 1, METATILE_SeaCottage_Teleporter_Cable_Bottom | MAPGRID_COLLISION_MASK);
            CurrentMapDrawMetatileAt(tX, tY);
            CurrentMapDrawMetatileAt(tX, tY + 1);

            // End after drawing 4 times (length of the cable)
            if (tState == 4)
            {
                DestroyTask(taskId);
                return;
            }

            tX--;
        }

        // Draw the cable ball
        MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_CableBall_Top | MAPGRID_COLLISION_MASK);
        MapGridSetMetatileIdAt(tX, tY + 1, METATILE_SeaCottage_Teleporter_CableBall_Bottom | MAPGRID_COLLISION_MASK);
        CurrentMapDrawMetatileAt(tX, tY);
        CurrentMapDrawMetatileAt(tX, tY + 1);
    }

    tTimer++;
    if (tTimer == 4)
    {
        tTimer = 0;
        tState++;
    }
}

void AnimateTeleporterCable(void)
{
    u8 taskId;
    s16 *data;

    taskId = CreateTask(Task_DrawTeleporterCable, 0);
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tState = 0;
    data = gTasks[taskId].data;
    PlayerGetDestCoords(&tX, &tY);
    gTasks[taskId].tX += 4;
    gTasks[taskId].tY -= 5;
}

#undef tTimer
#undef tState
#undef tX
#undef tY

void SetVermilionTrashCans(void)
{
    u16 idx = (Random() % 15) + 1;
    gSpecialVar_0x8004 = idx;
    gSpecialVar_0x8005 = idx;
    switch (gSpecialVar_0x8004)
    {
    case 1:
        idx = Random() % 2;
        if (idx == 0)
            gSpecialVar_0x8005 += 1;
        else
            gSpecialVar_0x8005 += 5;
        break;
    case 2:
    case 3:
    case 4:
        idx = Random() % 3;
        if (idx == 0)
            gSpecialVar_0x8005 += 1;
        else if (idx == 1)
            gSpecialVar_0x8005 += 5;
        else
            gSpecialVar_0x8005 -= 1;
        break;
    case 5:
        idx = Random() % 2;
        if (idx == 0)
            gSpecialVar_0x8005 += 5;
        else
            gSpecialVar_0x8005 -= 1;
        break;
    case 6:
        idx = Random() % 3;
        if (idx == 0)
            gSpecialVar_0x8005 -= 5;
        else if (idx == 1)
            gSpecialVar_0x8005 += 1;
        else
            gSpecialVar_0x8005 += 5;
        break;
    case 7:
    case 8:
    case 9:
        idx = Random() % 4;
        if (idx == 0)
            gSpecialVar_0x8005 -= 5;
        else if (idx == 1)
            gSpecialVar_0x8005 += 1;
        else if (idx == 2)
            gSpecialVar_0x8005 += 5;
        else
            gSpecialVar_0x8005 -= 1;
        break;
    case 10:
        idx = Random() % 3;
        if (idx == 0)
            gSpecialVar_0x8005 -= 5;
        else if (idx == 1)
            gSpecialVar_0x8005 += 5;
        else
            gSpecialVar_0x8005 -= 1;
        break;
    case 11:
        idx = Random() % 2;
        if (idx == 0)
            gSpecialVar_0x8005 -= 5;
        else
            gSpecialVar_0x8005 += 1;
        break;
    case 12:
    case 13:
    case 14:
        idx = Random() % 3;
        if (idx == 0)
            gSpecialVar_0x8005 -= 5;
        else if (idx == 1)
            gSpecialVar_0x8005 += 1;
        else
            gSpecialVar_0x8005 -= 1;
        break;
    case 15:
        idx = Random() % 2;
        if (idx == 0)
            gSpecialVar_0x8005 -= 5;
        else
            gSpecialVar_0x8005 -= 1;
        break;
    }
    if (gSpecialVar_0x8005 > 15)
    {
        if (gSpecialVar_0x8004 % 5 == 1)
            gSpecialVar_0x8005 = gSpecialVar_0x8004 + 1;
        else if (gSpecialVar_0x8004 % 5 == 0)
            gSpecialVar_0x8005 = gSpecialVar_0x8004 - 1;
        else
            gSpecialVar_0x8005 = gSpecialVar_0x8004 + 1;
    }
}

bool8 DoesPlayerPartyContainSpecies(void)
{
    u8 partyCount = CalculatePlayerPartyCount();
    u8 i;
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG, NULL) == gSpecialVar_0x8004)
            return TRUE;
    }
    return FALSE;
}

static const u8 sSlotMachineIndices[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    2,
    2,
    2,
    3,
    3,
    3,
    4,
    4,
    5
};

u8 GetRandomSlotMachineId(void)
{
    u16 rval = Random() % NELEMS(sSlotMachineIndices);
    return sSlotMachineIndices[rval];
}

static const struct WindowTemplate sElevatorCurrentFloorWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 1,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x008
};

static const u8 *const sFloorNamePointers[] = {
    gText_B4F,
    gText_B3F,
    gText_B2F,
    gText_B1F,
    gText_1F,
    gText_2F,
    gText_3F,
    gText_4F,
    gText_5F,
    gText_6F,
    gText_7F,
    gText_8F,
    gText_9F,
    gText_10F,
    gText_11F,
    gText_Rooftop
};

static const u16 sElevatorWindowMetatilesGoingUp[][3] = {
    {
        METATILE_SilphCo_ElevatorWindow_Top0,
        METATILE_SilphCo_ElevatorWindow_Top1,
        METATILE_SilphCo_ElevatorWindow_Top2
    },
    {
        METATILE_SilphCo_ElevatorWindow_Mid0,
        METATILE_SilphCo_ElevatorWindow_Mid1,
        METATILE_SilphCo_ElevatorWindow_Mid2
    },
    {
        METATILE_SilphCo_ElevatorWindow_Bottom0,
        METATILE_SilphCo_ElevatorWindow_Bottom1,
        METATILE_SilphCo_ElevatorWindow_Bottom2
    }
};

static const u16 sElevatorWindowMetatilesGoingDown[][3] = {
    {
        METATILE_SilphCo_ElevatorWindow_Top0,
        METATILE_SilphCo_ElevatorWindow_Top2,
        METATILE_SilphCo_ElevatorWindow_Top1
    },
    {
        METATILE_SilphCo_ElevatorWindow_Mid0,
        METATILE_SilphCo_ElevatorWindow_Mid2,
        METATILE_SilphCo_ElevatorWindow_Mid1
    },
    {
        METATILE_SilphCo_ElevatorWindow_Bottom0,
        METATILE_SilphCo_ElevatorWindow_Bottom2,
        METATILE_SilphCo_ElevatorWindow_Bottom1
    }
};

static const u8 sElevatorAnimationDuration[] = {
    8,
    16,
    24,
    32,
    38,
    46,
    53,
    56,
    57
};

static const u8 sElevatorWindowAnimDuration[] = {
    3,
    6,
    9,
    12,
    15,
    18,
    21,
    24,
    27
};

void GetElevatorFloor(void)
{
    u16 floor = 4;
    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_ROCKET_HIDEOUT_B1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_SILPH_CO_1F):
            floor = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_2F):
            floor = 5;
            break;
        case MAP_NUM(MAP_SILPH_CO_3F):
            floor = 6;
            break;
        case MAP_NUM(MAP_SILPH_CO_4F):
            floor = 7;
            break;
        case MAP_NUM(MAP_SILPH_CO_5F):
            floor = 8;
            break;
        case MAP_NUM(MAP_SILPH_CO_6F):
            floor = 9;
            break;
        case MAP_NUM(MAP_SILPH_CO_7F):
            floor = 10;
            break;
        case MAP_NUM(MAP_SILPH_CO_8F):
            floor = 11;
            break;
        case MAP_NUM(MAP_SILPH_CO_9F):
            floor = 12;
            break;
        case MAP_NUM(MAP_SILPH_CO_10F):
            floor = 13;
            break;
        case MAP_NUM(MAP_SILPH_CO_11F):
            floor = 14;
            break;
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B1F):
            floor = 3;
            break;
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B2F):
            floor = 2;
            break;
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B4F):
            floor = 0;
            break;
        }
    }
    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_CELADON_CITY_DEPARTMENT_STORE_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_1F):
            floor = 4;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_2F):
            floor = 5;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_3F):
            floor = 6;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_4F):
            floor = 7;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_5F):
            floor = 8;
            break;
        }
    }
    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_TRAINER_TOWER_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_TRAINER_TOWER_1F):
        case MAP_NUM(MAP_TRAINER_TOWER_2F):
        case MAP_NUM(MAP_TRAINER_TOWER_3F):
        case MAP_NUM(MAP_TRAINER_TOWER_4F):
        case MAP_NUM(MAP_TRAINER_TOWER_5F):
        case MAP_NUM(MAP_TRAINER_TOWER_6F):
        case MAP_NUM(MAP_TRAINER_TOWER_7F):
        case MAP_NUM(MAP_TRAINER_TOWER_8F):
        case MAP_NUM(MAP_TRAINER_TOWER_ROOF):
            floor = 15;
            break;
        case MAP_NUM(MAP_TRAINER_TOWER_LOBBY):
            floor = 3;
            break;
        }
    }
    VarSet(VAR_ELEVATOR_FLOOR, floor);
}

u16 InitElevatorFloorSelectMenuPos(void)
{
    sElevatorScroll = 0;
    sElevatorCursorPos = 0;

    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_ROCKET_HIDEOUT_B1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_SILPH_CO_11F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 0;
            break;
        case MAP_NUM(MAP_SILPH_CO_10F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 1;
            break;
        case MAP_NUM(MAP_SILPH_CO_9F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 2;
            break;
        case MAP_NUM(MAP_SILPH_CO_8F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 3;
            break;
        case MAP_NUM(MAP_SILPH_CO_7F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_6F):
            sElevatorScroll = 1;
            sElevatorCursorPos = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_5F):
            sElevatorScroll = 2;
            sElevatorCursorPos = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_4F):
            sElevatorScroll = 3;
            sElevatorCursorPos = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_3F):
            sElevatorScroll = 4;
            sElevatorCursorPos = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_2F):
            sElevatorScroll = 5;
            sElevatorCursorPos = 4;
            break;
        case MAP_NUM(MAP_SILPH_CO_1F):
            sElevatorScroll = 5;
            sElevatorCursorPos = 5;
            break;
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B1F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 0;
            break;
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B2F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 1;
            break;
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B4F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 2;
            break;
        }
    }
    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_CELADON_CITY_DEPARTMENT_STORE_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_5F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 0;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_4F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 1;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_3F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 2;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_2F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 3;
            break;
        case MAP_NUM(MAP_CELADON_CITY_DEPARTMENT_STORE_1F):
            sElevatorScroll = 0;
            sElevatorCursorPos = 4;
            break;
        }
    }
    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_TRAINER_TOWER_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_TRAINER_TOWER_1F):
        case MAP_NUM(MAP_TRAINER_TOWER_2F):
        case MAP_NUM(MAP_TRAINER_TOWER_3F):
        case MAP_NUM(MAP_TRAINER_TOWER_4F):
        case MAP_NUM(MAP_TRAINER_TOWER_5F):
        case MAP_NUM(MAP_TRAINER_TOWER_6F):
        case MAP_NUM(MAP_TRAINER_TOWER_7F):
        case MAP_NUM(MAP_TRAINER_TOWER_8F):
        case MAP_NUM(MAP_TRAINER_TOWER_ROOF):
            sElevatorScroll = 0;
            sElevatorCursorPos = 0;
            break;
        case MAP_NUM(MAP_TRAINER_TOWER_LOBBY):
            sElevatorScroll = 0;
            sElevatorCursorPos = 1;
            break;
        }
    }
    return sElevatorCursorPos;
}

void AnimateElevator(void)
{
    u16 nfloors;
    s16 *data = gTasks[CreateTask(Task_ElevatorShake, 9)].data;
    data[1] = 0;
    data[2] = 0;
    data[4] = 1;
    if (gSpecialVar_0x8005 > gSpecialVar_0x8006)
    {
        nfloors = gSpecialVar_0x8005 - gSpecialVar_0x8006;
        data[6] = 1;
    }
    else
    {
        nfloors = gSpecialVar_0x8006 - gSpecialVar_0x8005;
        data[6] = 0;
    }
    if (nfloors > 8)
        nfloors = 8;
    data[5] = sElevatorAnimationDuration[nfloors];
    SetCameraPanningCallback(NULL);
    AnimateElevatorWindowView(nfloors, data[6]);
    PlaySE(SE_ELEVATOR);
}

static void Task_ElevatorShake(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1]++;
    if ((data[1] % 3) == 0)
    {
        data[1] = 0;
        data[2]++;
        data[4] = -data[4];
        SetCameraPanning(0, data[4]);
        if (data[2] == data[5])
        {
            PlaySE(SE_DING_DONG);
            DestroyTask(taskId);
            ScriptContext_Enable();
            InstallCameraPanAheadCallback();
        }
    }
}

static const u8 sText_NowOn[] = _("Now on:");

void DrawElevatorCurrentFloorWindow(void)
{
    const u8 *floorname;
    u32 strwidth;

    sElevatorCurrentFloorWindowId = AddWindow(&sElevatorCurrentFloorWindowTemplate);
    LoadUserWindowBorderGfx(sElevatorCurrentFloorWindowId, 0x21D, BG_PLTT_ID(13));
    DrawStdFrameWithCustomTileAndPalette(sElevatorCurrentFloorWindowId, FALSE, 0x21D, 13);
    AddTextPrinterParameterized(sElevatorCurrentFloorWindowId, FONT_NORMAL, sText_NowOn, 0, 2, 0xFF, NULL);
    floorname = sFloorNamePointers[gSpecialVar_0x8005];
    strwidth = GetStringWidth(FONT_NORMAL, floorname, 0);
    AddTextPrinterParameterized(sElevatorCurrentFloorWindowId, FONT_NORMAL, floorname, 56 - strwidth, 16, 0xFF, NULL);
    PutWindowTilemap(sElevatorCurrentFloorWindowId);
    CopyWindowToVram(sElevatorCurrentFloorWindowId, COPYWIN_FULL);
}

void CloseElevatorCurrentFloorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(sElevatorCurrentFloorWindowId, TRUE);
    RemoveWindow(sElevatorCurrentFloorWindowId);
}

static void AnimateElevatorWindowView(u16 nfloors, u8 direction)
{
    u8 taskId;
    if (FuncIsActiveTask(Task_AnimateElevatorWindowView) != TRUE)
    {
        taskId = CreateTask(Task_AnimateElevatorWindowView, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = direction;
        gTasks[taskId].data[3] = sElevatorWindowAnimDuration[nfloors];
    }
}

static void Task_AnimateElevatorWindowView(u8 taskId)
{
    u8 i;
    u8 j;
    s16 *data = gTasks[taskId].data;
    if (data[1] == 6)
    {
        data[0]++;
        if (data[2] == 0)
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                    MapGridSetMetatileIdAt(j + 1 + MAP_OFFSET, i + MAP_OFFSET, sElevatorWindowMetatilesGoingUp[i][data[0] % 3] | MAPGRID_COLLISION_MASK);
            }
        }
        else
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                    MapGridSetMetatileIdAt(j + 1 + MAP_OFFSET, i + MAP_OFFSET, sElevatorWindowMetatilesGoingDown[i][data[0] % 3] | MAPGRID_COLLISION_MASK);
            }
        }
        DrawWholeMapView();
        data[1] = 0;
        if (data[0] == data[3])
            DestroyTask(taskId);
    }
    data[1]++;
}

void ForcePlayerOntoBike(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE);
    Overworld_SetSavedMusic(IS_FRLG ? MUS_RG_CYCLING : MUS_CYCLING);
    Overworld_ChangeMusicTo(IS_FRLG ? MUS_RG_CYCLING : MUS_CYCLING);
}

bool8 IsPlayerNotInTrainerTowerLobby(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_TRAINER_TOWER_LOBBY) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_TRAINER_TOWER_LOBBY))
        return FALSE;
    else
        return TRUE;
}

void BrailleCursorToggle(void)
{
    // 8004 = x - 27
    // 8005 = y
    // 8006 = action (0 = create, 1 = delete)
    u16 x = gSpecialVar_0x8004 + 27;

    if (gSpecialVar_0x8006 == 0)
        sBrailleTextCursorSpriteID = CreateTextCursorSprite(0, x, gSpecialVar_0x8005, 0, 0);
    else
        DestroyTextCursorSprite(sBrailleTextCursorSpriteID);
}

static const u16 sEliteFourLightingPalettes[][16] = {
    INCGFX_U16("graphics/field_specials/elite_four_lighting_0.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_1.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_2.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_3.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_4.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_5.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_6.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_7.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_8.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_9.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_10.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/elite_four_lighting_11.pal", ".gbapal")
};

static const u16 sChampionRoomLightingPalettes[][16] = {
    INCGFX_U16("graphics/field_specials/champion_room_lighting_0.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_1.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_2.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_3.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_4.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_5.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_6.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_7.pal", ".gbapal"),
    INCGFX_U16("graphics/field_specials/champion_room_lighting_8.pal", ".gbapal")
};

static const u8 sEliteFourLightingTimers[] = {
    40,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12
};

static const u8 sChampionRoomLightingTimers[] = {
    20,
     8,
     8,
     8,
     8,
     8,
     8,
     8
};

void DoPokemonLeagueLightingEffect(void)
{
    u8 taskId = CreateTask(Task_RunPokemonLeagueLightingEffect, 8);
    s16 *data = gTasks[taskId].data;
    if (FlagGet(FLAG_TEMP_3) == TRUE)
    {
        gTasks[taskId].func = Task_CancelPokemonLeagueLightingEffect;
    }
    else
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM))
        {
            data[0] = sChampionRoomLightingTimers[0];
            data[2] = 8;
            LoadPalette(sChampionRoomLightingPalettes[0], BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        }
        else
        {
            data[0] = sEliteFourLightingTimers[0];
            data[2] = 11;
            LoadPalette(sEliteFourLightingPalettes[0], BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        }
        data[1] = 0;
        // ApplyGlobalTintToPaletteSlot(7, 1);
    }
}

static void Task_RunPokemonLeagueLightingEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active
     && FlagGet(FLAG_TEMP_2) != FALSE
     && FlagGet(FLAG_TEMP_5) != TRUE
     && --data[0] == 0
    )
    {
        if (++data[1] == data[2])
            data[1] = 0;

        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM))
        {
            data[0] = sChampionRoomLightingTimers[data[1]];
            LoadPalette(sChampionRoomLightingPalettes[data[1]], BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        }
        else
        {
            data[0] = sEliteFourLightingTimers[data[1]];
            LoadPalette(sEliteFourLightingPalettes[data[1]], BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        }
        // ApplyGlobalTintToPaletteSlot(7, 1);
    }
}

static void Task_CancelPokemonLeagueLightingEffect(u8 taskId)
{
    if (FlagGet(FLAG_TEMP_4) != FALSE)
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM))
            LoadPalette(sChampionRoomLightingPalettes[8], BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        else
            LoadPalette(sEliteFourLightingPalettes[11], BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        // ApplyGlobalTintToPaletteSlot(7, 1);
        if (gPaletteFade.active)
        {
            BlendPalettes(0x00000080, 16, RGB_BLACK);
        }
        DestroyTask(taskId);
    }
}

/*
 * Determines which of Lorelei's doll collection to show
 * based on how many times you've entered the Hall of Fame.
 */
void UpdateLoreleiDollCollection(void)
{
    u32 numHofClears = GetGameStat(GAME_STAT_ENTERED_HOF);
    if (numHofClears >= 25)
    {
        FlagClear(FLAG_HIDE_LORELEI_HOUSE_MEOWTH_DOLL);
        if (numHofClears >= 50)
            FlagClear(FLAG_HIDE_LORELEI_HOUSE_CHANSEY_DOLL);
        if (numHofClears >= 75)
            FlagClear(FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_F_DOLL);
        if (numHofClears >= 100)
            FlagClear(FLAG_HIDE_LORELEI_HOUSE_JIGGLYPUFF_DOLL);
        if (numHofClears >= 125)
            FlagClear(FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_M_DOLL);
        if (numHofClears >= 150)
            FlagClear(FLAG_HIDE_LORELEIS_HOUSE_FEAROW_DOLL);
        if (numHofClears >= 175)
            FlagClear(FLAG_HIDE_LORELEIS_HOUSE_PIDGEOT_DOLL);
        if (numHofClears >= 200)
            FlagClear(FLAG_HIDE_LORELEIS_HOUSE_LAPRAS_DOLL);
    }
}

void SampleResortGorgeousMonAndReward(void)
{
    enum Species requestedSpecies = VarGet(VAR_RESORT_GORGEOUS_REQUESTED_MON);
    if (requestedSpecies == SPECIES_NONE || requestedSpecies == 0xFFFF)
    {
        VarSet(VAR_RESORT_GORGEOUS_REQUESTED_MON, SampleResortGorgeousMon());
        VarSet(VAR_RESORT_GORGEOUS_REWARD, SampleResortGorgeousReward());
        VarSet(VAR_RESORT_GOREGEOUS_STEP_COUNTER, 0);
    }
    StringCopy(gStringVar1, gSpeciesInfo[VarGet(VAR_RESORT_GORGEOUS_REQUESTED_MON)].speciesName);
}

static enum Species SampleResortGorgeousMon(void)
{
    u16 i;
    enum Species species;
    for (i = 0; i < 100; i++)
    {
        species = (Random() % (NUM_SPECIES - 1)) + 1;
        if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), 0) == TRUE)
            return species;
    }
    while (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), 0) != TRUE)
    {
        if (species == SPECIES_BULBASAUR)
            species = NUM_SPECIES - 1;
        else
            species--;
    }
    return species;
}

static const u16 sResortGorgeousDeluxeRewards[] = {
    ITEM_BIG_PEARL,
    ITEM_PEARL,
    ITEM_STARDUST,
    ITEM_STAR_PIECE,
    ITEM_NUGGET,
    ITEM_RARE_CANDY
};

static u16 SampleResortGorgeousReward(void)
{
    if ((Random() % 100) >= 30)
        return ITEM_LUXURY_BALL;
    else
        return sResortGorgeousDeluxeRewards[Random() % NELEMS(sResortGorgeousDeluxeRewards)];
}

bool8 PlayerPartyContainsSpeciesWithPlayerID(void)
{
    // 8004 = species
    u8 playerCount = CalculatePlayerPartyCount();
    u8 i;
    for (i = 0; i < playerCount; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG, NULL) == gSpecialVar_0x8004
            && GetPlayerIDAsU32() == GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_OT_ID, NULL))
            return TRUE;
    }
    return FALSE;
}

#define tXtrans   data[0]
#define tTimer    data[1]
#define tNremain  data[2]
#define tDuration data[3]
#define tYtrans   data[4]

void ShakeScreen(void)
{
    /*
     * 0x8004 = x translation
     * 0x8005 = y translation
     * 0x8006 = num interations
     * 0x8007 = duration of an iteration
     */
    u8 taskId = CreateTask(Task_ShakeScreen, 9);
    gTasks[taskId].tXtrans = gSpecialVar_0x8005;
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tNremain = gSpecialVar_0x8006;
    gTasks[taskId].tDuration = gSpecialVar_0x8007;
    gTasks[taskId].tYtrans = gSpecialVar_0x8004;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_M_STRENGTH);
}

static void Task_ShakeScreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tTimer++;
    if (tTimer % tDuration == 0)
    {
        tTimer = 0;
        tNremain--;
        tXtrans = -tXtrans;
        tYtrans = -tYtrans;
        SetCameraPanning(tXtrans, tYtrans);
        if (tNremain == 0)
        {
            Task_EndScreenShake(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void Task_EndScreenShake(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#undef tYtrans
#undef tDuration
#undef tNremain
#undef tTimer
#undef tXtrans

bool8 CutMoveRuinValleyCheck(void)
{
    if (FlagGet(FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE) != TRUE
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_SIX_ISLAND_RUIN_VALLEY)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SIX_ISLAND_RUIN_VALLEY)
     && gSaveBlock1Ptr->pos.x == 24
     && gSaveBlock1Ptr->pos.y == 25
     && GetPlayerFacingDirection() == DIR_NORTH
    )
        return TRUE;
    else
        return FALSE;
}

void CutMoveOpenDottedHoleDoor(void)
{
    MapGridSetMetatileIdAt(31, 31, METATILE_SeviiIslands67_DottedHoleDoor_Open);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE);
    UnlockPlayerFieldControls();
}

void ForcePlayerToStartSurfing(void)
{
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_SURFING);
}

void UpdateTrainerCardPhotoIcons(void)
{
    enum Species species[PARTY_SIZE];
    u32 personality[PARTY_SIZE];
    u8 i;
    u8 partyCount;
    for (i = 0; i < PARTY_SIZE; i++)
        species[i] = SPECIES_NONE;
    partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        species[i] = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG, NULL);
        personality[i] = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_PERSONALITY, NULL);
    }
    VarSet(VAR_TRAINER_CARD_MON_ICON_1, SpeciesToMailSpecies(species[0], personality[0]));
    VarSet(VAR_TRAINER_CARD_MON_ICON_2, SpeciesToMailSpecies(species[1], personality[1]));
    VarSet(VAR_TRAINER_CARD_MON_ICON_3, SpeciesToMailSpecies(species[2], personality[2]));
    VarSet(VAR_TRAINER_CARD_MON_ICON_4, SpeciesToMailSpecies(species[3], personality[3]));
    VarSet(VAR_TRAINER_CARD_MON_ICON_5, SpeciesToMailSpecies(species[4], personality[4]));
    VarSet(VAR_TRAINER_CARD_MON_ICON_6, SpeciesToMailSpecies(species[5], personality[5]));
    VarSet(VAR_TRAINER_CARD_MON_ICON_TINT_IDX, gSpecialVar_0x8004);
}

u16 StickerManGetBragFlags(void)
{
    u16 result = 0;
    u32 numEggs;
    gSpecialVar_0x8004 = GetGameStat(GAME_STAT_ENTERED_HOF);
    numEggs = GetGameStat(GAME_STAT_HATCHED_EGGS);
    gSpecialVar_0x8006 = GetGameStat(GAME_STAT_LINK_BATTLE_WINS);
    if (numEggs > 0xFFFF)
        gSpecialVar_0x8005 = 0xFFFF;
    else
        gSpecialVar_0x8005 = numEggs;
    if (gSpecialVar_0x8004 != 0)
        result |= 1 << 0;
    if (gSpecialVar_0x8005 != 0)
        result |= 1 << 1;
    if (gSpecialVar_0x8006 != 0)
        result |= 1 << 2;
    return result;
}

bool8 CheckAddCoins(void)
{
    if (gSpecialVar_Result + gSpecialVar_0x8006 > 9999)
        return FALSE;
    else
        return TRUE;
}
