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
    u8 gender;
    u8 stars;
    bool8 hasPokedex;
    bool8 caughtAllHoenn;
    bool8 hasAllPaintings;
    u16 hofDebutHours;
    u16 hofDebutMinutes;
    u16 hofDebutSeconds;
    u16 caughtMonsCount;
    u16 trainerId;
    u16 playTimeHours;
    u16 playTimeMinutes;
    u16 linkBattleWins;
    u16 linkBattleLosses;
    u16 battleTowerWins;
    u16 battleTowerStraightWins;
    u16 contestsWithFriends;
    u16 pokeblocksWithFriends;
    u16 pokemonTrades;
    u32 money;
    u16 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH];
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 version;
    bool16 linkHasAllFrontierSymbols;
    union {
       u32 berryCrush;
       u32 frontier;
    } linkPoints; // This field is used differently by FRLG vs Emerald
    u32 unionRoomNum;
    u8 filler[8];
    bool8 shouldDrawStickers; // FRLG only
    u8 unused;
    u8 monIconTint; // FRLG only
    u8 unionRoomClass;
    u8 stickers[TRAINER_CARD_STICKER_TYPES]; // FRLG only
    u16 monSpecies[PARTY_SIZE]; // FRLG only
    // Note: Link players use linkHasAllFrontierSymbols, not the field below,
    // which they use for a Wonder Card flag id instead (see CreateTrainerCardInBuffer)
    bool16 hasAllFrontierSymbols;
    u16 frontierBP;
};

extern struct TrainerCard gTrainerCards[4];

u32 CountPlayerTrainerStars(void);
u8 GetTrainerCardStars(u8 cardId);
void CopyTrainerCardData(struct TrainerCard *dst, struct TrainerCard *src, u8 gameVersion);
void ShowPlayerTrainerCard(void (*callback)(void));
void ShowTrainerCardInLink(u8 cardId, void (*callback)(void));
void TrainerCard_GenerateCardForLinkPlayer(struct TrainerCard *trainerCard);

#endif // GUARD_TRAINER_CARD_H
