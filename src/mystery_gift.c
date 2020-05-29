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
#include "mevent_801BAAC.h"
#include "save.h"
#include "link.h"
#include "mevent_client.h"
#include "event_data.h"
#include "link_rfu.h"
#include "mevent_news.h"
#include "mevent_server.h"

void bgid_upload_textbox_1(u8 bgId);
void task_add_00_mystery_gift(void);
void task00_mystery_gift(u8 taskId);

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
    u8 IsCardOrNews;
    u8 source;
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
    }, {
        0xFF
    }
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

void vblankcb_mystery_gift_e_reader_run(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

void c2_mystery_gift_e_reader_run(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

bool32 HandleMysteryGiftOrEReaderSetup(s32 mg_or_ereader)
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

        SetBgTilemapBuffer(3, Alloc(0x800));
        SetBgTilemapBuffer(2, Alloc(0x800));
        SetBgTilemapBuffer(1, Alloc(0x800));
        SetBgTilemapBuffer(0, Alloc(0x800));

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
        LoadPalette(stdpal_get(2), 0xd0, 0x20);
        Menu_LoadStdPalAt(0xC0);
        LoadUserWindowBorderGfx(0, 0xA, 0xE0);
        LoadUserWindowBorderGfx_(0, 0x1, 0xF0);
        FillBgTilemapBufferRect(0, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(1, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(2, 0x000, 0, 0, 32, 32, 0x11);
        MG_DrawCheckerboardPattern(3);
        PrintMysteryGiftOrEReaderTopMenu(mg_or_ereader, 0);
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
        PlayBGM(MUS_RG_OKURIMONO);
        SetVBlankCallback(vblankcb_mystery_gift_e_reader_run);
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        return TRUE;
    }

    return FALSE;
}

void c2_mystery_gift(void)
{
    if (HandleMysteryGiftOrEReaderSetup(0))
    {
        SetMainCallback2(c2_mystery_gift_e_reader_run);
        gGiftIsFromEReader = FALSE;
        task_add_00_mystery_gift();
    }
    RunTasks();
}

void c2_ereader(void)
{
    if (HandleMysteryGiftOrEReaderSetup(1))
    {
        SetMainCallback2(c2_mystery_gift_e_reader_run);
        gGiftIsFromEReader = TRUE;
        task_add_00_ereader();
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

void PrintMysteryGiftOrEReaderTopMenu(bool8 mg_or_ereader, bool32 usePickOkCancel)
{
    const u8 * header;
    const u8 * options;
    FillWindowPixelBuffer(0, 0);
    if (mg_or_ereader == 0)
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
            {
                FillBgTilemapBufferRect(bg, 1, j, i + 2, 1, 1, 0x11);
            }
            else
            {
                FillBgTilemapBufferRect(bg, 2, j, i + 2, 1, 1, 0x11);
            }
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
        goto inc;
    case 1:
        DrawDownArrow(1, 0xD0, 0x14, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        if (({gMain.newKeys & (A_BUTTON | B_BUTTON);}))
        {
        inc:
            (*textState)++;
        }
        break;
    case 2:
        DrawDownArrow(1, 0xD0, 0x14, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        *textState = 0;
        ClearTextWindow();
        return TRUE;
    case 0xFF:
        *textState = 2;
        break;
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
        if (({gMain.newKeys & (A_BUTTON | B_BUTTON);}))
        {
            (*textState)++;
        }
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
    {
        AddTextPrinterToWindow1(str);
    }
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
    {
        listMenuTemplate.items = sListMenuItems_CardsOrNews;
    }
    else
    {
        listMenuTemplate.items = sListMenuItems_WirelessOrFriend;
    }
    width = Intl_GetListMenuWidth(&listMenuTemplate);
    if (width & 1)
    {
        width++;
    }
    windowTemplate.width = width;
    if (width < 30)
    {
        windowTemplate.tilemapLeft = (30 - width) / 2;
    }
    else
    {
        windowTemplate.tilemapLeft = 0;
    }
    response = DoMysteryGiftListMenu(&windowTemplate, &listMenuTemplate, 1, 0x00A, 0xE0);
    if (response != -1)
    {
        ClearWindowTilemap(2);
        CopyWindowToVram(2, 1);
    }
    return response;
}

s8 mevent_message_print_and_prompt_yes_no(u8 * textState, u16 * windowId, bool8 yesNoBoxPlacement, const u8 * str)
{
    struct WindowTemplate windowTemplate;
    s8 input;

    switch (*textState)
    {
    case 0:
        StringExpandPlaceholders(gStringVar4, str);
        if (yesNoBoxPlacement == 0)
        {
            *windowId = AddWindow(&sWindowTemplate_PromptYesOrNo_Width28);
        }
        else
        {
            *windowId = AddWindow(&sWindowTemplate_PromptYesOrNo_Width20);
        }
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
        {
            windowTemplate.tilemapTop = 9;
        }
        else
        {
            windowTemplate.tilemapTop = 15;
        }
        CreateYesNoMenu(&windowTemplate, 10, 14, 0);
        (*textState)++;
        break;
    case 2:
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input == -1 || input == 0 || input == 1)
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
        return -1;
    }

    return -2;
}

static s32 HandleMysteryGiftListMenu(u8 * textState, u16 * windowId, bool32 cannotToss, bool32 cannotSend)
{
    struct WindowTemplate windowTemplate;
    s32 input;

    switch (*textState)
    {
    case 0:
        if (cannotToss == 0)
        {
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithCards);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithNews);
        }
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
            if (cannotToss == 0)
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by6, &sListMenu_ReceiveToss, 1, 0x00A, 0xE0);
            }
            else
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by4, &sListMenu_Receive, 1, 0x00A, 0xE0);
            }
        }
        else
        {
            if (cannotToss == 0)
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by8, &sListMenu_ReceiveSendToss, 1, 0x00A, 0xE0);
            }
            else
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_7by6, &sListMenu_ReceiveSend, 1, 0x00A, 0xE0);
            }
        }
        if (input != -1)
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
        return -2;
    }

    return -1;
}

static bool32 ValidateCardOrNews(bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        return ValidateReceivedWonderCard();
    }
    else
    {
        return ValidateReceivedWonderNews();
    }
}

static bool32 HandleLoadWonderCardOrNews(u8 * state, bool32 cardOrNews)
{
    s32 v0;

    switch (*state)
    {
    case 0:
        if (cardOrNews == 0)
        {
            InitWonderCardResources(GetSavedWonderCard(), sav1_get_mevent_buffer_2());
        }
        else
        {
            InitWonderNewsResources(GetSavedWonderNews());
        }
        (*state)++;
        break;
    case 1:
        if (cardOrNews == 0)
        {
            v0 = FadeToWonderCardMenu();
        check:
            if (v0 != 0)
            {
                goto done;
            }
            break;
        }
        else
        {
            v0 = FadeToWonderNewsMenu();
            goto check;
        }
    done:
        *state = 0;
        return TRUE;
    }

    return FALSE;
}

static bool32 DestroyNewsOrCard(bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        DestroyWonderCard();
    }
    else
    {
        DestroyWonderNews();
    }
    return TRUE;
}

static bool32 TearDownCardOrNews_ReturnToTopMenu(bool32 cardOrNews, bool32 arg1)
{
    if (cardOrNews == 0)
    {
        if (FadeOutFromWonderCard(arg1) != 0)
        {
            DestroyWonderCardResources();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        if (FadeOutFromWonderNews(arg1) != 0)
        {
            DestroyWonderNewsResources();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

static s32 mevent_message_prompt_discard(u8 * textState, u16 * windowId, bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        return mevent_message_print_and_prompt_yes_no(textState, windowId, TRUE, gText_IfThrowAwayCardEventWontHappen);
    }
    else
    {
        return mevent_message_print_and_prompt_yes_no(textState, windowId, TRUE, gText_OkayToDiscardNews);
    }
}

static bool32 mevent_message_was_thrown_away(u8 * textState, bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        return MG_PrintTextOnWindow1AndWaitButton(textState, gText_WonderCardThrownAway);
    }
    else
    {
        return MG_PrintTextOnWindow1AndWaitButton(textState, gText_WonderNewsThrownAway);
    }
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
        if (({gMain.newKeys & (A_BUTTON | B_BUTTON);}))
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

static const u8 * mevent_message(u32 * a0, u8 a1, u8 cardOrNews, u32 msgId)
{
    const u8 * msg = NULL;
    *a0 = 0;

    switch (msgId)
    {
    case 0:
        *a0 = 0;
        msg = gText_NothingSentOver;
        break;
    case 1:
        *a0 = 0;
        msg = gText_RecordUploadedViaWireless;
        break;
    case 2:
        *a0 = 1;
        msg = cardOrNews == 0 ? gText_WonderCardReceived : gText_WonderCardReceivedFrom;
        break;
    case 3:
        *a0 = 1;
        msg = cardOrNews == 0 ? gText_WonderNewsReceived : gText_WonderNewsReceivedFrom;
        break;
    case 4:
        *a0 = 1;
        msg = gText_NewStampReceived;
        break;
    case 5:
        *a0 = 0;
        msg = gText_AlreadyHadCard;
        break;
    case 6:
        *a0 = 0;
        msg = gText_AlreadyHadStamp;
        break;
    case 7:
        *a0 = 0;
        msg = gText_AlreadyHadNews;
        break;
    case 8:
        *a0 = 0;
        msg = gText_NoMoreRoomForStamps;
        break;
    case 9:
        *a0 = 0;
        msg = gText_CommunicationCanceled;
        break;
    case 10:
        *a0 = 0;
        msg = a1 == 0 ? gText_CantAcceptCardFromTrainer : gText_CantAcceptNewsFromTrainer;
        break;
    case 11:
        *a0 = 0;
        msg = gText_CommunicationError;
        break;
    case 12:
        *a0 = 1;
        msg = gText_NewTrainerReceived;
        break;
    case 13:
        *a0 = 1;
        break;
    case 14:
        *a0 = 0;
        break;
    }

    return msg;
}

static bool32 PrintMGSuccessMessage(u8 * state, const u8 * arg1, u16 * arg2)
{
    switch (*state)
    {
    case 0:
        if (arg1 != NULL)
        {
            AddTextPrinterToWindow1(arg1);
        }
        PlayFanfare(MUS_FANFA4);
        *arg2 = 0;
        (*state)++;
        break;
    case 1:
        if (++(*arg2) > 0xF0)
        {
            (*state)++;
        }
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
    {
        return PrintMGSuccessMessage(state, str, arg1);
    }
    else
    {
        return MG_PrintTextOnWindow1AndWaitButton(state, str);
    }
}

void task_add_00_mystery_gift(void)
{
    u8 taskId = CreateTask(task00_mystery_gift, 0);
    struct MysteryGiftTaskData * data = (void *)gTasks[taskId].data;
    data->state = 0;
    data->textState = 0;
    data->unkA = 0;
    data->unkB = 0;
    data->IsCardOrNews = 0;
    data->source = 0;
    data->curPromptWindowId = 0;
    data->unk2 = 0;
    data->unk4 = 0;
    data->unk6 = 0;
    data->prevPromptWindowId = 0;
    data->buffer = AllocZeroed(0x40);
}

void task00_mystery_gift(u8 taskId)
{
    struct MysteryGiftTaskData *data = (void *)gTasks[taskId].data;
    u32 sp0, flag;
    const u8 *r1;

    switch (data->state)
    {
    case  0:
        data->state = 1;
        break;
    case  1:
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->curPromptWindowId, FALSE))
        {
        case 0:
            data->IsCardOrNews = 0;
            if (ValidateReceivedWonderCard() == TRUE)
            {
                data->state = 18;
            }
            else
            {
                data->state = 2;
            }
            break;
        case 1:
            data->IsCardOrNews = 1;
            if (ValidateReceivedWonderNews() == TRUE)
            {
                data->state = 18;
            }
            else
            {
                data->state = 2;
            }
            break;
        case -2u:
            data->state = 37;
            break;
        }
        break;
    case  2:
    {
        if (data->IsCardOrNews == 0)
        {
            if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_DontHaveCardNewOneInput))
            {
                data->state = 3;
                PrintMysteryGiftOrEReaderTopMenu(0, 1);
            }
        }
        else
        {
            if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_DontHaveNewsNewOneInput))
            {
                data->state = 3;
                PrintMysteryGiftOrEReaderTopMenu(0, 1);
            }
        }
        break;
    }
    case  3:
        if (data->IsCardOrNews == 0)
        {
            AddTextPrinterToWindow1(gText_WhereShouldCardBeAccessed);
        }
        else
        {
            AddTextPrinterToWindow1(gText_WhereShouldNewsBeAccessed);
        }
        data->state = 4;
        break;
    case  4:
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->curPromptWindowId, TRUE))
        {
        case 0:
            ClearTextWindow();
            data->state = 5;
            data->source = 0;
            break;
        case 1:
            ClearTextWindow();
            data->state = 5;
            data->source = 1;
            break;
        case -2u:
            ClearTextWindow();
            if (ValidateCardOrNews(data->IsCardOrNews))
            {
                data->state = 18;
            }
            else
            {
                data->state = 0;
                PrintMysteryGiftOrEReaderTopMenu(0, 0);
            }
            break;
        }
        break;
    case  5:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        switch (data->IsCardOrNews)
        {
        case 0:
            if (data->source == 1)
            {
                MEvent_CreateTask_CardOrNewsWithFriend(0x15);
            }
            else if (data->source == 0)
            {
                MEvent_CreateTask_CardOrNewsOverWireless(0x15);
            }
            break;
        case 1:
            if (data->source == 1)
            {
                MEvent_CreateTask_CardOrNewsWithFriend(0x16);
            }
            else if (data->source == 0)
            {
                MEvent_CreateTask_CardOrNewsOverWireless(0x16);
            }
            break;
        }
        data->state = 6;
        break;
    case  6:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ClearScreenInBg0(TRUE);
            data->state = 7;
            mevent_client_do_init(data->IsCardOrNews);
        }
        else if (gSpecialVar_Result == 5)
        {
            ClearScreenInBg0(TRUE);
            data->state = 3;
        }
        break;
    case  7:
        AddTextPrinterToWindow1(gText_Communicating);
        data->state = 8;
        break;
    case  8:
        switch (mevent_client_do_exec(&data->curPromptWindowId))
        {
        case 6:
            task_add_05_task_del_08FA224_when_no_RfuFunc();
            data->prevPromptWindowId = data->curPromptWindowId;
            data->state = 13;
            break;
        case 5:
            memcpy(data->buffer, mevent_client_get_buffer(), 0x40);
            mevent_client_inc_flag();
            break;
        case 3:
            data->state = 10;
            break;
        case 2:
            data->state = 9;
            break;
        case 4:
            data->state = 11;
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            break;
        }
        break;
    case  9:
        flag = mevent_message_print_and_prompt_yes_no(&data->textState, &data->curPromptWindowId, FALSE, mevent_client_get_buffer());
        switch (flag)
        {
        case 0:
            mevent_client_set_param(0);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case 1:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case -1u:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        }
        break;
    case 10:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, mevent_client_get_buffer()))
        {
            mevent_client_inc_flag();
            data->state = 7;
        }
        break;
    case 11:
        flag = mevent_message_print_and_prompt_yes_no(&data->textState, &data->curPromptWindowId, FALSE, gText_ThrowAwayWonderCard);
        switch (flag)
        {
        case 0:
            if (CheckReceivedGiftFromWonderCard() == TRUE)
            {
                data->state = 12;
            }
            else
            {
                mevent_client_set_param(0);
                mevent_client_inc_flag();
                data->state = 7;
            }
            break;
        case 1:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case -1u:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        }
        break;
    case 12:
        flag = mevent_message_print_and_prompt_yes_no(&data->textState, &data->curPromptWindowId, FALSE, gText_HaventReceivedCardsGift);
        switch (flag)
        {
        case 0:
            mevent_client_set_param(0);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case 1:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case -1u:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        }
        break;
    case 13:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = 14;
        }
        break;
    case 14:
        if (PrintStringAndWait2Seconds(&data->textState, gText_CommunicationCompleted))
        {
            if (data->source == 1)
            {
                StringCopy(gStringVar1, gLinkPlayers[0].name);
            }
            data->state = 15;
        }
        break;
    case 15:
        r1 = mevent_message(&sp0, data->IsCardOrNews, data->source, data->prevPromptWindowId);
        if (r1 == NULL)
        {
            r1 = data->buffer;
        }
        if (sp0)
        {
            flag = PrintMGSuccessMessage(&data->textState, r1, &data->curPromptWindowId);
        }
        else
        {
            flag = MG_PrintTextOnWindow1AndWaitButton(&data->textState, r1);
        }
        if (flag)
        {
            if (data->prevPromptWindowId == 3)
            {
                if (data->source == 1)
                {
                    GenerateRandomNews(1);
                }
                else
                {
                    GenerateRandomNews(2);
                }
            }
            if (!sp0)
            {
                data->state = 0;
                PrintMysteryGiftOrEReaderTopMenu(0, 0);
            }
            else
            {
                data->state = 17;
            }
        }
        break;
    case 16:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_CommunicationError))
        {
            data->state = 0;
            PrintMysteryGiftOrEReaderTopMenu(0, 0);
        }
        break;
    case 17:
        if (mevent_save_game(&data->textState))
        {
            data->state = 18;
        }
        break;
    case 18:
        if (HandleLoadWonderCardOrNews(&data->textState, data->IsCardOrNews))
        {
            data->state = 20;
        }
        break;
    case 20:
        if (data->IsCardOrNews == 0)
        {
            if (({gMain.newKeys & A_BUTTON;}))
            {
                data->state = 21;
            }
            if (({gMain.newKeys & B_BUTTON;}))
            {
                data->state = 27;
            }
        }
        else
        {
            switch (MENews_GetInput(gMain.newKeys))
            {
            case 0:
                MENews_RemoveScrollIndicatorArrowPair();
                data->state = 21;
                break;
            case 1:
                data->state = 27;
                break;
            }
        }
        break;
    case 21:
    {
        u32 result;
        if (data->IsCardOrNews == 0)
        {
            if (WonderCard_Test_Unk_08_6())
            {
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->IsCardOrNews, FALSE);
            }
            else
            {
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->IsCardOrNews, TRUE);
            }
        }
        else
        {
            if (WonderNews_Test_Unk_02())
            {
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->IsCardOrNews, FALSE);
            }
            else
            {
                result = HandleMysteryGiftListMenu(&data->textState, &data->curPromptWindowId, data->IsCardOrNews, TRUE);
            }
        }
        switch (result)
        {
        case 0:
            data->state = 28;
            break;
        case 1:
            data->state = 29;
            break;
        case 2:
            data->state = 22;
            break;
        case -2u:
            if (data->IsCardOrNews == 1)
            {
                MENews_AddScrollIndicatorArrowPair();
            }
            data->state = 20;
            break;
        }
        break;
    }
    case 22:
        switch (mevent_message_prompt_discard(&data->textState, &data->curPromptWindowId, data->IsCardOrNews))
        {
        case 0:
            if (data->IsCardOrNews == 0 && CheckReceivedGiftFromWonderCard() == TRUE)
            {
                data->state = 23;
            }
            else
            {
                data->state = 24;
            }
            break;
        case 1:
            data->state = 21;
            break;
        case -1:
            data->state = 21;
            break;
        }
        break;
    case 23:
        switch ((u32)mevent_message_print_and_prompt_yes_no(&data->textState, &data->curPromptWindowId, TRUE, gText_HaventReceivedGiftOkayToDiscard))
        {
        case 0:
            data->state = 24;
            break;
        case 1:
            data->state = 21;
            break;
        case -1u:
            data->state = 21;
            break;
        }
        break;
    case 24:
        if (TearDownCardOrNews_ReturnToTopMenu(data->IsCardOrNews, 1))
        {
            DestroyNewsOrCard(data->IsCardOrNews);
            data->state = 25;
        }
        break;
    case 25:
        if (mevent_save_game(&data->textState))
        {
            data->state = 26;
        }
        break;
    case 26:
        if (mevent_message_was_thrown_away(&data->textState, data->IsCardOrNews))
        {
            data->state = 0;
            PrintMysteryGiftOrEReaderTopMenu(0, 0);
        }
        break;
    case 27:
        if (TearDownCardOrNews_ReturnToTopMenu(data->IsCardOrNews, 0))
        {
            data->state = 0;
        }
        break;
    case 28:
        if (TearDownCardOrNews_ReturnToTopMenu(data->IsCardOrNews, 1))
        {
            data->state = 3;
        }
        break;
    case 29:
        if (TearDownCardOrNews_ReturnToTopMenu(data->IsCardOrNews, 1))
        {
            switch (data->IsCardOrNews)
            {
            case 0:
                MEvent_CreateTask_Leader(21);
                break;
            case 1:
                MEvent_CreateTask_Leader(22);
                break;
            }
            data->source = 1;
            data->state = 30;
        }
        break;
    case 30:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ClearScreenInBg0(1);
            data->state = 31;
        }
        else if (gSpecialVar_Result == 5)
        {
            ClearScreenInBg0(1);
            data->state = 18;
        }
        break;
    case 31:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        if (data->IsCardOrNews == 0)
        {
            AddTextPrinterToWindow1(gText_SendingWonderCard);
            mevent_srv_new_wcard();
        }
        else
        {
            AddTextPrinterToWindow1(gText_SendingWonderNews);
            mevent_srv_init_wnews();
        }
        data->state = 32;
        break;
    case 32:
        if (mevent_srv_common_do_exec(&data->curPromptWindowId) == 3)
        {
            data->prevPromptWindowId = data->curPromptWindowId;
            data->state = 33;
        }
        break;
    case 33:
        task_add_05_task_del_08FA224_when_no_RfuFunc();
        StringCopy(gStringVar1, gLinkPlayers[1].name);
        data->state = 34;
        break;
    case 34:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = 35;
        }
        break;
    case 35:
        if (PrintMGSendStatus(&data->textState, &data->curPromptWindowId, data->source, data->prevPromptWindowId))
        {
            if (data->source == 1 && data->prevPromptWindowId == 3)
            {
                GenerateRandomNews(3);
                data->state = 17;
            }
            else
            {
                data->state = 0;
                PrintMysteryGiftOrEReaderTopMenu(0, 0);
            }
        }
        break;
    case 36:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_CommunicationError))
        {
            data->state = 0;
            PrintMysteryGiftOrEReaderTopMenu(0, 0);
        }
        break;
    case 37:
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
