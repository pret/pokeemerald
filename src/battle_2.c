#include "global.h"
#include "battle.h"
#include "recorded_battle.h"
#include "main.h"
#include "load_save.h"
#include "gpu_regs.h"
#include "unknown_task.h"
#include "battle_setup.h"
#include "pokemon.h"
#include "palette.h"
#include "task.h"
#include "event_data.h"
#include "species.h"
#include "berry.h"
#include "text.h"
#include "item.h"
#include "items.h"
#include "hold_effects.h"
#include "link.h"
#include "bg.h"
#include "dma3.h"
#include "string_util.h"
#include "malloc.h"
#include "event_data.h"
#include "m4a.h"
#include "window.h"
#include "rng.h"
#include "songs.h"
#include "sound.h"
#include "battle_message.h"
#include "sprite.h"
#include "util.h"
#include "trig.h"
#include "battle_ai_script_commands.h"
#include "battle_move_effects.h"
#include "battle_controllers.h"
#include "pokedex.h"
#include "abilities.h"
#include "moves.h"
#include "trainer_classes.h"
#include "evolution_scene.h"
#include "roamer.h"
#include "safari_zone.h"
#include "battle_string_ids.h"

struct UnknownStruct6
{
    u16 unk0[0xA0];
    u8 fillerA0[0x640];
    u16 unk780[0xA0];
};

struct UnknownPokemonStruct2
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 heldItem;
    /*0x04*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0F*/ u8 level;
    /*0x10*/ u16 hp;
    /*0x12*/ u16 maxhp;
    /*0x14*/ u32 status;
    /*0x18*/ u32 personality;
    /*0x1C*/ u8 gender;
    /*0x1D*/ u8 language;
};

extern u32 gBattleTypeFlags;
extern u8 gBattleCommunication[];
extern u8 gBattleTerrain;
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u16 gPartnerTrainerId;
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern struct BattleEnigmaBerry gEnigmaBerries[BATTLE_BANKS_COUNT];
extern void (*gPreBattleCallback1)(void);
extern void (*gBattleMainFunc)(void);
extern void (*gUnknown_030061E8)(void);
extern struct UnknownPokemonStruct2 gUnknown_02022FF8[3]; // what is it used for?
extern struct UnknownPokemonStruct2* gUnknown_02023058; // what is it used for?
extern u8 gBattleOutcome;
extern u8 gUnknown_02039B28[]; // possibly a struct?
extern struct UnknownStruct6 gUnknown_02038C28; // todo: identify & document
extern struct MusicPlayerInfo gMPlay_SE1;
extern struct MusicPlayerInfo gMPlay_SE2;
extern u8 gDecompressionBuffer[];
extern u16 gUnknown_020243FC;
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u8 gStringBank;
extern u32 gUnknown_02022F88;
extern u32 gHitMarker;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u16 gPaydayMoney;
extern u16 gBattleWeather;
extern u16 gPauseCounterBattle;
extern u16 gRandomTurnNumber;
extern u8 gActiveBank;
extern u8 gNoOfAllBanks;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gLeveledUpInBattle;
extern u8 gAbsentBankFlags;
extern u32 gBattleExecBuffer;
extern u8 gMultiHitCounter;
extern u8 gBattleMoveFlags;
extern s32 gBattleMoveDamage;
extern const u8* gUnknown_02024230[BATTLE_BANKS_COUNT];
extern u16 gUnknownMovesUsedByBanks[BATTLE_BANKS_COUNT];
extern u16 gLastUsedMovesByBanks[BATTLE_BANKS_COUNT];
extern u16 gUnknown_02024250[BATTLE_BANKS_COUNT];
extern u16 gUnknown_02024258[BATTLE_BANKS_COUNT];
extern u16 gUnknown_02024260[BATTLE_BANKS_COUNT];
extern u16 gLockedMoves[BATTLE_BANKS_COUNT];
extern u8 gUnknown_02024270[BATTLE_BANKS_COUNT];
extern u8 gUnknown_02024284[BATTLE_BANKS_COUNT];
extern u32 gStatuses3[BATTLE_BANKS_COUNT];
extern u16 gSideAffecting[2];
extern u16 gCurrentMove;
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gMoveSelectionCursor[BATTLE_BANKS_COUNT];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u8 gBanksByTurnOrder[BATTLE_BANKS_COUNT];
extern u8 gActionForBanks[BATTLE_BANKS_COUNT];
extern u16 gChosenMovesByBanks[BATTLE_BANKS_COUNT];
extern u8 gCurrentActionFuncId;
extern u8 gLastUsedAbility;
extern u16 gLastUsedItem;
extern u8 gUnknown_0203CF00[];
extern const u8* gBattlescriptPtrsForSelection[BATTLE_BANKS_COUNT];
extern const u8* gBattlescriptCurrInstr;
extern u32 gBattlePalaceMoveSelectionRngValue;
extern u8 gActionsByTurnOrder[BATTLE_BANKS_COUNT];
extern u8 gCurrentTurnActionNumber;
extern u16 gDynamicBasePower;
extern u8 gCritMultiplier;
extern u8 gCurrMovePos;
extern u8 gUnknown_020241E9;
extern u16 gLastUsedMove;

extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
extern const struct BattleMove gBattleMoves[];
extern const u16 gUnknown_08C004E0[]; // battle textbox palette
extern const struct BgTemplate gUnknown_0831AA08[];
extern const struct WindowTemplate * const gUnknown_0831ABA0[];
extern const u8 gUnknown_0831ACE0[];
extern const u8 gStatStageRatios[][2];
extern const u8 * const gBattleScriptsForMoveEffects[];
extern const u8 * const gBattlescriptsForBallThrow[];
extern const u8 * const gBattlescriptsForRunningByItem[];
extern const u8 * const gUnknown_082DBD3C[];
extern const u8 * const gBattlescriptsForSafariActions[];

// strings
extern const u8 gText_LinkStandby3[];
extern const u8 gText_RecordBattleToPass[];
extern const u8 gText_BattleYesNoChoice[];
extern const u8 gText_BattleRecordCouldntBeSaved[];
extern const u8 gText_BattleRecordedOnPass[];
extern const u8 gText_ShedinjaJapaneseName[];
extern const u8 gText_EmptyString3[];
extern const u8 gText_Poison[];
extern const u8 gText_Sleep[];
extern const u8 gText_Paralysis[];
extern const u8 gText_Burn[];
extern const u8 gText_Ice[];
extern const u8 gText_Confusion[];
extern const u8 gText_Love[];

// battlescripts
extern const u8 gUnknown_082DB8BE[];
extern const u8 gUnknown_082DB881[];
extern const u8 BattleScript_ActionSelectionItemsCantBeUsed[];
extern const u8 gUnknown_082DAB11[];
extern const u8 gUnknown_082DB9BA[];
extern const u8 gUnknown_082DAAFE[];
extern const u8 gUnknown_082DAB0B[];
extern const u8 BattleScript_FocusPunchSetUp[];
extern const u8 BattleScript_LinkBattleWonOrLost[];
extern const u8 BattleScript_FrontierTrainerBattleWon[];
extern const u8 BattleScript_LocalTrainerBattleWon[];
extern const u8 BattleScript_PayDayMoneyAndPickUpItems[];
extern const u8 BattleScript_LocalBattleLost[];
extern const u8 gUnknown_082DB9C8[];
extern const u8 gUnknown_082DAA0B[];
extern const u8 gUnknown_082DB9C1[];
extern const u8 BattleScript_RanAwayUsingMonAbility[];
extern const u8 BattleScript_SmokeBallEscape[];
extern const u8 BattleScript_GotAwaySafely[];
extern const u8 BattleScript_WildMonFled[];
extern const u8 BattleScript_MoveUsedLoafingAround[];
extern const u8 BattleScript_ActionSwitch[];
extern const u8 BattleScript_PrintFailedToRunString[];

// functions
extern void HandleLinkBattleSetup(void); // rom_3
extern void SetUpBattleVarsAndBirchZigzagoon(void); // rom_3
extern void sub_8032768(void); // rom_3
extern void dp12_8087EA4(void);
extern void sub_80356D0(void);
extern void GetFrontierTrainerName(u8* dst, u16 trainerId); // battle tower
extern void sub_8166188(void); // battle tower, sets link battle mons level but why?
extern void sub_8165B88(u8* dst, u16 trainerId); // battle tower, gets language
extern void sub_81DB4DC(u8* dst, u8 arg2); //
extern void sub_81B9150(void);
extern void sub_800AC34(void);
extern void sub_80B3AF8(u8 taskId); // cable club
extern void sub_8076918(u8 bank);
extern void sub_80729D0(u8 healthoxSpriteId);
extern void sub_81A56B4(void); // battle frontier 2
extern u8 sub_81A9E28(void); // battle frontier 2
extern void sub_81A56E8(u8 bank); // battle frontier 2
extern void sub_81B8FB0(u8, u8); // party menu
extern u8 pokemon_order_func(u8); // party menu
extern void sub_80EC728(void); // tv
extern void sub_80EE184(void); // tv
extern bool8 InBattlePyramid(void);

// this file's functions
static void CB2_InitBattleInternal(void);
static void CB2_PreInitMultiBattle(void);
static void CB2_PreInitIngamePlayerPartnerBattle(void);
static void CB2_HandleStartMultiPartnerBattle(void);
static void CB2_HandleStartMultiBattle(void);
static void CB2_HandleStartBattle(void);
static void TryCorrectShedinjaLanguage(struct Pokemon *mon);
static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer);
static void BattleMainCB1(void);
static void sub_8038538(struct Sprite *sprite);
static void sub_8038F14(void);
static void sub_8038F34(void);
static void sub_80392A8(void);
static void sub_803937C(void);
static void sub_803939C(void);
static void oac_poke_opponent(struct Sprite *sprite);
static void sub_803980C(struct Sprite *sprite);
static void sub_8039838(struct Sprite *sprite);
static void sub_8039894(struct Sprite *sprite);
static void sub_80398D0(struct Sprite *sprite);
static void sub_8039A48(struct Sprite *sprite);
static void sub_8039AF4(struct Sprite *sprite);
static void SpriteCallbackDummy_3(struct Sprite *sprite);
static void oac_poke_ally_(struct Sprite *sprite);
static void SpecialStatusesClear(void);
static void TurnValuesCleanUp(bool8 var0);
static void SpriteCB_HealthBoxBounce(struct Sprite *sprite);
static void BattleStartClearSetData(void);
static void BattleIntroGetMonsData(void);
static void BattleIntroPrepareBackgroundSlide(void);
static void BattleIntroDrawTrainersOrMonsSprites(void);
static void BattleIntroDrawPartySummaryScreens(void);
static void BattleIntroPrintTrainerWantsToBattle(void);
static void BattleIntroPrintWildMonAttacked(void);
static void BattleIntroPrintOpponentSendsOut(void);
static void BattleIntroPrintPlayerSendsOut(void);
static void BattleIntroOpponent1SendsOutMonAnimation(void);
static void BattleIntroOpponent2SendsOutMonAnimation(void);
static void BattleIntroRecordMonsToDex(void);
static void BattleIntroPlayer1SendsOutMonAnimation(void);
static void TryDoEventsBeforeFirstTurn(void);
static void HandleTurnActionSelectionState(void);
static void RunTurnActionsFunctions(void);
static void SetActionsAndBanksTurnOrder(void);
static void sub_803CDF8(void);
static bool8 sub_803CDB8(void);
static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void);
static void FreeResetData_ReturnToOvOrDoEvolutions(void);
static void ReturnFromBattleToOverworld(void);
static void TryEvolvePokemon(void);
static void WaitForEvoSceneToFinish(void);
static void HandleEndTurn_ContinueBattle(void);
static void HandleEndTurn_BattleWon(void);
static void HandleEndTurn_BattleLost(void);
static void HandleEndTurn_RanFromBattle(void);
static void HandleEndTurn_MonFled(void);
static void HandleEndTurn_FinishBattle(void);
static void HandleAction_UseMove(void);
static void HandleAction_Switch(void);
static void HandleAction_UseItem(void);
static void HandleAction_Run(void);
static void HandleAction_WatchesCarefully(void);
static void HandleAction_SafariZoneBallThrow(void);
static void HandleAction_ThrowPokeblock(void);
static void HandleAction_GoNear(void);
static void HandleAction_SafriZoneRun(void);
static void HandleAction_Action9(void);
static void HandleAction_Action11(void);
static void HandleAction_NothingIsFainted(void);
static void HandleAction_ActionFinished(void);

// rom const data
static void (* const sTurnActionsFuncsTable[])(void) =
{
    HandleAction_UseMove,               // ACTION_USE_MOVE
    HandleAction_UseItem,               // ACTION_USE_ITEM
    HandleAction_Switch,                // ACTION_SWITCH
    HandleAction_Run,                   // ACTION_RUN
    HandleAction_WatchesCarefully,      // ACTION_WATCHES_CAREFULLY
    HandleAction_SafariZoneBallThrow,   // ACTION_SAFARI_ZONE_BALL
    HandleAction_ThrowPokeblock,        // ACTION_POKEBLOCK_CASE
    HandleAction_GoNear,                // ACTION_GO_NEAR
    HandleAction_SafriZoneRun,          // ACTION_SAFARI_ZONE_RUN
    HandleAction_Action9,               // ACTION_9
    HandleAction_RunBattleScript,       // ACTION_RUN_BATTLESCRIPT
    HandleAction_Action11,              // not sure about this one
    HandleAction_ActionFinished,        // ACTION_FINISHED
    HandleAction_NothingIsFainted,      // ACTION_NOTHING_FAINTED
};

static void (* const sEndTurnFuncsTable[])(void) =
{
    HandleEndTurn_ContinueBattle,       // battle outcome 0
    HandleEndTurn_BattleWon,            // BATTLE_WON
    HandleEndTurn_BattleLost,           // BATTLE_LOST
    HandleEndTurn_BattleLost,           // BATTLE_DREW
    HandleEndTurn_RanFromBattle,        // BATTLE_RAN
    HandleEndTurn_FinishBattle,         // BATTLE_PLAYER_TELEPORTED
    HandleEndTurn_MonFled,              // BATTLE_POKE_FLED
    HandleEndTurn_FinishBattle,         // BATTLE_CAUGHT
    HandleEndTurn_FinishBattle,         // battle outcome 8
    HandleEndTurn_FinishBattle,         // BATTLE_FORFEITED
    HandleEndTurn_FinishBattle,         // BATTLE_OPPONENT_TELEPORTED
};

const u8 gStatusConditionString_PoisonJpn[8] = _("どく$$$$$");
const u8 gStatusConditionString_SleepJpn[8] = _("ねむり$$$$");
const u8 gStatusConditionString_ParalysisJpn[8] = _("まひ$$$$$");
const u8 gStatusConditionString_BurnJpn[8] = _("やけど$$$$");
const u8 gStatusConditionString_IceJpn[8] = _("こおり$$$$");
const u8 gStatusConditionString_ConfusionJpn[8] = _("こんらん$$$");
const u8 gStatusConditionString_LoveJpn[8] = _("メロメロ$$$");

const u8 * const gStatusConditionStringsTable[7][2] =
{
    {gStatusConditionString_PoisonJpn, gText_Poison},
    {gStatusConditionString_SleepJpn, gText_Sleep},
    {gStatusConditionString_ParalysisJpn, gText_Paralysis},
    {gStatusConditionString_BurnJpn, gText_Burn},
    {gStatusConditionString_IceJpn, gText_Ice},
    {gStatusConditionString_ConfusionJpn, gText_Confusion},
    {gStatusConditionString_LoveJpn, gText_Love}
};

static const u8 sUnknown_0831BCE0[][3] = {{0, 0, 0}, {3, 5, 0}, {2, 3, 0}, {1, 2, 0}, {1, 1, 0}};
static const u8 sUnknown_0831BCEF[] = {4, 3, 2, 1};
static const u8 sUnknown_0831BCF3[] = {4, 4, 4, 4};

void CB2_InitBattle(void)
{
    MoveSaveBlocks_ResetHeap();
    AllocateBattleResrouces();
    AllocateBattleSpritesData();
    AllocateMonSpritesGfx();
    sub_8185F84();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            CB2_InitBattleInternal();
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            HandleLinkBattleSetup();
            SetMainCallback2(CB2_PreInitMultiBattle);
        }
        else
        {
            SetMainCallback2(CB2_PreInitIngamePlayerPartnerBattle);
        }
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
    else
    {
        CB2_InitBattleInternal();
    }
}

static void CB2_InitBattleInternal(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);

    CpuFill32(0, (void*)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 240);
    SetGpuReg(REG_OFFSET_WIN0V, 0x5051);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    gBattle_WIN0H = 240;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId != STEVEN_PARTNER_ID)
    {
        gBattle_WIN0V = 159;
        gBattle_WIN1H = 240;
        gBattle_WIN1V = 32;
    }
    else
    {
        gBattle_WIN0V = 0x5051;
        dp12_8087EA4();

        for (i = 0; i < 80; i++)
        {
            gUnknown_02038C28.unk0[i] = 0xF0;
            gUnknown_02038C28.unk780[i] = 0xF0;
        }
        for (i = 80; i < 160; i++)
        {
            #ifndef NONMATCHING
                asm(""::"r"(i)); // needed to match
            #endif // NONMATCHING

            gUnknown_02038C28.unk0[i] = 0xFF10;
            gUnknown_02038C28.unk780[i] = 0xFF10;
        }

        sub_80BA038(gUnknown_0831AC70);
    }

    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;

    gBattleTerrain = BattleSetup_GetTerrainId();
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        gBattleTerrain = BATTLE_TERRAIN_INSIDE;

    sub_80356D0();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    LoadBattleEntryBackground();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;
    SetVBlankCallback(VBlankCB_Battle);
    SetUpBattleVarsAndBirchZigzagoon();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        SetMainCallback2(CB2_HandleStartMultiBattle);
    else
        SetMainCallback2(CB2_HandleStartBattle);

    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)))
    {
        CreateNPCTrainerParty(&gEnemyParty[0], gTrainerBattleOpponent_A, TRUE);
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            CreateNPCTrainerParty(&gEnemyParty[3], gTrainerBattleOpponent_B, FALSE);
        SetWildMonHeldItem();
    }

    gMain.inBattle = TRUE;
    gSaveBlock2Ptr->field_CA9_b = 0;

    for (i = 0; i < 6; i++)
        AdjustFriendship(&gPlayerParty[i], 3);

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

static void sub_8036A5C(void)
{
    u16 r6 = 0;
    u16 species = 0;
    u16 hp = 0;
    u32 status = 0;
    s32 i;

    for (i = 0; i < 6; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
        status = GetMonData(&gPlayerParty[i], MON_DATA_STATUS);

        if (species == SPECIES_NONE)
            continue;
        if (species != SPECIES_EGG && hp != 0 && status == 0)
            r6 |= 1 << i * 2;

        if (species == SPECIES_NONE)
            continue;
        if (hp != 0 && (species == SPECIES_EGG || status != 0))
            r6 |= 2 << i * 2;

        if (species == SPECIES_NONE)
            continue;
        if (species != SPECIES_EGG && hp == 0)
            r6 |= 3 << i * 2;
    }

    gBattleStruct->field_182 = r6;
    *(&gBattleStruct->field_183) = r6 >> 8;
    gBattleStruct->field_183 |= FlagGet(SYS_FRONTIER_PASS) << 7;
}

static void SetPlayerBerryDataInBattleStruct(void)
{
    s32 i;
    struct BattleStruct *battleStruct = gBattleStruct;
    struct BattleEnigmaBerry *battleBerry = &battleStruct->battleEnigmaBerry;

    if (IsEnigmaBerryValid() == TRUE)
    {
        for (i = 0; i < BERRY_NAME_COUNT - 1; i++)
            battleBerry->name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];

        battleBerry->holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        battleBerry->holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
    }
    else
    {
        const struct Berry* berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY));

        for (i = 0; i < BERRY_NAME_COUNT - 1; i++)
            battleBerry->name[i] = berryData->name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = 0;

        battleBerry->holdEffect = HOLD_EFFECT_NONE;
        battleBerry->holdEffectParam = 0;
    }
}

static void SetAllPlayersBerryData(void)
{
    s32 i;
    s32 j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        if (IsEnigmaBerryValid() == TRUE)
        {
            for (i = 0; i < BERRY_NAME_COUNT - 1; i++)
            {
                gEnigmaBerries[0].name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
                gEnigmaBerries[2].name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];
                gEnigmaBerries[2].itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];
            }

            gEnigmaBerries[0].holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            gEnigmaBerries[2].holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            gEnigmaBerries[0].holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
            gEnigmaBerries[2].holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
        }
        else
        {
            const struct Berry* berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY));

            for (i = 0; i < BERRY_NAME_COUNT - 1; i++)
            {
                gEnigmaBerries[0].name[i] = berryData->name[i];
                gEnigmaBerries[2].name[i] = berryData->name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = 0;
                gEnigmaBerries[2].itemEffect[i] = 0;
            }

            gEnigmaBerries[0].holdEffect = 0;
            gEnigmaBerries[2].holdEffect = 0;
            gEnigmaBerries[0].holdEffectParam = 0;
            gEnigmaBerries[2].holdEffectParam = 0;
        }
    }
    else
    {
        s32 numPlayers;
        struct BattleEnigmaBerry *src;
        u8 r4;

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = 4;

            for (i = 0; i < numPlayers; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);
                r4 = gLinkPlayers[i].lp_field_18;

                for (j = 0; j < BERRY_NAME_COUNT - 1; j++)
                    gEnigmaBerries[r4].name[j] = src->name[j];
                gEnigmaBerries[r4].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                    gEnigmaBerries[r4].itemEffect[j] = src->itemEffect[j];

                gEnigmaBerries[r4].holdEffect = src->holdEffect;
                gEnigmaBerries[r4].holdEffectParam = src->holdEffectParam;
            }
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);

                for (j = 0; j < BERRY_NAME_COUNT - 1; j++)
                {
                    gEnigmaBerries[i].name[j] = src->name[j];
                    gEnigmaBerries[i + 2].name[j] = src->name[j];
                }
                gEnigmaBerries[i].name[j] = EOS;
                gEnigmaBerries[i + 2].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                {
                    gEnigmaBerries[i].itemEffect[j] = src->itemEffect[j];
                    gEnigmaBerries[i + 2].itemEffect[j] = src->itemEffect[j];
                }

                gEnigmaBerries[i].holdEffect = src->holdEffect;
                gEnigmaBerries[i + 2].holdEffect = src->holdEffect;
                gEnigmaBerries[i].holdEffectParam = src->holdEffectParam;
                gEnigmaBerries[i + 2].holdEffectParam = src->holdEffectParam;
            }
        }
    }
}

static void sub_8036EB8(u8 arg0, u8 arg1)
{
    u8 var = 0;

    if (gBlockRecvBuffer[0][0] == 256)
    {
        if (arg1 == 0)
            gBattleTypeFlags |= BATTLE_TYPE_WILD | BATTLE_TYPE_TRAINER;
        else
            gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        var++;
    }

    if (var == 0)
    {
        s32 i;

        for (i = 0; i < arg0; i++)
        {
            if (gBlockRecvBuffer[0][0] != gBlockRecvBuffer[i][0])
                break;
        }

        if (i == arg0)
        {
            if (arg1 == 0)
                gBattleTypeFlags |= BATTLE_TYPE_WILD | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
            var++;
        }

        if (var == 0)
        {
            for (i = 0; i < arg0; i++)
            {
                if (gBlockRecvBuffer[i][0] == 0x300)
                {
                    if (i != arg1 && i < arg1)
                        break;
                }
                if (gBlockRecvBuffer[i][0] > 0x300 && i != arg1)
                    break;
            }

            if (i == arg0)
                gBattleTypeFlags |= BATTLE_TYPE_WILD | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        }
    }
}

static void CB2_HandleStartBattle(void)
{
    u8 playerMultiplayerId;
    u8 enemyMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    enemyMultiplayerId = playerMultiplayerId ^ BIT_SIDE;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            sub_805EF14();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gLinkVSyncDisabled)
            sub_800E0E8();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (sub_800A520())
                {
                    *(&gBattleStruct->field_180) = 0;
                    *(&gBattleStruct->field_181) = 3;
                    sub_8036A5C();
                    SetPlayerBerryDataInBattleStruct();

                    if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
                    {
                        gLinkPlayers[0].lp_field_18 = 0;
                        gLinkPlayers[1].lp_field_18 = 1;
                    }

                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->field_180, 32);
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }
                if (gLinkVSyncDisabled)
                    sub_800DFB4(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_WILD;
            gBattleCommunication[MULTIUSE_STATE] = 15;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            sub_8036EB8(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(task00_0800F6FC, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = gBattleStruct->field_182 | (gBattleStruct->field_183 << 8);
            gTasks[taskId].data[4] = gBlockRecvBuffer[enemyMultiplayerId][1];
            sub_8185F90(gBlockRecvBuffer[playerMultiplayerId][1]);
            sub_8185F90(gBlockRecvBuffer[enemyMultiplayerId][1]);
            sub_8068AA4();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty + 2, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 4, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty + 4, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            TryCorrectShedinjaLanguage(&gEnemyParty[0]);
            TryCorrectShedinjaLanguage(&gEnemyParty[1]);
            TryCorrectShedinjaLanguage(&gEnemyParty[2]);
            TryCorrectShedinjaLanguage(&gEnemyParty[3]);
            TryCorrectShedinjaLanguage(&gEnemyParty[4]);
            TryCorrectShedinjaLanguage(&gEnemyParty[5]);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        sub_8032768();
        sub_8184E58();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            s32 i;

            for (i = 0; i < 2 && (gLinkPlayers[i].version & 0xFF) == 3; i++);

            if (i == 2)
                gBattleCommunication[MULTIUSE_STATE] = 16;
            else
                gBattleCommunication[MULTIUSE_STATE] = 18;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 18;
        }
        break;
    case 16:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 17:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_WILD))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[enemyMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 18:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gBattleTypeFlags |= BATTLE_TYPE_20;
            }
        }
        break;
    case 5:
    case 9:
    case 13:
        gBattleCommunication[MULTIUSE_STATE]++;
        gBattleCommunication[1] = 1;
    case 6:
    case 10:
    case 14:
        if (--gBattleCommunication[1] == 0)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    }
}

static void CB2_HandleStartMultiPartnerBattle(void)
{
    u8 playerMultiplayerId;
    u8 enemyMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    enemyMultiplayerId = playerMultiplayerId ^ BIT_SIDE;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            sub_805EF14();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gLinkVSyncDisabled)
            sub_800E0E8();
        // fall through
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                u8 language;

                gLinkPlayers[0].lp_field_18 = 0;
                gLinkPlayers[1].lp_field_18 = 2;
                gLinkPlayers[2].lp_field_18 = 1;
                gLinkPlayers[3].lp_field_18 = 3;
                GetFrontierTrainerName(gLinkPlayers[2].name, gTrainerBattleOpponent_A);
                GetFrontierTrainerName(gLinkPlayers[3].name, gTrainerBattleOpponent_B);
                sub_8165B88(&language, gTrainerBattleOpponent_A);
                gLinkPlayers[2].language = language;
                sub_8165B88(&language, gTrainerBattleOpponent_B);
                gLinkPlayers[3].language = language;

                if (sub_800A520())
                {
                    *(&gBattleStruct->field_180) = 0;
                    *(&gBattleStruct->field_181) = 3;
                    sub_8036A5C();
                    SetPlayerBerryDataInBattleStruct();
                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->field_180, 32);
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }

                if (gLinkVSyncDisabled)
                    sub_800DFB4(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_WILD;
            gBattleCommunication[MULTIUSE_STATE] = 13;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            sub_8036EB8(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(task00_0800F6FC, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = 0x145;
            gTasks[taskId].data[4] = 0x145;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].lp_field_18 != 0)
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(gPlayerParty + 3, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            else
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(gPlayerParty + 3, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].lp_field_18 != 0)
            {
                memcpy(gPlayerParty + 2, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon));
                memcpy(gPlayerParty + 5, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
            }
            else
            {
                memcpy(gPlayerParty + 2, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
                memcpy(gPlayerParty + 5, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon));
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gEnemyParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
            {
                memcpy(gEnemyParty, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gEnemyParty + 2, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
            {
                memcpy(gEnemyParty + 2, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gEnemyParty + 4, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(gEnemyParty + 4, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            TryCorrectShedinjaLanguage(&gPlayerParty[0]);
            TryCorrectShedinjaLanguage(&gPlayerParty[1]);
            TryCorrectShedinjaLanguage(&gPlayerParty[2]);
            TryCorrectShedinjaLanguage(&gPlayerParty[3]);
            TryCorrectShedinjaLanguage(&gPlayerParty[4]);
            TryCorrectShedinjaLanguage(&gPlayerParty[5]);
            TryCorrectShedinjaLanguage(&gEnemyParty[0]);
            TryCorrectShedinjaLanguage(&gEnemyParty[1]);
            TryCorrectShedinjaLanguage(&gEnemyParty[2]);
            TryCorrectShedinjaLanguage(&gEnemyParty[3]);
            TryCorrectShedinjaLanguage(&gEnemyParty[4]);
            TryCorrectShedinjaLanguage(&gEnemyParty[5]);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 13:
        sub_8032768();
        sub_8184E58();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            gBattleCommunication[MULTIUSE_STATE] = 14;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 16;
        }
        break;
    case 14:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_WILD))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[enemyMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 16:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            sub_8166188();
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gBattleTypeFlags |= BATTLE_TYPE_20;
            }
        }
        break;
    }
}

static void sub_80379F8(u8 arrayIdPlus)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        gUnknown_02022FF8[i].species     = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_SPECIES);
        gUnknown_02022FF8[i].heldItem    = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_HELD_ITEM);
        GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_NICKNAME, gUnknown_02022FF8[i].nickname);
        gUnknown_02022FF8[i].level       = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_LEVEL);
        gUnknown_02022FF8[i].hp          = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_HP);
        gUnknown_02022FF8[i].maxhp       = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_MAX_HP);
        gUnknown_02022FF8[i].status      = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_STATUS);
        gUnknown_02022FF8[i].personality = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_PERSONALITY);
        gUnknown_02022FF8[i].gender      = GetMonGender(&gPlayerParty[arrayIdPlus + i]);
        StripExtCtrlCodes(gUnknown_02022FF8[i].nickname);
        if (GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
            sub_81DB4DC(gUnknown_02022FF8[i].nickname, 0);
    }
    memcpy(gUnknown_02023058, gUnknown_02022FF8, sizeof(gUnknown_02022FF8));
}

static void CB2_PreInitMultiBattle(void)
{
    s32 i;
    u8 playerMultiplierId;
    s32 numPlayers = 4;
    u8 r4 = 0xF;
    u32* savedBattleTypeFlags;
    void (**savedCallback)(void);

    if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        numPlayers = 2;
        r4 = 3;
    }

    playerMultiplierId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplierId;
    savedCallback = &gBattleStruct->savedCallback;
    savedBattleTypeFlags = &gBattleStruct->savedBattleTypeFlags;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (gReceivedRemoteLinkPlayers != 0 && sub_800A520())
        {
            gUnknown_02023058 = Alloc(sizeof(struct UnknownPokemonStruct2) * 3);
            sub_80379F8(0);
            SendBlock(bitmask_all_link_players_but_self(), gUnknown_02023058, sizeof(struct UnknownPokemonStruct2) * 3);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 1:
        if ((GetBlockReceivedStatus() & r4) == r4)
        {
            ResetBlockReceivedFlags();
            for (i = 0; i < numPlayers; i++)
            {
                if (i == playerMultiplierId)
                    continue;

                if (numPlayers == 4)
                {
                    if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[playerMultiplierId].lp_field_18 & 1))
                        || (gLinkPlayers[i].lp_field_18 & 1 && gLinkPlayers[playerMultiplierId].lp_field_18 & 1))
                    {
                        memcpy(gUnknown_02022FF8, gBlockRecvBuffer[i], sizeof(struct UnknownPokemonStruct2) * 3);
                    }
                }
                else
                {
                    memcpy(gUnknown_02022FF8, gBlockRecvBuffer[i], sizeof(struct UnknownPokemonStruct2) * 3);
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
            *savedCallback = gMain.savedCallback;
            *savedBattleTypeFlags = gBattleTypeFlags;
            gMain.savedCallback = CB2_PreInitMultiBattle;
            sub_81B9150();
        }
        break;
    case 2:
        if (sub_800A520() && !gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE]++;
            if (gLinkVSyncDisabled)
                sub_800ADF8();
            else
                sub_800AC34();
        }
        break;
    case 3:
        if (gLinkVSyncDisabled)
        {
            if (sub_8010500())
            {
                gBattleTypeFlags = *savedBattleTypeFlags;
                gMain.savedCallback = *savedCallback;
                SetMainCallback2(CB2_InitBattleInternal);
                Free(gUnknown_02023058);
                gUnknown_02023058 = NULL;
            }
        }
        else if (gReceivedRemoteLinkPlayers == 0)
        {
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            Free(gUnknown_02023058);
            gUnknown_02023058 = NULL;
        }
        break;
    }
}

static void CB2_PreInitIngamePlayerPartnerBattle(void)
{
    u32* savedBattleTypeFlags;
    void (**savedCallback)(void);

    savedCallback = &gBattleStruct->savedCallback;
    savedBattleTypeFlags = &gBattleStruct->savedBattleTypeFlags;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        gUnknown_02023058 = Alloc(sizeof(struct UnknownPokemonStruct2) * 3);
        sub_80379F8(3);
        gBattleCommunication[MULTIUSE_STATE]++;
        *savedCallback = gMain.savedCallback;
        *savedBattleTypeFlags = gBattleTypeFlags;
        gMain.savedCallback = CB2_PreInitIngamePlayerPartnerBattle;
        sub_81B9150();
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE] = 2;
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            Free(gUnknown_02023058);
            gUnknown_02023058 = NULL;
        }
        break;
    }
}

static void CB2_HandleStartMultiBattle(void)
{
    u8 playerMultiplayerId;
    s32 id;
    u8 var;

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            sub_805EF14();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gLinkVSyncDisabled)
            sub_800E0E8();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (sub_800A520())
                {
                    *(&gBattleStruct->field_180) = 0;
                    *(&gBattleStruct->field_181) = 3;
                    sub_8036A5C();
                    SetPlayerBerryDataInBattleStruct();

                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->field_180, 32);
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                if (gLinkVSyncDisabled)
                    sub_800DFB4(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_WILD;
            gBattleCommunication[MULTIUSE_STATE] = 7;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            sub_8036EB8(4, playerMultiplayerId);
            SetAllPlayersBerryData();
            sub_8068AA4();
            var = CreateTask(task00_0800F6FC, 0);
            gTasks[var].data[1] = 0x10E;
            gTasks[var].data[2] = 0x5A;
            gTasks[var].data[5] = 0;
            gTasks[var].data[3] = 0;
            gTasks[var].data[4] = 0;

            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                sub_8185F90(gBlockRecvBuffer[id][1]);
                switch (gLinkPlayers[id].lp_field_18)
                {
                case 0:
                    gTasks[var].data[3] |= gBlockRecvBuffer[id][1] & 0x3F;
                    break;
                case 1:
                    gTasks[var].data[4] |= gBlockRecvBuffer[id][1] & 0x3F;
                    break;
                case 2:
                    gTasks[var].data[3] |= (gBlockRecvBuffer[id][1] & 0x3F) << 6;
                    break;
                case 3:
                    gTasks[var].data[4] |= (gBlockRecvBuffer[id][1] & 0x3F) << 6;
                    break;
                }
            }
            ZeroEnemyPartyMons();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
            break;
        // fall through
    case 3:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                if (id == playerMultiplayerId)
                {
                    switch (gLinkPlayers[id].lp_field_18)
                    {
                    case 0:
                    case 3:
                        memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    case 1:
                    case 2:
                        memcpy(gPlayerParty + 3, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].lp_field_18 & 1) && !(gLinkPlayers[playerMultiplayerId].lp_field_18 & 1))
                     || ((gLinkPlayers[id].lp_field_18 & 1) && (gLinkPlayers[playerMultiplayerId].lp_field_18 & 1)))
                    {
                        switch (gLinkPlayers[id].lp_field_18)
                        {
                        case 0:
                        case 3:
                            memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gPlayerParty + 3, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].lp_field_18)
                        {
                        case 0:
                        case 3:
                            memcpy(gEnemyParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gEnemyParty + 3, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (sub_800A520())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                if (id == playerMultiplayerId)
                {
                    switch (gLinkPlayers[id].lp_field_18)
                    {
                    case 0:
                    case 3:
                        memcpy(gPlayerParty + 2, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                        break;
                    case 1:
                    case 2:
                        memcpy(gPlayerParty + 5, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].lp_field_18 & 1) && !(gLinkPlayers[playerMultiplayerId].lp_field_18 & 1))
                     || ((gLinkPlayers[id].lp_field_18 & 1) && (gLinkPlayers[playerMultiplayerId].lp_field_18 & 1)))
                    {
                        switch (gLinkPlayers[id].lp_field_18)
                        {
                        case 0:
                        case 3:
                            memcpy(gPlayerParty + 2, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        case 1:
                        case 2:
                            memcpy(gPlayerParty + 5, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].lp_field_18)
                        {
                        case 0:
                        case 3:
                            memcpy(gEnemyParty + 2, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        case 1:
                        case 2:
                            memcpy(gEnemyParty + 5, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        }
                    }
                }
            }
            TryCorrectShedinjaLanguage(&gPlayerParty[0]);
            TryCorrectShedinjaLanguage(&gPlayerParty[1]);
            TryCorrectShedinjaLanguage(&gPlayerParty[2]);
            TryCorrectShedinjaLanguage(&gPlayerParty[3]);
            TryCorrectShedinjaLanguage(&gPlayerParty[4]);
            TryCorrectShedinjaLanguage(&gPlayerParty[5]);

            TryCorrectShedinjaLanguage(&gEnemyParty[0]);
            TryCorrectShedinjaLanguage(&gEnemyParty[1]);
            TryCorrectShedinjaLanguage(&gEnemyParty[2]);
            TryCorrectShedinjaLanguage(&gEnemyParty[3]);
            TryCorrectShedinjaLanguage(&gEnemyParty[4]);
            TryCorrectShedinjaLanguage(&gEnemyParty[5]);

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        sub_8032768();
        sub_8184E58();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (id = 0; id < 4 && (gLinkPlayers[id].version & 0xFF) == 3; id++);

            if (id == 4)
                gBattleCommunication[MULTIUSE_STATE] = 8;
            else
                gBattleCommunication[MULTIUSE_STATE] = 10;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 10;
        }
        break;
    case 8:
        if (sub_800A520())
        {
            u32* ptr = (u32*)(&gBattleStruct->field_180);
            ptr[0] = gBattleTypeFlags;
            ptr[1] = gRecordedBattleRngSeed; // UB: overwrites berry data
            SendBlock(bitmask_all_link_players_but_self(), ptr, 8);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (var = 0; var < 4; var++)
            {
                u32 blockValue = gBlockRecvBuffer[var][0];
                if (blockValue & 4)
                {
                    memcpy(&gRecordedBattleRngSeed, &gBlockRecvBuffer[var][2], sizeof(gRecordedBattleRngSeed));
                    break;
                }
            }

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gTrainerBattleOpponent_A = TRAINER_OPPONENT_800;
                gBattleTypeFlags |= BATTLE_TYPE_20;
            }
        }
        break;
    }
}

void BattleMainCB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();

    if (gMain.heldKeys & B_BUTTON && gBattleTypeFlags & BATTLE_TYPE_RECORDED && sub_8186450())
    {
        gScriptResult = gBattleOutcome = BATTLE_PLAYER_TELEPORTED;
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        SetMainCallback2(CB2_QuitRecordedBattle);
    }
}

static void FreeRestoreBattleData(void)
{
    gMain.callback1 = gPreBattleCallback1;
    gUnknown_02039B28[0x15] = 3;
    gMain.inBattle = 0;
    ZeroEnemyPartyMons();
    m4aSongNumStop(0x5A);
    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
}

void CB2_QuitRecordedBattle(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        m4aMPlayStop(&gMPlay_SE1);
        m4aMPlayStop(&gMPlay_SE2);
        FreeRestoreBattleData();
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void sub_8038528(struct Sprite* sprite)
{
    sprite->data0 = 0;
    sprite->callback = sub_8038538;
}

static void sub_8038538(struct Sprite *sprite)
{
    u16 *arr = (u16*)(gDecompressionBuffer);

    switch (sprite->data0)
    {
    case 0:
        sprite->data0++;
        sprite->data1 = 0;
        sprite->data2 = 0x281;
        sprite->data3 = 0;
        sprite->data4 = 1;
        // fall through
    case 1:
        sprite->data4--;
        if (sprite->data4 == 0)
        {
            s32 i;
            s32 r2;
            s32 r0;

            sprite->data4 = 2;
            r2 = sprite->data1 + sprite->data3 * 32;
            r0 = sprite->data2 - sprite->data3 * 32;
            for (i = 0; i < 29; i += 2)
            {
                arr[r2 + i] = 0x3D;
                arr[r0 + i] = 0x3D;
            }
            sprite->data3++;
            if (sprite->data3 == 21)
            {
                sprite->data0++;
                sprite->data1 = 32;
            }
        }
        break;
    case 2:
        sprite->data1--;
        if (sprite->data1 == 20)
            SetMainCallback2(CB2_InitBattle);
        break;
    }
}

static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer)
{
    u32 nameHash = 0;
    u32 personalityValue;
    u8 fixedIV;
    s32 i, j;
    u8 monsCount;

    if (trainerNum == SECRET_BASE_OPPONENT)
        return 0;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER
                                                                        | BATTLE_TYPE_EREADER_TRAINER
                                                                        | BATTLE_TYPE_x4000000)))
    {
        if (firstTrainer == TRUE)
            ZeroEnemyPartyMons();

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (gTrainers[trainerNum].partySize > 3)
                monsCount = 3;
            else
                monsCount = gTrainers[trainerNum].partySize;
        }
        else
        {
            monsCount = gTrainers[trainerNum].partySize;
        }

        for (i = 0; i < monsCount; i++)
        {

            if (gTrainers[trainerNum].doubleBattle == TRUE)
                personalityValue = 0x80;
            else if (gTrainers[trainerNum].encounterMusic_gender & 0x80)
                personalityValue = 0x78;
            else
                personalityValue = 0x88;

            for (j = 0; gTrainers[trainerNum].trainerName[j] != 0xFF; j++)
                nameHash += gTrainers[trainerNum].trainerName[j];

            switch (gTrainers[trainerNum].partyFlags)
            {
            case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *partyData = gTrainers[trainerNum].party.NoItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != 0xFF; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
                break;
            }
            case PARTY_FLAG_CUSTOM_MOVES:
            {
                const struct TrainerMonNoItemCustomMoves *partyData = gTrainers[trainerNum].party.NoItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != 0xFF; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, 2, 0);

                for (j = 0; j < 4; j++)
                {
                    SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            case PARTY_FLAG_HAS_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *partyData = gTrainers[trainerNum].party.ItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != 0xFF; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, 2, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);
                break;
            }
            case PARTY_FLAG_CUSTOM_MOVES | PARTY_FLAG_HAS_ITEM:
            {
                const struct TrainerMonItemCustomMoves *partyData = gTrainers[trainerNum].party.ItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != 0xFF; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, 2, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

                for (j = 0; j < 4; j++)
                {
                    SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            }
        }

        gBattleTypeFlags |= gTrainers[trainerNum].doubleBattle;
    }

    return gTrainers[trainerNum].partySize;
}

void sub_8038A04(void) // unused
{
    if (REG_VCOUNT < 0xA0 && REG_VCOUNT >= 0x6F)
        SetGpuReg(REG_OFFSET_BG0CNT, 0x9800);
}

void VBlankCB_Battle(void)
{
    // change gRngSeed every vblank unless the battle could be recorded
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_RECORDED)))
        Random();

    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_80BA0A8();
}

void nullsub_17(void)
{

}

static void sub_8038B04(struct Sprite *sprite)
{
    if (sprite->data0 != 0)
        sprite->pos1.x = sprite->data1 + ((sprite->data2 & 0xFF00) >> 8);
    else
        sprite->pos1.x = sprite->data1 - ((sprite->data2 & 0xFF00) >> 8);

    sprite->data2 += 0x180;

    if (sprite->affineAnimEnded)
    {
        FreeSpriteTilesByTag(0x2710);
        FreeSpritePaletteByTag(0x2710);
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void sub_8038B74(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->callback = sub_8038B04;
    PlaySE(SE_BT_START);
}

static void sub_8038B94(u8 taskId)
{
    struct Pokemon *sp4 = NULL;
    struct Pokemon *sp8 = NULL;
    u8 r2 = gBattleScripting.multiplayerId;
    u32 r7;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        switch (gLinkPlayers[r2].lp_field_18)
        {
        case 0:
        case 2:
            sp4 = gPlayerParty;
            sp8 = gEnemyParty;
            break;
        case 1:
        case 3:
            sp4 = gEnemyParty;
            sp8 = gPlayerParty;
            break;
        }
    }
    else
    {
        sp4 = gPlayerParty;
        sp8 = gEnemyParty;
    }

    r7 = 0;
    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&sp4[i], MON_DATA_SPECIES2);
        u16 hp = GetMonData(&sp4[i], MON_DATA_HP);
        u32 status = GetMonData(&sp4[i], MON_DATA_STATUS);

        if (species == SPECIES_NONE)
            continue;
        if (species != SPECIES_EGG && hp != 0 && status == 0)
            r7 |= 1 << i * 2;

        if (species == 0)
            continue;
        if (hp != 0 && (species == SPECIES_EGG || status != 0))
            r7 |= 2 << i * 2;

        if (species == 0)
            continue;
        if (species != SPECIES_EGG && hp == 0)
            r7 |= 3 << i * 2;
    }
    gTasks[taskId].data[3] = r7;

    r7 = 0;
    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&sp8[i], MON_DATA_SPECIES2);
        u16 hp = GetMonData(&sp8[i], MON_DATA_HP);
        u32 status = GetMonData(&sp8[i], MON_DATA_STATUS);

        if (species == SPECIES_NONE)
            continue;
        if (species != SPECIES_EGG && hp != 0 && status == 0)
            r7 |= 1 << i * 2;

        if (species == SPECIES_NONE)
            continue;
        if (hp != 0 && (species == SPECIES_EGG || status != 0))
            r7 |= 2 << i * 2;

        if (species == SPECIES_NONE)
            continue;
        if (species != SPECIES_EGG && hp == 0)
            r7 |= 3 << i * 2;
    }
    gTasks[taskId].data[4] = r7;
}

void sub_8038D64(void)
{
    s32 i;
    u8 taskId;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    gBattleTypeFlags &= ~(BATTLE_TYPE_20);

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        SetMainCallback2(gMain.savedCallback);
        FreeBattleResources();
        FreeBattleSpritesData();
        FreeMonSpritesGfx();
    }
    else
    {
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
        SetGpuReg(REG_OFFSET_WIN0V, 0x5051);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gBattle_WIN0H = 0xF0;
        gBattle_WIN0V = 0x5051;
        dp12_8087EA4();

        for (i = 0; i < 80; i++)
        {
            gUnknown_02038C28.unk0[i] = 0xF0;
            gUnknown_02038C28.unk780[i] = 0xF0;
        }
        for (i = 80; i < 160; i++)
        {
            asm(""::"r"(i));  // Needed to stop the compiler from optimizing out the loop counter
            gUnknown_02038C28.unk0[i] = 0xFF10;
            gUnknown_02038C28.unk780[i] = 0xFF10;
        }

        ResetPaletteFade();

        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;

        sub_80356D0();
        LoadCompressedPalette(gUnknown_08C004E0, 0, 64);
        ApplyPlayerChosenFrameToBattleMenu();
        ResetSpriteData();
        ResetTasks();
        LoadBattleEntryBackground();
        SetGpuReg(REG_OFFSET_WINOUT, 0x37);
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        SetVBlankCallback(VBlankCB_Battle);

        taskId = CreateTask(task00_0800F6FC, 0);
        gTasks[taskId].data[1] = 0x10E;
        gTasks[taskId].data[2] = 0x5A;
        gTasks[taskId].data[5] = 1;
        sub_8038B94(taskId);
        SetMainCallback2(sub_8038F14);
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
}

static void sub_8038F14(void)
{
    sub_8038F34();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void sub_8038F34(void)
{
    s32 i;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[1] = 0xFF;
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (--gBattleCommunication[1] == 0)
        {
            BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            u8 monsCount;

            gMain.field_439_x4 = sub_8185FAC();

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                monsCount = 4;
            else
                monsCount = 2;

            for (i = 0; i < monsCount && (gLinkPlayers[i].version & 0xFF) == 3; i++);

            if (!gSaveBlock2Ptr->field_CA9_b && i == monsCount)
            {
                if (FlagGet(SYS_FRONTIER_PASS))
                {
                    FreeAllWindowBuffers();
                    SetMainCallback2(sub_80392A8);
                }
                else if (!gMain.field_439_x4)
                {
                    SetMainCallback2(gMain.savedCallback);
                    FreeBattleResources();
                    FreeBattleSpritesData();
                    FreeMonSpritesGfx();
                }
                else if (gReceivedRemoteLinkPlayers == 0)
                {
                    CreateTask(sub_80B3AF8, 5);
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                else
                {
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
            }
            else
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case 3:
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);

        for (i = 0; i < 2; i++)
            LoadChosenBattleElement(i);

        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 4:
        if (!gPaletteFade.active)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 5:
        if (!FuncIsActiveTask(sub_80B3AF8))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 6:
        if (sub_800A520() == TRUE)
        {
            sub_800ADF8();
            sub_814F9EC(gText_LinkStandby3, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(0))
        {
            if (sub_800A520() == TRUE)
                gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (!gLinkVSyncDisabled)
            sub_800AC34();
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 9:
        if (!gMain.field_439_x4 || gLinkVSyncDisabled || gReceivedRemoteLinkPlayers != 1)
        {
            gMain.field_439_x4 = 0;
            SetMainCallback2(gMain.savedCallback);
            FreeBattleResources();
            FreeBattleSpritesData();
            FreeMonSpritesGfx();
        }
        break;
    }
}

u32 sub_80391E0(u8 arrayId, u8 caseId)
{
    u32 ret = 0;

    switch (caseId)
    {
    case 0:
        ret = gUnknown_0831AA08[arrayId].bg;
        break;
    case 1:
        ret = gUnknown_0831AA08[arrayId].charBaseIndex;
        break;
    case 2:
        ret = gUnknown_0831AA08[arrayId].mapBaseIndex;
        break;
    case 3:
        ret = gUnknown_0831AA08[arrayId].screenSize;
        break;
    case 4:
        ret = gUnknown_0831AA08[arrayId].paletteMode;
        break;
    case 5:
        ret = gUnknown_0831AA08[arrayId].priority;
        break;
    case 6:
        ret = gUnknown_0831AA08[arrayId].baseTile;
        break;
    }

    return ret;
}

static void sub_80392A8(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;
    sub_80356D0();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ApplyPlayerChosenFrameToBattleMenu();

    for (i = 0; i < 2; i++)
        LoadChosenBattleElement(i);

    ResetSpriteData();
    ResetTasks();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;
    SetVBlankCallback(VBlankCB_Battle);
    SetMainCallback2(sub_803937C);
    BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
    gBattleCommunication[MULTIUSE_STATE] = 0;
}

static void sub_803937C(void)
{
    sub_803939C();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void sub_803939C(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (gMain.field_439_x4 && gReceivedRemoteLinkPlayers == 0)
            CreateTask(sub_80B3AF8, 5);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 2:
        if (!FuncIsActiveTask(sub_80B3AF8))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            sub_814F9EC(gText_RecordBattleToPass, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if (!IsTextPrinterActive(0))
        {
            sub_8056A3C(0x18, 8, 0x1D, 0xD, 0);
            sub_814F9EC(gText_BattleYesNoChoice, 0xC);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateCursorAt(1);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (gMain.newKeys & DPAD_UP)
        {
            if (gBattleCommunication[CURSOR_POSITION] != 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 0;
                BattleCreateCursorAt(0);
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 1;
                BattleCreateCursorAt(1);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
                gBattleCommunication[1] = MoveRecordedBattleToSaveData();
                gBattleCommunication[MULTIUSE_STATE] = 10;
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE]++;
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if (sub_800A520() == TRUE)
        {
            sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
            if (gMain.field_439_x4)
            {
                sub_800ADF8();
                sub_814F9EC(gText_LinkStandby3, 0);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (--gBattleCommunication[1] == 0)
        {
            if (gMain.field_439_x4 && !gLinkVSyncDisabled)
                sub_800AC34();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (!gMain.field_439_x4 || gLinkVSyncDisabled || gReceivedRemoteLinkPlayers != 1)
        {
            gMain.field_439_x4 = 0;
            if (!gPaletteFade.active)
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case 10:
        if (gBattleCommunication[1] == 1)
        {
            PlaySE(SE_SAVE);
            BattleStringExpandPlaceholdersToDisplayedString(gText_BattleRecordedOnPass);
            sub_814F9EC(gDisplayedStringBattle, 0);
            gBattleCommunication[1] = 0x80;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
        {
            BattleStringExpandPlaceholdersToDisplayedString(gText_BattleRecordCouldntBeSaved);
            sub_814F9EC(gDisplayedStringBattle, 0);
            gBattleCommunication[1] = 0x80;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (sub_800A520() == TRUE && !IsTextPrinterActive(0) && --gBattleCommunication[1] == 0)
        {
            if (gMain.field_439_x4)
            {
                sub_800ADF8();
                sub_814F9EC(gText_LinkStandby3, 0);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
    case 7:
        if (!IsTextPrinterActive(0))
        {
            if (gMain.field_439_x4)
            {
                if (sub_800A520() == TRUE)
                {
                    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
                    gBattleCommunication[1] = 0x20;
                    gBattleCommunication[MULTIUSE_STATE] = 8;
                }

            }
            else
            {
                BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
                gBattleCommunication[1] = 0x20;
                gBattleCommunication[MULTIUSE_STATE] = 8;
            }
        }
        break;
    }
}

static void TryCorrectShedinjaLanguage(struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 language = LANGUAGE_JAPANESE;

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_SHEDINJA
     && GetMonData(mon, MON_DATA_LANGUAGE) != language)
    {
        GetMonData(mon, MON_DATA_NICKNAME, nickname);
        if (StringCompareWithoutExtCtrlCodes(nickname, gText_ShedinjaJapaneseName) == 0)
            SetMonData(mon, MON_DATA_LANGUAGE, &language);
    }
}

u32 sub_80397C4(u32 setId, u32 tableId)
{
    return gUnknown_0831ABA0[setId][tableId].width * 8;
}

#define tBank               data0
#define tSpeciesId          data2

static void oac_poke_opponent(struct Sprite *sprite)
{
    sprite->callback = sub_803980C;
    StartSpriteAnimIfDifferent(sprite, 0);
    BeginNormalPaletteFade(0x20000, 0, 10, 10, 0x2108);
}

static void sub_803980C(struct Sprite *sprite)
{
    if ((gUnknown_020243FC & 1) == 0)
    {
        sprite->pos2.x += 2;
        if (sprite->pos2.x == 0)
        {
            sprite->callback = sub_8039838;
        }
    }
}

static void sub_8039838(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sub_8076918(sprite->tBank);
        sub_80729D0(gHealthBoxesIds[sprite->tBank]);
        sprite->callback = sub_8039894;
        StartSpriteAnimIfDifferent(sprite, 0);
        BeginNormalPaletteFade(0x20000, 0, 10, 0, 0x2108);
    }
}

static void sub_8039894(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
    {
        BattleAnimateFrontSprite(sprite, sprite->tSpeciesId, FALSE, 1);
    }
}

void SpriteCallbackDummy_2(struct Sprite *sprite)
{

}

static void sub_80398BC(struct Sprite *sprite) // unused?
{
    sprite->data3 = 6;
    sprite->data4 = 1;
    sprite->callback = sub_80398D0;
}

static void sub_80398D0(struct Sprite *sprite)
{
    sprite->data4--;
    if (sprite->data4 == 0)
    {
        sprite->data4 = 8;
        sprite->invisible ^= 1;
        sprite->data3--;
        if (sprite->data3 == 0)
        {
            sprite->invisible = FALSE;
            sprite->callback = SpriteCallbackDummy_2;
            gUnknown_02022F88 = 0;
        }
    }
}

// to get rid of once the struct is declared in a header
struct MonCoords
{
    // This would use a bitfield, but sub_8079F44
    // uses it as a u8 and casting won't match.
    u8 coords; // u8 x:4, y:4;
    u8 y_offset;
};

extern const struct MonCoords gMonFrontPicCoords[];
extern const struct MonCoords gCastformFrontSpriteCoords[];

void sub_8039934(struct Sprite *sprite)
{
    u8 bank = sprite->tBank;
    u16 species;
    u8 yOffset;

    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies != 0)
        species = gBattleSpritesDataPtr->bankData[bank].transformSpecies;
    else
        species = sprite->tSpeciesId;

    GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_PERSONALITY);  // Unused return value

    if (species == SPECIES_UNOWN)
    {
        u32 personalityValue = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_PERSONALITY);
        u16 unownForm = ((((personalityValue & 0x3000000) >> 18) | ((personalityValue & 0x30000) >> 12) | ((personalityValue & 0x300) >> 6) | (personalityValue & 3)) % 0x1C);
        u16 unownSpecies;

        if (unownForm == 0)
            unownSpecies = SPECIES_UNOWN;  // Use the A Unown form
        else
            unownSpecies = NUM_SPECIES + unownForm;  // Use one of the other Unown letters

        yOffset = gMonFrontPicCoords[unownSpecies].y_offset;
    }
    else if (species == SPECIES_CASTFORM)
    {
        yOffset = gCastformFrontSpriteCoords[gBattleMonForms[bank]].y_offset;
    }
    else if (species > NUM_SPECIES)
    {
        yOffset = gMonFrontPicCoords[SPECIES_NONE].y_offset;
    }
    else
    {
        yOffset = gMonFrontPicCoords[species].y_offset;
    }

    sprite->data3 = 8 - yOffset / 8;
    sprite->data4 = 1;
    sprite->callback = sub_8039A48;
}

static void sub_8039A48(struct Sprite *sprite)
{
    s32 i;

    sprite->data4--;
    if (sprite->data4 == 0)
    {
        sprite->data4 = 2;
        sprite->pos2.y += 8;
        sprite->data3--;
        if (sprite->data3 < 0)
        {
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
        else
        {
            u8 *dst = (u8 *)gMonSpritesGfxPtr->sprites[GetBankIdentity(sprite->tBank)] + (gBattleMonForms[sprite->tBank] << 11) + (sprite->data3 << 8);

            for (i = 0; i < 0x100; i++)
                *(dst++) = 0;

            StartSpriteAnim(sprite, gBattleMonForms[sprite->tBank]);
        }
    }
}

void sub_8039AD8(struct Sprite *sprite)
{
    sprite->data3 = 8;
    sprite->data4 = sprite->invisible;
    sprite->callback = sub_8039AF4;
}

static void sub_8039AF4(struct Sprite *sprite)
{
    sprite->data3--;
    if (sprite->data3 == 0)
    {
        sprite->invisible ^= 1;
        sprite->data3 = 8;
    }
}

void sub_8039B2C(struct Sprite *sprite)
{
    sprite->invisible = sprite->data4;
    sprite->data4 = FALSE;
    sprite->callback = SpriteCallbackDummy_2;
}

void sub_8039B58(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        if (!(gHitMarker & HITMARKER_NO_ANIMATIONS) || gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        {
            if (HasTwoFramesAnimation(sprite->tSpeciesId))
                StartSpriteAnim(sprite, 1);
        }
        BattleAnimateFrontSprite(sprite, sprite->tSpeciesId, TRUE, 1);
    }
}

void sub_8039BB4(struct Sprite *sprite)
{
    sprite->callback = oac_poke_ally_;
}

static void oac_poke_ally_(struct Sprite *sprite)
{
    if ((gUnknown_020243FC & 1) == 0)
    {
        sprite->pos2.x -= 2;
        if (sprite->pos2.x == 0)
        {
            sprite->callback = SpriteCallbackDummy_3;
            sprite->data1 = 0;
        }
    }
}

void sub_80105DC(struct Sprite *sprite)
{
    sprite->callback = SpriteCallbackDummy_3;
}

static void SpriteCallbackDummy_3(struct Sprite *sprite)
{
}

void sub_8039C00(struct Sprite *sprite)
{
    if (!(gUnknown_020243FC & 1))
    {
        sprite->pos2.x += sprite->data1;
        sprite->pos2.y += sprite->data2;
    }
}

void dp11b_obj_instanciate(u8 bank, u8 b, s8 c, s8 d)
{
    u8 bounceHealthBoxSpriteId;
    u8 spriteId2;

    if (b)
    {
        if (gBattleSpritesDataPtr->healthBoxesData[bank].flag_x2)
            return;
    }
    else
    {
        if (gBattleSpritesDataPtr->healthBoxesData[bank].flag_x4)
            return;
    }

    bounceHealthBoxSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_HealthBoxBounce);
    if (b == TRUE)
    {
        spriteId2 = gHealthBoxesIds[bank];
        gBattleSpritesDataPtr->healthBoxesData[bank].field_2 = bounceHealthBoxSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x2 = 1;
        gSprites[bounceHealthBoxSpriteId].data0 = 0x80;
    }
    else
    {
        spriteId2 = gBankSpriteIds[bank];
        gBattleSpritesDataPtr->healthBoxesData[bank].field_3 = bounceHealthBoxSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x4 = 1;
        gSprites[bounceHealthBoxSpriteId].data0 = 0xC0;
    }
    gSprites[bounceHealthBoxSpriteId].data1 = c;
    gSprites[bounceHealthBoxSpriteId].data2 = d;
    gSprites[bounceHealthBoxSpriteId].data3 = spriteId2;
    gSprites[bounceHealthBoxSpriteId].data4 = b;
    gSprites[spriteId2].pos2.x = 0;
    gSprites[spriteId2].pos2.y = 0;
}

void dp11b_obj_free(u8 bank, bool8 b)
{
    u8 r4;

    if (b == TRUE)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[bank].flag_x2)
            return;

        r4 = gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].field_2].data3;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].field_2]);
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x2 = 0;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[bank].flag_x4)
            return;

        r4 = gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].field_3].data3;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].field_3]);
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x4 = 0;
    }
    gSprites[r4].pos2.x = 0;
    gSprites[r4].pos2.y = 0;
}

static void SpriteCB_HealthBoxBounce(struct Sprite *sprite)
{
    u8 spriteId = sprite->data3;
    s32 var;

    if (sprite->data4 == 1)
        var = sprite->data0;
    else
        var = sprite->data0;

    gSprites[spriteId].pos2.y = Sin(var, sprite->data2) + sprite->data2;
    sprite->data0 = (sprite->data0 + sprite->data1) & 0xFF;
}

void sub_8039E44(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        BattleAnimateBackSprite(sprite, sprite->tSpeciesId);
}

void sub_8039E60(struct Sprite *sprite)
{
    sub_8039E9C(sprite);
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy_3;
}

void sub_8039E84(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = sub_8039E60;
}

void sub_8039E9C(struct Sprite *sprite)
{
    if (sprite->animDelayCounter == 0)
        sprite->centerToCornerVecX = gUnknown_0831ACE0[sprite->animCmdIndex];
}

void nullsub_20(void)
{

}

void BeginBattleIntro(void)
{
    BattleStartClearSetData();
    gBattleCommunication[1] = 0;
    gBattleMainFunc = BattleIntroGetMonsData;
}

static void BattleMainCB1(void)
{
    gBattleMainFunc();

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
        gBattleBankFunc[gActiveBank]();
}

static void BattleStartClearSetData(void)
{
    s32 i;
    u32 j;
    u8 *dataPtr;

    TurnValuesCleanUp(FALSE);
    SpecialStatusesClear();

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        gStatuses3[i] = 0;

        dataPtr = (u8 *)&gDisableStructs[i];
        for (j = 0; j < sizeof(struct DisableStruct); j++)
            dataPtr[j] = 0;

        gDisableStructs[i].isFirstTurn= 2;
        gUnknown_02024284[i] = 0;
        gLastUsedMovesByBanks[i] = 0;
        gUnknown_02024250[i] = 0;
        gUnknown_02024258[i] = 0;
        gUnknown_02024260[i] = 0;
        gUnknown_02024270[i] = 0xFF;
        gLockedMoves[i] = 0;
        gUnknownMovesUsedByBanks[i] = 0;
        gBattleResources->flags->flags[i] = 0;
        gUnknown_02024230[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        gSideAffecting[i] = 0;

        dataPtr = (u8 *)&gSideTimers[i];
        for (j = 0; j < sizeof(struct SideTimer); j++)
            dataPtr[j] = 0;
    }

    gBankAttacker = 0;
    gBankTarget = 0;
    gBattleWeather = 0;

    dataPtr = (u8 *)&gWishFutureKnock;
    for (i = 0; i < sizeof(struct WishFutureKnock); i++)
        dataPtr[i] = 0;

    gHitMarker = 0;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && gSaveBlock2Ptr->optionsBattleSceneOff == TRUE)
            gHitMarker |= HITMARKER_NO_ANIMATIONS;
    }
    else if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)) && sub_8185FB8())
        gHitMarker |= HITMARKER_NO_ANIMATIONS;

    gBattleScripting.battleStyle = gSaveBlock2Ptr->optionsBattleStyle;

    gMultiHitCounter = 0;
    gBattleOutcome = 0;
    gBattleExecBuffer = 0;
    gPaydayMoney = 0;
    gBattleResources->battleScriptsStack->size = 0;
    gBattleResources->battleCallbackStack->size = 0;

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    gPauseCounterBattle = 0;
    gBattleMoveDamage = 0;
    gUnknown_020243FC = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLeveledUpInBattle = 0;
    gAbsentBankFlags = 0;
    gBattleStruct->runTries = 0;
    gBattleStruct->field_79 = 0;
    gBattleStruct->field_7A = 0;
    *(&gBattleStruct->field_7C) = gBaseStats[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)].catchRate * 100 / 1275;
    gBattleStruct->field_7B = 3;
    gBattleStruct->wildVictorySong = 0;
    gBattleStruct->moneyMultiplier = 1;

    for (i = 0; i < 8; i++)
    {
        *((u8 *)gBattleStruct->mirrorMoves + i) = 0;
        *((u8 *)gBattleStruct->usedHeldItems + i) = 0;
        *((u8 *)gBattleStruct->choicedMove + i) = 0;
        *((u8 *)gBattleStruct->changedItems + i) = 0;
        *(i + 0 * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
        *(i + 1 * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
        *(i + 2 * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
        *(i + 3 * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    }

    for (i = 0; i < 4; i++)
    {
        *(gBattleStruct->field_294 + i) = 6;
    }

    gBattleStruct->field_DF = 0;
    gBattleStruct->field_92 = 0;

    gRandomTurnNumber = Random();

    dataPtr = (u8 *)(&gBattleResults);
    for (i = 0; i < sizeof(struct BattleResults); i++)
        dataPtr[i] = 0;

    gBattleResults.unk5_6 = IsMonShiny(&gEnemyParty[0]);

    gBattleStruct->field_2A0 = 0;
    gBattleStruct->field_2A1 = 0;
}

void SwitchInClearSetData(void)
{
    struct DisableStruct disableStructCopy = gDisableStructs[gActiveBank];
    s32 i;
    u8 *ptr;

    if (gBattleMoves[gCurrentMove].effect != EFFECT_BATON_PASS)
    {
        for (i = 0; i < BATTLE_STATS_NO; i++)
            gBattleMons[gActiveBank].statStages[i] = 6;
        for (i = 0; i < gNoOfAllBanks; i++)
        {
            if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gDisableStructs[i].bankPreventingEscape == gActiveBank)
                gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
            if ((gStatuses3[i] & STATUS3_ALWAYS_HITS) && gDisableStructs[i].bankWithSureHit == gActiveBank)
            {
                gStatuses3[i] &= ~STATUS3_ALWAYS_HITS;
                gDisableStructs[i].bankWithSureHit = 0;
            }
        }
    }
    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gBattleMons[gActiveBank].status2 &= (STATUS2_CONFUSION | STATUS2_FOCUS_ENERGY | STATUS2_SUBSTITUTE | STATUS2_ESCAPE_PREVENTION | STATUS2_CURSED);
        gStatuses3[gActiveBank] &= (STATUS3_LEECHSEED_BANK | STATUS3_LEECHSEED | STATUS3_ALWAYS_HITS | STATUS3_PERISH_SONG | STATUS3_ROOTED | STATUS3_MUDSPORT | STATUS3_WATERSPORT);

        for (i = 0; i < gNoOfAllBanks; i++)
        {
            if (GetBankSide(gActiveBank) != GetBankSide(i)
             && (gStatuses3[i] & STATUS3_ALWAYS_HITS) != 0
             && (gDisableStructs[i].bankWithSureHit == gActiveBank))
            {
                gStatuses3[i] &= ~STATUS3_ALWAYS_HITS;
                gStatuses3[i] |= 0x10;
            }
        }
    }
    else
    {
        gBattleMons[gActiveBank].status2 = 0;
        gStatuses3[gActiveBank] = 0;
    }

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(gActiveBank))
            gBattleMons[i].status2 &= ~(STATUS2_INFATUATED_WITH(gActiveBank));
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gBattleStruct->wrappedBy + i) == gActiveBank)
            gBattleMons[i].status2 &= ~(STATUS2_WRAPPED);
    }

    gActionSelectionCursor[gActiveBank] = 0;
    gMoveSelectionCursor[gActiveBank] = 0;

    ptr = (u8 *)&gDisableStructs[gActiveBank];
    for (i = 0; i < sizeof(struct DisableStruct); i++)
        ptr[i] = 0;

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gDisableStructs[gActiveBank].substituteHP = disableStructCopy.substituteHP;
        gDisableStructs[gActiveBank].bankWithSureHit = disableStructCopy.bankWithSureHit;
        gDisableStructs[gActiveBank].perishSong1 = disableStructCopy.perishSong1;
        gDisableStructs[gActiveBank].perishSong2 = disableStructCopy.perishSong2;
        gDisableStructs[gActiveBank].bankPreventingEscape = disableStructCopy.bankPreventingEscape;
    }

    gBattleMoveFlags = 0;
    gDisableStructs[gActiveBank].isFirstTurn= 2;
    gDisableStructs[gActiveBank].truantUnknownBit = disableStructCopy.truantUnknownBit;
    gLastUsedMovesByBanks[gActiveBank] = 0;
    gUnknown_02024250[gActiveBank] = 0;
    gUnknown_02024258[gActiveBank] = 0;
    gUnknown_02024260[gActiveBank] = 0;
    gUnknownMovesUsedByBanks[gActiveBank] = 0;
    gUnknown_02024270[gActiveBank] = 0xFF;

    *(gBattleStruct->mirrorMoves + gActiveBank * 2 + 0) = 0;
    *(gBattleStruct->mirrorMoves + gActiveBank * 2 + 1) = 0;
    *(0 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(0 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    *(1 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(1 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    *(2 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(2 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    *(3 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(3 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;

    gBattleStruct->field_92 &= ~(gBitTable[gActiveBank]);

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (i != gActiveBank && GetBankSide(i) != GetBankSide(gActiveBank))
        {
            *(gBattleStruct->mirrorMoves + i * 2 + 0) = 0;
            *(gBattleStruct->mirrorMoves + i * 2 + 1) = 0;
        }
        *(i * 8 + gActiveBank * 2 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
        *(i * 8 + gActiveBank * 2 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    }

    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBank]) + 0) = 0;
    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBank]) + 1) = 0;

    gBattleResources->flags->flags[gActiveBank] = 0;
    gCurrentMove = 0;
    gBattleStruct->field_DA = 0xFF;

    ClearBankMoveHistory(gActiveBank);
    ClearBankAbilityHistory(gActiveBank);
}

void FaintClearSetData(void)
{
    s32 i;
    u8 *ptr;

    for (i = 0; i < BATTLE_STATS_NO; i++)
        gBattleMons[gActiveBank].statStages[i] = 6;

    gBattleMons[gActiveBank].status2 = 0;
    gStatuses3[gActiveBank] = 0;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gDisableStructs[i].bankPreventingEscape == gActiveBank)
            gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(gActiveBank))
            gBattleMons[i].status2 &= ~(STATUS2_INFATUATED_WITH(gActiveBank));
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gBattleStruct->wrappedBy + i) == gActiveBank)
            gBattleMons[i].status2 &= ~(STATUS2_WRAPPED);
    }

    gActionSelectionCursor[gActiveBank] = 0;
    gMoveSelectionCursor[gActiveBank] = 0;

    ptr = (u8 *)&gDisableStructs[gActiveBank];
    for (i = 0; i < sizeof(struct DisableStruct); i++)
        ptr[i] = 0;

    gProtectStructs[gActiveBank].protected = 0;
    gProtectStructs[gActiveBank].endured = 0;
    gProtectStructs[gActiveBank].onlyStruggle = 0;
    gProtectStructs[gActiveBank].helpingHand = 0;
    gProtectStructs[gActiveBank].bounceMove = 0;
    gProtectStructs[gActiveBank].stealMove = 0;
    gProtectStructs[gActiveBank].flag0Unknown = 0;
    gProtectStructs[gActiveBank].prlzImmobility = 0;
    gProtectStructs[gActiveBank].confusionSelfDmg = 0;
    gProtectStructs[gActiveBank].targetNotAffected = 0;
    gProtectStructs[gActiveBank].chargingTurn = 0;
    gProtectStructs[gActiveBank].fleeFlag = 0;
    gProtectStructs[gActiveBank].usedImprisionedMove = 0;
    gProtectStructs[gActiveBank].loveImmobility = 0;
    gProtectStructs[gActiveBank].usedDisabledMove = 0;
    gProtectStructs[gActiveBank].usedTauntedMove = 0;
    gProtectStructs[gActiveBank].flag2Unknown = 0;
    gProtectStructs[gActiveBank].flinchImmobility = 0;
    gProtectStructs[gActiveBank].notFirstStrike = 0;

    gDisableStructs[gActiveBank].isFirstTurn = 2;

    gLastUsedMovesByBanks[gActiveBank] = 0;
    gUnknown_02024250[gActiveBank] = 0;
    gUnknown_02024258[gActiveBank] = 0;
    gUnknown_02024260[gActiveBank] = 0;
    gUnknownMovesUsedByBanks[gActiveBank] = 0;
    gUnknown_02024270[gActiveBank] = 0xFF;

    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBank]) + 0) = 0;
    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBank]) + 1) = 0;

    *(gBattleStruct->mirrorMoves + gActiveBank * 2 + 0) = 0;
    *(gBattleStruct->mirrorMoves + gActiveBank * 2 + 1) = 0;
    *(0 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(0 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    *(1 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(1 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    *(2 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(2 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    *(3 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
    *(3 * 2 + gActiveBank * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;

    gBattleStruct->field_92 &= ~(gBitTable[gActiveBank]);

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (i != gActiveBank && GetBankSide(i) != GetBankSide(gActiveBank))
        {
            *(gBattleStruct->mirrorMoves + i * 2 + 0) = 0;
            *(gBattleStruct->mirrorMoves + i * 2 + 1) = 0;
        }
        *(i * 8 + gActiveBank * 2 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = 0;
        *(i * 8 + gActiveBank * 2 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = 0;
    }

    gBattleResources->flags->flags[gActiveBank] = 0;

    gBattleMons[gActiveBank].type1 = gBaseStats[gBattleMons[gActiveBank].species].type1;
    gBattleMons[gActiveBank].type2 = gBaseStats[gBattleMons[gActiveBank].species].type2;

    ClearBankMoveHistory(gActiveBank);
    ClearBankAbilityHistory(gActiveBank);
}

static void BattleIntroGetMonsData(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        gActiveBank = gBattleCommunication[1];
        EmitGetMonData(0, 0, 0);
        MarkBufferBankForExecution(gActiveBank);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (gBattleExecBuffer == 0)
        {
            gBattleCommunication[1]++;
            if (gBattleCommunication[1] == gNoOfAllBanks)
                gBattleMainFunc = BattleIntroPrepareBackgroundSlide;
            else
                gBattleCommunication[MULTIUSE_STATE] = 0;
        }
        break;
    }
}

static void BattleIntroPrepareBackgroundSlide(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBankByIdentity(0);
        EmitIntroSlide(0, gBattleTerrain);
        MarkBufferBankForExecution(gActiveBank);
        gBattleMainFunc = BattleIntroDrawTrainersOrMonsSprites;
        gBattleCommunication[0] = 0;
        gBattleCommunication[1] = 0;
    }
}

static void BattleIntroDrawTrainersOrMonsSprites(void)
{
    u8 *ptr;
    s32 i;

    if (gBattleExecBuffer)
        return;

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI)
         && GetBankSide(gActiveBank) == SIDE_PLAYER)
        {
            ptr = (u8 *)&gBattleMons[gActiveBank];
            for (i = 0; i < sizeof(struct BattlePokemon); i++)
                ptr[i] = 0;
        }
        else
        {
            u16* hpOnSwitchout;

            ptr = (u8 *)&gBattleMons[gActiveBank];
            for (i = 0; i < sizeof(struct BattlePokemon); i++)
                ptr[i] = gBattleBufferB[gActiveBank][4 + i];

            gBattleMons[gActiveBank].type1 = gBaseStats[gBattleMons[gActiveBank].species].type1;
            gBattleMons[gActiveBank].type2 = gBaseStats[gBattleMons[gActiveBank].species].type2;
            gBattleMons[gActiveBank].ability = GetAbilityBySpecies(gBattleMons[gActiveBank].species, gBattleMons[gActiveBank].altAbility);
            hpOnSwitchout = &gBattleStruct->hpOnSwitchout[GetBankSide(gActiveBank)];
            *hpOnSwitchout = gBattleMons[gActiveBank].hp;
            for (i = 0; i < BATTLE_STATS_NO; i++)
                gBattleMons[gActiveBank].statStages[i] = 6;
            gBattleMons[gActiveBank].status2 = 0;
        }

        if (GetBankIdentity(gActiveBank) == IDENTITY_PLAYER_MON1)
        {
            EmitDrawTrainerPic(0);
            MarkBufferBankForExecution(gActiveBank);
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON1)
            {
                EmitDrawTrainerPic(0);
                MarkBufferBankForExecution(gActiveBank);
            }
            if (GetBankSide(gActiveBank) == SIDE_OPPONENT
             && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                      | BATTLE_TYPE_FRONTIER
                                      | BATTLE_TYPE_LINK
                                      | BATTLE_TYPE_x2000000
                                      | BATTLE_TYPE_x4000000)))
            {
                HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBank].species), FLAG_SET_SEEN, gBattleMons[gActiveBank].personality);
            }
        }
        else
        {
            if (GetBankSide(gActiveBank) == SIDE_OPPONENT)
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                      | BATTLE_TYPE_FRONTIER
                                      | BATTLE_TYPE_LINK
                                      | BATTLE_TYPE_x2000000
                                      | BATTLE_TYPE_x4000000)))
                {
                    HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBank].species), FLAG_SET_SEEN, gBattleMons[gActiveBank].personality);
                }
                EmitLoadMonSprite(0);
                MarkBufferBankForExecution(gActiveBank);
                gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES, NULL);
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (GetBankIdentity(gActiveBank) == IDENTITY_PLAYER_MON2
             || GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON2)
            {
                EmitDrawTrainerPic(0);
                MarkBufferBankForExecution(gActiveBank);
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON2)
        {
            EmitDrawTrainerPic(0);
            MarkBufferBankForExecution(gActiveBank);
        }

        if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
            sub_81A56B4();
    }
    gBattleMainFunc = BattleIntroDrawPartySummaryScreens;
}

static void BattleIntroDrawPartySummaryScreens(void)
{
    s32 i;
    struct HpAndStatus hpStatus[6];

    if (gBattleExecBuffer)
        return;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        for (i = 0; i < 6; i++)
        {
            if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES2) == SPECIES_NONE
             || GetMonData(&gEnemyParty[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            {
                hpStatus[i].hp = 0xFFFF;
                hpStatus[i].status = 0;
            }
            else
            {
                hpStatus[i].hp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                hpStatus[i].status = GetMonData(&gEnemyParty[i], MON_DATA_STATUS);
            }
        }
        gActiveBank = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
        EmitDrawPartyStatusSummary(0, hpStatus, 0x80);
        MarkBufferBankForExecution(gActiveBank);

        for (i = 0; i < 6; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_NONE
             || GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            {
                hpStatus[i].hp = 0xFFFF;
                hpStatus[i].status = 0;
            }
            else
            {
                hpStatus[i].hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                hpStatus[i].status = GetMonData(&gPlayerParty[i], MON_DATA_STATUS);
            }
        }
        gActiveBank = GetBankByIdentity(IDENTITY_PLAYER_MON1);
        EmitDrawPartyStatusSummary(0, hpStatus, 0x80);
        MarkBufferBankForExecution(gActiveBank);

        gBattleMainFunc = BattleIntroPrintTrainerWantsToBattle;
    }
    else
    {
        // The struct gets set here, but nothing is ever done with it since
        // wild battles don't show the party summary.
        // Still, there's no point in having dead code.

        for (i = 0; i < 6; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_NONE
             || GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            {
                hpStatus[i].hp = 0xFFFF;
                hpStatus[i].status = 0;
            }
            else
            {
                hpStatus[i].hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                hpStatus[i].status = GetMonData(&gPlayerParty[i], MON_DATA_STATUS);
            }
        }

        gBattleMainFunc = BattleIntroPrintWildMonAttacked;
    }

}

static void BattleIntroPrintTrainerWantsToBattle(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
        PrepareStringBattle(STRINGID_INTROMSG, gActiveBank);
        gBattleMainFunc = BattleIntroPrintOpponentSendsOut;
    }
}

static void BattleIntroPrintWildMonAttacked(void)
{
    if (gBattleExecBuffer == 0)
    {
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
        PrepareStringBattle(STRINGID_INTROMSG, 0);
    }
}

static void BattleIntroPrintOpponentSendsOut(void)
{
    u32 identity;

    if (gBattleExecBuffer)
        return;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        identity = IDENTITY_OPPONENT_MON1;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            identity = IDENTITY_OPPONENT_MON1;
        else
            identity = IDENTITY_PLAYER_MON1;
    }
    else
        identity = IDENTITY_OPPONENT_MON1;

    PrepareStringBattle(STRINGID_INTROSENDOUT, GetBankByIdentity(identity));
    gBattleMainFunc = BattleIntroOpponent1SendsOutMonAnimation;
}

static void BattleIntroOpponent2SendsOutMonAnimation(void)
{
    u32 identity;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        identity = IDENTITY_OPPONENT_MON2;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            identity = IDENTITY_OPPONENT_MON2;
        else
            identity = IDENTITY_PLAYER_MON2;
    }
    else
        identity = IDENTITY_OPPONENT_MON2;

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        if (GetBankIdentity(gActiveBank) == identity)
        {
            EmitIntroTrainerBallThrow(0);
            MarkBufferBankForExecution(gActiveBank);
        }
    }

    gBattleMainFunc = BattleIntroRecordMonsToDex;
}

#ifdef NONMATCHING
static void BattleIntroOpponent1SendsOutMonAnimation(void)
{
    u32 identity;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        identity = IDENTITY_OPPONENT_MON1;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            identity = IDENTITY_OPPONENT_MON1;
        else
            identity = IDENTITY_PLAYER_MON1;
    }
    else
        identity = IDENTITY_OPPONENT_MON1;

    if (gBattleExecBuffer)
        return;

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        if (GetBankIdentity(gActiveBank) == identity)
        {
            EmitIntroTrainerBallThrow(0);
            MarkBufferBankForExecution(gActiveBank);
            if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS))
            {
                gBattleMainFunc = BattleIntroOpponent2SendsOutMonAnimation;
                return;
            }
        }
    }

    gBattleMainFunc = BattleIntroRecordMonsToDex;
}

#else
__attribute__((naked))
static void BattleIntroOpponent1SendsOutMonAnimation(void)
{
    asm(".syntax unified\n\
        	push {r4-r6,lr}\n\
	ldr r0, =gBattleTypeFlags\n\
	ldr r2, [r0]\n\
	movs r0, 0x80\n\
	lsls r0, 17\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _0803B298\n\
	movs r0, 0x80\n\
	lsls r0, 18\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _0803B298\n\
	movs r1, 0x80\n\
	lsls r1, 24\n\
	ands r1, r2\n\
	negs r0, r1\n\
	orrs r0, r1\n\
	lsrs r5, r0, 31\n\
	b _0803B29A\n\
	.pool\n\
_0803B288:\n\
	ldr r1, =gBattleMainFunc\n\
	ldr r0, =BattleIntroOpponent2SendsOutMonAnimation\n\
	b _0803B2F0\n\
	.pool\n\
_0803B298:\n\
	movs r5, 0x1\n\
_0803B29A:\n\
	ldr r0, =gBattleExecBuffer\n\
	ldr r2, [r0]\n\
	cmp r2, 0\n\
	bne _0803B2F2\n\
	ldr r0, =gActiveBank\n\
	strb r2, [r0]\n\
	ldr r1, =gNoOfAllBanks\n\
	adds r4, r0, 0\n\
	ldrb r1, [r1]\n\
	cmp r2, r1\n\
	bcs _0803B2EC\n\
	adds r6, r4, 0\n\
_0803B2B2:\n\
	ldrb r0, [r4]\n\
	bl GetBankIdentity\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, r5\n\
	bne _0803B2D8\n\
	movs r0, 0\n\
	bl EmitIntroTrainerBallThrow\n\
	ldrb r0, [r4]\n\
	bl MarkBufferBankForExecution\n\
	ldr r0, =gBattleTypeFlags\n\
	ldr r0, [r0]\n\
	ldr r1, =0x00008040\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _0803B288\n\
_0803B2D8:\n\
	ldrb r0, [r6]\n\
	adds r0, 0x1\n\
	strb r0, [r6]\n\
	ldr r1, =gNoOfAllBanks\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	ldr r4, =gActiveBank\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bcc _0803B2B2\n\
_0803B2EC:\n\
	ldr r1, =gBattleMainFunc\n\
	ldr r0, =BattleIntroRecordMonsToDex\n\
_0803B2F0:\n\
	str r0, [r1]\n\
_0803B2F2:\n\
	pop {r4-r6}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
        .syntax divided");
}

#endif // NONMATCHING

static void BattleIntroRecordMonsToDex(void)
{
    if (gBattleExecBuffer == 0)
    {
        for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
        {
            if (GetBankSide(gActiveBank) == SIDE_OPPONENT
             && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                      | BATTLE_TYPE_FRONTIER
                                      | BATTLE_TYPE_LINK
                                      | BATTLE_TYPE_x2000000
                                      | BATTLE_TYPE_x4000000)))
            {
                HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBank].species), FLAG_SET_SEEN, gBattleMons[gActiveBank].personality);
            }
        }
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
    }
}

void sub_803B3AC(void) // unused
{
    if (gBattleExecBuffer == 0)
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
}

static void BattleIntroPrintPlayerSendsOut(void)
{
    if (gBattleExecBuffer == 0)
    {
        u8 identity;

        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
            identity = IDENTITY_PLAYER_MON1;
        else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
                identity = IDENTITY_PLAYER_MON1;
            else
                identity = IDENTITY_OPPONENT_MON1;
        }
        else
            identity = IDENTITY_PLAYER_MON1;

        if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
            PrepareStringBattle(STRINGID_INTROSENDOUT, GetBankByIdentity(identity));

        gBattleMainFunc = BattleIntroPlayer1SendsOutMonAnimation;
    }
}

static void BattleIntroPlayer2SendsOutMonAnimation(void)
{
    u32 identity;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        identity = IDENTITY_PLAYER_MON2;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            identity = IDENTITY_PLAYER_MON2;
        else
            identity = IDENTITY_OPPONENT_MON2;
    }
    else
        identity = IDENTITY_PLAYER_MON2;

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        if (GetBankIdentity(gActiveBank) == identity)
        {
            EmitIntroTrainerBallThrow(0);
            MarkBufferBankForExecution(gActiveBank);
        }
    }

    gBattleStruct->switchInAbilitiesCounter = 0;
    gBattleStruct->switchInItemsCounter = 0;
    gBattleStruct->overworldWeatherDone = FALSE;

    gBattleMainFunc = TryDoEventsBeforeFirstTurn;
}

static void BattleIntroPlayer1SendsOutMonAnimation(void)
{
    u32 identity;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        identity = IDENTITY_PLAYER_MON1;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            identity = IDENTITY_PLAYER_MON1;
        else
            identity = IDENTITY_OPPONENT_MON1;
    }
    else
        identity = IDENTITY_PLAYER_MON1;

    if (gBattleExecBuffer)
        return;

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        if (GetBankIdentity(gActiveBank) == identity)
        {
            EmitIntroTrainerBallThrow(0);
            MarkBufferBankForExecution(gActiveBank);
            if (gBattleTypeFlags & (BATTLE_TYPE_MULTI))
            {
                gBattleMainFunc = BattleIntroPlayer2SendsOutMonAnimation;
                return;
            }
        }
    }

    gBattleStruct->switchInAbilitiesCounter = 0;
    gBattleStruct->switchInItemsCounter = 0;
    gBattleStruct->overworldWeatherDone = FALSE;

    gBattleMainFunc = TryDoEventsBeforeFirstTurn;
}

void sub_803B598(void) // unused
{
    if (gBattleExecBuffer == 0)
    {
        for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
        {
            if (GetBankSide(gActiveBank) == SIDE_PLAYER)
            {
                EmitSwitchInAnim(0, gBattlePartyID[gActiveBank], FALSE);
                MarkBufferBankForExecution(gActiveBank);
            }
        }

        gBattleStruct->switchInAbilitiesCounter = 0;
        gBattleStruct->switchInItemsCounter = 0;
        gBattleStruct->overworldWeatherDone = FALSE;

        gBattleMainFunc = TryDoEventsBeforeFirstTurn;
    }
}

static void TryDoEventsBeforeFirstTurn(void)
{
    s32 i;
    s32 j;
    u8 effect = 0;

    if (gBattleExecBuffer)
        return;

    if (gBattleStruct->switchInAbilitiesCounter == 0)
    {
        for (i = 0; i < gNoOfAllBanks; i++)
            gBanksByTurnOrder[i] = i;
        for (i = 0; i < gNoOfAllBanks - 1; i++)
        {
            for (j = i + 1; j < gNoOfAllBanks; j++)
            {
                if (GetWhoStrikesFirst(gBanksByTurnOrder[i], gBanksByTurnOrder[j], TRUE) != 0)
                    SwapTurnOrder(i, j);
            }
        }
    }
    if (!gBattleStruct->overworldWeatherDone
        && AbilityBattleEffects(0, 0, 0, ABILITYEFFECT_SWITCH_IN_WEATHER, 0) != 0)
    {
        gBattleStruct->overworldWeatherDone = TRUE;
        return;
    }
    // check all switch in abilities happening from the fastest mon to slowest
    while (gBattleStruct->switchInAbilitiesCounter < gNoOfAllBanks)
    {
        if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gBanksByTurnOrder[gBattleStruct->switchInAbilitiesCounter], 0, 0, 0) != 0)
            effect++;

        gBattleStruct->switchInAbilitiesCounter++;

        if (effect)
            return;
    }
    if (AbilityBattleEffects(ABILITYEFFECT_INTIMIDATE1, 0, 0, 0, 0) != 0)
        return;
    if (AbilityBattleEffects(ABILITYEFFECT_TRACE, 0, 0, 0, 0) != 0)
        return;
    // check all switch in items having effect from the fastest mon to slowest
    while (gBattleStruct->switchInItemsCounter < gNoOfAllBanks)
    {
        if (ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, gBanksByTurnOrder[gBattleStruct->switchInItemsCounter], 0) != 0)
            effect++;

        gBattleStruct->switchInItemsCounter++;

        if (effect)
            return;
    }
    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        *(gBattleStruct->field_5C + i) = 6;
        gActionForBanks[i] = ACTION_INIT_VALUE;
        gChosenMovesByBanks[i] = MOVE_NONE;
    }
    TurnValuesCleanUp(FALSE);
    SpecialStatusesClear();
    *(&gBattleStruct->field_91) = gAbsentBankFlags;
    sub_814F9EC(gText_EmptyString3, 0);
    gBattleMainFunc = HandleTurnActionSelectionState;
    ResetSentPokesToOpponentValue();

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    for (i = 0; i < gNoOfAllBanks; i++)
        gBattleMons[i].status2 &= ~(STATUS2_FLINCHED);

    *(&gBattleStruct->turnEffectsTracker) = 0;
    *(&gBattleStruct->turnEffectsBank) = 0;
    *(&gBattleStruct->field_1A0) = 0;
    *(&gBattleStruct->field_1A1) = 0;
    gBattleScripting.atk49_state = 0;
    gBattleStruct->field_4D = 0;
    gBattleStruct->turncountersTracker = 0;
    gBattleMoveFlags = 0;

    gRandomTurnNumber = Random();

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        StopCryAndClearCrySongs();
        BattleScriptExecute(gUnknown_082DB8BE);
    }
}

static void HandleEndTurn_ContinueBattle(void)
{
    s32 i;

    if (gBattleExecBuffer == 0)
    {
        gBattleMainFunc = BattleTurnPassed;
        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;
        for (i = 0; i < gNoOfAllBanks; i++)
        {
            gBattleMons[i].status2 &= ~(STATUS2_FLINCHED);
            if ((gBattleMons[i].status1 & STATUS_SLEEP) && (gBattleMons[i].status2 & STATUS2_MULTIPLETURNS))
                CancelMultiTurnMoves(i);
        }
        gBattleStruct->turnEffectsTracker = 0;
        gBattleStruct->turnEffectsBank = 0;
        gBattleStruct->field_1A0 = 0;
        gBattleStruct->field_1A1 = 0;
        gBattleStruct->turncountersTracker = 0;
        gBattleMoveFlags = 0;
    }
}

void BattleTurnPassed(void)
{
    s32 i;

    TurnValuesCleanUp(TRUE);
    if (gBattleOutcome == 0)
    {
        if (UpdateTurnCounters() != 0)
            return;
        if (TurnBasedEffects() != 0)
            return;
    }
    if (sub_8041728() != 0)
        return;
    gBattleStruct->field_4D = 0;
    if (sub_8041364() != 0)
        return;

    TurnValuesCleanUp(FALSE);
    gHitMarker &= ~(HITMARKER_NO_ATTACKSTRING);
    gHitMarker &= ~(HITMARKER_UNABLE_TO_USE_MOVE);
    gHitMarker &= ~(HITMARKER_x400000);
    gHitMarker &= ~(HITMARKER_x100000);
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleScripting.atk49_state = 0;
    gBattleMoveDamage = 0;
    gBattleMoveFlags = 0;

    for (i = 0; i < 5; i++)
        gBattleCommunication[i] = 0;

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = 12;
        gBattleMainFunc = RunTurnActionsFunctions;
        return;
    }

    if (gBattleResults.battleTurnCounter < 0xFF)
    {
        gBattleResults.battleTurnCounter++;
        gBattleStruct->field_DA++;
    }

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        gActionForBanks[i] = ACTION_INIT_VALUE;
        gChosenMovesByBanks[i] = MOVE_NONE;
    }

    for (i = 0; i < 4; i++)
        *(gBattleStruct->field_5C + i) = 6;

    *(&gBattleStruct->field_91) = gAbsentBankFlags;
    sub_814F9EC(gText_EmptyString3, 0);
    gBattleMainFunc = HandleTurnActionSelectionState;
    gRandomTurnNumber = Random();

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        BattleScriptExecute(gUnknown_082DB881);
    else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->field_DA == 0)
        BattleScriptExecute(gUnknown_082DB8BE);
}

u8 IsRunningFromBattleImpossible(void)
{
    u8 holdEffect;
    u8 side;
    s32 i;

    if (gBattleMons[gActiveBank].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gActiveBank].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gActiveBank].item);

    gStringBank = gActiveBank;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
        return 0;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return 0;
    if (gBattleMons[gActiveBank].ability == ABILITY_RUN_AWAY)
        return 0;

    side = GetBankSide(gActiveBank);

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (side != GetBankSide(i)
         && gBattleMons[i].ability == ABILITY_SHADOW_TAG)
        {
            gBattleScripting.bank = i;
            gLastUsedAbility = gBattleMons[i].ability;
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            return 2;
        }
        if (side != GetBankSide(i)
         && gBattleMons[gActiveBank].ability != ABILITY_LEVITATE
         && gBattleMons[gActiveBank].type1 != TYPE_FLYING
         && gBattleMons[gActiveBank].type2 != TYPE_FLYING
         && gBattleMons[i].ability == ABILITY_ARENA_TRAP)
        {
            gBattleScripting.bank = i;
            gLastUsedAbility = gBattleMons[i].ability;
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            return 2;
        }
    }
    i = AbilityBattleEffects(ABILITYEFFECT_CHECK_FIELD_EXCEPT_BANK, gActiveBank, ABILITY_MAGNET_PULL, 0, 0);
    if (i != 0 && (gBattleMons[gActiveBank].type1 == TYPE_STEEL || gBattleMons[gActiveBank].type2 == TYPE_STEEL))
    {
        gBattleScripting.bank = i - 1;
        gLastUsedAbility = gBattleMons[i - 1].ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        return 2;
    }
    if ((gBattleMons[gActiveBank].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        || (gStatuses3[gActiveBank] & STATUS3_ROOTED))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        return 1;
    }
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        return 1;
    }
    return 0;
}

void sub_803BDA0(u8 bank)
{
    s32 i;
    u8 r4;
    u8 r1;

    // gBattleStruct->field_60[bank][i]

    for (i = 0; i < 3; i++)
        gUnknown_0203CF00[i] = *(bank * 3 + i + (u8*)(gBattleStruct->field_60));

    r4 = pokemon_order_func(gBattlePartyID[bank]);
    r1 = pokemon_order_func(*(gBattleStruct->field_5C + bank));
    sub_81B8FB0(r4, r1);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        for (i = 0; i < 3; i++)
        {
            *(bank * 3 + i + (u8*)(gBattleStruct->field_60)) = gUnknown_0203CF00[i];
            *((bank ^ BIT_MON) * 3 + i + (u8*)(gBattleStruct->field_60)) = gUnknown_0203CF00[i];
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            *(bank * 3 + i + (u8*)(gBattleStruct->field_60)) = gUnknown_0203CF00[i];
        }
    }
}

enum
{
    STATE_TURN_START_RECORD,
    STATE_BEFORE_ACTION_CHOSEN,
    STATE_WAIT_ACTION_CHOSEN,
    STATE_WAIT_ACTION_CASE_CHOSEN,
    STATE_WAIT_ACTION_CONFIRMED_STANDBY,
    STATE_WAIT_ACTION_CONFIRMED,
    STATE_SELECTION_SCRIPT,
    STATE_WAIT_SET_BEFORE_ACTION,
    STATE_SELECTION_SCRIPT_MAY_RUN
};

static void HandleTurnActionSelectionState(void)
{
    s32 i;

    gBattleCommunication[ACTIONS_CONFIRMED_COUNT] = 0;
    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        u8 identity = GetBankIdentity(gActiveBank);
        switch (gBattleCommunication[gActiveBank])
        {
        case STATE_TURN_START_RECORD: // recorded battle related on start of every turn
            sub_8185FD0();
            gBattleCommunication[gActiveBank] = STATE_BEFORE_ACTION_CHOSEN;
            break;
        case STATE_BEFORE_ACTION_CHOSEN: // choose an action
            *(gBattleStruct->field_5C + gActiveBank) = 6;
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI
                || !(identity & BIT_MON)
                || gBattleStruct->field_91 & gBitTable[GetBankByIdentity(identity ^ BIT_MON)]
                || gBattleCommunication[GetBankByIdentity(identity ^ BIT_MON)] == 5)
            {
                if (gBattleStruct->field_91 & gBitTable[gActiveBank])
                {
                    gActionForBanks[gActiveBank] = ACTION_NOTHING_FAINTED;
                    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        gBattleCommunication[gActiveBank] = STATE_WAIT_ACTION_CONFIRMED;
                    else
                        gBattleCommunication[gActiveBank] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    if (gBattleMons[gActiveBank].status2 & STATUS2_MULTIPLETURNS
                        || gBattleMons[gActiveBank].status2 & STATUS2_RECHARGE)
                    {
                        gActionForBanks[gActiveBank] = ACTION_USE_MOVE;
                        gBattleCommunication[gActiveBank] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else
                    {
                        EmitChooseAction(0, gActionForBanks[0], gBattleBufferB[0][1] | (gBattleBufferB[0][2] << 8));
                        MarkBufferBankForExecution(gActiveBank);
                        gBattleCommunication[gActiveBank]++;
                    }
                }
            }
            break;
        case STATE_WAIT_ACTION_CHOSEN: // try to perform an action
            if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
            {
                RecordedBattle_SetBankAction(gActiveBank, gBattleBufferB[gActiveBank][1]);
                gActionForBanks[gActiveBank] = gBattleBufferB[gActiveBank][1];

                switch (gBattleBufferB[gActiveBank][1])
                {
                case ACTION_USE_MOVE:
                    if (AreAllMovesUnusable())
                    {
                        gBattleCommunication[gActiveBank] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBank) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBank) = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        *(gBattleStruct->moveTarget + gActiveBank) = gBattleBufferB[gActiveBank][3];
                        return;
                    }
                    else if (gDisableStructs[gActiveBank].encoredMove != 0)
                    {
                        gChosenMovesByBanks[gActiveBank] = gDisableStructs[gActiveBank].encoredMove;
                        *(gBattleStruct->chosenMovePositions + gActiveBank) = gDisableStructs[gActiveBank].encoredMovePos;
                        gBattleCommunication[gActiveBank] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        return;
                    }
                    else
                    {
                        struct ChooseMoveStruct moveInfo;

                        moveInfo.species = gBattleMons[gActiveBank].species;
                        moveInfo.monType1 = gBattleMons[gActiveBank].type1;
                        moveInfo.monType2 = gBattleMons[gActiveBank].type2;

                        for (i = 0; i < 4; i++)
                        {
                            moveInfo.moves[i] = gBattleMons[gActiveBank].moves[i];
                            moveInfo.ppNumbers[i] = gBattleMons[gActiveBank].pp[i];
                            moveInfo.ppWithBonusNumbers[i] = CalculatePPWithBonus(
                                                            gBattleMons[gActiveBank].moves[i],
                                                            gBattleMons[gActiveBank].ppBonuses,
                                                            i);
                        }

                        EmitChooseMove(0, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0, FALSE, &moveInfo);
                        MarkBufferBankForExecution(gActiveBank);
                    }
                    break;
                case ACTION_USE_ITEM:
                    if (gBattleTypeFlags & (BATTLE_TYPE_LINK
                                            | BATTLE_TYPE_FRONTIER_NO_PYRAMID
                                            | BATTLE_TYPE_EREADER_TRAINER
                                            | BATTLE_TYPE_x2000000))
                    {
                        RecordedBattle_ClearBankAction(gActiveBank, 1);
                        gBattlescriptPtrsForSelection[gActiveBank] = BattleScript_ActionSelectionItemsCantBeUsed;
                        gBattleCommunication[gActiveBank] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBank) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBank) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    else
                    {
                        EmitOpenBag(0, gBattleStruct->field_60[gActiveBank]);
                        MarkBufferBankForExecution(gActiveBank);
                    }
                    break;
                case ACTION_SWITCH:
                    *(gBattleStruct->field_58 + gActiveBank) = gBattlePartyID[gActiveBank];
                    if (gBattleMons[gActiveBank].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION)
                        || gBattleTypeFlags & BATTLE_TYPE_ARENA
                        || gStatuses3[gActiveBank] & STATUS3_ROOTED)
                    {
                        EmitChoosePokemon(0, 2, 6, ABILITY_NONE, gBattleStruct->field_60[gActiveBank]);
                    }
                    else if ((i = AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBank, ABILITY_SHADOW_TAG, 0, 0))
                             || ((i = AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBank, ABILITY_ARENA_TRAP, 0, 0))
                                 && gBattleMons[gActiveBank].type1 != TYPE_FLYING
                                 && gBattleMons[gActiveBank].type2 != TYPE_FLYING
                                 && gBattleMons[gActiveBank].ability != ABILITY_LEVITATE)
                             || ((i = AbilityBattleEffects(ABILITYEFFECT_CHECK_FIELD_EXCEPT_BANK, gActiveBank, ABILITY_MAGNET_PULL, 0, 0))
                                 && (gBattleMons[gActiveBank].type1 == TYPE_STEEL
                                     || gBattleMons[gActiveBank].type2 == TYPE_STEEL)))
                    {
                        EmitChoosePokemon(0, ((i - 1) << 4) | 4, 6, gLastUsedAbility, gBattleStruct->field_60[gActiveBank]);
                    }
                    else
                    {
                        if (gActiveBank == 2 && gActionForBanks[0] == ACTION_SWITCH)
                            EmitChoosePokemon(0, 0, *(gBattleStruct->field_5C + 0), ABILITY_NONE, gBattleStruct->field_60[gActiveBank]);
                        else if (gActiveBank == 3 && gActionForBanks[1] == ACTION_SWITCH)
                            EmitChoosePokemon(0, 0, *(gBattleStruct->field_5C + 1), ABILITY_NONE, gBattleStruct->field_60[gActiveBank]);
                        else
                            EmitChoosePokemon(0, 0, 6, ABILITY_NONE, gBattleStruct->field_60[gActiveBank]);
                    }
                    MarkBufferBankForExecution(gActiveBank);
                    break;
                case ACTION_SAFARI_ZONE_BALL:
                    if (IsPlayerPartyAndPokemonStorageFull())
                    {
                        gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DAB11;
                        gBattleCommunication[gActiveBank] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBank) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBank) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    break;
                case ACTION_POKEBLOCK_CASE:
                    EmitOpenBag(0, gBattleStruct->field_60[gActiveBank]);
                    MarkBufferBankForExecution(gActiveBank);
                    break;
                case ACTION_CANCEL_PARTNER:
                    gBattleCommunication[gActiveBank] = 7;
                    gBattleCommunication[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)] = 1;
                    RecordedBattle_ClearBankAction(gActiveBank, 1);
                    if (gBattleMons[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)].status2 & STATUS2_MULTIPLETURNS
                        || gBattleMons[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)].status2 & STATUS2_RECHARGE)
                    {
                        Emit_x32(0);
                        MarkBufferBankForExecution(gActiveBank);
                        return;
                    }
                    else if (gActionForBanks[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)] == ACTION_SWITCH)
                    {
                        RecordedBattle_ClearBankAction(GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON), 2);
                    }
                    else if (gActionForBanks[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)] == ACTION_RUN)
                    {
                        RecordedBattle_ClearBankAction(GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON), 1);
                    }
                    else if (gActionForBanks[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)] == ACTION_USE_MOVE
                             && (gProtectStructs[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)].onlyStruggle
                                || gDisableStructs[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)].encoredMove))
                    {
                        RecordedBattle_ClearBankAction(GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON), 1);
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_PALACE
                             && gActionForBanks[GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON)] == ACTION_USE_MOVE)
                    {
                        gRngValue = gBattlePalaceMoveSelectionRngValue;
                        RecordedBattle_ClearBankAction(GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON), 1);
                    }
                    else
                    {
                        RecordedBattle_ClearBankAction(GetBankByIdentity(GetBankIdentity(gActiveBank) ^ BIT_MON), 3);
                    }
                    Emit_x32(0);
                    MarkBufferBankForExecution(gActiveBank);
                    return;
                }

                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                    && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_x4000000)
                    && gBattleBufferB[gActiveBank][1] == ACTION_RUN)
                {
                    gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DB9BA;
                    gBattleCommunication[gActiveBank] = 8;
                    *(gBattleStruct->selectionScriptFinished + gActiveBank) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBank) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                         && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
                         && gBattleBufferB[gActiveBank][1] == ACTION_RUN)
                {
                    BattleScriptExecute(gUnknown_082DAAFE);
                    gBattleCommunication[gActiveBank] = 1;
                }
                else if (IsRunningFromBattleImpossible() != 0
                         && gBattleBufferB[gActiveBank][1] == ACTION_RUN)
                {
                    gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DAB0B;
                    gBattleCommunication[gActiveBank] = STATE_SELECTION_SCRIPT;
                    *(gBattleStruct->selectionScriptFinished + gActiveBank) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBank) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else
                {
                    gBattleCommunication[gActiveBank]++;
                }
            }
            break;
        case STATE_WAIT_ACTION_CASE_CHOSEN:
            if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
            {
                switch (gActionForBanks[gActiveBank])
                {
                case ACTION_USE_MOVE:
                    switch (gBattleBufferB[gActiveBank][1])
                    {
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                        gActionForBanks[gActiveBank] = gBattleBufferB[gActiveBank][1];
                        return;
                    case 15:
                        gActionForBanks[gActiveBank] = ACTION_SWITCH;
                        sub_803CDF8();
                        return;
                    default:
                        sub_818603C(2);
                        if ((gBattleBufferB[gActiveBank][2] | (gBattleBufferB[gActiveBank][3] << 8)) == 0xFFFF)
                        {
                            gBattleCommunication[gActiveBank] = 1;
                            RecordedBattle_ClearBankAction(gActiveBank, 1);
                        }
                        else if (TrySetCantSelectMoveBattleScript())
                        {
                            RecordedBattle_ClearBankAction(gActiveBank, 1);
                            gBattleCommunication[gActiveBank] = STATE_SELECTION_SCRIPT;
                            *(gBattleStruct->selectionScriptFinished + gActiveBank) = FALSE;
                            gBattleBufferB[gActiveBank][1] = 0;
                            *(gBattleStruct->stateIdAfterSelScript + gActiveBank) = STATE_WAIT_ACTION_CHOSEN;
                            return;
                        }
                        else
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_PALACE))
                            {
                                RecordedBattle_SetBankAction(gActiveBank, gBattleBufferB[gActiveBank][2]);
                                RecordedBattle_SetBankAction(gActiveBank, gBattleBufferB[gActiveBank][3]);
                            }
                            *(gBattleStruct->chosenMovePositions + gActiveBank) = gBattleBufferB[gActiveBank][2];
                            gChosenMovesByBanks[gActiveBank] = gBattleMons[gActiveBank].moves[*(gBattleStruct->chosenMovePositions + gActiveBank)];
                            *(gBattleStruct->moveTarget + gActiveBank) = gBattleBufferB[gActiveBank][3];
                            gBattleCommunication[gActiveBank]++;
                        }
                        break;
                    }
                    break;
                case ACTION_USE_ITEM:
                    if ((gBattleBufferB[gActiveBank][1] | (gBattleBufferB[gActiveBank][2] << 8)) == 0)
                    {
                        gBattleCommunication[gActiveBank] = 1;
                    }
                    else
                    {
                        gLastUsedItem = (gBattleBufferB[gActiveBank][1] | (gBattleBufferB[gActiveBank][2] << 8));
                        gBattleCommunication[gActiveBank]++;
                    }
                    break;
                case ACTION_SWITCH:
                    if (gBattleBufferB[gActiveBank][1] == 6)
                    {
                        gBattleCommunication[gActiveBank] = 1;
                        RecordedBattle_ClearBankAction(gActiveBank, 1);
                    }
                    else
                    {
                        sub_803CDF8();
                        gBattleCommunication[gActiveBank]++;
                    }
                    break;
                case ACTION_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[gActiveBank]++;
                    break;
                case ACTION_WATCHES_CAREFULLY:
                    gBattleCommunication[gActiveBank]++;
                    break;
                case ACTION_SAFARI_ZONE_BALL:
                    gBattleCommunication[gActiveBank]++;
                    break;
                case ACTION_POKEBLOCK_CASE:
                    if ((gBattleBufferB[gActiveBank][1] | (gBattleBufferB[gActiveBank][2] << 8)) != 0)
                    {
                        gBattleCommunication[gActiveBank]++;
                    }
                    else
                    {
                        gBattleCommunication[gActiveBank] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    break;
                case ACTION_GO_NEAR:
                    gBattleCommunication[gActiveBank]++;
                    break;
                case ACTION_SAFARI_ZONE_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[gActiveBank]++;
                    break;
                case ACTION_9:
                    gBattleCommunication[gActiveBank]++;
                    break;
                }
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED_STANDBY:
            if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
            {
                i = (sub_803CDB8() != 0);

                if (((gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_DOUBLE)) != BATTLE_TYPE_DOUBLE)
                    || (identity & BIT_MON)
                    || (*(&gBattleStruct->field_91) & gBitTable[GetBankByIdentity(identity ^ BIT_MON)]))
                {
                    EmitLinkStandbyMsg(0, 0, i);
                }
                else
                {
                    EmitLinkStandbyMsg(0, 1, i);
                }
                MarkBufferBankForExecution(gActiveBank);
                gBattleCommunication[gActiveBank]++;
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED:
            if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
            {
                gBattleCommunication[ACTIONS_CONFIRMED_COUNT]++;
            }
            break;
        case STATE_SELECTION_SCRIPT:
            if (*(gBattleStruct->selectionScriptFinished + gActiveBank))
            {
                gBattleCommunication[gActiveBank] = *(gBattleStruct->stateIdAfterSelScript + gActiveBank);
            }
            else
            {
                gBankAttacker = gActiveBank;
                gBattlescriptCurrInstr = gBattlescriptPtrsForSelection[gActiveBank];
                if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gBattlescriptPtrsForSelection[gActiveBank] = gBattlescriptCurrInstr;
            }
            break;
        case STATE_WAIT_SET_BEFORE_ACTION:
            if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
            {
                gBattleCommunication[gActiveBank] = 1;
            }
            break;
        case STATE_SELECTION_SCRIPT_MAY_RUN:
            if (*(gBattleStruct->selectionScriptFinished + gActiveBank))
            {
                if (gBattleBufferB[gActiveBank][1] == 13)
                {
                    gHitMarker |= HITMARKER_RUN;
                    gActionForBanks[gActiveBank] = ACTION_RUN;
                    gBattleCommunication[gActiveBank] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    RecordedBattle_ClearBankAction(gActiveBank, 1);
                    gBattleCommunication[gActiveBank] = *(gBattleStruct->stateIdAfterSelScript + gActiveBank);
                }
            }
            else
            {
                gBankAttacker = gActiveBank;
                gBattlescriptCurrInstr = gBattlescriptPtrsForSelection[gActiveBank];
                if (!(gBattleExecBuffer & ((gBitTable[gActiveBank]) | (0xF0000000) | (gBitTable[gActiveBank] << 4) | (gBitTable[gActiveBank] << 8) | (gBitTable[gActiveBank] << 0xC))))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gBattlescriptPtrsForSelection[gActiveBank] = gBattlescriptCurrInstr;
            }
            break;
        }
    }

    // check if everyone chose actions
    if (gBattleCommunication[ACTIONS_CONFIRMED_COUNT] == gNoOfAllBanks)
    {
        sub_818603C(1);
        gBattleMainFunc = SetActionsAndBanksTurnOrder;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gActionForBanks[i] == ACTION_SWITCH)
                    sub_80571DC(i, *(gBattleStruct->field_5C + i));
            }
        }
    }
}

static bool8 sub_803CDB8(void)
{
    s32 i, var;

    for (var = 0, i = 0; i < gNoOfAllBanks; i++)
    {
        if (gBattleCommunication[i] == 5)
            var++;
    }

    if (var + 1 == gNoOfAllBanks)
        return TRUE;
    else
        return FALSE;
}

static void sub_803CDF8(void)
{
    *(gBattleStruct->field_5C + gActiveBank) = gBattleBufferB[gActiveBank][1];
    RecordedBattle_SetBankAction(gActiveBank, gBattleBufferB[gActiveBank][1]);

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        *(gActiveBank * 3 + (u8*)(gBattleStruct->field_60) + 0) &= 0xF;
        *(gActiveBank * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleBufferB[gActiveBank][2] & 0xF0);
        *(gActiveBank * 3 + (u8*)(gBattleStruct->field_60) + 1) = gBattleBufferB[gActiveBank][3];

        *((gActiveBank ^ BIT_MON) * 3 + (u8*)(gBattleStruct->field_60) + 0) &= (0xF0);
        *((gActiveBank ^ BIT_MON) * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleBufferB[gActiveBank][2] & 0xF0) >> 4;
        *((gActiveBank ^ BIT_MON) * 3 + (u8*)(gBattleStruct->field_60) + 2) = gBattleBufferB[gActiveBank][3];
    }
}

void SwapTurnOrder(u8 id1, u8 id2)
{
    u32 temp = gActionsByTurnOrder[id1];
    gActionsByTurnOrder[id1] = gActionsByTurnOrder[id2];
    gActionsByTurnOrder[id2] = temp;

    temp = gBanksByTurnOrder[id1];
    gBanksByTurnOrder[id1] = gBanksByTurnOrder[id2];
    gBanksByTurnOrder[id2] = temp;
}

u8 GetWhoStrikesFirst(u8 bank1, u8 bank2, bool8 ignoreChosenMoves)
{
    u8 strikesFirst = 0;
    u8 speedMultiplierBank1 = 0, speedMultiplierBank2 = 0;
    u32 speedBank1 = 0, speedBank2 = 0;
    u8 holdEffect = 0;
    u8 holdEffectParam = 0;
    u16 moveBank1 = 0, moveBank2 = 0;

    if (WEATHER_HAS_EFFECT)
    {
        if ((gBattleMons[bank1].ability == ABILITY_SWIFT_SWIM && gBattleWeather & WEATHER_RAIN_ANY)
            || (gBattleMons[bank1].ability == ABILITY_CHLOROPHYLL && gBattleWeather & WEATHER_SUN_ANY))
            speedMultiplierBank1 = 2;
        else
            speedMultiplierBank1 = 1;

        if ((gBattleMons[bank2].ability == ABILITY_SWIFT_SWIM && gBattleWeather & WEATHER_RAIN_ANY)
            || (gBattleMons[bank2].ability == ABILITY_CHLOROPHYLL && gBattleWeather & WEATHER_SUN_ANY))
            speedMultiplierBank2 = 2;
        else
            speedMultiplierBank2 = 1;
    }
    else
    {
        speedMultiplierBank1 = 1;
        speedMultiplierBank2 = 1;
    }

    speedBank1 = (gBattleMons[bank1].speed * speedMultiplierBank1)
                * (gStatStageRatios[gBattleMons[bank1].statStages[STAT_STAGE_SPEED]][0])
                / (gStatStageRatios[gBattleMons[bank1].statStages[STAT_STAGE_SPEED]][1]);

    if (gBattleMons[bank1].item == ITEM_ENIGMA_BERRY)
    {
        holdEffect = gEnigmaBerries[bank1].holdEffect;
        holdEffectParam = gEnigmaBerries[bank1].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[bank1].item);
        holdEffectParam = ItemId_GetHoldEffectParam(gBattleMons[bank1].item);
    }

    // badge boost
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_FRONTIER))
        && FlagGet(BADGE03_GET)
        && GetBankSide(bank1) == SIDE_PLAYER)
    {
        speedBank1 = (speedBank1 * 110) / 100;
    }

    if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
        speedBank1 /= 2;

    if (gBattleMons[bank1].status1 & STATUS_PARALYSIS)
        speedBank1 /= 4;

    if (holdEffect == HOLD_EFFECT_QUICK_CLAW && gRandomTurnNumber < (0xFFFF * holdEffectParam) / 100)
        speedBank1 = UINT_MAX;

    // check second bank's speed

    speedBank2 = (gBattleMons[bank2].speed * speedMultiplierBank2)
                * (gStatStageRatios[gBattleMons[bank2].statStages[STAT_STAGE_SPEED]][0])
                / (gStatStageRatios[gBattleMons[bank2].statStages[STAT_STAGE_SPEED]][1]);

    if (gBattleMons[bank2].item == ITEM_ENIGMA_BERRY)
    {
        holdEffect = gEnigmaBerries[bank2].holdEffect;
        holdEffectParam = gEnigmaBerries[bank2].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[bank2].item);
        holdEffectParam = ItemId_GetHoldEffectParam(gBattleMons[bank2].item);
    }

    // badge boost
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_FRONTIER))
        && FlagGet(BADGE03_GET)
        && GetBankSide(bank2) == SIDE_PLAYER)
    {
        speedBank2 = (speedBank2 * 110) / 100;
    }

    if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
        speedBank2 /= 2;

    if (gBattleMons[bank2].status1 & STATUS_PARALYSIS)
        speedBank2 /= 4;

    if (holdEffect == HOLD_EFFECT_QUICK_CLAW && gRandomTurnNumber < (0xFFFF * holdEffectParam) / 100)
        speedBank2 = UINT_MAX;

    if (ignoreChosenMoves)
    {
        moveBank1 = MOVE_NONE;
        moveBank2 = MOVE_NONE;
    }
    else
    {
        if (gActionForBanks[bank1] == ACTION_USE_MOVE)
        {
            if (gProtectStructs[bank1].onlyStruggle)
                moveBank1 = MOVE_STRUGGLE;
            else
                moveBank1 = gBattleMons[bank1].moves[*(gBattleStruct->chosenMovePositions + bank1)];
        }
        else
            moveBank1 = MOVE_NONE;

        if (gActionForBanks[bank2] == ACTION_USE_MOVE)
        {
            if (gProtectStructs[bank2].onlyStruggle)
                moveBank2 = MOVE_STRUGGLE;
            else
                moveBank2 = gBattleMons[bank2].moves[*(gBattleStruct->chosenMovePositions + bank2)];
        }
        else
            moveBank2 = MOVE_NONE;
    }

    // both move priorities are different than 0
    if (gBattleMoves[moveBank1].priority != 0 || gBattleMoves[moveBank2].priority != 0)
    {
        // both priorities are the same
        if (gBattleMoves[moveBank1].priority == gBattleMoves[moveBank2].priority)
        {
            if (speedBank1 == speedBank2 && Random() & 1)
                strikesFirst = 2; // same speeds, same priorities
            else if (speedBank1 < speedBank2)
                strikesFirst = 1; // bank2 has more speed

            // else bank1 has more speed
        }
        else if (gBattleMoves[moveBank1].priority < gBattleMoves[moveBank2].priority)
            strikesFirst = 1; // bank2's move has greater priority

        // else bank1's move has greater priority
    }
    // both priorities are equal to 0
    else
    {
        if (speedBank1 == speedBank2 && Random() & 1)
            strikesFirst = 2; // same speeds, same priorities
        else if (speedBank1 < speedBank2)
            strikesFirst = 1; // bank2 has more speed

        // else bank1 has more speed
    }

    return strikesFirst;
}

static void SetActionsAndBanksTurnOrder(void)
{
    s32 var = 0;
    s32 i, j;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
    {
        for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
        {
            gActionsByTurnOrder[var] = gActionForBanks[gActiveBank];
            gBanksByTurnOrder[var] = gActiveBank;
            var++;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
            {
                if (gActionForBanks[gActiveBank] == ACTION_RUN)
                {
                    var = 5;
                    break;
                }
            }
        }
        else
        {
            if (gActionForBanks[0] == ACTION_RUN)
            {
                gActiveBank = 0;
                var = 5;
            }
            if (gActionForBanks[2] == ACTION_RUN)
            {
                gActiveBank = 2;
                var = 5;
            }
        }

        if (var == 5)
        {
            gActionsByTurnOrder[0] = gActionForBanks[gActiveBank];
            gBanksByTurnOrder[0] = gActiveBank;
            var = 1;
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (i != gActiveBank)
                {
                    gActionsByTurnOrder[var] = gActionForBanks[i];
                    gBanksByTurnOrder[var] = i;
                    var++;
                }
            }
            gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
            gBattleStruct->focusPunchBank = 0;
            return;
        }
        else
        {
            for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
            {
                if (gActionForBanks[gActiveBank] == ACTION_USE_ITEM || gActionForBanks[gActiveBank] == ACTION_SWITCH)
                {
                    gActionsByTurnOrder[var] = gActionForBanks[gActiveBank];
                    gBanksByTurnOrder[var] = gActiveBank;
                    var++;
                }
            }
            for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
            {
                if (gActionForBanks[gActiveBank] != ACTION_USE_ITEM && gActionForBanks[gActiveBank] != ACTION_SWITCH)
                {
                    gActionsByTurnOrder[var] = gActionForBanks[gActiveBank];
                    gBanksByTurnOrder[var] = gActiveBank;
                    var++;
                }
            }
            for (i = 0; i < gNoOfAllBanks - 1; i++)
            {
                for (j = i + 1; j < gNoOfAllBanks; j++)
                {
                    u8 bank1 = gBanksByTurnOrder[i];
                    u8 bank2 = gBanksByTurnOrder[j];
                    if (gActionsByTurnOrder[i] != ACTION_USE_ITEM
                        && gActionsByTurnOrder[j] != ACTION_USE_ITEM
                        && gActionsByTurnOrder[i] != ACTION_SWITCH
                        && gActionsByTurnOrder[j] != ACTION_SWITCH)
                    {
                        if (GetWhoStrikesFirst(bank1, bank2, FALSE))
                            SwapTurnOrder(i, j);
                    }
                }
            }
        }
    }
    gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
    gBattleStruct->focusPunchBank = 0;
}

static void TurnValuesCleanUp(bool8 var0)
{
    s32 i;
    u8 *dataPtr;

    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        if (var0)
        {
            gProtectStructs[gActiveBank].protected = 0;
            gProtectStructs[gActiveBank].endured = 0;
        }
        else
        {
            dataPtr = (u8*)(&gProtectStructs[gActiveBank]);
            for (i = 0; i < sizeof(struct ProtectStruct); i++)
                dataPtr[i] = 0;

            if (gDisableStructs[gActiveBank].isFirstTurn)
                gDisableStructs[gActiveBank].isFirstTurn--;

            if (gDisableStructs[gActiveBank].rechargeCounter)
            {
                gDisableStructs[gActiveBank].rechargeCounter--;
                if (gDisableStructs[gActiveBank].rechargeCounter == 0)
                    gBattleMons[gActiveBank].status2 &= ~(STATUS2_RECHARGE);
            }
        }

        if (gDisableStructs[gActiveBank].substituteHP == 0)
                gBattleMons[gActiveBank].status2 &= ~(STATUS2_SUBSTITUTE);
    }

    gSideTimers[0].followmeTimer = 0;
    gSideTimers[1].followmeTimer = 0;
}

static void SpecialStatusesClear(void)
{
    for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
    {
        s32 i;
        u8 *dataPtr = (u8*)(&gSpecialStatuses[gActiveBank]);

        for (i = 0; i < sizeof(struct SpecialStatus); i++)
            dataPtr[i] = 0;
    }
}

static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void)
{
    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->focusPunchBank < gNoOfAllBanks)
        {
            gActiveBank = gBankAttacker = gBattleStruct->focusPunchBank;
            gBattleStruct->focusPunchBank++;
            if (gChosenMovesByBanks[gActiveBank] == MOVE_FOCUS_PUNCH
                && !(gBattleMons[gActiveBank].status1 & STATUS_SLEEP)
                && !(gDisableStructs[gBankAttacker].truantCounter)
                && !(gProtectStructs[gActiveBank].onlyStruggle))
            {
                BattleScriptExecute(BattleScript_FocusPunchSetUp);
                return;
            }
        }
    }

    TryClearRageStatuses();
    gCurrentTurnActionNumber = 0;
{
    // something stupid needed to match
    u8 zero;
    gCurrentActionFuncId = gActionsByTurnOrder[(zero = 0)];
}
    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleMainFunc = RunTurnActionsFunctions;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.field_16 = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

static void RunTurnActionsFunctions(void)
{
    if (gBattleOutcome != 0)
        gCurrentActionFuncId = 12;

    *(&gBattleStruct->field_4B) = gCurrentTurnActionNumber;
    sTurnActionsFuncsTable[gCurrentActionFuncId]();

    if (gCurrentTurnActionNumber >= gNoOfAllBanks) // everyone did their actions, turn finished
    {
        gHitMarker &= ~(HITMARKER_x100000);
        gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
    }
    else
    {
        if (gBattleStruct->field_4B != gCurrentTurnActionNumber) // action turn has been done, clear hitmarker bits for another bank
        {
            gHitMarker &= ~(HITMARKER_NO_ATTACKSTRING);
            gHitMarker &= ~(HITMARKER_UNABLE_TO_USE_MOVE);
        }
    }
}

static void HandleEndTurn_BattleWon(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
    {
        gScriptResult = gBattleOutcome;
        gBattleTextBuff1[0] = gBattleOutcome;
        gBankAttacker = GetBankByIdentity(IDENTITY_PLAYER_MON1);
        gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
        gBattleOutcome &= ~(BATTLE_OUTCOME_BIT_x80);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_x4000000 | BATTLE_TYPE_EREADER_TRAINER))
    {
        BattleMusicStop();
        gBattlescriptCurrInstr = BattleScript_FrontierTrainerBattleWon;

        if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_3FE)
            PlayBGM(BGM_KACHI3);
        else
            PlayBGM(BGM_KACHI1);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        BattleMusicStop();
        gBattlescriptCurrInstr = BattleScript_LocalTrainerBattleWon;

        switch (gTrainers[gTrainerBattleOpponent_A].trainerClass)
        {
        case CLASS_ELITE_FOUR:
        case CLASS_CHAMPION:
            PlayBGM(BGM_KACHI5);
            break;
        case CLASS_TEAM_AQUA:
        case CLASS_TEAM_MAGMA:
        case CLASS_AQUA_ADMIN:
        case CLASS_AQUA_LEADER:
        case CLASS_MAGMA_ADMIN:
        case CLASS_MAGMA_LEADER:
            PlayBGM(BGM_KACHI4);
            break;
        case CLASS_LEADER:
            PlayBGM(BGM_KACHI3);
            break;
        default:
            PlayBGM(BGM_KACHI1);
            break;
        }
    }
    else
    {
        gBattlescriptCurrInstr = BattleScript_PayDayMoneyAndPickUpItems;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_BattleLost(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        {
            if (gBattleOutcome & BATTLE_OUTCOME_BIT_x80)
            {
                gBattlescriptCurrInstr = gUnknown_082DB9C8;
                gBattleOutcome &= ~(BATTLE_OUTCOME_BIT_x80);
                gSaveBlock2Ptr->field_CA9_b = 1;
            }
            else
            {
                gBattlescriptCurrInstr = gUnknown_082DAA0B;
                gBattleOutcome &= ~(BATTLE_OUTCOME_BIT_x80);
            }
        }
        else
        {
            gBattleTextBuff1[0] = gBattleOutcome;
            gBankAttacker = GetBankByIdentity(IDENTITY_PLAYER_MON1);
            gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
            gBattleOutcome &= ~(BATTLE_OUTCOME_BIT_x80);
        }
    }
    else
    {
        gBattlescriptCurrInstr = BattleScript_LocalBattleLost;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_RanFromBattle(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        gBattlescriptCurrInstr = gUnknown_082DB9C1;
        gBattleOutcome = BATTLE_FORFEITED;
        gSaveBlock2Ptr->field_CA9_b = 1;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_x4000000)
    {
        gBattlescriptCurrInstr = gUnknown_082DB9C1;
        gBattleOutcome = BATTLE_FORFEITED;
    }
    else
    {
        switch (gProtectStructs[gBankAttacker].fleeFlag)
        {
        default:
            gBattlescriptCurrInstr = BattleScript_GotAwaySafely;
            break;
        case 1:
            gBattlescriptCurrInstr = BattleScript_SmokeBallEscape;
            break;
        case 2:
            gBattlescriptCurrInstr = BattleScript_RanAwayUsingMonAbility;
            break;
        }
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_MonFled(void)
{
    gCurrentActionFuncId = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBankAttacker, gBattlePartyID[gBankAttacker]);
    gBattlescriptCurrInstr = BattleScript_WildMonFled;

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_FinishBattle(void)
{
    if (gCurrentActionFuncId == 0xB || gCurrentActionFuncId == 0xC)
    {
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_x2000000
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_WALLY_TUTORIAL
                                  | BATTLE_TYPE_FRONTIER)))
        {
            for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
            {
                if (GetBankSide(gActiveBank) == SIDE_PLAYER)
                {
                    if (gBattleResults.playerMon1Species == SPECIES_NONE)
                    {
                        gBattleResults.playerMon1Species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES, NULL);
                        GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_NICKNAME, gBattleResults.playerMon1Name);
                    }
                    else
                    {
                        gBattleResults.playerMon2Species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES, NULL);
                        GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_NICKNAME, gBattleResults.playerMon2Name);
                    }
                }
            }
            sub_80EC728();
        }

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_x2000000
                                  | BATTLE_TYPE_TRAINER
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_WALLY_TUTORIAL))
            && gBattleResults.unk5_6)
        {
            sub_80EE184();
        }

        sub_8186444();
        BeginFastPaletteFade(3);
        FadeOutMapMusic(5);
        gBattleMainFunc = FreeResetData_ReturnToOvOrDoEvolutions;
        gUnknown_030061E8 = BattleMainCB2;
    }
    else
    {
        if (gBattleExecBuffer == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        if (gLeveledUpInBattle == 0 || gBattleOutcome != BATTLE_WON)
        {
            gBattleMainFunc = ReturnFromBattleToOverworld;
            return;
        }
        else
        {
            gBattleMainFunc = TryEvolvePokemon;
        }
    }

    FreeAllWindowBuffers();
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        FreeMonSpritesGfx();
        FreeBattleResources();
        FreeBattleSpritesData();
    }
}

static void TryEvolvePokemon(void)
{
    s32 i;

    while (gLeveledUpInBattle != 0)
    {
        for (i = 0; i < 6; i++)
        {
            if (gLeveledUpInBattle & gBitTable[i])
            {
                u16 species;
                u8 levelUpBits = gLeveledUpInBattle;

                levelUpBits &= ~(gBitTable[i]);
                gLeveledUpInBattle = levelUpBits;

                species = GetEvolutionTargetSpecies(&gPlayerParty[i], 0, levelUpBits);
                if (species != SPECIES_NONE)
                {
                    FreeAllWindowBuffers();
                    gBattleMainFunc = WaitForEvoSceneToFinish;
                    EvolutionScene(&gPlayerParty[i], species, TRUE, i);
                    return;
                }
            }
        }
    }

    gBattleMainFunc = ReturnFromBattleToOverworld;
}

static void WaitForEvoSceneToFinish(void)
{
    if (gMain.callback2 == BattleMainCB2)
        gBattleMainFunc = TryEvolvePokemon;
}

static void ReturnFromBattleToOverworld(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        RandomlyGivePartyPokerus(gPlayerParty);
        PartySpreadPokerus(gPlayerParty);
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gReceivedRemoteLinkPlayers != 0)
        return;

    gScriptResult = gBattleOutcome;
    gMain.inBattle = 0;
    gMain.callback1 = gPreBattleCallback1;

    if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
    {
        UpdateRoamerHPStatus(&gEnemyParty[0]);
        if ((gBattleOutcome & BATTLE_WON) || gBattleOutcome == BATTLE_CAUGHT)
            SetRoamerInactive();
    }

    m4aSongNumStop(0x5A);
    SetMainCallback2(gMain.savedCallback);
}

void RunBattleScriptCommands_PopCallbacksStack(void)
{
    if (gCurrentActionFuncId == 0xB || gCurrentActionFuncId == 0xC)
    {
        if (BATTLE_CALLBACKS_STACK->size != 0)
            BATTLE_CALLBACKS_STACK->size--;
        gBattleMainFunc = BATTLE_CALLBACKS_STACK->function[BATTLE_CALLBACKS_STACK->size];
    }
    else
    {
        if (gBattleExecBuffer == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

void RunBattleScriptCommands(void)
{
    if (gBattleExecBuffer == 0)
        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
}

static void HandleAction_UseMove(void)
{
    u8 side;
    u8 var = 4;

    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];

    if (*(&gBattleStruct->field_91) & gBitTable[gBankAttacker])
    {
        gCurrentActionFuncId = ACTION_FINISHED;
        return;
    }

    gCritMultiplier = 1;
    gBattleScripting.dmgMultiplier = 1;
    gBattleStruct->atkCancellerTracker = 0;
    gBattleMoveFlags = 0;
    gMultiHitCounter = 0;
    gBattleCommunication[6] = 0;
    gCurrMovePos = gUnknown_020241E9 = *(gBattleStruct->chosenMovePositions + gBankAttacker);

    // choose move
    if (gProtectStructs[gBankAttacker].onlyStruggle)
    {
        gProtectStructs[gBankAttacker].onlyStruggle = 0;
        gCurrentMove = gLastUsedMove = MOVE_STRUGGLE;
        gHitMarker |= HITMARKER_NO_PPDEDUCT;
        *(gBattleStruct->moveTarget + gBankAttacker) = GetMoveTarget(MOVE_STRUGGLE, 0);
    }
    else if (gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS || gBattleMons[gBankAttacker].status2 & STATUS2_RECHARGE)
    {
        gCurrentMove = gLastUsedMove = gLockedMoves[gBankAttacker];
    }
    // encore forces you to use the same move
    else if (gDisableStructs[gBankAttacker].encoredMove != MOVE_NONE
             && gDisableStructs[gBankAttacker].encoredMove == gBattleMons[gBankAttacker].moves[gDisableStructs[gBankAttacker].encoredMovePos])
    {
        gCurrentMove = gLastUsedMove = gDisableStructs[gBankAttacker].encoredMove;
        gCurrMovePos = gUnknown_020241E9 = gDisableStructs[gBankAttacker].encoredMovePos;
        *(gBattleStruct->moveTarget + gBankAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    // check if the encored move wasn't overwritten
    else if (gDisableStructs[gBankAttacker].encoredMove != MOVE_NONE
             && gDisableStructs[gBankAttacker].encoredMove != gBattleMons[gBankAttacker].moves[gDisableStructs[gBankAttacker].encoredMovePos])
    {
        gCurrMovePos = gUnknown_020241E9 = gDisableStructs[gBankAttacker].encoredMovePos;
        gCurrentMove = gLastUsedMove = gBattleMons[gBankAttacker].moves[gCurrMovePos];
        gDisableStructs[gBankAttacker].encoredMove = MOVE_NONE;
        gDisableStructs[gBankAttacker].encoredMovePos = 0;
        gDisableStructs[gBankAttacker].encoreTimer1 = 0;
        *(gBattleStruct->moveTarget + gBankAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else if (gBattleMons[gBankAttacker].moves[gCurrMovePos] != gChosenMovesByBanks[gBankAttacker])
    {
        gCurrentMove = gLastUsedMove = gBattleMons[gBankAttacker].moves[gCurrMovePos];
        *(gBattleStruct->moveTarget + gBankAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else
    {
        gCurrentMove = gLastUsedMove = gBattleMons[gBankAttacker].moves[gCurrMovePos];
    }

    if (gBattleMons[gBankAttacker].hp != 0)
    {
        if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
            gBattleResults.lastUsedMovePlayer = gCurrentMove;
        else
            gBattleResults.lastUsedMoveOpponent = gCurrentMove;
    }

    // choose target
    side = GetBankSide(gBankAttacker) ^ BIT_SIDE;
    if (gSideTimers[side].followmeTimer != 0
        && gBattleMoves[gCurrentMove].target == MOVE_TARGET_SELECTED
        && GetBankSide(gBankAttacker) != GetBankSide(gSideTimers[side].followmeTarget)
        && gBattleMons[gSideTimers[side].followmeTarget].hp != 0)
    {
        gBankTarget = gSideTimers[side].followmeTarget;
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
             && gSideTimers[side].followmeTimer == 0
             && (gBattleMoves[gCurrentMove].power != 0
                 || gBattleMoves[gCurrentMove].target != MOVE_TARGET_x10)
             && gBattleMons[*(gBattleStruct->moveTarget + gBankAttacker)].ability != ABILITY_LIGHTNING_ROD
             && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
    {
        side = GetBankSide(gBankAttacker);
        for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
        {
            if (side != GetBankSide(gActiveBank)
                && *(gBattleStruct->moveTarget + gBankAttacker) != gActiveBank
                && gBattleMons[gActiveBank].ability == ABILITY_LIGHTNING_ROD
                && BankGetTurnOrder(gActiveBank) < var)
            {
                var = BankGetTurnOrder(gActiveBank);
            }
        }
        if (var == 4)
        {
            if (gBattleMoves[gLastUsedMove].target & MOVE_TARGET_RANDOM)
            {
                if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
                {
                    if (Random() & 1)
                        gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
                    else
                        gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
                }
                else
                {
                    if (Random() & 1)
                        gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON1);
                    else
                        gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON2);
                }
            }
            else
            {
                gBankTarget = *(gBattleStruct->moveTarget + gBankAttacker);
            }

            if (gAbsentBankFlags & gBitTable[gBankTarget])
            {
                if (GetBankSide(gBankAttacker) != GetBankSide(gBankTarget))
                {
                    gBankTarget = GetBankByIdentity(GetBankIdentity(gBankTarget) ^ BIT_MON);
                }
                else
                {
                    gBankTarget = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ BIT_SIDE);
                    if (gAbsentBankFlags & gBitTable[gBankTarget])
                        gBankTarget = GetBankByIdentity(GetBankIdentity(gBankTarget) ^ BIT_MON);
                }
            }
        }
        else
        {
            gActiveBank = gBanksByTurnOrder[var];
            RecordAbilityBattle(gActiveBank, gBattleMons[gActiveBank].ability);
            gSpecialStatuses[gActiveBank].lightningRodRedirected = 1;
            gBankTarget = gActiveBank;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
             && gBattleMoves[gLastUsedMove].target & MOVE_TARGET_RANDOM)
    {
        if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
        {
            if (Random() & 1)
                gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
            else
                gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
        }
        else
        {
            if (Random() & 1)
                gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON1);
            else
                gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON2);
        }

        if (gAbsentBankFlags & gBitTable[gBankTarget]
            && GetBankSide(gBankAttacker) != GetBankSide(gBankTarget))
        {
            gBankTarget = GetBankByIdentity(GetBankIdentity(gBankTarget) ^ BIT_MON);
        }
    }
    else
    {
        gBankTarget = *(gBattleStruct->moveTarget + gBankAttacker);
        if (gAbsentBankFlags & gBitTable[gBankTarget])
        {
            if (GetBankSide(gBankAttacker) != GetBankSide(gBankTarget))
            {
                gBankTarget = GetBankByIdentity(GetBankIdentity(gBankTarget) ^ BIT_MON);
            }
            else
            {
                gBankTarget = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ BIT_SIDE);
                if (gAbsentBankFlags & gBitTable[gBankTarget])
                    gBankTarget = GetBankByIdentity(GetBankIdentity(gBankTarget) ^ BIT_MON);
            }
        }
    }

    // choose battlescript
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE
        && gProtectStructs[gBankAttacker].flag_x10)
    {
        if (gBattleMons[gBankAttacker].hp == 0)
        {
            gCurrentActionFuncId = 12;
            return;
        }
        else if (gUnknown_02024230[gBankAttacker] != NULL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            gBattlescriptCurrInstr = gUnknown_02024230[gBankAttacker];
            gUnknown_02024230[gBankAttacker] = NULL;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
        }
    }
    else
    {
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        sub_81A56E8(gBankAttacker);

    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
}

static void HandleAction_Switch(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBankAttacker] = 0;
    gMoveSelectionCursor[gBankAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBankAttacker, *(gBattleStruct->field_58 + gBankAttacker))

    gBattleScripting.bank = gBankAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;
}

static void HandleAction_UseItem(void)
{
    gBankAttacker = gBankTarget = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    ClearFuryCutterDestinyBondGrudge(gBankAttacker);
    gLastUsedItem = gBattleBufferB[gBankAttacker][1] | (gBattleBufferB[gBankAttacker][2] << 8);

    if (gLastUsedItem <= ITEM_PREMIER_BALL) // is ball
    {
        gBattlescriptCurrInstr = gBattlescriptsForBallThrow[gLastUsedItem];
    }
    else if (gLastUsedItem == ITEM_POKE_DOLL || gLastUsedItem == ITEM_FLUFFY_TAIL)
    {
        gBattlescriptCurrInstr = gBattlescriptsForRunningByItem[0];
    }
    else if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
    {
        gBattlescriptCurrInstr = gUnknown_082DBD3C[0];
    }
    else
    {
        gBattleScripting.bank = gBankAttacker;

        switch (*(gBattleStruct->field_C4 + (gBankAttacker >> 1)))
        {
        case 1:
        case 2:
            break;
        case 3:
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            if (*(gBattleStruct->field_C6 + gBankAttacker / 2) & 1)
            {
                if (*(gBattleStruct->field_C6 + gBankAttacker / 2) & 0x3E)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            }
            else
            {
                while (!(*(gBattleStruct->field_C6 + gBankAttacker / 2) & 1))
                {
                    *(gBattleStruct->field_C6 + gBankAttacker / 2) >>= 1;
                    gBattleCommunication[MULTISTRING_CHOOSER]++;
                }
            }
            break;
        case 4:
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            if (*(gBattleStruct->field_C6 + (gBankAttacker >> 1)) & 0x80)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            }
            else
            {
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK)
                PREPARE_STRING_BUFFER(gBattleTextBuff2, 0xD2)

                while (!((*(gBattleStruct->field_C6 + (gBankAttacker >> 1))) & 1))
                {
                    *(gBattleStruct->field_C6 + gBankAttacker / 2) >>= 1;
                    gBattleTextBuff1[2]++;
                }

                gBattleScripting.animArg1 = gBattleTextBuff1[2] + 14;
                gBattleScripting.animArg2 = 0;
            }
            break;
        case 5:
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            break;
        }

        gBattlescriptCurrInstr = gUnknown_082DBD3C[*(gBattleStruct->field_C4 + gBankAttacker / 2)];
    }
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
}

bool8 TryRunFromBattle(u8 bank)
{
    bool8 effect = FALSE;
    u8 holdEffect;
    u8 pyramidMultiplier;
    u8 speedVar;

    if (gBattleMons[bank].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[bank].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[bank].item);

    gStringBank = bank;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
    {
        gLastUsedItem = gBattleMons[bank].item ;
        gProtectStructs[bank].fleeFlag = 1;
        effect++;
    }
    else if (gBattleMons[bank].ability == ABILITY_RUN_AWAY)
    {
        if (InBattlePyramid())
        {
            gBattleStruct->runTries++;
            pyramidMultiplier = sub_81A9E28();
            speedVar = (gBattleMons[bank].speed * pyramidMultiplier) / (gBattleMons[bank ^ BIT_SIDE].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
            {
                gLastUsedAbility = ABILITY_RUN_AWAY;
                gProtectStructs[bank].fleeFlag = 2;
                effect++;
            }
        }
        else
        {
            gLastUsedAbility = ABILITY_RUN_AWAY;
            gProtectStructs[bank].fleeFlag = 2;
            effect++;
        }
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_x4000000) && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        effect++;
    }
    else
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            if (InBattlePyramid())
            {
                pyramidMultiplier = sub_81A9E28();
                speedVar = (gBattleMons[bank].speed * pyramidMultiplier) / (gBattleMons[bank ^ BIT_SIDE].speed) + (gBattleStruct->runTries * 30);
                if (speedVar > (Random() & 0xFF))
                    effect++;
            }
            else if (gBattleMons[bank].speed < gBattleMons[bank ^ BIT_SIDE].speed)
            {
                speedVar = (gBattleMons[bank].speed * 128) / (gBattleMons[bank ^ BIT_SIDE].speed) + (gBattleStruct->runTries * 30);
                if (speedVar > (Random() & 0xFF))
                    effect++;
            }
            else // same speed or faster
            {
                effect++;
            }
        }

        gBattleStruct->runTries++;
    }

    if (effect)
    {
        gCurrentTurnActionNumber = gNoOfAllBanks;
        gBattleOutcome = BATTLE_RAN;
    }

    return effect;
}

static void HandleAction_Run(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
    {
        gCurrentTurnActionNumber = gNoOfAllBanks;

        for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
        {
            if (GetBankSide(gActiveBank) == SIDE_PLAYER)
            {
                if (gActionForBanks[gActiveBank] == ACTION_RUN)
                    gBattleOutcome |= BATTLE_LOST;
            }
            else
            {
                if (gActionForBanks[gActiveBank] == ACTION_RUN)
                    gBattleOutcome |= BATTLE_WON;
            }
        }

        gBattleOutcome |= BATTLE_OUTCOME_BIT_x80;
        gSaveBlock2Ptr->field_CA9_b = 1;
    }
    else
    {
        if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
        {
            if (!TryRunFromBattle(gBankAttacker)) // failed to run away
            {
                ClearFuryCutterDestinyBondGrudge(gBankAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
            }
        }
        else
        {
            if (gBattleMons[gBankAttacker].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
            }
            else
            {
                gCurrentTurnActionNumber = gNoOfAllBanks;
                gBattleOutcome = BATTLE_POKE_FLED;
            }
        }
    }
}

static void HandleAction_WatchesCarefully(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
}

static void HandleAction_SafariZoneBallThrow(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gNumSafariBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = gBattlescriptsForBallThrow[ITEM_SAFARI_BALL];
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
}

static void HandleAction_ThrowPokeblock(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleBufferB[gBankAttacker][1] - 1;
    gLastUsedItem = gBattleBufferB[gBankAttacker][2];

    if (gBattleResults.field_1F < 0xFF)
        gBattleResults.field_1F++;
    if (gBattleStruct->field_7A < 3)
        gBattleStruct->field_7A++;
    if (gBattleStruct->field_7B > 1)
    {
        if (gBattleStruct->field_7B < sUnknown_0831BCE0[gBattleStruct->field_7A][gBattleCommunication[MULTISTRING_CHOOSER]])
            gBattleStruct->field_7B = 1;
        else
            gBattleStruct->field_7B -= sUnknown_0831BCE0[gBattleStruct->field_7A][gBattleCommunication[MULTISTRING_CHOOSER]];
    }

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
}

static void HandleAction_GoNear(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->field_7C += sUnknown_0831BCEF[gBattleStruct->field_79];
    if (gBattleStruct->field_7C > 20)
        gBattleStruct->field_7C = 20;

    gBattleStruct->field_7B +=sUnknown_0831BCF3[gBattleStruct->field_79];
    if (gBattleStruct->field_7B > 20)
        gBattleStruct->field_7B = 20;

    if (gBattleStruct->field_79 < 3)
    {
        gBattleStruct->field_79++;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
}

static void HandleAction_SafriZoneRun(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_NIGERU);
    gCurrentTurnActionNumber = gNoOfAllBanks;
    gBattleOutcome = BATTLE_RAN;
}

static void HandleAction_Action9(void)
{
    gBankAttacker = gBanksByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBankAttacker, gBattlePartyID[gBankAttacker])

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[3];
    gCurrentActionFuncId = ACTION_RUN_BATTLESCRIPT;
    gActionsByTurnOrder[1] = ACTION_FINISHED;
}

static void HandleAction_Action11(void)
{
    if (!sub_8041728())
    {
        gBattleStruct->field_4D = 0;
        gCurrentActionFuncId = ACTION_FINISHED;
    }
}

static void HandleAction_NothingIsFainted(void)
{
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_IGNORE_ON_AIR
                    | HITMARKER_IGNORE_UNDERGROUND | HITMARKER_IGNORE_UNDERWATER | HITMARKER_x100000
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_x8000000 | HITMARKER_x4000000);
}

static void HandleAction_ActionFinished(void)
{
    *(gBattleStruct->field_5C + gBanksByTurnOrder[gCurrentTurnActionNumber]) = 6;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_IGNORE_ON_AIR
                    | HITMARKER_IGNORE_UNDERGROUND | HITMARKER_IGNORE_UNDERWATER | HITMARKER_x100000
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_x8000000 | HITMARKER_x4000000);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gBattleMoveFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gUnknown_02024250[gBankAttacker] = 0;
    gUnknown_02024258[gBankAttacker] = 0;
    gBattleStruct->dynamicMoveType = 0;
    gDynamicBasePower = 0;
    gBattleScripting.atk49_state = 0;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.field_16 = 0;
    gBattleResources->battleScriptsStack->size = 0;
}
