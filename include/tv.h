#ifndef GUARD_TV_H
#define GUARD_TV_H

#define SLOT_MACHINE 0
#define ROULETTE 1

extern u8 *const gTVStringVarPtrs[3];

void ClearTVShowData(void);
void sub_80EE184(void);
void sub_80EE35C(u16 foeSpecies, u16 species, u8 moveIdx, const u16 *movePtr, u16 betterMove);
void sub_80EE8C8(u16 winStreak, u8 facility);
void DoTVShow(void);
void DoTVShowInSearchOfTrainers(void);
void sub_80EDCE8(void);
void sub_80EE2CC(void);
void sub_80EE72C(void);
void sub_80EED10(void);
void sub_80EED34(void);
void sub_80EED60(u16 delta);
void sub_80F01B8(void);
void ReceiveTvShowsData(void *src, u32 size, u8 masterIdx);
void sub_80EE4DC(struct Pokemon *pokemon, u8 ribbonMonDataIdx);
u32 GetPlayerIDAsU32(void);
bool8 GetPriceReduction(u8 newsKind);
void sub_80F14F8(TVShow *shows);
size_t CountDigits(int value);
u8 GetRibbonCount(struct Pokemon *pokemon);
void AlertTVThatPlayerPlayedSlotMachine(u16 nCoinsSpent);
void AlertTVThatPlayerPlayedRoulette(u16 nCoinsSpent);
void AlertTVOfNewCoinTotal(u16 nCoinsPaidOut);
void sub_80EEA70(void);
void sub_80EDB44(void);
void sub_80EDC60(const u16 *words);
void sub_80EDA80(void);
void ReceivePokeNewsData(void *src, u32 size, u8 masterIdx);
void sub_80F0BB8(void);
void sub_80ED950(bool8 flag);
void sub_80EEC80(void);
void sub_80EECA4(void);
void sub_80EECC8(void);
void sub_80EECEC(void);
void sub_80F1208(TVShow *shows);
void sub_80EE44C(u8 nMonsCaught, u8 nPkblkUsed);
void sub_80F14F8(TVShow *shows);
size_t sub_80EF370(int value);
bool8 Put3CheersForPokeblocksOnTheAir(const u8 *partnersName, u8 flavor, u8 unused, u8 sheen, u8 language);
void SetPokemonAnglerSpecies(u16 species);
void UpdateTVShowsPerDay(u16 days);
void PutPokemonTodayCaughtOnAir(void);
void TV_PutSecretBaseVisitOnTheAir(void);
void PutBattleUpdateOnTheAir(u8 opponentLinkPlayerId, u16 move, u16 speciesPlayer, u16 speciesOpponent);
void BravoTrainerPokemonProfile_BeforeInterview1(u16 move);
void InterviewBefore(void);
void InterviewAfter(void);
void UpdateTVScreensOnMap(int, int);
void TV_PrintIntToStringVar(u8 varIdx, int value);
void SaveRecordedItemPurchasesForTVShow(void);
bool8 sub_80EE818(void);
void sub_80EE8C8(u16 winStreak, u8 facilityAndMode);
void BravoTrainerPokemonProfile_BeforeInterview2(u8 contestStandingPlace);
void ContestLiveUpdates_BeforeInterview_1(u8 a0);
void ContestLiveUpdates_BeforeInterview_2(u8 a0);
void ContestLiveUpdates_BeforeInterview_3(u8 a0);
void ContestLiveUpdates_BeforeInterview_4(u16 a0);
void ContestLiveUpdates_BeforeInterview_5(u8 a0, u8 a1);
void ResetGabbyAndTy(void);

#endif //GUARD_TV_H
