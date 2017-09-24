#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

struct HpAndStatus
{
    u16 hp;
    u32 status;
};

// rom3.s, emitters
void EmitSetAttributes(u8 bufferId, u8 request, u8 c, u8 bytes, void *data);
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
void EmitGetAttributes(u8 bufferId, u8 arg1, u8 arg2);
void EmitSwitchInAnim(u8 bufferId, u8 partyId, bool8 dontClearSubstituteBit);
void EmitChoosePokemon(u8 bufferId, u8 caseId, u8 arg2, u8 abilityId, const u8* arg4);
void EmitLinkStandbyMsg(u8 bufferId, u8 arg1, u8 arg2);
void EmitTrainerSlide(u8 bufferId);
void EmitFaintingCry(u8 bufferId);
void Emit_x37(u8 bufferId, u8 arg1);
void EmitHitAnimation(u8 bufferId);
void EmitCmd48(u8 bufferId, struct HpAndStatus* hpAndStatus, u8 arg2);
void EmitCmd49(u8 bufferId);
void EmitStatusAnimation(u8 bufferId, bool8 status2, u32 status);

void MarkBufferBankForExecution(u8 bank);

#endif // GUARD_BATTLE_CONTROLLERS_H
