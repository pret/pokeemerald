EventScript_UseSurf:: @ 8271EA0
	checkpartymove MOVE_SURF
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantSurf
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CancelSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF

EventScript_CancelSurf:: @ 8271ED5
	releaseall

EventScript_CantSurf:: @ 8271ED6
	end
