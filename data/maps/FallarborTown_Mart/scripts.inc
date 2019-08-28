FallarborTown_Mart_MapScripts:: @ 81FFCBE
	.byte 0

FallarborTown_Mart_EventScript_1FFCBF:: @ 81FFCBF
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemart FallarborTown_Mart_Pokemart_1FFCD8
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart_1FFCD8: @ 81FFCD8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_1FFCF4:: @ 81FFCF4
	msgbox FallarborTown_Mart_Text_1FFD19, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_1FFCFD:: @ 81FFCFD
	msgbox FallarborTown_Mart_Text_1FFE09, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_1FFD06:: @ 81FFD06
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox FallarborTown_Mart_Text_1FFDFA, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_1FFD19: @ 81FFD19
	.string "I'm having a hard time deciding if I\n"
	.string "should make my SKITTY evolve or not.\p"
	.string "I only have to use this MOON STONE,\n"
	.string "but it's so hard to decide…\p"
	.string "If I make it evolve, it will become\n"
	.string "much stronger.\p"
	.string "But it will look so different, too.$"

FallarborTown_Mart_Text_1FFDFA: @ 81FFDFA
	.string "SKITTY: Miyao?$"

FallarborTown_Mart_Text_1FFE09: @ 81FFE09
	.string "This NUGGET I found here…\n"
	.string "I suppose I'll have to sell it, seeing\l"
	.string "as how it has no other use.$"

