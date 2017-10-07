#ifndef GUARD_BATTLE_MESSAGE_H
#define GUARD_BATTLE_MESSAGE_H

// for 0xFD

#define B_TXT_BUFF1 00
#define B_TXT_BUFF2 01
#define B_TXT_COPY_VAR_1 02
#define B_TXT_COPY_VAR_2 03
#define B_TXT_COPY_VAR_3 04
#define B_TXT_PLAYER_MON1_NAME 05
#define B_TXT_OPPONENT_MON1_NAME 06
#define B_TXT_PLAYER_MON2_NAME 07
#define B_TXT_OPPONENT_MON2_NAME 08
#define B_TXT_LINK_PLAYER_MON1_NAME 09
#define B_TXT_LINK_OPPONENT_MON1_NAME 0A
#define B_TXT_LINK_PLAYER_MON2_NAME 0B
#define B_TXT_LINK_OPPONENT_MON2_NAME 0C
#define B_TXT_ATK_NAME_WITH_PREFIX_MON1 0D
#define B_TXT_ATK_NAME 0E
#define B_TXT_ATK_NAME_WITH_PREFIX 0F
#define B_TXT_DEF_NAME_WITH_PREFIX 10
#define B_TXT_EFF_NAME_WITH_PREFIX 11 // EFF = short for gEffectBank
#define B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX 12
#define B_TXT_ACTIVE_NAME_WITH_PREFIX 13
#define B_TXT_CURRENT_MOVE 14
#define B_TXT_LAST_MOVE 15
#define B_TXT_LAST_ITEM 16
#define B_TXT_LAST_ABILITY 17
#define B_TXT_ATK_ABILITY 18
#define B_TXT_DEF_ABILITY 19
#define B_TXT_SCR_ACTIVE_ABILITY 1A
#define B_TXT_EFF_ABILITY 1B
#define B_TXT_TRAINER1_CLASS 1C
#define B_TXT_TRAINER1_NAME 1D
#define B_TXT_1E 1E // trainer name for a link player
#define B_TXT_1F 1F // trainer name for a link player
#define B_TXT_20 20 // trainer name for a link player
#define B_TXT_21 21 // trainer name for a link player
#define B_TXT_22 22 // trainer name for a link player
#define B_TXT_PLAYER_NAME 23
#define B_TXT_TRAINER1_LOSE_TEXT 24
#define B_TXT_TRAINER1_WIN_TEXT 25
#define B_TXT_26 26
#define B_TXT_PC_CREATOR_NAME 27
#define B_TXT_ATK_PREFIX1 28
#define B_TXT_DEF_PREFIX1 29
#define B_TXT_ATK_PREFIX2 2A
#define B_TXT_DEF_PREFIX2 2B
#define B_TXT_ATK_PREFIX3 2C
#define B_TXT_DEF_PREFIX3 2D
#define B_TXT_TRAINER2_CLASS 2E
#define B_TXT_TRAINER2_NAME 2F
#define B_TXT_TRAINER2_LOSE_TEXT 30
#define B_TXT_TRAINER2_WIN_TEXT 31
#define B_TXT_PARTNER_CLASS 32
#define B_TXT_PARTNER_NAME 33
#define B_TXT_BUFF3 34

// for B_TXT_BUFF1, B_TXT_BUFF2 and B_TXT_BUFF3

#define B_BUFF_STRING                   0
#define B_BUFF_NUMBER                   1
#define B_BUFF_MOVE                     2
#define B_BUFF_TYPE                     3
#define B_BUFF_MON_NICK_WITH_PREFIX     4
#define B_BUFF_STAT                     5
#define B_BUFF_SPECIES                  6
#define B_BUFF_MON_NICK                 7
#define B_BUFF_NEGATIVE_FLAVOUR         8
#define B_BUFF_ABILITY                  9
#define B_BUFF_ITEM                     10

#define B_BUFF_PLACEHOLDER_BEGIN        0xFD
#define B_BUFF_EOS                      0xFF

#define PREPARE_STAT_BUFFER(textVar, statId)                                \
{                                                                           \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                                  \
    textVar[1] = B_BUFF_STAT;                                               \
    textVar[2] = statId;                                                    \
    textVar[3] = B_BUFF_EOS;                                                \
}

#define PREPARE_ABILITY_BUFFER(textVar, abilityId)                          \
{                                                                           \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                                  \
    textVar[1] = B_BUFF_ABILITY;                                            \
    textVar[2] = abilityId;                                                 \
    textVar[3] = B_BUFF_EOS;                                                \
}

#define PREPARE_TYPE_BUFFER(textVar, typeId)                                \
{                                                                           \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                                  \
    textVar[1] = B_BUFF_TYPE;                                               \
    textVar[2] = typeId;                                                    \
    textVar[3] = B_BUFF_EOS;                                                \
}

#define PREPARE_BYTE_NUMBER_BUFFER(textVar, maxDigits, number)  \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_NUMBER;                                 \
    textVar[2] = 1;                                             \
    textVar[3] = maxDigits;                                     \
    textVar[4] = (number);                                      \
    textVar[5] = B_BUFF_EOS;                                    \
}

#define PREPARE_HWORD_NUMBER_BUFFER(textVar, maxDigits, number)             \
{                                                                           \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                                  \
    textVar[1] = B_BUFF_NUMBER;                                             \
    textVar[2] = 2;                                                         \
    textVar[3] = maxDigits;                                                 \
    textVar[4] = (number);                                                  \
    textVar[5] = (number & 0x0000FF00) >> 8;                                \
    textVar[6] = B_BUFF_EOS;                                                \
}

#define PREPARE_WORD_NUMBER_BUFFER(textVar, maxDigits, number)  \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_NUMBER;                                 \
    textVar[2] = 4;                                             \
    textVar[3] = maxDigits;                                     \
    textVar[4] = (number);                                      \
    textVar[5] = (number & 0x0000FF00) >> 8;                    \
    textVar[6] = (number & 0x00FF0000) >> 16;                   \
    textVar[7] = (number & 0xFF000000) >> 24;                   \
    textVar[8] = B_BUFF_EOS;                                    \
}

#define PREPARE_STRING_BUFFER(textVar, stringId)                \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_STRING;                                 \
    textVar[2] = stringId;                                      \
    textVar[3] = (stringId & 0xFF00) >> 8;                      \
    textVar[4] = B_BUFF_EOS;                                    \
}

#define PREPARE_MOVE_BUFFER(textVar, move)                      \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_MOVE;                                   \
    textVar[2] = move;                                          \
    textVar[3] = (move & 0xFF00) >> 8;                          \
    textVar[4] = B_BUFF_EOS;                                    \
}

#define PREPARE_ITEM_BUFFER(textVar, item)                      \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_ITEM;                                   \
    textVar[2] = item;                                          \
    textVar[3] = (item & 0xFF00) >> 8;                          \
    textVar[4] = B_BUFF_EOS;                                    \
}

#define PREPARE_SPECIES_BUFFER(textVar, species)                \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_SPECIES;                                \
    textVar[2] = species;                                       \
    textVar[3] = (species & 0xFF00) >> 8;                       \
    textVar[4] = B_BUFF_EOS;                                    \
}

#define PREPARE_MON_NICK_WITH_PREFIX_BUFFER(textVar, bank, partyId)         \
{                                                                           \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                                  \
    textVar[1] = B_BUFF_MON_NICK_WITH_PREFIX;                               \
    textVar[2] = bank;                                                      \
    textVar[3] = partyId;                                                   \
    textVar[4] = B_BUFF_EOS;                                                \
}

#define PREPARE_MON_NICK_BUFFER(textVar, bank, partyId)         \
{                                                               \
    textVar[0] = B_BUFF_PLACEHOLDER_BEGIN;                      \
    textVar[1] = B_BUFF_MON_NICK;                               \
    textVar[2] = bank;                                          \
    textVar[3] = partyId;                                       \
    textVar[4] = B_BUFF_EOS;                                    \
}

struct StringInfoBattle
{
    u16 currentMove;
    u16 lastMove;
    u16 lastItem;
    u8 lastAbility;
    u8 scrActive;
    u8 unk1605E;
    u8 hpScale;
    u8 StringBank;
    u8 moveType;
    u8 abilities[4];
    u8 textBuffs[3][0x10];
};

void BufferStringBattle(u16 stringID);
u32 BattleStringExpandPlaceholdersToDisplayedString(const u8* src);
u32 BattleStringExpandPlaceholders(const u8* src, u8* dst);
void sub_814F9EC(const u8* text, u8 arg1);

#define TEXT_BUFF_ARRAY_COUNT   16

extern u8 gDisplayedStringBattle[300];
extern u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT];

extern const u8* const gStatNamesTable[];
extern const u8* const gPokeblockWasTooXStringTable[];
extern const u8* const gRefereeStringsTable[];
extern const u8* const gStatNamesTable2[];

extern const u16 gMissStringIds[];
extern const u16 gTrappingMoves[];

#endif // GUARD_BATTLE_MESSAGE_H
