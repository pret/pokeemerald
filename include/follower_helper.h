#ifndef GUARD_FOLLOWER_HELPER_H
#define GUARD_FOLLOWER_HELPER_H

enum {
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

// This struct is optimized for size
// Each "section" can be used to combine multiple conditions,
// i.e, species and map
// Just set the flags accordingly and use the right union member
struct __attribute__((packed)) FollowerMsgInfoExtended {
    const u8 *text;
    const u8 *script;

    union __attribute__((packed)) {
        u16 species:10;
        struct __attribute__((packed)) {
            u16 type1:5;
            u16 type2:5; // if >= NUMBER_OF_MON_TYPES, inverts checking for type1
        } types;
        u16 status:10;
    } st;
    u16 stFlags:2; // 0 = no matching, 1 = species matching, 2 = type matching, 3 = status
    u16 emotion:4; // emotion for this message

    union __attribute__((packed)) {
        struct __attribute__((packed)) {
            u16 mapSec:8;
        } mapSec;
        struct __attribute__((packed)) {
            u16 mapNum:8;
            u16 mapGroup:6;
        } map;
        struct __attribute__((packed)) {
            u16 behavior1:8;
            u16 behavior2:6; // not full; only goes up to 0x3F
        } mb;
    } mm;
    u16 mmFlags:2; // 1 = map sec, 2 = map, 3 = metatile behavior

    union __attribute__((packed)) {
        struct __attribute__((packed)) {
            u16 weather1:5;
            u16 weather2:5;
        } weather;
        u16 song:10;
        u16 timeOfDay:10;
    } wt;
    u16 wtFlags:2; // 1 = weather matching, 2 = song, 3 = time
    u16 weight:3;
    // if set, `text` is treated as an array of up to 4 texts instead
    u16 textSpread:1;

    union __attribute__((packed)) {
        struct __attribute__((packed)) {
            u16 behavior:8;
            u16 distance:6;
        } mb;
    } near;
    u16 nearFlags:2; // 1 = mb within '+'-shaped distance away
};

enum {
    ST_FLAGS_SPECIES = 1,
    ST_FLAGS_TYPE,
    ST_FLAGS_STATUS,
};

enum {
    MM_FLAGS_MAPSEC = 1,
    MM_FLAGS_MAP,
    MM_FLAGS_MB, // (m)etatile (b)ehavior
};

enum {
    WT_FLAGS_WEATHER = 1,
    WT_FLAGS_MUSIC,
    WT_FLAGS_TIME,
};

#define NEAR_FLAGS_MB 1

enum {
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
    COND_MSG_COUNT,
};

extern const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT];

#endif //GUARD_FOLLOWER_HELPER_H
