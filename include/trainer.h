#ifndef GUARD_TRAINER_H
#define GUARD_TRAINER_H

#include "constants/global.h"
#include "constants/trainers.h"

enum TrainerPicID GetPlayerTrainerPic(enum Gender gender, enum GameVersion version);


static inline u16 GetTrainerPicTag(enum TrainerPicID trainerPicId, bool32 isFrontPic)
{
    return isFrontPic ? trainerPicId : TRAINER_PIC_COUNT + trainerPicId;
}

#endif // GUARD_TRAINER_H
