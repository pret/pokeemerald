#ifndef GUARD_CONSTANTS_MYSTERY_GIFT_H
#define GUARD_CONSTANTS_MYSTERY_GIFT_H

#define GET_NUM_STAMPS        0
#define GET_MAX_STAMPS        1
#define GET_CARD_BATTLES_WON  2
#define GET_CARD_BATTLES_LOST 3
#define GET_CARD_NUM_TRADES   4

#define CARD_STAT_BATTLES_WON   0
#define CARD_STAT_BATTLES_LOST  1
#define CARD_STAT_NUM_TRADES    2
#define CARD_STAT_NUM_STAMPS    3
#define CARD_STAT_MAX_STAMPS    4

// Values for the type field of Wonder Card
#define CARD_TYPE_GIFT       0 // Normal "Wonder Card"
#define CARD_TYPE_STAMP      1 // "Stamp Card"
#define CARD_TYPE_LINK_STAT  2 // Referred to as the "Battle Card", shows battle and trade stats
#define CARD_TYPE_COUNT      3

// Values for the sendType field of Wonder Card/News
#define SEND_TYPE_DISALLOWED     0
#define SEND_TYPE_ALLOWED        1
#define SEND_TYPE_ALLOWED_ALWAYS 2

// Return values for MysteryGift_CompareCardFlags, handled by gMysteryGiftServerScript_SendWonderCard
#define HAS_NO_CARD   0
#define HAS_SAME_CARD 1
#define HAS_DIFF_CARD 2

// The number of battles needed to be recorded on a Battle Card to win a prize
#define REQUIRED_CARD_BATTLES 3

// Stamps are 32 bits. The first 16 bits are the species
// and the second 16 bits are a number (presumably an ID of some kind)
#define STAMP_SPECIES 0
#define STAMP_ID      1

// Number of different types/colors of Wonder Card and News backgrounds
#define NUM_WONDER_BGS 8

#define MAX_WONDER_CARD_STAT 999

#define WONDER_CARD_FLAG_OFFSET 1000

#endif //GUARD_CONSTANTS_MYSTERY_GIFT_H
