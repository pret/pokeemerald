#ifndef GUARD_MEVENT_H
#define GUARD_MEVENT_H

struct MEvent_Str_1
{
    u16 unk_000;
    size_t unk_004;
    const void * unk_008;
};

struct MEvent_Str_2
{
    u8 fill_00[0x40];
};

struct MEventStruct_Unk1442CC
{
    u32 unk_00;
    u16 unk_04;
    u32 unk_08;
    u16 unk_0C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16[NUM_QUESTIONNAIRE_WORDS];
    struct MEventBuffer_3430_Sub unk_20;
    u8 unk_44;
    u8 unk_45[7];
    u8 unk_4C[4];
    u16 unk_50[6];
    u8 unk_5C[4];
    u8 unk_60;
};

void sub_801AFD8(void);
struct WonderNews *GetSavedWonderNews(void);
struct WonderCard *GetSavedWonderCard(void);
struct MEventBuffer_3430_Sub *sav1_get_mevent_buffer_2(void);
struct MysteryEventStruct *sub_801B044(void);
u16 *GetQuestionnaireWordsPtr(void);
void DestroyWonderNews(void);
bool32 sub_801B078(const struct WonderNews *src);
bool32 ValidateReceivedWonderNews(void);
bool32 WonderNews_Test_Unk_02(void);
bool32 sub_801B1A4(const u8 *src);
void DestroyWonderCard(void);
bool32 sub_801B21C(const struct WonderCard *data);
bool32 ValidateReceivedWonderCard(void);
bool32 WonderCard_Test_Unk_08_6(void);
u16 GetWonderCardFlagID(void);
void WonderCard_ResetInternalReceivedFlag(struct WonderCard *buffer);
bool32 CheckReceivedGiftFromWonderCard(void);
bool32 sub_801B508(const u16 *data);
void sub_801B580(struct MEventStruct_Unk1442CC *data, bool32 a1);
bool32 sub_801B6A0(const struct MEventStruct_Unk1442CC *data, bool32 a1);
u32 sub_801B6EC(const u16 *a0, const struct MEventStruct_Unk1442CC *a1, const void *unused);
u32 sub_801B708(const u16 *a0, const struct MEventStruct_Unk1442CC *a1, const void *unused);
bool32 MEventStruct_Unk1442CC_CompareField_unk_16(const struct MEventStruct_Unk1442CC *a0, const u16 *a1);
u16 MEventStruct_Unk1442CC_GetValueNFrom_unk_20(const struct MEventStruct_Unk1442CC *a0, u32 command);
u16 mevent_081445C0(u32 command);
void ResetReceivedWonderCardFlag(void);
bool32 MEventHandleReceivedWonderCard(u16 a0);

#endif //GUARD_MEVENT_H
