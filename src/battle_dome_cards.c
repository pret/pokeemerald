
// Includes
#include "global.h"
#include "sprite.h"
#include "malloc.h"
#include "species.h"
#include "palette.h"
#include "decompress.h"

extern const struct CompressedSpriteSheet gMonFrontPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gMonBackPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const union AnimCmd *const gUnknown_082FF70C[];
extern const union AnimCmd *const *const gUnknown_0830536C[];
extern const struct OamData gUnknown_0860B064;
extern const struct OamData gUnknown_0860B06C;
extern const union AnimCmd *const *const gUnknown_08309AAC[NUM_SPECIES];
extern const union AffineAnimCmd *const gUnknown_082FF694[];
extern const union AffineAnimCmd *const gUnknown_082FF618[];

// Static type declarations

struct BattleDomeCard {
    u8 *frames;
    const struct SpriteFrameImage *images;
    u16 paletteTag;
    u8 spriteId;
    u8 active;
};

// Static RAM declarations

extern struct BattleDomeCard gUnknown_0203CD04[8];
extern struct SpriteTemplate gUnknown_0203CCEC;

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

bool16 load_pokemon_image_TODO(u16 species, u32 personality, bool8 isFrontPic, void *dest, bool8 isTrainer, bool8 ignoreDeoxys)
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

bool16 sub_818D09C(u16 species, u32 personality, bool8 isFrontPic, void *dest, bool8 isTrainer)
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
