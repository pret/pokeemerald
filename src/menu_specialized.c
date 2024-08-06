#include "global.h"
#include "malloc.h"
#include "battle_main.h"
#include "contest_effect.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "menu.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_specialized.h"
#include "move_relearner.h"
#include "palette.h"
#include "player_pc.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/battle_move_effects.h"
#include "gba/io_reg.h"

EWRAM_DATA static u8 sMailboxWindowIds[MAILBOXWIN_COUNT] = {0};
EWRAM_DATA static struct ListMenuItem *sMailboxList = NULL;

static void MailboxMenu_MoveCursorFunc(s32, bool8, struct ListMenu *);
static void ConditionGraph_CalcRightHalf(struct ConditionGraph *);
static void ConditionGraph_CalcLeftHalf(struct ConditionGraph *);
static void MoveRelearnerCursorCallback(s32, bool8, struct ListMenu *);
static void MoveRelearnerDummy(void);
static void SetNextConditionSparkle(struct Sprite *);
static void SpriteCB_ConditionSparkle(struct Sprite *);
static void ShowAllConditionSparkles(struct Sprite *);

static const struct WindowTemplate sWindowTemplates_MailboxMenu[MAILBOXWIN_COUNT] =
{
    [MAILBOXWIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x8
    },
    [MAILBOXWIN_LIST] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 1,
        .width = 8,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x18
    },
    [MAILBOXWIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 11,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 0x18
    }
};

static const u8 sPlayerNameTextColors[] =
{
    TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY
};

static const u8 sEmptyItemName[] = _("");

static const struct ScanlineEffectParams sConditionGraphScanline =
{
    .dmaDest = &REG_WIN0H,
    .dmaControl = SCANLINE_EFFECT_DMACNT_32BIT,
    .initState = 1,
};

static const u8 sConditionToLineLength[MAX_CONDITION + 1] =
{
     4,  5,  6,  7,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 13,
    13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 17,
    17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19,
    19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21,
    21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23,
    23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24,
    24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26,
    26, 26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27,
    27, 27, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
    29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
    30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 33, 33, 33, 33, 33, 33, 33, 33,
    33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 34, 34, 34, 34,
    34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 35
};

static const struct WindowTemplate sMoveRelearnerWindowTemplates[] =
{
    [RELEARNERWIN_DESC_BATTLE] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 16,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 0xA
    },
    [RELEARNERWIN_DESC_CONTEST] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 16,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 0xCA
    },
    [RELEARNERWIN_MOVE_LIST] = {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 1,
        .width = 10,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 0x18A
    },
    [RELEARNERWIN_MSG] = {
        .bg = 1,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x202
    },
    // Unused. Identical to sMoveRelearnerYesNoMenuTemplate
    [RELEARNERWIN_YESNO] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 8,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x25A
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sMoveRelearnerYesNoMenuTemplate =
{
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 8,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x25A
};


static const struct ListMenuTemplate sMoveRelearnerMovesListTemplate =
{
    .items = NULL,
    .moveCursorFunc = MoveRelearnerCursorCallback,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = RELEARNERWIN_MOVE_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
    .textNarrowWidth = 68,
};

//--------------
// Mailbox menu
//--------------

bool8 MailboxMenu_Alloc(u8 count)
{
    u8 i;

    // + 1 to count for 'Cancel'
    sMailboxList = Alloc((count + 1) * sizeof(*sMailboxList));
    if (sMailboxList == NULL)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sMailboxWindowIds); i++)
        sMailboxWindowIds[i] = WINDOW_NONE;

    return TRUE;
}

u8 MailboxMenu_AddWindow(u8 windowIdx)
{
    if (sMailboxWindowIds[windowIdx] == WINDOW_NONE)
    {
        if (windowIdx == MAILBOXWIN_OPTIONS)
        {
            struct WindowTemplate template = sWindowTemplates_MailboxMenu[windowIdx];
            template.width = GetMaxWidthInMenuTable(&gMailboxMailOptions[0], 4);
            sMailboxWindowIds[windowIdx] = AddWindow(&template);
        }
        else // MAILBOXWIN_TITLE or MAILBOXWIN_LIST
        {
            sMailboxWindowIds[windowIdx] = AddWindow(&sWindowTemplates_MailboxMenu[windowIdx]);
        }
        SetStandardWindowBorderStyle(sMailboxWindowIds[windowIdx], FALSE);
    }
    return sMailboxWindowIds[windowIdx];
}

void MailboxMenu_RemoveWindow(u8 windowIdx)
{
    ClearStdWindowAndFrameToTransparent(sMailboxWindowIds[windowIdx], FALSE);
    ClearWindowTilemap(sMailboxWindowIds[windowIdx]);
    RemoveWindow(sMailboxWindowIds[windowIdx]);
    sMailboxWindowIds[windowIdx] = WINDOW_NONE;
}

static u8 UNUSED MailboxMenu_GetWindowId(u8 windowIdx)
{
    return sMailboxWindowIds[windowIdx];
}

static void MailboxMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    u8 buffer[30];
    u16 length;

    if (itemId == LIST_CANCEL)
        return;

    StringCopy(buffer, gSaveBlock1Ptr->mail[PARTY_SIZE + itemId].playerName);
    ConvertInternationalPlayerName(buffer);
    length = StringLength(buffer);
    if (length < PLAYER_NAME_LENGTH - 1)
        ConvertInternationalString(buffer, LANGUAGE_JAPANESE);
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, 8, y, 0, 0, sPlayerNameTextColors, TEXT_SKIP_DRAW, buffer);
}

u8 MailboxMenu_CreateList(struct PlayerPCItemPageStruct *page)
{
    u16 i;
    for (i = 0; i < page->count; i++)
    {
        sMailboxList[i].name = sEmptyItemName;
        sMailboxList[i].id = i;
    }

    sMailboxList[i].name = gText_Cancel2;
    sMailboxList[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate.items = sMailboxList;
    gMultiuseListMenuTemplate.totalItems = page->count + 1;
    gMultiuseListMenuTemplate.windowId = sMailboxWindowIds[MAILBOXWIN_LIST];
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.maxShowed = 8;
    gMultiuseListMenuTemplate.upText_Y = 9;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 1;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = MailboxMenu_MoveCursorFunc;
    gMultiuseListMenuTemplate.itemPrintFunc = MailboxMenu_ItemPrintFunc;
    gMultiuseListMenuTemplate.fontId = FONT_NORMAL;
    gMultiuseListMenuTemplate.cursorKind = CURSOR_BLACK_ARROW;
    gMultiuseListMenuTemplate.lettersSpacing = 0;
    gMultiuseListMenuTemplate.itemVerticalPadding = 0;
    gMultiuseListMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    return ListMenuInit(&gMultiuseListMenuTemplate, page->itemsAbove, page->cursorPos);
}

static void MailboxMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
}

void MailboxMenu_AddScrollArrows(struct PlayerPCItemPageStruct *page)
{
    page->scrollIndicatorTaskId = AddScrollIndicatorArrowPairParameterized(2, 0xC8, 12, 0x94, page->count - page->pageItems + 1, 0x6E, 0x6E, &page->itemsAbove);
}

void MailboxMenu_Free(void)
{
    Free(sMailboxList);
}

//---------------------------------------
// Condition graph
//
// This is the graph in the Pokénav and
// Pokéblock case that shows a Pokémon's
// conditions (Beauty, Tough, etc.).
// It works by using scanlines to
// selectively reveal a bg that has been
// filled with the graph color.
//---------------------------------------

#define SHIFT_RIGHT_ADJUSTED(n, s)(((n) >> (s)) + (((n) >> ((s) - 1)) & 1))

void ConditionGraph_Init(struct ConditionGraph *graph)
{
    u8 i, j;

    for (j = 0; j < CONDITION_COUNT; j++)
    {
        for (i = 0; i < CONDITION_GRAPH_UPDATE_STEPS; i++)
        {
            graph->newPositions[i][j].x = 0;
            graph->newPositions[i][j].y = 0;
        }

        for (i = 0; i < CONDITION_GRAPH_LOAD_MAX; i++)
        {
            graph->conditions[i][j] = 0;
            graph->savedPositions[i][j].x = CONDITION_GRAPH_CENTER_X;
            graph->savedPositions[i][j].y = CONDITION_GRAPH_CENTER_Y;
        }

        graph->curPositions[j].x = 0;
        graph->curPositions[j].y = 0;
    }

    graph->needsDraw = FALSE;
    graph->updateCounter = 0;
}

// Fills the newPositions array with incremental positions between
// old and new for the graph transition when switching between Pokémon.
void ConditionGraph_SetNewPositions(struct ConditionGraph *graph, struct UCoords16 *old, struct UCoords16 *new)
{
    u16 i, j;
    s32 coord, increment;

    for (i = 0; i < CONDITION_COUNT; i++)
    {
        coord = old[i].x << 8;
        increment = ((new[i].x - old[i].x) << 8) / CONDITION_GRAPH_UPDATE_STEPS;
        for (j = 0; j < CONDITION_GRAPH_UPDATE_STEPS - 1; j++)
        {
            graph->newPositions[j][i].x = SHIFT_RIGHT_ADJUSTED(coord, 8);
            coord += increment;
        }
        graph->newPositions[j][i].x = new[i].x;

        coord = old[i].y << 8;
        increment = ((new[i].y - old[i].y) << 8) / CONDITION_GRAPH_UPDATE_STEPS;
        for (j = 0; j < CONDITION_GRAPH_UPDATE_STEPS - 1; j++)
        {
            graph->newPositions[j][i].y = SHIFT_RIGHT_ADJUSTED(coord, 8);
            coord += increment;
        }
        graph->newPositions[j][i].y = new[i].y;
    }

    graph->updateCounter = 0;
}

bool8 ConditionGraph_TryUpdate(struct ConditionGraph *graph)
{
    if (graph->updateCounter < CONDITION_GRAPH_UPDATE_STEPS)
    {
        ConditionGraph_Update(graph);
        return (++graph->updateCounter != CONDITION_GRAPH_UPDATE_STEPS);
    }
    else
    {
        return FALSE;
    }
}

void ConditionGraph_InitResetScanline(struct ConditionGraph *graph)
{
    graph->scanlineResetState = 0;
}

bool8 ConditionGraph_ResetScanline(struct ConditionGraph *graph)
{
    struct ScanlineEffectParams params;

    switch (graph->scanlineResetState)
    {
    case 0:
        ScanlineEffect_Clear();
        graph->scanlineResetState++;
        return TRUE;
    case 1:
        params = sConditionGraphScanline;
        ScanlineEffect_SetParams(params);
        graph->scanlineResetState++;
        return FALSE;
    default:
        return FALSE;
    }
}

void ConditionGraph_Draw(struct ConditionGraph *graph)
{
    u16 i;

    if (!graph->needsDraw)
        return;

    ConditionGraph_CalcRightHalf(graph);
    ConditionGraph_CalcLeftHalf(graph);

    for (i = 0; i < CONDITION_GRAPH_HEIGHT; i++)
    {
        // Draw right half
        gScanlineEffectRegBuffers[1][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 0] = // double assignment
        gScanlineEffectRegBuffers[0][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 0] = (graph->scanlineRight[i][0] << 8) | (graph->scanlineRight[i][1]);
        // Draw left half
        gScanlineEffectRegBuffers[1][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 1] = // double assignment
        gScanlineEffectRegBuffers[0][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 1] = (graph->scanlineLeft[i][0] << 8) | (graph->scanlineLeft[i][1]);
    }

    graph->needsDraw = FALSE;
}

void ConditionGraph_InitWindow(u8 bg)
{
    u32 flags;

    if (bg >= NUM_BACKGROUNDS)
        bg = 0;

    // Unset the WINOUT flag for the bg.
    flags = (WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ) & ~(1 << bg);

    // Set limits for graph data
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE( 0, DISPLAY_WIDTH)); // Right side horizontal
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE( 0, CONDITION_GRAPH_CENTER_X)); // Left side horizontal
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(CONDITION_GRAPH_TOP_Y, CONDITION_GRAPH_BOTTOM_Y)); // Right side vertical
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(CONDITION_GRAPH_TOP_Y, CONDITION_GRAPH_BOTTOM_Y)); // Left side vertical
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, flags);
}

void ConditionGraph_Update(struct ConditionGraph *graph)
{
    u16 i;
    for (i = 0; i < CONDITION_COUNT; i++)
        graph->curPositions[i] = graph->newPositions[graph->updateCounter][i];

    graph->needsDraw = TRUE;
}

static void ConditionGraph_CalcLine(struct ConditionGraph *graph, u16 *scanline, struct UCoords16 *pos1, struct UCoords16 *pos2, bool8 dir, u16 *overflowScanline)
{
    u16 i, height, top, bottom, x2;
    u16 *ptr;
    s32 x, xIncrement = 0;

    if (pos1->y < pos2->y)
    {
        top = pos1->y;
        bottom = pos2->y;
        x = pos1->x << 10;
        x2 = pos2->x;
        height = bottom - top;
        if (height != 0)
            xIncrement = ((x2 - pos1->x) << 10) / height;
    }
    else
    {
        bottom = pos1->y;
        top = pos2->y;
        x = pos2->x << 10;
        x2 = pos1->x;
        height = bottom - top;
        if (height != 0)
            xIncrement = ((x2 - pos2->x) << 10) / height;
    }

    height++;
    if (overflowScanline == NULL)
    {
        scanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        for (i = 0; i < height; i++)
        {
            scanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            x += xIncrement;
            scanline += 2;
        }

        ptr = scanline - 2;
    }
    else if (xIncrement > 0)
    {
        overflowScanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        // Less readable than the other loops, but it has to be written this way to match.
        for (i = 0; i < height; overflowScanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir, x += xIncrement, overflowScanline += 2, i++)
        {
            if (x >= (CONDITION_GRAPH_CENTER_X << 10))
                break;
        }

        graph->bottom = top + i;
        scanline += (graph->bottom - CONDITION_GRAPH_TOP_Y) * 2;
        for (; i < height; i++)
        {
            scanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            x += xIncrement;
            scanline += 2;
        }

        ptr = scanline - 2;
    }
    else if (xIncrement < 0)
    {
        scanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        for (i = 0; i < height; i++)
        {
            scanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            if (x < (CONDITION_GRAPH_CENTER_X << 10))
            {
                scanline[dir] = CONDITION_GRAPH_CENTER_X;
                break;
            }
            x += xIncrement;
            scanline += 2;
        }

        graph->bottom = top + i;
        overflowScanline += (graph->bottom - CONDITION_GRAPH_TOP_Y) * 2;
        for (; i < height; i++)
        {
            overflowScanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            x += xIncrement;
            overflowScanline += 2;
        }

        ptr = overflowScanline - 2;
    }
    else
    {
        graph->bottom = top;
        scanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        overflowScanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        scanline[1] = pos1->x + 1;
        overflowScanline[0] = pos2->x;
        overflowScanline[1] = CONDITION_GRAPH_CENTER_X;
        return;
    }

    ptr[dir] = dir + x2;
}

static void ConditionGraph_CalcRightHalf(struct ConditionGraph *graph)
{
    u16 i, y, bottom;

    // Calculate Cool -> Beauty line
    if (graph->curPositions[GRAPH_COOL].y < graph->curPositions[GRAPH_BEAUTY].y)
    {
        y = graph->curPositions[GRAPH_COOL].y;
        ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_COOL], &graph->curPositions[GRAPH_BEAUTY], TRUE, NULL);
    }
    else
    {
        y = graph->curPositions[GRAPH_BEAUTY].y;
        ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_BEAUTY], &graph->curPositions[GRAPH_COOL], FALSE, NULL);
    }

    // Calculate Beauty -> Cute line
    // No need for conditional, positions on the Beauty line are always above the Cute line
    ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_BEAUTY], &graph->curPositions[GRAPH_CUTE], TRUE, NULL);

    // Calculate Cute -> Smart line (includes left scanline because this crosses the halfway point)
    i = (graph->curPositions[GRAPH_CUTE].y <= graph->curPositions[GRAPH_SMART].y);
    ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_CUTE], &graph->curPositions[GRAPH_SMART], i, graph->scanlineLeft[0]);

    // Clear down to new top
    for (i = CONDITION_GRAPH_TOP_Y; i < y; i++)
    {
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = graph->curPositions[GRAPH_COOL].y; i <= graph->bottom; i++)
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = CONDITION_GRAPH_CENTER_X;

    // Clear after new bottom
    bottom = max(graph->bottom, graph->curPositions[GRAPH_CUTE].y);
    for (i = bottom + 1; i <= CONDITION_GRAPH_BOTTOM_Y; i++)
    {
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = CONDITION_GRAPH_TOP_Y; i <= CONDITION_GRAPH_BOTTOM_Y; i++)
    {
        if (graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] == 0
         && graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][1] != 0)
            graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = CONDITION_GRAPH_CENTER_X;
    }
}

static void ConditionGraph_CalcLeftHalf(struct ConditionGraph *graph)
{
    s32 i, y, bottom;

    // Calculate Cool -> Tough line
    if (graph->curPositions[GRAPH_COOL].y < graph->curPositions[GRAPH_TOUGH].y)
    {
        y = graph->curPositions[GRAPH_COOL].y;
        ConditionGraph_CalcLine(graph, graph->scanlineLeft[0], &graph->curPositions[GRAPH_COOL], &graph->curPositions[GRAPH_TOUGH], FALSE, NULL);
    }
    else
    {
        y = graph->curPositions[GRAPH_TOUGH].y;
        ConditionGraph_CalcLine(graph, graph->scanlineLeft[0], &graph->curPositions[GRAPH_TOUGH], &graph->curPositions[GRAPH_COOL], TRUE, NULL);
    }

    // Calculate Tough -> Smart line
    // No need for conditional, positions on the Tough line are always above the Smart line
    ConditionGraph_CalcLine(graph, graph->scanlineLeft[0], &graph->curPositions[GRAPH_TOUGH], &graph->curPositions[GRAPH_SMART], FALSE, NULL);

    // Clear down to new top
    for (i = CONDITION_GRAPH_TOP_Y; i < y; i++)
    {
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = graph->curPositions[GRAPH_COOL].y; i <= graph->bottom; i++)
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][1] = CONDITION_GRAPH_CENTER_X;

    // Clear after new bottom
    bottom = max(graph->bottom, graph->curPositions[GRAPH_SMART].y + 1);
    for (i = bottom; i <= CONDITION_GRAPH_BOTTOM_Y; i++)
    {
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = 0; i < CONDITION_GRAPH_HEIGHT; i++)
    {
        if (graph->scanlineLeft[i][0] >= graph->scanlineLeft[i][1])
        {
            graph->scanlineLeft[i][1] = 0;
            graph->scanlineLeft[i][0] = 0;
        }
    }
}

void ConditionGraph_CalcPositions(u8 *conditions, struct UCoords16 *positions)
{
    u8 lineLength, sinIdx;
    s8 posIdx;
    u16 i;

    // Cool is straight up-and-down (not angled), so no need for Sin
    lineLength = sConditionToLineLength[*(conditions++)];
    positions[GRAPH_COOL].x = CONDITION_GRAPH_CENTER_X;
    positions[GRAPH_COOL].y = CONDITION_GRAPH_CENTER_Y - lineLength;

    sinIdx = 64;
    posIdx = GRAPH_COOL;
    for (i = 1; i < CONDITION_COUNT; i++)
    {
        sinIdx += 51;
        if (--posIdx < 0)
            posIdx = CONDITION_COUNT - 1;

        if (posIdx == GRAPH_CUTE)
            sinIdx++;

        lineLength = sConditionToLineLength[*(conditions++)];
        positions[posIdx].x = CONDITION_GRAPH_CENTER_X + ((lineLength * gSineTable[64 + sinIdx]) >> 8);
        positions[posIdx].y = CONDITION_GRAPH_CENTER_Y - ((lineLength * gSineTable[sinIdx]) >> 8);

        if (posIdx <= GRAPH_CUTE && (lineLength != 32 || posIdx != GRAPH_CUTE))
            positions[posIdx].x++;
    }
}

//----------------
// Move relearner
//----------------

void InitMoveRelearnerWindows(bool8 useContestWindow)
{
    u8 i;

    InitWindows(sMoveRelearnerWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    for (i = 0; i < ARRAY_COUNT(sMoveRelearnerWindowTemplates) - 1; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(1));

    if (!useContestWindow)
    {
        PutWindowTilemap(RELEARNERWIN_DESC_BATTLE);
        DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_DESC_BATTLE, FALSE, 0x1, 0xE);
    }
    else
    {
        PutWindowTilemap(RELEARNERWIN_DESC_CONTEST);
        DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_DESC_CONTEST, FALSE, 1, 0xE);
    }
    PutWindowTilemap(RELEARNERWIN_MOVE_LIST);
    PutWindowTilemap(RELEARNERWIN_MSG);
    DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_MOVE_LIST, FALSE, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_MSG, FALSE, 1, 0xE);
    MoveRelearnerDummy();
    ScheduleBgCopyTilemapToVram(1);
}

static void MoveRelearnerDummy(void)
{

}

u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices)
{
    gMultiuseListMenuTemplate = sMoveRelearnerMovesListTemplate;
    gMultiuseListMenuTemplate.totalItems = numChoices;
    gMultiuseListMenuTemplate.items = items;

    if (numChoices < 6)
        gMultiuseListMenuTemplate.maxShowed = numChoices;
    else
        gMultiuseListMenuTemplate.maxShowed = 6;

    return gMultiuseListMenuTemplate.maxShowed;
}

static void MoveRelearnerLoadBattleMoveDescription(u32 chosenMove)
{
    s32 x;
    const struct MoveInfo *move;
    u8 buffer[32];
    const u8 *str;

    if (B_SHOW_CATEGORY_ICON == TRUE)
        MoveRelearnerShowHideCategoryIcon(chosenMove);

    FillWindowPixelBuffer(RELEARNERWIN_DESC_BATTLE, PIXEL_FILL(1));
    str = gText_MoveRelearnerBattleMoves;
    x = GetStringCenterAlignXOffset(FONT_NORMAL, str, 128);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, x, 1, TEXT_SKIP_DRAW, NULL);

    str = gText_MoveRelearnerPP;
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, 4, 41, TEXT_SKIP_DRAW, NULL);

    str = gText_MoveRelearnerPower;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 106);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_MoveRelearnerAccuracy;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 106);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, x, 41, TEXT_SKIP_DRAW, NULL);
    if (chosenMove == LIST_CANCEL)
    {
        // On "Cancel", skip printing move data
        CopyWindowToVram(RELEARNERWIN_DESC_BATTLE, COPYWIN_GFX);
        return;
    }
    move = &gMovesInfo[chosenMove];
    str = gTypesInfo[move->type].name;
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, 4, 25, TEXT_SKIP_DRAW, NULL);

    x = 4 + GetStringWidth(FONT_NORMAL, gText_MoveRelearnerPP, 0);
    ConvertIntToDecimalStringN(buffer, move->pp, STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, buffer, x, 41, TEXT_SKIP_DRAW, NULL);

    if (move->power < 2)
    {
        str = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->power, STR_CONV_MODE_LEFT_ALIGN, 3);
        str = buffer;
    }
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, 106, 25, TEXT_SKIP_DRAW, NULL);

    if (move->accuracy == 0)
    {
        str = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
        str = buffer;
    }
    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NORMAL, str, 106, 41, TEXT_SKIP_DRAW, NULL);

    if (move->effect != EFFECT_PLACEHOLDER)
        str = gMovesInfo[chosenMove].description;
    else
        str = gNotDoneYetDescription;

    AddTextPrinterParameterized(RELEARNERWIN_DESC_BATTLE, FONT_NARROW, str, 0, 65, 0, NULL);
}

static void MoveRelearnerMenuLoadContestMoveDescription(u32 chosenMove)
{
    s32 x;
    const u8 *str;
    const struct MoveInfo *move;

    MoveRelearnerShowHideHearts(chosenMove);
    FillWindowPixelBuffer(RELEARNERWIN_DESC_CONTEST, PIXEL_FILL(1));
    str = gText_MoveRelearnerContestMovesTitle;
    x = GetStringCenterAlignXOffset(FONT_NORMAL, str, 128);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_CONTEST, FONT_NORMAL, str, x, 1, TEXT_SKIP_DRAW, NULL);

    str = gText_MoveRelearnerAppeal;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 92);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_CONTEST, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_MoveRelearnerJam;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 92);
    AddTextPrinterParameterized(RELEARNERWIN_DESC_CONTEST, FONT_NORMAL, str, x, 41, TEXT_SKIP_DRAW, NULL);

    if (chosenMove == MENU_NOTHING_CHOSEN)
    {
        CopyWindowToVram(RELEARNERWIN_DESC_CONTEST, COPYWIN_GFX);
        return;
    }

    move = &gMovesInfo[chosenMove];
    str = gContestMoveTypeTextPointers[move->contestCategory];
    AddTextPrinterParameterized(RELEARNERWIN_DESC_CONTEST, FONT_NORMAL, str, 4, 25, TEXT_SKIP_DRAW, NULL);

    str = gContestEffectDescriptionPointers[move->contestEffect];
    AddTextPrinterParameterized(RELEARNERWIN_DESC_CONTEST, FONT_NARROW, str, 0, 65, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(RELEARNERWIN_DESC_CONTEST, COPYWIN_GFX);
}

static void MoveRelearnerCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
    MoveRelearnerLoadBattleMoveDescription(itemIndex);
    MoveRelearnerMenuLoadContestMoveDescription(itemIndex);
}

void MoveRelearnerPrintMessage(u8 *str)
{
    u8 speed;

    FillWindowPixelBuffer(RELEARNERWIN_MSG, PIXEL_FILL(1));
    gTextFlags.canABSpeedUpPrint = TRUE;
    speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized2(RELEARNERWIN_MSG, FONT_NORMAL, str, speed, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, 3);
}

bool16 MoveRelearnerRunTextPrinters(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(RELEARNERWIN_MSG);
}

void MoveRelearnerCreateYesNoMenu(void)
{
    CreateYesNoMenu(&sMoveRelearnerYesNoMenuTemplate, 1, 0xE, 0);
}

//----------------
// Condition menu
//----------------

s32 GetBoxOrPartyMonData(u16 boxId, u16 monId, s32 request, u8 *dst)
{
    s32 ret;

    if (boxId == TOTAL_BOXES_COUNT) // Party mon.
    {
        if (request == MON_DATA_NICKNAME || request == MON_DATA_OT_NAME)
            ret = GetMonData(&gPlayerParty[monId], request, dst);
        else
            ret = GetMonData(&gPlayerParty[monId], request);
    }
    else
    {
        if (request == MON_DATA_NICKNAME || request == MON_DATA_OT_NAME)
            ret = GetAndCopyBoxMonDataAt(boxId, monId, request, dst);
        else
            ret = GetBoxMonDataAt(boxId, monId, request);
    }

    return ret;
}

// Gets the name/gender/level string for the condition menu
static u8 *GetConditionMenuMonString(u8 *dst, u16 boxId, u16 monId)
{
    u16 box, mon, species, level, gender;
    struct BoxPokemon *boxMon;
    u8 *str;

    box = boxId;
    mon = monId;
    *(dst++) = EXT_CTRL_CODE_BEGIN;
    *(dst++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
    *(dst++) = TEXT_COLOR_BLUE;
    *(dst++) = TEXT_COLOR_TRANSPARENT;
    *(dst++) = TEXT_COLOR_LIGHT_BLUE;
    if (GetBoxOrPartyMonData(box, mon, MON_DATA_IS_EGG, NULL))
        return StringCopyPadded(dst, gText_EggNickname, 0, POKEMON_NAME_LENGTH + 2);
    GetBoxOrPartyMonData(box, mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
    species = GetBoxOrPartyMonData(box, mon, MON_DATA_SPECIES, NULL);
    if (box == TOTAL_BOXES_COUNT) // Party mon.
    {
        level = GetMonData(&gPlayerParty[mon], MON_DATA_LEVEL);
        gender = GetMonGender(&gPlayerParty[mon]);
    }
    else
    {
        boxMon = GetBoxedMonPtr(box, mon);
        gender = GetBoxMonGender(boxMon);
        level = GetLevelFromBoxMonExp(boxMon);
    }

    if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && !StringCompare(dst, GetSpeciesName(species)))
        gender = MON_GENDERLESS;

    for (str = dst; *str != EOS; str++)
        ;

    *(str++) = EXT_CTRL_CODE_BEGIN;
    *(str++) = EXT_CTRL_CODE_SKIP;
    *(str++) = 60;

    switch (gender)
    {
    default:
        *(str++) = CHAR_SPACE;
        break;
    case MON_MALE:
        *(str++) = EXT_CTRL_CODE_BEGIN;
        *(str++) = EXT_CTRL_CODE_COLOR;
        *(str++) = TEXT_COLOR_RED;
        *(str++) = EXT_CTRL_CODE_BEGIN;
        *(str++) = EXT_CTRL_CODE_SHADOW;
        *(str++) = TEXT_COLOR_LIGHT_RED;
        *(str++) = CHAR_MALE;
        break;
    case MON_FEMALE:
        *(str++) = EXT_CTRL_CODE_BEGIN;
        *(str++) = EXT_CTRL_CODE_COLOR;
        *(str++) = TEXT_COLOR_GREEN;
        *(str++) = EXT_CTRL_CODE_BEGIN;
        *(str++) = EXT_CTRL_CODE_SHADOW;
        *(str++) = TEXT_COLOR_LIGHT_GREEN;
        *(str++) = CHAR_FEMALE;
        break;
    }

    *(str++) = EXT_CTRL_CODE_BEGIN;
    *(str++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
    *(str++) = TEXT_COLOR_BLUE;
    *(str++) = TEXT_COLOR_TRANSPARENT;
    *(str++) = TEXT_COLOR_LIGHT_BLUE;
    *(str++) = CHAR_SLASH;
    *(str++) = CHAR_EXTRA_SYMBOL;
    *(str++) = CHAR_LV_2;
    str = ConvertIntToDecimalStringN(str, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    *(str++) = CHAR_SPACE;
    *str = EOS;

    return str;
}

// Buffers the string in src to dest up to n chars. If src is less than n chars, fill with spaces
static u8 *BufferConditionMenuSpacedStringN(u8 *dst, const u8 *src, s16 n)
{
    while (*src != EOS)
    {
        *(dst++) = *(src++);
        n--;
    }
    while (n-- > 0)
        *(dst++) = CHAR_SPACE;

    *dst = EOS;
    return dst;
}

void GetConditionMenuMonNameAndLocString(u8 *locationDst, u8 *nameDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel)
{
    u16 i;
    u16 box = boxId;
    u16 mon = monId;

    // In this and the below 2 functions, numMons is passed as the number of menu selections (which includes Cancel)
    // To indicate that the Cancel needs to be subtracted they pass an additional bool
    // Unclear why they didn't just subtract 1 when it gets passed instead
    if (!excludesCancel)
        numMons--;

    if (partyId != numMons)
    {
        GetConditionMenuMonString(nameDst, box, mon);
        locationDst[0] = EXT_CTRL_CODE_BEGIN;
        locationDst[1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        locationDst[2] = TEXT_COLOR_BLUE;
        locationDst[3] = TEXT_COLOR_TRANSPARENT;
        locationDst[4] = TEXT_COLOR_LIGHT_BLUE;
        if (box == TOTAL_BOXES_COUNT) // Party mon.
            BufferConditionMenuSpacedStringN(&locationDst[5], gText_InParty, BOX_NAME_LENGTH);
        else
            BufferConditionMenuSpacedStringN(&locationDst[5], GetBoxNamePtr(box), BOX_NAME_LENGTH);
    }
    else
    {
        for (i = 0; i < POKEMON_NAME_LENGTH + 2; i++)
            nameDst[i] = CHAR_SPACE;
        nameDst[i] = EOS;
        for (i = 0; i < BOX_NAME_LENGTH; i++)
            locationDst[i] = CHAR_SPACE;
        locationDst[i] = EOS;
    }
}

void GetConditionMenuMonConditions(struct ConditionGraph *graph, u8 *numSparkles, u16 boxId, u16 monId, u16 partyId, u16 id, u16 numMons, bool8 excludesCancel)
{
    u16 i;

    if (!excludesCancel)
        numMons--;

    if (partyId != numMons)
    {
        graph->conditions[id][CONDITION_COOL] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        graph->conditions[id][CONDITION_TOUGH] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        graph->conditions[id][CONDITION_SMART] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        graph->conditions[id][CONDITION_CUTE] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        graph->conditions[id][CONDITION_BEAUTY] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);

        numSparkles[id] = GET_NUM_CONDITION_SPARKLES(GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL));

        ConditionGraph_CalcPositions(graph->conditions[id], graph->savedPositions[id]);
    }
    else
    {
        for (i = 0; i < CONDITION_COUNT; i++)
        {
            graph->conditions[id][i] = 0;
            graph->savedPositions[id][i].x = CONDITION_GRAPH_CENTER_X;
            graph->savedPositions[id][i].y = CONDITION_GRAPH_CENTER_Y;
        }
    }
}

void GetConditionMenuMonGfx(void *tilesDst, void *palDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel)
{
    if (!excludesCancel)
        numMons--;

    if (partyId != numMons)
    {
        u16 species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES_OR_EGG, NULL);
        bool8 isShiny = GetBoxOrPartyMonData(boxId, monId, MON_DATA_IS_SHINY, NULL);
        u32 personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);

        LoadSpecialPokePic(tilesDst, species, personality, TRUE);
        LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), palDst);
    }
}

bool8 MoveConditionMonOnscreen(s16 *x)
{
    *x += 24;
    if (*x > 0)
        *x = 0;

    return (*x != 0);
}

bool8 MoveConditionMonOffscreen(s16 *x)
{
    *x -= 24;
    if (*x < -80)
        *x = -80;

    return (*x != -80);
}

bool8 ConditionMenu_UpdateMonEnter(struct ConditionGraph *graph, s16 *x)
{
    bool8 graphUpdating = ConditionGraph_TryUpdate(graph);
    bool8 monUpdating = MoveConditionMonOnscreen(x);

    return (graphUpdating || monUpdating);
}

bool8 ConditionMenu_UpdateMonExit(struct ConditionGraph *graph, s16 *x)
{
    bool8 graphUpdating = ConditionGraph_TryUpdate(graph);
    bool8 monUpdating = MoveConditionMonOffscreen(x);

    return (graphUpdating || monUpdating);
}

static const u32 sConditionPokeball_Gfx[] = INCBIN_U32("graphics/pokenav/condition/pokeball.4bpp");
static const u32 sConditionPokeballPlaceholder_Gfx[] = INCBIN_U32("graphics/pokenav/condition/pokeball_placeholder.4bpp");
static const u16 sConditionSparkle_Gfx[] = INCBIN_U16("graphics/pokenav/condition/sparkle.gbapal");
static const u32 sConditionSparkle_Pal[] = INCBIN_U32("graphics/pokenav/condition/sparkle.4bpp");

static const struct OamData sOam_ConditionMonPic =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOam_ConditionSelectionIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnim_ConditionSelectionIcon_Selected[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ConditionSelectionIcon_Unselected[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ConditionSelectionIcon[] =
{
    [CONDITION_ICON_SELECTED] = sAnim_ConditionSelectionIcon_Selected,
    [CONDITION_ICON_UNSELECTED] = sAnim_ConditionSelectionIcon_Unselected
};

// Just loads the generic data, up to the caller to load the actual sheet/pal for the specific mon
void LoadConditionMonPicTemplate(struct SpriteSheet *sheet, struct SpriteTemplate *template, struct SpritePalette *pal)
{
    struct SpriteSheet dataSheet = {NULL, MON_PIC_SIZE, TAG_CONDITION_MON};

    struct SpriteTemplate dataTemplate =
    {
        .tileTag = TAG_CONDITION_MON,
        .paletteTag = TAG_CONDITION_MON,
        .oam = &sOam_ConditionMonPic,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    struct SpritePalette dataPal = {NULL, TAG_CONDITION_MON};

    *sheet = dataSheet;
    *template = dataTemplate;
    *pal = dataPal;
}

void LoadConditionSelectionIcons(struct SpriteSheet *sheets, struct SpriteTemplate * template, struct SpritePalette *pals)
{
    u8 i;

    struct SpriteSheet dataSheets[] =
    {
        {sConditionPokeball_Gfx, 0x100, TAG_CONDITION_BALL},
        {sConditionPokeballPlaceholder_Gfx, 0x20, TAG_CONDITION_BALL_PLACEHOLDER},
        {gPokenavConditionCancel_Gfx, 0x100, TAG_CONDITION_CANCEL},
        {},
    };

    struct SpritePalette dataPals[] =
    {
        {gPokenavConditionCancel_Pal, TAG_CONDITION_BALL},
        {gPokenavConditionCancel_Pal + 16, TAG_CONDITION_CANCEL},
        {},
    };

    // Tag is overwritten for the other selection icons
    struct SpriteTemplate dataTemplate =
    {
        .tileTag = TAG_CONDITION_BALL,
        .paletteTag = TAG_CONDITION_BALL,
        .oam = &sOam_ConditionSelectionIcon,
        .anims = sAnims_ConditionSelectionIcon,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    for (i = 0; i < ARRAY_COUNT(dataSheets); i++)
        *(sheets++) = dataSheets[i];

    *template = dataTemplate;

    for (i = 0; i < ARRAY_COUNT(dataPals); i++)
        *(pals++) = dataPals[i];
}

#define sSparkleId           data[0]
#define sDelayTimer          data[1]
#define sNumExtraSparkles    data[2]
#define sCurSparkleId        data[3]
#define sMonSpriteId         data[4]
#define sNextSparkleSpriteId data[5]

void LoadConditionSparkle(struct SpriteSheet *sheet, struct SpritePalette *pal)
{
    struct SpriteSheet dataSheet = {sConditionSparkle_Pal, 0x380, TAG_CONDITION_SPARKLE};
    struct SpritePalette dataPal = {sConditionSparkle_Gfx, TAG_CONDITION_SPARKLE};

    *sheet = dataSheet;
    *pal = dataPal;
}

static void SpriteCB_ConditionSparkle_DoNextAfterDelay(struct Sprite *sprite)
{
    if (++sprite->sDelayTimer > 60)
    {
        sprite->sDelayTimer = 0;
        SetNextConditionSparkle(sprite);
    }
}

static void SpriteCB_ConditionSparkle_WaitForAllAnim(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->sDelayTimer = 0;
        sprite->callback = SpriteCB_ConditionSparkle_DoNextAfterDelay;
    }
}

static const struct OamData sOam_ConditionSparkle =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .priority = 0,
};

static const union AnimCmd sAnim_ConditionSparkle[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ConditionSparkle[] =
{
    &sAnim_ConditionSparkle[0], // Only this entry is used
    &sAnim_ConditionSparkle[2],
    &sAnim_ConditionSparkle[4],
    &sAnim_ConditionSparkle[6],
    &sAnim_ConditionSparkle[8], // Here below OOB, will crash if used
    &sAnim_ConditionSparkle[10],
    &sAnim_ConditionSparkle[12],
};

static const struct SpriteTemplate sSpriteTemplate_ConditionSparkle =
{
    .tileTag = TAG_CONDITION_SPARKLE,
    .paletteTag = TAG_CONDITION_SPARKLE,
    .oam = &sOam_ConditionSparkle,
    .anims = sAnims_ConditionSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ConditionSparkle,
};

static const s16 sConditionSparkleCoords[MAX_CONDITION_SPARKLES][2] =
{
    {  0,  -35},
    { 20,  -28},
    { 33,  -10},
    { 33,   10},
    { 20,   28},
    {  0,   35},
    {-20,   28},
    {-33,   10},
    {-33,  -10},
    {-20,  -28},
};

static void SetConditionSparklePosition(struct Sprite *sprite)
{
    struct Sprite *mon = &gSprites[sprite->sMonSpriteId];

    if (mon != NULL)
    {
        sprite->x = mon->x + mon->x2 + sConditionSparkleCoords[sprite->sSparkleId][0];
        sprite->y = mon->y + mon->y2 + sConditionSparkleCoords[sprite->sSparkleId][1];
    }
    else
    {
        sprite->x = sConditionSparkleCoords[sprite->sSparkleId][0] + 40;
        sprite->y = sConditionSparkleCoords[sprite->sSparkleId][1] + 104;
    }
}

static void InitConditionSparkles(u8 count, bool8 allowFirstShowAll, struct Sprite **sprites)
{
    u16 i;

    for (i = 0; i < MAX_CONDITION_SPARKLES; i++)
    {
        if (sprites[i] != NULL)
        {
            sprites[i]->sSparkleId = i;
            sprites[i]->sDelayTimer = (i * 16) + 1;
            sprites[i]->sNumExtraSparkles = count;
            sprites[i]->sCurSparkleId = i;
            if (!allowFirstShowAll || count != MAX_CONDITION_SPARKLES - 1)
            {
                sprites[i]->callback = SpriteCB_ConditionSparkle;
            }
            else
            {
                SetConditionSparklePosition(sprites[i]);
                ShowAllConditionSparkles(sprites[i]);
                sprites[i]->callback = SpriteCB_ConditionSparkle_WaitForAllAnim;
                sprites[i]->invisible = FALSE;
            }
        }
    }
}

static void SetNextConditionSparkle(struct Sprite *sprite)
{
    u16 i;
    u8 id = sprite->sNextSparkleSpriteId;
    for (i = 0; i < sprite->sNumExtraSparkles + 1; i++)
    {
        gSprites[id].sDelayTimer = (gSprites[id].sSparkleId * 16) + 1;
        gSprites[id].callback = SpriteCB_ConditionSparkle;
        id = gSprites[id].sNextSparkleSpriteId;
    }
}

void ResetConditionSparkleSprites(struct Sprite **sprites)
{
    u8 i;

    for (i = 0; i < MAX_CONDITION_SPARKLES; i++)
        sprites[i] = NULL;
}

void CreateConditionSparkleSprites(struct Sprite **sprites, u8 monSpriteId, u8 _count)
{
    u16 i, spriteId, firstSpriteId = 0;
    u8 count = _count;

    for (i = 0; i < count + 1; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_ConditionSparkle, 0, 0, 0);
        if (spriteId != MAX_SPRITES)
        {
            sprites[i] = &gSprites[spriteId];
            sprites[i]->invisible = TRUE;
            sprites[i]->sMonSpriteId = monSpriteId;
            if (i != 0)
                sprites[i - 1]->sNextSparkleSpriteId = spriteId;
            else
                firstSpriteId = spriteId;
        }
        else
        {
            break;
        }
    }

    sprites[count]->sNextSparkleSpriteId = firstSpriteId;
    InitConditionSparkles(count, TRUE, sprites);
}

void DestroyConditionSparkleSprites(struct Sprite **sprites)
{
    u16 i;

    for (i = 0; i < MAX_CONDITION_SPARKLES; i++)
    {
        if (sprites[i] != NULL)
        {
            DestroySprite(sprites[i]);
            sprites[i] = NULL;
        }
        else
        {
            break;
        }
    }
}

void FreeConditionSparkles(struct Sprite **sprites)
{
    DestroyConditionSparkleSprites(sprites);
    FreeSpriteTilesByTag(TAG_CONDITION_SPARKLE);
    FreeSpritePaletteByTag(TAG_CONDITION_SPARKLE);
}

static void SpriteCB_ConditionSparkle(struct Sprite *sprite)
{
    // Delay, then do sparkle anim
    if (sprite->sDelayTimer != 0)
    {
        if (--sprite->sDelayTimer != 0)
            return;

        SeekSpriteAnim(sprite, 0);
        sprite->invisible = FALSE;
    }

    SetConditionSparklePosition(sprite);

    // Set up next sparkle
    if (sprite->animEnded)
    {
        sprite->invisible = TRUE;
        if (sprite->sCurSparkleId == sprite->sNumExtraSparkles)
        {
            if (sprite->sCurSparkleId == MAX_CONDITION_SPARKLES - 1)
            {
                ShowAllConditionSparkles(sprite);
                sprite->callback = SpriteCB_ConditionSparkle_WaitForAllAnim;
            }
            else
            {
                sprite->callback = SpriteCB_ConditionSparkle_DoNextAfterDelay;
            }
        }
        else
        {
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

static void ShowAllConditionSparkles(struct Sprite *sprite)
{
    u8 i, id = sprite->sNextSparkleSpriteId;

    for (i = 0; i < sprite->sNumExtraSparkles + 1; i++)
    {
        SeekSpriteAnim(&gSprites[id], 0);
        gSprites[id].invisible = FALSE;
        id = gSprites[id].sNextSparkleSpriteId;
    }
}

#undef sSparkleId
#undef sDelayTimer
#undef sNumExtraSparkles
#undef sCurSparkleId
#undef sMonSpriteId
#undef sNextSparkleSpriteId

static const u8 *const sLvlUpStatStrings[NUM_STATS] =
{
    gText_MaxHP,
    gText_Attack,
    gText_Defense,
    gText_SpAtk,
    gText_SpDef,
    gText_Speed
};

void DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr)
{
    u16 i, x;
    s16 statsDiff[NUM_STATS];
    u8 text[12];
    u8 color[3];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(bgClr));

    statsDiff[0] = statsAfter[STAT_HP]    - statsBefore[STAT_HP];
    statsDiff[1] = statsAfter[STAT_ATK]   - statsBefore[STAT_ATK];
    statsDiff[2] = statsAfter[STAT_DEF]   - statsBefore[STAT_DEF];
    statsDiff[3] = statsAfter[STAT_SPATK] - statsBefore[STAT_SPATK];
    statsDiff[4] = statsAfter[STAT_SPDEF] - statsBefore[STAT_SPDEF];
    statsDiff[5] = statsAfter[STAT_SPEED] - statsBefore[STAT_SPEED];

    color[0] = bgClr;
    color[1] = fgClr;
    color[2] = shadowClr;

    for (i = 0; i < NUM_STATS; i++)
    {

        AddTextPrinterParameterized3(windowId,
                                     FONT_NORMAL,
                                     0,
                                     15 * i,
                                     color,
                                     TEXT_SKIP_DRAW,
                                     sLvlUpStatStrings[i]);

        StringCopy(text, (statsDiff[i] >= 0) ? gText_Plus : gText_Dash);
        AddTextPrinterParameterized3(windowId,
                                     FONT_NORMAL,
                                     56,
                                     15 * i,
                                     color,
                                     TEXT_SKIP_DRAW,
                                     text);
        if (abs(statsDiff[i]) <= 9)
            x = 18;
        else
            x = 12;

        ConvertIntToDecimalStringN(text, abs(statsDiff[i]), STR_CONV_MODE_LEFT_ALIGN, 2);
        AddTextPrinterParameterized3(windowId,
                                     FONT_NORMAL,
                                     56 + x,
                                     15 * i,
                                     color,
                                     TEXT_SKIP_DRAW,
                                     text);
    }
}

void DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr)
{
    u16 i, numDigits, x;
    s16 stats[NUM_STATS];
    u8 text[12];
    u8 color[3];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(bgClr));

    stats[0] = currStats[STAT_HP];
    stats[1] = currStats[STAT_ATK];
    stats[2] = currStats[STAT_DEF];
    stats[3] = currStats[STAT_SPATK];
    stats[4] = currStats[STAT_SPDEF];
    stats[5] = currStats[STAT_SPEED];

    color[0] = bgClr;
    color[1] = fgClr;
    color[2] = shadowClr;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (stats[i] > 99)
            numDigits = 3;
        else if (stats[i] > 9)
            numDigits = 2;
        else
            numDigits = 1;

        ConvertIntToDecimalStringN(text, stats[i], STR_CONV_MODE_LEFT_ALIGN, numDigits);
        x = 6 * (4 - numDigits);

        AddTextPrinterParameterized3(windowId,
                                     FONT_NORMAL,
                                     0,
                                     15 * i,
                                     color,
                                     TEXT_SKIP_DRAW,
                                     sLvlUpStatStrings[i]);

        AddTextPrinterParameterized3(windowId,
                                     FONT_NORMAL,
                                     56 + x,
                                     15 * i,
                                     color,
                                     TEXT_SKIP_DRAW,
                                     text);
    }
}

void GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats)
{
    currStats[STAT_HP]    = GetMonData(mon, MON_DATA_MAX_HP);
    currStats[STAT_ATK]   = GetMonData(mon, MON_DATA_ATK);
    currStats[STAT_DEF]   = GetMonData(mon, MON_DATA_DEF);
    currStats[STAT_SPEED] = GetMonData(mon, MON_DATA_SPEED);
    currStats[STAT_SPATK] = GetMonData(mon, MON_DATA_SPATK);
    currStats[STAT_SPDEF] = GetMonData(mon, MON_DATA_SPDEF);
}
