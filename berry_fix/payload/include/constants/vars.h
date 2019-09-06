#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#define VAR_0x3F20                 0x3F20

#define VARS_START 0x4000

// temporary vars
// The first 0x10 vars are are temporary--they are cleared every time a map is loaded.
#define VAR_TEMP_0                 0x4000
#define VAR_TEMP_1                 0x4001
#define VAR_TEMP_2                 0x4002
#define VAR_TEMP_3                 0x4003
#define VAR_TEMP_4                 0x4004
#define VAR_TEMP_5                 0x4005
#define VAR_TEMP_6                 0x4006
#define VAR_TEMP_7                 0x4007
#define VAR_TEMP_8                 0x4008
#define VAR_TEMP_9                 0x4009
#define VAR_TEMP_A                 0x400A
#define VAR_TEMP_B                 0x400B
#define VAR_TEMP_C                 0x400C
#define VAR_TEMP_D                 0x400D
#define VAR_TEMP_E                 0x400E
#define VAR_TEMP_F                 0x400F

// object gfx id vars
// These 0x10 vars are used to dynamically control a event object's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetEventObjectGraphicsId().
#define VAR_OBJ_GFX_ID_0           0x4010
#define VAR_OBJ_GFX_ID_1           0x4011
#define VAR_OBJ_GFX_ID_2           0x4012
#define VAR_OBJ_GFX_ID_3           0x4013
#define VAR_OBJ_GFX_ID_4           0x4014
#define VAR_OBJ_GFX_ID_5           0x4015
#define VAR_OBJ_GFX_ID_6           0x4016
#define VAR_OBJ_GFX_ID_7           0x4017
#define VAR_OBJ_GFX_ID_8           0x4018
#define VAR_OBJ_GFX_ID_9           0x4019
#define VAR_OBJ_GFX_ID_A           0x401A
#define VAR_OBJ_GFX_ID_B           0x401B
#define VAR_OBJ_GFX_ID_C           0x401C
#define VAR_OBJ_GFX_ID_D           0x401D
#define VAR_OBJ_GFX_ID_E           0x401E
#define VAR_OBJ_GFX_ID_F           0x401F

// general purpose vars
#define VAR_RECYCLE_GOODS          0x4020
#define VAR_REPEL_STEP_COUNT       0x4021
#define VAR_ICE_STEP_COUNT         0x4022
#define VAR_STARTER_MON            0x4023 // 0=Treecko, 1=Torchic, 2=Mudkip
#define VAR_MIRAGE_RND_H           0x4024
#define VAR_MIRAGE_RND_L           0x4025
#define VAR_SECRET_BASE_MAP        0x4026
#define VAR_CYCLING_ROAD_RECORD_COLLISIONS 0x4027
#define VAR_CYCLING_ROAD_RECORD_TIME_L     0x4028
#define VAR_CYCLING_ROAD_RECORD_TIME_H     0x4029
#define VAR_HAPPINESS_STEP_COUNTER 0x402A
#define VAR_POISON_STEP_COUNTER    0x402B
#define VAR_RESET_RTC_ENABLE       0x402C
#define VAR_ENIGMA_BERRY_AVAILABLE 0x402D

#define VAR_DAYS                   0x4040
#define VAR_FANCLUB_UNKNOWN_1      0x4041 // TODO: document these two fanclub vars
#define VAR_FANCLUB_UNKNOWN_2      0x4042
#define VAR_DEPT_STORE_FLOOR       0x4043
#define VAR_TRICK_HOUSE_ROOMS_COMPLETED 0x4044
#define VAR_LOTTERY_PRIZE          0x4045
#define VAR_NATIONAL_DEX           0x4046
#define VAR_SHROOMISH_SIZE_RECORD  0x4047
#define VAR_ASH_GATHER_COUNT       0x4048
#define VAR_BIRCH_STATE            0x4049
#define VAR_CRUISE_STEP_COUNT      0x404A
#define VAR_LOTTERY_RND_L          0x404B
#define VAR_LOTTERY_RND_H          0x404C

#define VAR_BARBOACH_SIZE_RECORD   0x404F
#define VAR_LITTLEROOT_STATE       0x4050
#define VAR_ROUTE102_ACCESSIBLE    0x4051

#define VAR_LAVARIDGE_RIVAL_STATE  0x4053
#define VAR_CURRENT_SECRET_BASE    0x4054

#define VAR_PETALBURG_STATE        0x4057
#define VAR_SLATEPORT_STATE        0x4058

#define VAR_RUSTBORO_STATE         0x405A

#define VAR_SOOTOPOLIS_STATE       0x405E

#define VAR_ROUTE101_STATE         0x4060

#define VAR_ROUTE103_STATE         0x4062

#define VAR_ROUTE110_STATE         0x4069

#define VAR_ROUTE116_STATE         0x406F

#define VAR_ROUTE118_STATE         0x4071
#define VAR_ROUTE119_STATE         0x4072

#define VAR_ROUTE121_STATE         0x4074
#define VAR_ROUTE128_STATE         0x407B

#define VAR_LITTLEROOT_HOUSES_STATE 0x4082 // TODO: needs more investigation

#define VAR_BIRCH_LAB_STATE         0x4084
#define VAR_PETALBURG_GYM_STATE     0x4085
#define VAR_LINK_CONTEST_ROOM_STATE 0x4086
#define VAR_CABLE_CLUB_STATE        0x4087
#define VAR_CONTEST_LOCATION        0x4088
#define VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F                  0x4089 // TODO: related to decorations
#define VAR_CONTEST_PRIZE_PICKUP    0x408A

#define VAR_LITTLEROOT_HOUSES_STATE_2 0x408C // TODO: needs more investigation
#define VAR_LITTLEROOT_RIVAL_STATE    0x408D
#define VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE 0x408E
#define VAR_DEVON_CORP_3F_STATE       0x408F
#define VAR_BRINEY_HOUSE_STATE        0x4090

#define VAR_LITTLEROOT_INTRO_STATE   0x4092
#define VAR_MAUVILLE_GYM_STATE       0x4093
#define VAR_LILYCOVE_MUSEUM_2F_STATE 0x4094
#define VAR_LILYCOVE_FAN_CLUB_STATE  0x4095
#define VAR_BRINEY_LOCATION          0x4096
#define VAR_0x4097                   0x4097 // TODO: related to creating new secret base
#define VAR_PETALBURG_WOODS_STATE    0x4098
#define VAR_LILYCOVE_CONTEST_LOBBY_STATE 0x4099
#define VAR_RUSTURF_TUNNEL_STATE     0x409a
#define VAR_CAVE_OF_ORIGIN_B4F_STATE 0x409B
#define VAR_ELITE_4_STATE            0x409C

#define VAR_SLATEPORT_HARBOR_STATE   0x40A0

#define VAR_SEAFLOOR_CAVERN_STATE         0x40A2
#define VAR_CABLE_CAR_STATION_STATE       0x40A3
#define VAR_SAFARI_ZONE_STATE             0x40A4
#define VAR_TRICK_HOUSE_ENTRANCE_STATE    0x40A5
#define VAR_TRICK_HOUSE_ENTRANCE_STATE_2  0x40A6
#define VAR_TRICK_HOUSE_ENTRANCE_STATE_3  0x40A7

#define VAR_CYCLING_CHALLENGE_STATE       0x40A9
#define VAR_SLATEPORT_MUSEUM_1F_STATE     0x40AA
#define VAR_TRICK_HOUSE_PUZZLE_1_STATE    0x40AB
#define VAR_TRICK_HOUSE_PUZZLE_2_STATE    0x40AC
#define VAR_TRICK_HOUSE_PUZZLE_3_STATE    0x40AD
#define VAR_TRICK_HOUSE_PUZZLE_4_STATE    0x40AE
#define VAR_TRICK_HOUSE_PUZZLE_5_STATE    0x40AF
#define VAR_TRICK_HOUSE_PUZZLE_6_STATE    0x40B0
#define VAR_TRICK_HOUSE_PUZZLE_7_STATE    0x40B1
#define VAR_TRICK_HOUSE_PUZZLE_8_STATE    0x40B2
#define VAR_WEATHER_INSTITUTE_STATE       0x40B3
#define VAR_PORTHOLE_STATE                0x40B4
#define VAR_TRICK_HOUSE_STATE             0x40B5 // TODO: needs some further investigation
#define VAR_TRICK_HOUSE_PUZZLE_7_STATE_2  0x40B6
#define VAR_SLATEPORT_FAN_CLUB_STATE      0x40B7

#define VAR_MT_PYRE_STATE                 0x40B9
#define VAR_NEW_MAUVILLE_STATE            0x40BA

#define VAR_BRAVO_TRAINER_BATTLE_TOWER_ON    0x40BC
#define VAR_JAGGED_PASS_VOLCANIC_ASH_WEATHER 0x40BD
#define VAR_GLASS_WORKSHOP_STATE             0x40BE
#define VAR_METEOR_FALLS_STATE               0x40BF
#define VAR_GAME_CORNER_STATE                0x40C0
#define VAR_TRICK_HOUSE_PRIZE_PICKUP         0x40C1
#define VAR_PACIFIDLOG_TM_RECEIVED_DAY       0x40C2
#define VAR_VICTORY_ROAD_1F_STATE            0x40C3
#define VAR_FOSSIL_RESURRECTION_STATE        0x40C4
#define VAR_WHICH_FOSSIL_REVIVED             0x40C5
#define VAR_STEVENS_HOUSE_STATE              0x40C6
#define VAR_OLDALE_STATE                     0x40C7

// special vars
// They are commonly used as parameters to commands, or return values from commands.
#define VAR_SPECIAL_0     0x8000
#define VAR_SPECIAL_1     0x8001
#define VAR_SPECIAL_2     0x8002
#define VAR_SPECIAL_3     0x8003
#define VAR_SPECIAL_4     0x8004
#define VAR_SPECIAL_5     0x8005
#define VAR_SPECIAL_6     0x8006
#define VAR_SPECIAL_7     0x8007
#define VAR_SPECIAL_8     0x8008
#define VAR_SPECIAL_9     0x8009
#define VAR_SPECIAL_A     0x800A
#define VAR_SPECIAL_B     0x800B
#define FACING           0x800C
#define RESULT           0x800D
#define ITEM_ID          0x800E
#define LAST_TALKED      0x800F
#define CONTEST_RANK     0x8010
#define CONTEST_CATEGORY 0x8011

#endif // GUARD_CONSTANTS_VARS_H
