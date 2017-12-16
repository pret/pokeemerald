#ifndef GUARD_ROM4_H
#define GUARD_ROM4_H

#include "main.h"

struct UnkPlayerStruct
{
    u8 player_field_0;
    u8 player_field_1;
};

struct LinkPlayerMapObject
{
    u8 active;
    u8 linkPlayerId;
    u8 mapObjId;
    u8 mode;
};

struct UCoords32
{
    u32 x, y;
};

extern struct LinkPlayerMapObject gLinkPlayerMapObjects[4];
extern MainCallback gFieldCallback;

void Overworld_SetMapObjTemplateCoords(u8, s16, s16);
void Overworld_SetMapObjTemplateMovementType(u8, u8);

void Overworld_SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);

void saved_warp2_set(int unused, s8 mapGroup, s8 mapNum, s8 warpId);
void saved_warp2_set_2(int unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void Overworld_SetHealLocationWarp(u8);
void sub_8084DD4(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void sub_8084E2C(s8, s8, s8, s8, s8);
void sub_8084E80(s8, s8, s8, s8, s8);
void sub_8084EBC(s16, s16);

void player_avatar_init_params_reset(void);

void Overworld_SetFlashLevel(s32 a1);
//u8 Overworld_GetFlashLevel(void);
void sub_8085524(u16);

void Overworld_SetSavedMusic(u16);
void Overworld_ChangeMusicToDefault(void);
void Overworld_ChangeMusicTo(u16);

bool32 is_c1_link_related_active(void);
extern u16 gUnknown_03005DA8;

void strange_npc_table_clear(void);
const struct MapHeader *get_mapheader_by_bank_and_number(u16, u16);
void FieldObjectMoveDestCoords(struct MapObject *, u32, s16 *, s16 *);
void sub_8086230(void);
void c2_exit_to_overworld_2_switch(void);
bool32 sub_8087598(void);
void c2_exit_to_overworld_1_continue_scripts_restart_music(void);
void warp_in(void);
u8 get_map_light_level_by_bank_and_number(s8 mapGroup, s8 mapNum);
void sub_8086194(void);
void sub_8084CCC(u8 spawn);
void warp1_set_2(s8 mapGroup, s8 mapNum, s8 warpNum);
void c2_load_new_map(void);
void copy_saved_warp2_bank_and_enter_x_to_warp1(u8 unused);
void mapldr_default(void);

bool32 sub_80875C8(void);
bool32 sub_8087634(void);
bool32 sub_808766C(void);
void IncrementGameStat(u8);
u32 GetGameStat(u8);

#endif //GUARD_ROM4_H
