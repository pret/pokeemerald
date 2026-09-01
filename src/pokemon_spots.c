#include "global.h"
#include "assertf.h"
#include "constants/species.h"
#include "pokemon.h"
#include "pokemon_spots.h"

/* INFO: DrawPokemonSpots
 *
 * This function handles drawing the randomly-placed spots on a Pokemon's front sprite.
 * This is used by default to draw Spinda's spots.
 *
 * A pokemon can have upto 4 spots, defined in this file. Each entry is a MonSpotTemplate which contains
 * an array of spots and some shared data. Each spot is a 1bpp image paired with a base (x,y) coordinate
 *
 * Each bit in the image determines whether that pixel should be considered part of the spot.
 *
 * The position of each spot is randomized using the Pokemon's personality. One byte of the personality
 * is used to for each spot (one nibble for one coordinate).
 *
 * Thus for a pokemon that uses four spots,The entire 32 bit personality value is used.
 *
 * The personality is read from right to left as the left-most digits are used for gender and nature.
 * For instance, for single-spotted pokemon, the right-most digits are first. 
 * This is preferable as those are more independant
 *
 * If the personality value is 0x87654321, then:
 * - 0x1 will be used for the 4th spot's x coord,
 * - 0x2 will be used for the 4th spot's y coord,
 * - 0x3 will be used for the 3rd spot's x coord, and so on.
 *
 * Each coordinate is calculated as (baseCoord + (given personality nible) - size/2).
 *
 * The function then loops over the 16x16 spot image. For each bit in the spot's binary image, if
 * the bit is set then it's part of the spot; try to draw it. A pixel is drawn on Pokemon if the
 * pixel is between firstColor and lastColor (defined in the MonSpotTemplate). The spot is drawn by
 * incrementing the color index by the colorAdjust.
 *
 * In Spinda's case these color indexes are Spinda's light brown body colors. To create
 * the spot it adds 4 to the color index, so Spinda's spots will be colors 5, 6, and 7.
 *
 * The above is done in TryDrawSpotPixel in two different ways: one with << 4, and one without.
 * This is because Pokemon sprites are 4bpp images, but the pointer to Spinda's pixels
 * (destPixels) is an 8 bit pointer, so it addresses two pixels. Shifting by 4 accesses the 2nd
 * of these pixels, so this is done every other time.
 */

#define EVEN_PIXEL_SHIFT 0
#define ODD_PIXEL_SHIFT 4
#define FRAME_SIZE 64

#define NIBBLE_LOWER 0x0F
#define NIBBLE_UPPER 0xF0

typedef u32 SpotImage8[2];
typedef u32 SpotImage16[8];
typedef u32 SpotImage32[32];

enum SpotAnimFrame {
    FRAME_1,
    FRAME_2
};

enum SpotScale
{
    SCALE_1 = 1,
    SCALE_2 = 2,
    SCALE_4 = 4
};

struct MonSpot {
    u8 x, y;
    const u32* image;
};

struct MonSpotTemplate {
    const struct MonSpot* spots;
    u8 count;
    enum SpotScale scale;
    s8 xOffsetFrame2;
    s8 yOffsetFrame2;
    u8 firstColor;
    u8 lastColor;
    u8 colorAdjust;
};

// Static Functions
static void DrawPokemonSpots(u32 personality, const struct MonSpotTemplate* spotTemplate, u8 *dest, enum SpotAnimFrame SpotAnimFrame);
static const struct MonSpotTemplate* GetSpeciesSpots(enum Species species);
static inline void TryDrawSpotPixel(u8* pixels, u8 pixelShift, u8 firstColor, u8 lastColor, u8 spotColorAdjust);
static inline u32 CoordToByteOffset(u32 x, u32 y);
static inline u32 GetSpotRow(const u32* image, u32 row, enum SpotScale scale);

/*NOTE: Define Spots Below */

// SPECIES_SPINDA
static const SpotImage16 sSpindaSpotImages[4] = {
    INCGFX_U32("graphics/pokemon/spinda/spots/spot_0.png", ".1bpp", "-plain -data_width 2"),
    INCGFX_U32("graphics/pokemon/spinda/spots/spot_1.png", ".1bpp", "-plain -data_width 2"),
    INCGFX_U32("graphics/pokemon/spinda/spots/spot_2.png", ".1bpp", "-plain -data_width 2"),
    INCGFX_U32("graphics/pokemon/spinda/spots/spot_3.png", ".1bpp", "-plain -data_width 2"),
};
//NOTE: Spinda spots have been ordered in reverse for save compatibility
static const struct MonSpot sSpindaSpots[] = {
    {.x = 34, .y = 26, .image = sSpindaSpotImages[3]},
    {.x = 22, .y = 27, .image = sSpindaSpotImages[2]},
    {.x = 40, .y = 8, .image = sSpindaSpotImages[1]},
    {.x = 16, .y = 7, .image = sSpindaSpotImages[0]},
};
const struct MonSpotTemplate gSpindaSpotTemplate = {
    .spots = sSpindaSpots,
    .count = ARRAY_COUNT(sSpindaSpots),
    .scale = SCALE_2,
    .xOffsetFrame2 = -4,
    .yOffsetFrame2 = 0,
    .firstColor = 1,
    .lastColor = 3,
    .colorAdjust = 4,
};

/*NOTE: End of Spot Defintions */

static const struct MonSpotTemplate* GetSpeciesSpots(enum Species species)
{
    switch (species)
    {
    case SPECIES_SPINDA:
            return &gSpindaSpotTemplate;
    default:
        return NULL;
    }
}

static inline void TryDrawSpotPixel(u8* pixels, u8 pixelShift, u8 firstColor, u8 lastColor, u8 spotColorAdjust)
{
    u8 pixel = (*pixels >> pixelShift) & 0xF;
    if (firstColor <= pixel && pixel <= lastColor)
        *pixels += (spotColorAdjust << pixelShift);
}

static inline u32 CoordToByteOffset(u32 x, u32 y)
{
    return ((x / 8) * TILE_SIZE_4BPP)
         + ((x % 8) / 2)
         + ((y / 8) * TILE_SIZE_4BPP * 8)
         + ((y % 8) * 4);
}

bool32 ShouldDrawSpotsOnSpecies(enum Species species)
{
    return GetSpeciesSpots(species) != NULL;
}

static inline u32 GetSpotRow(const u32* image, u32 row, enum SpotScale scale)
{
    switch (scale)
    {
    case SCALE_1:
        return (image[row / 4] >> ((row % 4) * 8)) & 0xFF;
    case SCALE_2:
        return (image[row / 2] >> ((row % 2) * 16)) & 0xFFFF;
    case SCALE_4:
        return image[row];
    default:
        errorf("scale %d not in enum SpotScale", scale);
        return 0;
    }
}

static void DrawPokemonSpots(u32 personality, const struct MonSpotTemplate* spotTemplate, u8* dest,
                             enum SpotAnimFrame spotAnimFrame)
{
    u8 size = 8 * spotTemplate->scale;  // NOTE: We only expect square spots

    for (u32 i = 0; i < spotTemplate->count; i++)
    {
        const struct MonSpot* spot = &spotTemplate->spots[i];

        u8 pidByteForSpot = personality >> (8 * (3 - i));
        u8 pidLowerNibble = pidByteForSpot & NIBBLE_LOWER;
        u8 pidUpperNibble = (pidByteForSpot & NIBBLE_UPPER) >> 4;

        s32 x = spot->x + pidLowerNibble * (spotTemplate->scale / 2);
        s32 y = spot->y + pidUpperNibble * (spotTemplate->scale / 2);

        switch (spotAnimFrame)
        {
        case FRAME_1:
            x -= size / 2;
            y -= size / 2;
            break;

        case FRAME_2:
            x += spotTemplate->xOffsetFrame2 - size / 2;
            y += FRAME_SIZE + spotTemplate->yOffsetFrame2 - size / 2;
            break;

        default:
            break;
        }

        // INFO: This loop draws the spot
        for (u32 i = 0; i < size; i++)
        {
            u32 spotPixelRow = GetSpotRow(spot->image, i, spotTemplate->scale);
            s32 row = y + i;

            //INFO: This loop draws one row
            for (u32 j = 0; j < size; j++)
            {
                u32 bit = (spotPixelRow >> j) & 1;
                if (bit)
                {
                    s32 col = x + j;
                    if (col < 0 || col >= MON_PIC_WIDTH
                     || row < 0 || row >= MON_PIC_HEIGHT * MAX_MON_PIC_FRAMES)
                        continue;

                    u8* destPixels = dest + CoordToByteOffset(col, row);

                    u8 shift = (col & 1) ? ODD_PIXEL_SHIFT : EVEN_PIXEL_SHIFT;

                    TryDrawSpotPixel(destPixels, shift, spotTemplate->firstColor, spotTemplate->lastColor,
                                     spotTemplate->colorAdjust);
                }
            }
        }
    }
}

void DrawPokemonSpotsBothFrames(u32 personality, enum Species species, u8 *dest)
{
    const struct MonSpotTemplate* spotTemplate = GetSpeciesSpots(species);
    DrawPokemonSpots(personality, spotTemplate, dest, FRAME_1);
    DrawPokemonSpots(personality, spotTemplate, dest, FRAME_2);
}
