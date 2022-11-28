#ifndef GUARD_MAUVILLE_OLD_MAN_H
#define GUARD_MAUVILLE_OLD_MAN_H

extern struct BardSong gBardSong;

void SetMauvilleOldMan(void);
u8 GetCurrentMauvilleOldMan(void);
void SetMauvilleOldManObjEventGfx(void);
void SanitizeMauvilleOldManForRuby(OldMan *dest);
void SanitizeReceivedRubyOldMan(union OldMan * oldMan, u32 version, u32 language);
void SanitizeReceivedEmeraldOldMan(union OldMan * oldMan, u32 version, u32 language);
void ResetMauvilleOldManFlag(void);

#endif // GUARD_MAUVILLE_OLD_MAN_H
