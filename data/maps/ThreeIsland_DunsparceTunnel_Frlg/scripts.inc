ThreeIsland_DunsparceTunnel_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_DunsparceTunnel_OnTransition
	.byte 0

ThreeIsland_DunsparceTunnel_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_DUNSPARCE_TUNNEL
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, ThreeIsland_DunsparceTunnel_EventScript_SetLayoutDugOut
	call_if_eq VAR_0x8008, FALSE, ThreeIsland_DunsparceTunnel_EventScript_MoveProspectorToWall
	end

ThreeIsland_DunsparceTunnel_EventScript_SetLayoutDugOut::
	setmaplayoutindex LAYOUT_THREE_ISLAND_DUNSPARCE_TUNNEL_DUG_OUT
	return

ThreeIsland_DunsparceTunnel_EventScript_MoveProspectorToWall::
	setobjectxyperm LOCALID_PROSPECTOR, 6, 3
	setobjectmovementtype LOCALID_PROSPECTOR, MOVEMENT_TYPE_FACE_RIGHT
	return

ThreeIsland_DunsparceTunnel_EventScript_Prospector::
	lock
	faceplayer
	goto_if_set FLAG_GOT_NUGGET_FROM_DUNSPARCE_TUNNEL, ThreeIsland_DunsparceTunnel_EventScript_ProspectorAlreadyGaveNugget
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, ThreeIsland_DunsparceTunnel_EventScript_ProspectorStruckGold
	msgbox ThreeIsland_DunsparceTunnel_Text_ProspectingForGold
	closemessage
	applymovement LOCALID_PROSPECTOR, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ThreeIsland_DunsparceTunnel_EventScript_ProspectorStruckGold::
	msgbox ThreeIsland_DunsparceTunnel_Text_StruckGoldThisIsForYou
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, ThreeIsland_DunsparceTunnel_EventScript_NoRoomForNugget
	setflag FLAG_GOT_NUGGET_FROM_DUNSPARCE_TUNNEL
	goto ThreeIsland_DunsparceTunnel_EventScript_ProspectorAlreadyGaveNugget
	end

ThreeIsland_DunsparceTunnel_EventScript_NoRoomForNugget::
	msgbox ThreeIsland_DunsparceTunnel_Text_WhoopsBagCrammedFull
	release
	end

ThreeIsland_DunsparceTunnel_EventScript_ProspectorAlreadyGaveNugget::
	msgbox ThreeIsland_DunsparceTunnel_Text_ThatsANugget
	release
	end

ThreeIsland_DunsparceTunnel_Text_ProspectingForGold::
	.string "Hey, there!\n"
	.string "How's it going?\p"
	.string "What am I doing here, you ask?\n"
	.string "Why, I'm prospecting for gold!\p"
	.string "When I strike it rich, I'm buying\n"
	.string "a house in KANTO.$"

ThreeIsland_DunsparceTunnel_Text_StruckGoldThisIsForYou::
	.string "Hey, there! How's it going?\n"
	.string "Did you hear? I've struck gold!\p"
	.string "You remembered that I was\n"
	.string "prospecting, didn't you?\p"
	.string "You can't begin to imagine just\n"
	.string "how happy I am.\p"
	.string "So, I'll show you!\n"
	.string "This is for you!$"

ThreeIsland_DunsparceTunnel_Text_ThatsANugget::
	.string "That's a NUGGET!\p"
	.string "I can't give you any nuggets of\n"
	.string "wisdom, so that'll have to do!$"

ThreeIsland_DunsparceTunnel_Text_WhoopsBagCrammedFull::
	.string "Whoops, your BAG is crammed full!\n"
	.string "I'll give this to you later.$"

