VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Pour les combats de POKéMON, SPECIAL +\n"
	.string "est crucial.\p"
	.string "Cela permet d’augmenter la puissance de\n"
	.string "certaines attaques pendant un combat.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Je ne trouve aucun livre de stratégie\n"
	.string "sur les TENTES DE COMBAT…\p"
	.string "Peut-être qu’il faut simplement suivre\n"
	.string "son instinct, après tout…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "La FAIBLO BALL fonctionne mieux\n"
	.string "sur les POKéMON faibles.\p"
	.string "On ne peut en acheter qu’à VERGAZON.$"

