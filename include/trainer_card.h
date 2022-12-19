#ifndef GUARD_TRAINER_CARD_H
#define GUARD_TRAINER_CARD_H

#define TRAINER_CARD_PROFILE_LENGTH  4
#define TRAINER_CARD_STICKER_TYPES   3

enum
{
    CARD_TYPE_FRLG,
    CARD_TYPE_RS,
    CARD_TYPE_EMERALD,
};

enum
{
    MON_ICON_TINT_NORMAL,
    MON_ICON_TINT_BLACK,
    MON_ICON_TINT_PINK,
    MON_ICON_TINT_SEPIA,
};

struct TrainerCard
{
    /*0x00*/ u8 gender;
    /*0x01*/ u8 stars;
    /*0x02*/ bool8 hasPokedex;
    /*0x03*/ bool8 caughtAllHoenn;
    /*0x04*/ bool8 hasAllPaintings;
    /*0x06*/ u16 hofDebutHours;
    /*0x08*/ u16 hofDebutMinutes;
    /*0x0A*/ u16 hofDebutSeconds;
    /*0x0C*/ u16 caughtMonsCount;
    /*0x0E*/ u16 trainerId;
    /*0x10*/ u16 playTimeHours;
    /*0x12*/ u16 playTimeMinutes;
    /*0x14*/ u16 linkBattleWins;
    /*0x16*/ u16 linkBattleLosses;
    /*0x18*/ u16 battleTowerWins;
    /*0x1A*/ u16 battleTowerStraightWins;
    /*0x1C*/ u16 contestsWithFriends;
    /*0x1E*/ u16 pokeblocksWithFriends;
    /*0x20*/ u16 pokemonTrades;
    /*0x24*/ u32 money;
    /*0x28*/ u16 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH];
    /*0x30*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x38*/ u8 version;
    /*0x3A*/ bool16 linkHasAllFrontierSymbols;
    /*0x3C*/ union {
                u32 berryCrush;
                u32 frontier;
             } linkPoints; // This field is used differently by FRLG vs Emerald
    /*0x40*/ u32 unionRoomNum;
    /*0x44*/ u8 filler[8];
    /*0x4C*/ bool8 shouldDrawStickers; // FRLG only
    /*0x4D*/ u8 unused;
    /*0x4E*/ u8 monIconTint; // FRLG only
    /*0x4F*/ u8 unionRoomClass;
    /*0x50*/ u8 stickers[TRAINER_CARD_STICKER_TYPES]; // FRLG only
    /*0x54*/ u16 monSpecies[PARTY_SIZE]; // FRLG only
             // Note: Link players use linkHasAllFrontierSymbols, not the field below,
             // which they use for a Wonder Card flag id instead (see CreateTrainerCardInBuffer)
    /*0x60*/ bool16 hasAllFrontierSymbols;
    /*0x62*/ u16 frontierBP;
};

extern struct TrainerCard gTrainerCards[4];

u32 CountPlayerTrainerStars(void);
u8 GetTrainerCardStars(u8 cardId);
void CopyTrainerCardData(struct TrainerCard *dst, struct TrainerCard *src, u8 gameVersion);
void ShowPlayerTrainerCard(void (*callback)(void));
void ShowTrainerCardInLink(u8 cardId, void (*callback)(void));
void TrainerCard_GenerateCardForLinkPlayer(struct TrainerCard *);

#endif // GUARD_TRAINER_CARD_H
