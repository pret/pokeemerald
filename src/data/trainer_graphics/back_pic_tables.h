const struct MonCoords gTrainerBackPicCoords[] =
{
    {8, 4},
    {8, 4},
    {8, 5},
    {8, 5},
    {8, 4},
    {8, 4},
    {8, 4},
    {8, 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    (const u32 *)gTrainerBackPic_Brendan, 0x2000, 0,
    (const u32 *)gTrainerBackPic_May, 0x2000, 1,
    (const u32 *)gTrainerBackPic_Red, 0x2800, 2,
    (const u32 *)gTrainerBackPic_Leaf, 0x2800, 3,
    (const u32 *)gTrainerBackPic_RubySapphireBrendan, 0x2000, 4,
    (const u32 *)gTrainerBackPic_RubySapphireMay, 0x2000, 5,
    (const u32 *)gTrainerBackPic_Wally, 0x2000, 6,
    (const u32 *)gTrainerBackPic_Steven, 0x2000, 7,
};

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] = 
{
    gTrainerPalette_Brendan, 0,
    gTrainerPalette_May, 1,
    gTrainerBackPicPalette_Red, 2,
    gTrainerBackPicPalette_Leaf, 3,
    gTrainerPalette_RubySapphireBrendan, 4,
    gTrainerPalette_RubySapphireMay, 5,
    gTrainerPalette_Wally, 6,
    gTrainerPalette_Steven, 7,
};
