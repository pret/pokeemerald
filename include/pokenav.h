#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H
#include "player_pc.h"
#include "list_menu.h"

bool8 sub_81D20BC(void *arg0);
bool8 sub_81D312C(void *arg0);
void sub_81D1ED4(void *arg0);
void sub_81D2108(void *arg0);
void sub_81D20AC(void *arg0);
void sub_81D2230(void *arg0);
void sub_81D3464(void *arg0);
void sub_81D3480(void *arg0, u8 arg1);
void sub_81D2754(void *arg0, void *arg1);
void sub_81D1F84(void *arg0, void *arg1, void *arg2);
u8 sub_81D1C84(u8);
u8 sub_81D1DC0(struct PlayerPCItemPageStruct *);
void sub_81D1E90(struct PlayerPCItemPageStruct *);
void sub_81D1EC0(void);
void sub_81D1D04(u8);
bool8 sub_81D1C44(u8);
bool8 sub_81D4A58(struct EventObject*);
void sub_81D2BF4(u8 *);
u16 sub_81D2C3C(void);
void sub_81D2C50(void);
u8 sub_81D28C8(const struct ListMenuItem *items, u16 numChoices);
void sub_81D2824(u16);
bool8 EventObjectIsFarawayIslandMew(struct EventObject *);
u32 sub_81D427C(void);
void sub_81D4998(void);
void sub_81D3640(u16 arg0, void* statStoreLocation1, void* statStoreLocation2, u8 arg3, u8 arg4, u8 arg5);
void sub_81D3784(u16 arg0, void* statStoreLocation1, u8 arg2, u8 arg3, u8 arg4);

#endif //GUARD_POKENAV_H
