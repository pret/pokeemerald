
// Includes
#include "global.h"
#include "sprite.h"
#include "species.h"
#include "pokemon.h"
#include "decompress.h"

extern const struct CompressedSpriteSheet gMonFrontPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gMonBackPicTable[NUM_SPECIES];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[];

// Static type declarations

struct BattleDomeCard {
    u8 unk_00[12];
};

// Static RAM declarations

extern struct BattleDomeCard gUnknown_0203CD04[8];

// Static ROM declarations

// .rodata

extern const struct BattleDomeCard gUnknown_0860B058;

// .text

void nullsub_122(struct Sprite *sprite)
{

}

bool8 dp13_810BB8C(void)
{
    int i;

    for (i = 0; i < 8; i ++)
    {
        gUnknown_0203CD04[i] = gUnknown_0860B058;
    }
    return FALSE;
}

bool8 load_pokemon_image_TODO(u16 species, u32 personality, bool8 isFrontPic, void *dest, bool8 isTrainer, bool8 ignoreDeoxys)
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
