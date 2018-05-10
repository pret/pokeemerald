#include "global.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "bg.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_map_obj.h"
#include "fieldmap.h"
#include "global.fieldmap.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "menu.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"

#define MIRAGE_TOWER_GFX_LENGTH (sizeof(gUnknown_08617274) + sizeof(gMirageTower_Gfx))
#define MIRAGE_TOWER_PALETTE_LENGTH 0x800
#define ROOT_FOSSIL_GFX_LENGTH sizeof(gRootFossil_Gfx)
#define ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH 0x100

//struct
struct Struct8617DA4 {
    u8 x;
    u8 y;
    u16 tileId;
};

struct Struct203CF10 {
    u8 *buffer;
    u8 curr_buffer_index;
};

struct DynamicSpriteFrameImage{
    u8 *data;
    u16 size;
};

struct Struct203CF0C {
    u8 *frameImageTiles;
    struct DynamicSpriteFrameImage *frameImage;
    u8 spriteId;
    u16 *unkC;
    u16 unk10;
};

// static functions
static void sub_81BED50(u8 taskId);
static void sub_81BEBF4(u8 taskId);
static void sub_81BF028(u8 taskId);
static void sub_81BF248(struct Sprite *);
/*static*/ void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e);

// .rodata
static const u8 gUnknown_08617274[] = {00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00};
static const u8 gMirageTower_Gfx[] = INCBIN_U8("graphics/misc/mirage_tower.4bpp");
static const u16 gUnknown_08617B94[] = INCBIN_U16("graphics/misc/mirage_tower.bin");
static const u16 gRootFossil_Pal[] = INCBIN_U16("graphics/misc/fossil.gbapal");
static const u8 gRootFossil_Gfx[] = INCBIN_U8("graphics/misc/fossil.4bpp");
static const u8 gMirageTowerCrumbles_Gfx[] = INCBIN_U8("graphics/misc/mirage_tower_crumbles.4bpp");
static const u16 gMirageTowerCrumbles_Palette[] = INCBIN_U16("graphics/misc/mirage_tower_crumbles.gbapal");

const s16 gUnknown_08617D64[][3] =
    {
        {  0,  10,  65},
        { 17,   3,  50},
        {-12,   0,  75},
        { 10,  15,  90},
        {  7,   8,  65},
        {-18,   5,  75},
        { 22, -10,  55},
        {-24,  -4,  65},
    };

const struct SpriteSheet gUnknown_08617D94[] =
{
    {gMirageTowerCrumbles_Gfx, 0x0080, 0x0fa0},
    {NULL}
};

static const struct Struct8617DA4 gUnknown_08617DA4[] =
    {
        {0x12, 0x35, 0x251},
        {0x13, 0x35, 0x251},
        {0x14, 0x35, 0x251},
        {0x12, 0x36, 0x251},
        {0x13, 0x36, 0x251},
        {0x14, 0x36, 0x251},
        {0x12, 0x37, 0x251},
        {0x13, 0x37, 0x251},
        {0x14, 0x37, 0x251},
        {0x12, 0x38, 0x251},
        {0x13, 0x38, 0x251},
        {0x14, 0x38, 0x251},
        {0x12, 0x39, 0x259},
        {0x13, 0x39, 0x259},
        {0x14, 0x39, 0x259},
        {0x12, 0x3A, 0x121},
        {0x13, 0x3A, 0x121},
        {0x14, 0x3A, 0x121},
    };

static const union AnimCmd gSpriteAnim_8617DEC[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const struct OamData gOamData_8617DF4 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 3,
    .affineParam = 0,
};

static const union AnimCmd *const gSpriteAnimTable_8617DFC[] =
{
    gSpriteAnim_8617DEC,
};

static const struct SpriteTemplate gUnknown_08617E00 = {
    0xFFFF, 0xFFFF, &gOamData_8617DF4, gSpriteAnimTable_8617DFC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
};

// ewram
EWRAM_DATA u8* gUnknown_0203CF04 = NULL;
EWRAM_DATA u8* gUnknown_0203CF08 = NULL;
EWRAM_DATA struct Struct203CF0C *gUnknown_0203CF0C = NULL;
EWRAM_DATA struct Struct203CF10 *gUnknown_0203CF10 = NULL;
EWRAM_DATA u16 *gUnknown_0203CF14 = NULL;

// iwram
IWRAM_DATA u16 gUnknown_030012A8[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// text
void sub_81BEB24(void)
{
    u8 i;
    for(i = 0; i < (sizeof(gUnknown_08617DA4)/sizeof(gUnknown_08617DA4[0])); i++)
        MapGridSetMetatileIdAt(gUnknown_08617DA4[i].x + 7, gUnknown_08617DA4[i].y + 7, gUnknown_08617DA4[i].tileId);
    DrawWholeMapView();
}

void sub_81BEB54(void)
{
    CreateTask(sub_81BED50, 0x9);
}

void sub_81BEB68(void)
{
    CreateTask(sub_81BEBF4, 0x9);
}

void sub_81BEB7C(void)
{
    CreateTask(sub_81BF028, 0x9);
}

void sub_81BEB90(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gUnknown_0203CF14[0]);
    SetGpuReg(REG_OFFSET_BG0VOFS, gUnknown_0203CF14[1]);
}

void sub_81BEBB4(u8 taskId)
{
    if(!(gTasks[taskId].data[0]))
    {
        gUnknown_0203CF14[0] = -gUnknown_0203CF14[0];
        gTasks[taskId].data[0] = 2;
        sub_81BEB90();
    }
    else
        gTasks[taskId].data[0]--;
}

static void sub_81BEBF4(u8 taskId)
{
    u8 zero;

    switch(gTasks[taskId].data[0])
    {
    case 0:
        FreeAllWindowBuffers();
        SetBgAttribute(0, BG_CTRL_ATTR_MOSAIC, 2);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gUnknown_0203CF04 = (u8 *)AllocZeroed(MIRAGE_TOWER_GFX_LENGTH);
        gUnknown_0203CF08 = (u8 *)AllocZeroed(MIRAGE_TOWER_PALETTE_LENGTH);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        CpuSet(gUnknown_08617274, gUnknown_0203CF04, MIRAGE_TOWER_GFX_LENGTH / 2);
        LoadBgTiles(0, gUnknown_0203CF04, MIRAGE_TOWER_GFX_LENGTH, 0);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        SetBgTilemapBuffer(0, gUnknown_0203CF08);
        CopyToBgTilemapBufferRect_ChangePalette(0, &gUnknown_08617B94, 12, 29, 6, 12, 17);
        CopyBgTilemapBufferToVram(0);
        gTasks[taskId].data[0]++;
        break;
    case 4:
        ShowBg(0);
        gTasks[taskId].data[0]++;
        break;
    case 5:
        sub_81BEB24();
        gTasks[taskId].data[0]++;
        break;
    case 6:
        gUnknown_0203CF14 = (u16 *)Alloc(4);
        zero = 0;
        gUnknown_0203CF14[0] = 2;
        gUnknown_0203CF14[1] = zero;
        CreateTask(sub_81BEBB4, 0xA);
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
}

#ifdef NONMATCHING
#define OUTER_BUFFER_LENGTH 0x60
#define INNER_BUFFER_LENGTH 0x30
static void sub_81BED50(u8 taskId)
{
    u8 anotherTaskId, j;


    switch(gTasks[taskId].data[0])
    {
    case 1:
        gUnknown_0203CF10 = (struct Struct203CF10 *)AllocZeroed(OUTER_BUFFER_LENGTH * sizeof(struct Struct203CF10));
        break;
    case 3:
        {
            u16 i;
            u16 left;
            u32 index, next;

            index = (u16)gTasks[taskId].data[3];
            if(gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
            {
                if(gTasks[taskId].data[1] > 1)
                {
                    index = (u8)index;
                    gUnknown_0203CF10[index].buffer = (u8 *)Alloc(INNER_BUFFER_LENGTH);
                    for(i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                        gUnknown_0203CF10[index].buffer[i] = i;
                    for(i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                    {
                        u16 rand1, rand2, temp;

                        rand1 = Random() % 0x30;
                        rand2 = Random() % 0x30;
                        temp = gUnknown_0203CF10[index].buffer[rand2];
                        gUnknown_0203CF10[index].buffer[rand2] = gUnknown_0203CF10[index].buffer[rand1];
                        gUnknown_0203CF10[index].buffer[rand1] = temp;
                    }
                    if(gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
                        gTasks[taskId].data[3]++;
                    gTasks[taskId].data[1] = 0;
                }
                gTasks[taskId].data[1]++;
            }
            index = (u8)gTasks[taskId].data[3];
            for(left = (u8)gTasks[taskId].data[2]; left < (u16)index; left = next)
            {
                j = 0;
                next = left + 1;
                while(!j)
                {
                    sub_81BF2B8(gUnknown_0203CF04, ((((OUTER_BUFFER_LENGTH - 1) - left) * INNER_BUFFER_LENGTH) + gUnknown_0203CF10[left].buffer[(gUnknown_0203CF10[left].curr_buffer_index)++]), 0, INNER_BUFFER_LENGTH, 1);
                    j++;
                }
                if(gUnknown_0203CF10[left].curr_buffer_index > (INNER_BUFFER_LENGTH - 1))
                {
                    FREE_AND_SET_NULL(gUnknown_0203CF10[left].buffer);
                    gTasks[taskId].data[2]++;
                    if((left % 2) ==  1)
                        gUnknown_0203CF14[1]--;
                }
            }
            LoadBgTiles(0, gUnknown_0203CF04, MIRAGE_TOWER_GFX_LENGTH, 0);
            if(gUnknown_0203CF10[OUTER_BUFFER_LENGTH - 1].curr_buffer_index > (INNER_BUFFER_LENGTH - 1))
                break;
            return;
        }
    case 4:
        UnsetBgTilemapBuffer(0);
        anotherTaskId = FindTaskIdByFunc(sub_81BEBB4);
        if(anotherTaskId != 0xFF)
            DestroyTask(anotherTaskId);
        gUnknown_0203CF14[1] = gUnknown_0203CF14[0] = 0;
        sub_81BEB90();
        break;
    case 5:
        FREE_AND_SET_NULL(gUnknown_0203CF14);
        FREE_AND_SET_NULL(gUnknown_0203CF10);
        FREE_AND_SET_NULL(gUnknown_0203CF04);
        FREE_AND_SET_NULL(gUnknown_0203CF08);
        break;
    case 6:
        SetGpuRegBits(REG_OFFSET_BG2CNT, 0x2);
        SetGpuRegBits(REG_OFFSET_BG0CNT, 0x0);
        SetBgAttribute(0, BG_CTRL_ATTR_MOSAIC, 0);
        sub_81971D0();
        break;
    case 7:
        ShowBg(0);
        break;
    case 8:
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
    gTasks[taskId].data[0]++;
}

#else
NAKED
static void sub_81BED50(u8 taskId)
{
    asm("\n\
        .syntax unified\n\
        push {r4-r7,lr}\n\
        mov r7, r10\n\
        mov r6, r9\n\
        mov r5, r8\n\
        push {r5-r7}\n\
        sub sp, 0x10\n\
        lsls r0, 24\n\
        lsrs r0, 24\n\
        mov r10, r0\n\
        ldr r1, =gTasks\n\
        lsls r0, 2\n\
        add r0, r10\n\
        lsls r0, 3\n\
        adds r0, r1\n\
        ldrh r0, [r0, 0x8]\n\
        subs r0, 0x1\n\
        lsls r0, 16\n\
        asrs r0, 16\n\
        adds r6, r1, 0\n\
        cmp r0, 0x7\n\
        bls _081BED7C\n\
        b _081BF002\n\
    _081BED7C:\n\
        lsls r0, 2\n\
        ldr r1, =_081BED90\n\
        adds r0, r1\n\
        ldr r0, [r0]\n\
        mov pc, r0\n\
        .pool\n\
        .align 2, 0\n\
    _081BED90:\n\
        .4byte _081BEDB0\n\
        .4byte _081BF002\n\
        .4byte _081BEDC4\n\
        .4byte _081BEF64\n\
        .4byte _081BEF94\n\
        .4byte _081BEFD0\n\
        .4byte _081BEFF0\n\
        .4byte _081BEFF8\n\
    _081BEDB0:\n\
        ldr r4, =gUnknown_0203CF10\n\
        movs r0, 0xC0\n\
        lsls r0, 2\n\
        bl AllocZeroed\n\
        str r0, [r4]\n\
        b _081BF002\n\
        .pool\n\
    _081BEDC4:\n\
        mov r1, r10\n\
        lsls r0, r1, 2\n\
        adds r1, r0, r1\n\
        lsls r1, 3\n\
        adds r2, r1, r6\n\
        ldrh r3, [r2, 0xE]\n\
        movs r4, 0xE\n\
        ldrsh r1, [r2, r4]\n\
        str r0, [sp, 0x8]\n\
        cmp r1, 0x5F\n\
        bgt _081BEE8A\n\
        movs r1, 0xA\n\
        ldrsh r0, [r2, r1]\n\
        cmp r0, 0x1\n\
        ble _081BEE7C\n\
        lsls r0, r3, 24\n\
        lsrs r4, r0, 24\n\
        movs r0, 0x30\n\
        bl Alloc\n\
        ldr r3, =gUnknown_0203CF10\n\
        ldr r1, [r3]\n\
        lsls r2, r4, 3\n\
        adds r1, r2, r1\n\
        str r0, [r1]\n\
        movs r5, 0\n\
        adds r4, r2, 0\n\
    _081BEDFA:\n\
        ldr r0, [r3]\n\
        adds r0, r4, r0\n\
        ldr r0, [r0]\n\
        adds r0, r5\n\
        strb r5, [r0]\n\
        adds r0, r5, 0x1\n\
        lsls r0, 16\n\
        lsrs r5, r0, 16\n\
        cmp r5, 0x2F\n\
        bls _081BEDFA\n\
        movs r5, 0\n\
        ldr r7, =gUnknown_0203CF10\n\
        adds r6, r2, 0\n\
    _081BEE14:\n\
        bl Random\n\
        lsls r0, 16\n\
        lsrs r0, 16\n\
        movs r1, 0x30\n\
        bl __umodsi3\n\
        adds r4, r0, 0\n\
        lsls r4, 16\n\
        lsrs r4, 16\n\
        bl Random\n\
        lsls r0, 16\n\
        lsrs r0, 16\n\
        movs r1, 0x30\n\
        bl __umodsi3\n\
        lsls r0, 16\n\
        lsrs r0, 16\n\
        ldr r1, [r7]\n\
        adds r1, r6, r1\n\
        ldr r1, [r1]\n\
        adds r0, r1, r0\n\
        ldrb r2, [r0]\n\
        adds r1, r4 \n\
        ldrb r1, [r1]\n\
        strb r1, [r0]\n\
        ldr r0, [r7]\n\
        adds r0, r6, r0\n\
        ldr r0, [r0]\n\
        adds r0, r4\n\
        strb r2, [r0]\n\
        adds r0, r5, 0x1\n\
        lsls r0, 16\n\
        lsrs r5, r0, 16\n\
        cmp r5, 0x2F\n\
        bls _081BEE14\n\
        ldr r0, =gTasks\n\
        ldr r1, [sp, 0x8]\n\
        add r1, r10\n\
        lsls r1, 3\n\
        adds r2, r1, r0\n\
        ldrh r3, [r2, 0xE]\n\
        movs r4, 0xE\n\
        ldrsh r1, [r2, r4]\n\
        adds r6, r0, 0\n\
        cmp r1, 0x5F\n\
        bgt _081BEE78\n\
        adds r0, r3, 0x1\n\
        strh r0, [r2, 0xE]\n\
    _081BEE78:\n\
        movs r0, 0\n\
        strh r0, [r2, 0xA]\n\
    _081BEE7C:\n\
        ldr r1, [sp, 0x8]\n\
        add r1, r10\n\
        lsls r1, 3\n\
        adds r1, r6\n\
        ldrh r0, [r1, 0xA]\n\
        adds r0, 0x1\n\
        strh r0, [r1, 0xA]\n\
    _081BEE8A:\n\
        ldr r0, [sp, 0x8]\n\
        add r0, r10\n\
        lsls r0, 3\n\
        adds r0, r6\n\
        ldrb r4, [r0, 0xE]\n\
        ldrb r5, [r0, 0xC]\n\
        lsls r0, r4, 16\n\
        cmp r5, r4\n\
        bcs _081BEF32\n\
        str r0, [sp, 0xC]\n\
    _081BEE9E:\n\
        movs r6, 0\n\
        adds r0, r5, 0x1\n\
        str r0, [sp, 0x4]\n\
        lsls r4, r5, 3\n\
        movs r2, 0x5F\n\
        subs r1, r2, r5\n\
        lsls r0, r1, 1\n\
        adds r0, r1\n\
        lsls r0, 4\n\
        mov r9, r0\n\
    _081BEEB2:\n\
        ldr r0, =gUnknown_0203CF04\n\
        ldr r0, [r0]\n\
        ldr r7, =gUnknown_0203CF10\n\
        ldr r3, [r7]\n\
        adds r3, r4, r3\n\
        ldrb r2, [r3, 0x4]\n\
        adds r1, r2, 0x1\n\
        strb r1, [r3, 0x4]\n\
        lsls r2, 24\n\
        lsrs r2, 24\n\
        ldr r1, [r3]\n\
        adds r1, r2\n\
        ldrb r1, [r1]\n\
        add r1, r9\n\
        lsls r1, 16\n\
        lsrs r1, 16\n\
        movs r2, 0x1\n\
        mov r8, r2\n\
        str r2, [sp]\n\
        movs r2, 0\n\
        movs r3, 0x30\n\
        bl sub_81BF2B8\n\
        adds r0, r6, 0x1\n\
        lsls r0, 24\n\
        lsrs r6, r0, 24\n\
        cmp r6, 0\n\
        beq _081BEEB2\n\
        ldr r0, [r7]\n\
        adds r1, r4, r0\n\
        ldrb r0, [r1, 0x4]\n\
        cmp r0, 0x2F\n\
        bls _081BEF24\n\
        ldr r0, [r1]\n\
        bl Free\n\
        ldr r0, [r7]\n\
        adds r0, r4, r0\n\
        movs r1, 0\n\
        str r1, [r0]\n\
        ldr r1, [sp, 0x8]\n\
        add r1, r10\n\
        lsls r1, 3\n\
        ldr r4, =gTasks\n\
        adds r1, r4\n\
        ldrh r0, [r1, 0xC]\n\
        adds r0, 0x1\n\
        strh r0, [r1, 0xC]\n\
        mov r0, r8\n\
        ands r5, r0\n\
        cmp r5, 0x1\n\
        bne _081BEF24\n\
        ldr r0, =gUnknown_0203CF14\n\
        ldr r1, [r0]\n\
        ldrh r0, [r1, 0x2]\n\
        subs r0, 0x1\n\
        strh r0, [r1, 0x2]\n\
    _081BEF24:\n\
        ldr r1, [sp, 0x4]\n\
        lsls r0, r1, 16\n\
        lsrs r5, r0, 16\n\
        ldr r2, [sp, 0xC]\n\
        lsrs r0, r2, 16\n\
        cmp r5, r0\n\
        bcc _081BEE9E\n\
    _081BEF32:\n\
        ldr r0, =gUnknown_0203CF04\n\
        ldr r1, [r0]\n\
        movs r2, 0x92\n\
        lsls r2, 4\n\
        movs r0, 0\n\
        movs r3, 0\n\
        bl LoadBgTiles\n\
        ldr r0, =gUnknown_0203CF10\n\
        ldr r0, [r0]\n\
        movs r4, 0xBE\n\
        lsls r4, 2\n\
        adds r0, r4\n\
        ldrb r0, [r0, 0x4]\n\
        cmp r0, 0x2F\n\
        bhi _081BF002\n\
        b _081BF014\n\
        .pool\n\
    _081BEF64:\n\
        movs r0, 0\n\
        bl UnsetBgTilemapBuffer\n\
        ldr r0, =sub_81BEBB4\n\
        bl FindTaskIdByFunc\n\
        lsls r0, 24\n\
        lsrs r0, 24\n\
        cmp r0, 0xFF\n\
        beq _081BEF7C\n\
        bl DestroyTask\n\
    _081BEF7C:\n\
        ldr r0, =gUnknown_0203CF14\n\
        ldr r1, [r0]\n\
        movs r0, 0\n\
        strh r0, [r1]\n\
        strh r0, [r1, 0x2]\n\
        bl sub_81BEB90\n\
        b _081BF002\n\
        .pool\n\
    _081BEF94:\n\
        ldr r4, =gUnknown_0203CF14\n\
        ldr r0, [r4]\n\
        bl Free\n\
        movs r5, 0\n\
        str r5, [r4]\n\
        ldr r4, =gUnknown_0203CF10\n\
        ldr r0, [r4]\n\
        bl Free\n\
        str r5, [r4]\n\
        ldr r4, =gUnknown_0203CF04\n\
        ldr r0, [r4]\n\
        bl Free\n\
        str r5, [r4]\n\
        ldr r4, =gUnknown_0203CF08\n\
        ldr r0, [r4]\n\
        bl Free\n\
        str r5, [r4]\n\
        b _081BF002\n\
        .pool\n\
    _081BEFD0:\n\
        movs r0, 0xC\n\
        movs r1, 0x2\n\
        bl SetGpuRegBits\n\
        movs r0, 0x8\n\
        movs r1, 0\n\
        bl SetGpuRegBits\n\
        movs r0, 0\n\
        movs r1, 0x7\n\
        movs r2, 0\n\
        bl SetBgAttribute\n\
        bl sub_81971D0\n\
        b _081BF002\n\
    _081BEFF0:\n\
        movs r0, 0\n\
        bl ShowBg\n\
        b _081BF002\n\
    _081BEFF8:\n\
        mov r0, r10\n\
        bl DestroyTask\n\
        bl EnableBothScriptContexts\n\
    _081BF002:\n\
        ldr r0, =gTasks\n\
        mov r2, r10\n\
        lsls r1, r2, 2\n\
        add r1, r10\n\
        lsls r1, 3\n\
        adds r1, r0\n\
        ldrh r0, [r1, 0x8]\n\
        adds r0, 0x1\n\
        strh r0, [r1, 0x8]\n\
    _081BF014:\n\
        add sp, 0x10\n\
        pop {r3-r5}\n\
        mov r8, r3\n\
        mov r9, r4\n\
        mov r10, r5\n\
        pop {r4-r7}\n\
        pop {r0}\n\
        bx r0\n\
        .pool\n\
        .syntax divided");
}
#endif // NONMATCHING

static void sub_81BF028(u8 taskId)
{
    u16 i;

    switch(gTasks[taskId].data[0])
    {
    case 1:
        gUnknown_0203CF0C = (struct Struct203CF0C *)AllocZeroed(sizeof(struct Struct203CF0C));
        gUnknown_0203CF0C->frameImageTiles = (u8 *)AllocZeroed(ROOT_FOSSIL_GFX_LENGTH);
        gUnknown_0203CF0C->frameImage = (struct DynamicSpriteFrameImage *) AllocZeroed(sizeof(struct DynamicSpriteFrameImage));
        gUnknown_0203CF0C->unkC = (u16 *)AllocZeroed(ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16));
        gUnknown_0203CF0C->unk10 = 0;
        break;
    case 2:
        {
            u8 *buffer;
            buffer = gUnknown_0203CF0C->frameImageTiles;
            for(i = 0; i < ROOT_FOSSIL_GFX_LENGTH; i++, buffer++)
                *buffer = gRootFossil_Gfx[i];
        }
        break;
    case 3:
        gUnknown_0203CF0C->frameImage->data = gUnknown_0203CF0C->frameImageTiles;
        gUnknown_0203CF0C->frameImage->size = ROOT_FOSSIL_GFX_LENGTH;
        break;
    case 4:
        {
            u8 spriteId, zero;
            struct SpriteTemplate fossilTemplate;

            fossilTemplate = gUnknown_08617E00;
            fossilTemplate.images = (struct SpriteFrameImage *)(gUnknown_0203CF0C->frameImage);
            spriteId = CreateSprite(&fossilTemplate, 128, -16, 1);
            gUnknown_0203CF0C->spriteId = spriteId;
            zero = 0;
            gSprites[gUnknown_0203CF0C->spriteId].centerToCornerVecX = zero;
            gSprites[gUnknown_0203CF0C->spriteId].data[0] = gSprites[gUnknown_0203CF0C->spriteId].pos1.x;
            gSprites[gUnknown_0203CF0C->spriteId].data[1] = 1;
        }
    case 5:
        for(i = 0; i < ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH; i++)
            gUnknown_0203CF0C->unkC[i] = i;
        break;
    case 6:
        {
            u16 rand1, rand2, temp, j;
            j = (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16)) - 1;
            for(i = 0; i <= j; i++)
            {
                rand1 = Random() % 0x100;
                rand2 = Random() % 0x100;
                j = (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16)) - 1;
                temp = gUnknown_0203CF0C->unkC[rand2];
                gUnknown_0203CF0C->unkC[rand2] = gUnknown_0203CF0C->unkC[rand1];
                gUnknown_0203CF0C->unkC[rand1] = temp;
            }
            gSprites[gUnknown_0203CF0C->spriteId].callback = sub_81BF248;
            break;
        }
    case 7:
        if(gSprites[gUnknown_0203CF0C->spriteId].callback != SpriteCallbackDummy)
            return;
        DestroySprite(&gSprites[gUnknown_0203CF0C->spriteId]);
        FREE_AND_SET_NULL(gUnknown_0203CF0C->unkC);;
        FREE_AND_SET_NULL(gUnknown_0203CF0C->frameImage);
        FREE_AND_SET_NULL(gUnknown_0203CF0C->frameImageTiles);
        FREE_AND_SET_NULL(gUnknown_0203CF0C);
        break;
    case 8:
        EnableBothScriptContexts();
    }
    ++gTasks[taskId].data[0];
}

static void sub_81BF248(struct Sprite *sprite)
{
    if (gUnknown_0203CF0C->unk10 >= (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH))
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else if (sprite->pos1.y >= 0x60)
    {
        u8 i;
        for (i = 0; i < 2; i++)
        {
            sub_81BF2B8(gUnknown_0203CF0C->frameImageTiles, gUnknown_0203CF0C->unkC[gUnknown_0203CF0C->unk10++], 0, 16, 0);
        }
        StartSpriteAnim(sprite, 0);
    }
    else
    {
        sprite->pos1.y++;
    }
}
