.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "FLORA: {PLAYER}{KUN}! Ça faisait un bail!\p"
	.string "Oh? Tu as eu le BADGE de VERMILAVA\n"
	.string "pendant que j’étais aux sources.\p"
	.string "Tu as dû attraper pas mal de POKéMON…\n"
	.string "Enfin, je devrais plutôt dire “dresser”\l"
	.string "pas mal de POKéMON.\p"
	.string "Je pense que ce serait bien pour toi\n"
	.string "d’avoir ça.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "FLORA: Avec ces LUNET. SABLE,\n"
	.string "tu pourras sans problème traverser le\l"
	.string "désert près de la ROUTE 111.\p"
	.string "Mais, waouh, {PLAYER}{KUN}…\n"
	.string "Te battre dans les ARENES…\p"
	.string "Tu t’entraînes dur car je parie que tu\n"
	.string "ne veux pas perdre contre moi!\p"
	.string "{PLAYER}{KUN}, je crois que je devrais défier\n"
	.string "ton père à l’ARENE de CLEMENTI-VILLE.\p"
	.string "A une prochaine fois, {PLAYER}{KUN}!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRICE: Hé, {PLAYER}, ça fait un bail.\n"
	.string "Comment ça va?\p"
	.string "Hum…\n"
	.string "Voilà une collection de BADGES\l"
	.string "plutôt honnête.\p"
	.string "Bon, très bien.\n"
	.string "Tu peux aussi prendre ça.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRICE: Prends-les avec toi si tu\n"
	.string "comptes aller dans ce désert, près de\l"
	.string "la ROUTE 111.\p"
	.string "Il devrait y avoir des POKéMON que tu\n"
	.string "ne peux affronter que dans le désert.\l"
	.string "Regarde autour de toi pour les trouver.\p"
	.string "En ce qui me concerne…\n"
	.string "J’envisage de défier NORMAN, le\l"
	.string "CHAMPION D’ARENE de CLEMENTI-VILLE.\p"
	.string "Contrairement à toi, {PLAYER}, ton père\n"
	.string "semble être très fort.\p"
	.string "A plus tard!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "J’ai un OEUF ici.\p"
	.string "J’espérais le faire éclore dans le\n"
	.string "sable chaud, près des sources chaudes.\p"
	.string "Mais ça n’a pas l’air de suffire…\p"
	.string "J’ai entendu dire qu’il valait mieux qu’il\n"
	.string "reste avec d’autres POKéMON, dans\l"
	.string "une équipe.\p"
	.string "Tu es DRESSEUR, n’est-ce pas?\n"
	.string "Et tes POKéMON dégagent de la vitalité.\p"
	.string "Alors, qu’est-ce que t’en dis?\n"
	.string "Tu veux bien ajouter cet OEUF\l"
	.string "à ton équipe pour le faire éclore?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Bien! J’espère que cet OEUF ne va pas\n"
	.string "vous ralentir!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} reçoit l’OEUF.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? Tu as trop de POKéMON.\n"
	.string "Il n’y a plus de place pour cet OEUF…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Bon, comme tu veux…\p"
	.string "Si tu changes d’avis et que tu décides\n"
	.string "de faire éclore cet OEUF, je serai là.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Parfois, on trouve des OEUFS\n"
	.string "à la PENSION POKéMON.\p"
	.string "En tout cas, c’est ce qu’il paraît.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "On prend toute notre eau chaude aux\n"
	.string "sources, mais elles ne s’assèchent pas.\p"
	.string "N’est-ce pas magique?\p"
	.string "Les sources chaudes se forment près\n"
	.string "des volcans actifs. Des filets d’eau,\l"
	.string "chauffés par le magma, jaillissent de\l"
	.string "la terre sous forme de sources chaudes.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Etre enseveli dans ce sable chaud…\n"
	.string "Ahhhh…\p"
	.string "Si chaud et divin…\p"
	.string "Eh? Aaaaah! Ouille!\p"
	.string "Un POKéMON m’a pincé le dos!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, tu aimes les sources chaudes,\n"
	.string "n’est-ce pas?\p"
	.string "C’est surprenant pour quelqu’un d’aussi\n"
	.string "jeune que toi.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Je me baigne chaque jour dans les\n"
	.string "sources chaudes.\p"
	.string "Je veux être DRESSEUR comme\n"
	.string "ADRIANE, et aussi belle et forte qu’elle.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Si on mettait des POKéMON dans les\n"
	.string "sources, ça pourrait être très étrange.\p"
	.string "Ça pourrait être un bain électrique, un\n"
	.string "bain de bulles ou même un bain de lave…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Ils affirment que ces sources chaudes\n"
	.string "calment la nervosité, soulagent les\l"
	.string "douleurs musculaires, peuvent résoudre\l"
	.string "les soucis de cœur et attirent l’argent.$"

LavaridgeTown_Text_TownSign:
	.string "VERMILAVA\p"
	.string "“CENTRE POKéMON des SOURCES\n"
	.string "CHAUDES. Détente garantie!”$"

LavaridgeTown_Text_GymSign:
	.string "ARENE POKéMON de VERMILAVA\n"
	.string "CHAMPION: ADRIANE\l"
	.string "“Ici brûle le feu de la passion!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "HERBORISTERIE POKéMON\n"
	.string "“Plus c’est amer et plus c’est sain!”$"

