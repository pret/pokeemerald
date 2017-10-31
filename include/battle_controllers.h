#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

enum
{
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

#define RESET_ACTION_MOVE_SELECTION     0
#define RESET_ACTION_SELECTION          1
#define RESET_MOVE_SELECTION            2

#define BALL_NO_SHAKES          0
#define BALL_1_SHAKE            1
#define BALL_2_SHAKES           2
#define BALL_3_SHAKES_FAIL      3
#define BALL_3_SHAKES_SUCCESS   4
#define BALL_TRAINER_BLOCK      5

#define RET_VALUE_LEVELLED_UP   11

#define INSTANT_HP_BAR_DROP     32767

struct UnusedControllerStruct
{
    u8 field_0 : 7;
    u8 flag_x80 : 1;
};

struct HpAndStatus
{
    u16 hp;
    u32 status;
};

struct MovePpInfo
{
    u16 moves[4];
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
    CONTROLLER_RETURNMONTOBALL,
    CONTROLLER_DRAWTRAINERPIC,
    CONTROLLER_TRAINERSLIDE,
    CONTROLLER_TRAINERSLIDEBACK,
    CONTROLLER_FAINTANIMATION,
    CONTROLLER_PALETTEFADE,
    CONTROLLER_SUCCESSBALLTHROWANIM,
    CONTROLLER_BALLTHROWANIM,
    CONTROLLER_PAUSE,
    CONTROLLER_MOVEANIMATION,
    CONTROLLER_PRINTSTRING,
    CONTROLLER_PRINTSTRINGPLAYERONLY,
    CONTROLLER_CHOOSEACTION,
    CONTROLLER_UNKNOWNYESNOBOX,
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
    CONTROLLER_31,
    CONTROLLER_32,
    CONTROLLER_TWORETURNVALUES,
    CONTROLLER_CHOSENMONRETURNVALUE,
    CONTROLLER_ONERETURNVALUE,
    CONTROLLER_ONERETURNVALUE_DUPLICATE,
    CONTROLLER_37,
    CONTROLLER_38,
    CONTROLLER_39,
    CONTROLLER_40,
    CONTROLLER_HITANIMATION,
    CONTROLLER_42,
    CONTROLLER_EFFECTIVENESSSOUND,
    CONTROLLER_PLAYFANFAREORBGM,
    CONTROLLER_FAINTINGCRY,
    CONTROLLER_INTROSLIDE,
    CONTROLLER_INTROTRAINERBALLTHROW,
    CONTROLLER_DRAWPARTYSTATUSSUMMARY,
    CONTROLLER_49,
    CONTROLLER_50,
    CONTROLLER_SPRITEINVISIBILITY,
    CONTROLLER_BATTLEANIMATION,
    CONTROLLER_LINKSTANDBYMSG,
    CONTROLLER_RESETACTIONMOVESELECTION,
    CONTROLLER_55,
    /*new controllers should go after 55 and before 56*/
    CONTROLLER_56,
    CONTROLLER_CMDS_COUNT
};


// general functions
void HandleLinkBattleSetup(void);
void SetUpBattleVarsAndBirchZigzagoon(void);
void sub_8032768(void);
void sub_8033648(void);
void PrepareBufferDataTransferLink(u8 bufferId, u16 size, u8 *data);

// emitters
void EmitGetMonData(u8 bufferId, u8 requestId, u8 monToCheck);
void EmitGetRawMonData(u8 bufferId, u8 monId, u8 bytes); // unused
void EmitSetMonData(u8 bufferId, u8 requestId, u8 monToCheck, u8 bytes, void *data);
void EmitSetRawMonData(u8 bufferId, u8 monId, u8 bytes, void *data); // unused
void EmitLoadMonSprite(u8 bufferId);
void EmitSwitchInAnim(u8 bufferId, u8 partyId, bool8 dontClearSubstituteBit);
void EmitReturnMonToBall(u8 bufferId, u8 arg1);
void EmitDrawTrainerPic(u8 bufferId);
void EmitTrainerSlide(u8 bufferId);
void EmitTrainerSlideBack(u8 bufferId);
void EmitFaintAnimation(u8 bufferId);
void EmitPaletteFade(u8 bufferId); // unused
void EmitSuccessBallThrowAnim(u8 bufferId); // unused
void EmitBallThrowAnim(u8 bufferId, u8 caseId);
void EmitPause(u8 bufferId, u8 toWait, void *data); // unused
void EmitMoveAnimation(u8 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct *disableStructPtr, u8 multihit);
void EmitPrintString(u8 bufferId, u16 stringId);
void EmitPrintStringPlayerOnly(u8 bufferId, u16 stringId);
void EmitChooseAction(u8 bufferId, u8 arg1, u16 arg2);
void EmitUnknownYesNoBox(u8 bufferId);
void EmitChooseMove(u8 bufferId, bool8 isDoubleBattle, bool8 NoPpNumber, struct ChooseMoveStruct *movePpData);
void EmitChooseItem(u8 bufferId, u8* arg1);
void EmitChoosePokemon(u8 bufferId, u8 caseId, u8 arg2, u8 abilityId, u8* arg4);
void EmitCmd23(u8 bufferId); // unused
void EmitHealthBarUpdate(u8 bufferId, u16 hpValue);
void EmitExpUpdate(u8 bufferId, u8 partyId, u16 expPoints);
void EmitStatusIconUpdate(u8 bufferId, u32 status1, u32 status2);
void EmitStatusAnimation(u8 bufferId, bool8 status2, u32 status);
void EmitStatusXor(u8 bufferId, u8 b); // unused
void EmitDataTransfer(u8 bufferId, u16 size, void *data);
void EmitDMA3Transfer(u8 bufferId, void *dst, u16 size, void *data); // unused
void EmitPlayBGM(u8 bufferId, u16 songId, void *unusedDumbDataParameter); // unused
void EmitCmd32(u8 bufferId, u16 size, void *c); // unused
void EmitTwoReturnValues(u8 bufferId, u8 arg1, u16 arg2);
void EmitChosenMonReturnValue(u8 bufferId, u8 b, u8 *c);
void EmitOneReturnValue(u8 bufferId, u16 arg1);
void EmitOneReturnValue_Duplicate(u8 bufferId, u16 b);
void EmitCmd37(u8 bufferId); // unused
void EmitCmd38(u8 bufferId, u8 b); // unused
void EmitCmd39(u8 bufferId); // unused
void EmitCmd40(u8 bufferId); // unused
void EmitHitAnimation(u8 bufferId);
void EmitCmd42(u8 bufferId);
void EmitEffectivenessSound(u8 bufferId, u16 songId);
void EmitPlayFanfareOrBGM(u8 bufferId, u16 songId, bool8 playBGM);
void EmitFaintingCry(u8 bufferId);
void EmitIntroSlide(u8 bufferId, u8 terrainId);
void EmitIntroTrainerBallThrow(u8 bufferId);
void EmitDrawPartyStatusSummary(u8 bufferId, struct HpAndStatus* hpAndStatus, u8 arg2);
void EmitCmd49(u8 bufferId);
void EmitCmd50(u8 bufferId);
void EmitSpriteInvisibility(u8 bufferId, bool8 isInvisible);
void EmitBattleAnimation(u8 bufferId, u8 animationId, u16 argument);
void EmitLinkStandbyMsg(u8 bufferId, u8 arg1, bool32 arg2);
void EmitResetActionMoveSelection(u8 bufferId, u8 caseId);
void EmitCmd55(u8 bufferId, u8 arg1);

// player controller
void SetControllerToPlayer(void);
void nullsub_21(void);
void PlayerHandleGetRawMonData(void);
void sub_80587B0(void);
void sub_805CC00(struct Sprite *sprite);
void SetCB2ToReshowScreenAfterMenu(void);
void SetCB2ToReshowScreenAfterMenu2(void);
void c3_0802FDF4(u8 taskId);
void ActionSelectionCreateCursorAt(u8 cursorPos, u8 unused);
void ActionSelectionDestroyCursorAt(u8 cursorPos);
void InitMoveSelectionsVarsAndStrings(void);

// recorded player controller
void SetControllerToRecordedPlayer(void);

// opponent controller
void SetControllerToOpponent(void);

// player partner controller
void SetControllerToPlayerPartner(void);

// safari controller
void SetControllerToSafari(void);

// wally controller
void SetControllerToWally(void);

// recorded opponent controller
void SetControllerToRecordedOpponent(void);

// link opponent
void SetControllerToLinkOpponent(void);

// link partner
void SetControllerToLinkPartner(void);

#endif // GUARD_BATTLE_CONTROLLERS_H
