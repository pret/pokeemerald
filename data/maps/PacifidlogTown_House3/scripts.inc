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
	.string "Kijk eens naar deze {STR_VAR_2}!\p"
	.string "Ik ving de {STR_VAR_2} gisteren\n"
	.string "voor mijn verjaardag!\p"
	.string "Oh, ik zie dat je hem wilt!\n"
	.string "Hij is dan ook onbetaalbaar!\p"
	.string "Weet je wat. Misschien ruil ik hem\n"
	.string "wel voor een {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, dit is dus een {STR_VAR_1}?\p"
	.string "Hij lijkt op een {STR_VAR_2},\n"
	.string "maar is toch een beetje anders.\p"
	.string "Bedankt!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Nee, nee, nee! Ik neem niet minder\n"
	.string "dan een echte {STR_VAR_1}!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, dus je doet het niet?\p"
	.string "Prima. Ik ben niet wanhopig om\n"
	.string "te ruilen of zo.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Ik kan er zelf wel een zoeken,\n"
	.string "maar…\p"
	.string "Ik wilde echt een BAGON die een\n"
	.string "ander TRAINER ving…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Is dat een POKéDEX?\p"
	.string "Heb je veel verschillende\n"
	.string "POKéMON ontmoet?\p"
	.string "Ik wou dat ik zoals jij was.$"

