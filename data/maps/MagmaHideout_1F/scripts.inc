MagmaHideout_1F_MapScripts:: @ 8239880
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition: @ 8239886
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_23988C:: @ 823988C
	trainerbattle_single TRAINER_GRUNT_38, MagmaHideout_1F_Text_2398BA, MagmaHideout_1F_Text_239964
	msgbox MagmaHideout_1F_Text_2399B1, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_2398A3:: @ 82398A3
	trainerbattle_single TRAINER_GRUNT_39, MagmaHideout_1F_Text_2399F5, MagmaHideout_1F_Text_239ABA
	msgbox MagmaHideout_1F_Text_239ACD, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_2398BA: @ 82398BA
	.string "When TEAM MAGMA has roll call, we get\n"
	.string "important guarding assignments in\l"
	.string "the order that we line up.\p"
	.string "That's why I'm stuck off in this corner.\n"
	.string "I'm always late to roll call!$"

MagmaHideout_1F_Text_239964: @ 8239964
	.string "I'm always late for training sessions,\n"
	.string "too!\p"
	.string "I hate to say it, but I'm wimpy…$"

MagmaHideout_1F_Text_2399B1: @ 82399B1
	.string "Okay, I'll try to put a little more\n"
	.string "effort into things from now on…$"

MagmaHideout_1F_Text_2399F5: @ 82399F5
	.string "Our leader told us to dig into\n"
	.string "MT. CHIMNEY, so we dug and dug.\p"
	.string "And in the course of digging, we came\n"
	.string "across something that blew our minds!\p"
	.string "What did we find?\p"
	.string "Fuhahaha!\n"
	.string "I'll tell you if you beat me!$"

MagmaHideout_1F_Text_239ABA: @ 8239ABA
	.string "Arrgh!\n"
	.string "Taken down!$"

MagmaHideout_1F_Text_239ACD: @ 8239ACD
	.string "I won't tell you after all.\n"
	.string "You'll find out when you get there!\p"
	.string "It'd be better if you saved surprises\n"
	.string "to the end, don't you think?$"

