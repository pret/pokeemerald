PacifidlogTown_MapScripts:: @ 81EBAB1
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_MapScript1_1EBAC0
	.byte 0

PacifidlogTown_OnTransition: @ 81EBABC
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_MapScript1_1EBAC0: @ 81EBAC0
	setstepcallback 3
	end

PacifidlogTown_EventScript_1EBAC3:: @ 81EBAC3
	msgbox PacifidlogTown_Text_1EBB6C, MSGBOX_NPC
	end

PacifidlogTown_EventScript_1EBACC:: @ 81EBACC
	msgbox PacifidlogTown_Text_1EBAE7, MSGBOX_NPC
	end

PacifidlogTown_EventScript_1EBAD5:: @ 81EBAD5
	msgbox PacifidlogTown_Text_1EBBAC, MSGBOX_NPC
	end

PacifidlogTown_EventScript_1EBADE:: @ 81EBADE
	msgbox PacifidlogTown_Text_1EBC7A, MSGBOX_SIGN
	end

PacifidlogTown_Text_1EBAE7: @ 81EBAE7
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_1EBB6C: @ 81EBB6C
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_1EBBAC: @ 81EBBAC
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_1EBC7A: @ 81EBC7A
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

