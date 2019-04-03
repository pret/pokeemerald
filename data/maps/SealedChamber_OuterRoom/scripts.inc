SealedChamber_OuterRoom_MapScripts:: @ 8239106
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_MapScript1_239116
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_MapScript1_23912B
	.byte 0

SealedChamber_OuterRoom_MapScript1_239116: @ 8239116
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
	end

SealedChamber_OuterRoom_OnTransition: @ 8239127
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_OuterRoom_MapScript1_23912B: @ 823912B
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_239135
	end

SealedChamber_OuterRoom_EventScript_239135:: @ 8239135
	setmetatile 9, 1, 553, 1
	setmetatile 10, 1, 553, 1
	setmetatile 11, 1, 553, 1
	setmetatile 9, 2, 565, 1
	setmetatile 10, 2, 565, 1
	setmetatile 11, 2, 565, 1
	return

SealedChamber_OuterRoom_EventScript_23916C:: @ 823916C
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B27
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_239176:: @ 8239176
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B31
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_239180:: @ 8239180
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B3B
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_23918A:: @ 823918A
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B45
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_239194:: @ 8239194
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B4F
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_23919E:: @ 823919E
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B59
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391A8:: @ 82391A8
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B63
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391B2:: @ 82391B2
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B6E
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391BC:: @ 82391BC
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B76
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391C6:: @ 82391C6
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B81
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391D0:: @ 82391D0
	lockall
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_2391E3
	braillemessage SealedChamber_OuterRoom_Braille_2A6B89
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391E3:: @ 82391E3
	msgbox gUnknown_0827304E, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_OuterRoom_EventScript_2391ED:: @ 82391ED
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_2A6B89
	waitbuttonpress
	hidebox2
	releaseall
	end

