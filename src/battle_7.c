#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_ai_script_commands.h"
#include "malloc.h"
#include "rng.h"
#include "util.h"
#include "pokemon.h"
#include "moves.h"

extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gActiveBank;
extern u16 gUnknown_020243FC;
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];

extern const struct BattleMove gBattleMoves[];
extern const u8 gUnknown_0831C604[];

// this file's functions
u8 sub_805D4A8(u16 move);
u16 BattlePalaceGetTargetRetValue(void);
void sub_805D7EC(struct Sprite *sprite);

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
        chosenMoveId |= (GetBankByIdentity((GetBankIdentity(gActiveBank) & BIT_SIDE) ^ BIT_SIDE) << 8);

    return chosenMoveId;
}

u8 sub_805D4A8(u16 move)
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

u16 BattlePalaceGetTargetRetValue(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u8 opposing1, opposing2;

        if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        {
            opposing1 = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
            opposing2 = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
        }
        else
        {
            opposing1 = GetBankByIdentity(IDENTITY_PLAYER_MON1);
            opposing2 = GetBankByIdentity(IDENTITY_PLAYER_MON2);
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
    u8 spriteId = sprite->data1;

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
        sprite->pos2.x += sprite->data0;
        if (sprite->pos2.x == 0)
        {
            if (sprite->pos2.y != 0)
                sprite->callback = sub_805D7EC;
            else
                sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_805D7EC(struct Sprite *sprite)
{
    sprite->pos2.y -= 2;
    if (sprite->pos2.y == 0)
        sprite->callback = SpriteCallbackDummy;
}
