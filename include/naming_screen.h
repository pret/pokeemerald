#ifndef GUARD_NAMING_SCREEN_H
#define GUARD_NAMING_SCREEN_H

#define NAMING_SCREEN_PLAYER        0
#define NAMING_SCREEN_BOX           1
#define NAMING_SCREEN_CAUGHT_MON    2
#define NAMING_SCREEN_3             3
#define NAMING_SCREEN_WALDA         4

void DoNamingScreen(u8 caseId, u8* dst, u16 monSpecies, u8 monGender, u32 monPersonality, void (*callback)(void));

#endif // GUARD_NAMING_SCREEN_H
