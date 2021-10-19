#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

// Battle Scripting and BattleCommunication addresses
#define sPAINSPLIT_HP gBattleScripting
#define sBIDE_DMG gBattleScripting + 4
#define sMULTIHIT_STRING gBattleScripting + 8
#define sEXP_CATCH gBattleScripting + 0xE
#define sTWOTURN_STRINGID gBattleScripting + 0xF
#define sB_ANIM_ARG1 gBattleScripting + 0x10
#define sB_ANIM_ARG2 gBattleScripting + 0x11
#define sTRIPLE_KICK_POWER gBattleScripting + 0x12
#define sMOVEEND_STATE gBattleScripting + 0x14
#define sSAVED_STAT_CHANGER gBattleScripting + 0x15
#define sSHIFT_SWITCHED gBattleScripting + 0x16
#define sBATTLER gBattleScripting + 0x17
#define sB_ANIM_TURN gBattleScripting + 0x18
#define sB_ANIM_TARGETS_HIT gBattleScripting + 0x19
#define sSTATCHANGER gBattleScripting + 0x1A
#define sSTAT_ANIM_PLAYED gBattleScripting + 0x1B
#define sGIVEEXP_STATE gBattleScripting + 0x1C
#define sBATTLE_STYLE gBattleScripting + 0x1D
#define sLVLBOX_STATE gBattleScripting + 0x1E
#define sLEARNMOVE_STATE gBattleScripting + 0x1F
#define sSAVED_BATTLER gBattleScripting + 0x20
#define sRESHOW_MAIN_STATE gBattleScripting + 0x21
#define sRESHOW_HELPER_STATE gBattleScripting + 0x22
#define sFIELD_23 gBattleScripting + 0x23
#define sWINDOWS_TYPE gBattleScripting + 0x24
#define sMULTIPLAYER_ID gBattleScripting + 0x25
#define sSPECIAL_TRAINER_BATTLE_TYPE gBattleScripting + 0x26
#define sMON_CAUGHT gBattleScripting + 0x27
#define sSAVED_DMG gBattleScripting + 0x28
#define sSAVED_MOVE_EFFECT gBattleScripting + 0x2C
#define sMOVE_EFFECT gBattleScripting + 0x2E
#define sMULTIHIT_EFFECT gBattleScripting + 0x30
#define sILLUSION_NICK_HACK gBattleScripting + 0x32
#define sFIXED_ABILITY_POPUP gBattleScripting + 0x33
#define sABILITY_OVERWRITE gBattleScripting + 0x34
#define sSWITCH_CASE gBattleScripting + 0x36
#define sBERRY_OVERRIDE gBattleScripting + 0x37

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
#define BS_TARGET_SIDE              9 // for Cmd_jumpifability
#define BS_SCRIPTING                10
#define BS_PLAYER1                  11
#define BS_OPPONENT1                12
#define BS_PLAYER2                  13
#define BS_OPPONENT2                14
#define BS_ABILITY_BATTLER          15

// Cmd_accuracycheck
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
#define VARIOUS_PALACE_FLAVOR_TEXT              8
#define VARIOUS_ARENA_JUDGMENT_WINDOW           9
#define VARIOUS_ARENA_OPPONENT_MON_LOST         10
#define VARIOUS_ARENA_PLAYER_MON_LOST           11
#define VARIOUS_ARENA_BOTH_MONS_LOST            12
#define VARIOUS_EMIT_YESNOBOX                   13
#define VARIOUS_ARENA_JUDGMENT_STRING           16
#define VARIOUS_ARENA_WAIT_STRING               17
#define VARIOUS_WAIT_CRY                        18
#define VARIOUS_RETURN_OPPONENT_MON1            19
#define VARIOUS_RETURN_OPPONENT_MON2            20
#define VARIOUS_VOLUME_DOWN                     21
#define VARIOUS_VOLUME_UP                       22
#define VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT 23
#define VARIOUS_SET_TELEPORT_OUTCOME            25
#define VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC     26
#define VARIOUS_STAT_TEXT_BUFFER                27
#define VARIOUS_SWITCHIN_ABILITIES              28
#define VARIOUS_SAVE_TARGET                     29
#define VARIOUS_RESTORE_TARGET                  30
#define VARIOUS_INSTANT_HP_DROP                 31
#define VARIOUS_CLEAR_STATUS                    32
#define VARIOUS_RESTORE_PP                      33
#define VARIOUS_TRY_ACTIVATE_MOXIE              34
#define VARIOUS_TRY_ACTIVATE_FELL_STINGER       35
#define VARIOUS_PLAY_MOVE_ANIMATION             36
#define VARIOUS_SET_LUCKY_CHANT                 37
#define VARIOUS_SUCKER_PUNCH_CHECK              38
#define VARIOUS_SET_SIMPLE_BEAM                 39
#define VARIOUS_TRY_ENTRAINMENT                 40
#define VARIOUS_SET_LAST_USED_ABILITY           41
#define VARIOUS_TRY_HEAL_PULSE                  42
#define VARIOUS_TRY_QUASH                       43
#define VARIOUS_INVERT_STAT_STAGES              44
#define VARIOUS_SET_TERRAIN                     45
#define VARIOUS_TRY_ME_FIRST                    46
#define VARIOUS_JUMP_IF_BATTLE_END              47
#define VARIOUS_TRY_ELECTRIFY                   48
#define VARIOUS_TRY_REFLECT_TYPE                49
#define VARIOUS_TRY_SOAK                        50
#define VARIOUS_HANDLE_MEGA_EVO                 51
#define VARIOUS_TRY_LAST_RESORT                 52
#define VARIOUS_ARGUMENT_STATUS_EFFECT          53
#define VARIOUS_TRY_HIT_SWITCH_TARGET           54
#define VARIOUS_TRY_AUTOTOMIZE                  55
#define VARIOUS_TRY_COPYCAT                     56
#define VARIOUS_ABILITY_POPUP                   57
#define VARIOUS_DEFOG                           58
#define VARIOUS_JUMP_IF_TARGET_ALLY             59
#define VARIOUS_TRY_SYNCHRONOISE                60
#define VARIOUS_PSYCHO_SHIFT                    61
#define VARIOUS_CURE_STATUS                     62
#define VARIOUS_POWER_TRICK                     63
#define VARIOUS_AFTER_YOU                       64
#define VARIOUS_BESTOW                          65
#define VARIOUS_ARGUMENT_TO_MOVE_EFFECT         66
#define VARIOUS_JUMP_IF_NOT_GROUNDED            67
#define VARIOUS_HANDLE_TRAINER_SLIDE_MSG        68
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF 69
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON   70
#define VARIOUS_SET_AURORA_VEIL                 71
#define VARIOUS_TRY_THIRD_TYPE                  72
#define VARIOUS_ACUPRESSURE                     73
#define VARIOUS_SET_POWDER                      74
#define VARIOUS_SPECTRAL_THIEF                  75
#define VARIOUS_GRAVITY_ON_AIRBORNE_MONS        76
#define VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS   77
#define VARIOUS_JUMP_IF_ROAR_FAILS              78
#define VARIOUS_TRY_INSTRUCT                    79
#define VARIOUS_JUMP_IF_NOT_BERRY               80
#define VARIOUS_TRACE_ABILITY                   81
#define VARIOUS_UPDATE_NICK                     82
#define VARIOUS_TRY_ILLUSION_OFF                83
#define VARIOUS_SET_SPRITEIGNORE0HP             84
#define VARIOUS_HANDLE_FORM_CHANGE              85
#define VARIOUS_GET_STAT_VALUE                  86
#define VARIOUS_JUMP_IF_FULL_HP                 87
#define VARIOUS_LOSE_TYPE                       88
#define VARIOUS_TRY_ACTIVATE_SOULHEART          89
#define VARIOUS_TRY_ACTIVATE_RECEIVER           90
#define VARIOUS_TRY_ACTIVATE_BEAST_BOOST        91
#define VARIOUS_TRY_FRISK                       92
#define VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED  93
#define VARIOUS_TRY_FAIRY_LOCK                  94
#define VARIOUS_JUMP_IF_NO_ALLY                 95
#define VARIOUS_POISON_TYPE_IMMUNITY            96
#define VARIOUS_JUMP_IF_NO_HOLD_EFFECT          97
#define VARIOUS_INFATUATE_WITH_BATTLER          98
#define VARIOUS_SET_LAST_USED_ITEM              99
#define VARIOUS_PARALYZE_TYPE_IMMUNITY          100
#define VARIOUS_JUMP_IF_ABSENT                  101
#define VARIOUS_DESTROY_ABILITY_POPUP           102
#define VARIOUS_TOTEM_BOOST                     103
#define VARIOUS_TRY_ACTIVATE_GRIM_NEIGH         104
#define VARIOUS_MOVEEND_ITEM_EFFECTS            105
#define VARIOUS_TERRAIN_SEED                    106
#define VARIOUS_MAKE_INVISIBLE                  107
#define VARIOUS_ROOM_SERVICE                    108
#define VARIOUS_JUMP_IF_TERRAIN_AFFECTED        109
#define VARIOUS_EERIE_SPELL_PP_REDUCE           110
#define VARIOUS_JUMP_IF_TEAM_HEALTHY            111
#define VARIOUS_TRY_HEAL_QUARTER_HP             112
#define VARIOUS_REMOVE_TERRAIN                  113
#define VARIOUS_JUMP_IF_PRANKSTER_BLOCKED       114
#define VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER     115
#define VARIOUS_GET_ROTOTILLER_TARGETS          116
#define VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED 117
#define VARIOUS_TRY_ACTIVATE_BATTLE_BOND        118
#define VARIOUS_CONSUME_BERRY                   119
#define VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL   120
#define VARIOUS_HANDLE_PRIMAL_REVERSION         121

// Cmd_manipulatedamage
#define DMG_CHANGE_SIGN            0
#define DMG_RECOIL_FROM_MISS       1
#define DMG_DOUBLED                2
#define DMG_1_8_TARGET_HP          3
#define DMG_FULL_ATTACKER_HP       4
#define DMG_CURR_ATTACKER_HP       5
#define DMG_BIG_ROOT               6
#define DMG_1_2_ATTACKER_HP        7
#define DMG_RECOIL_FROM_IMMUNE     8 // Used to calculate recoil for the Gen 4 version of Jump Kick

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
#define MOVEEND_PROTECT_LIKE_EFFECT               0
#define MOVEEND_RAGE                              1
#define MOVEEND_DEFROST                           2
#define MOVEEND_SYNCHRONIZE_TARGET                3
#define MOVEEND_ABILITIES                         4
#define MOVEEND_ABILITIES_ATTACKER                5
#define MOVEEND_STATUS_IMMUNITY_ABILITIES         6
#define MOVEEND_SYNCHRONIZE_ATTACKER              7
#define MOVEEND_CHOICE_MOVE                       8
#define MOVEEND_CHANGED_ITEMS                     9
#define MOVEEND_ATTACKER_INVISIBLE                10
#define MOVEEND_ATTACKER_VISIBLE                  11
#define MOVEEND_TARGET_VISIBLE                    12
#define MOVEEND_ITEM_EFFECTS_TARGET               13
#define MOVEEND_MOVE_EFFECTS2                     14
#define MOVEEND_ITEM_EFFECTS_ALL                  15
#define MOVEEND_KINGSROCK                         16    // These item effects will occur each strike of a multi-hit move
#define MOVEEND_SUBSTITUTE                        17
#define MOVEEND_UPDATE_LAST_MOVES                 18
#define MOVEEND_MIRROR_MOVE                       19
#define MOVEEND_NEXT_TARGET                       20    // Everything up until here is handled for each strike of a multi-hit move
#define MOVEEND_EJECT_BUTTON                      21
#define MOVEEND_RED_CARD                          22
#define MOVEEND_EJECT_PACK                        23
#define MOVEEND_LIFEORB_SHELLBELL                 24    // Includes shell bell, throat spray, etc
#define MOVEEND_PICKPOCKET                        25
#define MOVEEND_DANCER                            26
#define MOVEEND_EMERGENCY_EXIT                    27
#define MOVEEND_CLEAR_BITS                        28
#define MOVEEND_COUNT                             29

// switch cases
#define B_SWITCH_NORMAL     0
#define B_SWITCH_HIT        1   // dragon tail, circle throw
#define B_SWITCH_RED_CARD   2

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
