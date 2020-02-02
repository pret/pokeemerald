EventScript_FieldPoison:: @ 82736BC
	lockall
	special TryFieldPoisonWhiteOut
	waitstate
	compare VAR_RESULT, FLDPSN_WHITEOUT
	goto_if_eq EventScript_FieldWhiteOut
	compare VAR_RESULT, FLDPSN_FRONTIER_WHITEOUT
	goto_if_eq EventScript_FrontierFieldWhiteOut
	releaseall
	end

EventScript_FieldWhiteOut:: @ 82736D9
	message gText_PlayerWhitedOut
	waitmessage
	waitbuttonpress
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, EventScript_SetRespawnLavaridgePkmnCenter
	special SetCB2WhiteOut
	waitstate
	end

EventScript_SetRespawnLavaridgePkmnCenter:: @ 82736F4
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	return

EventScript_FrontierFieldWhiteOut:: @ 82736F8
	message gText_PlayerWhitedOut
	waitmessage
	waitbuttonpress
	pike_inchallenge
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePike_EventScript_Retire
	pyramid_inchallenge
	compare VAR_RESULT, 1  @ On Pyramid floor
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	compare VAR_RESULT, 2  @ On Pyramid peak
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	trainerhill_inchallenge
	compare VAR_RESULT, TRUE
	goto_if_eq TrainerHill_1F_EventScript_Lost
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end
