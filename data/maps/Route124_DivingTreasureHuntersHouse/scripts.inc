Route124_DivingTreasureHuntersHouse_MapScripts:: @ 8270A28
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_DivingTreasureHuntersHouse_OnTransition
	.byte 0

Route124_DivingTreasureHuntersHouse_OnTransition: @ 8270A2E
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
	end

Route124_DivingTreasureHuntersHouse_EventScript_TreasureHunter:: @ 8270A32
	lock
	faceplayer
	goto_if_set FLAG_MET_DIVING_TREASURE_HUNTER, Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting
	msgbox Route124_DivingTreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
	setflag FLAG_MET_DIVING_TREASURE_HUNTER
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
	end

Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting:: @ 8270A4E
	msgbox Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards, MSGBOX_DEFAULT
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
	end

Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard:: @ 8270A5C
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
	compare VAR_TEMP_1, 0
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_NoShards
	goto Route124_DivingTreasureHuntersHouse_EventScript_HasShard
	end

Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards:: @ 8270A72
	setvar VAR_TEMP_1, 0
	checkitem ITEM_RED_SHARD, 1
	compare VAR_RESULT, TRUE
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard
	checkitem ITEM_YELLOW_SHARD, 1
	compare VAR_RESULT, TRUE
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard
	checkitem ITEM_BLUE_SHARD, 1
	compare VAR_RESULT, TRUE
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard
	checkitem ITEM_GREEN_SHARD, 1
	compare VAR_RESULT, TRUE
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard:: @ 8270AB8
	addvar VAR_TEMP_1, 1
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard:: @ 8270ABE
	addvar VAR_TEMP_1, 2
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard:: @ 8270AC4
	addvar VAR_TEMP_1, 4
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard:: @ 8270ACA
	addvar VAR_TEMP_1, 8
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasShard:: @ 8270AD0
	msgbox Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou, MSGBOX_DEFAULT
	goto Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions:: @ 8270ADE
	message Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade
	waitmessage
	switch VAR_TEMP_1
	case 1,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR
	case 2,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY
	case 3,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY
	case 4,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB
	case 5,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB
	case 6,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB
	case 7,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB
	case 8,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG
	case 9,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG
	case 10, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG
	case 11, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG
	case 12, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG
	case 13, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG
	case 14, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG
	case 15, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR:: @ 8270B8F
	multichoice 0, 0, MULTI_SHARDS_R, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY:: @ 8270BB5
	multichoice 0, 0, MULTI_SHARDS_Y, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY:: @ 8270BDB
	multichoice 0, 0, MULTI_SHARDS_RY, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB:: @ 8270C0C
	multichoice 0, 0, MULTI_SHARDS_B, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB:: @ 8270C32
	multichoice 0, 0, MULTI_SHARDS_RB, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB:: @ 8270C63
	multichoice 0, 0, MULTI_SHARDS_YB, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB:: @ 8270C94
	multichoice 0, 0, MULTI_SHARDS_RYB, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG:: @ 8270CD0
	multichoice 0, 0, MULTI_SHARDS_G, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG:: @ 8270CF6
	multichoice 0, 0, MULTI_SHARDS_RG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG:: @ 8270D27
	multichoice 0, 0, MULTI_SHARDS_YG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG:: @ 8270D58
	multichoice 0, 0, MULTI_SHARDS_RYG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG:: @ 8270D94
	multichoice 0, 0, MULTI_SHARDS_BG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG:: @ 8270DC5
	multichoice 0, 0, MULTI_SHARDS_RBG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG:: @ 8270E01
	multichoice 0, 0, MULTI_SHARDS_YBG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG:: @ 8270E3D
	multichoice 0, 0, MULTI_SHARDS_RYBG, 0
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 4, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard:: @ 8270E84
	setvar VAR_0x8008, ITEM_RED_SHARD
	setvar VAR_0x8009, ITEM_FIRE_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard:: @ 8270E93
	setvar VAR_0x8008, ITEM_YELLOW_SHARD
	setvar VAR_0x8009, ITEM_THUNDER_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard:: @ 8270EA2
	setvar VAR_0x8008, ITEM_BLUE_SHARD
	setvar VAR_0x8009, ITEM_WATER_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard:: @ 8270EB1
	setvar VAR_0x8008, ITEM_GREEN_SHARD
	setvar VAR_0x8009, ITEM_LEAF_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard:: @ 8270EC0
	bufferitemname 0, VAR_0x8008
	bufferitemname 1, VAR_0x8009
	msgbox Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
	checkitem VAR_0x8008, 2
	compare VAR_RESULT, FALSE
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
	goto Route124_DivingTreasureHuntersHouse_EventScript_BagFull
	end

Route124_DivingTreasureHuntersHouse_EventScript_TradeShard:: @ 8270F01
	removeitem VAR_0x8008
	giveitem VAR_0x8009
	msgbox Route124_DivingTreasureHuntersHouse_Text_ItsADeal, MSGBOX_DEFAULT
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
	compare VAR_TEMP_1, 0
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_EndTrade
	msgbox Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_BagFull:: @ 8270F43
	msgbox Route124_DivingTreasureHuntersHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade:: @ 8270F4D
	msgbox Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_NoShards:: @ 8270F57
	msgbox Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_EndTrade:: @ 8270F61
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardTradeBoard:: @ 8270F63
	msgbox Route124_DivingTreasureHuntersHouse_Text_ShardTradeBoard, MSGBOX_SIGN
	end

Route124_DivingTreasureHuntersHouse_Text_Greeting: @ 8270F6C
	.string "I'm the DIVING TREASURE HUNTER!\p"
	.string "I'm the awesome dude who makes\n"
	.string "deep-sea dives to gather treasures\l"
	.string "resting at the bottom.$"

Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards: @ 8270FE5
	.string "Tell me, have you seen any SHARDS of\n"
	.string "tools made in ancient times?$"

Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards: @ 8271027
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any SHARDS, like the RED\n"
	.string "SHARD, you've got to trade it with me!$"

Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou: @ 8271098
	.string "Oh, hey! That…\n"
	.string "That's a SHARD! I'm looking for those!\p"
	.string "Oh, man, you've got to trade that\n"
	.string "with me! I'll give you something good!$"

Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade: @ 8271117
	.string "What do you want to trade?$"

Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone: @ 8271132
	.string "You'll trade your {STR_VAR_1} for\n"
	.string "my {STR_VAR_2}, then?$"

Route124_DivingTreasureHuntersHouse_Text_ItsADeal: @ 8271158
	.string "It's a done deal!\n"
	.string "Use that wisely!$"

Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse: @ 827117B
	.string "Do you want to trade something else?$"

Route124_DivingTreasureHuntersHouse_Text_BagFull: @ 82711A0
	.string "Whoops, your BAG's full.\n"
	.string "Get rid of some items, friend!$"

Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind: @ 82711D8
	.string "No? That's a downer.\n"
	.string "Well, if you change your mind, come back.$"

Route124_DivingTreasureHuntersHouse_Text_ShardTradeBoard: @ 8271217
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0f}RED SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}FIRE STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x06}YELLOW SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x73}THUNDERSTONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0c}BLUE SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x79}WATER STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x08}GREEN SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}LEAF STONE$"
