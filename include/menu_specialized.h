#ifndef GUARD_MENU_SPECIALIZED_H
#define GUARD_MENU_SPECIALIZED_H

#include "sprite.h"
#include "player_pc.h"
#include "list_menu.h"
#include "pokemon.h"
#include "constants/berry.h"

#define TAG_CONDITION_MON              100
#define TAG_CONDITION_BALL             101
#define TAG_CONDITION_CANCEL           102
#define TAG_CONDITION_BALL_PLACEHOLDER 103
#define TAG_CONDITION_SPARKLE          104

#define MAX_CONDITION_SPARKLES 10

// Window IDs for the Player PC Mailbox
enum {
    MAILBOXWIN_TITLE,
    MAILBOXWIN_LIST,
    MAILBOXWIN_OPTIONS,
    MAILBOXWIN_COUNT
};

struct UnknownSubStruct_81D1ED4
{
    u16 unk0;
    u16 unk2;
};

struct ConditionGraph
{
    /*0x000*/ u8 stat[4][FLAVOR_COUNT];
    /*0x014*/ struct UnknownSubStruct_81D1ED4 unk14[4][FLAVOR_COUNT];
    /*0x064*/ struct UnknownSubStruct_81D1ED4 unk64[10][FLAVOR_COUNT];
    /*0x12C*/ struct UnknownSubStruct_81D1ED4 unk12C[FLAVOR_COUNT];
    /*0x140*/ u16 unk140[66][2];
    /*0x248*/ u16 unk248[66][2];
    /*0x350*/ u16 unk350;
    /*0x352*/ u16 unk352;
    /*0x354*/ u8 unk354;
    /*0x355*/ u8 state;
};

bool8 MailboxMenu_Alloc(u8 count);
u8 MailboxMenu_AddWindow(u8 windowIdx);
u8 MailboxMenu_CreateList(struct PlayerPCItemPageStruct *page);
void MailboxMenu_AddScrollArrows(struct PlayerPCItemPageStruct *page);
void MailboxMenu_Free(void);
void MailboxMenu_RemoveWindow(u8 windowIdx);
void InitConditionGraphData(struct ConditionGraph *graph);
void sub_81D2108(struct ConditionGraph *graph);
void SetConditionGraphIOWindows(u8 bg);
void InitConditionGraphState(struct ConditionGraph *graph);
void sub_81D2230(struct ConditionGraph *graph);
bool8 SetupConditionGraphScanlineParams(struct ConditionGraph *graph);
bool32 TransitionConditionGraph(struct ConditionGraph *graph);
void sub_81D2754(u8 *arg0, struct UnknownSubStruct_81D1ED4 *arg1);
void sub_81D1F84(struct ConditionGraph *graph, struct UnknownSubStruct_81D1ED4 *arg1, struct UnknownSubStruct_81D1ED4 *arg2);
void MoveRelearnerPrintText(u8 *str);
bool16 MoveRelearnerRunTextPrinters(void);
void MoveRelearnerCreateYesNoMenu(void);
u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices);
void InitMoveRelearnerWindows(bool8 useContextWindow);
s32 GetBoxOrPartyMonData(u16 boxId, u16 monId, s32 request, u8 *dst);
void GetConditionMenuMonNameAndLocString(u8 *locationDst, u8 *nameDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel);
void GetConditionMenuMonConditions(struct ConditionGraph *graph, u8 *sheen, u16 boxId, u16 monId, u16 partyId, u16 id, u16 numMons, bool8 excludesCancel);
void GetConditionMenuMonGfx(void *tilesDst, void *palDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel);
bool8 MoveConditionMonOnscreen(s16 *x);
bool8 MoveConditionMonOffscreen(s16 *x);
bool8 TryUpdateConditionMonTransitionOn(struct ConditionGraph *graph, s16 *x);
bool8 TryUpdateConditionMonTransitionOff(struct ConditionGraph *graph, s16 *x);
void LoadConditionMonPicTemplate(struct SpriteSheet *sheet, struct SpriteTemplate *template, struct SpritePalette *pal);
void LoadConditionSelectionIcons(struct SpriteSheet *sheets, struct SpriteTemplate * template, struct SpritePalette *pals);
void LoadConditionSparkle(struct SpriteSheet *sheet, struct SpritePalette *pal);
void ResetConditionSparkleSprites(struct Sprite **sprites);
void CreateConditionSparkleSprites(struct Sprite **sprites, u8 monSpriteId, u8 count);
void DestroyConditionSparkleSprites(struct Sprite **sprites);
void FreeConditionSparkles(struct Sprite **sprites);
void DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr);
void DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr);
void GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats);

#endif // GUARD_MENU_SPECIALIZED_H
