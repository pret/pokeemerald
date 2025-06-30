#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3);
u8 ScriptGiveEgg(u16 species);
void CreateScriptedWildMon(u16 species, u8 level, u16 item);
void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
