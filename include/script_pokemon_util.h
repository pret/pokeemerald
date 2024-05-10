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
u32 BirchCase_GiveMonParameterized(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 gender, u8 *evs, u8 *ivs, u16 *moves, bool8 ggMaxFactor, u8 teraType, bool8 isShinyExpansion);
void Script_GetChosenMonOffensiveEVs(void);
void Script_GetChosenMonDefensiveEVs(void);
void Script_GetChosenMonOffensiveIVs(void);
void Script_GetChosenMonDefensiveIVs(void);
int GameClear(void);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
