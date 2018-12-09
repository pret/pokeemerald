#include "global.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "bg.h"
#include "event_data.h"
#include "field_camera.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "global.fieldmap.h"
#include "gpu_regs.h"
#include "alloc.h"
#include "menu.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"

#define MIRAGE_TOWER_GFX_LENGTH (32 + sizeof(gMirageTower_Gfx))
#define MIRAGE_TOWER_PALETTE_LENGTH 0x800
#define ROOT_FOSSIL_GFX_LENGTH sizeof(gRootFossil_Gfx)
#define ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH 0x100

struct Struct8617DA4
{
    u8 x;
    u8 y;
    u16 tileId;
};

struct Struct203CF10
{
    u8 *buffer;
    u8 currIndex;
};

struct DynamicSpriteFrameImage
{
    u8 *data;
    u16 size;
};

struct Struct203CF0C
{
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
static void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e);

// .rodata
static const u8 gUnknown_08617274[32] = {0};
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

static const struct SpriteTemplate gUnknown_08617E00 =
{
    0xFFFF, 0xFFFF, &gOamData_8617DF4, gSpriteAnimTable_8617DFC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
};

// EWRAM
EWRAM_DATA static u8* sUnknown_0203CF04 = NULL;
EWRAM_DATA static u8* sUnknown_0203CF08 = NULL;
EWRAM_DATA static struct Struct203CF0C *sUnknown_0203CF0C = NULL;
EWRAM_DATA static struct Struct203CF10 *sUnknown_0203CF10 = NULL;
EWRAM_DATA static u16 *sUnknown_0203CF14 = NULL;

// IWRAM bss
IWRAM_DATA static u16 gUnknown_030012A8[8];

// text
void sub_81BEB24(void)
{
    u8 i;
    for (i = 0; i < (sizeof(gUnknown_08617DA4)/sizeof(gUnknown_08617DA4[0])); i++)
        MapGridSetMetatileIdAt(gUnknown_08617DA4[i].x + 7, gUnknown_08617DA4[i].y + 7, gUnknown_08617DA4[i].tileId);
    DrawWholeMapView();
}

void sub_81BEB54(void)
{
    CreateTask(sub_81BED50, 9);
}

void sub_81BEB68(void)
{
    CreateTask(sub_81BEBF4, 9);
}

void sub_81BEB7C(void)
{
    CreateTask(sub_81BF028, 9);
}

void sub_81BEB90(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, sUnknown_0203CF14[0]);
    SetGpuReg(REG_OFFSET_BG0VOFS, sUnknown_0203CF14[1]);
}

void sub_81BEBB4(u8 taskId)
{
    if (!(gTasks[taskId].data[0]))
    {
        sUnknown_0203CF14[0] = -sUnknown_0203CF14[0];
        gTasks[taskId].data[0] = 2;
        sub_81BEB90();
    }
    else
    {
        gTasks[taskId].data[0]--;
    }
}

static void sub_81BEBF4(u8 taskId)
{
    u8 zero;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        FreeAllWindowBuffers();
        SetBgAttribute(0, BG_CTRL_ATTR_MOSAIC, 2);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        sUnknown_0203CF04 = (u8 *)AllocZeroed(MIRAGE_TOWER_GFX_LENGTH);
        sUnknown_0203CF08 = (u8 *)AllocZeroed(MIRAGE_TOWER_PALETTE_LENGTH);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        CpuSet(gUnknown_08617274, sUnknown_0203CF04, MIRAGE_TOWER_GFX_LENGTH / 2);
        LoadBgTiles(0, sUnknown_0203CF04, MIRAGE_TOWER_GFX_LENGTH, 0);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        SetBgTilemapBuffer(0, sUnknown_0203CF08);
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
        sUnknown_0203CF14 = Alloc(4);
        zero = 0;
        sUnknown_0203CF14[0] = 2;
        sUnknown_0203CF14[1] = zero;
        CreateTask(sub_81BEBB4, 0xA);
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
}

#define OUTER_BUFFER_LENGTH 0x60
#define INNER_BUFFER_LENGTH 0x30
static void sub_81BED50(u8 taskId)
{
    u8 anotherTaskId, j;
    u16 i;
    u8 index;

    switch (gTasks[taskId].data[0])
    {
    case 1:
        sUnknown_0203CF10 = AllocZeroed(OUTER_BUFFER_LENGTH * sizeof(struct Struct203CF10));
        break;
    case 3:
        if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
        {
            if (gTasks[taskId].data[1] > 1)
            {
                index = gTasks[taskId].data[3];
                sUnknown_0203CF10[index].buffer = Alloc(INNER_BUFFER_LENGTH);
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                    sUnknown_0203CF10[index].buffer[i] = i;
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                {
                    u16 rand1, rand2, temp;

                    rand1 = Random() % 0x30;
                    rand2 = Random() % 0x30;
                    SWAP(sUnknown_0203CF10[index].buffer[rand2], sUnknown_0203CF10[index].buffer[rand1], temp);
                }
                if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
                    gTasks[taskId].data[3]++;
                gTasks[taskId].data[1] = 0;
            }
            gTasks[taskId].data[1]++;
        }
        index = gTasks[taskId].data[3];
        for (i = (u8)(gTasks[taskId].data[2]); i < index; i++)
        {
            for (j = 0; j < 1; j++)
            {
                sub_81BF2B8(sUnknown_0203CF04,
                            ((((OUTER_BUFFER_LENGTH - 1) - i) * INNER_BUFFER_LENGTH) + sUnknown_0203CF10[i].buffer[(sUnknown_0203CF10[i].currIndex)++]),
                            0, INNER_BUFFER_LENGTH, 1);
            }
            if (sUnknown_0203CF10[i].currIndex > (INNER_BUFFER_LENGTH - 1))
            {
                FREE_AND_SET_NULL(sUnknown_0203CF10[i].buffer);
                gTasks[taskId].data[2]++;
                if ((i % 2) == 1)
                    sUnknown_0203CF14[1]--;
            }
        }
        LoadBgTiles(0, sUnknown_0203CF04, MIRAGE_TOWER_GFX_LENGTH, 0);
        if (sUnknown_0203CF10[OUTER_BUFFER_LENGTH - 1].currIndex > (INNER_BUFFER_LENGTH - 1))
            break;
        return;
    case 4:
        UnsetBgTilemapBuffer(0);
        anotherTaskId = FindTaskIdByFunc(sub_81BEBB4);
        if (anotherTaskId != 0xFF)
            DestroyTask(anotherTaskId);
        sUnknown_0203CF14[1] = sUnknown_0203CF14[0] = 0;
        sub_81BEB90();
        break;
    case 5:
        FREE_AND_SET_NULL(sUnknown_0203CF14);
        FREE_AND_SET_NULL(sUnknown_0203CF10);
        FREE_AND_SET_NULL(sUnknown_0203CF04);
        FREE_AND_SET_NULL(sUnknown_0203CF08);
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

static void sub_81BF028(u8 taskId)
{
    u16 i;
    u8 *buffer;

    switch (gTasks[taskId].data[0])
    {
    case 1:
        sUnknown_0203CF0C = AllocZeroed(sizeof(*sUnknown_0203CF0C));
        sUnknown_0203CF0C->frameImageTiles = AllocZeroed(ROOT_FOSSIL_GFX_LENGTH);
        sUnknown_0203CF0C->frameImage = AllocZeroed(sizeof(*sUnknown_0203CF0C->frameImage));
        sUnknown_0203CF0C->unkC = AllocZeroed(ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16));
        sUnknown_0203CF0C->unk10 = 0;
        break;
    case 2:
        buffer = sUnknown_0203CF0C->frameImageTiles;
        for (i = 0; i < ROOT_FOSSIL_GFX_LENGTH; i++, buffer++)
            *buffer = gRootFossil_Gfx[i];
        break;
    case 3:
        sUnknown_0203CF0C->frameImage->data = sUnknown_0203CF0C->frameImageTiles;
        sUnknown_0203CF0C->frameImage->size = ROOT_FOSSIL_GFX_LENGTH;
        break;
    case 4:
        {
            struct SpriteTemplate fossilTemplate;

            fossilTemplate = gUnknown_08617E00;
            fossilTemplate.images = (struct SpriteFrameImage *)(sUnknown_0203CF0C->frameImage);
            sUnknown_0203CF0C->spriteId = CreateSprite(&fossilTemplate, 128, -16, 1);
            gSprites[sUnknown_0203CF0C->spriteId].centerToCornerVecX = 0;
            gSprites[sUnknown_0203CF0C->spriteId].data[0] = gSprites[sUnknown_0203CF0C->spriteId].pos1.x;
            gSprites[sUnknown_0203CF0C->spriteId].data[1] = 1;
        }
    case 5:
        for (i = 0; i < ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH; i++)
            sUnknown_0203CF0C->unkC[i] = i;
        break;
    case 6:
        for (i = 0; i < (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH * sizeof(u16)); i++)
        {
            u16 rand1, rand2, temp;

            rand1 = Random() % 0x100;
            rand2 = Random() % 0x100;
            SWAP(sUnknown_0203CF0C->unkC[rand2], sUnknown_0203CF0C->unkC[rand1], temp);
        }
        gSprites[sUnknown_0203CF0C->spriteId].callback = sub_81BF248;
        break;
    case 7:
        if (gSprites[sUnknown_0203CF0C->spriteId].callback != SpriteCallbackDummy)
            return;
        DestroySprite(&gSprites[sUnknown_0203CF0C->spriteId]);
        FREE_AND_SET_NULL(sUnknown_0203CF0C->unkC);;
        FREE_AND_SET_NULL(sUnknown_0203CF0C->frameImage);
        FREE_AND_SET_NULL(sUnknown_0203CF0C->frameImageTiles);
        FREE_AND_SET_NULL(sUnknown_0203CF0C);
        break;
    case 8:
        EnableBothScriptContexts();
        break;
    }

    gTasks[taskId].data[0]++;
}

static void sub_81BF248(struct Sprite *sprite)
{
    if (sUnknown_0203CF0C->unk10 >= (ROOT_FOSSIL_GFX_RANDOMIZER_LENGTH))
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else if (sprite->pos1.y >= 0x60)
    {
        u8 i;
        for (i = 0; i < 2; i++)
        {
            sub_81BF2B8(sUnknown_0203CF0C->frameImageTiles, sUnknown_0203CF0C->unkC[sUnknown_0203CF0C->unk10++], 0, 16, 0);
        }
        StartSpriteAnim(sprite, 0);
    }
    else
    {
        sprite->pos1.y++;
    }
}

#ifdef NONMATCHING
static void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e)
{
    u8 r5, r4, r0, r2;
    u16 var;

    r4 = r5 = b / d;
    gUnknown_030012A8[0] = r4;

    r0 = r2 = b % d;
    gUnknown_030012A8[1] = r2;

    r4 &= 7;
    r2 &= 7;
    gUnknown_030012A8[2] = r4;
    gUnknown_030012A8[3] = r2;

    r0 /= 8;
    r5 /= 8;
    gUnknown_030012A8[4] = r0;
    gUnknown_030012A8[5] = r5;

    var = ((d / 8) * (r5 * 64)) + (r0 * 64);
    gUnknown_030012A8[6] = var;

    var += (r4 * 8) + r2;
    gUnknown_030012A8[7] = var;

    // This part is non-matching. 99% sure it IS functionally equivalent, though.
    b = (b & 1) ^ 1;
    c = (c << ((b) << 2)) | (15 << ((b ^ 1) << 2));

    a[(var / 2) + (e * 32)] &= c;
}

#else
NAKED
static void sub_81BF2B8(u8* a, u16 b, u8 c, u8 d, u8 e)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x8\n\
    str r0, [sp]\n\
    mov r10, r1\n\
    adds r6, r2, 0\n\
    mov r8, r3\n\
    ldr r0, [sp, 0x28]\n\
    mov r9, r0\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    mov r10, r1\n\
    lsls r6, 24\n\
    lsrs r6, 24\n\
    mov r0, r8\n\
    lsls r0, 24\n\
    mov r8, r0\n\
    lsrs r7, r0, 24\n\
    mov r1, r9\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    mov r9, r1\n\
    mov r0, r10\n\
    adds r1, r7, 0\n\
    bl __divsi3\n\
    adds r5, r0, 0\n\
    lsls r5, 24\n\
    lsrs r4, r5, 24\n\
    ldr r3, =gUnknown_030012A8\n\
    strh r4, [r3]\n\
    mov r0, r10\n\
    adds r1, r7, 0\n\
    str r3, [sp, 0x4]\n\
    bl __modsi3\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    ldr r3, [sp, 0x4]\n\
    strh r2, [r3, 0x2]\n\
    movs r1, 0x7\n\
    ands r4, r1\n\
    ands r2, r1\n\
    strh r4, [r3, 0x4]\n\
    strh r2, [r3, 0x6]\n\
    lsrs r0, 27\n\
    lsrs r5, 27\n\
    strh r0, [r3, 0x8]\n\
    strh r5, [r3, 0xA]\n\
    mov r1, r8\n\
    lsrs r1, 27\n\
    lsls r1, 6\n\
    mov r8, r1\n\
    mov r1, r8\n\
    muls r1, r5\n\
    lsls r0, 6\n\
    adds r1, r0\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    strh r1, [r3, 0xC]\n\
    lsls r4, 3\n\
    adds r4, r2\n\
    adds r1, r4\n\
    lsls r4, r1, 16\n\
    lsrs r4, 17\n\
    strh r1, [r3, 0xE]\n\
    movs r1, 0x1\n\
    mov r0, r10\n\
    ands r1, r0\n\
    movs r2, 0x1\n\
    eors r1, r2\n\
    lsls r0, r1, 2\n\
    lsls r6, r0\n\
    eors r1, r2\n\
    lsls r1, 2\n\
    movs r0, 0xF\n\
    lsls r0, r1\n\
    orrs r6, r0\n\
    lsls r6, 24\n\
    lsrs r6, 24\n\
    mov r1, r9\n\
    lsls r1, 5\n\
    mov r9, r1\n\
    add r9, r4\n\
    ldr r1, [sp]\n\
    add r1, r9\n\
    ldrb r0, [r1]\n\
    ands r6, r0\n\
    strb r6, [r1]\n\
    add sp, 0x8\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
                ");
}
#endif // NONMATCHING
