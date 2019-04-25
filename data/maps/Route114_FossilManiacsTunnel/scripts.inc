Route114_FossilManiacsTunnel_MapScripts:: @ 822AF28
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_MapScript1_22AF49
	.byte 0

Route114_FossilManiacsTunnel_OnTransition: @ 822AF33
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_22AF3D
	end

Route114_FossilManiacsTunnel_EventScript_22AF3D:: @ 822AF3D
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_MapScript1_22AF49: @ 822AF49
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_22AF53
	end

Route114_FossilManiacsTunnel_EventScript_22AF53:: @ 822AF53
	setmetatile 6, 1, 617, 1
	setmetatile 6, 2, 617, 1
	return

Route114_FossilManiacsTunnel_EventScript_22AF66:: @ 822AF66
	lockall
	applymovement 1, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_22B1F7, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_22AF87:: @ 822AF87
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_22AFC6
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq Route114_FossilManiacsTunnel_EventScript_22AFBC
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_eq Route114_FossilManiacsTunnel_EventScript_22AFBC
	msgbox Route114_FossilManiacsTunnel_Text_22AFD0, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_22AFBC:: @ 822AFBC
	msgbox Route114_FossilManiacsTunnel_Text_22B0D6, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_22AFC6:: @ 822AFC6
	msgbox Route114_FossilManiacsTunnel_Text_22B1CC, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_22AFD0: @ 822AFD0
	.string "I'm the FOSSIL MANIAC…\n"
	.string "I'm a nice guy who loves FOSSILS…\p"
	.string "Do you want a FOSSIL?\p"
	.string "But the FOSSILS around these parts all\n"
	.string "belong to me… None for you…\p"
	.string "If you can't bear to go without\n"
	.string "a FOSSIL, look in a desert where there\l"
	.string "are boulders and sand that may hide\l"
	.string "FOSSILS…$"

Route114_FossilManiacsTunnel_Text_22B0D6: @ 822B0D6
	.string "You found a FOSSIL, didn't you?\n"
	.string "That's so nice… It's so dreamy…\p"
	.string "What are you going to do with that\n"
	.string "FOSSIL?\p"
	.string "From what I've heard, DEVON is doing\n"
	.string "research on reviving POKéMON from\l"
	.string "FOSSILS…\p"
	.string "I love my FOSSILS, so I would never\n"
	.string "do anything like that…$"

Route114_FossilManiacsTunnel_Text_22B1CC: @ 822B1CC
	.string "FOSSILS are so… Wonderful…\n"
	.string "It's so dreamy…$"

Route114_FossilManiacsTunnel_Text_22B1F7: @ 822B1F7
	.string "Oh…\n"
	.string "It's not safe that way…\p"
	.string "I was digging away, you see…\n"
	.string "When the whole wall collapsed…\p"
	.string "I think there's a giant cavern\n"
	.string "underneath now…\p"
	.string "But I've left it alone because I don't\n"
	.string "think there are any FOSSILS there…$"

