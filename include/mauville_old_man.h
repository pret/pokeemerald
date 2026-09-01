#ifndef GUARD_MAUVILLE_OLD_MAN_H
#define GUARD_MAUVILLE_OLD_MAN_H

extern struct BardSong gBardSong;

void SetMauvilleOldMan(void);
u8 GetCurrentMauvilleOldMan(void);
void SetMauvilleOldManObjEventGfx(void);
void SanitizeMauvilleOldManForRuby(union OldMan *oldMan);
void SanitizeReceivedRubyOldMan(union OldMan *oldMan, enum GameVersion version, enum Language language);
void SanitizeReceivedEmeraldOldMan(union OldMan *oldMan, enum Language language);
void ResetMauvilleOldManFlag(void);

#endif // GUARD_MAUVILLE_OLD_MAN_H
