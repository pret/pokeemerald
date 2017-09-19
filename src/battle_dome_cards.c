
// Includes
#include "global.h"
#include "sprite.h"
#include "species.h"
#include "palette.h"
#include "decompress.h"

extern const struct CompressedSpriteSheet gMonFrontPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gMonBackPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];

// Static type declarations

struct BattleDomeCard {
    u8 unk_00[12];
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
