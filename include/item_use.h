#ifndef GUARD_ITEM_USE_H
#define GUARD_ITEM_USE_H

void ItemUseOutOfBattle_Mail(u8);
void ItemUseOutOfBattle_Bike(u8);
void ItemUseOnFieldCB_Bike(u8);
void ItemUseOutOfBattle_Rod(u8);
void ItemUseOnFieldCB_Rod(u8);
void ItemUseOutOfBattle_Itemfinder(u8);
void ItemUseOnFieldCB_Itemfinder(u8);
void RunItemfinderResults(u8);
void ExitItemfinder(u8);
bool8 ItemfinderCheckForHiddenItems(const struct MapEvents *, u8);
void sub_80C9720(u8);
void sub_80C9838(u8, s16, s16);
u8 GetPlayerDirectionTowardsHiddenItem(s16, s16);
void SetPlayerDirectionTowardsItem(u8);
void DisplayItemRespondingMessageAndExitItemfinder(u8);
void RotatePlayerAndExitItemfinder(u8);
void ItemUseOutOfBattle_PokeblockCase(u8);
void ItemUseOutOfBattle_CoinCase(u8);
void ItemUseOutOfBattle_PowderJar(u8);
void ItemUseOutOfBattle_SSTicket(u8);
void sub_80C9D00(u8);
void ItemUseOutOfBattle_WailmerPail(u8);
void sub_80C9D74(u8);
void ItemUseOutOfBattle_Medicine(u8);
void ItemUseOutOfBattle_ReduceEV(u8);
void ItemUseOutOfBattle_SacredAsh(u8);
void ItemUseOutOfBattle_PPRecovery(u8);
void ItemUseOutOfBattle_PPUp(u8);
void ItemUseOutOfBattle_RareCandy(u8);
void ItemUseOutOfBattle_TMHM(u8);
void sub_80C9EE4(u8);
void sub_80C9F10(u8);
void sub_80C9F80(u8);
void sub_80C9FC0(u8);
void ItemUseOutOfBattle_Repel(u8);
void ItemUseOutOfBattle_BlackWhiteFlute(u8);
void task08_080A1C44(u8);
u8 CanUseEscapeRopeOnCurrMap(void);
void ItemUseOutOfBattle_EscapeRope(u8);
void ItemUseOutOfBattle_EvolutionStone(u8);
void ItemUseInBattle_PokeBall(u8);
void ItemUseInBattle_StatIncrease(u8);
void ItemUseInBattle_Medicine(u8);
void ItemUseInBattle_PPRecovery(u8);
void ItemUseInBattle_Escape(u8);
void ItemUseOutOfBattle_EnigmaBerry(u8);
void ItemUseInBattle_EnigmaBerry(u8);
void ItemUseOutOfBattle_CannotUse(u8);
u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId);
void sub_80FDD10(u8);

#endif // GUARD_ITEM_USE_H
