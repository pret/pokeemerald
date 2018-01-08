#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_link_817C95C.h"
#include "recorded_battle.h"
#include "pokemon.h"
#include "link.h"
#include "util.h"
#include "main.h"
#include "constants/songs.h"
#include "sound.h"
#include "window.h"
#include "m4a.h"
#include "palette.h"
#include "task.h"
#include "text.h"
#include "string_util.h"
#include "bg.h"
#include "reshow_battle_screen.h"
#include "pokeball.h"
#include "data2.h"

extern u32 gBattleExecBuffer;
extern u8 gActiveBank;
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern bool8 gDoingBattleAnim;
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern void (*gPreBattleCallback1)(void);
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern struct SpriteTemplate gUnknown_0202499C;
extern u16 gSpecialVar_ItemId;
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern u8 gBattleOutcome;
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gUnknown_020243FC;
extern u8 gUnknown_03005D7C[BATTLE_BANKS_COUNT];
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u16 gPartnerTrainerId;
extern u8 GetFrontierTrainerFrontSpriteId(u16 trainerId);
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u8 gUnknown_020244B4[];
extern u32 gTransformedPersonalities[BATTLE_BANKS_COUNT];
extern struct MusicPlayerInfo gMPlay_BGM;
extern struct UnusedControllerStruct gUnknown_02022D0C;
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u8 gUnknown_0203C7B4;

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);
extern u16 sub_8068B48(void);

// this file's functions
static void RecordedOpponentHandleGetMonData(void);
static void RecordedOpponentHandleGetRawMonData(void);
static void RecordedOpponentHandleSetMonData(void);
static void RecordedOpponentHandleSetRawMonData(void);
static void RecordedOpponentHandleLoadMonSprite(void);
static void RecordedOpponentHandleSwitchInAnim(void);
static void RecordedOpponentHandleReturnMonToBall(void);
static void RecordedOpponentHandleDrawTrainerPic(void);
static void RecordedOpponentHandleTrainerSlide(void);
static void RecordedOpponentHandleTrainerSlideBack(void);
static void RecordedOpponentHandleFaintAnimation(void);
static void RecordedOpponentHandlePaletteFade(void);
static void RecordedOpponentHandleSuccessBallThrowAnim(void);
static void RecordedOpponentHandleBallThrowAnim(void);
static void RecordedOpponentHandlePause(void);
static void RecordedOpponentHandleMoveAnimation(void);
static void RecordedOpponentHandlePrintString(void);
static void RecordedOpponentHandlePrintSelectionString(void);
static void RecordedOpponentHandleChooseAction(void);
static void RecordedOpponentHandleUnknownYesNoBox(void);
static void RecordedOpponentHandleChooseMove(void);
static void RecordedOpponentHandleChooseItem(void);
static void RecordedOpponentHandleChoosePokemon(void);
static void RecordedOpponentHandleCmd23(void);
static void RecordedOpponentHandleHealthBarUpdate(void);
static void RecordedOpponentHandleExpUpdate(void);
static void RecordedOpponentHandleStatusIconUpdate(void);
static void RecordedOpponentHandleStatusAnimation(void);
static void RecordedOpponentHandleStatusXor(void);
static void RecordedOpponentHandleDataTransfer(void);
static void RecordedOpponentHandleDMA3Transfer(void);
static void RecordedOpponentHandlePlayBGM(void);
static void RecordedOpponentHandleCmd32(void);
static void RecordedOpponentHandleTwoReturnValues(void);
static void RecordedOpponentHandleChosenMonReturnValue(void);
static void RecordedOpponentHandleOneReturnValue(void);
static void RecordedOpponentHandleOneReturnValue_Duplicate(void);
static void RecordedOpponentHandleCmd37(void);
static void RecordedOpponentHandleCmd38(void);
static void RecordedOpponentHandleCmd39(void);
static void RecordedOpponentHandleCmd40(void);
static void RecordedOpponentHandleHitAnimation(void);
static void RecordedOpponentHandleCmd42(void);
static void RecordedOpponentHandlePlaySE(void);
static void RecordedOpponentHandlePlayFanfareOrBGM(void);
static void RecordedOpponentHandleFaintingCry(void);
static void RecordedOpponentHandleIntroSlide(void);
static void RecordedOpponentHandleIntroTrainerBallThrow(void);
static void RecordedOpponentHandleDrawPartyStatusSummary(void);
static void RecordedOpponentHandleCmd49(void);
static void RecordedOpponentHandleCmd50(void);
static void RecordedOpponentHandleSpriteInvisibility(void);
static void RecordedOpponentHandleBattleAnimation(void);
static void RecordedOpponentHandleLinkStandbyMsg(void);
static void RecordedOpponentHandleResetActionMoveSelection(void);
static void RecordedOpponentHandleCmd55(void);
static void nullsub_119(void);

static void RecordedOpponentBufferRunCommand(void);
static void RecordedOpponentBufferExecCompleted(void);
static void sub_8186F14(void);
static u32 CopyRecordedOpponentMonData(u8 monId, u8 *dst);
static void SetRecordedOpponentMonData(u8 monId);
static void sub_81885D8(u8 bank, bool8 dontClearSubstituteBit);
static void DoSwitchOutAnimation(void);
static void RecordedOpponentDoMoveAnimation(void);
static void sub_8189548(u8 taskId);
static void sub_818962C(struct Sprite *sprite);
static void sub_818975C(void);

static void (*const sRecordedOpponentBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    RecordedOpponentHandleGetMonData,
    RecordedOpponentHandleGetRawMonData,
    RecordedOpponentHandleSetMonData,
    RecordedOpponentHandleSetRawMonData,
    RecordedOpponentHandleLoadMonSprite,
    RecordedOpponentHandleSwitchInAnim,
    RecordedOpponentHandleReturnMonToBall,
    RecordedOpponentHandleDrawTrainerPic,
    RecordedOpponentHandleTrainerSlide,
    RecordedOpponentHandleTrainerSlideBack,
    RecordedOpponentHandleFaintAnimation,
    RecordedOpponentHandlePaletteFade,
    RecordedOpponentHandleSuccessBallThrowAnim,
    RecordedOpponentHandleBallThrowAnim,
    RecordedOpponentHandlePause,
    RecordedOpponentHandleMoveAnimation,
    RecordedOpponentHandlePrintString,
    RecordedOpponentHandlePrintSelectionString,
    RecordedOpponentHandleChooseAction,
    RecordedOpponentHandleUnknownYesNoBox,
    RecordedOpponentHandleChooseMove,
    RecordedOpponentHandleChooseItem,
    RecordedOpponentHandleChoosePokemon,
    RecordedOpponentHandleCmd23,
    RecordedOpponentHandleHealthBarUpdate,
    RecordedOpponentHandleExpUpdate,
    RecordedOpponentHandleStatusIconUpdate,
    RecordedOpponentHandleStatusAnimation,
    RecordedOpponentHandleStatusXor,
    RecordedOpponentHandleDataTransfer,
    RecordedOpponentHandleDMA3Transfer,
    RecordedOpponentHandlePlayBGM,
    RecordedOpponentHandleCmd32,
    RecordedOpponentHandleTwoReturnValues,
    RecordedOpponentHandleChosenMonReturnValue,
    RecordedOpponentHandleOneReturnValue,
    RecordedOpponentHandleOneReturnValue_Duplicate,
    RecordedOpponentHandleCmd37,
    RecordedOpponentHandleCmd38,
    RecordedOpponentHandleCmd39,
    RecordedOpponentHandleCmd40,
    RecordedOpponentHandleHitAnimation,
    RecordedOpponentHandleCmd42,
    RecordedOpponentHandlePlaySE,
    RecordedOpponentHandlePlayFanfareOrBGM,
    RecordedOpponentHandleFaintingCry,
    RecordedOpponentHandleIntroSlide,
    RecordedOpponentHandleIntroTrainerBallThrow,
    RecordedOpponentHandleDrawPartyStatusSummary,
    RecordedOpponentHandleCmd49,
    RecordedOpponentHandleCmd50,
    RecordedOpponentHandleSpriteInvisibility,
    RecordedOpponentHandleBattleAnimation,
    RecordedOpponentHandleLinkStandbyMsg,
    RecordedOpponentHandleResetActionMoveSelection,
    RecordedOpponentHandleCmd55,
    nullsub_119
};

static void nullsub_70(void)
{
}

void SetControllerToRecordedOpponent(void)
{
    gBattleBankFunc[gActiveBank] = RecordedOpponentBufferRunCommand;
}

static void RecordedOpponentBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(sRecordedOpponentBufferCommands))
            sRecordedOpponentBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            RecordedOpponentBufferExecCompleted();
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        RecordedOpponentBufferExecCompleted();
}

static void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        RecordedOpponentBufferExecCompleted();
}

static void sub_81865C8(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        FreeTrainerFrontPicPalette(gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        RecordedOpponentBufferExecCompleted();
    }
}

static void sub_8186630(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 0xFF)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
        RecordedOpponentBufferExecCompleted();
    }
}

static void sub_8186678(void)
{
    bool8 var = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].animEnded)
        {
            var = TRUE;
        }

    }
    else
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gHealthBoxesIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].animEnded
            && gSprites[gBankSpriteIds[gActiveBank ^ BIT_MON]].animEnded)
         {
             var = TRUE;
         }
    }

    if (var)
    {
        if (GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON1)
        {
            if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
                return;
            if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1)
                return;

            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 = 0;
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1 = 0;
            FreeSpriteTilesByTag(0x27F9);
            FreeSpritePaletteByTag(0x27F9);
        }

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 3;
        gBattleBankFunc[gActiveBank] = sub_8186630;
    }
}

static void sub_818686C(void)
{
    bool32 r9 = FALSE;
    bool32 r8 = FALSE;

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].ballAnimActive)
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].ballAnimActive)
        sub_8172EF0(gActiveBank ^ BIT_MON, &gEnemyParty[gBattlePartyID[gActiveBank ^ BIT_MON]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].ballAnimActive && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].ballAnimActive)
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
                if (GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON1)
                    m4aMPlayContinue(&gMPlay_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            }
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20 = 1;
        r9 = TRUE;
    }

    if (!IsDoubleBattle())
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        {
            r8 = TRUE;
        }
    }
    else
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
        {
            r8 = TRUE;
        }
    }

    if (r9 && r8)
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

        gBattleBankFunc[gActiveBank] = sub_8186678;
    }
}

static void sub_8186C48(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
     && gSprites[gBankSpriteIds[gActiveBank]].pos2.x == 0)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80)
        {
            sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);
        }
        else
        {
            if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
            {
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
                FreeSpriteTilesByTag(0x27F9);
                FreeSpritePaletteByTag(0x27F9);
                RecordedOpponentBufferExecCompleted();
            }
        }
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
    {
        RecordedOpponentBufferExecCompleted();
    }
}

static void sub_8186D58(void)
{
    if (!gSprites[gBankSpriteIds[gActiveBank]].inUse)
    {
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        RecordedOpponentBufferExecCompleted();
    }
}

static void sub_8186D9C(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        EnemyShadowCallbackToSetInvisible(gActiveBank);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        RecordedOpponentBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        RecordedOpponentBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBankSpriteIds[gActiveBank];

    if (gSprites[spriteId].data[1] == 32)
    {
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = 0;
        gDoingBattleAnim = FALSE;
        RecordedOpponentBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data[1] % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data[1]++;
    }
}

static void sub_8186EA4(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);

        gBattleBankFunc[gActiveBank] = sub_8186F14;
    }
}

static void sub_8186F14(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive
        && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
            || gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy_2)
        {
            m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            RecordedOpponentBufferExecCompleted();
        }
    }
}

static void sub_8186F94(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1
     && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
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
        gBattleBankFunc[gActiveBank] = sub_8186EA4;
    }
}

static void sub_8187084(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80)
    {
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);
    }

    if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].ballAnimActive)
    {
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));
        gBattleBankFunc[gActiveBank] = sub_8186F94;
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        RecordedOpponentBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = RecordedOpponentBufferRunCommand;
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

static void RecordedOpponentHandleGetMonData(void)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    u32 size = 0;
    u8 monToCheck;
    s32 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        size += CopyRecordedOpponentMonData(gBattlePartyID[gActiveBank], monData);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                size += CopyRecordedOpponentMonData(i, monData + size);
            monToCheck >>= 1;
        }
    }
    EmitDataTransfer(1, size, monData);
    RecordedOpponentBufferExecCompleted();
}

static u32 CopyRecordedOpponentMonData(u8 monId, u8 *dst)
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

static void RecordedOpponentHandleGetRawMonData(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleSetMonData(void)
{
    u8 monToCheck;
    u8 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        SetRecordedOpponentMonData(gBattlePartyID[gActiveBank]);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                SetRecordedOpponentMonData(i);
            monToCheck >>= 1;
        }
    }
    RecordedOpponentBufferExecCompleted();
}

static void SetRecordedOpponentMonData(u8 monId)
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

static void RecordedOpponentHandleSetRawMonData(void)
{
    u8 *dst = (u8 *)&gEnemyParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = gBattleBufferA[gActiveBank][3 + i];

    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleLoadMonSprite(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[gActiveBank]], gActiveBank);
    sub_806A068(species, GetBankIdentity(gActiveBank));

    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               GetBankPosition(gActiveBank, 2),
                                               GetBankSpriteDefault_Y(gActiveBank),
                                               sub_80A82E4(gActiveBank));



    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -240;
    gSprites[gBankSpriteIds[gActiveBank]].data[0] = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], gBattleMonForms[gActiveBank]);

    SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));

    gBattleBankFunc[gActiveBank] = sub_8186C48;
}

static void RecordedOpponentHandleSwitchInAnim(void)
{
    gBattlePartyID[gActiveBank] = gBattleBufferA[gActiveBank][1];
    sub_81885D8(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattleBankFunc[gActiveBank] = sub_8187084;
}

static void sub_81885D8(u8 bank, bool8 dontClearSubstituteBit)
{
    u16 species;

    ClearTemporarySpeciesSpriteData(bank, dontClearSubstituteBit);
    gBattlePartyID[bank] = gBattleBufferA[bank][1];
    species = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES);
    gUnknown_03005D7C[bank] = CreateInvisibleSpriteWithCallback(sub_805D714);
    BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[bank]], bank);
    sub_806A068(species, GetBankIdentity(bank));

    gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C,
                                        GetBankPosition(bank, 2),
                                        GetBankSpriteDefault_Y(bank),
                                        sub_80A82E4(bank));

    gSprites[gUnknown_03005D7C[bank]].data[1] = gBankSpriteIds[bank];
    gSprites[gUnknown_03005D7C[bank]].data[2] = bank;

    gSprites[gBankSpriteIds[bank]].data[0] = bank;
    gSprites[gBankSpriteIds[bank]].data[2] = species;
    gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;

    StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], gBattleMonForms[bank]);

    gSprites[gBankSpriteIds[bank]].invisible = TRUE;
    gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;

    gSprites[gUnknown_03005D7C[bank]].data[0] = DoPokeballSendOutAnimation(0, POKEBALL_OPPONENT_SENDOUT);
}

static void RecordedOpponentHandleReturnMonToBall(void)
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
        RecordedOpponentBufferExecCompleted();
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
            gBattleBankFunc[gActiveBank] = sub_8186D9C;
        }
        break;
    }
}

static void RecordedOpponentHandleDrawTrainerPic(void)
{
    s16 xPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBankIdentity(gActiveBank) & BIT_MON) != 0) // second mon
            xPos = 152;
        else // first mon
            xPos = 200;

        if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
        {
            if (gActiveBank == 1)
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
            else
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = PlayerGenderToFrontTrainerPicId(GetActiveBankLinkPlayerGender());
        }
    }
    else
    {
        xPos = 176;
        if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
        {
            trainerPicId = sub_8068B48();
        }
        else
        {
            trainerPicId = PlayerGenderToFrontTrainerPicId(gLinkPlayers[gUnknown_0203C7B4 ^ BIT_SIDE].gender);
        }
    }

    DecompressTrainerFrontPic(trainerPicId, gActiveBank);
    sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               xPos,
                                               (8 - gTrainerFrontPicCoords[trainerPicId].coords) * 4 + 40,
                                               sub_80A82E4(gActiveBank));

    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -240;
    gSprites[gBankSpriteIds[gActiveBank]].data[0] = 2;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerFrontPicPaletteTable[trainerPicId].tag);
    gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam = trainerPicId;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy;
}

static void RecordedOpponentHandleTrainerSlide(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleTrainerSlideBack(void)
{
    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);
    gSprites[gBankSpriteIds[gActiveBank]].data[0] = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data[2] = 280;
    gSprites[gBankSpriteIds[gActiveBank]].data[4] = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], SpriteCallbackDummy);
    gBattleBankFunc[gActiveBank] = sub_81865C8;
}

static void RecordedOpponentHandleFaintAnimation(void)
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
            gBattleBankFunc[gActiveBank] = sub_8186D58;
        }
    }
}

static void RecordedOpponentHandlePaletteFade(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleSuccessBallThrowAnim(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleBallThrowAnim(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandlePause(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleMoveAnimation(void)
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
            RecordedOpponentBufferExecCompleted();
        }
        else
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            gBattleBankFunc[gActiveBank] = RecordedOpponentDoMoveAnimation;
        }
    }
}

static void RecordedOpponentDoMoveAnimation(void)
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
            RecordedOpponentBufferExecCompleted();
        }
        break;
    }
}

static void RecordedOpponentHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBank][2]);
    BufferStringBattle(*stringId);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 0);
    gBattleBankFunc[gActiveBank] = CompleteOnInactiveTextPrinter;
}

static void RecordedOpponentHandlePrintSelectionString(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleChooseAction(void)
{
    EmitTwoReturnValues(1, RecordedBattle_ReadBankAction(gActiveBank), 0);
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleUnknownYesNoBox(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleChooseMove(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        EmitTwoReturnValues(1, 10, ChooseMoveAndTargetInBattlePalace());
    }
    else
    {
        u8 moveId = RecordedBattle_ReadBankAction(gActiveBank);
        u8 target = RecordedBattle_ReadBankAction(gActiveBank);
        EmitTwoReturnValues(1, 10, moveId | (target << 8));
    }

    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleChooseItem(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleChoosePokemon(void)
{
    *(gBattleStruct->monToSwitchIntoId + gActiveBank) = RecordedBattle_ReadBankAction(gActiveBank);
    EmitChosenMonReturnValue(1, *(gBattleStruct->monToSwitchIntoId + gActiveBank), NULL);
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd23(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleHealthBarUpdate(void)
{
    s16 hpVal;

    LoadBattleBarGfx(0);
    hpVal = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

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

static void RecordedOpponentHandleExpUpdate(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleStatusIconUpdate(void)
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

static void RecordedOpponentHandleStatusAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        InitAndLaunchChosenStatusAnimation(gBattleBufferA[gActiveBank][1],
                        gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8) | (gBattleBufferA[gActiveBank][4] << 16) | (gBattleBufferA[gActiveBank][5] << 24));
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void RecordedOpponentHandleStatusXor(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleDataTransfer(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleDMA3Transfer(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandlePlayBGM(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd32(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleTwoReturnValues(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleChosenMonReturnValue(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleOneReturnValue(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleOneReturnValue_Duplicate(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd37(void)
{
    gUnknown_02022D0C.field_0 = 0;
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd38(void)
{
    gUnknown_02022D0C.field_0 = gBattleBufferA[gActiveBank][1];
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd39(void)
{
    gUnknown_02022D0C.flag_x80 = 0;
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd40(void)
{
    gUnknown_02022D0C.flag_x80 ^= 1;
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleHitAnimation(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].invisible == TRUE)
    {
        RecordedOpponentBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBankSpriteIds[gActiveBank]].data[1] = 0;
        DoHitAnimHealthboxEffect(gActiveBank);
        gBattleBankFunc[gActiveBank] = DoHitAnimBlinkSpriteEffect;
    }
}

static void RecordedOpponentHandleCmd42(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandlePlaySE(void)
{
    s8 pan;

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        pan = PAN_SIDE_PLAYER;
    else
        pan = PAN_SIDE_OPPONENT;

    PlaySE12WithPanning(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8), pan);
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandlePlayFanfareOrBGM(void)
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

    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleFaintingCry(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry3(species, 25, 5);
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;

    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);

    gSprites[gBankSpriteIds[gActiveBank]].data[0] = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data[2] = 280;
    gSprites[gBankSpriteIds[gActiveBank]].data[4] = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;

    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], sub_818962C);

    taskId = CreateTask(sub_8189548, 5);
    gTasks[taskId].data[0] = gActiveBank;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattleBankFunc[gActiveBank] = nullsub_70;
}

static void sub_8189548(u8 taskId)
{
    u8 savedActiveBank = gActiveBank;

    gActiveBank = gTasks[taskId].data[0];
    if (!IsDoubleBattle() || (gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_81885D8(gActiveBank, FALSE);
    }
    else
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_81885D8(gActiveBank, FALSE);
        gActiveBank ^= BIT_MON;
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_81885D8(gActiveBank, FALSE);
        gActiveBank ^= BIT_MON;
    }
    gBattleBankFunc[gActiveBank] = sub_818686C;
    gActiveBank = savedActiveBank;
    DestroyTask(taskId);
}

static void sub_818962C(struct Sprite *sprite)
{
    FreeTrainerFrontPicPalette(sprite->oam.affineParam);
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
}

static void RecordedOpponentHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBank][1] != 0 && GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        RecordedOpponentBufferExecCompleted();
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

        gBattleBankFunc[gActiveBank] = sub_818975C;
    }
}

static void sub_818975C(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5++ > 0x5C)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;
        RecordedOpponentBufferExecCompleted();
    }
}

static void RecordedOpponentHandleCmd49(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd50(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleSpriteInvisibility(void)
{
    if (IsBankSpritePresent(gActiveBank))
    {
        gSprites[gBankSpriteIds[gActiveBank]].invisible = gBattleBufferA[gActiveBank][1];
        CopyBattleSpriteInvisibility(gActiveBank);
    }
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleBattleAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 animationId = gBattleBufferA[gActiveBank][1];
        u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

        if (TryHandleLaunchBattleTableAnimation(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
            RecordedOpponentBufferExecCompleted();
        else
            gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;
    }
}

static void RecordedOpponentHandleLinkStandbyMsg(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleResetActionMoveSelection(void)
{
    RecordedOpponentBufferExecCompleted();
}

static void RecordedOpponentHandleCmd55(void)
{
    if (gBattleBufferA[gActiveBank][1] == BATTLE_DREW)
        gBattleOutcome = gBattleBufferA[gActiveBank][1];
    else
        gBattleOutcome = gBattleBufferA[gActiveBank][1] ^ BATTLE_DREW;

    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    RecordedOpponentBufferExecCompleted();
    gBattleBankFunc[gActiveBank] = sub_80587B0;
}

static void nullsub_119(void)
{
}
