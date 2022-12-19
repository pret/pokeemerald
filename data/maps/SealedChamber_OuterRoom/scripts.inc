SealedChamber_OuterRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
	.byte 0

SealedChamber_OuterRoom_OnResume:
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
	end

SealedChamber_OuterRoom_OnTransition:
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_OuterRoom_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
	end

SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance::
	setmetatile 9, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 10, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 11, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

SealedChamber_OuterRoom_EventScript_BrailleABC::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_ABC
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleGHI::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_GHI
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleMNO::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_MNO
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleTUV::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_TUV
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDEF::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_DEF
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleJKL::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_JKL
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePQRS::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_PQRS
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePeriod::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_Period
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleWXYZ::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_WXYZ
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleComma::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_Comma
	releaseall
	end

SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall::
	lockall
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
	releaseall
	end

SealedChamber_OuterRoom_EventScript_HoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDigHere::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
	releaseall
	end

