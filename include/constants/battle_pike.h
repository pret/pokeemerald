#ifndef GUARD_CONSTANTS_BATTLE_PIKE_H
#define GUARD_CONSTANTS_BATTLE_PIKE_H

#define PIKE_ROOM_SINGLE_BATTLE 0
#define PIKE_ROOM_HEAL_FULL 1
#define PIKE_ROOM_NPC 2
#define PIKE_ROOM_STATUS 3
#define PIKE_ROOM_HEAL_PART 4
#define PIKE_ROOM_WILD_MONS 5
#define PIKE_ROOM_HARD_BATTLE 6
#define PIKE_ROOM_DOUBLE_BATTLE 7
#define PIKE_ROOM_BRAIN 8

// For the room with a status effect.
#define PIKE_STATUS_KIRLIA 0
#define PIKE_STATUS_DUSCLOPS 1

// Function IDs for sBattlePikeFunctions / CallBattlePikeFunction
#define BATTLE_PIKE_FUNC_SET_ROOM_TYPE                0
#define BATTLE_PIKE_FUNC_GET_DATA                     1
#define BATTLE_PIKE_FUNC_SET_DATA                     2
#define BATTLE_PIKE_FUNC_IN_FINAL_ROOM                3
#define BATTLE_PIKE_FUNC_SET_UP_ROOM_OBJECTS          4
#define BATTLE_PIKE_FUNC_GET_ROOM_TYPE                5
#define BATTLE_PIKE_FUNC_6                            6
#define BATTLE_PIKE_FUNC_7                            7
#define BATTLE_PIKE_FUNC_8                            8
#define BATTLE_PIKE_FUNC_NULL_9                       9
#define BATTLE_PIKE_FUNC_NULL_10                      10
#define BATTLE_PIKE_FUNC_GET_ROOM_STATUS              11
#define BATTLE_PIKE_FUNC_GET_ROOM_STATUS_MON          12
#define BATTLE_PIKE_FUNC_HEAL_ONE_TWO_MONS            13
#define BATTLE_PIKE_FUNC_BUFFER_NPC_MSG               14
#define BATTLE_PIKE_FUNC_STATUS_SCREEN_FADE           15
#define BATTLE_PIKE_FUNC_IS_IN                        16
#define BATTLE_PIKE_FUNC_SET_HINT_ROOM                17
#define BATTLE_PIKE_FUNC_SET_HINT_ROOM_ID             18
#define BATTLE_PIKE_FUNC_GET_ROOM_TYPE_HINT           19
#define BATTLE_PIKE_FUNC_CLEAR_TRAINER_IDS            20
#define BATTLE_PIKE_FUNC_BUFFER_RECORD_MIX_MSG        21
#define BATTLE_PIKE_FUNC_GET_QUEEN_FIGHT_TYPE         22
#define BATTLE_PIKE_FUNC_HEAL_MONS_BEFORE_QUEEN       23
#define BATTLE_PIKE_FUNC_SET_HEALING_ROOMS_DISABLED   24
#define BATTLE_PIKE_FUNC_CAN_PARTY_BE_HEALED          25
#define BATTLE_PIKE_FUNC_SAVE_MON_HELD_ITEMS          26
#define BATTLE_PIKE_FUNC_LOAD_MON_HELD_ITEMS          27
#define BATTLE_PIKE_FUNC_INIT_CHALLENGE               28

#endif // GUARD_CONSTANTS_BATTLE_PIKE_H
