#ifndef GUARD_BATTLE_SPECIAL_H
#define GUARD_BATTLE_SPECIAL_H

void DoSpecialTrainerBattle(void); 
void SetEReaderTrainerGfxId(void);
u8 GetEreaderTrainerFrontSpriteId(void);
enum TrainerClassID GetEreaderTrainerClassId(void);
void GetEreaderTrainerName(u8 *dst);
void ValidateEReaderTrainer(void);
void ClearEReaderTrainer(struct BattleTowerEReaderTrainer *ereaderTrainer);
void CopyEReaderTrainerGreeting(void);

#endif // GUARD_BATTLE_SPECIAL_H
