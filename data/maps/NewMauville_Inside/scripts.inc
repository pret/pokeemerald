NewMauville_Inside_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
	.byte 0

NewMauville_Inside_OnResume:
	compare VAR_TEMP_1, 1
	call_if_eq NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	compare VAR_TEMP_2, 1
	call_if_eq NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
	end

NewMauville_Inside_EventScript_TryRemoveVoltorb::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMauville_Inside_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
	end

NewMauville_Inside_EventScript_ShowVoltorb1::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
	return

NewMauville_Inside_EventScript_ShowVoltorb2::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
	return

NewMauville_Inside_EventScript_ShowVoltorb3::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
	return

NewMauville_Inside_OnLoad:
	compare VAR_NEW_MAUVILLE_STATE, 2
	call_if_eq NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	end

NewMauville_Inside_EventScript_BlueButton::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_GreenButton::
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, 0
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, 0
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, 0
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, 0
	return

NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, 1
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, 1
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, 1
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, 1
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, 1
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, 1
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, 1
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, 1
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, 1
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, 0
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, 0
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, 0
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, 0
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, 0
	return

NewMauville_Inside_EventScript_RedButton::
	lockall
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	setvar VAR_NEW_MAUVILLE_STATE, 2
	releaseall
	end

NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, 1
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, 1
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, 1
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, 1
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, 1
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, 1
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, 1
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, 1
	special DrawWholeMapView
	return

NewMauville_Inside_EventScript_Generator::
	lockall
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_eq NewMauville_Inside_EventScript_GeneratorOff
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_GeneratorOff::
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_Voltorb1::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25, ITEM_NONE
	waitse
	playmoncry SPECIES_VOLTORB, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb1::
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb2::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25, ITEM_NONE
	waitse
	playmoncry SPECIES_VOLTORB, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb2::
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb3::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25, ITEM_NONE
	waitse
	playmoncry SPECIES_VOLTORB, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb3::
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_Text_GeneratorRadiatingHeat:
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off\n"
	.string "as soon as possible.$"

NewMauville_Inside_Text_GeneratorQuietedDown:
	.string "The generator quieted down.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "The generator appears to have\n"
	.string "stopped…$"
