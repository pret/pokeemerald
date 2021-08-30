SealedChamber_OuterRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
	.byte 0

SealedChamber_OuterRoom_OnResume:
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
	end

SealedChamber_OuterRoom_OnTransition:
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_OuterRoom_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
	end

SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance::
	setmetatile 9, 1, METATILE_Cave_EntranceCover, 1
	setmetatile 10, 1, METATILE_Cave_EntranceCover, 1
	setmetatile 11, 1, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

SealedChamber_OuterRoom_EventScript_BrailleABC::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_ABC
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleGHI::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_GHI
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleMNO::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_MNO
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleTUV::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_TUV
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDEF::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_DEF
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleJKL::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_JKL
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePQRS::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_PQRS
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePeriod::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_Period
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleWXYZ::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_WXYZ
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleComma::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_Comma
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall::
	lockall
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
	braillemessage SealedChamber_OuterRoom_Braille_DigHere
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_HoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDigHere::
	lockall
	braillemessage SealedChamber_OuterRoom_Braille_DigHere
	waitbuttonpress
	closebraillemessage
	releaseall
	end

