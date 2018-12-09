#include "global.h"
#include "constants/songs.h"
#include "overworld.h"
#include "field_effect.h"
#include "random.h"
#include "sound.h"
#include "main.h"
#include "slot_machine.h"
#include "string_util.h"
#include "decompress.h"
#include "trig.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "text.h"
#include "menu.h"
#include "alloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "coins.h"
#include "tv.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "main_menu.h"
#include "bg.h"
#include "window.h"

// Text
extern const u8 gText_YouDontHaveThreeCoins[];
extern const u8 gText_QuitTheGame[];
extern const u8 gText_YouveGot9999Coins[];
extern const u8 gText_YouveRunOutOfCoins[];
extern const u8 gText_ReelTimeHelp[];

enum
{
    SLOT_MACHINE_TAG_7_RED,
    SLOT_MACHINE_TAG_7_BLUE,
    SLOT_MACHINE_TAG_AZURILL,
    SLOT_MACHINE_TAG_LOTAD,
    SLOT_MACHINE_TAG_CHERRY,
    SLOT_MACHINE_TAG_POWER,
    SLOT_MACHINE_TAG_REPLAY
};

enum
{
    SLOT_MACHINE_MATCHED_1CHERRY,
    SLOT_MACHINE_MATCHED_2CHERRY,
    SLOT_MACHINE_MATCHED_REPLAY,
    SLOT_MACHINE_MATCHED_LOTAD,
    SLOT_MACHINE_MATCHED_AZURILL,
    SLOT_MACHINE_MATCHED_POWER,
    SLOT_MACHINE_MATCHED_777_MIXED,
    SLOT_MACHINE_MATCHED_777_RED,
    SLOT_MACHINE_MATCHED_777_BLUE,
    SLOT_MACHINE_MATCHED_NONE
};

struct SlotMachineEwramStruct
{
    /*0x00*/ u8 state;
    /*0x01*/ u8 unk01;
    /*0x02*/ u8 pikaPower;
    /*0x03*/ u8 unk03;
    /*0x04*/ u8 unk04;
    /*0x05*/ u8 unk05;
    /*0x06*/ u8 unk06;
    /*0x07*/ u8 unk07;
    /*0x08*/ u16 matchedSymbols;
    /*0x0A*/ u8 unk0A;
    /*0x0B*/ u8 unk0B;
    /*0x0C*/ s16 coins;
    /*0x0E*/ s16 payout;
    /*0x10*/ s16 unk10;
    /*0x12*/ s16 bet;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C[3];
    /*0x22*/ u16 unk22[3];
    /*0x28*/ s16 reelPositions[3];
    /*0x2E*/ s16 unk2E[3];
    /*0x34*/ s16 unk34[3];
    /*0x3A*/ u8 reelTasks[3];
    /*0x3D*/ u8 unk3D;
    /*0x3E*/ u8 unk3E;
    /*0x3F*/ u8 unk3F;
    /*0x40*/ u8 unk40;
    /*0x41*/ u8 unk41;
    /*0x42*/ u8 unk42;
    /*0x43*/ u8 unk43;
    /*0x44*/ u8 unk44[5];
    /*0x49*/ u8 unk49[2];
    /*0x49*/ u8 unk4B[3];
    /*0x4E*/ u8 unk4E[2];
    /*0x50*/ u8 unk50[2];
    /*0x52*/ u8 unk52[2];
    /*0x54*/ u8 unk54[4];
    /*0x58*/ u16 win0h;
    /*0x5a*/ u16 win0v;
    /*0x5c*/ u16 winIn;
    /*0x5e*/ u16 winOut;
    /*0x60*/ u16 backupMapMusic;
    /*0x64*/ MainCallback prevMainCb;
};

struct UnkStruct1
{
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ s16 unk02;
};

#define SLOTMACHINE_GFX_TILES 233

/*static */void CB2_SlotMachineSetup(void);
/*static */void CB2_SlotMachineLoop(void);
/*static */void PlaySlotMachine_Internal(u8 arg0, MainCallback cb);
/*static */void SlotMachineDummyTask(u8 taskId);
/*static */void SlotMachineSetup_0_0(void);
/*static */void SlotMachineSetup_6_2(void);
/*static */void SlotMachineSetup_1_0(void);
/*static */void SlotMachineSetup_2_0(void);
/*static */void SlotMachineSetup_2_1(void);
/*static */void SlotMachineSetup_0_1(void);
/*static */void SlotMachineSetup_3_0(void);
/*static */void SlotMachineSetup_4_0(void);
/*static */void SlotMachineSetup_5_0(void);
/*static */void SlotMachineSetup_6_0(void);
/*static */void SlotMachineSetup_6_1(void);
/*static */void SlotMachineSetup_8_0(void);
/*static */void SlotMachineSetup_9_0(void);
/*static */void SlotMachineSetup_10_0(void);
/*static */void SlotMachineSetup_10_1(void);
/*static */void sub_8101D04(void);
/*static */void sub_8104DA4(void);
/*static */void sub_8101D24(u8 taskId);
/*static */bool8 sub_8101D5C(struct Task *task);
/*static */bool8 sub_8101D8C(struct Task *task);
/*static */bool8 sub_8101DB0(struct Task *task);
/*static */bool8 sub_8101DF4(struct Task *task);
/*static */bool8 sub_8101E10(struct Task *task);
/*static */bool8 sub_8101E3C(struct Task *task);
/*static */bool8 sub_8101F44(struct Task *task);
/*static */bool8 sub_8101F60(struct Task *task);
/*static */bool8 sub_8101F88(struct Task *task);
/*static */bool8 sub_8101FA4(struct Task *task);
/*static */bool8 sub_8102008(struct Task *task);
/*static */bool8 sub_8102034(struct Task *task);
/*static */bool8 sub_8102058(struct Task *task);
/*static */bool8 sub_8102090(struct Task *task);
/*static */bool8 sub_81020C8(struct Task *task);
/*static */bool8 sub_81021E0(struct Task *task);
/*static */bool8 sub_81021FC(struct Task *task);
/*static */bool8 sub_8102264(struct Task *task);
/*static */bool8 sub_81022A0(struct Task *task);
/*static */bool8 sub_81022CC(struct Task *task);
/*static */bool8 sub_81022F0(struct Task *task);
/*static */bool8 sub_8102318(struct Task *task);
/*static */bool8 sub_8102344(struct Task *task);
/*static */bool8 sub_810239C(struct Task *task);
/*static */bool8 sub_81023B8(struct Task *task);
/*static */bool8 sub_81023E0_(struct Task *task);
/*static */bool8 sub_81023FC(struct Task *task);
/*static */bool8 sub_8102424(struct Task *task);
/*static */bool8 sub_8102460(struct Task *task);
/*static */void sub_8102484(void);
/*static */void sub_81024F0(void);
/*static */bool8 sub_8102540_(void);
/*static */u8 sub_8102578(void);
/*static */u16 dp15_jump_random_unknown(void);
/*static */u8 sub_81025BC(void);
/*static */void CheckMatch(void);
/*static */void CheckMatch_CenterRow(void);
/*static */void CheckMatch_TopAndBottom(void);
/*static */void CheckMatch_Diagonals(void);
/*static */u8 GetMatchFromSymbolsInRow(u8 c1, u8 c2, u8 c3);
/*static */void sub_8102A24(void);
/*static */void sub_8102A64(u8 taskId);
/*static */bool8 sub_8102A44(void);
/*static */bool8 sub_8102A9C(struct Task *task);
/*static */bool8 sub_8102AD0(struct Task *task);
/*static */bool8 sub_8102B80(struct Task *task);
/*static */u8 GetTagOfReelSymbolOnScreenAtPos(u8 x, s16 y);
/*static */void sub_8102DA8(void);
/*static */void sub_8102DEC(u8 a0);
/*static */void sub_8102E1C(u8 a0);
/*static */bool8 sub_8102E40(u8 a0);
/*static */void sub_8102E68(u8 taskId);
/*static */bool8 sub_8102EA0(struct Task *task);
/*static */bool8 sub_8102EA4(struct Task *task);
/*static */bool8 sub_8102EC0(struct Task *task);
/*static */bool8 sub_8102F4C(struct Task *task);
/*static */bool8 sub_8103008(struct Task *task);
/*static */bool8 sub_810305C(void);
/*static */bool8 sub_8103154(u8 a0, u8 a1);
/*static */bool8 sub_81031B4(u8 a0, u8 a1);
/*static */bool8 sub_81032C0(void);
/*static */bool8 sub_81032E8(void);
/*static */bool8 sub_810333C(void);
/*static */bool8 sub_81033DC(void);
/*static */bool8 sub_810341C(u8 a0);
/*static */bool8 sub_810347C(u8 a0);
/*static */void sub_81034F4(void);
/*static */void sub_8103540(void);
/*static */void sub_8103564(void);
/*static */void j5_08111E84(void);
/*static */void sub_8103668(void);
/*static */void sub_810380C(void);
/*static */void sub_8103830(void);
/*static */void sub_8103910(void);
/*static */void sub_8103A78(void);
/*static */void sub_8103C14(u8 a0);
/*static */void sub_8103C48(u8 taskId);
/*static */void sub_8103D50(u8 a0);
/*static */void sub_8103C78(struct Task *task, u8 taskId);
/*static */void sub_8103CAC(struct Task *task, u8 taskId);
/*static */void sub_8103CC8(struct Task *task, u8 taskId);
/*static */void sub_8103D8C(u8 a0);
/*static */void sub_8103DC8(void);
/*static */void sub_8103E04(u8 a0);
/*static */bool8 sub_8103E38(void);
/*static */bool8 sub_8103E7C(void);
/*static */bool8 sub_8103EAC(u8 spriteId);
/*static */void sub_8103EE4(struct Sprite *sprite);
/*static */void sub_8103F70(void);
/*static */bool8 sub_8103FA0(void);
/*static */void sub_8103FE8_(u8 taskId);
/*static */void sub_8104048(void);
/*static */void sub_8104064(u8 pikaPower);
/*static */bool8 sub_81040C8(void);
/*static */void sub_81040E8(u8 taskId);
/*static */void nullsub_68(struct Task *task);
/*static */void sub_810411C(struct Task *task);
/*static */void sub_8104144(struct Task *task);
/*static */void sub_81041AC(struct Task *task);
/*static */void sub_812D394(struct Task *task);
/*static */void sub_810423C(u8 pikaPower);
/*static */void sub_810430C(void);
/*static */bool8 sub_810432C(void);
/*static */void sub_810434C(u8 taskId);
/*static */void sub_810437C(struct Task *task);
/*static */void sub_81043EC(struct Task *task);
/*static */void sub_8104468(struct Task *task);
/*static */void sub_8104498(struct Task *task);
/*static */void sub_8104548(struct Task *task);
/*static */void sub_8104598(struct Task *task);
/*static */void sub_81045CC(struct Task *task);
/*static */void sub_810463C(struct Task *task);
/*static */void sub_81046C0(struct Task *task);
/*static */void sub_8104764(struct Task *task);
/*static */void sub_8104794(struct Task *task);
/*static */void sub_81047EC(struct Task *task);
/*static */void sub_8104860(struct Task *task);
/*static */void sub_81048A8(struct Task *task);
/*static */void sub_81048CC(struct Task *task);
/*static */void sub_8104940(struct Task *task);
/*static */void sub_81049C8(struct Task *task);
/*static */void sub_81049F8(struct Task *task);
/*static */void sub_8104A40(s16 a0, s16 a1);
/*static */void sub_8104A88(s16 a0);
/*static */void sub_8104AB8(u8 a0);
/*static */bool8 sub_8104AEC(void);
/*static */void sub_8104B0C(u8 taskId);
/*static */void sub_8104B3C(struct Task *task);
/*static */void sub_8104B60(struct Task *task);
/*static */void sub_8104B80(struct Task *task);
/*static */void sub_8104BC8(struct Task *task);
/*static */void sub_812DD78(struct Task *task);
/*static */void sub_8104BFC(struct Task *task);
/*static */void sub_812DE14(struct Task *task);
/*static */void sub_812DE30(struct Task *task);
/*static */void sub_8104C44(struct Task *task);
/*static */void sub_8104C5C(void);
/*static */void sub_8104CAC(u8 arg0);
/*static */bool8 sub_8104E18(void);
/*static */void nullsub_69(struct Task *task);
/*static */void sub_8104E74_(u8 taskId);
/*static */void sub_8104EA8(void);
/*static */void sub_8104F8C(void);
/*static */void sub_8104FF4(s16 x, s16 y, u8 a2, s16 a3);
/*static */void sub_81050C4(void);
/*static */void sub_8105100(void);
/*static */void sub_810514C(void);
/*static */void sub_81051C0(void);
/*static */void sub_8105284_(void);
/*static */void sub_81052EC(void);
/*static */void sub_81053A0(void);
/*static */void sub_810545C(void);
/*static */void sub_81054B8(void);
/*static */void sub_8105524(void);
/*static */void sub_8105554(void);
/*static */void sub_8105578(void);
/*static */void sub_8105688(s16 a0);
/*static */void sub_81056C0(void);
/*static */void sub_81056F0(void);
/*static */void sub_81057E8(s16 a0);
/*static */void sub_8105804(void);
/*static */void sub_8105854(void);
/*static */void sub_81058A0(void);
/*static */void sub_81058C4(void);
/*static */void sub_81059B8(void);
/*static */void sub_81059E8(void);
/*static */bool8 sub_8105ACC(void);
/*static */void sub_8105AEC(void);
/*static */u8 sub_8105B1C(s16 x, s16 y);
/*static */void sub_8105B88(u8 spriteId);
/*static */u8 sub_8105BF8(u8 templateIdx, void (*callback)(struct Sprite*), s16 x, s16 y, s16 a4);
/*static */void sub_81063C0(void);
/*static */void sub_8106404(void);
/*static */void sub_8106448(void);
/*static */void sub_81064B8(void);
/*static */void sub_81065A8(s16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
/*static */void sub_81065DC(void);
/*static */void sub_812F958(void);
/*static */void sub_812F968(void);
/*static */void LoadSlotMachineWheelOverlay(void);
/*static */u8 sub_8105BB4(u8 templateIdx, u8 cbAndCoordsIdx, s16 a2);

// Ewram variables
static EWRAM_DATA u16 *gUnknown_0203AAC8 = NULL;
static EWRAM_DATA u16 *gUnknown_0203AACC = NULL;
static EWRAM_DATA u16 *gUnknown_0203AAD0 = NULL;
static EWRAM_DATA u8 *gUnknown_0203AAD4 = NULL;
static EWRAM_DATA u8 *gUnknown_0203AAD8 = NULL;
static EWRAM_DATA u16 *gUnknown_0203AADC = NULL;
static EWRAM_DATA u8 *gUnknown_0203AAE0 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAE4 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAE8 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAEC = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAF0 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAF4 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAF8 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AAFC = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB00 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB04 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB08 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB0C = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB10 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB14 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB18 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB1C = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB20 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB24 = NULL;
static EWRAM_DATA struct SpriteFrameImage *gUnknown_0203AB28 = NULL;
static EWRAM_DATA struct SpriteSheet *gUnknown_0203AB2C = NULL;
static EWRAM_DATA struct SpriteSheet *gUnknown_0203AB30 = NULL;
static EWRAM_DATA struct SlotMachineEwramStruct *sSlotMachine = NULL;

// IWRAM bss
static IWRAM_DATA struct SpriteFrameImage *gUnknown_03001188[26];

// Const rom data.
extern const struct UnkStruct1 *const gUnknown_083ED048[];
extern const u16 gPalette_83EDE24[];
extern const u8 gUnknown_083ECD04[][3];
extern const u8 gUnknown_083ECE3A[];
extern const u16 gUnknown_083ECE42[];
extern const u16 gUnknown_083ECE48[];
extern const s16 gUnknown_083ECE7E[][2];
extern const SpriteCallback gUnknown_083ECF0C[];
extern const struct SpriteTemplate *const gUnknown_083EDB5C[];
extern const struct SubspriteTable *const gUnknown_083EDBC4[];
extern const struct SpriteTemplate gSpriteTemplate_83ED6CC;
extern const struct SpriteTemplate gSpriteTemplate_83ED564;
extern const struct SpriteTemplate gSpriteTemplate_83ED54C;
extern const struct SpriteTemplate gSpriteTemplate_83ED534;
extern const u8 gUnknown_083ECC58[2];
extern const struct SpriteTemplate gSpriteTemplate_83ED51C;
extern const u16 gUnknown_083ECE12[];
extern const u16 *const gUnknown_083EDE10[];
extern const u16 gUnknown_083ECE1C[][2];
extern const u16 gUnknown_083ECE30[];
extern const u16 sSlotMatchFlags[];
extern const u16 sSlotPayouts[];
extern const u8 *const gUnknown_083EDCE4;
extern const u8 *const gUnknown_083EDCDC;
extern const u32 sReelTimeGfx[];
extern const struct SpriteSheet sSlotMachineSpriteSheets[];
extern const struct SpritePalette gSlotMachineSpritePalettes[];
extern const u16 *const gUnknown_083EDE20;
extern const s16 gUnknown_083ECCF8[][2];
extern const struct BgTemplate gUnknown_085A7424[4];
extern const struct WindowTemplate gUnknown_085A7434[];
extern const u8 gUnknown_083ECD16[][6];
extern const u8 gUnknown_083ECD28[][6];
extern const u8 gUnknown_083ECD46[][17];
extern const u8 gUnknown_083ECDAC[][17];
extern const u8 sSym2Match[];
extern const u8 gUnknown_083ECCF1[];
extern const u8 sReelSymbols[][21];
extern const u16 *const gUnknown_083EDD08[];
extern const u16 *const gUnknown_083EDD1C[];
extern const u8 gUnknown_083EDD30[];
extern const u8 gUnknown_083EDD35[][2];
extern const u8 gUnknown_083EDD3B[];
extern const u16 *const gUnknown_083EDDA0[];
extern const u16 *const gUnknown_083EDDAC;
extern const u16 sReelTimeWindowTilemap[];
extern const u16 gUnknown_085A9898[];
extern void (*const gUnknown_083ED064[])(void);

const struct BgTemplate gUnknown_085A7424[] =
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
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

const struct WindowTemplate gUnknown_085A7434[] =
{
    {0, 2, 15, 0x1B, 4, 15, 0x194},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_085A7444 =
{
    0, 1, 3, 20, 13, 13, 1
};

const u8 gUnknown_085A744C[] = {3, 1, 2, 0};

bool8 (*const gUnknown_083ECAAC[])(struct Task *task) =
{
    sub_8101D5C,
    sub_8101D8C,
    sub_8101DB0,
    sub_8101DF4,
    sub_8101E10,
    sub_8101E3C,
    sub_8101F44,
    sub_8101F60,
    sub_8101F88,
    sub_8101FA4,
    sub_8102008,
    sub_8102034,
    sub_8102058,
    sub_8102090,
    sub_81020C8,
    sub_81021E0,
    sub_81021FC,
    sub_8102264,
    sub_81022A0,
    sub_81022CC,
    sub_81022F0,
    sub_8102318,
    sub_8102344,
    sub_810239C,
    sub_81023B8,
    sub_81023E0_,
    sub_81023FC,
    sub_8102424,
    sub_8102460,
};

bool8 (*const gUnknown_083ECB20[])(struct Task *task) =
{
    sub_8102A9C,
    sub_8102AD0,
    sub_8102B80
};

bool8 (*const gUnknown_083ECB2C[])(struct Task *task) =
{
    sub_8102EA0,
    sub_8102EA4,
    sub_8102EC0,
    sub_8102F4C,
    sub_8103008
};

bool8 (*const gUnknown_083ECB40[])(void) =
{
    sub_810305C,
    sub_81032C0,
    sub_81033DC
};

void (*const gUnknown_083ECB4C[])(void) =
{
    sub_81034F4,
    sub_8103540,
    sub_810380C
};

const u16 gUnknown_085A74FC[] = {2, 4, 4, 4, 8};

bool8 (*const gUnknown_083ECB64[])(u8 a0, u8 a1) =
{
    sub_8103154,
    sub_81031B4,
    sub_81031B4
};

bool8 (*const gUnknown_083ECB70[])(void) =
{
    sub_81032E8,
    sub_81032E8,
    sub_810333C
};

bool8 (*const gUnknown_083ECB7C[])(u8 a0) =
{
    sub_810341C,
    sub_810341C,
    sub_810347C
};

void (*const gUnknown_083ECB88[])(void) =
{
    sub_8103564,
    j5_08111E84,
    sub_8103668
};

void (*const gUnknown_083ECB94[])(void) =
{
    sub_8103830,
    sub_8103910,
    sub_8103A78
};

void (*const gUnknown_083ECBA0[])(struct Task *task, u8 taskId) =
{
    sub_8103C78,
    sub_8103CAC,
    sub_8103CC8
};

const s16 gUnknown_083ECBAC[] = {5, 10, 15};

void (*const gUnknown_083ECBB4[])(struct Task *task) =
{
    nullsub_68,
    sub_810411C,
    sub_8104144,
    sub_81041AC
};

const u16 gUnknown_083ECBC4[][2] =
{
    {0x9e, 0x6e},
    {0x9f, 0x6f},
    {0xaf, 0x7f},
};

void (*const gUnknown_083ECBD0[])(struct Task *task) =
{
    sub_810437C,
    sub_81043EC,
    sub_8104468,
    sub_8104498,
    sub_8104548,
    sub_8104598,
    sub_81045CC,
    sub_810463C,
    sub_81046C0,
    sub_8104764,
    sub_8104794,
    sub_81047EC,
    sub_8104860,
    sub_81048A8,
    sub_81048CC,
    sub_8104940,
    sub_81049C8,
    sub_8104794,
    sub_81049F8
};

const u8 gUnknown_085A75C0[] = {1, 1, 2, 2};
const s16 gUnknown_085A75C4[] = {0x40, 0x30, 0x18, 0x08};
const s16 gUnknown_085A75CC[] = {10, 8, 6, 4};

void (*const gUnknown_083ECC30[])(struct Task *task) =
{
    sub_8104B3C,
    sub_8104B60,
    sub_8104B80,
    sub_8104B60,
    sub_812DD78,
    sub_8104B60,
    sub_8104BC8,
    sub_8104B60,
    sub_812DE14,
    sub_8104B60,
    sub_812DE30,
    sub_8104B60,
    sub_8104BFC,
    sub_8104B60,
    sub_8104C44,
};

void (*const gUnknown_083ECC54[])(struct Task *task) =
{
    nullsub_69,
};

extern const struct SpriteTemplate gSpriteTemplate_83ED504;
extern const struct SpriteTemplate gSpriteTemplate_83ED4EC;
extern const struct SubspriteTable gSubspriteTables_83ED7D4[];
extern const struct SpriteTemplate gSpriteTemplate_83ED4D4;
extern const struct SubspriteTable gSubspriteTables_83ED7B4[];
extern const struct SpriteTemplate gSpriteTemplate_83ED4BC;
extern const struct SpriteTemplate gSpriteTemplate_83ED4A4;
extern const struct SubspriteTable gSubspriteTables_83ED78C[];
extern const struct SpriteTemplate gSpriteTemplate_83ED474;
extern const struct SpriteTemplate gSpriteTemplate_83ED48C;
extern const struct SubspriteTable gSubspriteTables_83ED73C[];
extern const struct SubspriteTable gSubspriteTables_83ED75C[];
extern const struct SpriteTemplate gSpriteTemplate_83ED444;
extern const struct SubspriteTable gSubspriteTables_83ED704[];
extern const struct SpriteTemplate gSpriteTemplate_83ED42C;
extern const struct SpriteTemplate gSpriteTemplate_83ED414;
extern const struct SpriteTemplate gSpriteTemplate_83ED45C;

// code
#define tState data[0]

/*static */void Task_FadeToSlotMachine(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
        gTasks[taskId].tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_SlotMachineSetup);
            DestroyTask(taskId);
        }
        break;
    }
}

void PlaySlotMachine(u8 arg0, MainCallback cb)
{
    u8 taskId;

    sSlotMachine = AllocZeroed(sizeof(*sSlotMachine));
    PlaySlotMachine_Internal(arg0, cb);
    taskId = CreateTask(Task_FadeToSlotMachine, 0);
    gTasks[taskId].tState = 0;
}

#undef tState

/*static */void CB2_SlotMachineSetup(void)
{
    switch (gMain.state)
    {
        case 0:
            SlotMachineSetup_0_0();
            SlotMachineSetup_0_1();
            gMain.state++;
            break;
        case 1:
            SlotMachineSetup_1_0();
            gMain.state++;
            break;
        case 2:
            SlotMachineSetup_2_0();
            SlotMachineSetup_2_1();
            gMain.state++;
            break;
        case 3:
            SlotMachineSetup_3_0();
            gMain.state++;
            break;
        case 4:
            SlotMachineSetup_4_0();
            gMain.state++;
            break;
        case 5:
            SlotMachineSetup_5_0();
            gMain.state++;
            break;
        case 6:
            SlotMachineSetup_6_0();
            gMain.state++;
            break;
        case 7:
            BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 8:
            SlotMachineSetup_8_0();
            gMain.state++;
            break;
        case 9:
            SlotMachineSetup_9_0();
            gMain.state++;
            break;
        case 10:
            SlotMachineSetup_10_0();
            SlotMachineSetup_10_1();
            gMain.state++;
            break;
        case 11:
            SetMainCallback2(CB2_SlotMachineLoop);
            break;
    }
}

/*static */void CB2_SlotMachineLoop(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

/*static */void SlotMachine_VBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_WIN0H, sSlotMachine->win0h);
    SetGpuReg(REG_OFFSET_WIN0V, sSlotMachine->win0v);
    SetGpuReg(REG_OFFSET_WININ, sSlotMachine->winIn);
    SetGpuReg(REG_OFFSET_WINOUT, sSlotMachine->winOut);
}

/*static */void PlaySlotMachine_Internal(u8 arg0, MainCallback cb)
{
    struct Task *task = gTasks + CreateTask(SlotMachineDummyTask, 0xFF);
    task->data[0] = arg0;
    StoreWordInTwoHalfwords(task->data + 1, (intptr_t)cb);
}

/*static */void sub_81019EC(void)
{
    struct Task *task = gTasks + FindTaskIdByFunc(SlotMachineDummyTask);
    sSlotMachine->unk01 = task->data[0];
    LoadWordFromTwoHalfwords((u16 *)(task->data + 1), (u32 *)&sSlotMachine->prevMainCb);
}

/*static */void SlotMachineDummyTask(u8 taskId)
{
}

/*static */void SlotMachineSetup_0_0(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    CpuFill32(0, (void *)VRAM, VRAM_SIZE);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085A7424, ARRAY_COUNT(gUnknown_085A7424));
    InitWindows(gUnknown_085A7434);
    DeactivateAllTextPrinters();
}

/*static */void SlotMachineSetup_6_0(void)
{
    SetVBlankCallback(SlotMachine_VBlankCallback);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
}

/*static */void SlotMachineSetup_1_0(void)
{
    DmaClearLarge16(3, (u16 *)(BG_VRAM), BG_VRAM_SIZE, 0x1000);
}

/*static */void SlotMachineSetup_2_0(void)
{
    DmaClear16(3, (u16 *)OAM, OAM_SIZE);
}

/*static */void SlotMachineSetup_2_1(void)
{
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 8));
}

/*static */void SlotMachineSetup_0_1(void)
{
    u8 i;

    sub_81019EC();
    sSlotMachine->state = 0;
    sSlotMachine->pikaPower = 0;
    sSlotMachine->unk03 = Random() & 1;
    sSlotMachine->unk04 = 0;
    sSlotMachine->matchedSymbols = 0;
    sSlotMachine->unk0A = 0;
    sSlotMachine->unk0B = 0;
    sSlotMachine->coins = GetCoins();
    sSlotMachine->payout = 0;
    sSlotMachine->unk10 = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->unk18 = 0;
    sSlotMachine->unk1A = 8;
    sSlotMachine->win0h = 0xf0;
    sSlotMachine->win0v = 0xa0;
    sSlotMachine->winIn = 0x3f;
    sSlotMachine->winOut = 0x3f;
    sSlotMachine->backupMapMusic = GetCurrentMapMusic();
    for (i = 0; i < 3; i++)
    {
        sSlotMachine->unk22[i] = 0;
        sSlotMachine->reelPositions[i] = gUnknown_083ECCF8[i][sSlotMachine->unk03] % 21;
        sSlotMachine->unk1C[i] = 0x1f8 - sSlotMachine->reelPositions[i] * 24;
        sSlotMachine->unk1C[i] %= 0x1f8;
    }
    sub_80EDE70(GetCoins());
}

/*static */void SlotMachineSetup_3_0(void)
{
    ResetPaletteFade();
    ResetSpriteData();
    gOamLimit = 0x80;
    FreeAllSpritePalettes();
    ResetTasks();
}

/*static */void SlotMachineSetup_4_0(void)
{
    gUnknown_0203AACC = Alloc(8);
    gUnknown_0203AAD0 = AllocZeroed(0xE);
    gUnknown_0203AADC = AllocZeroed(8);

    gUnknown_0203AAD0[0] = 0x2051;
    gUnknown_0203AAD0[1] = 0x2851;
    gUnknown_0203AAD0[2] = 0x2061;
    gUnknown_0203AAD0[3] = 0x2861;
    gUnknown_0203AAD0[4] = 0x20BE;
    gUnknown_0203AAD0[5] = 0x28BE;
    gUnknown_0203AAD0[6] = 0x20BF;
}

/*static */void SlotMachineSetup_5_0(void)
{
    sub_8106448();
    sub_81064B8();
    sub_81063C0();
    LoadMessageBoxGfx(0, 0x200, 0xF0);
    LoadUserWindowBorderGfx(0, 0x214, 0xE0);
    PutWindowTilemap(0);
}

/*static */void SlotMachineSetup_10_0(void)
{
    sub_8104EA8();
    sub_8104F8C();
    sub_8103DC8();
    sub_81050C4();
}

/*static */void SlotMachineSetup_10_1(void)
{
    sub_8104048();
    sub_8102DA8();
    sub_8104C5C();
    sub_8101D04();
}

/*static */void sub_8101D04(void)
{
    sub_8101D24(CreateTask(sub_8101D24, 0));
}

/*static */void sub_8101D24(u8 taskId)
{
    while (gUnknown_083ECAAC[sSlotMachine->state](gTasks + taskId))
        ;
}

/*static */bool8 sub_8101D5C(struct Task *task)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
    sub_810423C(sSlotMachine->pikaPower);
    sSlotMachine->state++;
    return FALSE;
}

/*static */bool8 sub_8101D8C(struct Task *task)
{
    if (!gPaletteFade.active)
        sSlotMachine->state++;
    return FALSE;
}

/*static */bool8 sub_8101DB0(struct Task *task)
{
    sSlotMachine->payout = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->unk18 = 0;
    sSlotMachine->unk04 &= 0xc0;
    sSlotMachine->state = 4;
    if (sSlotMachine->coins <= 0)
    {
        sSlotMachine->state = 25;
    }
    else if (sSlotMachine->unk0A)
    {
        sSlotMachine->state = 3;
        sub_8104CAC(4);
    }
    return TRUE;
}

/*static */bool8 sub_8101DF4(struct Task *task)
{
    if (sub_8104E18())
        sSlotMachine->state = 4;
    return FALSE;
}

/*static */bool8 sub_8101E10(struct Task *task)
{
    sub_8104CAC(0);
    sSlotMachine->state = 5;
    if (sSlotMachine->coins >= 9999)
        sSlotMachine->state = 23;
    return TRUE;
}

/*static */bool8 sub_8101E3C(struct Task *task)
{
    s16 i;

    if (gMain.newKeys & SELECT_BUTTON)
    {
        sub_8104AB8(0);
        sSlotMachine->state = 8;
    }
    else if (gMain.newKeys & R_BUTTON)
    {
        if (sSlotMachine->coins - (3 - sSlotMachine->bet) >= 0)
        {
            for (i = sSlotMachine->bet; i < 3; i++)
                sub_8103D50(i);
            sSlotMachine->coins -= (3 - sSlotMachine->bet);
            sSlotMachine->bet = 3;
            sSlotMachine->state = 9;
            PlaySE(SE_REGI);
        }
        else
        {
            sSlotMachine->state = 6;
        }
    }
    else
    {
        if (gMain.newKeys & DPAD_DOWN && sSlotMachine->coins != 0)
        {
            PlaySE(SE_REGI);
            sub_8103D50(sSlotMachine->bet);
            sSlotMachine->coins--;
            sSlotMachine->bet++;
        }
        if (sSlotMachine->bet >= 3 || (sSlotMachine->bet != 0 && gMain.newKeys & A_BUTTON))
            sSlotMachine->state = 9;
        if (gMain.newKeys & B_BUTTON)
            sSlotMachine->state = 21;
    }
    return FALSE;
}

/*static */bool8 sub_8101F44(struct Task *task)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouDontHaveThreeCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = 7;
    return FALSE;
}

/*static */bool8 sub_8101F60(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        sub_8197434(0, TRUE);
        sSlotMachine->state = 5;
    }
    return FALSE;
}

/*static */bool8 sub_8101F88(struct Task *task)
{
    if (sub_8104AEC())
        sSlotMachine->state = 5;
    return FALSE;
}

/*static */bool8 sub_8101FA4(struct Task *task)
{
    sub_8102484();
    sub_8104DA4();
    sub_8102DEC(0);
    sub_8102DEC(1);
    sub_8102DEC(2);
    sub_80EEC80();
    task->data[0] = 0;
    if (sSlotMachine->unk04 & 0x20)
    {
        sub_810430C();
        sSlotMachine->state = 10;
    }
    else
    {
        sub_8104CAC(1);
        sSlotMachine->state = 11;
    }
    sSlotMachine->unk1A = 8;
    if (sSlotMachine->unk0A)
        sSlotMachine->unk1A = dp15_jump_random_unknown();
    return FALSE;
}

/*static */bool8 sub_8102008(struct Task *task)
{
    if (sub_810432C())
    {
        sub_8104CAC(1);
        sSlotMachine->unk04 &= 0xDF;
        sSlotMachine->state = 11;
    }
    return FALSE;
}

/*static */bool8 sub_8102034(struct Task *task)
{
    if (++task->data[0] >= 30)
    {
        sub_81024F0();
        sSlotMachine->state = 12;
    }
    return FALSE;
}

/*static */bool8 sub_8102058(struct Task *task)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_JYUNI);
        sub_8102E1C(sSlotMachine->unk18);
        sub_8103C14(sSlotMachine->unk18);
        sSlotMachine->state = 13;
    }
    return FALSE;
}

/*static */bool8 sub_8102090(struct Task *task)
{
    if (!sub_8102E40(sSlotMachine->unk18))
    {
        sSlotMachine->unk18++;
        sSlotMachine->state = 12;
        if (sSlotMachine->unk18 > 2)
        {
            sSlotMachine->state = 14;
        }
        return TRUE;
    }
    return FALSE;
}

/*static */bool8 sub_81020C8(struct Task *task)
{
    sSlotMachine->unk04 &= 0xc0;
    CheckMatch();
    if (sSlotMachine->unk0A)
    {
        sSlotMachine->unk0A--;
        sSlotMachine->unk0B++;
    }

    if (sSlotMachine->matchedSymbols)
    {
        sSlotMachine->state = 15;
        sub_8102A24();
        sub_8103F70();
        if ((sSlotMachine->unk10 -= sSlotMachine->payout) < 0)
        {
            sSlotMachine->unk10 = 0;
        }
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
        {
            PlayFanfare(MUS_ME_B_BIG);
            sub_8104CAC(6);
        }
        else if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_777_MIXED))
        {
            PlayFanfare(MUS_ME_B_BIG);
            sub_8104CAC(5);
        }
        else
        {
            PlayFanfare(MUS_ME_B_SMALL);
            sub_8104CAC(2);
        }
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_MIXED) | (1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
        {
            sSlotMachine->unk04 &= 0x3f;
            if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
            {
                sSlotMachine->unk0A = 0;
                sSlotMachine->unk0B = 0;
                sSlotMachine->unk03 = 0;
                if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_777_BLUE))
                    sSlotMachine->unk03 = 1;
            }
        }
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_POWER) && sSlotMachine->pikaPower < 16)
        {
            sSlotMachine->pikaPower++;
            sub_8104064(sSlotMachine->pikaPower);
        }
    }
    else
    {
        sub_8104CAC(3);
        sSlotMachine->state = 20;
        if ((sSlotMachine->unk10 += sSlotMachine->bet) > 9999)
            sSlotMachine->unk10 = 9999;
    }
    return FALSE;
}

/*static */bool8 sub_81021E0(struct Task *task)
{
    if (sub_8102A44())
        sSlotMachine->state = 16;
    return FALSE;
}

/*static */bool8 sub_81021FC(struct Task *task)
{
    if (sub_8103FA0())
    {
        sSlotMachine->state = 19;
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_RED) | (1 << SLOT_MACHINE_MATCHED_777_BLUE)))
            IncrementGameStat(GAME_STAT_SLOT_JACKPOTS);
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->unk18 = 0;
            sSlotMachine->state = 9;
        }
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_POWER))
            sSlotMachine->state = 17;
        if (sSlotMachine->unk0A && sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sub_8104CAC(4);
            sSlotMachine->state = 18;
        }
    }
    return FALSE;
}

/*static */bool8 sub_8102264(struct Task *task)
{
    if (!sub_81040C8())
    {
        sSlotMachine->state = 19;
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->state = 9;
            if (sSlotMachine->unk0A)
            {
                sub_8104CAC(4);
                sSlotMachine->state = 18;
            }
        }
    }
    return FALSE;
}

/*static */bool8 sub_81022A0(struct Task *task)
{
    if (sub_8104E18())
    {
        sSlotMachine->state = 19;
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->state = 9;
        }
    }
    return FALSE;
}

/*static */bool8 sub_81022CC(struct Task *task)
{
    sub_8103D8C(0);
    sub_8103D8C(1);
    sub_8103D8C(2);
    sSlotMachine->state = 2;
    return FALSE;
}

/*static */bool8 sub_81022F0(struct Task *task)
{
    if (++task->data[1] > 64)
    {
        task->data[1] = 0;
        sSlotMachine->state = 19;
    }
    return FALSE;
}

/*static */bool8 sub_8102318(struct Task *task)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_QuitTheGame, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    CreateYesNoMenuParameterized(0x15, 7, 0x214, 0x180, 0xE, 0xF);
    sSlotMachine->state = 22;
    return FALSE;
}

/*static */bool8 sub_8102344(struct Task *task)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    if (input == 0)
    {
        sub_8197434(0, TRUE);
        sub_8103D8C(0);
        sub_8103D8C(1);
        sub_8103D8C(2);
        sSlotMachine->coins += sSlotMachine->bet;
        sSlotMachine->state = 27;
    }
    else if (input == 1 || input == -1)
    {
        sub_8197434(0, TRUE);
        sSlotMachine->state = 5;
    }
    return FALSE;
}

/*static */bool8 sub_810239C(struct Task *task)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveGot9999Coins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = 24;
    return FALSE;
}

/*static */bool8 sub_81023B8(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        sub_8197434(0, TRUE);
        sSlotMachine->state = 5;
    }
    return FALSE;
}

/*static */bool8 sub_81023E0_(struct Task *task)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveRunOutOfCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = 26;
    return FALSE;
}

/*static */bool8 sub_81023FC(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        sub_8197434(0, TRUE);
        sSlotMachine->state = 27;
    }
    return FALSE;
}

/*static */bool8 sub_8102424(struct Task *task)
{
    SetCoins(sSlotMachine->coins);
    sub_80EDD78(GetCoins());
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    sSlotMachine->state++;
    return FALSE;
}

/*static */bool8 sub_8102460(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSlotMachine->prevMainCb);
        FREE_AND_SET_NULL(gUnknown_0203AAF4);
        FREE_AND_SET_NULL(gUnknown_0203AAF8);
        FREE_AND_SET_NULL(gUnknown_0203AAFC);
        FREE_AND_SET_NULL(gUnknown_0203AB00);
        FREE_AND_SET_NULL(gUnknown_0203AB04);
        FREE_AND_SET_NULL(gUnknown_0203AB08);
        FREE_AND_SET_NULL(gUnknown_0203AB0C);
        FREE_AND_SET_NULL(gUnknown_0203AB10);
        FREE_AND_SET_NULL(gUnknown_0203AB14);
        FREE_AND_SET_NULL(gUnknown_0203AB18);
        FREE_AND_SET_NULL(gUnknown_0203AB1C);
        FREE_AND_SET_NULL(gUnknown_0203AB20);
        FREE_AND_SET_NULL(gUnknown_0203AB24);
        FREE_AND_SET_NULL(gUnknown_0203AB28);
        if (gUnknown_0203AAE4 != NULL)
            FREE_AND_SET_NULL(gUnknown_0203AAE4);
        if (gUnknown_0203AAE8 != NULL)
            FREE_AND_SET_NULL(gUnknown_0203AAE8);
        if (gUnknown_0203AAEC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203AAEC);
        if (gUnknown_0203AAF0 != NULL)
            FREE_AND_SET_NULL(gUnknown_0203AAF0);
        FREE_AND_SET_NULL(gUnknown_0203AAC8);
        FREE_AND_SET_NULL(gUnknown_0203AACC);
        FREE_AND_SET_NULL(gUnknown_0203AAD0);
        FREE_AND_SET_NULL(gUnknown_0203AAD4);
        FREE_AND_SET_NULL(gUnknown_0203AAD8);
        FREE_AND_SET_NULL(gUnknown_0203AADC);
        FREE_AND_SET_NULL(gUnknown_0203AAE0);
        FREE_AND_SET_NULL(gUnknown_0203AB2C);
        FREE_AND_SET_NULL(gUnknown_0203AB30);

        FREE_AND_SET_NULL(sSlotMachine);
    }
    return FALSE;
}

/*static */void sub_8102484(void)
{
    u8 r3;

    if (sSlotMachine->unk0A == 0)
    {
        if (!(sSlotMachine->unk04 & 0xc0))
        {
            if (sub_8102540_())
            {
                r3 = sub_8102578();
                if (r3 != 3)
                {
                    sSlotMachine->unk04 |= gUnknown_083ECE42[r3];
                    if (r3 != 1)
                    {
                        return;
                    }
                }
            }
            r3 = sub_81025BC();
            if (r3 != 5)
            {
                sSlotMachine->unk04 |= gUnknown_083ECE48[r3];
            }
        }
    }
}

/*static */void sub_81024F0(void)
{
    sSlotMachine->unk06 = 0;
    if (sSlotMachine->unk04)
        sSlotMachine->unk06 = 1;
}

/*static */u8 sub_810250C(u8 a0)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        if (a0 & 1)
            return gUnknown_083ECE3A[i];
        a0 >>= 1;
    }
    return 0;
}

/*static */bool8 sub_8102540_(void)
{
    u8 rval = Random();
    if (gUnknown_083ECD04[sSlotMachine->unk01][sSlotMachine->bet - 1] > rval)
        return TRUE;
    return FALSE;
}

/*static */u8 sub_8102578(void)
{
    s16 i;

    for (i = 0; i < 3; i++)
    {
        s16 rval = Random() & 0xff;
        s16 value = gUnknown_083ECD16[i][sSlotMachine->unk01];
        if (value > rval)
            break;
    }
    return i;
}

/*static */u8 sub_81025BC(void)
{
    s16 i;

    for (i = 0; i < 5; i++)
    {
        s16 rval = Random() & 0xff;
        s16 r3 = gUnknown_083ECD28[i][sSlotMachine->unk01];
        if (i == 0 && sSlotMachine->unk03 == 1)
        {
            r3 += 10;
            if (r3 > 0x100)
                r3 = 0x100;
        }
        else if (i == 4 && sSlotMachine->unk03 == 1)
        {
            r3 -= 10;
            if (r3 < 0)
                r3 = 0;
        }
        if (r3 > rval)
            break;
    }
    return i;
}

/*static */u8 sub_810264C(u8 a0)
{
    if (sSlotMachine->unk03 == 0)
        return gUnknown_083ECD46[a0][sSlotMachine->pikaPower];
    else
        return gUnknown_083ECDAC[a0][sSlotMachine->pikaPower];
}

/*static */void sub_8102680(void)
{
    u8 rval;
    s16 i;

    sSlotMachine->unk05 = 0;
    rval = Random();
    if (rval < sub_810264C(0))
        return;
    for (i = 5; i > 0; i--)
    {
        rval = Random();
        if (rval < sub_810264C(i))
            break;
    }
    sSlotMachine->unk05 = i;
}

/*static */bool8 sub_81026DC(u16 a0)
{
    u16 rval = Random() & 0xff;
    if (rval < gUnknown_083ECE12[a0])
        return TRUE;
    else
        return FALSE;
}

/*static */u16 dp15_jump_random_unknown(void)
{
    u8 r4 = 0;
    u8 rval;
    u8 value;
    if (sSlotMachine->unk10 >= 300)
        r4 = 4;
    else if (sSlotMachine->unk10 >= 250)
        r4 = 3;
    else if (sSlotMachine->unk10 >= 200)
        r4 = 2;
    else if (sSlotMachine->unk10 >= 150)
        r4 = 1;
    rval = Random() % 100;
    value = gUnknown_083ECE1C[r4][0];
    if (rval < value)
        return 4;
    rval = Random() % 100;
    value = gUnknown_083ECE1C[r4][1] + gUnknown_083ECE30[sSlotMachine->unk0B];
    if (rval < value)
        return 2;
    return 8;
}

/*static */void CheckMatch(void)
{
    sSlotMachine->matchedSymbols = 0;
    CheckMatch_CenterRow();
    if (sSlotMachine->bet > 1)
        CheckMatch_TopAndBottom();
    if (sSlotMachine->bet > 2)
        CheckMatch_Diagonals();
}

/*static */void CheckMatch_CenterRow(void)
{
    u8 c1, c2, c3, match;

    c1 = GetTagOfReelSymbolOnScreenAtPos(0, 2);
    c2 = GetTagOfReelSymbolOnScreenAtPos(1, 2);
    c3 = GetTagOfReelSymbolOnScreenAtPos(2, 2);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        sub_8103E04(0);
    }
}

/*static */void CheckMatch_TopAndBottom(void)
{
    u8 c1, c2, c3, match;

    c1 = GetTagOfReelSymbolOnScreenAtPos(0, 1);
    c2 = GetTagOfReelSymbolOnScreenAtPos(1, 1);
    c3 = GetTagOfReelSymbolOnScreenAtPos(2, 1);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match == SLOT_MACHINE_MATCHED_1CHERRY)
            match = SLOT_MACHINE_MATCHED_2CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        sub_8103E04(1);
    }
    c1 = GetTagOfReelSymbolOnScreenAtPos(0, 3);
    c2 = GetTagOfReelSymbolOnScreenAtPos(1, 3);
    c3 = GetTagOfReelSymbolOnScreenAtPos(2, 3);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match == SLOT_MACHINE_MATCHED_1CHERRY)
            match = SLOT_MACHINE_MATCHED_2CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        sub_8103E04(2);
    }
}

/*static */void CheckMatch_Diagonals(void)
{
    u8 c1, c2, c3, match;

    c1 = GetTagOfReelSymbolOnScreenAtPos(0, 1);
    c2 = GetTagOfReelSymbolOnScreenAtPos(1, 2);
    c3 = GetTagOfReelSymbolOnScreenAtPos(2, 3);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match != SLOT_MACHINE_MATCHED_1CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        }
        sub_8103E04(3);
    }
    c1 = GetTagOfReelSymbolOnScreenAtPos(0, 3);
    c2 = GetTagOfReelSymbolOnScreenAtPos(1, 2);
    c3 = GetTagOfReelSymbolOnScreenAtPos(2, 1);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match != SLOT_MACHINE_MATCHED_1CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        }
        sub_8103E04(4);
    }
}

/*static */u8 GetMatchFromSymbolsInRow(u8 c1, u8 c2, u8 c3)
{
    if (c1 == c2 && c1 == c3)
        return sSym2Match[c1];
    if (c1 == SLOT_MACHINE_TAG_7_RED && c2 == SLOT_MACHINE_TAG_7_RED && c3 == SLOT_MACHINE_TAG_7_BLUE)
        return SLOT_MACHINE_MATCHED_777_MIXED;
    if (c1 == SLOT_MACHINE_TAG_7_BLUE && c2 == SLOT_MACHINE_TAG_7_BLUE && c3 == SLOT_MACHINE_TAG_7_RED)
        return SLOT_MACHINE_MATCHED_777_MIXED;
    if (c1 == SLOT_MACHINE_TAG_CHERRY)
        return SLOT_MACHINE_MATCHED_1CHERRY;
    return SLOT_MACHINE_MATCHED_NONE;
}

/*static */void sub_8102A24(void)
{
    sub_8102A64(CreateTask(sub_8102A64, 4));
}

/*static */bool8 sub_8102A44(void)
{
    if (FindTaskIdByFunc(sub_8102A64) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

/*static */void sub_8102A64(u8 taskId)
{
    while (gUnknown_083ECB20[gTasks[taskId].data[0]](gTasks + taskId))
        ;
}

/*static */bool8 sub_8102A9C(struct Task *task)
{
    if (sub_8103E38())
    {
        task->data[0]++;
        if (sSlotMachine->payout == 0)
        {
            task->data[0] = 2;
            return TRUE;
        }
    }
    return FALSE;
}

/*static */bool8 sub_8102AD0(struct Task *task)
{
    if (!task->data[1]--)
    {
        if (IsFanfareTaskInactive())
            PlaySE(SE_PIN);
        sSlotMachine->payout--;
        if (sSlotMachine->coins < 9999)
            sSlotMachine->coins++;
        task->data[1] = 8;
        if (gMain.heldKeys & A_BUTTON)
            task->data[1] = 4;
    }
    if (IsFanfareTaskInactive() && gMain.newKeys & START_BUTTON)
    {
        PlaySE(SE_PIN);
        sSlotMachine->coins += sSlotMachine->payout;
        if (sSlotMachine->coins > 9999)
            sSlotMachine->coins = 9999;
        sSlotMachine->payout = 0;
    }
    if (sSlotMachine->payout == 0)
        task->data[0]++;
    return FALSE;
}

/*static */bool8 sub_8102B80(struct Task *task)
{
    if (sub_8103E7C())
        DestroyTask(FindTaskIdByFunc(sub_8102A64));
    return FALSE;
}

/*static */u8 GetTagOfReelSymbolOnScreenAtPos(u8 x, s16 y)
{
    s16 offset = (sSlotMachine->reelPositions[x] + y) % 21;
    if (offset < 0)
        offset += 21;
    return sReelSymbols[x][offset];
}

/*static */u8 GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(u8 x, s16 y)
{
    s16 r6 = 0;
    s16 result = sSlotMachine->unk1C[x] % 24;
    if (result != 0)
        r6 = -1;
    return GetTagOfReelSymbolOnScreenAtPos(x, y + r6);
}

/*static */u8 sub_8102C48(s16 a0)
{
    s16 r1 = (sSlotMachine->unk16 + a0) % 6;
    if (r1 < 0)
        r1 += 6;
    return gUnknown_083ECCF1[r1];
}

/*static */void sub_8102C84(u8 a0, s16 a1)
{
    sSlotMachine->unk1C[a0] += a1;
    sSlotMachine->unk1C[a0] %= 504;
    sSlotMachine->reelPositions[a0] = 21 - sSlotMachine->unk1C[a0] / 24;
}

s16 sub_8102CCC(u8 a0, s16 a1)
{
    s16 r1 = sSlotMachine->unk1C[a0] % 24;
    if (r1 != 0)
    {
        if (r1 < a1)
            a1 = r1;
        sub_8102C84(a0, a1);
        r1 = sSlotMachine->unk1C[a0] % 24;
    }
    return r1;
}

/*static */void sub_8102D28(s16 a0)
{
    sSlotMachine->unk14 += a0;
    sSlotMachine->unk14 %= 120;
    sSlotMachine->unk16 = 6 - sSlotMachine->unk14 / 20;
}

s16 sub_8102D5C(s16 a0)
{
    s16 r1 = sSlotMachine->unk14 % 20;
    if (r1 != 0)
    {
        if (r1 < a0)
            a0 = r1;
        sub_8102D28(a0);
        r1 = sSlotMachine->unk14 % 20;
    }
    return r1;
}

/*static */void sub_8102DA8(void)
{
    u8 i;
    for (i = 0; i < 3; i++)
    {
        u8 taskId = CreateTask(sub_8102E68, 2);
        gTasks[taskId].data[15] = i;
        sSlotMachine->reelTasks[i] = taskId;
        sub_8102E68(taskId);
    }
}

/*static */void sub_8102DEC(u8 a0)
{
    gTasks[sSlotMachine->reelTasks[a0]].data[0] = 1;
    gTasks[sSlotMachine->reelTasks[a0]].data[14] = 1;
}

/*static */void sub_8102E1C(u8 a0)
{
    gTasks[sSlotMachine->reelTasks[a0]].data[0] = 2;
}

/*static */bool8 sub_8102E40(u8 a0)
{
    return gTasks[sSlotMachine->reelTasks[a0]].data[14];
}

/*static */void sub_8102E68(u8 taskId)
{
    while (gUnknown_083ECB2C[gTasks[taskId].data[0]](gTasks + taskId))
        ;
}

/*static */bool8 sub_8102EA0(struct Task *task)
{
    return FALSE;
}

/*static */bool8 sub_8102EA4(struct Task *task)
{
    sub_8102C84(task->data[15], sSlotMachine->unk1A);
    return FALSE;
}


/*static */bool8 sub_8102EC0(struct Task *task)
{
    task->data[0]++;
    sSlotMachine->unk34[task->data[15]] = 0;
    sSlotMachine->unk2E[task->data[15]] = 0;
    if (sSlotMachine->unk0A == 0 && (sSlotMachine->unk04 == 0 || sSlotMachine->unk06 == 0 || !gUnknown_083ECB40[task->data[15]]()))
    {
        sSlotMachine->unk06 = 0;
        gUnknown_083ECB4C[task->data[15]]();
    }
    task->data[1] = sSlotMachine->unk2E[task->data[15]];
    return TRUE;
}

/*static */bool8 sub_8102F4C(struct Task *task)
{
    u16 sp[ARRAY_COUNT(gUnknown_085A74FC)];
    s16 r2;

    memcpy(sp, gUnknown_085A74FC, sizeof(gUnknown_085A74FC));
    r2 = sSlotMachine->unk1C[task->data[15]] % 24;
    if (r2 != 0)
        r2 = sub_8102CCC(task->data[15], sSlotMachine->unk1A);
    else if (sSlotMachine->unk2E[task->data[15]])
    {
        sSlotMachine->unk2E[task->data[15]]--;
        sub_8102C84(task->data[15], sSlotMachine->unk1A);
        r2 = sSlotMachine->unk1C[task->data[15]] % 24;
    }
    if (r2 == 0 && sSlotMachine->unk2E[task->data[15]] == 0)
    {
        task->data[0]++;
        task->data[1] = sp[task->data[1]];
        task->data[2] = 0;
    }
    return FALSE;
}

/*static */bool8 sub_8103008(struct Task *task)
{
    sSlotMachine->unk22[task->data[15]] = task->data[1];
    task->data[1] = -task->data[1];
    task->data[2]++;
    if ((task->data[2] & 0x3) == 0)
        task->data[1] >>= 1;
    if (task->data[1] == 0)
    {
        task->data[0] = 0;
        task->data[14] = 0;
        sSlotMachine->unk22[task->data[15]] = 0;
    }
    return FALSE;
}

/*static */bool8 sub_810305C(void)
{
    u8 r3 = sub_810250C(sSlotMachine->unk04);
    u8 r5 = r3;
    if (sSlotMachine->unk04 & 0xc0)
    {
        r5 = 0;
        r3 = 1;
    }
    return gUnknown_083ECB64[sSlotMachine->bet - 1](r5, r3);
}

/*static */bool8 sub_81030A4(s16 y, u8 tag1, u8 tag2)
{
    u8 tag = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, y);
    if (tag == tag1 || tag == tag2)
    {
        sSlotMachine->unk07 = tag;
        return TRUE;
    }
    return FALSE;
}

/*static */bool8 sub_81030E0(s16 y)
{
    if (GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 1 - y) == 4 || GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 2 - y) == 4 || GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 3 - y) == 4)
        return TRUE;
    else
        return FALSE;
}

/*static */bool8 sub_8103134(void)
{
    if (sSlotMachine->unk04 & 0xc2)
        return TRUE;
    else
        return FALSE;
}

/*static */bool8 sub_8103154(u8 a0, u8 a1)
{
    s16 i;

    for (i = 0; i < 5; i++)
    {
        if (sub_81030A4(2 - i, a0, a1))
        {
            sSlotMachine->unk34[0] = 2;
            sSlotMachine->unk2E[0] = i;
            return TRUE;
        }
    }
    return FALSE;
}

/*static */bool8 sub_81031B4(u8 tag1, u8 tag2)
{
    s16 i;
    bool8 r6 = sub_8103134();
    if (r6 || !sub_81030E0(0))
    {
        for (i = 1; i < 4; i++)
        {
            if (sub_81030A4(i, tag1, tag2))
            {
                sSlotMachine->unk34[0] = i;
                sSlotMachine->unk2E[0] = 0;
                return TRUE;
            }
        }
    }
    for (i = 1; i < 5; i++)
    {
        bool8 r7 = r6;
        if (r7 || !sub_81030E0(i))
        {
            if (sub_81030A4(1 - i, tag1, tag2))
            {
                if (i == 1 && (r7 || !sub_81030E0(3)))
                {
                    sSlotMachine->unk34[0] = 3;
                    sSlotMachine->unk2E[0] = 3;
                    return TRUE;
                }
                if (i < 4 && (r7 || !sub_81030E0(i + 1)))
                {
                    sSlotMachine->unk34[0] = 2;
                    sSlotMachine->unk2E[0] = i + 1;
                    return TRUE;
                }
                sSlotMachine->unk34[0] = 1;
                sSlotMachine->unk2E[0] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

/*static */bool8 sub_81032C0(void)
{
    return gUnknown_083ECB70[sSlotMachine->bet - 1]();
}

/*static */bool8 sub_81032E8(void)
{
    s16 i;
    s16 unk34_0 = sSlotMachine->unk34[0];

    for (i = 0; i < 5; i++)
    {
        if (GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, unk34_0 - i) == sSlotMachine->unk07)
        {
            sSlotMachine->unk34[1] = unk34_0;
            sSlotMachine->unk2E[1] = i;
            return TRUE;
        }
    }
    return FALSE;
}

/*static */bool8 sub_810333C(void)
{
    s16 i;
    if (sub_81032E8())
    {
        if (sSlotMachine->unk34[0] != 2 && sSlotMachine->unk2E[1] > 1 && sSlotMachine->unk2E[1] != 4)
        {
            for (i = 0; i < 5; i++)
            {
                if (GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, 2 - i) == sSlotMachine->unk07)
                {
                    sSlotMachine->unk34[1] = 2;
                    sSlotMachine->unk2E[1] = i;
                    break;
                }
            }
        }
        return TRUE;
    }
    if (sSlotMachine->unk34[0] != 2)
    {
        for (i = 0; i < 5; i++)
        {
            if (GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, 2 - i) == sSlotMachine->unk07)
            {
                sSlotMachine->unk34[1] = 2;
                sSlotMachine->unk2E[1] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

/*static */bool8 sub_81033DC(void)
{
    u8 r3 = sSlotMachine->unk07;
    if (sSlotMachine->unk04 & 0x40)
    {
        r3 = 0;
        if (sSlotMachine->unk07 == 0)
        {
            r3 = 1;
        }
    }
    return gUnknown_083ECB7C[sSlotMachine->bet - 1](r3);
}

/*static */bool8 sub_810341C(u8 a0)
{
    s16 i;
    s16 unk34_1 = sSlotMachine->unk34[1];

    for (i = 0; i < 5; i++)
    {
        if (GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, unk34_1 - i) == a0)
        {
            sSlotMachine->unk34[2] = unk34_1;
            sSlotMachine->unk2E[2] = i;
            return TRUE;
        }
    }
    return FALSE;
}

/*static */bool8 sub_810347C(u8 a0)
{
    s16 i;
    s16 r8;
    if (sSlotMachine->unk34[0] == sSlotMachine->unk34[1])
        return sub_810341C(a0);
    if (sSlotMachine->unk34[0] == 1)
        r8 = 3;
    else
        r8 = 1;
    for (i = 0; i < 5; i++)
    {
        if (GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, r8 - i) == a0)
        {
            sSlotMachine->unk2E[2] = i;
            sSlotMachine->unk34[2] = r8;
            return TRUE;
        }
    }
    return FALSE;
}

/*static */void sub_81034F4(void)
{
    s16 i = 0;

    while (sub_81030E0(i) != 0)
        i++;
    sSlotMachine->unk2E[0] = i;
}

/*static */bool8 sub_8103520(u8 *a0)
{
    if (*a0 == 0)
    {
        *a0 = 1;
        return TRUE;
    }
    if (*a0 == 1)
    {
        *a0 = 0;
        return TRUE;
    }
    return FALSE;
}

/*static */void sub_8103540(void)
{
    gUnknown_083ECB88[sSlotMachine->bet - 1]();
}

/*static */void sub_8103564(void)
{
    if (sSlotMachine->unk34[0] != 0 && sSlotMachine->unk04 & 0x80)
    {
        u8 sp0 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 2 - sSlotMachine->unk2E[0]);
        if (sub_8103520(&sp0))
        {
            s16 i;
            for (i = 0; i < 5; i++)
            {
                if (sp0 == GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, 2 - i))
                {
                    sSlotMachine->unk34[1] = 2;
                    sSlotMachine->unk2E[1] = i;
                    break;
                }
            }
        }
    }
}

/*static */void j5_08111E84(void)
{
    if (sSlotMachine->unk34[0] != 0 && sSlotMachine->unk04 & 0x80)
    {
        u8 sp0 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, sSlotMachine->unk34[0] - sSlotMachine->unk2E[0]);
        if (sub_8103520(&sp0))
        {
            s16 i;
            for (i = 0; i < 5; i++)
            {
                if (sp0 == GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, sSlotMachine->unk34[0] - i))
                {
                    sSlotMachine->unk34[1] = sSlotMachine->unk34[0];
                    sSlotMachine->unk2E[1] = i;
                    break;
                }
            }
        }
    }
}

/*static */void sub_8103668(void)
{
    s16 i;
    s16 j;
    if (sSlotMachine->unk34[0] != 0 && sSlotMachine->unk04 & 0x80)
    {
        if (sSlotMachine->unk34[0] == 2)
        {
            j5_08111E84();
        }
        else
        {
            u8 sp0 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, sSlotMachine->unk34[0] - sSlotMachine->unk2E[0]);
            if (sub_8103520(&sp0))
            {
                j = 2;
                if (sSlotMachine->unk34[0] == 3)
                    j = 3;
                for (i = 0; i < 2; i++, j--)
                {
                    if (sp0 == GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, j))
                    {
                        sSlotMachine->unk34[1] = j;
                        sSlotMachine->unk2E[1] = 0;
                        return;
                    }
                }
                for (j = 1; j < 5; j++)
                {
                    if (sp0 == GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, sSlotMachine->unk34[0] - j))
                    {
                        if (sSlotMachine->unk34[0] == 1)
                        {
                            if (j < 3)
                            {
                                sSlotMachine->unk34[1] = 2;
                                sSlotMachine->unk2E[1] = j + 1;
                            }
                            else
                            {
                                sSlotMachine->unk34[1] = 1;
                                sSlotMachine->unk2E[1] = j;
                            }
                        }
                        else
                        {
                            if (j < 3)
                            {
                                sSlotMachine->unk34[1] = 3;
                                sSlotMachine->unk2E[1] = j;
                            }
                            else
                            {
                                sSlotMachine->unk34[1] = 2;
                                sSlotMachine->unk2E[1] = j - 1;
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
}

/*static */bool8 sub_8103764(u8 a0, u8 a1)
{
    if ((a0 == 0 && a1 == 1) || (a0 == 1 && a1 == 0))
        return TRUE;
    else
        return FALSE;
}

/*static */bool8 sub_810378C(u8 a0, u8 a1, u8 a2)
{
    if ((a0 == 0 && a1 == 1 && a2 == 0) || (a0 == 1 && a1 == 0 && a2 == 1))
        return TRUE;
    else
        return FALSE;
}

/*static */bool8 sub_81037BC(u8 a0, u8 a1, u8 a2)
{
    if ((a0 == 0 && a1 == 1 && a2 == 0) ||
        (a0 == 1 && a1 == 0 && a2 == 1) ||
        (a0 == 0 && a1 == 0 && a2 == 1) ||
        (a0 == 1 && a1 == 1 && a2 == 0) ||
        (a0 == a1 && a0 == a2))
    {
        return FALSE;
    }
    return TRUE;
}

/*static */void sub_810380C(void)
{
    gUnknown_083ECB94[sSlotMachine->bet - 1]();
}

/*static */void sub_8103830(void)
{
    s16 i = 0;
    u8 r5 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 2 - sSlotMachine->unk2E[0]);
    u8 r1 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, 2 - sSlotMachine->unk2E[1]);
    if (r5 == r1)
    {
        while (1)
        {
            u8 r0;
            if (!(r5 == (r0 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, 2 - i)) || (r5 == 0 && r0 == 1) || (r5 == 1 && r0 == 0)))
                break;
            i++;
        }
    }
    else if (sub_8103764(r5, r1))
    {
        if (sSlotMachine->unk04 & 0x80)
        {
            for (i = 0; i < 5; i++)
            {
                if (r5 == GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, 2 - i))
                {
                    sSlotMachine->unk2E[2] = i;
                    return;
                }
            }
        }
        i = 0;
        while (1)
        {
            if (r5 != GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, 2 - i))
                break;
            i++;
        }
    }
    sSlotMachine->unk2E[2] = i;
}

/*static */void sub_8103910(void)
{
    s16 sp0 = 0;
    s16 i;
    u8 r7;
    u8 r6;
    u8 r4;

    if (sSlotMachine->unk34[1] != 0 && sSlotMachine->unk34[0] == sSlotMachine->unk34[1] && sSlotMachine->unk04 & 0x80)
    {
        r7 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, sSlotMachine->unk34[0] - sSlotMachine->unk2E[0]);
        r6 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, sSlotMachine->unk34[1] - sSlotMachine->unk2E[1]);
        if (sub_8103764(r7, r6))
        {
            for (i = 0; i < 5; i++)
            {
                r4 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, sSlotMachine->unk34[1] - i);
                if (r7 == r4)
                {
                    sp0 = i;
                    break;
                }
            }
        }
    }
    while (1)
    {
        s16 r8;
        for (i = 1, r8 = 0; i < 4; i++)
        {
            r7 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, i - sSlotMachine->unk2E[0]);
            r6 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, i - sSlotMachine->unk2E[1]);
            r4 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, i - sp0);
            if (!sub_81037BC(r7, r6, r4) && (!sub_810378C(r7, r6, r4) || !(sSlotMachine->unk04 & 0x80)))
            {
                r8++;
                break;
            }
        }
        if (r8 == 0)
            break;
        sp0++;
    }
    sSlotMachine->unk2E[2] = sp0;
}

/*static */void sub_8103A78(void)
{
    u8 r6;
    u8 r5;
    u8 r4;
    s16 r8;
    s16 i;

    sub_8103910();
    if (sSlotMachine->unk34[1] != 0 && sSlotMachine->unk34[0] != sSlotMachine->unk34[1] && sSlotMachine->unk04 & 0x80)
    {
        r6 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, sSlotMachine->unk34[0] - sSlotMachine->unk2E[0]);
        r5 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, sSlotMachine->unk34[1] - sSlotMachine->unk2E[1]);
        if (sub_8103764(r6, r5))
        {
            r8 = 1;
            if (sSlotMachine->unk34[0] == 1)
                r8 = 3;
            for (i = 0; i < 5; i++)
            {
                r4 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, r8 - (sSlotMachine->unk2E[2] + i));
                if (r6 == r4)
                {
                    sSlotMachine->unk2E[2] += i;
                    break;
                }
            }
        }
    }
    while (1)
    {
        r6 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 1 - sSlotMachine->unk2E[0]);
        r5 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, 2 - sSlotMachine->unk2E[1]);
        r4 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, 3 - sSlotMachine->unk2E[2]);
        if (sub_81037BC(r6, r5, r4) || (sub_810378C(r6, r5, r4) && sSlotMachine->unk04 & 0x80))
            break;
        sSlotMachine->unk2E[2]++;
    }
    while (1)
    {
        r6 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(0, 3 - sSlotMachine->unk2E[0]);
        r5 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(1, 2 - sSlotMachine->unk2E[1]);
        r4 = GetTagOfReelSymbolOnScreenAtPos_AdjustForPixelOffset(2, 1 - sSlotMachine->unk2E[2]);
        if (sub_81037BC(r6, r5, r4) || (sub_810378C(r6, r5, r4) && sSlotMachine->unk04 & 0x80))
            break;
        sSlotMachine->unk2E[2]++;
    }
}

/*static */void sub_8103C14(u8 a0)
{
    u8 taskId = CreateTask(sub_8103C48, 5);
    gTasks[taskId].data[15] = a0;
    sub_8103C48(taskId);
}

/*static */void sub_8103C48(u8 taskId)
{
    gUnknown_083ECBA0[gTasks[taskId].data[0]](gTasks + taskId, taskId);
}

/*static */void sub_8103C78(struct Task *task, u8 taskId)
{
    sub_81065A8(gUnknown_083ECBAC[task->data[15]], 0x62, 0x63, 0x72, 0x73);
    task->data[0]++;
}

/*static */void sub_8103CAC(struct Task *task, u8 taskId)
{
    if (++task->data[1] > 11)
        task->data[0]++;
}

/*static */void sub_8103CC8(struct Task *task, u8 taskId)
{
    sub_81065A8(gUnknown_083ECBAC[task->data[15]], 0x42, 0x43, 0x52, 0x53);
    DestroyTask(taskId);
}

/*static */void sub_8103D00(u8 a0)
{
    LoadPalette(gUnknown_083EDD08[a0], gUnknown_083EDD30[a0], 2);
}

/*static */void sub_8103D28(u8 a0)
{
    LoadPalette(gUnknown_083EDD1C[a0], gUnknown_083EDD30[a0], 2);
}

/*static */void sub_8103D50(u8 a0)
{
    u8 i;
    for (i = 0; i < gUnknown_083EDD3B[a0]; i++)
        sub_8103D00(gUnknown_083EDD35[a0][i]);
}

/*static */void sub_8103D8C(u8 a0)
{
    u8 i;
    for (i = 0; i < gUnknown_083EDD3B[a0]; i++)
        sub_8103D28(gUnknown_083EDD35[a0][i]);
}

/*static */void sub_8103DC8(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        u8 spriteId = CreateInvisibleSprite(sub_8103EE4);
        gSprites[spriteId].data[0] = i;
        sSlotMachine->unk44[i] = spriteId;
    }
}

/*static */void sub_8103E04(u8 a0)
{
    struct Sprite *sprite = gSprites + sSlotMachine->unk44[a0];
    sprite->data[1] = 1;
    sprite->data[2] = 4;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 2;
    sprite->data[7] = 0;
}

/*static */bool8 sub_8103E38(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        struct Sprite *sprite = &gSprites[sSlotMachine->unk44[i]];
        if (sprite->data[1] && sprite->data[2])
            return FALSE;
    }
    return TRUE;
}

/*static */bool8 sub_8103E7C(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        if (!sub_8103EAC(sSlotMachine->unk44[i]))
            return FALSE;
    }
    return TRUE;
}

/*static */bool8 sub_8103EAC(u8 spriteId)
{
    struct Sprite *sprite = gSprites + spriteId;
    if (!sprite->data[1])
        return TRUE;
    if (sprite->data[7])
        sprite->data[1] = 0;
    return sprite->data[7];
}

/*static */void sub_8103EE4(struct Sprite *sprite)
{
    s16 r4;
    if (sprite->data[1])
    {
        if (!sprite->data[3]--)
        {
            sprite->data[7] = 0;
            sprite->data[3] = 1;
            sprite->data[4] += sprite->data[5];
            r4 = 4;
            if (sprite->data[2])
                r4 = 8;
            if (sprite->data[4] <= 0)
            {
                sprite->data[7] = 1;
                sprite->data[5] = -sprite->data[5];
                if (sprite->data[2])
                    sprite->data[2]--;
            }
            else if (sprite->data[4] >= r4)
                sprite->data[5] = -sprite->data[5];
            if (sprite->data[2])
                sprite->data[3] <<= 1;
        }
        MultiplyPaletteRGBComponents(gUnknown_083EDD30[sprite->data[0]], sprite->data[4], sprite->data[4], sprite->data[4]);
    }
}

/*static */void sub_8103F70(void)
{
    u8 taskId = CreateTask(sub_8103FE8_, 6);
    gTasks[taskId].data[3] = 1;
    sub_8103FE8_(taskId);
}

/*static */bool8 sub_8103FA0(void)
{
    u8 taskId = FindTaskIdByFunc(sub_8103FE8_);
    if (!gTasks[taskId].data[2])
    {
        DestroyTask(taskId);
        LoadPalette(gUnknown_083EDDAC, 0x10, 0x20);
        return TRUE;
    }
    return FALSE;
}

/*static */void sub_8103FE8_(u8 taskId)
{
    struct Task *task = gTasks + taskId;
    if (!task->data[1]--)
    {
        task->data[1] = 4;
        task->data[2] += task->data[3];
        if (task->data[2] == 0 || task->data[2] == 2)
            task->data[3] = -task->data[3];
    }
    LoadPalette(gUnknown_083EDDA0[task->data[2]], 0x10, 0x20);
}

/*static */void sub_8104048(void)
{
    sSlotMachine->unk3E = CreateTask(sub_81040E8, 8);
}

/*static */void sub_8104064(u8 pikaPower)
{
    struct Task *task = gTasks + sSlotMachine->unk3E;
    sub_812D394(task);
    task->data[0] = 1;
    task->data[1]++;
    task->data[15] = 1;
}

/*static */void sub_8104098(void)
{
    struct Task *task = gTasks + sSlotMachine->unk3E;
    sub_812D394(task);
    task->data[0] = 3;
    task->data[15] = 1;
}

/*static */bool8 sub_81040C8(void)
{
    return gTasks[sSlotMachine->unk3E].data[15];
}

/*static */void sub_81040E8(u8 taskId)
{
    gUnknown_083ECBB4[gTasks[taskId].data[0]](gTasks + taskId);
}

/*static */void nullsub_68(struct Task *task)
{
}

/*static */void sub_810411C(struct Task *task)
{
    task->data[2] = sub_8105B1C((task->data[1] << 3) + 20, 20);
    task->data[0]++;
}

/*static */void sub_8104144(struct Task *task)
{
    if (gSprites[task->data[2]].data[7])
    {
        s16 r5 = task->data[1] + 2;
        s16 r3 = 0;
        s16 r2 = 0;
        if (task->data[1] == 1)
            r3 = 1, r2 = 1;
        else if (task->data[1] == 16)
            r3 = 2, r2 = 2;
        gUnknown_0203AACC[r2] = gUnknown_083ECBC4[r3][0];
        LoadBgTilemap(2, &gUnknown_0203AACC[r2], 2, r5 + 0x40);
        sub_8105B88(task->data[2]);
        task->data[0] = 0;
        task->data[15] = 0;
    }
}

/*static */void sub_81041AC(struct Task *task)
{
    s16 r5 = task->data[1] + 2;
    s16 r3 = 0;
    s16 r2 = 3;
    if (task->data[1] == 1)
        r3 = 1, r2 = 1;
    else if (task->data[1] == 16)
        r3 = 2, r2 = 2;
    if (task->data[2] == 0)
    {
        gUnknown_0203AACC[r2] = gUnknown_083ECBC4[r3][1];
        LoadBgTilemap(2, &gUnknown_0203AACC[r2], 2, r5 + 0x40);
        task->data[1]--;
    }
    if (++task->data[2] >= 20)
        task->data[2] = 0;
    if (task->data[1] == 0)
    {
        task->data[0] = 0;
        task->data[15] = 0;
    }
}

/*static */void sub_812D394(struct Task *task)
{
    u8 i;

    for (i = 2; i < 16; i++)
        task->data[i] = 0;
}

/*static */void sub_810423C(u8 pikaPower)
{
    s16 i;
    s16 r3 = 0, r1 = 0;
    s16 r4 = 3;
    for (i = 0; i < pikaPower; i++, r4++)
    {
        r3 = 0, r1 = 0;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15)
            r3 = 2, r1 = 2;
        gUnknown_0203AACC[r1] = gUnknown_083ECBC4[r3][0];
        LoadBgTilemap(2, &gUnknown_0203AACC[r1], 2, r4 + 0x40);
    }
    for (; i < 16; i++, r4++)
    {
        r3 = 0, r1 = 3;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15)
            r3 = 2, r1 = 2;
        gUnknown_0203AACC[r1] = gUnknown_083ECBC4[r3][1];
        LoadBgTilemap(2, &gUnknown_0203AACC[r1], 2, r4 + 0x40);
    }
    gTasks[sSlotMachine->unk3E].data[1] = pikaPower;
}

/*static */void sub_810430C(void)
{
    u8 taskId = CreateTask(sub_810434C, 7);
    sub_810434C(taskId);
}

/*static */bool8 sub_810432C(void)
{
    if (FindTaskIdByFunc(sub_810434C) == 0xFF)
        return TRUE;
    return FALSE;
}

/*static */void sub_810434C(u8 taskId)
{
    gUnknown_083ECBD0[gTasks[taskId].data[0]](gTasks + taskId);
}

/*static */void sub_810437C(struct Task *task)
{
    sSlotMachine->unk0A = 0;
    sSlotMachine->unk14 = 0;
    sSlotMachine->unk16 = 0;
    task->data[0]++;
    task->data[1] = 0;
    task->data[2] = 30;
    task->data[4] = 1280;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    sub_8104A40(REG_OFFSET_BG3VOFS, 0);
    sub_81051C0();
    sub_8105100();
    sub_81052EC();
    sub_81053A0();
    sub_810545C();
    sub_8102680();
    StopMapMusic();
    PlayNewMapMusic(MUS_BD_TIME);
}

/*static */void sub_81043EC(struct Task *task)
{
    s16 r3;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    r3 = ((task->data[1] + 240) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (r3 != task->data[2] && task->data[3] <= 18)
    {
        task->data[2] = r3;
        task->data[3] = task->data[1] >> 3;
        sub_8104A40(r3, task->data[3]);
    }
    if (task->data[1] >= 200)
    {
        task->data[0]++;
        task->data[3] = 0;
    }
    sub_8102D28(task->data[4] >> 8);
}

/*static */void sub_8104468(struct Task *task)
{
    sub_8102D28(task->data[4] >> 8);
    if (++task->data[5] >= 60)
    {
        task->data[0]++;
        sub_8105578();
        sub_81056F0();
    }
}

/*static */void sub_8104498(struct Task *task)
{
    int r5;
    u8 sp0[ARRAY_COUNT(gUnknown_085A75C0)];
    s16 sp4[ARRAY_COUNT(gUnknown_085A75C4)];
    s16 spC[ARRAY_COUNT(gUnknown_085A75CC)];

    memcpy(sp0, gUnknown_085A75C0, sizeof(gUnknown_085A75C0));
    memcpy(sp4, gUnknown_085A75C4, sizeof(gUnknown_085A75C4));
    memcpy(spC, gUnknown_085A75CC, sizeof(gUnknown_085A75CC));

    sub_8102D28(task->data[4] >> 8);
    task->data[4] -= 4;
    r5 = 4 - (task->data[4] >> 8);
    sub_8105688(sp4[r5]);
    sub_81057E8(spC[r5]);
    StartSpriteAnimIfDifferent(gSprites + sSlotMachine->unk3F, sp0[r5]);
    if (task->data[4] <= 0x100)
    {
        task->data[0]++;
        task->data[4] = 0x100;
        task->data[5] = 0;
    }
}

/*static */void sub_8104548(struct Task *task)
{
    sub_8102D28(task->data[4] >> 8);
    if (++task->data[5] >= 80)
    {
        task->data[0]++;
        task->data[5] = 0;
        sub_81057E8(2);
        StartSpriteAnimIfDifferent(gSprites + sSlotMachine->unk3F, 3);
    }
}

/*static */void sub_8104598(struct Task *task)
{
    sub_8102D28(task->data[4] >> 8);
    task->data[4] = (u8)task->data[4] + 0x80;
    if (++task->data[5] >= 80)
    {
        task->data[0]++;
        task->data[5] = 0;
    }
}

/*static */void sub_81045CC(struct Task *task)
{
    sub_8102D28(task->data[4] >> 8);
    task->data[4] = (u8)task->data[4] + 0x40;
    if (++task->data[5] >= 40)
    {
        task->data[5] = 0;
        if (sSlotMachine->unk05)
        {
            if (sSlotMachine->unk0A <= task->data[6])
                task->data[0]++;
        }
        else if (task->data[6] > 3)
        {
            task->data[0]++;
        }
        else if (sub_81026DC(task->data[6]))
        {
            task->data[0] = 14;
        }
        task->data[6]++;
    }
}

/*static */void sub_810463C(struct Task *task)
{
    s16 r5 = sSlotMachine->unk14 % 20;
    if (r5)
    {
        r5 = sub_8102D5C(task->data[4] >> 8);
        task->data[4] = (u8)task->data[4] + 0x40;
    }
    else if (sub_8102C48(1) != sSlotMachine->unk05)
    {
        sub_8102D28(task->data[4] >> 8);
        r5 = sSlotMachine->unk14 % 20;
        task->data[4] = (u8)task->data[4] + 0x40;
    }
    if (r5 == 0 && sub_8102C48(1) == sSlotMachine->unk05)
    {
        task->data[4] = 0;
        task->data[0]++;
    }
}

/*static */void sub_81046C0(struct Task *task)
{
    if (++task->data[4] >= 60)
    {
        StopMapMusic();
        sub_81056C0();
        sub_8105804();
        task->data[0]++;
        if(sSlotMachine->unk05 == 0)
        {
            task->data[4] = 0xa0;
            StartSpriteAnimIfDifferent(gSprites + sSlotMachine->unk3F, 5);
            PlayFanfare(MUS_ME_ZANNEN);
        }
        else
        {
            task->data[4] = 0xc0;
            StartSpriteAnimIfDifferent(gSprites + sSlotMachine->unk3F, 4);
            gSprites[sSlotMachine->unk3F].animCmdIndex = 0;
            if (sSlotMachine->pikaPower)
            {
                sub_8104098();
                sSlotMachine->pikaPower = 0;
            }
            PlayFanfare(MUS_ME_B_SMALL);
        }
    }
}

/*static */void sub_8104764(struct Task *task)
{
    if ((task->data[4] == 0 || --task->data[4] == 0) && !sub_81040C8())
        task->data[0]++;
}

/*static */void sub_8104794(struct Task *task)
{
    s16 r4;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    task->data[3] += 8;
    r4 = ((task->data[1] - 8) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (task->data[3] >> 3 <= 25)
        sub_8104A88(r4);
    else
        task->data[0]++;
}

/*static */void sub_81047EC(struct Task *task)
{
    sSlotMachine->unk0B = 0;
    sSlotMachine->unk0A = sSlotMachine->unk05;
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    sSlotMachine->unk1A = 8;
    sub_810514C();
    sub_81054B8();
    sub_8105524();
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    if (sSlotMachine->unk0A == 0)
    {
        DestroyTask(FindTaskIdByFunc(sub_810434C));
    }
    else
    {
        sub_8104CAC(4);
        task->data[1] = dp15_jump_random_unknown();
        task->data[2] = 0;
        task->data[3] = 0;
        task->data[0]++;
    }
}

/*static */void sub_8104860(struct Task *task)
{
    if (sSlotMachine->unk1A == task->data[1])
        task->data[0]++;
    else if (sSlotMachine->unk1C[0] % 24 == 0 && (++task->data[2]& 0x07) == 0)
        sSlotMachine->unk1A >>= 1;
}

/*static */void sub_81048A8(struct Task *task)
{
    if (sub_8104E18())
        DestroyTask(FindTaskIdByFunc(sub_810434C));
}

/*static */void sub_81048CC(struct Task *task)
{
    sub_81054B8();
    sub_81056C0();
    sub_8105804();
    sub_8105854();
    gSprites[sSlotMachine->unk4E[0]].invisible = TRUE;
    StartSpriteAnimIfDifferent(gSprites + sSlotMachine->unk3F, 5);
    task->data[0]++;
    task->data[4] = 4;
    task->data[5] = 0;
    StopMapMusic();
    PlayFanfare(MUS_ME_ZANNEN);
    PlaySE(SE_W153);
}

/*static */void sub_8104940(struct Task *task)
{
    gSpriteCoordOffsetY = task->data[4];
    SetGpuReg(REG_OFFSET_BG1VOFS, task->data[4]);
    if (task->data[5] & 0x01)
        task->data[4] = -task->data[4];
    if ((++task->data[5] & 0x1f) == 0)
        task->data[4] >>= 1;
    if (task->data[4] == 0)
    {
        sub_81058A0();
        sub_81058C4();
        sub_8105284_();
        sub_81059E8();
        gSprites[sSlotMachine->unk4E[0]].invisible = FALSE;
        task->data[0]++;
        task->data[5] = 0;
    }
}

/*static */void sub_81049C8(struct Task *task)
{
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    if (sub_8105ACC())
    {
        task->data[0]++;
        sub_8105AEC();
    }
}

/*static */void sub_81049F8(struct Task *task)
{
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    sub_810514C();
    sub_8105554();
    sub_8105524();
    sub_81059B8();
    DestroyTask(FindTaskIdByFunc(sub_810434C));
}

/*static */void sub_8104A40(s16 a0, s16 a1)
{
    s16 i;

    for (i = 4; i < 15; i++)
    {
        LoadBgTilemap(1, &sReelTimeWindowTilemap[a1 + (i - 4) * 20], 2, 32 * i + a0);
    }
}

/*static */void sub_8104A88(s16 a0)
{
    u8 i;

    for (i = 4; i < 15; i++)
    {
        LoadBgTilemap(1, gUnknown_085A9898, 2, 32 * i + a0);
    }
}

/*static */void sub_8104AB8(u8 a0)
{
    u8 taskId = CreateTask(sub_8104B0C, 1);
    gTasks[taskId].data[1] = a0;
    sub_8104B0C(taskId);
}

/*static */bool8 sub_8104AEC(void)
{
    if (FindTaskIdByFunc(sub_8104B0C) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

/*static */void sub_8104B0C(u8 taskId)
{
    gUnknown_083ECC30[gTasks[taskId].data[0]](gTasks + taskId);
}

/*static */void sub_8104B3C(struct Task *task)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    task->data[0]++;
}

/*static */void sub_8104B60(struct Task *task)
{
    if (!gPaletteFade.active)
        task->data[0]++;
}

/*static */void sub_8104B80(struct Task *task)
{
    sub_8104DA4();
    sub_81065DC();
    AddWindow(&gUnknown_085A7444);
    PutWindowTilemap(1);
    FillWindowPixelBuffer(1, 0);
    task->data[0]++;
}

/*static */void sub_812DD78(struct Task *task)
{
    AddTextPrinterParameterized3(1, 1, 2, 5, gUnknown_085A744C, 0, gText_ReelTimeHelp);
    CopyWindowToVram(1, 3);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
    task->data[0]++;
}

/*static */void sub_8104BC8(struct Task *task)
{
    if (gMain.newKeys & (B_BUTTON | SELECT_BUTTON))
    {
        FillWindowPixelBuffer(1, 0);
        ClearWindowTilemap(1);
        CopyWindowToVram(1, 1);
        RemoveWindow(1);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
        task->data[0]++;
    }
}

/*static */void sub_812DE14(struct Task *task)
{
    sub_812F968();
    ShowBg(3);
    task->data[0]++;
}

/*static */void sub_812DE30(struct Task *task)
{
    sub_8104CAC(task->data[1]);
    task->data[0]++;
}

/*static */void sub_8104BFC(struct Task *task)
{
    sub_810423C(sSlotMachine->pikaPower);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
    task->data[0]++;
}

/*static */void sub_8104C44(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(sub_8104B0C));
}

/*static */void sub_8104C5C(void)
{
    u8 i;
    struct Task *task;
    i = CreateTask(sub_8104E74_, 3);
    sSlotMachine->unk3D = i;
    task = gTasks + i;
    task->data[1] = -1;
    for (i = 4; i < 16; i++)
        task->data[i] = MAX_SPRITES;
}

/*static */void sub_8104CAC(u8 arg0)
{
    u8 i;
    struct Task *task;

    sub_8104DA4();

    task = gTasks + sSlotMachine->unk3D;
    task->data[1] = arg0;

    for (i = 0; gUnknown_083ED048[arg0][i].unk00 != 0xFF; i++)
    {
        u8 spriteId;
        spriteId = sub_8105BB4(
                gUnknown_083ED048[arg0][i].unk00,
                gUnknown_083ED048[arg0][i].unk01,
                gUnknown_083ED048[arg0][i].unk02
        );
        task->data[4 + i] = spriteId;
    }
}

/*static */void sub_8104D30(u8 a0, SpriteCallback a1, s16 a2, s16 a3, s16 a4)
{
    u8 i;
    struct Task *task = gTasks + sSlotMachine->unk3D;
    for (i = 4; i < 16; i++)
    {
        if (task->data[i] == MAX_SPRITES)
        {
            task->data[i] = sub_8105BF8(a0, a1, a2, a3, a4);
            break;
        }
    }
}

/*static */void sub_8104DA4(void)
{
    u8 i;
    struct Task *task = gTasks + sSlotMachine->unk3D;
    if ((u16)task->data[1] != 0xFFFF)
        gUnknown_083ED064[task->data[1]]();
    for (i = 4; i < 16; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            DestroySprite(gSprites + task->data[i]);
            task->data[i] = MAX_SPRITES;
        }
    }
}

/*static */bool8 sub_8104E18(void)
{
    u8 i;
    struct Task *task = gTasks + sSlotMachine->unk3D;
    for (i = 4; i < 16; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            if (gSprites[task->data[i]].data[7])
                return FALSE;
        }
    }
    return TRUE;
}

/*static */void sub_8104E74_(u8 taskId)
{
    gUnknown_083ECC54[gTasks[taskId].data[0]](gTasks + taskId);
}

/*static */void nullsub_69(struct Task *task)
{
}

/*static */void sub_8104EA8(void)
{
    s16 i;
    s16 j;
    s16 x;
    for (i = 0, x = 0x30; i < 3; i++, x += 0x28)
    {
        for (j = 0; j < 120; j += 24)
        {
            struct Sprite *sprite = gSprites + CreateSprite(&gSpriteTemplate_83ED414, x, 0, 14);
            sprite->oam.priority = 3;
            sprite->data[0] = i;
            sprite->data[1] = j;
            sprite->data[3] = -1;
        }
    }
}

/*static */void sub_8104F18(struct Sprite *sprite)
{
    sprite->data[2] = sSlotMachine->unk1C[sprite->data[0]] + sprite->data[1];
    sprite->data[2] %= 120;
    sprite->pos1.y = sSlotMachine->unk22[sprite->data[0]] + 28 + sprite->data[2];
    sprite->sheetTileStart = GetSpriteTileStartByTag(GetTagOfReelSymbolOnScreenAtPos(sprite->data[0], sprite->data[2] / 24));
    SetSpriteSheetFrameTileNum(sprite);
}

/*static */void sub_8104F8C(void)
{
    s16 i;
    s16 x;

    for (x = 203, i = 1; i < 10000; i *= 10, x -= 7)
        sub_8104FF4(x, 23, 0, i);
    for (x = 235, i = 1; i < 10000; i *= 10, x -= 7)
        sub_8104FF4(x, 23, 1, i);
}

/*static */void sub_8104FF4(s16 x, s16 y, u8 a2, s16 a3)
{
    struct Sprite *sprite = gSprites + CreateSprite(&gSpriteTemplate_83ED42C, x, y, 13);
    sprite->oam.priority = 2;
    sprite->data[0] = a2;
    sprite->data[1] = a3;
    sprite->data[2] = a3 * 10;
    sprite->data[3] = -1;
}

/*static */void sub_810506C(struct Sprite *sprite)
{
    u16 tag = sSlotMachine->coins;
    if (sprite->data[0])
        tag = sSlotMachine->payout;
    if (sprite->data[3] != tag)
    {
        sprite->data[3] = tag;
        tag %= (u16)sprite->data[2];
        tag /= (u16)sprite->data[1];
        tag += 7;
        sprite->sheetTileStart = GetSpriteTileStartByTag(tag);
        SetSpriteSheetFrameTileNum(sprite);
    }
}

/*static */void sub_81050C4(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED444, 0x58, 0x48, 15);
    gSprites[spriteId].oam.priority = 3;
    SetSubspriteTables(gSprites + spriteId, gSubspriteTables_83ED704);
}

/*static */void sub_8105100(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    if (gUnknown_0203AAE4 == NULL)
        gUnknown_0203AAE4 = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);

    gUnknown_0203AAE4[0].data = gUnknown_0203AAD8 + (0 * 0x800);
    gUnknown_0203AAE4[0].size = 0x800;
    gUnknown_0203AAE4[1].data = gUnknown_0203AAD8 + (1 * 0x800);
    gUnknown_0203AAE4[1].size = 0x800;
    gUnknown_0203AAE4[2].data = gUnknown_0203AAD8 + (2 * 0x800);
    gUnknown_0203AAE4[2].size = 0x800;
    gUnknown_0203AAE4[3].data = gUnknown_0203AAD8 + (3 * 0x800);
    gUnknown_0203AAE4[3].size = 0x800;
    gUnknown_0203AAE4[4].data = gUnknown_0203AAD8 + (4 * 0x800);
    gUnknown_0203AAE4[4].size = 0x800;

    spriteTemplate = gSpriteTemplate_83ED45C;
    spriteTemplate.images = gUnknown_0203AAE4;
    spriteId = CreateSprite(&spriteTemplate, 280, 80, 1);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    sSlotMachine->unk3F = spriteId;
}

/*static */void sub_810514C(void)
{
    DestroySprite(gSprites + sSlotMachine->unk3F);
    if (gUnknown_0203AAE4 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203AAE4);
}

/*static */void sub_8105170(struct Sprite *sprite)
{
    sprite->pos2.y = sprite->pos2.x = 0;
    if (sprite->animNum == 4)
    {
        sprite->pos2.y = sprite->pos2.x = 8;
        if ((sprite->animCmdIndex != 0 && sprite->animDelayCounter != 0) || (sprite->animCmdIndex == 0 && sprite->animDelayCounter == 0))
            sprite->pos2.y = -8;
    }
}

/*static */void sub_81051C0(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (gUnknown_0203AAE8 == NULL)
        gUnknown_0203AAE8 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    gUnknown_0203AAE8[0].data = gUnknown_0203AAD8 + 0x2800;
    gUnknown_0203AAE8[0].size = 0x300;
    spriteTemplate = gSpriteTemplate_83ED474;
    spriteTemplate.images = gUnknown_0203AAE8;
    spriteId = CreateSprite(&spriteTemplate, 368, 52, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, gSubspriteTables_83ED73C);
    sSlotMachine->unk49[0] = spriteId;

    if (gUnknown_0203AAEC == NULL)
        gUnknown_0203AAEC = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    gUnknown_0203AAEC[0].data = gUnknown_0203AAD8 + 0x2800 + 0x300;
    gUnknown_0203AAEC[0].size = 0x500;
    spriteTemplate = gSpriteTemplate_83ED48C;
    spriteTemplate.images = gUnknown_0203AAEC;
    spriteId = CreateSprite(&spriteTemplate, 368, 84, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, gSubspriteTables_83ED75C);
    sSlotMachine->unk49[1] = spriteId;
}

/*static */void sub_8105284_(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (gUnknown_0203AAF0 == NULL)
        gUnknown_0203AAF0 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    gUnknown_0203AAF0[0].data = gUnknown_0203AAD8 + 0x3000;
    gUnknown_0203AAF0[0].size = 0x600;
    spriteTemplate = gSpriteTemplate_83ED4A4;
    spriteTemplate.images = gUnknown_0203AAF0;
    spriteId = CreateSprite(&spriteTemplate, 0xa8 - gSpriteCoordOffsetX, 0x50, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, gSubspriteTables_83ED78C);
    sSlotMachine->unk42 = spriteId;
}

/*static */void sub_81052EC(void)
{
    u8 i;
    s16 r5;
    for (i = 0, r5 = 0; i < 3; i++, r5 += 20)
    {
        u8 spriteId = CreateSprite(&gSpriteTemplate_83ED4BC, 0x170, 0, 10);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[7] = r5;
        sSlotMachine->unk4B[i] = spriteId;
    }
}

/*static */void sub_810535C(struct Sprite *sprite)
{
    s16 r0 = (u16)(sSlotMachine->unk14 + sprite->data[7]);
    r0 %= 40;
    sprite->pos1.y = r0 + 59;
    StartSpriteAnimIfDifferent(sprite, sub_8102C48(r0 / 20));
}

/*static */void sub_81053A0(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED4D4, 0x170, 0x64, 9);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, gSubspriteTables_83ED7B4);
    sSlotMachine->unk4E[0] = spriteId;

    spriteId = CreateSprite(&gSpriteTemplate_83ED4D4, 0x120, 0x68, 4);
    sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, gSubspriteTables_83ED7B4);
    sSlotMachine->unk4E[1] = spriteId;
}

/*static */void sub_810545C(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED4EC, 0x170, 0x4c, 11);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, gSubspriteTables_83ED7D4);
    sSlotMachine->unk40 = spriteId;
}

/*static */void sub_81054B8(void)
{
    u8 i;

    DestroySprite(&gSprites[sSlotMachine->unk40]);
    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->unk49[i]]);

    if (gUnknown_0203AAE8 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203AAE8);
    if (gUnknown_0203AAEC != NULL)
        FREE_AND_SET_NULL(gUnknown_0203AAEC);

    for (i = 0; i < 3; i++)
        DestroySprite(&gSprites[sSlotMachine->unk4B[i]]);
}

/*static */void sub_8105524(void)
{
    u8 i;

    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->unk4E[i]]);
}

/*static */void sub_8105554(void)
{
    DestroySprite(&gSprites[sSlotMachine->unk42]);
    if (gUnknown_0203AAF0 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203AAF0);
}

/*static */void sub_8105578(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED504, 0x98, 0x20, 5);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->hFlip = TRUE;
    sSlotMachine->unk50[0] = spriteId;
    sprite->data[0] = 8;
    sprite->data[1] = -1;
    sprite->data[2] = -1;
    sprite->data[7] = 0x20;

    spriteId = CreateSprite(&gSpriteTemplate_83ED504, 0xb8, 0x20, 5);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sSlotMachine->unk50[1] = spriteId;
    sprite->data[1] = 1;
    sprite->data[2] = -1;
    sprite->data[7] = 0x20;
}

/*static */void sub_810562C(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
    {
        sprite->data[0]--;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->pos2.x += sprite->data[1];
        sprite->pos2.y += sprite->data[2];
        if (++sprite->data[3] >= 8)
        {
            sprite->data[0] = sprite->data[7];
            sprite->data[3] = 0;
        }
    }
}

/*static */void sub_8105688(s16 a0)
{
    gSprites[sSlotMachine->unk50[0]].data[7] = a0;
    gSprites[sSlotMachine->unk50[1]].data[7] = a0;
}

/*static */void sub_81056C0(void)
{
    u8 i;

    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->unk50[i]]);
}

/*static */void sub_81056F0(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED51C, 0x48, 0x50, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].data[0] = 1;
    gSprites[spriteId].data[5] = 0;
    gSprites[spriteId].data[6] = 16;
    gSprites[spriteId].data[7] = 8;
    sSlotMachine->unk52[0] = spriteId;

    spriteId = CreateSprite(&gSpriteTemplate_83ED51C, 0x68, 0x50, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].hFlip = TRUE;
    sSlotMachine->unk52[1] = spriteId;
}

/*static */void sub_8105784(struct Sprite *sprite)
{
    u8 sp[] = {16, 0};
    if (sprite->data[0] && --sprite->data[6] <= 0)
    {
        MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(7) << 4) + 0x103, sp[sprite->data[5]], sp[sprite->data[5]], sp[sprite->data[5]]);
        ++sprite->data[5];
        sprite->data[5] &= 1;
        sprite->data[6] = sprite->data[7];
    }
}

/*static */void sub_81057E8(s16 a0)
{
    gSprites[sSlotMachine->unk52[0]].data[7] = a0;
}

/*static */void sub_8105804(void)
{
    u8 i;
    MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(7) << 4) + 0x103, 0, 0, 0);
    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->unk52[i]]);
}

/*static */void sub_8105854(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED534, 0xa8, 0x50, 6);
    gSprites[spriteId].oam.priority = 1;
    sSlotMachine->unk41 = spriteId;
}

/*static */void sub_8105894(struct Sprite *sprite)
{
    sprite->pos2.y = gSpriteCoordOffsetY;
}

/*static */void sub_81058A0(void)
{
    DestroySprite(&gSprites[sSlotMachine->unk41]);
}

/*static */void sub_81058C4(void)
{
    u8 i;
    u16 sp[] = {0x0, 0x40, 0x80, 0xC0};
    for (i = 0; i < 4; i++)
    {
        u8 spriteId = CreateSprite(&gSpriteTemplate_83ED54C, 0x50 - gSpriteCoordOffsetX, 0x44, 0);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = sp[i];
        sSlotMachine->unk54[i] = spriteId;
    }
}

/*static */void sub_810594C(struct Sprite *sprite)
{
    sprite->data[0] -= 2;
    sprite->data[0] &= 0xff;
    sprite->pos2.x = Cos(sprite->data[0], 20);
    sprite->pos2.y = Sin(sprite->data[0], 6);
    sprite->subpriority = 0;
    if (sprite->data[0] >= 0x80)
    {
        sprite->subpriority = 2;
    }
    if (++sprite->data[1] >= 16)
    {
        sprite->hFlip ^= 1;
        sprite->data[1] = 0;
    }
}

/*static */void sub_81059B8(void)
{
    u8 i;
    for (i = 0; i < 4; i++)
    {
        DestroySprite(&gSprites[sSlotMachine->unk54[i]]);
    }
}

/*static */void sub_81059E8(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED564, 0xa8, 0x3c, 8);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sSlotMachine->unk43 = spriteId;
}

/*static */void sub_8105A38(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        if (sprite->affineAnimEnded)
            sprite->data[0]++;
    }
    else if (sprite->data[0] == 1)
    {
        sprite->invisible ^= 1;
        if (++sprite->data[2] >= 24)
        {
            sprite->data[0]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        sprite->invisible = TRUE;
        if (++sprite->data[2] >= 16)
            sprite->data[7] = 1;
    }
    sprite->data[1] &= 0xff;
    sprite->data[1] += 16;
    sprite->pos2.y -= (sprite->data[1] >> 8);
}

/*static */u8 sub_8105ACC(void)
{
    return gSprites[sSlotMachine->unk43].data[7];
}

/*static */void sub_8105AEC(void)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->unk43];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

/*static */u8 sub_8105B1C(s16 x, s16 y)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED6CC, x, y, 12);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 2;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    return spriteId;
}

/*static */void sub_8105B70(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        sprite->data[7] = 1;
}

/*static */void sub_8105B88(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

/*static */u8 sub_8105BB4(u8 templateIdx, u8 cbAndCoordsIdx, s16 a2)
{
    return sub_8105BF8(templateIdx, gUnknown_083ECF0C[cbAndCoordsIdx], gUnknown_083ECE7E[cbAndCoordsIdx][0], gUnknown_083ECE7E[cbAndCoordsIdx][1], a2);
}

/*static */u8 sub_8105BF8(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 a4)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    spriteTemplate = *gUnknown_083EDB5C[templateIdx];
    spriteTemplate.images = gUnknown_03001188[templateIdx];
    spriteId = CreateSprite(&spriteTemplate, x, y, 16);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 3;
    sprite->callback = callback;
    sprite->data[6] = a4;
    sprite->data[7] = 1;
    if (gUnknown_083EDBC4[templateIdx])
        SetSubspriteTables(sprite, gUnknown_083EDBC4[templateIdx]);
    return spriteId;
}

/*static */void sub_8105C64(struct Sprite *sprite)
{
    sprite->data[7] = 0;
}

/*static */void sub_8105C6C(struct Sprite *sprite)
{
    s16 sp0[] = {4, -4, 4, -4};
    s16 sp8[] = {4, 4, -4, -4};

    if (sprite->data[1]++ >= 16)
    {
        sprite->subspriteTableNum ^= 1;
        sprite->data[1] = 0;
    }
    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    if (sprite->subspriteTableNum != 0)
    {
        sprite->pos2.x = sp0[sprite->data[6]];
        sprite->pos2.y = sp8[sprite->data[6]];
    }
}

/*static */void sub_8105CF0(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    sub_8105C6C(sprite);
}

/*static */void sub_8105D08(struct Sprite *sprite)
{
    sprite->vFlip = TRUE;
    sub_8105C6C(sprite);
}

/*static */void sub_8105D20(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    sprite->vFlip = TRUE;
    sub_8105C6C(sprite);
}

/*static */void sub_8105D3C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0xd0)
        {
            sprite->pos1.x = 0xd0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 90)
            sprite->data[0]++;
        break;
    case 2:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0x110)
            sprite->data[0]++;
        break;
    case 3:
        sprite->data[7] = 0;
        break;
    }
}

/*static */void sub_8105DA4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.x -= 4;
        if (sprite->pos1.x <= 0xd0)
        {
            sprite->pos1.x = 0xd0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 90)
            sprite->data[0]++;
        break;
    case 2:
        sprite->pos1.x -= 4;
        if (sprite->pos1.x <= 0x90)
            sprite->data[0]++;
        break;
    case 3:
        sprite->data[7] = 0;
        break;
    }
}

/*static */void sub_8105E08(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnim(sprite, sSlotMachine->unk0A - 1);
        sprite->data[0]++;
        // fallthrough
    case 1:
        if (++sprite->data[1] >= 4)
        {
            sprite->data[0]++;
            sprite->data[1] = 0;
        }
        break;
    case 2:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0xd0)
        {
            sprite->pos1.x = 0xd0;
            sprite->data[0]++;
        }
        break;
    case 3:
        if (++sprite->data[1] > 90)
            sprite->data[0]++;
        break;
    case 4:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0xf8)
            sprite->data[0]++;
        break;
    case 5:
        sprite->data[7] = 0;
        break;
    }
}

/*static */void sub_8105EB4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->animPaused = TRUE;
        sprite->data[0]++;
        // fallthrough
    case 1:
        sprite->pos1.y += 8;
        if (sprite->pos1.y >= 0x70)
        {
            sprite->pos1.y = 0x70;
            sprite->data[1] = 16;
            sprite->data[0]++;
        }
        break;
    case 2:
        if (sprite->data[2] == 0)
        {
            sprite->pos1.y -= sprite->data[1];
            sprite->data[1] = -sprite->data[1];
            if (++sprite->data[3] >= 2)
            {
                sprite->data[1] >>= 2;
                sprite->data[3] = 0;
                if (sprite->data[1] == 0)
                {
                    sprite->data[0]++;
                    sprite->data[7] = 0;
                    sprite->animPaused = FALSE;
                }
            }
        }
        sprite->data[2]++;
        sprite->data[2] &= 0x07;
        break;
    }
}

/*static */void sub_8105F54(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 8)
            sprite->data[0]++;
        break;
    case 1:
        sprite->pos1.y += 2;
        if (sprite->pos1.y >= 0x30)
        {
            sprite->pos1.y = 0x30;
            sprite->data[0]++;
            sprite->data[7] = 0;
        }
        break;
    }
}

/*static */void sub_8105F9C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->invisible = TRUE;
        if (++sprite->data[1] > 0x20)
        {
            sprite->data[0]++;
            sprite->data[1] = 5;
            sprite->oam.mosaic = TRUE;
            sprite->invisible = FALSE;
            StartSpriteAnim(sprite, 1);
            SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->data[1] << 4) | sprite->data[1]) << 8);
        }
        break;
    case 1:
        sprite->data[1] -= (sprite->data[2] >> 8);
        if (sprite->data[1] < 0)
            sprite->data[1] = 0;
        SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->data[1] << 4) | sprite->data[1]) << 8);
        sprite->data[2] &= 0xff;
        sprite->data[2] += 0x80;
        if (sprite->data[1] == 0)
        {
            sprite->data[0]++;
            sprite->data[7] = 0;
            sprite->oam.mosaic = FALSE;
            StartSpriteAnim(sprite, 0);
        }
        break;
    }
}

/*static */void sub_8106058(struct Sprite *sprite)
{
    if (sprite->data[1] < 3)
    {
        LoadPalette(gUnknown_083EDE10[sprite->data[1]], (IndexOfSpritePaletteTag(6) << 4) + 0x100, 0x20);
        if (++sprite->data[2] >= 4)
        {
            sprite->data[1]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        LoadPalette(gUnknown_083EDE10[sprite->data[1]], (IndexOfSpritePaletteTag(6) << 4) + 0x100, 0x20);
        if (++sprite->data[2] >= 25)
        {
            sprite->data[1] = 0;
            sprite->data[2] = 0;
        }
    }
    StartSpriteAnimIfDifferent(sprite, 1);
    sprite->data[7] = 0;
}

/*static */void sub_81060FC(struct Sprite *sprite)
{
    s16 sp00[] = {0, -40, 0, 0, 48, 0, 24, 0};
    s16 sp10[] = {-32, 0, -32, -48, 0, -48, 0, -48};
    s16 sp20[] = {16, 12, 16, 0, 0, 4, 8, 8};

    switch (sprite->data[0])
    {
    case 0:
        sprite->pos2.x = sp00[sprite->data[6]];
        sprite->pos2.y = sp10[sprite->data[6]];
        sprite->data[1] = sp20[sprite->data[6]];
        sprite->data[0]++;
        // fallthrough
    case 1:
        if (sprite->data[1]-- == 0)
            sprite->data[0]++;
        break;
    case 2:
        if (sprite->pos2.x > 0)
            sprite->pos2.x -= 4;
        else if (sprite->pos2.x < 0)
            sprite->pos2.x += 4;

        if (sprite->pos2.y > 0)
            sprite->pos2.y -= 4;
        else if (sprite->pos2.y < 0)
            sprite->pos2.y += 4;

        if (sprite->pos2.x == 0 && sprite->pos2.y == 0)
            sprite->data[0]++;
        break;
    }
}

/*static */void sub_81061C8(struct Sprite *sprite)
{
    s16 sp0[] = {160, 192, 224, 104, 80, 64, 48, 24};

    if (sprite->data[0] == 0)
    {
        sprite->data[0]++;
        sprite->data[1] = 12;
    }
    sprite->pos2.x = Cos(sp0[sprite->data[6]], sprite->data[1]);
    sprite->pos2.y = Sin(sp0[sprite->data[6]], sprite->data[1]);
    if (sprite->data[1] != 0)
        sprite->data[1]--;
}

/*static */void sub_8106230(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
        case 0:
            sSlotMachine->winIn = 0x2f;
            sSlotMachine->winOut = 0x3f;
            sSlotMachine->win0v = 0x2088;
            sprite->invisible = TRUE;
            sprite->data[0]++;
            // fallthrough
        case 1:
            sprite->data[1] += 2;
            sprite->data[2] = sprite->data[1] + 0xb0;
            sprite->data[3] = 0xf0 - sprite->data[1];
            if (sprite->data[2] > 0xd0)
                sprite->data[2] = 0xd0;
            if (sprite->data[3] < 0xd0)
                sprite->data[3] = 0xd0;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->data[1] > 0x33)
            {
                sprite->data[0]++;
                sSlotMachine->winIn = 0x3f;
            }
            break;
        case 2:
            if (sSlotMachine->bet == 0)
                break;
            sub_8104D30(5, SpriteCallbackDummy, 0xd0, 0x74, 0);
            sSlotMachine->win0h = 0xc0e0;
            sSlotMachine->win0v = 0x6880;
            sSlotMachine->winIn = 0x2f;
            sprite->data[0]++;
            sprite->data[1] = 0;
            // fallthrough
        case 3:
            sprite->data[1] += 2;
            sprite->data[2] = sprite->data[1] + 0xc0;
            sprite->data[3] = 0xe0 - sprite->data[1];
            if (sprite->data[2] > 0xd0)
                sprite->data[2] = 0xd0;
            if (sprite->data[3] < 0xd0)
                sprite->data[3] = 0xd0;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->data[1] > 0x0f)
            {
                sprite->data[0]++;
                sSlotMachine->winIn = 0x3f;
            }
            break;
    }
}

/*static */void nullsub_70(void)
{
}

/*static */void sub_8106364(void)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
}

/*static */void sub_8106370(void)
{
    LoadPalette(gUnknown_083EDE20, (IndexOfSpritePaletteTag(6) << 4) + 0x100, 0x20);
}

/*static */void sub_810639C(void)
{
    sSlotMachine->win0h = 0xf0;
    sSlotMachine->win0v = 0xa0;
    sSlotMachine->winIn = 0x3f;
    sSlotMachine->winOut = 0x3f;
}

/*static */void sub_81063C0(void)
{
    u8 i;

    sub_8106404();
    gUnknown_0203AAD4 = Alloc(0x3200);
    LZDecompressWram(gSlotMachineReelTime_Gfx, gUnknown_0203AAD4);
    gUnknown_0203AAD8 = Alloc(0x3600);
    LZDecompressWram(sReelTimeGfx, gUnknown_0203AAD8);
    gUnknown_0203AB30 = AllocZeroed(sizeof(struct SpriteSheet) * 22);
    for (i = 0; i < 22; i++)
    {
        gUnknown_0203AB30[i].data = sSlotMachineSpriteSheets[i].data;
        gUnknown_0203AB30[i].size = sSlotMachineSpriteSheets[i].size;
        gUnknown_0203AB30[i].tag = sSlotMachineSpriteSheets[i].tag;
    }
    gUnknown_0203AB30[17].data = gUnknown_0203AAD4 + 0xA00;
    gUnknown_0203AB30[18].data = gUnknown_0203AAD4 + 0x1400;
    gUnknown_0203AB30[19].data = gUnknown_0203AAD4 + 0x1600;
    gUnknown_0203AB30[20].data = gUnknown_0203AAD4 + 0x1900;
    LoadSpriteSheets(gUnknown_0203AB30);
    LoadSpritePalettes(gSlotMachineSpritePalettes);
}

/*static */void sub_8106404(void)
{
    u8 *dest;
    u8 i, j;

    gUnknown_0203AB2C = AllocZeroed(sizeof(struct SpriteSheet));
    gUnknown_0203AAE0 = AllocZeroed(0x2000);
    dest = gUnknown_0203AAE0;
    for (i = 0; i < 0x40; i++)
    {
        for (j = 0; j < 0x20; j++, dest++)
            *dest = gUnknown_083EDCDC[j];
    }
    gUnknown_0203AB2C->data = gUnknown_0203AAE0;
    gUnknown_0203AB2C->size = 0x800;
    gUnknown_0203AB2C->tag  = 0x11;
    LoadSpriteSheet(gUnknown_0203AB2C);
}

extern const u32 gSlotMachineMenu_Gfx[];
extern const u16 gSlotMachineMenu_Tilemap[];
extern const u16 gUnknown_08DCEC70[];
extern const u16 gSlotMachineMenu_Pal[];

/*static */void sub_8106448(void)
{
    gUnknown_0203AAC8 = Alloc(0x2200);
    LZDecompressWram(gSlotMachineMenu_Gfx, gUnknown_0203AAC8);
    LoadBgTiles(2, gUnknown_0203AAC8, 0x2200, 0);
    LoadPalette(gSlotMachineMenu_Pal, 0, 160);
    LoadPalette(gPalette_83EDE24, 208, 32);
}

/*static */void sub_81064B8(void)
{
    sub_812F968();
    LoadSlotMachineWheelOverlay();
}

/*static */void sub_812F968(void)
{
    LoadBgTilemap(2, gSlotMachineMenu_Tilemap, 0x500, 0);
}

/*static */void LoadSlotMachineWheelOverlay(void)
{
    s16 x, y, dx;

    for (x = 4; x < 18; x += 5)
    {
        for (dx = 0; dx < 4; dx++)
        {
            LoadBgTilemap(3, gUnknown_0203AAD0,     2, x + dx + 5  * 32);
            LoadBgTilemap(3, gUnknown_0203AAD0 + 1, 2, x + dx + 13 * 32);
            LoadBgTilemap(3, gUnknown_0203AAD0 + 2, 2, x + dx + 6  * 32);
            LoadBgTilemap(3, gUnknown_0203AAD0 + 3, 2, x + dx + 12 * 32);
        }

        LoadBgTilemap(3, gUnknown_0203AAD0 + 4, 2, x + 6 * 32);
        LoadBgTilemap(3, gUnknown_0203AAD0 + 5, 2, x + 12 * 32);

        for (y = 7; y <= 11; y++)
            LoadBgTilemap(3, gUnknown_0203AAD0 + 6, 2, x + y * 32);
    }
}

/*static */void sub_81065A8(s16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4)
{
    gUnknown_0203AADC[0] = arg1;
    gUnknown_0203AADC[1] = arg2;
    gUnknown_0203AADC[2] = arg3;
    gUnknown_0203AADC[3] = arg4;

    LoadBgTilemap(2, gUnknown_0203AADC,     2, 15 * 32 + arg0);
    LoadBgTilemap(2, gUnknown_0203AADC + 1, 2, 15 * 32 + 1 + arg0);
    LoadBgTilemap(2, gUnknown_0203AADC + 2, 2, 16 * 32 + arg0);
    LoadBgTilemap(2, gUnknown_0203AADC + 3, 2, 16 * 32 + 1 + arg0);
}

/*static */void sub_81065DC(void)
{
    LoadBgTilemap(2, gUnknown_08DCEC70, 0x500, 0);
    HideBg(3);
}

/*static */void SlotMachineSetup_9_0(void)
{
    gUnknown_03001188[0]  = gUnknown_0203AAF4;
    gUnknown_03001188[1]  = gUnknown_0203AAF8;
    gUnknown_03001188[2]  = gUnknown_0203AAFC;
    gUnknown_03001188[3]  = gUnknown_0203AB04;
    gUnknown_03001188[4]  = gUnknown_0203AB08;
    gUnknown_03001188[5]  = gUnknown_0203AB18;
    gUnknown_03001188[6]  = gUnknown_0203AB1C;
    gUnknown_03001188[7]  = gUnknown_0203AB20;
    gUnknown_03001188[8]  = gUnknown_0203AB24;
    gUnknown_03001188[9]  = gUnknown_0203AB28;
    gUnknown_03001188[10] = gUnknown_0203AB00;
    gUnknown_03001188[11] = gUnknown_0203AB00;
    gUnknown_03001188[12] = gUnknown_0203AB00;
    gUnknown_03001188[13] = gUnknown_0203AB00;
    gUnknown_03001188[14] = gUnknown_0203AB0C;
    gUnknown_03001188[15] = gUnknown_0203AB0C;
    gUnknown_03001188[16] = gUnknown_0203AB0C;
    gUnknown_03001188[17] = gUnknown_0203AB0C;
    gUnknown_03001188[18] = gUnknown_0203AB0C;
    gUnknown_03001188[19] = gUnknown_0203AB10;
    gUnknown_03001188[20] = gUnknown_0203AB10;
    gUnknown_03001188[21] = gUnknown_0203AB10;
    gUnknown_03001188[22] = gUnknown_0203AB14;
    gUnknown_03001188[23] = gUnknown_0203AB14;
    gUnknown_03001188[24] = gUnknown_0203AB14;
    gUnknown_03001188[25] = NULL;
}

/*static */void SlotMachineSetup_8_0(void)
{
    gUnknown_0203AAF4 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AAF4[0].data = gUnknown_0203AAD4;
    gUnknown_0203AAF4[0].size = 0x600;

    gUnknown_0203AAF8 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AAF8[0].data = gUnknown_0203AAD4 + 0x600;
    gUnknown_0203AAF8[0].size = 0x200;

    gUnknown_0203AAFC = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AAFC[0].data = gUnknown_0203AAD4 + 0x800;
    gUnknown_0203AAFC[0].size = 0x200;

    gUnknown_0203AB00 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB00[0].data = gUnknown_0203AAD4 + 0xA00;
    gUnknown_0203AB00[0].size = 0x200;

    gUnknown_0203AB04 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB04[0].data = gUnknown_0203AAD4 + 0xC00;
    gUnknown_0203AB04[0].size = 0x300;

    gUnknown_0203AB08 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB08[0].data = gUnknown_0203AAD4 + 0x1000;
    gUnknown_0203AB08[0].size = 0x400;

    gUnknown_0203AB0C = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB0C[0].data = gUnknown_0203AAD4 + 0x1400;
    gUnknown_0203AB0C[0].size = 0x200;

    gUnknown_0203AB10 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB10[0].data = gUnknown_0203AAD4 + 0x1600;
    gUnknown_0203AB10[0].size = 0x300;

    gUnknown_0203AB14 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB14[0].data = gUnknown_0203AAD4 + 0x1900;
    gUnknown_0203AB14[0].size = 0x300;

    gUnknown_0203AB18 = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    gUnknown_0203AB18[0].data = gUnknown_0203AAD4 + 0x1C00;
    gUnknown_0203AB18[0].size = 0x200;
    gUnknown_0203AB18[1].data = gUnknown_0203AAD4 + 0x1E00;
    gUnknown_0203AB18[1].size = 0x200;

    gUnknown_0203AB1C = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    gUnknown_0203AB1C[0].data = gUnknown_0203AAD4 + 0x2000;
    gUnknown_0203AB1C[0].size = 640;

    gUnknown_0203AB20 = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);
    gUnknown_0203AB20[0].data = gUnknown_0203AAD4 + 0x2280;
    gUnknown_0203AB20[0].size = 0x80;
    gUnknown_0203AB20[1].data = gUnknown_0203AAD4 + 0x2300;
    gUnknown_0203AB20[1].size = 0x80;
    gUnknown_0203AB20[2].data = gUnknown_0203AAD4 + 0x2380;
    gUnknown_0203AB20[2].size = 0x80;
    gUnknown_0203AB20[3].data = gUnknown_0203AAD4 + 0x2400;
    gUnknown_0203AB20[3].size = 0x80;
    gUnknown_0203AB20[4].data = gUnknown_0203AAD4 + 0x2480;
    gUnknown_0203AB20[4].size = 0x80;

    gUnknown_0203AB24 = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    gUnknown_0203AB24[0].data = gUnknown_0203AAD4 + 0x2600;
    gUnknown_0203AB24[0].size = 0x480;
    gUnknown_0203AB24[1].data = gUnknown_0203AAD4 + 10880;
    gUnknown_0203AB24[1].size = 0x480;

    gUnknown_0203AB28 = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    gUnknown_0203AB28[0].data = gUnknown_0203AAD4 + 0x2F00;
    gUnknown_0203AB28[0].size = 0x180;
    gUnknown_0203AB28[1].data = gUnknown_0203AAD4 + 0x3080;
    gUnknown_0203AB28[1].size = 0x180;
}

const u8 sReelSymbols[][21] =
{
    {
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY
    },
    {
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_CHERRY
    },
    {
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_CHERRY
    },
};

const u8 gUnknown_083ECCF1[] = {
    1, 0, 5, 4, 3, 2
};

const s16 gUnknown_083ECCF8[][2] = {
    {0,  6},
    {0, 10},
    {0,  2}
};

const u8 gUnknown_083ECD04[][3] = {
    {1, 1, 12},
    {1, 1, 14},
    {2, 2, 14},
    {2, 2, 14},
    {2, 3, 16},
    {3, 3, 16}
};

const u8 gUnknown_083ECD16[][6] = {
    {25, 25, 30, 40, 40, 50},
    {25, 25, 30, 30, 35, 35},
    {25, 25, 30, 25, 25, 30}
};

const u8 gUnknown_083ECD28[][6] = {
    {20, 25, 25, 20, 25, 25},
    {12, 15, 15, 18, 19, 22},
    {25, 25, 25, 30, 30, 40},
    {25, 25, 20, 20, 15, 15},
    {40, 40, 35, 35, 40, 40}
};

const u8 gUnknown_083ECD46[][17] = {
    {243, 243, 243,  80,  80,  80,  80,  40,  40,  40,  40,  40,  40,   5,   5,   5,   5},
    {  5,   5,   5, 150, 150, 150, 150, 130, 130, 130, 130, 130, 130, 100, 100, 100,   5},
    {  4,   4,   4,  20,  20,  20,  20,  80,  80,  80,  80,  80,  80, 100, 100, 100,  40},
    {  2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,  45,  45,  45, 100},
    {  1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   5,   5,   5, 100},
    {  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   6}
};

const u8 gUnknown_083ECDAC[][17] = {
    { 243, 243, 243, 200, 200, 200, 200, 160, 160, 160, 160, 160, 160,  70,  70,  70,   5},
    {   5,   5,   5,  25,  25,  25,  25,   5,   5,   5,   5,   5,   5,   2,   2,   2,   6},
    {   4,   4,   4,  25,  25,  25,  25,  30,  30,  30,  30,  30,  30,  40,  40,  40,  35},
    {   2,   2,   2,   3,   3,   3,   3,  30,  30,  30,  30,  30,  30, 100, 100, 100,  50},
    {   1,   1,   1,   2,   2,   2,   2,  30,  30,  30,  30,  30,  30,  40,  40,  40, 100},
    {   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   4,   4,  60}
};

const u16 gUnknown_083ECE12[] = {
    0x80, 0xaf, 0xc8, 0xe1, 0x100
};

const u16 gUnknown_083ECE1C[][2] = {
    {10,  5},
    {10, 10},
    {10, 15},
    {10, 25},
    {10, 35}
};

const u16 gUnknown_083ECE30[] = {
    0, 5, 10, 15, 20
};

const u8 gUnknown_083ECE3A[] = {
    6, 4, 3, 2, 5, 0, 0, 0
};

const u16 gUnknown_083ECE42[] = {
    0x80, 0x20, 0x40
};

const u16 gUnknown_083ECE48[] = {
    0x10, 0x08, 0x04, 0x02, 0x01
};

const u8 sSym2Match[] = {
    SLOT_MACHINE_MATCHED_777_RED,
    SLOT_MACHINE_MATCHED_777_BLUE,
    SLOT_MACHINE_MATCHED_AZURILL,
    SLOT_MACHINE_MATCHED_LOTAD,
    SLOT_MACHINE_MATCHED_1CHERRY,
    SLOT_MACHINE_MATCHED_POWER,
    SLOT_MACHINE_MATCHED_REPLAY
};

const u16 sSlotMatchFlags[] = {
    1 << SLOT_MACHINE_MATCHED_1CHERRY,
    1 << SLOT_MACHINE_MATCHED_2CHERRY,
    1 << SLOT_MACHINE_MATCHED_REPLAY,
    1 << SLOT_MACHINE_MATCHED_LOTAD,
    1 << SLOT_MACHINE_MATCHED_AZURILL,
    1 << SLOT_MACHINE_MATCHED_POWER,
    1 << SLOT_MACHINE_MATCHED_777_MIXED,
    1 << SLOT_MACHINE_MATCHED_777_RED,
    1 << SLOT_MACHINE_MATCHED_777_BLUE
};

const u16 sSlotPayouts[] = {
    2, 4, 0, 6, 12, 3, 90, 300, 300
};

const s16 gUnknown_083ECE7E[][2] = {
    { 0xd0, 0x38},
    { 0xb8, 0x00},
    { 0xc8, 0x08},
    { 0xd8, 0x10},
    { 0xe8, 0x18},
    { 0xd0, 0x48},
    { 0xd0, 0x08},
    { 0xd0, 0x40},
    { 0xd0, 0x38},
    { 0xc0, 0x58},
    { 0xe0, 0x58},
    { 0xc0, 0x78},
    { 0xe0, 0x78},
    { 0x90, 0x38},
    {0x110, 0x58},
    { 0xa8, 0x70},
    { 0xd0, 0x54},
    { 0xd0, 0x70},
    { 0xbc, 0x34},
    { 0xd0, 0x34},
    { 0xe4, 0x34},
    { 0xb8, 0x48},
    { 0xc4, 0x48},
    { 0xd0, 0x48},
    { 0xdc, 0x48},
    { 0xe8, 0x48},
    { 0xbc, 0x34},
    { 0xd0, 0x34},
    { 0xe4, 0x34},
    { 0xb8, 0x48},
    { 0xc4, 0x48},
    { 0xd0, 0x48},
    { 0xdc, 0x48},
    { 0xe8, 0x48},
    { 0x00, 0x00}
};

const SpriteCallback gUnknown_083ECF0C[] = {
    sub_8105C64,
    sub_8105F54,
    sub_8105F54,
    sub_8105F54,
    sub_8105F54,
    sub_8105F9C,
    sub_8105EB4,
    sub_8105C64,
    sub_8105C64,
    sub_8105C6C,
    sub_8105CF0,
    sub_8105D08,
    sub_8105D20,
    sub_8105D3C,
    sub_8105DA4,
    sub_8105E08,
    sub_8105C64,
    sub_8106058,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_8106230
};

const struct UnkStruct1 Unknown_83ECF98[] = {
    {25, 34, 0},
    {2, 0, 0},
    {9, 16, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFA8[] = {
    {10, 1, 0},
    {11, 2, 0},
    {12, 3, 0},
    {13, 4, 0},
    {5, 5, 0},
    {8, 6, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFC4[] = {
    {3, 7, 0},
    {8, 17, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFD0[] = {
    {4, 8, 0},
    {6, 9, 0},
    {6, 10, 1},
    {6, 11, 2},
    {6, 12, 3},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFE8[] = {
    {0, 13, 0},
    {1, 14, 0},
    {7, 15, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFF8[] = {
    {19, 26, 0},
    {20, 27, 1},
    {21, 28, 2},
    {14, 29, 3},
    {15, 30, 4},
    {16, 31, 5},
    {17, 32, 6},
    {18, 33, 7},
    {8, 17, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ED020[] = {
    {22, 18, 0},
    {23, 19, 1},
    {24, 20, 2},
    {14, 21, 3},
    {15, 22, 4},
    {16, 23, 5},
    {17, 24, 6},
    {18, 25, 7},
    {8, 17, 0},
    {255, 0, 0}
};

const struct UnkStruct1 *const gUnknown_083ED048[] = {
    Unknown_83ECF98,
    Unknown_83ECFA8,
    Unknown_83ECFC4,
    Unknown_83ECFD0,
    Unknown_83ECFE8,
    Unknown_83ED020,
    Unknown_83ECFF8
};

void (*const gUnknown_083ED064[])(void) = {
    sub_810639C,
    sub_8106364,
    sub_8106370,
    nullsub_70,
    nullsub_70,
    sub_8106370,
    sub_8106370
};
