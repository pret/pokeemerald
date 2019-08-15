SealedChamber_InnerRoom_MapScripts:: @ 82391F7
	.byte 0

SealedChamber_InnerRoom_EventScript_2391F8:: @ 82391F8
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6B99
	waitbuttonpress
	hidebox2
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_239253
	specialvar VAR_RESULT, CheckRelicanthWailord
	compare VAR_RESULT, 0
	goto_if_eq SealedChamber_InnerRoom_EventScript_239253
	fadeoutbgm 0
	playse SE_TRACK_MOVE
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

SealedChamber_InnerRoom_EventScript_239253:: @ 8239253
	releaseall
	end

SealedChamber_InnerRoom_EventScript_239255:: @ 8239255
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6BCA
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_InnerRoom_EventScript_23925F:: @ 823925F
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6BEC
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_InnerRoom_EventScript_239269:: @ 8239269
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6C0D
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_InnerRoom_EventScript_239273:: @ 8239273
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6C34
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_InnerRoom_EventScript_23927D:: @ 823927D
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6C48
	waitbuttonpress
	hidebox2
	releaseall
	end

SealedChamber_InnerRoom_EventScript_239287:: @ 8239287
	lockall
	braillemessage SealedChamber_InnerRoom_Braille_2A6C73
	waitbuttonpress
	hidebox2
	releaseall
	end

