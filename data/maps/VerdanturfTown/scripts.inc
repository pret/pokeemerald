VerdanturfTown_MapScripts:: @ 81EB566
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition: @ 81EB56C
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	end

VerdanturfTown_EventScript_1EB575:: @ 81EB575
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_1EB594
	msgbox VerdanturfTown_Text_1EB5FD, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_1EB594:: @ 81EB594
	msgbox VerdanturfTown_Text_1EB6E0, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_1EB5A8:: @ 81EB5A8
	msgbox VerdanturfTown_Text_1EB736, MSGBOX_NPC
	end

VerdanturfTown_EventScript_1EB5B1:: @ 81EB5B1
	msgbox VerdanturfTown_Text_1EB7E2, MSGBOX_NPC
	end

VerdanturfTown_EventScript_1EB5BA:: @ 81EB5BA
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_1EB5CF
	msgbox VerdanturfTown_Text_1EB854, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_1EB5CF:: @ 81EB5CF
	msgbox VerdanturfTown_Text_1EB935, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_1EB5D9:: @ 81EB5D9
	msgbox VerdanturfTown_Text_1EB9C4, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_1EB5E2:: @ 81EB5E2
	msgbox VerdanturfTown_Text_1EBA11, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_1EB5EB:: @ 81EB5EB
	msgbox VerdanturfTown_Text_1EBA1F, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_1EB5F4:: @ 81EB5F4
	msgbox VerdanturfTown_Text_1EBA59, MSGBOX_SIGN
	end

VerdanturfTown_Text_1EB5FD: @ 81EB5FD
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_1EB6E0: @ 81EB6E0
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_1EB736: @ 81EB736
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_1EB7E2: @ 81EB7E2
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"

VerdanturfTown_Text_1EB854: @ 81EB854
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"

VerdanturfTown_Text_1EB935: @ 81EB935
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"

VerdanturfTown_Text_1EB9C4: @ 81EB9C4
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_1EBA11: @ 81EBA11
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_1EBA1F: @ 81EBA1F
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_1EBA59: @ 81EBA59
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

