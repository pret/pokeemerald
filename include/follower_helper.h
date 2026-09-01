#ifndef GUARD_FOLLOWER_HELPER_H
#define GUARD_FOLLOWER_HELPER_H

enum FollowerEmotion
{
    FOLLOWER_EMOTION_HAPPY = 0,
    FOLLOWER_EMOTION_NEUTRAL, // Also called "No emotion"
    FOLLOWER_EMOTION_SAD,
    FOLLOWER_EMOTION_UPSET,
    FOLLOWER_EMOTION_ANGRY,
    FOLLOWER_EMOTION_PENSIVE,
    FOLLOWER_EMOTION_LOVE,
    FOLLOWER_EMOTION_SURPRISE,
    FOLLOWER_EMOTION_CURIOUS,
    FOLLOWER_EMOTION_MUSIC,
    FOLLOWER_EMOTION_POISONED,
    FOLLOWER_EMOTION_LENGTH,
};

// Can be either 3 bytes, a u16 and a byte, or a 24-bit value
union __attribute__((packed)) MsgConditionData
{
    u8 bytes[3];
    struct __attribute__((packed))
    {
        u16 hw;
        u8 b;
    } split;
    u32 raw:24;
}; // size = 0x3

struct __attribute__((packed)) MsgCondition
{
    u32 type:8;
    union MsgConditionData data;
}; // size = 0x4

struct FollowerMsgInfoExtended
{
    const u8 *text;
    const u8 *script;

    u32 emotion:4;
    u32 weight:3;
    // if set, `text` is treated as an array of up to 4 texts instead
    // which one is displayed is chosen at random
    u32 textSpread:1;
    u32 orFlag:1; // if set, *any* condition can match, rather than all

    struct MsgCondition conditions[5];
}; // size = 8 + 4 + 5*4 = 32, 0x20

// Follower message conditions
enum MessageCondition
{
    MSG_COND_NONE,
    MSG_COND_SPECIES,
    MSG_COND_TYPE,
    MSG_COND_STATUS,
    MSG_COND_MAPSEC,
    MSG_COND_MAP,
    MSG_COND_ON_MB,
    MSG_COND_WEATHER,
    MSG_COND_MUSIC,
    MSG_COND_TIME_OF_DAY,
    MSG_COND_NEAR_MB
};

#define MATCH_U24(type, value) {type, {.raw = value}}
#define MATCH_U16(type, value1, value2) {type, {.split = {.hw = value1, .b = value2}}}
#define MATCH_U8(type, v1, v2, v3) {type, {.bytes = {v1, v2, v3}}}

#define MATCH_SPECIES(species) MATCH_U16(MSG_COND_SPECIES, species, 0)
#define MATCH_NOT_SPECIES(species) MATCH_U16(MSG_COND_SPECIES, species, 1)
#define MATCH_TYPES(type1, type2) MATCH_U8(MSG_COND_TYPE, type1, type2, 0)
// Checks that follower has *neither* of the two types
#define MATCH_NOT_TYPES(type1, type2) MATCH_U8(MSG_COND_TYPE, type1, type2, TYPE_NONE | 1)
#define MATCH_STATUS(status) MATCH_U24(MSG_COND_STATUS, status)
#define MATCH_MAPSEC(mapsec) MATCH_U24(MSG_COND_MAPSEC, mapsec)
#define MATCH_MAP_RAW(mapGroup, mapNum) MATCH_U8(MSG_COND_MAP, mapGroup, mapNum, 0)
#define MATCH_MAP(map) MATCH_U8(MSG_COND_MAP, MAP_GROUP(map), MAP_NUM(map), 0)
// Matches one of two metatile behaviors follower is standing on
#define MATCH_ON_MB(mb1, mb2) MATCH_U8(MSG_COND_ON_MB, mb1, mb2, 0)
#define MATCH_WEATHER(weather1, weather2) MATCH_U8(MSG_COND_WEATHER, weather1, weather2, 0)
#define MATCH_MUSIC(song) MATCH_U24(MSG_COND_MUSIC, song)
#define MATCH_TIME_OF_DAY(time) MATCH_U24(MSG_COND_TIME_OF_DAY, time)
// Matches metatile behavior within a '+' shape of size `distance`
#define MATCH_NEAR_MB(mb, distance) MATCH_U8(MSG_COND_NEAR_MB, mb, distance, 0)

enum ConditionalMessage
{
    COND_MSG_CELEBI,
    COND_MSG_FIRE,
    COND_MSG_EVER_GRANDE,
    COND_MSG_ROUTE_112,
    COND_MSG_DAY_CARE,
    COND_MSG_MART,
    COND_MSG_VICTORY_ROAD,
    COND_MSG_BIKE_SHOP,
    COND_MSG_MACHINES,
    COND_MSG_SAILING,
    COND_MSG_PUDDLE,
    COND_MSG_SAND,
    COND_MSG_GRASS,
    COND_MSG_FOOTPRINTS,
    COND_MSG_ELEVATOR,
    COND_MSG_ICE_ROOM,
    COND_MSG_ROUTE_117,
    COND_MSG_DRAGON_GROWL,
    COND_MSG_FEAR,
    COND_MSG_FIRE_RAIN,
    COND_MSG_FROZEN,
    COND_MSG_SEASIDE,
    COND_MSG_WATERFALL,
    COND_MSG_RAIN,
    COND_MSG_REFLECTION,
    COND_MSG_LEAVES,
    COND_MSG_ICE,
    COND_MSG_BURN,
    COND_MSG_DAY,
    COND_MSG_NIGHT,
    COND_MSG_ABNORMAL_WEATHER,
    COND_MSG_COUNT,
};

extern const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT];
extern const struct FollowerMessagePool gFollowerBasicMessages[FOLLOWER_EMOTION_LENGTH];

#endif //GUARD_FOLLOWER_HELPER_H
