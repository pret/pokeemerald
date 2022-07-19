PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Regarde-moi ce {STR_VAR_2}!\p"
	.string "Je l’ai attrapé hier pour fêter mon\n"
	.string "anniversaire!\p"
	.string "Il te plaît, on dirait!\n"
	.string "Comme je te comprends…\p"
	.string "Bon… J’accepterais peut-être\n"
	.string "de l’échanger contre un {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, c’est un {STR_VAR_1}?\p"
	.string "Ça ressemble à un {STR_VAR_2}, la\n"
	.string "différence est subtile.\p"
	.string "Merci!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Non, non et non! Un {STR_VAR_1}\n"
	.string "sinon rien!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, pas d’échange alors?\p"
	.string "Pas de problème. Je n’insiste pas.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Je sais que j’aurais pu m’en trouver un\n"
	.string "moi-même…\p"
	.string "Mais je voulais un DRABY attrapé par un\n"
	.string "autre DRESSEUR…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "C’est un POKéDEX?\p"
	.string "Tu as rencontré beaucoup de POKéMON\n"
	.string "différents?\p"
	.string "J’aimerais bien être comme toi.$"

