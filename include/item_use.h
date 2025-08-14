#ifndef GUARD_ITEM_USE_H
#define GUARD_ITEM_USE_H

void ItemUseOutOfBattle_Mail(u8 taskId);
void ItemUseOutOfBattle_Bike(u8 taskId);
void ItemUseOutOfBattle_Rod(u8 taskId);
void ItemUseOutOfBattle_Itemfinder(u8 var);
void ItemUseOutOfBattle_PokeblockCase(u8 taskId);
void ItemUseOutOfBattle_CoinCase(u8 taskId);
void ItemUseOutOfBattle_PowderJar(u8 taskId);
void ItemUseOutOfBattle_WailmerPail(u8 taskId);
void ItemUseOutOfBattle_Medicine(u8 taskId);
void ItemUseOutOfBattle_ReduceEV(u8 taskId);
void ItemUseOutOfBattle_SacredAsh(u8 taskId);
void ItemUseOutOfBattle_PPRecovery(u8 taskId);
void ItemUseOutOfBattle_PPUp(u8 taskId);
void ItemUseOutOfBattle_RareCandy(u8 taskId);
void ItemUseOutOfBattle_TMHM(u8 taskId);
void ItemUseOutOfBattle_Repel(u8 taskId);
void ItemUseOutOfBattle_EscapeRope(u8 taskId);
void ItemUseOutOfBattle_BlackWhiteFlute(u8 taskId);
void ItemUseOutOfBattle_EvolutionStone(u8 taskId);
void ItemUseOutOfBattle_Berry(u8 taskId);
void ItemUseOutOfBattle_EnigmaBerry(u8 taskId);
void ItemUseOutOfBattle_CannotUse(u8 taskId);
void ItemUseInBattle_PokeBall(u8 taskId);
void ItemUseInBattle_StatIncrease(u8 taskId);
void ItemUseInBattle_Medicine(u8 taskId);
void ItemUseInBattle_PPRecovery(u8 taskId);
void ItemUseInBattle_Escape(u8 taskId);
void ItemUseInBattle_EnigmaBerry(u8 taskId);
void Task_UseDigEscapeRopeOnField(u8 taskId);
bool8 CanUseDigOrEscapeRopeOnCurMap(void);
u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId);

#endif // GUARD_ITEM_USE_H
