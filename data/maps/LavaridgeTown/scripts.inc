.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_CheckSetRivalPos
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut:: @ 81EA514
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos:: @ 81EA518
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos:: @ 81EA529
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame: @ 81EA547
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles:: @ 81EA551
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalNoticePlayer
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_PlayBrendanMusic
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalApproachPlayer1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_MayGiveGoGoggles
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles:: @ 81EA5B5
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles:: @ 81EA5DA
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit:: @ 81EA5FF
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalExit1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic:: @ 81EA630
	playbgm MUS_ENCOUNTER_MAY, 1
	return

LavaridgeTown_EventScript_PlayBrendanMusic:: @ 81EA635
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	return

LavaridgeTown_EventScript_RivalNoticePlayer:: @ 81EA63A
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop:: @ 81EA65C
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1:: @ 81EA6A1
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2:: @ 81EA6AC
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1:: @ 81EA6B7
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2:: @ 81EA6C9
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2: @ 81EA6D4
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

LavaridgeTown_Movement_PlayerWatchRivalExit: @ 81EA6DF
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LavaridgeTown_Movement_RivalExit1: @ 81EA6E3
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

LavaridgeTown_Movement_RivalApproachPlayer2: @ 81EA6ED
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1: @ 81EA6F4
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop: @ 81EA6F8
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings:: @ 81EA70B
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM:: @ 81EA70E
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan:: @ 81EA717
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin:: @ 81EA720
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1:: @ 81EA729
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2:: @ 81EA732
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF:: @ 81EA73B
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman:: @ 81EA744
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg:: @ 81EA787
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg:: @ 81EA791
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg:: @ 81EA79B
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign:: @ 81EA7A5
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign:: @ 81EA7AE
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign:: @ 81EA7B7
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis: @ 81EA7C0
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the LAVARIDGE GYM BADGE.\p"
	.string "You must have collected\n"
	.string "good POKéMON…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad: @ 81EA897
	.string "MAY: With those GO-GOGGLES, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near ROUTE 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging GYMS…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in PETALBURG GYM.\p"
	.string "See you again!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis: @ 81EA9A2
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of BADGES.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad: @ 81EAA2E
	.string "BRENDAN: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "ROUTE 111.\p"
	.string "There should be some POKéMON that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging NORMAN,\l"
	.string "the GYM LEADER of PETALBURG.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt: @ 81EAB80
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg: @ 81EACC0
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

LavaridgeTown_Text_ReceivedTheEgg: @ 81EACF4
	.string "{PLAYER} received the EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg: @ 81EAD09
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

LavaridgeTown_Text_AsYouWishThen: @ 81EAD44
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare: @ 81EAD9E
	.string "Every so often, an EGG will be found at\n"
	.string "the POKéMON DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry: @ 81EAE03
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside: @ 81EAEE1
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A POKéMON nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings: @ 81EAF4E
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay: @ 81EAF9B
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "GYM LEADER like FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings: @ 81EB003
	.string "If people put POKéMON in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims: @ 81EB092
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign: @ 81EB12B
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign: @ 81EB178
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEADER: FLANNERY\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_HerbShopSign: @ 81EB1CB
	.string "POKéMON HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"

