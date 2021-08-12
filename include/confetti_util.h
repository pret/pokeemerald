#ifndef GUARD_CONFETTI_UTIL_H
#define GUARD_CONFETTI_UTIL_H

struct ConfettiUtil
{
    struct OamData oam;
    s16 x;
    s16 y;
    s16 xDelta;
    s16 yDelta;
    u16 tileTag;
    u16 palTag;
    u16 tileNum;
    u8 id;
    u8 filler;
    u8 animNum;
    u8 active:1;
    u8 allowUpdates:1;
    u8 dummied:1;
    u8 priority:2;
    s16 data[8];
    void (*callback)(struct ConfettiUtil *);
};

bool32 ConfettiUtil_Init(u8 count);
bool32 ConfettiUtil_Free(void);
bool32 ConfettiUtil_Update(void);
u8 ConfettiUtil_SetCallback(u8 id, void (*func)(struct ConfettiUtil *));
u8 ConfettiUtil_SetData(u8 id, u8 dataArrayId, s16 dataValue);
u8 ConfettiUtil_AddNew(const struct OamData *oam, u16 tileTag, u16 palTag, s16 x, s16 y, u8 animNum, u8 priority);
u8 ConfettiUtil_Remove(u8 id);

#endif // GUARD_CONFETTI_UTIL_H
