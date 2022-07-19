MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM06, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	setflag FLAG_RECEIVED_HM06
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woahou!\p"
	.string "Les gens m’appellent le TYPE\n"
	.string "ECLATE-ROC, mais je n’aime pas trop ça.\p"
	.string "Je crois que je mérite un surnom\n"
	.string "plus flatteur, comme le MEC\l"
	.string "ECLATE-ROC par exemple.\p"
	.string "Woahou!\p"
	.string "Quoi qu’il en soit, ton POKéMON semble\n"
	.string "plutôt fort.\p"
	.string "J’aime ça!\n"
	.string "Tiens, prends cette CS!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Cette CS contient ECLATE-ROC.\p"
	.string "Si tu te trouves face à de gros blocs\n"
	.string "de pierre bloquant le passage…\p"
	.string "Eh bien, utilise l’attaque de cette CS\n"
	.string "et pulvérise-les!\p"
	.string "Ouaip! Eclate-les carrément!\n"
	.string "Woahou!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, oui! Si tu détruis une pierre,\n"
	.string "un POKéMON peut en surgir.\p"
	.string "Woahou!$"

