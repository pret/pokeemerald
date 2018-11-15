#ifndef GUARD_POKEMON_3_H
#define GUARD_POKEMON_3_H

#include <gba/gba.h>

u16 sub_806EFF0(u16);
const u8* GetTrainerClassNameFromId(u16 trainerId);
const u8* GetTrainerNameFromId(u16 trainerId);
void PlayMapChosenOrBattleBGM(u16 song);
u8 GetTrainerEncounterMusicId(u16 trainerOpponentId);

#endif // GUARD_POKEMON_3_H
