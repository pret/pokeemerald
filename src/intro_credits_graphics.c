#include "global.h"
#include "intro_credits_graphics.h"
#include "palette.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "main.h"

EWRAM_DATA u16 gUnknown_0203BD24 = 0;
EWRAM_DATA s16 gUnknown_0203BD26 = 0;
EWRAM_DATA s16 gUnknown_0203BD28 = 0;

extern const u16 gUnknown_085F06E0[]/* = INCBIN_U16("graphics/intro/intro2_grass.gbapal")*/;
extern const u16 gUnknown_085F0700[]/* = INCBIN_U16("graphics/intro/intro2_grass_afternoon.gbapal")*/;
extern const u16 gUnknown_085F0720[]/* = INCBIN_U16("graphics/intro/intro2_grass_night.gbapal")*/;
extern const u8 gUnknown_085F0740[]/* = INCBIN_U8("graphics/intro/intro2_grass.4bpp.lz")*/;
extern const u8 gUnknown_085F0BC0[]/* = INCBIN_U8("graphics/intro/intro2_grass_map.bin.lz")*/;
extern const u16 gUnknown_085F0CFC[]/* = INCBIN_U16("graphics/intro/8412818.gbapal")*/;
extern const u16 gUnknown_085F0D5C[]/* = INCBIN_U16("graphics/intro/8412878.gbapal")*/;
extern const u8 gUnknown_085F0DBC[]/* = INCBIN_U8("graphics/intro/intro2_bgclouds.4bpp.lz")*/;
extern const u8 gUnknown_085F1398[]/* = INCBIN_U8("graphics/intro/intro2_bgclouds_map.bin.lz")*/;
extern const u16 gUnknown_085F1668[]/* = INCBIN_U16("graphics/intro/intro2_bgclouds.gbapal")*/;
extern const u16 gUnknown_085F1688[]/* = INCBIN_U16("graphics/intro/intro2_bgclouds_afternoon.gbapal")*/;
extern const u8 gUnknown_085F16A8[]/* = INCBIN_U8("graphics/intro/intro2_bgclouds2.4bpp.lz")*/;
extern const u16 gUnknown_085F17E4[]/* = INCBIN_U16("graphics/intro/intro2_bgtrees2.gbapal")*/;
extern const u16 gUnknown_085F1804[]/* = INCBIN_U16("graphics/intro/intro2_bgtrees2_afternoon.gbapal")*/;
extern const u8 gUnknown_085F1824[]/* = INCBIN_U8("graphics/intro/intro2_bgtrees.4bpp.lz")*/;
extern const u8 gUnknown_085F1EAC[]/* = INCBIN_U8("graphics/intro/intro2_bgtrees_map.bin.lz")*/;
extern const u16 gUnknown_085F21B0[]/* = INCBIN_U16("graphics/intro/intro2_bgtrees.gbapal")*/;
extern const u8 gIntro2TreeTiles[]/* = INCBIN_U8("graphics/intro/intro2_bgtreessmall.4bpp.lz")*/;
extern const u16 gUnknown_085F231C[]/* = INCBIN_U16("graphics/intro/8413E38.gbapal")*/;
extern const u8 gUnknown_085F235C[]/* = INCBIN_U8("graphics/intro/intro2_bgnight.4bpp.lz")*/; // only used in credits, coupled with intro because bicycle sequence
extern const u16 gUnknown_085F2548[]/* = INCBIN_U16("graphics/intro/intro2_bgnight.gbapal")*/;
extern const u8 gUnknown_085F2568[]/* = INCBIN_U8("graphics/intro/intro2_bgnight_map.bin.lz")*/;
extern const u8 gIntro2NightTiles[]/* = INCBIN_U8("graphics/intro/intro2_night.4bpp.lz")*/;
extern const u16 gIntro2BrendanPalette[]/* = INCBIN_U16("graphics/intro/intro2_brendan.gbapal")*/;
extern const u8 gIntro2BrendanTiles[]/* = INCBIN_U8("graphics/intro/intro2_brendan.4bpp.lz")*/;
extern const u16 gIntro2MayPalette[]/* = INCBIN_U16("graphics/intro/intro2_may.gbapal")*/;
extern const u16 gUnknown_08414F90[0xF0]/* = {0}*/;
extern const u8 gIntro2MayTiles[]/* = INCBIN_U8("graphics/intro/intro2_may.4bpp.lz")*/;
extern const u8 gIntro2BicycleTiles[]/* = INCBIN_U8("graphics/intro/intro2_bicycle.4bpp.lz")*/;
extern const u16 gIntro2LatiosPalette[]/* = INCBIN_U16("graphics/intro/intro2_latios.gbapal")*/;
extern const u8 gIntro2LatiosTiles[]/* = INCBIN_U8("graphics/intro/intro2_latios.4bpp.lz")*/;
extern const u16 gIntro2LatiasPalette[]/* = INCBIN_U16("graphics/intro/intro2_latias.gbapal")*/;
extern const u8 gIntro2LatiasTiles[]/* = INCBIN_U8("graphics/intro/intro2_latias.4bpp.lz")*/;

extern const struct CompressedSpriteSheet gUnknown_085F5064[]/* = {
    { gUnknown_085F16A8, 0x400, 2000 },
    {}
}*/;

extern const struct CompressedSpriteSheet gUnknown_085F50EC[]/* = {
    { gIntro2TreeTiles, 0x400, 2000 },
    {}
}*/;

extern const struct CompressedSpriteSheet gUnknown_085F5180[]/* = {
    { gIntro2NightTiles, 0x400, 2000 },
    {}
}*/;

void sub_817B76C();
void sub_817B788();
void sub_817B7A4();

void load_intro_part2_graphics(u8 a)
{
    LZ77UnCompVram(&gUnknown_085F0740, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(&gUnknown_085F0BC0, (void *)(VRAM + 0x7800));
    LoadPalette(&gUnknown_085F06E0, 240, 32);
    switch (a)
    {
    case 0:
    default:
        LZ77UnCompVram(&gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(&gUnknown_085F1398, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F0CFC, 0, 96);
        LoadCompressedObjectPic(gUnknown_085F5064);
        LoadPalette(&gUnknown_085F1668, 256, 32);
        sub_817B76C();
        break;
    case 1:
        LZ77UnCompVram(&gUnknown_085F1824, (void *)(VRAM));
        LZ77UnCompVram(&gUnknown_085F1EAC, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F17E4, 0, 32);
        LoadCompressedObjectPic(gUnknown_085F50EC);
        LoadPalette(&gUnknown_085F21B0, 256, 32);
        sub_817B788();
        break;
    }
    gUnknown_0203BD28 = 0;
    gReservedSpritePaletteCount = 8;
}

void sub_817B150(u8 a)
{
    switch (a)
    {
    default:
    case 0:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    }
}

void sub_817B1C8(u8 a)
{
    LZ77UnCompVram(&gUnknown_085F0740, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(&gUnknown_085F0BC0, (void *)(VRAM + 0x7800));
    switch (a)
    {
    case 0:
    default:
        LoadPalette(&gUnknown_085F06E0, 240, 32);
        LZ77UnCompVram(&gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(&gUnknown_085F1398, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F0CFC, 0, 96);
        LoadCompressedObjectPic(gUnknown_085F5064);
        LZ77UnCompVram(&gUnknown_085F16A8, (void *)(VRAM + 0x10000));
        LoadPalette(&gUnknown_085F1668, 256, 32);
        sub_817B76C();
        break;
    case 1:
        LoadPalette(&gUnknown_085F0700, 240, 32);
        LZ77UnCompVram(&gUnknown_085F0DBC, (void *)(VRAM));
        LZ77UnCompVram(&gUnknown_085F1398, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F0D5C, 0, 96);
        LoadCompressedObjectPic(gUnknown_085F5064);
        LZ77UnCompVram(&gUnknown_085F16A8, (void *)(VRAM + 0x10000));
        LoadPalette(&gUnknown_085F1688, 256, 32);
        sub_817B76C();
        break;
    case 2:
    case 3:
        LoadPalette(&gUnknown_085F0700, 240, 32);
        LZ77UnCompVram(&gUnknown_085F1824, (void *)(VRAM));
        LZ77UnCompVram(&gUnknown_085F1EAC, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F1804, 0, 32);
        LoadCompressedObjectPic(gUnknown_085F50EC);
        LoadPalette(&gUnknown_085F1804, 256, 32);
        sub_817B788();
        break;
    case 4:
        LoadPalette(&gUnknown_085F0720, 240, 32);
        LZ77UnCompVram(&gUnknown_085F235C, (void *)(VRAM));
        LZ77UnCompVram(&gUnknown_085F2568, (void *)(VRAM + 0x3000));
        LoadPalette(&gUnknown_085F231C, 0, 64);
        LoadCompressedObjectPic(gUnknown_085F5180);
        LoadPalette(&gUnknown_085F2548, 256, 32);
        sub_817B7A4();
        break;
    }
    gReservedSpritePaletteCount = 8;
    gUnknown_0203BD28 = 0;
}

void sub_817B3A8(u8 a)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(6)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(15)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG_ALL_ON
                                | DISPCNT_OBJ_ON);
}

u8 sub_817B3DC(u8 a, u16 b, u16 c, u16 d)
{
    u8 taskId = CreateTask(&sub_817B458, 0);

    gTasks[taskId].data[0] = a;
    gTasks[taskId].data[1] = b;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = c;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
    gTasks[taskId].data[7] = d;
    gTasks[taskId].data[8] = 8;
    gTasks[taskId].data[9] = 0;
    sub_817B458(taskId);
    return taskId;
}

#ifdef NONMATCHING
void sub_817B458(u8 taskId)
{
    s16 r4;
    s32 r2;

    r4 = gTasks[taskId].data[1];
    if (r4 != 0)
    {
        r2 = (gTasks[taskId].data[2] << 16) + (u16)gTasks[taskId].data[3];
        r2 -= (u16)r4 << 4;
        gTasks[taskId].data[2] = r2 >> 16;
        gTasks[taskId].data[3] = r2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].data[2]);
        SetGpuReg(REG_OFFSET_BG1VOFS, gUnknown_0203BD24 + gUnknown_0203BD26);
    }

    r4 = gTasks[taskId].data[4];
    if (r4 != 0)
    {
        r2 = (gTasks[taskId].data[5] << 16) + (u16)gTasks[taskId].data[6];
        r2 -= (u16)r4 << 4;
        gTasks[taskId].data[5] = r2 >> 16;
        gTasks[taskId].data[6] = r2;
        SetGpuReg(REG_OFFSET_BG2HOFS, gTasks[taskId].data[5]);
        if (gTasks[taskId].data[0] != 0)
            SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_0203BD24 + gUnknown_0203BD26);
        else
            SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_0203BD24);
    }

    r4 = gTasks[taskId].data[7];
    if (r4 != 0)
    {
        r2 = (gTasks[taskId].data[8] << 16) + (u16)gTasks[taskId].data[9];
        r2 -= (u16)r4 << 4;
        gTasks[taskId].data[8] = r2 >> 16;
        gTasks[taskId].data[9] = r2;
        SetGpuReg(REG_OFFSET_BG3HOFS, gTasks[taskId].data[8]);
        SetGpuReg(REG_OFFSET_BG3VOFS, gUnknown_0203BD24);
    }
}
#else
ASM_DIRECT
void sub_817B458(u8 taskId)
{
    asm("push {r4,r5,lr}\n\
	lsl r0, #24\n\
	lsr r5, r0, #24\n\
	ldr r1, =gTasks\n\
	lsl r0, r5, #2\n\
	add r0, r5\n\
	lsl r0, #3\n\
	add r4, r0, r1\n\
	ldrh r0, [r4, #0xA]\n\
	lsl r2, r0, #16\n\
	cmp r2, #0\n\
	beq _0817B4A0\n\
	mov r1, #0xC\n\
	ldrsh r0, [r4, r1]\n\
	lsl r0, #16\n\
	ldrh r1, [r4, #0xE]\n\
	add r1, r0, r1\n\
	lsr r0, r2, #12\n\
	sub r1, r0\n\
	asr r0, r1, #16\n\
	strh r0, [r4, #0xC]\n\
	strh r1, [r4, #0xE]\n\
	ldrh r1, [r4, #0xC]\n\
	mov r0, #0x14\n\
	bl SetGpuReg\n\
	ldr r2, =gUnknown_0203BD24\n\
	ldr r0, =gUnknown_0203BD26\n\
	ldrh r1, [r0]\n\
	ldrh r2, [r2]\n\
	add r1, r2\n\
	lsl r1, #16\n\
	lsr r1, #16\n\
	mov r0, #0x16\n\
	bl SetGpuReg\n\
_0817B4A0:\n\
	ldrh r0, [r4, #0x10]\n\
	lsl r2, r0, #16\n\
	cmp r2, #0\n\
	beq _0817B4FA\n\
	mov r1, #0x12\n\
	ldrsh r0, [r4, r1]\n\
	lsl r0, #16\n\
	ldrh r1, [r4, #0x14]\n\
	add r1, r0, r1\n\
	lsr r0, r2, #12\n\
	sub r1, r0\n\
	asr r0, r1, #16\n\
	strh r0, [r4, #0x12]\n\
	strh r1, [r4, #0x14]\n\
	ldrh r1, [r4, #0x12]\n\
	mov r0, #0x18\n\
	bl SetGpuReg\n\
	mov r1, #0x8\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0\n\
	beq _0817B4F0\n\
	ldr r2, =gUnknown_0203BD24\n\
	ldr r0, =gUnknown_0203BD26\n\
	ldrh r1, [r0]\n\
	ldrh r2, [r2]\n\
	add r1, r2\n\
	lsl r1, #16\n\
	lsr r1, #16\n\
	mov r0, #0x1A\n\
	bl SetGpuReg\n\
	b _0817B4FA\n\
	.pool\n\
_0817B4F0:\n\
	ldr r0, =gUnknown_0203BD24\n\
	ldrh r1, [r0]\n\
	mov r0, #0x1A\n\
	bl SetGpuReg\n\
_0817B4FA:\n\
	ldr r0, =gTasks\n\
	lsl r1, r5, #2\n\
	add r1, r5\n\
	lsl r1, #3\n\
	add r2, r1, r0\n\
	ldrh r0, [r2, #0x16]\n\
	lsl r3, r0, #16\n\
	cmp r3, #0\n\
	beq _0817B532\n\
	mov r1, #0x18\n\
	ldrsh r0, [r2, r1]\n\
	lsl r0, #16\n\
	ldrh r1, [r2, #0x1A]\n\
	add r1, r0, r1\n\
	lsr r0, r3, #12\n\
	sub r1, r0\n\
	asr r0, r1, #16\n\
	strh r0, [r2, #0x18]\n\
	strh r1, [r2, #0x1A]\n\
	ldrh r1, [r2, #0x18]\n\
	mov r0, #0x1C\n\
	bl SetGpuReg\n\
	ldr r0, =gUnknown_0203BD24\n\
	ldrh r1, [r0]\n\
	mov r0, #0x1E\n\
	bl SetGpuReg\n\
_0817B532:\n\
	pop {r4,r5}\n\
	pop {r0}\n\
	bx r0\n\
	.pool");
}
#endif // NONMATCHING

void sub_817B540(u8 mode)
{
    u16 x;
    u16 y;
    switch (mode)
    {
        case 0:
        default:
            /* stuff */
            if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
                break;
            if (gMain.vblankCounter1 & 4)
            {
                x = gPlttBufferUnfaded[9];
                y = gPlttBufferUnfaded[10];
            }
            else
            {
                x = gPlttBufferUnfaded[10];
                y = gPlttBufferUnfaded[9];
            }
            LoadPalette(&x, 9, 2);
            LoadPalette(&y, 10, 2);
            break;
        case 2:
            if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
                break;
            if (gMain.vblankCounter1 & 4)
            {
                x = 0x3D27;
                y = 0x295;
            }
            else
            {
                x = 0x31C;
                y = 0x3D27;
            }
            LoadPalette(&x, 12, 2);
            LoadPalette(&y, 13, 2);
            break;
        case 1:
            break;
    }
}

void sub_817B62C(struct Sprite *sprite)
{
    s32 var;
    s16 var2 = gUnknown_0203BD28;
    
    if (var2 != 2)
    {
        switch (var2)
        {
        default:
            DestroySprite(sprite);
            break;
        case 0:
            var = ((sprite->pos1.x << 16) | (u16)sprite->data[2]) + (u16)sprite->data[1];
            sprite->pos1.x = var >> 16;
            sprite->data[2] = var;
            if (sprite->pos1.x > 0xFF)
                sprite->pos1.x = -0x20;
            if (sprite->data[0])
                sprite->pos2.y = -(gUnknown_0203BD24 + gUnknown_0203BD26);
            else
                sprite->pos2.y = -gUnknown_0203BD24;
            break;
        }
    }
}
