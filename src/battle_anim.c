#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_anim_scripts.h"
#include "battle_controllers.h"
#include "battle_environment.h"
#include "battle_interface.h"
#include "battle_util.h"
#include "bg.h"
#include "contest.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "m4a.h"
#include "palette.h"
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "test_runner.h"
#include "test/battle.h"
#include "constants/battle_anim.h"
#include "constants/moves.h"

/*
    This file handles the commands for the macros defined in
    battle_anim_script.inc and used in battle_anim_scripts.s
*/

static void Cmd_unloadspritegfx(void);
static void Cmd_unloadspritepal(void);
static void Cmd_createsprite(void);
static void Cmd_createvisualtask(void);
static void Cmd_delay(void);
static void Cmd_waitforvisualfinish(void);
static void Cmd_nop(void);
static void Cmd_nop2(void);
static void Cmd_end(void);
static void Cmd_playse(void);
static void Cmd_monbg(void);
static void Cmd_clearmonbg(void);
static void Cmd_setalpha(void);
static void Cmd_blendoff(void);
static void Cmd_call(void);
static void Cmd_return(void);
static void Cmd_setarg(void);
static void Cmd_choosetwoturnanim(void);
static void Cmd_jumpifmoveturn(void);
static void Cmd_goto(void);
static void Cmd_fadetobg(void);
static void Cmd_restorebg(void);
static void Cmd_waitbgfadeout(void);
static void Cmd_waitbgfadein(void);
static void Cmd_changebg(void);
static void Cmd_playsewithpan(void);
static void Cmd_setpan(void);
static void Cmd_panse(void);
static void Cmd_loopsewithpan(void);
static void Cmd_waitplaysewithpan(void);
static void Cmd_setbldcnt(void);
static void Cmd_createsoundtask(void);
static void Cmd_waitsound(void);
static void Cmd_jumpargeq(void);
static void Cmd_monbg_static(void);
static void Cmd_clearmonbg_static(void);
static void Cmd_jumpifcontest(void);
static void Cmd_fadetobgfromset(void);
static void Cmd_panse_adjustnone(void);
static void Cmd_panse_adjustall(void);
static void Cmd_splitbgprio(void);
static void Cmd_splitbgprio_all(void);
static void Cmd_splitbgprio_foes(void);
static void Cmd_invisible(void);
static void Cmd_visible(void);
static void Cmd_teamattack_moveback(void);
static void Cmd_teamattack_movefwd(void);
static void Cmd_stopsound(void);
static void Cmd_createvisualtaskontargets(void);
static void Cmd_createspriteontargets(void);
static void Cmd_createspriteontargets_onpos(void);
static void Cmd_jumpifmovetypeequal(void);
static void Cmd_createdragondartsprite(void);
static void Cmd_unloadallspritepals(void);
static void RunAnimScriptCommand(void);
static void Task_UpdateMonBg(u8 taskId);
static void FlipBattlerBgTiles(void);
static void Task_ClearMonBg(u8 taskId);
static void Task_ClearMonBgStatic(u8 taskId);
static void Task_FadeToBg(u8 taskId);
static void Task_PanFromInitialToTarget(u8 taskId);
static void Task_LoopAndPlaySE(u8 taskId);
static void Task_WaitAndPlaySE(u8 taskId);
static void LoadDefaultBg(void);

EWRAM_DATA static const u8 *sBattleAnimScriptPtr = NULL;
EWRAM_DATA static const u8 *sBattleAnimScriptRetAddr[MAX_ANIM_CALL_DEPTH] = {0};
EWRAM_DATA static u8 sBattleAnimScriptCallDepth = 0;
EWRAM_DATA void (*gAnimScriptCallback)(void) = NULL;
EWRAM_DATA static s8 sAnimFramesToWait = 0;
EWRAM_DATA bool8 gAnimScriptActive = FALSE;
EWRAM_DATA u8 gAnimVisualTaskCount = 0;
EWRAM_DATA u8 gAnimSoundTaskCount = 0;
EWRAM_DATA struct LinkBattleAnim *gAnimDisableStructPtr = NULL;
EWRAM_DATA s32 gAnimMoveDmg = 0;
EWRAM_DATA u16 gAnimMovePower = 0;
ALIGNED(4) EWRAM_DATA static u16 sAnimSpriteGfxTags[ANIM_SPRITE_GFX_COUNT] = {0};
ALIGNED(4) EWRAM_DATA static u16 sAnimSpritePalTags[ANIM_SPRITE_GFX_COUNT] = {0};
EWRAM_DATA u8 gAnimFriendship = 0;
EWRAM_DATA u16 gWeatherMoveAnim = 0;
EWRAM_DATA s16 gBattleAnimArgs[ANIM_ARGS_COUNT] = {0};
EWRAM_DATA static u16 sSoundAnimFramesToWait = 0;
EWRAM_DATA static u8 sMonAnimTaskIdArray[2] = {0};
EWRAM_DATA u8 gAnimMoveTurn = 0;
EWRAM_DATA static u8 sAnimBackgroundFadeState = 0;
EWRAM_DATA u16 gAnimMoveIndex = 0;
EWRAM_DATA enum BattlerId gBattleAnimAttacker = 0;
EWRAM_DATA enum BattlerId gBattleAnimTarget = 0;
EWRAM_DATA enum Species gAnimBattlerSpecies[MAX_BATTLERS_COUNT] = {SPECIES_NONE};
EWRAM_DATA u8 gAnimCustomPanning = 0;
EWRAM_DATA static bool8 sAnimHideHpBoxes = FALSE;

#include "data/battle_anim.h"

static void (*const sScriptCmdTable[])(void) =
{
    Cmd_unloadspritegfx,      // 0x00
    Cmd_unloadspritepal,      // 0x01
    Cmd_createsprite,         // 0x02
    Cmd_createvisualtask,     // 0x03
    Cmd_delay,                // 0x04
    Cmd_waitforvisualfinish,  // 0x05
    Cmd_nop,                  // 0x06
    Cmd_nop2,                 // 0x07
    Cmd_end,                  // 0x08
    Cmd_playse,               // 0x09
    Cmd_monbg,                // 0x0A
    Cmd_clearmonbg,           // 0x0B
    Cmd_setalpha,             // 0x0C
    Cmd_blendoff,             // 0x0D
    Cmd_call,                 // 0x0E
    Cmd_return,               // 0x0F
    Cmd_setarg,               // 0x10
    Cmd_choosetwoturnanim,    // 0x11
    Cmd_jumpifmoveturn,       // 0x12
    Cmd_goto,                 // 0x13
    Cmd_fadetobg,             // 0x14
    Cmd_restorebg,            // 0x15
    Cmd_waitbgfadeout,        // 0x16
    Cmd_waitbgfadein,         // 0x17
    Cmd_changebg,             // 0x18
    Cmd_playsewithpan,        // 0x19
    Cmd_setpan,               // 0x1A
    Cmd_panse,                // 0x1B
    Cmd_loopsewithpan,        // 0x1C
    Cmd_waitplaysewithpan,    // 0x1D
    Cmd_setbldcnt,            // 0x1E
    Cmd_createsoundtask,      // 0x1F
    Cmd_waitsound,            // 0x20
    Cmd_jumpargeq,            // 0x21
    Cmd_monbg_static,         // 0x22
    Cmd_clearmonbg_static,    // 0x23
    Cmd_jumpifcontest,        // 0x24
    Cmd_fadetobgfromset,      // 0x25
    Cmd_panse_adjustnone,     // 0x26
    Cmd_panse_adjustall,      // 0x27
    Cmd_splitbgprio,          // 0x28
    Cmd_splitbgprio_all,      // 0x29
    Cmd_splitbgprio_foes,     // 0x2A
    Cmd_invisible,            // 0x2B
    Cmd_visible,              // 0x2C
    Cmd_teamattack_moveback,  // 0x2D
    Cmd_teamattack_movefwd,   // 0x2E
    Cmd_stopsound,            // 0x2F
    Cmd_createvisualtaskontargets,  // 0x30
    Cmd_createspriteontargets,      // 0x31
    Cmd_createspriteontargets_onpos, // 0x32
    Cmd_jumpifmovetypeequal,         // 0x33
    Cmd_createdragondartsprite,      // 0x34
    Cmd_unloadallspritepals,        // 0x35
};

static const u16 sMovesWithQuietBGM[] =
{
    MOVE_SING, MOVE_PERISH_SONG, MOVE_GRASS_WHISTLE
};

static const u8* const sBattleAnims_StatusConditions[NUM_B_ANIMS_STATUS] =
{
    [B_ANIM_STATUS_PSN]         = gBattleAnimStatus_Poison,
    [B_ANIM_STATUS_CONFUSION]   = gBattleAnimStatus_Confusion,
    [B_ANIM_STATUS_BRN]         = gBattleAnimStatus_Burn,
    [B_ANIM_STATUS_INFATUATION] = gBattleAnimStatus_Infatuation,
    [B_ANIM_STATUS_SLP]         = gBattleAnimStatus_Sleep,
    [B_ANIM_STATUS_PRZ]         = gBattleAnimStatus_Paralysis,
    [B_ANIM_STATUS_FRZ]         = gBattleAnimStatus_Freeze,
    [B_ANIM_STATUS_CURSED]      = gBattleAnimStatus_Curse,
    [B_ANIM_STATUS_NIGHTMARE]   = gBattleAnimStatus_Nightmare,
    [B_ANIM_STATUS_FRB]         = gBattleAnimStatus_Frostbite,
};

static const u8* const sBattleAnims_General[NUM_B_ANIMS_GENERAL] =
{
    [B_ANIM_STATS_CHANGE]           = gBattleAnimGeneral_StatsChange,
    [B_ANIM_SUBSTITUTE_FADE]        = gBattleAnimGeneral_SubstituteFade,
    [B_ANIM_SUBSTITUTE_APPEAR]      = gBattleAnimGeneral_SubstituteAppear,
    [B_ANIM_POKEBLOCK_THROW]        = gBattleAnimGeneral_PokeblockThrow,
    [B_ANIM_ITEM_KNOCKOFF]          = gBattleAnimGeneral_ItemKnockoff,
    [B_ANIM_TURN_TRAP]              = gBattleAnimGeneral_TurnTrap,
    [B_ANIM_HELD_ITEM_EFFECT]       = gBattleAnimGeneral_HeldItemEffect,
    [B_ANIM_SMOKEBALL_ESCAPE]       = gBattleAnimGeneral_SmokeballEscape,
    [B_ANIM_HANGED_ON]              = gBattleAnimGeneral_HangedOn,
    [B_ANIM_RAIN_CONTINUES]         = gBattleAnimGeneral_Rain,
    [B_ANIM_SUN_CONTINUES]          = gBattleAnimGeneral_Sun,
    [B_ANIM_SANDSTORM_CONTINUES]    = gBattleAnimGeneral_Sandstorm,
    [B_ANIM_HAIL_CONTINUES]         = gBattleAnimGeneral_Hail,
    [B_ANIM_LEECH_SEED_DRAIN]       = gBattleAnimGeneral_LeechSeedDrain,
    [B_ANIM_MON_HIT]                = gBattleAnimGeneral_MonHit,
    [B_ANIM_ITEM_STEAL]             = gBattleAnimGeneral_ItemSteal,
    [B_ANIM_SNATCH_MOVE]            = gBattleAnimGeneral_SnatchMove,
    [B_ANIM_FOCUS_PUNCH_SETUP]      = gBattleAnimGeneral_FocusPunchSetUp,
    [B_ANIM_INGRAIN_HEAL]           = gBattleAnimGeneral_IngrainHeal,
    [B_ANIM_WISH_HEAL]              = gBattleAnimGeneral_WishHeal,
    [B_ANIM_MEGA_EVOLUTION]         = gBattleAnimGeneral_MegaEvolution,
    [B_ANIM_ILLUSION_OFF]           = gBattleAnimGeneral_IllusionOff,
    [B_ANIM_FORM_CHANGE]            = gBattleAnimGeneral_FormChange,
    [B_ANIM_FORM_CHANGE_INSTANT]    = gBattleAnimGeneral_FormChangeInstant,
    [B_ANIM_FORM_CHANGE_DISGUISE]   = gBattleAnimGeneral_FormChangeDisguise,
    [B_ANIM_SLIDE_OFFSCREEN]        = gBattleAnimGeneral_SlideOffScreen,
    [B_ANIM_RESTORE_BG]             = gBattleAnimGeneral_RestoreBg,
    [B_ANIM_TOTEM_FLARE]            = gBattleAnimGeneral_TotemFlare,
    [B_ANIM_GULP_MISSILE]           = gBattleAnimGeneral_GulpMissile,
    [B_ANIM_STRONG_WINDS]           = gBattleAnimGeneral_StrongWinds,
    [B_ANIM_PRIMAL_REVERSION]       = gBattleAnimGeneral_PrimalReversion,
    [B_ANIM_AQUA_RING_HEAL]         = gBattleAnimGeneral_AquaRingHeal,
    [B_ANIM_BEAK_BLAST_SETUP]       = gBattleAnimGeneral_BeakBlastSetUp,
    [B_ANIM_SHELL_TRAP_SETUP]       = gBattleAnimGeneral_ShellTrapSetUp,
    [B_ANIM_ZMOVE_ACTIVATE]         = gBattleAnimGeneral_ZMoveActivate,
    [B_ANIM_AFFECTION_HANGED_ON]    = gBattleAnimGeneral_AffectionHangedOn,
    [B_ANIM_SNOW_CONTINUES]         = gBattleAnimGeneral_Snow,
    [B_ANIM_ULTRA_BURST]            = gBattleAnimGeneral_UltraBurst,
    [B_ANIM_SALT_CURE_DAMAGE]       = gBattleAnimGeneral_SaltCureDamage,
    [B_ANIM_DYNAMAX_GROWTH]         = gBattleAnimGeneral_DynamaxGrowth,
    [B_ANIM_MAX_SET_WEATHER]        = gBattleAnimGeneral_SetWeather,
    [B_ANIM_SYRUP_BOMB_SPEED_DROP]  = gBattleAnimGeneral_SyrupBombSpeedDrop,
    [B_ANIM_RAINBOW]                = gBattleAnimGeneral_Rainbow,
    [B_ANIM_SEA_OF_FIRE]            = gBattleAnimGeneral_SeaOfFire,
    [B_ANIM_SWAMP]                  = gBattleAnimGeneral_Swamp,
    [B_ANIM_TRICK_ROOM]             = gBattleAnimGeneral_TrickRoom,
    [B_ANIM_WONDER_ROOM]            = gBattleAnimGeneral_WonderRoom,
    [B_ANIM_MAGIC_ROOM]             = gBattleAnimGeneral_MagicRoom,
    [B_ANIM_TAILWIND]               = gBattleAnimGeneral_Tailwind,
    [B_ANIM_FOG_CONTINUES]          = gBattleAnimGeneral_Fog,
    [B_ANIM_TERA_CHARGE]            = gBattleAnimGeneral_TeraCharge,
    [B_ANIM_TERA_ACTIVATE]          = gBattleAnimGeneral_TeraActivate,
    [B_ANIM_SIMPLE_HEAL]            = gBattleAnimGeneral_SimpleHeal,
    [B_ANIM_POWER_CONSTRUCT]        = gBattleAnimGeneral_PowerConstruct,
    [B_ANIM_SWAP_TO_SUBSTITUTE]     = gBattleAnimGeneral_SwapToSubstitute,
    [B_ANIM_SWAP_FROM_SUBSTITUTE]   = gBattleAnimGeneral_SwapFromSubstitute,
    [B_ANIM_MON_SCARED]             = gBattleAnimGeneral_MonScared,
    [B_ANIM_GHOST_GET_OUT]          = gBattleAnimGeneral_GhostGetOut,
    [B_ANIM_SILPH_SCOPED]           = gBattleAnimGeneral_SilphScoped,
    [B_ANIM_ROCK_THROW]             = gBattleAnimGeneral_SafariRockThrow,
    [B_ANIM_SAFARI_REACTION]        = gBattleAnimGeneral_SafariReaction,
    [B_ANIM_HELD_ITEM_BERRY]        = gBattleAnimGeneral_HeldItemBerry,
    [B_ANIM_PROTECTED_ITSELF]       = gBattleAnimGeneral_ProtectedItself,
};

static const u8* const sBattleAnims_Special[NUM_B_ANIMS_SPECIAL] =
{
    [B_ANIM_LVL_UP]                     = gBattleAnimSpecial_LevelUp,
    [B_ANIM_SWITCH_OUT_PLAYER_MON]      = gBattleAnimSpecial_SwitchOutPlayerMon,
    [B_ANIM_SWITCH_OUT_OPPONENT_MON]    = gBattleAnimSpecial_SwitchOutOpponentMon,
    [B_ANIM_BALL_THROW]                 = gBattleAnimSpecial_BallThrow,
    [B_ANIM_BALL_THROW_WITH_TRAINER]    = gBattleAnimSpecial_BallThrowWithTrainer,
    [B_ANIM_SUBSTITUTE_TO_MON]          = gBattleAnimSpecial_SubstituteToMon,
    [B_ANIM_MON_TO_SUBSTITUTE]          = gBattleAnimSpecial_MonToSubstitute,
    [B_ANIM_CRITICAL_CAPTURE_THROW]     = gBattleAnimSpecial_CriticalCaptureBallThrow,
};

void ClearBattleAnimationVars(void)
{
    sAnimFramesToWait = 0;
    gAnimScriptActive = FALSE;
    gAnimVisualTaskCount = 0;
    gAnimSoundTaskCount = 0;
    gAnimDisableStructPtr = NULL;
    gAnimMoveDmg = 0;
    gAnimMovePower = 0;
    gAnimFriendship = 0;

    // Clear index array.
    for (u32 i = 0; i < ANIM_SPRITE_GFX_COUNT; i++)
        sAnimSpriteGfxTags[i] = 0xFFFF;

    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT; i++)
        sAnimSpritePalTags[i] = 0xFFFF;

    // Clear anim args.
    for (u32 i = 0; i < ANIM_ARGS_COUNT; i++)
        gBattleAnimArgs[i] = 0;

    sMonAnimTaskIdArray[0] = TASK_NONE;
    sMonAnimTaskIdArray[1] = TASK_NONE;
    gAnimMoveTurn = 0;
    sAnimBackgroundFadeState = 0;
    gAnimMoveIndex = 0;
    gBattleAnimAttacker = 0;
    gBattleAnimTarget = 0;
    gAnimCustomPanning = 0;
}

void DoMoveAnim(enum Move move)
{
    gBattleAnimAttacker = gBattlerAttacker;
    gBattleAnimTarget = gBattlerTarget;
    // Make sure the anim target of moves hitting everyone is at the opposite side.
    if (GetBattlerMoveTargetType(gBattleAnimAttacker, move) == TARGET_FOES_AND_ALLY && IsDoubleBattle())
    {
        while (IsBattlerAlly(gBattleAnimAttacker, gBattleAnimTarget))
        {
            if (++gBattleAnimTarget >= MAX_BATTLERS_COUNT)
                gBattleAnimTarget = 0;
        }
    }
    LaunchBattleAnimation(ANIM_TYPE_MOVE, move);
}

static void Nop(void)
{
}

void LaunchBattleAnimation(u32 animType, u32 animId)
{
    s32 i;

    if (gTestRunnerEnabled)
    {
        TestRunner_Battle_RecordAnimation(animType, animId);

        bool32 forceMoveAnim = FALSE;
        #if TESTING // Because gBattleTestRunnerState is not seen outside of test env.
        forceMoveAnim = gBattleTestRunnerState->forceMoveAnim;
        #endif
        if (!forceMoveAnim)
        {
            enum { DEFAULT, PLAY, SKIP } mode = DEFAULT;
            if (animType == ANIM_TYPE_MOVE)
            {
                switch (animId)
                {
                // Play Transform and Ally Switch even in headless
                // because the animations also change mon data.
                case MOVE_TRANSFORM:
                case MOVE_ALLY_SWITCH:
                    mode = PLAY;
                    break;
                // Skip Celebrate even in non-headless because it's
                // very noisy.
                case MOVE_CELEBRATE:
                    mode = SKIP;
                    break;
                }
            }
            if ((mode == DEFAULT && gTestRunnerHeadless) || mode == SKIP)
            {
                gAnimScriptCallback = Nop;
                gAnimScriptActive = FALSE;
                return;
            }
        }
    }

    sAnimHideHpBoxes = !(animType == ANIM_TYPE_MOVE && animId == MOVE_TRANSFORM);
    if (animType != ANIM_TYPE_MOVE)
    {
        switch (animId)
        {
        case B_ANIM_TURN_TRAP:
        case B_ANIM_LEECH_SEED_DRAIN:
        case B_ANIM_MON_HIT:
        case B_ANIM_SNATCH_MOVE:
        case B_ANIM_WISH_HEAL:
        case B_ANIM_MEGA_EVOLUTION:
        case B_ANIM_PRIMAL_REVERSION:
        case B_ANIM_POWER_CONSTRUCT:
        case B_ANIM_ULTRA_BURST:
        case B_ANIM_GULP_MISSILE:
        case B_ANIM_RAINBOW:
        case B_ANIM_SEA_OF_FIRE:
        case B_ANIM_SWAMP:
        case B_ANIM_TERA_CHARGE:
            sAnimHideHpBoxes = TRUE;
            break;
        default:
            sAnimHideHpBoxes = FALSE;
            break;
        }
    }

    if (!IsContest())
    {
        InitPrioritiesForVisibleBattlers();
        UpdateOamPriorityInAllHealthboxes(0, sAnimHideHpBoxes);
        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            gAnimBattlerSpecies[i] = GetMonData(GetBattlerMon(i), MON_DATA_SPECIES);
    }
    else
    {
        for (i = 0; i < CONTESTANT_COUNT; i++)
            gAnimBattlerSpecies[i] = gContestResources->moveAnim->species;
    }

    if (animType != ANIM_TYPE_MOVE)
        gAnimMoveIndex = 0;
    else
        gAnimMoveIndex = animId;

    for (i = 0; i < ANIM_ARGS_COUNT; i++)
        gBattleAnimArgs[i] = 0;

    sMonAnimTaskIdArray[0] = TASK_NONE;
    sMonAnimTaskIdArray[1] = TASK_NONE;

    switch (animType)
    {
    case ANIM_TYPE_GENERAL:
    default:
        sBattleAnimScriptPtr = sBattleAnims_General[animId];
        break;
    case ANIM_TYPE_MOVE:
        sBattleAnimScriptPtr = GetMoveAnimationScript(animId);

        if (sBattleAnimScriptPtr == gBattleAnimMove_SecretPower)
        {
            if (gFieldTimers.terrain != B_TERRAIN_NONE)
                sBattleAnimScriptPtr = gBattleTerrainInfo[gFieldTimers.terrain].secretPowerAnimation;
            else
                sBattleAnimScriptPtr = gBattleEnvironmentInfo[gBattleEnvironment].secretPowerAnimation;
        }
        break;
    case ANIM_TYPE_STATUS:
        sBattleAnimScriptPtr = sBattleAnims_StatusConditions[animId];
        break;
    case ANIM_TYPE_SPECIAL:
        sBattleAnimScriptPtr = sBattleAnims_Special[animId];
        break;
    }
    gAnimScriptActive = TRUE;
    sAnimFramesToWait = 0;
    gAnimScriptCallback = RunAnimScriptCommand;

    for (u32 i = 0; i < ANIM_SPRITE_GFX_COUNT; i++)
        sAnimSpriteGfxTags[i] = 0xFFFF;

    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT; i++)
        sAnimSpritePalTags[i] = 0xFFFF;

    if (animType == ANIM_TYPE_MOVE)
    {
        for (i = 0; i < ARRAY_COUNT(sMovesWithQuietBGM); i++)
        {
            if (animId == sMovesWithQuietBGM[i])
            {
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 128);
                break;
            }
        }
    }

    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
}

void DestroyAnimSprite(struct Sprite *sprite)
{
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
    gAnimVisualTaskCount--;
}

void DestroyAnimVisualTask(u8 taskId)
{
    DestroyTask(taskId);
    gAnimVisualTaskCount--;
}

void DestroyAnimSoundTask(u8 taskId)
{
    DestroyTask(taskId);
    gAnimSoundTaskCount--;
}

bool32 StoreGfxTag(u32 tag)
{
    for (u32 i = 0; i < ANIM_SPRITE_GFX_COUNT; i++)
    {
        if (sAnimSpriteGfxTags[i] == 0xFFFF)
        {
            sAnimSpriteGfxTags[i] = tag;
            return TRUE;
        }
    }
    return FALSE;
}

bool32 StorePalTag(u32 tag)
{
    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT; i++)
    {
        if (sAnimSpritePalTags[i] == 0xFFFF)
        {
            sAnimSpritePalTags[i] = tag;
            return TRUE;
        }
    }
    return FALSE;
}

__attribute__((optimize("-O3"))) bool32 IsGfxLoaded(u32 tag)
{
    u32 tag2 = (tag << 16) | tag;
    u32 *tag2s = (u32 *)sAnimSpriteGfxTags;

    for (u32 i = 0; i < ANIM_SPRITE_GFX_COUNT / 2; i++)
    {
        u32 xor = tag2 ^ tag2s[i];
        if ((xor << 16) == 0)
            return 1;
        if ((xor >> 16) == 0)
            return 1;
    }
    return 0;
}

__attribute__((optimize("-O3"))) bool32 IsPalLoaded(u32 tag)
{
    u32 tag2 = (tag << 16) | tag;
    u32 *tag2s = (u32 *)sAnimSpritePalTags;

    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT / 2; i++)
    {
        u32 xor = tag2 ^ tag2s[i];
        if ((xor << 16) == 0)
            return 1;
        if ((xor >> 16) == 0)
            return 1;
    }
    return 0;
}

bool32 TryLoadGfx(u32 tag)
{
    if (!IsGfxLoaded(tag))
    {
        if (StoreGfxTag(tag))
        {
            LoadCompressedSpriteSheetUsingHeap(&gBattleAnimTable[GET_TRUE_SPRITE_INDEX(tag)].pic);
            return TRUE;
        }
        else
        {
            assertf(FALSE, "failed to store gfx: %u", tag);
            return FALSE;
        }
    }
    else
    {
        return TRUE;
    }
}

bool32 TryLoadPal(u32 tag)
{
    if (!IsPalLoaded(tag))
    {
        if (StorePalTag(tag))
        {
            LoadSpritePalette(&gBattleAnimTable[GET_TRUE_SPRITE_INDEX(tag)].palette);
            return TRUE;
        }
        else
        {
            assertf(FALSE, "failed to store pal: %u", tag);
            return FALSE;
        }
    }
    else
    {
        return TRUE;
    }
}

bool32 TryLoadSpriteAssets(const struct SpriteTemplate *template)
{
    return TryLoadPal(template->paletteTag) && TryLoadGfx(template->tileTag);
}

static void WaitAnimFrameCount(void)
{
    if (sAnimFramesToWait <= 0)
    {
        gAnimScriptCallback = RunAnimScriptCommand;
        sAnimFramesToWait = 0;
    }
    else
    {
        sAnimFramesToWait--;
    }
}

static void RunAnimScriptCommand(void)
{
    do
    {
        sScriptCmdTable[sBattleAnimScriptPtr[0]]();
    } while (sAnimFramesToWait == 0 && gAnimScriptActive);
}

static void ClearSpriteGfxIndex(u32 tag)
{
    for (u32 i = 0; i < ANIM_SPRITE_GFX_COUNT; i++)
    {
        if (tag == sAnimSpriteGfxTags[i])
        {
            sAnimSpriteGfxTags[i] = 0xFFFF;
            return;
        }
    }
}

static void ClearSpritePalIndex(u32 tag)
{
    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT; i++)
    {
        if (tag == sAnimSpritePalTags[i])
        {
            sAnimSpritePalTags[i] = 0xFFFF;
            return;
        }
    }
}

static void Cmd_unloadspritegfx(void)
{
    sBattleAnimScriptPtr++;
    u16 index = T1_READ_16(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 2;
    if (IsGfxLoaded(index))
    {
        FreeSpriteTilesByTag(index);
        ClearSpriteGfxIndex(index);
    }
}

static void Cmd_unloadspritepal(void)
{
    sBattleAnimScriptPtr++;
    u16 index = T1_READ_16(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 2;
    if (IsPalLoaded(index))
    {
        FreeSpritePaletteByTag(index);
        ClearSpritePalIndex(index);
    }
}

static void UnloadAllSpritePalettes(void)
{
    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT; i++)
    {
        if (sAnimSpritePalTags[i] != 0xFFFF)
        {
            u32 index = sAnimSpritePalTags[i];
            FreeSpritePaletteByTag(index);
            sAnimSpritePalTags[i] = 0xFFFF;
        }
    }
}

static void Cmd_unloadallspritepals(void)
{
    sBattleAnimScriptPtr++;
    UnloadAllSpritePalettes();
}

static u8 GetBattleAnimMoveTargets(u8 battlerArgIndex, enum BattlerId *targets)
{
    u8 numTargets = 0;
    enum AnimBattler battlerAnimId = gBattleAnimArgs[battlerArgIndex];   // ANIM_xx input
    enum BattlerId i;
    enum BattlerId ignoredTgt;
    enum MoveTarget target = GetBattlerMoveTargetType(gBattleAnimAttacker, gAnimMoveIndex);

    switch (battlerAnimId)
    {
    case ANIM_ATTACKER:
    case ANIM_ATK_PARTNER:
        ignoredTgt = gBattlerTarget;
        break;
    case ANIM_TARGET:
    case ANIM_DEF_PARTNER:
    default:
        ignoredTgt = gBattlerAttacker;
        break;
    }

    switch (target)
    {
    case TARGET_FOES_AND_ALLY:
        if (battlerAnimId == ANIM_ATTACKER)
        {
            targets[numTargets++] = gBattleAnimAttacker;
        }
        else
        {
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i != gBattleAnimAttacker && IS_ALIVE_AND_PRESENT(i))
                    targets[numTargets++] = i + MAX_BATTLERS_COUNT; // anim ids for battler ids
            }
        }
        break;
    case TARGET_BOTH: // all opponents
        for (i = 0; i < gBattlersCount; i++)
        {
            if (i != ignoredTgt && !IsBattlerAlly(i, ignoredTgt) && IS_ALIVE_AND_PRESENT(i))
                targets[numTargets++] = i + MAX_BATTLERS_COUNT;
        }
        break;
    default:
        targets[0] = gBattleAnimArgs[battlerArgIndex]; // original
        numTargets = 1;
        break;
    }

    return numTargets;
}

static s16 GetSubpriorityForMoveAnim(u8 argVar)
{
    s16 subpriority;

    if (argVar & ANIMSPRITE_IS_TARGET)
    {
        argVar ^= ANIMSPRITE_IS_TARGET;
        if (argVar >= 64)
            argVar -= 64;
        else
            argVar *= -1;

        subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + (s8)(argVar);
    }
    else
    {
        if (argVar >= 64)
            argVar -= 64;
        else
            argVar *= -1;

        subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + (s8)(argVar);
    }

    if (subpriority < 3)
        subpriority = 3;

    return subpriority;
}

static void Cmd_createsprite(void)
{
    s32 i;
    const struct SpriteTemplate *template;
    u8 argVar;
    u8 argsCount;
    s16 subpriority;

    sBattleAnimScriptPtr++;
    template = (const struct SpriteTemplate *)(T2_READ_32(sBattleAnimScriptPtr));
    sBattleAnimScriptPtr += 4;

    argVar = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    argsCount = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    for (i = 0; i < argsCount; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    if (template->tileTag != 0)
        if (!TryLoadGfx(template->tileTag))
            return;
    if (template->paletteTag != 0)
        if (!TryLoadPal(template->paletteTag))
            return;

    subpriority = GetSubpriorityForMoveAnim(argVar);

    if (CreateSpriteAndAnimate(template,
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2),
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET),
        subpriority) != MAX_SPRITES) // Don't increment the task count if the sprite couldn't be created(i.e. there are too many created sprites atm).
     {
         gAnimVisualTaskCount++;
     }
}

static void CreateSpriteOnTargets(const struct SpriteTemplate *template, u8 argVar, u8 battlerArgIndex, u8 argsCount, bool32 overwriteAnimTgt)
{
    u32 i;
    enum BattlerId battler;
    enum BattlerId targets[MAX_BATTLERS_COUNT];
    int ntargets;
    s16 subpriority;

    for (i = 0; i < argsCount; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    subpriority = GetSubpriorityForMoveAnim(argVar);

    ntargets = GetBattleAnimMoveTargets(battlerArgIndex, targets);
    if (ntargets == 0)
        return;

    for (i = 0; i < ntargets; i++)
    {
        battler = GetAnimBattlerId((enum AnimBattler)targets[i]);
        if (overwriteAnimTgt)
            gBattleAnimArgs[battlerArgIndex] = targets[i];

        if (CreateSpriteAndAnimate(template,
            GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2),
            GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET),
            subpriority) != MAX_SPRITES) // Don't increment the task count if the sprite couldn't be created(i.e. there are too many created sprites atm).
        {
            gAnimVisualTaskCount++;
        }
    }
}

// will NOT overwrite gBattleAnimArgs
static void Cmd_createspriteontargets_onpos(void)
{
    const struct SpriteTemplate *template;
    u8 argVar;
    u8 argsCount;
    u8 battlerArgIndex;

    sBattleAnimScriptPtr++;
    template = (const struct SpriteTemplate *)(T2_READ_32(sBattleAnimScriptPtr));
    sBattleAnimScriptPtr += 4;

    argVar = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    battlerArgIndex = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    argsCount = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    if (!TryLoadSpriteAssets(template))
    {
        sBattleAnimScriptPtr += 2 * argsCount;
        return;
    }

    CreateSpriteOnTargets(template, argVar, battlerArgIndex, argsCount, FALSE);
}

// DOES overwrite gBattleAnimArgs
static void Cmd_createspriteontargets(void)
{
    const struct SpriteTemplate *template;
    u8 argVar;
    u8 argsCount;
    u8 battlerArgIndex;

    sBattleAnimScriptPtr++;
    template = (const struct SpriteTemplate *)(T2_READ_32(sBattleAnimScriptPtr));
    sBattleAnimScriptPtr += 4;

    argVar = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    battlerArgIndex = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    argsCount = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    if (!TryLoadSpriteAssets(template))
    {
        sBattleAnimScriptPtr += 2 * argsCount;
        return;
    }

    CreateSpriteOnTargets(template, argVar, battlerArgIndex, argsCount, TRUE);
}

static void Cmd_createvisualtask(void)
{
    TaskFunc taskFunc;
    u8 taskPriority;
    u8 taskId;
    u8 numArgs;
    s32 i;

    sBattleAnimScriptPtr++;

    taskFunc = (TaskFunc)T2_READ_32(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 4;

    taskPriority = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    numArgs = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    for (i = 0; i < numArgs; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    taskId = CreateTask(taskFunc, taskPriority);
    taskFunc(taskId);
    gAnimVisualTaskCount++;
}

static void Cmd_createvisualtaskontargets(void)
{
    TaskFunc taskFunc;
    u8 taskPriority;
    u8 taskId;
    u8 numArgs;
    u8 battlerArgIndex; // index in gBattleAnimArgs that has the battlerId
    s32 i;
    enum BattlerId targets[MAX_BATTLERS_COUNT] = {0};

    sBattleAnimScriptPtr++;

    taskFunc = (TaskFunc)T2_READ_32(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 4;

    taskPriority = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    battlerArgIndex = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    numArgs = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    // copy task arguments
    for (i = 0; i < numArgs; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    numArgs = GetBattleAnimMoveTargets(battlerArgIndex, targets);
    if (numArgs == 0)
        return;

    for (i = 0; i < numArgs; i++)
    {
        gBattleAnimArgs[battlerArgIndex] = targets[i];
        taskId = CreateTask(taskFunc, taskPriority);
        taskFunc(taskId);
        gAnimVisualTaskCount++;
    }
}


static void Cmd_delay(void)
{
    sBattleAnimScriptPtr++;
    sAnimFramesToWait = sBattleAnimScriptPtr[0];
    if (sAnimFramesToWait == 0)
        sAnimFramesToWait = -1;
    sBattleAnimScriptPtr++;
    gAnimScriptCallback = WaitAnimFrameCount;
}

// Wait for visual tasks to finish.
static void Cmd_waitforvisualfinish(void)
{
    if (gAnimVisualTaskCount == 0)
    {
        sBattleAnimScriptPtr++;
        sAnimFramesToWait = 0;
    }
    else
    {
        sAnimFramesToWait = 1;
    }
}

static void Cmd_nop(void)
{
}

static void Cmd_nop2(void)
{
}

static void Cmd_end(void)
{
    bool32 continuousAnim = FALSE;

    assertf(sBattleAnimScriptCallDepth == 0, "Call depth not 0 at end of move animation");

    // Keep waiting as long as there are animations to be done.
    if (gAnimVisualTaskCount != 0 || gAnimSoundTaskCount != 0
     || sMonAnimTaskIdArray[0] != TASK_NONE || sMonAnimTaskIdArray[1] != TASK_NONE)
    {
        sSoundAnimFramesToWait = 0;
        sAnimFramesToWait = 1;
        return;
    }

    // Finish the sound effects.
    if (IsSEPlaying())
    {
        if (++sSoundAnimFramesToWait <= 90) // Wait 90 frames, then halt the sound effect.
        {
            sAnimFramesToWait = 1;
            return;
        }
        else
        {
            m4aMPlayStop(&gMPlayInfo_SE1);
            m4aMPlayStop(&gMPlayInfo_SE2);
        }
    }

    // The SE has halted, so set the SE Frame Counter to 0 and continue.
    sSoundAnimFramesToWait = 0;

    for (u32 i = 0; i < ANIM_SPRITE_GFX_COUNT; i++)
    {
        if (sAnimSpriteGfxTags[i] != 0xFFFF)
        {
            u32 index = sAnimSpriteGfxTags[i];
            FreeSpriteTilesByTag(index);
            sAnimSpriteGfxTags[i] = 0xFFFF;
        }
    }

    for (u32 i = 0; i < ANIM_SPRITE_PAL_COUNT; i++)
    {
        if (sAnimSpritePalTags[i] != 0xFFFF)
        {
            u32 index = sAnimSpritePalTags[i];
            FreeSpritePaletteByTag(index);
            sAnimSpritePalTags[i] = 0xFFFF;
        }
    }

    if (!continuousAnim) // May have been used for debug?
    {
        assertf(!FuncIsActiveTask(Task_UpdateMonBg), "move %d still has Task_UpdateMonBg active at the end", gAnimMoveIndex);

        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        if (!IsContest())
        {
            InitPrioritiesForVisibleBattlers();
            UpdateOamPriorityInAllHealthboxes(1, sAnimHideHpBoxes);
            sAnimHideHpBoxes = FALSE;
        }
        gAnimScriptActive = FALSE;
    }
}

static void Cmd_playse(void)
{
    sBattleAnimScriptPtr++;
    PlaySE(T1_READ_16(sBattleAnimScriptPtr));
    sBattleAnimScriptPtr += 2;
}

// These two tasks share context and similar task data
// To differentiate them the task data for Task_UpdateMonBg is prefixed t2

// Task data for Task_InitUpdateMonBg
#define tBattlerId  data[0]
#define tInBg2      data[1]
#define tActive     data[2]
#define tIsPartner  data[3]

// Task data for Task_UpdateMonBg
#define t2_SpriteId  data[0]
#define t2_SpriteX   data[1]
#define t2_SpriteY   data[2]
#define t2_BgX       data[3]
#define t2_BgY       data[4]
#define t2_InBg2     data[5]
#define t2_BattlerId data[6]

static void Task_InitUpdateMonBg(u8 taskId)
{
    u8 updateTaskId;

    s16 *data = gTasks[taskId].data;
    u8 battlerSpriteId = gBattlerSpriteIds[tBattlerId];
    gSprites[battlerSpriteId].invisible = TRUE;

    if (!tActive)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    updateTaskId = CreateTask(Task_UpdateMonBg, 10);
    gTasks[updateTaskId].t2_SpriteId = battlerSpriteId;
    gTasks[updateTaskId].t2_SpriteX = gSprites[battlerSpriteId].x + gSprites[battlerSpriteId].x2;
    gTasks[updateTaskId].t2_SpriteY = gSprites[battlerSpriteId].y + gSprites[battlerSpriteId].y2;

    if (!tInBg2)
    {
        gTasks[updateTaskId].t2_BgX = gBattle_BG1_X;
        gTasks[updateTaskId].t2_BgY = gBattle_BG1_Y;
    }
    else
    {
        gTasks[updateTaskId].t2_BgX = gBattle_BG2_X;
        gTasks[updateTaskId].t2_BgY = gBattle_BG2_Y;
    }

    assertf(sMonAnimTaskIdArray[tIsPartner] == TASK_NONE, "Duplicate monbg without clearmonbg");

    gTasks[updateTaskId].t2_InBg2 = tInBg2;
    gTasks[updateTaskId].t2_BattlerId = tBattlerId;
    sMonAnimTaskIdArray[tIsPartner] = updateTaskId;
    DestroyAnimVisualTask(taskId);
}

static void Cmd_monbg(void)
{
    bool8 toBG_2;
    u8 taskId;
    enum BattlerId battler;
    enum AnimBattler animBattler;

    sBattleAnimScriptPtr++;

    animBattler = sBattleAnimScriptPtr[0];
    if (animBattler & ANIM_TARGET)
        battler = gBattleAnimTarget;
    else
        battler = gBattleAnimAttacker;

    // Move designated battler to background
    if (IsBattlerSpriteVisible(battler))
    {
        enum BattlerPosition position = GetBattlerPosition(battler);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battler, toBG_2, FALSE);
        taskId = CreateTask(Task_InitUpdateMonBg, 10);
        gAnimVisualTaskCount++;
        gTasks[taskId].tBattlerId = battler;
        gTasks[taskId].tInBg2 = toBG_2;
        gTasks[taskId].tActive = TRUE;
        gTasks[taskId].tIsPartner = FALSE;

    }

    // Move battler's partner to background
    battler ^= BIT_FLANK;
    if (IsBattlerSpriteVisible(battler))
    {
        enum BattlerPosition position = GetBattlerPosition(battler);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battler, toBG_2, FALSE);
        taskId = CreateTask(Task_InitUpdateMonBg, 10);
        gAnimVisualTaskCount++;
        gTasks[taskId].tBattlerId = battler;
        gTasks[taskId].tInBg2 = toBG_2;
        gTasks[taskId].tActive = TRUE;
        gTasks[taskId].tIsPartner = TRUE;
    }

    sBattleAnimScriptPtr++;
    sAnimFramesToWait = 1;
    gAnimScriptCallback = WaitAnimFrameCount;
}

enum BattlerId GetAnimBattlerId(enum AnimBattler wantedBattler)
{
    switch (wantedBattler)
    {
    case ANIM_ATTACKER:
    default:
        return gBattleAnimAttacker;
    case ANIM_TARGET:
        return gBattleAnimTarget;
    case ANIM_ATK_PARTNER:
        return GetPartnerBattler(gBattleAnimAttacker);
    case ANIM_DEF_PARTNER:
        return GetPartnerBattler(gBattleAnimTarget);
    case ANIM_PLAYER_LEFT ... ANIM_OPPONENT_RIGHT:
        return wantedBattler - MAX_BATTLERS_COUNT;
    }
}

bool8 IsBattlerSpriteVisible(enum BattlerId battler)
{
    if (IsContest())
    {
        if (battler == gBattleAnimAttacker)
            return TRUE;
        else
            return FALSE;
    }
    if (!IsBattlerSpritePresent(battler))
        return FALSE;
    if (IsContest())
        return TRUE; // This line won't ever be reached.
    if (!gBattleSpritesDataPtr->battlerData[battler].invisible || !gSprites[gBattlerSpriteIds[battler]].invisible)
        return TRUE;

    return FALSE;
}

void MoveBattlerSpriteToBG(enum BattlerId battler, bool8 toBG_2, bool8 setSpriteInvisible)
{
    struct BattleAnimBgData animBg;
    u8 battlerSpriteId;

    if (!toBG_2)
    {
        enum BattlerPosition battlerPosition;

        if (IsContest() == TRUE)
        {
            RequestDma3Fill(0, (void *)(BG_SCREEN_ADDR(16)), 0x2000, 1);
            RequestDma3Fill(0xFF, (void *)(BG_SCREEN_ADDR(30)), 0x1000, 0);
        }
        else
        {
            RequestDma3Fill(0, (void *)(BG_SCREEN_ADDR(8)), 0x2000, 1);
            RequestDma3Fill(0xFF, (void *)(BG_SCREEN_ADDR(28)), 0x1000, 0);
        }

        GetBattleAnimBg1Data(&animBg);
        CpuFill16(0, animBg.bgTiles, 0x1000);
        CpuFill16(0xFF, animBg.bgTilemap, 0x800);

        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 2);
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 0);

        battlerSpriteId = gBattlerSpriteIds[battler];

        gBattle_BG1_X =  -(gSprites[battlerSpriteId].x + gSprites[battlerSpriteId].x2) + 0x20;
        if (IsContest() && IsSpeciesNotUnown(gContestResources->moveAnim->species))
            gBattle_BG1_X--;

        gBattle_BG1_Y =  -(gSprites[battlerSpriteId].y + gSprites[battlerSpriteId].y2) + 0x20;
        if (setSpriteInvisible)
            gSprites[gBattlerSpriteIds[battler]].invisible = TRUE;

        SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
        SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

        LoadPalette(&gPlttBufferUnfaded[OBJ_PLTT_ID(battler)], BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);
        CpuCopy32(&gPlttBufferUnfaded[OBJ_PLTT_ID(battler)], (void *)(BG_PLTT + PLTT_OFFSET_4BPP(animBg.paletteId)), PLTT_SIZE_4BPP);

        if (IsContest())
            battlerPosition = 0;
        else
            battlerPosition = GetBattlerPosition(battler);

        DrawBattlerOnBg(1, 0, 0, battlerPosition, animBg.paletteId, animBg.bgTiles, animBg.bgTilemap, animBg.tilesOffset);

        if (IsContest())
            FlipBattlerBgTiles();
    }
    else
    {
        RequestDma3Fill(0, (void *)(BG_SCREEN_ADDR(12)), 0x2000, 1);
        RequestDma3Fill(0, (void *)(BG_SCREEN_ADDR(30)), 0x1000, 1);
        GetBattleAnimBgData(&animBg, 2);
        CpuFill16(0, animBg.bgTiles + 0x1000, 0x1000);
        CpuFill16(0, animBg.bgTilemap + 0x400, 0x800);
        SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
        SetAnimBgAttribute(2, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(2, BG_ANIM_AREA_OVERFLOW_MODE, 0);

        battlerSpriteId = gBattlerSpriteIds[battler];

        gBattle_BG2_X =  -(gSprites[battlerSpriteId].x + gSprites[battlerSpriteId].x2) + 0x20;
        gBattle_BG2_Y =  -(gSprites[battlerSpriteId].y + gSprites[battlerSpriteId].y2) + 0x20;

        if (setSpriteInvisible)
            gSprites[gBattlerSpriteIds[battler]].invisible = TRUE;

        SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
        SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);

        LoadPalette(&gPlttBufferUnfaded[OBJ_PLTT_ID(battler)], BG_PLTT_ID(9), PLTT_SIZE_4BPP);
        CpuCopy32(&gPlttBufferUnfaded[OBJ_PLTT_ID(battler)], (void *)(BG_PLTT + PLTT_OFFSET_4BPP(9)), PLTT_SIZE_4BPP);

        DrawBattlerOnBg(2, 0, 0, GetBattlerPosition(battler), animBg.paletteId, animBg.bgTiles + 0x1000, animBg.bgTilemap + 0x400, animBg.tilesOffset);
    }
}

static void FlipBattlerBgTiles(void)
{
    s32 i, j;
    struct BattleAnimBgData animBg;
    u16 *ptr;

    if (IsSpeciesNotUnown(gContestResources->moveAnim->species))
    {
        GetBattleAnimBg1Data(&animBg);
        ptr = animBg.bgTilemap;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 4; j++)
            {
                u16 temp;
                SWAP(ptr[j + i * 32], ptr[7 - j + i * 32], temp);
            }
        }
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
                ptr[j + i * 32] ^= 0x400;
        }
    }
}

void RelocateBattleBgPal(u16 paletteNum, u16 *dest, u32 offset, bool8 largeScreen)
{
    s32 i, j;
    s32 size;

    if (!largeScreen)
        size = 32;
    else
        size = 64;
    paletteNum <<= 12;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 32; j++)
            dest[j + i * 32] = ((dest[j + i * 32] & 0xFFF) | paletteNum) + offset;
    }
}

void ResetBattleAnimBg(bool8 toBG2)
{
    struct BattleAnimBgData animBg;
    GetBattleAnimBg1Data(&animBg);

    if (!toBG2 || IsContest())
    {
        ClearBattleAnimBg(1);
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
    }
    else
    {
        ClearBattleAnimBg(2);
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
    }
}

static void Task_UpdateMonBg(u8 taskId)
{
    u8 spriteId, battler;
    s16 x, y;
    struct BattleAnimBgData animBg;

    spriteId = gTasks[taskId].t2_SpriteId;
    battler = gTasks[taskId].t2_BattlerId;
    GetBattleAnimBg1Data(&animBg);
    x = gTasks[taskId].t2_SpriteX - (gSprites[spriteId].x + gSprites[spriteId].x2);
    y = gTasks[taskId].t2_SpriteY - (gSprites[spriteId].y + gSprites[spriteId].y2);

    if (!gTasks[taskId].t2_InBg2)
    {
        gBattle_BG1_X = x + gTasks[taskId].t2_BgX;
        gBattle_BG1_Y = y + gTasks[taskId].t2_BgY;
        CpuCopy32(&gPlttBufferFaded[OBJ_PLTT_ID(battler)], &gPlttBufferFaded[BG_PLTT_ID(animBg.paletteId)], PLTT_SIZE_4BPP);
    }
    else
    {
        gBattle_BG2_X = x + gTasks[taskId].t2_BgX;
        gBattle_BG2_Y = y + gTasks[taskId].t2_BgY;
        CpuCopy32(&gPlttBufferFaded[OBJ_PLTT_ID(battler)], &gPlttBufferFaded[BG_PLTT_ID(9)], PLTT_SIZE_4BPP);
    }
}

#undef tBattlerId
#undef tInBg2
#undef tActive
#undef tIsPartner

#undef t2_SpriteId
#undef t2_SpriteX
#undef t2_SpriteY
#undef t2_BgX
#undef t2_BgY
#undef t2_InBg2
#undef t2_BattlerId

static void Cmd_clearmonbg(void)
{
    enum AnimBattler animBattlerId;
    enum BattlerId battler;
    u8 taskId;

    sBattleAnimScriptPtr++;
    animBattlerId = sBattleAnimScriptPtr[0];

    if (animBattlerId == ANIM_ATTACKER)
        animBattlerId = ANIM_ATK_PARTNER;
    else if (animBattlerId == ANIM_TARGET)
        animBattlerId = ANIM_DEF_PARTNER;

    if (animBattlerId == ANIM_ATTACKER || animBattlerId == ANIM_ATK_PARTNER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (sMonAnimTaskIdArray[0] != TASK_NONE)
        gSprites[gBattlerSpriteIds[battler]].invisible = FALSE;
    if (animBattlerId > 1 && sMonAnimTaskIdArray[1] != TASK_NONE)
        gSprites[gBattlerSpriteIds[GetPartnerBattler(battler)]].invisible = FALSE;
    else
        animBattlerId = 0;

    taskId = CreateTask(Task_ClearMonBg, 5);
    gTasks[taskId].data[0] = animBattlerId;
    gTasks[taskId].data[2] = battler;

    sBattleAnimScriptPtr++;
}

static void Task_ClearMonBg(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] != 1)
    {
        u8 to_BG2;
        enum BattlerPosition position = GetBattlerPosition(gTasks[taskId].data[2]);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            to_BG2 = FALSE;
        else
            to_BG2 = TRUE;

        if (sMonAnimTaskIdArray[0] != TASK_NONE)
        {
            ResetBattleAnimBg(to_BG2);
            DestroyTask(sMonAnimTaskIdArray[0]);
            sMonAnimTaskIdArray[0] = TASK_NONE;
        }
        if (gTasks[taskId].data[0] > 1)
        {
            ResetBattleAnimBg(to_BG2 ^ 1);
            DestroyTask(sMonAnimTaskIdArray[1]);
            sMonAnimTaskIdArray[1] = TASK_NONE;
        }
        DestroyTask(taskId);
    }
}

// Equivalent to Cmd_monbg but never creates Task_InitUpdateMonBg / Task_UpdateMonBg
static void Cmd_monbg_static(void)
{
    bool8 toBG_2;
    enum BattlerId battler;
    enum AnimBattler animBattlerId;

    sBattleAnimScriptPtr++;

    animBattlerId = sBattleAnimScriptPtr[0];

    if (animBattlerId == ANIM_ATTACKER)
        animBattlerId = ANIM_ATK_PARTNER;
    else if (animBattlerId == ANIM_TARGET)
        animBattlerId = ANIM_DEF_PARTNER;

    if (animBattlerId == ANIM_ATTACKER || animBattlerId == ANIM_ATK_PARTNER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (IsBattlerSpriteVisible(battler))
    {
        enum BattlerPosition position = GetBattlerPosition(battler);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battler, toBG_2, FALSE);
    }

    battler ^= BIT_FLANK;
    if (animBattlerId > 1 && IsBattlerSpriteVisible(battler))
    {
        enum BattlerPosition position = GetBattlerPosition(battler);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battler, toBG_2, FALSE);
    }

    sBattleAnimScriptPtr++;
}

static void Cmd_clearmonbg_static(void)
{
    enum AnimBattler animBattlerId;
    enum BattlerId battler;
    u8 taskId;

    sBattleAnimScriptPtr++;
    animBattlerId = sBattleAnimScriptPtr[0];

    if (animBattlerId == ANIM_ATTACKER)
        animBattlerId = ANIM_ATK_PARTNER;
    else if (animBattlerId == ANIM_TARGET)
        animBattlerId = ANIM_DEF_PARTNER;

    if (animBattlerId == ANIM_ATTACKER || animBattlerId == ANIM_ATK_PARTNER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (IsBattlerSpriteVisible(battler))
        gSprites[gBattlerSpriteIds[battler]].invisible = FALSE;
    if (animBattlerId > 1 && IsBattlerSpriteVisible(GetPartnerBattler(battler)))
        gSprites[gBattlerSpriteIds[GetPartnerBattler(battler)]].invisible = FALSE;
    else
        animBattlerId = 0;

    taskId = CreateTask(Task_ClearMonBgStatic, 5);
    gTasks[taskId].data[0] = animBattlerId;
    gTasks[taskId].data[2] = battler;

    sBattleAnimScriptPtr++;
}

static void Task_ClearMonBgStatic(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] != 1)
    {
        bool8 toBG_2;
        enum BattlerId battler = gTasks[taskId].data[2];
        enum BattlerPosition position = GetBattlerPosition(battler);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        if (IsBattlerSpriteVisible(battler))
            ResetBattleAnimBg(toBG_2);
        if (gTasks[taskId].data[0] > 1 && IsBattlerSpriteVisible(GetPartnerBattler(battler)))
            ResetBattleAnimBg(toBG_2 ^ 1);

        DestroyTask(taskId);
    }
}

static void Cmd_setalpha(void)
{
    u16 half1, half2;

    sBattleAnimScriptPtr++;
    half1 = *(sBattleAnimScriptPtr++);
    half2 = *(sBattleAnimScriptPtr++) << 8;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, half1 | half2);
}

static void Cmd_setbldcnt(void)
{
    u16 half1, half2;

    sBattleAnimScriptPtr++;
    half1 = *(sBattleAnimScriptPtr++);
    half2 = *(sBattleAnimScriptPtr++) << 8;
    SetGpuReg(REG_OFFSET_BLDCNT, half1 | half2);
}

static void Cmd_blendoff(void)
{
    sBattleAnimScriptPtr++;
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
}

static void Cmd_call(void)
{
    assertf(sBattleAnimScriptCallDepth + 1 < MAX_ANIM_CALL_DEPTH, "Max animation call depth exceeded");
    sBattleAnimScriptPtr++;
    sBattleAnimScriptRetAddr[sBattleAnimScriptCallDepth++] = sBattleAnimScriptPtr + 4;
    sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

static void Cmd_return(void)
{
    assertf(sBattleAnimScriptCallDepth > 0, "return with empty call stack");
    sBattleAnimScriptPtr = sBattleAnimScriptRetAddr[sBattleAnimScriptCallDepth - 1];
    sBattleAnimScriptRetAddr[sBattleAnimScriptCallDepth] = 0;
    sBattleAnimScriptCallDepth--;
}

static void Cmd_setarg(void)
{
    // Save original address to return to
    // after the T1_READ_16, + 4.
    // They could have equivalently just advanced
    // sBattleAnimScriptPtr by 2 afterwards.
    const u8 *addr = sBattleAnimScriptPtr;
    u16 value;
    u8 argId;

    sBattleAnimScriptPtr++;
    argId = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    value = T1_READ_16(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr = addr + 4;
    gBattleAnimArgs[argId] = value;
}

static void Cmd_choosetwoturnanim(void)
{
    sBattleAnimScriptPtr++;
    if (gAnimMoveTurn & 1)
        sBattleAnimScriptPtr += 4;
    sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

static void Cmd_jumpifmoveturn(void)
{
    u8 toCheck;
    sBattleAnimScriptPtr++;
    toCheck = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    if (toCheck == gAnimMoveTurn)
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
    else
        sBattleAnimScriptPtr += 4;
}

static void Cmd_goto(void)
{
    sBattleAnimScriptPtr++;
    sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

// Uses of this function that rely on a TRUE return are expecting inBattle to not be ticked as defined in contest behavior.
// As a result, if misused, this function cannot reliably discern between field and contest status and could result in undefined behavior.
bool8 IsContest(void)
{
    if (!gMain.inBattle)
        return TRUE;
    else
        return FALSE;
}

#define tBackgroundId   data[0]
#define tState          data[10]

static void Cmd_fadetobg(void)
{
    u8 backgroundId;
    u8 taskId;

    sBattleAnimScriptPtr++;
    backgroundId = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    taskId = CreateTask(Task_FadeToBg, 5);
    gTasks[taskId].tBackgroundId = backgroundId;
    sAnimBackgroundFadeState = 1;
}

static void Cmd_fadetobgfromset(void)
{
    u8 bg1, bg2, bg3;
    u8 taskId;

    sBattleAnimScriptPtr++;
    bg1 = sBattleAnimScriptPtr[0];
    bg2 = sBattleAnimScriptPtr[1];
    bg3 = sBattleAnimScriptPtr[2];
    sBattleAnimScriptPtr += 3;
    taskId = CreateTask(Task_FadeToBg, 5);

    if (IsContest())
        gTasks[taskId].tBackgroundId = bg3;
    else if (IsOnPlayerSide(gBattleAnimTarget))
        gTasks[taskId].tBackgroundId = bg2;
    else
        gTasks[taskId].tBackgroundId = bg1;

    sAnimBackgroundFadeState = 1;
}

static void Task_FadeToBg(u8 taskId)
{
    if (gTasks[taskId].tState == 0)
    {
        BeginHardwarePaletteFade(0xE8, 0, 0, 16, 0);
        gTasks[taskId].tState++;
        return;
    }
    if (gPaletteFade.active)
        return;
    if (gTasks[taskId].tState == 1)
    {
        gTasks[taskId].tState++;
        sAnimBackgroundFadeState = 2;
    }
    else if (gTasks[taskId].tState == 2)
    {
        s16 bgId = gTasks[taskId].tBackgroundId;

        if (bgId == -1)
            LoadDefaultBg();
        else
            LoadMoveBg(bgId);

        BeginHardwarePaletteFade(0xE8, 0, 16, 0, 1);
        gTasks[taskId].tState++;
        return;
    }
    if (gPaletteFade.active)
        return;
    if (gTasks[taskId].tState == 3)
    {
        DestroyTask(taskId);
        sAnimBackgroundFadeState = 0;
    }
}

void LoadMoveBg(u16 bgId)
{
    if (IsContest())
    {
        void *decompressionBuffer = malloc_and_decompress(gBattleAnimBackgroundTable[bgId].tilemap, NULL);
        RelocateBattleBgPal(GetBattleBgPaletteNum(), decompressionBuffer, 0x100, FALSE);
        DmaCopy32(3, decompressionBuffer, (void *)BG_SCREEN_ADDR(26), 0x800);
        Free(decompressionBuffer);
        DecompressDataWithHeaderVram(gBattleAnimBackgroundTable[bgId].image, (void *)BG_SCREEN_ADDR(4));
        LoadPalette(gBattleAnimBackgroundTable[bgId].palette, BG_PLTT_ID(GetBattleBgPaletteNum()), PLTT_SIZE_4BPP);
    }
    else
    {
        DecompressDataWithHeaderVram(gBattleAnimBackgroundTable[bgId].tilemap, (void *)BG_SCREEN_ADDR(26));
        DecompressDataWithHeaderVram(gBattleAnimBackgroundTable[bgId].image, (void *)BG_CHAR_ADDR(2));
        LoadPalette(gBattleAnimBackgroundTable[bgId].palette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
    }
}

static void LoadDefaultBg(void)
{
    if (IsContest())
        LoadContestBgAfterMoveAnim();
    else if (B_TERRAIN_BG_CHANGE == TRUE && gFieldTimers.terrain != B_TERRAIN_NONE)
        DrawTerrainTypeBattleBackground();
    else
        DrawMainBattleBackground();
}

static void Cmd_restorebg(void)
{
    u8 taskId;

    sBattleAnimScriptPtr++;
    taskId = CreateTask(Task_FadeToBg, 5);
    gTasks[taskId].tBackgroundId = -1;
    sAnimBackgroundFadeState = 1;
}

#undef tBackgroundId
#undef tState

static void Cmd_waitbgfadeout(void)
{
    if (sAnimBackgroundFadeState == 2)
    {
        sBattleAnimScriptPtr++;
        sAnimFramesToWait = 0;
    }
    else
    {
        sAnimFramesToWait = 1;
    }
}

static void Cmd_waitbgfadein(void)
{
    if (sAnimBackgroundFadeState == 0)
    {
        sBattleAnimScriptPtr++;
        sAnimFramesToWait = 0;
    }
    else
    {
        sAnimFramesToWait = 1;
    }
}

static void Cmd_changebg(void)
{
    sBattleAnimScriptPtr++;
    LoadMoveBg(sBattleAnimScriptPtr[0]);
    sBattleAnimScriptPtr++;
}

s8 BattleAnimAdjustPanning(s8 pan)
{
    if (!IsContest() && gBattleSpritesDataPtr->healthBoxesData[gBattleAnimAttacker].statusAnimActive)
    {
        if (!IsOnPlayerSide(gBattleAnimAttacker))
            pan = SOUND_PAN_TARGET;
        else
            pan = SOUND_PAN_ATTACKER;
    }
    else if (IsContest())
    {
        if (gBattleAnimAttacker != gBattleAnimTarget || gBattleAnimAttacker != 2 || pan != SOUND_PAN_TARGET)
            pan *= -1;
    }
    else if (IsOnPlayerSide(gBattleAnimAttacker))
    {
        if (IsOnPlayerSide(gBattleAnimTarget))
        {
            if (pan == SOUND_PAN_TARGET)
                pan = SOUND_PAN_ATTACKER;
            else if (pan != SOUND_PAN_ATTACKER)
                pan *= -1;
        }
    }
    else if (!IsOnPlayerSide(gBattleAnimTarget))
    {
        if (pan == SOUND_PAN_ATTACKER)
            pan = SOUND_PAN_TARGET;
    }
    else
    {
        pan *= -1;
    }

    if (pan > SOUND_PAN_TARGET)
        pan = SOUND_PAN_TARGET;
    else if (pan < SOUND_PAN_ATTACKER)
        pan = SOUND_PAN_ATTACKER;

    return pan;
}

s8 BattleAnimAdjustPanning2(s8 pan)
{
    if (!IsContest() && gBattleSpritesDataPtr->healthBoxesData[gBattleAnimAttacker].statusAnimActive)
    {
        if (!IsOnPlayerSide(gBattleAnimAttacker))
            pan = SOUND_PAN_TARGET;
        else
            pan = SOUND_PAN_ATTACKER;
    }
    else
    {
        if (!IsOnPlayerSide(gBattleAnimAttacker) || IsContest())
            pan = -pan;
    }
    return pan;
}

s16 KeepPanInRange(s16 panArg, int oldPan)
{
    s16 pan = panArg;

    if (pan > SOUND_PAN_TARGET)
        pan = SOUND_PAN_TARGET;
    else if (pan < SOUND_PAN_ATTACKER)
        pan = SOUND_PAN_ATTACKER;

    return pan;
}

s16 CalculatePanIncrement(s16 sourcePan, s16 targetPan, s16 incrementPan)
{
    s16 ret;

    if (sourcePan < targetPan)
        ret = ((incrementPan < 0) ? -incrementPan : incrementPan);
    else if (sourcePan > targetPan)
        ret = -((incrementPan < 0) ? -incrementPan : incrementPan);
    else
        ret = 0;

    return ret;
}

static void Cmd_playsewithpan(void)
{
    u16 songId;
    s8 pan;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    pan = sBattleAnimScriptPtr[2];
    PlaySE12WithPanning(songId, BattleAnimAdjustPanning(pan));
    sBattleAnimScriptPtr += 3;
}

static void Cmd_setpan(void)
{
    s8 pan;

    sBattleAnimScriptPtr++;
    pan = sBattleAnimScriptPtr[0];
    SE12PanpotControl(BattleAnimAdjustPanning(pan));
    sBattleAnimScriptPtr++;
}

#define tInitialPan     data[0]
#define tTargetPan      data[1]
#define tIncrementPan   data[2]
#define tFramesToWait   data[3]
#define tCurrentPan     data[4]
#define tFrameCounter   data[8]

static void Cmd_panse(void)
{
    u16 songNum;
    s8 currentPanArg, incrementPan, incrementPanArg, currentPan, targetPan;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songNum = T1_READ_16(sBattleAnimScriptPtr);
    currentPanArg = sBattleAnimScriptPtr[2];
    incrementPan = sBattleAnimScriptPtr[3]; // targetPan, var is re-used
    incrementPanArg = sBattleAnimScriptPtr[4];
    framesToWait = sBattleAnimScriptPtr[5];

    currentPan = BattleAnimAdjustPanning(currentPanArg);
    targetPan = BattleAnimAdjustPanning(incrementPan);
    incrementPan = CalculatePanIncrement(currentPan, targetPan, incrementPanArg);

    taskId = CreateTask(Task_PanFromInitialToTarget, 1);
    gTasks[taskId].tInitialPan = currentPan;
    gTasks[taskId].tTargetPan = targetPan;
    gTasks[taskId].tIncrementPan = incrementPan;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tCurrentPan = currentPan;

    PlaySE12WithPanning(songNum, currentPan);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 6;
}

void Task_PanFromInitialToTarget(u8 taskId)
{
    bool32 destroyTask = FALSE;
    if (gTasks[taskId].tFrameCounter++ >= gTasks[taskId].tFramesToWait)
    {
        s16 pan;
        s16 initialPanning, targetPanning, currentPan, incrementPan;

        gTasks[taskId].tFrameCounter = 0;
        initialPanning = gTasks[taskId].tInitialPan;
        targetPanning = gTasks[taskId].tTargetPan;
        currentPan = gTasks[taskId].tCurrentPan;
        incrementPan = gTasks[taskId].tIncrementPan;
        pan = currentPan + incrementPan;
        gTasks[taskId].tCurrentPan = pan;

        if (incrementPan == 0) // If we're not incrementing, just cancel the task immediately.
        {
            destroyTask = TRUE;
        }
        else if (initialPanning < targetPanning) // Panning increasing.
        {
            if (pan >= targetPanning) // Target reached.
                destroyTask = TRUE;
        }
        else // Panning decreasing.
        {
            if (pan <= targetPanning) // Target reached.
                destroyTask = TRUE;
        }

        if (destroyTask)
        {
            pan = targetPanning;
            DestroyTask(taskId);
            gAnimSoundTaskCount--;
        }

        SE12PanpotControl(pan);
    }
}

static void Cmd_panse_adjustnone(void)
{
    u16 songId;
    s8 currentPan, targetPan, incrementPan;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    currentPan = sBattleAnimScriptPtr[2];
    targetPan = sBattleAnimScriptPtr[3];
    incrementPan = sBattleAnimScriptPtr[4];
    framesToWait = sBattleAnimScriptPtr[5];

    taskId = CreateTask(Task_PanFromInitialToTarget, 1);
    gTasks[taskId].tInitialPan = currentPan;
    gTasks[taskId].tTargetPan = targetPan;
    gTasks[taskId].tIncrementPan = incrementPan;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tCurrentPan = currentPan;

    PlaySE12WithPanning(songId, currentPan);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 6;
}

static void Cmd_panse_adjustall(void)
{
    u16 songId;
    s8 targetPanArg, incrementPanArg, currentPanArg, currentPan, targetPan, incrementPan;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    currentPanArg = sBattleAnimScriptPtr[2];
    targetPanArg = sBattleAnimScriptPtr[3];
    incrementPanArg = sBattleAnimScriptPtr[4];
    framesToWait = sBattleAnimScriptPtr[5];

    currentPan = BattleAnimAdjustPanning2(currentPanArg);
    targetPan = BattleAnimAdjustPanning2(targetPanArg);
    incrementPan = BattleAnimAdjustPanning2(incrementPanArg);

    taskId = CreateTask(Task_PanFromInitialToTarget, 1);
    gTasks[taskId].tInitialPan = currentPan;
    gTasks[taskId].tTargetPan = targetPan;
    gTasks[taskId].tIncrementPan = incrementPan;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tCurrentPan = currentPan;

    PlaySE12WithPanning(songId, currentPan);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 6;
}

#undef tInitialPan
#undef tTargetPan
#undef tIncrementPan
#undef tFramesToWait
#undef tCurrentPan
#undef tFrameCounter

#define tSongId         data[0]
#define tPanning        data[1]
#define tFramesToWait   data[2]
#define tNumberOfPlays  data[3]
#define tFrameCounter   data[8]

static void Cmd_loopsewithpan(void)
{
    u16 songId;
    s8 panningArg, panning;
    u8 framesToWait, numberOfPlays;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    panningArg = sBattleAnimScriptPtr[2];
    framesToWait = sBattleAnimScriptPtr[3];
    numberOfPlays = sBattleAnimScriptPtr[4];
    panning = BattleAnimAdjustPanning(panningArg);

    taskId = CreateTask(Task_LoopAndPlaySE, 1);
    gTasks[taskId].tSongId = songId;
    gTasks[taskId].tPanning = panning;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tNumberOfPlays = numberOfPlays;
    gTasks[taskId].tFrameCounter = framesToWait;
    gTasks[taskId].func(taskId);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 5;
}

static void Task_LoopAndPlaySE(u8 taskId)
{
    if (gTasks[taskId].tFrameCounter++ >= gTasks[taskId].tFramesToWait)
    {
        u16 songId;
        s8 panning;
        u8 numberOfPlays;

        gTasks[taskId].tFrameCounter = 0;
        songId = gTasks[taskId].tSongId;
        panning = gTasks[taskId].tPanning;
        numberOfPlays = --gTasks[taskId].tNumberOfPlays;
        PlaySE12WithPanning(songId, panning);
        if (numberOfPlays == 0)
        {
            DestroyTask(taskId);
            gAnimSoundTaskCount--;
        }
    }
}

#undef tSongId
#undef tPanning
#undef tFramesToWait
#undef tNumberOfPlays
#undef tFrameCounter

#define tSongId         data[0]
#define tPanning        data[1]
#define tFramesToWait   data[2]

static void Cmd_waitplaysewithpan(void)
{
    u16 songId;
    s8 panningArg, panning;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    panningArg = sBattleAnimScriptPtr[2];
    framesToWait = sBattleAnimScriptPtr[3];
    panning = BattleAnimAdjustPanning(panningArg);

    taskId = CreateTask(Task_WaitAndPlaySE, 1);
    gTasks[taskId].tSongId = songId;
    gTasks[taskId].tPanning = panning;
    gTasks[taskId].tFramesToWait = framesToWait;

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 4;
}

static void Task_WaitAndPlaySE(u8 taskId)
{
    if (gTasks[taskId].tFramesToWait-- <= 0)
    {
        PlaySE12WithPanning(gTasks[taskId].tSongId, gTasks[taskId].tPanning);
        DestroyTask(taskId);
        gAnimSoundTaskCount--;
    }
}

#undef tSongId
#undef tPanning
#undef tFramesToWait

static void Cmd_createsoundtask(void)
{
    TaskFunc func;
    u8 numArgs, taskId;
    s32 i;

    sBattleAnimScriptPtr++;
    func = (TaskFunc)T2_READ_32(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 4;
    numArgs = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    for (i = 0; i < numArgs; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }
    taskId = CreateTask(func, 1);
    func(taskId);
    gAnimSoundTaskCount++;
}

static void Cmd_waitsound(void)
{
    if (gAnimSoundTaskCount != 0)
    {
        sSoundAnimFramesToWait = 0;
        sAnimFramesToWait = 1;
    }
    else if (IsSEPlaying())
    {
        if (++sSoundAnimFramesToWait > 90)
        {
            m4aMPlayStop(&gMPlayInfo_SE1);
            m4aMPlayStop(&gMPlayInfo_SE2);
            sSoundAnimFramesToWait = 0;
        }
        else
        {
            sAnimFramesToWait = 1;
        }
    }
    else
    {
        sSoundAnimFramesToWait = 0;
        sBattleAnimScriptPtr++;
        sAnimFramesToWait = 0;
    }
}

static void Cmd_jumpargeq(void)
{
    u8 argId;
    s16 valueToCheck;

    sBattleAnimScriptPtr++;
    argId = sBattleAnimScriptPtr[0];
    valueToCheck = T1_READ_16(sBattleAnimScriptPtr + 1);

    if (valueToCheck == gBattleAnimArgs[argId])
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr + 3);
    else
        sBattleAnimScriptPtr += 7;
}

static void Cmd_jumpifcontest(void)
{
    sBattleAnimScriptPtr++;
    if (IsContest())
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
    else
        sBattleAnimScriptPtr += 4;
}

static void Cmd_splitbgprio(void)
{
    enum AnimBattler wantedBattler;
    enum BattlerId battler;
    enum BattlerPosition battlerPosition;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;

    if (wantedBattler != ANIM_ATTACKER)
        battler = gBattleAnimTarget;
    else
        battler = gBattleAnimAttacker;

    // Apply only if the given battler is the lead (on left from team's perspective)
    battlerPosition = GetBattlerPosition(battler);
    if (!IsContest() && (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_OPPONENT_RIGHT))
    {
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
    }
}

static void Cmd_splitbgprio_all(void)
{
    sBattleAnimScriptPtr++;
    if (!IsContest())
    {
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
    }
}

static void Cmd_splitbgprio_foes(void)
{
    enum AnimBattler wantedBattler;
    enum BattlerPosition battlerPosition;
    enum BattlerId battler;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;

    // Apply only if the attacking the opposing side
    if (!IsBattlerAlly(gBattleAnimAttacker, gBattleAnimTarget))
    {
        if (wantedBattler != ANIM_ATTACKER)
            battler = gBattleAnimTarget;
        else
            battler = gBattleAnimAttacker;

        // Apply only if the given battler is the lead (on left from team's perspective)
        battlerPosition = GetBattlerPosition(battler);
        if (!IsContest() && (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_OPPONENT_RIGHT))
        {
            SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
            SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
        }
    }
}

static void Cmd_invisible(void)
{
    enum AnimBattler animBattler = sBattleAnimScriptPtr[1];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    if (spriteId != SPRITE_NONE)
        gSprites[spriteId].invisible = TRUE;

    sBattleAnimScriptPtr += 2;
}

static void Cmd_visible(void)
{
    enum AnimBattler animBattler = sBattleAnimScriptPtr[1];
    u8 spriteId = GetAnimBattlerSpriteId(animBattler);
    if (spriteId != SPRITE_NONE)
        gSprites[spriteId].invisible = FALSE;

    sBattleAnimScriptPtr += 2;
}

// Below two commands are never used
static void Cmd_teamattack_moveback(void)
{
    u8 wantedBattler;
    u8 priorityRank;
    u8 spriteId;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;

    // Apply to double battles when attacking own side
    if (!IsContest() && IsDoubleBattle() && IsBattlerAlly(gBattleAnimAttacker, gBattleAnimTarget))
    {
        if (wantedBattler == ANIM_ATTACKER)
        {
            priorityRank = GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker);
            spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        }
        else
        {
            priorityRank = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);
            spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        }
        if (spriteId != SPRITE_NONE)
        {
            gSprites[spriteId].invisible = FALSE;
            if (priorityRank == 2)
                gSprites[spriteId].oam.priority = 3;

            if (priorityRank == 1)
                ResetBattleAnimBg(FALSE);
            else
                ResetBattleAnimBg(TRUE);
        }
    }
}

static void Cmd_teamattack_movefwd(void)
{
    u8 wantedBattler;
    u8 priorityRank;
    u8 spriteId;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;

    // Apply to double battles when attacking own side
    if (!IsContest() && IsDoubleBattle()
     && IsBattlerAlly(gBattleAnimAttacker, gBattleAnimTarget))
    {
        if (wantedBattler == ANIM_ATTACKER)
        {
            priorityRank = GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker);
            spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        }
        else
        {
            priorityRank = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);
            spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        }

        if (spriteId != SPRITE_NONE && priorityRank == 2)
            gSprites[spriteId].oam.priority = 2;
    }
}

static void Cmd_stopsound(void)
{
    m4aMPlayStop(&gMPlayInfo_SE1);
    m4aMPlayStop(&gMPlayInfo_SE2);
    sBattleAnimScriptPtr++;
}

static void Cmd_jumpifmovetypeequal(void)
{
    const enum Type *type = sBattleAnimScriptPtr + 1;
    sBattleAnimScriptPtr += 2;
    if (*type != GetBattleMoveType(gCurrentMove))
        sBattleAnimScriptPtr += 4;
    else
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

static void Cmd_createdragondartsprite(void)
{
    s32 i;
    struct SpriteTemplate template;
    u8 argVar;
    u8 argsCount;
    s16 subpriority;
    struct Pokemon *mon = GetBattlerMon(gBattleAnimAttacker);

    sBattleAnimScriptPtr++;

    argVar = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    argsCount = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    for (i = 0; i < argsCount; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    subpriority = GetSubpriorityForMoveAnim(argVar);

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_DRAGAPULT)
    {
        template.tileTag = ANIM_TAG_DREEPY;
        if (IsMonShiny(mon) == TRUE)
            template.paletteTag = ANIM_TAG_DREEPY_SHINY;
        else
            template.paletteTag = ANIM_TAG_DREEPY;
        template.oam = &gOamData_AffineOff_ObjNormal_32x32;
        if (!IsOnPlayerSide(gBattleAnimAttacker))
            template.anims = gAnims_DreepyMissileOpponent;
        else
            template.anims = gAnims_DreepyMissilePlayer;
    }
    else
    {
        template.tileTag = ANIM_TAG_AIR_WAVE;
        template.paletteTag = ANIM_TAG_DREEPY;
        template.oam = &gOamData_AffineOff_ObjNormal_32x16;
        if (!IsOnPlayerSide(gBattleAnimAttacker))
            template.anims = gAnims_DreepyMissileOpponentNotDrag;
        else
            template.anims = gAnims_DreepyMissilePlayer;
    }

    template.images = NULL;
    template.affineAnims = gDummySpriteAffineAnimTable;
    template.callback = AnimShadowBall;

    if (!TryLoadSpriteAssets(&template))
        return;

    if (CreateSpriteAndAnimate(&template,
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2),
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET),
        subpriority) != MAX_SPRITES) // Don't increment the task count if the sprite couldn't be created(i.e. there are too many created sprites atm).
         gAnimVisualTaskCount++;
}
