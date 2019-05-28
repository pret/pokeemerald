#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "gym_leader_rematch.h"
#include "international_string_util.h"
#include "main.h"
#include "match_call.h"
#include "overworld.h"
#include "pokemon.h"
#include "pokenav.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "constants/flags.h"
#include "constants/songs.h"

struct Pokenav3Struct
{
    u16 unk0;
    u16 unk2;
    const u8 *unk4;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u32 unk10;
    u32 unk14;
    u32 (*callback)(struct Pokenav3Struct*);
    struct Pokenav3Struct_Unk1C unk1C[99];
};

static u32 sub_81CAB44(struct Pokenav3Struct *);
static u32 sub_81CABFC(struct Pokenav3Struct *);
static u32 sub_81CAC04(struct Pokenav3Struct *);
static u32 sub_81CACB8(struct Pokenav3Struct *);
static u32 sub_81CACF8(struct Pokenav3Struct *);
static u32 sub_81CAD20(int);
static bool32 sub_81CB1D0(void);

extern const u8 gUnknown_08622508[];
extern const u8 gUnknown_0862250A[];
extern const u8 *const gUnknown_08622028[][4];

bool32 sub_81CAAE8(void)
{
    struct Pokenav3Struct *state = AllocSubstruct(5, sizeof(struct Pokenav3Struct));
    if (!state)
        return FALSE;

    state->callback = sub_81CAB44;
    state->unk8 = 0;
    state->unk10 = 0;
    state->unk14 = CreateLoopedTask(sub_81CAD20, 1);
    return TRUE;
}

u32 sub_81CAB24(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->callback(state);
}

void sub_81CAB38(void)
{
    FreePokenavSubstruct(5);
}

static u32 sub_81CAB44(struct Pokenav3Struct *state)
{
    int selectedMatchCall;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return 2;
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return 1;
    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        return 4;
    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        return 3;

    if (gMain.newKeys & A_BUTTON)
    {
        state->callback = sub_81CAC04;
        state->unk0 = 0;
        selectedMatchCall = GetSelectedMatchCall();
        if (!state->unk1C[selectedMatchCall].unk0 || sub_81D17E8(state->unk1C[selectedMatchCall].unk2))
        {
            state->unk4 = gUnknown_0862250A;
            state->unk2 = 2;
        }
        else
        {
            state->unk4 = gUnknown_08622508;
            state->unk2 = 1;
        }

        return 5;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (GetPokenavMode() != POKENAV_MODE_FORCE_CALL_1)
        {
            state->callback = sub_81CABFC;
            return 15;
        }
        else
        {
            PlaySE(SE_HAZURE);
        }
    }

    return 0;
}

static u32 sub_81CABFC(struct Pokenav3Struct *state)
{
    return POKENAV_MENU_4;
}

static u32 sub_81CAC04(struct Pokenav3Struct *state)
{
    if ((gMain.newKeys & DPAD_UP) && state->unk0)
    {
        state->unk0--;
        return 6;
    }

    if ((gMain.newKeys & DPAD_DOWN) && state->unk0 < state->unk2)
    {
        state->unk0++;
        return 6;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        switch (state->unk4[state->unk0])
        {
        case 2:
            state->callback = sub_81CAB44;
            return 7;
        case 0:
            if (GetPokenavMode() == POKENAV_MODE_FORCE_CALL_1)
                SetPokenavMode(POKENAV_MODE_FORCE_CALL_2);

            state->callback = sub_81CACF8;
            if (sub_81CB1D0())
                return 9;

            return 8;
        case 1:
            state->callback = sub_81CACB8;
            return 11;
        }
    }

    if (gMain.newKeys & B_BUTTON)
    {
        state->callback = sub_81CAB44;
        return 7;
    }

    return 0;
}

static u32 sub_81CACB8(struct Pokenav3Struct *state)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return 12;
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return 13;

    if (gMain.newKeys & B_BUTTON)
    {
        state->callback = sub_81CAB44;
        return 14;
    }

    return 0;
}

static u32 sub_81CACF8(struct Pokenav3Struct *state)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        state->callback = sub_81CAB44;
        return 10;
    }

    return 0;
}

static u32 sub_81CAD20(int taskState)
{
    int i, j;
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    switch (taskState)
    {
    case 0:
        state->unk8 = 0;
        state->unkA = 0;
        return LT_INC_AND_CONTINUE;
    case 1:
        for (i = 0, j = state->unk8; i < 30; i++, j++)
        {
            if (MatchCallFlagGetByIndex(j))
            {
                state->unk1C[state->unkA].unk2 = j;
                state->unk1C[state->unkA].unk0 = 1;
                state->unk1C[state->unkA].unk1 = sub_81D16DC(j);
                state->unkA++;
            }

            if (++state->unk8 >= 21) // TODO: This is the size of sMatchCallHeaders
            {
                state->unkC = state->unk8;
                state->unk8 = 0;
                return LT_INC_AND_CONTINUE;
            }
        }

        return LT_CONTINUE;
    case 2:
        for (i = 0, j = state->unk8; i < 30; i++, j++)
        {
            if (!sub_81D1BF8(state->unk8) && sub_81CAE08(state->unk8))
            {
                state->unk1C[state->unkA].unk2 = state->unk8;
                state->unk1C[state->unkA].unk0 = 0;
                state->unk1C[state->unkA].unk1 = sub_81CB0C8(j);
                state->unkA++;
            }

            if (++state->unk8 > REMATCH_TABLE_ENTRIES - 1)
                return LT_INC_AND_CONTINUE;
        }

        return LT_CONTINUE;
    case 3:
        state->unk10 = 1;
        break;
    }

    return LT_FINISH;
}

bool32 sub_81CAE08(int rematchIndex)
{
    if (rematchIndex < REMATCH_TABLE_ENTRIES)
        return FlagGet(FLAG_MATCH_CALL_REGISTERED + rematchIndex);

    return FALSE;
}

int sub_81CAE28(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unk10;
}

int sub_81CAE38(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unkA;
}

int sub_81CAE48(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unkC;
}

int unref_sub_81CAE58(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unkA - state->unkC;
}

int unref_sub_81CAE6C(int arg0)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    arg0 += state->unkC;
    if (arg0 >= state->unkA)
        return REMATCH_TABLE_ENTRIES;

    return state->unk1C[arg0].unk2;
}

struct Pokenav3Struct_Unk1C *sub_81CAE94(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unk1C;
}

u16 sub_81CAEA4(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unk1C[index].unk1;
}

bool32 sub_81CAEBC(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    if (!state->unk1C[index].unk0)
        index = state->unk1C[index].unk2;
    else
        index = MatchCall_GetRematchTableIdx(state->unk1C[index].unk2);

    if (index == REMATCH_TABLE_ENTRIES)
        return FALSE;

    return gSaveBlock1Ptr->trainerRematches[index] != 0;
}

int sub_81CAF04(int index)
{
    int var0;
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    if (!state->unk1C[index].unk0)
    {
        index = GetTrainerIdxByRematchIdx(state->unk1C[index].unk2);
        return gTrainers[index].trainerPic;
    }

    var0 = state->unk1C[index].unk2;
    index = MatchCall_GetRematchTableIdx(var0);
    if (index != REMATCH_TABLE_ENTRIES)
    {
        index = GetTrainerIdxByRematchIdx(index);
        return gTrainers[index].trainerPic;
    }

    index = sub_81D1BD0(var0);
    return gFacilityClassToPicIndex[index];
}

const u8 *sub_81CAF78(int index, u8 *arg1)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    *arg1 = 0;
    if (!Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType))
        return gText_CallCantBeMadeHere;

    if (!state->unk1C[index].unk0)
        *arg1 = SelectMatchCallMessage(GetTrainerIdxByRematchIdx(state->unk1C[index].unk2), gStringVar4);
    else
        MatchCall_GetMessage(state->unk1C[index].unk2, gStringVar4);

    return gStringVar4;
}

const u8 *sub_81CAFD8(int index, int textType)
{
    int var0;
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    if (state->unk1C[index].unk0)
    {
        var0 = MatchCall_GetRematchTableIdx(state->unk1C[index].unk2);
        if (var0 == REMATCH_TABLE_ENTRIES)
            return sub_81D1B40(state->unk1C[index].unk2, textType);
    }
    else
    {
        var0 = state->unk1C[index].unk2;
    }

    return gUnknown_08622028[var0][textType];
}

u16 sub_81CB01C(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unk0;
}

u16 sub_81CB02C(int arg0)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    if (state->unk2 < arg0)
        return 3;

    return state->unk4[arg0];
}

void sub_81CB050(u32 arg0, u8 *str)
{
    struct Pokenav3Struct_Unk1C *var0 = (struct Pokenav3Struct_Unk1C *)arg0;
    const u8 *trainerName;
    const u8 *className;
    if (!var0->unk0)
    {
        int index = GetTrainerIdxByRematchIdx(var0->unk2);
        const struct Trainer *trainer = &gTrainers[index];
        int class = trainer->trainerClass;
        className = gTrainerClassNames[class];
        trainerName = trainer->trainerName;
    }
    else
    {
        sub_81D1A78(var0->unk2, &className, &trainerName);
    }

    if (className && trainerName)
    {
        u8 *str2 = sub_81DB494(str, 7, className, 69);
        sub_81DB494(str2, 7, trainerName, 51);
    }
    else
    {
        sub_81DB494(str, 7, NULL, 120);
    }
}

u8 sub_81CB0C8(int rematchIndex)
{
    int mapGroup = gRematchTable[rematchIndex].mapGroup;
    int mapNum = gRematchTable[rematchIndex].mapNum;
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId;
}

int sub_81CB0E4(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    int count = 1;
    while (++index < state->unkA)
    {
        if (!state->unk1C[index].unk0)
            return count;
        if (sub_81D17E8(state->unk1C[index].unk2))
            return count;

        count++;
    }

    return 0;
}

int sub_81CB128(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    int count = -1;
    while (--index >= 0)
    {
        if (!state->unk1C[index].unk0)
            return count;
        if (sub_81D17E8(state->unk1C[index].unk2))
            return count;

        count--;
    }

    return 0;
}

bool32 unref_sub_81CB16C(void)
{
    int i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (sub_81CAE08(i) && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    for (i = 0; i < 21; i++) // TODO: This is the size of sMatchCallHeaders
    {
        if (MatchCallFlagGetByIndex(i))
        {
            int index = MatchCall_GetRematchTableIdx(i);
            if (gSaveBlock1Ptr->trainerRematches[index])
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 sub_81CB1D0(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    int index = GetSelectedMatchCall();
    if (!state->unk1C[index].unk0)
    {
        if (sub_81CAEA4(index) == gMapHeader.regionMapSectionId)
        {
            if (!gSaveBlock1Ptr->trainerRematches[state->unk1C[index].unk2])
                return TRUE;
        }
    }
    else
    {
        if (state->unk1C[index].unk2 == 11)
        {
            if (sub_81CAEA4(index) == gMapHeader.regionMapSectionId
             && FlagGet(FLAG_BADGE05_GET) == TRUE)
            {
                if (!FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
                    return TRUE;
            }
        }
    }

    return FALSE;
}
