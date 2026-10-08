Route110_TrickHousePuzzle7_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle7_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle7_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle7_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHousePuzzle7_OnFrame
	.byte 0

@ Puzzle Room 7 in RSE uses whatever puzzle Mossdeep Gym uses
@ Because Mossdeep Gym was redesigned for Emerald, theres a good deal of leftover script from the old R/S puzzle

Route110_TrickHousePuzzle7_OnResume:
	call Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles
	end

Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles::
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn
	return

@ Leftover from R/S, none of the below metatile scripts are ever called
Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn::
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, FALSE
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn::
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, FALSE
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn::
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, FALSE
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn::
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right_Alt, FALSE
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn::
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, FALSE
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOff::
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, FALSE
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOff::
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, FALSE
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOff::
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, FALSE
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOff::
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left_Alt, FALSE
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOff::
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right, FALSE
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_OnTransition:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_TeleportedTransition
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	end

Route110_TrickHousePuzzle7_EventScript_TeleportedTransition::
	end

Route110_TrickHousePuzzle7_OnLoad:
	call_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles
	end

Route110_TrickHousePuzzle7_OnFrame:
	map_script_2 VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_ClearState2
	.2byte 0

Route110_TrickHousePuzzle7_EventScript_ClearState2::
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 0
	end

Route110_TrickHousePuzzle7_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle7_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle7_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

@ Unused, leftover from R/S
Route110_TrickHousePuzzle7_EventScript_TeleportPad::
	lockall
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	warpteleport MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 3, 19
	waitstate
	releaseall
	end

@ All the below switch scripts are unused leftover from R/S
Route110_TrickHousePuzzle7_EventScript_Switch1::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch2::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch3::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch4::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch5::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5Off
	end

@ All the below switch scripts are unused leftover from R/S
Route110_TrickHousePuzzle7_EventScript_SetSwitch1On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch1Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch2On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch2Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch3On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch3Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch4On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch4Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch5On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch5Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

@ From here is where the new, actually used puzzle scripts begin
Route110_TrickHousePuzzle7_EventScript_YellowButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 0
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_BlueButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 1
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_GreenButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 2
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_PurpleButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 3
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

@ Unused
Route110_TrickHousePuzzle7_EventScript_RedButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 4
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA, Route110_TrickHousePuzzle7_Text_JoshuaIntro, Route110_TrickHousePuzzle7_Text_JoshuaDefeat
	msgbox Route110_TrickHousePuzzle7_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Patricia::
	trainerbattle_single TRAINER_PATRICIA, Route110_TrickHousePuzzle7_Text_PatriciaIntro, Route110_TrickHousePuzzle7_Text_PatriciaDefeat
	msgbox Route110_TrickHousePuzzle7_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Alexis::
	trainerbattle_single TRAINER_ALEXIS, Route110_TrickHousePuzzle7_Text_AlexisIntro, Route110_TrickHousePuzzle7_Text_AlexisDefeat
	msgbox Route110_TrickHousePuzzle7_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Mariela::
	trainerbattle_single TRAINER_MARIELA, Route110_TrickHousePuzzle7_Text_MarielaIntro, Route110_TrickHousePuzzle7_Text_MarielaDefeat
	msgbox Route110_TrickHousePuzzle7_Text_MarielaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Alvaro::
	trainerbattle_single TRAINER_ALVARO, Route110_TrickHousePuzzle7_Text_AlvaroIntro, Route110_TrickHousePuzzle7_Text_AlvaroDefeat
	msgbox Route110_TrickHousePuzzle7_Text_AlvaroPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_EventScript_Everett::
	trainerbattle_single TRAINER_EVERETT, Route110_TrickHousePuzzle7_Text_EverettIntro, Route110_TrickHousePuzzle7_Text_EverettDefeat
	msgbox Route110_TrickHousePuzzle7_Text_EverettPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} schrijft de geheime code\n"
	.string "op de deur.\p"
	.string "“TRICK MASTER is knuffelbaar.”\n"
	.string "… … … … … … … …\p"
	.string "Klik! Het slot gaat open!$"

Route110_TrickHousePuzzle7_Text_JoshuaIntro:
	.string "De TRICK MASTER verdwijnt altijd\n"
	.string "als rook. Hoe doet hij dat?$"

Route110_TrickHousePuzzle7_Text_JoshuaDefeat:
	.string "Aaah! Je bent veel te sterk!\n"
	.string "Hoe doe je dat?$"

Route110_TrickHousePuzzle7_Text_JoshuaPostBattle:
	.string "Ik wil ook verschijnen en verdwijnen\n"
	.string "als rook.$"

Route110_TrickHousePuzzle7_Text_PatriciaIntro:
	.string "Steeds rondjes om dezelfde plek…\n"
	.string "Dat brengt ongeluk…$"

Route110_TrickHousePuzzle7_Text_PatriciaDefeat:
	.string "Verslagen!\n"
	.string "Dat is een slecht teken…$"

Route110_TrickHousePuzzle7_Text_PatriciaPostBattle:
	.string "Ik heb al meer dan tien keer rond\n"
	.string "deze plek gelopen… Dat is ongeluk…$"

Route110_TrickHousePuzzle7_Text_AlexisIntro:
	.string "Wie wint, komt hier als eerste\n"
	.string "door. Dat gevoel heb ik.$"

Route110_TrickHousePuzzle7_Text_AlexisDefeat:
	.string "Oh!\n"
	.string "Nou, ga je gang dan!$"

Route110_TrickHousePuzzle7_Text_AlexisPostBattle:
	.string "Jij lost alle puzzels in het\n"
	.string "TRICK HOUSE op. Dat gevoel heb ik.$"

Route110_TrickHousePuzzle7_Text_MarielaIntro:
	.string "Nufufufu, eindelijk!\n"
	.string "Laten we meteen beginnen!$"

Route110_TrickHousePuzzle7_Text_MarielaDefeat:
	.string "Jij wint alsof het niks is!$"

Route110_TrickHousePuzzle7_Text_MarielaPostBattle:
	.string "Hmpf! Ik ben niet boos!\n"
	.string "Ik niet!$"

Route110_TrickHousePuzzle7_Text_AlvaroIntro:
	.string "Ik zag je heel goed aankomen!$"

Route110_TrickHousePuzzle7_Text_AlvaroDefeat:
	.string "Dit zag ik niet aankomen…$"

Route110_TrickHousePuzzle7_Text_AlvaroPostBattle:
	.string "Nou ja, we kozen allebei een rare\n"
	.string "plek om elkaar te leren kennen.\p"
	.string "Van de ene gekke naar de andere:\n"
	.string "laten we ons best doen!$"

Route110_TrickHousePuzzle7_Text_EverettIntro:
	.string "Het is hier wel heel krap…$"

Route110_TrickHousePuzzle7_Text_EverettDefeat:
	.string "Oh ja, sterk ben jij.$"

Route110_TrickHousePuzzle7_Text_EverettPostBattle:
	.string "Ik hoopte met je te ruilen van\n"
	.string "plek als ik won, maar…$"

