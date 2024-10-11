#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_ai_main.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "battle_interface.h"
#include "main.h"
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
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/battle_palace.h"
#include "constants/battle_move_effects.h"


extern const struct CompressedSpriteSheet gSpriteSheet_EnemyShadow;
extern const struct SpriteTemplate gSpriteTemplate_EnemyShadow;

// this file's functions
static u8 GetBattlePalaceMoveGroup(u8 battler, u16 move);
static u16 GetBattlePalaceTarget(u32 battler);
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
u16 ChooseMoveAndTargetInBattlePalace(u32 battler)
{
    s32 i, var1, var2;
    s32 chosenMoveId = -1;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    u8 unusableMovesBits = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    s32 percent = Random() % 100;

    // Heavy variable re-use here makes this hard to read without defines
    // Possibly just optimization? might still match with additional vars
    #define maxGroupNum var1
    #define minGroupNum var2
    #define selectedGroup percent
    #define selectedMoves var2
    #define moveTarget var1
    #define numMovesPerGroup var1
    #define numMultipleMoveGroups var2
    #define randSelectGroup var2

    // If battler is < 50% HP and not asleep, use second set of move group likelihoods
    // otherwise use first set
    i = (gBattleStruct->palaceFlags & gBitTable[battler]) ? 2 : 0;
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
        if (selectedGroup == GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) && moveInfo->currentPp[i] != 0)
            selectedMoves |= gBitTable[i];
    }

    // Pass selected moves to AI, pick one
    if (selectedMoves != 0)
    {
        // Lower 4 bits of palaceFlags are flags for each battler.
        // Clear the rest of palaceFlags, then set the selected moves in the upper 4 bits.
        gBattleStruct->palaceFlags &= (1 << MAX_BATTLERS_COUNT) - 1;
        gBattleStruct->palaceFlags |= (selectedMoves << MAX_BATTLERS_COUNT);
        BattleAI_SetupAIData(selectedMoves, battler);
        chosenMoveId = BattleAI_ChooseMoveOrAction();
    }

    // If no moves matched the selected group, pick a new move from groups the Pokémon has
    // In this case the AI is not checked again, so the choice may be worse
    // If a move is chosen this way, there's a 50% chance that it will be unable to use it anyway
    if (chosenMoveId == -1 || chosenMoveId >= MAX_MON_MOVES)
    {
        chosenMoveId = -1;
        if (unusableMovesBits != ALL_MOVES_MASK)
        {
            numMovesPerGroup = 0, numMultipleMoveGroups = 0;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                // Count the number of usable moves the battler has in each move group.
                // The totals will be stored separately in 3 groups of 4 bits each in numMovesPerGroup.
                if (GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) == PALACE_MOVE_GROUP_ATTACK && !(gBitTable[i] & unusableMovesBits))
                    numMovesPerGroup += (1 << 0);
                if (GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) == PALACE_MOVE_GROUP_DEFENSE && !(gBitTable[i] & unusableMovesBits))
                    numMovesPerGroup += (1 << 4);
                if (GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]) == PALACE_MOVE_GROUP_SUPPORT && !(gBitTable[i] & unusableMovesBits))
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
                    if (!(gBitTable[i] & unusableMovesBits))
                        chosenMoveId = i;
                } while (chosenMoveId == -1);
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
                    if (!(gBitTable[i] & unusableMovesBits) && randSelectGroup == GetBattlePalaceMoveGroup(battler, moveInfo->moves[i]))
                        chosenMoveId = i;
                } while (chosenMoveId == -1);
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

    moveTarget = GetBattlerMoveTargetType(battler, moveInfo->moves[chosenMoveId]);

    if (moveTarget & MOVE_TARGET_USER)
        chosenMoveId |= (battler << 8);
    else if (moveTarget == MOVE_TARGET_SELECTED)
        chosenMoveId |= GetBattlePalaceTarget(battler);
    else
        chosenMoveId |= (GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerSide(battler))) << 8);

    return chosenMoveId;
}

#undef maxGroupNum
#undef minGroupNum
#undef selectedGroup
#undef selectedMoves
#undef moveTarget
#undef numMovesPerGroup
#undef numMultipleMoveGroups
#undef randSelectGroup

static u8 GetBattlePalaceMoveGroup(u8 battler, u16 move)
{
    switch (GetBattlerMoveTargetType(battler, move))
    {
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
        if (IS_MOVE_STATUS(move))
            return PALACE_MOVE_GROUP_SUPPORT;
        else
            return PALACE_MOVE_GROUP_ATTACK;
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_OPPONENTS_FIELD:
        return PALACE_MOVE_GROUP_SUPPORT;
    case MOVE_TARGET_USER:
        return PALACE_MOVE_GROUP_DEFENSE;
    default:
        return PALACE_MOVE_GROUP_ATTACK;
    }
}

static u16 GetBattlePalaceTarget(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u8 opposing1, opposing2;

        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
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
            return (BATTLE_OPPOSITE(battler & BIT_SIDE) + (Random() & 2)) << 8;

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
            return (BATTLE_OPPOSITE(battler & BIT_SIDE) + (Random() & 2)) << 8;
        }
    }

    return BATTLE_OPPOSITE(battler) << 8;
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

// Slide up to 0 if necessary (used by multi battle intro)
static void SpriteCB_TrainerSlideVertical(struct Sprite *sprite)
{
    sprite->y2 -= 2;
    if (sprite->y2 == 0)
        sprite->callback = SpriteCallbackDummy;
}

#undef sSpeedX

void InitAndLaunchChosenStatusAnimation(u32 battler, bool32 isStatus2, u32 status)
{
    gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 1;
    if (!isStatus2)
    {
        if (status == STATUS1_FREEZE || status == STATUS1_FROSTBITE)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_FRZ);
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
        if (status & STATUS2_INFATUATION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_INFATUATION);
        else if (status & STATUS2_CONFUSION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_CONFUSION);
        else if (status & STATUS2_CURSED)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_CURSED);
        else if (status & STATUS2_NIGHTMARE)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_NIGHTMARE);
        else if (status & STATUS2_WRAPPED)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_WRAPPED); // this animation doesn't actually exist
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
    {
        gBattleStruct->illusion[activeBattler].broken = 1;
        gBattleStruct->illusion[activeBattler].on = 0;
    }

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
    case B_ANIM_SUBSTITUTE_FADE:
    case B_ANIM_RAIN_CONTINUES:
    case B_ANIM_SUN_CONTINUES:
    case B_ANIM_SANDSTORM_CONTINUES:
    case B_ANIM_HAIL_CONTINUES:
    case B_ANIM_SNOW_CONTINUES:
    case B_ANIM_FOG_CONTINUES:
    case B_ANIM_SNATCH_MOVE:
        return TRUE;
    default:
        return FALSE;
    }
}

#define tBattlerId data[0]

void InitAndLaunchSpecialAnimation(u8 activeBattler, u8 atkBattler, u8 defBattler, u8 tableId)
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
bool8 IsBattleSEPlaying(u8 battler)
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

void BattleLoadMonSpriteGfx(struct Pokemon *mon, u32 battler)
{
    u32 monsPersonality, currentPersonality, isShiny, species, paletteOffset, position;
    const void *lzPaletteData;
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    if (illusionMon != NULL)
        mon = illusionMon;

    if (GetMonData(mon, MON_DATA_IS_EGG) || GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE) // Don't load GFX of egg pokemon.
        return;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    isShiny = GetMonData(mon, MON_DATA_IS_SHINY);

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_NONE)
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        currentPersonality = monsPersonality;
    }
    else
    {
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;
        if (B_TRANSFORM_SHINY >= GEN_4)
        {
            currentPersonality = gTransformedPersonalities[battler];
            isShiny = gTransformedShininess[battler];
        }
        else
        {
            currentPersonality = monsPersonality;
        }
    }

    position = GetBattlerPosition(battler);
    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        HandleLoadSpecialPokePic(TRUE,
                                 gMonSpritesGfxPtr->spritesGfx[position],
                                 species, currentPersonality);
    }
    else
    {
        HandleLoadSpecialPokePic(FALSE,
                                 gMonSpritesGfxPtr->spritesGfx[position],
                                 species, currentPersonality);
    }

    paletteOffset = OBJ_PLTT_ID(battler);

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, currentPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, PLTT_SIZE_4BPP);
    LoadPalette(gDecompressionBuffer, BG_PLTT_ID(8) + BG_PLTT_ID(battler), PLTT_SIZE_4BPP);

    // transform's pink color
    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != SPECIES_NONE)
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

void BattleGfxSfxDummy2(u16 species)
{
}

void DecompressTrainerFrontPic(u16 frontPicId, u8 battler)
{
    u8 position = GetBattlerPosition(battler);
    DecompressPicFromTable(&gTrainerSprites[frontPicId].frontPic,
                           gMonSpritesGfxPtr->spritesGfx[position]);
    LoadCompressedSpritePalette(&gTrainerSprites[frontPicId].palette);
}

void DecompressTrainerBackPic(u16 backPicId, u8 battler)
{
    u8 position = GetBattlerPosition(battler);
    DecompressPicFromTable(&gTrainerBacksprites[backPicId].backPic,
                           gMonSpritesGfxPtr->spritesGfx[position]);
    LoadCompressedPalette(gTrainerBacksprites[backPicId].palette.data,
                          OBJ_PLTT_ID(battler), PLTT_SIZE_4BPP);
}

void FreeTrainerFrontPicPalette(u16 frontPicId)
{
    FreeSpritePaletteByTag(gTrainerSprites[frontPicId].palette.tag);
}

// Unused.
void BattleLoadAllHealthBoxesGfxAtOnce(void)
{
    u8 numberOfBattlers = 0;
    u8 i;

    LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[0]);
    LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[1]);
    if (!IsDoubleBattle())
    {
        LoadCompressedSpriteSheet(&sSpriteSheet_SinglesPlayerHealthbox);
        LoadCompressedSpriteSheet(&sSpriteSheet_SinglesOpponentHealthbox);
        numberOfBattlers = 2;
    }
    else
    {
        LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[0]);
        LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[1]);
        LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[0]);
        LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[1]);
        numberOfBattlers = MAX_BATTLERS_COUNT;
    }
    for (i = 0; i < numberOfBattlers; i++)
        LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(i)]);
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
            LoadIndicatorSpritesGfx();
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
                LoadCompressedSpriteSheet(&sSpriteSheet_SinglesOpponentHealthbox);
            else if (state == 4)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(0)]);
            else if (state == 5)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(1)]);
            else
                retVal = TRUE;
        }
        else
        {
            if (state == 2)
            {
                if (WhichBattleCoords(0))
                    LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[0]);
                else
                    LoadCompressedSpriteSheet(&sSpriteSheet_SinglesPlayerHealthbox);
            }
            else if (state == 3)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[1]);
            else if (state == 4)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[0]);
            else if (state == 5)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[1]);
            else if (state == 6)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(0)]);
            else if (state == 7)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(1)]);
            else if (state == 8)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(2)]);
            else if (state == 9)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[GetBattlerPosition(3)]);
            else
                retVal = TRUE;
        }
    }

    return retVal;
}

void LoadBattleBarGfx(u8 unused)
{
    LZDecompressWram(gBattleInterfaceGfx_BattleBar, gMonSpritesGfxPtr->barFontGfx);
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
        if (GetBattlerSide(*battler) == B_SIDE_PLAYER)
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
                UpdateHealthboxAttribute(gHealthboxSpriteIds[*battler], &gPlayerParty[gBattlerPartyIndexes[*battler]], HEALTHBOX_ALL);
        }
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[*battler], &gEnemyParty[gBattlerPartyIndexes[*battler]], HEALTHBOX_ALL);
        }
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
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
        gBattleSpritesDataPtr->battlerData[i].invisible = gSprites[gBattlerSpriteIds[i]].invisible;
}

void CopyBattleSpriteInvisibility(u8 battler)
{
    gBattleSpritesDataPtr->battlerData[battler].invisible = gSprites[gBattlerSpriteIds[battler]].invisible;
}

void HandleSpeciesGfxDataChange(u8 battlerAtk, u8 battlerDef, bool32 megaEvo, bool8 trackEnemyPersonality)
{
    u32 personalityValue, position, paletteOffset, targetSpecies;
    bool8 isShiny;
    const void *lzPaletteData, *src;
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

        if (GetBattlerSide(battlerDef) == B_SIDE_OPPONENT)
            targetSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_SPECIES);
        else
            targetSpecies = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_SPECIES);

        if (GetBattlerSide(battlerAtk) == B_SIDE_PLAYER)
        {
            if (B_TRANSFORM_SHINY >= GEN_4 && trackEnemyPersonality)
            {
                personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_PERSONALITY);
                isShiny = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_IS_SHINY);
            }
            else
            {
                personalityValue = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_PERSONALITY);
                isShiny = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_IS_SHINY);
            }

            HandleLoadSpecialPokePic(FALSE,
                                     gMonSpritesGfxPtr->spritesGfx[position],
                                     targetSpecies,
                                     personalityValue);
        }
        else
        {
            if (B_TRANSFORM_SHINY >= GEN_4 && trackEnemyPersonality)
            {
                personalityValue = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_PERSONALITY);
                isShiny = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerDef]], MON_DATA_IS_SHINY);
            }
            else
            {
                personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_PERSONALITY);
                isShiny = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_IS_SHINY);
            }

            HandleLoadSpecialPokePic(TRUE,
                                     gMonSpritesGfxPtr->spritesGfx[position],
                                     targetSpecies,
                                     personalityValue);
        }
    }
    src = gMonSpritesGfxPtr->spritesGfx[position];
    dst = (void *)(OBJ_VRAM0 + gSprites[gBattlerSpriteIds[battlerAtk]].oam.tileNum * 32);
    DmaCopy32(3, src, dst, MON_PIC_SIZE);
    paletteOffset = OBJ_PLTT_ID(battlerAtk);
    lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(targetSpecies, isShiny, personalityValue);
    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, PLTT_SIZE_4BPP);

    if (!megaEvo)
    {
        BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
        CpuCopy32(&gPlttBufferFaded[paletteOffset], &gPlttBufferUnfaded[paletteOffset], PLTT_SIZEOF(16));
        if (!IsContest())
        {
            gBattleSpritesDataPtr->battlerData[battlerAtk].transformSpecies = targetSpecies;
        }
    }

    gSprites[gBattlerSpriteIds[battlerAtk]].y = GetBattlerSpriteDefault_Y(battlerAtk);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerAtk]], 0);
}

void BattleLoadSubstituteOrMonSpriteGfx(u8 battler, bool8 loadMonSprite)
{
    s32 i, position, palOffset;

    if (!loadMonSprite)
    {
        if (IsContest())
            position = B_POSITION_PLAYER_LEFT;
        else
            position = GetBattlerPosition(battler);

        if (IsContest())
            LZDecompressVram(gBattleAnimSpriteGfx_SubstituteBack, gMonSpritesGfxPtr->spritesGfx[position]);
        else if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            LZDecompressVram(gBattleAnimSpriteGfx_Substitute, gMonSpritesGfxPtr->spritesGfx[position]);
        else
            LZDecompressVram(gBattleAnimSpriteGfx_SubstituteBack, gMonSpritesGfxPtr->spritesGfx[position]);

        for (i = 1; i < 4; i++)
        {
            Dma3CopyLarge32_(gMonSpritesGfxPtr->spritesGfx[position], &gMonSpritesGfxPtr->spritesGfx[position][MON_PIC_SIZE * i], MON_PIC_SIZE);
        }

        palOffset = OBJ_PLTT_ID(battler);
        LoadCompressedPalette(gBattleAnimSpritePal_Substitute, palOffset, PLTT_SIZE_4BPP);
    }
    else
    {
        if (!IsContest())
            BattleLoadMonSpriteGfx(&GetBattlerParty(battler)[gBattlerPartyIndexes[battler]], battler);
    }
}

void LoadBattleMonGfxAndAnimate(u8 battler, bool8 loadMonSprite, u8 spriteId)
{
    BattleLoadSubstituteOrMonSpriteGfx(battler, loadMonSprite);
    StartSpriteAnim(&gSprites[spriteId], 0);

    if (!loadMonSprite)
        gSprites[spriteId].y = GetSubstituteSpriteDefault_Y(battler);
    else
        gSprites[spriteId].y = GetBattlerSpriteDefault_Y(battler);
}

void TrySetBehindSubstituteSpriteBit(u8 battler, u16 move)
{
    if (gMovesInfo[move].effect == EFFECT_SUBSTITUTE || gMovesInfo[move].effect == EFFECT_SHED_TAIL)
        gBattleSpritesDataPtr->battlerData[battler].behindSubstitute = 1;
}

void ClearBehindSubstituteBit(u8 battler)
{
    gBattleSpritesDataPtr->battlerData[battler].behindSubstitute = 0;
}

void HandleLowHpMusicChange(struct Pokemon *mon, u8 battler)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    if (GetHPBarLevel(hp, maxHP) == HP_BAR_RED)
    {
        if (!gBattleSpritesDataPtr->battlerData[battler].lowHpSong)
        {
            if (!gBattleSpritesDataPtr->battlerData[BATTLE_PARTNER(battler)].lowHpSong)
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
        if (IsDoubleBattle() && !gBattleSpritesDataPtr->battlerData[BATTLE_PARTNER(battler)].lowHpSong)
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            return;
        }
    }
}

void BattleStopLowHpSound(void)
{
    u8 playerBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

    gBattleSpritesDataPtr->battlerData[playerBattler].lowHpSong = 0;
    if (IsDoubleBattle())
        gBattleSpritesDataPtr->battlerData[BATTLE_PARTNER(playerBattler)].lowHpSong = 0;

    m4aSongNumStop(SE_LOW_HEALTH);
}

u8 GetMonHPBarLevel(struct Pokemon *mon)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    return GetHPBarLevel(hp, maxHP);
}

void HandleBattleLowHpMusicChange(void)
{
    if (gMain.inBattle)
    {
        u8 playerBattler1 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        u8 playerBattler2 = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        u8 battler1PartyId = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[playerBattler1]);
        u8 battler2PartyId = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[playerBattler2]);

        if (GetMonData(&gPlayerParty[battler1PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[battler1PartyId], playerBattler1);
        if (IsDoubleBattle() && GetMonData(&gPlayerParty[battler2PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[battler2PartyId], playerBattler2);
    }
}

void SetBattlerSpriteAffineMode(u8 affineMode)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
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

#define tBattlerId data[0]

void CreateEnemyShadowSprite(u32 battler)
{
    gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId = CreateSprite(&gSpriteTemplate_EnemyShadow,
                                                                                    GetBattlerSpriteCoord(battler, BATTLER_COORD_X),
                                                                                    GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + 29,
                                                                                    0xC8);
    if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId < MAX_SPRITES)
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId].data[0] = battler;
}

void LoadAndCreateEnemyShadowSprites(void)
{
    u8 battler;
    u32 i;

    LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadow);

    // initialize shadow sprite ids
    for (i = 0; i < gBattlersCount; i++)
    {
        gBattleSpritesDataPtr->healthBoxesData[i].shadowSpriteId = MAX_SPRITES;
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
    bool8 invisible = FALSE;
    u8 battler = shadowSprite->tBattlerId;
    struct Sprite *battlerSprite = &gSprites[gBattlerSpriteIds[battler]];
    u16 transformSpecies = SanitizeSpeciesId(gBattleSpritesDataPtr->battlerData[battler].transformSpecies);

    if (!battlerSprite->inUse || !IsBattlerSpritePresent(battler))
    {
        shadowSprite->callback = SpriteCB_SetInvisible;
        return;
    }
    if (gAnimScriptActive || battlerSprite->invisible)
        invisible = TRUE;
    else if (transformSpecies != SPECIES_NONE && gSpeciesInfo[transformSpecies].enemyMonElevation == 0)
        invisible = TRUE;

    if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
        invisible = TRUE;

    shadowSprite->x = battlerSprite->x;
    shadowSprite->x2 = battlerSprite->x2;
    shadowSprite->invisible = invisible;
}

#undef tBattlerId

void SpriteCB_SetInvisible(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
}

void SetBattlerShadowSpriteCallback(u8 battler, u16 species)
{
    // The player's shadow is never seen.
    if (GetBattlerSide(battler) == B_SIDE_PLAYER || gBattleScripting.monCaught)
        return;
    if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId >= MAX_SPRITES)
        return;

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != SPECIES_NONE)
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;

    if (gSpeciesInfo[SanitizeSpeciesId(species)].enemyMonElevation != 0)
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId].callback = SpriteCB_EnemyShadow;
    else
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId].callback = SpriteCB_SetInvisible;
}

void HideBattlerShadowSprite(u8 battler)
{
    gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteId].callback = SpriteCB_SetInvisible;
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

void ClearTemporarySpeciesSpriteData(u8 battler, bool8 dontClearSubstitute)
{
    gBattleSpritesDataPtr->battlerData[battler].transformSpecies = SPECIES_NONE;
    if (!dontClearSubstitute)
        ClearBehindSubstituteBit(battler);
}

void AllocateMonSpritesGfx(void)
{
    u8 i = 0, j;

    gMonSpritesGfxPtr = NULL;
    gMonSpritesGfxPtr = AllocZeroed(sizeof(*gMonSpritesGfxPtr));
    gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(MON_PIC_SIZE * 4 * MAX_BATTLERS_COUNT);

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gMonSpritesGfxPtr->spritesGfx[i] = gMonSpritesGfxPtr->firstDecompressed + (i * MON_PIC_SIZE * 4);
        gMonSpritesGfxPtr->templates[i] = gBattlerSpriteTemplates[i];

        for (j = 0; j < MAX_MON_PIC_FRAMES; j++)
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
