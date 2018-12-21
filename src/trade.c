#include "global.h"
#include "alloc.h"
#include "battle_anim.h"
#include "bg.h"
#include "cable_club.h"
#include "data2.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "trade.h"
#include "window.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/rgb.h"

extern u8 gUnknown_02022C2C;
extern struct {
    u8 unk_0;
    u8 unk_1;
    u8 filler_2[0x28 - 2];
    u8 unk_28[PARTY_SIZE];
    u8 unk_2E[PARTY_SIZE];
    u8 unk_34;
    u8 unk_35;
    u8 unk_36[2];
    u8 unk_38[12];
    u8 unk_44;
    u8 unk_45[12];
    u8 filler_51[0x57 - 0x51];
    u8 unk_57[PARTY_SIZE];
    u8 filler_5D[0x69 - 0x5D];
    u8 unk_69;
    u8 filler_6A[0x6F - 0x6A];
    u8 unk_6F;
    u8 unk_70;
    u8 filler_71;
    u16 unk_72;
    u8 unk_74[2];
    u8 unk_76[2];
    u8 unk_78;
    u8 unk_79;
    u8 unk_7A;
    u8 unk_7B;
    u8 filler_7C[0x7E - 0x7C];
    u8 unk_7E;
    u8 filler_7F;
    u16 unk_80[2];
    u8 filler_84[0xA8 - 0x84];
    u8 unk_A8;
    u8 unk_A9[11];
    u8 filler_B4[0x8F0-0xB4];
    u8 tilemapBuffer[0x800];
} *gUnknown_0203229C;
extern u8 *gUnknown_02032184;
extern u8 *gUnknown_02032188[14];
extern u8 gUnknown_02032298[2];

extern u8 gUnknown_0203CF20;

extern const struct BgTemplate gUnknown_0832DEE4[4];
extern const struct WindowTemplate gUnknown_0832DEF4[];
extern const u8 gUnknown_0832DE24[][2];
extern const u8 *gUnknown_0832DE94[];
extern const struct SpriteTemplate gSpriteTemplate_832DC94;
extern const struct SpriteTemplate gSpriteTemplate_832DCAC;
extern const u8 gTradeStripesBG2Tilemap[];
extern const u8 gTradeStripesBG3Tilemap[];
extern struct MailStruct gUnknown_020321C0[PARTY_SIZE];
extern const u8 gJPText_Shedinja[];
extern const u8 gText_IsThisTradeOkay[];
extern const u8 gUnknown_0832DCEC[][4][6];
extern const struct MenuAction gUnknown_0832DEAC[];
extern const struct WindowTemplate gUnknown_0832DF8C;
extern const u16 gTradePartyBoxTilemap[];
extern const u16 gTradeMovesBoxTilemap[];
extern const u8 gUnknown_0832DEE0[];
extern const u8 gUnknown_0832DF99[][2];

bool32 sub_8077260(void);
void sub_80773D0(void);
void sub_807811C(void);
void sub_807A19C(u8);
bool8 shedinja_maker_maybe(void);
void sub_807A308(const u8 *, u8 *, u8);
bool8 sub_807A1F0(void);
void sub_807A320(u8);
void sub_8079BE0(u8);
void sub_8078388(void);
void sub_80782B8(u8);
void sub_807A468(u8);
void sub_807A53C(void);
void sub_8078C34(void);
void sub_807825C(void);
void sub_807A5B0(void);
void sub_80795AC(void);
void sub_807A0C4(void);
void sub_80796B4(u8);
void sub_8079E44(u8);
void sub_807967C(u8);
void sub_807A048(u16, u8);
void sub_8079F74(void);
u32 sub_807A5F4(struct Pokemon *, u8, u8);
void sub_8079F88(u8);
u32 sub_807A09C(void);
u8 sub_8079A3C(u8 *, u8, u8);
void sub_8079AA4(u8 *, u8, u8);
void sub_8079C4C(u8, u8, u8, u8, u8, u8);

bool8 sub_8077170(const void *a0, u32 a1)
{
    if (gUnknown_02022C2C == 29)
    {
        rfu_NI_setSendData(gUnknown_03004140.unk_00, 84, a0, a1);
        return TRUE;
    }
    else
    {
        return SendBlock(0, a0, a1);
    }
}

void sub_80771AC(u8 a0)
{
    sub_800A4D8(a0);
}

bool32 sub_80771BC(void)
{
    if (gUnknown_02022C2C == 29)
    {
        if (gUnknown_03007880[sub_800E87C(gUnknown_03004140.unk_00)]->unk_0 == 0)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return sub_800A520();
    }
}

u32 sub_8077200(void)
{
    return GetBlockReceivedStatus();
}

void sub_8077210(void)
{
    if (sub_8077260())
    {
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    }
    else
    {
        ResetBlockReceivedFlags();
    }
}

void sub_8077234(u32 a0)
{
    if (sub_8077260())
    {
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    }
    else
    {
        ResetBlockReceivedFlag(a0);
    }
}

bool32 sub_8077260(void)
{
    if (gWirelessCommType != 0 && gUnknown_02022C2C == 29)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void sub_8077288(void)
{
    sub_800ADF8();
}

bool8 sub_8077294(void)
{
    return sub_800A520();
}

void sub_80772A4(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();

    gPaletteFade.bufferTransferDisabled = TRUE;

    SetVBlankCallback(sub_807811C);
    LoadPalette(gUnknown_0860F074, 0xF0, 20);
    LoadPalette(gUnknown_0860F074, 0xD0, 20);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0832DEE4, ARRAY_COUNT(gUnknown_0832DEE4));
    SetBgTilemapBuffer(1, gUnknown_0203229C->tilemapBuffer);

    if (InitWindows(gUnknown_0832DEF4))
    {
        u32 i;

        DeactivateAllTextPrinters();

        for (i = 0; i < 18; i++)
        {
            ClearWindowTilemap(i);
            FillWindowPixelBuffer(i, 0);
        }

        FillBgTilemapBufferRect(0, 0, 0, 0, 30, 20, 15);
        LoadUserWindowBorderGfx_(0, 20, 0xC0);
        LoadUserWindowBorderGfx(2, 1, 0xE0);
        LoadMonIconPalettes();
        gUnknown_0203229C->unk_69 = 0;
        gUnknown_0203229C->unk_6F = 0;
        gUnknown_0203229C->unk_70 = 0;
        gUnknown_0203229C->unk_74[0] = 0;
        gUnknown_0203229C->unk_74[1] = 0;
        gUnknown_0203229C->unk_7A = 0;
        gUnknown_0203229C->unk_7B = 0;
        gUnknown_0203229C->unk_A8 = 0;
    }
}

void sub_80773AC(void)
{
    SetMainCallback2(sub_80773D0);
    gMain.callback1 = NULL;
    gEnemyPartyCount = 0;
}

void sub_80773D0(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        gUnknown_0203229C = AllocZeroed(sizeof(*gUnknown_0203229C));
        sub_80772A4();
        gUnknown_02032184 = AllocZeroed(0xE00);
        
        for (i = 0; i < 14; i++)
        {
            gUnknown_02032188[i] = &gUnknown_02032184[i * 256];
        }

        gMain.state++;
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = FALSE;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, 0x20, FALSE, 0, 0, 0);
        }

        sub_807A19C(0);
        ShowBg(0);

        if (gReceivedRemoteLinkPlayers == 0)
        {
            gLinkType = 0x1122;
            gUnknown_0203229C->unk_A8 = 0;

            if (gWirelessCommType != 0)
            {
                sub_800B488();
                OpenLink();
                sub_8011BA4();
            }
            else
            {
                OpenLink();
                gMain.state++;
                CreateTask(task00_08081A90, 1);
            }
        }
        else
        {
            gMain.state = 4;
        }
        break;
    case 2:
        gUnknown_0203229C->unk_A8++;
        if (gUnknown_0203229C->unk_A8 > 11)
        {
            gUnknown_0203229C->unk_A8 = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= sub_800AA48())
        {
            if (IsLinkMaster())
            {
                if (++gUnknown_0203229C->unk_A8 > 30)
                {
                    sub_800A620();
                    gMain.state++;
                }
            }
            else
            {
                gMain.state++;
            }
        }
        break;
    case 4:
        if (gReceivedRemoteLinkPlayers == 1 && IsLinkPlayerDataExchangeComplete() == 1)
        {
            sub_8011BD0();
            CalculatePlayerPartyCount();
            gMain.state++;
            gUnknown_0203229C->unk_A8 = 0;
            if (gWirelessCommType != 0)
            {
                sub_801048C(TRUE);
                sub_800ADF8();
            }
        }
        break;
    case 5:
        if (gWirelessCommType != 0)
        {
            if (sub_8010500())
            {
                gMain.state++;
                sub_800E0E8();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            gMain.state++;
        }
        break;
    case 6:
        if (shedinja_maker_maybe())
        {
            sub_807A5B0();
            gMain.state++;
        }
        break;
    case 7:
        CalculateEnemyPartyCount();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        gUnknown_0203229C->unk_36[0] = gPlayerPartyCount;
        gUnknown_0203229C->unk_36[1] = gEnemyPartyCount;

        for (i = 0; i < gUnknown_0203229C->unk_36[0]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            gUnknown_0203229C->unk_28[i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < gUnknown_0203229C->unk_36[1]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->unk_2E[i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        sub_81B5D30();
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28, 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28, 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(gUnknown_0832DE94[0], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(gUnknown_0832DE94[1], gUnknown_02032188[8], 24);
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 11:
        if (sub_807A1F0())
            gMain.state++;
        break;
    case 12:
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 3;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 6;
        CreateSprite(&temp, 215, 152, 1);
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 7;
        CreateSprite(&temp, 247, 152, 1);

        for (i = 0; i < PARTY_SIZE; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 8;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        gUnknown_0203229C->unk_34 = CreateSprite(&gSpriteTemplate_832DC94, gUnknown_0832DE24[0][0] * 8 + 32, gUnknown_0832DE24[0][1] * 8, 2);
        gUnknown_0203229C->unk_35 = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        sub_807A320(0);
        sub_8079BE0(0);
        gUnknown_0203229C->unk_0 = 0;
        gUnknown_0203229C->unk_1 = 0;
        sub_8078388();
        gMain.state++;
        PlayBGM(MUS_P_SCHOOL);
        break;
    case 15:
        sub_807A320(1);
        sub_8079BE0(1);
        gMain.state++;
    case 16: // fallthrough
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        gMain.state++;
        break;
    case 18:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        sub_80782B8(2);
        gMain.state++;
        break;
    case 20:
        sub_807A468(0);
        gMain.state++;
        break;
    case 21:
        sub_807A468(1);
        sub_807A53C();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            gMain.callback1 = sub_8078C34;
            SetMainCallback2(sub_807825C);
        }
        break;
    }

    RunTextPrinters();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_8077B74(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        sub_80772A4();
        gMain.state++;
        break;
    case 1:
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        gMain.state++;
        break;
    case 4:
        CalculatePlayerPartyCount();
        gMain.state++;
        break;
    case 5:
        if (gWirelessCommType != 0)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        gMain.state++;
        break;
    case 6:
        gMain.state++;
        break;
    case 7:
        CalculateEnemyPartyCount();
        gUnknown_0203229C->unk_36[0] = gPlayerPartyCount;
        gUnknown_0203229C->unk_36[1] = gEnemyPartyCount;
        ClearWindowTilemap(0);
        sub_8079BE0(0);
        sub_8079BE0(1);

        for (i = 0; i < gUnknown_0203229C->unk_36[0]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            gUnknown_0203229C->unk_28[i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < gUnknown_0203229C->unk_36[1]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->unk_2E[i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        sub_81B5D30();
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28, 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28, 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(gUnknown_0832DE94[0], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(gUnknown_0832DE94[1], gUnknown_02032188[8], 24);
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 11:
        if (sub_807A1F0())
            gMain.state++;
        break;
    case 12:
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 3;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 6;
        CreateSprite(&temp, 215, 152, 1);
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 7;
        CreateSprite(&temp, 247, 152, 1);

        for (i = 0; i < PARTY_SIZE; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 8;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        if (gUnknown_0203229C->unk_35 < PARTY_SIZE)
        {
            gUnknown_0203229C->unk_35 = gUnknown_0203CF20;
        }
        else
        {
            gUnknown_0203229C->unk_35 = gUnknown_0203CF20 + PARTY_SIZE;
        }

        gUnknown_0203229C->unk_34 = CreateSprite(&gSpriteTemplate_832DC94, gUnknown_0832DE24[gUnknown_0203229C->unk_35][0] * 8 + 32, gUnknown_0832DE24[gUnknown_0203229C->unk_35][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        gUnknown_0203229C->unk_0 = 0;
        gUnknown_0203229C->unk_1 = 0;
        sub_8078388();
        gMain.state++;
        break;
    case 18:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        sub_80782B8(2);
        gMain.state++;
        break;
    case 20:
        gMain.state++;
        break;
    case 21:
        sub_807A53C();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(sub_807825C);
        }
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807811C(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_8078130(void)
{
    if (++gUnknown_0203229C->unk_A8 > 15)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203229C->unk_6F = 10;
    }
}

void sub_807816C(void)
{
    if (!gPaletteFade.active)
    {
        gUnknown_02032298[0] = gUnknown_0203229C->unk_35;
        gUnknown_02032298[1] = gUnknown_0203229C->unk_7E;

        if (gWirelessCommType != 0)
        {
            gUnknown_0203229C->unk_6F = 16;
        }
        else
        {
            sub_800ABF4(32);
            gUnknown_0203229C->unk_6F = 13;
        }
    }
}

void sub_80781C8(void)
{
    gMain.savedCallback = sub_80773AC;

    if (gWirelessCommType != 0)
    {
        if (sub_8010500())
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(gUnknown_0203229C);
            gMain.callback1 = NULL;
            sub_800E084();
            SetMainCallback2(sub_807AE50);
        }
    }
    else
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(gUnknown_0203229C);
            gMain.callback1 = NULL;
            SetMainCallback2(sub_807AE50);
        }
    }
}

void sub_807825C(void)
{
    u8 temp;

    sub_80795AC();
    sub_807A0C4();
    sub_80796B4(0);
    sub_80796B4(1);
    
    SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_0203229C->unk_0++);
    SetGpuReg(REG_OFFSET_BG3HOFS, gUnknown_0203229C->unk_1--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_80782B8(u8 a0)
{
    int i;

    switch (a0)
    {
    case 0:
        LoadPalette(gUnknown_08DDB3E4, 0, 0x60);
        LoadBgTiles(1, gUnknown_08DDB464, 0x1280, 0);
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDCF04, 0, 0, 32, 20, 0);
        LoadBgTilemap(2, gTradeStripesBG2Tilemap, 0x800, 0);
        break;
    case 1:
        LoadBgTilemap(3, gTradeStripesBG3Tilemap, 0x800, 0);
        sub_8079E44(0);
        sub_8079E44(1);
        CopyBgTilemapBufferToVram(1);
        break;
    case 2:
        for (i = 0; i < 4; i++)
        {
            SetGpuReg(REG_OFFSET_BG0HOFS + (i * 2), 0);
        }
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        break;
    }
}

void sub_8078388(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i < gUnknown_0203229C->unk_36[0])
        {
            gSprites[gUnknown_0203229C->unk_28[i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i] = FALSE;
        }
        
        if (i < gUnknown_0203229C->unk_36[1])
        {
            gSprites[gUnknown_0203229C->unk_2E[i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i + PARTY_SIZE] = FALSE;
        }
    }

    gUnknown_0203229C->unk_44 = 1;
}

void sub_8078438(u8 *dest, const u8 *src, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        dest[i] = src[i];
    }
}

bool8 shedinja_maker_maybe(void)
{
    u8 id = GetMultiplayerId();
    int i;
    struct Pokemon *mon;

    switch (gUnknown_0203229C->unk_69)
    {
    case 0:
        sub_8078438(gBlockSendBuffer, (void *)&gPlayerParty[0], 200);
        gUnknown_0203229C->unk_69++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 1:
        if (sub_80771BC())
        {
            if (!sub_8077200())
            {
                gUnknown_0203229C->unk_69++;
            }
            else
            {
                sub_8077210();
                gUnknown_0203229C->unk_69++;
            }
        }
        break;
    case 3:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 4:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)&gEnemyParty[0], (void *)gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 5:
        sub_8078438(gBlockSendBuffer, (void *)&gPlayerParty[2], 200);
        gUnknown_0203229C->unk_69++;
        break;
    case 7:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 8:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)&gEnemyParty[2], (void *)gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 9:
        sub_8078438(gBlockSendBuffer, (void *)&gPlayerParty[4], 200);
        gUnknown_0203229C->unk_69++;
        break;
    case 11:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 12:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)&gEnemyParty[4], (void *)gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 13:
        sub_8078438(gBlockSendBuffer, (void *)gSaveBlock1Ptr->mail, 220);
        gUnknown_0203229C->unk_69++;
        break;
    case 15:
        if (id == 0)
        {
            sub_80771AC(3);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 16:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)gUnknown_020321C0, (void *)gBlockRecvBuffer[id ^ 1], 216);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 17:
        sub_8078438(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, 11);
        gUnknown_0203229C->unk_69++;
        break;
    case 19:
        if (id == 0)
        {
            sub_80771AC(4);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 20:
        if (sub_8077200() == 3)
        {
            sub_8078438(gUnknown_0203229C->unk_A9, (void *)gBlockRecvBuffer[id ^ 1], 11);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 21:
        for (i = 0, mon = gEnemyParty; i < PARTY_SIZE; mon++, i++)
        {
            u8 name[POKEMON_NAME_LENGTH + 1];
            u16 species = GetMonData(mon, MON_DATA_SPECIES);

            if (species != SPECIES_NONE)
            {
                if (species == SPECIES_SHEDINJA && GetMonData(mon, MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
                {
                    GetMonData(mon, MON_DATA_NICKNAME, name);

                    if (!StringCompareWithoutExtCtrlCodes(name, gJPText_Shedinja))
                    {
                        SetMonData(mon, MON_DATA_NICKNAME, gSpeciesNames[SPECIES_SHEDINJA]);
                    }
                }
            }
        }
        return TRUE;
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        gUnknown_0203229C->unk_A8++;
        if (gUnknown_0203229C->unk_A8 > 10)
        {
            gUnknown_0203229C->unk_A8 = 0;
            gUnknown_0203229C->unk_69++;
        }
        break;
    }
    return FALSE;
}

void sub_80787B8(void)
{
    sub_807A308(gText_IsThisTradeOkay, (void *)(OBJ_VRAM0 + (gUnknown_0203229C->unk_72 * 32)), 24);
}

void sub_80787E0(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEAA:
            gUnknown_0203229C->unk_78 = 2;
            break;
        case 0xAABB:
            gUnknown_0203229C->unk_78 = 1;
            break;
        case 0xBBBB:
            gUnknown_0203229C->unk_7A = 1;
            break;
        case 0xBBCC:
            gUnknown_0203229C->unk_7A = 2;
            break;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case 0xEEAA:
            gUnknown_0203229C->unk_79 = 2;
            break;
        case 0xAABB:
            gUnknown_0203229C->unk_7E = gBlockRecvBuffer[1][1] + 6;
            gUnknown_0203229C->unk_79 = 1;
            break;
        case 0xBBBB:
            gUnknown_0203229C->unk_7B = 1;
            break;
        case 0xBBCC:
            gUnknown_0203229C->unk_7B = 2;
            break;
        }
        sub_8077234(1);
    }
}

void sub_8078900(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEBB:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sub_807A19C(4);
            gUnknown_0203229C->unk_6F = 11;
            break;
        case 0xEECC:
            sub_807A19C(5);
            gUnknown_0203229C->unk_6F = 8;
            break;
        case 0xDDDD:
            gUnknown_0203229C->unk_7E = gBlockRecvBuffer[0][1] + 6;
            rbox_fill_rectangle(0);
            sub_807967C(gUnknown_0203229C->unk_35);
            sub_807967C(gUnknown_0203229C->unk_7E);
            gUnknown_0203229C->unk_6F = 7;
            break;
        case 0xCCDD:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 10;
            break;
        case 0xDDEE:
            sub_807A19C(1);
            gUnknown_0203229C->unk_6F = 8;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
    {
        sub_8077234(1);
    }
}

// Can't get some weird loading behavior for unk_78/79/7A/7B for parts of this
#ifdef NONMATCHING
void sub_80789FC(void)
{
    if (gUnknown_0203229C->unk_78 && gUnknown_0203229C->unk_79)
    {
        if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 1)
        {
            gUnknown_0203229C->unk_6F = 6;
            gUnknown_0203229C->unk_80[0] = 0xDDDD;
            gUnknown_0203229C->unk_80[1] = gUnknown_0203229C->unk_35;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_78 = 0;
        }
        else if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->unk_80[0] = 0xEECC;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_78 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 1)
        {
            sub_807A19C(5);
            gUnknown_0203229C->unk_80[0] = 0xDDEE;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_78 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 2)
        {
            gUnknown_0203229C->unk_80[0] = 0xEEBB;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_78 = 0;
            gUnknown_0203229C->unk_6F = 11;
        }
    }

    if (gUnknown_0203229C->unk_7A && gUnknown_0203229C->unk_7B)
    {
        if (gUnknown_0203229C->unk_7A == 1 && gUnknown_0203229C->unk_7B == 1)
        {
            gUnknown_0203229C->unk_80[0] = 0xCCDD;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_6F = 9;
        }

        if (gUnknown_0203229C->unk_7A == 2 || gUnknown_0203229C->unk_7B == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->unk_80[0] = 0xDDEE;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
    }
}
#else
NAKED
void sub_80789FC(void)
{
    asm_unified("push {r4-r6,lr}\n\
	sub sp, 0x4\n\
	ldr r6, =gUnknown_0203229C\n\
	ldr r2, [r6]\n\
	adds r1, r2, 0\n\
	adds r1, 0x78\n\
	ldrb r0, [r1]\n\
	cmp r0, 0\n\
	bne _08078A10\n\
	b _08078B44\n\
_08078A10:\n\
	adds r0, r2, 0\n\
	adds r0, 0x79\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	bne _08078A1C\n\
	b _08078B44\n\
_08078A1C:\n\
	ldrh r1, [r1]\n\
	ldr r0, =0x00000101\n\
	cmp r1, r0\n\
	bne _08078A64\n\
	adds r1, r2, 0\n\
	adds r1, 0x6F\n\
	movs r0, 0x6\n\
	strb r0, [r1]\n\
	ldr r2, [r6]\n\
	adds r1, r2, 0\n\
	adds r1, 0x80\n\
	movs r4, 0\n\
	ldr r0, =0x0000dddd\n\
	strh r0, [r1]\n\
	adds r0, r2, 0\n\
	adds r0, 0x35\n\
	ldrb r1, [r0]\n\
	adds r0, 0x4D\n\
	strh r1, [r0]\n\
	movs r0, 0x5\n\
	movs r1, 0\n\
	bl sub_807A048\n\
	ldr r0, [r6]\n\
	adds r2, r0, 0\n\
	adds r2, 0x79\n\
	strb r4, [r2]\n\
	adds r0, 0x78\n\
	strb r4, [r0]\n\
	b _08078B44\n\
	.pool\n\
_08078A64:\n\
	ldr r0, =0x00000201\n\
	cmp r1, r0\n\
	bne _08078AB4\n\
	movs r0, 0x1\n\
	bl sub_807A19C\n\
	ldr r1, [r6]\n\
	adds r2, r1, 0\n\
	adds r2, 0x80\n\
	movs r4, 0\n\
	movs r3, 0\n\
	ldr r0, =0x0000eecc\n\
	strh r0, [r2]\n\
	adds r1, 0x82\n\
	strh r3, [r1]\n\
	movs r0, 0x5\n\
	movs r1, 0\n\
	bl sub_807A048\n\
	ldr r0, [r6]\n\
	adds r1, r0, 0\n\
	adds r1, 0x7B\n\
	strb r4, [r1]\n\
	adds r0, 0x7A\n\
	strb r4, [r0]\n\
	ldr r0, [r6]\n\
	adds r1, r0, 0\n\
	adds r1, 0x79\n\
	strb r4, [r1]\n\
	adds r0, 0x78\n\
	strb r4, [r0]\n\
	ldr r0, [r6]\n\
	adds r0, 0x6F\n\
	movs r1, 0x8\n\
	b _08078B42\n\
	.pool\n\
_08078AB4:\n\
	movs r0, 0x81\n\
	lsls r0, 1\n\
	cmp r1, r0\n\
	bne _08078B00\n\
	movs r0, 0x5\n\
	bl sub_807A19C\n\
	ldr r1, [r6]\n\
	adds r2, r1, 0\n\
	adds r2, 0x80\n\
	movs r4, 0\n\
	movs r3, 0\n\
	ldr r0, =0x0000ddee\n\
	strh r0, [r2]\n\
	adds r1, 0x82\n\
	strh r3, [r1]\n\
	movs r0, 0x5\n\
	movs r1, 0\n\
	bl sub_807A048\n\
	ldr r0, [r6]\n\
	adds r1, r0, 0\n\
	adds r1, 0x7B\n\
	strb r4, [r1]\n\
	adds r0, 0x7A\n\
	strb r4, [r0]\n\
	ldr r0, [r6]\n\
	adds r1, r0, 0\n\
	adds r1, 0x79\n\
	strb r4, [r1]\n\
	adds r0, 0x78\n\
	strb r4, [r0]\n\
	ldr r0, [r6]\n\
	adds r0, 0x6F\n\
	movs r1, 0x8\n\
	b _08078B42\n\
	.pool\n\
_08078B00:\n\
	ldr r0, =0x00000202\n\
	cmp r1, r0\n\
	bne _08078B44\n\
	adds r1, r2, 0\n\
	adds r1, 0x80\n\
	movs r5, 0\n\
	movs r4, 0\n\
	ldr r0, =0x0000eebb\n\
	strh r0, [r1]\n\
	adds r0, r2, 0\n\
	adds r0, 0x82\n\
	strh r4, [r0]\n\
	movs r0, 0x5\n\
	movs r1, 0\n\
	bl sub_807A048\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	str r4, [sp]\n\
	movs r1, 0\n\
	movs r2, 0\n\
	movs r3, 0x10\n\
	bl BeginNormalPaletteFade\n\
	ldr r0, [r6]\n\
	adds r1, r0, 0\n\
	adds r1, 0x79\n\
	strb r5, [r1]\n\
	adds r0, 0x78\n\
	strb r5, [r0]\n\
	ldr r0, [r6]\n\
	adds r0, 0x6F\n\
	movs r1, 0xB\n\
_08078B42:\n\
	strb r1, [r0]\n\
_08078B44:\n\
	ldr r5, =gUnknown_0203229C\n\
	ldr r3, [r5]\n\
	adds r1, r3, 0\n\
	adds r1, 0x7A\n\
	ldrb r0, [r1]\n\
	cmp r0, 0\n\
	beq _08078BDC\n\
	adds r0, r3, 0\n\
	adds r0, 0x7B\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _08078BDC\n\
	ldrh r1, [r1]\n\
	ldr r0, =0x00000101\n\
	cmp r1, r0\n\
	bne _08078B92\n\
	adds r1, r3, 0\n\
	adds r1, 0x80\n\
	movs r4, 0\n\
	movs r2, 0\n\
	ldr r0, =0x0000ccdd\n\
	strh r0, [r1]\n\
	adds r0, r3, 0\n\
	adds r0, 0x82\n\
	strh r2, [r0]\n\
	movs r0, 0x5\n\
	movs r1, 0\n\
	bl sub_807A048\n\
	ldr r0, [r5]\n\
	adds r0, 0x7A\n\
	strb r4, [r0]\n\
	ldr r0, [r5]\n\
	adds r0, 0x7B\n\
	strb r4, [r0]\n\
	ldr r0, [r5]\n\
	adds r0, 0x6F\n\
	movs r1, 0x9\n\
	strb r1, [r0]\n\
_08078B92:\n\
	ldr r1, [r5]\n\
	adds r0, r1, 0\n\
	adds r0, 0x7A\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x2\n\
	beq _08078BA8\n\
	adds r0, r1, 0\n\
	adds r0, 0x7B\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x2\n\
	bne _08078BDC\n\
_08078BA8:\n\
	movs r0, 0x1\n\
	bl sub_807A19C\n\
	ldr r1, [r5]\n\
	adds r2, r1, 0\n\
	adds r2, 0x80\n\
	movs r4, 0\n\
	movs r3, 0\n\
	ldr r0, =0x0000ddee\n\
	strh r0, [r2]\n\
	adds r1, 0x82\n\
	strh r3, [r1]\n\
	movs r0, 0x5\n\
	movs r1, 0\n\
	bl sub_807A048\n\
	ldr r0, [r5]\n\
	adds r0, 0x7A\n\
	strb r4, [r0]\n\
	ldr r0, [r5]\n\
	adds r0, 0x7B\n\
	strb r4, [r0]\n\
	ldr r0, [r5]\n\
	adds r0, 0x6F\n\
	movs r1, 0x8\n\
	strb r1, [r0]\n\
_08078BDC:\n\
	add sp, 0x4\n\
	pop {r4-r6}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif // NONMATCHING

void sub_8078BFC(u16 *a0, u16 a1, u16 a2)
{
    a0[0] = a1;
    a0[1] = a2;
    sub_807A048(5, 0);
}

void sub_8078C10(u16 a0, u16 a1)
{
    sub_8078BFC(gUnknown_0203229C->unk_80, a0, a1);
}

void sub_8078C34(void)
{
    u8 id = GetMultiplayerId();
    u8 unk;

    if ((unk = sub_8077200()))
    {
        if (id == 0)
        {
            sub_80787E0(id, unk);
        }
        else
        {
            sub_8078900(id, unk);
        }
    }

    if (id == 0)
    {
        sub_80789FC();
    }
}

u8 sub_8078C6C(u8 a0, u8 a1)
{
    int i;
    u8 ret = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gUnknown_0203229C->unk_38[gUnknown_0832DCEC[a0][a1][i]] == 1)
        {
            ret = gUnknown_0832DCEC[a0][a1][i];
            break;
        }
    }

    return ret;
}

void sub_8078CB8(u8 *a0, u8 a1)
{
    u8 unk = sub_8078C6C(*a0, a1);

    if (unk == 12)
    {
        StartSpriteAnim(&gSprites[gUnknown_0203229C->unk_34], 1);
        gSprites[gUnknown_0203229C->unk_34].pos1.x = 224;
        gSprites[gUnknown_0203229C->unk_34].pos1.y = 160;
    }
    else
    {
        StartSpriteAnim(&gSprites[gUnknown_0203229C->unk_34], 0);
        gSprites[gUnknown_0203229C->unk_34].pos1.x = gUnknown_0832DE24[unk][0] * 8 + 32;
        gSprites[gUnknown_0203229C->unk_34].pos1.y = gUnknown_0832DE24[unk][1] * 8;
    }

    if (*a0 != unk)
    {
        PlaySE(SE_SELECT);
    }

    *a0 = unk;
}

void sub_8078D78(void)
{
    sub_807A19C(0);
    gUnknown_0203229C->unk_6F = 100;

    if (GetMultiplayerId() == 1)
    {
        sub_8078C10(0xAABB, gUnknown_0203229C->unk_35);
    }
    else
    {
        gUnknown_0203229C->unk_78 = 1;
    }
}

void sub_8078DBC(void)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 0);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 1);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 2);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 3);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        if (gUnknown_0203229C->unk_35 < 6)
        {
            sub_8098858(1, 1, 14);
            FillWindowPixelBuffer(1, 0x11);
            PrintMenuTable(1, 2, gUnknown_0832DEAC);
            InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
            PutWindowTilemap(1);
            CopyWindowToVram(1, 3);
            gUnknown_0203229C->unk_6F = 1;
        }
        else if (gUnknown_0203229C->unk_35 < 12)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 2;
        }
        else if (gUnknown_0203229C->unk_35 == 12)
        {
            CreateYesNoMenu(&gUnknown_0832DF8C, 1, 14, 0);
            gUnknown_0203229C->unk_6F = 4;
            sub_807A308(gUnknown_0832DE94[4], (void *)(OBJ_VRAM0 + gUnknown_0203229C->unk_72 * 32), 24);
        }
    }
}

void sub_8078EF8(void)
{
    sub_8079F74();
    gUnknown_0203229C->unk_6F = 0;
    gSprites[gUnknown_0203229C->unk_34].invisible = FALSE;
    sub_807A308(gUnknown_0832DE94[1], (void *)(OBJ_VRAM0 + gUnknown_0203229C->unk_72 * 32), 24);
}

void sub_8078F50(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
        case MENU_NOTHING_CHOSEN:
            break;
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 2;
            break;
        case 1:
            switch (sub_807A5F4(gPlayerParty, gPlayerPartyCount, gUnknown_0203229C->unk_35))
            {
                case 0:
                    sub_8078D78();
                    gSprites[gUnknown_0203229C->unk_34].invisible = TRUE;
                    break;
                case 1:
                    sub_807A048(3, 3);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
                case 2:
                case 4:
                    sub_807A048(3, 6);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
                case 3:
                case 5:
                    sub_807A048(3, 7);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
            }
            break;
    }
}

void sub_8079034(void)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_8078EF8();
    }
}

void sub_807905C(void)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203229C->unk_35 < PARTY_SIZE)
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, gUnknown_0203229C->unk_35, gUnknown_0203229C->unk_36[0] - 1, sub_8077B74);
        }
        else
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gEnemyParty, gUnknown_0203229C->unk_35 - PARTY_SIZE, gUnknown_0203229C->unk_36[1] - 1, sub_8077B74);
        }
        FreeAllWindowBuffers();
    }
}

u8 sub_80790D4(u8 *a0, u8 a1, u8 a2, u8 a3)
{
    int i;
    u16 species;
    u8 res = 0;

    for (i = 0; i < a1; i++)
    {
        if (a2 != i)
        {
            res += a0[i];
        }
    }

    a3 %= PARTY_SIZE;
    species = GetMonData(&gEnemyParty[a3], MON_DATA_SPECIES);

    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!GetMonData(&gEnemyParty[a3], MON_DATA_OBEDIENCE))
        {
            return 2;
        }
    }

    if (!IsNationalPokedexEnabled())
    {
        if (gUnknown_0203229C->unk_57[a3] || !IsSpeciesInHoennDex(species))
        {
            return 2;
        }
    }
    
    if (res)
    {
        res = 1;
    }

    return res;
}

bool32 sub_8079174(void)
{
    int i;
    u8 arr[12];

    for (i = 0; i < gUnknown_0203229C->unk_36[0]; i++)
    {
        arr[i] = gUnknown_0203229C->unk_45[i];
    }

    switch (sub_80790D4(arr, gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_35, gUnknown_0203229C->unk_7E))
    {
        case 0:
            sub_807A048(3, 3);
            sub_8078C10(0xBBCC, 0);
            break;
        case 1:
            sub_807A048(3, 1);
            sub_8078C10(0xBBBB, 0);
            break;
        case 2:
            sub_807A048(3, 8);
            return TRUE;
    }

    return FALSE;
}

void sub_8079218(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            if (!sub_8079174())
            {
                gUnknown_0203229C->unk_6F = 100;
            }
            else
            {
                gUnknown_0203229C->unk_6F = 17;
            }
            PutWindowTilemap(17);
            break;
        case 1:
        case MENU_B_PRESSED:
            sub_807A048(3, 1);
            if (sub_80771BC())
            {
                sub_8078C10(0xBBCC, 0);
            }
            gUnknown_0203229C->unk_6F = 100;
            PutWindowTilemap(17);
            break;
    }
}

void sub_807929C(void)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->unk_36[1] - 4; i++)
    {
        PutWindowTilemap(i + 12);
        CopyWindowToVram(i + 12, 1);
    }
}

void sub_80792E4(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            sub_807A19C(4);
            sub_8078C10(0xEEAA, 0);
            gSprites[gUnknown_0203229C->unk_34].invisible = TRUE;
            gUnknown_0203229C->unk_6F = 100;
            sub_807929C();
            break;
        case 1:
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
    }
}

void sub_807935C(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        sub_807967C(gUnknown_0203229C->unk_35);
        sub_807967C(gUnknown_0203229C->unk_7E);
    }
    gUnknown_0203229C->unk_6F = 7;
}

void sub_8079398(void)
{
    if (gUnknown_0203229C->unk_74[0] == 5 && gUnknown_0203229C->unk_74[1] == 5)
    {
        sub_80787B8();
        gUnknown_0203229C->unk_6F = 14;
    }
}

void sub_80793C4(void)
{
    gUnknown_0203229C->unk_A8++;
    
    if (gUnknown_0203229C->unk_A8 > 120)
    {
        CreateYesNoMenu(&gUnknown_0832DF8C, 1, 14, 0);
        gUnknown_0203229C->unk_A8 = 0;
        gUnknown_0203229C->unk_6F = 3;
    }
}

void sub_8079408(void)
{
    int i;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(0);
        rbox_fill_rectangle(1);

        for (i = 0; i < 4; i++)
        {
            FillWindowPixelBuffer(i + 14, 0);
            rbox_fill_rectangle(i + 14);
        }

        sub_8079F88(0);
        sub_8079F88(1);
        gUnknown_0203229C->unk_6F = 0;
        gSprites[gUnknown_0203229C->unk_34].invisible = FALSE;
    }
}

void sub_8079490(void)
{
    if (!gPaletteFade.active)
    {
        if (gWirelessCommType)
        {
            sub_800ADF8();
        }
        else
        {
            sub_800ABF4(12);
        }

        gUnknown_0203229C->unk_6F = 12;
    }
}

void sub_80794CC(void)
{
    if (gWirelessCommType)
    {
        if (sub_80771BC() && sub_807A09C() == 0)
        {
            Free(gUnknown_02032184);
            Free(gUnknown_0203229C);
            FreeAllWindowBuffers();
            sub_800E084();
            SetMainCallback2(c2_8056854);
        }
    }
    else
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            Free(gUnknown_02032184);
            Free(gUnknown_0203229C);
            FreeAllWindowBuffers();
            SetMainCallback2(c2_8056854);
        }
    }
}

void sub_8079550(void)
{
    if (!sub_801048C(FALSE) && sub_807A09C() == 0)
    {
        sub_800ADF8();
        gUnknown_0203229C->unk_6F = 13;
    }
}

void sub_807957C(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        sub_8078C10(0xBBCC, 0);
        gUnknown_0203229C->unk_6F = 100;
    }
}

void sub_80795AC(void)
{
    switch (gUnknown_0203229C->unk_6F)
    {
        case 0:
            sub_8078DBC();
            break;
        case 1:
            sub_8078F50();
            break;
        case 2:
            sub_807905C();
            break;
        case 3:
            sub_8079218();
            break;
        case 4:
            sub_80792E4();
            break;
        case 6:
            sub_807935C();
            break;
        case 7:
            sub_8079398();
            break;
        case 8:
            sub_8079408();
            break;
        case 9:
            sub_8078130();
            break;
        case 10:
            sub_807816C();
            break;
        case 11:
            sub_8079490();
            break;
        case 12:
            sub_80794CC();
            break;
        case 13:
            sub_80781C8();
            break;
        case 14:
            sub_80793C4();
            break;
        case 15:
            sub_8079034();
            break;
        case 16:
            sub_8079550();
            break;
        case 17:
            sub_807957C();
            break;
    }
}

void sub_807967C(u8 a0)
{
    u8 whichTeam = a0 / PARTY_SIZE;

    if (gUnknown_0203229C->unk_74[whichTeam] == 0)
    {
        gUnknown_0203229C->unk_74[whichTeam] = 1;
        gUnknown_0203229C->unk_76[whichTeam] = a0;
    }
}

void sub_80796B4(u8 a0)
{
    s8 test;
    u8 sp14[20];
    u8 sp28[48];
    u8 i;
    u8 r10 = gUnknown_0203229C->unk_76[a0];
    u32 sp60;
    sp60 = 1;
    if (gUnknown_0203229C->unk_76[a0] < 6)
        sp60 = 0;
    r10 %= 6;
    
    switch (gUnknown_0203229C->unk_74[a0])
    {
        case 1:
            for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
            {
                gSprites[gUnknown_0203229C->unk_28[i + (sp60 * 6)]].invisible = TRUE;
            }

            for (i = 0; i < 6; i++)
            {
                ClearWindowTilemap(i + (a0 * 6 + 2));
            }
            
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].invisible = FALSE;
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].data[0] = 20;
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].data[2] = (gUnknown_0832DE24[sp60 * 6][0] + gUnknown_0832DE24[sp60 * 6 + 1][0]) / 2 * 8 + 14;
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].data[4] = (gUnknown_0832DE24[sp60 * 6][1] * 8) - 12;
            StoreSpriteCallbackInData6(&gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]], sub_80D3014);
            gUnknown_0203229C->unk_74[a0]++;
            sub_80A6DEC(&gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]]);
            CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(0);

            if (!sp60)
            {
                sub_8079F74();
            }
            break;
        case 2:
            if (gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].callback == sub_80D3014)
            {
                gUnknown_0203229C->unk_74[a0] = 3;
            }
            break;
        case 3:
            CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMovesBoxTilemap, sp60 * 15, 0, 15, 17, 0);
            CopyBgTilemapBufferToVram(1);
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].pos1.x = (gUnknown_0832DE24[sp60 * 6][0] + gUnknown_0832DE24[sp60 * 6 + 1][0]) / 2 * 8 + 14;
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].pos1.y = (gUnknown_0832DE24[sp60 * 6][1] * 8) - 12;
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].pos2.x = 0;
            gSprites[gUnknown_0203229C->unk_28[r10 + (sp60 * 6)]].pos2.y = 0;
            test = sub_8079A3C(sp14, sp60, r10);
            AddTextPrinterParameterized3((a0 * 2) + 14, 0, (80 - test) / 2, 4, gUnknown_0832DEE0, 0, sp14);
            sub_8079AA4(sp28, sp60, r10);
            AddTextPrinterParameterized4((a0 * 2) + 15, 1, 0, 0, 0, 0, gUnknown_0832DEE0, 0, sp28);
            PutWindowTilemap((a0 * 2) + 14);
            CopyWindowToVram((a0 * 2) + 14, 3);
            PutWindowTilemap((a0 * 2) + 15);
            CopyWindowToVram((a0 * 2) + 15, 3);
            gUnknown_0203229C->unk_74[a0]++;
            break;
        case 4:
            sub_8079C4C(a0, r10, gUnknown_0832DF99[a0][0] + 4, gUnknown_0832DF99[a0][1] + 1, gUnknown_0832DF99[a0][0], gUnknown_0832DF99[a0][1]);
            gUnknown_0203229C->unk_74[a0]++;
            break;
    }
}
