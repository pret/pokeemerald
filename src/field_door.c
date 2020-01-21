#include "global.h"
#include "event_data.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "task.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

#define DOOR_SOUND_NORMAL  0
#define DOOR_SOUND_SLIDING 1
#define DOOR_SOUND_ARENA   2

struct DoorGraphics
{
    u16 metatileNum;
    u8 sound;
    u8 size;
    const void *tiles;
    const void *palette;
};

struct DoorAnimFrame
{
    u8 time;
    u16 offset;
};

static bool8 ShouldUseMultiCorridorDoor(void);

const u8 sDoorAnimTiles_Littleroot[][0x100] =
{
    INCBIN_U8("graphics/door_anims/littleroot/0.4bpp"),
    INCBIN_U8("graphics/door_anims/littleroot/1.4bpp"),
    INCBIN_U8("graphics/door_anims/littleroot/2.4bpp"),
};

// TODO: Make these blank palette includes?
asm(".space 32");

const u8 sDoorAnimTiles_BirchsLab[][0x100] =
{
    INCBIN_U8("graphics/door_anims/birchs_lab/0.4bpp"),
    INCBIN_U8("graphics/door_anims/birchs_lab/1.4bpp"),
    INCBIN_U8("graphics/door_anims/birchs_lab/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_FallarborLightRoof[][0x100] =
{
    INCBIN_U8("graphics/door_anims/fallarbor_light_roof/0.4bpp"),
    INCBIN_U8("graphics/door_anims/fallarbor_light_roof/1.4bpp"),
    INCBIN_U8("graphics/door_anims/fallarbor_light_roof/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Lilycove[][0x100] =
{
    INCBIN_U8("graphics/door_anims/lilycove/0.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove/1.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_LilycoveWooden[][0x100] =
{
    INCBIN_U8("graphics/door_anims/lilycove_wooden/0.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove_wooden/1.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove_wooden/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_General[][0x100] =
{
    INCBIN_U8("graphics/door_anims/general/0.4bpp"),
    INCBIN_U8("graphics/door_anims/general/1.4bpp"),
    INCBIN_U8("graphics/door_anims/general/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_PokeCenter[][0x100] =
{
    INCBIN_U8("graphics/door_anims/poke_center/0.4bpp"),
    INCBIN_U8("graphics/door_anims/poke_center/1.4bpp"),
    INCBIN_U8("graphics/door_anims/poke_center/2.4bpp"),
};

const u8 sDoorAnimTiles_Gym[][0x100] =
{
    INCBIN_U8("graphics/door_anims/gym/0.4bpp"),
    INCBIN_U8("graphics/door_anims/gym/1.4bpp"),
    INCBIN_U8("graphics/door_anims/gym/2.4bpp"),
};

const u8 sDoorAnimTiles_PokeMart[][0x100] =
{
    INCBIN_U8("graphics/door_anims/poke_mart/0.4bpp"),
    INCBIN_U8("graphics/door_anims/poke_mart/1.4bpp"),
    INCBIN_U8("graphics/door_anims/poke_mart/2.4bpp"),
};

const u8 sDoorAnimTiles_RustboroTan[][0x100] =
{
    INCBIN_U8("graphics/door_anims/rustboro_tan/0.4bpp"),
    INCBIN_U8("graphics/door_anims/rustboro_tan/1.4bpp"),
    INCBIN_U8("graphics/door_anims/rustboro_tan/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_RustboroGray[][0x100] =
{
    INCBIN_U8("graphics/door_anims/rustboro_gray/0.4bpp"),
    INCBIN_U8("graphics/door_anims/rustboro_gray/1.4bpp"),
    INCBIN_U8("graphics/door_anims/rustboro_gray/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Oldale[][0x100] =
{
    INCBIN_U8("graphics/door_anims/oldale/0.4bpp"),
    INCBIN_U8("graphics/door_anims/oldale/1.4bpp"),
    INCBIN_U8("graphics/door_anims/oldale/2.4bpp"),
};

asm(".space 0x5900");

const u8 sDoorAnimTiles_UnusedTops[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_848EDEC/0_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/1_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/2_top.4bpp"),
};

asm(".space 0x140");

const u8 sDoorAnimTiles_UnusedBottoms[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_848EDEC/0_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/1_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/2_bottom.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Mauville[][0x100] =
{
    INCBIN_U8("graphics/door_anims/mauville/0.4bpp"),
    INCBIN_U8("graphics/door_anims/mauville/1.4bpp"),
    INCBIN_U8("graphics/door_anims/mauville/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Verdanturf[][0x100] =
{
    INCBIN_U8("graphics/door_anims/verdanturf/0.4bpp"),
    INCBIN_U8("graphics/door_anims/verdanturf/1.4bpp"),
    INCBIN_U8("graphics/door_anims/verdanturf/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Slateport[][0x100] =
{
    INCBIN_U8("graphics/door_anims/slateport/0.4bpp"),
    INCBIN_U8("graphics/door_anims/slateport/1.4bpp"),
    INCBIN_U8("graphics/door_anims/slateport/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Dewford[][0x100] =
{
    INCBIN_U8("graphics/door_anims/dewford/0.4bpp"),
    INCBIN_U8("graphics/door_anims/dewford/1.4bpp"),
    INCBIN_U8("graphics/door_anims/dewford/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Contest[][0x100] =
{
    INCBIN_U8("graphics/door_anims/contest/0.4bpp"),
    INCBIN_U8("graphics/door_anims/contest/1.4bpp"),
    INCBIN_U8("graphics/door_anims/contest/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Mossdeep[][0x100] =
{
    INCBIN_U8("graphics/door_anims/mossdeep/0.4bpp"),
    INCBIN_U8("graphics/door_anims/mossdeep/1.4bpp"),
    INCBIN_U8("graphics/door_anims/mossdeep/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_SootopolisPeakedRoof[][0x100] =
{
    INCBIN_U8("graphics/door_anims/sootopolis_peaked_roof/0.4bpp"),
    INCBIN_U8("graphics/door_anims/sootopolis_peaked_roof/1.4bpp"),
    INCBIN_U8("graphics/door_anims/sootopolis_peaked_roof/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Sootopolis[][0x100] =
{
    INCBIN_U8("graphics/door_anims/sootopolis/0.4bpp"),
    INCBIN_U8("graphics/door_anims/sootopolis/1.4bpp"),
    INCBIN_U8("graphics/door_anims/sootopolis/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_PokemonLeague[][0x100] =
{
    INCBIN_U8("graphics/door_anims/pokemon_league/0.4bpp"),
    INCBIN_U8("graphics/door_anims/pokemon_league/1.4bpp"),
    INCBIN_U8("graphics/door_anims/pokemon_league/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_Pacifidlog[][0x100] =
{
    INCBIN_U8("graphics/door_anims/pacifidlog/0.4bpp"),
    INCBIN_U8("graphics/door_anims/pacifidlog/1.4bpp"),
    INCBIN_U8("graphics/door_anims/pacifidlog/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleTowerCorridor[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tower_corridor/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_corridor/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_corridor/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_CyclingRoad[][0x100] =
{
    INCBIN_U8("graphics/door_anims/cycling_road/0.4bpp"),
    INCBIN_U8("graphics/door_anims/cycling_road/1.4bpp"),
    INCBIN_U8("graphics/door_anims/cycling_road/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_LilycoveDeptStore[][0x100] =
{
    INCBIN_U8("graphics/door_anims/lilycove_dept_store/0.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove_dept_store/1.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove_dept_store/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_SafariZone[][0x100] =
{
    INCBIN_U8("graphics/door_anims/safari_zone/0.4bpp"),
    INCBIN_U8("graphics/door_anims/safari_zone/1.4bpp"),
    INCBIN_U8("graphics/door_anims/safari_zone/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_MossdeepSpaceCenter[][0x100] =
{
    INCBIN_U8("graphics/door_anims/mossdeep_space_center/0.4bpp"),
    INCBIN_U8("graphics/door_anims/mossdeep_space_center/1.4bpp"),
    INCBIN_U8("graphics/door_anims/mossdeep_space_center/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_CableClub[][0x100] =
{
    INCBIN_U8("graphics/door_anims/cable_club/0.4bpp"),
    INCBIN_U8("graphics/door_anims/cable_club/1.4bpp"),
    INCBIN_U8("graphics/door_anims/cable_club/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_AbandonedShip[][0x100] =
{
    INCBIN_U8("graphics/door_anims/abandoned_ship/0.4bpp"),
    INCBIN_U8("graphics/door_anims/abandoned_ship/1.4bpp"),
    INCBIN_U8("graphics/door_anims/abandoned_ship/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_FallarborDarkRoof[][0x100] =
{
    INCBIN_U8("graphics/door_anims/fallarbor_dark_roof/0.4bpp"),
    INCBIN_U8("graphics/door_anims/fallarbor_dark_roof/1.4bpp"),
    INCBIN_U8("graphics/door_anims/fallarbor_dark_roof/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_AbandonedShipRoom[][0x100] =
{
    INCBIN_U8("graphics/door_anims/abandoned_ship_room/0.4bpp"),
    INCBIN_U8("graphics/door_anims/abandoned_ship_room/1.4bpp"),
    INCBIN_U8("graphics/door_anims/abandoned_ship_room/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_LilycoveDeptStoreElevator[][0x100] =
{
    INCBIN_U8("graphics/door_anims/lilycove_dept_store_elevator/0.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove_dept_store_elevator/1.4bpp"),
    INCBIN_U8("graphics/door_anims/lilycove_dept_store_elevator/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleTowerOld[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tower_old/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_old/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_old/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleTowerElevator[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tower_elevator/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_elevator/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_elevator/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_34[][0x100] =
{
    INCBIN_U8("graphics/door_anims/unknown/0.4bpp"),
    INCBIN_U8("graphics/door_anims/unknown/1.4bpp"),
    INCBIN_U8("graphics/door_anims/unknown/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleDome[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_dome/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleFactory[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_factory/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_factory/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_factory/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleTower[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tower/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleArena[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_arena/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_arena/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_arena/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleArenaLobby[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_arena_lobby/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_arena_lobby/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_arena_lobby/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleDomeLobby[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_dome_lobby/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome_lobby/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome_lobby/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattlePalaceLobby[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_palace_lobby/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_palace_lobby/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_palace_lobby/2.4bpp"),
};

const u8 sDoorAnimTiles_BattleTent[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tent/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tent/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tent/2.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tent/3.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleDomeCorridor[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_dome_corridor/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome_corridor/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome_corridor/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleTowerMultiCorridor[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor/0_left.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor/0_right.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor/1_left.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor/1_right.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor/2_left.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor/2_right.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleFrontier[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_frontier/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_frontier/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_frontier/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleFrontierSliding[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_frontier_sliding/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_frontier_sliding/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_frontier_sliding/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleDomePreBattleRoom[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_dome_pre_battle_room/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome_pre_battle_room/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_dome_pre_battle_room/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_BattleTentInterior[][0x100] =
{
    INCBIN_U8("graphics/door_anims/battle_tent_interior/0.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tent_interior/1.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tent_interior/2.4bpp"),
    INCBIN_U8("graphics/door_anims/battle_tent_interior/3.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_TrainerHillLobbyElevator[][0x100] =
{
    INCBIN_U8("graphics/door_anims/trainer_hill_lobby_elevator/0.4bpp"),
    INCBIN_U8("graphics/door_anims/trainer_hill_lobby_elevator/1.4bpp"),
    INCBIN_U8("graphics/door_anims/trainer_hill_lobby_elevator/2.4bpp"),
};

asm(".space 32");

const u8 sDoorAnimTiles_TrainerHillRoofElevator[][0x100] =
{
    INCBIN_U8("graphics/door_anims/trainer_hill_roof_elevator/0.4bpp"),
    INCBIN_U8("graphics/door_anims/trainer_hill_roof_elevator/1.4bpp"),
    INCBIN_U8("graphics/door_anims/trainer_hill_roof_elevator/2.4bpp"),
};

asm(".space 32");

static const struct DoorAnimFrame sDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x200},
    {0, 0},
};

static const struct DoorAnimFrame sDoorCloseAnimFrames[] =
{
    {4, 0x200},
    {4, 0x100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x200},
    {4, 0x400},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorCloseAnimFrames[] =
{
    {4, 0x400},
    {4, 0x200},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const u8 sDoorAnimPalettes_General[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_PokeCenter[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_Gym[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_PokeMart[] = {0, 0, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_Littleroot[] = {10, 10, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_BirchsLab[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_RustboroTan[] = {11, 11, 11, 11, 11, 11, 11, 11};
static const u8 sDoorAnimPalettes_RustboroGray[] = {10, 10, 10, 10, 10, 10, 10, 10};
static const u8 sDoorAnimPalettes_FallarborLightRoof[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Lilycove[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Oldale[] = {10, 10, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_Mossdeep[] = {9, 9, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_PokemonLeague[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Pacifidlog[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_SootopolisPeakedRoof[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_Sootopolis[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_Dewford[] = {0, 0, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Slateport[] = {6, 6, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_Mauville[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Verdanturf[] = {6, 6, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_LilycoveWooden[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Contest[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleTowerCorridor[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_CyclingRoad[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_LilycoveDeptStore[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_SafariZone[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_MossdeepSpaceCenter[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_CableClub[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_AbandonedShip[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_FallarborDarkRoof[] = {11, 11, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_AbandonedShipRoom[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_LilycoveDeptStoreElevator[] = {6, 6, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTowerOld[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleTowerElevator[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_34[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleDome[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleFactory[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleTower[] = {0, 0, 0, 0, 0, 0, 0, 0};
static const u8 sDoorAnimPalettes_BattleArena[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_BattleArenaLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleDomeLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattlePalaceLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTent[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleDomeCorridor[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTowerMultiCorridor[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Unused[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleFrontier[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleDomePreBattleRoom[] = {9, 9, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTentInterior[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_TrainerHillLobbyElevator[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_TrainerHillRoofElevator[] = {9, 9, 7, 7, 7, 7, 7, 7};

static const struct DoorGraphics sDoorAnimGraphicsTable[] =
{
    {METATILE_General_Door,                                 DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_General, sDoorAnimPalettes_General},
    {METATILE_General_Door_PokeCenter,                      DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokeCenter, sDoorAnimPalettes_PokeCenter},
    {METATILE_General_Door_Gym,                             DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_Gym, sDoorAnimPalettes_Gym},
    {METATILE_General_Door_PokeMart,                        DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokeMart, sDoorAnimPalettes_PokeMart},
    {METATILE_Petalburg_Door_Littleroot,                    DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Littleroot, sDoorAnimPalettes_Littleroot},
    {METATILE_Petalburg_Door_BirchsLab,                     DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BirchsLab, sDoorAnimPalettes_BirchsLab},
    {METATILE_Rustboro_Door_Tan,                            DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_RustboroTan, sDoorAnimPalettes_RustboroTan},
    {METATILE_Rustboro_Door_Gray,                           DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_RustboroGray, sDoorAnimPalettes_RustboroGray},
    {METATILE_Fallarbor_Door_LightRoof,                     DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FallarborLightRoof, sDoorAnimPalettes_FallarborLightRoof},
    {METATILE_Petalburg_Door_Oldale,                        DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Oldale, sDoorAnimPalettes_Oldale},
    {METATILE_Mauville_Door,                                DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Mauville, sDoorAnimPalettes_Mauville},
    {METATILE_Mauville_Door_Verdanturf,                     DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Verdanturf, sDoorAnimPalettes_Verdanturf},
    {METATILE_Slateport_Door,                               DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Slateport, sDoorAnimPalettes_Slateport},
    {METATILE_Dewford_Door,                                 DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Dewford, sDoorAnimPalettes_Dewford},
    {METATILE_General_Door_Contest,                         DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_Contest, sDoorAnimPalettes_Contest},
    {METATILE_Lilycove_Door,                                DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Lilycove, sDoorAnimPalettes_Lilycove},
    {METATILE_Lilycove_Door_Wooden,                         DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_LilycoveWooden, sDoorAnimPalettes_LilycoveWooden},
    {METATILE_Mossdeep_Door,                                DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Mossdeep, sDoorAnimPalettes_Mossdeep},
    {METATILE_Sootopolis_Door_PeakedRoof,                   DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_SootopolisPeakedRoof, sDoorAnimPalettes_SootopolisPeakedRoof},
    {METATILE_Sootopolis_Door,                              DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Sootopolis, sDoorAnimPalettes_Sootopolis},
    {METATILE_EverGrande_Door_PokemonLeague,                DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokemonLeague, sDoorAnimPalettes_PokemonLeague},
    {METATILE_Pacifidlog_Door,                              DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Pacifidlog, sDoorAnimPalettes_Pacifidlog},
    {METATILE_BattleFrontier_Door_Corridor,                 DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleTowerCorridor, sDoorAnimPalettes_BattleTowerCorridor},
    {METATILE_Mauville_Door_CyclingRoad,                    DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_CyclingRoad, sDoorAnimPalettes_CyclingRoad},
    {METATILE_Lilycove_Door_DeptStore,                      DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_LilycoveDeptStore, sDoorAnimPalettes_LilycoveDeptStore},
    {METATILE_Lilycove_Door_SafariZone,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SafariZone, sDoorAnimPalettes_SafariZone},
    {METATILE_Mossdeep_Door_SpaceCenter,                    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_MossdeepSpaceCenter, sDoorAnimPalettes_MossdeepSpaceCenter},
    {METATILE_PokemonCenter_Door_CableClub,                 DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_CableClub, sDoorAnimPalettes_CableClub},
    {METATILE_InsideShip_IntactDoor_Bottom_Unlocked,        DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_AbandonedShip, sDoorAnimPalettes_AbandonedShip},
    {METATILE_Fallarbor_Door_DarkRoof,                      DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FallarborDarkRoof, sDoorAnimPalettes_FallarborDarkRoof},
    {METATILE_InsideShip_IntactDoor_Bottom_Interior,        DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_AbandonedShipRoom, sDoorAnimPalettes_AbandonedShipRoom},
    {METATILE_Shop_Door_Elevator,                           DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_LilycoveDeptStoreElevator, sDoorAnimPalettes_LilycoveDeptStoreElevator},
    {METATILE_Dewford_Door_BattleTower,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTowerOld, sDoorAnimPalettes_BattleTowerOld},
    {METATILE_BattleFrontier_Door_Elevator,                 DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTowerElevator, sDoorAnimPalettes_BattleTowerElevator},
    {0x3B0, /* TODO: Missing metatile ID */                 DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_34, sDoorAnimPalettes_34},
    {METATILE_BattleFrontierOutsideWest_Door_BattleDome,    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDome, sDoorAnimPalettes_BattleDome},
    {METATILE_BattleFrontierOutsideWest_Door_BattleFactory, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleFactory, sDoorAnimPalettes_BattleFactory},
    {METATILE_BattleFrontierOutsideEast_Door_BattleTower,   DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTower, sDoorAnimPalettes_BattleTower},
    {METATILE_BattleFrontierOutsideEast_Door_BattleArena,   DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleArena, sDoorAnimPalettes_BattleArena},
    {METATILE_BattleArena_Door,                             DOOR_SOUND_ARENA,   1, sDoorAnimTiles_BattleArenaLobby, sDoorAnimPalettes_BattleArenaLobby},
    {METATILE_BattleDome_Door_Lobby,                        DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomeLobby, sDoorAnimPalettes_BattleDomeLobby},
    {METATILE_BattlePalace_Door,                            DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattlePalaceLobby, sDoorAnimPalettes_BattlePalaceLobby},
    {METATILE_Slateport_Door_BattleTent,                    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_Mauville_Door_BattleTent,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_Fallarbor_Door_BattleTent,                    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_BattleDome_Door_Corridor,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomeCorridor, sDoorAnimPalettes_BattleDomeCorridor},
    {METATILE_BattleFrontier_Door_MultiCorridor,            DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_BattleTowerMultiCorridor, sDoorAnimPalettes_BattleTowerMultiCorridor},
    {METATILE_BattleFrontierOutsideWest_Door,               DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleFrontier, sDoorAnimPalettes_BattleFrontier},
    {METATILE_BattleFrontierOutsideWest_Door_Sliding,       DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleFrontierSliding, sDoorAnimPalettes_BattleFrontier},
    {METATILE_BattleDome_Door_PreBattleRoom,                DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomePreBattleRoom, sDoorAnimPalettes_BattleDomePreBattleRoom},
    {METATILE_BattleTent_Door,                              DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTentInterior, sDoorAnimPalettes_BattleTentInterior},
    {METATILE_TrainerHill_Door_Elevator_Lobby,              DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_TrainerHillLobbyElevator, sDoorAnimPalettes_TrainerHillLobbyElevator},
    {METATILE_TrainerHill_Door_Elevator_Roof,               DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_TrainerHillRoofElevator, sDoorAnimPalettes_TrainerHillRoofElevator},
    {},
};

static void CopyDoorTilesToVram(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame)
{
    if (gfx->size == 2)
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7E00), 0x80);
    else
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7F00), 0x40);
}

static void door_build_blockdef(u16 *a, u16 b, const u8 *c)
{
    int i;
    u16 unk;

    for (i = 0; i < 4; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk | (b + i);
    }
    for (; i < 8; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk;
    }
}

static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, u32 x, u32 y, const u8 *pal)
{
    u16 arr[24];
    
    if (gfx->size == 2)
    {
        door_build_blockdef(&arr[8], 0x3F0, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F4, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F8, pal);
        DrawDoorMetatileAt(x + 1, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x + 1, y, &arr[8]);
    }
    else
    {
        door_build_blockdef(&arr[0], 0x3F8, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[0]);
        door_build_blockdef(&arr[0], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[0]);
    }
}

static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    CurrentMapDrawMetatileAt(x, y - 1);
    CurrentMapDrawMetatileAt(x, y);

    if (gfx->size == 2)
    {
        CurrentMapDrawMetatileAt(x + 1, y - 1);
        CurrentMapDrawMetatileAt(x + 1, y);
    }
}

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, u32 x, u32 y)
{
    if (frame->offset == 0xFFFF)
    {
        DrawClosedDoorTiles(gfx, x, y);
        if (ShouldUseMultiCorridorDoor())
            DrawClosedDoorTiles(gfx, gSpecialVar_0x8004 + 7, gSpecialVar_0x8005 + 7);
    }
    else
    {
        CopyDoorTilesToVram(gfx, frame);
        DrawCurrentDoorAnimFrame(gfx, x, y, gfx->palette);
        if (ShouldUseMultiCorridorDoor())
            DrawCurrentDoorAnimFrame(gfx, gSpecialVar_0x8004 + 7, gSpecialVar_0x8005 + 7, gfx->palette);
    }
}

enum
{
    TD_FRAMELIST = 0,
    TD_GFX = 2,
    TD_FRAME = 4,
    TD_COUNTER,
    TD_X,
    TD_Y
};

static bool32 sub_808A5F0(struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *taskData)
{
    if (taskData[TD_COUNTER] == 0)
        DrawDoor(gfx, &frames[taskData[TD_FRAME]], taskData[TD_X], taskData[TD_Y]);
    if (taskData[TD_COUNTER] == frames[taskData[TD_FRAME]].time)
    {
        taskData[TD_COUNTER] = 0;
        taskData[TD_FRAME]++;
        if (frames[taskData[TD_FRAME]].time == 0)
            return FALSE;
        else
            return TRUE;
    }
    taskData[TD_COUNTER]++;
    return TRUE;
}

static void Task_AnimateDoor(u8 taskId)
{
    u16 *taskData = gTasks[taskId].data;
    struct DoorAnimFrame *frames = (struct DoorAnimFrame *)(taskData[TD_FRAMELIST] << 16 | taskData[TD_FRAMELIST + 1]);
    struct DoorGraphics *gfx = (struct DoorGraphics *)(taskData[TD_GFX] << 16 | taskData[TD_GFX + 1]);

    if (sub_808A5F0(gfx, frames, taskData) == FALSE)
        DestroyTask(taskId);
}

static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}

static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum)
{
    while (gfx->tiles != NULL)
    {
        if (gfx->metatileNum == metatileNum)
            return gfx;
        gfx++;
    }
    return NULL;
}

static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y)
{
    if (FuncIsActiveTask(Task_AnimateDoor) == TRUE)
        return -1;
    else
    {
        u8 taskId = CreateTask(Task_AnimateDoor, 0x50);
        s16 *taskData = gTasks[taskId].data;

        taskData[TD_X] = x;
        taskData[TD_Y] = y;

        taskData[TD_FRAMELIST + 1] = (u32)frames;
        taskData[TD_FRAMELIST] = (u32)frames >> 16;

        taskData[TD_GFX + 1] = (u32)gfx;
        taskData[TD_GFX] = (u32)gfx >> 16;

        return taskId;
    }
}

static void DrawClosedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    DrawClosedDoorTiles(gfx, x, y);
}

static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx != NULL)
        DrawDoor(gfx, GetLastDoorFrame(sDoorOpenAnimFrames, sDoorOpenAnimFrames), x, y);
}

static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
    {
        return -1;
    }
    else
    {
        if (gfx->size == 2)
            return StartDoorAnimationTask(gfx, sBigDoorOpenAnimFrames, x, y);
        else
            return StartDoorAnimationTask(gfx, sDoorOpenAnimFrames, x, y);
    }
}

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return StartDoorAnimationTask(gfx, sDoorCloseAnimFrames, x, y);
}

static s8 GetDoorSoundType(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}

// Unused. Debug? Same as FieldAnimateDoorOpen but doesnt return or check if metatile is actually a door
static void Debug_FieldAnimateDoorOpen(u32 x, u32 y)
{
    StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorOpened(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawOpenedDoor(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorClosed(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawClosedDoor(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorClose(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorCloseAnimation(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}

u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = GetDoorSoundType(sDoorAnimGraphicsTable, x, y);
    
    if (sound == DOOR_SOUND_NORMAL)
        return SE_DOOR;
    else if (sound == DOOR_SOUND_SLIDING)
        return SE_JIDO_DOA;
    else if (sound == DOOR_SOUND_ARENA)
        return SE_TU_SAA;
    else
        return SE_DOOR;
}

// Opens the Battle Tower multi partner's door in sync with the player's door
static bool8 ShouldUseMultiCorridorDoor(void)
{
    if (FlagGet(FLAG_ENABLE_MULTI_CORRIDOR_DOOR))
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR) 
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR))
        {
            return TRUE;
        }
    }
    return FALSE;
}
