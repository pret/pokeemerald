@ A large number of the Contest AI commands go unused, so their corresponding macros in this file are similarly unused

@ Add a positive/negative value to the score of the move being evaluated.

	.macro score score:req
	.byte 0x00
	.byte \score
	.endm

	.macro get_appeal_num
	.byte 0x01
	.endm

	.macro if_appeal_num_less_than num:req, destination:req
	.byte 0x02
	.byte \num
	.4byte \destination
	.endm

	.macro if_appeal_num_more_than num:req, destination:req
	.byte 0x03
	.byte \num
	.4byte \destination
	.endm

	.macro if_appeal_num_eq num:req, destination:req
	.byte 0x04
	.byte \num
	.4byte \destination
	.endm

	.macro if_appeal_num_not_eq num:req, destination:req
	.byte 0x05
	.byte \num
	.4byte \destination
	.endm

	.macro if_last_appeal destination:req
	if_appeal_num_eq CONTEST_LAST_APPEAL, \destination
	.endm

	.macro if_not_last_appeal destination:req
	if_appeal_num_not_eq CONTEST_LAST_APPEAL, \destination
	.endm

@ audience excitement

	.macro get_excitement
	.byte 0x06
	.endm

	.macro if_excitement_less_than num:req, destination:req
	.byte 0x07
	.byte \num
	.4byte \destination
	.endm

	.macro if_excitement_more_than num:req, destination:req
	.byte 0x08
	.byte \num
	.4byte \destination
	.endm

	.macro if_excitement_eq num:req, destination:req
	.byte 0x09
	.byte \num
	.4byte \destination
	.endm

	.macro if_excitement_not_eq num:req, destination:req
	.byte 0x0A
	.byte \num
	.4byte \destination
	.endm

@ the order that the user goes in the current appeal

	.macro get_user_order
	.byte 0x0B
	.endm

	.macro if_user_order_less_than num:req, destination:req
	.byte 0x0C
	.byte \num
	.4byte \destination
	.endm

	.macro if_user_order_more_than num:req, destination:req
	.byte 0x0D
	.byte \num
	.4byte \destination
	.endm

	.macro if_user_order_eq num:req, destination:req
	.byte 0x0E
	.byte \num
	.4byte \destination
	.endm

	.macro if_user_order_not_eq num:req, destination:req
	.byte 0x0F
	.byte \num
	.4byte \destination
	.endm

@ user condition

	.macro get_user_condition
	.byte 0x10
	.endm

	.macro if_user_condition_less_than num:req, destination:req
	.byte 0x11
	.byte \num
	.4byte \destination
	.endm

	.macro if_user_condition_more_than num:req, destination:req
	.byte 0x12
	.byte \num
	.4byte \destination
	.endm

	.macro if_user_condition_eq num:req, destination:req
	.byte 0x13
	.byte \num
	.4byte \destination
	.endm

	.macro if_user_condition_not_eq num:req, destination:req
	.byte 0x14
	.byte \num
	.4byte \destination
	.endm

@ appeal points

	.macro get_point_total
	.byte 0x15
	.endm

	.macro if_points_less_than num:req, destination:req
	.byte 0x16
	.2byte \num
	.4byte \destination
	.endm

	.macro if_points_more_than num:req, destination:req
	.byte 0x17
	.2byte \num
	.4byte \destination
	.endm

	.macro if_points_eq num:req, destination:req
	.byte 0x18
	.2byte \num
	.4byte \destination
	.endm

	.macro if_points_not_eq num:req, destination:req
	.byte 0x19
	.2byte \num
	.4byte \destination
	.endm

@ preliminary (pre-appeal) judging points

	.macro get_preliminary_points
	.byte 0x1A
	.endm

	.macro if_preliminary_points_less_than num:req, destination:req
	.byte 0x1B
	.2byte \num
	.4byte \destination
	.endm

	.macro if_preliminary_points_more_than num:req, destination:req
	.byte 0x1C
	.2byte \num
	.4byte \destination
	.endm

	.macro if_preliminary_points_eq num:req, destination:req
	.byte 0x1D
	.2byte \num
	.4byte \destination
	.endm

	.macro if_preliminary_points_not_eq num:req, destination:req
	.byte 0x1E
	.2byte \num
	.4byte \destination
	.endm

@ contest type

	.macro get_contest_type
	.byte 0x1F
	.endm

	.macro if_contest_type_eq type:req, destination:req
	.byte 0x20
	.byte \type
	.4byte \destination
	.endm

	.macro if_contest_type_not_eq type:req, destination:req
	.byte 0x21
	.byte \type
	.4byte \destination
	.endm

@ move excitement (change in excitement due to move)

	.macro get_move_excitement
	.byte 0x22
	.endm

	.macro if_move_excitement_less_than num:req, destination:req
	.byte 0x23
	.byte \num
	.4byte \destination
	.endm

	.macro if_move_excitement_more_than num:req, destination:req
	.byte 0x24
	.byte \num
	.4byte \destination
	.endm

	.macro if_move_excitement_eq num:req, destination:req
	.byte 0x25
	.byte \num
	.4byte \destination
	.endm

	.macro if_move_excitement_not_eq num:req, destination:req
	.byte 0x26
	.byte \num
	.4byte \destination
	.endm

@ move effect

	.macro get_effect
	.byte 0x27
	.endm

	.macro if_effect_eq effect:req, destination:req
	.byte 0x28
	.byte \effect
	.4byte \destination
	.endm

	.macro if_effect_not_eq effect:req, destination:req
	.byte 0x29
	.byte \effect
	.4byte \destination
	.endm

@ move effect type

	.macro get_effect_type
	.byte 0x2A
	.endm

	.macro if_effect_type_eq type:req, destination:req
	.byte 0x2B
	.byte \type
	.4byte \destination
	.endm

	.macro if_effect_type_not_eq type:req, destination:req
	.byte 0x2C
	.byte \type
	.4byte \destination
	.endm

@ whether the current move is the most appealing in the user's moveset

	.macro check_most_appealing_move
	.byte 0x2D
	.endm

	.macro if_most_appealing_move destination:req
	.byte 0x2E
	.4byte \destination
	.endm

@ whether the current move is the most jamming in the user's moveset

	.macro check_most_jamming_move
	.byte 0x2F
	.endm

	.macro if_most_jamming_move destination:req
	.byte 0x30
	.4bye \destination
	.endm

@ number of hearts the current move's appeal would provide

	.macro get_num_move_hearts
	.byte 0x31
	.endm

	.macro if_num_move_hearts_less_than num:req, destination:req
	.byte 0x32
	.byte \num
	.4byte \destination
	.endm

	.macro if_num_move_hearts_more_than num:req, destination:req
	.byte 0x33
	.byte \num
	.4byte \destination
	.endm

	.macro if_num_move_hearts_eq num:req, destination:req
	.byte 0x34
	.byte \num
	.4byte \destination
	.endm

	.macro if_num_move_hearts_not_eq num:req, destination:req
	.byte 0x35
	.byte \num
	.4byte \destination
	.endm

@ number of hearts the current move's jam would remove

	.macro get_num_move_jam_hearts
	.byte 0x36
	.endm

	.macro if_num_move_jam_hearts_less_than num:req, destination:req
	.byte 0x37
	.byte \num
	.4byte \destination
	.endm

	.macro if_num_move_jam_hearts_more_than num:req, destination:req
	.byte 0x38
	.byte \num
	.4byte \destination
	.endm

	.macro if_num_move_jam_hearts_eq num:req, destination:req
	.byte 0x39
	.byte \num
	.4byte \destination
	.endm

	.macro if_num_move_jam_hearts_not_eq num:req, destination:req
	.byte 0x3A
	.byte \num
	.4byte \destination
	.endm

@ number of times current move has been used

	.macro get_move_used_count
	.byte 0x3B
	.endm

	.macro if_move_used_count_less_than num:req, destination:req
	.byte 0x3C
	.byte \num
	.4byte \destination
	.endm

	.macro if_move_used_count_more_than num:req, destination:req
	.byte 0x3D
	.byte \num
	.4byte \destination
	.endm

	.macro if_move_used_count_eq num:req, destination:req
	.byte 0x3E
	.byte \num
	.4byte \destination
	.endm

	.macro if_move_used_count_not_eq num:req, destination:req
	.byte 0x3F
	.byte \num
	.4byte \destination
	.endm

@ whether the current move is a combo starter (with another move in the moveset)

	.macro check_combo_starter
	.byte 0x40
	.endm

	.macro if_combo_starter destination:req
	.byte 0x41
	.4byte \destination
	.endm

	.macro if_not_combo_starter destination:req
	.byte 0x42
	.4byte \destination
	.endm

@ whether the current move is a combo finisher (with another move in the moveset)

	.macro check_combo_finisher
	.byte 0x43
	.endm

	.macro if_combo_finisher destination:req
	.byte 0x44
	.4byte \destination
	.endm

	.macro if_not_combo_finisher destination:req
	.byte 0x45
	.4byte \destination
	.endm

@ whether the current move would finish a combo

	.macro check_would_finish_combo
	.byte 0x46
	.endm

	.macro if_would_finish_combo destination:req
	.byte 0x47
	.4byte \destination
	.endm

	.macro if_would_not_finish_combo destination:req
	.byte 0x48
	.4byte \destination
	.endm

@ condition of mon (indexed by order)

	.macro get_condition mon:req
	.byte 0x49
	.byte \mon
	.endm

	.macro if_condition_less_than mon:req, num:req destination:req
	.byte 0x4A
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

	.macro if_condition_more_than mon:req, num:req, destination:req
	.byte 0x4B
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

	.macro if_condition_eq mon:req, num:req, destination:req
	.byte 0x4C
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

	.macro if_condition_not_eq mon:req, num:req, destination:req
	.byte 0x4D
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

@ whether the mon used a combo starter move
@ Even though this value is always 1 or 0 (i.e. TRUE/FALSE),
@ there are less-than and greater-than comparison operations for some reason.

	.macro get_used_combo_starter mon:req
	.byte 0x4E
	.byte \mon
	.endm

	.macro if_used_combo_starter_less_than mon:req, num:req, destination:req
	.byte 0x4F
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

	.macro if_used_combo_starter_more_than mon:req, num:req, destination:req
	.byte 0x50
	.byte \mon
	.byte \num
	.4byte \destination
	.endm


	.macro if_used_combo_starter_eq mon:req, num:req, destination:req
	.byte 0x51
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

	.macro if_used_combo_starter_not_eq mon:req, num:req, destination:req
	.byte 0x52
	.byte \mon
	.byte \num
	.4byte \destination
	.endm

	.macro if_used_combo_starter mon:req, destination:req
	if_used_combo_starter_eq \mon, TRUE, \destination
	.endm

	.macro if_not_used_combo_starter mon:req, destination:req
	if_used_combo_starter_eq \mon, FALSE, \destination
	.endm

@ whether the mon can make an appeal

	.macro check_can_participate mon:req
	.byte 0x53
	.byte \mon
	.endm

	.macro if_can_participate mon:req, destination:req
	.byte 0x54
	.byte \mon
	.4byte \destination
	.endm

	.macro if_cannot_participate mon:req, destination:req
	.byte 0x55
	.byte \mon
	.4byte \destination
	.endm

@ whether the mon just completed a combo

	.macro get_completed_combo mon:req
	.byte 0x56
	.byte \mon
	.4byte \destination
	.endm

	.macro if_completed_combo mon:req, destination:req
	.byte 0x57
	.byte \mon
	.4byte \destination
	.endm

	.macro if_not_completed_combo mon:req destination:req
	.byte 0x58
	.byte \mon
	.4byte \destination
	.endm

@ comparing appeal points to another mon

	.macro get_points_diff mon:req
	.byte 0x59
	.byte \mon
	.endm

	.macro if_points_more_than_mon mon:req, destination:req
	.byte 0x5A
	.byte \mon
	.4byte \destination
	.endm

	.macro if_points_less_than_mon mon:req, destination:req
	.byte 0x5B
	.byte \mon
	.4byte \destination
	.endm

	.macro if_points_eq_mon mon:req, destination:req
	.byte 0x5C
	.byte \mon
	.4byte \destination
	.endm

	.macro if_points_not_eq_mon mon:req, destination:req
	.byte 0x5D
	.byte \mon
	.4byte \destination
	.endm

@ comparing preliminary judging points to another mon

	.macro get_preliminary_points_diff mon:req
	.byte 0x5E
	.byte \mon
	.endm

	.macro if_preliminary_points_more_than_mon mon:req, destination:req
	.byte 0x5F
	.byte \mon
	.4byte \destination
	.endm

	.macro if_preliminary_points_less_than_mon mon:req, destination:req
	.byte 0x60
	.byte \mon
	.4byte \destination
	.endm

	.macro if_preliminary_points_eq_mon mon:req, destination:req
	.byte 0x61
	.byte \mon
	.4byte \destination
	.endm

	.macro if_preliminary_points_not_eq_mon mon:req, destination:req
	.byte 0x62
	.byte \mon
	.4byte \destination
	.endm

@ checking move history for move effect

	.macro get_used_moves_effect mon:req, round:req
	.byte 0x63
	.byte \mon
	.byte \round
	.endm

	.macro if_used_moves_effect_less_than mon:req, round:req, effect:req, destination:req
	.byte 0x64
	.byte \mon
	.byte \round
	.byte \effect
	.4byte \destination
	.endm

	.macro if_used_moves_effect_more_than mon:req, round:req, effect:req, destination:req
	.byte 0x65
	.byte \mon
	.byte \round
	.byte \effect
	.4byte \destination
	.endm

	.macro if_used_moves_effect_eq mon:req, round:req, effect:req, destination:req
	.byte 0x66
	.byte \mon
	.byte \round
	.byte \effect
	.4byte \destination
	.endm

	.macro if_used_moves_effect_not_eq mon:req, round:req, effect:req, destination:req
	.byte 0x67
	.byte \mon
	.byte \round
	.byte \effect
	.4byte \destination
	.endm

@ checking move history for excitement

	.macro get_used_moves_excitement mon:req, round:req
	.byte 0x68
	.byte \mon
	.byte \round
	.endm

	.macro if_used_moves_excitement_less_than mon:req, round:req, num:req, destination:req
	.byte 0x69
	.byte \mon
	.byte \round
	.byte \num
	.4byte \destination
	.endm

	.macro if_used_moves_excitement_more_than mon:req, round:req, num:req, destination:req
	.byte 0x6A
	.byte \mon
	.byte \round
	.byte \num
	.4byte \destination
	.endm

	.macro if_used_moves_excitement_eq mon:req, round:req, num:req, destination:req
	.byte 0x6B
	.byte \mon
	.byte \round
	.byte \num
	.4byte \destination
	.endm

	.macro if_used_moves_excitement_not_eq mon:req, round:req, num:req, destination:req
	.byte 0x6C
	.byte \mon
	.byte \round
	.byte \num
	.4byte \destination
	.endm

@ checking move history for effect type

	.macro get_used_moves_effect_type mon:req, round:req
	.byte 0x6D
	.byte \mon
	.byte \round
	.endm

	.macro if_used_moves_effect_type_eq mon:req, round:req, type:req, destination:req
	.byte 0x6E
	.byte \mon
	.byte \round
	.byte \type
	.4byte \destination
	.endm

	.macro if_used_moves_effect_type_not_eq mon:req, round:req, type:req, destination:req
	.byte 0x6F
	.byte \mon
	.byte \round
	.byte \type
	.4byte \destination
	.endm

@ generic commands

	.macro save_result varId:req
	.byte 0x70
	.byte \varId
	.endm

	.macro setvar varId:req, num:req
	.byte 0x71
	.byte \varId
	.2byte \num
	.endm

	.macro add varId:req, num:req
	.byte 0x72
	.byte \varId
	.2byte \num
	.endm

	.macro addvar varId1:req, varId2:req
	.byte 0x73
	.byte \varId1
	.byte \varId2
	.endm

	@ Duplicate of above
	.macro addvar_duplicate varId1:req, varId2:req
	.byte 0x74
	.byte \varId1
	.byte \varId2
	.endm

	.macro if_less_than varId:req, num:req, destination:req
	.byte 0x75
	.byte \varId
	.2byte \num
	.4byte \destination
	.endm

	.macro if_greater_than varId:req, num:req, destination:req
	.byte 0x76
	.byte \varId
	.2byte \num
	.4byte \destination
	.endm

	.macro if_eq varId:req, num:req, destination:req
	.byte 0x77
	.byte \varId
	.2byte \num
	.4byte \destination
	.endm

	.macro if_not_eq varId:req, num:req, destination:req
	.byte 0x78
	.byte \varId
	.2byte \num
	.4byte \destination
	.endm

	.macro if_less_than_var varId1:req, varId2:req, destination:req
	.byte 0x79
	.byte \varId1
	.byte \varId2
	.4byte \destination
	.endm

	.macro if_greater_than_var varId1:req, varId2:req, destination:req
	.byte 0x7A
	.byte \varId1
	.byte \varId2
	.4byte \destination
	.endm

	.macro if_eq_var varId1:req, varId2:req, destination:req
	.byte 0x7B
	.byte \varId1
	.byte \varId2
	.4byte \destination
	.endm

	.macro if_not_eq_var varId1:req, varId2:req, destination:req
	.byte 0x7C
	.byte \varId1
	.byte \varId2
	.4byte \destination
	.endm

	@ NOTE: The random commands are broken (see ContestAICmd_if_random_less_than)
	.macro if_random_less_than num:req, destination:req
	.byte 0x7D
	.byte \num
	.4byte \destination
	.endm

	.macro if_random_greater_than num:req, destination:req
	.byte 0x7E
	.byte \num
	.4byte \destination
	.endm

	.macro goto destination:req
	.byte 0x7F
	.4byte \destination
	.endm

	.macro call destination:req
	.byte 0x80
	.4byte \destination
	.endm

	.macro end
	.byte 0x81
	.endm

	.macro check_user_has_exciting_move
	.byte 0x82
	.endm

	.macro if_user_has_exciting_move destination:req
	.byte 0x83
	.4byte \destination
	.endm

	.macro if_user_doesnt_have_exciting_move destination:req
	.byte 0x84
	.4byte \destination
	.endm

	@ This is used incorrectly to check for an effect; see ContestAICmd_check_user_has_move
	.macro check_user_has_move move:req
	.byte 0x85
	.2byte \move
	.endm

	.macro if_user_has_move move:req, destination:req
	.byte 0x86
	.2byte \move
	.4byte \destination
	.endm

	.macro if_user_doesnt_have_move move:req, destination:req
	.byte 0x87
	.2byte \move
	.4byte \destination
	.endm
