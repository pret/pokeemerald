FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wroooaaar! Ik wil hem!\n"
	.string "Ik moet een {STR_VAR_1} hebben!\l"
	.string "Ik doe alles ervoor!\p"
	.string "…Eh… Hoorde je dat?\n"
	.string "Mijn kreet uit het diepst van mijn hart?\p"
	.string "Nu je dat hoorde, ruil je je\n"
	.string "{STR_VAR_1} toch voor mijn {STR_VAR_2}?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh ja, top!\p"
	.string "{STR_VAR_1}, welkom!\n"
	.string "{STR_VAR_2}, pas goed op jezelf!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Eh, nee, dat denk ik niet.\n"
	.string "Dat is geen {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Nee? Ruil je niet met me?\n"
	.string "Terwijl ik mijn hart voor je opende?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Vanaf nu maak ik VOLBEAT super\n"
	.string "sterk!\p"
	.string "Houd jij PLUSLE ook sterk!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "POKéMON ruilen met anderen…\p"
	.string "Het is alsof je je eigen\n"
	.string "herinneringen ruilt.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

