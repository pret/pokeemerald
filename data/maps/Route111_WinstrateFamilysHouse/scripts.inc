.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "C’est la première fois que je vois un\n"
	.string "DRESSEUR qui maîtrise aussi bien\l"
	.string "ses POKéMON.\p"
	.string "Mais il vaut mieux que je te prévienne,\n"
	.string "mon fils est plus fort que toi.\p"
	.string "Il a même relevé le défi de la LIGUE\n"
	.string "POKéMON, j’te signale.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Nous utilisons ce BRAC. MACHO\n"
	.string "pour améliorer l’entraînement\l"
	.string "de nos POKéMON.\p"
	.string "Je ne sais pas si tu en auras besoin,\n"
	.string "mais comme tu nous as tous battus ici,\l"
	.string "nous t’offrons notre BRAC. MACHO.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Lorsqu’on parle de combats de POKéMON,\n"
	.string "on est souvent très passionnés.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Maman est plus forte que papa.\p"
	.string "Je suis plus forte que maman.\p"
	.string "Et mémé est plus forte que moi!\p"
	.string "Mais mon grand frère est encore plus\n"
	.string "fort que mémé.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Aucun doute, tu es très robuste.\p"
	.string "Mais si tu te mesurais à mon petit-fils,\n"
	.string "tu pleurerais comme un bébé.\p"
	.string "Notre famille n’a jamais vu un DRESSEUR\n"
	.string "aussi fort que lui.\p"
	.string "En ce moment, il doit défier le MAITRE\n"
	.string "de la LIGUE POKéMON.\p"
	.string "Tel que je connais mon petit-fils, il est\n"
	.string "peut-être déjà le MAITRE!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "En ce moment, mon petit-fils doit défier\n"
	.string "le MAITRE de la LIGUE POKéMON.\p"
	.string "Tel que je le connais, il est\n"
	.string "peut-être déjà le MAITRE!$"

