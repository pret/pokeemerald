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
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
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
	.string "Ik ben de FOSSIL MANIAC…\n"
	.string "Ik ben aardig en hou van FOSSIELEN…\p"
	.string "Wil jij een FOSSIEL?\p"
	.string "Maar alle FOSSIELEN hier zijn van\n"
	.string "mij… Geen een voor jou…\p"
	.string "Wil je per se een FOSSIEL? Zoek\n"
	.string "dan in een woestijn. Daar kunnen\l"
	.string "FOSSIELEN onder rotsen en\l"
	.string "zand liggen…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Je hebt een FOSSIEL gevonden, hè?\n"
	.string "Wat fijn… Het is zo prachtig…\p"
	.string "Wat ga je met dat FOSSIEL\n"
	.string "doen?\p"
	.string "Ik hoorde dat DEVON onderzoekt hoe\n"
	.string "ze POKéMON weer tot leven kunnen\l"
	.string "wekken uit FOSSIELEN…\p"
	.string "Ik hou van mijn FOSSIELEN. Zoiets\n"
	.string "zou ik nooit doen…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "FOSSIELEN zijn zo… prachtig…\n"
	.string "Het is zo mooi…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "Daar is het niet veilig…\p"
	.string "Ik was aan het graven, zie je…\n"
	.string "Toen stortte de hele muur in…\p"
	.string "Ik denk dat er nu een enorme\n"
	.string "grot onder zit…\p"
	.string "Maar ik laat hem met rust. Ik denk\n"
	.string "niet dat er FOSSIELEN liggen…$"

