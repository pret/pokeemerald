#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_ai_script_commands.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "battle_interface.h"
#include "main.h"
#include "alloc.h"
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
#include "constants/species.h"
#include "decompress.h"
#include "data.h"
#include "palette.h"
#include "contest.h"
#include "constants/songs.h"
#include "constants/rgb.h"

extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MusicPlayerInfo gMPlayInfo_BGM;

extern const u8 gUnknown_0831C604[];
extern const u8 * const gBattleAnims_General[];
extern const u8 * const gBattleAnims_Special[];
extern const struct CompressedSpriteSheet gSpriteSheet_EnemyShadow;
extern const struct SpriteTemplate gSpriteTemplate_EnemyShadow;

// this file's functions
static u8 sub_805D4A8(u16 move);
static u16 BattlePalaceGetTargetRetValue(void);
static void sub_805D7EC(struct Sprite *sprite);
static bool8 ShouldAnimBeDoneRegardlessOfSubsitute(u8 animId);
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

static const struct SpritePalette sSpritePalettes_HealthBoxHealthBar[2] =
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

u16 ChooseMoveAndTargetInBattlePalace(void)
{
    s32 i, var1, var2;
    s32 chosenMoveId = -1;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]);
    u8 unusableMovesBits = CheckMoveLimitations(gActiveBattler, 0, 0xFF);
    s32 percent = Random() % 100;

    i = (gBattleStruct->field_92 & gBitTable[gActiveBattler]) ? 2 : 0;
    var2 = i;
    var1 = i + 2;

    for (; i < var1; i++)
    {
        if (gUnknown_0831C494[GetNatureFromPersonality(gBattleMons[gActiveBattler].personality)][i] > percent)
            break;
    }

    percent = i - var2;
    if (i == var1)
        percent = 2;

    for (var2 = 0, i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moveInfo->moves[i] == MOVE_NONE)
            break;
        if (percent == sub_805D4A8(moveInfo->moves[i]) && moveInfo->currentPp[i] != 0)
            var2 |= gBitTable[i];
    }

    if (var2 != 0)
    {
        gBattleStruct->field_92 &= 0xF;
        gBattleStruct->field_92 |= (var2 << 4);
        BattleAI_SetupAIData(var2);
        chosenMoveId = BattleAI_ChooseMoveOrAction();
    }

    if (chosenMoveId == -1)
    {
        if (unusableMovesBits != 0xF)
        {
            var1 = 0, var2 = 0;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (sub_805D4A8(moveInfo->moves[i]) == 0 && !(gBitTable[i] & unusableMovesBits))
                    var1 += 0x1;
                if (sub_805D4A8(moveInfo->moves[i]) == 1 && !(gBitTable[i] & unusableMovesBits))
                    var1 += 0x10;
                if (sub_805D4A8(moveInfo->moves[i]) == 2 && !(gBitTable[i] & unusableMovesBits))
                    var1 += 0x100;
            }

            if ((var1 & 0xF) > 1)
                var2++;
            if ((var1 & 0xF0) > 0x1F)
                var2++;
            if ((var1 & 0xF0) > 0x1FF)
                var2++;

            if (var2 > 1 || var2 == 0)
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
                if ((var1 & 0xF) > 1)
                    var2 = 0;
                if ((var1 & 0xF0) > 0x1F)
                    var2 = 1;
                if ((var1 & 0xF0) > 0x1FF)
                    var2 = 2;

                do
                {
                    i = Random() % MAX_MON_MOVES;
                    if (!(gBitTable[i] & unusableMovesBits) && var2 == sub_805D4A8(moveInfo->moves[i]))
                        chosenMoveId = i;
                } while (chosenMoveId == -1);
            }

            if (Random() % 100 > 49)
            {
                gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
                return 0;
            }
        }
        else
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
            return 0;
        }
    }

    if (moveInfo->moves[chosenMoveId] == MOVE_CURSE)
    {
        if (moveInfo->monType1 != TYPE_GHOST && moveInfo->monType2 != TYPE_GHOST && moveInfo->monType3 != TYPE_GHOST)
            var1 = MOVE_TARGET_USER;
        else
            var1 = MOVE_TARGET_SELECTED;
    }
    else
    {
        var1 = gBattleMoves[moveInfo->moves[chosenMoveId]].target;
    }

    if (var1 & MOVE_TARGET_USER)
        chosenMoveId |= (gActiveBattler << 8);
    else if (var1 == MOVE_TARGET_SELECTED)
        chosenMoveId |= (BattlePalaceGetTargetRetValue());
    else
        chosenMoveId |= (GetBattlerAtPosition((GetBattlerPosition(gActiveBattler) & BIT_SIDE) ^ BIT_SIDE) << 8);

    return chosenMoveId;
}

static u8 sub_805D4A8(u16 move)
{
    switch (gBattleMoves[move].target)
    {
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
        if (gBattleMoves[move].power == 0)
            return 2;
        else
            return 0;
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_OPPONENTS_FIELD:
        return 2;
    case MOVE_TARGET_USER:
        return 1;
    default:
        return 0;
    }
}

static u16 BattlePalaceGetTargetRetValue(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u8 opposing1, opposing2;

        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
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
            return (((gActiveBattler & BIT_SIDE) ^ BIT_SIDE) + (Random() & 2)) << 8;

        switch (gUnknown_0831C604[GetNatureFromPersonality(gBattleMons[gActiveBattler].personality)])
        {
        case 0:
            if (gBattleMons[opposing1].hp > gBattleMons[opposing2].hp)
                return opposing1 << 8;
            else
                return opposing2 << 8;
        case 1:
            if (gBattleMons[opposing1].hp < gBattleMons[opposing2].hp)
                return opposing1 << 8;
            else
                return opposing2 << 8;
        case 2:
            return (((gActiveBattler & BIT_SIDE) ^ BIT_SIDE) + (Random() & 2)) << 8;
        }
    }

    return (gActiveBattler ^ BIT_SIDE) << 8;
}

void sub_805D714(struct Sprite *sprite)
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

void sub_805D770(struct Sprite *sprite, bool8 arg1)
{
    sprite->animPaused = 1;
    sprite->callback = SpriteCallbackDummy;

    if (!arg1)
        StartSpriteAffineAnim(sprite, 1);
    else
        StartSpriteAffineAnim(sprite, 1);

    AnimateSprite(sprite);
}

void sub_805D7AC(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->pos2.x += sprite->data[0];
        if (sprite->pos2.x == 0)
        {
            if (sprite->pos2.y != 0)
                sprite->callback = sub_805D7EC;
            else
                sprite->callback = SpriteCallbackDummy;
        }
    }
}

static void sub_805D7EC(struct Sprite *sprite)
{
    sprite->pos2.y -= 2;
    if (sprite->pos2.y == 0)
        sprite->callback = SpriteCallbackDummy;
}

void InitAndLaunchChosenStatusAnimation(bool8 isStatus2, u32 status)
{
    gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive = 1;
    if (!isStatus2)
    {
        if (status == STATUS1_FREEZE)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_FRZ);
        else if (status == STATUS1_POISON || status & STATUS1_TOXIC_POISON)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_PSN);
        else if (status == STATUS1_BURN)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_BRN);
        else if (status & STATUS1_SLEEP)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_SLP);
        else if (status == STATUS1_PARALYSIS)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_PRZ);
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive = 0;
    }
    else
    {
        if (status & STATUS2_INFATUATION)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_INFATUATION);
        else if (status & STATUS2_CONFUSION)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_CONFUSION);
        else if (status & STATUS2_CURSED)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_CURSED);
        else if (status & STATUS2_NIGHTMARE)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_NIGHTMARE);
        else if (status & STATUS2_WRAPPED)
            LaunchStatusAnimation(gActiveBattler, B_ANIM_STATUS_WRAPPED); // this animation doesn't actually exist
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive = 0;
    }
}

#define tBattlerId data[0]

bool8 TryHandleLaunchBattleTableAnimation(u8 activeBattler, u8 atkBattler, u8 defBattler, u8 tableId, u16 argument)
{
    u8 taskId;

    if (tableId == B_ANIM_CASTFORM_CHANGE && (argument & 0x80))
    {
        gBattleMonForms[activeBattler] = (argument & ~(0x80));
        return TRUE;
    }
    if (gBattleSpritesDataPtr->battlerData[activeBattler].behindSubstitute
        && !ShouldAnimBeDoneRegardlessOfSubsitute(tableId))
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

    gBattleAnimAttacker = atkBattler;
    gBattleAnimTarget = defBattler;
    gBattleSpritesDataPtr->animationData->animArg = argument;
    LaunchBattleAnimation(gBattleAnims_General, tableId, FALSE);
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

static bool8 ShouldAnimBeDoneRegardlessOfSubsitute(u8 animId)
{
    switch (animId)
    {
    case B_ANIM_SUBSTITUTE_FADE:
    case B_ANIM_RAIN_CONTINUES:
    case B_ANIM_SUN_CONTINUES:
    case B_ANIM_SANDSTORM_CONTINUES:
    case B_ANIM_HAIL_CONTINUES:
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
    LaunchBattleAnimation(gBattleAnims_Special, tableId, FALSE);
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

// Great function to include newly added moves that don't have animation yet.
bool8 IsMoveWithoutAnimation(u16 moveId, u8 animationTurn)
{
    if (moveId >= (MOVES_COUNT_GEN6 - 1))
        return TRUE;
    else
        return FALSE;
}

bool8 mplay_80342A4(u8 battlerId)
{
    u8 zero = 0;

    if (IsSEPlaying())
    {
        gBattleSpritesDataPtr->healthBoxesData[battlerId].field_8++;
        if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].field_8 < 30)
            return TRUE;

        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
    }
    if (zero == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[battlerId].field_8 = 0;
        return FALSE;
    }

    return TRUE;
}

void BattleLoadOpponentMonSpriteGfx(struct Pokemon *mon, u8 battlerId)
{
    u32 monsPersonality, currentPersonality, otId;
    u16 species;
    u8 position;
    u16 paletteOffset;
    const void *lzPaletteData;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies == SPECIES_NONE)
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        currentPersonality = monsPersonality;
    }
    else
    {
        species = gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies;
        currentPersonality = gTransformedPersonalities[battlerId];
    }

    otId = GetMonData(mon, MON_DATA_OT_ID);
    position = GetBattlerPosition(battlerId);
    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species],
                                              gMonSpritesGfxPtr->sprites[position],
                                              species, currentPersonality);

    paletteOffset = 0x100 + battlerId * 16;

    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(species, otId, monsPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, 0x20);
    LoadPalette(gDecompressionBuffer, 0x80 + battlerId * 16, 0x20);

    if (species == SPECIES_CASTFORM)
    {
        paletteOffset = 0x100 + battlerId * 16;
        LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
        LoadPalette(gBattleStruct->castformPalette[gBattleMonForms[battlerId]], paletteOffset, 0x20);
    }

    // transform's pink color
    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE)
    {
        BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
    }
}

void BattleLoadPlayerMonSpriteGfx(struct Pokemon *mon, u8 battlerId)
{
    u32 monsPersonality, currentPersonality, otId;
    u16 species;
    u8 position;
    u16 paletteOffset;
    const void *lzPaletteData;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies == SPECIES_NONE)
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        currentPersonality = monsPersonality;
    }
    else
    {
        species = gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies;
        currentPersonality = gTransformedPersonalities[battlerId];
    }

    otId = GetMonData(mon, MON_DATA_OT_ID);
    position = GetBattlerPosition(battlerId);

    if (sub_80688F8(1, battlerId) == 1 || gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE)
    {
        HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[species],
                                                  gMonSpritesGfxPtr->sprites[position],
                                                  species, currentPersonality);
    }
    else
    {
        HandleLoadSpecialPokePic(&gMonBackPicTable[species],
                                gMonSpritesGfxPtr->sprites[position],
                                species, currentPersonality);
    }

    paletteOffset = 0x100 + battlerId * 16;

    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(species, otId, monsPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, 0x20);
    LoadPalette(gDecompressionBuffer, 0x80 + battlerId * 16, 0x20);

    if (species == SPECIES_CASTFORM)
    {
        paletteOffset = 0x100 + battlerId * 16;
        LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
        LoadPalette(gBattleStruct->castformPalette[gBattleMonForms[battlerId]], paletteOffset, 0x20);
    }

    // transform's pink color
    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE)
    {
        BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
    }
}

void nullsub_23(void)
{
}

void nullsub_24(u16 species)
{
}

void DecompressTrainerFrontPic(u16 frontPicId, u8 battlerId)
{
    u8 position = GetBattlerPosition(battlerId);
    DecompressPicFromTable_2(&gTrainerFrontPicTable[frontPicId],
                             gMonSpritesGfxPtr->sprites[position],
                             SPECIES_NONE);
    LoadCompressedSpritePalette(&gTrainerFrontPicPaletteTable[frontPicId]);
}

void DecompressTrainerBackPic(u16 backPicId, u8 battlerId)
{
    u8 position = GetBattlerPosition(battlerId);
    DecompressPicFromTable_2(&gTrainerBackPicTable[backPicId],
                             gMonSpritesGfxPtr->sprites[position],
                             SPECIES_NONE);
    LoadCompressedPalette(gTrainerBackPicPaletteTable[backPicId].data,
                          0x100 + 16 * battlerId, 0x20);
}

void nullsub_25(u8 arg0)
{
}

void FreeTrainerFrontPicPalette(u16 frontPicId)
{
    FreeSpritePaletteByTag(gTrainerFrontPicPaletteTable[frontPicId].tag);
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
        LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[i]]);
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
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[0]]);
            else if (state == 5)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[1]]);
            else
                retVal = TRUE;
        }
        else
        {
            if (state == 2)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[0]);
            else if (state == 3)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesPlayerHealthbox[1]);
            else if (state == 4)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[0]);
            else if (state == 5)
                LoadCompressedSpriteSheet(&sSpriteSheets_DoublesOpponentHealthbox[1]);
            else if (state == 6)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[0]]);
            else if (state == 7)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[1]]);
            else if (state == 8)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[2]]);
            else if (state == 9)
                LoadCompressedSpriteSheet(&sSpriteSheets_HealthBar[gBattlerPositions[3]]);
            else
                retVal = TRUE;
        }
    }

    return retVal;
}

void LoadBattleBarGfx(u8 arg0)
{
    LZDecompressWram(gUnknown_08C093F0, gMonSpritesGfxPtr->barFontGfx);
}

bool8 BattleInitAllSprites(u8 *state1, u8 *battlerId)
{
    bool8 retVal = FALSE;

    switch (*state1)
    {
    case 0:
        ClearSpritesBattlerHealthboxAnimData();
        (*state1)++;
        break;
    case 1:
        if (!BattleLoadAllHealthBoxesGfx(*battlerId))
        {
            (*battlerId)++;
        }
        else
        {
            *battlerId = 0;
            (*state1)++;
        }
        break;
    case 2:
        (*state1)++;
        break;
    case 3:
        if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && *battlerId == 0)
            gHealthboxSpriteIds[*battlerId] = CreateSafariPlayerHealthboxSprites();
        else
            gHealthboxSpriteIds[*battlerId] = CreateBattlerHealthboxSprites(*battlerId);

        (*battlerId)++;
        if (*battlerId == gBattlersCount)
        {
            *battlerId = 0;
            (*state1)++;
        }
        break;
    case 4:
        InitBattlerHealthboxCoords(*battlerId);
        if (gBattlerPositions[*battlerId] <= 1)
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[*battlerId], FALSE);
        else
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[*battlerId], TRUE);

        (*battlerId)++;
        if (*battlerId == gBattlersCount)
        {
            *battlerId = 0;
            (*state1)++;
        }
        break;
    case 5:
        if (GetBattlerSide(*battlerId) == B_SIDE_PLAYER)
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
                UpdateHealthboxAttribute(gHealthboxSpriteIds[*battlerId], &gPlayerParty[gBattlerPartyIndexes[*battlerId]], HEALTHBOX_ALL);
        }
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[*battlerId], &gEnemyParty[gBattlerPartyIndexes[*battlerId]], HEALTHBOX_ALL);
        }
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[*battlerId]);
        (*battlerId)++;
        if (*battlerId == gBattlersCount)
        {
            *battlerId = 0;
            (*state1)++;
        }
        break;
    case 6:
        LoadAndCreateEnemyShadowSprites();
        sub_81B8C68();
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

void CopyBattleSpriteInvisibility(u8 battlerId)
{
    gBattleSpritesDataPtr->battlerData[battlerId].invisible = gSprites[gBattlerSpriteIds[battlerId]].invisible;
}

void HandleSpeciesGfxDataChange(u8 battlerAtk, u8 battlerDef, bool8 notTransform, bool32 megaEvo)
{
    u16 paletteOffset;
    u32 personalityValue;
    u32 otId;
    u8 position;
    const u32 *lzPaletteData;

    if (notTransform)
    {
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerAtk]], gBattleSpritesDataPtr->animationData->animArg);
        paletteOffset = 0x100 + battlerAtk * 16;
        LoadPalette(gBattleStruct->castformPalette[gBattleSpritesDataPtr->animationData->animArg], paletteOffset, 32);
        gBattleMonForms[battlerAtk] = gBattleSpritesDataPtr->animationData->animArg;
        if (gBattleSpritesDataPtr->battlerData[battlerAtk].transformSpecies != SPECIES_NONE)
        {
            BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
            CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
        }
        gSprites[gBattlerSpriteIds[battlerAtk]].pos1.y = GetBattlerSpriteDefault_Y(battlerAtk);
    }
    else
    {
        const void *src;
        void *dst;
        u16 targetSpecies;

        if (IsContest())
        {
            position = 0;
            targetSpecies = gContestResources->field_18->unk2;
            personalityValue = gContestResources->field_18->unk8;
            otId = gContestResources->field_18->unkC;

            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[targetSpecies],
                                                      gMonSpritesGfxPtr->sprites[0],
                                                      targetSpecies,
                                                      gContestResources->field_18->unk10);
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
                personalityValue = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_PERSONALITY);
                otId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_OT_ID);

                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[targetSpecies],
                                                          gMonSpritesGfxPtr->sprites[position],
                                                          targetSpecies,
                                                          gTransformedPersonalities[battlerAtk]);
            }
            else
            {
                personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_PERSONALITY);
                otId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerAtk]], MON_DATA_OT_ID);

                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[targetSpecies],
                                                          gMonSpritesGfxPtr->sprites[position],
                                                          targetSpecies,
                                                          gTransformedPersonalities[battlerAtk]);
            }
        }

        src = gMonSpritesGfxPtr->sprites[position];
        dst = (void *)(VRAM + 0x10000 + gSprites[gBattlerSpriteIds[battlerAtk]].oam.tileNum * 32);
        DmaCopy32(3, src, dst, 0x800);
        paletteOffset = 0x100 + battlerAtk * 16;
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(targetSpecies, otId, personalityValue);
        LZDecompressWram(lzPaletteData, gDecompressionBuffer);
        LoadPalette(gDecompressionBuffer, paletteOffset, 32);

        if (targetSpecies == SPECIES_CASTFORM)
        {
            gSprites[gBattlerSpriteIds[battlerAtk]].anims = gMonFrontAnimsPtrTable[targetSpecies];
            LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
            LoadPalette(gBattleStruct->castformPalette[0] + gBattleMonForms[battlerDef] * 16, paletteOffset, 32);
        }

        if (!megaEvo)
        {
            BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
            CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
        }

        if (!IsContest() && !megaEvo)
        {
            gBattleSpritesDataPtr->battlerData[battlerAtk].transformSpecies = targetSpecies;
            gBattleMonForms[battlerAtk] = gBattleMonForms[battlerDef];
        }

        gSprites[gBattlerSpriteIds[battlerAtk]].pos1.y = GetBattlerSpriteDefault_Y(battlerAtk);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerAtk]], gBattleMonForms[battlerAtk]);
    }
}

void BattleLoadSubstituteOrMonSpriteGfx(u8 battlerId, bool8 loadMonSprite)
{
    u8 position;
    s32 i;
    u32 var;
    const void *substitutePal;

    if (!loadMonSprite)
    {
        if (IsContest())
            position = 0;
        else
            position = GetBattlerPosition(battlerId);

        if (IsContest())
            LZDecompressVram(gSubstituteDollTilemap, gMonSpritesGfxPtr->sprites[position]);
        else if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
            LZDecompressVram(gSubstituteDollGfx, gMonSpritesGfxPtr->sprites[position]);
        else
            LZDecompressVram(gSubstituteDollTilemap, gMonSpritesGfxPtr->sprites[position]);

        i = 1;
        var = battlerId * 16;
        substitutePal = gSubstituteDollPal;
        for (; i < 4; i++)
        {
            register void *dmaSrc asm("r0") = gMonSpritesGfxPtr->sprites[position];
            void *dmaDst = (i * 0x800) + dmaSrc;
            u32 dmaSize = 0x800;
            DmaCopy32(3, dmaSrc, dmaDst, dmaSize);
            i++;i--;
        }

        LoadCompressedPalette(substitutePal, 0x100 + var, 32);
    }
    else
    {
        if (!IsContest())
        {
            if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[battlerId]], battlerId);
            else
                BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battlerId]], battlerId);
        }
    }
}

void LoadBattleMonGfxAndAnimate(u8 battlerId, bool8 loadMonSprite, u8 spriteId)
{
    BattleLoadSubstituteOrMonSpriteGfx(battlerId, loadMonSprite);
    StartSpriteAnim(&gSprites[spriteId], gBattleMonForms[battlerId]);

    if (!loadMonSprite)
        gSprites[spriteId].pos1.y = GetSubstituteSpriteDefault_Y(battlerId);
    else
        gSprites[spriteId].pos1.y = GetBattlerSpriteDefault_Y(battlerId);
}

void TrySetBehindSubstituteSpriteBit(u8 battlerId, u16 move)
{
    if (move == MOVE_SUBSTITUTE)
        gBattleSpritesDataPtr->battlerData[battlerId].behindSubstitute = 1;
}

void ClearBehindSubstituteBit(u8 battlerId)
{
    gBattleSpritesDataPtr->battlerData[battlerId].behindSubstitute = 0;
}

void HandleLowHpMusicChange(struct Pokemon *mon, u8 battlerId)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    if (GetHPBarLevel(hp, maxHP) == HP_BAR_RED)
    {
        if (!gBattleSpritesDataPtr->battlerData[battlerId].lowHpSong)
        {
            if (!gBattleSpritesDataPtr->battlerData[battlerId ^ BIT_FLANK].lowHpSong)
                PlaySE(SE_HINSI);
            gBattleSpritesDataPtr->battlerData[battlerId].lowHpSong = 1;
        }
    }
    else
    {
        gBattleSpritesDataPtr->battlerData[battlerId].lowHpSong = 0;
        if (!IsDoubleBattle())
        {
            m4aSongNumStop(SE_HINSI);
            return;
        }
        if (IsDoubleBattle() && !gBattleSpritesDataPtr->battlerData[battlerId ^ BIT_FLANK].lowHpSong)
        {
            m4aSongNumStop(SE_HINSI);
            return;
        }
    }
}

void BattleStopLowHpSound(void)
{
    u8 playerBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

    gBattleSpritesDataPtr->battlerData[playerBattler].lowHpSong = 0;
    if (IsDoubleBattle())
        gBattleSpritesDataPtr->battlerData[playerBattler ^ BIT_FLANK].lowHpSong = 0;

    m4aSongNumStop(SE_HINSI);
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
        u8 battler1PartyId = pokemon_order_func(gBattlerPartyIndexes[playerBattler1]);
        u8 battler2PartyId = pokemon_order_func(gBattlerPartyIndexes[playerBattler2]);

        if (GetMonData(&gPlayerParty[battler1PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[battler1PartyId], playerBattler1);
        if (IsDoubleBattle() && GetMonData(&gPlayerParty[battler2PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[battler2PartyId], playerBattler2);
    }
}

void sub_805EB9C(u8 affineMode)
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

void LoadAndCreateEnemyShadowSprites(void)
{
    u8 battlerId;

    LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadow);

    battlerId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId = CreateSprite(&gSpriteTemplate_EnemyShadow, GetBattlerSpriteCoord(battlerId, 0), GetBattlerSpriteCoord(battlerId, 1) + 29, 0xC8);
    gSprites[gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId].data[0] = battlerId;

    if (IsDoubleBattle())
    {
        battlerId = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId = CreateSprite(&gSpriteTemplate_EnemyShadow, GetBattlerSpriteCoord(battlerId, 0), GetBattlerSpriteCoord(battlerId, 1) + 29, 0xC8);
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId].data[0] = battlerId;
    }
}

void SpriteCB_EnemyShadow(struct Sprite *shadowSprite)
{
    bool8 invisible = FALSE;
    u8 battlerId = shadowSprite->tBattlerId;
    struct Sprite *battlerSprite = &gSprites[gBattlerSpriteIds[battlerId]];

    if (!battlerSprite->inUse || !IsBattlerSpritePresent(battlerId))
    {
        shadowSprite->callback = SpriteCB_SetInvisible;
        return;
    }
    if (gAnimScriptActive || battlerSprite->invisible)
        invisible = TRUE;
    else if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE
             && gEnemyMonElevation[gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies] == 0)
        invisible = TRUE;

    if (gBattleSpritesDataPtr->battlerData[battlerId].behindSubstitute)
        invisible = TRUE;

    shadowSprite->pos1.x = battlerSprite->pos1.x;
    shadowSprite->pos2.x = battlerSprite->pos2.x;
    shadowSprite->invisible = invisible;
}

#undef tBattlerId

void SpriteCB_SetInvisible(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
}

void SetBattlerShadowSpriteCallback(u8 battlerId, u16 species)
{
    // The player's shadow is never seen.
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return;

    if (gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies != SPECIES_NONE)
        species = gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies;

    if (gEnemyMonElevation[species] != 0)
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId].callback = SpriteCB_EnemyShadow;
    else
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId].callback = SpriteCB_SetInvisible;
}

void HideBattlerShadowSprite(u8 battlerId)
{
    gSprites[gBattleSpritesDataPtr->healthBoxesData[battlerId].shadowSpriteId].callback = SpriteCB_SetInvisible;
}

void sub_805EF14(void)
{
    u16 *vramPtr = (u16*)(VRAM + 0x240);
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

void ClearTemporarySpeciesSpriteData(u8 battlerId, bool8 dontClearSubstitute)
{
    gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies = SPECIES_NONE;
    gBattleMonForms[battlerId] = 0;
    if (!dontClearSubstitute)
        ClearBehindSubstituteBit(battlerId);
}

void AllocateMonSpritesGfx(void)
{
    u8 i = 0, j;

    gMonSpritesGfxPtr = NULL;
    gMonSpritesGfxPtr = AllocZeroed(sizeof(*gMonSpritesGfxPtr));
    gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(0x8000);

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gMonSpritesGfxPtr->sprites[i] = gMonSpritesGfxPtr->firstDecompressed + (i * 0x2000);
        *(gMonSpritesGfxPtr->templates + i) = gUnknown_08329D98[i];

        for (j = 0; j < 4; j++)
        {
            gMonSpritesGfxPtr->field_74[i][j].data = gMonSpritesGfxPtr->sprites[i] + (j * 0x800);
            gMonSpritesGfxPtr->field_74[i][j].size = 0x800;
        }

        gMonSpritesGfxPtr->templates[i].images = gMonSpritesGfxPtr->field_74[i];
    }

    gMonSpritesGfxPtr->barFontGfx = AllocZeroed(0x1000);
}

void FreeMonSpritesGfx(void)
{
    if (gMonSpritesGfxPtr == NULL)
        return;

    if (gMonSpritesGfxPtr->field_17C != NULL)
        FREE_AND_SET_NULL(gMonSpritesGfxPtr->field_17C);
    if (gMonSpritesGfxPtr->field_178 != NULL)
        FREE_AND_SET_NULL(gMonSpritesGfxPtr->field_178);

    FREE_AND_SET_NULL(gMonSpritesGfxPtr->barFontGfx);
    FREE_AND_SET_NULL(gMonSpritesGfxPtr->firstDecompressed);
    gMonSpritesGfxPtr->sprites[0] = NULL;
    gMonSpritesGfxPtr->sprites[1] = NULL;
    gMonSpritesGfxPtr->sprites[2] = NULL;
    gMonSpritesGfxPtr->sprites[3] = NULL;
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
