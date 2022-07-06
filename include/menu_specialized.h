#ifndef GUARD_MENU_SPECIALIZED_H
#define GUARD_MENU_SPECIALIZED_H

#include "sprite.h"
#include "player_pc.h"
#include "list_menu.h"
#include "pokemon.h"
#include "constants/berry.h"

// Window IDs for the Player PC Mailbox
enum {
    MAILBOXWIN_TITLE,
    MAILBOXWIN_LIST,
    MAILBOXWIN_OPTIONS,
    MAILBOXWIN_COUNT
};

enum {
    TAG_CONDITION_MON = 100,
    TAG_CONDITION_BALL,
    TAG_CONDITION_CANCEL,
    TAG_CONDITION_BALL_PLACEHOLDER,
    TAG_CONDITION_SPARKLE,
    TAG_CONDITION_MON_MARKINGS,
    TAG_CONDITION_MARKINGS_MENU,
    TAG_CONDITION_MARKINGS_MENU_2, // Used implicitly by CreateMonMarkingsMenuSprites
};

enum {
    CONDITION_ICON_SELECTED,
    CONDITION_ICON_UNSELECTED,
};

#define MAX_CONDITION_SPARKLES 10

// The number of extra sparkles shown on a Pokémon's condition screen.
// All Pokémon start with 1, so the max here is MAX_CONDITION_SPARKLES - 1
#define GET_NUM_CONDITION_SPARKLES(sheen)((sheen) != MAX_SHEEN) ? (sheen) / ((u32)MAX_SHEEN / (MAX_CONDITION_SPARKLES - 1) + 1) : MAX_CONDITION_SPARKLES - 1;

#define CONDITION_GRAPH_TOP_Y  56
#define CONDITION_GRAPH_BOTTOM_Y 121
#define CONDITION_GRAPH_HEIGHT  (CONDITION_GRAPH_BOTTOM_Y - CONDITION_GRAPH_TOP_Y + 1)
#define CONDITION_GRAPH_CENTER_X 155
#define CONDITION_GRAPH_CENTER_Y ((CONDITION_GRAPH_BOTTOM_Y + CONDITION_GRAPH_TOP_Y) / 2 + 3)
#define CONDITION_GRAPH_UPDATE_STEPS 10
#define CONDITION_GRAPH_LOAD_MAX 4

// Equivalent to flavor and contest values, but in a different order.
enum {
    CONDITION_COOL,
    CONDITION_TOUGH,
    CONDITION_SMART,
    CONDITION_CUTE,
    CONDITION_BEAUTY,
    CONDITION_COUNT
};

// Yet another order. This one is the same (by coincidence) as the contest categories
enum {
    GRAPH_COOL,
    GRAPH_BEAUTY,
    GRAPH_CUTE,
    GRAPH_SMART,
    GRAPH_TOUGH,
};

struct ConditionGraph
{
    /*0x000*/ u8 conditions[CONDITION_GRAPH_LOAD_MAX][CONDITION_COUNT];
    /*0x014*/ struct UCoords16 savedPositions[CONDITION_GRAPH_LOAD_MAX][CONDITION_COUNT];
    /*0x064*/ struct UCoords16 newPositions[CONDITION_GRAPH_UPDATE_STEPS][CONDITION_COUNT];
    /*0x12C*/ struct UCoords16 curPositions[CONDITION_COUNT];
    /*0x140*/ u16 scanlineRight[CONDITION_GRAPH_HEIGHT][2];
    /*0x248*/ u16 scanlineLeft[CONDITION_GRAPH_HEIGHT][2];
    /*0x350*/ u16 bottom;
    /*0x352*/ u16 updateCounter;
    /*0x354*/ bool8 needsDraw;
    /*0x355*/ u8 scanlineResetState;
};

// Mailbox menu
bool8 MailboxMenu_Alloc(u8 count);
u8 MailboxMenu_AddWindow(u8 windowIdx);
u8 MailboxMenu_CreateList(struct PlayerPCItemPageStruct *page);
void MailboxMenu_AddScrollArrows(struct PlayerPCItemPageStruct *page);
void MailboxMenu_Free(void);
void MailboxMenu_RemoveWindow(u8 windowIdx);

// Condition graph
void ConditionGraph_Init(struct ConditionGraph *graph);
void ConditionGraph_InitWindow(u8 bg);
void ConditionGraph_InitResetScanline(struct ConditionGraph *graph);
bool8 ConditionGraph_ResetScanline(struct ConditionGraph *graph);
void ConditionGraph_Draw(struct ConditionGraph *graph);
bool8 ConditionGraph_TryUpdate(struct ConditionGraph *graph);
void ConditionGraph_Update(struct ConditionGraph *graph);
void ConditionGraph_CalcPositions(u8 *conditions, struct UCoords16 *positions);
void ConditionGraph_SetNewPositions(struct ConditionGraph *graph, struct UCoords16 *old, struct UCoords16 *new);

// Condition menu
bool8 ConditionMenu_UpdateMonEnter(struct ConditionGraph *graph, s16 *x);
bool8 ConditionMenu_UpdateMonExit(struct ConditionGraph *graph, s16 *x);
bool8 MoveConditionMonOnscreen(s16 *x);
bool8 MoveConditionMonOffscreen(s16 *x);
void GetConditionMenuMonNameAndLocString(u8 *locationDst, u8 *nameDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel);
void GetConditionMenuMonConditions(struct ConditionGraph *graph, u8 *sheen, u16 boxId, u16 monId, u16 partyId, u16 id, u16 numMons, bool8 excludesCancel);
void GetConditionMenuMonGfx(void *tilesDst, void *palDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel);
void LoadConditionMonPicTemplate(struct SpriteSheet *sheet, struct SpriteTemplate *template, struct SpritePalette *pal);
void LoadConditionSelectionIcons(struct SpriteSheet *sheets, struct SpriteTemplate * template, struct SpritePalette *pals);
s32 GetBoxOrPartyMonData(u16 boxId, u16 monId, s32 request, u8 *dst);

// Condition sparkles
void LoadConditionSparkle(struct SpriteSheet *sheet, struct SpritePalette *pal);
void ResetConditionSparkleSprites(struct Sprite **sprites);
void CreateConditionSparkleSprites(struct Sprite **sprites, u8 monSpriteId, u8 count);
void DestroyConditionSparkleSprites(struct Sprite **sprites);
void FreeConditionSparkles(struct Sprite **sprites);

// Move relearner
void MoveRelearnerPrintText(u8 *str);
bool16 MoveRelearnerRunTextPrinters(void);
void MoveRelearnerCreateYesNoMenu(void);
u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices);
void InitMoveRelearnerWindows(bool8 useContextWindow);

// Level up window
void DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr);
void DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr);
void GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats);

#endif // GUARD_MENU_SPECIALIZED_H
