AquaHideout_B1F_MapScripts:: @ 82339A7
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_MapScript1_2339B2
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_MapScript1_2339B2: @ 82339B2
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_2339BC
	end

AquaHideout_B1F_EventScript_2339BC:: @ 82339BC
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition: @ 82339D0
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_2339E3
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_2339E7
	end

AquaHideout_B1F_EventScript_2339E3:: @ 82339E3
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_2339E7:: @ 82339E7
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_2339EB:: @ 82339EB
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq AquaHideout_B1F_EventScript_233A2F
	compare VAR_RESULT, 4
	goto_if_eq AquaHideout_B1F_EventScript_233A2F
	compare VAR_RESULT, 5
	goto_if_eq AquaHideout_B1F_EventScript_233A2F
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_233A2F:: @ 8233A2F
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_233A38:: @ 8233A38
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq AquaHideout_B1F_EventScript_233A7C
	compare VAR_RESULT, 4
	goto_if_eq AquaHideout_B1F_EventScript_233A7C
	compare VAR_RESULT, 5
	goto_if_eq AquaHideout_B1F_EventScript_233A7C
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_233A7C:: @ 8233A7C
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_233A85:: @ 8233A85
	trainerbattle_single TRAINER_GRUNT_2, AquaHideout_B1F_Text_233B03, AquaHideout_B1F_Text_233B4A, AquaHideout_B1F_EventScript_233AA0
	msgbox AquaHideout_B1F_Text_233B5E, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_233AA0:: @ 8233AA0
	special sub_80B4808
	waitmovement 0
	msgbox AquaHideout_B1F_Text_233B5E, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_233AB0:: @ 8233AB0
	trainerbattle_single TRAINER_GRUNT_3, AquaHideout_B1F_Text_233BC5, AquaHideout_B1F_Text_233C27, AquaHideout_B1F_EventScript_233ACB
	msgbox AquaHideout_B1F_Text_233C41, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_233ACB:: @ 8233ACB
	msgbox AquaHideout_B1F_Text_233C41, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_233AD5:: @ 8233AD5
	trainerbattle_single TRAINER_GRUNT_21, AquaHideout_B1F_Text_233C89, AquaHideout_B1F_Text_233CCA
	msgbox AquaHideout_B1F_Text_233CDC, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_233AEC:: @ 8233AEC
	trainerbattle_single TRAINER_GRUNT_25, AquaHideout_B1F_Text_233D1B, AquaHideout_B1F_Text_233D6E
	msgbox AquaHideout_B1F_Text_233D84, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_233B03: @ 8233B03
	.string "If you want to know the secret about\n"
	.string "our HIDEOUT, you have me to beat!$"

AquaHideout_B1F_Text_233B4A: @ 8233B4A
	.string "I can't win at all…$"

AquaHideout_B1F_Text_233B5E: @ 8233B5E
	.string "Our HIDEOUT's secret?\p"
	.string "Well, let's just say…\n"
	.string "There's a submarine at the far end!\p"
	.string "But, by now…\n"
	.string "Kekekeke…$"

AquaHideout_B1F_Text_233BC5: @ 8233BC5
	.string "Fuel supply loaded A-OK!\n"
	.string "In-cruise snacks loaded A-OK!\p"
	.string "Nothing left to do but KO a pesky\n"
	.string "meddler!$"

AquaHideout_B1F_Text_233C27: @ 8233C27
	.string "I took a serious licking!$"

AquaHideout_B1F_Text_233C41: @ 8233C41
	.string "Humph!\n"
	.string "This was supposed to happen!\p"
	.string "My mission was to just hold you up!$"

AquaHideout_B1F_Text_233C89: @ 8233C89
	.string "Yawn… Keeping watch over the\n"
	.string "HIDEOUT bores me. I'll take you on.$"

AquaHideout_B1F_Text_233CCA: @ 8233CCA
	.string "Yawn…\n"
	.string "Oh, I lost…$"

AquaHideout_B1F_Text_233CDC: @ 8233CDC
	.string "If you scurry too much, other TEAM\n"
	.string "AQUA members might get you.$"

AquaHideout_B1F_Text_233D1B: @ 8233D1B
	.string "Hey!\n"
	.string "You there!\p"
	.string "Which do you think is cooler?\n"
	.string "TEAM AQUA's uniform or TEAM MAGMA's?$"

AquaHideout_B1F_Text_233D6E: @ 8233D6E
	.string "I lost in a cool way…$"

AquaHideout_B1F_Text_233D84: @ 8233D84
	.string "If you have a cool uniform, you look\n"
	.string "good even in a loss, don't you think?$"
