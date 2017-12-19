#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u8 mapObjectId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern struct ApproachingTrainer gApproachingTrainers[2];

bool8 CheckForTrainersWantingBattle(void);
void sub_80B4578(struct MapObject *var);
void EndTrainerApproach(void);
void sub_80B45D0(void);
u8 FldEff_ExclamationMarkIcon1(void);
u8 FldEff_ExclamationMarkIcon2(void);
u8 FldEff_HeartIcon(void);
u8 GetCurrentApproachingTrainerMapObjectId(void);
u8 GetChosenApproachingTrainerMapObjectId(u8 arrayId);
void sub_80B4808(void);

#endif // GUARD_TRAINER_SEE_H
