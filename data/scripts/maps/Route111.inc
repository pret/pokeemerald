Route111_MapScripts:: @ 81F0CA7
	map_script 1, Route111_MapScript1_1F0CBC
	map_script 3, Route111_MapScript1_1F0D87
	map_script 4, Route111_MapScript2_1F0E46
	map_script 2, Route111_MapScript2_1F0E56
	.byte 0

Route111_MapScript1_1F0CBC: @ 81F0CBC
	checkflag FLAG_0x0E4
	call_if 0, Route111_EventScript_1F0CD1
	compare VAR_0x40CB, 1
	call_if 1, Route111_EventScript_1F0CE4
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

Route111_MapScript1_1F0D87: @ 81F0D87
	setvar VAR_0x40D6, 0
	special sub_81BE79C
	checkflag FLAG_0x14E
	call_if 0, Route111_EventScript_1F0E3C
	compare VAR_0x40CB, 1
	call_if 1, Route111_EventScript_1F0DC2
	compare VAR_0x40CB, 2
	call_if 1, Route111_EventScript_1F0E40
	call Route111_EventScript_1F0DE6
	call Route111_EventScript_28CCC7
	checktrainerflag TRAINER_VICKY
	goto_if 0, Route111_EventScript_1F0E26
	end

Route111_EventScript_1F0DC2:: @ 81F0DC2
	checkplayergender
	compare VAR_RESULT, 0
	goto_eq Route111_EventScript_1F0DDA
	compare VAR_RESULT, 1
	goto_eq Route111_EventScript_1F0DE0
	return

Route111_EventScript_1F0DDA:: @ 81F0DDA
	setvar VAR_0x4010, 100
	return

Route111_EventScript_1F0DE0:: @ 81F0DE0
	setvar VAR_0x4010, 105
	return

Route111_EventScript_1F0DE6:: @ 81F0DE6
	getplayerxy VAR_0x4000, VAR_0x4001
	compare VAR_0x4001, 34
	goto_if 0, Route111_EventScript_1F0E25
	compare VAR_0x4001, 107
	goto_if 2, Route111_EventScript_1F0E25
	compare VAR_0x4001, 72
	goto_if 2, Route111_EventScript_1F0E22
	compare VAR_0x4000, 2000
	goto_if 2, Route111_EventScript_1F0E25
	compare VAR_0x4000, 8
	goto_if 0, Route111_EventScript_1F0E25

Route111_EventScript_1F0E22:: @ 81F0E22
	setweather 8

Route111_EventScript_1F0E25:: @ 81F0E25
	return

Route111_EventScript_1F0E26:: @ 81F0E26
	clearflag FLAG_0x300
	setflag FLAG_0x301
	setflag FLAG_0x302
	setflag FLAG_0x303
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_1F0E3C:: @ 81F0E3C
	setmaplayoutindex 392
	return

Route111_EventScript_1F0E40:: @ 81F0E40
	setvar VAR_0x40CB, 3
	return

Route111_MapScript2_1F0E46: @ 81F0E46
	map_script_2 VAR_0x40CB, 1, Route111_EventScript_1F0E50
	.2byte 0

Route111_EventScript_1F0E50:: @ 81F0E50
	hideobjectat 255, LITTLEROOT_TOWN
	end

Route111_MapScript2_1F0E56: @ 81F0E56
	map_script_2 VAR_0x40CB, 1, Route111_EventScript_1F0E60
	.2byte 0

Route111_EventScript_1F0E60:: @ 81F0E60
	lockall
	special sub_81BEB68
	waitstate
	delay 24
	playse SE_RU_HYUU
	addobject 45
	special sub_81BE7F4
	waitstate
	showobjectat 255, LITTLEROOT_TOWN
	removeobject 45
	delay 16
	turnobject 255, 2
	delay 16
	special sub_81BEB54
	waitstate
	special sub_81BEB7C
	waitstate
	setvar VAR_0x40CB, 2
	clearflag FLAG_0x36A
	checkflag FLAG_0x150
	goto_eq Route111_EventScript_1F0EA7
	msgbox Route111_Text_1F1C74, 4
	releaseall
	end

Route111_EventScript_1F0EA7:: @ 81F0EA7
	msgbox Route111_Text_1F1C9F, 4
	releaseall
	end

Route111_Movement_1F0EB1:: @ 81F0EB1
	step_94
	step_15
	step_15
	step_15
	step_15
	step_15
	step_15
	step_end

Route111_EventScript_1F0EB9:: @ 81F0EB9
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_0x92C
	goto_eq Route111_EventScript_1F0EF4
	msgbox Route111_Text_2A6EBD, 4
	giveitem_std ITEM_RAZZ_BERRY
	compare VAR_RESULT, 0
	goto_eq Route111_EventScript_272054
	setflag FLAG_0x92C
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_2A6F3D, 4
	release
	end

Route111_EventScript_1F0EF4:: @ 81F0EF4
	msgbox Route111_Text_2A6F9A, 4
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
	goto_eq Route111_EventScript_1F0F45
	setvar VAR_0x4003, 1
	releaseall
	end

Route111_EventScript_1F0F45:: @ 81F0F45
	msgbox gUnknown_08272C5F, 4
	closemessage
	compare VAR_0x8004, 0
	call_if 1, Route111_EventScript_1F0F7C
	compare VAR_0x8004, 1
	call_if 1, Route111_EventScript_1F0F87
	compare VAR_0x8004, 2
	call_if 1, Route111_EventScript_1F0F92
	compare VAR_0x8004, 3
	call_if 1, Route111_EventScript_1F0F9D
	releaseall
	end

Route111_EventScript_1F0F7C:: @ 81F0F7C
	applymovement 255, Route111_Movement_1F0FA8
	waitmovement 0
	return

Route111_EventScript_1F0F87:: @ 81F0F87
	applymovement 255, Route111_Movement_1F0FAA
	waitmovement 0
	return

Route111_EventScript_1F0F92:: @ 81F0F92
	applymovement 255, Route111_Movement_1F0FAC
	waitmovement 0
	return

Route111_EventScript_1F0F9D:: @ 81F0F9D
	applymovement 255, Route111_Movement_1F0FAE
	waitmovement 0
	return

Route111_Movement_1F0FA8: @ 81F0FA8
	step_up
	step_end

Route111_Movement_1F0FAA: @ 81F0FAA
	step_down
	step_end

Route111_Movement_1F0FAC: @ 81F0FAC
	step_left
	step_end

Route111_Movement_1F0FAE: @ 81F0FAE
	step_right
	step_end

Route111_EventScript_1F0FB0:: @ 81F0FB0
	setweather 2
	fadenewbgm MUS_DOORO_X1
	doweather
	setvar VAR_0x4003, 0
	end

Route111_EventScript_1F0FBD:: @ 81F0FBD
	setweather 8
	fadenewbgm MUS_ASHROAD
	doweather
	end

Route111_EventScript_1F0FC5:: @ 81F0FC5
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_1F1475, 5
	compare VAR_RESULT, 1
	goto_eq Route111_EventScript_1F0FE7
	msgbox Route111_Text_1F14F5, 4
	release
	end

Route111_EventScript_1F0FE7:: @ 81F0FE7
	msgbox Route111_Text_1F1523, 4
	trainerbattle 3, TRAINER_VICTOR, 0, Route111_Text_1F1542
	applymovement 1, Route111_Movement_2725A6
	waitmovement 0
	call Route111_EventScript_1F113C
	msgbox Route111_Text_1F156F, 4
	closemessage
	applymovement 1, Route111_Movement_1F114A
	waitmovement 0
	removeobject 1
	call Route111_EventScript_1F1143
	applymovement 255, Route111_Movement_1F114F
	waitmovement 0
	call Route111_EventScript_1F113C
	addobject 2
	applymovement 2, Route111_Movement_1F114D
	waitmovement 0
	call Route111_EventScript_1F1143
	msgbox Route111_Text_1F159D, 4
	trainerbattle 3, TRAINER_VICTORIA, 0, Route111_Text_1F1616
	applymovement 2, Route111_Movement_2725A6
	waitmovement 0
	call Route111_EventScript_1F113C
	msgbox Route111_Text_1F1645, 4
	closemessage
	applymovement 2, Route111_Movement_1F114A
	waitmovement 0
	removeobject 2
	call Route111_EventScript_1F1143
	applymovement 255, Route111_Movement_1F114F
	waitmovement 0
	call Route111_EventScript_1F113C
	addobject 3
	applymovement 3, Route111_Movement_1F114D
	waitmovement 0
	call Route111_EventScript_1F1143
	msgbox Route111_Text_1F167E, 4
	trainerbattle 3, TRAINER_VIVI, 0, Route111_Text_1F16C6
	applymovement 3, Route111_Movement_2725A6
	waitmovement 0
	call Route111_EventScript_1F113C
	msgbox Route111_Text_1F16DC, 4
	closemessage
	applymovement 3, Route111_Movement_1F114A
	waitmovement 0
	removeobject 3
	call Route111_EventScript_1F1143
	applymovement 255, Route111_Movement_1F114F
	waitmovement 0
	call Route111_EventScript_1F113C
	addobject 4
	applymovement 4, Route111_Movement_1F114D
	waitmovement 0
	call Route111_EventScript_1F1143
	msgbox Route111_Text_1F16FB, 4
	trainerbattle 3, TRAINER_VICKY, 0, Route111_Text_1F1756
	msgbox Route111_Text_1F1788, 4
	closemessage
	applymovement 4, Route111_Movement_2725A6
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
	step_26
	step_up
	step_end

Route111_Movement_1F114D: @ 81F114D
	step_down
	step_end

Route111_Movement_1F114F: @ 81F114F
	step_14
	step_14
	step_14
	step_end

Route111_EventScript_1F1153:: @ 81F1153
	msgbox Route111_Text_1F18CE, 3
	end

Route111_EventScript_1F115C:: @ 81F115C
	msgbox Route111_Text_1F18E8, 3
	end

Route111_EventScript_1F1165:: @ 81F1165
	msgbox Route111_Text_1F1921, 3
	end

Route111_EventScript_1F116E:: @ 81F116E
	msgbox Route111_Text_1F1937, 3
	end

Route111_EventScript_1F1177:: @ 81F1177
	msgbox Route111_Text_1F194D, 3
	end

Route111_EventScript_1F1180:: @ 81F1180
	msgbox Route111_Text_1F1987, 3
	end

Route111_EventScript_1F1189:: @ 81F1189
	msgbox Route111_Text_1F17BA, 2
	end

Route111_EventScript_1F1192:: @ 81F1192
	msgbox Route111_Text_1F186E, 2
	end

Route111_EventScript_1F119B:: @ 81F119B
	lock
	faceplayer
	compare VAR_0x40CB, 3
	goto_eq Route111_EventScript_1F11C6
	compare VAR_0x40CB, 2
	goto_eq Route111_EventScript_1F11D0
	checkflag FLAG_0x14E
	goto_eq Route111_EventScript_1F11DA
	msgbox Route111_Text_1F1A22, 4
	release
	end

Route111_EventScript_1F11C6:: @ 81F11C6
	msgbox Route111_Text_1F1C12, 4
	release
	end

Route111_EventScript_1F11D0:: @ 81F11D0
	msgbox Route111_Text_1F1B92, 4
	release
	end

Route111_EventScript_1F11DA:: @ 81F11DA
	msgbox Route111_Text_1F1AC7, 4
	release
	end

Route111_EventScript_1F11E4:: @ 81F11E4
	lockall
	applymovement 46, Route111_Movement_27259E
	waitmovement 0
	msgbox Route111_Text_1F1CCA, 4
	closemessage
	applymovement 46, Route111_Movement_2725A2
	waitmovement 0
	releaseall
	end

Route111_EventScript_1F1204:: @ 81F1204
	trainerbattle 0, TRAINER_DREW, 0, Route111_Text_29878E, Route111_Text_29880A
	msgbox Route111_Text_298853, 6
	end

Route111_EventScript_1F121B:: @ 81F121B
	trainerbattle 0, TRAINER_HEIDI, 0, Route111_Text_2988A3, Route111_Text_298908
	msgbox Route111_Text_29891B, 6
	end

Route111_EventScript_1F1232:: @ 81F1232
	trainerbattle 0, TRAINER_BEAU, 0, Route111_Text_29898E, Route111_Text_2989E6
	msgbox Route111_Text_298A03, 6
	end

Route111_EventScript_1F1249:: @ 81F1249
	trainerbattle 0, TRAINER_BECKY, 0, Route111_Text_298A65, Route111_Text_298AAF
	msgbox Route111_Text_298AC0, 6
	end

Route111_EventScript_1F1260:: @ 81F1260
	trainerbattle 2, TRAINER_DUSTY_1, 0, Route111_Text_298B08, Route111_Text_298B53, Route111_EventScript_1F128C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route111_EventScript_1F12AB
	msgbox Route111_Text_298B9A, 4
	release
	end

Route111_EventScript_1F128C:: @ 81F128C
	special sub_80B4808
	waitmovement 0
	msgbox Route111_Text_298C00, 4
	setvar VAR_0x8004, 44
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 44
	callstd 8
	release
	end

Route111_EventScript_1F12AB:: @ 81F12AB
	trainerbattle 5, TRAINER_DUSTY_1, 0, Route111_Text_298C5F, Route111_Text_298CD2
	msgbox Route111_Text_298D0C, 6
	end

Route111_EventScript_1F12C2:: @ 81F12C2
	trainerbattle 0, TRAINER_TRAVIS, 0, Route111_Text_298DA9, Route111_Text_298DD8
	msgbox Route111_Text_298DF1, 6
	end

Route111_EventScript_1F12D9:: @ 81F12D9
	trainerbattle 0, TRAINER_IRENE, 0, Route111_Text_298E2F, Route111_Text_298E6E
	msgbox Route111_Text_298E8C, 6
	end

Route111_EventScript_1F12F0:: @ 81F12F0
	trainerbattle 0, TRAINER_DAISUKE, 0, Route111_Text_298EE6, Route111_Text_298F14
	msgbox Route111_Text_298F26, 6
	end

Route111_EventScript_1F1307:: @ 81F1307
	trainerbattle 2, TRAINER_WILTON_1, 0, Route111_Text_298F79, Route111_Text_298FA9, Route111_EventScript_1F1333
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route111_EventScript_1F1352
	msgbox Route111_Text_298FD4, 4
	release
	end

Route111_EventScript_1F1333:: @ 81F1333
	special sub_80B4808
	waitmovement 0
	msgbox Route111_Text_29903D, 4
	setvar VAR_0x8004, 78
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 78
	callstd 8
	release
	end

Route111_EventScript_1F1352:: @ 81F1352
	trainerbattle 5, TRAINER_WILTON_1, 0, Route111_Text_29909B, Route111_Text_2990EE
	msgbox Route111_Text_299102, 6
	end

Route111_EventScript_1F1369:: @ 81F1369
	trainerbattle 2, TRAINER_BROOKE_1, 0, Route111_Text_299143, Route111_Text_299193, Route111_EventScript_1F1395
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq Route111_EventScript_1F13B4
	msgbox Route111_Text_2991C2, 4
	release
	end

Route111_EventScript_1F1395:: @ 81F1395
	special sub_80B4808
	waitmovement 0
	msgbox Route111_Text_29921D, 4
	setvar VAR_0x8004, 94
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 94
	callstd 8
	release
	end

Route111_EventScript_1F13B4:: @ 81F13B4
	trainerbattle 5, TRAINER_BROOKE_1, 0, Route111_Text_29925D, Route111_Text_2992D6
	msgbox Route111_Text_2992F5, 6
	end

Route111_EventScript_1F13CB:: @ 81F13CB
	trainerbattle 0, TRAINER_HAYDEN, 0, Route111_Text_299682, Route111_Text_2996BE
	msgbox Route111_Text_2996C5, 6
	end

Route111_EventScript_1F13E2:: @ 81F13E2
	trainerbattle 0, TRAINER_BIANCA, 0, Route111_Text_2996FE, Route111_Text_29973D
	msgbox Route111_Text_29975D, 6
	end

Route111_EventScript_1F13F9:: @ 81F13F9
	trainerbattle 0, TRAINER_TYRON, 0, Route111_Text_299524, Route111_Text_299549
	msgbox Route111_Text_299576, 6
	end

Route111_EventScript_1F1410:: @ 81F1410
	trainerbattle 0, TRAINER_CELINA, 0, Route111_Text_2995F0, Route111_Text_299625
	msgbox Route111_Text_29964B, 6
	end

Route111_EventScript_1F1427:: @ 81F1427
	trainerbattle 0, TRAINER_CELIA, 0, Route111_Text_29934B, Route111_Text_299384
	msgbox Route111_Text_2993A7, 6
	end

Route111_EventScript_1F143E:: @ 81F143E
	trainerbattle 0, TRAINER_BRYAN, 0, Route111_Text_299401, Route111_Text_299431
	msgbox Route111_Text_29945F, 6
	end

Route111_EventScript_1F1455:: @ 81F1455
	trainerbattle 0, TRAINER_BRANDEN, 0, Route111_Text_299493, Route111_Text_2994C5
	msgbox Route111_Text_2994FB, 6
	end

Route111_EventScript_1F146C:: @ 81F146C
	msgbox Route111_Text_1F1D61, 3
	end

Route111_Text_1F1475: @ 81F1475
	.string "Hello! I take it you’re a traveler.\p"
	.string "How’s this? What do you say to taking\n"
	.string "on our family of four in a series of\l"
	.string "POKéMON battles?$"

Route111_Text_1F14F5: @ 81F14F5
	.string "Is that so?\n"
	.string "Drop in, if you change your mind!$"

Route111_Text_1F1523: @ 81F1523
	.string "That’s the spirit! I like you!$"

Route111_Text_1F1542: @ 81F1542
	.string "Aiyah!\n"
	.string "You’re a lot tougher than I expected!$"

Route111_Text_1F156F: @ 81F156F
	.string "Hey, all!\n"
	.string "I’ve found a pretty strong TRAINER!$"

Route111_Text_1F159D: @ 81F159D
	.string "Oh, my goodness! Aren’t you young?\p"
	.string "You must be quite the TRAINER to beat\n"
	.string "my husband, though.\p"
	.string "It’s my turn to battle now!$"

Route111_Text_1F1616: @ 81F1616
	.string "Oh, gosh!\n"
	.string "I can’t get over how strong you are!$"

Route111_Text_1F1645: @ 81F1645
	.string "There’s a strong TRAINER here!\n"
	.string "This one’s really strong!$"

Route111_Text_1F167E: @ 81F167E
	.string "You’re stronger than Mommy? Wow!\p"
	.string "But I’m strong, too!\n"
	.string "Really! Honestly!$"

Route111_Text_1F16C6: @ 81F16C6
	.string "Huh? Did I just lose?$"

Route111_Text_1F16DC: @ 81F16DC
	.string "This stinks…\p"
	.string "…Snivel… Grandma!$"

Route111_Text_1F16FB: @ 81F16FB
	.string "How dare you make my granddaughter\n"
	.string "cry!\p"
	.string "For that, I’m going to smack you!\n"
	.string "Prepare to lose!$"

Route111_Text_1F1756: @ 81F1756
	.string "Kwah! You are strong…\n"
	.string "My granddaughter was right…$"

Route111_Text_1F1788: @ 81F1788
	.string "If you’re not in any hurry,\n"
	.string "visit with us awhile.$"

Route111_Text_1F17BA: @ 81F17BA
	.string "If you don’t raise your POKéMON some\n"
	.string "more, it could be tough to keep winning\l"
	.string "up through the ranks.\p"
	.string "I’ve heard the POKéMON LEAGUE’s\n"
	.string "ELITE FOUR are far stronger than\l"
	.string "any GYM LEADER.$"

Route111_Text_1F186E: @ 81F186E
	.string "I challenged the WINSTRATE family,\n"
	.string "but four matches in a row is tough\l"
	.string "going… They destroyed me.$"

Route111_Text_1F18CE: @ 81F18CE
	.string "ROUTE 111\n"
	.string "{0x7A} MAUVILLE CITY$"

Route111_Text_1F18E8: @ 81F18E8
	.string "“Our family’s hearts beat as one!”\n"
	.string "THE WINSTRATE’S HOUSE$"

Route111_Text_1F1921: @ 81F1921
	.string "ROUTE 111\n"
	.string "{0x7B} ROUTE 112$"

Route111_Text_1F1937: @ 81F1937
	.string "ROUTE 111\n"
	.string "{0x7B} ROUTE 113$"

Route111_Text_1F194D: @ 81F194D
	.string "OLD LADY’S REST STOP\n"
	.string "“Come in and rest your tired bones.”$"

Route111_Text_1F1987: @ 81F1987
	.string "TRAINER TIPS\p"
	.string "One of the indicators of a POKéMON’s\n"
	.string "powerfulness is SP. ATK. It stands for\l"
	.string "“SPECIAL ATTACK.”\p"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
	.string "DEFENSE.”$"

Route111_Text_1F1A22: @ 81F1A22
	.string "There should be a tower made of sand\n"
	.string "around here somewhere.\p"
	.string "But for some reason, it can be seen\n"
	.string "sometimes, and sometimes not.\p"
	.string "That’s why I call it the MIRAGE TOWER.$"

Route111_Text_1F1AC7: @ 81F1AC7
	.string "I see it!\n"
	.string "The tower of sand!\p"
	.string "The sand tower they called a mirage\n"
	.string "is clearly visible!\p"
	.string "But it looks so fragile…\n"
	.string "It could crumble away anytime…\p"
	.string "I want to go inside it, but I can’t\n"
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
	.string "hasn’t been seen.\p"
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
	.string "{0x7C} TRAINER HILL ENTRANCE\p"
	.string "“Scale the heights, you hot-blooded\n"
	.string "TRAINERS!”$"

