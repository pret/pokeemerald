#include "global.h"
#include "battle_anim.h"
#include "berry.h"
#include "berry_powder.h"
#include "bg.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item_icon.h"
#include "item_menu.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "malloc.h"
#include "math_util.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "minigame_countdown.h"
#include "random.h"
#include "digit_obj_util.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

struct BerryCrushGame_Player
{
    u16 unk0;
    u16 unk2;
    union
    {
        u8 as_2d_bytes[2][8];
        u16 as_hwords[8];
    } unk4;
    u8 unk14[12];
};

struct __attribute__((packed, aligned(2))) BerryCrushGame_4E
{
    u16 unk0;
    u16 filler2;
    u8 unk4_0:1;
    u8 unk4_1:1;
    s8 unk5;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
};

struct __attribute__((packed)) BerryCrushGame_40
{
    u8 unk0[2];
    u16 unk2[6];
    struct BerryCrushGame_4E unkE;
};

struct BerryCrushGame_5C
{
    u16 unk00;
    u8 unk02_0:1;
    u8 unk02_1:1;
    u8 unk02_2:1;
    u8 unk02_3:5;
    u8 unk03;
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u16 unk0A;
};

union BerryCrushGame_68
{
    struct BerryCrushGame_68_x
    {
        struct BerryCrushGame_68_x_SubStruct
        {
            s32 unk00;
            u16 unk04;
            s16 unk06;
            u16 unk08;
            u16 unk0A;
            u16 unk0C[2][5];
            u8 filler20[16];
        } unk00;
        u8 unk30[12];
        struct BerryCrushGame_Player others[4];
        u8 fillerBC[20];
    } as_four_players;
    struct BerryCrushGame_68_y
    {
        u8 filler00[28];
        struct BerryCrushGame_Player unk1C[5];
        u8 fillerBC[20];
    } as_five_players;
};

struct BerryCrushGame_138_C
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

struct BerryCrushGame_138
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    const struct BerryCrushGame_138_C *unkC[5];
    struct Sprite *unk20;
    struct Sprite *unk24[5];
    struct Sprite *unk38[5];
    struct Sprite *unk4C[11];
    struct Sprite *unk78[2];
    u8 unk80;
    u8 filler81;
    u8 unk82;
    u8 unk83[5];
};

struct BerryCrushGame
{
    MainCallback unk0;
    u32 (* unk4)(struct BerryCrushGame *, u8 *);
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    s16 unk18;
    s16 unk1A;
    int unk1C;
    s32 unk20;
    u8 unk24;
    u8 unk25_0:1;
    u8 unk25_1:1;
    u8 unk25_2:1;
    u8 unk25_3:1;
    u8 unk25_4:1;
    u8 unk25_5:3;
    u16 unk26;
    u16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    u8 unk36[0xA];
    struct BerryCrushGame_40 unk40;
    struct BerryCrushGame_5C unk5C;
    union BerryCrushGame_68 unk68;
    struct BerryCrushGame_138 unk138;
    u8 unk1C0[0x1000];
    u8 unk11C0[0x1000];
    u8 unk21C0[0x1000];
    u8 unk31C0[0x1000];
};

static void sub_8020F74(void);
static void sub_8020F88(void);
static void sub_8020FA0(u8);
void sub_8020FC4(struct BerryCrushGame *);
void sub_8022BEC(u16, u8, u8 *);
void sub_8024604(u8 *, u32, s32, u32, u32, u32, u32);
static int sub_8021450(struct BerryCrushGame *);
void sub_8022588(struct BerryCrushGame *);
void sub_8022600(struct BerryCrushGame *);
void sub_80226D0(struct BerryCrushGame *);
void sub_8022730(struct BerryCrushGame *);
void sub_8022960(struct BerryCrushGame *);
void sub_8022524(struct BerryCrushGame_138 *, u16);
void sub_8022B28(struct Sprite *);
void sub_8022554(struct BerryCrushGame_138 *r0);
void sub_8024578(struct BerryCrushGame *);
void sub_8024644(u8 *, u32, u32, u32, u32);
static void sub_8022A20(struct Sprite *sprite);
static u32 sub_8022C58(struct BerryCrushGame *r6, u8 *r1);
static u32 sub_8022CB0(struct BerryCrushGame *r4, u8 *r5);
static u32 sub_8022D14(struct BerryCrushGame *r7, u8 *r5);
static u32 sub_8022E1C(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_8022E3C(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_8022E5C(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_8022EAC(struct BerryCrushGame *r4, u8 *r5);
static u32 sub_8022F04(struct BerryCrushGame *r0, __attribute__((unused)) u8 *r1);
static u32 sub_8022F1C(struct BerryCrushGame *r5, u8 *r2);
static u32 sub_8023070(struct BerryCrushGame *r4,  __attribute__((unused)) u8 *r1);
static u32 sub_80231B8(struct BerryCrushGame *r4,  __attribute__((unused)) u8 *r1);
static u32 sub_80232EC(struct BerryCrushGame *r4,  __attribute__((unused)) u8 *r1);
static u32 sub_80238F0(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_8023998(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_8023A30(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_8023BC0(struct BerryCrushGame *r5, u8 *r6);
static u32 sub_8023CAC(struct BerryCrushGame *r7, __attribute__((unused)) u8 *r1);
static u32 sub_8024048(struct BerryCrushGame *r5, u8 *r6);
static u32 sub_8024134(struct BerryCrushGame *r5, u8 *r4);
static u32 sub_8024228(struct BerryCrushGame *r5, u8 *r6);
static u32 sub_80242E0(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1);
static u32 sub_80243BC(struct BerryCrushGame *r5, __attribute__((unused)) u8 *r1);
static u32 sub_8024444(struct BerryCrushGame *r5, __attribute__((unused)) u8 *r1);
static u32 sub_8024508(struct BerryCrushGame *r5, __attribute__((unused)) u8 *r1);
static u32 sub_8024568(__attribute__((unused)) struct BerryCrushGame *r0, __attribute__((unused)) u8 *r1);

static EWRAM_DATA struct BerryCrushGame *gUnknown_02022C90 = NULL;

static const u8 gUnknown_082F325C[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
static const u8 gUnknown_082F3264[] = { 0, 1, 2, 3, 5, 0, 0, 0 };

static const s8 gUnknown_082F326C[][7] = 
{
    { 4, 1, 0, -1,  0,  0, 0}, 
    { 4, 2, 0, -1,  0,  0, 0}, 
    { 4, 2, 0, -2,  0,  0, 0}, 
    { 6, 3, 1, -1, -3, -1, 0}, 
    { 6, 4, 1, -2, -4, -2, 0},
};

static const u8 sUnusedZero = 0;

static const u8 gUnknown_082F3290[][4] = 
{
    {3, 2, 1, 0}, 
    {3, 3, 1, 0},
    {3, 3, 2, 0},
    {3, 4, 2, 0},
    {3, 5, 3, 0},
};

static const u8 *const gUnknown_082F32A4[] =
{
    gText_ReadyToBerryCrush,
    gText_WaitForAllChooseBerry,
    gText_EndedWithXUnitsPowder,
    gText_RecordingGameResults,
    gText_PlayBerryCrushAgain,
    gText_YouHaveNoBerries,
    gText_MemberDroppedOut,
    gText_TimesUpNoGoodPowder,
    gText_CommunicationStandby2,
};

static const struct BgTemplate gUnknown_082F32C8[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0, 
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0, 
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 11,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0, 
    },
};


static const u8 sBerryCrushTextColorTable[][3] =
{
    {TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GREY,  TEXT_COLOR_LIGHT_GREY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GREY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GREY, TEXT_COLOR_RED},
    {TEXT_COLOR_WHITE,       TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_BLUE},
    {TEXT_COLOR_WHITE,       TEXT_COLOR_GREEN,      TEXT_COLOR_LIGHT_GREEN},
    {TEXT_COLOR_WHITE,       TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_RED},
};


static const struct WindowTemplate gUnknown_082F32EC =
{
    .bg = 0, 
    .tilemapLeft = 3, 
    .tilemapTop = 4, 
    .width = 24, 
    .height = 13, 
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate gUnknown_082F32F4[] =
{
    {
        .bg = 0, 
        .tilemapLeft = 0, 
        .tilemapTop = 0, 
        .width = 9, 
        .height = 2, 
        .paletteNum = 8, 
        .baseBlock = 1005
    },
    {
        .bg = 0, 
        .tilemapLeft = 0, 
        .tilemapTop = 3, 
        .width = 9, 
        .height = 2, 
        .paletteNum = 8, 
        .baseBlock = 987
    },
    {
        .bg = 0, 
        .tilemapLeft = 0, 
        .tilemapTop = 6, 
        .width = 9, 
        .height = 2, 
        .paletteNum = 8, 
        .baseBlock = 969
    },
    {
        .bg = 0, 
        .tilemapLeft = 21, 
        .tilemapTop = 3, 
        .width = 9, 
        .height = 2, 
        .paletteNum = 8, 
        .baseBlock = 951
    },
    {
        .bg = 0, 
        .tilemapLeft = 21, 
        .tilemapTop = 6, 
        .width = 9, 
        .height = 2, 
        .paletteNum = 8, 
        .baseBlock = 933
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate gUnknown_082F3324[] =
{
    {
        .bg = 0, 
        .tilemapLeft = 5, 
        .tilemapTop = 2, 
        .width = 20, 
        .height = 16, 
        .paletteNum = 15, 
        .baseBlock = 1
    },
    {
        .bg = 0, 
        .tilemapLeft = 5, 
        .tilemapTop = 2, 
        .width = 20, 
        .height = 16, 
        .paletteNum = 15, 
        .baseBlock = 1
    },
    {
        .bg = 0, 
        .tilemapLeft = 4, 
        .tilemapTop = 2, 
        .width = 22, 
        .height = 16, 
        .paletteNum = 15, 
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE,
};

static const u8 gUnknown_082F3344[][4] =
{
    {6, 8, 9, 11}, 
    {12, 14, 15, 16},
};

static const u32 gUnknown_082F334C[] = 
{
    50000000 / (1 << 0), 
    50000000 / (1 << 1), 
    50000000 / (1 << 2), 
    50000000 / (1 << 3), 
    50000000 / (1 << 4), 
    50000000 / (1 << 5), 
    50000000 / (1 << 6), 
    50000000 / (1 << 7),
};

static const u16 gBerryCrushGrinderBasePal[] = INCBIN_U16("graphics/link_games/berrycrush_grinder_base.gbapal");
static const u16 gBerryCrushMiscSpritesPal[] = INCBIN_U16("graphics/link_games/berrycrush_misc.gbapal");
static const u16 gBerryCrushTimerDigitsPal[] = INCBIN_U16("graphics/link_games/berrycrush_timerdigits.gbapal");
static const u32 gBerryCrushGrinderBaseGfx[] = INCBIN_U32("graphics/link_games/berrycrush_grinder_base.4bpp.lz");
static const u32 gBerryCrushBtnPressGfx[] = INCBIN_U32("graphics/link_games/berrycrush_btnpress.4bpp.lz");
static const u32 gBerryCrushSparkleGfx[] = INCBIN_U32("graphics/link_games/berrycrush_sparkle.4bpp.lz");
static const u8 gBerryCrushTimerDigitsGfx[] = INCBIN_U8("graphics/link_games/berrycrush_timerdigits.4bpp.lz");
static const u8 gBerryCrushGrinderTopTilemap[] = INCBIN_U8("graphics/link_games/berrycrush_grinder_top.bin.lz");
static const u8 gBerryCrushContainerCapTilemap[] = INCBIN_U8("graphics/link_games/berrycrush_container_cap.bin.lz");
static const u8 gBerryCrushBackgroundTilemap[] = INCBIN_U8("graphics/link_games/berrycrush_background.bin.lz");

static const u8 gUnknown_082F417C[][5] = 
{
    {1, 3, 0, 0, 0}, 
    {0, 1, 3, 0, 0}, 
    {1, 3, 2, 4, 0},
    {0, 1, 3, 2, 4},
};

static const struct BerryCrushGame_138_C gUnknown_082F4190[] =
{
    {
        .unk0 = 0,
        .unk1 = 0,
        .unk2 = 0,
        .unk4 = 0,
        .unk6 = -16,
        .unk8 = 0,
        .unkA = 0,
    },
    {
        .unk0 = 1,
        .unk1 = 0,
        .unk2 = 3,
        .unk4 = -28,
        .unk6 = -4,
        .unk8 = -24,
        .unkA = 16,
    },
    {
        .unk0 = 2,
        .unk1 = 0,
        .unk2 = 6,
        .unk4 = -16,
        .unk6 = 20,
        .unk8 = -8,
        .unkA = 16,
    },
    {
        .unk0 = 3,
        .unk1 = 20,
        .unk2 = 3,
        .unk4 = 28,
        .unk6 = -4,
        .unk8 = 32,
        .unkA = -8,
    },
    {
        .unk0 = 4,
        .unk1 = 20,
        .unk2 = 6,
        .unk4 = 16,
        .unk6 = 20,
        .unk8 = 16,
        .unkA = -8,
    }
};


static const s8 gUnknown_082F41CC[][2] =
{
    { 0, 0},
    {-1, 0},
    { 1, 1},
};

static const s8 gUnknown_082F41D2[][2] =
{
    {  0,   0},
    {-16,  -4},
    { 16,  -4},
    { -8,  -2},
    {  8,  -2},
    {-24,  -8},
    { 24,  -8},
    {-32, -12},
    { 32, -12},
    {-40, -16},
    { 40, -16},
};

static const u16 gUnknown_082F41E8[] = {5, 6, 7, 8, 9, 0};

static const struct CompressedSpriteSheet gUnknown_082F41F4[] = 
{
    { .data = gBerryCrushGrinderBaseGfx, .size = 0x800, .tag = 1 },
    { .data = gBerryCrushBtnPressGfx,    .size = 0xE00, .tag = 2 },
    { .data = gBerryCrushSparkleGfx,     .size = 0x700, .tag = 3 },
};

static const struct SpriteSheet gUnknown_082F420C[] =
{
    { .data = gBerryCrushTimerDigitsGfx, .size = 0x2C0, .tag = 4 },
    {}
};


static const struct SpritePalette gUnknown_082F421C[] =
{
    { .data = gBerryCrushGrinderBasePal, .tag = 1 },
    { .data = gBerryCrushMiscSpritesPal, .tag = 2 },
};

static const struct SpritePalette gUnknown_082F422C[] =
{
    { .data = gBerryCrushTimerDigitsPal, .tag = 4 },
    {}
};

static const union AnimCmd gUnknown_082F423C[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_082F4244[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_082F4254[] =
{
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_FRAME(64, 2),
    ANIMCMD_FRAME(80, 2),
    ANIMCMD_FRAME(96, 2),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_082F4268[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2), 
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(12, 2),
    ANIMCMD_FRAME(16, 2), 
    ANIMCMD_FRAME(20, 2), 
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gUnknown_082F4284[] =
{
    ANIMCMD_FRAME(24, 4), 
    ANIMCMD_FRAME(28, 4), 
    ANIMCMD_FRAME(32, 4), 
    ANIMCMD_FRAME(36, 4),
    ANIMCMD_FRAME(40, 4), 
    ANIMCMD_FRAME(44, 4), 
    ANIMCMD_FRAME(48, 4), 
    ANIMCMD_FRAME(52, 4),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gUnknown_082F42A8[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_082F42B0[] =
{
    ANIMCMD_FRAME(0, 0), 
    ANIMCMD_END
};


static const union AffineAnimCmd gUnknown_082F42B8[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 2, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AffineAnimCmd gUnknown_082F42D0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -2, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AnimCmd *const gUnknown_082F42E8[] =
{
    gUnknown_082F423C
};

static const union AnimCmd *const gUnknown_082F42EC[] =
{
    gUnknown_082F4244,
    gUnknown_082F4254,
};

static const union AnimCmd *const gUnknown_082F42F4[] =
{
    gUnknown_082F4268,
    gUnknown_082F4284,
};

static const union AnimCmd *const gUnknown_082F42FC[] =
{
    gUnknown_082F42A8
};

static const union AnimCmd *const gUnknown_082F4300[] =
{
    gUnknown_082F42B0
};

static const union AffineAnimCmd *const gUnknown_082F4304[] =
{
    gUnknown_082F42B8,
    gUnknown_082F42D0,
};

static const struct SpriteTemplate gUnknown_082F430C =
{
    .tileTag = 1, 
    .paletteTag = 1, 
    .oam = &gOamData_AffineOff_ObjNormal_64x64, 
    .anims = gUnknown_082F42E8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_082F4324 =
{
    .tileTag = 2, 
    .paletteTag = 2, 
    .oam = &gOamData_AffineOff_ObjNormal_32x32, 
    .anims = gUnknown_082F42EC, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = sub_8022A20
};

static const struct SpriteTemplate gUnknown_082F433C =
{
    .tileTag = 3, 
    .paletteTag = 2, 
    .oam = &gOamData_AffineOff_ObjNormal_16x16, 
    .anims = gUnknown_082F42F4, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_082F4354 =
{
    .tileTag = 4, 
    .paletteTag = 4, 
    .oam = &gOamData_AffineOff_ObjNormal_8x16, 
    .anims = gUnknown_082F42FC, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_082F436C =
{
    .tileTag = 5, 
    .paletteTag = 5, 
    .oam = &gOamData_AffineDouble_ObjNormal_32x32, 
    .anims = gUnknown_082F4300, 
    .images = NULL, 
    .affineAnims = gUnknown_082F4304, 
    .callback = SpriteCallbackDummy
};

static const struct DigitObjUtilTemplate gUnknown_082F4384[] = 
{
    {
        .strConvMode = 1,
        .shape = 2,
        .size = 0,
        .priority = 0,
        .oamCount = 2, 
        .xDelta = 8, 
        .x = 156,
        .y = 0,
        .spriteSheet = gUnknown_082F420C,
        .spritePal = gUnknown_082F422C,
    },
    {
        .strConvMode = 0,
        .shape = 2,
        .size = 0,
        .priority = 0,
        .oamCount = 2, 
        .xDelta = 8, 
        .x = 180,
        .y = 0,
        .spriteSheet = gUnknown_082F420C,
        .spritePal = gUnknown_082F422C,
    },
    {
        .strConvMode = 0,
        .shape = 2,
        .size = 0,
        .priority = 0,
        .oamCount = 2, 
        .xDelta = 8, 
        .x = 204,
        .y = 0,
        .spriteSheet = gUnknown_082F420C,
        .spritePal = gUnknown_082F422C,
    }
};

static const u8 *const gUnknown_082F43B4[] =
{
    gText_SpaceTimes2,
    gText_XDotY,
    gText_Var1Berry,
    gText_NeatnessRankings,
    gText_CoopRankings,
    gText_PressingPowerRankings,
};

static u32 (*const gUnknown_082F43CC[])(struct BerryCrushGame *, u8 *) =
{
    NULL,
    sub_8022C58,
    sub_8022CB0,
    sub_8022D14,
    sub_8022E1C,
    sub_8022E3C,
    sub_8022E5C,
    sub_8022EAC,
    sub_8022F04,
    sub_8022F1C,
    sub_8023070,
    sub_80231B8,
    sub_80232EC,
    sub_80238F0,
    sub_8023998,
    sub_8023A30,
    sub_8023BC0,
    sub_8023CAC,
    sub_8024048,
    sub_8024134,
    sub_8024228,
    sub_80242E0,
    sub_80243BC,
    sub_8024444,
    sub_8024508,
    sub_8024568,
};

static const u8 gUnknown_082F4434[][4] =
{
    {2,  4,  6,  7}, 
    {3,  5,  8, 11},
    {3,  7, 11, 15},
    {4,  8, 12, 17},
};

static const u8 gUnknown_082F4444[] = {5, 7, 9, 12};
static const u8 gUnknown_082F4448[] = {3, 7, 15, 31};


struct BerryCrushGame *sub_8020C00(void)
{
    return gUnknown_02022C90;
}

u32 sub_8020C0C(MainCallback callback)
{
    if (!gUnknown_02022C90)
        return 2;

    if (!callback)
        callback = gUnknown_02022C90->unk0;

    DestroyTask(gUnknown_02022C90->unkA);
    FREE_AND_SET_NULL(gUnknown_02022C90);
    SetMainCallback2(callback);
    if (callback == CB2_ReturnToField)
    {
        gTextFlags.autoScroll = TRUE;
        PlayNewMapMusic(MUS_POKECEN);
        SetMainCallback1(CB1_Overworld);
    }

    return 0;
}

void sub_8020C70(MainCallback callback)
{
    u8 playerCount = 0;
    u8 multiplayerId;

    if (!gReceivedRemoteLinkPlayers || gWirelessCommType == 0)
    {
        SetMainCallback2(callback);
        Rfu.unk_10 = 0;
        Rfu.unk_12 = 0;
        Rfu.unk_ee = 1;
        return;
    }

    playerCount = GetLinkPlayerCount();
    multiplayerId = GetMultiplayerId();
    if (playerCount < 2 || multiplayerId >= playerCount)
    {
        SetMainCallback2(callback);
        Rfu.unk_10 = 0;
        Rfu.unk_12 = 0;
        Rfu.unk_ee = 1;
        return;
    }

    gUnknown_02022C90 = AllocZeroed(sizeof(*gUnknown_02022C90));
    if (!gUnknown_02022C90)
    {
        SetMainCallback2(callback);
        Rfu.unk_10 = 0;
        Rfu.unk_12 = 0;
        Rfu.unk_ee = 1;
        return;
    }

    gUnknown_02022C90->unk0 = callback;
    gUnknown_02022C90->unk8 = multiplayerId;
    gUnknown_02022C90->unk9 = playerCount;
    sub_8020FC4(gUnknown_02022C90);
    gUnknown_02022C90->unk12 = 1;
    gUnknown_02022C90->unkE = 1;
    gUnknown_02022C90->unkF = 6;
    sub_8024604(gUnknown_02022C90->unk36, 1, -1, 0, 16, 0, 0);
    sub_8022BEC(4, 1, gUnknown_02022C90->unk36);
    SetMainCallback2(sub_8020F88);
    gUnknown_02022C90->unkA = CreateTask(sub_8020FA0, 8);
    gTextFlags.autoScroll = 0;
}

static void sub_8020D8C(void)
{
    if (gSpecialVar_ItemId < FIRST_BERRY_INDEX || gSpecialVar_ItemId > LAST_BERRY_INDEX + 1)
        gSpecialVar_ItemId = ITEM_CHERI_BERRY;
    else
        RemoveBagItem(gSpecialVar_ItemId, 1);

    gUnknown_02022C90->unk68.as_four_players.others[gUnknown_02022C90->unk8].unk0 = gSpecialVar_ItemId - FIRST_BERRY_INDEX;
    gUnknown_02022C90->unkE = 1;
    gUnknown_02022C90->unkF = 9;
    sub_8024604(gUnknown_02022C90->unk36, 0, -1, 0, 16, 0, 0);
    sub_8022BEC(4, 1, gUnknown_02022C90->unk36);
    gUnknown_02022C90->unkA = CreateTask(sub_8020FA0, 8);
    SetMainCallback2(sub_8020F88);
}

void sub_8020E1C(void)
{
    DestroyTask(gUnknown_02022C90->unkA);
    ChooseBerrySetCallback(sub_8020D8C);
}

static void sub_8020E3C(void)
{
    SetVBlankCallback(sub_8020F74);
}

void sub_8020E4C(void)
{
    SetVBlankCallback(NULL);
}

void sub_8020E58(void)
{
    u32 var0, var1;

    var0 = gUnknown_02022C90->unk68.as_four_players.unk00.unk04;
    var0 <<= 8;
    var0 = sub_81515FC(var0, 60 << 8);
    var1 = gUnknown_02022C90->unk68.as_four_players.unk00.unk0A;
    var1 <<= 8;
    var1 = sub_81515FC(var1, var0) & 0xFFFF;
    gUnknown_02022C90->unk16 = var1;
    switch (gUnknown_02022C90->unk9)
    {
    case 2:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[0])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[0] = gUnknown_02022C90->unk16;
        }
        break;
    case 3:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[1])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[1] = gUnknown_02022C90->unk16;
        }
        break;
    case 4:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[2])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[2] = gUnknown_02022C90->unk16;
        }
        break;
    case 5:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[3])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[3] = gUnknown_02022C90->unk16;
        }
        break;
    }

    gUnknown_02022C90->unk1C = gUnknown_02022C90->unk68.as_four_players.unk00.unk00;
    if (GiveBerryPowder(gUnknown_02022C90->unk1C))
        return;

    gUnknown_02022C90->unk25_0 = 1;
}

static void sub_8020F74(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_8020F88(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

static void sub_8020FA0(u8 taskId)
{
    if (gUnknown_02022C90->unk4)
        gUnknown_02022C90->unk4(gUnknown_02022C90, gUnknown_02022C90->unk36);

    sub_8021450(gUnknown_02022C90);
}

#define PLAYER_UNK14(game, i)                        \
    ((u8 *)(game)                                    \
    + offsetof(struct BerryCrushGame, unk68)         \
    + offsetof(struct BerryCrushGame_68_x, unk30)    \
    + sizeof(struct BerryCrushGame_Player) * (i))

void sub_8020FC4(struct BerryCrushGame *arg0)
{
    u8 i;

    for (i = 0; i < arg0->unk9; i++)
        StringCopy(PLAYER_UNK14(arg0, i), gLinkPlayers[i].name);
    for (; i < 5; i++)
    {
        memset(PLAYER_UNK14(arg0, i), 1, PLAYER_NAME_LENGTH);
        arg0->unk68.as_five_players.unk1C[i].unk14[PLAYER_NAME_LENGTH] = EOS;
    }

    switch (gSaveBlock2Ptr->optionsTextSpeed)
    {
    case OPTIONS_TEXT_SPEED_SLOW:
        arg0->unkB = 8;
        break;
    case OPTIONS_TEXT_SPEED_MID:
        arg0->unkB = 4;
        break;
    case OPTIONS_TEXT_SPEED_FAST:
        arg0->unkB = 1;
        break;
    }
}

int sub_802104C(void)
{
    struct BerryCrushGame *var0 = sub_8020C00();
    if (!var0)
        return -1;

    switch (var0->unkC)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ScanlineEffect_Stop();
        reset_temp_tile_data_buffers();
        break;
    case 1:
        CpuFill16(0, (void *)OAM, OAM_SIZE);
        gReservedSpritePaletteCount = 0;
        DigitObjUtil_Init(3);
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_082F32C8, ARRAY_COUNT(gUnknown_082F32C8));
        SetBgTilemapBuffer(1, var0->unk1C0);
        SetBgTilemapBuffer(2, var0->unk21C0);
        SetBgTilemapBuffer(3, var0->unk31C0);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 64);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        break;
    case 5:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        decompress_and_copy_tile_data_to_vram(1, gUnknown_08DE34B8, 0, 0, 0);
        break;
    case 6:
        if (free_temp_tile_data_buffers_if_possible())
            return 0;

        InitStandardTextBoxWindows();
        sub_8197200();
        sub_8022588(var0);
        sub_8022600(var0);
        gPaletteFade.bufferTransferDisabled = TRUE;
        break;
    case 7:
        LoadPalette(gUnknown_08DE3398, 0, 0x180);
        CopyToBgTilemapBuffer(1, gBerryCrushGrinderTopTilemap, 0, 0);
        CopyToBgTilemapBuffer(2, gBerryCrushContainerCapTilemap, 0, 0);
        CopyToBgTilemapBuffer(3, gBerryCrushBackgroundTilemap, 0, 0);
        sub_80226D0(var0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 8:
        LoadWirelessStatusIndicatorSpriteGfx();
        CreateWirelessStatusIndicatorSprite(0,  0);
        sub_8022730(var0);
        SetGpuReg(REG_OFFSET_BG1VOFS, -gSpriteCoordOffsetY);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        break;
    case 9:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        sub_8020E3C();
        var0->unkC = 0;
        return 1;
    }

    var0->unkC++;
    return 0;
}

int sub_802130C(void)
{
    struct BerryCrushGame *var0 = sub_8020C00();
    if (!var0)
        return -1;

    switch (var0->unkC)
    {
    case 0:
        sub_8010434();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        // fall through. The original author forgot to use "break" here
        // because this will call BeginNormalPaletteFade() twice.
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 3:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 5:
        FreeAllWindowBuffers();
        HideBg(0);
        UnsetBgTilemapBuffer(0);
        HideBg(1);
        UnsetBgTilemapBuffer(1);
        HideBg(2);
        UnsetBgTilemapBuffer(2);
        HideBg(3);
        UnsetBgTilemapBuffer(3);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        break;
    case 6:
        DestroyWirelessStatusIndicatorSprite();
        sub_8022960(var0);
        DigitObjUtil_Free();
        break;
    case 7:
        var0->unkC = 0;
        return 1;
    }

    var0->unkC++;
    return 0;
}

static int sub_8021450(struct BerryCrushGame *arg0)
{
    gSpriteCoordOffsetY = arg0->unk2A + arg0->unk2C;
    SetGpuReg(REG_OFFSET_BG1VOFS, -gSpriteCoordOffsetY);
    if (arg0->unk12 == 7)
    {
        sub_8022524(&arg0->unk138, arg0->unk28);
    }

    return 0;
}

void sub_8021488(struct BerryCrushGame *arg0)
{
    arg0->unk2A = -104;
    arg0->unk2C = 0;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = -104;
}

void sub_80214A8(struct BerryCrushGame *arg0, struct BerryCrushGame_138 *arg1)
{
    u8 i;
    u8 spriteId;
    s16 var0, var1;
    s16 *data;
    int var3;
    s16 var5;
    u32 var6;

    for (i = 0; i < arg0->unk9; i++)
    {
        spriteId = AddCustomItemIconSprite(
            &gUnknown_082F436C,
            gUnknown_082F41E8[i],
            gUnknown_082F41E8[i],
            arg0->unk68.as_four_players.others[i].unk0 + 133);
        arg1->unk38[i] = &gSprites[spriteId];
        arg1->unk38[i]->oam.priority = 3;
        arg1->unk38[i]->affineAnimPaused = TRUE;
        arg1->unk38[i]->pos1.x = arg1->unkC[i]->unk8 + 120;
        arg1->unk38[i]->pos1.y = -16;
        data = arg1->unk38[i]->data;
        var5 = 512;
        data[1] = var5;
        data[2] = 32;
        data[7] = 112;
        var0 = arg1->unkC[i]->unkA - arg1->unkC[i]->unk8;
        var3 = var0;
        if (var0 < 0)
            var3 += 3;

        data[6] = var3 >> 2;
        var0 *= 128;
        var6 = var5 + 32;
        var6 = var6 / 2;
        var1 = sub_81515D4(7, 0x3F80, var6);
        data[0] = (u16)arg1->unk38[i]->pos1.x * 128;
        data[3] = sub_81515D4(7, var0, var1);
        var1 = sub_8151550(7, var1, 85);
        data[4] = 0;
        data[5] = sub_81515D4(7, 0x3F80, var1);
        data[7] |= 0x8000;
        if (arg1->unkC[i]->unk8 < 0)
            StartSpriteAffineAnim(arg1->unk38[i], 1);
    }
}

void sub_8021608(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    data[1] += data[2];
    sprite->pos2.y += data[1] >> 8;
    if (data[7] & 0x8000)
    {
        sprite->data[0] += data[3];
        data[4] += data[5];
        sprite->pos2.x = Sin(data[4] >> 7, data[6]);
        if ((data[7] & 0x8000) && (data[4] >> 7) > 126)
        {
            sprite->pos2.x = 0;
            data[7] &= 0x7FFF;
        }
    }

    sprite->pos1.x = data[0] >> 7;
    if (sprite->pos1.y + sprite->pos2.y >= (data[7] & 0x7FFF))
    {
        sprite->callback = SpriteCallbackDummy;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void sub_80216A8(struct BerryCrushGame *arg0, __attribute__((unused)) struct BerryCrushGame_138 *arg1)
{
    u8 i;
    for (i = 0; i < arg0->unk9; i++)
    {
        FreeSpritePaletteByTag(gUnknown_082F41E8[i]);
        FreeSpriteTilesByTag(gUnknown_082F41E8[i]);
    }
}

void sub_80216E0(struct BerryCrushGame *arg0, struct BerryCrushGame_138 *arg1)
{
    u8 sp4;
    struct BerryCrushGame_4E *var4E;
    u8 i;
    u16 var, var2;

    sp4 = 0;
    var4E = &arg0->unk40.unkE;
    for (i = 0; i < arg0->unk9; i++)
    {
        var = var4E->unkA >> (i * 3);
        var &= 7;
        if (var)
        {
            sp4++;
            if (var & 0x4)
                StartSpriteAnim(arg1->unk24[i], 1);
            else
                StartSpriteAnim(arg1->unk24[i], 0);

            arg1->unk24[i]->invisible = FALSE;
            arg1->unk24[i]->animPaused = FALSE;
            arg1->unk24[i]->pos2.x = gUnknown_082F41CC[(var % 4) - 1][0];
            arg1->unk24[i]->pos2.y = gUnknown_082F41CC[(var % 4) - 1][1];
        }
    }

    if (sp4 == 0)
    {
        arg0->unk25_2 = 0;
    }
    else
    {
        var = (u8)(arg0->unk28 % 3);
        var2 = var;
        for (i = 0; i < var4E->unkC * 2 + 3; i++)
        {
            if (arg1->unk4C[i]->invisible)
            {
                arg1->unk4C[i]->callback = sub_8022B28;
                arg1->unk4C[i]->pos1.x = gUnknown_082F41D2[i][0] + 120;
                arg1->unk4C[i]->pos1.y = gUnknown_082F41D2[i][1] + 136 - (var * 4);
                arg1->unk4C[i]->pos2.x = gUnknown_082F41D2[i][0] + (gUnknown_082F41D2[i][0] / (var2 * 4));
                arg1->unk4C[i]->pos2.y = gUnknown_082F41D2[i][1];
                if (var4E->unk4_1)
                    StartSpriteAnim(arg1->unk4C[i], 1);
                else
                    StartSpriteAnim(arg1->unk4C[i], 0);

                var++;
                if (var > 3)
                    var = 0;
            }
        }

        if (arg0->unk25_2)
        {
            arg0->unk25_2 = 0;
        }
        else
        {
            if (sp4 == 1)
                PlaySE(SE_TOY_DANGO);
            else
                PlaySE(SE_TOY_KABE);

            arg0->unk25_2 = 1;
        }
    }
}

bool32 sub_80218D4(struct BerryCrushGame *arg0, struct BerryCrushGame_138 *arg1)
{
    u8 i;

    for (i = 0; i < arg0->unk9; i++)
    {
        if (!arg1->unk24[i]->invisible)
            return FALSE;
    }

    for (i = 0; i < 11; i++)
    {
        if (!arg1->unk4C[i]->invisible)
            return FALSE;
    }

    if (arg0->unk2C != 0)
        arg0->unk2C = 0;

    return TRUE;
}

void sub_8021944(struct BerryCrushGame_138 *arg0, u16 arg1)
{
    u8 i = 0;
    u32 r7 = 0;
    s16 r3 = 0;

    arg0->unk4 = arg1 / 3600;
    arg0->unk6 = (arg1 % 3600) / 60;
    r3 = sub_8151534((arg1 % 60) << 8, 4);

    for (i = 0; i < 8; i++)
    {
        if ((r3 >> (7 - i)) & 1)
            r7 += gUnknown_082F334C[i];
    }

    arg0->unk8 = r7 / 1000000;
}

void sub_80219C8(u8 windowId, u8 left, u8 colorId, const u8 *string)
{
    left = (left * 4) - (GetStringWidth(2, string, -1) / 2u);
    AddTextPrinterParameterized3(windowId, 2, left, 0, sBerryCrushTextColorTable[colorId], 0, string);
}

void sub_8021A28(struct BerryCrushGame * sp0C, u8 sp10, u8 sp14, u8 sp18)
{
    u8 r8;
    u8 sp1C = 0;
    u8 sp20 = 0;
    u8 r2;
    s32 r3;
    u8 r7;
    union BerryCrushGame_68 * sp24 = &sp0C->unk68;
    u32 xOffset;
    s32 r6;

    sp18 -= 16;
    if (sp10 == 2)
        sp18 -= 42;
    r6 = sp18 - 14 * sp0C->unk9;
    if (r6 > 0)
        r6 = r6 / 2 + 16;
    else
        r6 = 16;

    for (r8 = 0; r8 < sp0C->unk9; r6 += 14, ++r8)
    {
        DynamicPlaceholderTextUtil_Reset();
        switch (sp10)
        {
        case 0:
            sp1C = sp24->as_five_players.unk1C[0].unk4.as_2d_bytes[sp10][r8];
            if (r8 != 0 && sp24->as_four_players.unk00.unk0C[sp10][r8] != sp24->as_four_players.unk00.unk0C[sp10][r8 - 1])
                sp20 = r8;
            ConvertIntToDecimalStringN(gStringVar4, sp24->as_four_players.unk00.unk0C[sp10][r8], STR_CONV_MODE_RIGHT_ALIGN, 4);
            StringAppend(gStringVar4, gUnknown_082F43B4[sp10]);
            break;
        case 1:
            sp1C = sp24->as_five_players.unk1C[0].unk4.as_2d_bytes[sp10][r8];
            if (r8 != 0 && sp24->as_four_players.unk00.unk0C[sp10][r8] != sp24->as_four_players.unk00.unk0C[sp10][r8 - 1])
                sp20 = r8;
            ConvertIntToDecimalStringN(gStringVar1, sp24->as_four_players.unk00.unk0C[sp10][r8] >> 4, STR_CONV_MODE_RIGHT_ALIGN, 3);
            r3 = 0;
            r7 = sp24->as_four_players.unk00.unk0C[sp10][r8] & 15;
            for (r2 = 0; r2 < 4; ++r2)
                if ((r7 >> (3 - r2)) & 1)
                    r3 += gUnknown_082F334C[r2];
            r7 = r3 / 1000000u;
            ConvertIntToDecimalStringN(gStringVar2, r7, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringExpandPlaceholders(gStringVar4, gUnknown_082F43B4[sp10]);
            break;
        case 2:
            sp1C = r8;
            sp20 = r8;
            r2 = sp0C->unk68.as_five_players.unk1C[r8].unk14[12];
            if (r2 >= LAST_BERRY_INDEX - FIRST_BERRY_INDEX + 2)
                r2 = 0;
            StringCopy(gStringVar1, gBerries[r2].name);
            StringExpandPlaceholders(gStringVar4, gUnknown_082F43B4[2]);
            break;
        }
        xOffset = GetStringRightAlignXOffset(2, gStringVar4, sp14 - 4);
        AddTextPrinterParameterized3(sp0C->unk138.unk82, 2, xOffset, r6, sBerryCrushTextColorTable[0], 0, gStringVar4);
        if (sp1C == sp0C->unk8)
            StringCopy(gStringVar3, gText_1DotBlueF700);
        else
            StringCopy(gStringVar3, gText_1DotF700);
        gStringVar3[0] = sp20 + CHAR_1;
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, PLAYER_UNK14(sp0C, sp1C));
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gStringVar3);
        AddTextPrinterParameterized3(sp0C->unk138.unk82, 2, 4, r6, sBerryCrushTextColorTable[0], 0, gStringVar4);
    }
}

void sub_8021D34(struct BerryCrushGame *r8)
{
    u8 r10 = 0;
    u8 r6 = 0;
    u32 sp0C = 0;
    union BerryCrushGame_68 *sp10 = &r8->unk68;
    u8 r7 = GetWindowAttribute(r8->unk138.unk82, WINDOW_HEIGHT) * 8 - 42;

    sub_8021944(&r8->unk138, sp10->as_four_players.unk00.unk04);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gText_TimeColon);
    r6 = 176 - (u8)GetStringWidth(2, gText_SpaceSec, -1);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gText_SpaceSec);
    ConvertIntToDecimalStringN(gStringVar1, r8->unk138.unk6, STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gStringVar2, r8->unk138.unk8, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_XDotY2);
    r6 -= GetStringWidth(2, gStringVar4, -1);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gStringVar4);
    r6 -= GetStringWidth(2, gText_SpaceMin, -1);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gText_SpaceMin);
    ConvertIntToDecimalStringN(gStringVar1, r8->unk138.unk4, STR_CONV_MODE_LEADING_ZEROS, 1);
    StringExpandPlaceholders(gStringVar4, gText_StrVar1);
    r6 -= GetStringWidth(2, gStringVar4, -1);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gStringVar4);
    r7 += 14;
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, 0, r7, sBerryCrushTextColorTable[0], 0, gText_PressingSpeed);
    r6 = 176 - (u8)GetStringWidth(2, gText_TimesPerSec, -1);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gText_TimesPerSec);
    for (; r10 < 8; ++r10)
        if (((u8)r8->unk16 >> (7 - r10)) & 1)
            sp0C += *(r10 + gUnknown_082F334C); // It's accessed in a different way here for unknown reason
    ConvertIntToDecimalStringN(gStringVar1, r8->unk16 >> 8, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, sp0C / 1000000, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_XDotY3);
    r6 -= GetStringWidth(2, gStringVar4, -1);
    if (r8->unk25_1)
        AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[5], 0, gStringVar4);
    else
        AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gStringVar4);
    r7 += 14;
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, 0, r7, sBerryCrushTextColorTable[0], 0, gText_Silkiness);
    ConvertIntToDecimalStringN(gStringVar1, sp10->as_four_players.unk00.unk08, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_Var1Percent);
    r6 = 176 - (u8)GetStringWidth(2, gStringVar4, -1);
    AddTextPrinterParameterized3(r8->unk138.unk82, 2, r6, r7, sBerryCrushTextColorTable[0], 0, gStringVar4);
}

bool32 sub_8022070(struct BerryCrushGame *r4, struct BerryCrushGame_138 *r6)
{
    u8 r5;
    struct WindowTemplate template;

    switch (r6->unk80)
    {
    case 0:
        r5 = r4->unk9 - 2;
        sub_8022554(r6);
        memcpy(&template, &gUnknown_082F3324[r4->unk12 - 11], sizeof(struct WindowTemplate));
        if (r4->unk12 == 13)
            template.height = gUnknown_082F3344[1][r5];
        else
            template.height = gUnknown_082F3344[0][r5];
        r6->unk82 = AddWindow(&template);
        break;
    case 1:
        PutWindowTilemap(r6->unk82);
        FillWindowPixelBuffer(r6->unk82, PIXEL_FILL(0));
        break;
    case 2:
        LoadUserWindowBorderGfx_(r6->unk82, 541, 208);
        DrawStdFrameWithCustomTileAndPalette(r6->unk82, 0, 541, 13);
        break;
    case 3:
        r5 = r4->unk9 - 2;
        switch (r4->unk12)
        {
        case 11:
            sub_80219C8(r6->unk82, 20, 3, gText_PressesRankings);
            sub_8021A28(r4, 0, 0xA0, 8 * gUnknown_082F3344[0][r5]);
            r6->unk80 = 5;
            return FALSE;
        case 12:
            sub_80219C8(r6->unk82, 20, 4, gUnknown_082F43B4[r4->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[0][7] + 3]);
            sub_8021A28(r4, 1, 0xA0, 8 * gUnknown_082F3344[0][r5]);
            r6->unk80 = 5;
            return FALSE;
        case 13:
            sub_80219C8(r6->unk82, 22, 3, gText_CrushingResults);
            sub_8021A28(r4, 2, 0xB0, 8 * gUnknown_082F3344[1][r5]);
            break;
        }
        break;
    case 4:
        sub_8021D34(r4);
        break;
    case 5:
        CopyWindowToVram(r6->unk82, 3);
        r6->unk80 = 0;
        return TRUE;
    }
    ++r6->unk80;
    return FALSE;
}

void sub_802222C(struct BerryCrushGame *r4)
{
    ClearStdWindowAndFrameToTransparent(r4->unk138.unk82, 1);
    RemoveWindow(r4->unk138.unk82);
    sub_8022600(r4);
}

void sub_8022250(u8 r4)
{
    u8 r9 = 0, r2, r7, r10;
    u32 sp0C = 0;
    s16 *r6 = gTasks[r4].data;
    const u8 *r10_; // turn r5/sl register swap into r8/sl
    
    switch (r6[0])
    {
    case 0:
        r6[1] = AddWindow(&gUnknown_082F32EC);
        PutWindowTilemap((u8)r6[1]);
        FillWindowPixelBuffer((u8)r6[1], PIXEL_FILL(0));
        LoadUserWindowBorderGfx_((u8)r6[1], 541, 208);
        DrawStdFrameWithCustomTileAndPalette((u8)r6[1], 0, 541, 13);
        break;
    case 1:
        r10_ = gText_BerryCrush2;
        ++r10_; --r10_; // swap sb/sl
    #ifndef NONMATCHING
        asm("":::"r8"); // turn r8/sl register swap into sb/sl
    #endif
        r7 = 96 - GetStringWidth(1, r10_, -1) / 2u;
        AddTextPrinterParameterized3(
            (u8)r6[1],
            1,
            r7,
            1,
            sBerryCrushTextColorTable[3],
            0,
            r10_
        );
        r10_ = gText_PressingSpeedRankings;
        r7 = 96 - GetStringWidth(1, r10_, -1) / 2u;
        AddTextPrinterParameterized3(
            (u8)r6[1],
            1,
            r7,
            17,
            sBerryCrushTextColorTable[3],
            0,
            r10_
        );
        r10 = 41;
        for (; r9 < 4; ++r9)
        {
            ConvertIntToDecimalStringN(gStringVar1, r9 + 2, STR_CONV_MODE_LEFT_ALIGN, 1);
            StringExpandPlaceholders(gStringVar4, gText_Var1Players);
            AddTextPrinterParameterized3(
                (u8)r6[1],
                1,
                0,
                r10,
                sBerryCrushTextColorTable[0],
                0,
                gStringVar4
            );
            r7 = 192 - (u8)GetStringWidth(1, gText_TimesPerSec, -1);
            AddTextPrinterParameterized3(
                (u8)r6[1],
                1,
                r7,
                r10,
                sBerryCrushTextColorTable[0],
                0,
                gText_TimesPerSec
            );
            for (r2 = 0; r2 < 8; ++r2)
                if (((u8)r6[r9 + 2] >> (7 - r2)) & 1)
                    sp0C += gUnknown_082F334C[r2];
            ConvertIntToDecimalStringN(gStringVar1, (u16)r6[r9 + 2] >> 8, STR_CONV_MODE_RIGHT_ALIGN, 3);
            ConvertIntToDecimalStringN(gStringVar2, sp0C / 1000000, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringExpandPlaceholders(gStringVar4, gText_XDotY3);
            r7 -= GetStringWidth(1, gStringVar4, -1);
            AddTextPrinterParameterized3(
                (u8)r6[1],
                1,
                r7,
                r10,
                sBerryCrushTextColorTable[0],
                0,
                gStringVar4
            );
            r10 += 16;
            sp0C = 0;
        }
        CopyWindowToVram((u8)r6[1], 3);
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            break;
        else
            return;
    case 3:
        ClearStdWindowAndFrameToTransparent((u8)r6[1], 1);
        ClearWindowTilemap((u8)r6[1]);
        RemoveWindow((u8)r6[1]);
        DestroyTask(r4);
        EnableBothScriptContexts();
        ScriptContext2_Disable();
        r6[0] = 0;
        return;
    }
    ++r6[0];
}

void ShowBerryCrushRankings(void)
{
    u8 taskId;

    ScriptContext2_Enable();
    taskId = CreateTask(sub_8022250, 0);
    gTasks[taskId].data[2] = gSaveBlock2Ptr->berryCrush.berryCrushResults[0];
    gTasks[taskId].data[3] = gSaveBlock2Ptr->berryCrush.berryCrushResults[1];
    gTasks[taskId].data[4] = gSaveBlock2Ptr->berryCrush.berryCrushResults[2];
    gTasks[taskId].data[5] = gSaveBlock2Ptr->berryCrush.berryCrushResults[3];
}

void sub_8022524(struct BerryCrushGame_138 *r4, u16 r1)
{
    sub_8021944(r4, r1);
    DigitObjUtil_PrintNumOn(0, r4->unk4);
    DigitObjUtil_PrintNumOn(1, r4->unk6);
    DigitObjUtil_PrintNumOn(2, r4->unk8);
}

void sub_8022554(struct BerryCrushGame_138 *r0)
{
    r0->unk78[0]->invisible = TRUE;
    r0->unk78[1]->invisible = TRUE;
    DigitObjUtil_HideOrShow(2, 1);
    DigitObjUtil_HideOrShow(1, 1);
    DigitObjUtil_HideOrShow(0, 1);
}

void sub_8022588(struct BerryCrushGame *r5)
{
    u8 r6;

    for (r6 = 0; r6 < r5->unk9; ++r6)
    {
        r5->unk138.unkC[r6] = &gUnknown_082F4190[gUnknown_082F417C[r5->unk9 - 2][r6]];
        r5->unk138.unk83[r6] = AddWindow(&gUnknown_082F32F4[r5->unk138.unkC[r6]->unk0]);
        PutWindowTilemap(r5->unk138.unk83[r6]);
        FillWindowPixelBuffer(r5->unk138.unk83[r6], 0);
    }
}

void sub_8022600(struct BerryCrushGame *r6)
{
    u8 r7, r2;
    u8 *r4;

    for (r7 = 0; r7 < r6->unk9; ++r7)
    {
        PutWindowTilemap(r6->unk138.unk83[r7]);
        if (r7 == r6->unk8)
        {
            AddTextPrinterParameterized4(
                r6->unk138.unk83[r7],
                2,
                36 - GetStringWidth(2, PLAYER_UNK14(r6, r7), 0) / 2u,
                1,
                0,
                0,
                sBerryCrushTextColorTable[1],
                0,
                PLAYER_UNK14(r6, r7)
            );
        }
        else
        {
            AddTextPrinterParameterized4(
                r6->unk138.unk83[r7],
                2,
                36 - GetStringWidth(2, PLAYER_UNK14(r6, r7), 0) / 2u,
                1,
                0,
                0,
                sBerryCrushTextColorTable[2],
                0,
                PLAYER_UNK14(r6, r7)
            );
        }
        CopyWindowToVram(r6->unk138.unk83[r7], 3);
    }
    CopyBgTilemapBufferToVram(0);
}

void sub_80226D0(struct BerryCrushGame *r6)
{
    u8 r5 = 0;
    const u32 *r0 = gUnknown_08DE3FD4;
#ifndef NONMATCHING // r4, r5, r6 register roulette
    register u8 *r4 asm("r4") = gDecompressionBuffer;
    register u32 r0_ asm("r0");
#else
    u8 *r4 = gDecompressionBuffer;
    u32 r0_;
#endif

    LZ77UnCompWram(r0, r4);
    for (; r5 < r6->unk9; ++r5)
    {
        r0_ = r6->unk138.unkC[r5]->unk0;
        CopyToBgTilemapBufferRect(
            3,
            &r4[r0_ * 40],
            r6->unk138.unkC[r5]->unk1,
            r6->unk138.unkC[r5]->unk2,
            10,
            2
        );
    }
    CopyBgTilemapBufferToVram(3);
}

void sub_8022730(struct BerryCrushGame *r6)
{
    u8 r5 = 0;
    u8 r2;

    r6->unk2A = -104;
    r6->unk2C = 0;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = -104;
    for (; r5 < 4; ++r5)
        LoadCompressedSpriteSheet(&gUnknown_082F41F4[r5]);
    LoadSpritePalettes(gUnknown_082F421C);
    r2 = CreateSprite(&gUnknown_082F430C, 120, 88, 5);
    r6->unk138.unk20 = &gSprites[r2];
    r6->unk138.unk20->oam.priority = 3;
    r6->unk138.unk20->coordOffsetEnabled = TRUE;
    r6->unk138.unk20->animPaused = TRUE;
    for (r5 = 0; r5 < r6->unk9; ++r5)
    {
        r2 = CreateSprite(
            &gUnknown_082F4324,
            r6->unk138.unkC[r5]->unk4 + 120,
            r6->unk138.unkC[r5]->unk6 + 32,
            0
        );
        r6->unk138.unk24[r5] = &gSprites[r2];
        r6->unk138.unk24[r5]->oam.priority = 1;
        r6->unk138.unk24[r5]->invisible = TRUE;
        r6->unk138.unk24[r5]->coordOffsetEnabled = TRUE;
        r6->unk138.unk24[r5]->animPaused = TRUE;
    }
    for (r5 = 0; r5 < ARRAY_COUNT(r6->unk138.unk4C); ++r5)
    {
        r2 = CreateSprite(
            &gUnknown_082F433C,
            gUnknown_082F41D2[r5][0] + 120,
            gUnknown_082F41D2[r5][1] + 136,
            6
        );
        r6->unk138.unk4C[r5] = &gSprites[r2];
        r6->unk138.unk4C[r5]->oam.priority = 3;
        r6->unk138.unk4C[r5]->invisible = TRUE;
        r6->unk138.unk4C[r5]->animPaused = TRUE;
        r6->unk138.unk4C[r5]->data[0] = r5;
    }
    for (r5 = 0; r5 < ARRAY_COUNT(r6->unk138.unk78); ++r5)
    {
        r2 = CreateSprite(
            &gUnknown_082F4354,
            24 * r5 + 176,
            8,
            0
        );
        r6->unk138.unk78[r5] = &gSprites[r2];
        r6->unk138.unk78[r5]->oam.priority = 0;
        r6->unk138.unk78[r5]->invisible = FALSE;
        r6->unk138.unk78[r5]->animPaused = FALSE;
    }
    DigitObjUtil_CreatePrinter(0, 0, &gUnknown_082F4384[0]);
    DigitObjUtil_CreatePrinter(1, 0, &gUnknown_082F4384[1]);
    DigitObjUtil_CreatePrinter(2, 0, &gUnknown_082F4384[2]);
    if (r6->unk12 == 1)
        sub_8022554(&r6->unk138);
}

void sub_8022960(struct BerryCrushGame *r5)
{
    u8 r4 = 0;

    FreeSpriteTilesByTag(4);
    FreeSpriteTilesByTag(3);
    FreeSpriteTilesByTag(2);
    FreeSpriteTilesByTag(1);
    FreeSpritePaletteByTag(4);
    FreeSpritePaletteByTag(2);
    FreeSpritePaletteByTag(1);
    for (; r4 < ARRAY_COUNT(r5->unk138.unk78); ++r4)
        DestroySprite(r5->unk138.unk78[r4]);
    DigitObjUtil_DeletePrinter(2);
    DigitObjUtil_DeletePrinter(1);
    DigitObjUtil_DeletePrinter(0);
    for (r4 = 0; r4 < ARRAY_COUNT(r5->unk138.unk4C); ++r4)
        DestroySprite(r5->unk138.unk4C[r4]);
    for (r4 = 0; r4 < r5->unk9; ++r4)
        DestroySprite(r5->unk138.unk24[r4]);
    if (r5->unk138.unk20->inUse)
        DestroySprite(r5->unk138.unk20);
}

static void sub_8022A20(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->invisible = TRUE;
        sprite->animPaused = TRUE;
    }
}

void sub_8022A4C(struct Sprite *sprite)
{
    u8 r1 = 0;
    SpriteCallback r5 = SpriteCallbackDummy;

    for (; r1 < ARRAY_COUNT(sprite->data); ++r1)
        sprite->data[r1] = 0;
    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    sprite->invisible = TRUE;
    sprite->animPaused = TRUE;
    sprite->callback = r5;
}

void sub_8022A94(struct Sprite *sprite)
{
    s16 *r4 = sprite->data;

    r4[1] += r4[2];
    sprite->pos2.y += r4[1] >> 8;
    if (r4[7] & 0x8000)
    {
        sprite->data[0] += r4[3];
        r4[4] += r4[5];
        sprite->pos2.x = Sin(r4[4] >> 7, r4[6]);
        if (r4[7] & 0x8000 && r4[4] >> 7 > 126)
        {
            sprite->pos2.x = 0;
            r4[7] &= 0x7FFF;
        }
    }
    sprite->pos1.x = r4[0] >> 7;
    if (sprite->pos1.y + sprite->pos2.y > (r4[7] & 0x7FFF))
        sprite->callback = sub_8022A4C;
}

void sub_8022B28(struct Sprite *sprite)
{
    s16 *r7 = sprite->data;
    s16 r4, r5;
    s32 r2;
    u32 r8 = 0;

    r2 = 640;
    r7[1] = r2;
    r7[2] = 32;
    r7[7] = 168;
    r4 = sprite->pos2.x * 128;
    r5 = sub_81515D4(7, (168 - sprite->pos1.y) << 7, (r2 + 32) >> 1);
    sprite->data[0] = sprite->pos1.x << 7;
    r7[3] = sub_81515D4(7, r4, r5);
    r2 = sub_8151550(7, r5, 85);
    r7[4] = r8;
    r7[5] = sub_81515D4(7, 0x3F80, r2);
    r7[6] = sprite->pos2.x / 4;
    r7[7] |= 0x8000;
    sprite->pos2.y = r8;
    sprite->pos2.x = r8;
    sprite->callback = sub_8022A94;
    sprite->animPaused = FALSE;
    sprite->invisible = FALSE;
}

void sub_8022BEC(u16 r5, u8 r4, u8 *r7)
{
    struct BerryCrushGame *r6 = sub_8020C00();

    if (r5 > 25)
        r5 = 0;
    switch (r4)
    {
    case 0:
        if (r5 != 0)
            gUnknown_082F43CC[r5](r6, r7);
        if (r6->unkE > 25)
            r6->unkE = r4;
        r6->unk4 = gUnknown_082F43CC[r6->unkE];
        break;
    case 1:
        r6->unk4 = gUnknown_082F43CC[r5];
        break;
    }
}

static u32 sub_8022C58(struct BerryCrushGame *r6, u8 *r1)
{
    u16 r4;
    u32 r0;
#ifndef NONMATCHING // fake match, nobody can write such code
    register u32 r2 asm("r2");
    register u32 r3 asm("r3");

    r2 = r1[0];
    r3 = r1[1];
    r3 <<= 8;
    r2 |= r3;
    r3 = r1[2];
    r3 <<= 16;
    r2 |= r3;
    r3 = r1[3];
    r3 <<= 24;
    r0 = r2;
    r0 |= r3;
#else
    u32 r2;

    r0 = T1_READ_32(r1);
#endif
    r2 = r1[9];
    r1[0] = r2;
    r4 = r1[8] << 8;
    r2 = r1[7];
    r4 |= r2;
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(r0, r1[4], r1[5], r1[6], r4);
    UpdatePaletteFade();
    r6->unkE = 2;
    return 0;
}

static u32 sub_8022CB0(struct BerryCrushGame *r4, u8 *r5)
{
    switch (r4->unkC)
    {
    case 0:
        if (UpdatePaletteFade())
            return 0;
        if(r5[0] != 0)
            ++r4->unkC;
        else
            r4->unkC = 3;
        return 0;
    case 1:
        sub_8010434();
        ++r4->unkC;
        return 0;
    case 2:
        if (IsLinkTaskFinished())
        {
            ++r4->unkC;
            return 0;
        }
        return 0;
    case 3:
        sub_8022BEC(r4->unkF, 1, NULL);
        r4->unkC = 0;
        return 0;
    default:
        ++r4->unkC;
        return 0;
    }
}

static u32 sub_8022D14(struct BerryCrushGame *r7, u8 *r5)
{
    u16 r4 = r5[3];

    r4 <<= 8;
    r4 |= r5[2];
    switch (r7->unkC)
    {
    case 0:
        DrawDialogueFrame(0, 0);
        if (r5[1] & 2)
        {
            StringExpandPlaceholders(gStringVar4, gUnknown_082F32A4[r5[0]]);
            AddTextPrinterParameterized2(0, 1, gStringVar4, r7->unkB, 0, 2, 1, 3);
        }
        else
        {
            AddTextPrinterParameterized2(0, 1, gUnknown_082F32A4[r5[0]], r7->unkB, 0, 2, 1, 3);
        }
        CopyWindowToVram(0, 3);
        break;
    case 1:
        if (!IsTextPrinterActive(0))
        {
            if (r4 == 0)
                ++r7->unkC;
            break;
        }
        return 0;
    case 2:
        if (!(r4 & gMain.newKeys))
            return 0;
        break;
    case 3:
        if (r5[1] & 1)
            ClearDialogWindowAndFrame(0, 1);
        sub_8022BEC(r7->unkE, 1, NULL);
        r7->unkC = r5[4];
        return 0;
    }
    ++r7->unkC;
    return 0;
}

static u32 sub_8022E1C(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    if (sub_802104C() != 0)
        sub_8022BEC(r4->unkE, 0, r4->unk36);
    return 0;
}

static u32 sub_8022E3C(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    if (sub_802130C() != 0)
        sub_8022BEC(r4->unkE, 0, r4->unk36);
    return 0;
}

static u32 sub_8022E5C(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    switch (r4->unkC)
    {
    case 0:
        sub_8010434();
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            PlayNewMapMusic(MUS_RG_SLOT);
            sub_8022BEC(7, 1, NULL);
            r4->unk12 = 3;
            r4->unkC = 0;
        }
        return 0;
    }
    ++r4->unkC;
    return 0;
}

static u32 sub_8022EAC(struct BerryCrushGame *r4, u8 *r5)
{
    switch (r4->unkC)
    {
    default:
        ++r4->unkC;
        break;
    case 0:
        sub_8024578(r4);
        sub_8024644(r5, 0, 1, 0, 1);
        r4->unkE = 7;
        sub_8022BEC(3, 1, NULL);
        break;
    case 1:
        r4->unkE = 8;
        sub_8022BEC(5, 1, NULL);
        r4->unkC = 2;
        break;
    }
    return 0;
}

static u32 sub_8022F04(struct BerryCrushGame *r0, __attribute__((unused)) u8 *r1)
{
    r0->unk4 = NULL;
    SetMainCallback2(sub_8020E1C);
    return 0;
}

static u32 sub_8022F1C(struct BerryCrushGame *r5, u8 *r2)
{
    u8 r3;

    switch (r5->unkC)
    {
    case 0:
        sub_8024644(r2, 1, 0, 0, 1);
        r5->unkE = 9;
        sub_8022BEC(3, 1, NULL);
        return 0;
    case 1:
        sub_8010434();
        break;
    case 2:
        if (!IsLinkTaskFinished())
            return 0;
        memset(r5->unk40.unk2, 0, sizeof(r5->unk40.unk2));
        r5->unk40.unk2[0] = r5->unk68.as_four_players.others[r5->unk8].unk0;
        SendBlock(0, r5->unk40.unk2, 2);
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        r5->unk10 = 0;
        break;
    case 4:
        if (GetBlockReceivedStatus() != gUnknown_082F4448[r5->unk9 - 2])
            return 0;
        for (r3 = 0; r3 < r5->unk9; ++r3)
        {
            r5->unk68.as_four_players.others[r3].unk0 = gBlockRecvBuffer[r3][0];
            if (r5->unk68.as_four_players.others[r3].unk0 > 0xB0)
                r5->unk68.as_four_players.others[r3].unk0 = 0;
            r5->unk18 += gUnknown_0858AB24[r5->unk68.as_four_players.others[r3].unk0].unk0;
            r5->unk1C += gUnknown_0858AB24[r5->unk68.as_four_players.others[r3].unk0].unk1;
        }
        r5->unk10 = 0;
        ResetBlockReceivedFlags();
        r5->unk20 = sub_81515FC(r5->unk18 << 8, 0x2000);
        break;
    case 5:
        ClearDialogWindowAndFrame(0, 1);
        sub_8022BEC(10, 1, NULL);
        r5->unk12 = 4;
        r5->unkC = 0;
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8023070(struct BerryCrushGame *r4,  __attribute__((unused)) u8 *r1)
{
    switch (r4->unkC)
    {
    case 0:
        sub_80214A8(r4, &r4->unk138);
        sub_8010434();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        r4->unk138.unk0 = 0;
        r4->unk138.unk1 = 0;
        r4->unk138.unk2 = 0;
        r4->unk138.unk3 = 0;
        break;
    case 2:
        r4->unk138.unk38[r4->unk138.unk0]->callback = sub_8021608;
        r4->unk138.unk38[r4->unk138.unk0]->affineAnimPaused = FALSE;
        PlaySE(SE_NAGERU);
        break;
    case 3:
        if (r4->unk138.unk38[r4->unk138.unk0]->callback == sub_8021608)
            return 0;
        r4->unk138.unk38[r4->unk138.unk0] = NULL;
        ++r4->unk138.unk0;
        sub_8010434();
        break;
    case 4:
        if (!IsLinkTaskFinished())
            return 0;
        if (r4->unk138.unk0 < r4->unk9)
        {
            r4->unkC = 2;
            return 0;
        }
        r4->unk138.unk0 = 0;
        break;
    case 5:
        sub_80216A8(r4, &r4->unk138);
        sub_8010434();
        break;
    case 6:
        if (!IsLinkTaskFinished())
            return 0;
        PlaySE(SE_RU_HYUU);
        sub_8022BEC(11, 1, NULL);
        r4->unk12 = 5;
        r4->unkC = 0;
        return 0;
    }
    ++r4->unkC;
    return 0;
}

static u32 sub_80231B8(struct BerryCrushGame *r4,  __attribute__((unused)) u8 *r1)
{
    switch (r4->unkC)
    {
    case 0:
        r4->unk2A += 4;
        if (r4->unk2A < 0)
            return 0;
        r4->unk2A = 0;
        r4->unk138.unk1 = 4;
        r4->unk138.unk0 = 0;
        r4->unk138.unk2 = gUnknown_082F326C[r4->unk138.unk1][0];
        PlaySE(SE_W070);
        break;
    case 1:
        r4->unk2C = gUnknown_082F326C[r4->unk138.unk1][r4->unk138.unk0];
        SetGpuReg(REG_OFFSET_BG0VOFS, -r4->unk2C);
        SetGpuReg(REG_OFFSET_BG2VOFS, -r4->unk2C);
        SetGpuReg(REG_OFFSET_BG3VOFS, -r4->unk2C);
        ++r4->unk138.unk0;
        if (r4->unk138.unk0 < r4->unk138.unk2)
            return 0;
        if (r4->unk138.unk1 == 0)
            break;
        --r4->unk138.unk1;
        r4->unk138.unk2 = gUnknown_082F326C[r4->unk138.unk1][0];
        r4->unk138.unk0 = 0;
        return 0;
    case 2:
        r4->unk2C = 0;
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        sub_8010434();
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        sub_8022BEC(12, 1, NULL);
        r4->unk12 = 6;
        r4->unkC = 0;
        return 0;
    }
    ++r4->unkC;
    return 0;
}

static u32 sub_80232EC(struct BerryCrushGame *r4,  __attribute__((unused)) u8 *r1)
{
    switch (r4-> unkC)
    {
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        StartMinigameCountdown(0x1000, 0x1000, 120, 80, 0);
        break;
    case 2:
        if (IsMinigameCountdownRunning())
            return 0;
        // fallthrough
    case 0:
        sub_8010434();
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        r4->unk138.unk0 = 0;
        r4->unk138.unk1 = 0;
        r4->unk138.unk2 = 0;
        r4->unk138.unk3 = 0;
        r4->unk10 = 0;
        if (r4->unk8 == 0)
            sub_8022BEC(13, 1, NULL);
        else
            sub_8022BEC(14, 1, NULL);
        r4->unk12 = 7;
        r4->unkC = 0;
        return 0;
    }
    ++r4->unkC;
    return 0;
}

void sub_802339C(struct BerryCrushGame *r4)
{
    u8 r8 = 0;
    u16 r3;
    u16 *r2;
    u8 r7 = 0;
    s32 r2_ = 0;
    s32 r0;

    for (r7 = 0; r7 < r4->unk9; ++r7)
    {
        r2 = gRecvCmds[r7];
        if ((r2[0] & 0xFF00) == 0x2F00
         && r2[1] == 2)
        {
            if ((u8)r2[2] & 4)
            {
                r4->unk5C.unk02_3 |= gUnknown_082F325C[r7];
                r4->unk68.as_four_players.others[r7].unk4.as_2d_bytes[1][5] = 1;
                ++r4->unk68.as_four_players.others[r7].unk4.as_hwords[3];
                ++r8;
                r3 = r4->unk28 - r4->unk68.as_four_players.others[r7].unk2;
                if (r3 >= r4->unk68.as_four_players.others[r7].unk4.as_hwords[1] - 1
                 && r3 <= r4->unk68.as_four_players.others[r7].unk4.as_hwords[1] + 1)
                {
                    ++r4->unk68.as_four_players.others[r7].unk4.as_hwords[0];
                    r4->unk68.as_four_players.others[r7].unk4.as_hwords[1] = r3;
                    if (r4->unk68.as_four_players.others[r7].unk4.as_hwords[0] > r4->unk68.as_four_players.others[r7].unk4.as_hwords[2])
                        r4->unk68.as_four_players.others[r7].unk4.as_hwords[2] = r4->unk68.as_four_players.others[r7].unk4.as_hwords[0];
                }
                else
                {
                    r4->unk68.as_four_players.others[r7].unk4.as_hwords[0] = 0;
                    r4->unk68.as_four_players.others[r7].unk4.as_hwords[1] = r3;
                }
                r4->unk68.as_four_players.others[r7].unk2 = r4->unk28;
                if (++r4->unk68.as_four_players.others[r7].unk4.as_2d_bytes[1][4] > 2)
                    r4->unk68.as_four_players.others[r7].unk4.as_2d_bytes[1][4] = 0;
            }
            else
            {
                r4->unk68.as_four_players.others[r7].unk4.as_2d_bytes[1][5] = 0;
            }
        }
    }
    if (r8 > 1)
    {
        for (r7 = 0; r7 < r4->unk9; ++r7)
        {
            if (r4->unk68.as_four_players.others[r7].unk4.as_2d_bytes[1][5] != 0)
            {
                r4->unk68.as_four_players.others[r7].unk4.as_2d_bytes[1][5] |= 2;
                ++r4->unk68.as_four_players.others[r7].unk4.as_hwords[4];
            }
        }
    }
    if (r8 != 0)
    {
        r4->unk2E += r8;
        r8 += gUnknown_082F3264[r8 - 1];
        r4->unk34 += r8;
        r4->unk1A += r8;
        r0 = r4->unk18;
        r2_ = r4->unk1A;
        if (r0 - r2_ > 0)
        {
            r2_ <<= 8;
            r2_ = sub_81515FC(r2_, r4->unk20);
            r2_ >>= 8;
            r4->unk24 = r2_;
        }
        else
        {
            r4->unk24 = 32;
            r4->unk5C.unk02_0 = 1;
        }
    }
}

void sub_8023558(struct BerryCrushGame *r3)
{
    u8 r6 = 0;
    u16 r1 = 0;
    u8 r4 = 0;
    
    for (r4 = 0; r4 < r3->unk9; ++r4)
    {
        if (r3->unk68.as_four_players.others[r4].unk4.as_2d_bytes[1][5] != 0)
        {
            ++r6;
            r1 = r3->unk68.as_four_players.others[r4].unk4.as_2d_bytes[1][4] + 1;
            if (r3->unk68.as_four_players.others[r4].unk4.as_2d_bytes[1][5] & 2)
                r1 |= 4;
            r1 <<= 3 * r4;
            r3->unk5C.unk08 |= r1;
        }
    }
    r3->unk5C.unk04 = r3->unk24;
    if (r6 == 0)
    {
        if (r3->unk138.unk3 != 0)
            ++r3->unk138.unk0;
        else
            goto SET_UNK5F_0;
    }
    else
    {
        if (r3->unk138.unk3 != 0)
        {
            if (r6 != r3->unk138.unk1)
            {
                r3->unk138.unk1 = r6 - 1;
                r3->unk138.unk2 = gUnknown_082F3290[r6 - 1][0];
            }
            else
            {
                ++r3->unk138.unk0;
            }
        }
        else
        {
            r3->unk138.unk0 = 0;
            r3->unk138.unk1 = r6 - 1;
            r3->unk138.unk2 = gUnknown_082F3290[r6 - 1][0];
            r3->unk138.unk3 = 1;
        }
    }
    if (r3->unk138.unk3 != 0)
    {
        if (r3->unk138.unk0 >= r3->unk138.unk2)
        {
            r3->unk138.unk0 = 0;
            r3->unk138.unk1 = 0;
            r3->unk138.unk2 = 0;
            r3->unk138.unk3 = 0;
            r1 = 0;
        }
        else
        {
            r1 = gUnknown_082F3290[r3->unk138.unk1][r3->unk138.unk0 + 1];
        }
        r3->unk5C.unk03 = r1;
    }
    else
    {
    SET_UNK5F_0:
        r3->unk5C.unk03 = 0;
    }
    r3->unk5C.unk06 = r3->unk26;
}

void sub_80236B8(struct BerryCrushGame *r5)
{
    if (gMain.newKeys & A_BUTTON)
        r5->unk5C.unk02_2 = 1;
    if (gMain.heldKeys & A_BUTTON)
    {
        if (r5->unk68.as_four_players.others[r5->unk8].unk4.as_hwords[5] < r5->unk28)
            ++r5->unk68.as_four_players.others[r5->unk8].unk4.as_hwords[5];
    }
    if (r5->unk8 != 0 && r5->unk5C.unk02_2 == 0)
        return;
    r5->unk5C.unk00 = 2;
    if (r5->unk28 % 30 == 0)
    {
        if (r5->unk2E > gUnknown_082F4444[r5->unk9 - 2])
        {
            ++r5->unk30;
            r5->unk25_4 = 1;
        }
        else
        {
            r5->unk25_4 = 0;
        }
        r5->unk2E = 0;
        ++r5->unk32;
    }
    if (r5->unk28 % 15 == 0)
    {
        if (r5->unk34 < gUnknown_082F4434[r5->unk9 - 2][0])
            r5->unk25_5 = 0;
        else if (r5->unk34 < gUnknown_082F4434[r5->unk9 - 2][1])
            r5->unk25_5 = 1;
        else if (r5->unk34 < gUnknown_082F4434[r5->unk9 - 2][2])
            r5->unk34 = 2; // typo since r5->unk34 will be reset? 
        else if (r5->unk34 < gUnknown_082F4434[r5->unk9 - 2][3])
            r5->unk34 = 3; // typo since r5->unk34 will be reset? 
        else
            r5->unk25_5 = 4;
        r5->unk34 = 0;
    }
    else
    {
        ++r5->unk10;
        if (r5->unk10 > 60)
        {
            if (r5->unk10 > 70)
            {
                sub_8011AC8();
                r5->unk10 = 0;
            }
            else if (r5->unk5C.unk02_3 == 0)
            {
                sub_8011AC8();
                r5->unk10 = 0;
            }
        }
        
    }
    if (r5->unk28 >= 36000)
        r5->unk5C.unk02_0 = 1;
    r5->unk5C.unk02_1 = r5->unk25_4;
    r5->unk5C.unk0A = r5->unk25_5;
    memcpy(r5->unk40.unk2, &r5->unk5C, sizeof(r5->unk40.unk2));
    sub_800FE50(r5->unk40.unk2);
}

void sub_802385C(struct BerryCrushGame *r5)
{
    struct BerryCrushGame_4E *r4_;
#ifndef NONMATCHING
    register u32 r4 asm("r4");
    register u32 r0 asm("r0");

    for (r4 = 0; r4 < r5->unk9; r4 = (u8)r0)
    {
        r5->unk68.as_four_players.others[r4].unk4.as_2d_bytes[1][5] = 0;
        r0 = r4 + 1;
    }
#else
    u8 r4;

    for (r4 = 0; r4 < r5->unk9; ++r4)
        r5->unk68.as_four_players.others[r4].unk4.as_2d_bytes[1][5] = 0;
#endif
    if ((gRecvCmds[0][0] & 0xFF00) != 0x2F00
     || gRecvCmds[0][1] != 2)
    {
        r5->unk25_2 = 0;
    }
    else
    {
        r4_ = &r5->unk40.unkE;
        memcpy(r4_, gRecvCmds, sizeof(struct BerryCrushGame_4E));
        r5->unk2A = r4_->unk6;
        r5->unk2C = r4_->unk5;
        r5->unk28 = r4_->unk8;
        sub_80216E0(r5, &r5->unk138);
        if (r4_->unk4_0)
            r5->unk25_3 = 1;
    }
}

static u32 sub_80238F0(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    memset(&r4->unk5C, 0, sizeof(r4->unk5C));
    memset(&r4->unk40.unkE, 0, sizeof(r4->unk40.unkE));
    sub_802385C(r4);
    SetGpuReg(REG_OFFSET_BG0VOFS, -r4->unk2C);
    SetGpuReg(REG_OFFSET_BG2VOFS, -r4->unk2C);
    SetGpuReg(REG_OFFSET_BG3VOFS, -r4->unk2C);
    if (r4->unk25_3)
    {
        if (r4->unk28 >= 36000)
        {
            r4->unk28 = 36000;
            sub_8022BEC(16, 1, NULL);
        }
        else
        {
            sub_8022BEC(15, 1, NULL);
        }
        r4->unk10 = 0;
        r4->unkC = 0;
        return 0;
    }
    else
    {
        ++r4->unk26;
        sub_802339C(r4);
        sub_8023558(r4);
        sub_80236B8(r4);
        return 0;
    }
}

static u32 sub_8023998(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    memset(&r4->unk5C, 0, sizeof(r4->unk5C));
    memset(&r4->unk40.unkE, 0, sizeof(r4->unk40.unkE));
    sub_802385C(r4);
    SetGpuReg(REG_OFFSET_BG0VOFS, -r4->unk2C);
    SetGpuReg(REG_OFFSET_BG2VOFS, -r4->unk2C);
    SetGpuReg(REG_OFFSET_BG3VOFS, -r4->unk2C);
    if (r4->unk25_3)
    {
        if (r4->unk28 >= 36000)
        {
            r4->unk28 = 36000;
            sub_8022BEC(16, 1, NULL);
        }
        else
        {
            sub_8022BEC(15, 1, NULL);
        }
        r4->unk10 = 0;
        r4->unkC = 0;
        return 0;
    }
    else
    {
        sub_80236B8(r4);
        return 0;
    }
}

static u32 sub_8023A30(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    switch (r4->unkC)
    {
    case 0:
        r4->unk12 = 8;
        PlaySE(SE_W070);
        BlendPalettes(0xFFFFFFFF, 8, RGB(31, 31, 0));
        r4->unk138.unk0 = 2;
        break;
    case 1:
        if (--r4->unk138.unk0 != 255)
            return 0;
        BlendPalettes(0xFFFFFFFF, 0, RGB(31, 31, 0));
        r4->unk138.unk1 = 4;
        r4->unk138.unk0 = 0;
        r4->unk138.unk2 = gUnknown_082F326C[r4->unk138.unk1][0];
        break;
    case 2:
        r4->unk2C = gUnknown_082F326C[r4->unk138.unk1][r4->unk138.unk0];
        SetGpuReg(REG_OFFSET_BG0VOFS, -r4->unk2C);
        SetGpuReg(REG_OFFSET_BG2VOFS, -r4->unk2C);
        SetGpuReg(REG_OFFSET_BG3VOFS, -r4->unk2C);
        if (++r4->unk138.unk0 < r4->unk138.unk2)
            return 0;
        if (r4->unk138.unk1 != 0)
        {
            --r4->unk138.unk1;
            r4->unk138.unk2 = gUnknown_082F326C[r4->unk138.unk1][0];
            r4->unk138.unk0 = 0;
            return 0;
        }
        break;
    case 3:
        r4->unk2C = 0;
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        break;
    case 4:
        if (!sub_80218D4(r4, &r4->unk138))
            return 0;
        sub_8010434();
        r4->unk10 = 0;
        break;
    case 5:
        if (!IsLinkTaskFinished())
            return 0;
        sub_8022BEC(17, 1, NULL);
        r4->unk10 = 0;
        r4->unkC = 0;
        return 0;
    }
    ++r4->unkC;
    return 0;
}

static u32 sub_8023BC0(struct BerryCrushGame *r5, u8 *r6)
{
    switch (r5->unkC)
    {
    case 0:
        r5->unk12 = 9;
        PlaySE(SE_HAZURE);
        BlendPalettes(0xFFFFFFFF, 8, RGB(31, 0, 0));
        r5->unk138.unk0 = 4;
        break;
    case 1:
        if (--r5->unk138.unk0 != 255)
            return 0;
        BlendPalettes(0xFFFFFFFF, 0, RGB(31, 0, 0));
        r5->unk138.unk0 = 0;
        break;
    case 2:
        if (!sub_80218D4(r5, &r5->unk138))
            return 0;
        sub_8010434();
        r5->unk10 = 0;
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        break;
    case 3:
        if (!IsLinkTaskFinished())
            return 0;
        ConvertIntToDecimalStringN(gStringVar1, r5->unk1C, STR_CONV_MODE_LEFT_ALIGN, 6);
        sub_8024644(r6, 7, 1, 0, 0);
        r5->unkE = 19;
        sub_8022BEC(3, 1, NULL);
        r5->unk10 = 0;
        r5->unkC = 0;
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8023CAC(struct BerryCrushGame *r7, __attribute__((unused)) u8 *r1)
{
    u8 r8, r4_;
    s32 r2;
    s32 r4;
    u8 r6; // ???

    switch (r7->unkC)
    {
    case 0:
        memset(r7->unk40.unk2, 0, 2 * sizeof(u16));
        if (r7->unk68.as_four_players.others[r7->unk8].unk4.as_hwords[5] > r7->unk28)
            r7->unk68.as_four_players.others[r7->unk8].unk4.as_hwords[5] = r7->unk28;
        r7->unk40.unk2[0] = r7->unk68.as_four_players.others[r7->unk8].unk4.as_hwords[5];
        SendBlock(0, r7->unk40.unk2, 2);
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        r7->unk10 = 0;
        break;
    case 2:
        if (GetBlockReceivedStatus() != gUnknown_082F4448[r7->unk9 - 2])
            return 0;
        for (r8 = 0; r8 < r7->unk9; ++r8)
            r7->unk68.as_four_players.others[r8].unk4.as_hwords[5] = gBlockRecvBuffer[r8][0];
        r7->unk10 = 0;
        r7->unk40.unk2[0] = 0;
        ResetBlockReceivedFlags();
        if (r7->unk8 == 0)
            r7->unkC = 3;
        else
            r7->unkC = 6;
        return 0;
    case 3:
        memset(
            &r7->unk68,
            0,
            sizeof(struct BerryCrushGame_68_x_SubStruct)
        );
        r7->unk68.as_four_players.unk00.unk04 = r7->unk28;
        r7->unk68.as_four_players.unk00.unk06 = r7->unk18 / (r7->unk28 / 60);
        r2 = sub_8151574(r7->unk30 << 8, 0x3200);
        r2 = sub_81515FC(r2, r7->unk32 << 8) + 0x3200;
        r2 >>= 8;
        r7->unk68.as_four_players.unk00.unk08 = r2 & 0x7F;
        r2 <<= 8;
        r2 = sub_81515FC(r2, 0x6400);
        r4 = (r7->unk1C * r7->unk9) << 8;
        r4 = sub_8151574(r4, r2);
        r7->unk68.as_four_players.unk00.unk00 = r4 >> 8;
        r7->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[0][7] = Random() % 3;
        for (r6 = 0, r8 = 0; r8 < r7->unk9; ++r8)
        {
            r7->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[0][r8] = r8;
            r7->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[1][r8] = r8;
            r7->unk68.as_four_players.unk00.unk0C[0][r8] = r7->unk68.as_four_players.others[r8].unk4.as_hwords[3];
            r7->unk68.as_four_players.unk00.unk0A += r7->unk68.as_four_players.unk00.unk0C[0][r8];
            switch (r7->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[0][7])
            {
            case 0:
                if (r7->unk68.as_four_players.others[r8].unk4.as_hwords[3] != 0)
                {
                    r2 = r7->unk68.as_four_players.others[r8].unk4.as_hwords[2];
                    r2 <<= 8;
                    r2 = sub_8151574(r2, 0x6400);
                    r4 = r7->unk68.as_four_players.others[r8].unk4.as_hwords[3];
                    r4 <<= 8;
                    r4 = sub_81515FC(r2, r4);
                }
                else
                {
                    r4 = 0;
                }
                break;
            case 1:
                if (r7->unk68.as_four_players.others[r8].unk4.as_hwords[3] != 0)
                {
                    r2 = r7->unk68.as_four_players.others[r8].unk4.as_hwords[4];
                    r2 <<= 8;
                    r2 = sub_8151574(r2, 0x6400);
                    r4 = r7->unk68.as_four_players.others[r8].unk4.as_hwords[3];
                    r4 <<= 8;
                    r4 = sub_81515FC(r2, r4);
                }
                else
                {
                    r4 = 0;
                }
                break;
            case 2:
                if (r7->unk68.as_four_players.others[r8].unk4.as_hwords[3] == 0)
                {
                    r4 = 0;
                }
                else if (r7->unk68.as_four_players.others[r8].unk4.as_hwords[5] >= r7->unk28)
                {
                    r4 = 0x6400;
                }
                else
                {
                    r2 = r7->unk68.as_four_players.others[r8].unk4.as_hwords[5];
                    r2 <<= 8;
                    r2 = sub_8151574(r2, 0x6400);
                    r4 = r7->unk28;
                    r4 <<= 8;
                    r4 = sub_81515FC(r2, r4);
                }
                break;
            }
            r4 >>= 4;
            r7->unk68.as_four_players.unk00.unk0C[1][r8] = r4;
        }
        break;
    case 4:
        for (r6 = 0, r8 = 0; r8 < r7->unk9 - 1; ++r8)
        {
            for (r4_ = r7->unk9 - 1; r4_ > r8; --r4_)
            {
                u16 r0;
                u8 r3;
                u16 *sp00 = r7->unk68.as_four_players.unk00.unk0C[0];
                u8 *sp04 = r7->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[0];
                u8 *r10 = r7->unk68.as_five_players.unk1C[0].unk4.as_2d_bytes[1];
                u16 *r9 = r7->unk68.as_four_players.unk00.unk0C[1];
                s32 r12 = r4_ - 1;
                u16 *p1 = sp00 + r12; // these have to be here
                u16 *p2 = sp00 + r4_; // to swap operands. macro? 

                if (*p1 < *p2)
                {
                    r0 = sp00[r4_];
                    sp00[r4_] = sp00[r12];
                    sp00[r12] = r0;
                    r3 = sp04[r4_];
                    sp04[r4_] = sp04[r12];
                    sp04[r12] = r3;
                }
                p1 = r9 + r12;
                p2 = r9 + r4_;
                if (*p1 < *p2)
                {
                    r0 = r9[r4_];
                    r9[r4_] = r9[r12];
                    r9[r12] = r0;
                    r3 = r10[r4_];
                    r10[r4_] = r10[r12];
                    r10[r12] = r3;
                }
            }
        }
        SendBlock(
            0,
            &r7->unk68,
            sizeof(struct BerryCrushGame_68_x_SubStruct)
        );
        break;
    case 5:
        if (!IsLinkTaskFinished())
            return 0;
        r7->unk10 = 0;
        break;
    case 6:
        if (GetBlockReceivedStatus() != 1)
            return 0;
        memset(
            &r7->unk68,
            0,
            sizeof(struct BerryCrushGame_68_x_SubStruct)
        );
        memcpy(
            &r7->unk68,
            gBlockRecvBuffer,
            sizeof(struct BerryCrushGame_68_x_SubStruct)
        );
        ResetBlockReceivedFlags();
        r7->unk10 = 0;
        break;
    case 7:
        sub_8020E58();
        sub_8022BEC(18, 1, NULL);
        r7->unk12 = 11;
        r7->unkC = 0;
        r7->unk24 = 0;
        return 0;
    }
    ++r7->unkC;
    return 0;
}

static u32 sub_8024048(struct BerryCrushGame *r5, u8 *r6)
{
    switch (r5->unkC)
    {
    case 0:
        if (!sub_8022070(r5, &r5->unk138))
            return 0;
        break;
    case 1:
        CopyBgTilemapBufferToVram(0);
        r5->unk138.unk0 = 30;
        break;
    case 2:
        if (r5->unk138.unk0 != 0)
        {
            --r5->unk138.unk0;
            return 0;
        }
        if (!(gMain.newKeys & A_BUTTON))
            return 0;
        PlaySE(SE_SELECT);
        sub_802222C(r5);
        break;
    case 3:
        if (r5->unk12 <= 12)
        {
            ++r5->unk12;
            r5->unkC = 0;
            return 0;
        }
        break;
    case 4:
        ConvertIntToDecimalStringN(gStringVar1, r5->unk1C, STR_CONV_MODE_LEFT_ALIGN, 6);
        ConvertIntToDecimalStringN(gStringVar2, GetBerryPowder(), STR_CONV_MODE_LEFT_ALIGN, 6);
        sub_8024644(r6, 2, 3, 0, 0);
        r5->unkE = 19;
        sub_8022BEC(3, 1, NULL);
        r5->unkC = 0;
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8024134(struct BerryCrushGame *r5, u8 *r4)
{
    switch (r5->unkC)
    {
    case 0:
        if (r5->unk28 >= 36000)
            sub_8022554(&r5->unk138);
        sub_8024644(r4, 8, 0, 0, 1);
        r5->unkE = 19;
        sub_8022BEC(3, 1, NULL);
        r5->unkC = 0;
        return 0;
    case 1:
        sub_8010434();
        break;
    case 2:
        if (!IsLinkTaskFinished())
            return 0;
        DrawDialogueFrame(0, 0);
        AddTextPrinterParameterized2(0, 1, gText_SavingDontTurnOffPower, 0, 0, 2, 1, 3);
        CopyWindowToVram(0, 3);
        CreateTask(sub_8153688, 0);
        break;
    case 3:
        if (FuncIsActiveTask(sub_8153688))
            return 0;
        break;
    case 4:
        sub_8022BEC(20, 1, NULL);
        r5->unk12 = 15;
        r5->unkC = 0;
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8024228(struct BerryCrushGame *r5, u8 *r6)
{
    s32 r4;
#ifndef NONMATCHING
    register s32 r0 asm("r0");
#else
    s32 r0;
#endif

    switch (r5->unkC)
    {
    case 0:
        sub_8024644(r6, 4, 0, 0, 1);
        r5->unkE = 20;
        sub_8022BEC(3, 1, NULL);
        r0 = 0;
        r5->unkC = r0; // dunno what it's doing because it's already in case 0
        return 0;
    case 1:
        DisplayYesNoMenuDefaultYes();
        break;
    case 2:
        if ((r4 = Menu_ProcessInputNoWrapClearOnChoose()) != -2)
        {
            memset(r5->unk40.unk2, 0, sizeof(r5->unk40.unk2));
            if (r4 == 0)
            {
                if (HasAtLeastOneBerry())
                    r5->unk14 = 0;
                else
                    r5->unk14 = 3;
            }
            else
            {
                r5->unk14 = 1;
            }
            ClearDialogWindowAndFrame(0, 1);
            sub_8024644(r6, 8, 0, 0, 0);
            r5->unkE = 21;
            sub_8022BEC(3, 1, NULL);
            r5->unkC = 0;
        }
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_80242E0(struct BerryCrushGame *r4, __attribute__((unused)) u8 *r1)
{
    u8 r5 = 0;

    switch (r4->unkC)
    {
    case 0:
        sub_8010434();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        r4->unk40.unk2[0] = r4->unk14;
        r4->unk40.unkE.unk0 = 0;
        SendBlock(0, r4->unk40.unk2, sizeof(u16));
        break;
    case 2:
        if (!IsLinkTaskFinished())
            return 0;
        r4->unk10 = 0;
        break;
    case 3:
        if (GetBlockReceivedStatus() != gUnknown_082F4448[r4->unk9 - 2])
            return 0;
        for (; r5 < r4->unk9; ++r5)
            r4->unk40.unkE.unk0 += gBlockRecvBuffer[r5][0];
        if (r4->unk40.unkE.unk0 != 0)
            sub_8022BEC(23, 1, NULL);
        else
            sub_8022BEC(22, 1, NULL);
        ResetBlockReceivedFlags();
        r4->unk40.unk2[0] = 0;
        r4->unk40.unkE.unk0 = 0;
        r4->unk10 = 0;
        r4->unkC = 0;
        return 0;
    }
    ++r4->unkC;
    return 0;
}

static u32 sub_80243BC(struct BerryCrushGame *r5, __attribute__((unused)) u8 *r1)
{
    switch (r5->unkC)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 1, 0, 0x10, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 1:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 2:
        ClearDialogWindowAndFrame(0, 1);
        sub_8021488(r5);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 3:
        if (UpdatePaletteFade())
            return 0;
        sub_8022BEC(7, 1, NULL);
        r5->unk12 = 3;
        r5->unkC = 0;
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8024444(struct BerryCrushGame *r5, __attribute__((unused)) u8 *r1)
{
    switch (r5->unkC)
    {
    case 0:
        DrawDialogueFrame(0, 0);
        if (r5->unk14 == 3)
            AddTextPrinterParameterized2(0, 1, gUnknown_082F32A4[5], r5->unkB, 0, 2, 1, 3);
        else
            AddTextPrinterParameterized2(0, 1, gUnknown_082F32A4[6], r5->unkB, 0, 2, 1, 3);
        CopyWindowToVram(0, 3);
        break;
    case 1:
        if (IsTextPrinterActive(0))
            return 0;
        r5->unk138.unk0 = 120;
        break;
    case 2:
        if (r5->unk138.unk0 != 0)
            --r5->unk138.unk0;
        else
        {
            sub_8022BEC(24, 1, NULL);
            r5->unkC = 0;
        }
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8024508(struct BerryCrushGame *r5, __attribute__((unused)) u8 *r1)
{
    switch (r5->unkC)
    {
    case 0:
        sub_8010434();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        sub_800AC34();
        break;
    case 2:
        if (gReceivedRemoteLinkPlayers != 0)
            return 0;
        r5->unkE = 25;
        sub_8022BEC(5, 1, NULL);
        r5->unkC = 2; // ???
        return 0;
    }
    ++r5->unkC;
    return 0;
}

static u32 sub_8024568(__attribute__((unused)) struct BerryCrushGame *r0, __attribute__((unused)) u8 *r1)
{
    sub_8020C0C(NULL);
    return 0;
}

void sub_8024578(struct BerryCrushGame *r4)
{
    u8 r5 = 0;

    IncrementGameStat(GAME_STAT_51);
    r4->unkD = 0;
    r4->unk10 = 0;
    r4->unk12 = 2;
    r4->unk14 = 0;
    r4->unk1C = 0;
    r4->unk18 = 0;
    r4->unk1A = 0;
    r4->unk20 = 0;
    r4->unk24 = 0;
    r4->unk25_0 = 0;
    r4->unk25_1 = 0;
    r4->unk25_2 = 0;
    r4->unk25_3 = 0;
    r4->unk25_4 = 0;
    r4->unk25_5 = 0;
    r4->unk26 = 0;
    r4->unk28 = 0;
    r4->unk2E = 0;
    r4->unk32 = -1;
    r4->unk30 = 0;
    r4->unk34 = 0;
    for (; r5 < 5; ++r5) // why is it 5 instead of 4? fillerBC isn't sufficient for one player
    {
        r4->unk68.as_four_players.others[r5].unk0 = -1;
        r4->unk68.as_four_players.others[r5].unk2 = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_hwords[0] = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_hwords[1] = 1;
        r4->unk68.as_four_players.others[r5].unk4.as_hwords[2] = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_hwords[3] = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_hwords[4] = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_hwords[5] = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_2d_bytes[1][4] = 0;
        r4->unk68.as_four_players.others[r5].unk4.as_2d_bytes[1][5] = 0;
    }
}

#ifdef NONMATCHING
void sub_8024604(u8 *r0, u32 r1, s32 r2, u32 r3, u32 r5, u32 r6, u32 r4)
{
    u8 sp[8];
    u8 *p;

    1[(u32 *)sp] = r2;
    0[(u16 *)sp] = r4;
    p = &sp[4];
    r0[0] = p[0];
    r0[1] = p[1];
    r0[2] = p[2];
    r0[3] = p[3];
    r0[4] = r3;
    r0[5] = r5;
    r0[6] = r6;
    r0[7] = sp[0];
    r0[8] = sp[1];
    r0[9] = r1;
}
#else
NAKED
void sub_8024604(u8 *r0, u32 r1, s32 r2, u32 r3, u32 r5, u32 r6, u32 r4)
{
    asm_unified("\n\
        push {r4-r6,lr}\n\
        sub sp, 0x8\n\
        str r2, [sp, 0x4]\n\
        ldr r5, [sp, 0x18]\n\
        ldr r6, [sp, 0x1C]\n\
        ldr r4, [sp, 0x20]\n\
        mov r2, sp\n\
        strh r4, [r2]\n\
        add r4, sp, 0x4\n\
        ldrb r2, [r4]\n\
        strb r2, [r0]\n\
        ldrb r2, [r4, 0x1]\n\
        strb r2, [r0, 0x1]\n\
        ldrb r2, [r4, 0x2]\n\
        strb r2, [r0, 0x2]\n\
        ldrb r2, [r4, 0x3]\n\
        strb r2, [r0, 0x3]\n\
        strb r3, [r0, 0x4]\n\
        strb r5, [r0, 0x5]\n\
        strb r6, [r0, 0x6]\n\
        mov r2, sp\n\
        ldrb r2, [r2]\n\
        strb r2, [r0, 0x7]\n\
        mov r2, sp\n\
        ldrb r2, [r2, 0x1]\n\
        strb r2, [r0, 0x8]\n\
        strb r1, [r0, 0x9]\n\
        add sp, 0x8\n\
        pop {r4-r6}\n\
        pop {r0}\n\
        bx r0");
}
#endif

void sub_8024644(u8 *r0, u32 r1, u32 r2, u32 r3, u32 r5)
{
    u8 sp[4];

    0[(u16 *)sp] = r3;
    r0[0] = r1;
    r0[1] = r2;
    r0[2] = sp[0];
    r0[3] = sp[1];
    r0[4] = r5;
}
