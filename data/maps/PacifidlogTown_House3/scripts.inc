PacifidlogTown_House3_MapScripts:: @ 8203C10
	.byte 0

PacifidlogTown_House3_EventScript_203C11:: @ 8203C11
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_203CAB
	setvar VAR_0x8008, 2
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_203CBE, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq PacifidlogTown_House3_EventScript_203C93
	special sub_81B94B0
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq PacifidlogTown_House3_EventScript_203C93
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne PacifidlogTown_House3_EventScript_203C9D
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_203D87, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_203C93:: @ 8203C93
	msgbox PacifidlogTown_House3_Text_203E12, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_203C9D:: @ 8203C9D
	bufferspeciesname 0, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_203DDE, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_203CAB:: @ 8203CAB
	msgbox PacifidlogTown_House3_Text_203E7F, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_203CB5:: @ 8203CB5
	msgbox PacifidlogTown_House3_Text_203EF1, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_203CBE: @ 8203CBE
	.string "Check out this {STR_VAR_2}!\p"
	.string "It's the {STR_VAR_2} that I caught\n"
	.string "yesterday to celebrate my birthday!\p"
	.string "Oh, I can see that you want it!\n"
	.string "After all, it's priceless!\p"
	.string "I'll tell you what. I might be willing\n"
	.string "to trade it for a {STR_VAR_1}.$"

PacifidlogTown_House3_Text_203D87: @ 8203D87
	.string "Oh, so this is a {STR_VAR_1}?\p"
	.string "It's sort of like a {STR_VAR_2},\n"
	.string "and yet it's subtly different.\p"
	.string "Thank you!$"

PacifidlogTown_House3_Text_203DDE: @ 8203DDE
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

PacifidlogTown_House3_Text_203E12: @ 8203E12
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

PacifidlogTown_House3_Text_203E7F: @ 8203E7F
	.string "I know I could go looking for one\n"
	.string "on my own, but…\p"
	.string "But I really wanted to get a BAGON\n"
	.string "that another TRAINER caught…$"

PacifidlogTown_House3_Text_203EF1: @ 8203EF1
	.string "Is that a POKéDEX?\p"
	.string "Did you get to meet a lot of different\n"
	.string "POKéMON?\p"
	.string "I wish I was like you.$"

