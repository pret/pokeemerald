EventScript_TV:: @ 827EE0B
	lockall
	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForBigMovieOrEmergencyNewsOnTV
	compare VAR_RESULT, 2
	goto_if_eq EventScript_27EE9A
	compare VAR_RESULT, 1
	goto_if_eq EventScript_27EEA4
	goto_if_unset FLAG_SYS_TV_START, EventScript_27EE8A
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_27EE8A
	specialvar VAR_RESULT, IsTVShowInSearchOfTrainersAiring
	compare VAR_RESULT, 1
	goto_if_eq EventScript_27EEFF
	goto EventScript_27EEE9
	end

EventScript_27EE54:: @ 827EE54
	specialvar VAR_0x8004, special_0x44
	compare VAR_0x8004, 255
	goto_if_eq EventScript_27EED8
	specialvar VAR_RESULT, special_0x4a
	compare VAR_RESULT, 255
	goto_if_eq EventScript_27EED8
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, special_0x45
	compare VAR_RESULT, 0
	goto_if_ne EventScript_27EEBA
	end

EventScript_27EE8A:: @ 827EE8A
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_27EE9A:: @ 827EE9A
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7F0F, MSGBOX_DEFAULT
	releaseall
	end

EventScript_27EEA4:: @ 827EEA4
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F826F, MSGBOX_DEFAULT
	@ This is a junk call. Its input var (VAR_0x8004) hasn't been set, and
	@ It's called again when Mom actually asks for the color, overwriting
	@ whatever it does here.
	special InitRoamer
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	releaseall
	end

EventScript_27EEBA:: @ 827EEBA
	special DoTVShow
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 1
	goto_if_ne EventScript_27EEBA
	goto EventScript_27EED0
	end

EventScript_27EED0:: @ 827EED0
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_27EED8:: @ 827EED8
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	goto EventScript_27EED0
	end

EventScript_27EEE9:: @ 827EEE9
	special DoPokeNews
	compare VAR_RESULT, 0
	goto_if_eq EventScript_27EE54
	waitmessage
	waitbuttonpress
	goto EventScript_27EED0
	end

EventScript_27EEFF:: @ 827EEFF
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 0
	goto_if_eq EventScript_27EEFF
	goto EventScript_27EED0
	end
