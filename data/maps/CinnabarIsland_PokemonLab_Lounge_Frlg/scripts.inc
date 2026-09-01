CinnabarIsland_PokemonLab_Lounge_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_Lounge_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_FoundFossilInMtMoon, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_Clifton::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_ELECTRODE
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_ESPHERE_TRADE, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonAlreadyTraded
	msgbox Trade_Text_DoYouHaveMonWouldYouTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonDeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonDeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonNotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_Thanks
	setflag FLAG_DID_ESPHERE_TRADE
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonDeclineTrade::
	msgbox Trade_Text_WellIfYouDontWantTo
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_ThisIsntMon
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonAlreadyTraded::
	msgbox Trade_Text_HasTradedMonGrownStronger
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_Norma::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_TANGELA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_DID_TANGENY_TRADE, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaAlreadyTraded
	msgbox Trade_Text_DoYouHaveMonWantToTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaDeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaDeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaNotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox Trade_Text_ThanksYoureAPal
	setflag FLAG_DID_TANGENY_TRADE
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_NormaDeclineTrade::
	msgbox Trade_Text_ThatsTooBad
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_NormaNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_ThisIsNoMon
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_NormaAlreadyTraded::
	msgbox Trade_Text_HowIsMyOldMon
	release
	end

CinnabarIsland_PokemonLab_Lounge_Text_FoundFossilInMtMoon::
	.string "I found this most remarkable fossil\n"
	.string "inside MT. MOON.\p"
	.string "I think it's of a rare, prehistoric\n"
	.string "POKéMON.$"

