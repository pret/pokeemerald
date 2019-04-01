#include "global.h"
#include "battle.h"
#include "task.h"
#include "text.h"
#include "main.h"
#include "bg.h"
#include "palette.h"
#include "gpu_regs.h"
#include "alloc.h"
#include "menu.h"
#include "window.h"
#include "scanline_effect.h"
#include "m4a.h"
#include "dynamic_placeholder_text_util.h"
#include "overworld.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "sound.h"
#include "constants/songs.h"
#include "union_room.h"
#include "union_room_battle.h"

struct UnkStruct_3000DAC
{
    /*0x00*/ u32 unk00[4];
    /*0x10*/ u32 unk10[4];
    /*0x20*/ u32 unk20[16];
    /*0x60*/ u8 taskId;
    /*0x61*/ u8 unk61;
    /*0x62*/ u8 filler_62[10];
};

IWRAM_DATA struct UnkStruct_3000DAC * gUnknown_03000DAC;
IWRAM_DATA bool32 gUnknown_03000DB0;

void sub_801A43C(void);
void sub_801A6C0(u8 taskId);
static void sub_801A8B0(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 mode);
bool32 sub_801AA30(u32 * a0, u32 * a1, u32 * a2, u8 a3);

const u16 gWirelessInfoScreenPal[] = INCBIN_U16("graphics/interface/wireless_info_screen.gbapal");
const u32 gWirelessInfoScreenGfx[] = INCBIN_U32("graphics/interface/wireless_info_screen.4bpp.lz");
const u32 gWirelessInfoScreenTilemap[] = INCBIN_U32("graphics/interface/wireless_info_screen.bin.lz");

const struct BgTemplate gUnknown_082F0D34[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1F,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x08,
        .priority = 1
    }
};

const struct WindowTemplate gUnknown_082F0D3C[] = {
    {
        .bg = 0x00,
        .tilemapLeft = 0x03,
        .tilemapTop = 0x00,
        .width = 0x18,
        .height = 0x03,
        .paletteNum = 0x0f,
        .baseBlock = 0x0001
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x03,
        .tilemapTop = 0x04,
        .width = 0x15,
        .height = 0x0f,
        .paletteNum = 0x0f,
        .baseBlock = 0x0049
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x18,
        .tilemapTop = 0x04,
        .width = 0x03,
        .height = 0x0f,
        .paletteNum = 0x0f,
        .baseBlock = 0x0184
    },
    { 0xFF }
};

const u8 *const gUnknown_082F0D5C[] = {
    gText_WirelessCommStatus,
    gText_PeopleTrading,
    gText_PeopleBattling,
    gText_PeopleInUnionRoom,
    gText_PeopleCommunicating
};

const u8 gUnknown_082F0D70[][3] = {
    {0x01, 0x01, 0x02},
    {0x02, 0x01, 0x02},
    {0x03, 0x01, 0x04},
    {0x04, 0x00, 0x02},
    {0x06, 0x03, 0x02},
    {0x07, 0x03, 0x02},
    {0x09, 0x03, 0x00},
    {0x0a, 0x03, 0x00},
    {0x0b, 0x03, 0x00},
    {0x0c, 0xff, 0x00},
    {0x0d, 0x00, 0x00},
    {0x10, 0x03, 0x00},
    {0x0f, 0x03, 0x00},
    {0x40, 0x02, 0x01},
    {0x41, 0x02, 0x02},
    {0x44, 0x02, 0x02},
    {0x45, 0x02, 0x00},
    {0x48, 0x02, 0x02},
    {0x54, 0x02, 0x01},
    {0x53, 0x02, 0x02},
    {0x51, 0x02, 0x01},
    {0x52, 0x02, 0x01},
    {0x15, 0x03, 0x02},
    {0x16, 0x03, 0x02},
    {0x17, 0x03, 0x00},
    {0x18, 0x03, 0x00},
    {0x19, 0x03, 0x00},
    {0x1a, 0x03, 0x00},
    {0x1b, 0x03, 0x00},
    {0x1c, 0x01, 0x02},
    {0x0e, 0x01, 0x02}
};

void sub_801A3F4(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        RunTasks();
        RunTextPrinters();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
    }
}

void sub_801A418(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_801A42C(void)
{
    SetMainCallback2(sub_801A43C);
}

void sub_801A43C(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
    gUnknown_03000DAC = AllocZeroed(sizeof(struct UnkStruct_3000DAC));
    SetVBlankCallback(NULL);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_082F0D34, ARRAY_COUNT(gUnknown_082F0D34));
    SetBgTilemapBuffer(1, Alloc(0x800));
    SetBgTilemapBuffer(0, Alloc(0x800));
    DecompressAndLoadBgGfxUsingHeap(1, gWirelessInfoScreenGfx, 0, 0, 0);
    CopyToBgTilemapBuffer(1, gWirelessInfoScreenTilemap, 0, 0);
    InitWindows(gUnknown_082F0D3C);
    DeactivateAllTextPrinters();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
    ScanlineEffect_Stop();
    m4aSoundVSyncOn();
    SetVBlankCallback(sub_801A418);
    gUnknown_03000DAC->taskId = CreateTask(sub_801A6C0, 0);
    gUnknown_03000DAC->unk61 = sub_8013C40();
    gUnknown_03000DAC->unk10[3] = 1;
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    LoadPalette(gWirelessInfoScreenPal, 0x00, 0x20);
    Menu_LoadStdPalAt(0xF0);
    DynamicPlaceholderTextUtil_Reset();
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x0F);
    CopyBgTilemapBufferToVram(1);
    SetMainCallback2(sub_801A3F4);
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_801A584(void)
{
    s32 i;
    FreeAllWindowBuffers();
    for (i = 0; i < 2; i++)
    {
        Free(GetBgTilemapBuffer(i));
    }
    Free(gUnknown_03000DAC);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void sub_801A5BC(s16 * a0, s16 * a1)
{
    if (++(*a0) > 5)
    {
        if (++(*a1) == 14)
        {
            *a1 = 0;
        }
        *a0 = 0;
    }
    LoadPalette(gWirelessInfoScreenPal + 16 * (*a1 + 2), 0, 0x10);
}

void sub_801A600(void)
{
    s32 i;
    FillWindowPixelBuffer(0, 0);
    FillWindowPixelBuffer(1, 0);
    FillWindowPixelBuffer(2, 0);
    sub_801A8B0(0, 1, gUnknown_082F0D5C[0], GetStringCenterAlignXOffset(1, gUnknown_082F0D5C[0], 0xC0), 6, 3);
    for (i = 0; i < 3; i++)
    {
        sub_801A8B0(1, 1, gUnknown_082F0D5C[i + 1], 0, 30 * i + 8, 1);
    }
    sub_801A8B0(1, 1, gUnknown_082F0D5C[i + 1], 0, 30 * i + 8, 2);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 2);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
}

void sub_801A6C0(u8 taskId)
{
    s32 i;
    switch (gTasks[taskId].data[0])
    {
    case 0:
        sub_801A600();
        gTasks[taskId].data[0]++;
        break;
    case 1:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
        ShowBg(1);
        CopyBgTilemapBufferToVram(0);
        ShowBg(0);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        if (sub_801AA30(gUnknown_03000DAC->unk00, gUnknown_03000DAC->unk10, gUnknown_03000DAC->unk20, gUnknown_03000DAC->unk61))
        {
            FillWindowPixelBuffer(2, 0);
            for (i = 0; i < 4; i++)
            {
                ConvertIntToDecimalStringN(gStringVar4, gUnknown_03000DAC->unk00[i], STR_CONV_MODE_RIGHT_ALIGN, 2);
                if (i != 3)
                {
                    sub_801A8B0(2, 1, gStringVar4, 12, 30 * i + 8, 1);
                }
                else
                {
                    sub_801A8B0(2, 1, gStringVar4, 12, 98, 2);
                }
            }
            PutWindowTilemap(2);
            CopyWindowToVram(2, 3);
        }
        if (({gMain.newKeys & A_BUTTON;}) || ({gMain.newKeys & B_BUTTON;}))
        {
            PlaySE(SE_SELECT);
            gTasks[gUnknown_03000DAC->unk61].data[15] = 0xFF;
            gTasks[taskId].data[0]++;
        }
        sub_801A5BC(&gTasks[taskId].data[7], &gTasks[taskId].data[8]);
        break;
    case 4:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        gTasks[taskId].data[0]++;
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(sub_801A584);
            DestroyTask(taskId);
        }
        break;
    }
}

static void sub_801A8B0(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 mode)
{
    u8 color[3];

    switch (mode)
    {
    case 0:
        color[0] = 0;
        color[1] = 2;
        color[2] = 3;
        break;
    case 1:
        color[0] = 0;
        color[1] = 1;
        color[2] = 3;
        break;
    case 2:
        color[0] = 0;
        color[1] = 4;
        color[2] = 5;
        break;
    case 3:
        color[0] = 0;
        color[1] = 7;
        color[2] = 6;
        break;
    case 4:
        color[0] = 0;
        color[1] = 1;
        color[2] = 2;
        break;
    }

    AddTextPrinterParameterized4(windowId, fontId, x, y, 0, 0, color, -1, str);
}

#ifdef NONMATCHING
// register swap r2, r3
u8 sub_801A960(struct UnkStruct_x20 * a0, u32 * a1)
{
    s32 i, j, r2;
    u8 result = a0->unk.field_0.unk_0a_0;

    for (i = 0; i < (unsigned)ARRAY_COUNT(gUnknown_082F0D70); i++)
    {
        if (result != gUnknown_082F0D70[i][0])
        {
            continue;
        }
        if (a0->field_1A_0 != 1)
        {
            continue;
        }
        if (gUnknown_082F0D70[i][2] == 0)
        {
            r2 = 0;
            for (j = 0; j < 4; j++)
            {
                if (a0->unk.field_0.unk_04[j] != 0)
                {
                    r2++;
                }
            }
            r2++;
            a1[gUnknown_082F0D70[i][1]] += r2;
        }
        else
        {
            a1[gUnknown_082F0D70[i][1]] += gUnknown_082F0D70[i][2];
        }
    }
    return result;
}
#else
NAKED
u8 sub_801A960(struct UnkStruct_x20 * a0, u32 * a1)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tmov r7, r10\n"
                "\tmov r6, r9\n"
                "\tmov r5, r8\n"
                "\tpush {r5-r7}\n"
                "\tsub sp, 0x4\n"
                "\tmov r12, r0\n"
                "\tadds r7, r1, 0\n"
                "\tldrb r0, [r0, 0xA]\n"
                "\tlsls r0, 25\n"
                "\tlsrs r0, 25\n"
                "\tmov r8, r0\n"
                "\tmovs r4, 0\n"
                "\tldr r0, =gUnknown_082F0D70\n"
                "\tmov r9, r0\n"
                "\tmovs r1, 0x1\n"
                "\tadd r1, r9\n"
                "\tmov r10, r1\n"
                "\tmov r3, r12\n"
                "\tadds r3, 0x4\n"
                "\tstr r3, [sp]\n"
                "_0801A98A:\n"
                "\tlsls r0, r4, 1\n"
                "\tadds r2, r0, r4\n"
                "\tmov r3, r9\n"
                "\tadds r1, r2, r3\n"
                "\tadds r5, r0, 0\n"
                "\tadds r6, r4, 0x1\n"
                "\tldrb r1, [r1]\n"
                "\tcmp r8, r1\n"
                "\tbne _0801A9EE\n"
                "\tmov r0, r12\n"
                "\tldrb r1, [r0, 0x1A]\n"
                "\tmovs r0, 0x3\n"
                "\tands r0, r1\n"
                "\tcmp r0, 0x1\n"
                "\tbne _0801A9EE\n"
                "\tmov r0, r9\n"
                "\tadds r0, 0x2\n"
                "\tadds r3, r2, r0\n"
                "\tldrb r0, [r3]\n"
                "\tcmp r0, 0\n"
                "\tbne _0801A9DC\n"
                "\tmovs r2, 0\n"
                "\tmovs r1, 0\n"
                "\tldr r3, [sp]\n"
                "_0801A9BA:\n"
                "\tadds r0, r3, r1\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0\n"
                "\tbeq _0801A9C4\n"
                "\tadds r2, 0x1\n"
                "_0801A9C4:\n"
                "\tadds r1, 0x1\n"
                "\tcmp r1, 0x3\n"
                "\tble _0801A9BA\n"
                "\tadds r2, 0x1\n"
                "\tadds r0, r5, r4\n"
                "\tadd r0, r10\n"
                "\tldrb r1, [r0]\n"
                "\tlsls r1, 2\n"
                "\tadds r1, r7\n"
                "\tb _0801A9E8\n"
                "\t.pool\n"
                "_0801A9DC:\n"
                "\tmov r1, r10\n"
                "\tadds r0, r2, r1\n"
                "\tldrb r1, [r0]\n"
                "\tlsls r1, 2\n"
                "\tadds r1, r7\n"
                "\tldrb r2, [r3]\n"
                "_0801A9E8:\n"
                "\tldr r0, [r1]\n"
                "\tadds r0, r2\n"
                "\tstr r0, [r1]\n"
                "_0801A9EE:\n"
                "\tadds r4, r6, 0\n"
                "\tcmp r4, 0x1E\n"
                "\tbls _0801A98A\n"
                "\tmov r0, r8\n"
                "\tadd sp, 0x4\n"
                "\tpop {r3-r5}\n"
                "\tmov r8, r3\n"
                "\tmov r9, r4\n"
                "\tmov r10, r5\n"
                "\tpop {r4-r7}\n"
                "\tpop {r1}\n"
                "\tbx r1");
}
#endif //NONMATCHING
