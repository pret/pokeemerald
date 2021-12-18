#ifndef GUARD_ITEM_USE_H
#define GUARD_ITEM_USE_H

void ItemUseOutOfBattle_Mail(u8);
void ItemUseOutOfBattle_Bike(u8);
void ItemUseOutOfBattle_Rod(u8);
void ItemUseOutOfBattle_Itemfinder(u8);
void ItemUseOutOfBattle_PokeblockCase(u8);
void ItemUseOutOfBattle_CoinCase(u8);
void ItemUseOutOfBattle_PowderJar(u8);
void ItemUseOutOfBattle_SSTicket(u8);
void ItemUseOutOfBattle_WailmerPail(u8);
void ItemUseOutOfBattle_Medicine(u8);
void ItemUseOutOfBattle_AbilityCapsule(u8);
void ItemUseOutOfBattle_ReduceEV(u8);
void ItemUseOutOfBattle_SacredAsh(u8);
void ItemUseOutOfBattle_PPRecovery(u8);
void ItemUseOutOfBattle_PPUp(u8);
void ItemUseOutOfBattle_RareCandy(u8);
void ItemUseOutOfBattle_TMHM(u8);
void ItemUseOutOfBattle_Repel(u8);
void ItemUseOutOfBattle_EscapeRope(u8);
void ItemUseOutOfBattle_BlackWhiteFlute(u8);
void ItemUseOutOfBattle_EvolutionStone(u8);
void ItemUseOutOfBattle_Berry(u8);
void ItemUseOutOfBattle_EnigmaBerry(u8);
void ItemUseOutOfBattle_FormChange(u8);
void ItemUseOutOfBattle_FormChange_ConsumedOnUse(u8);
void ItemUseOutOfBattle_CannotUse(u8);
void ItemUseInBattle_PokeBall(u8);
void ItemUseInBattle_StatIncrease(u8);
void ItemUseInBattle_Medicine(u8);
void ItemUseInBattle_PPRecovery(u8);
void ItemUseInBattle_Escape(u8);
void ItemUseInBattle_EnigmaBerry(u8);
void Task_UseDigEscapeRopeOnField(u8 taskId);
u8 CanUseDigOrEscapeRopeOnCurMap(void);
u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId);
u32 CanThrowBall(void);

#endif // GUARD_ITEM_USE_H
