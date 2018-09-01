	.macro if_random_less_than param0, param1
	.byte 0x0
	.byte \param0
	.4byte \param1
	.endm

	.macro if_random_greater_than param0, param1
	.byte 0x1
	.byte \param0
	.4byte \param1
	.endm

	.macro if_random_equal param0, param1
	.byte 0x2
	.byte \param0
	.4byte \param1
	.endm

	.macro if_random_not_equal param0, param1
	.byte 0x3
	.byte \param0
	.4byte \param1
	.endm

	.macro score param0
	.byte 0x4
	.byte \param0
	.endm

	.macro if_hp_less_than bank, param1, param2
	.byte 0x5
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_hp_more_than bank, param1, param2
	.byte 0x6
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_hp_equal bank, param1, param2
	.byte 0x7
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_hp_not_equal bank, param1, param2
	.byte 0x8
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_status bank, status1, param2
	.byte 0x9
	.byte \bank
	.4byte \status1
	.4byte \param2
	.endm

	.macro if_not_status bank, status1, param2
	.byte 0xa
	.byte \bank
	.4byte \status1
	.4byte \param2
	.endm

	.macro if_status2 bank, status2, param2
	.byte 0xb
	.byte \bank
	.4byte \status2
	.4byte \param2
	.endm

	.macro if_not_status2 bank, status2, param2
	.byte 0xc
	.byte \bank
	.4byte \status2
	.4byte \param2
	.endm

	.macro if_status3 bank, status3, param2
	.byte 0xd
	.byte \bank
	.4byte \status3
	.4byte \param2
	.endm

	.macro if_not_status3 bank, status3, param2
	.byte 0xe
	.byte \bank
	.4byte \status3
	.4byte \param2
	.endm

	.macro if_side_affecting bank, sidestatus, param2
	.byte 0xf
	.byte \bank
	.4byte \sidestatus
	.4byte \param2
	.endm

	.macro if_not_side_affecting bank, sidestatus, param2
	.byte 0x10
	.byte \bank
	.4byte \sidestatus
	.4byte \param2
	.endm

	.macro if_less_than param0, param1
	.byte 0x11
	.byte \param0
	.4byte \param1
	.endm

	.macro if_more_than param0, param1
	.byte 0x12
	.byte \param0
	.4byte \param1
	.endm

	.macro if_equal param0, param1
	.byte 0x13
	.byte \param0
	.4byte \param1
	.endm

	.macro if_not_equal param0, param1
	.byte 0x14
	.byte \param0
	.4byte \param1
	.endm

	.macro if_less_than_ptr param0, param1
	.byte 0x15
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_more_than_ptr param0, param1
	.byte 0x16
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_equal_ptr param0, param1
	.byte 0x17
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_not_equal_ptr param0, param1
	.byte 0x18
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_move param0, param1
	.byte 0x19
	.2byte \param0
	.4byte \param1
	.endm

	.macro if_not_move param0, param1
	.byte 0x1a
	.2byte \param0
	.4byte \param1
	.endm

	.macro if_in_bytes param0, param1
	.byte 0x1b
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_not_in_bytes param0, param1
	.byte 0x1c
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_in_hwords param0, param1
	.byte 0x1d
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_not_in_hwords param0, param1
	.byte 0x1e
	.4byte \param0
	.4byte \param1
	.endm

	.macro if_user_has_attacking_move param0
	.byte 0x1f
	.4byte \param0
	.endm

	.macro if_user_has_no_attacking_moves param0
	.byte 0x20
	.4byte \param0
	.endm

	.macro get_turn_count
	.byte 0x21
	.endm

	.macro get_type param0
	.byte 0x22
	.byte \param0
	.endm

	.macro get_considered_move_power
	.byte 0x23
	.endm

	.macro get_how_powerful_move_is
	.byte 0x24
	.endm

	.macro get_last_used_bank_move bank
	.byte 0x25
	.byte \bank
	.endm

	.macro if_equal_ param0, param1
	.byte 0x26
	.byte \param0
	.4byte \param1
	.endm

	.macro if_not_equal_ param0, param1
	.byte 0x27
	.byte \param0
	.4byte \param1
	.endm

	.macro if_user_goes param0, param1
	.byte 0x28
	.byte \param0
	.4byte \param1
	.endm

	.macro if_user_doesnt_go param0, param1
	.byte 0x29
	.byte \param0
	.4byte \param1
	.endm

	.macro nullsub_2A
	.byte 0x2a
	.endm

	.macro nullsub_2B
	.byte 0x2b
	.endm

	.macro count_usable_party_mons bank
	.byte 0x2c
	.byte \bank
	.endm

	.macro get_considered_move
	.byte 0x2d
	.endm

	.macro get_considered_move_effect
	.byte 0x2e
	.endm

	.macro get_ability bank
	.byte 0x2f
	.byte \bank
	.endm

	.macro get_highest_type_effectiveness
	.byte 0x30
	.endm

	.macro if_type_effectiveness param0, param1
	.byte 0x31
	.byte \param0
	.4byte \param1
	.endm

	.macro nullsub_32
	.byte 0x32
	.endm

	.macro nullsub_33
	.byte 0x33
	.endm

	.macro if_status_in_party bank, status1, param2
	.byte 0x34
	.byte \bank
	.4byte \status1
	.4byte \param2
	.endm

	.macro if_status_not_in_party bank, status1, param2
	.byte 0x35
	.byte \bank
	.4byte \status1
	.4byte \param2
	.endm

	.macro get_weather
	.byte 0x36
	.endm

	.macro if_effect param0, param1
	.byte 0x37
	.byte \param0
	.4byte \param1
	.endm

	.macro if_not_effect param0, param1
	.byte 0x38
	.byte \param0
	.4byte \param1
	.endm

	.macro if_stat_level_less_than bank, stat, param2, param3
	.byte 0x39
	.byte \bank
	.byte \stat
	.byte \param2
	.4byte \param3
	.endm

	.macro if_stat_level_more_than bank, stat, param2, param3
	.byte 0x3a
	.byte \bank
	.byte \stat
	.byte \param2
	.4byte \param3
	.endm

	.macro if_stat_level_equal bank, stat, param2, param3
	.byte 0x3b
	.byte \bank
	.byte \stat
	.byte \param2
	.4byte \param3
	.endm

	.macro if_stat_level_not_equal bank, stat, param2, param3
	.byte 0x3c
	.byte \bank
	.byte \stat
	.byte \param2
	.4byte \param3
	.endm

	.macro if_can_faint param0
	.byte 0x3d
	.4byte \param0
	.endm

	.macro if_cant_faint param0
	.byte 0x3e
	.4byte \param0
	.endm

	.macro if_has_move bank, param1, param2
	.byte 0x3f
	.byte \bank
	.2byte \param1
	.4byte \param2
	.endm

	.macro if_doesnt_have_move bank, param1, param2
	.byte 0x40
	.byte \bank
	.2byte \param1
	.4byte \param2
	.endm

	.macro if_has_move_with_effect bank, param1, param2
	.byte 0x41
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_doesnt_have_move_with_effect bank, param1, param2
	.byte 0x42
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_any_move_disabled_or_encored bank, param1, param2
	.byte 0x43
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro if_curr_move_disabled_or_encored param0, param1
	.byte 0x44
	.byte \param0
	.4byte \param1
	.endm

	.macro flee
	.byte 0x45
	.endm

	.macro if_random_safari_flee param0
	.byte 0x46
	.4byte \param0
	.endm

	.macro watch
	.byte 0x47
	.endm

	.macro get_hold_effect bank
	.byte 0x48
	.byte \bank
	.endm

	.macro get_gender bank
	.byte 0x49
	.byte \bank
	.endm

	.macro is_first_turn_for bank
	.byte 0x4a
	.byte \bank
	.endm

	.macro get_stockpile_count bank
	.byte 0x4b
	.byte \bank
	.endm

	.macro is_double_battle
	.byte 0x4c
	.endm

	.macro get_used_held_item bank
	.byte 0x4d
	.byte \bank
	.endm

	.macro get_move_type_from_result
	.byte 0x4e
	.endm

	.macro get_move_power_from_result
	.byte 0x4f
	.endm

	.macro get_move_effect_from_result
	.byte 0x50
	.endm

	.macro get_protect_count bank
	.byte 0x51
	.byte \bank
	.endm

	.macro if_move_flag flag jumpptr
	.byte 0x52
	.2byte \flag
	.4byte \jumpptr
	.endm

	.macro if_field_status flag jumpptr
	.byte 0x53
	.word \flag
	.word \jumpptr
	.endm

	.macro get_move_accuracy
	.byte 0x54
	.endm

	.macro call_if_eq value, ptr
	.byte 0x55
	.2byte \value
	.4byte \ptr
	.endm

	.macro call_if_move_flag flag ptr
	.byte 0x52
	.2byte \flag
	.4byte \ptr
	.endm

	.macro nullsub_57
	.byte 0x57
	.endm

	.macro call param0
	.byte 0x58
	.4byte \param0
	.endm

	.macro goto param0
	.byte 0x59
	.4byte \param0
	.endm

	.macro end
	.byte 0x5a
	.endm

	.macro if_level_cond param0, param1
	.byte 0x5b
	.byte \param0
	.4byte \param1
	.endm

	.macro if_target_taunted param0
	.byte 0x5c
	.4byte \param0
	.endm

	.macro if_target_not_taunted param0
	.byte 0x5d
	.4byte \param0
	.endm

	.macro if_target_is_ally param0
	.byte 0x5e
	.4byte \param0
	.endm

	.macro is_of_type bank, type
	.byte 0x5f
	.byte \bank
	.byte \type
	.endm

	.macro check_ability bank, ability
	.byte 0x60
	.byte \bank
	.byte \ability
	.endm

	.macro if_flash_fired bank, param1
	.byte 0x61
	.byte \bank
	.4byte \param1
	.endm

	.macro if_holds_item bank, param1, param2
	.byte 0x62
	.byte \bank
	.2byte \param1
	.4byte \param2
	.endm
	
	.macro get_ally_chosen_move bank
	.byte 0x63
	.endm
	
	.macro if_has_no_attacking_moves bank, param1
	.byte 0x64
	.byte \bank
	.4byte \param1
	.endm
	
@ useful script macros
	.macro get_curr_move_type
	get_type AI_TYPE_MOVE
	.endm
	
	.macro get_user_type1
	get_type AI_TYPE1_USER
	.endm
	
	.macro get_user_type2
	get_type AI_TYPE2_USER
	.endm
	
	.macro get_target_type1
	get_type AI_TYPE1_TARGET
	.endm
	
	.macro get_target_type2
	get_type AI_TYPE2_TARGET
	.endm
	
	.macro if_ability bank, ability, ptr
	check_ability \bank, \ability
	if_equal 1, \ptr
	.endm
	
	.macro if_no_ability bank, ability, ptr
	check_ability \bank, \ability
	if_equal 0, \ptr
	.endm
	
	.macro if_type bank, type, ptr
	is_of_type \bank, \type
	if_equal 1, \ptr
	.endm

	.macro if_no_type bank, type, ptr
	is_of_type \bank, \type
	if_equal 0, \ptr
	.endm
	
	.macro if_target_faster ptr
	if_user_goes 1, \ptr
	.endm
	
	.macro if_user_faster ptr
	if_user_goes 0, \ptr
	.endm
	
	.macro if_double_battle ptr
	is_double_battle
	if_equal 1, \ptr
	.endm
	
	.macro if_not_double_battle ptr
	is_double_battle
	if_equal 0, \ptr
	.endm

	.macro if_any_move_disabled bank, ptr
	if_any_move_disabled_or_encored \bank, 0, \ptr
	.endm
	
	.macro if_any_move_encored bank, ptr
	if_any_move_disabled_or_encored \bank, 1, \ptr
	.endm
	
	.macro call_if_always_hit ptr
	get_move_accuracy
	call_if_eq 0, \ptr
	.endm
