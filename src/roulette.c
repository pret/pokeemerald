#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "coins.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "roulette.h"
#include "roulette_util.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "tv.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/species.h"
#include "constants/songs.h"

struct StructgUnknown_083F8DF4
{
    u8 var00;
    u8 var01;
    u8 var02;
    u8 var03;
    u8 var04;
    u8 filler_05[3];
    u16 var08;
    u16 var0A;
    u16 var0C;
    u8 filler_0E[2];
    u16 var10;
    u16 var12;
    u16 var14;
    u8 filler_16[2];
    u16 var18;
    u16 var1A;
    float var1C;
};

struct StructgUnknown_085B6154
{
    u8 var00;
    u8 var01_0:4;
    u8 var01_4:4;
    u8 var02;
    u8 var03;
    u8 var04;
    u8 var05;
    u8 var06;
    u32 var08;
    u32 var0C;
    u16 var10;
};

struct StructgUnknown_083F8D90
{
    u8 var00;
    u8 var01;
    u8 var02;
    u32 var04;
};

EWRAM_DATA struct Roulette
{
    u8 var00;
    u8 var01;
    u8 var02;
    u8 var03_0:5;
    u8 var03_5:1;
    u8 var03_6:1;
    u8 var03_7:1;
    u8 var04_0:2;
    u8 var04_2:5;
    u8 var04_7:1;
    u32 var08;
    u8 var0C[6];
    u8 var12[4];
    u8 var16[3];
    u8 var19;
    u8 var1A_0:4;
    u8 var1A_4:4;
    u8 var1B[6];
    u8 var21;
    u8 var22;
    u8 var23;
    s16 var24;
    s16 var26;
    s16 var28;
    s16 var2A;
    struct OamMatrix var2C;
    u16 var34;
    struct Sprite *var38;
    u8 var3C[MAX_SPRITES]; // Sprite IDs
    u8 var7C;
    u8 var7D;
    u8 var7E;
    u8 var7F;
    s16 var80;
    s16 var82;
    u16 var84;
    u16 var86;
    float var88;
    float var8C;
    float var90;
    float var94;
    float var98;
    float var9C;
    float varA0;
    u8 varA4;
    u8 varA5;
    u8 v51[2];
    u16 varA8;
    u16 varAA;
    TaskFunc varAC;
    u8 v46[4];
    TaskFunc varB4;
    struct UnkStruct0 varB8;
    u16 tilemapBuffers[7][0x400];
    u16 *unk_397C;
} *gUnknown_0203AB88 = NULL;
EWRAM_DATA u8 gUnknown_0203AB8C = 0;

static void sub_8140814(u8);
static void sub_81408A8(u8);
static void sub_8140968(u8);
static void sub_8140994(u8);
static void sub_8140BD0(u8);
static void sub_8141040(u8);
static void sub_81410FC(u8);
static void sub_8141344(u8);
static void sub_814155C(u8);
static void sub_81415D4(u8);
static void sub_81416D4(u8);
static void sub_8141778(u8);
static void sub_814189C(u8);
static void sub_8141A18(u8);
static void sub_8141AC0(u8);
static void sub_8141B58(u8);
static void dp01t_12_3_battle_menu(u8);
static void sub_8141DE4(u8);
static void sub_8141E7C(u8);
static void sub_8141F7C(u8 taskId, TaskFunc r1, u16 r2, u16 r3);
static void sub_8141FF4(u8);
static void sub_8142070(void);
static void sub_8142918(u8);
static void sub_814297C(u8);
static u8 sub_81420D0(u8, u8);
static bool8 sub_81421E8(u8, u8);
static void sub_8142284(u8);
static void sub_81424FC(u8);
static u8 sub_8142758(u8);
static void sub_8142814(void);
static void sub_8142C0C(u8);
static void sub_8142CD0(void);
static void sub_8142E70(u8, u8);
static void sub_8142F7C(void);
static void sub_8143038(u8, u8);
static void sub_8143150(u8);
static void sub_81431E4(void);
static void sub_8143280(struct Sprite *);
static void sub_8143314(void);
static void sub_8143514(u16);
static void sub_81436D0(u8);
static void sub_814372C(u8);
static void sub_814390C(struct Sprite *);
static void sub_814391C(void);
static void sub_814399C(struct Sprite *);
static void sub_81439C8(void);
static void sub_8143A40(void);
static void sub_81446AC(struct Sprite *);
static void sub_81446DC(struct Sprite *);
static void sub_81448B8(struct Sprite *);
static void sub_8144A24(struct Sprite *);
static void sub_8144E60(struct Sprite *);
static void sub_8145294(struct Sprite *);

extern const u8 Roulette_Text_ControlsInstruction[];
extern const u8 Roulette_Text_KeepPlaying[];
extern const u8 Roulette_Text_Jackpot[];
extern const u8 Roulette_Text_ItsAHit[];
extern const u8 Roulette_Text_NothingDoing[];
extern const u8 Roulette_Text_YouveWonXCoins[];
extern const u8 Roulette_Text_BoardWillBeCleared[];
extern const u8 Roulette_Text_CoinCaseIsFull[];
extern const u8 Roulette_Text_NoCoinsLeft[];
extern const u8 Roulette_Text_PlayMinimumWagerIsX[];
extern const u8 Roulette_Text_SpecialRateTable[];
extern const u8 Roulette_Text_NotEnoughCoins[];

static const u16 gUnknown_085B5BFC[] = INCBIN_U16("graphics/roulette/85B5BFC.gbapal");
static const u32 gUnknown_085B5DFC[] = INCBIN_U32("graphics/roulette/85B5DFC.bin.lz");
static const u32 gUnknown_085B5FA0[] = INCBIN_U32("graphics/roulette/wheel_map.bin.lz");
static const struct BgTemplate gUnknown_085B6140[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 4,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 6,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 2,
        .baseTile = 0
    }
};
static const struct WindowTemplate gUnknown_085B614C[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xC5
    },
    // BUG: Array not terminated properly
    //DUMMY_WIN_TEMPLATE
};
static const struct StructgUnknown_085B6154 gUnknown_085B6154[] =
{
    {
        .var00 = 0xFF,
        .var01_0 = 0,
        .var01_4 = 0,
        .var02 = 0,
        .var03 = 7,
        .var04 = 7,
        .var05 = 0,
        .var06 = 0,
        .var08 = 0x0,
        .var0C = 0x0,
        .var10 = 0x0,
    },
    {
        .var00 = 12,
        .var01_0 = 4,
        .var01_4 = 1,
        .var02 = 0,
        .var03 = 17,
        .var04 = 7,
        .var05 = 0,
        .var06 = 0,
        .var08 = 0x2,
        .var0C = 0x10842,
        .var10 = 0xE000,
    },
    {
        .var00 = 13,
        .var01_0 = 4,
        .var01_4 = 2,
        .var02 = 0,
        .var03 = 20,
        .var04 = 7,
        .var05 = 0,
        .var06 = 0,
        .var08 = 0x4,
        .var0C = 0x21084,
        .var10 = 0xE000,
    },
    {
        .var00 = 14,
        .var01_0 = 4,
        .var01_4 = 3,
        .var02 = 0,
        .var03 = 23,
        .var04 = 7,
        .var05 = 0,
        .var06 = 0,
        .var08 = 0x8,
        .var0C = 0x42108,
        .var10 = 0xE000,
    },
    {
        .var00 = 15,
        .var01_0 = 4,
        .var01_4 = 4,
        .var02 = 0,
        .var03 = 26,
        .var04 = 7,
        .var05 = 0,
        .var06 = 0,
        .var08 = 0x10,
        .var0C = 0x84210,
        .var10 = 0xE000,
    },
    {
        .var00 = 16,
        .var01_0 = 3,
        .var01_4 = 0,
        .var02 = 1,
        .var03 = 14,
        .var04 = 10,
        .var05 = 0,
        .var06 = 12,
        .var08 = 0x20,
        .var0C = 0x3E0,
        .var10 = 0x249,
    },
    {
        .var00 = 0,
        .var01_0 = 12,
        .var01_4 = 1,
        .var02 = 1,
        .var03 = 17,
        .var04 = 10,
        .var05 = 3,
        .var06 = 3,
        .var08 = 0x40,
        .var0C = 0x40,
        .var10 = 0x2001,
    },
    {
        .var00 = 9,
        .var01_0 = 12,
        .var01_4 = 2,
        .var02 = 1,
        .var03 = 20,
        .var04 = 10,
        .var05 = 3,
        .var06 = 3,
        .var08 = 0x80,
        .var0C = 0x80,
        .var10 = 0x2200,
    },
    {
        .var00 = 6,
        .var01_0 = 12,
        .var01_4 = 3,
        .var02 = 1,
        .var03 = 23,
        .var04 = 10,
        .var05 = 3,
        .var06 = 3,
        .var08 = 0x100,
        .var0C = 0x100,
        .var10 = 0x2040,
    },
    {
        .var00 = 3,
        .var01_0 = 12,
        .var01_4 = 4,
        .var02 = 1,
        .var03 = 26,
        .var04 = 10,
        .var05 = 3,
        .var06 = 3,
        .var08 = 0x200,
        .var0C = 0x200,
        .var10 = 0x2008,
    },
    {
        .var00 = 17,
        .var01_0 = 3,
        .var01_4 = 0,
        .var02 = 2,
        .var03 = 14,
        .var04 = 13,
        .var05 = 3,
        .var06 = 15,
        .var08 = 0x400,
        .var0C = 0x7C00,
        .var10 = 0x492,
    },
    {
        .var00 = 4,
        .var01_0 = 12,
        .var01_4 = 1,
        .var02 = 2,
        .var03 = 17,
        .var04 = 13,
        .var05 = 6,
        .var06 = 6,
        .var08 = 0x800,
        .var0C = 0x800,
        .var10 = 0x2010,
    },
    {
        .var00 = 1,
        .var01_0 = 12,
        .var01_4 = 2,
        .var02 = 2,
        .var03 = 20,
        .var04 = 13,
        .var05 = 6,
        .var06 = 6,
        .var08 = 0x1000,
        .var0C = 0x1000,
        .var10 = 0x2002,
    },
    {
        .var00 = 10,
        .var01_0 = 12,
        .var01_4 = 3,
        .var02 = 2,
        .var03 = 23,
        .var04 = 13,
        .var05 = 6,
        .var06 = 6,
        .var08 = 0x2000,
        .var0C = 0x2000,
        .var10 = 0x2400,
    },
    {
        .var00 = 7,
        .var01_0 = 12,
        .var01_4 = 4,
        .var02 = 2,
        .var03 = 26,
        .var04 = 13,
        .var05 = 6,
        .var06 = 6,
        .var08 = 0x4000,
        .var0C = 0x4000,
        .var10 = 0x2080,
    },
    {
        .var00 = 18,
        .var01_0 = 3,
        .var01_4 = 0,
        .var02 = 3,
        .var03 = 14,
        .var04 = 16,
        .var05 = 6,
        .var06 = 18,
        .var08 = 0x8000,
        .var0C = 0xF8000,
        .var10 = 0x924,
    },
    {
        .var00 = 8,
        .var01_0 = 12,
        .var01_4 = 1,
        .var02 = 3,
        .var03 = 17,
        .var04 = 16,
        .var05 = 9,
        .var06 = 9,
        .var08 = 0x10000,
        .var0C = 0x10000,
        .var10 = 0x2100,
    },
    {
        .var00 = 5,
        .var01_0 = 12,
        .var01_4 = 2,
        .var02 = 3,
        .var03 = 20,
        .var04 = 16,
        .var05 = 9,
        .var06 = 9,
        .var08 = 0x20000,
        .var0C = 0x20000,
        .var10 = 0x2020,
    },
    {
        .var00 = 2,
        .var01_0 = 12,
        .var01_4 = 3,
        .var02 = 3,
        .var03 = 23,
        .var04 = 16,
        .var05 = 9,
        .var06 = 9,
        .var08 = 0x40000,
        .var0C = 0x40000,
        .var10 = 0x2004,
    },
    {
        .var00 = 11,
        .var01_0 = 12,
        .var01_4 = 4,
        .var02 = 3,
        .var03 = 26,
        .var04 = 16,
        .var05 = 9,
        .var06 = 9,
        .var08 = 0x80000,
        .var0C = 0x80000,
        .var10 = 0x2800,
    },
};

static const struct StructgUnknown_083F8D90 gUnknown_085B62E4[] =
{
    {
        .var00 = 0,
        .var01 = 1,
        .var02 = 6,
        .var04 = 0x40,
    },
    {
        .var00 = 1,
        .var01 = 3,
        .var02 = 12,
        .var04 = 0x1000,
    },
    {
        .var00 = 2,
        .var01 = 5,
        .var02 = 18,
        .var04 = 0x40000,
    },
    {
        .var00 = 3,
        .var01 = 7,
        .var02 = 9,
        .var04 = 0x200,
    },
    {
        .var00 = 4,
        .var01 = 9,
        .var02 = 11,
        .var04 = 0x800,
    },
    {
        .var00 = 5,
        .var01 = 11,
        .var02 = 17,
        .var04 = 0x20000,
    },
    {
        .var00 = 6,
        .var01 = 13,
        .var02 = 8,
        .var04 = 0x100,
    },
    {
        .var00 = 7,
        .var01 = 15,
        .var02 = 14,
        .var04 = 0x4000,
    },
    {
        .var00 = 8,
        .var01 = 17,
        .var02 = 16,
        .var04 = 0x10000,
    },
    {
        .var00 = 9,
        .var01 = 19,
        .var02 = 7,
        .var04 = 0x80,
    },
    {
        .var00 = 10,
        .var01 = 21,
        .var02 = 13,
        .var04 = 0x2000,
    },
    {
        .var00 = 11,
        .var01 = 23,
        .var02 = 19,
        .var04 = 0x80000,
    },
};
static const u8 gUnknown_085B6344[] = {1, 3, 1, 6};
static const struct StructgUnknown_083F8DF4 gUnknown_085B6348[] =
{
    {
        .var00 = 1,
        .var01 = 60,
        .var02 = 30,
        .var03 = 1,
        .var04 = 1,
        .var08 = 45,
        .var0A = 30,
        .var0C = 1,
        .var10 = 75,
        .var12 = 27,
        .var14 = 24,
        .var18 = 10,
        .var1A = 360,
        .var1C = -0.5f
    },
    {
        .var00 = 3,
        .var01 = 30,
        .var02 = 15,
        .var03 = 1,
        .var04 = 0,
        .var08 = 75,
        .var0A = 60,
        .var0C = 2,
        .var10 = 0,
        .var12 = 54,
        .var14 = 48,
        .var18 = 10,
        .var1A = 270,
        .var1C = -1.0f
    }
};

static const struct UnkStruct1 gUnknown_085B6388[] =
{
    {
        .var00 = 0x8000,
        .var02 = 0x0005,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x000A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0015,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0055,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x005A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0065,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0075,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x007A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0085,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0095,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x009A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x00A5,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x77D6,
        .var02 = 0x0028,
        .var04 = 2,
        .var05 = 10,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = 2,
        .var07_7 = 0
    },
};

static const struct UnkStruct1 gUnknown_085B63F0[] =
{
    {
        .var00 = 0x53FF,
        .var02 = 0x0101,
        .var04 = 5,
        .var05 = 30,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x7FFB,
        .var02 = 0x0106,
        .var04 = 5,
        .var05 = 30,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = 2,
        .var07_7 = 0
    },
    {
        .var00 = 0x7F7F,
        .var02 = 0x010B,
        .var04 = 5,
        .var05 = 30,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = 2,
        .var07_7 = 0
    }
};

static const struct YesNoFuncTable gUnknown_085B6408 =
{
    sub_8142918,
    sub_814297C
};

static const struct YesNoFuncTable gUnknown_085B6410 =
{
    sub_8140968,
    sub_8140994
};

static void sub_8140238(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	if (gUnknown_0203AB88->varB8.var00)
	   task_tutorial_controls_fadein(&gUnknown_0203AB88->varB8);
}

static void sub_8140264(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_8142814();
    SetGpuReg(REG_OFFSET_BG1HOFS, 0x200 - gUnknown_0203AB88->var26);
    if (gUnknown_0203AB88->var01)
        SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0203AB88->var34);
    if (gUnknown_0203AB88->var2A != 0)
    {
        DmaCopy16(3, &gUnknown_0203AB88->tilemapBuffers[2][0xE0], (void *)BG_SCREEN_ADDR(4) + 0x1C0, 0x340);
        gUnknown_0203AB88->var2A = 0;
    }
    switch (gUnknown_0203AB88->var28)
    {
    case 1:
        SetBgAttribute(0, BG_ATTR_CHARBASEINDEX, 0);
        ShowBg(0);
        DmaCopy16(3, &gUnknown_0203AB88->tilemapBuffers[0][0xE0], (void *)BG_SCREEN_ADDR(31) + 0x1C0, 0x340);
        gUnknown_0203AB88->var28 = 2;
        break;
    case 2:
        DmaCopy16(3, &gUnknown_0203AB88->tilemapBuffers[0][0xE0], (void *)BG_SCREEN_ADDR(31) + 0x1C0, 0x340);
        break;
    case 0xFF:
        SetBgAttribute(0, BG_ATTR_CHARBASEINDEX, 2);
        ShowBg(0);
        DmaFill16(3, 0, (void *)BG_SCREEN_ADDR(31) + 0x1C0, 0x340);
        gUnknown_0203AB88->var28 = 0;
    case 0:
        break;
    }
}

static void sub_8140388(void)
{
    u32 size = 0;

    gUnknown_0203AB88 = AllocZeroed(sizeof(*gUnknown_0203AB88));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, gUnknown_085B6140, ARRAY_COUNT(gUnknown_085B6140));
    SetBgTilemapBuffer(0, gUnknown_0203AB88->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, gUnknown_0203AB88->tilemapBuffers[2]);
    SetBgTilemapBuffer(2, gUnknown_0203AB88->tilemapBuffers[6]);
    InitWindows(gUnknown_085B614C);
    sub_8197200();
    gUnknown_0203AB8C = 0;
    gUnknown_0203AB88->unk_397C = malloc_and_decompress(gUnknown_085B5DFC, &size);
}

static void sub_8140418(void)
{
    FREE_AND_SET_NULL(gUnknown_0203AB88->unk_397C);
    FreeAllWindowBuffers();
    UnsetBgTilemapBuffer(0);
    UnsetBgTilemapBuffer(1);
    UnsetBgTilemapBuffer(2);
    ResetBgsAndClearDma3BusyFlags(0);
    memset(gUnknown_0203AB88, 0, sizeof(*gUnknown_0203AB88));
    FREE_AND_SET_NULL(gUnknown_0203AB88);
}

static void sub_8140470(void)
{
    u8 i;
    u16 arr[3] = {RGB(24, 4, 10), RGB(10, 19, 6), RGB(24, 4, 10)}; // the third is never used ?

    gUnknown_0203AB88->var04_0 = (gSpecialVar_0x8004 & 1);

    if (gSpecialVar_0x8004 & 0x80)
        gUnknown_0203AB88->var04_7 = 1;

    gUnknown_0203AB88->var22 = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var03;
    gUnknown_0203AB88->var23 = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var04;
    gUnknown_0203AB88->var19 = gUnknown_085B6344[gUnknown_0203AB88->var04_0 + gUnknown_0203AB88->var04_7 * 2];
    gUnknown_0203AB88->var1A_4 = 1;

    if (gUnknown_0203AB88->var19 == 1)
        gPlttBufferUnfaded[0] = gPlttBufferUnfaded[0x51] = gPlttBufferFaded[0] = gPlttBufferFaded[0x51] = arr[0];
    else
        gPlttBufferUnfaded[0] = gPlttBufferUnfaded[0x51] = gPlttBufferFaded[0] = gPlttBufferFaded[0x51] = arr[1];

    sub_8151678(&gUnknown_0203AB88->varB8);

    for (i = 0; i < 13; i++)
    {
        sub_815168C(&gUnknown_0203AB88->varB8, i, &gUnknown_085B6388[i]);
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        switch (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2))
        {
        case SPECIES_SHROOMISH:
            gUnknown_0203AB88->var02 |= 0x1;
            break;
        case SPECIES_TAILLOW:
            gUnknown_0203AB88->var02 |= 0x2;
            break;
        }
    }
    RtcCalcLocalTime();
}

static void sub_81405CC(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ResetAllBgsCoordinates();
        break;
    case 1:
        sub_8140388();
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE |
                                     BLDCNT_TGT2_BG2 |
                                     BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(10, 6));
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        reset_temp_tile_data_buffers();
        break;
    case 3:
        LoadPalette(&gUnknown_085B5BFC, 0, 0x1C0);
        decompress_and_copy_tile_data_to_vram(1, gRouletteMenuTiles, 0, 0, 0);
        decompress_and_copy_tile_data_to_vram(2, gRouletteWheelTiles, 0, 0, 0);
        break;
    case 4:
        if (free_temp_tile_data_buffers_if_possible())
            return;

        sub_8140470();
        CopyToBgTilemapBuffer(2, gUnknown_085B5FA0, 0, 0);
        break;
    case 5:
        sub_8142C0C(0);
        sub_81439C8();
        sub_814391C();
        sub_8143314();
        sub_8142CD0();
        sub_8142F7C();
        sub_81431E4();
        break;
    case 6:
        AnimateSprites();
        BuildOamBuffer();
        sub_8143514(GetCoins());
        sub_814372C(6);
        sub_81436D0(0);
        sub_81424FC(0);
        DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_ControlsInstruction, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        gSpriteCoordOffsetX = -60;
        gSpriteCoordOffsetY = 0;
        break;
    case 7:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_OBJ_ON);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        break;
    case 8:
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(sub_8140264);
        BeginHardwarePaletteFade(0xFF, 0, 16, 0, 1);
        taskId = gUnknown_0203AB88->varA4 = CreateTask(sub_81408A8, 0);
        gTasks[taskId].data[6] = 6;
        gTasks[taskId].data[13] = GetCoins();
        AlertTVThatPlayerPlayedRoulette(GetCoins());
        gUnknown_0203AB88->varA5 = CreateTask(sub_8140814, 1);
        SetMainCallback2(sub_8140238);
        return;
    }
    gMain.state++;
}

static void sub_8140814(u8 unused)
{
    s16 sin;
    s16 cos;

    if (gUnknown_0203AB88->var21++ == gUnknown_0203AB88->var23)
    {
        gUnknown_0203AB88->var21 = 0;
        if ((gUnknown_0203AB88->var24 -= gUnknown_0203AB88->var22) < 0)
            gUnknown_0203AB88->var24 = 360 - gUnknown_0203AB88->var22;
    }
    sin = Sin2(gUnknown_0203AB88->var24);
    cos = Cos2(gUnknown_0203AB88->var24);
    sin = sin / 16;
    gUnknown_0203AB88->var2C.a = gUnknown_0203AB88->var2C.d = cos / 16;
    gUnknown_0203AB88->var2C.b =  sin;
    gUnknown_0203AB88->var2C.c = -sin;
}

static void sub_81408A8(u8 taskId)
{
    if (UpdatePaletteFade() == 0)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE |
                                     BLDCNT_TGT2_BG2 |
                                     BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        gTasks[taskId].data[6] = 0;
        sub_8141FF4(taskId);
        sub_8142070();
        sub_8143A40();
        sub_81424FC(0);
        sub_814372C(6);
        sub_8141F7C(taskId, sub_8140968, 0xFFFF, 0x3);
    }
}

static void sub_8140914(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    DrawStdWindowFrame(gUnknown_0203AB8C, 0);
    AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_KeepPlaying, 0, 1, TEXT_SPEED_FF, 0);
    CopyWindowToVram(gUnknown_0203AB8C, 3);
    DoYesNoFuncWithChoice(taskId, &gUnknown_085B6410);
}

static void sub_8140968(u8 taskId)
{
    ClearStdWindowAndFrame(0, TRUE);
    gTasks[taskId].func = sub_8140BD0;
}

static void sub_8140994(u8 taskId)
{
    DestroyTask(gUnknown_0203AB88->varA5);
    sub_8141DE4(taskId);
}

static void sub_81409B8(u8 r0)
{
    u8 temp0, temp1;
    switch (r0)
    {
    case 0:
        sub_8152008(&gUnknown_0203AB88->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        temp0 = (r0 * 3 + 14);
        sub_8152008(&gUnknown_0203AB88->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        sub_8152058(&gUnknown_0203AB88->tilemapBuffers[0][0], &gUnknown_0203AB88->unk_397C[281], temp0, 7, 3, 13);
        break;
    case 0x5:
    case 0xA:
    case 0xF:
        temp1 = ((r0 - 1) / 5 * 3 + 10);
        sub_8152008(&gUnknown_0203AB88->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        sub_8152058(&gUnknown_0203AB88->tilemapBuffers[0][0], &gUnknown_0203AB88->unk_397C[320], 14, temp1, 16, 3);
        break;
    default:
        temp0 = ((r0 % 5) * 3 + 14);
        temp1 = ((r0 - 1) / 5 * 3 + 7);
        sub_8152008(&gUnknown_0203AB88->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        sub_8152058(&gUnknown_0203AB88->tilemapBuffers[0][0], &gUnknown_0203AB88->unk_397C[272], temp0, temp1, 3, 3);
        break;
    }
}

static void sub_8140B64(u8 taskId)
{
    sub_81436D0(gTasks[taskId].data[4]);
    sub_81409B8(gTasks[taskId].data[4]);
}

static void sub_8140B8C(u8 taskId)
{
    gUnknown_0203AB88->var28 = 1;
    sub_81409B8(gTasks[taskId].data[4]);
    gUnknown_0203AB88->var23 = 2;
    gUnknown_0203AB88->var21 = 0;
    gTasks[taskId].func = sub_8141040;
}

static void sub_8140BD0(u8 taskId)
{
    s16 i;

    if (gUnknown_0203AB88->var08 & 0x20)
    {
        for (i = 11; i < 14; i++)
        {
            if ((gUnknown_0203AB88->var08 & gUnknown_085B6154[i].var08) == 0)
                break;
        }
    }
    else
    {
        for (i = 6; i < 10; i++)
        {
            if ((gUnknown_0203AB88->var08 & gUnknown_085B6154[i].var08) == 0)
                break;
        }
    }
    gTasks[taskId].data[4] = i;
    sub_8141FF4(taskId);
    sub_81424FC(gTasks[taskId].data[4]);
    sub_81436D0(gTasks[taskId].data[4]);
    sub_8142284(gTasks[taskId].data[4]);
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_8140B8C;
}

static u8 sub_8140CA8(s16 *r0, u8 r1)
{
    s8 temp1 = 0;
    s8 temp = 0;
    s8 arr[4] = {-5, 5, -1, 1};
    s8 t = *r0;

    switch (r1)
    {
    case 0:
    case 1:
        temp1 = (*r0 % 5);
        temp = temp1 + 15;
        if (temp1 == 0)
            temp1 = 5;
        break;
    case 2:
    case 3:
        temp1 = (*r0 / 5) * 5;
        temp = temp1 + 4;
        if (temp1 == 0)
            temp1 = 1;
        break;
    }

    *r0 += arr[r1];

    if (*r0 < temp1)
        *r0 = temp;

    if (*r0 > temp)
        *r0 = temp1;

    if (*r0 != t)
        return TRUE;

    return FALSE;
}

static void sub_8140D6C(u8 r0)
{
    u8 z = 0;
    bool8 var0 = FALSE;
    if (!(gMain.newKeys & DPAD_UP) || ((var0 = TRUE), sub_8140CA8(&gTasks[r0].data[4], 0)))
        if (!(gMain.newKeys & DPAD_DOWN) || ((var0 = TRUE), sub_8140CA8(&gTasks[r0].data[4], 1)))
            if (!(gMain.newKeys & DPAD_LEFT) || ((var0 = TRUE), sub_8140CA8(&gTasks[r0].data[4], 2)))
                if (!(gMain.newKeys & DPAD_RIGHT) || ((var0 = TRUE), sub_8140CA8(&gTasks[r0].data[4], 3)))
                    if (var0)
                    {
                        u8 i;
                        sub_81424FC(gTasks[r0].data[4]);
                        sub_8140B64(r0);
                        gTasks[r0].data[1] = z;
                        PlaySE(SE_SELECT);
                        sub_8151A9C(&gUnknown_0203AB88->varB8, 0xFFFF);
                        gUnknown_0203AB88->varB8.var04[13].var00_7 = gUnknown_0203AB88->varB8.var04[14].var00_7 = gUnknown_0203AB88->varB8.var04[15].var00_7 = 0;
                        sub_8142284(gTasks[r0].data[4]);
                        for (i = 0; i < 4; i++)
                        {
                            gSprites[gUnknown_0203AB88->var3C[i + 41]].oam.tileNum =
                            gSprites[gUnknown_0203AB88->var3C[i + 41]].sheetTileStart
                            + (*gSprites[gUnknown_0203AB88->var3C[i + 41]].anims)->type;
                        }
                        if ((u16)(gTasks[r0].data[4] - 1) < 4 && !(gUnknown_0203AB88->var08 & gUnknown_085B6154[gTasks[r0].data[4]].var08) )
                        {
                            z = gTasks[r0].data[4] - 1;
                            gSprites[gUnknown_0203AB88->var3C[z + 41]].oam.tileNum =
                            gSprites[gUnknown_0203AB88->var3C[z + 41]].sheetTileStart
                            + (*gSprites[gUnknown_0203AB88->var3C[z + 41]].anims + 1)->type;
                        }
                    }
}

static void sub_8140F6C(u8 r0)
{
    IncrementDailyRouletteUses();
    gUnknown_0203AB88->var28 = 0xFF;
    if (gUnknown_0203AB88->var19 == 1)
        gUnknown_0203AB88->var23 = 1;
    else
        gUnknown_0203AB88->var23 = 0;
    gUnknown_0203AB88->var21 = 0;
    gTasks[r0].data[1] = 32;
    gTasks[r0].func = sub_81410FC;
}

static void sub_8140FC4(u8 taskId)
{
    gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0] = gTasks[taskId].data[4];
    gTasks[taskId].data[2] = sub_8142758(gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]);
    sub_81436D0(gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]);
    if ((gTasks[taskId].data[13] -= gUnknown_0203AB88->var19) < 0)
        gTasks[taskId].data[13] = 0;
    sub_8143514(gTasks[taskId].data[13]);
    gTasks[taskId].func = sub_8140F6C;
}

static void sub_8141040(u8 taskId)
{
    sub_8140D6C(taskId);

    switch (gTasks[taskId].data[1])
    {
    case 0:
        sub_81409B8(gTasks[taskId].data[4]);
        gTasks[taskId].data[1]++;
        break;
    case 30:
        sub_81409B8(0);
        gTasks[taskId].data[1]++;
        break;
    case 59:
        gTasks[taskId].data[1] = 0;
        break;
    default:
        gTasks[taskId].data[1]++;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        if ((gUnknown_0203AB88->var08 & gUnknown_085B6154[gTasks[taskId].data[4]].var08))
            PlaySE(SE_BOO);
        else
        {
            m4aSongNumStart(SE_REGI);
            gTasks[taskId].func = sub_8140FC4;
        }
    }
}

static void sub_81410FC(u8 taskId)
{
    if (gTasks[taskId].data[1]-- > 0)
    {
        if (gTasks[taskId].data[1] > 2)
            gSpriteCoordOffsetX += 2;
        if ((gUnknown_0203AB88->var26 += 4) == 104)
            gSprites[gUnknown_0203AB88->var3C[25]].callback = &SpriteCallbackDummy;
    }
    else
    {
        sub_8142E70(1, -1);
        sub_8143038(1, -1);
        gTasks[taskId].func = sub_8141344;
        gTasks[taskId].data[1] = 0;
    }
}

static u8 sub_814118C(u16 r0, u16 r1)
{
    switch (gUnknown_0203AB88->var02)
    {
    case 1: // SHROOMISH
    case 2: // TAILLOW
        // one of the two is in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 10)
        {
            if (r0 < 12 || (r1 & 1))
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
            else
            {
                return 1;
            }
        }
        else if (!(r1 & 0x3))
        {
            return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
        }
        else
        {
            return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02;
        }
        break;
    case 3:
        // both are in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 11)
        {
            if (r0 < 6 || (r1 & 1))
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
            else
            {
                return 1;
            }
        }
        else if ((r1 & 1) && r0 > 6)
        {
            return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 4;
        }
        else
        {
            return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
        }
        break;
    case 0:
    default:
        // neither is in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 10)
        {
            if (!(r1 & 3))
            {
                return 1;
            }
            else
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
        }
        else if (!(r1 & 3))
        {
            if (r0 > 12)
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
            else
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02;
            }
        }
        else if (r1 & 0x8000)
        {
            if (r0 > 12)
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02;
            }
            else
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01;
            }
        }
        else
        {
            return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01 * 2;
        }
        break;
    }
}

static void sub_8141344(u8 taskId)
{
    u8 randf;
    s8 randfinal;
    s8 r5;
    u16 g = 0;
    u16 rand;
    u16 randmod;
    u16 angles[4] = {0, 180, 90, 270}; // angles in 90 degree steps

    rand = Random();
    randmod = rand % 100;
    gUnknown_0203AB88->var7C = gTasks[taskId].data[6];
    gUnknown_0203AB88->var7D = gUnknown_0203AB88->var7E = gUnknown_0203AB88->var7F = g;
    randf = sub_814118C(gTasks[taskId].data[8], rand);
    randfinal = (rand % randf) - (randf / 2);

    if (gLocalTime.hours < 13)
        r5 = 0;
    else
        r5 = 1;

    if (randmod < 80)
        r5 *= 2;
    else
        r5 = (1 - r5) * 2;

    gUnknown_0203AB88->var80 = g = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var1A + randfinal;

    g = S16TOPOSFLOAT(g) / 5.0f;
    gUnknown_0203AB88->var82 = g * 3;
    gUnknown_0203AB88->var86 = gUnknown_0203AB88->var84 = g;

    gUnknown_0203AB88->var88 = S16TOPOSFLOAT(angles[(rand & 1) + r5]);
    gUnknown_0203AB88->var8C = S16TOPOSFLOAT(gUnknown_085B6348[gUnknown_0203AB88->var04_0].var18);
    gUnknown_0203AB88->var90 = ((gUnknown_0203AB88->var8C * 0.5f) - gUnknown_0203AB88->var8C) / S16TOPOSFLOAT(gUnknown_0203AB88->var82);
    gUnknown_0203AB88->var94 = 68.0f;
    gUnknown_0203AB88->var9C = 0.0f;
    gUnknown_0203AB88->var98 = -(8.0f / S16TOPOSFLOAT(gUnknown_0203AB88->var82));
    gUnknown_0203AB88->varA0 = 36.0f;
    gTasks[taskId].func = sub_814155C;
}

static void sub_814155C(u8 taskId)
{
    u8 index;
    gUnknown_0203AB88->var03_7 = 1;
    index = gUnknown_0203AB88->var3C[gUnknown_0203AB88->var7C];
    gUnknown_0203AB88->var38 = &gSprites[index];
    gUnknown_0203AB88->var38->callback = sub_81446AC;
    gTasks[taskId].data[6]++;
    gTasks[taskId].data[0x8]++;
    sub_814372C(6 - gTasks[taskId].data[6]);
    m4aSongNumStart(SE_TAMAKORO);
    gTasks[taskId].func = sub_81415D4;
}

static void sub_81415D4(u8 taskId)
{
    if (gUnknown_0203AB88->var7D)
    {
        if (gUnknown_0203AB88->var03_5)
        {
            if (gUnknown_0203AB88->var03_6)
            {
                gUnknown_0203AB88->var03_6 = FALSE;
                gUnknown_0203AB88->var03_5 = FALSE;
            }
        }
        else
        {
            if (!gTasks[taskId].data[1])
            {
                bool8 temp = sub_81421E8(sub_81420D0(taskId, gUnknown_0203AB88->var7E), gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]);
                gTasks[taskId].data[5] = temp;
                if (temp == TRUE)
                    sub_8151A48(&gUnknown_0203AB88->varB8, 0x1000);
            }
            if (gTasks[taskId].data[1] <= 60)
            {
                if (gMain.newKeys & A_BUTTON)
                    gTasks[taskId].data[1] = 60;
                gTasks[taskId].data[1]++;
            }
            else
            {
                sub_81424FC(gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]);
                sub_8142E70(0, gTasks[taskId].data[12]);
                sub_8143038(0, gTasks[taskId].data[6] - 1);
                gTasks[taskId].data[1] = 32;
                gTasks[taskId].func = sub_81416D4;
            }
        }
    }
}

static void sub_81416D4(u8 taskId)
{
    if (gTasks[taskId].data[1]-- > 0)
    {
        if (gTasks[taskId].data[1] > 2)
            gSpriteCoordOffsetX -= 2;
        if ((gUnknown_0203AB88->var26 -= 4) == 104)
            gSprites[gUnknown_0203AB88->var3C[25]].callback = sub_814390C;
    }
    else
    {
        sub_8143150(gTasks[taskId].data[12]);
        if (gTasks[taskId].data[5] == 1)
            gTasks[taskId].data[1] = 121;
        else
            gTasks[taskId].data[1] = 61;
        gTasks[taskId].func = sub_8141778;
    }
}

static void sub_8141778(u8 taskId)
{
    if (gTasks[taskId].data[1]-- > 1)
    {
        switch (gTasks[taskId].data[1] % 16)
        {
        case 8:
            sub_8142E70(0, -1);
            sub_8143038(0, -1);
            break;
        case 0:
            sub_8142E70(0, gTasks[taskId].data[12]);
            sub_8143038(0, gTasks[taskId].data[6] - 1);
            break;
        }
    }
    else
    {
        sub_8141F7C(taskId, sub_814189C, 30, 0);
    }
}

static void sub_8141800(u8 taskId)
{
    switch (gTasks[taskId].data[0x5])
    {
    case 1:
    case 2:
        if (IsFanfareTaskInactive())
        {
            u32 wins = GetGameStat(GAME_STAT_CONSECUTIVE_ROULETTE_WINS);
            if (wins < ++gTasks[taskId].data[11])
                SetGameStat(GAME_STAT_CONSECUTIVE_ROULETTE_WINS, gTasks[taskId].data[11]);
            sub_8141F7C(taskId, sub_8141A18, 0xFFFF, 3);
        }
        break;
    case 0:
    default:
        if (!IsSEPlaying())
        {
            gTasks[taskId].data[11] = FALSE;
            sub_8141F7C(taskId, sub_8141AC0, 0xFFFF, 3);
        }
        break;
    }
}

static void sub_814189C(u8 taskId)
{
    switch (gTasks[taskId].data[5])
    {
    case 1:
    case 2:
        if (gTasks[taskId].data[2] == 12)
        {
            PlayFanfare(MUS_ME_B_BIG);
            DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_Jackpot, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
        }
        else
        {
            PlayFanfare(MUS_ME_B_SMALL);
            DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_ItsAHit, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
        }
        break;
    case 0:
    default:
        m4aSongNumStart(SE_HAZURE);
        DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_NothingDoing, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        break;
    }
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_8141800;
}

static void sub_8141984(u8 taskId)
{
    s32 r0 = gTasks[taskId].data[7];
    switch (r0)
    {
    case 0:
        gTasks[taskId].data[13]++;
        m4aSongNumStart(SE_PIN);
        sub_8143514(gTasks[taskId].data[13]);
        if (gTasks[taskId].data[13] >= 9999)
        {
            gTasks[taskId].data[1] = r0;
        }
        else
        {
            gTasks[taskId].data[1]--;
            gTasks[taskId].data[7]++;
        }
        break;
    case 3:
        m4aSongNumStop(SE_PIN);
        gTasks[taskId].data[7] = 0;
        break;
    default:
        gTasks[taskId].data[7]++;
        break;
    }
    if (gTasks[taskId].data[1] == 0)
        sub_8141F7C(taskId, sub_8141AC0, 0xFFFF, 3);
}

static void sub_8141A18(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, (gUnknown_0203AB88->var19 * gTasks[taskId].data[2]), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, Roulette_Text_YouveWonXCoins);
    DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
    AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(gUnknown_0203AB8C, 3);
    gTasks[taskId].data[1] = (gUnknown_0203AB88->var19 * gTasks[taskId].data[2]);
    gTasks[taskId].data[7] = 0;
    gTasks[taskId].func = sub_8141984;
}

static void sub_8141AC0(u8 taskId)
{
    sub_8151A9C(&gUnknown_0203AB88->varB8, 0xFFFF);
    gUnknown_0203AB88->varB8.var04[13].var00_7 = gUnknown_0203AB88->varB8.var04[14].var00_7 = gUnknown_0203AB88->varB8.var04[15].var00_7 = 0;
    gSprites[gUnknown_0203AB88->var3C[7 + gUnknown_085B6154[gTasks[taskId].data[12]].var00]].invisible = TRUE;
    gTasks[taskId].func = sub_8141B58;
}

static void sub_8141B58(u8 taskId)
{
    u8 i = 0;
    gTasks[taskId].data[4] = i;
    gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0] = 0;
    sub_81424FC(0);
    gSprites[gUnknown_0203AB88->var3C[48]].invisible = TRUE;
    for (i = 0; i < 4; i++)
    {
        gSprites[gUnknown_0203AB88->var3C[i + 41]].oam.tileNum =
            gSprites[gUnknown_0203AB88->var3C[i + 41]].sheetTileStart
            + (*gSprites[gUnknown_0203AB88->var3C[i + 41]].anims)->type;
    }
    if (gTasks[taskId].data[13] >= gUnknown_0203AB88->var19)
    {
        if (gTasks[taskId].data[6] == 6)
        {
            DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_BoardWillBeCleared, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
            sub_8141F7C(taskId, dp01t_12_3_battle_menu, 0xFFFF, 3);
        }
        else if (gTasks[taskId].data[13] == 9999)
        {
            DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_CoinCaseIsFull, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
            sub_8141F7C(taskId, sub_8140914, 0xFFFF, 0x3);
        }
        else
        {
            gTasks[taskId].func = sub_8140914;
        }
    }
    else
    {
        DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_NoCoinsLeft, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        sub_8141F7C(taskId, sub_8140994, 0x3C, 0x3);
    }
}

static void dp01t_12_3_battle_menu(u8 taskId)
{
    u8 i = 0;

    gTasks[taskId].data[6] = 0;
    sub_8141FF4(taskId);
    sub_8142070();
    sub_8143A40();
    sub_81424FC(0);
    sub_814372C(6);

    for (i = 0; i < 12; i++)
    {
        gSprites[gUnknown_0203AB88->var3C[i + 7]].invisible = FALSE;
    }

    if (gTasks[taskId].data[13] == 9999)
    {
        DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, Roulette_Text_CoinCaseIsFull, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        sub_8141F7C(taskId, sub_8140914, 0xFFFF, 3);
    }
    else
    {
        gTasks[taskId].func = sub_8140914;
    }
}

static void sub_8141DE4(u8 taskId)
{
    sub_8151A9C(&gUnknown_0203AB88->varB8, 0xFFFF);
    sub_8151678(&gUnknown_0203AB88->varB8);
    SetCoins(gTasks[taskId].data[13]);
    if (GetCoins() < gUnknown_0203AB88->var19)
        gSpecialVar_0x8004 = TRUE;
    else
        gSpecialVar_0x8004 = FALSE;
    AlertTVOfNewCoinTotal(GetCoins());
    BeginHardwarePaletteFade(0xFF, 0, 0, 16, 0);
    gTasks[taskId].func = sub_8141E7C;
}

static void sub_8141E7C(u8 taskId) // end roulette ?
{
    if (UpdatePaletteFade() == 0)
    {
        SetVBlankCallback(NULL);
        gSpriteCoordOffsetX = gSpriteCoordOffsetY = 0;
        ResetVramOamAndBgCntRegs();
        ResetAllBgsCoordinates();
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        sub_8140418();
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void sub_8141EF8(u8 taskId)
{
    if (gUnknown_0203AB88->varA8 == 0 || gMain.newKeys & gUnknown_0203AB88->varAA)
    {
        gTasks[taskId].func = gUnknown_0203AB88->varAC;
        if (gUnknown_0203AB88->varAA > 0)
            PlaySE(SE_SELECT);
        gUnknown_0203AB88->varAC = NULL;
        gUnknown_0203AB88->varAA = 0;
        gUnknown_0203AB88->varA8 = 0;
    }
    if (gUnknown_0203AB88->varA8 != 0xFFFF)
        gUnknown_0203AB88->varA8--;
}

static void sub_8141F7C(u8 taskId, TaskFunc r1, u16 r2, u16 r3)
{
    gUnknown_0203AB88->varB4 = gTasks[taskId].func;
    if (r1 == NULL)
        r1 = gUnknown_0203AB88->varB4;
    gUnknown_0203AB88->varAC = r1;
    gUnknown_0203AB88->varA8 = r2;
    if (r2 == 0xFFFF && r3 == 0)
        gUnknown_0203AB88->varAA = 0xFFFF;
    else
        gUnknown_0203AB88->varAA = r3;
    gTasks[taskId].func = sub_8141EF8;
}

static void sub_8141FF4(u8 taskId)
{
    u8 i = 0;
    gUnknown_0203AB88->var00 = i;
    gUnknown_0203AB88->var03_7 = 0;
    gUnknown_0203AB88->var03_5 = 0;
    gUnknown_0203AB88->var03_6 = 0;
    gUnknown_0203AB88->var03_0 = 0;
    for (i = 0; i < 6; i++)
    {
        gUnknown_0203AB88->var1B[i] = 0;
    }
    gUnknown_0203AB88->var1A_0 = 0;
    gTasks[taskId].data[1] = 0;
}

static void sub_8142070(void)
{
    u8 i;
    gUnknown_0203AB88->var08 = 0;
    for (i = 0; i < 6; i++)
    {
        gUnknown_0203AB88->var0C[i] = 0;
    }
    for (i = 0; i < 4; i++)
    {
        gUnknown_0203AB88->var12[i] = 0;
    }
    for (i = 0; i < 3; i++)
    {
        gUnknown_0203AB88->var16[i] = 0;
    }
    sub_8143038(1, -1);
}

static u8 sub_81420D0(u8 taskId, u8 r1)
{
    u8 i;
    u8 z;
    u32 t0[4] = {0x10842, 0x21084, 0x42108, 0x84210};
    u32 t1[3] = {0x3E0, 0x7C00, 0xF8000};

    if (r1 > 11)
        return 0;

    gUnknown_0203AB88->var0C[gTasks[taskId].data[6] - 1] = gUnknown_085B62E4[r1].var02;
    gTasks[taskId].data[12] = gUnknown_085B62E4[r1].var02;
    gUnknown_0203AB88->var08 |= gUnknown_085B62E4[r1].var04;
    for (i = 0; i < 4; i++)
    {
        if (gUnknown_085B62E4[r1].var04 & t0[i])
            gUnknown_0203AB88->var12[i]++;
        if (gUnknown_0203AB88->var12[i] > 2)
            gUnknown_0203AB88->var08 |= t0[i];
    }
    for (z = 0; z < 3; z++)
    {
        if (gUnknown_085B62E4[r1].var04 & t1[z])
            gUnknown_0203AB88->var16[z]++;
        if (gUnknown_0203AB88->var16[z] > 3)
            gUnknown_0203AB88->var08 |= t1[z];
    }
    return gUnknown_085B62E4[r1].var02;
}

static bool8 sub_81421E8(u8 r0, u8 r1)
{
    u8 t = r0;
    if (--r0 < 19)
    {
        switch (r1)
        {
        case 0:
            return 3;
        case 1 ... 4:
            if (t == r1 + 5 || t == r1 + 10 || t == r1 + 15)
                return TRUE;
            break;
        case 5:
        case 10:
        case 15:
            if (t >= (r1 + 1) && t <= (r1 + 4))
                return TRUE;
            break;
        default:
            if (t == r1)
                return TRUE;
        }
    }
    return FALSE;
}

static void sub_8142284(u8 r0)
{

    u16 var0 = 0;
    u8 var2;
    u16 var3;
    u8 i;

    switch (r0)
    {
    case 5:
    case 10:
    case 15:
        for (i = (r0 + 1); i < (r0 + 5); i++)
        {
            if (!(gUnknown_0203AB88->var08 & gUnknown_085B6154[i].var08))
                var0 |= gUnknown_085B6154[i].var10;
        }
        sub_8151A48(&gUnknown_0203AB88->varB8, var0 &= 0xDFFF);
        break;
    default:
    {
        struct UnkStruct1 var1[3];
        memcpy(var1, gUnknown_085B63F0, sizeof(var1));
        if (r0 > 0 && r0 < 5)
            var2 = 3;
        else
            var2 = 1;
        var3 = r0 / 5 - 1;
        switch (r0 % 5)
        {
            case 1:
                var3 = gSprites[gUnknown_0203AB88->var3C[7]].oam.paletteNum * 16;
                break;
            case 2:
                var3 = gSprites[gUnknown_0203AB88->var3C[8]].oam.paletteNum * 16;
                break;
            case 3:
                var3 = gSprites[gUnknown_0203AB88->var3C[9]].oam.paletteNum * 16;
                break;
            case 4:
                var3 = gSprites[gUnknown_0203AB88->var3C[10]].oam.paletteNum * 16;
                break;
        }
        if (var2 == 1)
        {
            if (!(gUnknown_0203AB88->var08 & gUnknown_085B6154[r0].var08))
            {
                var1[r0 / 5 - 1].var02 += var3;
                sub_815168C(&gUnknown_0203AB88->varB8, 13, &var1[r0 / 5 - 1]);
            }
            else
            {
                break;
            }
        }
        else
        {
            for (i = 0; i < 3; i++)
            {
                u8 var4 = i * 5 + r0 + 5;
                if (!(gUnknown_0203AB88->var08 & gUnknown_085B6154[var4].var08))
                {
                    var1[var4 / 5 - 1].var02 += var3;
                    sub_815168C(&gUnknown_0203AB88->varB8, i + 13, &var1[var4 / 5 - 1]);
                    if (var2 == 3)
                        var0 = gUnknown_085B6154[var4].var10;
                    var2--;
                }
            }
            if (var2 != 2)
                var0 = 0;
        }
        sub_8151A48(&gUnknown_0203AB88->varB8, var0 |= gUnknown_085B6154[r0].var10);
        break;
    }
    }
}

static void sub_81424FC(u8 r0)
{
    vu8 i;
    vu8 z;
    vu16 var1;
    vu16 var2;
    vu8 var0;
    u8 v[5];
    u8 l;
    gUnknown_0203AB88->var2A = 1;
    sub_8142E70(0, 0);
    sub_8152058(gUnknown_0203AB88->tilemapBuffers[2], gUnknown_0203AB88->unk_397C, 14, 7, 16, 13);
    switch (r0)
    {
    case 0:
        return;
    case 1 ... 4:
        l = 4;
        for (i = 0; i < l; i++)
        {
            v[i] = i * 5 + r0;
        }
        break;
    case 5:
    case 10:
    case 15:
        l = 5;
        for (i = 0; i < l; i++)
        {
            v[i] = i + r0;
        }
        break;
    default:
        l = 1;
        v[0] = r0;
    }
    for (i = 0; i < l; i++)
    {
        var0 = gUnknown_085B6154[v[i]].var06;
        var1 = gUnknown_085B6154[v[i]].var03;
        for (z = 0; z < 3; z++)
        {
            var2 = (gUnknown_085B6154[v[i]].var04 + z) * 32;
            gUnknown_0203AB88->tilemapBuffers[2][var1 + var2 + 0] = gUnknown_0203AB88->unk_397C[(var0 + z) * 3 + 208];
            gUnknown_0203AB88->tilemapBuffers[2][var1 + var2 + 1] = gUnknown_0203AB88->unk_397C[(var0 + z) * 3 + 209];
            gUnknown_0203AB88->tilemapBuffers[2][var1 + var2 + 2] = gUnknown_0203AB88->unk_397C[(var0 + z) * 3 + 210];
        }
    }
}

static u8 sub_8142758(u8 r0)
{
    u8 var0[5] = {0, 3, 4, 6, 12};

    if (r0 > 19)
        r0 = 0;
    switch (gUnknown_085B6154[r0].var01_0)
    {
    case 3:
        r0 = r0 / 5 - 1;
        if (gUnknown_0203AB88->var16[r0] > 3)
            return 0;
        return var0[gUnknown_0203AB88->var16[r0] + 1];
    case 4:
        r0--;
        if (gUnknown_0203AB88->var12[r0] > 2)
            return 0;
        return var0[gUnknown_0203AB88->var12[r0] + 2];
    case 12:
        if (gUnknown_0203AB88->var08 & gUnknown_085B6154[r0].var08)
            return 0;
        return var0[4];
    }
    return 0;
}

static void sub_8142814(void)
{
    s32 x1;
    s32 x2;
    SetGpuReg(REG_OFFSET_BG2PA, gUnknown_0203AB88->var2C.a);
    SetGpuReg(REG_OFFSET_BG2PB, gUnknown_0203AB88->var2C.b);
    SetGpuReg(REG_OFFSET_BG2PC, gUnknown_0203AB88->var2C.c);
    SetGpuReg(REG_OFFSET_BG2PD, gUnknown_0203AB88->var2C.d);
    x1 = 0x7400 - gUnknown_0203AB88->var2C.a * (gSpriteCoordOffsetX + 116)
                - gUnknown_0203AB88->var2C.b * (gSpriteCoordOffsetY + 80);
    x2 = 0x5400 - gUnknown_0203AB88->var2C.c * (gSpriteCoordOffsetX + 116)
                - gUnknown_0203AB88->var2C.d * (gSpriteCoordOffsetY + 80);
    SetGpuReg(REG_OFFSET_BG2X_L, x1);
    SetGpuReg(REG_OFFSET_BG2X_H, (x1 & 0x0fff0000) >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, x2);
    SetGpuReg(REG_OFFSET_BG2Y_H, (x2 & 0x0fff0000) >> 16);
}

static const u8 sFiller_085B644D[3] = {};
static const u16 RouletteSpritePalette_01[] = INCBIN_U16("graphics/roulette/shadow.gbapal");
static const u16 RouletteSpritePalette_02[] = INCBIN_U16("graphics/roulette/ball.gbapal");
static const u16 RouletteSpritePalette_03[] = INCBIN_U16("graphics/roulette/ball_counter.gbapal");
static const u16 RouletteSpritePalette_04[] = INCBIN_U16("graphics/roulette/cursor.gbapal");
static const u16 RouletteSpritePalette_05[] = INCBIN_U16("graphics/roulette/credit.gbapal");
static const u16 RouletteSpritePalette_06[] = INCBIN_U16("graphics/roulette/shroomish.gbapal");
static const u16 RouletteSpritePalette_07[] = INCBIN_U16("graphics/roulette/tailow.gbapal");
static const u16 RouletteSpritePalette_08[] = INCBIN_U16("graphics/roulette/poke_icons.gbapal");
static const u16 RouletteSpritePalette_09[] = INCBIN_U16("graphics/roulette/wynaut.gbapal");
static const u16 RouletteSpritePalette_10[] = INCBIN_U16("graphics/roulette/azurill.gbapal");
static const u16 RouletteSpritePalette_11[] = INCBIN_U16("graphics/roulette/skitty.gbapal");
static const u16 RouletteSpritePalette_12[] = INCBIN_U16("graphics/roulette/makuhita.gbapal");
static const u16 RouletteSpritePalette_13[] = INCBIN_U16("graphics/roulette/85B65D0.gbapal");
static const u16 RouletteSpritePalette_14[] = INCBIN_U16("graphics/roulette/85B65F0.gbapal");
static const u16 RouletteSpritePalette_15[] = INCBIN_U16("graphics/roulette/85B6610.gbapal");
static const u16 RouletteSpritePalette_16[] = INCBIN_U16("graphics/roulette/85B6630.gbapal");
static const u32 gUnknown_085B6650[] = INCBIN_U32("graphics/roulette/ball.4bpp.lz");
static const u32 RouletteBallCounterTiles[] = INCBIN_U32("graphics/roulette/ball_counter.4bpp.lz");
static const u32 gUnknown_085B67FC[] = INCBIN_U32("graphics/roulette/roulette_tilt.4bpp.lz");
static const u32 RoulettePokeIconsTiles[] = INCBIN_U32("graphics/roulette/poke_icons.4bpp.lz");
static const u32 RoulettePokeIcons2Tiles[] = INCBIN_U32("graphics/roulette/poke_icons2.4bpp.lz");
static const u32 gUnknown_085B7290[] = INCBIN_U32("graphics/roulette/shadow.4bpp.lz");
static const u32 RouletteCursorTiles[] = INCBIN_U32("graphics/roulette/cursor.4bpp.lz");

static const struct SpritePalette gUnknown_085B7384[] =
{
    { .data = RouletteSpritePalette_01, .tag = 1 },
    { .data = RouletteSpritePalette_02, .tag = 2 },
    { .data = RouletteSpritePalette_03, .tag = 3 },
    { .data = RouletteSpritePalette_04, .tag = 4 },
    { .data = RouletteSpritePalette_05, .tag = 5 },
    { .data = RouletteSpritePalette_06, .tag = 6 },
    { .data = RouletteSpritePalette_07, .tag = 7 },
    { .data = RouletteSpritePalette_08, .tag = 8 },
    { .data = RouletteSpritePalette_09, .tag = 9 },
    { .data = RouletteSpritePalette_10, .tag = 10 },
    { .data = RouletteSpritePalette_11, .tag = 11 },
    { .data = RouletteSpritePalette_12, .tag = 12 },
    {}
};

static const struct OamData gOamData_85B73EC =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct OamData gOamData_85B73F4 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const struct OamData gOamData_85B73FC =
{
    .y = 60,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 2,
};

static const union AnimCmd gSpriteAnim_85B7404[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B740C[] =
{
    gSpriteAnim_85B7404
};

static const union AffineAnimCmd gSpriteAffineAnim_85B7410[] =
{
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_85B7418[] =
{
    gSpriteAffineAnim_85B7410
};

static const struct CompressedSpriteSheet gUnknown_085B741C =
{
    .data = RoulettePokeIcons2Tiles,
    .size = 0xC00,
    .tag = 0
};

static const union AnimCmd gSpriteAnim_85B7420[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_FRAME(72, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(40, 0),
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_FRAME(56, 0),
    ANIMCMD_FRAME(88, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B7458[] =
{
    &gSpriteAnim_85B7420[0]
};

static const union AnimCmd *const gSpriteAnimTable_85B745C[] =
{
    &gSpriteAnim_85B7420[1]
};

static const union AnimCmd *const gSpriteAnimTable_85B7460[] =
{
    &gSpriteAnim_85B7420[2]
};

static const union AnimCmd *const gSpriteAnimTable_85B7464[] =
{
    &gSpriteAnim_85B7420[3]
};

static const union AnimCmd *const gSpriteAnimTable_85B7468[] =
{
    &gSpriteAnim_85B7420[4]
};

static const union AnimCmd *const gSpriteAnimTable_85B746C[] =
{
    &gSpriteAnim_85B7420[5]
};

static const union AnimCmd *const gSpriteAnimTable_85B7470[] =
{
    &gSpriteAnim_85B7420[6]
};

static const union AnimCmd *const gSpriteAnimTable_85B7474[] =
{
    &gSpriteAnim_85B7420[7]
};

static const union AnimCmd *const gSpriteAnimTable_85B7478[] =
{
    &gSpriteAnim_85B7420[8]
};

static const union AnimCmd *const gSpriteAnimTable_85B747C[] =
{
    &gSpriteAnim_85B7420[9]
};

static const union AnimCmd *const gSpriteAnimTable_85B7480[] =
{
    &gSpriteAnim_85B7420[10]
};

static const union AnimCmd *const gSpriteAnimTable_85B7484[] =
{
    &gSpriteAnim_85B7420[11]
};

static const struct CompressedSpriteSheet gUnknown_085B7488 =
{
    .data = gRouletteHeadersTiles,
    .size = 0x1600,
    .tag = 4
};

static const struct CompressedSpriteSheet gUnknown_085B7490 =
{
    .data = RoulettePokeIconsTiles,
    .size = 0x400,
    .tag = 5
};

static const union AnimCmd gSpriteAnim_85B7498[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_FRAME(112, 0),
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_FRAME(144, 0),
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B74C8[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B74DC[] =
{
    &gSpriteAnim_85B7498[0]
};

static const union AnimCmd *const gSpriteAnimTable_85B74E0[] =
{
    &gSpriteAnim_85B7498[2]
};

static const union AnimCmd *const gSpriteAnimTable_85B74E4[] =
{
    &gSpriteAnim_85B7498[4]
};

static const union AnimCmd *const gSpriteAnimTable_85B74E8[] =
{
    &gSpriteAnim_85B7498[6]
};

static const union AnimCmd *const gSpriteAnimTable_85B74EC[] =
{
    &gSpriteAnim_85B7498[8]
};

static const union AnimCmd *const gSpriteAnimTable_85B74F0[] =
{
    &gSpriteAnim_85B7498[9]
};

static const union AnimCmd *const gSpriteAnimTable_85B74F4[] =
{
    &gSpriteAnim_85B7498[10]
};

static const union AnimCmd *const gSpriteAnimTable_85B74F8[] =
{
    &gSpriteAnim_85B74C8[0]
};

static const union AnimCmd *const gSpriteAnimTable_85B74FC[] =
{
    &gSpriteAnim_85B74C8[1]
};

static const union AnimCmd *const gSpriteAnimTable_85B7500[] =
{
    &gSpriteAnim_85B74C8[2]
};

static const union AnimCmd *const gSpriteAnimTable_85B7504[] =
{
    &gSpriteAnim_85B74C8[3]
};

static const struct SpriteTemplate gSpriteTemplate_85B7508[] =
{
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74DC,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74E0,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74E4,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74E8,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    }
};

static const struct SpriteTemplate gSpriteTemplate_85B7568[] =
{
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74EC,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74F0,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 4,
        .paletteTag = 8,
        .oam = &gOamData_85B73EC,
        .anims = gSpriteAnimTable_85B74F4,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    }
};

static const struct SpriteTemplate gSpriteTemplate_85B75B0[] =
{
    {
        .tileTag = 5,
        .paletteTag = 8,
        .oam = &gOamData_85B73F4,
        .anims = gSpriteAnimTable_85B74F8,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 5,
        .paletteTag = 8,
        .oam = &gOamData_85B73F4,
        .anims = gSpriteAnimTable_85B74FC,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 5,
        .paletteTag = 8,
        .oam = &gOamData_85B73F4,
        .anims = gSpriteAnimTable_85B7500,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    },
    {
        .tileTag = 5,
        .paletteTag = 8,
        .oam = &gOamData_85B73F4,
        .anims = gSpriteAnimTable_85B7504,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_814390C
    }
};

static const struct SpriteTemplate gSpriteTemplate_85B7610[] =
{
    {
        .tileTag = 0,
        .paletteTag = 9,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7458,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 10,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B745C,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 11,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7460,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 12,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7464,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 9,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7468,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 10,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B746C,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 11,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7470,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 12,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7474,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 9,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7478,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 10,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B747C,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 11,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7480,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    },
    {
        .tileTag = 0,
        .paletteTag = 12,
        .oam = &gOamData_85B73FC,
        .anims = gSpriteAnimTable_85B7484,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8143280
    }
};

static const struct OamData gOamData_85B7730 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1,
};

static const struct OamData gOamData_85B7738 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 1,
};

static const struct OamData gOamData_85B7740 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1,
};

static const struct OamData gOamData_85B7748 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x8),
    .size = SPRITE_SIZE(16x8),
    .priority = 1,
};

static const struct CompressedSpriteSheet gUnknown_085B7750[] =
{
    {
        .data = gRouletteCreditTiles,
        .size = 0x400,
        .tag = 7
    },
    {
        .data = gRouletteNumbersTiles,
        .size = 0x280,
        .tag = 8
    },
    {
        .data = gRouletteMultiplierTiles,
        .size = 0x500,
        .tag = 9
    },
    {
        .data = RouletteBallCounterTiles,
        .size = 0x140,
        .tag = 10
    },
    {
        .data = RouletteCursorTiles,
        .size = 0x200,
        .tag = 11
    },
    {}
};

static const union AnimCmd gSpriteAnim_85B7780[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(10, 0),
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_FRAME(14, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(18, 0),
    // BUG: Animation not terminated properly
    //ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B77A8[] =
{
    gSpriteAnim_85B7780
};

static const union AnimCmd gSpriteAnim_85B77AC[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B77C4[] =
{
    gSpriteAnim_85B77AC
};

static const union AnimCmd gSpriteAnim_85B77C8[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B77E0[] =
{
    gSpriteAnim_85B77C8
};

static const struct SpriteTemplate gSpriteTemplate_85B77E4 =
{
    .tileTag = 7,
    .paletteTag = 5,
    .oam = &gOamData_85B7730,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_085B77FC =
{
    .tileTag = 8,
    .paletteTag = 5,
    .oam = &gOamData_85B7738,
    .anims = gSpriteAnimTable_85B77A8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_085B7814 =
{
    .tileTag = 9,
    .paletteTag = 5,
    .oam = &gOamData_85B7740,
    .anims = gSpriteAnimTable_85B77C4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_814390C
};

static const struct SpriteTemplate gUnknown_085B782C =
{
    .tileTag = 10,
    .paletteTag = 3,
    .oam = &gOamData_85B7748,
    .anims = gSpriteAnimTable_85B77E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_085B7844 =
{
    .tileTag = 11,
    .paletteTag = 5,
    .oam = &gOamData_85B73EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData gOamData_85B785C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const struct CompressedSpriteSheet gUnknown_085B7864 = {
    .data = gUnknown_085B6650,
    .size = 0x200,
    .tag = 12
};

static const union AnimCmd gSpriteAnim_85B786C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B7880[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(8, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B7894[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(4, 15),
    ANIMCMD_FRAME(8, 15),
    ANIMCMD_FRAME(4, 15),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B78A8[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78BC[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78D4[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78E8[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78F0[] =
{
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B7904[] =
{
    gSpriteAnim_85B786C,
    gSpriteAnim_85B7880,
    gSpriteAnim_85B7894,
    gSpriteAnim_85B78A8,
    gSpriteAnim_85B78F0,
    gSpriteAnim_85B78BC,
    gSpriteAnim_85B78D4,
    gSpriteAnim_85B78D4,
    gSpriteAnim_85B78E8
};

static const struct SpriteTemplate gSpriteTemplate_85B7928 =
{
    .tileTag = 12,
    .paletteTag = 2,
    .oam = &gOamData_85B785C,
    .anims = gSpriteAnimTable_85B7904,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData gOamData_85B7940 =
{
    .y = 81,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 2,
};

static const struct CompressedSpriteSheet gUnknown_085B7948 =
{
    .data = gRouletteCenter_Gfx,
    .size = 0x800,
    .tag = 6
};

static const struct SpriteTemplate gSpriteTemplate_85B7950 =
{
    .tileTag = 6,
    .paletteTag = 2,
    .oam = &gOamData_85B7940,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_814399C
};

static const struct OamData gOamData_85B7968 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const struct OamData gOamData_85B7970 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const struct CompressedSpriteSheet gUnknown_085B7978 =
{
    .data = gUnknown_085B67FC,
    .size = 0xE00,
    .tag = 13
};

static const union AnimCmd gSpriteAnim_85B7980[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_JUMP(2)
};

static const union AnimCmd gSpriteAnim_85B799C[] =
{
    ANIMCMD_FRAME(80, 10),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B79A4[] =
{
    ANIMCMD_FRAME(80, 10, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B79AC[] =
{
    ANIMCMD_FRAME(80, 20),
    ANIMCMD_FRAME(96, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B79B8[] =
{
    ANIMCMD_FRAME(80, 20, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 20, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B79C4[] =
{
    ANIMCMD_FRAME(80, 10),
    ANIMCMD_FRAME(96, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B79D0[] =
{
    ANIMCMD_FRAME(80, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 10, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const gSpriteAnimTable_85B79DC[] =
{
    gSpriteAnim_85B7980
};

static const union AnimCmd *const gSpriteAnimTable_85B79E0[] =
{
    gSpriteAnim_85B799C,
    gSpriteAnim_85B79A4,
    gSpriteAnim_85B79AC,
    gSpriteAnim_85B79B8,
    gSpriteAnim_85B79C4,
    gSpriteAnim_85B79D0
};

static const struct SpriteTemplate gSpriteTemplate_85B79F8 =
{
    .tileTag = 13,
    .paletteTag = 6,
    .oam = &gOamData_85B7968,
    .anims = gSpriteAnimTable_85B79DC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gSpriteTemplate_85B7A10 =
{
    .tileTag = 13,
    .paletteTag = 7,
    .oam = &gOamData_85B7970,
    .anims = gSpriteAnimTable_85B79E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8145294
};

static const struct OamData gOamData_85B7A28 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const struct OamData gOamData_85B7A30 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

static const struct OamData gOamData_85B7A38 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

static const struct CompressedSpriteSheet gUnknown_085B7A40 =
{
    .data = gUnknown_085B7290,
    .size = 0x180,
    .tag = 14
};

static const union AffineAnimCmd gSpriteAffineAnim_85B7A48[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(2,    2,    0, 60),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd gSpriteAffineAnim_85B7A60[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-2,    0x0,   0, 15),
    AFFINEANIMCMD_FRAME(-1,    -2,    0, 15),
    AFFINEANIMCMD_FRAME(-1,    -5,    0, 24),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_85B7A88[] =
{
    gSpriteAffineAnim_85B7A48
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_85B7A8C[] =
{
    gSpriteAffineAnim_85B7A60
};

static const union AffineAnimCmd gSpriteAffineAnim_85B7A90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_85B7AA0[] =
{
    gSpriteAffineAnim_85B7A90
};

static const union AnimCmd gSpriteAnim_85B7AA4[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B7AAC[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B7AB4[] =
{
    gSpriteAnim_85B7AA4
};

static const union AnimCmd *const gSpriteAnimTable_85B7AB8[] =
{
    gSpriteAnim_85B7AAC
};

static const struct SpriteTemplate gSpriteTemplate_85B7ABC[] =
{
    {
        .tileTag = 14,
        .paletteTag = 1,
        .oam = &gOamData_85B7A28,
        .anims = gSpriteAnimTable_85B7AB4,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = 14,
        .paletteTag = 1,
        .oam = &gOamData_85B7A30,
        .anims = gSpriteAnimTable_85B7AB8,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8144E60
    }
};

static const struct SpriteTemplate gUnknown_085B7AEC =
{
    .tileTag = 14,
    .paletteTag = 1,
    .oam = &gOamData_85B7A38,
    .anims = gSpriteAnimTable_85B7AB8,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_85B7A8C,
    .callback = sub_8145294
};

static void sub_81428C4(u8 r0)
{
    DisplayYesNoMenuDefaultYes();
    DoYesNoFuncWithChoice(r0, &gUnknown_085B6408);
}

static void sub_81428E4(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        SetMainCallback2(sub_81405CC);
        DestroyTask(taskId);
    }
}

static void sub_8142918(u8 taskId)
{
    ClearStdWindowAndFrame(0, TRUE);
    HideCoinsWindow();
    FreeAllWindowBuffers();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gPaletteFade.delayCounter = gPaletteFade.multipurpose2;
    UpdatePaletteFade();
    gTasks[taskId].func = sub_81428E4;
}

static void sub_814297C(u8 taskId)
{
    ClearStdWindowAndFrame(0, FALSE);
    HideCoinsWindow();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

static void sub_81429A0(u8 taskId)
{
    gTasks[taskId].data[0]++;
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        gSpecialVar_0x8004 = 1;
        HideCoinsWindow();
        ClearStdWindowAndFrame(0, TRUE);
        ScriptContext2_Disable();
        DestroyTask(taskId);
    }
}

static void sub_81429F0(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        u32 temp = gUnknown_085B6344[(gSpecialVar_0x8004 & 1) + (gSpecialVar_0x8004 >> 7 << 1)];
        ConvertIntToDecimalStringN(gStringVar1, temp, STR_CONV_MODE_LEADING_ZEROS, 1);
        StringExpandPlaceholders(gStringVar4, Roulette_Text_PlayMinimumWagerIsX);
        DrawStdWindowFrame(0, FALSE);
        AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = sub_81428C4;
    }
}

static void Task_Roulette_0(u8 taskId)
{
    s32 temp;
    PrintCoinsString(gTasks[taskId].data[13]);
    temp = gUnknown_085B6344[(gSpecialVar_0x8004 & 1) + (gSpecialVar_0x8004 >> 7 << 1)];
    ConvertIntToDecimalStringN(gStringVar1, temp, STR_CONV_MODE_LEADING_ZEROS, 1);
    if (gTasks[taskId].data[13] >= temp)
    {
        if ((gSpecialVar_0x8004 & 0x80) && (gSpecialVar_0x8004 & 1))
        {
            DrawStdWindowFrame(0, FALSE);
            AddTextPrinterParameterized(0, 1, Roulette_Text_SpecialRateTable, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = sub_81429F0;
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, Roulette_Text_PlayMinimumWagerIsX);
            DrawStdWindowFrame(0, FALSE);
            AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = sub_81428C4;
        }
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, Roulette_Text_NotEnoughCoins);
        DrawStdWindowFrame(0, FALSE);
        AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = sub_81429A0;
        gTasks[taskId].data[13] = 0;
        gTasks[taskId].data[0] = 0;
    }
}

void PlayRoulette(void)
{
    u8 taskId;

    ScriptContext2_Enable();
    ShowCoinsWindow(GetCoins(), 1, 1);
    taskId = CreateTask(Task_Roulette_0, 0);
    gTasks[taskId].data[13] = GetCoins();
}

static void sub_8142C0C(u8 r0)
{
    if (!r0)
    {
        FreeAllSpritePalettes();
        LoadSpritePalettes(gUnknown_085B7384);
        LoadCompressedSpriteSheet(&gUnknown_085B7864);
        LoadCompressedSpriteSheet(&gUnknown_085B7978);
        LoadCompressedSpriteSheet(&gUnknown_085B7A40);
    }
    else
    {
        FreeSpriteTilesByTag(14);
        FreeSpriteTilesByTag(13);
        FreeSpriteTilesByTag(12);
        FreeAllSpritePalettes();
    }
}

static u8 sub_8142C60(const struct SpriteTemplate *r0, u8 r1, u16 *r2)
{
    u16 temp;
    u8 spriteId = CreateSprite(r0, 116, 80, r0->oam->y);
    gSprites[spriteId].data[0]            = *r2;
    gSprites[spriteId].data[1]            = r1;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    gSprites[spriteId].animPaused         = TRUE;
    gSprites[spriteId].affineAnimPaused   = TRUE;
    temp = *r2;
    *r2 += 30;
    if (*r2 >= 360)
        *r2 = temp - 330;
    return spriteId;
}

static void sub_8142CD0(void)
{
    u8 i, j;
    u8 spriteId;
    struct SpriteSheet s;
    LZ77UnCompWram(gUnknown_085B7488.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = gUnknown_085B7488.size;
    s.tag  = gUnknown_085B7488.tag;
    LoadSpriteSheet(&s);
    LZ77UnCompWram(gUnknown_085B7490.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = gUnknown_085B7490.size;
    s.tag  = gUnknown_085B7490.tag;
    LoadSpriteSheet(&s);
    for (i = 0; i < 3; i++)
    {
        u8 o = i * 24;
        for (j = 0; j < 4; j++)
        {
            spriteId = gUnknown_0203AB88->var3C[(i * 4) + 29 + j] = CreateSprite(&gSpriteTemplate_85B75B0[j], (j * 24) + 148, o + 92, 30);
            gSprites[spriteId].animPaused = TRUE;
            o += 24;
            if (o >= 72)
                o = 0;
        }
    }
    for (i = 0; i < 4; i++)
    {
        spriteId = gUnknown_0203AB88->var3C[i + 41] = CreateSprite(&gSpriteTemplate_85B7508[i], (i * 24) + 148, 70, 30);
        gSprites[spriteId].animPaused = TRUE;
    }
    for (i = 0; i < 3; i++)
    {
        spriteId = gUnknown_0203AB88->var3C[i + 45] = CreateSprite(&gSpriteTemplate_85B7568[i], 126, (i * 24) + 92, 30);
        gSprites[spriteId].animPaused = TRUE;
    }
}

static void unref_sub_8142E3C(void)
{
    u8 i;
    for (i = 0; i < 12; i++)
    {
        DestroySprite(&gSprites[gUnknown_0203AB88->var3C[i + 29]]);
    }
}

static void sub_8142E70(u8 r0, u8 r1)
{
    u8 i;
    switch (r0)
    {
    case 1:
        for (i = 0; i < 19; i++)
        {
            gSprites[gUnknown_0203AB88->var3C[i + 29]].invisible = TRUE;
        }
        break;
    case 0:
        for (i = 0; i < 12; i++)
        {
            if (!(gUnknown_0203AB88->var08 & gUnknown_085B62E4[i].var04))
                gSprites[gUnknown_0203AB88->var3C[i + 29]].invisible = FALSE;
            else if (gUnknown_085B62E4[i].var02 != r1)
                gSprites[gUnknown_0203AB88->var3C[i + 29]].invisible = TRUE;
            else
                gSprites[gUnknown_0203AB88->var3C[i + 29]].invisible = FALSE;
        }
        for (; i < 19; i++)
        {
            gSprites[gUnknown_0203AB88->var3C[i + 29]].invisible = FALSE;
        }
        break;
    }
}

static void sub_8142F7C(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
    {
        gUnknown_0203AB88->var3C[i + 49] = CreateSprite(&gSpriteTemplate_85B7928, 116, 20, 10);
        gSprites[gUnknown_0203AB88->var3C[i + 49]].invisible = TRUE;
        gSprites[gUnknown_0203AB88->var3C[i + 49]].data[0] = 1;
        gSprites[gUnknown_0203AB88->var3C[i + 49]].callback = sub_814390C;
        gSprites[gUnknown_0203AB88->var3C[i + 49]].oam.priority = 1;
        StartSpriteAnim(&gSprites[gUnknown_0203AB88->var3C[i + 49]], 8);
    }
}

static void sub_8143038(u8 r0, u8 r1)
{
    u8 i = 0;
    if (r0)
    {
        for ( ; i < 6; i++)
        {
            gSprites[gUnknown_0203AB88->var3C[i + 49]].invisible = TRUE;
        }
    }
    else
    {
        for ( ; i < 6; i++)
        {
            if (!gUnknown_0203AB88->var0C[i] || i == r1)
            {
                gSprites[gUnknown_0203AB88->var3C[i + 49]].invisible = TRUE;
            }
            else
            {
                gSprites[gUnknown_0203AB88->var3C[i + 49]].invisible = FALSE;
                gSprites[gUnknown_0203AB88->var3C[i + 49]].pos1.x = (gUnknown_085B6154[gUnknown_0203AB88->var0C[i]].var03 + 1) * 8 + 4;
                gSprites[gUnknown_0203AB88->var3C[i + 49]].pos1.y = (gUnknown_085B6154[gUnknown_0203AB88->var0C[i]].var04 + 1) * 8 + 3;
            }
        }
    }
}

static void sub_8143150(u8 r0)
{
    if (!r0)
    {
        gSprites[gUnknown_0203AB88->var3C[48]].invisible = TRUE;
    }
    else
    {
        gSprites[gUnknown_0203AB88->var3C[48]].invisible = FALSE;
        gSprites[gUnknown_0203AB88->var3C[48]].pos1.x = (gUnknown_085B6154[r0].var03 + 2) * 8;
        gSprites[gUnknown_0203AB88->var3C[48]].pos1.y = (gUnknown_085B6154[r0].var04 + 2) * 8;
    }
}

static void sub_81431E4(void)
{
    u8 i, j;
    u16 k;
    struct SpriteSheet s;

    LZ77UnCompWram(gUnknown_085B741C.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = gUnknown_085B741C.size;
    s.tag  = gUnknown_085B741C.tag;
    LoadSpriteSheet(&s);

    k = 15;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            u8 spriteId;
            spriteId = gUnknown_0203AB88->var3C[(i * 4) + 7 + j] = sub_8142C60(&gSpriteTemplate_85B7610[i * 4 + j], 40, &k);
            gSprites[spriteId].animPaused = TRUE;
            gSprites[spriteId].affineAnimPaused = TRUE;
        }
    }
}

static void sub_8143280(struct Sprite *sprite)
{
    s16 cos;
    s16 sin;
    u32 matrixNum;
    s16 angle = gUnknown_0203AB88->var24 + sprite->data[0];
    if (angle >= 360)
        angle -= 360;
    sin = Sin2(angle);
    cos = Cos2(angle);
    sprite->pos2.x =  sin * sprite->data[1] >> 12;
    sprite->pos2.y = -cos * sprite->data[1] >> 12;
    matrixNum = sprite->oam.matrixNum;
    sin /= 16;
    gOamMatrices[matrixNum].d = cos /= 16;
    gOamMatrices[matrixNum].a = cos;
    gOamMatrices[matrixNum].b = sin;
    gOamMatrices[matrixNum].c = -sin;
}

static void sub_8143314(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        struct SpriteSheet s;
        LZ77UnCompWram(gUnknown_085B7750[i].data, gDecompressionBuffer);
        s.data = gDecompressionBuffer;
        s.size = gUnknown_085B7750[i].size;
        s.tag  = gUnknown_085B7750[i].tag;
        LoadSpriteSheet(&s);
    }
    gUnknown_0203AB88->var3C[20] = CreateSprite(&gSpriteTemplate_85B77E4, 208, 16, 4);
    gSprites[gUnknown_0203AB88->var3C[20]].animPaused = TRUE;
    for (i = 0; i < 4; i++)
    {
        gUnknown_0203AB88->var3C[i + 21] = CreateSprite(&gUnknown_085B77FC, i * 8 + 196, 24, 0);
        gSprites[gUnknown_0203AB88->var3C[i + 21]].invisible = TRUE;
        gSprites[gUnknown_0203AB88->var3C[i + 21]].animPaused = TRUE;
    }
    gUnknown_0203AB88->var3C[25] = CreateSprite(&gUnknown_085B7814, 120, 68, 4);
    gSprites[gUnknown_0203AB88->var3C[25]].animPaused = TRUE;
    for (i = 0; i < 3; i++)
    {
        gUnknown_0203AB88->var3C[i + 26] = CreateSprite(&gUnknown_085B782C, i * 16 + 192, 36, 4);
        gSprites[gUnknown_0203AB88->var3C[i + 26]].invisible = TRUE;
        gSprites[gUnknown_0203AB88->var3C[i + 26]].animPaused = TRUE;
    }
    gUnknown_0203AB88->var3C[48] = CreateSprite(&gUnknown_085B7844, 152, 96, 9);
    gSprites[gUnknown_0203AB88->var3C[48]].oam.priority = 1;
    gSprites[gUnknown_0203AB88->var3C[48]].animPaused = TRUE;
    gSprites[gUnknown_0203AB88->var3C[48]].invisible = TRUE;
}

static void sub_8143514(u16 r0)
{
    u8 i;
    u16 d = 1000;
    bool8 v = FALSE;
    for (i = 0; i < 4; i++)
    {
        u8 t = r0 / d;
        gSprites[gUnknown_0203AB88->var3C[i + 21]].invisible = TRUE;
        if (t > 0 || v || i == 3)
        {
            gSprites[gUnknown_0203AB88->var3C[i + 21]].invisible = FALSE;
            gSprites[gUnknown_0203AB88->var3C[i + 21]].oam.tileNum =
                gSprites[gUnknown_0203AB88->var3C[i + 21]].sheetTileStart
                + (*gSprites[gUnknown_0203AB88->var3C[i + 21]].anims + t)->type;
            v = TRUE;
        }
        r0 = r0 % d;
        d = d / 10;
    }
}

static u8 sub_8143614(u8 r0)
{
    u8 t[5] = {0, 1, 2, 3, 4};

    if (r0 >= 20)
        r0 = 0;
    switch (gUnknown_085B6154[r0].var01_0)
    {
    case 3:
        r0 = r0 / 5 - 1;
        if (gUnknown_0203AB88->var16[r0] > 3)
            return 0;
        return t[gUnknown_0203AB88->var16[r0] + 1];
    case 4:
        r0--;
        if (gUnknown_0203AB88->var12[r0] > 2)
            return 0;
        return t[gUnknown_0203AB88->var12[r0] + 2];
    case 12:
        if (gUnknown_0203AB88->var08 & gUnknown_085B6154[r0].var08)
            return 0;
        return t[4];
    }
    return 0;
}

static void sub_81436D0(u8 r0)
{
    struct Sprite *s = &gSprites[gUnknown_0203AB88->var3C[25]];
    s->animCmdIndex = sub_8143614(r0);
    s->oam.tileNum = s->sheetTileStart + (*s->anims + s->animCmdIndex)->type;
}

static void sub_814372C(u8 r0)
{
    u8 i;
    u8 t = 0;
    if (gUnknown_0203AB88->var19 == 1)
        t = 2;
    switch (r0)
    {
    case 6:
        for (i = 0; i < 3; i++)
        {
            gSprites[gUnknown_0203AB88->var3C[i + 26]].invisible = FALSE;
            gSprites[gUnknown_0203AB88->var3C[i + 26]].oam.tileNum =
                gSprites[gUnknown_0203AB88->var3C[i + 26]].sheetTileStart
                + (*gSprites[gUnknown_0203AB88->var3C[i + 26]].anims)->type;
        }
        break;
    case 5:
        gSprites[gUnknown_0203AB88->var3C[28]].oam.tileNum =
            gSprites[gUnknown_0203AB88->var3C[28]].sheetTileStart
            + (*gSprites[gUnknown_0203AB88->var3C[28]].anims + t + 1)->type;
        break;
    case 4:
        gSprites[gUnknown_0203AB88->var3C[28]].oam.tileNum =
            gSprites[gUnknown_0203AB88->var3C[28]].sheetTileStart
            + (*gSprites[gUnknown_0203AB88->var3C[28]].anims + t + 2)->type;
        break;
    case 3:
        gSprites[gUnknown_0203AB88->var3C[27]].oam.tileNum =
            gSprites[gUnknown_0203AB88->var3C[27]].sheetTileStart
            + (*gSprites[gUnknown_0203AB88->var3C[27]].anims + t + 1)->type;
        break;
    case 2:
        gSprites[gUnknown_0203AB88->var3C[27]].oam.tileNum =
            gSprites[gUnknown_0203AB88->var3C[27]].sheetTileStart
            + (*gSprites[gUnknown_0203AB88->var3C[27]].anims + t + 2)->type;
        break;
    case 1:
        gSprites[gUnknown_0203AB88->var3C[26]].oam.tileNum =
            gSprites[gUnknown_0203AB88->var3C[26]].sheetTileStart
            + (*gSprites[gUnknown_0203AB88->var3C[26]].anims + t + 1)->type;
        break;
    case 0:
    default:
        for (i = 0; i < 3; i++)
        {
            gSprites[gUnknown_0203AB88->var3C[i + 26]].oam.tileNum =
                gSprites[gUnknown_0203AB88->var3C[i + 26]].sheetTileStart
                + (*gSprites[gUnknown_0203AB88->var3C[i + 26]].anims + t + 2)->type;
        }
    }
}

static void sub_814390C(struct Sprite *sprite)
{
    sprite->pos2.x = gUnknown_0203AB88->var26;
}

static void sub_814391C(void)
{
    u8 spriteId;
    struct SpriteSheet s;
    LZ77UnCompWram(gUnknown_085B7948.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = gUnknown_085B7948.size;
    s.tag = gUnknown_085B7948.tag;
    LoadSpriteSheet(&s);
    spriteId = CreateSprite(&gSpriteTemplate_85B7950, 116, 80, 81);
    gSprites[spriteId].data[0] = gUnknown_0203AB88->var24;
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].affineAnimPaused = TRUE;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
}

static void sub_814399C(struct Sprite *sprite)
{
    u32 t = sprite->oam.matrixNum;
    struct OamMatrix *m = &gOamMatrices[0];
    m[t].d = gUnknown_0203AB88->var2C.a;
    m[t].a = gUnknown_0203AB88->var2C.a;
    m[t].b = gUnknown_0203AB88->var2C.b;
    m[t].c = gUnknown_0203AB88->var2C.c;
}

static void sub_81439C8(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
    {
        gUnknown_0203AB88->var3C[i] = CreateSprite(&gSpriteTemplate_85B7928, 116, 80, 57 - i);
        if (gUnknown_0203AB88->var3C[i] != MAX_SPRITES)
        {
            gSprites[gUnknown_0203AB88->var3C[i]].invisible = TRUE;
            gSprites[gUnknown_0203AB88->var3C[i]].coordOffsetEnabled = TRUE;
        }
    }
}

static void sub_8143A40(void)
{
    u8 t = gUnknown_0203AB88->var3C[0];
    u8 i;
    for (i = 0; i < 6; i++)
    {
        u8 j;
        gSprites[t].invisible = TRUE;
        gSprites[t].callback = &SpriteCallbackDummy;
        StartSpriteAnim(&gSprites[t], 0);
        for (j = 0; j < 8; j++)
        {
            gSprites[t].data[j] = 0;
        }
        t++;
    }
}

static s16 sub_8143AC8(struct Sprite *sprite)
{
    if (gUnknown_0203AB88->var24 > sprite->data[3])
    {
        sprite->data[6] = 360 - gUnknown_0203AB88->var24 + sprite->data[3];
        if (sprite->data[6] >= 360)
            sprite->data[6] -= 360;
    }
    else
    {
        sprite->data[6] = sprite->data[3] - gUnknown_0203AB88->var24;
    }

    return sprite->data[6];
}

static u8 sub_8143B14(struct Sprite *sprite)
{
    gUnknown_0203AB88->var7E = sub_8143AC8(sprite) / 30.0f;
    return gUnknown_0203AB88->var7E;
}

static s16 sub_8143B48(struct Sprite *sprite)
{
    s16 t = sub_8143AC8(sprite) % 30;
    u16 z;
    if (t == 14)
    {
        z = 0;
        return sprite->data[2] = z;
    }
    else if (t > 13)
    {
        z = 43 - t;
        return sprite->data[2] = z;
    }
    else
    {
        z = 14 - t;
        return sprite->data[2] = z;
    }
}

static void sub_8143B84(struct Sprite *sprite)
{
    s16 sin, cos;

    gUnknown_0203AB88->var8C += gUnknown_0203AB88->var90;
    gUnknown_0203AB88->var88 += gUnknown_0203AB88->var8C;

    if (gUnknown_0203AB88->var88 >= 360)
        gUnknown_0203AB88->var88 -= 360.0f;
    else if (gUnknown_0203AB88->var88 < 0.0f)
        gUnknown_0203AB88->var88 += 360.0f;

    sprite->data[3] = gUnknown_0203AB88->var88;
    gUnknown_0203AB88->var98 += gUnknown_0203AB88->var9C;
    gUnknown_0203AB88->var94 += gUnknown_0203AB88->var98;
    sprite->data[4] = gUnknown_0203AB88->var94;
    sin = Sin2(sprite->data[3]);
    cos = Cos2(sprite->data[3]);
    sprite->pos2.x =  sin * sprite->data[4] >> 12;
    sprite->pos2.y = -cos * sprite->data[4] >> 12;
    if (IsSEPlaying())
    {
        m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, sprite->pos2.x);
        m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, sprite->pos2.x);
    }
}

static void sub_8143C90(struct Sprite *sprite)
{
    s16 sin, cos;
    sprite->data[3] = gUnknown_0203AB88->var24 + sprite->data[6];
    if (sprite->data[3] >= 360)
        sprite->data[3] -= 360;
    sin = Sin2(sprite->data[3]);
    cos = Cos2(sprite->data[3]);
    sprite->pos2.x =  sin * sprite->data[4] >> 12;
    sprite->pos2.y = -cos * sprite->data[4] >> 12;
    sprite->pos2.y += gSpriteCoordOffsetY;
}

static void sub_8143CFC(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    sprite->data[2]++;
    if (sprite->data[4] < -132 || sprite->data[4] > 80)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;

    if (sprite->data[2] >= 30)
    {
        if (!sprite->data[0])
        {
            if (gUnknown_0203AB88->var94 <= gUnknown_0203AB88->varA0 - 2.0f)
            {
                gUnknown_0203AB88->var7D = 0xFF;
                gUnknown_0203AB88->var03_7 = 0;
                StartSpriteAnim(sprite, sprite->animCmdIndex + 0x3);
                sub_8143B14(sprite);
                sprite->data[4] = 30;
                sub_8143AC8(sprite);
                sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
                sprite->callback = sub_8143C90;
                m4aSongNumStartOrChange(SE_HASHI);
                gUnknown_0203AB88->var9C = gUnknown_0203AB88->var98 = 0.0f;
                gUnknown_0203AB88->var8C = -1.0f;
            }
        }
        else
        {
            if (gUnknown_0203AB88->var94 >= gUnknown_0203AB88->varA0 - 2.0f)
            {
                gUnknown_0203AB88->var7D = 0xFF;
                gUnknown_0203AB88->var03_7 = 0;
                StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
                sub_8143B14(sprite);
                sprite->data[4] = 30;
                sub_8143AC8(sprite);
                sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
                sprite->callback = sub_8143C90;
                m4aSongNumStartOrChange(SE_HASHI);
                gUnknown_0203AB88->var9C = gUnknown_0203AB88->var98 = 0.0f;
                gUnknown_0203AB88->var8C = -1.0f;
            }
        }
    }
}

static void sub_8143E14(struct Sprite *sprite)
{
    float f0, f1, f2;
    sub_8143B84(sprite);

    switch (sprite->data[3])
    {
    case 0:
        if (sprite->data[0] != 1)
        {
            f0 = sprite->data[7];
            f1 = (f0 * gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01 + (gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 - 1));
            f2 = (f0 / gUnknown_085B6348[gUnknown_0203AB88->var04_0].var0C);
        }
        else
        {
            return;
        }
        break;
    case 180:
        if (sprite->data[0] != 0)
        {
            f0 = sprite->data[7];
            f1 = (f0 * gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01 + (gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 - 1));
            f2 = -(f0 / gUnknown_085B6348[gUnknown_0203AB88->var04_0].var0C);
        }
        else
        {
            return;
        }
        break;
    default:
        return;
    }
    gUnknown_0203AB88->varA0 = gUnknown_0203AB88->var94;
    gUnknown_0203AB88->var98 = f2;
    gUnknown_0203AB88->var9C = -((f2 * 2.0f) / f1 + (2.0f / (f1 * f1)));
    gUnknown_0203AB88->var8C = 0.0f;
    sprite->animPaused = FALSE;
    sprite->animNum = 0;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->callback = sub_8143CFC;
    sprite->data[2] = 0;
}

static void sub_8143FA4(struct Sprite *sprite)
{
    sprite->pos2.y = (s16)(sprite->data[2] * 0.05f * sprite->data[2]) - 45;
    sprite->data[2]++;
    if (sprite->data[2] > 29 && sprite->pos2.y >= 0)
    {
        gUnknown_0203AB88->var7D = 0xFF;
        gUnknown_0203AB88->var03_7 = FALSE;
        StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
        sub_8143B14(sprite);
        sprite->data[4] = 30;
        sub_8143AC8(sprite);
        sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
        sprite->callback = sub_8143C90;
        m4aSongNumStartOrChange(SE_HASHI);
        gUnknown_0203AB88->var03_6 = TRUE;
    }
}

static void sub_8144050(struct Sprite *sprite)
{
    if (sprite->data[2]++ < 45)
    {
        sprite->pos2.y--;
        if (sprite->data[2] == 45)
        {
            if (gSprites[gUnknown_0203AB88->var3C[55]].animCmdIndex == 1)
                sprite->pos2.y++;
        }
    }
    else
    {
        if (sprite->data[2] < sprite->data[7])
        {
            if (gSprites[gUnknown_0203AB88->var3C[55]].animDelayCounter == 0)
            {
                if (gSprites[gUnknown_0203AB88->var3C[55]].animCmdIndex == 1)
                    sprite->pos2.y++;
                else
                    sprite->pos2.y--;
            }
        }
        else
        {
            sprite->animPaused = FALSE;
            sprite->animNum = 1;
            sprite->animBeginning = TRUE;
            sprite->animEnded = FALSE;
            sprite->data[2] = 0;
            sprite->callback = sub_8143FA4;
            m4aSongNumStart(SE_NAGERU);
        }
    }
}

static void sub_8144128(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    switch (sprite->data[3])
    {
    case 90:
        if (sprite->data[0] != 1)
        {
            sprite->callback  = &sub_8144050;
            sprite->data[2] = 0;
        }
        break;
    case 270:
        if (sprite->data[0] != 0)
        {
            sprite->callback  = &sub_8144050;
            sprite->data[2] = 0;
        }
        break;
    }
}

static void sub_8144168(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    switch (gUnknown_0203AB88->var03_0)
    {
    default:
    case 0:
        sub_81446DC(sprite);
        sprite->callback = sub_8143E14;
        break;
    case 1:
        sub_81448B8(sprite);
        sprite->callback = sub_8144128;
        break;
    }
}

static void prev_quest_read_x24_hm_usage(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (sprite->data[2]-- == 16)
        gUnknown_0203AB88->var98 *= -1.0f;
    if (sprite->data[2] == 0)
    {
        if (!sprite->data[0])
        {
            gUnknown_0203AB88->var7D = 0xFF;
            gUnknown_0203AB88->var03_7 = 0;
            StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
            sub_8143B14(sprite);
            sprite->data[4] = 30;
            sub_8143AC8(sprite);
            sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
            sprite->callback = sub_8143C90;
            m4aSongNumStartOrChange(SE_HASHI);
        }
        else
        {
            sprite->animPaused = TRUE;
            m4aSongNumStart(SE_KON);
            sub_8144A24(sprite);
        }
    }
}

static void sub_8144264(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    sprite->data[2] = 0;
    sub_8143B14(sprite);
    if (!(gUnknown_085B62E4[gUnknown_0203AB88->var7E].var04 & gUnknown_0203AB88->var08))
    {
        gUnknown_0203AB88->var7D = 0xFF;
        gUnknown_0203AB88->var03_7 = 0;
        StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
        sub_8143B14(sprite);
        sprite->data[4] = 30;
        sub_8143AC8(sprite);
        sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
        sprite->callback = sub_8143C90;
        m4aSongNumStartOrChange(SE_HASHI);
    }
    else
    {
        u8 t;
        u32 z;
        m4aSongNumStart(SE_KON);
        z = Random() & 1;
        if (z)
        {
            gUnknown_0203AB88->var8C = 0.0f;
            gUnknown_0203AB88->var7F = t = (gUnknown_0203AB88->var7E + 1) % 12;
        }
        else
        {
            float temp;
            gUnknown_0203AB88->var8C = (temp = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var1C) * 2.0f;
            t = (gUnknown_0203AB88->var7E + 11) % 12;
            gUnknown_0203AB88->var7F = gUnknown_0203AB88->var7E;
        }
        if (gUnknown_085B62E4[t].var04 & gUnknown_0203AB88->var08)
        {
            sprite->data[0] = 1;
            sprite->data[2] = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02;
        }
        else
        {
            sprite->data[0] = gUnknown_085B62E4[t].var04 & gUnknown_0203AB88->var08;
            if (gUnknown_0203AB88->var04_0)
            {
                sprite->data[2] = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01;
            }
            else
            {
                sprite->data[2] = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02;
                if (z)
                {
                    gUnknown_0203AB88->var8C = 0.5f;
                }
                else
                {
                    gUnknown_0203AB88->var8C = -1.5f;
                }
            }
        }
        gUnknown_0203AB88->var98 = 0.085f;
        sprite->callback = prev_quest_read_x24_hm_usage;
        sprite->data[1] = 5;
    }
}

static void sub_8144410(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (gUnknown_0203AB88->var8C > 0.5f)
        return;

    sub_8143B14(sprite);
    if (!sub_8143B48(sprite))
    {
        gUnknown_0203AB88->var90 = 0.0f;
        gUnknown_0203AB88->var8C -= (float)(gUnknown_085B6348[gUnknown_0203AB88->var04_0].var03)
            / (gUnknown_085B6348[gUnknown_0203AB88->var04_0].var04 + 1);
        sprite->data[1] = 4;
        sprite->callback = sub_8144264;
    }
    else
    {
        if (gUnknown_0203AB88->var90 != 0.0f)
        {
            if (gUnknown_0203AB88->var8C < 0.0f)
            {
                gUnknown_0203AB88->var90 = 0.0f;
                gUnknown_0203AB88->var8C = 0.0f;
                gUnknown_0203AB88->var98 /= 1.2;
            }
        }
    }
}

static void sub_8144514(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (gUnknown_0203AB88->var94 > 40.f)
        return;

    gUnknown_0203AB88->var98 = -(4.0f / (float)(gUnknown_0203AB88->var86));
    gUnknown_0203AB88->var90 = -(gUnknown_0203AB88->var8C / (float)(gUnknown_0203AB88->var86));
    sprite->animNum = 2;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->data[1] = 3;
    sprite->callback = sub_8144410;
}

static void sub_81445D8(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (gUnknown_0203AB88->var94 > 60.0f)
        return;

    m4aSongNumStartOrChange(SE_TAMAKORO_E);
    gUnknown_0203AB88->var98 = -(20.0f / (float)(gUnknown_0203AB88->var84));
    gUnknown_0203AB88->var90 = ((1.0f - gUnknown_0203AB88->var8C) / (float)(gUnknown_0203AB88->var84));
    sprite->animNum = 1;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->data[1] = 2;
    sprite->callback = sub_8144514;
}

static void sub_81446AC(struct Sprite *sprite)
{
    sprite->data[1] = 1;
    sprite->data[2] = 0;
    sub_8143B84(sprite);
    sprite->invisible = FALSE;
    sprite->callback = sub_81445D8;
}

static void sub_81446DC(struct Sprite *sprite)
{
    u16 t;
    u8 i;
    s16 s[2][2] = {
        {116, 44},
        {116, 112}
    };
    struct Roulette *p;

    t = sprite->data[7] - 2;
    p = gUnknown_0203AB88;  // why???
    gUnknown_0203AB88->var3C[55] = CreateSprite(&gSpriteTemplate_85B79F8, 36, -12, 50);
    gUnknown_0203AB88->var3C[56] = CreateSprite(&gSpriteTemplate_85B7ABC[0], s[sprite->data[0]][0], s[sprite->data[0]][1], 59);
    gUnknown_0203AB88->var3C[57] = CreateSprite(&gSpriteTemplate_85B7ABC[1], 36, 140, 51);
    gSprites[gUnknown_0203AB88->var3C[57]].oam.objMode = ST_OAM_OBJ_BLEND;
    for (i = 0; i < 3; i++)
    {
        gSprites[gUnknown_0203AB88->var3C[i + 55]].coordOffsetEnabled = FALSE;
        gSprites[gUnknown_0203AB88->var3C[i + 55]].invisible = TRUE;
        gSprites[gUnknown_0203AB88->var3C[i + 55]].animPaused = TRUE;
        gSprites[gUnknown_0203AB88->var3C[i + 55]].affineAnimPaused = TRUE;
        gSprites[gUnknown_0203AB88->var3C[i + 55]].data[4] = gUnknown_0203AB88->var3C[55];
        gSprites[gUnknown_0203AB88->var3C[i + 55]].data[5] = gUnknown_0203AB88->var3C[56];
        gSprites[gUnknown_0203AB88->var3C[i + 55]].data[6] = gUnknown_0203AB88->var3C[57];
        gSprites[gUnknown_0203AB88->var3C[i + 55]].data[2] = t;
        gSprites[gUnknown_0203AB88->var3C[i + 55]].data[3] = (sprite->data[7] * gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01) +
                                                                (gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 + 0xFFFF);
    }
    gSprites[gUnknown_0203AB88->var3C[56]].coordOffsetEnabled = TRUE;
    gUnknown_0203AB88->var38 = sprite;
}

static void sub_81448B8(struct Sprite *sprite)
{
    u8 i = 0;
    s16 t;
    s16 s[2][2] = {
        {256, 84},
        {-16, 84}
    };

    t = sprite->data[7] - 2;
    gUnknown_0203AB88->var3C[55] = CreateSprite(&gSpriteTemplate_85B7A10, s[sprite->data[0]][0], s[sprite->data[0]][1], 50);
    StartSpriteAnim(&gSprites[gUnknown_0203AB88->var3C[55]], sprite->data[0]);
    gUnknown_0203AB88->var3C[56] = CreateSprite(&gUnknown_085B7AEC, s[sprite->data[0]][0], s[sprite->data[0]][1], 51);
    gSprites[gUnknown_0203AB88->var3C[56]].affineAnimPaused = TRUE;
    gSprites[gUnknown_0203AB88->var3C[56]].animPaused = TRUE;
    sprite->data[7] = (t * gUnknown_085B6348[gUnknown_0203AB88->var04_0].var01) + (gUnknown_085B6348[gUnknown_0203AB88->var04_0].var10 + 45);
    for (; i < 2; i++)
    {
        gSprites[gUnknown_0203AB88->var3C[55 + i]].data[4] = gUnknown_0203AB88->var3C[55];
        gSprites[gUnknown_0203AB88->var3C[55 + i]].data[5] = gUnknown_0203AB88->var3C[56];
        gSprites[gUnknown_0203AB88->var3C[55 + i]].data[6] = gUnknown_0203AB88->var3C[56];
        gSprites[gUnknown_0203AB88->var3C[55 + i]].data[2] = t;
        gSprites[gUnknown_0203AB88->var3C[55 + i]].data[3] = sprite->data[7] - 45;
    }
    gUnknown_0203AB88->var38 = sprite;
}

static void sub_8144A24(struct Sprite *sprite)
{
    u8 z;
    u16 o;
    u8 h = 0;
    u8 j = 5;
    u8 p = 0;
    u8 i = 0;
    u8 val;
    u8 s[10] = {};
    u16 rand = Random();

    gUnknown_0203AB88->var7D = 1;
    gUnknown_0203AB88->var03_5 = TRUE;
    gUnknown_0203AB88->var03_6 = FALSE;
    gUnknown_0203AB88->var7E = 0xFF;
    gUnknown_0203AB88->var88 = sprite->data[3];
    gUnknown_0203AB88->var98 = 0.0f;
    gUnknown_0203AB88->var8C = gUnknown_085B6348[gUnknown_0203AB88->var04_0].var1C;

    o = (gUnknown_0203AB88->var04_0 * 30 + 33) + (0x1 - gUnknown_0203AB88->var03_0) * 15;
    for (i = 0; i < 4; i++)
    {
        if (o < sprite->data[3] && sprite->data[3] <= o + 90)
        {
            sprite->data[0] = i / 2;
            gUnknown_0203AB88->var03_0 = i % 2;
            break;
        }
        if (i == 3)
        {
            sprite->data[0] = 1;
            gUnknown_0203AB88->var03_0 = 1;
            break;
        }
        o += 90;
    }

    if (gUnknown_0203AB88->var03_0)
    {
        if (sprite->data[0])
            PlayCry1(SPECIES_TAILLOW, -63);
        else
            PlayCry1(SPECIES_TAILLOW, 63);
    }
    else
    {
        PlayCry1(SPECIES_SHROOMISH, -63);
    }

    val = 2;
    z = (gUnknown_0203AB88->var7F + 2) % 12;

    if (gUnknown_0203AB88->var03_0 == 1 && gUnknown_0203AB88->var04_0 == 1)
        j += 6;
    else
        j += val;

    for (i = val; i < j; i++)
    {
        if (!(gUnknown_0203AB88->var08 & gUnknown_085B62E4[z].var04))
        {
            s[h++] = i;
            if (p == 0 && (gUnknown_085B62E4[z].var04 & gUnknown_085B6154[gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]].var0C))
                p = i;
        }
        z = (z + 1) % 0xC;
    }

    if ((gUnknown_0203AB88->var03_0 + 1) & gUnknown_0203AB88->var02)
    {
        if (p && (rand & 0xFF) < 0xc0)
            sprite->data[7] = p;
        else
            sprite->data[7] = s[rand % h];
    }
    else
    {
        sprite->data[7] = s[rand % h];
    }

    sprite->callback = sub_8144168;
}

static const u16 gUnknown_085B7B1A[] = {
    0x907,
    0x808,
    0x709,
    0x60A,
    0x50B,
    0x40C,
    0x30D,
    0x20E,
    0x10F,
    0x010,
};

static void sub_8144C70(struct Sprite *sprite)
{
    if (sprite->data[1]++ >= sprite->data[3])
    {
	    sprite->pos1.x -= 2;
        if (sprite->pos1.x < -16)
        {
            if (!gUnknown_0203AB88->var03_6)
                gUnknown_0203AB88->var03_6 = TRUE;
            DestroySprite(sprite);
            gUnknown_0203AB88->var01 = 0;
            gUnknown_0203AB88->var34 = gUnknown_085B7B1A[0];
        }
    }
}

static void sub_8144CD0(struct Sprite *sprite)
{
    int p;
    u16 t[][4] = {
        {-1, 0, 1, 0},
        {-2, 0, 2, 0},
        {-3, 0, 3, 0},
    };

    if (sprite->data[1]++ < sprite->data[3])
    {
        if (sprite->data[1] & 1)
        {
            gSpriteCoordOffsetY = t[sprite->data[2] / 2][sprite->data[7]];
            p = sprite->data[7] + 1;
            sprite->data[7] = p - ((p / 4) * 4);
        }
        sprite->invisible ^= 1;
    }
    else
    {
        gSpriteCoordOffsetY = 0;
        gSprites[gUnknown_0203AB88->var3C[55]].animPaused = FALSE;
        DestroySprite(sprite);
    }
}

static void sub_8144D94(struct Sprite *sprite)
{
    float t;
    sprite->data[1]++;
    t = sprite->data[1];
    sprite->pos2.y = t * 0.039f * t;
    gUnknown_0203AB88->var34 = gUnknown_085B7B1A[(gUnknown_0203AB88->var01 - 1) / 2];
    if (gUnknown_0203AB88->var01 < 19)
        gUnknown_0203AB88->var01++;
    if (sprite->data[1] > 60)
    {
        sprite->data[1] = 0;
        sprite->callback = sub_8144C70;
        gSprites[sprite->data[6]].callback  = sub_8144C70;
        gSprites[sprite->data[6]].data[1] = -2;
        gSprites[sprite->data[5]].invisible = FALSE;
        gSprites[sprite->data[5]].callback  = sub_8144CD0;
        m4aSongNumStart(SE_W070);
    }
}

static void sub_8144E60(struct Sprite *sprite)
{
    if (sprite->data[7] == 0)
    {
        if (gUnknown_0203AB88->var38->data[0] == 0)
        {
            if (gUnknown_0203AB88->var38->data[3] != gUnknown_085B6348[gUnknown_0203AB88->var04_0].var08)
                return;
        }
        else
        {
            if (gUnknown_0203AB88->var38->data[3] != gUnknown_085B6348[gUnknown_0203AB88->var04_0].var08 + 180)
                return;
        }

        sprite->invisible = FALSE;
        sprite->data[7]++;
        m4aSongNumStart(SE_RU_HYUU);
        gUnknown_0203AB88->var01 = 1;
        gUnknown_0203AB88->var34 = gUnknown_085B7B1A[0];
    }
    else
    {
        gUnknown_0203AB88->var34 = gUnknown_085B7B1A[(gUnknown_0203AB88->var01 - 1) / 2];
        if (gUnknown_0203AB88->var01 < 19)
            gUnknown_0203AB88->var01++;

        if (gUnknown_0203AB88->var38->data[0] == 0)
        {
            if (gUnknown_0203AB88->var38->data[3] != gUnknown_085B6348[gUnknown_0203AB88->var04_0].var0A)
                return;
        }
        else
        {
            if (gUnknown_0203AB88->var38->data[3] != gUnknown_085B6348[gUnknown_0203AB88->var04_0].var0A + 180)
                return;
        }

        gSprites[sprite->data[4]].callback  = sub_8144D94;
        gSprites[sprite->data[4]].invisible = FALSE;
        sprite->callback  = &SpriteCallbackDummy;
        sprite->data[7] = 0;
    }
}

static void sub_8144F94(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
}

static void sub_8144FB0(struct Sprite *sprite)
{
    if (sprite->pos1.y > -16)
    {
        sprite->pos1.y--;
    }
    else
    {
        sprite->callback = SpriteCallbackDummy;
        sprite->invisible = TRUE;
        sprite->animPaused = TRUE;
        m4aSongNumStop(SE_BASABASA);
        DestroySprite(sprite);
        FreeOamMatrix(gSprites[gUnknown_0203AB88->var3C[56]].oam.matrixNum);
        DestroySprite(&gSprites[gUnknown_0203AB88->var3C[56]]);
    }
}

static void sub_8145030(struct Sprite *sprite)
{
    if (sprite->data[1] >= 0)
    {
        sprite->data[1]--;
        sprite->pos1.y--;
        if (sprite->data[1] == 0 && sprite->animCmdIndex == 1)
            sprite->pos2.y++;
    }
    else
    {
        if (sprite->data[3] >= 0)
        {
            sprite->data[3]--;
            if (sprite->animDelayCounter == 0)
            {
                if (sprite->animCmdIndex == 1)
                    sprite->pos2.y++;
                else
                    sprite->pos2.y--;
            }
        }
        else
        {
            m4aSongNumStart(SE_RU_HYUU);
            StartSpriteAnim(sprite, gUnknown_0203AB88->var38->data[0] + 4);
            sprite->callback = sub_8144FB0;
            gSprites[sprite->data[6]].affineAnimPaused = FALSE;
        }
    }
}

static void sub_81450D8(struct Sprite *sprite)
{
    s8 t[2] = {-1, 1};
    s8 z[][2] = {
        {2, 0},
        {2, 0},
        {2, -1},
        {2, -1},
        {2, -1},
        {2, -1},
        {2, -2},
        {2, -2},
    };

    if (sprite->data[1]-- > 7)
    {
        sprite->pos1.x += t[gUnknown_0203AB88->var38->data[0]] * 2;
        if (IsSEPlaying())
        {
            s8 pan = -((116 - sprite->pos1.x) / 2);
            m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
            m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
        }
    }
    else
    {
        if (sprite->data[1] >= 0)
        {
            sprite->pos1.x += t[gUnknown_0203AB88->var38->data[0]] * z[7 - sprite->data[1]][0];
            sprite->pos1.y += z[7 - sprite->data[1]][1];
        }
        else
        {
            m4aSongNumStartOrChange(SE_BASABASA);
            if (gUnknown_0203AB88->var38->data[0] == 0)
                PlayCry1(SPECIES_TAILLOW, 63);
            else
                PlayCry1(SPECIES_TAILLOW, -63);
            StartSpriteAnim(sprite, gUnknown_0203AB88->var38->data[0] + 2);
            sprite->data[1] = 45;
            sprite->callback = sub_8145030;
        }
    }
}

static void sub_8145218(struct Sprite *sprite)
{
    s8 t[2] = {-1, 1};

    if (sprite->data[1]-- >= 0)
    {
        sprite->pos1.x += t[gUnknown_0203AB88->var38->data[0]] * 2;
        gSprites[sprite->data[6]].invisible ^= 1;
    }
    else
    {
        sprite->callback = sub_8144F94;
    }
}

static void sub_8145294(struct Sprite *sprite)
{
    if (gUnknown_0203AB88->var38->data[0] == 0)
    {
        if (gUnknown_0203AB88->var38->data[3] == gUnknown_085B6348[gUnknown_0203AB88->var04_0].var12 + 90)
        {
            gSprites[sprite->data[6]].data[1] = 52;
            gSprites[sprite->data[4]].data[1] = 52;
        }
        else
        {
            return;
        }
    }
    else
    {
        if (gUnknown_0203AB88->var38->data[3] == gUnknown_085B6348[gUnknown_0203AB88->var04_0].var14 + 270)
        {
            gSprites[sprite->data[6]].data[1] = 46;
            gSprites[sprite->data[4]].data[1] = 46;
        }
        else
        {
            return;
        }
    }
    gSprites[sprite->data[6]].callback = sub_8145218;
    gSprites[sprite->data[4]].callback = sub_81450D8;
    m4aSongNumStart(SE_RU_HYUU);
}
