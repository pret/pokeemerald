#include "global.h"
#include "battle.h"
#include "task.h"
#include "text.h"
#include "main.h"
#include "bg.h"
#include "palette.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "menu.h"
#include "window.h"
#include "text_window.h"
#include "scanline_effect.h"
#include "m4a.h"
#include "dynamic_placeholder_text_util.h"
#include "overworld.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "sound.h"
#include "constants/songs.h"
#include "party_menu.h"
#include "battle_setup.h"
#include "link.h"
#include "union_room.h"
#include "union_room_battle.h"

struct UnkStruct_3000DAC
{
    /*0x00*/ u32 unk00[4];
    /*0x10*/ u32 unk10[4];
    /*0x20*/ u32 unk20[16];
    /*0x60*/ u8 taskId;
    /*0x61*/ u8 unk61;
    /*0x62*/ u8 filler_62[10];
};

struct UnkStruct_2022C6C
{
    s16 a0;
};

static struct UnkStruct_3000DAC * gUnknown_03000DAC;

EWRAM_DATA struct UnkStruct_2022C6C * gUnknown_02022C6C = NULL;

void sub_801A43C(void);
void sub_801A6C0(u8 taskId);
static void sub_801A8B0(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 mode);
bool32 sub_801AA30(u32 * a0, u32 * a1, u32 * a2, u8 taskId);

const u16 gWirelessInfoScreenPal[] = INCBIN_U16("graphics/interface/wireless_info_screen.gbapal");
const u32 gWirelessInfoScreenGfx[] = INCBIN_U32("graphics/interface/wireless_info_screen.4bpp.lz");
const u32 gWirelessInfoScreenTilemap[] = INCBIN_U32("graphics/interface/wireless_info_screen.bin.lz");

const struct BgTemplate gUnknown_082F0D34[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1F,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x08,
        .priority = 1
    }
};

const struct WindowTemplate gUnknown_082F0D3C[] = {
    {
        .bg = 0x00,
        .tilemapLeft = 0x03,
        .tilemapTop = 0x00,
        .width = 0x18,
        .height = 0x03,
        .paletteNum = 0x0f,
        .baseBlock = 0x0001
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x03,
        .tilemapTop = 0x04,
        .width = 0x15,
        .height = 0x0f,
        .paletteNum = 0x0f,
        .baseBlock = 0x0049
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x18,
        .tilemapTop = 0x04,
        .width = 0x03,
        .height = 0x0f,
        .paletteNum = 0x0f,
        .baseBlock = 0x0184
    },
    { 0xFF }
};

const u8 *const gUnknown_082F0D5C[] = {
    gText_WirelessCommStatus,
    gText_PeopleTrading,
    gText_PeopleBattling,
    gText_PeopleInUnionRoom,
    gText_PeopleCommunicating
};

const u8 gUnknown_082F0D70[][3] = {
    {0x01, 0x01, 0x02},
    {0x02, 0x01, 0x02},
    {0x03, 0x01, 0x04},
    {0x04, 0x00, 0x02},
    {0x06, 0x03, 0x02},
    {0x07, 0x03, 0x02},
    {0x09, 0x03, 0x00},
    {0x0a, 0x03, 0x00},
    {0x0b, 0x03, 0x00},
    {0x0c, 0xff, 0x00},
    {0x0d, 0x00, 0x00},
    {0x10, 0x03, 0x00},
    {0x0f, 0x03, 0x00},
    {0x40, 0x02, 0x01},
    {0x41, 0x02, 0x02},
    {0x44, 0x02, 0x02},
    {0x45, 0x02, 0x00},
    {0x48, 0x02, 0x02},
    {0x54, 0x02, 0x01},
    {0x53, 0x02, 0x02},
    {0x51, 0x02, 0x01},
    {0x52, 0x02, 0x01},
    {0x15, 0x03, 0x02},
    {0x16, 0x03, 0x02},
    {0x17, 0x03, 0x00},
    {0x18, 0x03, 0x00},
    {0x19, 0x03, 0x00},
    {0x1a, 0x03, 0x00},
    {0x1b, 0x03, 0x00},
    {0x1c, 0x01, 0x02},
    {0x0e, 0x01, 0x02}
};

const struct BgTemplate gUnknown_082F0DD0[] = {
    {
        .bg = 0,
        .charBaseIndex = 3,
        .mapBaseIndex = 31
    }
};

const struct WindowTemplate gUnknown_082F0DD4[] = {
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 0xE,
        .baseBlock = 0x014
    },
    { 0xFF }
};

const u8 gUnknown_082F0DE4[] = { 1, 2, 3 };

void sub_801A3F4(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        RunTasks();
        RunTextPrinters();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
    }
}

void sub_801A418(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_801A42C(void)
{
    SetMainCallback2(sub_801A43C);
}

void sub_801A43C(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
    gUnknown_03000DAC = AllocZeroed(sizeof(struct UnkStruct_3000DAC));
    SetVBlankCallback(NULL);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_082F0D34, ARRAY_COUNT(gUnknown_082F0D34));
    SetBgTilemapBuffer(1, Alloc(0x800));
    SetBgTilemapBuffer(0, Alloc(0x800));
    DecompressAndLoadBgGfxUsingHeap(1, gWirelessInfoScreenGfx, 0, 0, 0);
    CopyToBgTilemapBuffer(1, gWirelessInfoScreenTilemap, 0, 0);
    InitWindows(gUnknown_082F0D3C);
    DeactivateAllTextPrinters();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
    ScanlineEffect_Stop();
    m4aSoundVSyncOn();
    SetVBlankCallback(sub_801A418);
    gUnknown_03000DAC->taskId = CreateTask(sub_801A6C0, 0);
    gUnknown_03000DAC->unk61 = sub_8013C40();
    gUnknown_03000DAC->unk10[3] = 1;
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    LoadPalette(gWirelessInfoScreenPal, 0x00, 0x20);
    Menu_LoadStdPalAt(0xF0);
    DynamicPlaceholderTextUtil_Reset();
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x0F);
    CopyBgTilemapBufferToVram(1);
    SetMainCallback2(sub_801A3F4);
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_801A584(void)
{
    s32 i;
    FreeAllWindowBuffers();
    for (i = 0; i < 2; i++)
    {
        Free(GetBgTilemapBuffer(i));
    }
    Free(gUnknown_03000DAC);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void sub_801A5BC(s16 * a0, s16 * a1)
{
    if (++(*a0) > 5)
    {
        if (++(*a1) == 14)
        {
            *a1 = 0;
        }
        *a0 = 0;
    }
    LoadPalette(gWirelessInfoScreenPal + 16 * (*a1 + 2), 0, 0x10);
}

void sub_801A600(void)
{
    s32 i;
    FillWindowPixelBuffer(0, 0);
    FillWindowPixelBuffer(1, 0);
    FillWindowPixelBuffer(2, 0);
    sub_801A8B0(0, 1, gUnknown_082F0D5C[0], GetStringCenterAlignXOffset(1, gUnknown_082F0D5C[0], 0xC0), 6, 3);
    for (i = 0; i < 3; i++)
    {
        sub_801A8B0(1, 1, gUnknown_082F0D5C[i + 1], 0, 30 * i + 8, 1);
    }
    sub_801A8B0(1, 1, gUnknown_082F0D5C[i + 1], 0, 30 * i + 8, 2);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 2);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
}

void sub_801A6C0(u8 taskId)
{
    s32 i;
    switch (gTasks[taskId].data[0])
    {
    case 0:
        sub_801A600();
        gTasks[taskId].data[0]++;
        break;
    case 1:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
        ShowBg(1);
        CopyBgTilemapBufferToVram(0);
        ShowBg(0);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        if (sub_801AA30(gUnknown_03000DAC->unk00, gUnknown_03000DAC->unk10, gUnknown_03000DAC->unk20, gUnknown_03000DAC->unk61))
        {
            FillWindowPixelBuffer(2, 0);
            for (i = 0; i < 4; i++)
            {
                ConvertIntToDecimalStringN(gStringVar4, gUnknown_03000DAC->unk00[i], STR_CONV_MODE_RIGHT_ALIGN, 2);
                if (i != 3)
                {
                    sub_801A8B0(2, 1, gStringVar4, 12, 30 * i + 8, 1);
                }
                else
                {
                    sub_801A8B0(2, 1, gStringVar4, 12, 98, 2);
                }
            }
            PutWindowTilemap(2);
            CopyWindowToVram(2, 3);
        }
        if (({gMain.newKeys & A_BUTTON;}) || ({gMain.newKeys & B_BUTTON;}))
        {
            PlaySE(SE_SELECT);
            gTasks[gUnknown_03000DAC->unk61].data[15] = 0xFF;
            gTasks[taskId].data[0]++;
        }
        sub_801A5BC(&gTasks[taskId].data[7], &gTasks[taskId].data[8]);
        break;
    case 4:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        gTasks[taskId].data[0]++;
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(sub_801A584);
            DestroyTask(taskId);
        }
        break;
    }
}

static void sub_801A8B0(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 mode)
{
    u8 color[3];

    switch (mode)
    {
    case 0:
        color[0] = 0;
        color[1] = 2;
        color[2] = 3;
        break;
    case 1:
        color[0] = 0;
        color[1] = 1;
        color[2] = 3;
        break;
    case 2:
        color[0] = 0;
        color[1] = 4;
        color[2] = 5;
        break;
    case 3:
        color[0] = 0;
        color[1] = 7;
        color[2] = 6;
        break;
    case 4:
        color[0] = 0;
        color[1] = 1;
        color[2] = 2;
        break;
    }

    AddTextPrinterParameterized4(windowId, fontId, x, y, 0, 0, color, -1, str);
}

u32 sub_801A960(struct UnkStruct_x20 * a0, u32 * a1)
{
    s32 i, j, r2;
    u32 result = a0->unk.field_0.activity;

    for (i = 0; i < (unsigned)ARRAY_COUNT(gUnknown_082F0D70); i++)
    {
        if (result != gUnknown_082F0D70[i][0])
        {
            continue;
        }
        if (a0->field_1A_0 != 1)
        {
            continue;
        }
        if (gUnknown_082F0D70[i][2] == 0)
        {
            r2 = 0;
            for (j = 0; j < 4; j++)
            {
                if (a0->unk.field_0.child_sprite_gender[j] != 0)
                {
                    r2++;
                }
            }
            r2++;
            a1[gUnknown_082F0D70[i][1]] += r2;
        }
        else
        {
            a1[gUnknown_082F0D70[i][1]] += gUnknown_082F0D70[i][2];
        }
    }
    return result;
}

bool32 sub_801AA08(u32 * a0, u32 * a1)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        if (a0[i] != a1[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool32 sub_801AA30(u32 * a0, u32 * a1, u32 * a2, u8 taskId)
{
    bool32 r8 = FALSE;
    u32 sp0[4] = {0, 0, 0, 0};
    struct UnkStruct_x20 ** data = (void *)gTasks[taskId].data;
    s32 i;

    for (i = 0; i < 16; i++)
    {
        u32 r1 = sub_801A960(&(*data)[i], sp0);
        if (r1 != a2[i])
        {
            a2[i] = r1;
            r8 = TRUE;
        }
    }
    if (sub_801AA08(sp0, a1) == 0)
    {
        if (r8 != TRUE)
        {
            return FALSE;
        }
    }
    else
    {
        memcpy(a0, sp0, sizeof(sp0));
        memcpy(a1, sp0, sizeof(sp0));
        a0[3] = a0[0] + a0[1] + a0[2] + a0[3];
    }
    return TRUE;
}

void sub_801AAD4(void)
{
    s32 i;
    sub_8014210(10);
    for (i = 0; i < UNION_ROOM_PARTY_SIZE; i++)
    {
        gEnemyParty[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1];
    }
    for (i = 0; i < PARTY_SIZE; i++)
    {
        ZeroMonData(&gPlayerParty[i]);
    }
    for (i = 0; i < UNION_ROOM_PARTY_SIZE; i++)
    {
        gPlayerParty[i] = gEnemyParty[i];
    }
    IncrementGameStat(GAME_STAT_NUM_UNION_ROOM_BATTLES);
    CalculatePlayerPartyCount();
    gTrainerBattleOpponent_A = 0xC00;
    SetMainCallback2(CB2_InitBattle);
}

void sub_801AB68(u8 windowId, const u8 * str, u8 x, u8 y, s32 speed)
{
    s32 letterSpacing = 0;
    s32 lineSpacing = 1;
    FillWindowPixelBuffer(windowId, (gUnknown_082F0DE4[0] << 4) | gUnknown_082F0DE4[0]);
    AddTextPrinterParameterized4(windowId, 1, x, y, letterSpacing, lineSpacing, gUnknown_082F0DE4, speed, str);
}

bool32 sub_801ABDC(s16 * state, const u8 * str, s32 speed)
{
    switch (*state)
    {
    case 0:
        DrawTextBorderOuter(0, 0x001, 0xD);
        sub_801AB68(0, str, 0, 1, speed);
        PutWindowTilemap(0);
        CopyWindowToVram(0, 3);
        (*state)++;
        break;
    case 1:
        if (!IsTextPrinterActive(0))
        {
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void sub_801AC40(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_801AC54(void)
{
    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
        gUnknown_02022C6C = AllocZeroed(4);
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_082F0DD0, 1);
        reset_temp_tile_data_buffers();
        if (!InitWindows(gUnknown_082F0DD4))
        {
            return;
        }
        DeactivateAllTextPrinters();
        ClearWindowTilemap(0);
        FillWindowPixelBuffer(0, 0x00);
        FillWindowPixelBuffer(0, 0x11);
        FillBgTilemapBufferRect(0, 0, 0, 0, 30, 20, 0xF);
        LoadUserWindowBorderGfx(0, 1, 0xD0);
        LoadUserWindowBorderGfx_(0, 1, 0xD0);
        sub_819789C();
        SetVBlankCallback(sub_801AC40);
        gMain.state++;
        break;
    case 1:
        if (sub_801ABDC(&gUnknown_02022C6C->a0, gText_CommStandbyAwaitingOtherPlayer, 0))
        {
            gMain.state++;
        }
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
        ShowBg(0);
        gMain.state++;
        break;
    case 3:
        if (!UpdatePaletteFade())
        {
            memset(gBlockSendBuffer, 0, 0x20);
            if (gSelectedOrderFromParty[0] == -gSelectedOrderFromParty[1])
            {
                gBlockSendBuffer[0] = 0x52;
            }
            else
            {
                gBlockSendBuffer[0] = 0x51;
            }
            SendBlock(0, gBlockSendBuffer, 0x20);
            gMain.state++;
        }
        break;
    case 4:
        if (GetBlockReceivedStatus() == 3)
        {
            if (gBlockRecvBuffer[0][0] == 0x51 && gBlockRecvBuffer[1][0] == 0x51)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
                gMain.state = 50;
            }
            else
            {
                sub_800AC34();
                if (gBlockRecvBuffer[GetMultiplayerId()][0] == 0x52)
                {
                    gMain.state = 6;
                }
                else
                {
                    gMain.state = 8;
                }
            }
            ResetBlockReceivedFlags();
        }
        break;
    case 50:
        if (!UpdatePaletteFade())
        {
            sub_800ADF8();
            gMain.state++;
        }
        break;
    case 51:
        if (IsLinkTaskFinished())
        {
            SetMainCallback2(sub_801AAD4);
        }
        break;
    case 6:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            gMain.state++;
        }
        break;
    case 7:
        if (sub_801ABDC(&gUnknown_02022C6C->a0, gText_RefusedBattle, 1))
        {
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    case 8:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            gMain.state++;
        }
        break;
    case 9:
        if (sub_801ABDC(&gUnknown_02022C6C->a0, gText_BattleWasRefused, 1))
        {
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
