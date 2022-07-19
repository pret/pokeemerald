FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPEREPOUSSE dure longtemps et\n"
	.string "fait tout le boulot.\p"
	.string "C’est plus efficace qu’un REPOUSSE\n"
	.string "ordinaire.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Je prends toujours plus d’objets qu’il\n"
	.string "ne m’en faut réellement.\p"
	.string "On ne sait jamais ce qui peut arriver.\n"
	.string "Mieux vaut prévenir que guérir!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "Un SUPER BONBON fait automatiquement\n"
	.string "monter un POKéMON d’un niveau.$"

