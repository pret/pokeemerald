
// Includes
#include "global.h"
#include "gpu_regs.h"
#include "multiboot.h"
#include "malloc.h"
#include "bg.h"
#include "main.h"
#include "sprite.h"
#include "task.h"
#include "unknown_task.h"
#include "window.h"
#include "menu.h"
#include "m4a.h"

// Static type declarations

typedef struct {
    u8 state;
    u8 unk1;
    u16 unk2;
    struct MultiBootParam mb;
} berryfix_t;

// Static RAM declarations

extern berryfix_t *gUnknown_030012B8;

// Static ROM declarations

static void sub_81BF3DC(void);
static void sub_81BF5A4(void);
static int sub_81BF7A4(int);
static void sub_81BF7E8(int);
static void sub_81BF8D8(void);

// .rodata

const u8 gUnknown_08617E78[] = _("Berry Program Update");
const u8 gUnknown_08617E8D[] = _("Ruby/Sapphire");
const u8 gUnknown_08617E9B[] = _("Emerald");

const u8 Unknown_08617EA3[] = _("The Berry Program on your POKéMON\nRuby/Sapphire Game Pak will be updated.\n{COLOR RED}{SHADOW LIGHT_RED}Press the A Button.");
const u8 Unknown_08617F07[] = _("Please ensure the connection of your\nGame Boy Advance system matches this.\n{COLOR RED}{SHADOW LIGHT_RED}YES: Press the A Button.\nNO: Turn off the power and try again.");
const u8 Unknown_08617F97[] = _("Please turn on the power of POKéMON\nRuby/Sapphire while holding START and\nSELECT simultaneously. Then, ensure\nthe picture above appears.");
const u8 Unknown_08618020[] = _("Transmitting. Please wait.\n{COLOR RED}{SHADOW LIGHT_RED}Please do not turn off the power or\nunplug the Game Boy Advance Game\nLink Cable.");
const u8 Unknown_08618092[] = _("Please follow the instructions on your\nPOKéMON Ruby/Sapphire screen.");
const u8 Unknown_086180D7[] = _("Transmission failure.\n{COLOR RED}{SHADOW LIGHT_RED}Please try again.");

const struct BgTemplate gUnknown_08618108[] = {
    {
        0, 0, 30, 0, 0, 0
    }, {
        1, 1, 31, 0, 0, 1
    }
};

const struct WindowTemplate gUnknown_08618110[] = {
    {0, 2,  4, 26, 2, 15, 0x001},
    {0, 1, 11, 28, 8, 15, 0x035},
    {0, 0,  8, 30, 2, 15, 0x115},
    {0, 8,  0, 14, 2, 15, 0x151},
    {-1}
};

const u16 gUnknown_08618138[] = {
    0x7fff, 0x7fff, 0x318c, 0x675a,
    0x043c, 0x3aff, 0x0664, 0x4bd2,
    0x6546, 0x7b14, 0x7fff, 0x318c,
    0x675a, 0x0000, 0x0000, 0x0000
};

const u8 gUnknown_08618158[] = {10, 11, 12};
const u8 gUnknown_0861815B[] = { 0, 10, 13};

const u8 *const gUnknown_08618160[] = {
    Unknown_08617F07,
    Unknown_08617F97,
    Unknown_08618020,
    Unknown_08618092,
    Unknown_086180D7,
    Unknown_08617EA3
};

extern const u8 gUnknown_08DD87C0[];
extern const u8 gUnknown_08DD8EE0[];
extern const u8 gUnknown_08DD8780[];
extern const u8 gUnknown_08DD90E0[];
extern const u8 gUnknown_08DD9718[];
extern const u8 gUnknown_08DD9080[];
extern const u8 gUnknown_08DD98B4[];
extern const u8 gUnknown_08DD9E58[];
extern const u8 gUnknown_08DD9874[];
extern const u8 gUnknown_08DDA02C[];
extern const u8 gUnknown_08DDA63C[];
extern const u8 gUnknown_08DD9FEC[];
extern const u8 gUnknown_08DDA840[];
extern const u8 gUnknown_08DDAE40[];
extern const u8 gUnknown_08DDA800[];
extern const u8 gUnknown_08DDB020[];
extern const u8 gUnknown_08DDB2C4[];
extern const u8 gUnknown_08DDAFE0[];

const u8 *const gUnknown_08618178[][3] = {
    {
        gUnknown_08DD87C0,
        gUnknown_08DD8EE0,
        gUnknown_08DD8780
    }, {
        gUnknown_08DD90E0,
        gUnknown_08DD9718,
        gUnknown_08DD9080
    }, {
        gUnknown_08DD98B4,
        gUnknown_08DD9E58,
        gUnknown_08DD9874
    }, {
        gUnknown_08DDA02C,
        gUnknown_08DDA63C,
        gUnknown_08DD9FEC
    }, {
        gUnknown_08DDA840,
        gUnknown_08DDAE40,
        gUnknown_08DDA800
    }, {
        gUnknown_08DDB020,
        gUnknown_08DDB2C4,
        gUnknown_08DDAFE0
    },
};

extern const u8 gUnknown_089A6550[0xC0];
extern const u8 gMultiBootProgram_BerryGlitchFix_Script[0x3b34];
extern const u8 gMultiBootProgram_BerryGlitchFix_Start[];
extern const u8 gMultiBootProgram_BerryGlitchFix_End[];

// .text

void sub_81BF384(void)
{
    DisableInterrupts(0xFFFF);
    EnableInterrupts(0x0001);
    m4aSoundVSyncOff();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    ResetTasks();
    remove_some_task();
    SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
    gUnknown_030012B8 = AllocZeroed(0x50);
    gUnknown_030012B8->state = 0;
    gUnknown_030012B8->unk1 = 6;
    SetMainCallback2(sub_81BF3DC);
}

static void sub_81BF3DC(void)
{
    switch (gUnknown_030012B8->state)
    {
        case 0:
            sub_81BF5A4();
            gUnknown_030012B8->state = 1;
            break;
        case 1:
            if (sub_81BF7A4(5) == 5 && (gMain.newKeys & A_BUTTON))
            {
                gUnknown_030012B8->state = 2;
            }
            break;
        case 2:
            if (sub_81BF7A4(0) == 0 && (gMain.newKeys & A_BUTTON))
            {
                gUnknown_030012B8->state = 3;
            }
            break;
        case 3:
            if (sub_81BF7A4(1) == 1)
            {
                gUnknown_030012B8->mb.masterp = gUnknown_089A6550;
                gUnknown_030012B8->mb.server_type = 0;
                MultiBootInit(&gUnknown_030012B8->mb);
                gUnknown_030012B8->unk2 = 0;
                gUnknown_030012B8->state = 4;
            }
            break;
        case 4:
            MultiBootMain(&gUnknown_030012B8->mb);
            if (gUnknown_030012B8->mb.probe_count != 0 || (!(gUnknown_030012B8->mb.response_bit & 2) || !(gUnknown_030012B8->mb.client_bit & 2)))
            {
                gUnknown_030012B8->unk2 = 0;
            }
            else if (++ gUnknown_030012B8->unk2 > 180)
            {
                MultiBootStartMaster(&gUnknown_030012B8->mb, gMultiBootProgram_BerryGlitchFix_Start, (u32)(gMultiBootProgram_BerryGlitchFix_End - gMultiBootProgram_BerryGlitchFix_Start), 4, 1);
                gUnknown_030012B8->state = 5;
            }
            break;
        case 5:
            if (sub_81BF7A4(2) == 2) {
                MultiBootMain(&gUnknown_030012B8->mb);
                if (MultiBootCheckComplete(&gUnknown_030012B8->mb)) {
                    gUnknown_030012B8->state = 6;
                }
                else if (!(gUnknown_030012B8->mb.client_bit & 2)) {
                    gUnknown_030012B8->state = 7;
                }
            }
            break;
        case 6:
            if (sub_81BF7A4(3) == 3 && gMain.newKeys & A_BUTTON)
            {
                DoSoftReset();
            }
            break;
        case 7:
            if (sub_81BF7A4(4) == 4 && gMain.newKeys & A_BUTTON)
            {
                gUnknown_030012B8->state = 1;
            }
            break;
    }
}

#ifdef NONMATCHING
static void sub_81BF5A4(void)
{
    s32 width;

    SetGpuReg(REG_OFFSET_BG0CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG1CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0x0000);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0x0000);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0x0000);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0x0000);
    SetGpuReg(REG_OFFSET_BLDCNT, 0x0000);

    DmaFill32(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill32(3, 0, PLTT, PLTT_SIZE);
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, gUnknown_08618108, ARRAY_COUNT(gUnknown_08618108));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    InitWindows(gUnknown_08618110);
    DeactivateAllTextPrinters();

    DmaCopy32(3, gUnknown_08618138, BG_PLTT + 0x1E0, 0x20);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    FillWindowPixelBuffer(2, 0);
    FillWindowPixelBuffer(3, 0);
    FillWindowPixelBuffer(0, 0xAA);

// This block is a meme among memes
    width = (0x78 - GetStringWidth(0, gUnknown_08617E9B, 0)) / 2;
    box_print(2, 0, width, 3, gUnknown_0861815B, -1, gUnknown_08617E9B);
    width = (s32)(0x78 - GetStringWidth(0, gUnknown_08617E9B, 0)) / 2 + 0x78;
    box_print(2, 0, width, 3, gUnknown_0861815B, -1, gUnknown_08617E8D);
    width = (0x70 - GetStringWidth(0, gUnknown_08617E8D, 0)) / 2;
    box_print(3, 0, width, 0, gUnknown_0861815B, -1, gUnknown_08617E8D);
    width = (0xd0 - GetStringWidth(1, gUnknown_08617E78, 0)) / 2;
    box_print(0, 1, width, 2, gUnknown_08618158, -1, gUnknown_08617E78);

    CopyWindowToVram(2, 2);
    CopyWindowToVram(3, 2);
    CopyWindowToVram(0, 2);
}

#else
__attribute__((naked)) static void sub_81BF5A4(void)
{
    asm(".syntax unified\n"
        "\tpush {r4-r6,lr}\n"
        "\tmov r6, r8\n"
        "\tpush {r6}\n"
        "\tsub sp, 0x10\n"
        "\tmovs r0, 0x8\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0xA\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0x10\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0x12\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0x14\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0x16\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0x50\n"
        "\tmovs r1, 0\n"
        "\tbl SetGpuReg\n"
        "\tmovs r1, 0\n"
        "\tstr r1, [sp, 0xC]\n"
        "\tldr r4, =0x040000d4\n"
        "\tadd r0, sp, 0xC\n"
        "\tstr r0, [r4]\n"
        "\tmovs r0, 0xC0\n"
        "\tlsls r0, 19\n"
        "\tstr r0, [r4, 0x4]\n"
        "\tldr r0, =0x85006000\n"
        "\tstr r0, [r4, 0x8]\n"
        "\tldr r0, [r4, 0x8]\n"
        "\tstr r1, [sp, 0xC]\n"
        "\tadd r0, sp, 0xC\n"
        "\tstr r0, [r4]\n"
        "\tmovs r0, 0xE0\n"
        "\tlsls r0, 19\n"
        "\tstr r0, [r4, 0x4]\n"
        "\tldr r2, =0x85000100\n"
        "\tstr r2, [r4, 0x8]\n"
        "\tldr r0, [r4, 0x8]\n"
        "\tstr r1, [sp, 0xC]\n"
        "\tadd r0, sp, 0xC\n"
        "\tstr r0, [r4]\n"
        "\tmovs r0, 0xA0\n"
        "\tlsls r0, 19\n"
        "\tstr r0, [r4, 0x4]\n"
        "\tstr r2, [r4, 0x8]\n"
        "\tldr r0, [r4, 0x8]\n"
        "\tmovs r0, 0\n"
        "\tbl ResetBgsAndClearDma3BusyFlags\n"
        "\tldr r1, =gUnknown_08618108\n"
        "\tmovs r0, 0\n"
        "\tmovs r2, 0x2\n"
        "\tbl InitBgsFromTemplates\n"
        "\tmovs r0, 0\n"
        "\tmovs r1, 0\n"
        "\tmovs r2, 0\n"
        "\tbl ChangeBgX\n"
        "\tmovs r0, 0\n"
        "\tmovs r1, 0\n"
        "\tmovs r2, 0\n"
        "\tbl ChangeBgY\n"
        "\tmovs r0, 0x1\n"
        "\tmovs r1, 0\n"
        "\tmovs r2, 0\n"
        "\tbl ChangeBgX\n"
        "\tmovs r0, 0x1\n"
        "\tmovs r1, 0\n"
        "\tmovs r2, 0\n"
        "\tbl ChangeBgY\n"
        "\tldr r0, =gUnknown_08618110\n"
        "\tbl InitWindows\n"
        "\tbl DeactivateAllTextPrinters\n"
        "\tldr r0, =gUnknown_08618138\n"
        "\tstr r0, [r4]\n"
        "\tldr r0, =0x050001e0\n"
        "\tstr r0, [r4, 0x4]\n"
        "\tldr r0, =0x84000008\n"
        "\tstr r0, [r4, 0x8]\n"
        "\tldr r0, [r4, 0x8]\n"
        "\tmovs r0, 0\n"
        "\tmovs r1, 0x40\n"
        "\tbl SetGpuReg\n"
        "\tmovs r0, 0x2\n"
        "\tmovs r1, 0\n"
        "\tbl FillWindowPixelBuffer\n"
        "\tmovs r0, 0x3\n"
        "\tmovs r1, 0\n"
        "\tbl FillWindowPixelBuffer\n"
        "\tmovs r0, 0\n"
        "\tmovs r1, 0xAA\n"
        "\tbl FillWindowPixelBuffer\n"
        "\tldr r5, =gUnknown_08617E9B\n"
        "\tmovs r0, 0\n"
        "\tadds r1, r5, 0\n"
        "\tmovs r2, 0\n"
        "\tbl GetStringWidth\n"
        "\tadds r1, r0, 0\n"
        "\tmovs r4, 0x78\n"
        "\tsubs r0, r4, r1\n"
        "\tlsrs r1, r0, 31\n"
        "\tadds r0, r1\n"
        "\tasrs r0, 1\n"
        "\tlsls r2, r0, 24\n"
        "\tlsrs r2, 24\n"
        "\tldr r6, =gUnknown_0861815B\n"
        "\tstr r6, [sp]\n"
        "\tmovs r0, 0x1\n"
        "\tnegs r0, r0\n"
        "\tmov r8, r0\n"
        "\tstr r0, [sp, 0x4]\n"
        "\tstr r5, [sp, 0x8]\n"
        "\tmovs r0, 0x2\n"
        "\tmovs r1, 0\n"
        "\tmovs r3, 0x3\n"
        "\tbl box_print\n"
        "\tldr r5, =gUnknown_08617E8D\n"
        "\tmovs r0, 0\n"
        "\tadds r1, r5, 0\n"
        "\tmovs r2, 0\n"
        "\tbl GetStringWidth\n"
        "\tadds r1, r0, 0\n"
        "\tsubs r4, r1\n"
        "\tlsrs r0, r4, 31\n"
        "\tadds r4, r0\n"
        "\tasrs r4, 1\n"
        "\tadds r0, r4, 0\n"
        "\tadds r0, 0x78\n"
        "\tlsls r2, r0, 24\n"
        "\tlsrs r2, 24\n"
        "\tstr r6, [sp]\n"
        "\tmov r0, r8\n"
        "\tstr r0, [sp, 0x4]\n"
        "\tstr r5, [sp, 0x8]\n"
        "\tmovs r0, 0x2\n"
        "\tmovs r1, 0\n"
        "\tmovs r3, 0x3\n"
        "\tbl box_print\n"
        "\tmovs r0, 0\n"
        "\tadds r1, r5, 0\n"
        "\tmovs r2, 0\n"
        "\tbl GetStringWidth\n"
        "\tadds r1, r0, 0\n"
        "\tmovs r0, 0x70\n"
        "\tsubs r0, r1\n"
        "\tlsrs r1, r0, 31\n"
        "\tadds r0, r1\n"
        "\tasrs r0, 1\n"
        "\tlsls r2, r0, 24\n"
        "\tlsrs r2, 24\n"
        "\tstr r6, [sp]\n"
        "\tmov r0, r8\n"
        "\tstr r0, [sp, 0x4]\n"
        "\tstr r5, [sp, 0x8]\n"
        "\tmovs r0, 0x3\n"
        "\tmovs r1, 0\n"
        "\tmovs r3, 0\n"
        "\tbl box_print\n"
        "\tldr r4, =gUnknown_08617E78\n"
        "\tmovs r0, 0x1\n"
        "\tadds r1, r4, 0\n"
        "\tmovs r2, 0\n"
        "\tbl GetStringWidth\n"
        "\tadds r1, r0, 0\n"
        "\tmovs r0, 0xD0\n"
        "\tsubs r0, r1\n"
        "\tlsrs r1, r0, 31\n"
        "\tadds r0, r1\n"
        "\tasrs r0, 1\n"
        "\tlsls r2, r0, 24\n"
        "\tlsrs r2, 24\n"
        "\tldr r0, =gUnknown_08618158\n"
        "\tstr r0, [sp]\n"
        "\tmov r0, r8\n"
        "\tstr r0, [sp, 0x4]\n"
        "\tstr r4, [sp, 0x8]\n"
        "\tmovs r0, 0\n"
        "\tmovs r1, 0x1\n"
        "\tmovs r3, 0x2\n"
        "\tbl box_print\n"
        "\tmovs r0, 0x2\n"
        "\tmovs r1, 0x2\n"
        "\tbl CopyWindowToVram\n"
        "\tmovs r0, 0x3\n"
        "\tmovs r1, 0x2\n"
        "\tbl CopyWindowToVram\n"
        "\tmovs r0, 0\n"
        "\tmovs r1, 0x2\n"
        "\tbl CopyWindowToVram\n"
        "\tadd sp, 0x10\n"
        "\tpop {r3}\n"
        "\tmov r8, r3\n"
        "\tpop {r4-r6}\n"
        "\tpop {r0}\n"
        "\tbx r0\n"
        "\t.pool\n"
        ".syntax divided");
}
#endif

static int sub_81BF7A4(int checkval)
{
    if (gUnknown_030012B8->unk1 == checkval)
    {
        return checkval;
    }
    if (gUnknown_030012B8->unk1 == 6)
    {
        sub_81BF7E8(checkval);
        gUnknown_030012B8->unk1 = checkval;
    }
    else
    {
        sub_81BF8D8();
        gUnknown_030012B8->unk1 = 6;
    }
    return gUnknown_030012B8->unk1;
}

static void sub_81BF7E8(int scene)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    FillWindowPixelBuffer(1, 0xAA);
    box_print(1, 1, 0, 0, gUnknown_08618158, -1, gUnknown_08618160[scene]);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
    switch (scene)
    {
        case 0:
        case 2:
        case 3:
        case 4:
            PutWindowTilemap(2);
            break;
        case 1:
            PutWindowTilemap(3);
            break;
        case 5:
            PutWindowTilemap(0);
            break;
    }
    CopyBgTilemapBufferToVram(0);
    LZ77UnCompVram(gUnknown_08618178[scene][0], (void *)BG_CHAR_ADDR(1));
    LZ77UnCompVram(gUnknown_08618178[scene][1], (void *)BG_SCREEN_ADDR(31));
    CpuCopy32(gUnknown_08618178[scene][2], (void *)BG_PLTT, 0x100);
    ShowBg(0);
    ShowBg(1);
}

static void sub_81BF8D8()
{
    HideBg(0);
    HideBg(1);
}
