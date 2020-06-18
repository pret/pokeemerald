#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "contest.h"
#include "contest_util.h"
#include "contest_painting.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "script_menu.h"
#include "sprite.h"
#include "string_util.h"
#include "tv.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/tv.h"
#include "constants/vars.h"
#include "constants/battle_frontier.h"

extern const u16 gObjectEventPalette8[];
extern const u16 gObjectEventPalette17[];
extern const u16 gObjectEventPalette33[];
extern const u16 gObjectEventPalette34[];

static const u8 gUnknown_0858D8EC[] = { 3, 4, 5, 14 };

static void Task_ShowContestEntryMonPic(u8 taskId);
static void Task_LinkContestWaitForConnection(u8 taskId);
static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleFrontierParty(void);

void SetContestTrainerGfxIds(void)
{
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_0 - VARS_START] = gContestMons[0].trainerGfxId;
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_1 - VARS_START] = gContestMons[1].trainerGfxId;
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_2 - VARS_START] = gContestMons[2].trainerGfxId;
}

// Unused
void sub_80F8814(void)
{
    u16 var1;
    u8 var0 = gSpecialVar_0x8005;
    switch (var0)
    {
    case 0:
        var1 = 3;
        break;
    case 1:
        var1 = 4;
        break;
    case 2:
        var1 = 5;
        break;
    default:
        var1 = 100;
        break;
    }

    gSpecialVar_0x8004 = var1;
}

void BufferContestTrainerAndMonNames(void)
{
    BufferContestantTrainerName();
    BufferContestantMonNickname();
    BufferContestantMonSpecies();
}

// Unused
void DoesContestCategoryHaveWinner(void)
{
    int contestWinner;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        contestWinner = 8;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        contestWinner = 9;
        break;
    case CONTEST_CATEGORY_CUTE:
        contestWinner = 10;
        break;
    case CONTEST_CATEGORY_SMART:
        contestWinner = 11;
        break;
    case CONTEST_CATEGORY_TOUGH:
    default:
        contestWinner = 12;
        break;
    }

    if (gSaveBlock1Ptr->contestWinners[contestWinner].species == SPECIES_NONE)
        gSpecialVar_0x8004 = FALSE;
    else
        gSpecialVar_0x8004 = TRUE;
}

void SaveMuseumContestPainting(void)
{
    sub_80DEDA8(0xFF);
}

void ShouldReadyContestArtist(void)
{
    if (gContestFinalStandings[gContestPlayerMonIndex] == 0
     && gSpecialVar_ContestRank == CONTEST_RANK_MASTER
     && gContestMonTotalPoints[gContestPlayerMonIndex] >= 800)
    {
        gSpecialVar_0x8004 = TRUE;
    }
    else
    {
        gSpecialVar_0x8004 = FALSE;
    }
}

u8 CountPlayerContestPaintings(void)
{
    int i;
    u8 count = 0;

    for (i = 0; i < 5; i++)
    {
        if (gSaveBlock1Ptr->contestWinners[8 + i].species)
            count++;
    }

    return count;
}

// Unused
void sub_80F8970(void)
{
    s16 conditions[CONTESTANT_COUNT];
    int i, j;
    s16 condition;
    s8 var0;
    u8 var2;
    u8 r8;
    u8 r7;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        conditions[i] = gContestMonConditions[i];

    for (i = 0; i < CONTESTANT_COUNT - 1; i++)
    {
        for (j = CONTESTANT_COUNT - 1; j > i; j--)
        {
            if (conditions[j - 1] < conditions[j])
            {
                int temp;
                SWAP(conditions[j], conditions[j - 1], temp)
            }
        }
    }

    condition = conditions[gSpecialVar_0x8006];
    var0 = 0;
    r8 = 0;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (conditions[i] == condition)
        {
            var0++;
            if (i == gSpecialVar_0x8006)
                r8 = var0;
        }
    }

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (conditions[i] == condition)
            break;
    }

    r7 = i;
    var2 = r8;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (condition == gContestMonConditions[i])
        {
            if (var2 == 1)
                break;
            var2--;
        }
    }

    StringCopy(gStringVar1, gContestMons[i].nickname);
    StringCopy(gStringVar2, gContestMons[i].trainerName);
    sub_81DB5AC(gStringVar2);

    if (var0 == 1)
        gSpecialVar_0x8006 = r7;
    else if (r8 == var0)
        gSpecialVar_0x8006 = r7;
    else
        gSpecialVar_0x8006 = r7 + 4;
}

static void ShowContestWinnerCleanup(void)
{
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ShowContestWinner(void)
{
    /*
    if(gUnknown_0203856C)
    {
        sub_80AAF30();
        gBattleStruct->unk15DDF = 1;
        gBattleStruct->unk15DDE = sub_80B2C4C(254, 0);
        Contest_SaveWinner(3);
        gUnknown_0203856C = 0;
    }
    */

    SetMainCallback2(CB2_ContestPainting);
    gMain.savedCallback = ShowContestWinnerCleanup;
}

void SetLinkContestPlayerGfx(void)
{
    int i;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            int version = (u8)gLinkPlayers[i].version;
            if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[i].gender == MALE)
                    gContestMons[i].trainerGfxId = OBJ_EVENT_GFX_LINK_RS_BRENDAN;
                else
                    gContestMons[i].trainerGfxId = OBJ_EVENT_GFX_LINK_RS_MAY;
            }
        }

        VarSet(VAR_OBJ_GFX_ID_0, gContestMons[0].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_1, gContestMons[1].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_2, gContestMons[2].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_3, gContestMons[3].trainerGfxId);
    }
}

void LoadLinkContestPlayerPalettes(void)
{
    int i;
    u8 objectEventId;
    int version;
    struct Sprite *sprite;

    gReservedSpritePaletteCount = 12;
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            objectEventId = GetObjectEventIdByLocalIdAndMap(gUnknown_0858D8EC[i], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            sprite = &gSprites[gObjectEvents[objectEventId].spriteId];
            sprite->oam.paletteNum = 6 + i;
            version = (u8)gLinkPlayers[i].version;
            if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[i].gender == MALE)
                    LoadPalette(gObjectEventPalette33, 0x160 + i * 0x10, 0x20);
                else
                    LoadPalette(gObjectEventPalette34, 0x160 + i * 0x10, 0x20);
            }
            else
            {
                if (gLinkPlayers[i].gender == MALE)
                    LoadPalette(gObjectEventPalette8, 0x160 + i * 0x10, 0x20);
                else
                    LoadPalette(gObjectEventPalette17, 0x160 + i * 0x10, 0x20);
            }
        }
    }
}

u8 GiveMonArtistRibbon(void)
{
    u8 hasArtistRibbon;

    hasArtistRibbon = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_ARTIST_RIBBON);
    if (!hasArtistRibbon 
        && gContestFinalStandings[gContestPlayerMonIndex] == 0 
        && gSpecialVar_ContestRank == CONTEST_RANK_MASTER
        && gContestMonTotalPoints[gContestPlayerMonIndex] >= 800)
    {
        hasArtistRibbon = 1;
        SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_ARTIST_RIBBON, &hasArtistRibbon);
        if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
            TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_ARTIST_RIBBON);

        return 1;
    }
    else
    {
        return 0;
    }
}

bool8 IsContestDebugActive(void)
{
    return FALSE; // gUnknown_0203856C in pokeruby
}

void ShowContestEntryMonPic(void)
{
    const struct CompressedSpritePalette *palette;
    u32 personality, otId;
    u16 species;
    u8 spriteId;
    u8 taskId;
    u8 left, top;

    if (FindTaskIdByFunc(Task_ShowContestEntryMonPic) == 0xFF)
    {
        AllocateMonSpritesGfx();
        left = 10;
        top = 3;
        species = gContestMons[gSpecialVar_0x8006].species;
        personality = gContestMons[gSpecialVar_0x8006].personality;
        otId = gContestMons[gSpecialVar_0x8006].otId;
        taskId = CreateTask(Task_ShowContestEntryMonPic, 0x50);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = species;
        if (gSpecialVar_0x8006 == gContestPlayerMonIndex)
            HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);
        else
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);

        palette = GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
        LoadCompressedSpritePalette(palette);
        SetMultiuseSpriteTemplateToPokemon(species, 1);
        gMultiuseSpriteTemplate.paletteTag = palette->tag;
        spriteId = CreateSprite(&gMultiuseSpriteTemplate, (left + 1) * 8 + 32, (top * 8) + 40, 0);

        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            if (!(gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER))
                DoMonFrontSpriteAnimation(&gSprites[spriteId], species, FALSE, 0);
        }
        else
        {
            DoMonFrontSpriteAnimation(&gSprites[spriteId], species, FALSE, 0);
        }

        gTasks[taskId].data[2] = spriteId;
        gTasks[taskId].data[3] = left;
        gTasks[taskId].data[4] = top;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
    }
}

void HideContestEntryMonPic(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ShowContestEntryMonPic);
    if (taskId != 0xFF)
    {
        gTasks[taskId].data[0]++;
        FreeMonSpritesGfx();
    }
}

static void Task_ShowContestEntryMonPic(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Sprite *sprite;

    switch(task->data[0])
    {
    case 0:
        task->data[0]++;
        break;
    case 1:
        task->data[5] = CreateWindowFromRect(10, 3, 8, 8);
        SetStandardWindowBorderStyle(task->data[5], 1);
        task->data[0]++;
        break;
    case 2:
        break;
    case 3:
        sprite = &gSprites[task->data[2]];
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));

        if(sprite->oam.affineMode)
            FreeOamMatrix(sprite->oam.matrixNum);

        DestroySprite(sprite);
        task->data[0]++;
        break;
    case 4:
        ClearToTransparentAndRemoveWindow(gTasks[taskId].data[5]);
        DestroyTask(taskId);
        break;
    }
}

void ScriptGetMultiplayerId(void)
{
    if ((gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK) 
        && gNumLinkContestPlayers == CONTESTANT_COUNT 
        && !(gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS))
        gSpecialVar_Result = GetMultiplayerId();
    else
        gSpecialVar_Result = MAX_LINK_PLAYERS;
}

void ScriptRandom(void)
{
    u16 random;
    u16 *scriptPtr;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        gContestRngValue = ISO_RANDOMIZE1(gContestRngValue);
        random = gContestRngValue >> 16;
        scriptPtr = &gSpecialVar_Result;
    }
    else
    {
        scriptPtr = &gSpecialVar_Result;
        random = Random();
    }
    *scriptPtr = random % *scriptPtr;
}

u16 GetContestRand(void)
{
    gContestRngValue = ISO_RANDOMIZE1(gContestRngValue);
    return gContestRngValue >> 16;
}

bool8 LinkContestWaitForConnection(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        CreateTask(Task_LinkContestWaitForConnection, 5);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Task_LinkContestWaitForConnection(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            sub_800ADF8();
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        gTasks[taskId].data[0]++;
        break;
    default:
        if (IsLinkTaskFinished() == 1)
        {
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
        break;
    }
}

void LinkContestTryShowWirelessIndicator(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        if (gReceivedRemoteLinkPlayers)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(8, 8);
        }
    }
}

void LinkContestTryHideWirelessIndicator(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        if (gReceivedRemoteLinkPlayers)
            DestroyWirelessStatusIndicatorSprite();
    }
}

bool8 IsContestWithRSPlayer(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
        return TRUE;
    else
        return FALSE;
}

void ClearLinkContestFlags(void)
{
    gLinkContestFlags = 0;
}

bool8 IsWirelessContest(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        return TRUE;
    else
        return FALSE;
}

void HealPlayerParty(void)
{
    u8 i, j;
    u8 ppBonuses;
    u8 arg[4];

    // restore HP.
    for(i = 0; i < gPlayerPartyCount; i++)
    {
        u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        // restore PP.
        for(j = 0; j < MAX_MON_MOVES; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        // since status is u32, the four 0 assignments here are probably for safety to prevent undefined data from reaching SetMonData.
        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);
    }
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;

    CreateMon(&mon, species, level, 32, 0, 0, OT_ID_PLAYER_ID, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = SpeciesToNationalPokedexNum(species);

    switch(sentToPc)
    {
    case 0:
    case 1:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    }
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    CreateMon(&gEnemyParty[0], species, level, 32, 0, 0, OT_ID_PLAYER_ID, 0);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
    if (monIndex > PARTY_SIZE)
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleFrontierParty;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

static void CB2_ReturnFromChooseBattleFrontierParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected pokemon according to the order.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}
