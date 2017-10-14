#include "global.h"
#include "main.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "overworld.h"
#include "malloc.h"

void sub_81700F8(void)
{
    u16 imeBackup;

    imeBackup = REG_IME;
    REG_IME = 0;
    RegisterRamReset(0x00000001);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, 0x80);
    REG_IME = imeBackup;
    gMain.inBattle = FALSE;
    SetSaveBlocksPointers(sub_815355C());
    sub_808447C();
    ResetSaveCounters();
    sub_81534D0(0);
    if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
    {
        Sav2_ClearSetDefault();
    }
    SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
    InitHeap(gHeap, 0x1c000);
    SetMainCallback2(sub_8086230);
}
