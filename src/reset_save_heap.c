#include "global.h"
#include "main.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "overworld.h"
#include "alloc.h"

void ResetSaveHeap(void)
{
    u16 imeBackup;

    imeBackup = REG_IME;
    REG_IME = 0;
    RegisterRamReset(0x00000001);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_FORCED_BLANK);
    REG_IME = imeBackup;
    gMain.inBattle = FALSE;
    ValidateSave();
    SetSaveBlocksPointers(GetTrainerNumerSum());
    ResetMenuAndMonGlobals();
    Save_ResetSaveCounters();
    Save_LoadGameData(0);
    if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
        Sav2_ClearSetDefault();
    SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
    InitHeap(gHeap, HEAP_SIZE);
    SetMainCallback2(CB2_ContinueSavedGame);
}
