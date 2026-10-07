RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hè? Is mijn POKéMON schattig?\n"
	.string "Ja, dat wist ik al.\p"
	.string "Maar als je echt wilt, wil ik hem\n"
	.string "wel met je ruilen.\p"
	.string "Ik ruil mijn {STR_VAR_2} voor\n"
	.string "een {STR_VAR_1}, als je wilt.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hihihi…\n"
	.string "Wees lief voor mijn POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hè? Dat lijkt helemaal niet op\n"
	.string "een {STR_VAR_1}.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "O, als je niet wilt, is het ook goed.\n"
	.string "Maar mijn POKéMON is wel schattig, hoor…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Elke POKéMON wordt schattig als je\n"
	.string "hem met zorg en liefde opvoedt.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Op allerlei plekken zijn allerlei\n"
	.string "POKéMON en mensen.\p"
	.string "Dat vind ik zo leuk, dus ik ga naar\n"
	.string "allerlei plekken.$"

