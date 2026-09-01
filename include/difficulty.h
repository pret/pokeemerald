#ifndef GUARD_DIFFICULTY_H
#define GUARD_DIFFICULTY_H

#include "constants/difficulty.h"
#include "script.h"

enum DifficultyLevel GetCurrentDifficultyLevel(void);
void SetCurrentDifficultyLevel(enum DifficultyLevel);

enum DifficultyLevel GetBattlePartnerDifficultyLevel(u16);
enum DifficultyLevel GetTrainerDifficultyLevel(u16);
void Script_IncreaseDifficulty(void);
void Script_DecreaseDifficulty(void);
void Script_GetDifficulty(void);
void Script_SetDifficulty(struct ScriptContext *);

#endif // GUARD_DIFFICULTY_H
