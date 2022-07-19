.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Je suis le MANIAQUE DES FOSSILES…\n"
	.string "Je suis un bon garçon, passionné de\l"
	.string "FOSSILES…\p"
	.string "Tu veux un FOSSILE?\p"
	.string "Pas de chance, tous les FOSSILES du\n"
	.string "coin m’appartiennent. Tu n’en auras pas.\p"
	.string "Si tu veux absolument un FOSSILE, va\n"
	.string "dans le désert. Tu risques d’en trouver\l"
	.string "dans les rochers ou dans le sable…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Tu as trouvé un FOSSILE, n’est-ce pas?\n"
	.string "C’est génial… Ça laisse rêveur…\p"
	.string "Qu’est-ce que tu vas faire avec ce\n"
	.string "FOSSILE?\p"
	.string "J’ai entendu dire que DEVON faisait\n"
	.string "des recherches pour ranimer des\l"
	.string "POKéMON à partir de FOSSILES…\p"
	.string "J’aime tellement mes FOSSILES que je\n"
	.string "ne ferai jamais ça…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Les FOSSILES sont si… merveilleux…\n"
	.string "Ils laissent rêveur…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "C’est dangereux par là…\p"
	.string "J’étais en train de creuser…\n"
	.string "Le mur entier s’est effondré…\p"
	.string "Il doit y avoir une grotte immense\n"
	.string "là-dessous…\p"
	.string "Mais ça ne m’intéresse pas, il n’y a\n"
	.string "sûrement pas de FOSSILES…$"

