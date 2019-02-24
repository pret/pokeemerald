#include "global.h"
#include "alloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"
#include "field_weather.h"
#include "palette.h"
#include "pokemon_storage_system.h"
#include "sound.h"
#include "constants/songs.h"
#include "window.h"
#include "gpu_regs.h"
#include "bg.h"
#include "menu.h"
#include "graphics.h"
#include "dma3.h"
#include "gba/macro.h"
#include "decompress.h"
#include "strings.h"
#include "constants/rgb.h"

enum
{
    MODE_NORMAL, // Chosen from Start menu.
    MODE_FORCE_CALL_1, // Used for the script's special. Has to choose Match Call and make a call.
    MODE_FORCE_CALL_2, // Set after making a call, has to exit Pokenav.
};

#define UNKNOWN_OFFSET 100000

// Sizes based tentatively on loads and stores in sub_81C9160
struct UnknownSubSubStruct_0203CF40 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 windowId;
    u8 unk9;
    u16 unkA;
    u16 unkC;
};

struct UnknownSubStruct_0203CF40
{
    void (*unk0)(u32);
    u32 (*unk4)(void);
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    struct Sprite *unk18;
    struct Sprite *unk1C[2];
    struct Sprite *unk24[2];
    u8 tilemapBuffer[0x800];
};

struct UnknownSubStruct_81C81D4
{
    struct UnknownSubSubStruct_0203CF40 unk0;
    u8 unkE[0x878];
    struct UnknownSubSubStruct_0203CF40 unk888;
    u8 unk898[0xC];
};

#define SUBSTRUCT_COUNT 19

struct UnknownStruct_0203CF40
{
    u32 (*field0)(void);
    u32 field4;
    u16 mode;
    u16 fieldA;
    bool32 hasAnyRibbons;
    void *field10[SUBSTRUCT_COUNT];
};

extern u32 sub_81C9430(void);
extern void sub_81CAADC(void);
extern u32 sub_81C99D4(void);
extern void sub_8199D98(void);
extern void sub_81C7D28(void);
extern void sub_81C8FE0(void);
extern u32 sub_81C9298(void);
extern u32 sub_81C941C(void);
extern u32 sub_81C9924(void);
extern u32 sub_81C99C0(void);
extern u32 sub_81C9990(void);
extern u32 sub_81C9940(void);
extern u32 sub_81C9338(void);
extern u32 sub_81C9368(void);
extern u32 sub_81C92CC(void);
extern u32 sub_81C9304(void);
extern u32 sub_81CC4D4(void);
extern u32 sub_81CC554(void);
extern u32 sub_81CC5F4(void);
extern u32 sub_81CC62C(void);
extern u32 sub_81CC65C(void);
extern u32 sub_81CC524(void);
extern u32 sub_81CC670(void);
extern u32 sub_81CCFD8(void);
extern u32 sub_81CD070(void);
extern u32 sub_81CDDD4(void);
extern u32 sub_81CDE2C(void);
extern u32 sub_81CDE64(void);
extern u32 sub_81CD1C0(void);
extern u32 sub_81CECA0(void);
extern u32 sub_81CEF3C(void);
extern u32 sub_81CEFDC(void);
extern u32 sub_81CF330(void);
extern u32 sub_81CF3A0(void);
extern u32 sub_81CF3D0(void);
extern u32 sub_81CEFF0(void);
extern u32 sub_81CF3F8(void);
extern u32 sub_81CD024(void);
extern u32 sub_81CEF98(void);
extern u32 sub_81CF368(void);
extern u32 sub_81CAAE8(void);
extern u32 sub_81CAB24(void);
extern u32 sub_81CB260(void);
extern u32 sub_81CB29C(void);
extern u32 sub_81CB2CC(void);
extern u32 sub_81CAB38(void);
extern u32 sub_81CB2E0(void);
extern u32 sub_81CF9BC(void);
extern u32 sub_81CFA34(void);
extern u32 sub_81CFDD0(void);
extern u32 sub_81CFE40(void);
extern u32 sub_81CFE70(void);
extern u32 sub_81CFA48(void);
extern u32 sub_81CFE98(void);
extern u32 sub_81D0450(void);
extern u32 sub_81D04A0(void);
extern u32 sub_81D0978(void);
extern u32 sub_81D09B0(void);
extern u32 sub_81D09E0(void);
extern u32 sub_81D04B8(void);
extern u32 sub_81D09F4(void);
extern u32 sub_81CFA04(void);
extern u32 sub_81CFE08(void);
extern u32 sub_81C91AC(struct UnknownSubStruct_81C81D4 *a0, const void *a1, void *a2, s32 a3);
extern u32 sub_81C9160(struct UnknownSubSubStruct_0203CF40 *a0, void *a1);
extern u32 sub_81C8254(s32);

u32 sub_81C791C(s32 a0);
bool32 sub_81C756C(u32 a0);
bool32 sub_81C76C4(void);
static bool32 AnyMonHasRibbon(void);
u32 sub_81C75E0(void);
u32 sub_81C75D4(void);
u32 sub_81C76FC(void);
u32 sub_81C786C(void);
u32 sub_81C7764(s32 a0);
u32 sub_81C78D4(s32 a0);
bool32 sub_81C7738(void);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 a1, u32 a2);
void sub_81C7834(void *func1, void *func2);
static void InitMainStruct(struct UnknownStruct_0203CF40 *a0);
void FreeSubstruct(u32 index);
void sub_81C7850(u32 a0);
void sub_81C7BF8(u32 a0);
void sub_81C71E4(u8 a0);
void sub_81C7170(u8 taskId);
void sub_81C742C(u8 taskId);
void sub_81C7710(void);
static void InitKeys_(void);
static void FreeVars(void);
static void VblankCb_Pokenav(void);
static void Cb2_Pokenav(void);
void sub_81C7C28(void);
void sub_81C72BC(void);
void sub_81C7B74(void);
void sub_81C7C94(void);
void sub_81C7F24(u32 arg0);
void sub_81C7E58(u32 arg0);
void sub_81C8110(bool32 arg0);
void sub_81C80D4(bool32 arg0);
void sub_81C803C(u32 arg0, bool32 arg1);
void sub_81C8088(u32 arg0, bool32 arg1);
void sub_81C814C(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3);
void sub_81C817C(struct Sprite *sprite);

// Const rom data.
u32 (*const gUnknown_0861F3EC[15][7])(void) =
{
    {
        sub_81C9298,
        sub_81C941C,
        sub_81C9924,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9298,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9338,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9368,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C92CC,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9304,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81CC4D4,
        sub_81CC554,
        sub_81CC5F4,
        sub_81CC62C,
        sub_81CC65C,
        sub_81CC524,
        sub_81CC670,
    },
    {
        sub_81CCFD8,
        sub_81CD070,
        sub_81CDDD4,
        sub_81CDE2C,
        sub_81CDE64,
        sub_81CD1C0,
        sub_81CECA0,
    },
    {
        sub_81CEF3C,
        sub_81CEFDC,
        sub_81CF330,
        sub_81CF3A0,
        sub_81CF3D0,
        sub_81CEFF0,
        sub_81CF3F8,
    },
    {
        sub_81CD024,
        sub_81CD070,
        sub_81CDDD4,
        sub_81CDE2C,
        sub_81CDE64,
        sub_81CD1C0,
        sub_81CECA0,
    },
    {
        sub_81CEF98,
        sub_81CEFDC,
        sub_81CF368,
        sub_81CF3A0,
        sub_81CF3D0,
        sub_81CEFF0,
        sub_81CF3F8,
    },
    {
        sub_81CAAE8,
        sub_81CAB24,
        sub_81CB260,
        sub_81CB29C,
        sub_81CB2CC,
        sub_81CAB38,
        sub_81CB2E0,
    },
    {
        sub_81CF9BC,
        sub_81CFA34,
        sub_81CFDD0,
        sub_81CFE40,
        sub_81CFE70,
        sub_81CFA48,
        sub_81CFE98,
    },
    {
        sub_81D0450,
        sub_81D04A0,
        sub_81D0978,
        sub_81D09B0,
        sub_81D09E0,
        sub_81D04B8,
        sub_81D09F4,
    },
    {
        sub_81CFA04,
        sub_81CFA34,
        sub_81CFE08,
        sub_81CFE40,
        sub_81CFE70,
        sub_81CFA48,
        sub_81CFE98,
    },
};

const u16 gUnknown_0861F590[] = INCBIN_U16("graphics/pokenav/icon2.gbapal");
const u32 gUnknown_0861F5B0[] = INCBIN_U32("graphics/pokenav/icon2.4bpp.lz");
const u32 gUnknown_0861F994[] = INCBIN_U32("graphics/pokenav/icon2_unused.4bpp.lz");

const struct BgTemplate gUnknown_0861FA04[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    }
};

const struct WindowTemplate gUnknown_0861FA08[2] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 22,
        .width = 16,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x36,
    },
    {
        .bg = 0xFF,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0,
    },
};

const u8 *const (sMenuButtonReminders[12]) =
{
    gText_Navgear_ClearButtonList,
    gText_NavgearMap_ZoomedOutButtons,
    gText_NavgearMap_ZoomedInButtons,
    gText_NavgearCondition_MonListButtons,
    gText_NavgearCondition_MonStatusButtons,
    gText_NavgearCondition_MarkingButtons,
    gText_NavgearMatchCall_TrainerListButtons,
    gText_NavgearMatchCall_CallMenuButtons,
    gText_NavgearMatchCall_CheckTrainerButtons,
    gText_NavgearRibbons_MonListButtons,
    gText_NavgearRibbons_RibbonListButtons,
    gText_NavgearRibbons_RibbonCheckButtons,
};

const u8 gMenuButtonReminderColor[4] =
{
    4, 1, 2, 0
};

const struct CompressedSpriteSheet gUnknown_0861FA4C[] =
{
    {
        .data = gUnknown_0861F5B0,
        .size = 0x1000,
        .tag = 0,
    }
};

const struct SpritePalette gUnknown_0861FA54[2] =
{
    {
        .data = gUnknown_0861F590,
        .tag = 0,
    },
};

const struct CompressedSpriteSheet gUnknown_0861FA64 =
{
    .data = gPokenavLeftHeaderHoennMap_Gfx,
    .size = 0xC00,
    .tag = 2
};

extern struct UnknownStruct_0203CF40 *gUnknown_0203CF40;
extern u8 gUnknown_0203CF3C;
extern const struct SpriteTemplate gUnknown_0861FB04;

// code
u32 sub_81C7078(u32 (*func)(s32), u32 priority)
{
    u16 taskId;

    if (!is_c1_link_related_active())
        taskId = CreateTask(sub_81C7170, priority);
    else
        taskId = CreateTask(sub_81C71E4, priority);

    SetWordTaskArg(taskId, 1, (u32)func);

    gTasks[taskId].data[3] = gUnknown_0203CF3C;
    return ((gUnknown_0203CF3C++) << 16) | taskId;
}

bool32 sub_81C70D8(u32 a0)
{
    u32 taskId = a0 & 0xFFFF;
    u32 v2 = a0 >> 16;

    if (gTasks[taskId].isActive
        && (gTasks[taskId].func == sub_81C7170 || gTasks[taskId].func == sub_81C71E4)
        && gTasks[taskId].data[3] == v2)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_81C7124(u32 (*a0)(s32))
{
    s32 i;
    for (i = 0; i < NUM_TASKS; i++)
    {
        if (gTasks[i].isActive
            && (gTasks[i].func == sub_81C7170 || gTasks[i].func == sub_81C71E4)
            && (void *)GetWordTaskArg(i, 1) == a0)
            return TRUE;
    }
    return FALSE;
}

void sub_81C7170(u8 taskId)
{
    u32 (*func)(s32) = (void *)GetWordTaskArg(taskId, 1);
    s16 *data = gTasks[taskId].data;
    bool32 exitLoop = FALSE;

    while (!exitLoop)
    {
        u32 var = func(data[0]);
        switch (var)
        {
        case 1:
            data[0] = data[0] + 1;
            break;
        case 0:
            data[0]++;
            return;
        case 4:
            DestroyTask(taskId);
            return;
        default:
            data[0] = var - 5;
            break;
        case 3:
            break;
        case 2:
            return;
        }
    }
}

void sub_81C71E4(u8 taskId)
{
    u32 (*func)(u32);
    s16 *data;
    u32 v1;

    if (sub_8087598())
        return;
    func = (u32 (*)(u32))GetWordTaskArg(taskId, 1);
    data = gTasks[taskId].data;
    v1 = func(data[0]);
    switch (v1)
    {
    case 0:
    case 1:
        data[0]++;
        break;
    case 4:
        DestroyTask(taskId);
        break;
    default:
        data[0] = v1 - 5;
        break;
    case 2:
    case 3:
        break;
    }
}

void CB2_PokeNav(void)
{
    gUnknown_0203CF40 = Alloc(sizeof(*gUnknown_0203CF40));
    if (gUnknown_0203CF40 == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
    else
    {
        InitMainStruct(gUnknown_0203CF40);
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(Cb2_Pokenav);
        SetVBlankCallback(VblankCb_Pokenav);
    }
}

void sub_81C72A4(void)
{
    SetMainCallback2(sub_81C72BC);
    FadeScreen(1, 0);
}

void sub_81C72BC(void)
{
    UpdatePaletteFade();
    if (gPaletteFade.active)
        return;

    gUnknown_0203CF40 = Alloc(sizeof(*gUnknown_0203CF40));
    if (gUnknown_0203CF40 == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else
    {
        InitMainStruct(gUnknown_0203CF40);
        gUnknown_0203CF40->mode = MODE_FORCE_CALL_1;
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(Cb2_Pokenav);
        SetVBlankCallback(VblankCb_Pokenav);
    }
}

static void FreeVars(void)
{
    s32 i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        FreeSubstruct(i);

    FREE_AND_SET_NULL(gUnknown_0203CF40);
    InitKeys();
}

// Clears UnknownStruct_0203CF40
static void InitMainStruct(struct UnknownStruct_0203CF40 *a0)
{
    s32 i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        a0->field10[i] = NULL;

    a0->mode = MODE_NORMAL;
    a0->field4 = 0;
    a0->hasAnyRibbons = AnyMonHasRibbon();
    a0->field0 = NULL;
}

static bool32 AnyMonHasRibbon(void)
{
    s32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i],  MON_DATA_SANITY_HAS_SPECIES)
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_RIBBON_COUNT) != 0)
        {
            return TRUE;
        }
    }

    for (j = 0; j < TOTAL_BOXES_COUNT; j++)
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (CheckBoxMonSanityAt(j, i)
                && GetBoxMonDataAt(j, i, MON_DATA_RIBBON_COUNT) != 0)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static void Cb2_Pokenav(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VblankCb_Pokenav(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void sub_81C742C(u8 taskId)
{
    u32 v1;
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        sub_81C76C4();
        data[0] = 1;
        break;
    case 1:
        if (sub_81C76FC())
            break;
        sub_81C756C(UNKNOWN_OFFSET);
        data[0] = 4;
        break;
    case 2:
        if (sub_81C786C())
            break;
        data[0] = 3;
    case 3:
        v1 = sub_81C75E0();
        if (v1 == -1)
        {
            sub_81C7710();
            data[0] = 5;
        }
        else if (v1 >= UNKNOWN_OFFSET)
        {
            gUnknown_0861F3EC[gUnknown_0203CF40->field4][6]();
            gUnknown_0861F3EC[gUnknown_0203CF40->field4][5]();
            if (sub_81C756C(v1))
            {
                data[0] = 4;
            }
            else
            {
                sub_81C7710();
                data[0] = 5;
            }
        }
        else if (v1 != 0)
        {
            sub_81C7850(v1);
            if (sub_81C786C())
                data[0] = 2;
        }
        break;
    case 4:
        if (!sub_81C75D4())
            data[0] = 3;
        break;
    case 5:
        if (!sub_81C7738())
        {
            bool32 calledFromScript = (gUnknown_0203CF40->mode != MODE_NORMAL);

            sub_81C9430();
            FreeVars();
            if (calledFromScript)
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            else
                SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        break;
    }
}

bool32 sub_81C756C(u32 a0)
{
    u32 index = a0 - UNKNOWN_OFFSET;

    InitKeys_();
    if (!gUnknown_0861F3EC[index][0]())
        return FALSE;
    if (!gUnknown_0861F3EC[index][2]())
        return FALSE;

    sub_81C7834(gUnknown_0861F3EC[index][3], gUnknown_0861F3EC[index][4]);
    gUnknown_0203CF40->field0 = gUnknown_0861F3EC[index][1];
    gUnknown_0203CF40->field4 = index;
    return TRUE;
}

u32 sub_81C75D4(void)
{
    return sub_81C786C();
}

u32 sub_81C75E0(void)
{
    return gUnknown_0203CF40->field0();
}

static void InitKeys_(void)
{
    InitKeys();
}

void SetVBlankCallback_(IntrCallback callback)
{
    SetVBlankCallback(callback);
}

void SetPokenavVBlankCallback(void)
{
    SetVBlankCallback(VblankCb_Pokenav);
}

void *AllocSubstruct(u32 index, u32 size)
{
    return gUnknown_0203CF40->field10[index] = Alloc(size);
}

void *GetSubstructPtr(u32 index)
{
    return gUnknown_0203CF40->field10[index];
}

void FreeSubstruct(u32 index)
{
    if (gUnknown_0203CF40->field10[index] != NULL)
        FREE_AND_SET_NULL(gUnknown_0203CF40->field10[index]);
}

u16 GetPokenavMode(void)
{
    return gUnknown_0203CF40->mode;
}

void SetPokenavMode(u16 mode)
{
    gUnknown_0203CF40->mode = mode;
}

void sub_81C7694(u32 a0)
{
    u32 value = a0;

    if (value > 4)
        value = 0;
    gUnknown_0203CF40->fieldA = value;
}

u16 sub_81C76AC(void)
{
    return gUnknown_0203CF40->fieldA;
}

bool32 CanViewRibbonsMenu(void)
{
    return gUnknown_0203CF40->hasAnyRibbons;
}

bool32 sub_81C76C4(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr;
    
    structPtr = AllocSubstruct(0, sizeof(struct UnknownSubStruct_0203CF40));
    if (structPtr == NULL)
        return FALSE;

    ResetSpriteData();
    FreeAllSpritePalettes();
    structPtr->unkC = sub_81C7078(sub_81C7764, 1);
    return TRUE;
}

u32 sub_81C76FC(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    return sub_81C70D8(structPtr->unkC);
}

void sub_81C7710(void)
{
    PlaySE(SE_PN_OFF);
    sub_81CAADC();
    BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
}

bool32 sub_81C7738(void)
{
    if (!gPaletteFade.active)
    {
        sub_81C99D4();
        sub_81C7C94();
        FreeAllWindowBuffers();
        return FALSE;
    }

    return TRUE;
}

u32 sub_81C7764(s32 a0)
{
    struct UnknownSubStruct_0203CF40 *structPtr;

    switch (a0)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_0861FA04, ARRAY_COUNT(gUnknown_0861FA04));
        sub_8199D98();
        reset_temp_tile_data_buffers();
        return 1;
    case 1:
        structPtr = GetSubstructPtr(0);
        decompress_and_copy_tile_data_to_vram(0, &gPokenavHeader_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(0, structPtr->tilemapBuffer);
        CopyToBgTilemapBuffer(0, &gPokenavHeader_Tilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(gPokenavHeader_Pal, 0, 0x20);
        CopyBgTilemapBufferToVram(0);
        return 0;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return 2;

        sub_81C7B74();
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;

        sub_81C7C28();
        sub_81C7D28();
        ShowBg(0);
        return 4;
    default:
        return 4;
    }
}

void sub_81C7834(void *func1, void *func2) // Fix types later.
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    structPtr->unk0 = func1;
    structPtr->unk4 = func2;
    structPtr->unk8 = 0;
}

void sub_81C7850(u32 a0)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    structPtr->unk8 = 0;
    structPtr->unk0(a0);
}

u32 sub_81C786C(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    return structPtr->unk4();
}

void sub_81C7880(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    structPtr->unkC = sub_81C7078(sub_81C78D4, 4);
}

void sub_81C78A0(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    structPtr->unkC = sub_81C7078(sub_81C791C, 4);
}

bool32 sub_81C78C0(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);
    return sub_81C70D8(structPtr->unkC);
}

u32 sub_81C78D4(s32 a0)
{
    switch (a0)
    {
    default:
        return 4;
    case 1:
        return 0;
    case 0:
        return 0;
    case 2:
        if (ChangeBgY(0, 384, 1) >= 0x2000u)
        {
            ChangeBgY(0, 0x2000, 0);
            return 4;
        }

        return 2;
    }
}

u32 sub_81C791C(s32 a0)
{
    if (ChangeBgY(0, 384, 2) <= 0)
    {
        ChangeBgY(0, 0, 0);
        return 4;
    }
    return 2;
}

void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size)
{
    CpuCopy16(palette, gPlttBufferUnfaded + bufferOffset, size);
}

void sub_81C795C(const struct SpritePalette *palettes)
{
    const struct SpritePalette *current;
    u32 index;

    for (current = palettes; current->data != NULL; current++)
    {
        index = AllocSpritePalette(current->tag);
        if (index == 0xFF)
        {
            break;
        }
        else
        {
            index = (index * 16) + 0x100;
            CopyPaletteIntoBufferUnfaded(current->data, index, 0x20);
        }
    }
}

void sub_81C7990(u32 a0, u16 a1)
{
    CpuFill16(a1, gPlttBufferFaded + 0x100 + (a0 * 16), 16 * sizeof(u16));
}

__attribute__((naked))
void sub_81C79BC(u16 *a0, u16 *a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0xC\n\
    str r0, [sp]\n\
    str r1, [sp, 0x4]\n\
    mov r10, r2\n\
    str r3, [sp, 0x8]\n\
    ldr r0, [sp, 0x2C]\n\
    cmp r0, 0\n\
    bne _081C79E4\n\
    ldr r2, =0x001fffff\n\
    mov r1, r10\n\
    ands r2, r1\n\
    ldr r0, [sp]\n\
    b _081C79F4\n\
    .pool\n\
_081C79E4:\n\
    ldr r2, [sp, 0x2C]\n\
    ldr r0, [sp, 0x8]\n\
    cmp r2, r0\n\
    blt _081C7A00\n\
    ldr r2, =0x001fffff\n\
    mov r1, r10\n\
    ands r2, r1\n\
    ldr r0, [sp, 0x4]\n\
_081C79F4:\n\
    ldr r1, [sp, 0x30]\n\
    bl CpuSet\n\
    b _081C7AAE\n\
    .pool\n\
_081C7A00:\n\
    movs r2, 0x1\n\
    negs r2, r2\n\
    add r10, r2\n\
    b _081C7AA6\n\
_081C7A08:\n\
    ldr r1, [sp]\n\
    ldrh r0, [r1]\n\
    movs r2, 0x1F\n\
    mov r9, r2\n\
    mov r1, r9\n\
    ands r1, r0\n\
    mov r9, r1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 21\n\
    movs r1, 0x1F\n\
    ands r1, r2\n\
    mov r8, r1\n\
    lsrs r7, r0, 26\n\
    movs r2, 0x1F\n\
    ands r7, r2\n\
    ldr r0, [sp, 0x4]\n\
    ldrh r4, [r0]\n\
    movs r0, 0x1F\n\
    ands r0, r4\n\
    mov r1, r9\n\
    subs r0, r1\n\
    lsls r0, 8\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r2, [sp, 0x2C]\n\
    adds r6, r0, 0\n\
    muls r6, r2\n\
    asrs r6, 8\n\
    lsls r4, 16\n\
    lsrs r0, r4, 21\n\
    movs r1, 0x1F\n\
    ands r0, r1\n\
    mov r2, r8\n\
    subs r0, r2\n\
    lsls r0, 8\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r1, [sp, 0x2C]\n\
    adds r5, r0, 0\n\
    muls r5, r1\n\
    asrs r5, 8\n\
    lsrs r4, 26\n\
    movs r2, 0x1F\n\
    ands r4, r2\n\
    subs r4, r7\n\
    lsls r4, 8\n\
    adds r0, r4, 0\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r1, [sp, 0x2C]\n\
    muls r0, r1\n\
    asrs r0, 8\n\
    add r6, r9\n\
    movs r2, 0x1F\n\
    ands r6, r2\n\
    add r5, r8\n\
    ands r5, r2\n\
    adds r0, r7, r0\n\
    ands r0, r2\n\
    lsls r0, 10\n\
    lsls r5, 5\n\
    orrs r0, r5\n\
    orrs r0, r6\n\
    ldr r1, [sp, 0x30]\n\
    strh r0, [r1]\n\
    ldr r2, [sp]\n\
    adds r2, 0x2\n\
    str r2, [sp]\n\
    ldr r0, [sp, 0x4]\n\
    adds r0, 0x2\n\
    str r0, [sp, 0x4]\n\
    adds r1, 0x2\n\
    str r1, [sp, 0x30]\n\
    movs r1, 0x1\n\
    negs r1, r1\n\
    add r10, r1\n\
_081C7AA6:\n\
    movs r0, 0x1\n\
    negs r0, r0\n\
    cmp r10, r0\n\
    bne _081C7A08\n\
_081C7AAE:\n\
    add sp, 0xC\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided");
}

void sub_81C7AC0(s32 a0)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    switch (a0)
    {
    case 0:
        BeginNormalPaletteFade(structPtr->unk14, -2, 0, 16, RGB_BLACK);
        break;
    case 1:
        BeginNormalPaletteFade(structPtr->unk14, -2, 16, 0, RGB_BLACK);
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 16, 0, RGB_BLACK);
        break;
    }
}

bool32 IsPaletteFadeActive(void)
{
    return gPaletteFade.active;
}

void sub_81C7B40(void)
{
    BlendPalettes(0xFFFEFFFE, 16, RGB_BLACK);
}

void InitBgTemplates(const struct BgTemplate *templates, s32 count)
{
    s32 i;

    for (i = 0; i < count; i++)
        InitBgFromTemplate(templates++);
}

void sub_81C7B74(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    InitWindows(&gUnknown_0861FA08[0]);
    structPtr->unk10 = 0;
    sub_81C7BF8(structPtr->unk10);
    PutWindowTilemap(structPtr->unk10);
    CopyWindowToVram(structPtr->unk10, 3); // TODO: Use a defined constant here.
}

void sub_81C7BA4(u32 a0)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    sub_81C7BF8(structPtr->unk10);
    AddTextPrinterParameterized3(structPtr->unk10, 1, 0, 1, gMenuButtonReminderColor, 0, sMenuButtonReminders[a0]);
}

bool32 IsDma3ManagerBusyWithBgCopy_(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

void sub_81C7BF8(u32 windowId)
{
    FillWindowPixelBuffer(windowId, 0x44);
    FillWindowPixelRect(windowId, 0x55, 0, 0, 0x80, 1);
}

void sub_81C7C28(void)
{
    s32 i;
    u8 spriteId;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    for (i = 0; i < ARRAY_COUNT(gUnknown_0861FA4C); i++)
        LoadCompressedSpriteSheet(&gUnknown_0861FA4C[i]);

    sub_81C795C(gUnknown_0861FA54);
    structPtr->unk14 = ~1 & ~(0x10000 << IndexOfSpritePaletteTag(0));
    spriteId = CreateSprite(&gUnknown_0861FB04, 220, 12, 0);
    structPtr->unk18 = &gSprites[spriteId];
}

void sub_81C7C94(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    DestroySprite(structPtr->unk18);
    FreeSpriteTilesByTag(0);
    FreeSpritePaletteByTag(0);
}

void sub_81C7CB4(struct Sprite *sprite)
{
    sprite->pos2.y = (GetBgY(0) / 256u) * -1;
}

struct Sprite *sub_81C7CCC(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    structPtr->unk18->callback = SpriteCallbackDummy;
    return structPtr->unk18;
}

void sub_81C7CE4(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    structPtr->unk18->pos1.x = 220;
    structPtr->unk18->pos1.y = 12;
    structPtr->unk18->callback = sub_81C7CB4;
    structPtr->unk18->invisible = FALSE;
    structPtr->unk18->oam.priority = 0;
    structPtr->unk18->subpriority = 0;
}

extern const struct SpriteTemplate gUnknown_0861FB2C;
extern const struct SpriteTemplate gUnknown_0861FB44;
extern const struct CompressedSpriteSheet gUnknown_0861FA6C[];

void sub_81C7D28(void)
{
    s32 i, spriteId;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    LoadCompressedSpriteSheet(&gUnknown_0861FA64);
    AllocSpritePalette(1);
    AllocSpritePalette(2);
    for (i = 0; i < 2; i++)
    {
        spriteId = CreateSprite(&gUnknown_0861FB2C, 0, 0, 1);
        structPtr->unk1C[i] = &gSprites[spriteId];
        structPtr->unk1C[i]->invisible = TRUE;
        structPtr->unk1C[i]->pos2.x = i * 64;

        spriteId = CreateSprite(&gUnknown_0861FB44, 0, 0, 2);
        structPtr->unk24[i] = &gSprites[spriteId];
        structPtr->unk24[i]->invisible = TRUE;
        structPtr->unk24[i]->pos2.x = i * 32;
        structPtr->unk24[i]->pos2.y = 18;
        structPtr->unk24[i]->oam.tileNum += (i * 8) + 64;
    }
}

void sub_81C7DFC(u32 arg0)
{
    if (arg0 < 6)
        sub_81C7E58(arg0);
    else
        sub_81C7F24(arg0 - 6);
}

void sub_81C7E14(u32 arg0)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    if (arg0 == 4)
        structPtr->unk1C[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 32;
    else
        structPtr->unk1C[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 64;
}

void sub_81C7E58(u32 arg0)
{
    struct UnknownSubStruct_0203CF40 *structPtr;
    u32 size, tag;

    if (arg0 >= 6)
        return;

    structPtr = GetSubstructPtr(0);
    tag = gUnknown_0861FA6C[arg0].tag;
    size = GetDecompressedDataSize(gUnknown_0861FA6C[arg0].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(1) * 16) + 0x100, 0x20);
    LZ77UnCompWram(gUnknown_0861FA6C[arg0].data, gDecompressionBuffer);
    RequestDma3Copy(gDecompressionBuffer, (void *)VRAM + 0x10000 + (GetSpriteTileStartByTag(2) * 32), size, 1);
    structPtr->unk1C[1]->oam.tileNum = GetSpriteTileStartByTag(2) + gUnknown_0861FA6C[arg0].size;

    if (arg0 == 4 || arg0 == 5)
        structPtr->unk1C[1]->pos2.x = 56;
    else
        structPtr->unk1C[1]->pos2.x = 64;
}

// Needed to match u32/u16 tag field difference.
struct CompressedSpritePalette_
{
    const u32 *data;  // LZ77 compressed palette data
    u32 tag;
};

extern const struct CompressedSpritePalette_ gUnknown_0861FA9C[];

void sub_81C7F24(u32 arg0)
{
    u32 size, tag;

    if (arg0 >= 7)
        return;

    tag = gUnknown_0861FA9C[arg0].tag;
    size = GetDecompressedDataSize(gUnknown_0861FA9C[arg0].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(2) * 16) + 0x100, 0x20);
    LZ77UnCompWram(gUnknown_0861FA9C[arg0].data, &gDecompressionBuffer[0x1000]);
    RequestDma3Copy(&gDecompressionBuffer[0x1000], (void *)VRAM + 0x10800 + (GetSpriteTileStartByTag(2) * 32), size, 1);
}

void sub_81C7FA0(u32 arg0, bool32 arg1, bool32 arg2)
{
    u32 var;

    if (!arg1)
        var = 0x30;
    else
        var = 0x10;

    if (arg0 < 6)
        sub_81C803C(var, arg2);
    else
        sub_81C8088(var, arg2);
}

void sub_81C7FC4(u32 arg0, bool32 arg1)
{
    if (arg0 < 6)
        sub_81C80D4(arg1);
    else
        sub_81C8110(arg1);
}

void sub_81C7FDC(void)
{
    s32 i;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    for (i = 0; i < 2; i++)
    {
        structPtr->unk1C[i]->invisible = TRUE;
        structPtr->unk24[i]->invisible = TRUE;
    }
}

bool32 sub_81C8010(void)
{
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    if (structPtr->unk1C[0]->callback == SpriteCallbackDummy && structPtr->unk24[0]->callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

void sub_81C803C(u32 arg0, bool32 arg1)
{
    s32 var1, var2, i;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    if (!arg1)
        var1 = -96, var2 = 32;
    else
        var1 = 256, var2 = 160;

    for (i = 0; i < 2; i++)
    {
        structPtr->unk1C[i]->pos1.y = arg0;
        sub_81C814C(structPtr->unk1C[i], var1, var2, 12);
    }
}

void sub_81C8088(u32 arg0, bool32 arg1)
{
    s32 var1, var2, i;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    if (!arg1)
        var1 = -96, var2 = 16;
    else
        var1 = 256, var2 = 192;

    for (i = 0; i < 2; i++)
    {
        structPtr->unk24[i]->pos1.y = arg0;
        sub_81C814C(structPtr->unk24[i], var1, var2, 12);
    }
}

void sub_81C80D4(bool32 arg0)
{
    s32 var1, var2, i;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    if (!arg0)
        var1 = 32, var2 = -96;
    else
        var1 = 192, var2 = 256;

    for (i = 0; i < 2; i++)
    {
        sub_81C814C(structPtr->unk1C[i], var1, var2, 12);
    }
}

void sub_81C8110(bool32 arg0)
{
    s32 var1, var2, i;
    struct UnknownSubStruct_0203CF40 *structPtr = GetSubstructPtr(0);

    if (!arg0)
        var1 = 16, var2 = -96;
    else
        var1 = 192, var2 = 256;

    for (i = 0; i < 2; i++)
    {
        sub_81C814C(structPtr->unk24[i], var1, var2, 12);
    }
}

void sub_81C814C(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3)
{
    sprite->pos1.x = arg1;
    sprite->data[0] = arg1 * 16;
    sprite->data[1] = (arg2 - arg1) * 16 / arg3;
    sprite->data[2] = arg3;
    sprite->data[7] = arg2;
    sprite->callback = sub_81C817C;
}

void sub_81C817C(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
    {
        sprite->data[2]--;
        sprite->data[0] += sprite->data[1];
        sprite->pos1.x = sprite->data[0] >> 4;
        if (sprite->pos1.x < -16 || sprite->pos1.x > 256)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->pos1.x = sprite->data[7];
        sprite->callback = SpriteCallbackDummy;
    }
}

bool32 sub_81C81D4(const void *arg0, void *arg1, s32 arg2)
{
    u32 v1;
    struct UnknownSubStruct_81C81D4 *structPtr;
    
    structPtr = AllocSubstruct(0x11, sizeof(struct UnknownSubStruct_81C81D4));

    if (structPtr == NULL)
        return FALSE;
    
    sub_81C9160(&structPtr->unk888, arg1);

    v1 = sub_81C91AC(structPtr, arg0, arg1, arg2);
    if (v1 == 0)
        return FALSE;
    
    sub_81C7078(sub_81C8254, 6);
    return TRUE;
}

bool32 sub_81C8224(void) {
    return sub_81C7124(sub_81C8254);
}

void sub_81C8234(void) {
    struct UnknownSubStruct_81C81D4 *structPtr;

    structPtr = GetSubstructPtr(0x11);
    sub_81C8FE0();
    RemoveWindow(structPtr->unk0.windowId);
    FreeSubstruct(0x11);
}