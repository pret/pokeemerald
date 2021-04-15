enum {
    WALLPAPER_FOREST,
    WALLPAPER_CITY,
    WALLPAPER_DESERT,
    WALLPAPER_SAVANNA,
    WALLPAPER_CRAG,
    WALLPAPER_VOLCANO,
    WALLPAPER_SNOW,
    WALLPAPER_CAVE,
    WALLPAPER_BEACH,
    WALLPAPER_SEAFLOOR,
    WALLPAPER_RIVER,
    WALLPAPER_SKY,
    WALLPAPER_POLKADOT,
    WALLPAPER_POKECENTER,
    WALLPAPER_MACHINE,
    WALLPAPER_PLAIN,
    WALLPAPER_FRIENDS, // The one received as a gift from Walda's parents.
    WALLPAPER_COUNT
};
#define MAX_DEFAULT_WALLPAPER WALLPAPER_SAVANNA

static const u16 sWallpaperPalettes_Forest[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/forest_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/forest_bg.gbapal"),
};
static const u32 sWallpaperTiles_Forest[] = INCBIN_U32("graphics/pokemon_storage/forest.4bpp.lz");
static const u32 sWallpaperTilemap_Forest[] = INCBIN_U32("graphics/pokemon_storage/forest.bin.lz");

static const u16 sWallpaperPalettes_City[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/city_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/city_bg.gbapal"),
};
static const u32 sWallpaperTiles_City[] = INCBIN_U32("graphics/pokemon_storage/city.4bpp.lz");
static const u32 sWallpaperTilemap_City[] = INCBIN_U32("graphics/pokemon_storage/city.bin.lz");

static const u16 sWallpaperPalettes_Desert[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/desert_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/desert_bg.gbapal"),
};
static const u32 sWallpaperTiles_Desert[] = INCBIN_U32("graphics/pokemon_storage/desert.4bpp.lz");
static const u32 sWallpaperTilemap_Desert[] = INCBIN_U32("graphics/pokemon_storage/desert.bin.lz");

static const u16 sWallpaperPalettes_Savanna[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/savanna_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/savanna_bg.gbapal"),
};
static const u32 sWallpaperTiles_Savanna[] = INCBIN_U32("graphics/pokemon_storage/savanna.4bpp.lz");
static const u32 sWallpaperTilemap_Savanna[] = INCBIN_U32("graphics/pokemon_storage/savanna.bin.lz");

static const u16 sWallpaperPalettes_Crag[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/crag_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/crag_bg.gbapal"),
};
static const u32 sWallpaperTiles_Crag[] = INCBIN_U32("graphics/pokemon_storage/crag.4bpp.lz");
static const u32 sWallpaperTilemap_Crag[] = INCBIN_U32("graphics/pokemon_storage/crag.bin.lz");

static const u16 sWallpaperPalettes_Volcano[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/volcano_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/volcano_bg.gbapal"),
};
static const u32 sWallpaperTiles_Volcano[] = INCBIN_U32("graphics/pokemon_storage/volcano.4bpp.lz");
static const u32 sWallpaperTilemap_Volcano[] = INCBIN_U32("graphics/pokemon_storage/volcano.bin.lz");

static const u16 sWallpaperPalettes_Snow[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/snow_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/snow_bg.gbapal"),
};
static const u32 sWallpaperTiles_Snow[] = INCBIN_U32("graphics/pokemon_storage/snow.4bpp.lz");
static const u32 sWallpaperTilemap_Snow[] = INCBIN_U32("graphics/pokemon_storage/snow.bin.lz");

static const u16 sWallpaperPalettes_Cave[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/cave_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/cave_bg.gbapal"),
};
static const u32 sWallpaperTiles_Cave[] = INCBIN_U32("graphics/pokemon_storage/cave.4bpp.lz");
static const u32 sWallpaperTilemap_Cave[] = INCBIN_U32("graphics/pokemon_storage/cave.bin.lz");

static const u16 sWallpaperPalettes_Beach[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/beach_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/beach_bg.gbapal"),
};
static const u32 sWallpaperTiles_Beach[] = INCBIN_U32("graphics/pokemon_storage/beach.4bpp.lz");
static const u32 sWallpaperTilemap_Beach[] = INCBIN_U32("graphics/pokemon_storage/beach.bin.lz");

static const u16 sWallpaperPalettes_Seafloor[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/seafloor_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/seafloor_bg.gbapal"),
};
static const u32 sWallpaperTiles_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/seafloor.4bpp.lz");
static const u32 sWallpaperTilemap_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/seafloor.bin.lz");

static const u16 sWallpaperPalettes_River[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/river_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/river_bg.gbapal"),
};
static const u32 sWallpaperTiles_River[] = INCBIN_U32("graphics/pokemon_storage/river.4bpp.lz");
static const u32 sWallpaperTilemap_River[] = INCBIN_U32("graphics/pokemon_storage/river.bin.lz");
static const u16 sWallpaperPalettes_Sky[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/sky_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/sky_bg.gbapal"),
};
static const u32 sWallpaperTiles_Sky[] = INCBIN_U32("graphics/pokemon_storage/sky.4bpp.lz");
static const u32 sWallpaperTilemap_Sky[] = INCBIN_U32("graphics/pokemon_storage/sky.bin.lz");

static const u16 sWallpaperPalettes_PolkaDot[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/polkadot_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/polkadot_bg.gbapal"),
};
static const u32 sWallpaperTiles_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/polkadot.4bpp.lz");
static const u32 sWallpaperTilemap_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/polkadot.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/pokecenter_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/pokecenter_bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/pokecenter.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/pokecenter.bin.lz");

static const u16 sWallpaperPalettes_Machine[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/machine_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/machine_bg.gbapal"),
};
static const u32 sWallpaperTiles_Machine[] = INCBIN_U32("graphics/pokemon_storage/machine.4bpp.lz");
static const u32 sWallpaperTilemap_Machine[] = INCBIN_U32("graphics/pokemon_storage/machine.bin.lz");

static const u16 sWallpaperPalettes_Plain[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/plain_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/plain_bg.gbapal"),
};
static const u32 sWallpaperTiles_Plain[] = INCBIN_U32("graphics/pokemon_storage/plain.4bpp.lz");
static const u32 sWallpaperTilemap_Plain[] = INCBIN_U32("graphics/pokemon_storage/plain.bin.lz");

// 12x18 tilemap
static const u32 gUnknown_085773C4[] = INCBIN_U32("graphics/unused/tilemap_5773C4.bin");

// Shadow color, text color
static const u16 sBoxTitleColors[WALLPAPER_COUNT][2] =
{
    [WALLPAPER_FOREST]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CITY]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_DESERT]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SAVANNA]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CRAG]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_VOLCANO]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SNOW]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CAVE]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_BEACH]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SEAFLOOR]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_RIVER]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SKY]        = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POLKADOT]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POKECENTER] = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_MACHINE]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_PLAIN]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_FRIENDS]    = {RGB(7, 7, 7), RGB_WHITE}
};

#define WALLPAPER_ENTRY(name) {sWallpaperTiles_##name, sWallpaperTilemap_##name, sWallpaperPalettes_##name[0]}
// A few wallpapers are not defined in this file
#define WALLPAPER_ENTRY_G(name) {gWallpaperTiles_##name, gWallpaperTilemap_##name, gWallpaperPalettes_##name[0]}

static const struct Wallpaper sWallpapers[WALLPAPER_COUNT - 1] =
{
    [WALLPAPER_FOREST]     = WALLPAPER_ENTRY(Forest),
    [WALLPAPER_CITY]       = WALLPAPER_ENTRY(City),
    [WALLPAPER_DESERT]     = WALLPAPER_ENTRY(Desert),
    [WALLPAPER_SAVANNA]    = WALLPAPER_ENTRY(Savanna),
    [WALLPAPER_CRAG]       = WALLPAPER_ENTRY(Crag),
    [WALLPAPER_VOLCANO]    = WALLPAPER_ENTRY(Volcano),
    [WALLPAPER_SNOW]       = WALLPAPER_ENTRY(Snow),
    [WALLPAPER_CAVE]       = WALLPAPER_ENTRY(Cave),
    [WALLPAPER_BEACH]      = WALLPAPER_ENTRY(Beach),
    [WALLPAPER_SEAFLOOR]   = WALLPAPER_ENTRY(Seafloor),
    [WALLPAPER_RIVER]      = WALLPAPER_ENTRY(River),
    [WALLPAPER_SKY]        = WALLPAPER_ENTRY(Sky),
    [WALLPAPER_POLKADOT]   = WALLPAPER_ENTRY(PolkaDot),
    [WALLPAPER_POKECENTER] = WALLPAPER_ENTRY(Pokecenter),
    [WALLPAPER_MACHINE]    = WALLPAPER_ENTRY(Machine),
    [WALLPAPER_PLAIN]      = WALLPAPER_ENTRY(Plain),
};

static const u8 sArrow_Gfx[] = INCBIN_U8("graphics/pokemon_storage/arrow.4bpp");

static const u16 sWallpaperPalettes_Zigzagoon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/zigzagoon_bg.gbapal"),
};
static const u32 sWallpaperTiles_Zigzagoon[]   = INCBIN_U32("graphics/pokemon_storage/zigzagoon.4bpp.lz");
static const u32 sWallpaperTilemap_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/zigzagoon.bin.lz");

static const u16 sWallpaperPalettes_Screen[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/screen_bg.gbapal"),
};
static const u32 sWallpaperTiles_Screen[]   = INCBIN_U32("graphics/pokemon_storage/screen.4bpp.lz");
static const u32 sWallpaperTilemap_Screen[] = INCBIN_U32("graphics/pokemon_storage/screen.bin.lz");

static const u16 sWallpaperPalettes_Diagonal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/diagonal_bg.gbapal"),
};
static const u32 sWallpaperTiles_Diagonal[]   = INCBIN_U32("graphics/pokemon_storage/diagonal.4bpp.lz");
static const u32 sWallpaperTilemap_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/diagonal.bin.lz");

static const u16 sWallpaperPalettes_Block[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/block_bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/block_bg.gbapal"),
};
static const u32 sWallpaperTiles_Block[]   = INCBIN_U32("graphics/pokemon_storage/block.4bpp.lz");
static const u32 sWallpaperTilemap_Block[] = INCBIN_U32("graphics/pokemon_storage/block.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter2[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/pokecenter2_bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/pokecenter2_bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter2[]   = INCBIN_U32("graphics/pokemon_storage/pokecenter2.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/pokecenter2.bin.lz");

static const u16 sWallpaperPalettes_Frame[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/frame_bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/frame_bg.gbapal"),
};
static const u32 sWallpaperTiles_Frame[]   = INCBIN_U32("graphics/pokemon_storage/frame.4bpp.lz");
static const u32 sWallpaperTilemap_Frame[] = INCBIN_U32("graphics/pokemon_storage/frame.bin.lz");

static const u16 sWallpaperPalettes_Blank[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/zigzagoon_bg.gbapal"),
};
static const u32 sWallpaperTiles_Blank[]   = INCBIN_U32("graphics/pokemon_storage/blank.4bpp.lz");
static const u32 sWallpaperTilemap_Blank[] = INCBIN_U32("graphics/pokemon_storage/blank.bin.lz");

static const u16 sWallpaperPalettes_Circles[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/circles_bg.gbapal"),
};
static const u32 sWallpaperTiles_Circles[]   = INCBIN_U32("graphics/pokemon_storage/circles.4bpp.lz");
static const u32 sWallpaperTilemap_Circles[] = INCBIN_U32("graphics/pokemon_storage/circles.bin.lz");

static const u16 sWallpaperPalettes_Azumarill[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/azumarill_bg.gbapal"),
};
static const u32 sWallpaperTiles_Azumarill[]   = INCBIN_U32("graphics/pokemon_storage/azumarill.4bpp.lz");
static const u32 sWallpaperTilemap_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/azumarill.bin.lz");

static const u16 sWallpaperPalettes_Pikachu[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/pikachu_bg.gbapal"),
};
static const u32 sWallpaperTiles_Pikachu[]   = INCBIN_U32("graphics/pokemon_storage/pikachu.4bpp.lz");
static const u32 sWallpaperTilemap_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/pikachu.bin.lz");

static const u16 sWallpaperPalettes_Legendary[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/legendary_bg.gbapal"),
};
static const u32 sWallpaperTiles_Legendary[]   = INCBIN_U32("graphics/pokemon_storage/legendary.4bpp.lz");
static const u32 sWallpaperTilemap_Legendary[] = INCBIN_U32("graphics/pokemon_storage/legendary.bin.lz");

static const u16 sWallpaperPalettes_Dusclops[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/dusclops_bg.gbapal"),
};
static const u32 sWallpaperTiles_Dusclops[]   = INCBIN_U32("graphics/pokemon_storage/dusclops.4bpp.lz");
static const u32 sWallpaperTilemap_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/dusclops.bin.lz");

static const u16 sWallpaperPalettes_Ludicolo[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/ludicolo_bg.gbapal"),
};
static const u32 sWallpaperTiles_Ludicolo[]   = INCBIN_U32("graphics/pokemon_storage/ludicolo.4bpp.lz");
static const u32 sWallpaperTilemap_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/ludicolo.bin.lz");

static const u16 sWallpaperPalettes_Whiscash[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/whiscash_bg.gbapal"),
};
static const u32 sWallpaperTiles_Whiscash[]   = INCBIN_U32("graphics/pokemon_storage/whiscash.4bpp.lz");
static const u32 sWallpaperTilemap_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/whiscash.bin.lz");

static const u32 sWallpaperIcon_Aqua[]         = INCBIN_U32("graphics/pokemon_storage/aqua_icon.4bpp.lz");
static const u32 sWallpaperIcon_Heart[]        = INCBIN_U32("graphics/pokemon_storage/heart_icon.4bpp.lz");
static const u32 sWallpaperIcon_FiveStar[]     = INCBIN_U32("graphics/pokemon_storage/five_star_icon.4bpp.lz");
static const u32 sWallpaperIcon_Brick[]        = INCBIN_U32("graphics/pokemon_storage/brick_icon.4bpp.lz");
static const u32 sWallpaperIcon_FourStar[]     = INCBIN_U32("graphics/pokemon_storage/four_star_icon.4bpp.lz");
static const u32 sWallpaperIcon_Asterisk[]     = INCBIN_U32("graphics/pokemon_storage/asterisk_icon.4bpp.lz");
static const u32 sWallpaperIcon_Dot[]          = INCBIN_U32("graphics/pokemon_storage/dot_icon.4bpp.lz");
static const u32 sWallpaperIcon_LineCircle[]   = INCBIN_U32("graphics/pokemon_storage/line_circle_icon.4bpp.lz");
static const u32 sWallpaperIcon_PokeBall[]     = INCBIN_U32("graphics/pokemon_storage/pokeball_icon.4bpp.lz");
static const u32 sWallpaperIcon_Maze[]         = INCBIN_U32("graphics/pokemon_storage/maze_icon.4bpp.lz");
static const u32 sWallpaperIcon_Footprint[]    = INCBIN_U32("graphics/pokemon_storage/footprint_icon.4bpp.lz");
static const u32 sWallpaperIcon_BigAsterisk[]  = INCBIN_U32("graphics/pokemon_storage/big_asterisk_icon.4bpp.lz");
static const u32 sWallpaperIcon_Circle[]       = INCBIN_U32("graphics/pokemon_storage/circle_icon.4bpp.lz");
static const u32 sWallpaperIcon_Koffing[]      = INCBIN_U32("graphics/pokemon_storage/koffing_icon.4bpp.lz");
static const u32 sWallpaperIcon_Ribbon[]       = INCBIN_U32("graphics/pokemon_storage/ribbon_icon.4bpp.lz");
static const u32 sWallpaperIcon_FourCircles[]  = INCBIN_U32("graphics/pokemon_storage/four_circles_icon.4bpp.lz");
static const u32 sWallpaperIcon_Lotad[]        = INCBIN_U32("graphics/pokemon_storage/lotad_icon.4bpp.lz");
static const u32 sWallpaperIcon_Crystal[]      = INCBIN_U32("graphics/pokemon_storage/crystal_icon.4bpp.lz");
static const u32 sWallpaperIcon_Pichu[]        = INCBIN_U32("graphics/pokemon_storage/pichu_icon.4bpp.lz");
static const u32 sWallpaperIcon_Diglett[]      = INCBIN_U32("graphics/pokemon_storage/diglett_icon.4bpp.lz");
static const u32 sWallpaperIcon_Luvdisc[]      = INCBIN_U32("graphics/pokemon_storage/luvdisc_icon.4bpp.lz");
static const u32 sWallpaperIcon_StarInCircle[] = INCBIN_U32("graphics/pokemon_storage/star_in_circle_icon.4bpp.lz");
static const u32 sWallpaperIcon_Spinda[]       = INCBIN_U32("graphics/pokemon_storage/spinda_icon.4bpp.lz");
static const u32 sWallpaperIcon_Latis[]        = INCBIN_U32("graphics/pokemon_storage/latis_icon.4bpp.lz");
static const u32 sWallpaperIcon_Minun[]        = INCBIN_U32("graphics/pokemon_storage/minun_icon.4bpp.lz");
static const u32 sWallpaperIcon_Togepi[]       = INCBIN_U32("graphics/pokemon_storage/togepi_icon.4bpp.lz");
static const u32 sWallpaperIcon_Magma[]        = INCBIN_U32("graphics/pokemon_storage/magma_icon.4bpp.lz");

static const struct Wallpaper sWaldaWallpapers[] =
{
    WALLPAPER_ENTRY(Zigzagoon),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY_G(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY_G(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(Azumarill),
    WALLPAPER_ENTRY(Pikachu),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(Dusclops),
    WALLPAPER_ENTRY(Ludicolo),
    WALLPAPER_ENTRY(Whiscash),
};

static const u32 *const sWaldaWallpaperIcons[] =
{
    sWallpaperIcon_Aqua,
    sWallpaperIcon_Heart,
    sWallpaperIcon_FiveStar,
    sWallpaperIcon_Brick,
    sWallpaperIcon_FourStar,
    sWallpaperIcon_Asterisk,
    sWallpaperIcon_Dot,
    gWallpaperIcon_Cross,
    sWallpaperIcon_LineCircle,
    sWallpaperIcon_PokeBall,
    sWallpaperIcon_Maze,
    sWallpaperIcon_Footprint,
    sWallpaperIcon_BigAsterisk,
    sWallpaperIcon_Circle,
    sWallpaperIcon_Koffing,
    sWallpaperIcon_Ribbon,
    gWallpaperIcon_Bolt,
    sWallpaperIcon_FourCircles,
    sWallpaperIcon_Lotad,
    sWallpaperIcon_Crystal,
    sWallpaperIcon_Pichu,
    sWallpaperIcon_Diglett,
    sWallpaperIcon_Luvdisc,
    sWallpaperIcon_StarInCircle,
    sWallpaperIcon_Spinda,
    sWallpaperIcon_Latis,
    gWallpaperIcon_Plusle,
    sWallpaperIcon_Minun,
    sWallpaperIcon_Togepi,
    sWallpaperIcon_Magma,
};
