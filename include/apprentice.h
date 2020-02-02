#ifndef GUARD_APPRENTICE_H
#define GUARD_APPRENTICE_H

#include "constants/apprentice.h"

struct ApprenticeTrainer
{
    u8 name[NUM_LANGUAGES - 1][PLAYER_NAME_LENGTH + 1]; // For all languages except the unused one.
    u16 otId;
    u8 facilityClass;
    u16 species[APPRENTICE_SPECIES_COUNT];
    u8 id;
    u16 speechLost[EASY_CHAT_BATTLE_WORDS_COUNT];
};

extern const struct ApprenticeTrainer gApprentices[];

void BufferApprenticeChallengeText(u8 saveApprenticeId);
void Apprentice_EnableBothScriptContexts(void);
void ResetApprenticeStruct(struct Apprentice *apprentice);
void ResetAllApprenticeData(void);
void CallApprenticeFunction(void);
const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language);

#endif // GUARD_APPRENTICE_H
