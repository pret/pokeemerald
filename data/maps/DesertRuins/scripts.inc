DesertRuins_MapScripts:: @ 822D95B
	map_script 5, DesertRuins_MapScript1_22D96B
	map_script 1, DesertRuins_MapScript1_22D989
	map_script 3, DesertRuins_MapScript1_22D9CA
	.byte 0

DesertRuins_MapScript1_22D96B: @ 822D96B
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, DesertRuins_EventScript_22D975
	end

DesertRuins_EventScript_22D975:: @ 822D975
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if 5, DesertRuins_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

DesertRuins_MapScript1_22D989: @ 822D989
	checkflag FLAG_SYS_BRAILLE_STRENGTH
	call_if 0, DesertRuins_EventScript_22D993
	end

DesertRuins_EventScript_22D993:: @ 822D993
	setmetatile 7, 19, 553, 1
	setmetatile 8, 19, 553, 1
	setmetatile 9, 19, 553, 1
	setmetatile 7, 20, 565, 1
	setmetatile 8, 20, 565, 1
	setmetatile 9, 20, 565, 1
	return

DesertRuins_MapScript1_22D9CA: @ 822D9CA
	setflag FLAG_LANDMARK_DESERT_RUINS
	checkflag FLAG_0x1BB
	call_if 0, DesertRuins_EventScript_22D9D7
	end

DesertRuins_EventScript_22D9D7:: @ 822D9D7
	clearflag FLAG_0x3A7
	return

DesertRuins_EventScript_22D9DB:: @ 822D9DB
	lockall
	checkflag FLAG_SYS_BRAILLE_STRENGTH
	goto_eq DesertRuins_EventScript_22D9EE
	braillemessage DesertRuins_Braille_2A6CA0
	waitbuttonpress
	hidebox2
	releaseall
	end

DesertRuins_EventScript_22D9EE:: @ 822D9EE
	msgbox gUnknown_0827304E, 4
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
	goto_eq DesertRuins_EventScript_22DA49
	compare VAR_RESULT, 4
	goto_eq DesertRuins_EventScript_22DA52
	compare VAR_RESULT, 5
	goto_eq DesertRuins_EventScript_22DA52
	setflag FLAG_0x1BB
	release
	end

DesertRuins_EventScript_22DA49:: @ 822DA49
	setflag FLAG_0x1BB
	goto DesertRuins_EventScript_27376D
	end

DesertRuins_EventScript_22DA52:: @ 822DA52
	setvar VAR_0x8004, 401
	goto DesertRuins_EventScript_273776
	end

