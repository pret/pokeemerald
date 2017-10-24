#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_link_817C95C.h"
#include "pokemon.h"
#include "link.h"
#include "util.h"
#include "main.h"
#include "songs.h"
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
extern u16 gScriptItemId;
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

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const struct BattleMove gBattleMoves[];
extern const u8 gUnknown_0831F578[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);
extern void sub_81851A8(u8 *);
extern u16 sub_8068B48(void);

// this file's functions
static void LinkOpponentHandleGetMonData(void);
static void LinkOpponentHandleGetRawMonData(void);
static void LinkOpponentHandleSetMonData(void);
static void LinkOpponentHandleSetRawMonData(void);
static void LinkOpponentHandleLoadMonSprite(void);
static void LinkOpponentHandleSwitchInAnim(void);
static void LinkOpponentHandleReturnMonToBall(void);
static void LinkOpponentHandleDrawTrainerPic(void);
static void LinkOpponentHandleTrainerSlide(void);
static void LinkOpponentHandleTrainerSlideBack(void);
static void LinkOpponentHandleFaintAnimation(void);
static void LinkOpponentHandlePaletteFade(void);
static void LinkOpponentHandleSuccessBallThrowAnim(void);
static void LinkOpponentHandleBallThrowAnim(void);
static void LinkOpponentHandlePause(void);
static void LinkOpponentHandleMoveAnimation(void);
static void LinkOpponentHandlePrintString(void);
static void LinkOpponentHandlePrintStringPlayerOnly(void);
static void LinkOpponentHandleChooseAction(void);
static void LinkOpponentHandleUnknownYesNoBox(void);
static void LinkOpponentHandleChooseMove(void);
static void LinkOpponentHandleChooseItem(void);
static void LinkOpponentHandleChoosePokemon(void);
static void LinkOpponentHandleCmd23(void);
static void LinkOpponentHandleHealthBarUpdate(void);
static void LinkOpponentHandleExpUpdate(void);
static void LinkOpponentHandleStatusIconUpdate(void);
static void LinkOpponentHandleStatusAnimation(void);
static void LinkOpponentHandleStatusXor(void);
static void LinkOpponentHandleDataTransfer(void);
static void LinkOpponentHandleDMA3Transfer(void);
static void LinkOpponentHandlePlayBGM(void);
static void LinkOpponentHandleCmd32(void);
static void LinkOpponentHandleTwoReturnValues(void);
static void LinkOpponentHandleChosenMonReturnValue(void);
static void LinkOpponentHandleOneReturnValue(void);
static void LinkOpponentHandleOneReturnValue_Duplicate(void);
static void LinkOpponentHandleCmd37(void);
static void LinkOpponentHandleCmd38(void);
static void LinkOpponentHandleCmd39(void);
static void LinkOpponentHandleCmd40(void);
static void LinkOpponentHandleHitAnimation(void);
static void LinkOpponentHandleCmd42(void);
static void LinkOpponentHandleEffectivenessSound(void);
static void LinkOpponentHandlePlayFanfareOrBGM(void);
static void LinkOpponentHandleFaintingCry(void);
static void LinkOpponentHandleIntroSlide(void);
static void LinkOpponentHandleIntroTrainerBallThrow(void);
static void LinkOpponentHandleDrawPartyStatusSummary(void);
static void LinkOpponentHandleCmd49(void);
static void LinkOpponentHandleCmd50(void);
static void LinkOpponentHandleSpriteInvisibility(void);
static void LinkOpponentHandleBattleAnimation(void);
static void LinkOpponentHandleLinkStandbyMsg(void);
static void LinkOpponentHandleResetActionMoveSelection(void);
static void LinkOpponentHandleCmd55(void);
static void nullsub_92(void);

static void LinkOpponentBufferRunCommand(void);
static void LinkOpponentBufferExecCompleted(void);
static void sub_8064DD0(void);
static u32 CopyLinkOpponentMonData(u8 monId, u8 *dst);
static void SetLinkOpponentMonData(u8 monId);
static void sub_8066494(u8 bank, bool8 dontClearSubstituteBit);
static void DoSwitchOutAnimation(void);
static void LinkOpponentDoMoveAnimation(void);
static void sub_8067618(u8 taskId);
static void sub_80676FC(struct Sprite *sprite);
static void sub_806782C(void);

static void (*const gLinkOpponentBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
{
    LinkOpponentHandleGetMonData,
    LinkOpponentHandleGetRawMonData,
    LinkOpponentHandleSetMonData,
    LinkOpponentHandleSetRawMonData,
    LinkOpponentHandleLoadMonSprite,
    LinkOpponentHandleSwitchInAnim,
    LinkOpponentHandleReturnMonToBall,
    LinkOpponentHandleDrawTrainerPic,
    LinkOpponentHandleTrainerSlide,
    LinkOpponentHandleTrainerSlideBack,
    LinkOpponentHandleFaintAnimation,
    LinkOpponentHandlePaletteFade,
    LinkOpponentHandleSuccessBallThrowAnim,
    LinkOpponentHandleBallThrowAnim,
    LinkOpponentHandlePause,
    LinkOpponentHandleMoveAnimation,
    LinkOpponentHandlePrintString,
    LinkOpponentHandlePrintStringPlayerOnly,
    LinkOpponentHandleChooseAction,
    LinkOpponentHandleUnknownYesNoBox,
    LinkOpponentHandleChooseMove,
    LinkOpponentHandleChooseItem,
    LinkOpponentHandleChoosePokemon,
    LinkOpponentHandleCmd23,
    LinkOpponentHandleHealthBarUpdate,
    LinkOpponentHandleExpUpdate,
    LinkOpponentHandleStatusIconUpdate,
    LinkOpponentHandleStatusAnimation,
    LinkOpponentHandleStatusXor,
    LinkOpponentHandleDataTransfer,
    LinkOpponentHandleDMA3Transfer,
    LinkOpponentHandlePlayBGM,
    LinkOpponentHandleCmd32,
    LinkOpponentHandleTwoReturnValues,
    LinkOpponentHandleChosenMonReturnValue,
    LinkOpponentHandleOneReturnValue,
    LinkOpponentHandleOneReturnValue_Duplicate,
    LinkOpponentHandleCmd37,
    LinkOpponentHandleCmd38,
    LinkOpponentHandleCmd39,
    LinkOpponentHandleCmd40,
    LinkOpponentHandleHitAnimation,
    LinkOpponentHandleCmd42,
    LinkOpponentHandleEffectivenessSound,
    LinkOpponentHandlePlayFanfareOrBGM,
    LinkOpponentHandleFaintingCry,
    LinkOpponentHandleIntroSlide,
    LinkOpponentHandleIntroTrainerBallThrow,
    LinkOpponentHandleDrawPartyStatusSummary,
    LinkOpponentHandleCmd49,
    LinkOpponentHandleCmd50,
    LinkOpponentHandleSpriteInvisibility,
    LinkOpponentHandleBattleAnimation,
    LinkOpponentHandleLinkStandbyMsg,
    LinkOpponentHandleResetActionMoveSelection,
    LinkOpponentHandleCmd55,
    nullsub_92
};

static void nullsub_28(void)
{
}

void SetBankFuncToLinkOpponentBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = LinkOpponentBufferRunCommand;
}

static void LinkOpponentBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gLinkOpponentBufferCommands))
            gLinkOpponentBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            LinkOpponentBufferExecCompleted();
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        LinkOpponentBufferExecCompleted();
}

static void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        LinkOpponentBufferExecCompleted();
}

static void sub_8064470(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        FreeTrainerFrontPicPalette(gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        LinkOpponentBufferExecCompleted();
    }
}

static void sub_80644D8(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 0xFF)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
        LinkOpponentBufferExecCompleted();
    }
}

static void sub_8064520(void)
{
    bool32 r8 = FALSE;
    bool32 r4 = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
            r8 = TRUE;
    }
    else
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gHealthBoxesIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
        {
            r8 = TRUE;
        }
        r4 = TRUE;
    }

    if (r8)
    {
        if (r4 || !IsAnimBankSpriteVisible(gActiveBank ^ BIT_MON))
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
        else
        {
            if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
                return;

            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;

            if (GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON2)
            {
                FreeSpriteTilesByTag(0x27F9);
                FreeSpritePaletteByTag(0x27F9);
            }
        }

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 3;
        gBattleBankFunc[gActiveBank] = sub_80644D8;
    }
}

static void sub_8064734(void)
{
    bool32 r10 = FALSE;

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
    {
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI)
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1)
    {
        sub_8172EF0(gActiveBank ^ BIT_MON, &gEnemyParty[gBattlePartyID[gActiveBank ^ BIT_MON]]);
    }


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
                if (GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON1)
                    m4aMPlayContinue(&gMPlay_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            }
        }

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20 = 1;
        r10 = TRUE;
    }

    if (r10)
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && GetBankIdentity(gActiveBank) == IDENTITY_OPPONENT_MON2)
            {
                if (++gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 1)
                    return;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
            }

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

            gBattleBankFunc[gActiveBank] = sub_8064520;
        }
    }
}

static void sub_8064B04(void)
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
                LinkOpponentBufferExecCompleted();
            }
        }
    }
}

static void CompleteOnHealthbarDone(void)
{
    s16 hpValue = sub_8074AA0(gActiveBank, gHealthBoxesIds[gActiveBank], 0, 0);

    SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);

    if (hpValue != -1)
    {
        UpdateHpTextInHealthbox(gHealthBoxesIds[gActiveBank], hpValue, HP_CURRENT);
    }
    else
    {
        LinkOpponentBufferExecCompleted();
    }
}

static void sub_8064C14(void)
{
    if (!gSprites[gBankSpriteIds[gActiveBank]].inUse)
    {
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        LinkOpponentBufferExecCompleted();
    }
}

static void sub_8064C58(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        sub_805EEE0(gActiveBank);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        LinkOpponentBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        LinkOpponentBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBankSpriteIds[gActiveBank];

    if (gSprites[spriteId].data1 == 32)
    {
        gSprites[spriteId].data1 = 0;
        gSprites[spriteId].invisible = 0;
        gDoingBattleAnim = FALSE;
        LinkOpponentBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data1 % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data1++;
    }
}

static void sub_8064D60(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);

        gBattleBankFunc[gActiveBank] = sub_8064DD0;
    }
}

static void sub_8064DD0(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
            || gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy_2)
        {
            m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            LinkOpponentBufferExecCompleted();
        }
    }
}

static void sub_8064E50(void)
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
        SetBattleSpriteInvisibilityBitToSpriteInvisibility(gActiveBank);
        gBattleBankFunc[gActiveBank] = sub_8064D60;
    }
}

static void sub_8064F40(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80)
    {
        sub_8172EF0(gActiveBank, &gEnemyParty[gBattlePartyID[gActiveBank]]);
    }

    if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
    {
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));
        gBattleBankFunc[gActiveBank] = sub_8064E50;
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        LinkOpponentBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        LinkOpponentBufferExecCompleted();
}

static void LinkOpponentBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = LinkOpponentBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBank][0] = CONTOLLER_CMDS_COUNT - 1;
    }
    else
    {
        gBattleExecBuffer &= ~gBitTable[gActiveBank];
    }
}

static void LinkOpponentHandleGetMonData(void)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    u32 size = 0;
    u8 monsToCheck;
    s32 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        size += CopyLinkOpponentMonData(gBattlePartyID[gActiveBank], monData);
    }
    else
    {
        monsToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monsToCheck & 1)
                size += CopyLinkOpponentMonData(i, monData + size);
            monsToCheck >>= 1;
        }
    }
    EmitDataTransfer(1, size, monData);
    LinkOpponentBufferExecCompleted();
}

static u32 CopyLinkOpponentMonData(u8 monId, u8 *dst)
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

static void LinkOpponentHandleGetRawMonData(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleSetMonData(void)
{
    u8 monsToCheck;
    u8 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        SetLinkOpponentMonData(gBattlePartyID[gActiveBank]);
    }
    else
    {
        monsToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monsToCheck & 1)
                SetLinkOpponentMonData(i);
            monsToCheck >>= 1;
        }
    }
    LinkOpponentBufferExecCompleted();
}

static void SetLinkOpponentMonData(u8 monId)
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

static void LinkOpponentHandleSetRawMonData(void)
{
    u8 *dst = (u8 *)&gEnemyParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = gBattleBufferA[gActiveBank][3 + i];

    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleLoadMonSprite(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[gActiveBank]], gActiveBank);
    sub_806A068(species, GetBankIdentity(gActiveBank));

    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               sub_80A5C6C(gActiveBank, 2),
                                               sub_80A6138(gActiveBank),
                                               sub_80A82E4(gActiveBank));



    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], gBattleMonForms[gActiveBank]);

    SetBankEnemyShadowSpriteCallback(gActiveBank, GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES));

    gBattleBankFunc[gActiveBank] = sub_8064B04;
}

static void LinkOpponentHandleSwitchInAnim(void)
{
    gBattlePartyID[gActiveBank] = gBattleBufferA[gActiveBank][1];
    sub_8066494(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattleBankFunc[gActiveBank] = sub_8064F40;
}

static void sub_8066494(u8 bank, bool8 dontClearSubstituteBit)
{
    u16 species;

    ClearTemporarySpeciesSpriteData(bank, dontClearSubstituteBit);
    gBattlePartyID[bank] = gBattleBufferA[bank][1];
    species = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES);
    gUnknown_03005D7C[bank] = CreateInvisibleSpriteWithCallback(sub_805D714);
    BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[bank]], bank);
    sub_806A068(species, GetBankIdentity(bank));

    gBankSpriteIds[bank] = CreateSprite(
      &gUnknown_0202499C,
      sub_80A5C6C(bank, 2),
      sub_80A6138(bank),
      sub_80A82E4(bank));

    gSprites[gUnknown_03005D7C[bank]].data1 = gBankSpriteIds[bank];
    gSprites[gUnknown_03005D7C[bank]].data2 = bank;

    gSprites[gBankSpriteIds[bank]].data0 = bank;
    gSprites[gBankSpriteIds[bank]].data2 = species;
    gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;

    StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], gBattleMonForms[bank]);

    gSprites[gBankSpriteIds[bank]].invisible = TRUE;
    gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;

    gSprites[gUnknown_03005D7C[bank]].data0 = sub_80753E8(0, 0xFE);
}

static void LinkOpponentHandleReturnMonToBall(void)
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
        sub_805EEE0(gActiveBank);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        LinkOpponentBufferExecCompleted();
    }
}

static void DoSwitchOutAnimation(void)
{
    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SWITCH_OUT_OPPONENT_MON);
            gBattleBankFunc[gActiveBank] = sub_8064C58;
        }
        break;
    }
}

// todo: get rid of it once the struct is declared in a header
struct MonCoords
{
    // This would use a bitfield, but sub_8079F44
    // uses it as a u8 and casting won't match.
    u8 coords; // u8 x:4, y:4;
    u8 y_offset;
};
extern const struct MonCoords gTrainerFrontPicCoords[];

static void LinkOpponentHandleDrawTrainerPic(void)
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
            if ((gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_FIRE_RED
            || (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_LEAF_GREEN)
            {
                if (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender != 0)
                    trainerPicId = gUnknown_0831F578[0x4F];
                else
                    trainerPicId = gUnknown_0831F578[0x4E];
            }
            else if ((gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_RUBY
                     || (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender != 0)
                    trainerPicId = gUnknown_0831F578[0x51];
                else
                    trainerPicId = gUnknown_0831F578[0x50];
            }
            else
            {
                trainerPicId = PlayerGenderToFrontTrainerPicId(gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender);
            }
        }
    }
    else
    {
        xPos = 176;
        if (gTrainerBattleOpponent_A == TRAINER_OPPONENT_C00)
        {
            trainerPicId = sub_8068B48();
        }
        else if ((gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_FIRE_RED
                 || (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_LEAF_GREEN)
        {
            if (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].gender != 0)
                trainerPicId = gUnknown_0831F578[0x4F];
            else
                trainerPicId = gUnknown_0831F578[0x4E];
        }
        else if ((gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_RUBY
                 || (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_SAPPHIRE)
        {
            if (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].gender != 0)
                trainerPicId = gUnknown_0831F578[0x51];
            else
                trainerPicId = gUnknown_0831F578[0x50];
        }
        else
        {
            trainerPicId = PlayerGenderToFrontTrainerPicId(gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].gender);
        }
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

static void LinkOpponentHandleTrainerSlide(void)
{
    u32 trainerPicId;

    if (gActiveBank == 1)
        trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
    else
        trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);

    DecompressTrainerFrontPic(trainerPicId, gActiveBank);
    sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C, 176, (8 - gTrainerFrontPicCoords[trainerPicId].coords) * 4 + 40, 0x1E);

    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 96;
    gSprites[gBankSpriteIds[gActiveBank]].pos1.x += 32;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerFrontPicPaletteTable[trainerPicId].tag);
    gSprites[gBankSpriteIds[gActiveBank]].oam.affineParam = trainerPicId;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy2; // this line is redundant, because LinkOpponentBufferExecCompleted changes the battle bank function
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleTrainerSlideBack(void)
{
    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = 280;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], SpriteCallbackDummy);
    gBattleBankFunc[gActiveBank] = sub_8064470;
}

static void LinkOpponentHandleFaintAnimation(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState == 0)
    {
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState++;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            PlaySE12WithPanning(SE_POKE_DEAD, PAN_SIDE_OPPONENT);
            gSprites[gBankSpriteIds[gActiveBank]].callback = sub_8039934;
            gBattleBankFunc[gActiveBank] = sub_8064C14;
        }
    }
}

static void LinkOpponentHandlePaletteFade(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleSuccessBallThrowAnim(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleBallThrowAnim(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandlePause(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleMoveAnimation(void)
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
            LinkOpponentBufferExecCompleted();
        }
        else
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            gBattleBankFunc[gActiveBank] = LinkOpponentDoMoveAnimation;
            sub_817E0FC(move, gWeatherMoveAnim, gAnimDisableStructPtr);
        }
    }
}

static void LinkOpponentDoMoveAnimation(void)
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
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
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
                DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);
                gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8 = 0;
            }
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            sub_805E394();
            TrySetBehindSubstituteSpriteBit(gActiveBank, gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            LinkOpponentBufferExecCompleted();
        }
        break;
    }
}

static void LinkOpponentHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBank][2]);
    BufferStringBattle(*stringId);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 0);
    gBattleBankFunc[gActiveBank] = CompleteOnInactiveTextPrinter;
    sub_817C95C(*stringId);
}

static void LinkOpponentHandlePrintStringPlayerOnly(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleChooseAction(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleUnknownYesNoBox(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleChooseMove(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleChooseItem(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleChoosePokemon(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd23(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleHealthBarUpdate(void)
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

static void LinkOpponentHandleExpUpdate(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleStatusIconUpdate(void)
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

static void LinkOpponentHandleStatusAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        DoStatusAnimation(gBattleBufferA[gActiveBank][1],
                        gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8) | (gBattleBufferA[gActiveBank][4] << 16) | (gBattleBufferA[gActiveBank][5] << 24));
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void LinkOpponentHandleStatusXor(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleDataTransfer(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleDMA3Transfer(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandlePlayBGM(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd32(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleTwoReturnValues(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleChosenMonReturnValue(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleOneReturnValue(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleOneReturnValue_Duplicate(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd37(void)
{
    gUnknown_02022D0C.field_0 = 0;
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd38(void)
{
    gUnknown_02022D0C.field_0 = gBattleBufferA[gActiveBank][1];
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd39(void)
{
    gUnknown_02022D0C.flag_x80 = 0;
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd40(void)
{
    gUnknown_02022D0C.flag_x80 ^= 1;
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleHitAnimation(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].invisible == TRUE)
    {
        LinkOpponentBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
        DoHitAnimHealthboxEffect(gActiveBank);
        gBattleBankFunc[gActiveBank] = DoHitAnimBlinkSpriteEffect;
    }
}

static void LinkOpponentHandleCmd42(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleEffectivenessSound(void)
{
    s8 pan;

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        pan = PAN_SIDE_PLAYER;
    else
        pan = PAN_SIDE_OPPONENT;

    PlaySE12WithPanning(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8), pan);
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBank][3])
    {
        BattleMusicStop();
        PlayBGM(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }

    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleFaintingCry(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry3(species, 25, 5);
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;

    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);

    gSprites[gBankSpriteIds[gActiveBank]].data0 = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = 280;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;

    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], sub_80676FC);

    taskId = CreateTask(sub_8067618, 5);
    gTasks[taskId].data[0] = gActiveBank;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattleBankFunc[gActiveBank] = nullsub_28;
}

static void sub_8067618(u8 taskId)
{
    u8 savedActiveBank = gActiveBank;

    gActiveBank = gTasks[taskId].data[0];
    if (!IsDoubleBattle() || (gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_8066494(gActiveBank, FALSE);
    }
    else
    {
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_8066494(gActiveBank, FALSE);
        gActiveBank ^= BIT_MON;
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_8066494(gActiveBank, FALSE);
        gActiveBank ^= BIT_MON;
    }
    gBattleBankFunc[gActiveBank] = sub_8064734;
    gActiveBank = savedActiveBank;
    DestroyTask(taskId);
}

static void sub_80676FC(struct Sprite *sprite)
{
    FreeTrainerFrontPicPalette(sprite->oam.affineParam);
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
}

static void LinkOpponentHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBank][1] != 0 && GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        LinkOpponentBufferExecCompleted();
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

        gBattleBankFunc[gActiveBank] = sub_806782C;
    }
}

static void sub_806782C(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5++ > 0x5C)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;
        LinkOpponentBufferExecCompleted();
    }
}

static void LinkOpponentHandleCmd49(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd50(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleSpriteInvisibility(void)
{
    if (AnimBankSpriteExists(gActiveBank))
    {
        gSprites[gBankSpriteIds[gActiveBank]].invisible = gBattleBufferA[gActiveBank][1];
        SetBattleSpriteInvisibilityBitToSpriteInvisibility(gActiveBank);
    }
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleBattleAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 animationId = gBattleBufferA[gActiveBank][1];
        u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

        if (DoBattleAnimationFromTable(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
            LinkOpponentBufferExecCompleted();
        else
            gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;

        sub_817E32C(animationId);
    }
}

static void LinkOpponentHandleLinkStandbyMsg(void)
{
    sub_81851A8(&gBattleBufferA[gActiveBank][2]);
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleResetActionMoveSelection(void)
{
    LinkOpponentBufferExecCompleted();
}

static void LinkOpponentHandleCmd55(void)
{
    sub_81851A8(&gBattleBufferA[gActiveBank][4]);

    if (gBattleBufferA[gActiveBank][1] == BATTLE_DREW)
        gBattleOutcome = gBattleBufferA[gActiveBank][1];
    else
        gBattleOutcome = gBattleBufferA[gActiveBank][1] ^ BATTLE_DREW;

    gSaveBlock2Ptr->field_CA9_b = gBattleBufferA[gActiveBank][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    LinkOpponentBufferExecCompleted();
    gBattleBankFunc[gActiveBank] = sub_80587B0;
}

static void nullsub_92(void)
{
}
