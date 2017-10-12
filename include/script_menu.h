#ifndef GUARD_SCRIPTMENU_H
#define GUARD_SCRIPTMENU_H

extern const u8 *const gUnknown_0858BAF0[];

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 var3, u8 var4);
bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 var3, u8 var4, u8 var5);
bool8 ScriptMenu_YesNo(u8 var1, u8 var2);
bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 a4, u8 columnCount);
bool8 ScriptMenu_ShowPokemonPic(u16 var1, u8 var2, u8 var3);
bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void);

#endif
