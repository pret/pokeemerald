#include "global.h"
#include "malloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"
#include "field_weather.h"
#include "palette.h"
#include "pokemon_storage_system.h"
#include "pokenav.h"

#define LOOPED_TASK_DECODE_STATE(action) (action - 5)

#define LOOPED_TASK_ID(primary, secondary) (((secondary) << 16) |(primary))
#define LOOPED_TASK_PRIMARY_ID(taskId) (taskId & 0xFFFF)
#define LOOPED_TASK_SECONDARY_ID(taskId) (taskId >> 16)

#define SUBSTRUCT_COUNT 19

struct PokenavResources
{
    u32 (*currentMenuCb1)(void);
    u32 currentMenuIndex;
    u16 mode;
    u16 fieldA;
    bool32 hasAnyRibbons;
    void *field10[SUBSTRUCT_COUNT];
};

struct UnknownPokenavCallbackStruct
{
    bool32 (*unk0)(void);
    u32 (*unk4)(void);
    bool32 (*unk8)(void);
    void (*unkC)(s32);
    u32 (*unk10)(void);
    void (*unk14)(void);
    void (*unk18)(void);
};

static u32 sub_81C75E0(void);
static u32 sub_81C75D4(void);
static bool32 SetActivePokenavMenu(u32 menuId);
static bool32 AnyMonHasRibbon(void);
static void InitPokenavResources(struct PokenavResources *a0);
static void InitKeys_(void);
static void FreePokenavResources(void);
static void VBlankCB_Pokenav(void);
static void CB2_Pokenav(void);
static void Task_RunLoopedTask_LinkMode(u8 a0);
static void Task_RunLoopedTask(u8 taskId);
static void Task_Pokenav(u8 taskId);
static void CB2_InitPokenavForTutorial(void);

const struct UnknownPokenavCallbackStruct PokenavMenuCallbacks[15] =
{
    {
        .unk0 = PokenavCallback_Init_0,
        .unk4 = sub_81C941C,
        .unk8 = sub_81C9924,
        .unkC = sub_81C9990,
        .unk10 = sub_81C99C0,
        .unk14 = sub_81C9430,
        .unk18 = sub_81C99D4,
    },
    {
        .unk0 = PokenavCallback_Init_0,
        .unk4 = sub_81C941C,
        .unk8 = sub_81C9940,
        .unkC = sub_81C9990,
        .unk10 = sub_81C99C0,
        .unk14 = sub_81C9430,
        .unk18 = sub_81C99D4,
    },
    {
        .unk0 = PokenavCallback_Init_2,
        .unk4 = sub_81C941C,
        .unk8 = sub_81C9940,
        .unkC = sub_81C9990,
        .unk10 = sub_81C99C0,
        .unk14 = sub_81C9430,
        .unk18 = sub_81C99D4,
    },
    {
        .unk0 = PokenavCallback_Init_3,
        .unk4 = sub_81C941C,
        .unk8 = sub_81C9940,
        .unkC = sub_81C9990,
        .unk10 = sub_81C99C0,
        .unk14 = sub_81C9430,
        .unk18 = sub_81C99D4,
    },
    {
        .unk0 = PokenavCallback_Init_4,
        .unk4 = sub_81C941C,
        .unk8 = sub_81C9940,
        .unkC = sub_81C9990,
        .unk10 = sub_81C99C0,
        .unk14 = sub_81C9430,
        .unk18 = sub_81C99D4,
    },
    {
        .unk0 = PokenavCallback_Init_5,
        .unk4 = sub_81C941C,
        .unk8 = sub_81C9940,
        .unkC = sub_81C9990,
        .unk10 = sub_81C99C0,
        .unk14 = sub_81C9430,
        .unk18 = sub_81C99D4,
    },
    {
        .unk0 = PokenavCallback_Init_6,
        .unk4 = sub_81CC554,
        .unk8 = sub_81CC5F4,
        .unkC = sub_81CC62C,
        .unk10 = sub_81CC65C,
        .unk14 = sub_81CC524,
        .unk18 = sub_81CC670,
    },
    {
        .unk0 = PokenavCallback_Init_7,
        .unk4 = sub_81CD070,
        .unk8 = sub_81CDDD4,
        .unkC = sub_81CDE2C,
        .unk10 = sub_81CDE64,
        .unk14 = sub_81CD1C0,
        .unk18 = sub_81CECA0,
    },
    {
        .unk0 = PokenavCallback_Init_8,
        .unk4 = sub_81CEFDC,
        .unk8 = sub_81CF330,
        .unkC = sub_81CF3A0,
        .unk10 = sub_81CF3D0,
        .unk14 = sub_81CEFF0,
        .unk18 = sub_81CF3F8,
    },
    {
        .unk0 = PokenavCallback_Init_9,
        .unk4 = sub_81CD070,
        .unk8 = sub_81CDDD4,
        .unkC = sub_81CDE2C,
        .unk10 = sub_81CDE64,
        .unk14 = sub_81CD1C0,
        .unk18 = sub_81CECA0,
    },
    {
        .unk0 = PokenavCallback_Init_10,
        .unk4 = sub_81CEFDC,
        .unk8 = sub_81CF368,
        .unkC = sub_81CF3A0,
        .unk10 = sub_81CF3D0,
        .unk14 = sub_81CEFF0,
        .unk18 = sub_81CF3F8,
    },
    {
        .unk0 = PokenavCallback_Init_11,
        .unk4 = sub_81CAB24,
        .unk8 = sub_81CB260,
        .unkC = sub_81CB29C,
        .unk10 = sub_81CB2CC,
        .unk14 = sub_81CAB38,
        .unk18 = sub_81CB2E0,
    },
    {
        .unk0 = PokenavCallback_Init_12,
        .unk4 = sub_81CFA34,
        .unk8 = sub_81CFDD0,
        .unkC = sub_81CFE40,
        .unk10 = sub_81CFE70,
        .unk14 = sub_81CFA48,
        .unk18 = sub_81CFE98,
    },
    {
        .unk0 = PokenavCallback_Init_13,
        .unk4 = sub_81D04A0,
        .unk8 = sub_81D0978,
        .unkC = sub_81D09B0,
        .unk10 = sub_81D09E0,
        .unk14 = sub_81D04B8,
        .unk18 = sub_81D09F4,
    },
    {
        .unk0 = PokenavCallback_Init_14,
        .unk4 = sub_81CFA34,
        .unk8 = sub_81CFE08,
        .unkC = sub_81CFE40,
        .unk10 = sub_81CFE70,
        .unk14 = sub_81CFA48,
        .unk18 = sub_81CFE98,
    },
};

EWRAM_DATA u8 gNextLoopedTaskId = 0;
EWRAM_DATA struct PokenavResources *gPokenavResources = NULL;

// code
u32 CreateLoopedTask(LoopedTask loopedTask, u32 priority)
{
    u16 taskId;

    if (!IsUpdateLinkStateCBActive())
        taskId = CreateTask(Task_RunLoopedTask, priority);
    else
        taskId = CreateTask(Task_RunLoopedTask_LinkMode, priority);

    SetWordTaskArg(taskId, 1, (u32)loopedTask);

    gTasks[taskId].data[3] = gNextLoopedTaskId;
    return LOOPED_TASK_ID(taskId, gNextLoopedTaskId++);
}

bool32 IsLoopedTaskActive(u32 taskId)
{
    u32 primaryId = LOOPED_TASK_PRIMARY_ID(taskId);
    u32 secondaryId = LOOPED_TASK_SECONDARY_ID(taskId);

    if (gTasks[primaryId].isActive
        && (gTasks[primaryId].func == Task_RunLoopedTask || gTasks[primaryId].func == Task_RunLoopedTask_LinkMode)
        && gTasks[primaryId].data[3] == secondaryId)
        return TRUE;
    else
        return FALSE;
}

bool32 FuncIsActiveLoopedTask(LoopedTask func)
{
    int i;
    for (i = 0; i < NUM_TASKS; i++)
    {
        if (gTasks[i].isActive
            && (gTasks[i].func == Task_RunLoopedTask || gTasks[i].func == Task_RunLoopedTask_LinkMode)
            && (LoopedTask)GetWordTaskArg(i, 1) == func)
            return TRUE;
    }
    return FALSE;
}

static void Task_RunLoopedTask(u8 taskId)
{
    LoopedTask loopedTask = (LoopedTask)GetWordTaskArg(taskId, 1);
    s16 *state = &gTasks[taskId].data[0];
    bool32 exitLoop = FALSE;

    while (!exitLoop)
    {
        u32 action = loopedTask(*state);
        switch (action)
        {
        case LT_INC_AND_CONTINUE:
            (*state)++;
            break;
        case LT_INC_AND_PAUSE:
            (*state)++;
            return;
        case LT_FINISH:
            DestroyTask(taskId);
            return;
        // case LT_SET_STATE:
        default:
            *state = LOOPED_TASK_DECODE_STATE(action);
            break;
        case LT_CONTINUE:
            break;
        case LT_PAUSE:
            return;
        }
    }
}

// Every "Continue" action pauses instead.
static void Task_RunLoopedTask_LinkMode(u8 taskId)
{
    LoopedTask task;
    s16 *state;
    u32 action;

    if (sub_8087598())
        return;

    task = (LoopedTask)GetWordTaskArg(taskId, 1);
    state = &gTasks[taskId].data[0];
    action = task(*state);
    switch (action)
    {
    case LT_INC_AND_PAUSE:
    case LT_INC_AND_CONTINUE:
        (*state)++;
        break;
    case LT_FINISH:
        DestroyTask(taskId);
        break;
    // case: LT_SET_STATE:
    default:
        *state = LOOPED_TASK_DECODE_STATE(action);
        break;
    case LT_PAUSE:
    case LT_CONTINUE:
        break;
    }
}

void CB2_InitPokeNav(void)
{
    gPokenavResources = Alloc(sizeof(*gPokenavResources));
    if (gPokenavResources == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
    else
    {
        InitPokenavResources(gPokenavResources);
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(Task_Pokenav, 0);
        SetMainCallback2(CB2_Pokenav);
        SetVBlankCallback(VBlankCB_Pokenav);
    }
}

void OpenPokenavForTutorial(void)
{
    SetMainCallback2(CB2_InitPokenavForTutorial);
    FadeScreen(1, 0);
}

static void CB2_InitPokenavForTutorial(void)
{
    UpdatePaletteFade();
    if (gPaletteFade.active)
        return;

    gPokenavResources = Alloc(sizeof(*gPokenavResources));
    if (gPokenavResources == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else
    {
        InitPokenavResources(gPokenavResources);
        gPokenavResources->mode = POKENAV_MODE_FORCE_CALL_1;
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(NULL);
        CreateTask(Task_Pokenav, 0);
        SetMainCallback2(CB2_Pokenav);
        SetVBlankCallback(VBlankCB_Pokenav);
    }
}

static void FreePokenavResources(void)
{
    int i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        FreePokenavSubstruct(i);

    FREE_AND_SET_NULL(gPokenavResources);
    InitKeys();
}

static void InitPokenavResources(struct PokenavResources *a0)
{
    int i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        a0->field10[i] = NULL;

    a0->mode = POKENAV_MODE_NORMAL;
    a0->currentMenuIndex = 0;
    a0->hasAnyRibbons = AnyMonHasRibbon();
    a0->currentMenuCb1 = NULL;
}

static bool32 AnyMonHasRibbon(void)
{
    int i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i],  MON_DATA_SANITY_HAS_SPECIES)
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_RIBBON_COUNT) != 0)
        {
            return TRUE;
        }
    }

    for (j = 0; j < TOTAL_BOXES_COUNT; j++)
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (CheckBoxMonSanityAt(j, i)
                && GetBoxMonDataAt(j, i, MON_DATA_RIBBON_COUNT) != 0)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static void CB2_Pokenav(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Pokenav(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void Task_Pokenav(u8 taskId)
{
    u32 v1;
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        InitPokenavMainMenu();
        data[0] = 1;
        break;
    case 1:
        // Wait for LoopedTask_InitPokenavMenu to finish
        if (PokenavMainMenuLoopedTaskIsActive())
            break;
        SetActivePokenavMenu(POKENAV_MENU_0);
        data[0] = 4;
        break;
    case 2:
        if (sub_81C786C())
            break;
        data[0] = 3;
    case 3:
        v1 = sub_81C75E0();
        if (v1 == -1)
        {
            ShutdownPokenav();
            data[0] = 5;
        }
        else if (v1 >= POKENAV_MENU_IDS_START)
        {
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex].unk18();
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex].unk14();
            if (SetActivePokenavMenu(v1))
            {
                data[0] = 4;
            }
            else
            {
                ShutdownPokenav();
                data[0] = 5;
            }
        }
        else if (v1 != 0)
        {
            sub_81C7850(v1);
            if (sub_81C786C())
                data[0] = 2;
        }
        break;
    case 4:
        if (!sub_81C75D4())
            data[0] = 3;
        break;
    case 5:
        if (!WaitForPokenavShutdownFade())
        {
            bool32 calledFromScript = (gPokenavResources->mode != POKENAV_MODE_NORMAL);

            sub_81C9430();
            FreePokenavResources();
            if (calledFromScript)
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            else
                SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        break;
    }
}

static bool32 SetActivePokenavMenu(u32 menuId)
{
    u32 index = menuId - POKENAV_MENU_IDS_START;

    InitKeys_();
    if (!PokenavMenuCallbacks[index].unk0())
        return FALSE;
    if (!PokenavMenuCallbacks[index].unk8())
        return FALSE;

    sub_81C7834(PokenavMenuCallbacks[index].unkC, PokenavMenuCallbacks[index].unk10);
    gPokenavResources->currentMenuCb1 = PokenavMenuCallbacks[index].unk4;
    gPokenavResources->currentMenuIndex = index;
    return TRUE;
}

static u32 sub_81C75D4(void)
{
    return sub_81C786C();
}

static u32 sub_81C75E0(void)
{
    return gPokenavResources->currentMenuCb1();
}

static void InitKeys_(void)
{
    InitKeys();
}

void SetVBlankCallback_(IntrCallback callback)
{
    SetVBlankCallback(callback);
}

void SetPokenavVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_Pokenav);
}

void *AllocSubstruct(u32 index, u32 size)
{
    gPokenavResources->field10[index] = Alloc(size);
    return gPokenavResources->field10[index];
}

void *GetSubstructPtr(u32 index)
{
    return gPokenavResources->field10[index];
}

void FreePokenavSubstruct(u32 index)
{
    if (gPokenavResources->field10[index] != NULL)
        FREE_AND_SET_NULL(gPokenavResources->field10[index]);
}

u32 GetPokenavMode(void)
{
    return gPokenavResources->mode;
}

void SetPokenavMode(u16 mode)
{
    gPokenavResources->mode = mode;
}

void sub_81C7694(u32 a0)
{
    u32 value = a0;

    if (value > 4)
        value = 0;
    gPokenavResources->fieldA = value;
}

u32 sub_81C76AC(void)
{
    return gPokenavResources->fieldA;
}

bool32 CanViewRibbonsMenu(void)
{
    return gPokenavResources->hasAnyRibbons;
}
