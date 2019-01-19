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
    /*0x0C*/ u16 pokedexCaught;
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
    /*0x38*/ u8 var_38;
    /*0x39*/ u8 var_39;
    /*0x3A*/ u16 var_3A;
    /*0x3C*/ u32 var_3C;
    /*0x40*/ u32 var_40;
    /*0x44*/ u8 filler44[0x8];
    /*0x4C*/ u8 var_4C;
    /*0x4D*/ u8 var_4D;
    /*0x4E*/ u8 var_4E;
    /*0x4F*/ u8 var_4F;
    /*0x50*/ u8 var_50[0x4];
    /*0x54*/ u16 monSpecies[6];
    /*0x60*/ u16 var_60;
    /*0x62*/ u16 var_62;
};


extern struct TrainerCard gTrainerCards[4];

void sub_80C3120(struct TrainerCard *arg0, u16 *src, u8 gameVersion);
void TrainerCard_ShowLinkCard(u8 arg0, void (*callback)(void));
void TrainerCard_GenerateCardForPlayer(struct TrainerCard *);
u8 sub_80C4904(u8);
void sub_80C6D80(const u8 *, u8 *, u8, u8, u8);

#endif // GUARD_TRAINER_CARD_H
