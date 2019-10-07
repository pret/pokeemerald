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

static EWRAM_DATA u8 *sMessageBoxAllocBuffer = NULL;

// Bytes 0-2 are used for the player's name box
// Bytes 3-5 are used for the partner's name box
// Bytes 6-7 are used for the Cancel box
// Bytes 8-13 are used for the Choose a Pokemon box
static EWRAM_DATA u8 *sMessageBoxTileBuffers[14] = {NULL};

EWRAM_DATA struct MailStruct gTradeMail[PARTY_SIZE] = {0};
EWRAM_DATA u8 gSelectedTradeMonPositions[2] = {0};
static EWRAM_DATA struct {
    /*0x0000*/ u8 bg2hofs;
    /*0x0001*/ u8 bg3hofs;
    /*0x0002*/ u8 filler_2[0x28 - 2];
    /*0x0028*/ u8 partySpriteIds[2][PARTY_SIZE];
    /*0x0034*/ u8 cursorSpriteIdx;
    /*0x0035*/ u8 cursorPosition;
    /*0x0036*/ u8 partyCounts[2];
    /*0x0038*/ bool8 monPresent[PARTY_SIZE * 2];
    /*0x0044*/ u8 neverRead_44;
    /*0x0045*/ bool8 isLiveMon[2][PARTY_SIZE];
    /*0x0051*/ bool8 isEgg[2][PARTY_SIZE];
    /*0x005D*/ u8 hpBarLevels[2][PARTY_SIZE];
    /*0x0069*/ u8 unk_69; //state var for shedinja_maker_maybe
    /*0x006A*/ u8 filler_6A[0x6F - 0x6A];
    /*0x006F*/ u8 tradeMenuFunc; //switch var for sub_80795AC
    /*0x0070*/ u8 neverRead_70;
    /*0x0071*/ u8 filler_71;
    /*0x0072*/ u16 unk_72; //sheet
    /*0x0074*/ u8 drawPartyState[2];
    /*0x0076*/ u8 selectedMonIdx[2];
    /*0x0078*/ u8 playerLinkFlagChoseAction;
    /*0x0079*/ u8 partnerLinkFlagChoseAction;
    /*0x007A*/ u8 playerLinkFlagChoseMon;
    /*0x007B*/ u8 partnerLinkFlagChoseMon;
    /*0x007C*/ u8 filler_7C[0x7E - 0x7C];
    /*0x007E*/ u8 partnerCursorPosition;
    /*0x007F*/ u8 unused_7F;
    /*0x0080*/ u16 linkData[20];
    /*0x00A8*/ u8 timer;
    /*0x00A9*/ u8 giftRibbons[11];
    /*0x00B4*/ u8 filler_B4[0x8D0-0xB4];
    /*0x08D0*/ struct {
        bool8 queued;
        u16 queueDelay;
        u8 actionId;
    } queuedActions[4];
    /*0x08F0*/ u16 tilemapBuffer[0x400];
} *sTradeData = {NULL};
static EWRAM_DATA struct {
    /*0x00*/ struct Pokemon mon;
    /*0x64*/ u32 timer;
    /*0x68*/ u32 monPersonalities[2];
    /*0x70*/ u8 filler_70[2];
    /*0x72*/ u8 unk_72;
    /*0x73*/ u8 unk_73;
    /*0x74*/ u16 linkData[10];
    /*0x88*/ u8 alwaysZero_88;
    /*0x89*/ u8 alwaysZero_89;
    /*0x8A*/ u16 linkTimeoutCounter;
    /*0x8C*/ u16 neverRead_8C;
    /*0x8E*/ u8 pokePicSpriteIdxs[2];
    /*0x90*/ u8 unk_90; //sprite id
    /*0x91*/ u8 unk_91; //sprite id
    /*0x92*/ u8 unk_92; //sprite id
    /*0x93*/ u8 unk_93;
    /*0x94*/ u16 state;
    /*0x96*/ u8 filler_96[0xD2 - 0x96];
    /*0xD2*/ u8 unk_D2; //sprite id
    /*0xD3*/ u8 unk_D3; //sprite id
    /*0xD4*/ u16 texX;
    /*0xD6*/ u16 texY;
    /*0xD8*/ u16 neverRead_D8;
    /*0xDA*/ u16 neverRead_DA;
    /*0xDC*/ u16 scrX;
    /*0xDE*/ u16 scrY;
    /*0xE0*/ s16 bg1vofs;
    /*0xE2*/ s16 bg1hofs;
    /*0xE4*/ s16 bg2vofs;
    /*0xE6*/ s16 bg2hofs;
    /*0xE8*/ u16 sXY;
    /*0xEA*/ u16 unk_EA; //sXY divisor
    /*0xEC*/ u16 alpha;
    /*0xEE*/ bool8 isLinkTrade;
    /*0xF0*/ u16 monSpecies[2];
    /*0xF4*/ u16 cachedMapMusic;
    /*0xF6*/ u8 textColors[3];
    /*0xF9*/ u8 filler_F9;
    /*0xFA*/ bool8 isCableTrade;
    /*0xFB*/ u8 unk_FB;
    /*0xFC*/ u8 unk_FC;
    /*0xFD*/ u8 unk_FD;
    /*0xFE*/ u8 unk_FE;
} *sTradeWindowData = {NULL};

#if !defined(NONMATCHING) && MODERN
#define static
#endif
static bool32 IsWirelessTrade(void);
static void sub_80773D0(void);
static void sub_807811C(void);
static void CB2_TradeMenu(void);
static void sub_80782B8(u8);
static void SetTradePartyMonsVisible(void);
static bool8 shedinja_maker_maybe(void);
static void sub_8078C34(void);
static void sub_80795AC(void);
static void SetSelectedMon(u8);
static void DrawTradeMenuParty(u8);
static u8 GetMonNicknameWidth(u8 *, u8, u8);
static void BufferTradeMonMoves(u8 *, u8, u8);
static void PrintPartyNicknamesForTradeMenu(u8);
static void DrawTradeMenuPartyMonInfo(u8, u8, u8, u8, u8, u8);
static void sub_8079E44(u8);
static void sub_8079F74(void);
static void RedrawTradeMenuParty(u8);
static void sub_807A000(u8 taskId);
static void sub_807A024(u8 taskId);
static void QueueAction(u16, u8);
static u32 GetNumQueuedActions(void);
static void DoQueuedActions(void);
static void PrintTradeMessage(u8);
static bool8 LoadTradeMenuSpriteSheetsAndPalettes(void);
static void DrawTextWindowAndBuffer6Bytes(const u8 *, u8 *, u8);
static void SetTradePartyLiveStatuses(u8);
static void GetTradePartyHPBarLevels(u8);
static void SetTradePartyHPBarSprites(void);
static void sub_807A5B0(void);
static u32 CanTradeSelectedMon(struct Pokemon *, int, int);
static void sub_807AA28(struct Sprite *sprite);
static void sub_807AA7C(struct Sprite *sprite);
static void sub_807AABC(struct Sprite *sprite);
static void sub_807AAE0(struct Sprite *sprite);
static void sub_807AB04(struct Sprite *sprite);
static void InitTradeBgInternal(void);
static void sub_807B60C(void);
static void sub_807B62C(u8);
static void LoadTradeSequenceSpriteSheetsAndPalettes(void);
static void SetTradeSceneStrings(void);
static bool8 AnimateTradeSequence(void);
static bool8 AnimateTradeSequenceCable(void);
static bool8 AnimateTradeSequenceWireless(void);
static void sub_807E55C(struct Sprite *sprite);
static void sub_807E5D8(struct Sprite *sprite);
static void sub_807E64C(struct Sprite *sprite);
static void sub_807E6AC(struct Sprite *sprite);
static void BuffeInGameTradeMonName(void);
static void SetInGameTradeMail(struct MailStruct *mail, const struct InGameTrade *trade);
static void sub_807EA2C(void);
static void sub_807EACC(void);
static void sub_807EB50(void);
static void c2_080543C4(void);
static void Task_InGameTrade(u8);
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
            return TRUE;
        else
            return FALSE;
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

static void TradeResetReceivedFlags(void)
{
    if (IsWirelessTrade())
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    else
        ResetBlockReceivedFlags();
}

static void TradeResetReceivedFlag(u32 who)
{
    if (IsWirelessTrade())
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    else
        ResetBlockReceivedFlag(who);
}

static bool32 IsWirelessTrade(void)
{
    if (gWirelessCommType && gUnknown_02022C2C == 29)
        return TRUE;
    else
        return FALSE;
}

static void sub_8077288(u8 unused)
{
    sub_800ADF8();
}

static bool32 _IsLinkTaskFinished(void)
{
    return IsLinkTaskFinished();
}

static void InitTradeMenu(void)
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
    InitBgsFromTemplates(0, sTradeMenuBgTemplates, ARRAY_COUNT(sTradeMenuBgTemplates));
    SetBgTilemapBuffer(1, sTradeData->tilemapBuffer);

    if (InitWindows(sTradeMenuWindowTemplates))
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
        sTradeData->unk_69 = 0;
        sTradeData->tradeMenuFunc = 0;
        sTradeData->neverRead_70 = 0;
        sTradeData->drawPartyState[TRADE_PLAYER] = 0;
        sTradeData->drawPartyState[TRADE_PARTNER] = 0;
        sTradeData->playerLinkFlagChoseMon = 0;
        sTradeData->partnerLinkFlagChoseMon = 0;
        sTradeData->timer = 0;
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
        sTradeData = AllocZeroed(sizeof(*sTradeData));
        InitTradeMenu();
        sMessageBoxAllocBuffer = AllocZeroed(14 * 256);

        for (i = 0; i < (int)ARRAY_COUNT(sMessageBoxTileBuffers); i++)
        {
            sMessageBoxTileBuffers[i] = &sMessageBoxAllocBuffer[i * 256];
        }

        gMain.state++;
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = FALSE;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, 32, FALSE, 0, OT_ID_PLAYER_ID, 0);
        }

        PrintTradeMessage(TRADE_MSG_STANDBY);
        ShowBg(0);

        if (!gReceivedRemoteLinkPlayers)
        {
            gLinkType = 0x1122;
            sTradeData->timer = 0;

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
        sTradeData->timer++;
        if (sTradeData->timer > 11)
        {
            sTradeData->timer = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
        {
            if (IsLinkMaster())
            {
                if (++sTradeData->timer > 30)
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
            sTradeData->timer = 0;
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
        sTradeData->partyCounts[TRADE_PLAYER] = gPlayerPartyCount;
        sTradeData->partyCounts[TRADE_PARTNER] = gEnemyPartyCount;

        for (i = 0; i < sTradeData->partyCounts[TRADE_PLAYER]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            sTradeData->partySpriteIds[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < sTradeData->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeData->partySpriteIds[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
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
        DrawHeldItemIconsForTrade(&sTradeData->partyCounts[TRADE_PLAYER], sTradeData->partySpriteIds[TRADE_PLAYER], TRADE_PLAYER);
        gMain.state++;
        break;
    case 9:
        DrawHeldItemIconsForTrade(&sTradeData->partyCounts[TRADE_PLAYER], sTradeData->partySpriteIds[TRADE_PLAYER], TRADE_PARTNER);
        gMain.state++;
        break;
    case 10:
        DrawTextWindowAndBufferTiles(gSaveBlock2Ptr->playerName, sMessageBoxTileBuffers[0], 0, 0, 3);
        id = GetMultiplayerId();
        DrawTextWindowAndBufferTiles(gLinkPlayers[id ^ 1].name, sMessageBoxTileBuffers[3], 0, 0, 3);
        DrawTextWindowAndBufferTiles(sTradeActionTexts[TRADE_ACTION_TEXT_CANCEL], sMessageBoxTileBuffers[6], 0, 0, 2);
        DrawTextWindowAndBuffer6Bytes(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], sMessageBoxTileBuffers[8], 24);
        gMain.state++;
        sTradeData->timer = 0;
        break;
    case 11:
        if (LoadTradeMenuSpriteSheetsAndPalettes())
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

        sTradeData->cursorSpriteIdx = CreateSprite(&gSpriteTemplate_832DC94, gTradeMonSpriteCoords[0][0] * 8 + 32, gTradeMonSpriteCoords[0][1] * 8, 2);
        sTradeData->cursorPosition = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        SetTradePartyLiveStatuses(TRADE_PLAYER);
        PrintPartyNicknamesForTradeMenu(TRADE_PLAYER);
        sTradeData->bg2hofs = 0;
        sTradeData->bg3hofs = 0;
        SetTradePartyMonsVisible();
        gMain.state++;
        PlayBGM(MUS_P_SCHOOL);
        break;
    case 15:
        SetTradePartyLiveStatuses(TRADE_PARTNER);
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
            SetMainCallback2(CB2_TradeMenu);
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
        InitTradeMenu();
        gMain.state++;
        break;
    case 1:
        gMain.state++;
        sTradeData->timer = 0;
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
        sTradeData->partyCounts[TRADE_PLAYER] = gPlayerPartyCount;
        sTradeData->partyCounts[TRADE_PARTNER] = gEnemyPartyCount;
        ClearWindowTilemap(0);
        PrintPartyNicknamesForTradeMenu(TRADE_PLAYER);
        PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);

        for (i = 0; i < sTradeData->partyCounts[TRADE_PLAYER]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            sTradeData->partySpriteIds[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < sTradeData->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeData->partySpriteIds[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
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
        DrawHeldItemIconsForTrade(&sTradeData->partyCounts[TRADE_PLAYER], sTradeData->partySpriteIds[TRADE_PLAYER], TRADE_PLAYER);
        gMain.state++;
        break;
    case 9:
        DrawHeldItemIconsForTrade(&sTradeData->partyCounts[TRADE_PLAYER], sTradeData->partySpriteIds[TRADE_PLAYER], TRADE_PARTNER);
        gMain.state++;
        break;
    case 10:
        DrawTextWindowAndBufferTiles(gSaveBlock2Ptr->playerName, sMessageBoxTileBuffers[0], 0, 0, 3);
        id = GetMultiplayerId();
        DrawTextWindowAndBufferTiles(gLinkPlayers[id ^ 1].name, sMessageBoxTileBuffers[3], 0, 0, 3);
        DrawTextWindowAndBufferTiles(sTradeActionTexts[TRADE_ACTION_TEXT_CANCEL], sMessageBoxTileBuffers[6], 0, 0, 2);
        DrawTextWindowAndBuffer6Bytes(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], sMessageBoxTileBuffers[8], 24);
        gMain.state++;
        sTradeData->timer = 0;
        break;
    case 11:
        if (LoadTradeMenuSpriteSheetsAndPalettes())
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

        if (sTradeData->cursorPosition < PARTY_SIZE)
            sTradeData->cursorPosition = gLastViewedMonIndex;
        else
            sTradeData->cursorPosition = gLastViewedMonIndex + PARTY_SIZE;

        sTradeData->cursorSpriteIdx = CreateSprite(&gSpriteTemplate_832DC94, gTradeMonSpriteCoords[sTradeData->cursorPosition][0] * 8 + 32, gTradeMonSpriteCoords[sTradeData->cursorPosition][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        sTradeData->bg2hofs = 0;
        sTradeData->bg3hofs = 0;
        SetTradePartyMonsVisible();
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
            SetMainCallback2(CB2_TradeMenu);
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
    if (++sTradeData->timer > 15)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sTradeData->tradeMenuFunc = 10;
    }
}

static void sub_807816C(void)
{
    if (!gPaletteFade.active)
    {
        gSelectedTradeMonPositions[TRADE_PLAYER] = sTradeData->cursorPosition;
        gSelectedTradeMonPositions[TRADE_PARTNER] = sTradeData->partnerCursorPosition;

        if (gWirelessCommType)
        {
            sTradeData->tradeMenuFunc = 16;
        }
        else
        {
            sub_800ABF4(32);
            sTradeData->tradeMenuFunc = 13;
        }
    }
}

static void sub_80781C8(void)
{
    gMain.savedCallback = sub_80773AC;

    // Wireless Link Trade
    if (gWirelessCommType)
    {
        if (sub_8010500())
        {
            Free(sMessageBoxAllocBuffer);
            FreeAllWindowBuffers();
            Free(sTradeData);
            gMain.callback1 = NULL;
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(CB2_LinkTrade);
        }
    }
    // Cable Link Trade
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(sMessageBoxAllocBuffer);
            FreeAllWindowBuffers();
            Free(sTradeData);
            gMain.callback1 = NULL;
            SetMainCallback2(CB2_LinkTrade);
        }
    }
}

static void CB2_TradeMenu(void)
{
    sub_80795AC(); //func switch
    DoQueuedActions();
    DrawTradeMenuParty(TRADE_PLAYER);
    DrawTradeMenuParty(TRADE_PARTNER);

    SetGpuReg(REG_OFFSET_BG2HOFS, sTradeData->bg2hofs++);
    SetGpuReg(REG_OFFSET_BG3HOFS, sTradeData->bg3hofs--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_80782B8(u8 state)
{
    int i;

    switch (state)
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

static void SetTradePartyMonsVisible(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i < sTradeData->partyCounts[TRADE_PLAYER])
        {
            gSprites[sTradeData->partySpriteIds[TRADE_PLAYER][i]].invisible = FALSE;
            sTradeData->monPresent[i] = TRUE;
        }
        else
        {
            sTradeData->monPresent[i] = FALSE;
        }

        if (i < sTradeData->partyCounts[TRADE_PARTNER])
        {
            gSprites[sTradeData->partySpriteIds[TRADE_PARTNER][i]].invisible = FALSE;
            sTradeData->monPresent[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            sTradeData->monPresent[i + PARTY_SIZE] = FALSE;
        }
    }

    sTradeData->neverRead_44 = 1;
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

    switch (sTradeData->unk_69)
    {
    case 0:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[0], 2 * sizeof(struct Pokemon));
        sTradeData->unk_69++;
        sTradeData->timer = 0;
        break;
    case 1:
        if (sub_80771BC())
        {
            if (_GetBlockReceivedStatus() == 0)
            {
                sTradeData->unk_69++;
            }
            else
            {
                TradeResetReceivedFlags();
                sTradeData->unk_69++;
            }
        }
        break;
    case 3:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        sTradeData->unk_69++;
        break;
    case 4:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[0], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeData->unk_69++;
        }
        break;
    case 5:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[2], 2 * sizeof(struct Pokemon));
        sTradeData->unk_69++;
        break;
    case 7:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        sTradeData->unk_69++;
        break;
    case 8:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[2], gBlockRecvBuffer[id ^ 1], 200);
            TradeResetReceivedFlags();
            sTradeData->unk_69++;
        }
        break;
    case 9:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[4], 200);
        sTradeData->unk_69++;
        break;
    case 11:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        sTradeData->unk_69++;
        break;
    case 12:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[4], gBlockRecvBuffer[id ^ 1], 200);
            TradeResetReceivedFlags();
            sTradeData->unk_69++;
        }
        break;
    case 13:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->mail, 220);
        sTradeData->unk_69++;
        break;
    case 15:
        if (id == 0)
        {
            sub_80771AC(3);
        }
        sTradeData->unk_69++;
        break;
    case 16:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(gTradeMail, gBlockRecvBuffer[id ^ 1], 216);
            TradeResetReceivedFlags();
            sTradeData->unk_69++;
        }
        break;
    case 17:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, ARRAY_COUNT(sTradeData->giftRibbons));
        sTradeData->unk_69++;
        break;
    case 19:
        if (id == 0)
        {
            sub_80771AC(4);
        }
        sTradeData->unk_69++;
        break;
    case 20:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(sTradeData->giftRibbons, gBlockRecvBuffer[id ^ 1], ARRAY_COUNT(sTradeData->giftRibbons));
            TradeResetReceivedFlags();
            sTradeData->unk_69++;
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
        sTradeData->timer++;
        if (sTradeData->timer > 10)
        {
            sTradeData->timer = 0;
            sTradeData->unk_69++;
        }
        break;
    }
    return FALSE;
}

static void PrintAndBufferIsThisTradeOkay(void)
{
    DrawTextWindowAndBuffer6Bytes(gText_IsThisTradeOkay, (void *)(OBJ_VRAM0 + (sTradeData->unk_72 * 32)), 24);
}

static void UpdateLinkFlags(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEAA:
            sTradeData->playerLinkFlagChoseAction = WANTS_TO_CANCEL;
            break;
        case 0xAABB:
            sTradeData->playerLinkFlagChoseAction = WANTS_TO_TRADE;
            break;
        case 0xBBBB:
            sTradeData->playerLinkFlagChoseMon = CHOSE_VALID_MON;
            break;
        case 0xBBCC:
            sTradeData->playerLinkFlagChoseMon = CHOSE_INVALID_MON;
            break;
        }
        TradeResetReceivedFlag(TRADE_PLAYER);
    }

    if (a1 & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case 0xEEAA:
            sTradeData->partnerLinkFlagChoseAction = WANTS_TO_CANCEL;
            break;
        case 0xAABB:
            sTradeData->partnerCursorPosition = gBlockRecvBuffer[1][1] + 6;
            sTradeData->partnerLinkFlagChoseAction = WANTS_TO_TRADE;
            break;
        case 0xBBBB:
            sTradeData->partnerLinkFlagChoseMon = CHOSE_VALID_MON;
            break;
        case 0xBBCC:
            sTradeData->partnerLinkFlagChoseMon = CHOSE_INVALID_MON;
            break;
        }
        TradeResetReceivedFlag(TRADE_PARTNER);
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
            sTradeData->tradeMenuFunc = 11;
            break;
        case 0xEECC:
            PrintTradeMessage(TRADE_MSG_FRIEND_WANTS_TO_TRADE);
            sTradeData->tradeMenuFunc = 8;
            break;
        case 0xDDDD:
            sTradeData->partnerCursorPosition = gBlockRecvBuffer[0][1] + 6;
            rbox_fill_rectangle(0);
            SetSelectedMon(sTradeData->cursorPosition);
            SetSelectedMon(sTradeData->partnerCursorPosition);
            sTradeData->tradeMenuFunc = 7;
            break;
        case 0xCCDD:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->tradeMenuFunc = 10;
            break;
        case 0xDDEE:
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeData->tradeMenuFunc = 8;
        }
        TradeResetReceivedFlag(TRADE_PLAYER);
    }

    if (a1 & 2)
        TradeResetReceivedFlag(TRADE_PARTNER);
}

// TODO: SetLinkData with additional steps
static void sub_80789FC(void)
{
    if (sTradeData->playerLinkFlagChoseAction && sTradeData->partnerLinkFlagChoseAction)
    {
        if (sTradeData->playerLinkFlagChoseAction == WANTS_TO_TRADE 
            && sTradeData->partnerLinkFlagChoseAction == WANTS_TO_TRADE)
        {
            sTradeData->tradeMenuFunc = 6;
            sTradeData->linkData[0] = 0xDDDD;
            sTradeData->linkData[1] = sTradeData->cursorPosition;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeData->playerLinkFlagChoseAction = sTradeData->partnerLinkFlagChoseAction = 0;
        }
        else if (sTradeData->playerLinkFlagChoseAction == WANTS_TO_TRADE 
              && sTradeData->partnerLinkFlagChoseAction == WANTS_TO_CANCEL)
        {
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeData->linkData[0] = 0xEECC;
            sTradeData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeData->playerLinkFlagChoseMon = sTradeData->partnerLinkFlagChoseMon = 0;
            sTradeData->playerLinkFlagChoseAction = sTradeData->partnerLinkFlagChoseAction = 0;
            sTradeData->tradeMenuFunc = 8;
        }
        else if (sTradeData->playerLinkFlagChoseAction == WANTS_TO_CANCEL 
              && sTradeData->partnerLinkFlagChoseAction == WANTS_TO_TRADE)
        {
            PrintTradeMessage(TRADE_MSG_FRIEND_WANTS_TO_TRADE);
            sTradeData->linkData[0] = 0xDDEE;
            sTradeData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeData->playerLinkFlagChoseMon = sTradeData->partnerLinkFlagChoseMon = 0;
            sTradeData->playerLinkFlagChoseAction = sTradeData->partnerLinkFlagChoseAction = 0;
            sTradeData->tradeMenuFunc = 8;
        }
        else if (sTradeData->playerLinkFlagChoseAction == WANTS_TO_CANCEL 
              && sTradeData->partnerLinkFlagChoseAction == WANTS_TO_CANCEL)
        {
            sTradeData->linkData[0] = 0xEEBB;
            sTradeData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->playerLinkFlagChoseAction = sTradeData->partnerLinkFlagChoseAction = 0;
            sTradeData->tradeMenuFunc = 11;
        }
    }

    if (sTradeData->playerLinkFlagChoseMon && sTradeData->partnerLinkFlagChoseMon)
    {
        if (sTradeData->playerLinkFlagChoseMon == CHOSE_VALID_MON 
         && sTradeData->partnerLinkFlagChoseMon == CHOSE_VALID_MON)
        {
            sTradeData->linkData[0] = 0xCCDD;
            sTradeData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeData->playerLinkFlagChoseMon = 0;
            sTradeData->partnerLinkFlagChoseMon = 0;
            sTradeData->tradeMenuFunc = 9;
        }

        if (sTradeData->playerLinkFlagChoseMon == CHOSE_INVALID_MON 
         || sTradeData->partnerLinkFlagChoseMon == CHOSE_INVALID_MON)
        {
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeData->linkData[0] = 0xDDEE;
            sTradeData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeData->playerLinkFlagChoseMon = 0;
            sTradeData->partnerLinkFlagChoseMon = 0;
            sTradeData->tradeMenuFunc = 8;
        }
    }
}

static void _SetLinkData(u16 *linkData, u16 linkCmd, u16 cursorPosition)
{
    linkData[0] = linkCmd;
    linkData[1] = cursorPosition;
    QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
}

static void SetLinkData(u16 linkCmd, u16 cursorPosition)
{
    _SetLinkData(sTradeData->linkData, linkCmd, cursorPosition);
}

static void sub_8078C34(void)
{
    u8 mpId = GetMultiplayerId();
    u8 status;

    if ((status = _GetBlockReceivedStatus()))
    {
        if (mpId == 0)
            UpdateLinkFlags(mpId, status);
        else
            sub_8078900(mpId, status);
    }

    if (mpId == 0)
        sub_80789FC();
}

static u8 GetNewTradeMenuPosition(u8 oldPosition, u8 direction)
{
    int i;
    u8 newPosition = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sTradeData->monPresent[gTradeNextSelectedMonTable[oldPosition][direction][i]] == TRUE)
        {
            newPosition = gTradeNextSelectedMonTable[oldPosition][direction][i];
            break;
        }
    }

    return newPosition;
}

static void TradeMenuMoveCursor(u8 *cursorPosition, u8 direction)
{
    u8 newPosition = GetNewTradeMenuPosition(*cursorPosition, direction);

    if (newPosition == (PARTY_SIZE * 2)) // CANCEL
    {
        StartSpriteAnim(&gSprites[sTradeData->cursorSpriteIdx], 1);
        gSprites[sTradeData->cursorSpriteIdx].pos1.x = 224;
        gSprites[sTradeData->cursorSpriteIdx].pos1.y = 160;
    }
    else
    {
        StartSpriteAnim(&gSprites[sTradeData->cursorSpriteIdx], 0);
        gSprites[sTradeData->cursorSpriteIdx].pos1.x = gTradeMonSpriteCoords[newPosition][0] * 8 + 32;
        gSprites[sTradeData->cursorSpriteIdx].pos1.y = gTradeMonSpriteCoords[newPosition][1] * 8;
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
    sTradeData->tradeMenuFunc = 100;

    if (GetMultiplayerId() == 1)
    {
        SetLinkData(0xAABB, sTradeData->cursorPosition);
    }
    else
    {
        sTradeData->playerLinkFlagChoseAction = WANTS_TO_TRADE;
    }
}

static void TradeMenuProcessInput(void)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        TradeMenuMoveCursor(&sTradeData->cursorPosition, 0);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        TradeMenuMoveCursor(&sTradeData->cursorPosition, 1);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        TradeMenuMoveCursor(&sTradeData->cursorPosition, 2);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        TradeMenuMoveCursor(&sTradeData->cursorPosition, 3);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        // Cursor is in player's party
        if (sTradeData->cursorPosition < PARTY_SIZE)
        {
            DrawTextBorderOuter(1, 1, 14);
            FillWindowPixelBuffer(1, PIXEL_FILL(1));
            PrintMenuTable(1, ARRAY_COUNT(sSelectTradeMonActions), sSelectTradeMonActions);
            InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
            PutWindowTilemap(1);
            CopyWindowToVram(1, 3);
            sTradeData->tradeMenuFunc = 1;
        }
        // Cursor is in partner's party
        else if (sTradeData->cursorPosition < PARTY_SIZE * 2)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->tradeMenuFunc = 2;
        }
        // Cursor is on Cancel
        else if (sTradeData->cursorPosition == PARTY_SIZE * 2)
        {
            CreateYesNoMenu(&sTradeYesNoWindowTemplate, 1, 14, 0);
            sTradeData->tradeMenuFunc = 4;
            DrawTextWindowAndBuffer6Bytes(sTradeActionTexts[TRADE_ACTION_TEXT_CANCEL_TRADE], (void *)(OBJ_VRAM0 + sTradeData->unk_72 * 32), 24);
        }
    }
}

static void ReturnToTradeMenu(void)
{
    sub_8079F74();
    sTradeData->tradeMenuFunc = 0;
    gSprites[sTradeData->cursorSpriteIdx].invisible = FALSE;
    DrawTextWindowAndBuffer6Bytes(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + sTradeData->unk_72 * 32), 24);
}

static void TradeMenuProcessInput_SelectedMon(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            ReturnToTradeMenu();
            break;
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_ACTION_SUMMARY:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeData->tradeMenuFunc = 2;
            break;
        case MENU_ACTION_TRADE:
            switch (CanTradeSelectedMon(gPlayerParty, gPlayerPartyCount, sTradeData->cursorPosition))
            {
                case CAN_TRADE_MON:
                    sub_8078D78();
                    gSprites[sTradeData->cursorSpriteIdx].invisible = TRUE;
                    break;
                case CANT_TRADE_LAST_MON:
                    QueueAction(QUEUE_DELAY_MSG, QUEUE_ONLY_MON2);
                    sTradeData->tradeMenuFunc = 8;
                    break;
                case CANT_TRADE_NATIONAL:
                case CANT_TRADE_INVALID_MON:
                    QueueAction(QUEUE_DELAY_MSG, QUEUE_MON_CANT_BE_TRADED);
                    sTradeData->tradeMenuFunc = 8;
                    break;
                case CANT_TRADE_EGG:
                case CANT_TRADE_EGG2:
                    QueueAction(QUEUE_DELAY_MSG, QUEUE_EGG_CANT_BE_TRADED);
                    sTradeData->tradeMenuFunc = 8;
                    break;
            }
            break;
    }
}

static void ReturnToTradeMenuAfterButtonPress(void)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        ReturnToTradeMenu();
    }
}

static void TradeMenuShowMonSummaryScreen(void)
{
    if (!gPaletteFade.active)
    {
        // Player's party
        if (sTradeData->cursorPosition < PARTY_SIZE)
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, sTradeData->cursorPosition, sTradeData->partyCounts[TRADE_PLAYER] - 1, sub_8077B74);
        }
        // Partner's party
        else
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gEnemyParty, sTradeData->cursorPosition - PARTY_SIZE, sTradeData->partyCounts[TRADE_PARTNER] - 1, sub_8077B74);
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
        if (sTradeData->isEgg[TRADE_PARTNER][partnerMonIdx] || !IsSpeciesInHoennDex(species))
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

    for (i = 0; i < sTradeData->partyCounts[TRADE_PLAYER]; i++)
    {
        aliveMons[i] = sTradeData->isLiveMon[TRADE_PLAYER][i];
    }

    switch (CheckValidityOfTradeMons(aliveMons, sTradeData->partyCounts[TRADE_PLAYER], sTradeData->cursorPosition, sTradeData->partnerCursorPosition))
    {
        case PLAYER_MON_INVALID:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_ONLY_MON2);
            SetLinkData(0xBBCC, 0);
            break;
        case PLAYER_MON_VALID:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_STANDBY);
            SetLinkData(LINKCMD_INIT_BLOCK, 0);
            break;
        case PARTNER_MON_INVALID:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_FRIENDS_MON_CANT_BE_TRADED);
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
                sTradeData->tradeMenuFunc = 100;
            }
            else
            {
                sTradeData->tradeMenuFunc = 17;
            }
            PutWindowTilemap(17);
            break;
        case 1:
        case MENU_B_PRESSED:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_STANDBY);
            if (sub_80771BC())
                SetLinkData(0xBBCC, 0);
            sTradeData->tradeMenuFunc = 100;
            PutWindowTilemap(17);
            break;
    }
}

static void sub_807929C(void)
{
    int i;

    for (i = 0; i < sTradeData->partyCounts[1] - 4; i++)
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
            gSprites[sTradeData->cursorSpriteIdx].invisible = TRUE;
            sTradeData->tradeMenuFunc = 100;
            sub_807929C();
            break;
        case 1:
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            ReturnToTradeMenu();
            break;
    }
}

static void sub_807935C(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        SetSelectedMon(sTradeData->cursorPosition);
        SetSelectedMon(sTradeData->partnerCursorPosition);
    }
    sTradeData->tradeMenuFunc = 7;
}

static void sub_8079398(void)
{
    if (sTradeData->drawPartyState[TRADE_PLAYER] == 5 
        && sTradeData->drawPartyState[TRADE_PARTNER] == 5)
    {
        PrintAndBufferIsThisTradeOkay();
        sTradeData->tradeMenuFunc = 14;
    }
}

static void Wait2SecondsAndCreateYesNoMenu(void)
{
    sTradeData->timer++;

    if (sTradeData->timer > 120)
    {
        CreateYesNoMenu(&sTradeYesNoWindowTemplate, 1, 14, 0);
        sTradeData->timer = 0;
        sTradeData->tradeMenuFunc = 3;
    }
}

static void RedrawTradeMenuAfterPressA(void)
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

        RedrawTradeMenuParty(TRADE_PLAYER);
        RedrawTradeMenuParty(TRADE_PARTNER);
        sTradeData->tradeMenuFunc = 0;
        gSprites[sTradeData->cursorSpriteIdx].invisible = FALSE;
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

        sTradeData->tradeMenuFunc = 12;
    }
}

static void sub_80794CC(void)
{
    if (gWirelessCommType)
    {
        if (sub_80771BC() && GetNumQueuedActions() == 0)
        {
            Free(sMessageBoxAllocBuffer);
            Free(sTradeData);
            FreeAllWindowBuffers();
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(sMessageBoxAllocBuffer);
            Free(sTradeData);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
}

static void sub_8079550(void)
{
    if (!sub_801048C(FALSE) && GetNumQueuedActions() == 0)
    {
        sub_800ADF8();
        sTradeData->tradeMenuFunc = 13;
    }
}

static void sub_807957C(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        SetLinkData(0xBBCC, 0);
        sTradeData->tradeMenuFunc = 100;
    }
}

//TODO:
static void sub_80795AC(void)
{
    switch (sTradeData->tradeMenuFunc)
    {
        case 0:
            TradeMenuProcessInput();
            break;
        case 1:
            TradeMenuProcessInput_SelectedMon();
            break;
        case 2:
            TradeMenuShowMonSummaryScreen();
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
            RedrawTradeMenuAfterPressA();
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
            ReturnToTradeMenuAfterButtonPress();
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

    if (sTradeData->drawPartyState[whichParty] == 0)
    {
        sTradeData->drawPartyState[whichParty] = 1;
        sTradeData->selectedMonIdx[whichParty] = cursorPosition;
    }
}

static void DrawTradeMenuParty(u8 whichParty)
{
    s8 nameStringWidth;
    u8 nickname[20];
    u8 movesString[56];
    u8 i;
    u8 partyIdx;
    u8 selectedMonParty;
    u8 selectedMonIdx = sTradeData->selectedMonIdx[whichParty];

    selectedMonParty = TRADE_PARTNER;
    if (sTradeData->selectedMonIdx[whichParty] < PARTY_SIZE)
        selectedMonParty = TRADE_PLAYER;
    partyIdx = selectedMonIdx % PARTY_SIZE;
    nameStringWidth = 0;

    switch (sTradeData->drawPartyState[whichParty])
    {
    case 1:
        for (i = 0; i < sTradeData->partyCounts[whichParty]; i++)
        {
            gSprites[sTradeData->partySpriteIds[0][i + (selectedMonParty * PARTY_SIZE)]].invisible = TRUE;
        }

        for (i = 0; i < 6; i++)
        {
            ClearWindowTilemap(i + (whichParty * PARTY_SIZE + 2));
        }

        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].invisible = FALSE;
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].data[0] = 20;
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].data[2] = (gTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][0] + gTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].data[4] = (gTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][1] * 8) - 12;
        StoreSpriteCallbackInData6(&gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]], sub_80D3014);
        sTradeData->drawPartyState[whichParty]++;
        TradeMenuBouncePartySprites(&gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]]);
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, whichParty * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);

        if (selectedMonParty == TRADE_PLAYER)
            sub_8079F74();
        break;
    case 2:
        if (gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].callback == sub_80D3014)
            sTradeData->drawPartyState[whichParty] = 3;
        break;
    case 3:
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMovesBoxTilemap, selectedMonParty * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].pos1.x = (gTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][0] + gTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].pos1.y = (gTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][1] * 8) - 12;
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].pos2.x = 0;
        gSprites[sTradeData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].pos2.y = 0;
        nameStringWidth = GetMonNicknameWidth(nickname, selectedMonParty, partyIdx);
        AddTextPrinterParameterized3((whichParty * 2) + 14, 0, (80 - nameStringWidth) / 2, 4, sTradeTextColors, 0, nickname);
        BufferTradeMonMoves(movesString, selectedMonParty, partyIdx);
        AddTextPrinterParameterized4((whichParty * 2) + 15, 1, 0, 0, 0, 0, sTradeTextColors, 0, movesString);
        PutWindowTilemap((whichParty * 2) + 14);
        CopyWindowToVram((whichParty * 2) + 14, 3);
        PutWindowTilemap((whichParty * 2) + 15);
        CopyWindowToVram((whichParty * 2) + 15, 3);
        sTradeData->drawPartyState[whichParty]++;
        break;
    case 4:
        DrawTradeMenuPartyMonInfo(whichParty, partyIdx, 
            sTradeMenuPartyMonBoxDimensions[whichParty][0] + 4, 
            sTradeMenuPartyMonBoxDimensions[whichParty][1] + 1, 
            sTradeMenuPartyMonBoxDimensions[whichParty][0], 
            sTradeMenuPartyMonBoxDimensions[whichParty][1]);
        sTradeData->drawPartyState[whichParty]++;
        break;
    }
}

static u8 GetMonNicknameWidth(u8 *str, u8 whichParty, u8 monIdx)
{
    u8 nickname[12];

    if (whichParty == TRADE_PLAYER)
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

    if (!sTradeData->isEgg[whichParty][partyIdx])
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

    for (i = 0; i < sTradeData->partyCounts[whichParty]; i++)
    {
        GetMonData(&party[i], MON_DATA_NICKNAME, nickname);
        StringCopy10(str, nickname);
        PrintMonNicknameForTradeMenu(whichParty, i, str);
    }
}

static void DrawTradeMenuPartyMonInfo(u8 whichParty, u8 monIdx, u8 x, u8 y, u8 width, u8 height)
{
    u8 level;
    u32 symbolTile;
    u8 gender;
    u8 nickname[12];

    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDD704, width, height, 6, 3, 0);
    CopyBgTilemapBufferToVram(1);

    if (whichParty == TRADE_PLAYER)
        level = GetMonData(&gPlayerParty[monIdx], MON_DATA_LEVEL, NULL);
    else
        level = GetMonData(&gEnemyParty[monIdx], MON_DATA_LEVEL, NULL);

    if (!sTradeData->isEgg[whichParty][monIdx])
    {
        if (level / 10 != 0)
            sTradeData->tilemapBuffer[x + (y * 32)] = (level / 10) + 0x60;

        sTradeData->tilemapBuffer[x + (y * 32) + 1] = (level % 10) + 0x70;
    }
    else
    {
        sTradeData->tilemapBuffer[x + (y * 32) - 32] = sTradeData->tilemapBuffer[x + (y * 32) - 33];
        sTradeData->tilemapBuffer[x + (y * 32) - 31] = sTradeData->tilemapBuffer[x + (y * 32) - 36] | 0x400;
    }

    if (sTradeData->isEgg[whichParty][monIdx])
    {
        symbolTile = 0x480;
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
                symbolTile = !NameHasGenderSymbol(nickname, MON_MALE) ? 0x84 : 0x83;
                break;
            case MON_FEMALE:
                symbolTile = !NameHasGenderSymbol(nickname, MON_FEMALE) ? 0x85 : 0x83;
                break;
            default:
                symbolTile = 0x83;
                break;
        }
    }
    sTradeData->tilemapBuffer[(y - 1) * 32 + x + 1] = symbolTile;
}

// Very close but loop preamble not working.
#ifdef NONMATCHING
static void sub_8079E44(u8 whichParty)
{
    int i;

    for (i = 0; i < sTradeData->partyCounts[whichParty]; i++)
    {
        DrawTradeMenuPartyMonInfo(whichParty, i, 
            sTradeMonCoords[whichParty][i][0] + 4, 
            sTradeMonCoords[whichParty][i][1] - 1, 
            sTradeMonBoxDimensions[whichParty][i][0], 
            sTradeMonBoxDimensions[whichParty][i][1]);
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
    ldr r0, =sTradeData\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    bge _08079E94\n\
    lsls r0, r6, 1\n\
    adds r0, r6\n\
    ldr r1, =sTradeMonCoords\n\
    lsls r0, 2\n\
    adds r5, r0, r1\n\
    ldr r1, =sTradeMonBoxDimensions\n\
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
    bl DrawTradeMenuPartyMonInfo\n\
    adds r5, 0x2\n\
    adds r4, 0x2\n\
    adds r7, 0x1\n\
    ldr r0, =sTradeData\n\
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

static void ResetTradeMenuPartyPositions(u8 whichParty)
{
    int i;

    for (i = 0; i < sTradeData->partyCounts[whichParty]; i++)
    {
        gSprites[sTradeData->partySpriteIds[whichParty][i]].invisible = FALSE;
        gSprites[sTradeData->partySpriteIds[whichParty][i]].pos1.x = gTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][0] * 8 + 14;
        gSprites[sTradeData->partySpriteIds[whichParty][i]].pos1.y = gTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][1] * 8 - 12;
        gSprites[sTradeData->partySpriteIds[whichParty][i]].pos2.x = 0;
        gSprites[sTradeData->partySpriteIds[whichParty][i]].pos2.y = 0;
    }
}

static void sub_8079F74(void)
{
    rbox_fill_rectangle(1);
    PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);
}

static void RedrawTradeMenuParty(u8 whichParty)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, whichParty * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    sub_8079E44(whichParty);
    PrintPartyNicknamesForTradeMenu(whichParty);
    ResetTradeMenuPartyPositions(whichParty);
    DrawTextWindowAndBuffer6Bytes(sTradeActionTexts[TRADE_ACTION_TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + (sTradeData->unk_72 * 32)), 24);
    sTradeData->drawPartyState[whichParty] = 0;
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

static void QueueAction(u16 delay, u8 actionId)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeData->queuedActions); i++)
    {
        if (!sTradeData->queuedActions[i].queued)
        {
            sTradeData->queuedActions[i].queueDelay = delay;
            sTradeData->queuedActions[i].actionId = actionId;
            sTradeData->queuedActions[i].queued = TRUE;
            break;
        }
    }
}

static u32 GetNumQueuedActions(void)
{
    u32 numActions = 0;
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeData->queuedActions); i++)
    {
        numActions += sTradeData->queuedActions[i].queued;
    }

    return numActions;
}

static void DoQueuedActions(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeData->queuedActions); i++)
    {
        if (sTradeData->queuedActions[i].queued)
        {
            if (sTradeData->queuedActions[i].queueDelay)
            {
                sTradeData->queuedActions[i].queueDelay--;
            }
            else
            {
                switch (sTradeData->queuedActions[i].actionId)
                {
                    case QUEUE_SEND_DATA:
                        SendLinkData(sTradeData->linkData, 20);
                        break;
                    case QUEUE_STANDBY:
                        PrintTradeMessage(TRADE_MSG_STANDBY);
                        break;
                    case QUEUE_ONLY_MON1:
                        PrintTradeMessage(TRADE_MSG_ONLY_MON1);
                        break;
                    case QUEUE_ONLY_MON2:
                    case QUEUE_UNUSED1:
                    case QUEUE_UNUSED2:
                        PrintTradeMessage(TRADE_MSG_ONLY_MON2);
                        break;
                    case QUEUE_MON_CANT_BE_TRADED:
                        PrintTradeMessage(TRADE_MSG_MON_CANT_BE_TRADED);
                        break;
                    case QUEUE_EGG_CANT_BE_TRADED:
                        PrintTradeMessage(TRADE_MSG_EGG_CANT_BE_TRADED);
                        break;
                    case QUEUE_FRIENDS_MON_CANT_BE_TRADED:
                        PrintTradeMessage(TRADE_MSG_FRIENDS_MON_CANT_BE_TRADED);
                        break;
                }
                sTradeData->queuedActions[i].queued = FALSE;
            }
        }
    }
}

static void PrintTradeMessage(u8 messageId)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, 1, sTradeMessages[messageId], 0, 1, TEXT_SPEED_FF, NULL);
    DrawTextBorderOuter(0, 20, 12);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static bool8 LoadTradeMenuSpriteSheetsAndPalettes(void)
{
    struct SpriteSheet sheet;

    if (sTradeData->timer < (int)ARRAY_COUNT(sMessageBoxTileBuffers))
    {
        sheet.data = sMessageBoxTileBuffers[sTradeData->timer];
        sheet.size = 0x100;
        sheet.tag = 200 + sTradeData->timer;
    }

    switch (sTradeData->timer)
    {
        case 0 ... 7:
            LoadSpriteSheet(&sheet);
            sTradeData->timer++;
            break;
        case 8:
            sTradeData->unk_72 = LoadSpriteSheet(&sheet);
            sTradeData->timer++;
            break;
        case 9 ... 13:
            LoadSpriteSheet(&sheet);
            sTradeData->timer++;
            break;
        case 14:
            LoadSpritePalette(&gSpritePalette_TradeScreenText);
            sTradeData->timer++;
            break;
        case 15:
            LoadSpritePalette(&gUnknown_0832DC44);
            sTradeData->timer++;
            break;
        case 16:
            LoadSpriteSheet(&sTradeButtonsSpriteSheet);
            sTradeData->timer++;
            break;
        case 17:
            sTradeData->timer = 0;
            return TRUE;
    }

    return FALSE;
}

static void DrawTextWindowAndBuffer6Bytes(const u8 *str, u8 *dest, u8 unused)
{
    DrawTextWindowAndBufferTiles(str, dest, 0, 0, 6);
}

static void SetTradePartyLiveStatuses(u8 whichParty)
{
    int i;

    switch (whichParty)
    {
    case TRADE_PLAYER:
        for (i = 0; i < sTradeData->partyCounts[whichParty]; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == TRUE)
            {
                sTradeData->isLiveMon[whichParty][i] = FALSE;
                sTradeData->isEgg[whichParty][i] = TRUE;
            }
            else if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
            {
                sTradeData->isLiveMon[whichParty][i] = FALSE;
                sTradeData->isEgg[whichParty][i] = FALSE;
            }
            else
            {
                sTradeData->isLiveMon[whichParty][i] = TRUE;
                sTradeData->isEgg[whichParty][i] = FALSE;
            }
        }
        break;
    case TRADE_PARTNER:
        for (i = 0; i < sTradeData->partyCounts[whichParty]; i++)
        {
            if (GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG) == TRUE)
            {
                sTradeData->isLiveMon[whichParty][i] = FALSE;
                sTradeData->isEgg[whichParty][i] = TRUE;
            }
            else if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
            {
                sTradeData->isLiveMon[whichParty][i] = FALSE;
                sTradeData->isEgg[whichParty][i] = FALSE;
            }
            else
            {
                sTradeData->isLiveMon[whichParty][i] = TRUE;
                sTradeData->isEgg[whichParty][i] = FALSE;
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
            for (i = 0; i < sTradeData->partyCounts[TRADE_PLAYER]; i++)
            {
                curHp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
                sTradeData->hpBarLevels[TRADE_PLAYER][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
        case TRADE_PARTNER:
            for (i = 0; i < sTradeData->partyCounts[TRADE_PARTNER]; i++)
            {
                curHp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gEnemyParty[i], MON_DATA_MAX_HP);
                sTradeData->hpBarLevels[TRADE_PARTNER][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
    }
}

static void SetTradePartyHPBarSprites(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < sTradeData->partyCounts[i]; j++)
        {
            SetPartyHPBarSprite(&gSprites[sTradeData->partySpriteIds[i][j]], 4 - sTradeData->hpBarLevels[i][j]);
        }
    }
}

static void sub_807A5B0(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeData->giftRibbons); i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && sTradeData->giftRibbons[i] != 0)
        {
            if (sTradeData->giftRibbons[i] < 64)
                gSaveBlock1Ptr->giftRibbons[i] = sTradeData->giftRibbons[i];
        }
    }
}

//TODO:
static u32 CanTradeSelectedMon(struct Pokemon *playerParty, int partyCount, int monIdx)
{
    int i, numAliveMons;
    struct LinkPlayer *player;
    u32 species[PARTY_SIZE];
    u32 species2[PARTY_SIZE];

    for (i = 0; i < partyCount; i++)
    {
        species2[i] = GetMonData(&playerParty[i], MON_DATA_SPECIES2);
        species[i] = GetMonData(&playerParty[i], MON_DATA_SPECIES);
    }

    // Cant trade Eggs or non-Hoenn mons if player doesn't have National Dex
    if (!IsNationalPokedexEnabled())
    {
        if (species2[monIdx] == SPECIES_EGG)
            return CANT_TRADE_EGG;

        if (!IsSpeciesInHoennDex(species2[monIdx]))
            return CANT_TRADE_NATIONAL;
    }

    player = &gLinkPlayers[GetMultiplayerId() ^ 1];
    if ((player->version & 0xFF) != VERSION_RUBY &&
        (player->version & 0xFF) != VERSION_SAPPHIRE)
    {
        if ((player->name[10] & 0xF) == 0)
        {
            if (species2[monIdx] == SPECIES_EGG)
                return CANT_TRADE_EGG2;

            if (!IsSpeciesInHoennDex(species2[monIdx]))
                return CANT_TRADE_INVALID_MON;
        }
    }

    if (species[monIdx] == SPECIES_DEOXYS || species[monIdx] == SPECIES_MEW)
    {
        if (!GetMonData(&playerParty[monIdx], MON_DATA_OBEDIENCE))
            return CANT_TRADE_INVALID_MON;
    }

    for (i = 0; i < partyCount; i++)
    {
        if (species2[i] == SPECIES_EGG)
            species2[i] = SPECIES_NONE;
    }

    // Count alive mons in party, excluding selected trade mon
    for (numAliveMons = 0, i = 0; i < partyCount; i++)
    {
        if (i != monIdx)
            numAliveMons += species2[i];
    }

    if (numAliveMons != 0)
        return CAN_TRADE_MON;
    else
        return CANT_TRADE_LAST_MON;
}

// Return values are used to determine exchange status in GetLinkPlayerDataExchangeStatusTimed
// 0: EXCHANGE_COMPLETE
// 1: EXCHANGE_STAT_4
// 2: EXCHANGE_STAT_5
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
                if (val == 2) //unnecessary check, val always 2 here
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

int GetUnionRoomTradeMessageId(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 playerSpecies2, u16 partnerSpecies, u8 requestedType, u16 playerSpecies, u8 isObedientBitSet)
{
    bool8 playerHasNationalDex = a0.hasNationalDex;
    bool8 playerIsChampion = a0.isChampion;
    bool8 partnerHasNationalDex = a1.hasNationalDex;
    bool8 partnerIsChampion = a1.isChampion;
    u8 r1 = a1.unk_01_2;

    if (r1 != 3)
    {
        if (!playerIsChampion)
        {
            return UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_1;
        }
        else if (!partnerIsChampion)
        {
            return UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_2;
        }
    }

    if (IsDeoxysOrMewUntradable(playerSpecies, isObedientBitSet))
    {
        return UR_TRADE_MSG_MON_CANT_BE_TRADED_2;
    }

    if (partnerSpecies == SPECIES_EGG)
    {
        if (playerSpecies2 != partnerSpecies)
        {
            return UR_TRADE_MSG_NOT_EGG;
        }
    }
    else
    {
        if (gBaseStats[playerSpecies2].type1 != requestedType && gBaseStats[playerSpecies2].type2 != requestedType)
        {
            return UR_TRADE_MSG_NOT_MON_PARTNER_WANTS;
        }
    }

    if (playerSpecies2 == SPECIES_EGG && playerSpecies2 != partnerSpecies)
    {
        return UR_TRADE_MSG_MON_CANT_BE_TRADED_1;
    }

    if (!playerHasNationalDex)
    {
        if (playerSpecies2 == SPECIES_EGG)
        {
            return UR_TRADE_MSG_EGG_CANT_BE_TRADED;
        }

        if (!IsSpeciesInHoennDex(playerSpecies2))
        {
            return UR_TRADE_MSG_MON_CANT_BE_TRADED_2;
        }

        if (!IsSpeciesInHoennDex(partnerSpecies))
        {
            return UR_TRADE_MSG_PARTNERS_MON_CANT_BE_TRADED;
        }
    }

    if (!partnerHasNationalDex && !IsSpeciesInHoennDex(playerSpecies2))
    {
        return UR_TRADE_MSG_PARTNER_CANT_ACCEPT_MON;
    }

    return UR_TRADE_MSG_NONE;
}

int CanRegisterMonForTradingBoard(struct UnkLinkRfuStruct_02022B14Substruct a0, u16 species2, u16 species, u8 isObedientBitSet)
{
    bool8 hasNationalDex = a0.hasNationalDex;

    if (IsDeoxysOrMewUntradable(species, isObedientBitSet))
        return CANT_REGISTER_MON;

    if (hasNationalDex)
        return CAN_REGISTER_MON;

    // Eggs can only be traded if the player has the National Dex
    if (species2 == SPECIES_EGG)
        return CANT_REGISTER_EGG;

    if (IsSpeciesInHoennDex(species2))
        return CAN_REGISTER_MON;

    return CANT_REGISTER_MON;
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

static void SetTradeBGAffine(void)
{
    struct BgAffineDstData affine;

    DoBgAffineSet(&affine, sTradeWindowData->texX * 0x100, sTradeWindowData->texY * 0x100, sTradeWindowData->scrX, sTradeWindowData->scrY, sTradeWindowData->sXY, sTradeWindowData->sXY, sTradeWindowData->alpha);
    SetGpuReg(REG_OFFSET_BG2PA, affine.pa);
    SetGpuReg(REG_OFFSET_BG2PB, affine.pb);
    SetGpuReg(REG_OFFSET_BG2PC, affine.pc);
    SetGpuReg(REG_OFFSET_BG2PD, affine.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, affine.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, affine.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, affine.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, affine.dy >> 16);
}

static void SetTradeGpuRegs(void)
{
    u16 dispcnt;

    SetGpuReg(REG_OFFSET_BG1VOFS, sTradeWindowData->bg1vofs);
    SetGpuReg(REG_OFFSET_BG1HOFS, sTradeWindowData->bg1hofs);

    dispcnt = GetGpuReg(REG_OFFSET_DISPCNT);
    if ((dispcnt & 7) == DISPCNT_MODE_0)
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, sTradeWindowData->bg2vofs);
        SetGpuReg(REG_OFFSET_BG2HOFS, sTradeWindowData->bg2hofs);
    }
    else
    {
        SetTradeBGAffine();
    }
}

static void VBlankCB_Trade(void)
{
    SetTradeGpuRegs();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ClearLinkTimeoutCounter(void)
{
    sTradeWindowData->linkTimeoutCounter = 0;
    sTradeWindowData->alwaysZero_88 = 0;
    sTradeWindowData->alwaysZero_89 = 0;
}

static void CheckForLinkTimeout(void)
{
    if (sTradeWindowData->alwaysZero_88 == sTradeWindowData->alwaysZero_89)
        sTradeWindowData->linkTimeoutCounter++;
    else
        sTradeWindowData->linkTimeoutCounter = 0;

    if (sTradeWindowData->linkTimeoutCounter > LINK_TRADE_TIMEOUT)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        sTradeWindowData->linkTimeoutCounter = 0;
        sTradeWindowData->alwaysZero_89 = 0;
        sTradeWindowData->alwaysZero_88 = 0;
    }

    sTradeWindowData->alwaysZero_89 = sTradeWindowData->alwaysZero_88;
}

static u32 TradeGetMultiplayerId(void)
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
            sTradeWindowData->monSpecies[whichParty] = species;
            sTradeWindowData->monPersonalities[whichParty] = personality;
            break;
        case 1:
            SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, pos);
            sTradeWindowData->pokePicSpriteIdxs[whichParty] = CreateSprite(&gMultiuseSpriteTemplate, 120, 60, 6);
            gSprites[sTradeWindowData->pokePicSpriteIdxs[whichParty]].invisible = TRUE;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[whichParty]].callback = SpriteCallbackDummy;
            break;
    }
}

void CB2_LinkTrade(void)
{
    switch (gMain.state)
    {
        case 0:
            if (!gReceivedRemoteLinkPlayers)
            {
                gLinkType = 0x1144;
                CloseLink();
            }
            sTradeWindowData = AllocZeroed(sizeof(*sTradeWindowData));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(VBlankCB_Trade);
            InitTradeBgInternal();
            ClearLinkTimeoutCounter();
            gMain.state++;
            sTradeWindowData->neverRead_8C = 0;
            sTradeWindowData->state = 0;
            sTradeWindowData->isLinkTrade = TRUE;
            sTradeWindowData->texX = 64;
            sTradeWindowData->texY = 64;
            sTradeWindowData->neverRead_D8 = 0;
            sTradeWindowData->neverRead_DA = 0;
            sTradeWindowData->scrX = 120;
            sTradeWindowData->scrY = 80;
            sTradeWindowData->sXY = 256;
            sTradeWindowData->alpha = 0;
            break;
        case 1:
            if (!gReceivedRemoteLinkPlayers)
            {
                sTradeWindowData->isCableTrade = TRUE;
                OpenLink();
                gMain.state++;
                sTradeWindowData->timer = 0;
            }
            else
            {
                gMain.state = 4;
            }
            break;
        case 2:
            if (++sTradeWindowData->timer > 60)
            {
                sTradeWindowData->timer = 0;
                gMain.state++;
            }
            break;
        case 3:
            if (IsLinkMaster())
            {
                if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
                {
                    if (++sTradeWindowData->timer > 30)
                    {
                        CheckShouldAdvanceLinkState();
                        gMain.state++;
                    }
                }
                else
                {
                    CheckForLinkTimeout();
                }
            }
            else
            {
                gMain.state++;
            }
            break;
        case 4:
            CheckForLinkTimeout();
            if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
                gMain.state++;
            break;
        case 5:
            sTradeWindowData->unk_72 = 0;
            sTradeWindowData->unk_73 = 0;
            sTradeWindowData->unk_93 = 0;
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
            LoadTradeSequenceSpriteSheetsAndPalettes();
            LoadSpriteSheet(&sPokeBallSpriteSheet);
            LoadSpritePalette(&sPokeBallSpritePalette);
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

static void InitTradeBgInternal(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sTradeSequenceBgTemplates, ARRAY_COUNT(sTradeSequenceBgTemplates));
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
    InitWindows(sTradeSequenceWindowTemplates);
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
}

static void CB2_InGameTrade(void)
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
            sTradeWindowData = AllocZeroed(sizeof(*sTradeWindowData));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(VBlankCB_Trade);
            InitTradeBgInternal();
            sTradeWindowData->isLinkTrade = FALSE;
            sTradeWindowData->neverRead_8C = 0;
            sTradeWindowData->state = 0;
            sTradeWindowData->texX = 64;
            sTradeWindowData->texY = 64;
            sTradeWindowData->neverRead_D8 = 0;
            sTradeWindowData->neverRead_DA = 0;
            sTradeWindowData->scrX = 120;
            sTradeWindowData->scrY = 80;
            sTradeWindowData->sXY = 256;
            sTradeWindowData->alpha = 0;
            sTradeWindowData->timer = 0;
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
            LoadTradeSequenceSpriteSheetsAndPalettes();
            LoadSpriteSheet(&sPokeBallSpriteSheet);
            LoadSpritePalette(&sPokeBallSpritePalette);
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

static void UpdatePokedexForReceivedMon(u8 partyIdx)
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

// Functionally nop after commented code
static void EnableNationalDexFromLinkPlayer(void)
{
    u8 mpId = GetMultiplayerId();
    // Originally in Ruby but commented out
    /*if (gLinkPlayers[mpId ^ 1].lp_field_2 == 0x8000)
        EnableNationalPokedex();*/
}

static void TradeMons(u8 playerPartyIdx, u8 partnerPartyIdx)
{
    u8 friendship;

    struct Pokemon *playerMon = &gPlayerParty[playerPartyIdx];
    u16 playerMail = GetMonData(playerMon, MON_DATA_MAIL);

    struct Pokemon *partnerMon = &gEnemyParty[partnerPartyIdx];
    u16 partnerMail = GetMonData(partnerMon, MON_DATA_MAIL);

    if (playerMail != 0xFF)
        ClearMailStruct(&gSaveBlock1Ptr->mail[playerMail]);

    sTradeWindowData->mon = *playerMon;
    *playerMon = *partnerMon;
    *partnerMon = sTradeWindowData->mon;

    friendship = 70;
    if (!GetMonData(playerMon, MON_DATA_IS_EGG))
        SetMonData(playerMon, MON_DATA_FRIENDSHIP, &friendship);

    if (partnerMail != 0xFF)
        GiveMailToMon2(playerMon, &gTradeMail[partnerMail]);

    UpdatePokedexForReceivedMon(playerPartyIdx);
    if (gReceivedRemoteLinkPlayers)
        EnableNationalDexFromLinkPlayer();
}

static void sub_807B5B8(void)
{
    switch (sTradeWindowData->unk_93)
    {
        case 1:
            if (IsLinkTaskFinished())
            {
                Trade_SendData(sTradeWindowData);
                sTradeWindowData->unk_93++;
            }
            // fallthrough
        case 2:
            sTradeWindowData->unk_93 = 0;
            break;
    }
}

static void sub_807B60C(void)
{
    AnimateTradeSequence();
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
            sTradeWindowData->bg2vofs = 0;
            sTradeWindowData->bg2hofs = 180;
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
            sTradeWindowData->bg1hofs = 0;
            sTradeWindowData->bg1vofs = 348;
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

            if (sTradeWindowData->isCableTrade)
            {
                DmaCopy16Defvars(3, sTradeTilemap_GbaCable, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }
            else
            {
                DmaCopy16Defvars(3, sTradeTilemap_GbaWireless, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }

            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(0), 0x1420, 0x1000);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 2:
            sTradeWindowData->bg1vofs = 0;
            sTradeWindowData->bg1hofs = 0;
            if (!sTradeWindowData->isCableTrade)
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
            sTradeWindowData->bg2vofs = 80;
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
            sTradeWindowData->texX = 64;
            sTradeWindowData->texY = 92;
            sTradeWindowData->sXY = 32;
            sTradeWindowData->unk_EA = 1024;
            sTradeWindowData->alpha = 0;

            DmaCopyLarge16(3, sTradeAffine_Gba, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

            if (sTradeWindowData->isCableTrade)
            {
                DmaCopy16Defvars(3, sTradeAffineMap_GbaCable, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, sTradeAffineMap_GbaWireless, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 5:
            sTradeWindowData->bg1vofs = 0;
            sTradeWindowData->bg1hofs = 0;
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
            sTradeWindowData->texX = 64;
            sTradeWindowData->texY = 92;
            sTradeWindowData->sXY = 256;
            sTradeWindowData->unk_EA = 128;
            sTradeWindowData->scrX = 120;
            sTradeWindowData->scrY = 80;
            sTradeWindowData->alpha = 0;

            DmaCopyLarge16(3, sTradeAffine_Gba, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

            if (sTradeWindowData->isCableTrade)
            {
                DmaCopy16Defvars(3, sTradeAffineMap_GbaCable, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, sTradeAffineMap_GbaWireless, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 7:
            sTradeWindowData->bg2vofs = 0;
            sTradeWindowData->bg2hofs = 0;
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

static void LoadTradeSequenceSpriteSheetsAndPalettes(void)
{
    LoadSpriteSheet(&sGlow1SpriteSheet);
    LoadSpriteSheet(&sGlow2SpriteSheet);
    LoadSpriteSheet(&sCableEndSpriteSheet);
    LoadSpriteSheet(&sGbaScreenSpriteSheet);
    LoadSpritePalette(&sMiscTradeSpritePalette);
    LoadSpritePalette(&sGbaSpritePalette);
}

/// Buffers "[Pokemon] will be sent to [Trainer]" strings
static void SetTradeSceneStrings(void)
{
    u8 mpId;
    u8 name[20];
    const struct InGameTrade *ingameTrade;

    if (sTradeWindowData->isLinkTrade)
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

// returns TRUE if it was a link trade, FALSE if it was an in-game trade
static bool8 AnimateTradeSequence(void)
{
    if (sTradeWindowData->isCableTrade)
        return AnimateTradeSequenceCable();
    else
        return AnimateTradeSequenceWireless();
}

static bool8 AnimateTradeSequenceCable(void)
{
    u16 evoTarget;

    switch (sTradeWindowData->state)
    {
        case 0:
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].invisible = FALSE;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.x = -180;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y = gMonFrontPicCoords[sTradeWindowData->monSpecies[TRADE_PLAYER]].y_offset;
            sTradeWindowData->state++;
            sTradeWindowData->cachedMapMusic = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (sTradeWindowData->bg2hofs > 0)
            {
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.x += 3;
                sTradeWindowData->bg2hofs -= 3;
            }
            else
            {
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.x = 0;
                sTradeWindowData->bg2hofs = 0;
                sTradeWindowData->state = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);

            if (sTradeWindowData->monSpecies[TRADE_PLAYER] != SPECIES_EGG)
            {
                PlayCry1(sTradeWindowData->monSpecies[TRADE_PLAYER], 0);
            }

            sTradeWindowData->state = 11;
            sTradeWindowData->timer = 0;
            break;
        case 11:
            if (++sTradeWindowData->timer == 80)
            {
                sTradeWindowData->unk_D2 = sub_807671C(sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER], gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                sTradeWindowData->state++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[sTradeWindowData->unk_D2].callback == SpriteCallbackDummy)
            {
                sTradeWindowData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[sTradeWindowData->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[sTradeWindowData->unk_D2]);
                sTradeWindowData->state++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeWindowData->state = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, PIXEL_FILL(15));
                CopyWindowToVram(0, 3);
                sTradeWindowData->state++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state = 23;
            }
            break;
        case 23:
            if (sTradeWindowData->unk_EA > 0x100)
            {
                sTradeWindowData->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                sTradeWindowData->unk_EA = 0x80;
                sTradeWindowData->state++;
                sTradeWindowData->timer = 0;
            }
            sTradeWindowData->sXY = 0x8000 / sTradeWindowData->unk_EA;
            break;
        case 24:
            if (++sTradeWindowData->timer > 20)
            {
                SetTradeBGAffine();
                sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
                sTradeWindowData->state++;
            }
            break;
        case 25:
            if (gSprites[sTradeWindowData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG1 |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 4));
                sTradeWindowData->state++;
            }
            break;
        case 26:
            if (--sTradeWindowData->bg1vofs == 316)
            {
                sTradeWindowData->state++;
            }
            if (sTradeWindowData->bg1vofs == 328)
            {
                sTradeWindowData->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
            }
            break;
        case 27:
            sTradeWindowData->unk_90 = CreateSprite(&gUnknown_08338D88, 128, 80, 3);
            sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, 80, 0);
            StartSpriteAnim(&gSprites[sTradeWindowData->unk_91], 1);
            sTradeWindowData->state++;
            break;
        case 28:
            if ((sTradeWindowData->bg1vofs -= 2) == 166)
            {
                sTradeWindowData->state = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[sTradeWindowData->unk_90].pos1.y -= 2;
            gSprites[sTradeWindowData->unk_91].pos1.y -= 2;
            if (gSprites[sTradeWindowData->unk_90].pos1.y < -8)
            {
                sTradeWindowData->state = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            sTradeWindowData->state = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[sTradeWindowData->unk_90]);
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
                sub_807B62C(2);
                sTradeWindowData->state++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeWindowData->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            sTradeWindowData->state++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                sTradeWindowData->state++;
            }
            gSprites[sTradeWindowData->unk_90].pos2.y -= 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[sTradeWindowData->unk_90].pos2.y -= 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            if (gSprites[sTradeWindowData->unk_90].pos2.y <= -90)
            {
                gSprites[sTradeWindowData->unk_90].data[1] = 1;
                gSprites[sTradeWindowData->unk_91].data[1] = 1;
                sTradeWindowData->state++;
            }
            break;
        case 34:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 35:
            BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 36:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(sTradeWindowData->monSpecies[TRADE_PLAYER]))
            {
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]], 0);
            }
            StartSpriteAffineAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]], 0);
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos1.x = 60;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.x = 180;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos1.y = 192;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.y = -32;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].invisible = FALSE;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].invisible = FALSE;
            sTradeWindowData->state++;
            break;
        case 38:
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y -= 3;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos2.y += 3;
            if (gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y < -160 && gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y < -222)
            {
                gSprites[sTradeWindowData->unk_90].data[1] = 0;
                gSprites[sTradeWindowData->unk_91].data[1] = 0;
                sTradeWindowData->state++;
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].invisible = TRUE;
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].invisible = TRUE;
                BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            }
            break;
        case 39:
            gSprites[sTradeWindowData->unk_90].pos2.y -= 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            if (gSprites[sTradeWindowData->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                sTradeWindowData->state++;
                DestroySprite(&gSprites[sTradeWindowData->unk_90]);
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state++;
                sub_807B62C(1);
                sTradeWindowData->bg1vofs = 166;
                sTradeWindowData->unk_90 = CreateSprite(&gUnknown_08338D88, 128, -20, 3);
                sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, -20, 0);
                StartSpriteAnim(&gSprites[sTradeWindowData->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state++;
            }
            break;
        case 43:
            gSprites[sTradeWindowData->unk_90].pos2.y += 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            if (gSprites[sTradeWindowData->unk_90].pos2.y + gSprites[sTradeWindowData->unk_90].pos1.y == 64)
            {
                sTradeWindowData->state++;
            }
            break;
        case 44:
            if ((sTradeWindowData->bg1vofs += 2) > 316)
            {
                sTradeWindowData->bg1vofs = 316;
                sTradeWindowData->state++;
            }
            break;
        case 45:
            DestroySprite(&gSprites[sTradeWindowData->unk_90]);
            DestroySprite(&gSprites[sTradeWindowData->unk_91]);
            sTradeWindowData->state++;
            sTradeWindowData->timer = 0;
            break;
        case 46:
            if (++sTradeWindowData->timer == 10)
            {
                sTradeWindowData->state++;
            }
            break;
        case 47:
            if (++sTradeWindowData->bg1vofs > 348)
            {
                sTradeWindowData->bg1vofs = 348;
                sTradeWindowData->state++;
            }
            if (sTradeWindowData->bg1vofs == 328 && sTradeWindowData->isCableTrade)
            {
                sTradeWindowData->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
                gSprites[sTradeWindowData->unk_92].callback = sub_807AAE0;
            }
            break;
        case 48:
            sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            sTradeWindowData->state = 50;
            break;
        case 50:
            if (gSprites[sTradeWindowData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
                sub_807B62C(6);
                sTradeWindowData->state++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (sTradeWindowData->unk_EA < 0x400)
            {
                sTradeWindowData->unk_EA += 0x34;
            }
            else
            {
                sTradeWindowData->unk_EA = 0x400;
                sTradeWindowData->state++;
            }
            sTradeWindowData->sXY = 0x8000 / sTradeWindowData->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeWindowData->state = 60;
            break;

        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                sTradeWindowData->state++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state++;
            }
            break;
        case 63:
            sTradeWindowData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[sTradeWindowData->unk_D3].data[3] = 74;
            gSprites[sTradeWindowData->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[sTradeWindowData->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[sTradeWindowData->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[sTradeWindowData->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            sTradeWindowData->timer = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[sTradeWindowData->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 65:
            if (gSprites[sTradeWindowData->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[sTradeWindowData->monSpecies[TRADE_PARTNER]], gMonSpritesGfxPtr->sprites[3], sTradeWindowData->monSpecies[TRADE_PARTNER], sTradeWindowData->monPersonalities[TRADE_PARTNER]);
                sTradeWindowData->state++;
            }
            break;
        case 66:
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.x = 120;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.y = gMonFrontPicCoords[sTradeWindowData->monSpecies[TRADE_PARTNER]].y_offset + 60;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos2.x = 0;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos2.y = 0;
            StartSpriteAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]], 0);
            CreatePokeballSpriteToReleaseMon(sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER], gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, sTradeWindowData->monSpecies[TRADE_PARTNER]);
            FreeSpriteOamMatrix(&gSprites[sTradeWindowData->unk_D3]);
            DestroySprite(&gSprites[sTradeWindowData->unk_D3]);
            sTradeWindowData->state++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            sTradeWindowData->state = 167;
            sTradeWindowData->timer = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++sTradeWindowData->timer > 60)
            {
                sTradeWindowData->state = 267;
                sTradeWindowData->timer = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                sTradeWindowData->state = 68;
            }
            break;
        case 68:
            if (++sTradeWindowData->timer == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (sTradeWindowData->timer == 250)
            {
                sTradeWindowData->state++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
                sTradeWindowData->timer = 0;
            }
            break;
        case 69:
            if (++sTradeWindowData->timer == 60)
            {
                sTradeWindowData->state++;
            }
            break;
        case 70:
            CheckPartnersMonForRibbons();
            sTradeWindowData->state++;
            break;
        case 71:
            if (sTradeWindowData->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                sTradeWindowData->state++;
            }
            break;
        case 72: // Only if in-game trade
            TradeMons(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
            }
            sTradeWindowData->state++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(sTradeWindowData->cachedMapMusic);
                if (sTradeWindowData)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(sTradeWindowData);
                }
                SetMainCallback2(CB2_ReturnToField);
                BuffeInGameTradeMonName();
            }
            break;
    }
    return FALSE;
}

static bool8 AnimateTradeSequenceWireless(void)
{
    u16 evoTarget;

    switch (sTradeWindowData->state)
    {
        case 0:
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].invisible = FALSE;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.x = -180;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y = gMonFrontPicCoords[sTradeWindowData->monSpecies[TRADE_PLAYER]].y_offset;
            sTradeWindowData->state++;
            sTradeWindowData->cachedMapMusic = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (sTradeWindowData->bg2hofs > 0)
            {
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.x += 3;
                sTradeWindowData->bg2hofs -= 3;
            }
            else
            {
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.x = 0;
                sTradeWindowData->bg2hofs = 0;
                sTradeWindowData->state = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);

            if (sTradeWindowData->monSpecies[TRADE_PLAYER] != SPECIES_EGG)
            {
                PlayCry1(sTradeWindowData->monSpecies[TRADE_PLAYER], 0);
            }

            sTradeWindowData->state = 11;
            sTradeWindowData->timer = 0;
            break;
        case 11:
            if (++sTradeWindowData->timer == 80)
            {
                sTradeWindowData->unk_D2 = sub_807671C(sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER], gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                sTradeWindowData->state++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[sTradeWindowData->unk_D2].callback == SpriteCallbackDummy)
            {
                sTradeWindowData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[sTradeWindowData->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[sTradeWindowData->unk_D2]);
                sTradeWindowData->state++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeWindowData->state = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, PIXEL_FILL(15));
                CopyWindowToVram(0, 3);
                sTradeWindowData->state++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state = 23;
            }
            break;
        case 23:
            if (sTradeWindowData->unk_EA > 0x100)
            {
                sTradeWindowData->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                sTradeWindowData->unk_EA = 0x80;
                sTradeWindowData->state = 124;
                sTradeWindowData->timer = 0;
            }
            sTradeWindowData->sXY = 0x8000 / sTradeWindowData->unk_EA;
            break;
        case 124:
            if (++sTradeWindowData->timer > 20)
            {
                sub_807B62C(3);
                sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338E8C, 120, 80, 0);
                sTradeWindowData->state++;
            }
            break;
        case 125:
            if (gSprites[sTradeWindowData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 |
                                             BLDCNT_TGT1_OBJ |
                                             BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));
                CreateTask(c3_08054588, 5);
                sTradeWindowData->state++;
            }
            break;
        case 126:
            if (!FuncIsActiveTask(c3_08054588))
            {
                sTradeWindowData->state = 26;
            }
            break;
        case 26:
            if (--sTradeWindowData->bg1vofs == 316)
            {
                sTradeWindowData->state++;
            }
            break;
        case 27:
            sTradeWindowData->unk_90 = CreateSprite(&gUnknown_08338D88, 120, 80, 3);
            gSprites[sTradeWindowData->unk_90].callback = sub_807AA4C;
            sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, 80, 0);
            StartSpriteAnim(&gSprites[sTradeWindowData->unk_91], 1);
            sTradeWindowData->state++;
            break;
        case 28:
            if ((sTradeWindowData->bg1vofs -= 3) == 166)
            {
                sTradeWindowData->state = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[sTradeWindowData->unk_90].pos1.y -= 2;
            gSprites[sTradeWindowData->unk_91].pos1.y -= 2;
            if (gSprites[sTradeWindowData->unk_90].pos1.y < -8)
            {
                sTradeWindowData->state = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            sTradeWindowData->state = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[sTradeWindowData->unk_90]);
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
                sub_807B62C(2);
                sTradeWindowData->state++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeWindowData->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            sTradeWindowData->state++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                sTradeWindowData->state++;
            }
            gSprites[sTradeWindowData->unk_90].pos2.y -= 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[sTradeWindowData->unk_90].pos2.y -= 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            if (gSprites[sTradeWindowData->unk_90].pos2.y <= -90)
            {
                gSprites[sTradeWindowData->unk_90].data[1] = 1;
                gSprites[sTradeWindowData->unk_91].data[1] = 1;
                sTradeWindowData->state++;
                CreateTask(c3_0805465C, 5);
            }
            break;
        case 34:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 35:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 36:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(sTradeWindowData->monSpecies[TRADE_PLAYER]))
            {
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]], 0);
            }
            StartSpriteAffineAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]], 0);
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos1.x = 40;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.x = 200;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos1.y = 192;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.y = -32;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].invisible = FALSE;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].invisible = FALSE;
            sTradeWindowData->state++;
            break;
        case 38:
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y -= 3;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos2.y += 3;
            if (gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y < -160 && gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].pos2.y < -222)
            {
                gSprites[sTradeWindowData->unk_90].data[1] = 0;
                gSprites[sTradeWindowData->unk_91].data[1] = 0;
                sTradeWindowData->state++;
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]].invisible = TRUE;
                gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].invisible = TRUE;
                CreateTask(sub_807F39C, 5);
            }
            break;
        case 39:
            gSprites[sTradeWindowData->unk_90].pos2.y -= 3;
            gSprites[sTradeWindowData->unk_91].pos2.y += 3;
            if (gSprites[sTradeWindowData->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                sTradeWindowData->state++;
                DestroySprite(&gSprites[sTradeWindowData->unk_90]);
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state++;
                sub_807B62C(1);
                sTradeWindowData->bg1vofs = 166;
                sub_807B62C(3);
                sTradeWindowData->bg2vofs = 412;
                sTradeWindowData->unk_90 = CreateSprite(&gUnknown_08338D88, 120, -20, 3);
                gSprites[sTradeWindowData->unk_90].callback = sub_807AA4C;
                sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, -20, 0);
                StartSpriteAnim(&gSprites[sTradeWindowData->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state++;
            }
            break;
        case 43:
            gSprites[sTradeWindowData->unk_90].pos2.y += 4;
            gSprites[sTradeWindowData->unk_91].pos2.y += 4;
            if (gSprites[sTradeWindowData->unk_90].pos2.y + gSprites[sTradeWindowData->unk_90].pos1.y == 64)
            {
                sTradeWindowData->state = 144;
                sTradeWindowData->timer = 0;
            }
            break;
        case 144:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            sTradeWindowData->bg1vofs += 3;
            sTradeWindowData->bg2vofs += 3;
            if (++sTradeWindowData->timer == 10)
            {
                u8 taskId = CreateTask(c3_08054588, 5);
                gTasks[taskId].data[2] = 1;
            }
            if (sTradeWindowData->bg1vofs > 316)
            {
                sTradeWindowData->bg1vofs = 316;
                sTradeWindowData->state++;
            }
            break;
        case 145:
            DestroySprite(&gSprites[sTradeWindowData->unk_90]);
            DestroySprite(&gSprites[sTradeWindowData->unk_91]);
            sTradeWindowData->state++;
            sTradeWindowData->timer = 0;
            break;
        case 146:
            if (!FuncIsActiveTask(c3_08054588))
            {
                sTradeWindowData->state = 46;
                sTradeWindowData->timer = 0;
            }
            break;
        case 46:
            if (++sTradeWindowData->timer == 10)
            {
                sTradeWindowData->state++;
            }
            break;
        case 47:
            if (++sTradeWindowData->bg1vofs > 348)
            {
                sTradeWindowData->bg1vofs = 348;
                sTradeWindowData->state++;
            }
            break;
        case 48:
            sTradeWindowData->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            sTradeWindowData->state = 50;
            break;
        case 50:
            if (gSprites[sTradeWindowData->unk_91].animEnded)
            {
                DestroySprite(&gSprites[sTradeWindowData->unk_91]);
                sub_807B62C(6);
                sTradeWindowData->state++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (sTradeWindowData->unk_EA < 0x400)
            {
                sTradeWindowData->unk_EA += 0x34;
            }
            else
            {
                sTradeWindowData->unk_EA = 0x400;
                sTradeWindowData->state++;
            }
            sTradeWindowData->sXY = 0x8000 / sTradeWindowData->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeWindowData->state = 60;
            break;
        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                sTradeWindowData->state++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                sTradeWindowData->state++;
            }
            break;
        case 63:
            sTradeWindowData->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[sTradeWindowData->unk_D3].data[3] = 74;
            gSprites[sTradeWindowData->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[sTradeWindowData->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[sTradeWindowData->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[sTradeWindowData->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            sTradeWindowData->timer = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[sTradeWindowData->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            sTradeWindowData->state++;
            break;
        case 65:
            if (gSprites[sTradeWindowData->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[sTradeWindowData->monSpecies[TRADE_PARTNER]], gMonSpritesGfxPtr->sprites[3], sTradeWindowData->monSpecies[TRADE_PARTNER], sTradeWindowData->monPersonalities[TRADE_PARTNER]);
                sTradeWindowData->state++;
            }
            break;
        case 66:
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.x = 120;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos1.y = gMonFrontPicCoords[sTradeWindowData->monSpecies[TRADE_PARTNER]].y_offset + 60;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos2.x = 0;
            gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].pos2.y = 0;
            StartSpriteAnim(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]], 0);
            CreatePokeballSpriteToReleaseMon(sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER], gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, sTradeWindowData->monSpecies[TRADE_PARTNER]);
            FreeSpriteOamMatrix(&gSprites[sTradeWindowData->unk_D3]);
            DestroySprite(&gSprites[sTradeWindowData->unk_D3]);
            sTradeWindowData->state++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            sTradeWindowData->state = 167;
            sTradeWindowData->timer = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++sTradeWindowData->timer > 60)
            {
                sTradeWindowData->state = 267;
                sTradeWindowData->timer = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                sTradeWindowData->state = 68;
            }
            break;
        case 68:
            if (++sTradeWindowData->timer == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (sTradeWindowData->timer == 250)
            {
                sTradeWindowData->state++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
                sTradeWindowData->timer = 0;
            }
            break;
        case 69:
            if (++sTradeWindowData->timer == 60)
            {
                sTradeWindowData->state++;
            }
            break;
        case 70:
            CheckPartnersMonForRibbons();
            sTradeWindowData->state++;
            break;
        case 71:
            if (sTradeWindowData->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                sTradeWindowData->state++;
            }
            break;
        case 72: // Only if in-game trade
            TradeMons(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
            }
            sTradeWindowData->state++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sTradeWindowData->state++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(sTradeWindowData->cachedMapMusic);
                if (sTradeWindowData)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(sTradeWindowData);
                }
                SetMainCallback2(CB2_ReturnToField);
                BuffeInGameTradeMonName();
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
                TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
            else if (IsWirelessTrade())
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
    TradeGetMultiplayerId(); // no effect call, ret val ignored
    blockReceivedStatus = GetBlockReceivedStatus();
    if (blockReceivedStatus & 0x01)
    {
        if (gBlockRecvBuffer[0][0] == 0xDCBA)
        {
            SetMainCallback2(c2_08053788);
        }
        if (gBlockRecvBuffer[0][0] == 0xABCD)
        {
            sTradeWindowData->unk_72 = 1;
        }
        ResetBlockReceivedFlag(0);
    }
    if (blockReceivedStatus & 0x02)
    {
        if (gBlockRecvBuffer[1][0] == 0xABCD)
        {
            sTradeWindowData->unk_73 = 1;
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
    sprite->pos2.y += sTradeBallVerticalVelocityTable[sprite->data[0]];
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
        sprite->pos2.y -= sTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++ sprite->data[0] == 23)
        {
            DestroySprite(sprite);
            sTradeWindowData->state = 14; // Resume the master trade animation
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
        sprite->pos2.y += sTradeBallVerticalVelocityTable[sprite->data[0]];
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

static void BuffeInGameTradeMonName(void)
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
            gTradeMail[0] = mail;
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

    for (i = 0; i < MAIL_WORDS_COUNT; i++)
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
    if (AnimateTradeSequence() == TRUE)
    {
        DestroySprite(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PLAYER]]);
        FreeSpriteOamMatrix(&gSprites[sTradeWindowData->pokePicSpriteIdxs[TRADE_PARTNER]]);
        TradeMons(gSelectedTradeMonPositions[TRADE_PLAYER], gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE);
        if (!IsWirelessTrade())
        {
            sTradeWindowData->linkData[0] = 0xABCD;
            sTradeWindowData->unk_93 = 1;
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
    u8 mpId = TradeGetMultiplayerId();
    if (IsWirelessTrade())
    {
        SetMainCallback2(c2_08053788);
    }
    else
    {
        sub_807E4DC();
        if (mpId == 0 && sTradeWindowData->unk_72 == 1 && sTradeWindowData->unk_73 == 1)
        {
            sTradeWindowData->linkData[0] = 0xDCBA;
            Trade_SendData(sTradeWindowData);
            sTradeWindowData->unk_72 = 2;
            sTradeWindowData->unk_73 = 2;
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
            sTradeWindowData->timer = 0;
            break;
        case 100:
            if (++sTradeWindowData->timer > 180)
            {
                gMain.state = 101;
                sTradeWindowData->timer = 0;
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
            sTradeWindowData->timer = 0;
            break;
        case 51:
            if (++sTradeWindowData->timer == 5)
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
                sTradeWindowData->timer = 0;
                gMain.state = 51;
            }
            break;
        case 4:
            sub_81533E0();
            gMain.state = 40;
            sTradeWindowData->timer = 0;
            break;
        case 40:
            if (++sTradeWindowData->timer > 50)
            {
                if (GetMultiplayerId() == 0)
                {
                    sTradeWindowData->timer = Random() % 30;
                }
                else
                {
                    sTradeWindowData->timer = 0;
                }
                gMain.state = 41;
            }
            break;
        case 41:
            if (sTradeWindowData->timer == 0)
            {
                sub_8077288(1);
                gMain.state = 42;
            }
            else
            {
                sTradeWindowData->timer--;
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
            if (++sTradeWindowData->timer > 60)
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
        FREE_AND_SET_NULL(sTradeWindowData);
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
    CreateTask(Task_InGameTrade, 10);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
}

static void Task_InGameTrade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InGameTrade);
        gFieldCallback = FieldCallback_ReturnToEventScript2;
        DestroyTask(taskId);
    }
}

static void CheckPartnersMonForRibbons(void)
{
    u8 i;
    u8 numRibbons = 0;
    for (i = 0; i < 12; i ++)
    {
        numRibbons += GetMonData(&gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE], MON_DATA_CHAMPION_RIBBON + i);
    }
    if (numRibbons != 0)
        FlagSet(FLAG_SYS_RIBBON_GET);
}

void InitTradeBg(void)
{
    InitTradeBgInternal();
}

void DrawTextOnTradeWindow(u8 windowId, const u8 *str, u8 speed)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(15));
    sTradeWindowData->textColors[0] = TEXT_DYNAMIC_COLOR_6;
    sTradeWindowData->textColors[1] = TEXT_COLOR_WHITE;
    sTradeWindowData->textColors[2] = TEXT_COLOR_GREEN;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, sTradeWindowData->textColors, speed, str);
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
        sTradeWindowData->unk_FB = sTradeWindowData->unk_FD = 120;
        sTradeWindowData->unk_FC = 0;
        sTradeWindowData->unk_FE = 160;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(sTradeWindowData->unk_FB, sTradeWindowData->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(sTradeWindowData->unk_FC, sTradeWindowData->unk_FE));

    data[0]++;
    sTradeWindowData->unk_FB -= 5;
    sTradeWindowData->unk_FD += 5;

    if (sTradeWindowData->unk_FB < 80)
    {
        DestroyTask(taskId);
    }
}

static void sub_807F39C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        sTradeWindowData->unk_FB = 80;
        sTradeWindowData->unk_FD = 160;
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(sTradeWindowData->unk_FB, sTradeWindowData->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(sTradeWindowData->unk_FC, sTradeWindowData->unk_FE));

    if (sTradeWindowData->unk_FB != 120)
    {
        data[0]++;
        sTradeWindowData->unk_FB += 5;
        sTradeWindowData->unk_FD -= 5;

        if (sTradeWindowData->unk_FB >= 116)
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
            sTradeWindowData->timer = 0;
            break;
        case 2:
            if (_IsLinkTaskFinished())
            {
                gMain.state = 3;
                StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
                DrawTextOnTradeWindow(0, gStringVar4, 0);
                IncrementGameStat(GAME_STAT_POKEMON_TRADES);
                sub_8153380();
                sTradeWindowData->timer = 0;
            }
            break;
        case 3:
            if (++sTradeWindowData->timer == 5)
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
                sTradeWindowData->timer = 0;
                gMain.state = 3;
            }
            break;
        case 5:
            sub_81533E0();
            gMain.state = 6;
            sTradeWindowData->timer = 0;
            break;
        case 6:
            if (++sTradeWindowData->timer > 10)
            {
                if (GetMultiplayerId() == 0)
                {
                    sTradeWindowData->timer = Random() % 30;
                }
                else
                {
                    sTradeWindowData->timer = 0;
                }
                gMain.state = 7;
            }
            break;
        case 7:
            if (sTradeWindowData->timer == 0)
            {
                sub_8077288(1);
                gMain.state = 8;
            }
            else
            {
                sTradeWindowData->timer--;
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
            if (++sTradeWindowData->timer > 60)
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
