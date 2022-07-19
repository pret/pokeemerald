FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM27
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. KOSMO: Oh…\n"
	.string "Je n’aurais jamais dû me laisser rouler\l"
	.string "dans la farine et avouer à la TEAM MAGMA\l"
	.string "où on peut trouver des METEORITES…\p"
	.string "Ce METEORITE du SITE METEORE…\n"
	.string "Il ne sera jamais à moi, maintenant…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Hein?\p"
	.string "Mais, cet objet…\p"
	.string "C’est impossible!?!\p"
	.string "Est-ce le METEORITE que la TEAM\n"
	.string "MAGMA a pris au SITE METEORE?\p"
	.string "S’il te plaît, tu peux me le donner?\p"
	.string "Je suis prêt à te l’échanger contre un\n"
	.string "objet de valeur. Que dirais-tu d’une CT?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. KOSMO: Cette CT est le symbole\n"
	.string "de ma gratitude à ton égard.\p"
	.string "N’hésite pas à l’utiliser!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. KOSMO: Oh, je n’arrive pas à\n"
	.string "y croire. C’est vraiment super génial!\p"
	.string "Ça va faire avancer mes recherches!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. KOSMO: Oh, mais…\n"
	.string "Je suis extrêmement déçu…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. KOSMO: S’il te plaît, tu peux\n"
	.string "me donner ce METEORITE?\p"
	.string "Je suis prêt à te l’échanger contre un\n"
	.string "objet de valeur. Que dirais-tu d’une CT?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "Le PROF. KOSMO est parti au SITE\n"
	.string "METEORE, sur la ROUTE 114, avec\l"
	.string "des types de la TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Pauvre PROF. KOSMO… Il est si déprimé…\n"
	.string "Ça me fend le cœur.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Regarde le PROF. KOSMO…\n"
	.string "Il est tellement content! C’est génial!$"

