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
	pokemartlistend

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
	.string "For any POKéMON match, X SPECIAL\n"
	.string "is crucial.\p"
	.string "It jacks up the power of some moves\n"
	.string "even though it's only for one battle.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Ze verkopen hier geen tipsboek\n"
	.string "voor de BATTLE TENT…\p"
	.string "Je moet het dus toch zelf\n"
	.string "bedenken…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "De NESTBALL werkt beter op\n"
	.string "zwakke POKéMON.\p"
	.string "Je kunt hem alleen in\n"
	.string "VERDANTURF kopen.$"

