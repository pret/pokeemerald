#include "global.h"
#include "test/test.h"
#include "item.h"
#include "text.h"
#include "constants/moves.h"

TEST("Move names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Battle Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 64;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Contest Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 61;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    // All moves explicitly listed here are too big to fit.
    switch (move)
    {
    case MOVE_NATURES_MADNESS:
        EXPECT_GT(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
        break;
    }
}

TEST("Move names fit on TMs & HMs Bag Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 63;
    u32 move = MOVE_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].pocket == POCKET_TM_HM)
        {
            PARAMETRIZE_LABEL("%S", gMovesInfo[gItemsInfo[i].secondaryId].name) { move = gItemsInfo[i].secondaryId; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Move Relearner Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}
