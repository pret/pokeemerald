DesertRuins_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_OnResume
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
	.byte 0

DesertRuins_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_TryRemoveRegirock
	end

DesertRuins_EventScript_TryRemoveRegirock::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DesertRuins_OnLoad:
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
	end

DesertRuins_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

DesertRuins_OnTransition:
	setflag FLAG_LANDMARK_DESERT_RUINS
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_ShowRegirock
	end

DesertRuins_EventScript_ShowRegirock::
	clearflag FLAG_HIDE_REGIROCK
	return

DesertRuins_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
	braillemessage DesertRuins_Braille_UseRockSmash
	waitbuttonpress
	closebraillemessage
	releaseall
	end

DesertRuins_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

DesertRuins_EventScript_CaveEntranceSide::
	lockall
	braillemessage DesertRuins_Braille_UseRockSmash
	waitbuttonpress
	closebraillemessage
	releaseall
	end

DesertRuins_EventScript_Regirock::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIROCK, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIROCK, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DesertRuins_EventScript_DefeatedRegirock
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DesertRuins_EventScript_RanFromRegirock
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DesertRuins_EventScript_RanFromRegirock
	setflag FLAG_DEFEATED_REGIROCK
	release
	end

DesertRuins_EventScript_DefeatedRegirock::
	setflag FLAG_DEFEATED_REGIROCK
	goto Common_EventScript_RemoveStaticPokemon
	end

DesertRuins_EventScript_RanFromRegirock::
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto Common_EventScript_LegendaryFlewAway
	end

