MossdeepCity_House2_MapScripts:: @ 82220DE
	.byte 0

MossdeepCity_House2_EventScript_2220DF:: @ 82220DF
	msgbox MossdeepCity_House2_Text_222146, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_2220E8:: @ 82220E8
	msgbox MossdeepCity_House2_Text_2221A6, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_2220F1:: @ 82220F1
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox MossdeepCity_House2_Text_22222E, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_WINGULL_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
	compare VAR_FACING, 2
	call_if_eq MossdeepCity_House2_EventScript_222124
	compare VAR_FACING, 3
	call_if_eq MossdeepCity_House2_EventScript_22212F
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
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_222141: @ 8222141
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_222146: @ 8222146
	.string "My little sister exchanges MAIL with\n"
	.string "her boyfriend in FORTREE.\p"
	.string "I don't envy her one bit at all.$"

MossdeepCity_House2_Text_2221A6: @ 82221A6
	.string "Even though I can't see my friend in\n"
	.string "FORTREE, my POKéMON carries MAIL\l"
	.string "back and forth for us.\p"
	.string "I'm not lonesome, even though we're\n"
	.string "apart.$"

MossdeepCity_House2_Text_22222E: @ 822222E
	.string "WINGULL: Pihyoh!$"

