#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u8 mapObjectId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern u16 gUnknown_03006080;
extern u8 gUnknown_03006084[4];
extern struct ApproachingTrainer gApproachingTrainers[2];
extern u8 gNoOfApproachingTrainers;
extern u8 gUnknown_030060AC;
extern u8 gApproachingTrainerId;

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
