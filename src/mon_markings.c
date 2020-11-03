#include "global.h"
#include "dma3.h"
#include "graphics.h"
#include "main.h"
#include "window.h"
#include "list_menu.h"
#include "mon_markings.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "text_window.h"

#define MENU_TEXT_SPRITE_X_OFFSET 32

// static functions
static void sub_811FC80(s16, s16, u16, u16);
static void TaskDummy7(struct Sprite *);
static void sub_811FF40(struct Sprite *);
static void sub_811FF7C(struct Sprite *);
static struct Sprite *sub_811FFD4(u16, u16, const u16 *, u16);

// .rodata
static const u16 gUnknown_0859E65C[] = INCBIN_U16("graphics/misc/mon_markings.gbapal");
static const u8 gUnknown_0859E67C[] = INCBIN_U8("graphics/misc/mon_markings.4bpp");

static const struct OamData gUnknown_0859EE7C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_0859EE84 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gUnknown_0859EE8C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EE94[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EE9C[] =
{
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EEA4[] =
{
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EEAC[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EEB4[] =
{
    ANIMCMD_FRAME(5, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EEBC[] =
{
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EEC4[] =
{
    ANIMCMD_FRAME(7, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EECC[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EED4[] =
{
    ANIMCMD_FRAME(9, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const gUnknown_0859EEDC[] =
{
    gUnknown_0859EE8C,
    gUnknown_0859EE94,
    gUnknown_0859EE9C,
    gUnknown_0859EEA4,
    gUnknown_0859EEAC,
    gUnknown_0859EEB4,
    gUnknown_0859EEBC,
    gUnknown_0859EEC4,
    gUnknown_0859EECC,
    gUnknown_0859EED4,
};

static const union AnimCmd gUnknown_0859EF04[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF0C[] =
{
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const gUnknown_0859EF14[] =
{
    gUnknown_0859EF04,
    gUnknown_0859EF0C,
};

static const struct OamData gUnknown_0859EF1C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gUnknown_0859EF24[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF2C[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF34[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF3C[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF44[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF4C[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF54[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF5C[] =
{
    ANIMCMD_FRAME(28, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF64[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF6C[] =
{
    ANIMCMD_FRAME(36, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF74[] =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF7C[] =
{
    ANIMCMD_FRAME(44, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF84[] =
{
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF8C[] =
{
    ANIMCMD_FRAME(52, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF94[] =
{
    ANIMCMD_FRAME(56, 5),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0859EF9C[] =
{
    ANIMCMD_FRAME(60, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const gUnknown_0859EFA4[] =
{
    gUnknown_0859EF24,
    gUnknown_0859EF2C,
    gUnknown_0859EF34,
    gUnknown_0859EF3C,
    gUnknown_0859EF44,
    gUnknown_0859EF4C,
    gUnknown_0859EF54,
    gUnknown_0859EF5C,
    gUnknown_0859EF64,
    gUnknown_0859EF6C,
    gUnknown_0859EF74,
    gUnknown_0859EF7C,
    gUnknown_0859EF84,
    gUnknown_0859EF8C,
    gUnknown_0859EF94,
    gUnknown_0859EF9C,
};

static EWRAM_DATA struct PokemonMarkMenu *sMenu = NULL;

void sub_811F90C(struct PokemonMarkMenu *ptr)
{
    sMenu = ptr;
}

void sub_811F918(void)
{
    const struct TilesPal *frame = GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType);
    sMenu->frameTiles = frame->tiles;
    sMenu->framePalette = frame->pal;
    sMenu->tileLoadState = 0;
    CpuFill16(0, sMenu->menuWindowSpriteTiles, sizeof(sMenu->menuWindowSpriteTiles));
}

bool8 sub_811F960(void)
{
    u16 i;
    u8 *dest = sMenu->menuWindowSpriteTiles + sMenu->tileLoadState * 0x100;

    switch (sMenu->tileLoadState)
    {
    case 0:
        CpuFastCopy(sMenu->frameTiles, dest, TILE_SIZE_4BPP);
        for (i = 0; i < 6; i++)
        {
            CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP, dest + TILE_SIZE_4BPP * (i + 1), TILE_SIZE_4BPP);
        }
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 2, dest + TILE_SIZE_4BPP * 7, TILE_SIZE_4BPP);
        sMenu->tileLoadState++;
        break;
    default:
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 3, dest, TILE_SIZE_4BPP);
        for (i = 0; i < 6; i++)
        {
            CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 4, dest + TILE_SIZE_4BPP * (i + 1), TILE_SIZE_4BPP);
        }
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 5, dest + TILE_SIZE_4BPP * 7, TILE_SIZE_4BPP);
        sMenu->tileLoadState++;
        break;
    case 13:
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 6, dest, TILE_SIZE_4BPP);
        for (i = 0; i < 6; i++)
        {
            CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 7, dest + TILE_SIZE_4BPP * (i + 1), TILE_SIZE_4BPP);
        }
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 8, dest + TILE_SIZE_4BPP * 7, TILE_SIZE_4BPP);
        sMenu->tileLoadState++;
        return FALSE;
    case 14:
        return FALSE;
    }

    return TRUE;
}

void sub_811FA90(void)
{
    sub_811F918();
    while (sub_811F960());
}

void sub_811FAA4(u8 markings, s16 x, s16 y)
{
    u16 i;
    sMenu->cursorPos = 0;
    sMenu->markings = markings;
    for (i = 0; i < NUM_MON_MARKINGS; i++)
        sMenu->markingsArray[i] = (sMenu->markings >> i) & 1;
    sub_811FC80(x, y, sMenu->baseTileTag, sMenu->basePaletteTag);
}

void sub_811FAF8(void)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        FreeSpriteTilesByTag(sMenu->baseTileTag + i);
        FreeSpritePaletteByTag(sMenu->basePaletteTag + i);
    }
    for (i = 0; i < 2; i++)
    {
        if (!sMenu->menuWindowSprites[i])
            return;
        DestroySprite(sMenu->menuWindowSprites[i]);
        sMenu->menuWindowSprites[i] = NULL;
    }
    for (i = 0; i < NUM_MON_MARKINGS; i++)
    {
        if (!sMenu->menuMarkingSprites[i])
            return;
        DestroySprite(sMenu->menuMarkingSprites[i]);
        sMenu->menuMarkingSprites[i] = NULL;
    }
    if (sMenu->unkSprite)
    {
        DestroySprite(sMenu->unkSprite);
        sMenu->unkSprite = NULL;
    }
    if (sMenu->menuTextSprite)
    {
        DestroySprite(sMenu->menuTextSprite);
        sMenu->menuTextSprite = NULL;
    }
}

bool8 MonMarkingsMenuHandleInput(void)
{
    u16 i;

    if (JOY_NEW(DPAD_UP))
    {
        s8 pos;
        PlaySE(SE_SELECT);
        pos = --sMenu->cursorPos;
        if (pos < 0)
            sMenu->cursorPos = 5;
        return TRUE;
    }

    if (JOY_NEW(DPAD_DOWN))
    {
        s8 pos;
        PlaySE(SE_SELECT);
        pos = ++sMenu->cursorPos;
        if (pos > 5)
            sMenu->cursorPos = 0;
        return TRUE;
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (sMenu->cursorPos)
        {
        case 4:
            sMenu->markings = 0;
            for (i = 0; i < NUM_MON_MARKINGS; i++)
                sMenu->markings |= sMenu->markingsArray[i] << i;
            return FALSE;
        case 5:
            return FALSE;
        }

        sMenu->markingsArray[sMenu->cursorPos] = !sMenu->markingsArray[sMenu->cursorPos];
        return TRUE;
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        return FALSE;
    }

    return TRUE;
}

static void sub_811FC80(s16 x, s16 y, u16 baseTileTag, u16 basePaletteTag)
{
    u16 i;
    u8 spriteId;

    struct SpriteSheet sheets[] =
    {
        { sMenu->menuWindowSpriteTiles, 0x1000, baseTileTag },
        { gPokenavConditionMarker_Gfx, 0x320, baseTileTag + 1 },
        { NULL, 0 }
    };

    struct SpritePalette palettes[] =
    {
        { sMenu->framePalette, basePaletteTag },
        { gPokenavConditionMarker_Pal, basePaletteTag + 1},
        { NULL, 0 }
    };

    struct SpriteTemplate sprTemplate =
    {
        baseTileTag,
        basePaletteTag,
        &gUnknown_0859EE7C,
        gUnknown_0859EF14,
        NULL,
        gDummySpriteAffineAnimTable,
        TaskDummy7,
    };

    LoadSpriteSheets(sheets);
    LoadSpritePalettes(palettes);

    for (i = 0; i < 2; i++)
    {
        spriteId = CreateSprite(&sprTemplate, x + 32, y + 32, 1);
        if (spriteId != MAX_SPRITES)
        {
            sMenu->menuWindowSprites[i] = &gSprites[spriteId];
            StartSpriteAnim(&gSprites[spriteId], i);
        }
        else
        {
            sMenu->menuWindowSprites[i] = NULL;
            return;
        }
    }

    sMenu->menuWindowSprites[1]->pos1.y = y + 96;

    sprTemplate.tileTag++;
    sprTemplate.paletteTag++;
    sprTemplate.anims = gUnknown_0859EEDC;
    sprTemplate.callback = sub_811FF40;
    sprTemplate.oam = &gUnknown_0859EE84;

    for (i = 0; i < NUM_MON_MARKINGS; i++)
    {
        spriteId = CreateSprite(&sprTemplate, x + 32, y + 16 + 16 * i, 0);
        if (spriteId != MAX_SPRITES)
        {
            sMenu->menuMarkingSprites[i] = &gSprites[spriteId];
            gSprites[spriteId].data[0] = i;
        }
        else
        {
            sMenu->menuMarkingSprites[i] = NULL;
            return;
        }
    }

    sprTemplate.callback = SpriteCallbackDummy;

    spriteId = CreateSprite(&sprTemplate, 0, 0, 0);

    if (spriteId != MAX_SPRITES)
    {
        sMenu->menuTextSprite = &gSprites[spriteId];
        sMenu->menuTextSprite->oam.shape = SPRITE_SHAPE(32x32);
        sMenu->menuTextSprite->oam.size = SPRITE_SIZE(32x32);
        StartSpriteAnim(sMenu->menuTextSprite, 9);
        sMenu->menuTextSprite->pos1.x = x + MENU_TEXT_SPRITE_X_OFFSET;
        sMenu->menuTextSprite->pos1.y = y + 80;
        CalcCenterToCornerVec(sMenu->menuTextSprite, SPRITE_SHAPE(32x16), SPRITE_SIZE(32x16), ST_OAM_AFFINE_OFF);
    }
    else
    {
        sMenu->menuTextSprite = NULL;
    }

    sprTemplate.callback = sub_811FF7C;
    spriteId = CreateSprite(&sprTemplate, x + 12, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sMenu->unkSprite = &gSprites[spriteId];
        sMenu->unkSprite->data[0] = y + 16;
        StartSpriteAnim(sMenu->unkSprite, 8);
    }
    else
    {
        sMenu->unkSprite = NULL;
    }

}

static void TaskDummy7(struct Sprite *sprite)
{
}

static void sub_811FF40(struct Sprite *sprite)
{
    if (sMenu->markingsArray[sprite->data[0]])
        StartSpriteAnim(sprite, 2 * sprite->data[0] + 1);
    else
        StartSpriteAnim(sprite, 2 * sprite->data[0]);
}

static void sub_811FF7C(struct Sprite *sprite)
{
    sprite->pos1.y = (16 * sMenu->cursorPos) + sprite->data[0];
}

struct Sprite *CreateMonMarkingsSpriteWithPal(u16 tileTag, u16 paletteTag, const u16 *palette)
{
    if (!palette)
        palette = gUnknown_0859E65C;
    return sub_811FFD4(tileTag, paletteTag, palette, 16);
}

struct Sprite *sub_811FFB4(u16 tileTag, u16 paletteTag, const u16 *palette)
{
    if (!palette)
        palette = gUnknown_0859E65C;
    return sub_811FFD4(tileTag, paletteTag, palette, 1);
}

static struct Sprite *sub_811FFD4(u16 tileTag, u16 paletteTag, const u16 *palette, u16 size)
{
    u8 spriteId;
    struct SpriteTemplate sprTemplate;
    struct SpriteSheet sheet = { gUnknown_0859E67C, 0x80, tileTag };
    struct SpritePalette sprPalette = { palette, paletteTag };

    sprTemplate.tileTag = tileTag;
    sprTemplate.paletteTag = paletteTag;
    sprTemplate.oam = &gUnknown_0859EF1C;
    sprTemplate.anims = gUnknown_0859EFA4;
    sprTemplate.images = NULL;
    sprTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sprTemplate.callback = TaskDummy7;

    sheet.size = size * 0x80;

    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&sprPalette);

    spriteId = CreateSprite(&sprTemplate, 0, 0, 0);
    if (spriteId != MAX_SPRITES)
        return  &gSprites[spriteId];
    else
        return NULL;
}

void sub_8120084(u8 markings, void *dest)
{
    RequestDma3Copy(gUnknown_0859E67C + markings * 0x80, dest, 0x80, 0x10);
}
