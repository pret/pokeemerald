#ifndef GUARD_TRAINER_UTIL_H
#define GUARD_TRAINER_UTIL_H

struct TrainerGenerator
{
    u8 gender:6;
    u8 smartTera:1;
    u8 isFrontier:1;
    u8 trainerClass;
    u8 padding;
    u8 name[TRAINER_NAME_LENGTH + 1];
    struct OriginalTrainerId otID;
    rng_value_t localRngState;
};

rng_value_t GeneratePartySeed(const struct Trainer *trainer);
void GenerateMonFromTrainerMon(struct Pokemon *mon, const struct TrainerMon *trainerMon, struct TrainerGenerator *trainer);
u32 GeneratePersonalityForGender(u32 gender, u32 species);
void MakeTrainerGenerator(struct TrainerGenerator *trainerGen, const struct Trainer *trainer);
void MakePartnerGenerator(struct TrainerGenerator *trainerGen, const struct Trainer *partner);

#endif // GUARD_TRAINER_UTIL_H
