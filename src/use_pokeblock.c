#include "global.h"
#include "main.h"
#include "pokeblock.h"
#include "malloc.h"
#include "decompress.h"
#include "graphics.h"
#include "palette.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "scanline_effect.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "sound.h"
#include "constants/songs.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "menu.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "pokemon_summary_screen.h"
#include "item_menu.h"

/*
    This file handles the pokeblock screen where the player
    chooses which pokemon to give a pokeblock to. The subsequent
    scene of feeding the pokeblock to the pokemon is handled by
    pokeblock_feed.c, and the rest of the pokeblock menu (and 
    other pokeblock-related functions) are in pokeblock.c
*/

enum {
    WIN_NAME,
    WIN_NATURE,
    WIN_TEXT,
    WIN_COUNT
};

struct UsePokeblockSession
{
    /*0x00*/ void (*callback)(void);
    /*0x04*/ void (*exitCallback)(void);
    /*0x08*/ struct Pokeblock *pokeblock;
    /*0x0C*/ struct Pokemon *mon;
    /*0x10*/ u8 stringBuffer[0x40];
    /*0x50*/ u8 mainState;
    /*0x51*/ u8 field_51; // unused
    /*0x52*/ u8 field_52;
    /*0x53*/ u8 field_53;
    /*0x54*/ u8 numEnhancements;
    /*0x55*/ u8 field_55; // unused
    /*0x56*/ u8 field_56;
    /*0x57*/ u8 field_57[FLAVOR_COUNT];
    /*0x5C*/ u8 field_5c[FLAVOR_COUNT];
    /*0x61*/ u8 field_61[FLAVOR_COUNT];
    /*0x66*/ s16 field_66[FLAVOR_COUNT];
    /*0x70*/ u8 field_70; // mon id + 1
    /*0x71*/ u8 field_71; // mon id 
    /*0x74*/ u8 (*unk74)(void); // selection handler
    /*0x78*/ u8 helperState;
    /*0x79*/ u8 filler79[1]; // unused
    /*0x7A*/ u8 field_7A[0x22]; // nature text buffer
};

// This struct is identical to PokenavMonList, the struct used for managing lists of pokemon in the pokenav
// Given that this screen is essentially duplicated in the poknav, this struct was probably the same one with
// a more general name/purpose
// TODO: Once the pokenav conditions screens are documented, resolve the above
struct UsePokeblockMenuPokemon
{
    u8 boxId; // Because this screen is never used for the PC this is always set to TOTAL_BOXES_COUNT to refer to party
    u8 monId;
    u16 data; // never read
};

struct UsePokeblockMenu
{
    /*0x0000*/ u8 filler0[4]; // unused
    /*0x0000*/ u16 field_4[6][0x40]; // pal buffer
    /*0x0304*/ u8 field_304[3][0x2000]; // sheet buffer
    /*0x6304*/ u8 filler_6304[0x1000]; // unused?
    /*0x7304*/ u8 tilemapBuffer[BG_SCREEN_SIZE + 2];
    /*0x7B06*/ u8 field_7B06[7]; // sprite ids
    /*0x7B0E*/ s16 field_7B0E; // x pos?
    /*0x7B10*/ u8 field_7B10; // sprite id?
    /*0x7B12*/ u16 field_7B12; // pal
    /*0x7B12*/ u16 field_7B14; // sheet
    /*0x7B12*/ u8 *field_7B18;
    /*0x7B1C*/ struct Sprite *sparkles[10];
    /*0x7B44*/ struct Sprite *condition[2];
    /*0x7B4C*/ u8 field_7B4C;
    /*0x7B4D*/ u8 field_7B4D[3][24];
    /*0x7B95*/ u8 field_7B95[3][64];
    /*0x7C58*/ struct UnknownStruct_81D1ED4 field_7C58;
    /*0x7FB0*/ u8 unk7FB0[3];
    /*0x7FB3*/ s8 field_7FB3;
    /*0x7FB4*/ s8 field_7FB4;
    /*0x7FB5*/ s8 field_7FB5;
    /*0x7FB6*/ s8 field_7FB6;
    /*0x7FB8*/ struct UsePokeblockMenuPokemon party[PARTY_SIZE];
    /*0x7FD0*/ struct UsePokeblockSession info;
};

#define TAG_UP_DOWN     0
#define TAG_CONDITION   1

static void SetUsePokeblockCallback(void (*func)(void));
static void LoadUsePokeblockMenu(void);
static void sub_816631C(void);
static void sub_81662C0(void);
static void ShowUsePokeblockMenu(void);
static void sub_8166304(void);
static void sub_81668F8(void);
static void sub_8167420(void);
static void sub_8167760(void);
static u8 GetNumNonEggPartyMons(u8);
static bool8 sub_8168328(void);
static bool8 LoadUsePokeblockGfx(void);
static void sub_8167608(u8);
static void UpdateMonInfoText(u16, bool8);
static void UsePokeblockMenu(void);
static void sub_8167CA0(bool8);
static void CloseUsePokeblockMenu(void);
static void AskUsePokeblock(void);
static s8 HandleAskUsePokeblockInput(void);
static bool8 IsSheenMaxed(void);
static void PrintWontEatAnymore(void);
static void FeedPokeblockToMon(void);
static void EraseMenuWindow(void);
static u8 sub_81672A4(u8);
static void sub_8166A34(void);
static void sub_8167104(void);
static void sub_8167338(void);
static void sub_81681F4(u8);
static void sub_8166E24(void);
static bool8 sub_8166EDC(void);
static void BufferEnhancedStatText(u8 *, u8, s16);
static void PrintMenuWindowText(const u8 *);
static void sub_8167184(struct Pokeblock *, struct Pokemon *);
static void sub_81673DC(struct Sprite *);
static void sub_81674BC(void);
static void sub_816753C(s16, u8);
static u8 sub_8167EA4(void);
static u8 sub_8167FA4(void);
static u8 sub_8168048(void);
static void sub_8168180(struct Sprite *);
static void sub_81681B4(struct Sprite *);
static void sub_8168168(struct Sprite *);
static void sub_8168374(struct Sprite *);

extern const u16 gConditionGraphData_Pal[];
extern const u16 gUnknown_08623208[];

// The below 3 are saved for returning to the screen after feeding a pokeblock to a mon
// so that the rest of the data can be freed
static EWRAM_DATA struct UsePokeblockSession *sInfo = NULL;
static EWRAM_DATA void (*sExitCallback)(void) = NULL;
static EWRAM_DATA struct Pokeblock *sPokeblock = NULL;
EWRAM_DATA u8 gPokeblockMonId = 0;
EWRAM_DATA s16 gPokeblockGain = 0;
static EWRAM_DATA u8 *sGraph_Tilemap = NULL;
static EWRAM_DATA u8 *sGraph_Gfx = NULL;
static EWRAM_DATA u8 *sMonFrame_TilemapPtr = NULL;
static EWRAM_DATA struct UsePokeblockMenu *sMenu = NULL;

static const u32 sMonFrame_Pal[] = INCBIN_U32("graphics/pokeblock/use_screen/mon_frame_pal.bin"); // TODO: convert to .pal
static const u32 sMonFrame_Gfx[] = INCBIN_U32("graphics/pokeblock/use_screen/mon_frame.4bpp");
static const u32 sMonFrame_Tilemap[] = INCBIN_U32("graphics/pokeblock/use_screen/mon_frame.bin");
static const u32 sGraphData_Tilemap[] = INCBIN_U32("graphics/pokeblock/use_screen/graph_data.bin");

static const u32 gUnknown_085DFCB0[] =
{
    MON_DATA_COOL,
    MON_DATA_TOUGH,
    MON_DATA_SMART,
    MON_DATA_CUTE,
    MON_DATA_BEAUTY
};

static const u8 sFlavors[FLAVOR_COUNT] =
{
    FLAVOR_SPICY,
    FLAVOR_SOUR,
    FLAVOR_BITTER,
    FLAVOR_SWEET,
    FLAVOR_DRY
};

static const u8 sNatureTextColors[] =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_WHITE
};

static const struct BgTemplate sBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x1E,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1D,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x100
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x17,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates[WIN_COUNT + 1] = 
{
    [WIN_NAME] = {
        .bg = 0,
        .tilemapLeft = 13,
        .tilemapTop = 1,
        .width = 13,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WIN_NATURE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 14,
        .width = 11,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x35
    },
    [WIN_TEXT] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 17,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x4B
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sUsePokeblockYesNoWinTemplate = 
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 11,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x83
};

static const u8 *const sContestStatNames[] =
{
    gText_Coolness,
    gText_Toughness,
    gText_Smartness,
    gText_Cuteness,
    gText_Beauty3
};

static const struct SpriteSheet sSpriteSheet_UpDown = 
{
    gUsePokeblockUpDown_Gfx, 0x200, TAG_UP_DOWN
};

static const struct SpritePalette sSpritePalette_UpDown =
{
    gUsePokeblockUpDown_Pal, TAG_UP_DOWN
};

static const s16 gUnknown_085DFD28[][2] =
{
    {0x9C, 0x24},
    {0x75, 0x3B},
    {0x75, 0x76},
    {0xC5, 0x76},
    {0xC5, 0x3B}
};

static const struct OamData sOam_UpDown = 
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const union AnimCmd sAnim_Up[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Down[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_UpDown[] =
{
    sAnim_Up,
    sAnim_Down
};

static const struct SpriteTemplate sSpriteTemplate_UpDown =
{
    .tileTag = TAG_UP_DOWN,
    .paletteTag = TAG_UP_DOWN,
    .oam = &sOam_UpDown,
    .anims = sAnims_UpDown,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOam_Condition = 
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const union AnimCmd gSpriteAnim_085DFD7C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_085DFD84[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_085DFD8C[] =
{
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Condition[] =
{
    gSpriteAnim_085DFD7C,
    gSpriteAnim_085DFD84,
    gSpriteAnim_085DFD8C
};

static const struct SpriteTemplate sSpriteTemplate_Condition =
{
    .tileTag = TAG_CONDITION,
    .paletteTag = TAG_CONDITION,
    .oam = &sOam_Condition,
    .anims = sAnims_Condition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8168374,
};

static const struct SpritePalette sSpritePalette_Condition =
{
    gUsePokeblockCondition_Pal, TAG_CONDITION
};

// When first opening the selection screen
void ChooseMonToGivePokeblock(struct Pokeblock *pokeblock, void (*callback)(void))
{
    sMenu = AllocZeroed(sizeof(*sMenu));
    sInfo = &sMenu->info;
    sInfo->pokeblock = pokeblock;
    sInfo->exitCallback = callback;
    SetUsePokeblockCallback(LoadUsePokeblockMenu);
    SetMainCallback2(sub_816631C);
}

// When returning to the selection screen after feeding a pokeblock to a mon
static void CB2_ReturnAndChooseMonToGivePokeblock(void)
{
    sMenu = AllocZeroed(sizeof(*sMenu));
    sInfo = &sMenu->info;
    sInfo->pokeblock = sPokeblock;
    sInfo->exitCallback = sExitCallback;
    gPokeblockMonId = GetNumNonEggPartyMons(gPokeblockMonId);
    sInfo->field_56 = gPokeblockMonId < 4 ? 0 : 1;
    SetUsePokeblockCallback(LoadUsePokeblockMenu);
    SetMainCallback2(sub_81662C0);
}

static void sub_81662C0(void)
{
    sInfo->callback();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (sInfo->callback == ShowUsePokeblockMenu)
    {
        sInfo->mainState = 0;
        SetMainCallback2(sub_8166304);
    }
}

static void sub_8166304(void)
{
    sub_81668F8();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_816631C(void)
{
    sInfo->callback();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void VBlankCB_UsePokeblock(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_81D2108(&sMenu->field_7C58);
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void SetUsePokeblockCallback(void (*func)(void))
{
    sInfo->callback = func;
    sInfo->mainState = 0;
}

static void LoadUsePokeblockMenu(void)
{
    switch (sInfo->mainState)
    {
    case 0:
        sMenu->field_7B10 = 0xFF;
        sub_81D1ED4(&sMenu->field_7C58);
        sInfo->mainState++;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        sInfo->mainState++;
        break;
    case 2:
        SetVBlankCallback(NULL);
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
        sInfo->mainState++;
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWindowTemplates);
        DeactivateAllTextPrinters();
        LoadUserWindowBorderGfx(0, 0x97, 0xE0);
        sInfo->mainState++;
        break;
    case 4:
        sInfo->mainState++;
        break;
    case 5:
        if (!sub_8168328())
            sInfo->mainState++;
        break;
    case 6:
        gKeyRepeatStartDelay = 20;
        sub_8167420();
        sInfo->mainState++;
        break;
    case 7:
        if (!LoadUsePokeblockGfx())
            sInfo->mainState++;
        break;
    case 8:
        sub_8167608(0);
        sub_8167760();
        sInfo->mainState++;
        break;
    case 9:
        if (!sub_81D312C(&sMenu->field_7B0E))
            sInfo->mainState++;
        break;
    case 10:
        sInfo->mainState++;
        break;
    case 11:
        sub_81D2754(sMenu->field_7C58.unk0[0], sMenu->field_7C58.unk14[0]);
        sub_81D20AC(&sMenu->field_7C58);
        sInfo->mainState++;
        break;
    case 12:
        if (!sub_81D20BC(&sMenu->field_7C58))
        {
            sub_81D1F84(&sMenu->field_7C58, sMenu->field_7C58.unk14[0], sMenu->field_7C58.unk14[0]);
            sInfo->mainState++;
        }
        break;
    case 13:
        sub_81D2230(&sMenu->field_7C58);
        sInfo->mainState++;
        break;
    case 14:
        PutWindowTilemap(WIN_NAME);
        PutWindowTilemap(WIN_NATURE);
        UpdateMonInfoText(0, TRUE);
        sInfo->mainState++;
        break;
    case 15:
        SetUsePokeblockCallback(ShowUsePokeblockMenu);
        break;
    }
}

static void ShowUsePokeblockMenu(void)
{
    switch (sInfo->mainState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_UsePokeblock);
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        ShowBg(2);
        sInfo->mainState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            ResetConditionSparkleSprites(sMenu->sparkles);
            if (sMenu->info.field_71 != sMenu->info.field_70 - 1)
            {
                u8 var0 = sMenu->unk7FB0[sMenu->field_7FB3];
                CreateConditionSparkleSprites(sMenu->sparkles, sMenu->field_7B10, var0);
            }

            SetUsePokeblockCallback(UsePokeblockMenu);
        }
        break;
    }
}

enum {
    STATE_HANDLE_INPUT,
    STATE_UPDATE_SELECTION,
    STATE_2, // unused state
    STATE_CLOSE,
    STATE_4, // unused state
    STATE_CONFIRM_SELECTION,
    STATE_HANDLE_CONFIRMATION,
    STATE_WAIT_MSG,
};

static void UsePokeblockMenu(void)
{
    u8 var;

    switch (sInfo->mainState)
    {
    case STATE_HANDLE_INPUT:
        if (JOY_HELD(DPAD_UP))
        {
            PlaySE(SE_SELECT);
            sub_8167CA0(TRUE);
            DestroyConditionSparkleSprites(sMenu->sparkles);
            sInfo->mainState = STATE_UPDATE_SELECTION;
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            sub_8167CA0(FALSE);
            DestroyConditionSparkleSprites(sMenu->sparkles);
            sInfo->mainState = STATE_UPDATE_SELECTION;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sInfo->mainState = STATE_CLOSE;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);

            // If last item, selected Cancel. Otherwise selected mon
            if (sMenu->info.field_71 == sMenu->info.field_70 - 1)
                sInfo->mainState = STATE_CLOSE;
            else
                sInfo->mainState = STATE_CONFIRM_SELECTION;
        }
        break;
    case STATE_UPDATE_SELECTION:
        var = sMenu->info.unk74();
        if (!var)
            sInfo->mainState = STATE_HANDLE_INPUT;
        break;
    case STATE_2:
        break;
    case STATE_CLOSE:
        SetUsePokeblockCallback(CloseUsePokeblockMenu);
        break;
    case STATE_4:
        break;
    case STATE_CONFIRM_SELECTION:
        AskUsePokeblock();
        sInfo->mainState++;
        break;
    case STATE_HANDLE_CONFIRMATION:
        switch (HandleAskUsePokeblockInput())
        {
        case 1: // NO
        case MENU_B_PRESSED:
            sInfo->mainState = STATE_HANDLE_INPUT;
            break;
        case 0: // YES
            if (IsSheenMaxed())
            {
                PrintWontEatAnymore();
                sInfo->mainState = STATE_WAIT_MSG;
            }
            else
            {
                SetUsePokeblockCallback(FeedPokeblockToMon);
            }
            break;
        }
        break;
    case STATE_WAIT_MSG:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            EraseMenuWindow();
            sInfo->mainState = STATE_HANDLE_INPUT;
        }
        break;
    }
}

static void FeedPokeblockToMon(void)
{
    switch (sInfo->mainState)
    {
    case 0:
        gPokeblockMonId = sub_81672A4(sMenu->info.field_71);
        sExitCallback = sInfo->exitCallback;
        sPokeblock = sInfo->pokeblock;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sInfo->mainState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetVBlankCallback(NULL);
            FREE_AND_SET_NULL(sGraph_Tilemap);
            FREE_AND_SET_NULL(sGraph_Gfx);
            FREE_AND_SET_NULL(sMonFrame_TilemapPtr);
            FREE_AND_SET_NULL(sMenu);
            FreeAllWindowBuffers();
            gMain.savedCallback = CB2_ReturnAndChooseMonToGivePokeblock;
            CB2_PreparePokeblockFeedScene();
        }
        break;
    }
}

static void sub_81668F8(void)
{
    u16 var;

    switch (sInfo->mainState)
    {
    case 0:
        if (sMenu->info.field_71 != gPokeblockMonId)
        {
            sub_8167CA0(sInfo->field_56);
            sInfo->mainState++;
        }
        else
        {
            sInfo->mainState = 3;
        }
        break;
    case 1:
        var = sMenu->info.unk74();
        if (!var)
            sInfo->mainState = var;
        break;
    case 2:
        break;
    case 3:
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        sInfo->mainState++;
        break;
    case 4:
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        ShowBg(2);
        sInfo->mainState++;
        break;
    case 5:
        SetVBlankCallback(VBlankCB_UsePokeblock);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        sInfo->mainState++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            ResetConditionSparkleSprites(sMenu->sparkles);
            SetUsePokeblockCallback(sub_8166A34);
            SetMainCallback2(sub_816631C);
        }
        break;
    }
}

static void sub_8166A34(void)
{
    u8 var;

    switch (sInfo->mainState)
    {
    case 0:
        sInfo->mon = gPlayerParty;
        sInfo->mon += sMenu->party[sMenu->info.field_71].monId;
        DestroyConditionSparkleSprites(sMenu->sparkles);
        sInfo->mainState++;
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            sInfo->mainState++;
        break;
    case 2:
        sub_8167104();
        sub_81D2754(sInfo->field_5c, sMenu->field_7C58.unk14[3]);
        sub_81D1F84(&sMenu->field_7C58, sMenu->field_7C58.unk14[sMenu->field_7FB3], sMenu->field_7C58.unk14[3]);
        sub_8167338();
        sInfo->mainState++;
        break;
    case 3:
        var = sub_81D2074(&sMenu->field_7C58);
        if (!var)
        {
            sub_81681F4(sub_81672A4(sMenu->info.field_71));
            if (sMenu->info.field_71 != sMenu->info.field_70 - 1)
            {
                u8 var0 = sMenu->unk7FB0[sMenu->field_7FB3];
                CreateConditionSparkleSprites(sMenu->sparkles, sMenu->field_7B10, var0);
            }

            sInfo->field_52 = 0;
            sInfo->mainState++;
        }
        break;
    case 4:
        if (++sInfo->field_52 > 16)
        {
            sub_8166E24();
            sInfo->mainState++;
        }
        break;
    case 5:
        if (JOY_NEW(A_BUTTON | B_BUTTON) && !sub_8166EDC())
        {
            TryClearPokeblock((u8)gSpecialVar_ItemId);
            SetUsePokeblockCallback(CloseUsePokeblockMenu);
        }
        break;
    }
}

static void CloseUsePokeblockMenu(void)
{
    u8 i, var;

    switch (sInfo->mainState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sInfo->mainState++;
        break;
    case 1:
        if (!gPaletteFade.active)
            sInfo->mainState = 2;
        break;
    case 2:
        gScanlineEffect.state = 3;
        ScanlineEffect_InitHBlankDmaTransfer();
        sInfo->mainState++;
        break;
    case 3:
        SetMainCallback2(sInfo->exitCallback);
        FreeConditionSparkles(sMenu->sparkles);
        for (i = 0; i < ARRAY_COUNT(sMenu->field_7B06); i++)
            DestroySprite(&gSprites[sMenu->field_7B06[i]]);

        FreeSpriteTilesByTag(TAG_UP_DOWN);
        FreeSpriteTilesByTag(TAG_CONDITION);
        FreeSpritePaletteByTag(TAG_UP_DOWN);
        FreeSpritePaletteByTag(TAG_CONDITION);

        for (i = 0; i < ARRAY_COUNT(sMenu->condition); i++)
            DestroySprite(sMenu->condition[i]);

        if (sMenu->field_7B10 != 0xFF)
            DestroySprite(&gSprites[sMenu->field_7B10]);

        SetVBlankCallback(NULL);
        FREE_AND_SET_NULL(sGraph_Tilemap);
        FREE_AND_SET_NULL(sGraph_Gfx);
        FREE_AND_SET_NULL(sMonFrame_TilemapPtr);
        FREE_AND_SET_NULL(sMenu);
        FreeAllWindowBuffers();
        break;
    }
}

static void AskUsePokeblock(void)
{
    u8 stringBuffer[0x40];

    GetMonData(&gPlayerParty[sub_81672A4(sMenu->info.field_71)], MON_DATA_NICKNAME, stringBuffer);
    StringGetEnd10(stringBuffer);
    StringAppend(stringBuffer, gText_GetsAPokeBlockQuestion);
    StringCopy(gStringVar4, stringBuffer);
    FillWindowPixelBuffer(WIN_TEXT, 17);
    DrawTextBorderOuter(WIN_TEXT, 151, 14);
    AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, 0, NULL);
    PutWindowTilemap(WIN_TEXT);
    CopyWindowToVram(WIN_TEXT, 3);
    CreateYesNoMenu(&sUsePokeblockYesNoWinTemplate, 151, 14, 0);
}

static s8 HandleAskUsePokeblockInput(void)
{
    s8 menuItem = Menu_ProcessInputNoWrapClearOnChoose();

    switch (menuItem)
    {
    case 0: // YES
        break;
    case MENU_B_PRESSED:
    case 1: // NO
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(2);
        ClearWindowTilemap(2);
        break;
    }

    return menuItem;
}

static void sub_8166E24(void)
{
    DrawTextBorderOuter(WIN_TEXT, 151, 14);
    FillWindowPixelBuffer(WIN_TEXT, 17);

    for (sInfo->field_53 = 0; sInfo->field_53 < FLAVOR_COUNT; sInfo->field_53++)
    {
        if (sInfo->field_61[sInfo->field_53] != 0)
            break;
    }

    if (sInfo->field_53 < FLAVOR_COUNT)
        BufferEnhancedStatText(gStringVar4, sInfo->field_53, sInfo->field_61[sInfo->field_53]);
    else
        BufferEnhancedStatText(gStringVar4, sInfo->field_53, 0);

    PrintMenuWindowText(gStringVar4);
    PutWindowTilemap(WIN_TEXT);
    CopyWindowToVram(WIN_TEXT, 3);
}

static bool8 sub_8166EDC(void)
{
    FillWindowPixelBuffer(WIN_TEXT, 17);

    while (1)
    {
        sInfo->field_53++;
        if (sInfo->field_53 < FLAVOR_COUNT)
        {
            if (sInfo->field_61[sInfo->field_53] != 0)
                break;
        }
        else
        {
            sInfo->field_53 = FLAVOR_COUNT;
            return FALSE;
        }
    }

    BufferEnhancedStatText(gStringVar4, sInfo->field_53, sInfo->field_61[sInfo->field_53]);
    PrintMenuWindowText(gStringVar4);
    CopyWindowToVram(WIN_TEXT, 2);

    return TRUE;
}

static void PrintWontEatAnymore(void)
{
    FillWindowPixelBuffer(WIN_TEXT, 17);
    DrawTextBorderOuter(WIN_TEXT, 151, 14);
    AddTextPrinterParameterized(WIN_TEXT, 1, gText_WontEatAnymore, 0, 1, 0, NULL);
    PutWindowTilemap(WIN_TEXT);
    CopyWindowToVram(WIN_TEXT, 3);
}

static void EraseMenuWindow(void)
{
    rbox_fill_rectangle(WIN_TEXT);
    ClearWindowTilemap(WIN_TEXT);
    CopyWindowToVram(WIN_TEXT, 3);
}

static void PrintMenuWindowText(const u8 *message)
{
    AddTextPrinterParameterized(WIN_TEXT, 1, gStringVar4, 0, 1, 0, NULL);
}

static void BufferEnhancedStatText(u8 *dest, u8 statId, s16 enhancement)
{
    switch (enhancement)
    {
    case 1 ... 32767: // if > 0
        enhancement = 0;
        // fallthrough
    case -32768 ... -1: // if < 0
        if (enhancement)
            dest[(u16)enhancement] += 0; // something you can't imagine
        StringCopy(dest, sContestStatNames[statId]);
        StringAppend(dest, gText_WasEnhanced);
        break;
    case 0:
        StringCopy(dest, gText_NothingChanged);
        break;
    }
}

static void GetMonConditions(struct Pokemon *mon, u8 *data)
{
    u16 i;

    for (i = 0; i < 5; i++)
        data[i] = GetMonData(mon, gUnknown_085DFCB0[i]);
}

static void sub_8167054(struct Pokeblock *pokeblock, struct Pokemon *mon)
{
    u16 i;
    s16 cstat;
    u8 data;

    if (GetMonData(mon, MON_DATA_SHEEN) != 255)
    {
        sub_8167184(pokeblock, mon);
        for (i = 0; i < FLAVOR_COUNT; i++)
        {
            data = GetMonData(mon, gUnknown_085DFCB0[i]);
            cstat = data +  sInfo->field_66[i];
            if (cstat < 0)
                cstat = 0;
            if (cstat > 255)
                cstat = 255;
            data = cstat;
            SetMonData(mon, gUnknown_085DFCB0[i], &data);
        }

        cstat = (u8)(GetMonData(mon, MON_DATA_SHEEN)) + pokeblock->feel;
        if (cstat > 255)
            cstat = 255;

        data = cstat;
        SetMonData(mon, MON_DATA_SHEEN, &data);
    }
}

static void sub_8167104(void)
{
    u16 i;
    struct Pokemon *mon = gPlayerParty;
    mon += sMenu->unk7FB0[sMenu->info.field_71 * 4 + 9];

    GetMonConditions(mon, sInfo->field_57);
    sub_8167054(sInfo->pokeblock, mon);
    GetMonConditions(mon, sInfo->field_5c);
    for (i = 0; i < FLAVOR_COUNT; i++)
        sInfo->field_61[i] = sInfo->field_5c[i] - sInfo->field_57[i];
}

static void sub_8167184(struct Pokeblock *pokeblock, struct Pokemon *mon)
{
    s8 i, direction, taste;

    sInfo->field_66[0] = pokeblock->spicy;
    sInfo->field_66[1] = pokeblock->sour;
    sInfo->field_66[2] = pokeblock->bitter;
    sInfo->field_66[3] = pokeblock->sweet;
    sInfo->field_66[4] = pokeblock->dry;

    if (gPokeblockGain > 0)
        direction = 1;
    else if (gPokeblockGain < 0)
        direction = -1;
    else
        return;

    for (i = 0; i < FLAVOR_COUNT; i++)
    {
        s16 amount = sInfo->field_66[i];
        s8 boost = amount / 10;

        if (amount % 10 >= 5) // round to the nearest
            boost++;

        taste = GetMonFlavorRelation(mon, sFlavors[i]);
        if (taste == direction)
            sInfo->field_66[i] += boost * taste;
    }
}

static bool8 IsSheenMaxed(void)
{
    if (GetBoxOrPartyMonData(sMenu->party[sMenu->info.field_71].boxId,
                             sMenu->party[sMenu->info.field_71].monId,
                             MON_DATA_SHEEN,
                             NULL) == 255)
        return TRUE;
    else
        return FALSE;
}

static u8 sub_81672A4(u8 a0)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            if (a0 == 0)
                return i;
            a0--;
        }
    }

    return 0;
}

// TODO: Update
static u8 GetNumNonEggPartyMons(u8 partyCount)
{
    u8 i, numEggs;

    for (i = 0, numEggs = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            numEggs++;
    }

    return partyCount - numEggs;
}

// Unused
static u8 sub_8167324(u8 a0)
{
    return sub_81672A4(a0);
}

static void sub_8167338(void)
{
    u16 i, spriteId;

    LoadSpriteSheet(&sSpriteSheet_UpDown);
    LoadSpritePalette(&sSpritePalette_UpDown);
    sInfo->numEnhancements = 0;

    for (i = 0; i < FLAVOR_COUNT; i++)
    {
        if (sInfo->field_61[i] != 0)
        {
            spriteId = CreateSprite(&sSpriteTemplate_UpDown, gUnknown_085DFD28[i][0], gUnknown_085DFD28[i][1], 0);
            if (spriteId != MAX_SPRITES)
            {
                if (sInfo->field_61[i] != 0)
                    gSprites[spriteId].callback = sub_81673DC;

                sInfo->numEnhancements++;
            }
        }
    }
}

static void sub_81673DC(struct Sprite *sprite)
{
    if (sprite->data[0] < 6)
        sprite->pos2.y -= 2;
    else if (sprite->data[0] < 12)
        sprite->pos2.y += 2;

    if (++sprite->data[0] > 60)
    {
        DestroySprite(sprite);
        sInfo->numEnhancements--;
    }
}

static void sub_8167420(void)
{
    u16 i;
    u16 numMons;

    for (i = 0, numMons = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            sMenu->party[numMons].boxId = TOTAL_BOXES_COUNT;
            sMenu->party[numMons].monId = i;
            sMenu->party[numMons].data = 0;
            numMons++;
        }
    }

    sMenu->info.field_71 = 0;
    sMenu->info.field_70 = numMons + 1;
    sub_81674BC();
}

static void sub_81674BC(void)
{
    s16 var, var2;

    sub_816753C(sMenu->info.field_71, 0);
    sMenu->field_7FB3 = 0;
    sMenu->field_7FB4 = 1;
    sMenu->field_7FB5 = 2;

    var = sMenu->info.field_71 + 1;
    if (var >= sMenu->info.field_70)
        var = 0;

    var2 = sMenu->info.field_71 - 1;
    if (var2 < 0)
        var2 = sMenu->info.field_70 - 1;

    sub_816753C(var, 1);
    sub_816753C(var2, 2);
}

static void sub_816753C(s16 id1, u8 id2)
{
    u8 boxId = sMenu->party[id1].boxId;
    u8 monId = sMenu->party[id1].monId;
    u8 r6 = sMenu->info.field_70;
    bool8 r8 = FALSE;

    sub_81D2ED4(sMenu->field_7B4D[id2], sMenu->field_7B95[id2], boxId, monId, id1, r6, r8);
    sub_81D2F78(&sMenu->field_7C58, sMenu->unk7FB0, boxId, monId, id1, id2, r6, r8);
    sub_81D3094(sMenu->field_304[id2], sMenu->field_4[id2], boxId, monId, id1, r6, r8);
}

static void sub_8167608(u8 arg0)
{
    u8 spriteId;
    struct SpriteTemplate spriteTemplate;
    struct SpriteSheet spriteSheet;
    struct SpritePalette spritePal;

    if (sMenu->field_7B10 == 0xFF)
    {
        sub_81D31D0(&spriteSheet, &spriteTemplate, &spritePal);
        spriteSheet.data = sMenu->field_304[arg0];
        spritePal.data = sMenu->field_4[arg0];
        sMenu->field_7B12 = LoadSpritePalette(&spritePal);
        sMenu->field_7B14 = LoadSpriteSheet(&spriteSheet);
        spriteId = CreateSprite(&spriteTemplate, 38, 104, 0);
        sMenu->field_7B10 = spriteId;
        if (spriteId == MAX_SPRITES)
        {
            FreeSpriteTilesByTag(100);
            FreeSpritePaletteByTag(100);
            sMenu->field_7B10 = 0xFF;
        }
        else
        {
            sMenu->field_7B10 = spriteId;
            gSprites[sMenu->field_7B10].callback = sub_8168168;
            gSprites[sMenu->field_7B10].pos2.y -= 34;
            sMenu->field_7B18 = (void*)(OBJ_VRAM0 + (sMenu->field_7B14 * 32));
            sMenu->field_7B12 = (sMenu->field_7B12 * 16) + 0x100;
        }
    }
    else
    {
        do {} while(0); // Only needed to match, feel free to remove.
        DmaCopy16Defvars(3, sMenu->field_304[arg0], sMenu->field_7B18, 0x800);
        LoadPalette(sMenu->field_4[arg0], sMenu->field_7B12, 32);
    }
}

static void sub_8167760(void)
{
    u16 i, spriteId;
    struct SpriteSheet spriteSheets[4];
    struct SpriteTemplate spriteTemplate;
    struct SpritePalette spritePals[3];
    struct SpriteSheet spriteSheet2;
    struct SpritePalette spritePal2;

    LoadConditionSelectionIcons(spriteSheets, &spriteTemplate, spritePals);
    LoadSpriteSheets(spriteSheets);
    LoadSpritePalettes(spritePals);

    for (i = 0; i < sMenu->info.field_70 - 1; i++)
    {
        spriteId = CreateSprite(&spriteTemplate, 226, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            sMenu->field_7B06[i] = spriteId;
            gSprites[spriteId].data[0] = i;
            gSprites[spriteId].callback = sub_8168180;
        }
        else
        {
            sMenu->field_7B06[i] = -1;
        }
    }

    spriteTemplate.tileTag = 103;
    for (; i < 6; i++)
    {
        spriteId = CreateSprite(&spriteTemplate, 230, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            sMenu->field_7B06[i] = spriteId;
            gSprites[spriteId].oam.size = 0;
        }
        else
        {
            sMenu->field_7B06[i] = -1;
        }
    }

    spriteTemplate.tileTag = 102;
    spriteTemplate.callback = sub_81681B4;
    spriteId = CreateSprite(&spriteTemplate, 222, (i * 20) + 8, 0);
    if (spriteId != MAX_SPRITES)
    {
        sMenu->field_7B06[i] = spriteId;
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
        gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
    }
    else
    {
        sMenu->field_7B06[i] = -1;
    }

    LoadConditionSparkle(&spriteSheet2, &spritePal2);
    LoadSpriteSheet(&spriteSheet2);
    LoadSpritePalette(&spritePal2);
}

static bool8 LoadUsePokeblockGfx(void)
{
    switch (sMenu->info.helperState)
    {
    case 0:
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 136 << 6, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        break;
    case 1:
        sGraph_Gfx = Alloc(6656);
        sGraph_Tilemap = Alloc(1280);
        sMonFrame_TilemapPtr = Alloc(1280);
        break;
    case 2:
        LZ77UnCompVram(sMonFrame_Tilemap, sMonFrame_TilemapPtr);
        break;
    case 3:
        LoadBgTiles(3, sMonFrame_Gfx, 224, 0);
        break;
    case 4:
         LoadBgTilemap(3, sMonFrame_TilemapPtr, 1280, 0);
        break;
    case 5:
        LoadPalette(sMonFrame_Pal, 208, 32);
        sMenu->field_7B0E = -80;
        break;
    case 6:
        LZ77UnCompVram(gUsePokeblockGraph_Gfx, sGraph_Gfx);
        break;
    case 7:
        LZ77UnCompVram(gUsePokeblockGraph_Tilemap, sGraph_Tilemap);
        LoadPalette(gUsePokeblockGraph_Pal, 32, 32);
        break;
    case 8:
        LoadBgTiles(1, sGraph_Gfx, 6656, 160 << 2);
        break;
    case 9:
        SetBgTilemapBuffer(1, sGraph_Tilemap);
        CopyToBgTilemapBufferRect(1, gUsePokeblockNatureWin_Pal, 0, 13, 12, 4);
        CopyBgTilemapBufferToVram(1);
        break;
    case 10:
        LZ77UnCompVram(sGraphData_Tilemap, sMenu->tilemapBuffer);
        break;
    case 11:
        LoadBgTilemap(2, sMenu->tilemapBuffer, 1280, 0);
        LoadPalette(gConditionGraphData_Pal, 48, 32);
        LoadPalette(gUnknown_08623208, 240, 32);
        sub_81D21DC(2);
        break;
    default:
        sMenu->info.helperState = 0;
        return FALSE;
    }

    sMenu->info.helperState++;
    return TRUE;
}

static void UpdateMonInfoText(u16 arg0, bool8 firstPrint)
{
    u8 partyIndex;
    u8 nature;
    u8 *str;

    FillWindowPixelBuffer(WIN_NAME, PIXEL_FILL(0));
    FillWindowPixelBuffer(WIN_NATURE, PIXEL_FILL(0));
    if (sMenu->info.field_71 != sMenu->info.field_70 - 1)
    {
        AddTextPrinterParameterized(WIN_NAME, 1, sMenu->field_7B95[arg0], 0, 1, 0, NULL);
        partyIndex = sub_81672A4(sMenu->info.field_71);
        nature = GetNature(&gPlayerParty[partyIndex]);
        str = StringCopy(sMenu->info.field_7A, gText_NatureSlash);
        str = StringCopy(str, gNatureNamePointers[nature]);
        AddTextPrinterParameterized3(WIN_NATURE, 1, 2, 1, sNatureTextColors, 0, sMenu->info.field_7A);
    }

    if (firstPrint)
    {
        CopyWindowToVram(WIN_NAME, 3);
        CopyWindowToVram(WIN_NATURE, 3);
    }
    else
    {
        CopyWindowToVram(WIN_NAME, 2);
        CopyWindowToVram(WIN_NATURE, 2);
    }
}

static void sub_8167CA0(bool8 arg0)
{
    u16 var0;
    bool32 r8, r4;

    if (arg0)
        var0 = sMenu->field_7FB5;
    else
        var0 = sMenu->field_7FB4;

    sub_81D1F84(
        &sMenu->field_7C58,
        sMenu->field_7C58.unk14[sMenu->field_7FB3],
        sMenu->field_7C58.unk14[var0]);

    r8 = (sMenu->info.field_71 ^ (sMenu->info.field_70 - 1)) ? 1 : 0;
    if (arg0)
    {
        sMenu->field_7FB5 = sMenu->field_7FB4;
        sMenu->field_7FB4 = sMenu->field_7FB3;
        sMenu->field_7FB3 = var0;
        sMenu->field_7FB6 = sMenu->field_7FB5;

        sMenu->info.field_71 = (sMenu->info.field_71 == 0)
            ? sMenu->info.field_70 - 1
            : sMenu->info.field_71 - 1;

        sMenu->field_7B4C = (sMenu->info.field_71 == 0)
            ? sMenu->info.field_70 - 1
            : sMenu->info.field_71 - 1;
    }
    else
    {
        sMenu->field_7FB4 = sMenu->field_7FB5;
        sMenu->field_7FB5 = sMenu->field_7FB3;
        sMenu->field_7FB3 = var0;
        sMenu->field_7FB6 = sMenu->field_7FB4;

        sMenu->info.field_71 = (sMenu->info.field_71 < sMenu->info.field_70 - 1)
            ? sMenu->info.field_71 + 1
            : 0;

        sMenu->field_7B4C = (sMenu->info.field_71 < sMenu->info.field_70 - 1)
            ? sMenu->info.field_71 + 1
            : 0;
    }

    r4 = (sMenu->info.field_71 ^ (sMenu->info.field_70 - 1)) ? 1 : 0;
    DestroyConditionSparkleSprites(sMenu->sparkles);

    if (!r8)
        sMenu->info.unk74 = sub_8167EA4;
    else if (!r4)
        sMenu->info.unk74 = sub_8167FA4;
    else
        sMenu->info.unk74 = sub_8168048;
}

static u8 sub_8167EA4(void)
{
    switch (sMenu->info.helperState)
    {
    case 0:
        sub_8167608(sMenu->field_7FB3);
        sMenu->info.helperState++;
        break;
    case 1:
        UpdateMonInfoText(sMenu->field_7FB3, FALSE);
        sMenu->info.helperState++;
        break;
    case 2:
        if (!sub_81D3178(&sMenu->field_7C58, &sMenu->field_7B0E))
        {
            sub_816753C(sMenu->field_7B4C, sMenu->field_7FB6);
            sMenu->info.helperState++;
        }
        break;
    case 3:
        ResetConditionSparkleSprites(sMenu->sparkles);
        if (sMenu->info.field_71 != sMenu->info.field_70 - 1)
        {
            u8 var0 = sMenu->unk7FB0[sMenu->field_7FB3];
            CreateConditionSparkleSprites(sMenu->sparkles, sMenu->field_7B10, var0);
        }

        sMenu->info.helperState = 0;
        return FALSE;
    }

    return TRUE;
}

static u8 sub_8167FA4(void)
{
    switch (sMenu->info.helperState)
    {
    case 0:
        if (!sub_81D31A4(&sMenu->field_7C58, &sMenu->field_7B0E))
            sMenu->info.helperState++;
        break;
    case 1:
        UpdateMonInfoText(sMenu->field_7FB3, FALSE);
        sMenu->info.helperState++;
        break;
    case 2:
        sub_816753C(sMenu->field_7B4C, sMenu->field_7FB6);
        sMenu->info.helperState++;
        break;
    case 3:
        sMenu->info.helperState = 0;
        return FALSE;
    }

    return TRUE;
}

static u8 sub_8168048(void)
{
    switch (sMenu->info.helperState)
    {
    case 0:
        sub_81D2074(&sMenu->field_7C58);
        if (!sub_81D3150(&sMenu->field_7B0E))
        {
            sub_8167608(sMenu->field_7FB3);
            sMenu->info.helperState++;
        }
        break;
    case 1:
        UpdateMonInfoText(sMenu->field_7FB3, FALSE);
        sMenu->info.helperState++;
        break;
    case 2:
        if (!sub_81D3178(&sMenu->field_7C58, &sMenu->field_7B0E))
        {
            sub_816753C(sMenu->field_7B4C, sMenu->field_7FB6);
            sMenu->info.helperState++;
        }
        break;
    case 3:
        ResetConditionSparkleSprites(sMenu->sparkles);
        if (sMenu->info.field_71 != sMenu->info.field_70 - 1)
        {
            u8 var0 = sMenu->unk7FB0[sMenu->field_7FB3];
            CreateConditionSparkleSprites(sMenu->sparkles, sMenu->field_7B10, var0);
        }

        sMenu->info.helperState = 0;
        return FALSE;
    }

    return TRUE;
}

static void sub_8168168(struct Sprite *sprite)
{
    sprite->pos1.x = sMenu->field_7B0E + 38;
}

static void sub_8168180(struct Sprite *sprite)
{
    if (sprite->data[0] == sMenu->info.field_71)
        StartSpriteAnim(sprite, 0);
    else
        StartSpriteAnim(sprite, 1);
}

static void sub_81681B4(struct Sprite *sprite)
{
    if (sMenu->info.field_71 == sMenu->info.field_70 - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(101);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(102);
}

static void sub_81681F4(u8 monIndex)
{
    u8 sheen = GetMonData(&gPlayerParty[monIndex], MON_DATA_SHEEN);

    sMenu->unk7FB0[sMenu->field_7FB3] = (sheen != 255)
        ? sheen / 29
        : 9;
}

static void sub_8168248(void)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePalette;

    spritePalette = sSpritePalette_Condition;
    spriteSheet.data = gUsePokeblockCondition_Gfx;
    spriteSheet.size = 0x800;
    spriteSheet.tag = TAG_CONDITION;
    LoadCompressedSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
}

static void sub_8168294(void)
{
    u16 i;
    s16 xDiff, xStart;
    int yStart = 17;
    int var = 8;
    struct Sprite **sprites = sMenu->condition;
    const struct SpriteTemplate *template = &sSpriteTemplate_Condition;

    for (i = 0, xDiff = 64, xStart = -96; i < 2; i++)
    {
        u8 spriteId = CreateSprite(template, i * xDiff + xStart, yStart, 0);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = var;
            gSprites[spriteId].data[1] = (i * xDiff) | 0x20;
            gSprites[spriteId].data[2] = i;
            StartSpriteAnim(&gSprites[spriteId], i);
            sprites[i] = &gSprites[spriteId];
        }
    }
}

static bool8 sub_8168328(void)
{
    switch (sMenu->info.helperState)
    {
    case 0:
        sub_8168248();
        sMenu->info.helperState++;
        return TRUE;
    case 1:
        sub_8168294();
        sMenu->info.helperState = 0;
        return FALSE;
    }

    return FALSE;
}

static void sub_8168374(struct Sprite *sprite)
{
    s16 prevX = sprite->pos1.x;

    sprite->pos1.x += sprite->data[0];
    if ((prevX <= sprite->data[1] && sprite->pos1.x >= sprite->data[1])
     || (prevX >= sprite->data[1] && sprite->pos1.x <= sprite->data[1]))
    {
        sprite->pos1.x = sprite->data[1];
        sprite->callback = SpriteCallbackDummy;
    }
}
