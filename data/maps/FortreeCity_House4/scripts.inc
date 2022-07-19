.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "En vivant avec les POKéMON, les\n"
	.string "humains se font de plus en plus d’amis.\p"
	.string "Et ça unit le monde!\n"
	.string "Je trouve ça merveilleux.$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Là-bas!\n"
	.string "Vas-y, POKéMON OISEAU!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Hé, j’ai chargé GOELISE de faire\n"
	.string "une course pour moi.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Bien!\n"
	.string "Heureux de te revoir, GOELISE!\p"
	.string "Hum? Qu’est-ce que c’est?\n"
	.string "Qu’est-ce qu’il rapporte là?\p"
	.string "Une HERBE MENTAL?\n"
	.string "Il a dû ramasser ça quelque part.\p"
	.string "Mais je ne suis pas DRESSEUR,\n"
	.string "alors tu peux la garder.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Grâce à GOELISE, je peux avoir\n"
	.string "des amis qui vivent loin d’ici.$"

FortreeCity_House4_Text_Wingull:
	.string "GOELISE: Goéééliiise!$"

