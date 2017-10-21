#include "global.h"
#include "reshow_battle_screen.h"
#include "battle.h"
#include "palette.h"
#include "main.h"
#include "unknown_task.h"
#include "text.h"
#include "gpu_regs.h"
#include "bg.h"
#include "battle_controllers.h"
#include "link.h"
#include "sprite.h"
#include "species.h"
#include "battle_interface.h"

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u8 gReservedSpritePaletteCount;
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gBankInMenu;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern u32 gBattleTypeFlags;
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern struct SpriteTemplate gUnknown_0202499C;

extern const union AnimCmd * const * const gMonAnimationsSpriteAnimsPtrTable[];

extern void dp12_8087EA4(void);
extern void trs_config(void);
extern bool8 IsDoubleBattle(void);
extern u8 sub_80A614C(u8 bank);
extern u8 sub_80A6138(u8 bank);
extern u8 sub_80A82E4(u8 bank);
extern void sub_806A068(u16 species, u8 bankIdentity);
extern void sub_806A12C(u16 backPicId, u8 bankIdentity);
extern u8 sub_80A5C6C(u8 bank, u8 caseId);

// this file's functions
static void CB2_ReshowBattleScreenAfterMenu(void);
static bool8 LoadBankSpriteGfx(u8 bank);
static void CreateBankSprite(u8 bank);
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
        dp12_8087EA4();
        trs_config();
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
        sub_805E350();
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
        if (!LoadBankSpriteGfx(0))
            gBattleScripting.reshowMainState--;
        break;
    case 8:
        if (!LoadBankSpriteGfx(1))
            gBattleScripting.reshowMainState--;
        break;
    case 9:
        if (!LoadBankSpriteGfx(2))
            gBattleScripting.reshowMainState--;
        break;
    case 10:
        if (!LoadBankSpriteGfx(3))
            gBattleScripting.reshowMainState--;
        break;
    case 11:
        CreateBankSprite(0);
        break;
    case 12:
        CreateBankSprite(1);
        break;
    case 13:
        CreateBankSprite(2);
        break;
    case 14:
        CreateBankSprite(3);
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

            opponentBank = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
            species = GetMonData(&gEnemyParty[gBattlePartyID[opponentBank]], MON_DATA_SPECIES);
            SetBankEnemyShadowSpriteCallback(opponentBank, species);

            if (IsDoubleBattle())
            {
                opponentBank = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
                species = GetMonData(&gEnemyParty[gBattlePartyID[opponentBank]], MON_DATA_SPECIES);
                SetBankEnemyShadowSpriteCallback(opponentBank, species);
            }

            ActionSelectionCreateCursorAt(gActionSelectionCursor[gBankInMenu], 0);

            if (gLinkVSyncDisabled != 0 && gReceivedRemoteLinkPlayers != 0)
            {
                sub_800E0E8();
                sub_800DFB4(0, 0);
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

static bool8 LoadBankSpriteGfx(u8 bank)
{
    if (bank < gNoOfAllBanks)
    {
        if (GetBankSide(bank) != SIDE_PLAYER)
        {
            if (!gBattleSpritesDataPtr->bankData[bank].behindSubstitute)
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlePartyID[bank]], bank);
            else
                BattleLoadSubstituteSpriteGfx(bank, FALSE);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && bank == 0)
            DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, bank);
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && bank == 0)
            DecompressTrainerBackPic(BACK_PIC_WALLY, bank);
        else if (!gBattleSpritesDataPtr->bankData[bank].behindSubstitute)
            BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[bank]], bank);
        else
            BattleLoadSubstituteSpriteGfx(bank, FALSE);

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

static void CreateBankSprite(u8 bank)
{
    if (bank < gNoOfAllBanks)
    {
        u8 posY;

        if (gBattleSpritesDataPtr->bankData[bank].behindSubstitute)
            posY = sub_80A614C(bank);
        else
            posY = sub_80A6138(bank);

        if (GetBankSide(bank) != SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_HP) == 0)
                return;

            sub_806A068(GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES), GetBankIdentity(bank));
            gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C, sub_80A5C6C(bank, 2), posY, sub_80A82E4(bank));
            gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;
            gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;
            gSprites[gBankSpriteIds[bank]].data0 = bank;
            gSprites[gBankSpriteIds[bank]].data2 = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], gBattleMonForms[bank]);
            if (gBattleSpritesDataPtr->bankData[bank].transformSpecies == SPECIES_CASTFORM)
                gSprites[gBankSpriteIds[bank]].anims = gMonAnimationsSpriteAnimsPtrTable[SPECIES_CASTFORM];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && bank == 0)
        {
            sub_806A12C(gSaveBlock2Ptr->playerGender, GetBankIdentity(IDENTITY_PLAYER_MON1));
            gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C, 0x50,
                                                (8 - gTrainerBackPicCoords[gSaveBlock2Ptr->playerGender].coords) * 4 + 80,
                                                 sub_80A82E4(0));
            gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;
            gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;
            gSprites[gBankSpriteIds[bank]].data0 = bank;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && bank == 0)
        {
            sub_806A12C(BACK_PIC_WALLY, GetBankIdentity(0));
            gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C, 0x50,
                                                (8 - gTrainerBackPicCoords[BACK_PIC_WALLY].coords) * 4 + 80,
                                                 sub_80A82E4(0));
            gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;
            gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;
            gSprites[gBankSpriteIds[bank]].data0 = bank;
        }
        else
        {
            if (GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_HP) == 0)
                return;

            sub_806A068(GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES), GetBankIdentity(bank));
            gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C, sub_80A5C6C(bank, 2), posY, sub_80A82E4(bank));
            gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;
            gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;
            gSprites[gBankSpriteIds[bank]].data0 = bank;
            gSprites[gBankSpriteIds[bank]].data2 = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], gBattleMonForms[bank]);
            if (gBattleSpritesDataPtr->bankData[bank].transformSpecies == SPECIES_CASTFORM)
                gSprites[gBankSpriteIds[bank]].anims = gMonAnimationsSpriteAnimsPtrTable[SPECIES_CASTFORM];
        }

        gSprites[gBankSpriteIds[bank]].invisible = gBattleSpritesDataPtr->bankData[bank].invisible;
    }
}

static void CreateHealthboxSprite(u8 bank)
{
    if (bank < gNoOfAllBanks)
    {
        u8 healthboxSpriteId;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && bank == 0)
            healthboxSpriteId = CreateSafariPlayerHealthboxSprites();
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && bank == 0)
            return;
        else
            healthboxSpriteId = CreateBankHealthboxSprites(bank);

        gHealthBoxesIds[bank] = healthboxSpriteId;
        SetBankHealthboxSpritePos(bank);
        SetHealthboxSpriteVisible(healthboxSpriteId);

        if (GetBankSide(bank) != SIDE_PLAYER)
            UpdateHealthboxAttribute(gHealthBoxesIds[bank], &gEnemyParty[gBattlePartyID[bank]], HEALTHBOX_ALL);
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            UpdateHealthboxAttribute(gHealthBoxesIds[bank], &gPlayerParty[gBattlePartyID[bank]], HEALTHBOX_SAFARI_ALL_TEXT);
        else
            UpdateHealthboxAttribute(gHealthBoxesIds[bank], &gPlayerParty[gBattlePartyID[bank]], HEALTHBOX_ALL);

        if (GetBankIdentity(bank) == IDENTITY_OPPONENT_MON2 || GetBankIdentity(bank) == IDENTITY_PLAYER_MON2)
            DummyBattleInterfaceFunc(gHealthBoxesIds[bank], TRUE);
        else
            DummyBattleInterfaceFunc(gHealthBoxesIds[bank], FALSE);

        if (GetBankSide(bank) != SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            if (GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
    }
}
