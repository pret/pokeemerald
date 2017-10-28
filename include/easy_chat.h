#ifndef GUARD_EASYCHAT_H
#define GUARD_EASYCHAT_H

// Taken from Pokeruby, check if it's correct
enum
{
    EC_GROUP_POKEMON,
    EC_GROUP_TRAINER,
    EC_GROUP_STATUS,
    EC_GROUP_BATTLE,
    EC_GROUP_GREETINGS,
    EC_GROUP_PEOPLE,
    EC_GROUP_VOICES,
    EC_GROUP_SPEECH,
    EC_GROUP_ENDINGS,
    EC_GROUP_FEELINGS,
    EC_GROUP_CONDITIONS,
    EC_GROUP_ACTIONS,
    EC_GROUP_LIFESTYLE,
    EC_GROUP_HOBBIES,
    EC_GROUP_TIME,
    EC_GROUP_MISC,
    EC_GROUP_ADJECTIVES,
    EC_GROUP_EVENTS,
    EC_GROUP_MOVE_1,
    EC_GROUP_MOVE_2,
    EC_GROUP_TRENDY_SAYING,
    EC_GROUP_POKEMON_2,
};

void InitEasyChatPhrases(void);
void easy_chat_input_maybe(void);
void CopyEasyChatWord(u8 *dest, u16 word);
bool32 sub_811F8D8(u16 word);
void InitializeEasyChatWordArray(u16 *words, u16 length);
void ConvertEasyChatWordsToString(u8 *dest, const u16 *src, u16 length1, u16 length2);
bool8 IsECWordInValidRange(u16 word);

#endif // GUARD_EASYCHAT_H
