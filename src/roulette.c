#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "coins.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
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
    u8 var07;
    u32 var08;
    u32 var0C;
    u16 var10;
    u16 var12;
};

struct StructgUnknown_083F8D90
{
    u8 var00;
    u8 var01;
    u8 var02;
    u8 var03;
    u32 var04;
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
/*static*/ void sub_81415D4(u8);
/*static*/ void sub_81416D4(u8);
/*static*/ void sub_8141778(u8);
/*static*/ void sub_814189C(u8);
/*static*/ void sub_8141A18(u8);
/*static*/ void sub_8141AC0(u8);
/*static*/ void sub_8141B58(u8);
/*static*/ void dp01t_12_3_battle_menu(u8);
/*static*/ void sub_8141DE4(u8);
/*static*/ void sub_8141E7C(u8);
/*static*/ void sub_8141F7C(u8 taskId, TaskFunc r1, u16 r2, u16 r3);
/*static*/ void sub_8141FF4(u8);
/*static*/ void sub_8142070(void);
/*static*/ u8 sub_81420D0(u8, u8);
/*static*/ bool8 sub_81421E8(u8, u8);
/*static*/ void sub_8142284(u8);
/*static*/ void sub_81424FC(u8);
/*static*/ u8 sub_8142758(u8);
/*static*/ void sub_8142814(void);
/*static*/ void sub_8142C0C(u8);
/*static*/ void sub_8142CD0(void);
/*static*/ void sub_8142E70(u8, u8);
/*static*/ void sub_8142F7C(void);
/*static*/ void sub_8143038(u8, u8);
/*static*/ void sub_8143150(u8);
/*static*/ void sub_81431E4(void);
/*static*/ void sub_8143314(void);
/*static*/ void sub_8143514(u16);
/*static*/ void sub_81436D0(u8);
/*static*/ void sub_814372C(u8);
/*static*/ void sub_814390C(struct Sprite *);
/*static*/ void sub_814391C(void);
/*static*/ void sub_81439C8(void);
/*static*/ void sub_8143A40(void);
/*static*/ void sub_81446AC(struct Sprite *);
/*static*/ void sub_81446DC(struct Sprite *);
/*static*/ void sub_81448B8(struct Sprite *);
/*static*/ void sub_8144A24(struct Sprite *);

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
extern const u8 gUnknown_082A5BD7[];
extern const u8 gUnknown_082A5BCB[];
extern const u8 gUnknown_082A5BE0[];
extern const u8 gUnknown_082A5BEF[];
extern const u8 gUnknown_082A5C21[];
extern const u8 gUnknown_082A5C61[];
extern const u8 gUnknown_082A5C04[];
extern const u8 gUnknown_082A5B12[];
extern const u8 gUnknown_082A5B6B[];
extern const u8 gUnknown_082A5B4E[];
extern const struct YesNoFuncTable gUnknown_085B6410;
extern const struct StructgUnknown_085B6154 gUnknown_085B6154[];
extern const u8 gUnknown_085B641E[];
extern const u16 gUnknown_085B6422;
extern const u32 gUnknown_085B642C[];
extern const u32 gUnknown_085B643C[];
extern const struct StructgUnknown_083F8D90 gUnknown_085B62E4[];
extern const struct UnkStruct1 gUnknown_085B63F0[];
extern const u8 gUnknown_085B6448[];
extern const struct YesNoFuncTable gUnknown_085B6408;
extern const struct SpritePalette gUnknown_085B7384[];
extern const struct CompressedSpriteSheet gUnknown_085B7864;
extern const struct CompressedSpriteSheet gUnknown_085B7978;
extern const struct CompressedSpriteSheet gUnknown_085B7A40;
extern const struct CompressedSpriteSheet gUnknown_085B7488;
extern const struct CompressedSpriteSheet gUnknown_085B7490;
extern const struct SpriteTemplate gSpriteTemplate_85B75B0[];
extern const struct SpriteTemplate gSpriteTemplate_85B7508[];
extern const struct SpriteTemplate gSpriteTemplate_85B7568[];
extern const struct SpriteTemplate gSpriteTemplate_85B7928;
extern const struct CompressedSpriteSheet gUnknown_085B741C;
extern const struct SpriteTemplate gSpriteTemplate_85B7610[];
extern const struct CompressedSpriteSheet gUnknown_085B7750[];
extern const struct SpriteTemplate gSpriteTemplate_85B77E4;
extern const struct SpriteTemplate gUnknown_085B77FC;
extern const struct SpriteTemplate gUnknown_085B7814;
extern const struct SpriteTemplate gUnknown_085B782C;
extern const struct SpriteTemplate gUnknown_085B7844;
extern const u8 gUnknown_085B7B04[];
extern const struct CompressedSpriteSheet gUnknown_085B7948;
extern const struct SpriteTemplate gSpriteTemplate_85B7950;
extern const u16 gUnknown_085B7B0A[][2];
extern const struct SpriteTemplate gSpriteTemplate_85B79F8;
extern const struct SpriteTemplate gSpriteTemplate_85B7ABC[];

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
    gTasks[taskId].func = sub_8140F6C;
}

void sub_8141040(u8 taskId)
{
    sub_8140D6C(taskId);

    switch (gTasks[taskId].data[1])
    {
    case 0:
        sub_81409B8(gTasks[taskId].data[4]);
        gTasks[taskId].data[1]+= 1;
        break;
    case 30:
        sub_81409B8(0);
        gTasks[taskId].data[1]+= 1;
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

void sub_81410FC(u8 taskId)
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

void sub_814155C(u8 taskId)
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

void sub_81415D4(u8 taskId)
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

void sub_81416D4(u8 taskId)
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

void sub_8141778(u8 taskId)
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

void sub_8141800(u8 taskId)
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

void sub_814189C(u8 taskId)
{
    switch (gTasks[taskId].data[5])
    {
    case 1:
    case 2:
        if (gTasks[taskId].data[2] == 12)
        {
            PlayFanfare(MUS_ME_B_BIG);
            NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5BD7, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
        }
        else
        {
            PlayFanfare(MUS_ME_B_SMALL);
            NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5BCB, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
        }
        break;
    case 0:
    default:
        m4aSongNumStart(SE_HAZURE);
        NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5BE0, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        break;
    }
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_8141800;
}

void sub_8141984(u8 taskId)
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

void sub_8141A18(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, (gUnknown_0203AB88->var19 * gTasks[taskId].data[2]), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gUnknown_082A5BEF);
    NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
    AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(gUnknown_0203AB8C, 3);
    gTasks[taskId].data[1] = (gUnknown_0203AB88->var19 * gTasks[taskId].data[2]);
    gTasks[taskId].data[7] = 0;
    gTasks[taskId].func = sub_8141984;
}

void sub_8141AC0(u8 taskId)
{
    sub_8151A9C(&gUnknown_0203AB88->varB8, 0xFFFF);
    gUnknown_0203AB88->varB8.var04[13].var00_7 = gUnknown_0203AB88->varB8.var04[14].var00_7 = gUnknown_0203AB88->varB8.var04[15].var00_7 = 0;
    gSprites[gUnknown_0203AB88->var3C[7 + gUnknown_085B6154[gTasks[taskId].data[12]].var00]].invisible = TRUE;
    gTasks[taskId].func = sub_8141B58;
}

void sub_8141B58(u8 taskId)
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
            NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5C21, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(gUnknown_0203AB8C, 3);
            sub_8141F7C(taskId, dp01t_12_3_battle_menu, 0xFFFF, 3);
        }
        else if (gTasks[taskId].data[13] == 9999)
        {
            NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
            AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5C61, 0, 1, TEXT_SPEED_FF, NULL);
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
        NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5C04, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        sub_8141F7C(taskId, sub_8140994, 0x3C, 0x3);
    }
}

void dp01t_12_3_battle_menu(u8 taskId)
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
        NewMenuHelpers_DrawStdWindowFrame(gUnknown_0203AB8C, FALSE);
        AddTextPrinterParameterized(gUnknown_0203AB8C, 1, gUnknown_082A5C61, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_0203AB8C, 3);
        sub_8141F7C(taskId, sub_8140914, 0xFFFF, 3);
    }
    else
    {
        gTasks[taskId].func = sub_8140914;
    }
}

void sub_8141DE4(u8 taskId)
{
    sub_8151A9C(&gUnknown_0203AB88->varB8, 0xFFFF);
    sub_8151678(&gUnknown_0203AB88->varB8);
    SetCoins(gTasks[taskId].data[13]);
    if (GetCoins() < gUnknown_0203AB88->var19)
        gSpecialVar_0x8004 = TRUE;
    else
        gSpecialVar_0x8004 = FALSE;
    sub_80EDD78(GetCoins());
    BeginHardwarePaletteFade(0xFF, 0, 0, 16, 0);
    gTasks[taskId].func = sub_8141E7C;
}

void sub_8141E7C(u8 taskId) // end roulette ?
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
        gFieldCallback = sub_80AF168;
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void sub_8141EF8(u8 taskId)
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

void sub_8141F7C(u8 taskId, TaskFunc r1, u16 r2, u16 r3)
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

void sub_8141FF4(u8 taskId)
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

void sub_8142070(void)
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

u8 sub_81420D0(u8 taskId, u8 r1)
{
    u8 i;
    u8 z;
    u32 t0[4];
    u32 t1[3];

    memcpy(t0, gUnknown_085B642C, sizeof(t0));
    memcpy(t1, gUnknown_085B643C, sizeof(t1));
    
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

bool8 sub_81421E8(u8 r0, u8 r1)
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

void sub_8142284(u8 r0)
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

void sub_81424FC(u8 r0)
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

u8 sub_8142758(u8 r0)
{
    u8 var0[5];
    memcpy(var0, gUnknown_085B6448, sizeof(var0));

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

void sub_8142814(void)
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

void sub_81428C4(u8 r0)
{
    DisplayYesNoMenu();
    DoYesNoFuncWithChoice(r0, &gUnknown_085B6408);
}

void sub_81428E4(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        SetMainCallback2(sub_81405CC);
        DestroyTask(taskId);
    }
}

void sub_8142918(u8 taskId)
{
    sub_819746C(0, TRUE);
    HideCoinsWindow();
    FreeAllWindowBuffers();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gPaletteFade.delayCounter = gPaletteFade.multipurpose2;
    UpdatePaletteFade();
    gTasks[taskId].func = sub_81428E4;
}

void sub_814297C(u8 taskId)
{
    sub_819746C(0, FALSE);
    HideCoinsWindow();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

void sub_81429A0(u8 taskId)
{
    gTasks[taskId].data[0]++;
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        gSpecialVar_0x8004 = 1;
        HideCoinsWindow();
        sub_819746C(0, TRUE);
        ScriptContext2_Disable();
        DestroyTask(taskId);
    }
}

void sub_81429F0(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        u32 temp = gUnknown_085B6344[(gSpecialVar_0x8004 & 1) + (gSpecialVar_0x8004 >> 7 << 1)];
        ConvertIntToDecimalStringN(gStringVar1, temp, STR_CONV_MODE_LEADING_ZEROS, 1);
        StringExpandPlaceholders(gStringVar4, gUnknown_082A5B12);
        NewMenuHelpers_DrawStdWindowFrame(0, FALSE);
        AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = sub_81428C4;
    }
}

void Task_Roulette_0(u8 taskId)
{
    s32 temp;
    PrintCoinsString(gTasks[taskId].data[13]);
    temp = gUnknown_085B6344[(gSpecialVar_0x8004 & 1) + (gSpecialVar_0x8004 >> 7 << 1)];
    ConvertIntToDecimalStringN(gStringVar1, temp, 2, 1);
    if (gTasks[taskId].data[13] >= temp)
    {
        if ((gSpecialVar_0x8004 & 0x80) && (gSpecialVar_0x8004 & 1))
        {
            NewMenuHelpers_DrawStdWindowFrame(0, FALSE);
            AddTextPrinterParameterized(0, 1, gUnknown_082A5B6B, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = sub_81429F0;
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gUnknown_082A5B12);
            NewMenuHelpers_DrawStdWindowFrame(0, FALSE);
            AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = sub_81428C4;
        }
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gUnknown_082A5B4E);
        NewMenuHelpers_DrawStdWindowFrame(0, FALSE);
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

void sub_8142C0C(u8 r0)
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

u8 sub_8142C60(const struct SpriteTemplate *r0, u8 r1, u16 *r2)
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

void sub_8142CD0(void)
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

void unref_sub_8142E3C(void)
{
    u8 i;
    for (i = 0; i < 12; i++)
    {
        DestroySprite(&gSprites[gUnknown_0203AB88->var3C[i + 29]]);
    }
}

void sub_8142E70(u8 r0, u8 r1)
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

void sub_8142F7C(void)
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

void sub_8143038(u8 r0, u8 r1)
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

void sub_8143150(u8 r0)
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

void sub_81431E4(void)
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

void sub_8143280(struct Sprite *sprite)
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

void sub_8143314(void)
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

void sub_8143514(u16 r0)
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

u8 sub_8143614(u8 r0)
{
    u8 t[5];
    memcpy(t, gUnknown_085B7B04, sizeof(t));
    
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

void sub_81436D0(u8 r0)
{
    struct Sprite *s = &gSprites[gUnknown_0203AB88->var3C[25]];
    s->animCmdIndex = sub_8143614(r0);
    s->oam.tileNum = s->sheetTileStart + (*s->anims + s->animCmdIndex)->type;
}

void sub_814372C(u8 r0)
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

void sub_814390C(struct Sprite *sprite)
{
    sprite->pos2.x = gUnknown_0203AB88->var26;
}

void sub_814391C(void)
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

void sub_814399C(struct Sprite *sprite)
{
    u32 t = sprite->oam.matrixNum;
    struct OamMatrix *m = &gOamMatrices[0];
    m[t].d = gUnknown_0203AB88->var2C.a;
    m[t].a = gUnknown_0203AB88->var2C.a;
    m[t].b = gUnknown_0203AB88->var2C.b;
    m[t].c = gUnknown_0203AB88->var2C.c;
}

void sub_81439C8(void)
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

void sub_8143A40(void)
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

s16 sub_8143AC8(struct Sprite *sprite)
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

u8 sub_8143B14(struct Sprite *sprite)
{
    gUnknown_0203AB88->var7E = sub_8143AC8(sprite) / 30.0f;
    return gUnknown_0203AB88->var7E;
}

s16 sub_8143B48(struct Sprite *sprite)
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

void sub_8143B84(struct Sprite *sprite)
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

void sub_8143C90(struct Sprite *sprite)
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

void sub_8143CFC(struct Sprite *sprite)
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

void sub_8143E14(struct Sprite *sprite)
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

void sub_8143FA4(struct Sprite *sprite)
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

void sub_8144050(struct Sprite *sprite)
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

void sub_8144128(struct Sprite *sprite)
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

void sub_8144168(struct Sprite *sprite)
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

void prev_quest_read_x24_hm_usage(struct Sprite *sprite)
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

void sub_8144264(struct Sprite *sprite)
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

void sub_8144410(struct Sprite *sprite)
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

void sub_8144514(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (gUnknown_0203AB88->var94 > 40.f)
        return;

    gUnknown_0203AB88->var98 = -(4.0f / (float)gUnknown_0203AB88->var86);
    gUnknown_0203AB88->var90 = -(gUnknown_0203AB88->var8C / (float)gUnknown_0203AB88->var86);
    sprite->animNum = 2;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->data[1] = 3;
    sprite->callback = sub_8144410;
}

void sub_81445D8(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (gUnknown_0203AB88->var94 > 60.0f)
        return;

    m4aSongNumStartOrChange(SE_TAMAKORO_E);
    gUnknown_0203AB88->var98 = -(20.0f / (float)gUnknown_0203AB88->var84);
    gUnknown_0203AB88->var90 = ((1.0f - gUnknown_0203AB88->var8C) / (float)gUnknown_0203AB88->var84);
    sprite->animNum = 1;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->data[1] = 2;
    sprite->callback = sub_8144514;
}

void sub_81446AC(struct Sprite *sprite)
{
    sprite->data[1] = 1;
    sprite->data[2] = 0;
    sub_8143B84(sprite);
    sprite->invisible = FALSE;
    sprite->callback = sub_81445D8;
}

void sub_81446DC(struct Sprite *sprite)
{
    u16 t;
    u8 i;
    s16 s[2][2];
    struct Roulette *p;

    memcpy(s, gUnknown_085B7B0A, 8);
    t = sprite->data[7] - 2;
    p = gUnknown_0203AB88;  // why???
    gUnknown_0203AB88->var3C[55] = CreateSprite(&gSpriteTemplate_85B79F8, 36, -12, 50);
    gUnknown_0203AB88->var3C[56] = CreateSprite(&gSpriteTemplate_85B7ABC[0], s[sprite->data[0]][0], s[sprite->data[0]][1], 59);
    gUnknown_0203AB88->var3C[57] = CreateSprite(&gSpriteTemplate_85B7ABC[1], 36, 140, 51);
    gSprites[gUnknown_0203AB88->var3C[57]].oam.objMode = 1;
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
