const struct MonCoords gTrainerBackPicCoords[] =
{
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 5},
    {.size = 8, .y_offset = 5},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    (const u32 *)gTrainerBackPic_Brendan, 0x2000, TRAINER_BACK_PIC_BRENDAN,
    (const u32 *)gTrainerBackPic_May, 0x2000, TRAINER_BACK_PIC_MAY,
    (const u32 *)gTrainerBackPic_Red, 0x2800, TRAINER_BACK_PIC_RED,
    (const u32 *)gTrainerBackPic_Leaf, 0x2800, TRAINER_BACK_PIC_LEAF,
    (const u32 *)gTrainerBackPic_RubySapphireBrendan, 0x2000, TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
    (const u32 *)gTrainerBackPic_RubySapphireMay, 0x2000, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY,
    (const u32 *)gTrainerBackPic_Wally, 0x2000, TRAINER_BACK_PIC_WALLY,
    (const u32 *)gTrainerBackPic_Steven, 0x2000, TRAINER_BACK_PIC_STEVEN,
};

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] = 
{
    gTrainerPalette_Brendan, TRAINER_BACK_PIC_BRENDAN,
    gTrainerPalette_May, TRAINER_BACK_PIC_MAY,
    gTrainerBackPicPalette_Red, TRAINER_BACK_PIC_RED,
    gTrainerBackPicPalette_Leaf, TRAINER_BACK_PIC_LEAF,
    gTrainerPalette_RubySapphireBrendan, TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
    gTrainerPalette_RubySapphireMay, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY,
    gTrainerPalette_Wally, TRAINER_BACK_PIC_WALLY,
    gTrainerPalette_Steven, TRAINER_BACK_PIC_STEVEN,
};
