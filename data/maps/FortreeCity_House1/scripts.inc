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
	waitstate
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
	waitstate
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
	.string "Aaaah, j’en veux un!\n"
	.string "Il me faut un {STR_VAR_1}!\p"
	.string "Je ferais n’importe quoi pour en\n"
	.string "avoir un! C’est un vrai cri du cœur!\p"
	.string "Maintenant que tu es au courant,\n"
	.string "tu vas échanger ton {STR_VAR_1} \l"
	.string "contre un {STR_VAR_2}, n’est-ce pas?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Ouais, super!\p"
	.string "{STR_VAR_1}, bienvenue!\n"
	.string "{STR_VAR_2}, fais attention à toi!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Ah non, je ne pense pas!\n"
	.string "Ce n’est pas un {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Non? Tu ne veux pas faire d’échange?\n"
	.string "Même après que je t’ai ouvert mon cœur?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "A partir de maintenant, je vais rendre\n"
	.string "ce MUCIOLE très fort!\p"
	.string "J’espère que tu feras la même chose\n"
	.string "avec POSIPI!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Echanger des POKéMON avec d’autres…\p"
	.string "C’est comme échanger ses propres\n"
	.string "souvenirs avec quelqu’un d’autre.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZATON: Zigzaaa?$"

