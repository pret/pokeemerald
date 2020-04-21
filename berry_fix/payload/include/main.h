#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "gba/gba.h"

enum RomHeaderValidationResult
{
    SAPPHIRE_UPDATABLE = 2,
    RUBY_UPDATABLE,
    SAPPHIRE_NONEED,
    RUBY_NONEED,
    INVALID
};

enum MainCallbackState
{
    MAINCB_INIT = 0,
    MAINCB_CHECK_RTC,
    MAINCB_CHECK_FLASH,
    MAINCB_READ_SAVE,
    MAINCB_CHECK_TIME,
    MAINCB_FIX_DATE,
    MAINCB_NO_NEED_TO_FIX,
    MAINCB_YEAR_MAKES_NO_SENSE,
    MAINCB_FINISHED,
    MAINCB_CHECK_PACIFIDLOG_TM,
    MAINCB_FIX_PACIFIDLOG_TM,
    MAINCB_ERROR
};

extern IntrFunc gIntrTable[];
extern u16 gHeldKeys;
extern u16 gNewKeys;
extern u8 gIntrVector[];
extern u32 gUpdateSuccessful;
extern u32 gUnknown_3001194;
extern u32 gUnknown_30011A0[];
extern u32 gMainCallbackState;
extern u32 gGameVersion;

extern u8 gSharedMem[0x8000];

extern const IntrFunc gIntrFuncPointers[];

#endif //GUARD_MAIN_H
