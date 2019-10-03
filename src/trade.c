#include "global.h"
#include "malloc.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "bg.h"
#include "cable_club.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "mail.h"
#include "main.h"
#include "mevent2.h"
#include "mystery_gift.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "rom_8011DC0.h"
#include "save.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "trade.h"
#include "union_room.h"
#include "util.h"
#include "window.h"
#include "constants/contest.h"
#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/species.h"
#include "constants/songs.h"

#define Trade_SendData(ptr) (SendBlock(bitmask_all_link_players_but_self(), ptr->linkData, 20))

struct InGameTrade {
    /*0x00*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0C*/ u16 species;
    /*0x0E*/ u8 ivs[NUM_STATS];
    /*0x14*/ u8 abilityNum;
    /*0x18*/ u32 otId;
    /*0x1C*/ u8 conditions[CONTEST_CATEGORIES_COUNT];
    /*0x24*/ u32 personality;
    /*0x28*/ u16 heldItem;
    /*0x2A*/ u8 mailNum;
    /*0x2B*/ u8 otName[11];
    /*0x36*/ u8 otGender;
    /*0x37*/ u8 sheen;
    /*0x38*/ u16 requestedSpecies;
};

static EWRAM_DATA u8 *gUnknown_02032184 = NULL;
static EWRAM_DATA u8 *gUnknown_02032188[14] = {NULL};
EWRAM_DATA struct MailStruct gUnknown_020321C0[PARTY_SIZE] = {0};
EWRAM_DATA u8 gSelectedTradeMonPositions[2] = {0};
static EWRAM_DATA struct {
    /*0x0000*/ u8 bg2hofs;
    /*0x0001*/ u8 bg3hofs;
    /*0x0002*/ u8 filler_2[0x28 - 2];
    /*0x0028*/ u8 partyIcons[2][PARTY_SIZE];
    /*0x0034*/ u8 cursorSpriteIdx;
    /*0x0035*/ u8 cursorPosition;
    /*0x0036*/ u8 partyCounts[2];
    /*0x0038*/ bool8 tradeMenuOptionsActive[12];
    /*0x0044*/ u8 neverRead_44;
    /*0x0045*/ bool8 isLiveMon[2][PARTY_SIZE];
    /*0x0051*/ bool8 isEgg[2][PARTY_SIZE];
    /*0x005D*/ u8 hpBarLevels[2][PARTY_SIZE];
    /*0x0069*/ u8 unk_69;
    /*0x006A*/ u8 filler_6A[0x6F - 0x6A];
    /*0x006F*/ u8 unk_6F;
    /*0x0070*/ u8 unk_70;
    /*0x0071*/ u8 filler_71;
    /*0x0072*/ u16 unk_72;
    /*0x0074*/ u8 unk_74[2]; //state var for sub_80796B4
    /*0x0076*/ u8 selectedMonIdx[2];
    /*0x0078*/ u8 unk_78;
    /*0x0079*/ u8 unk_79;
    /*0x007A*/ u8 unk_7A;
    /*0x007B*/ u8 unk_7B;
    /*0x007C*/ u8 filler_7C[0x7E - 0x7C];
    /*0x007E*/ u8 partnerCursorPosition;
    /*0x007F*/ u8 filler_7F;
    /*0x0080*/ u16 linkData[20];
    /*0x00A8*/ u8 unk_A8;
    /*0x00A9*/ u8 unk_A9[11];
    /*0x00B4*/ u8 filler_B4[0x8D0-0xB4];
    /*0x08D0*/ struct {
        bool8 unk_0;
        u16 unk_2;
        u8 monValidity;
    } unk_8D0[4];
    /*0x08F0*/ u16 tilemapBuffer[0x400];
} *sTradeMenuData = {NULL};
static EWRAM_DATA struct {
    /*0x00*/ struct Pokemon mon;
    /*0x64*/ u32 timer;
    /*0x68*/ u32 unk_68[2];
    /*0x70*/ u8 filler_70[2];
    /*0x72*/ u8 unk_72;
    /*0x73*/ u8 unk_73;
    /*0x74*/ u16 linkData[10];
    /*0x88*/ u8 unk_88;
    /*0x89*/ u8 unk_89;
    /*0x8A*/ u16 unk_8A;
    /*0x8C*/ u16 unk_8C;
    /*0x8E*/ u8 pokePicSpriteIdxs[2];
    /*0x90*/ u8 unk_90;
    /*0x91*/ u8 unk_91;
    /*0x92*/ u8 unk_92;
    /*0x93*/ u8 unk_93;
    /*0x94*/ u16 state;
    /*0x96*/ u8 filler_96[0xD2 - 0x96];
    /*0xD2*/ u8 unk_D2;
    /*0xD3*/ u8 unk_D3;
    /*0xD4*/ u16 unk_D4;
    /*0xD6*/ u16 unk_D6;
    /*0xD8*/ u16 unk_D8;
    /*0xDA*/ u16 unk_DA;
    /*0xDC*/ u16 unk_DC;
    /*0xDE*/ u16 unk_DE;
    /*0xE0*/ s16 bg1vofs;
    /*0xE2*/ s16 bg1hofs;
    /*0xE4*/ s16 bg2vofs;
    /*0xE6*/ s16 bg2hofs;
    /*0xE8*/ u16 unk_E8;
    /*0xEA*/ u16 unk_EA;
    /*0xEC*/ u16 unk_EC;
    /*0xEE*/ bool8 isLinkTrade;
    /*0xF0*/ u16 tradeSpecies[2];
    /*0xF4*/ u16 cachedMapMusic;
    /*0xF6*/ u8 textColors[3];
    /*0xF9*/ u8 filler_F9;
    /*0xFA*/ u8 unk_FA;
    /*0xFB*/ u8 unk_FB;
    /*0xFC*/ u8 unk_FC;
    /*0xFD*/ u8 unk_FD;
    /*0xFE*/ u8 unk_FE;
} *sTradeData = {NULL};

#if !defined(NONMATCHING) && MODERN
#define static
#endif
static bool32 sub_8077260(void);
static void sub_80773D0(void);
static void sub_807811C(void);
static void sub_807825C(void);
static void sub_80782B8(u8);
static void sub_8078388(void);
static bool8 shedinja_maker_maybe(void);
static void sub_8078C34(void);
static void sub_80795AC(void);
static void SetSelectedMon(u8);
static void sub_80796B4(u8);
static u8 sub_8079A3C(u8 *, u8, u8);
static void BufferTradeMonMoves(u8 *, u8, u8);
static void PrintPartyNicknamesForTradeMenu(u8);
static void sub_8079C4C(u8, u8, u8, u8, u8, u8);
static void sub_8079E44(u8);
static void sub_8079F74(void);
static void sub_8079F88(u8);
static void sub_807A000(u8 taskId);
static void sub_807A024(u8 taskId);
static void sub_807A048(u16, u8);
static u32 sub_807A09C(void);
static void sub_807A0C4(void);
static void PrintTradeMessage(u8);
static bool8 sub_807A1F0(void);
static void sub_807A308(const u8 *, u8 *, u8);
static void sub_807A320(u8);
static void GetTradePartyHPBarLevels(u8);
static void SetTradePartyHPBarSprites(void);
static void sub_807A5B0(void);
static u32 sub_807A5F4(struct Pokemon *, int, int);
static void sub_807AA28(struct Sprite *sprite);
static void sub_807AA7C(struct Sprite *sprite);
static void sub_807AABC(struct Sprite *sprite);
static void sub_807AAE0(struct Sprite *sprite);
static void sub_807AB04(struct Sprite *sprite);
static void sub_807B170(void);
static void sub_807B60C(void);
static void sub_807B62C(u8);
static void sub_807BA94(void);
static void SetTradeSceneStrings(void);
static u8 sub_807BBC8(void);
static u8 sub_807BBEC(void);
static u8 sub_807CFC8(void);
static void sub_807E55C(struct Sprite *sprite);
static void sub_807E5D8(struct Sprite *sprite);
static void sub_807E64C(struct Sprite *sprite);
static void sub_807E6AC(struct Sprite *sprite);
static void sub_807E784(void);
static void SetInGameTradeMail(struct MailStruct *mail, const struct InGameTrade *trade);
static void sub_807EA2C(void);
static void sub_807EACC(void);
static void sub_807EB50(void);
static void c2_080543C4(void);
static void sub_807F110(u8);
static void CheckPartnersMonForRibbons(void);
static void c3_08054588(u8);
static void c3_0805465C(u8);
static void sub_807F39C(u8);
static void sub_807F464(void);

#include "data/trade.h"

static bool8 SendLinkData(const void *linkData, u32 size)
{
    if (gUnknown_02022C2C == 29)
    {
        rfu_NI_setSendData(gUnknown_03004140.unk_00, 84, linkData, size);
        return TRUE;
    }
    else
    {
        return SendBlock(0, linkData, size);
    }
}

static void sub_80771AC(u8 a0)
{
    sub_800A4D8(a0);
}

static bool32 sub_80771BC(void)
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
        return IsLinkTaskFinished();
    }
}

static u32 _GetBlockReceivedStatus(void)
{
    return GetBlockReceivedStatus();
}

static void sub_8077210(void)
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

static void sub_8077234(u32 a0)
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

static bool32 sub_8077260(void)
{
    if (gWirelessCommType && gUnknown_02022C2C == 29)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void sub_8077288(u8 unused)
{
    sub_800ADF8();
}

static bool32 _IsLinkTaskFinished(void)
{
    return IsLinkTaskFinished();
}

static void sub_80772A4(void)
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
    SetBgTilemapBuffer(1, sTradeMenuData->tilemapBuffer);

    if (InitWindows(gUnknown_0832DEF4))
    {
        u32 i;

        DeactivateAllTextPrinters();

        for (i = 0; i < 18; i++)
        {
            ClearWindowTilemap(i);
            FillWindowPixelBuffer(i, PIXEL_FILL(0));
        }

        FillBgTilemapBufferRect(0, 0, 0, 0, 30, 20, 15);
        LoadUserWindowBorderGfx_(0, 20, 0xC0);
        LoadUserWindowBorderGfx(2, 1, 0xE0);
        LoadMonIconPalettes();
        sTradeMenuData->unk_69 = 0;
        sTradeMenuData->unk_6F = 0;
        sTradeMenuData->unk_70 = 0;
        sTradeMenuData->unk_74[TRADE_PLAYER] = 0;
        sTradeMenuData->unk_74[TRADE_PARTNER] = 0;
        sTradeMenuData->unk_7A = 0;
        sTradeMenuData->unk_7B = 0;
        sTradeMenuData->unk_A8 = 0;
    }
}

void sub_80773AC(void)
{
    SetMainCallback2(sub_80773D0);
    gMain.callback1 = NULL;
    gEnemyPartyCount = 0;
}

static void sub_80773D0(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        sTradeMenuData = AllocZeroed(sizeof(*sTradeMenuData));
        sub_80772A4();
        gUnknown_02032184 = AllocZeroed(14 * 256);

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
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, 0x20, FALSE, 0, OT_ID_PLAYER_ID, 0);
        }

        PrintTradeMessage(TRADE_MSG_STANDBY);
        ShowBg(0);

        if (!gReceivedRemoteLinkPlayers)
        {
            gLinkType = 0x1122;
            sTradeMenuData->unk_A8 = 0;

            if (gWirelessCommType)
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
        sTradeMenuData->unk_A8++;
        if (sTradeMenuData->unk_A8 > 11)
        {
            sTradeMenuData->unk_A8 = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
        {
            if (IsLinkMaster())
            {
                if (++sTradeMenuData->unk_A8 > 30)
                {
                    CheckShouldAdvanceLinkState();
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
        if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
        {
            sub_8011BD0();
            CalculatePlayerPartyCount();
            gMain.state++;
            sTradeMenuData->unk_A8 = 0;
            if (gWirelessCommType)
            {
                sub_801048C(TRUE);
                sub_800ADF8();
            }
        }
        break;
    case 5:
        if (gWirelessCommType)
        {
            if (sub_8010500())
            {
                gMain.state++;
                LoadWirelessStatusIndicatorSpriteGfx();
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
        sTradeMenuData->partyCounts[TRADE_PLAYER] = gPlayerPartyCount;
        sTradeMenuData->partyCounts[TRADE_PARTNER] = gEnemyPartyCount;

        for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PLAYER]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            sTradeMenuData->partyIcons[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeMenuData->partyIcons[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        sub_81B5D4C(&sTradeMenuData->partyCounts[TRADE_PLAYER], sTradeMenuData->partyIcons[TRADE_PLAYER], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&sTradeMenuData->partyCounts[TRADE_PLAYER], sTradeMenuData->partyIcons[TRADE_PLAYER], 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(sTradeActionTexts[TRADE_ACTION_TEXT_CANCEL], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], gUnknown_02032188[8], 24);
        gMain.state++;
        sTradeMenuData->unk_A8 = 0;
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

        sTradeMenuData->cursorSpriteIdx = CreateSprite(&gSpriteTemplate_832DC94, gTradeMonSpriteCoords[0][0] * 8 + 32, gTradeMonSpriteCoords[0][1] * 8, 2);
        sTradeMenuData->cursorPosition = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        sub_807A320(TRADE_PLAYER);
        PrintPartyNicknamesForTradeMenu(TRADE_PLAYER);
        sTradeMenuData->bg2hofs = 0;
        sTradeMenuData->bg3hofs = 0;
        sub_8078388();
        gMain.state++;
        PlayBGM(MUS_P_SCHOOL);
        break;
    case 15:
        sub_807A320(TRADE_PARTNER);
        PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);
        gMain.state++;
        // fallthrough
    case 16:
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
        GetTradePartyHPBarLevels(TRADE_PLAYER);
        gMain.state++;
        break;
    case 21:
        GetTradePartyHPBarLevels(TRADE_PARTNER);
        SetTradePartyHPBarSprites();
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

static void sub_8077B74(void)
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
        sTradeMenuData->unk_A8 = 0;
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
        if (gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        gMain.state++;
        break;
    case 6:
        gMain.state++;
        break;
    case 7:
        CalculateEnemyPartyCount();
        sTradeMenuData->partyCounts[TRADE_PLAYER] = gPlayerPartyCount;
        sTradeMenuData->partyCounts[TRADE_PARTNER] = gEnemyPartyCount;
        ClearWindowTilemap(0);
        PrintPartyNicknamesForTradeMenu(TRADE_PLAYER);
        PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);

        for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PLAYER]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            sTradeMenuData->partyIcons[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeMenuData->partyIcons[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        sub_81B5D4C(&sTradeMenuData->partyCounts[TRADE_PLAYER], sTradeMenuData->partyIcons[TRADE_PLAYER], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&sTradeMenuData->partyCounts[TRADE_PLAYER], sTradeMenuData->partyIcons[TRADE_PLAYER], 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(sTradeActionTexts[TRADE_ACTION_TEXT_CANCEL], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], gUnknown_02032188[8], 24);
        gMain.state++;
        sTradeMenuData->unk_A8 = 0;
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

        if (sTradeMenuData->cursorPosition < PARTY_SIZE)
            sTradeMenuData->cursorPosition = gLastViewedMonIndex;
        else
            sTradeMenuData->cursorPosition = gLastViewedMonIndex + PARTY_SIZE;

        sTradeMenuData->cursorSpriteIdx = CreateSprite(&gSpriteTemplate_832DC94, gTradeMonSpriteCoords[sTradeMenuData->cursorPosition][0] * 8 + 32, gTradeMonSpriteCoords[sTradeMenuData->cursorPosition][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        sTradeMenuData->bg2hofs = 0;
        sTradeMenuData->bg3hofs = 0;
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
        SetTradePartyHPBarSprites();
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

static void sub_807811C(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_8078130(void)
{
    if (++sTradeMenuData->unk_A8 > 15)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sTradeMenuData->unk_6F = 10;
    }
}

static void sub_807816C(void)
{
    if (!gPaletteFade.active)
    {
        gSelectedTradeMonPositions[TRADE_PLAYER] = sTradeMenuData->cursorPosition;
        gSelectedTradeMonPositions[TRADE_PARTNER] = sTradeMenuData->partnerCursorPosition;

        if (gWirelessCommType)
        {
            sTradeMenuData->unk_6F = 16;
        }
        else
        {
            sub_800ABF4(32);
            sTradeMenuData->unk_6F = 13;
        }
    }
}

static void sub_80781C8(void)
{
    gMain.savedCallback = sub_80773AC;

    if (gWirelessCommType)
    {
        if (sub_8010500())
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(sTradeMenuData);
            gMain.callback1 = NULL;
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(sub_807AE50);
        }
    }
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(sTradeMenuData);
            gMain.callback1 = NULL;
            SetMainCallback2(sub_807AE50);
        }
    }
}

static void sub_807825C(void)
{
    u8 temp;

    sub_80795AC();
    sub_807A0C4();
    sub_80796B4(TRADE_PLAYER);
    sub_80796B4(TRADE_PARTNER);

    SetGpuReg(REG_OFFSET_BG2HOFS, sTradeMenuData->bg2hofs++);
    SetGpuReg(REG_OFFSET_BG3HOFS, sTradeMenuData->bg3hofs--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_80782B8(u8 a0)
{
    int i;

    switch (a0)
    {
    case 0:
        LoadPalette(gTradeMenu_Pal, 0, 0x60);
        LoadBgTiles(1, gTradeMenu_Gfx, 0x1280, 0);
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDCF04, 0, 0, 32, 20, 0);
        LoadBgTilemap(2, gTradeStripesBG2Tilemap, 0x800, 0);
        break;
    case 1:
        LoadBgTilemap(3, gTradeStripesBG3Tilemap, 0x800, 0);
        sub_8079E44(TRADE_PLAYER);
        sub_8079E44(TRADE_PARTNER);
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

static void sub_8078388(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i < sTradeMenuData->partyCounts[TRADE_PLAYER])
        {
            gSprites[sTradeMenuData->partyIcons[TRADE_PLAYER][i]].invisible = FALSE;
            sTradeMenuData->tradeMenuOptionsActive[i] = TRUE;
        }
        else
        {
            sTradeMenuData->tradeMenuOptionsActive[i] = FALSE;
        }

        if (i < sTradeMenuData->partyCounts[TRADE_PARTNER])
        {
            gSprites[sTradeMenuData->partyIcons[TRADE_PARTNER][i]].invisible = FALSE;
            sTradeMenuData->tradeMenuOptionsActive[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            sTradeMenuData->tradeMenuOptionsActive[i + PARTY_SIZE] = FALSE;
        }
    }

    sTradeMenuData->neverRead_44 = 1;
}

// why not just use memcpy?
static void Trade_Memcpy(void *dataDest, const void *dataSrc, u32 count)
{
    u8 *dest = dataDest;
    const u8 *src = dataSrc;
    u32 i;

    for (i = 0; i < count; i++)
    {
        dest[i] = src[i];
    }
}

static bool8 shedinja_maker_maybe(void)
{
    u8 id = GetMultiplayerId();
    int i;
    struct Pokemon *mon;

    switch (sTradeMenuData->unk_69)
    {
    case 0:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[0], 2 * sizeof(struct Pokemon));
        sTradeMenuData->unk_69++;
        sTradeMenuData->unk_A8 = 0;
        break;
    case 1:
        if (sub_80771BC())
        {
            if (_GetBlockReceivedStatus() == 0)
            {
                sTradeMenuData->unk_69++;
            }
            else
            {
                sub_8077210();
                sTradeMenuData->unk_69++;
            }
        }
        break;
    case 3:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        sTradeMenuData->unk_69++;
        break;
    case 4:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[0], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            sub_8077210();
            sTradeMenuData->unk_69++;
        }
        break;
    case 5:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[2], 2 * sizeof(struct Pokemon));
        sTradeMenuData->unk_69++;
        break;
    case 7:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        sTradeMenuData->unk_69++;
        break;
    case 8:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[2], gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            sTradeMenuData->unk_69++;
        }
        break;
    case 9:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[4], 200);
        sTradeMenuData->unk_69++;
        break;
    case 11:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        sTradeMenuData->unk_69++;
        break;
    case 12:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[4], gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            sTradeMenuData->unk_69++;
        }
        break;
    case 13:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->mail, 220);
        sTradeMenuData->unk_69++;
        break;
    case 15:
        if (id == 0)
        {
            sub_80771AC(3);
        }
        sTradeMenuData->unk_69++;
        break;
    case 16:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(gUnknown_020321C0, gBlockRecvBuffer[id ^ 1], 216);
            sub_8077210();
            sTradeMenuData->unk_69++;
        }
        break;
    case 17:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, 11);
        sTradeMenuData->unk_69++;
        break;
    case 19:
        if (id == 0)
        {
            sub_80771AC(4);
        }
        sTradeMenuData->unk_69++;
        break;
    case 20:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(sTradeMenuData->unk_A9, gBlockRecvBuffer[id ^ 1], 11);
            sub_8077210();
            sTradeMenuData->unk_69++;
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

                    if (!StringCompareWithoutExtCtrlCodes(name, sJPText_Shedinja))
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
        sTradeMenuData->unk_A8++;
        if (sTradeMenuData->unk_A8 > 10)
        {
            sTradeMenuData->unk_A8 = 0;
            sTradeMenuData->unk_69++;
        }
        break;
    }
    return FALSE;
}

static void sub_80787B8(void)
{
    sub_807A308(gText_IsThisTradeOkay, (void *)(OBJ_VRAM0 + (sTradeMenuData->unk_72 * 32)), 24);
}

static void sub_80787E0(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEAA:
            sTradeMenuData->unk_78 = 2;
            break;
        case 0xAABB:
            sTradeMenuData->unk_78 = 1;
            break;
        case 0xBBBB:
            sTradeMenuData->unk_7A = 1;
            break;
        case 0xBBCC:
            sTradeMenuData->unk_7A = 2;
            break;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case 0xEEAA:
            sTradeMenuData->unk_79 = 2;
            break;
        case 0xAABB:
            sTradeMenuData->partnerCursorPosition = gBlockRecvBuffer[1][1] + 6;
            sTradeMenuData->unk_79 = 1;
            break;
        case 0xBBBB:
            sTradeMenuData->unk_7B = 1;
            break;
        case 0xBBCC:
            sTradeMenuData->unk_7B = 2;
            break;
        }
        sub_8077234(1);
    }
}

static void sub_8078900(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEBB:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            PrintTradeMessage(TRADE_MSG_WAITING_FOR_FRIEND);
            sTradeMenuData->unk_6F = 11;
            break;
        case 0xEECC:
            PrintTradeMessage(TRADE_MSG_FRIEND_WANTS_TO_TRADE);
            sTradeMenuData->unk_6F = 8;
            break;
        case 0xDDDD:
            sTradeMenuData->partnerCursorPosition = gBlockRecvBuffer[0][1] + 6;
            rbox_fill_rectangle(0);
            SetSelectedMon(sTradeMenuData->cursorPosition);
            SetSelectedMon(sTradeMenuData->partnerCursorPosition);
            sTradeMenuData->unk_6F = 7;
            break;
        case 0xCCDD:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->unk_6F = 10;
            break;
        case 0xDDEE:
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeMenuData->unk_6F = 8;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
        sub_8077234(1);
}

static void sub_80789FC(void)
{
    if (sTradeMenuData->unk_78 && sTradeMenuData->unk_79)
    {
        if (sTradeMenuData->unk_78 == 1 && sTradeMenuData->unk_79 == 1)
        {
            sTradeMenuData->unk_6F = 6;
            sTradeMenuData->linkData[0] = 0xDDDD;
            sTradeMenuData->linkData[1] = sTradeMenuData->cursorPosition;
            sub_807A048(5, 0);
            sTradeMenuData->unk_78 = sTradeMenuData->unk_79 = 0;
        }
        else if (sTradeMenuData->unk_78 == 1 && sTradeMenuData->unk_79 == 2)
        {
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeMenuData->linkData[0] = 0xEECC;
            sTradeMenuData->linkData[1] = 0;
            sub_807A048(5, 0);
            sTradeMenuData->unk_7A = sTradeMenuData->unk_7B = 0;
            sTradeMenuData->unk_78 = sTradeMenuData->unk_79 = 0;
            sTradeMenuData->unk_6F = 8;
        }
        else if (sTradeMenuData->unk_78 == 2 && sTradeMenuData->unk_79 == 1)
        {
            PrintTradeMessage(TRADE_MSG_FRIEND_WANTS_TO_TRADE);
            sTradeMenuData->linkData[0] = 0xDDEE;
            sTradeMenuData->linkData[1] = 0;
            sub_807A048(5, 0);
            sTradeMenuData->unk_7A = sTradeMenuData->unk_7B = 0;
            sTradeMenuData->unk_78 = sTradeMenuData->unk_79 = 0;
            sTradeMenuData->unk_6F = 8;
        }
        else if (sTradeMenuData->unk_78 == 2 && sTradeMenuData->unk_79 == 2)
        {
            sTradeMenuData->linkData[0] = 0xEEBB;
            sTradeMenuData->linkData[1] = 0;
            sub_807A048(5, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->unk_78 = sTradeMenuData->unk_79 = 0;
            sTradeMenuData->unk_6F = 11;
        }
    }

    if (sTradeMenuData->unk_7A && sTradeMenuData->unk_7B)
    {
        if (sTradeMenuData->unk_7A == 1 && sTradeMenuData->unk_7B == 1)
        {
            sTradeMenuData->linkData[0] = 0xCCDD;
            sTradeMenuData->linkData[1] = 0;
            sub_807A048(5, 0);
            sTradeMenuData->unk_7A = 0;
            sTradeMenuData->unk_7B = 0;
            sTradeMenuData->unk_6F = 9;
        }

        if (sTradeMenuData->unk_7A == 2 || sTradeMenuData->unk_7B == 2)
        {
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeMenuData->linkData[0] = 0xDDEE;
            sTradeMenuData->linkData[1] = 0;
            sub_807A048(5, 0);
            sTradeMenuData->unk_7A = 0;
            sTradeMenuData->unk_7B = 0;
            sTradeMenuData->unk_6F = 8;
        }
    }
}

static void sub_8078BFC(u16 *linkData, u16 linkFlag, u16 cursorPosition)
{
    linkData[0] = linkFlag;
    linkData[1] = cursorPosition;
    sub_807A048(5, 0);
}

static void SetLinkData(u16 linkFlag, u16 cursorPosition)
{
    sub_8078BFC(sTradeMenuData->linkData, linkFlag, cursorPosition);
}

static void sub_8078C34(void)
{
    u8 mpId = GetMultiplayerId();
    u8 status;

    if ((status = _GetBlockReceivedStatus()))
    {
        if (mpId == 0)
            sub_80787E0(mpId, status);
        else
            sub_8078900(mpId, status);
    }

    if (mpId == 0)
        sub_80789FC();
}

static u8 sub_8078C6C(u8 oldPosition, u8 direction)
{
    int i;
    u8 newPosition = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sTradeMenuData->tradeMenuOptionsActive[gTradeNextSelectedMonTable[oldPosition][direction][i]] == TRUE)
        {
            newPosition = gTradeNextSelectedMonTable[oldPosition][direction][i];
            break;
        }
    }

    return newPosition;
}

static void TradeMenuMoveCursor(u8 *cursorPosition, u8 direction)
{
    u8 newPosition = sub_8078C6C(*cursorPosition, direction);

    if (newPosition == 12) // CANCEL
    {
        StartSpriteAnim(&gSprites[sTradeMenuData->cursorSpriteIdx], 1);
        gSprites[sTradeMenuData->cursorSpriteIdx].pos1.x = 224;
        gSprites[sTradeMenuData->cursorSpriteIdx].pos1.y = 160;
    }
    else
    {
        StartSpriteAnim(&gSprites[sTradeMenuData->cursorSpriteIdx], 0);
        gSprites[sTradeMenuData->cursorSpriteIdx].pos1.x = gTradeMonSpriteCoords[newPosition][0] * 8 + 32;
        gSprites[sTradeMenuData->cursorSpriteIdx].pos1.y = gTradeMonSpriteCoords[newPosition][1] * 8;
    }

    if (*cursorPosition != newPosition)
    {
        PlaySE(SE_SELECT);
    }

    *cursorPosition = newPosition;
}

static void sub_8078D78(void)
{
    PrintTradeMessage(TRADE_MSG_STANDBY);
    sTradeMenuData->unk_6F = 100;

    if (GetMultiplayerId() == 1)
    {
        SetLinkData(0xAABB, sTradeMenuData->cursorPosition);
    }
    else
    {
        sTradeMenuData->unk_78 = 1;
    }
}

static void sub_8078DBC(void)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 0);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 1);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 2);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 3);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        // Cursor is in player's party
        if (sTradeMenuData->cursorPosition < PARTY_SIZE)
        {
            DrawTextBorderOuter(1, 1, 14);
            FillWindowPixelBuffer(1, PIXEL_FILL(1));
            PrintMenuTable(1, ARRAY_COUNT(sSelectTradeMonActions), sSelectTradeMonActions);
            InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
            PutWindowTilemap(1);
            CopyWindowToVram(1, 3);
            sTradeMenuData->unk_6F = 1;
        }
        // Cursor is in partner's party
        else if (sTradeMenuData->cursorPosition < PARTY_SIZE * 2)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->unk_6F = 2;
        }
        // Cursor is on Cancel
        else if (sTradeMenuData->cursorPosition == PARTY_SIZE * 2)
        {
            CreateYesNoMenu(&sTradeYesNoWindowTemplate, 1, 14, 0);
            sTradeMenuData->unk_6F = 4;
            sub_807A308(sTradeActionTexts[TRADE_ACTION_TEXT_CANCEL_TRADE], (void *)(OBJ_VRAM0 + sTradeMenuData->unk_72 * 32), 24);
        }
    }
}

static void sub_8078EF8(void)
{
    sub_8079F74();
    sTradeMenuData->unk_6F = 0;
    gSprites[sTradeMenuData->cursorSpriteIdx].invisible = FALSE;
    sub_807A308(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + sTradeMenuData->unk_72 * 32), 24);
}

static void TradeMenuProcessInput_SelectedMon(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_ACTION_SUMMARY:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->unk_6F = 2;
            break;
        case MENU_ACTION_TRADE:
            switch (sub_807A5F4(gPlayerParty, gPlayerPartyCount, sTradeMenuData->cursorPosition))
            {
                case 0:
                    sub_8078D78();
                    gSprites[sTradeMenuData->cursorSpriteIdx].invisible = TRUE;
                    break;
                case 1:
                    sub_807A048(3, 3);
                    sTradeMenuData->unk_6F = 8;
                    break;
                case 2:
                case 4:
                    sub_807A048(3, 6);
                    sTradeMenuData->unk_6F = 8;
                    break;
                case 3:
                case 5:
                    sub_807A048(3, 7);
                    sTradeMenuData->unk_6F = 8;
                    break;
            }
            break;
    }
}

static void sub_8079034(void)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_8078EF8();
    }
}

static void sub_807905C(void)
{
    if (!gPaletteFade.active)
    {
        if (sTradeMenuData->cursorPosition < PARTY_SIZE)
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, sTradeMenuData->cursorPosition, sTradeMenuData->partyCounts[TRADE_PLAYER] - 1, sub_8077B74);
        }
        else
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gEnemyParty, sTradeMenuData->cursorPosition - PARTY_SIZE, sTradeMenuData->partyCounts[TRADE_PARTNER] - 1, sub_8077B74);
        }
        FreeAllWindowBuffers();
    }
}

static u8 CheckValidityOfTradeMons(u8 *aliveMons, u8 playerPartyCount, u8 playerMonIdx, u8 partnerMonIdx)
{
    int i;
    u16 species;
    u8 hasLiveMon = 0;

    // Make sure mon to be traded isn't player's last alive mon
    for (i = 0; i < playerPartyCount; i++)
    {
        if (playerMonIdx != i)
        {
            hasLiveMon += aliveMons[i];
        }
    }
    partnerMonIdx %= PARTY_SIZE;
    species = GetMonData(&gEnemyParty[partnerMonIdx], MON_DATA_SPECIES);

    // Partner cant trade illegitimate Deoxys or Mew
    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!GetMonData(&gEnemyParty[partnerMonIdx], MON_DATA_OBEDIENCE))
        {
            return PARTNER_MON_INVALID;
        }
    }

    // Partner cant trade Egg or non-Hoenn mon if player doesn't have National Dex
    if (!IsNationalPokedexEnabled())
    {
        if (sTradeMenuData->isEgg[TRADE_PARTNER][partnerMonIdx] || !IsSpeciesInHoennDex(species))
        {
            return PARTNER_MON_INVALID;
        }
    }

    if (hasLiveMon)
    {
        hasLiveMon = PLAYER_MON_VALID;
    }

    return hasLiveMon; //PLAYER_MON_INVALID or PLAYER_MON_VALID 
}

static bool32 sub_8079174(void)
{
    int i;
    u8 aliveMons[PARTY_SIZE * 2];

    for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PLAYER]; i++)
    {
        aliveMons[i] = sTradeMenuData->isLiveMon[TRADE_PLAYER][i];
    }

    switch (CheckValidityOfTradeMons(aliveMons, sTradeMenuData->partyCounts[TRADE_PLAYER], sTradeMenuData->cursorPosition, sTradeMenuData->partnerCursorPosition))
    {
        case PLAYER_MON_INVALID:
            sub_807A048(3, 3);
            SetLinkData(0xBBCC, 0);
            break;
        case PLAYER_MON_VALID:
            sub_807A048(3, 1);
            SetLinkData(0xBBBB, 0);
            break;
        case PARTNER_MON_INVALID:
            sub_807A048(3, 8);
            return TRUE;
    }

    return FALSE;
}

static void sub_8079218(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            if (!sub_8079174())
            {
                sTradeMenuData->unk_6F = 100;
            }
            else
            {
                sTradeMenuData->unk_6F = 17;
            }
            PutWindowTilemap(17);
            break;
        case 1:
        case MENU_B_PRESSED:
            sub_807A048(3, 1);
            if (sub_80771BC())
                SetLinkData(0xBBCC, 0);
            sTradeMenuData->unk_6F = 100;
            PutWindowTilemap(17);
            break;
    }
}

static void sub_807929C(void)
{
    int i;

    for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PARTNER] - 4; i++)
    {
        PutWindowTilemap(i + 12);
        CopyWindowToVram(i + 12, 1);
    }
}

static void sub_80792E4(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            PrintTradeMessage(TRADE_MSG_WAITING_FOR_FRIEND);
            SetLinkData(0xEEAA, 0);
            gSprites[sTradeMenuData->cursorSpriteIdx].invisible = TRUE;
            sTradeMenuData->unk_6F = 100;
            sub_807929C();
            break;
        case 1:
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
    }
}

static void sub_807935C(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        SetSelectedMon(sTradeMenuData->cursorPosition);
        SetSelectedMon(sTradeMenuData->partnerCursorPosition);
    }
    sTradeMenuData->unk_6F = 7;
}

static void sub_8079398(void)
{
    if (sTradeMenuData->unk_74[TRADE_PLAYER] == 5 
        && sTradeMenuData->unk_74[TRADE_PARTNER] == 5)
    {
        sub_80787B8();
        sTradeMenuData->unk_6F = 14;
    }
}

static void Wait2SecondsAndCreateYesNoMenu(void)
{
    sTradeMenuData->unk_A8++;

    if (sTradeMenuData->unk_A8 > 120)
    {
        CreateYesNoMenu(&sTradeYesNoWindowTemplate, 1, 14, 0);
        sTradeMenuData->unk_A8 = 0;
        sTradeMenuData->unk_6F = 3;
    }
}

static void sub_8079408(void)
{
    int i;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(0);
        rbox_fill_rectangle(1);

        for (i = 0; i < 4; i++)
        {
            FillWindowPixelBuffer(i + 14, PIXEL_FILL(0));
            rbox_fill_rectangle(i + 14);
        }

        sub_8079F88(TRADE_PLAYER);
        sub_8079F88(TRADE_PARTNER);
        sTradeMenuData->unk_6F = 0;
        gSprites[sTradeMenuData->cursorSpriteIdx].invisible = FALSE;
    }
}

static void sub_8079490(void)
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

        sTradeMenuData->unk_6F = 12;
    }
}

static void sub_80794CC(void)
{
    if (gWirelessCommType)
    {
        if (sub_80771BC() && sub_807A09C() == 0)
        {
            Free(gUnknown_02032184);
            Free(sTradeMenuData);
            FreeAllWindowBuffers();
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(gUnknown_02032184);
            Free(sTradeMenuData);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
}

static void sub_8079550(void)
{
    if (!sub_801048C(FALSE) && sub_807A09C() == 0)
    {
        sub_800ADF8();
        sTradeMenuData->unk_6F = 13;
    }
}

static void sub_807957C(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        SetLinkData(0xBBCC, 0);
        sTradeMenuData->unk_6F = 100;
    }
}

//TODO:
static void sub_80795AC(void)
{
    switch (sTradeMenuData->unk_6F)
    {
        case 0:
            sub_8078DBC();
            break;
        case 1:
            TradeMenuProcessInput_SelectedMon();
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
            Wait2SecondsAndCreateYesNoMenu();
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

static void SetSelectedMon(u8 cursorPosition)
{
    //cursorPosition 0-5 are the player's mons, 6-11 are the partner's
    u8 whichParty = cursorPosition / PARTY_SIZE;

    if (sTradeMenuData->unk_74[whichParty] == 0)
    {
        sTradeMenuData->unk_74[whichParty] = 1;
        sTradeMenuData->selectedMonIdx[whichParty] = cursorPosition;
    }
}

static void sub_80796B4(u8 a0)
{
    s8 nameStringWidth;
    u8 nickname[20];
    u8 movesString[56];
    u8 i;
    u8 partyIdx;
    u8 whichParty;
    u8 selectedMonIdx = sTradeMenuData->selectedMonIdx[a0];

    whichParty = TRADE_PARTNER;
    if (sTradeMenuData->selectedMonIdx[a0] < PARTY_SIZE)
        whichParty = TRADE_PLAYER;
    partyIdx = selectedMonIdx % PARTY_SIZE;
    nameStringWidth = 0;

    switch (sTradeMenuData->unk_74[a0])
    {
    case 1:
        for (i = 0; i < sTradeMenuData->partyCounts[a0]; i++)
        {
            gSprites[sTradeMenuData->partyIcons[TRADE_PLAYER][i + (whichParty * PARTY_SIZE)]].invisible = TRUE;
        }

        for (i = 0; i < 6; i++)
        {
            ClearWindowTilemap(i + (a0 * PARTY_SIZE + 2));
        }

        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].invisible = FALSE;
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].data[0] = 20;
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].data[2] = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][0] + gTradeMonSpriteCoords[whichParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].data[4] = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][1] * 8) - 12;
        StoreSpriteCallbackInData6(&gSprites[sTradeMenuData->partyIcons[TRADE_PLAYER][partyIdx + (whichParty * PARTY_SIZE)]], sub_80D3014);
        sTradeMenuData->unk_74[a0]++;
        sub_80A6DEC(&gSprites[sTradeMenuData->partyIcons[TRADE_PLAYER][partyIdx + (whichParty * PARTY_SIZE)]]);
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);

        if (whichParty == TRADE_PLAYER)
            sub_8079F74();
        break;
    case 2:
        if (gSprites[sTradeMenuData->partyIcons[TRADE_PLAYER][partyIdx + (whichParty * PARTY_SIZE)]].callback == sub_80D3014)
            sTradeMenuData->unk_74[a0] = 3;
        break;
    case 3:
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMovesBoxTilemap, whichParty * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos1.x = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][0] + gTradeMonSpriteCoords[whichParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos1.y = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][1] * 8) - 12;
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos2.x = 0;
        gSprites[sTradeMenuData->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos2.y = 0;
        nameStringWidth = sub_8079A3C(nickname, whichParty, partyIdx);
        AddTextPrinterParameterized3((a0 * 2) + 14, 0, (80 - nameStringWidth) / 2, 4, sTradeTextColors, 0, nickname);
        BufferTradeMonMoves(movesString, whichParty, partyIdx);
        AddTextPrinterParameterized4((a0 * 2) + 15, 1, 0, 0, 0, 0, sTradeTextColors, 0, movesString);
        PutWindowTilemap((a0 * 2) + 14);
        CopyWindowToVram((a0 * 2) + 14, 3);
        PutWindowTilemap((a0 * 2) + 15);
        CopyWindowToVram((a0 * 2) + 15, 3);
        sTradeMenuData->unk_74[a0]++;
        break;
    case 4:
        sub_8079C4C(a0, partyIdx, gUnknown_0832DF99[a0][0] + 4, gUnknown_0832DF99[a0][1] + 1, gUnknown_0832DF99[a0][0], gUnknown_0832DF99[a0][1]);
        sTradeMenuData->unk_74[a0]++;
        break;
    }
}

static u8 sub_8079A3C(u8 *str, u8 whichParty, u8 monIdx)
{
    u8 nickname[12];

    if (whichParty == 0)
        GetMonData(&gPlayerParty[monIdx], MON_DATA_NICKNAME, nickname);
    else
        GetMonData(&gEnemyParty[monIdx], MON_DATA_NICKNAME, nickname);

    StringCopy10(str, nickname);
    return GetStringWidth(0, str, GetFontAttribute(0, FONTATTR_LETTER_SPACING));
}

static void BufferTradeMonMoves(u8 *str, u8 whichParty, u8 partyIdx)
{
    u16 moves[MAX_MON_MOVES];
    u16 i;

    if (!sTradeMenuData->isEgg[whichParty][partyIdx])
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (whichParty == TRADE_PLAYER)
            {
                moves[i] = GetMonData(&gPlayerParty[partyIdx], i + MON_DATA_MOVE1, NULL);
            }
            else
            {
                moves[i] = GetMonData(&gEnemyParty[partyIdx], i + MON_DATA_MOVE1, NULL);
            }
        }

        StringCopy(str, gText_EmptyString7);

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (moves[i] != MOVE_NONE)
            {
                StringAppend(str, gMoveNames[moves[i]]);
            }

            StringAppend(str, gText_NewLine3);
        }
    }
    else
    {
        StringCopy(str, gText_EmptyString7);
        StringAppend(str, gText_FourQuestionMarks);
    }
}

static void PrintMonNicknameForTradeMenu(u8 whichParty, u8 windowId, u8 *nickname)
{
    u8 xPos;
    windowId += (whichParty * PARTY_SIZE) + 2;
    xPos = GetStringCenterAlignXOffset(0, nickname, 64);
    AddTextPrinterParameterized3(windowId, 0, xPos, 4, sTradeTextColors, 0, nickname);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void PrintPartyNicknamesForTradeMenu(u8 whichParty)
{
    u8 i;
    u8 nickname[20];
    u8 str[32];
    struct Pokemon *party = (whichParty == TRADE_PLAYER) ? gPlayerParty : gEnemyParty;

    for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
    {
        GetMonData(&party[i], MON_DATA_NICKNAME, nickname);
        StringCopy10(str, nickname);
        PrintMonNicknameForTradeMenu(whichParty, i, str);
    }
}

static void sub_8079C4C(u8 whichParty, u8 monIdx, u8 x, u8 y, u8 width, u8 height)
{
    u8 level;
    u32 r2;
    u8 gender;
    u8 nickname[12];

    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDD704, width, height, 6, 3, 0);
    CopyBgTilemapBufferToVram(1);

    if (whichParty == TRADE_PLAYER)
        level = GetMonData(&gPlayerParty[monIdx], MON_DATA_LEVEL, NULL);
    else
        level = GetMonData(&gEnemyParty[monIdx], MON_DATA_LEVEL, NULL);

    if (!sTradeMenuData->isEgg[whichParty][monIdx])
    {
        if (level / 10 != 0)
            sTradeMenuData->tilemapBuffer[x + (y * 32)] = (level / 10) + 0x60;

        sTradeMenuData->tilemapBuffer[x + (y * 32) + 1] = (level % 10) + 0x70;
    }
    else
    {
        sTradeMenuData->tilemapBuffer[x + (y * 32) - 32] = sTradeMenuData->tilemapBuffer[x + (y * 32) - 33];
        sTradeMenuData->tilemapBuffer[x + (y * 32) - 31] = sTradeMenuData->tilemapBuffer[x + (y * 32) - 36] | 0x400;
    }

    if (sTradeMenuData->isEgg[whichParty][monIdx])
    {
        r2 = 0x480;
    }
    else
    {
        if (whichParty == TRADE_PLAYER)
        {
            gender = GetMonGender(&gPlayerParty[monIdx]);
            GetMonData(&gPlayerParty[monIdx], MON_DATA_NICKNAME, nickname);
        }
        else
        {
            gender = GetMonGender(&gEnemyParty[monIdx]);
            GetMonData(&gEnemyParty[monIdx], MON_DATA_NICKNAME, nickname);
        }

        switch (gender)
        {
            case MON_MALE:
                r2 = !NameHasGenderSymbol(nickname, MON_MALE) ? 0x84 : 0x83;
                break;
            case MON_FEMALE:
                r2 = !NameHasGenderSymbol(nickname, MON_FEMALE) ? 0x85 : 0x83;
                break;
            default:
                r2 = 0x83;
                break;
        }
    }
    sTradeMenuData->tilemapBuffer[(y - 1) * 32 + x + 1] = r2;
}

// Very close but loop preamble not working.
#ifdef NONMATCHING
static void sub_8079E44(u8 whichParty)
{
    int i;

    for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
    {
        sub_8079C4C(whichParty, i, gTradeLevelDisplayCoords[whichParty][i][0], gTradeLevelDisplayCoords[whichParty][i][1], gTradeMonBoxCoords[whichParty][i][0], gTradeMonBoxCoords[whichParty][i][1]);
    }
}
#else
NAKED
static void sub_8079E44(u8 whichParty)
{
    asm_unified("push {r4-r7,lr}\n\
    sub sp, 0x8\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    movs r7, 0\n\
    ldr r0, =sTradeMenuData\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    bge _08079E94\n\
    lsls r0, r6, 1\n\
    adds r0, r6\n\
    ldr r1, =gTradeLevelDisplayCoords\n\
    lsls r0, 2\n\
    adds r5, r0, r1\n\
    ldr r1, =gTradeMonBoxCoords\n\
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
    ldr r0, =sTradeMenuData\n\
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

static void sub_8079EA8(u8 whichParty)
{
    int i;

    for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
    {
        gSprites[sTradeMenuData->partyIcons[whichParty][i]].invisible = FALSE;
        gSprites[sTradeMenuData->partyIcons[whichParty][i]].pos1.x = gTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][0] * 8 + 14;
        gSprites[sTradeMenuData->partyIcons[whichParty][i]].pos1.y = gTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][1] * 8 - 12;
        gSprites[sTradeMenuData->partyIcons[whichParty][i]].pos2.x = 0;
        gSprites[sTradeMenuData->partyIcons[whichParty][i]].pos2.y = 0;
    }
}

static void sub_8079F74(void)
{
    rbox_fill_rectangle(1);
    PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);
}

static void sub_8079F88(u8 whichParty)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, whichParty * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    sub_8079E44(whichParty);
    PrintPartyNicknamesForTradeMenu(whichParty);
    sub_8079EA8(whichParty);
    sub_807A308(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + (sTradeMenuData->unk_72 * 32)), 24);
    sTradeMenuData->unk_74[whichParty] = 0;
}

static void sub_807A000(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

static void sub_807A024(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

//TODO: a1 here is the case var for the switch in sub_807A0C4
static void sub_807A048(u16 a0, u8 validity)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (sTradeMenuData->unk_8D0[i].unk_0 == FALSE)
        {
            sTradeMenuData->unk_8D0[i].unk_2 = a0; //TODO: always 3 or 5
            sTradeMenuData->unk_8D0[i].monValidity = validity;
            sTradeMenuData->unk_8D0[i].unk_0 = TRUE;
            break;
        }
    }
}

static u32 sub_807A09C(void)
{
    u32 acc = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        acc += sTradeMenuData->unk_8D0[i].unk_0;
    }

    return acc;
}

static void sub_807A0C4(void)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (sTradeMenuData->unk_8D0[i].unk_0)
        {
            if (sTradeMenuData->unk_8D0[i].unk_2)
            {
                sTradeMenuData->unk_8D0[i].unk_2--;
            }
            else
            {
                switch (sTradeMenuData->unk_8D0[i].monValidity)
                {
                    case 0:
                        SendLinkData(sTradeMenuData->linkData, 20);
                        break;
                    case 1:
                        PrintTradeMessage(TRADE_MSG_STANDBY);
                        break;
                    case 2:
                        PrintTradeMessage(TRADE_MSG_ONLY_MON1);
                        break;
                    case 3:
                    case 4:
                    case 5:
                        PrintTradeMessage(TRADE_MSG_ONLY_MON2);
                        break;
                    case 6:
                        PrintTradeMessage(TRADE_MSG_MON_CANT_BE_TRADED);
                        break;
                    case 7:
                        PrintTradeMessage(TRADE_MSG_EGG_CANT_BE_TRADED);
                        break;
                    case 8:
                        PrintTradeMessage(TRADE_MSG_FRIENDS_MON_CANT_BE_TRADED);
                        break;
                }
                sTradeMenuData->unk_8D0[i].unk_0 = FALSE;
            }
        }
    }
}

static void PrintTradeMessage(u8 messageId)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, 1, sTradeMessageTexts[messageId], 0, 1, TEXT_SPEED_FF, NULL);
    DrawTextBorderOuter(0, 20, 12);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static bool8 sub_807A1F0(void)
{
    struct SpriteSheet sheet;

    if (sTradeMenuData->unk_A8 < 14)
    {
        sheet.data = gUnknown_02032188[sTradeMenuData->unk_A8];
        sheet.size = 0x100;
        sheet.tag = 200 + sTradeMenuData->unk_A8;
    }

    switch (sTradeMenuData->unk_A8)
    {
        case 0 ... 7:
            LoadSpriteSheet(&sheet);
            sTradeMenuData->unk_A8++;
            break;
        case 8:
            sTradeMenuData->unk_72 = LoadSpriteSheet(&sheet);
            sTradeMenuData->unk_A8++;
            break;
        case 9 ... 13:
            LoadSpriteSheet(&sheet);
            sTradeMenuData->unk_A8++;
            break;
        case 14:
            LoadSpritePalette(&gSpritePalette_TradeScreenText);
            sTradeMenuData->unk_A8++;
            break;
        case 15:
            LoadSpritePalette(&gUnknown_0832DC44);
            sTradeMenuData->unk_A8++;
            break;
        case 16:
            LoadSpriteSheet(&gUnknown_0832DC3C);
            sTradeMenuData->unk_A8++;
            break;
        case 17:
            sTradeMenuData->unk_A8 = 0;
            return TRUE;
    }

    return FALSE;
}

static void sub_807A308(const u8 *a0, u8 *a1, u8 unused)
{
    sub_80C6D80(a0, a1, 0, 0, 6);
}

static void sub_807A320(u8 whichParty)
{
    int i;

    switch (whichParty)
    {
    case TRADE_PLAYER:
        for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == TRUE)
            {
                sTradeMenuData->isLiveMon[whichParty][i] = FALSE;
                sTradeMenuData->isEgg[whichParty][i] = TRUE;
            }
            else if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
            {
                sTradeMenuData->isLiveMon[whichParty][i] = FALSE;
                sTradeMenuData->isEgg[whichParty][i] = FALSE;
            }
            else
            {
                sTradeMenuData->isLiveMon[whichParty][i] = TRUE;
                sTradeMenuData->isEgg[whichParty][i] = FALSE;
            }
        }
        break;
    case TRADE_PARTNER:
        for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
        {
            if (GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG) == TRUE)
            {
                sTradeMenuData->isLiveMon[whichParty][i] = FALSE;
                sTradeMenuData->isEgg[whichParty][i] = TRUE;
            }
            else if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
            {
                sTradeMenuData->isLiveMon[whichParty][i] = FALSE;
                sTradeMenuData->isEgg[whichParty][i] = FALSE;
            }
            else
            {
                sTradeMenuData->isLiveMon[whichParty][i] = TRUE;
                sTradeMenuData->isEgg[whichParty][i] = FALSE;
            }
        }
        break;
    }
}

static void GetTradePartyHPBarLevels(u8 who)
{
    u16 i, curHp, maxHp;

    switch (who)
    {
        case TRADE_PLAYER:
            for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PLAYER]; i++)
            {
                curHp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
                sTradeMenuData->hpBarLevels[TRADE_PLAYER][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
        case TRADE_PARTNER:
            for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PARTNER]; i++)
            {
                curHp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gEnemyParty[i], MON_DATA_MAX_HP);
                sTradeMenuData->hpBarLevels[TRADE_PARTNER][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
    }
}

static void SetTradePartyHPBarSprites(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < sTradeMenuData->partyCounts[i]; j++)
        {
            SetPartyHPBarSprite(&gSprites[sTradeMenuData->partyIcons[i][j]], 4 - sTradeMenuData->hpBarLevels[i][j]);
        }
    }
}

static void sub_807A5B0(void)
{
    int i;

    for (i = 0; i < 11; i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && sTradeMenuData->unk_A9[i] != 0)
        {
            if (sTradeMenuData->unk_A9[i] < 64)
                gSaveBlock1Ptr->giftRibbons[i] = sTradeMenuData->unk_A9[i];
        }
    }
}

static u32 sub_807A5F4(struct Pokemon *playerParty, int partyCount, int monIdx)
{
    int i, sum;
    struct LinkPlayer *player;
    u32 species[PARTY_SIZE];
    u32 species2[PARTY_SIZE];

    for (i = 0; i < partyCount; i++)
    {
        species2[i] = GetMonData(&playerParty[i], MON_DATA_SPECIES2);
        species[i] = GetMonData(&playerParty[i], MON_DATA_SPECIES);
    }

    if (!IsNationalPokedexEnabled())
    {
        if (species2[monIdx] == SPECIES_EGG)
        {
            return 3;
        }

        if (!IsSpeciesInHoennDex(species2[monIdx]))
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
            if (species2[monIdx] == SPECIES_EGG)
            {
                return 5;
            }

            if (!IsSpeciesInHoennDex(species2[monIdx]))
            {
                return 4;
            }
        }
    }

    if (species[monIdx] == SPECIES_DEOXYS || species[monIdx] == SPECIES_MEW)
    {
        if (!GetMonData(&playerParty[monIdx], MON_DATA_OBEDIENCE))
        {
            return 4;
        }
    }

    for (i = 0; i < partyCount; i++)
    {
        if (species2[i] == SPECIES_EGG)
        {
            species2[i] = SPECIES_NONE;
        }
    }

    for (sum = 0, i = 0; i < partyCount; i++)
    {
        if (i != monIdx)
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

static bool32 IsDeoxysOrMewUntradable(u16 species, bool8 isObedientBitSet)
{
    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!isObedientBitSet)
            return TRUE;
    }
    return FALSE;
}

int sub_807A7E0(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 species1, u16 species2, u8 type, u16 species3, u8 isObedientBitSet)
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

    if (IsDeoxysOrMewUntradable(species3, isObedientBitSet))
    {
        return 4;
    }

    if (species2 == SPECIES_EGG)
    {
        if (species1 != species2)
        {
            return 2;
        }
    }
    else
    {
        if (gBaseStats[species1].type1 != type && gBaseStats[species1].type2 != type)
        {
            return 1;
        }
    }

    if (species1 == SPECIES_EGG && species1 != species2)
    {
        return 3;
    }

    if (!r9)
    {
        if (species1 == SPECIES_EGG)
        {
            return 6;
        }

        if (!IsSpeciesInHoennDex(species1))
        {
            return 4;
        }

        if (!IsSpeciesInHoennDex(species2))
        {
            return 5;
        }
    }

    if (!r10 && !IsSpeciesInHoennDex(species1))
    {
        return 7;
    }

    return 0;
}

int sub_807A8D0(struct UnkLinkRfuStruct_02022B14Substruct a0, u16 species, u16 a2, u8 a3)
{
    u8 unk = a0.unk_01_0;

    if (IsDeoxysOrMewUntradable(a2, a3))
    {
        return 1;
    }

    if (unk)
    {
        return 0;
    }

    if (species == SPECIES_EGG)
    {
        return 2;
    }

    if (IsSpeciesInHoennDex(species))
    {
        return 0;
    }

    return 1;
}

// r6/r7 flip. Ugh.
#ifdef NONMATCHING
int sub_807A918(struct Pokemon *mon, u16 monIdx)
{
    int i, version, versions, unk, unk2;
    int speciesArray[PARTY_SIZE];

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        speciesArray[i] = GetMonData(&mon[i], MON_DATA_SPECIES2);
        if (speciesArray[i] == SPECIES_EGG)
        {
            speciesArray[i] = 0;
        }
    }

    versions = 0;
    unk = 1;
    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        version = gLinkPlayers[i].version & 0xFF;
        if (version == VERSION_FIRE_RED ||
            version == VERSION_LEAF_GREEN)
        {
            versions = 0;
        }
        else
        {
            versions |= 1;
        }
    }

    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        struct LinkPlayer *player = &gLinkPlayers[i];
        if ((player->name[8] & 0xF) == 0)
        {
            unk = 0;
        }

        if (versions && (player->name[8] / 16))
        {
            unk = 0;
        }
    }

    if (unk == 0)
    {
        if (!IsSpeciesInHoennDex(speciesArray[monIdx]))
        {
            return 2;
        }

        if (speciesArray[monIdx] == SPECIES_NONE)
        {
            return 3;
        }
    }

    unk2 = 0;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (monIdx != i)
        {
            unk2 += speciesArray[i];
        }
    }

    if (!unk2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#else
NAKED
int sub_807A918(struct Pokemon *mon, u16 a1)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0x18\n\
	adds r6, r0, 0\n\
	lsls r1, 16\n\
	lsrs r1, 16\n\
	mov r8, r1\n\
	movs r5, 0\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bge _0807A95A\n\
	mov r4, sp\n\
_0807A934:\n\
	movs r0, 0x64\n\
	muls r0, r5\n\
	adds r0, r6, r0\n\
	movs r1, 0x41\n\
	bl GetMonData\n\
	str r0, [r4]\n\
	movs r1, 0xCE\n\
	lsls r1, 1\n\
	cmp r0, r1\n\
	bne _0807A94E\n\
	movs r0, 0\n\
	str r0, [r4]\n\
_0807A94E:\n\
	adds r4, 0x4\n\
	adds r5, 0x1\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	blt _0807A934\n\
_0807A95A:\n\
	movs r7, 0\n\
	movs r6, 0x1\n\
	movs r5, 0\n\
	ldr r4, =gLinkPlayers\n\
	b _0807A980\n\
	.pool\n\
_0807A96C:\n\
	ldrb r0, [r4]\n\
	subs r0, 0x4\n\
	cmp r0, 0x1\n\
	bhi _0807A978\n\
	movs r7, 0\n\
	b _0807A97C\n\
_0807A978:\n\
	movs r0, 0x1\n\
	orrs r7, r0\n\
_0807A97C:\n\
	adds r4, 0x1C\n\
	adds r5, 0x1\n\
_0807A980:\n\
	bl GetLinkPlayerCount\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r5, r0\n\
	blt _0807A96C\n\
	movs r5, 0\n\
	movs r4, 0\n\
	b _0807A9B4\n\
_0807A992:\n\
	ldr r0, =gLinkPlayers\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2, 0x10]\n\
	movs r0, 0xF\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _0807A9A2\n\
	movs r6, 0\n\
_0807A9A2:\n\
	cmp r7, 0\n\
	beq _0807A9B0\n\
	ldrb r0, [r2, 0x10]\n\
	lsrs r0, 4\n\
	cmp r0, 0\n\
	beq _0807A9B0\n\
	movs r6, 0\n\
_0807A9B0:\n\
	adds r4, 0x1C\n\
	adds r5, 0x1\n\
_0807A9B4:\n\
	bl GetLinkPlayerCount\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r5, r0\n\
	blt _0807A992\n\
	cmp r6, 0\n\
	bne _0807A9EA\n\
	mov r1, r8\n\
	lsls r0, r1, 2\n\
	mov r1, sp\n\
	adds r4, r1, r0\n\
	ldrh r0, [r4]\n\
	bl IsSpeciesInHoennDex\n\
	cmp r0, 0\n\
	bne _0807A9E0\n\
	movs r0, 0x2\n\
	b _0807AA1A\n\
	.pool\n\
_0807A9E0:\n\
	ldr r0, [r4]\n\
	cmp r0, 0\n\
	bne _0807A9EA\n\
	movs r0, 0x3\n\
	b _0807AA1A\n\
_0807A9EA:\n\
	movs r2, 0\n\
	movs r5, 0\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	bge _0807AA0A\n\
	adds r3, r0, 0\n\
	mov r1, sp\n\
_0807A9FA:\n\
	cmp r8, r5\n\
	beq _0807AA02\n\
	ldr r0, [r1]\n\
	adds r2, r0\n\
_0807AA02:\n\
	adds r1, 0x4\n\
	adds r5, 0x1\n\
	cmp r5, r3\n\
	blt _0807A9FA\n\
_0807AA0A:\n\
	cmp r2, 0\n\
	beq _0807AA18\n\
	movs r0, 0\n\
	b _0807AA1A\n\
	.pool\n\
_0807AA18:\n\
	movs r0, 0x1\n\
_0807AA1A:\n\
	add sp, 0x18\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1");
}
#endif // NONMATCHING

static void sub_807AA28(struct Sprite *sprite)
{
    if (++sprite->data[0] == 10)
    {
        PlaySE(SE_BOWA);
        sprite->data[0] = 0;
    }
}

static void sub_807AA4C(struct Sprite *sprite)
{
    if (!sprite->invisible && ++sprite->data[0] == 10)
    {
        PlaySE(SE_W207B);
        sprite->data[0] = 0;
    }
}

static void sub_807AA7C(struct Sprite *sprite)
{
    if (!sprite->data[1])
    {
        if (++sprite->data[0] == 12)
            sprite->data[0] = 0;

        LoadPalette(&gUnknown_08338EA4[sprite->data[0]], (sprite->oam.paletteNum + 16) * 16 + 4, 2);
    }
}

static void sub_807AABC(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->pos2.y++;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void sub_807AAE0(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->pos2.y--;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void sub_807AB04(struct Sprite *sprite)
{
    if (++sprite->data[0] == 15)
    {
        PlaySE(SE_W107);
        sprite->data[0] = 0;
    }
}

static void sub_807AB28(void)
{
    struct BgAffineDstData affine;

    DoBgAffineSet(&affine, sTradeData->unk_D4 * 0x100, sTradeData->unk_D6 * 0x100, sTradeData->unk_DC, sTradeData->unk_DE, sTradeData->unk_E8, sTradeData->unk_E8, sTradeData->unk_EC);
    SetGpuReg(REG_OFFSET_BG2PA, affine.pa);
    SetGpuReg(REG_OFFSET_BG2PB, affine.pb);
    SetGpuReg(REG_OFFSET_BG2PC, affine.pc);
    SetGpuReg(REG_OFFSET_BG2PD, affine.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, affine.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, affine.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, affine.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, affine.dy >> 16);
}

static void sub_807ABCC(void)
{
    u16 dispcnt;

    SetGpuReg(REG_OFFSET_BG1VOFS, sTradeData->bg1vofs);
    SetGpuReg(REG_OFFSET_BG1HOFS, sTradeData->bg1hofs);

    dispcnt = GetGpuReg(REG_OFFSET_DISPCNT);
    if ((dispcnt & 7) == DISPCNT_MODE_0)
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, sTradeData->bg2vofs);
        SetGpuReg(REG_OFFSET_BG2HOFS, sTradeData->bg2hofs);
    }
    else
    {
        sub_807AB28();
    }
}

static void sub_807AC24(void)
{
    sub_807ABCC();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_807AC3C(void)
{
    sTradeData->unk_8A = 0;
    sTradeData->unk_88 = 0;
    sTradeData->unk_89 = 0;
}

static void sub_807AC64(void)
{
    if (sTradeData->unk_88 == sTradeData->unk_89)
        sTradeData->unk_8A++;
    else
        sTradeData->unk_8A = 0;

    if (sTradeData->unk_8A > 300)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        sTradeData->unk_8A = 0;
        sTradeData->unk_89 = 0;
        sTradeData->unk_88 = 0;
    }

    sTradeData->unk_89 = sTradeData->unk_88;
}

static u32 sub_807ACDC(void)
{
    if (gReceivedRemoteLinkPlayers)
        return GetMultiplayerId();
    return 0;
}

static void sub_807ACFC(u8 whichParty, u8 a1)
{
    int pos = 0;
    struct Pokemon *mon = NULL;
    u16 species;
    u32 personality;

    if (whichParty == TRADE_PLAYER)
    {
        mon = &gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]];
        pos = 1;
    }

    if (whichParty == TRADE_PARTNER)
    {
        mon = &gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE];
        pos = 3;
    }

    switch (a1)
    {
        case 0:
            species = GetMonData(mon, MON_DATA_SPECIES2);
            personality = GetMonData(mon, MON_DATA_PERSONALITY);

            if (whichParty == TRADE_PLAYER)
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);
            else
                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[whichParty * 2 + 1], species, personality);

            LoadCompressedSpritePalette(GetMonSpritePalStruct(mon));
            sTradeData->tradeSpecies[whichParty] = species;
            sTradeData->unk_68[whichParty] = personality;
            break;
        case 1:
            SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, pos);
            sTradeData->pokePicSpriteIdxs[whichParty] = CreateSprite(&gMultiuseSpriteTemplate, 120, 60, 6);
            gSprites[sTradeData->pokePicSpriteIdxs[whichParty]].invisible = TRUE;
            gSprites[sTradeData->pokePicSpriteIdxs[whichParty]].callback = SpriteCallbackDummy;
            break;
    }
}

void sub_807AE50(void)
{
    switch (gMain.state)
    {
        case 0:
            if (!gReceivedRemoteLinkPlayers)
            {
                gLinkType = 0x1144;
                CloseLink();
            }
            sTradeData = AllocZeroed(sizeof(*sTradeData));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(sub_807AC24);
            sub_807B170();
            sub_807AC3C();
            gMain.state++;
            sTradeData->unk_8C = 0;
            sTradeData->state = 0;
            sTradeData->isLinkTrade = TRUE;
            sTradeData->unk_D4 = 64;
            sTradeData->unk_D6 = 64;
            sTradeData->unk_D8 = 0;
            sTradeData->unk_DA = 0;
            sTradeData->unk_DC = 120;
            sTradeData->unk_DE = 80;
            sTradeData->unk_E8 = 256;
            sTradeData->unk_EC = 0;
            break;
        case 1:
            if (!gReceivedRemoteLinkPlayers)
            {
                sTradeData->unk_FA = 1;
                OpenLink();
                gMain.state++;
                sTradeData->timer = 0;
            }
            else
            {
                gMain.state = 4;
            }
            break;
        case 2:
            if (++sTradeData->timer > 60)
            {
                sTradeData->timer = 0;
                gMain.state++;
            }
            break;
        case 3:
            if (IsLinkMaster())
            {
                if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
                {
                    if (++sTradeData->timer > 30)
                    {
                        CheckShouldAdvanceLinkState();
                        gMain.state++;
                    }
                }
                else
                {
                    sub_807AC64();
                }
            }
            else
            {
                gMain.state++;
            }
            break;
        case 4:
            sub_807AC64();
            if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
                gMain.state++;
            break;
        case 5:
            sTradeData->unk_72 = 0;
            sTradeData->unk_73 = 0;
            sTradeData->unk_93 = 0;
            sub_807ACFC(TRADE_PLAYER, 0);
            gMain.state++;
            break;
        case 6:
            sub_807ACFC(TRADE_PLAYER, 1);
            gMain.state++;
            break;
        case 7:
            sub_807ACFC(TRADE_PARTNER, 0);
            gMain.state++;
            break;
        case 8:
            sub_807ACFC(TRADE_PARTNER, 1);
            sub_807B154();
            gMain.state++;
            break;
        case 9:
            sub_807BA94();
            LoadSpriteSheet(&gUnknown_08338D18);
            LoadSpritePalette(&gUnknown_08338D20);
            gMain.state++;
            break;
        case 10:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            ShowBg(0);
            gMain.state++;
            break;
        case 11:
            sub_807B140();
            SetTradeSceneStrings();
            gMain.state++;
            break;
        case 12:
            if (!gPaletteFade.active)
            {
                if (gWirelessCommType)
                {
                    LoadWirelessStatusIndicatorSpriteGfx();
                    CreateWirelessStatusIndicatorSprite(0, 0);
                }
                SetMainCallback2(sub_807EA2C);
            }
            break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807B140(void)
{
    sub_807B62C(5);
    sub_807B62C(0);
}

void sub_807B154(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static void sub_807B170(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08339014, ARRAY_COUNT(gUnknown_08339014));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    SetBgTilemapBuffer(0, Alloc(0x800));
    SetBgTilemapBuffer(1, Alloc(0x800));
    SetBgTilemapBuffer(3, Alloc(0x800));
    DeactivateAllTextPrinters();
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
    InitWindows(gUnknown_08338FFC);
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
}

// In-game trade init
static void sub_807B270(void)
{
    u8 otName[11];

    switch (gMain.state)
    {
        case 0:
            gSelectedTradeMonPositions[TRADE_PLAYER] = gSpecialVar_0x8005;
            gSelectedTradeMonPositions[TRADE_PARTNER] = PARTY_SIZE;
            StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);
            GetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, otName);
            StringCopy(gLinkPlayers[1].name, otName);
            gLinkPlayers[0].language = LANGUAGE_ENGLISH;
            gLinkPlayers[1].language = GetMonData(&gEnemyParty[0], MON_DATA_LANGUAGE);
            sTradeData = AllocZeroed(sizeof(*sTradeData));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(sub_807AC24);
            sub_807B170();
            sTradeData->isLinkTrade = FALSE;
            sTradeData->unk_8C = 0;
            sTradeData->state = 0;
            sTradeData->unk_D4 = 64;
            sTradeData->unk_D6 = 64;
            sTradeData->unk_D8 = 0;
            sTradeData->unk_DA = 0;
            sTradeData->unk_DC = 120;
            sTradeData->unk_DE = 80;
            sTradeData->unk_E8 = 256;
            sTradeData->unk_EC = 0;
            sTradeData->timer = 0;
            gMain.state = 5;
            break;
        case 5:
            sub_807ACFC(TRADE_PLAYER, 0);
            gMain.state++;
            break;
        case 6:
            sub_807ACFC(TRADE_PLAYER, 1);
            gMain.state++;
            break;
        case 7:
            sub_807ACFC(TRADE_PARTNER, 0);
            ShowBg(0);
            gMain.state++;
            break;
        case 8:
            sub_807ACFC(TRADE_PARTNER, 1);
            FillWindowPixelBuffer(0, PIXEL_FILL(15));
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            gMain.state++;
            break;
        case 9:
            sub_807BA94();
            LoadSpriteSheet(&gUnknown_08338D18);
            LoadSpritePalette(&gUnknown_08338D20);
            gMain.state++;
            break;
        case 10:
            ShowBg(0);
            gMain.state++;
            break;
        case 11:
            sub_807B62C(5);
            sub_807B62C(0);
            SetTradeSceneStrings();
            gMain.state++;
            break;
        case 12:
            SetMainCallback2(sub_807B60C);
            break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807B464(u8 partyIdx)
{
    struct Pokemon *mon = &gPlayerParty[partyIdx];

    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
        species = SpeciesToNationalPokedexNum(species);
        GetSetPokedexFlag(species, FLAG_SET_SEEN);
        HandleSetPokedexFlag(species, FLAG_SET_CAUGHT, personality);
    }
}

static void sub_807B4C4(void)
{
    u8 mpId = GetMultiplayerId();
    // Originally in Ruby but commented out
    /*if (gLinkPlayers[mpId ^ 1].lp_field_2 == 0x8000)
        EnableNationalPokedex();*/
}

static void sub_807B4D0(u8 a0, u8 a1)
{
    u8 friendship;

    struct Pokemon *playerMon = &gPlayerParty[a0];
    u16 playerMail = GetMonData(playerMon, MON_DATA_MAIL);

    struct Pokemon *partnerMon = &gEnemyParty[a1];
    u16 partnerMail = GetMonData(partnerMon, MON_DATA_MAIL);

    if (playerMail != 0xFF)
        ClearMailStruct(&gSaveBlock1Ptr->mail[playerMail]);

    // This is where the actual trade happens!!
    sTradeData->mon = *playerMon;
    *playerMon = *partnerMon;
    *partnerMon = sTradeData->mon;

    friendship = 70;
    if (!GetMonData(playerMon, MON_DATA_IS_EGG))
        SetMonData(playerMon, MON_DATA_FRIENDSHIP, &friendship);

    if (partnerMail != 0xFF)
        GiveMailToMon2(playerMon, &gUnknown_020321C0[partnerMail]);

    sub_807B464(a0);
    if (gReceivedRemoteLinkPlayers)
        sub_807B4C4();
}

static void sub_807B5B8(void)
{
    switch (sTradeData->unk_93)
    {
        case 1:
            if (IsLinkTaskFinished())
            {
                Trade_SendData(sTradeData);
                sTradeData->unk_93++;
            }
            // fallthrough
        case 2:
            sTradeData->unk_93 = 0;
            break;
    }
}

static void sub_807B60C(void)
{
    sub_807BBC8();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807B62C(u8 a0)
{
    switch (a0)
    {
        case 0:
            sTradeData->bg2vofs = 0;
            sTradeData->bg2hofs = 180;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT512x256);
            LoadPalette(gTradeGba2_Pal, 16, 0x60);
            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
            DmaCopy16Defvars(3, gUnknown_08331F60, (void *) BG_SCREEN_ADDR(18), 0x1000);
            break;
        case 1:
            sTradeData->bg1hofs = 0;
            sTradeData->bg1vofs = 348;
            SetGpuReg(REG_OFFSET_BG1VOFS, 348);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(0) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(5) |
                                         BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT256x512);

            if (sTradeData->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083369A0, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083359A0, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }

            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(0), 0x1420, 0x1000);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 2:
            sTradeData->bg1vofs = 0;
            sTradeData->bg1hofs = 0;
            if (!sTradeData->unk_FA)
            {
                SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                              DISPCNT_OBJ_1D_MAP |
                                              DISPCNT_BG1_ON |
                                              DISPCNT_OBJ_ON);
                LZ77UnCompVram(gUnknown_083379A0, (void *) BG_SCREEN_ADDR(5));
                BlendPalettes(0x8, 16, RGB_BLACK);
            }
            else
            {
                SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                              DISPCNT_OBJ_1D_MAP |
                                              DISPCNT_BG1_ON |
                                              DISPCNT_OBJ_ON);
                DmaCopy16Defvars(3, sTradeTilemap_Cable, (void *) BG_SCREEN_ADDR(5), 0x800);
                BlendPalettes(0x1, 16, RGB_BLACK);
            }
            break;
        case 3:
            LoadPalette(sTradePal_Black, 48, 0x20);
            LZ77UnCompVram(sTradeGfx_WirelessSignal, (void *) BG_CHAR_ADDR(1));
            LZ77UnCompVram(sTradeTilemap_WirelessSignal, (void *) BG_SCREEN_ADDR(18));
            sTradeData->bg2vofs = 80;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 4:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_256COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_AFF128x128);
            sTradeData->unk_D4 = 64;
            sTradeData->unk_D6 = 92;
            sTradeData->unk_E8 = 32;
            sTradeData->unk_EA = 1024;
            sTradeData->unk_EC = 0;

            DmaCopyLarge16(3, gUnknown_08332F60, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

            if (sTradeData->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083357A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083358A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 5:
            sTradeData->bg1vofs = 0;
            sTradeData->bg1hofs = 0;
            break;
        case 6:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_256COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_AFF128x128);
            sTradeData->unk_D4 = 64;
            sTradeData->unk_D6 = 92;
            sTradeData->unk_E8 = 256;
            sTradeData->unk_EA = 128;
            sTradeData->unk_DC = 120;
            sTradeData->unk_DE = 80;
            sTradeData->unk_EC = 0;

            DmaCopyLarge16(3, gUnknown_08332F60, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

            if (sTradeData->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083357A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083358A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 7:
            sTradeData->bg2vofs = 0;
            sTradeData->bg2hofs = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT512x256);
            LoadPalette(gTradeGba2_Pal, 16, 0x60);
            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
            DmaCopy16Defvars(3, gUnknown_08331F60, (void *) BG_SCREEN_ADDR(18), 0x1000);
            break;
    }
}

static void sub_807BA94(void)
{
    LoadSpriteSheet(&gUnknown_08338D70);
    LoadSpriteSheet(&gUnknown_08338DC0);
    LoadSpriteSheet(&gUnknown_08338DF4);
    LoadSpriteSheet(&gUnknown_08338E6C);
    LoadSpritePalette(&gUnknown_08338D78);
    LoadSpritePalette(&gUnknown_08338D80);
}

/// Buffers "[Pokemon] will be sent to [Trainer]" strings
static void SetTradeSceneStrings(void)
{
    u8 mpId;
    u8 name[20];
    const struct InGameTrade *ingameTrade;

    if (sTradeData->isLinkTrade)
    {
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar3, name);
        GetMonData(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
    else
    {
        ingameTrade = &sIngameTrades[gSpecialVar_0x8004];
        StringCopy(gStringVar1, ingameTrade->otName);
        StringCopy10(gStringVar3, ingameTrade->nickname);
        GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
}

static u8 sub_807BBC8(void)
{
    if (sTradeData->unk_FA)
    {
        return sub_807BBEC();
    }
    else
    {
        return sub_807CFC8();
    }
}

static bool8 sub_807BBEC(void)
{
    u16 evoTarget;

    switch (sTradeData->state)
    {
        case 0:
            gSprites[sTradeData->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.x = -180;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y = gMonFrontPicCoords[sTradeData->tradeSpecies[0]].y_offset;
            sTradeData->state++;
            sTradeData->cachedMapMusic = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (sTradeData->bg2hofs > 0)
            {
                gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.x += 3;
                sTradeData->bg2hofs -= 3;
            }
            else
            {
                gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.x = 0;
                sTradeData->bg2hofs = 0;
                sTradeData->state = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);

            if (sTradeData->tradeSpecies[0] != SPECIES_EGG)
            {
                PlayCry1(sTradeData->tradeSpecies[0], 0);
            }

            sTradeData->state = 11;
            sTradeData->timer = 0;
            break;
        case 11:
            if (++sTradeData->timer == 80)
            {
                sTradeData->unk_D2 = sub_807671C(sTradeData->pokePicSpriteIdxs[0], gSprites[sTradeData->pokePicSpriteIdxs[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                sTradeData->state++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[sTradeData->unk_D2].callback == SpriteCallbackDummy)
            {
                sTradeData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[sTradeData->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[sTradeData->unk_D2]);
                sTradeData->state++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->state = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, PIXEL_FILL(15));
                CopyWindowToVram(0, 3);
                sTradeData->state++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeData->state++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                sTradeData->state = 23;
            }
            break;
        case 23:
            if (sTradeData->unk_EA > 0x100)
            {
                sTradeData->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                sTradeData->unk_EA = 0x80;
                sTradeData->state++;
                sTradeData->timer = 0;
            }
            sTradeData->unk_E8 = 0x8000 / sTradeData->unk_EA;
            break;
        case 24:
            if (++sTradeData->timer > 20)
            {
                sub_807AB28();
                sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
                sTradeData->state++;
            }
            break;
        case 25:
            if (gSprites[sTradeData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeData->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG1 |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 4));
                sTradeData->state++;
            }
            break;
        case 26:
            if (--sTradeData->bg1vofs == 316)
            {
                sTradeData->state++;
            }
            if (sTradeData->bg1vofs == 328)
            {
                sTradeData->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
            }
            break;
        case 27:
            sTradeData->unk_90 = CreateSprite(&gUnknown_08338D88, 128, 80, 3);
            sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, 80, 0);
            StartSpriteAnim(&gSprites[sTradeData->unk_91], 1);
            sTradeData->state++;
            break;
        case 28:
            if ((sTradeData->bg1vofs -= 2) == 166)
            {
                sTradeData->state = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[sTradeData->unk_90].pos1.y -= 2;
            gSprites[sTradeData->unk_91].pos1.y -= 2;
            if (gSprites[sTradeData->unk_90].pos1.y < -8)
            {
                sTradeData->state = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            sTradeData->state = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[sTradeData->unk_90]);
                DestroySprite(&gSprites[sTradeData->unk_91]);
                sub_807B62C(2);
                sTradeData->state++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeData->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            sTradeData->state++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                sTradeData->state++;
            }
            gSprites[sTradeData->unk_90].pos2.y -= 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[sTradeData->unk_90].pos2.y -= 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            if (gSprites[sTradeData->unk_90].pos2.y <= -90)
            {
                gSprites[sTradeData->unk_90].data[1] = 1;
                gSprites[sTradeData->unk_91].data[1] = 1;
                sTradeData->state++;
            }
            break;
        case 34:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 35:
            BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 36:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(sTradeData->tradeSpecies[0]))
            {
                gSprites[sTradeData->pokePicSpriteIdxs[0]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[sTradeData->pokePicSpriteIdxs[0]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[sTradeData->pokePicSpriteIdxs[0]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[sTradeData->pokePicSpriteIdxs[0]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[sTradeData->pokePicSpriteIdxs[0]], 0);
            }
            StartSpriteAffineAnim(&gSprites[sTradeData->pokePicSpriteIdxs[1]], 0);
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos1.x = 60;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.x = 180;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos1.y = 192;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.y = -32;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].invisible = FALSE;
            sTradeData->state++;
            break;
        case 38:
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y -= 3;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos2.y += 3;
            if (gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y < -160 && gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y < -222)
            {
                gSprites[sTradeData->unk_90].data[1] = 0;
                gSprites[sTradeData->unk_91].data[1] = 0;
                sTradeData->state++;
                gSprites[sTradeData->pokePicSpriteIdxs[0]].invisible = TRUE;
                gSprites[sTradeData->pokePicSpriteIdxs[1]].invisible = TRUE;
                BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            }
            break;
        case 39:
            gSprites[sTradeData->unk_90].pos2.y -= 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            if (gSprites[sTradeData->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                sTradeData->state++;
                DestroySprite(&gSprites[sTradeData->unk_90]);
                DestroySprite(&gSprites[sTradeData->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                sTradeData->state++;
                sub_807B62C(1);
                sTradeData->bg1vofs = 166;
                sTradeData->unk_90 = CreateSprite(&gUnknown_08338D88, 128, -20, 3);
                sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, -20, 0);
                StartSpriteAnim(&gSprites[sTradeData->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeData->state++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeData->state++;
            }
            break;
        case 43:
            gSprites[sTradeData->unk_90].pos2.y += 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            if (gSprites[sTradeData->unk_90].pos2.y + gSprites[sTradeData->unk_90].pos1.y == 64)
            {
                sTradeData->state++;
            }
            break;
        case 44:
            if ((sTradeData->bg1vofs += 2) > 316)
            {
                sTradeData->bg1vofs = 316;
                sTradeData->state++;
            }
            break;
        case 45:
            DestroySprite(&gSprites[sTradeData->unk_90]);
            DestroySprite(&gSprites[sTradeData->unk_91]);
            sTradeData->state++;
            sTradeData->timer = 0;
            break;
        case 46:
            if (++sTradeData->timer == 10)
            {
                sTradeData->state++;
            }
            break;
        case 47:
            if (++sTradeData->bg1vofs > 348)
            {
                sTradeData->bg1vofs = 348;
                sTradeData->state++;
            }
            if (sTradeData->bg1vofs == 328 && sTradeData->unk_FA)
            {
                sTradeData->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
                gSprites[sTradeData->unk_92].callback = sub_807AAE0;
            }
            break;
        case 48:
            sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            sTradeData->state = 50;
            break;
        case 50:
            if (gSprites[sTradeData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeData->unk_91]);
                sub_807B62C(6);
                sTradeData->state++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (sTradeData->unk_EA < 0x400)
            {
                sTradeData->unk_EA += 0x34;
            }
            else
            {
                sTradeData->unk_EA = 0x400;
                sTradeData->state++;
            }
            sTradeData->unk_E8 = 0x8000 / sTradeData->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->state = 60;
            break;

        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                sTradeData->state++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            sTradeData->state++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeData->state++;
            }
            break;
        case 63:
            sTradeData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[sTradeData->unk_D3].data[3] = 74;
            gSprites[sTradeData->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[sTradeData->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[sTradeData->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[sTradeData->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            sTradeData->state++;
            sTradeData->timer = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[sTradeData->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 65:
            if (gSprites[sTradeData->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[sTradeData->tradeSpecies[1]], gMonSpritesGfxPtr->sprites[3], sTradeData->tradeSpecies[1], sTradeData->unk_68[1]);
                sTradeData->state++;
            }
            break;
        case 66:
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.x = 120;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.y = gMonFrontPicCoords[sTradeData->tradeSpecies[1]].y_offset + 60;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos2.x = 0;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos2.y = 0;
            StartSpriteAnim(&gSprites[sTradeData->pokePicSpriteIdxs[1]], 0);
            CreatePokeballSpriteToReleaseMon(sTradeData->pokePicSpriteIdxs[1], gSprites[sTradeData->pokePicSpriteIdxs[1]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, sTradeData->tradeSpecies[1]);
            FreeSpriteOamMatrix(&gSprites[sTradeData->unk_D3]);
            DestroySprite(&gSprites[sTradeData->unk_D3]);
            sTradeData->state++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            sTradeData->state = 167;
            sTradeData->timer = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++sTradeData->timer > 60)
            {
                sTradeData->state = 267;
                sTradeData->timer = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                sTradeData->state = 68;
            }
            break;
        case 68:
            if (++sTradeData->timer == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (sTradeData->timer == 250)
            {
                sTradeData->state++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
                sTradeData->timer = 0;
            }
            break;
        case 69:
            if (++sTradeData->timer == 60)
            {
                sTradeData->state++;
            }
            break;
        case 70:
            CheckPartnersMonForRibbons();
            sTradeData->state++;
            break;
        case 71:
            if (sTradeData->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                sTradeData->state++;
            }
            break;
        case 72: // Only if in-game trade
            sub_807B4D0(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeData->pokePicSpriteIdxs[1], gSelectedTradeMonPositions[TRADE_PLAYER]);
            }
            sTradeData->state++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->state++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(sTradeData->cachedMapMusic);
                if (sTradeData)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(sTradeData);
                }
                SetMainCallback2(CB2_ReturnToField);
                sub_807E784();
            }
            break;
    }
    return FALSE;
}

static bool8 sub_807CFC8(void)
{
    u16 evoTarget;

    switch (sTradeData->state)
    {
        case 0:
            gSprites[sTradeData->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.x = -180;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y = gMonFrontPicCoords[sTradeData->tradeSpecies[0]].y_offset;
            sTradeData->state++;
            sTradeData->cachedMapMusic = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (sTradeData->bg2hofs > 0)
            {
                gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.x += 3;
                sTradeData->bg2hofs -= 3;
            }
            else
            {
                gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.x = 0;
                sTradeData->bg2hofs = 0;
                sTradeData->state = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);

            if (sTradeData->tradeSpecies[0] != SPECIES_EGG)
            {
                PlayCry1(sTradeData->tradeSpecies[0], 0);
            }

            sTradeData->state = 11;
            sTradeData->timer = 0;
            break;
        case 11:
            if (++sTradeData->timer == 80)
            {
                sTradeData->unk_D2 = sub_807671C(sTradeData->pokePicSpriteIdxs[0], gSprites[sTradeData->pokePicSpriteIdxs[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                sTradeData->state++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[sTradeData->unk_D2].callback == SpriteCallbackDummy)
            {
                sTradeData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[sTradeData->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[sTradeData->unk_D2]);
                sTradeData->state++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->state = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, PIXEL_FILL(15));
                CopyWindowToVram(0, 3);
                sTradeData->state++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeData->state++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                sTradeData->state = 23;
            }
            break;
        case 23:
            if (sTradeData->unk_EA > 0x100)
            {
                sTradeData->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                sTradeData->unk_EA = 0x80;
                sTradeData->state = 124;
                sTradeData->timer = 0;
            }
            sTradeData->unk_E8 = 0x8000 / sTradeData->unk_EA;
            break;
        case 124:
            if (++sTradeData->timer > 20)
            {
                sub_807B62C(3);
                sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338E8C, 120, 80, 0);
                sTradeData->state++;
            }
            break;
        case 125:
            if (gSprites[sTradeData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeData->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 |
                                             BLDCNT_TGT1_OBJ |
                                             BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));
                CreateTask(c3_08054588, 5);
                sTradeData->state++;
            }
            break;
        case 126:
            if (!FuncIsActiveTask(c3_08054588))
            {
                sTradeData->state = 26;
            }
            break;
        case 26:
            if (--sTradeData->bg1vofs == 316)
            {
                sTradeData->state++;
            }
            break;
        case 27:
            sTradeData->unk_90 = CreateSprite(&gUnknown_08338D88, 120, 80, 3);
            gSprites[sTradeData->unk_90].callback = sub_807AA4C;
            sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, 80, 0);
            StartSpriteAnim(&gSprites[sTradeData->unk_91], 1);
            sTradeData->state++;
            break;
        case 28:
            if ((sTradeData->bg1vofs -= 3) == 166)
            {
                sTradeData->state = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[sTradeData->unk_90].pos1.y -= 2;
            gSprites[sTradeData->unk_91].pos1.y -= 2;
            if (gSprites[sTradeData->unk_90].pos1.y < -8)
            {
                sTradeData->state = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            sTradeData->state = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[sTradeData->unk_90]);
                DestroySprite(&gSprites[sTradeData->unk_91]);
                sub_807B62C(2);
                sTradeData->state++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeData->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            sTradeData->state++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                sTradeData->state++;
            }
            gSprites[sTradeData->unk_90].pos2.y -= 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[sTradeData->unk_90].pos2.y -= 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            if (gSprites[sTradeData->unk_90].pos2.y <= -90)
            {
                gSprites[sTradeData->unk_90].data[1] = 1;
                gSprites[sTradeData->unk_91].data[1] = 1;
                sTradeData->state++;
                CreateTask(c3_0805465C, 5);
            }
            break;
        case 34:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 35:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 36:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(sTradeData->tradeSpecies[0]))
            {
                gSprites[sTradeData->pokePicSpriteIdxs[0]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[sTradeData->pokePicSpriteIdxs[0]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[sTradeData->pokePicSpriteIdxs[0]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[sTradeData->pokePicSpriteIdxs[0]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[sTradeData->pokePicSpriteIdxs[0]], 0);
            }
            StartSpriteAffineAnim(&gSprites[sTradeData->pokePicSpriteIdxs[1]], 0);
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos1.x = 40;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.x = 200;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos1.y = 192;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.y = -32;
            gSprites[sTradeData->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].invisible = FALSE;
            sTradeData->state++;
            break;
        case 38:
            gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y -= 3;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos2.y += 3;
            if (gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y < -160 && gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[sTradeData->pokePicSpriteIdxs[0]].pos2.y < -222)
            {
                gSprites[sTradeData->unk_90].data[1] = 0;
                gSprites[sTradeData->unk_91].data[1] = 0;
                sTradeData->state++;
                gSprites[sTradeData->pokePicSpriteIdxs[0]].invisible = TRUE;
                gSprites[sTradeData->pokePicSpriteIdxs[1]].invisible = TRUE;
                CreateTask(sub_807F39C, 5);
            }
            break;
        case 39:
            gSprites[sTradeData->unk_90].pos2.y -= 3;
            gSprites[sTradeData->unk_91].pos2.y += 3;
            if (gSprites[sTradeData->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                sTradeData->state++;
                DestroySprite(&gSprites[sTradeData->unk_90]);
                DestroySprite(&gSprites[sTradeData->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                sTradeData->state++;
                sub_807B62C(1);
                sTradeData->bg1vofs = 166;
                sub_807B62C(3);
                sTradeData->bg2vofs = 412;
                sTradeData->unk_90 = CreateSprite(&gUnknown_08338D88, 120, -20, 3);
                gSprites[sTradeData->unk_90].callback = sub_807AA4C;
                sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, -20, 0);
                StartSpriteAnim(&gSprites[sTradeData->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeData->state++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeData->state++;
            }
            break;
        case 43:
            gSprites[sTradeData->unk_90].pos2.y += 4;
            gSprites[sTradeData->unk_91].pos2.y += 4;
            if (gSprites[sTradeData->unk_90].pos2.y + gSprites[sTradeData->unk_90].pos1.y == 64)
            {
                sTradeData->state = 144;
                sTradeData->timer = 0;
            }
            break;
        case 144:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            sTradeData->bg1vofs += 3;
            sTradeData->bg2vofs += 3;
            if (++sTradeData->timer == 10)
            {
                u8 taskId = CreateTask(c3_08054588, 5);
                gTasks[taskId].data[2] = 1;
            }
            if (sTradeData->bg1vofs > 316)
            {
                sTradeData->bg1vofs = 316;
                sTradeData->state++;
            }
            break;
        case 145:
            DestroySprite(&gSprites[sTradeData->unk_90]);
            DestroySprite(&gSprites[sTradeData->unk_91]);
            sTradeData->state++;
            sTradeData->timer = 0;
            break;
        case 146:
            if (!FuncIsActiveTask(c3_08054588))
            {
                sTradeData->state = 46;
                sTradeData->timer = 0;
            }
            break;
        case 46:
            if (++sTradeData->timer == 10)
            {
                sTradeData->state++;
            }
            break;
        case 47:
            if (++sTradeData->bg1vofs > 348)
            {
                sTradeData->bg1vofs = 348;
                sTradeData->state++;
            }
            break;
        case 48:
            sTradeData->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            sTradeData->state = 50;
            break;
        case 50:
            if (gSprites[sTradeData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeData->unk_91]);
                sub_807B62C(6);
                sTradeData->state++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (sTradeData->unk_EA < 0x400)
            {
                sTradeData->unk_EA += 0x34;
            }
            else
            {
                sTradeData->unk_EA = 0x400;
                sTradeData->state++;
            }
            sTradeData->unk_E8 = 0x8000 / sTradeData->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->state = 60;
            break;
        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                sTradeData->state++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            sTradeData->state++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeData->state++;
            }
            break;
        case 63:
            sTradeData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[sTradeData->unk_D3].data[3] = 74;
            gSprites[sTradeData->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[sTradeData->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[sTradeData->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[sTradeData->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            sTradeData->state++;
            sTradeData->timer = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[sTradeData->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            sTradeData->state++;
            break;
        case 65:
            if (gSprites[sTradeData->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[sTradeData->tradeSpecies[1]], gMonSpritesGfxPtr->sprites[3], sTradeData->tradeSpecies[1], sTradeData->unk_68[1]);
                sTradeData->state++;
            }
            break;
        case 66:
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.x = 120;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos1.y = gMonFrontPicCoords[sTradeData->tradeSpecies[1]].y_offset + 60;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos2.x = 0;
            gSprites[sTradeData->pokePicSpriteIdxs[1]].pos2.y = 0;
            StartSpriteAnim(&gSprites[sTradeData->pokePicSpriteIdxs[1]], 0);
            CreatePokeballSpriteToReleaseMon(sTradeData->pokePicSpriteIdxs[1], gSprites[sTradeData->pokePicSpriteIdxs[1]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, sTradeData->tradeSpecies[1]);
            FreeSpriteOamMatrix(&gSprites[sTradeData->unk_D3]);
            DestroySprite(&gSprites[sTradeData->unk_D3]);
            sTradeData->state++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            sTradeData->state = 167;
            sTradeData->timer = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++sTradeData->timer > 60)
            {
                sTradeData->state = 267;
                sTradeData->timer = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                sTradeData->state = 68;
            }
            break;
        case 68:
            if (++sTradeData->timer == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (sTradeData->timer == 250)
            {
                sTradeData->state++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
                sTradeData->timer = 0;
            }
            break;
        case 69:
            if (++sTradeData->timer == 60)
            {
                sTradeData->state++;
            }
            break;
        case 70:
            CheckPartnersMonForRibbons();
            sTradeData->state++;
            break;
        case 71:
            if (sTradeData->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                sTradeData->state++;
            }
            break;
        case 72: // Only if in-game trade
            sub_807B4D0(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeData->pokePicSpriteIdxs[1], gSelectedTradeMonPositions[TRADE_PLAYER]);
            }
            sTradeData->state++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->state++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(sTradeData->cachedMapMusic);
                if (sTradeData)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(sTradeData);
                }
                SetMainCallback2(CB2_ReturnToField);
                sub_807E784();
            }
            break;
    }
    return FALSE;
}

static void c2_08053788(void)
{
    u16 evoTarget;
    switch (gMain.state)
    {
        case 0:
            gMain.state = 4;
            gSoftResetDisabled = TRUE;
            break;
        case 4:
            gCB2_AfterEvolution = sub_807EB50;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
                TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeData->pokePicSpriteIdxs[1], gSelectedTradeMonPositions[TRADE_PLAYER]);
            else if (sub_8077260())
                SetMainCallback2(sub_807F464);
            else
                SetMainCallback2(sub_807EB50);
            gSelectedTradeMonPositions[TRADE_PLAYER] = 255;
            break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807E4DC(void)
{
    u8 blockReceivedStatus;
    sub_807ACDC();
    blockReceivedStatus = GetBlockReceivedStatus();
    if (blockReceivedStatus & 0x01)
    {
        if (gBlockRecvBuffer[0][0] == 0xDCBA)
        {
            SetMainCallback2(c2_08053788);
        }
        if (gBlockRecvBuffer[0][0] == 0xABCD)
        {
            sTradeData->unk_72 = 1;
        }
        ResetBlockReceivedFlag(0);
    }
    if (blockReceivedStatus & 0x02)
    {
        if (gBlockRecvBuffer[1][0] == 0xABCD)
        {
            sTradeData->unk_73 = 1;
        }
        ResetBlockReceivedFlag(1);
    }
}

static void sub_807E55C(struct Sprite *sprite)
{
    sprite->pos1.y += sprite->data[0] / 10;
    sprite->data[5] += sprite->data[1];
    sprite->pos1.x = sprite->data[5] / 10;
    if (sprite->pos1.y > 0x4c)
    {
        sprite->pos1.y = 0x4c;
        sprite->data[0] = -(sprite->data[0] * sprite->data[2]) / 100;
        sprite->data[3] ++;
    }
    if (sprite->pos1.x == 0x78)
        sprite->data[1] = 0;
    sprite->data[0] += sprite->data[4];
    if (sprite->data[3] == 4)
    {
        sprite->data[7] = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_807E5D8(struct Sprite *sprite)
{
    sprite->pos2.y += gTradeBallVerticalVelocityTable[sprite->data[0]];
    if (sprite->data[0] == 22)
        PlaySE(SE_KON);
    if (++ sprite->data[0] == 44)
    {
        PlaySE(SE_W025);
        sprite->callback = sub_807E64C;
        sprite->data[0] = 0;
        BeginNormalPaletteFade(1 << (16 + sprite->oam.paletteNum), -1, 0, 16, RGB_WHITEALPHA);
    }
}

static void sub_807E64C(struct Sprite *sprite)
{
    if (sprite->data[1] == 20)
        StartSpriteAffineAnim(sprite, 1);
    if (++ sprite->data[1] > 20)
    {
        sprite->pos2.y -= gTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++ sprite->data[0] == 23)
        {
            DestroySprite(sprite);
            sTradeData->state = 14; // Resume the master trade animation
        }
    }
}

static void sub_807E6AC(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->pos1.y += 4) > sprite->data[3])
        {
            sprite->data[2] ++;
            sprite->data[0] = 0x16;
            PlaySE(SE_KON);
        }
    }
    else
    {
        if (sprite->data[0] == 0x42)
            PlaySE(SE_KON2);
        if (sprite->data[0] == 0x5c)
            PlaySE(SE_KON3);
        if (sprite->data[0] == 0x6b)
            PlaySE(SE_KON4);
        sprite->pos2.y += gTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++sprite->data[0] == 0x6c)
            sprite->callback = SpriteCallbackDummy;
    }
}

u16 GetInGameTradeSpeciesInfo(void)
{
    const struct InGameTrade *inGameTrade = &sIngameTrades[gSpecialVar_0x8004];
    StringCopy(gStringVar1, gSpeciesNames[inGameTrade->requestedSpecies]);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
    return inGameTrade->requestedSpecies;
}

static void sub_807E784(void)
{
    u8 nickname[32];
    const struct InGameTrade *inGameTrade = &sIngameTrades[gSpecialVar_0x8004];
    GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, nickname);
    StringCopy10(gStringVar1, nickname);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
}

static void _CreateInGameTradePokemon(u8 whichPlayerMon, u8 whichInGameTrade)
{
    const struct InGameTrade *inGameTrade = &sIngameTrades[whichInGameTrade];
    u8 level = GetMonData(&gPlayerParty[whichPlayerMon], MON_DATA_LEVEL);

    struct MailStruct mail;
    u8 metLocation = METLOC_IN_GAME_TRADE;
    u8 isMail;
    struct Pokemon *pokemon = &gEnemyParty[0];

    CreateMon(pokemon, inGameTrade->species, level, 32, TRUE, inGameTrade->personality, OT_ID_PRESET, inGameTrade->otId);

    SetMonData(pokemon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(pokemon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(pokemon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(pokemon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(pokemon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(pokemon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(pokemon, MON_DATA_NICKNAME, inGameTrade->nickname);
    SetMonData(pokemon, MON_DATA_OT_NAME, inGameTrade->otName);
    SetMonData(pokemon, MON_DATA_OT_GENDER, &inGameTrade->otGender);
    SetMonData(pokemon, MON_DATA_ABILITY_NUM, &inGameTrade->abilityNum);
    SetMonData(pokemon, MON_DATA_BEAUTY, &inGameTrade->conditions[1]);
    SetMonData(pokemon, MON_DATA_CUTE, &inGameTrade->conditions[2]);
    SetMonData(pokemon, MON_DATA_COOL, &inGameTrade->conditions[0]);
    SetMonData(pokemon, MON_DATA_SMART, &inGameTrade->conditions[3]);
    SetMonData(pokemon, MON_DATA_TOUGH, &inGameTrade->conditions[4]);
    SetMonData(pokemon, MON_DATA_SHEEN, &inGameTrade->sheen);
    SetMonData(pokemon, MON_DATA_MET_LOCATION, &metLocation);

    isMail = FALSE;
    if (inGameTrade->heldItem != ITEM_NONE)
    {
        if (ItemIsMail(inGameTrade->heldItem))
        {
            SetInGameTradeMail(&mail, inGameTrade);
            gUnknown_020321C0[0] = mail;
            SetMonData(pokemon, MON_DATA_MAIL, &isMail);
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
        else
        {
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
    }
    CalculateMonStats(&gEnemyParty[0]);
}

static void SetInGameTradeMail(struct MailStruct *mail, const struct InGameTrade *trade) {
    s32 i;

    for (i = 0; i < INGAME_TRADE_MAIL_LENGTH; i++)
    {
        mail->words[i] = sIngameTradeMail[trade->mailNum][i];
    }

    StringCopy(mail->playerName, trade->otName);
    PadNameString(mail->playerName, CHAR_SPACE);

    mail->trainerId[0] = trade->otId >> 24;
    mail->trainerId[1] = trade->otId >> 16;
    mail->trainerId[2] = trade->otId >> 8;
    mail->trainerId[3] = trade->otId;
    mail->species = trade->species;
    mail->itemId = trade->heldItem;
}

u16 GetTradeSpecies(void)
{
    if (GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_IS_EGG))
        return SPECIES_NONE;
    return GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_SPECIES);
}

void CreateInGameTradePokemon(void)
{
    _CreateInGameTradePokemon(gSpecialVar_0x8005, gSpecialVar_0x8004);
}

static void sub_807EA2C(void)
{
    if (sub_807BBC8() == TRUE)
    {
        DestroySprite(&gSprites[sTradeData->pokePicSpriteIdxs[0]]);
        FreeSpriteOamMatrix(&gSprites[sTradeData->pokePicSpriteIdxs[1]]);
        sub_807B4D0(gSelectedTradeMonPositions[TRADE_PLAYER], gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE);
        if (!sub_8077260())
        {
            sTradeData->linkData[0] = 0xABCD;
            sTradeData->unk_93 = 1;
        }
        SetMainCallback2(sub_807EACC);
    }
    sub_807B5B8();
    sub_807E4DC();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807EACC(void)
{
    u8 mpId = sub_807ACDC();
    if (sub_8077260())
    {
        SetMainCallback2(c2_08053788);
    }
    else
    {
        sub_807E4DC();
        if (mpId == 0 && sTradeData->unk_72 == 1 && sTradeData->unk_73 == 1)
        {
            sTradeData->linkData[0] = 0xDCBA;
            Trade_SendData(sTradeData);
            sTradeData->unk_72 = 2;
            sTradeData->unk_73 = 2;
        }
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807EB50(void)
{
    switch (gMain.state)
    {
        case 0:
            gMain.state++;
            StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            break;
        case 1:
            sub_8077288(0);
            gMain.state = 100;
            sTradeData->timer = 0;
            break;
        case 100:
            if (++sTradeData->timer > 180)
            {
                gMain.state = 101;
                sTradeData->timer = 0;
            }
            if (_IsLinkTaskFinished())
            {
                gMain.state = 2;
            }
            break;
        case 101:
            if (_IsLinkTaskFinished())
            {
                gMain.state = 2;
            }
            break;
        case 2:
            gMain.state = 50;
            StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            break;
        case 50:
            if (!InUnionRoom())
                IncrementGameStat(GAME_STAT_POKEMON_TRADES);
            if (gWirelessCommType)
            {
                sub_801B990(2, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);
            }
            SetContinueGameWarpStatusToDynamicWarp();
            sub_8153380();
            gMain.state++;
            sTradeData->timer = 0;
            break;
        case 51:
            if (++sTradeData->timer == 5)
            {
                gMain.state++;
            }
            break;
        case 52:
            if (sub_81533AC())
            {
                ClearContinueGameWarpStatus2();
                gMain.state = 4;
            }
            else
            {
                sTradeData->timer = 0;
                gMain.state = 51;
            }
            break;
        case 4:
            sub_81533E0();
            gMain.state = 40;
            sTradeData->timer = 0;
            break;
        case 40:
            if (++sTradeData->timer > 50)
            {
                if (GetMultiplayerId() == 0)
                {
                    sTradeData->timer = Random() % 30;
                }
                else
                {
                    sTradeData->timer = 0;
                }
                gMain.state = 41;
            }
            break;
        case 41:
            if (sTradeData->timer == 0)
            {
                sub_8077288(1);
                gMain.state = 42;
            }
            else
            {
                sTradeData->timer--;
            }
            break;
        case 42:
            if (_IsLinkTaskFinished())
            {
                sub_8153408();
                gMain.state = 5;
            }
            break;
        case 5:
            if (++sTradeData->timer > 60)
            {
                gMain.state++;
                sub_8077288(2);
            }
            break;
        case 6:
            if (_IsLinkTaskFinished())
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gMain.state ++;
            }
            break;
        case 7:
            if (!gPaletteFade.active)
            {
                FadeOutBGM(3);
                gMain.state++;
            }
            break;
        case 8:
            if (IsBGMStopped() == TRUE)
            {
                if (gWirelessCommType && gMain.savedCallback == sub_80773AC)
                {
                    sub_8077288(3);
                }
                else
                {
                    sub_800AC34();
                }
                gMain.state++;
            }
            break;
        case 9:
            if (gWirelessCommType && gMain.savedCallback == sub_80773AC)
            {
                if (_IsLinkTaskFinished())
                {
                    gSoftResetDisabled = FALSE;
                    SetMainCallback2(c2_080543C4);
                }
            }
            else if (!gReceivedRemoteLinkPlayers)
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(c2_080543C4);
            }
            break;
    }
    if (!HasLinkErrorOccurred())
    {
        RunTasks();
    }
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void c2_080543C4(void)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        Free(GetBgTilemapBuffer(3));
        Free(GetBgTilemapBuffer(1));
        Free(GetBgTilemapBuffer(0));
        FreeMonSpritesGfx();
        FREE_AND_SET_NULL(sTradeData);
        if (gWirelessCommType)
            DestroyWirelessStatusIndicatorSprite();
        SetMainCallback2(gMain.savedCallback);
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoInGameTradeScene(void)
{
    ScriptContext2_Enable();
    CreateTask(sub_807F110, 10);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
}

static void sub_807F110(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sub_807B270);
        gFieldCallback = FieldCallback_ReturnToEventScript2;
        DestroyTask(taskId);
    }
}

static void CheckPartnersMonForRibbons(void)
{
    u8 i;
    u8 numRibbons = 0;
    for (i = 0; i < 12; i ++) //TODO: MON_DATA_GIFT_RIBBON_7 - (MON_DATA_CHAMPION_RIBBON - 1)
    {
        numRibbons += GetMonData(&gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE], MON_DATA_CHAMPION_RIBBON + i);
    }
    if (numRibbons != 0)
        FlagSet(FLAG_SYS_RIBBON_GET);
}

void sub_807F19C(void)
{
    sub_807B170();
}

void DrawTextOnTradeWindow(u8 windowId, const u8 *str, u8 speed)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(15));
    sTradeData->textColors[0] = TEXT_DYNAMIC_COLOR_6;
    sTradeData->textColors[1] = TEXT_COLOR_WHITE;
    sTradeData->textColors[2] = TEXT_COLOR_GREEN;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, sTradeData->textColors, speed, str);
    CopyWindowToVram(windowId, 3);
}

static void c3_08054588(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 unk = gUnknown_08339090[data[0]][0] * 16;

    if (!data[2])
    {
        if (unk == 0x100)
            LoadPalette(sTradePal_Black, 0x30, 32);
        else
            LoadPalette(&sTradePal_WirelessSignalSend[unk], 0x30, 32);
    }
    else
    {
        if (unk == 0x100)
            LoadPalette(sTradePal_Black, 0x30, 32);
        else
            LoadPalette(&sTradePal_WirelessSignalReceive[unk], 0x30, 32);
    }

    if (gUnknown_08339090[data[0]][0] == 0 && data[1] == 0)
        PlaySE(SE_W215);

    if (data[1] == gUnknown_08339090[data[0]][1])
    {
        data[0]++;
        data[1] = 0;
        if (gUnknown_08339090[data[0]][1] == 0xFF)
        {
            DestroyTask(taskId);
        }
    }
    else
    {
        data[1]++;
    }
}

static void c3_0805465C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        sTradeData->unk_FB = sTradeData->unk_FD = 120;
        sTradeData->unk_FC = 0;
        sTradeData->unk_FE = 160;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(sTradeData->unk_FB, sTradeData->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(sTradeData->unk_FC, sTradeData->unk_FE));

    data[0]++;
    sTradeData->unk_FB -= 5;
    sTradeData->unk_FD += 5;

    if (sTradeData->unk_FB < 80)
    {
        DestroyTask(taskId);
    }
}

static void sub_807F39C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        sTradeData->unk_FB = 80;
        sTradeData->unk_FD = 160;
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(sTradeData->unk_FB, sTradeData->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(sTradeData->unk_FC, sTradeData->unk_FE));

    if (sTradeData->unk_FB != 120)
    {
        data[0]++;
        sTradeData->unk_FB += 5;
        sTradeData->unk_FD -= 5;

        if (sTradeData->unk_FB >= 116)
            BlendPalettes(0x8, 0, RGB_WHITEALPHA);
    }
    else
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
    }
}

static void sub_807F464(void)
{
    switch (gMain.state)
    {
        case 0:
            gMain.state = 1;
            StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            break;
        case 1:
            sub_8077288(0);
            gMain.state = 2;
            sTradeData->timer = 0;
            break;
        case 2:
            if (_IsLinkTaskFinished())
            {
                gMain.state = 3;
                StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
                IncrementGameStat(GAME_STAT_POKEMON_TRADES);
                sub_8153380();
                sTradeData->timer = 0;
            }
            break;
        case 3:
            if (++sTradeData->timer == 5)
            {
                gMain.state = 4;
            }
            break;
        case 4:
            if (sub_81533AC())
            {
                gMain.state = 5;
            }
            else
            {
                sTradeData->timer = 0;
                gMain.state = 3;
            }
            break;
        case 5:
            sub_81533E0();
            gMain.state = 6;
            sTradeData->timer = 0;
            break;
        case 6:
            if (++sTradeData->timer > 10)
            {
                if (GetMultiplayerId() == 0)
                {
                    sTradeData->timer = Random() % 30;
                }
                else
                {
                    sTradeData->timer = 0;
                }
                gMain.state = 7;
            }
            break;
        case 7:
            if (sTradeData->timer == 0)
            {
                sub_8077288(1);
                gMain.state = 8;
            }
            else
            {
                sTradeData->timer--;
            }
            break;
        case 8:
            if (_IsLinkTaskFinished())
            {
                sub_8153408();
                gMain.state = 9;
            }
            break;
        case 9:
            if (++sTradeData->timer > 60)
            {
                gMain.state++;
                sub_8077288(2);
            }
            break;
        case 10:
            if (_IsLinkTaskFinished())
            {
                FadeOutBGM(3);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gMain.state = 11;
            }
            break;
        case 11:
            if (!gPaletteFade.active && IsBGMStopped() == TRUE)
            {
                sub_8077288(3);
                gMain.state = 12;
            }
            break;
        case 12:
            if (_IsLinkTaskFinished())
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(c2_080543C4);
            }
            break;
    }

    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
