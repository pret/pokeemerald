SealedChamber_InnerRoom_MapScripts:: @ 82391F7
	.byte 0

SealedChamber_InnerRoom_EventScript_BrailleBackWall:: @ 82391F8
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
	waitbuttonpress
	closebraillemessage
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
	specialvar VAR_RESULT, CheckRelicanthWailord
	compare VAR_RESULT, FALSE
	goto_if_eq SealedChamber_InnerRoom_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect:: @ 8239253
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1:: @ 8239255
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2:: @ 823925F
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3:: @ 8239269
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4:: @ 8239273
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_WeFearedIt
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5:: @ 823927D
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6:: @ 8239287
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	waitbuttonpress
	closebraillemessage
	releaseall
	end

