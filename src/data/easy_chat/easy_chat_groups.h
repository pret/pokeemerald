#include "easy_chat.h"

#if ENGLISH
#include "easy_chat_group_pokemon.h"
#include "easy_chat_group_trainer.h"
#include "easy_chat_group_status.h"
#include "easy_chat_group_battle.h"
#include "easy_chat_group_greetings.h"
#include "easy_chat_group_people.h"
#include "easy_chat_group_voices.h"
#include "easy_chat_group_speech.h"
#include "easy_chat_group_endings.h"
#include "easy_chat_group_feelings.h"
#include "easy_chat_group_conditions.h"
#include "easy_chat_group_actions.h"
#include "easy_chat_group_lifestyle.h"
#include "easy_chat_group_hobbies.h"
#include "easy_chat_group_time.h"
#include "easy_chat_group_misc.h"
#include "easy_chat_group_adjectives.h"
#include "easy_chat_group_events.h"
#include "easy_chat_group_move_1.h"
#include "easy_chat_group_move_2.h"
#include "easy_chat_group_trendy_saying.h"
#include "easy_chat_group_pokemon2.h"
#elif FRENCH
#include "fr/easy_chat_group_pokemon.h"
#include "fr/easy_chat_group_trainer.h"
#include "fr/easy_chat_group_status.h"
#include "fr/easy_chat_group_battle.h"
#include "fr/easy_chat_group_greetings.h"
#include "fr/easy_chat_group_people.h"
#include "fr/easy_chat_group_voices.h"
#include "fr/easy_chat_group_speech.h"
#include "fr/easy_chat_group_endings.h"
#include "fr/easy_chat_group_feelings.h"
#include "fr/easy_chat_group_conditions.h"
#include "fr/easy_chat_group_actions.h"
#include "fr/easy_chat_group_lifestyle.h"
#include "fr/easy_chat_group_hobbies.h"
#include "fr/easy_chat_group_time.h"
#include "fr/easy_chat_group_misc.h"
#include "fr/easy_chat_group_adjectives.h"
#include "fr/easy_chat_group_events.h"
#include "fr/easy_chat_group_move_1.h"
#include "fr/easy_chat_group_move_2.h"
#include "fr/easy_chat_group_trendy_saying.h"
#include "fr/easy_chat_group_pokemon2.h"
#elif ITALIAN
#include "easy_chat_group_pokemon.h"
#include "it/easy_chat_group_trainer.h"
#include "it/easy_chat_group_status.h"
#include "it/easy_chat_group_battle.h"
#include "it/easy_chat_group_greetings.h"
#include "it/easy_chat_group_people.h"
#include "it/easy_chat_group_voices.h"
#include "it/easy_chat_group_speech.h"
#include "it/easy_chat_group_endings.h"
#include "it/easy_chat_group_feelings.h"
#include "it/easy_chat_group_conditions.h"
#include "it/easy_chat_group_actions.h"
#include "it/easy_chat_group_lifestyle.h"
#include "it/easy_chat_group_hobbies.h"
#include "it/easy_chat_group_time.h"
#include "it/easy_chat_group_misc.h"
#include "it/easy_chat_group_adjectives.h"
#include "it/easy_chat_group_events.h"
#include "it/easy_chat_group_move_1.h"
#include "it/easy_chat_group_move_2.h"
#include "it/easy_chat_group_trendy_saying.h"
#include "easy_chat_group_pokemon2.h"
#endif

const struct EasyChatGroup gEasyChatGroups[] = {
    {
        .wordData = {.valueList = gEasyChatGroup_Pokemon},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Pokemon),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Pokemon),
    },
    {
        .wordData = {.words = gEasyChatGroup_Trainer},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Trainer),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Trainer) - 6, // Excludes Red, Green, Flame, Gold, Leaf, and Silver
    },
    {
        .wordData = {.words = gEasyChatGroup_Status},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Status),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Status),
    },
    {
        .wordData = {.words = gEasyChatGroup_Battle},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Battle),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Battle),
    },
    {
        .wordData = {.words = gEasyChatGroup_Greetings},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Greetings),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Greetings),
    },
    {
        .wordData = {.words = gEasyChatGroup_People},
        .numWords = ARRAY_COUNT(gEasyChatGroup_People),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_People),
    },
    {
        .wordData = {.words = gEasyChatGroup_Voices},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Voices),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Voices),
    },
    {
        .wordData = {.words = gEasyChatGroup_Speech},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Speech),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Speech),
    },
    {
        .wordData = {.words = gEasyChatGroup_Endings},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Endings),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Endings),
    },
    {
        .wordData = {.words = gEasyChatGroup_Feelings},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Feelings),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Feelings),
    },
    {
        .wordData = {.words = gEasyChatGroup_Conditions},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Conditions),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Conditions),
    },
    {
        .wordData = {.words = gEasyChatGroup_Actions},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Actions),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Actions),
    },
    {
        .wordData = {.words = gEasyChatGroup_Lifestyle},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Lifestyle),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Lifestyle),
    },
    {
        .wordData = {.words = gEasyChatGroup_Hobbies},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Hobbies),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Hobbies),
    },
    {
        .wordData = {.words = gEasyChatGroup_Time},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Time),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Time),
    },
    {
        .wordData = {.words = gEasyChatGroup_Misc},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Misc),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Misc),
    },
    {
        .wordData = {.words = gEasyChatGroup_Adjectives},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Adjectives),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Adjectives),
    },
    {
        .wordData = {.words = gEasyChatGroup_Events},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Events),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Events),
    },
    {
        .wordData = {.valueList = gEasyChatGroup_Move1},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Move1),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Move1),
    },
    {
        .wordData = {.valueList = gEasyChatGroup_Move2},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Move2),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Move2),
    },
    {
        .wordData = {.words = gEasyChatGroup_TrendySaying},
        .numWords = ARRAY_COUNT(gEasyChatGroup_TrendySaying),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_TrendySaying),
    },
    {
        .wordData = {.valueList = gEasyChatGroup_Pokemon2},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Pokemon2),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Pokemon2),
    },
};
