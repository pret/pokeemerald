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
#include "constants/songs.h"
#include "constants/union_room.h"

// The following tags are offsets from GFXTAG_MENU_TEXT
// They're looped over in CB2_CreateTradeMenu and CB2_ReturnToTradeMenu
// and used as indexes into sMenuTextTileBuffers
enum {
    GFXTAG_PLAYER_NAME_L,
    GFXTAG_PLAYER_NAME_M,
    GFXTAG_PLAYER_NAME_R,
    GFXTAG_PARTNER_NAME_L,
    GFXTAG_PARTNER_NAME_M,
    GFXTAG_PARTNER_NAME_R,
    GFXTAG_CANCEL_L,
    GFXTAG_CANCEL_R,
    GFXTAG_CHOOSE_PKMN_L,
    GFXTAG_CHOOSE_PKMN_M,
    GFXTAG_CHOOSE_PKMN_R,
    GFXTAG_CHOOSE_PKMN_EMPTY_1, // 6 sprites to cover the full bottom bar, but only first 3 are needed
    GFXTAG_CHOOSE_PKMN_EMPTY_2,
    GFXTAG_CHOOSE_PKMN_EMPTY_3,
    GFXTAG_MENU_TEXT_COUNT
};
#define GFXTAG_PLAYER_NAME (1 + GFXTAG_PLAYER_NAME_R - GFXTAG_PLAYER_NAME_L)
#define GFXTAG_PARTNER_NAME (1 + GFXTAG_PARTNER_NAME_R - GFXTAG_PARTNER_NAME_L)
#define GFXTAG_CHOOSE_PKMN (1 + GFXTAG_CHOOSE_PKMN_EMPTY_3 - GFXTAG_CHOOSE_PKMN_L)

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

static EWRAM_DATA u8 *sMenuTextAllocBuffer = NULL;

// Bytes 0-2 are used for the player's name text
// Bytes 3-5 are used for the partner's name text
// Bytes 6-7 are used for the Cancel text
// Bytes 8-13 are used for the Choose a Pokemon text
// See the corresponding GFXTAGs in src/data/trade.h
static EWRAM_DATA u8 *sMenuTextTileBuffers[GFXTAG_MENU_TEXT_COUNT] = {NULL};

EWRAM_DATA struct MailStruct gTradeMail[PARTY_SIZE] = {0};
EWRAM_DATA u8 gSelectedTradeMonPositions[2] = {0};
static EWRAM_DATA struct {
    /*0x0000*/ u8 bg2hofs;
    /*0x0001*/ u8 bg3hofs;
    /*0x0002*/ u8 filler_2[38];
    /*0x0028*/ u8 partySpriteIds[2][PARTY_SIZE];
    /*0x0034*/ u8 cursorSpriteId;
    /*0x0035*/ u8 cursorPosition;
    /*0x0036*/ u8 partyCounts[2];
    /*0x0038*/ bool8 monPresent[PARTY_SIZE * 2];
    /*0x0044*/ bool8 neverRead_44;
    /*0x0045*/ bool8 isLiveMon[2][PARTY_SIZE];
    /*0x0051*/ bool8 isEgg[2][PARTY_SIZE];
    /*0x005D*/ u8 hpBarLevels[2][PARTY_SIZE];
    /*0x0069*/ u8 bufferPartyState;
    /*0x006A*/ u8 filler_6A[5];
    /*0x006F*/ u8 tradeMenuFunc;
    /*0x0070*/ u8 neverRead_70;
    /*0x0071*/ u8 filler_71;
    /*0x0072*/ u16 bottomTextTileStart;
    /*0x0074*/ u8 drawPartyState[2];
    /*0x0076*/ u8 selectedMonIdx[2];
    /*0x0078*/ u8 playerLinkFlagChoseAction;
    /*0x0079*/ u8 partnerLinkFlagChoseAction;
    /*0x007A*/ u8 playerLinkFlagStatus;
    /*0x007B*/ u8 partnerLinkFlagStatus;
    /*0x007C*/ u8 filler_7C[2];
    /*0x007E*/ u8 partnerCursorPosition;
    /*0x007F*/ u8 unused_7F;
    /*0x0080*/ u16 linkData[20];
    /*0x00A8*/ u8 timer;
    /*0x00A9*/ u8 giftRibbons[GIFT_RIBBONS_COUNT];
    /*0x00B4*/ u8 filler_B4[0x81C];
    /*0x08D0*/ struct {
        bool8 queued;
        u16 queueDelay;
        u8 actionId;
    } queuedActions[4];
    /*0x08F0*/ u16 tilemapBuffer[0x400];
} *sTradeMenuData = {NULL};

static EWRAM_DATA struct {
    /*0x00*/ struct Pokemon mon;
    /*0x64*/ u32 timer;
    /*0x68*/ u32 monPersonalities[2];
    /*0x70*/ u8 filler_70[2];
    /*0x72*/ u8 playerLinkFlagFinishTrade;
    /*0x73*/ u8 partnerLinkFlagFinishTrade;
    /*0x74*/ u16 linkData[10];
    /*0x88*/ u8 linkTimeoutZero1;
    /*0x89*/ u8 linkTimeoutZero2;
    /*0x8A*/ u16 linkTimeoutCounter;
    /*0x8C*/ u16 neverRead_8C;
    /*0x8E*/ u8 monSpriteIds[2];
    /*0x90*/ u8 connectionSpriteId1; // Multi-purpose sprite ids used during the transfer sequence
    /*0x91*/ u8 connectionSpriteId2;
    /*0x92*/ u8 cableEndSpriteId;
    /*0x93*/ u8 sendTradeFinishState;
    /*0x94*/ u16 state;
    /*0x96*/ u8 filler_96[0xD2 - 0x96];
    /*0xD2*/ u8 releasePokeballSpriteId;
    /*0xD3*/ u8 bouncingPokeballSpriteId;
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
    /*0xEA*/ u16 gbaScale;
    /*0xEC*/ u16 alpha;
    /*0xEE*/ bool8 isLinkTrade;
    /*0xF0*/ u16 monSpecies[2];
    /*0xF4*/ u16 cachedMapMusic;
    /*0xF6*/ u8 textColors[3];
    /*0xF9*/ u8 filler_F9;
    /*0xFA*/ bool8 isCableTrade;
    /*0xFB*/ u8 wirelessWinLeft;
    /*0xFC*/ u8 wirelessWinTop;
    /*0xFD*/ u8 wirelessWinRight;
    /*0xFE*/ u8 wirelessWinBottom;
} *sTradeData = {NULL};

static bool32 IsWirelessTrade(void);
static void CB2_CreateTradeMenu(void);
static void VBlankCB_TradeMenu(void);
static void CB2_TradeMenu(void);
static void LoadTradeBgGfx(u8);
static void SetTradePartyMonsVisible(void);
static bool8 BufferTradeParties(void);
static void CB1_SendOrReactToLinkTradeData(void);
static void CallTradeMenuFunc(void);
static void SetSelectedMon(u8);
static void DrawTradeMenuParty(u8);
static u8 GetMonNicknameWidth(u8 *, u8, u8);
static void BufferTradeMonMoves(u8 *, u8, u8);
static void PrintPartyNicknamesForTradeMenu(u8);
static void DrawTradeMenuPartyMonInfo(u8, u8, u8, u8, u8, u8);
static void DrawTradeMenuPartyInfo(u8);
static void PrintNicknamesForTradeMenu(void);
static void RedrawTradeMenuParty(u8);
static void Task_DrawSelectionSummary(u8);
static void Task_DrawSelectionTrade(u8);
static void QueueAction(u16, u8);
static u32 GetNumQueuedActions(void);
static void DoQueuedActions(void);
static void PrintTradeMessage(u8);
static bool8 LoadTradeMenuSpriteSheetsAndPalettes(void);
static void DrawBottomRowText(const u8 *, u8 *, u8);
static void SetTradePartyLiveStatuses(u8);
static void GetTradePartyHPBarLevels(u8);
static void SetTradePartyHPBarSprites(void);
static void SaveTradeGiftRibbons(void);
static u32 CanTradeSelectedMon(struct Pokemon *, int, int);
static void SpriteCB_LinkMonGlow(struct Sprite *);
static void SpriteCB_LinkMonShadow(struct Sprite *);
static void SpriteCB_CableEndSending(struct Sprite *);
static void SpriteCB_CableEndReceiving(struct Sprite *);
static void SpriteCB_GbaScreen(struct Sprite *);
static void InitTradeBgInternal(void);
static void CB2_UpdateInGameTrade(void);
static void SetTradeSequenceBgGpuRegs(u8);
static void LoadTradeSequenceSpriteSheetsAndPalettes(void);
static void BufferTradeSceneStrings(void);
static bool8 AnimateTradeSequence(void);
static bool8 AnimateTradeSequenceCable(void);
static bool8 AnimateTradeSequenceWireless(void);
static void SpriteCB_BouncingPokeball(struct Sprite *);
static void SpriteCB_BouncingPokeballDepart(struct Sprite *);
static void SpriteCB_BouncingPokeballDepartEnd(struct Sprite *);
static void SpriteCB_BouncingPokeballArrive(struct Sprite *);
static void BufferInGameTradeMonName(void);
static void SetInGameTradeMail(struct MailStruct *, const struct InGameTrade *);
static void CB2_UpdateLinkTrade(void);
static void CB2_TryFinishTrade(void);
static void CB2_SaveAndEndTrade(void);
static void CB2_FreeTradeData(void);
static void Task_InGameTrade(u8);
static void CheckPartnersMonForRibbons(void);
static void Task_AnimateWirelessSignal(u8);
static void Task_NarrowWindowForCrossing_Wireless(u8);
static void Task_NarrowWindowForCrossing_Cable(u8);
static void CB2_SaveAndEndWirelessTrade(void);

#include "data/trade.h"

static bool8 SendLinkData(const void *linkData, u32 size)
{
    if (gPlayerCurrActivity == ACTIVITY_29)
    {
        rfu_NI_setSendData(lman.acceptSlot_flag, 84, linkData, size);
        return TRUE;
    }
    else
    {
        return SendBlock(0, linkData, size);
    }
}

static void RequestLinkData(u8 type)
{
    SendBlockRequest(type);
}

static bool32 IsLinkTradeTaskFinished(void)
{
    if (gPlayerCurrActivity == ACTIVITY_29)
    {
        if (gRfuSlotStatusNI[sub_800E87C(lman.acceptSlot_flag)]->send.state == 0)
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
        rfu_clearSlot(12, lman.acceptSlot_flag);
    else
        ResetBlockReceivedFlags();
}

static void TradeResetReceivedFlag(u32 who)
{
    if (IsWirelessTrade())
        rfu_clearSlot(12, lman.acceptSlot_flag);
    else
        ResetBlockReceivedFlag(who);
}

static bool32 IsWirelessTrade(void)
{
    if (gWirelessCommType && gPlayerCurrActivity == ACTIVITY_29)
        return TRUE;
    else
        return FALSE;
}

static void SetTradeLinkStandbyCallback(u8 unused)
{
    SetLinkStandbyCallback();
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

    SetVBlankCallback(VBlankCB_TradeMenu);
    LoadPalette(gUnknown_0860F074, 0xF0, 20);
    LoadPalette(gUnknown_0860F074, 0xD0, 20);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sTradeMenuBgTemplates, ARRAY_COUNT(sTradeMenuBgTemplates));
    SetBgTilemapBuffer(1, sTradeMenuData->tilemapBuffer);

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
        sTradeMenuData->bufferPartyState = 0;
        sTradeMenuData->tradeMenuFunc = 0;
        sTradeMenuData->neverRead_70 = 0;
        sTradeMenuData->drawPartyState[TRADE_PLAYER] = 0;
        sTradeMenuData->drawPartyState[TRADE_PARTNER] = 0;
        sTradeMenuData->playerLinkFlagStatus = 0;
        sTradeMenuData->partnerLinkFlagStatus = 0;
        sTradeMenuData->timer = 0;
    }
}

void CB2_StartCreateTradeMenu(void)
{
    SetMainCallback2(CB2_CreateTradeMenu);
    gMain.callback1 = NULL;
    gEnemyPartyCount = 0;
}

static void CB2_CreateTradeMenu(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        sTradeMenuData = AllocZeroed(sizeof(*sTradeMenuData));
        InitTradeMenu();
        sMenuTextAllocBuffer = AllocZeroed(GFXTAG_MENU_TEXT_COUNT * 256);

        for (i = 0; i < GFXTAG_MENU_TEXT_COUNT; i++)
            sMenuTextTileBuffers[i] = &sMenuTextAllocBuffer[i * 256];

        gMain.state++;
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = FALSE;

        for (i = 0; i < PARTY_SIZE; i++)
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);

        PrintTradeMessage(TRADE_MSG_STANDBY);
        ShowBg(0);

        if (!gReceivedRemoteLinkPlayers)
        {
            gLinkType = LINKTYPE_TRADE_CONNECTING;
            sTradeMenuData->timer = 0;

            if (gWirelessCommType)
            {
                SetWirelessCommType1();
                OpenLink();
                CreateTask_RfuIdle();
            }
            else
            {
                OpenLink();
                gMain.state++;
                CreateTask(Task_WaitForLinkPlayerConnection, 1);
            }
        }
        else
        {
            gMain.state = 4;
        }
        break;
    case 2:
        sTradeMenuData->timer++;
        if (sTradeMenuData->timer > 11)
        {
            sTradeMenuData->timer = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
        {
            if (IsLinkMaster())
            {
                if (++sTradeMenuData->timer > 30)
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
            DestroyTask_RfuIdle();
            CalculatePlayerPartyCount();
            gMain.state++;
            sTradeMenuData->timer = 0;
            if (gWirelessCommType)
            {
                sub_801048C(TRUE);
                SetLinkStandbyCallback();
            }
        }
        break;
    case 5:
        if (gWirelessCommType)
        {
            if (IsLinkRfuTaskFinished())
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
        if (BufferTradeParties())
        {
            SaveTradeGiftRibbons();
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
            sTradeMenuData->partySpriteIds[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY));
        }

        for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeMenuData->partySpriteIds[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY));
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        DrawHeldItemIconsForTrade(&sTradeMenuData->partyCounts[0], sTradeMenuData->partySpriteIds[0], TRADE_PLAYER);
        gMain.state++;
        break;
    case 9:
        DrawHeldItemIconsForTrade(&sTradeMenuData->partyCounts[0], sTradeMenuData->partySpriteIds[0], TRADE_PARTNER);
        gMain.state++;
        break;
    case 10:
        DrawTextWindowAndBufferTiles(gSaveBlock2Ptr->playerName, sMenuTextTileBuffers[GFXTAG_PLAYER_NAME_L], 0, 0, 3);
        id = GetMultiplayerId();
        DrawTextWindowAndBufferTiles(gLinkPlayers[id ^ 1].name, sMenuTextTileBuffers[GFXTAG_PARTNER_NAME_L], 0, 0, 3);
        DrawTextWindowAndBufferTiles(sTradeActionTexts[TRADE_TEXT_CANCEL], sMenuTextTileBuffers[GFXTAG_CANCEL_L], 0, 0, 2);
        DrawBottomRowText(sTradeActionTexts[TRADE_TEXT_CHOOSE_MON], sMenuTextTileBuffers[GFXTAG_CHOOSE_PKMN_L], 24);
        gMain.state++;
        sTradeMenuData->timer = 0;
        break;
    case 11:
        if (LoadTradeMenuSpriteSheetsAndPalettes())
            gMain.state++;
        break;
    case 12:
        // Create player's name text sprites
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < GFXTAG_PLAYER_NAME; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PLAYER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        // Create partner's name text sprites
        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < GFXTAG_PARTNER_NAME; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PARTNER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        // Create Cancel text sprites
        temp = sSpriteTemplate_MenuText;
        temp.tileTag += GFXTAG_CANCEL_L;
        CreateSprite(&temp, 215, 152, 1);
        temp = sSpriteTemplate_MenuText;
        temp.tileTag += GFXTAG_CANCEL_R;
        CreateSprite(&temp, 247, 152, 1);

        // Create Choose a Pokémon text sprites (only 3 are needed, other 3 are empty)
        for (i = 0; i < GFXTAG_CHOOSE_PKMN; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_CHOOSE_PKMN_L;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        sTradeMenuData->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor, sTradeMonSpriteCoords[0][0] * 8 + 32, sTradeMonSpriteCoords[0][1] * 8, 2);
        sTradeMenuData->cursorPosition = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        SetTradePartyLiveStatuses(TRADE_PLAYER);
        PrintPartyNicknamesForTradeMenu(TRADE_PLAYER);
        sTradeMenuData->bg2hofs = 0;
        sTradeMenuData->bg3hofs = 0;
        SetTradePartyMonsVisible();
        gMain.state++;
        PlayBGM(MUS_SCHOOL);
        break;
    case 15:
        SetTradePartyLiveStatuses(TRADE_PARTNER);
        PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);
        gMain.state++;
        // fallthrough
    case 16:
        LoadTradeBgGfx(0);
        gMain.state++;
        break;
    case 17:
        LoadTradeBgGfx(1);
        gMain.state++;
        break;
    case 18:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        LoadTradeBgGfx(2);
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
            gMain.callback1 = CB1_SendOrReactToLinkTradeData;
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

static void CB2_ReturnToTradeMenu(void)
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
        sTradeMenuData->timer = 0;
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
            sTradeMenuData->partySpriteIds[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY));
        }

        for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeMenuData->partySpriteIds[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY));
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        DrawHeldItemIconsForTrade(&sTradeMenuData->partyCounts[0], sTradeMenuData->partySpriteIds[0], TRADE_PLAYER);
        gMain.state++;
        break;
    case 9:
        DrawHeldItemIconsForTrade(&sTradeMenuData->partyCounts[0], sTradeMenuData->partySpriteIds[0], TRADE_PARTNER);
        gMain.state++;
        break;
    case 10:
        DrawTextWindowAndBufferTiles(gSaveBlock2Ptr->playerName, sMenuTextTileBuffers[GFXTAG_PLAYER_NAME_L], 0, 0, 3);
        id = GetMultiplayerId();
        DrawTextWindowAndBufferTiles(gLinkPlayers[id ^ 1].name, sMenuTextTileBuffers[GFXTAG_PARTNER_NAME_L], 0, 0, 3);
        DrawTextWindowAndBufferTiles(sTradeActionTexts[TRADE_TEXT_CANCEL], sMenuTextTileBuffers[GFXTAG_CANCEL_L], 0, 0, 2);
        DrawBottomRowText(sTradeActionTexts[TRADE_TEXT_CHOOSE_MON], sMenuTextTileBuffers[GFXTAG_CHOOSE_PKMN_L], 24);
        gMain.state++;
        sTradeMenuData->timer = 0;
        break;
    case 11:
        if (LoadTradeMenuSpriteSheetsAndPalettes())
            gMain.state++;
        break;
    case 12:
        // Create player's name text sprites
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < GFXTAG_PLAYER_NAME; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PLAYER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        // Create partner's name text sprites
        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < GFXTAG_PARTNER_NAME; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PARTNER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        // Create Cancel text sprites
        temp = sSpriteTemplate_MenuText;
        temp.tileTag += GFXTAG_CANCEL_L;
        CreateSprite(&temp, 215, 152, 1);
        temp = sSpriteTemplate_MenuText;
        temp.tileTag += GFXTAG_CANCEL_R;
        CreateSprite(&temp, 247, 152, 1);

        // Create Choose a Pokémon text sprites
        for (i = 0; i < GFXTAG_CHOOSE_PKMN; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_CHOOSE_PKMN_L;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        if (sTradeMenuData->cursorPosition < PARTY_SIZE)
            sTradeMenuData->cursorPosition = gLastViewedMonIndex;
        else
            sTradeMenuData->cursorPosition = gLastViewedMonIndex + PARTY_SIZE;

        sTradeMenuData->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor, 
                                                     sTradeMonSpriteCoords[sTradeMenuData->cursorPosition][0] * 8 + 32, 
                                                     sTradeMonSpriteCoords[sTradeMenuData->cursorPosition][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        LoadTradeBgGfx(0);
        gMain.state++;
        break;
    case 17:
        LoadTradeBgGfx(1);
        sTradeMenuData->bg2hofs = 0;
        sTradeMenuData->bg3hofs = 0;
        SetTradePartyMonsVisible();
        gMain.state++;
        break;
    case 18:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        LoadTradeBgGfx(2);
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

static void VBlankCB_TradeMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void LinkTradeFadeOut(void)
{
    if (++sTradeMenuData->timer > 15)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_LINK_TRADE_WAIT_FADE;
    }
}

static void LinkTradeWaitForFade(void)
{
    if (!gPaletteFade.active)
    {
        gSelectedTradeMonPositions[TRADE_PLAYER] = sTradeMenuData->cursorPosition;
        gSelectedTradeMonPositions[TRADE_PARTNER] = sTradeMenuData->partnerCursorPosition;

        if (gWirelessCommType)
        {
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_LINK_TRADE_WAIT_QUEUE;
        }
        else
        {
            SetCloseLinkCallbackAndType(32);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_START_LINK_TRADE;
        }
    }
}

static void SetLinkTradeCallbacks(void)
{
    gMain.savedCallback = CB2_StartCreateTradeMenu;

    // Wireless Link Trade
    if (gWirelessCommType)
    {
        if (IsLinkRfuTaskFinished())
        {
            Free(sMenuTextAllocBuffer);
            FreeAllWindowBuffers();
            Free(sTradeMenuData);
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
            Free(sMenuTextAllocBuffer);
            FreeAllWindowBuffers();
            Free(sTradeMenuData);
            gMain.callback1 = NULL;
            SetMainCallback2(CB2_LinkTrade);
        }
    }
}

static void CB2_TradeMenu(void)
{
    CallTradeMenuFunc();
    DoQueuedActions();
    DrawTradeMenuParty(TRADE_PLAYER);
    DrawTradeMenuParty(TRADE_PARTNER);

    SetGpuReg(REG_OFFSET_BG2HOFS, sTradeMenuData->bg2hofs++);
    SetGpuReg(REG_OFFSET_BG3HOFS, sTradeMenuData->bg3hofs--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void LoadTradeBgGfx(u8 state)
{
    int i;

    switch (state)
    {
    case 0:
        LoadPalette(gTradeMenu_Pal, 0, 0x60);
        LoadBgTiles(1, gTradeMenu_Gfx, 0x1280, 0);
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDCF04, 0, 0, 32, 20, 0);
        LoadBgTilemap(2, sTradeStripesBG2Tilemap, 0x800, 0);
        break;
    case 1:
        LoadBgTilemap(3, sTradeStripesBG3Tilemap, 0x800, 0);
        DrawTradeMenuPartyInfo(TRADE_PLAYER);
        DrawTradeMenuPartyInfo(TRADE_PARTNER);
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
        if (i < sTradeMenuData->partyCounts[TRADE_PLAYER])
        {
            gSprites[sTradeMenuData->partySpriteIds[TRADE_PLAYER][i]].invisible = FALSE;
            sTradeMenuData->monPresent[i] = TRUE;
        }
        else
        {
            sTradeMenuData->monPresent[i] = FALSE;
        }

        if (i < sTradeMenuData->partyCounts[TRADE_PARTNER])
        {
            gSprites[sTradeMenuData->partySpriteIds[TRADE_PARTNER][i]].invisible = FALSE;
            sTradeMenuData->monPresent[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            sTradeMenuData->monPresent[i + PARTY_SIZE] = FALSE;
        }
    }

    sTradeMenuData->neverRead_44 = TRUE;
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

static bool8 BufferTradeParties(void)
{
    u8 id = GetMultiplayerId();
    int i;
    struct Pokemon *mon;

    switch (sTradeMenuData->bufferPartyState)
    {
    case 0:
        // The parties are sent in pairs rather than all at once
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[0], 2 * sizeof(struct Pokemon));
        sTradeMenuData->bufferPartyState++;
        sTradeMenuData->timer = 0;
        break;
    case 1:
        if (IsLinkTradeTaskFinished())
        {
            if (_GetBlockReceivedStatus() == 0)
            {
                sTradeMenuData->bufferPartyState++;
            }
            else
            {
                TradeResetReceivedFlags();
                sTradeMenuData->bufferPartyState++;
            }
        }
        break;
    case 3:
        if (id == 0)
        {
            RequestLinkData(1);
        }
        sTradeMenuData->bufferPartyState++;
        break;
    case 4:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[0], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeMenuData->bufferPartyState++;
        }
        break;
    case 5:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[2], 2 * sizeof(struct Pokemon));
        sTradeMenuData->bufferPartyState++;
        break;
    case 7:
        if (id == 0)
        {
            RequestLinkData(1);
        }
        sTradeMenuData->bufferPartyState++;
        break;
    case 8:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[2], gBlockRecvBuffer[id ^ 1],  2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeMenuData->bufferPartyState++;
        }
        break;
    case 9:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[4], 2 * sizeof(struct Pokemon));
        sTradeMenuData->bufferPartyState++;
        break;
    case 11:
        if (id == 0)
        {
            RequestLinkData(1);
        }
        sTradeMenuData->bufferPartyState++;
        break;
    case 12:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[4], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeMenuData->bufferPartyState++;
        }
        break;
    case 13:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->mail, PARTY_SIZE * sizeof(struct MailStruct) + 4);
        sTradeMenuData->bufferPartyState++;
        break;
    case 15:
        if (id == 0)
        {
            RequestLinkData(3);
        }
        sTradeMenuData->bufferPartyState++;
        break;
    case 16:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(gTradeMail, gBlockRecvBuffer[id ^ 1], PARTY_SIZE * sizeof(struct MailStruct));
            TradeResetReceivedFlags();
            sTradeMenuData->bufferPartyState++;
        }
        break;
    case 17:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, sizeof(sTradeMenuData->giftRibbons));
        sTradeMenuData->bufferPartyState++;
        break;
    case 19:
        if (id == 0)
        {
            RequestLinkData(4);
        }
        sTradeMenuData->bufferPartyState++;
        break;
    case 20:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(sTradeMenuData->giftRibbons, gBlockRecvBuffer[id ^ 1], sizeof(sTradeMenuData->giftRibbons));
            TradeResetReceivedFlags();
            sTradeMenuData->bufferPartyState++;
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
    // Delay until next state
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        sTradeMenuData->timer++;
        if (sTradeMenuData->timer > 10)
        {
            sTradeMenuData->timer = 0;
            sTradeMenuData->bufferPartyState++;
        }
        break;
    }
    return FALSE;
}

static void DrawIsThisTradeOkay(void)
{
    DrawBottomRowText(sText_IsThisTradeOkay, (void *)(OBJ_VRAM0 + (sTradeMenuData->bottomTextTileStart * 32)), 24);
}

// mpId is unused
static void UpdateLinkTradeFlags(u8 mpId, u8 status)
{
    if (status & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case LINKCMD_REQUEST_CANCEL:
            sTradeMenuData->playerLinkFlagChoseAction = WANTS_TO_CANCEL;
            break;
        case LINKCMD_READY_TO_TRADE:
            sTradeMenuData->playerLinkFlagChoseAction = WANTS_TO_TRADE;
            break;
        case LINKCMD_INIT_BLOCK:
            sTradeMenuData->playerLinkFlagStatus = INITIATE_TRADE;
            break;
        case LINKCMD_READY_CANCEL_TRADE:
            sTradeMenuData->playerLinkFlagStatus = CANCEL_TRADE;
            break;
        }
        TradeResetReceivedFlag(0);
    }

    if (status & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case LINKCMD_REQUEST_CANCEL:
            sTradeMenuData->partnerLinkFlagChoseAction = WANTS_TO_CANCEL;
            break;
        case LINKCMD_READY_TO_TRADE:
            sTradeMenuData->partnerCursorPosition = gBlockRecvBuffer[1][1] + 6;
            sTradeMenuData->partnerLinkFlagChoseAction = WANTS_TO_TRADE;
            break;
        case LINKCMD_INIT_BLOCK:
            sTradeMenuData->partnerLinkFlagStatus = INITIATE_TRADE;
            break;
        case LINKCMD_READY_CANCEL_TRADE:
            sTradeMenuData->partnerLinkFlagStatus = CANCEL_TRADE;
            break;
        }
        TradeResetReceivedFlag(1);
    }
}

// mpId is unused
static void ReactToLinkTradeData(u8 mpId, u8 status)
{
    if (status & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case LINKCMD_BOTH_CANCEL_TRADE:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            PrintTradeMessage(TRADE_MSG_WAITING_FOR_FRIEND);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CANCEL_TRADE_1;
            break;
        case LINKCMD_PARTNER_CANCEL_TRADE:
            PrintTradeMessage(TRADE_MSG_FRIEND_WANTS_TO_TRADE);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
            break;
        case LINKCMD_SET_MONS_TO_TRADE:
            sTradeMenuData->partnerCursorPosition = gBlockRecvBuffer[0][1] + 6;
            rbox_fill_rectangle(0);
            SetSelectedMon(sTradeMenuData->cursorPosition);
            SetSelectedMon(sTradeMenuData->partnerCursorPosition);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CONFIRM_TRADE_PROMPT;
            break;
        case LINKCMD_START_TRADE:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_LINK_TRADE_WAIT_FADE;
            break;
        case LINKCMD_PLAYER_CANCEL_TRADE:
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
        }
        TradeResetReceivedFlag(0);
    }

    if (status & 2)
        TradeResetReceivedFlag(1);
}

static void QueueLinkTradeData(void)
{
    if (sTradeMenuData->playerLinkFlagChoseAction && sTradeMenuData->partnerLinkFlagChoseAction)
    {
        if (sTradeMenuData->playerLinkFlagChoseAction == WANTS_TO_TRADE
            && sTradeMenuData->partnerLinkFlagChoseAction == WANTS_TO_TRADE)
        {
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_BOTH_MONS_SELECTED;
            sTradeMenuData->linkData[0] = LINKCMD_SET_MONS_TO_TRADE;
            sTradeMenuData->linkData[1] = sTradeMenuData->cursorPosition;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenuData->playerLinkFlagChoseAction = sTradeMenuData->partnerLinkFlagChoseAction = 0;
        }
        else if (sTradeMenuData->playerLinkFlagChoseAction == WANTS_TO_TRADE
              && sTradeMenuData->partnerLinkFlagChoseAction == WANTS_TO_CANCEL)
        {
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeMenuData->linkData[0] = LINKCMD_PARTNER_CANCEL_TRADE;
            sTradeMenuData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenuData->playerLinkFlagStatus = sTradeMenuData->partnerLinkFlagStatus = 0;
            sTradeMenuData->playerLinkFlagChoseAction = sTradeMenuData->partnerLinkFlagChoseAction = 0;
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
        }
        else if (sTradeMenuData->playerLinkFlagChoseAction == WANTS_TO_CANCEL
              && sTradeMenuData->partnerLinkFlagChoseAction == WANTS_TO_TRADE)
        {
            PrintTradeMessage(TRADE_MSG_FRIEND_WANTS_TO_TRADE);
            sTradeMenuData->linkData[0] = LINKCMD_PLAYER_CANCEL_TRADE;
            sTradeMenuData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenuData->playerLinkFlagStatus = sTradeMenuData->partnerLinkFlagStatus = 0;
            sTradeMenuData->playerLinkFlagChoseAction = sTradeMenuData->partnerLinkFlagChoseAction = 0;
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
        }
        else if (sTradeMenuData->playerLinkFlagChoseAction == WANTS_TO_CANCEL
              && sTradeMenuData->partnerLinkFlagChoseAction == WANTS_TO_CANCEL)
        {
            sTradeMenuData->linkData[0] = LINKCMD_BOTH_CANCEL_TRADE;
            sTradeMenuData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->playerLinkFlagChoseAction = sTradeMenuData->partnerLinkFlagChoseAction = 0;
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CANCEL_TRADE_1;
        }
    }

    if (sTradeMenuData->playerLinkFlagStatus && sTradeMenuData->partnerLinkFlagStatus)
    {
        if (sTradeMenuData->playerLinkFlagStatus == INITIATE_TRADE
         && sTradeMenuData->partnerLinkFlagStatus == INITIATE_TRADE)
        {
            sTradeMenuData->linkData[0] = LINKCMD_START_TRADE;
            sTradeMenuData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenuData->playerLinkFlagStatus = 0;
            sTradeMenuData->partnerLinkFlagStatus = 0;
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_LINK_TRADE_FADE_OUT;
        }

        if (sTradeMenuData->playerLinkFlagStatus == CANCEL_TRADE
         || sTradeMenuData->partnerLinkFlagStatus == CANCEL_TRADE)
        {
            PrintTradeMessage(TRADE_MSG_CANCELED);
            sTradeMenuData->linkData[0] = LINKCMD_PLAYER_CANCEL_TRADE;
            sTradeMenuData->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenuData->playerLinkFlagStatus = 0;
            sTradeMenuData->partnerLinkFlagStatus = 0;
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
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
    _SetLinkData(sTradeMenuData->linkData, linkCmd, cursorPosition);
}

static void CB1_SendOrReactToLinkTradeData(void)
{
    u8 mpId = GetMultiplayerId();
    u8 status;

    if ((status = _GetBlockReceivedStatus()))
    {
        if (mpId == 0)
            UpdateLinkTradeFlags(mpId, status);
        else
            ReactToLinkTradeData(mpId, status);
    }

    if (mpId == 0)
        QueueLinkTradeData();
}

static u8 GetNewTradeMenuPosition(u8 oldPosition, u8 direction)
{
    int i;
    u8 newPosition = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sTradeMenuData->monPresent[sTradeNextSelectedMonTable[oldPosition][direction][i]] == TRUE)
        {
            newPosition = sTradeNextSelectedMonTable[oldPosition][direction][i];
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
        StartSpriteAnim(&gSprites[sTradeMenuData->cursorSpriteId], CURSOR_ANIM_ON_CANCEL);
        gSprites[sTradeMenuData->cursorSpriteId].x = DISPLAY_WIDTH - 16;
        gSprites[sTradeMenuData->cursorSpriteId].y = DISPLAY_HEIGHT;
    }
    else
    {
        StartSpriteAnim(&gSprites[sTradeMenuData->cursorSpriteId], CURSOR_ANIM_NORMAL);
        gSprites[sTradeMenuData->cursorSpriteId].x = sTradeMonSpriteCoords[newPosition][0] * 8 + 32;
        gSprites[sTradeMenuData->cursorSpriteId].y = sTradeMonSpriteCoords[newPosition][1] * 8;
    }

    if (*cursorPosition != newPosition)
    {
        PlaySE(SE_SELECT);
    }

    *cursorPosition = newPosition;
}

static void SetReadyToTrade(void)
{
    PrintTradeMessage(TRADE_MSG_STANDBY);
    sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_STANDBY;

    if (GetMultiplayerId() == 1)
        SetLinkData(LINKCMD_READY_TO_TRADE, sTradeMenuData->cursorPosition);
    else
        sTradeMenuData->playerLinkFlagChoseAction = WANTS_TO_TRADE;
}

static void TradeMenuProcessInput(void)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 0);
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 1);
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 2);
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        TradeMenuMoveCursor(&sTradeMenuData->cursorPosition, 3);
    }

    if (JOY_NEW(A_BUTTON))
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
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_SELECTED_MON;
        }
        // Cursor is in partner's party
        else if (sTradeMenuData->cursorPosition < PARTY_SIZE * 2)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_SHOW_MON_SUMMARY;
        }
        // Cursor is on Cancel
        else if (sTradeMenuData->cursorPosition == PARTY_SIZE * 2)
        {
            CreateYesNoMenu(&sTradeYesNoWindowTemplate, 1, 14, 0);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CANCEL_TRADE_PROMPT;
            DrawBottomRowText(sTradeActionTexts[TRADE_TEXT_CANCEL_TRADE], (void *)(OBJ_VRAM0 + sTradeMenuData->bottomTextTileStart * 32), 24);
        }
    }
}

static void TradeMenuChooseMon(void)
{
    PrintNicknamesForTradeMenu();
    sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_MAIN_MENU;
    gSprites[sTradeMenuData->cursorSpriteId].invisible = FALSE;
    DrawBottomRowText(sTradeActionTexts[TRADE_TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + sTradeMenuData->bottomTextTileStart * 32), 24);
}

static void TradeMenuProcessInput_SelectedMon(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        TradeMenuChooseMon();
        break;
    case MENU_NOTHING_CHOSEN:
        break;
    case 0: // Summary
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_SHOW_MON_SUMMARY;
        break;
    case 1: // Trade
        switch (CanTradeSelectedMon(gPlayerParty, gPlayerPartyCount, sTradeMenuData->cursorPosition))
        {
        case CAN_TRADE_MON:
            SetReadyToTrade();
            gSprites[sTradeMenuData->cursorSpriteId].invisible = TRUE;
            break;
        case CANT_TRADE_LAST_MON:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_ONLY_MON2);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
            break;
        case CANT_TRADE_NATIONAL:
        case CANT_TRADE_INVALID_MON:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_MON_CANT_BE_TRADED);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
            break;
        case CANT_TRADE_EGG_YET:
        case CANT_TRADE_EGG_YET2:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_EGG_CANT_BE_TRADED);
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_REDRAW_MAIN_MENU;
            break;
        }
        break;
    }
}

static void ChooseMonAfterButtonPress(void)
{
    if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON)))
    {
        PlaySE(SE_SELECT);
        TradeMenuChooseMon();
    }
}

static void TradeMenuShowMonSummaryScreen(void)
{
    if (!gPaletteFade.active)
    {
        // Player's party
        if (sTradeMenuData->cursorPosition < PARTY_SIZE)
            ShowPokemonSummaryScreen(SUMMARY_MODE_LOCK_MOVES, gPlayerParty, sTradeMenuData->cursorPosition, sTradeMenuData->partyCounts[TRADE_PLAYER] - 1, CB2_ReturnToTradeMenu);
        // Partner's party
        else
            ShowPokemonSummaryScreen(SUMMARY_MODE_LOCK_MOVES, gEnemyParty, sTradeMenuData->cursorPosition - PARTY_SIZE, sTradeMenuData->partyCounts[TRADE_PARTNER] - 1, CB2_ReturnToTradeMenu);
        FreeAllWindowBuffers();
    }
}

static u8 CheckValidityOfTradeMons(u8 *aliveMons, u8 playerPartyCount, u8 playerMonIdx, u8 partnerMonIdx)
{
    int i;
    u16 partnerSpecies;
    u8 hasLiveMon = 0;

    // Make sure mon to be traded isn't player's last alive mon
    for (i = 0; i < playerPartyCount; i++)
    {
        if (playerMonIdx != i)
            hasLiveMon += aliveMons[i];
    }
    partnerMonIdx %= PARTY_SIZE;
    partnerSpecies = GetMonData(&gEnemyParty[partnerMonIdx], MON_DATA_SPECIES);

    // Partner cant trade illegitimate Deoxys or Mew
    if (partnerSpecies == SPECIES_DEOXYS || partnerSpecies == SPECIES_MEW)
    {
        if (!GetMonData(&gEnemyParty[partnerMonIdx], MON_DATA_EVENT_LEGAL))
            return PARTNER_MON_INVALID;
    }

    // Partner cant trade Egg or non-Hoenn mon if player doesn't have National Dex
    if (!IsNationalPokedexEnabled())
    {
        if (sTradeMenuData->isEgg[TRADE_PARTNER][partnerMonIdx] || !IsSpeciesInHoennDex(partnerSpecies))
            return PARTNER_MON_INVALID;
    }

    if (hasLiveMon)
        hasLiveMon = BOTH_MONS_VALID;

    return hasLiveMon; //PLAYER_MON_INVALID or BOTH_MONS_VALID
}

// Returns TRUE if the partner's selected mon is invalid, FALSE otherwise
static bool32 CheckMonsBeforeTrade(void)
{
    int i;
    u8 aliveMons[PARTY_SIZE * 2];

    for (i = 0; i < sTradeMenuData->partyCounts[TRADE_PLAYER]; i++)
    {
        aliveMons[i] = sTradeMenuData->isLiveMon[TRADE_PLAYER][i];
    }

    switch (CheckValidityOfTradeMons(aliveMons, sTradeMenuData->partyCounts[TRADE_PLAYER], 
                                                sTradeMenuData->cursorPosition, 
                                                sTradeMenuData->partnerCursorPosition))
    {
    case PLAYER_MON_INVALID:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_ONLY_MON2);
        SetLinkData(LINKCMD_READY_CANCEL_TRADE, 0);
        break;
    case BOTH_MONS_VALID:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_STANDBY);
        SetLinkData(LINKCMD_INIT_BLOCK, 0);
        break;
    case PARTNER_MON_INVALID:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_FRIENDS_MON_CANT_BE_TRADED);
        return TRUE;
    }

    return FALSE;
}

static void ConfirmOrCancelTrade(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Confirm Trade
        if (!CheckMonsBeforeTrade())
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_STANDBY;
        else
            sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_PARTNER_MON_INVALID;

        PutWindowTilemap(17);
        break;
    case 1: // Cancel Trade
    case MENU_B_PRESSED:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_STANDBY);
        if (IsLinkTradeTaskFinished())
            SetLinkData(LINKCMD_READY_CANCEL_TRADE, 0);
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_STANDBY;
        PutWindowTilemap(17);
        break;
    }
}

// Only when choosing Yes to cancel, when No is chosen all are redrawn anyway 
static void RestoreNicknamesCoveredByYesNo(void)
{
    int i;

    for (i = 0; i < sTradeMenuData->partyCounts[1] - 4; i++)
    {
        PutWindowTilemap(i + 12);
        CopyWindowToVram(i + 12, 1);
    }
}

static void CancelTradeYesNo(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // YES, Cancel
        PrintTradeMessage(TRADE_MSG_WAITING_FOR_FRIEND);
        SetLinkData(LINKCMD_REQUEST_CANCEL, 0);
        gSprites[sTradeMenuData->cursorSpriteId].invisible = TRUE;
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_STANDBY;
        RestoreNicknamesCoveredByYesNo();
        break;
    case 1: // NO, Continue
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        TradeMenuChooseMon();
        break;
    }
}

static void SetBothSelectedMons(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        SetSelectedMon(sTradeMenuData->cursorPosition);
        SetSelectedMon(sTradeMenuData->partnerCursorPosition);
    }
    sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CONFIRM_TRADE_PROMPT;
}

static void ConfirmTradePrompt(void)
{
    if (sTradeMenuData->drawPartyState[TRADE_PLAYER] == DRAW_PARTY_FINISH
        && sTradeMenuData->drawPartyState[TRADE_PARTNER] == DRAW_PARTY_FINISH)
    {
        DrawIsThisTradeOkay();
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_DELAY_TRADE_CONFIRM;
    }
}

static void DelayTradeConfirmation(void)
{
    sTradeMenuData->timer++;

    if (sTradeMenuData->timer > 120)
    {
        CreateYesNoMenu(&sTradeYesNoWindowTemplate, 1, 14, 0);
        sTradeMenuData->timer = 0;
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CONFIRM_OR_CANCEL_TRADE;
    }
}

static void RedrawTradeMenuAfterPressA(void)
{
    int i;

    if (JOY_NEW(A_BUTTON))
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
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_MAIN_MENU;
        gSprites[sTradeMenuData->cursorSpriteId].invisible = FALSE;
    }
}

static void CancelTrade_1(void)
{
    if (!gPaletteFade.active)
    {
        if (gWirelessCommType)
        {
            SetLinkStandbyCallback();
        }
        else
        {
            SetCloseLinkCallbackAndType(12);
        }

        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_CANCEL_TRADE_2;
    }
}

static void CancelTrade_2(void)
{
    if (gWirelessCommType)
    {
        if (IsLinkTradeTaskFinished() && GetNumQueuedActions() == 0)
        {
            Free(sMenuTextAllocBuffer);
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
            Free(sMenuTextAllocBuffer);
            Free(sTradeMenuData);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
}

static void LinkTradeWaitForQueue(void)
{
    if (!sub_801048C(FALSE) && GetNumQueuedActions() == 0)
    {
        SetLinkStandbyCallback();
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_START_LINK_TRADE;
    }
}

static void PartnersMonWasInvalid(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        SetLinkData(LINKCMD_READY_CANCEL_TRADE, 0);
        sTradeMenuData->tradeMenuFunc = TRADEMENUFUNC_STANDBY;
    }
}

static void CallTradeMenuFunc(void)
{
    switch (sTradeMenuData->tradeMenuFunc)
    {
    case TRADEMENUFUNC_MAIN_MENU:
        TradeMenuProcessInput();
        break;
    case TRADEMENUFUNC_SELECTED_MON:
        TradeMenuProcessInput_SelectedMon();
        break;
    case TRADEMENUFUNC_SHOW_MON_SUMMARY:
        TradeMenuShowMonSummaryScreen();
        break;
    case TRADEMENUFUNC_CONFIRM_OR_CANCEL_TRADE:
        ConfirmOrCancelTrade();
        break;
    case TRADEMENUFUNC_CANCEL_TRADE_PROMPT:
        CancelTradeYesNo();
        break;
    case TRADEMENUFUNC_BOTH_MONS_SELECTED:
        SetBothSelectedMons();
        break;
    case TRADEMENUFUNC_CONFIRM_TRADE_PROMPT:
        ConfirmTradePrompt();
        break;
    case TRADEMENUFUNC_REDRAW_MAIN_MENU:
        RedrawTradeMenuAfterPressA();
        break;
    case TRADEMENUFUNC_LINK_TRADE_FADE_OUT:
        LinkTradeFadeOut();
        break;
    case TRADEMENUFUNC_LINK_TRADE_WAIT_FADE:
        LinkTradeWaitForFade();
        break;
    case TRADEMENUFUNC_CANCEL_TRADE_1:
        CancelTrade_1();
        break;
    case TRADEMENUFUNC_CANCEL_TRADE_2:
        CancelTrade_2();
        break;
    case TRADEMENUFUNC_START_LINK_TRADE:
        SetLinkTradeCallbacks();
        break;
    case TRADEMENUFUNC_DELAY_TRADE_CONFIRM:
        DelayTradeConfirmation();
        break;
    case TRADEMENUFUNC_UNUSED_15:
        ChooseMonAfterButtonPress();
        break;
    case TRADEMENUFUNC_LINK_TRADE_WAIT_QUEUE:
        LinkTradeWaitForQueue();
        break;
    case TRADEMENUFUNC_PARTNER_MON_INVALID:
        PartnersMonWasInvalid();
        break;
  //case TRADEMENUFUNC_STANDBY: is nop
    }
}

static void SetSelectedMon(u8 cursorPosition)
{
    //cursorPosition 0-5 are the player's mons, 6-11 are the partner's
    u8 whichParty = cursorPosition / PARTY_SIZE;

    if (sTradeMenuData->drawPartyState[whichParty] == 0)
    {
        sTradeMenuData->drawPartyState[whichParty] = 1;
        sTradeMenuData->selectedMonIdx[whichParty] = cursorPosition;
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
    u8 selectedMonIdx = sTradeMenuData->selectedMonIdx[whichParty];

    selectedMonParty = TRADE_PARTNER;
    if (sTradeMenuData->selectedMonIdx[whichParty] < PARTY_SIZE)
        selectedMonParty = TRADE_PLAYER;
    partyIdx = selectedMonIdx % PARTY_SIZE;
    nameStringWidth = 0;

    switch (sTradeMenuData->drawPartyState[whichParty])
    {
    case 1:
        for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
        {
            gSprites[sTradeMenuData->partySpriteIds[0][i + (selectedMonParty * PARTY_SIZE)]].invisible = TRUE;
        }

        for (i = 0; i < 6; i++)
        {
            ClearWindowTilemap(i + (whichParty * PARTY_SIZE + 2));
        }

        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].invisible = FALSE;
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].data[0] = 20;
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].data[2] = (sTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][0]
                                                                                                         + sTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].data[4] = (sTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][1] * 8) - 12;
        StoreSpriteCallbackInData6(&gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]], SpriteCB_MonIcon);
        sTradeMenuData->drawPartyState[whichParty]++;
        TradeMenuBouncePartySprites(&gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]]);
        CopyToBgTilemapBufferRect_ChangePalette(1, sTradePartyBoxTilemap, whichParty * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);

        if (selectedMonParty == TRADE_PLAYER)
            PrintNicknamesForTradeMenu();
        break;
    case 2:
        if (gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].callback == SpriteCB_MonIcon)
            sTradeMenuData->drawPartyState[whichParty] = 3;
        break;
    case 3:
        CopyToBgTilemapBufferRect_ChangePalette(1, sTradeMovesBoxTilemap, selectedMonParty * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].x = (sTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][0]
                                                                                                        + sTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].y = (sTradeMonSpriteCoords[selectedMonParty * PARTY_SIZE][1] * 8) - 12;
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].x2 = 0;
        gSprites[sTradeMenuData->partySpriteIds[0][partyIdx + (selectedMonParty * PARTY_SIZE)]].y2 = 0;
        nameStringWidth = GetMonNicknameWidth(nickname, selectedMonParty, partyIdx);
        AddTextPrinterParameterized3((whichParty * 2) + 14, 0, (80 - nameStringWidth) / 2, 4, sTradeTextColors, 0, nickname);
        BufferTradeMonMoves(movesString, selectedMonParty, partyIdx);
        AddTextPrinterParameterized4((whichParty * 2) + 15, 1, 0, 0, 0, 0, sTradeTextColors, 0, movesString);
        PutWindowTilemap((whichParty * 2) + 14);
        CopyWindowToVram((whichParty * 2) + 14, 3);
        PutWindowTilemap((whichParty * 2) + 15);
        CopyWindowToVram((whichParty * 2) + 15, 3);
        sTradeMenuData->drawPartyState[whichParty]++;
        break;
    case 4:
        DrawTradeMenuPartyMonInfo(whichParty, partyIdx,
            sTradeMenuPartyMonBoxDimensions[whichParty][0] + 4,
            sTradeMenuPartyMonBoxDimensions[whichParty][1] + 1,
            sTradeMenuPartyMonBoxDimensions[whichParty][0],
            sTradeMenuPartyMonBoxDimensions[whichParty][1]);
        sTradeMenuData->drawPartyState[whichParty]++;
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

        StringCopy(str, sText_EmptyString);

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (moves[i] != MOVE_NONE)
            {
                StringAppend(str, gMoveNames[moves[i]]);
            }

            StringAppend(str, sText_NewLine);
        }
    }
    else
    {
        StringCopy(str, sText_EmptyString);
        StringAppend(str, sText_FourQuestionMarks);
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

static void DrawTradeMenuPartyMonInfo(u8 whichParty, u8 monIdx, u8 x, u8 y, u8 width, u8 height)
{
    u8 level;
    u32 symbolTile;
    u8 gender;
    u8 nickname[12];

    CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMenuMonBox_Tilemap, width, height, 6, 3, 0);
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
    sTradeMenuData->tilemapBuffer[(y - 1) * 32 + x + 1] = symbolTile;
}

static void DrawTradeMenuPartyInfo(u8 whichParty)
{
    s32 i;
    for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
    {
        const u8 (*r5)[2];
        const u8 (*r4)[2];
        u32 r0 = 3 * whichParty;
        const u8 (*r1)[2][2] = sTradeMonLevelCoords;

        r5 = r1[r0];
        r4 = sTradeMonBoxCoords[r0];
        DrawTradeMenuPartyMonInfo(
            whichParty,
            i,
            r5[i][0],
            r5[i][1],
            r4[i][0],
            r4[i][1]
        );
    }
}

static void ResetTradeMenuPartyPositions(u8 whichParty)
{
    int i;

    for (i = 0; i < sTradeMenuData->partyCounts[whichParty]; i++)
    {
        gSprites[sTradeMenuData->partySpriteIds[whichParty][i]].invisible = FALSE;
        gSprites[sTradeMenuData->partySpriteIds[whichParty][i]].x = sTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][0] * 8 + 14;
        gSprites[sTradeMenuData->partySpriteIds[whichParty][i]].y = sTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][1] * 8 - 12;
        gSprites[sTradeMenuData->partySpriteIds[whichParty][i]].x2 = 0;
        gSprites[sTradeMenuData->partySpriteIds[whichParty][i]].y2 = 0;
    }
}

static void PrintNicknamesForTradeMenu(void)
{
    rbox_fill_rectangle(1);
  //PrintPartyNicknamesForTradeMenu(TRADE_PLAYER); ?
    PrintPartyNicknamesForTradeMenu(TRADE_PARTNER);
}

static void RedrawTradeMenuParty(u8 whichParty)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, sTradePartyBoxTilemap, whichParty * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    DrawTradeMenuPartyInfo(whichParty);
    PrintPartyNicknamesForTradeMenu(whichParty);
    ResetTradeMenuPartyPositions(whichParty);
    DrawBottomRowText(sTradeActionTexts[TRADE_TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + (sTradeMenuData->bottomTextTileStart * 32)), 24);
    sTradeMenuData->drawPartyState[whichParty] = 0;
}

static void Task_DrawSelectionSummary(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

static void Task_DrawSelectionTrade(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

static void QueueAction(u16 delay, u8 actionId)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenuData->queuedActions); i++)
    {
        if (!sTradeMenuData->queuedActions[i].queued)
        {
            sTradeMenuData->queuedActions[i].queueDelay = delay;
            sTradeMenuData->queuedActions[i].actionId = actionId;
            sTradeMenuData->queuedActions[i].queued = TRUE;
            break;
        }
    }
}

static u32 GetNumQueuedActions(void)
{
    u32 numActions = 0;
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenuData->queuedActions); i++)
    {
        numActions += sTradeMenuData->queuedActions[i].queued;
    }

    return numActions;
}

static void DoQueuedActions(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenuData->queuedActions); i++)
    {
        if (sTradeMenuData->queuedActions[i].queued)
        {
            if (sTradeMenuData->queuedActions[i].queueDelay)
            {
                sTradeMenuData->queuedActions[i].queueDelay--;
            }
            else
            {
                switch (sTradeMenuData->queuedActions[i].actionId)
                {
                case QUEUE_SEND_DATA:
                    SendLinkData(sTradeMenuData->linkData, 20);
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
                sTradeMenuData->queuedActions[i].queued = FALSE;
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

    if (sTradeMenuData->timer < GFXTAG_MENU_TEXT_COUNT)
    {
        sheet.data = sMenuTextTileBuffers[sTradeMenuData->timer];
        sheet.size = 0x100;
        sheet.tag = GFXTAG_MENU_TEXT + sTradeMenuData->timer;
    }

    switch (sTradeMenuData->timer)
    {
    case GFXTAG_PLAYER_NAME_L:
    case GFXTAG_PLAYER_NAME_M:
    case GFXTAG_PLAYER_NAME_R:
    case GFXTAG_PARTNER_NAME_L:
    case GFXTAG_PARTNER_NAME_M:
    case GFXTAG_PARTNER_NAME_R:
    case GFXTAG_CANCEL_L:
    case GFXTAG_CANCEL_R:
        LoadSpriteSheet(&sheet);
        sTradeMenuData->timer++;
        break;
    case GFXTAG_CHOOSE_PKMN_L:
        sTradeMenuData->bottomTextTileStart = LoadSpriteSheet(&sheet);
        sTradeMenuData->timer++;
        break;
    case GFXTAG_CHOOSE_PKMN_M:
    case GFXTAG_CHOOSE_PKMN_R:
    case GFXTAG_CHOOSE_PKMN_EMPTY_1:
    case GFXTAG_CHOOSE_PKMN_EMPTY_2:
    case GFXTAG_CHOOSE_PKMN_EMPTY_3:
        LoadSpriteSheet(&sheet);
        sTradeMenuData->timer++;
        break;
    case GFXTAG_MENU_TEXT_COUNT:
        LoadSpritePalette(&gSpritePalette_TradeScreenText);
        sTradeMenuData->timer++;
        break;
    case GFXTAG_MENU_TEXT_COUNT + 1:
        LoadSpritePalette(&sCursor_SpritePalette);
        sTradeMenuData->timer++;
        break;
    case GFXTAG_MENU_TEXT_COUNT + 2:
        LoadSpriteSheet(&sCursor_SpriteSheet);
        sTradeMenuData->timer++;
        break;
    case GFXTAG_MENU_TEXT_COUNT + 3:
        sTradeMenuData->timer = 0;
        return TRUE;
    }

    return FALSE;
}

static void DrawBottomRowText(const u8 *str, u8 *dest, u8 unused)
{
    DrawTextWindowAndBufferTiles(str, dest, 0, 0, 6);
}

static void SetTradePartyLiveStatuses(u8 whichParty)
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
            SetPartyHPBarSprite(&gSprites[sTradeMenuData->partySpriteIds[i][j]], 4 - sTradeMenuData->hpBarLevels[i][j]);
        }
    }
}

static void SaveTradeGiftRibbons(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenuData->giftRibbons); i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && sTradeMenuData->giftRibbons[i] != 0)
        {
            if (sTradeMenuData->giftRibbons[i] < 64)
                gSaveBlock1Ptr->giftRibbons[i] = sTradeMenuData->giftRibbons[i];
        }
    }
}

static u32 CanTradeSelectedMon(struct Pokemon *playerParty, int partyCount, int monIdx)
{
    int i, numMonsLeft;
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
            return CANT_TRADE_EGG_YET;

        if (!IsSpeciesInHoennDex(species2[monIdx]))
            return CANT_TRADE_NATIONAL;
    }

    player = &gLinkPlayers[GetMultiplayerId() ^ 1];
    if ((player->version & 0xFF) != VERSION_RUBY &&
        (player->version & 0xFF) != VERSION_SAPPHIRE)
    {
        // Does partner not have National Dex
        if (!(player->progressFlagsCopy & 0xF))
        {
            if (species2[monIdx] == SPECIES_EGG)
                return CANT_TRADE_EGG_YET2;

            if (!IsSpeciesInHoennDex(species2[monIdx]))
                return CANT_TRADE_INVALID_MON;
        }
    }

    if (species[monIdx] == SPECIES_DEOXYS || species[monIdx] == SPECIES_MEW)
    {
        if (!GetMonData(&playerParty[monIdx], MON_DATA_EVENT_LEGAL))
            return CANT_TRADE_INVALID_MON;
    }

    // Make Eggs not count for numMonsLeft
    for (i = 0; i < partyCount; i++)
    {
        if (species2[i] == SPECIES_EGG)
            species2[i] = SPECIES_NONE;
    }

    // Count alive mons in party, excluding selected trade mon
    for (numMonsLeft = 0, i = 0; i < partyCount; i++)
    {
        if (i != monIdx)
            numMonsLeft += species2[i];
    }

    if (numMonsLeft != 0)
        return CAN_TRADE_MON;
    else
        return CANT_TRADE_LAST_MON;
}

s32 GetGameProgressForLinkTrade(void)
{
    // isGameFrLg could have been a bool but they use 2 and > 0 instead
    // possible other checks (for other game versions?) were planned/removed
    s32 isGameFrLg;
    u16 version;

    if (gReceivedRemoteLinkPlayers != 0)
    {
        isGameFrLg = 0;
        version = (gLinkPlayers[GetMultiplayerId() ^ 1].version & 0xFF);

        if (version == VERSION_RUBY || version == VERSION_SAPPHIRE || version == VERSION_EMERALD)
            isGameFrLg = 0;
        else if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
            isGameFrLg = 2;

        // If trading with FRLG, both players must be champion
        if (isGameFrLg > 0)
        {
            // Is player champion
            if (gLinkPlayers[GetMultiplayerId()].progressFlagsCopy & 0xF0)
            {
                if (isGameFrLg == 2) //unnecessary check, isGameFrLg always 2 here
                {
                    // Is partner champion
                    if (gLinkPlayers[GetMultiplayerId() ^ 1].progressFlagsCopy & 0xF0)
                        return TRADE_BOTH_PLAYERS_READY;
                    else
                        return TRADE_PARTNER_NOT_READY;
                }
            }
            else
            {
                return TRADE_PLAYER_NOT_READY;
            }
        }
    }
    return TRADE_BOTH_PLAYERS_READY;
}

static bool32 IsDeoxysOrMewUntradable(u16 species, bool8 isEventLegal)
{
    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!isEventLegal)
            return TRUE;
    }
    return FALSE;
}

int GetUnionRoomTradeMessageId(struct GFtgtGnameSub rfuPlayer, struct GFtgtGnameSub rfuPartner, u16 playerSpecies2, u16 partnerSpecies, u8 requestedType, u16 playerSpecies, u8 isEventLegal)
{
    bool8 playerHasNationalDex = rfuPlayer.hasNationalDex;
    bool8 playerIsChampion = rfuPlayer.isChampion;
    bool8 partnerHasNationalDex = rfuPartner.hasNationalDex;
    bool8 partnerIsChampion = rfuPartner.isChampion;
    u8 r1 = rfuPartner.version;

    if (r1 != VERSION_EMERALD)
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

    if (IsDeoxysOrMewUntradable(playerSpecies, isEventLegal))
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

int CanRegisterMonForTradingBoard(struct GFtgtGnameSub rfuPlayer, u16 species2, u16 species, u8 isEventLegal)
{
    bool8 hasNationalDex = rfuPlayer.hasNationalDex;

    if (IsDeoxysOrMewUntradable(species, isEventLegal))
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

// Spin Trade wasnt fully implemented, but this checks if a mon would be valid to Spin Trade
// Unlike later generations, this version of Spin Trade isnt only for Eggs
int CanSpinTradeMon(struct Pokemon *mon, u16 monIdx)
{
    int i, version, versions, canTradeAnyMon, numMonsLeft;
    int speciesArray[PARTY_SIZE];

    // Make Eggs not count for numMonsLeft
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        speciesArray[i] = GetMonData(&mon[i], MON_DATA_SPECIES2);
        if (speciesArray[i] == SPECIES_EGG)
        {
            speciesArray[i] = SPECIES_NONE;
        }
    }

    versions = 0;
    canTradeAnyMon = TRUE;
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

        // Does player not have National Dex
        do
        {
            if (!(player->progressFlags & 0xF))
                canTradeAnyMon = FALSE;

            if (versions && (player->progressFlags / 16))
                canTradeAnyMon = FALSE;
        } while (0);
    }

    if (canTradeAnyMon == FALSE)
    {
        if (!IsSpeciesInHoennDex(speciesArray[monIdx]))
            return CANT_TRADE_NATIONAL;

        if (speciesArray[monIdx] == SPECIES_NONE)
            return CANT_TRADE_EGG_YET;
    }

    numMonsLeft = 0;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (monIdx != i)
        {
            numMonsLeft += speciesArray[i];
        }
    }

    if (!numMonsLeft)
        return CANT_TRADE_LAST_MON;
    else
        return CAN_TRADE_MON;
}

static void SpriteCB_LinkMonGlow(struct Sprite *sprite)
{
    if (++sprite->data[0] == 10)
    {
        PlaySE(SE_BALL);
        sprite->data[0] = 0;
    }
}

static void SpriteCB_LinkMonGlowWireless(struct Sprite *sprite)
{
    if (!sprite->invisible && ++sprite->data[0] == 10)
    {
        PlaySE(SE_M_SWAGGER2);
        sprite->data[0] = 0;
    }
}

static void SpriteCB_LinkMonShadow(struct Sprite *sprite)
{
    if (!sprite->data[1])
    {
        if (++sprite->data[0] == 12)
            sprite->data[0] = 0;

        LoadPalette(&sLinkMonShadow_Pal[sprite->data[0]], (sprite->oam.paletteNum + 16) * 16 + 4, 2);
    }
}

// Move cable down offscreen
static void SpriteCB_CableEndSending(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->y2++;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

// Move cable up onscreen
static void SpriteCB_CableEndReceiving(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->y2--;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void SpriteCB_GbaScreen(struct Sprite *sprite)
{
    if (++sprite->data[0] == 15)
    {
        PlaySE(SE_M_MINIMIZE);
        sprite->data[0] = 0;
    }
}

static void SetTradeBGAffine(void)
{
    struct BgAffineDstData affine;

    DoBgAffineSet(&affine, sTradeData->texX * 0x100, sTradeData->texY * 0x100, sTradeData->scrX, sTradeData->scrY, sTradeData->sXY, sTradeData->sXY, sTradeData->alpha);
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
    sTradeData->linkTimeoutCounter = 0;
    sTradeData->linkTimeoutZero1 = 0;
    sTradeData->linkTimeoutZero2 = 0;
}

static void CheckForLinkTimeout(void)
{
    if (sTradeData->linkTimeoutZero1 == sTradeData->linkTimeoutZero2)
        sTradeData->linkTimeoutCounter++;
    else
        sTradeData->linkTimeoutCounter = 0;

    if (sTradeData->linkTimeoutCounter > LINK_TRADE_TIMEOUT)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        sTradeData->linkTimeoutCounter = 0;
        sTradeData->linkTimeoutZero2 = 0;
        sTradeData->linkTimeoutZero1 = 0;
    }

    sTradeData->linkTimeoutZero2 = sTradeData->linkTimeoutZero1;
}

static u32 TradeGetMultiplayerId(void)
{
    if (gReceivedRemoteLinkPlayers)
        return GetMultiplayerId();
    return 0;
}

static void LoadTradeMonPic(u8 whichParty, u8 state)
{
    int pos = 0;
    struct Pokemon *mon = NULL;
    u16 species;
    u32 personality;

    if (whichParty == TRADE_PLAYER)
    {
        mon = &gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]];
        pos = B_POSITION_OPPONENT_LEFT;
    }

    if (whichParty == TRADE_PARTNER)
    {
        mon = &gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE];
        pos = B_POSITION_OPPONENT_RIGHT;
    }

    switch (state)
    {
    case 0:
        species = GetMonData(mon, MON_DATA_SPECIES2);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);

        HandleLoadSpecialPokePic(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[whichParty * 2 + 1], species, personality);

        LoadCompressedSpritePalette(GetMonSpritePalStruct(mon));
        sTradeData->monSpecies[whichParty] = species;
        sTradeData->monPersonalities[whichParty] = personality;
        break;
    case 1:
        SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, pos);
        sTradeData->monSpriteIds[whichParty] = CreateSprite(&gMultiuseSpriteTemplate, 120, 60, 6);
        gSprites[sTradeData->monSpriteIds[whichParty]].invisible = TRUE;
        gSprites[sTradeData->monSpriteIds[whichParty]].callback = SpriteCallbackDummy;
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
            gLinkType = LINKTYPE_TRADE_DISCONNECTED;
            CloseLink();
        }
        sTradeData = AllocZeroed(sizeof(*sTradeData));
        AllocateMonSpritesGfx();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(VBlankCB_Trade);
        InitTradeBgInternal();
        ClearLinkTimeoutCounter();
        gMain.state++;
        sTradeData->neverRead_8C = 0;
        sTradeData->state = 0;
        sTradeData->isLinkTrade = TRUE;
        sTradeData->texX = 64;
        sTradeData->texY = 64;
        sTradeData->neverRead_D8 = 0;
        sTradeData->neverRead_DA = 0;
        sTradeData->scrX = 120;
        sTradeData->scrY = 80;
        sTradeData->sXY = 256;
        sTradeData->alpha = 0;
        break;
    case 1:
        if (!gReceivedRemoteLinkPlayers)
        {
            sTradeData->isCableTrade = TRUE;
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
        sTradeData->playerLinkFlagFinishTrade = 0;
        sTradeData->partnerLinkFlagFinishTrade = 0;
        sTradeData->sendTradeFinishState = 0;
        LoadTradeMonPic(TRADE_PLAYER, 0);
        gMain.state++;
        break;
    case 6:
        LoadTradeMonPic(TRADE_PLAYER, 1);
        gMain.state++;
        break;
    case 7:
        LoadTradeMonPic(TRADE_PARTNER, 0);
        gMain.state++;
        break;
    case 8:
        LoadTradeMonPic(TRADE_PARTNER, 1);
        LinkTradeDrawWindow();
        gMain.state++;
        break;
    case 9:
        LoadTradeSequenceSpriteSheetsAndPalettes();
        LoadSpriteSheet(&sPokeBallSpriteSheet);
        LoadSpritePalette(&sPokeBallSpritePalette);
        gMain.state++;
        break;
    case 10:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        ShowBg(0);
        gMain.state++;
        break;
    case 11:
        InitTradeSequenceBgGpuRegs();
        BufferTradeSceneStrings();
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
            SetMainCallback2(CB2_UpdateLinkTrade);
        }
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void InitTradeSequenceBgGpuRegs(void)
{
    SetTradeSequenceBgGpuRegs(5);
    SetTradeSequenceBgGpuRegs(0);
}

void LinkTradeDrawWindow(void)
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
    SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(1, Alloc(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(3, Alloc(BG_SCREEN_SIZE));
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
        gLinkPlayers[0].language = GAME_LANGUAGE;
        gLinkPlayers[1].language = GetMonData(&gEnemyParty[0], MON_DATA_LANGUAGE);
        sTradeData = AllocZeroed(sizeof(*sTradeData));
        AllocateMonSpritesGfx();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(VBlankCB_Trade);
        InitTradeBgInternal();
        sTradeData->isLinkTrade = FALSE;
        sTradeData->neverRead_8C = 0;
        sTradeData->state = 0;
        sTradeData->texX = 64;
        sTradeData->texY = 64;
        sTradeData->neverRead_D8 = 0;
        sTradeData->neverRead_DA = 0;
        sTradeData->scrX = 120;
        sTradeData->scrY = 80;
        sTradeData->sXY = 256;
        sTradeData->alpha = 0;
        sTradeData->timer = 0;
        gMain.state = 5;
        break;
    case 5:
        LoadTradeMonPic(TRADE_PLAYER, 0);
        gMain.state++;
        break;
    case 6:
        LoadTradeMonPic(TRADE_PLAYER, 1);
        gMain.state++;
        break;
    case 7:
        LoadTradeMonPic(TRADE_PARTNER, 0);
        ShowBg(0);
        gMain.state++;
        break;
    case 8:
        LoadTradeMonPic(TRADE_PARTNER, 1);
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
        SetTradeSequenceBgGpuRegs(5);
        SetTradeSequenceBgGpuRegs(0);
        BufferTradeSceneStrings();
        gMain.state++;
        break;
    case 12:
        SetMainCallback2(CB2_UpdateInGameTrade);
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
static void TryEnableNationalDexFromLinkPartner(void)
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

    if (playerMail != MAIL_NONE)
        ClearMailStruct(&gSaveBlock1Ptr->mail[playerMail]);

    sTradeData->mon = *playerMon;
    *playerMon = *partnerMon;
    *partnerMon = sTradeData->mon;

    friendship = 70;
    if (!GetMonData(playerMon, MON_DATA_IS_EGG))
        SetMonData(playerMon, MON_DATA_FRIENDSHIP, &friendship);

    if (partnerMail != MAIL_NONE)
        GiveMailToMon2(playerMon, &gTradeMail[partnerMail]);

    UpdatePokedexForReceivedMon(playerPartyIdx);
    if (gReceivedRemoteLinkPlayers)
        TryEnableNationalDexFromLinkPartner();
}

static void TrySendTradeFinishData(void)
{
    switch (sTradeData->sendTradeFinishState)
    {
    case 1:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), sTradeData->linkData, sizeof(sTradeData->linkData));
            sTradeData->sendTradeFinishState++;
        }
        // fallthrough
    case 2:
        sTradeData->sendTradeFinishState = 0;
        break;
    }
}

static void CB2_UpdateInGameTrade(void)
{
    AnimateTradeSequence();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void SetTradeSequenceBgGpuRegs(u8 state)
{
    switch (state)
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
        DmaCopy16Defvars(3, gTradePlatform_Tilemap, (void *) BG_SCREEN_ADDR(18), 0x1000);
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

        if (sTradeData->isCableTrade)
        {
            DmaCopy16Defvars(3, sGbaCable_Tilemap, (void *) BG_SCREEN_ADDR(5), 0x1000);
        }
        else
        {
            DmaCopy16Defvars(3, sGbaWireless_Tilemap, (void *) BG_SCREEN_ADDR(5), 0x1000);
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
        if (!sTradeData->isCableTrade)
        {
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            LZ77UnCompVram(sCrossingHighlightWireless_Tilemap, (void *) BG_SCREEN_ADDR(5));
            BlendPalettes(0x8, 16, RGB_BLACK);
        }
        else
        {
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            DmaCopy16Defvars(3, sCrossingHighlightCable_Tilemap, (void *) BG_SCREEN_ADDR(5), 0x800);
            BlendPalettes(0x1, 16, RGB_BLACK);
        }
        break;
    case 3:
        LoadPalette(sWirelessSignalNone_Pal, 48, 0x20);
        LZ77UnCompVram(sWirelessSignal_Gfx, (void *) BG_CHAR_ADDR(1));
        LZ77UnCompVram(sWirelessSignal_Tilemap, (void *) BG_SCREEN_ADDR(18));
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
        sTradeData->texX = 64;
        sTradeData->texY = 92;
        sTradeData->sXY = 32;
        sTradeData->gbaScale = 1024;
        sTradeData->alpha = 0;

        DmaCopyLarge16(3, sGbaAffine_Gfx, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

        if (sTradeData->isCableTrade)
        {
            DmaCopy16Defvars(3, sGbaCable_AffineTilemap, (void *) BG_SCREEN_ADDR(18), 0x100);
        }
        else
        {
            DmaCopy16Defvars(3, sGbaWireless_AffineTilemap, (void *) BG_SCREEN_ADDR(18), 0x100);
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
        sTradeData->texX = 64;
        sTradeData->texY = 92;
        sTradeData->sXY = 256;
        sTradeData->gbaScale = 128;
        sTradeData->scrX = 120;
        sTradeData->scrY = 80;
        sTradeData->alpha = 0;

        DmaCopyLarge16(3, sGbaAffine_Gfx, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

        if (sTradeData->isCableTrade)
        {
            DmaCopy16Defvars(3, sGbaCable_AffineTilemap, (void *) BG_SCREEN_ADDR(18), 0x100);
        }
        else
        {
            DmaCopy16Defvars(3, sGbaWireless_AffineTilemap, (void *) BG_SCREEN_ADDR(18), 0x100);
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
        DmaCopy16Defvars(3, gTradePlatform_Tilemap, (void *) BG_SCREEN_ADDR(18), 0x1000);
        break;
    }
}

static void LoadTradeSequenceSpriteSheetsAndPalettes(void)
{
    LoadSpriteSheet(&sSpriteSheet_LinkMonGlow);
    LoadSpriteSheet(&sSpriteSheet_LinkMonShadow);
    LoadSpriteSheet(&sSpriteSheet_CableEnd);
    LoadSpriteSheet(&sSpriteSheet_GbaScreen);
    LoadSpritePalette(&sSpritePalette_LinkMon);
    LoadSpritePalette(&sSpritePalette_Gba);
}

// Buffers "[Pokemon] will be sent to [Trainer]" strings
static void BufferTradeSceneStrings(void)
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

// returns TRUE if it finished a link trade, FALSE if it finished an in-game trade or if sequence is still going
static bool8 AnimateTradeSequence(void)
{
    if (sTradeData->isCableTrade)
        return AnimateTradeSequenceCable();
    else
        return AnimateTradeSequenceWireless();
}

// Below are the states for the main switch in AnimateTradeSequenceCable and AnimateTradeSequenceWireless
// When AnimateTradeSequenceWireless has a unique version of a
// state used by AnimateTradeSequenceCable, it adds the below modifier
#define TS_WIRELESS_STATE 100
enum {
    TS_STATE_START,
    TS_STATE_MON_SLIDE_IN,
    // 2-9 unused
    TS_STATE_SEND_MSG = 10,
    TS_STATE_BYE_BYE,
    TS_STATE_POKEBALL_DEPART,
    TS_STATE_POKEBALL_DEPART_WAIT,
    TS_STATE_FADE_OUT_TO_GBA_SEND,
    // 15-19 unused
    TS_STATE_WAIT_FADE_OUT_TO_GBA_SEND = 20,
    TS_STATE_FADE_IN_TO_GBA_SEND,
    TS_STATE_WAIT_FADE_IN_TO_GBA_SEND,
    TS_STATE_GBA_ZOOM_OUT,
    TS_STATE_GBA_FLASH_SEND,
    TS_STATE_GBA_STOP_FLASH_SEND,
    TS_STATE_PAN_AWAY_GBA,
    TS_STATE_CREATE_LINK_MON_LEAVING,
    TS_STATE_LINK_MON_TRAVEL_OUT,
    TS_STATE_FADE_OUT_TO_CROSSING,
    TS_STATE_WAIT_FADE_OUT_TO_CROSSING,
    TS_STATE_FADE_IN_TO_CROSSING,
    TS_STATE_WAIT_FADE_IN_TO_CROSSING,
    TS_STATE_CROSSING_LINK_MONS_ENTER,
    TS_STATE_CROSSING_BLEND_WHITE_1,
    TS_STATE_CROSSING_BLEND_WHITE_2,
    TS_STATE_CROSSING_BLEND_WHITE_3,
    TS_STATE_CROSSING_CREATE_MON_PICS,
    TS_STATE_CROSSING_MON_PICS_MOVE,
    TS_STATE_CROSSING_LINK_MONS_EXIT,
    TS_STATE_CREATE_LINK_MON_ARRIVING,
    TS_STATE_FADE_OUT_TO_GBA_RECV,
    TS_STATE_WAIT_FADE_OUT_TO_GBA_RECV,
    TS_STATE_LINK_MON_TRAVEL_IN,
    TS_STATE_PAN_TO_GBA,
    TS_STATE_DESTROY_LINK_MON,
    TS_STATE_LINK_MON_ARRIVED_DELAY,
    TS_STATE_MOVE_GBA_TO_CENTER,
    TS_STATE_GBA_FLASH_RECV,
    TS_STATE_UNUSED,
    TS_STATE_GBA_STOP_FLASH_RECV,
    TS_STATE_GBA_ZOOM_IN,
    TS_STATE_FADE_OUT_TO_NEW_MON,
    // 53-59 unused
    TS_STATE_WAIT_FADE_OUT_TO_NEW_MON = 60,
    TS_STATE_FADE_IN_TO_NEW_MON,
    TS_STATE_WAIT_FADE_IN_TO_NEW_MON,
    TS_STATE_POKEBALL_ARRIVE,
    TS_STATE_FADE_POKEBALL_TO_NORMAL,
    TS_STATE_POKEBALL_ARRIVE_WAIT,
    TS_STATE_SHOW_NEW_MON,
    TS_STATE_NEW_MON_MSG,
    TS_STATE_TAKE_CARE_OF_MON,
    TS_STATE_AFTER_NEW_MON_DELAY,
    TS_STATE_CHECK_RIBBONS,
    TS_STATE_END_LINK_TRADE,
    TS_STATE_TRY_EVOLUTION,
    TS_STATE_FADE_OUT_END,
    TS_STATE_WAIT_FADE_OUT_END,
    // Special states
    TS_STATE_GBA_FLASH_SEND_WIRELESS = TS_STATE_GBA_FLASH_SEND + TS_WIRELESS_STATE,
    TS_STATE_GBA_STOP_FLASH_SEND_WIRELESS,
    TS_STATE_WAIT_WIRELESS_SIGNAL_SEND,
    TS_STATE_PAN_TO_GBA_WIRELESS = TS_STATE_PAN_TO_GBA + TS_WIRELESS_STATE,
    TS_STATE_DESTROY_LINK_MON_WIRELESS,
    TS_STATE_WAIT_WIRELESS_SIGNAL_RECV,
    TS_STATE_DELAY_FOR_MON_ANIM = 167,
    TS_STATE_LINK_MON_TRAVEL_OFFSCREEN = 200,
    TS_STATE_WAIT_FOR_MON_CRY = 267,
};

static bool8 AnimateTradeSequenceCable(void)
{
    u16 evoTarget;

    switch (sTradeData->state)
    {
    case TS_STATE_START:
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x2 = -180;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 = gMonFrontPicCoords[sTradeData->monSpecies[TRADE_PLAYER]].y_offset;
        sTradeData->state++;
        sTradeData->cachedMapMusic = GetCurrentMapMusic();
        PlayNewMapMusic(MUS_EVOLUTION);
        break;
    case TS_STATE_MON_SLIDE_IN:
        if (sTradeData->bg2hofs > 0)
        {
            // Sliding
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x2 += 3;
            sTradeData->bg2hofs -= 3;
        }
        else
        {
            // Pokémon has arrived onscreen
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x2 = 0;
            sTradeData->bg2hofs = 0;
            sTradeData->state = TS_STATE_SEND_MSG;
        }
        break;
    case TS_STATE_SEND_MSG:
        StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
        DrawTextOnTradeWindow(0, gStringVar4, 0);

        if (sTradeData->monSpecies[TRADE_PLAYER] != SPECIES_EGG)
            PlayCry1(sTradeData->monSpecies[TRADE_PLAYER], 0);

        sTradeData->state = TS_STATE_BYE_BYE;
        sTradeData->timer = 0;
        break;
    case TS_STATE_BYE_BYE:
        if (++sTradeData->timer == 80)
        {
            sTradeData->releasePokeballSpriteId = CreateTradePokeballSprite(sTradeData->monSpriteIds[0], gSprites[sTradeData->monSpriteIds[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
            sTradeData->state++;
            StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
        }
        break;
    case TS_STATE_POKEBALL_DEPART:
        if (gSprites[sTradeData->releasePokeballSpriteId].callback == SpriteCallbackDummy)
        {
            sTradeData->bouncingPokeballSpriteId = CreateSprite(&sSpriteTemplate_Pokeball, 120, 32, 0);
            gSprites[sTradeData->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballDepart;
            DestroySprite(&gSprites[sTradeData->releasePokeballSpriteId]);
            sTradeData->state++;
        }
        break;
    case TS_STATE_POKEBALL_DEPART_WAIT:
        // The game waits here for the sprite to finish its animation sequence.
        break;
    case TS_STATE_FADE_OUT_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeData->state = TS_STATE_WAIT_FADE_OUT_TO_GBA_SEND;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_GBA_SEND:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(4);
            FillWindowPixelBuffer(0, PIXEL_FILL(15));
            CopyWindowToVram(0, 3);
            sTradeData->state++;
        }
        break;
    case TS_STATE_FADE_IN_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_IN_TO_GBA_SEND:
        if (!gPaletteFade.active)
            sTradeData->state = TS_STATE_GBA_ZOOM_OUT;
        break;
    case TS_STATE_GBA_ZOOM_OUT:
        if (sTradeData->gbaScale > 0x100)
        {
            sTradeData->gbaScale -= 0x34;
        }
        else
        {
            SetTradeSequenceBgGpuRegs(1);
            sTradeData->gbaScale = 0x80;
            sTradeData->state++;
            sTradeData->timer = 0;
        }
        sTradeData->sXY = 0x8000 / sTradeData->gbaScale;
        break;
    case TS_STATE_GBA_FLASH_SEND:
        if (++sTradeData->timer > 20)
        {
            SetTradeBGAffine();
            sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_GbaScreenFlash_Long, 120, 80, 0);
            sTradeData->state++;
        }
        break;
    case TS_STATE_GBA_STOP_FLASH_SEND:
        if (gSprites[sTradeData->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND |
                                         BLDCNT_TGT2_BG1 |
                                         BLDCNT_TGT2_BG2);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 4));
            sTradeData->state++;
        }
        break;
    case TS_STATE_PAN_AWAY_GBA:
        if (--sTradeData->bg1vofs == 316)
            sTradeData->state++;

        if (sTradeData->bg1vofs == 328)
            sTradeData->cableEndSpriteId = CreateSprite(&sSpriteTemplate_CableEnd, 128, 65, 0);
        break;
    case TS_STATE_CREATE_LINK_MON_LEAVING:
        sTradeData->connectionSpriteId1 = CreateSprite(&sSpriteTemplate_LinkMonGlow, 128, 80, 3);
        sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 128, 80, 0);
        StartSpriteAnim(&gSprites[sTradeData->connectionSpriteId2], ANIM_LINKMON_SMALL);
        sTradeData->state++;
        break;
    case TS_STATE_LINK_MON_TRAVEL_OUT:
        if ((sTradeData->bg1vofs -= 2) == 166)
            sTradeData->state = TS_STATE_LINK_MON_TRAVEL_OFFSCREEN;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        break;
    case TS_STATE_LINK_MON_TRAVEL_OFFSCREEN:
        gSprites[sTradeData->connectionSpriteId1].y -= 2;
        gSprites[sTradeData->connectionSpriteId2].y -= 2;
        if (gSprites[sTradeData->connectionSpriteId1].y < -8)
            sTradeData->state = TS_STATE_FADE_OUT_TO_CROSSING;
        break;
    case TS_STATE_FADE_OUT_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        sTradeData->state = TS_STATE_WAIT_FADE_OUT_TO_CROSSING;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            DestroySprite(&gSprites[sTradeData->connectionSpriteId1]);
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(2);
            sTradeData->state++;
        }
        break;
    case TS_STATE_FADE_IN_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        sTradeData->connectionSpriteId1 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 111, 170, 0);
        sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 129, -10, 0);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_IN_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            PlaySE(SE_WARP_OUT);
            sTradeData->state++;
        }
        gSprites[sTradeData->connectionSpriteId1].y2 -= 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        break;
    case TS_STATE_CROSSING_LINK_MONS_ENTER:
        gSprites[sTradeData->connectionSpriteId1].y2 -= 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        if (gSprites[sTradeData->connectionSpriteId1].y2 <= -90)
        {
            gSprites[sTradeData->connectionSpriteId1].data[1] = 1;
            gSprites[sTradeData->connectionSpriteId2].data[1] = 1;
            sTradeData->state++;
        }
        break;
    case TS_STATE_CROSSING_BLEND_WHITE_1:
        BlendPalettes(0x1, 16, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_BLEND_WHITE_2:
        BlendPalettes(0x1, 0, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_BLEND_WHITE_3:
        BlendPalettes(0x1, 16, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_CREATE_MON_PICS:
        if (!IsMonSpriteNotFlipped(sTradeData->monSpecies[TRADE_PLAYER]))
        {
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].affineAnims = sAffineAnims_CrossingMonPics;
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            CalcCenterToCornerVec(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]], SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), ST_OAM_AFFINE_DOUBLE);
            StartSpriteAffineAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]], 0);
        }
        else
        {
            StartSpriteAffineAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]], 0);
        }
        StartSpriteAffineAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]], 0);
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x = 60;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].x = 180;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y = 192;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y = -32;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].invisible = FALSE;
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_MON_PICS_MOVE:
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 -= 3;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y2 += 3;
        if (gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 < -DISPLAY_HEIGHT 
         && gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 >= -DISPLAY_HEIGHT - 3)
        {
            PlaySE(SE_WARP_IN);
        }
        if (gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 < -222)
        {
            gSprites[sTradeData->connectionSpriteId1].data[1] = 0;
            gSprites[sTradeData->connectionSpriteId2].data[1] = 0;
            sTradeData->state++;
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].invisible = TRUE;
            gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].invisible = TRUE;
            BlendPalettes(0x1, 0, RGB_WHITEALPHA);
        }
        break;
    case TS_STATE_CROSSING_LINK_MONS_EXIT:
        gSprites[sTradeData->connectionSpriteId1].y2 -= 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        if (gSprites[sTradeData->connectionSpriteId1].y2 <= -222)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            sTradeData->state++;
            DestroySprite(&gSprites[sTradeData->connectionSpriteId1]);
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
        }
        break;
    case TS_STATE_CREATE_LINK_MON_ARRIVING:
        if (!gPaletteFade.active)
        {
            sTradeData->state++;
            SetTradeSequenceBgGpuRegs(1);
            sTradeData->bg1vofs = 166;
            sTradeData->connectionSpriteId1 = CreateSprite(&sSpriteTemplate_LinkMonGlow, 128, -20, 3);
            sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 128, -20, 0);
            StartSpriteAnim(&gSprites[sTradeData->connectionSpriteId2], ANIM_LINKMON_SMALL);
        }
        break;
    case TS_STATE_FADE_OUT_TO_GBA_RECV:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_GBA_RECV:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            sTradeData->state++;
        break;
    case TS_STATE_LINK_MON_TRAVEL_IN:
        gSprites[sTradeData->connectionSpriteId1].y2 += 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        if (gSprites[sTradeData->connectionSpriteId1].y2 + gSprites[sTradeData->connectionSpriteId1].y == 64)
        {
            sTradeData->state++;
        }
        break;
    case TS_STATE_PAN_TO_GBA:
        if ((sTradeData->bg1vofs += 2) > 316)
        {
            sTradeData->bg1vofs = 316;
            sTradeData->state++;
        }
        break;
    case TS_STATE_DESTROY_LINK_MON:
        DestroySprite(&gSprites[sTradeData->connectionSpriteId1]);
        DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
        sTradeData->state++;
        sTradeData->timer = 0;
        break;
    case TS_STATE_LINK_MON_ARRIVED_DELAY:
        if (++sTradeData->timer == 10)
            sTradeData->state++;
        break;
    case TS_STATE_MOVE_GBA_TO_CENTER:
        if (++sTradeData->bg1vofs > 348)
        {
            sTradeData->bg1vofs = 348;
            sTradeData->state++;
        }
        if (sTradeData->bg1vofs == 328 && sTradeData->isCableTrade)
        {
            sTradeData->cableEndSpriteId = CreateSprite(&sSpriteTemplate_CableEnd, 128, 65, 0);
            gSprites[sTradeData->cableEndSpriteId].callback = SpriteCB_CableEndReceiving;
        }
        break;
    case TS_STATE_GBA_FLASH_RECV:
        sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_GbaScreenFlash_Long, 120, 80, 0);
        sTradeData->state = TS_STATE_GBA_STOP_FLASH_RECV;
        break;
    case TS_STATE_GBA_STOP_FLASH_RECV:
        if (gSprites[sTradeData->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(6);
            sTradeData->state++;
            PlaySE(SE_M_SAND_ATTACK);
        }
        break;
    case TS_STATE_GBA_ZOOM_IN:
        if (sTradeData->gbaScale < 0x400)
        {
            sTradeData->gbaScale += 0x34;
        }
        else
        {
            sTradeData->gbaScale = 0x400;
            sTradeData->state++;
        }
        sTradeData->sXY = 0x8000 / sTradeData->gbaScale;
        break;
    case TS_STATE_FADE_OUT_TO_NEW_MON:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeData->state = TS_STATE_WAIT_FADE_OUT_TO_NEW_MON;
        break;

    case TS_STATE_WAIT_FADE_OUT_TO_NEW_MON:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(5);
            SetTradeSequenceBgGpuRegs(7);
            gPaletteFade.bufferTransferDisabled = TRUE;
            sTradeData->state++;
        }
        break;
    case TS_STATE_FADE_IN_TO_NEW_MON:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_IN_TO_NEW_MON:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            sTradeData->state++;
        break;
    case TS_STATE_POKEBALL_ARRIVE:
        sTradeData->bouncingPokeballSpriteId = CreateSprite(&sSpriteTemplate_Pokeball, 120, -8, 0);
        gSprites[sTradeData->bouncingPokeballSpriteId].data[3] = 74;
        gSprites[sTradeData->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballArrive;
        StartSpriteAnim(&gSprites[sTradeData->bouncingPokeballSpriteId], 1);
        StartSpriteAffineAnim(&gSprites[sTradeData->bouncingPokeballSpriteId], 2);
        BlendPalettes(1 << (16 + gSprites[sTradeData->bouncingPokeballSpriteId].oam.paletteNum), 16, RGB_WHITEALPHA);
        sTradeData->state++;
        sTradeData->timer = 0;
        break;
    case TS_STATE_FADE_POKEBALL_TO_NORMAL:
        BeginNormalPaletteFade(1 << (16 + gSprites[sTradeData->bouncingPokeballSpriteId].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_POKEBALL_ARRIVE_WAIT:
        if (gSprites[sTradeData->bouncingPokeballSpriteId].callback == SpriteCallbackDummy)
        {
            HandleLoadSpecialPokePic(&gMonFrontPicTable[sTradeData->monSpecies[TRADE_PARTNER]], gMonSpritesGfxPtr->sprites.ptr[3], sTradeData->monSpecies[TRADE_PARTNER], sTradeData->monPersonalities[TRADE_PARTNER]);
            sTradeData->state++;
        }
        break;
    case TS_STATE_SHOW_NEW_MON:
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].x = 120;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y = gMonFrontPicCoords[sTradeData->monSpecies[TRADE_PARTNER]].y_offset + 60;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].x2 = 0;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y2 = 0;
        StartSpriteAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]], 0);
        CreatePokeballSpriteToReleaseMon(sTradeData->monSpriteIds[TRADE_PARTNER], gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, sTradeData->monSpecies[TRADE_PARTNER]);
        FreeSpriteOamMatrix(&gSprites[sTradeData->bouncingPokeballSpriteId]);
        DestroySprite(&gSprites[sTradeData->bouncingPokeballSpriteId]);
        sTradeData->state++;
        break;
    case TS_STATE_NEW_MON_MSG:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        sTradeData->state = TS_STATE_DELAY_FOR_MON_ANIM;
        sTradeData->timer = 0;
        break;
    case TS_STATE_DELAY_FOR_MON_ANIM:
        if (++sTradeData->timer > 60)
        {
            sTradeData->state = TS_STATE_WAIT_FOR_MON_CRY;
            sTradeData->timer = 0;
        }
        break;
    case TS_STATE_WAIT_FOR_MON_CRY:
        if (IsCryFinished())
            sTradeData->state = TS_STATE_TAKE_CARE_OF_MON;
        break;
    case TS_STATE_TAKE_CARE_OF_MON:
        if (++sTradeData->timer == 10)
            PlayFanfare(MUS_EVOLVED);

        if (sTradeData->timer == 250)
        {
            sTradeData->state++;
            StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            sTradeData->timer = 0;
        }
        break;
    case TS_STATE_AFTER_NEW_MON_DELAY:
        if (++sTradeData->timer == 60)
            sTradeData->state++;
        break;
    case TS_STATE_CHECK_RIBBONS:
        CheckPartnersMonForRibbons();
        sTradeData->state++;
        break;
    case TS_STATE_END_LINK_TRADE:
        if (sTradeData->isLinkTrade)
        {
            return TRUE;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            sTradeData->state++;
        }
        break;
    case TS_STATE_TRY_EVOLUTION: // Only if in-game trade, link trades use CB2_TryLinkTradeEvolution
        TradeMons(gSpecialVar_0x8005, 0);
        gCB2_AfterEvolution = CB2_UpdateInGameTrade;
        evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], EVO_MODE_TRADE, ITEM_NONE, GetMonData(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PARTNER]], MON_DATA_SPECIES));
        if (evoTarget != SPECIES_NONE)
        {
            TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeData->monSpriteIds[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
        }
        sTradeData->state++;
        break;
    case TS_STATE_FADE_OUT_END:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_OUT_END:
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
            BufferInGameTradeMonName();
        }
        break;
    }
    return FALSE;
}

static bool8 AnimateTradeSequenceWireless(void)
{
    u16 evoTarget;

    switch (sTradeData->state)
    {
    case TS_STATE_START:
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x2 = -180;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 = gMonFrontPicCoords[sTradeData->monSpecies[TRADE_PLAYER]].y_offset;
        sTradeData->state++;
        sTradeData->cachedMapMusic = GetCurrentMapMusic();
        PlayNewMapMusic(MUS_EVOLUTION);
        break;
    case TS_STATE_MON_SLIDE_IN:
        if (sTradeData->bg2hofs > 0)
        {
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x2 += 3;
            sTradeData->bg2hofs -= 3;
        }
        else
        {
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x2 = 0;
            sTradeData->bg2hofs = 0;
            sTradeData->state = TS_STATE_SEND_MSG;
        }
        break;
    case TS_STATE_SEND_MSG:
        StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
        DrawTextOnTradeWindow(0, gStringVar4, 0);

        if (sTradeData->monSpecies[TRADE_PLAYER] != SPECIES_EGG)
            PlayCry1(sTradeData->monSpecies[TRADE_PLAYER], 0);

        sTradeData->state = TS_STATE_BYE_BYE;
        sTradeData->timer = 0;
        break;
    case TS_STATE_BYE_BYE:
        if (++sTradeData->timer == 80)
        {
            sTradeData->releasePokeballSpriteId = CreateTradePokeballSprite(sTradeData->monSpriteIds[0], gSprites[sTradeData->monSpriteIds[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
            sTradeData->state++;
            StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
        }
        break;
    case TS_STATE_POKEBALL_DEPART:
        if (gSprites[sTradeData->releasePokeballSpriteId].callback == SpriteCallbackDummy)
        {
            sTradeData->bouncingPokeballSpriteId = CreateSprite(&sSpriteTemplate_Pokeball, 120, 32, 0);
            gSprites[sTradeData->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballDepart;
            DestroySprite(&gSprites[sTradeData->releasePokeballSpriteId]);
            sTradeData->state++;
        }
        break;
    case TS_STATE_POKEBALL_DEPART_WAIT:
        // The game waits here for the sprite to finish its animation sequence.
        break;
    case TS_STATE_FADE_OUT_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeData->state = TS_STATE_WAIT_FADE_OUT_TO_GBA_SEND;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_GBA_SEND:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(4);
            FillWindowPixelBuffer(0, PIXEL_FILL(15));
            CopyWindowToVram(0, 3);
            sTradeData->state++;
        }
        break;
    case TS_STATE_FADE_IN_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_IN_TO_GBA_SEND:
        if (!gPaletteFade.active)
            sTradeData->state = TS_STATE_GBA_ZOOM_OUT;
        break;
    case TS_STATE_GBA_ZOOM_OUT:
        if (sTradeData->gbaScale > 0x100)
        {
            sTradeData->gbaScale -= 0x34;
        }
        else
        {
            SetTradeSequenceBgGpuRegs(1);
            sTradeData->gbaScale = 0x80;
            sTradeData->state = TS_STATE_GBA_FLASH_SEND_WIRELESS;
            sTradeData->timer = 0;
        }
        sTradeData->sXY = 0x8000 / sTradeData->gbaScale;
        break;
    case TS_STATE_GBA_FLASH_SEND_WIRELESS:
        if (++sTradeData->timer > 20)
        {
            SetTradeSequenceBgGpuRegs(3);
            sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_GbaScreenFlash_Short, 120, 80, 0);
            sTradeData->state++;
        }
        break;
    case TS_STATE_GBA_STOP_FLASH_SEND_WIRELESS:
        if (gSprites[sTradeData->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 |
                                         BLDCNT_TGT1_OBJ |
                                         BLDCNT_EFFECT_BLEND |
                                         BLDCNT_TGT2_BG2);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));
            
            // Start wireless signal effect
            CreateTask(Task_AnimateWirelessSignal, 5);
            sTradeData->state++;
        }
        break;
    case TS_STATE_WAIT_WIRELESS_SIGNAL_SEND:
        if (!FuncIsActiveTask(Task_AnimateWirelessSignal))
            sTradeData->state = TS_STATE_PAN_AWAY_GBA;
        break;
    case TS_STATE_PAN_AWAY_GBA:
        if (--sTradeData->bg1vofs == 316)
            sTradeData->state++;
        break;
    case TS_STATE_CREATE_LINK_MON_LEAVING:
        sTradeData->connectionSpriteId1 = CreateSprite(&sSpriteTemplate_LinkMonGlow, 120, 80, 3);
        gSprites[sTradeData->connectionSpriteId1].callback = SpriteCB_LinkMonGlowWireless;
        sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 120, 80, 0);
        StartSpriteAnim(&gSprites[sTradeData->connectionSpriteId2], ANIM_LINKMON_SMALL);
        sTradeData->state++;
        break;
    case TS_STATE_LINK_MON_TRAVEL_OUT:
        if ((sTradeData->bg1vofs -= 3) == 166)
            sTradeData->state = TS_STATE_LINK_MON_TRAVEL_OFFSCREEN;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        break;
    case TS_STATE_LINK_MON_TRAVEL_OFFSCREEN:
        gSprites[sTradeData->connectionSpriteId1].y -= 2;
        gSprites[sTradeData->connectionSpriteId2].y -= 2;
        if (gSprites[sTradeData->connectionSpriteId1].y < -8)
        {
            sTradeData->state = TS_STATE_FADE_OUT_TO_CROSSING;
        }
        break;
    case TS_STATE_FADE_OUT_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        sTradeData->state = TS_STATE_WAIT_FADE_OUT_TO_CROSSING;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            DestroySprite(&gSprites[sTradeData->connectionSpriteId1]);
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(2);
            sTradeData->state++;
        }
        break;
    case TS_STATE_FADE_IN_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        sTradeData->connectionSpriteId1 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 111, 170, 0);
        sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 129, -10, 0);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_IN_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            PlaySE(SE_WARP_OUT);
            sTradeData->state++;
        }
        gSprites[sTradeData->connectionSpriteId1].y2 -= 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        break;
    case TS_STATE_CROSSING_LINK_MONS_ENTER:
        gSprites[sTradeData->connectionSpriteId1].y2 -= 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        if (gSprites[sTradeData->connectionSpriteId1].y2 <= -90)
        {
            gSprites[sTradeData->connectionSpriteId1].data[1] = 1;
            gSprites[sTradeData->connectionSpriteId2].data[1] = 1;
            sTradeData->state++;
            CreateTask(Task_NarrowWindowForCrossing_Wireless, 5);
        }
        break;
    case TS_STATE_CROSSING_BLEND_WHITE_1:
        BlendPalettes(0x8, 16, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_BLEND_WHITE_2:
        BlendPalettes(0x8, 16, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_BLEND_WHITE_3:
        BlendPalettes(0x8, 16, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_CREATE_MON_PICS:
        if (!IsMonSpriteNotFlipped(sTradeData->monSpecies[TRADE_PLAYER]))
        {
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].affineAnims = sAffineAnims_CrossingMonPics;
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            CalcCenterToCornerVec(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]], SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), ST_OAM_AFFINE_DOUBLE);
            StartSpriteAffineAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]], 0);
        }
        else
        {
            StartSpriteAffineAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]], 0);
        }
        StartSpriteAffineAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]], 0);
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].x = 40;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].x = 200;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y = 192;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y = -32;
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].invisible = FALSE;
        sTradeData->state++;
        break;
    case TS_STATE_CROSSING_MON_PICS_MOVE:
        gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 -= 3;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y2 += 3;
        if (gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 < -DISPLAY_HEIGHT
         && gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 >= -DISPLAY_HEIGHT - 3)
        {
            PlaySE(SE_WARP_IN);
        }
        if (gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].y2 < -222)
        {
            gSprites[sTradeData->connectionSpriteId1].data[1] = 0;
            gSprites[sTradeData->connectionSpriteId2].data[1] = 0;
            sTradeData->state++;
            gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]].invisible = TRUE;
            gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].invisible = TRUE;
            CreateTask(Task_NarrowWindowForCrossing_Cable, 5);
        }
        break;
    case TS_STATE_CROSSING_LINK_MONS_EXIT:
        gSprites[sTradeData->connectionSpriteId1].y2 -= 3;
        gSprites[sTradeData->connectionSpriteId2].y2 += 3;
        if (gSprites[sTradeData->connectionSpriteId1].y2 <= -222)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            sTradeData->state++;
            DestroySprite(&gSprites[sTradeData->connectionSpriteId1]);
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
        }
        break;
    case TS_STATE_CREATE_LINK_MON_ARRIVING:
        if (!gPaletteFade.active)
        {
            sTradeData->state++;
            SetTradeSequenceBgGpuRegs(1);
            sTradeData->bg1vofs = 166;
            SetTradeSequenceBgGpuRegs(3);
            sTradeData->bg2vofs = 412;
            sTradeData->connectionSpriteId1 = CreateSprite(&sSpriteTemplate_LinkMonGlow, 120, -20, 3);
            gSprites[sTradeData->connectionSpriteId1].callback = SpriteCB_LinkMonGlowWireless;
            sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_LinkMonShadow, 120, -20, 0);
            StartSpriteAnim(&gSprites[sTradeData->connectionSpriteId2], ANIM_LINKMON_SMALL);
        }
        break;
    case TS_STATE_FADE_OUT_TO_GBA_RECV:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_GBA_RECV:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            sTradeData->state++;
        break;
    case TS_STATE_LINK_MON_TRAVEL_IN:
        gSprites[sTradeData->connectionSpriteId1].y2 += 4;
        gSprites[sTradeData->connectionSpriteId2].y2 += 4;
        if (gSprites[sTradeData->connectionSpriteId1].y2 + gSprites[sTradeData->connectionSpriteId1].y == 64)
        {
            sTradeData->state = TS_STATE_PAN_TO_GBA_WIRELESS;
            sTradeData->timer = 0;
        }
        break;
    case TS_STATE_PAN_TO_GBA_WIRELESS:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        sTradeData->bg1vofs += 3;
        sTradeData->bg2vofs += 3;
        if (++sTradeData->timer == 10)
        {
            u8 taskId = CreateTask(Task_AnimateWirelessSignal, 5);
            gTasks[taskId].data[2] = TRUE;
        }
        if (sTradeData->bg1vofs > 316)
        {
            sTradeData->bg1vofs = 316;
            sTradeData->state++;
        }
        break;
    case TS_STATE_DESTROY_LINK_MON_WIRELESS:
        DestroySprite(&gSprites[sTradeData->connectionSpriteId1]);
        DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
        sTradeData->state++;
        sTradeData->timer = 0;
        break;
    case TS_STATE_WAIT_WIRELESS_SIGNAL_RECV:
        if (!FuncIsActiveTask(Task_AnimateWirelessSignal))
        {
            sTradeData->state = TS_STATE_LINK_MON_ARRIVED_DELAY;
            sTradeData->timer = 0;
        }
        break;
    case TS_STATE_LINK_MON_ARRIVED_DELAY:
        if (++sTradeData->timer == 10)
            sTradeData->state++;
        break;
    case TS_STATE_MOVE_GBA_TO_CENTER:
        if (++sTradeData->bg1vofs > 348)
        {
            sTradeData->bg1vofs = 348;
            sTradeData->state++;
        }
        break;
    case TS_STATE_GBA_FLASH_RECV:
        sTradeData->connectionSpriteId2 = CreateSprite(&sSpriteTemplate_GbaScreenFlash_Long, 120, 80, 0);
        sTradeData->state = TS_STATE_GBA_STOP_FLASH_RECV;
        break;
    case TS_STATE_GBA_STOP_FLASH_RECV:
        if (gSprites[sTradeData->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[sTradeData->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(6);
            sTradeData->state++;
            PlaySE(SE_M_SAND_ATTACK);
        }
        break;
    case TS_STATE_GBA_ZOOM_IN:
        if (sTradeData->gbaScale < 0x400)
        {
            sTradeData->gbaScale += 0x34;
        }
        else
        {
            sTradeData->gbaScale = 0x400;
            sTradeData->state++;
        }
        sTradeData->sXY = 0x8000 / sTradeData->gbaScale;
        break;
    case TS_STATE_FADE_OUT_TO_NEW_MON:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeData->state = TS_STATE_WAIT_FADE_OUT_TO_NEW_MON;
        break;
    case TS_STATE_WAIT_FADE_OUT_TO_NEW_MON:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(5);
            SetTradeSequenceBgGpuRegs(7);
            gPaletteFade.bufferTransferDisabled = TRUE;
            sTradeData->state++;
        }
        break;
    case TS_STATE_FADE_IN_TO_NEW_MON:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_IN_TO_NEW_MON:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            sTradeData->state++;
        break;
    case TS_STATE_POKEBALL_ARRIVE:
        sTradeData->bouncingPokeballSpriteId = CreateSprite(&sSpriteTemplate_Pokeball, 120, -8, 0);
        gSprites[sTradeData->bouncingPokeballSpriteId].data[3] = 74;
        gSprites[sTradeData->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballArrive;
        StartSpriteAnim(&gSprites[sTradeData->bouncingPokeballSpriteId], 1);
        StartSpriteAffineAnim(&gSprites[sTradeData->bouncingPokeballSpriteId], 2);
        BlendPalettes(1 << (16 + gSprites[sTradeData->bouncingPokeballSpriteId].oam.paletteNum), 16, RGB_WHITEALPHA);
        sTradeData->state++;
        sTradeData->timer = 0;
        break;
    case TS_STATE_FADE_POKEBALL_TO_NORMAL:
        BeginNormalPaletteFade(1 << (16 + gSprites[sTradeData->bouncingPokeballSpriteId].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
        sTradeData->state++;
        break;
    case TS_STATE_POKEBALL_ARRIVE_WAIT:
        if (gSprites[sTradeData->bouncingPokeballSpriteId].callback == SpriteCallbackDummy)
        {
            HandleLoadSpecialPokePic(&gMonFrontPicTable[sTradeData->monSpecies[TRADE_PARTNER]], 
                                      gMonSpritesGfxPtr->sprites.ptr[3], 
                                      sTradeData->monSpecies[TRADE_PARTNER], 
                                      sTradeData->monPersonalities[TRADE_PARTNER]);
            sTradeData->state++;
        }
        break;
    case TS_STATE_SHOW_NEW_MON:
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].x = 120;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y = gMonFrontPicCoords[sTradeData->monSpecies[TRADE_PARTNER]].y_offset + 60;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].x2 = 0;
        gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].y2 = 0;
        StartSpriteAnim(&gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]], 0);
        CreatePokeballSpriteToReleaseMon(sTradeData->monSpriteIds[TRADE_PARTNER], gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, sTradeData->monSpecies[TRADE_PARTNER]);
        FreeSpriteOamMatrix(&gSprites[sTradeData->bouncingPokeballSpriteId]);
        DestroySprite(&gSprites[sTradeData->bouncingPokeballSpriteId]);
        sTradeData->state++;
        break;
    case TS_STATE_NEW_MON_MSG:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        sTradeData->state = TS_STATE_DELAY_FOR_MON_ANIM;
        sTradeData->timer = 0;
        break;
    case TS_STATE_DELAY_FOR_MON_ANIM:
        if (++sTradeData->timer > 60)
        {
            sTradeData->state = TS_STATE_WAIT_FOR_MON_CRY;
            sTradeData->timer = 0;
        }
        break;
    case TS_STATE_WAIT_FOR_MON_CRY:
        if (IsCryFinished())
            sTradeData->state = TS_STATE_TAKE_CARE_OF_MON;
        break;
    case TS_STATE_TAKE_CARE_OF_MON:
        if (++sTradeData->timer == 10)
            PlayFanfare(MUS_EVOLVED);

        if (sTradeData->timer == 250)
        {
            sTradeData->state++;
            StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            sTradeData->timer = 0;
        }
        break;
    case TS_STATE_AFTER_NEW_MON_DELAY:
        if (++sTradeData->timer == 60)
            sTradeData->state++;
        break;
    case TS_STATE_CHECK_RIBBONS:
        CheckPartnersMonForRibbons();
        sTradeData->state++;
        break;
    case TS_STATE_END_LINK_TRADE:
        if (sTradeData->isLinkTrade)
        {
            return TRUE;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            sTradeData->state++;
        }
        break;
    case TS_STATE_TRY_EVOLUTION: // Only if in-game trade, link trades use CB2_TryLinkTradeEvolution
        TradeMons(gSpecialVar_0x8005, 0);
        gCB2_AfterEvolution = CB2_UpdateInGameTrade;
        evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], EVO_MODE_TRADE, ITEM_NONE, GetMonData(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PARTNER]], MON_DATA_SPECIES));
        if (evoTarget != SPECIES_NONE)
        {
            TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeData->monSpriteIds[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
        }
        sTradeData->state++;
        break;
    case TS_STATE_FADE_OUT_END:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeData->state++;
        break;
    case TS_STATE_WAIT_FADE_OUT_END:
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
            BufferInGameTradeMonName();
        }
        break;
    }
    return FALSE;
}

// Try to evolve a Pokémon received in a link trade
// In-game trades resolve evolution during the trade sequence, in TS_STATE_TRY_EVOLUTION
static void CB2_TryLinkTradeEvolution(void)
{
    u16 evoTarget;
    switch (gMain.state)
    {
    case 0:
        gMain.state = 4;
        gSoftResetDisabled = TRUE;
        break;
    case 4:
        gCB2_AfterEvolution = CB2_SaveAndEndTrade;
        evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], EVO_MODE_TRADE, ITEM_NONE, GetMonData(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PARTNER]], MON_DATA_SPECIES));
        if (evoTarget != SPECIES_NONE)
            TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, sTradeData->monSpriteIds[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
        else if (IsWirelessTrade())
            SetMainCallback2(CB2_SaveAndEndWirelessTrade);
        else
            SetMainCallback2(CB2_SaveAndEndTrade);
        gSelectedTradeMonPositions[TRADE_PLAYER] = 255;
        break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void UpdateTradeFinishFlags(void)
{
    u8 blockReceivedStatus;
    TradeGetMultiplayerId(); // no effect call, ret val ignored
    blockReceivedStatus = GetBlockReceivedStatus();
    if (blockReceivedStatus & 0x01)
    {
        if (gBlockRecvBuffer[0][0] == LINKCMD_CONFIRM_FINISH_TRADE)
            SetMainCallback2(CB2_TryLinkTradeEvolution);

        if (gBlockRecvBuffer[0][0] == LINKCMD_READY_FINISH_TRADE)
            sTradeData->playerLinkFlagFinishTrade = READY_FINISH_TRADE;

        ResetBlockReceivedFlag(0);
    }
    if (blockReceivedStatus & 0x02)
    {
        if (gBlockRecvBuffer[1][0] == LINKCMD_READY_FINISH_TRADE)
            sTradeData->partnerLinkFlagFinishTrade = READY_FINISH_TRADE;

        ResetBlockReceivedFlag(1);
    }
}

static void SpriteCB_BouncingPokeball(struct Sprite *sprite)
{
    sprite->y += sprite->data[0] / 10;
    sprite->data[5] += sprite->data[1];
    sprite->x = sprite->data[5] / 10;
    if (sprite->y > 0x4c)
    {
        sprite->y = 0x4c;
        sprite->data[0] = -(sprite->data[0] * sprite->data[2]) / 100;
        sprite->data[3] ++;
    }
    if (sprite->x == 0x78)
        sprite->data[1] = 0;
    sprite->data[0] += sprite->data[4];
    if (sprite->data[3] == 4)
    {
        sprite->data[7] = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_BouncingPokeballDepart(struct Sprite *sprite)
{
    sprite->y2 += sTradeBallVerticalVelocityTable[sprite->data[0]];
    if (sprite->data[0] == 22)
        PlaySE(SE_BALL_BOUNCE_1);
    if (++ sprite->data[0] == 44)
    {
        PlaySE(SE_M_MEGA_KICK);
        sprite->callback = SpriteCB_BouncingPokeballDepartEnd;
        sprite->data[0] = 0;
        BeginNormalPaletteFade(1 << (16 + sprite->oam.paletteNum), -1, 0, 16, RGB_WHITEALPHA);
    }
}

static void SpriteCB_BouncingPokeballDepartEnd(struct Sprite *sprite)
{
    if (sprite->data[1] == 20)
        StartSpriteAffineAnim(sprite, 1);
    if (++ sprite->data[1] > 20)
    {
        sprite->y2 -= sTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++ sprite->data[0] == 23)
        {
            DestroySprite(sprite);
            sTradeData->state = TS_STATE_FADE_OUT_TO_GBA_SEND; // Resume the master trade animation
        }
    }
}

static void SpriteCB_BouncingPokeballArrive(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->y += 4) > sprite->data[3])
        {
            sprite->data[2] ++;
            sprite->data[0] = 0x16;
            PlaySE(SE_BALL_BOUNCE_1);
        }
    }
    else
    {
        if (sprite->data[0] == 0x42)
            PlaySE(SE_BALL_BOUNCE_2);
        if (sprite->data[0] == 0x5c)
            PlaySE(SE_BALL_BOUNCE_3);
        if (sprite->data[0] == 0x6b)
            PlaySE(SE_BALL_BOUNCE_4);
        sprite->y2 += sTradeBallVerticalVelocityTable[sprite->data[0]];
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

static void BufferInGameTradeMonName(void)
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

    CreateMon(pokemon, inGameTrade->species, level, USE_RANDOM_IVS, TRUE, inGameTrade->personality, OT_ID_PRESET, inGameTrade->otId);

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

static void CB2_UpdateLinkTrade(void)
{
    if (AnimateTradeSequence() == TRUE)
    {
        DestroySprite(&gSprites[sTradeData->monSpriteIds[TRADE_PLAYER]]);
        FreeSpriteOamMatrix(&gSprites[sTradeData->monSpriteIds[TRADE_PARTNER]]);
        TradeMons(gSelectedTradeMonPositions[TRADE_PLAYER], gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE);
        if (!IsWirelessTrade())
        {
            sTradeData->linkData[0] = LINKCMD_READY_FINISH_TRADE;
            sTradeData->sendTradeFinishState = 1;
        }
        SetMainCallback2(CB2_TryFinishTrade);
    }
    TrySendTradeFinishData();
    UpdateTradeFinishFlags();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_TryFinishTrade(void)
{
    u8 mpId = TradeGetMultiplayerId();
    if (IsWirelessTrade())
    {
        SetMainCallback2(CB2_TryLinkTradeEvolution);
    }
    else
    {
        UpdateTradeFinishFlags();
        if (mpId == 0
            && sTradeData->playerLinkFlagFinishTrade == READY_FINISH_TRADE
            && sTradeData->partnerLinkFlagFinishTrade == READY_FINISH_TRADE)
        {
            sTradeData->linkData[0] = LINKCMD_CONFIRM_FINISH_TRADE;
            SendBlock(bitmask_all_link_players_but_self(), sTradeData->linkData, sizeof(sTradeData->linkData));
            sTradeData->playerLinkFlagFinishTrade = FINISH_TRADE;
            sTradeData->partnerLinkFlagFinishTrade = FINISH_TRADE;
        }
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_SaveAndEndTrade(void)
{
    switch (gMain.state)
    {
    case 0:
        gMain.state++;
        StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        break;
    case 1:
        SetTradeLinkStandbyCallback(0);
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
            RecordIdOfWonderCardSenderByEventType(2, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);
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
            SetTradeLinkStandbyCallback(1);
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
            SetTradeLinkStandbyCallback(2);
        }
        break;
    case 6:
        if (_IsLinkTaskFinished())
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
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
            if (gWirelessCommType && gMain.savedCallback == CB2_StartCreateTradeMenu)
            {
                SetTradeLinkStandbyCallback(3);
            }
            else
            {
                SetCloseLinkCallback();
            }
            gMain.state++;
        }
        break;
    case 9:
        if (gWirelessCommType && gMain.savedCallback == CB2_StartCreateTradeMenu)
        {
            if (_IsLinkTaskFinished())
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(CB2_FreeTradeData);
            }
        }
        else if (!gReceivedRemoteLinkPlayers)
        {
            gSoftResetDisabled = FALSE;
            SetMainCallback2(CB2_FreeTradeData);
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

static void CB2_FreeTradeData(void)
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
    CreateTask(Task_InGameTrade, 10);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

static void Task_InGameTrade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InGameTrade);
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
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
    sTradeData->textColors[0] = TEXT_DYNAMIC_COLOR_6;
    sTradeData->textColors[1] = TEXT_COLOR_WHITE;
    sTradeData->textColors[2] = TEXT_COLOR_GREEN;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, sTradeData->textColors, speed, str);
    CopyWindowToVram(windowId, 3);
}

#define idx               data[0]
#define counter           data[1]
#define signalComingBack  data[2]

static void Task_AnimateWirelessSignal(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 paletteIdx = sWirelessSignalTiming[idx][0] * 16;

    if (!signalComingBack)
    {
        if (paletteIdx == 256)
            LoadPalette(sWirelessSignalNone_Pal, 0x30, 32);
        else
            LoadPalette(&sWirelessSignalSend_Pal[paletteIdx], 0x30, 32);
    }
    else
    {
        if (paletteIdx == 256)
            LoadPalette(sWirelessSignalNone_Pal, 0x30, 32);
        else
            LoadPalette(&sWirelessSignalRecv_Pal[paletteIdx], 0x30, 32);
    }

    if (sWirelessSignalTiming[idx][0] == 0 && counter == 0)
        PlaySE(SE_M_HEAL_BELL);

    if (counter == sWirelessSignalTiming[idx][1])
    {
        idx++;
        counter = 0;
        if (sWirelessSignalTiming[idx][1] == 0xFF)
        {
            DestroyTask(taskId);
        }
    }
    else
    {
        counter++;
    }
}

#undef idx
#undef counter
#undef signalComingBack

static void Task_NarrowWindowForCrossing_Wireless(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        sTradeData->wirelessWinLeft = sTradeData->wirelessWinRight = DISPLAY_WIDTH / 2;
        sTradeData->wirelessWinTop = 0;
        sTradeData->wirelessWinBottom = DISPLAY_HEIGHT;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(sTradeData->wirelessWinLeft, sTradeData->wirelessWinRight));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(sTradeData->wirelessWinTop, sTradeData->wirelessWinBottom));

    data[0]++;
    sTradeData->wirelessWinLeft -= 5;
    sTradeData->wirelessWinRight += 5;

    if (sTradeData->wirelessWinLeft < 80)
        DestroyTask(taskId);
}

static void Task_NarrowWindowForCrossing_Cable(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        sTradeData->wirelessWinLeft = 80;
        sTradeData->wirelessWinRight = DISPLAY_WIDTH - 80;
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(sTradeData->wirelessWinLeft, sTradeData->wirelessWinRight));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(sTradeData->wirelessWinTop, sTradeData->wirelessWinBottom));

    if (sTradeData->wirelessWinLeft != DISPLAY_WIDTH / 2)
    {
        data[0]++;
        sTradeData->wirelessWinLeft += 5;
        sTradeData->wirelessWinRight -= 5;

        if (sTradeData->wirelessWinLeft > DISPLAY_WIDTH / 2 - 5)
            BlendPalettes(0x8, 0, RGB_WHITEALPHA);
    }
    else
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
    }
}

static void CB2_SaveAndEndWirelessTrade(void)
{
    switch (gMain.state)
    {
    case 0:
        gMain.state = 1;
        StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        break;
    case 1:
        SetTradeLinkStandbyCallback(0);
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
            gMain.state = 4;
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
                sTradeData->timer = Random() % 30;
            else
                sTradeData->timer = 0;
            gMain.state = 7;
        }
        break;
    case 7:
        if (sTradeData->timer == 0)
        {
            SetTradeLinkStandbyCallback(1);
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
            SetTradeLinkStandbyCallback(2);
        }
        break;
    case 10:
        if (_IsLinkTaskFinished())
        {
            FadeOutBGM(3);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gMain.state = 11;
        }
        break;
    case 11:
        if (!gPaletteFade.active && IsBGMStopped() == TRUE)
        {
            SetTradeLinkStandbyCallback(3);
            gMain.state = 12;
        }
        break;
    case 12:
        if (_IsLinkTaskFinished())
        {
            gSoftResetDisabled = FALSE;
            SetMainCallback2(CB2_FreeTradeData);
        }
        break;
    }

    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
