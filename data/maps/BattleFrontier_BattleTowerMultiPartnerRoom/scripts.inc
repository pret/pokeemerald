.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Veuillez choisir le DRESSEUR qui sera\n"
	.string "votre partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, vous n’avez pas trouvé\n"
	.string "de partenaire.\p"
	.string "Voulez-vous arrêter de chercher et\n"
	.string "retourner au guichet d’inscription?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Alors je vous prie de choisir l’un de ces\n"
	.string "DRESSEURS comme partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Merci d’avoir choisi un partenaire.\p"
	.string "Je vais maintenant vous mener à votre\n"
	.string "SALLE DE COMBAT MULTI.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "On {STR_VAR_1}’s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Thank you!\n"
	.string "I’ll go register right now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "I am {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let’s form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Thank you very much!\n"
	.string "I’ll be done with registration quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Hum, je m’appelle {STR_VAR_3}. Je suis\n"
	.string "l’apprenti nº {STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Sniff…\p"
	.string "Je suis désolé!\n"
	.string "Je ne supporte pas cette pression…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} m’a conseillé. J’ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Sniff…\n"
	.string "S’il te plaît, fais équipe avec moi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Vraiment? Tu veux bien?\n"
	.string "Super! Extra!\p"
	.string "Oh… Je suis désolé…\n"
	.string "Ce sont des larmes de joie…\p"
	.string "Je vais nous inscrire tout de suite.\n"
	.string "Surtout, reste ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, mais…\n"
	.string "Sniff… Ouin!!!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Bonjour! Je suis {STR_VAR_3}!\n"
	.string "Je suis l’apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} a choisi mon équipe!\n"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "Plutôt pas mal, hein?\p"
	.string "Allez, vas-y!\n"
	.string "Fais équipe avec moi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Ouais, super!\n"
	.string "Je vais m’inscrire, alors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Mais pourquoi, d’abord?\n"
	.string "Je veux faire équipe avec toi, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Je suis {STR_VAR_3}, l’apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "J’ai demandé conseil à {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}, voilà ce que j’ai.\p"
	.string "S’il te plaît, tu veux bien faire\n"
	.string "équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Merci!\n"
	.string "Je vais nous inscrire tout de suite!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, j’avais tellement envie de\n"
	.string "faire équipe avec toi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Oh… Ça me fait plaisir\n"
	.string "que tu viennes me parler.\p"
	.string "Je m’appelle {STR_VAR_3}.\n"
	.string "Je suis l’apprentie nº {STR_VAR_2} de {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} a bien voulu me conseiller.\n"
	.string "Je lui dois tant de choses!\p"
	.string "Dans mon équipe, j’ai un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "Je sais que j’en demande trop…\p"
	.string "Tu vas sûrement refuser, mais tu veux\n"
	.string "bien qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Vraiment? Je n’arrive pas à le croire!\n"
	.string "On va faire équipe!\l"
	.string "Je… Je serai à la hauteur!\p"
	.string "Bon… Je vais vite nous inscrire\n"
	.string "avant que tu ne changes d’avis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Je comprends…\n"
	.string "Je ne suis pas à la hauteur…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Salut, je m’appelle {STR_VAR_3}.\n"
	.string "Je suis l’apprentie nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "C’est {STR_VAR_3} qui a fait mon équipe!\n"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "et un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}.\p"
	.string "Pas mal, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "D’accord!\n"
	.string "J’espère qu’on va bien s’entendre!\l"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Quoi? Tu refuses?\n"
	.string "Tu ne sais pas ce que tu perds!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Je m’appelle {STR_VAR_3}. Je suis\n"
	.string "TRIATHLETE. Je n’arrête pas!\l"
	.string "Footing, entraînement, danse…\p"
	.string "Et je suis aussi l’apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Voilà ce que {STR_VAR_3} m’a conseillé.\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Malgré tout ce que j’ai à faire, j’ai\n"
	.string "trouvé le temps de les dresser!\p"
	.string "On fait équipe et on voit ce que\n"
	.string "ça donne?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Merci! Tu as l’esprit sportif!\n"
	.string "Ne bouge pas, je vais nous inscrire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Je vois. Pour ta gouverne, je déteste\n"
	.string "qu’on me fasse perdre mon temps!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Bonjour!\n"
	.string "Comment ça va?\p"
	.string "Je suis {STR_VAR_3}, l’apprentie nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}. Enchantée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Ecoute, écoute! C’est {STR_VAR_3} qui\n"
	.string "a composé mon équipe POKéMON.\l"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Je les ai bien dressés!\p"
	.string "Tu veux qu’on fasse équipe?\n"
	.string "Je suis sûre qu’on ira bien ensemble!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Super, on va bien s’amuser!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Quelle méchanceté!\n"
	.string "Je suis sûre que tu vas le regretter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Je me présente, je m’appelle\n"
	.string "{STR_VAR_3}.\p"
	.string "Je suis l’apprentie nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "J’ai suivi les conseils de {STR_VAR_3}\n"
	.string "et dans mon équipe j’ai un\l"
	.string "{STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "On fait équipe ensemble?\n"
	.string "S’il te plaît!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… J’en suis ravie!\n"
	.string "Je vais donner tout ce que j’ai!\p"
	.string "Allez, je vais nous inscrire!\n"
	.string "Attends-moi ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "J’espérais vraiment être ta partenaire,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Hé, tu m’as parlée!\n"
	.string "Ça me fait tellement plaisir!\p"
	.string "Je m’appelle {STR_VAR_3}! Je suis\n"
	.string "l’apprentie nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "J’ai écouté {STR_VAR_3} et j’ai dressé\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Tu veux bien exaucer mon souhait?\n"
	.string "J’aimerais faire équipe avec toi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Oh… C’est un jour merveilleux!\n"
	.string "Merci infiniment!\l"
	.string "Je vais nous inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Oh! Tu n’as donc aucun cœur?\n"
	.string "Mais je t’admire, tu sais…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Bonjour! Je suis l’apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!\p"
	.string "Je m’appelle {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mon mentor {STR_VAR_3} m’a conseillé\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Pas mal, non?\n"
	.string "On fait équipe, alors?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Excellent!\n"
	.string "Je vais nous inscrire vite fait!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Je me méfierai de toi à l’avenir,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Tu sais quoi? C’est le dernier jour\n"
	.string "de la TOUR DE COMBAT!\p"
	.string "… … … … … …\n"
	.string "Mais non, je rigole!\p"
	.string "On m’appelle {STR_VAR_3}. Normal, c’est\n"
	.string "mon nom! Je suis l’apprenti nº 1 000 de\l"
	.string "{STR_VAR_1}. Non, je suis le nº {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} m’a recommandé\n"
	.string "les {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "et les {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}. J’en ai dix de chaque.\l"
	.string "Je rigole, j’en ai qu’un de chaque!\p"
	.string "Alors, on fait équipe, toi et moi?\n"
	.string "Qu’en dis-tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Youpi!\n"
	.string "Allez, je te donne un POKéMON!\p"
	.string "Tu m’as pas cru, j’espère! Je passe au\n"
	.string "guichet d’inscription et je reviens!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Tu me le paieras! Je vais faire de\n"
	.string "ta vie un enfer!\p"
	.string "Mais non, je rigole! Ha, ha, ha!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Salut, DRESSEUR!\n"
	.string "J’attends ici depuis des heures!\p"
	.string "Non, je ne suis pas un requin blanc…\n"
	.string "Je suis {STR_VAR_3}, le MARIN chantant!\p"
	.string "Je suis l’apprenti nº {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Avec moi, ça va swinguer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Les conseils de {STR_VAR_3}, je les ai\n"
	.string "suivis, et mon équipe a bien grandi!\l"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}!\p"
	.string "Faisons équipe,\n"
	.string "nom d’une pipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hé, hé, j’aime ton style!\n"
	.string "Je vais nous inscrire, je file!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Hé, {PLAYER}! Tu me surprends!\n"
	.string "Moi, j’étais partant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yahou, yippie!\n"
	.string "Oh, je t’en prie, reste!\p"
	.string "Je m’appelle {STR_VAR_3}!\n"
	.string "Je suis l’apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} m’a dit quoi faire.\n"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}.\p"
	.string "Qu’en dis-tu?\n"
	.string "Me choisiras-tu?\p"
	.string "Laisse-moi être ton partenaire!\n"
	.string "Allez… Accepte, partenaire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Oh, ça me fait tellement plaisir!\n"
	.string "Je ne sais pas quoi dire!\p"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Tu me rejettes?\n"
	.string "{PLAYER}, ton comportement est abject!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Oh, je tousse!\p"
	.string "Désolé, j’ai pris froid.\n"
	.string "Mes POKéMON vont bien, eux.\p"
	.string "Je m’appelle {STR_VAR_3}. Je suis\n"
	.string "l’apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "{STR_VAR_3} a formé mon équipe.\n"
	.string "J’ai un {STR_VAR_2} qui utilise\l"
	.string "{STR_VAR_1} et aussi un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Je les entraîne tous les jours, qu’il\n"
	.string "pleuve, qu’il neige, qu’il vente!\p"
	.string "C’est d’ailleurs pour ça que j’ai pris\n"
	.string "froid, je pense.\p"
	.string "Maintenant que tu me connais un peu,\n"
	.string "tu veux qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Merci! Ça me fait plaisir!\n"
	.string "Je n’arrête pas de tousser… \l"
	.string "Allez, je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Tu ne veux pas?\n"
	.string "Quel dommage, {PLAYER}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Bonjour!\n"
	.string "Il y a trop de monde, ici… \p"
	.string "Je m’appelle {STR_VAR_3}.\n"
	.string "Je suis l’apprenti nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} m’a conseillé cette équipe… \n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça me met mal à l’aise de te parler… \n"
	.string "Mais veux-tu qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, merci!\n"
	.string "J’ai peur mais je ferai de mon mieux!\p"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Tu ne peux pas refuser!\n"
	.string "Je crois que je vais faire un malaise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Je m’appelle {STR_VAR_3}, je suis\n"
	.string "l’apprenti nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "Je dois mon équipe à {STR_VAR_3}.\p"
	.string "J’ai suivi ses conseils. J’ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Si tu es d’accord, j’aimerais être ton\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Tu acceptes?\n"
	.string "Tu ne le regretteras pas!\p"
	.string "Je vais nous inscrire et nous pourrons\n"
	.string "commencer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Tu refuses?\n"
	.string "Ton humour est totalement déplacé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Je m’appelle {STR_VAR_1}.\n"
	.string "Je suis une FILLETTE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "J’ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et puis un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "C’est tout ce que j’ai avec moi.\p"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Merci!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Tu ne veux pas de moi comme partenaire?\n"
	.string "Tu vas t’en mordre les doigts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Salut!\p"
	.string "Je suis GAMIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Tu veux savoir ce que j’ai?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On va faire équipe, toi et moi,\n"
	.string "non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Chouette!\n"
	.string "Je vais nous inscrire, alors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Tu as tort! Avec tes POKéMON et les\n"
	.string "miens, on serait invincibles!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Bien le bonjour!\n"
	.string "Je suis MONTAGNARD {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Tu veux savoir ce que j’ai avec moi?\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Pas trop mal, non?\n"
	.string "Tu veux qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "D’accord!\n"
	.string "Je vais au guichet et je reviens.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Dommage, j’aurais aimé me battre à tes\n"
	.string "côtés.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Bonjour! Je m’appelle {STR_VAR_1}\n"
	.string "et je suis un CANON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Tu sais ce que j’ai dressé?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu’en penses-tu?\n"
	.string "Tu veux qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Merveilleux!\n"
	.string "Je vais au guichet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Quel dommage!\p"
	.string "Toi et moi, nous aurions fait une belle\n"
	.string "équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Bonjour, toi!\p"
	.string "Tu sais qui je suis?\n"
	.string "Je suis {STR_VAR_1} le PECHEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Mon équipe se compose d’un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "d’un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Qu’en dis-tu?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bien, bien!\n"
	.string "Je me charge de tout!\p"
	.string "Je vais nous inscrire tout de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Oh, c’est bien dommage…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Ravie de te rencontrer.\n"
	.string "Je suis MADEMOISELLE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Je suis accompagnée d’un\n"
	.string "{STR_VAR_2} maîtrisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "et d’un {STR_VAR_2} maîtrisant\n"
	.string "{STR_VAR_1}.\p"
	.string "M’acceptes-tu comme partenaire?\n"
	.string "Cela me ferait tant plaisir!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Je te remercie du fond du cœur.\n"
	.string "Je m’occupe de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Je suis sûre que tu vas le regretter.\n"
	.string "Cependant, je respecte ta décision.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Je m’appelle {STR_VAR_1}. Je suis\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Voyons ce que j’ai…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "C’est mon équipe!\p"
	.string "Dis, tu veux bien qu’on soit\n"
	.string "partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Merci!\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "C’est dommage, je sais qu’on aurait été\n"
	.string "très forts ensemble!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Bonjour!\n"
	.string "Je suis le SCOUT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Regarde ce que j’ai!\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Je te propose que nous fassions\n"
	.string "équipe, tous les deux! Tu es d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Bien!\p"
	.string "Je m’occupe de l’inscription,\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Tu sais, mes POKéMON valent le détour.\n"
	.string "J’espère que tu ne le regretteras pas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bonjour!\n"
	.string "Je suis l’ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "J’ai dressé un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "{STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "C’est plutôt bien, non?\n"
	.string "Tu veux qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Merci!\n"
	.string "Je m’occupe de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Je suis déçu…\p"
	.string "En me battant avec toi, j’aurais pu\n"
	.string "apprendre un tas de choses…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Bonjour.\n"
	.string "Je suis RICHARD {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Tu ne devineras jamais ce que j’ai!\n"
	.string "Un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Si tu le souhaites, tu peux faire équipe\n"
	.string "avec moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "C’est intelligent de ta part! Avec moi,\n"
	.string "impossible de perdre!\p"
	.string "Je m’occupe de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Tu vas le regretter!\n"
	.string "Je suis le meilleur dans cette pièce!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\n"
	.string "Je suis KARATEKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "J’ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Sois sympa, choisis-moi comme\n"
	.string "partenaire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\n"
	.string "Je vais nous inscrire illico presto!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Je comprends…\n"
	.string "Ce n’est que partie remise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Bonjour!\n"
	.string "Je suis FLOTTEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Voilà ce que j’ai…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "Tu veux bien qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Merci!\n"
	.string "Je vais nous inscrire immédiatement!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Ensemble, on aurait pu battre\n"
	.string "n’importe qui, j’en suis sûre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Bien le bonjour…\n"
	.string "Je suis MYSTIMANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "J’ai sur moi un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}…\p"
	.string "Je t’en supplie…\n"
	.string "Choisis-moi comme partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Je te remercie…\n"
	.string "Je vais nous inscrire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "J’espérais tant qu’on fasse équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Comment ça va? Je m’appelle\n"
	.string "{STR_VAR_1}. Je suis un ELEVEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "J’ai deux POKéMON pas mal du tout!\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu’en penses-tu?\n"
	.string "Tu penses qu’on devrait faire équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Je te remercie!\p"
	.string "Ne bouge pas, je vais au guichet\n"
	.string "d’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "J’aurais préféré que tu dises oui,\n"
	.string "bien sûr… Mais tant pis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Bonjour! Je m’appelle {STR_VAR_1}.\n"
	.string "Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Tu veux savoir ce que j’ai?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Alors?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "C’est parti!\n"
	.string "Je vais nous inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Toi et moi, on aurait fait un carton!\n"
	.string "Tu ne sais pas ce que tu rates…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Bonjour! Je m’appelle {STR_VAR_1}!\n"
	.string "Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "J’ai bien entraîné mes POKéMON! J’ai\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Il y a pire, non?\n"
	.string "Tu veux de moi comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Très bien!\n"
	.string "Je cours nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "J’aurais bien aimé combattre\n"
	.string "à tes côtés…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Je suis COMBATTANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "J’ai dressé un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Alors, ça te plaît?\n"
	.string "Si on faisait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Oh, merci!\p"
	.string "Je m’occupe de l’inscription,\n"
	.string "ne bouge pas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Je suis sûre qu’ensemble, on aurait\n"
	.string "été imbattables…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Je m’appelle {STR_VAR_1}.\n"
	.string "Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "J’ai un {STR_VAR_2} à qui j’ai appris\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "{STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "On ferait une équipe du tonnerre,\n"
	.string "tous les deux! Non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Merci!\p"
	.string "Il ne reste plus qu’à nous inscrire.\n"
	.string "J’y cours!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "C’est dommage. Je me faisais une telle\n"
	.string "joie à l’idée de combattre à tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Moi?\n"
	.string "Je suis FLOTTEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Ce que j’ai? Un {STR_VAR_2} qui\n"
	.string "connaît {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}!\p"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "D’accord!\p"
	.string "Je vais nous inscrire!\n"
	.string "Ça va déménager!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mes POKéMON sont forts…\n"
	.string "C’est bête que tu ne veuilles pas de moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Bonjour!\n"
	.string "Je suis GUITARISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Regarde qui est là…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On pourrait pas rêver mieux, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Super! Je vais m’occuper des formalités\n"
	.string "au guichet. Je reviens!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Mes POKéMON sont les meilleurs!\n"
	.string "Tu risques de le regretter!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Ravi de faire ta connaissance.\n"
	.string "Je suis {STR_VAR_1}, un vrai GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Mon cher {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "mon cher {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} sont ici.\p"
	.string "Puis-je te demander de me choisir\n"
	.string "comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Je te remercie de ta confiance.\n"
	.string "Reste ici, je m’occupe de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Cela m’aurait fait tant plaisir…\p"
	.string "J’espère que nous aurons l’occasion de\n"
	.string "faire équipe une autre fois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Bonjour, je m’appelle {STR_VAR_1}.\n"
	.string "Je suis POKéFAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Avec moi, j’ai un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Est-ce que ça te plaît?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Merci!\n"
	.string "Je m’occupe de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Tu ne sais pas reconnaître de bons\n"
	.string "POKéMON quand tu en vois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Je suis {STR_VAR_1}. Je suis un EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "J’ai élevé un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "{STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "Que dirais-tu de faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Parfait!\n"
	.string "Je vais de ce pas nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Je doute que tu aies fait le bon choix…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Bonjour, bonjour!\n"
	.string "Je suis EXPERT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "J’ai élevé mes POKéMON avec soin.\n"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Voilà!\p"
	.string "Voudrais-tu faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bien, bien.\n"
	.string "Je vais de suite nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "D’accord. On remet ça à une prochaine\n"
	.string "fois, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Je suis DRACOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Mon équipe se compose d’un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "et d’un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Qu’est-ce que tu en dis?\n"
	.string "Tu me prends comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Je te promets de faire de mon mieux!\n"
	.string "Je m’occupe de l’inscription, d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Tu sais, tu ne trouveras pas mieux que\n"
	.string "moi, ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Je suis l’ORNITHOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quels POKéMON j’ai? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Tu ne penses pas qu’on ferait une bonne\n"
	.string "équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Super, merci!\n"
	.string "Je vais m’occuper de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mes POKéMON et moi sommes très\n"
	.string "forts. Quel dommage pour toi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Je suis NINJA FAN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mon équipe de POKéMON comporte\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Faisons équipe, tous les deux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Ouais!\n"
	.string "Je me charge de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Tu vas regretter de ne pas avoir mes\n"
	.string "POKéMON à tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Bonjour!\n"
	.string "Je suis SŒUR PARASOL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Je ne suis pas seule. J’ai avec moi un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "N’est-ce pas merveilleux?\n"
	.string "Tu veux faire équipe avec nous?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Merci beaucoup!\p"
	.string "Je vais nous inscrire au guichet.\n"
	.string "Nous ferons de notre mieux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mes POKéMON sont incroyablement forts.\n"
	.string "Quelle déception…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Bonjour!\n"
	.string "Je suis {STR_VAR_1} l’ENTOMOMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Oui, j’ai trouvé mes POKéMON.\n"
	.string "J’ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "et {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "C’est tout ce que j’ai trouvé.\p"
	.string "Ça t’intéresse de faire équipe avec\n"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Compris!\n"
	.string "Super!\p"
	.string "Je m’occupe de l’inscription.\n"
	.string "Ça ne prendra pas longtemps!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Avec mes POKéMON, on aurait gagné à\n"
	.string "coup sûr, tu sais?…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Bonjour!\n"
	.string "Je suis MARIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Mes POKéMON sont ma fierté! J’ai un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec moi,\n"
	.string "n’est-ce pas?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "J’en étais sûr!\n"
	.string "Je m’occupe de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Avec mes POKéMON et moi, c’était\n"
	.string "pourtant la victoire assurée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Bonjour, je suis COLLEC {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "J’ai ici deux beaux spécimens: un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "C’est le nec plus ultra en matière de\n"
	.string "POKéMON, non? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, super!\p"
	.string "Ne perdons pas de temps.\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Ça me chiffonne un peu…\n"
	.string "Tu n’aimes pas mes POKéMON…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Bonjour, je m’appelle {STR_VAR_1}.\n"
	.string "Je suis un POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Je suis escorté par un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1}!\p"
	.string "Tu ne penses pas qu’on ferait une\n"
	.string "équipe du tonnerre, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "C’est super!\n"
	.string "Je vais m’occuper de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La prochaine fois, choisis mes POKéMON\n"
	.string "où je risque de me vexer…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Je suis {STR_VAR_1}, une\n"
	.string "POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Voici mon équipe: j’ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec mes petits\n"
	.string "protégés et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Nous ferons de notre mieux, c’est\n"
	.string "promis! Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "J’espère que tu nous choisiras, la\n"
	.string "prochaine fois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Ravie de faire ta connaissance. Je suis\n"
	.string "AROMA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Je sillonne les chemins avec un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "J’espère qu’ils te conviennent.\n"
	.string "Tu veux bien qu’on soit partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Ton choix m’honore.\n"
	.string "Je vais au guichet d’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Cela me ferait plaisir de faire équipe\n"
	.string "avec toi une prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Tu veux savoir qui je suis?\n"
	.string "Je suis RUINEMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Les POKéMON qui m’accompagnent sont\n"
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Intrigant, n’est-ce pas?\n"
	.string "Si nous faisions équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "C’est une sage décision! Je me charge\n"
	.string "des formalités d’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hum…\n"
	.string "Mes POKéMON sont très forts pourtant…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "J’ai amené un {STR_VAR_2}\n"
	.string "qui sait utiliser {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}. Impressionnant, je sais!\p"
	.string "Dis, tu ne crois pas qu’on devrait faire\n"
	.string "équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool! Je vais vite au guichet\n"
	.string "d’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "On aurait pourtant bien combattu\n"
	.string "ensemble.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "L’équipe que j’ai formée comporte un\n"
	.string "{STR_VAR_2} utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}.\p"
	.string "Ça correspond à ce que tu cherches?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "J’espérais que tu dirais ça!\n"
	.string "Je vais nous inscrire, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Je pensais qu’on aurait fait une\n"
	.string "belle équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Bonjour!\n"
	.string "Je suis POKéMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Tu te demandes ce que j’ai?\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}. Oui, rien que ça!\p"
	.string "Je sais que ça t’impressionne.\n"
	.string "Allez, faisons équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Excellente décision!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Rien ne peut arrêter mes POKéMON!\n"
	.string "Tu vas regretter ta décision!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Salut, toi! Je m’appelle {STR_VAR_1}!\n"
	.string "Je suis un SALTIMBANQUE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Voici le fruit de mon entraînement:\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Alors, qu’en dis-tu?\n"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Bien!\n"
	.string "Je m’occupe de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Quel dommage. Promets-moi qu’on\n"
	.string "fera équipe la prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Je suis CAMPEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "J’ai dressé un {STR_VAR_2} qui sait\n"
	.string "utiliser {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}.\p"
	.string "On s’amuserait bien si on était dans la\n"
	.string "même équipe! Alors, on essaie?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Super!\n"
	.string "Sur ce, je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Bon, une prochaine fois, alors!\n"
	.string "J’aimerais bien combattre à tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Bonjour!\n"
	.string "Je suis PIQUE-NIQUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "J’ai avec moi un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ça te dirait de faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Eh bien, merci!\n"
	.string "Je me charge de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "D’accord. J’espère qu’on fera équipe\n"
	.string "une prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Je suis KINESISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Les deux POKéMON que j’ai dressés sont\n"
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "Qu’en dis-tu?\n"
	.string "On est partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Très bien!\n"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "D’accord. Mais tu dois me promettre\n"
	.string "qu’on fera équipe bientôt.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Je suis KINESISTE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "J’ai avec moi…\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Ce sont mes disciples.\p"
	.string "Je suis sûre que tout cela t’intrigue…\n"
	.string "Si tu veux, nous pouvons faire équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Merci.\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "J’espère qu’il y aura une autre\n"
	.string "occasion. Tu m’intrigues…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Je suis ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Mes POKéMON? J’ai un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ça me plairait bien d’être ta\n"
	.string "partenaire. Tu es d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Oh, merci! Je vais aller au guichet\n"
	.string "pour nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Hein?\n"
	.string "La prochaine fois alors, non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Coucou! Je suis {STR_VAR_1}, un\n"
	.string "ELEVEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Voici les POKéMON que j’ai dressés: un\n"
	.string " {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "C’est plutôt tentant, je sais.\n"
	.string "On fait équipe, d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Parfait!\n"
	.string "Laisse-moi m’occuper de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Je comprends, mais la prochaine fois,\n"
	.string "tu ne pourras pas refuser!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Je suis {STR_VAR_1}. Je suis une\n"
	.string "POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Mes POKéMON chéris sont un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ne sont-ils pas mignons?\n"
	.string "Il faut absolument qu’on fasse équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Je te remercie!\n"
	.string "Je m’occupe de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mes POKéMON chéris sont les meilleurs,\n"
	.string "crois-moi. Mais c’est toi qui décides!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Bonjour! Je suis {STR_VAR_1},\n"
	.string "une NAGEUSE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "J’ai entraîné un {STR_VAR_2} qui\n"
	.string "sait utiliser {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}.\p"
	.string "Si on faisait équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Super!\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si jamais on se rencontre de nouveau,\n"
	.string "tu ne pourras pas refuser!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Oui? Je m’appelle {STR_VAR_1}\n"
	.string "et je suis TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "J’ai quelques POKéMON qui se défendent:\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Ce serait sympa si on faisait équipe,\n"
	.string "tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Merveilleux!\n"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Tu me laisseras être ton partenaire\n"
	.string "la prochaine fois, j’espère.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Je suis {STR_VAR_1}, une TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}, voilà ce que j’ai.\p"
	.string "Qu’en penses-tu?\n"
	.string "Je pense qu’on ferait une bonne équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "J’aime cette réponse!\n"
	.string "Je m’occupe de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Promets-moi que tu me donneras\n"
	.string "bientôt ma chance…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Bonjour, bonjour!\n"
	.string "Je suis {STR_VAR_1}, un NAGEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Regarde quels POKéMON j’ai dressés!\n"
	.string "Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Pas mal, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Quel honneur!\n"
	.string "Je me charge de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "On remet ça à une prochaine fois,\n"
	.string "d’accord?$"

