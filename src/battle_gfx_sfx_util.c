#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_ai_main.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "battle_interface.h"
#include "main.h"
#include "menu.h"
#include "dma3.h"
#include "malloc.h"
#include "graphics.h"
#include "random.h"
#include "util.h"
#include "pokemon.h"
#include "constants/moves.h"
#include "task.h"
#include "sprite.h"
#include "sound.h"
#include "party_menu.h"
#include "m4a.h"
#include "decompress.h"
#include "data.h"
#include "palette.h"
#include "contest.h"
#include "trainer.h"
#include "trainer_pokemon_sprites.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/battle_palace.h"
#include "constants/battle_move_effects.h"
#include "constants/event_objects.h" // only for SHADOW_SIZE constants

// this file's functions
static u8 GetBattlePalaceMoveGroup(enum BattlerId battler, enum Move move);
static u16 GetBattlePalaceTarget(enum BattlerId battler);
static void SpriteCB_TrainerSlideVertical(struct Sprite *sprite);
static bool8 ShouldAnimBeDoneRegardlessOfSubstitute(u8 animId);
static void Task_ClearBitWhenBattleTableAnimDone(u8 taskId);
static void Task_ClearBitWhenSpecialAnimDone(u8 taskId);
static void ClearSpritesBattlerHealthboxAnimData(void);

// const rom data
static const struct CompressedSpriteSheet sSpriteSheet_SinglesPlayerHealthbox =
{
    gHealthboxSinglesPlayerGfx, 0x1000, TAG_HEALTHBOX_PLAYER1_TILE
};

static const struct CompressedSpriteSheet sSpriteSheet_SinglesOpponentHealthbox =
{
    gHealthboxSinglesOpponentGfx, 0x1000, TAG_HEALTHBOX_OPPONENT1_TILE
};

static const struct CompressedSpriteSheet sSpriteSheet_SinglesOpponentLargeHealthbox =
{
    gHealthboxSinglesOpponentLargeGfx, 0x1000, TAG_HEALTHBOX_OPPONENT1_TILE
};

static const struct CompressedSpriteSheet sSpriteSheets_DoublesPlayerHealthbox[2] =
{
    {gHealthboxDoublesPlayerGfx, 0x800, TAG_HEALTHBOX_PLAYER1_TILE},
    {gHealthboxDoublesPlayerGfx, 0x800, TAG_HEALTHBOX_PLAYER2_TILE}
};

static const struct CompressedSpriteSheet sSpriteSheets_DoublesOpponentHealthbox[2] =
{
    {gHealthboxDoublesOpponentGfx, 0x800, TAG_HEALTHBOX_OPPONENT1_TILE},
    {gHealthboxDoublesOpponentGfx, 0x800, TAG_HEALTHBOX_OPPONENT2_TILE}
};

static const struct CompressedSpriteSheet sSpriteSheet_SafariHealthbox =
{
    gHealthboxSafariGfx, 0x1000, TAG_HEALTHBOX_SAFARI_TILE
};

static const struct CompressedSpriteSheet sSpriteSheets_HealthBar[MAX_BATTLERS_COUNT] =
{
    {gBlankGfxCompressed, 0x0100, TAG_HEALTHBAR_PLAYER1_TILE},
    {gBlankGfxCompressed, 0x0120, TAG_HEALTHBAR_OPPONENT1_TILE},
    {gBlankGfxCompressed, 0x0100, TAG_HEALTHBAR_PLAYER2_TILE},
    {gBlankGfxCompressed, 0x0120, TAG_HEALTHBAR_OPPONENT2_TILE}
};

const struct SpritePalette sSpritePalettes_HealthBoxHealthBar[2] =
{
    {gBattleInterface_BallStatusBarPal, TAG_HEALTHBOX_PAL},
    {gBattleInterface_BallDisplayPal, TAG_HEALTHBAR_PAL}
};

const struct CompressedSpriteSheet gSpriteSheet_EnemyShadow =
{
    .data = gEnemyMonShadow_Gfx, .size = 0x80, .tag = TAG_SHADOW_TILE
};

const struct CompressedSpriteSheet gSpriteSheet_EnemyShadowsSized =
{
    .data = gEnemyMonShadowsSized_Gfx,
    .size = TILE_SIZE_4BPP * 8 * 4, // 8 tiles per sprite, 4 sprites total
    .tag = TAG_SHADOW_TILE,
};

static const struct OamData sOamData_EnemyShadow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0
};

const struct SpriteTemplate gSpriteTemplate_EnemyShadow =
{
    .tileTag = TAG_SHADOW_TILE,
    .paletteTag = TAG_SHADOW_PAL,
    .oam = &sOamData_EnemyShadow,
};

// code
void AllocateBattleSpritesData(void)
{
    gBattleSpritesDataPtr = AllocZeroed(sizeof(struct BattleSpriteData));
    gBattleSpritesDataPtr->battlerData = AllocZeroed(sizeof(struct BattleSpriteInfo) * MAX_BATTLERS_COUNT);
    gBattleSpritesDataPtr->healthBoxesData = AllocZeroed(sizeof(struct BattleHealthboxInfo) * MAX_BATTLERS_COUNT);
    gBattleSpritesDataPtr->animationData = AllocZeroed(sizeof(struct BattleAnimationInfo));
    gBattleSpritesDataPtr->battleBars = AllocZeroed(sizeof(struct BattleBarInfo) * MAX_BATTLERS_COUNT);
}

void FreeBattleSpritesData(void)
{
    if (gBattleSpritesDataPtr == NULL)
        return;

    FREE_AND_SET_NULL(gBattleSpritesDataPtr->battleBars);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->animationData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->healthBoxesData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->battlerData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr);
}

// Pokémon chooses move to use in Battle Palace rather than player
u16 ChooseMoveAndTargetInBattlePalace(enum BattlerId battler)
{
    s32 i, var1, var2;
    s32 chosenMoveIndex = -1;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    u8 unusableMovesBits = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    s32 percent = Random() % 100;

    // Heavy variable re-use here makes this hard to read without defines
    // Possibly just optimization? might still match with additional vars
    #define maxGroupNum var1
    #define minGroupNum var2
    #define selectedGroup percent
    #define selectedMoves var2
    #define numMovesPerGroup var1
    #define numMultipleMoveGroups var2
    #define randSelectGroup var2

    // If battler is < 50% HP and not asleep, use second set of move group likelihoods
    // otherwise use first set
    i = (gBattleStruct->palaceFlags & (1u << battler)) ? 2 : 0;
    minGroupNum = i;

    maxGroupNum = i + 2; // + 2 because there are two percentages per set of likelihoods

    // Each nature has a different percent chance to select a move from one of 3 move groups
    // If percent is less than 1st check, use move from "Attack" group
    // If percent is less than 2nd check, use move from "Defense" group
    // Otherwise use move from "Support" group
    for (; i < maxGroupNum; i++)
    {
        if (gNaturesInfo[GetNatureFromPersonality(gBattleMons[battler].personality)].battlePalacePercents[i] > percent)
            break;
    }
    selectedGroup = i - minGroupNum;
    if (i == maxGroupNum)
        selectedGroup = PALACE_MOVE_GROUP_SUPPORT;

    // Flag moves that match selected group, to be passed to AI
    for (selectedMoves = 0, i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moveInfo->moves[i] == MOVE_NONE)
            break;
        if (selectedGroup == GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) && moveInfo->currentPP[i] != 0)
            selectedMoves |= 1u << i;
    }

    // Pass selected moves to AI, pick one
    if (selectedMoves != 0)
    {
        // Lower 4 bits of palaceFlags are flags for each battler.
        // Clear the rest of palaceFlags, then set the selected moves in the upper 4 bits.
        gBattleStruct->palaceFlags &= (1 << MAX_BATTLERS_COUNT) - 1;
        gBattleStruct->palaceFlags |= (selectedMoves << MAX_BATTLERS_COUNT);
        BattleAI_SetupAIData(selectedMoves, battler);
        chosenMoveIndex = BattleAI_ChooseMoveIndex(battler);
    }

    // If no moves matched the selected group, pick a new move from groups the Pokémon has
    // In this case the AI is not checked again, so the choice may be worse
    // If a move is chosen this way, there's a 50% chance that it will be unable to use it anyway
    if (chosenMoveIndex == -1 || chosenMoveIndex >= MAX_MON_MOVES)
    {
        chosenMoveIndex = -1;
        if (unusableMovesBits != ALL_MOVES_MASK)
        {
            numMovesPerGroup = 0, numMultipleMoveGroups = 0;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                // Count the number of usable moves the battler has in each move group.
                // The totals will be stored separately in 3 groups of 4 bits each in numMovesPerGroup.
                if (GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) == PALACE_MOVE_GROUP_ATTACK && !((1u << i) & unusableMovesBits))
                    numMovesPerGroup += (1 << 0);
                if (GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) == PALACE_MOVE_GROUP_DEFENSE && !((1u << i) & unusableMovesBits))
                    numMovesPerGroup += (1 << 4);
                if (GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) == PALACE_MOVE_GROUP_SUPPORT && !((1u << i) & unusableMovesBits))
                    numMovesPerGroup += (1 << 8);
            }

            // Count the number of move groups for which the battler has at least 2 usable moves.
            // This is a roundabout way to determine if there is a move group that should be
            // preferred, because it has multiple move options and the others do not.
            // The condition intended to check the total for the Support group is accidentally
            // checking the Defense total, and is never true. As a result the preferences for
            // random move selection here will skew away from the Support move group.
            if ((numMovesPerGroup & 0xF) >= 2)
                numMultipleMoveGroups++;
            if ((numMovesPerGroup & (0xF << 4)) >= (2 << 4))
                numMultipleMoveGroups++;
#ifdef BUGFIX
            if ((numMovesPerGroup & (0xF << 8)) >= (2 << 8))
#else
            if ((numMovesPerGroup & (0xF << 4)) >= (2 << 8))
#endif
                numMultipleMoveGroups++;


            // By this point we already know the battler only has usable moves from at most 2 of the 3 move groups,
            // because they had no usable moves from the move group that was selected based on Nature.
            //
            // The below condition is effectively 'numMultipleMoveGroups != 1'.
            // There is no stand-out group with multiple moves to choose from, so we pick randomly.
            // Note that because of the bug above the battler may actually have any number of Support moves.
            if (numMultipleMoveGroups > 1 || numMultipleMoveGroups == 0)
            {
                do
                {
                    i = Random() % MAX_MON_MOVES;
                    if (!((1u << i) & unusableMovesBits))
                        chosenMoveIndex = i;
                } while (chosenMoveIndex == -1);
            }
            else
            {
                // The battler has just 1 move group with multiple move options to choose from.
                // Choose a move randomly from this group.

                // Same bug as the previous set of conditions (the condition for Support is never true).
                // This bug won't cause a softlock below, because if Support is the only group with multiple
                // moves then it won't have been counted, and the 'numMultipleMoveGroups == 0' above will be true.
                if ((numMovesPerGroup & 0xF) >= 2)
                    randSelectGroup = PALACE_MOVE_GROUP_ATTACK;
                if ((numMovesPerGroup & (0xF << 4)) >= (2 << 4))
                    randSelectGroup = PALACE_MOVE_GROUP_DEFENSE;
#ifdef BUGFIX
                if ((numMovesPerGroup & (0xF << 8)) >= (2 << 8))
#else
                if ((numMovesPerGroup & (0xF << 4)) >= (2 << 8))
#endif
                    randSelectGroup = PALACE_MOVE_GROUP_SUPPORT;

                do
                {
                    i = Random() % MAX_MON_MOVES;
                    if (!((1u << i) & unusableMovesBits) && randSelectGroup == GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]))
                        chosenMoveIndex = i;
                } while (chosenMoveIndex == -1);
            }

            // Because the selected move was not from the Nature-chosen move group there's a 50% chance
            // that it will be unable to use it. This could have been checked earlier to avoid the above work.
            if (Random() % 100 >= 50)
            {
                gProtectStructs[battler].palaceUnableToUseMove = TRUE;
                return 0;
            }
        }
        else
        {
            // All the battler's moves were flagged as unusable.
            gProtectStructs[battler].palaceUnableToUseMove = TRUE;
            return 0;
        }
    }

    enum MoveTarget moveTarget = GetBattlerMoveSelectionTargetType(battler, moveInfo->moves[chosenMoveIndex]);

    if (moveTarget == TARGET_USER || moveTarget == TARGET_USER_OR_ALLY || moveTarget == TARGET_USER_AND_ALLY)
        chosenMoveIndex |= (battler << 8);
    else if (moveTarget == TARGET_SELECTED || moveTarget == TARGET_SMART)
        chosenMoveIndex |= GetBattlePalaceTarget(battler);
    else
        chosenMoveIndex |= (GetBattlerLeftFoe(battler) << 8);

    return chosenMoveIndex;
}

#undef maxGroupNum
#undef minGroupNum
#undef selectedGroup
#undef selectedMoves
#undef moveTarget
#undef numMovesPerGroup
#undef numMultipleMoveGroups
#undef randSelectGroup

static u8 GetBattlePalaceMoveGroup(enum BattlerId battler, enum Move move)
{
    switch (GetBattlerMoveSelectionTargetType(battler, move))
    {
    case TARGET_SELECTED:
    case TARGET_USER_AND_ALLY:
    case TARGET_SMART:
    case TARGET_OPPONENT:
    case TARGET_RANDOM:
    case TARGET_BOTH:
    case TARGET_FOES_AND_ALLY:
    case TARGET_ALL_BATTLERS:
    case TARGET_FIELD:
        if (IsBattleMoveStatus(move))
            return PALACE_MOVE_GROUP_SUPPORT;
        else
            return PALACE_MOVE_GROUP_ATTACK;
        break;
    case TARGET_DEPENDS:
    case TARGET_OPPONENTS_FIELD:
    case TARGET_ALLY:
    case TARGET_USER_OR_ALLY:
        return PALACE_MOVE_GROUP_SUPPORT;
    case TARGET_USER:
        return PALACE_MOVE_GROUP_DEFENSE;
    default:
        return PALACE_MOVE_GROUP_ATTACK;
    }
}

static u16 GetBattlePalaceTarget(enum BattlerId battler)
{
    if (IsDoubleBattle())
    {
        enum BattlerId opposing1, opposing2;

        if (IsOnPlayerSide(battler))
        {
            opposing1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            opposing2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            opposing1 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            opposing2 = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        }

        if (gBattleMons[opposing1].hp == gBattleMons[opposing2].hp)
            return (GetBattlerLeftFoe(battler) + (Random() & 2)) << 8;

        switch (gNaturesInfo[GetNatureFromPersonality(gBattleMons[battler].personality)].battlePalaceSmokescreen)
        {
        case PALACE_TARGET_STRONGER:
            if (gBattleMons[opposing1].hp > gBattleMons[opposing2].hp)
                return opposing1 << 8;
            else
                return opposing2 << 8;
        case PALACE_TARGET_WEAKER:
            if (gBattleMons[opposing1].hp < gBattleMons[opposing2].hp)
                return opposing1 << 8;
            else
                return opposing2 << 8;
        case PALACE_TARGET_RANDOM:
            return (GetBattlerLeftFoe(battler) + (Random() & 2)) << 8;
        }
    }

    return GetOppositeBattler(battler) << 8;
}

// Wait for the Pokémon to finish appearing out from the Poké Ball on send out
void SpriteCB_WaitForBattlerBallReleaseAnim(struct Sprite *sprite)
{
    u8 spriteId = sprite->data[1];

    if (!gSprites[spriteId].affineAnimEnded)
        return;
    if (gSprites[spriteId].invisible)
        return;

    if (gSprites[spriteId].animPaused)
    {
        gSprites[spriteId].animPaused = 0;
    }
    else
    {
        if (gSprites[spriteId].animEnded)
            sprite->callback = SpriteCallbackDummy;
    }
}

static void UNUSED UnusedDoBattleSpriteAffineAnim(struct Sprite *sprite, bool8 pointless)
{
    sprite->animPaused = TRUE;
    sprite->callback = SpriteCallbackDummy;

    if (!pointless)
        StartSpriteAffineAnim(sprite, 1);
    else
        StartSpriteAffineAnim(sprite, 1);

    AnimateSprite(sprite);
}

#define sSpeedX data[0]

void SpriteCB_TrainerSlideIn(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 += sprite->sSpeedX;
        if (sprite->x2 == 0)
        {
            if (sprite->y2 != 0)
                sprite->callback = SpriteCB_TrainerSlideVertical;
            else
                sprite->callback = SpriteCallbackDummy;
        }
    }
}

void SpriteCB_TrainerSpawn(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 = 0;
        if (sprite->y2 != 0)
            sprite->callback = SpriteCB_TrainerSlideVertical;
        else
            sprite->callback = SpriteCallbackDummy;
    }
}

// Slide up to 0 if necessary (used by multi battle intro)
static void SpriteCB_TrainerSlideVertical(struct Sprite *sprite)
{
    sprite->y2 -= 2;
    if (sprite->y2 == 0)
        sprite->callback = SpriteCallbackDummy;
}

#undef sSpeedX

void InitAndLaunchChosenStatusAnimation(enum BattlerId battler, bool32 isVolatile, u32 status)
{
    gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 1;
    if (!isVolatile)
    {
        if (status == STATUS1_FREEZE)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_FRZ);
        else if (status == STATUS1_FROSTBITE)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_FRB);
        else if (status == STATUS1_POISON || status & STATUS1_TOXIC_POISON)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_PSN);
        else if (status == STATUS1_BURN)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_BRN);
        else if (status & STATUS1_SLEEP)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_SLP);
        else if (status == STATUS1_PARALYSIS)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_PRZ);
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 0;
    }
    else
    {
        if (status == VOLATILE_INFATUATION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_INFATUATION);
        else if (status == VOLATILE_CONFUSION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_CONFUSION);
        else if (status == VOLATILE_CURSED)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_CURSED);
        else if (status == VOLATILE_NIGHTMARE)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_NIGHTMARE);
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 0;
    }
}

#define tBattlerId data[0]

bool8 TryHandleLaunchBattleTableAnimation(u8 activeBattler, u8 atkBattler, u8 defBattler, u8 tableId, u16 argument)
{
    u8 taskId;

    if (gBattleSpritesDataPtr->battlerData[activeBattler].behindSubstitute
        && !ShouldAnimBeDoneRegardlessOfSubstitute(tableId))
    {
        return TRUE;
    }
    if (gBattleSpritesDataPtr->battlerData[activeBattler].behindSubstitute
        && tableId == B_ANIM_SUBSTITUTE_FADE
        && gSprites[gBattlerSpriteIds[activeBattler]].invisible)
    {
        LoadBattleMonGfxAndAnimate(activeBattler, TRUE, gBattlerSpriteIds[activeBattler]);
        ClearBehindSubstituteBit(activeBattler);
        return TRUE;
    }

    if (tableId == B_ANIM_ILLUSION_OFF)
        gBattleStruct->illusion[activeBattler].state = ILLUSION_OFF;

    gBattleAnimAttacker = atkBattler;
    gBattleAnimTarget = defBattler;
    gBattleSpritesDataPtr->animationData->animArg = argument;
    LaunchBattleAnimation(ANIM_TYPE_GENERAL, tableId);
    taskId = CreateTask(Task_ClearBitWhenBattleTableAnimDone, 10);
    gTasks[taskId].tBattlerId = activeBattler;
    gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].animFromTableActive = 1;

    return FALSE;
}

static void Task_ClearBitWhenBattleTableAnimDone(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].animFromTableActive = 0;
        DestroyTask(taskId);
    }
}

#undef tBattlerId

static bool8 ShouldAnimBeDoneRegardlessOfSubstitute(u8 animId)
{
    switch (animId)
    {
    case B_ANIM_ILLUSION_OFF:
    case B_ANIM_FOCUS_PUNCH_SETUP:
    case B_ANIM_SWAP_TO_SUBSTITUTE:
    case B_ANIM_SWAP_FROM_SUBSTITUTE:
    case B_ANIM_SUBSTITUTE_FADE:
    case B_ANIM_RAIN_CONTINUES:
    case B_ANIM_SUN_CONTINUES:
    case B_ANIM_SANDSTORM_CONTINUES:
    case B_ANIM_HAIL_CONTINUES:
    case B_ANIM_SNOW_CONTINUES:
    case B_ANIM_FOG_CONTINUES:
    case B_ANIM_SNATCH_MOVE:
    case B_ANIM_STATS_CHANGE:
        return TRUE;
    default:
        return FALSE;
    }
}

#define tBattlerId data[0]

void InitAndLaunchSpecialAnimation(enum BattlerId activeBattler, enum BattlerId atkBattler, enum BattlerId defBattler, u8 tableId)
{
    u8 taskId;

    gBattleAnimAttacker = atkBattler;
    gBattleAnimTarget = defBattler;
    LaunchBattleAnimation(ANIM_TYPE_SPECIAL, tableId);
    taskId = CreateTask(Task_ClearBitWhenSpecialAnimDone, 10);
    gTasks[taskId].tBattlerId = activeBattler;
    gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].specialAnimActive = 1;
}

static void Task_ClearBitWhenSpecialAnimDone(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].specialAnimActive = 0;
        DestroyTask(taskId);
    }
}

#undef tBattlerId

// Check if SE has finished or 30 calls, whichever comes first
bool8 IsBattleSEPlaying(enum BattlerId battler)
{
    u8 zero = 0;

    if (IsSEPlaying())
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].soundTimer++;
        if (gBattleSpritesDataPtr->healthBoxesData[battler].soundTimer < 30)
            return TRUE;

        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
    }
    if (zero == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].soundTimer = 0;
        return FALSE;
    }

    // Never reached
    return TRUE;
}

void BattleLoadMonSpriteGfx(struct Pokemon *mon, enum BattlerId battler)
{
    u32 personalityValue, paletteOffset;
    bool32 isShiny;
    enum Species species;
    enum BattlerPosition position;
    const u16 *paletteData;
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    if (illusionMon != NULL)
        mon = illusionMon;

    if (GetMonData(mon, MON_DATA_IS_EGG) || GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE) // Don't load GFX of egg Pokémon.
        return;

    isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
    species = GetMonData(mon, MON_DATA_SPECIES);
    personalityValue = GetMonData(mon, MON_DATA_PERSONALITY);

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != SPECIES_NONE)
    {
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;
        // If battler has Gigantamax factor, try convert gfx to G-Max version
        if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && GetMonData(mon, MON_DATA_GIGANTAMAX_FACTOR))
            gBattleSpritesDataPtr->battlerData[battler].transformSpecies = species = GetGMaxTargetSpecies(species);

        if (gBattleMons[battler].volatiles.transformed)
        {
            personalityValue = gTransformedPersonalities[battler];
            isShiny = gTransformedShininess[battler];
        }
    }

    position = GetBattlerPosition(battler);
    HandleLoadSpecialPokePic(!IsOnPlayerSide(battler),
                             gMonSpritesGfxPtr->spritesGfx[position],
                             species, personalityValue);

    paletteOffset = OBJ_PLTT_ID(battler);

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_NONE)
        paletteData = GetMonFrontSpritePal(mon);
    else
        paletteData = GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personalityValue);

    LoadPalette(paletteData, paletteOffset, PLTT_SIZE_4BPP);
    LoadPalette(paletteData, BG_PLTT_ID(8) + BG_PLTT_ID(battler), PLTT_SIZE_4BPP);

    // transform's pink color
    if (gBattleMons[battler].volatiles.transformed)
    {
        BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
        CpuCopy32(&gPlttBufferFaded[paletteOffset], &gPlttBufferUnfaded[paletteOffset], PLTT_SIZEOF(16));
    }

    // dynamax tint
    if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX)
    {
        // Calyrex and its forms have a blue dynamax aura instead of red.
        if (GET_BASE_SPECIES_ID(species) == SPECIES_CALYREX)
            BlendPalette(paletteOffset, 16, 4, RGB(12, 0, 31));
        else
            BlendPalette(paletteOffset, 16, 4, RGB(31, 0, 12));
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, PLTT_SIZEOF(16));
    }

    // Terastallization's tint
    if (GetActiveGimmick(battler) == GIMMICK_TERA)
    {
        BlendPalette(paletteOffset, 16, 8, GetTeraTypeRGB(GetBattlerTeraType(battler)));
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, PLTT_SIZEOF(16));
    }
}

void BattleGfxSfxDummy2(enum Species species)
{
}

void DecompressTrainerFrontPic(enum TrainerPicID trainerPicId, enum BattlerId battler)
{
    enum BattlerPosition position = GetBattlerPosition(battler);
    DecompressDataWithHeaderWram(GetTrainerFrontPicData(trainerPicId), gMonSpritesGfxPtr->spritesGfx[position]);
    LoadSpritePaletteWithTag(GetTrainerFrontPicPalette(trainerPicId), GetTrainerPicTag(trainerPicId, TRUE));
}

void FreeTrainerFrontPicPalette(enum TrainerPicID trainerPicId)
{
    FreeSpritePaletteByTag(GetTrainerPicTag(trainerPicId, TRUE));
}

bool8 BattleLoadAllHealthBoxesGfx(u8 state)
{
    bool8 retVal = FALSE;

    if (state != 0)
    {
        if (state == 1)
        {
            LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[0]);
            LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[1]);
            CategoryIcons_LoadSpritesGfx();
        }
        else if (!IsDoubleBattle())
        {
            if (state == 2)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    LoadCompressedSpriteSheet(&sSpriteSheet_SafariHealthbox);
                else
                    LoadCompressedSpriteSheet(&sSpriteSheet_SinglesPlayerHealthbox);
            }
            else if (state == 3)
            {
                if (B_HP_PERCENTAGE_DISPLAY)
                    LoadCompressedSpriteSheet(&sSpriteSheet_SinglesOpponentLargeHealthbox);
                else
                    LoadCompressedSpriteSheet(&sSpriteSheet_SinglesOpponentHealthbox);
            }
            else if (state == 4)
            {
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(B_BATTLER_0)]);
            }
            else if (state == 5)
            {
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(B_BATTLER_1)]);
            }
            else
            {
                retVal = TRUE;
            }
        }
        else
        {
            if (state == 2)
            {
                switch (GetBattlerCoordsIndex(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
                {
                default:
                    LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[0]);
                    break;
                case BATTLE_COORDS_SINGLES:
                    LoadCompressedSpriteSheet(&sSpriteSheet_SinglesPlayerHealthbox);
                    break;
                }
            }
            else if (state == 3)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[1]);
            else if (state == 4)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[0]);
            else if (state == 5)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[1]);
            else if (state == 6)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(B_BATTLER_0)]);
            else if (state == 7)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(B_BATTLER_1)]);
            else if (state == 8)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(B_BATTLER_2)]);
            else if (state == 9)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(B_BATTLER_3)]);
            else
                retVal = TRUE;
        }
    }

    return retVal;
}

void LoadBattleBarGfx(u8 unused)
{
    DecompressDataWithHeaderWram(gBattleInterfaceGfx_BattleBar, gMonSpritesGfxPtr->barFontGfx);
}

bool8 BattleInitAllSprites(u8 *state1, u8 *battler)
{
    bool8 retVal = FALSE;

    switch (*state1)
    {
    case 0:
        ClearSpritesBattlerHealthboxAnimData();
        (*state1)++;
        break;
    case 1:
        if (!BattleLoadAllHealthBoxesGfx(*battler))
        {
            (*battler)++;
        }
        else
        {
            *battler = 0;
            (*state1)++;
        }
        break;
    case 2:
        (*state1)++;
        break;
    case 3:
        if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && *battler == 0)
            gHealthboxSpriteIds[*battler] = CreateSafariPlayerHealthboxSprites();
        else
            gHealthboxSpriteIds[*battler] = CreateBattlerHealthboxSprites(*battler);

        (*battler)++;
        if (*battler == gBattlersCount)
        {
            *battler = 0;
            (*state1)++;
        }
        break;
    case 4:
        InitBattlerHealthboxCoords(*battler);
        if (GetBattlerPosition(*battler) <= B_POSITION_OPPONENT_LEFT)
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[*battler], FALSE);
        else
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[*battler], TRUE);

        (*battler)++;
        if (*battler == gBattlersCount)
        {
            *battler = 0;
            (*state1)++;
        }
        break;
    case 5:
        if (!IsOnPlayerSide(*battler) || !(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
            UpdateHealthboxAttribute(gHealthboxSpriteIds[*battler], GetBattlerMon(*battler), HEALTHBOX_ALL);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[*battler]);
        (*battler)++;
        if (*battler == gBattlersCount)
        {
            *battler = 0;
            (*state1)++;
        }
        break;
    case 6:
        LoadAndCreateEnemyShadowSprites();
        BufferBattlePartyCurrentOrder();
        retVal = TRUE;
        break;
    }

    return retVal;
}

void ClearSpritesHealthboxAnimData(void)
{
    memset(gBattleSpritesDataPtr->healthBoxesData, 0, sizeof(struct BattleHealthboxInfo) * MAX_BATTLERS_COUNT);
    memset(gBattleSpritesDataPtr->animationData, 0, sizeof(struct BattleAnimationInfo));
}

static void ClearSpritesBattlerHealthboxAnimData(void)
{
    ClearSpritesHealthboxAnimData();
    memset(gBattleSpritesDataPtr->battlerData, 0, sizeof(struct BattleSpriteInfo) * MAX_BATTLERS_COUNT);
}

void CopyAllBattleSpritesInvisibilities(void)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleSpritesDataPtr->battlerData[i].invisible = gSprites[gBattlerSpriteIds[i]].invisible;
}

void CopyBattleSpriteInvisibility(enum BattlerId battler)
{
    gBattleSpritesDataPtr->battlerData[battler].invisible = gSprites[gBattlerSpriteIds[battler]].invisible;
}

void HandleSpeciesGfxDataChange(enum BattlerId battlerAtk, enum BattlerId battlerDef, u8 changeType)
{
    u32 personalityValue, paletteOffset;
    enum Species targetSpecies;
    enum BattlerPosition position;
    bool32 isShiny;
    const void *src;
    const u16 *paletteData;
    struct Pokemon *monAtk = GetBattlerMon(battlerAtk);
    struct Pokemon *monDef = GetBattlerMon(battlerDef);
    void *dst;

    if (IsContest())
    {
        position = B_POSITION_PLAYER_LEFT;
        targetSpecies = gContestResources->moveAnim->targetSpecies;
        personalityValue = gContestResources->moveAnim->personality;
        isShiny = gContestResources->moveAnim->isShiny;

        HandleLoadSpecialPokePic(FALSE,
                                 gMonSpritesGfxPtr->spritesGfx[position],
                                 targetSpecies,
                                 gContestResources->moveAnim->targetPersonality);
    }
    else
    {
        position = GetBattlerPosition(battlerAtk);
        if (changeType == SPECIES_GFX_CHANGE_TRANSFORM)
        {
            // Get base form if its currently Gigantamax
            if (IsGigantamaxed(battlerDef))
                targetSpecies = GetBattlerPartyState(battlerDef)->changedSpecies;
            else if (gBattleStruct->illusion[battlerDef].state == ILLUSION_ON)
                targetSpecies = GetIllusionMonSpecies(battlerDef);
            else
                targetSpecies = GetMonData(monDef, MON_DATA_SPECIES);
        }
        else
        {
            targetSpecies = GetMonData(monAtk, MON_DATA_SPECIES);
        }
        gBattleSpritesDataPtr->battlerData[battlerAtk].transformSpecies = targetSpecies;

        if (changeType == SPECIES_GFX_CHANGE_TRANSFORM)
        {
            personalityValue = gTransformedPersonalities[battlerAtk];
            isShiny = gTransformedShininess[battlerAtk];
        }
        else
        {
            personalityValue = GetMonData(monAtk, MON_DATA_PERSONALITY);
            isShiny = GetMonData(monAtk, MON_DATA_IS_SHINY);
        }
        HandleLoadSpecialPokePic(!IsOnPlayerSide(battlerAtk),
                                 gMonSpritesGfxPtr->spritesGfx[position],
                                 targetSpecies,
                                 personalityValue);
    }
    src = gMonSpritesGfxPtr->spritesGfx[position];
    dst = (void *)(OBJ_VRAM0 + gSprites[gBattlerSpriteIds[battlerAtk]].oam.tileNum * 32);
    DmaCopy32(3, src, dst, MON_PIC_SIZE);
    paletteOffset = OBJ_PLTT_ID(battlerAtk);
    paletteData = GetMonSpritePalFromSpeciesAndPersonality(targetSpecies, isShiny, personalityValue);
    LoadPalette(paletteData, paletteOffset, PLTT_SIZE_4BPP);

    if (changeType == SPECIES_GFX_CHANGE_GHOST_UNVEIL)
    {
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][gBattlerPartyIndexes[battlerAtk]], MON_DATA_NICKNAME, gSpeciesInfo[targetSpecies].speciesName);
        UpdateNickInHealthbox(gHealthboxSpriteIds[battlerAtk], &gParties[B_TRAINER_OPPONENT_A][gBattlerPartyIndexes[battlerAtk]]);
        TryAddPokeballIconToHealthbox(gHealthboxSpriteIds[battlerAtk], TRUE);
    }
    else if (changeType == SPECIES_GFX_CHANGE_TRANSFORM)
    {
        BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
        CpuCopy32(&gPlttBufferFaded[paletteOffset], &gPlttBufferUnfaded[paletteOffset], PLTT_SIZEOF(16));
    }

    // dynamax tint
    if (GetActiveGimmick(battlerAtk) == GIMMICK_DYNAMAX)
    {
        // Calyrex and its forms have a blue dynamax aura instead of red.
        if (GET_BASE_SPECIES_ID(targetSpecies) == SPECIES_CALYREX)
            BlendPalette(paletteOffset, 16, 4, RGB(12, 0, 31));
        else
            BlendPalette(paletteOffset, 16, 4, RGB(31, 0, 12));
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, PLTT_SIZEOF(16));
    }

    // Terastallization's tint
    if (changeType != SPECIES_GFX_CHANGE_ILLUSION_OFF && GetActiveGimmick(battlerAtk) == GIMMICK_TERA)
    {
        BlendPalette(paletteOffset, 16, 8, GetTeraTypeRGB(GetBattlerTeraType(battlerAtk)));
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, PLTT_SIZEOF(16));
    }

    gSprites[gBattlerSpriteIds[battlerAtk]].y = GetBattlerSpriteDefault_Y(battlerAtk);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerAtk]], 0);
}

void BattleLoadSubstituteOrMonSpriteGfx(enum BattlerId battler, bool8 loadMonSprite)
{
    s32 palOffset;
    enum BattlerPosition position;

    if (!loadMonSprite)
    {
        if (IsContest())
            position = B_POSITION_PLAYER_LEFT;
        else
            position = GetBattlerPosition(battler);

        if (IsContest())
            DecompressDataWithHeaderVram(gBattleAnimSpriteGfx_SubstituteBack, gMonSpritesGfxPtr->spritesGfx[position]);
        else if (!IsOnPlayerSide(battler))
            DecompressDataWithHeaderVram(gBattleAnimSpriteGfx_Substitute, gMonSpritesGfxPtr->spritesGfx[position]);
        else
            DecompressDataWithHeaderVram(gBattleAnimSpriteGfx_SubstituteBack, gMonSpritesGfxPtr->spritesGfx[position]);

        for (u32 i = 1; i < 2; i++)
        {
            Dma3CopyLarge32_(gMonSpritesGfxPtr->spritesGfx[position], &gMonSpritesGfxPtr->spritesGfx[position][MON_PIC_SIZE * i], MON_PIC_SIZE);
        }

        palOffset = OBJ_PLTT_ID(battler);
        LoadPalette(gBattleAnimSpritePal_Substitute, palOffset, PLTT_SIZE_4BPP);
    }
    else
    {
        if (!IsContest())
            BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
    }
}

void LoadBattleMonGfxAndAnimate(enum BattlerId battler, bool8 loadMonSprite, u8 spriteId)
{
    BattleLoadSubstituteOrMonSpriteGfx(battler, loadMonSprite);
    StartSpriteAnim(&gSprites[spriteId], 0);

    if (!loadMonSprite)
        gSprites[spriteId].y = GetSubstituteSpriteDefault_Y(battler);
    else
        gSprites[spriteId].y = GetBattlerSpriteDefault_Y(battler);
}

void TrySetBehindSubstituteSpriteBit(enum BattlerId battler, enum Move move)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_SUBSTITUTE || effect == EFFECT_SHED_TAIL)
        gBattleSpritesDataPtr->battlerData[battler].behindSubstitute = 1;
}

void ClearBehindSubstituteBit(enum BattlerId battler)
{
    gBattleSpritesDataPtr->battlerData[battler].behindSubstitute = 0;
}

void HandleLowHpMusicChange(struct Pokemon *mon, enum BattlerId battler)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    if (GetHPBarLevel(hp, maxHP) == HP_BAR_RED)
    {
        if (!gBattleSpritesDataPtr->battlerData[battler].lowHpSong)
        {
            if (!gBattleSpritesDataPtr->battlerData[GetPartnerBattler(battler)].lowHpSong)
                PlaySE(SE_LOW_HEALTH);
            gBattleSpritesDataPtr->battlerData[battler].lowHpSong = 1;
        }
    }
    else
    {
        gBattleSpritesDataPtr->battlerData[battler].lowHpSong = 0;
        if (!IsDoubleBattle())
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            return;
        }
        if (IsDoubleBattle() && !gBattleSpritesDataPtr->battlerData[GetPartnerBattler(battler)].lowHpSong)
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            return;
        }
    }
}

void BattleStopLowHpSound(void)
{
    enum BattlerId playerBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

    gBattleSpritesDataPtr->battlerData[playerBattler].lowHpSong = 0;
    if (IsDoubleBattle())
        gBattleSpritesDataPtr->battlerData[GetPartnerBattler(playerBattler)].lowHpSong = 0;

    m4aSongNumStop(SE_LOW_HEALTH);
}

void HandleBattleLowHpMusicChange(void)
{
    if (gMain.inBattle)
    {
        enum BattlerId playerBattler1 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId playerBattler2 = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        u8 battler1PartyId = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[playerBattler1]);
        u8 battler2PartyId = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[playerBattler2]);
        struct Pokemon mon1 = GetBattlerParty(playerBattler1)[battler1PartyId];
        struct Pokemon mon2 = GetBattlerParty(playerBattler2)[battler2PartyId];

        if (GetMonData(&mon1, MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&mon1, playerBattler1);
        if (IsDoubleBattle())
        {
            if (GetMonData(&mon2, MON_DATA_HP) != 0)
                HandleLowHpMusicChange(&mon2, playerBattler2);
        }
    }
}

void SetBattlerSpriteAffineMode(u8 affineMode)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerSpritePresent(i))
        {
            gSprites[gBattlerSpriteIds[i]].oam.affineMode = affineMode;
            if (affineMode == ST_OAM_AFFINE_OFF)
            {
                gBattleSpritesDataPtr->healthBoxesData[i].matrixNum = gSprites[gBattlerSpriteIds[i]].oam.matrixNum;
                gSprites[gBattlerSpriteIds[i]].oam.matrixNum = 0;
            }
            else
            {
                gSprites[gBattlerSpriteIds[i]].oam.matrixNum = gBattleSpritesDataPtr->healthBoxesData[i].matrixNum;
            }
        }
    }
}

#define tBattlerId   data[0]
#define tSpriteSide  data[1]
#define tBaseTileNum data[2]

#define SPRITE_SIDE_LEFT    0
#define SPRITE_SIDE_RIGHT   1

void CreateEnemyShadowSprite(enum BattlerId battler)
{
    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        enum Species species = GetBattlerVisualSpecies(battler);
        u8 size = gSpeciesInfo[species].enemyShadowSize;

        gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary = CreateSpriteUnchecked(&gSpriteTemplate_EnemyShadow,
                                                                                             GetBattlerSpriteCoord(battler, BATTLER_COORD_X),
                                                                                             GetBattlerSpriteCoord(battler, BATTLER_COORD_Y),
                                                                                             0xC8);
        if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary < MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary];
            sprite->tBattlerId = battler;
            sprite->tSpriteSide = SPRITE_SIDE_LEFT;
            sprite->tBaseTileNum = sprite->oam.tileNum;
            sprite->oam.tileNum = sprite->tBaseTileNum + (8 * size);
            sprite->invisible = TRUE;
        }

        gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary = CreateSpriteUnchecked(&gSpriteTemplate_EnemyShadow,
                                                                                               GetBattlerSpriteCoord(battler, BATTLER_COORD_X),
                                                                                               GetBattlerSpriteCoord(battler, BATTLER_COORD_Y),
                                                                                               0xC8);
        if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary < MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary];
            sprite->tBattlerId = battler;
            sprite->tSpriteSide = SPRITE_SIDE_RIGHT;
            sprite->tBaseTileNum = sprite->oam.tileNum + 4;
            sprite->oam.tileNum = sprite->tBaseTileNum + (8 * size);
            sprite->invisible = TRUE;
        }
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary = CreateSpriteUnchecked(&gSpriteTemplate_EnemyShadow,
                                                                                             GetBattlerSpriteCoord(battler, BATTLER_COORD_X),
                                                                                             GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + 29,
                                                                                             0xC8);
        if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary < MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary];
            sprite->tBattlerId = battler;
            sprite->tBaseTileNum = sprite->oam.tileNum;
            sprite->invisible = TRUE;
        }
    }
}

void LoadAndCreateEnemyShadowSprites(void)
{
    enum BattlerId battler;
    enum BattlerId i;

    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadowsSized);

        // initialize shadow sprite ids
        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleSpritesDataPtr->healthBoxesData[i].shadowSpriteIdPrimary = MAX_SPRITES;
            gBattleSpritesDataPtr->healthBoxesData[i].shadowSpriteIdSecondary = MAX_SPRITES;
        }
    }
    else
    {
        LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadow);

        // initialize shadow sprite ids
        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleSpritesDataPtr->healthBoxesData[i].shadowSpriteIdPrimary = MAX_SPRITES;
        }
    }

    battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    CreateEnemyShadowSprite(battler);

    if (IsDoubleBattle())
    {
        battler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        CreateEnemyShadowSprite(battler);
    }
}

void SpriteCB_EnemyShadow(struct Sprite *shadowSprite)
{
    if (gBattleSpritesDataPtr == NULL)
    {
        shadowSprite->callback = SpriteCB_SetInvisible;
        return;
    }

    bool8 invisible = FALSE;
    enum BattlerId battler = shadowSprite->tBattlerId;
    struct Sprite *battlerSprite = &gSprites[gBattlerSpriteIds[battler]];
    enum Species transformSpecies = SanitizeSpeciesId(gBattleSpritesDataPtr->battlerData[battler].transformSpecies);

    if (!battlerSprite->inUse || !IsBattlerSpritePresent(battler))
    {
        shadowSprite->callback = SpriteCB_SetInvisible;
        return;
    }

    s8 xOffset = 0, yOffset = 0, size = SHADOW_SIZE_S;
    if (gAnimScriptActive || battlerSprite->invisible)
    {
        invisible = TRUE;
    }
    else if (transformSpecies != SPECIES_NONE)
    {
        xOffset = gSpeciesInfo[transformSpecies].enemyShadowXOffset;
        yOffset = gSpeciesInfo[transformSpecies].enemyShadowYOffset + 16;
        size = gSpeciesInfo[transformSpecies].enemyShadowSize;

        if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4)
            xOffset += (shadowSprite->tSpriteSide == SPRITE_SIDE_LEFT ? -16 : 16);

        invisible = (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
                  ? gSpeciesInfo[transformSpecies].suppressEnemyShadow
                  : gSpeciesInfo[transformSpecies].enemyMonElevation == 0;
    }
    else if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        enum Species species = GetBattlerVisualSpecies(battler);
        xOffset = gSpeciesInfo[species].enemyShadowXOffset + (shadowSprite->tSpriteSide == SPRITE_SIDE_LEFT ? -16 : 16);
        yOffset = gSpeciesInfo[species].enemyShadowYOffset + 16;
        size = gSpeciesInfo[species].enemyShadowSize;
    }

    if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
        invisible = TRUE;

    shadowSprite->x = battlerSprite->x + xOffset;
    shadowSprite->x2 = battlerSprite->x2;
    shadowSprite->invisible = invisible;

    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        shadowSprite->oam.tileNum = shadowSprite->tBaseTileNum + (8 * size);
        shadowSprite->y = battlerSprite->y + yOffset;
    }
}

#undef tBattlerId

void SpriteCB_SetInvisible(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
}

void SetBattlerShadowSpriteCallback(enum BattlerId battler, enum Species species)
{
    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        if (IsOnPlayerSide(battler) || gBattleScripting.monCaught)
        {
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary].callback = SpriteCB_SetInvisible;
            return;
        }

        if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary >= MAX_SPRITES
            || gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary >= MAX_SPRITES)
            return;

        if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != SPECIES_NONE)
            species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;

        if (gSpeciesInfo[SanitizeSpeciesId(species)].suppressEnemyShadow == FALSE)
        {
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_EnemyShadow;
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary].callback = SpriteCB_EnemyShadow;
        }
        else
        {
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary].callback = SpriteCB_SetInvisible;
        }
    }
    else
    {
        if (IsOnPlayerSide(battler) || gBattleScripting.monCaught)
        {
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
            return;
        }

        if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary >= MAX_SPRITES)
            return;

        if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != SPECIES_NONE)
            species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;

        if (gSpeciesInfo[SanitizeSpeciesId(species)].enemyMonElevation != 0)
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_EnemyShadow;
        else
            gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
    }
}

void HideBattlerShadowSprite(enum BattlerId battler)
{
    gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary].callback = SpriteCB_SetInvisible;
}

// Color the background tiles surrounding the action selection and move windows
void FillAroundBattleWindows(void)
{
    u16 *vramPtr = (u16 *)(VRAM + 0x240);
    s32 i;
    s32 j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (!(*vramPtr & 0xF000))
                *vramPtr |= 0xF000;
            if (!(*vramPtr & 0x0F00))
                *vramPtr |= 0x0F00;
            if (!(*vramPtr & 0x00F0))
                *vramPtr |= 0x00F0;
            if (!(*vramPtr & 0x000F))
                *vramPtr |= 0x000F;
            vramPtr++;
        }
    }
}

void ClearTemporarySpeciesSpriteData(enum BattlerId battler, bool32 dontClearTransform, bool32 dontClearSubstitute)
{
    if (!dontClearTransform)
        gBattleSpritesDataPtr->battlerData[battler].transformSpecies = SPECIES_NONE;
    if (!dontClearSubstitute)
        ClearBehindSubstituteBit(battler);
}

void AllocateMonSpritesGfx(void)
{
    gMonSpritesGfxPtr = NULL;
    gMonSpritesGfxPtr = AllocZeroed(sizeof(*gMonSpritesGfxPtr));
    gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(MON_PIC_SIZE * MAX_MON_PIC_FRAMES * MAX_BATTLERS_COUNT);

    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gMonSpritesGfxPtr->spritesGfx[i] = gMonSpritesGfxPtr->firstDecompressed + (i * MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
        gMonSpritesGfxPtr->templates[i] = gBattlerSpriteTemplates[i];

        for (u32 j = 0; j < MAX_MON_PIC_FRAMES; j++)
        {
            if (gMonSpritesGfxPtr->spritesGfx[i])
            {
                gMonSpritesGfxPtr->frameImages[i][j].data = gMonSpritesGfxPtr->spritesGfx[i] + (j * MON_PIC_SIZE);
                gMonSpritesGfxPtr->frameImages[i][j].size = MON_PIC_SIZE;
            }
        }

        gMonSpritesGfxPtr->templates[i].images = gMonSpritesGfxPtr->frameImages[i];
    }

    gMonSpritesGfxPtr->barFontGfx = AllocZeroed(0x1000);
}

void FreeMonSpritesGfx(void)
{
    if (gMonSpritesGfxPtr == NULL)
        return;

    TRY_FREE_AND_SET_NULL(gMonSpritesGfxPtr->buffer);
    FREE_AND_SET_NULL(gMonSpritesGfxPtr->barFontGfx);
    FREE_AND_SET_NULL(gMonSpritesGfxPtr->firstDecompressed);
    gMonSpritesGfxPtr->spritesGfx[B_POSITION_PLAYER_LEFT] = NULL;
    gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_LEFT] = NULL;
    gMonSpritesGfxPtr->spritesGfx[B_POSITION_PLAYER_RIGHT] = NULL;
    gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_RIGHT] = NULL;
    FREE_AND_SET_NULL(gMonSpritesGfxPtr);
}

bool32 ShouldPlayNormalMonCry(struct Pokemon *mon)
{
    s16 hp, maxHP;
    s32 barLevel;

    if (GetMonData(mon, MON_DATA_STATUS) & (STATUS1_ANY | STATUS1_TOXIC_COUNTER))
        return FALSE;

    hp = GetMonData(mon, MON_DATA_HP);
    maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    barLevel = GetHPBarLevel(hp, maxHP);
    if (barLevel <= HP_BAR_YELLOW)
        return FALSE;

    return TRUE;
}

void DecompressGhostFrontPic(enum BattlerId battler)
{
    u16 palOffset;
    enum BattlerPosition position = GetBattlerPosition(battler);

    DecompressDataWithHeaderWram(gGhostFrontPic, gMonSpritesGfxPtr->spritesGfx[position]);
    palOffset = OBJ_PLTT_ID(battler);
    LoadPalette(gGhostPalette, palOffset, PLTT_SIZE_4BPP);
    LoadPalette(gGhostPalette, BG_PLTT_ID(8) + BG_PLTT_ID(battler), PLTT_SIZE_4BPP);
}
