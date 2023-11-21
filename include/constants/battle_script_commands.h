#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

// The following correspond to the struct members of BattleScripting by adding their offset
#define sPAINSPLIT_HP                (gBattleScripting + 0x00) // painSplitHp
#define sBIDE_DMG                    (gBattleScripting + 0x04) // bideDmg
#define sMULTIHIT_STRING             (gBattleScripting + 0x08) // multihitString
#define sEXP_CATCH                   (gBattleScripting + 0x0E) // expOnCatch
#define sTWOTURN_STRINGID            (gBattleScripting + 0x0F) // twoTurnsMoveStringId
#define sB_ANIM_ARG1                 (gBattleScripting + 0x10) // animArg1
#define sB_ANIM_ARG2                 (gBattleScripting + 0x11) // animArg2
#define sTRIPLE_KICK_POWER           (gBattleScripting + 0x12) // tripleKickPower
#define sMOVEEND_STATE               (gBattleScripting + 0x14) // moveendState
#define sSAVED_STAT_CHANGER          (gBattleScripting + 0x15) // savedStatChanger
#define sSHIFT_SWITCHED              (gBattleScripting + 0x16) // shiftSwitched
#define sBATTLER                     (gBattleScripting + 0x17) // battler
#define sB_ANIM_TURN                 (gBattleScripting + 0x18) // animTurn
#define sB_ANIM_TARGETS_HIT          (gBattleScripting + 0x19) // animTargetsHit
#define sSTATCHANGER                 (gBattleScripting + 0x1A) // statChanger
#define sSTAT_ANIM_PLAYED            (gBattleScripting + 0x1B) // statAnimPlayed
#define sGIVEEXP_STATE               (gBattleScripting + 0x1C) // getexpState
#define sBATTLE_STYLE                (gBattleScripting + 0x1D) // battleStyle
#define sLVLBOX_STATE                (gBattleScripting + 0x1E) // drawlvlupboxState
#define sLEARNMOVE_STATE             (gBattleScripting + 0x1F) // learnMoveState
#define sSAVED_BATTLER               (gBattleScripting + 0x20) // savedBattler
#define sRESHOW_MAIN_STATE           (gBattleScripting + 0x21) // reshowMainState
#define sRESHOW_HELPER_STATE         (gBattleScripting + 0x22) // reshowHelperState
#define sLVLUP_HP                    (gBattleScripting + 0x23) // levelUpHP
#define sWINDOWS_TYPE                (gBattleScripting + 0x24) // windowsType
#define sMULTIPLAYER_ID              (gBattleScripting + 0x25) // multiplayerId
#define sSPECIAL_TRAINER_BATTLE_TYPE (gBattleScripting + 0x26) // specialTrainerBattleType
#define sMON_CAUGHT                  (gBattleScripting + 0x27) // monCaught
#define sSAVED_DMG                   (gBattleScripting + 0x28) // savedDmg
#define sSAVED_MOVE_EFFECT           (gBattleScripting + 0x2C) // savedMoveEffect
#define sMOVE_EFFECT                 (gBattleScripting + 0x2E) // moveEffect
#define sMULTIHIT_EFFECT             (gBattleScripting + 0x30) // multihitMoveEffect
#define sILLUSION_NICK_HACK          (gBattleScripting + 0x32) // illusionNickHack
#define sFIXED_ABILITY_POPUP         (gBattleScripting + 0x33) // fixedPopup
#define sABILITY_OVERWRITE           (gBattleScripting + 0x34) // abilityPopupOverwrite
#define sSWITCH_CASE                 (gBattleScripting + 0x36) // switchCase
#define sBERRY_OVERRIDE              (gBattleScripting + 0x37) // overrideBerryRequirements
#define sSTICKY_WEB_STAT_DROP        (gBattleScripting + 0x38) // stickyWebStatDrop

// Array entries for battle communication
#define MULTIUSE_STATE          0
#define CURSOR_POSITION         1
#define TASK_ID                 1 // task Id and cursor position share the same field
#define SPRITES_INIT_STATE1     1 // shares the Id as well
#define SPRITES_INIT_STATE2     2
#define MOVE_EFFECT_BYTE        3
#define ACTIONS_CONFIRMED_COUNT 4
#define MULTISTRING_CHOOSER     5
#define MISS_TYPE               6
#define MSG_DISPLAY             7
#define BATTLE_COMMUNICATION_ENTRIES_COUNT  8

#define cMULTISTRING_CHOOSER (gBattleCommunication + MULTISTRING_CHOOSER)
#define cMISS_TYPE           (gBattleCommunication + MISS_TYPE)

// Battle Script defines for getting the wanted battler
#define BS_TARGET                   0
#define BS_ATTACKER                 1
#define BS_EFFECT_BATTLER           2
#define BS_FAINTED                  3
#define BS_ATTACKER_WITH_PARTNER    4 // for Cmd_updatestatusicon
#define BS_FAINTED_LINK_MULTIPLE_1  5 // for openpartyscreen
#define BS_FAINTED_LINK_MULTIPLE_2  6 // for openpartyscreen
#define BS_BATTLER_0                7
#define BS_ATTACKER_SIDE            8 // for Cmd_jumpifability
#define BS_TARGET_SIDE              9 // for Cmd_jumpifability
#define BS_SCRIPTING                10
#define BS_PLAYER1                  11
#define BS_OPPONENT1                12
#define BS_PLAYER2                  13 // for Cmd_updatestatusicon
#define BS_OPPONENT2                14
#define BS_ABILITY_BATTLER          15
#define BS_ATTACKER_PARTNER         16

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
#define VARIOUS_CANCEL_MULTI_TURN_MOVES              0
#define VARIOUS_SET_MAGIC_COAT_TARGET                1
#define VARIOUS_IS_RUNNING_IMPOSSIBLE                2
#define VARIOUS_GET_MOVE_TARGET                      3
#define VARIOUS_GET_BATTLER_FAINTED                  4
#define VARIOUS_RESET_SWITCH_IN_ABILITY_BITS         5
#define VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP         6
#define VARIOUS_RESET_PLAYER_FAINTED                 7
#define VARIOUS_PALACE_FLAVOR_TEXT                   8
#define VARIOUS_ARENA_JUDGMENT_WINDOW                9
#define VARIOUS_ARENA_OPPONENT_MON_LOST              10
#define VARIOUS_ARENA_PLAYER_MON_LOST                11
#define VARIOUS_ARENA_BOTH_MONS_LOST                 12
#define VARIOUS_EMIT_YESNOBOX                        13
#define VARIOUS_DRAW_ARENA_REF_TEXT_BOX              14
#define VARIOUS_ERASE_ARENA_REF_TEXT_BOX             15
#define VARIOUS_ARENA_JUDGMENT_STRING                16
#define VARIOUS_ARENA_WAIT_STRING                    17
#define VARIOUS_WAIT_CRY                             18
#define VARIOUS_RETURN_OPPONENT_MON1                 19
#define VARIOUS_RETURN_OPPONENT_MON2                 20
#define VARIOUS_VOLUME_DOWN                          21
#define VARIOUS_VOLUME_UP                            22
#define VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT      23
#define VARIOUS_PALACE_TRY_ESCAPE_STATUS             24
#define VARIOUS_SET_TELEPORT_OUTCOME                 25
#define VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC          26
#define VARIOUS_STAT_TEXT_BUFFER                     27
#define VARIOUS_SWITCHIN_ABILITIES                   28
#define VARIOUS_SAVE_TARGET                          29
#define VARIOUS_RESTORE_TARGET                       30
#define VARIOUS_INSTANT_HP_DROP                      31
#define VARIOUS_CLEAR_STATUS                         32
#define VARIOUS_RESTORE_PP                           33
#define VARIOUS_TRY_ACTIVATE_MOXIE                   34
#define VARIOUS_TRY_ACTIVATE_FELL_STINGER            35
#define VARIOUS_PLAY_MOVE_ANIMATION                  36
#define VARIOUS_SET_LUCKY_CHANT                      37
#define VARIOUS_SUCKER_PUNCH_CHECK                   38
#define VARIOUS_SET_SIMPLE_BEAM                      39
#define VARIOUS_TRY_ENTRAINMENT                      40
#define VARIOUS_SET_LAST_USED_ABILITY                41
#define VARIOUS_TRY_HEAL_PULSE                       42
#define VARIOUS_TRY_QUASH                            43
#define VARIOUS_INVERT_STAT_STAGES                   44
#define VARIOUS_TRY_ME_FIRST                         45
#define VARIOUS_JUMP_IF_BATTLE_END                   46
#define VARIOUS_TRY_ELECTRIFY                        47
#define VARIOUS_TRY_REFLECT_TYPE                     48
#define VARIOUS_TRY_SOAK                             49
#define VARIOUS_HANDLE_MEGA_EVO                      50
#define VARIOUS_TRY_LAST_RESORT                      51
#define VARIOUS_ARGUMENT_STATUS_EFFECT               52
#define VARIOUS_TRY_HIT_SWITCH_TARGET                53
#define VARIOUS_TRY_AUTOTOMIZE                       54
#define VARIOUS_TRY_COPYCAT                          55
#define VARIOUS_ABILITY_POPUP                        56
#define VARIOUS_DEFOG                                57
#define VARIOUS_JUMP_IF_TARGET_ALLY                  58
#define VARIOUS_TRY_SYNCHRONOISE                     59
#define VARIOUS_PSYCHO_SHIFT                         60
#define VARIOUS_CURE_STATUS                          61
#define VARIOUS_POWER_TRICK                          62
#define VARIOUS_AFTER_YOU                            63
#define VARIOUS_BESTOW                               64
#define VARIOUS_ARGUMENT_TO_MOVE_EFFECT              65
#define VARIOUS_JUMP_IF_NOT_GROUNDED                 66
#define VARIOUS_HANDLE_TRAINER_SLIDE_MSG             67
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF      68
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON        69
#define VARIOUS_SET_AURORA_VEIL                      70
#define VARIOUS_TRY_THIRD_TYPE                       71
#define VARIOUS_ACUPRESSURE                          72
#define VARIOUS_SET_POWDER                           73
#define VARIOUS_SPECTRAL_THIEF                       74
#define VARIOUS_GRAVITY_ON_AIRBORNE_MONS             75
#define VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS        76
#define VARIOUS_JUMP_IF_ROAR_FAILS                   77
#define VARIOUS_TRY_INSTRUCT                         78
#define VARIOUS_JUMP_IF_NOT_BERRY                    79
#define VARIOUS_TRACE_ABILITY                        80
#define VARIOUS_UPDATE_NICK                          81
#define VARIOUS_TRY_ILLUSION_OFF                     82
#define VARIOUS_SET_SPRITEIGNORE0HP                  83
#define VARIOUS_HANDLE_FORM_CHANGE                   84
#define VARIOUS_GET_STAT_VALUE                       85
#define VARIOUS_JUMP_IF_FULL_HP                      86
#define VARIOUS_LOSE_TYPE                            87
#define VARIOUS_TRY_ACTIVATE_SOULHEART               88
#define VARIOUS_TRY_ACTIVATE_RECEIVER                89
#define VARIOUS_TRY_ACTIVATE_BEAST_BOOST             90
#define VARIOUS_TRY_FRISK                            91
#define VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED       92
#define VARIOUS_TRY_FAIRY_LOCK                       93
#define VARIOUS_JUMP_IF_NO_ALLY                      94
#define VARIOUS_POISON_TYPE_IMMUNITY                 95
#define VARIOUS_JUMP_IF_NO_HOLD_EFFECT               96
#define VARIOUS_INFATUATE_WITH_BATTLER               97
#define VARIOUS_SET_LAST_USED_ITEM                   98
#define VARIOUS_PARALYZE_TYPE_IMMUNITY               99
#define VARIOUS_JUMP_IF_ABSENT                       100
#define VARIOUS_DESTROY_ABILITY_POPUP                101
#define VARIOUS_TOTEM_BOOST                          102
#define VARIOUS_TRY_ACTIVATE_GRIM_NEIGH              103
#define VARIOUS_MOVEEND_ITEM_EFFECTS                 104
#define VARIOUS_TERRAIN_SEED                         105
#define VARIOUS_MAKE_INVISIBLE                       106
#define VARIOUS_ROOM_SERVICE                         107

#define VARIOUS_EERIE_SPELL_PP_REDUCE                108
#define VARIOUS_JUMP_IF_TEAM_HEALTHY                 109
#define VARIOUS_TRY_HEAL_QUARTER_HP                  110
#define VARIOUS_REMOVE_TERRAIN                       111
#define VARIOUS_JUMP_IF_PRANKSTER_BLOCKED            112
#define VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER          113
#define VARIOUS_GET_ROTOTILLER_TARGETS               114
#define VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED      115
#define VARIOUS_TRY_ACTIVATE_BATTLE_BOND             116
#define VARIOUS_CONSUME_BERRY                        117
#define VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL        118
#define VARIOUS_JUMP_IF_SPECIES                      119
#define VARIOUS_UPDATE_ABILITY_POPUP                 120
#define VARIOUS_JUMP_IF_WEATHER_AFFECTED             121
#define VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED         122
#define VARIOUS_SET_ATTACKER_STICKY_WEB_USER         123
#define VARIOUS_PHOTON_GEYSER_CHECK                  124
#define VARIOUS_SHELL_SIDE_ARM_CHECK                 125
#define VARIOUS_TRY_NO_RETREAT                       126
#define VARIOUS_TRY_TAR_SHOT                         127
#define VARIOUS_CAN_TAR_SHOT_WORK                    128
#define VARIOUS_CHECK_POLTERGEIST                    129
#define VARIOUS_CUT_1_3_HP_RAISE_STATS               130
#define VARIOUS_TRY_END_NEUTRALIZING_GAS             131
#define VARIOUS_JUMP_IF_UNDER_200                    132
#define VARIOUS_SET_SKY_DROP                         133
#define VARIOUS_CLEAR_SKY_DROP                       134
#define VARIOUS_SKY_DROP_YAWN                        135
#define VARIOUS_JUMP_IF_HOLD_EFFECT                  136
#define VARIOUS_CURE_CERTAIN_STATUSES                137
#define VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES       138
#define VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY         139
#define VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT   140
#define VARIOUS_SAVE_BATTLER_ITEM                    141
#define VARIOUS_RESTORE_BATTLER_ITEM                 142
#define VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM       143
#define VARIOUS_SET_BEAK_BLAST                       144
#define VARIOUS_SWAP_SIDE_STATUSES                   145
#define VARIOUS_SWAP_STATS                           146
#define VARIOUS_TEATIME_INVUL                        147
#define VARIOUS_TEATIME_TARGETS                      148
#define VARIOUS_TRY_WIND_RIDER_POWER                 149
#define VARIOUS_ACTIVATE_WEATHER_CHANGE_ABILITIES    150
#define VARIOUS_ACTIVATE_TERRAIN_CHANGE_ABILITIES    151
#define VARIOUS_STORE_HEALING_WISH                   152
#define VARIOUS_HIT_SWITCH_TARGET_FAILED             153
#define VARIOUS_TRY_REVIVAL_BLESSING                 154
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_Z_MOVE         155
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_MEGA_EVOLUTION 156

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
#define STAT_CHANGE_ALLOW_PTR               (1 << 0)   // If set, allow use of jumpptr. Set in every use of statbuffchange
#define STAT_CHANGE_MIRROR_ARMOR            (1 << 1)   // Stat change redirection caused by Mirror Armor ability.
#define STAT_CHANGE_NOT_PROTECT_AFFECTED    (1 << 5)
#define STAT_CHANGE_UPDATE_MOVE_EFFECT      (1 << 6)

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
#define MOVEEND_SUM_DAMAGE                        0
#define MOVEEND_PROTECT_LIKE_EFFECT               1
#define MOVEEND_RAGE                              2
#define MOVEEND_SYNCHRONIZE_TARGET                3
#define MOVEEND_ABILITIES                         4
#define MOVEEND_ABILITIES_ATTACKER                5
#define MOVEEND_STATUS_IMMUNITY_ABILITIES         6
#define MOVEEND_SYNCHRONIZE_ATTACKER              7
#define MOVEEND_CHOICE_MOVE                       8
#define MOVEEND_ATTACKER_INVISIBLE                9
#define MOVEEND_ATTACKER_VISIBLE                  10
#define MOVEEND_TARGET_VISIBLE                    11
#define MOVEEND_ITEM_EFFECTS_TARGET               12
#define MOVEEND_MOVE_EFFECTS2                     13
#define MOVEEND_ITEM_EFFECTS_ALL                  14
#define MOVEEND_KINGSROCK                         15    // These item effects will occur each strike of a multi-hit move
#define MOVEEND_SUBSTITUTE                        16
#define MOVEEND_SKY_DROP_CONFUSE                  17
#define MOVEEND_UPDATE_LAST_MOVES                 18
#define MOVEEND_MIRROR_MOVE                       19
#define MOVEEND_NEXT_TARGET                       20   // Everything up until here is handled for each strike of a multi-hit move
#define MOVEEND_MULTIHIT_MOVE                     21
#define MOVEEND_DEFROST                           22
#define MOVEEND_RECOIL                            23
#define MOVEEND_MAGICIAN                          24    // Occurs after final multi-hit strike, and after other items/abilities would activate
#define MOVEEND_EJECT_BUTTON                      25
#define MOVEEND_RED_CARD                          26
#define MOVEEND_EJECT_PACK                        27
#define MOVEEND_LIFEORB_SHELLBELL                 28    // Includes shell bell, throat spray, etc
#define MOVEEND_CHANGED_ITEMS                     29
#define MOVEEND_PICKPOCKET                        30
#define MOVEEND_DANCER                            31
#define MOVEEND_EMERGENCY_EXIT                    32
#define MOVEEND_SYMBIOSIS                         33
#define MOVEEND_OPPORTUNIST                       34    // Occurs after other stat change items/abilities to try and copy the boosts
#define MOVEEND_CLEAR_BITS                        35
#define MOVEEND_COUNT                             36

// switch cases
#define B_SWITCH_NORMAL     0
#define B_SWITCH_HIT        1   // dragon tail, circle throw
#define B_SWITCH_RED_CARD   2

// Argument labels for EFFECT_HIT_SET_REMOVE_TERRAIN
#define ARG_SET_PSYCHIC_TERRAIN        0
#define ARG_TRY_REMOVE_TERRAIN_HIT     1
#define ARG_TRY_REMOVE_TERRAIN_FAIL    2

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
