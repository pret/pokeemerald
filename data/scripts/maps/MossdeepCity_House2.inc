MossdeepCity_House2_MapScripts:: @ 82220DE
	.byte 0

MossdeepCity_House2_EventScript_2220DF:: @ 82220DF
	msgbox MossdeepCity_House2_Text_222146, 2
	end

MossdeepCity_House2_EventScript_2220E8:: @ 82220E8
	msgbox MossdeepCity_House2_Text_2221A6, 2
	end

MossdeepCity_House2_EventScript_2220F1:: @ 82220F1
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox MossdeepCity_House2_Text_22222E, 4
	waitmoncry
	closemessage
	setflag FLAG_0x0E0
	clearflag FLAG_0x3A5
	compare_var_to_value VAR_FACING, 2
	call_if 1, MossdeepCity_House2_EventScript_222124
	compare_var_to_value VAR_FACING, 3
	call_if 1, MossdeepCity_House2_EventScript_22212F
	removeobject 3
	release
	end

MossdeepCity_House2_EventScript_222124:: @ 8222124
	applymovement 3, MossdeepCity_House2_Movement_22213A
	waitmovement 0
	return

MossdeepCity_House2_EventScript_22212F:: @ 822212F
	applymovement 3, MossdeepCity_House2_Movement_222141
	waitmovement 0
	return

MossdeepCity_House2_Movement_22213A: @ 822213A
	step_18
	step_15
	step_15
	step_17
	step_15
	step_13
	step_end

MossdeepCity_House2_Movement_222141: @ 8222141
	step_15
	step_15
	step_15
	step_13
	step_end

MossdeepCity_House2_Text_222146: @ 8222146
	.string "My little sister exchanges MAIL with\n"
	.string "her boyfriend in FORTREE.\p"
	.string "I don’t envy her one bit at all.$"

MossdeepCity_House2_Text_2221A6: @ 82221A6
	.string "Even though I can’t see my friend in\n"
	.string "FORTREE, my POKéMON carries MAIL\l"
	.string "back and forth for us.\p"
	.string "I’m not lonesome, even though we’re\n"
	.string "apart.$"

MossdeepCity_House2_Text_22222E: @ 822222E
	.string "WINGULL: Pihyoh!$"

