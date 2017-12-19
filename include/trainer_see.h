#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u8 mapObjectId;
    u8 radius;
    u8 field_2;
    u8 field_3;
    const u8 *trainerScriptPtr;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
};

extern struct ApproachingTrainer gApproachingTrainers[];

void sub_80B4578(struct MapObject *);
u8 sub_80B47BC(void);
void sub_8155D78(struct MapObject *);

#endif //GUARD_TRAINER_SEE_H
