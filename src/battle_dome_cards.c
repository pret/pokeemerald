
// Includes
#include "global.h"
#include "sprite.h"
#include "window.h"
#include "malloc.h"
#include "species.h"
#include "palette.h"
#include "decompress.h"

extern const struct CompressedSpriteSheet gMonFrontPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gMonBackPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const union AffineAnimCmd *const gUnknown_082FF618[];
extern const union AffineAnimCmd *const gUnknown_082FF694[];
extern const union AnimCmd *const gUnknown_082FF70C[];
extern const union AnimCmd *const *const gUnknown_08309AAC[NUM_SPECIES];
extern const union AnimCmd *const *const gUnknown_0830536C[];
extern const struct OamData gUnknown_0860B064;
extern const struct OamData gUnknown_0860B06C;
extern const u8 gUnknown_0831F578[];

// Static type declarations

struct BattleDomeCard {
    u8 *frames;
    struct SpriteFrameImage *images;
    u16 paletteTag;
    u8 spriteId;
    u8 active;
};

// Static RAM declarations

static EWRAM_DATA struct SpriteTemplate gUnknown_0203CCEC = {};
EWRAM_DATA struct BattleDomeCard gUnknown_0203CD04[8] = {};

// Static ROM declarations

// .rodata

extern const struct BattleDomeCard gUnknown_0860B058;

// .text

void nullsub_122(struct Sprite *sprite)
{

}

bool16 dp13_810BB8C(void)
{
    int i;

    for (i = 0; i < 8; i ++)
    {
        gUnknown_0203CD04[i] = gUnknown_0860B058;
    }
    return FALSE;
}

bool16 load_pokemon_image_TODO(u16 species, u32 personality, bool8 isFrontPic, u8 *dest, bool8 isTrainer, bool8 ignoreDeoxys)
{
    if (!isTrainer)
    {
        if (isFrontPic)
        {
            if (!ignoreDeoxys)
            {
                LoadSpecialPokePic(&gMonFrontPicTable[species], dest, species, personality, isFrontPic);
            }
            else
            {
                LoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], dest, species, personality, isFrontPic);
            }
        }
        else
        {
            if (!ignoreDeoxys)
            {
                LoadSpecialPokePic(&gMonBackPicTable[species], dest, species, personality, isFrontPic);
            }
            else
            {
                LoadSpecialPokePic_DontHandleDeoxys(&gMonBackPicTable[species], dest, species, personality, isFrontPic);
            }
        }
    }
    else
    {
        if (isFrontPic)
        {
            DecompressPicFromTable(&gTrainerFrontPicTable[species], dest, species);
        }
        else
        {
            DecompressPicFromTable(&gTrainerBackPicTable[species], dest, species);
        }
    }
    return FALSE;
}

bool16 sub_818D09C(u16 species, u32 personality, bool8 isFrontPic, u8 *dest, bool8 isTrainer)
{
    return load_pokemon_image_TODO(species, personality, isFrontPic, dest, isTrainer, FALSE);
}

void sub_818D0C4(u16 species, u32 otId, u32 personality, u8 paletteSlot, u16 paletteTag, bool8 isTrainer)
{
    if (!isTrainer)
    {
        if (paletteTag == 0xFFFF)
        {
            gUnknown_0203CCEC.paletteTag |= 0xFFFF;
            LoadCompressedPalette(species_and_otid_get_pal(species, otId, personality), 0x100 + paletteSlot * 0x10, 0x20);
        }
        else
        {
            gUnknown_0203CCEC.paletteTag = paletteTag;
            LoadCompressedObjectPalette(sub_806E7CC(species, otId, personality));
        }
    }
    else
    {
        if (paletteTag == 0xFFFF)
        {
            gUnknown_0203CCEC.paletteTag |= 0xFFFF;
            LoadCompressedPalette(gTrainerFrontPicPaletteTable[species].data, 0x100 + paletteSlot * 0x10, 0x20);
        }
        else
        {
            gUnknown_0203CCEC.paletteTag = paletteTag;
            LoadCompressedObjectPalette(&gTrainerFrontPicPaletteTable[species]);
        }
    }
}

void sub_818D180(u16 species, u32 otId, u32 personality, u8 paletteSlot, bool8 isTrainer)
{
    if (!isTrainer)
    {
        LoadCompressedPalette(species_and_otid_get_pal(species, otId, personality), paletteSlot * 0x10, 0x20);
    }
    else
    {
        LoadCompressedPalette(gTrainerFrontPicPaletteTable[species].data, paletteSlot * 0x10, 0x20);
    }
}

void uns_builder_assign_animtable1(bool8 isTrainer)
{
    if (!isTrainer)
    {
        gUnknown_0203CCEC.anims = gUnknown_082FF70C;
    }
    else
    {
        gUnknown_0203CCEC.anims = gUnknown_0830536C[0];
    }
}

u16 oamt_spawn_poke_or_trainer_picture(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag, bool8 isTrainer, bool8 ignoreDeoxys)
{
    u8 i;
    u8 *framePics;
    struct SpriteFrameImage *images;
    int j;
    u8 spriteId;

    for (i = 0; i < 8; i ++)
    {
        if (!gUnknown_0203CD04[i].active)
        {
            break;
        }
    }
    if (i == 8)
    {
        return 0xFFFF;
    }
    framePics = Alloc(4 * 0x800);
    if (!framePics)
    {
        return 0xFFFF;
    }
    images = Alloc(4 * sizeof(struct SpriteFrameImage));
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }
    if (load_pokemon_image_TODO(species, personality, isFrontPic, framePics, isTrainer, ignoreDeoxys))
    {
        // debug trap?
        return 0xFFFF;
    }
    for (j = 0; j < 4; j ++)
    {
        images[j].data = framePics + 0x800 * j;
        images[j].size = 0x800;
    }
    gUnknown_0203CCEC.tileTag = 0xFFFF;
    gUnknown_0203CCEC.oam = &gUnknown_0860B064;
    uns_builder_assign_animtable1(isTrainer);
    gUnknown_0203CCEC.images = images;
    gUnknown_0203CCEC.affineAnims = gDummySpriteAffineAnimTable;
    gUnknown_0203CCEC.callback = nullsub_122;
    sub_818D0C4(species, otId, personality, paletteSlot, paletteTag, isTrainer);
    spriteId = CreateSprite(&gUnknown_0203CCEC, x, y, 0);
    if (paletteTag == 0xFFFF)
    {
        gSprites[spriteId].oam.paletteNum = paletteSlot;
    }
    gUnknown_0203CD04[i].frames = framePics;
    gUnknown_0203CD04[i].images = images;
    gUnknown_0203CD04[i].paletteTag = paletteTag;
    gUnknown_0203CD04[i].spriteId = spriteId;
    gUnknown_0203CD04[i].active = TRUE;
    return spriteId;
}

u16 sub_818D384(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag, bool8 isTrainer)
{
    return oamt_spawn_poke_or_trainer_picture(species, otId, personality, isFrontPic, x, y, paletteSlot, paletteTag, isTrainer, FALSE);
}

u16 sub_818D3E4(u16 species, u32 otId, u32 personality, u8 flags, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u8 *framePics;
    struct SpriteFrameImage *images;
    int j;
    u8 i;
    u8 spriteId;
    u8 flags2;

    for (i = 0; i < 8; i ++)
    {
        if (!gUnknown_0203CD04[i].active)
        {
            break;
        }
    }
    if (i == 8)
    {
        return 0xFFFF;
    }
    framePics = Alloc(4 * 0x800);
    if (!framePics)
    {
        return 0xFFFF;
    }
    if (flags & 0x80)
    {
        flags &= 0x7F;
        flags2 = 3;
    }
    else
    {
        flags2 = flags;
    }
    images = Alloc(4 * sizeof(struct SpriteFrameImage));
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }
    if (load_pokemon_image_TODO(species, personality, flags, framePics, FALSE, FALSE))
    {
        // debug trap?
        return 0xFFFF;
    }
    for (j = 0; j < 4; j ++)
    {
        images[j].data = framePics + 0x800 * j;
        images[j].size = 0x800;
    }
    gUnknown_0203CCEC.tileTag = 0xFFFF;
    gUnknown_0203CCEC.anims = gUnknown_08309AAC[species];
    gUnknown_0203CCEC.images = images;
    if (flags2 == 0x01)
    {
        gUnknown_0203CCEC.affineAnims = gUnknown_082FF694;
        gUnknown_0203CCEC.oam = &gUnknown_0860B06C;
    }
    else if (flags2 == 0x00)
    {
        gUnknown_0203CCEC.affineAnims = gUnknown_082FF618;
        gUnknown_0203CCEC.oam = &gUnknown_0860B06C;
    }
    else
    {
        gUnknown_0203CCEC.oam = &gUnknown_0860B064;
        gUnknown_0203CCEC.affineAnims = gDummySpriteAffineAnimTable;
    }
    gUnknown_0203CCEC.callback = nullsub_122;
    sub_818D0C4(species, otId, personality, paletteSlot, paletteTag, FALSE);
    spriteId = CreateSprite(&gUnknown_0203CCEC, x, y, 0);
    if (paletteTag == 0xFFFF)
    {
        gSprites[spriteId].oam.paletteNum = paletteSlot;
    }
    gUnknown_0203CD04[i].frames = framePics;
    gUnknown_0203CD04[i].images = images;
    gUnknown_0203CD04[i].paletteTag = paletteTag;
    gUnknown_0203CD04[i].spriteId = spriteId;
    gUnknown_0203CD04[i].active = TRUE;
    return spriteId;
}

u16 sub_818D5B0(u16 spriteId)
{
    u8 i;
    u8 *framePics;
    struct SpriteFrameImage *images;

    for (i = 0; i < 8; i ++)
    {
        if (gUnknown_0203CD04[i].spriteId == spriteId)
        {
            break;
        }
    }
    if (i == 8)
    {
        return 0xFFFF;
    }
    framePics = gUnknown_0203CD04[i].frames;
    images = gUnknown_0203CD04[i].images;
    if (gUnknown_0203CD04[i].paletteTag != 0xFFFF)
    {
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[spriteId].oam.paletteNum));
    }
    DestroySprite(&gSprites[spriteId]);
    Free(framePics);
    Free(images);
    gUnknown_0203CD04[i] = gUnknown_0860B058;
    return 0;
}

u16 sub_818D65C(u16 species, u32 otId, u32 personality, bool8 isFrontPic, u8 paletteSlot, u8 windowId, bool8 isTrainer)
{
    if (sub_818D09C(species, personality, isFrontPic, (u8 *)GetWindowAttribute(windowId, WINDOW_TILE_DATA), FALSE))
    {
        return 0xFFFF;
    }
    sub_818D180(species, otId, personality, paletteSlot, isTrainer);
    return 0;
}

u16 sub_818D6CC(u16 species, u32 otId, u32 personality, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId, bool8 isTrainer)
{
    u8 *framePics;

    framePics = Alloc(4 * 0x800);
    if (framePics && !sub_818D09C(species, personality, isFrontPic, framePics, isTrainer))
    {
        BlitBitmapRectToWindow(windowId, framePics, 0, 0, 0x40, 0x40, destX, destY, 0x40, 0x40);
        sub_818D180(species, otId, personality, paletteSlot, isTrainer);
        Free(framePics);
        return 0;
    }
    return 0xFFFF;
}

u16 sub_818D778(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag, bool8 ignoreDeoxys)
{
    return oamt_spawn_poke_or_trainer_picture(species, otId, personality, isFrontPic, x, y, paletteSlot, paletteTag, FALSE, ignoreDeoxys);
}

u16 sub_818D7D8(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    return sub_818D778(species, otId, personality, isFrontPic, x, y, paletteSlot, paletteTag, FALSE);
}

u16 sub_818D820(u16 spriteId)
{
    return sub_818D5B0(spriteId);
}

u16 sub_818D834(u16 species, u32 otId, u32 personality, bool8 isFrontPic, u8 paletteSlot, u8 windowId)
{
    return sub_818D65C(species, otId, personality, isFrontPic, paletteSlot, windowId, FALSE);
}

u16 sub_818D864(u16 species, u32 otId, u32 personality, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId)
{
    return sub_818D6CC(species, otId, personality, isFrontPic, destX, destY, paletteSlot, windowId, FALSE);
}

u16 sub_818D8AC(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    return sub_818D384(species, 0, 0, isFrontPic, x, y, paletteSlot, paletteTag, TRUE);
}

u16 sub_818D8F0(u16 spriteId)
{
    return sub_818D5B0(spriteId);
}

u16 sub_818D904(u16 species, bool8 isFrontPic, u8 paletteSlot, u8 windowId)
{
    return sub_818D65C(species, 0, 0, isFrontPic, paletteSlot, windowId, TRUE);
}

u16 sub_818D938(u16 species, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId)
{
    return sub_818D6CC(species, 0, 0, isFrontPic, destX, destY, paletteSlot, windowId, TRUE);
}

//u8 sub_818D97C(u8 a0, u8 a1)
//{
//    u8 id;
//    if (a1 == 1 && a0)
//    {
//        id = gUnknown_0831F578[0x3F];
//    }
//    else
//    {
//        id = gUnknown_0831F578[0x3C];
//    }
//    return id;
//}
