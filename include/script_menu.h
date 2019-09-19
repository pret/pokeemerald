#ifndef GUARD_SCRIPT_MENU_H
#define GUARD_SCRIPT_MENU_H

extern const u8 *const gStdStrings[];

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 var3, u8 var4);
bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 var3, u8 var4, u8 var5);
bool8 ScriptMenu_YesNo(u8 var1, u8 var2);
bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 a4, u8 columnCount);
bool8 ScriptMenu_ShowPokemonPic(u16 var1, u8 var2, u8 var3);
bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void);
int ConvertPixelWidthToTileWidth(int);
u8 CreateWindowFromRect(u8, u8, u8, u8);
void ClearToTransparentAndRemoveWindow(u8);
int DisplayTextAndGetWidth(const u8*, int);
int ScriptMenu_AdjustLeftCoordFromWidth(int arg0, int tileWidth);
bool16 ScriptMenu_CreatePCMultichoice(void);
void ScriptMenu_DisplayPCStartupPrompt(void);

#endif //GUARD_SCRIPT_MENU_H
