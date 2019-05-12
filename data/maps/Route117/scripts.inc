Route117_MapScripts:: @ 81F397D
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
	.byte 0

Route117_OnTransition: @ 81F3983
	call Route117_EventScript_1F3989
	end

Route117_EventScript_1F3989:: @ 81F3989
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_1F3999
	setobjectxyperm 3, 47, 6

Route117_EventScript_1F3999:: @ 81F3999
	return

Route117_EventScript_1F399A:: @ 81F399A
	msgbox Route117_Text_1F3CFD, MSGBOX_NPC
	end

Route117_EventScript_1F39A3:: @ 81F39A3
	msgbox Route117_Text_1F3D41, MSGBOX_NPC
	end

Route117_EventScript_1F39AC:: @ 81F39AC
	msgbox Route117_Text_1F3C7C, MSGBOX_NPC
	end

Route117_EventScript_1F39B5:: @ 81F39B5
	msgbox Route117_Text_1F3D58, MSGBOX_SIGN
	end

Route117_EventScript_1F39BE:: @ 81F39BE
	msgbox Route117_Text_1F3D74, MSGBOX_SIGN
	end

Route117_EventScript_1F39C7:: @ 81F39C7
	msgbox Route117_Text_1F3D8E, MSGBOX_SIGN
	end

Route117_EventScript_1F39D0:: @ 81F39D0
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_29C43F, Route117_Text_29C47A, Route117_EventScript_1F39FC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3A1B
	msgbox Route117_Text_29C498, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_1F39FC:: @ 81F39FC
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29C508, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAAC_1
	release
	end

Route117_EventScript_1F3A1B:: @ 81F3A1B
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_29C549, Route117_Text_29C58B
	msgbox Route117_Text_29C5D0, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3A32:: @ 81F3A32
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_29C612, Route117_Text_29C659, Route117_EventScript_1F3A5E
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3A7D
	msgbox Route117_Text_29C679, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_1F3A5E:: @ 81F3A5E
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29C6BC, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYDIA_1
	release
	end

Route117_EventScript_1F3A7D:: @ 81F3A7D
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_29C6FD, Route117_Text_29C73E
	msgbox Route117_Text_29C75A, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3A94:: @ 81F3A94
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_29C7A5, Route117_Text_29C7EB, Route117_EventScript_1F3AC0
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3ADF
	msgbox Route117_Text_29C800, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_1F3AC0:: @ 81F3AC0
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29C846, MSGBOX_DEFAULT
	register_matchcall TRAINER_DYLAN_1
	release
	end

Route117_EventScript_1F3ADF:: @ 81F3ADF
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_29C880, Route117_Text_29C8E3
	msgbox Route117_Text_29C8FE, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3AF6:: @ 81F3AF6
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_29C955, Route117_Text_29C9A6, Route117_EventScript_1F3B22
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3B41
	msgbox Route117_Text_29C9D0, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_1F3B22:: @ 81F3B22
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29CA32, MSGBOX_DEFAULT
	register_matchcall TRAINER_MARIA_1
	release
	end

Route117_EventScript_1F3B41:: @ 81F3B41
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_29CA7C, Route117_Text_29CACC
	msgbox Route117_Text_29CAF6, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3B58:: @ 81F3B58
	trainerbattle_single TRAINER_DEREK, Route117_Text_29CB32, Route117_Text_29CB87
	msgbox Route117_Text_29CBAD, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3B6F:: @ 81F3B6F
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CC4A, Route117_Text_29CC8E, Route117_Text_29CD61, Route117_EventScript_1F3B9F
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3BB8
	msgbox Route117_Text_29CCCB, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_1F3B9F:: @ 81F3B9F
	msgbox Route117_Text_29CD1D, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_1F3BB8:: @ 81F3BB8
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CEB6, Route117_Text_29CEF6, Route117_Text_29CF6E
	msgbox Route117_Text_29CF1C, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3BD3:: @ 81F3BD3
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CD9D, Route117_Text_29CDE9, Route117_Text_29CE52, Route117_EventScript_1F3C03
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3C1C
	msgbox Route117_Text_29CE17, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_1F3C03:: @ 81F3C03
	msgbox Route117_Text_29CD1D, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_1F3C1C:: @ 81F3C1C
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CFAA, Route117_Text_29CFED, Route117_Text_29D053
	msgbox Route117_Text_29CFFE, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3C37:: @ 81F3C37
	trainerbattle_single TRAINER_MELINA, Route117_Text_29D0B7, Route117_Text_29D0F1
	msgbox Route117_Text_29D10E, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3C4E:: @ 81F3C4E
	trainerbattle_single TRAINER_BRANDI, Route117_Text_29D14B, Route117_Text_29D189
	msgbox Route117_Text_29D196, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_1F3C65:: @ 81F3C65
	trainerbattle_single TRAINER_AISHA, Route117_Text_29D1D1, Route117_Text_29D206
	msgbox Route117_Text_29D24C, MSGBOX_AUTOCLOSE
	end

Route117_Text_1F3C7C: @ 81F3C7C
	.string "I left my POKéMON at the DAY CARE.\p"
	.string "When I got it back, it had a new move\n"
	.string "that I didn't teach it.\l"
	.string "I was really, really surprised.$"

Route117_Text_1F3CFD: @ 81F3CFD
	.string "What do you think?\n"
	.string "Aren't these flowers pretty?\p"
	.string "I planted them all!$"

Route117_Text_1F3D41: @ 81F3D41
	.string "The air is tasty here!$"

Route117_Text_1F3D58: @ 81F3D58
	.string "ROUTE 117\n"
	.string "{LEFT_ARROW} VERDANTURF TOWN$"

Route117_Text_1F3D74: @ 81F3D74
	.string "ROUTE 117\n"
	.string "{RIGHT_ARROW} MAUVILLE CITY$"

Route117_Text_1F3D8E: @ 81F3D8E
	.string "POKéMON DAY CARE\n"
	.string "“Let us raise your POKéMON.”$"

