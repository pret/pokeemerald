#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

// Battle Scripting and BattleCommunication addresses
#define sPAINSPLIT_HP gBattleScripting
#define sBIDE_DMG gBattleScripting + 4
#define sMULTIHIT_STRING gBattleScripting + 8
#define sDMG_MULTIPLIER gBattleScripting + 0xE
#define sTWOTURN_STRINGID gBattleScripting + 0xF
#define sB_ANIM_ARG1 gBattleScripting + 0x10
#define sB_ANIM_ARG2 gBattleScripting + 0x11
#define sTRIPLE_KICK_POWER gBattleScripting + 0x12
#define sMOVEEND_STATE gBattleScripting + 0x14
#define sBATTLER_WITH_ABILITY gBattleScripting + 0x15
#define sMULTIHIT_EFFECT gBattleScripting + 0x16
#define sBATTLER gBattleScripting + 0x17
#define sB_ANIM_TURN gBattleScripting + 0x18
#define sB_ANIM_TARGETS_HIT gBattleScripting + 0x19
#define sSTATCHANGER gBattleScripting + 0x1A
#define sSTAT_ANIM_PLAYED gBattleScripting + 0x1B
#define sGIVEEXP_STATE gBattleScripting + 0x1C
#define sBATTLE_STYLE gBattleScripting + 0x1D
#define sLVLBOX_STATE gBattleScripting + 0x1E
#define sLEARNMOVE_STATE gBattleScripting + 0x1F
#define sFIELD_20 gBattleScripting + 0x20
#define sRESHOW_MAIN_STATE gBattleScripting + 0x21
#define sRESHOW_HELPER_STATE gBattleScripting + 0x22
#define sFIELD_23 gBattleScripting + 0x23
#define sWINDOWS_TYPE gBattleScripting + 0x24
#define sMULTIPLAYER_ID gBattleScripting + 0x25
#define sSPECIAL_TRAINER_BATTLE_TYPE gBattleScripting + 0x26

#define cEFFECT_CHOOSER gBattleCommunication + 3
#define cMULTISTRING_CHOOSER gBattleCommunication + 5
#define cMISS_TYPE gBattleCommunication + 6

// Battle Script defines for getting the wanted battler
#define BS_TARGET                   0
#define BS_ATTACKER                 1
#define BS_EFFECT_BATTLER           2
#define BS_FAINTED                  3
#define BS_ATTACKER_WITH_PARTNER    4 // for Cmd_updatestatusicon
#define BS_UNK_5                    5
#define BS_UNK_6                    6
#define BS_BATTLER_0                7
#define BS_ATTACKER_SIDE            8 // for Cmd_jumpifability
#define BS_NOT_ATTACKER_SIDE        9 // for Cmd_jumpifability
#define BS_SCRIPTING                10
#define BS_PLAYER1                  11
#define BS_OPPONENT1                12
#define BS_PLAYER2                  13
#define BS_OPPONENT2                14

// Cmd_accuracycheck
#define NO_ACC_CALC 0xFFFE
#define NO_ACC_CALC_CHECK_LOCK_ON 0xFFFF
#define ACC_CURR_MOVE 0

// compare operands
#define CMP_EQUAL               0
#define CMP_NOT_EQUAL           1
#define CMP_GREATER_THAN        2
#define CMP_LESS_THAN           3
#define CMP_COMMON_BITS         4
#define CMP_NO_COMMON_BITS      5

// Cmd_various
#define VARIOUS_CANCEL_MULTI_TURN_MOVES         0
#define VARIOUS_SET_MAGIC_COAT_TARGET           1
#define VARIOUS_IS_RUNNING_IMPOSSIBLE           2
#define VARIOUS_GET_MOVE_TARGET                 3
#define VARIOUS_GET_BATTLER_FAINTED             4
#define VARIOUS_RESET_INTIMIDATE_TRACE_BITS     5
#define VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP    6
#define VARIOUS_RESET_PLAYER_FAINTED            7
#define VARIOUS_PALACE_FLAVOR_TEXT              8
#define VARIOUS_ARENA_JUDGMENT_WINDOW           9
#define VARIOUS_ARENA_OPPONENT_MON_LOST         10
#define VARIOUS_ARENA_PLAYER_MON_LOST           11
#define VARIOUS_ARENA_BOTH_MONS_LOST            12
#define VARIOUS_EMIT_YESNOBOX                   13
#define VARIOUS_DRAW_ARENA_REF_TEXT_BOX         14
#define VARIOUS_ERASE_ARENA_REF_TEXT_BOX        15
#define VARIOUS_ARENA_JUDGMENT_STRING           16
#define VARIOUS_ARENA_WAIT_STRING               17
#define VARIOUS_WAIT_CRY                        18
#define VARIOUS_RETURN_OPPONENT_MON1            19
#define VARIOUS_RETURN_OPPONENT_MON2            20
#define VARIOUS_VOLUME_DOWN                     21
#define VARIOUS_VOLUME_UP                       22
#define VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT 23
#define VARIOUS_PALACE_TRY_ESCAPE_STATUS        24
#define VARIOUS_SET_TELEPORT_OUTCOME            25
#define VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC     26

// Cmd_manipulatedmg
#define DMG_CHANGE_SIGN            0
#define DMG_RECOIL_FROM_MISS       1
#define DMG_DOUBLED                2

// Cmd_jumpifcantswitch
#define SWITCH_IGNORE_ESCAPE_PREVENTION   (1 << 7)

// Cmd_statbuffchange
#define STAT_BUFF_ALLOW_PTR                 (1 << 0)   // If set, allow use of jumpptr. Set in every use of statbuffchange
#define STAT_BUFF_NOT_PROTECT_AFFECTED      (1 << 5)

// stat change flags for Cmd_playstatchangeanimation
#define STAT_CHANGE_NEGATIVE             (1 << 0)
#define STAT_CHANGE_BY_TWO               (1 << 1)
#define STAT_CHANGE_MULTIPLE_STATS       (1 << 2)
#define STAT_CHANGE_CANT_PREVENT         (1 << 3)

// stat flags for Cmd_playstatchangeanimation
#define BIT_HP                      (1 << 0)
#define BIT_ATK                     (1 << 1)
#define BIT_DEF                     (1 << 2)
#define BIT_SPEED                   (1 << 3)
#define BIT_SPATK                   (1 << 4)
#define BIT_SPDEF                   (1 << 5)
#define BIT_ACC                     (1 << 6)
#define BIT_EVASION                 (1 << 7)

#define PARTY_SCREEN_OPTIONAL (1 << 7) // Flag for first argument to openpartyscreen

// cases for Cmd_moveend
#define MOVEEND_RAGE                              0
#define MOVEEND_DEFROST                           1
#define MOVEEND_SYNCHRONIZE_TARGET                2
#define MOVEEND_ON_DAMAGE_ABILITIES               3
#define MOVEEND_IMMUNITY_ABILITIES                4
#define MOVEEND_SYNCHRONIZE_ATTACKER              5
#define MOVEEND_CHOICE_MOVE                       6
#define MOVEEND_CHANGED_ITEMS                     7
#define MOVEEND_ATTACKER_INVISIBLE                8
#define MOVEEND_ATTACKER_VISIBLE                  9
#define MOVEEND_TARGET_VISIBLE                    10
#define MOVEEND_ITEM_EFFECTS_ALL                  11
#define MOVEEND_KINGSROCK_SHELLBELL               12
#define MOVEEND_SUBSTITUTE                        13
#define MOVEEND_UPDATE_LAST_MOVES                 14
#define MOVEEND_MIRROR_MOVE                       15
#define MOVEEND_NEXT_TARGET                       16
#define MOVEEND_COUNT                             17

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
