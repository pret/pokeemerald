#ifndef GUARD_TRAINER_CARD_H
#define GUARD_TRAINER_CARD_H

struct TrainerCard
{
    /*0x00*/ u8 gender;
    /*0x01*/ u8 stars;
    /*0x02*/ bool8 hasPokedex;
    /*0x03*/ bool8 var_3;
    /*0x04*/ bool8 var_4;
    /*0x05*/ u8 var_5;
    /*0x06*/ u16 firstHallOfFameA;
    /*0x08*/ u16 firstHallOfFameB;
    /*0x0A*/ u16 firstHallOfFameC;
    /*0x0C*/ u16 pokedexSeen;
    /*0x0E*/ u16 trainerId;
    /*0x10*/ u16 playTimeHours;
    /*0x12*/ u16 playTimeMinutes;
    /*0x14*/ u16 linkBattleWins;
    /*0x16*/ u16 linkBattleLosses;
    /*0x18*/ u16 battleTowerWins;
    /*0x1A*/ u16 battleTowerLosses;
    /*0x1C*/ u16 contestsWithFriends;
    /*0x1E*/ u16 pokeblocksWithFriends;
    /*0x20*/ u16 pokemonTrades;
    /*0x22*/ u16 var_22;
    /*0x24*/ u32 money;
    /*0x28*/ u16 var_28[4];
    /*0x30*/ u8 playerName[8];
    /*0x38*/ u8 emeraldAddedUnknownFields[0x54-0x38];
    /*0x54*/ u16 monSpecies[2];
    /*0x58*/ u8 emeraldAddedUnknownFields2[0x64-0x58];
};

extern struct TrainerCard gTrainerCards[4];

void sub_80C3120(struct TrainerCard *arg0, u16 *arg1, u8 gameVersion);
void TrainerCard_ShowLinkCard(u8 arg0, void (*callback)(void));
void TrainerCard_GenerateCardForPlayer(struct TrainerCard *);
u8 sub_80C4904(u8);
void sub_80C6D80(const u8 *, u8 *, u8, u8, u8);

#endif // GUARD_TRAINER_CARD_H
