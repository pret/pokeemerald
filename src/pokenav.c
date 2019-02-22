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
#include "gba/macro.h"
#include "decompress.h"
#include "strings.h"
#include "constants/rgb.h"

#define UNKNOWN_OFFSET 100000

struct UnknownStruct_0203CF40
{
    u32 (*field0)(void);
    u32 field4;
    u16 field8;
    u16 fieldA;
    u32 fieldC;
    void *field10[19];
};

struct UnknownStruct_sub_81C76C4
{
    u32 data[523];
};

extern u32 sub_81C9430(void);
extern void sub_81CAADC(void);
extern u32 sub_81C99D4(void);
extern void sub_8199D98(void);
extern void sub_81C7D28(void);
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

u32 sub_81C791C(s32 a0);
bool32 sub_81C756C(u32 a0);
bool32 sub_81C76C4(void);
u32 AnyMonHasRibbon(void);
u32 sub_81C75E0(void);
u32 sub_81C75D4(void);
u32 sub_81C76FC(void);
u32 sub_81C786C(void);
u32 sub_81C7764(s32 a0);
u32 atk47_cmd47(s32 a0);
bool32 sub_81C7738(void);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 a1, u32 a2);
void sub_81C7834(u32 (*a0)(void), u32(*a1)(void));
void sub_81C7360(struct UnknownStruct_0203CF40 *a0);
void sub_81C7650(u32 index);
void sub_81C7850(u32 a0);
void sub_81C7BF8(u32 a0);
void sub_81C71E4(u8 a0);
void sub_81C7170(u8 a0);
void sub_81C742C(u8 taskId);
void sub_81C7710(void);
void sub_81C75F4(void);
void sub_81C7334(void);
void sub_81C7418(void);
void sub_81C7400(void);
void sub_81C7C28(void);
void sub_81C72BC(void);
void sub_81C7B74(void);
void sub_81C7C94(void);


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

const struct BgTemplate gUnknown_0861FA04 =
{
    .bg = 0,
    .charBaseIndex = 0,
    .mapBaseIndex = 5,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0,
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

const u8 *const (MenuButtonReminders[12]) =
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
    {
        .data = NULL,
        .tag = 0,
    }
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

u32 sub_81C7078(u32 (*a0)(s32), u32 a1)
{
    u16 taskId;

    if (!IsUpdateLinkStateCBActive())
        taskId = CreateTask(sub_81C7170, a1);
    else
        taskId = CreateTask(sub_81C71E4, a1);

    SetWordTaskArg(taskId, 1, (u32)a0);

    gTasks[taskId].data[3] = gUnknown_0203CF3C;
    return ((gUnknown_0203CF3C++) << 16) | taskId;
}

bool32 sub_81C70D8(u32 a0)
{
    u32 v1 = a0 & 0xFFFF;
    u32 v2 = a0 >> 16;
    if (gTasks[v1].isActive
        && (gTasks[v1].func == sub_81C7170 || gTasks[v1].func == sub_81C71E4)
        && gTasks[v1].data[3] == v2)
    {
    
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool32 sub_81C7124(u32 a0)
{
    s32 i;
    for (i = 0; i < 16; i++)
    {
        if (gTasks[i].isActive
            && (gTasks[i].func == sub_81C7170 || gTasks[i].func == sub_81C71E4))
        {
            u32 arg = GetWordTaskArg((u8)i, 1);
            if (arg == a0)
                return TRUE;
        }
    }
    return FALSE;
}

void sub_81C7170(u8 taskId)
{
    s16 *dataPtr;
    u32 (*func)(u32);
    bool32 exitLoop;

    func = (u32 (*)(u32))GetWordTaskArg(taskId, 1);
    dataPtr = gTasks[taskId].data;
    exitLoop = FALSE;
    while (!exitLoop)
    {
        u32 v1 =((u32 (*)(u32))func)(dataPtr[0]); 
        switch (v1)
        {
        case 1:
            dataPtr[0] = dataPtr[0] + 1;
            break;
        case 0:
            dataPtr[0]++;
            return;
        case 4:
            DestroyTask(taskId);
            return;
        default:
            dataPtr[0] = v1 - 5;
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
    gUnknown_0203CF40 = Alloc(sizeof(struct UnknownStruct_0203CF40));
    if (gUnknown_0203CF40 == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
    else
    {
        sub_81C7360(gUnknown_0203CF40);
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(sub_81C7400);
        SetVBlankCallback(sub_81C7418);
    }
}

void sub_81C72A4()
{
    SetMainCallback2(sub_81C72BC);
    FadeScreen(1, 0);
}

void sub_81C72BC()
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        gUnknown_0203CF40 = Alloc(sizeof(struct UnknownStruct_0203CF40));
        if (gUnknown_0203CF40 == NULL)
        {
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        }
        else
        {
            sub_81C7360(gUnknown_0203CF40);
            gUnknown_0203CF40->field8 = 1;
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(NULL);
            CreateTask(sub_81C742C, 0);
            SetMainCallback2(sub_81C7400);
            SetVBlankCallback(sub_81C7418);
        }
    }
}

void sub_81C7334()
{
    s32 i;
    for (i = 0; i < 19; i++)
    {
        sub_81C7650(i);
    }

    Free(gUnknown_0203CF40);
    gUnknown_0203CF40 = NULL;
    InitKeys();
}

// Clears UnknownStruct_0203CF40
void sub_81C7360(struct UnknownStruct_0203CF40 *a0)
{
    s32 i;
    void **arrayPtr;
    void *fill;

    fill = NULL;
    i = 18;
    arrayPtr = &(a0->field10[18]);
    for (i; i >= 0; i--)
    {
        *arrayPtr = fill;
        arrayPtr -= 1;
    }
    a0->field8 = 0;
    a0->field4 = 0;
    a0->fieldC = AnyMonHasRibbon();
    a0->field0 = NULL;
}

bool32 AnyMonHasRibbon()
{
    s32 i;
    s32 j;

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

void sub_81C7400()
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_81C7418()
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void sub_81C742C(u8 taskId)
{
    s16 *dataPtr;
    u32 v1;
    bool32 v2;

    dataPtr = gTasks[taskId].data;

    switch (dataPtr[0])
    {
    case 0:
        sub_81C76C4();
        dataPtr[0] = 1;
        break;
    case 1:
        if (sub_81C76FC())
            break;
        sub_81C756C(UNKNOWN_OFFSET);
        dataPtr[0] = 4;
        break;
    case 2:
        if (sub_81C786C())
            break;
        dataPtr[0] = 3;
    case 3:
        v1 = sub_81C75E0();
        if (v1 == -1)
        {
            sub_81C7710();
            dataPtr[0] = 5;
        }
        else if (v1 >= UNKNOWN_OFFSET)
        {
            gUnknown_0861F3EC[gUnknown_0203CF40->field4][6]();
            gUnknown_0861F3EC[gUnknown_0203CF40->field4][5]();
            if (sub_81C756C(v1))
            {
                dataPtr[0] = 4;
            }
            else
            {
                sub_81C7710();
                dataPtr[0] = 5;
            }
        }
        else if (v1 != 0)
        {
            sub_81C7850(v1);
            if (sub_81C786C())
                dataPtr[0] = 2;
        }
        break;
    case 4:
        if (!sub_81C75D4())
            dataPtr[0] = 3;
        break;
    case 5:
        if (!sub_81C7738())
        {
            v2 = gUnknown_0203CF40->field8 != 0;
            sub_81C9430();
            sub_81C7334();
            if (v2)
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            else
                SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        break;
    }
}

bool32 sub_81C756C(u32 a0)
{
    u32 index;

    index = a0 - UNKNOWN_OFFSET;
    sub_81C75F4();
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

void sub_81C75F4(void)
{
    InitKeys();
}

void IndirectSetVBlankCallback(IntrCallback callback)
{
    SetVBlankCallback(callback);
}

void sub_81C760C(void)
{
    SetVBlankCallback(sub_81C7418);
}

void *sub_81C761C(u32 index, u32 size)
{
    return gUnknown_0203CF40->field10[index] = (void*)Alloc(size);
}

void *sub_81C763C(u32 index)
{
    return gUnknown_0203CF40->field10[index];
}

void sub_81C7650(u32 index)
{
    if (gUnknown_0203CF40->field10[index] != NULL)
        FREE_AND_SET_NULL(gUnknown_0203CF40->field10[index]);
}

u16 sub_81C767C(void)
{
    return gUnknown_0203CF40->field8;
}

void sub_81C7688(u16 a0)
{
    gUnknown_0203CF40->field8 = a0;
}

void sub_81C7694(u32 a0)
{
    u32 value;
    value = a0;
    if (a0 > 4)
        value = 0;
    gUnknown_0203CF40->fieldA = value;
}

u16 sub_81C76AC(void)
{
    return gUnknown_0203CF40->fieldA;
}

u32 sub_81C76B8(void)
{
    return gUnknown_0203CF40->fieldC;
}

bool32 sub_81C76C4(void)
{
    struct UnknownStruct_sub_81C76C4 *v1;

    v1 = (struct UnknownStruct_sub_81C76C4*)sub_81C761C(0, sizeof(struct UnknownStruct_sub_81C76C4));
    if (v1 == NULL)
    {
        return FALSE;
    }
    else
    {
        ResetSpriteData();
        FreeAllSpritePalettes();
        v1->data[3] = sub_81C7078(sub_81C7764, 1);
        return TRUE;
    }
}

u32 sub_81C76FC(void)
{
    u32 *v1;
    v1 = sub_81C763C(0);
    return sub_81C70D8(v1[3]);
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
    } else
    {
        return TRUE;
    }
}

u32 sub_81C7764(s32 a0)
{
    u32 *v1;

    switch (a0)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, &gUnknown_0861FA04, 1);
        sub_8199D98();
        reset_temp_tile_data_buffers();
        return 1;
    case 1:
        v1 = sub_81C763C(0);
        decompress_and_copy_tile_data_to_vram(0, &gPokenavHeader_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(0, &v1[11]);
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

void sub_81C7834(u32 (*a0)(void), u32(*a1)(void))
{
    u32 (**v1)(void);

    v1 = sub_81C763C(0);
    v1[0] = a0;
    v1[1] = a1;
    v1[2] = NULL;
}

void sub_81C7850(u32 a0)
{
    void (**v1)(u32);

    v1 = sub_81C763C(0);
    v1[2] = NULL;
    v1[0](a0);
}

u32 sub_81C786C(void)
{
    u32 (**v1)(void);

    v1 = sub_81C763C(0);
    return v1[1]();
}

void sub_81C7880(void)
{
    u32 *v1;
    
    v1 = sub_81C763C(0);
    v1[3] = sub_81C7078(atk47_cmd47, 4);
}

void sub_81C78A0(void)
{
    u32 *v1;

    v1 = sub_81C763C(0);
    v1[3] = sub_81C7078(sub_81C791C, 4);
}

bool32 sub_81C78C0(void)
{
    u32 *v1;

    v1 = sub_81C763C(0);
    return sub_81C70D8(v1[3]);
}

u32 atk47_cmd47(s32 a0)
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
        if ((u32)ChangeBgY(0, 384, 1) >= 0x2000)
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

void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size) {
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
void sub_81C79BC(u16 *a0, u16 *a1, u32 a2, u32 a3, u32 unused, u32 a5, u32 a6)
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
    u32 *v1;
    v1 = sub_81C763C(0);
    switch (a0)
    {
    case 0:
        BeginNormalPaletteFade(v1[5], -2, 0, 16, RGB_BLACK);
        break;
    case 1:
        BeginNormalPaletteFade(v1[5], -2, 16, 0, RGB_BLACK);
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

void sub_81C7B54(const struct BgTemplate *a0, s32 a1)
{
    s32 i;
    if (a1 <= 0)
        return;
    for (i = a1; i != 0; i--)
    {
        InitBgFromTemplate(a0++);
    }
}

void sub_81C7B74(void)
{
    u32 *v1;

    v1 = sub_81C763C(0);
    InitWindows(&gUnknown_0861FA08[0]);
    v1[4] = 0;
    sub_81C7BF8(0);
    PutWindowTilemap(v1[4]);
    CopyWindowToVram(v1[4], 3); // TODO: Use a defined constant here.
}

void sub_81C7BA4(u32 a0)
{
    u32 *v1;

    v1 = sub_81C763C(0);
    sub_81C7BF8(v1[4]);
    AddTextPrinterParameterized3(v1[4], 1, 0, 1, gMenuButtonReminderColor, 0, MenuButtonReminders[a0]);
}

bool8 sub_81C7BE8(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

void sub_81C7BF8(u32 a0)
{
    FillWindowPixelBuffer(a0, 0x44);
    FillWindowPixelRect(a0, 0x55, 0, 0, 0x80, 1);
}

void sub_81C7C28(void)
{
    u32 *v1;
    u32 i;
    u8 v2;
    u32 v3;
    u32 v4;
    u8 spriteId;

    v1 = sub_81C763C(0);
    for (i = 0; i < ARRAY_COUNT(gUnknown_0861FA4C); i++)
    {
        LoadCompressedSpriteSheet(&gUnknown_0861FA4C[i]);
    }

    sub_81C795C(gUnknown_0861FA54);
    v2 = IndexOfSpritePaletteTag(0);
    v1[5] = ~1 & ~(0x10000 << v2);
    spriteId = CreateSprite(&gUnknown_0861FB04, 220, 12, 0);
    v1[6] = (u32)(&gSprites[spriteId]);
}

void sub_81C7C94(void)
{
    void **v1;
    v1 = sub_81C763C(0);
    DestroySprite(v1[6]);
    FreeSpriteTilesByTag(0);
    FreeSpritePaletteByTag(0);
}

void sub_81C7CB4(u16 *a0)
{
    u32 v1;
    v1 = GetBgY(0);
    a0[19] = (v1 >> 8) * -1;
}

struct Sprite *sub_81C7CCC(void)
{
    struct Sprite **v1;
    struct Sprite *v2;
    v1 = sub_81C763C(0);
    v2 = v1[6];
    v2->callback = SpriteCallbackDummy;
    return v2;
}
