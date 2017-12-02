#include "global.h"
#include "sprite.h"
#include "pokeball.h"
#include "battle.h"
#include "battle_anim.h"
#include "task.h"
#include "sound.h"
#include "songs.h"
#include "trig.h"
#include "main.h"
#include "m4a.h"

extern bool8 gDoingBattleAnim;
extern u8 gActiveBank;
extern u8 gBankTarget;
extern u16 gBattlePartyID[];
extern u8 gBankSpriteIds[];
extern struct MusicPlayerInfo gMPlay_BGM;

// this file's functions
void Task_DoPokeballSendOutAnim(u8 taskId);
void SpriteCB_PlayerMonSendOut_1(struct Sprite *sprite);
void SpriteCB_PlayerMonSendOut_2(struct Sprite *sprite);
void SpriteCB_OpponentMonSendOut(struct Sprite *sprite);
void sub_80756D4(struct Sprite *sprite);
void sub_80756E0(struct Sprite *sprite);
void sub_807574C(struct Sprite *sprite);
void sub_80757E4(struct Sprite *sprite);
void sub_8075838(struct Sprite *sprite);
void sub_8075930(struct Sprite *sprite);
void SpriteCB_ReleaseMonFromBall(struct Sprite *sprite);
void sub_8075970(struct Sprite *sprite);
void HandleBallAnimEnd(struct Sprite *sprite);
void sub_8075FB4(struct Sprite *sprite);
void sub_80760F8(struct Sprite *sprite);
u16 GetBankPokeballItemId(u8 bank);

extern const struct SpriteTemplate gBallSpriteTemplates[];

#define tFrames         data[0]
#define tPan            data[1]
#define tThrowId        data[2]
#define tBank           data[3]
#define tOpponentBank   data[4]

u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow)
{
    u8 taskId;

    gDoingBattleAnim = TRUE;
    gBattleSpritesDataPtr->healthBoxesData[gActiveBank].ballAnimActive = 1;

    taskId = CreateTask(Task_DoPokeballSendOutAnim, 5);
    gTasks[taskId].tPan = pan;
    gTasks[taskId].tThrowId = kindOfThrow;
    gTasks[taskId].tBank = gActiveBank;

    return 0;
}

#define sData0          data[0]
#define sData1          data[1]
#define sData2          data[2]
#define sData3          data[3]
#define sData4          data[4]
#define sData5          data[5]
#define sBank           data[6]

void Task_DoPokeballSendOutAnim(u8 taskId)
{
    u16 throwCaseId;
    u8 bank;
    u16 itemId, ballId;
    u8 ballSpriteId;
    bool8 notSendOut = FALSE;

    if (gTasks[taskId].tFrames == 0)
    {
        gTasks[taskId].tFrames++;
        return;
    }

    throwCaseId = gTasks[taskId].tThrowId;
    bank = gTasks[taskId].tBank;

    if (GetBankSide(bank) != SIDE_PLAYER)
        itemId = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_POKEBALL);
    else
        itemId = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_POKEBALL);

    ballId = ItemIdToBallId(itemId);
    LoadBallGfx(ballId);
    ballSpriteId = CreateSprite(&gBallSpriteTemplates[ballId], 32, 80, 29);
    gSprites[ballSpriteId].data[0] = 0x80;
    gSprites[ballSpriteId].data[1] = 0;
    gSprites[ballSpriteId].data[7] = throwCaseId;

    switch (throwCaseId)
    {
    case POKEBALL_PLAYER_SENDOUT:
        gBankTarget = bank;
        gSprites[ballSpriteId].pos1.x = 24;
        gSprites[ballSpriteId].pos1.y = 68;
        gSprites[ballSpriteId].callback = SpriteCB_PlayerMonSendOut_1;
        break;
    case POKEBALL_OPPONENT_SENDOUT:
        gSprites[ballSpriteId].pos1.x = GetBankPosition(bank, BANK_X_POS);
        gSprites[ballSpriteId].pos1.y = GetBankPosition(bank, BANK_Y_POS) + 24;
        gBankTarget = bank;
        gSprites[ballSpriteId].sData0 = 0;
        gSprites[ballSpriteId].callback = SpriteCB_OpponentMonSendOut;
        break;
    default:
        gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
        notSendOut = TRUE;
        break;
    }

    gSprites[ballSpriteId].sBank = gBankTarget;
    if (!notSendOut)
    {
        DestroyTask(taskId);
        return;
    }

    // this will perform an unused ball throw animation
    gSprites[ballSpriteId].sData0 = 0x22;
    gSprites[ballSpriteId].sData2 = GetBankPosition(gBankTarget, BANK_X_POS);
    gSprites[ballSpriteId].sData4 = GetBankPosition(gBankTarget, BANK_Y_POS) - 16;
    gSprites[ballSpriteId].sData5 = -40;
    sub_80A68D4(&gSprites[ballSpriteId]);
    gSprites[ballSpriteId].oam.affineParam = taskId;
    gTasks[taskId].tOpponentBank = gBankTarget;
    gTasks[taskId].func = TaskDummy;
    PlaySE(SE_NAGERU);
}

void SpriteCB_TestBallThrow(struct Sprite *sprite)
{
    if (AnimateBallThrow(sprite))
    {
        u16 ballId;
        u8 taskId = sprite->oam.affineParam;
        u8 opponentBank = gTasks[taskId].tOpponentBank;
        u8 noOfShakes = gTasks[taskId].tThrowId;

        StartSpriteAnim(sprite, 1);
        sprite->affineAnimPaused = 1;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->sData5 = 0;
        ballId = ItemIdToBallId(GetBankPokeballItemId(opponentBank));
        LaunchBallStarsTask(sprite->pos1.x, sprite->pos1.y - 5, 1, 0x1C, ballId);
        sprite->sData0 = LaunchBallFadeMonTask(FALSE, opponentBank, 14, ballId);
        sprite->sBank = opponentBank;
        sprite->data[7] = noOfShakes;
        DestroyTask(taskId);
        sprite->callback = sub_80756D4;
    }
}

#undef tFrames
#undef tPan
#undef tThrowId
#undef tBank
#undef tOpponentBank

void sub_80756D4(struct Sprite *sprite)
{
    sprite->callback = sub_80756E0;
}

void sub_80756E0(struct Sprite *sprite)
{
    if (++sprite->sData5 == 10)
    {
        sprite->sData5 = 0;
        sprite->callback = sub_807574C;
        StartSpriteAffineAnim(&gSprites[gBankSpriteIds[sprite->sBank]], 2);
        AnimateSprite(&gSprites[gBankSpriteIds[sprite->sBank]]);
        gSprites[gBankSpriteIds[sprite->sBank]].data[1] = 0;
    }
}

void sub_807574C(struct Sprite *sprite)
{
    sprite->data[5]++;
    if (sprite->data[5] == 11)
        PlaySE(SE_SUIKOMU);
    if (gSprites[gBankSpriteIds[sprite->data[6]]].affineAnimEnded)
    {
        StartSpriteAnim(sprite, 2);
        gSprites[gBankSpriteIds[sprite->data[6]]].invisible = TRUE;
        sprite->data[5] = 0;
        sprite->callback = sub_80757E4;
    }
    else
    {
        gSprites[gBankSpriteIds[sprite->data[6]]].data[1] += 0x60;
        gSprites[gBankSpriteIds[sprite->data[6]]].pos2.y = -gSprites[gBankSpriteIds[sprite->data[6]]].data[1] >> 8;
    }
}

void sub_80757E4(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->data[5]++;
        if (sprite->data[5] == 1)
        {
            sprite->data[3] = 0;
            sprite->data[4] = 32;
            sprite->data[5] = 0;
            sprite->pos1.y += Cos(0, 32);
            sprite->pos2.y = -Cos(0, sprite->data[4]);
            sprite->callback = sub_8075838;
        }
    }
}

void sub_8075838(struct Sprite *sprite)
{
    bool8 r5 = FALSE;

    switch (sprite->data[3] & 0xFF)
    {
    case 0:
        sprite->pos2.y = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] += 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] >= 64)
        {
            sprite->data[4] -= 10;
            sprite->data[3] += 0x101;
            if (sprite->data[3] >> 8 == 4)
                r5 = TRUE;
            switch (sprite->data[3] >> 8)
            {
            case 1:
                PlaySE(SE_KON);
                break;
            case 2:
                PlaySE(SE_KON2);
                break;
            case 3:
                PlaySE(SE_KON3);
                break;
            default:
                PlaySE(SE_KON4);
                break;
            }
        }
        break;
    case 1:
        sprite->pos2.y = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] -= 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] <= 0)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
        }
        break;
    }
    if (r5)
    {
        sprite->data[3] = 0;
        sprite->pos1.y += Cos(64, 32);
        sprite->pos2.y = 0;
        if (sprite->data[7] == 0)
        {
            sprite->callback = SpriteCB_ReleaseMonFromBall;
        }
        else
        {
            sprite->callback = sub_8075930;
            sprite->data[4] = 1;
            sprite->data[5] = 0;
        }
    }
}

void sub_8075930(struct Sprite *sprite)
{
    sprite->data[3]++;
    if (sprite->data[3] == 31)
    {
        sprite->data[3] = 0;
        sprite->affineAnimPaused = TRUE;
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = sub_8075970;
        PlaySE(SE_BOWA);
    }
}

void sub_8075970(struct Sprite *sprite)
{
    switch (sprite->data[3] & 0xFF)
    {
    case 0:
    case 2:
        sprite->pos2.x += sprite->data[4];
        sprite->data[5] += sprite->data[4];
        sprite->affineAnimPaused = FALSE;
        if (sprite->data[5] > 3 || sprite->data[5] < -3)
        {
            sprite->data[3]++;
            sprite->data[5] = 0;
        }
        break;
    case 1:
        sprite->data[5]++;
        if (sprite->data[5] == 1)
        {
            sprite->data[5] = 0;
            sprite->data[4] = -sprite->data[4];
            sprite->data[3]++;
            sprite->affineAnimPaused = FALSE;
            if (sprite->data[4] < 0)
                ChangeSpriteAffineAnim(sprite, 2);
            else
                ChangeSpriteAffineAnim(sprite, 1);
        }
        else
        {
            sprite->affineAnimPaused = TRUE;
        }
        break;
    case 3:
        sprite->data[3] += 0x100;
        if (sprite->data[3] >> 8 == sprite->data[7])
        {
            sprite->callback = SpriteCB_ReleaseMonFromBall;
        }
        else
        {
            if (sprite->data[7] == 4 && sprite->data[3] >> 8 == 3)
            {
                sprite->callback = sub_8075FB4;
                sprite->affineAnimPaused = TRUE;
            }
            else
            {
                sprite->data[3]++;
                sprite->affineAnimPaused = TRUE;
            }
        }
        break;
    case 4:
    default:
        sprite->data[5]++;
        if (sprite->data[5] == 31)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
            StartSpriteAffineAnim(sprite, 3);
            if (sprite->data[4] < 0)
                StartSpriteAffineAnim(sprite, 2);
            else
                StartSpriteAffineAnim(sprite, 1);
            PlaySE(SE_BOWA);
        }
        break;
    }
}

#define tCryTaskSpecies         data[0]
#define tCryTaskPan             data[1]
#define tCryTaskWantedCry       data[2]
#define tCryTaskBank            data[3]
#define tCryTaskMonSpriteId     data[4]
#define tCryTaskMonPtr1         data[5]
#define tCryTaskMonPtr2         data[6]
#define tCryTaskFrames          data[10]
#define tCryTaskState           data[15]

void Task_PlayCryWhenReleasedFromBall(u8 taskId)
{
    u8 wantedCry = gTasks[taskId].tCryTaskWantedCry;
    s8 pan = gTasks[taskId].tCryTaskPan;
    u16 species = gTasks[taskId].tCryTaskSpecies;
    u8 bank = gTasks[taskId].tCryTaskBank;
    u8 monSpriteId = gTasks[taskId].tCryTaskMonSpriteId;
    struct Pokemon *mon = (void*)(u32)((gTasks[taskId].tCryTaskMonPtr1 << 0x10) | (u16)(gTasks[taskId].tCryTaskMonPtr2));

    switch (gTasks[taskId].tCryTaskState)
    {
    case 0:
    default:
        if (gSprites[monSpriteId].affineAnimEnded)
            gTasks[taskId].tCryTaskState = wantedCry + 1;
        break;
    case 1:
        if (ShouldPlayNormalPokeCry(mon) == TRUE)
            PlayCry3(species, pan, 0);
        else
            PlayCry3(species, pan, 11);
        gBattleSpritesDataPtr->healthBoxesData[bank].field_1_x40 = 0;
        DestroyTask(taskId);
        break;
    case 2:
        StopCryAndClearCrySongs();
        gTasks[taskId].tCryTaskFrames = 3;
        gTasks[taskId].tCryTaskState = 20;
        break;
    case 20:
        if (gTasks[taskId].tCryTaskFrames == 0)
        {
            if (ShouldPlayNormalPokeCry(mon) == TRUE)
                PlayCry4(species, pan, 1);
            else
                PlayCry4(species, pan, 12);

            gBattleSpritesDataPtr->healthBoxesData[bank].field_1_x40 = 0;
            DestroyTask(taskId);
        }
        else
        {
            gTasks[taskId].tCryTaskFrames--;
        }
        break;
    case 3:
        gTasks[taskId].tCryTaskFrames = 6;
        gTasks[taskId].tCryTaskState = 30;
        break;
    case 30:
        if (gTasks[taskId].tCryTaskFrames != 0)
        {
            gTasks[taskId].tCryTaskFrames--;
            break;
        }
        gTasks[taskId].tCryTaskState++;
        // fall through
    case 31:
        if (!IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            gTasks[taskId].tCryTaskFrames = 3;
            gTasks[taskId].tCryTaskState++;
        }
        break;
    case 32:
        if (gTasks[taskId].tCryTaskFrames != 0)
        {
            gTasks[taskId].tCryTaskFrames--;
            break;
        }
        if (ShouldPlayNormalPokeCry(mon) == TRUE)
            PlayCry4(species, pan, 0);
        else
            PlayCry4(species, pan, 11);

        gBattleSpritesDataPtr->healthBoxesData[bank].field_1_x40 = 0;
        DestroyTask(taskId);
        break;
    }
}

void SpriteCB_ReleaseMonFromBall(struct Sprite *sprite)
{
    u8 bank = sprite->sBank;
    u32 ballId;

    StartSpriteAnim(sprite, 1);
    ballId = ItemIdToBallId(GetBankPokeballItemId(bank));
    LaunchBallStarsTask(sprite->pos1.x, sprite->pos1.y - 5, 1, 0x1C, ballId);
    sprite->sData0 = LaunchBallFadeMonTask(1, sprite->sBank, 14, ballId);
    sprite->callback = HandleBallAnimEnd;

    if (gMain.inBattle)
    {
        struct Pokemon *mon;
        u16 species;
        s8 pan;
        u16 wantedCryCase;
        u8 taskId;

        if (GetBankSide(bank) != SIDE_PLAYER)
        {
            mon = &gEnemyParty[gBattlePartyID[bank]];
            pan = 25;
        }
        else
        {
            mon = &gPlayerParty[gBattlePartyID[bank]];
            pan = -25;
        }

        species = GetMonData(mon, MON_DATA_SPECIES);
        if ((bank == GetBankByIdentity(IDENTITY_PLAYER_MON1) || bank == GetBankByIdentity(IDENTITY_OPPONENT_MON1))
         && IsDoubleBattle() && gBattleSpritesDataPtr->animationData->field_9_x1)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (IsBGMPlaying())
                    m4aMPlayStop(&gMPlay_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 128);
            }
        }

        if (!IsDoubleBattle() || !gBattleSpritesDataPtr->animationData->field_9_x1)
            wantedCryCase = 0;
        else if (bank == GetBankByIdentity(IDENTITY_PLAYER_MON1) || bank == GetBankByIdentity(IDENTITY_OPPONENT_MON1))
            wantedCryCase = 1;
        else
            wantedCryCase = 2;

        gBattleSpritesDataPtr->healthBoxesData[bank].field_1_x40 = 1;

        taskId = CreateTask(Task_PlayCryWhenReleasedFromBall, 3);
        gTasks[taskId].tCryTaskSpecies = species;
        gTasks[taskId].tCryTaskPan = pan;
        gTasks[taskId].tCryTaskWantedCry = wantedCryCase;
        gTasks[taskId].tCryTaskBank = bank;
        gTasks[taskId].tCryTaskMonSpriteId = gBankSpriteIds[sprite->sBank];
        gTasks[taskId].tCryTaskMonPtr1 = (u32)(mon) >> 0x10;
        gTasks[taskId].tCryTaskMonPtr2 = (u32)(mon);
        gTasks[taskId].tCryTaskState = 0;
    }

    StartSpriteAffineAnim(&gSprites[gBankSpriteIds[sprite->sBank]], 1);

    if (GetBankSide(sprite->sBank) == SIDE_OPPONENT)
        gSprites[gBankSpriteIds[sprite->sBank]].callback = sub_8039B58;
    else
        gSprites[gBankSpriteIds[sprite->sBank]].callback = sub_8039E44;

    AnimateSprite(&gSprites[gBankSpriteIds[sprite->sBank]]);
    gSprites[gBankSpriteIds[sprite->sBank]].data[1] = 0x1000;
}

#undef tCryTaskSpecies
#undef tCryTaskPan
#undef tCryTaskWantedCry
#undef tCryTaskBank
#undef tCryTaskMonSpriteId
#undef tCryTaskMonPtr1
#undef tCryTaskMonPtr2
#undef tCryTaskFrames
#undef tCryTaskState

void sub_8075FB4(struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    sprite->callback = sub_80760F8;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

void HandleBallAnimEnd(struct Sprite *sprite)
{
    bool8 affineAnimEnded = FALSE;
    u8 bank = sprite->sBank;

    gSprites[gBankSpriteIds[bank]].invisible = FALSE;
    if (sprite->animEnded)
        sprite->invisible = TRUE;
    if (gSprites[gBankSpriteIds[bank]].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[gBankSpriteIds[bank]], 0);
        affineAnimEnded = TRUE;
    }
    else
    {
        gSprites[gBankSpriteIds[bank]].data[1] -= 288;
        gSprites[gBankSpriteIds[bank]].pos2.y = gSprites[gBankSpriteIds[bank]].data[1] >> 8;
    }
    if (sprite->animEnded && affineAnimEnded)
    {
        s32 i, doneBanks;

        gSprites[gBankSpriteIds[bank]].pos2.y = 0;
        gDoingBattleAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[bank].ballAnimActive = 0;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);

        for (doneBanks = 0, i = 0; i < BATTLE_BANKS_COUNT; i++)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[i].ballAnimActive == 0)
                doneBanks++;
        }
        if (doneBanks == BATTLE_BANKS_COUNT)
        {
            for (i = 0; i < POKEBALL_COUNT; i++)
                FreeBallGfx(i);
        }
    }
}

void sub_80760F8(struct Sprite *sprite)
{
    u8 bank = sprite->sBank;

    sprite->data[4]++;
    if (sprite->data[4] == 40)
    {
        return;
    }
    else if (sprite->data[4] == 95)
    {
        gDoingBattleAnim = FALSE;
        m4aMPlayAllStop();
        PlaySE(BGM_FANFA5);
    }
    else if (sprite->data[4] == 315)
    {
        FreeOamMatrix(gSprites[gBankSpriteIds[sprite->sBank]].oam.matrixNum);
        DestroySprite(&gSprites[gBankSpriteIds[sprite->sBank]]);
        DestroySpriteAndFreeResources(sprite);
        if (gMain.inBattle)
            gBattleSpritesDataPtr->healthBoxesData[bank].ballAnimActive = 0;
    }
}

void SpriteCB_PlayerMonSendOut_1(struct Sprite *sprite)
{
    sprite->data[0] = 25;
    sprite->data[2] = GetBankPosition(sprite->sBank, 2);
    sprite->data[4] = GetBankPosition(sprite->sBank, 3) + 24;
    sprite->data[5] = -30;
    sprite->oam.affineParam = sprite->sBank;
    sub_80A68D4(sprite);
    sprite->callback = SpriteCB_PlayerMonSendOut_2;
}

#undef sData0
#undef sData1
#undef sData2
#undef sData3
#undef sData4
#undef sData5
#undef sBank
