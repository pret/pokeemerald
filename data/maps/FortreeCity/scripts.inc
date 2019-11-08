FortreeCity_MapScripts:: @ 81E25A4
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition: @ 81E25AF
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume: @ 81E25B3
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man:: @ 81E25B6
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman:: @ 81E25BF
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible:: @ 81E25D4
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl:: @ 81E25DE
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan:: @ 81E25E7
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy:: @ 81E25F0
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid:: @ 81E25F9
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign:: @ 81E2602
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign:: @ 81E260B
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon:: @ 81E2614
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope:: @ 81E2630
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope:: @ 81E2645
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee: @ 81E2674
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky: @ 81E2676
	.string "No one believes me, but I saw this\n"
	.string "gigantic POKéMON in the sky.\p"
	.string "It seemed to squirm as it flew toward\n"
	.string "ROUTE 131.\p"
	.string "By the way… Sniff…\n"
	.string "Um… You, uh…smell singed.\p"
	.string "Were you at a volcano or something?$"

FortreeCity_Text_SomethingBlockingGym: @ 81E2738
	.string "I want to go to the POKéMON GYM,\n"
	.string "but something's blocking the way.\p"
	.string "After all the bother I went through\n"
	.string "training on ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona: @ 81E27B6
	.string "I've got my pride-and-joy POKéMON\n"
	.string "with me. This time, I'll beat WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater: @ 81E27FE
	.string "The ground absorbs rainwater, and\n"
	.string "trees grow by drinking that water…\p"
	.string "Our FORTREE CITY exists because\n"
	.string "there's both water and soil.$"

FortreeCity_Text_EveryoneHealthyAndLively: @ 81E2880
	.string "The CITY consists of homes built on\n"
	.string "trees.\p"
	.string "Perhaps because of that lifestyle,\n"
	.string "everyone is healthy and lively.\p"
	.string "Why, even myself--I feel as if I've\n"
	.string "grown thirty years younger.$"

FortreeCity_Text_BugPokemonComeThroughWindow: @ 81E292E
	.string "Living on top of trees is okay.\p"
	.string "But sometimes BUG POKéMON come in\n"
	.string "through windows.\l"
	.string "It can be really startling.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded: @ 81E299D
	.string "There are POKéMON that evolve when\n"
	.string "you trade them! That's what I heard.$"

FortreeCity_Text_SomethingUnseeable: @ 81E29E5
	.string "Something unseeable is in the way.$"

FortreeCity_Text_UnseeableUseDevonScope: @ 81E2A08
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled: @ 81E2A48
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON fled!$"

FortreeCity_Text_CitySign: @ 81E2AAC
	.string "FORTREE CITY\n"
	.string "“The treetop city that frolics with\l"
	.string "nature.”$"

FortreeCity_Text_GymSign: @ 81E2AE6
	.string "FORTREE CITY POKéMON GYM\n"
	.string "LEADER: WINONA\p"
	.string "“The bird user taking flight into\n"
	.string "the world.”$"

