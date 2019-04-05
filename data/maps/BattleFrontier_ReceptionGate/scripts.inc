BattleFrontier_ReceptionGate_MapScripts:: @ 82661DA
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_MapScript2_2661E9
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition: @ 82661E5
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_MapScript2_2661E9: @ 82661E9
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_2661F3
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_2661F3:: @ 82661F3
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_266580, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_2662D2
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_266229
	end

BattleFrontier_ReceptionGate_EventScript_266229:: @ 8266229
	msgbox BattleFrontier_ReceptionGate_Text_2665B2, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_2665F7, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message BattleFrontier_ReceptionGate_Text_266676
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_266695, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_266703, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	applymovement 2, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	applymovement 2, Common_Movement_ExclamationMark
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_266733, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BattleFrontier_ReceptionGate_Movement_2662F0
	applymovement 2, BattleFrontier_ReceptionGate_Movement_2662F6
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_2662D7
	applymovement 4, BattleFrontier_ReceptionGate_Movement_2662E0
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_266764, MSGBOX_DEFAULT
	closemessage
	applymovement 4, BattleFrontier_ReceptionGate_Movement_2662E8
	waitmovement 0
	removeobject 4
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_2662D2: @ 82662D2
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_2662D7: @ 82662D7
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

BattleFrontier_ReceptionGate_Movement_2662DD: @ 82662DD
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_2662E0: @ 82662E0
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_2662E8: @ 82662E8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_2662F0: @ 82662F0
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

BattleFrontier_ReceptionGate_Movement_2662F6: @ 82662F6
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

BattleFrontier_ReceptionGate_EventScript_2662FC:: @ 82662FC
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_2665B2, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_266310:: @ 8266310
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_266857, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_266320:: @ 8266320
	message BattleFrontier_ReceptionGate_Text_26689D
	waitmessage
	setvar VAR_0x8004, 8
	special sub_813A128
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_2663AE
	case 1, BattleFrontier_ReceptionGate_EventScript_2663BC
	case 2, BattleFrontier_ReceptionGate_EventScript_2663CA
	case 3, BattleFrontier_ReceptionGate_EventScript_2663D8
	case 4, BattleFrontier_ReceptionGate_EventScript_2663E6
	case 5, BattleFrontier_ReceptionGate_EventScript_2663F4
	case 6, BattleFrontier_ReceptionGate_EventScript_266402
	case 7, BattleFrontier_ReceptionGate_EventScript_266410
	case 8, BattleFrontier_ReceptionGate_EventScript_26641E
	case 9, BattleFrontier_ReceptionGate_EventScript_26642C
	case 127, BattleFrontier_ReceptionGate_EventScript_26642C
	end

BattleFrontier_ReceptionGate_EventScript_2663AE:: @ 82663AE
	msgbox BattleFrontier_ReceptionGate_Text_2668C2, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663BC:: @ 82663BC
	msgbox BattleFrontier_ReceptionGate_Text_26696F, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663CA:: @ 82663CA
	msgbox BattleFrontier_ReceptionGate_Text_266A34, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663D8:: @ 82663D8
	msgbox BattleFrontier_ReceptionGate_Text_266AC2, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663E6:: @ 82663E6
	msgbox BattleFrontier_ReceptionGate_Text_266B5D, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_2663F4:: @ 82663F4
	msgbox BattleFrontier_ReceptionGate_Text_266C24, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_266402:: @ 8266402
	msgbox BattleFrontier_ReceptionGate_Text_266CBB, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_266410:: @ 8266410
	msgbox BattleFrontier_ReceptionGate_Text_266D1C, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_26641E:: @ 826641E
	msgbox BattleFrontier_ReceptionGate_Text_266DCB, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266320
	end

BattleFrontier_ReceptionGate_EventScript_26642C:: @ 826642C
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_266436:: @ 8266436
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_266E66, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_266446:: @ 8266446
	message BattleFrontier_ReceptionGate_Text_266EE0
	waitmessage
	multichoice 15, 0, 95, 0
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_2664A4
	case 1, BattleFrontier_ReceptionGate_EventScript_2664B2
	case 2, BattleFrontier_ReceptionGate_EventScript_2664C0
	case 3, BattleFrontier_ReceptionGate_EventScript_2664CE
	case 4, BattleFrontier_ReceptionGate_EventScript_2664DC
	case 5, BattleFrontier_ReceptionGate_EventScript_2664EA
	case 127, BattleFrontier_ReceptionGate_EventScript_2664EA
	end

BattleFrontier_ReceptionGate_EventScript_2664A4:: @ 82664A4
	msgbox BattleFrontier_ReceptionGate_Text_266F04, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664B2:: @ 82664B2
	msgbox BattleFrontier_ReceptionGate_Text_266F69, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664C0:: @ 82664C0
	msgbox BattleFrontier_ReceptionGate_Text_267080, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664CE:: @ 82664CE
	msgbox BattleFrontier_ReceptionGate_Text_26716A, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664DC:: @ 82664DC
	msgbox BattleFrontier_ReceptionGate_Text_267298, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266446
	end

BattleFrontier_ReceptionGate_EventScript_2664EA:: @ 82664EA
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_2664F4:: @ 82664F4
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_267357, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_266504:: @ 8266504
	message BattleFrontier_ReceptionGate_Text_26737C
	waitmessage
	multichoice 16, 4, 11, 0
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_26654C
	case 1, BattleFrontier_ReceptionGate_EventScript_26655A
	case 2, BattleFrontier_ReceptionGate_EventScript_266568
	case 3, BattleFrontier_ReceptionGate_EventScript_266576
	case 127, BattleFrontier_ReceptionGate_EventScript_266576
	end

BattleFrontier_ReceptionGate_EventScript_26654C:: @ 826654C
	msgbox BattleFrontier_ReceptionGate_Text_2673A1, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_26655A:: @ 826655A
	msgbox BattleFrontier_ReceptionGate_Text_2674F3, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_266568:: @ 8266568
	msgbox BattleFrontier_ReceptionGate_Text_26761C, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_266504
	end

BattleFrontier_ReceptionGate_EventScript_266576:: @ 8266576
	msgbox BattleFrontier_ReceptionGate_Text_2666C6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_266580: @ 8266580
	.string "Is it your first time here?\n"
	.string "Please step this way!$"

BattleFrontier_ReceptionGate_Text_2665B2: @ 82665B2
	.string "The front lines of POKéMON battling!\n"
	.string "Welcome to the BATTLE FRONTIER!$"

BattleFrontier_ReceptionGate_Text_2665F7: @ 82665F7
	.string "For a first-time visitor, we issue\n"
	.string "the FRONTIER PASS.\p"
	.string "It's for use at all the facilities\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Here you are!$"

BattleFrontier_ReceptionGate_Text_266676: @ 8266676
	.string "{PLAYER} obtained\n"
	.string "the FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_266695: @ 8266695
	.string "{PLAYER} placed the TRAINER CARD\n"
	.string "in the FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_2666C6: @ 82666C6
	.string "We hope you enjoy all that the BATTLE\n"
	.string "FRONTIER has to offer!$"

BattleFrontier_ReceptionGate_Text_266703: @ 8266703
	.string "???: Well, if it isn't {PLAYER}{KUN}!\n"
	.string "You came out here!$"

BattleFrontier_ReceptionGate_Text_266733: @ 8266733
	.string "GUIDE: Oh! MR. SCOTT, sir!\n"
	.string "Good day to you, sir!$"

BattleFrontier_ReceptionGate_Text_266764: @ 8266764
	.string "SCOTT: It's great to see you here,\n"
	.string "it really is!\p"
	.string "I hope you'll take your time and\n"
	.string "explore everywhere.\p"
	.string "Naturally, I hope you'll also experience\n"
	.string "the pure essence of battling.\p"
	.string "I also have my quarters here, so feel\n"
	.string "free to visit if you have time.$"

BattleFrontier_ReceptionGate_Text_266857: @ 8266857
	.string "I'm your guide to the various facilities\n"
	.string "here in the BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_26689D: @ 826689D
	.string "Which would you like to learn about?$"

BattleFrontier_ReceptionGate_Text_2668C2: @ 82668C2
	.string "It is the gigantic tower considered\n"
	.string "to be the BATTLE FRONTIER's symbol.\p"
	.string "There are four kinds of BATTLE ROOMS\n"
	.string "in the tower for SINGLE, DOUBLE, MULTI,\l"
	.string "and LINK MULTI BATTLES.$"

BattleFrontier_ReceptionGate_Text_26696F: @ 826696F
	.string "The BATTLE DOME is the large building\n"
	.string "shaped like a huge egg.\p"
	.string "Events named Battle Tourneys are held\n"
	.string "in this facility.\p"
	.string "The Battle Tourneys are offered in\n"
	.string "two courses--for SINGLE and DOUBLE\l"
	.string "BATTLES.$"

BattleFrontier_ReceptionGate_Text_266A34: @ 8266A34
	.string "The BATTLE PALACE is the red building\n"
	.string "on the right of the BATTLE FRONTIER.\p"
	.string "There are two kinds of BATTLE HALLS\n"
	.string "for SINGLE and DOUBLE BATTLES.$"

BattleFrontier_ReceptionGate_Text_266AC2: @ 8266AC2
	.string "The BATTLE ARENA is the dojo-like\n"
	.string "building at the center-right of\l"
	.string "the BATTLE FRONTIER.\p"
	.string "An event called the Set KO Tourney\n"
	.string "takes place at the BATTLE ARENA.$"

BattleFrontier_ReceptionGate_Text_266B5D: @ 8266B5D
	.string "The BATTLE FACTORY is the large\n"
	.string "building that is the closest to us.\p"
	.string "An event called the Battle Swap\n"
	.string "is conducted there.\p"
	.string "The Battle Swap event is offered in\n"
	.string "two courses for SINGLE and DOUBLE\l"
	.string "BATTLES.$"

BattleFrontier_ReceptionGate_Text_266C24: @ 8266C24
	.string "The BATTLE PIKE is the building shaped\n"
	.string "like a POKéMON at the center-left of\l"
	.string "the BATTLE FRONTIER.\p"
	.string "An event called the Battle Choice\n"
	.string "is conducted there.$"

BattleFrontier_ReceptionGate_Text_266CBB: @ 8266CBB
	.string "The BATTLE PYRAMID is the enormous\n"
	.string "pyramid.\p"
	.string "An event called the Battle Quest\n"
	.string "is conducted there.$"

BattleFrontier_ReceptionGate_Text_266D1C: @ 8266D1C
	.string "The RANKING HALL is located near\n"
	.string "the BATTLE TOWER.\p"
	.string "There, you may see the most fantastic\n"
	.string "records left by the TRAINERS that\l"
	.string "took on the many challenges of\l"
	.string "the BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_266DCB: @ 8266DCB
	.string "The EXCHANGE SERVICE CORNER is near\n"
	.string "the BATTLE TOWER.\p"
	.string "The Battle Points you have earned in\n"
	.string "the BATTLE FRONTIER may be exchanged\l"
	.string "for fabulous prizes there.$"

BattleFrontier_ReceptionGate_Text_266E66: @ 8266E66
	.string "I'm your guide to the basic rules that\n"
	.string "are common to all the challenges\l"
	.string "offered by the facilities in the BATTLE\l"
	.string "FRONTIER.$"

BattleFrontier_ReceptionGate_Text_266EE0: @ 8266EE0
	.string "What would you like to learn about?$"

BattleFrontier_ReceptionGate_Text_266F04: @ 8266F04
	.string "All the challenges at the BATTLE\n"
	.string "FRONTIER's facilities come in\l"
	.string "two courses--Level 50 and Open Level.$"

BattleFrontier_ReceptionGate_Text_266F69: @ 8266F69
	.string "The Level 50 course is open to POKéMON\n"
	.string "up to and including Level 50.\p"
	.string "Please keep in mind, however, that\n"
	.string "no TRAINER you face will have any\l"
	.string "POKéMON below Level 50.\p"
	.string "This course is the entry level for\n"
	.string "battles at the BATTLE FRONTIER.\p"
	.string "To begin, we hope you will challenge\n"
	.string "this course.$"

BattleFrontier_ReceptionGate_Text_267080: @ 8267080
	.string "The Open Level course places no limit\n"
	.string "on the levels of POKéMON entering\l"
	.string "challenges.\p"
	.string "The levels of your opponents will\n"
	.string "be adjusted to match the levels of\l"
	.string "your POKéMON.\p"
	.string "However, no TRAINER you face will\n"
	.string "have any POKéMON below Level 60.$"

BattleFrontier_ReceptionGate_Text_26716A: @ 826716A
	.string "Virtually any kind of POKéMON may take\n"
	.string "on the challenges at all facilities.\p"
	.string "EGGS and certain kinds of POKéMON,\n"
	.string "however, are not permitted.\p"
	.string "The numbers of POKéMON required for\n"
	.string "challenges will depend on the facility.\p"
	.string "At all facilities, however, two or more\n"
	.string "of the same kind of POKéMON are not\l"
	.string "permitted.$"

BattleFrontier_ReceptionGate_Text_267298: @ 8267298
	.string "When entering a challenge at a BATTLE\n"
	.string "FRONTIER facility, POKéMON may not\l"
	.string "be holding the same kind of item.\p"
	.string "Please make sure that all POKéMON\n"
	.string "entering a challenge are holding\l"
	.string "different items.$"

BattleFrontier_ReceptionGate_Text_267357: @ 8267357
	.string "I'm your guide to the FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_26737C: @ 826737C
	.string "Which would you like to learn about?$"

BattleFrontier_ReceptionGate_Text_2673A1: @ 82673A1
	.string "There are seven facilities at\n"
	.string "the BATTLE FRONTIER.\p"
	.string "TRAINERS who gain recognition for\n"
	.string "their abilities may be rewarded with\l"
	.string "symbols from each of the facilities.\p"
	.string "To earn a symbol, TRAINERS may need\n"
	.string "to defeat other TRAINERS in a row,\l"
	.string "and may need to win events repeatedly.\p"
	.string "It's certainly not easy to win symbols.\n"
	.string "I wish you the best of luck!$"

BattleFrontier_ReceptionGate_Text_2674F3: @ 82674F3
	.string "It is possible to record one battle\n"
	.string "on your FRONTIER PASS.\p"
	.string "You may record a battle you had with\n"
	.string "a friend or friends.\p"
	.string "Or you may record a battle conducted\n"
	.string "at the BATTLE FRONTIER excluding\l"
	.string "matches at the BATTLE PIKE or\l"
	.string "the BATTLE PYRAMID.\p"
	.string "You may choose to record your match\n"
	.string "at the end of a battle.$"

BattleFrontier_ReceptionGate_Text_26761C: @ 826761C
	.string "Battle Points are rewards given to\n"
	.string "TRAINERS who battled outstandingly\l"
	.string "at the BATTLE FRONTIER.\p"
	.string "You may trade in your Battle Points\n"
	.string "for prizes at the EXCHANGE SERVICE\l"
	.string "CORNER.$"

