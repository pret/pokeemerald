#ifndef GUARD_APPRENTICE_H
#define GUARD_APPRENTICE_H

#define APPRENTICE_SPECIES_COUNT 10

struct ApprenticeTrainer
{
    u8 name[6][PLAYER_NAME_LENGTH + 1]; // For all six languages.
    u16 otId;
    u16 facilityClass;
    u16 species[APPRENTICE_SPECIES_COUNT];
    u8 rest[14];
};

extern const struct ApprenticeTrainer gApprentices[];

#endif // GUARD_APPRENTICE_H
