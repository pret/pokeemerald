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
    u16 textSpread:1; // if set, `text` is an array of texts instead

    union __attribute__((packed)) {
        struct __attribute__((packed)) {
            u16 behavior:8;
            u16 distance:6;
        } mb;
    } near;
    u16 nearFlags:2; // 1 = mb within '+' shape distance away
};

extern const struct FollowerMsgInfoExtended gFollowerConditionalMessages[];

#endif //GUARD_FOLLOWER_HELPER_H
