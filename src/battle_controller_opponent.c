#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "battle_link_817C95C.h"
#include "battle_ai_script_commands.h"
#include "pokemon.h"
#include "link.h"
#include "util.h"
#include "main.h"
#include "item.h"
#include "items.h"
#include "songs.h"
#include "sound.h"
#include "moves.h"
#include "window.h"
#include "m4a.h"
#include "palette.h"
#include "task.h"
#include "text.h"
#include "string_util.h"
#include "bg.h"
#include "reshow_battle_screen.h"
#include "rng.h"
#include "pokeball.h"
#include "data2.h"

extern u32 gBattleExecBuffer;
extern u8 gActiveBank;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern bool8 gDoingBattleAnim;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern struct MusicPlayerInfo gMPlay_BGM;
extern u8 gUnknown_03005D7C[BATTLE_BANKS_COUNT];
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern void *gUnknown_020244D8;
extern void *gUnknown_020244DC;
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern struct SpriteTemplate gUnknown_0202499C;
extern struct UnusedControllerStruct gUnknown_02022D0C;
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u32 gTransformedPersonalities[BATTLE_BANKS_COUNT];
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gUnknown_020243FC;
extern u8 gUnknown_020244B4[];
extern void (*gPreBattleCallback1)(void);

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct BattleMove gBattleMoves[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);
extern void sub_81A57E4(u8 bank, u16 stringId);
extern u8 sub_81A4CB0(void);
extern u8 sub_81D5588(u16 trainerId);
extern u8 GetFrontierTrainerFrontSpriteId(u16 trainerId);
extern u8 GetEreaderTrainerFrontSpriteId(void);

// this file's functions
static void OpponentHandleGetMonData(void);
static void OpponentHandleGetRawMonData(void);
static void OpponentHandleSetMonData(void);
static void OpponentHandleSetRawMonData(void);
static void OpponentHandleLoadMonSprite(void);
static void OpponentHandleSwitchInAnim(void);
static void OpponentHandleReturnMonToBall(void);
static void OpponentHandleDrawTrainerPic(void);
static void OpponentHandleTrainerSlide(void);
static void OpponentHandleTrainerSlideBack(void);
static void OpponentHandleFaintAnimation(void);
static void OpponentHandlePaletteFade(void);
static void OpponentHandleSuccessBallThrowAnim(void);
static void OpponentHandleBallThrow(void);
static void OpponentHandlePause(void);
static void OpponentHandleMoveAnimation(void);
static void OpponentHandlePrintString(void);
static void OpponentHandlePrintStringPlayerOnly(void);
static void OpponentHandleChooseAction(void);
static void OpponentHandleUnknownYesNoBox(void);
static void OpponentHandleChooseMove(void);
static void OpponentHandleChooseItem(void);
static void OpponentHandleChoosePokemon(void);
static void OpponentHandleCmd23(void);
static void OpponentHandleHealthBarUpdate(void);
static void OpponentHandleExpUpdate(void);
static void OpponentHandleStatusIconUpdate(void);
static void OpponentHandleStatusAnimation(void);
static void OpponentHandleStatusXor(void);
static void OpponentHandleDataTransfer(void);
static void OpponentHandleDMA3Transfer(void);
static void OpponentHandlePlayBGM(void);
static void OpponentHandleCmd32(void);
static void OpponentHandleTwoReturnValues(void);
static void OpponentHandleChosenMonReturnValue(void);
static void OpponentHandleOneReturnValue(void);
static void OpponentHandleOneReturnValue_Duplicate(void);
static void OpponentHandleCmd37(void);
static void OpponentHandleCmd38(void);
static void OpponentHandleCmd39(void);
static void OpponentHandleCmd40(void);
static void OpponentHandleHitAnimation(void);
static void OpponentHandleCmd42(void);
static void OpponentHandleEffectivenessSound(void);
static void OpponentHandlePlayFanfareOrBGM(void);
static void OpponentHandleFaintingCry(void);
static void OpponentHandleIntroSlide(void);
static void OpponentHandleIntroTrainerBallThrow(void);
static void OpponentHandleDrawPartyStatusSummary(void);
static void OpponentHandleCmd49(void);
static void OpponentHandleCmd50(void);
static void OpponentHandleSpriteInvisibility(void);
static void OpponentHandleBattleAnimation(void);
static void OpponentHandleLinkStandbyMsg(void);
static void OpponentHandleResetActionMoveSelection(void);
static void OpponentHandleCmd55(void);
static void nullsub_91(void);

static void OpponentBufferRunCommand(void);
static void OpponentBufferExecCompleted(void);
static void sub_805FC80(void);
static u32 GetOpponentMonData(u8 monId, u8 *dst);
static void SetOpponentMonData(u8 monId);
static void sub_80613DC(u8 bank, bool8 dontClearSubstituteBit);
static void DoSwitchOutAnimation(void);
static void OpponentDoMoveAnimation(void);
static void sub_806280C(struct Sprite *sprite);
static void sub_8062828(u8 taskId);
static void sub_8062A2C(void);

static void (*const sOpponentBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    OpponentHandleGetMonData,
    OpponentHandleGetRawMonData,
    OpponentHandleSetMonData,
    OpponentHandleSetRawMonData,
    OpponentHandleLoadMonSprite,
    OpponentHandleSwitchInAnim,
    OpponentHandleReturnMonToBall,
    OpponentHandleDrawTrainerPic,
    OpponentHandleTrainerSlide,
    OpponentHandleTrainerSlideBack,
    OpponentHandleFaintAnimation,
    OpponentHandlePaletteFade,
    OpponentHandleSuccessBallThrowAnim,
    OpponentHandleBallThrow,
    OpponentHandlePause,
    OpponentHandleMoveAnimation,
    OpponentHandlePrintString,
    OpponentHandlePrintStringPlayerOnly,
    OpponentHandleChooseAction,
    OpponentHandleUnknownYesNoBox,
    OpponentHandleChooseMove,
    OpponentHandleChooseItem,
    OpponentHandleChoosePokemon,
    OpponentHandleCmd23,
    OpponentHandleHealthBarUpdate,
    OpponentHandleExpUpdate,
    OpponentHandleStatusIconUpdate,
    OpponentHandleStatusAnimation,
    OpponentHandleStatusXor,
    OpponentHandleDataTransfer,
    OpponentHandleDMA3Transfer,
    OpponentHandlePlayBGM,
    OpponentHandleCmd32,
    OpponentHandleTwoReturnValues,
    OpponentHandleChosenMonReturnValue,
    OpponentHandleOneReturnValue,
    OpponentHandleOneReturnValue_Duplicate,
    OpponentHandleCmd37,
    OpponentHandleCmd38,
    OpponentHandleCmd39,
    OpponentHandleCmd40,
    OpponentHandleHitAnimation,
    OpponentHandleCmd42,
    OpponentHandleEffectivenessSound,
    OpponentHandlePlayFanfareOrBGM,
    OpponentHandleFaintingCry,
    OpponentHandleIntroSlide,
    OpponentHandleIntroTrainerBallThrow,
    OpponentHandleDrawPartyStatusSummary,
    OpponentHandleCmd49,
    OpponentHandleCmd50,
    OpponentHandleSpriteInvisibility,
    OpponentHandleBattleAnimation,
    OpponentHandleLinkStandbyMsg,
    OpponentHandleResetActionMoveSelection,
    OpponentHandleCmd55,
    nullsub_91
};

// unknown unused data
static const u8 sUnknown_0831C7AC[] = {0xB0, 0xB0, 0xC8, 0x98, 0x28, 0x28, 0x28, 0x20};

static void nullsub_26(void)
{
}

void SetControllerToOpponent(void)
{
    gBattleBankFunc[gActiveBank] = OpponentBufferRunCommand;
}

static void OpponentBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(sOpponentBufferCommands))
            sOpponentBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            OpponentBufferExecCompleted();
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        OpponentBufferExecCompleted();
}

static void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        OpponentBufferExecCompleted();
}

static void sub_805F240(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        FreeTrainerFrontPicPalette(gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        OpponentBufferExecCompleted();
    }
}

static void sub_805F2A8(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 0xFF)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
        OpponentBufferExecCompleted();
    }
}

static void sub_805F2F0(void)
{
    bool8 var = FALSE;
    bool8 var2;

    if (!IsDoubleBattle() || ((IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)) || (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)))
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
            var = TRUE;
        var2 = FALSE;
    }
    else
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
         && gSprites[gHealthBoxesIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
            var = TRUE;
        var2 = TRUE;
    }

    gUnknown_020244D8 = &gBattleSpritesDataPtr->healthBoxesData[gActiveBank];
    gUnknown_020244DC = &gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON];

    if (var)
    {
        if (var2 == TRUE)
        {
            if (var2 && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 && gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1)
            {
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 = 0;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1 = 0;
                FreeSpriteTilesByTag(0x27F9);
                FreeSpritePaletteByTag(0x27F9);
            }
            else
                return;
        }
        else if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
        {
            if (GetBankIdentity(gActiveBank) == 3)
            {
                if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 == 0 && gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1 == 0)
                {
                    FreeSpriteTilesByTag(0x27F9);
                    FreeSpritePaletteByTag(0x27F9);
                }
                else
                    return;
            }
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
        }
        else
            return;

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 3;
        gBattleBankFunc[gActiveBank] = sub_805F2A8;
    }
}

static void sub_805F560(void)
{
    bool32 sp = FALSE;
    bool32 r10 = FALSE;

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);
    if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI) && IsDoubleBattle() && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1)
        sub_8172EF0(gActiveBank ^ BIT_MON, &gEnemyParty[gBattlePartyID[gActiveBank ^ BIT_MON]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80)
        {
            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank ^ BIT_MON], &gEnemyParty[gBattlePartyID[gActiveBank ^ BIT_MON]], HEALTHBOX_ALL);
                sub_8076918(gActiveBank ^ BIT_MON);
                SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank ^ BIT_MON]);
            }
            UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gEnemyParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
            sub_8076918(gActiveBank);
            SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80 = 1;
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x40
        && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x40
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (GetBankIdentity(gActiveBank) == 1)
                    m4aMPlayContinue(&gMPlay_BGM);
            }
            else
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20 = 1;
        sp = TRUE;
    }

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        {
            r10 = TRUE;
        }
    }
    else
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
        {
            r10 = TRUE;
        }
    }

    if (sp && r10)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]]);
            SetBankEnemyShadowSpriteCallback(gActiveBank ^ BIT_MON, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank ^ BIT_MON]], MON_DATA_SPECIES));
        }

        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));
        gBattleSpritesDataPtr->animationData->field_9_x1 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80 = 0;

        gBattleBankFunc[gActiveBank] = sub_805F2F0;
    }
}

static void sub_805F994(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].pos2.x == 0 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);

    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);
        OpponentBufferExecCompleted();
    }
}

static void CompleteOnHealthbarDone(void)
{
    s16 hpValue = sub_8074AA0(gActiveBank, gHealthBoxesIds[gActiveBank], HEALTH_BAR, 0);
    SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);
    if (hpValue != -1)
    {
        UpdateHpTextInHealthbox(gHealthBoxesIds[gActiveBank], hpValue, HP_CURRENT);
    }
    else
        OpponentBufferExecCompleted();
}

static void sub_805FAC4(void)
{
    if (!gSprites[gBankSpriteIds[gActiveBank]].inUse)
    {
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        OpponentBufferExecCompleted();
    }
}

static void sub_805FB08(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        EnemyShadowCallbackToSetInvisible(gActiveBank);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        OpponentBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        OpponentBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBankSpriteIds[gActiveBank];

    if (gSprites[spriteId].data1 == 32)
    {
        gSprites[spriteId].data1 = 0;
        gSprites[spriteId].invisible = 0;
        gDoingBattleAnim = FALSE;
        OpponentBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data1 % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data1++;
    }
}

static void sub_805FC10(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);
        gBattleBankFunc[gActiveBank] = sub_805FC80;
    }
}

static void sub_805FC80(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy || gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy_2)
        {
            m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            OpponentBufferExecCompleted();
        }
    }
}

static void sub_805FD00(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);
        StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], 0);
        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gEnemyParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
        sub_8076918(gActiveBank);
        SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);
        CopyBattleSpriteInvisibility(gActiveBank);
        gBattleBankFunc[gActiveBank] = sub_805FC10;
    }
}

static void sub_805FDF0(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);

    if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
    {
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));
        gBattleBankFunc[gActiveBank] = sub_805FD00;
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        OpponentBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        OpponentBufferExecCompleted();
}

static void OpponentBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = OpponentBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBank][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleExecBuffer &= ~gBitTable[gActiveBank];
    }
}

static void OpponentHandleGetMonData(void)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    u32 size = 0;
    u8 monToCheck;
    s32 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        size += GetOpponentMonData(gBattlePartyID[gActiveBank], monData);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                size += GetOpponentMonData(i, monData + size);
            monToCheck >>= 1;
        }
    }
    EmitDataTransfer(1, size, monData);
    OpponentBufferExecCompleted();
}

static u32 GetOpponentMonData(u8 monId, u8 *dst)
{
    struct BattlePokemon battleMon;
    struct MovePpInfo moveData;
    u8 nickname[20];
    u8 *src;
    s16 data16;
    u32 data32;
    s32 size = 0;

    switch (gBattleBufferA[gActiveBank][1])
    {
    case REQUEST_ALL_BATTLE:
        battleMon.species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);
        battleMon.item = GetMonData(&gEnemyParty[monId], MON_DATA_HELD_ITEM);
        for (size = 0; size < 4; size++)
        {
            battleMon.moves[size] = GetMonData(&gEnemyParty[monId], MON_DATA_MOVE1 + size);
            battleMon.pp[size] = GetMonData(&gEnemyParty[monId], MON_DATA_PP1 + size);
        }
        battleMon.ppBonuses = GetMonData(&gEnemyParty[monId], MON_DATA_PP_BONUSES);
        battleMon.friendship = GetMonData(&gEnemyParty[monId], MON_DATA_FRIENDSHIP);
        battleMon.experience = GetMonData(&gEnemyParty[monId], MON_DATA_EXP);
        battleMon.hpIV = GetMonData(&gEnemyParty[monId], MON_DATA_HP_IV);
        battleMon.attackIV = GetMonData(&gEnemyParty[monId], MON_DATA_ATK_IV);
        battleMon.defenseIV = GetMonData(&gEnemyParty[monId], MON_DATA_DEF_IV);
        battleMon.speedIV = GetMonData(&gEnemyParty[monId], MON_DATA_SPEED_IV);
        battleMon.spAttackIV = GetMonData(&gEnemyParty[monId], MON_DATA_SPATK_IV);
        battleMon.spDefenseIV = GetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_IV);
        battleMon.personality = GetMonData(&gEnemyParty[monId], MON_DATA_PERSONALITY);
        battleMon.status1 = GetMonData(&gEnemyParty[monId], MON_DATA_STATUS);
        battleMon.level = GetMonData(&gEnemyParty[monId], MON_DATA_LEVEL);
        battleMon.hp = GetMonData(&gEnemyParty[monId], MON_DATA_HP);
        battleMon.maxHP = GetMonData(&gEnemyParty[monId], MON_DATA_MAX_HP);
        battleMon.attack = GetMonData(&gEnemyParty[monId], MON_DATA_ATK);
        battleMon.defense = GetMonData(&gEnemyParty[monId], MON_DATA_DEF);
        battleMon.speed = GetMonData(&gEnemyParty[monId], MON_DATA_SPEED);
        battleMon.spAttack = GetMonData(&gEnemyParty[monId], MON_DATA_SPATK);
        battleMon.spDefense = GetMonData(&gEnemyParty[monId], MON_DATA_SPDEF);
        battleMon.isEgg = GetMonData(&gEnemyParty[monId], MON_DATA_IS_EGG);
        battleMon.altAbility = GetMonData(&gEnemyParty[monId], MON_DATA_ALT_ABILITY);
        battleMon.otId = GetMonData(&gEnemyParty[monId], MON_DATA_OT_ID);
        GetMonData(&gEnemyParty[monId], MON_DATA_NICKNAME, nickname);
        StringCopy10(battleMon.nickname, nickname);
        GetMonData(&gEnemyParty[monId], MON_DATA_OT_NAME, battleMon.otName);
        src = (u8 *)&battleMon;
        for (size = 0; size < sizeof(battleMon); size++)
            dst[size] = src[size];
        break;
    case REQUEST_SPECIES_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_HELDITEM_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_HELD_ITEM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (size = 0; size < 4; size++)
        {
            moveData.moves[size] = GetMonData(&gEnemyParty[monId], MON_DATA_MOVE1 + size);
            moveData.pp[size] = GetMonData(&gEnemyParty[monId], MON_DATA_PP1 + size);
        }
        moveData.ppBonuses = GetMonData(&gEnemyParty[monId], MON_DATA_PP_BONUSES);
        src = (u8*)(&moveData);
        for (size = 0; size < sizeof(moveData); size++)
            dst[size] = src[size];
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_MOVE1 + gBattleBufferA[gActiveBank][1] - REQUEST_MOVE1_BATTLE);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_PP_DATA_BATTLE:
        for (size = 0; size < 4; size++)
            dst[size] = GetMonData(&gEnemyParty[monId], MON_DATA_PP1 + size);
        dst[size] = GetMonData(&gEnemyParty[monId], MON_DATA_PP_BONUSES);
        size++;
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_PP1 + gBattleBufferA[gActiveBank][1] - REQUEST_PPMOVE1_BATTLE);
        size = 1;
        break;
    case REQUEST_OTID_BATTLE:
        data32 = GetMonData(&gEnemyParty[monId], MON_DATA_OT_ID);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_EXP_BATTLE:
        data32 = GetMonData(&gEnemyParty[monId], MON_DATA_EXP);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_HP_EV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_HP_EV);
        size = 1;
        break;
    case REQUEST_ATK_EV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_ATK_EV);
        size = 1;
        break;
    case REQUEST_DEF_EV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_DEF_EV);
        size = 1;
        break;
    case REQUEST_SPEED_EV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SPEED_EV);
        size = 1;
        break;
    case REQUEST_SPATK_EV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SPATK_EV);
        size = 1;
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_EV);
        size = 1;
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_FRIENDSHIP);
        size = 1;
        break;
    case REQUEST_POKERUS_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_POKERUS);
        size = 1;
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_MET_LOCATION);
        size = 1;
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_MET_LEVEL);
        size = 1;
        break;
    case REQUEST_MET_GAME_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_MET_GAME);
        size = 1;
        break;
    case REQUEST_POKEBALL_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_POKEBALL);
        size = 1;
        break;
    case REQUEST_ALL_IVS_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_HP_IV);
        dst[1] = GetMonData(&gEnemyParty[monId], MON_DATA_ATK_IV);
        dst[2] = GetMonData(&gEnemyParty[monId], MON_DATA_DEF_IV);
        dst[3] = GetMonData(&gEnemyParty[monId], MON_DATA_SPEED_IV);
        dst[4] = GetMonData(&gEnemyParty[monId], MON_DATA_SPATK_IV);
        dst[5] = GetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_IV);
        size = 6;
        break;
    case REQUEST_HP_IV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_HP_IV);
        size = 1;
        break;
    case REQUEST_ATK_IV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_ATK_IV);
        size = 1;
        break;
    case REQUEST_DEF_IV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_DEF_IV);
        size = 1;
        break;
    case REQUEST_SPEED_IV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SPEED_IV);
        size = 1;
        break;
    case REQUEST_SPATK_IV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SPATK_IV);
        size = 1;
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_IV);
        size = 1;
        break;
    case REQUEST_PERSONALITY_BATTLE:
        data32 = GetMonData(&gEnemyParty[monId], MON_DATA_PERSONALITY);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_CHECKSUM_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_CHECKSUM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_STATUS_BATTLE:
        data32 = GetMonData(&gEnemyParty[monId], MON_DATA_STATUS);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_LEVEL_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_LEVEL);
        size = 1;
        break;
    case REQUEST_HP_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MAX_HP_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_MAX_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_ATK_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_ATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_DEF_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_DEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPEED_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_SPEED);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPATK_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_SPATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPDEF_BATTLE:
        data16 = GetMonData(&gEnemyParty[monId], MON_DATA_SPDEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_COOL_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_COOL);
        size = 1;
        break;
    case REQUEST_BEAUTY_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_BEAUTY);
        size = 1;
        break;
    case REQUEST_CUTE_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_CUTE);
        size = 1;
        break;
    case REQUEST_SMART_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SMART);
        size = 1;
        break;
    case REQUEST_TOUGH_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_TOUGH);
        size = 1;
        break;
    case REQUEST_SHEEN_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SHEEN);
        size = 1;
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_COOL_RIBBON);
        size = 1;
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_BEAUTY_RIBBON);
        size = 1;
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_CUTE_RIBBON);
        size = 1;
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_SMART_RIBBON);
        size = 1;
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        dst[0] = GetMonData(&gEnemyParty[monId], MON_DATA_TOUGH_RIBBON);
        size = 1;
        break;
    }

    return size;
}

static void OpponentHandleGetRawMonData(void)
{
    struct BattlePokemon battleMon;
    u8 *src = (u8 *)&gEnemyParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 *dst = (u8 *)&battleMon + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = src[i];

    EmitDataTransfer(1, gBattleBufferA[gActiveBank][2], dst);
    OpponentBufferExecCompleted();
}

static void OpponentHandleSetMonData(void)
{
    u8 monToCheck;
    u8 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        SetOpponentMonData(gBattlePartyID[gActiveBank]);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                SetOpponentMonData(i);
            monToCheck >>= 1;
        }
    }
    OpponentBufferExecCompleted();
}

static void SetOpponentMonData(u8 monId)
{
    struct BattlePokemon *battlePokemon = (struct BattlePokemon *)&gBattleBufferA[gActiveBank][3];
    struct MovePpInfo *moveData = (struct MovePpInfo *)&gBattleBufferA[gActiveBank][3];
    s32 i;

    switch (gBattleBufferA[gActiveBank][1])
    {
    case REQUEST_ALL_BATTLE:
        {
            u8 iv;

            SetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, &battlePokemon->species);
            SetMonData(&gEnemyParty[monId], MON_DATA_HELD_ITEM, &battlePokemon->item);
            for (i = 0; i < 4; i++)
            {
                SetMonData(&gEnemyParty[monId], MON_DATA_MOVE1 + i, &battlePokemon->moves[i]);
                SetMonData(&gEnemyParty[monId], MON_DATA_PP1 + i, &battlePokemon->pp[i]);
            }
            SetMonData(&gEnemyParty[monId], MON_DATA_PP_BONUSES, &battlePokemon->ppBonuses);
            SetMonData(&gEnemyParty[monId], MON_DATA_FRIENDSHIP, &battlePokemon->friendship);
            SetMonData(&gEnemyParty[monId], MON_DATA_EXP, &battlePokemon->experience);
            iv = battlePokemon->hpIV;
            SetMonData(&gEnemyParty[monId], MON_DATA_HP_IV, &iv);
            iv = battlePokemon->attackIV;
            SetMonData(&gEnemyParty[monId], MON_DATA_ATK_IV, &iv);
            iv = battlePokemon->defenseIV;
            SetMonData(&gEnemyParty[monId], MON_DATA_DEF_IV, &iv);
            iv = battlePokemon->speedIV;
            SetMonData(&gEnemyParty[monId], MON_DATA_SPEED_IV, &iv);
            iv = battlePokemon->spAttackIV;
            SetMonData(&gEnemyParty[monId], MON_DATA_SPATK_IV, &iv);
            iv = battlePokemon->spDefenseIV;
            SetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_IV, &iv);
            SetMonData(&gEnemyParty[monId], MON_DATA_PERSONALITY, &battlePokemon->personality);
            SetMonData(&gEnemyParty[monId], MON_DATA_STATUS, &battlePokemon->status1);
            SetMonData(&gEnemyParty[monId], MON_DATA_LEVEL, &battlePokemon->level);
            SetMonData(&gEnemyParty[monId], MON_DATA_HP, &battlePokemon->hp);
            SetMonData(&gEnemyParty[monId], MON_DATA_MAX_HP, &battlePokemon->maxHP);
            SetMonData(&gEnemyParty[monId], MON_DATA_ATK, &battlePokemon->attack);
            SetMonData(&gEnemyParty[monId], MON_DATA_DEF, &battlePokemon->defense);
            SetMonData(&gEnemyParty[monId], MON_DATA_SPEED, &battlePokemon->speed);
            SetMonData(&gEnemyParty[monId], MON_DATA_SPATK, &battlePokemon->spAttack);
            SetMonData(&gEnemyParty[monId], MON_DATA_SPDEF, &battlePokemon->spDefense);
        }
        break;
    case REQUEST_SPECIES_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HELDITEM_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_HELD_ITEM, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (i = 0; i < 4; i++)
        {
            SetMonData(&gEnemyParty[monId], MON_DATA_MOVE1 + i, &moveData->moves[i]);
            SetMonData(&gEnemyParty[monId], MON_DATA_PP1 + i, &moveData->pp[i]);
        }
        SetMonData(&gEnemyParty[monId], MON_DATA_PP_BONUSES, &moveData->ppBonuses);
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_MOVE1 + gBattleBufferA[gActiveBank][1] - REQUEST_MOVE1_BATTLE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_PP_DATA_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_PP1, &gBattleBufferA[gActiveBank][3]);
        SetMonData(&gEnemyParty[monId], MON_DATA_PP2, &gBattleBufferA[gActiveBank][4]);
        SetMonData(&gEnemyParty[monId], MON_DATA_PP3, &gBattleBufferA[gActiveBank][5]);
        SetMonData(&gEnemyParty[monId], MON_DATA_PP4, &gBattleBufferA[gActiveBank][6]);
        SetMonData(&gEnemyParty[monId], MON_DATA_PP_BONUSES, &gBattleBufferA[gActiveBank][7]);
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_PP1 + gBattleBufferA[gActiveBank][1] - REQUEST_PPMOVE1_BATTLE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_OTID_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_OT_ID, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_EXP_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_EXP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HP_EV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_HP_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_EV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_ATK_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_EV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_DEF_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_EV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPEED_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_EV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPATK_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_FRIENDSHIP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_POKERUS_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_POKERUS, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_MET_LOCATION, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_MET_LEVEL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_GAME_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_MET_GAME, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_POKEBALL_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_POKEBALL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ALL_IVS_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_HP_IV, &gBattleBufferA[gActiveBank][3]);
        SetMonData(&gEnemyParty[monId], MON_DATA_ATK_IV, &gBattleBufferA[gActiveBank][4]);
        SetMonData(&gEnemyParty[monId], MON_DATA_DEF_IV, &gBattleBufferA[gActiveBank][5]);
        SetMonData(&gEnemyParty[monId], MON_DATA_SPEED_IV, &gBattleBufferA[gActiveBank][6]);
        SetMonData(&gEnemyParty[monId], MON_DATA_SPATK_IV, &gBattleBufferA[gActiveBank][7]);
        SetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_IV, &gBattleBufferA[gActiveBank][8]);
        break;
    case REQUEST_HP_IV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_HP_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_IV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_ATK_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_IV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_DEF_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_IV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPEED_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_IV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPATK_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPDEF_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_PERSONALITY_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_PERSONALITY, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CHECKSUM_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_CHECKSUM, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_STATUS_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_STATUS, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_LEVEL_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_LEVEL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HP_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_HP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MAX_HP_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_MAX_HP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_ATK, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_DEF, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPEED, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPATK, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SPDEF, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_COOL_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_COOL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_BEAUTY_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_BEAUTY, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CUTE_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_CUTE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SMART_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SMART, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_TOUGH_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_TOUGH, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SHEEN_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SHEEN, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_COOL_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_BEAUTY_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_CUTE_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_SMART_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        SetMonData(&gEnemyParty[monId], MON_DATA_TOUGH_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    }
}

static void OpponentHandleSetRawMonData(void)
{
    u8 *dst = (u8 *)&gEnemyParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = gBattleBufferA[gActiveBank][3 + i];

    OpponentBufferExecCompleted();
}

static void OpponentHandleLoadMonSprite(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[gActiveBank]], gActiveBank);
    sub_806A068(species, GetBankIdentity(gActiveBank));

    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               sub_80A5C6C(gActiveBank, 2),
                                               GetBankSpriteDefault_Y(gActiveBank),
                                               sub_80A82E4(gActiveBank));

    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = species;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], gBattleMonForms[gActiveBank]);

    SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));

    gBattleBankFunc[gActiveBank] = sub_805F994;
}

static void OpponentHandleSwitchInAnim(void)
{
    *(gBattleStruct->monToSwitchIntoId + gActiveBank) = 6;
    gBattlePartyID[gActiveBank] = gBattleBufferA[gActiveBank][1];
    sub_80613DC(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattleBankFunc[gActiveBank] = sub_805FDF0;
}

static void sub_80613DC(u8 bank, bool8 dontClearSubstituteBit)
{
    u16 species;

    ClearTemporarySpeciesSpriteData(bank, dontClearSubstituteBit);
    gBattlePartyID[bank] = gBattleBufferA[bank][1];
    species = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES);
    gUnknown_03005D7C[bank] = CreateInvisibleSpriteWithCallback(sub_805D714);
    BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[bank]], bank);
    sub_806A068(species, GetBankIdentity(bank));

    gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C,
                                        sub_80A5C6C(bank, 2),
                                        GetBankSpriteDefault_Y(bank),
                                        sub_80A82E4(bank));

    gSprites[gBankSpriteIds[bank]].data0 = bank;
    gSprites[gBankSpriteIds[bank]].data2 = species;

    gSprites[gUnknown_03005D7C[bank]].data1 = gBankSpriteIds[bank];
    gSprites[gUnknown_03005D7C[bank]].data2 = bank;

    gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;

    StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], gBattleMonForms[bank]);

    gSprites[gBankSpriteIds[bank]].invisible = TRUE;
    gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;

    gSprites[gUnknown_03005D7C[bank]].data0 = sub_80753E8(0, 0xFE);
}

static void OpponentHandleReturnMonToBall(void)
{
    if (gBattleBufferA[gActiveBank][1] == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
        gBattleBankFunc[gActiveBank] = DoSwitchOutAnimation;
    }
    else
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        EnemyShadowCallbackToSetInvisible(gActiveBank);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        OpponentBufferExecCompleted();
    }
}

static void DoSwitchOutAnimation(void)
{
    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SWITCH_OUT_OPPONENT_MON);
            gBattleBankFunc[gActiveBank] = sub_805FB08;
        }
        break;
    }
}

static void OpponentHandleDrawTrainerPic(void)
{
    u32 trainerPicId;
    s16 xPos;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        trainerPicId = GetSecretBaseTrainerPicIndex();
    }
    else if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_3FE)
    {
        trainerPicId = sub_81A4CB0();
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_x4000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (gActiveBank == 1)
                trainerPicId = sub_81D5588(gTrainerBattleOpponent_A);
            else
                trainerPicId = sub_81D5588(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = sub_81D5588(gTrainerBattleOpponent_A);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
        {
            if (gActiveBank == 1)
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
            else
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        trainerPicId = GetEreaderTrainerFrontSpriteId();
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (gActiveBank != 1)
            trainerPicId = gTrainers[gTrainerBattleOpponent_B].trainerPic;
        else
            trainerPicId = gTrainers[gTrainerBattleOpponent_A].trainerPic;
    }
    else
    {
        trainerPicId = gTrainers[gTrainerBattleOpponent_A].trainerPic;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS))
    {
        if ((GetBankIdentity(gActiveBank) & BIT_MON) != 0) // second mon
            xPos = 152;
        else // first mon
            xPos = 200;
    }
    else
    {
        xPos = 176;
    }

    DecompressTrainerFrontPic(trainerPicId, gActiveBank);
    sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               xPos,
                                               (8 - gTrainerFrontPicCoords[trainerPicId].coords) * 4 + 40,
                                               sub_80A82E4(gActiveBank));

    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 2;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerFrontPicPaletteTable[trainerPicId].tag);
    gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam = trainerPicId;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy;
}

static void OpponentHandleTrainerSlide(void)
{
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        trainerPicId = GetSecretBaseTrainerPicIndex();
    }
    else if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_3FE)
    {
        trainerPicId = sub_81A4CB0();
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_x4000000)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (gActiveBank == 1)
                trainerPicId = sub_81D5588(gTrainerBattleOpponent_A);
            else
                trainerPicId = sub_81D5588(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = sub_81D5588(gTrainerBattleOpponent_A);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
        {
            if (gActiveBank == 1)
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
            else
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        trainerPicId = GetEreaderTrainerFrontSpriteId();
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (gActiveBank != 1)
            trainerPicId = gTrainers[gTrainerBattleOpponent_B].trainerPic;
        else
            trainerPicId = gTrainers[gTrainerBattleOpponent_A].trainerPic;
    }
    else
    {
        trainerPicId = gTrainers[gTrainerBattleOpponent_A].trainerPic;
    }

    DecompressTrainerFrontPic(trainerPicId, gActiveBank);
    sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C, 176, (8 - gTrainerFrontPicCoords[trainerPicId].coords) * 4 + 40, 0x1E);

    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 96;
    gSprites[gBankSpriteIds[gActiveBank]].pos1.x += 32;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerFrontPicPaletteTable[trainerPicId].tag);
    gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam = trainerPicId;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy2;
}

static void OpponentHandleTrainerSlideBack(void)
{
    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = 280;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], SpriteCallbackDummy);
    gBattleBankFunc[gActiveBank] = sub_805F240;
}

static void OpponentHandleFaintAnimation(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState == 0)
    {
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState++;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            PlaySE12WithPanning(SE_POKE_DEAD, PAN_SIDE_OPPONENT);
            gSprites[gBankSpriteIds[gActiveBank]].callback = sub_8039934;
            gBattleBankFunc[gActiveBank] = sub_805FAC4;
        }
    }
}

static void OpponentHandlePaletteFade(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleSuccessBallThrowAnim(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleBallThrow(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandlePause(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleMoveAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u16 move = gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8);

        gAnimMoveTurn = gBattleBufferA[gActiveBank][3];
        gAnimMovePower = gBattleBufferA[gActiveBank][4] | (gBattleBufferA[gActiveBank][5] << 8);
        gAnimMoveDmg = gBattleBufferA[gActiveBank][6] | (gBattleBufferA[gActiveBank][7] << 8) | (gBattleBufferA[gActiveBank][8] << 16) | (gBattleBufferA[gActiveBank][9] << 24);
        gAnimFriendship = gBattleBufferA[gActiveBank][10];
        gWeatherMoveAnim = gBattleBufferA[gActiveBank][12] | (gBattleBufferA[gActiveBank][13] << 8);
        gAnimDisableStructPtr = (struct DisableStruct *)&gBattleBufferA[gActiveBank][16];
        gTransformedPersonalities[gActiveBank] = gAnimDisableStructPtr->transformedMonPersonality;
        if (IsMoveWithoutAnimation(move, gAnimMoveTurn)) // always returns FALSE
        {
            OpponentBufferExecCompleted();
        }
        else
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            gBattleBankFunc[gActiveBank] = OpponentDoMoveAnimation;
        }
    }
}

static void OpponentDoMoveAnimation(void)
{
    u16 move = gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8);
    u8 multihit = gBattleBufferA[gActiveBank][11];

    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute
            && !gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8)
        {
            gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8 = 1;
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            sub_805EB9C(0);
            DoMoveAnim(move);
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 2;
        }
        break;
    case 2:
        gAnimScriptCallback();
        if (!gAnimScriptActive)
        {
            sub_805EB9C(1);
            if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute && multihit < 2)
            {
                InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);
                gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8 = 0;
            }
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            CopyAllBattleSpritesInvisibilities();
            TrySetBehindSubstituteSpriteBit(gActiveBank, gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            OpponentBufferExecCompleted();
        }
        break;
    }
}

static void OpponentHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBank][2]);
    BufferStringBattle(*stringId);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 0);
    gBattleBankFunc[gActiveBank] = CompleteOnInactiveTextPrinter;
    sub_81A57E4(gActiveBank, *stringId);
}

static void OpponentHandlePrintStringPlayerOnly(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleChooseAction(void)
{
    AI_TrySwitchOrUseItem();
    OpponentBufferExecCompleted();
}

static void OpponentHandleUnknownYesNoBox(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleChooseMove(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        EmitTwoReturnValues(1, 10, ChooseMoveAndTargetInBattlePalace());
        OpponentBufferExecCompleted();
    }
    else
    {
        u8 chosenMoveId;
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);

        if (gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FIRST_BATTLE | BATTLE_TYPE_SAFARI | BATTLE_TYPE_ROAMER))
        {

            BattleAI_SetupAIData(0xF);
            chosenMoveId = BattleAI_ChooseMoveOrAction();

            switch (chosenMoveId)
            {
            case 5:
                EmitTwoReturnValues(1, ACTION_WATCHES_CAREFULLY, 0);
                break;
            case 4:
                EmitTwoReturnValues(1, ACTION_RUN, 0);
                break;
            case 6:
                EmitTwoReturnValues(1, 15, gBankTarget);
                break;
            default:
                if (gBattleMoves[moveInfo->moves[chosenMoveId]].target & (MOVE_TARGET_USER | MOVE_TARGET_x10))
                    gBankTarget = gActiveBank;
                if (gBattleMoves[moveInfo->moves[chosenMoveId]].target & MOVE_TARGET_BOTH)
                {
                    gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON1);
                    if (gAbsentBankFlags & gBitTable[gBankTarget])
                        gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON2);
                }
                EmitTwoReturnValues(1, 10, (chosenMoveId) | (gBankTarget << 8));
                break;
            }
            OpponentBufferExecCompleted();
        }
        else
        {
            u16 move;
            do
            {
                chosenMoveId = Random() & 3;
                move = moveInfo->moves[chosenMoveId];
            } while (move == MOVE_NONE);

            if (gBattleMoves[move].target & (MOVE_TARGET_USER | MOVE_TARGET_x10))
                EmitTwoReturnValues(1, 10, (chosenMoveId) | (gActiveBank << 8));
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                EmitTwoReturnValues(1, 10, (chosenMoveId) | (GetBankByIdentity(Random() & 2) << 8));
            else
                EmitTwoReturnValues(1, 10, (chosenMoveId) | (GetBankByIdentity(IDENTITY_PLAYER_MON1) << 8));

            OpponentBufferExecCompleted();
        }
    }
}

static void OpponentHandleChooseItem(void)
{
    EmitOneReturnValue(1, *(gBattleStruct->chosenItem + (gActiveBank / 2) * 2));
    OpponentBufferExecCompleted();
}

static void OpponentHandleChoosePokemon(void)
{
    s32 chosenMonId;

    if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBank) == 6)
    {
        chosenMonId = GetMostSuitableMonToSwitchInto();

        if (chosenMonId == 6)
        {
            s32 bank1, bank2, firstId, lastId;

            if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
            {
                bank2 = bank1 = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
            }
            else
            {
                bank1 = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
                bank2 = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
            }

            if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
            {
                if (gActiveBank == 1)
                    firstId = 0, lastId = 3;
                else
                    firstId = 3, lastId = 6;
            }
            else
            {
                firstId = 0, lastId = 6;
            }

            for (chosenMonId = firstId; chosenMonId < lastId; chosenMonId++)
            {
                if (GetMonData(&gEnemyParty[chosenMonId], MON_DATA_HP) != 0
                    && chosenMonId != gBattlePartyID[bank1]
                    && chosenMonId != gBattlePartyID[bank2])
                {
                    break;
                }
            }
        }
    }
    else
    {
        chosenMonId = *(gBattleStruct->AI_monToSwitchIntoId + gActiveBank);
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBank) = 6;
    }


    *(gBattleStruct->monToSwitchIntoId + gActiveBank) = chosenMonId;
    EmitChosenMonReturnValue(1, chosenMonId, NULL);
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd23(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleHealthBarUpdate(void)
{
    s16 hpVal;

    LoadBattleBarGfx(0);
    hpVal = (gBattleBufferA[gActiveBank][3] << 8) | gBattleBufferA[gActiveBank][2];

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        u32 maxHP = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_MAX_HP);
        u32 curHP = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_HP);

        SetBattleBarStruct(gActiveBank, gHealthBoxesIds[gActiveBank], maxHP, curHP, hpVal);
    }
    else
    {
        u32 maxHP = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_MAX_HP);

        SetBattleBarStruct(gActiveBank, gHealthBoxesIds[gActiveBank], maxHP, 0, hpVal);
    }

    gBattleBankFunc[gActiveBank] = CompleteOnHealthbarDone;
}

static void OpponentHandleExpUpdate(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleStatusIconUpdate(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 bank;

        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gEnemyParty[gBattlePartyID[gActiveBank]], HEALTHBOX_STATUS_ICON);
        bank = gActiveBank;
        gBattleSpritesDataPtr->healthBoxesData[bank].statusAnimActive = 0;
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void OpponentHandleStatusAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        InitAndLaunchChosenStatusAnimation(gBattleBufferA[gActiveBank][1],
                        gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8) | (gBattleBufferA[gActiveBank][4] << 16) | (gBattleBufferA[gActiveBank][5] << 24));
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void OpponentHandleStatusXor(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleDataTransfer(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleDMA3Transfer(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandlePlayBGM(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd32(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleTwoReturnValues(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleChosenMonReturnValue(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleOneReturnValue(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleOneReturnValue_Duplicate(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd37(void)
{
    gUnknown_02022D0C.field_0 = 0;
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd38(void)
{
    gUnknown_02022D0C.field_0 = gBattleBufferA[gActiveBank][1];
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd39(void)
{
    gUnknown_02022D0C.flag_x80 = 0;
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd40(void)
{
    gUnknown_02022D0C.flag_x80 ^= 1;
    OpponentBufferExecCompleted();
}

static void OpponentHandleHitAnimation(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].invisible == TRUE)
    {
        OpponentBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
        DoHitAnimHealthboxEffect(gActiveBank);
        gBattleBankFunc[gActiveBank] = DoHitAnimBlinkSpriteEffect;
    }
}

static void OpponentHandleCmd42(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleEffectivenessSound(void)
{
    s8 pan;

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        pan = PAN_SIDE_PLAYER;
    else
        pan = PAN_SIDE_OPPONENT;

    PlaySE12WithPanning(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8), pan);
    OpponentBufferExecCompleted();
}

static void OpponentHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBank][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }

    OpponentBufferExecCompleted();
}

static void OpponentHandleFaintingCry(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry3(species, 25, 5);
    OpponentBufferExecCompleted();
}

static void OpponentHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    OpponentBufferExecCompleted();
}

static void OpponentHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;

    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);

    gSprites[gBankSpriteIds[gActiveBank]].data0 = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = 280;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;

    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], sub_806280C);

    taskId = CreateTask(sub_8062828, 5);
    gTasks[taskId].data[0] = gActiveBank;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattleBankFunc[gActiveBank] = nullsub_26;
}

static void sub_806280C(struct Sprite *sprite)
{
    FreeTrainerFrontPicPalette(sprite->oam.affineParam);
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
}

static void sub_8062828(u8 taskId)
{
    u8 savedActiveBank = gActiveBank;

    gActiveBank = gTasks[taskId].data[0];
    if (!IsDoubleBattle() || (gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_80613DC(gActiveBank, FALSE);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_80613DC(gActiveBank, FALSE);
    }
    else
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_80613DC(gActiveBank, FALSE);
        gActiveBank ^= BIT_MON;
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_80613DC(gActiveBank, FALSE);
        gActiveBank ^= BIT_MON;
    }
    gBattleBankFunc[gActiveBank] = sub_805F560;
    gActiveBank = savedActiveBank;
    DestroyTask(taskId);
}

static void OpponentHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBank][1] != 0 && GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        OpponentBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1 = 1;

        if (gBattleBufferA[gActiveBank][2] != 0)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1E < 2)
            {
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1E++;
                return;
            }
            else
            {
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1E = 0;
            }
        }

        gUnknown_020244B4[gActiveBank] = CreatePartyStatusSummarySprites(gActiveBank, (struct HpAndStatus *)&gBattleBufferA[gActiveBank][4], gBattleBufferA[gActiveBank][1], gBattleBufferA[gActiveBank][2]);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;

        if (gBattleBufferA[gActiveBank][2] != 0)
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0x5D;

        gBattleBankFunc[gActiveBank] = sub_8062A2C;
    }
}

static void sub_8062A2C(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5++ > 0x5C)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;
        OpponentBufferExecCompleted();
    }
}

static void OpponentHandleCmd49(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd50(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleSpriteInvisibility(void)
{
    if (IsBankSpritePresent(gActiveBank))
    {
        gSprites[gBankSpriteIds[gActiveBank]].invisible = gBattleBufferA[gActiveBank][1];
        CopyBattleSpriteInvisibility(gActiveBank);
    }
    OpponentBufferExecCompleted();
}

static void OpponentHandleBattleAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 animationId = gBattleBufferA[gActiveBank][1];
        u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

        if (TryHandleLaunchBattleTableAnimation(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
            OpponentBufferExecCompleted();
        else
            gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;
    }
}

static void OpponentHandleLinkStandbyMsg(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleResetActionMoveSelection(void)
{
    OpponentBufferExecCompleted();
}

static void OpponentHandleCmd55(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK && !(gBattleTypeFlags & BATTLE_TYPE_WILD))
    {
        gMain.inBattle = 0;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
    OpponentBufferExecCompleted();
}

static void nullsub_91(void)
{
}
