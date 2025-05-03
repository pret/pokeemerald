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
void Apprentice_ScriptContext_Enable(void);
void ResetApprenticeStruct(struct Apprentice *apprentice);
void ResetAllApprenticeData(void);
void CallApprenticeFunction(void);
const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language);

static void Script_GivenApprenticeLvlMode(void);
static void Script_SetApprenticeLvlMode(void);
static void Script_SetApprenticeId(void);
static void ShuffleApprenticeSpecies(void);
static void Script_SetRandomQuestionData(void);
static void IncrementQuestionsAnswered(void);
static void IsFinalQuestion(void);
static void Script_CreateApprenticeMenu(void);
static void Script_PrintApprenticeMessage(void);
static void Script_ResetPlayerApprentice(void);
static void GetShouldCheckApprenticeGone(void);
static void ApprenticeGetQuestion(void);
static void GetNumApprenticePartyMonsAssigned(void);
static void SetApprenticePartyMon(void);
static void InitQuestionData(void);
static void FreeQuestionData(void);
static void ApprenticeBufferString(void);
static void SetApprenticeMonMove(void);
static void SetLeadApprenticeMon(void);
static void Script_ApprenticeOpenBagMenu(void);
static void TrySetApprenticeHeldItem(void);
static void SaveApprentice(void);
static void SetSavedApprenticeTrainerGfxId(void);
static void SetPlayerApprenticeTrainerGfxId(void);
static void GetShouldApprenticeLeave(void);
static void ShiftSavedApprentices(void);

#endif // GUARD_APPRENTICE_H
