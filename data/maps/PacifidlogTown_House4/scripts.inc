PacifidlogTown_House4_MapScripts:: @ 8203F4B
	.byte 0

PacifidlogTown_House4_EventScript_203F4C:: @ 8203F4C
	msgbox PacifidlogTown_House4_Text_204017, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_203F55:: @ 8203F55
	msgbox PacifidlogTown_House4_Text_203F93, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_203F5E:: @ 8203F5E
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_204035, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PacifidlogTown_House4_EventScript_203F7F
	compare VAR_RESULT, 0
	goto_if_eq PacifidlogTown_House4_EventScript_203F89
	end

PacifidlogTown_House4_EventScript_203F7F:: @ 8203F7F
	msgbox PacifidlogTown_House4_Text_20404E, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_203F89:: @ 8203F89
	msgbox PacifidlogTown_House4_Text_204084, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_203F93: @ 8203F93
	.string "People were saying they saw a POKéMON\n"
	.string "flying high above HOENN.\p"
	.string "Is it flying around all the time?\n"
	.string "Doesn't it need to rest somewhere?$"

PacifidlogTown_House4_Text_204017: @ 8204017
	.string "A sky POKéMON!\n"
	.string "A sky POKéMON!$"

PacifidlogTown_House4_Text_204035: @ 8204035
	.string "Where did you come from?$"

PacifidlogTown_House4_Text_20404E: @ 820404E
	.string "Yes?\n"
	.string "YES TOWN?\p"
	.string "I've never heard of a place like that.$"

PacifidlogTown_House4_Text_204084: @ 8204084
	.string "No? That doesn't make any sense.\n"
	.string "You have to come from somewhere.\p"
	.string "Oh! Wait! You're not going to say you\n"
	.string "were born at the bottom of the sea?$"

