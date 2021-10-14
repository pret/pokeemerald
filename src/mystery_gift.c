#include "global.h"
#include "main.h"
#include "text.h"
#include "task.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "text_window.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "text_window.h"
#include "menu.h"
#include "palette.h"
#include "constants/songs.h"
#include "sound.h"
#include "mystery_gift.h"
#include "union_room.h"
#include "title_screen.h"
#include "ereader_screen.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "string_util.h"
#include "mevent.h"
#include "wonder_transfer.h"
#include "save.h"
#include "link.h"
#include "mevent_client.h"
#include "event_data.h"
#include "link_rfu.h"
#include "mevent_news.h"
#include "mevent_server.h"
#include "constants/cable_club.h"

void bgid_upload_textbox_1(u8 bgId);
static void CreateMysteryGiftTask(void);
static void Task_MysteryGift(u8 taskId);

EWRAM_DATA u8 sDownArrowCounterAndYCoordIdx[8] = {};
EWRAM_DATA bool8 gGiftIsFromEReader = FALSE;

static const u16 gUnkTextboxBorderPal[] = INCBIN_U16("graphics/interface/unk_textbox_border.gbapal");
static const u32 gUnkTextboxBorderGfx[] = INCBIN_U32("graphics/interface/unk_textbox_border.4bpp.lz");

struct MysteryGiftTaskData
{
    u16 curPromptWindowId;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 state;
    u8 textState;
    u8 unkA;
    u8 unkB;
    bool8 isWonderNews;
    bool8 sourceIsFriend;
    u8 prevPromptWindowId;
    u8 * buffer;
};

static const struct BgTemplate sBGTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sMainWindows[] = {
    {
        .bg = 0x00,
        .tilemapLeft = 0x00,
        .tilemapTop = 0x00,
        .width = 0x1e,
        .height = 0x02,
        .paletteNum = 0x0c,
        .baseBlock = 0x0013
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x0f,
        .width = 0x1c,
        .height = 0x04,
        .paletteNum = 0x0c,
        .baseBlock = 0x004f
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x00,
        .tilemapTop = 0x0f,
        .width = 0x1e,
        .height = 0x05,
        .paletteNum = 0x0d,
        .baseBlock = 0x004f
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplate_PromptYesOrNo_Width28 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x0f,
    .width = 0x1c,
    .height = 0x04,
    .paletteNum = 0x0c,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_PromptYesOrNo_Width20 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x0f,
    .width = 0x14,
    .height = 0x04,
    .paletteNum = 0x0c,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sMysteryGiftMenuWindowTemplate = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x0f,
    .width = 0x13,
    .height = 0x04,
    .paletteNum = 0x0c,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_ThreeOptions = {
    .bg = 0x00,
    .tilemapLeft = 0x08,
    .tilemapTop = 0x06,
    .width = 0x0e,
    .height = 0x06,
    .paletteNum = 0x0c,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_YesNoBox = {
    .bg = 0x00,
    .tilemapLeft = 0x17,
    .tilemapTop = 0x0f,
    .width = 0x06,
    .height = 0x04,
    .paletteNum = 0x0c,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_7by8 = {
    .bg = 0x00,
    .tilemapLeft = 0x16,
    .tilemapTop = 0x0b,
    .width = 0x07,
    .height = 0x08,
    .paletteNum = 0x0c,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_7by6 = {
    .bg = 0x00,
    .tilemapLeft = 0x16,
    .tilemapTop = 0x0d,
    .width = 0x07,
    .height = 0x06,
    .paletteNum = 0x0c,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_7by4 = {
    .bg = 0x00,
    .tilemapLeft = 0x16,
    .tilemapTop = 0x0f,
    .width = 0x07,
    .height = 0x04,
    .paletteNum = 0x0c,
    .baseBlock = 0x0155
};

static const struct ListMenuItem sListMenuItems_CardsOrNews[] = {
    { gText_WonderCards,  0 },
    { gText_WonderNews,   1 },
    { gText_Exit3,       -2 }
};

static const struct ListMenuItem sListMenuItems_WirelessOrFriend[] = {
    { gText_WirelessCommunication,  0 },
    { gText_Friend2,                1 },
    { gText_Cancel2,               -2 }
};

static const struct ListMenuTemplate sListMenuTemplate_ThreeOptions = {
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuItem sListMenuItems_ReceiveSendToss[] = {
    { gText_Receive,  0 },
    { gText_Send,     1 },
    { gText_Toss,     2 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuItem sListMenuItems_ReceiveToss[] = {
    { gText_Receive,  0 },
    { gText_Toss,     2 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuItem sListMenuItems_ReceiveSend[] = {
    { gText_Receive,  0 },
    { gText_Send,     1 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuItem sListMenuItems_Receive[] = {
    { gText_Receive,  0 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuTemplate sListMenu_ReceiveSendToss = {
    .items = sListMenuItems_ReceiveSendToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 4,
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ReceiveToss = {
    .items = sListMenuItems_ReceiveToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ReceiveSend = {
    .items = sListMenuItems_ReceiveSend,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_Receive = {
    .items = sListMenuItems_Receive,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 2,
    .maxShowed = 2,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const u8 *const Unref_082F0710[] = {
    gText_VarietyOfEventsImportedWireless,
    gText_WonderCardsInPossession,
    gText_ReadNewsThatArrived,
    gText_ReturnToTitle
};

ALIGNED(2) const u8 sMG_Ereader_TextColor_1[]      = { 0, 1, 2 };
ALIGNED(2) const u8 sMG_Ereader_TextColor_1_Copy[] = { 0, 1, 2 };
ALIGNED(2) const u8 sMG_Ereader_TextColor_2[]      = { 1, 2, 3 };

static void VBlankCB_MysteryGiftEReader(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

void CB2_MysteryGiftEReader(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

static bool32 HandleMysteryGiftOrEReaderSetup(s32 isEReader)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        ScanlineEffect_Stop();
        ResetBgsAndClearDma3BusyFlags(0);

        InitBgsFromTemplates(0, sBGTemplates, ARRAY_COUNT(sBGTemplates));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);

        SetBgTilemapBuffer(3, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));

        bgid_upload_textbox_1(3);
        InitWindows(sMainWindows);
        DeactivateAllTextPrinters();
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gMain.state++;
        break;
    case 1:
        LoadPalette(gUnkTextboxBorderPal, 0, 0x20);
        LoadPalette(GetTextWindowPalette(2), 0xd0, 0x20);
        Menu_LoadStdPalAt(0xC0);
        LoadUserWindowBorderGfx(0, 0xA, 0xE0);
        LoadUserWindowBorderGfx_(0, 0x1, 0xF0);
        FillBgTilemapBufferRect(0, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(1, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(2, 0x000, 0, 0, 32, 32, 0x11);
        MG_DrawCheckerboardPattern(3);
        PrintMysteryGiftOrEReaderTopMenu(isEReader, FALSE);
        gMain.state++;
        break;
    case 2:
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    case 3:
        ShowBg(0);
        ShowBg(3);
        PlayBGM(MUS_RG_MYSTERY_GIFT);
        SetVBlankCallback(VBlankCB_MysteryGiftEReader);
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        return TRUE;
    }

    return FALSE;
}

void CB2_InitMysteryGift(void)
{
    if (HandleMysteryGiftOrEReaderSetup(FALSE))
    {
        SetMainCallback2(CB2_MysteryGiftEReader);
        gGiftIsFromEReader = FALSE;
        CreateMysteryGiftTask();
    }
    RunTasks();
}

void CB2_InitEReader(void)
{
    if (HandleMysteryGiftOrEReaderSetup(TRUE))
    {
        SetMainCallback2(CB2_MysteryGiftEReader);
        gGiftIsFromEReader = TRUE;
        CreateEReaderTask();
    }
}

void MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void)
{
    gGiftIsFromEReader = FALSE;
    FreeAllWindowBuffers();
    Free(GetBgTilemapBuffer(0));
    Free(GetBgTilemapBuffer(1));
    Free(GetBgTilemapBuffer(2));
    Free(GetBgTilemapBuffer(3));
    SetMainCallback2(CB2_InitTitleScreen);
}

void PrintMysteryGiftOrEReaderTopMenu(bool8 isEReader, bool32 usePickOkCancel)
{
    const u8 * header;
    const u8 * options;
    FillWindowPixelBuffer(0, 0);
    if (!isEReader)
    {
        header = gText_MysteryGift;
        options = !usePickOkCancel ? gText_PickOKExit : gText_PickOKCancel;
    }
    else
    {
        header = gJPText_MysteryGift;
        options = gJPText_DecideStop;
    }

    AddTextPrinterParameterized4(0, 1, 4, 1, 0, 0, sMG_Ereader_TextColor_1, -1, header);
    AddTextPrinterParameterized4(0, 0, GetStringRightAlignXOffset(0, options, 0xDE), 1, 0, 0, sMG_Ereader_TextColor_1, -1, options);
    CopyWindowToVram(0, 2);
    PutWindowTilemap(0);
}

void MG_DrawTextBorder(u8 windowId)
{
    DrawTextBorderOuter(windowId, 0x01, 0xF);
}

void MG_DrawCheckerboardPattern(u32 bg)
{
    s32 i = 0, j;

    FillBgTilemapBufferRect(bg, 0x003, 0, 0, 32, 2, 0x11);

    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((i & 1) != (j & 1))
                FillBgTilemapBufferRect(bg, 1, j, i + 2, 1, 1, 0x11);
            else
                FillBgTilemapBufferRect(bg, 2, j, i + 2, 1, 1, 0x11);
        }
    }
}

void ClearScreenInBg0(bool32 ignoreTopTwoRows)
{
    switch (ignoreTopTwoRows)
    {
    case 0:
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x11);
        break;
    case 1:
        FillBgTilemapBufferRect(0, 0, 0, 2, 32, 30, 0x11);
        break;
    }
    CopyBgTilemapBufferToVram(0);
}

void AddTextPrinterToWindow1(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    FillWindowPixelBuffer(1, 0x11);
    AddTextPrinterParameterized4(1, 1, 0, 1, 0, 0, sMG_Ereader_TextColor_2, 0, gStringVar4);
    DrawTextBorderOuter(1, 0x001, 0xF);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}

static void ClearTextWindow(void)
{
    rbox_fill_rectangle(1);
    ClearWindowTilemap(1);
    CopyWindowToVram(1, 1);
}

bool32 MG_PrintTextOnWindow1AndWaitButton(u8 *textState, const u8 *str)
{
    switch (*textState)
    {
    case 0:
        AddTextPrinterToWindow1(str);
        (*textState)++;
        break;
    case 1:
        DrawDownArrow(1, 0xD0, 0x14, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        if (({JOY_NEW(A_BUTTON | B_BUTTON);}))
            (*textState)++;
        break;
    case 2:
        DrawDownArrow(1, 0xD0, 0x14, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        *textState = 0;
        ClearTextWindow();
        return TRUE;
    case 0xFF:
        *textState = 2;
        return FALSE;
    }
    return FALSE;
}

static void HideDownArrow(void)
{
    DrawDownArrow(1, 0xD0, 0x14, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

static void ShowDownArrow(void)
{
    DrawDownArrow(1, 0xD0, 0x14, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

bool32 unref_HideDownArrowAndWaitButton(u8 * textState)
{
    switch (*textState)
    {
    case 0:
        HideDownArrow();
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            (*textState)++;
        break;
    case 1:
        ShowDownArrow();
        *textState = 0;
        return TRUE;
    }
    return FALSE;
}

static bool32 PrintStringAndWait2Seconds(u8 * counter, const u8 * str)
{
    if (*counter == 0)
        AddTextPrinterToWindow1(str);

    if (++(*counter) > 120)
    {
        *counter = 0;
        ClearTextWindow();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static u32 MysteryGift_HandleThreeOptionMenu(u8 * unused0, u16 * unused1, u8 whichMenu)
{
    struct ListMenuTemplate listMenuTemplate = sListMenuTemplate_ThreeOptions;
    struct WindowTemplate windowTemplate = sWindowTemplate_ThreeOptions;
    s32 width;
    s32 response;

    if (whichMenu == 0)
        listMenuTemplate.items = sListMenuItems_CardsOrNews;
    else
        listMenuTemplate.items = sListMenuItems_WirelessOrFriend;

    width = Intl_GetListMenuWidth(&listMenuTemplate);
    if (width & 1)
        width++;

    windowTemplate.width = width;
    if (width < 30)
        windowTemplate.tilemapLeft = (30 - width) / 2;
    else
        windowTemplate.tilemapLeft = 0;

    response = DoMysteryGiftListMenu(&windowTemplate, &listMenuTemplate, 1, 0x00A, 0xE0);
    if (response != LIST_NOTHING_CHOSEN)
    {
        ClearWindowTilemap(2);
        CopyWindowToVram(2, 1);
    }
    return response;
}

s8 DoMysteryGiftYesNo(u8 * textState, u16 * windowId, bool8 yesNoBoxPlacement, const u8 * str)
{
    struct WindowTemplate windowTemplate;
    s8 input;

    switch (*textState)
    {
    case 0:
        StringExpandPlaceholders(gStringVar4, str);
        if (yesNoBoxPlacement == 0)
            *windowId = AddWindow(&sWindowTemplate_PromptYesOrNo_Width28);
        else
            *windowId = AddWindow(&sWindowTemplate_PromptYesOrNo_Width20);
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, 1, 0, 1, 0, 0, sMG_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, 2);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        windowTemplate = sWindowTemplate_YesNoBox;
        if (yesNoBoxPlacement == 0)
            windowTemplate.tilemapTop = 9;
        else
            windowTemplate.tilemapTop = 15;
        CreateYesNoMenu(&windowTemplate, 10, 14, 0);
        (*textState)++;
        break;
    case 2:
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input == MENU_B_PRESSED || input == 0 || input == 1)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, 1);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case (u8)MENU_B_PRESSED:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, 1);
        RemoveWindow(*windowId);
        return MENU_B_PRESSED;
    }

    return MENU_NOTHING_CHOSEN;
}

static s32 HandleMysteryGiftListMenu(u8 * textState, u16 * windowId, bool32 cannotToss, bool32 cannotSend)
{
    struct WindowTemplate windowTemplate;
    s32 input;

    switch (*textState)
    {
    case 0:
        if (!cannotToss)
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithCards);
        else
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithNews);
        *windowId = AddWindow(&sMysteryGiftMenuWindowTemplate);
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, 1, 0, 1, 0, 0, sMG_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, 2);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        windowTemplate = sWindowTemplate_YesNoBox;
        if (cannotSend)
        {
            if (!cannotToss)
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by6, &sListMenu_ReceiveToss, 1, 0x00A, 0xE0);
            else
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by4, &sListMenu_Receive, 1, 0x00A, 0xE0);
        }
        else
        {
            if (!cannotToss)
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by8, &sListMenu_ReceiveSendToss, 1, 0x00A, 0xE0);
            else
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by6, &sListMenu_ReceiveSend, 1, 0x00A, 0xE0);
        }
        if (input != LIST_NOTHING_CHOSEN)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, 1);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case 0xFF:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, 1);
        RemoveWindow(*windowId);
        return LIST_CANCEL;
    }

    return LIST_NOTHING_CHOSEN;
}

static bool32 ValidateCardOrNews(bool32 isWonderNews)
{
    if (!isWonderNews)
        return ValidateSavedWonderCard();
    else
        return ValidateSavedWonderNews();
}

static bool32 HandleLoadWonderCardOrNews(u8 * state, bool32 isWonderNews)
{
    switch (*state)
    {
    case 0:
        if (!isWonderNews)
            WonderCard_Init(GetSavedWonderCard(), sav1_get_mevent_buffer_2());
        else
            WonderNews_Init(GetSavedWonderNews());
        (*state)++;
        break;
    case 1:
        if (!isWonderNews)
        {
            if (!WonderCard_Enter())
                return FALSE;
        }
        else
        {
            if (!WonderNews_Enter())
                return FALSE;
        }
        *state = 0;
        return TRUE;
    }

    return FALSE;
}

static bool32 ClearSavedNewsOrCard(bool32 isWonderNews)
{
    if (!isWonderNews)
        ClearSavedWonderCard();
    else
        ClearSavedWonderNews();
    return TRUE;
}

static bool32 ExitWonderCardOrNews(bool32 isWonderNews, bool32 arg1)
{
    if (!isWonderNews)
    {
        if (WonderCard_Exit(arg1))
        {
            WonderCard_Destroy();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        if (WonderNews_Exit(arg1))
        {
            WonderNews_Destroy();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

static s32 AskDiscardGift(u8 * textState, u16 * windowId, bool32 isWonderNews)
{
    if (!isWonderNews)
        return DoMysteryGiftYesNo(textState, windowId, TRUE, gText_IfThrowAwayCardEventWontHappen);
    else
        return DoMysteryGiftYesNo(textState, windowId, TRUE, gText_OkayToDiscardNews);
}

static bool32 PrintThrownAway(u8 * textState, bool32 isWonderNews)
{
    if (!isWonderNews)
        return MG_PrintTextOnWindow1AndWaitButton(textState, gText_WonderCardThrownAway);
    else
        return MG_PrintTextOnWindow1AndWaitButton(textState, gText_WonderNewsThrownAway);
}

static bool32 mevent_save_game(u8 * state)
{
    switch (*state)
    {
    case 0:
        AddTextPrinterToWindow1(gText_DataWillBeSaved);
        (*state)++;
        break;
    case 1:
        TrySavingData(SAVE_NORMAL);
        (*state)++;
        break;
    case 2:
        AddTextPrinterToWindow1(gText_SaveCompletedPressA);
        (*state)++;
        break;
    case 3:
        if (({JOY_NEW(A_BUTTON | B_BUTTON);}))
        {
            (*state)++;
        }
        break;
    case 4:
        *state = 0;
        ClearTextWindow();
        return TRUE;
    }

    return FALSE;
}

static const u8 * GetStdMessage(bool32 * receivedMsg, bool8 isWonderNews, bool8 sourceIsFriend, u32 msgId)
{
    const u8 * msg = NULL;
    *receivedMsg = FALSE;

    switch (msgId)
    {
    case 0:
        *receivedMsg = FALSE;
        msg = gText_NothingSentOver;
        break;
    case 1:
        *receivedMsg = FALSE;
        msg = gText_RecordUploadedViaWireless;
        break;
    case 2:
        *receivedMsg = TRUE;
        msg = !sourceIsFriend ? gText_WonderCardReceived : gText_WonderCardReceivedFrom;
        break;
    case 3:
        *receivedMsg = TRUE;
        msg = !sourceIsFriend ? gText_WonderNewsReceived : gText_WonderNewsReceivedFrom;
        break;
    case 4:
        *receivedMsg = TRUE;
        msg = gText_NewStampReceived;
        break;
    case 5:
        *receivedMsg = FALSE;
        msg = gText_AlreadyHadCard;
        break;
    case 6:
        *receivedMsg = FALSE;
        msg = gText_AlreadyHadStamp;
        break;
    case 7:
        *receivedMsg = FALSE;
        msg = gText_AlreadyHadNews;
        break;
    case 8:
        *receivedMsg = FALSE;
        msg = gText_NoMoreRoomForStamps;
        break;
    case 9:
        *receivedMsg = FALSE;
        msg = gText_CommunicationCanceled;
        break;
    case 10:
        *receivedMsg = FALSE;
        msg = !isWonderNews ? gText_CantAcceptCardFromTrainer : gText_CantAcceptNewsFromTrainer;
        break;
    case 11:
        *receivedMsg = FALSE;
        msg = gText_CommunicationError;
        break;
    case 12:
        *receivedMsg = TRUE;
        msg = gText_NewTrainerReceived;
        break;
    case 13:
        *receivedMsg = TRUE;
        break;
    case 14:
        *receivedMsg = FALSE;
        break;
    }

    return msg;
}

static bool32 PrintSuccessMessage(u8 * state, const u8 * msg, u16 * timer)
{
    switch (*state)
    {
    case 0:
        if (msg != NULL)
            AddTextPrinterToWindow1(msg);
        PlayFanfare(MUS_OBTAIN_ITEM);
        *timer = 0;
        (*state)++;
        break;
    case 1:
        if (++(*timer) > 240)
            (*state)++;
        break;
    case 2:
        if (IsFanfareTaskInactive())
        {
            *state = 0;
            ClearTextWindow();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static const u8 * mevent_message_stamp_card_etc_send_status(u32 * a0, u8 unused, u32 msgId)
{
    const u8 * result = gText_CommunicationError;
    *a0 = 0;
    switch (msgId)
    {
    case 0:
        result = gText_NothingSentOver;
        break;
    case 1:
        result = gText_RecordUploadedViaWireless;
        break;
    case 2:
        result = gText_WonderCardSentTo;
        *a0 = 1;
        break;
    case 3:
        result = gText_WonderNewsSentTo;
        *a0 = 1;
        break;
    case 4:
        result = gText_StampSentTo;
        break;
    case 5:
        result = gText_OtherTrainerHasCard;
        break;
    case 6:
        result = gText_OtherTrainerHasStamp;
        break;
    case 7:
        result = gText_OtherTrainerHasNews;
        break;
    case 8:
        result = gText_NoMoreRoomForStamps;
        break;
    case 9:
        result = gText_OtherTrainerCanceled;
        break;
    case 10:
        result = gText_CantSendGiftToTrainer;
        break;
    case 11:
        result = gText_CommunicationError;
        break;
    case 12:
        result = gText_GiftSentTo;
        break;
    case 13:
        result = gText_GiftSentTo;
        break;
    case 14:
        result = gText_CantSendGiftToTrainer;
        break;
    }
    return result;
}

static bool32 PrintMGSendStatus(u8 * state, u16 * arg1, u8 arg2, u32 msgId)
{
    u32 flag;
    const u8 * str = mevent_message_stamp_card_etc_send_status(&flag, arg2, msgId);
    if (flag)
        return PrintSuccessMessage(state, str, arg1);
    else
        return MG_PrintTextOnWindow1AndWaitButton(state, str);
}

enum {
    MG_STATE_TO_MAIN_MENU,
    MG_STATE_MAIN_MENU,
    MG_STATE_DONT_HAVE_ANY,
    MG_STATE_LINK_PROMPT,
    MG_STATE_LINK_PROMPT_INPUT,
    MG_STATE_LINK_START,
    MG_STATE_LINK_WAIT,
    MG_STATE_COMMUNICATING,
    MG_STATE_COMMUNICATE,
    MG_STATE_9,
    MG_STATE_10,
    MG_STATE_LINK_ASK_TOSS,
    MG_STATE_LINK_ASK_TOSS_UNRECEIVED,
    MG_STATE_LINK_COMPLETE_WAIT,
    MG_STATE_LINK_COMPLETED,
    MG_STATE_LINK_RESULT_MSG,
    MG_STATE_LINK_ERROR_1,
    MG_STATE_SAVE_LOAD_GIFT,
    MG_STATE_LOAD_GIFT,
    MG_STATE_UNUSED,
    MG_STATE_HANDLE_GIFT_INPUT,
    MG_STATE_HANDLE_GIFT_SELECT,
    MG_STATE_ASK_TOSS,
    MG_STATE_ASK_TOSS_UNRECEIVED,
    MG_STATE_TOSS,
    MG_STATE_TOSS_SAVE,
    MG_STATE_TOSSED,
    MG_STATE_GIFT_INPUT_EXIT,
    MG_STATE_RECEIVE,
    MG_STATE_SEND,
    MG_STATE_SEND_WAIT,
    MG_STATE_SEND_START,
    MG_STATE_SENDING,
    MG_STATE_SEND_FINISH,
    MG_STATE_SEND_WAIT_END,
    MG_STATE_SEND_END,
    MG_STATE_LINK_ERROR_2,
    MG_STATE_EXIT,
};

static void CreateMysteryGiftTask(void)
{
    u8 taskId = CreateTask(Task_MysteryGift, 0);
    struct MysteryGiftTaskData * data = (void *)gTasks[taskId].data;
    data->state = MG_STATE_TO_MAIN_MENU;
    data->textState = 0;
    data->unkA = 0;
    data->unkB = 0;
    data->isWonderNews = 0;
    data->sourceIsFriend = 0;
    data->curPromptWindowId = 0;
    data->unk2 = 0;
    data->unk4 = 0;
    data->unk6 = 0;
    data->prevPromptWindowId = 0;
    data->buffer = AllocZeroed(0x40);
}

static void Task_MysteryGift(u8 taskId)
{
    struct MysteryGiftTaskData *data = (void *)gTasks[taskId].data;
    u32 receivedMsg, input;
    const u8 *msg;

    switch (data->state)
    {
    case MG_STATE_TO_MAIN_MENU:
        data->state = MG_STATE_MAIN_MENU;
        break;
    case MG_STATE_MAIN_MENU:
        // Main Mystery Gift menu, player can select Wonder Cards or News (or exit)
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->curPromptWindowId, FALSE))
        {
        case 0: // "Wonder Cards"
            data->isWonderNews = FALSE;
            if (ValidateSavedWonderCard() == TRUE)
                data->state = MG_STATE_LOAD_GIFT;
            else
                data->state = MG_STATE_DONT_HAVE_ANY;
            break;
        case 1: // "Wonder News"
            data->isWonderNews = TRUE;
            if (ValidateSavedWonderNews() == TRUE)
                data->state = MG_STATE_LOAD_GIFT;
            else
                data->state = MG_STATE_DONT_HAVE_ANY;
            break;
        case LIST_CANCEL:
            data->state = MG_STATE_EXIT;
            break;
        }
        break;
    case MG_STATE_DONT_HAVE_ANY:
    {
        // Player doesn't have any Wonder Card/News
        // Start prompt to ask where to read one from
        if (!data->isWonderNews)
        {
            if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_DontHaveCardNewOneInput))
            {
                data->state = MG_STATE_LINK_PROMPT;
                PrintMysteryGiftOrEReaderTopMenu(FALSE, TRUE);
            }
        }
        else
        {
            if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_DontHaveNewsNewOneInput))
            {
                data->state = MG_STATE_LINK_PROMPT;
                PrintMysteryGiftOrEReaderTopMenu(FALSE, TRUE);
            }
        }
        break;
    }
    case MG_STATE_LINK_PROMPT:
        if (!data->isWonderNews)
            AddTextPrinterToWindow1(gText_WhereShouldCardBeAccessed);
        else
            AddTextPrinterToWindow1(gText_WhereShouldNewsBeAccessed);
        data->state = MG_STATE_LINK_PROMPT_INPUT;
        break;
    case MG_STATE_LINK_PROMPT_INPUT:
        // Choose where to access the Wonder Card/News from
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->curPromptWindowId, TRUE))
        {
        case 0: // "Wireless Communication"
            ClearTextWindow();
            data->state = MG_STATE_LINK_START;
            data->sourceIsFriend = FALSE;
            break;
        case 1: // "Friend"
            ClearTextWindow();
            data->state = MG_STATE_LINK_START;
            data->sourceIsFriend = TRUE;
            break;
        case LIST_CANCEL:
            ClearTextWindow();
            if (ValidateCardOrNews(data->isWonderNews))
            {
                data->state = MG_STATE_LOAD_GIFT;
            }
            else
            {
                data->state = MG_STATE_TO_MAIN_MENU;
                PrintMysteryGiftOrEReaderTopMenu(FALSE, FALSE);
            }
            break;
        }
        break;
    case MG_STATE_LINK_START:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        switch (data->isWonderNews)
        {
        case FALSE:
            if (data->sourceIsFriend == TRUE)
                CreateTask_LinkMysteryGiftWithFriend(ACTIVITY_WONDER_CARD);
            else if (data->sourceIsFriend == FALSE)
                CreateTask_LinkMysteryGiftOverWireless(ACTIVITY_WONDER_CARD);
            break;
        case TRUE:
            if (data->sourceIsFriend == TRUE)
                CreateTask_LinkMysteryGiftWithFriend(ACTIVITY_WONDER_NEWS);
            else if (data->sourceIsFriend == FALSE)
                CreateTask_LinkMysteryGiftOverWireless(ACTIVITY_WONDER_NEWS);
            break;
        }
        data->state = MG_STATE_LINK_WAIT;
        break;
    case MG_STATE_LINK_WAIT:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ClearScreenInBg0(TRUE);
            data->state = MG_STATE_COMMUNICATING;
            MysteryGiftClient_Create(data->isWonderNews);
        }
        else if (gSpecialVar_Result == LINKUP_FAILED)
        {
            // Link failed, return to link start menu 
            ClearScreenInBg0(TRUE);
            data->state = MG_STATE_LINK_PROMPT;
        }
        break;
    case MG_STATE_COMMUNICATING:
        AddTextPrinterToWindow1(gText_Communicating);
        data->state = MG_STATE_COMMUNICATE;
        break;
    case MG_STATE_COMMUNICATE:
        switch (MysteryGiftClient_Run(&data->curPromptWindowId))
        {
        case CLI_RET_END:
            Rfu_SetCloseLinkCallback();
            data->prevPromptWindowId = data->curPromptWindowId;
            data->state = MG_STATE_LINK_COMPLETE_WAIT;
            break;
        case CLI_RET_5:
            memcpy(data->buffer, mevent_client_get_buffer(), 0x40);
            MysteryGiftClient_AdvanceState();
            break;
        case CLI_RET_3:
            data->state = MG_STATE_10;
            break;
        case CLI_RET_2:
            data->state = MG_STATE_9;
            break;
        case CLI_RET_ASK_TOSS:
            data->state = MG_STATE_LINK_ASK_TOSS;
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            break;
        }
        break;
    case MG_STATE_9:
        input = DoMysteryGiftYesNo(&data->textState, &data->curPromptWindowId, FALSE, mevent_client_get_buffer());
        switch (input)
        {
        case 0: // Yes
            MysteryGiftClient_SetParam(0);
            MysteryGiftClient_AdvanceState();
            data->state = MG_STATE_COMMUNICATING;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            MysteryGiftClient_SetParam(1);
            MysteryGiftClient_AdvanceState();
            data->state = MG_STATE_COMMUNICATING;
            break;
        }
        break;
    case MG_STATE_10:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, mevent_client_get_buffer()))
        {
            MysteryGiftClient_AdvanceState();
            data->state = MG_STATE_COMMUNICATING;
        }
        break;
    case MG_STATE_LINK_ASK_TOSS:
        input = DoMysteryGiftYesNo(&data->textState, &data->curPromptWindowId, FALSE, gText_ThrowAwayWonderCard);
        switch (input)
        {
        case 0: // Yes
            if (CheckReceivedGiftFromWonderCard() == TRUE)
            {
                data->state = MG_STATE_LINK_ASK_TOSS_UNRECEIVED;
            }
            else
            {
                MysteryGiftClient_SetParam(0);
                MysteryGiftClient_AdvanceState();
                data->state = MG_STATE_COMMUNICATING;
            }
            break;
        case 1: // No
        case MENU_B_PRESSED:
            MysteryGiftClient_SetParam(1);
            MysteryGiftClient_AdvanceState();
            data->state = MG_STATE_COMMUNICATING;
            break;
        }
        break;
    case MG_STATE_LINK_ASK_TOSS_UNRECEIVED:
        input = DoMysteryGiftYesNo(&data->textState, &data->curPromptWindowId, FALSE, gText_HaventReceivedCardsGift);
        switch (input)
        {
        case 0: // Yes
            MysteryGiftClient_SetParam(0);
            MysteryGiftClient_AdvanceState();
            data->state = MG_STATE_COMMUNICATING;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            MysteryGiftClient_SetParam(1);
            MysteryGiftClient_AdvanceState();
            data->state = MG_STATE_COMMUNICATING;
            break;
        }
        break;
    case MG_STATE_LINK_COMPLETE_WAIT:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = MG_STATE_LINK_COMPLETED;
        }
        break;
    case MG_STATE_LINK_COMPLETED:
        if (PrintStringAndWait2Seconds(&data->textState, gText_CommunicationCompleted))
        {
            if (data->sourceIsFriend == TRUE)
                StringCopy(gStringVar1, gLinkPlayers[0].name);
            data->state = MG_STATE_LINK_RESULT_MSG;
        }
        break;
    case MG_STATE_LINK_RESULT_MSG:
        msg = GetStdMessage(&receivedMsg, data->isWonderNews, data->sourceIsFriend, data->prevPromptWindowId);
        if (msg == NULL)
            msg = data->buffer;
        if (receivedMsg)
            input = PrintSuccessMessage(&data->textState, msg, &data->curPromptWindowId);
        else
            input = MG_PrintTextOnWindow1AndWaitButton(&data->textState, msg);
        // input var re-used, here it is TRUE if the message is finished
        if (input)
        {
            if (data->prevPromptWindowId == 3)
            {
                if (data->sourceIsFriend == TRUE)
                    GenerateRandomNews(1);
                else
                    GenerateRandomNews(2);
            }
            if (!receivedMsg)
            {
                // Did not receive card/news, return to main menu
                data->state = MG_STATE_TO_MAIN_MENU;
                PrintMysteryGiftOrEReaderTopMenu(FALSE, FALSE);
            }
            else
            {
                data->state = MG_STATE_SAVE_LOAD_GIFT;
            }
        }
        break;
    case MG_STATE_SAVE_LOAD_GIFT:
        if (mevent_save_game(&data->textState))
            data->state = MG_STATE_LOAD_GIFT;
        break;
    case MG_STATE_LOAD_GIFT:
        if (HandleLoadWonderCardOrNews(&data->textState, data->isWonderNews))
            data->state = MG_STATE_HANDLE_GIFT_INPUT;
        break;
    case MG_STATE_HANDLE_GIFT_INPUT:
        if (!data->isWonderNews)
        {
            // Handle Wonder Card input
            if (JOY_NEW(A_BUTTON))
                data->state = MG_STATE_HANDLE_GIFT_SELECT;
            if (JOY_NEW(B_BUTTON))
                data->state = MG_STATE_GIFT_INPUT_EXIT;
        }
        else
        {
            switch (WonderNews_GetInput(gMain.newKeys))
            {
            case NEWS_INPUT_A:
                WonderNews_RemoveScrollIndicatorArrowPair();
                data->state = MG_STATE_HANDLE_GIFT_SELECT;
                break;
            case NEWS_INPUT_B:
                data->state = MG_STATE_GIFT_INPUT_EXIT;
                break;
            }
        }
        break;
    case MG_STATE_HANDLE_GIFT_SELECT:
    {
        // A Wonder Card/News has been selected, handle its menu
        u32 result;
        if (!data->isWonderNews)
        {
            if (WonderCard_Test_Unk_08_6())
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->isWonderNews, FALSE);
            else
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->isWonderNews, TRUE);
        }
        else
        {
            if (WonderNews_Test_Unk_02())
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->isWonderNews, FALSE);
            else
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->isWonderNews, TRUE);
        }
        switch (result)
        {
        case 0: // Receive
            data->state = MG_STATE_RECEIVE;
            break;
        case 1: // Send
            data->state = MG_STATE_SEND;
            break;
        case 2: // Toss
            data->state = MG_STATE_ASK_TOSS;
            break;
        case LIST_CANCEL:
            if (data->isWonderNews == TRUE)
                WonderNews_AddScrollIndicatorArrowPair();
            data->state = MG_STATE_HANDLE_GIFT_INPUT;
            break;
        }
        break;
    }
    case MG_STATE_ASK_TOSS:
        // Player is attempting to discard a Wonder Card/News
        switch (AskDiscardGift(&data->textState, &data->curPromptWindowId, data->isWonderNews))
        {
        case 0: // Yes
            if (!data->isWonderNews && CheckReceivedGiftFromWonderCard() == TRUE)
                data->state = MG_STATE_ASK_TOSS_UNRECEIVED;
            else
                data->state = MG_STATE_TOSS;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            data->state = MG_STATE_HANDLE_GIFT_SELECT;
            break;
        }
        break;
    case MG_STATE_ASK_TOSS_UNRECEIVED:
        // Player has selected to toss a Wonder Card that they haven't received the gift for.
        // Ask for confirmation again.
        switch ((u32)DoMysteryGiftYesNo(&data->textState, &data->curPromptWindowId, TRUE, gText_HaventReceivedGiftOkayToDiscard))
        {
        case 0: // Yes
            data->state = MG_STATE_TOSS;
            break;
        case 1: // No
        case MENU_B_PRESSED:
            data->state = MG_STATE_HANDLE_GIFT_SELECT;
            break;
        }
        break;
    case MG_STATE_TOSS:
        if (ExitWonderCardOrNews(data->isWonderNews, 1))
        {
            ClearSavedNewsOrCard(data->isWonderNews);
            data->state = MG_STATE_TOSS_SAVE;
        }
        break;
    case MG_STATE_TOSS_SAVE:
        if (mevent_save_game(&data->textState))
            data->state = MG_STATE_TOSSED;
        break;
    case MG_STATE_TOSSED:
        if (PrintThrownAway(&data->textState, data->isWonderNews))
        {
            data->state = MG_STATE_TO_MAIN_MENU;
            PrintMysteryGiftOrEReaderTopMenu(FALSE, FALSE);
        }
        break;
    case MG_STATE_GIFT_INPUT_EXIT:
        if (ExitWonderCardOrNews(data->isWonderNews, 0))
            data->state = MG_STATE_TO_MAIN_MENU;
        break;
    case MG_STATE_RECEIVE:
        if (ExitWonderCardOrNews(data->isWonderNews, 1))
            data->state = MG_STATE_LINK_PROMPT;
        break;
    case MG_STATE_SEND:
        if (ExitWonderCardOrNews(data->isWonderNews, 1))
        {
            switch (data->isWonderNews)
            {
            case FALSE:
                CreateTask_SendMysteryGift(ACTIVITY_WONDER_CARD);
                break;
            case TRUE:
                CreateTask_SendMysteryGift(ACTIVITY_WONDER_NEWS);
                break;
            }
            data->sourceIsFriend = TRUE;
            data->state = MG_STATE_SEND_WAIT;
        }
        break;
    case MG_STATE_SEND_WAIT:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ClearScreenInBg0(1);
            data->state = MG_STATE_SEND_START;
        }
        else if (gSpecialVar_Result == LINKUP_FAILED)
        {
            ClearScreenInBg0(1);
            data->state = MG_STATE_LOAD_GIFT;
        }
        break;
    case MG_STATE_SEND_START:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        if (!data->isWonderNews)
        {
            AddTextPrinterToWindow1(gText_SendingWonderCard);
            mevent_srv_new_wcard();
        }
        else
        {
            AddTextPrinterToWindow1(gText_SendingWonderNews);
            mevent_srv_init_wnews();
        }
        data->state = MG_STATE_SENDING;
        break;
    case MG_STATE_SENDING:
        if (mevent_srv_common_do_exec(&data->curPromptWindowId) == 3)
        {
            data->prevPromptWindowId = data->curPromptWindowId;
            data->state = MG_STATE_SEND_FINISH;
        }
        break;
    case MG_STATE_SEND_FINISH:
        Rfu_SetCloseLinkCallback();
        StringCopy(gStringVar1, gLinkPlayers[1].name);
        data->state = MG_STATE_SEND_WAIT_END;
        break;
    case MG_STATE_SEND_WAIT_END:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = MG_STATE_SEND_END;
        }
        break;
    case MG_STATE_SEND_END:
        if (PrintMGSendStatus(&data->textState, &data->curPromptWindowId, data->sourceIsFriend, data->prevPromptWindowId))
        {
            if (data->sourceIsFriend == TRUE && data->prevPromptWindowId == 3)
            {
                GenerateRandomNews(3);
                data->state = MG_STATE_SAVE_LOAD_GIFT;
            }
            else
            {
                data->state = MG_STATE_TO_MAIN_MENU;
                PrintMysteryGiftOrEReaderTopMenu(FALSE, FALSE);
            }
        }
        break;
    case MG_STATE_LINK_ERROR_1:
    case MG_STATE_LINK_ERROR_2:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_CommunicationError))
        {
            data->state = MG_STATE_TO_MAIN_MENU;
            PrintMysteryGiftOrEReaderTopMenu(FALSE, FALSE);
        }
        break;
    case MG_STATE_EXIT:
        CloseLink();
        Free(data->buffer);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}

u16 GetMysteryGiftBaseBlock(void)
{
    return 0x1A9;
}

void bgid_upload_textbox_1(u8 bgId)
{
    DecompressAndLoadBgGfxUsingHeap(bgId, gUnkTextboxBorderGfx, 0x100, 0, 0);
}
