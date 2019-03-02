Underwater_SealedChamber_MapScripts:: @ 82390C4
	map_script MAP_SCRIPT_ON_DIVE_WARP, Underwater_SealedChamber_MapScript1_2390CA
	.byte 0

Underwater_SealedChamber_MapScript1_2390CA: @ 82390CA
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_ne Underwater_SealedChamber_EventScript_2390EA
	compare VAR_0x8005, 44
	goto_if_ne Underwater_SealedChamber_EventScript_2390EA
	goto Underwater_SealedChamber_EventScript_2390F3

Underwater_SealedChamber_EventScript_2390EA:: @ 82390EA
	setdivewarp MAP_ROUTE134, 255, 60, 31
	end

Underwater_SealedChamber_EventScript_2390F3:: @ 82390F3
	setdivewarp MAP_SEALED_CHAMBER_OUTER_ROOM, 255, 10, 19
	end

Underwater_SealedChamber_EventScript_2390FC:: @ 82390FC
	lockall
	braillemessage Underwater_SealedChamber_Braille_2A6B15
	waitbuttonpress
	hidebox2
	releaseall
	end

