#include "global.h"
#include "reshow_battle_screen.h"
#include "battle.h"
#include "palette.h"
#include "main.h"
#include "scanline_effect.h"
#include "text.h"
#include "gpu_regs.h"
#include "bg.h"
#include "battle_controllers.h"
#include "link.h"
#include "sprite.h"
#include "constants/species.h"
#include "battle_interface.h"
#include "battle_anim.h"

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;

extern const union AnimCmd * const * const gMonAnimationsSpriteAnimsPtrTable[];

extern void sub_806A068(u16 species, u8 bankIdentity);
extern void sub_806A12C(u16 backPicId, u8 bankIdentity);

// this file's functions
static void CB2_ReshowBattleScreenAfterMenu(void);
static bool8 LoadBattlerSpriteGfx(u8 bank);
static void CreateBattlerSprite(u8 bank);
static void CreateHealthboxSprite(u8 bank);
static void sub_80A95F4(void);

void nullsub_35(void)
{

}

void ReshowBattleScreenAfterMenu(void)
{
    gPaletteFade.bufferTransferDisabled = 1;
    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    gBattleScripting.reshowMainState = 0;
    gBattleScripting.reshowHelperState = 0;
    SetMainCallback2(CB2_ReshowBattleScreenAfterMenu);
}

static void CB2_ReshowBattleScreenAfterMenu(void)
{
    switch (gBattleScripting.reshowMainState)
    {
    case 0:
        ScanlineEffect_Clear();
        sub_8035658();
        SetBgAttribute(1, BG_CTRL_ATTR_VISIBLE, 0);
        SetBgAttribute(2, BG_CTRL_ATTR_VISIBLE, 0);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        ResetPaletteFade();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        break;
    case 1:
        CpuFastFill(0, (void*)(VRAM), VRAM_SIZE);
        break;
    case 2:
        LoadBattleTextboxAndBackground();
        break;
    case 3:
        ResetSpriteData();
        break;
    case 4:
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        break;
    case 5:
        ClearSpritesHealthboxAnimData();
        break;
    case 6:
        if (BattleLoadAllHealthBoxesGfx(gBattleScripting.reshowHelperState))
        {
            gBattleScripting.reshowHelperState = 0;
        }
        else
        {
            gBattleScripting.reshowHelperState++;
            gBattleScripting.reshowMainState--;
        }
        break;
    case 7:
        if (!LoadBattlerSpriteGfx(0))
            gBattleScripting.reshowMainState--;
        break;
    case 8:
        if (!LoadBattlerSpriteGfx(1))
            gBattleScripting.reshowMainState--;
        break;
    case 9:
        if (!LoadBattlerSpriteGfx(2))
            gBattleScripting.reshowMainState--;
        break;
    case 10:
        if (!LoadBattlerSpriteGfx(3))
            gBattleScripting.reshowMainState--;
        break;
    case 11:
        CreateBattlerSprite(0);
        break;
    case 12:
        CreateBattlerSprite(1);
        break;
    case 13:
        CreateBattlerSprite(2);
        break;
    case 14:
        CreateBattlerSprite(3);
        break;
    case 15:
        CreateHealthboxSprite(0);
        break;
    case 16:
        CreateHealthboxSprite(1);
        break;
    case 17:
        CreateHealthboxSprite(2);
        break;
    case 18:
        CreateHealthboxSprite(3);
        break;
    case 19:
        {
            u8 opponentBank;
            u16 species;

            LoadAndCreateEnemyShadowSprites();

            opponentBank = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[opponentBank]], MON_DATA_SPECIES);
            SetBattlerShadowSpriteCallback(opponentBank, species);

            if (IsDoubleBattle())
            {
                opponentBank = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[opponentBank]], MON_DATA_SPECIES);
                SetBattlerShadowSpriteCallback(opponentBank, species);
            }

            ActionSelectionCreateCursorAt(gActionSelectionCursor[gBattlerInMenuId], 0);

            if (gWirelessCommType != 0 && gReceivedRemoteLinkPlayers != 0)
            {
                sub_800E0E8();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        break;
    default:
        SetVBlankCallback(VBlankCB_Battle);
        sub_80A95F4();
        BeginHardwarePaletteFade(0xFF, 0, 0x10, 0, 1);
        gPaletteFade.bufferTransferDisabled = 0;
        SetMainCallback2(BattleMainCB2);
        sub_805EF14();
        break;
    }

    gBattleScripting.reshowMainState++;
}

static void sub_80A95F4(void)
{
    struct BGCntrlBitfield *regBgcnt1, *regBgcnt2;

    regBgcnt1 = (struct BGCntrlBitfield *)(&REG_BG1CNT);
    regBgcnt1->charBaseBlock = 0;

    regBgcnt2 = (struct BGCntrlBitfield *)(&REG_BG2CNT);
    regBgcnt2->charBaseBlock = 0;
}

static bool8 LoadBattlerSpriteGfx(u8 battler)
{
    if (battler < gBattlersCount)
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[battler]], battler);
            else
                BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == 0)
            DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, battler);
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == 0)
            DecompressTrainerBackPic(BACK_PIC_WALLY, battler);
        else if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        else
            BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);

        gBattleScripting.reshowHelperState = 0;
    }
    return TRUE;
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

static void CreateBattlerSprite(u8 battler)
{
    if (battler < gBattlersCount)
    {
        u8 posY;

        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            posY = GetSubstituteSpriteDefault_Y(battler);
        else
            posY = GetBattlerSpriteDefault_Y(battler);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                return;

            sub_806A068(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gUnknown_0202499C, GetBattlerSpriteCoord(battler, 2), posY, sub_80A82E4(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], gBattleMonForms[battler]);
            if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_CASTFORM)
                gSprites[gBattlerSpriteIds[battler]].anims = gMonAnimationsSpriteAnimsPtrTable[SPECIES_CASTFORM];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == 0)
        {
            sub_806A12C(gSaveBlock2Ptr->playerGender, GetBattlerPosition(B_POSITION_PLAYER_LEFT));
            gBattlerSpriteIds[battler] = CreateSprite(&gUnknown_0202499C, 0x50,
                                                (8 - gTrainerBackPicCoords[gSaveBlock2Ptr->playerGender].coords) * 4 + 80,
                                                 sub_80A82E4(0));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == 0)
        {
            sub_806A12C(BACK_PIC_WALLY, GetBattlerPosition(0));
            gBattlerSpriteIds[battler] = CreateSprite(&gUnknown_0202499C, 0x50,
                                                (8 - gTrainerBackPicCoords[BACK_PIC_WALLY].coords) * 4 + 80,
                                                 sub_80A82E4(0));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
        }
        else
        {
            if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                return;

            sub_806A068(GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gUnknown_0202499C, GetBattlerSpriteCoord(battler, 2), posY, sub_80A82E4(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], gBattleMonForms[battler]);
            if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_CASTFORM)
                gSprites[gBattlerSpriteIds[battler]].anims = gMonAnimationsSpriteAnimsPtrTable[SPECIES_CASTFORM];
        }

        gSprites[gBattlerSpriteIds[battler]].invisible = gBattleSpritesDataPtr->battlerData[battler].invisible;
    }
}

static void CreateHealthboxSprite(u8 battler)
{
    if (battler < gBattlersCount)
    {
        u8 healthboxSpriteId;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == 0)
            healthboxSpriteId = CreateSafariPlayerHealthboxSprites();
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == 0)
            return;
        else
            healthboxSpriteId = CreateBattlerHealthboxSprites(battler);

        gHealthboxSpriteIds[battler] = healthboxSpriteId;
        InitBattlerHealthboxCoords(battler);
        SetHealthboxSpriteVisible(healthboxSpriteId);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_SAFARI_ALL_TEXT);
        else
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);

        if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_RIGHT || GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT)
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[battler], TRUE);
        else
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[battler], FALSE);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
    }
}
