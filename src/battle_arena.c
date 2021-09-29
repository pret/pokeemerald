#include "global.h"
#include "battle.h"
#include "battle_arena.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "item.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "util.h"
#include "constants/songs.h"
#include "constants/battle_arena.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"

// This file's functions.
static void InitArenaChallenge(void);
static void GetArenaData(void);
static void SetArenaData(void);
static void SaveArenaChallenge(void);
static void SetArenaPrize(void);
static void GiveArenaPrize(void);
static void BufferArenaOpponentName(void);
static void SpriteCb_JudgmentIcon(struct Sprite *sprite);
static void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler);

// Const rom data.
static const s8 sMindRatings[] =
{
    [MOVE_NONE] = 0,
    [MOVE_POUND] = 1,
    [MOVE_KARATE_CHOP] = 1,
    [MOVE_DOUBLE_SLAP] = 1,
    [MOVE_COMET_PUNCH] = 1,
    [MOVE_MEGA_PUNCH] = 1,
    [MOVE_PAY_DAY] = 1,
    [MOVE_FIRE_PUNCH] = 1,
    [MOVE_ICE_PUNCH] = 1,
    [MOVE_THUNDER_PUNCH] = 1,
    [MOVE_SCRATCH] = 1,
    [MOVE_VICE_GRIP] = 1,
    [MOVE_GUILLOTINE] = 1,
    [MOVE_RAZOR_WIND] = 1,
    [MOVE_SWORDS_DANCE] = 0,
    [MOVE_CUT] = 1,
    [MOVE_GUST] = 1,
    [MOVE_WING_ATTACK] = 1,
    [MOVE_WHIRLWIND] = 0,
    [MOVE_FLY] = 1,
    [MOVE_BIND] = 1,
    [MOVE_SLAM] = 1,
    [MOVE_VINE_WHIP] = 1,
    [MOVE_STOMP] = 1,
    [MOVE_DOUBLE_KICK] = 1,
    [MOVE_MEGA_KICK] = 1,
    [MOVE_JUMP_KICK] = 1,
    [MOVE_ROLLING_KICK] = 1,
    [MOVE_SAND_ATTACK] = 0,
    [MOVE_HEADBUTT] = 1,
    [MOVE_HORN_ATTACK] = 1,
    [MOVE_FURY_ATTACK] = 1,
    [MOVE_HORN_DRILL] = 1,
    [MOVE_TACKLE] = 1,
    [MOVE_BODY_SLAM] = 1,
    [MOVE_WRAP] = 1,
    [MOVE_TAKE_DOWN] = 1,
    [MOVE_THRASH] = 1,
    [MOVE_DOUBLE_EDGE] = 1,
    [MOVE_TAIL_WHIP] = 0,
    [MOVE_POISON_STING] = 1,
    [MOVE_TWINEEDLE] = 1,
    [MOVE_PIN_MISSILE] = 1,
    [MOVE_LEER] = 0,
    [MOVE_BITE] = 1,
    [MOVE_GROWL] = 0,
    [MOVE_ROAR] = 0,
    [MOVE_SING] = 0,
    [MOVE_SUPERSONIC] = 0,
    [MOVE_SONIC_BOOM] = 1,
    [MOVE_DISABLE] = 0,
    [MOVE_ACID] = 1,
    [MOVE_EMBER] = 1,
    [MOVE_FLAMETHROWER] = 1,
    [MOVE_MIST] = 0,
    [MOVE_WATER_GUN] = 1,
    [MOVE_HYDRO_PUMP] = 1,
    [MOVE_SURF] = 1,
    [MOVE_ICE_BEAM] = 1,
    [MOVE_BLIZZARD] = 1,
    [MOVE_PSYBEAM] = 1,
    [MOVE_BUBBLE_BEAM] = 1,
    [MOVE_AURORA_BEAM] = 1,
    [MOVE_HYPER_BEAM] = 1,
    [MOVE_PECK] = 1,
    [MOVE_DRILL_PECK] = 1,
    [MOVE_SUBMISSION] = 1,
    [MOVE_LOW_KICK] = 1,
    [MOVE_COUNTER] = 0,
    [MOVE_SEISMIC_TOSS] = 1,
    [MOVE_STRENGTH] = 1,
    [MOVE_ABSORB] = 1,
    [MOVE_MEGA_DRAIN] = 1,
    [MOVE_LEECH_SEED] = 0,
    [MOVE_GROWTH] = 0,
    [MOVE_RAZOR_LEAF] = 1,
    [MOVE_SOLAR_BEAM] = 1,
    [MOVE_POISON_POWDER] = 0,
    [MOVE_STUN_SPORE] = 0,
    [MOVE_SLEEP_POWDER] = 0,
    [MOVE_PETAL_DANCE] = 1,
    [MOVE_STRING_SHOT] = 0,
    [MOVE_DRAGON_RAGE] = 1,
    [MOVE_FIRE_SPIN] = 1,
    [MOVE_THUNDER_SHOCK] = 1,
    [MOVE_THUNDERBOLT] = 1,
    [MOVE_THUNDER_WAVE] = 0,
    [MOVE_THUNDER] = 1,
    [MOVE_ROCK_THROW] = 1,
    [MOVE_EARTHQUAKE] = 1,
    [MOVE_FISSURE] = 1,
    [MOVE_DIG] = 1,
    [MOVE_TOXIC] = 0,
    [MOVE_CONFUSION] = 1,
    [MOVE_PSYCHIC] = 1,
    [MOVE_HYPNOSIS] = 0,
    [MOVE_MEDITATE] = 0,
    [MOVE_AGILITY] = 0,
    [MOVE_QUICK_ATTACK] = 1,
    [MOVE_RAGE] = 1,
    [MOVE_TELEPORT] = 0,
    [MOVE_NIGHT_SHADE] = 1,
    [MOVE_MIMIC] = 0,
    [MOVE_SCREECH] = 0,
    [MOVE_DOUBLE_TEAM] = 0,
    [MOVE_RECOVER] = 0,
    [MOVE_HARDEN] = 0,
    [MOVE_MINIMIZE] = 0,
    [MOVE_SMOKESCREEN] = 0,
    [MOVE_CONFUSE_RAY] = 0,
    [MOVE_WITHDRAW] = 0,
    [MOVE_DEFENSE_CURL] = 0,
    [MOVE_BARRIER] = 0,
    [MOVE_LIGHT_SCREEN] = 0,
    [MOVE_HAZE] = 0,
    [MOVE_REFLECT] = 0,
    [MOVE_FOCUS_ENERGY] = 0,
    [MOVE_BIDE] = 0,
    [MOVE_METRONOME] = 0,
    [MOVE_MIRROR_MOVE] = 0,
    [MOVE_SELF_DESTRUCT] = 1,
    [MOVE_EGG_BOMB] = 1,
    [MOVE_LICK] = 1,
    [MOVE_SMOG] = 1,
    [MOVE_SLUDGE] = 1,
    [MOVE_BONE_CLUB] = 1,
    [MOVE_FIRE_BLAST] = 1,
    [MOVE_WATERFALL] = 1,
    [MOVE_CLAMP] = 1,
    [MOVE_SWIFT] = 1,
    [MOVE_SKULL_BASH] = 1,
    [MOVE_SPIKE_CANNON] = 1,
    [MOVE_CONSTRICT] = 1,
    [MOVE_AMNESIA] = 0,
    [MOVE_KINESIS] = 0,
    [MOVE_SOFT_BOILED] = 0,
    [MOVE_HI_JUMP_KICK] = 1,
    [MOVE_GLARE] = 0,
    [MOVE_DREAM_EATER] = 1,
    [MOVE_POISON_GAS] = 0,
    [MOVE_BARRAGE] = 1,
    [MOVE_LEECH_LIFE] = 1,
    [MOVE_LOVELY_KISS] = 0,
    [MOVE_SKY_ATTACK] = 1,
    [MOVE_TRANSFORM] = 0,
    [MOVE_BUBBLE] = 1,
    [MOVE_DIZZY_PUNCH] = 1,
    [MOVE_SPORE] = 0,
    [MOVE_FLASH] = 0,
    [MOVE_PSYWAVE] = 1,
    [MOVE_SPLASH] = 0,
    [MOVE_ACID_ARMOR] = 0,
    [MOVE_CRABHAMMER] = 1,
    [MOVE_EXPLOSION] = 1,
    [MOVE_FURY_SWIPES] = 1,
    [MOVE_BONEMERANG] = 1,
    [MOVE_REST] = 0,
    [MOVE_ROCK_SLIDE] = 1,
    [MOVE_HYPER_FANG] = 1,
    [MOVE_SHARPEN] = 0,
    [MOVE_CONVERSION] = 0,
    [MOVE_TRI_ATTACK] = 1,
    [MOVE_SUPER_FANG] = 1,
    [MOVE_SLASH] = 1,
    [MOVE_SUBSTITUTE] = 0,
    [MOVE_STRUGGLE] = 1,
    [MOVE_SKETCH] = 0,
    [MOVE_TRIPLE_KICK] = 1,
    [MOVE_THIEF] = 1,
    [MOVE_SPIDER_WEB] = 0,
    [MOVE_MIND_READER] = 0,
    [MOVE_NIGHTMARE] = 0,
    [MOVE_FLAME_WHEEL] = 1,
    [MOVE_SNORE] = 1,
    [MOVE_CURSE] = 0,
    [MOVE_FLAIL] = 1,
    [MOVE_CONVERSION_2] = 0,
    [MOVE_AEROBLAST] = 1,
    [MOVE_COTTON_SPORE] = 0,
    [MOVE_REVERSAL] = 1,
    [MOVE_SPITE] = 0,
    [MOVE_POWDER_SNOW] = 1,
    [MOVE_PROTECT] = -1,
    [MOVE_MACH_PUNCH] = 1,
    [MOVE_SCARY_FACE] = 0,
    [MOVE_FAINT_ATTACK] = 1,
    [MOVE_SWEET_KISS] = 0,
    [MOVE_BELLY_DRUM] = 0,
    [MOVE_SLUDGE_BOMB] = 1,
    [MOVE_MUD_SLAP] = 1,
    [MOVE_OCTAZOOKA] = 1,
    [MOVE_SPIKES] = 0,
    [MOVE_ZAP_CANNON] = 1,
    [MOVE_FORESIGHT] = 0,
    [MOVE_DESTINY_BOND] = 0,
    [MOVE_PERISH_SONG] = 0,
    [MOVE_ICY_WIND] = 1,
    [MOVE_DETECT] = -1,
    [MOVE_BONE_RUSH] = 1,
    [MOVE_LOCK_ON] = 0,
    [MOVE_OUTRAGE] = 1,
    [MOVE_SANDSTORM] = 0,
    [MOVE_GIGA_DRAIN] = 1,
    [MOVE_ENDURE] = -1,
    [MOVE_CHARM] = 0,
    [MOVE_ROLLOUT] = 1,
    [MOVE_FALSE_SWIPE] = 1,
    [MOVE_SWAGGER] = 0,
    [MOVE_MILK_DRINK] = 0,
    [MOVE_SPARK] = 1,
    [MOVE_FURY_CUTTER] = 1,
    [MOVE_STEEL_WING] = 1,
    [MOVE_MEAN_LOOK] = 0,
    [MOVE_ATTRACT] = 0,
    [MOVE_SLEEP_TALK] = 0,
    [MOVE_HEAL_BELL] = 0,
    [MOVE_RETURN] = 1,
    [MOVE_PRESENT] = 1,
    [MOVE_FRUSTRATION] = 1,
    [MOVE_SAFEGUARD] = 0,
    [MOVE_PAIN_SPLIT] = 0,
    [MOVE_SACRED_FIRE] = 1,
    [MOVE_MAGNITUDE] = 1,
    [MOVE_DYNAMIC_PUNCH] = 1,
    [MOVE_MEGAHORN] = 1,
    [MOVE_DRAGON_BREATH] = 1,
    [MOVE_BATON_PASS] = 0,
    [MOVE_ENCORE] = 0,
    [MOVE_PURSUIT] = 1,
    [MOVE_RAPID_SPIN] = 1,
    [MOVE_SWEET_SCENT] = 0,
    [MOVE_IRON_TAIL] = 1,
    [MOVE_METAL_CLAW] = 1,
    [MOVE_VITAL_THROW] = 1,
    [MOVE_MORNING_SUN] = 0,
    [MOVE_SYNTHESIS] = 0,
    [MOVE_MOONLIGHT] = 0,
    [MOVE_HIDDEN_POWER] = 1,
    [MOVE_CROSS_CHOP] = 1,
    [MOVE_TWISTER] = 1,
    [MOVE_RAIN_DANCE] = 0,
    [MOVE_SUNNY_DAY] = 0,
    [MOVE_CRUNCH] = 1,
    [MOVE_MIRROR_COAT] = 0,
    [MOVE_PSYCH_UP] = 0,
    [MOVE_EXTREME_SPEED] = 1,
    [MOVE_ANCIENT_POWER] = 1,
    [MOVE_SHADOW_BALL] = 1,
    [MOVE_FUTURE_SIGHT] = 1,
    [MOVE_ROCK_SMASH] = 1,
    [MOVE_WHIRLPOOL] = 1,
    [MOVE_BEAT_UP] = 1,
    [MOVE_FAKE_OUT] = -1,
    [MOVE_UPROAR] = 1,
    [MOVE_STOCKPILE] = 0,
    [MOVE_SPIT_UP] = 1,
    [MOVE_SWALLOW] = 0,
    [MOVE_HEAT_WAVE] = 1,
    [MOVE_HAIL] = 0,
    [MOVE_TORMENT] = 0,
    [MOVE_FLATTER] = 0,
    [MOVE_WILL_O_WISP] = 0,
    [MOVE_MEMENTO] = 0,
    [MOVE_FACADE] = 1,
    [MOVE_FOCUS_PUNCH] = 1,
    [MOVE_SMELLING_SALT] = 1,
    [MOVE_FOLLOW_ME] = 0,
    [MOVE_NATURE_POWER] = 0,
    [MOVE_CHARGE] = 0,
    [MOVE_TAUNT] = 0,
    [MOVE_HELPING_HAND] = 0,
    [MOVE_TRICK] = 0,
    [MOVE_ROLE_PLAY] = 0,
    [MOVE_WISH] = 0,
    [MOVE_ASSIST] = 0,
    [MOVE_INGRAIN] = 0,
    [MOVE_SUPERPOWER] = 1,
    [MOVE_MAGIC_COAT] = 0,
    [MOVE_RECYCLE] = 0,
    [MOVE_REVENGE] = 1,
    [MOVE_BRICK_BREAK] = 1,
    [MOVE_YAWN] = 0,
    [MOVE_KNOCK_OFF] = 1,
    [MOVE_ENDEAVOR] = 1,
    [MOVE_ERUPTION] = 1,
    [MOVE_SKILL_SWAP] = 0,
    [MOVE_IMPRISON] = 0,
    [MOVE_REFRESH] = 0,
    [MOVE_GRUDGE] = 0,
    [MOVE_SNATCH] = 0,
    [MOVE_SECRET_POWER] = 1,
    [MOVE_DIVE] = 1,
    [MOVE_ARM_THRUST] = 1,
    [MOVE_CAMOUFLAGE] = 0,
    [MOVE_TAIL_GLOW] = 0,
    [MOVE_LUSTER_PURGE] = 1,
    [MOVE_MIST_BALL] = 1,
    [MOVE_FEATHER_DANCE] = 0,
    [MOVE_TEETER_DANCE] = 0,
    [MOVE_BLAZE_KICK] = 1,
    [MOVE_MUD_SPORT] = 0,
    [MOVE_ICE_BALL] = 1,
    [MOVE_NEEDLE_ARM] = 1,
    [MOVE_SLACK_OFF] = 0,
    [MOVE_HYPER_VOICE] = 1,
    [MOVE_POISON_FANG] = 1,
    [MOVE_CRUSH_CLAW] = 1,
    [MOVE_BLAST_BURN] = 1,
    [MOVE_HYDRO_CANNON] = 1,
    [MOVE_METEOR_MASH] = 1,
    [MOVE_ASTONISH] = 1,
    [MOVE_WEATHER_BALL] = 1,
    [MOVE_AROMATHERAPY] = 0,
    [MOVE_FAKE_TEARS] = 0,
    [MOVE_AIR_CUTTER] = 1,
    [MOVE_OVERHEAT] = 1,
    [MOVE_ODOR_SLEUTH] = 0,
    [MOVE_ROCK_TOMB] = 1,
    [MOVE_SILVER_WIND] = 1,
    [MOVE_METAL_SOUND] = 0,
    [MOVE_GRASS_WHISTLE] = 0,
    [MOVE_TICKLE] = 0,
    [MOVE_COSMIC_POWER] = 0,
    [MOVE_WATER_SPOUT] = 1,
    [MOVE_SIGNAL_BEAM] = 1,
    [MOVE_SHADOW_PUNCH] = 1,
    [MOVE_EXTRASENSORY] = 1,
    [MOVE_SKY_UPPERCUT] = 1,
    [MOVE_SAND_TOMB] = 1,
    [MOVE_SHEER_COLD] = 1,
    [MOVE_MUDDY_WATER] = 1,
    [MOVE_BULLET_SEED] = 1,
    [MOVE_AERIAL_ACE] = 1,
    [MOVE_ICICLE_SPEAR] = 1,
    [MOVE_IRON_DEFENSE] = 0,
    [MOVE_BLOCK] = 0,
    [MOVE_HOWL] = 0,
    [MOVE_DRAGON_CLAW] = 1,
    [MOVE_FRENZY_PLANT] = 1,
    [MOVE_BULK_UP] = 0,
    [MOVE_BOUNCE] = 1,
    [MOVE_MUD_SHOT] = 1,
    [MOVE_POISON_TAIL] = 1,
    [MOVE_COVET] = 1,
    [MOVE_VOLT_TACKLE] = 1,
    [MOVE_MAGICAL_LEAF] = 1,
    [MOVE_WATER_SPORT] = 0,
    [MOVE_CALM_MIND] = 0,
    [MOVE_LEAF_BLADE] = 1,
    [MOVE_DRAGON_DANCE] = 0,
    [MOVE_ROCK_BLAST] = 1,
    [MOVE_SHOCK_WAVE] = 1,
    [MOVE_WATER_PULSE] = 1,
    [MOVE_DOOM_DESIRE] = 1,
    [MOVE_PSYCHO_BOOST] = 1,
};

#define TAG_JUDGEMENT_ICON 1000

static const struct OamData sJudgementIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 15,
    .affineParam = 0
};

static const union AnimCmd sJudgementIconAnimCmd0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sJudgementIconAnimCmd1[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd sJudgementIconAnimCmd2[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sJudgementIconAnimCmd3[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sJudgementIconAnimCmds[] =
{
    sJudgementIconAnimCmd0,
    sJudgementIconAnimCmd1,
    sJudgementIconAnimCmd2,
    sJudgementIconAnimCmd3
};

static const struct SpriteTemplate sSpriteTemplate_JudgmentIcon =
{
    .tileTag = TAG_JUDGEMENT_ICON,
    .paletteTag = TAG_NONE,
    .oam = &sJudgementIconOamData,
    .anims = sJudgementIconAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_JudgmentIcon,
};

static const struct CompressedSpriteSheet sBattleArenaJudgementSymbolsSpriteSheet[] =
{
    {gBattleArenaJudgementSymbolsGfx, 0x200, TAG_JUDGEMENT_ICON},
    {0}
};

static void (* const sArenaFunctions[])(void) =
{
    [BATTLE_ARENA_FUNC_INIT]             = InitArenaChallenge,
    [BATTLE_ARENA_FUNC_GET_DATA]         = GetArenaData,
    [BATTLE_ARENA_FUNC_SET_DATA]         = SetArenaData,
    [BATTLE_ARENA_FUNC_SAVE]             = SaveArenaChallenge,
    [BATTLE_ARENA_FUNC_SET_PRIZE]        = SetArenaPrize,
    [BATTLE_ARENA_FUNC_GIVE_PRIZE]       = GiveArenaPrize,
    [BATTLE_ARENA_FUNC_GET_TRAINER_NAME] = BufferArenaOpponentName,
};

static const u16 sShortStreakPrizeItems[] =
{
    ITEM_HP_UP,
    ITEM_PROTEIN,
    ITEM_IRON,
    ITEM_CALCIUM,
    ITEM_CARBOS,
    ITEM_ZINC,
};

static const u16 sLongStreakPrizeItems[] =
{
    ITEM_BRIGHT_POWDER,
    ITEM_WHITE_HERB,
    ITEM_QUICK_CLAW,
    ITEM_LEFTOVERS,
    ITEM_MENTAL_HERB,
    ITEM_KINGS_ROCK,
    ITEM_FOCUS_BAND,
    ITEM_SCOPE_LENS,
    ITEM_CHOICE_BAND,
};

// code
void CallBattleArenaFunction(void)
{
    sArenaFunctions[gSpecialVar_0x8004]();
}

u8 BattleArena_ShowJudgmentWindow(u8 *state)
{
    int i;
    u8 ret = 0;
    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 0, 8, RGB_BLACK);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
        LoadCompressedSpriteSheet(sBattleArenaJudgementSymbolsSpriteSheet);
        LoadCompressedPalette(gBattleArenaJudgementSymbolsPalette, 0x1F0, 0x20);
        gBattle_WIN0H = 0xFF;
        gBattle_WIN0V = 0x70;
        (*state)++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            HandleBattleWindow(5, 0, 24, 13, 0);
            (*state)++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattleTextBuff1[0] = CHAR_0;
            gBattleTextBuff1[1] = EOS;
            gBattleTextBuff2[0] = CHAR_0;
            gBattleTextBuff2[1] = EOS;
            BattleStringExpandPlaceholdersToDisplayedString(gText_PlayerMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, 15);
            BattlePutTextOnWindow(gText_Vs, 16);
            BattleStringExpandPlaceholdersToDisplayedString(gText_OpponentMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, 17);
            BattlePutTextOnWindow(gText_Mind, 18);
            BattlePutTextOnWindow(gText_Skill, 19);
            BattlePutTextOnWindow(gText_Body, 20);
            BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
            BattlePutTextOnWindow(gDisplayedStringBattle, 21);
            (*state)++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
            for (i = 0; i < 8; i++)
            {
                u8 spriteId = CreateSprite(&sSpriteTemplate_JudgmentIcon, 64 + i * 16, 84, 0);
                StartSpriteAnim(&gSprites[spriteId], 3);
            }
            ret = 1;
            (*state)++;
        }
        break;
    case 4:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 40, ARENA_CATEGORY_MIND, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 40, ARENA_CATEGORY_MIND, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
        BattlePutTextOnWindow(gDisplayedStringBattle, 21);
        (*state)++;
        ret = 1;
        break;
    case 5:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 56, ARENA_CATEGORY_SKILL, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 56, ARENA_CATEGORY_SKILL, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
        BattlePutTextOnWindow(gDisplayedStringBattle, 21);
        (*state)++;
        ret = 1;
        break;
    case 6:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 72, ARENA_CATEGORY_BODY, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 72, ARENA_CATEGORY_BODY, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
        BattlePutTextOnWindow(gDisplayedStringBattle, 21);
        (*state)++;
        ret = 1;
        break;
    case 7:
        PlaySE(SE_ARENA_TIMEUP2);
        if (gBattleTextBuff1[0] > gBattleTextBuff2[0])
        {
            ret = 2;
            gBattleScripting.battler = 0;
        }
        else if (gBattleTextBuff1[0] < gBattleTextBuff2[0])
        {
            ret = 3;
            gBattleScripting.battler = 1;
        }
        else
        {
            ret = 4;
        }
        (*state)++;
        break;
    case 8:
        (*state)++;
        break;
    case 9:
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
        HandleBattleWindow(5, 0, 24, 13, WINDOW_CLEAR);
        CopyBgTilemapBufferToVram(0);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 8, 0, RGB_BLACK);
        (*state)++;
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
            FreeSpriteTilesByTag(TAG_JUDGEMENT_ICON);
            ret = 1;
            (*state)++;
        }
        break;
    }

    return ret;
}

static void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler)
{
    int animNum = 0;
    int pointsPlayer = 0;
    int pointsOpponent = 0;
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    switch (category)
    {
    case ARENA_CATEGORY_MIND:
        pointsPlayer = mindPoints[battler];
        pointsOpponent = mindPoints[BATTLE_OPPOSITE(battler)];
        break;
    case ARENA_CATEGORY_SKILL:
        pointsPlayer = skillPoints[battler];
        pointsOpponent = skillPoints[BATTLE_OPPOSITE(battler)];
        break;
    case ARENA_CATEGORY_BODY:
        pointsPlayer = (gBattleMons[battler].hp * 100) / hpAtStart[battler];
        pointsOpponent = (gBattleMons[BATTLE_OPPOSITE(battler)].hp * 100) / hpAtStart[BATTLE_OPPOSITE(battler)];
        break;
    }

    if (pointsPlayer > pointsOpponent)
    {
        animNum = 2;
        if (battler != 0)
            gBattleTextBuff2[0] += 2;
        else
            gBattleTextBuff1[0] += 2;
    }
    else if (pointsPlayer == pointsOpponent)
    {
        animNum = 1;
        if (battler != 0)
            gBattleTextBuff2[0] += 1;
        else
            gBattleTextBuff1[0] += 1;
    }
    else
    {
        animNum = 0;
    }

    pointsPlayer = CreateSprite(&sSpriteTemplate_JudgmentIcon, x, y, 0);
    StartSpriteAnim(&gSprites[pointsPlayer], animNum);
}

static void SpriteCb_JudgmentIcon(struct Sprite *sprite)
{
    if (gBattleCommunication[0] > 8)
        DestroySprite(sprite);
}

void BattleArena_InitPoints(void)
{
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    mindPoints[0] = 0;
    mindPoints[1] = 0;
    skillPoints[0] = 0;
    skillPoints[1] = 0;
    hpAtStart[0] = gBattleMons[0].hp;
    hpAtStart[1] = gBattleMons[1].hp;
}

void BattleArena_AddMindPoints(u8 battler)
{
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    mindPoints[battler] += sMindRatings[gCurrentMove];
}

void BattleArena_AddSkillPoints(u8 battler)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    if (gHitMarker & HITMARKER_OBEYS)
    {
        u8 *failedMoveBits = &gBattleStruct->alreadyStatusedMoveAttempt;
        if (*failedMoveBits & gBitTable[battler])
        {
            *failedMoveBits &= ~(gBitTable[battler]);
            skillPoints[battler] -= 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        {
            if (!(gMoveResultFlags & MOVE_RESULT_MISSED) || gBattleCommunication[6] != 1)
                skillPoints[battler] -= 2;
        }
        else if ((gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE) && (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE))
        {
            skillPoints[battler] += 1;
        }
        else if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
        {
            skillPoints[battler] += 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
        {
            skillPoints[battler] -= 1;
        }
        else if (!gProtectStructs[battler].protected)
        {
            skillPoints[battler] += 1;
        }
    }
}

void BattleArena_DeductMindPoints(u8 battler, u16 stringId)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    switch (stringId)
    {
    case STRINGID_PKMNSXMADEYUSELESS:
    case STRINGID_PKMNSXMADEITINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSFLINCHING:
    case STRINGID_PKMNSXBLOCKSY2:
    case STRINGID_PKMNSXPREVENTSYLOSS:
    case STRINGID_PKMNSXMADEYINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSBURNS:
    case STRINGID_PKMNSXBLOCKSY:
    case STRINGID_PKMNPROTECTEDBY:
    case STRINGID_PKMNPREVENTSUSAGE:
    case STRINGID_PKMNRESTOREDHPUSING:
    case STRINGID_PKMNPREVENTSPARALYSISWITH:
    case STRINGID_PKMNPREVENTSROMANCEWITH:
    case STRINGID_PKMNPREVENTSPOISONINGWITH:
    case STRINGID_PKMNPREVENTSCONFUSIONWITH:
    case STRINGID_PKMNRAISEDFIREPOWERWITH:
    case STRINGID_PKMNANCHORSITSELFWITH:
    case STRINGID_PKMNPREVENTSSTATLOSSWITH:
    case STRINGID_PKMNSTAYEDAWAKEUSING:
        skillPoints[battler] -= 3;
        break;
    }
}

// Unused
static void UpdateHPAtStart(u8 battler)
{
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    hpAtStart[battler] = gBattleMons[battler].hp;
    if (hpAtStart[BATTLE_OPPOSITE(battler)] > gBattleMons[BATTLE_OPPOSITE(battler)].hp)
        hpAtStart[BATTLE_OPPOSITE(battler)] = gBattleMons[BATTLE_OPPOSITE(battler)].hp;
}

static void InitArenaChallenge(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_OPEN;
    else
        isCurrent = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_50;

    if (!isCurrent)
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

static void GetArenaData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case ARENA_DATA_PRIZE:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaPrize;
        break;
    case ARENA_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
        break;
    case ARENA_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_OPEN;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_50;
        break;
    }
}

static void SetArenaData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case ARENA_DATA_PRIZE:
        gSaveBlock2Ptr->frontier.arenaPrize = gSpecialVar_0x8006;
        break;
    case ARENA_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case ARENA_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_ARENA_OPEN;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~(STREAK_ARENA_OPEN);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_ARENA_50;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~(STREAK_ARENA_50);
        }
        break;
    }
}

static void SaveArenaChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetArenaPrize(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.arenaPrize = sLongStreakPrizeItems[Random() % ARRAY_COUNT(sLongStreakPrizeItems)];
    else
        gSaveBlock2Ptr->frontier.arenaPrize = sShortStreakPrizeItems[Random() % ARRAY_COUNT(sShortStreakPrizeItems)];
}

static void GiveArenaPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.arenaPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.arenaPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.arenaPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void BufferArenaOpponentName(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void DrawArenaRefereeTextBox(void)
{
    u8 width = 27;
    u8 palNum = 7;

    FillBgTilemapBufferRect(0, 0,    254, 14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0,    32,  14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0x31, 0,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x33, 1,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x34, 2,   14, width, 1, palNum);
    width++;
    FillBgTilemapBufferRect(0, 0x35, 28,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x36, 29,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x37, 0,   15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x39, 1,   15, width, 5, palNum);
    FillBgTilemapBufferRect(0, 0x3A, 29,  15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x831, 0,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 1,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 2,  19, width - 2, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 28, 19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 29, 19, 1,  1, palNum);
}

void EraseArenaRefereeTextBox(void)
{
    u8 width;
    u8 height;
    u8 palNum = 0;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    width = 27;
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}
