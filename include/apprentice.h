#ifndef GUARD_APPRENTICE_H
#define GUARD_APPRENTICE_H

#include "constants/apprentice.h"

struct ApprenticeTrainer
{
    u8 name[6][PLAYER_NAME_LENGTH + 1]; // For all six languages.
    u16 otId;
    u8 facilityClass;
    u16 species[APPRENTICE_SPECIES_COUNT];
    u8 id;
    u16 speechLost[EASY_CHAT_BATTLE_WORDS_COUNT];
};

extern const struct ApprenticeTrainer gApprentices[];

void CopyFriendsApprenticeChallengeText(u8 saveblockApprenticeId);
void Apprentice_EnableBothScriptContexts(void);
void ResetApprenticeStruct(struct Apprentice *apprentice);
void ResetAllApprenticeData(void);
void CallApprenticeFunction(void);
const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language);

#endif // GUARD_APPRENTICE_H
