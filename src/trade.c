#include "global.h"
#include "alloc.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "bg.h"
#include "cable_club.h"
#include "data2.h"
#include "daycare.h"
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
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/rgb.h"

extern u8 gUnknown_02022C2C;
extern struct {
    u8 unk_0;
    u8 unk_1;
    u8 filler_2[0x28 - 2];
    u8 unk_28[2][PARTY_SIZE];
    u8 unk_34;
    u8 unk_35;
    u8 unk_36[2];
    u8 unk_38[12];
    u8 unk_44;
    u8 unk_45[2][PARTY_SIZE];
    u8 unk_51[2][PARTY_SIZE];
    u8 unk_5D[PARTY_SIZE];
    u8 unk_63[PARTY_SIZE];
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
    u8 filler_B4[0x8D0-0xB4];
    struct {
        bool8 unk_0;
        u16 unk_2;
        u8 unk_4;
    } unk_8D0[4];
    u16 tilemapBuffer[0x400];    // 8F0
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
extern const u8 gText_EmptyString7[];
extern const u8 gText_NewLine3[];
extern const u8 gText_FourQuestionMarks[];
extern const u8 *gUnknown_0832DEBC[];
extern const struct SpritePalette gSpritePalette_TradeScreenText;
extern const struct SpritePalette gUnknown_0832DC44;
extern const struct SpriteSheet gUnknown_0832DC3C;

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
u32 sub_807A5F4(struct Pokemon *, int, int);
void sub_8079F88(u8);
u32 sub_807A09C(void);
u8 sub_8079A3C(u8 *, bool8, u8);
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
            gUnknown_0203229C->unk_28[0][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
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
            gUnknown_0203229C->unk_28[1][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
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
        LoadHeldItemIcons();
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28[0], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28[0], 1);
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
            gUnknown_0203229C->unk_28[0][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
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
            gUnknown_0203229C->unk_28[1][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
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
        LoadHeldItemIcons();
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28[0], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->unk_36[0], gUnknown_0203229C->unk_28[0], 1);
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
            gSprites[gUnknown_0203229C->unk_28[0][i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i] = FALSE;
        }

        if (i < gUnknown_0203229C->unk_36[1])
        {
            gSprites[gUnknown_0203229C->unk_28[1][i]].invisible = FALSE;
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
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
        }
        else if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->unk_80[0] = 0xEECC;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 1)
        {
            sub_807A19C(5);
            gUnknown_0203229C->unk_80[0] = 0xDDEE;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 2)
        {
            gUnknown_0203229C->unk_80[0] = 0xEEBB;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
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
        if (gUnknown_0203229C->unk_51[1][a3] || !IsSpeciesInHoennDex(species))
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
        arr[i] = gUnknown_0203229C->unk_45[0][i];
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
    u8 sp28[56];
    u8 i;
    u8 r8;
    u8 r10;
    u8 sp60;
    u8 var = gUnknown_0203229C->unk_76[a0];

    sp60 = 1;
    if (gUnknown_0203229C->unk_76[a0] < 6)
        sp60 = 0;
    r10 = var % 6;
    test = 0;

    switch (gUnknown_0203229C->unk_74[a0])
    {
    case 1:
        for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
        {
            gSprites[gUnknown_0203229C->unk_28[0][i + (sp60 * 6)]].invisible = TRUE;
        }

        for (i = 0; i < 6; i++)
        {
            ClearWindowTilemap(i + (a0 * 6 + 2));
        }

        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].invisible = FALSE;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].data[0] = 20;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].data[2] = (gUnknown_0832DE24[sp60 * 6][0] + gUnknown_0832DE24[sp60 * 6 + 1][0]) / 2 * 8 + 14;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].data[4] = (gUnknown_0832DE24[sp60 * 6][1] * 8) - 12;
        StoreSpriteCallbackInData6(&gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]], sub_80D3014);
        gUnknown_0203229C->unk_74[a0]++;
        sub_80A6DEC(&gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]]);
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);

        if (!sp60)
        {
            sub_8079F74();
        }
        break;
    case 2:
        if (gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].callback == sub_80D3014)
        {
            gUnknown_0203229C->unk_74[a0] = 3;
        }
        break;
    case 3:
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMovesBoxTilemap, sp60 * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos1.x = (gUnknown_0832DE24[sp60 * 6][0] + gUnknown_0832DE24[sp60 * 6 + 1][0]) / 2 * 8 + 14;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos1.y = (gUnknown_0832DE24[sp60 * 6][1] * 8) - 12;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos2.x = 0;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos2.y = 0;
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

u8 sub_8079A3C(u8 *a0, bool8 a1, u8 a2)
{
    u8 name[12];

    if (!a1)
    {
        GetMonData(&gPlayerParty[a2], MON_DATA_NICKNAME, name);
    }
    else
    {
        GetMonData(&gEnemyParty[a2], MON_DATA_NICKNAME, name);
    }

    StringCopy10(a0, name);
    return GetStringWidth(0, a0, GetFontAttribute(0, FONTATTR_LETTER_SPACING));
}

void sub_8079AA4(u8 *a0, u8 a1, u8 a2)
{
    u16 arr[4];
    u16 i;

    if (!gUnknown_0203229C->unk_51[a1][a2])
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (!a1)
            {
                arr[i] = GetMonData(&gPlayerParty[a2], i + MON_DATA_MOVE1, NULL);
            }
            else
            {
                arr[i] = GetMonData(&gEnemyParty[a2], i + MON_DATA_MOVE1, NULL);
            }
        }

        StringCopy(a0, gText_EmptyString7);

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (arr[i] != MOVE_NONE)
            {
                StringAppend(a0, gMoveNames[arr[i]]);
            }

            StringAppend(a0, gText_NewLine3);
        }
    }
    else
    {
        StringCopy(a0, gText_EmptyString7);
        StringAppend(a0, gText_FourQuestionMarks);
    }
}

void sub_8079B84(u8 a0, u8 a1, u8 *a2)
{
    u8 xPos;
    a1 += (a0 * 6) + 2;
    xPos = GetStringCenterAlignXOffset(0, a2, 64);
    AddTextPrinterParameterized3(a1, 0, xPos, 4, gUnknown_0832DEE0, 0, a2);
    PutWindowTilemap(a1);
    CopyWindowToVram(a1, 3);
}

void sub_8079BE0(u8 a0)
{
    u8 i;
    u8 sp[20];
    u8 sp14[32];
    struct Pokemon *mons = a0 == 0 ? gPlayerParty : gEnemyParty;

    for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
    {
        GetMonData(&mons[i], MON_DATA_NICKNAME, sp);
        StringCopy10(sp14, sp);
        sub_8079B84(a0, i, sp14);
    }
}

void sub_8079C4C(u8 a0, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5)
{
    u8 r6;
    u32 r2;
    u8 gender;
    u8 name[12];

    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDD704, a4, a5, 6, 3, 0);
    CopyBgTilemapBufferToVram(1);

    if (a0 == 0)
    {
        r6 = GetMonData(&gPlayerParty[a1], MON_DATA_LEVEL, NULL);
    }
    else
    {
        r6 = GetMonData(&gEnemyParty[a1], MON_DATA_LEVEL, NULL);
    }

    if (gUnknown_0203229C->unk_51[a0][a1] == 0)
    {
        if (r6 / 10 != 0)
        {
            gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32)] = (r6 / 10) + 0x60;
        }
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) + 1] = (r6 % 10) + 0x70;
    }
    else
    {
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 32] = gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 33];
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 31] = gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 36] | 0x400;
    }

    if (gUnknown_0203229C->unk_51[a0][a1] != 0)
    {
        r2 = 0x480;
    }
    else
    {
        if (a0 == 0)
        {
            gender = GetMonGender(&gPlayerParty[a1]);
            GetMonData(&gPlayerParty[a1], MON_DATA_NICKNAME, name);
        }
        else
        {
            gender = GetMonGender(&gEnemyParty[a1]);
            GetMonData(&gEnemyParty[a1], MON_DATA_NICKNAME, name);
        }

        switch (gender)
        {
            case MON_MALE:
                r2 = !NameHasGenderSymbol(name, MON_MALE) ? 0x84 : 0x83;
                break;
            case MON_FEMALE:
                r2 = !NameHasGenderSymbol(name, MON_FEMALE) ? 0x85 : 0x83;
                break;
            default:
                r2 = 0x83;
                break;
        }
    }
    gUnknown_0203229C->tilemapBuffer[(a3 - 1) * 32 + a2 + 1] = r2;
}

extern const u8 gUnknown_0832DE3E[][6][2];
extern const u8 gUnknown_0832DE56[][6][2];
// Very close but loop preamble not working.
#ifdef NONMATCHING
void sub_8079E44(u8 a0)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
    {
        sub_8079C4C(a0, i, gUnknown_0832DE3E[a0][i][0], gUnknown_0832DE3E[a0][i][1], gUnknown_0832DE56[a0][i][0], gUnknown_0832DE56[a0][i][1]);
    }
}
#else
NAKED
void sub_8079E44(u8 a0)
{
    asm_unified("push {r4-r7,lr}\n\
    sub sp, 0x8\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    movs r7, 0\n\
    ldr r0, =gUnknown_0203229C\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    bge _08079E94\n\
    lsls r0, r6, 1\n\
    adds r0, r6\n\
    ldr r1, =gUnknown_0832DE3E\n\
    lsls r0, 2\n\
    adds r5, r0, r1\n\
    ldr r1, =gUnknown_0832DE56\n\
    adds r4, r0, r1\n\
_08079E6A:\n\
    lsls r1, r7, 24\n\
    lsrs r1, 24\n\
    ldrb r2, [r5]\n\
    ldrb r3, [r5, 0x1]\n\
    ldrb r0, [r4]\n\
    str r0, [sp]\n\
    ldrb r0, [r4, 0x1]\n\
    str r0, [sp, 0x4]\n\
    adds r0, r6, 0\n\
    bl sub_8079C4C\n\
    adds r5, 0x2\n\
    adds r4, 0x2\n\
    adds r7, 0x1\n\
    ldr r0, =gUnknown_0203229C\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    blt _08079E6A\n\
_08079E94:\n\
    add sp, 0x8\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

void sub_8079EA8(u8 a0)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
    {
        gSprites[gUnknown_0203229C->unk_28[a0][i]].invisible = FALSE;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos1.x = gUnknown_0832DE24[(a0 * 6) + i][0] * 8 + 14;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos1.y = gUnknown_0832DE24[(a0 * 6) + i][1] * 8 - 12;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos2.x = 0;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos2.y = 0;
    }
}

void sub_8079F74(void)
{
    rbox_fill_rectangle(1);
    sub_8079BE0(1);
}

void sub_8079F88(u8 a0)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    sub_8079E44(a0);
    sub_8079BE0(a0);
    sub_8079EA8(a0);
    sub_807A308(gUnknown_0832DE94[1], (void *)(OBJ_VRAM0 + (gUnknown_0203229C->unk_72 * 32)), 24);
    gUnknown_0203229C->unk_74[a0] = 0;
}

void sub_807A000(void)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

void sub_807A024(void)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

void sub_807A048(u16 a0, u8 a1)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (!gUnknown_0203229C->unk_8D0[i].unk_0)
        {
            gUnknown_0203229C->unk_8D0[i].unk_2 = a0;
            gUnknown_0203229C->unk_8D0[i].unk_4 = a1;
            gUnknown_0203229C->unk_8D0[i].unk_0 = TRUE;
            break;
        }
    }
}

u32 sub_807A09C(void)
{
    u32 acc = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        acc += gUnknown_0203229C->unk_8D0[i].unk_0;
    }

    return acc;
}

void sub_807A0C4(void)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_0203229C->unk_8D0[i].unk_0)
        {
            if (gUnknown_0203229C->unk_8D0[i].unk_2)
            {
                gUnknown_0203229C->unk_8D0[i].unk_2--;
            }
            else
            {
                switch (gUnknown_0203229C->unk_8D0[i].unk_4)
                {
                    case 0:
                        sub_8077170(gUnknown_0203229C->unk_80, 20);
                        break;
                    case 1:
                        sub_807A19C(0);
                        break;
                    case 2:
                        sub_807A19C(2);
                        break;
                    case 3:
                    case 4:
                    case 5:
                        sub_807A19C(3);
                        break;
                    case 6:
                        sub_807A19C(6);
                        break;
                    case 7:
                        sub_807A19C(7);
                        break;
                    case 8:
                        sub_807A19C(8);
                        break;
                }
                gUnknown_0203229C->unk_8D0[i].unk_0 = 0;
            }
        }
    }
}

void sub_807A19C(u8 a0)
{
    FillWindowPixelBuffer(0, 0x11);
    AddTextPrinterParameterized(0, 1, gUnknown_0832DEBC[a0], 0, 1, TEXT_SPEED_FF, NULL);
    sub_8098858(0, 20, 12);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

bool8 sub_807A1F0(void)
{
    struct SpriteSheet sheet;

    if (gUnknown_0203229C->unk_A8 < 14)
    {
        sheet.data = gUnknown_02032188[gUnknown_0203229C->unk_A8];
        sheet.size = 0x100;
        sheet.tag = 200 + gUnknown_0203229C->unk_A8;
    }

    switch (gUnknown_0203229C->unk_A8)
    {
        case 0 ... 7:
            LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 8:
            gUnknown_0203229C->unk_72 = LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 9 ... 13:
            LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 14:
            LoadSpritePalette(&gSpritePalette_TradeScreenText);
            gUnknown_0203229C->unk_A8++;
            break;
        case 15:
            LoadSpritePalette(&gUnknown_0832DC44);
            gUnknown_0203229C->unk_A8++;
            break;
        case 16:
            LoadSpriteSheet(&gUnknown_0832DC3C);
            gUnknown_0203229C->unk_A8++;
            break;
        case 17:
            gUnknown_0203229C->unk_A8 = 0;
            return TRUE;
    }

    return FALSE;
}

void sub_807A308(const u8 *a0, u8 *a1, u8 unused)
{
    sub_80C6D80(a0, a1, 0, 0, 6);
}

void sub_807A320(u8 a0)
{
    int i;

    switch (a0)
    {
        case 0:
            for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == TRUE)
                {
                    gUnknown_0203229C->unk_45[a0][i] = 0;
                    gUnknown_0203229C->unk_51[a0][i] = 1;
                }
                else if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                {
                    gUnknown_0203229C->unk_45[a0][i] = 0;
                    gUnknown_0203229C->unk_51[a0][i] = 0;
                }
                else
                {
                    gUnknown_0203229C->unk_45[a0][i] = 1;
                    gUnknown_0203229C->unk_51[a0][i] = 0;
                }
            }
            break;
        case 1:
            for (i = 0; i < gUnknown_0203229C->unk_36[a0]; i++)
            {
                if (GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG) == TRUE)
                {
                    gUnknown_0203229C->unk_45[a0][i] = 0;
                    gUnknown_0203229C->unk_51[a0][i] = 1;
                }
                else if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
                {
                    gUnknown_0203229C->unk_45[a0][i] = 0;
                    gUnknown_0203229C->unk_51[a0][i] = 0;
                }
                else
                {
                    gUnknown_0203229C->unk_45[a0][i] = 1;
                    gUnknown_0203229C->unk_51[a0][i] = 0;
                }
            }
            break;
    }
}

void sub_807A468(u8 a0)
{
    u16 i, hp, maxHp;

    switch (a0)
    {
        case 0:
            for (i = 0; i < gUnknown_0203229C->unk_36[0]; i++)
            {
                hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
                gUnknown_0203229C->unk_5D[i] = GetHPBarLevel(hp, maxHp);
            }
            break;
        case 1:
            for (i = 0; i < gUnknown_0203229C->unk_36[1]; i++)
            {
                hp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gEnemyParty[i], MON_DATA_MAX_HP);
                gUnknown_0203229C->unk_63[i] = GetHPBarLevel(hp, maxHp);
            }
            break;
    }
}

void sub_807A53C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < gUnknown_0203229C->unk_36[i]; j++)
        {
            sub_80D32C8(&gSprites[gUnknown_0203229C->unk_28[i][j]], 4 - gUnknown_0203229C->unk_5D[i * 6 + j]);
        }
    }
}

void sub_807A5B0(void)
{
    int i;

    for (i = 0; i < 11; i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && gUnknown_0203229C->unk_A9[i] != 0)
        {
            if (gUnknown_0203229C->unk_A9[i] < 64)
            {
                gSaveBlock1Ptr->giftRibbons[i] = gUnknown_0203229C->unk_A9[i];
            }
        }
    }
}

u32 sub_807A5F4(struct Pokemon *a0, int a1, int a2)
{
    int i, sum;
    struct LinkPlayer *player;
    u32 species[6];
    u32 species2[6];

    for (i = 0; i < a1; i++)
    {
        species2[i] = GetMonData(&a0[i], MON_DATA_SPECIES2);
        species[i] = GetMonData(&a0[i], MON_DATA_SPECIES);
    }

    if (!IsNationalPokedexEnabled())
    {
        if (species2[a2] == SPECIES_EGG)
        {
            return 3;
        }

        if (!IsSpeciesInHoennDex(species2[a2]))
        {
            return 2;
        }
    }

    player = &gLinkPlayers[GetMultiplayerId() ^ 1];
    if ((player->version & 0xFF) != VERSION_RUBY &&
        (player->version & 0xFF) != VERSION_SAPPHIRE)
    {
        if ((player->name[10] & 0xF) == 0)
        {
            if (species2[a2] == SPECIES_EGG)
            {
                return 5;
            }

            if (!IsSpeciesInHoennDex(species2[a2]))
            {
                return 4;
            }
        }
    }

    if (species[a2] == SPECIES_DEOXYS || species[a2] == SPECIES_MEW)
    {
        if (!GetMonData(&a0[a2], MON_DATA_OBEDIENCE))
        {
            return 4;
        }
    }

    for (i = 0; i < a1; i++)
    {
        if (species2[i] == SPECIES_EGG)
        {
            species2[i] = SPECIES_NONE;
        }
    }

    for (sum = 0, i = 0; i < a1; i++)
    {
        if (i != a2)
        {
            sum += species2[i];
        }
    }

    if (sum != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

#ifdef NONMATCHING
s32 sub_807A728(void)
{
    s32 val;
    u16 version;

    if (gReceivedRemoteLinkPlayers != 0)
    {
        val = 0;
        version = (gLinkPlayers[GetMultiplayerId() ^ 1].version & 0xFF);

        if (version == VERSION_RUBY || version == VERSION_SAPPHIRE || version == VERSION_EMERALD)
        {
            // this value could actually be anything 0 or less
            val = 0;
        }
        else if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        {
            val = 2;
        }

        if (val > 0)
        {
            if (gLinkPlayers[GetMultiplayerId()].name[10] & 0xF0)
            {
                if (val == 2)
                {
                    if (gLinkPlayers[GetMultiplayerId() ^ 1].name[10] & 0xF0)
                    {
                        return 0;
                    }
                    else
                    {
                        return 2;
                    }
                }
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}
#else
NAKED
s32 sub_807A728(void)
{
    asm_unified("push {r4-r7,lr}\n\
    ldr r0, =gReceivedRemoteLinkPlayers\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    beq _0807A7B4\n\
    movs r4, 0\n\
    bl GetMultiplayerId\n\
    ldr r5, =gLinkPlayers\n\
    movs r7, 0x1\n\
    eors r0, r7\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1]\n\
    subs r0, r1, 0x1\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0x2\n\
    bls _0807A7B4\n\
    subs r0, r1, 0x4\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0x1\n\
    bhi _0807A762\n\
    movs r4, 0x2\n\
_0807A762:\n\
    cmp r4, 0\n\
    ble _0807A7B4\n\
    bl GetMultiplayerId\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1, 0x12]\n\
    movs r6, 0xF0\n\
    adds r0, r6, 0\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0807A7B0\n\
    cmp r4, 0x2\n\
    bne _0807A7B4\n\
    bl GetMultiplayerId\n\
    eors r0, r7\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1, 0x12]\n\
    adds r0, r6, 0\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0807A7B4\n\
    movs r0, 0x2\n\
    b _0807A7B6\n\
    .pool\n\
_0807A7B0:\n\
    movs r0, 0x1\n\
    b _0807A7B6\n\
_0807A7B4:\n\
    movs r0, 0\n\
_0807A7B6:\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1");
}
#endif // NONMATCHING

bool32 sub_807A7BC(u16 a0, u8 a1)
{
    if (a0 == SPECIES_DEOXYS || a0 == SPECIES_MEW)
    {
        if (!a1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int sub_807A7E0(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 a2, u16 a3, u8 a4, u16 a5, u8 a6)
{
    u8 r9 = a0.unk_01_0;
    u8 r2 = a0.unk_00_7;
    u8 r10 = a1.unk_01_0;
    u8 r0 = a1.unk_00_7;
    u8 r1 = a1.unk_01_2;

    if (r1 != 3)
    {
        if (!r2)
        {
            return 8;
        }
        else if (!r0)
        {
            return 9;
        }
    }

    if (sub_807A7BC(a5, a6))
    {
        return 4;
    }

    if (a3 == SPECIES_EGG)
    {
        if (a2 != a3)
        {
            return 2;
        }
    }
    else
    {
        if (gBaseStats[a2].type1 != a4 && gBaseStats[a2].type2 != a4)
        {
            return 1;
        }
    }

    if (a2 == SPECIES_EGG && a2 != a3)
    {
        return 3;
    }

    if (!r9)
    {
        if (a2 == SPECIES_EGG)
        {
            return 6;
        }
        
        if (!IsSpeciesInHoennDex(a2))
        {
            return 4;
        }

        if (!IsSpeciesInHoennDex(a3))
        {
            return 5;
        }
    }

    if (!r10 && !IsSpeciesInHoennDex(a2))
    {
        return 7;
    }

    return 0;
}
