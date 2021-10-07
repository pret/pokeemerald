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
#include "constants/songs.h"

struct Pokenav3Struct
{
    u16 optionCursorPos;
    u16 maxOptionId;
    const u8 *matchCallOptions;
    u16 headerId;
    u16 numRegistered;
    u16 unkC;
    u32 unk10;
    u32 unk14;
    u32 (*callback)(struct Pokenav3Struct*);
    struct PokenavMatchCallEntries matchCallEntries[MAX_REMATCH_ENTRIES - 1];
};

static u32 CB2_HandleMatchCallInput(struct Pokenav3Struct *);
static u32 GetExitMatchCallMenuId(struct Pokenav3Struct *);
static u32 CB2_HandleMatchCallOptionsInput(struct Pokenav3Struct *);
static u32 CB2_HandleCheckPageInput(struct Pokenav3Struct *);
static u32 CB2_HandleCallInput(struct Pokenav3Struct *);
static u32 sub_81CAD20(s32);
static bool32 sub_81CB1D0(void);

#include "data/text/match_call_messages.h"

static const u8 sMatchCallOptionsNoCheckPage[] =
{
    MATCH_CALL_OPTION_CALL,
    MATCH_CALL_OPTION_CANCEL
};

static const u8 sMatchCallOptionsHasCheckPage[] =
{
    MATCH_CALL_OPTION_CALL,
    MATCH_CALL_OPTION_CHECK,
    MATCH_CALL_OPTION_CANCEL
};

bool32 PokenavCallback_Init_MatchCall(void)
{
    struct Pokenav3Struct *state = AllocSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN, sizeof(struct Pokenav3Struct));
    if (!state)
        return FALSE;

    state->callback = CB2_HandleMatchCallInput;
    state->headerId = 0;
    state->unk10 = 0;
    state->unk14 = CreateLoopedTask(sub_81CAD20, 1);
    return TRUE;
}

u32 GetMatchCallCallback(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->callback(state);
}

void FreeMatchCallSubstruct1(void)
{
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
}

static u32 CB2_HandleMatchCallInput(struct Pokenav3Struct *state)
{
    int selection;

    if (JOY_REPEAT(DPAD_UP))
        return POKENAV_MC_FUNC_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        return POKENAV_MC_FUNC_DOWN;
    if (JOY_REPEAT(DPAD_LEFT))
        return POKENAV_MC_FUNC_PG_UP;
    if (JOY_REPEAT(DPAD_RIGHT))
        return POKENAV_MC_FUNC_PG_DOWN;

    if (JOY_NEW(A_BUTTON))
    {
        state->callback = CB2_HandleMatchCallOptionsInput;
        state->optionCursorPos = 0;
        selection = GetSelectedPokenavListIndex();

        if (!state->matchCallEntries[selection].isSpecialTrainer || MatchCall_HasCheckPage(state->matchCallEntries[selection].headerId))
        {
            state->matchCallOptions = sMatchCallOptionsHasCheckPage;
            state->maxOptionId = ARRAY_COUNT(sMatchCallOptionsHasCheckPage) - 1;
        }
        else
        {
            state->matchCallOptions = sMatchCallOptionsNoCheckPage;
            state->maxOptionId = ARRAY_COUNT(sMatchCallOptionsNoCheckPage) - 1;
        }

        return POKENAV_MC_FUNC_SELECT;
    }

    if (JOY_NEW(B_BUTTON))
    {
        if (GetPokenavMode() != POKENAV_MODE_FORCE_CALL_READY)
        {
            state->callback = GetExitMatchCallMenuId;
            return POKENAV_MC_FUNC_EXIT;
        }
        else
        {
            // Cant exit Match Call menu before calling Mr Stone during tutorial
            PlaySE(SE_FAILURE);
        }
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 GetExitMatchCallMenuId(struct Pokenav3Struct *state)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_MATCH_CALL;
}

static u32 CB2_HandleMatchCallOptionsInput(struct Pokenav3Struct *state)
{
    if ((JOY_NEW(DPAD_UP)) && state->optionCursorPos)
    {
        state->optionCursorPos--;
        return POKENAV_MC_FUNC_MOVE_OPTIONS_CURSOR;
    }

    if ((JOY_NEW(DPAD_DOWN)) && state->optionCursorPos < state->maxOptionId)
    {
        state->optionCursorPos++;
        return POKENAV_MC_FUNC_MOVE_OPTIONS_CURSOR;
    }

    if (JOY_NEW(A_BUTTON))
    {
        switch (state->matchCallOptions[state->optionCursorPos])
        {
        case MATCH_CALL_OPTION_CANCEL:
            state->callback = CB2_HandleMatchCallInput;
            return POKENAV_MC_FUNC_CANCEL;
        case MATCH_CALL_OPTION_CALL:
            if (GetPokenavMode() == POKENAV_MODE_FORCE_CALL_READY)
                SetPokenavMode(POKENAV_MODE_FORCE_CALL_EXIT);

            state->callback = CB2_HandleCallInput;
            if (sub_81CB1D0())
                return POKENAV_MC_FUNC_NEARBY_MSG;

            return POKENAV_MC_FUNC_CALL_MSG;
        case MATCH_CALL_OPTION_CHECK:
            state->callback = CB2_HandleCheckPageInput;
            return POKENAV_MC_FUNC_SHOW_CHECK_PAGE;
        }
    }

    if (JOY_NEW(B_BUTTON))
    {
        state->callback = CB2_HandleMatchCallInput;
        return POKENAV_MC_FUNC_CANCEL;
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 CB2_HandleCheckPageInput(struct Pokenav3Struct *state)
{
    if (JOY_REPEAT(DPAD_UP))
        return POKENAV_MC_FUNC_CHECK_PAGE_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        return POKENAV_MC_FUNC_CHECK_PAGE_DOWN;

    if (JOY_NEW(B_BUTTON))
    {
        state->callback = CB2_HandleMatchCallInput;
        return POKENAV_MC_FUNC_EXIT_CHECK_PAGE;
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 CB2_HandleCallInput(struct Pokenav3Struct *state)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        state->callback = CB2_HandleMatchCallInput;
        return POKENAV_MC_FUNC_10;
    }

    return POKENAV_MC_FUNC_NONE;
}

static u32 sub_81CAD20(s32 taskState)
{
    int i, j;
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    switch (taskState)
    {
    case 0:
        state->headerId = 0;
        state->numRegistered = 0;
        return LT_INC_AND_CONTINUE;
    case 1:
        for (i = 0, j = state->headerId; i < 30; i++, j++)
        {
            if (MatchCall_GetEnabled(j))
            {
                state->matchCallEntries[state->numRegistered].headerId = j;
                state->matchCallEntries[state->numRegistered].isSpecialTrainer = TRUE;
                state->matchCallEntries[state->numRegistered].mapSec = MatchCall_GetMapSec(j);
                state->numRegistered++;
            }

            if (++state->headerId >= MC_HEADER_COUNT)
            {
                state->unkC = state->headerId;
                state->headerId = 0;
                return LT_INC_AND_CONTINUE;
            }
        }

        return LT_CONTINUE;
    case 2:
        for (i = 0, j = state->headerId; i < 30; i++, j++)
        {
            if (!MatchCall_HasRematchId(state->headerId) && IsRematchEntryRegistered(state->headerId))
            {
                state->matchCallEntries[state->numRegistered].headerId = state->headerId;
                state->matchCallEntries[state->numRegistered].isSpecialTrainer = FALSE;
                state->matchCallEntries[state->numRegistered].mapSec = GetMatchTableMapSectionId(j);
                state->numRegistered++;
            }

            if (++state->headerId > REMATCH_TABLE_ENTRIES - 1)
                return LT_INC_AND_CONTINUE;
        }

        return LT_CONTINUE;
    case 3:
        state->unk10 = 1;
        break;
    }

    return LT_FINISH;
}

bool32 IsRematchEntryRegistered(int rematchIndex)
{
    if (rematchIndex < REMATCH_TABLE_ENTRIES)
        return FlagGet(FLAG_MATCH_CALL_REGISTERED + rematchIndex);

    return FALSE;
}

int sub_81CAE28(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->unk10;
}

int GetNumberRegistered(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->numRegistered;
}

int sub_81CAE48(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->unkC;
}

int unref_sub_81CAE58(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->numRegistered - state->unkC;
}

int unref_sub_81CAE6C(int arg0)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    arg0 += state->unkC;
    if (arg0 >= state->numRegistered)
        return REMATCH_TABLE_ENTRIES;

    return state->matchCallEntries[arg0].headerId;
}

struct PokenavMatchCallEntries *sub_81CAE94(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->matchCallEntries;
}

u16 GetMatchCallMapSec(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->matchCallEntries[index].mapSec;
}

bool32 ShouldDrawRematchPokeballIcon(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    if (!state->matchCallEntries[index].isSpecialTrainer)
        index = state->matchCallEntries[index].headerId;
    else
        index = MatchCall_GetRematchTableIdx(state->matchCallEntries[index].headerId);

    if (index == REMATCH_TABLE_ENTRIES)
        return FALSE;

    return gSaveBlock1Ptr->trainerRematches[index] != 0;
}

int GetMatchCallTrainerPic(int index)
{
    int headerId;
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    if (!state->matchCallEntries[index].isSpecialTrainer)
    {
        index = GetTrainerIdxByRematchIdx(state->matchCallEntries[index].headerId);
        return gTrainers[index].trainerPic;
    }

    headerId = state->matchCallEntries[index].headerId;
    index = MatchCall_GetRematchTableIdx(headerId);
    if (index != REMATCH_TABLE_ENTRIES)
    {
        index = GetTrainerIdxByRematchIdx(index);
        return gTrainers[index].trainerPic;
    }

    index = MatchCall_GetOverrideFacilityClass(headerId);
    return gFacilityClassToPicIndex[index];
}

const u8 *GetMatchCallMessageText(int index, u8 *arg1)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    *arg1 = 0;
    if (!Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType))
        return gText_CallCantBeMadeHere;

    if (!state->matchCallEntries[index].isSpecialTrainer)
        *arg1 = SelectMatchCallMessage(GetTrainerIdxByRematchIdx(state->matchCallEntries[index].headerId), gStringVar4);
    else
        MatchCall_GetMessage(state->matchCallEntries[index].headerId, gStringVar4);

    return gStringVar4;
}

const u8 *GetMatchCallFlavorText(int index, int checkPageEntry)
{
    int rematchId;
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    if (state->matchCallEntries[index].isSpecialTrainer)
    {
        rematchId = MatchCall_GetRematchTableIdx(state->matchCallEntries[index].headerId);
        if (rematchId == REMATCH_TABLE_ENTRIES)
            return MatchCall_GetOverrideFlavorText(state->matchCallEntries[index].headerId, checkPageEntry);
    }
    else
    {
        rematchId = state->matchCallEntries[index].headerId;
    }

    return gMatchCallFlavorTexts[rematchId][checkPageEntry];
}

u16 GetMatchCallOptionCursorPos(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    return state->optionCursorPos;
}

u16 GetMatchCallOptionId(int optionId)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    if (state->maxOptionId < optionId)
        return MATCH_CALL_OPTION_COUNT;

    return state->matchCallOptions[optionId];
}

void BufferMatchCallNameAndDesc(struct PokenavMatchCallEntries *matchCallEntry, u8 *str)
{
    const u8 *trainerName;
    const u8 *className;
    if (!matchCallEntry->isSpecialTrainer)
    {
        int index = GetTrainerIdxByRematchIdx(matchCallEntry->headerId);
        const struct Trainer *trainer = &gTrainers[index];
        int class = trainer->trainerClass;
        className = gTrainerClassNames[class];
        trainerName = trainer->trainerName;
    }
    else
    {
        MatchCall_GetNameAndDesc(matchCallEntry->headerId, &className, &trainerName);
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

u8 GetMatchTableMapSectionId(int rematchIndex)
{
    int mapGroup = gRematchTable[rematchIndex].mapGroup;
    int mapNum = gRematchTable[rematchIndex].mapNum;
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId;
}

int GetIndexDeltaOfNextCheckPageDown(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    int count = 1;
    while (++index < state->numRegistered)
    {
        if (!state->matchCallEntries[index].isSpecialTrainer)
            return count;
        if (MatchCall_HasCheckPage(state->matchCallEntries[index].headerId))
            return count;

        count++;
    }

    return 0;
}

int GetIndexDeltaOfNextCheckPageUp(int index)
{
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    int count = -1;
    while (--index >= 0)
    {
        if (!state->matchCallEntries[index].isSpecialTrainer)
            return count;
        if (MatchCall_HasCheckPage(state->matchCallEntries[index].headerId))
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
        if (IsRematchEntryRegistered(i) && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    for (i = 0; i < MC_HEADER_COUNT; i++)
    {
        if (MatchCall_GetEnabled(i))
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
    struct Pokenav3Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_MAIN);
    int selection = GetSelectedPokenavListIndex();
    if (!state->matchCallEntries[selection].isSpecialTrainer)
    {
        if (GetMatchCallMapSec(selection) == gMapHeader.regionMapSectionId)
        {
            if (!gSaveBlock1Ptr->trainerRematches[state->matchCallEntries[selection].headerId])
                return TRUE;
        }
    }
    else
    {
        if (state->matchCallEntries[selection].headerId == MC_HEADER_WATTSON)
        {
            if (GetMatchCallMapSec(selection) == gMapHeader.regionMapSectionId
             && FlagGet(FLAG_BADGE05_GET) == TRUE)
            {
                if (!FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
                    return TRUE;
            }
        }
    }

    return FALSE;
}
