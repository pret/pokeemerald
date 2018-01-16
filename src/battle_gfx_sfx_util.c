#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_ai_script_commands.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "battle_interface.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "util.h"
#include "pokemon.h"
#include "constants/moves.h"
#include "task.h"
#include "sprite.h"
#include "sound.h"
#include "m4a.h"
#include "constants/species.h"
#include "decompress.h"
#include "data2.h"
#include "palette.h"
#include "blend_palette.h"
#include "contest.h"
#include "constants/songs.h"

extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gActiveBank;
extern u8 gBattleBanksCount;
extern u16 gUnknown_020243FC;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u8 gBankPositions[BATTLE_BANKS_COUNT];
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u32 gTransformedPersonalities[BATTLE_BANKS_COUNT];
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MusicPlayerInfo gMPlayInfo_BGM;

extern const struct BattleMove gBattleMoves[];
extern const u8 gUnknown_0831C604[];
extern const u8 * const gBattleAnims_VariousTable[];
extern const u8 * const gBattleAnims_Special[];
extern const struct CompressedSpriteSheet gMonFrontPicTable[];
extern const struct CompressedSpriteSheet gMonBackPicTable[];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const union AnimCmd* const * const gMonAnimationsSpriteAnimsPtrTable[];
extern const struct SpriteTemplate gUnknown_08329D98[4];
extern const struct CompressedSpriteSheet gSpriteSheet_EnemyShadow;
extern const struct SpriteTemplate gSpriteTemplate_EnemyShadow;
extern const u8 gEnemyMonElevation[];

// graphics
extern const u32 gUnknown_08C093F0[];
extern const u32 gSubstituteDollTilemap[];
extern const u32 gSubstituteDollGfx[];
extern const u16 gSubstituteDollPal[];
extern const u8 gUnknown_08C1F1C8[];
extern const u8 gUnknown_08C1F46C[];
extern const u8 gUnknown_08C1F5E8[];
extern const u8 gUnknown_08C1F76C[];
extern const u8 gUnknown_08C1F8E8[];
extern const u8 gBlankGfxCompressed[];
extern const u16 gBattleInterface_BallStatusBarPal[];
extern const u16 gBattleInterface_BallDisplayPal[];

extern u8 sub_80688F8(u8, u8 bank);
extern u8 pokemon_order_func(u8); // party menu
extern void sub_81B8C68(void);

// this file's functions
static u8 sub_805D4A8(u16 move);
static u16 BattlePalaceGetTargetRetValue(void);
static void sub_805D7EC(struct Sprite *sprite);
static bool8 ShouldAnimBeDoneRegardlessOfSubsitute(u8 animId);
static void Task_ClearBitWhenBattleTableAnimDone(u8 taskId);
static void Task_ClearBitWhenSpecialAnimDone(u8 taskId);
static void ClearSpritesBankHealthboxAnimData(void);

// const rom data
static const struct CompressedSpriteSheet gUnknown_0832C0D0 =
{
    gUnknown_08C1F1C8, 0x1000, TAG_HEALTHBOX_PLAYER1_TILE
};

static const struct CompressedSpriteSheet gUnknown_0832C0D8 =
{
    gUnknown_08C1F46C, 0x1000, TAG_HEALTHBOX_OPPONENT1_TILE
};

static const struct CompressedSpriteSheet gUnknown_0832C0E0[2] =
{
    {gUnknown_08C1F5E8, 0x800, TAG_HEALTHBOX_PLAYER1_TILE},
    {gUnknown_08C1F5E8, 0x800, TAG_HEALTHBOX_PLAYER2_TILE}
};

static const struct CompressedSpriteSheet gUnknown_0832C0F0[2] =
{
    {gUnknown_08C1F76C, 0x800, TAG_HEALTHBOX_OPPONENT1_TILE},
    {gUnknown_08C1F76C, 0x800, TAG_HEALTHBOX_OPPONENT2_TILE}
};

static const struct CompressedSpriteSheet gUnknown_0832C100 =
{
    gUnknown_08C1F8E8, 0x1000, TAG_HEALTHBOX_SAFARI_TILE
};

static const struct CompressedSpriteSheet gUnknown_0832C108[BATTLE_BANKS_COUNT] =
{
    {gBlankGfxCompressed, 0x0100, 0xd704},
    {gBlankGfxCompressed, 0x0120, 0xd705},
    {gBlankGfxCompressed, 0x0100, 0xd706},
    {gBlankGfxCompressed, 0x0120, 0xd707}
};

static const struct SpritePalette gUnknown_0832C128[2] =
{
    {gBattleInterface_BallStatusBarPal, TAG_HEALTHBOX_PAL},
    {gBattleInterface_BallDisplayPal, 0xd704}
};

// code
void AllocateBattleSpritesData(void)
{
    gBattleSpritesDataPtr = AllocZeroed(sizeof(struct BattleSpriteData));
    gBattleSpritesDataPtr->bankData = AllocZeroed(sizeof(struct BattleSpriteInfo) * BATTLE_BANKS_COUNT);
    gBattleSpritesDataPtr->healthBoxesData = AllocZeroed(sizeof(struct BattleHealthboxInfo) * BATTLE_BANKS_COUNT);
    gBattleSpritesDataPtr->animationData = AllocZeroed(sizeof(struct BattleAnimationInfo));
    gBattleSpritesDataPtr->battleBars = AllocZeroed(sizeof(struct BattleBarInfo) * BATTLE_BANKS_COUNT);
}

void FreeBattleSpritesData(void)
{
    if (gBattleSpritesDataPtr == NULL)
        return;

    FREE_AND_SET_NULL(gBattleSpritesDataPtr->battleBars);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->animationData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->healthBoxesData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->bankData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr);
}

u16 ChooseMoveAndTargetInBattlePalace(void)
{
    s32 i, var1, var2;
    s32 chosenMoveId = -1;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);
    u8 unusableMovesBits = CheckMoveLimitations(gActiveBank, 0, 0xFF);
    s32 percent = Random() % 100;

    i = (gBattleStruct->field_92 & gBitTable[gActiveBank]) ? 2 : 0;
    var2 = i;
    var1 = i + 2;

    for (; i < var1; i++)
    {
        if (gUnknown_0831C494[GetNatureFromPersonality(gBattleMons[gActiveBank].personality)][i] > percent)
            break;
    }

    percent = i - var2;
    if (i == var1)
        percent = 2;

    for (var2 = 0, i = 0; i < 4; i++)
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

            for (i = 0; i < 4; i++)
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
                    i = Random() % 4;
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
                    i = Random() % 4;
                    if (!(gBitTable[i] & unusableMovesBits) && var2 == sub_805D4A8(moveInfo->moves[i]))
                        chosenMoveId = i;
                } while (chosenMoveId == -1);
            }

            if (Random() % 100 > 49)
            {
                gProtectStructs[gActiveBank].flag_x10 = 1;
                return 0;
            }
        }
        else
        {
            gProtectStructs[gActiveBank].flag_x10 = 1;
            return 0;
        }
    }

    if (moveInfo->moves[chosenMoveId] == MOVE_CURSE)
    {
        if (moveInfo->monType1 != TYPE_GHOST && moveInfo->monType2 != TYPE_GHOST)
            var1 = MOVE_TARGET_x10;
        else
            var1 = MOVE_TARGET_SELECTED;
    }
    else
    {
        var1 = gBattleMoves[moveInfo->moves[chosenMoveId]].target;
    }

    if (var1 & MOVE_TARGET_x10)
        chosenMoveId |= (gActiveBank << 8);
    else if (var1 == MOVE_TARGET_SELECTED)
        chosenMoveId |= (BattlePalaceGetTargetRetValue());
    else
        chosenMoveId |= (GetBankByPosition((GetBankPosition(gActiveBank) & BIT_SIDE) ^ BIT_SIDE) << 8);

    return chosenMoveId;
}

static u8 sub_805D4A8(u16 move)
{
    switch (gBattleMoves[move].target)
    {
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_USER:
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
    case MOVE_TARGET_x10:
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

        if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        {
            opposing1 = GetBankByPosition(B_POSITION_OPPONENT_LEFT);
            opposing2 = GetBankByPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            opposing1 = GetBankByPosition(B_POSITION_PLAYER_LEFT);
            opposing2 = GetBankByPosition(B_POSITION_PLAYER_RIGHT);
        }

        if (gBattleMons[opposing1].hp == gBattleMons[opposing2].hp)
            return (((gActiveBank & BIT_SIDE) ^ BIT_SIDE) + (Random() & 2)) << 8;

        switch (gUnknown_0831C604[GetNatureFromPersonality(gBattleMons[gActiveBank].personality)])
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
            return (((gActiveBank & BIT_SIDE) ^ BIT_SIDE) + (Random() & 2)) << 8;
        }
    }

    return (gActiveBank ^ BIT_SIDE) << 8;
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
    if (!(gUnknown_020243FC & 1))
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
    gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive = 1;
    if (!isStatus2)
    {
        if (status == STATUS1_FREEZE)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_FRZ);
        else if (status == STATUS1_POISON || status & STATUS1_TOXIC_POISON)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_PSN);
        else if (status == STATUS1_BURN)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_BRN);
        else if (status & STATUS1_SLEEP)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_SLP);
        else if (status == STATUS1_PARALYSIS)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_PRZ);
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive = 0;
    }
    else
    {
        if (status & STATUS2_INFATUATION)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_INFATUATION);
        else if (status & STATUS2_CONFUSION)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_CONFUSION);
        else if (status & STATUS2_CURSED)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_CURSED);
        else if (status & STATUS2_NIGHTMARE)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_NIGHTMARE);
        else if (status & STATUS2_WRAPPED)
            LaunchStatusAnimation(gActiveBank, B_ANIM_STATUS_WRAPPED); // this animation doesn't actually exist
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive = 0;
    }
}

#define tBank data[0]

bool8 TryHandleLaunchBattleTableAnimation(u8 activeBank, u8 atkBank, u8 defBank, u8 tableId, u16 argument)
{
    u8 taskId;

    if (tableId == B_ANIM_CASTFORM_CHANGE && (argument & 0x80))
    {
        gBattleMonForms[activeBank] = (argument & ~(0x80));
        return TRUE;
    }
    if (gBattleSpritesDataPtr->bankData[activeBank].behindSubstitute
        && !ShouldAnimBeDoneRegardlessOfSubsitute(tableId))
    {
        return TRUE;
    }
    if (gBattleSpritesDataPtr->bankData[activeBank].behindSubstitute
        && tableId == B_ANIM_SUBSTITUTE_FADE
        && gSprites[gBankSpriteIds[activeBank]].invisible)
    {
        LoadBattleMonGfxAndAnimate(activeBank, TRUE, gBankSpriteIds[activeBank]);
        ClearBehindSubstituteBit(activeBank);
        return TRUE;
    }

    gAnimBankAttacker = atkBank;
    gAnimBankTarget = defBank;
    gBattleSpritesDataPtr->animationData->animArg = argument;
    LaunchBattleAnimation(gBattleAnims_VariousTable, tableId, FALSE);
    taskId = CreateTask(Task_ClearBitWhenBattleTableAnimDone, 10);
    gTasks[taskId].tBank = activeBank;
    gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBank].animFromTableActive = 1;

    return FALSE;
}

static void Task_ClearBitWhenBattleTableAnimDone(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBank].animFromTableActive = 0;
        DestroyTask(taskId);
    }
}

#undef tBank

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

#define tBank data[0]

void InitAndLaunchSpecialAnimation(u8 activeBank, u8 atkBank, u8 defBank, u8 tableId)
{
    u8 taskId;

    gAnimBankAttacker = atkBank;
    gAnimBankTarget = defBank;
    LaunchBattleAnimation(gBattleAnims_Special, tableId, FALSE);
    taskId = CreateTask(Task_ClearBitWhenSpecialAnimDone, 10);
    gTasks[taskId].tBank = activeBank;
    gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBank].specialAnimActive = 1;
}

static void Task_ClearBitWhenSpecialAnimDone(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBank].specialAnimActive = 0;
        DestroyTask(taskId);
    }
}

#undef tBank

// great function to include newly added moves that don't have animation yet
bool8 IsMoveWithoutAnimation(u16 moveId, u8 animationTurn)
{
    return FALSE;
}

bool8 mplay_80342A4(u8 bank)
{
    u8 zero = 0;

    if (IsSEPlaying())
    {
        gBattleSpritesDataPtr->healthBoxesData[bank].field_8++;
        if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_8 < 30)
            return TRUE;

        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
    }
    if (zero == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[bank].field_8 = 0;
        return FALSE;
    }

    return TRUE;
}

void BattleLoadOpponentMonSpriteGfx(struct Pokemon *mon, u8 bank)
{
    u32 monsPersonality, currentPersonality, otId;
    u16 species;
    u8 position;
    u16 paletteOffset;
    const void *lzPaletteData;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies == SPECIES_NONE)
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        currentPersonality = monsPersonality;
    }
    else
    {
        species = gBattleSpritesDataPtr->bankData[bank].transformSpecies;
        currentPersonality = gTransformedPersonalities[bank];
    }

    otId = GetMonData(mon, MON_DATA_OT_ID);
    position = GetBankPosition(bank);
    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species],
                                              gMonSpritesGfxPtr->sprites[position],
                                              species, currentPersonality);

    paletteOffset = 0x100 + bank * 16;

    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(species, otId, monsPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, 0x20);
    LoadPalette(gDecompressionBuffer, 0x80 + bank * 16, 0x20);

    if (species == SPECIES_CASTFORM)
    {
        paletteOffset = 0x100 + bank * 16;
        LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
        LoadPalette(gBattleStruct->castformPalette[gBattleMonForms[bank]], paletteOffset, 0x20);
    }

    // transform's pink color
    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies != SPECIES_NONE)
    {
        BlendPalette(paletteOffset, 16, 6, 0x7FFF);
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
    }
}

void BattleLoadPlayerMonSpriteGfx(struct Pokemon *mon, u8 bank)
{
    u32 monsPersonality, currentPersonality, otId;
    u16 species;
    u8 position;
    u16 paletteOffset;
    const void *lzPaletteData;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies == SPECIES_NONE)
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        currentPersonality = monsPersonality;
    }
    else
    {
        species = gBattleSpritesDataPtr->bankData[bank].transformSpecies;
        currentPersonality = gTransformedPersonalities[bank];
    }

    otId = GetMonData(mon, MON_DATA_OT_ID);
    position = GetBankPosition(bank);

    if (sub_80688F8(1, bank) == 1 || gBattleSpritesDataPtr->bankData[bank].transformSpecies != SPECIES_NONE)
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

    paletteOffset = 0x100 + bank * 16;

    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(species, otId, monsPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, 0x20);
    LoadPalette(gDecompressionBuffer, 0x80 + bank * 16, 0x20);

    if (species == SPECIES_CASTFORM)
    {
        paletteOffset = 0x100 + bank * 16;
        LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
        LoadPalette(gBattleStruct->castformPalette[gBattleMonForms[bank]], paletteOffset, 0x20);
    }

    // transform's pink color
    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies != SPECIES_NONE)
    {
        BlendPalette(paletteOffset, 16, 6, 0x7FFF);
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
    }
}

void nullsub_23(void)
{
}

void nullsub_24(u16 species)
{
}

void DecompressTrainerFrontPic(u16 frontPicId, u8 bank)
{
    u8 position = GetBankPosition(bank);
    DecompressPicFromTable_2(&gTrainerFrontPicTable[frontPicId],
                             gMonSpritesGfxPtr->sprites[position],
                             SPECIES_NONE);
    LoadCompressedObjectPalette(&gTrainerFrontPicPaletteTable[frontPicId]);
}

void DecompressTrainerBackPic(u16 backPicId, u8 bank)
{
    u8 position = GetBankPosition(bank);
    DecompressPicFromTable_2(&gTrainerBackPicTable[backPicId],
                             gMonSpritesGfxPtr->sprites[position],
                             SPECIES_NONE);
    LoadCompressedPalette(gTrainerBackPicPaletteTable[backPicId].data,
                          0x100 + 16 * bank, 0x20);
}

void nullsub_25(u8 arg0)
{
}

void FreeTrainerFrontPicPalette(u16 frontPicId)
{
    FreeSpritePaletteByTag(gTrainerFrontPicPaletteTable[frontPicId].tag);
}

void sub_805DFFC(void)
{
    u8 numberOfBanks = 0;
    u8 i;

    LoadSpritePalette(&gUnknown_0832C128[0]);
    LoadSpritePalette(&gUnknown_0832C128[1]);
    if (!IsDoubleBattle())
    {
        LoadCompressedObjectPic(&gUnknown_0832C0D0);
        LoadCompressedObjectPic(&gUnknown_0832C0D8);
        numberOfBanks = 2;
    }
    else
    {
        LoadCompressedObjectPic(&gUnknown_0832C0E0[0]);
        LoadCompressedObjectPic(&gUnknown_0832C0E0[1]);
        LoadCompressedObjectPic(&gUnknown_0832C0F0[0]);
        LoadCompressedObjectPic(&gUnknown_0832C0F0[1]);
        numberOfBanks = 4;
    }
    for (i = 0; i < numberOfBanks; i++)
        LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[i]]);
}

bool8 BattleLoadAllHealthBoxesGfx(u8 state)
{
    bool8 retVal = FALSE;

    if (state != 0)
    {
        if (state == 1)
        {
            LoadSpritePalette(&gUnknown_0832C128[0]);
            LoadSpritePalette(&gUnknown_0832C128[1]);
        }
        else if (!IsDoubleBattle())
        {
            if (state == 2)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    LoadCompressedObjectPic(&gUnknown_0832C100);
                else
                    LoadCompressedObjectPic(&gUnknown_0832C0D0);
            }
            else if (state == 3)
                LoadCompressedObjectPic(&gUnknown_0832C0D8);
            else if (state == 4)
                LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[0]]);
            else if (state == 5)
                LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[1]]);
            else
                retVal = TRUE;
        }
        else
        {
            if (state == 2)
                LoadCompressedObjectPic(&gUnknown_0832C0E0[0]);
            else if (state == 3)
                LoadCompressedObjectPic(&gUnknown_0832C0E0[1]);
            else if (state == 4)
                LoadCompressedObjectPic(&gUnknown_0832C0F0[0]);
            else if (state == 5)
                LoadCompressedObjectPic(&gUnknown_0832C0F0[1]);
            else if (state == 6)
                LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[0]]);
            else if (state == 7)
                LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[1]]);
            else if (state == 8)
                LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[2]]);
            else if (state == 9)
                LoadCompressedObjectPic(&gUnknown_0832C108[gBankPositions[3]]);
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

bool8 BattleInitAllSprites(u8 *state1, u8 *bank)
{
    bool8 retVal = FALSE;

    switch (*state1)
    {
    case 0:
        ClearSpritesBankHealthboxAnimData();
        (*state1)++;
        break;
    case 1:
        if (!BattleLoadAllHealthBoxesGfx(*bank))
        {
            (*bank)++;
        }
        else
        {
            *bank = 0;
            (*state1)++;
        }
        break;
    case 2:
        (*state1)++;
        break;
    case 3:
        if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && *bank == 0)
            gHealthBoxesIds[*bank] = CreateSafariPlayerHealthboxSprites();
        else
            gHealthBoxesIds[*bank] = CreateBankHealthboxSprites(*bank);

        (*bank)++;
        if (*bank == gBattleBanksCount)
        {
            *bank = 0;
            (*state1)++;
        }
        break;
    case 4:
        SetBankHealthboxSpritePos(*bank);
        if (gBankPositions[*bank] <= 1)
            DummyBattleInterfaceFunc(gHealthBoxesIds[*bank], FALSE);
        else
            DummyBattleInterfaceFunc(gHealthBoxesIds[*bank], TRUE);

        (*bank)++;
        if (*bank == gBattleBanksCount)
        {
            *bank = 0;
            (*state1)++;
        }
        break;
    case 5:
        if (GetBankSide(*bank) == SIDE_PLAYER)
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
                UpdateHealthboxAttribute(gHealthBoxesIds[*bank], &gPlayerParty[gBattlePartyID[*bank]], HEALTHBOX_ALL);
        }
        else
        {
            UpdateHealthboxAttribute(gHealthBoxesIds[*bank], &gEnemyParty[gBattlePartyID[*bank]], HEALTHBOX_ALL);
        }
        SetHealthboxSpriteInvisible(gHealthBoxesIds[*bank]);
        (*bank)++;
        if (*bank == gBattleBanksCount)
        {
            *bank = 0;
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
    memset(gBattleSpritesDataPtr->healthBoxesData, 0, sizeof(struct BattleHealthboxInfo) * BATTLE_BANKS_COUNT);
    memset(gBattleSpritesDataPtr->animationData, 0, sizeof(struct BattleAnimationInfo));
}

static void ClearSpritesBankHealthboxAnimData(void)
{
    ClearSpritesHealthboxAnimData();
    memset(gBattleSpritesDataPtr->bankData, 0, sizeof(struct BattleSpriteInfo) * BATTLE_BANKS_COUNT);
}

void CopyAllBattleSpritesInvisibilities(void)
{
    s32 i;

    for (i = 0; i < gBattleBanksCount; i++)
        gBattleSpritesDataPtr->bankData[i].invisible = gSprites[gBankSpriteIds[i]].invisible;
}

void CopyBattleSpriteInvisibility(u8 bank)
{
    gBattleSpritesDataPtr->bankData[bank].invisible = gSprites[gBankSpriteIds[bank]].invisible;
}

void HandleSpeciesGfxDataChange(u8 bankAtk, u8 bankDef, bool8 notTransform)
{
    u16 paletteOffset;
    u32 personalityValue;
    u32 otId;
    u8 position;
    const u8 *lzPaletteData;

    if (notTransform)
    {
        StartSpriteAnim(&gSprites[gBankSpriteIds[bankAtk]], gBattleSpritesDataPtr->animationData->animArg);
        paletteOffset = 0x100 + bankAtk * 16;
        LoadPalette(gBattleStruct->castformPalette[gBattleSpritesDataPtr->animationData->animArg], paletteOffset, 32);
        gBattleMonForms[bankAtk] = gBattleSpritesDataPtr->animationData->animArg;
        if (gBattleSpritesDataPtr->bankData[bankAtk].transformSpecies != SPECIES_NONE)
        {
            BlendPalette(paletteOffset, 16, 6, 0x7FFF);
            CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);
        }
        gSprites[gBankSpriteIds[bankAtk]].pos1.y = GetBankSpriteDefault_Y(bankAtk);
    }
    else
    {
        const void *src;
        void *dst;
        u16 targetSpecies;

        if (IsContest())
        {
            position = 0;
            targetSpecies = gContestResources->field_18->field_2;
            personalityValue = gContestResources->field_18->field_8;
            otId = gContestResources->field_18->field_C;

            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[targetSpecies],
                                                      gMonSpritesGfxPtr->sprites[0],
                                                      targetSpecies,
                                                      gContestResources->field_18->field_10);
        }
        else
        {
            position = GetBankPosition(bankAtk);

            if (GetBankSide(bankDef) == SIDE_OPPONENT)
                targetSpecies = GetMonData(&gEnemyParty[gBattlePartyID[bankDef]], MON_DATA_SPECIES);
            else
                targetSpecies = GetMonData(&gPlayerParty[gBattlePartyID[bankDef]], MON_DATA_SPECIES);

            if (GetBankSide(bankAtk) == SIDE_PLAYER)
            {
                personalityValue = GetMonData(&gPlayerParty[gBattlePartyID[bankAtk]], MON_DATA_PERSONALITY);
                otId = GetMonData(&gPlayerParty[gBattlePartyID[bankAtk]], MON_DATA_OT_ID);

                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[targetSpecies],
                                                          gMonSpritesGfxPtr->sprites[position],
                                                          targetSpecies,
                                                          gTransformedPersonalities[bankAtk]);
            }
            else
            {
                personalityValue = GetMonData(&gEnemyParty[gBattlePartyID[bankAtk]], MON_DATA_PERSONALITY);
                otId = GetMonData(&gEnemyParty[gBattlePartyID[bankAtk]], MON_DATA_OT_ID);

                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[targetSpecies],
                                                          gMonSpritesGfxPtr->sprites[position],
                                                          targetSpecies,
                                                          gTransformedPersonalities[bankAtk]);
            }
        }

        src = gMonSpritesGfxPtr->sprites[position];
        dst = (void *)(VRAM + 0x10000 + gSprites[gBankSpriteIds[bankAtk]].oam.tileNum * 32);
        DmaCopy32(3, src, dst, 0x800);
        paletteOffset = 0x100 + bankAtk * 16;
        lzPaletteData = GetFrontSpritePalFromSpeciesAndPersonality(targetSpecies, otId, personalityValue);
        LZDecompressWram(lzPaletteData, gDecompressionBuffer);
        LoadPalette(gDecompressionBuffer, paletteOffset, 32);

        if (targetSpecies == SPECIES_CASTFORM)
        {
            gSprites[gBankSpriteIds[bankAtk]].anims = gMonAnimationsSpriteAnimsPtrTable[targetSpecies];
            LZDecompressWram(lzPaletteData, gBattleStruct->castformPalette[0]);
            LoadPalette(gBattleStruct->castformPalette[0] + gBattleMonForms[bankDef] * 16, paletteOffset, 32);
        }

        BlendPalette(paletteOffset, 16, 6, 0x7FFF);
        CpuCopy32(gPlttBufferFaded + paletteOffset, gPlttBufferUnfaded + paletteOffset, 32);

        if (!IsContest())
        {
            gBattleSpritesDataPtr->bankData[bankAtk].transformSpecies = targetSpecies;
            gBattleMonForms[bankAtk] = gBattleMonForms[bankDef];
        }

        gSprites[gBankSpriteIds[bankAtk]].pos1.y = GetBankSpriteDefault_Y(bankAtk);
        StartSpriteAnim(&gSprites[gBankSpriteIds[bankAtk]], gBattleMonForms[bankAtk]);
    }
}

void BattleLoadSubstituteOrMonSpriteGfx(u8 bank, bool8 loadMonSprite)
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
            position = GetBankPosition(bank);

        if (IsContest())
            LZDecompressVram(gSubstituteDollTilemap, gMonSpritesGfxPtr->sprites[position]);
        else if (GetBankSide(bank) != SIDE_PLAYER)
            LZDecompressVram(gSubstituteDollGfx, gMonSpritesGfxPtr->sprites[position]);
        else
            LZDecompressVram(gSubstituteDollTilemap, gMonSpritesGfxPtr->sprites[position]);

        i = 1;
        var = bank * 16;
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
            if (GetBankSide(bank) != SIDE_PLAYER)
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[bank]], bank);
            else
                BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[bank]], bank);
        }
    }
}

void LoadBattleMonGfxAndAnimate(u8 bank, bool8 loadMonSprite, u8 spriteId)
{
    BattleLoadSubstituteOrMonSpriteGfx(bank, loadMonSprite);
    StartSpriteAnim(&gSprites[spriteId], gBattleMonForms[bank]);

    if (!loadMonSprite)
        gSprites[spriteId].pos1.y = GetSubstituteSpriteDefault_Y(bank);
    else
        gSprites[spriteId].pos1.y = GetBankSpriteDefault_Y(bank);
}

void TrySetBehindSubstituteSpriteBit(u8 bank, u16 move)
{
    if (move == MOVE_SUBSTITUTE)
        gBattleSpritesDataPtr->bankData[bank].behindSubstitute = 1;
}

void ClearBehindSubstituteBit(u8 bank)
{
    gBattleSpritesDataPtr->bankData[bank].behindSubstitute = 0;
}

void HandleLowHpMusicChange(struct Pokemon *mon, u8 bank)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    if (GetHPBarLevel(hp, maxHP) == HP_BAR_RED)
    {
        if (!gBattleSpritesDataPtr->bankData[bank].lowHpSong)
        {
            if (!gBattleSpritesDataPtr->bankData[bank ^ BIT_MON].lowHpSong)
                PlaySE(SE_HINSI);
            gBattleSpritesDataPtr->bankData[bank].lowHpSong = 1;
        }
    }
    else
    {
        gBattleSpritesDataPtr->bankData[bank].lowHpSong = 0;
        if (!IsDoubleBattle())
        {
            m4aSongNumStop(SE_HINSI);
            return;
        }
        if (IsDoubleBattle() && !gBattleSpritesDataPtr->bankData[bank ^ BIT_MON].lowHpSong)
        {
            m4aSongNumStop(SE_HINSI);
            return;
        }
    }
}

void BattleStopLowHpSound(void)
{
    u8 playerBank = GetBankByPosition(B_POSITION_PLAYER_LEFT);

    gBattleSpritesDataPtr->bankData[playerBank].lowHpSong = 0;
    if (IsDoubleBattle())
        gBattleSpritesDataPtr->bankData[playerBank ^ BIT_MON].lowHpSong = 0;

    m4aSongNumStop(SE_HINSI);
}

u8 GetMonHPBarLevel(struct Pokemon *mon)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    return GetHPBarLevel(hp, maxHP);
}

void sub_805EAE8(void)
{
    if (gMain.inBattle)
    {
        u8 playerBank1 = GetBankByPosition(B_POSITION_PLAYER_LEFT);
        u8 playerBank2 = GetBankByPosition(B_POSITION_PLAYER_RIGHT);
        u8 bank1PartyId = pokemon_order_func(gBattlePartyID[playerBank1]);
        u8 bank2PartyId = pokemon_order_func(gBattlePartyID[playerBank2]);

        if (GetMonData(&gPlayerParty[bank1PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[bank1PartyId], playerBank1);
        if (IsDoubleBattle() && GetMonData(&gPlayerParty[bank2PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[bank2PartyId], playerBank2);
    }
}

void sub_805EB9C(u8 affineMode)
{
    s32 i;

    for (i = 0; i < gBattleBanksCount; i++)
    {
        if (IsBankSpritePresent(i))
        {
            gSprites[gBankSpriteIds[i]].oam.affineMode = affineMode;
            if (affineMode == 0)
            {
                gBattleSpritesDataPtr->healthBoxesData[i].field_6 = gSprites[gBankSpriteIds[i]].oam.matrixNum;
                gSprites[gBankSpriteIds[i]].oam.matrixNum = 0;
            }
            else
            {
                gSprites[gBankSpriteIds[i]].oam.matrixNum = gBattleSpritesDataPtr->healthBoxesData[i].field_6;
            }
        }
    }
}

#define tBank data[0]

void LoadAndCreateEnemyShadowSprites(void)
{
    u8 bank;

    LoadCompressedObjectPic(&gSpriteSheet_EnemyShadow);

    bank = GetBankByPosition(B_POSITION_OPPONENT_LEFT);
    gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId = CreateSprite(&gSpriteTemplate_EnemyShadow, GetBankCoord(bank, 0), GetBankCoord(bank, 1) + 29, 0xC8);
    gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId].data[0] = bank;

    if (IsDoubleBattle())
    {
        bank = GetBankByPosition(B_POSITION_OPPONENT_RIGHT);
        gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId = CreateSprite(&gSpriteTemplate_EnemyShadow, GetBankCoord(bank, 0), GetBankCoord(bank, 1) + 29, 0xC8);
        gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId].data[0] = bank;
    }
}

void SpriteCB_EnemyShadow(struct Sprite *shadowSprite)
{
    bool8 invisible = FALSE;
    u8 bank = shadowSprite->tBank;
    struct Sprite *bankSprite = &gSprites[gBankSpriteIds[bank]];

    if (!bankSprite->inUse || !IsBankSpritePresent(bank))
    {
        shadowSprite->callback = SpriteCB_SetInvisible;
        return;
    }
    if (gAnimScriptActive || bankSprite->invisible)
        invisible = TRUE;
    else if (gBattleSpritesDataPtr->bankData[bank].transformSpecies != SPECIES_NONE
             && gEnemyMonElevation[gBattleSpritesDataPtr->bankData[bank].transformSpecies] == 0)
        invisible = TRUE;

    if (gBattleSpritesDataPtr->bankData[bank].behindSubstitute)
        invisible = TRUE;

    shadowSprite->pos1.x = bankSprite->pos1.x;
    shadowSprite->pos2.x = bankSprite->pos2.x;
    shadowSprite->invisible = invisible;
}

#undef tBank

void SpriteCB_SetInvisible(struct Sprite *sprite)
{
    sprite->invisible = 1;
}

void SetBankEnemyShadowSpriteCallback(u8 bank, u16 species)
{
    if (GetBankSide(bank) == SIDE_PLAYER)
        return;

    if (gBattleSpritesDataPtr->bankData[bank].transformSpecies != SPECIES_NONE)
        species = gBattleSpritesDataPtr->bankData[bank].transformSpecies;

    if (gEnemyMonElevation[species] != 0)
        gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId].callback = SpriteCB_EnemyShadow;
    else
        gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId].callback = SpriteCB_SetInvisible;
}

void EnemyShadowCallbackToSetInvisible(u8 bank)
{
    gSprites[gBattleSpritesDataPtr->healthBoxesData[bank].shadowSpriteId].callback = SpriteCB_SetInvisible;
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

void ClearTemporarySpeciesSpriteData(u8 bank, bool8 dontClearSubstitute)
{
    gBattleSpritesDataPtr->bankData[bank].transformSpecies = SPECIES_NONE;
    gBattleMonForms[bank] = 0;
    if (!dontClearSubstitute)
        ClearBehindSubstituteBit(bank);
}

void AllocateMonSpritesGfx(void)
{
    u8 i = 0, j;

    gMonSpritesGfxPtr = NULL;
    gMonSpritesGfxPtr = AllocZeroed(sizeof(*gMonSpritesGfxPtr));
    gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(0x8000);

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
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

bool32 ShouldPlayNormalPokeCry(struct Pokemon *mon)
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
