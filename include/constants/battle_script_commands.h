#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

// The following correspond to the struct members of BattleScripting by adding their offset
#define sPAINSPLIT_HP                (gBattleScripting + 0x00) // painSplitHp
#define sBIDE_DMG                    (gBattleScripting + 0x04) // bideDmg
#define sMULTIHIT_STRING             (gBattleScripting + 0x08) // multihitString
#define sEXP_CATCH                   (gBattleScripting + 0x0E) // expOnCatch
#define sUNUSED                      (gBattleScripting + 0x0F) // unused
#define sB_ANIM_ARG1                 (gBattleScripting + 0x10) // animArg1
#define sB_ANIM_ARG2                 (gBattleScripting + 0x11) // animArg2
#define sSAVED_STRINID               (gBattleScripting + 0x12) // savedStringId
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
#define BS_FAINTED_MULTIPLE_1       5 // for openpartyscreen
#define BS_FAINTED_MULTIPLE_2       6 // for openpartyscreen
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
#define VARIOUS_INSTANT_HP_DROP                      29
#define VARIOUS_CLEAR_STATUS                         30
#define VARIOUS_RESTORE_PP                           31
#define VARIOUS_TRY_ACTIVATE_MOXIE                   32
#define VARIOUS_TRY_ACTIVATE_FELL_STINGER            33
#define VARIOUS_PLAY_MOVE_ANIMATION                  34
#define VARIOUS_SET_LUCKY_CHANT                      35
#define VARIOUS_SUCKER_PUNCH_CHECK                   36
#define VARIOUS_SET_SIMPLE_BEAM                      37
#define VARIOUS_TRY_ENTRAINMENT                      38
#define VARIOUS_SET_LAST_USED_ABILITY                39
#define VARIOUS_INVERT_STAT_STAGES                   40
#define VARIOUS_TRY_ME_FIRST                         41
#define VARIOUS_JUMP_IF_BATTLE_END                   42
#define VARIOUS_TRY_ELECTRIFY                        43
#define VARIOUS_TRY_REFLECT_TYPE                     44
#define VARIOUS_TRY_SOAK                             45
#define VARIOUS_HANDLE_MEGA_EVO                      46
#define VARIOUS_TRY_LAST_RESORT                      47
#define VARIOUS_SET_ARG_TO_BATTLE_DAMAGE             48
#define VARIOUS_TRY_HIT_SWITCH_TARGET                49
#define VARIOUS_TRY_AUTOTOMIZE                       50
#define VARIOUS_ABILITY_POPUP                        51
#define VARIOUS_JUMP_IF_TARGET_ALLY                  52
#define VARIOUS_TRY_SYNCHRONOISE                     53
#define VARIOUS_PSYCHO_SHIFT                         54
#define VARIOUS_CURE_STATUS                          55
#define VARIOUS_POWER_TRICK                          56
#define VARIOUS_AFTER_YOU                            57
#define VARIOUS_BESTOW                               58
#define VARIOUS_JUMP_IF_NOT_GROUNDED                 59
#define VARIOUS_HANDLE_TRAINER_SLIDE_MSG             60
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF      61
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON        62
#define VARIOUS_SET_AURORA_VEIL                      63
#define VARIOUS_TRY_THIRD_TYPE                       64
#define VARIOUS_ACUPRESSURE                          65
#define VARIOUS_SET_POWDER                           66
#define VARIOUS_SPECTRAL_THIEF                       67
#define VARIOUS_GRAVITY_ON_AIRBORNE_MONS             68
#define VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS        69
#define VARIOUS_JUMP_IF_ROAR_FAILS                   70
#define VARIOUS_TRY_INSTRUCT                         71
#define VARIOUS_JUMP_IF_NOT_BERRY                    72
#define VARIOUS_TRACE_ABILITY                        73
#define VARIOUS_UPDATE_NICK                          74
#define VARIOUS_TRY_ILLUSION_OFF                     75
#define VARIOUS_SET_SPRITEIGNORE0HP                  76
#define VARIOUS_HANDLE_FORM_CHANGE                   77
#define VARIOUS_GET_STAT_VALUE                       78
#define VARIOUS_JUMP_IF_FULL_HP                      79
#define VARIOUS_LOSE_TYPE                            80
#define VARIOUS_TRY_ACTIVATE_SOULHEART               81
#define VARIOUS_TRY_ACTIVATE_RECEIVER                82
#define VARIOUS_TRY_ACTIVATE_BEAST_BOOST             83
#define VARIOUS_TRY_FRISK                            84
#define VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED       85
#define VARIOUS_TRY_FAIRY_LOCK                       86
#define VARIOUS_JUMP_IF_NO_ALLY                      87
#define VARIOUS_POISON_TYPE_IMMUNITY                 88
#define VARIOUS_JUMP_IF_HOLD_EFFECT                  89
#define VARIOUS_INFATUATE_WITH_BATTLER               90
#define VARIOUS_SET_LAST_USED_ITEM                   91
#define VARIOUS_PARALYZE_TYPE_IMMUNITY               92
#define VARIOUS_JUMP_IF_ABSENT                       93
#define VARIOUS_DESTROY_ABILITY_POPUP                94
#define VARIOUS_TOTEM_BOOST                          95
#define VARIOUS_TRY_ACTIVATE_GRIM_NEIGH              96
#define VARIOUS_MOVEEND_ITEM_EFFECTS                 97
#define VARIOUS_TERRAIN_SEED                         98
#define VARIOUS_MAKE_INVISIBLE                       99
#define VARIOUS_ROOM_SERVICE                         100
#define VARIOUS_EERIE_SPELL_PP_REDUCE                101
#define VARIOUS_JUMP_IF_TEAM_HEALTHY                 102
#define VARIOUS_TRY_HEAL_QUARTER_HP                  103
#define VARIOUS_REMOVE_TERRAIN                       104
#define VARIOUS_JUMP_IF_PRANKSTER_BLOCKED            105
#define VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER          106
#define VARIOUS_GET_ROTOTILLER_TARGETS               107
#define VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED      108
#define VARIOUS_TRY_ACTIVATE_BATTLE_BOND             109
#define VARIOUS_CONSUME_BERRY                        110
#define VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL        111
#define VARIOUS_JUMP_IF_SPECIES                      112
#define VARIOUS_UPDATE_ABILITY_POPUP                 113
#define VARIOUS_JUMP_IF_WEATHER_AFFECTED             114
#define VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED         115
#define VARIOUS_SET_ATTACKER_STICKY_WEB_USER         116
#define VARIOUS_TRY_NO_RETREAT                       117
#define VARIOUS_TRY_TAR_SHOT                         118
#define VARIOUS_CAN_TAR_SHOT_WORK                    119
#define VARIOUS_CHECK_POLTERGEIST                    120
#define VARIOUS_CUT_1_3_HP_RAISE_STATS               121
#define VARIOUS_TRY_END_NEUTRALIZING_GAS             122
#define VARIOUS_JUMP_IF_UNDER_200                    123
#define VARIOUS_SET_SKY_DROP                         124
#define VARIOUS_CLEAR_SKY_DROP                       125
#define VARIOUS_SKY_DROP_YAWN                        126
#define VARIOUS_CURE_CERTAIN_STATUSES                127
#define VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES       128
#define VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY         129
#define VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT   130
#define VARIOUS_SAVE_BATTLER_ITEM                    131
#define VARIOUS_RESTORE_BATTLER_ITEM                 132
#define VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM       133
#define VARIOUS_SET_BEAK_BLAST                       134
#define VARIOUS_SWAP_SIDE_STATUSES                   135
#define VARIOUS_SWAP_STATS                           136
#define VARIOUS_TEATIME_INVUL                        137
#define VARIOUS_TEATIME_TARGETS                      138
#define VARIOUS_TRY_WIND_RIDER_POWER                 139
#define VARIOUS_ACTIVATE_WEATHER_CHANGE_ABILITIES    140
#define VARIOUS_ACTIVATE_TERRAIN_CHANGE_ABILITIES    141
#define VARIOUS_STORE_HEALING_WISH                   142
#define VARIOUS_HIT_SWITCH_TARGET_FAILED             143
#define VARIOUS_TRY_REVIVAL_BLESSING                 144

// Cmd_manipulatedamage
#define DMG_CHANGE_SIGN            0
#define DMG_RECOIL_FROM_MISS       1
#define DMG_DOUBLED                2
#define DMG_1_8_TARGET_HP          3
#define DMG_FULL_ATTACKER_HP       4
#define DMG_CURR_ATTACKER_HP       5
#define DMG_BIG_ROOT               6
#define DMG_RECOIL_FROM_IMMUNE     7 // Used to calculate recoil for the Gen 4 version of Jump Kick

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
enum MoveEndEffects
{
    MOVEEND_SUM_DAMAGE,
    MOVEEND_PROTECT_LIKE_EFFECT,
    MOVEEND_RAGE,
    MOVEEND_SYNCHRONIZE_TARGET,
    MOVEEND_ABILITIES,
    MOVEEND_ABILITIES_ATTACKER,
    MOVEEND_STATUS_IMMUNITY_ABILITIES,
    MOVEEND_SYNCHRONIZE_ATTACKER,
    MOVEEND_CHOICE_MOVE,
    MOVEEND_ATTACKER_INVISIBLE,
    MOVEEND_ATTACKER_VISIBLE,
    MOVEEND_TARGET_VISIBLE,
    MOVEEND_ITEM_EFFECTS_TARGET,
    MOVEEND_MOVE_EFFECTS2,
    MOVEEND_ITEM_EFFECTS_ALL,
    MOVEEND_KINGSROCK, // These item effects will occur each strike of a multi-hit move
    MOVEEND_NUM_HITS,
    MOVEEND_SUBSTITUTE,
    MOVEEND_SKY_DROP_CONFUSE,
    MOVEEND_UPDATE_LAST_MOVES,
    MOVEEND_MIRROR_MOVE,
    MOVEEND_NEXT_TARGET, // Everything up until here is handled for each strike of a multi-hit move
    MOVEEND_MULTIHIT_MOVE,
    MOVEEND_DEFROST,
    MOVEEND_RECOIL,
    MOVEEND_ITEM_EFFECTS_ATTACKER,
    MOVEEND_MAGICIAN, // Occurs after final multi-hit strike, and after other items/abilities would activate
    MOVEEND_EJECT_ITEMS,
    MOVEEND_WHITE_HERB,
    MOVEEND_RED_CARD,
    MOVEEND_LIFEORB_SHELLBELL, // Includes shell bell, throat spray, etc
    MOVEEND_CHANGED_ITEMS,
    MOVEEND_PICKPOCKET,
    MOVEEND_DANCER,
    MOVEEND_EMERGENCY_EXIT,
    MOVEEND_SYMBIOSIS,
    MOVEEND_OPPORTUNIST, // Occurs after other stat change items/abilities to try and copy the boosts
    MOVEEND_SAME_MOVE_TURNS,
    MOVEEND_SET_EVOLUTION_TRACKER,
    MOVEEND_CLEAR_BITS,
    MOVEEND_COUNT,
};

// switch cases
#define B_SWITCH_NORMAL     0
#define B_SWITCH_HIT        1   // dragon tail, circle throw
#define B_SWITCH_RED_CARD   2

// Argument labels for EFFECT_HIT_SET_REMOVE_TERRAIN
#define ARG_SET_PSYCHIC_TERRAIN        0
#define ARG_TRY_REMOVE_TERRAIN_HIT     1
#define ARG_TRY_REMOVE_TERRAIN_FAIL    2

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
