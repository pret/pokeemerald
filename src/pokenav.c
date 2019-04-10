#include "global.h"
#include "alloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"
#include "field_weather.h"
#include "palette.h"
#include "pokemon_storage_system.h"
#include "pokenav.h"

enum
{
    MODE_NORMAL, // Chosen from Start menu.
    MODE_FORCE_CALL_1, // Used for the script's special. Has to choose Match Call and make a call.
    MODE_FORCE_CALL_2, // Set after making a call, has to exit Pokenav.
};

enum
{
    NAVMENU_CB_UNK_0,
    NAVMENU_CB_UNK_1,
    NAVMENU_CB_UNK_2,
    NAVMENU_CB_UNK_3,
    NAVMENU_CB_UNK_4,
    NAVMENU_CB_UNK_5,
    NAVMENU_CB_UNK_6
};

#define LOOPED_TASK_DECODE_STATE(action) (action - 5)

#define LOOPED_TASK_ID(primary, secondary) (((secondary) << 16) |(primary))
#define LOOPED_TASK_PRIMARY_ID(taskId) (taskId & 0xFFFF)
#define LOOPED_TASK_SECONDARY_ID(taskId) (taskId >> 16)

#define UNKNOWN_OFFSET 100000

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

extern u32 sub_81C9430(void);
extern u32 sub_81C9298(void);
extern u32 sub_81C941C(void);
extern u32 sub_81C9924(void);
extern u32 sub_81C99C0(void);
extern u32 sub_81C9990(void);
extern u32 sub_81C9940(void);
extern u32 sub_81C9338(void);
extern u32 sub_81C9368(void);
extern u32 sub_81C92CC(void);
extern u32 sub_81C9304(void);
extern u32 sub_81CC4D4(void);
extern u32 sub_81CC554(void);
extern u32 sub_81CC5F4(void);
extern u32 sub_81CC62C(void);
extern u32 sub_81CC65C(void);
extern u32 sub_81CC524(void);
extern u32 sub_81CC670(void);
extern u32 sub_81CCFD8(void);
extern u32 sub_81CD070(void);
extern u32 sub_81CDDD4(void);
extern u32 sub_81CDE2C(void);
extern u32 sub_81CDE64(void);
extern u32 sub_81CD1C0(void);
extern u32 sub_81CECA0(void);
extern u32 sub_81CEF3C(void);
extern u32 sub_81CEFDC(void);
extern u32 sub_81CF330(void);
extern u32 sub_81CF3A0(void);
extern u32 sub_81CF3D0(void);
extern u32 sub_81CEFF0(void);
extern u32 sub_81CF3F8(void);
extern u32 sub_81CD024(void);
extern u32 sub_81CEF98(void);
extern u32 sub_81CF368(void);
extern u32 sub_81CAAE8(void);
extern u32 sub_81CAB24(void);
extern u32 sub_81CB260(void);
extern u32 sub_81CB29C(void);
extern u32 sub_81CB2CC(void);
extern u32 sub_81CAB38(void);
extern u32 sub_81CB2E0(void);
extern u32 sub_81CF9BC(void);
extern u32 sub_81CFA34(void);
extern u32 sub_81CFDD0(void);
extern u32 sub_81CFE40(void);
extern u32 sub_81CFE70(void);
extern u32 sub_81CFA48(void);
extern u32 sub_81CFE98(void);
extern u32 sub_81D0450(void);
extern u32 sub_81D04A0(void);
extern u32 sub_81D0978(void);
extern u32 sub_81D09B0(void);
extern u32 sub_81D09E0(void);
extern u32 sub_81D04B8(void);
extern u32 sub_81D09F4(void);
extern u32 sub_81CFA04(void);
extern u32 sub_81CFE08(void);

bool32 SetActivePokenavMenu(u32 a0);
bool32 InitPokenavMainMenu(void);
static bool32 AnyMonHasRibbon(void);
u32 sub_81C75E0(void);
u32 sub_81C75D4(void);
u32 PokenavMainMenuLoopedTaskIsActive(void);
u32 sub_81C786C(void);
bool32 WaitForPokenavShutdownFade(void);
void sub_81C7834(void *func1, void *func2);
static void InitPokenavResources(struct PokenavResources *a0);
void sub_81C7850(u32 a0);
void Task_RunLoopedTask_LinkMode(u8 a0);
void Task_RunLoopedTask(u8 taskId);
void sub_81C742C(u8 taskId);
void ShutdownPokenav(void);
static void InitKeys_(void);
static void FreePokenavResources(void);
static void VBlankCB_Pokenav(void);
static void CB2_Pokenav(void);
void sub_81C72BC(void);

// Const rom data.
u32 (*const PokenavMenuCallbacks[15][7])(void) =
{
    {
        sub_81C9298,
        sub_81C941C,
        sub_81C9924,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9298,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9338,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9368,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C92CC,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9304,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81CC4D4,
        sub_81CC554,
        sub_81CC5F4,
        sub_81CC62C,
        sub_81CC65C,
        sub_81CC524,
        sub_81CC670,
    },
    {
        sub_81CCFD8,
        sub_81CD070,
        sub_81CDDD4,
        sub_81CDE2C,
        sub_81CDE64,
        sub_81CD1C0,
        sub_81CECA0,
    },
    {
        sub_81CEF3C,
        sub_81CEFDC,
        sub_81CF330,
        sub_81CF3A0,
        sub_81CF3D0,
        sub_81CEFF0,
        sub_81CF3F8,
    },
    {
        sub_81CD024,
        sub_81CD070,
        sub_81CDDD4,
        sub_81CDE2C,
        sub_81CDE64,
        sub_81CD1C0,
        sub_81CECA0,
    },
    {
        sub_81CEF98,
        sub_81CEFDC,
        sub_81CF368,
        sub_81CF3A0,
        sub_81CF3D0,
        sub_81CEFF0,
        sub_81CF3F8,
    },
    {
        sub_81CAAE8,
        sub_81CAB24,
        sub_81CB260,
        sub_81CB29C,
        sub_81CB2CC,
        sub_81CAB38,
        sub_81CB2E0,
    },
    {
        sub_81CF9BC,
        sub_81CFA34,
        sub_81CFDD0,
        sub_81CFE40,
        sub_81CFE70,
        sub_81CFA48,
        sub_81CFE98,
    },
    {
        sub_81D0450,
        sub_81D04A0,
        sub_81D0978,
        sub_81D09B0,
        sub_81D09E0,
        sub_81D04B8,
        sub_81D09F4,
    },
    {
        sub_81CFA04,
        sub_81CFA34,
        sub_81CFE08,
        sub_81CFE40,
        sub_81CFE70,
        sub_81CFA48,
        sub_81CFE98,
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
    s32 i;
    for (i = 0; i < NUM_TASKS; i++)
    {
        if (gTasks[i].isActive
            && (gTasks[i].func == Task_RunLoopedTask || gTasks[i].func == Task_RunLoopedTask_LinkMode)
            && (LoopedTask)GetWordTaskArg(i, 1) == func)
            return TRUE;
    }
    return FALSE;
}

void Task_RunLoopedTask(u8 taskId)
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
void Task_RunLoopedTask_LinkMode(u8 taskId)
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
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(CB2_Pokenav);
        SetVBlankCallback(VBlankCB_Pokenav);
    }
}

void sub_81C72A4(void)
{
    SetMainCallback2(sub_81C72BC);
    FadeScreen(1, 0);
}

void sub_81C72BC(void)
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
        gPokenavResources->mode = MODE_FORCE_CALL_1;
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(CB2_Pokenav);
        SetVBlankCallback(VBlankCB_Pokenav);
    }
}

static void FreePokenavResources(void)
{
    s32 i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        FreePokenavSubstruct(i);

    FREE_AND_SET_NULL(gPokenavResources);
    InitKeys();
}

static void InitPokenavResources(struct PokenavResources *a0)
{
    s32 i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        a0->field10[i] = NULL;

    a0->mode = MODE_NORMAL;
    a0->currentMenuIndex = 0;
    a0->hasAnyRibbons = AnyMonHasRibbon();
    a0->currentMenuCb1 = NULL;
}

static bool32 AnyMonHasRibbon(void)
{
    s32 i, j;

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

void sub_81C742C(u8 taskId)
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
        SetActivePokenavMenu(0 + UNKNOWN_OFFSET);
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
        else if (v1 >= UNKNOWN_OFFSET)
        {
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex][NAVMENU_CB_UNK_6]();
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex][NAVMENU_CB_UNK_5]();
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
            bool32 calledFromScript = (gPokenavResources->mode != MODE_NORMAL);

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

bool32 SetActivePokenavMenu(u32 indexWithOffset)
{
    u32 index = indexWithOffset - UNKNOWN_OFFSET;

    InitKeys_();
    if (!PokenavMenuCallbacks[index][NAVMENU_CB_UNK_0]())
        return FALSE;
    if (!PokenavMenuCallbacks[index][NAVMENU_CB_UNK_2]())
        return FALSE;

    sub_81C7834(PokenavMenuCallbacks[index][NAVMENU_CB_UNK_3], PokenavMenuCallbacks[index][NAVMENU_CB_UNK_4]);
    gPokenavResources->currentMenuCb1 = PokenavMenuCallbacks[index][NAVMENU_CB_UNK_1];
    gPokenavResources->currentMenuIndex = index;
    return TRUE;
}

u32 sub_81C75D4(void)
{
    return sub_81C786C();
}

u32 sub_81C75E0(void)
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
    return gPokenavResources->field10[index] = Alloc(size);
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

u16 GetPokenavMode(void)
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

u16 sub_81C76AC(void)
{
    return gPokenavResources->fieldA;
}

bool32 CanViewRibbonsMenu(void)
{
    return gPokenavResources->hasAnyRibbons;
}
