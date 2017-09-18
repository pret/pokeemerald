
// Includes
#include "global.h"
#include "multiboot.h"
#include "gpu_regs.h"
#include "main.h"
#include "sprite.h"
#include "task.h"
#include "unknown_task.h"
#include "malloc.h"
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
void sub_81BF5A4(void);
u32 sub_81BF7A4(u8);

// .rodata

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
