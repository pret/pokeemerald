#include "global.h"
#include "pokenav.h"
#include "event_data.h"
#include "main.h"
#include "sound.h"
#include "constants/songs.h"

struct Pokenav1Struct
{
    u16 menuType;
    s16 cursorPos;
    u16 currMenuItem;
    u16 helpBarIndex;
    u32 menuId;
    u32 (*callback)(struct Pokenav1Struct*);
};

static bool32 UpdateMenuCursorPos(struct Pokenav1Struct *state);
static void ReturnToConditionMenu(struct Pokenav1Struct *state);
static void ReturnToMainMenu(struct Pokenav1Struct *state);
static u32 GetMenuId(struct Pokenav1Struct *state);
static void SetMenuIdAndCB(struct Pokenav1Struct *state, u32 a1);
static u32 CB2_ReturnToConditionMenu(struct Pokenav1Struct *state);
static u32 CB2_ReturnToMainMenu(struct Pokenav1Struct *state);
static u32 HandleConditionSearchMenuInput(struct Pokenav1Struct *state);
static u32 HandleConditionMenuInput(struct Pokenav1Struct *state);
static u32 HandleCantOpenRibbonsInput(struct Pokenav1Struct *state);
static u32 HandleMainMenuInputEndTutorial(struct Pokenav1Struct *state);
static u32 HandleMainMenuInputTutorial(struct Pokenav1Struct *state);
static u32 HandleMainMenuInput(struct Pokenav1Struct *state);
static u32 (*GetMainMenuInputHandler(void))(struct Pokenav1Struct*);
static void SetMenuInputHandler(struct Pokenav1Struct *state);

// Number of entries - 1 for that menu type
static const u8 sLastCursorPositions[] = 
{
    [POKENAV_MENU_TYPE_DEFAULT]           = 2, 
    [POKENAV_MENU_TYPE_UNLOCK_MC]         = 3, 
    [POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS] = 4, 
    [POKENAV_MENU_TYPE_CONDITION]         = 2, 
    [POKENAV_MENU_TYPE_CONDITION_SEARCH]  = 5
};

static const u8 sMenuItems[][6] =
{
    [POKENAV_MENU_TYPE_DEFAULT] = 
    { 
        POKENAV_MENUITEM_MAP, 
        POKENAV_MENUITEM_CONDITION,  
        [2 ... 5] = POKENAV_MENUITEM_SWITCH_OFF
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC] = 
    { 
        POKENAV_MENUITEM_MAP, 
        POKENAV_MENUITEM_CONDITION,  
        POKENAV_MENUITEM_MATCH_CALL,  
        [3 ... 5] = POKENAV_MENUITEM_SWITCH_OFF
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS] = 
    { 
        POKENAV_MENUITEM_MAP, 
        POKENAV_MENUITEM_CONDITION,  
        POKENAV_MENUITEM_MATCH_CALL,  
        POKENAV_MENUITEM_RIBBONS,  
        [4 ... 5] = POKENAV_MENUITEM_SWITCH_OFF
    },
    [POKENAV_MENU_TYPE_CONDITION] = 
    { 
        POKENAV_MENUITEM_CONDITION_PARTY, 
        POKENAV_MENUITEM_CONDITION_SEARCH,  
        POKENAV_MENUITEM_CONDITION_CANCEL,  
        [3 ... 5] = POKENAV_MENUITEM_SWITCH_OFF
    },
    [POKENAV_MENU_TYPE_CONDITION_SEARCH] = 
    { 
        POKENAV_MENUITEM_CONDITION_SEARCH_COOL, 
        POKENAV_MENUITEM_CONDITION_SEARCH_BEAUTY, 
        POKENAV_MENUITEM_CONDITION_SEARCH_CUTE, 
        POKENAV_MENUITEM_CONDITION_SEARCH_SMART, 
        POKENAV_MENUITEM_CONDITION_SEARCH_TOUGH, 
        POKENAV_MENUITEM_CONDITION_SEARCH_CANCEL 
    },
};

static u8 GetPokenavMainMenuType(void)
{
    u8 menuType = POKENAV_MENU_TYPE_DEFAULT;

    if (FlagGet(FLAG_ADDED_MATCH_CALL_TO_POKENAV))
    { 
        menuType = POKENAV_MENU_TYPE_UNLOCK_MC;

        if (FlagGet(FLAG_SYS_RIBBON_GET))
            menuType = POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS;
    }
    
    return menuType;
}

bool32 PokenavCallback_Init_MainMenuCursorOnMap(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->menuType = GetPokenavMainMenuType();
    state->cursorPos = 0;
    state->currMenuItem = POKENAV_MENUITEM_MAP;
    state->helpBarIndex = HELPBAR_NONE;
    SetMenuInputHandler(state);
    return TRUE;
}

bool32 PokenavCallback_Init_MainMenuCursorOnMatchCall(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->menuType = GetPokenavMainMenuType();
    state->cursorPos = 2;
    state->currMenuItem = POKENAV_MENUITEM_MATCH_CALL;
    state->helpBarIndex = HELPBAR_NONE;
    SetMenuInputHandler(state);
    return TRUE;
}

bool32 PokenavCallback_Init_MainMenuCursorOnRibbons(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->menuType = GetPokenavMainMenuType();
    state->cursorPos = 3;
    state->currMenuItem = POKENAV_MENUITEM_RIBBONS;
    SetMenuInputHandler(state);
    return TRUE;
}

bool32 PokenavCallback_Init_ConditionMenu(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->menuType = POKENAV_MENU_TYPE_CONDITION;
    state->cursorPos = 0;
    state->currMenuItem = POKENAV_MENUITEM_CONDITION_PARTY;
    state->helpBarIndex = HELPBAR_NONE;
    SetMenuInputHandler(state);
    return TRUE;
}

bool32 PokenavCallback_Init_ConditionSearchMenu(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->menuType = POKENAV_MENU_TYPE_CONDITION_SEARCH;
    state->cursorPos = GetSelectedConditionSearch();
    state->currMenuItem = state->cursorPos + POKENAV_MENUITEM_CONDITION_SEARCH_COOL;
    state->helpBarIndex = HELPBAR_NONE;
    SetMenuInputHandler(state);
    return TRUE;
}

static void SetMenuInputHandler(struct Pokenav1Struct *state)
{
    switch (state->menuType)
    {
    case POKENAV_MENU_TYPE_DEFAULT:
        SetPokenavMode(POKENAV_MODE_NORMAL);
        // fallthrough
    case POKENAV_MENU_TYPE_UNLOCK_MC:
    case POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS:
        state->callback = GetMainMenuInputHandler();
        break;
    case POKENAV_MENU_TYPE_CONDITION:
        state->callback = HandleConditionMenuInput;
        break;
    case POKENAV_MENU_TYPE_CONDITION_SEARCH:
        state->callback = HandleConditionSearchMenuInput;
        break;
    }
}

static u32 (*GetMainMenuInputHandler(void))(struct Pokenav1Struct*)
{
    switch (GetPokenavMode())
    {
    default:
    case POKENAV_MODE_NORMAL:
        return HandleMainMenuInput;
    case POKENAV_MODE_FORCE_CALL_READY:
        return HandleMainMenuInputTutorial;
    case POKENAV_MODE_FORCE_CALL_EXIT:
        return HandleMainMenuInputEndTutorial;
    }
}

u32 GetMenuHandlerCallback(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->callback(state);
}

void FreeMenuHandlerSubstruct1(void)
{
    FreePokenavSubstruct(1);
}

static u32 HandleMainMenuInput(struct Pokenav1Struct *state)
{
    if (UpdateMenuCursorPos(state))
        return POKENAV_MENU_FUNC_MOVE_CURSOR;

    if (gMain.newKeys & A_BUTTON)
    {
        switch (sMenuItems[state->menuType][state->cursorPos])
        {
        case POKENAV_MENUITEM_MAP:
            state->helpBarIndex = gSaveBlock2Ptr->regionMapZoom ? HELPBAR_MAP_ZOOMED_IN : HELPBAR_MAP_ZOOMED_OUT;
            SetMenuIdAndCB(state, POKENAV_REGION_MAP);
            return POKENAV_MENU_FUNC_OPEN_FEATURE;
        case POKENAV_MENUITEM_CONDITION:
            state->menuType = POKENAV_MENU_TYPE_CONDITION;
            state->cursorPos = 0;
            state->currMenuItem = sMenuItems[POKENAV_MENU_TYPE_CONDITION][0];
            state->callback = HandleConditionMenuInput;
            return POKENAV_MENU_FUNC_OPEN_CONDITION;
        case POKENAV_MENUITEM_MATCH_CALL:
            state->helpBarIndex = HELPBAR_MC_TRAINER_LIST;
            SetMenuIdAndCB(state, POKENAV_MATCH_CALL);
            return POKENAV_MENU_FUNC_OPEN_FEATURE;
        case POKENAV_MENUITEM_RIBBONS:
            if (CanViewRibbonsMenu())
            {
                state->helpBarIndex = HELPBAR_RIBBONS_MON_LIST;
                SetMenuIdAndCB(state, POKENAV_RIBBONS_MON_LIST);
                return POKENAV_MENU_FUNC_OPEN_FEATURE;
            }
            else
            {
                state->callback = HandleCantOpenRibbonsInput;
                return POKENAV_MENU_FUNC_NO_RIBBON_WINNERS;
            }
        case POKENAV_MENUITEM_SWITCH_OFF:
            return -1;
        }
    }
    
    if (gMain.newKeys & B_BUTTON)
        return -1;

    return POKENAV_MENU_FUNC_NONE;
}

// Force the player to select Match Call during the call Mr. Stone pokenav tutorial
static u32 HandleMainMenuInputTutorial(struct Pokenav1Struct *state)
{
    if (UpdateMenuCursorPos(state))
        return POKENAV_MENU_FUNC_MOVE_CURSOR;
    
    if (gMain.newKeys & A_BUTTON)
    {
        if (sMenuItems[state->menuType][state->cursorPos] == POKENAV_MENUITEM_MATCH_CALL)
        {
            state->helpBarIndex = HELPBAR_MC_TRAINER_LIST;
            SetMenuIdAndCB(state, POKENAV_MATCH_CALL);
            return POKENAV_MENU_FUNC_OPEN_FEATURE;
        }
        else
        {
            PlaySE(SE_HAZURE);
            return POKENAV_MENU_FUNC_NONE;
        }
    }
    
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_HAZURE);
        return POKENAV_MENU_FUNC_NONE;
    }
    
    return POKENAV_MENU_FUNC_NONE;
}

// After calling Mr. Stone during the pokenav tutorial, force player to exit or use Match Call again
static u32 HandleMainMenuInputEndTutorial(struct Pokenav1Struct *state)
{
    if (UpdateMenuCursorPos(state))
        return POKENAV_MENU_FUNC_MOVE_CURSOR;
    
    if (gMain.newKeys & A_BUTTON)
    {
        u32 menuItem = sMenuItems[state->menuType][state->cursorPos];
        if (menuItem != POKENAV_MENUITEM_MATCH_CALL && menuItem != POKENAV_MENUITEM_SWITCH_OFF)
        {
            PlaySE(SE_HAZURE);
            return POKENAV_MENU_FUNC_NONE;
        }
        else if (menuItem == POKENAV_MENUITEM_MATCH_CALL)
        {
            state->helpBarIndex = HELPBAR_MC_TRAINER_LIST;
            SetMenuIdAndCB(state, POKENAV_MATCH_CALL);
            return POKENAV_MENU_FUNC_OPEN_FEATURE;
        }
        else
        {
            return -1;
        }
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    return POKENAV_MENU_FUNC_NONE;
}

// Handles input after selecting Ribbons when there are no ribbon winners left
// Selecting it again just reprints the Ribbon description to replace the "No Ribbon winners" message
static u32 HandleCantOpenRibbonsInput(struct Pokenav1Struct *state)
{
    if (UpdateMenuCursorPos(state))
    {
        state->callback = GetMainMenuInputHandler();
        return POKENAV_MENU_FUNC_MOVE_CURSOR;
    }

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        state->callback = GetMainMenuInputHandler();
        return POKENAV_MENU_FUNC_RESHOW_DESCRIPTION;
    }

    return POKENAV_MENU_FUNC_NONE;
}

static u32 HandleConditionMenuInput(struct Pokenav1Struct *state)
{
    if (UpdateMenuCursorPos(state))
        return POKENAV_MENU_FUNC_MOVE_CURSOR;
    
    if (gMain.newKeys & A_BUTTON)
    {
        switch (sMenuItems[state->menuType][state->cursorPos])
        {
        case POKENAV_MENUITEM_CONDITION_SEARCH:
            state->menuType = POKENAV_MENU_TYPE_CONDITION_SEARCH;
            state->cursorPos = 0;
            state->currMenuItem = sMenuItems[POKENAV_MENU_TYPE_CONDITION_SEARCH][0];
            state->callback = HandleConditionSearchMenuInput;
            return POKENAV_MENU_FUNC_OPEN_CONDITION_SEARCH;
        case POKENAV_MENUITEM_CONDITION_PARTY:
            state->helpBarIndex = 0;
            SetMenuIdAndCB(state, POKENAV_CONDITION_PARTY);
            return POKENAV_MENU_FUNC_OPEN_FEATURE;
        case POKENAV_MENUITEM_CONDITION_CANCEL:
            PlaySE(SE_SELECT);
            ReturnToMainMenu(state);
            return POKENAV_MENU_FUNC_RETURN_TO_MAIN;
        }
    }
    if (gMain.newKeys & B_BUTTON)
    {
        if (state->cursorPos != sLastCursorPositions[state->menuType])
        {
            state->cursorPos = sLastCursorPositions[state->menuType];
            state->callback = CB2_ReturnToMainMenu;
            return POKENAV_MENU_FUNC_MOVE_CURSOR;
        }
        else
        {
            PlaySE(SE_SELECT);
            ReturnToMainMenu(state);
            return POKENAV_MENU_FUNC_RETURN_TO_MAIN;
        }
    }

    return POKENAV_MENU_FUNC_NONE;
}

static u32 HandleConditionSearchMenuInput(struct Pokenav1Struct *state)
{
    if (UpdateMenuCursorPos(state))
        return POKENAV_MENU_FUNC_MOVE_CURSOR;
    
    if (gMain.newKeys & A_BUTTON)
    {
        u8 menuItem = sMenuItems[state->menuType][state->cursorPos];
        if (menuItem != POKENAV_MENUITEM_CONDITION_SEARCH_CANCEL)
        {
            SetSelectedConditionSearch(menuItem - POKENAV_MENUITEM_CONDITION_SEARCH_COOL);
            SetMenuIdAndCB(state, POKENAV_CONDITION_SEARCH_RESULTS);
            state->helpBarIndex = HELPBAR_CONDITION_MON_LIST;
            return POKENAV_MENU_FUNC_OPEN_FEATURE;
        }
        else
        {
            PlaySE(SE_SELECT);
            ReturnToConditionMenu(state);
            return POKENAV_MENU_FUNC_RETURN_TO_CONDITION;
        }
    }
    if (gMain.newKeys & B_BUTTON)
    {
        if (state->cursorPos != sLastCursorPositions[state->menuType])
        {
            state->cursorPos = sLastCursorPositions[state->menuType];
            state->callback = CB2_ReturnToConditionMenu;
            return POKENAV_MENU_FUNC_MOVE_CURSOR;
        }
        else
        {
            PlaySE(SE_SELECT);
            ReturnToConditionMenu(state);
            return POKENAV_MENU_FUNC_RETURN_TO_CONDITION;
        }
    }
    return POKENAV_MENU_FUNC_NONE;
}

static u32 CB2_ReturnToMainMenu(struct Pokenav1Struct *state)
{
    ReturnToMainMenu(state);
    return POKENAV_MENU_FUNC_RETURN_TO_MAIN;
}

static u32 CB2_ReturnToConditionMenu(struct Pokenav1Struct *state)
{
    ReturnToConditionMenu(state);
    return POKENAV_MENU_FUNC_RETURN_TO_CONDITION;
}

static void SetMenuIdAndCB(struct Pokenav1Struct *state, u32 menuId)
{
    state->menuId = menuId;
    state->callback = GetMenuId;
}

static u32 GetMenuId(struct Pokenav1Struct *state)
{
    return state->menuId;
}

static void ReturnToMainMenu(struct Pokenav1Struct *state)
{
    state->menuType = GetPokenavMainMenuType();
    state->cursorPos = 1;
    state->currMenuItem = sMenuItems[state->menuType][state->cursorPos];
    state->callback = HandleMainMenuInput;
}

static void ReturnToConditionMenu(struct Pokenav1Struct *state)
{
    state->menuType = POKENAV_MENU_TYPE_CONDITION;
    state->cursorPos = 1;
    state->currMenuItem = sMenuItems[POKENAV_MENU_TYPE_CONDITION][1];
    state->callback = HandleConditionMenuInput;
}

static bool32 UpdateMenuCursorPos(struct Pokenav1Struct *state)
{
    if (gMain.newKeys & DPAD_UP)
    {
        if (--state->cursorPos < 0)
            state->cursorPos = sLastCursorPositions[state->menuType];

        state->currMenuItem = sMenuItems[state->menuType][state->cursorPos];
        return TRUE;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        state->cursorPos++;
        if (state->cursorPos > sLastCursorPositions[state->menuType])
            state->cursorPos = 0;

        state->currMenuItem = sMenuItems[state->menuType][state->cursorPos];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int GetPokenavMenuType(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->menuType;
}

// Position of cursor relative to number of current menu options
int GetPokenavCursorPos(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->cursorPos;
}

// ID of menu item the cursor is currently on
int GetCurrentMenuItemId(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->currMenuItem;
}

u16 GetHelpBarTextId(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->helpBarIndex;
}
