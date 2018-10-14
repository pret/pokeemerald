#ifndef GUARD_APPRENTICE_H
#define GUARD_APPRENTICE_H

#define APPRENTICE_SPECIES_COUNT 10

struct ApprenticeTrainer
{
    u8 name[6][PLAYER_NAME_LENGTH + 1]; // For all six languages.
    u16 otId;
    u8 facilityClass;
    u16 species[APPRENTICE_SPECIES_COUNT];
    u8 rest[14];
};

extern const struct ApprenticeTrainer gApprentices[];

const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language);

#endif // GUARD_APPRENTICE_H
