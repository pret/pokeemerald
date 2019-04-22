Route111_MapScripts:: @ 81F0CA7
	map_script MAP_SCRIPT_ON_LOAD, Route111_MapScript1_1F0CBC
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_MapScript2_1F0E46
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_MapScript2_1F0E56
	.byte 0

Route111_MapScript1_1F0CBC: @ 81F0CBC
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_1F0CD1
	compare VAR_ROUTE_111_STATE, 1
	call_if_eq Route111_EventScript_1F0CE4
	end

Route111_EventScript_1F0CD1:: @ 81F0CD1
	setmetatile 29, 86, 124, 1
	setmetatile 29, 87, 145, 1
	return

Route111_EventScript_1F0CE4:: @ 81F0CE4
	setmetatile 18, 53, 984, 0
	setmetatile 19, 53, 985, 0
	setmetatile 20, 53, 986, 0
	setmetatile 18, 54, 992, 0
	setmetatile 19, 54, 993, 0
	setmetatile 20, 54, 994, 0
	setmetatile 18, 55, 1000, 0
	setmetatile 19, 55, 1001, 0
	setmetatile 20, 55, 1002, 0
	setmetatile 18, 56, 1008, 0
	setmetatile 19, 56, 1009, 0
	setmetatile 20, 56, 1010, 0
	setmetatile 18, 57, 987, 0
	setmetatile 19, 57, 988, 0
	setmetatile 20, 57, 989, 0
	setmetatile 18, 58, 995, 0
	setmetatile 19, 58, 996, 0
	setmetatile 20, 58, 997, 0
	return

Route111_OnTransition: @ 81F0D87
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special SetMirageTowerVisibility
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_1F0E3C
	compare VAR_ROUTE_111_STATE, 1
	call_if_eq Route111_EventScript_1F0DC2
	compare VAR_ROUTE_111_STATE, 2
	call_if_eq Route111_EventScript_1F0E40
	call Route111_EventScript_1F0DE6
	call Route111_EventScript_28CCC7
	checktrainerflag TRAINER_VICKY
	goto_if_lt Route111_EventScript_1F0E26
	end

Route111_EventScript_1F0DC2:: @ 81F0DC2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route111_EventScript_1F0DDA
	compare VAR_RESULT, FEMALE
	goto_if_eq Route111_EventScript_1F0DE0
	return

Route111_EventScript_1F0DDA:: @ 81F0DDA
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

Route111_EventScript_1F0DE0:: @ 81F0DE0
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

Route111_EventScript_1F0DE6:: @ 81F0DE6
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 34
	goto_if_lt Route111_EventScript_1F0E25
	compare VAR_TEMP_1, 107
	goto_if_gt Route111_EventScript_1F0E25
	compare VAR_TEMP_1, 72
	goto_if_gt Route111_EventScript_1F0E22
	compare VAR_TEMP_0, 2000
	goto_if_gt Route111_EventScript_1F0E25
	compare VAR_TEMP_0, 8
	goto_if_lt Route111_EventScript_1F0E25

Route111_EventScript_1F0E22:: @ 81F0E22
	setweather WEATHER_SANDSTORM

Route111_EventScript_1F0E25:: @ 81F0E25
	return

Route111_EventScript_1F0E26:: @ 81F0E26
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_1F0E3C:: @ 81F0E3C
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
	return

Route111_EventScript_1F0E40:: @ 81F0E40
	setvar VAR_ROUTE_111_STATE, 3
	return

Route111_MapScript2_1F0E46: @ 81F0E46
	map_script_2 VAR_ROUTE_111_STATE, 1, Route111_EventScript_1F0E50
	.2byte 0

Route111_EventScript_1F0E50:: @ 81F0E50
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_LITTLEROOT_TOWN
	end

Route111_MapScript2_1F0E56: @ 81F0E56
	map_script_2 VAR_ROUTE_111_STATE, 1, Route111_EventScript_1F0E60
	.2byte 0

Route111_EventScript_1F0E60:: @ 81F0E60
	lockall
	special StartMirageTowerShake
	waitstate
	delay 24
	playse SE_RU_HYUU
	addobject 45
	special StartPlayerDescendMirageTower
	waitstate
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_LITTLEROOT_TOWN
	removeobject 45
	delay 16
	turnobject EVENT_OBJ_ID_PLAYER, 2
	delay 16
	special StartMirageTowerDisintegration
	waitstate
	special StartMirageTowerFossilFallAndSink
	waitstate
	setvar VAR_ROUTE_111_STATE, 2
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, Route111_EventScript_1F0EA7
	msgbox Route111_Text_1F1C74, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_1F0EA7:: @ 81F0EA7
	msgbox Route111_Text_1F1C9F, MSGBOX_DEFAULT
	releaseall
	end

Route111_Movement_1F0EB1:: @ 81F0EB1
	store_lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_1F0EB9:: @ 81F0EB9
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_1F0EF4
	msgbox Route111_Text_2A6EBD, MSGBOX_DEFAULT
	giveitem_std ITEM_RAZZ_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_2A6F3D, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F0EF4:: @ 81F0EF4
	msgbox Route111_Text_2A6F9A, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F0EFE:: @ 81F0EFE
	lockall
	setvar VAR_0x8004, 0
	goto Route111_EventScript_1F0F2E
	end

Route111_EventScript_1F0F0A:: @ 81F0F0A
	lockall
	setvar VAR_0x8004, 1
	goto Route111_EventScript_1F0F2E
	end

Route111_EventScript_1F0F16:: @ 81F0F16
	lockall
	setvar VAR_0x8004, 2
	goto Route111_EventScript_1F0F2E
	end

Route111_EventScript_1F0F22:: @ 81F0F22
	lockall
	setvar VAR_0x8004, 3
	goto Route111_EventScript_1F0F2E
	end

Route111_EventScript_1F0F2E:: @ 81F0F2E
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, 0
	goto_if_eq Route111_EventScript_1F0F45
	setvar VAR_TEMP_3, 1
	releaseall
	end

Route111_EventScript_1F0F45:: @ 81F0F45
	msgbox gUnknown_08272C5F, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8004, 0
	call_if_eq Route111_EventScript_1F0F7C
	compare VAR_0x8004, 1
	call_if_eq Route111_EventScript_1F0F87
	compare VAR_0x8004, 2
	call_if_eq Route111_EventScript_1F0F92
	compare VAR_0x8004, 3
	call_if_eq Route111_EventScript_1F0F9D
	releaseall
	end

Route111_EventScript_1F0F7C:: @ 81F0F7C
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F0FA8
	waitmovement 0
	return

Route111_EventScript_1F0F87:: @ 81F0F87
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F0FAA
	waitmovement 0
	return

Route111_EventScript_1F0F92:: @ 81F0F92
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F0FAC
	waitmovement 0
	return

Route111_EventScript_1F0F9D:: @ 81F0F9D
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F0FAE
	waitmovement 0
	return

Route111_Movement_1F0FA8: @ 81F0FA8
	walk_up
	step_end

Route111_Movement_1F0FAA: @ 81F0FAA
	walk_down
	step_end

Route111_Movement_1F0FAC: @ 81F0FAC
	walk_left
	step_end

Route111_Movement_1F0FAE: @ 81F0FAE
	walk_right
	step_end

Route111_EventScript_1F0FB0:: @ 81F0FB0
	setweather WEATHER_SUNNY
	fadenewbgm MUS_DOORO_X1
	doweather
	setvar VAR_TEMP_3, 0
	end

Route111_EventScript_1F0FBD:: @ 81F0FBD
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_ASHROAD
	doweather
	end

Route111_EventScript_1F0FC5:: @ 81F0FC5
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_1F1475, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_1F0FE7
	msgbox Route111_Text_1F14F5, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F0FE7:: @ 81F0FE7
	msgbox Route111_Text_1F1523, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_1F1542
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	call Route111_EventScript_1F113C
	msgbox Route111_Text_1F156F, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Route111_Movement_1F114A
	waitmovement 0
	removeobject 1
	call Route111_EventScript_1F1143
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F114F
	waitmovement 0
	call Route111_EventScript_1F113C
	addobject 2
	applymovement 2, Route111_Movement_1F114D
	waitmovement 0
	call Route111_EventScript_1F1143
	msgbox Route111_Text_1F159D, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_1F1616
	applymovement 2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	call Route111_EventScript_1F113C
	msgbox Route111_Text_1F1645, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Route111_Movement_1F114A
	waitmovement 0
	removeobject 2
	call Route111_EventScript_1F1143
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F114F
	waitmovement 0
	call Route111_EventScript_1F113C
	addobject 3
	applymovement 3, Route111_Movement_1F114D
	waitmovement 0
	call Route111_EventScript_1F1143
	msgbox Route111_Text_1F167E, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_1F16C6
	applymovement 3, Common_Movement_WalkInPlaceUp
	waitmovement 0
	call Route111_EventScript_1F113C
	msgbox Route111_Text_1F16DC, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Route111_Movement_1F114A
	waitmovement 0
	removeobject 3
	call Route111_EventScript_1F1143
	applymovement EVENT_OBJ_ID_PLAYER, Route111_Movement_1F114F
	waitmovement 0
	call Route111_EventScript_1F113C
	addobject 4
	applymovement 4, Route111_Movement_1F114D
	waitmovement 0
	call Route111_EventScript_1F1143
	msgbox Route111_Text_1F16FB, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_1F1756
	msgbox Route111_Text_1F1788, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	call Route111_EventScript_1F113C
	applymovement 4, Route111_Movement_1F114A
	waitmovement 0
	removeobject 4
	call Route111_EventScript_1F1143
	release
	end

Route111_EventScript_1F113C:: @ 81F113C
	opendoor 13, 113
	waitdooranim
	return

Route111_EventScript_1F1143:: @ 81F1143
	closedoor 13, 113
	waitdooranim
	return

Route111_Movement_1F114A: @ 81F114A
	walk_in_place_fastest_up
	walk_up
	step_end

Route111_Movement_1F114D: @ 81F114D
	walk_down
	step_end

Route111_Movement_1F114F: @ 81F114F
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_1F1153:: @ 81F1153
	msgbox Route111_Text_1F18CE, MSGBOX_SIGN
	end

Route111_EventScript_1F115C:: @ 81F115C
	msgbox Route111_Text_1F18E8, MSGBOX_SIGN
	end

Route111_EventScript_1F1165:: @ 81F1165
	msgbox Route111_Text_1F1921, MSGBOX_SIGN
	end

Route111_EventScript_1F116E:: @ 81F116E
	msgbox Route111_Text_1F1937, MSGBOX_SIGN
	end

Route111_EventScript_1F1177:: @ 81F1177
	msgbox Route111_Text_1F194D, MSGBOX_SIGN
	end

Route111_EventScript_1F1180:: @ 81F1180
	msgbox Route111_Text_1F1987, MSGBOX_SIGN
	end

Route111_EventScript_1F1189:: @ 81F1189
	msgbox Route111_Text_1F17BA, MSGBOX_NPC
	end

Route111_EventScript_1F1192:: @ 81F1192
	msgbox Route111_Text_1F186E, MSGBOX_NPC
	end

Route111_EventScript_1F119B:: @ 81F119B
	lock
	faceplayer
	compare VAR_ROUTE_111_STATE, 3
	goto_if_eq Route111_EventScript_1F11C6
	compare VAR_ROUTE_111_STATE, 2
	goto_if_eq Route111_EventScript_1F11D0
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_1F11DA
	msgbox Route111_Text_1F1A22, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F11C6:: @ 81F11C6
	msgbox Route111_Text_1F1C12, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F11D0:: @ 81F11D0
	msgbox Route111_Text_1F1B92, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F11DA:: @ 81F11DA
	msgbox Route111_Text_1F1AC7, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F11E4:: @ 81F11E4
	lockall
	applymovement 46, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_1F1CCA, MSGBOX_DEFAULT
	closemessage
	applymovement 46, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route111_EventScript_1F1204:: @ 81F1204
	trainerbattle_single TRAINER_DREW, Route111_Text_29878E, Route111_Text_29880A
	msgbox Route111_Text_298853, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F121B:: @ 81F121B
	trainerbattle_single TRAINER_HEIDI, Route111_Text_2988A3, Route111_Text_298908
	msgbox Route111_Text_29891B, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1232:: @ 81F1232
	trainerbattle_single TRAINER_BEAU, Route111_Text_29898E, Route111_Text_2989E6
	msgbox Route111_Text_298A03, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1249:: @ 81F1249
	trainerbattle_single TRAINER_BECKY, Route111_Text_298A65, Route111_Text_298AAF
	msgbox Route111_Text_298AC0, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1260:: @ 81F1260
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_298B08, Route111_Text_298B53, Route111_EventScript_1F128C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_1F12AB
	msgbox Route111_Text_298B9A, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F128C:: @ 81F128C
	special sub_80B4808
	waitmovement 0
	msgbox Route111_Text_298C00, MSGBOX_DEFAULT
	register_matchcall TRAINER_DUSTY_1
	release
	end

Route111_EventScript_1F12AB:: @ 81F12AB
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_298C5F, Route111_Text_298CD2
	msgbox Route111_Text_298D0C, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F12C2:: @ 81F12C2
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_298DA9, Route111_Text_298DD8
	msgbox Route111_Text_298DF1, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F12D9:: @ 81F12D9
	trainerbattle_single TRAINER_IRENE, Route111_Text_298E2F, Route111_Text_298E6E
	msgbox Route111_Text_298E8C, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F12F0:: @ 81F12F0
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_298EE6, Route111_Text_298F14
	msgbox Route111_Text_298F26, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1307:: @ 81F1307
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_298F79, Route111_Text_298FA9, Route111_EventScript_1F1333
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_1F1352
	msgbox Route111_Text_298FD4, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F1333:: @ 81F1333
	special sub_80B4808
	waitmovement 0
	msgbox Route111_Text_29903D, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_1
	release
	end

Route111_EventScript_1F1352:: @ 81F1352
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_29909B, Route111_Text_2990EE
	msgbox Route111_Text_299102, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1369:: @ 81F1369
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_299143, Route111_Text_299193, Route111_EventScript_1F1395
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_1F13B4
	msgbox Route111_Text_2991C2, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_1F1395:: @ 81F1395
	special sub_80B4808
	waitmovement 0
	msgbox Route111_Text_29921D, MSGBOX_DEFAULT
	register_matchcall TRAINER_BROOKE_1
	release
	end

Route111_EventScript_1F13B4:: @ 81F13B4
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_29925D, Route111_Text_2992D6
	msgbox Route111_Text_2992F5, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F13CB:: @ 81F13CB
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_299682, Route111_Text_2996BE
	msgbox Route111_Text_2996C5, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F13E2:: @ 81F13E2
	trainerbattle_single TRAINER_BIANCA, Route111_Text_2996FE, Route111_Text_29973D
	msgbox Route111_Text_29975D, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F13F9:: @ 81F13F9
	trainerbattle_single TRAINER_TYRON, Route111_Text_299524, Route111_Text_299549
	msgbox Route111_Text_299576, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1410:: @ 81F1410
	trainerbattle_single TRAINER_CELINA, Route111_Text_2995F0, Route111_Text_299625
	msgbox Route111_Text_29964B, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1427:: @ 81F1427
	trainerbattle_single TRAINER_CELIA, Route111_Text_29934B, Route111_Text_299384
	msgbox Route111_Text_2993A7, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F143E:: @ 81F143E
	trainerbattle_single TRAINER_BRYAN, Route111_Text_299401, Route111_Text_299431
	msgbox Route111_Text_29945F, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F1455:: @ 81F1455
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_299493, Route111_Text_2994C5
	msgbox Route111_Text_2994FB, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_1F146C:: @ 81F146C
	msgbox Route111_Text_1F1D61, MSGBOX_SIGN
	end

Route111_Text_1F1475: @ 81F1475
	.string "Hello! I take it you're a traveler.\p"
	.string "How's this? What do you say to taking\n"
	.string "on our family of four in a series of\l"
	.string "POKéMON battles?$"

Route111_Text_1F14F5: @ 81F14F5
	.string "Is that so?\n"
	.string "Drop in, if you change your mind!$"

Route111_Text_1F1523: @ 81F1523
	.string "That's the spirit! I like you!$"

Route111_Text_1F1542: @ 81F1542
	.string "Aiyah!\n"
	.string "You're a lot tougher than I expected!$"

Route111_Text_1F156F: @ 81F156F
	.string "Hey, all!\n"
	.string "I've found a pretty strong TRAINER!$"

Route111_Text_1F159D: @ 81F159D
	.string "Oh, my goodness! Aren't you young?\p"
	.string "You must be quite the TRAINER to beat\n"
	.string "my husband, though.\p"
	.string "It's my turn to battle now!$"

Route111_Text_1F1616: @ 81F1616
	.string "Oh, gosh!\n"
	.string "I can't get over how strong you are!$"

Route111_Text_1F1645: @ 81F1645
	.string "There's a strong TRAINER here!\n"
	.string "This one's really strong!$"

Route111_Text_1F167E: @ 81F167E
	.string "You're stronger than Mommy? Wow!\p"
	.string "But I'm strong, too!\n"
	.string "Really! Honestly!$"

Route111_Text_1F16C6: @ 81F16C6
	.string "Huh? Did I just lose?$"

Route111_Text_1F16DC: @ 81F16DC
	.string "This stinks…\p"
	.string "…Snivel… Grandma!$"

Route111_Text_1F16FB: @ 81F16FB
	.string "How dare you make my granddaughter\n"
	.string "cry!\p"
	.string "For that, I'm going to smack you!\n"
	.string "Prepare to lose!$"

Route111_Text_1F1756: @ 81F1756
	.string "Kwah! You are strong…\n"
	.string "My granddaughter was right…$"

Route111_Text_1F1788: @ 81F1788
	.string "If you're not in any hurry,\n"
	.string "visit with us awhile.$"

Route111_Text_1F17BA: @ 81F17BA
	.string "If you don't raise your POKéMON some\n"
	.string "more, it could be tough to keep winning\l"
	.string "up through the ranks.\p"
	.string "I've heard the POKéMON LEAGUE's\n"
	.string "ELITE FOUR are far stronger than\l"
	.string "any GYM LEADER.$"

Route111_Text_1F186E: @ 81F186E
	.string "I challenged the WINSTRATE family,\n"
	.string "but four matches in a row is tough\l"
	.string "going… They destroyed me.$"

Route111_Text_1F18CE: @ 81F18CE
	.string "ROUTE 111\n"
	.string "{DOWN_ARROW} MAUVILLE CITY$"

Route111_Text_1F18E8: @ 81F18E8
	.string "“Our family's hearts beat as one!”\n"
	.string "THE WINSTRATE'S HOUSE$"

Route111_Text_1F1921: @ 81F1921
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 112$"

Route111_Text_1F1937: @ 81F1937
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 113$"

Route111_Text_1F194D: @ 81F194D
	.string "OLD LADY'S REST STOP\n"
	.string "“Come in and rest your tired bones.”$"

Route111_Text_1F1987: @ 81F1987
	.string "TRAINER TIPS\p"
	.string "One of the indicators of a POKéMON's\n"
	.string "powerfulness is SP. ATK. It stands for\l"
	.string "“SPECIAL ATTACK.”\p"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
	.string "DEFENSE.”$"

Route111_Text_1F1A22: @ 81F1A22
	.string "There should be a tower made of sand\n"
	.string "around here somewhere.\p"
	.string "But for some reason, it can be seen\n"
	.string "sometimes, and sometimes not.\p"
	.string "That's why I call it the MIRAGE TOWER.$"

Route111_Text_1F1AC7: @ 81F1AC7
	.string "I see it!\n"
	.string "The tower of sand!\p"
	.string "The sand tower they called a mirage\n"
	.string "is clearly visible!\p"
	.string "But it looks so fragile…\n"
	.string "It could crumble away anytime…\p"
	.string "I want to go inside it, but I can't\n"
	.string "get my courage up for it…$"

Route111_Text_1F1B92: @ 81F1B92
	.string "Whoa…\n"
	.string "That was shocking.\p"
	.string "Sand rained down in chunks all of\n"
	.string "a sudden.\p"
	.string "What was it like inside?\n"
	.string "Were there sandy ghosts and such?$"

Route111_Text_1F1C12: @ 81F1C12
	.string "Since I spoke to you, the tower of sand\n"
	.string "hasn't been seen.\p"
	.string "Perhaps it really was\n"
	.string "the MIRAGE TOWER…$"

Route111_Text_1F1C74: @ 81F1C74
	.string "The CLAW FOSSIL disappeared into\n"
	.string "the sand…$"

Route111_Text_1F1C9F: @ 81F1C9F
	.string "The ROOT FOSSIL disappeared into\n"
	.string "the sand…$"

Route111_Text_1F1CCA: @ 81F1CCA
	.string "Oh, no!\p"
	.string "My uncle in MAUVILLE told me to take\n"
	.string "ROCK SMASH with me if I was going to\l"
	.string "ROUTE 111!\p"
	.string "My uncle? He lives across from\n"
	.string "the bike shop in MAUVILLE.$"

Route111_Text_1F1D61: @ 81F1D61
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
	.string "“Scale the heights, you hot-blooded\n"
	.string "TRAINERS!”$"

