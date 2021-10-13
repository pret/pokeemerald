#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H

#include "bg.h"
#include "main.h"
#include "pokemon_storage_system.h"

typedef u32 (*LoopedTask)(s32 state);

struct PokenavMonList
{
    u8 boxId;
    u8 monId;
    u16 data;
};

struct PokenavMatchCallEntries
{
    bool8 isSpecialTrainer;
    u8 mapSec;
    u16 headerId;
};

struct PokenavListTemplate
{
    union {
        struct PokenavMonList *monList;
        struct PokenavMatchCallEntries *matchCallEntries;
    } list;
    u16 count;
    u16 unk6;
    u8 unk8;
    u8 item_X;
    u8 windowWidth;
    u8 listTop;
    u8 maxShowed;
    u8 fillValue;
    u8 fontId;
    union {
        void (*printMonFunc)(struct PokenavMonList *item, u8 *dest);
        void (*unk10_2)(struct PokenavMatchCallEntries *, u8 *a1);
    } listFunc;
    void (*unk14)(u16 a0, u32 a1, u32 a2);
};

struct PokenavSub18
{
    u16 listCount;
    u16 currIndex;
    struct PokenavMonList monData[TOTAL_BOXES_COUNT * IN_BOX_COUNT + PARTY_SIZE];
};

// Return values of LoopedTask functions.
#define LT_INC_AND_PAUSE 0
#define LT_INC_AND_CONTINUE 1
#define LT_PAUSE 2
#define LT_CONTINUE 3
#define LT_FINISH 4
#define LT_SET_STATE(newState) (newState + 5)

enum
{
    POKENAV_MODE_NORMAL,           // Chosen from Start menu.
    POKENAV_MODE_FORCE_CALL_READY, // Pokenav tutorial before calling Mr. Stone
    POKENAV_MODE_FORCE_CALL_EXIT,  // Pokenav tutorial after calling Mr. Stone
};

// TODO - refine these names
enum Substructures
{
    POKENAV_SUBSTRUCT_MAIN_MENU,
    POKENAV_SUBSTRUCT_MAIN_MENU_HANDLER,
    POKENAV_SUBSTRUCT_MENU_ICONS,
    POKENAV_SUBSTRUCT_REGION_MAP_STATE,
    POKENAV_SUBSTRUCT_REGION_MAP_ZOOM,
    POKENAV_SUBSTRUCT_MATCH_CALL_MAIN,
    POKENAV_SUBSTRUCT_MATCH_CALL_OPEN,
    POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS,
    POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULT_LIST,
    POKENAV_SUBSTRUCT_RIBBONS_MON_LIST,
    POKENAV_SUBSTRUCT_RIBBONS_MON_MENU,
    POKENAV_SUBSTRUCT_CONDITION_GRAPH,
    POKENAV_SUBSTRUCT_MON_MARK_MENU,
    POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST,
    POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU,
    POKENAV_SUBSTRUCT_15,   //unused
    POKENAV_SUBSTRUCT_REGION_MAP,
    POKENAV_SUBSTRUCT_MATCH_CALL_LIST,
    POKENAV_SUBSTRUCT_MON_LIST,
    POKENAV_SUBSTRUCT_COUNT,
};

enum
{
    POKENAV_GFX_MAIN_MENU,
    POKENAV_GFX_CONDITION_MENU,
    POKENAV_GFX_RIBBONS_MENU,
    POKENAV_GFX_MATCH_CALL_MENU,
    POKENAV_GFX_MAP_MENU_ZOOMED_OUT,
    POKENAV_GFX_MAP_MENU_ZOOMED_IN,
    POKENAV_GFX_PARTY_MENU,
    POKENAV_GFX_SEARCH_MENU,
    POKENAV_GFX_COOL_MENU,
    POKENAV_GFX_BEAUTY_MENU,
    POKENAV_GFX_CUTE_MENU,
    POKENAV_GFX_SMART_MENU,
    POKENAV_GFX_TOUGH_MENU,
    POKENAV_GFX_MENUS_END,
};

#define POKENAV_GFX_SUBMENUS_START POKENAV_GFX_PARTY_MENU

#define POKENAV_MENU_IDS_START 100000
enum
{
	POKENAV_MAIN_MENU = POKENAV_MENU_IDS_START,
	POKENAV_MAIN_MENU_CURSOR_ON_MAP,
	POKENAV_CONDITION_MENU,
	POKENAV_CONDITION_SEARCH_MENU,
	POKENAV_MAIN_MENU_CURSOR_ON_MATCH_CALL,
	POKENAV_MAIN_MENU_CURSOR_ON_RIBBONS,
	POKENAV_REGION_MAP,
	POKENAV_CONDITION_PARTY,
	POKENAV_CONDITION_SEARCH_RESULTS,
	POKENAV_CONDITION_GRAPH_FROM_SEARCH, // opening condition graph from search list
	POKENAV_RETURN_CONDITION_SEARCH,    //return to search list from condition graph
	POKENAV_MATCH_CALL,
	POKENAV_RIBBONS_MON_LIST,
	POKENAV_RIBBONS_SUMMARY_SCREEN,
	POKENAV_RIBBONS_RETURN_TO_MON_LIST,
};

enum
{
    POKENAV_MENU_TYPE_DEFAULT,
    POKENAV_MENU_TYPE_UNLOCK_MC,
    POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS,
    POKENAV_MENU_TYPE_CONDITION,
    POKENAV_MENU_TYPE_CONDITION_SEARCH,
    POKENAV_MENU_TYPE_COUNT
};

// Global IDs for menu selections
// As opposed to the cursor position, which is only relative to the number of options for the current menu
enum
{
    POKENAV_MENUITEM_MAP,
    POKENAV_MENUITEM_CONDITION,
    POKENAV_MENUITEM_MATCH_CALL,
    POKENAV_MENUITEM_RIBBONS,
    POKENAV_MENUITEM_SWITCH_OFF,
    POKENAV_MENUITEM_CONDITION_PARTY,
    POKENAV_MENUITEM_CONDITION_SEARCH,
    POKENAV_MENUITEM_CONDITION_CANCEL,
    POKENAV_MENUITEM_CONDITION_SEARCH_COOL,
    POKENAV_MENUITEM_CONDITION_SEARCH_BEAUTY,
    POKENAV_MENUITEM_CONDITION_SEARCH_CUTE,
    POKENAV_MENUITEM_CONDITION_SEARCH_SMART,
    POKENAV_MENUITEM_CONDITION_SEARCH_TOUGH,
    POKENAV_MENUITEM_CONDITION_SEARCH_CANCEL,
};

// Max menu options (condition search uses 6)
#define MAX_POKENAV_MENUITEMS 6

enum
{
    HELPBAR_NONE,
    HELPBAR_MAP_ZOOMED_OUT,
    HELPBAR_MAP_ZOOMED_IN,
    HELPBAR_CONDITION_MON_LIST,
    HELPBAR_CONDITION_MON_STATUS,
    HELPBAR_CONDITION_MARKINGS,
    HELPBAR_MC_TRAINER_LIST,
    HELPBAR_MC_CALL_MENU,
    HELPBAR_MC_CHECK_PAGE,
    HELPBAR_RIBBONS_MON_LIST,
    HELPBAR_RIBBONS_LIST,
    HELPBAR_RIBBONS_CHECK,
    HELPBAR_COUNT
};

enum
{
	MC_HEADER_MR_STONE,
	MC_HEADER_PROF_BIRCH,
	MC_HEADER_BRENDAN,
	MC_HEADER_MAY,
	MC_HEADER_WALLY,
	MC_HEADER_NORMAN,
	MC_HEADER_MOM,
	MC_HEADER_STEVEN,
	MC_HEADER_SCOTT,
	MC_HEADER_ROXANNE,
	MC_HEADER_BRAWLY,
	MC_HEADER_WATTSON,
	MC_HEADER_FLANNERY,
	MC_HEADER_WINONA,
	MC_HEADER_TATE_LIZA,
	MC_HEADER_JUAN,
	MC_HEADER_SIDNEY,
	MC_HEADER_PHOEBE,
	MC_HEADER_GLACIA,
	MC_HEADER_DRAKE,
	MC_HEADER_WALLACE,
	MC_HEADER_COUNT
};

enum
{
    MATCH_CALL_OPTION_CALL,
    MATCH_CALL_OPTION_CHECK,
    MATCH_CALL_OPTION_CANCEL,
    MATCH_CALL_OPTION_COUNT
};

enum
{
    CHECK_PAGE_STRATEGY,
    CHECK_PAGE_POKEMON,
    CHECK_PAGE_INTRO_1,
    CHECK_PAGE_INTRO_2,
    CHECK_PAGE_ENTRY_COUNT
};

#define MCFLAVOR(name) {[CHECK_PAGE_STRATEGY] = gText_MatchCall##name##_Strategy, \
                        [CHECK_PAGE_POKEMON]  = gText_MatchCall##name##_Pokemon,  \
                        [CHECK_PAGE_INTRO_1]  = gText_MatchCall##name##_Intro1,   \
                        [CHECK_PAGE_INTRO_2]  = gText_MatchCall##name##_Intro2}


// Pokenav Function IDs
// Indices into the LoopedTask tables for each of the main Pokenav features

enum RegionMapFuncIds
{
    POKENAV_MENU_FUNC_NONE,
    POKENAV_MENU_FUNC_MOVE_CURSOR,
    POKENAV_MENU_FUNC_OPEN_CONDITION,
    POKENAV_MENU_FUNC_RETURN_TO_MAIN,
    POKENAV_MENU_FUNC_OPEN_CONDITION_SEARCH,
    POKENAV_MENU_FUNC_RETURN_TO_CONDITION,
    POKENAV_MENU_FUNC_NO_RIBBON_WINNERS,
    POKENAV_MENU_FUNC_RESHOW_DESCRIPTION,
    POKENAV_MENU_FUNC_OPEN_FEATURE,
};

enum PartyConditionFuncIds
{
    PARTY_CONDITION_FUNC_NONE,
    PARTY_CONDITION_FUNC_SLIDE_MON_IN,
    PARTY_CONDITION_FUNC_RETURN,
    PARTY_CONDITION_FUNC_NO_TRANSITION,
    PARTY_CONDITION_FUNC_SLIDE_MON_OUT,
    PARTY_CONDITION_FUNC_ADD_MARKINGS,
    PARTY_CONDITION_FUNC_CLOSE_MARKINGS,
};

#define POKENAV_MENU_FUNC_EXIT  -1

enum
{
    POKENAV_MC_FUNC_NONE,
    POKENAV_MC_FUNC_DOWN,
    POKENAV_MC_FUNC_UP,
    POKENAV_MC_FUNC_PG_DOWN,
    POKENAV_MC_FUNC_PG_UP,
    POKENAV_MC_FUNC_SELECT,
    POKENAV_MC_FUNC_MOVE_OPTIONS_CURSOR,
    POKENAV_MC_FUNC_CANCEL,
    POKENAV_MC_FUNC_CALL_MSG,
    POKENAV_MC_FUNC_NEARBY_MSG,
    POKENAV_MC_FUNC_10,
    POKENAV_MC_FUNC_SHOW_CHECK_PAGE,
    POKENAV_MC_FUNC_CHECK_PAGE_UP,
    POKENAV_MC_FUNC_CHECK_PAGE_DOWN,
    POKENAV_MC_FUNC_EXIT_CHECK_PAGE,
    POKENAV_MC_FUNC_EXIT
};

enum
{
    POKENAV_MAP_FUNC_NONE,
    POKENAV_MAP_FUNC_CURSOR_MOVED,
    POKENAV_MAP_FUNC_ZOOM_OUT,
    POKENAV_MAP_FUNC_ZOOM_IN,
    POKENAV_MAP_FUNC_EXIT,
};

// pokenav.c
void SetSelectedConditionSearch(u32);
u32 GetSelectedConditionSearch(void);

void CB2_InitPokeNav(void);
u32 CreateLoopedTask(LoopedTask loopedTask, u32 priority);
bool32 FuncIsActiveLoopedTask(LoopedTask func);
void *GetSubstructPtr(u32 index);
void FreePokenavSubstruct(u32 index);
void *AllocSubstruct(u32 index, u32 size);
void Pokenav_AllocAndLoadPalettes(const struct SpritePalette *palettes);
bool32 IsLoopedTaskActive(u32 taskId);
void SetPokenavMode(u16 mode);
u32 GetPokenavMode(void);
bool32 CanViewRibbonsMenu(void);
void SetPokenavVBlankCallback(void);
void SetVBlankCallback_(IntrCallback callback);

// pokenav_match_call_ui.c
u32 GetSelectedPokenavListIndex(void);
bool32 sub_81C8224(void);
int MatchCall_MoveCursorUp(void);
int MatchCall_MoveCursorDown(void);
int MatchCall_PageDown(void);
int MatchCall_PageUp(void);
bool32 IsMonListLoopedTaskActive(void);
void ToggleMatchCallVerticalArrows(bool32 shouldHide);
void sub_81C8838(void);
void sub_81C877C(void);
bool32 IsMatchCallListTaskActive(void);
void PrintCheckPageInfo(s16 a0);
u32 GetMatchCallListTopIndex(void);
void sub_81C87F0(void);
bool32 sub_81C81D4(const struct BgTemplate *arg0, struct PokenavListTemplate *arg1, s32 arg2);
void sub_81C8234(void);

// pokenav_match_call_data.c
bool32 MatchCall_HasCheckPage(u32 idx);
u8 MatchCall_GetMapSec(u32 idx);
bool32 MatchCall_HasRematchId(u32 idx);
bool32 MatchCall_GetEnabled(u32 idx);
u32 MatchCall_GetRematchTableIdx(u32 idx);
u32 GetTrainerIdxByRematchIdx(u32 rematchIdx);
int MatchCall_GetOverrideFacilityClass(u32 idx);
void MatchCall_GetMessage(u32 idx, u8 *dest);
const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset);
void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name);

// pokenav_main_menu.c
bool32 InitPokenavMainMenu(void);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size);
void RunMainMenuLoopedTask(u32 a0);
u32 IsActiveMenuLoopTaskActive(void);
void LoadLeftHeaderGfxForIndex(u32 arg0);
void ShowLeftHeaderGfx(u32 menugfxId, bool32 arg1, bool32 isOnRightSide);
void PokenavFadeScreen(s32 fadeType);
bool32 AreLeftHeaderSpritesMoving(void);
void InitBgTemplates(const struct BgTemplate *templates, int count);
bool32 IsPaletteFadeActive(void);
void PrintHelpBarText(u32 textId);
bool32 WaitForHelpBar(void);
void SlideMenuHeaderDown(void);
bool32 MainMenuLoopedTaskIsBusy(void);
void SetLeftHeaderSpritesInvisibility(void);
void PokenavCopyPalette(const u16 *a0, const u16 *a1, int a2, int a3, int a4, u16 *palette);
void sub_81C7B40(void);
struct Sprite *PauseSpinningPokenavSprite(void);
void ResumeSpinningPokenavSprite(void);
void UpdateRegionMapRightHeaderTiles(u32 arg0);
void HideMainOrSubMenuLeftHeader(u32 id, bool32 onRightSide);
void SlideMenuHeaderUp(void);
void PokenavFillPalette(u32 palIndex, u16 fillValue);
u32 PokenavMainMenuLoopedTaskIsActive(void);
bool32 WaitForPokenavShutdownFade(void);
void SetActiveMenuLoopTasks(void *func1, void *func2);
void ShutdownPokenav(void);

// pokenav_menu_handler_1.c
bool32 PokenavCallback_Init_MainMenuCursorOnMap(void);
bool32 PokenavCallback_Init_MainMenuCursorOnMatchCall(void);
bool32 PokenavCallback_Init_MainMenuCursorOnRibbons(void);
bool32 PokenavCallback_Init_ConditionMenu(void);
bool32 PokenavCallback_Init_ConditionSearchMenu(void);
u32 GetMenuHandlerCallback(void);
void FreeMenuHandlerSubstruct1(void);
int GetPokenavMenuType(void);
int GetPokenavCursorPos(void);
int GetCurrentMenuItemId(void);
u16 GetHelpBarTextId(void);

// pokenav_menu_handler_2.c
bool32 OpenPokenavMenuInitial(void);
bool32 OpenPokenavMenuNotInitial(void);
void CreateMenuHandlerLoopedTask(s32 ltIdx);
bool32 IsMenuHandlerLoopedTaskActive(void);
void FreeMenuHandlerSubstruct2(void);
void ResetBldCnt_(void);

// pokenav_match_call_1.c
bool32 PokenavCallback_Init_MatchCall(void);
u32 GetMatchCallCallback(void);
void FreeMatchCallSubstruct1(void);
int sub_81CAE28(void);
int GetNumberRegistered(void);
int sub_81CAE48(void);
struct PokenavMatchCallEntries *sub_81CAE94(void);
u16 GetMatchCallMapSec(int);
bool32 ShouldDrawRematchPokeballIcon(int index);
void ClearRematchPokeballIcon(u16 windowId, u32 a1);
int GetMatchCallTrainerPic(int index);
const u8 *GetMatchCallFlavorText(int index, int textType);
const u8 *GetMatchCallMessageText(int index, u8 *arg1);
u16 GetMatchCallOptionCursorPos(void);
u16 GetMatchCallOptionId(int arg0);
void BufferMatchCallNameAndDesc(struct PokenavMatchCallEntries * arg0, u8 *str);
u8 GetMatchTableMapSectionId(int rematchIndex);
int GetIndexDeltaOfNextCheckPageDown(int index);
int GetIndexDeltaOfNextCheckPageUp(int index);
bool32 IsRematchEntryRegistered(int index);

// pokenav_match_call_2.c
bool32 OpenMatchCall(void);
void CreateMatchCallLoopedTask(s32 index);
bool32 IsMatchCallLoopedTaskActive(void);
void FreeMatchCallSubstruct2(void);

// pokenav_region_map.c
u32 PokenavCallback_Init_RegionMap(void);
u32 GetRegionMapCallback(void);
bool32 OpenPokenavRegionMap(void);
void CreateRegionMapLoopedTask(s32);
bool32 IsRegionMapLoopedTaskActive(void);
void FreeRegionMapSubstruct1(void);
void FreeRegionMapSubstruct2(void);

// pokenav_conditions_1.c
u32 PokenavCallback_Init_PartyCondition(void);
u32 PokenavCallback_Init_ConditionGraphFromSearch(void);
u32 GetPartyConditionCallback(void);
void FreePartyConditionSubstruct1(void);
bool32 LoadPartyConditionMenuGfx(void);
bool32 IsConditionMenuSearchMode(void);
struct ConditionGraph *GetConditionGraphDataPtr(void);
u16 GetConditionGraphCurrentMonIndex(void);
u16 GetMonListCount(void);
u8 GetMonSheen(void);
bool32 SetConditionGraphData(u8 arg0);
u8 TryGetMonMarkId(void);
u8 *GetConditionMonNameBuffer(u8 id);
u8 *GetConditionMonLocationBuffer(u8 id);
u16 GetConditionMonDataBuffer(void);
void *GetConditionMonPicGfx(u8 id);
void *GetConditionMonPal(u8 id);

// pokenav_conditions_2.c
bool32 OpenPartyConditionMenu(void);
void CreatePartyConditionLoopedTask(s32);
u32 IsPartyConditionLoopedTaskActive(void);
void FreePartyConditionSubstruct2(void);
u8 GetMonMarkingsData(void);

// pokenav_conditions_3.c
u32 PokenavCallback_Init_ConditionSearch(void);
u32 PokenavCallback_Init_ReturnToMonSearchList(void);
u32 GetConditionSearchResultsCallback(void);
void FreeSearchResultSubstruct1(void);
bool32 OpenConditionSearchResults(void);
bool32 OpenConditionSearchListFromGraph(void);
void CreateSearchResultsLoopedTask(s32);
u32 IsSearchResultLoopedTaskActive(void);
void FreeSearchResultSubstruct2(void);

// pokenav_ribbons_1.c
u32 PokenavCallback_Init_MonRibbonList(void);
u32 PokenavCallback_Init_RibbonsMonListFromSummary(void);
u32 GetRibbonsMonListCallback(void);
void FreeRibbonsMonList1(void);
bool32 OpenRibbonsMonList(void);
bool32 OpenRibbonsMonListFromRibbonsSummary(void);
void CreateRibbonsMonListLoopedTask(s32);
u32 IsRibbonsMonListLoopedTaskActive(void);
void FreeRibbonsMonList2(void);

// pokenav_ribbons_2.c
u32 PokenavCallback_Init_RibbonsSummaryMenu(void);
u32 GetRibbonsSummaryMenuCallback(void);
void FreeRibbonsSummaryScreen1(void);
bool32 OpenRibbonsSummaryMenu(void);
void CreateRibbonsSummaryLoopedTask(s32);
u32 IsRibbonsSummaryLoopedTaskActive(void);
void FreeRibbonsSummaryScreen2(void);

#endif // GUARD_POKENAV_H
