#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "cable_club.h"
#include "data2.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
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
    u8 unk_28[6];
    u8 unk_2E[6];
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38[12];
    u8 unk_44;
    u8 filler_45[0x69 - 0x45];
    u8 unk_69;
    u8 filler_6A[0x6F - 0x6A];
    u8 unk_6F;
    u8 unk_70;
    u8 filler_71;
    u16 unk_72;
    u8 unk_74;
    u8 unk_75;
    u8 filler_76[0x7A - 0x76];
    u8 unk_7A;
    u8 unk_7B;
    u8 filler_7C[0x7E - 0x7C];
    u8 unk_7E;
    u8 filler_7F[0xA8 - 0x7F];
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
        gUnknown_0203229C->unk_74 = 0;
        gUnknown_0203229C->unk_75 = 0;
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
        gUnknown_0203229C->unk_36 = gPlayerPartyCount;
        gUnknown_0203229C->unk_37 = gEnemyPartyCount;

        for (i = 0; i < gUnknown_0203229C->unk_36; i++)
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

        for (i = 0; i < gUnknown_0203229C->unk_37; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->unk_2E[i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i + 6][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i + 6][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        sub_81B5D30();
        sub_81B5D4C(&gUnknown_0203229C->unk_36, gUnknown_0203229C->unk_28, 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->unk_36, gUnknown_0203229C->unk_28, 1);
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

        for (i = 0; i < 6; i++)
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
        gUnknown_0203229C->unk_36 = gPlayerPartyCount;
        gUnknown_0203229C->unk_37 = gEnemyPartyCount;
        ClearWindowTilemap(0);
        sub_8079BE0(0);
        sub_8079BE0(1);

        for (i = 0; i < gUnknown_0203229C->unk_36; i++)
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

        for (i = 0; i < gUnknown_0203229C->unk_37; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->unk_2E[i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         gUnknown_0832DE24[i + 6][0] * 8 + 14,
                                                         (gUnknown_0832DE24[i + 6][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        sub_81B5D30();
        sub_81B5D4C(&gUnknown_0203229C->unk_36, gUnknown_0203229C->unk_28, 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->unk_36, gUnknown_0203229C->unk_28, 1);
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

    for (i = 0; i < 6; i++)
    {
        if (i < gUnknown_0203229C->unk_36)
        {
            gSprites[gUnknown_0203229C->unk_28[i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i] = FALSE;
        }
        
        if (i < gUnknown_0203229C->unk_37)
        {
            gSprites[gUnknown_0203229C->unk_2E[i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i + 6] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i + 6] = FALSE;
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
        for (i = 0, mon = gEnemyParty; i < 6; mon++, i++)
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
