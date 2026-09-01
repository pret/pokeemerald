#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "battle_ai_record.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_end_turn.h"
#include "battle_hold_effects.h"
#include "battle_interface.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_pyramid.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "battle_gimmick.h"
#include "berry.h"
#include "bg.h"
#include "data.h"
#include "debug.h"
#include "decompress.h"
#include "dexnav.h"
#include "dma3.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "frontier_util.h"
#include "field_weather.h"
#include "follower_npc.h"
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
#include "pokerus.h"
#include "random.h"
#include "recorded_battle.h"
#include "roamer.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "test/battle.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_util.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_partner.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainer_slide.h"
#include "constants/trainers.h"
#include "constants/weather.h"
#include "cable_club.h"

extern const struct BgTemplate gBattleBgTemplates[];
extern const struct WindowTemplate *const gBattleWindowTemplates[];

static void CB2_InitBattleInternal(void);
static void CB2_PreInitMultiBattle(void);
static void CB2_PreInitIngamePlayerPartnerBattle(void);
static void CB2_HandleStartMultiPartnerBattle(void);
static void CB2_HandleStartMultiBattle(void);
static void CB2_HandleStartBattle(void);
static void TryCorrectShedinjaLanguage(struct Pokemon *mon);
static void BattleMainCB1(void);
static void CB2_EndLinkBattle(void);
static void EndLinkBattleInSteps(void);
static void CB2_InitAskRecordBattle(void);
static void CB2_AskRecordBattle(void);
static void AskRecordBattle(void);
static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite);
static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite);
static void SpriteCB_WildMonAnimate(struct Sprite *sprite);
static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite);
static void SpriteCB_BlinkVisible(struct Sprite *sprite);
static void SpriteCB_Idle(struct Sprite *sprite);
static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite);
static void TurnValuesCleanUp(bool32 endTurn);
static void SpriteCB_BounceEffect(struct Sprite *sprite);
static void BattleStartClearSetData(void);
static void DoBattleIntro(void);
static void TryDoEventsBeforeFirstTurn(void);
static void HandleTurnActionSelectionState(void);
static void RunTurnActionsFunctions(void);
static void SetActionsAndBattlersTurnOrder(void);
static void UpdateBattlerPartyOrdersOnSwitch(enum BattlerId battler);
static bool8 AllAtActionConfirmed(void);
static void TryChangeTurnOrder(void);
static void TryChangingTurnOrderEffects(struct BattleCalcValues *calcValues, u32 *quickClawRandom, u32 *quickDrawRandom);
static void CheckChangingTurnOrderEffects(void);
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
EWRAM_DATA u8 gDisplayedStringBattle[425] = {0}; // Increased in size to fit Juan's defeat text (SootopolisCity_Gym_1F_Text_JuanDefeat)
EWRAM_DATA u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT + 13] = {0};   // expanded for stupidly long z move names
EWRAM_DATA u32 gBattleTypeFlags = 0;
EWRAM_DATA u8 gBattleEnvironment = 0;
EWRAM_DATA struct MultiPartnerMenuPokemon *gMultiPartnerParty = NULL;
EWRAM_DATA u8 *gBattleAnimBgTileBuffer = NULL;
EWRAM_DATA u8 *gBattleAnimBgTilemapBuffer = NULL;
EWRAM_DATA u32 gBattleControllerExecFlags = 0;
EWRAM_DATA u8 gBattlersCount = 0;
EWRAM_DATA u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerPositions[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA enum BattlerId gBattlerByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA enum BattlerId gBattlersBySpeed[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA enum BattlerId gBattlersByRawSpeed[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrentTurnActionNumber = 0;
EWRAM_DATA u8 gCurrentActionFuncId = 0;
EWRAM_DATA struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerSpriteIds[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrMovePos = 0;
EWRAM_DATA u8 gChosenMovePos = 0;
EWRAM_DATA u16 gCurrentMove = 0;
EWRAM_DATA u16 gChosenMove = 0;
EWRAM_DATA u16 gCalledMove = 0;
EWRAM_DATA s32 gBideDmg[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA enum Item gLastUsedItem = ITEM_NONE;
EWRAM_DATA enum Ability gLastUsedAbility = ABILITY_NONE;
EWRAM_DATA enum BattlerId gBattlerAttacker = 0;
EWRAM_DATA enum BattlerId gBattlerTarget = 0;
EWRAM_DATA enum BattlerId gBattlerFainted = 0;
EWRAM_DATA enum BattlerId gEffectBattler = 0;
EWRAM_DATA enum BattlerId gPotentialItemEffectBattler = 0;
EWRAM_DATA u8 gAbsentBattlerFlags = 0;
EWRAM_DATA u8 gMultiHitCounter = 0;
EWRAM_DATA const u8 *gBattlescriptCurrInstr = NULL;
EWRAM_DATA u8 gChosenActionByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA const u8 *gSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA const u8 *gPalaceSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA u16 gLastPrintedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastLandedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastHitByType[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedMoveType[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastResultingMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLockedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedMove = 0;
EWRAM_DATA u8 gLastHitBy[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gChosenMoveByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u32 gHitMarker = 0;
EWRAM_DATA u8 gBideTarget[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u32 gSideStatuses[NUM_BATTLE_SIDES] = {0};
EWRAM_DATA struct SideTimer gSideTimers[NUM_BATTLE_SIDES] = {0};
EWRAM_DATA u16 gPauseCounterBattle = 0;
EWRAM_DATA u16 gPaydayMoney = 0;
EWRAM_DATA u8 gBattleCommunication[BATTLE_COMMUNICATION_ENTRIES_COUNT] = {0};
EWRAM_DATA u8 gBattleOutcome = 0;
EWRAM_DATA struct ProtectStruct gProtectStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct SpecialStatus gSpecialStatuses[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gBattleWeather = 0;
EWRAM_DATA u16 gIntroSlideFlags = 0;
EWRAM_DATA u8 gSentPokesToOpponent[2] = {0};
EWRAM_DATA struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleScripting gBattleScripting = {0};
EWRAM_DATA struct BattleStruct *gBattleStruct = NULL;
EWRAM_DATA struct StartingStatuses gStartingStatuses = {0};
EWRAM_DATA struct AiThinkingStruct *gAiThinkingStruct = NULL;
EWRAM_DATA struct AiLogicData *gAiLogicData = NULL;
EWRAM_DATA struct AiPartyData *gAiPartyData = NULL;
EWRAM_DATA struct BattleHistory *gBattleHistory = NULL;
EWRAM_DATA struct AiBattleData *gAiBattleData = NULL;

EWRAM_DATA u8 *gLinkBattleSendBuffer = NULL;
EWRAM_DATA u8 *gLinkBattleRecvBuffer = NULL;
EWRAM_DATA struct BattleResources *gBattleResources = NULL;
EWRAM_DATA u8 gActionSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gMoveSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerStatusSummaryTaskId[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerInMenuId = 0;
EWRAM_DATA bool8 gDoingBattleAnim = FALSE;
EWRAM_DATA u32 gTransformedPersonalities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA bool8 gTransformedShininess[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gPlayerDpadHoldFrames = 0;
EWRAM_DATA struct BattleSpriteData *gBattleSpritesDataPtr = NULL;
EWRAM_DATA struct MonSpritesGfx *gMonSpritesGfxPtr = NULL;
EWRAM_DATA u16 gBattleMovePower = 0;
EWRAM_DATA u16 gMoveToLearn = 0;
EWRAM_DATA u32 gFieldStatuses = 0;
EWRAM_DATA struct FieldTimer gFieldTimers = {0};
EWRAM_DATA u16 gBattleTurnCounter = 0;
EWRAM_DATA enum BattlerId gBattlerAbility = 0;
EWRAM_DATA struct QueuedStatBoost gQueuedStatBoosts[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA bool8 gHasFetchedBall = FALSE;
EWRAM_DATA u16 gLastUsedBall = 0;
EWRAM_DATA u16 gLastThrownBall = 0;
EWRAM_DATA u16 gBallToDisplay = 0;
EWRAM_DATA bool8 gLastUsedBallMenuPresent = FALSE;
EWRAM_DATA u8 gPartyCriticalHits[PARTY_SIZE] = {0};
EWRAM_DATA u8 gCategoryIconSpriteId = 0;

COMMON_DATA MainCallback gPreBattleCallback1 = NULL;
COMMON_DATA void (*gBattleMainFunc)(void) = NULL;
COMMON_DATA struct BattleResults gBattleResults = {0};
COMMON_DATA u8 gLeveledUpInBattle = 0;
COMMON_DATA u8 gHealthboxSpriteIds[MAX_BATTLERS_COUNT] = {0};
COMMON_DATA u8 gMultiUsePlayerCursor = 0;
COMMON_DATA u8 gNumberOfMovesToChoose = 0;

static const struct ScanlineEffectParams sIntroScanlineParams16Bit =
{
    &REG_BG3HOFS, SCANLINE_EFFECT_DMACNT_16BIT, 1
};

// unused
static const struct ScanlineEffectParams sIntroScanlineParams32Bit =
{
    &REG_BG3HOFS, SCANLINE_EFFECT_DMACNT_32BIT, 1
};

static const u8 sText_ShedinjaJpnName[] = _("ヌケニン"); // Nukenin

const struct OamData gOamData_BattleSpriteOpponentSide =
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

const struct OamData gOamData_BattleSpritePlayerSide =
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

static const s8 sCenterToCornerVecXs[8] ={-32, -16, -16, -32, -32};

#include "data/types_info.h"

// [TRAINER_CLASS_XYZ] = { _("name"), <money=5>, <ball=BALL_POKE> }
const struct TrainerClass gTrainerClasses[TRAINER_CLASS_COUNT] =
{
    [TRAINER_CLASS_PKMN_TRAINER_1] = { _("{PKMN} TRAINER") },
    [TRAINER_CLASS_PKMN_TRAINER_2] = { _("{PKMN} TRAINER") },
    [TRAINER_CLASS_HIKER] = { _("HIKER"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_ULTRA : BALL_POKE },
    [TRAINER_CLASS_TEAM_AQUA] = { _("TEAM AQUA") },
    [TRAINER_CLASS_PKMN_BREEDER] = { _("{PKMN} BREEDER"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_HEAL : BALL_FRIEND },
    [TRAINER_CLASS_COOLTRAINER] = { _("COOLTRAINER"), 12, BALL_ULTRA },
    [TRAINER_CLASS_BIRD_KEEPER] = { _("BIRD KEEPER"), 8 },
    [TRAINER_CLASS_COLLECTOR] = { _("COLLECTOR"), 15, BALL_PREMIER },
    [TRAINER_CLASS_SWIMMER_M] = { _("SWIMMER♂"), 2, BALL_DIVE },
    [TRAINER_CLASS_TEAM_MAGMA] = { _("TEAM MAGMA") },
    [TRAINER_CLASS_EXPERT] = { _("EXPERT"), 10 },
    [TRAINER_CLASS_AQUA_ADMIN] = { _("AQUA ADMIN"), 10 },
    [TRAINER_CLASS_BLACK_BELT] = { _("BLACK BELT"), 8, BALL_ULTRA },
    [TRAINER_CLASS_AQUA_LEADER] = { _("AQUA LEADER"), 20, BALL_MASTER },
    [TRAINER_CLASS_HEX_MANIAC] = { _("HEX MANIAC"), 6 },
    [TRAINER_CLASS_AROMA_LADY] = { _("AROMA LADY"), 10 },
    [TRAINER_CLASS_RUIN_MANIAC] = { _("RUIN MANIAC"), 15 },
    [TRAINER_CLASS_INTERVIEWER] = { _("INTERVIEWER"), 12 },
    [TRAINER_CLASS_TUBER_F] = { _("TUBER"), 1 },
    [TRAINER_CLASS_TUBER_M] = { _("TUBER"), 1 },
    [TRAINER_CLASS_LADY] = { _("LADY"), 50 },
    [TRAINER_CLASS_BEAUTY] = { _("BEAUTY"), 20, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_GREAT : BALL_POKE },
    [TRAINER_CLASS_RICH_BOY] = { _("RICH BOY"), 50 },
    [TRAINER_CLASS_POKEMANIAC] = { _("POKéMANIAC"), 15 },
    [TRAINER_CLASS_GUITARIST] = { _("GUITARIST"), 8 },
    [TRAINER_CLASS_KINDLER] = { _("KINDLER"), 8 },
    [TRAINER_CLASS_CAMPER] = { _("CAMPER"), 4 },
    [TRAINER_CLASS_PICNICKER] = { _("PICNICKER"), 4 },
    [TRAINER_CLASS_BUG_MANIAC] = { _("BUG MANIAC"), 15 },
    [TRAINER_CLASS_PSYCHIC] = { _("PSYCHIC"), 6 },
    [TRAINER_CLASS_GENTLEMAN] = { _("GENTLEMAN"), 20, BALL_LUXURY },
    [TRAINER_CLASS_ELITE_FOUR] = { _("ELITE FOUR"), 25, BALL_ULTRA },
    [TRAINER_CLASS_LEADER] = { _("LEADER"), 25, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_ULTRA : BALL_POKE },
    [TRAINER_CLASS_SCHOOL_KID] = { _("SCHOOL KID") },
    [TRAINER_CLASS_SR_AND_JR] = { _("SR. AND JR."), 4 },
    [TRAINER_CLASS_WINSTRATE] = { _("WINSTRATE"), 10 },
    [TRAINER_CLASS_POKEFAN] = { _("POKéFAN"), 20 },
    [TRAINER_CLASS_YOUNGSTER] = { _("YOUNGSTER"), 4 },
    [TRAINER_CLASS_CHAMPION] = { _("CHAMPION"), 50, BALL_ULTRA },
    [TRAINER_CLASS_FISHERMAN] = { _("FISHERMAN"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_DIVE : BALL_LURE },
    [TRAINER_CLASS_TRIATHLETE] = { _("TRIATHLETE"), 10 },
    [TRAINER_CLASS_DRAGON_TAMER] = { _("DRAGON TAMER"), 12 },
    [TRAINER_CLASS_NINJA_BOY] = { _("NINJA BOY"), 3 },
    [TRAINER_CLASS_BATTLE_GIRL] = { _("BATTLE GIRL"), 6 },
    [TRAINER_CLASS_PARASOL_LADY] = { _("PARASOL LADY"), 10 },
    [TRAINER_CLASS_SWIMMER_F] = { _("SWIMMER♀"), 2, BALL_DIVE },
    [TRAINER_CLASS_TWINS] = { _("TWINS"), 3 },
    [TRAINER_CLASS_SAILOR] = { _("SAILOR"), 8 },
    [TRAINER_CLASS_COOLTRAINER_2] = { _("COOLTRAINER"), 5, BALL_ULTRA },
    [TRAINER_CLASS_MAGMA_ADMIN] = { _("MAGMA ADMIN"), 10 },
    [TRAINER_CLASS_RIVAL] = { _("{PKMN} TRAINER"), 15 },
    [TRAINER_CLASS_BUG_CATCHER] = { _("BUG CATCHER"), 4 },
    [TRAINER_CLASS_PKMN_RANGER] = { _("{PKMN} RANGER"), 12 },
    [TRAINER_CLASS_MAGMA_LEADER] = { _("MAGMA LEADER"), 20, BALL_MASTER },
    [TRAINER_CLASS_LASS] = { _("LASS"), 4 },
    [TRAINER_CLASS_YOUNG_COUPLE] = { _("YOUNG COUPLE"), 8 },
    [TRAINER_CLASS_OLD_COUPLE] = { _("OLD COUPLE"), 10 },
    [TRAINER_CLASS_SIS_AND_BRO] = { _("SIS AND BRO"), 3 },
    [TRAINER_CLASS_SALON_MAIDEN] = { _("SALON MAIDEN"), 5, BALL_ULTRA },
    [TRAINER_CLASS_DOME_ACE] = { _("DOME ACE") },
    [TRAINER_CLASS_PALACE_MAVEN] = { _("PALACE MAVEN") },
    [TRAINER_CLASS_ARENA_TYCOON] = { _("ARENA TYCOON") },
    [TRAINER_CLASS_FACTORY_HEAD] = { _("FACTORY HEAD") },
    [TRAINER_CLASS_PIKE_QUEEN] = { _("PIKE QUEEN") },
    [TRAINER_CLASS_PYRAMID_KING] = { _("PYRAMID KING") },
    [TRAINER_CLASS_RS_PROTAG] = { _("{PKMN} TRAINER") },

    [TRAINER_CLASS_YOUNGSTER_FRLG] =       { _("YOUNGSTER"), 4 },
    [TRAINER_CLASS_BUG_CATCHER_FRLG] =     { _("BUG CATCHER"), 3 },
    [TRAINER_CLASS_LASS_FRLG] =            { _("LASS"), 4 },
    [TRAINER_CLASS_SAILOR_FRLG] =          { _("SAILOR"), 8 },
    [TRAINER_CLASS_CAMPER_FRLG] =          { _("CAMPER"), 5 },
    [TRAINER_CLASS_PICNICKER_FRLG] =       { _("PICNICKER"), 5 },
    [TRAINER_CLASS_POKEMANIAC_FRLG] =      { _("POKéMANIAC"), 12 },
    [TRAINER_CLASS_SUPER_NERD_FRLG] =      { _("SUPER NERD"), 6 },
    [TRAINER_CLASS_HIKER_FRLG] =           { _("HIKER"), 9 },
    [TRAINER_CLASS_BIKER_FRLG] =           { _("BIKER"), 5 },
    [TRAINER_CLASS_BURGLAR_FRLG] =         { _("BURGLAR"), 22 },
    [TRAINER_CLASS_ENGINEER_FRLG] =        { _("ENGINEER"), 12 },
    [TRAINER_CLASS_FISHERMAN_FRLG] =       { _("FISHERMAN"), 9, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_DIVE : BALL_LURE },
    [TRAINER_CLASS_SWIMMER_M_FRLG] =       { _("SWIMMER♂"), 1 },
    [TRAINER_CLASS_CUE_BALL_FRLG] =        { _("CUE BALL"), 6 },
    [TRAINER_CLASS_GAMER_FRLG] =           { _("GAMER"), 18 },
    [TRAINER_CLASS_BEAUTY_FRLG] =          { _("BEAUTY"), 18 },
    [TRAINER_CLASS_SWIMMER_F_FRLG] =       { _("SWIMMER♀"), 1, BALL_DIVE },
    [TRAINER_CLASS_PSYCHIC_FRLG] =         { _("PSYCHIC"), 5 },
    [TRAINER_CLASS_ROCKER_FRLG] =          { _("ROCKER"), 6 },
    [TRAINER_CLASS_JUGGLER_FRLG] =         { _("JUGGLER"), 10 },
    [TRAINER_CLASS_TAMER_FRLG] =           { _("TAMER"), 10 },
    [TRAINER_CLASS_BIRD_KEEPER_FRLG] =     { _("BIRD KEEPER"), 6 },
    [TRAINER_CLASS_BLACK_BELT_FRLG] =      { _("BLACK BELT"), 6, BALL_ULTRA },
    [TRAINER_CLASS_RIVAL_EARLY_FRLG] =     { _("RIVAL"), 4 },
    [TRAINER_CLASS_SCIENTIST_FRLG] =       { _("SCIENTIST"), 12 },
    [TRAINER_CLASS_BOSS_FRLG] =            { _("BOSS"), 25 },
    [TRAINER_CLASS_LEADER_FRLG] =          { _("LEADER"), 25 },
    [TRAINER_CLASS_TEAM_ROCKET_FRLG] =     { _("TEAM ROCKET"), 8 },
    [TRAINER_CLASS_COOLTRAINER_FRLG] =     { _("COOLTRAINER"), 9, BALL_ULTRA },
    [TRAINER_CLASS_ELITE_FOUR_FRLG] =      { _("ELITE FOUR"), 25, BALL_ULTRA },
    [TRAINER_CLASS_GENTLEMAN_FRLG] =       { _("GENTLEMAN"), 18, BALL_LUXURY },
    [TRAINER_CLASS_RIVAL_LATE_FRLG] =      { _("RIVAL"), 9 },
    [TRAINER_CLASS_CHAMPION_FRLG] =        { _("CHAMPION"), 25 },
    [TRAINER_CLASS_CHANNELER_FRLG] =       { _("CHANNELER"), 8 },
    [TRAINER_CLASS_TWINS_FRLG] =           { _("TWINS"), 3 },
    [TRAINER_CLASS_COOL_COUPLE_FRLG] =     { _("COOL COUPLE"), 6 },
    [TRAINER_CLASS_YOUNG_COUPLE_FRLG] =    { _("YOUNG COUPLE"), 7 },
    [TRAINER_CLASS_CRUSH_KIN_FRLG] =       { _("CRUSH KIN"), 6 },
    [TRAINER_CLASS_SIS_AND_BRO_FRLG] =     { _("SIS AND BRO"), 1 },
    [TRAINER_CLASS_PKMN_PROF_FRLG] =       { _("{PKMN} PROF."), 25 },
    [TRAINER_CLASS_PLAYER_FRLG] =          { _("{PKMN} TRAINER"), 1 },
    [TRAINER_CLASS_CRUSH_GIRL_FRLG] =      { _("CRUSH GIRL"), 6 },
    [TRAINER_CLASS_TUBER_FRLG] =           { _("TUBER"), 1 },
    [TRAINER_CLASS_PKMN_BREEDER_FRLG] =    { _("{PKMN} BREEDER"), 7, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_HEAL : BALL_FRIEND },
    [TRAINER_CLASS_PKMN_RANGER_FRLG] =     { _("{PKMN} RANGER"), 9 },
    [TRAINER_CLASS_AROMA_LADY_FRLG] =      { _("AROMA LADY"), 7 },
    [TRAINER_CLASS_RUIN_MANIAC_FRLG] =     { _("RUIN MANIAC"), 12 },
    [TRAINER_CLASS_LADY_FRLG] =            { _("LADY"), 50 },
    [TRAINER_CLASS_PAINTER_FRLG] =         { _("PAINTER"), 4 },
};

static void (*const sTurnActionsFuncsTable[])(void) =
{
    [B_ACTION_USE_MOVE]               = HandleAction_UseMove,
    [B_ACTION_USE_ITEM]               = HandleAction_UseItem,
    [B_ACTION_SWITCH]                 = HandleAction_Switch,
    [B_ACTION_RUN]                    = HandleAction_Run,
    [B_ACTION_SAFARI_WATCH_CAREFULLY] = HandleAction_WatchesCarefully,
    [B_ACTION_SAFARI_BALL]            = HandleAction_SafariZoneBallThrow,
    [B_ACTION_SAFARI_POKEBLOCK]       = HandleAction_ThrowPokeblock,
    [B_ACTION_SAFARI_GO_NEAR]         = HandleAction_GoNear,
    [B_ACTION_SAFARI_RUN]             = HandleAction_SafariZoneRun,
    [B_ACTION_WALLY_THROW]            = HandleAction_WallyBallThrow,
    [B_ACTION_EXEC_SCRIPT]            = HandleAction_RunBattleScript,
    [B_ACTION_TRY_FINISH]             = HandleAction_TryFinish,
    [B_ACTION_FINISHED]               = HandleAction_ActionFinished,
    [B_ACTION_NOTHING_FAINTED]        = HandleAction_NothingIsFainted,
    [B_ACTION_THROW_BALL]             = HandleAction_ThrowBall,
};

static void (*const sEndTurnFuncsTable[])(void) =
{
    [0]                           = HandleEndTurn_ContinueBattle,
    [B_OUTCOME_WON]               = HandleEndTurn_BattleWon,
    [B_OUTCOME_LOST]              = HandleEndTurn_BattleLost,
    [B_OUTCOME_DREW]              = HandleEndTurn_BattleLost,
    [B_OUTCOME_RAN]               = HandleEndTurn_RanFromBattle,
    [B_OUTCOME_PLAYER_TELEPORTED] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_FLED]          = HandleEndTurn_MonFled,
    [B_OUTCOME_CAUGHT]            = HandleEndTurn_FinishBattle,
    [B_OUTCOME_NO_SAFARI_BALLS]   = HandleEndTurn_FinishBattle,
    [B_OUTCOME_FORFEITED]         = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_TELEPORTED]    = HandleEndTurn_FinishBattle,
};

const u8 gStatusConditionString_PoisonJpn[] = _("どく$$$$$");
const u8 gStatusConditionString_SleepJpn[] = _("ねむり$$$$");
const u8 gStatusConditionString_ParalysisJpn[] = _("まひ$$$$$");
const u8 gStatusConditionString_BurnJpn[] = _("やけど$$$$");
const u8 gStatusConditionString_IceJpn[] = _("こおり$$$$");
const u8 gStatusConditionString_ConfusionJpn[] = _("こんらん$$$");
const u8 gStatusConditionString_LoveJpn[] = _("メロメロ$$$");

const u8 *const gStatusConditionStringsTable[][2] =
{
    {gStatusConditionString_PoisonJpn, gText_Poison},
    {gStatusConditionString_SleepJpn, gText_Sleep},
    {gStatusConditionString_ParalysisJpn, gText_Paralysis},
    {gStatusConditionString_BurnJpn, gText_Burn},
    {gStatusConditionString_IceJpn, gText_Ice},
    {gStatusConditionString_ConfusionJpn, gText_Confusion},
    {gStatusConditionString_LoveJpn, gText_Love}
};

void CB2_InitBattle(void)
{
    if (!gTestRunnerEnabled)
        MoveSaveBlocks_ResetHeap();
    AllocateBattleResources();
    AllocateBattleSpritesData();
    AllocateMonSpritesGfx();
    RecordedBattle_ClearFrontierPassFlag();

#if TESTING
    gLoadFail = FALSE;
#endif // TESTING

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
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

    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    gBattle_WIN0H = DISPLAY_WIDTH;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId < TRAINER_PARTNER(PARTNER_NONE))
    {
        gBattle_WIN0V = DISPLAY_HEIGHT - 1;
        gBattle_WIN1H = DISPLAY_WIDTH;
        gBattle_WIN1V = 32;
    }
    else
    {
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
        ScanlineEffect_Clear();
        if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless)
        {
            for (i = 0; i < DISPLAY_HEIGHT / 2; i++)
            {
                gScanlineEffectRegBuffers[0][i] = 0xF0;
                gScanlineEffectRegBuffers[1][i] = 0xF0;
            }

            for (; i < DISPLAY_HEIGHT; i++)
            {
                gScanlineEffectRegBuffers[0][i] = 0xFF10;
                gScanlineEffectRegBuffers[1][i] = 0xFF10;
            }

            ScanlineEffect_SetParams(sIntroScanlineParams16Bit);
        }
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

    if (!DEBUG_OVERWORLD_MENU || (DEBUG_OVERWORLD_MENU && !gIsDebugBattle))
        gBattleEnvironment = BattleSetup_GetEnvironmentId();
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        gBattleEnvironment = BATTLE_ENVIRONMENT_BUILDING;
    if (TestRunner_Battle_GetForcedEnvironment())
        gBattleEnvironment = TestRunner_Battle_GetForcedEnvironment() - 1;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless)
        DrawBattleEntryBackground();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
    SetVBlankCallback(VBlankCB_Battle);
    SetUpBattleVarsAndBirchZigzagoon();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI
     && (TESTING || gBattleTypeFlags & (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_INGAME_PARTNER)))
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        SetMainCallback2(CB2_HandleStartMultiBattle);
    else
        SetMainCallback2(CB2_HandleStartBattle);

    gMain.inBattle = TRUE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        AdjustFriendship(&gParties[B_TRAINER_PLAYER][i], FRIENDSHIP_EVENT_LEAGUE_BATTLE);

        // Apply party-wide start-of-battle form changes for both sides.
        for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
            TryFormChange(&gParties[trainer][i], FORM_CHANGE_BEGIN_BATTLE, trainer);
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
    {
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_PYRAMID | BATTLE_TYPE_PIKE)))
            SetWildMonHeldItem();
        TryFormChange(&gParties[B_TRAINER_OPPONENT_A][0], FORM_CHANGE_BEGIN_WILD_ENCOUNTER, B_TRAINER_OPPONENT_A);
        if (IsDoubleBattle())
            TryFormChange(&gParties[B_TRAINER_OPPONENT_A][1], FORM_CHANGE_BEGIN_WILD_ENCOUNTER, B_TRAINER_OPPONENT_A);
    }

    for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
        gPartiesCount[trainer] = CalculatePartyCount(trainer);

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

#define BUFFER_PARTY_VS_SCREEN_STATUS(party, flags, i)                      \
    for ((i) = 0; (i) < PARTY_SIZE; (i)++)                                  \
    {                                                                       \
        enum Species species = GetMonData(&(party)[(i)], MON_DATA_SPECIES_OR_EGG);   \
        u16 hp = GetMonData(&(party)[(i)], MON_DATA_HP);                    \
        u32 status = GetMonData(&(party)[(i)], MON_DATA_STATUS);            \
                                                                            \
        if (species == SPECIES_NONE)                                        \
            continue;                                                       \
                                                                            \
        /* Is healthy mon? */                                               \
        if (species != SPECIES_EGG && hp != 0 && status == 0)               \
            (flags) |= 1 << (i) * 2;                                        \
                                                                            \
        if (species == SPECIES_NONE) /* Redundant */                        \
            continue;                                                       \
                                                                            \
        /* Is Egg or statused? */                                           \
        if (hp != 0 && (species == SPECIES_EGG || status != 0))             \
            (flags) |= 2 << (i) * 2;                                        \
                                                                            \
        if (species == SPECIES_NONE) /* Redundant */                        \
            continue;                                                       \
                                                                            \
        /* Is fainted? */                                                   \
        if (species != SPECIES_EGG && hp == 0)                              \
            (flags) |= 3 << (i) * 2;                                        \
    }

// For Vs Screen at link battle start
static void BufferPartyVsScreenHealth_AtStart(void)
{
    u16 flags = 0;
    s32 i;

    BUFFER_PARTY_VS_SCREEN_STATUS(gParties[B_TRAINER_PLAYER], flags, i);
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo = flags;
    *(&gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi) = flags >> 8;
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi |= FlagGet(FLAG_SYS_FRONTIER_PASS) << 7;
}

static void SetPlayerBerryDataInBattleStruct(void)
{
    s32 i;
    struct BattleStruct *battleStruct = gBattleStruct;
    struct BattleEnigmaBerry *battleBerry = &battleStruct->multiBuffer.linkBattlerHeader.battleEnigmaBerry;

    if (IsEnigmaBerryValid() == TRUE)
    {
    #if FREE_ENIGMA_BERRY == FALSE
        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];

        battleBerry->holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        battleBerry->holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
    #endif //FREE_ENIGMA_BERRY
    }
    else
    {
        const struct BerryInfo *berryInfo = GetBerryInfo(BERRY_ID_ENGIMA_E_READER);

        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = berryInfo->name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = 0;

        battleBerry->holdEffect = HOLD_EFFECT_NONE;
        battleBerry->holdEffectParam = 0;
    }
}

static void SetAllPlayersBerryData(void)
{
    s32 i, j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        if (IsEnigmaBerryValid() == TRUE)
        {
        #if FREE_ENIGMA_BERRY == FALSE
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
        #endif //FREE_ENIGMA_BERRY
        }
        else
        {
            const struct BerryInfo *berryInfo = GetBerryInfo(BERRY_ID_ENGIMA_E_READER);

            for (i = 0; i < BERRY_NAME_LENGTH; i++)
            {
                gEnigmaBerries[0].name[i] = berryInfo->name[i];
                gEnigmaBerries[2].name[i] = berryInfo->name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = 0;
                gEnigmaBerries[2].itemEffect[i] = 0;
            }

            gEnigmaBerries[0].holdEffect = HOLD_EFFECT_NONE;
            gEnigmaBerries[2].holdEffect = HOLD_EFFECT_NONE;
            gEnigmaBerries[0].holdEffectParam = 0;
            gEnigmaBerries[2].holdEffectParam = 0;
        }
    }
    else
    {
        s32 numPlayers;
        struct BattleEnigmaBerry *src;
        enum BattlerId battler;

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = 4;

            for (i = 0; i < numPlayers; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);
                battler = gLinkPlayers[i].id;

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
                    gEnigmaBerries[battler].name[j] = src->name[j];
                gEnigmaBerries[battler].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                    gEnigmaBerries[battler].itemEffect[j] = src->itemEffect[j];

                gEnigmaBerries[battler].holdEffect = src->holdEffect;
                gEnigmaBerries[battler].holdEffectParam = src->holdEffectParam;
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

// This was inlined in Ruby/Sapphire
static void FindLinkBattleMaster(u8 numPlayers, u8 multiPlayerId)
{
    u8 found = 0;

    // If player 1 is playing the minimum version, player 1 is master.
    if (gBlockRecvBuffer[0][0] == 0x100)
    {
        if (multiPlayerId == 0)
            gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
        else
            gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        found++;
    }

    if (found == 0)
    {
        // If multiple different versions are being used, player 1 is master.
        s32 i;

        for (i = 0; i < numPlayers; i++)
        {
            if (gBlockRecvBuffer[0][0] != gBlockRecvBuffer[i][0])
                break;
        }

        if (i == numPlayers)
        {
            if (multiPlayerId == 0)
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
            found++;
        }

        if (found == 0)
        {
            // Lowest index player with the highest game version is master.
            for (i = 0; i < numPlayers; i++)
            {
                if (gBlockRecvBuffer[i][0] == 0x300 && i != multiPlayerId)
                {
                    if (i < multiPlayerId)
                        break;
                }
                if (gBlockRecvBuffer[i][0] > 0x300 && i != multiPlayerId)
                    break;
            }

            if (i == numPlayers)
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
            FillAroundBattleWindows();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();

                    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    {
                        gLinkPlayers[0].id = 0;
                        gLinkPlayers[1].id = 1;
                    }

                    SendBlock(BitmaskAllOtherLinkPlayers(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
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
            FindLinkBattleMaster(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo | (gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi << 8);
            gTasks[taskId].data[4] = gBlockRecvBuffer[enemyMultiplayerId][1];
            RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[playerMultiplayerId][1]);
            RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[enemyMultiplayerId][1]);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        // Link battle, send/receive party Pokémon 2 at a time
        if (IsLinkTaskFinished())
        {
            // Send Pokémon 1-2
            SendBlock(BitmaskAllOtherLinkPlayers(), gParties[B_TRAINER_PLAYER], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv Pokémon 1-2
            ResetBlockReceivedFlags();
            memcpy(gParties[B_TRAINER_OPPONENT_A], gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (IsLinkTaskFinished())
        {
            // Send Pokémon 3-4
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_PLAYER][2], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv Pokémon 3-4
            ResetBlockReceivedFlags();
            memcpy(&gParties[B_TRAINER_OPPONENT_A][2], gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished())
        {
            // Send Pokémon 5-6
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_PLAYER][4], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv Pokémon 5-6
            ResetBlockReceivedFlags();
            memcpy(&gParties[B_TRAINER_OPPONENT_A][4], gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        InitBattleControllers();
        RecordedBattle_SetTrainerInfo();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            // Check if both players are using Emerald
            // to determine if the recorded battle rng
            // seed needs to be sent
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
        // Both players are using Emerald, send rng seed for recorded battle
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 17:
        // Receive rng seed for recorded battle (only read it if partner is the link master)
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[enemyMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 18:
        // Finish, start battle
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
        }
        break;
    // Introduce short delays between sending party Pokémon for link
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
    u8 partnerMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    partnerMultiplayerId = playerMultiplayerId ^ BIT_SIDE;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            FillAroundBattleWindows();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        // fall through
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers)
            {
                u8 language;

                gLinkPlayers[0].id = 0;
                gLinkPlayers[1].id = 2;
                gLinkPlayers[2].id = 1;
                gLinkPlayers[3].id = 3;
                GetFrontierTrainerName(gLinkPlayers[2].name, TRAINER_BATTLE_PARAM.opponentA);
                GetFrontierTrainerName(gLinkPlayers[3].name, TRAINER_BATTLE_PARAM.opponentB);
                GetBattleTowerTrainerLanguage(&language, TRAINER_BATTLE_PARAM.opponentA);
                gLinkPlayers[2].language = language;
                GetBattleTowerTrainerLanguage(&language, TRAINER_BATTLE_PARAM.opponentB);
                gLinkPlayers[3].language = language;

                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();
                    SendBlock(BitmaskAllOtherLinkPlayers(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
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
            gBattleCommunication[MULTIUSE_STATE] = 19;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            FindLinkBattleMaster(2, playerMultiplayerId);
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
        // Link battle, send/receive party Pokémon in groups
        if (IsLinkTaskFinished())
        {
            // Send Pokémon 1-2
            SendBlock(BitmaskAllOtherLinkPlayers(), gParties[B_TRAINER_PLAYER], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv partner's Pokémon 1-2, put each player's mons in their own party
            ResetBlockReceivedFlags();
            memcpy(gParties[B_TRAINER_PLAYER], gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
            memcpy(gParties[B_TRAINER_PARTNER], gBlockRecvBuffer[partnerMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            // Send Pokémon 3
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_PLAYER][2], sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv partner's Pokémon 3, put each player's mon in their own party
            ResetBlockReceivedFlags();
            memcpy(&gParties[B_TRAINER_PLAYER][2], gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
            memcpy(&gParties[B_TRAINER_PARTNER][2], gBlockRecvBuffer[partnerMultiplayerId], sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (IsLinkTaskFinished())
        {
            // Send opponent A Pokémon 1-2 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), gParties[B_TRAINER_OPPONENT_A], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv opponent A Pokémon 1-2 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(gParties[B_TRAINER_OPPONENT_A], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            // Send opponent A Pokémon 3-4 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_OPPONENT_A][2], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv opponent A Pokémon 3-4 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(&gParties[B_TRAINER_OPPONENT_A][2], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished())
        {
            // Send opponent A Pokémon 5-6 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_OPPONENT_A][4], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv opponent A Pokémon 5-6 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(&gParties[B_TRAINER_OPPONENT_A][4], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 13:
        if (IsLinkTaskFinished())
        {
            // Send opponent B Pokémon 1-2 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), gParties[B_TRAINER_OPPONENT_B], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 14:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv opponent B Pokémon 1-2 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(gParties[B_TRAINER_OPPONENT_B], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        if (IsLinkTaskFinished())
        {
            // Send opponent B Pokémon 3-4 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_OPPONENT_B][2], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 16:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv opponent B Pokémon 3-4 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(&gParties[B_TRAINER_OPPONENT_B][2], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 17:
        if (IsLinkTaskFinished())
        {
            // Send opponent B Pokémon 5-6 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), &gParties[B_TRAINER_OPPONENT_B][4], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 18:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv opponent B Pokémon 5-6 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(&gParties[B_TRAINER_OPPONENT_B][4], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);

            for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
            {
                for (u32 i = 0; i < PARTY_SIZE; i++)
                    TryCorrectShedinjaLanguage(&gParties[trainer][i]);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 19:
    {
        InitBattleControllers();
        RecordedBattle_SetTrainerInfo();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            gBattleCommunication[MULTIUSE_STATE] = 20;
        else
            gBattleCommunication[MULTIUSE_STATE] = 22;
        break;
    }
    case 20:
        // Send rng seed for recorded battle
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 21:
        // Receive rng seed for recorded battle (only read it if partner is the link master)
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[partnerMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 22:
        // Finish, start battle
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            TrySetLinkBattleTowerEnemyPartyLevel();
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
        }
        break;
    }
}

static void SetMultiPartnerMenuParty(enum BattleTrainer trainer)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gMultiPartnerParty[i].species     = GetMonData(&gParties[trainer][i], MON_DATA_SPECIES);
        gMultiPartnerParty[i].heldItem    = GetMonData(&gParties[trainer][i], MON_DATA_HELD_ITEM);
        GetMonData(&gParties[trainer][i], MON_DATA_NICKNAME, gMultiPartnerParty[i].nickname);
        gMultiPartnerParty[i].level       = GetMonData(&gParties[trainer][i], MON_DATA_LEVEL);
        gMultiPartnerParty[i].hp          = GetMonData(&gParties[trainer][i], MON_DATA_HP);
        gMultiPartnerParty[i].maxhp       = GetMonData(&gParties[trainer][i], MON_DATA_MAX_HP);
        gMultiPartnerParty[i].status      = GetMonData(&gParties[trainer][i], MON_DATA_STATUS);
        gMultiPartnerParty[i].personality = GetMonData(&gParties[trainer][i], MON_DATA_PERSONALITY);
        gMultiPartnerParty[i].gender      = GetMonGender(&gParties[trainer][i]);
        StripExtCtrlCodes(gMultiPartnerParty[i].nickname);
        if (GetMonData(&gParties[trainer][i], MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
            PadNameString(gMultiPartnerParty[i].nickname, CHAR_SPACE);
    }
}

static void CB2_PreInitMultiBattle(void)
{
    s32 i;
    u8 playerMultiplierId;
    s32 numPlayers = MAX_BATTLERS_COUNT;
    u8 blockMask = 0xF;
    u32 *savedBattleTypeFlags;
    void (**savedCallback)(void);

    if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        numPlayers = 2;
        blockMask = 3;
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
        if (gReceivedRemoteLinkPlayers && IsLinkTaskFinished())
        {
            gMultiPartnerParty = Alloc(sizeof(struct MultiPartnerMenuPokemon) * PARTY_SIZE); // only 3 mons actually used for link multis
            SetMultiPartnerMenuParty(B_TRAINER_PLAYER);
            SendBlock(BitmaskAllOtherLinkPlayers(), gMultiPartnerParty, sizeof(struct MultiPartnerMenuPokemon) * PARTY_SIZE);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 1:
        if ((GetBlockReceivedStatus() & blockMask) == blockMask)
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
                        memcpy(gMultiPartnerParty, gBlockRecvBuffer[i], sizeof(struct MultiPartnerMenuPokemon) * PARTY_SIZE);
                    }
                }
                else
                {
                    memcpy(gMultiPartnerParty, gBlockRecvBuffer[i], sizeof(struct MultiPartnerMenuPokemon) * PARTY_SIZE);
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
                SetLinkStandbyCallback();
            else
                SetCloseLinkCallback();
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
                FREE_AND_SET_NULL(gMultiPartnerParty);
            }
        }
        else if (!gReceivedRemoteLinkPlayers)
        {
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            FREE_AND_SET_NULL(gMultiPartnerParty);
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
        gMultiPartnerParty = Alloc(sizeof(struct MultiPartnerMenuPokemon) * PARTY_SIZE); // Up to 6 Pokemon for Ingame Partner multis
        SetMultiPartnerMenuParty(B_TRAINER_PARTNER);
        gBattleCommunication[MULTIUSE_STATE]++;
        *savedCallback = gMain.savedCallback;
        *savedBattleTypeFlags = gBattleTypeFlags;
        gMain.savedCallback = CB2_PreInitIngamePlayerPartnerBattle;
        if ((!PlayerHasFollowerNPC() || !FollowerNPCIsBattlePartner() || (FNPC_NPC_FOLLOWER_PARTY_PREVIEW && FollowerNPCIsBattlePartner())))
        {
            ShowPartyMenuToShowcaseMultiBattleParty();
        }

        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE] = 2;
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            FREE_AND_SET_NULL(gMultiPartnerParty);
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
            FillAroundBattleWindows();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();

                    SendBlock(BitmaskAllOtherLinkPlayers(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
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
            FindLinkBattleMaster(4, playerMultiplayerId);
            SetAllPlayersBerryData();
            var = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[var].data[1] = 0x10E;
            gTasks[var].data[2] = 0x5A;
            gTasks[var].data[5] = 0;
            gTasks[var].data[3] = 0;
            gTasks[var].data[4] = 0;

            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[id][1]);
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
        {
            break;
        }
        // fall through
    case 3:
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), gParties[B_TRAINER_PLAYER], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                enum BattleTrainer trainer;
                bool32 sameSide = (!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                 || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1));

                if (id == playerMultiplayerId)
                    trainer = B_TRAINER_PLAYER;
                else if (sameSide)
                    trainer = B_TRAINER_PARTNER;
                else if (gLinkPlayers[id].id <= 1)
                    trainer = B_TRAINER_OPPONENT_A;
                else
                    trainer = B_TRAINER_OPPONENT_B;
                memcpy(gParties[trainer], gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), gParties[B_TRAINER_PLAYER] + 2, sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                enum BattleTrainer trainer;
                bool32 sameSide = (!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                 || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1));

                if (id == playerMultiplayerId)
                    trainer = B_TRAINER_PLAYER;
                else if (sameSide)
                    trainer = B_TRAINER_PARTNER;
                else if (gLinkPlayers[id].id <= 1)
                    trainer = B_TRAINER_OPPONENT_A;
                else
                    trainer = B_TRAINER_OPPONENT_B;
                memcpy(&gParties[trainer][2], gBlockRecvBuffer[id], sizeof(struct Pokemon));
            }

            for (enum BattleTrainer trainerParty = B_TRAINER_PLAYER; trainerParty < MAX_BATTLE_TRAINERS; trainerParty++)
            {
                for (u32 i = 0; i < MULTI_PARTY_SIZE; i++)
                {
                    TryCorrectShedinjaLanguage(&gParties[trainerParty][i]);
                }
            }

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        InitBattleControllers();
        RecordedBattle_SetTrainerInfo();
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
            struct BattleVideo *ptr = &gBattleStruct->multiBuffer.battleVideo;
            ptr->battleTypeFlags = gBattleTypeFlags;
            ptr->rngSeed = gRecordedBattleRngSeed;

            SendBlock(BitmaskAllOtherLinkPlayers(), ptr, sizeof(gBattleStruct->multiBuffer.battleVideo));
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
                TRAINER_BATTLE_PARAM.opponentA = TRAINER_LINK_OPPONENT;
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
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

    if (JOY_HELD(B_BUTTON) && gBattleTypeFlags & BATTLE_TYPE_RECORDED && RecordedBattle_CanStopPlayback())
    {
        // Player pressed B during recorded battle playback, end battle
        gSpecialVar_Result = gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED;
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_QuitRecordedBattle);
    }
}

static void FreeRestoreBattleData(void)
{
    gMain.callback1 = gPreBattleCallback1;
    gScanlineEffect.state = 3;
    gMain.inBattle = FALSE;
    ZeroEnemyPartyMons();
    m4aSongNumStop(SE_LOW_HEALTH);
    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
    ResetDynamicAiFunctions();
}

void CB2_QuitRecordedBattle(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
        if (gTestRunnerEnabled)
        {
            // Clean up potentially-leaking tasks.
            // I think these leak when the battle ends soon after a
            // battler is fainted.
            u8 taskId;
            taskId = FindTaskIdByFunc(Task_PlayerController_RestoreBgmAfterCry);
            if (taskId != TASK_NONE)
                DestroyTask(taskId);
            taskId = FindTaskIdByFunc(Task_DuckBGMForPokemonCry);
            if (taskId != TASK_NONE)
                DestroyTask(taskId);

            gCurrentActionFuncId = B_ACTION_FINISHED;
            sEndTurnFuncsTable[gBattleOutcome & 0x7F](); // Contains TestRunner_Battle_AfterLastTurn
        }
        FreeRestoreBattleData();
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

void ModifyPersonalityForNature(u32 *personality, u32 newNature)
{
    u32 nature = GetNatureFromPersonality(*personality);
    s32 diff = abs((s32)nature - (s32)newNature);
    s32 sign = (nature > newNature) ? 1 : -1;
    if (diff > NUM_NATURES / 2)
    {
        diff = NUM_NATURES - diff;
        sign *= -1;
    }
    *personality -= (diff * sign);
}

void VBlankCB_Battle(void)
{
    // Change gRngSeed every vblank unless the battle could be recorded.
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_RECORDED)))
        AdvanceRandom();

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

void SpriteCB_VsLetterDummy(struct Sprite *sprite)
{

}

static void SpriteCB_VsLetter(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->x = sprite->data[1] + ((sprite->data[2] & 0xFF00) >> 8);
    else
        sprite->x = sprite->data[1] - ((sprite->data[2] & 0xFF00) >> 8);

    sprite->data[2] += 0x180;

    if (sprite->affineAnimEnded)
    {
        FreeSpriteTilesByTag(ANIM_SPRITES_START);
        FreeSpritePaletteByTag(ANIM_SPRITES_START);
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void SpriteCB_VsLetterInit(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->callback = SpriteCB_VsLetter;
    PlaySE(SE_MUGSHOT);
}

static void BufferPartyVsScreenHealth_AtEnd(u8 taskId)
{
    struct Pokemon *party1 = NULL;
    struct Pokemon *party2 = NULL;
    u8 multiplayerId = gBattleScripting.multiplayerId;
    u32 flags;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        switch (gLinkPlayers[multiplayerId].id)
        {
        case 0:
        case 2:
            party1 = gParties[B_TRAINER_PLAYER];
            party2 = gParties[B_TRAINER_OPPONENT_A];
            break;
        case 1:
        case 3:
            party1 = gParties[B_TRAINER_OPPONENT_A];
            party2 = gParties[B_TRAINER_PLAYER];
            break;
        }
    }
    else
    {
        party1 = gParties[B_TRAINER_PLAYER];
        party2 = gParties[B_TRAINER_OPPONENT_A];
    }

    flags = 0;
    BUFFER_PARTY_VS_SCREEN_STATUS(party1, flags, i);
    gTasks[taskId].data[3] = flags;

    flags = 0;
    BUFFER_PARTY_VS_SCREEN_STATUS(party2, flags, i);
    gTasks[taskId].data[4] = flags;
}

void CB2_InitEndLinkBattle(void)
{
    s32 i;
    u8 taskId;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    gBattleTypeFlags &= ~BATTLE_TYPE_LINK_IN_BATTLE;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        SetMainCallback2(gMain.savedCallback);
        FreeBattleResources();
        FreeBattleSpritesData();
        FreeMonSpritesGfx();
    }
    else
    {
        CpuFill32(0, (void *)(VRAM), VRAM_SIZE);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gBattle_WIN0H = DISPLAY_WIDTH;
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
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
        LoadPalette(gBattleTextboxPalette, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        LoadBattleMenuWindowGfx();
        ResetSpriteData();
        ResetTasks();
        DrawBattleEntryBackground();
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
        SetVBlankCallback(VBlankCB_Battle);

        // Show end Vs screen with battle results
        taskId = CreateTask(InitLinkBattleVsScreen, 0);
        gTasks[taskId].data[1] = 0x10E;
        gTasks[taskId].data[2] = 0x5A;
        gTasks[taskId].data[5] = 1;
        BufferPartyVsScreenHealth_AtEnd(taskId);

        SetMainCallback2(CB2_EndLinkBattle);
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
}

static void CB2_EndLinkBattle(void)
{
    EndLinkBattleInSteps();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void EndLinkBattleInSteps(void)
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
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            u32 battlerCount;

            gMain.anyLinkBattlerHasFrontierPass = RecordedBattle_GetFrontierPassFlag();

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                battlerCount = 4;
            else
                battlerCount = 2;

            for (i = 0; i < battlerCount && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

            if (!gSaveBlock2Ptr->frontier.disableRecordBattle && i == battlerCount)
            {
                if (FlagGet(FLAG_SYS_FRONTIER_PASS))
                {
                    // Ask player if they want to record the battle
                    FreeAllWindowBuffers();
                    SetMainCallback2(CB2_InitAskRecordBattle);
                }
                else if (!gMain.anyLinkBattlerHasFrontierPass)
                {
                    // No players can record this battle, end
                    SetMainCallback2(gMain.savedCallback);
                    FreeBattleResources();
                    FreeBattleSpritesData();
                    FreeMonSpritesGfx();
                }
                else if (!gReceivedRemoteLinkPlayers)
                {
                    // Player can't record battle but
                    // another player can, reconnect with them
                    CreateTask(Task_ReconnectWithLinkPlayers, 5);
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
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);

        for (i = 0; i < 2; i++)
            LoadChosenBattleElement(i);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 4:
        if (!gPaletteFade.active)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 5:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 6:
        if (IsLinkTaskFinished() == TRUE)
        {
            SetLinkStandbyCallback();
            BattlePutTextOnWindow(gText_LinkStandby3, B_WIN_MSG);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (!IsTextPrinterActiveOnWindow(B_WIN_MSG))
        {
            if (IsLinkTaskFinished() == TRUE)
                gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (!gWirelessCommType)
            SetCloseLinkCallback();
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 9:
        if (!gMain.anyLinkBattlerHasFrontierPass || gWirelessCommType || !gReceivedRemoteLinkPlayers)
        {
            gMain.anyLinkBattlerHasFrontierPass = FALSE;
            SetMainCallback2(gMain.savedCallback);
            FreeBattleResources();
            FreeBattleSpritesData();
            FreeMonSpritesGfx();
        }
        break;
    }
}

u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId)
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
    case 5: // Only this case is used
        ret = gBattleBgTemplates[arrayId].priority;
        break;
    case 6:
        ret = gBattleBgTemplates[arrayId].baseTile;
        break;
    }

    return ret;
}

static void CB2_InitAskRecordBattle(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);
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
    gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
    SetVBlankCallback(VBlankCB_Battle);
    SetMainCallback2(CB2_AskRecordBattle);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    gBattleCommunication[MULTIUSE_STATE] = 0;
}

static void CB2_AskRecordBattle(void)
{
    AskRecordBattle();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}


// States for AskRecordBattle
#define STATE_INIT             0
#define STATE_LINK             1
#define STATE_WAIT_LINK        2
#define STATE_ASK_RECORD       3
#define STATE_PRINT_YES_NO     4
#define STATE_HANDLE_YES_NO    5
#define STATE_RECORD_NO        6
#define STATE_END_RECORD_NO    7
#define STATE_WAIT_END         8
#define STATE_END              9
#define STATE_RECORD_YES      10
#define STATE_RECORD_WAIT     11
#define STATE_END_RECORD_YES  12

static void AskRecordBattle(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case STATE_INIT:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case STATE_LINK:
        if (gMain.anyLinkBattlerHasFrontierPass && !gReceivedRemoteLinkPlayers)
            CreateTask(Task_ReconnectWithLinkPlayers, 5);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case STATE_WAIT_LINK:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case STATE_ASK_RECORD:
        if (!gPaletteFade.active)
        {
            // "Would you like to record your battle on your FRONTIER PASS?"
            BattlePutTextOnWindow(gText_RecordBattleToPass, B_WIN_MSG);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_PRINT_YES_NO:
        if (!IsTextPrinterActiveOnWindow(B_WIN_MSG))
        {
            HandleBattleWindow(YESNOBOX_X_Y, 0);
            BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_HANDLE_YES_NO:
        if (JOY_NEW(DPAD_UP))
        {
            if (gBattleCommunication[CURSOR_POSITION] != 0)
            {
                // Moved cursor onto Yes
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 0;
                BattleCreateYesNoCursorAt(0);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                // Moved cursor onto No
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 1;
                BattleCreateYesNoCursorAt(1);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                // Selected Yes
                HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
                gBattleCommunication[1] = MoveRecordedBattleToSaveData();
                gBattleCommunication[MULTIUSE_STATE] = STATE_RECORD_YES;
            }
            else
            {
                // Selected No
                gBattleCommunication[MULTIUSE_STATE]++;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_RECORD_NO:
        if (IsLinkTaskFinished() == TRUE)
        {
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                // Other battlers may be recording, wait for them
                SetLinkStandbyCallback();
                BattlePutTextOnWindow(gText_LinkStandby3, B_WIN_MSG);
            }
            gBattleCommunication[MULTIUSE_STATE]++; // STATE_END_RECORD_NO
        }
        break;
    case STATE_WAIT_END:
        if (--gBattleCommunication[1] == 0)
        {
            if (gMain.anyLinkBattlerHasFrontierPass && !gWirelessCommType)
                SetCloseLinkCallback();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_END:
        if (!gMain.anyLinkBattlerHasFrontierPass || gWirelessCommType || !gReceivedRemoteLinkPlayers)
        {
            gMain.anyLinkBattlerHasFrontierPass = FALSE;
            if (!gPaletteFade.active)
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case STATE_RECORD_YES:
        if (gBattleCommunication[1] == 1)
        {
            PlaySE(SE_SAVE);
            BattleStringExpandPlaceholdersToDisplayedString(gText_BattleRecordedOnPass);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
            gBattleCommunication[1] = 128; // Delay
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
        {
            BattleStringExpandPlaceholdersToDisplayedString(BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
            gBattleCommunication[1] = 128; // Delay
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_RECORD_WAIT:
        if (IsLinkTaskFinished() == TRUE && !IsTextPrinterActiveOnWindow(B_WIN_MSG) && --gBattleCommunication[1] == 0)
        {
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                SetLinkStandbyCallback();
                BattlePutTextOnWindow(gText_LinkStandby3, B_WIN_MSG);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_END_RECORD_YES:
    case STATE_END_RECORD_NO:
        if (!IsTextPrinterActiveOnWindow(B_WIN_MSG))
        {
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                if (IsLinkTaskFinished() == TRUE)
                {
                    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                    gBattleCommunication[1] = 32; // Delay
                    gBattleCommunication[MULTIUSE_STATE] = STATE_WAIT_END;
                }

            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gBattleCommunication[1] = 32; // Delay
                gBattleCommunication[MULTIUSE_STATE] = STATE_WAIT_END;
            }
        }
        break;
    }
}

static void TryCorrectShedinjaLanguage(struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    enum Language language = LANGUAGE_JAPANESE;

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_SHEDINJA
     && GetMonData(mon, MON_DATA_LANGUAGE) != language)
    {
        GetMonData(mon, MON_DATA_NICKNAME, nickname);
        if (StringCompareWithoutExtCtrlCodes(nickname, sText_ShedinjaJpnName) == 0)
            SetMonData(mon, MON_DATA_LANGUAGE, &language);
    }
}

u32 GetBattleWindowTemplatePixelWidth(u32 windowsType, u32 tableId)
{
    return gBattleWindowTemplates[windowsType][tableId].width * 8;
}

#define sBattler            data[0]
#define sSpeciesId          data[2]

void SpriteCB_WildMon(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_MoveWildMonToRight;
    StartSpriteAnimIfDifferent(sprite, 0);
    if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless)
    {
        if (WILD_DOUBLE_BATTLE)
            BeginNormalPaletteFade((0x10000 << sprite->sBattler) | (0x10000 << GetPartnerBattler(sprite->sBattler)), 0, 10, 10, RGB(8, 8, 8));
        else
            BeginNormalPaletteFade((0x10000 << sprite->sBattler), 0, 10, 10, RGB(8, 8, 8));
    }
}

static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite)
{
    if ((gIntroSlideFlags & 1) == 0)
    {
        if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless)
            sprite->x2 += 2;
        else
            sprite->x2 = 0;

        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCB_WildMonShowHealthbox;
        }
    }
}

static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        StartHealthboxSlideIn(sprite->sBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[sprite->sBattler]);
        sprite->callback = SpriteCB_WildMonAnimate;
        StartSpriteAnimIfDifferent(sprite, 0);
        if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless)
        {
            if (WILD_DOUBLE_BATTLE)
                BeginNormalPaletteFade((0x10000 << sprite->sBattler) | (0x10000 << GetPartnerBattler(sprite->sBattler)), 0, 10, 0, RGB(8, 8, 8));
            else
                BeginNormalPaletteFade((0x10000 << sprite->sBattler), 0, 10, 0, RGB(8, 8, 8));
        }
    }
}

static void SpriteCB_WildMonAnimate(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
    {
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, FALSE, 1);
    }
}

void SpriteCallbackDummy_2(struct Sprite *sprite)
{

}

void SpriteCB_FaintOpponentMon(struct Sprite *sprite)
{
    enum BattlerId battler = sprite->sBattler;
    u32 personality = GetMonData(GetBattlerMon(battler), MON_DATA_PERSONALITY);
    enum Species species;
    u8 yOffset;

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != 0)
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;
    else
        species = sprite->sSpeciesId;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_UNOWN)
        species = GetUnownSpeciesId(personality);
    yOffset = gSpeciesInfo[species].frontPicYOffset;

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
        sprite->y2 += 8; // Move the sprite down.
        if (--sprite->data[3] < 0)
        {
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
        else // Erase bottom part of the sprite to create a smooth illusion of mon falling down.
        {
            u8 *dst = &gMonSpritesGfxPtr->spritesGfx[GetBattlerPosition(sprite->sBattler)][(sprite->data[3] << 8)];

            for (i = 0; i < 0x100; i++)
                *(dst++) = 0;

            StartSpriteAnim(sprite, 0);
        }
    }
}

// Used when selecting a move, which can hit multiple targets, in double battles.
void SpriteCB_ShowAsMoveTarget(struct Sprite *sprite)
{
    sprite->data[3] = 8;
    sprite->data[4] = sprite->invisible;
    sprite->callback = SpriteCB_BlinkVisible;
}

static void SpriteCB_BlinkVisible(struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
    {
        sprite->invisible ^= 1;
        sprite->data[3] = 8;
    }
}

void SpriteCB_HideAsMoveTarget(struct Sprite *sprite)
{
    sprite->invisible = sprite->data[4];
    sprite->data[4] = FALSE;
    sprite->callback = SpriteCallbackDummy_2;
}

bool32 ShouldHideBattler(enum BattlerId battler)
{
    if (!IsBattlerAlive(battler)
     || !gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
        return FALSE;

    SpriteCallback callback = gSprites[gBattlerSpriteIds[battler]].callback;
    return callback == SpriteCB_ShowAsMoveTarget || callback == SpriteCB_BlinkVisible;
}

void SpriteCB_OpponentMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        if (!(gHitMarker & HITMARKER_NO_ANIMATIONS) || gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        {
            if (HasTwoFramesAnimation(sprite->sSpeciesId))
                StartSpriteAnim(sprite, 1);
        }
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, TRUE, 1);
    }
}

// This callback is frequently overwritten by SpriteCB_TrainerSlideIn
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_BattleSpriteSlideLeft;
}

static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 -= 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCB_Idle;
            sprite->data[1] = 0;
        }
    }
}

static void UNUSED SetIdleSpriteCallback(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_Idle;
}

static void SpriteCB_Idle(struct Sprite *sprite)
{
}

#define sSpeedX data[1]
#define sSpeedY data[2]

void SpriteCB_FaintSlideAnim(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 += sprite->sSpeedX;
        sprite->y2 += sprite->sSpeedY;
    }
}

#undef sSpeedX
#undef sSpeedY

#define sSinIndex           data[3]
#define sDelta              data[4]
#define sAmplitude          data[5]
#define sBouncerSpriteId    data[6]
#define sWhich              data[7]

void DoBounceEffect(enum BattlerId battler, u8 which, s8 delta, s8 amplitude)
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
    gSprites[invisibleSpriteId].sBattler = battler;
    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

void EndBounceEffect(enum BattlerId battler, u8 which)
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

    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

static void SpriteCB_BounceEffect(struct Sprite *sprite)
{
    u8 bouncerSpriteId = sprite->sBouncerSpriteId;
    s32 index = sprite->sSinIndex;
    s32 y = Sin(index, sprite->sAmplitude) + sprite->sAmplitude;

    gSprites[bouncerSpriteId].y2 = y;
    sprite->sSinIndex = (sprite->sSinIndex + sprite->sDelta) & 0xFF;
}

#undef sSinIndex
#undef sDelta
#undef sAmplitude
#undef sBouncerSpriteId
#undef sWhich

void SpriteCB_PlayerMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        BattleAnimateBackSprite(sprite, sprite->sSpeciesId);
}

void SpriteCB_PlayerMonSlideIn(struct Sprite *sprite)
{
    if (sprite->data[3] == 0)
    {
        PlaySE(SE_BALL_TRAY_ENTER);
        sprite->data[3]++;
    }
    else if (sprite->data[3] == 1)
    {
        if (sprite->animEnded)
            return;
        sprite->data[4] = sprite->x;
        sprite->x = -33;
        sprite->invisible = FALSE;
        sprite->data[3]++;
    }
    else if (sprite->data[3] < 27)
    {
        sprite->x += 4;
        sprite->data[3]++;
    }
    else
    {
        sprite->data[3] = 0;
        sprite->x = sprite->data[4];
        sprite->data[4] = 0;
        sprite->callback = SpriteCB_PlayerMonFromBall;
        PlayCry_ByMode(sprite->sSpeciesId, -25, CRY_MODE_NORMAL);
    }
}

static void SpriteCB_TrainerThrowObject_Main(struct Sprite *sprite)
{
    AnimSetCenterToCornerVecX(sprite);
    if (sprite->animEnded)
        sprite->callback = SpriteCB_Idle;
}

// Sprite callback for a trainer back pic to throw an object
// (Wally throwing a ball, throwing Pokéblocks/balls in the Safari Zone)
void SpriteCB_TrainerThrowObject(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = SpriteCB_TrainerThrowObject_Main;
}

void AnimSetCenterToCornerVecX(struct Sprite *sprite)
{
    if (sprite->animDelayCounter == 0)
        sprite->centerToCornerVecX = sCenterToCornerVecXs[sprite->animCmdIndex];
}

void BeginBattleIntroDummy(void)
{

}

void BeginBattleIntro(void)
{
    BattleStartClearSetData();
    gBattleCommunication[1] = 0;
    gBattleStruct->eventState.battleIntro = 0;
    gBattleMainFunc = DoBattleIntro;
}

static void BattleMainCB1(void)
{
    gBattleMainFunc();
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        gBattlerControllerFuncs[battler](battler);
}

static void ClearSetBScriptingStruct(void)
{
    // windowsType is set up earlier in BattleInitBgsAndWindows, so we need to save the value
    u32 temp = gBattleScripting.windowsType;
    u32 specialBattleType = gBattleScripting.specialTrainerBattleType;
    memset(&gBattleScripting, 0, sizeof(gBattleScripting));

    gBattleScripting.windowsType = temp;
    gBattleScripting.battleStyle = gSaveBlock2Ptr->optionsBattleStyle;
    #if TESTING
    gBattleScripting.battleStyle = OPTIONS_BATTLE_STYLE_SET;
    #endif
    gBattleScripting.expOnCatch = (GetConfig(B_EXP_CATCH) >= GEN_6);
    gBattleScripting.specialTrainerBattleType = specialBattleType;
}

static void BattleStartClearSetData(void)
{
    s32 i;

    TurnValuesCleanUp(FALSE);
    memset(&gSpecialStatuses, 0, sizeof(gSpecialStatuses));

    memset(&gFieldTimers, 0, sizeof(gFieldTimers));
    memset(&gSideStatuses, 0, sizeof(gSideStatuses));
    memset(&gSideTimers, 0, sizeof(gSideTimers));
    memset(&gBattleResults, 0, sizeof(gBattleResults));
    ClearSetBScriptingStruct();

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattleStruct->battlerState[i].isFirstTurn = 2;
        gBattleStruct->battlerState[i].originalBattlerPartyId = PARTY_SIZE;
        gLastMoves[i] = MOVE_NONE;
        gLastLandedMoves[i] = MOVE_NONE;
        gLastHitByType[i] = 0;
        gLastUsedMoveType[i] = 0;
        gLastResultingMoves[i] = MOVE_NONE;
        gLastHitBy[i] = 0xFF;
        gLockedMoves[i] = MOVE_NONE;
        gLastPrintedMoves[i] = MOVE_NONE;
        gSelectionBattleScripts[i] = NULL;
        gPalaceSelectionBattleScripts[i] = NULL;
        gBattleStruct->lastTakenMove[i] = MOVE_NONE;
        gBattleStruct->choicedMove[i] = MOVE_NONE;
        gBattleStruct->lastTakenMoveFrom[i][0] = MOVE_NONE;
        gBattleStruct->lastTakenMoveFrom[i][1] = MOVE_NONE;
        gBattleStruct->lastTakenMoveFrom[i][2] = MOVE_NONE;
        gBattleStruct->lastTakenMoveFrom[i][3] = MOVE_NONE;
        gBattleStruct->AI_monToSwitchIntoId[i] = PARTY_SIZE;
    }

    gLastUsedMove = 0;
    gFieldStatuses = 0;

    gHasFetchedBall = FALSE;
    gLastUsedBall = 0;

    gBattlerAttacker = 0;
    gBattlerTarget = 0;
    gEffectBattler = 0;
    gBattlerAbility = 0;
    gBattleWeather = 0;
    gHitMarker = 0;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && gSaveBlock2Ptr->optionsBattleSceneOff == TRUE)
            gHitMarker |= HITMARKER_NO_ANIMATIONS;
    }
    else if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)) && GetBattleSceneInRecordedBattle())
    {
        gHitMarker |= HITMARKER_NO_ANIMATIONS;
    }

    gMultiHitCounter = 0;
    gBattleOutcome = 0;
    gBattleControllerExecFlags = 0;
    gPaydayMoney = 0;
    gBattleResources->battleScriptsStack->size = 0;
    gBattleResources->battleCallbackStack->size = 0;

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    gPauseCounterBattle = 0;
    gIntroSlideFlags = 0;
    gLeveledUpInBattle = 0;
    gAbsentBattlerFlags = 0;
    gBattleStruct->runTries = 0;
    gBattleStruct->safariGoNearCounter = 0;
    gBattleStruct->safariPkblThrowCounter = 0;
    gBattleStruct->safariCatchFactor = gSpeciesInfo[GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES)].catchRate * 100 / 1275;
    gBattleStruct->safariEscapeFactor = 3;
    gBattleStruct->wildVictorySong = 0;
    gBattleStruct->moneyMultiplier = 1;

    gBattleStruct->givenExpMons[0] = 0;
    gBattleStruct->givenExpMons[1] = 0;
    gBattleStruct->palaceFlags = 0;

    gBattleResults.shinyWildMon = IsMonShiny(&gParties[B_TRAINER_OPPONENT_A][0]);

    gBattleStruct->arenaLostPlayerMons = 0;
    gBattleStruct->arenaLostOpponentMons = 0;

    for (i = 0; i < ARRAY_COUNT(gSideTimers); i++)
    {
        gSideTimers[i].stickyWebBattlerId = 0xFF;
    }
    gBattleStruct->beatUpSlot = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
        {
            gBattleStruct->partyState[trainer][i].usedHeldItem = ITEM_NONE;
            gBattleStruct->itemLost[trainer][i].originalItem = GetMonData(&gParties[trainer][i], MON_DATA_HELD_ITEM);
            gPartyCriticalHits[i] = 0;
        }
    }

    ClearPursuitValues();
    gSelectedMonPartyId = PARTY_SIZE; // Revival Blessing
    gCategoryIconSpriteId = 0xFF;

    if (IsSleepClauseEnabled())
    {
        // If monCausingSleepClause[side].partyIndex equals PARTY_SIZE, Sleep Clause is not active for the given side.
        gBattleStruct->monCausingSleepClause[B_SIDE_PLAYER].partyIndex = PARTY_SIZE;
        gBattleStruct->monCausingSleepClause[B_SIDE_PLAYER].trainer = MAX_BATTLE_TRAINERS;
        gBattleStruct->monCausingSleepClause[B_SIDE_OPPONENT].partyIndex = PARTY_SIZE;
        gBattleStruct->monCausingSleepClause[B_SIDE_OPPONENT].trainer = MAX_BATTLE_TRAINERS;
    }
}

#define UNPACK_VOLATILE_BATON_PASSABLES(_enum, _fieldName, _typeMaxValue, ...) __VA_OPT__(if ((FIRST(__VA_ARGS__)) & V_BATON_PASSABLE) gBattleMons[battler].volatiles._fieldName = volatilesCopy->_fieldName;)

static void ClearSetDataOnLeave(enum BattlerId battler)
{
    // Clear Rage Fist stacks
    if (GetConfig(B_RAGE_FIST) >= GEN_CHAMPIONS)
        GetBattlerPartyState(battler)->timesGotHit = 0;

    if (GetProtectType(gProtectStructs[battler].protected) == PROTECT_TYPE_SINGLE) // Side type protects expire at the end of the turn
        gProtectStructs[battler].protected = PROTECT_NONE;

    if (battler == gBattlerAttacker)
        gBattleStruct->moldBreakerActive = FALSE;

    gActionSelectionCursor[battler] = 0;
    gMoveSelectionCursor[battler] = 0;

    gProtectStructs[battler].quash = FALSE;
    gProtectStructs[battler].noValidMoves = FALSE;
    gProtectStructs[battler].helpingHand = 0;
    gProtectStructs[battler].bounceMove = FALSE;
    gProtectStructs[battler].stealMove = FALSE;
    gProtectStructs[battler].chargingTurn = FALSE;
    gProtectStructs[battler].fleeType = 0;
    gProtectStructs[battler].statRaised = FALSE;
    gProtectStructs[battler].pranksterElevated = FALSE;
    gSpecialStatuses[battler].queuedSwitch = NO_QUEUED_SWITCH;
    gSpecialStatuses[battler].shellBellEmergencyExit = FALSE;
    gBattleStruct->battlerState[battler].isFirstTurn = 2;
    gBattleStruct->battlerState[battler].stompingTantrumTimer = 0;
    gBattleStruct->battlerState[battler].canPickupItem = FALSE;
    gBattleStruct->battlerState[battler].wasAboveHalfHp = gBattleMons[battler].hp > gBattleMons[battler].maxHP / 2;
    gBattleStruct->choicedMove[battler] = MOVE_NONE;
    gBattleStruct->palaceFlags &= ~(1u << battler);

    gLastMoves[battler] = MOVE_NONE;
    gLastLandedMoves[battler] = MOVE_NONE;
    gLastHitByType[battler] = 0;
    gLastUsedMoveType[battler] = 0;
    gLastResultingMoves[battler] = MOVE_NONE;
    gLastPrintedMoves[battler] = MOVE_NONE;
    gLastHitBy[battler] = 0xFF;

    for (u32 i = 0; i < NUM_BATTLE_SIDES; i++)
    {
        // User of sticky web fainted, so reset the stored battler ID
        if (gSideTimers[i].stickyWebBattlerId == battler)
            gSideTimers[i].stickyWebBattlerId = 0xFF;
    }

    gBattleStruct->lastTakenMove[battler] = 0;
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (i != battler && !IsBattlerAlly(i, battler))
            gBattleStruct->lastTakenMove[i] = MOVE_NONE;

        gBattleStruct->lastTakenMoveFrom[i][battler] = 0;
        gBattleStruct->lastTakenMoveFrom[battler][i] = 0;

        if (gBattleMons[i].volatiles.infatuation == INFATUATED_WITH(battler))
            gBattleMons[i].volatiles.infatuation = 0;
        if (gBattleMons[i].volatiles.wrapped && gBattleMons[i].volatiles.wrappedBy == battler)
            gBattleMons[i].volatiles.wrapped = FALSE;
        if (gBattleMons[i].volatiles.syrupBomb && gBattleMons[i].volatiles.stickySyrupedBy == battler)
            gBattleMons[i].volatiles.syrupBomb = FALSE;
        if (gBattleMons[i].volatiles.octolock && gBattleMons[i].volatiles.octolockedBy == battler)
            gBattleMons[i].volatiles.octolock = FALSE;
        if (gBattleMons[i].volatiles.skyDropTarget == battler + 1)
            gBattleMons[i].volatiles.skyDropTarget = 0;
    }

    ClearPursuitValuesIfSet(battler);

    // Reset Eject Button / Eject Pack switch detection
    gAiLogicData->ejectButtonSwitch = FALSE;
    gAiLogicData->ejectPackSwitch = FALSE;
}

void SwitchInClearSetData(enum BattlerId battler, struct Volatiles *volatilesCopy)
{
    enum BattleMoveEffects effect = GetMoveEffect(gCurrentMove);

    // Data cleared both on switch and faint
    ClearSetDataOnLeave(battler);

    ClearIllusionMon(battler);
    if (effect != EFFECT_BATON_PASS)
    {
        for (enum Stat i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;
        for (enum BattlerId i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].volatiles.escapePrevention && gBattleMons[i].volatiles.battlerPreventingEscape == battler)
                gBattleMons[i].volatiles.escapePrevention = FALSE;

            if (gBattleMons[i].volatiles.battlerWithSureHit == battler + 1)
                gBattleMons[i].volatiles.battlerWithSureHit = 0;
        }
    }
    if (effect != EFFECT_BATON_PASS || GetConfig(B_BATON_PASS_TRAPPING) >= GEN_5)
    {
        for (enum BattlerId i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].volatiles.escapePrevention && gBattleMons[i].volatiles.battlerPreventingEscape == battler)
                gBattleMons[i].volatiles.escapePrevention = FALSE;
        }
    }

    // Clear volatiles - reapply some if Baton Pass was used
    memset(&gBattleMons[battler].volatiles, 0, sizeof(struct Volatiles));
    if (effect == EFFECT_BATON_PASS)
    {
        // Transfer Baton Passable volatile statuses
        VOLATILE_DEFINITIONS(UNPACK_VOLATILE_BATON_PASSABLES)
        /* Expands to the following (compiler removes `if` statements):
         * gBattleMons[battler].volatiles.confusionTimer = volatilesCopy->confusionTimer;
         * gBattleMons[battler].volatiles.substitute = volatilesCopy->substitute;
         * gBattleMons[battler].volatiles.escapePrevention = volatilesCopy->escapePrevention;
         * ...etc
         */

        enum BattlerId i;
        if (gBattleMons[battler].volatiles.powerTrick)
            SWAP(gBattleMons[battler].attack, gBattleMons[battler].defense, i);

        if (gBattleMons[battler].volatiles.gastroAcid && gAbilitiesInfo[gBattleMons[battler].ability].cantBeSuppressed)
            gBattleMons[battler].volatiles.gastroAcid = FALSE;
    }

    if (effect == EFFECT_BATON_PASS)
    {
        gBattleMons[battler].volatiles.substituteHP = volatilesCopy->substituteHP;
        gBattleMons[battler].volatiles.perishSongTimer = volatilesCopy->perishSongTimer;
        gBattleMons[battler].volatiles.battlerPreventingEscape = volatilesCopy->battlerPreventingEscape;
        gBattleMons[battler].volatiles.embargoTimer = volatilesCopy->embargoTimer;
        gBattleMons[battler].volatiles.healBlockTimer = volatilesCopy->healBlockTimer;
    }
    else if (effect == EFFECT_SHED_TAIL)
    {
        gBattleMons[battler].volatiles.substitute = TRUE;
        gBattleMons[battler].volatiles.substituteHP = volatilesCopy->substituteHP;
    }

    gBattleStruct->battlerState[battler].notOnField = FALSE;
    gBattleMons[battler].volatiles.truantSwitchInHack = volatilesCopy->truantSwitchInHack;

    gBattleStruct->hazardsCounter = 0;
    gSpecialStatuses[battler].queuedSwitch = NO_QUEUED_SWITCH;
    gBattleStruct->eventState.arenaTurn = 0xFF;

    // Reset damage to prevent things like red card activating if the switched-in mon is holding it
    gSpecialStatuses[battler].damagedByAttack = FALSE;

    // Clear selected party ID so Revival Blessing doesn't get confused.
    gSelectedMonPartyId = PARTY_SIZE;

    // Allow for illegal abilities within tests.
    #if TESTING
    if (gTestRunnerEnabled)
    {
        enum BattleTrainer trainer = GetBattlerTrainer(battler);
        u32 partyIndex = gBattlerPartyIndexes[battler];
        if (TestRunner_Battle_GetForcedAbility(trainer, partyIndex))
            gBattleMons[battler].ability = TestRunner_Battle_GetForcedAbility(trainer, partyIndex);
    }
    #endif // TESTING

    Ai_UpdateSwitchInData(battler);
}

void FaintClearSetData(enum BattlerId battler)
{
    // Data cleared both on switch and faint
    ClearSetDataOnLeave(battler);

    for (enum Stat i = 0; i < NUM_BATTLE_STATS; i++)
        gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;

    bool32 keepTransformed = gBattleMons[battler].volatiles.transformed;
    enum Species originalSpecies = gBattleMons[battler].volatiles.transformedMonSpecies;
    memset(&gBattleMons[battler].volatiles, 0, sizeof(struct Volatiles));
    gBattleMons[battler].volatiles.transformed = keepTransformed; // Edge case: Keep Transformed status to prevent triggering FORM_CHANGE_FAINT on transformed mons.
    gBattleMons[battler].volatiles.transformedMonSpecies = originalSpecies; // Also keep transformed species for ev and exp calculation

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].volatiles.battlerWithSureHit == battler + 1)
            gBattleMons[i].volatiles.battlerWithSureHit = 0;
        if (gBattleMons[i].volatiles.escapePrevention && gBattleMons[i].volatiles.battlerPreventingEscape == battler)
            gBattleMons[i].volatiles.escapePrevention = FALSE;
    }

    if (gBattleStruct->battlerState[battler].commanderSpecies != SPECIES_NONE)
    {
        enum BattlerId partner = GetPartnerBattler(battler);
        // Clear commander state immediately so a replacement doesn't inherit it.
        gBattleStruct->battlerState[battler].commanderSpecies = SPECIES_NONE;
        if (gBattleMons[partner].volatiles.semiInvulnerable == STATE_COMMANDER)
        {
            gBattleMons[partner].volatiles.semiInvulnerable = STATE_NONE;
            if (IsBattlerAlive(partner))
            {
                BtlController_EmitSpriteInvisibility(partner, B_COMM_TO_CONTROLLER, FALSE);
                MarkBattlerForControllerExec(partner);
            }
        }
    }

    Ai_UpdateFaintData(battler);
    TryBattleFormChange(battler, FORM_CHANGE_FAINT, GetBattlerAbility(battler));
}

static void DoBattleIntro(void)
{
    s32 i;
    enum BattlerId battler;

    switch ((enum BattleIntroStates)gBattleStruct->eventState.battleIntro)
    {
    case BATTLE_INTRO_STATE_GET_MON_DATA:
        battler = gBattleCommunication[1];
        BtlController_EmitGetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(battler);
        gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_LOOP_BATTLER_DATA:
        if (!gBattleControllerExecFlags)
        {
            if (++gBattleCommunication[1] == gBattlersCount)
                gBattleStruct->eventState.battleIntro++;
            else
                gBattleStruct->eventState.battleIntro = BATTLE_INTRO_STATE_GET_MON_DATA;
        }
        break;
    case BATTLE_INTRO_STATE_PREPARE_BG_SLIDE:
        if (!gBattleControllerExecFlags)
        {
            battler = GetBattlerAtPosition(0);
            BtlController_EmitIntroSlide(battler, B_COMM_TO_CONTROLLER, gBattleEnvironment);
            MarkBattlerForControllerExec(battler);
            gBattleCommunication[0] = 0;
            gBattleCommunication[1] = 0;
            gBattleStruct->eventState.battleIntro++;
        }
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_BG_SLIDE:
        if (!gBattleControllerExecFlags)
            gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_DRAW_SPRITES:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && IsOnPlayerSide(battler))
            {
                memset(&gBattleMons[battler], 0, sizeof(struct BattlePokemon));
            }
            else
            {
                memcpy(&gBattleMons[battler], &gBattleResources->bufferB[battler][4], sizeof(struct BattlePokemon));
                gBattleMons[battler].types[0] = GetSpeciesType(gBattleMons[battler].species, 0);
                gBattleMons[battler].types[1] = GetSpeciesType(gBattleMons[battler].species, 1);
                gBattleMons[battler].types[2] = TYPE_MYSTERY;
                gBattleMons[battler].ability = GetAbilityBySpecies(gBattleMons[battler].species, gBattleMons[battler].abilityNum);
                gBattleStruct->battlerState[battler].hpOnSwitchout = gBattleMons[battler].hp;
                memset(&gBattleMons[battler].volatiles, 0, sizeof(struct Volatiles));
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                    gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;
                #if TESTING
                if (gTestRunnerEnabled)
                {
                    enum BattleTrainer trainer = GetBattlerTrainer(battler);
                    u32 partyIndex = gBattlerPartyIndexes[battler];
                    if (TestRunner_Battle_GetForcedAbility(trainer, partyIndex))
                        gBattleMons[battler].ability = TestRunner_Battle_GetForcedAbility(trainer, partyIndex);
                }
                #endif
            }

            // Draw sprite.
            switch (GetBattlerPosition(battler))
            {
            case B_POSITION_PLAYER_LEFT: // player sprite
                BtlController_EmitDrawTrainerPic(battler, B_COMM_TO_CONTROLLER);
                MarkBattlerForControllerExec(battler);
                break;
            case B_POSITION_OPPONENT_LEFT:
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER) // opponent 1 sprite
                {
                    BtlController_EmitDrawTrainerPic(battler, B_COMM_TO_CONTROLLER);
                    MarkBattlerForControllerExec(battler);
                }
                else // wild mon 1
                {
                    BtlController_EmitLoadMonSprite(battler, B_COMM_TO_CONTROLLER);
                    MarkBattlerForControllerExec(battler);
                    gBattleResults.lastOpponentSpecies = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
                }
                break;
            case B_POSITION_PLAYER_RIGHT:
                if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)) // partner sprite
                {
                    BtlController_EmitDrawTrainerPic(battler, B_COMM_TO_CONTROLLER);
                    MarkBattlerForControllerExec(battler);
                }
                break;
            case B_POSITION_OPPONENT_RIGHT:
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                {
                    if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS) && !BATTLE_TWO_VS_ONE_OPPONENT) // opponent 2 if exists
                    {
                        BtlController_EmitDrawTrainerPic(battler, B_COMM_TO_CONTROLLER);
                        MarkBattlerForControllerExec(battler);
                    }
                }
                else if (IsBattlerAlive(battler)) // wild mon 2 if alive
                {
                    BtlController_EmitLoadMonSprite(battler, B_COMM_TO_CONTROLLER);
                    MarkBattlerForControllerExec(battler);
                    gBattleResults.lastOpponentSpecies = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
                }
                break;
            default:
                break;
            }

            if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
                BattleArena_InitPoints();
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            gBattleStruct->eventState.battleIntro++;
        else // Skip party summary since it is a wild battle.
            gBattleStruct->eventState.battleIntro = BATTLE_INTRO_STATE_INTRO_TEXT;
        break;
    case BATTLE_INTRO_STATE_DRAW_PARTY_SUMMARY:
        if (!gBattleControllerExecFlags)
        {
            struct HpAndStatus hpStatus[MAX_BATTLE_TRAINERS][PARTY_SIZE];

            u32 lastId = MULTI_PARTY_SIZE;
            for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
            {
                if (AreMultiPartiesFullTeams() || !BattleSideHasTwoTrainers(trainer & BIT_SIDE))
                    lastId = PARTY_SIZE;

                for (i = 0; i < PARTY_SIZE; i++)
                {
                    if (GetMonData(&gParties[trainer][i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE
                     || GetMonData(&gParties[trainer][i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG
                     || i >= lastId)
                    {
                        hpStatus[trainer][i].hp = HP_EMPTY_SLOT;
                        hpStatus[trainer][i].status = 0;
                    }
                    else
                    {
                        hpStatus[trainer][i].hp = GetMonData(&gParties[trainer][i], MON_DATA_HP);
                        hpStatus[trainer][i].status = GetMonData(&gParties[trainer][i], MON_DATA_STATUS);
                    }
                }
            }

            for (enum BattlerPosition position = B_POSITION_PLAYER_LEFT; position < MAX_POSITION_COUNT; position++)
            {
                if (position > B_POSITION_OPPONENT_LEFT && !BattleSideHasTwoTrainers(position & BIT_SIDE))
                    continue;
                battler = GetBattlerAtPosition(position);
                BtlController_EmitDrawPartyStatusSummary(battler, B_COMM_TO_CONTROLLER, hpStatus[GetBattlerTrainer(battler)], PARTY_SUMM_SKIP_DRAW_DELAY);
                MarkBattlerForControllerExec(battler);
            }

            gBattleStruct->eventState.battleIntro++;
        }
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_PARTY_SUMMARY:
        if (!gBattleControllerExecFlags)
            gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_INTRO_TEXT:
        if (!IsBattlerMarkedForControllerExec(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
        {
            PrepareStringBattle(STRINGID_INTROMSG, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
            gBattleStruct->eventState.battleIntro++;
        }
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_INTRO_TEXT:
        if (!IsBattlerMarkedForControllerExec(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                gBattleStruct->eventState.battleIntro++;
            }
            else
            {
                if (B_FAST_INTRO_PKMN_TEXT == TRUE)
                    gBattleStruct->eventState.battleIntro = BATTLE_INTRO_STATE_WAIT_FOR_WILD_BATTLE_TEXT;
                else
                    gBattleStruct->eventState.battleIntro = BATTLE_INTRO_STATE_WAIT_FOR_TRAINER_2_SEND_OUT_ANIM;
            }
        }
        break;
    case BATTLE_INTRO_STATE_TRAINER_SEND_OUT_TEXT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
            PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
        else
            PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
        gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_TRAINER_SEND_OUT_TEXT:
        if (!gBattleControllerExecFlags)
            gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_TRAINER_1_SEND_OUT_ANIM:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
            battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        else
            battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);

        BtlController_EmitIntroTrainerBallThrow(battler, B_COMM_TO_CONTROLLER);
        MarkBattlerForControllerExec(battler);
        gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_TRAINER_2_SEND_OUT_ANIM:
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS) && !BATTLE_TWO_VS_ONE_OPPONENT)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                battler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            else
                battler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

            BtlController_EmitIntroTrainerBallThrow(battler, B_COMM_TO_CONTROLLER);
            MarkBattlerForControllerExec(battler);
        }
        if (B_FAST_INTRO_PKMN_TEXT == TRUE
          && !(gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_LINK)))
            gBattleStruct->eventState.battleIntro = BATTLE_INTRO_STATE_WAIT_FOR_WILD_BATTLE_TEXT; // Print at the same time as trainer sends out second mon.
        else
            gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_TRAINER_2_SEND_OUT_ANIM:
        if (!gBattleControllerExecFlags)
            gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_WILD_BATTLE_TEXT:
        if (!IsBattlerMarkedForControllerExec(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_GHOST && CheckBagHasItem(ITEM_SILPH_SCOPE, 1))
            {
                gBattleScripting.battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                BattleScriptExecute(BattleScript_SilphScopeUnveiled);
            }
            gBattleStruct->eventState.battleIntro++;
        }
        break;
    case BATTLE_INTRO_STATE_PRINT_PLAYER_SEND_OUT_TEXT:
        if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

            // A hack that makes fast intro work in trainer battles too.
            if (B_FAST_INTRO_PKMN_TEXT == TRUE
                && gBattleTypeFlags & BATTLE_TYPE_TRAINER
                && !(gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_LINK))
                && gSprites[gHealthboxSpriteIds[battler ^ BIT_SIDE]].callback == SpriteCallbackDummy)
            {
                return;
            }

            PrepareStringBattle(STRINGID_INTROSENDOUT, battler);
        }
        gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_WAIT_FOR_PLAYER_SEND_OUT_TEXT:
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleControllerExecFlags))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

            if (!IsBattlerMarkedForControllerExec(battler))
                gBattleStruct->eventState.battleIntro++;
        }
        break;
    case BATTLE_INTRO_STATE_PRINT_PLAYER_1_SEND_OUT_TEXT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
            battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        else
            battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

        BtlController_EmitIntroTrainerBallThrow(battler, B_COMM_TO_CONTROLLER);
        MarkBattlerForControllerExec(battler);
        gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_PRINT_PLAYER_2_SEND_OUT_TEXT:
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                battler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            else
                battler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);

            BtlController_EmitIntroTrainerBallThrow(battler, B_COMM_TO_CONTROLLER);
            MarkBattlerForControllerExec(battler);
        }
        gBattleStruct->eventState.battleIntro++;
        break;
    case BATTLE_INTRO_STATE_SET_DEX_AND_BATTLE_VARS:
        if (!gBattleControllerExecFlags)
        {
            gBattleStruct->eventState.beforeFirstTurn = 0;
            gBattleStruct->switchInBattlerCounter = 0;
            Ai_InitPartyStruct(); // Save mons party counts, and first 2/4 mons on the battlefield.

            // mark all battlers as sent out
            for (battler = 0; battler < gBattlersCount; battler++)
                GetBattlerPartyState(battler)->sentOut = TRUE;

#define UNPACK_STARTING_STATUS_TO_BATTLE(_enum, _fieldName, ...) gStartingStatuses._fieldName = (statusesOpponentA._fieldName || statusesOpponentB._fieldName || gStartingStatuses._fieldName);

            struct StartingStatuses statusesOpponentA = {0};
            struct StartingStatuses statusesOpponentB = {0};

            // Try to set a status to start the battle with
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !IsSpecialTrainer(TRAINER_BATTLE_PARAM.opponentA))
            {
                statusesOpponentA = GetTrainerStartingStatusFromId(TRAINER_BATTLE_PARAM.opponentA);
                if (TRAINER_BATTLE_PARAM.opponentB != 0xFFFF)
                    statusesOpponentB = GetTrainerStartingStatusFromId(TRAINER_BATTLE_PARAM.opponentB);
            }
            STARTING_STATUS_DEFINITIONS(UNPACK_STARTING_STATUS_TO_BATTLE);
            gBattleMainFunc = TryDoEventsBeforeFirstTurn;
        }
        break;
    }
}

static void TryDoEventsBeforeFirstTurn(void)
{
    s32 i;

    if (gBattleControllerExecFlags)
        return;

    switch (gBattleStruct->eventState.beforeFirstTurn)
    {
    case FIRST_TURN_EVENTS_START:
        LoadIndicatorSpritesGfx();
        // Set invalid mons as absent(for example when starting a double battle with only one Pokémon).
        if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                gBattleStruct->monToSwitchIntoId[battler] = PARTY_SIZE; // Included here because switches can happen before during set ups (eg. eject pack)
                struct Pokemon *mon = GetBattlerMon(battler);
                if (!IsBattlerAlive(battler) || gBattleMons[battler].species == SPECIES_NONE || GetMonData(mon, MON_DATA_IS_EGG))
                    gAbsentBattlerFlags |= 1u << battler;
            }
        }

        // Allow for illegal abilities within tests.
        #if TESTING
        if (gTestRunnerEnabled)
        {
            for (enum BattlerId battler = 0; battler < gBattlersCount; ++battler)
            {
                enum BattleTrainer trainer = GetBattlerTrainer(battler);
                u32 partyIndex = gBattlerPartyIndexes[battler];
                if (TestRunner_Battle_GetForcedAbility(trainer, partyIndex))
                    gBattleMons[battler].ability = TestRunner_Battle_GetForcedAbility(trainer, partyIndex);
            }
        }
        #endif // TESTING

        gBattleStruct->speedTieBreaks = RandomUniform(RNG_SPEED_TIE, 0, Factorial(MAX_BATTLERS_COUNT) - 1);
        gBattleTurnCounter = 0;
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_EVENTS_OVERWORLD_WEATHER:
        gBattleStruct->eventState.beforeFirstTurn++;
        if (TryFieldEffects(FIELD_EFFECT_OVERWORLD_WEATHER))
            return;
        break;
    case FIRST_TURN_EVENTS_TERRAIN:
        gBattleStruct->eventState.beforeFirstTurn++;
        if (TryFieldEffects(FIELD_EFFECT_OVERWORLD_TERRAIN))
            return;
        break;
    case FIRST_TURN_EVENTS_STARTING_STATUS:
        while (TRUE)
        {
            if (TryFieldEffects(FIELD_EFFECT_TRAINER_STATUSES))
                return;
            break;
        }
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_EVENTS_TOTEM_BOOST:
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            if (gQueuedStatBoosts[battler].stats == 0)
                continue;

            for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            {
                if (gQueuedStatBoosts[battler].stats & (1 << stat))
                {
                    s32 stage = gQueuedStatBoosts[battler].statChanges[stat];
                    gBattleMons[battler].statStages[stat] += stage;
                    if (gBattleMons[battler].statStages[stat] > MAX_STAT_STAGE)
                        gBattleMons[battler].statStages[stat] = MAX_STAT_STAGE;
                    else if (gBattleMons[battler].statStages[stat] < MIN_STAT_STAGE)
                        gBattleMons[battler].statStages[stat] = MIN_STAT_STAGE;
                }
            }

            gBattlerAttacker = battler;
            gQueuedStatBoosts[battler].stats = 0;
            BattleScriptPushCursorAndCallback(BattleScript_TotemBoost);
            return;
        }
        memset(gQueuedStatBoosts, 0, sizeof(gQueuedStatBoosts)); // erase all totem boosts for Mirror Herb and Opportunist
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_SWITCH_IN_EVENTS:
        gBattleStruct->eventState.switchIn = 0;
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            gBattleStruct->battlerState[battler].switchIn = TRUE;
        BattleScriptPushCursorAndCallback(BattleScript_FirstTurnSwitchInEvents);
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_FAINTED_BATTLERS:
        // Handle any Pokemon that fainted from starting hazards before transitioning to action selection
        if (HandleFaintedMonActions())
            return;
        gBattleStruct->eventState.faintedAction = 0;
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_EVENTS_TRAINER_SLIDE_A:
        if (ShouldDoTrainerSlide(B_BATTLER_1, TRAINER_SLIDE_BEFORE_FIRST_TURN))
            BattleScriptExecute(BattleScript_TrainerASlideMsgEnd);
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_EVENTS_TRAINER_SLIDE_B:
        if (ShouldDoTrainerSlide(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), TRAINER_SLIDE_BEFORE_FIRST_TURN))
            BattleScriptExecute(BattleScript_TrainerBSlideMsgEnd);
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_EVENTS_TRAINER_SLIDE_PARTNER:
        if (ShouldDoTrainerSlide(B_BATTLER_2, TRAINER_SLIDE_BEFORE_FIRST_TURN))
            BattleScriptExecute(BattleScript_TrainerPartnerSlideMsgEnd);
        gBattleStruct->eventState.beforeFirstTurn++;
        break;
    case FIRST_TURN_EVENTS_END:
        for (enum BattlerId battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
        {
            gBattleStruct->monToSwitchIntoId[battler] = PARTY_SIZE;
            gChosenActionByBattler[battler] = B_ACTION_NONE;
            gChosenMoveByBattler[battler] = MOVE_NONE;
        }
        TurnValuesCleanUp(FALSE);
        memset(&gSpecialStatuses, 0, sizeof(gSpecialStatuses));
        memset(gQueuedStatBoosts, 0, sizeof(gQueuedStatBoosts));
        BattlePutTextOnWindow(gText_EmptyString3, B_WIN_MSG);
        AssignUsableGimmicks();
        SetShellSideArmCategory();
        SetAiLogicDataForTurn(gAiLogicData); // get assumed abilities, hold effects, etc of all battlers
        gBattleMainFunc = HandleTurnActionSelectionState;
        ResetSentPokesToOpponentValue();

        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;

        gBattleStruct->eventState.endTurnBlock = 0;
        gBattleStruct->eventState.endTurnBattler = 0;
        gBattleScripting.moveendState = 0;
        gBattleStruct->eventState.faintedAction = 0;
        gBattleStruct->eventState.endTurn = 0;

        if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        {
            StopCryAndClearCrySongs();
            BattleScriptExecute(BattleScript_ArenaTurnBeginning);
        }

        gBattleStruct->eventState.beforeFirstTurn = 0;
        break;
    }
}

static void HandleEndTurn_ContinueBattle(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gBattleMainFunc = BattleTurnPassed;
        for (u32 i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            gBattleMons[battler].volatiles.flinched = FALSE;
            if ((gBattleMons[battler].status1 & STATUS1_SLEEP) && (gBattleMons[battler].volatiles.multipleTurns))
                CancelMultiTurnMoves(battler);
        }
        gBattleStruct->eventState.endTurnBlock = 0;
        gBattleStruct->eventState.endTurnBattler = 0;
        gBattleStruct->eventState.endTurn = 0;
    }
}

void SetBattleCallback(void (*func)(void))
{
    if (gBattleResources->battleCallbackStack->size != 0)
        gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size - 1] = func;
    else
        gBattleMainFunc = func;
}

void BattleTurnPassed(void)
{
    BattleScriptExecute(BattleScript_EndTurnEvents);
}

bool32 EndTurnEvents(void) // Called from Battle Script
{
    gBattleStruct->speedTieBreaks = RandomUniform(RNG_SPEED_TIE, 0, Factorial(MAX_BATTLERS_COUNT) - 1);

    TurnValuesCleanUp(TRUE);

    if (DoEndTurnEffects())
        return TRUE;

    gBattleStruct->eventState.faintedAction = 0;

    TurnValuesCleanUp(FALSE);
    gHitMarker &= ~HITMARKER_PLAYER_FAINTED;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleScripting.moveendState = 0;

    for (u32 i = 0; i < 5; i++)
        gBattleCommunication[i] = 0;

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        SetBattleCallback(RunTurnActionsFunctions);
        return FALSE;
    }

    if (gBattleResults.battleTurnCounter < 0xFF)
    {
        gBattleResults.battleTurnCounter++;
        gBattleStruct->eventState.arenaTurn++;
    }

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        gChosenActionByBattler[battler] = B_ACTION_NONE;
        gChosenMoveByBattler[battler] = MOVE_NONE;
        gBattleStruct->monToSwitchIntoId[battler] = PARTY_SIZE;
        gBattleMons[battler].volatiles.electrified = FALSE;
        gBattleMons[battler].volatiles.flinched = FALSE;
        gBattleMons[battler].volatiles.powder = FALSE;
        memset(&gQueuedStatBoosts[battler], 0, sizeof(struct QueuedStatBoost));

        if (gBattleStruct->battlerState[battler].stompingTantrumTimer > 0)
            gBattleStruct->battlerState[battler].stompingTantrumTimer--;
    }

    for (u32 i = 0; i < NUM_BATTLE_SIDES; i++)
    {
        if (gSideTimers[i].retaliateTimer > 0)
            gSideTimers[i].retaliateTimer--;
    }

    gFieldStatuses &= ~STATUS_FIELD_ION_DELUGE;

    BattlePutTextOnWindow(gText_EmptyString3, B_WIN_MSG);
    AssignUsableGimmicks();
    SetShellSideArmCategory();
    SetAiLogicDataForTurn(gAiLogicData); // get assumed abilities, hold effects, etc of all battlers
    SetBattleCallback(HandleTurnActionSelectionState);

    return FALSE;
}

u8 IsRunningFromBattleImpossible(enum BattlerId battler)
{
    enum HoldEffect holdEffect;
    u32 i;

    if (FlagGet(WE_FLAG_NO_RUNNING))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE;
        return BATTLE_RUN_FORBIDDEN;
    }

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY_E_READER)
        holdEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = GetItemHoldEffect(gBattleMons[battler].item);

    gPotentialItemEffectBattler = battler;

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE) // Cannot ever run from saving Birch's battle.
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DONT_LEAVE_BIRCH;
        return BATTLE_RUN_FORBIDDEN;
    }
    if (GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT && WILD_DOUBLE_BATTLE
        && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT))) // The second Pokémon cannot run from a double wild battle, unless it's the only alive mon.
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE;
        return BATTLE_RUN_FORBIDDEN;
    }

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
        return BATTLE_RUN_SUCCESS;
    if (GetConfig(B_GHOSTS_ESCAPE) >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return BATTLE_RUN_SUCCESS;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return BATTLE_RUN_SUCCESS;
    if (GetBattlerAbility(battler) == ABILITY_RUN_AWAY)
        return BATTLE_RUN_SUCCESS;

    if ((i = IsAbilityPreventingEscape(battler)))
    {
        gBattleScripting.battler = i - 1;
        gLastUsedAbility = gBattleMons[i - 1].ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PREVENTS_ESCAPE;
        return BATTLE_RUN_FAILURE;
    }

    if (!CanBattlerEscape(battler))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE;
        return BATTLE_RUN_FORBIDDEN;
    }
    return BATTLE_RUN_SUCCESS;
}

void SwitchTwoBattlersInParty(enum BattlerId battler, enum BattlerId battler2)
{
    s32 i;
    u32 partyId1, partyId2;

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler2]);
    SwitchPartyMonSlots(partyId1, partyId2);

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
    {
        *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        *(GetPartnerBattler(battler) * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
    }
}

void SwitchPartyOrder(enum BattlerId battler)
{
    s32 i;
    u32 partyId1, partyId2;

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(gBattleStruct->monToSwitchIntoId[battler]);
    SwitchPartyMonSlots(partyId1, partyId2);

    if (gBattleStruct->battlerState[battler].originalBattlerPartyId == partyId1)
        gBattleStruct->battlerState[battler].originalBattlerPartyId = partyId2;
    else if (gBattleStruct->battlerState[battler].originalBattlerPartyId == partyId2)
        gBattleStruct->battlerState[battler].originalBattlerPartyId = partyId1;

    if (IsDoubleBattle())
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
            *(GetPartnerBattler(battler) * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
    else
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
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

    gAiLogicData->reverseBattlerLogicOrder = RandomPercentage(RNG_AI_REVERSE_BATTLER_LOGIC_ORDER, GetConfig(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE)) && IsDoubleBattle();

    gBattleCommunication[ACTIONS_CONFIRMED_COUNT] = 0;
    for (enum BattlerId battlerIndex = 0; battlerIndex < gBattlersCount; battlerIndex++)
    {
        enum BattlerId battler = gAiLogicData->reverseBattlerLogicOrder ? GetPartnerBattler(battlerIndex) : battlerIndex;
        enum BattlerPosition position = GetBattlerPosition(battler);
        switch (gBattleCommunication[battler])
        {
        case STATE_TURN_START_RECORD: // Recorded battle related action on start of every turn.
            RecordedBattle_CopyBattlerMoves(battler);
            gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
            bool32 isAiBattler = (gBattleTypeFlags & BATTLE_TYPE_HAS_AI || IsWildMonSmart()) && (BattlerHasAi(battler) && !(gBattleTypeFlags & BATTLE_TYPE_PALACE));
            if (isAiBattler)
            {
                ComputeAiBattlerDecisions(battler); // Do AI score computations here so we can use them in AI_TrySwitchOrUseItem
            }
            // fallthrough
        case STATE_BEFORE_ACTION_CHOSEN: // Choose an action.
            gBattleStruct->monToSwitchIntoId[battler] = PARTY_SIZE;
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI
                || (position & BIT_FLANK) == B_FLANK_LEFT
                || gAbsentBattlerFlags & 1u << GetBattlerAtPosition(GetPartnerPosition(position))
                || gBattleCommunication[GetBattlerAtPosition(GetPartnerPosition(position))] == STATE_WAIT_ACTION_CONFIRMED)
            {
                if (gAbsentBattlerFlags & 1u << battler || gBattleStruct->battlerState[battler].commandingDondozo)
                {
                    gChosenActionByBattler[battler] = B_ACTION_NOTHING_FAINTED;
                    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED;
                    else
                        gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    if (gBattleMons[battler].volatiles.multipleTurns
                        || gBattleMons[battler].volatiles.rechargeTimer > 0)
                    {
                        gChosenActionByBattler[battler] = B_ACTION_USE_MOVE;
                        gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else if (WILD_DOUBLE_BATTLE
                             && position == B_POSITION_PLAYER_RIGHT
                             && (gBattleStruct->throwingPokeBall || gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] == B_ACTION_RUN)
                             && gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] != B_ACTION_NOTHING_FAINTED)
                    {
                        gBattleStruct->throwingPokeBall = FALSE;
                        gChosenActionByBattler[battler] = B_ACTION_NOTHING_FAINTED; // Not fainted, but it cannot move, because of the throwing ball.
                        gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else if (B_RUN_TRAINER_BATTLE
                          && gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                          && position == B_POSITION_PLAYER_RIGHT
                          && gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] == B_ACTION_RUN
                          && gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] != B_ACTION_NOTHING_FAINTED)
                    {
                        gChosenActionByBattler[battler] = B_ACTION_USE_MOVE;
                        gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else
                    {
                        gBattleStruct->itemPartyIndex[battler] = PARTY_SIZE;
                        BtlController_EmitChooseAction(battler, B_COMM_TO_CONTROLLER, gChosenActionByBattler[0], gBattleResources->bufferB[0][1] | (gBattleResources->bufferB[0][2] << 8));
                        MarkBattlerForControllerExec(battler);
                        gBattleCommunication[battler]++;
                    }
                }
            }
            break;
        case STATE_WAIT_ACTION_CHOSEN: // Try to perform an action.
            if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
            {
                RecordedBattle_SetBattlerAction(battler, gBattleResources->bufferB[battler][1]);
                gChosenActionByBattler[battler] = gBattleResources->bufferB[battler][1];

                switch (gBattleResources->bufferB[battler][1])
                {
                case B_ACTION_USE_MOVE:
                    if (AreAllMovesUnusable(battler))
                    {
                        gBattleCommunication[battler] = STATE_SELECTION_SCRIPT;
                        gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                        gBattleStruct->stateIdAfterSelScript[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        gBattleStruct->moveTarget[battler] = gBattleResources->bufferB[battler][3];
                        return;
                    }
                    else if (GetConfig(B_ENCORE_TARGET) < GEN_5 && gBattleMons[battler].volatiles.encoredMove != MOVE_NONE)
                    {
                        gChosenMoveByBattler[battler] = gBattleMons[battler].volatiles.encoredMove;
                        gBattleStruct->chosenMovePositions[battler] = gBattleMons[battler].volatiles.encoredMovePos;
                        gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        if (gTestRunnerEnabled)
                        {
                            UNUSED enum Gimmick gimmick = GIMMICK_NONE;
                            if (gBattleResources->bufferB[battler][2] & RET_GIMMICK)
                                gimmick = gBattleStruct->gimmick.usableGimmick[battler];
                            TestRunner_Battle_CheckChosenMove(battler, gBattleMons[battler].volatiles.encoredMove, gBattleMons[battler].volatiles.encoredMovePos, gimmick);
                        }
                        return;
                    }
                    else
                    {
                        struct ChooseMoveStruct moveInfo;

                        moveInfo.zmove = gBattleStruct->zmove;
                        moveInfo.species = gBattleMons[battler].species;
                        moveInfo.monTypes[0] = gBattleMons[battler].types[0];
                        moveInfo.monTypes[1] = gBattleMons[battler].types[1];
                        moveInfo.monTypes[2] = gBattleMons[battler].types[2];

                        for (i = 0; i < MAX_MON_MOVES; i++)
                        {
                            moveInfo.moves[i] = gBattleMons[battler].moves[i];
                            moveInfo.currentPP[i] = gBattleMons[battler].pp[i];
                            moveInfo.maxPP[i] = CalculatePPWithBonus(
                                                            gBattleMons[battler].moves[i],
                                                            gBattleMons[battler].ppBonuses,
                                                            i);
                        }

                        BtlController_EmitChooseMove(battler, B_COMM_TO_CONTROLLER, IsDoubleBattle() != 0, FALSE, &moveInfo);
                        MarkBattlerForControllerExec(battler);
                    }
                    break;
                case B_ACTION_USE_ITEM:
                    if (ShouldBattleRestrictionsApply(battler) && !IsAllowedToUseBag())
                    {
                        RecordedBattle_ClearBattlerAction(battler, 1);
                        gSelectionBattleScripts[battler] = BattleScript_ActionSelectionItemsCantBeUsed;
                        gBattleCommunication[battler] = STATE_SELECTION_SCRIPT;
                        gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                        gBattleStruct->stateIdAfterSelScript[battler] = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }

                    if (((gBattleTypeFlags & (BATTLE_TYPE_LINK
                                            | BATTLE_TYPE_FRONTIER_NO_PYRAMID
                                            | BATTLE_TYPE_EREADER_TRAINER
                                            | BATTLE_TYPE_RECORDED_LINK))
                                            && !gTestRunnerEnabled)
                                            // Or if currently held by Sky Drop
                                            || gBattleMons[battler].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
                    {
                        RecordedBattle_ClearBattlerAction(battler, 1);
                        gSelectionBattleScripts[battler] = BattleScript_ActionSelectionItemsCantBeUsed;
                        gBattleCommunication[battler] = STATE_SELECTION_SCRIPT;
                        gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                        gBattleStruct->stateIdAfterSelScript[battler] = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    else
                    {
                        BtlController_EmitChooseItem(battler, B_COMM_TO_CONTROLLER, gBattleStruct->battlerPartyOrders[battler]);
                        MarkBattlerForControllerExec(battler);
                    }
                    break;
                case B_ACTION_SWITCH:
                    gBattleStruct->battlerPartyIndexes[battler] = gBattlerPartyIndexes[battler];
                    if (gBattleTypeFlags & BATTLE_TYPE_ARENA
                        || gBattleStruct->battlerState[battler].commanderSpecies != SPECIES_NONE
                        || (!CanBattlerEscape(battler) && GetBattlerHoldEffect(battler) != HOLD_EFFECT_SHED_SHELL))
                    {
                        BtlController_EmitChoosePokemon(battler, B_COMM_TO_CONTROLLER, PARTY_ACTION_CANT_SWITCH, PARTY_SIZE, ABILITY_NONE, 0, gBattleStruct->battlerPartyOrders[battler]);
                    }
                    else if (GetItemHoldEffect(gBattleMons[battler].item) != HOLD_EFFECT_SHED_SHELL
                      && (i = IsAbilityPreventingEscape(battler)))   // must be last to keep i value integrity
                    {
                        BtlController_EmitChoosePokemon(battler, B_COMM_TO_CONTROLLER, PARTY_ACTION_ABILITY_PREVENTS, PARTY_SIZE, gBattleMons[i - 1].ability, i - 1, gBattleStruct->battlerPartyOrders[battler]);
                    }
                    else
                    {
                        if (battler == 2 && gChosenActionByBattler[0] == B_ACTION_SWITCH)
                            BtlController_EmitChoosePokemon(battler, B_COMM_TO_CONTROLLER, PARTY_ACTION_CHOOSE_MON, gBattleStruct->monToSwitchIntoId[0], ABILITY_NONE, 0, gBattleStruct->battlerPartyOrders[battler]);
                        else if (battler == 3 && gChosenActionByBattler[1] == B_ACTION_SWITCH)
                            BtlController_EmitChoosePokemon(battler, B_COMM_TO_CONTROLLER, PARTY_ACTION_CHOOSE_MON, gBattleStruct->monToSwitchIntoId[1], ABILITY_NONE, 0, gBattleStruct->battlerPartyOrders[battler]);
                        else
                            BtlController_EmitChoosePokemon(battler, B_COMM_TO_CONTROLLER, PARTY_ACTION_CHOOSE_MON, PARTY_SIZE, ABILITY_NONE, 0, gBattleStruct->battlerPartyOrders[battler]);
                    }
                    MarkBattlerForControllerExec(battler);
                    break;
                case B_ACTION_SAFARI_BALL:
                    if (IsPlayerPartyAndPokemonStorageFull())
                    {
                        gSelectionBattleScripts[battler] = BattleScript_PrintFullBox;
                        gBattleCommunication[battler] = STATE_SELECTION_SCRIPT;
                        gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                        gBattleStruct->stateIdAfterSelScript[battler] = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    break;
                case B_ACTION_SAFARI_POKEBLOCK:
                    if (!IS_FRLG)
                    {
                        BtlController_EmitChooseItem(battler, B_COMM_TO_CONTROLLER, gBattleStruct->battlerPartyOrders[battler]);
                        MarkBattlerForControllerExec(battler);
                    }
                    break;
                case B_ACTION_CANCEL_PARTNER:
                    gBattleCommunication[battler] = STATE_WAIT_SET_BEFORE_ACTION;
                    gBattleCommunication[GetPartnerBattler(battler)] = STATE_BEFORE_ACTION_CHOSEN;
                    RecordedBattle_ClearBattlerAction(battler, 1);
                    if (gBattleMons[GetPartnerBattler(battler)].volatiles.multipleTurns
                        || gBattleMons[GetPartnerBattler(battler)].volatiles.rechargeTimer > 0)
                    {
                        BtlController_EmitEndBounceEffect(battler, B_COMM_TO_CONTROLLER);
                        MarkBattlerForControllerExec(battler);
                        return;
                    }
                    else if (gChosenActionByBattler[GetPartnerBattler(battler)] == B_ACTION_SWITCH)
                    {
                        RecordedBattle_ClearBattlerAction(GetPartnerBattler(battler), 2);
                    }
                    else if (gChosenActionByBattler[GetPartnerBattler(battler)] == B_ACTION_RUN)
                    {
                        RecordedBattle_ClearBattlerAction(GetPartnerBattler(battler), 1);
                    }
                    else if (gChosenActionByBattler[GetPartnerBattler(battler)] == B_ACTION_USE_MOVE
                             && (gProtectStructs[GetPartnerBattler(battler)].noValidMoves
                                || gBattleMons[GetPartnerBattler(battler)].volatiles.encoredMove))
                    {
                        RecordedBattle_ClearBattlerAction(GetPartnerBattler(battler), 1);
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_PALACE
                             && gChosenActionByBattler[GetPartnerBattler(battler)] == B_ACTION_USE_MOVE)
                    {
                        gRngValue = gBattlePalaceMoveSelectionRngValue;
                        RecordedBattle_ClearBattlerAction(GetPartnerBattler(battler), 1);
                    }
                    else
                    {
                        RecordedBattle_ClearBattlerAction(GetPartnerBattler(battler), 3);
                    }

                    gBattleStruct->gimmick.toActivate &= ~((1u << GetPartnerPosition(GetBattlerPosition(battler))));
                    BtlController_EmitEndBounceEffect(battler, B_COMM_TO_CONTROLLER);
                    MarkBattlerForControllerExec(battler);
                    return;
                case B_ACTION_DEBUG:
                    BtlController_EmitDebugMenu(battler, B_COMM_TO_CONTROLLER);
                    MarkBattlerForControllerExec(battler);
                    break;
                }

                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                    && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL)
                    && gBattleResources->bufferB[battler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[battler] = BattleScript_AskIfWantsToForfeitMatch;
                    gBattleCommunication[battler] = STATE_SELECTION_SCRIPT_MAY_RUN;
                    gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                    gBattleStruct->stateIdAfterSelScript[battler] = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else if (CanPlayerForfeitNormalTrainerBattle() && gBattleResources->bufferB[battler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[battler] = BattleScript_QuestionForfeitBattle;
                    gBattleCommunication[battler] = STATE_SELECTION_SCRIPT_MAY_RUN;
                    gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                    gBattleStruct->stateIdAfterSelScript[battler] = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                      && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                      && gBattleResources->bufferB[battler][1] == B_ACTION_RUN)
                {
                    BattleScriptExecute(BattleScript_PrintCantRunFromTrainer);
                    gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
                }
                else if ((IsRunningFromBattleImpossible(battler) != BATTLE_RUN_SUCCESS
                         && gBattleResources->bufferB[battler][1] == B_ACTION_RUN)
                         || (FlagGet(WE_FLAG_NO_RUNNING) == TRUE && gBattleResources->bufferB[battler][1] == B_ACTION_RUN))
                {
                    gSelectionBattleScripts[battler] = BattleScript_PrintCantEscapeFromBattle;
                    gBattleCommunication[battler] = STATE_SELECTION_SCRIPT;
                    gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                    gBattleStruct->stateIdAfterSelScript[battler] = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else
                {
                    gBattleCommunication[battler]++;
                }
            }
            break;
        case STATE_WAIT_ACTION_CASE_CHOSEN:
            if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
            {
                switch (gChosenActionByBattler[battler])
                {
                case B_ACTION_USE_MOVE:
                    switch (gBattleResources->bufferB[battler][1])
                    {
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                        gChosenActionByBattler[battler] = gBattleResources->bufferB[battler][1];
                        return;
                    case 15:
                        gChosenActionByBattler[battler] = B_ACTION_SWITCH;
                        UpdateBattlerPartyOrdersOnSwitch(battler);
                        return;
                    default:
                        RecordedBattle_CheckMovesetChanges(B_RECORD_MODE_PLAYBACK);
                        if ((gBattleResources->bufferB[battler][2] | (gBattleResources->bufferB[battler][3] << 8)) == 0xFFFF)
                        {
                            gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
                            RecordedBattle_ClearBattlerAction(battler, 1);
                        }
                        else if (TrySetCantSelectMoveBattleScript(battler))
                        {
                            RecordedBattle_ClearBattlerAction(battler, 1);
                            gBattleCommunication[battler] = STATE_SELECTION_SCRIPT;
                            gBattleStruct->battlerState[battler].selectionScriptFinished = FALSE;
                            gBattleResources->bufferB[battler][1] = B_ACTION_USE_MOVE;
                            gBattleStruct->stateIdAfterSelScript[battler] = STATE_WAIT_ACTION_CHOSEN;
                            return;
                        }
                        else
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_PALACE))
                            {
                                RecordedBattle_SetBattlerAction(battler, gBattleResources->bufferB[battler][2]);
                                RecordedBattle_SetBattlerAction(battler, gBattleResources->bufferB[battler][3]);
                            }

                            // Get the chosen move position (and thus the chosen move) and target from the returned buffer.
                            gBattleStruct->chosenMovePositions[battler] = gBattleResources->bufferB[battler][2] & ~RET_GIMMICK;
                            gChosenMoveByBattler[battler] = GetBattlerChosenMove(battler);
                            gBattleStruct->moveTarget[battler] = gBattleResources->bufferB[battler][3];
                            if (IsBattleMoveStatus(gChosenMoveByBattler[battler]) && GetBattlerAbility(battler) == ABILITY_MYCELIUM_MIGHT)
                                gProtectStructs[battler].myceliumMight = TRUE;
                            if (GetBattlerHoldEffect(battler) == HOLD_EFFECT_LAGGING_TAIL)
                                gProtectStructs[battler].laggingTail = TRUE;

                            // Check to see if any gimmicks need to be prepared.
                            if (gBattleResources->bufferB[battler][2] & RET_GIMMICK)
                                gBattleStruct->gimmick.toActivate |= 1u << battler;

                            // Max Move check
                            if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX || IsGimmickSelected(battler, GIMMICK_DYNAMAX))
                            {
                                gBattleStruct->dynamax.baseMoves[battler] = GetBattlerChosenMove(battler);
                            }
                            gBattleCommunication[battler]++;

                            if (gTestRunnerEnabled)
                            {
                                UNUSED enum Gimmick gimmick = GIMMICK_NONE;
                                if (gBattleResources->bufferB[battler][2] & RET_GIMMICK)
                                    gimmick = gBattleStruct->gimmick.usableGimmick[battler];
                                TestRunner_Battle_CheckChosenMove(battler, gChosenMoveByBattler[battler], gBattleStruct->moveTarget[battler], gimmick);
                            }
                        }
                        break;
                    }
                    break;
                case B_ACTION_USE_ITEM:
                    if ((gBattleResources->bufferB[battler][1] | (gBattleResources->bufferB[battler][2] << 8)) == 0)
                    {
                        gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    else
                    {
                        gLastUsedItem = (gBattleResources->bufferB[battler][1] | (gBattleResources->bufferB[battler][2] << 8));
                        if (GetItemPocket(gLastUsedItem) == POCKET_POKE_BALLS)
                            gBattleStruct->throwingPokeBall = TRUE;
                        gBattleCommunication[battler]++;
                    }
                    break;
                case B_ACTION_SWITCH:
                    if (gBattleResources->bufferB[battler][1] == PARTY_SIZE)
                    {
                        gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
                        RecordedBattle_ClearBattlerAction(battler, 1);
                    }
                    else
                    {
                        UpdateBattlerPartyOrdersOnSwitch(battler);
                        gBattleCommunication[battler]++;
                    }
                    break;
                case B_ACTION_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_SAFARI_WATCH_CAREFULLY:
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_SAFARI_BALL:
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_THROW_BALL:
                    gBattleStruct->throwingPokeBall = TRUE;
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_SAFARI_POKEBLOCK:
                    if (IS_FRLG)
                    {
                        gBattleCommunication[battler]++;
                    }
                    else
                    {
                        if ((gBattleResources->bufferB[battler][1] | (gBattleResources->bufferB[battler][2] << 8)) != 0)
                            gBattleCommunication[battler]++;
                        else
                            gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    break;
                case B_ACTION_SAFARI_GO_NEAR:
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_SAFARI_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_WALLY_THROW:
                    gBattleCommunication[battler]++;
                    break;
                case B_ACTION_DEBUG:
                    gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
                    break;
                }
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED_STANDBY:
            if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
            {
                if (AllAtActionConfirmed())
                    i = TRUE;
                else
                    i = FALSE;

                if (((gBattleTypeFlags & BATTLE_TYPE_MULTI) || !IsDoubleBattle())
                    || (position & BIT_FLANK) != B_FLANK_LEFT
                    || gAbsentBattlerFlags & 1u << GetBattlerAtPosition(GetPartnerPosition(position)))
                {
                    BtlController_EmitLinkStandbyMsg(battler, B_COMM_TO_CONTROLLER, LINK_STANDBY_MSG_STOP_BOUNCE, i);
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(battler, B_COMM_TO_CONTROLLER, LINK_STANDBY_STOP_BOUNCE_ONLY, i);
                }
                MarkBattlerForControllerExec(battler);
                gBattleCommunication[battler]++;
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED:
            if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
            {
                gBattleCommunication[ACTIONS_CONFIRMED_COUNT]++;
            }
            break;
        case STATE_SELECTION_SCRIPT:
            if (gBattleStruct->battlerState[battler].selectionScriptFinished)
            {
                gSelectionBattleScripts[battler] = NULL;
                gBattleCommunication[battler] = gBattleStruct->stateIdAfterSelScript[battler];
            }
            else
            {
                assertf(gSelectionBattleScripts[battler] != NULL, "selection script set to run, but pointer is null");
                gBattlerAttacker = battler;
                gBattlescriptCurrInstr = gSelectionBattleScripts[battler];
                if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gSelectionBattleScripts[battler] = gBattlescriptCurrInstr;
            }
            break;
        case STATE_WAIT_SET_BEFORE_ACTION:
            if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
            {
                gBattleCommunication[battler] = STATE_BEFORE_ACTION_CHOSEN;
            }
            break;
        case STATE_SELECTION_SCRIPT_MAY_RUN:
            if (gBattleStruct->battlerState[battler].selectionScriptFinished)
            {
                gSelectionBattleScripts[battler] = NULL;
                if (gBattleResources->bufferB[battler][1] == B_ACTION_NOTHING_FAINTED)
                {
                    gHitMarker |= HITMARKER_RUN;
                    gChosenActionByBattler[battler] = B_ACTION_RUN;
                    gBattleCommunication[battler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    RecordedBattle_ClearBattlerAction(battler, 1);
                    gBattleCommunication[battler] = gBattleStruct->stateIdAfterSelScript[battler];
                }
            }
            else
            {
                assertf(gSelectionBattleScripts[battler] != NULL, "selection script set to run, but pointer is null");
                gBattlerAttacker = battler;
                gBattlescriptCurrInstr = gSelectionBattleScripts[battler];
                if (!IsBattleControllerActiveOrPendingSyncAnywhere(battler))
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                gSelectionBattleScripts[battler] = gBattlescriptCurrInstr;
            }
            break;
        }
    }

    // Check if everyone chose actions.
    if (gBattleCommunication[ACTIONS_CONFIRMED_COUNT] == gBattlersCount)
    {
        RecordedBattle_CheckMovesetChanges(B_RECORD_MODE_RECORDING);

        if (WILD_DOUBLE_BATTLE
            && gBattleStruct->throwingPokeBall
            && gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)] != B_ACTION_NOTHING_FAINTED)
        {
            // if we choose to throw a ball with our second mon, skip the action of the first
            // (if we have chosen throw ball with first, second's is already skipped)
            // if throwing a ball in a wild battle with an in-game partner, skip partner's turn when throwing a ball
            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)] = B_ACTION_NOTHING_FAINTED;
            else
                gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] = B_ACTION_NOTHING_FAINTED;
        }

        gBattleMainFunc = SetActionsAndBattlersTurnOrder;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                if (gChosenActionByBattler[battler] == B_ACTION_SWITCH)
                    SwitchPartyOrderInGameMulti(battler, gBattleStruct->monToSwitchIntoId[battler]);
            }
        }
    }
}

static bool8 AllAtActionConfirmed(void)
{
    enum BattlerId i;
    s32 count;

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

static void UpdateBattlerPartyOrdersOnSwitch(enum BattlerId battler)
{
    gBattleStruct->monToSwitchIntoId[battler] = gBattleResources->bufferB[battler][1];
    RecordedBattle_SetBattlerAction(battler, gBattleResources->bufferB[battler][1]);

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        *(battler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= 0xF;
        *(battler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[battler][2] & 0xF0);
        *(battler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 1) = gBattleResources->bufferB[battler][3];

        *((GetPartnerBattler(battler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= (0xF0);
        *((GetPartnerBattler(battler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[battler][2] & 0xF0) >> 4;
        *((GetPartnerBattler(battler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 2) = gBattleResources->bufferB[battler][3];
    }
}

void SwapTurnOrder(u8 id1, u8 id2)
{
    u32 temp;

    SWAP(gActionsByTurnOrder[id1], gActionsByTurnOrder[id2], temp);
    SWAP(gBattlerByTurnOrder[id1], gBattlerByTurnOrder[id2], temp);
}

// For AI, so it doesn't 'cheat' by knowing player's ability
u32 GetBattlerTotalSpeedStat(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect)
{
    u32 speed = gBattleMons[battler].speed;

    // stat stages
    speed *= gStatStageRatios[gBattleMons[battler].statStages[STAT_SPEED]][0];
    speed /= gStatStageRatios[gBattleMons[battler].statStages[STAT_SPEED]][1];

    u32 weather = GetWeather();
    // weather abilities
    if (ability == ABILITY_SWIFT_SWIM       && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA && weather  & B_WEATHER_RAIN)
        speed *= 2;
    else if (ability == ABILITY_CHLOROPHYLL && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA && weather  & B_WEATHER_SUN)
        speed *= 2;
    else if (ability == ABILITY_SAND_RUSH   && weather & B_WEATHER_SANDSTORM)
        speed *= 2;
    else if (ability == ABILITY_SLUSH_RUSH  && weather & B_WEATHER_ICY_ANY)
        speed *= 2;

    // other abilities
    if (ability == ABILITY_QUICK_FEET && gBattleMons[battler].status1 & STATUS1_ANY)
        speed = (speed * 150) / 100;
    else if (ability == ABILITY_SURGE_SURFER && gFieldTimers.terrain == B_TERRAIN_ELECTRIC)
        speed *= 2;
    else if (ability == ABILITY_SLOW_START && gBattleMons[battler].volatiles.slowStartTimer != 0)
        speed /= 2;
    else if ((ability == ABILITY_PROTOSYNTHESIS && !gBattleMons[battler].volatiles.transformed && weather & B_WEATHER_SUN) || gBattleMons[battler].volatiles.boosterEnergyActivated)
        speed = (GetParadoxBoostedStatId(battler) == STAT_SPEED) ? (speed * 150) / 100 : speed;
    else if (ability == ABILITY_QUARK_DRIVE && !(gBattleMons[battler].volatiles.transformed) && (gFieldTimers.terrain == B_TERRAIN_ELECTRIC || gBattleMons[battler].volatiles.boosterEnergyActivated))
        speed = (GetParadoxBoostedStatId(battler) == STAT_SPEED) ? (speed * 150) / 100 : speed;
    else if (ability == ABILITY_UNBURDEN && gBattleMons[battler].volatiles.unburdenActive)
        speed *= 2;

    // player's badge boost
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_FRONTIER))
        && ShouldGetStatBadgeBoost(B_FLAG_BADGE_BOOST_SPEED, battler)
        && IsOnPlayerSide(battler))
    {
        speed = uq4_12_multiply_by_int_half_down(GetBadgeBoostModifier(), speed);
    }

    // item effects
    if (holdEffect == HOLD_EFFECT_MACHO_BRACE || holdEffect == HOLD_EFFECT_POWER_ITEM)
        speed /= 2;
    else if (holdEffect == HOLD_EFFECT_IRON_BALL)
        speed /= 2;
    else if (holdEffect == HOLD_EFFECT_CHOICE_SCARF && GetActiveGimmick(battler) != GIMMICK_DYNAMAX)
        speed = (speed * 150) / 100;
    else if (holdEffect == HOLD_EFFECT_QUICK_POWDER && gBattleMons[battler].species == SPECIES_DITTO && !(gBattleMons[battler].volatiles.transformed))
        speed *= 2;

    // various effects
    if (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
        speed *= 2;

    // paralysis drop
    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS && ability != ABILITY_QUICK_FEET)
        speed /= GetConfig(B_PARALYSIS_SPEED) >= GEN_7 ? 2 : 4;

    if (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SWAMP)
        speed /= 4;

    return speed;
}

s32 GetChosenMovePriority(enum BattlerId battler, enum Ability ability)
{
    enum Move move;

    gProtectStructs[battler].pranksterElevated = FALSE;
    if (gProtectStructs[battler].noValidMoves)
        move = MOVE_STRUGGLE;
    else if (gBattleMons[battler].volatiles.encoredMove != MOVE_NONE && GetConfig(B_ENCORE_PRIORITY) >= GEN_CHAMPIONS)
        move = gBattleMons[battler].volatiles.encoredMove;
    else
        move = GetBattlerChosenMove(battler);

    return GetBattleMovePriority(battler, ability, move);
}

s32 GetBattleMovePriority(enum BattlerId battler, enum Ability ability, enum Move move)
{
    s32 priority = 0;

    if (GetActiveGimmick(battler) == GIMMICK_Z_MOVE && !IsBattleMoveStatus(move))
        move = GetUsableZMove(battler, move);

    priority = GetMovePriority(move);

    // Max Guard check
    if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS)
        return GetMovePriority(MOVE_MAX_GUARD);

    if (gProtectStructs[battler].quash)
    {
        priority = -8;
    }
    else if (ability == ABILITY_GALE_WINGS
          && (GetConfig(B_GALE_WINGS) < GEN_7 || IsBattlerAtMaxHp(battler))
          && GetMoveType(move) == TYPE_FLYING)
    {
        priority++;
    }
    else if (IsBattleMoveStatus(move) && IsAbilityAndRecord(battler, ability, ABILITY_PRANKSTER))
    {
        gProtectStructs[battler].pranksterElevated = 1;
        priority++;
    }
    else if (GetMoveEffect(move) == EFFECT_GRASSY_GLIDE
          && IsGrassyTerrainAffected(battler, ability, GetBattlerHoldEffect(battler), gFieldTimers.terrain)
          && GetActiveGimmick(gBattlerAttacker) != GIMMICK_DYNAMAX && !IsGimmickSelected(battler, GIMMICK_DYNAMAX))
    {
        priority++;
    }
    else if (ability == ABILITY_TRIAGE && IsHealingMove(move))
    {
        priority += 3;
    }

    return priority;
}

s32 GetWhichBattlerFasterArgs(struct BattleCalcValues *calcValues, bool32 ignoreChosenMoves, u32 speedBattler1, u32 speedBattler2, s32 priority1, s32 priority2)
{
    u32 strikesFirst = 0;

    if (priority1 == priority2)
    {
        // Quick Claw / Quick Draw / Custap Berry - always first
        // Stall / Mycelium Might / Lagging Tail / Full Incense - always last
        // If both battlers are affected by one of these effects, order is determined by Speed.
        bool32 battler1HasQuickEffect = gProtectStructs[calcValues->battlerAtk].quickDraw || gProtectStructs[calcValues->battlerAtk].usedCustapBerry;
        bool32 battler2HasQuickEffect = gProtectStructs[calcValues->battlerDef].quickDraw || gProtectStructs[calcValues->battlerDef].usedCustapBerry;
        bool32 battler1HasStallingAbility = calcValues->abilities[calcValues->battlerAtk] == ABILITY_STALL || gProtectStructs[calcValues->battlerAtk].myceliumMight;
        bool32 battler2HasStallingAbility = calcValues->abilities[calcValues->battlerDef] == ABILITY_STALL || gProtectStructs[calcValues->battlerDef].myceliumMight;
        bool32 battler1HasSlowEffect = battler1HasStallingAbility || gProtectStructs[calcValues->battlerAtk].laggingTail;
        bool32 battler2HasSlowEffect = battler2HasStallingAbility || gProtectStructs[calcValues->battlerDef].laggingTail;

        if (battler1HasQuickEffect && !battler2HasQuickEffect)
            strikesFirst = 1;
        else if (battler2HasQuickEffect && !battler1HasQuickEffect)
            strikesFirst = -1;
        else if (battler1HasSlowEffect && !battler2HasSlowEffect)
            strikesFirst = -1;
        else if (battler2HasSlowEffect && !battler1HasSlowEffect)
            strikesFirst = 1;
        else
        {
            if (speedBattler1 == speedBattler2)
            {
                // same speeds, same priorities
                strikesFirst = 0;
            }
            else if (speedBattler1 < speedBattler2)
            {
                // battler2 has more speed
                if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
                    strikesFirst = 1;
                else
                    strikesFirst = -1;
            }
            else
            {
                // battler1 has more speed
                if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
                    strikesFirst = -1;
                else
                    strikesFirst = 1;
            }
        }
    }
    else if (priority1 < priority2)
    {
        strikesFirst = -1; // battler2's move has greater priority
    }
    else
    {
        strikesFirst = 1; // battler1's move has greater priority
    }
    return strikesFirst;
}

s32 GetWhichBattlerFasterOrTies(struct BattleCalcValues *calcValues, bool32 ignoreChosenMoves)
{
    s32 priority1 = 0, priority2 = 0;
    u32 speedBattler1 = GetBattlerTotalSpeedStat(calcValues->battlerAtk, calcValues->abilities[calcValues->battlerAtk], calcValues->holdEffects[calcValues->battlerAtk]);
    u32 speedBattler2 = GetBattlerTotalSpeedStat(calcValues->battlerDef, calcValues->abilities[calcValues->battlerDef], calcValues->holdEffects[calcValues->battlerDef]);

    if (!ignoreChosenMoves)
    {
        if (gChosenActionByBattler[calcValues->battlerAtk] == B_ACTION_USE_MOVE)
            priority1 = GetChosenMovePriority(calcValues->battlerAtk, calcValues->abilities[calcValues->battlerAtk]);
        if (gChosenActionByBattler[calcValues->battlerDef] == B_ACTION_USE_MOVE)
            priority2 = GetChosenMovePriority(calcValues->battlerDef, calcValues->abilities[calcValues->battlerDef]);
    }

    return GetWhichBattlerFasterArgs(
        calcValues,
        ignoreChosenMoves,
        speedBattler1,
        speedBattler2,
        priority1,
        priority2);
}

// 24 == MAX_BATTLERS_COUNT!.
// These are the possible orders if all the battlers speed tie.
// An order is chosen at the start of the turn.
static const u8 sBattlerOrders[24][4] =
{
    { 0, 1, 2, 3 },
    { 0, 1, 3, 2 },
    { 0, 2, 1, 3 },
    { 0, 2, 3, 1 },
    { 0, 3, 1, 2 },
    { 0, 3, 2, 1 },
    { 1, 0, 2, 3 },
    { 1, 0, 3, 2 },
    { 1, 2, 0, 3 },
    { 1, 2, 3, 0 },
    { 1, 3, 0, 2 },
    { 1, 3, 2, 0 },
    { 2, 0, 1, 3 },
    { 2, 0, 3, 1 },
    { 2, 1, 0, 3 },
    { 2, 1, 3, 0 },
    { 2, 3, 0, 1 },
    { 2, 3, 1, 0 },
    { 3, 0, 1, 2 },
    { 3, 0, 2, 1 },
    { 3, 1, 0, 2 },
    { 3, 1, 2, 0 },
    { 3, 2, 0, 1 },
    { 3, 2, 1, 0 },
};

s32 GetWhichBattlerFaster(struct BattleCalcValues *calcValues, bool32 ignoreChosenMoves)
{
    s32 strikesFirst = GetWhichBattlerFasterOrTies(calcValues, ignoreChosenMoves);
    if (strikesFirst == 0)
    {
        s32 order1 = sBattlerOrders[gBattleStruct->speedTieBreaks][calcValues->battlerAtk];
        s32 order2 = sBattlerOrders[gBattleStruct->speedTieBreaks][calcValues->battlerDef];
        if (order1 < order2)
            strikesFirst = 1;
        else
            strikesFirst = -1;
    }
    return strikesFirst;
}

static void SetActionsAndBattlersTurnOrder(void)
{
    s32 turnOrderId = 0;
    enum BattlerId battler, battler2;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
    {
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[battler];
            gBattlerByTurnOrder[turnOrderId] = battler;
            turnOrderId++;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (gChosenActionByBattler[battler] == B_ACTION_RUN)
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
                battler = B_BATTLER_0;
                turnOrderId = 5;
            }
            if (gChosenActionByBattler[2] == B_ACTION_RUN)
            {
                battler = B_BATTLER_2;
                turnOrderId = 5;
            }
        }

        if (turnOrderId == 5) // One of battlers wants to run.
        {
            gActionsByTurnOrder[0] = gChosenActionByBattler[battler];
            gBattlerByTurnOrder[0] = battler;
            turnOrderId = 1;
            for (battler2 = 0; battler2 < gBattlersCount; battler2++)
            {
                if (battler2 != battler)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[battler2];
                    gBattlerByTurnOrder[turnOrderId] = battler2;
                    turnOrderId++;
                }
            }
        }
        else
        {
            u32 quickClawRandom[MAX_BATTLERS_COUNT] = {0};
            u32 quickDrawRandom[MAX_BATTLERS_COUNT] = {0};

            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (gChosenActionByBattler[battler] == B_ACTION_USE_ITEM
                  || gChosenActionByBattler[battler] == B_ACTION_SWITCH
                  || gChosenActionByBattler[battler] == B_ACTION_THROW_BALL)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[battler];
                    gBattlerByTurnOrder[turnOrderId] = battler;
                    turnOrderId++;
                }
            }
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (gChosenActionByBattler[battler] != B_ACTION_USE_ITEM
                  && gChosenActionByBattler[battler] != B_ACTION_SWITCH
                  && gChosenActionByBattler[battler] != B_ACTION_THROW_BALL)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[battler];
                    gBattlerByTurnOrder[turnOrderId] = battler;
                    quickClawRandom[battler] = RandomPercentage(RNG_QUICK_CLAW, GetBattlerHoldEffectParam(battler));
                    quickDrawRandom[battler] = RandomPercentage(RNG_QUICK_DRAW, 30);
                    turnOrderId++;
                }
            }
            struct BattleCalcValues calcValues = {0};
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                calcValues.abilities[battler] = GetBattlerAbility(battler);
                calcValues.holdEffects[battler] = GetBattlerHoldEffect(battler);
            }
            for (battler = 0; battler < gBattlersCount - 1; battler++)
            {
                for (battler2 = battler + 1; battler2 < gBattlersCount; battler2++)
                {
                    calcValues.battlerAtk = gBattlerByTurnOrder[battler];
                    calcValues.battlerDef = gBattlerByTurnOrder[battler2];
                    TryChangingTurnOrderEffects(&calcValues, quickClawRandom, quickDrawRandom);
                    if (gActionsByTurnOrder[battler] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[battler2] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[battler] != B_ACTION_SWITCH
                        && gActionsByTurnOrder[battler2] != B_ACTION_SWITCH
                        && gActionsByTurnOrder[battler] != B_ACTION_THROW_BALL
                        && gActionsByTurnOrder[battler2] != B_ACTION_THROW_BALL)
                    {
                        if (GetWhichBattlerFaster(&calcValues, FALSE) == -1)
                            SwapTurnOrder(battler, battler2);
                    }
                }
            }
        }
    }
    gBattleMainFunc = CheckChangingTurnOrderEffects;
    gBattleScripting.battler = 0;
}

static void TurnValuesCleanUp(bool32 endTurn)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (endTurn)
        {
            gProtectStructs[i].protected = PROTECT_NONE;
            gProtectStructs[i].quash = FALSE;
            gProtectStructs[i].usedCustapBerry = FALSE;
            gProtectStructs[i].quickDraw = FALSE;
        }
        else
        {
            memset(&gProtectStructs[i], 0, sizeof(struct ProtectStruct));

            if (gBattleStruct->battlerState[i].isFirstTurn)
                gBattleStruct->battlerState[i].isFirstTurn--;

            if (gBattleMons[i].volatiles.rechargeTimer)
                gBattleMons[i].volatiles.rechargeTimer--;

            gBattleStruct->battlerState[i].canPickupItem = FALSE;
            gBattleStruct->battlerState[i].wasAboveHalfHp = FALSE;
        }

        if (gBattleMons[i].volatiles.substituteHP == 0)
            gBattleMons[i].volatiles.substitute = FALSE;

        if (gBattleMons[i].volatiles.semiInvulnerable != STATE_COMMANDER)
            gBattleStruct->battlerState[i].commandingDondozo = FALSE;

        gSpecialStatuses[i].parentalBondState = PARENTAL_BOND_OFF;
        gBattleStruct->battlerState[i].usedEjectItem = FALSE;
        gProtectStructs[i].lashOutAffected = FALSE;
        gBattleMons[i].volatiles.endured = FALSE;
    }

    gSideTimers[B_SIDE_PLAYER].followmeTimer = 0;
    gSideTimers[B_SIDE_OPPONENT].followmeTimer = 0;

    ClearPursuitValues();
    ClearDamageCalcResults();
}

static void PopulateArrayWithBattlers(enum BattlerId *battlers)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        battlers[i] = i;
}

static bool32 TryTrainerSlideGimmick(enum BattlerId battler)
{
    bool32 doSlide = TRUE;
    if (ShouldDoTrainerSlide(battler, gGimmicksInfo[gBattleStruct->gimmick.usableGimmick[battler]].attackerSlideType))
        gBattleScripting.battler = battler;
    else if (ShouldDoTrainerSlide(GetBattlerLeftFoe(battler), gGimmicksInfo[gBattleStruct->gimmick.usableGimmick[battler]].opponentSlideType))
        gBattleScripting.battler = GetBattlerLeftFoe(battler);
    else if (ShouldDoTrainerSlide(GetBattlerRightFoe(battler), gGimmicksInfo[gBattleStruct->gimmick.usableGimmick[battler]].opponentSlideType))
        gBattleScripting.battler = GetBattlerRightFoe(battler);
    else
        doSlide = FALSE;
    if (doSlide)
    {
        BattleScriptPushCursorAndCallback(BattleScript_TrainerSlideMsg);
        return TRUE;
    }
    return FALSE;
}

static bool32 TryActivateGimmick(enum BattlerId battler)
{
    if ((gBattleStruct->gimmick.toActivate & (1u << battler)) && !(gProtectStructs[battler].noValidMoves))
    {
        if (gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_Z_MOVE && TryTrainerSlideGimmick(battler))
        {
            return TRUE;
        }
        gBattlerAttacker = gBattleScripting.battler = battler;
        gBattleStruct->gimmick.toActivate &= ~(1u << battler);
        if (gGimmicksInfo[gBattleStruct->gimmick.usableGimmick[battler]].ActivateGimmick != NULL)
        {
            gGimmicksInfo[gBattleStruct->gimmick.usableGimmick[battler]].ActivateGimmick(battler);
            return TRUE;
        }
    }
    return FALSE;
}

static bool32 TryDoGimmicksBeforeMoves(void)
{
    if (!(gHitMarker & HITMARKER_RUN) && gBattleStruct->gimmick.toActivate)
    {
        enum BattlerId battlers[MAX_BATTLERS_COUNT];

        PopulateArrayWithBattlers(battlers);
        SortBattlersBySpeed(battlers, FALSE);
        for (enum BattlerId i = 0; i < gBattlersCount; i++)
        {
            // Search through each battler and activate their gimmick if they have one prepared.
            if (TryActivateGimmick(battlers[i]))
                return TRUE;
        }
    }

    if (GetConfig(B_MEGA_EVO_TURN_ORDER) >= GEN_7)
        TryChangeTurnOrder(); // This will just do nothing if no mon has mega evolved.
    return FALSE;
}

const u8 *GetChargingSetUpScript(enum BattleMoveEffects moveEffect, bool32 inMiddleOfTurn)
{
    switch (moveEffect)
    {
    case EFFECT_FOCUS_PUNCH:
        return inMiddleOfTurn ? BattleScript_FocusPunchSetUpEncored : BattleScript_FocusPunchSetUp;
    case EFFECT_BEAK_BLAST:
        return inMiddleOfTurn ? BattleScript_BeakBlastSetUpEncored : BattleScript_BeakBlastSetUp;
    case EFFECT_SHELL_TRAP:
        return inMiddleOfTurn ? BattleScript_ShellTrapSetUpEncored : BattleScript_ShellTrapSetUp;
    default:
        return NULL;
    }
}

static bool32 TryDoMoveEffectsBeforeMoves(void)
{
    if (!(gHitMarker & HITMARKER_RUN))
    {
        enum BattlerId battlers[MAX_BATTLERS_COUNT];

        PopulateArrayWithBattlers(battlers);
        SortBattlersBySpeed(battlers, FALSE);
        for (u32 i = 0; i < gBattlersCount; i++)
        {
            enum BattlerId battler = battlers[i];
            if (!gBattleStruct->battlerState[battler].focusPunchBattlers)
            {
                gBattlerAttacker = battler;
                gBattleScripting.battler = battler;
                const u8 *script = GetChargingSetUpScript(GetMoveEffect(gChosenMoveByBattler[gBattlerAttacker]), FALSE);
                if (script)
                {
                    gBattleStruct->battlerState[battler].focusPunchBattlers = TRUE;
                    BattleScriptExecute(script);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

// In gen7, priority and speed are recalculated during the turn in which a Pokémon mega evolves
static void TryChangeTurnOrder(void)
{
    enum BattlerId i, j;

    struct BattleCalcValues calcValues = {0};
    for (i = 0; i < gBattlersCount; i++)
    {
        calcValues.abilities[i] = GetBattlerAbility(i);
        calcValues.holdEffects[i] = GetBattlerHoldEffect(i);
    }
    for (i = gCurrentTurnActionNumber; i < gBattlersCount - 1; i++)
    {
        for (j = i + 1; j < gBattlersCount; j++)
        {
            calcValues.battlerAtk = gBattlerByTurnOrder[i];
            calcValues.battlerDef = gBattlerByTurnOrder[j];

            if (gActionsByTurnOrder[i] == B_ACTION_USE_MOVE
                && gActionsByTurnOrder[j] == B_ACTION_USE_MOVE)
            {
                if (GetWhichBattlerFaster(&calcValues, FALSE) == -1)
                    SwapTurnOrder(i, j);
            }
        }
    }
}

static void TryChangingTurnOrderEffects(struct BattleCalcValues *calcValues, u32 *quickClawRandom, u32 *quickDrawRandom)
{
    enum BattlerId battler1 = calcValues->battlerAtk;
    enum BattlerId battler2 = calcValues->battlerDef;
    enum Ability ability1 = calcValues->abilities[calcValues->battlerAtk];
    enum Ability ability2 = calcValues->abilities[calcValues->battlerDef];
    enum HoldEffect holdEffectBattler1 = calcValues->holdEffects[calcValues->battlerAtk];
    enum HoldEffect holdEffectBattler2 = calcValues->holdEffects[calcValues->battlerDef];

    // Battler 1
    // Quick Draw
    if (ability1 == ABILITY_QUICK_DRAW && !IsBattleMoveStatus(gChosenMoveByBattler[battler1]) && quickDrawRandom[battler1])
        gProtectStructs[battler1].quickDraw = TRUE;
    // Quick Claw and Custap Berry
    if (!gProtectStructs[battler1].quickDraw
     && ((holdEffectBattler1 == HOLD_EFFECT_QUICK_CLAW && quickClawRandom[battler1])
     || (holdEffectBattler1 == HOLD_EFFECT_CUSTAP_BERRY && HasEnoughHpToEatBerry(battler1, ability1, 4, gBattleMons[battler1].item))))
        gProtectStructs[battler1].usedCustapBerry = TRUE;

    // Battler 2
    // Quick Draw
    if (ability2 == ABILITY_QUICK_DRAW && !IsBattleMoveStatus(gChosenMoveByBattler[battler2]) && quickDrawRandom[battler2])
        gProtectStructs[battler2].quickDraw = TRUE;
    // Quick Claw and Custap Berry
    if (!gProtectStructs[battler2].quickDraw
     && ((holdEffectBattler2 == HOLD_EFFECT_QUICK_CLAW && quickClawRandom[battler2])
     || (holdEffectBattler2 == HOLD_EFFECT_CUSTAP_BERRY && HasEnoughHpToEatBerry(battler2, ability2, 4, gBattleMons[battler2].item))))
        gProtectStructs[battler2].usedCustapBerry = TRUE;
}

static void CheckChangingTurnOrderEffects(void)
{
    enum BattlerId i, battler;

    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleScripting.battler < gBattlersCount)
        {
            battler = gBattlerAttacker = gBattleScripting.battler++;

            if (gChosenActionByBattler[battler] == B_ACTION_USE_MOVE
             && GetMoveEffect(gChosenMoveByBattler[battler]) != EFFECT_FOCUS_PUNCH   // quick claw message doesn't need to activate here
             && (gProtectStructs[battler].usedCustapBerry || gProtectStructs[battler].quickDraw)
             && !(gBattleMons[battler].status1 & STATUS1_SLEEP)
             && !(gBattleMons[gBattlerAttacker].volatiles.truantCounter)
             && !(gProtectStructs[battler].noValidMoves))
            {
                if (gProtectStructs[battler].usedCustapBerry)
                {
                    gLastUsedItem = gBattleMons[battler].item;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    if (GetBattlerHoldEffect(battler) == HOLD_EFFECT_CUSTAP_BERRY)
                    {
                        // don't record berry since its gone now
                        BattleScriptExecute(BattleScript_CustapBerryActivation);
                    }
                    else
                    {
                        RecordItemEffectBattle(battler, GetBattlerHoldEffect(battler));
                        BattleScriptExecute(BattleScript_QuickClawActivation);
                    }
                }
                else if (gProtectStructs[battler].quickDraw)
                {
                    gBattlerAbility = battler;
                    gLastUsedAbility = gBattleMons[battler].ability;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    RecordAbilityBattle(battler, gLastUsedAbility);
                    BattleScriptExecute(BattleScript_QuickDrawActivation);
                }
                return;
            }
        }
    }

    // Prevents trainer slides triggering a turn late if another slide took priority on the previous turn
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        for (enum TrainerSlideType slideId = 0; slideId < TRAINER_SLIDE_COUNT; slideId++)
        {
            MarkInitializedTrainerSlidesAsPlayed(i, slideId);
        }
    }

    gCurrentTurnActionNumber = 0;
    gCurrentActionFuncId = gActionsByTurnOrder[0];
    gBattleStruct->dynamicMoveType = 0;
    gBattleStruct->effectsBeforeUsingMoveDone = FALSE;
    for (i = 0; i < gBattlersCount; i++)
    {
        gBattleStruct->battlerState[i].focusPunchBattlers = FALSE;
        gBattleStruct->battlerState[i].ateBoost = FALSE;
        gSpecialStatuses[i].gemBoost = FALSE;
        if (!MoveHasAdditionalEffectSelf(gChosenMoveByBattler[i], MOVE_EFFECT_RAGE))
            gBattleMons[i].volatiles.rage = FALSE;
    }

    gBattleMainFunc = RunTurnActionsFunctions;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

static void RunTurnActionsFunctions(void)
{
    if (gBattleOutcome != 0)
        gCurrentActionFuncId = B_ACTION_FINISHED;

    // Mega Evolve / Focus Punch-like moves after switching, items, running, but before using a move.
    if (gCurrentActionFuncId == B_ACTION_USE_MOVE && !gBattleStruct->effectsBeforeUsingMoveDone)
    {
        if (!IsPursuitTargetSet())
        {
            if (TryDoGimmicksBeforeMoves())
                return;
            else if (TryDoMoveEffectsBeforeMoves())
                return;
            gBattleStruct->effectsBeforeUsingMoveDone = TRUE;
        }
        else
        {
            if (TryActivateGimmick(gBattlerByTurnOrder[gCurrentTurnActionNumber]))
                return;
        }
    }

    // Z-move slides appear right before move instead of at the beginning of turn like other gimmicks
    if (GetActiveGimmick(gBattlerByTurnOrder[gCurrentTurnActionNumber]) == GIMMICK_Z_MOVE && TryTrainerSlideGimmick(gBattlerByTurnOrder[gCurrentTurnActionNumber]))
        return;

    sTurnActionsFuncsTable[gCurrentActionFuncId]();

    if (gCurrentTurnActionNumber >= gBattlersCount) // everyone did their actions, turn finished
        gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
}

static void HandleEndTurn_BattleWon(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gSpecialVar_Result = gBattleOutcome;
        gBattleTextBuff1[0] = gBattleOutcome;
        gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
        gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_EREADER_TRAINER))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_FrontierTrainerBattleWon;

        if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
            PlayBGM(MUS_VICTORY_GYM_LEADER);
        else
            PlayBGM(MUS_VICTORY_TRAINER);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_LocalTrainerBattleWon;

        switch (GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA))
        {
        case TRAINER_CLASS_ELITE_FOUR:
        case TRAINER_CLASS_CHAMPION:
            PlayBGM(MUS_VICTORY_LEAGUE);
            break;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_ADMIN:
        case TRAINER_CLASS_MAGMA_LEADER:
            PlayBGM(MUS_VICTORY_AQUA_MAGMA);
            break;
        case TRAINER_CLASS_LEADER:
            PlayBGM(MUS_VICTORY_GYM_LEADER);
            break;
        default:
            PlayBGM(MUS_VICTORY_TRAINER);
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

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        {
            if (gBattleOutcome & B_OUTCOME_LINK_BATTLE_RAN)
            {
                gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeitedLinkBattle;
                gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
                gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
            }
            else
            {
                gBattlescriptCurrInstr = BattleScript_FrontierLinkBattleLost;
                gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
            }
        }
        else
        {
            gBattleTextBuff1[0] = gBattleOutcome;
            gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
            gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && TRAINER_BATTLE_PARAM.earlyRival)
        {
            if (TRAINER_BATTLE_PARAM.earlyRival)
                gBattleCommunication[MULTISTRING_CHOOSER] = 1; // Dont do white out text
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 2; // Do white out text
            gBattlerAttacker = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        }
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
    else if (CanPlayerForfeitNormalTrainerBattle())
    {
        gBattlescriptCurrInstr = BattleScript_ForfeitBattleGaveMoney;
        gBattleOutcome = B_OUTCOME_FORFEITED;
    }
    else
    {
        switch (gProtectStructs[gBattlerAttacker].fleeType)
        {
        default:
            gBattlescriptCurrInstr = BattleScript_GotAwaySafely;
            break;
        case FLEE_ITEM:
            gBattlescriptCurrInstr = BattleScript_SmokeBallEscape;
            break;
        case FLEE_ABILITY:
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
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_CATCH_TUTORIAL
                                  | BATTLE_TYPE_FRONTIER))
            && !(gBattleTypeFlags & BATTLE_TYPE_GHOST && IsGhostBattleWithoutScope()))
        {
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                if (IsOnPlayerSide(battler))
                {
                    if (gBattleResults.playerMon1Species == SPECIES_NONE)
                    {
                        gBattleResults.playerMon1Species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
                        GetMonData(GetBattlerMon(battler), MON_DATA_NICKNAME, gBattleResults.playerMon1Name);
                    }
                    else
                    {
                        gBattleResults.playerMon2Species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
                        GetMonData(GetBattlerMon(battler), MON_DATA_NICKNAME, gBattleResults.playerMon2Name);
                    }
                }
            }
            TryPutPokemonTodayOnAir();
        }

        if (gIsFishingEncounter && IsMonShiny(&gParties[B_TRAINER_OPPONENT_A][0]))
            gChainFishingDexNavStreak = 0;

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_TRAINER_HILL
                                  | BATTLE_TYPE_FRONTIER)))
        {
            for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
            {
                struct Pokemon *party = GetTrainerParty(trainer);

                if ((trainer & BIT_SIDE) == B_SIDE_PLAYER && !B_PARTNER_MONS_MARKED_SEEN)
                    continue;

                for (u32 partySlot = 0; partySlot < PARTY_SIZE; partySlot++)
                {
                    if (gBattleStruct->partyState[trainer][partySlot].sentOut)
                        HandleSetPokedexFlagFromMon(&party[partySlot], FLAG_SET_SEEN);
                }
            }
        }

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_TRAINER
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_CATCH_TUTORIAL))
            && gBattleResults.shinyWildMon)
        {
            TryPutBreakingNewsOnAir();
        }

        BeginFastPaletteFade(3);
        FadeOutMapMusic(5);
        TryRestoreHeldItems();

        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            bool32 changedForm = TryRevertPartyMonFormChange(i);

            // Recalculate the stats of every party member before the end
            if (!changedForm && B_RECALCULATE_STATS >= GEN_5)
                CalculateMonStats(&gParties[B_TRAINER_PLAYER][i]);
        }
        RecordedBattle_SetPlaybackFinished();
        if (gTestRunnerEnabled)
            TestRunner_Battle_AfterLastTurn();

        // Set Battle Controllers to BATTLE_CONTROLLER_NONE
        for (enum BattlerId i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            gBattlerBattleController[i] = BATTLE_CONTROLLER_NONE;
        }

        gBattleMainFunc = FreeResetData_ReturnToOvOrDoEvolutions;
        gCB2_AfterEvolution = BattleMainCB2;
    }
    else
    {
        RunBattleScriptCommands();
    }
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gPaletteFade.active)
    {
        memset(&gBattleMons, 0, sizeof(struct BattlePokemon) * MAX_BATTLERS_COUNT);
        gIsFishingEncounter = FALSE;
        gIsSurfingEncounter = FALSE;
        if (gDexNavSpecies && (gBattleOutcome == B_OUTCOME_WON || gBattleOutcome == B_OUTCOME_CAUGHT))
        {
            IncrementDexNavChain();
            TryIncrementSpeciesSearchLevel();
        }
        else
            gSaveBlock3Ptr->dexNavChain = 0;

        ClearCurrentTrainerWantRematchVsSeeker();
        gDexNavSpecies = SPECIES_NONE;
        ResetSpriteData();
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_CATCH_TUTORIAL))
            && (B_EVOLUTION_AFTER_WHITEOUT >= GEN_6
                || gBattleOutcome == B_OUTCOME_WON
                || gBattleOutcome == B_OUTCOME_CAUGHT))
        {
            gBattleMainFunc = TryEvolvePokemon;
        }
        else
        {
            gBattleMainFunc = ReturnFromBattleToOverworld;
            return;
        }
    }

    FreeAllWindowBuffers();
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        // To account for Battle Factory and Slateport Battle Tent, enemy parties are zeroed out in the facilitites respective src/xxx.c files
        // The ZeroEnemyPartyMons() call happens in SaveXXXChallenge function (eg. SaveFactoryChallenge)
        if (!(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_ROAMER)))
        {
            ZeroEnemyPartyMons();
        }
        ResetDynamicAiFunctions();
        FreeMonSpritesGfx();
        FreeBattleResources();
        FreeBattleSpritesData();
    }
}

static void TryEvolvePokemon(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!(gTriedEvolving & (1u << i)))
        {
            bool32 canStopEvo = TRUE;
            enum EvolutionMode mode = EVO_MODE_BATTLE_SPECIAL;
            u32 evolutionItemArg = i;

            enum Species species = GetEvolutionTargetSpecies(&gParties[B_TRAINER_PLAYER][i], mode, evolutionItemArg, NULL, &canStopEvo, CHECK_EVO);
            gTriedEvolving |= 1u << i;

            if (species == SPECIES_NONE && (gLeveledUpInBattle & (1u << i)))
            {
                gLeveledUpInBattle &= ~(1u << i);
                mode = EVO_MODE_BATTLE_ONLY;
                evolutionItemArg = gLeveledUpInBattle;
                species = GetEvolutionTargetSpecies(&gParties[B_TRAINER_PLAYER][i], mode, evolutionItemArg, NULL, &canStopEvo, CHECK_EVO);
            }

            if (species != SPECIES_NONE)
            {
                CloseMainBattleScreen();
                gBattleMainFunc = WaitForEvoSceneToFinish;
                GetEvolutionTargetSpecies(&gParties[B_TRAINER_PLAYER][i], mode, evolutionItemArg, NULL, &canStopEvo, DO_EVO);
                EvolutionScene(&gParties[B_TRAINER_PLAYER][i], species, canStopEvo, i);
                return;
            }
        }
    }
    gTriedEvolving = 0;
    gLeveledUpInBattle = 0;
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
        CalculatePlayerPartyCount();
        RandomlyGivePartyPokerus();
        PartySpreadPokerus();
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gReceivedRemoteLinkPlayers)
        return;

    gSpecialVar_Result = gBattleOutcome;
    gMain.inBattle = FALSE;
    gMain.callback1 = gPreBattleCallback1;

    if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
    {
        UpdateRoamerHPStatus(&gParties[B_TRAINER_OPPONENT_A][0]);
        ZeroEnemyPartyMons();

#ifndef BUGFIX
        // Bug: When Roar is used by a roamer, gBattleOutcome is B_OUTCOME_PLAYER_TELEPORTED (5),
        // which deactivates the roamer.
        if ((gBattleOutcome & B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT)
#else
        if ((gBattleOutcome == B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT ||
            gBattleOutcome == B_OUTCOME_DREW)
#endif
            SetRoamerInactive(gEncounteredRoamerIndex);
    }

    m4aSongNumStop(SE_LOW_HEALTH);
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
        RunBattleScriptCommands();
    }
}

void RunBattleScriptCommands(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
}

enum Type TrySetAteType(enum Move move, enum BattlerId battlerAtk, enum Ability attackerAbility)
{
    enum Type ateType = TYPE_NONE;

    switch (GetMoveEffect(move))
    {
    case EFFECT_TERA_BLAST:
        if (GetActiveGimmick(battlerAtk) == GIMMICK_TERA)
            return ateType;
        break;
    case EFFECT_TERA_STARSTORM:
        if (gBattleMons[battlerAtk].species == SPECIES_TERAPAGOS_STELLAR)
            return ateType;
        break;
    case EFFECT_HIDDEN_POWER:
    case EFFECT_WEATHER_BALL:
    case EFFECT_NATURAL_GIFT:
    case EFFECT_CHANGE_TYPE_ON_ITEM:
    case EFFECT_REVELATION_DANCE:
    case EFFECT_TERRAIN_PULSE:
        return ateType;
    default:
        break;
    }

    switch (attackerAbility)
    {
    case ABILITY_PIXILATE:
        ateType = TYPE_FAIRY;
        break;
    case ABILITY_REFRIGERATE:
        ateType = TYPE_ICE;
        break;
    case ABILITY_AERILATE:
        ateType = TYPE_FLYING;
        break;
    case ABILITY_GALVANIZE:
        ateType = TYPE_ELECTRIC;
        break;
    case ABILITY_DRAGONIZE:
        ateType = TYPE_DRAGON;
        break;
    default:
        ateType = TYPE_NONE;
        break;
    }

    return ateType;
}

// Returns TYPE_NONE if type doesn't change.
enum Type GetDynamicMoveType(struct Pokemon *mon, enum Move move, enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum MonState state)
{
    enum Type moveType = GetMoveType(move);
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    enum Species species;
    enum Item heldItem;
    enum Type types[3];
    enum Gimmick gimmick = GIMMICK_NONE;

    if (state == MON_IN_BATTLE)
    {
        if (moveEffect == EFFECT_STRUGGLE)
            return TYPE_MYSTERY;

        species = gBattleMons[battler].species;
        heldItem = gBattleMons[battler].item;
        GetBattlerTypes(battler, FALSE, types);
        gimmick = GetActiveGimmick(battler);
    }
    else
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
        holdEffect = GetItemHoldEffect(heldItem);
        ability = GetMonAbility(mon);
        types[0] = GetSpeciesType(species, 0);
        types[1] = GetSpeciesType(species, 1);
        types[2] = TYPE_MYSTERY;
        gimmick = GIMMICK_NONE;
    }

    switch (moveEffect)
    {
    case EFFECT_WEATHER_BALL:
        if (state == MON_IN_BATTLE)
        {
            u32 weather =  GetAttackerWeather(holdEffect, ability, GetWeather());
            if (weather & B_WEATHER_SUN)
                return TYPE_FIRE;
            else if (weather & B_WEATHER_RAIN)
                return TYPE_WATER;
            else if (weather & B_WEATHER_SANDSTORM)
                return TYPE_ROCK;
            else if (weather & B_WEATHER_ICY_ANY)
                return TYPE_ICE;
            else
                return moveType;
        }
        else
        {
            if (ability == ABILITY_MEGA_SOL)
                return TYPE_FIRE;
            switch (gWeatherPtr->currWeather)
            {
            case WEATHER_DROUGHT:
                if (holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                    return TYPE_FIRE;
                break;
            case WEATHER_RAIN:
            case WEATHER_RAIN_THUNDERSTORM:
            case WEATHER_DOWNPOUR:
                if (holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                    return TYPE_WATER;
                break;
            case WEATHER_SNOW:
                return TYPE_ICE;
            case WEATHER_SANDSTORM:
                return TYPE_ROCK;
            }
            return moveType;
        }
        break;
    case EFFECT_HIDDEN_POWER:
        {
            u32 typeBits = 0;
            if (state == MON_IN_BATTLE)
            {
                typeBits = ((gBattleMons[battler].hpIV & 1) << 0)
                        | ((gBattleMons[battler].attackIV & 1) << 1)
                        | ((gBattleMons[battler].defenseIV & 1) << 2)
                        | ((gBattleMons[battler].speedIV & 1) << 3)
                        | ((gBattleMons[battler].spAttackIV & 1) << 4)
                        | ((gBattleMons[battler].spDefenseIV & 1) << 5);
            }
            else
            {
                typeBits = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
                        | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
                        | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
                        | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
                        | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
                        | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);
            }

            u32 hpTypes[NUMBER_OF_MON_TYPES] = {0};
            u32 i, hpTypeCount = 0;
            for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
            {
                if (gTypesInfo[i].isHiddenPowerType)
                    hpTypes[hpTypeCount++] = i;
            }
            moveType = ((hpTypeCount - 1) * typeBits) / 63;
            return hpTypes[moveType];
        }
        break;
    case EFFECT_CHANGE_TYPE_ON_ITEM:
        if (holdEffect == GetMoveEffectArg_HoldEffect(move))
            return GetItemSecondaryId(heldItem);
        break;
    case EFFECT_REVELATION_DANCE:
        if (gimmick != GIMMICK_Z_MOVE)
        {
            if (state == MON_IN_BATTLE)
            {
                enum Type teraType;
                if (gimmick == GIMMICK_TERA && ((teraType = GetMonData(mon, MON_DATA_TERA_TYPE)) != TYPE_STELLAR))
                    return teraType;
                if (types[0] != TYPE_MYSTERY && !(gBattleMons[battler].volatiles.roostActive && types[0] == TYPE_FLYING))
                    return types[0];
                if (types[1] != TYPE_MYSTERY && !(gBattleMons[battler].volatiles.roostActive && types[1] == TYPE_FLYING))
                    return types[1];
                if (gBattleMons[battler].volatiles.roostActive)
                    return (B_ROOST_PURE_FLYING >= GEN_5 ? TYPE_NORMAL : TYPE_MYSTERY);
                if (types[2] != TYPE_MYSTERY)
                    return types[2];

                return TYPE_MYSTERY;
            }
            else
            {
                return types[0];
            }
        }
        break;
    case EFFECT_RAGING_BULL:
        switch (species)
        {
        case SPECIES_TAUROS_PALDEA_COMBAT:
        case SPECIES_TAUROS_PALDEA_BLAZE:
        case SPECIES_TAUROS_PALDEA_AQUA:
            return GetSpeciesType(species, 1);
        default:
            break;
        }
        break;
    case EFFECT_IVY_CUDGEL:
        switch (species)
        {
        case SPECIES_OGERPON_WELLSPRING:
        case SPECIES_OGERPON_WELLSPRING_TERA:
        case SPECIES_OGERPON_HEARTHFLAME:
        case SPECIES_OGERPON_HEARTHFLAME_TERA:
        case SPECIES_OGERPON_CORNERSTONE:
        case SPECIES_OGERPON_CORNERSTONE_TERA:
            return GetSpeciesType(species, 1);
        default:
            break;
        }
        break;
    case EFFECT_NATURAL_GIFT:
        if (GetItemPocket(heldItem) == POCKET_BERRIES)
            return gBerries[ItemIdToBerryType(heldItem)].naturalGiftType;
        else
            return moveType;
    case EFFECT_TERRAIN_PULSE:
        if (state == MON_IN_BATTLE)
        {
            if (IsAnyTerrainAffected(battler, ability, holdEffect, gFieldTimers.terrain))
                return gBattleTerrainInfo[gFieldTimers.terrain].type;
        }
        else
        {
            switch (gWeatherPtr->currWeather)
            {
            case WEATHER_RAIN_THUNDERSTORM:
                if (B_THUNDERSTORM_TERRAIN)
                    return TYPE_ELECTRIC;
                break;
            case WEATHER_FOG_HORIZONTAL:
            case WEATHER_FOG_DIAGONAL:
                if (B_OVERWORLD_FOG >= GEN_8)
                    return TYPE_FAIRY;
                break;
            }
            return moveType;
        }
        break;
    case EFFECT_TERA_BLAST:
        if (gimmick == GIMMICK_TERA)
            return GetMonData(mon, MON_DATA_TERA_TYPE);
        break;
    case EFFECT_TERA_STARSTORM:
        if (species == SPECIES_TERAPAGOS_STELLAR)
            return TYPE_STELLAR;
        break;
    case EFFECT_NATURE_POWER:
        if (state == MON_IN_BATTLE)
            return GetMoveType(GetNaturePowerMove());
        break;
    default:
        break;
    }

    if (IsSoundMove(move) && ability == ABILITY_LIQUID_VOICE)
    {
        return TYPE_WATER;
    }
    else if (moveEffect == EFFECT_AURA_WHEEL
          && species == SPECIES_MORPEKO_HANGRY
          && ability != ABILITY_NORMALIZE)
    {
        return TYPE_DARK;
    }
    else if (moveType == TYPE_NORMAL
          && ability != ABILITY_NORMALIZE
          && gimmick != GIMMICK_DYNAMAX
          && gimmick != GIMMICK_Z_MOVE)
    {
        enum Type ateType = TrySetAteType(move, battler, ability);
        if (ateType != TYPE_NONE && state == MON_IN_BATTLE)
            gBattleStruct->battlerState[battler].ateBoost = TRUE;
        return ateType;
    }
    else if (moveEffect != EFFECT_CHANGE_TYPE_ON_ITEM
          && moveEffect != EFFECT_TERRAIN_PULSE
          && moveEffect != EFFECT_NATURAL_GIFT
          && moveEffect != EFFECT_HIDDEN_POWER
          && moveEffect != EFFECT_WEATHER_BALL
          && ability == ABILITY_NORMALIZE
          && gimmick != GIMMICK_Z_MOVE)
    {
        if (state == MON_IN_BATTLE && gimmick != GIMMICK_DYNAMAX)
            gBattleStruct->battlerState[battler].ateBoost = TRUE;
        return TYPE_NORMAL;
    }

    return TYPE_NONE;
}

void SetTypeBeforeUsingMove(enum Move move, enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect)
{
    enum Item heldItem = gBattleMons[battler].item;

    gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_NONE;
    gBattleStruct->battlerState[battler].ateBoost = FALSE;
    gSpecialStatuses[battler].gemBoost = FALSE;

    enum Type moveType = GetDynamicMoveType(
                              GetBattlerMon(battler),
                              move,
                              battler,
                              ability,
                              holdEffect,
                              MON_IN_BATTLE
                            );

    if (moveType != TYPE_NONE)
        gBattleStruct->dynamicMoveType = moveType;

    moveType = GetBattleMoveType(move);
    if ((gFieldStatuses & STATUS_FIELD_ION_DELUGE && moveType == TYPE_NORMAL)
     || gBattleMons[battler].volatiles.electrified)
        gBattleStruct->dynamicMoveType = TYPE_ELECTRIC;

    // Check if a gem should activate.
    u32 effect = GetMoveEffect(move);
    if (holdEffect == HOLD_EFFECT_GEMS
        && GetBattleMoveType(move) == GetItemSecondaryId(heldItem)
        && effect != EFFECT_PLEDGE
        && effect != EFFECT_OHKO)
    {
        gSpecialStatuses[battler].gemParam = GetBattlerHoldEffectParam(battler);
        gSpecialStatuses[battler].gemBoost = TRUE;
    }
}

// Queues stat boosts for a given battler for totem battles
void ScriptSetTotemBoost(struct ScriptContext *ctx)
{
    enum BattlerId battler = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
    {
        u32 stage = VarGet(ScriptReadHalfword(ctx));
        if (stage)
        {
            gQueuedStatBoosts[battler].stats |= (1 << stat);
            gQueuedStatBoosts[battler].statChanges[stat] = stage;
        }
    }
}

bool32 IsWildMonSmart(void)
{
#if WE_SMART_WILD_AI_FLAG != 0
    return (FlagGet(WE_SMART_WILD_AI_FLAG));
#else
    return FALSE;
#endif
}

s32 Factorial(s32 n)
{
    s32 f = 1, i;
    for (i = 2; i <= n; i++)
        f *= i;
    return f;
}

bool32 CanPlayerForfeitNormalTrainerBattle(void)
{
    if (!B_RUN_TRAINER_BATTLE)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_INVALID)
        return FALSE;

    return (gBattleTypeFlags & BATTLE_TYPE_TRAINER);
}

bool32 DidPlayerForfeitNormalTrainerBattle(void)
{
    if (!CanPlayerForfeitNormalTrainerBattle())
        return FALSE;

    return (gBattleOutcome == B_OUTCOME_FORFEITED);
}

// Wins the battle instantly. Used in the battle debug with LIST_ITEM_INSTANT_WIN
void BattleDebug_WonBattle(void)
{
    gBattleOutcome |= B_OUTCOME_WON;
    gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
}
