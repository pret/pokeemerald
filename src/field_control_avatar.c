#include "global.h"
#include "battle_setup.h"
#include "bike.h"
#include "coord_event_weather.h"
#include "daycare.h"
#include "debug.h"
#include "dexnav.h"
#include "faraway_island.h"
#include "follower_npc.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_control_avatar.h"
#include "field_message_box.h"
#include "field_move.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_poison.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "fldeff_misc.h"
#include "follower_npc.h"
#include "item_menu.h"
#include "link.h"
#include "match_call.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "pokemon.h"
#include "safari_zone.h"
#include "script.h"
#include "secret_base.h"
#include "sound.h"
#include "start_menu.h"
#include "trainer_see.h"
#include "trainer_hill.h"
#include "vs_seeker.h"
#include "wild_encounter.h"
#include "wild_encounter_ow.h"
#include "constants/event_bg.h"
#include "constants/event_objects.h"
#include "constants/field_poison.h"
#include "constants/layouts.h"
#include "constants/metatile_behaviors.h"
#include "constants/songs.h"
#include "constants/trainer_hill.h"

static EWRAM_DATA u8 sWildEncounterImmunitySteps = 0;
static EWRAM_DATA u16 sPrevMetatileBehavior = 0;

COMMON_DATA u8 gSelectedObjectEvent = 0;

static void GetInFrontOfPlayerPosition(struct MapPosition *);
static u16 GetPlayerCurMetatileBehavior(int);
static bool8 TryStartInteractionScript(struct MapPosition *, u16, enum Direction);
static const u8 *GetInteractionScript(struct MapPosition *, u8, enum Direction);
static const u8 *GetInteractedObjectEventScript(struct MapPosition *, u8, enum Direction);
static const u8 *GetInteractedBackgroundEventScript(struct MapPosition *, u8, enum Direction);
static const u8 *GetInteractedMetatileScript(struct MapPosition *, u8, enum Direction);
static const u8 *GetInteractedWaterScript(struct MapPosition *, u8, enum Direction);
static bool32 TrySetupDiveDownScript(void);
static bool32 TrySetupDiveEmergeScript(void);
static bool8 CheckStandardWildEncounter(u16);
static bool8 TryArrowWarp(struct MapPosition *, u16, enum Direction);
static bool8 IsWarpMetatileBehavior(u16);
static bool8 IsArrowWarpMetatileBehavior(u16, enum Direction);
static s8 GetWarpEventAtMapPosition(struct MapHeader *, struct MapPosition *);
static void SetupWarp(struct MapHeader *, s8, struct MapPosition *);
static bool8 TryDoorWarp(struct MapPosition *, u16, enum Direction);
static s8 GetWarpEventAtPosition(struct MapHeader *, u16, u16, u8);
static const u8 *GetCoordEventScriptAtPosition(struct MapHeader *, u16, u16, u8);
static const struct BgEvent *GetBackgroundEventAtPosition(struct MapHeader *, u16, u16, u8);
static bool8 TryStartCoordEventScript(struct MapPosition *);
static bool8 TryStartWarpEventScript(struct MapPosition *, u16);
static bool8 TryStartMiscWalkingScripts(u16);
static bool8 TryStartStepCountScript(u16);
static void UpdateFriendshipStepCounter(void);
static void UpdateFollowerStepCounter(void);
#if OW_POISON_DAMAGE < GEN_5
static bool8 UpdatePoisonStepCounter(void);
#endif // OW_POISON_DAMAGE
static bool32 TrySetUpWalkIntoSignpostScript(struct MapPosition *position, u32 metatileBehavior, enum Direction playerDirection);
static void SetMsgSignPostAndVarFacing(enum Direction playerDirection);
static void SetUpWalkIntoSignScript(const u8 *script, enum Direction playerDirection);
static u32 GetFacingSignpostType(u16 metatileBehvaior, enum Direction direction);
static const u8 *GetSignpostScriptAtMapPosition(struct MapPosition *position);

void FieldClearPlayerInput(struct FieldInput *input)
{
    input->pressedAButton = FALSE;
    input->checkStandardWildEncounter = FALSE;
    input->pressedStartButton = FALSE;
    input->pressedSelectButton = FALSE;
    input->heldDirection = FALSE;
    input->heldDirection2 = FALSE;
    input->tookStep = FALSE;
    input->pressedBButton = FALSE;
    input->pressedRButton = FALSE;
    input->input_field_1_1 = FALSE;
    input->input_field_1_2 = FALSE;
    input->input_field_1_3 = FALSE;
    input->dpadDirection = 0;
}

void FieldGetPlayerInput(struct FieldInput *input, u16 newKeys, u16 heldKeys)
{
    u8 tileTransitionState = gPlayerAvatar.tileTransitionState;
    u8 runningState = gPlayerAvatar.runningState;
    bool8 forcedMove = MetatileBehavior_IsForcedMovementTile(GetPlayerCurMetatileBehavior(runningState));

    if ((tileTransitionState == T_TILE_CENTER && forcedMove == FALSE) || tileTransitionState == T_NOT_MOVING)
    {
        if (GetPlayerSpeed() != PLAYER_SPEED_FASTEST)
        {
            if (newKeys & START_BUTTON)
                input->pressedStartButton = TRUE;
            if (newKeys & SELECT_BUTTON)
                input->pressedSelectButton = TRUE;
            if (newKeys & A_BUTTON)
                input->pressedAButton = TRUE;
            if (newKeys & B_BUTTON)
                input->pressedBButton = TRUE;
            if (newKeys & R_BUTTON)
                input->pressedRButton = TRUE;
        }

        if (heldKeys & (DPAD_UP | DPAD_DOWN | DPAD_LEFT | DPAD_RIGHT))
        {
            input->heldDirection = TRUE;
            input->heldDirection2 = TRUE;
        }
    }

    if (forcedMove == FALSE)
    {
        if (tileTransitionState == T_TILE_CENTER && runningState == MOVING)
            input->tookStep = TRUE;
        if (forcedMove == FALSE && tileTransitionState == T_TILE_CENTER)
            input->checkStandardWildEncounter = TRUE;
    }

    if (heldKeys & DPAD_UP)
        input->dpadDirection = DIR_NORTH;
    else if (heldKeys & DPAD_DOWN)
        input->dpadDirection = DIR_SOUTH;
    else if (heldKeys & DPAD_LEFT)
        input->dpadDirection = DIR_WEST;
    else if (heldKeys & DPAD_RIGHT)
        input->dpadDirection = DIR_EAST;

    if (DEBUG_OVERWORLD_MENU && !DEBUG_OVERWORLD_IN_MENU)
    {
        if ((heldKeys & DEBUG_OVERWORLD_HELD_KEYS) && input->DEBUG_OVERWORLD_TRIGGER_EVENT)
        {
            input->input_field_1_2 = TRUE;
            input->DEBUG_OVERWORLD_TRIGGER_EVENT = FALSE;
        }
    }
}

int ProcessPlayerFieldInput(struct FieldInput *input)
{
    struct MapPosition position;
    enum Direction playerDirection;
    u16 metatileBehavior;

    gSpecialVar_LastTalked = LOCALID_NONE;
    gSelectedObjectEvent = 0;

    gMsgIsSignPost = FALSE;
    playerDirection = GetPlayerFacingDirection();
    GetPlayerPosition(&position);
    metatileBehavior = MapGridGetMetatileBehaviorAt(position.x, position.y);

    if (CheckForTrainersWantingBattle() == TRUE)
        return TRUE;

    if (TryRunOnFrameMapScript() == TRUE)
        return TRUE;

    if (input->pressedBButton && TrySetupDiveEmergeScript() == TRUE)
        return TRUE;
    if (input->tookStep)
    {
        IncrementGameStat(GAME_STAT_STEPS);
        IncrementBirthIslandRockStepCount();
        DespawnAllOverworldWildEncounters(OWE_GENERATED, WILD_CHECK_REPEL);
        if (FindTaskIdByFunc(Task_FollowerNPCOutOfDoor) == TASK_NONE && TryStartStepBasedScript(&position, metatileBehavior, playerDirection) == TRUE)
            return TRUE;
    }

    if ((input->checkStandardWildEncounter) && ((input->dpadDirection == 0) || input->dpadDirection == playerDirection))
    {
        GetInFrontOfPlayerPosition(&position);
        metatileBehavior = MapGridGetMetatileBehaviorAt(position.x, position.y);
        if (TrySetUpWalkIntoSignpostScript(&position, metatileBehavior, playerDirection) == TRUE)
            return TRUE;
        GetPlayerPosition(&position);
        metatileBehavior = MapGridGetMetatileBehaviorAt(position.x, position.y);
    }

    if (input->checkStandardWildEncounter && CheckStandardWildEncounter(metatileBehavior) == TRUE)
        return TRUE;
    if (input->heldDirection && input->dpadDirection == playerDirection)
    {
        if (TryArrowWarp(&position, metatileBehavior, playerDirection) == TRUE)
            return TRUE;
    }

    GetInFrontOfPlayerPosition(&position);
    metatileBehavior = MapGridGetMetatileBehaviorAt(position.x, position.y);

    if (input->heldDirection && (input->dpadDirection == playerDirection) && (TrySetUpWalkIntoSignpostScript(&position, metatileBehavior, playerDirection) == TRUE))
        return TRUE;

    if (input->pressedAButton && TryStartInteractionScript(&position, metatileBehavior, playerDirection) == TRUE)
        return TRUE;

    if (input->heldDirection2 && input->dpadDirection == playerDirection)
    {
        if (TryDoorWarp(&position, metatileBehavior, playerDirection) == TRUE)
            return TRUE;
    }
    if (input->pressedAButton && TrySetupDiveDownScript() == TRUE)
        return TRUE;
    if (input->pressedStartButton)
    {
        FlagSet(FLAG_OPENED_START_MENU);
        PlaySE(SE_WIN_OPEN);
        ShowStartMenu();
        return TRUE;
    }

    if (input->tookStep && TryFindHiddenPokemon())
        return TRUE;

    if (input->pressedSelectButton && UseRegisteredKeyItemOnField() == TRUE)
        return TRUE;

    if (input->pressedRButton && TryStartDexNavSearch())
        return TRUE;

    if (input->input_field_1_2 && DEBUG_OVERWORLD_MENU && !DEBUG_OVERWORLD_IN_MENU)
    {
        PlaySE(SE_WIN_OPEN);
        FreezeObjectEvents();
        Debug_ShowMainMenu();
        return TRUE;
    }

    if (CanTriggerSpinEvolution())
    {
        ResetSpinTimer();
        TrySpecialOverworldEvo(); // Special vars set in CanTriggerSpinEvolution.
        return TRUE;
    }

    return FALSE;
}

void GetPlayerPosition(struct MapPosition *position)
{
    PlayerGetDestCoords(&position->x, &position->y);
    position->elevation = PlayerGetElevation();
}

static void GetInFrontOfPlayerPosition(struct MapPosition *position)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&position->x, &position->y);
    PlayerGetDestCoords(&x, &y);
    if (MapGridGetElevationAt(x, y) != ELEVATION_TRANSITION)
        position->elevation = PlayerGetElevation();
    else
        position->elevation = ELEVATION_TRANSITION;
}

static u16 GetPlayerCurMetatileBehavior(int runningState)
{
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    return MapGridGetMetatileBehaviorAt(x, y);
}

static bool8 TryStartInteractionScript(struct MapPosition *position, u16 metatileBehavior, enum Direction direction)
{
    const u8 *script = GetInteractionScript(position, metatileBehavior, direction);
    if (script == NULL || Script_HasNoEffect(script))
        return FALSE;

    // Don't play interaction sound for certain scripts.
    if (script != LittlerootTown_BrendansHouse_2F_EventScript_PC
     && script != LittlerootTown_MaysHouse_2F_EventScript_PC
     && script != EventScript_PalletTown_PlayersHouse_2F_TurnOnPC
     && script != SecretBase_EventScript_PC
     && script != SecretBase_EventScript_RecordMixingPC
     && script != SecretBase_EventScript_DollInteract
     && script != SecretBase_EventScript_CushionInteract
     && script != EventScript_PC)
        PlaySE(SE_SELECT);

    ScriptContext_SetupScript(script);
    return TRUE;
}

static const u8 *GetInteractionScript(struct MapPosition *position, u8 metatileBehavior, enum Direction direction)
{
    const u8 *script = GetInteractedObjectEventScript(position, metatileBehavior, direction);
    if (script != NULL)
        return script;

    script = GetInteractedBackgroundEventScript(position, metatileBehavior, direction);
    if (script != NULL)
        return script;

    script = GetInteractedMetatileScript(position, metatileBehavior, direction);
    if (script != NULL)
        return script;

    script = GetInteractedWaterScript(position, metatileBehavior, direction);
    if (script != NULL)
        return script;

    return NULL;
}

const u8 *GetInteractedLinkPlayerScript(struct MapPosition *position, u8 metatileBehavior, enum Direction direction)
{
    u8 objectEventId;
    s32 i;

    if (!MetatileBehavior_IsCounter(MapGridGetMetatileBehaviorAt(position->x, position->y)))
        objectEventId = GetObjectEventIdByPosition(position->x, position->y, position->elevation);
    else
        objectEventId = GetObjectEventIdByPosition(position->x + gDirectionToVectors[direction].x, position->y + gDirectionToVectors[direction].y, position->elevation);

    if (objectEventId == OBJECT_EVENTS_COUNT || gObjectEvents[objectEventId].localId == LOCALID_PLAYER)
        return NULL;

    for (i = 0; i < 4; i++)
    {
        if (gLinkPlayerObjectEvents[i].active == TRUE && gLinkPlayerObjectEvents[i].objEventId == objectEventId)
            return NULL;
    }

    gSelectedObjectEvent = objectEventId;
    gSpecialVar_LastTalked = gObjectEvents[objectEventId].localId;
    gSpecialVar_Facing = direction;
    return GetObjectEventScriptPointerByObjectEventId(objectEventId);
}

static const u8 *GetInteractedObjectEventScript(struct MapPosition *position, u8 metatileBehavior, enum Direction direction)
{
    u8 objectEventId;
    const u8 *script;
    s16 currX = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s16 currY = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    u8 currBehavior = MapGridGetMetatileBehaviorAt(currX, currY);

    gSpecialVar_Facing = direction;
    switch (direction)
    {
    case DIR_EAST:
        if (MetatileBehavior_IsSidewaysStairsLeftSideAny(metatileBehavior))
            // sideways stairs left-side to your right -> check northeast
            objectEventId = GetObjectEventIdByPosition(currX + 1, currY - 1, position->elevation);
        else if (MetatileBehavior_IsSidewaysStairsRightSideAny(currBehavior))
            // on top of right-side stairs -> check southeast
            objectEventId = GetObjectEventIdByPosition(currX + 1, currY + 1, position->elevation);
        else
            // check in front of player
            objectEventId = GetObjectEventIdByPosition(position->x, position->y, position->elevation);
        break;
    case DIR_WEST:
        if (MetatileBehavior_IsSidewaysStairsRightSideAny(metatileBehavior))
            // facing sideways stairs right side -> check northwest
            objectEventId = GetObjectEventIdByPosition(currX - 1, currY - 1, position->elevation);
        else if (MetatileBehavior_IsSidewaysStairsLeftSideAny(currBehavior))
            // on top of left-side stairs -> check southwest
            objectEventId = GetObjectEventIdByPosition(currX - 1, currY + 1, position->elevation);
        else
            // check in front of player
            objectEventId = GetObjectEventIdByPosition(position->x, position->y, position->elevation);
        break;
    default:
        objectEventId = GetObjectEventIdByPosition(position->x, position->y, position->elevation);
        break;
    }

    if (objectEventId == OBJECT_EVENTS_COUNT || gObjectEvents[objectEventId].localId == LOCALID_PLAYER)
    {
        if (MetatileBehavior_IsCounter(metatileBehavior) != TRUE)
            return NULL;

        // Look for an object event on the other side of the counter.
        objectEventId = GetObjectEventIdByPosition(position->x + gDirectionToVectors[direction].x, position->y + gDirectionToVectors[direction].y, position->elevation);
        if (objectEventId == OBJECT_EVENTS_COUNT || gObjectEvents[objectEventId].localId == LOCALID_PLAYER)
            return NULL;
    }

    gSelectedObjectEvent = objectEventId;
    gSpecialVar_LastTalked = gObjectEvents[objectEventId].localId;

    if (PlayerHasFollowerNPC() && objectEventId == GetFollowerNPCObjectId())
        script = GetFollowerNPCScriptPointer();
    else if (IsOverworldWildEncounter(&gObjectEvents[objectEventId], OWE_ANY))
        script = GetOverworlWildEncounterScript(objectEventId);
    else if (gObjectEvents[objectEventId].localId == OBJ_EVENT_ID_FOLLOWER)
        script = EventScript_Follower;
    else if (InTrainerHill() == TRUE)
        script = GetTrainerHillTrainerScript();
    else
        script = GetObjectEventScriptPointerByObjectEventId(objectEventId);

    script = GetRamScript(gSpecialVar_LastTalked, script);
    return script;
}

static const u8 *GetInteractedBackgroundEventScript(struct MapPosition *position, u8 metatileBehavior, enum Direction direction)
{
    const struct BgEvent *bgEvent = GetBackgroundEventAtPosition(&gMapHeader, position->x - MAP_OFFSET, position->y - MAP_OFFSET, position->elevation);

    if (bgEvent == NULL)
        return NULL;
    if (bgEvent->bgUnion.script == NULL)
        return EventScript_TestSignpostMsg;

    if (GetFacingSignpostType(metatileBehavior, direction) != NOT_SIGNPOST)
        SetMsgSignPostAndVarFacing(direction);

    switch (bgEvent->kind)
    {
    case BG_EVENT_PLAYER_FACING_ANY:
    default:
        return bgEvent->bgUnion.script;
    case BG_EVENT_PLAYER_FACING_NORTH:
        if (direction != DIR_NORTH)
            return NULL;
        break;
    case BG_EVENT_PLAYER_FACING_SOUTH:
        if (direction != DIR_SOUTH)
            return NULL;
        break;
    case BG_EVENT_PLAYER_FACING_EAST:
        if (direction != DIR_EAST)
            return NULL;
        break;
    case BG_EVENT_PLAYER_FACING_WEST:
        if (direction != DIR_WEST)
            return NULL;
        break;
    case 5:
    case 6:
    case BG_EVENT_HIDDEN_ITEM:
        if (bgEvent->bgUnion.hiddenItem.underfoot == TRUE)
            return NULL;
        gSpecialVar_0x8004 = bgEvent->bgUnion.hiddenItem.hiddenItemId + FLAG_HIDDEN_ITEMS_START;
        gSpecialVar_0x8005 = bgEvent->bgUnion.hiddenItem.item;
        gSpecialVar_0x8009 = bgEvent->bgUnion.hiddenItem.quantity;
        if (FlagGet(gSpecialVar_0x8004) == TRUE)
            return NULL;
        return EventScript_HiddenItemScript;
    case BG_EVENT_SECRET_BASE:
        if (direction == DIR_NORTH)
        {
            gSpecialVar_0x8004 = bgEvent->bgUnion.secretBaseId;
            if (TrySetCurSecretBase())
                return SecretBase_EventScript_CheckEntrance;
        }
        return NULL;
    }

    return bgEvent->bgUnion.script;
}

static const u8 *GetInteractedMetatileScript(struct MapPosition *position, u8 metatileBehavior, enum Direction direction)
{
    s8 elevation;

    if (MetatileBehavior_IsPlayerFacingTVScreen(metatileBehavior, direction) == TRUE)
    {
        if (IS_FRLG)
            return EventScript_PlayerFacingTVScreen;
        else
            return EventScript_TV;
    }
    if (MetatileBehavior_IsPC(metatileBehavior) == TRUE)
        return EventScript_PC;
    if (MetatileBehavior_IsClosedSootopolisDoor(metatileBehavior) == TRUE)
        return EventScript_ClosedSootopolisDoor;
    if (MetatileBehavior_IsSkyPillarClosedDoor(metatileBehavior) == TRUE)
        return SkyPillar_Outside_EventScript_ClosedDoor;
    if (MetatileBehavior_IsCableBoxResults1(metatileBehavior) == TRUE)
        return EventScript_CableBoxResults;
    if (MetatileBehavior_IsPokeblockFeeder(metatileBehavior) == TRUE)
        return EventScript_PokeBlockFeeder;
    if (MetatileBehavior_IsTrickHousePuzzleDoor(metatileBehavior) == TRUE)
        return Route110_TrickHousePuzzle_EventScript_Door;
    if (MetatileBehavior_IsRegionMap(metatileBehavior) == TRUE)
        return EventScript_RegionMap;
    if (MetatileBehavior_IsRunningShoesManual(metatileBehavior) == TRUE)
        return EventScript_RunningShoesManual;
    if (MetatileBehavior_IsPictureBookShelf(metatileBehavior) == TRUE)
        return EventScript_PictureBookShelf;
    if (MetatileBehavior_IsBookShelf(metatileBehavior) == TRUE)
        return EventScript_BookShelf;
    if (MetatileBehavior_IsPokeCenterBookShelf(metatileBehavior) == TRUE)
        return EventScript_PokemonCenterBookShelf;
    if (MetatileBehavior_IsVase(metatileBehavior) == TRUE)
        return EventScript_Vase;
    if (MetatileBehavior_IsTrashCan(metatileBehavior) == TRUE)
        return EventScript_EmptyTrashCan;
    if (MetatileBehavior_IsShopShelf(metatileBehavior) == TRUE)
        return EventScript_ShopShelf;
    if (MetatileBehavior_IsBlueprint(metatileBehavior) == TRUE)
        return EventScript_Blueprint;
    if (MetatileBehavior_IsPlayerFacingWirelessBoxResults(metatileBehavior, direction) == TRUE)
        return EventScript_WirelessBoxResults;
    if (MetatileBehavior_IsCableBoxResults2(metatileBehavior, direction) == TRUE)
        return EventScript_CableBoxResults;
    if (MetatileBehavior_IsQuestionnaire(metatileBehavior) == TRUE)
        return EventScript_Questionnaire;
    if (MetatileBehavior_IsTrainerHillTimer(metatileBehavior) == TRUE)
        return EventScript_TrainerHillTimer;
    if (IS_FRLG)
    {
        if (MetatileBehavior_IsFood(metatileBehavior) == TRUE)
            return EventScript_Food;
        if (MetatileBehavior_IsImpressiveMachine(metatileBehavior) == TRUE)
            return EventScript_ImpressiveMachine;
        if (MetatileBehavior_IsBlueprints(metatileBehavior) == TRUE)
            return EventScript_Blueprints;
        if (MetatileBehavior_IsVideoGame(metatileBehavior) == TRUE)
            return EventScript_VideoGame;
        if (MetatileBehavior_IsBurglary(metatileBehavior) == TRUE)
            return EventScript_Burglary;
        if (MetatileBehavior_IsTrainerTowerMonitor(metatileBehavior) == TRUE)
            return TrainerTower_EventScript_ShowTime;
        if (MetatileBehavior_IsComputer(metatileBehavior) == TRUE)
            return EventScript_Computer;
        if (MetatileBehavior_IsCabinet(metatileBehavior) == TRUE)
            return EventScript_Cabinet;
        if (MetatileBehavior_IsKitchen(metatileBehavior) == TRUE)
            return EventScript_Kitchen;
        if (MetatileBehavior_IsDresser(metatileBehavior) == TRUE)
            return EventScript_Dresser;
        if (MetatileBehavior_IsSnacks(metatileBehavior) == TRUE)
            return EventScript_Snacks;
        if (MetatileBehavior_IsPainting(metatileBehavior) == TRUE)
            return EventScript_Painting;
        if (MetatileBehavior_IsPowerPlantMachine(metatileBehavior) == TRUE)
            return EventScript_PowerPlantMachine;
        if (MetatileBehavior_IsTelephone(metatileBehavior) == TRUE)
            return EventScript_Telephone;
        if (MetatileBehavior_IsAdvertisingPoster(metatileBehavior) == TRUE)
            return EventScript_AdvertisingPoster;
        if (MetatileBehavior_IsTastyFood(metatileBehavior) == TRUE)
            return EventScript_TastyFood;
        if (MetatileBehavior_IsCup(metatileBehavior) == TRUE)
            return EventScript_Cup;
        if (MetatileBehavior_IsBlinkingLights(metatileBehavior) == TRUE)
            return EventScript_BlinkingLights;
        if (MetatileBehavior_IsNeatlyLinedUpTools(metatileBehavior) == TRUE)
            return EventScript_NeatlyLinedUpTools;
        if (MetatileBehavior_IsPlayerFacingCableClubWirelessMonitor(metatileBehavior, direction) == TRUE)
            return CableClub_EventScript_ShowWirelessCommunicationScreen_Frlg;
        if (MetatileBehavior_IsPlayerFacingBattleRecords(metatileBehavior, direction) == TRUE)
            return CableClub_EventScript_ShowBattleRecords_Frlg;
        if (MetatileBehavior_IsIndigoPlateauSign1(metatileBehavior) == TRUE)
        {
            if (direction != DIR_NORTH)
                return NULL;
            SetMsgSignPostAndVarFacing(direction);
            return EventScript_Indigo_UltimateGoal;
        }
        if (MetatileBehavior_IsIndigoPlateauSign2(metatileBehavior) == TRUE)
        {
            if (direction != DIR_NORTH)
                return NULL;
            SetMsgSignPostAndVarFacing(direction);
            return EventScript_Indigo_HighestAuthority;
        }
    }

    if (MetatileBehavior_IsPokeMartSign(metatileBehavior) == TRUE)
    {
        if (direction != DIR_NORTH)
            return NULL;
        SetMsgSignPostAndVarFacing(direction);
        return Common_EventScript_ShowPokemartSign;
    }
    if (MetatileBehavior_IsPokemonCenterSign(metatileBehavior) == TRUE)
    {
        if (direction != DIR_NORTH)
            return NULL;
        SetMsgSignPostAndVarFacing(direction);
        return Common_EventScript_ShowPokemonCenterSign;
    }
    if (IsFieldMoveUnlocked(FIELD_MOVE_ROCK_CLIMB) && MetatileBehavior_IsRockClimbable(metatileBehavior) == TRUE && !IsRockClimbActive())
        return EventScript_UseRockClimb;

    elevation = position->elevation;
    if (elevation == MapGridGetElevationAt(position->x, position->y))
    {
        if (MetatileBehavior_IsSecretBasePC(metatileBehavior) == TRUE)
            return SecretBase_EventScript_PC;
        if (MetatileBehavior_IsRecordMixingSecretBasePC(metatileBehavior) == TRUE)
            return SecretBase_EventScript_RecordMixingPC;
        if (MetatileBehavior_IsSecretBaseSandOrnament(metatileBehavior) == TRUE)
            return SecretBase_EventScript_SandOrnament;
        if (MetatileBehavior_IsSecretBaseShieldOrToyTV(metatileBehavior) == TRUE)
            return SecretBase_EventScript_ShieldOrToyTV;
        if (MetatileBehavior_IsSecretBaseDecorationBase(metatileBehavior) == TRUE)
        {
            CheckInteractedWithFriendsFurnitureBottom();
            return NULL;
        }
        if (MetatileBehavior_HoldsLargeDecoration(metatileBehavior) == TRUE)
        {
            CheckInteractedWithFriendsFurnitureMiddle();
            return NULL;
        }
        if (MetatileBehavior_HoldsSmallDecoration(metatileBehavior) == TRUE)
        {
            CheckInteractedWithFriendsFurnitureTop();
            return NULL;
        }
    }
    else if (MetatileBehavior_IsSecretBasePoster(metatileBehavior) == TRUE)
    {
        CheckInteractedWithFriendsPosterDecor();
        return NULL;
    }

    return NULL;
}

static const u8 *GetInteractedWaterScript(struct MapPosition *unused1, u8 metatileBehavior, enum Direction direction)
{
    if (MetatileBehavior_IsFastWater(metatileBehavior) == TRUE && !TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        return EventScript_CurrentTooFast;
    if (IsFieldMoveUnlocked(FIELD_MOVE_SURF) && PartyHasMonWithSurf() == TRUE && IsPlayerFacingSurfableFishableWater() == TRUE
     && CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_SURF)
     )
        return EventScript_UseSurf;

    if (MetatileBehavior_IsWaterfall(metatileBehavior) == TRUE
     && CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_WATERFALL)
     )
    {
        if (IsFieldMoveUnlocked(FIELD_MOVE_WATERFALL) && IsPlayerSurfingNorth() == TRUE)
            return EventScript_UseWaterfall;
        else
            return EventScript_CannotUseWaterfall;
    }
    return NULL;
}

static bool32 TrySetupDiveDownScript(void)
{
    if (!CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_DIVE))
        return FALSE;

    if (IsFieldMoveUnlocked(FIELD_MOVE_DIVE) && TrySetDiveWarp() == 2)
    {
        ScriptContext_SetupScript(EventScript_UseDive);
        return TRUE;
    }
    return FALSE;
}

static bool32 TrySetupDiveEmergeScript(void)
{
    if (!CheckFollowerNPCFlag(FOLLOWER_NPC_FLAG_CAN_DIVE))
        return FALSE;

    if (IsFieldMoveUnlocked(FIELD_MOVE_DIVE) && gMapHeader.mapType == MAP_TYPE_UNDERWATER && TrySetDiveWarp() == 1)
    {
        ScriptContext_SetupScript(EventScript_UseDiveUnderwater);
        return TRUE;
    }
    return FALSE;
}

bool8 TryStartStepBasedScript(struct MapPosition *position, u16 metatileBehavior, enum Direction direction)
{
    if (TryStartCoordEventScript(position) == TRUE)
        return TRUE;
    if (TryStartWarpEventScript(position, metatileBehavior) == TRUE)
        return TRUE;
    if (TryStartMiscWalkingScripts(metatileBehavior) == TRUE)
        return TRUE;
    if (TryStartStepCountScript(metatileBehavior) == TRUE)
        return TRUE;
    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_FORCED_MOVE) && !MetatileBehavior_IsForcedMovementTile(metatileBehavior) && UpdateRepelCounter() == TRUE)
        return TRUE;
    if (OnStep_DexNavSearch())
        return TRUE;
    return FALSE;
}

static bool8 TryStartCoordEventScript(struct MapPosition *position)
{
    const u8 *script = GetCoordEventScriptAtPosition(&gMapHeader, position->x - MAP_OFFSET, position->y - MAP_OFFSET, position->elevation);

    if (script == NULL)
        return FALSE;

    struct ScriptContext ctx;
    if (!RunScriptImmediatelyUntilEffect(SCREFF_V1 | SCREFF_HARDWARE, script, &ctx))
        return FALSE;

    ScriptContext_ContinueScript(&ctx);
    return TRUE;
}

static bool8 TryStartMiscWalkingScripts(u16 metatileBehavior)
{
    s16 x, y;

    if (MetatileBehavior_IsCrackedFloorHole(metatileBehavior))
    {
        ScriptContext_SetupScript(EventScript_FallDownHole);
        return TRUE;
    }
    else if (MetatileBehavior_IsBattlePyramidWarp(metatileBehavior))
    {
        ScriptContext_SetupScript(BattlePyramid_WarpToNextFloor);
        return TRUE;
    }
    else if (MetatileBehavior_IsSecretBaseGlitterMat(metatileBehavior) == TRUE)
    {
        DoSecretBaseGlitterMatSparkle();
        return FALSE;
    }
    else if (MetatileBehavior_IsSecretBaseSoundMat(metatileBehavior) == TRUE)
    {
        PlayerGetDestCoords(&x, &y);
        PlaySecretBaseMusicNoteMatSound(MapGridGetMetatileIdAt(x, y));
        return FALSE;
    }
    return FALSE;
}

static bool8 TryStartStepCountScript(u16 metatileBehavior)
{
    if (InUnionRoom() == TRUE)
    {
        return FALSE;
    }

    IncrementRematchStepCounter();
    IncrementDaycareSteps();
    UpdateFriendshipStepCounter();
    UpdateFarawayIslandStepCounter();
    UpdateFollowerStepCounter();

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_FORCED_MOVE) && !MetatileBehavior_IsForcedMovementTile(metatileBehavior))
    {
    #if OW_POISON_DAMAGE < GEN_5
        if (UpdatePoisonStepCounter() == TRUE)
        {
            ScriptContext_SetupScript(EventScript_FieldPoison);
            return TRUE;
        }
    #endif
        if (ShouldEggHatch())
        {
            IncrementGameStat(GAME_STAT_HATCHED_EGGS);
            ScriptContext_SetupScript(EventScript_EggHatch);
            return TRUE;
        }
        if (AbnormalWeatherHasExpired() == TRUE)
        {
            ScriptContext_SetupScript(AbnormalWeather_EventScript_EndEventAndCleanup_1);
            return TRUE;
        }
        if (ShouldDoBrailleRegicePuzzle() == TRUE)
        {
            ScriptContext_SetupScript(IslandCave_EventScript_OpenRegiEntrance);
            return TRUE;
        }
        if (ShouldDoWallyCall() == TRUE)
        {
            ScriptContext_SetupScript(MauvilleCity_EventScript_RegisterWallyCall);
            return TRUE;
        }
        if (ShouldDoScottFortreeCall() == TRUE)
        {
            ScriptContext_SetupScript(Route119_EventScript_ScottWonAtFortreeGymCall);
            return TRUE;
        }
        if (ShouldDoScottBattleFrontierCall() == TRUE)
        {
            ScriptContext_SetupScript(LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall);
            return TRUE;
        }
        if (ShouldDoRoxanneCall() == TRUE)
        {
            ScriptContext_SetupScript(RustboroCity_Gym_EventScript_RegisterRoxanne);
            return TRUE;
        }
        if (ShouldDoRivalRayquazaCall() == TRUE)
        {
            ScriptContext_SetupScript(MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall);
            return TRUE;
        }
        if (UpdateVsSeekerStepCounter())
        {
            ScriptContext_SetupScript(EventScript_VsSeekerChargingDone);
            return TRUE;
        }
    }

    if (SafariZoneTakeStep() == TRUE)
        return TRUE;
    if (CountSSTidalStep(1) == TRUE)
    {
        ScriptContext_SetupScript(SSTidalCorridor_EventScript_ReachedStepCount);
        return TRUE;
    }
    if (TryStartMatchCall())
        return TRUE;
    return FALSE;
}

static void UNUSED ClearFriendshipStepCounter(void)
{
    VarSet(VAR_FRIENDSHIP_STEP_COUNTER, 0);
}

static void UpdateFriendshipStepCounter(void)
{
    u16 *ptr = GetVarPointer(VAR_FRIENDSHIP_STEP_COUNTER);
    int i;

    (*ptr)++;
    (*ptr) %= 128;
    if (*ptr == 0)
    {
        struct Pokemon *mon = gParties[B_TRAINER_PLAYER];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            AdjustFriendship(mon, FRIENDSHIP_EVENT_WALKING);
            mon++;
        }
    }
}

static void UpdateFollowerStepCounter(void)
{
    if (gPartiesCount[B_TRAINER_PLAYER] > 0 && gFollowerSteps < (u16)-1)
        gFollowerSteps++;
}

void ClearPoisonStepCounter(void)
{
    VarSet(VAR_POISON_STEP_COUNTER, 0);
}

#if OW_POISON_DAMAGE < GEN_5
static bool8 UpdatePoisonStepCounter(void)
{
    u16 *ptr;

    if (gMapHeader.mapType != MAP_TYPE_SECRET_BASE)
    {
        ptr = GetVarPointer(VAR_POISON_STEP_COUNTER);
        (*ptr)++;
        (*ptr) %= 4;
        if (*ptr == 0)
        {
            switch (DoPoisonFieldEffect())
            {
            case FLDPSN_NONE:
                return FALSE;
            case FLDPSN_PSN:
                return FALSE;
            case FLDPSN_FNT:
                return TRUE;
            }
        }
    }
    return FALSE;
}
#endif // OW_POISON_DAMAGE

void RestartWildEncounterImmunitySteps(void)
{
    // Starts at 0 and counts up to 4 steps.
    sWildEncounterImmunitySteps = 0;
}

static bool32 ShouldDisableRandomEncounters(void)
{
    if (FlagGet(WE_FLAG_NO_ENCOUNTER))
        return TRUE;

    if (!WE_VANILLA_RANDOM && WE_OW_ENCOUNTERS)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && !WE_OWE_BATTLE_PIKE)
            return FALSE;

        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR && !WE_OWE_BATTLE_PYRAMID)
            return FALSE;
    }

    return !WE_VANILLA_RANDOM;
}

static bool8 CheckStandardWildEncounter(u16 metatileBehavior)
{
    if (ShouldDisableRandomEncounters())
        return FALSE;

    if (sWildEncounterImmunitySteps < 4)
    {
        sWildEncounterImmunitySteps++;
        sPrevMetatileBehavior = metatileBehavior;
        return FALSE;
    }

    if (StandardWildEncounter(metatileBehavior, sPrevMetatileBehavior) == TRUE)
    {
        sWildEncounterImmunitySteps = 0;
        sPrevMetatileBehavior = metatileBehavior;
        return TRUE;
    }

    sPrevMetatileBehavior = metatileBehavior;
    return FALSE;
}

static void StorePlayerStateAndSetupWarp(struct MapPosition *position, s32 warpEventId)
{
    StoreInitialPlayerAvatarState();
    SetupWarp(&gMapHeader, warpEventId, position);
}

static bool8 TryArrowWarp(struct MapPosition *position, u16 metatileBehavior, enum Direction direction)
{
    s32 warpEventId = GetWarpEventAtMapPosition(&gMapHeader, position);
    u32 delay;

    if (warpEventId == WARP_ID_NONE)
        return FALSE;

    if (IsArrowWarpMetatileBehavior(metatileBehavior, direction) == TRUE)
    {
        StorePlayerStateAndSetupWarp(position, warpEventId);
        DoWarp();
        return TRUE;
    }
    else if (IsDirectionalStairWarpMetatileBehavior(metatileBehavior, direction) == TRUE)
    {
        delay = 0;
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_BIKE)
        {
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
            delay = 12;
        }

        StorePlayerStateAndSetupWarp(position, warpEventId);
        DoStairWarp(metatileBehavior, delay);
        return TRUE;
    }
    return FALSE;
}

static bool8 TryStartWarpEventScript(struct MapPosition *position, u16 metatileBehavior)
{
    s8 warpEventId = GetWarpEventAtMapPosition(&gMapHeader, position);

    if (warpEventId != WARP_ID_NONE && IsWarpMetatileBehavior(metatileBehavior) == TRUE)
    {
        StoreInitialPlayerAvatarState();
        SetupWarp(&gMapHeader, warpEventId, position);
        if (MetatileBehavior_IsEscalator(metatileBehavior) == TRUE)
        {
            DoEscalatorWarp(metatileBehavior);
            return TRUE;
        }
        if (MetatileBehavior_IsLavaridgeB1FWarp(metatileBehavior) == TRUE)
        {
            DoLavaridgeGymB1FWarp();
            return TRUE;
        }
        if (MetatileBehavior_IsLavaridge1FWarp(metatileBehavior) == TRUE)
        {
            DoLavaridgeGym1FWarp();
            return TRUE;
        }
        if (MetatileBehavior_IsAquaHideoutWarp(metatileBehavior) == TRUE)
        {
            DoTeleportTileWarp();
            return TRUE;
        }
        if (MetatileBehavior_IsUnionRoomWarp(metatileBehavior) == TRUE)
        {
            DoSpinExitWarp();
            return TRUE;
        }
        if (MetatileBehavior_IsMtPyreHole(metatileBehavior) == TRUE)
        {
            ScriptContext_SetupScript(EventScript_FallDownHoleMtPyre);
            return TRUE;
        }
        if (MetatileBehavior_IsMossdeepGymWarp(metatileBehavior) == TRUE)
        {
            DoMossdeepGymWarp();
            return TRUE;
        }
        DoWarp();
        return TRUE;
    }
    return FALSE;
}

static bool8 IsWarpMetatileBehavior(u16 metatileBehavior)
{
    if (MetatileBehavior_IsWarpDoor(metatileBehavior) != TRUE
     && MetatileBehavior_IsLadder(metatileBehavior) != TRUE
     && MetatileBehavior_IsEscalator(metatileBehavior) != TRUE
     && MetatileBehavior_IsNonAnimDoor(metatileBehavior) != TRUE
     && MetatileBehavior_IsLavaridgeB1FWarp(metatileBehavior) != TRUE
     && MetatileBehavior_IsLavaridge1FWarp(metatileBehavior) != TRUE
     && MetatileBehavior_IsAquaHideoutWarp(metatileBehavior) != TRUE
     && MetatileBehavior_IsMtPyreHole(metatileBehavior) != TRUE
     && MetatileBehavior_IsMossdeepGymWarp(metatileBehavior) != TRUE
     && MetatileBehavior_IsUnionRoomWarp(metatileBehavior) != TRUE)
        return FALSE;
    return TRUE;
}

static bool8 IsArrowWarpMetatileBehavior(u16 metatileBehavior, enum Direction direction)
{
    switch (direction)
    {
    case DIR_NORTH:
        return MetatileBehavior_IsNorthArrowWarp(metatileBehavior);
    case DIR_SOUTH:
        return MetatileBehavior_IsSouthArrowWarp(metatileBehavior);
    case DIR_WEST:
        return MetatileBehavior_IsWestArrowWarp(metatileBehavior);
    case DIR_EAST:
        return MetatileBehavior_IsEastArrowWarp(metatileBehavior);
    default:
        return FALSE;
    }
}

static s8 GetWarpEventAtMapPosition(struct MapHeader *mapHeader, struct MapPosition *position)
{
    return GetWarpEventAtPosition(mapHeader, position->x - MAP_OFFSET, position->y - MAP_OFFSET, position->elevation);
}

static void SetupWarp(struct MapHeader *unused, s8 warpEventId, struct MapPosition *position)
{
    const struct WarpEvent *warpEvent;

    u8 trainerHillMapId = GetCurrentTrainerHillMapId();

    if (trainerHillMapId)
    {
        if (trainerHillMapId == GetNumFloorsInTrainerHillChallenge())
        {
            if (warpEventId == 0)
                warpEvent = &gMapHeader.events->warps[0];
            else
                warpEvent = SetWarpDestinationTrainerHill4F();
        }
        else if (trainerHillMapId == TRAINER_HILL_ROOF)
        {
            warpEvent = SetWarpDestinationTrainerHillFinalFloor(warpEventId);
        }
        else
        {
            warpEvent = &gMapHeader.events->warps[warpEventId];
        }
    }
    else
    {
        warpEvent = &gMapHeader.events->warps[warpEventId];
    }

    if (warpEvent->mapNum == MAP_NUM(MAP_DYNAMIC))
    {
        SetWarpDestinationToDynamicWarp(warpEvent->warpId);
    }
    else
    {
        const struct MapHeader *mapHeader;

        SetWarpDestinationToMapWarp(warpEvent->mapGroup, warpEvent->mapNum, warpEvent->warpId);
        UpdateEscapeWarp(position->x, position->y);
        mapHeader = Overworld_GetMapHeaderByGroupAndId(warpEvent->mapGroup, warpEvent->mapNum);
        if (mapHeader->events->warps[warpEvent->warpId].mapNum == MAP_NUM(MAP_DYNAMIC))
            SetDynamicWarp(mapHeader->events->warps[warpEventId].warpId, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, warpEventId);
    }
}

static bool8 TryDoorWarp(struct MapPosition *position, u16 metatileBehavior, enum Direction direction)
{
    s8 warpEventId;

    if (direction == DIR_NORTH)
    {
        if (MetatileBehavior_IsOpenSecretBaseDoor(metatileBehavior) == TRUE)
        {
            WarpIntoSecretBase(position, gMapHeader.events);
            return TRUE;
        }

        if (MetatileBehavior_IsWarpDoor(metatileBehavior) == TRUE)
        {
            warpEventId = GetWarpEventAtMapPosition(&gMapHeader, position);
            if (warpEventId != WARP_ID_NONE && IsWarpMetatileBehavior(metatileBehavior) == TRUE)
            {
                StoreInitialPlayerAvatarState();
                SetupWarp(&gMapHeader, warpEventId, position);
                DoDoorWarp();
                return TRUE;
            }
        }
    }
    return FALSE;
}

static s8 GetWarpEventAtPosition(struct MapHeader *mapHeader, u16 x, u16 y, u8 elevation)
{
    s32 i;
    const struct WarpEvent *warpEvent = mapHeader->events->warps;
    u8 warpCount = mapHeader->events->warpCount;

    for (i = 0; i < warpCount; i++, warpEvent++)
    {
        if ((u16)warpEvent->x == x && (u16)warpEvent->y == y)
        {
            if (warpEvent->elevation == elevation || warpEvent->elevation == ELEVATION_TRANSITION)
                return i;
        }
    }
    return WARP_ID_NONE;
}

static bool32 ShouldTriggerScriptRun(const struct CoordEvent *coordEvent)
{
    u16 *varPtr = GetVarPointer(coordEvent->trigger);
    // Treat non Vars as flags
    if (varPtr == NULL)
        return (FlagGet(coordEvent->trigger) == coordEvent->index);
    else
        return (*varPtr == coordEvent->index);
}

static const u8 *TryRunCoordEventScript(const struct CoordEvent *coordEvent)
{
    if (coordEvent != NULL)
    {
        if (coordEvent->script == NULL)
        {
            DoCoordEventWeather(coordEvent->trigger);
            return NULL;
        }
        if (coordEvent->trigger == TRIGGER_RUN_IMMEDIATELY)
        {
            RunScriptImmediately(coordEvent->script);
            return NULL;
        }
        if (ShouldTriggerScriptRun(coordEvent))
            return coordEvent->script;
    }
    return NULL;
}

static const u8 *GetCoordEventScriptAtPosition(struct MapHeader *mapHeader, u16 x, u16 y, u8 elevation)
{
    s32 i;
    const struct CoordEvent *coordEvents = mapHeader->events->coordEvents;
    u8 coordEventCount = mapHeader->events->coordEventCount;

    for (i = 0; i < coordEventCount; i++)
    {
        if ((u16)coordEvents[i].x == x && (u16)coordEvents[i].y == y)
        {
            if (coordEvents[i].elevation == elevation || coordEvents[i].elevation == ELEVATION_TRANSITION)
            {
                const u8 *script = TryRunCoordEventScript(&coordEvents[i]);
                if (script != NULL)
                    return script;
            }
        }
    }
    return NULL;
}

const u8 *GetCoordEventScriptAtMapPosition(struct MapPosition *position)
{
    return GetCoordEventScriptAtPosition(&gMapHeader, position->x - MAP_OFFSET, position->y - MAP_OFFSET, position->elevation);
}

static const struct BgEvent *GetBackgroundEventAtPosition(struct MapHeader *mapHeader, u16 x, u16 y, u8 elevation)
{
    u8 i;
    const struct BgEvent *bgEvents = mapHeader->events->bgEvents;
    u8 bgEventCount = mapHeader->events->bgEventCount;

    for (i = 0; i < bgEventCount; i++)
    {
        if ((u16)bgEvents[i].x == x && (u16)bgEvents[i].y == y)
        {
            if (bgEvents[i].elevation == elevation || bgEvents[i].elevation == ELEVATION_TRANSITION)
                return &bgEvents[i];
        }
    }
    return NULL;
}

bool8 TryDoDiveWarp(struct MapPosition *position, u16 metatileBehavior)
{
    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER && !MetatileBehavior_IsUnableToEmerge(metatileBehavior))
    {
        if (SetDiveWarpEmerge(position->x - MAP_OFFSET, position->y - MAP_OFFSET))
        {
            StoreInitialPlayerAvatarState();
            DoDiveWarp();
            PlaySE(SE_M_DIVE);
            return TRUE;
        }
    }
    else if (MetatileBehavior_IsDiveable(metatileBehavior) == TRUE)
    {
        if (SetDiveWarpDive(position->x - MAP_OFFSET, position->y - MAP_OFFSET))
        {
            StoreInitialPlayerAvatarState();
            DoDiveWarp();
            PlaySE(SE_M_DIVE);
            return TRUE;
        }
    }
    return FALSE;
}

u8 TrySetDiveWarp(void)
{
    s16 x, y;
    u8 metatileBehavior;

    PlayerGetDestCoords(&x, &y);
    metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER && !MetatileBehavior_IsUnableToEmerge(metatileBehavior))
    {
        if (SetDiveWarpEmerge(x - MAP_OFFSET, y - MAP_OFFSET) == TRUE)
            return 1;
    }
    else if (MetatileBehavior_IsDiveable(metatileBehavior) == TRUE)
    {
        if (SetDiveWarpDive(x - MAP_OFFSET, y - MAP_OFFSET) == TRUE)
            return 2;
    }
    return 0;
}

const u8 *GetObjectEventScriptPointerPlayerFacing(void)
{
    enum Direction direction;
    struct MapPosition position;

    direction = GetPlayerMovementDirection();
    GetInFrontOfPlayerPosition(&position);
    return GetInteractedObjectEventScript(&position, MapGridGetMetatileBehaviorAt(position.x, position.y), direction);
}

int SetCableClubWarp(void)
{
    struct MapPosition position;

    GetPlayerMovementDirection();  //unnecessary
    GetPlayerPosition(&position);
    MapGridGetMetatileBehaviorAt(position.x, position.y);  //unnecessary
    SetupWarp(&gMapHeader, GetWarpEventAtMapPosition(&gMapHeader, &position), &position);
    return 0;
}

static bool32 TrySetUpWalkIntoSignpostScript(struct MapPosition *position, u32 metatileBehavior, enum Direction playerDirection)
{
    const u8 *script;

    if ((JOY_HELD(DPAD_LEFT | DPAD_RIGHT)) || (playerDirection != DIR_NORTH))
        return FALSE;

    switch (GetFacingSignpostType(metatileBehavior, playerDirection))
    {
    case MB_POKEMON_CENTER_SIGN:
        SetUpWalkIntoSignScript(Common_EventScript_ShowPokemonCenterSign, playerDirection);
        return TRUE;
    case MB_POKEMART_SIGN:
        SetUpWalkIntoSignScript(Common_EventScript_ShowPokemartSign, playerDirection);
        return TRUE;
    case MB_SIGNPOST:
        script = GetSignpostScriptAtMapPosition(position);
        if (script == NULL)
            return FALSE;
        SetUpWalkIntoSignScript(script, playerDirection);
        return TRUE;
    default:
        return FALSE;
    }
}

static u32 GetFacingSignpostType(u16 metatileBehavior, enum Direction playerDirection)
{
    if (MetatileBehavior_IsPokemonCenterSign(metatileBehavior) == TRUE)
        return MB_POKEMON_CENTER_SIGN;
    if (MetatileBehavior_IsPokeMartSign(metatileBehavior) == TRUE)
        return MB_POKEMART_SIGN;
    if (MetatileBehavior_IsSignpost(metatileBehavior) == TRUE)
        return MB_SIGNPOST;

    return NOT_SIGNPOST;
}

static void SetMsgSignPostAndVarFacing(enum Direction playerDirection)
{
    gWalkAwayFromSignpostTimer = WALK_AWAY_SIGNPOST_FRAMES;
    gMsgBoxIsCancelable = TRUE;
    gMsgIsSignPost = TRUE;
    gSpecialVar_Facing = playerDirection;
}

static void SetUpWalkIntoSignScript(const u8 *script, enum Direction playerDirection)
{
    ScriptContext_SetupScript(script);
    SetMsgSignPostAndVarFacing(playerDirection);
}

static const u8 *GetSignpostScriptAtMapPosition(struct MapPosition *position)
{
    const struct BgEvent *event = GetBackgroundEventAtPosition(&gMapHeader, position->x - 7, position->y - 7, position->elevation);
    if (event == NULL)
        return NULL;
    if (event->bgUnion.script != NULL)
        return event->bgUnion.script;
    return EventScript_TestSignpostMsg;
}

static void Task_OpenStartMenu(u8 taskId)
{
    if (ArePlayerFieldControlsLocked())
        return;

    PlaySE(SE_WIN_OPEN);
    ShowStartMenu();
    DestroyTask(taskId);
}

bool32 IsDpadPushedToTurnOrMovePlayer(struct FieldInput *input)
{
    return (input->dpadDirection != 0 && GetPlayerFacingDirection() != input->dpadDirection);
}

void CancelSignPostMessageBox(struct FieldInput *input)
{
    if (!ScriptContext_IsEnabled())
        return;

    if (gWalkAwayFromSignpostTimer)
    {
        gWalkAwayFromSignpostTimer--;
        return;
    }

    if (!gMsgBoxIsCancelable)
        return;

    if (IsDpadPushedToTurnOrMovePlayer(input))
    {
        ScriptContext_SetupScript(EventScript_CancelMessageBox);
        LockPlayerFieldControls();
        return;
    }

    if (!input->pressedStartButton)
        return;

    ScriptContext_SetupScript(EventScript_CancelMessageBox);
    LockPlayerFieldControls();

    if (FuncIsActiveTask(Task_OpenStartMenu))
        return;

    CreateTask(Task_OpenStartMenu, 8);
}

u16 GetBoulderRevealFlagByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    // Pushable boulder object events store the flag to reveal the boulder
    // on the floor below in their trainer type field.
    return GetObjectEventTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->trainerType;
}

void HandleBoulderFallThroughHole(struct ObjectEvent * object)
{
    if (MapGridGetMetatileBehaviorAt(object->currentCoords.x, object->currentCoords.y) == MB_MT_PYRE_HOLE)
    {
        PlaySE(SE_FALL);
        RemoveObjectEventByLocalIdAndMap(object->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        FlagClear(GetBoulderRevealFlagByLocalIdAndMap(object->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup));
    }
}

void HandleBoulderActivateVictoryRoadSwitch(u16 x, u16 y)
{
    int i;
    const struct CoordEvent * events = gMapHeader.events->coordEvents;
    int n = gMapHeader.events->coordEventCount;

    if (MapGridGetMetatileBehaviorAt(x, y) == MB_STRENGTH_BUTTON)
    {
        for (i = 0; i < n; i++)
        {
            if (events[i].x + MAP_OFFSET == x && events[i].y + MAP_OFFSET == y)
            {
                ScriptContext_SetupScript(events[i].script);
                LockPlayerFieldControls();
            }
        }
    }
}
