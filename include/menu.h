#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "window.h"

struct MenuAction
{
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
    } func;
};

void box_print(u8, u8, u8, u8, const void *, s8, const u8 *);
void sub_8198070(u8 windowId, bool8 copyToVram);
void SetWindowTemplateFields(struct WindowTemplate* template, u8 priority, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 palNum, u16 baseBlock);
void SetWindowBorderStyle(u8 windowId, bool8 copyToVram, u16 tileStart, u8 palette);
void schedule_bg_copy_tilemap_to_vram(u8 bgNum);
void PrintMenuTable(u8 idx, u8 nstrs, const struct MenuAction *strs);
void InitMenuInUpperLeftCornerPlaySoundWhenAPressed(u8 idx, u8 nstrs,u8);
u8 GetMenuCursorPos(void);
s8 ProcessMenuInput(void);
s8 ProcessMenuInputNoWrapAround(void);
void blit_move_info_icon(u8 winId, u8 a2, u16 x, u16 y);
void reset_temp_tile_data_buffers(void);
int decompress_and_copy_tile_data_to_vram(u8 bg_id, const void *src, int size, u16 offset, u8 mode);
bool8 free_temp_tile_data_buffers_if_possible(void);
u64 sub_8198A50(struct WindowTemplate*, u8, u8, u8, u8, u8, u8, u16); // returns something but it isn't used, fix when menu.s is decomp'd
void CreateYesNoMenu(const struct WindowTemplate *windowTemplate, u16 borderFirstTileNum, u8 borderPalette, u8 initialCursorPos);
s8 sub_8198C58(void);
void copy_decompressed_tile_data_to_vram_autofree(u8 arg0, const void *arg1, bool32 arg2, u16 arg3, u8 arg4);

#endif // GUARD_MENU_H
