#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

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

// rom3.s, emitters
void EmitSetMonData(u8 bufferId, u8 request, u8 c, u8 bytes, void *data);
void EmitMoveAnimation(u8 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct* disableStructPtr, u8 multihit);
void EmitHealthBarUpdate(u8 bufferId, u16 hpValue);
void EmitEffectivenessSound(u8 bufferId, u16 songId);
void EmitPlaySound(u8 bufferId, u16 songId, u8 arg2);
void EmitPrintStringPlayerOnly(u8 bufferId, u16 stringId);
void EmitFaintAnimation(u8 bufferId);
void Emit_x2A(u8 bufferId);
void EmitExpUpdate(u8 bufferId, u8 partyId, u16 expPoints);
void EmitBattleAnimation(u8 bufferId, u8 animationId, u16 argument);
void EmitSpriteInvisibility(u8 bufferId, bool8 isInvisible);
void EmitReturnPokeToBall(u8 bufferId, u8 arg1);
void EmitGetMonData(u8 bufferId, u8 arg1, u8 arg2);
void EmitSwitchInAnim(u8 bufferId, u8 partyId, bool8 dontClearSubstituteBit);
void EmitChoosePokemon(u8 bufferId, u8 caseId, u8 arg2, u8 abilityId, const u8* arg4);
void EmitLinkStandbyMsg(u8 bufferId, u8 arg1, u8 arg2);
void EmitTrainerSlide(u8 bufferId);
void EmitTrainerSlideBack(u8 bufferId);
void EmitFaintingCry(u8 bufferId);
void Emit_x37(u8 bufferId, u8 arg1);
void EmitHitAnimation(u8 bufferId);
void EmitCmd48(u8 bufferId, struct HpAndStatus* hpAndStatus, u8 arg2);
void EmitCmd49(u8 bufferId);
void EmitStatusAnimation(u8 bufferId, bool8 status2, u32 status);
void EmitCmd13(u8 bufferId);
void EmitStatusIconUpdate(u8 bufferId, u32 status1, u32 status2);

#define RESET_ACTION_MOVE_SELECTION     0
#define RESET_ACTION_SELECTION          1
#define RESET_MOVE_SELECTION            2

void EmitResetActionMoveSelection(u8 bufferId, u8 caseId);

#define BALL_NO_SHAKES          0
#define BALL_1_SHAKE            1
#define BALL_2_SHAKES           2
#define BALL_3_SHAKES_FAIL      3
#define BALL_3_SHAKES_SUCCESS   4
#define BALL_TRAINER_BLOCK      5

void EmitBallThrow(u8 bufferId, u8 caseId);

void MarkBufferBankForExecution(u8 bank);

#endif // GUARD_BATTLE_CONTROLLERS_H
