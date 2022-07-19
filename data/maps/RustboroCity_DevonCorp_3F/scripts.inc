.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Je suis M. ROCHARD, le DIRECTEUR\n"
	.string "de DEVON.\p"
	.string "On vient de me parler de toi.\p"
	.string "Tu as sauvé notre équipe pas une,\n"
	.string "mais deux fois!\p"
	.string "J’ai un service à demander à\n"
	.string "quelqu’un d’aussi remarquable que toi.\p"
	.string "Je sais que tu dois livrer un paquet\n"
	.string "au CHANTIER NAVAL de POIVRESSEL.\p"
	.string "Sur la route, pourrais-tu faire une\n"
	.string "petite halte au VILLAGE MYOKARA?\p"
	.string "J’aimerais que tu remettes une LETTRE\n"
	.string "à PIERRE.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "M. ROCHARD: Tu dois savoir que je suis\n"
	.string "un grand DIRECTEUR.\p"
	.string "Je ne suis donc pas avare au point\n"
	.string "de demander un service sans rien\l"
	.string "en retour.\p"
	.string "Alors j’aimerais que tu prennes ça!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} reçoit un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "M. ROCHARD: Cet appareil…\p"
	.string "C’est un NAVIGATEUR POKéMON ou\n"
	.string "POKéNAV pour faire plus court.\p"
	.string "C’est un outil indispensable dans la\n"
	.string "quête de tout DRESSEUR.\p"
	.string "Il y a une carte de la région de HOENN.\p"
	.string "Tu pourras facilement voir où se\n"
	.string "situent MYOKARA et POIVRESSEL.\p"
	.string "A propos, j’ai entendu dire que des\n"
	.string "criminels, MAGMA ou AQUA je crois,\p"
	.string "causeraient des problèmes un\n"
	.string "peu partout.\p"
	.string "Je crois que tu ferais mieux de te\n"
	.string "reposer avant de reprendre la route.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "M. ROCHARD: Bien, {PLAYER}{KUN},\n"
	.string "voyage prudemment!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "M. ROCHARD: Je compte sur toi!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "M. ROCHARD: Tu as livré ma LETTRE?\n"
	.string "Merci beaucoup!\p"
	.string "C’est ma façon de te remercier. Ça\n"
	.string "devrait t’aider, en tant que DRESSEUR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "M. ROCHARD: Un POKéMON qui porte\n"
	.string "MULTI EXP se verra attribuer certains\l"
	.string "des points EXP obtenus au combat.\p"
	.string "Il obtiendra des points EXP, même s’il\n"
	.string "n’a pas vraiment combattu.\p"
	.string "Je trouve le MULTI EXP très utile pour\n"
	.string "faire progresser les POKéMON faibles.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "M. ROCHARD: Toute ma jeunesse, je me\n"
	.string "suis plongé dans le travail.\p"
	.string "Alors tu sais, je ne connais pas trop\n"
	.string "les modes et ce genre de choses.\p"
	.string "Mais, les jeunes désirent-ils tous être\n"
	.string "DRESSEURS à la LIGUE POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "C’est le deuxième étage du siège\n"
	.string "de DEVON.\p"
	.string "Le BUREAU du DIRECTEUR s’y trouve.\p"
	.string "Je ne saurais dire combien je suis\n"
	.string "reconnaissant de ce que tu as fait.\p"
	.string "Hum… Au fait, le paquet que tu nous \n"
	.string "as ramené…\p"
	.string "Je peux te demander de le livrer au\n"
	.string "CHANTIER NAVAL de POIVRESSEL?\p"
	.string "Ce serait désastreux si ces voleurs\n"
	.string "tentaient de le reprendre.\p"
	.string "Hum… Alors je peux compter sur toi\n"
	.string "pour me rendre ce service?\p"
	.string "Oh, c’est vrai!\n"
	.string "Tu pourrais attendre ici un instant?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Notre DIRECTEUR aimerait te dire\n"
	.string "un mot.\p"
	.string "Si tu veux bien me suivre…$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Vas-y, je t’en prie.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Si tu vas au CHANTIER NAVAL de\n"
	.string "POIVRESSEL, tu devrais aller voir le\l"
	.string "CAPT. POUPE.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Les nouvelles créations de DEVON,\n"
	.string "la BIS BALL et la CHRONO BALL, sont\l"
	.string "très appréciées des DRESSEURS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "C’est une collection de roches et de\n"
	.string "pierres rares réunies par le DIRECTEUR.$"

