#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

// rom3.s, emitters
void EmitSetAttributes(u8 bufferId, u8 request, u8 c, u8 bytes, void *data);
void EmitMoveAnimation(u8 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct* disableStructPtr, u8 multihit);
void EmitHealthBarUpdate(u8 bufferId, u16 hpValue);
void EmitEffectivenessSound(u8 bufferId, u16 songId);
void EmitPrintStringPlayerOnly(u8 bufferId, u16 stringId);

void MarkBufferBankForExecution(u8 bank);

#endif // GUARD_BATTLE_CONTROLLERS_H
