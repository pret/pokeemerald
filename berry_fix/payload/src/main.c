#include "gba/gba.h"
#include "global.h"
#include "main.h"
#include "rtc.h"
#include "flash.h"

static s32 gInitialWaitTimer;
IntrFunc gIntrTable[16];
u16 gHeldKeys;
u16 gNewKeys;
u8 gIntrVector[0x100];
u32 gUpdateSuccessful;
u32 gUnknown_3001194;
u32 gUnknown_30011A0[0x19];
u32 gMainCallbackState;
u32 gGameVersion;

EWRAM_DATA u8 gSharedMem[0x8000] = {};

void IntrMain(void);
void ReadKeys(void);
void dummy_intr_0(void);
void dummy_intr_1(void);
void main_callback(u32 *, void *, void *);


const char gBerryFixGameCode[] = "AGBJ";
const IntrFunc gIntrFuncPointers[] = {
    dummy_intr_0,
    dummy_intr_1,
    dummy_intr_0,
    dummy_intr_0,
    dummy_intr_0,
    dummy_intr_0,
    dummy_intr_0,
    dummy_intr_0,
    dummy_intr_0,
    dummy_intr_0,
    NULL,
    NULL,
    NULL
};
const char gVersionData[][2] = {
    {'J', 1},
    {'E', 2},
    {'D', 1},
    {'F', 1},
    {'I', 1},
    {'S', 1}
};
const char gRubyTitleAndCode[] = "POKEMON RUBYAXV";
const char gSapphireTitleAndCode[] = "POKEMON SAPPAXP";
const u16 sDebugPals[20] = {
    RGB(00, 00, 00),
    RGB(31, 00, 00),
    RGB(00, 31, 00),
    RGB(00, 00, 31)
};
const u16 sDebugDigitsGfx[] = INCBIN_U16("graphics/debug_digits.4bpp");

void AgbMain(void)
{
    RegisterRamReset(0x1E);
    DmaCopy32(3, gIntrFuncPointers, gIntrTable, sizeof gIntrFuncPointers);
    DmaCopy32(3, IntrMain, gIntrVector, sizeof(gIntrVector));
    INTR_VECTOR = gIntrVector;
    REG_IE = INTR_FLAG_VBLANK;
    if (*RomHeaderMagic == 0x96 && *(u32 *)RomHeaderGameCode == *(u32 *)gBerryFixGameCode)
        REG_IE |= INTR_FLAG_GAMEPAK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = INTR_FLAG_VBLANK;
    msg_load_gfx();
    gMainCallbackState = MAINCB_INIT;
    gUnknown_3001194 = 0;
    for (;;)
    {
        VBlankIntrWait();
        ReadKeys();
        main_callback(&gMainCallbackState, gUnknown_30011A0, gSharedMem);
    }
}

void dummy_intr_1(void)
{}

void dummy_intr_0(void)
{}

void ReadKeys(void)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    gNewKeys = keyInput & ~gHeldKeys;
    gHeldKeys = keyInput;
}

void fill_palette(const u8 * src, u16 * dest, u8 value)
{
    s32 i;
    for (i = 0; src[i] != 0; i++)
        dest[i] = src[i] | value << 12;
}

bool32 berry_fix_memcmp(const char * src1, const char * src2, size_t size)
{
    s32 i;
    for (i = 0; i < size; i++)
    {
        if (src1[i] != src2[i])
            return FALSE;
    }
    return TRUE;
}

s32 validate_rom_header_internal(void)
{
    char languageCode = *(RomHeaderGameCode + 3);
    s32 softwareVersion = *RomHeaderSoftwareVersion;
    s32 shouldUpdate = -1;
    s32 i;
    for (i = 0; i < ARRAY_COUNT(gVersionData); i++)
    {
        if (languageCode == gVersionData[i][0])
        {
            if (softwareVersion >= gVersionData[i][1])
            {
                shouldUpdate = 0;
            }
            else
            {
                shouldUpdate = 1;
            }
            break;
        }
    }
    if (shouldUpdate != -1)
    {
        if (berry_fix_memcmp(RomHeaderGameTitle, gRubyTitleAndCode, 15) == TRUE)
        {
            if (shouldUpdate == 0)
                return RUBY_NONEED;
            else
            {
                gGameVersion = VERSION_RUBY;
                return RUBY_UPDATABLE;
            }
        }
        else if (berry_fix_memcmp(RomHeaderGameTitle, gSapphireTitleAndCode, 15) == TRUE)
        {
            if (shouldUpdate == 0)
                return SAPPHIRE_NONEED;
            else
            {
                gGameVersion = VERSION_SAPPHIRE;
                return SAPPHIRE_UPDATABLE;
            }
        }
    }
    return INVALID;
}

s32 validate_rom_header(void)
{
    if (*RomHeaderMakerCode == '0' && *(RomHeaderMakerCode + 1) == '1' && *RomHeaderMagic == 0x96)
        return validate_rom_header_internal();
    else
        return INVALID;
}

void main_callback(u32 * state, void * unused1, void * unused2)
{
    u8 year;
    switch (*state)
    {
        case MAINCB_INIT:
            msg_display(MSGBOX_WILL_NOW_UPDATE);
            if (++gInitialWaitTimer >= 180)
            {
                gInitialWaitTimer = 0;
                gUpdateSuccessful = 0;
                switch (validate_rom_header())
                {
                    case SAPPHIRE_UPDATABLE:
                    case RUBY_UPDATABLE: // Should Update Ruby
                        ++(*state); // MAINCB_CHECK_RTC
                        break;
                    case INVALID: // Invalid header
                        *state = MAINCB_ERROR;
                        break;
                    case SAPPHIRE_NONEED: // Should not update Sapphire
                    case RUBY_NONEED: // Should not update Ruby
                        *state = MAINCB_NO_NEED_TO_FIX;
                        break;
                }
            }
            break;
        case MAINCB_CHECK_RTC:
            if (!rtc_maincb_is_rtc_working())
                *state = MAINCB_ERROR;
            else
                ++(*state); // MAINCB_CHECK_FLASH
            break;
        case MAINCB_CHECK_FLASH:
            if (flash_maincb_ident_is_valid() == TRUE)
                ++(*state); // MAINCB_READ_SAVE
            else
                *state = MAINCB_ERROR;
            break;
        case MAINCB_READ_SAVE:
            if (flash_maincb_read_save(0) == SAVE_STATUS_OK)
                ++(*state); // MAINCB_CHECK_TIME
            else
                *state = MAINCB_ERROR;
            break;
        case MAINCB_CHECK_TIME:
            if (rtc_maincb_is_time_since_last_berry_update_positive(&year) == TRUE)
            {
                if (year == 0)
                    ++(*state); // MAINCB_FIX_DATE
                else
                    *state = MAINCB_CHECK_PACIFIDLOG_TM;
            }
            else
            {
                if (year != 1)
                    *state = MAINCB_YEAR_MAKES_NO_SENSE;
                else
                    ++(*state); // MAINCB_FIX_DATE
            }
            break;
        case MAINCB_FIX_DATE:
            rtc_maincb_fix_date();
            gUpdateSuccessful |= 1;
            *state = MAINCB_CHECK_PACIFIDLOG_TM;
            break;
        case MAINCB_CHECK_PACIFIDLOG_TM:
            if (flash_maincb_check_need_reset_pacifidlog_tm() == TRUE)
                *state = MAINCB_FINISHED;
            else
                *state = MAINCB_FIX_PACIFIDLOG_TM;
            break;
        case MAINCB_FIX_PACIFIDLOG_TM:
            msg_display(MSGBOX_UPDATING);
            if (flash_maincb_reset_pacifidlog_tm() == TRUE)
            {
                gUpdateSuccessful |= 1;
                *state = MAINCB_FINISHED;
            }
            else
                *state = MAINCB_ERROR;
            break;
        case MAINCB_FINISHED:
            if (gUpdateSuccessful == 0)
                *state = MAINCB_NO_NEED_TO_FIX;
            else
                msg_display(MSGBOX_HAS_BEEN_UPDATED);
            break;
        case MAINCB_NO_NEED_TO_FIX:
            msg_display(MSGBOX_NO_NEED_TO_UPDATE);
            break;
        case MAINCB_YEAR_MAKES_NO_SENSE:
            msg_display(MSGBOX_UNABLE_TO_UPDATE);
            break;
        case MAINCB_ERROR:
            msg_display(MSGBOX_UNABLE_TO_UPDATE);
            break;
    }
}

void DBG_LoadDigitsPal(void)
{
    const u16 * src;
    s32 i;
    register vu16 * dest asm("r3") = (vu16 *)BG_PLTT + 1;
    DmaFill16(3, RGB(31, 31, 31), (vu16 *)BG_PLTT, BG_PLTT_SIZE);
    src = sDebugPals;
    for (i = 0; i < 4; i++)
    {
        *dest = *src;
        dest += 16;
        src++;
    }
}

void DBG_LoadDigits(void)
{
    DmaFill16(3, 0x1111, (void *)VRAM + 0x8420, 0x1800);
    DmaCopy32(3, sDebugDigitsGfx, (void *)VRAM + 0x8600, 0x200);
    DBG_LoadDigitsPal();
}
