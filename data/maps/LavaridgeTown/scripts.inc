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
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
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
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
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
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	closedoor 12, 15
	waitdooranim
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
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
	.string "MAY: {PLAYER}{KUN}! Lang niet gezien!\p"
	.string "Oh? Terwijl ik in de warme bronnen\n"
	.string "zat, kreeg jij de LAVARIDGE GYM BADGE.\p"
	.string "Je hebt vast goede POKéMON\n"
	.string "verzameld… Nee, je hebt ze\l"
	.string "opgevoed.\p"
	.string "Dan mag je dit wel hebben.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: Met deze ZANDBRIL kom je\n"
	.string "makkelijk door de woestijn bij\l"
	.string "ROUTE 111.\p"
	.string "Maar wow, {PLAYER}{KUN}…\n"
	.string "GYMS uitdagen…\p"
	.string "Je doet zo je best omdat je\n"
	.string "niet van mij wilt verliezen, hè!\p"
	.string "{PLAYER}{KUN}, ik ga je vader uitdagen\n"
	.string "in PETALBURG GYM.\p"
	.string "Tot ziens!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: {PLAYER}, hé, lang niet gezien.\n"
	.string "Hoe gaat het?\p"
	.string "Hmm…\n"
	.string "Je hebt een mooie rij BADGES.\p"
	.string "Nou, dan mag je dit wel hebben.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Houd die bij je als je\n"
	.string "naar de woestijn bij ROUTE 111 gaat.\p"
	.string "Daar wonen POKéMON die alleen\n"
	.string "in de woestijn leven.\l"
	.string "Kijk maar eens rond.\p"
	.string "Ik zelf…\n"
	.string "Ik wil NORMAN uitdagen,\l"
	.string "de GYMLEIDER van PETALBURG.\p"
	.string "Jouw vader lijkt echt sterk,\n"
	.string "anders dan jij, {PLAYER}.\p"
	.string "Tot de volgende keer!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Ik heb hier een EI.\p"
	.string "Ik hoopte dat het uit zou komen in\n"
	.string "het hete zand bij de warme bronnen.\l"
	.string "Maar dat is niet genoeg…\p"
	.string "Ik hoorde dat het beter is om\n"
	.string "het EI bij POKéMON te houden\l"
	.string "en mee te nemen.\p"
	.string "Jij bent een TRAINER, toch?\n"
	.string "En je POKéMON zijn vol energie.\p"
	.string "Dus, wat zeg je?\n"
	.string "Neem je dit EI mee?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Fijn! Ik hoop dat je veel gaat\n"
	.string "lopen met dit EI!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} kreeg het EI.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? Je hebt te veel POKéMON.\n"
	.string "Er is geen plek voor dit EI…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Zoals je wilt…\p"
	.string "Als je toch van gedachten\n"
	.string "verandert, ben ik hier.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Soms vind je een EI bij\n"
	.string "de POKéMON DAY CARE.\p"
	.string "Tenminste, dat zegt men.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "We pompen zoveel warm water op\n"
	.string "als we willen, en het raakt nooit op.\p"
	.string "Is dat niet magisch?\p"
	.string "Warme bronnen zijn bij vulkanen.\n"
	.string "Magma verwarmt het water onder\l"
	.string "de grond, en het komt omhoog.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Zo begraven in warm zand…\n"
	.string "Ach…\p"
	.string "Zo warm en heerlijk…\p"
	.string "Hè? Auw! Au!\p"
	.string "Een POKéMON beet in mijn kont!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, hou jij van warme bronnen?\p"
	.string "Dat is gek voor iemand die zo\n"
	.string "jong is.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Ik baad elke dag in de warme bronnen.\p"
	.string "Ik wil een mooie en sterke\n"
	.string "GYMLEIDER worden zoals FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Als je POKéMON in de warme bron doet,\n"
	.string "wordt het misschien heel gek.\p"
	.string "Misschien wordt het een stroombad,\n"
	.string "een schuimbad, of een lavabad…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Men zegt dat de warme bronnen goed\n"
	.string "zijn tegen stress, pijnlijke spieren,\l"
	.string "liefdesverdriet en geldzorgen…$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER WARME BRONNEN\n"
	.string "Een fijne plek om te relaxen!”$"

LavaridgeTown_Text_GymSign:
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEIDER: FLANNERY\l"
	.string "“Met een vuur dat fel brandt!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON KRUIDENWINKEL\n"
	.string "“Bitter van smaak, goed voor je!”$"

