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
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"

static void InitArenaChallenge(void);
static void GetArenaData(void);
static void SetArenaData(void);
static void SaveArenaChallenge(void);
static void SetArenaPrize(void);
static void GiveArenaPrize(void);
static void BufferArenaOpponentName(void);
static void SpriteCB_JudgmentIcon(struct Sprite *sprite);
static void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler);

#define JUDGMENT_STATE_FINISHED 8

#define TAG_JUDGMENT_ICON 1000

enum {
    ANIM_ICON_X,        // Player lost
    ANIM_ICON_TRIANGLE, // Tie
    ANIM_ICON_CIRCLE,   // Player won
    ANIM_ICON_LINE,     // Line segment for separating the score total at the bottom
};

static const struct OamData sOam_JudgmentIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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

static const union AnimCmd sAnim_JudgmentIcon_X[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Triangle[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Circle[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Line[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_JudgmentIcon[] =
{
    [ANIM_ICON_X]        = sAnim_JudgmentIcon_X,
    [ANIM_ICON_TRIANGLE] = sAnim_JudgmentIcon_Triangle,
    [ANIM_ICON_CIRCLE]   = sAnim_JudgmentIcon_Circle,
    [ANIM_ICON_LINE]     = sAnim_JudgmentIcon_Line,
};

static const struct SpriteTemplate sSpriteTemplate_JudgmentIcon =
{
    .tileTag = TAG_JUDGMENT_ICON,
    .paletteTag = TAG_NONE,
    .oam = &sOam_JudgmentIcon,
    .anims = sAnims_JudgmentIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_JudgmentIcon,
};

static const struct CompressedSpriteSheet sBattleArenaJudgmentSymbolsSpriteSheet[] =
{
    {gBattleArenaJudgmentSymbolsGfx, 0x200, TAG_JUDGMENT_ICON},
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

void CallBattleArenaFunction(void)
{
    sArenaFunctions[gSpecialVar_0x8004]();
}

u8 BattleArena_ShowJudgmentWindow(u8 *state)
{
    int i;
    u8 result = ARENA_RESULT_RUNNING;
    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 0, 8, RGB_BLACK);
        SetGpuReg(REG_OFFSET_WININ, (WININ_WIN0_ALL & ~WININ_WIN0_BG0) | WININ_WIN1_ALL);
        LoadCompressedSpriteSheet(sBattleArenaJudgmentSymbolsSpriteSheet);
        LoadCompressedPalette(gBattleArenaJudgmentSymbolsPalette, OBJ_PLTT_ID(15), PLTT_SIZE_4BPP);
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
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_PLAYER_NAME);
            BattlePutTextOnWindow(gText_Vs, ARENA_WIN_VS);
            BattleStringExpandPlaceholdersToDisplayedString(gText_OpponentMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_OPPONENT_NAME);
            BattlePutTextOnWindow(gText_Mind, ARENA_WIN_MIND);
            BattlePutTextOnWindow(gText_Skill, ARENA_WIN_SKILL);
            BattlePutTextOnWindow(gText_Body, ARENA_WIN_BODY);
            BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
            (*state)++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);

            // Create dividing line for the the score totals at the bottom
            for (i = 0; i < 8; i++)
            {
                u8 spriteId = CreateSprite(&sSpriteTemplate_JudgmentIcon, 64 + i * 16, 84, 0);
                StartSpriteAnim(&gSprites[spriteId], ANIM_ICON_LINE);
            }
            result = ARENA_RESULT_STEP_DONE;
            (*state)++;
        }
        break;
    case 4:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 40, ARENA_CATEGORY_MIND, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 40, ARENA_CATEGORY_MIND, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 5:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 56, ARENA_CATEGORY_SKILL, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 56, ARENA_CATEGORY_SKILL, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 6:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 72, ARENA_CATEGORY_BODY, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 72, ARENA_CATEGORY_BODY, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 7:
        PlaySE(SE_ARENA_TIMEUP2);
        if (gBattleTextBuff1[0] > gBattleTextBuff2[0])
        {
            result = ARENA_RESULT_PLAYER_WON;
            gBattleScripting.battler = 0;
        }
        else if (gBattleTextBuff1[0] < gBattleTextBuff2[0])
        {
            result = ARENA_RESULT_PLAYER_LOST;
            gBattleScripting.battler = 1;
        }
        else
        {
            result = ARENA_RESULT_TIE;
        }
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED:
        // Finishing this state is the indicator to SpriteCB_JudgmentIcon that its safe to destroy the judgment icon sprites
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED + 1:
        SetGpuReg(REG_OFFSET_WININ, (WININ_WIN0_ALL & ~WININ_WIN0_BG0) | WININ_WIN1_ALL);
        HandleBattleWindow(5, 0, 24, 13, WINDOW_CLEAR);
        CopyBgTilemapBufferToVram(0);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 8, 0, RGB_BLACK);
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED + 2:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);
            FreeSpriteTilesByTag(TAG_JUDGMENT_ICON);
            result = ARENA_RESULT_STEP_DONE;
            (*state)++;
        }
        break;
    }

    return result;
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
        animNum = ANIM_ICON_CIRCLE;
        // +2 to score total for winning
        if (battler != 0)
            gBattleTextBuff2[0] += 2;
        else
            gBattleTextBuff1[0] += 2;
    }
    else if (pointsPlayer == pointsOpponent)
    {
        animNum = ANIM_ICON_TRIANGLE;
        // +1 to score total for a tie
        if (battler != 0)
            gBattleTextBuff2[0] += 1;
        else
            gBattleTextBuff1[0] += 1;
    }
    else
    {
        animNum = ANIM_ICON_X;
    }

    pointsPlayer = CreateSprite(&sSpriteTemplate_JudgmentIcon, x, y, 0);
    StartSpriteAnim(&gSprites[pointsPlayer], animNum);
}

static void SpriteCB_JudgmentIcon(struct Sprite *sprite)
{
    if (gBattleCommunication[0] > JUDGMENT_STATE_FINISHED)
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
// All moves with power != 0 give 1 point, with the following exceptions:
//    - Counter, Mirror Coat, and Bide give 0 points
//    - Fake Out subtracts 1 point
// All moves with power == 0 give 0 points, with the following exceptions:
//    - Protect, Detect, and Endure subtract 1 point

    if (gMovesInfo[gCurrentMove].effect == EFFECT_FIRST_TURN_ONLY
     || gMovesInfo[gCurrentMove].effect == EFFECT_PROTECT
     || gMovesInfo[gCurrentMove].effect == EFFECT_ENDURE)
    {
        gBattleStruct->arenaMindPoints[battler]--;
    }
    else if (gMovesInfo[gCurrentMove].power != 0
          && gMovesInfo[gCurrentMove].effect != EFFECT_COUNTER
          && gMovesInfo[gCurrentMove].effect != EFFECT_MIRROR_COAT
          && gMovesInfo[gCurrentMove].effect != EFFECT_METAL_BURST
          && gMovesInfo[gCurrentMove].effect != EFFECT_BIDE)
    {
        gBattleStruct->arenaMindPoints[battler]++;
    }
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
            if (!(gMoveResultFlags & MOVE_RESULT_MISSED) || gBattleCommunication[MISS_TYPE] != B_MSG_PROTECTED)
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

void BattleArena_DeductSkillPoints(u8 battler, u16 stringId)
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

static void UNUSED UpdateHPAtStart(u8 battler)
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

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
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
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
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
