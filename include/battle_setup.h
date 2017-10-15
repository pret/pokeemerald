#ifndef GUARD_BATTLE_SETUP_H
#define GUARD_BATTLE_SETUP_H

void BattleSetup_StartScriptedWildBattle(void);
u8 BattleSetup_GetTerrainId(void);
u8 *BattleSetup_ConfigureTrainerBattle(const u8 *data);

u8 HasTrainerAlreadyBeenFought(u16);
void trainer_flag_set(u16);
void trainer_flag_clear(u16);
void BattleSetup_StartTrainerBattle(void);
u8 *BattleSetup_GetScriptAddrAfterBattle(void);
u8 *BattleSetup_GetTrainerPostBattleScript(void);

#endif // GUARD_BATTLE_SETUP_H
