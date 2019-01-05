FortreeCity_House1_MapScripts:: @ 82162BA
	.byte 0

FortreeCity_House1_EventScript_2162BB:: @ 82162BB
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_216355
	setvar VAR_0x8008, 1
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_21637B, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FortreeCity_House1_EventScript_21633D
	special sub_81B94B0
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq FortreeCity_House1_EventScript_21633D
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne FortreeCity_House1_EventScript_216347
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox FortreeCity_House1_Text_216440, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_21633D:: @ 821633D
	msgbox FortreeCity_House1_Text_21649F, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_216347:: @ 8216347
	bufferspeciesname 0, VAR_0x8009
	msgbox FortreeCity_House1_Text_216474, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_216355:: @ 8216355
	msgbox FortreeCity_House1_Text_2164DB, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_21635F:: @ 821635F
	msgbox FortreeCity_House1_Text_21653B, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_216368:: @ 8216368
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox FortreeCity_House1_Text_216597, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_21637B: @ 821637B
	.string "Wrooooaaar! I need it!\n"
	.string "I have to get me a {STR_VAR_1}!\l"
	.string "I'll do anything for it!\p"
	.string "…Uh… Did you hear that?\n"
	.string "My shout from the bottom of my heart?\p"
	.string "Having heard that, you will trade\n"
	.string "your {STR_VAR_1} for my {STR_VAR_2},\l"
	.string "won't you?$"

FortreeCity_House1_Text_216440: @ 8216440
	.string "Oh, yeah, right on!\p"
	.string "{STR_VAR_1}, welcome!\n"
	.string "{STR_VAR_2}, you take care!$"

FortreeCity_House1_Text_216474: @ 8216474
	.string "Uh, no, I don't think so.\n"
	.string "That isn't a {STR_VAR_1}.$"

FortreeCity_House1_Text_21649F: @ 821649F
	.string "No? You won't trade me?\n"
	.string "Even after I bared my heart to you?$"

FortreeCity_House1_Text_2164DB: @ 82164DB
	.string "I'm going to make VOLBEAT super\n"
	.string "strong from this moment on!\p"
	.string "I hope you do the same with PLUSLE!$"

FortreeCity_House1_Text_21653B: @ 821653B
	.string "Trading POKéMON with others…\p"
	.string "It's as if you're trading your own\n"
	.string "memories with other people.$"

FortreeCity_House1_Text_216597: @ 8216597
	.string "ZIGZAGOON: Gumomoh?$"

