#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "bg.h"
#include "palette.h"
#include "trig.h"
#include "gpu_regs.h"
#include "menu.h"
#include "window.h"
#include "pokenav.h"
#include "graphics.h"
#include "sound.h"
#include "gym_leader_rematch.h"
#include "window.h"
#include "strings.h"
#include "scanline_effect.h"
#include "constants/songs.h"
#include "constants/rgb.h"

struct Pokenav2Struct
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
    u16 optionDescWindowId;
    u8 bg3ScrollTaskId;
    u8 cursorPos;
    bool8 otherIconsInMotion;
    bool8 pokenavAlreadyOpen;
    bool32 iconVisible[MAX_POKENAV_MENUITEMS];
    struct Sprite * field_028;
    struct Sprite * iconSprites[MAX_POKENAV_MENUITEMS][4];
    u16 bg1TilemapBuffer[0x400];
};

static struct Pokenav2Struct * OpenPokenavMenu(void);
static bool32 GetCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenMenu(s32 state);
static u32 LoopedTask_MoveMenuCursor(s32 state);
static u32 LoopedTask_OpenConditionMenu(s32 state);
static u32 LoopedTask_ReturnToMainMenu(s32 state);
static u32 LoopedTask_OpenConditionSearchMenu(s32 state);
static u32 LoopedTask_ReturnToConditionMenu(s32 state);
static u32 LoopedTask_SelectRibbonsNoWinners(s32 state);
static u32 LoopedTask_ReShowDescription(s32 state);
static u32 LoopedTask_OpenPokenavFeature(s32 state);
static void sub_81C9FC4(void);
static void sub_81C9FEC(void);
static void CreateMenuOptionSprites(void);
static void sub_81CA094(void);
static void sub_81CA0C8(void);
static void sub_81CA0EC(const u16 *const * a0, s32 a1, s32 a2);
static void sub_81CA20C(void);
static void sub_81CA278(void);
static void sub_81CA35C(struct Sprite ** sprites, s32 a1, s32 a2, s32 a3);
static void sub_81CA3B4(struct Sprite ** sprites);
static void sub_81CA2DC(void);
static bool32 AreMenuOptionSpritesMoving(void);
static void sub_81CA448(struct Sprite ** sprites, bool32 a1);
static void sub_81CA474(struct Sprite * sprite);
static void sub_81CA4AC(struct Sprite * sprite);
static void sub_81CA580(u8 taskId);
static void sub_81CA640(void);
static void sub_81CA6AC(struct Sprite * sprite);
static void sub_81CA698(void);
static void AddOptionDescriptionWindow(void);
static void PrintCurrentOptionDescription(void);
static void PrintNoRibbonWinners(void);
static bool32 sub_81CA7C4(void);
static void sub_81CA7D4(void);
static void sub_81CA7F4(void);
static void sub_81CA808(u8 taskId);
static void sub_81CA818(void);
static void sub_81CA850(void);
static void sub_81CA864(void);
static bool32 sub_81CA89C(void);
static void sub_81CA8B0(u8 taskId);
static void sub_81CA92C(void);
static void sub_81CA994(void);
static void sub_81CA9C8(void);
static void sub_81CA9D8(void);
static void sub_81CA9EC(u8 taskId);
static void sub_81CAA3C(void);

static const u16 gUnknown_0861FC78[] = INCBIN_U16("graphics/pokenav/bg.gbapal");
static const u32 gUnknown_0861FC98[] = INCBIN_U32("graphics/pokenav/bg.4bpp.lz");
static const u32 gUnknown_0861FCAC[] = INCBIN_U32("graphics/pokenav/bg.bin.lz");
static const u16 gUnknown_0861FD4C[] = INCBIN_U16("graphics/pokenav/outline.gbapal");
static const u32 gUnknown_0861FD6C[] = INCBIN_U32("graphics/pokenav/outline.4bpp.lz");
static const u32 gUnknown_0861FFF4[] = INCBIN_U32("graphics/pokenav/outline_map.bin.lz");
static const u16 gUnknown_08620104[] = INCBIN_U16("graphics/pokenav/blue_light.gbapal");
static const u32 gUnknown_08620124[] = INCBIN_U32("graphics/pokenav/blue_light.4bpp.lz");

static const struct BgTemplate gUnknown_08620194[] = {
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const LoopedTask sMenuHandlerLoopTaskFuncs[] = {
    [POKENAV_MENU_FUNC_NONE]                  = NULL,
    [POKENAV_MENU_FUNC_MOVE_CURSOR]           = LoopedTask_MoveMenuCursor,
    [POKENAV_MENU_FUNC_OPEN_CONDITION]        = LoopedTask_OpenConditionMenu,
    [POKENAV_MENU_FUNC_RETURN_TO_MAIN]        = LoopedTask_ReturnToMainMenu,
    [POKENAV_MENU_FUNC_OPEN_CONDITION_SEARCH] = LoopedTask_OpenConditionSearchMenu,
    [POKENAV_MENU_FUNC_RETURN_TO_CONDITION]   = LoopedTask_ReturnToConditionMenu,
    [POKENAV_MENU_FUNC_NO_RIBBON_WINNERS]     = LoopedTask_SelectRibbonsNoWinners,
    [POKENAV_MENU_FUNC_RESHOW_DESCRIPTION]    = LoopedTask_ReShowDescription,
    [POKENAV_MENU_FUNC_OPEN_FEATURE]          = LoopedTask_OpenPokenavFeature
};

static const struct CompressedSpriteSheet gUnknown_086201C4[] =
{
    {
        .data = gPokenavOptions_Gfx,
        .size = 0x3400,
        .tag = 0x0003
    },
    {
        .data = gUnknown_08620124,
        .size = 0x0100,
        .tag = 0x0001
    }
};

static const struct SpritePalette gUnknown_086201D4[] =
{
    {gPokenavOptions_Pal + 0x00, 4},
    {gPokenavOptions_Pal + 0x10, 5},
    {gPokenavOptions_Pal + 0x20, 6},
    {gPokenavOptions_Pal + 0x30, 7},
    {gPokenavOptions_Pal + 0x40, 8},
    {gUnknown_08620104, 3},
    {}
};

static const u16 gUnknown_0862020C[] = {0, 0};
static const u16 gUnknown_08620210[] = {0x20, 1};
static const u16 gUnknown_08620214[] = {0x40, 4};
static const u16 gUnknown_08620218[] = {0x60, 2};
static const u16 gUnknown_0862021C[] = {0x80, 3};
static const u16 gUnknown_08620220[] = {0xA0, 1};
static const u16 gUnknown_08620224[] = {0xC0, 1};
static const u16 gUnknown_08620228[] = {0xE0, 4};
static const u16 gUnknown_0862022C[] = {0x100, 1};
static const u16 gUnknown_08620230[] = {0x120, 2};
static const u16 gUnknown_08620234[] = {0x140, 0};
static const u16 gUnknown_08620238[] = {0x160, 0};
static const u16 gUnknown_0862023C[] = {0x180, 3};

struct UnkStruct_08620240
{
    u16 unk0;
    u16 unk2;
    const u16 *unk4[MAX_POKENAV_MENUITEMS];
};

// TODO
static const struct UnkStruct_08620240 gUnknown_08620240[POKENAV_MENU_TYPE_COUNT] =
{
    [POKENAV_MENU_TYPE_DEFAULT] = 
    {
        0x2A,
        0x14,
        {gUnknown_0862020C, gUnknown_08620210, gUnknown_0862021C}
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC] = 
    {
        0x2A,
        0x14,
        {gUnknown_0862020C, gUnknown_08620210, gUnknown_08620214, gUnknown_0862021C}
    },
    [POKENAV_MENU_TYPE_UNLOCK_MC_RIBBONS] = 
    {
        0x2A,
        0x14,
        {gUnknown_0862020C, gUnknown_08620210, gUnknown_08620214, gUnknown_08620218, gUnknown_0862021C}
    },
    [POKENAV_MENU_TYPE_CONDITION] = 
    {
        0x38,
        0x14,
        {gUnknown_08620220, gUnknown_08620224, gUnknown_0862023C}
    },
    [POKENAV_MENU_TYPE_CONDITION_SEARCH] = 
    {
        0x28,
        0x10,
        {gUnknown_08620228, gUnknown_0862022C, gUnknown_08620230, gUnknown_08620234, gUnknown_08620238, gUnknown_0862023C}
    },
};

static const struct WindowTemplate sOptionDescWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 3,
    .tilemapTop = 17,
    .width = 0x18,
    .height = 0x2,
    .paletteNum = 1,
    .baseBlock = 8
};

static const u8 *const sPageDescriptions[] =
{
    [POKENAV_MENUITEM_MAP]                     = gText_CheckMapOfHoenn,
    [POKENAV_MENUITEM_CONDITION]               = gText_CheckPokemonInDetail,
    [POKENAV_MENUITEM_MATCH_CALL]              = gText_CallRegisteredTrainer,
    [POKENAV_MENUITEM_RIBBONS]                 = gText_CheckObtainedRibbons,
    [POKENAV_MENUITEM_SWITCH_OFF]              = gText_PutAwayPokenav,
    [POKENAV_MENUITEM_CONDITION_PARTY]         = gText_CheckPartyPokemonInDetail,
    [POKENAV_MENUITEM_CONDITION_SEARCH]        = gText_CheckAllPokemonInDetail,
    [POKENAV_MENUITEM_CONDITION_CANCEL]        = gText_ReturnToPokenavMenu,
    [POKENAV_MENUITEM_CONDITION_SEARCH_COOL]   = gText_FindCoolPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_BEAUTY] = gText_FindBeautifulPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_CUTE]   = gText_FindCutePokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_SMART]  = gText_FindSmartPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_TOUGH]  = gText_FindToughPokemon,
    [POKENAV_MENUITEM_CONDITION_SEARCH_CANCEL] = gText_ReturnToConditionMenu
};

static const u8 sOptionDescTextColors[]  = {TEXT_COLOR_GREEN, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREEN};
static const u8 sOptionDescTextColors2[] = {TEXT_COLOR_GREEN, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREEN};

static const struct OamData sOamData_MenuOption =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const union AffineAnimCmd gUnknown_0862031C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_0862032C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0x12),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sSpriteAnims_MenuOption[] =
{
    gUnknown_0862031C,
    gUnknown_0862032C
};

static const struct SpriteTemplate sMenuOptionSpriteTemplate =
{
    .tileTag = 3,
    .paletteTag = 4,
    .oam = &sOamData_MenuOption,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAnims_MenuOption,
    .callback = SpriteCallbackDummy,
};

static const struct OamData gUnknown_08620364 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const struct SpriteTemplate gUnknown_0862036C =
{
    .tileTag = 1,
    .paletteTag = 3,
    .oam = &gUnknown_08620364,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct ScanlineEffectParams gUnknown_08620384 =
{
    (void *)REG_ADDR_WIN0H,
        ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
        1,
        0
};

static bool32 sub_81C98D4(void)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (sub_81CB0C8(i) == gMapHeader.regionMapSectionId
            && IsRematchEntryRegistered(i)
            && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    return FALSE;
}

bool32 OpenPokenavMenuInitial(void)
{
    struct Pokenav2Struct * state = OpenPokenavMenu();

    if (state == NULL)
        return FALSE;
    
    state->pokenavAlreadyOpen = FALSE;
    return TRUE;
}

bool32 OpenPokenavMenuNotInitial(void)
{
    struct Pokenav2Struct * state = OpenPokenavMenu();

    if (state == NULL)
        return FALSE;

    state->pokenavAlreadyOpen = TRUE;
    return TRUE;
}

static struct Pokenav2Struct * OpenPokenavMenu(void)
{
    struct Pokenav2Struct * state = AllocSubstruct(2, sizeof(struct Pokenav2Struct));

    if (state != NULL)
    {
        state->otherIconsInMotion = FALSE;
        state->loopedTaskId = CreateLoopedTask(LoopedTask_OpenMenu, 1);
        state->isTaskActiveCB = GetCurrentLoopedTaskActive;
    }

    return state;
}

void CreateMenuHandlerLoopedTask(s32 ltIdx)
{
    struct Pokenav2Struct * state = GetSubstructPtr(2);
    state->loopedTaskId = CreateLoopedTask(sMenuHandlerLoopTaskFuncs[ltIdx], 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsMenuHandlerLoopedTaskActive(void)
{
    struct Pokenav2Struct * state = GetSubstructPtr(2);
    return state->isTaskActiveCB();
}

void FreeMenuHandlerSubstruct2(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    sub_81CA7F4();
    RemoveWindow(unk->optionDescWindowId);
    sub_81C9FEC();
    sub_81CA994();
    FreePokenavSubstruct(2);
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    return IsLoopedTaskActive(unk->loopedTaskId);
}

static u32 LoopedTask_OpenMenu(s32 state)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    switch (state)
    {
    case 0:
        InitBgTemplates(gUnknown_08620194, ARRAY_COUNT(gUnknown_08620194));
        decompress_and_copy_tile_data_to_vram(1, gPokenavMessageBox_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(1, unk->bg1TilemapBuffer);
        CopyToBgTilemapBuffer(1, gPokenavMessageBox_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(gPokenavMessageBox_Pal, 0x10, 0x20);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        decompress_and_copy_tile_data_to_vram(2, gUnknown_0861FD6C, 0, 0, 0);
        decompress_and_copy_tile_data_to_vram(2, gUnknown_0861FFF4, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(gUnknown_0861FD4C, 0x20, 0x20);
        return LT_INC_AND_PAUSE;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        decompress_and_copy_tile_data_to_vram(3, gUnknown_0861FC98, 0, 0, 0);
        decompress_and_copy_tile_data_to_vram(3, gUnknown_0861FCAC, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(gUnknown_0861FC78, 0x30, 0x20);
        if (GetPokenavMenuType() == POKENAV_MENU_TYPE_CONDITION || GetPokenavMenuType() == POKENAV_MENU_TYPE_CONDITION_SEARCH)
            sub_81CA850();
        return LT_INC_AND_PAUSE;
    case 3:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        AddOptionDescriptionWindow();
        sub_81CA7D4();
        return LT_INC_AND_CONTINUE;
    case 4:
        sub_81C9FC4();
        return LT_INC_AND_CONTINUE;
    case 5:
        PrintCurrentOptionDescription();
        CreateMenuOptionSprites();
        sub_81CA640();
        sub_81CA0C8();
        return LT_INC_AND_PAUSE;
    case 6:
        if (sub_81CA7C4())
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    case 7:
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        if (unk->pokenavAlreadyOpen)
            PokenavFadeScreen(1);
        else
        {
            PlaySE(SE_PN_ON);
            PokenavFadeScreen(3);
        }
        switch (GetPokenavMenuType())
        {
        case POKENAV_MENU_TYPE_CONDITION_SEARCH:
            LoadLeftHeaderGfxForIndex(7);
            // fallthrough
        case POKENAV_MENU_TYPE_CONDITION:
            LoadLeftHeaderGfxForIndex(1);
            break;
        default:
            LoadLeftHeaderGfxForIndex(0);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 8:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        switch (GetPokenavMenuType())
        {
        case POKENAV_MENU_TYPE_CONDITION_SEARCH:
            sub_81C7FA0(7, FALSE, FALSE);
            // fallthrough
        case POKENAV_MENU_TYPE_CONDITION:
            sub_81C7FA0(1, FALSE, FALSE);
            break;
        default:
            sub_81C7FA0(0, FALSE, FALSE);
            break;
        }
        sub_81CA20C();
        sub_81CA92C();
        return LT_INC_AND_CONTINUE;
    case 9:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveMenuCursor(s32 state)
{
    switch (state)
    {
    case 0:
        sub_81CAA3C();
        sub_81CA278();
        PrintCurrentOptionDescription();
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81CA7C4())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_OpenConditionMenu(s32 state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        sub_81C7FC4(0, 0);
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        sub_81CA0C8();
        LoadLeftHeaderGfxForIndex(1);
        return LT_INC_AND_PAUSE;
    case 2:
        sub_81CA20C();
        sub_81C7FA0(1, FALSE, FALSE);
        sub_81CA818();
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        if (sub_81CA89C())
            return LT_PAUSE;
        if (sub_81CA7C4())
            return LT_PAUSE;
        sub_81CA9D8();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ReturnToMainMenu(s32 state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        sub_81C7FC4(1, 0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        sub_81CA0C8();
        LoadLeftHeaderGfxForIndex(0);
        return LT_INC_AND_PAUSE;
    case 2:
        sub_81CA20C();
        sub_81C7FA0(0, FALSE, FALSE);
        sub_81CA864();
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        if (sub_81CA89C())
            return LT_PAUSE;
        if (sub_81CA7C4())
            return LT_PAUSE;
        sub_81CA9D8();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_OpenConditionSearchMenu(s32 state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        LoadLeftHeaderGfxForIndex(7);
        sub_81CA0C8();
        return LT_INC_AND_PAUSE;
    case 2:
        sub_81CA20C();
        sub_81C7FA0(7, FALSE, FALSE);
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        if (sub_81CA89C())
            return LT_PAUSE;
        sub_81CA9D8();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ReturnToConditionMenu(s32 state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        sub_81C7FC4(7, 0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        sub_81CA0C8();
        return LT_INC_AND_PAUSE;
    case 2:
        sub_81CA20C();
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 3:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81CA89C())
            return LT_PAUSE;
        sub_81CA9D8();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_SelectRibbonsNoWinners(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_HAZURE);
        PrintNoRibbonWinners();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

// For redisplaying the Ribbons description to replace the No Ribbon Winners message
static u32 LoopedTask_ReShowDescription(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintCurrentOptionDescription();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

// For selecting a feature option from a menu, e.g. the Map, Match Call, Beauty search, etc.
static u32 LoopedTask_OpenPokenavFeature(s32 state)
{
    switch (state)
    {
    case 0:
        PrintHelpBarText(GetHelpBarTextId());
        return LT_INC_AND_PAUSE;
    case 1:
        if (WaitForHelpBar())
            return LT_PAUSE;
        sub_81C7880();
        sub_81CA9C8();
        sub_81CA2DC();
        switch (GetPokenavMenuType())
        {
        case POKENAV_MENU_TYPE_CONDITION_SEARCH:
            sub_81C7FC4(7, FALSE);
            // fallthrough
        case POKENAV_MENU_TYPE_CONDITION:
            sub_81C7FC4(1, FALSE);
            break;
        default:
            sub_81C7FC4(0, FALSE);
            break;
        }
        PlaySE(SE_SELECT);
        return LT_INC_AND_PAUSE;
    case 2:
        if (AreMenuOptionSpritesMoving())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        PokenavFadeScreen(0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static void sub_81C9FC4(void)
{
    s32 i;

    for (i = 0; i < NELEMS(gUnknown_086201C4); i++)
        LoadCompressedSpriteSheet(&gUnknown_086201C4[i]);
    Pokenav_AllocAndLoadPalettes(gUnknown_086201D4);
}

static void sub_81C9FEC(void)
{
    FreeSpriteTilesByTag(3);
    FreeSpriteTilesByTag(1);
    FreeSpritePaletteByTag(4);
    FreeSpritePaletteByTag(5);
    FreeSpritePaletteByTag(6);
    FreeSpritePaletteByTag(7);
    FreeSpritePaletteByTag(8);
    FreeSpritePaletteByTag(3);
    sub_81CA094();
    sub_81CA698();
}

static void CreateMenuOptionSprites(void)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        // Each menu option is 4 subsprites
        for (j = 0; j < 4; j++)
        {
            u8 spriteId = CreateSprite(&sMenuOptionSpriteTemplate, 0x8c, 20 * i + 40, 3);
            unk->iconSprites[i][j] = &gSprites[spriteId];
            gSprites[spriteId].pos2.x = 32 * j;
        }
    }
}

static void sub_81CA094(void)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        for (j = 0; j < 4; j++)
        {
            FreeSpriteOamMatrix(unk->iconSprites[i][j]);
            DestroySprite(unk->iconSprites[i][j]);
        }
    }
}

static void sub_81CA0C8(void)
{
    s32 menuType = GetPokenavMenuType();
    sub_81CA0EC(gUnknown_08620240[menuType].unk4, gUnknown_08620240[menuType].unk0, gUnknown_08620240[menuType].unk2);
}

static void sub_81CA0EC(const u16 *const *a0, s32 a1, s32 a2)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    s32 sp04 = GetSpriteTileStartByTag(3);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (*a0 != NULL)
        {
            for (j = 0; j < 4; j++)
            {
                unk->iconSprites[i][j]->oam.tileNum = (*a0)[0] + sp04 + 8 * j;
                unk->iconSprites[i][j]->oam.paletteNum = IndexOfSpritePaletteTag((*a0)[1] + 4);
                unk->iconSprites[i][j]->invisible = TRUE;
                unk->iconSprites[i][j]->pos1.y = a1;
                unk->iconSprites[i][j]->pos1.x = 0x8c;
                unk->iconSprites[i][j]->pos2.x = 32 * j;
            }
            unk->iconVisible[i] = TRUE;
        }
        else
        {
            for (j = 0; j < 4; j++)
            {
                unk->iconSprites[i][j]->invisible = TRUE;
            }
            unk->iconVisible[i] = FALSE;
        }
        a0++;
        a1 += a2;
    }
}

static void sub_81CA20C(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    s32 r8 = GetPokenavCursorPos();
    s32 r7 = 0;
    s32 r2;

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (unk->iconVisible[i])
        {
            if (r7++ == r8)
            {
                r2 = 0x82;
                unk->cursorPos = i;
            }
            else
                r2 = 0x8c;
            sub_81CA35C(unk->iconSprites[i], 0x100, r2, 0xC);
            sub_81CA448(unk->iconSprites[i], FALSE);
        }
        else
            sub_81CA448(unk->iconSprites[i], TRUE);
    }
}

static void sub_81CA278(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    s32 r3 = GetPokenavCursorPos();
    s32 r5;

    for (i = 0, r5 = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (unk->iconVisible[i])
        {
            if (r5 == r3)
            {
                r5 = i;
                break;
            }
            r5++;
        }
    }

    sub_81CA35C(unk->iconSprites[unk->cursorPos], 0x82, 0x8c, 0x4);
    sub_81CA35C(unk->iconSprites[r5], 0x8c, 0x82, 0x4);
    unk->cursorPos = r5;
}

static void sub_81CA2DC(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (unk->iconVisible[i])
        {
            if (unk->cursorPos != i)
                sub_81CA35C(unk->iconSprites[i], 0x8C, 0x100, 0x8);
            else
                sub_81CA3B4(unk->iconSprites[i]);
        }
    }
}

static bool32 AreMenuOptionSpritesMoving(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < MAX_POKENAV_MENUITEMS; i++)
    {
        if (unk->iconSprites[i][0]->callback != SpriteCallbackDummy)
            return TRUE;
    }

    if (unk->otherIconsInMotion)
        return TRUE;

    return FALSE;
}

static void sub_81CA35C(struct Sprite ** sprites, s32 a1, s32 a2, s32 a3)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        (*sprites)->pos1.x = a1;
        (*sprites)->data[0] = a3;
        (*sprites)->data[1] = 16 * (a2 - a1) / a3;
        (*sprites)->data[2] = 16 * a1;
        (*sprites)->data[7] = a2;
        (*sprites)->callback = sub_81CA474;
        sprites++;
    }
}

static void sub_81CA3B4(struct Sprite ** sprites)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    u8 taskId;

    for (i = 0; i < 4; i++)
    {
        (*sprites)->oam.objMode = ST_OAM_OBJ_BLEND;
        (*sprites)->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        (*sprites)->callback = sub_81CA4AC;
        (*sprites)->data[0] = 8;
        (*sprites)->data[1] = 0;
        (*sprites)->data[7] = i;
        InitSpriteAffineAnim(sprites[0]);
        StartSpriteAffineAnim(sprites[0], 0);
        sprites++;
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x10, 0x00));
    taskId = CreateTask(sub_81CA580, 3);
    gTasks[taskId].data[0] = 8;
    unk->otherIconsInMotion++;
}

static void sub_81CA448(struct Sprite ** sprites, bool32 a1)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        (*sprites)->invisible = a1;
        sprites++;
    }
}

static void sub_81CA474(struct Sprite * sprite)
{
    sprite->data[0]--;
    if (sprite->data[0] != -1)
    {
        sprite->data[2] += sprite->data[1];
        sprite->pos1.x = sprite->data[2] >> 4;
    }
    else
    {
        sprite->pos1.x = sprite->data[7];
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_81CA4AC(struct Sprite * sprite)
{
    s32 r0;
    s32 r1;
    if (sprite->data[0] == 0)
    {
        if (sprite->data[1] == 0)
        {
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[1]++;
            sprite->data[2] = 0x100;
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos2.x = 0;
        }
        else
        {
            sprite->data[2] += 16;
            r0 = sprite->data[2];
            r1 = r0 >> 3;
            r1 = (r1 - 32) / 2;
            switch (sprite->data[7])
            {
            case 0:
                sprite->pos2.x = -r1 * 3;
                break;
            case 1:
                sprite->pos2.x = -r1;
                break;
            case 2:
                sprite->pos2.x = r1;
                break;
            case 3:
                sprite->pos2.x = r1 * 3;
                break;
            }
            if (sprite->affineAnimEnded)
            {
                sprite->invisible = TRUE;
                FreeOamMatrix(sprite->oam.matrixNum);
                CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, ST_OAM_AFFINE_OFF);
                sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
                sprite->oam.objMode = ST_OAM_OBJ_NORMAL;
                sprite->callback = SpriteCallbackDummy;
            }
        }
    }
    else
    {
        sprite->data[0]--;
    }
}

static void sub_81CA580(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        switch (data[1])
        {
        case 0:
            data[2] = 16;
            data[3] = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE | BLDCNT_TGT2_ALL);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x10, 0x00));
            data[1]++;
            break;
        case 1:
            if (data[4] & 1)
            {
                data[2] -= 3;
                if (data[2] < 0)
                    data[2] = 0;
            }
            else
            {
                data[3] += 3;
                if (data[3] > 16)
                    data[3] = 16;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(data[2], data[3]));
            data[4]++;
            if (data[4] == 12)
            {
                ((struct Pokenav2Struct *)GetSubstructPtr(2))->otherIconsInMotion--;
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0x00, 0x10));
                DestroyTask(taskId);
            }
            break;
        }
    }
    else
        data[0]--;
}

static void sub_81CA640(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);
    u8 spriteId = CreateSprite(&gUnknown_0862036C, 0x10, 0x60, 4);
    ptr->field_028 = &gSprites[spriteId];
    if (sub_81C98D4())
        ptr->field_028->callback = sub_81CA6AC;
    else
        ptr->field_028->invisible = TRUE;
}

static void sub_81CA698(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);
    DestroySprite(ptr->field_028);
}

static void sub_81CA6AC(struct Sprite * sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] > 8)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
    }
}

static void AddOptionDescriptionWindow(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);

    ptr->optionDescWindowId = AddWindow(&sOptionDescWindowTemplate);
    PutWindowTilemap(ptr->optionDescWindowId);
    FillWindowPixelBuffer(ptr->optionDescWindowId, PIXEL_FILL(6));
    CopyWindowToVram(ptr->optionDescWindowId, 3);
}

static void PrintCurrentOptionDescription(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);
    int menuItem = GetCurrentMenuItemId();
    const u8 * s = sPageDescriptions[menuItem];
    u32 width = GetStringWidth(1, s, -1);
    FillWindowPixelBuffer(ptr->optionDescWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(ptr->optionDescWindowId, 1, (192 - width) / 2, 1, sOptionDescTextColors, 0, s);
}

// Printed when Ribbons is selected if no PC/party mons have ribbons
// Can occur by obtaining a mon with a ribbon and then releasing all ribbon winners
static void PrintNoRibbonWinners(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);
    const u8 * s = gText_NoRibbonWinners;
    u32 width = GetStringWidth(1, s, -1);
    FillWindowPixelBuffer(ptr->optionDescWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(ptr->optionDescWindowId, 1, (192 - width) / 2, 1, sOptionDescTextColors2, 0, s);
}

static bool32 sub_81CA7C4(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void sub_81CA7D4(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);
    ptr->bg3ScrollTaskId = CreateTask(sub_81CA808, 2);
}

static void sub_81CA7F4(void)
{
    struct Pokenav2Struct * ptr = GetSubstructPtr(2);
    DestroyTask(ptr->bg3ScrollTaskId);
}

static void sub_81CA808(u8 taskId)
{
    ChangeBgX(3, 0x80, 1);
}

static void sub_81CA818(void)
{
    u8 taskId = CreateTask(sub_81CA8B0, 3);
    SetWordTaskArg(taskId, 1, (uintptr_t)(gUnknown_0861FC78 + 1));
    SetWordTaskArg(taskId, 3, (uintptr_t)(gUnknown_0861FC78 + 7));
}

static void sub_81CA850(void)
{
    CopyPaletteIntoBufferUnfaded(gUnknown_0861FC78 + 7, 0x31, 4);
}

static void sub_81CA864(void)
{
    u8 taskId = CreateTask(sub_81CA8B0, 3);
    SetWordTaskArg(taskId, 1, (uintptr_t)(gUnknown_0861FC78 + 7));
    SetWordTaskArg(taskId, 3, (uintptr_t)(gUnknown_0861FC78 + 1));
}

static bool32 sub_81CA89C(void)
{
    return FuncIsActiveTask(sub_81CA8B0);
}

static void sub_81CA8B0(u8 taskId)
{
    u16 sp8[2];
    s16 * data = gTasks[taskId].data;
    const u16 * pal1 = (const u16 *)GetWordTaskArg(taskId, 1);
    const u16 * pal2 = (const u16 *)GetWordTaskArg(taskId, 3);

    sub_81C79BC(pal1, pal2, 2, 12, ++data[0], sp8);
    LoadPalette(sp8, 0x31, 4);
    if (data[0] == 12)
        DestroyTask(taskId);
}

static void sub_81CA914(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void sub_81CA92C(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuRegBits(REG_OFFSET_WININ, 0x3F);
    SetGpuRegBits(REG_OFFSET_WINOUT, 0x1F);
    SetGpuRegBits(REG_OFFSET_WIN0V, 0xA0);
    ScanlineEffect_Stop();
    sub_81CAA3C();
    ScanlineEffect_SetParams(gUnknown_08620384);
    SetVBlankCallback_(sub_81CA914);
    CreateTask(sub_81CA9EC, 3);
}

static void sub_81CA994(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    ScanlineEffect_Stop();
    DestroyTask(FindTaskIdByFunc(sub_81CA9EC));
    SetPokenavVBlankCallback();
}

static void sub_81CA9C8(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void sub_81CA9D8(void)
{
    sub_81CAA3C();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_LIGHTEN);
}

static void sub_81CA9EC(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    data[0]++;
    if (data[0] > 0)
    {
        data[0] = 0;
        data[1] += 3;
        data[1] &= 0x7F;
        SetGpuReg(REG_OFFSET_BLDY, gSineTable[data[1]] >> 5);
    }
}

static void sub_81CAA3C(void)
{
    int menuType = GetPokenavMenuType();
    int cursorPos = GetPokenavCursorPos();
    int r4 = gUnknown_08620240[menuType].unk2 * cursorPos + gUnknown_08620240[menuType].unk0 - 8;
    CpuFill16(0, gScanlineEffectRegBuffers[0], 0x140);
    CpuFill16(0, gScanlineEffectRegBuffers[1], 0x140);
    CpuFill16(RGB(16, 23, 28), &gScanlineEffectRegBuffers[0][r4], 0x20);
    CpuFill16(RGB(16, 23, 28), &gScanlineEffectRegBuffers[1][r4], 0x20);
}

void sub_81CAADC(void)
{
    sub_81CA9C8();
}
