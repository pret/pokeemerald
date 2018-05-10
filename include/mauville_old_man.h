
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

void SetMauvilleOldMan(void);
u8 GetCurrentMauvilleOldMan(void);
extern struct BardSong gBardSong;
void ScrSpecial_SetMauvilleOldManMapObjGfx(void);

#endif // GUARD_MAUVILLE_OLD_MAN_H
