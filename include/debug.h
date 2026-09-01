#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H

void Debug_ShowMainMenu(void);
extern const u8 Debug_FlagsAndVarNotSetBattleConfigMessage[];
const u8 *GetWeatherName(u32 weatherId);
const struct Trainer* GetDebugAiTrainer(void);

void DebugNative_GetAbilityNames(void);
void DebugNative_Party_SetFriendship(void);

extern EWRAM_DATA bool8 gIsDebugBattle;
extern EWRAM_DATA u64 gDebugAIFlags;

#endif // GUARD_DEBUG_H
