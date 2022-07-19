Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "ANNETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Je suis désolée. C’est la pagaille. Quand\n"
	.string "je suis plongée dans mes recherches,\l"
	.string "je n’ai pas le temps de ranger…\p"
	.string "C’est très embarrassant… Si tu n’en\n"
	.string "parles à personne, je te donne ça.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Je peux te donner un conseil sur mon\n"
	.string "programme de Gestion de Stocks de\l"
	.string "POKéMON?\p"
	.string "Tu peux organiser tes BOITES pour\n"
	.string "savoir quels POKéMON elles contiennent.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ce sont les notes d’ANNETTE.\n"
	.string "Il y a des informations sur les BOITES.\p"
	.string "Concevoir des BOITES pouvant contenir\n"
	.string "30 POKéMON chacune.\p"
	.string "Chaque DRESSEUR doit pouvoir stocker\n"
	.string "420 POKéMON sur son PC.\p"
	.string "Continuer à lire?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Ajouter un système de marquage pour\n"
	.string "faciliter l’organisation des POKéMON.\p"
	.string "Le nom et le fond de chaque BOITE\n"
	.string "pourront être modifiés pour satisfaire\l"
	.string "les POKéMON stockés.\p"
	.string "Continuer à lire?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Quand un POKéMON est stocké, il est\n"
	.string "envoyé dans la dernière BOITE ouverte.\p"
	.string "Si cette BOITE est pleine, le POKéMON\n"
	.string "reçu sera stocké dans la suivante.\p"
	.string "En bref, la dernière BOITE ouverte\n"
	.string "devient la BOITE dans laquelle les\l"
	.string "POKéMON seront envoyés.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} ferme le cahier.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Il y a un e-mail sur le PC.\p"
	.string "… … … … … … …\p"
	.string "Votre programme de Gestion de Stocks\n"
	.string "est plus performant que le mien.\p"
	.string "La simplicité d’utilisation en fait\n"
	.string "un outil à la fois amusant et utile.\p"
	.string "Je suis très content d’avoir\n"
	.string "participé à son développement.\p"
	.string "J’espère que vous continuerez vos\n"
	.string "recherches sur la Gestion de Stocks.\p"
	.string "De la part de LEO.\n"
	.string "… … … … … … … …$"

