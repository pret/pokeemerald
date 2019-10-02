#include "global.h"
#include "scanline_effect.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "window.h"
#include "malloc.h"
#include "link.h"
#include "bg.h"
#include "sound.h"
#include "frontier_pass.h"
#include "overworld.h"
#include "menu.h"
#include "text.h"
#include "event_data.h"
#include "easy_chat.h"
#include "money.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "pokemon_icon.h"
#include "trainer_pokemon_sprites.h"
#include "script_pokemon_util_80F87D8.h"
#include "constants/songs.h"
#include "constants/flags.h"
#include "constants/game_stat.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"

enum
{
    CARD_TYPE_FRLG,
    CARD_TYPE_RS,
    CARD_TYPE_EMERALD,
};

struct TrainerCardData
{
    u8 var_0;
    u8 printState;
    u8 gfxLoadState;
    u8 bgPalLoadState;
    u8 var_4;
    bool8 isLink;
    u8 var_6;
    u8 var_7;
    u8 var_8;
    bool8 allowDMACopy;
    bool8 hasPokedex;
    bool8 hasHofResult;
    bool8 hasLinkResults;
    bool8 hasBattleTowerWins;
    u8 var_E;
    u8 var_F;
    bool8 hasTrades;
    u8 badgeCount[8];
    u8 var_19[4][0xD];
    u8 var_4D[0x46];
    u8 var_93[0x46];
    u8 var_D9[0x8C];
    u8 var_165[0x46];
    u8 var_1AB[0x8C];
    u8 var_237[0x8C];
    u8 var_2C3[0x8C];
    u8 var_34F[0x46];
    u8 var_395[0x46];
    u8 var_3DB[0x46];
    u8 var_421[0x46];
    u16 var_468[0x60];
    s8 var_528;
    u8 var_529;
    u8 cardType;
    bool8 isHoenn;
    u16 var_52C;
    void (*callback2)(void);
    struct TrainerCard trainerCard;
    u16 var_598[0x4B0 / 2];
    u16 var_A48[0x4B0 / 2];
    u16 var_EF8[0x4B0 / 2];
    u8 var_13A8[0x400];
    u8 var_17A8[0x200];
    u8 var_19A8[0x2300];
    u16 var_3CA8[0x2000 / 2];
    u16 var_5CA8[0x2000 / 2];
    u16 var_7CA8;
    u8 language;
};

// EWRAM
EWRAM_DATA struct TrainerCard gTrainerCards[4] = {0};
EWRAM_DATA static struct TrainerCardData *sData = NULL;

//this file's functions
static void VblankCb_TrainerCard(void);
static void HblankCb_TrainerCard(void);
static void sub_80C48C8(void);
static void CB2_TrainerCard(void);
static void CloseTrainerCard(u8 task);
static bool8 PrintAllOnCardPage1(void);
static void sub_80C438C(u8);
static void sub_80C4FF0(void);
static void sub_80C4550(u16*);
static void sub_80C45C0(u16*);
static void TrainerCard_PrintStarsAndBadgesOnCard(void);
static void PrintTimeOnCard(void);
static void sub_80C4918(void);
static bool8 sub_80C4940(void);
static bool8 LoadCardGfx(void);
static void CB2_InitTrainerCard(void);
static u32 GetCappedGameStat(u8 statId, u32 maxValue);
static bool8 HasAllFrontierSymbols(void);
static u8 GetRubyTrainerStars(struct TrainerCard*);
static u16 GetCaughtMonsCount(void);
static void SetPlayerCardData(struct TrainerCard*, u8);
static void TrainerCard_GenerateCardForLinkPlayer(struct TrainerCard*);
static u8 VersionToCardType(u8);
static void SetDataFromTrainerCard(void);
static void HandleGpuRegs(void);
static void ResetGpuRegs(void);
static void InitBgsAndWindows(void);
static void SetTrainerCardCb2(void);
static void sub_80C3414(void);
static void sub_80C4EE4(void);
static u8 GetSetCardType(void);
static void PrintNameOnCard(void);
static void PrintIdOnCard(void);
static void PrintMoneyOnCard(void);
static void PrintPokedexOnCard(void);
static void PrintProfilePhraseOnCard(void);
static bool8 PrintStringsOnCardPage2(void);
static void sub_80C3B50(void);
static void PrintHofDebutStringOnCard(void);
static void PrintWinsLossesStringOnCard(void);
static void PrintTradesStringOnCard(void);
static void PrintBerryCrushStringOnCard(void);
static void PrintPokeblockStringOnCard(void);
static void PrintUnionStringOnCard(void);
static void PrintContestStringOnCard(void);
static void TrainerCard_PrintPokemonIconsOnCard(void);
static void PrintBattleFacilityStringOnCard(void);
static void sub_80C42A4(void);
static void PrintAllVariableNumsOnCardPage2(void);
static void PrintNameOnCard2(void);
static void PrintHofTimeOnCard(void);
static void PrintLinkResultsNumsOnCard(void);
static void PrintTradesNumOnCard(void);
static void PrintBerryCrushNumOnCard(void);
static void PrintUnionNumOnCard(void);
static void PrintPokeblocksNumOnCard(void);
static void PrintContestNumOnCard(void);
static void PrintBattleFacilityNumsOnCard(void);
static void PrintString(u8 top, const u8* str1, u8* str2, const u8* color);
static void sub_80C4330(void);
static u8 SetCardBgsAndPals(void);
static void sub_80C474C(void);
static void sub_80C4960(u8);
static bool8 sub_80C4998(struct Task* task);
static bool8 sub_80C49D8(struct Task* task);
static bool8 sub_80C4B08(struct Task* task);
static bool8 sub_80C4C1C(struct Task* task);
static bool8 sub_80C4C84(struct Task* task);
static bool8 sub_80C4DB0(struct Task* task);
static void sub_80C32EC(u16);
static void sub_80C41D8(void);

// const rom data
static const u32 gUnknown_0856F018[] = INCBIN_U32("graphics/trainer_card/stickers_fr.4bpp.lz");
static const u16 gUnknown_0856F18C[] = INCBIN_U16("graphics/trainer_card/unknown_56F18C.gbapal");
static const u16 gEmeraldTrainerCard1Star_Pal[] = INCBIN_U16("graphics/trainer_card/one_star.gbapal");
static const u16 gFireRedTrainerCard1Star_Pal[] = INCBIN_U16("graphics/trainer_card/one_star_fr.gbapal");
static const u16 gEmeraldTrainerCard2Star_Pal[] = INCBIN_U16("graphics/trainer_card/two_stars.gbapal");
static const u16 gFireRedTrainerCard2Star_Pal[] = INCBIN_U16("graphics/trainer_card/two_stars_fr.gbapal");
static const u16 gEmeraldTrainerCard3Star_Pal[] = INCBIN_U16("graphics/trainer_card/three_stars.gbapal");
static const u16 gFireRedTrainerCard3Star_Pal[] = INCBIN_U16("graphics/trainer_card/three_stars_fr.gbapal");
static const u16 gEmeraldTrainerCard4Star_Pal[] = INCBIN_U16("graphics/trainer_card/four_stars.gbapal");
static const u16 gFireRedTrainerCard4Star_Pal[] = INCBIN_U16("graphics/trainer_card/four_stars_fr.gbapal");
static const u16 sEmeraldTrainerCardFemaleBackground_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg.gbapal");
static const u16 sFireRedTrainerCardFemaleBackground_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg_fr.gbapal");
static const u16 sEmeraldTrainerCardBadges_Pal[] = INCBIN_U16("graphics/trainer_card/badges.gbapal");
static const u16 sFireRedTrainerCardBadges_Pal[] = INCBIN_U16("graphics/trainer_card/badges_fr.gbapal");
static const u16 gUnknown_0856F52C[] = INCBIN_U16("graphics/trainer_card/gold.gbapal");
static const u16 gUnknown_0856F54C[] = INCBIN_U16("graphics/trainer_card/stickers_fr1.gbapal");
static const u16 gUnknown_0856F56C[] = INCBIN_U16("graphics/trainer_card/stickers_fr2.gbapal");
static const u16 gUnknown_0856F58C[] = INCBIN_U16("graphics/trainer_card/stickers_fr3.gbapal");
static const u16 gUnknown_0856F5AC[] = INCBIN_U16("graphics/trainer_card/stickers_fr4.gbapal");
static const u32 sEmeraldTrainerCardBadges_Tile[] = INCBIN_U32("graphics/trainer_card/badges.4bpp.lz");
static const u32 sFireRedTrainerCardBadges_Tile[] = INCBIN_U32("graphics/trainer_card/badges_fr.4bpp.lz");

static const struct BgTemplate gUnknown_0856FAB4[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 192
    },
};

static const struct WindowTemplate gUnknown_0856FAC4[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x253,
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    {
        .bg = 3,
        .tilemapLeft = 19,
        .tilemapTop = 5,
        .width = 9,
        .height = 10,
        .paletteNum = 8,
        .baseBlock = 0x150,
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 *const gEmeraldTrainerCardStarPals[] =
{
    gEmeraldTrainerCard0Star_Pal,
    gEmeraldTrainerCard1Star_Pal,
    gEmeraldTrainerCard2Star_Pal,
    gEmeraldTrainerCard3Star_Pal,
    gEmeraldTrainerCard4Star_Pal,
};

static const u16 *const gFireRedTrainerCardStarPals[] =
{
    gFireRedTrainerCard0Star_Pal,
    gFireRedTrainerCard1Star_Pal,
    gFireRedTrainerCard2Star_Pal,
    gFireRedTrainerCard3Star_Pal,
    gFireRedTrainerCard4Star_Pal,
};

static const u8 gUnknown_0856FB0C[] = {0, 2, 3};
static const u8 gUnknown_0856FB0F[] = {0, 4, 5};
static const u8 gUnknown_0856FB12[6] = {0};

static const u8 gUnknown_0856FB18[][2][2] =
{
    {{0xD, 4}, {0xD, 4}},
    {{1, 0}, {1, 0}},
};

static const u8 gUnknown_0856FB20[][2] = {{0x4E, 0x4F}, {0x50, 0x51}, {0x3C, 0x3F}};

static bool8 (*const gUnknown_0856FB28[])(struct Task *) =
{
    sub_80C4998,
    sub_80C49D8,
    sub_80C4B08,
    sub_80C4C1C,
    sub_80C4C84,
    sub_80C4DB0,
};

// code
static void VblankCb_TrainerCard(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_80C48C8();
    if (sData->allowDMACopy)
        DmaCopy16(3, &gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 0x140);
}

static void HblankCb_TrainerCard(void)
{
    u16 backup;
    u16 bgVOffset;

    backup = REG_IME;
    REG_IME = 0;
    bgVOffset = gScanlineEffectRegBuffers[1][REG_VCOUNT & 0xFF];
    REG_BG0VOFS = bgVOffset;
    REG_IME = backup;
}

static void CB2_TrainerCard(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CloseTrainerCard(u8 taskId)
{
    SetMainCallback2(sData->callback2);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sData);
    DestroyTask(taskId);
}

static void sub_80C2760(u8 taskId)
{
    switch (sData->var_0)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            sData->var_0++;
        }
        break;
    case 1:
        if (PrintAllOnCardPage1())
            sData->var_0++;
        break;
    case 2:
        sub_80C438C(1);
        sData->var_0++;
        break;
    case 3:
        FillWindowPixelBuffer(2, PIXEL_FILL(0));
        sub_80C4FF0();
        sub_80C438C(2);
        sData->var_0++;
        break;
    case 4:
        sub_80C4550(sData->var_EF8);
        sData->var_0++;
        break;
    case 5:
        sub_80C45C0(sData->var_598);
        sData->var_0++;
        break;
    case 6:
        TrainerCard_PrintStarsAndBadgesOnCard();
        sData->var_0++;
        break;
    case 7:
        if (gWirelessCommType == 1 && gReceivedRemoteLinkPlayers == TRUE)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(230, 150);
        }
        BlendPalettes(0xFFFFFFFF, 16, sData->var_52C);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, sData->var_52C);
        SetVBlankCallback(VblankCb_TrainerCard);
        sData->var_0++;
        break;
    case 8:
        if (!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_RG_CARD3);
            sData->var_0 = 10;
        }
        break;
    case 9:
        if (!IsSEPlaying())
            sData->var_0++;
        break;
    case 10:
        if (!gReceivedRemoteLinkPlayers && sData->var_529)
        {
            PrintTimeOnCard();
            sub_80C438C(1);
            sData->var_529 = 0;
        }
        if (gMain.newKeys & A_BUTTON)
        {
            sub_80C4918();
            PlaySE(SE_RG_CARD1);
            sData->var_0 = 12;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
            {
                sData->var_0 = 15;
            }
            else
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, sData->var_52C);
                sData->var_0 = 14;
            }
        }
        break;
    case 12:
        if (sub_80C4940() && sub_8087598() != TRUE)
        {
            PlaySE(SE_RG_CARD3);
            sData->var_0 = 11;
        }
        break;
    case 11:
        if (gMain.newKeys & B_BUTTON)
        {
            if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
            {
                sData->var_0 = 15;
            }
            else if (gReceivedRemoteLinkPlayers)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, sData->var_52C);
                sData->var_0 = 14;
            }
            else
            {
                sub_80C4918();
                sData->var_0 = 13;
                PlaySE(SE_RG_CARD1);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
           if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
           {
               sData->var_0 = 15;
           }
           else
           {
               BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, sData->var_52C);
               sData->var_0 = 14;
           }
        }
        break;
    case 15:
        sub_800AC34();
        DrawDialogueFrame(0, 1);
        AddTextPrinterParameterized(0, 1, gText_WaitingTrainerFinishReading, 0, 1, 255, 0);
        CopyWindowToVram(0, 3);
        sData->var_0 = 16;
        break;
    case 16:
        if (!gReceivedRemoteLinkPlayers)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, sData->var_52C);
            sData->var_0 = 14;
        }
        break;
    case 14:
        if (!UpdatePaletteFade())
            CloseTrainerCard(taskId);
        break;
    case 13:
        if (sub_80C4940() && sub_8087598() != TRUE)
        {
            sData->var_0 = 10;
            PlaySE(SE_RG_CARD3);
        }
        break;
   }
}

static bool8 LoadCardGfx(void)
{
    switch (sData->gfxLoadState)
    {
    case 0:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gUnknown_08DD1F78, sData->var_EF8);
        else
            LZ77UnCompWram(gUnknown_08DD2AE0, sData->var_EF8);
        break;
    case 1:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gUnknown_08DD21B0, sData->var_A48);
        else
            LZ77UnCompWram(gUnknown_08DD2D30, sData->var_A48);
        break;
    case 2:
        if (!sData->isLink)
        {
            if (sData->cardType != CARD_TYPE_FRLG)
                LZ77UnCompWram(gUnknown_08DD2010, sData->var_598);
            else
                LZ77UnCompWram(gUnknown_08DD2B78, sData->var_598);
        }
        else
        {
            if (sData->cardType != CARD_TYPE_FRLG)
                LZ77UnCompWram(gUnknown_08DD228C, sData->var_598);
            else
                LZ77UnCompWram(gUnknown_08DD2E5C, sData->var_598);
        }
        break;
    case 3:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(sEmeraldTrainerCardBadges_Tile, sData->var_13A8);
        else
            LZ77UnCompWram(sFireRedTrainerCardBadges_Tile, sData->var_13A8);
        break;
    case 4:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gEmeraldTrainerCard_Gfx, sData->var_19A8);
        else
            LZ77UnCompWram(gFireRedTrainerCard_Gfx, sData->var_19A8);
        break;
    case 5:
        if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(gUnknown_0856F018, sData->var_17A8);
        break;
    default:
        sData->gfxLoadState = 0;
        return TRUE;
    }
    sData->gfxLoadState++;
    return FALSE;
}

static void CB2_InitTrainerCard(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetGpuRegs();
        sub_80C3414();
        gMain.state++;
        break;
    case 1:
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        gMain.state++;
        break;
    case 2:
        if (!sData->var_52C)
            DmaClear16(3, (void *)PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        gMain.state++;
    case 4:
        InitBgsAndWindows();
        gMain.state++;
        break;
    case 5:
        sub_80C41D8();
        gMain.state++;
        break;
    case 6:
        if (LoadCardGfx() == TRUE)
            gMain.state++;
        break;
    case 7:
        sub_80C4330();
        gMain.state++;
        break;
    case 8:
        HandleGpuRegs();
        gMain.state++;
        break;
    case 9:
        PrintAllVariableNumsOnCardPage2();
        gMain.state++;
        break;
    case 10:
        if (SetCardBgsAndPals() == TRUE)
            gMain.state++;
        break;
    default:
        SetTrainerCardCb2();
        break;
    }
}

static u32 GetCappedGameStat(u8 statId, u32 maxValue)
{
    u32 statValue = GetGameStat(statId);

    return min(maxValue, statValue);
}

static bool8 HasAllFrontierSymbols(void)
{
    u8 i;
    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (!FlagGet(FLAG_SYS_TOWER_SILVER + 2 * i) || !FlagGet(FLAG_SYS_TOWER_GOLD + 2 * i))
            return FALSE;
    }
    return TRUE;
}

u32 CountPlayerTrainerStars(void)
{
    u8 stars = 0;

    if (GetGameStat(GAME_STAT_ENTERED_HOF))
        stars++;
    if (HasAllHoennMons())
        stars++;
    if (CountPlayerContestPaintings() > 4)
        stars++;
    if (HasAllFrontierSymbols())
        stars++;

    return stars;
}

static u8 GetRubyTrainerStars(struct TrainerCard *trainerCard)
{
    u8 stars = 0;

    if (trainerCard->hofDebutHours || trainerCard->hofDebutMinutes || trainerCard->hofDebutSeconds)
        stars++;
    if (trainerCard->caughtAllHoenn)
        stars++;
    if (trainerCard->battleTowerStraightWins > 49)
        stars++;
    if (trainerCard->hasAllPaintings)
        stars++;

    return stars;
}

static void SetPlayerCardData(struct TrainerCard *trainerCard, u8 cardType)
{
    u32 playTime;
    u8 i;

    trainerCard->gender = gSaveBlock2Ptr->playerGender;
    trainerCard->playTimeHours = gSaveBlock2Ptr->playTimeHours;
    trainerCard->playTimeMinutes = gSaveBlock2Ptr->playTimeMinutes;

    playTime = GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME);
    if (!GetGameStat(GAME_STAT_ENTERED_HOF))
        playTime = 0;

    trainerCard->hofDebutHours = playTime >> 16;
    trainerCard->hofDebutMinutes = (playTime >> 8) & 0xFF;
    trainerCard->hofDebutSeconds = playTime & 0xFF;
    if ((playTime >> 16) > 999)
    {
        trainerCard->hofDebutHours = 999;
        trainerCard->hofDebutMinutes = 59;
        trainerCard->hofDebutSeconds = 59;
    }

    trainerCard->hasPokedex = FlagGet(FLAG_SYS_POKEDEX_GET);
    trainerCard->caughtAllHoenn = HasAllHoennMons();
    trainerCard->caughtMonsCount = GetCaughtMonsCount();

    trainerCard->trainerId = (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0];

    trainerCard->linkBattleWins = GetCappedGameStat(GAME_STAT_LINK_BATTLE_WINS, 9999);
    trainerCard->linkBattleLosses = GetCappedGameStat(GAME_STAT_LINK_BATTLE_LOSSES, 9999);

    trainerCard->pokemonTrades = GetCappedGameStat(GAME_STAT_POKEMON_TRADES, 0xFFFF);

    trainerCard->money = GetMoney(&gSaveBlock1Ptr->money);

    for (i = 0; i < 4; i++)
        trainerCard->var_28[i] = gSaveBlock1Ptr->easyChatProfile[i];

    StringCopy(trainerCard->playerName, gSaveBlock2Ptr->playerName);

    switch (cardType)
    {
    case CARD_TYPE_EMERALD:
        trainerCard->battleTowerWins = 0;
        trainerCard->battleTowerStraightWins = 0;
    // Seems like GF got CARD_TYPE_FRLG and CARD_TYPE_RS wrong.
    case CARD_TYPE_FRLG:
        trainerCard->contestsWithFriends = GetCappedGameStat(GAME_STAT_WON_LINK_CONTEST, 999);
        trainerCard->pokeblocksWithFriends = GetCappedGameStat(GAME_STAT_POKEBLOCKS_WITH_FRIENDS, 0xFFFF);
        if (CountPlayerContestPaintings() > 4)
            trainerCard->hasAllPaintings = TRUE;
        trainerCard->stars = GetRubyTrainerStars(trainerCard);
        break;
    case CARD_TYPE_RS:
        trainerCard->battleTowerWins = 0;
        trainerCard->battleTowerStraightWins = 0;
        trainerCard->contestsWithFriends = 0;
        trainerCard->pokeblocksWithFriends = 0;
        trainerCard->hasAllPaintings = 0;
        trainerCard->stars = 0;
        break;
    }
}

static void TrainerCard_GenerateCardForLinkPlayer(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, sizeof(struct TrainerCard));
    trainerCard->version = GAME_VERSION;
    SetPlayerCardData(trainerCard, CARD_TYPE_EMERALD);
    trainerCard->hasAllSymbols = HasAllFrontierSymbols();
    trainerCard->frontierBP = gSaveBlock2Ptr->frontier.field_EBA;
    if (trainerCard->hasAllSymbols)
        trainerCard->stars++;

    if (trainerCard->gender == FEMALE)
        trainerCard->var_4F = gLinkPlayerFacilityClasses[(trainerCard->trainerId % 8) + 8];
    else
        trainerCard->var_4F = gLinkPlayerFacilityClasses[trainerCard->trainerId % 8];
}

void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, 0x60);
    trainerCard->version = GAME_VERSION;
    SetPlayerCardData(trainerCard, CARD_TYPE_EMERALD);
    trainerCard->var_3A = HasAllFrontierSymbols();
    *((u16*)&trainerCard->berryCrushPoints) = gSaveBlock2Ptr->frontier.field_EBA;
    if (trainerCard->var_3A)
        trainerCard->stars++;

    if (trainerCard->gender == FEMALE)
        trainerCard->var_4F = gLinkPlayerFacilityClasses[(trainerCard->trainerId % 8) + 8];
    else
        trainerCard->var_4F = gLinkPlayerFacilityClasses[trainerCard->trainerId % 8];
}

void CopyTrainerCardData(struct TrainerCard *dst, u16 *src, u8 gameVersion)
{
    memset(dst, 0, sizeof(struct TrainerCard));
    dst->version = gameVersion;

    switch (VersionToCardType(gameVersion))
    {
    case CARD_TYPE_FRLG:
        memcpy(dst, src, 0x60);
        break;
    case CARD_TYPE_RS:
        memcpy(dst, src, 0x38);
        break;
    case CARD_TYPE_EMERALD:
        memcpy(dst, src, 0x60);
        dst->berryCrushPoints = 0;
        dst->hasAllSymbols = src[29];
        dst->frontierBP = src[30];
        break;
    }
}

static void SetDataFromTrainerCard(void)
{
    u8 i;
    u32 badgeFlag;

    sData->hasPokedex = FALSE;
    sData->hasHofResult = FALSE;
    sData->hasLinkResults = FALSE;
    sData->hasBattleTowerWins = FALSE;
    sData->var_E = 0;
    sData->var_F = 0;
    sData->hasTrades = FALSE;
    memset(sData->badgeCount, 0, sizeof(sData->badgeCount));
    if (sData->trainerCard.hasPokedex)
        sData->hasPokedex++;

    if (sData->trainerCard.hofDebutHours
     || sData->trainerCard.hofDebutMinutes
     || sData->trainerCard.hofDebutSeconds)
        sData->hasHofResult++;

    if (sData->trainerCard.linkBattleWins || sData->trainerCard.linkBattleLosses)
        sData->hasLinkResults++;
    if (sData->trainerCard.pokemonTrades)
        sData->hasTrades++;
    if (sData->trainerCard.battleTowerWins || sData->trainerCard.battleTowerStraightWins)
        sData->hasBattleTowerWins++;

    for (i = 0, badgeFlag = FLAG_BADGE01_GET; badgeFlag <= FLAG_BADGE08_GET; badgeFlag++, i++)
    {
        if (FlagGet(badgeFlag))
            sData->badgeCount[i]++;
    }
}

static void HandleGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0V, 160);
    SetGpuReg(REG_OFFSET_WIN0H, 240);
    if (gReceivedRemoteLinkPlayers)
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    else
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
}

static void sub_80C32EC(u16 arg0)
{
    s8 quotient = (arg0 + 40) / 10;

    if (quotient <= 4)
        quotient = 0;
    sData->var_528 = quotient;
    SetGpuReg(REG_OFFSET_BLDY, sData->var_528);
    SetGpuReg(REG_OFFSET_WIN0V, (sData->var_7CA8 * 256) | (160 - sData->var_7CA8));
}

static void ResetGpuRegs(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
}

static void InitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0856FAB4, ARRAY_COUNT(gUnknown_0856FAB4));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(gUnknown_0856FAC4);
    DeactivateAllTextPrinters();
    sub_81973A4();
}

static void SetTrainerCardCb2(void)
{
    SetMainCallback2(CB2_TrainerCard);
}

static void sub_80C3414(void)
{
    ResetTasks();
    ScanlineEffect_Stop();
    CreateTask(sub_80C2760, 0);
    sub_80C4EE4();
    SetDataFromTrainerCard();
}

static bool8 PrintAllOnCardPage1(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintNameOnCard();
        break;
    case 1:
        PrintIdOnCard();
        break;
    case 2:
        PrintMoneyOnCard();
        break;
    case 3:
        PrintPokedexOnCard();
        break;
    case 4:
        PrintTimeOnCard();
        break;
    case 5:
        PrintProfilePhraseOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static bool8 PrintStringsOnCardPage2(void)
{
    switch (sData->printState)
    {
    case 0:
        sub_80C3B50();
        break;
    case 1:
        PrintHofDebutStringOnCard();
        break;
    case 2:
        PrintWinsLossesStringOnCard();
        break;
    case 3:
        PrintTradesStringOnCard();
        break;
    case 4:
        PrintBerryCrushStringOnCard();
        PrintPokeblockStringOnCard();
        break;
    case 5:
        PrintUnionStringOnCard();
        PrintContestStringOnCard();
        break;
    case 6:
        TrainerCard_PrintPokemonIconsOnCard();
        PrintBattleFacilityStringOnCard();
        break;
    case 7:
        sub_80C42A4();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static void PrintAllVariableNumsOnCardPage2(void)
{
    PrintNameOnCard2();
    PrintHofTimeOnCard();
    PrintLinkResultsNumsOnCard();
    PrintTradesNumOnCard();
    PrintBerryCrushNumOnCard();
    PrintUnionNumOnCard();
    PrintPokeblocksNumOnCard();
    PrintContestNumOnCard();
    PrintBattleFacilityNumsOnCard();
}

static void PrintNameOnCard(void)
{
    u8 buffer[32];
    u8* txtPtr;
    txtPtr = StringCopy(buffer, gText_TrainerCardName);
    StringCopy(txtPtr, sData->trainerCard.playerName);
    ConvertInternationalString(txtPtr, sData->language);
    if (sData->cardType == CARD_TYPE_FRLG)
        AddTextPrinterParameterized3(1, 1, 20, 28, gUnknown_0856FB0C, TEXT_SPEED_FF, buffer);
    else
        AddTextPrinterParameterized3(1, 1, 16, 33, gUnknown_0856FB0C, TEXT_SPEED_FF, buffer);
}

static void PrintIdOnCard(void)
{
    u8 buffer[32];
    u8* txtPtr;
    s32 xPos;
    u32 top;
    txtPtr = StringCopy(buffer, gText_TrainerCardIDNo);
    ConvertIntToDecimalStringN(txtPtr, sData->trainerCard.trainerId, STR_CONV_MODE_LEADING_ZEROS, 5);
    if (sData->cardType == CARD_TYPE_FRLG)
    {
        xPos = GetStringCenterAlignXOffset(1, buffer, 80) + 132;
        top = 9;
    }
    else
    {
        xPos = GetStringCenterAlignXOffset(1, buffer, 96) + 120;
        top = 9;
    }

    AddTextPrinterParameterized3(1, 1, xPos, top, gUnknown_0856FB0C, TEXT_SPEED_FF, buffer);
}

static void PrintMoneyOnCard(void)
{
    s32 xOffset;
    u8 top;

    if (!sData->isHoenn)
        AddTextPrinterParameterized3(1, 1, 20, 56, gUnknown_0856FB0C, TEXT_SPEED_FF, gText_TrainerCardMoney);
    else
        AddTextPrinterParameterized3(1, 1, 16, 57, gUnknown_0856FB0C, TEXT_SPEED_FF, gText_TrainerCardMoney);

    ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.money, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    if (!sData->isHoenn)
    {
        xOffset = GetStringRightAlignXOffset(1, gStringVar4, 144);
        top = 56;
    }
    else
    {
        xOffset = GetStringRightAlignXOffset(1, gStringVar4, 128);
        top = 57;
    }
    AddTextPrinterParameterized3(1, 1, xOffset, top, gUnknown_0856FB0C, TEXT_SPEED_FF, gStringVar4);
}

static u16 GetCaughtMonsCount(void)
{
    if (IsNationalPokedexEnabled())
        return GetNationalPokedexCount(FLAG_GET_CAUGHT);
    else
        return GetHoennPokedexCount(FLAG_GET_CAUGHT);
}

static void PrintPokedexOnCard(void)
{
    s32 xOffset;
    u8 top;
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        if (!sData->isHoenn)
            AddTextPrinterParameterized3(1, 1, 20, 72, gUnknown_0856FB0C, TEXT_SPEED_FF, gText_TrainerCardPokedex);
        else
            AddTextPrinterParameterized3(1, 1, 16, 73, gUnknown_0856FB0C, TEXT_SPEED_FF, gText_TrainerCardPokedex);
        StringCopy(ConvertIntToDecimalStringN(gStringVar4, sData->trainerCard.caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 3), gText_EmptyString6);
        if (!sData->isHoenn)
        {
            xOffset = GetStringRightAlignXOffset(1, gStringVar4, 144);
            top = 72;
        }
        else
        {
            xOffset = GetStringRightAlignXOffset(1, gStringVar4, 128);
            top = 73;
        }
        AddTextPrinterParameterized3(1, 1, xOffset, top, gUnknown_0856FB0C, TEXT_SPEED_FF, gStringVar4);
    }
}

static const u8 *const gUnknown_0856FB40[] = {gUnknown_0856FB0C, gUnknown_0856FB12};

static void PrintTimeOnCard(void)
{
    u16 hours;
    u16 minutes;
    s32 width;
    u32 r7, r4, r10;

    if (!sData->isHoenn)
        AddTextPrinterParameterized3(1, 1, 20, 88, gUnknown_0856FB0C, TEXT_SPEED_FF, gText_TrainerCardTime);
    else
        AddTextPrinterParameterized3(1, 1, 16, 89, gUnknown_0856FB0C, TEXT_SPEED_FF, gText_TrainerCardTime);

    if (sData->isLink)
    {
        hours = sData->trainerCard.playTimeHours;
        minutes = sData->trainerCard.playTimeMinutes;
    }
    else
    {
        hours = gSaveBlock2Ptr->playTimeHours;
        minutes = gSaveBlock2Ptr->playTimeMinutes;
    }

    if (hours > 999)
        hours = 999;
    if (minutes > 59)
        minutes = 59;
    width = GetStringWidth(1, gText_Colon2, 0);

    if (!sData->isHoenn)
    {
        r7 = 144;
        r4 = 88;
    }
    else
    {
        r7 = 128;
        r4 = 89;
    }
    r10 = width + 30;
    r7 -= r10;

    FillWindowPixelRect(1, PIXEL_FILL(0), r7, r4, r10, 15);
    ConvertIntToDecimalStringN(gStringVar4, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized3(1, 1, r7, r4, gUnknown_0856FB0C, TEXT_SPEED_FF, gStringVar4);
    r7 += 18;
    AddTextPrinterParameterized3(1, 1, r7, r4, gUnknown_0856FB40[sData->var_7], TEXT_SPEED_FF, gText_Colon2);
    r7 += width;
    ConvertIntToDecimalStringN(gStringVar4, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(1, 1, r7, r4, gUnknown_0856FB0C, TEXT_SPEED_FF, gStringVar4);
}

static const u8 gUnknown_0856FB48[] = {0x71, 0x68};
static const u8 gUnknown_0856FB4A[] = {0x81, 0x78};

static void PrintProfilePhraseOnCard(void)
{
    if (sData->isLink)
    {
        AddTextPrinterParameterized3(1, 1, 8, gUnknown_0856FB48[sData->isHoenn], gUnknown_0856FB0C, TEXT_SPEED_FF, sData->var_19[0]);
        AddTextPrinterParameterized3(1, 1, GetStringWidth(1, sData->var_19[0], 0) + 14, gUnknown_0856FB48[sData->isHoenn], gUnknown_0856FB0C, TEXT_SPEED_FF, sData->var_19[1]);
        AddTextPrinterParameterized3(1, 1, 8, gUnknown_0856FB4A[sData->isHoenn], gUnknown_0856FB0C, TEXT_SPEED_FF, sData->var_19[2]);
        AddTextPrinterParameterized3(1, 1, GetStringWidth(1, sData->var_19[2], 0) + 14, gUnknown_0856FB4A[sData->isHoenn], gUnknown_0856FB0C, TEXT_SPEED_FF, sData->var_19[3]);
    }
}

static void PrintNameOnCard2(void)
{
    StringCopy(sData->var_4D, sData->trainerCard.playerName);
    ConvertInternationalString(sData->var_4D, sData->language);
    if (sData->cardType != CARD_TYPE_FRLG)
    {
        StringCopy(gStringVar1, sData->var_4D);
        StringExpandPlaceholders(sData->var_4D, gText_Var1sTrainerCard);
    }
}

static void sub_80C3B50(void)
{
    if (!sData->isHoenn)
        AddTextPrinterParameterized3(1, 1, 136, 9, gUnknown_0856FB0C, TEXT_SPEED_FF, sData->var_4D);
    else
        AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->var_4D, 216), 9, gUnknown_0856FB0C, TEXT_SPEED_FF, sData->var_4D);
}

static const u8 gUnknown_0856FB4C[] = {0xfd, 0x02, 0xf0, 0xfd, 0x03, 0xf0, 0xfd, 0x04, 0xff};

static void PrintHofTimeOnCard(void)
{
    if (sData->hasHofResult)
    {
        ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.hofDebutHours, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, sData->trainerCard.hofDebutMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
        ConvertIntToDecimalStringN(gStringVar3, sData->trainerCard.hofDebutSeconds, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(sData->var_93, gUnknown_0856FB4C);
    }
}

static const u8 gUnknown_0856FB55[] = {0x08, 0x10};
static const u8 gUnknown_0856FB57[] = {0xd8, 0xd8};

static void PrintString(u8 top, const u8* str1, u8* str2, const u8* color)
{
    AddTextPrinterParameterized3(1, 1, gUnknown_0856FB55[sData->isHoenn], top * 16 + 33, gUnknown_0856FB0C, TEXT_SPEED_FF, str1);
    AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, str2, gUnknown_0856FB57[sData->isHoenn]), top * 16 + 33, color, TEXT_SPEED_FF, str2);
}

static void PrintHofDebutStringOnCard(void)
{
    if (sData->hasHofResult)
        PrintString(0, gText_HallOfFameDebut, sData->var_93, gUnknown_0856FB0F);
}

static const u8 *const gUnknown_0856FB5C[] = {gText_LinkBattles, gText_LinkCableBattles, gText_LinkBattles};

static void PrintLinkResultsNumsOnCard(void)
{
    if (sData->hasLinkResults)
    {
        StringCopy(sData->var_D9, gUnknown_0856FB5C[sData->cardType]);
        ConvertIntToDecimalStringN(sData->var_165, sData->trainerCard.linkBattleWins, STR_CONV_MODE_LEFT_ALIGN, 4);
        ConvertIntToDecimalStringN(sData->var_1AB, sData->trainerCard.linkBattleLosses, STR_CONV_MODE_LEFT_ALIGN, 4);
    }
}

static void PrintWinsLossesStringOnCard(void)
{
    if (sData->hasLinkResults)
    {
        StringCopy(gStringVar1, sData->var_165);
        StringCopy(gStringVar2, sData->var_1AB);
        StringExpandPlaceholders(gStringVar4, gText_WinsLosses);
        PrintString(1, sData->var_D9, gStringVar4, gUnknown_0856FB0C);
    }
}

static void PrintTradesNumOnCard(void)
{
    if (sData->hasTrades)
        ConvertIntToDecimalStringN(sData->var_237, sData->trainerCard.pokemonTrades, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintTradesStringOnCard(void)
{
    if (sData->hasTrades)
        PrintString(2, gText_PokemonTrades, sData->var_237, gUnknown_0856FB0F);
}

static void PrintBerryCrushNumOnCard(void)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.berryCrushPoints)
        ConvertIntToDecimalStringN(sData->var_2C3, sData->trainerCard.berryCrushPoints, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintBerryCrushStringOnCard(void)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.berryCrushPoints)
        PrintString(4, gText_BerryCrush, sData->var_2C3, gUnknown_0856FB0F);
}

static void PrintUnionNumOnCard(void)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.unionRoomNum)
        ConvertIntToDecimalStringN(sData->var_34F, sData->trainerCard.unionRoomNum, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintUnionStringOnCard(void)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.unionRoomNum)
        PrintString(3, gText_UnionTradesAndBattles, sData->var_34F, gUnknown_0856FB0F);
}

static void PrintPokeblocksNumOnCard(void)
{
    if (sData->cardType != CARD_TYPE_FRLG && sData->trainerCard.pokeblocksWithFriends)
    {
        ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.pokeblocksWithFriends, STR_CONV_MODE_RIGHT_ALIGN, 5);
        StringExpandPlaceholders(sData->var_395, gText_Var1DarkGreyShadowLightGrey);
    }
}

static void PrintPokeblockStringOnCard(void)
{
    if (sData->cardType != CARD_TYPE_FRLG && sData->trainerCard.pokeblocksWithFriends)
        PrintString(3, gText_PokeblocksWithFriends, sData->var_395, gUnknown_0856FB0F);
}

static void PrintContestNumOnCard(void)
{
    if (sData->cardType != CARD_TYPE_FRLG && sData->trainerCard.contestsWithFriends)
        ConvertIntToDecimalStringN(sData->var_3DB, sData->trainerCard.contestsWithFriends, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintContestStringOnCard(void)
{
    if (sData->cardType != CARD_TYPE_FRLG && sData->trainerCard.contestsWithFriends)
        PrintString(4, gText_WonContestsWFriends, sData->var_3DB, gUnknown_0856FB0F);
}

static void PrintBattleFacilityNumsOnCard(void)
{
    switch (sData->cardType)
    {
    case CARD_TYPE_RS:
        if (sData->hasBattleTowerWins)
        {
            ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.battleTowerWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
            ConvertIntToDecimalStringN(gStringVar2, sData->trainerCard.battleTowerStraightWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
            StringExpandPlaceholders(sData->var_421, gText_WSlashStraightSlash);
        }
        break;
    case CARD_TYPE_EMERALD:
        if (sData->trainerCard.frontierBP)
        {
            ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.frontierBP, STR_CONV_MODE_RIGHT_ALIGN, 5);
            StringExpandPlaceholders(sData->var_421, gText_Var1DarkLightGreyBP);
        }
        break;
    case CARD_TYPE_FRLG:
        break;
    }
}

static void PrintBattleFacilityStringOnCard(void)
{
    switch (sData->cardType)
    {
    case CARD_TYPE_RS:
        if (sData->hasBattleTowerWins)
            PrintString(5, gText_BattleTower, sData->var_421, gUnknown_0856FB0C);
        break;
    case CARD_TYPE_EMERALD:
        if (sData->trainerCard.frontierBP)
            PrintString(5, gText_BattlePtsWon, sData->var_421, gUnknown_0856FB0F);
        break;
    case CARD_TYPE_FRLG:
        break;
    }
}

static void TrainerCard_PrintPokemonIconsOnCard(void)
{
    u8 i;
    u8 buffer[] = {0x05, 0x06, 0x07, 0x08, 0x09, 0x0a};
    u8 buffer2[] = {0x00, 0x04, 0x08, 0x0c, 0x10, 0x14};

    if (sData->cardType == CARD_TYPE_FRLG)
    {
        for (i = 0; i < 6; i++)
        {
            if (sData->trainerCard.monSpecies[i])
            {
                u8 monSpecies = GetMonIconPaletteIndexFromSpecies(sData->trainerCard.monSpecies[i]);
                WriteSequenceToBgTilemapBuffer(3, 16 * i + 224, buffer2[i] + 3, 15, 4, 4, buffer[monSpecies], 1);
            }
        }
    }
}

static void sub_80C41D8(void)
{
    u8 i;

    CpuSet(gMonIconPalettes, sData->var_468, 0x60);
    switch (sData->trainerCard.var_4E)
    {
    case 0:
        break;
    case 1:
        TintPalette_CustomTone(sData->var_468, 96, 0, 0, 0);
        break;
    case 2:
        TintPalette_CustomTone(sData->var_468, 96, 500, 330, 310);
        break;
    case 3:
        TintPalette_SepiaTone(sData->var_468, 96);
        break;
    }
    LoadPalette(sData->var_468, 80, 192);

    for (i = 0; i < 6; i++)
    {
        if (sData->trainerCard.monSpecies[i])
            LoadBgTiles(3, GetMonIconTiles(sData->trainerCard.monSpecies[i], 0), 512, 16 * i + 32);
    }
}

static void sub_80C42A4(void)
{
    u8 i;
    u8 buffer[4] = {0x0b, 0x0c, 0x0d, 0x0e};

    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.var_4C == 1)
    {
        for (i = 0; i < 3; i++)
        {
            u8 var_50 = sData->trainerCard.var_50[i];
            if (sData->trainerCard.var_50[i])
                WriteSequenceToBgTilemapBuffer(3, i * 4 + 320, i * 3 + 2, 2, 2, 2, buffer[var_50 - 1], 1);
        }
    }
}

static void sub_80C4330(void)
{
    LoadPalette(gUnknown_0856F54C, 176, 32);
    LoadPalette(gUnknown_0856F56C, 192, 32);
    LoadPalette(gUnknown_0856F58C, 208, 32);
    LoadPalette(gUnknown_0856F5AC, 224, 32);
    LoadBgTiles(3, sData->var_17A8, 1024, 128);
}

static void sub_80C438C(u8 windowId)
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static u8 SetCardBgsAndPals(void)
{
    switch (sData->bgPalLoadState)
    {
    case 0:
        LoadBgTiles(3, sData->var_13A8, 1024, 0);
        break;
    case 1:
        LoadBgTiles(0, sData->var_19A8, 6144, 0);
        break;
    case 2:
        if (sData->cardType != CARD_TYPE_FRLG)
        {
            LoadPalette(gEmeraldTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sEmeraldTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender)
                LoadPalette(sEmeraldTrainerCardFemaleBackground_Pal, 16, 32);
        }
        else
        {
            LoadPalette(gFireRedTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sFireRedTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender)
                LoadPalette(sFireRedTrainerCardFemaleBackground_Pal, 16, 32);
        }
        LoadPalette(gUnknown_0856F52C, 64, 32);
        break;
    case 3:
        SetBgTilemapBuffer(0, sData->var_3CA8);
        SetBgTilemapBuffer(2, sData->var_5CA8);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
    default:
        return 1;
    }
    sData->bgPalLoadState++;
    return 0;
}

static void sub_80C4550(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->var_5CA8;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(2);
}

static void sub_80C45C0(u16* ptr)
{
    s16 i, j;
    u16 *dst = sData->var_3CA8;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(0);
}

static const u8 gUnknown_0856FB78[] = {7, 7};

static void TrainerCard_PrintStarsAndBadgesOnCard(void)
{
    s16 i, x;
    u16 tileNum = 192;
    u8 palNum = 3;

    FillBgTilemapBufferRect(3, 143, 15, gUnknown_0856FB78[sData->isHoenn], sData->trainerCard.stars, 1, 4);
    if (!sData->isLink)
    {
        x = 4;
        for (i = 0; i < 8; i++, tileNum += 2, x += 3)
        {
            if (sData->badgeCount[i])
            {
                FillBgTilemapBufferRect(3, tileNum, x, 15, 1, 1, palNum);
                FillBgTilemapBufferRect(3, tileNum + 1, x + 1, 15, 1, 1, palNum);
                FillBgTilemapBufferRect(3, tileNum + 16, x, 16, 1, 1, palNum);
                FillBgTilemapBufferRect(3, tileNum + 17, x + 1, 16, 1, 1, palNum);
            }
        }
    }
    CopyBgTilemapBufferToVram(3);
}

static void sub_80C474C(void)
{
    if (sData->cardType == CARD_TYPE_FRLG)
    {
        if (sData->hasTrades)
        {
            FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 1);
        }
        if (sData->trainerCard.berryCrushPoints)
        {
            FillBgTilemapBufferRect(3, 141, 21, 13, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 21, 14, 1, 1, 1);
        }
        if (sData->trainerCard.unionRoomNum)
        {
            FillBgTilemapBufferRect(3, 141, 27, 11, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 27, 12, 1, 1, 1);
        }
    }
    else
    {
        if (sData->hasTrades)
        {
            FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 0);
        }
        if (sData->trainerCard.contestsWithFriends)
        {
            FillBgTilemapBufferRect(3, 141, 27, 13, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 27, 14, 1, 1, 0);
        }
        if (sData->hasBattleTowerWins)
        {
            FillBgTilemapBufferRect(3, 141, 17, 15, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 17, 16, 1, 1, 0);
            FillBgTilemapBufferRect(3, 140, 27, 15, 1, 1, 0);
            FillBgTilemapBufferRect(3, 156, 27, 16, 1, 1, 0);
        }
    }
    CopyBgTilemapBufferToVram(3);
}

static void sub_80C48C8(void)
{
    if (++sData->var_6 > 60)
    {
        sData->var_6 = 0;
        sData->var_7 ^= 1;
        sData->var_529 = 1;
    }
}

u8 GetTrainerCardStars(u8 cardId)
{
    struct TrainerCard* trainerCards = gTrainerCards;
    return trainerCards[cardId].stars;
}

static void sub_80C4918(void)
{
    u8 taskId = CreateTask(sub_80C4960, 0);
    sub_80C4960(taskId);
    SetHBlankCallback(HblankCb_TrainerCard);
}

static bool8 sub_80C4940(void)
{
    if (FindTaskIdByFunc(sub_80C4960) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

static void sub_80C4960(u8 taskId)
{
    while(gUnknown_0856FB28[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

static bool8 sub_80C4998(struct Task* task)
{
    u32 i;

    HideBg(1);
    HideBg(3);
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    for (i = 0; i < 160; i++)
        gScanlineEffectRegBuffers[1][i] = 0;
    task->data[0]++;
    return FALSE;
}

static bool8 sub_80C49D8(struct Task* task)
{
    u32 r4, r5, r10, r7, r6, var_24, r9, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->data[1] >= 77)
        task->data[1] = 77;
    else
        task->data[1] += 7;

    sData->var_7CA8 = task->data[1];
    sub_80C32EC(task->data[1]);

    // ???
    r7 = task->data[1];
    r9 = 160 - r7;
    r4 = r9 - r7;
    r6 = -r7 << 16;
    r5 = 0xA00000 / r4;
    r5 += 0xFFFF0000;
    var_24 = r6;
    var_24 += r5 * r4;
    r10 = r5 / r4;
    r5 *= 2;

    for (i = 0; i < r7; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)(r9); i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 -= r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < 160; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->data[1] >= 77)
        task->data[0]++;

    return FALSE;
}

static bool8 sub_80C4B08(struct Task* task)
{
    sData->allowDMACopy = FALSE;
    if (sub_8087598() == TRUE)
        return FALSE;

    do
    {
        switch (sData->var_4)
        {
        case 0:
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
            break;
        case 1:
            if (!sData->var_8)
            {
                if (!PrintStringsOnCardPage2())
                    return FALSE;
            }
            else
            {
                if (!PrintAllOnCardPage1())
                    return FALSE;
            }
            break;
        case 2:
            if (!sData->var_8)
                sub_80C45C0(sData->var_A48);
            else
                sub_80C438C(1);
            break;
        case 3:
            if (!sData->var_8)
                sub_80C474C();
            else
                FillWindowPixelBuffer(2, PIXEL_FILL(0));
            break;
        case 4:
            if (sData->var_8)
                sub_80C4FF0();
            break;
        default:
            task->data[0]++;
            sData->allowDMACopy = TRUE;
            sData->var_4 = 0;
            return FALSE;
        }
        sData->var_4++;
    } while (gReceivedRemoteLinkPlayers == 0);

    return FALSE;
}

static bool8 sub_80C4C1C(struct Task* task)
{
    sData->allowDMACopy = FALSE;
    if (sData->var_8)
    {
        sub_80C438C(2);
        sub_80C4550(sData->var_EF8);
        sub_80C45C0(sData->var_598);
        TrainerCard_PrintStarsAndBadgesOnCard();
    }
    sub_80C438C(1);
    sData->var_8 ^= 1;
    task->data[0]++;
    sData->allowDMACopy = TRUE;
    PlaySE(SE_RG_CARD2);
    return FALSE;
}

static bool8 sub_80C4C84(struct Task* task)
{
    u32 r4, r5, r10, r7, r6, var_24, r9, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->data[1] <= 5)
        task->data[1] = 0;
    else
        task->data[1] -= 5;

    sData->var_7CA8 = task->data[1];
    sub_80C32EC(task->data[1]);

    // ???
    r7 = task->data[1];
    r9 = 160 - r7;
    r4 = r9 - r7;
    r6 = -r7 << 16;
    r5 = 0xA00000 / r4;
    r5 += 0xFFFF0000;
    var_24 = r6;
    var_24 += r5 * r4;
    r10 = r5 / r4;
    r5 /= 2;

    for (i = 0; i < r7; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)(r9); i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 += r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < 160; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->data[1] <= 0)
        task->data[0]++;

    return FALSE;
}

static bool8 sub_80C4DB0(struct Task *task)
{
    ShowBg(1);
    ShowBg(3);
    SetHBlankCallback(NULL);
    DestroyTask(FindTaskIdByFunc(sub_80C4960));
    return FALSE;
}

void ShowPlayerTrainerCard(void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    if (callback == CB2_ReshowFrontierPass)
        sData->var_52C = 0x7FFF;
    else
        sData->var_52C = 0;

    if (InUnionRoom() == TRUE)
        sData->isLink = TRUE;
    else
        sData->isLink = FALSE;

    sData->language = GAME_LANGUAGE;
    TrainerCard_GenerateCardForLinkPlayer(&sData->trainerCard);
    SetMainCallback2(CB2_InitTrainerCard);
}

void ShowTrainerCardInLink(u8 cardId, void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    sData->isLink = TRUE;
    sData->trainerCard = gTrainerCards[cardId];
    sData->language = gLinkPlayers[cardId].language;
    SetMainCallback2(CB2_InitTrainerCard);
}

static void sub_80C4EE4(void)
{
    u8 i;

    sData->var_0 = 0;
    sData->var_6 = gSaveBlock2Ptr->playTimeVBlanks;
    sData->var_7 = 0;
    sData->var_8 = 0;
    sData->var_528 = 0;
    sData->cardType = GetSetCardType();
    for (i = 0; i < 4; i++)
        CopyEasyChatWord(sData->var_19[i], sData->trainerCard.var_28[i]);
}

static u8 GetSetCardType(void)
{
    if (sData == NULL)
    {
        if (gGameVersion == VERSION_FIRE_RED || gGameVersion == VERSION_LEAF_GREEN)
            return CARD_TYPE_FRLG;
        else if (gGameVersion == VERSION_EMERALD)
            return CARD_TYPE_EMERALD;
        else
            return CARD_TYPE_RS;
    }
    else
    {
        if (sData->trainerCard.version == VERSION_FIRE_RED || sData->trainerCard.version == VERSION_LEAF_GREEN)
        {
            sData->isHoenn = FALSE;
            return CARD_TYPE_FRLG;
        }
        else if (sData->trainerCard.version == VERSION_EMERALD)
        {
            sData->isHoenn = TRUE;
            return CARD_TYPE_EMERALD;
        }
        else
        {
            sData->isHoenn = TRUE;
            return CARD_TYPE_RS;
        }
    }
}

static u8 VersionToCardType(u8 version)
{
    if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        return CARD_TYPE_FRLG;
    else if (version == VERSION_EMERALD)
        return CARD_TYPE_EMERALD;
    else
        return CARD_TYPE_RS;
}

static void sub_80C4FF0(void)
{
    if (InUnionRoom() == TRUE && gReceivedRemoteLinkPlayers == 1)
    {
        sub_818D938(FacilityClassToPicIndex(sData->trainerCard.var_4F),
                    TRUE,
                    gUnknown_0856FB18[sData->isHoenn][sData->trainerCard.gender][0],
                    gUnknown_0856FB18[sData->isHoenn][sData->trainerCard.gender][1],
                    8,
                    2);
    }
    else
    {
        sub_818D938(FacilityClassToPicIndex(gUnknown_0856FB20[sData->cardType][sData->trainerCard.gender]),
                    TRUE,
                    gUnknown_0856FB18[sData->isHoenn][sData->trainerCard.gender][0],
                    gUnknown_0856FB18[sData->isHoenn][sData->trainerCard.gender][1],
                    8,
                    2);
    }
}
