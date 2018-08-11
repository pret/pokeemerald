#ifndef GUARD_SCRIPT_MENU_H
#define GUARD_SCRIPT_MENU_H

extern const u8 *const gUnknown_0858BAF0[9];

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 var3, u8 var4);
bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 var3, u8 var4, u8 var5);
bool8 ScriptMenu_YesNo(u8 var1, u8 var2);
bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 a4, u8 columnCount);
bool8 ScriptMenu_ShowPokemonPic(u16 var1, u8 var2, u8 var3);
bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void);
s32 convert_pixel_width_to_tile_width(s32);
u8 CreateWindowFromRect(u8, u8, u8, u8);
void sub_80E2A78(u8);
u32 display_text_and_get_width(const u8*, u32);

#endif //GUARD_SCRIPT_MENU_H
