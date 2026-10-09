BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applywaitmovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "We zijn hier als begeleiders van\n"
	.string "onze kleinzoon.\p"
	.string "Maar nu we er toch zijn, nemen we\n"
	.string "wat souvenirs mee.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Schat, wat vind je hiervan?\n"
	.string "Is dit niet een leuk cadeau?\p"
	.string "Het is…PRO…TE…ÏNE?\n"
	.string "Dat klinkt lekker, hè?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "In veel gebouwen van de BATTLE\n"
	.string "FRONTIER mag je geen voorwerpen\l"
	.string "gebruiken in gevechten.\p"
	.string "Dat maakt het nog moeilijker!$"

