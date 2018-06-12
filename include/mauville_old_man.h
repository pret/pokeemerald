
#ifndef GUARD_MAUVILLE_OLD_MAN_H
#define GUARD_MAUVILLE_OLD_MAN_H

enum MauvilleOldManType
{
    MAUVILLE_MAN_BARD,
    MAUVILLE_MAN_HIPSTER,
    MAUVILLE_MAN_TRADER,
    MAUVILLE_MAN_STORYTELLER,
    MAUVILLE_MAN_GIDDY
};

extern struct BardSong gBardSong;

void SetMauvilleOldMan(void);
u8 GetCurrentMauvilleOldMan(void);
void ScrSpecial_SetMauvilleOldManEventObjGfx(void);
u8 sub_81201C8(void);
void sub_8120B70(OldMan *dest);
void sub_8120670(void);
void SanitizeReceivedRubyOldMan(union OldMan * oldMan, u32 r1, u32 r6);
void SanitizeReceivedEmeraldOldMan(union OldMan * oldMan, u32 unused, u32 a2);
void ResetMauvilleOldManFlag(void);

#endif // GUARD_MAUVILLE_OLD_MAN_H
