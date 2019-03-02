BattleFrontier_OutsideWest_MapScripts:: @ 823D3E1
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_MapScript1_23D3E7
	.byte 0

BattleFrontier_OutsideWest_MapScript1_23D3E7: @ 823D3E7
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_23D3F0:: @ 823D3F0
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_23D808, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D44E
	message BattleFrontier_OutsideWest_Text_23D89D
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_23D416
	end

BattleFrontier_OutsideWest_EventScript_23D416:: @ 823D416
	multichoicedefault 18, 6, 53, 2, 0
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_23D458
	case 1, BattleFrontier_OutsideWest_EventScript_23D483
	case 2, BattleFrontier_OutsideWest_EventScript_23D4D8
	case 127, BattleFrontier_OutsideWest_EventScript_23D4D8
	end

BattleFrontier_OutsideWest_EventScript_23D44E:: @ 823D44E
	msgbox BattleFrontier_OutsideWest_Text_23D842, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D458:: @ 823D458
	msgbox BattleFrontier_OutsideWest_Text_23D8F2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D4AE
	msgbox BattleFrontier_OutsideWest_Text_23D94B, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_23D4BA
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_23D483:: @ 823D483
	msgbox BattleFrontier_OutsideWest_Text_23D90E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D4AE
	msgbox BattleFrontier_OutsideWest_Text_23D94B, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_23D4BA
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_23D4AE:: @ 823D4AE
	message BattleFrontier_OutsideWest_Text_23D97A
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_23D416
	end

BattleFrontier_OutsideWest_EventScript_23D4BA:: @ 823D4BA
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	hideobjectat 3, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, 2
	call BattleFrontier_OutsideWest_EventScript_272250
	return

BattleFrontier_OutsideWest_EventScript_23D4D8:: @ 823D4D8
	msgbox BattleFrontier_OutsideWest_Text_23D929, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D4E2:: @ 823D4E2
	msgbox BattleFrontier_OutsideWest_Text_23D6F7, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_23D4EB:: @ 823D4EB
	msgbox BattleFrontier_OutsideWest_Text_23D737, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_23D4F4:: @ 823D4F4
	msgbox BattleFrontier_OutsideWest_Text_23D772, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_23D4FD:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_23D7A6, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D506:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_23D9DD, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D50F:: @ 823D50F
	msgbox BattleFrontier_OutsideWest_Text_23D99C, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D518:: @ 823D518
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_23DA60
	waitmessage
	applymovement 18, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_23D52D:: @ 823D52D
	msgbox BattleFrontier_OutsideWest_Text_23DABF, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D536:: @ 823D536
	lock
	goto BattleFrontier_OutsideWest_EventScript_23D544
	end

BattleFrontier_OutsideWest_EventScript_23D53D:: @ 823D53D
	lock
	goto BattleFrontier_OutsideWest_EventScript_23D544
	end

BattleFrontier_OutsideWest_EventScript_23D544:: @ 823D544
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_23DB7D, MSGBOX_DEFAULT
	applymovement 10, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_23DBCE, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement 9, Common_Movement_WalkInPlaceUp
	applymovement 10, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_23D57F:: @ 823D57F
	lock
	faceplayer
	delay 20
	compare VAR_FACING, 2
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5BA
	compare VAR_FACING, 1
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5C5
	compare VAR_FACING, 3
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5BA
	compare VAR_FACING, 4
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5BA
	msgbox BattleFrontier_OutsideWest_Text_23DC36, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D5BA:: @ 823D5BA
	applymovement 14, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D5C5:: @ 823D5C5
	return

BattleFrontier_OutsideWest_EventScript_23D5C6:: @ 823D5C6
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_23DCB0
	waitmessage
	compare VAR_FACING, 2
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D5FD
	compare VAR_FACING, 1
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D608
	compare VAR_FACING, 3
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D613
	compare VAR_FACING, 4
	call_if_eq BattleFrontier_OutsideWest_EventScript_23D61E
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_23D5FD:: @ 823D5FD
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D629
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D608:: @ 823D608
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D62C
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D613:: @ 823D613
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D62F
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_23D61E:: @ 823D61E
	applymovement 12, BattleFrontier_OutsideWest_Movement_23D632
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_23D629: @ 823D629
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	step_end

BattleFrontier_OutsideWest_Movement_23D62C: @ 823D62C
	walk_in_place_fastest_up
	walk_in_place_fastest_up
	step_end

BattleFrontier_OutsideWest_Movement_23D62F: @ 823D62F
	walk_in_place_fastest_right
	walk_in_place_fastest_right
	step_end

BattleFrontier_OutsideWest_Movement_23D632: @ 823D632
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	step_end

BattleFrontier_OutsideWest_EventScript_23D635:: @ 823D635
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_23DD3B, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_OutsideWest_EventScript_23D653
	goto BattleFrontier_OutsideWest_EventScript_23D65D
	end

BattleFrontier_OutsideWest_EventScript_23D653:: @ 823D653
	msgbox BattleFrontier_OutsideWest_Text_23DD7A, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D65D:: @ 823D65D
	msgbox BattleFrontier_OutsideWest_Text_23DDAD, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D667:: @ 823D667
	msgbox BattleFrontier_OutsideWest_Text_23DE15, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D670:: @ 823D670
	msgbox BattleFrontier_OutsideWest_Text_23DF7D, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D679:: @ 823D679
	msgbox BattleFrontier_OutsideWest_Text_23DEFD, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D682:: @ 823D682
	msgbox BattleFrontier_OutsideWest_Text_23DEB4, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D68B:: @ 823D68B
	msgbox BattleFrontier_OutsideWest_Text_23DFBF, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D694:: @ 823D694
	msgbox BattleFrontier_OutsideWest_Text_23E01E, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D69D:: @ 823D69D
	msgbox BattleFrontier_OutsideWest_Text_23E09F, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6A6:: @ 823D6A6
	msgbox BattleFrontier_OutsideWest_Text_23E102, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6AF:: @ 823D6AF
	msgbox BattleFrontier_OutsideWest_Text_23E154, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6B8:: @ 823D6B8
	lock
	msgbox BattleFrontier_OutsideWest_Text_23E273, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D6C3:: @ 823D6C3
	lock
	msgbox BattleFrontier_OutsideWest_Text_23E2E9, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_23D6CE:: @ 823D6CE
	msgbox BattleFrontier_OutsideWest_Text_23E37E, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_23D6D7:: @ 823D6D7
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_23E410, MSGBOX_DEFAULT
	closemessage
	applymovement 23, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_23D6EE:: @ 823D6EE
	msgbox BattleFrontier_OutsideWest_Text_23E5A5, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_23D6F7: @ 823D6F7
	.string "This is the BATTLE DOME!\n"
	.string "Your path to the invincible superstar!$"

BattleFrontier_OutsideWest_Text_23D737: @ 823D737
	.string "This is the BATTLE FACTORY!\n"
	.string "Seek out the toughest POKéMON!$"

BattleFrontier_OutsideWest_Text_23D772: @ 823D772
	.string "This is the BATTLE PIKE!\n"
	.string "Choose one of three paths!$"

BattleFrontier_OutsideWest_Text_23D7A6: @ 823D7A6
	.string "This is the BATTLE TOWER.\p"
	.string "TRAINERS bring their best-raised\n"
	.string "POKéMON for elimination-style matches.$"

BattleFrontier_OutsideWest_Text_23D808: @ 823D808
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

BattleFrontier_OutsideWest_Text_23D842: @ 823D842
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

BattleFrontier_OutsideWest_Text_23D89D: @ 823D89D
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

BattleFrontier_OutsideWest_Text_23D8F2: @ 823D8F2
	.string "SLATEPORT CITY it is, then!$"

BattleFrontier_OutsideWest_Text_23D90E: @ 823D90E
	.string "LILYCOVE CITY it is, then!$"

BattleFrontier_OutsideWest_Text_23D929: @ 823D929
	.string "Please sail with us another time!$"

BattleFrontier_OutsideWest_Text_23D94B: @ 823D94B
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

BattleFrontier_OutsideWest_Text_23D97A: @ 823D97A
	.string "Then, where would you like to go?$"

BattleFrontier_OutsideWest_Text_23D99C: @ 823D99C
	.string "I'm the best out of all my friends.\n"
	.string "But here…\l"
	.string "I've been useless!$"

BattleFrontier_OutsideWest_Text_23D9DD: @ 823D9DD
	.string "I want to go to the BATTLE TOWER,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the BATTLE FRONTIER.\p"
	.string "This place is just too big!$"

BattleFrontier_OutsideWest_Text_23DA60: @ 823DA60
	.string "I wanted to take a challenge as soon\n"
	.string "as I arrived here.\p"
	.string "But on the way, I got seasick…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_23DABF: @ 823DABF
	.string "It's not as if just anyone can come\n"
	.string "here, you know?\p"
	.string "Only those TRAINERS who've been\n"
	.string "recognized as tough are brought here.\p"
	.string "That's why many TRAINERS don't even\n"
	.string "know about the BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_23DB7D: @ 823DB7D
	.string "Hey, bro…\p"
	.string "Are you sure we can make challenges\n"
	.string "even if we don't have any POKéMON?$"

BattleFrontier_OutsideWest_Text_23DBCE: @ 823DBCE
	.string "Uh…\n"
	.string "I'm sure it'll be okay.\p"
	.string "I think…\p"
	.string "But remember that big scary guy?\n"
	.string "He said, “I'll lend you POKéMON!”$"

BattleFrontier_OutsideWest_Text_23DC36: @ 823DC36
	.string "That's the BATTLE FACTORY.\n"
	.string "You can rent strong POKéMON there.\p"
	.string "But it makes me wonder.\n"
	.string "Who's raising those rental POKéMON?$"

BattleFrontier_OutsideWest_Text_23DCB0: @ 823DCB0
	.string "I'm scared of going into the BATTLE\n"
	.string "PIKE because of SEVIPER…\p"
	.string "B-but I came all the way here, so I will\n"
	.string "try to conquer everything!\l"
	.string "…Shudder…$"

BattleFrontier_OutsideWest_Text_23DD3B: @ 823DD3B
	.string "Let's play rock, paper, scissors!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_23DD7A: @ 823DD7A
	.string "Yay! I won!\n"
	.string "I will take the BATTLE PIKE challenge!$"

BattleFrontier_OutsideWest_Text_23DDAD: @ 823DDAD
	.string "Oh, no…\n"
	.string "I lost.\p"
	.string "I guess I'm not very lucky today.\n"
	.string "I'll put off my BATTLE PIKE challenge\l"
	.string "until tomorrow.$"

BattleFrontier_OutsideWest_Text_23DE15: @ 823DE15
	.string "I believe I'm the only person here who,\n"
	.string "for some unknown reason, would choose\l"
	.string "fishing over battling.\p"
	.string "Huh? You can't catch anything here?\n"
	.string "That's disappointing…$"

BattleFrontier_OutsideWest_Text_23DEB4: @ 823DEB4
	.string "Today, I'm going to keep battling, no\n"
	.string "matter what, until I get a Symbol.$"

BattleFrontier_OutsideWest_Text_23DEFD: @ 823DEFD
	.string "Oh? You're off to challenge\n"
	.string "the BATTLE DOME?\p"
	.string "I'll wish you the best of luck.\n"
	.string "Let us both win our way up and meet\l"
	.string "in challenges.$"

BattleFrontier_OutsideWest_Text_23DF7D: @ 823DF7D
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"

BattleFrontier_OutsideWest_Text_23DFBF: @ 823DFBF
	.string "Ah, so this here is the BATTLE DOME?\n"
	.string "I won't let GENTLEMEN beat me!\p"
	.string "But where is the entrance?$"

BattleFrontier_OutsideWest_Text_23E01E: @ 823E01E
	.string "There used to be nothing here not all\n"
	.string "that long ago.\p"
	.string "But, now look at this place! Amazing!\n"
	.string "I'll bring my mother out to see this.$"

BattleFrontier_OutsideWest_Text_23E09F: @ 823E09F
	.string "I've finally arrived at the BATTLE\n"
	.string "FRONTIER!\p"
	.string "I'm sure to grab attention with\n"
	.string "my looks and ability!$"

BattleFrontier_OutsideWest_Text_23E102: @ 823E102
	.string "Munch, munch…\p"
	.string "It looks like this square's filled with\n"
	.string "tough people.\p"
	.string "Munch, munch…$"

BattleFrontier_OutsideWest_Text_23E154: @ 823E154
	.string "Crunch, munch…\p"
	.string "A while back, I met this older girl\n"
	.string "at the BATTLE PIKE.\p"
	.string "She had these eyes that were scary\n"
	.string "in a real ornery way.\p"
	.string "Crunch, munch…\p"
	.string "She got all furious: “Will you quit\n"
	.string "eating!” Then she whaled on me.\p"
	.string "It was a hair-raising kind of\n"
	.string "scary experience, sure enough.\p"
	.string "Crunch, munch…$"

BattleFrontier_OutsideWest_Text_23E273: @ 823E273
	.string "Huh? Will you listen to yourself?\n"
	.string "That's nothing!\p"
	.string "Why, the last time I cheered for him,\n"
	.string "our eyes met and sparks flew!$"

BattleFrontier_OutsideWest_Text_23E2E9: @ 823E2E9
	.string "Whaaaaaat?!\n"
	.string "Pfft!\p"
	.string "That only happened because\n"
	.string "I happened to be sitting next to you!\p"
	.string "The DOME ACE only looked our way\n"
	.string "because my cheering was so loud!$"

BattleFrontier_OutsideWest_Text_23E37E: @ 823E37E
	.string "Oh, shush!\n"
	.string "Keep that racket down!\p"
	.string "You fair-weather fans should stick\n"
	.string "to cheering for some GYM LEADER!\p"
	.string "The DOME ACE is mine!\n"
	.string "The only idol for me!$"

BattleFrontier_OutsideWest_Text_23E410: @ 823E410
	.string "Those people squabbling over there…\p"
	.string "It's hard to believe, but they once\n"
	.string "were TRAINERS, and good ones, too.\p"
	.string "They used to be incredibly tough,\n"
	.string "and they were famous, too.\p"
	.string "But they were obliterated by this\n"
	.string "certain TRAINER at a tournament.\p"
	.string "They were so thoroughly whipped,\n"
	.string "they became smitten by the TRAINER.\p"
	.string "Now they're just fans of the TRAINER.\n"
	.string "They go cheer for their idol at the\l"
	.string "BATTLE DOME every day now.$"

BattleFrontier_OutsideWest_Text_23E5A5: @ 823E5A5
	.string "I heard a rumor that someone saw\n"
	.string "a POKéMON with an unusually long tail\l"
	.string "somewhere in the BATTLE FRONTIER.\p"
	.string "It must be adorable. I'm sure of it…\p"
	.string "Oh, challenges can wait. I feel driven\n"
	.string "to find the delightful creature!$"

