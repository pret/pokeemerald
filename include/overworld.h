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

void DoWhiteOut(void);
void Overworld_ResetStateAfterFly(void);
void Overworld_ResetStateAfterTeleport(void);
void Overworld_ResetStateAfterDigEscRope(void);
void sub_8084788(void);
void ResetGameStats(void);
void IncrementGameStat(u8 index);
u32 GetGameStat(u8 index);
void SetGameStat(u8 index, u32 value);
void ApplyNewEncryptionKeyToGameStats(u32 newKey);
void LoadMapObjTemplatesFromHeader(void);
void LoadSaveblockMapObjScripts(void);
void Overworld_SetMapObjTemplateCoords(u8 localId, s16 x, s16 y);
void Overworld_SetMapObjTemplateMovementType(u8 localId, u8 movementType);
void mapdata_load_assets_to_gpu_and_full_redraw(void);
struct MapData *get_mapdata_header(void);
void ApplyCurrentWarp(void);
void set_warp2_warp3_to_neg_1(void);
void SetWarpData(struct WarpData *warp, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
bool32 warp_data_is_not_neg_1(struct WarpData *warp);
struct MapHeader *const Overworld_GetMapHeaderByGroupAndId(u16 mapGroup, u16 mapNum);
struct MapHeader *const warp1_get_mapheader(void);
void set_current_map_header_from_sav1_save_old_name(void);
void LoadSaveblockMapHeader(void);
void update_camera_pos_from_warpid(void);
void warp_in(void);
void Overworld_SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void warp1_set_2(s8 mapGroup, s8 mapNum, s8 warpId);
void saved_warp2_set(int unused, s8 mapGroup, s8 mapNum, s8 warpId);
void saved_warp2_set_2(int unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void copy_saved_warp2_bank_and_enter_x_to_warp1(u8 unused);
void sub_8084CCC(u8 a1);
void Overworld_SetWarpDestToLastHealLoc(void);
void Overworld_SetHealLocationWarp(u8 healLocationId);
void sub_8084D5C(s16 a1, s16 a2);
void sub_8084DD4(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);

// to erase later
u8 GetMapTypeByGroupAndId(s8 mapGroup, s8 mapNum);
u8 Overworld_GetMapTypeOfSaveblockLocation(void);
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
bool8 Overworld_MapTypeAllowsTeleportAndFly(u8 mapType);
void Overworld_ResetStateAfterTeleport(void);
void Overworld_SetFlashLevel(s32 a1);
//u8 Overworld_GetFlashLevel(void);
void sub_8085524(u16);
void Overworld_SetSavedMusic(u16);
void Overworld_ChangeMusicToDefault(void);
void Overworld_ChangeMusicTo(u16);
bool32 is_c1_link_related_active(void);
extern u16 gUnknown_03005DA8;
void strange_npc_table_clear(void);
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
u8 get_map_light_from_warp0(void);
bool8 is_light_level_1_2_3_5_or_6(u8 a1);
bool32 sub_80875C8(void);
bool32 sub_8087634(void);
bool32 sub_808766C(void);
void IncrementGameStat(u8);
u32 GetGameStat(u8);
void CB2_OverworldBasic(void);

#endif //GUARD_ROM4_H
