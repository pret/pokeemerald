#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

u32 ScriptGiveMon(u16, u8, u16);
u32 ScriptGiveMonParameterized(u16, u8, u16, u8, u8, u8, u8, u8 *, u8 *, u16 *, bool8, bool8, u8);
u8 ScriptGiveEgg(u16);
void CreateScriptedWildMon(u16, u8, u16);
void CreateScriptedDoubleWildMon(u16, u8, u16, u16, u8, u16);
void ScriptSetMonMoveSlot(u8, u16, u8);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);
void Script_GetChosenMonOffensiveEV(void);
void Script_GetChosenMonDefensiveEV(void);
void Script_GetChosenMonOffensiveIV(void);
void Script_GetChosenMonDefensiveIV(void);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
