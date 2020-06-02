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

struct UnionRoomBattleWork
{
    s16 textState;
};

EWRAM_DATA struct UnionRoomBattleWork * sWork = NULL;

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

void sub_801AAD4(void)
{
    s32 i;
    StartUnionRoomBattle(10);
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

void CB2_UnionRoomBattle(void)
{
    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
        sWork = AllocZeroed(4);
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
        if (sub_801ABDC(&sWork->textState, gText_CommStandbyAwaitingOtherPlayer, 0))
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
        if (sub_801ABDC(&sWork->textState, gText_RefusedBattle, 1))
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
        if (sub_801ABDC(&sWork->textState, gText_BattleWasRefused, 1))
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
