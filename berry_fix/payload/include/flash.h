#ifndef GUARD_FLASH_H
#define GUARD_FLASH_H

#include "gba/gba.h"

enum
{
    SECTOR_DAMAGED,
    SECTOR_OK,
    SECTOR_CHECK, // unused
};

enum MsgBoxUpdateMessage
{
    MSGBOX_WILL_NOW_UPDATE = 0,
    MSGBOX_HAS_BEEN_UPDATED,
    MSGBOX_UNABLE_TO_UPDATE,
    MSGBOX_NO_NEED_TO_UPDATE,
    MSGBOX_UPDATING
};

struct SaveSector
{
    u8 data[0xFF4];
    u16 id;
    u16 checksum;
    u32 signature;
    u32 counter;
}; // size is 0x1000

// headless save section?
struct UnkSaveSection
{
    u8 data[0xFF4];
    u32 signature;
}; // size is 0xFF8

#define eSaveSection ((struct SaveSector *)0x2020000)

#define NUM_SECTORS_PER_SAVE_SLOT 14  // Number of sectors occupied by a save slot
#define FILE_SIGNATURE 0x08012025

#define SAVE_STATUS_EMPTY 0
#define SAVE_STATUS_OK 1
#define SAVE_STATUS_NO_FLASH 4
#define SAVE_STATUS_ERROR 0xFF

bool32 flash_maincb_ident_is_valid(void);
bool8 flash_maincb_read_save(u32);
void msg_load_gfx(void);
void msg_display(enum MsgBoxUpdateMessage);
bool32 flash_maincb_check_need_reset_pacifidlog_tm(void);
bool32 flash_maincb_reset_pacifidlog_tm(void);

#endif //GUARD_FLASH_H
