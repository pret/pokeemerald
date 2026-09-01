#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

typedef void (*BattleControllerFunc)(enum BattlerId battler);

enum {
    REQUEST_ALL_BATTLE,
    REQUEST_SPECIES_BATTLE,
    REQUEST_HELDITEM_BATTLE,
    REQUEST_MOVES_PP_BATTLE,
    REQUEST_MOVE1_BATTLE,
    REQUEST_MOVE2_BATTLE,
    REQUEST_MOVE3_BATTLE,
    REQUEST_MOVE4_BATTLE,
    REQUEST_PP_DATA_BATTLE,
    REQUEST_PPMOVE1_BATTLE,
    REQUEST_PPMOVE2_BATTLE,
    REQUEST_PPMOVE3_BATTLE,
    REQUEST_PPMOVE4_BATTLE,
    REQUEST_UNUSED_13_BATTLE,
    REQUEST_UNUSED_14_BATTLE,
    REQUEST_UNUSED_15_BATTLE,
    REQUEST_UNUSED_16_BATTLE,
    REQUEST_OTID_BATTLE,
    REQUEST_EXP_BATTLE,
    REQUEST_HP_EV_BATTLE,
    REQUEST_ATK_EV_BATTLE,
    REQUEST_DEF_EV_BATTLE,
    REQUEST_SPEED_EV_BATTLE,
    REQUEST_SPATK_EV_BATTLE,
    REQUEST_SPDEF_EV_BATTLE,
    REQUEST_FRIENDSHIP_BATTLE,
    REQUEST_POKERUS_BATTLE,
    REQUEST_MET_LOCATION_BATTLE,
    REQUEST_MET_LEVEL_BATTLE,
    REQUEST_MET_GAME_BATTLE,
    REQUEST_POKEBALL_BATTLE,
    REQUEST_ALL_IVS_BATTLE,
    REQUEST_HP_IV_BATTLE,
    REQUEST_ATK_IV_BATTLE,
    REQUEST_DEF_IV_BATTLE,
    REQUEST_SPEED_IV_BATTLE,
    REQUEST_SPATK_IV_BATTLE,
    REQUEST_SPDEF_IV_BATTLE,
    REQUEST_PERSONALITY_BATTLE,
    REQUEST_CHECKSUM_BATTLE,
    REQUEST_STATUS_BATTLE,
    REQUEST_LEVEL_BATTLE,
    REQUEST_HP_BATTLE,
    REQUEST_MAX_HP_BATTLE,
    REQUEST_ATK_BATTLE,
    REQUEST_DEF_BATTLE,
    REQUEST_SPEED_BATTLE,
    REQUEST_SPATK_BATTLE,
    REQUEST_SPDEF_BATTLE,
    REQUEST_COOL_BATTLE,
    REQUEST_BEAUTY_BATTLE,
    REQUEST_CUTE_BATTLE,
    REQUEST_SMART_BATTLE,
    REQUEST_TOUGH_BATTLE,
    REQUEST_SHEEN_BATTLE,
    REQUEST_COOL_RIBBON_BATTLE,
    REQUEST_BEAUTY_RIBBON_BATTLE,
    REQUEST_CUTE_RIBBON_BATTLE,
    REQUEST_SMART_RIBBON_BATTLE,
    REQUEST_TOUGH_RIBBON_BATTLE,
};

enum BattleController
{
    BATTLE_CONTROLLER_NONE,
    BATTLE_CONTROLLER_PLAYER,
    BATTLE_CONTROLLER_PLAYER_PARTNER,
    BATTLE_CONTROLLER_OPPONENT,
    BATTLE_CONTROLLER_LINK_PARTNER,
    BATTLE_CONTROLLER_LINK_OPPONENT,
    BATTLE_CONTROLLER_SAFARI,
    BATTLE_CONTROLLER_WALLY,
    BATTLE_CONTROLLER_RECORDED_PLAYER,
    BATTLE_CONTROLLER_RECORDED_PARTNER,
    BATTLE_CONTROLLER_RECORDED_OPPONENT,
    BATTLE_CONTROLLER_OAK_OLD_MAN,
    BATTLE_CONTROLLERS_COUNT,
};

// Accessors for gBattleControllerExecFlags.
//
// These are provided for documentation purposes, to make the battle
// controller internals and the link communication internals more
// legible. Several of these have functions that you should call
// (e.g. MarkBattlerForControllerExec) instead of using these macros
// directly.

static inline void MarkBattleControllerActiveOnLocal(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    gBattleControllerExecFlags |= (1u << battler);
}

static inline void MarkBattleControllerIdleOnLocal(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    gBattleControllerExecFlags &= ~(1u << battler);
}

static inline bool32 IsBattleControllerActiveOnLocal(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    return gBattleControllerExecFlags & (1u << battler);
}

static inline void MarkBattleControllerMessageOutboundOverLink(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    gBattleControllerExecFlags |= ((1u << battler) << (32 - MAX_BATTLERS_COUNT));
}

static inline void MarkBattleControllerMessageSynchronizedOverLink(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    gBattleControllerExecFlags &= ~((1 << 28) << (battler));
}

static inline bool32 IsBattleControllerMessageSynchronizedOverLink(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    return gBattleControllerExecFlags & (1u << (battler + 28));
}

static inline void MarkBattleControllerActiveForPlayer(enum BattlerId battler, u32 playerId)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    gBattleControllerExecFlags |= ((1u << battler) << ((playerId) << 2));
}

static inline void MarkBattleControllerIdleForPlayer(enum BattlerId battler, u32 playerId)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    gBattleControllerExecFlags &= ~((1u << battler) << ((playerId) * 4));
}

static inline bool32 IsBattleControllerActiveForPlayer(enum BattlerId battler, u32 playerId)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
    return gBattleControllerExecFlags & ((1u << battler) << ((playerId) * 4));
}

// This actually checks if a specific controller is active on any player or if
// *any* controller is pending sync over link communications, but the macro name
// can only be so specific before it just gets ridiculous.
static inline bool32 IsBattleControllerActiveOrPendingSyncAnywhere(enum BattlerId battler)
{
    assertf(battler < MAX_BATTLERS_COUNT, "illegal battle controller: %d", battler);
   return gBattleControllerExecFlags & (
                  (1u << battler)
                | (0xF << 28)
                | (1u << battler << 4)
                | (1u << battler << 8)
                | (1u << battler << 12));
}

// Special arguments for Battle Controller functions.

enum {
   // For commands sent from the core battle engine to a controller.
   B_COMM_TO_CONTROLLER, // gBattleBufferA

   // For replies sent from a controller to the core battle engine.
   B_COMM_TO_ENGINE, // gBattleBufferB

   // During local play, a controller must directly mark itself as
   // inactive when it's done processing, whether or not it sends
   // a reply. During multiplayer, it must NOT directly mark itself
   // as inactive, but instead send one of these, with the player's
   // multiplayer ID as data.
   B_COMM_CONTROLLER_IS_DONE
};

enum {
    RESET_ACTION_MOVE_SELECTION,
    RESET_ACTION_SELECTION,
    RESET_MOVE_SELECTION,
};

enum {
    BALL_NO_SHAKES,
    BALL_1_SHAKE,
    BALL_2_SHAKES,
    BALL_3_SHAKES_FAIL,
    BALL_3_SHAKES_SUCCESS,
    BALL_TRAINER_BLOCK,
    BALL_GHOST_DODGE,
};

enum {
    LINK_STANDBY_MSG_STOP_BOUNCE,
    LINK_STANDBY_STOP_BOUNCE_ONLY,
    LINK_STANDBY_MSG_ONLY,
};

#define INSTANT_HP_BAR_DROP     0x7FFF

#define PARTY_SUMM_SKIP_DRAW_DELAY (1 << 7)

// Special return values in gBattleBufferB from Battle Controller functions.
#define RET_VALUE_LEVELED_UP   11
#define RET_GIMMICK            (1 << 7)

struct UnusedControllerStruct
{
    u8 unk:7;
    u8 flag:1;
};

struct HpAndStatus
{
    u16 hp;
    u32 status;
};

struct MovePPInfo
{
    enum Move moves[MAX_MON_MOVES];
    u8 pp[MAX_MON_MOVES];
    u8 ppBonuses;
};

struct ChooseMoveStruct
{
    enum Move moves[MAX_MON_MOVES];
    u8 currentPP[MAX_MON_MOVES];
    u8 maxPP[MAX_MON_MOVES];
    enum Species species;
    enum Type monTypes[3];
    struct ZMoveData zmove;
};

enum
{
    CONTROLLER_GETMONDATA,
    CONTROLLER_GETRAWMONDATA,
    CONTROLLER_SETMONDATA,
    CONTROLLER_SETRAWMONDATA,
    CONTROLLER_LOADMONSPRITE,
    CONTROLLER_SWITCHINANIM,
    CONTROLLER_RETURNMONTOBALL,
    CONTROLLER_DRAWTRAINERPIC,
    CONTROLLER_TRAINERSLIDE,
    CONTROLLER_TRAINERSLIDEBACK,
    CONTROLLER_FAINTANIMATION,
    CONTROLLER_PALETTEFADE,
    CONTROLLER_BALLTHROWANIM,
    CONTROLLER_PAUSE,
    CONTROLLER_MOVEANIMATION,
    CONTROLLER_PRINTSTRING,
    CONTROLLER_PRINTSTRINGPLAYERONLY,
    CONTROLLER_CHOOSEACTION,
    CONTROLLER_YESNOBOX,
    CONTROLLER_CHOOSEMOVE,
    CONTROLLER_OPENBAG,
    CONTROLLER_CHOOSEPOKEMON,
    CONTROLLER_23,
    CONTROLLER_HEALTHBARUPDATE,
    CONTROLLER_EXPUPDATE,
    CONTROLLER_STATUSICONUPDATE,
    CONTROLLER_STATUSANIMATION,
    CONTROLLER_STATUSXOR,
    CONTROLLER_DATATRANSFER,
    CONTROLLER_DMA3TRANSFER,
    CONTROLLER_PLAYBGM,
    CONTROLLER_32,
    CONTROLLER_TWORETURNVALUES,
    CONTROLLER_CHOSENMONRETURNVALUE,
    CONTROLLER_ONERETURNVALUE,
    CONTROLLER_ONERETURNVALUE_DUPLICATE,
    CONTROLLER_HITANIMATION,
    CONTROLLER_CANTSWITCH,
    CONTROLLER_PLAYSE,
    CONTROLLER_PLAYFANFAREORBGM,
    CONTROLLER_FAINTINGCRY,
    CONTROLLER_INTROSLIDE,
    CONTROLLER_INTROTRAINERBALLTHROW,
    CONTROLLER_DRAWPARTYSTATUSSUMMARY,
    CONTROLLER_HIDEPARTYSTATUSSUMMARY,
    CONTROLLER_ENDBOUNCE,
    CONTROLLER_SPRITEINVISIBILITY,
    CONTROLLER_BATTLEANIMATION,
    CONTROLLER_LINKSTANDBYMSG,
    CONTROLLER_RESETACTIONMOVESELECTION,
    CONTROLLER_ENDLINKBATTLE,
    CONTROLLER_DEBUGMENU,
    /*new controllers should go here*/
    CONTROLLER_TERMINATOR_NOP,
    CONTROLLER_CMDS_COUNT
};

extern struct UnusedControllerStruct gUnusedControllerStruct;
extern void (*gBattlerControllerFuncs[MAX_BATTLERS_COUNT])(enum BattlerId battler);
extern void (*gBattlerControllerEndFuncs[MAX_BATTLERS_COUNT])(enum BattlerId battler);
extern u8 gBattleControllerData[MAX_BATTLERS_COUNT];
extern u8 gBattlerBattleController[MAX_BATTLERS_COUNT];

// general functions
void HandleLinkBattleSetup(void);
void SetUpBattleVarsAndBirchZigzagoon(void);
void InitBattleControllers(void);
bool32 IsValidForBattle(struct Pokemon *mon);
void TryReceiveLinkBattleData(void);
void PrepareBufferDataTransferLink(enum BattlerId battler, u32 bufferId, u16 size, u8 *data);
void UpdateFriendshipFromXItem(enum BattlerId battler);
bool32 IsAiVsAiBattle(void);
bool32 BattlerIsPlayer(enum BattlerId battlerId);
bool32 BattlerIsPartner(enum BattlerId battlerId);
bool32 BattlerIsOpponent(enum BattlerId battlerId);
bool32 BattlerIsRecorded(enum BattlerId battlerId);
bool32 BattlerIsLink(enum BattlerId battlerId);
bool32 BattlerIsWally(enum BattlerId battlerId);
bool32 BattlerHasAi(enum BattlerId battlerId);

// emitters
void BtlController_EmitGetMonData(enum BattlerId battler, u32 bufferId, u8 requestId, u8 monToCheck);
void BtlController_EmitSetMonData(enum BattlerId battler, u32 bufferId, u8 requestId, u8 monToCheck, u8 bytes, void *data);
void BtlController_EmitLoadMonSprite(enum BattlerId battler, u32 bufferId);
void BtlController_EmitSwitchInAnim(enum BattlerId battler, u32 bufferId, u8 partyId, bool8 dontClearTransform, bool8 dontClearSubstituteBit);
void BtlController_EmitReturnMonToBall(enum BattlerId battler, u32 bufferId, bool8 skipAnim);
void BtlController_EmitDrawTrainerPic(enum BattlerId battler, u32 bufferId);
void BtlController_EmitTrainerSlide(enum BattlerId battler, u32 bufferId);
void BtlController_EmitTrainerSlideBack(enum BattlerId battler, u32 bufferId);
void BtlController_EmitFaintAnimation(enum BattlerId battler, u32 bufferId);
void BtlController_EmitBallThrowAnim(enum BattlerId battler, u32 bufferId, u8 caseId);
void BtlController_EmitMoveAnimation(enum BattlerId battler, u32 bufferId, enum Move move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, u8 multihit);
void BtlController_EmitPrintString(enum BattlerId battler, u32 bufferId, enum StringID stringId);
void BtlController_EmitPrintSelectionString(enum BattlerId battler, u32 bufferId, enum StringID stringId);
void BtlController_EmitChooseAction(enum BattlerId battler, u32 bufferId, u8 action, enum Item itemId);
void BtlController_EmitYesNoBox(enum BattlerId battler, u32 bufferId);
void BtlController_EmitChooseMove(enum BattlerId battler, u32 bufferId, bool8 isDoubleBattle, bool8 noPPNumber, struct ChooseMoveStruct *movePPData);
void BtlController_EmitChooseItem(enum BattlerId battler, u32 bufferId, u8 *battlePartyOrder);
void BtlController_EmitChoosePokemon(enum BattlerId battler, u32 bufferId, u8 caseId, u8 slotId, enum Ability abilityId, enum BattlerId battlerPreventingSwitchout, u8 *data);
void BtlController_EmitHealthBarUpdate(enum BattlerId battler, u32 bufferId, u16 hpValue);
void BtlController_EmitExpUpdate(enum BattlerId battler, u32 bufferId, u8 partyId, s32 expPoints);
void BtlController_EmitStatusIconUpdate(enum BattlerId battler, u32 bufferId, u32 status);
void BtlController_EmitStatusAnimation(enum BattlerId battler, u32 bufferId, bool8 isVolatile, u32 status);
void BtlController_EmitDataTransfer(enum BattlerId battler, u32 bufferId, u16 size, void *data);
void BtlController_EmitTwoReturnValues(enum BattlerId battler, u32 bufferId, u8 ret8, u32 ret32);
void BtlController_EmitChosenMonReturnValue(enum BattlerId battler, u32 bufferId, u8 partyId, u8 *battlePartyOrder);
void BtlController_EmitOneReturnValue(enum BattlerId battler, u32 bufferId, u16 ret);
void BtlController_EmitOneReturnValue_Duplicate(enum BattlerId battler, u32 bufferId, u16 ret);
void BtlController_EmitHitAnimation(enum BattlerId battler, u32 bufferId);
void BtlController_EmitCantSwitch(enum BattlerId battler, u32 bufferId);
void BtlController_EmitPlaySE(enum BattlerId battler, u32 bufferId, u16 songId);
void BtlController_EmitPlayFanfareOrBGM(enum BattlerId battler, u32 bufferId, u16 songId, bool8 playBGM);
void BtlController_EmitFaintingCry(enum BattlerId battler, u32 bufferId);
void BtlController_EmitIntroSlide(enum BattlerId battler, u32 bufferId, u8 terrainId);
void BtlController_EmitIntroTrainerBallThrow(enum BattlerId battler, u32 bufferId);
void BtlController_EmitDrawPartyStatusSummary(enum BattlerId battler, u32 bufferId, struct HpAndStatus *hpAndStatus, u8 flags);
void BtlController_EmitHidePartyStatusSummary(enum BattlerId battler, u32 bufferId);
void BtlController_EmitEndBounceEffect(enum BattlerId battler, u32 bufferId);
void BtlController_EmitSpriteInvisibility(enum BattlerId battler, u32 bufferId, bool8 isInvisible);
void BtlController_EmitBattleAnimation(enum BattlerId battler, u32 bufferId, u8 animationId, u16 argument);
void BtlController_EmitLinkStandbyMsg(enum BattlerId battler, u32 bufferId, u8 mode, bool32 record);
void BtlController_EmitResetActionMoveSelection(enum BattlerId battler, u32 bufferId, u8 caseId);
void BtlController_EmitEndLinkBattle(enum BattlerId battler, u32 bufferId, u8 battleOutcome);
void BtlController_EmitDebugMenu(enum BattlerId battler, u32 bufferId);

void BtlController_Complete(enum BattlerId battler); // Can be used for all the controllers.
void BtlController_Empty(enum BattlerId battler); // Empty command, does nothing, only completes the execution.
void BtlController_TerminatorNop(enum BattlerId battler); // Dummy function at the end of the table.
void BattleControllerDummy(enum BattlerId battler);
void StartSendOutAnim(enum BattlerId battler, bool32 dontClearTransform, bool32 dontClearSubstituteBit, bool32 doSlideIn);
void Controller_WaitForString(enum BattlerId battler);
void Controller_WaitForHealthBar(enum BattlerId battler);

// handlers
void BtlController_HandleGetMonData(enum BattlerId battler);
void BtlController_HandleGetRawMonData(enum BattlerId battler);
void BtlController_HandleSetMonData(enum BattlerId battler);
void BtlController_HandleSetRawMonData(enum BattlerId battler);
void BtlController_HandleLoadMonSprite(enum BattlerId battler);
void BtlController_HandleSwitchInAnim(enum BattlerId battler);
void BtlController_HandleReturnMonToBall(enum BattlerId battler);
void BtlController_HandleDrawTrainerPic(enum BattlerId battlerId, enum TrainerPicID trainerPicId, bool32 isFrontPic, s16 xPos, s16 yPos, s32 subpriority);
void BtlController_HandleTrainerSlide(enum BattlerId battler, enum TrainerPicID trainerPicId);
void BtlController_HandleTrainerSlideBack(enum BattlerId battlerId, s16 data0, bool32 startAnim);
void BtlController_HandleFaintAnimation(enum BattlerId battler);
void BtlController_HandleBallThrowAnim(enum BattlerId battler);
void BtlController_HandleMoveAnimation(enum BattlerId battler);
void BtlController_HandlePrintString(enum BattlerId battler);
void BtlController_HandlePrintStringPlayerOnly(enum BattlerId battler);
void BtlController_HandleHealthBarUpdate(enum BattlerId battler);
void BtlController_HandleStatusIconUpdate(enum BattlerId battler);
void BtlController_HandleStatusAnimation(enum BattlerId battler);
void BtlController_HandleHitAnimation(enum BattlerId battler);
void BtlController_HandlePlaySE(enum BattlerId battler);
void BtlController_HandlePlayFanfareOrBGM(enum BattlerId battler);
void BtlController_HandleFaintingCry(enum BattlerId battler);
void BtlController_HandleIntroSlide(enum BattlerId battler);
void BtlController_HandleSpriteInvisibility(enum BattlerId battler);
bool32 TwoPlayerIntroMons(enum BattlerId battlerId); // Double battle with both player Pokémon active.
bool32 TwoOpponentIntroMons(enum BattlerId battlerId); // Double battle with both opponent Pokémon active.
void BtlController_HandleIntroTrainerBallThrow(enum BattlerId battler, u16 tagTrainerPal, const u16 *trainerPal, s16 framesToWait, void (*controllerCallback)(enum BattlerId battler));
void BtlController_HandleDrawPartyStatusSummary(enum BattlerId battler, enum BattleSide side, bool32 considerDelay);
void BtlController_HandleHidePartyStatusSummary(enum BattlerId battler);
void BtlController_HandleBattleAnimation(enum BattlerId battler);

// player controller
void SetControllerToPlayer(enum BattlerId battler);
void PlayerBufferExecCompleted(enum BattlerId battler);
void SetBattleEndCallbacks(enum BattlerId battler);
void PlayerHandleExpUpdate(enum BattlerId battler);
enum TrainerPicID LinkPlayerGetTrainerPicId(u32 multiplayerId);
void CB2_SetUpReshowBattleScreenAfterMenu(void);
void CB2_SetUpReshowBattleScreenAfterMenu2(void);
void Task_PlayerController_RestoreBgmAfterCry(u8 taskId);
void ActionSelectionCreateCursorAt(u8 cursorPosition, u8 baseTileNum);
void ActionSelectionDestroyCursorAt(u8 cursorPosition);
void InitMoveSelectionsVarsAndStrings(enum BattlerId battler);
void MoveSelectionCreateCursorAt(u8 cursorPos, u8 arg1);
void MoveSelectionDestroyCursorAt(u8 cursorPosition);
void PlayerHandleChooseMove(enum BattlerId battler);
void HandleInputChooseMove(enum BattlerId battler);
void HandleInputChooseTarget(enum BattlerId battler);
void HandleInputShowEntireFieldTargets(enum BattlerId battler);
void HandleInputShowTargets(enum BattlerId battler);
void HandleMoveSwitching(enum BattlerId battler);
void HandleChooseMoveAfterDma3(enum BattlerId battler);

// recorded player controller
void SetControllerToRecordedPlayer(enum BattlerId battler);
void RecordedPlayerBufferExecCompleted(enum BattlerId battler);

// recorded partner controller
void SetControllerToRecordedPartner(enum BattlerId battler);
void RecordedPartnerBufferExecCompleted(enum BattlerId battler);

// opponent controller
void SetControllerToOpponent(enum BattlerId battler);
void OpponentBufferExecCompleted(enum BattlerId battler);
void OpponentHandleTrainerSlide(enum BattlerId battler);

// player partner controller
void Controller_PlayerPartnerShowIntroHealthbox(enum BattlerId battler); // Also used by the link partner.
void SetControllerToPlayerPartner(enum BattlerId battler);
void PlayerPartnerBufferExecCompleted(enum BattlerId battler);

// safari controller
void SetControllerToSafari(enum BattlerId battler);
void SafariBufferExecCompleted(enum BattlerId battler);

// wally controller
void SetControllerToWally(enum BattlerId battler);
void WallyBufferExecCompleted(enum BattlerId battler);

// recorded opponent controller
void SetControllerToRecordedOpponent(enum BattlerId battler);
void RecordedOpponentBufferExecCompleted(enum BattlerId battler);

// link opponent
void SetControllerToLinkOpponent(enum BattlerId battler);
void LinkOpponentBufferExecCompleted(enum BattlerId battler);

// link partner
void SetControllerToLinkPartner(enum BattlerId battler);
void LinkPartnerBufferExecCompleted(enum BattlerId battler);

void TrySetBattlerShadowSpriteCallback(enum BattlerId battler);

void AnimateMonAfterPokeBallFail(enum BattlerId battler);
void TryShinyAnimAfterMonAnim(enum BattlerId battler);
void WaitForMonAnimAfterLoad(enum BattlerId battler);
void BtlController_HandleSwitchInWaitAndEnd(enum BattlerId battler);
void BtlController_Intro_DelayAndEnd(enum BattlerId battler);
void BtlController_HandleSwitchInShowHealthbox(enum BattlerId battler);
void BtlController_HandleSwitchInTryShinyAnim(enum BattlerId battler);
void BtlController_HandleSwitchInSoundAndEnd(enum BattlerId battler);
void BtlController_HandleSwitchInShowSubstitute(enum BattlerId battler);

// oak and old man controller
void SetControllerToOakOrOldMan(enum BattlerId battler);
void OakOldManBufferExecCompleted(enum BattlerId battler);

// These flags are set to signal that the indicated message
// was already emitted

// Inflicting damage is key
#define FIRST_BATTLE_MSG_FLAG_INFLICT_DMG    0x1
// Lowering stats is advantageous
#define FIRST_BATTLE_MSG_FLAG_STAT_CHG       0x2
// Keep an eye on your HP
#define FIRST_BATTLE_MSG_FLAG_HP_RESTORE     0x4
//
#define FIRST_BATTLE_MSG_FLAG_PARTY_MENU     0x8

bool8 BtlCtrl_OakOldMan_TestState2Flag(u8 mask);
void BtlCtrl_OakOldMan_SetState2Flag(u8 mask);
void PrintOakText_InflictingDamageIsKey(enum BattlerId battler);
void PrintOakText_HowDisappointing(enum BattlerId battler);
void PrintOakText_OakNoRunningFromATrainer(enum BattlerId battler);
void OakOldManHandleInputChooseMove(enum BattlerId battler);
void BtlCtrl_DrawVoiceoverMessageFrame(void);
void BtlCtrl_RemoveVoiceoverMessageFrame(void);

bool32 ShouldBattleRestrictionsApply(enum BattlerId battler);
void FreeShinyStars(void);
enum BattleTrainer GetBattlerTrainer(enum BattlerId battler);
enum BattleTrainer GetTrainerFromBattlePosition(enum BattlerPosition position);
bool32 BattleSideHasTwoTrainers(enum BattleSide side);
bool32 BattlersShareParty(enum BattlerId battler1, enum BattlerId battler2);
bool32 TrainerHasParty(enum BattleTrainer trainer);
void SetFinalChosenTarget(enum BattlerId battler, bool32 checkPartner);


// oak and old man controller
void SetControllerToOakOrOldMan(enum BattlerId battler);
void OakOldManBufferExecCompleted(enum BattlerId battler);

// These flags are set to signal that the indicated message
// was already emitted

// Inflicting damage is key
#define FIRST_BATTLE_MSG_FLAG_INFLICT_DMG    0x1
// Lowering stats is advantageous
#define FIRST_BATTLE_MSG_FLAG_STAT_CHG       0x2
// Keep an eye on your HP
#define FIRST_BATTLE_MSG_FLAG_HP_RESTORE     0x4
//
#define FIRST_BATTLE_MSG_FLAG_PARTY_MENU     0x8

bool8 BtlCtrl_OakOldMan_TestState2Flag(u8 mask);
void BtlCtrl_OakOldMan_SetState2Flag(u8 mask);
void PrintOakText_InflictingDamageIsKey(enum BattlerId battler);
void PrintOakText_HowDisappointing(enum BattlerId battler);
void PrintOakText_OakNoRunningFromATrainer(enum BattlerId battler);
void OakOldManHandleInputChooseMove(enum BattlerId battler);
void BtlCtrl_DrawVoiceoverMessageFrame(void);
void BtlCtrl_RemoveVoiceoverMessageFrame(void);

#endif // GUARD_BATTLE_CONTROLLERS_H
