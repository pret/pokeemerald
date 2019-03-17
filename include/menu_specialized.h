#ifndef GUARD_MENU_SPECIALIZED_H
#define GUARD_MENU_SPECIALIZED_H

#include "player_pc.h"
#include "list_menu.h"
#include "pokemon.h"

struct UnknownSubStruct_81D1ED4
{
    u16 unk0;
    u16 unk2;
};

struct UnknownStruct_81D1ED4
{
    u8 unk0[4][5];
    struct UnknownSubStruct_81D1ED4 unk14[4][5];
    struct UnknownSubStruct_81D1ED4 unk64[10][5];
    struct UnknownSubStruct_81D1ED4 unk12C[5];
    struct UnknownSubStruct_81D1ED4 unk13C[0x42];
    struct UnknownSubStruct_81D1ED4 unk248[0x42];
    u16 unk350;
    u16 unk352;
    u8 unk354;
    u8 unk355;
    u8 unk356[0x22];
};

bool8 sub_81D1C44(u8 count);
u8 sub_81D1C84(u8 a0);
u8 sub_81D1DC0(struct PlayerPCItemPageStruct *page);
void sub_81D1E90(struct PlayerPCItemPageStruct *page);
void sub_81D1EC0(void);
void sub_81D1D04(u8 a0);
void DrawLevelUpWindowPg1(u16 arg0, void* statStoreLocation1, void* statStoreLocation2, u8 arg3, u8 arg4, u8 arg5);
void DrawLevelUpWindowPg2(u16 arg0, void* statStoreLocation1, u8 arg2, u8 arg3, u8 arg4);
void sub_81D1ED4(struct UnknownStruct_81D1ED4 *a0);
void sub_81D2108(struct UnknownStruct_81D1ED4 *arg0);
void sub_81D20AC(struct UnknownStruct_81D1ED4 *arg0);
void sub_81D2230(struct UnknownStruct_81D1ED4 *arg0);
bool8 sub_81D20BC(struct UnknownStruct_81D1ED4 *arg0);
void sub_81D3464(void *arg0);
void sub_81D3480(void *arg0, u8 arg1);
void sub_81D2754(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 *arg1);
void sub_81D1F84(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 arg1[4][5], struct UnknownSubStruct_81D1ED4 arg2[4][5]);
void MoveRelearnerPrintText(u8 *str);
bool16 MoveRelearnerRunTextPrinters(void);
void MoveRelearnerCreateYesNoMenu(void);
u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices);
void InitMoveRelearnerWindows(bool8 useContextWindow);
void GetMonLevelUpWindowStats(struct Pokemon* mon, void* statStoreLocation);

#endif // GUARD_MENU_SPECIALIZED_H