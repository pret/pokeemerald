#ifndef GUARD_UI_MENU_H
#define GUARD_UI_MENU_H

#include "main.h"

void Task_OpenMenuFromStartMenu(u8 taskId);
void Menu_Init(MainCallback callback);

extern const u8 *const gNatureNamePointers[];
extern const u8 gAbilityNames[][ABILITY_NAME_LENGTH + 1];
extern const struct SpeciesInfo gSpeciesInfo[];


#endif // GUARD_UI_MENU_H
