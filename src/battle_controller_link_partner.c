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
extern struct UnusedControllerStruct gUnknown_02022D0C;

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const struct BattleMove gBattleMoves[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);
extern void sub_81851A8(u8 *);

// this file's functions
static void LinkPartnerHandleGetMonData(void);
static void LinkPartnerHandleGetRawMonData(void);
static void LinkPartnerHandleSetMonData(void);
static void LinkPartnerHandleSetRawMonData(void);
static void LinkPartnerHandleLoadMonSprite(void);
static void LinkPartnerHandleSwitchInAnim(void);
static void LinkPartnerHandleReturnMonToBall(void);
static void LinkPartnerHandleDrawTrainerPic(void);
static void LinkPartnerHandleTrainerSlide(void);
static void LinkPartnerHandleTrainerSlideBack(void);
static void LinkPartnerHandleFaintAnimation(void);
static void LinkPartnerHandlePaletteFade(void);
static void LinkPartnerHandleSuccessBallThrowAnim(void);
static void LinkPartnerHandleBallThrowAnim(void);
static void LinkPartnerHandlePause(void);
static void LinkPartnerHandleMoveAnimation(void);
static void LinkPartnerHandlePrintString(void);
static void LinkPartnerHandlePrintStringPlayerOnly(void);
static void LinkPartnerHandleChooseAction(void);
static void LinkPartnerHandleUnknownYesNoBox(void);
static void LinkPartnerHandleChooseMove(void);
static void LinkPartnerHandleChooseItem(void);
static void LinkPartnerHandleChoosePokemon(void);
static void LinkPartnerHandleCmd23(void);
static void LinkPartnerHandleHealthBarUpdate(void);
static void LinkPartnerHandleExpUpdate(void);
static void LinkPartnerHandleStatusIconUpdate(void);
static void LinkPartnerHandleStatusAnimation(void);
static void LinkPartnerHandleStatusXor(void);
static void LinkPartnerHandleDataTransfer(void);
static void LinkPartnerHandleDMA3Transfer(void);
static void LinkPartnerHandlePlayBGM(void);
static void LinkPartnerHandleCmd32(void);
static void LinkPartnerHandleTwoReturnValues(void);
static void LinkPartnerHandleChosenMonReturnValue(void);
static void LinkPartnerHandleOneReturnValue(void);
static void LinkPartnerHandleOneReturnValue_Duplicate(void);
static void LinkPartnerHandleCmd37(void);
static void LinkPartnerHandleCmd38(void);
static void LinkPartnerHandleCmd39(void);
static void LinkPartnerHandleCmd40(void);
static void LinkPartnerHandleHitAnimation(void);
static void LinkPartnerHandleCmd42(void);
static void LinkPartnerHandleEffectivenessSound(void);
static void LinkPartnerHandlePlayFanfareOrBGM(void);
static void LinkPartnerHandleFaintingCry(void);
static void LinkPartnerHandleIntroSlide(void);
static void LinkPartnerHandleIntroTrainerBallThrow(void);
static void LinkPartnerHandleDrawPartyStatusSummary(void);
static void LinkPartnerHandleCmd49(void);
static void LinkPartnerHandleCmd50(void);
static void LinkPartnerHandleSpriteInvisibility(void);
static void LinkPartnerHandleBattleAnimation(void);
static void LinkPartnerHandleLinkStandbyMsg(void);
static void LinkPartnerHandleResetActionMoveSelection(void);
static void LinkPartnerHandleCmd55(void);
static void nullsub_113(void);

static void LinkPartnerBufferRunCommand(void);
static void LinkPartnerBufferExecCompleted(void);
static void sub_814B554(void);
static u32 CopyLinkPartnerMonData(u8 monId, u8 *dst);
static void SetLinkPartnerMonData(u8 monId);
static void sub_814CC98(u8 bank, bool8 dontClearSubstituteBit);
static void DoSwitchOutAnimation(void);
static void LinkPartnerDoMoveAnimation(void);
static void sub_814DCCC(u8 taskId);
static void sub_814DE9C(void);

static void (*const gLinkPartnerBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
{
    LinkPartnerHandleGetMonData,
    LinkPartnerHandleGetRawMonData,
    LinkPartnerHandleSetMonData,
    LinkPartnerHandleSetRawMonData,
    LinkPartnerHandleLoadMonSprite,
    LinkPartnerHandleSwitchInAnim,
    LinkPartnerHandleReturnMonToBall,
    LinkPartnerHandleDrawTrainerPic,
    LinkPartnerHandleTrainerSlide,
    LinkPartnerHandleTrainerSlideBack,
    LinkPartnerHandleFaintAnimation,
    LinkPartnerHandlePaletteFade,
    LinkPartnerHandleSuccessBallThrowAnim,
    LinkPartnerHandleBallThrowAnim,
    LinkPartnerHandlePause,
    LinkPartnerHandleMoveAnimation,
    LinkPartnerHandlePrintString,
    LinkPartnerHandlePrintStringPlayerOnly,
    LinkPartnerHandleChooseAction,
    LinkPartnerHandleUnknownYesNoBox,
    LinkPartnerHandleChooseMove,
    LinkPartnerHandleChooseItem,
    LinkPartnerHandleChoosePokemon,
    LinkPartnerHandleCmd23,
    LinkPartnerHandleHealthBarUpdate,
    LinkPartnerHandleExpUpdate,
    LinkPartnerHandleStatusIconUpdate,
    LinkPartnerHandleStatusAnimation,
    LinkPartnerHandleStatusXor,
    LinkPartnerHandleDataTransfer,
    LinkPartnerHandleDMA3Transfer,
    LinkPartnerHandlePlayBGM,
    LinkPartnerHandleCmd32,
    LinkPartnerHandleTwoReturnValues,
    LinkPartnerHandleChosenMonReturnValue,
    LinkPartnerHandleOneReturnValue,
    LinkPartnerHandleOneReturnValue_Duplicate,
    LinkPartnerHandleCmd37,
    LinkPartnerHandleCmd38,
    LinkPartnerHandleCmd39,
    LinkPartnerHandleCmd40,
    LinkPartnerHandleHitAnimation,
    LinkPartnerHandleCmd42,
    LinkPartnerHandleEffectivenessSound,
    LinkPartnerHandlePlayFanfareOrBGM,
    LinkPartnerHandleFaintingCry,
    LinkPartnerHandleIntroSlide,
    LinkPartnerHandleIntroTrainerBallThrow,
    LinkPartnerHandleDrawPartyStatusSummary,
    LinkPartnerHandleCmd49,
    LinkPartnerHandleCmd50,
    LinkPartnerHandleSpriteInvisibility,
    LinkPartnerHandleBattleAnimation,
    LinkPartnerHandleLinkStandbyMsg,
    LinkPartnerHandleResetActionMoveSelection,
    LinkPartnerHandleCmd55,
    nullsub_113
};

static void nullsub_112(void)
{
}

void SetBankFuncToLinkPartnerBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = LinkPartnerBufferRunCommand;
}

static void LinkPartnerBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gLinkPartnerBufferCommands))
            gLinkPartnerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            LinkPartnerBufferExecCompleted();
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        LinkPartnerBufferExecCompleted();
}

static void sub_814AF54(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        nullsub_25(0);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        LinkPartnerBufferExecCompleted();
    }
}

static void sub_814AFBC(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 0xFF)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
        LinkPartnerBufferExecCompleted();
    }
}

static void sub_814B004(void)
{
    bool32 r6 = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
            r6 = TRUE;
    }
    else
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gHealthBoxesIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
        {
            r6 = TRUE;
        }
    }

    if (IsCryPlayingOrClearCrySongs())
        r6 = FALSE;

    if (r6)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 3;
        gBattleBankFunc[gActiveBank] = sub_814AFBC;
    }
}

static void sub_814B0E8(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8
        && gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
        && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
        && ++gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 != 1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;

        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]]);
            UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank ^ BIT_MON], &gPlayerParty[gBattlePartyID[gActiveBank ^ BIT_MON]], HEALTHBOX_ALL);
            sub_8076918(gActiveBank ^ BIT_MON);
            SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank ^ BIT_MON]);
        }

        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
        sub_8076918(gActiveBank);
        SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);

        gBattleSpritesDataPtr->animationData->field_9_x1 = 0;

        gBattleBankFunc[gActiveBank] = sub_814B004;
    }
}

static void sub_814B290(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].animEnded && gSprites[gBankSpriteIds[gActiveBank]].pos2.x == 0)
        LinkPartnerBufferExecCompleted();
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
        sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
        LinkPartnerBufferExecCompleted();
    }
}

static void sub_814B340(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].pos1.y + gSprites[gBankSpriteIds[gActiveBank]].pos2.y > DISPLAY_HEIGHT)
    {
        u16 species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

        nullsub_24(species);
        FreeOamMatrix(gSprites[gBankSpriteIds[gActiveBank]].oam.matrixNum);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        LinkPartnerBufferExecCompleted();
    }
}

static void sub_814B3DC(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        LinkPartnerBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        LinkPartnerBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBankSpriteIds[gActiveBank];

    if (gSprites[spriteId].data1 == 32)
    {
        gSprites[spriteId].data1 = 0;
        gSprites[spriteId].invisible = 0;
        gDoingBattleAnim = FALSE;
        LinkPartnerBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data1 % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data1++;
    }
}

static void sub_814B4E0(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        SetBattleSpriteInvisibilityBitToSpriteInvisibility(gActiveBank);
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);

        gBattleBankFunc[gActiveBank] = sub_814B554;
    }
}

static void sub_814B554(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive
        && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        LinkPartnerBufferExecCompleted();
    }
}

static void sub_814B5A8(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;

        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);

        CreateTask(c3_0802FDF4, 10);
        sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
        StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], 0);
        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
        sub_8076918(gActiveBank);
        SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);

        gBattleBankFunc[gActiveBank] = sub_814B4E0;
    }
}

static void sub_814B69C(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
    {
        sub_8172EF0(gActiveBank, &gPlayerParty[gBattlePartyID[gActiveBank]]);
    }

    if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
    {
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        gBattleBankFunc[gActiveBank] = sub_814B5A8;
    }
}

static void LinkPartnerBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = LinkPartnerBufferRunCommand;
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

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        LinkPartnerBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleGetMonData(void)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    u32 size = 0;
    u8 monsToCheck;
    s32 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        size += CopyLinkPartnerMonData(gBattlePartyID[gActiveBank], monData);
    }
    else
    {
        monsToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monsToCheck & 1)
                size += CopyLinkPartnerMonData(i, monData + size);
            monsToCheck >>= 1;
        }
    }
    EmitDataTransfer(1, size, monData);
    LinkPartnerBufferExecCompleted();
}

static u32 CopyLinkPartnerMonData(u8 monId, u8 *dst)
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
        battleMon.species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        battleMon.item = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
        for (size = 0; size < 4; size++)
        {
            battleMon.moves[size] = GetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + size);
            battleMon.pp[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + size);
        }
        battleMon.ppBonuses = GetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES);
        battleMon.friendship = GetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP);
        battleMon.experience = GetMonData(&gPlayerParty[monId], MON_DATA_EXP);
        battleMon.hpIV = GetMonData(&gPlayerParty[monId], MON_DATA_HP_IV);
        battleMon.attackIV = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV);
        battleMon.defenseIV = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV);
        battleMon.speedIV = GetMonData(&gPlayerParty[monId], MON_DATA_SPD_IV);
        battleMon.spAttackIV = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV);
        battleMon.spDefenseIV = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV);
        battleMon.personality = GetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY);
        battleMon.status1 = GetMonData(&gPlayerParty[monId], MON_DATA_STATUS);
        battleMon.level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
        battleMon.hp = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
        battleMon.maxHP = GetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP);
        battleMon.attack = GetMonData(&gPlayerParty[monId], MON_DATA_ATK);
        battleMon.defense = GetMonData(&gPlayerParty[monId], MON_DATA_DEF);
        battleMon.speed = GetMonData(&gPlayerParty[monId], MON_DATA_SPD);
        battleMon.spAttack = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK);
        battleMon.spDefense = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF);
        battleMon.isEgg = GetMonData(&gPlayerParty[monId], MON_DATA_IS_EGG);
        battleMon.altAbility = GetMonData(&gPlayerParty[monId], MON_DATA_ALT_ABILITY);
        battleMon.otId = GetMonData(&gPlayerParty[monId], MON_DATA_OT_ID);
        GetMonData(&gPlayerParty[monId], MON_DATA_NICKNAME, nickname);
        StringCopy10(battleMon.nickname, nickname);
        GetMonData(&gPlayerParty[monId], MON_DATA_OT_NAME, battleMon.otName);
        src = (u8 *)&battleMon;
        for (size = 0; size < sizeof(battleMon); size++)
            dst[size] = src[size];
        break;
    case REQUEST_SPECIES_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_HELDITEM_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (size = 0; size < 4; size++)
        {
            moveData.moves[size] = GetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + size);
            moveData.pp[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + size);
        }
        moveData.ppBonuses = GetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES);
        src = (u8*)(&moveData);
        for (size = 0; size < sizeof(moveData); size++)
            dst[size] = src[size];
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + gBattleBufferA[gActiveBank][1] - REQUEST_MOVE1_BATTLE);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_PP_DATA_BATTLE:
        for (size = 0; size < 4; size++)
            dst[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + size);
        dst[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES);
        size++;
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + gBattleBufferA[gActiveBank][1] - REQUEST_PPMOVE1_BATTLE);
        size = 1;
        break;
    case REQUEST_OTID_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_OT_ID);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_EXP_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_EXP);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_HP_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_HP_EV);
        size = 1;
        break;
    case REQUEST_ATK_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_EV);
        size = 1;
        break;
    case REQUEST_DEF_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_EV);
        size = 1;
        break;
    case REQUEST_SPEED_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPD_EV);
        size = 1;
        break;
    case REQUEST_SPATK_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_EV);
        size = 1;
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_EV);
        size = 1;
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP);
        size = 1;
        break;
    case REQUEST_POKERUS_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_POKERUS);
        size = 1;
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_MET_LOCATION);
        size = 1;
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_MET_LEVEL);
        size = 1;
        break;
    case REQUEST_MET_GAME_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_MET_GAME);
        size = 1;
        break;
    case REQUEST_POKEBALL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_POKEBALL);
        size = 1;
        break;
    case REQUEST_ALL_IVS_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_HP_IV);
        dst[1] = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV);
        dst[2] = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV);
        dst[3] = GetMonData(&gPlayerParty[monId], MON_DATA_SPD_IV);
        dst[4] = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV);
        dst[5] = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV);
        size = 6;
        break;
    case REQUEST_HP_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_HP_IV);
        size = 1;
        break;
    case REQUEST_ATK_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV);
        size = 1;
        break;
    case REQUEST_DEF_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV);
        size = 1;
        break;
    case REQUEST_SPEED_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPD_IV);
        size = 1;
        break;
    case REQUEST_SPATK_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV);
        size = 1;
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV);
        size = 1;
        break;
    case REQUEST_PERSONALITY_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_CHECKSUM_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_CHECKSUM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_STATUS_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_STATUS);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_LEVEL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
        size = 1;
        break;
    case REQUEST_HP_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MAX_HP_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_ATK_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_ATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_DEF_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_DEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPEED_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPD);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPATK_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPDEF_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_COOL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_COOL);
        size = 1;
        break;
    case REQUEST_BEAUTY_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY);
        size = 1;
        break;
    case REQUEST_CUTE_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_CUTE);
        size = 1;
        break;
    case REQUEST_SMART_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SMART);
        size = 1;
        break;
    case REQUEST_TOUGH_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_TOUGH);
        size = 1;
        break;
    case REQUEST_SHEEN_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SHEEN);
        size = 1;
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_COOL_RIBBON);
        size = 1;
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY_RIBBON);
        size = 1;
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_CUTE_RIBBON);
        size = 1;
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SMART_RIBBON);
        size = 1;
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_TOUGH_RIBBON);
        size = 1;
        break;
    }

    return size;
}

static void LinkPartnerHandleGetRawMonData(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSetMonData(void)
{
    u8 monsToCheck;
    u8 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        SetLinkPartnerMonData(gBattlePartyID[gActiveBank]);
    }
    else
    {
        monsToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monsToCheck & 1)
                SetLinkPartnerMonData(i);
            monsToCheck >>= 1;
        }
    }
    LinkPartnerBufferExecCompleted();
}

static void SetLinkPartnerMonData(u8 monId)
{
    struct BattlePokemon *battlePokemon = (struct BattlePokemon *)&gBattleBufferA[gActiveBank][3];
    struct MovePpInfo *moveData = (struct MovePpInfo *)&gBattleBufferA[gActiveBank][3];
    s32 i;

    switch (gBattleBufferA[gActiveBank][1])
    {
    case REQUEST_ALL_BATTLE:
        {
            u8 iv;

            SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &battlePokemon->species);
            SetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM, &battlePokemon->item);
            for (i = 0; i < 4; i++)
            {
                SetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + i, &battlePokemon->moves[i]);
                SetMonData(&gPlayerParty[monId], MON_DATA_PP1 + i, &battlePokemon->pp[i]);
            }
            SetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES, &battlePokemon->ppBonuses);
            SetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP, &battlePokemon->friendship);
            SetMonData(&gPlayerParty[monId], MON_DATA_EXP, &battlePokemon->experience);
            iv = battlePokemon->hpIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_HP_IV, &iv);
            iv = battlePokemon->attackIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV, &iv);
            iv = battlePokemon->defenseIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV, &iv);
            iv = battlePokemon->speedIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_SPD_IV, &iv);
            iv = battlePokemon->spAttackIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV, &iv);
            iv = battlePokemon->spDefenseIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV, &iv);
            SetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY, &battlePokemon->personality);
            SetMonData(&gPlayerParty[monId], MON_DATA_STATUS, &battlePokemon->status1);
            SetMonData(&gPlayerParty[monId], MON_DATA_LEVEL, &battlePokemon->level);
            SetMonData(&gPlayerParty[monId], MON_DATA_HP, &battlePokemon->hp);
            SetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP, &battlePokemon->maxHP);
            SetMonData(&gPlayerParty[monId], MON_DATA_ATK, &battlePokemon->attack);
            SetMonData(&gPlayerParty[monId], MON_DATA_DEF, &battlePokemon->defense);
            SetMonData(&gPlayerParty[monId], MON_DATA_SPD, &battlePokemon->speed);
            SetMonData(&gPlayerParty[monId], MON_DATA_SPATK, &battlePokemon->spAttack);
            SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF, &battlePokemon->spDefense);
        }
        break;
    case REQUEST_SPECIES_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HELDITEM_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (i = 0; i < 4; i++)
        {
            SetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + i, &moveData->moves[i]);
            SetMonData(&gPlayerParty[monId], MON_DATA_PP1 + i, &moveData->pp[i]);
        }
        SetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES, &moveData->ppBonuses);
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + gBattleBufferA[gActiveBank][1] - REQUEST_MOVE1_BATTLE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_PP_DATA_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_PP1, &gBattleBufferA[gActiveBank][3]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP2, &gBattleBufferA[gActiveBank][4]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP3, &gBattleBufferA[gActiveBank][5]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP4, &gBattleBufferA[gActiveBank][6]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES, &gBattleBufferA[gActiveBank][7]);
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_PP1 + gBattleBufferA[gActiveBank][1] - REQUEST_PPMOVE1_BATTLE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_OTID_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_OT_ID, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_EXP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_EXP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HP_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPD_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_POKERUS_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_POKERUS, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MET_LOCATION, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MET_LEVEL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_GAME_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MET_GAME, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_POKEBALL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_POKEBALL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ALL_IVS_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP_IV, &gBattleBufferA[gActiveBank][3]);
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV, &gBattleBufferA[gActiveBank][4]);
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV, &gBattleBufferA[gActiveBank][5]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPD_IV, &gBattleBufferA[gActiveBank][6]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV, &gBattleBufferA[gActiveBank][7]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV, &gBattleBufferA[gActiveBank][8]);
        break;
    case REQUEST_HP_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPD_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_PERSONALITY_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CHECKSUM_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_CHECKSUM, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_STATUS_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_STATUS, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_LEVEL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_LEVEL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MAX_HP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPD, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_COOL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_COOL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_BEAUTY_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CUTE_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_CUTE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SMART_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SMART, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_TOUGH_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_TOUGH, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SHEEN_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SHEEN, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_COOL_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_CUTE_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SMART_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_TOUGH_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    }

    sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
}

static void LinkPartnerHandleSetRawMonData(void)
{
    u8 *dst = (u8 *)&gPlayerParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = gBattleBufferA[gActiveBank][3 + i];

    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleLoadMonSprite(void)
{
    u16 species;

    BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
    species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);
    sub_806A068(species, GetBankIdentity(gActiveBank));

    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               sub_80A5C6C(gActiveBank, 2),
                                               sub_80A6138(gActiveBank),
                                               sub_80A82E4(gActiveBank));
    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], gBattleMonForms[gActiveBank]);
    gBattleBankFunc[gActiveBank] = sub_814B290;
}

static void LinkPartnerHandleSwitchInAnim(void)
{
    ClearTemporarySpeciesSpriteData(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattlePartyID[gActiveBank] = gBattleBufferA[gActiveBank][1];
    BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
    sub_814CC98(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattleBankFunc[gActiveBank] = sub_814B69C;
}

static void sub_814CC98(u8 bank, bool8 dontClearSubstituteBit)
{
    u16 species;

    ClearTemporarySpeciesSpriteData(bank, dontClearSubstituteBit);
    gBattlePartyID[bank] = gBattleBufferA[bank][1];
    species = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES);
    gUnknown_03005D7C[bank] = CreateInvisibleSpriteWithCallback(sub_805D714);
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

    gSprites[gUnknown_03005D7C[bank]].data0 = sub_80753E8(0, 0xFF);
}

static void LinkPartnerHandleReturnMonToBall(void)
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
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        LinkPartnerBufferExecCompleted();
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
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SWITCH_OUT_PLAYER_MON);
            gBattleBankFunc[gActiveBank] = sub_814B3DC;
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
extern const struct MonCoords gTrainerBackPicCoords[];
extern const struct MonCoords gTrainerFrontPicCoords[];

static void LinkPartnerHandleDrawTrainerPic(void)
{
    s16 xPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBankIdentity(gActiveBank) & BIT_MON) != 0) // second mon
            xPos = 90;
        else // first mon
            xPos = 32;
    }
    else
    {
        xPos = 80;
    }

    if ((gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_FIRE_RED
        || (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_LEAF_GREEN)
    {
        trainerPicId = gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender + BACK_PIC_RED;
    }
    else if ((gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_RUBY
             || (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_SAPPHIRE)
    {
        trainerPicId = gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender + BACK_PIC_RS_BRENDAN;
    }
    else
    {
        trainerPicId = gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender;
    }

    DecompressTrainerBackPic(trainerPicId, gActiveBank);
    sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C, xPos, (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80, sub_80A82E4(gActiveBank));

    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy;
}

static void LinkPartnerHandleTrainerSlide(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleTrainerSlideBack(void)
{
    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 35;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = -40;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], SpriteCallbackDummy);
    gBattleBankFunc[gActiveBank] = sub_814AF54;
}

static void LinkPartnerHandleFaintAnimation(void)
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
            sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
            PlaySE12WithPanning(SE_POKE_DEAD, PAN_SIDE_PLAYER);
            gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
            gSprites[gBankSpriteIds[gActiveBank]].data2 = 5;
            gSprites[gBankSpriteIds[gActiveBank]].callback = sub_8039C00;
            gBattleBankFunc[gActiveBank] = sub_814B340;
        }
    }
}

static void LinkPartnerHandlePaletteFade(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSuccessBallThrowAnim(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleBallThrowAnim(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePause(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleMoveAnimation(void)
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
            LinkPartnerBufferExecCompleted();
        }
        else
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            gBattleBankFunc[gActiveBank] = LinkPartnerDoMoveAnimation;
            sub_817E0FC(move, gWeatherMoveAnim, gAnimDisableStructPtr);
        }
    }
}

static void LinkPartnerDoMoveAnimation(void)
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
            LinkPartnerBufferExecCompleted();
        }
        break;
    }
}

static void LinkPartnerHandlePrintString(void)
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

static void LinkPartnerHandlePrintStringPlayerOnly(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChooseAction(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleUnknownYesNoBox(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChooseMove(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChooseItem(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChoosePokemon(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd23(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleHealthBarUpdate(void)
{
    s16 hpVal;

    LoadBattleBarGfx(0);
    hpVal = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        u32 maxHP = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MAX_HP);
        u32 curHP = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_HP);

        SetBattleBarStruct(gActiveBank, gHealthBoxesIds[gActiveBank], maxHP, curHP, hpVal);
    }
    else
    {
        u32 maxHP = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MAX_HP);

        SetBattleBarStruct(gActiveBank, gHealthBoxesIds[gActiveBank], maxHP, 0, hpVal);
    }

    gBattleBankFunc[gActiveBank] = CompleteOnHealthbarDone;
}

static void LinkPartnerHandleExpUpdate(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleStatusIconUpdate(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 bank;

        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_STATUS_ICON);
        bank = gActiveBank;
        gBattleSpritesDataPtr->healthBoxesData[bank].statusAnimActive = 0;
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void LinkPartnerHandleStatusAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        DoStatusAnimation(gBattleBufferA[gActiveBank][1],
                        gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8) | (gBattleBufferA[gActiveBank][4] << 16) | (gBattleBufferA[gActiveBank][5] << 24));
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void LinkPartnerHandleStatusXor(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleDataTransfer(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleDMA3Transfer(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePlayBGM(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd32(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleTwoReturnValues(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChosenMonReturnValue(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleOneReturnValue(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleOneReturnValue_Duplicate(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd37(void)
{
    gUnknown_02022D0C.field_0 = 0;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd38(void)
{
    gUnknown_02022D0C.field_0 = gBattleBufferA[gActiveBank][1];
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd39(void)
{
    gUnknown_02022D0C.flag_x80 = 0;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd40(void)
{
    gUnknown_02022D0C.flag_x80 ^= 1;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleHitAnimation(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].invisible == TRUE)
    {
        LinkPartnerBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
        DoHitAnimHealthboxEffect(gActiveBank);
        gBattleBankFunc[gActiveBank] = DoHitAnimBlinkSpriteEffect;
    }
}

static void LinkPartnerHandleCmd42(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleEffectivenessSound(void)
{
    s8 pan;

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        pan = PAN_SIDE_PLAYER;
    else
        pan = PAN_SIDE_OPPONENT;

    PlaySE12WithPanning(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8), pan);
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePlayFanfareOrBGM(void)
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

    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry3(species, -25, 5);
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;
    u32 trainerPicId;

    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);

    gSprites[gBankSpriteIds[gActiveBank]].data0 = 50;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = -40;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    gSprites[gBankSpriteIds[gActiveBank]].data5 = gActiveBank;

    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], sub_805CC00);
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], 1);

    paletteNum = AllocSpritePalette(0xD6F9);

    if ((gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_FIRE_RED
        || (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_LEAF_GREEN)
    {
        trainerPicId = gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender + BACK_PIC_RED;
    }
    else if ((gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_RUBY
             || (gLinkPlayers[GetBankMultiplayerId(gActiveBank)].version & 0xFF) == VERSION_SAPPHIRE)
    {
        trainerPicId = gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender + BACK_PIC_RS_BRENDAN;
    }
    else
    {
        trainerPicId = gLinkPlayers[GetBankMultiplayerId(gActiveBank)].gender;
    }

    LoadCompressedPalette(gTrainerBackPicPaletteTable[trainerPicId].data, 0x100 + paletteNum * 16, 32);

    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = paletteNum;

    taskId = CreateTask(sub_814DCCC, 5);
    gTasks[taskId].data[0] = gActiveBank;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattleBankFunc[gActiveBank] = nullsub_112;
}

static void sub_814DCCC(u8 taskId)
{
    if (gTasks[taskId].data[1] < 24)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        u8 savedActiveBank = gActiveBank;

        gActiveBank = gTasks[taskId].data[0];
        if (!IsDoubleBattle() || (gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
            sub_814CC98(gActiveBank, FALSE);
        }
        else
        {
            gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
            sub_814CC98(gActiveBank, FALSE);
            gActiveBank ^= BIT_MON;
            gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
            BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
            sub_814CC98(gActiveBank, FALSE);
            gActiveBank ^= BIT_MON;
        }
        gBattleBankFunc[gActiveBank] = sub_814B0E8;
        gActiveBank = savedActiveBank;
        DestroyTask(taskId);
    }
}

static void LinkPartnerHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBank][1] != 0 && GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        LinkPartnerBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1 = 1;
        gUnknown_020244B4[gActiveBank] = CreatePartyStatusSummarySprites(gActiveBank, (struct HpAndStatus *)&gBattleBufferA[gActiveBank][4], gBattleBufferA[gActiveBank][1], gBattleBufferA[gActiveBank][2]);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;

        if (gBattleBufferA[gActiveBank][2] != 0)
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0x5D;

        gBattleBankFunc[gActiveBank] = sub_814DE9C;
    }
}

static void sub_814DE9C(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5++ > 0x5C)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;
        LinkPartnerBufferExecCompleted();
    }
}

static void LinkPartnerHandleCmd49(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd50(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSpriteInvisibility(void)
{
    if (AnimBankSpriteExists(gActiveBank))
    {
        gSprites[gBankSpriteIds[gActiveBank]].invisible = gBattleBufferA[gActiveBank][1];
        SetBattleSpriteInvisibilityBitToSpriteInvisibility(gActiveBank);
    }
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleBattleAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 animationId = gBattleBufferA[gActiveBank][1];
        u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

        if (DoBattleAnimationFromTable(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
            LinkPartnerBufferExecCompleted();
        else
            gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;

        sub_817E32C(animationId);
    }
}

static void LinkPartnerHandleLinkStandbyMsg(void)
{
    sub_81851A8(&gBattleBufferA[gActiveBank][2]);
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleResetActionMoveSelection(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd55(void)
{
    sub_81851A8(&gBattleBufferA[gActiveBank][4]);
    gBattleOutcome = gBattleBufferA[gActiveBank][1];
    gSaveBlock2Ptr->field_CA9_b = gBattleBufferA[gActiveBank][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    LinkPartnerBufferExecCompleted();
    gBattleBankFunc[gActiveBank] = sub_80587B0;
}

static void nullsub_113(void)
{
}
