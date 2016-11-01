	.align 1
gPickupItems:: @ 831C440
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_X_ATTACK
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_PROTEIN
	.2byte ITEM_REVIVE
	.2byte ITEM_HP_UP
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_PP_UP
	.2byte ITEM_MAX_ELIXIR

	.align 1
gRarePickupItems:: @ 831C464
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_NUGGET
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ETHER
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_TM44
	.2byte ITEM_ELIXIR
	.2byte ITEM_TM01
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_TM26

gPickupProbabilities:: @ 831C47A
	.byte 30
	.byte 40
	.byte 50
	.byte 60
	.byte 70
	.byte 80
	.byte 90
	.byte 94
	.byte 98
