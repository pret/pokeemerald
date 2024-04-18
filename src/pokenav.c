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

struct PokenavResources
{
    u32 (*currentMenuCb1)(void);
    u32 currentMenuIndex;
    u16 mode;
    u16 conditionSearchId;
    bool32 hasAnyRibbons;
    void *substructPtrs[POKENAV_SUBSTRUCT_COUNT];
};

struct PokenavCallbacks
{
    bool32 (*init)(void);
    u32 (*callback)(void);
    bool32 (*open)(void);
    void (*createLoopTask)(s32);
    bool32 (*isLoopTaskActive)(void);
    void (*free1)(void);
    void (*free2)(void);
};

static u32 GetCurrentMenuCB(void);
static u32 IsActiveMenuLoopTaskActive_(void);
static bool32 SetActivePokenavMenu(u32);
static bool32 AnyMonHasRibbon(void);
static void InitPokenavResources(struct PokenavResources *);
static void InitKeys_(void);
static void FreePokenavResources(void);
static void VBlankCB_Pokenav(void);
static void CB2_Pokenav(void);
static void Task_RunLoopedTask_LinkMode(u8);
static void Task_RunLoopedTask(u8);
static void Task_Pokenav(u8);
static void CB2_InitPokenavForTutorial(void);

const struct PokenavCallbacks PokenavMenuCallbacks[15] =
{
    [POKENAV_MAIN_MENU - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_MainMenuCursorOnMap,
        .callback = GetMenuHandlerCallback,
        .open = OpenPokenavMenuInitial,
        .createLoopTask = CreateMenuHandlerLoopedTask,
        .isLoopTaskActive = IsMenuHandlerLoopedTaskActive,
        .free1 = FreeMenuHandlerSubstruct1,
        .free2 = FreeMenuHandlerSubstruct2,
    },
    [POKENAV_MAIN_MENU_CURSOR_ON_MAP - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_MainMenuCursorOnMap,
        .callback = GetMenuHandlerCallback,
        .open = OpenPokenavMenuNotInitial,
        .createLoopTask = CreateMenuHandlerLoopedTask,
        .isLoopTaskActive = IsMenuHandlerLoopedTaskActive,
        .free1 = FreeMenuHandlerSubstruct1,
        .free2 = FreeMenuHandlerSubstruct2,
    },
    [POKENAV_CONDITION_MENU - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_ConditionMenu,
        .callback = GetMenuHandlerCallback,
        .open = OpenPokenavMenuNotInitial,
        .createLoopTask = CreateMenuHandlerLoopedTask,
        .isLoopTaskActive = IsMenuHandlerLoopedTaskActive,
        .free1 = FreeMenuHandlerSubstruct1,
        .free2 = FreeMenuHandlerSubstruct2,
    },
    [POKENAV_CONDITION_SEARCH_MENU - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_ConditionSearchMenu,
        .callback = GetMenuHandlerCallback,
        .open = OpenPokenavMenuNotInitial,
        .createLoopTask = CreateMenuHandlerLoopedTask,
        .isLoopTaskActive = IsMenuHandlerLoopedTaskActive,
        .free1 = FreeMenuHandlerSubstruct1,
        .free2 = FreeMenuHandlerSubstruct2,
    },
    [POKENAV_MAIN_MENU_CURSOR_ON_MATCH_CALL - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_MainMenuCursorOnMatchCall,
        .callback = GetMenuHandlerCallback,
        .open = OpenPokenavMenuNotInitial,
        .createLoopTask = CreateMenuHandlerLoopedTask,
        .isLoopTaskActive = IsMenuHandlerLoopedTaskActive,
        .free1 = FreeMenuHandlerSubstruct1,
        .free2 = FreeMenuHandlerSubstruct2,
    },
    [POKENAV_MAIN_MENU_CURSOR_ON_RIBBONS - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_MainMenuCursorOnRibbons,
        .callback = GetMenuHandlerCallback,
        .open = OpenPokenavMenuNotInitial,
        .createLoopTask = CreateMenuHandlerLoopedTask,
        .isLoopTaskActive = IsMenuHandlerLoopedTaskActive,
        .free1 = FreeMenuHandlerSubstruct1,
        .free2 = FreeMenuHandlerSubstruct2,
    },
    [POKENAV_REGION_MAP - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_RegionMap,
        .callback = GetRegionMapCallback,
        .open = OpenPokenavRegionMap,
        .createLoopTask = CreateRegionMapLoopedTask,
        .isLoopTaskActive = IsRegionMapLoopedTaskActive,
        .free1 = FreeRegionMapSubstruct1,
        .free2 = FreeRegionMapSubstruct2,
    },
    [POKENAV_CONDITION_GRAPH_PARTY - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_ConditionGraph_Party,
        .callback = GetConditionGraphMenuCallback,
        .open = OpenConditionGraphMenu,
        .createLoopTask = CreateConditionGraphMenuLoopedTask,
        .isLoopTaskActive = IsConditionGraphMenuLoopedTaskActive,
        .free1 = FreeConditionGraphMenuSubstruct1,
        .free2 = FreeConditionGraphMenuSubstruct2,
    },
    [POKENAV_CONDITION_SEARCH_RESULTS - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_ConditionSearch,
        .callback = GetConditionSearchResultsCallback,
        .open = OpenConditionSearchResults,
        .createLoopTask = CreateSearchResultsLoopedTask,
        .isLoopTaskActive = IsSearchResultLoopedTaskActive,
        .free1 = FreeSearchResultSubstruct1,
        .free2 = FreeSearchResultSubstruct2,
    },
    [POKENAV_CONDITION_GRAPH_SEARCH - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_ConditionGraph_Search,
        .callback = GetConditionGraphMenuCallback,
        .open = OpenConditionGraphMenu,
        .createLoopTask = CreateConditionGraphMenuLoopedTask,
        .isLoopTaskActive = IsConditionGraphMenuLoopedTaskActive,
        .free1 = FreeConditionGraphMenuSubstruct1,
        .free2 = FreeConditionGraphMenuSubstruct2,
    },
    [POKENAV_RETURN_CONDITION_SEARCH - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_ReturnToMonSearchList,
        .callback = GetConditionSearchResultsCallback,
        .open = OpenConditionSearchListFromGraph,
        .createLoopTask = CreateSearchResultsLoopedTask,
        .isLoopTaskActive = IsSearchResultLoopedTaskActive,
        .free1 = FreeSearchResultSubstruct1,
        .free2 = FreeSearchResultSubstruct2,
    },
    [POKENAV_MATCH_CALL - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_MatchCall,
        .callback = GetMatchCallCallback,
        .open = OpenMatchCall,
        .createLoopTask = CreateMatchCallLoopedTask,
        .isLoopTaskActive = IsMatchCallLoopedTaskActive,
        .free1 = FreeMatchCallSubstruct1,
        .free2 = FreeMatchCallSubstruct2,
    },
    [POKENAV_RIBBONS_MON_LIST - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_MonRibbonList,
        .callback = GetRibbonsMonListCallback,
        .open = OpenRibbonsMonList,
        .createLoopTask = CreateRibbonsMonListLoopedTask,
        .isLoopTaskActive = IsRibbonsMonListLoopedTaskActive,
        .free1 = FreeRibbonsMonList,
        .free2 = FreeRibbonsMonMenu,
    },
    [POKENAV_RIBBONS_SUMMARY_SCREEN - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_RibbonsSummaryMenu,
        .callback = GetRibbonsSummaryMenuCallback,
        .open = OpenRibbonsSummaryMenu,
        .createLoopTask = CreateRibbonsSummaryLoopedTask,
        .isLoopTaskActive = IsRibbonsSummaryLoopedTaskActive,
        .free1 = FreeRibbonsSummaryScreen1,
        .free2 = FreeRibbonsSummaryScreen2,
    },
    [POKENAV_RIBBONS_RETURN_TO_MON_LIST - POKENAV_MENU_IDS_START] =
    {
        .init = PokenavCallback_Init_RibbonsMonListFromSummary,
        .callback = GetRibbonsMonListCallback,
        .open = OpenRibbonsMonListFromRibbonsSummary,
        .createLoopTask = CreateRibbonsMonListLoopedTask,
        .isLoopTaskActive = IsRibbonsMonListLoopedTaskActive,
        .free1 = FreeRibbonsMonList,
        .free2 = FreeRibbonsMonMenu,
    },
};

EWRAM_DATA u8 gNextLoopedTaskId = 0;
EWRAM_DATA struct PokenavResources *gPokenavResources = NULL;

// code
u32 CreateLoopedTask(LoopedTask loopedTask, u32 priority)
{
    u16 taskId;

    if (!IsOverworldLinkActive())
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

    if (Overworld_IsRecvQueueAtMax())
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
        SetMainCallback2(CB2_ReturnToFullScreenStartMenu);
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
    FadeScreen(FADE_TO_BLACK, 0);
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
        gPokenavResources->mode = POKENAV_MODE_FORCE_CALL_READY;
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

    for (i = 0; i < POKENAV_SUBSTRUCT_COUNT; i++)
        FreePokenavSubstruct(i);

    FREE_AND_SET_NULL(gPokenavResources);
    InitKeys();
}

static void InitPokenavResources(struct PokenavResources *resources)
{
    int i;

    for (i = 0; i < POKENAV_SUBSTRUCT_COUNT; i++)
        resources->substructPtrs[i] = NULL;

    resources->mode = POKENAV_MODE_NORMAL;
    resources->currentMenuIndex = 0;
    resources->hasAnyRibbons = AnyMonHasRibbon();
    resources->currentMenuCb1 = NULL;
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

#define tState data[0]

static void Task_Pokenav(u8 taskId)
{
    u32 menuId;
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        InitPokenavMainMenu();
        tState = 1;
        break;
    case 1:
        // Wait for LoopedTask_InitPokenavMenu to finish
        if (PokenavMainMenuLoopedTaskIsActive())
            break;
        SetActivePokenavMenu(POKENAV_MAIN_MENU);
        tState = 4;
        break;
    case 2:
        if (IsActiveMenuLoopTaskActive())
            break;
        tState = 3;
    case 3:
        menuId = GetCurrentMenuCB();
        if (menuId == POKENAV_MENU_FUNC_EXIT)
        {
            ShutdownPokenav();
            tState = 5;
        }
        else if (menuId >= POKENAV_MENU_IDS_START)
        {
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex].free2();
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex].free1();
            if (SetActivePokenavMenu(menuId))
            {
                tState = 4;
            }
            else
            {
                ShutdownPokenav();
                tState = 5;
            }
        }
        else if (menuId != 0)
        {
            RunMainMenuLoopedTask(menuId);
            if (IsActiveMenuLoopTaskActive())
                tState = 2;
        }
        break;
    case 4:
        if (!IsActiveMenuLoopTaskActive_())
            tState = 3;
        break;
    case 5:
        if (!WaitForPokenavShutdownFade())
        {
            bool32 calledFromScript = (gPokenavResources->mode != POKENAV_MODE_NORMAL);

            FreeMenuHandlerSubstruct1();
            FreePokenavResources();
            if (calledFromScript)
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            else
                SetMainCallback2(CB2_ReturnToFullScreenStartMenu);
        }
        break;
    }
}

#undef tState

static bool32 SetActivePokenavMenu(u32 menuId)
{
    u32 index = menuId - POKENAV_MENU_IDS_START;

    InitKeys_();
    if (!PokenavMenuCallbacks[index].init())
        return FALSE;
    if (!PokenavMenuCallbacks[index].open())
        return FALSE;

    SetActiveMenuLoopTasks(PokenavMenuCallbacks[index].createLoopTask, PokenavMenuCallbacks[index].isLoopTaskActive);
    gPokenavResources->currentMenuCb1 = PokenavMenuCallbacks[index].callback;
    gPokenavResources->currentMenuIndex = index;
    return TRUE;
}

static u32 IsActiveMenuLoopTaskActive_(void)
{
    return IsActiveMenuLoopTaskActive();
}

static u32 GetCurrentMenuCB(void)
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
    gPokenavResources->substructPtrs[index] = Alloc(size);
    return gPokenavResources->substructPtrs[index];
}

void *GetSubstructPtr(u32 index)
{
    return gPokenavResources->substructPtrs[index];
}

void FreePokenavSubstruct(u32 index)
{
    TRY_FREE_AND_SET_NULL(gPokenavResources->substructPtrs[index]);
}

u32 GetPokenavMode(void)
{
    return gPokenavResources->mode;
}

void SetPokenavMode(u16 mode)
{
    gPokenavResources->mode = mode;
}

void SetSelectedConditionSearch(u32 cursorPos)
{
    u32 searchId = cursorPos;

    if (searchId > POKENAV_MENUITEM_CONDITION_SEARCH_TOUGH - POKENAV_MENUITEM_CONDITION_SEARCH_COOL)
        searchId = 0;
    gPokenavResources->conditionSearchId = searchId;
}

u32 GetSelectedConditionSearch(void)
{
    return gPokenavResources->conditionSearchId;
}

bool32 CanViewRibbonsMenu(void)
{
    return gPokenavResources->hasAnyRibbons;
}
