#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "coins.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "random.h"
#include "roulette.h"
#include "roulette_util.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "tv.h"
#include "window.h"
#include "constants/species.h"
#include "constants/songs.h"

struct StructgUnknown_083F8DF4
{
    u8 var00;
    u8 var01;
    u8 var02;
    u8 var03;
    u8 var04;
    u8 v[0x3];
    u16 var08;
    u16 var0A;
    u16 var0C;
    u16 v13[0x1];
    u16 var10;
    u16 var12;
    u16 var14;
    u8 v1[0x2];
    u16 var18;
    u16 var1A;
    float var1C;
};

struct StructgUnknown_083F8C00
{
    u8 var00;
    u8 var01_0:4;
    u8 var01_4:4;
    u8 var02;
    u8 var03;
    u8 var04;
    u8 var05;
    u8 var06;
    u8 var07;
    u32 var08;
    u32 var0C;
    u16 var10;
    u16 var12;
};

extern struct Roulette
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
    u8 var0C[0x6];
    u8 var12[0x4];
    u8 var16[0x3];
    u8 var19;
    u8 var1A_0:4;
    u8 var1A_4:4;
    u8 var1B[0x6];
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
    u8 var3C[0x40]; // Sprite IDs
    u8 var7C;
    u8 var7D;
    u8 var7E;
    u8 var7F;
    s16 var80;
    s16 var82;
    s16 var84;
    s16 var86;
    float var88;
    float var8C;
    float var90;
    float var94;
    float var98;
    float var9C;
    float varA0;
    u8 varA4;
    u8 varA5;
    u8 v51[0x2];
    u16 varA8;
    u16 varAA;
    TaskFunc varAC;
    u8 v46[0x4];
    TaskFunc varB4;
    struct UnkStruct0 varB8;
    u16 tilemapBuffers[7][0x400];
    u16 *unk_397C;
} *gUnknown_0203AB88;
extern u8 gUnknown_0203AB8C;

/*static*/ void sub_8140814(u8);
/*static*/ void sub_81408A8(u8);
/*static*/ void sub_8140968(u8);
/*static*/ void sub_8140BD0(u8);
/*static*/ void sub_8141040(u8);
/*static*/ void sub_81410FC(u8);
/*static*/ void sub_8141344(u8);
/*static*/ void sub_814155C(u8);
/*static*/ void sub_8141DE4(u8);
/*static*/ void sub_8141F7C(u8 taskId, TaskFunc r1, u16 r2, u16 r3);
/*static*/ void sub_8141FF4(u8);
/*static*/ void sub_8142070(void);
/*static*/ void sub_8142284(u8);
/*static*/ void sub_81424FC(u8);
/*static*/ u8 sub_8142758(u8);
/*static*/ void sub_8142814(void);
/*static*/ void sub_8142C0C(u8);
/*static*/ void sub_8142CD0(void);
/*static*/ void sub_8142E70(u8, u8);
/*static*/ void sub_8142F7C(void);
/*static*/ void sub_8143038(u8, u8);
/*static*/ void sub_81431E4(void);
/*static*/ void sub_8143314(void);
/*static*/ void sub_8143514(u16);
/*static*/ void sub_81436D0(u8);
/*static*/ void sub_814372C(u8);
/*static*/ void sub_814391C(void);
/*static*/ void sub_81439C8(void);
/*static*/ void sub_8143A40(void);

extern const struct BgTemplate gUnknown_085B6140[3];
extern const struct WindowTemplate gUnknown_085B614C[];
extern const u32 gUnknown_085B5DFC[];
extern const u16 gUnknown_085B6418[];
extern const struct StructgUnknown_083F8DF4 gUnknown_085B6348[];
extern const u8 gUnknown_085B6344[];
extern const struct UnkStruct1 gUnknown_085B6388[];
extern const u16 gUnknown_085B5BFC[];
extern const u32 gRouletteMenuTiles[];
extern const u32 gRouletteWheelTiles[];
extern const u32 gUnknown_085B5FA0[];
extern const u8 gUnknown_082A5B89[];
extern const u8 gUnknown_082A5C13[];
extern const struct YesNoFuncTable gUnknown_085B6410;
extern const struct StructgUnknown_083F8C00 gUnknown_085B6154[];
extern const u8 gUnknown_085B641E[];
extern const u16 gUnknown_085B6422;

void sub_8140238(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	if (gUnknown_0203AB88->varB8.var00)
	   task_tutorial_controls_fadein(&gUnknown_0203AB88->varB8);
}

void sub_8140264(void)
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

void sub_8140388(void)
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

void sub_8140418(void)
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

void sub_8140470(void)
{
    u8 i;
    u16 arr[3]; // the third is never used ?

    memcpy(arr, &gUnknown_085B6418, sizeof(arr));
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

void sub_81405CC(void)
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
        NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5B89, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        gSpriteCoordOffsetX = -0x3C;
        gSpriteCoordOffsetY = 0x0;
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
        sub_80EDE84(GetCoins());
        gUnknown_0203AB88->varA5 = CreateTask(sub_8140814, 1);
        SetMainCallback2(sub_8140238);
        return;
    }
    gMain.state++;
}

void sub_8140814(u8 unused)
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

void sub_81408A8(u8 taskId)
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

void sub_8140914(u8 taskId)
{
    DisplayYesNoMenu();
    NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, 0);
    AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5C13, 0, 1, TEXT_SPEED_FF, 0);
    CopyWindowToVram(gUnknown_0203AB8C, 3);
    DoYesNoFuncWithChoice(taskId, &gUnknown_085B6410);
}

void sub_8140968(u8 taskId)
{
    sub_819746C(0, TRUE);
    gTasks[taskId].func = sub_8140BD0;
}

void sub_8140994(u8 taskId)
{
    DestroyTask(gUnknown_0203AB88->varA5);
    sub_8141DE4(taskId);
}

void sub_81409B8(u8 r0)
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

void sub_8140B64(u8 taskId)
{
    sub_81436D0(gTasks[taskId].data[4]);
    sub_81409B8(gTasks[taskId].data[4]);
}

void sub_8140B8C(u8 taskId)
{
    gUnknown_0203AB88->var28 = 1;
    sub_81409B8(gTasks[taskId].data[4]);
    gUnknown_0203AB88->var23 = 2;
    gUnknown_0203AB88->var21 = 0;
    gTasks[taskId].func = sub_8141040;
}

void sub_8140BD0(u8 taskId)
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

u8 sub_8140CA8(s16 *r0, u8 r1)
{
    s8 temp1 = 0;
    s8 temp = 0;
    s8 arr[4];
    s8 t;

    memcpy(&arr, gUnknown_085B641E, sizeof(arr));
    t = *r0;

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

void sub_8140D6C(u8 r0)
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
                        struct Roulette *roulette;
                        sub_81424FC(gTasks[r0].data[4]);
                        sub_8140B64(r0);
                        gTasks[r0].data[1] = z;
                        PlaySE(SE_SELECT);
                        sub_8151A9C(&gUnknown_0203AB88->varB8, 0xFFFF);
                        roulette = gUnknown_0203AB88;
                        roulette->varB8.var04[15].var00_7 = 0;
                        roulette->varB8.var04[14].var00_7 = 0;
                        roulette->varB8.var04[13].var00_7 = 0;
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

void sub_8140F6C(u8 r0)
{
    sub_80EECA4();
    gUnknown_0203AB88->var28 = 0xFF;
    if (gUnknown_0203AB88->var19 == 1)
        gUnknown_0203AB88->var23 = 1;
    else
        gUnknown_0203AB88->var23 = 0;
    gUnknown_0203AB88->var21 = 0;
    gTasks[r0].data[1] = 32;
    gTasks[r0].func = sub_81410FC;
}

void sub_8140FC4(u8 taskId)
{
    gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0] = gTasks[taskId].data[4];
    gTasks[taskId].data[2] = sub_8142758(gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]);
    sub_81436D0(gUnknown_0203AB88->var1B[gUnknown_0203AB88->var1A_0]);
    if ((gTasks[taskId].data[13] -= gUnknown_0203AB88->var19) < 0)
        gTasks[taskId].data[13] = 0;
    sub_8143514(gTasks[taskId].data[13]);
    gTasks[taskId].func = &sub_8140F6C;
}

void sub_8141040(u8 taskId)
{
    sub_8140D6C(taskId);

    switch (gTasks[taskId].data[0x1])
    {
    case 0:
        sub_81409B8(gTasks[taskId].data[0x4]);
        gTasks[taskId].data[0x1]+= 1;
        break;
    case 30:
        sub_81409B8(0);
        gTasks[taskId].data[0x1]+= 1;
        break;
    case 59:
        gTasks[taskId].data[0x1] = 0;
        break;
    default:
        gTasks[taskId].data[0x1]++;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        if ((gUnknown_0203AB88->var08 & gUnknown_085B6154[gTasks[taskId].data[0x4]].var08))
            PlaySE(SE_BOO);
        else
        {
            m4aSongNumStart(SE_REGI);
            gTasks[taskId].func = sub_8140FC4;
        }
    }
}

void sub_81410FC(u8 taskId)
{
    if (gTasks[taskId].data[0x1]-- > 0)
    {
        if (gTasks[taskId].data[0x1] > 0x2)
            gSpriteCoordOffsetX += 0x2;
        if ((gUnknown_0203AB88->var26 += 0x4) == 0x68)
            gSprites[gUnknown_0203AB88->var3C[0x19]].callback = &SpriteCallbackDummy;
    }
    else
    {
        sub_8142E70(1, 0xFF);
        sub_8143038(1, 0xFF);
        gTasks[taskId].func = sub_8141344;
        gTasks[taskId].data[0x1] = 0;
    }
}

u8 sub_814118C(u16 r0, u16 r1)
{
    switch (gUnknown_0203AB88->var02)
    {
    case 1: // SHROOMISH
    case 2: // TAILLOW
        // one of the two is in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 10)
        {
            if (r0 < 0xC || (r1 & 0x1))
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
            else
            {
                return 0x1;
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
            if (r0 < 0x6 || (r1 & 0x1))
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
            else
            {
                return 0x1;
            }
        }
        else if ((r1 & 0x1) && r0 > 6)
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
            if (!(r1 & 0x3))
            {
                return 0x1;
            }
            else
            {
                return gUnknown_085B6348[gUnknown_0203AB88->var04_0].var02 / 2;
            }
        }
        else if (!(r1 & 0x3))
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

// r7/r8 swap
#ifdef NONMATCHING
void sub_8141344(u8 taskId)
{
    u8 randf;
    s8 randfinal;
    s8 r5;
    u16 g = 0;
    u16 rand;
    u16 randmod;
    u16 angles[4]; // angles in 90 degree steps

    memcpy(angles, &gUnknown_085B6422, sizeof(angles));
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
    gUnknown_0203AB88->var84 = g;
    gUnknown_0203AB88->var86 = g;

    gUnknown_0203AB88->var88 = S16TOPOSFLOAT(angles[(rand & 1) + r5]);
    gUnknown_0203AB88->var8C = S16TOPOSFLOAT(gUnknown_085B6348[gUnknown_0203AB88->var04_0].var18);
    gUnknown_0203AB88->var90 = ((gUnknown_0203AB88->var8C * 0.5f) - gUnknown_0203AB88->var8C) / S16TOPOSFLOAT(gUnknown_0203AB88->var82);
    gUnknown_0203AB88->var94 = 68.0f;
    gUnknown_0203AB88->var9C = 0.0f;
    gUnknown_0203AB88->var98 = -(8.0f / S16TOPOSFLOAT(gUnknown_0203AB88->var82));
    gUnknown_0203AB88->varA0 = 36.0f;
    gTasks[taskId].func = sub_814155C;
}
#else
NAKED
void sub_8141344(u8 taskId)
{
    asm_unified("	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x8\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r10, r0\n\
	movs r4, 0\n\
	ldr r1, =gUnknown_085B6422\n\
	mov r0, sp\n\
	movs r2, 0x8\n\
	bl memcpy\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r7, r0, 16\n\
	adds r0, r7, 0\n\
	movs r1, 0x64\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	lsrs r6, r0, 16\n\
	ldr r3, =gUnknown_0203AB88\n\
	ldr r0, [r3]\n\
	ldr r2, =gTasks\n\
	mov r5, r10\n\
	lsls r1, r5, 2\n\
	add r1, r10\n\
	lsls r1, 3\n\
	adds r1, r2\n\
	ldrh r2, [r1, 0x14]\n\
	adds r0, 0x7C\n\
	strb r2, [r0]\n\
	ldr r0, [r3]\n\
	adds r2, r0, 0\n\
	adds r2, 0x7F\n\
	strb r4, [r2]\n\
	subs r2, 0x1\n\
	strb r4, [r2]\n\
	adds r0, 0x7D\n\
	strb r4, [r0]\n\
	ldrh r0, [r1, 0x18]\n\
	adds r1, r7, 0\n\
	bl sub_814118C\n\
	adds r4, r0, 0\n\
	lsls r4, 24\n\
	lsrs r1, r4, 24\n\
	adds r0, r7, 0\n\
	bl __modsi3\n\
	lsrs r4, 25\n\
	subs r0, r4\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	ldr r0, =gLocalTime\n\
	ldrb r0, [r0, 0x2]\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	movs r5, 0x1\n\
	cmp r0, 0xC\n\
	bgt _081413C8\n\
	movs r5, 0\n\
_081413C8:\n\
	cmp r6, 0x4F\n\
	bhi _081413E0\n\
	lsls r0, r5, 25\n\
	b _081413EA\n\
	.pool\n\
_081413E0:\n\
	lsls r1, r5, 24\n\
	asrs r1, 24\n\
	movs r0, 0x1\n\
	subs r0, r1\n\
	lsls r0, 25\n\
_081413EA:\n\
	lsrs r5, r0, 24\n\
	ldr r0, _08141530  @ =gUnknown_0203AB88\n\
	ldr r6, [r0]\n\
	ldrb r0, [r6, 0x4]\n\
	lsls r0, 30\n\
	lsrs r0, 25\n\
	ldr r1, _08141534  @ =gUnknown_085B6348\n\
	adds r0, r1\n\
	lsls r4, 24\n\
	asrs r4, 24\n\
	ldrh r0, [r0, 0x1A]\n\
	adds r4, r0\n\
	adds r0, r6, 0\n\
	adds r0, 0x80\n\
	strh r4, [r0]\n\
	lsls r4, 16\n\
	asrs r4, 16\n\
	adds r0, r4, 0\n\
	bl __floatsisf\n\
	cmp r4, 0\n\
	bge _0814141C\n\
	ldr r1, _08141538  @ =0x47800000\n\
	bl __addsf3\n\
_0814141C:\n\
	ldr r1, _0814153C  @ =0x40A00000\n\
	bl __divsf3\n\
	bl __fixunssfsi\n\
	lsls r0, 16\n\
	lsrs r4, r0, 16\n\
	lsls r0, r4, 1\n\
	adds r0, r4\n\
	movs r2, 0x82\n\
	adds r2, r6\n\
	mov r8, r2\n\
	strh r0, [r2]\n\
	adds r0, r6, 0\n\
	adds r0, 0x84\n\
	strh r4, [r0]\n\
	adds r0, 0x2\n\
	strh r4, [r0]\n\
	movs r0, 0x88\n\
	adds r0, r6\n\
	mov r9, r0\n\
	movs r0, 0x1\n\
	ands r0, r7\n\
	lsls r1, r5, 24\n\
	asrs r1, 24\n\
	adds r0, r1\n\
	lsls r0, 1\n\
	add r0, sp\n\
	movs r1, 0\n\
	ldrsh r4, [r0, r1]\n\
	adds r0, r4, 0\n\
	bl __floatsisf\n\
	cmp r4, 0\n\
	bge _08141468\n\
	ldr r1, _08141538  @ =0x47800000\n\
	bl __addsf3\n\
_08141468:\n\
	mov r2, r9\n\
	str r0, [r2]\n\
	adds r7, r6, 0\n\
	adds r7, 0x8C\n\
	ldrb r0, [r6, 0x4]\n\
	lsls r0, 30\n\
	lsrs r0, 25\n\
	ldr r5, _08141534  @ =gUnknown_085B6348\n\
	adds r0, r5\n\
	movs r1, 0x18\n\
	ldrsh r4, [r0, r1]\n\
	adds r0, r4, 0\n\
	bl __floatsisf\n\
	adds r5, r0, 0\n\
	cmp r4, 0\n\
	bge _08141492\n\
	ldr r1, _08141538  @ =0x47800000\n\
	bl __addsf3\n\
	adds r5, r0, 0\n\
_08141492:\n\
	str r5, [r7]\n\
	adds r7, r6, 0\n\
	adds r7, 0x90\n\
	ldr r1, _08141540  @ =0x3F000000\n\
	adds r0, r5, 0\n\
	bl __mulsf3\n\
	adds r1, r5, 0\n\
	bl __subsf3\n\
	adds r5, r0, 0\n\
	mov r2, r8\n\
	movs r0, 0\n\
	ldrsh r4, [r2, r0]\n\
	adds r0, r4, 0\n\
	bl __floatsisf\n\
	adds r2, r0, 0\n\
	cmp r4, 0\n\
	bge _081414C2\n\
	ldr r1, _08141538  @ =0x47800000\n\
	bl __addsf3\n\
	adds r2, r0, 0\n\
_081414C2:\n\
	adds r0, r5, 0\n\
	adds r1, r2, 0\n\
	bl __divsf3\n\
	str r0, [r7]\n\
	adds r1, r6, 0\n\
	adds r1, 0x94\n\
	ldr r0, _08141544  @ =0x42880000\n\
	str r0, [r1]\n\
	adds r1, 0x8\n\
	ldr r0, _08141548  @ =0x00000000\n\
	str r0, [r1]\n\
	adds r5, r6, 0\n\
	adds r5, 0x98\n\
	mov r1, r8\n\
	movs r2, 0\n\
	ldrsh r4, [r1, r2]\n\
	adds r0, r4, 0\n\
	bl __floatsisf\n\
	adds r2, r0, 0\n\
	cmp r4, 0\n\
	bge _081414F8\n\
	ldr r1, _08141538  @ =0x47800000\n\
	bl __addsf3\n\
	adds r2, r0, 0\n\
_081414F8:\n\
	ldr r0, _0814154C  @ =0x41000000\n\
	adds r1, r2, 0\n\
	bl __divsf3\n\
	bl __negsf2\n\
	str r0, [r5]\n\
	adds r1, r6, 0\n\
	adds r1, 0xA0\n\
	ldr r0, _08141550  @ =0x42100000\n\
	str r0, [r1]\n\
	ldr r1, _08141554  @ =gTasks\n\
	mov r5, r10\n\
	lsls r0, r5, 2\n\
	add r0, r10\n\
	lsls r0, 3\n\
	adds r0, r1\n\
	ldr r1, _08141558  @ =sub_814155C\n\
	str r1, [r0]\n\
	add sp, 0x8\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08141530:\n\
	.4byte gUnknown_0203AB88\n\
_08141534:\n\
	.4byte gUnknown_085B6348\n\
_08141538:\n\
	.4byte 0x47800000\n\
_0814153C:\n\
	.4byte 0x40A00000\n\
_08141540:\n\
	.4byte 0x3F000000\n\
_08141544:\n\
	.4byte 0x42880000\n\
_08141548:\n\
	.4byte 0x00000000\n\
_0814154C:\n\
	.4byte 0x41000000\n\
_08141550:\n\
	.4byte 0x42100000\n\
_08141554:\n\
	.4byte gTasks\n\
_08141558:\n\
	.4byte sub_814155C");
}
#endif // NONMATCHING
