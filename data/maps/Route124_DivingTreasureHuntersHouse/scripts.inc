Route124_DivingTreasureHuntersHouse_MapScripts:: @ 8270A28
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_DivingTreasureHuntersHouse_OnTransition
	.byte 0

Route124_DivingTreasureHuntersHouse_OnTransition: @ 8270A2E
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
	end

Route124_DivingTreasureHuntersHouse_EventScript_270A32:: @ 8270A32
	lock
	faceplayer
	goto_if_set FLAG_MET_DIVING_TREASURE_HUNTER, Route124_DivingTreasureHuntersHouse_EventScript_270A4E
	msgbox Route124_DivingTreasureHuntersHouse_Text_270F6C, MSGBOX_DEFAULT
	setflag FLAG_MET_DIVING_TREASURE_HUNTER
	goto Route124_DivingTreasureHuntersHouse_EventScript_270A5C
	end

Route124_DivingTreasureHuntersHouse_EventScript_270A4E:: @ 8270A4E
	msgbox Route124_DivingTreasureHuntersHouse_Text_270FE5, MSGBOX_DEFAULT
	goto Route124_DivingTreasureHuntersHouse_EventScript_270A5C
	end

Route124_DivingTreasureHuntersHouse_EventScript_270A5C:: @ 8270A5C
	call Route124_DivingTreasureHuntersHouse_EventScript_270A72
	compare VAR_TEMP_1, 0
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270F57
	goto Route124_DivingTreasureHuntersHouse_EventScript_270AD0
	end

Route124_DivingTreasureHuntersHouse_EventScript_270A72:: @ 8270A72
	setvar VAR_TEMP_1, 0
	checkitem ITEM_RED_SHARD, 1
	compare VAR_RESULT, 1
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270AB8
	checkitem ITEM_YELLOW_SHARD, 1
	compare VAR_RESULT, 1
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270ABE
	checkitem ITEM_BLUE_SHARD, 1
	compare VAR_RESULT, 1
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270AC4
	checkitem ITEM_GREEN_SHARD, 1
	compare VAR_RESULT, 1
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270ACA
	return

Route124_DivingTreasureHuntersHouse_EventScript_270AB8:: @ 8270AB8
	addvar VAR_TEMP_1, 1
	return

Route124_DivingTreasureHuntersHouse_EventScript_270ABE:: @ 8270ABE
	addvar VAR_TEMP_1, 2
	return

Route124_DivingTreasureHuntersHouse_EventScript_270AC4:: @ 8270AC4
	addvar VAR_TEMP_1, 4
	return

Route124_DivingTreasureHuntersHouse_EventScript_270ACA:: @ 8270ACA
	addvar VAR_TEMP_1, 8
	return

Route124_DivingTreasureHuntersHouse_EventScript_270AD0:: @ 8270AD0
	msgbox Route124_DivingTreasureHuntersHouse_Text_271098, MSGBOX_DEFAULT
	goto Route124_DivingTreasureHuntersHouse_EventScript_270ADE
	end

Route124_DivingTreasureHuntersHouse_EventScript_270ADE:: @ 8270ADE
	message Route124_DivingTreasureHuntersHouse_Text_271117
	waitmessage
	switch VAR_TEMP_1
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270B8F
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270BB5
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_270BDB
	case 4, Route124_DivingTreasureHuntersHouse_EventScript_270C0C
	case 5, Route124_DivingTreasureHuntersHouse_EventScript_270C32
	case 6, Route124_DivingTreasureHuntersHouse_EventScript_270C63
	case 7, Route124_DivingTreasureHuntersHouse_EventScript_270C94
	case 8, Route124_DivingTreasureHuntersHouse_EventScript_270CD0
	case 9, Route124_DivingTreasureHuntersHouse_EventScript_270CF6
	case 10, Route124_DivingTreasureHuntersHouse_EventScript_270D27
	case 11, Route124_DivingTreasureHuntersHouse_EventScript_270D58
	case 12, Route124_DivingTreasureHuntersHouse_EventScript_270D94
	case 13, Route124_DivingTreasureHuntersHouse_EventScript_270DC5
	case 14, Route124_DivingTreasureHuntersHouse_EventScript_270E01
	case 15, Route124_DivingTreasureHuntersHouse_EventScript_270E3D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270B8F:: @ 8270B8F
	multichoice 0, 0, MULTI_SHARDS_R, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270BB5:: @ 8270BB5
	multichoice 0, 0, MULTI_SHARDS_Y, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270BDB:: @ 8270BDB
	multichoice 0, 0, MULTI_SHARDS_RY, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270C0C:: @ 8270C0C
	multichoice 0, 0, MULTI_SHARDS_B, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270C32:: @ 8270C32
	multichoice 0, 0, MULTI_SHARDS_RB, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270C63:: @ 8270C63
	multichoice 0, 0, MULTI_SHARDS_YB, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270C94:: @ 8270C94
	multichoice 0, 0, MULTI_SHARDS_RYB, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270CD0:: @ 8270CD0
	multichoice 0, 0, MULTI_SHARDS_G, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270CF6:: @ 8270CF6
	multichoice 0, 0, MULTI_SHARDS_RG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270D27:: @ 8270D27
	multichoice 0, 0, MULTI_SHARDS_YG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270D58:: @ 8270D58
	multichoice 0, 0, MULTI_SHARDS_RYG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270D94:: @ 8270D94
	multichoice 0, 0, MULTI_SHARDS_BG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270DC5:: @ 8270DC5
	multichoice 0, 0, MULTI_SHARDS_RBG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270E01:: @ 8270E01
	multichoice 0, 0, MULTI_SHARDS_YBG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270E3D:: @ 8270E3D
	multichoice 0, 0, MULTI_SHARDS_RYBG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_270E84
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_270E93
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_270EA2
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_270EB1
	case 4, Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270E84:: @ 8270E84
	setvar VAR_0x8008, ITEM_RED_SHARD
	setvar VAR_0x8009, ITEM_FIRE_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_270EC0

Route124_DivingTreasureHuntersHouse_EventScript_270E93:: @ 8270E93
	setvar VAR_0x8008, ITEM_YELLOW_SHARD
	setvar VAR_0x8009, ITEM_THUNDER_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_270EC0

Route124_DivingTreasureHuntersHouse_EventScript_270EA2:: @ 8270EA2
	setvar VAR_0x8008, ITEM_BLUE_SHARD
	setvar VAR_0x8009, ITEM_WATER_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_270EC0

Route124_DivingTreasureHuntersHouse_EventScript_270EB1:: @ 8270EB1
	setvar VAR_0x8008, ITEM_GREEN_SHARD
	setvar VAR_0x8009, ITEM_LEAF_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_270EC0

Route124_DivingTreasureHuntersHouse_EventScript_270EC0:: @ 8270EC0
	bufferitemname 0, VAR_0x8008
	bufferitemname 1, VAR_0x8009
	msgbox Route124_DivingTreasureHuntersHouse_Text_271132, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, 1
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270F01
	checkitem VAR_0x8008, 2
	compare VAR_RESULT, 0
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270F01
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F43
	end

Route124_DivingTreasureHuntersHouse_EventScript_270F01:: @ 8270F01
	takeitem VAR_0x8008, 1
	giveitem_std VAR_0x8009
	msgbox Route124_DivingTreasureHuntersHouse_Text_271158, MSGBOX_DEFAULT
	call Route124_DivingTreasureHuntersHouse_EventScript_270A72
	compare VAR_TEMP_1, 0
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270F61
	msgbox Route124_DivingTreasureHuntersHouse_Text_27117B, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_270ADE
	goto Route124_DivingTreasureHuntersHouse_EventScript_270F4D
	end

Route124_DivingTreasureHuntersHouse_EventScript_270F43:: @ 8270F43
	msgbox Route124_DivingTreasureHuntersHouse_Text_2711A0, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_270F4D:: @ 8270F4D
	msgbox Route124_DivingTreasureHuntersHouse_Text_2711D8, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_270F57:: @ 8270F57
	msgbox Route124_DivingTreasureHuntersHouse_Text_271027, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_270F61:: @ 8270F61
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_270F63:: @ 8270F63
	msgbox Route124_DivingTreasureHuntersHouse_Text_271217, MSGBOX_SIGN
	end

Route124_DivingTreasureHuntersHouse_Text_270F6C: @ 8270F6C
	.string "I'm the DIVING TREASURE HUNTER!\p"
	.string "I'm the awesome dude who makes\n"
	.string "deep-sea dives to gather treasures\l"
	.string "resting at the bottom.$"

Route124_DivingTreasureHuntersHouse_Text_270FE5: @ 8270FE5
	.string "Tell me, have you seen any SHARDS of\n"
	.string "tools made in ancient times?$"

Route124_DivingTreasureHuntersHouse_Text_271027: @ 8271027
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any SHARDS, like the RED\n"
	.string "SHARD, you've got to trade it with me!$"

Route124_DivingTreasureHuntersHouse_Text_271098: @ 8271098
	.string "Oh, hey! That…\n"
	.string "That's a SHARD! I'm looking for those!\p"
	.string "Oh, man, you've got to trade that\n"
	.string "with me! I'll give you something good!$"

Route124_DivingTreasureHuntersHouse_Text_271117: @ 8271117
	.string "What do you want to trade?$"

Route124_DivingTreasureHuntersHouse_Text_271132: @ 8271132
	.string "You'll trade your {STR_VAR_1} for\n"
	.string "my {STR_VAR_2}, then?$"

Route124_DivingTreasureHuntersHouse_Text_271158: @ 8271158
	.string "It's a done deal!\n"
	.string "Use that wisely!$"

Route124_DivingTreasureHuntersHouse_Text_27117B: @ 827117B
	.string "Do you want to trade something else?$"

Route124_DivingTreasureHuntersHouse_Text_2711A0: @ 82711A0
	.string "Whoops, your BAG's full.\n"
	.string "Get rid of some items, friend!$"

Route124_DivingTreasureHuntersHouse_Text_2711D8: @ 82711D8
	.string "No? That's a downer.\n"
	.string "Well, if you change your mind, come back.$"

Route124_DivingTreasureHuntersHouse_Text_271217: @ 8271217
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0f}RED SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}FIRE STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x06}YELLOW SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x73}THUNDERSTONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0c}BLUE SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x79}WATER STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x08}GREEN SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}LEAF STONE$"
