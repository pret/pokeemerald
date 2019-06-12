DesertRuins_MapScripts:: @ 822D95B
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_MapScript1_22D96B
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_MapScript1_22D989
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
	.byte 0

DesertRuins_MapScript1_22D96B: @ 822D96B
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_22D975
	end

DesertRuins_EventScript_22D975:: @ 822D975
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DesertRuins_MapScript1_22D989: @ 822D989
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_22D993
	end

DesertRuins_EventScript_22D993:: @ 822D993
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

DesertRuins_OnTransition: @ 822D9CA
	setflag FLAG_LANDMARK_DESERT_RUINS
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_22D9D7
	end

DesertRuins_EventScript_22D9D7:: @ 822D9D7
	clearflag FLAG_HIDE_REGIROCK
	return

DesertRuins_EventScript_22D9DB:: @ 822D9DB
	lockall
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_22D9EE
	braillemessage DesertRuins_Braille_2A6CA0
	waitbuttonpress
	hidebox2
	releaseall
	end

DesertRuins_EventScript_22D9EE:: @ 822D9EE
	msgbox gUnknown_0827304E, MSGBOX_DEFAULT
	releaseall
	end

DesertRuins_EventScript_22D9F8:: @ 822D9F8
	lockall
	braillemessage DesertRuins_Braille_2A6CA0
	waitbuttonpress
	hidebox2
	releaseall
	end

DesertRuins_EventScript_22DA02:: @ 822DA02
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
	compare VAR_RESULT, 1
	goto_if_eq DesertRuins_EventScript_22DA49
	compare VAR_RESULT, 4
	goto_if_eq DesertRuins_EventScript_22DA52
	compare VAR_RESULT, 5
	goto_if_eq DesertRuins_EventScript_22DA52
	setflag FLAG_DEFEATED_REGIROCK
	release
	end

DesertRuins_EventScript_22DA49:: @ 822DA49
	setflag FLAG_DEFEATED_REGIROCK
	goto DesertRuins_EventScript_27376D
	end

DesertRuins_EventScript_22DA52:: @ 822DA52
	setvar VAR_0x8004, 401
	goto DesertRuins_EventScript_273776
	end

