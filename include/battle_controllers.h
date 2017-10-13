#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

#define REQUEST_ALL_BATTLE      0x0
#define REQUEST_SPECIES_BATTLE  0x1
#define REQUEST_HELDITEM_BATTLE 0x2
#define REQUEST_MOVES_PP_BATTLE 0x3
#define REQUEST_PPMOVE1_BATTLE  0x9
#define REQUEST_PPMOVE2_BATTLE  0xA
#define REQUEST_PPMOVE3_BATTLE  0xB
#define REQUEST_PPMOVE4_BATTLE  0xC
#define REQUEST_STATUS_BATTLE   0x28
#define REQUEST_HP_BATTLE       0x2A

#define RESET_ACTION_MOVE_SELECTION     0
#define RESET_ACTION_SELECTION          1
#define RESET_MOVE_SELECTION            2

#define BALL_NO_SHAKES          0
#define BALL_1_SHAKE            1
#define BALL_2_SHAKES           2
#define BALL_3_SHAKES_FAIL      3
#define BALL_3_SHAKES_SUCCESS   4
#define BALL_TRAINER_BLOCK      5

struct HpAndStatus
{
    u16 hp;
    u32 status;
};

struct MovePpInfo
{
    u16 move[4];
    u8 pp[4];
    u8 ppBonuses;
};

struct ChooseMoveStruct
{
    u16 moves[4];
    u8 currentPp[4];
    u8 maxPp[4];
    u16 species;
    u8 monType1;
    u8 monType2;
};

enum
{
    CONTROLLER_GETMONDATA,
    CONTROLLER_GETRAWMONDATA,
    CONTROLLER_SETMONDATA,
    CONTROLLER_SETRAWMONDATA,
    CONTROLLER_LOADMONSPRITE,
    CONTROLLER_SWITCHINANIM,
    CONTROLLER_RETURNPOKETOBALL,
    CONTROLLER_DRAWTRAINERPIC,
    CONTROLLER_TRAINERSLIDE,
    CONTROLLER_TRAINERSLIDEBACK,
    CONTROLLER_FAINTANIMATION,
    CONTROLLER_11,
    CONTROLLER_12,
    CONTROLLER_BALLTHROW,
    CONTROLLER_PAUSE,
    CONTROLLER_MOVEANIMATION,
    CONTROLLER_PRINTSTRING,
    CONTROLLER_PRINTSTRINGPLAYERONLY,
    CONTROLLER_CHOOSEACTION,
    CONTROLLER_19,
    CONTROLLER_20,
    CONTROLLER_OPENBAG,
    CONTROLLER_22,
    CONTROLLER_23,
    CONTROLLER_HEALTHBARUPDATE,
    CONTROLLER_EXPBARUPDATE,
    CONTROLLER_STATUSICONUPDATE,
    CONTROLLER_STATUSANIMATION,
    CONTROLLER_STATUSXOR,
    CONTROLLER_29,
    CONTROLLER_DMATRANSFER,
    CONTROLLER_31,
    CONTROLLER_32,
    CONTROLLER_33,
    CONTROLLER_34,
    CONTROLLER_35,
    CONTROLLER_36,
    CONTROLLER_37,
    CONTROLLER_38,
    CONTROLLER_39,
    CONTROLLER_40,
    CONTROLLER_HITANIMATION,
    CONTROLLER_42,
    CONTROLLER_EFFECTIVENESSSOUND,
    CONTROLLER_44,
    CONTROLLER_FAINTINGCRY,
    CONTROLLER_INTROSLIDE,
    CONTROLLER_TRAINERBALLTHROW,
    CONTROLLER_48,
    CONTROLLER_49,
    CONTROLLER_50,
    CONTROLLER_SPRITEINVISIBILITY,
    CONTROLLER_BATTLEANIMATION,
    CONTROLLER_LINKSTANDBYMSG,
    CONTROLLER_RESETACTIONMOVESELECTION,
    CONTROLLER_55,
    CONTROLLER_56
};

#define LAST_CONTROLLER_CMD_ID CONTROLLER_56 + 1

// general functions
void HandleLinkBattleSetup(void);
void SetUpBattleVarsAndBirchZigzagoon(void);
void sub_8032768(void);
void sub_8033648(void);

// emitters
void EmitGetMonData(u8 bufferId, u8 arg1, u8 arg2);
void EmitGetRawMonData(u8 bufferId, u8 monId, u8 bytes); // unused
void EmitSetMonData(u8 bufferId, u8 request, u8 c, u8 bytes, void *data);
void EmitSetRawMonData(u8 bufferId, u8 monId, u8 bytes, void *data); // unused
void EmitLoadMonSprite(u8 bufferId);
void EmitSwitchInAnim(u8 bufferId, u8 partyId, bool8 dontClearSubstituteBit);
void EmitReturnPokeToBall(u8 bufferId, u8 arg1);
void EmitDrawTrainerPic(u8 bufferId);
void EmitTrainerSlide(u8 bufferId);
void EmitTrainerSlideBack(u8 bufferId);
void EmitFaintAnimation(u8 bufferId);
void EmitCmd11(u8 bufferId); // unused
void EmitCmd12(u8 bufferId); // unused
void EmitBallThrow(u8 bufferId, u8 caseId);
void EmitPause(u8 bufferId, u8 toWait, void *data); // unused
void EmitMoveAnimation(u8 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct *disableStructPtr, u8 multihit);
void EmitPrintString(u8 bufferId, u16 stringId);
void EmitPrintStringPlayerOnly(u8 bufferId, u16 stringId);
void EmitChooseAction(u8 bufferId, u8 arg1, u16 arg2);


void EmitHealthBarUpdate(u8 bufferId, u16 hpValue);
void EmitEffectivenessSound(u8 bufferId, u16 songId);
void EmitPlaySound(u8 bufferId, u16 songId, u8 arg2);
void Emit_x2A(u8 bufferId);
void EmitExpUpdate(u8 bufferId, u8 partyId, u16 expPoints);
void EmitBattleAnimation(u8 bufferId, u8 animationId, u16 argument);
void EmitSpriteInvisibility(u8 bufferId, bool8 isInvisible);
void EmitChoosePokemon(u8 bufferId, u8 caseId, u8 arg2, u8 abilityId, u8* arg4);
void EmitLinkStandbyMsg(u8 bufferId, u8 arg1, bool32 arg2);
void EmitFaintingCry(u8 bufferId);
void Emit_x37(u8 bufferId, u8 arg1);
void EmitHitAnimation(u8 bufferId);
void EmitDrawPartyStatusSummary(u8 bufferId, struct HpAndStatus* hpAndStatus, u8 arg2);
void EmitCmd49(u8 bufferId);
void EmitStatusAnimation(u8 bufferId, bool8 status2, u32 status);
void EmitCmd13(u8 bufferId);
void EmitStatusIconUpdate(u8 bufferId, u32 status1, u32 status2);
void EmitIntroSlide(u8 bufferId, u8 terrainId);
void EmitIntroTrainerBallThrow(u8 bufferId);
void EmitChooseMove(u8 bufferId, bool8 isDoubleBattle, bool8 NoPpNumber, struct ChooseMoveStruct* movePpData);
void EmitOpenBag(u8 bufferId, u8* arg1);
void Emit_x32(u8 bufferId);

void EmitResetActionMoveSelection(u8 bufferId, u8 caseId);
void EmitCmd_x21(u8 bufferId, u8 arg1, u16 arg2);

// player controller
void SetBankFuncToPlayerBufferRunCommand(void);
void nullsub_21(void);
void ActionSelectionCreateCursorAt(u8 cursorPos, u8 unused);
void ActionSelectionDestroyCursorAt(u8 cursorPos);

// recorded player controller
void SetBankFuncToRecordedPlayerBufferRunCommand(void);

// opponent controller
void SetBankFuncToOpponentBufferRunCommand(void);

// player partner controller
void SetBankFuncToPlayerPartnerBufferRunCommand(void);

// safari controller
void SetBankFuncToSafariBufferRunCommand(void);

// wally controller
void SetBankFuncToWallyBufferRunCommand(void);

// recorded opponent controller
void SetBankFuncToRecordedOpponentBufferRunCommand(void);

// link opponent
void SetBankFuncToLinkOpponentBufferRunCommand(void);

// link partner
void SetBankFuncToLinkPartnerBufferRunCommand(void);

#endif // GUARD_BATTLE_CONTROLLERS_H
