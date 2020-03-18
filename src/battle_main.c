#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_pyramid.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "berry.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "roamer.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "cable_club.h"

extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;

extern const struct BgTemplate gBattleBgTemplates[];
extern const struct WindowTemplate *const gBattleWindowTemplates[];
extern const u8 *const gBattleScriptsForMoveEffects[];
extern const u8 *const gBattlescriptsForBallThrow[];
extern const u8 *const gBattlescriptsForRunningByItem[];
extern const u8 *const gBattlescriptsForUsingItem[];
extern const u8 *const gBattlescriptsForSafariActions[];

// this file's functions
#if !defined(NONMATCHING) && MODERN
#define static
#endif
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
static void SpriteCb_MoveWildMonToRight(struct Sprite *sprite);
static void SpriteCb_WildMonShowHealthbox(struct Sprite *sprite);
static void SpriteCb_WildMonAnimate(struct Sprite *sprite);
static void sub_80398D0(struct Sprite *sprite);
static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite);
static void sub_8039AF4(struct Sprite *sprite);
static void SpriteCallbackDummy_3(struct Sprite *sprite);
static void oac_poke_ally_(struct Sprite *sprite);
static void SpecialStatusesClear(void);
static void TurnValuesCleanUp(bool8 var0);
static void SpriteCB_BounceEffect(struct Sprite *sprite);
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
static void SetActionsAndBattlersTurnOrder(void);
static void sub_803CDF8(void);
static bool8 AllAtActionConfirmed(void);
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
static void HandleAction_SafariZoneRun(void);
static void HandleAction_WallyBallThrow(void);
static void HandleAction_TryFinish(void);
static void HandleAction_NothingIsFainted(void);
static void HandleAction_ActionFinished(void);

// EWRAM vars
EWRAM_DATA u16 gBattle_BG0_X = 0;
EWRAM_DATA u16 gBattle_BG0_Y = 0;
EWRAM_DATA u16 gBattle_BG1_X = 0;
EWRAM_DATA u16 gBattle_BG1_Y = 0;
EWRAM_DATA u16 gBattle_BG2_X = 0;
EWRAM_DATA u16 gBattle_BG2_Y = 0;
EWRAM_DATA u16 gBattle_BG3_X = 0;
EWRAM_DATA u16 gBattle_BG3_Y = 0;
EWRAM_DATA u16 gBattle_WIN0H = 0;
EWRAM_DATA u16 gBattle_WIN0V = 0;
EWRAM_DATA u16 gBattle_WIN1H = 0;
EWRAM_DATA u16 gBattle_WIN1V = 0;
EWRAM_DATA u8 gDisplayedStringBattle[300] = {0};
EWRAM_DATA u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA static u32 sUnusedUnknownArray[25] = {0};
EWRAM_DATA u32 gBattleTypeFlags = 0;
EWRAM_DATA u8 gBattleTerrain = 0;
EWRAM_DATA u32 gUnknown_02022FF4 = 0;
EWRAM_DATA struct UnknownPokemonStruct4 gMultiPartnerParty[MULTI_PARTY_SIZE] = {0};
EWRAM_DATA static struct UnknownPokemonStruct4* sMultiPartnerPartyBuffer = NULL;
EWRAM_DATA u8 *gUnknown_0202305C = NULL;
EWRAM_DATA u8 *gUnknown_02023060 = NULL;
EWRAM_DATA u8 gBattleBufferA[MAX_BATTLERS_COUNT][0x200] = {0};
EWRAM_DATA u8 gBattleBufferB[MAX_BATTLERS_COUNT][0x200] = {0};
EWRAM_DATA u8 gActiveBattler = 0;
EWRAM_DATA u32 gBattleControllerExecFlags = 0;
EWRAM_DATA u8 gBattlersCount = 0;
EWRAM_DATA u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerPositions[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrentTurnActionNumber = 0;
EWRAM_DATA u8 gCurrentActionFuncId = 0;
EWRAM_DATA struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerSpriteIds[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrMovePos = 0;
EWRAM_DATA u8 gChosenMovePos = 0;
EWRAM_DATA u16 gCurrentMove = 0;
EWRAM_DATA u16 gChosenMove = 0;
EWRAM_DATA u16 gCalledMove = 0;
EWRAM_DATA s32 gBattleMoveDamage = 0;
EWRAM_DATA s32 gHpDealt = 0;
EWRAM_DATA s32 gTakenDmg[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedItem = 0;
EWRAM_DATA u8 gLastUsedAbility = 0;
EWRAM_DATA u8 gBattlerAttacker = 0;
EWRAM_DATA u8 gBattlerTarget = 0;
EWRAM_DATA u8 gBattlerFainted = 0;
EWRAM_DATA u8 gEffectBattler = 0;
EWRAM_DATA u8 gPotentialItemEffectBattler = 0;
EWRAM_DATA u8 gAbsentBattlerFlags = 0;
EWRAM_DATA u8 gCritMultiplier = 0;
EWRAM_DATA u8 gMultiHitCounter = 0;
EWRAM_DATA const u8 *gBattlescriptCurrInstr = NULL;
EWRAM_DATA u32 gUnusedBattleMainVar = 0;
EWRAM_DATA u8 gChosenActionByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA const u8 *gSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA const u8 *gPalaceSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA u16 gLastPrintedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastLandedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastHitByType[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastResultingMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLockedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gLastHitBy[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gChosenMoveByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gMoveResultFlags = 0;
EWRAM_DATA u32 gHitMarker = 0;
EWRAM_DATA static u8 sUnusedBattlersArray[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gTakenDmgByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gUnknown_0202428C = 0;
EWRAM_DATA u16 gSideStatuses[2] = {0};
EWRAM_DATA struct SideTimer gSideTimers[2] = {0};
EWRAM_DATA u32 gStatuses3[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct DisableStruct gDisableStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gPauseCounterBattle = 0;
EWRAM_DATA u16 gPaydayMoney = 0;
EWRAM_DATA u16 gRandomTurnNumber = 0;
EWRAM_DATA u8 gBattleCommunication[BATTLE_COMMUNICATION_ENTRIES_COUNT] = {0};
EWRAM_DATA u8 gBattleOutcome = 0;
EWRAM_DATA struct ProtectStruct gProtectStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct SpecialStatus gSpecialStatuses[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gBattleWeather = 0;
EWRAM_DATA struct WishFutureKnock gWishFutureKnock = {0};
EWRAM_DATA u16 gIntroSlideFlags = 0;
EWRAM_DATA u8 gSentPokesToOpponent[2] = {0};
EWRAM_DATA u16 gDynamicBasePower = 0;
EWRAM_DATA u16 gExpShareExp = 0;
EWRAM_DATA struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleScripting gBattleScripting = {0};
EWRAM_DATA struct BattleStruct *gBattleStruct = NULL;
EWRAM_DATA u8 *gLinkBattleSendBuffer = NULL;
EWRAM_DATA u8 *gLinkBattleRecvBuffer = NULL;
EWRAM_DATA struct BattleResources *gBattleResources = NULL;
EWRAM_DATA u8 gActionSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gMoveSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerStatusSummaryTaskId[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerInMenuId = 0;
EWRAM_DATA bool8 gDoingBattleAnim = FALSE;
EWRAM_DATA u32 gTransformedPersonalities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gPlayerDpadHoldFrames = 0;
EWRAM_DATA struct BattleSpriteData *gBattleSpritesDataPtr = NULL;
EWRAM_DATA struct MonSpritesGfx *gMonSpritesGfxPtr = NULL;
EWRAM_DATA struct BattleHealthboxInfo *gUnknown_020244D8 = NULL;
EWRAM_DATA struct BattleHealthboxInfo *gUnknown_020244DC = NULL;
EWRAM_DATA u16 gBattleMovePower = 0;
EWRAM_DATA u16 gMoveToLearn = 0;
EWRAM_DATA u8 gBattleMonForms[MAX_BATTLERS_COUNT] = {0};

// IWRAM common vars
void (*gPreBattleCallback1)(void);
void (*gBattleMainFunc)(void);
struct BattleResults gBattleResults;
u8 gLeveledUpInBattle;
void (*gBattlerControllerFuncs[MAX_BATTLERS_COUNT])(void);
u8 gHealthboxSpriteIds[MAX_BATTLERS_COUNT];
u8 gMultiUsePlayerCursor;
u8 gNumberOfMovesToChoose;
u8 gUnknown_03005D7C[MAX_BATTLERS_COUNT];

// rom const data
static const struct ScanlineEffectParams sIntroScanlineParams16Bit =
{
    (void *)REG_ADDR_BG3HOFS, SCANLINE_EFFECT_DMACNT_16BIT, 1
};

// unused
static const struct ScanlineEffectParams sIntroScanlineParams32Bit =
{
    (void *)REG_ADDR_BG3HOFS, SCANLINE_EFFECT_DMACNT_32BIT, 1
};

const struct SpriteTemplate gUnknown_0831AC88 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8038528,
};

static const u8 sText_ShedinjaJpnName[] = _("ヌケニン"); // Nukenin

const struct OamData gOamData_831ACA8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct OamData gOamData_831ACB0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 2,
    .affineParam = 0,
};

// Unknown and unused data. Feel free to remove.
static const u16 gUnknown_0831ACB8[] = {0, 5, 0xfffe, 0};
static const u16 *const gUnknown_0831ACC0 = gUnknown_0831ACB8;
static const u16 gUnknown_0831ACC4[] = {0xfff0, 0, 0x0400, 0, 0, 0, 0x3c00, 0, 0x7ffe, 1, 0, 0};
static const u16 *const gUnknown_0831ACDC = gUnknown_0831ACC4;

static const s8 gUnknown_0831ACE0[] ={-32, -16, -16, -32, -32, 0, 0, 0};

// format: attacking type, defending type, damage multiplier
// the multiplier is a (decimal) fixed-point number:
// 20 is ×2.0 TYPE_MUL_SUPER_EFFECTIVE
// 10 is ×1.0 TYPE_MUL_NORMAL
// 05 is ×0.5 TYPE_MUL_NOT_EFFECTIVE
// 00 is ×0.0 TYPE_MUL_NO_EFFECT
const u8 gTypeEffectiveness[336] =
{
    TYPE_NORMAL, TYPE_ROCK, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_NORMAL, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIRE, TYPE_FIRE, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIRE, TYPE_WATER, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIRE, TYPE_GRASS, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIRE, TYPE_ICE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIRE, TYPE_BUG, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIRE, TYPE_ROCK, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIRE, TYPE_DRAGON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIRE, TYPE_STEEL, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_WATER, TYPE_FIRE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_WATER, TYPE_WATER, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_WATER, TYPE_GRASS, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_WATER, TYPE_GROUND, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_WATER, TYPE_ROCK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_WATER, TYPE_DRAGON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ELECTRIC, TYPE_WATER, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ELECTRIC, TYPE_ELECTRIC, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ELECTRIC, TYPE_GRASS, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ELECTRIC, TYPE_GROUND, TYPE_MUL_NO_EFFECT,
    TYPE_ELECTRIC, TYPE_FLYING, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ELECTRIC, TYPE_DRAGON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_FIRE, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_WATER, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GRASS, TYPE_GRASS, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_POISON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_GROUND, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GRASS, TYPE_FLYING, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_BUG, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_ROCK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GRASS, TYPE_DRAGON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GRASS, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ICE, TYPE_WATER, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ICE, TYPE_GRASS, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ICE, TYPE_ICE, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ICE, TYPE_GROUND, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ICE, TYPE_FLYING, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ICE, TYPE_DRAGON, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ICE, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ICE, TYPE_FIRE, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIGHTING, TYPE_NORMAL, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIGHTING, TYPE_ICE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIGHTING, TYPE_POISON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIGHTING, TYPE_FLYING, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIGHTING, TYPE_PSYCHIC, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIGHTING, TYPE_BUG, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FIGHTING, TYPE_ROCK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIGHTING, TYPE_DARK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FIGHTING, TYPE_STEEL, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_POISON, TYPE_GRASS, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_POISON, TYPE_POISON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_POISON, TYPE_GROUND, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_POISON, TYPE_ROCK, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_POISON, TYPE_GHOST, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_POISON, TYPE_STEEL, TYPE_MUL_NO_EFFECT,
    TYPE_GROUND, TYPE_FIRE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GROUND, TYPE_ELECTRIC, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GROUND, TYPE_GRASS, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GROUND, TYPE_POISON, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GROUND, TYPE_FLYING, TYPE_MUL_NO_EFFECT,
    TYPE_GROUND, TYPE_BUG, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GROUND, TYPE_ROCK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GROUND, TYPE_STEEL, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FLYING, TYPE_ELECTRIC, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FLYING, TYPE_GRASS, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FLYING, TYPE_FIGHTING, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FLYING, TYPE_BUG, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_FLYING, TYPE_ROCK, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FLYING, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_PSYCHIC, TYPE_FIGHTING, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_PSYCHIC, TYPE_POISON, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_PSYCHIC, TYPE_PSYCHIC, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_PSYCHIC, TYPE_DARK, TYPE_MUL_NO_EFFECT,
    TYPE_PSYCHIC, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_BUG, TYPE_FIRE, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_BUG, TYPE_GRASS, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_BUG, TYPE_FIGHTING, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_BUG, TYPE_POISON, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_BUG, TYPE_FLYING, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_BUG, TYPE_PSYCHIC, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_BUG, TYPE_GHOST, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_BUG, TYPE_DARK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_BUG, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ROCK, TYPE_FIRE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ROCK, TYPE_ICE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ROCK, TYPE_FIGHTING, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ROCK, TYPE_GROUND, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_ROCK, TYPE_FLYING, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ROCK, TYPE_BUG, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_ROCK, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GHOST, TYPE_NORMAL, TYPE_MUL_NO_EFFECT,
    TYPE_GHOST, TYPE_PSYCHIC, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_GHOST, TYPE_DARK, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GHOST, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_GHOST, TYPE_GHOST, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_DRAGON, TYPE_DRAGON, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_DRAGON, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_DARK, TYPE_FIGHTING, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_DARK, TYPE_PSYCHIC, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_DARK, TYPE_GHOST, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_DARK, TYPE_DARK, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_DARK, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_STEEL, TYPE_FIRE, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_STEEL, TYPE_WATER, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_STEEL, TYPE_ELECTRIC, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_STEEL, TYPE_ICE, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_STEEL, TYPE_ROCK, TYPE_MUL_SUPER_EFFECTIVE,
    TYPE_STEEL, TYPE_STEEL, TYPE_MUL_NOT_EFFECTIVE,
    TYPE_FORESIGHT, TYPE_FORESIGHT, TYPE_MUL_NO_EFFECT,
    TYPE_NORMAL, TYPE_GHOST, TYPE_MUL_NO_EFFECT,
    TYPE_FIGHTING, TYPE_GHOST, TYPE_MUL_NO_EFFECT,
    TYPE_ENDTABLE, TYPE_ENDTABLE, TYPE_MUL_NO_EFFECT
};

const u8 gTypeNames[NUMBER_OF_MON_TYPES][TYPE_NAME_LENGTH + 1] =
{
    _("NORMAL"),
    _("FIGHT"),
    _("FLYING"),
    _("POISON"),
    _("GROUND"),
    _("ROCK"),
    _("BUG"),
    _("GHOST"),
    _("STEEL"),
    _("???"),
    _("FIRE"),
    _("WATER"),
    _("GRASS"),
    _("ELECTR"),
    _("PSYCHC"),
    _("ICE"),
    _("DRAGON"),
    _("DARK"),
};

// This is a factor in how much money you get for beating a trainer.
const struct TrainerMoney gTrainerMoneyTable[] =
{
    {TRAINER_CLASS_TEAM_AQUA, 5},
    {TRAINER_CLASS_AQUA_ADMIN, 10},
    {TRAINER_CLASS_AQUA_LEADER, 20},
    {TRAINER_CLASS_AROMA_LADY, 10},
    {TRAINER_CLASS_RUIN_MANIAC, 15},
    {TRAINER_CLASS_INTERVIEWER, 12},
    {TRAINER_CLASS_TUBER_F, 1},
    {TRAINER_CLASS_TUBER_M, 1},
    {TRAINER_CLASS_SIS_AND_BRO, 3},
    {TRAINER_CLASS_COOLTRAINER, 12},
    {TRAINER_CLASS_HEX_MANIAC, 6},
    {TRAINER_CLASS_LADY, 50},
    {TRAINER_CLASS_BEAUTY, 20},
    {TRAINER_CLASS_RICH_BOY, 50},
    {TRAINER_CLASS_POKEMANIAC, 15},
    {TRAINER_CLASS_SWIMMER_M, 2},
    {TRAINER_CLASS_BLACK_BELT, 8},
    {TRAINER_CLASS_GUITARIST, 8},
    {TRAINER_CLASS_KINDLER, 8},
    {TRAINER_CLASS_CAMPER, 4},
    {TRAINER_CLASS_OLD_COUPLE, 10},
    {TRAINER_CLASS_BUG_MANIAC, 15},
    {TRAINER_CLASS_PSYCHIC, 6},
    {TRAINER_CLASS_GENTLEMAN, 20},
    {TRAINER_CLASS_ELITE_FOUR, 25},
    {TRAINER_CLASS_LEADER, 25},
    {TRAINER_CLASS_SCHOOL_KID, 5},
    {TRAINER_CLASS_SR_AND_JR, 4},
    {TRAINER_CLASS_POKEFAN, 20},
    {TRAINER_CLASS_EXPERT, 10},
    {TRAINER_CLASS_YOUNGSTER, 4},
    {TRAINER_CLASS_CHAMPION, 50},
    {TRAINER_CLASS_FISHERMAN, 10},
    {TRAINER_CLASS_TRIATHLETE, 10},
    {TRAINER_CLASS_DRAGON_TAMER, 12},
    {TRAINER_CLASS_BIRD_KEEPER, 8},
    {TRAINER_CLASS_NINJA_BOY, 3},
    {TRAINER_CLASS_BATTLE_GIRL, 6},
    {TRAINER_CLASS_PARASOL_LADY, 10},
    {TRAINER_CLASS_SWIMMER_F, 2},
    {TRAINER_CLASS_PICNICKER, 4},
    {TRAINER_CLASS_TWINS, 3},
    {TRAINER_CLASS_SAILOR, 8},
    {TRAINER_CLASS_COLLECTOR, 15},
    {TRAINER_CLASS_PKMN_TRAINER_3, 15},
    {TRAINER_CLASS_PKMN_BREEDER, 10},
    {TRAINER_CLASS_PKMN_RANGER, 12},
    {TRAINER_CLASS_TEAM_MAGMA, 5},
    {TRAINER_CLASS_MAGMA_ADMIN, 10},
    {TRAINER_CLASS_MAGMA_LEADER, 20},
    {TRAINER_CLASS_LASS, 4},
    {TRAINER_CLASS_BUG_CATCHER, 4},
    {TRAINER_CLASS_HIKER, 10},
    {TRAINER_CLASS_YOUNG_COUPLE, 8},
    {TRAINER_CLASS_WINSTRATE, 10},
    {0xFF, 5},
};

#include "data/text/abilities.h"

static void (* const sTurnActionsFuncsTable[])(void) =
{
    [B_ACTION_USE_MOVE] = HandleAction_UseMove,
    [B_ACTION_USE_ITEM] = HandleAction_UseItem,
    [B_ACTION_SWITCH] = HandleAction_Switch,
    [B_ACTION_RUN] = HandleAction_Run,
    [B_ACTION_SAFARI_WATCH_CAREFULLY] = HandleAction_WatchesCarefully,
    [B_ACTION_SAFARI_BALL] = HandleAction_SafariZoneBallThrow,
    [B_ACTION_SAFARI_POKEBLOCK] = HandleAction_ThrowPokeblock,
    [B_ACTION_SAFARI_GO_NEAR] = HandleAction_GoNear,
    [B_ACTION_SAFARI_RUN] = HandleAction_SafariZoneRun,
    [B_ACTION_WALLY_THROW] = HandleAction_WallyBallThrow,
    [B_ACTION_EXEC_SCRIPT] = HandleAction_RunBattleScript,
    [B_ACTION_TRY_FINISH] = HandleAction_TryFinish,
    [B_ACTION_FINISHED] = HandleAction_ActionFinished,
    [B_ACTION_NOTHING_FAINTED] = HandleAction_NothingIsFainted,
};

static void (* const sEndTurnFuncsTable[])(void) =
{
    [0] = HandleEndTurn_ContinueBattle, //B_OUTCOME_NONE?
    [B_OUTCOME_WON] = HandleEndTurn_BattleWon,
    [B_OUTCOME_LOST] = HandleEndTurn_BattleLost,
    [B_OUTCOME_DREW] = HandleEndTurn_BattleLost,
    [B_OUTCOME_RAN] = HandleEndTurn_RanFromBattle,
    [B_OUTCOME_PLAYER_TELEPORTED] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_FLED] = HandleEndTurn_MonFled,
    [B_OUTCOME_CAUGHT] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_NO_SAFARI_BALLS] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_FORFEITED] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_TELEPORTED] = HandleEndTurn_FinishBattle,
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

static const u8 sPkblToEscapeFactor[][3] = {{0, 0, 0}, {3, 5, 0}, {2, 3, 0}, {1, 2, 0}, {1, 1, 0}};
static const u8 sGoNearCounterToCatchFactor[] = {4, 3, 2, 1};
static const u8 sGoNearCounterToEscapeFactor[] = {4, 4, 4, 4};

// code
void CB2_InitBattle(void)
{
    MoveSaveBlocks_ResetHeap();
    AllocateBattleResources();
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

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId != TRAINER_STEVEN_PARTNER)
    {
        gBattle_WIN0V = 159;
        gBattle_WIN1H = 240;
        gBattle_WIN1V = 32;
    }
    else
    {
        gBattle_WIN0V = 0x5051;
        ScanlineEffect_Clear();

        i = 0;
        while (i < 80)
        {
            gScanlineEffectRegBuffers[0][i] = 0xF0;
            gScanlineEffectRegBuffers[1][i] = 0xF0;
            i++;
        }

        while (i < 160)
        {
            gScanlineEffectRegBuffers[0][i] = 0xFF10;
            gScanlineEffectRegBuffers[1][i] = 0xFF10;
            i++;
        }

        ScanlineEffect_SetParams(sIntroScanlineParams16Bit);
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
        gBattleTerrain = BATTLE_TERRAIN_BUILDING;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    DrawBattleEntryBackground();
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
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
        AdjustFriendship(&gPlayerParty[i], FRIENDSHIP_EVENT_LEAGUE_BATTLE);

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

static void sub_8036A5C(void)
{
    u16 r6 = 0;
    u16 species = 0;
    u16 hp = 0;
    u32 status = 0;
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
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
    gBattleStruct->field_183 |= FlagGet(FLAG_SYS_FRONTIER_PASS) << 7;
}

static void SetPlayerBerryDataInBattleStruct(void)
{
    s32 i;
    struct BattleStruct *battleStruct = gBattleStruct;
    struct BattleEnigmaBerry *battleBerry = &battleStruct->battleEnigmaBerry;

    if (IsEnigmaBerryValid() == TRUE)
    {
        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];

        battleBerry->holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        battleBerry->holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
    }
    else
    {
        const struct Berry *berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY));

        for (i = 0; i < BERRY_NAME_LENGTH; i++)
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
            for (i = 0; i < BERRY_NAME_LENGTH; i++)
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
            const struct Berry *berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY));

            for (i = 0; i < BERRY_NAME_LENGTH; i++)
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
        u8 battlerId;

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = 4;

            for (i = 0; i < numPlayers; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);
                battlerId = gLinkPlayers[i].id;

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
                    gEnigmaBerries[battlerId].name[j] = src->name[j];
                gEnigmaBerries[battlerId].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                    gEnigmaBerries[battlerId].itemEffect[j] = src->itemEffect[j];

                gEnigmaBerries[battlerId].holdEffect = src->holdEffect;
                gEnigmaBerries[battlerId].holdEffectParam = src->holdEffectParam;
            }
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
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
            gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
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
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
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
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
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
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (IsLinkTaskFinished())
                {
                    *(&gBattleStruct->field_180) = 0;
                    *(&gBattleStruct->field_181) = 3;
                    sub_8036A5C();
                    SetPlayerBerryDataInBattleStruct();

                    if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
                    {
                        gLinkPlayers[0].id = 0;
                        gLinkPlayers[1].id = 1;
                    }

                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->field_180, 32);
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }
                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
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
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = gBattleStruct->field_182 | (gBattleStruct->field_183 << 8);
            gTasks[taskId].data[4] = gBlockRecvBuffer[enemyMultiplayerId][1];
            sub_8185F90(gBlockRecvBuffer[playerMultiplayerId][1]);
            sub_8185F90(gBlockRecvBuffer[enemyMultiplayerId][1]);
            SetDeoxysStats();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
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
        if (IsLinkTaskFinished())
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
        if (IsLinkTaskFinished())
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

            for (i = 0; i < 2 && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

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
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 17:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
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
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        // fall through
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                u8 language;

                gLinkPlayers[0].id = 0;
                gLinkPlayers[1].id = 2;
                gLinkPlayers[2].id = 1;
                gLinkPlayers[3].id = 3;
                GetFrontierTrainerName(gLinkPlayers[2].name, gTrainerBattleOpponent_A);
                GetFrontierTrainerName(gLinkPlayers[3].name, gTrainerBattleOpponent_B);
                GetBattleTowerTrainerLanguage(&language, gTrainerBattleOpponent_A);
                gLinkPlayers[2].language = language;
                GetBattleTowerTrainerLanguage(&language, gTrainerBattleOpponent_B);
                gLinkPlayers[3].language = language;

                if (IsLinkTaskFinished())
                {
                    *(&gBattleStruct->field_180) = 0;
                    *(&gBattleStruct->field_181) = 3;
                    sub_8036A5C();
                    SetPlayerBerryDataInBattleStruct();
                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->field_180, 32);
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }

                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
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
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = 0x145;
            gTasks[taskId].data[4] = 0x145;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].id != 0)
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            else
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].id != 0)
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
        if (IsLinkTaskFinished())
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
        if (IsLinkTaskFinished())
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
        if (IsLinkTaskFinished())
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
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
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

    for (i = 0; i < (int)ARRAY_COUNT(gMultiPartnerParty); i++)
    {
        gMultiPartnerParty[i].species     = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_SPECIES);
        gMultiPartnerParty[i].heldItem    = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_HELD_ITEM);
        GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_NICKNAME, gMultiPartnerParty[i].nickname);
        gMultiPartnerParty[i].level       = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_LEVEL);
        gMultiPartnerParty[i].hp          = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_HP);
        gMultiPartnerParty[i].maxhp       = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_MAX_HP);
        gMultiPartnerParty[i].status      = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_STATUS);
        gMultiPartnerParty[i].personality = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_PERSONALITY);
        gMultiPartnerParty[i].gender      = GetMonGender(&gPlayerParty[arrayIdPlus + i]);
        StripExtCtrlCodes(gMultiPartnerParty[i].nickname);
        if (GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
            PadNameString(gMultiPartnerParty[i].nickname, CHAR_SPACE);
    }
    memcpy(sMultiPartnerPartyBuffer, gMultiPartnerParty, sizeof(gMultiPartnerParty));
}

static void CB2_PreInitMultiBattle(void)
{
    s32 i;
    u8 playerMultiplierId;
    s32 numPlayers = 4;
    u8 r4 = 0xF;
    u32 *savedBattleTypeFlags;
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
        if (gReceivedRemoteLinkPlayers != 0 && IsLinkTaskFinished())
        {
            sMultiPartnerPartyBuffer = Alloc(sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
            sub_80379F8(0);
            SendBlock(bitmask_all_link_players_but_self(), sMultiPartnerPartyBuffer, sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
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

                if (numPlayers == MAX_LINK_PLAYERS)
                {
                    if ((!(gLinkPlayers[i].id & 1) && !(gLinkPlayers[playerMultiplierId].id & 1))
                        || (gLinkPlayers[i].id & 1 && gLinkPlayers[playerMultiplierId].id & 1))
                    {
                        memcpy(gMultiPartnerParty, gBlockRecvBuffer[i], sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
                    }
                }
                else
                {
                    memcpy(gMultiPartnerParty, gBlockRecvBuffer[i], sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
            *savedCallback = gMain.savedCallback;
            *savedBattleTypeFlags = gBattleTypeFlags;
            gMain.savedCallback = CB2_PreInitMultiBattle;
            ShowPartyMenuToShowcaseMultiBattleParty();
        }
        break;
    case 2:
        if (IsLinkTaskFinished() && !gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE]++;
            if (gWirelessCommType)
                sub_800ADF8();
            else
                sub_800AC34();
        }
        break;
    case 3:
        if (gWirelessCommType)
        {
            if (IsLinkRfuTaskFinished())
            {
                gBattleTypeFlags = *savedBattleTypeFlags;
                gMain.savedCallback = *savedCallback;
                SetMainCallback2(CB2_InitBattleInternal);
                Free(sMultiPartnerPartyBuffer);
                sMultiPartnerPartyBuffer = NULL;
            }
        }
        else if (gReceivedRemoteLinkPlayers == 0)
        {
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            Free(sMultiPartnerPartyBuffer);
            sMultiPartnerPartyBuffer = NULL;
        }
        break;
    }
}

static void CB2_PreInitIngamePlayerPartnerBattle(void)
{
    u32 *savedBattleTypeFlags;
    void (**savedCallback)(void);

    savedCallback = &gBattleStruct->savedCallback;
    savedBattleTypeFlags = &gBattleStruct->savedBattleTypeFlags;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        sMultiPartnerPartyBuffer = Alloc(sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
        sub_80379F8(3);
        gBattleCommunication[MULTIUSE_STATE]++;
        *savedCallback = gMain.savedCallback;
        *savedBattleTypeFlags = gBattleTypeFlags;
        gMain.savedCallback = CB2_PreInitIngamePlayerPartnerBattle;
        ShowPartyMenuToShowcaseMultiBattleParty();
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE] = 2;
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            Free(sMultiPartnerPartyBuffer);
            sMultiPartnerPartyBuffer = NULL;
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
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (IsLinkTaskFinished())
                {
                    *(&gBattleStruct->field_180) = 0;
                    *(&gBattleStruct->field_181) = 3;
                    sub_8036A5C();
                    SetPlayerBerryDataInBattleStruct();

                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->field_180, 32);
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
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
            SetDeoxysStats();
            var = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[var].data[1] = 0x10E;
            gTasks[var].data[2] = 0x5A;
            gTasks[var].data[5] = 0;
            gTasks[var].data[3] = 0;
            gTasks[var].data[4] = 0;

            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                sub_8185F90(gBlockRecvBuffer[id][1]);
                switch (gLinkPlayers[id].id)
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
        if (IsLinkTaskFinished())
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
                    switch (gLinkPlayers[id].id)
                    {
                    case 0:
                    case 3:
                        memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    case 1:
                    case 2:
                        memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                     || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1)))
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gEnemyParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gEnemyParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
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
                    switch (gLinkPlayers[id].id)
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
                    if ((!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                     || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1)))
                    {
                        switch (gLinkPlayers[id].id)
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
                        switch (gLinkPlayers[id].id)
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
            for (id = 0; id < MAX_LINK_PLAYERS && (gLinkPlayers[id].version & 0xFF) == VERSION_EMERALD; id++);

            if (id == MAX_LINK_PLAYERS)
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
        if (IsLinkTaskFinished())
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
                gTrainerBattleOpponent_A = TRAINER_LINK_OPPONENT;
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
        gSpecialVar_Result = gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED;
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        SetMainCallback2(CB2_QuitRecordedBattle);
    }
}

static void FreeRestoreBattleData(void)
{
    gMain.callback1 = gPreBattleCallback1;
    gScanlineEffect.state = 3;
    gMain.inBattle = 0;
    ZeroEnemyPartyMons();
    m4aSongNumStop(SE_HINSI);
    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
}

void CB2_QuitRecordedBattle(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
        FreeRestoreBattleData();
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

void sub_8038528(struct Sprite* sprite)
{
    sprite->data[0] = 0;
    sprite->callback = sub_8038538;
}

static void sub_8038538(struct Sprite *sprite)
{
    u16 *arr = (u16*)(gDecompressionBuffer);

    switch (sprite->data[0])
    {
    case 0:
        sprite->data[0]++;
        sprite->data[1] = 0;
        sprite->data[2] = 0x281;
        sprite->data[3] = 0;
        sprite->data[4] = 1;
        // fall through
    case 1:
        sprite->data[4]--;
        if (sprite->data[4] == 0)
        {
            s32 i;
            s32 r2;
            s32 r0;

            sprite->data[4] = 2;
            r2 = sprite->data[1] + sprite->data[3] * 32;
            r0 = sprite->data[2] - sprite->data[3] * 32;
            for (i = 0; i < 29; i += 2)
            {
                arr[r2 + i] = 0x3D;
                arr[r0 + i] = 0x3D;
            }
            sprite->data[3]++;
            if (sprite->data[3] == 21)
            {
                sprite->data[0]++;
                sprite->data[1] = 32;
            }
        }
        break;
    case 2:
        sprite->data[1]--;
        if (sprite->data[1] == 20)
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

    if (trainerNum == TRAINER_SECRET_BASE)
        return 0;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER
                                                                        | BATTLE_TYPE_EREADER_TRAINER
                                                                        | BATTLE_TYPE_TRAINER_HILL)))
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

            for (j = 0; gTrainers[trainerNum].trainerName[j] != EOS; j++)
                nameHash += gTrainers[trainerNum].trainerName[j];

            switch (gTrainers[trainerNum].partyFlags)
            {
            case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *partyData = gTrainers[trainerNum].party.NoItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *partyData = gTrainers[trainerNum].party.NoItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                for (j = 0; j < MAX_MON_MOVES; j++)
                {
                    SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&party[i], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *partyData = gTrainers[trainerNum].party.ItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);
                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *partyData = gTrainers[trainerNum].party.ItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * 31 / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

                for (j = 0; j < MAX_MON_MOVES; j++)
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
    // Change gRngSeed every vblank unless the battle could be recorded.
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
    ScanlineEffect_InitHBlankDmaTransfer();
}

void nullsub_17(struct Sprite *sprite)
{

}

static void sub_8038B04(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->pos1.x = sprite->data[1] + ((sprite->data[2] & 0xFF00) >> 8);
    else
        sprite->pos1.x = sprite->data[1] - ((sprite->data[2] & 0xFF00) >> 8);

    sprite->data[2] += 0x180;

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
        switch (gLinkPlayers[r2].id)
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
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&sp4[i], MON_DATA_SPECIES2);
        u16 hp = GetMonData(&sp4[i], MON_DATA_HP);
        u32 status = GetMonData(&sp4[i], MON_DATA_STATUS);

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
    gTasks[taskId].data[3] = r7;

    r7 = 0;
    for (i = 0; i < PARTY_SIZE; i++)
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
        ScanlineEffect_Clear();

        i = 0;
        while (i < 80)
        {
            gScanlineEffectRegBuffers[0][i] = 0xF0;
            gScanlineEffectRegBuffers[1][i] = 0xF0;
            i++;
        }

        while (i < 160)
        {
            gScanlineEffectRegBuffers[0][i] = 0xFF10;
            gScanlineEffectRegBuffers[1][i] = 0xFF10;
            i++;
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

        InitBattleBgsVideo();
        LoadCompressedPalette(gBattleTextboxPalette, 0, 64);
        LoadBattleMenuWindowGfx();
        ResetSpriteData();
        ResetTasks();
        DrawBattleEntryBackground();
        SetGpuReg(REG_OFFSET_WINOUT, 0x37);
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        SetVBlankCallback(VBlankCB_Battle);

        taskId = CreateTask(InitLinkBattleVsScreen, 0);
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
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
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

            for (i = 0; i < monsCount && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

            if (!gSaveBlock2Ptr->frontier.disableRecordBattle && i == monsCount)
            {
                if (FlagGet(FLAG_SYS_FRONTIER_PASS))
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

        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
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
        if (IsLinkTaskFinished() == TRUE)
        {
            sub_800ADF8();
            BattlePutTextOnWindow(gText_LinkStandby3, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(0))
        {
            if (IsLinkTaskFinished() == TRUE)
                gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (!gWirelessCommType)
            sub_800AC34();
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 9:
        if (!gMain.field_439_x4 || gWirelessCommType || gReceivedRemoteLinkPlayers != 1)
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
        ret = gBattleBgTemplates[arrayId].bg;
        break;
    case 1:
        ret = gBattleBgTemplates[arrayId].charBaseIndex;
        break;
    case 2:
        ret = gBattleBgTemplates[arrayId].mapBaseIndex;
        break;
    case 3:
        ret = gBattleBgTemplates[arrayId].screenSize;
        break;
    case 4:
        ret = gBattleBgTemplates[arrayId].paletteMode;
        break;
    case 5:
        ret = gBattleBgTemplates[arrayId].priority;
        break;
    case 6:
        ret = gBattleBgTemplates[arrayId].baseTile;
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
    InitBattleBgsVideo();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    LoadBattleMenuWindowGfx();

    for (i = 0; i < 2; i++)
        LoadChosenBattleElement(i);

    ResetSpriteData();
    ResetTasks();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;
    SetVBlankCallback(VBlankCB_Battle);
    SetMainCallback2(sub_803937C);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
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
            BattlePutTextOnWindow(gText_RecordBattleToPass, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if (!IsTextPrinterActive(0))
        {
            HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
            BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (gMain.newKeys & DPAD_UP)
        {
            if (gBattleCommunication[CURSOR_POSITION] != 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 0;
                BattleCreateYesNoCursorAt(0);
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 1;
                BattleCreateYesNoCursorAt(1);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
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
        if (IsLinkTaskFinished() == TRUE)
        {
            HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
            if (gMain.field_439_x4)
            {
                sub_800ADF8();
                BattlePutTextOnWindow(gText_LinkStandby3, 0);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (--gBattleCommunication[1] == 0)
        {
            if (gMain.field_439_x4 && !gWirelessCommType)
                sub_800AC34();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (!gMain.field_439_x4 || gWirelessCommType || gReceivedRemoteLinkPlayers != 1)
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
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gBattleCommunication[1] = 0x80;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
        {
            BattleStringExpandPlaceholdersToDisplayedString(BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gBattleCommunication[1] = 0x80;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished() == TRUE && !IsTextPrinterActive(0) && --gBattleCommunication[1] == 0)
        {
            if (gMain.field_439_x4)
            {
                sub_800ADF8();
                BattlePutTextOnWindow(gText_LinkStandby3, 0);
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
                if (IsLinkTaskFinished() == TRUE)
                {
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gBattleCommunication[1] = 0x20;
                    gBattleCommunication[MULTIUSE_STATE] = 8;
                }

            }
            else
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
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
        if (StringCompareWithoutExtCtrlCodes(nickname, sText_ShedinjaJpnName) == 0)
            SetMonData(mon, MON_DATA_LANGUAGE, &language);
    }
}

u32 sub_80397C4(u32 setId, u32 tableId)
{
    return gBattleWindowTemplates[setId][tableId].width * 8;
}

#define sBattler            data[0]
#define sSpeciesId          data[2]

void SpriteCb_WildMon(struct Sprite *sprite)
{
    sprite->callback = SpriteCb_MoveWildMonToRight;
    StartSpriteAnimIfDifferent(sprite, 0);
    BeginNormalPaletteFade(0x20000, 0, 10, 10, RGB(8, 8, 8));
}

static void SpriteCb_MoveWildMonToRight(struct Sprite *sprite)
{
    if ((gIntroSlideFlags & 1) == 0)
    {
        sprite->pos2.x += 2;
        if (sprite->pos2.x == 0)
        {
            sprite->callback = SpriteCb_WildMonShowHealthbox;
        }
    }
}

static void SpriteCb_WildMonShowHealthbox(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sub_8076918(sprite->sBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[sprite->sBattler]);
        sprite->callback = SpriteCb_WildMonAnimate;
        StartSpriteAnimIfDifferent(sprite, 0);
        BeginNormalPaletteFade(0x20000, 0, 10, 0, RGB(8, 8, 8));
    }
}

static void SpriteCb_WildMonAnimate(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
    {
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, FALSE, 1);
    }
}

void SpriteCallbackDummy_2(struct Sprite *sprite)
{

}

static void sub_80398BC(struct Sprite *sprite) // unused?
{
    sprite->data[3] = 6;
    sprite->data[4] = 1;
    sprite->callback = sub_80398D0;
}

static void sub_80398D0(struct Sprite *sprite)
{
    sprite->data[4]--;
    if (sprite->data[4] == 0)
    {
        sprite->data[4] = 8;
        sprite->invisible ^= 1;
        sprite->data[3]--;
        if (sprite->data[3] == 0)
        {
            sprite->invisible = FALSE;
            sprite->callback = SpriteCallbackDummy_2;
            sUnusedUnknownArray[0] = 0;
        }
    }
}

extern const struct MonCoords gMonFrontPicCoords[];
extern const struct MonCoords gCastformFrontSpriteCoords[];

void SpriteCB_FaintOpponentMon(struct Sprite *sprite)
{
    u8 battler = sprite->sBattler;
    u16 species;
    u8 yOffset;

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != 0)
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;
    else
        species = sprite->sSpeciesId;

    GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);  // Unused return value.

    if (species == SPECIES_UNOWN)
    {
        u32 personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);
        u16 unownForm = ((((personalityValue & 0x3000000) >> 18) | ((personalityValue & 0x30000) >> 12) | ((personalityValue & 0x300) >> 6) | (personalityValue & 3)) % 0x1C);
        u16 unownSpecies;

        if (unownForm == 0)
            unownSpecies = SPECIES_UNOWN;  // Use the A Unown form.
        else
            unownSpecies = NUM_SPECIES + unownForm;  // Use one of the other Unown letters.

        yOffset = gMonFrontPicCoords[unownSpecies].y_offset;
    }
    else if (species == SPECIES_CASTFORM)
    {
        yOffset = gCastformFrontSpriteCoords[gBattleMonForms[battler]].y_offset;
    }
    else if (species > NUM_SPECIES)
    {
        yOffset = gMonFrontPicCoords[SPECIES_NONE].y_offset;
    }
    else
    {
        yOffset = gMonFrontPicCoords[species].y_offset;
    }

    sprite->data[3] = 8 - yOffset / 8;
    sprite->data[4] = 1;
    sprite->callback = SpriteCB_AnimFaintOpponent;
}

static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite)
{
    s32 i;

    if (--sprite->data[4] == 0)
    {
        sprite->data[4] = 2;
        sprite->pos2.y += 8; // Move the sprite down.
        if (--sprite->data[3] < 0)
        {
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
        else // Erase bottom part of the sprite to create a smooth illusion of mon falling down.
        {
            u8 *dst = (u8 *)gMonSpritesGfxPtr->sprites[GetBattlerPosition(sprite->sBattler)] + (gBattleMonForms[sprite->sBattler] << 11) + (sprite->data[3] << 8);

            for (i = 0; i < 0x100; i++)
                *(dst++) = 0;

            StartSpriteAnim(sprite, gBattleMonForms[sprite->sBattler]);
        }
    }
}

void sub_8039AD8(struct Sprite *sprite)
{
    sprite->data[3] = 8;
    sprite->data[4] = sprite->invisible;
    sprite->callback = sub_8039AF4;
}

static void sub_8039AF4(struct Sprite *sprite)
{
    sprite->data[3]--;
    if (sprite->data[3] == 0)
    {
        sprite->invisible ^= 1;
        sprite->data[3] = 8;
    }
}

void sub_8039B2C(struct Sprite *sprite)
{
    sprite->invisible = sprite->data[4];
    sprite->data[4] = FALSE;
    sprite->callback = SpriteCallbackDummy_2;
}

void sub_8039B58(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        if (!(gHitMarker & HITMARKER_NO_ANIMATIONS) || gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        {
            if (HasTwoFramesAnimation(sprite->sSpeciesId))
                StartSpriteAnim(sprite, 1);
        }
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, TRUE, 1);
    }
}

void sub_8039BB4(struct Sprite *sprite)
{
    sprite->callback = oac_poke_ally_;
}

static void oac_poke_ally_(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->pos2.x -= 2;
        if (sprite->pos2.x == 0)
        {
            sprite->callback = SpriteCallbackDummy_3;
            sprite->data[1] = 0;
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
    if (!(gIntroSlideFlags & 1))
    {
        sprite->pos2.x += sprite->data[1];
        sprite->pos2.y += sprite->data[2];
    }
}

#define sSinIndex           data[0]
#define sDelta              data[1]
#define sAmplitude          data[2]
#define sBouncerSpriteId    data[3]
#define sWhich              data[4]

void DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude)
{
    u8 invisibleSpriteId;
    u8 bouncerSpriteId;

    switch (which)
    {
    case BOUNCE_HEALTHBOX:
    default:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;
        break;
    case BOUNCE_MON:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;
        break;
    }

    invisibleSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_BounceEffect);
    if (which == BOUNCE_HEALTHBOX)
    {
        bouncerSpriteId = gHealthboxSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 128; // 0
    }
    else
    {
        bouncerSpriteId = gBattlerSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 192; // -1
    }
    gSprites[invisibleSpriteId].sDelta = delta;
    gSprites[invisibleSpriteId].sAmplitude = amplitude;
    gSprites[invisibleSpriteId].sBouncerSpriteId = bouncerSpriteId;
    gSprites[invisibleSpriteId].sWhich = which;
    gSprites[bouncerSpriteId].pos2.x = 0;
    gSprites[bouncerSpriteId].pos2.y = 0;
}

void EndBounceEffect(u8 battler, u8 which)
{
    u8 bouncerSpriteId;

    if (which == BOUNCE_HEALTHBOX)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 0;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 0;
    }

    gSprites[bouncerSpriteId].pos2.x = 0;
    gSprites[bouncerSpriteId].pos2.y = 0;
}

static void SpriteCB_BounceEffect(struct Sprite *sprite)
{
    u8 bouncerSpriteId = sprite->sBouncerSpriteId;
    s32 index;

    if (sprite->sWhich == BOUNCE_HEALTHBOX)
        index = sprite->sSinIndex;
    else
        index = sprite->sSinIndex;

    gSprites[bouncerSpriteId].pos2.y = Sin(index, sprite->sAmplitude) + sprite->sAmplitude;
    sprite->sSinIndex = (sprite->sSinIndex + sprite->sDelta) & 0xFF;
}

#undef sSinIndex
#undef sDelta
#undef sAmplitude
#undef sBouncerSpriteId
#undef sWhich

void sub_8039E44(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        BattleAnimateBackSprite(sprite, sprite->sSpeciesId);
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

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        gBattlerControllerFuncs[gActiveBattler]();
}

static void BattleStartClearSetData(void)
{
    s32 i;
    u32 j;
    u8 *dataPtr;

    TurnValuesCleanUp(FALSE);
    SpecialStatusesClear();

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gStatuses3[i] = 0;

        dataPtr = (u8 *)&gDisableStructs[i];
        for (j = 0; j < sizeof(struct DisableStruct); j++)
            dataPtr[j] = 0;

        gDisableStructs[i].isFirstTurn = 2;
        sUnusedBattlersArray[i] = 0;
        gLastMoves[i] = 0;
        gLastLandedMoves[i] = 0;
        gLastHitByType[i] = 0;
        gLastResultingMoves[i] = 0;
        gLastHitBy[i] = 0xFF;
        gLockedMoves[i] = 0;
        gLastPrintedMoves[i] = 0;
        gBattleResources->flags->flags[i] = 0;
        gPalaceSelectionBattleScripts[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        gSideStatuses[i] = 0;

        dataPtr = (u8 *)&gSideTimers[i];
        for (j = 0; j < sizeof(struct SideTimer); j++)
            dataPtr[j] = 0;
    }

    gBattlerAttacker = 0;
    gBattlerTarget = 0;
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
    else if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)) && GetBattleSceneInRecordedBattle())
        gHitMarker |= HITMARKER_NO_ANIMATIONS;

    gBattleScripting.battleStyle = gSaveBlock2Ptr->optionsBattleStyle;

    gMultiHitCounter = 0;
    gBattleOutcome = 0;
    gBattleControllerExecFlags = 0;
    gPaydayMoney = 0;
    gBattleResources->battleScriptsStack->size = 0;
    gBattleResources->battleCallbackStack->size = 0;

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    gPauseCounterBattle = 0;
    gBattleMoveDamage = 0;
    gIntroSlideFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLeveledUpInBattle = 0;
    gAbsentBattlerFlags = 0;
    gBattleStruct->runTries = 0;
    gBattleStruct->safariGoNearCounter = 0;
    gBattleStruct->safariPkblThrowCounter = 0;
    *(&gBattleStruct->safariCatchFactor) = gBaseStats[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)].catchRate * 100 / 1275;
    gBattleStruct->safariEscapeFactor = 3;
    gBattleStruct->wildVictorySong = 0;
    gBattleStruct->moneyMultiplier = 1;

    for (i = 0; i < 8; i++)
    {
        *((u8 *)gBattleStruct->lastTakenMove + i) = 0;
        *((u8 *)gBattleStruct->usedHeldItems + i) = 0;
        *((u8 *)gBattleStruct->choicedMove + i) = 0;
        *((u8 *)gBattleStruct->changedItems + i) = 0;
        *(i + 0 * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
        *(i + 1 * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
        *(i + 2 * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
        *(i + 3 * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + i) = PARTY_SIZE;
    }

    gBattleStruct->givenExpMons = 0;
    gBattleStruct->field_92 = 0;

    gRandomTurnNumber = Random();

    dataPtr = (u8 *)(&gBattleResults);
    for (i = 0; i < sizeof(struct BattleResults); i++)
        dataPtr[i] = 0;

    gBattleResults.shinyWildMon = IsMonShiny(&gEnemyParty[0]);

    gBattleStruct->arenaLostPlayerMons = 0;
    gBattleStruct->arenaLostOpponentMons = 0;
}

void SwitchInClearSetData(void)
{
    struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
    s32 i;
    u8 *ptr;

    if (gBattleMoves[gCurrentMove].effect != EFFECT_BATON_PASS)
    {
        for (i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[gActiveBattler].statStages[i] = 6;
        for (i = 0; i < gBattlersCount; i++)
        {
            if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gDisableStructs[i].battlerPreventingEscape == gActiveBattler)
                gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
            if ((gStatuses3[i] & STATUS3_ALWAYS_HITS) && gDisableStructs[i].battlerWithSureHit == gActiveBattler)
            {
                gStatuses3[i] &= ~STATUS3_ALWAYS_HITS;
                gDisableStructs[i].battlerWithSureHit = 0;
            }
        }
    }
    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gBattleMons[gActiveBattler].status2 &= (STATUS2_CONFUSION | STATUS2_FOCUS_ENERGY | STATUS2_SUBSTITUTE | STATUS2_ESCAPE_PREVENTION | STATUS2_CURSED);
        gStatuses3[gActiveBattler] &= (STATUS3_LEECHSEED_BATTLER | STATUS3_LEECHSEED | STATUS3_ALWAYS_HITS | STATUS3_PERISH_SONG | STATUS3_ROOTED | STATUS3_MUDSPORT | STATUS3_WATERSPORT);

        for (i = 0; i < gBattlersCount; i++)
        {
            if (GetBattlerSide(gActiveBattler) != GetBattlerSide(i)
             && (gStatuses3[i] & STATUS3_ALWAYS_HITS) != 0
             && (gDisableStructs[i].battlerWithSureHit == gActiveBattler))
            {
                gStatuses3[i] &= ~(STATUS3_ALWAYS_HITS);
                gStatuses3[i] |= 0x10;
            }
        }
    }
    else
    {
        gBattleMons[gActiveBattler].status2 = 0;
        gStatuses3[gActiveBattler] = 0;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(gActiveBattler))
            gBattleMons[i].status2 &= ~(STATUS2_INFATUATED_WITH(gActiveBattler));
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gBattleStruct->wrappedBy + i) == gActiveBattler)
            gBattleMons[i].status2 &= ~(STATUS2_WRAPPED);
    }

    gActionSelectionCursor[gActiveBattler] = 0;
    gMoveSelectionCursor[gActiveBattler] = 0;

    ptr = (u8 *)&gDisableStructs[gActiveBattler];
    for (i = 0; i < sizeof(struct DisableStruct); i++)
        ptr[i] = 0;

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gDisableStructs[gActiveBattler].substituteHP = disableStructCopy.substituteHP;
        gDisableStructs[gActiveBattler].battlerWithSureHit = disableStructCopy.battlerWithSureHit;
        gDisableStructs[gActiveBattler].perishSongTimer = disableStructCopy.perishSongTimer;
        gDisableStructs[gActiveBattler].perishSongTimerStartValue = disableStructCopy.perishSongTimerStartValue;
        gDisableStructs[gActiveBattler].battlerPreventingEscape = disableStructCopy.battlerPreventingEscape;
    }

    gMoveResultFlags = 0;
    gDisableStructs[gActiveBattler].isFirstTurn = 2;
    gDisableStructs[gActiveBattler].truantSwitchInHack = disableStructCopy.truantSwitchInHack;
    gLastMoves[gActiveBattler] = 0;
    gLastLandedMoves[gActiveBattler] = 0;
    gLastHitByType[gActiveBattler] = 0;
    gLastResultingMoves[gActiveBattler] = 0;
    gLastPrintedMoves[gActiveBattler] = 0;
    gLastHitBy[gActiveBattler] = 0xFF;

    *(gBattleStruct->lastTakenMove + gActiveBattler * 2 + 0) = 0;
    *(gBattleStruct->lastTakenMove + gActiveBattler * 2 + 1) = 0;
    *(0 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(0 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    *(1 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(1 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    *(2 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(2 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    *(3 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(3 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;

    gBattleStruct->field_92 &= ~(gBitTable[gActiveBattler]);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gActiveBattler && GetBattlerSide(i) != GetBattlerSide(gActiveBattler))
        {
            *(gBattleStruct->lastTakenMove + i * 2 + 0) = 0;
            *(gBattleStruct->lastTakenMove + i * 2 + 1) = 0;
        }
        *(i * 8 + gActiveBattler * 2 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
        *(i * 8 + gActiveBattler * 2 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    }

    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBattler]) + 0) = 0;
    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBattler]) + 1) = 0;

    gBattleResources->flags->flags[gActiveBattler] = 0;
    gCurrentMove = 0;
    gBattleStruct->arenaTurnCounter = 0xFF;

    ClearBattlerMoveHistory(gActiveBattler);
    ClearBattlerAbilityHistory(gActiveBattler);
}

void FaintClearSetData(void)
{
    s32 i;
    u8 *ptr;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
        gBattleMons[gActiveBattler].statStages[i] = 6;

    gBattleMons[gActiveBattler].status2 = 0;
    gStatuses3[gActiveBattler] = 0;

    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gDisableStructs[i].battlerPreventingEscape == gActiveBattler)
            gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(gActiveBattler))
            gBattleMons[i].status2 &= ~(STATUS2_INFATUATED_WITH(gActiveBattler));
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gBattleStruct->wrappedBy + i) == gActiveBattler)
            gBattleMons[i].status2 &= ~(STATUS2_WRAPPED);
    }

    gActionSelectionCursor[gActiveBattler] = 0;
    gMoveSelectionCursor[gActiveBattler] = 0;

    ptr = (u8 *)&gDisableStructs[gActiveBattler];
    for (i = 0; i < sizeof(struct DisableStruct); i++)
        ptr[i] = 0;

    gProtectStructs[gActiveBattler].protected = 0;
    gProtectStructs[gActiveBattler].endured = 0;
    gProtectStructs[gActiveBattler].noValidMoves = 0;
    gProtectStructs[gActiveBattler].helpingHand = 0;
    gProtectStructs[gActiveBattler].bounceMove = 0;
    gProtectStructs[gActiveBattler].stealMove = 0;
    gProtectStructs[gActiveBattler].flag0Unknown = 0;
    gProtectStructs[gActiveBattler].prlzImmobility = 0;
    gProtectStructs[gActiveBattler].confusionSelfDmg = 0;
    gProtectStructs[gActiveBattler].targetNotAffected = 0;
    gProtectStructs[gActiveBattler].chargingTurn = 0;
    gProtectStructs[gActiveBattler].fleeFlag = 0;
    gProtectStructs[gActiveBattler].usedImprisonedMove = 0;
    gProtectStructs[gActiveBattler].loveImmobility = 0;
    gProtectStructs[gActiveBattler].usedDisabledMove = 0;
    gProtectStructs[gActiveBattler].usedTauntedMove = 0;
    gProtectStructs[gActiveBattler].flag2Unknown = 0;
    gProtectStructs[gActiveBattler].flinchImmobility = 0;
    gProtectStructs[gActiveBattler].notFirstStrike = 0;

    gDisableStructs[gActiveBattler].isFirstTurn = 2;

    gLastMoves[gActiveBattler] = 0;
    gLastLandedMoves[gActiveBattler] = 0;
    gLastHitByType[gActiveBattler] = 0;
    gLastResultingMoves[gActiveBattler] = 0;
    gLastPrintedMoves[gActiveBattler] = 0;
    gLastHitBy[gActiveBattler] = 0xFF;

    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBattler]) + 0) = 0;
    *(u8*)((u8*)(&gBattleStruct->choicedMove[gActiveBattler]) + 1) = 0;

    *(gBattleStruct->lastTakenMove + gActiveBattler * 2 + 0) = 0;
    *(gBattleStruct->lastTakenMove + gActiveBattler * 2 + 1) = 0;
    *(0 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(0 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    *(1 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(1 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    *(2 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(2 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    *(3 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
    *(3 * 2 + gActiveBattler * 8 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;

    gBattleStruct->field_92 &= ~(gBitTable[gActiveBattler]);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gActiveBattler && GetBattlerSide(i) != GetBattlerSide(gActiveBattler))
        {
            *(gBattleStruct->lastTakenMove + i * 2 + 0) = 0;
            *(gBattleStruct->lastTakenMove + i * 2 + 1) = 0;
        }
        *(i * 8 + gActiveBattler * 2 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 0) = 0;
        *(i * 8 + gActiveBattler * 2 + (u8*)(gBattleStruct->lastTakenMoveFrom) + 1) = 0;
    }

    gBattleResources->flags->flags[gActiveBattler] = 0;

    gBattleMons[gActiveBattler].type1 = gBaseStats[gBattleMons[gActiveBattler].species].type1;
    gBattleMons[gActiveBattler].type2 = gBaseStats[gBattleMons[gActiveBattler].species].type2;

    ClearBattlerMoveHistory(gActiveBattler);
    ClearBattlerAbilityHistory(gActiveBattler);
}

static void BattleIntroGetMonsData(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        gActiveBattler = gBattleCommunication[1];
        BtlController_EmitGetMonData(0, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (gBattleControllerExecFlags == 0)
        {
            gBattleCommunication[1]++;
            if (gBattleCommunication[1] == gBattlersCount)
                gBattleMainFunc = BattleIntroPrepareBackgroundSlide;
            else
                gBattleCommunication[MULTIUSE_STATE] = 0;
        }
        break;
    }
}

static void BattleIntroPrepareBackgroundSlide(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerAtPosition(0);
        BtlController_EmitIntroSlide(0, gBattleTerrain);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleMainFunc = BattleIntroDrawTrainersOrMonsSprites;
        gBattleCommunication[0] = 0;
        gBattleCommunication[1] = 0;
    }
}

static void BattleIntroDrawTrainersOrMonsSprites(void)
{
    u8 *ptr;
    s32 i;

    if (gBattleControllerExecFlags)
        return;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI)
         && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            ptr = (u8 *)&gBattleMons[gActiveBattler];
            for (i = 0; i < sizeof(struct BattlePokemon); i++)
                ptr[i] = 0;
        }
        else
        {
            u16* hpOnSwitchout;

            ptr = (u8 *)&gBattleMons[gActiveBattler];
            for (i = 0; i < sizeof(struct BattlePokemon); i++)
                ptr[i] = gBattleBufferB[gActiveBattler][4 + i];

            gBattleMons[gActiveBattler].type1 = gBaseStats[gBattleMons[gActiveBattler].species].type1;
            gBattleMons[gActiveBattler].type2 = gBaseStats[gBattleMons[gActiveBattler].species].type2;
            gBattleMons[gActiveBattler].ability = GetAbilityBySpecies(gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].abilityNum);
            hpOnSwitchout = &gBattleStruct->hpOnSwitchout[GetBattlerSide(gActiveBattler)];
            *hpOnSwitchout = gBattleMons[gActiveBattler].hp;
            for (i = 0; i < NUM_BATTLE_STATS; i++)
                gBattleMons[gActiveBattler].statStages[i] = 6;
            gBattleMons[gActiveBattler].status2 = 0;
        }

        if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_LEFT)
        {
            BtlController_EmitDrawTrainerPic(0);
            MarkBattlerForControllerExec(gActiveBattler);
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (GetBattlerPosition(gActiveBattler) == B_POSITION_OPPONENT_LEFT)
            {
                BtlController_EmitDrawTrainerPic(0);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT
             && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                      | BATTLE_TYPE_FRONTIER
                                      | BATTLE_TYPE_LINK
                                      | BATTLE_TYPE_x2000000
                                      | BATTLE_TYPE_TRAINER_HILL)))
            {
                HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);
            }
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                      | BATTLE_TYPE_FRONTIER
                                      | BATTLE_TYPE_LINK
                                      | BATTLE_TYPE_x2000000
                                      | BATTLE_TYPE_TRAINER_HILL)))
                {
                    HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);
                }
                BtlController_EmitLoadMonSprite(0);
                MarkBattlerForControllerExec(gActiveBattler);
                gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT
             || GetBattlerPosition(gActiveBattler) == B_POSITION_OPPONENT_RIGHT)
            {
                BtlController_EmitDrawTrainerPic(0);
                MarkBattlerForControllerExec(gActiveBattler);
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && GetBattlerPosition(gActiveBattler) == B_POSITION_OPPONENT_RIGHT)
        {
            BtlController_EmitDrawTrainerPic(0);
            MarkBattlerForControllerExec(gActiveBattler);
        }

        if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
            BattleArena_InitPoints();
    }
    gBattleMainFunc = BattleIntroDrawPartySummaryScreens;
}

static void BattleIntroDrawPartySummaryScreens(void)
{
    s32 i;
    struct HpAndStatus hpStatus[PARTY_SIZE];

    if (gBattleControllerExecFlags)
        return;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        for (i = 0; i < PARTY_SIZE; i++)
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
        gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        BtlController_EmitDrawPartyStatusSummary(0, hpStatus, 0x80);
        MarkBattlerForControllerExec(gActiveBattler);

        for (i = 0; i < PARTY_SIZE; i++)
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
        gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        BtlController_EmitDrawPartyStatusSummary(0, hpStatus, 0x80);
        MarkBattlerForControllerExec(gActiveBattler);

        gBattleMainFunc = BattleIntroPrintTrainerWantsToBattle;
    }
    else
    {
        // The struct gets set here, but nothing is ever done with it since
        // wild battles don't show the party summary.
        // Still, there's no point in having dead code.

        for (i = 0; i < PARTY_SIZE; i++)
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
    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        PrepareStringBattle(STRINGID_INTROMSG, gActiveBattler);
        gBattleMainFunc = BattleIntroPrintOpponentSendsOut;
    }
}

static void BattleIntroPrintWildMonAttacked(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
        PrepareStringBattle(STRINGID_INTROMSG, 0);
    }
}

static void BattleIntroPrintOpponentSendsOut(void)
{
    u32 position;

    if (gBattleControllerExecFlags)
        return;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        position = B_POSITION_OPPONENT_LEFT;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            position = B_POSITION_OPPONENT_LEFT;
        else
            position = B_POSITION_PLAYER_LEFT;
    }
    else
        position = B_POSITION_OPPONENT_LEFT;

    PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(position));
    gBattleMainFunc = BattleIntroOpponent1SendsOutMonAnimation;
}

static void BattleIntroOpponent2SendsOutMonAnimation(void)
{
    u32 position;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        position = B_POSITION_OPPONENT_RIGHT;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            position = B_POSITION_OPPONENT_RIGHT;
        else
            position = B_POSITION_PLAYER_RIGHT;
    }
    else
        position = B_POSITION_OPPONENT_RIGHT;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (GetBattlerPosition(gActiveBattler) == position)
        {
            BtlController_EmitIntroTrainerBallThrow(0);
            MarkBattlerForControllerExec(gActiveBattler);
        }
    }

    gBattleMainFunc = BattleIntroRecordMonsToDex;
}

#ifdef NONMATCHING
static void BattleIntroOpponent1SendsOutMonAnimation(void)
{
    u32 position;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        position = B_POSITION_OPPONENT_LEFT;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            position = B_POSITION_OPPONENT_LEFT;
        else
            position = B_POSITION_PLAYER_LEFT;
    }
    else
        position = B_POSITION_OPPONENT_LEFT;

    if (gBattleControllerExecFlags)
        return;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (GetBattlerPosition(gActiveBattler) == position)
        {
            BtlController_EmitIntroTrainerBallThrow(0);
            MarkBattlerForControllerExec(gActiveBattler);
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
NAKED
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
    ldr r0, =gBattleControllerExecFlags\n\
    ldr r2, [r0]\n\
    cmp r2, 0\n\
    bne _0803B2F2\n\
    ldr r0, =gActiveBattler\n\
    strb r2, [r0]\n\
    ldr r1, =gBattlersCount\n\
    adds r4, r0, 0\n\
    ldrb r1, [r1]\n\
    cmp r2, r1\n\
    bcs _0803B2EC\n\
    adds r6, r4, 0\n\
_0803B2B2:\n\
    ldrb r0, [r4]\n\
    bl GetBattlerPosition\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, r5\n\
    bne _0803B2D8\n\
    movs r0, 0\n\
    bl BtlController_EmitIntroTrainerBallThrow\n\
    ldrb r0, [r4]\n\
    bl MarkBattlerForControllerExec\n\
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
    ldr r1, =gBattlersCount\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    ldr r4, =gActiveBattler\n\
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
    if (gBattleControllerExecFlags == 0)
    {
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT
             && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                      | BATTLE_TYPE_FRONTIER
                                      | BATTLE_TYPE_LINK
                                      | BATTLE_TYPE_x2000000
                                      | BATTLE_TYPE_TRAINER_HILL)))
            {
                HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);
            }
        }
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
    }
}

void sub_803B3AC(void) // unused
{
    if (gBattleControllerExecFlags == 0)
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
}

static void BattleIntroPrintPlayerSendsOut(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        u8 position;

        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
            position = B_POSITION_PLAYER_LEFT;
        else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
                position = B_POSITION_PLAYER_LEFT;
            else
                position = B_POSITION_OPPONENT_LEFT;
        }
        else
            position = B_POSITION_PLAYER_LEFT;

        if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
            PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(position));

        gBattleMainFunc = BattleIntroPlayer1SendsOutMonAnimation;
    }
}

static void BattleIntroPlayer2SendsOutMonAnimation(void)
{
    u32 position;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        position = B_POSITION_PLAYER_RIGHT;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            position = B_POSITION_PLAYER_RIGHT;
        else
            position = B_POSITION_OPPONENT_RIGHT;
    }
    else
        position = B_POSITION_PLAYER_RIGHT;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (GetBattlerPosition(gActiveBattler) == position)
        {
            BtlController_EmitIntroTrainerBallThrow(0);
            MarkBattlerForControllerExec(gActiveBattler);
        }
    }

    gBattleStruct->switchInAbilitiesCounter = 0;
    gBattleStruct->switchInItemsCounter = 0;
    gBattleStruct->overworldWeatherDone = FALSE;

    gBattleMainFunc = TryDoEventsBeforeFirstTurn;
}

static void BattleIntroPlayer1SendsOutMonAnimation(void)
{
    u32 position;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        position = B_POSITION_PLAYER_LEFT;
    else if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
            position = B_POSITION_PLAYER_LEFT;
        else
            position = B_POSITION_OPPONENT_LEFT;
    }
    else
        position = B_POSITION_PLAYER_LEFT;

    if (gBattleControllerExecFlags)
        return;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (GetBattlerPosition(gActiveBattler) == position)
        {
            BtlController_EmitIntroTrainerBallThrow(0);
            MarkBattlerForControllerExec(gActiveBattler);
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
    if (gBattleControllerExecFlags == 0)
    {
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                BtlController_EmitSwitchInAnim(0, gBattlerPartyIndexes[gActiveBattler], FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
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

    if (gBattleControllerExecFlags)
        return;

    if (gBattleStruct->switchInAbilitiesCounter == 0)
    {
        for (i = 0; i < gBattlersCount; i++)
            gBattlerByTurnOrder[i] = i;
        for (i = 0; i < gBattlersCount - 1; i++)
        {
            for (j = i + 1; j < gBattlersCount; j++)
            {
                if (GetWhoStrikesFirst(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], TRUE) != 0)
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
    // Check all switch in abilities happening from the fastest mon to slowest.
    while (gBattleStruct->switchInAbilitiesCounter < gBattlersCount)
    {
        if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gBattlerByTurnOrder[gBattleStruct->switchInAbilitiesCounter], 0, 0, 0) != 0)
            effect++;

        gBattleStruct->switchInAbilitiesCounter++;

        if (effect)
            return;
    }
    if (AbilityBattleEffects(ABILITYEFFECT_INTIMIDATE1, 0, 0, 0, 0) != 0)
        return;
    if (AbilityBattleEffects(ABILITYEFFECT_TRACE, 0, 0, 0, 0) != 0)
        return;
    // Check all switch in items having effect from the fastest mon to slowest.
    while (gBattleStruct->switchInItemsCounter < gBattlersCount)
    {
        if (ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, gBattlerByTurnOrder[gBattleStruct->switchInItemsCounter], FALSE))
            effect++;

        gBattleStruct->switchInItemsCounter++;

        if (effect)
            return;
    }
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        *(gBattleStruct->monToSwitchIntoId + i) = PARTY_SIZE;
        gChosenActionByBattler[i] = B_ACTION_NONE;
        gChosenMoveByBattler[i] = MOVE_NONE;
    }
    TurnValuesCleanUp(FALSE);
    SpecialStatusesClear();
    *(&gBattleStruct->field_91) = gAbsentBattlerFlags;
    BattlePutTextOnWindow(gText_EmptyString3, 0);
    gBattleMainFunc = HandleTurnActionSelectionState;
    ResetSentPokesToOpponentValue();

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    for (i = 0; i < gBattlersCount; i++)
        gBattleMons[i].status2 &= ~(STATUS2_FLINCHED);

    *(&gBattleStruct->turnEffectsTracker) = 0;
    *(&gBattleStruct->turnEffectsBattlerId) = 0;
    *(&gBattleStruct->wishPerishSongState) = 0;
    *(&gBattleStruct->wishPerishSongBattlerId) = 0;
    gBattleScripting.moveendState = 0;
    gBattleStruct->faintedActionsState = 0;
    gBattleStruct->turnCountersTracker = 0;
    gMoveResultFlags = 0;

    gRandomTurnNumber = Random();

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        StopCryAndClearCrySongs();
        BattleScriptExecute(BattleScript_ArenaTurnBeginning);
    }
}

static void HandleEndTurn_ContinueBattle(void)
{
    s32 i;

    if (gBattleControllerExecFlags == 0)
    {
        gBattleMainFunc = BattleTurnPassed;
        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;
        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleMons[i].status2 &= ~(STATUS2_FLINCHED);
            if ((gBattleMons[i].status1 & STATUS1_SLEEP) && (gBattleMons[i].status2 & STATUS2_MULTIPLETURNS))
                CancelMultiTurnMoves(i);
        }
        gBattleStruct->turnEffectsTracker = 0;
        gBattleStruct->turnEffectsBattlerId = 0;
        gBattleStruct->wishPerishSongState = 0;
        gBattleStruct->wishPerishSongBattlerId = 0;
        gBattleStruct->turnCountersTracker = 0;
        gMoveResultFlags = 0;
    }
}

void BattleTurnPassed(void)
{
    s32 i;

    TurnValuesCleanUp(TRUE);
    if (gBattleOutcome == 0)
    {
        if (DoFieldEndTurnEffects())
            return;
        if (DoBattlerEndTurnEffects())
            return;
    }
    if (HandleFaintedMonActions())
        return;
    gBattleStruct->faintedActionsState = 0;
    if (HandleWishPerishSongOnTurnEnd())
        return;

    TurnValuesCleanUp(FALSE);
    gHitMarker &= ~(HITMARKER_NO_ATTACKSTRING);
    gHitMarker &= ~(HITMARKER_UNABLE_TO_USE_MOVE);
    gHitMarker &= ~(HITMARKER_x400000);
    gHitMarker &= ~(HITMARKER_x100000);
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleScripting.moveendState = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;

    for (i = 0; i < 5; i++)
        gBattleCommunication[i] = 0;

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        gBattleMainFunc = RunTurnActionsFunctions;
        return;
    }

    if (gBattleResults.battleTurnCounter < 0xFF)
    {
        gBattleResults.battleTurnCounter++;
        gBattleStruct->arenaTurnCounter++;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        gChosenActionByBattler[i] = B_ACTION_NONE;
        gChosenMoveByBattler[i] = MOVE_NONE;
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        *(gBattleStruct->monToSwitchIntoId + i) = PARTY_SIZE;

    *(&gBattleStruct->field_91) = gAbsentBattlerFlags;
    BattlePutTextOnWindow(gText_EmptyString3, 0);
    gBattleMainFunc = HandleTurnActionSelectionState;
    gRandomTurnNumber = Random();

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        BattleScriptExecute(BattleScript_82DB881);
    else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaTurnCounter == 0)
        BattleScriptExecute(BattleScript_ArenaTurnBeginning);
}

u8 IsRunningFromBattleImpossible(void)
{
    u8 holdEffect;
    u8 side;
    s32 i;

    if (gBattleMons[gActiveBattler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gActiveBattler].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gActiveBattler].item);

    gPotentialItemEffectBattler = gActiveBattler;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
        return 0;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return 0;
    if (gBattleMons[gActiveBattler].ability == ABILITY_RUN_AWAY)
        return 0;

    side = GetBattlerSide(gActiveBattler);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (side != GetBattlerSide(i)
         && gBattleMons[i].ability == ABILITY_SHADOW_TAG)
        {
            gBattleScripting.battler = i;
            gLastUsedAbility = gBattleMons[i].ability;
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            return 2;
        }
        if (side != GetBattlerSide(i)
         && gBattleMons[gActiveBattler].ability != ABILITY_LEVITATE
         && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_FLYING)
         && gBattleMons[i].ability == ABILITY_ARENA_TRAP)
        {
            gBattleScripting.battler = i;
            gLastUsedAbility = gBattleMons[i].ability;
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            return 2;
        }
    }
    i = AbilityBattleEffects(ABILITYEFFECT_CHECK_FIELD_EXCEPT_BATTLER, gActiveBattler, ABILITY_MAGNET_PULL, 0, 0);
    if (i != 0 && IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_STEEL))
    {
        gBattleScripting.battler = i - 1;
        gLastUsedAbility = gBattleMons[i - 1].ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        return 2;
    }
    if ((gBattleMons[gActiveBattler].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        || (gStatuses3[gActiveBattler] & STATUS3_ROOTED))
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

void SwitchPartyOrder(u8 battler)
{
    s32 i;
    u8 partyId1;
    u8 partyId2;

    // gBattleStruct->field_60[battler][i]

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8*)(gBattleStruct->field_60));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(*(gBattleStruct->monToSwitchIntoId + battler));
    SwitchPartyMonSlots(partyId1, partyId2);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8*)(gBattleStruct->field_60)) = gBattlePartyCurrentOrder[i];
            *(BATTLE_PARTNER(battler) * 3 + i + (u8*)(gBattleStruct->field_60)) = gBattlePartyCurrentOrder[i];
        }
    }
    else
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8*)(gBattleStruct->field_60)) = gBattlePartyCurrentOrder[i];
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
    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        u8 position = GetBattlerPosition(gActiveBattler);
        switch (gBattleCommunication[gActiveBattler])
        {
        case STATE_TURN_START_RECORD: // Recorded battle related action on start of every turn.
            RecordedBattle_CopyBattlerMoves();
            gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
            break;
        case STATE_BEFORE_ACTION_CHOSEN: // Choose an action.
            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI
                || (position & BIT_FLANK) == B_FLANK_LEFT
                || gBattleStruct->field_91 & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(position))]
                || gBattleCommunication[GetBattlerAtPosition(BATTLE_PARTNER(position))] == STATE_WAIT_ACTION_CONFIRMED)
            {
                if (gBattleStruct->field_91 & gBitTable[gActiveBattler])
                {
                    gChosenActionByBattler[gActiveBattler] = B_ACTION_NOTHING_FAINTED;
                    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED;
                    else
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    if (gBattleMons[gActiveBattler].status2 & STATUS2_MULTIPLETURNS
                        || gBattleMons[gActiveBattler].status2 & STATUS2_RECHARGE)
                    {
                        gChosenActionByBattler[gActiveBattler] = B_ACTION_USE_MOVE;
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else
                    {
                        BtlController_EmitChooseAction(0, gChosenActionByBattler[0], gBattleBufferB[0][1] | (gBattleBufferB[0][2] << 8));
                        MarkBattlerForControllerExec(gActiveBattler);
                        gBattleCommunication[gActiveBattler]++;
                    }
                }
            }
            break;
        case STATE_WAIT_ACTION_CHOSEN: // Try to perform an action.
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
            {
                RecordedBattle_SetBattlerAction(gActiveBattler, gBattleBufferB[gActiveBattler][1]);
                gChosenActionByBattler[gActiveBattler] = gBattleBufferB[gActiveBattler][1];

                switch (gBattleBufferB[gActiveBattler][1])
                {
                case B_ACTION_USE_MOVE:
                    if (AreAllMovesUnusable())
                    {
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        *(gBattleStruct->moveTarget + gActiveBattler) = gBattleBufferB[gActiveBattler][3];
                        return;
                    }
                    else if (gDisableStructs[gActiveBattler].encoredMove != 0)
                    {
                        gChosenMoveByBattler[gActiveBattler] = gDisableStructs[gActiveBattler].encoredMove;
                        *(gBattleStruct->chosenMovePositions + gActiveBattler) = gDisableStructs[gActiveBattler].encoredMovePos;
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        return;
                    }
                    else
                    {
                        struct ChooseMoveStruct moveInfo;

                        moveInfo.species = gBattleMons[gActiveBattler].species;
                        moveInfo.monType1 = gBattleMons[gActiveBattler].type1;
                        moveInfo.monType2 = gBattleMons[gActiveBattler].type2;

                        for (i = 0; i < MAX_MON_MOVES; i++)
                        {
                            moveInfo.moves[i] = gBattleMons[gActiveBattler].moves[i];
                            moveInfo.currentPp[i] = gBattleMons[gActiveBattler].pp[i];
                            moveInfo.maxPp[i] = CalculatePPWithBonus(
                                                            gBattleMons[gActiveBattler].moves[i],
                                                            gBattleMons[gActiveBattler].ppBonuses,
                                                            i);
                        }

                        BtlController_EmitChooseMove(0, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0, FALSE, &moveInfo);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    break;
                case B_ACTION_USE_ITEM:
                    if (gBattleTypeFlags & (BATTLE_TYPE_LINK
                                            | BATTLE_TYPE_FRONTIER_NO_PYRAMID
                                            | BATTLE_TYPE_EREADER_TRAINER
                                            | BATTLE_TYPE_x2000000))
                    {
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        gSelectionBattleScripts[gActiveBattler] = BattleScript_ActionSelectionItemsCantBeUsed;
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    else
                    {
                        BtlController_EmitChooseItem(0, gBattleStruct->field_60[gActiveBattler]);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    break;
                case B_ACTION_SWITCH:
                    *(gBattleStruct->field_58 + gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
                    if (gBattleMons[gActiveBattler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION)
                        || gBattleTypeFlags & BATTLE_TYPE_ARENA
                        || gStatuses3[gActiveBattler] & STATUS3_ROOTED)
                    {
                        BtlController_EmitChoosePokemon(0, PARTY_ACTION_CANT_SWITCH, PARTY_SIZE, ABILITY_NONE, gBattleStruct->field_60[gActiveBattler]);
                    }
                    else if ((i = ABILITY_ON_OPPOSING_FIELD(gActiveBattler, ABILITY_SHADOW_TAG))
                             || ((i = ABILITY_ON_OPPOSING_FIELD(gActiveBattler, ABILITY_ARENA_TRAP))
                                 && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_FLYING)
                                 && gBattleMons[gActiveBattler].ability != ABILITY_LEVITATE)
                             || ((i = AbilityBattleEffects(ABILITYEFFECT_CHECK_FIELD_EXCEPT_BATTLER, gActiveBattler, ABILITY_MAGNET_PULL, 0, 0))
                                 && IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_STEEL)))
                    {
                        BtlController_EmitChoosePokemon(0, ((i - 1) << 4) | PARTY_ACTION_ABILITY_PREVENTS, PARTY_SIZE, gLastUsedAbility, gBattleStruct->field_60[gActiveBattler]);
                    }
                    else
                    {
                        if (gActiveBattler == 2 && gChosenActionByBattler[0] == B_ACTION_SWITCH)
                            BtlController_EmitChoosePokemon(0, PARTY_ACTION_CHOOSE_MON, *(gBattleStruct->monToSwitchIntoId + 0), ABILITY_NONE, gBattleStruct->field_60[gActiveBattler]);
                        else if (gActiveBattler == 3 && gChosenActionByBattler[1] == B_ACTION_SWITCH)
                            BtlController_EmitChoosePokemon(0, PARTY_ACTION_CHOOSE_MON, *(gBattleStruct->monToSwitchIntoId + 1), ABILITY_NONE, gBattleStruct->field_60[gActiveBattler]);
                        else
                            BtlController_EmitChoosePokemon(0, PARTY_ACTION_CHOOSE_MON, PARTY_SIZE, ABILITY_NONE, gBattleStruct->field_60[gActiveBattler]);
                    }
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case B_ACTION_SAFARI_BALL:
                    if (IsPlayerPartyAndPokemonStorageFull())
                    {
                        gSelectionBattleScripts[gActiveBattler] = BattleScript_PrintFullBox;
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    break;
                case B_ACTION_SAFARI_POKEBLOCK:
                    BtlController_EmitChooseItem(0, gBattleStruct->field_60[gActiveBattler]);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case B_ACTION_CANCEL_PARTNER:
                    gBattleCommunication[gActiveBattler] = STATE_WAIT_SET_BEFORE_ACTION;
                    gBattleCommunication[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] = STATE_BEFORE_ACTION_CHOSEN;
                    RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                    if (gBattleMons[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].status2 & STATUS2_MULTIPLETURNS
                        || gBattleMons[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].status2 & STATUS2_RECHARGE)
                    {
                        BtlController_EmitEndBounceEffect(0);
                        MarkBattlerForControllerExec(gActiveBattler);
                        return;
                    }
                    else if (gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_SWITCH)
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 2);
                    }
                    else if (gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_RUN)
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 1);
                    }
                    else if (gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_USE_MOVE
                             && (gProtectStructs[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].noValidMoves
                                || gDisableStructs[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].encoredMove))
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 1);
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_PALACE
                             && gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_USE_MOVE)
                    {
                        gRngValue = gBattlePalaceMoveSelectionRngValue;
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 1);
                    }
                    else
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 3);
                    }
                    BtlController_EmitEndBounceEffect(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    return;
                }

                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                    && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL)
                    && gBattleBufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[gActiveBattler] = BattleScript_AskIfWantsToForfeitMatch;
                    gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT_MAY_RUN;
                    *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                         && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
                         && gBattleBufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    BattleScriptExecute(BattleScript_PrintCantRunFromTrainer);
                    gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                }
                else if (IsRunningFromBattleImpossible()
                         && gBattleBufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[gActiveBattler] = BattleScript_PrintCantEscapeFromBattle;
                    gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                    *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else
                {
                    gBattleCommunication[gActiveBattler]++;
                }
            }
            break;
        case STATE_WAIT_ACTION_CASE_CHOSEN:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
            {
                switch (gChosenActionByBattler[gActiveBattler])
                {
                case B_ACTION_USE_MOVE:
                    switch (gBattleBufferB[gActiveBattler][1])
                    {
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                        gChosenActionByBattler[gActiveBattler] = gBattleBufferB[gActiveBattler][1];
                        return;
                    case 15:
                        gChosenActionByBattler[gActiveBattler] = B_ACTION_SWITCH;
                        sub_803CDF8();
                        return;
                    default:
                        sub_818603C(2);
                        if ((gBattleBufferB[gActiveBattler][2] | (gBattleBufferB[gActiveBattler][3] << 8)) == 0xFFFF)
                        {
                            gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                            RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        }
                        else if (TrySetCantSelectMoveBattleScript())
                        {
                            RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                            gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                            *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                            gBattleBufferB[gActiveBattler][1] = B_ACTION_USE_MOVE;
                            *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_WAIT_ACTION_CHOSEN;
                            return;
                        }
                        else
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_PALACE))
                            {
                                RecordedBattle_SetBattlerAction(gActiveBattler, gBattleBufferB[gActiveBattler][2]);
                                RecordedBattle_SetBattlerAction(gActiveBattler, gBattleBufferB[gActiveBattler][3]);
                            }
                            *(gBattleStruct->chosenMovePositions + gActiveBattler) = gBattleBufferB[gActiveBattler][2];
                            gChosenMoveByBattler[gActiveBattler] = gBattleMons[gActiveBattler].moves[*(gBattleStruct->chosenMovePositions + gActiveBattler)];
                            *(gBattleStruct->moveTarget + gActiveBattler) = gBattleBufferB[gActiveBattler][3];
                            gBattleCommunication[gActiveBattler]++;
                        }
                        break;
                    }
                    break;
                case B_ACTION_USE_ITEM:
                    if ((gBattleBufferB[gActiveBattler][1] | (gBattleBufferB[gActiveBattler][2] << 8)) == 0)
                    {
                        gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    else
                    {
                        gLastUsedItem = (gBattleBufferB[gActiveBattler][1] | (gBattleBufferB[gActiveBattler][2] << 8));
                        gBattleCommunication[gActiveBattler]++;
                    }
                    break;
                case B_ACTION_SWITCH:
                    if (gBattleBufferB[gActiveBattler][1] == PARTY_SIZE)
                    {
                        gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                    }
                    else
                    {
                        sub_803CDF8();
                        gBattleCommunication[gActiveBattler]++;
                    }
                    break;
                case B_ACTION_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_WATCH_CAREFULLY:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_BALL:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_POKEBLOCK:
                    if ((gBattleBufferB[gActiveBattler][1] | (gBattleBufferB[gActiveBattler][2] << 8)) != 0)
                    {
                        gBattleCommunication[gActiveBattler]++;
                    }
                    else
                    {
                        gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    break;
                case B_ACTION_SAFARI_GO_NEAR:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_WALLY_THROW:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                }
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED_STANDBY:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
            {
                if (AllAtActionConfirmed())
                    i = TRUE;
                else
                    i = FALSE;

                if (((gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_DOUBLE)) != BATTLE_TYPE_DOUBLE)
                    || (position & BIT_FLANK) != B_FLANK_LEFT
                    || (*(&gBattleStruct->field_91) & gBitTable[GetBattlerAtPosition(position ^ BIT_FLANK)]))
                {
                    BtlController_EmitLinkStandbyMsg(0, 0, i);
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(0, 1, i);
                }
                MarkBattlerForControllerExec(gActiveBattler);
                gBattleCommunication[gActiveBattler]++;
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
            {
                gBattleCommunication[ACTIONS_CONFIRMED_COUNT]++;
            }
            break;
        case STATE_SELECTION_SCRIPT:
            if (*(gBattleStruct->selectionScriptFinished + gActiveBattler))
            {
                gBattleCommunication[gActiveBattler] = *(gBattleStruct->stateIdAfterSelScript + gActiveBattler);
            }
            else
            {
                gBattlerAttacker = gActiveBattler;
                gBattlescriptCurrInstr = gSelectionBattleScripts[gActiveBattler];
                if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gSelectionBattleScripts[gActiveBattler] = gBattlescriptCurrInstr;
            }
            break;
        case STATE_WAIT_SET_BEFORE_ACTION:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
            {
                gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
            }
            break;
        case STATE_SELECTION_SCRIPT_MAY_RUN:
            if (*(gBattleStruct->selectionScriptFinished + gActiveBattler))
            {
                if (gBattleBufferB[gActiveBattler][1] == B_ACTION_NOTHING_FAINTED)
                {
                    gHitMarker |= HITMARKER_RUN;
                    gChosenActionByBattler[gActiveBattler] = B_ACTION_RUN;
                    gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                    gBattleCommunication[gActiveBattler] = *(gBattleStruct->stateIdAfterSelScript + gActiveBattler);
                }
            }
            else
            {
                gBattlerAttacker = gActiveBattler;
                gBattlescriptCurrInstr = gSelectionBattleScripts[gActiveBattler];
                if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF0000000) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 0xC))))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gSelectionBattleScripts[gActiveBattler] = gBattlescriptCurrInstr;
            }
            break;
        }
    }

    // Check if everyone chose actions.
    if (gBattleCommunication[ACTIONS_CONFIRMED_COUNT] == gBattlersCount)
    {
        sub_818603C(1);
        gBattleMainFunc = SetActionsAndBattlersTurnOrder;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gChosenActionByBattler[i] == B_ACTION_SWITCH)
                    SwitchPartyOrderInGameMulti(i, *(gBattleStruct->monToSwitchIntoId + i));
            }
        }
    }
}

static bool8 AllAtActionConfirmed(void)
{
    s32 i, count;

    for (count = 0, i = 0; i < gBattlersCount; i++)
    {
        if (gBattleCommunication[i] == STATE_WAIT_ACTION_CONFIRMED)
            count++;
    }

    if (count + 1 == gBattlersCount)
        return TRUE;
    else
        return FALSE;
}

static void sub_803CDF8(void)
{
    *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = gBattleBufferB[gActiveBattler][1];
    RecordedBattle_SetBattlerAction(gActiveBattler, gBattleBufferB[gActiveBattler][1]);

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        *(gActiveBattler * 3 + (u8*)(gBattleStruct->field_60) + 0) &= 0xF;
        *(gActiveBattler * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleBufferB[gActiveBattler][2] & 0xF0);
        *(gActiveBattler * 3 + (u8*)(gBattleStruct->field_60) + 1) = gBattleBufferB[gActiveBattler][3];

        *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->field_60) + 0) &= (0xF0);
        *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleBufferB[gActiveBattler][2] & 0xF0) >> 4;
        *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->field_60) + 2) = gBattleBufferB[gActiveBattler][3];
    }
}

void SwapTurnOrder(u8 id1, u8 id2)
{
    u32 temp;

    SWAP(gActionsByTurnOrder[id1], gActionsByTurnOrder[id2], temp);
    SWAP(gBattlerByTurnOrder[id1], gBattlerByTurnOrder[id2], temp);
}

u8 GetWhoStrikesFirst(u8 battler1, u8 battler2, bool8 ignoreChosenMoves)
{
    u8 strikesFirst = 0;
    u8 speedMultiplierBattler1 = 0, speedMultiplierBattler2 = 0;
    u32 speedBattler1 = 0, speedBattler2 = 0;
    u8 holdEffect = 0;
    u8 holdEffectParam = 0;
    u16 moveBattler1 = 0, moveBattler2 = 0;

    if (WEATHER_HAS_EFFECT)
    {
        if ((gBattleMons[battler1].ability == ABILITY_SWIFT_SWIM && gBattleWeather & WEATHER_RAIN_ANY)
            || (gBattleMons[battler1].ability == ABILITY_CHLOROPHYLL && gBattleWeather & WEATHER_SUN_ANY))
            speedMultiplierBattler1 = 2;
        else
            speedMultiplierBattler1 = 1;

        if ((gBattleMons[battler2].ability == ABILITY_SWIFT_SWIM && gBattleWeather & WEATHER_RAIN_ANY)
            || (gBattleMons[battler2].ability == ABILITY_CHLOROPHYLL && gBattleWeather & WEATHER_SUN_ANY))
            speedMultiplierBattler2 = 2;
        else
            speedMultiplierBattler2 = 1;
    }
    else
    {
        speedMultiplierBattler1 = 1;
        speedMultiplierBattler2 = 1;
    }

    speedBattler1 = (gBattleMons[battler1].speed * speedMultiplierBattler1)
                * (gStatStageRatios[gBattleMons[battler1].statStages[STAT_SPEED]][0])
                / (gStatStageRatios[gBattleMons[battler1].statStages[STAT_SPEED]][1]);

    if (gBattleMons[battler1].item == ITEM_ENIGMA_BERRY)
    {
        holdEffect = gEnigmaBerries[battler1].holdEffect;
        holdEffectParam = gEnigmaBerries[battler1].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[battler1].item);
        holdEffectParam = ItemId_GetHoldEffectParam(gBattleMons[battler1].item);
    }

    // badge boost
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_FRONTIER))
        && FlagGet(FLAG_BADGE03_GET)
        && GetBattlerSide(battler1) == B_SIDE_PLAYER)
    {
        speedBattler1 = (speedBattler1 * 110) / 100;
    }

    if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
        speedBattler1 /= 2;

    if (gBattleMons[battler1].status1 & STATUS1_PARALYSIS)
        speedBattler1 /= 4;

    if (holdEffect == HOLD_EFFECT_QUICK_CLAW && gRandomTurnNumber < (0xFFFF * holdEffectParam) / 100)
        speedBattler1 = UINT_MAX;

    // check second battlerId's speed

    speedBattler2 = (gBattleMons[battler2].speed * speedMultiplierBattler2)
                * (gStatStageRatios[gBattleMons[battler2].statStages[STAT_SPEED]][0])
                / (gStatStageRatios[gBattleMons[battler2].statStages[STAT_SPEED]][1]);

    if (gBattleMons[battler2].item == ITEM_ENIGMA_BERRY)
    {
        holdEffect = gEnigmaBerries[battler2].holdEffect;
        holdEffectParam = gEnigmaBerries[battler2].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[battler2].item);
        holdEffectParam = ItemId_GetHoldEffectParam(gBattleMons[battler2].item);
    }

    // badge boost
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_FRONTIER))
        && FlagGet(FLAG_BADGE03_GET)
        && GetBattlerSide(battler2) == B_SIDE_PLAYER)
    {
        speedBattler2 = (speedBattler2 * 110) / 100;
    }

    if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
        speedBattler2 /= 2;

    if (gBattleMons[battler2].status1 & STATUS1_PARALYSIS)
        speedBattler2 /= 4;

    if (holdEffect == HOLD_EFFECT_QUICK_CLAW && gRandomTurnNumber < (0xFFFF * holdEffectParam) / 100)
        speedBattler2 = UINT_MAX;

    if (ignoreChosenMoves)
    {
        moveBattler1 = MOVE_NONE;
        moveBattler2 = MOVE_NONE;
    }
    else
    {
        if (gChosenActionByBattler[battler1] == B_ACTION_USE_MOVE)
        {
            if (gProtectStructs[battler1].noValidMoves)
                moveBattler1 = MOVE_STRUGGLE;
            else
                moveBattler1 = gBattleMons[battler1].moves[*(gBattleStruct->chosenMovePositions + battler1)];
        }
        else
            moveBattler1 = MOVE_NONE;

        if (gChosenActionByBattler[battler2] == B_ACTION_USE_MOVE)
        {
            if (gProtectStructs[battler2].noValidMoves)
                moveBattler2 = MOVE_STRUGGLE;
            else
                moveBattler2 = gBattleMons[battler2].moves[*(gBattleStruct->chosenMovePositions + battler2)];
        }
        else
            moveBattler2 = MOVE_NONE;
    }

    // both move priorities are different than 0
    if (gBattleMoves[moveBattler1].priority != 0 || gBattleMoves[moveBattler2].priority != 0)
    {
        // both priorities are the same
        if (gBattleMoves[moveBattler1].priority == gBattleMoves[moveBattler2].priority)
        {
            if (speedBattler1 == speedBattler2 && Random() & 1)
                strikesFirst = 2; // same speeds, same priorities
            else if (speedBattler1 < speedBattler2)
                strikesFirst = 1; // battler2 has more speed

            // else battler1 has more speed
        }
        else if (gBattleMoves[moveBattler1].priority < gBattleMoves[moveBattler2].priority)
            strikesFirst = 1; // battler2's move has greater priority

        // else battler1's move has greater priority
    }
    // both priorities are equal to 0
    else
    {
        if (speedBattler1 == speedBattler2 && Random() & 1)
            strikesFirst = 2; // same speeds, same priorities
        else if (speedBattler1 < speedBattler2)
            strikesFirst = 1; // battler2 has more speed

        // else battler1 has more speed
    }

    return strikesFirst;
}

static void SetActionsAndBattlersTurnOrder(void)
{
    s32 turnOrderId = 0;
    s32 i, j;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
    {
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
            gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
            turnOrderId++;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                {
                    turnOrderId = 5;
                    break;
                }
            }
        }
        else
        {
            if (gChosenActionByBattler[0] == B_ACTION_RUN)
            {
                gActiveBattler = 0;
                turnOrderId = 5;
            }
            if (gChosenActionByBattler[2] == B_ACTION_RUN)
            {
                gActiveBattler = 2;
                turnOrderId = 5;
            }
        }

        if (turnOrderId == 5) // One of battlers wants to run.
        {
            gActionsByTurnOrder[0] = gChosenActionByBattler[gActiveBattler];
            gBattlerByTurnOrder[0] = gActiveBattler;
            turnOrderId = 1;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i != gActiveBattler)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[i];
                    gBattlerByTurnOrder[turnOrderId] = i;
                    turnOrderId++;
                }
            }
            gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
            gBattleStruct->focusPunchBattlerId = 0;
            return;
        }
        else
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_USE_ITEM || gChosenActionByBattler[gActiveBattler] == B_ACTION_SWITCH)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
                    gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
                    turnOrderId++;
                }
            }
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] != B_ACTION_USE_ITEM && gChosenActionByBattler[gActiveBattler] != B_ACTION_SWITCH)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
                    gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
                    turnOrderId++;
                }
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    u8 battler1 = gBattlerByTurnOrder[i];
                    u8 battler2 = gBattlerByTurnOrder[j];
                    if (gActionsByTurnOrder[i] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[j] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[i] != B_ACTION_SWITCH
                        && gActionsByTurnOrder[j] != B_ACTION_SWITCH)
                    {
                        if (GetWhoStrikesFirst(battler1, battler2, FALSE))
                            SwapTurnOrder(i, j);
                    }
                }
            }
        }
    }
    gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
    gBattleStruct->focusPunchBattlerId = 0;
}

static void TurnValuesCleanUp(bool8 var0)
{
    s32 i;
    u8 *dataPtr;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (var0)
        {
            gProtectStructs[gActiveBattler].protected = 0;
            gProtectStructs[gActiveBattler].endured = 0;
        }
        else
        {
            dataPtr = (u8*)(&gProtectStructs[gActiveBattler]);
            for (i = 0; i < sizeof(struct ProtectStruct); i++)
                dataPtr[i] = 0;

            if (gDisableStructs[gActiveBattler].isFirstTurn)
                gDisableStructs[gActiveBattler].isFirstTurn--;

            if (gDisableStructs[gActiveBattler].rechargeTimer)
            {
                gDisableStructs[gActiveBattler].rechargeTimer--;
                if (gDisableStructs[gActiveBattler].rechargeTimer == 0)
                    gBattleMons[gActiveBattler].status2 &= ~(STATUS2_RECHARGE);
            }
        }

        if (gDisableStructs[gActiveBattler].substituteHP == 0)
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_SUBSTITUTE);
    }

    gSideTimers[0].followmeTimer = 0;
    gSideTimers[1].followmeTimer = 0;
}

static void SpecialStatusesClear(void)
{
    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        s32 i;
        u8 *dataPtr = (u8*)(&gSpecialStatuses[gActiveBattler]);

        for (i = 0; i < sizeof(struct SpecialStatus); i++)
            dataPtr[i] = 0;
    }
}

static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void)
{
    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->focusPunchBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattleStruct->focusPunchBattlerId;
            gBattleStruct->focusPunchBattlerId++;
            if (gChosenMoveByBattler[gActiveBattler] == MOVE_FOCUS_PUNCH
                && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                && !(gDisableStructs[gBattlerAttacker].truantCounter)
                && !(gProtectStructs[gActiveBattler].noValidMoves))
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
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

static void RunTurnActionsFunctions(void)
{
    if (gBattleOutcome != 0)
        gCurrentActionFuncId = B_ACTION_FINISHED;

    *(&gBattleStruct->savedTurnActionNumber) = gCurrentTurnActionNumber;
    sTurnActionsFuncsTable[gCurrentActionFuncId]();

    if (gCurrentTurnActionNumber >= gBattlersCount) // everyone did their actions, turn finished
    {
        gHitMarker &= ~(HITMARKER_x100000);
        gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
    }
    else
    {
        if (gBattleStruct->savedTurnActionNumber != gCurrentTurnActionNumber) // action turn has been done, clear hitmarker bits for another battlerId
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
        gSpecialVar_Result = gBattleOutcome;
        gBattleTextBuff1[0] = gBattleOutcome;
        gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
        gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_EREADER_TRAINER))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_FrontierTrainerBattleWon;

        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            PlayBGM(MUS_KACHI3);
        else
            PlayBGM(MUS_KACHI1);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_LocalTrainerBattleWon;

        switch (gTrainers[gTrainerBattleOpponent_A].trainerClass)
        {
        case TRAINER_CLASS_ELITE_FOUR:
        case TRAINER_CLASS_CHAMPION:
            PlayBGM(MUS_KACHI5);
            break;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_ADMIN:
        case TRAINER_CLASS_MAGMA_LEADER:
            PlayBGM(MUS_KACHI4);
            break;
        case TRAINER_CLASS_LEADER:
            PlayBGM(MUS_KACHI3);
            break;
        default:
            PlayBGM(MUS_KACHI1);
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
            if (gBattleOutcome & B_OUTCOME_LINK_BATTLE_RAN)
            {
                gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeitedLinkBattle;
                gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
                gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
            }
            else
            {
                gBattlescriptCurrInstr = BattleScript_82DAA0B;
                gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            }
        }
        else
        {
            gBattleTextBuff1[0] = gBattleOutcome;
            gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
            gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
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
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
    }
    else
    {
        switch (gProtectStructs[gBattlerAttacker].fleeFlag)
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

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);
    gBattlescriptCurrInstr = BattleScript_WildMonFled;

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_FinishBattle(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_x2000000
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_WALLY_TUTORIAL
                                  | BATTLE_TYPE_FRONTIER)))
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                {
                    if (gBattleResults.playerMon1Species == SPECIES_NONE)
                    {
                        gBattleResults.playerMon1Species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                        GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, gBattleResults.playerMon1Name);
                    }
                    else
                    {
                        gBattleResults.playerMon2Species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                        GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, gBattleResults.playerMon2Name);
                    }
                }
            }
            PutPokemonTodayCaughtOnAir();
        }

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_x2000000
                                  | BATTLE_TYPE_TRAINER
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_WALLY_TUTORIAL))
            && gBattleResults.shinyWildMon)
        {
            sub_80EE184();
        }

        sub_8186444();
        BeginFastPaletteFade(3);
        FadeOutMapMusic(5);
        gBattleMainFunc = FreeResetData_ReturnToOvOrDoEvolutions;
        gCB2_AfterEvolution = BattleMainCB2;
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        if (gLeveledUpInBattle == 0 || gBattleOutcome != B_OUTCOME_WON)
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
        for (i = 0; i < PARTY_SIZE; i++)
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

    gSpecialVar_Result = gBattleOutcome;
    gMain.inBattle = 0;
    gMain.callback1 = gPreBattleCallback1;

    if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
    {
        UpdateRoamerHPStatus(&gEnemyParty[0]);
        if ((gBattleOutcome & B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT)
            SetRoamerInactive();
    }

    m4aSongNumStop(SE_HINSI);
    SetMainCallback2(gMain.savedCallback);
}

void RunBattleScriptCommands_PopCallbacksStack(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (gBattleResources->battleCallbackStack->size != 0)
            gBattleResources->battleCallbackStack->size--;
        gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

void RunBattleScriptCommands(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
}

static void HandleAction_UseMove(void)
{
    u8 side;
    u8 var = 4;

    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];

    if (*(&gBattleStruct->field_91) & gBitTable[gBattlerAttacker])
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gCritMultiplier = 1;
    gBattleScripting.dmgMultiplier = 1;
    gBattleStruct->atkCancellerTracker = 0;
    gMoveResultFlags = 0;
    gMultiHitCounter = 0;
    gBattleCommunication[6] = 0;
    gCurrMovePos = gChosenMovePos = *(gBattleStruct->chosenMovePositions + gBattlerAttacker);

    // choose move
    if (gProtectStructs[gBattlerAttacker].noValidMoves)
    {
        gProtectStructs[gBattlerAttacker].noValidMoves = 0;
        gCurrentMove = gChosenMove = MOVE_STRUGGLE;
        gHitMarker |= HITMARKER_NO_PPDEDUCT;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(MOVE_STRUGGLE, 0);
    }
    else if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS || gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
    {
        gCurrentMove = gChosenMove = gLockedMoves[gBattlerAttacker];
    }
    // encore forces you to use the same move
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
             && gDisableStructs[gBattlerAttacker].encoredMove == gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrentMove = gChosenMove = gDisableStructs[gBattlerAttacker].encoredMove;
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    // check if the encored move wasn't overwritten
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
             && gDisableStructs[gBattlerAttacker].encoredMove != gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gDisableStructs[gBattlerAttacker].encoredMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].encoredMovePos = 0;
        gDisableStructs[gBattlerAttacker].encoreTimer = 0;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else if (gBattleMons[gBattlerAttacker].moves[gCurrMovePos] != gChosenMoveByBattler[gBattlerAttacker])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
    }

    if (gBattleMons[gBattlerAttacker].hp != 0)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            gBattleResults.lastUsedMovePlayer = gCurrentMove;
        else
            gBattleResults.lastUsedMoveOpponent = gCurrentMove;
    }

    // choose target
    side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
    if (gSideTimers[side].followmeTimer != 0
        && gBattleMoves[gCurrentMove].target == MOVE_TARGET_SELECTED
        && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gSideTimers[side].followmeTarget)
        && gBattleMons[gSideTimers[side].followmeTarget].hp != 0)
    {
        gBattlerTarget = gSideTimers[side].followmeTarget;
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
             && gSideTimers[side].followmeTimer == 0
             && (gBattleMoves[gCurrentMove].power != 0
                 || gBattleMoves[gCurrentMove].target != MOVE_TARGET_USER)
             && gBattleMons[*(gBattleStruct->moveTarget + gBattlerAttacker)].ability != ABILITY_LIGHTNING_ROD
             && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
    {
        side = GetBattlerSide(gBattlerAttacker);
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (side != GetBattlerSide(gActiveBattler)
                && *(gBattleStruct->moveTarget + gBattlerAttacker) != gActiveBattler
                && gBattleMons[gActiveBattler].ability == ABILITY_LIGHTNING_ROD
                && GetBattlerTurnOrderNum(gActiveBattler) < var)
            {
                var = GetBattlerTurnOrderNum(gActiveBattler);
            }
        }
        if (var == 4)
        {
            if (gBattleMoves[gChosenMove].target & MOVE_TARGET_RANDOM)
            {
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    if (Random() & 1)
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                    else
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                }
                else
                {
                    if (Random() & 1)
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
                    else
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
                }
            }
            else
            {
                gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
            }

            if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
            {
                if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
                {
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
                }
                else
                {
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_SIDE);
                    if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                        gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
                }
            }
        }
        else
        {
            gActiveBattler = gBattlerByTurnOrder[var];
            RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
            gSpecialStatuses[gActiveBattler].lightningRodRedirected = 1;
            gBattlerTarget = gActiveBattler;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
             && gBattleMoves[gChosenMove].target & MOVE_TARGET_RANDOM)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (Random() & 1)
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            if (Random() & 1)
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            else
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        }

        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget]
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
        {
            gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
        }
    }
    else
    {
        gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
        {
            if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            {
                gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
            }
            else
            {
                gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_SIDE);
                if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
            }
        }
    }

    // choose battlescript
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE
        && gProtectStructs[gBattlerAttacker].palaceUnableToUseMove)
    {
        if (gBattleMons[gBattlerAttacker].hp == 0)
        {
            gCurrentActionFuncId = B_ACTION_FINISHED;
            return;
        }
        else if (gPalaceSelectionBattleScripts[gBattlerAttacker] != NULL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            gBattlescriptCurrInstr = gPalaceSelectionBattleScripts[gBattlerAttacker];
            gPalaceSelectionBattleScripts[gBattlerAttacker] = NULL;
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
        BattleArena_AddMindPoints(gBattlerAttacker);

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

static void HandleAction_Switch(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBattlerAttacker] = 0;
    gMoveSelectionCursor[gBattlerAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, *(gBattleStruct->field_58 + gBattlerAttacker))

    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;
}

static void HandleAction_UseItem(void)
{
    gBattlerAttacker = gBattlerTarget = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);
    gLastUsedItem = gBattleBufferB[gBattlerAttacker][1] | (gBattleBufferB[gBattlerAttacker][2] << 8);

    if (gLastUsedItem <= ITEM_PREMIER_BALL) // is ball
    {
        gBattlescriptCurrInstr = gBattlescriptsForBallThrow[gLastUsedItem];
    }
    else if (gLastUsedItem == ITEM_POKE_DOLL || gLastUsedItem == ITEM_FLUFFY_TAIL)
    {
        gBattlescriptCurrInstr = gBattlescriptsForRunningByItem[0];
    }
    else if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
    {
        gBattlescriptCurrInstr = gBattlescriptsForUsingItem[0];
    }
    else
    {
        gBattleScripting.battler = gBattlerAttacker;

        switch (*(gBattleStruct->AI_itemType + (gBattlerAttacker >> 1)))
        {
        case AI_ITEM_FULL_RESTORE:
        case AI_ITEM_HEAL_HP:
            break;
        case AI_ITEM_CURE_CONDITION:
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            if (*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 1)
            {
                if (*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 0x3E)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            }
            else
            {
                while (!(*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 1))
                {
                    *(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) >>= 1;
                    gBattleCommunication[MULTISTRING_CHOOSER]++;
                }
            }
            break;
        case AI_ITEM_X_STAT:
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            if (*(gBattleStruct->AI_itemFlags + (gBattlerAttacker >> 1)) & 0x80)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            }
            else
            {
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK)
                PREPARE_STRING_BUFFER(gBattleTextBuff2, CHAR_X)

                while (!((*(gBattleStruct->AI_itemFlags + (gBattlerAttacker >> 1))) & 1))
                {
                    *(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) >>= 1;
                    gBattleTextBuff1[2]++;
                }

                gBattleScripting.animArg1 = gBattleTextBuff1[2] + 14;
                gBattleScripting.animArg2 = 0;
            }
            break;
        case AI_ITEM_GUARD_SPECS:
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            break;
        }

        gBattlescriptCurrInstr = gBattlescriptsForUsingItem[*(gBattleStruct->AI_itemType + gBattlerAttacker / 2)];
    }
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

bool8 TryRunFromBattle(u8 battler)
{
    bool8 effect = FALSE;
    u8 holdEffect;
    u8 pyramidMultiplier;
    u8 speedVar;

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[battler].item);

    gPotentialItemEffectBattler = battler;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
    {
        gLastUsedItem = gBattleMons[battler].item;
        gProtectStructs[battler].fleeFlag = 1;
        effect++;
    }
    else if (gBattleMons[battler].ability == ABILITY_RUN_AWAY)
    {
        if (InBattlePyramid())
        {
            gBattleStruct->runTries++;
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[BATTLE_OPPOSITE(battler)].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
            {
                gLastUsedAbility = ABILITY_RUN_AWAY;
                gProtectStructs[battler].fleeFlag = 2;
                effect++;
            }
        }
        else
        {
            gLastUsedAbility = ABILITY_RUN_AWAY;
            gProtectStructs[battler].fleeFlag = 2;
            effect++;
        }
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL) && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        effect++;
    }
    else
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            if (InBattlePyramid())
            {
                pyramidMultiplier = GetPyramidRunMultiplier();
                speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[BATTLE_OPPOSITE(battler)].speed) + (gBattleStruct->runTries * 30);
                if (speedVar > (Random() & 0xFF))
                    effect++;
            }
            else if (gBattleMons[battler].speed < gBattleMons[BATTLE_OPPOSITE(battler)].speed)
            {
                speedVar = (gBattleMons[battler].speed * 128) / (gBattleMons[BATTLE_OPPOSITE(battler)].speed) + (gBattleStruct->runTries * 30);
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
        gCurrentTurnActionNumber = gBattlersCount;
        gBattleOutcome = B_OUTCOME_RAN;
    }

    return effect;
}

static void HandleAction_Run(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
    {
        gCurrentTurnActionNumber = gBattlersCount;

        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_LOST;
            }
            else
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_WON;
            }
        }

        gBattleOutcome |= B_OUTCOME_LINK_BATTLE_RAN;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (!TryRunFromBattle(gBattlerAttacker)) // failed to run away
            {
                ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
        }
        else
        {
            if (gBattleMons[gBattlerAttacker].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
            else
            {
                gCurrentTurnActionNumber = gBattlersCount;
                gBattleOutcome = B_OUTCOME_MON_FLED;
            }
        }
    }
}

static void HandleAction_WatchesCarefully(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

static void HandleAction_SafariZoneBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gNumSafariBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = gBattlescriptsForBallThrow[ITEM_SAFARI_BALL];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

static void HandleAction_ThrowPokeblock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleBufferB[gBattlerAttacker][1] - 1;
    gLastUsedItem = gBattleBufferB[gBattlerAttacker][2];

    if (gBattleResults.pokeblockThrows < 0xFF)
        gBattleResults.pokeblockThrows++;
    if (gBattleStruct->safariPkblThrowCounter < 3)
        gBattleStruct->safariPkblThrowCounter++;
    if (gBattleStruct->safariEscapeFactor > 1)
    {
        if (gBattleStruct->safariEscapeFactor < sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
            gBattleStruct->safariEscapeFactor = 1;
        else
            gBattleStruct->safariEscapeFactor -= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]];
    }

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

static void HandleAction_GoNear(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariCatchFactor += sGoNearCounterToCatchFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariCatchFactor > 20)
        gBattleStruct->safariCatchFactor = 20;

    gBattleStruct->safariEscapeFactor += sGoNearCounterToEscapeFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariEscapeFactor > 20)
        gBattleStruct->safariEscapeFactor = 20;

    if (gBattleStruct->safariGoNearCounter < 3)
    {
        gBattleStruct->safariGoNearCounter++;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 1; // Can't get closer.
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

static void HandleAction_SafariZoneRun(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_NIGERU);
    gCurrentTurnActionNumber = gBattlersCount;
    gBattleOutcome = B_OUTCOME_RAN;
}

static void HandleAction_WallyBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[3];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
    gActionsByTurnOrder[1] = B_ACTION_FINISHED;
}

static void HandleAction_TryFinish(void)
{
    if (!HandleFaintedMonActions())
    {
        gBattleStruct->faintedActionsState = 0;
        gCurrentActionFuncId = B_ACTION_FINISHED;
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
                    | HITMARKER_CHARGING | HITMARKER_x4000000);
}

static void HandleAction_ActionFinished(void)
{
    *(gBattleStruct->monToSwitchIntoId + gBattlerByTurnOrder[gCurrentTurnActionNumber]) = 6;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_IGNORE_ON_AIR
                    | HITMARKER_IGNORE_UNDERGROUND | HITMARKER_IGNORE_UNDERWATER | HITMARKER_x100000
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_x4000000);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLastLandedMoves[gBattlerAttacker] = 0;
    gLastHitByType[gBattlerAttacker] = 0;
    gBattleStruct->dynamicMoveType = 0;
    gDynamicBasePower = 0;
    gBattleScripting.moveendState = 0;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}


