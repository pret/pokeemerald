BattleFrontier_Lounge6_MapScripts:: @ 8264FEC
	.byte 0

BattleFrontier_Lounge6_EventScript_264FED:: @ 8264FED
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_265083
	setvar VAR_0x8008, 3
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_26508D, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge6_EventScript_26506B
	special sub_81B94B0
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge6_EventScript_26506B
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne BattleFrontier_Lounge6_EventScript_265075
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_265128, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_26506B:: @ 826506B
	msgbox BattleFrontier_Lounge6_Text_2651CB, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_265075:: @ 8265075
	bufferspeciesname 0, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_26518D, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_265083:: @ 8265083
	msgbox BattleFrontier_Lounge6_Text_26520E, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_26508D: @ 826508D
	.string "My POKéMON is a {STR_VAR_2}.\n"
	.string "Do you know it?\l"
	.string "It's quite cute and rather nice.\p"
	.string "This little one, I could trade with\n"
	.string "pride!\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_265128: @ 8265128
	.string "Oh, it's adorable!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"

BattleFrontier_Lounge6_Text_26518D: @ 826518D
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_2651CB: @ 82651CB
	.string "Oh, you won't?\n"
	.string "Well, that's fine, too.\l"
	.string "Please come visit us again.$"

BattleFrontier_Lounge6_Text_26520E: @ 826520E
	.string "Giggle!\n"
	.string "A SKITTY is so much cuter than I had\l"
	.string "imagined. I'm delighted!$"
