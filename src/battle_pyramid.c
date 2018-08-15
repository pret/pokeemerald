#include "global.h"
#include "main.h"
#include "battle_controllers.h"
#include "bg.h"
#include "field_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "task.h"
#include "constants/rgb.h"

EWRAM_DATA struct
{
    u32 unk0;
    u8 filler4[0x804 - 0x4];
    u8 unk804[11];
    u8 unk80F[5];
    u8 unk814;
    u8 filler815;
    s8 unk816;
    u8 filler817[0x984 - 0x817];
    u16 unk984;
    u8 filler986[0x98C - 0x986];
} *gUnknown_0203CF2C = NULL;
EWRAM_DATA struct
{
    void (*callback)(void);
    u8 unk4;
    u16 unk6;
    u16 unk8;
} gUnknown_0203CF30 = {0};

extern const struct BgTemplate gUnknown_0861F2B4[3];

void sub_81C4F98(u8 a0, void (*callback)(void));
void sub_81C4F44(u8 taskId);
void sub_81C504C(void);
bool8 sub_81C5078(void);
void sub_81C51DC(void);
bool8 sub_81C5238(void);
void sub_81C5314(void);
void sub_81C5674(void);
void sub_81C56F8(void);
void sub_81C5924(void);
void sub_81C59BC(void);
void sub_81C5A20(void);
void sub_81C6BD8(void);
void sub_81C6EF4(void);
void sub_81C700C(void);

void sub_81C4EEC(void)
{
    gUnknown_0203CF30.unk6 = 0;
    gUnknown_0203CF30.unk8 = 0;
}

void sub_81C4EFC(void)
{
    sub_81C4F98(0, CB2_ReturnToFieldWithOpenMenu);
}

void sub_81C4F10(void)
{
    sub_81C4F98(1, SetCB2ToReshowScreenAfterMenu2);
}

void sub_81C4F24(void)
{
    ScriptContext2_Enable();
    FadeScreen(1, 0);
    CreateTask(sub_81C4F44, 10);
}

void sub_81C4F44(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        gFieldCallback2 = hm_add_c3_without_phase_2;
        sub_81C4F98(3, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void sub_81C4F84(void)
{
    sub_81C4F98(4, gUnknown_0203CF30.callback);
}

void sub_81C4F98(u8 a0, void (*callback)(void))
{
    gUnknown_0203CF2C = AllocZeroed(sizeof(*gUnknown_0203CF2C));

    if (a0 != 4)
    {
        gUnknown_0203CF30.unk4 = a0;
    }

    if (callback != NULL)
    {
        gUnknown_0203CF30.callback = callback;
    }

    gUnknown_0203CF2C->unk0 = 0;
    gUnknown_0203CF2C->unk814 = -1;
    gUnknown_0203CF2C->unk816 = -1;

    memset(gUnknown_0203CF2C->unk804, 0xFF, sizeof(gUnknown_0203CF2C->unk804));
    memset(gUnknown_0203CF2C->unk80F, 0xFF, sizeof(gUnknown_0203CF2C->unk80F));
    
    SetMainCallback2(sub_81C504C);
}

void sub_81C501C(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void sub_81C5038(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_81C504C(void)
{
    while (sub_81221EC() != TRUE && sub_81C5078() != TRUE && sub_81221AC() != TRUE);
}

bool8 sub_81C5078(void)
{
    switch (gMain.state)
    {
        case 0:
            SetVBlankHBlankCallbacksToNull();
            clear_scheduled_bg_copies_to_vram();
            gMain.state++;
            break;
        case 1:
            ScanlineEffect_Stop();
            gMain.state++;
            break;
        case 2:
            FreeAllSpritePalettes();
            gMain.state++;
            break;
        case 3:
            ResetPaletteFade();
            gPaletteFade.bufferTransferDisabled = TRUE;
            gMain.state++;
            break;
        case 4:
            ResetSpriteData();
            gMain.state++;
            break;
        case 5:
            if (!sub_81221AC())
            {
                ResetTasks();
            }
            gMain.state++;
            break;
        case 6:
            sub_81C51DC();
            gUnknown_0203CF2C->unk984 = 0;
            gMain.state++;
            break;
        case 7:
            if (sub_81C5238())
            {
                gMain.state++;
            }
            break;
        case 8:
            sub_81C6BD8();
            gMain.state++;
            break;
        case 9:
            sub_81C5924();
            sub_81C59BC();
            sub_81C5A20();
            gMain.state++;
            break;
        case 10:
            sub_81C5314();
            gMain.state++;
            break;
        case 11:
            sub_81C56F8();
            gMain.state++;
            break;
        case 12:
            sub_81C6EF4();
            gMain.state++;
            break;
        case 13:
            sub_81C5674();
            gMain.state++;
            break;
        case 14:
            sub_81C700C();
            gMain.state++;
            break;
        case 15:
            BlendPalettes(0xFFFFFFFF, 0x10, 0);
            gMain.state++;
            break;
        case 16:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            gPaletteFade.bufferTransferDisabled = FALSE;
            gMain.state++;
            break;
        default:
            SetVBlankCallback(sub_81C5038);
            SetMainCallback2(sub_81C501C);
            return TRUE;
    }
    return FALSE;
}

void sub_81C51DC(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0861F2B4, ARRAY_COUNT(gUnknown_0861F2B4));
    SetBgTilemapBuffer(2, gUnknown_0203CF2C->filler4);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP | 
                                  DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}
