#ifndef GUARD_MYSTERY_GIFT_H
#define GUARD_MYSTERY_GIFT_H

#include "main.h"
#include "constants/mystery_gift.h"

struct MysteryGiftLinkGameData
{
    // It's possible these first 5 fields had some other meaningful purpose,
    // but they are only ever set when creating this data and read to validate it.
    u32 validationVar;
    u16 validationFlag1;
    u32 validationFlag2;
    u16 validationGiftType1;
    u32 validationGiftType2;
    u16 flagId;
    u16 questionnaireWords[NUM_QUESTIONNAIRE_WORDS];
    struct WonderCardMetadata cardMetadata;
    u8 maxStamps;
    u8 playerName[PLAYER_NAME_LENGTH];
    u8 playerTrainerId[TRAINER_ID_LENGTH];
    u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    u8 romHeaderGameCode[GAME_CODE_LENGTH];
    u8 romHeaderSoftwareVersion;
};

void ClearMysteryGift(void);
struct WonderNews *GetSavedWonderNews(void);
struct WonderCard *GetSavedWonderCard(void);
struct WonderCardMetadata *GetSavedWonderCardMetadata(void);
struct WonderNewsMetadata *GetSavedWonderNewsMetadata(void);
u16 *GetQuestionnaireWordsPtr(void);
void ClearSavedWonderNewsAndRelated(void);
void ClearSavedWonderCardAndRelated(void);
bool32 SaveWonderNews(const struct WonderNews *news);
bool32 SaveWonderCard(const struct WonderCard *card);
bool32 ValidateSavedWonderNews(void);
bool32 ValidateSavedWonderCard(void);
bool32 IsWonderNewsSameAsSaved(const u8 *news);
bool32 IsSendingSavedWonderNewsAllowed(void);
bool32 IsSendingSavedWonderCardAllowed(void);
u16 GetWonderCardFlagID(void);
void DisableWonderCardSending(struct WonderCard *card);
bool32 IsSavedWonderCardGiftNotReceived(void);
bool32 MysteryGift_TrySaveStamp(const u16 *stamp);
void MysteryGift_LoadLinkGameData(struct MysteryGiftLinkGameData *data, bool32 isWonderNews);
bool32 MysteryGift_ValidateLinkGameData(const struct MysteryGiftLinkGameData *data, bool32 isWonderNews);
u32 MysteryGift_CompareCardFlags(const u16 *flagId, const struct MysteryGiftLinkGameData *data, const void *unused);
u32 MysteryGift_CheckStamps(const u16 *stamp, const struct MysteryGiftLinkGameData *data, const void *unused);
bool32 MysteryGift_DoesQuestionnaireMatch(const struct MysteryGiftLinkGameData *data, const u16 *words);
u16 MysteryGift_GetCardStatFromLinkData(const struct MysteryGiftLinkGameData *data, u32 stat);
u16 MysteryGift_GetCardStat(u32 stat);
void MysteryGift_DisableStats(void);
bool32 MysteryGift_TryEnableStatsByFlagId(u16 flagId);
void MysteryGift_TryIncrementStat(u32 stat, u32 trainerId);

#endif //GUARD_MYSTERY_GIFT_H
