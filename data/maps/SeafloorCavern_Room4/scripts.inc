SeafloorCavern_Room4_MapScripts:: @ 8234C9B
	.byte 0

SeafloorCavern_Room4_EventScript_234C9C:: @ 8234C9C
	trainerbattle_single TRAINER_GRUNT_7, SeafloorCavern_Room4_Text_234CCA, SeafloorCavern_Room4_Text_234CF3
	msgbox SeafloorCavern_Room4_Text_234CFC, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_234CB3:: @ 8234CB3
	trainerbattle_single TRAINER_GRUNT_9, SeafloorCavern_Room4_Text_234D3A, SeafloorCavern_Room4_Text_234D68
	msgbox SeafloorCavern_Room4_Text_234D79, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_234CCA: @ 8234CCA
	.string "Who are you?\n"
	.string "Where did you come in from?$"

SeafloorCavern_Room4_Text_234CF3: @ 8234CF3
	.string "Lost it…$"

SeafloorCavern_Room4_Text_234CFC: @ 8234CFC
	.string "I can't find the way out!\p"
	.string "I'm not afraid. Don't get me wrong!$"

SeafloorCavern_Room4_Text_234D3A: @ 8234D3A
	.string "Who are you?\n"
	.string "Where do you think you're going?$"

SeafloorCavern_Room4_Text_234D68: @ 8234D68
	.string "I failed to win!$"

SeafloorCavern_Room4_Text_234D79: @ 8234D79
	.string "My partner forgot the map in that\n"
	.string "submarine!\p"
	.string "How's that for being useless?$"

