Underwater_SealedChamber_MapScripts:: @ 82390C4
	map_script MAP_SCRIPT_ON_DIVE_WARP, Underwater_SealedChamber_OnDive
	.byte 0

Underwater_SealedChamber_OnDive: @ 82390CA
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_ne Underwater_SealedChamber_EventScript_SurfaceRoute134
	compare VAR_0x8005, 44
	goto_if_ne Underwater_SealedChamber_EventScript_SurfaceRoute134
	goto Underwater_SealedChamber_EventScript_SurfaceSealedChamber

Underwater_SealedChamber_EventScript_SurfaceRoute134:: @ 82390EA
	setdivewarp MAP_ROUTE134, 255, 60, 31
	end

Underwater_SealedChamber_EventScript_SurfaceSealedChamber:: @ 82390F3
	setdivewarp MAP_SEALED_CHAMBER_OUTER_ROOM, 255, 10, 19
	end

Underwater_SealedChamber_EventScript_Braille:: @ 82390FC
	lockall
	braillemessage Underwater_SealedChamber_Braille_GoUpHere
	waitbuttonpress
	closebraillemessage
	releaseall
	end

