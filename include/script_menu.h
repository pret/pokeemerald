#ifndef GUARD_SCRIPT_MENU_H
#define GUARD_SCRIPT_MENU_H

#include "constants/script_menu.h"

extern const u8 *const gStdStrings[];

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress);
bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice);
bool8 ScriptMenu_YesNo(u8 left, u8 top);
bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 columnCount);
bool8 ScriptMenu_ShowPokemonPic(u16 species, u8 x, u8 y);
bool8 (*ScriptMenu_HidePokemonPic(void))(void);
int ConvertPixelWidthToTileWidth(int width);
u8 CreateWindowFromRect(u8 x, u8 y, u8 width, u8 height);
void ClearToTransparentAndRemoveWindow(u8 windowId);
int DisplayTextAndGetWidth(const u8 *str, int width);
int ScriptMenu_AdjustLeftCoordFromWidth(int left, int width);
bool16 ScriptMenu_CreatePCMultichoice(void);
void ScriptMenu_DisplayPCStartupPrompt(void);

#endif //GUARD_SCRIPT_MENU_H
