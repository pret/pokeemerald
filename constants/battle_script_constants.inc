@ atk 80
	.set ATK80_DMG_CHANGE_SIGN, 0x0
	.set ATK80_DMG_HALF_BY_TWO_NOT_MORE_THAN_HALF_MAX_HP, 0x1
	.set ATK80_DMG_DOUBLED, 0x2
	
@ compare operands
	.set EQUAL, 0x0
	.set NOT_EQUAL, 0x1
	.set GREATER_THAN, 0x2
	.set LESS_THAN, 0x3
	.set COMMON_BITS, 0x4
	.set NO_COMMON_BITS, 0x5
	
@ accuracy calc
	.set NO_ACC_CALC, 0xFFFE
	.set NO_ACC_CALC_CHECK_LOCK_ON, 0xFFFF
	.set ACC_CURR_MOVE, 0x0

@ bank values
	.set TARGET, 0x0
	.set ATTACKER, 0x1
	.set MOVE_EFFECT_BANK, 0x2
	.set GBANK_1, 0x3
	.set ATTACKER_WITH_PARTNER, 0x4 @ only for cmd98
	.set BANK0, 0x7
	.set SCRIPTING_BANK, 0xA
	.set OPPONENT1, 0xC
	
@ various
	.set VARIOUS_CANCEL_MULTI_TURN_MOVES, 0
	.set VARIOUS_SET_MAGIC_COAT_TARGET, 1
	.set VARIOUS_IS_RUNNING_IMPOSSIBLE, 2
	.set VARIOUS_GET_MOVE_TARGET, 3
	.set VARIOUS_RESET_INTIMIDATE_TRACE_BITS, 5
	.set VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP, 6
	.set VARIOUS_EMIT_YESNOBOX, 13
	.set VARIOUS_WAIT_CRY, 18
	.set VARIOUS_RETURN_OPPONENT_MON1, 19
	.set VARIOUS_RETURN_OPPONENT_MON2, 20
	.set VARIOUS_SET_TELEPORT_OUTCOME, 25
	.set VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC, 26
	
@ jumpifcant switch flag argument
	.set ATK4F_DONT_CHECK_STATUSES, 0x80

@ battle scripting struct
	.equiv sPAINSPLIT_HP, gBattleScripting
	.equiv sBIDE_DMG, gBattleScripting + 4
	.equiv sMULTIHIT_STRING, gBattleScripting + 8
	.equiv sDMG_MULTIPLIER, gBattleScripting + 0xE
	.equiv sTWOTURN_STRINGID, gBattleScripting + 0xF
	.equiv sB_ANIM_ARG1, gBattleScripting + 0x10
	.equiv sB_ANIM_ARG2, gBattleScripting + 0x11
	.equiv sTRIPLE_KICK_POWER, gBattleScripting + 0x12
	.equiv sMOVEEND_STATE, gBattleScripting + 0x14
	.equiv sBANK_WITH_ABILITY, gBattleScripting + 0x15
	.equiv sMULTIHIT_EFFECT, gBattleScripting + 0x16
	.equiv sBANK, gBattleScripting + 0x17
	.equiv sB_ANIM_TURN, gBattleScripting + 0x18
	.equiv sB_ANIM_TARGETS_HIT, gBattleScripting + 0x19
	.equiv sSTATCHANGER, gBattleScripting + 0x1A
	.equiv sFIELD_1B, gBattleScripting + 0x1B
	.equiv sGIVEEXP_STATE, gBattleScripting + 0x1C
	.equiv sBATTLE_STYLE, gBattleScripting + 0x1D
	.equiv sLVLBOX_STATE, gBattleScripting + 0x1E
	.equiv sLEARNMOVE_STATE, gBattleScripting + 0x1F
	.equiv sFIELD_20, gBattleScripting + 0x20
	.equiv sRESHOW_MAIN_STATE, gBattleScripting + 0x21
	.equiv sRESHOW_HELPER_STATE, gBattleScripting + 0x22
	.equiv sFIELD_23, gBattleScripting + 0x23
	.equiv sFIELD_24, gBattleScripting + 0x24
	.equiv sMULTIPLAYER_ID, gBattleScripting + 0x25

@ battle communication struct
	.equiv cEFFECT_CHOOSER, gBattleCommunication + 3
	.equiv cMULTISTRING_CHOOSER, gBattleCommunication + 5
