SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_20BB00:: @ 820BB00
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BD8D, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 1
	addobject 3
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCE4
	waitmovement 0
	addobject 4
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCF3
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCE8
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCF5
	waitmovement 0
	compare VAR_FACING, 1
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BC92
	compare VAR_FACING, 4
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BC92
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BE40, MSGBOX_DEFAULT
	compare VAR_FACING, 4
	call_if_ne SlateportCity_OceanicMuseum_2F_EventScript_20BC9D
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BE69, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BE93, MSGBOX_DEFAULT
	closemessage
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCE2
	waitmovement 0
	compare VAR_FACING, 1
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BCA8
	compare VAR_FACING, 3
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BCB3
	trainerbattle_no_intro TRAINER_GRUNT_14, SlateportCity_OceanicMuseum_2F_Text_20BEE2
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BEFA, MSGBOX_DEFAULT
	closemessage
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCEF
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCE2
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BF35, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_15, SlateportCity_OceanicMuseum_2F_Text_20BF66
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_20BCEF
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceDown
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BF7A, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject 2
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_20BCD8
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_20BCFE
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BFF2, MSGBOX_DEFAULT
	closemessage
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_20BCD6
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C059, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen 1
	removeobject 2
	removeobject 3
	removeobject 4
	fadescreen 0
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C2BE, MSGBOX_DEFAULT
	setvar VAR_0x8004, 269
	call SlateportCity_OceanicMuseum_2F_EventScript_2723E4
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C36C, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	removeobject 1
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	compare VAR_0x40DA, 0
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_20BC8C
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen 0
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BC8C:: @ 820BC8C
	setvar VAR_0x40DA, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BC92:: @ 820BC92
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BC9D:: @ 820BC9D
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BCA8:: @ 820BCA8
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_20BCBE
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_20BCB3:: @ 820BCB3
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_20BCC2
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_20BCBE: @ 820BCBE
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCC2: @ 820BCC2
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCC8: @ 820BCC8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCD6: @ 820BCD6
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCD8: @ 820BCD8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCE2: @ 820BCE2
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCE4: @ 820BCE4
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCE8: @ 820BCE8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCEF: @ 820BCEF
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCF3: @ 820BCF3
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCF5: @ 820BCF5
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_20BCFE: @ 820BCFE
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_fastest_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_20BD0A:: @ 820BD0A
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C4F9, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD13:: @ 820BD13
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C566, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD1C:: @ 820BD1C
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C5C6, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD25:: @ 820BD25
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C6C7, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD2E:: @ 820BD2E
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C72F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD37:: @ 820BD37
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C7C1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD40:: @ 820BD40
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C82F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD49:: @ 820BD49
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C88B, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD52:: @ 820BD52
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C8E8, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD5B:: @ 820BD5B
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C93A, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD64:: @ 820BD64
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C43F, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD6D:: @ 820BD6D
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C495, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_20BD76:: @ 820BD76
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C4C2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_20BD8D: @ 820BD8D
	.string "Yes? If you're looking for STERN,\n"
	.string "that would be me.\p"
	.string "Ah! Those must be the parts I ordered\n"
	.string "from MR. STONE of DEVON.\p"
	.string "Thank you! That's great!\n"
	.string "We can prepare for our expedition now.$"

SlateportCity_OceanicMuseum_2F_Text_20BE40: @ 820BE40
	.string "Hehehe, hold it!\n"
	.string "We'll take those parts!$"

SlateportCity_OceanicMuseum_2F_Text_20BE69: @ 820BE69
	.string "CAPT. STERN: Wh-what?\n"
	.string "Who are you people?$"

SlateportCity_OceanicMuseum_2F_Text_20BE93: @ 820BE93
	.string "We're TEAM AQUA!\p"
	.string "Our BOSS wants those parts!\n"
	.string "Shut your yap and fork them over!$"

SlateportCity_OceanicMuseum_2F_Text_20BEE2: @ 820BEE2
	.string "Awaaaah!\n"
	.string "A kid beat me!$"

SlateportCity_OceanicMuseum_2F_Text_20BEFA: @ 820BEFA
	.string "Oh, man, what a disaster…\n"
	.string "The BOSS is going to be furious…$"

SlateportCity_OceanicMuseum_2F_Text_20BF35: @ 820BF35
	.string "Humph, sniveling wimp!\n"
	.string "Let me take care of this!$"

SlateportCity_OceanicMuseum_2F_Text_20BF66: @ 820BF66
	.string "What?!\n"
	.string "I lost, too!$"

SlateportCity_OceanicMuseum_2F_Text_20BF7A: @ 820BF7A
	.string "Now what? If we don't get the parts,\n"
	.string "we're in for it!\p"
	.string "Arrgh, I didn't count on being meddled\n"
	.string "with by some meddling kid!$"

SlateportCity_OceanicMuseum_2F_Text_20BFF2: @ 820BFF2
	.string "I came to see what was taking so\n"
	.string "long to snatch some parts, and you\l"
	.string "simps are held up by a mere child?$"

SlateportCity_OceanicMuseum_2F_Text_20C059: @ 820C059
	.string "We are TEAM AQUA,\n"
	.string "and we love the sea!\p"
	.string "And I am TEAM AQUA's leader,\n"
	.string "ARCHIE!\p"
	.string "What makes you interfere with us?\p"
	.string "…No! You can't be!\n"
	.string "You're not one of TEAM MAGMA?\p"
	.string "Wait, that can't be right.\n"
	.string "You're not dressed for the part.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, people… All life depends on\n"
	.string "the sea.\p"
	.string "So, TEAM AQUA is dedicated to\n"
	.string "the expansion of the sea.\p"
	.string "Don't you agree? What we are doing\n"
	.string "is a magnificent undertaking.\p"
	.string "Ah, fine…\n"
	.string "You're still too young to understand\l"
	.string "our noble objective.\p"
	.string "But, I warn you, don't even consider\n"
	.string "interfering with our plans again.\p"
	.string "The consequences will cost you\n"
	.string "dearly!\p"
	.string "And don't you forget it!$"

SlateportCity_OceanicMuseum_2F_Text_20C2BE: @ 820C2BE
	.string "CAPT. STERN: You're…\n"
	.string "Ah, okay, you're {PLAYER}{KUN}…\p"
	.string "Anyway, that was a tense situation!\n"
	.string "Thank you for saving us!\p"
	.string "Oh, yes, I almost forgot that you\n"
	.string "even brought the parts from DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_20C36C: @ 820C36C
	.string "CAPT. STERN: Whoops!\n"
	.string "There's no time to lose!\p"
	.string "We have to set out on our ocean-floor\n"
	.string "expedition really soon.\p"
	.string "Thanks again, but now I've got\n"
	.string "to go!\p"
	.string "Feel free to wander around and check\n"
	.string "out our facilities, though.$"

SlateportCity_OceanicMuseum_2F_Text_20C43F: @ 820C43F
	.string "I saw a model of a ship here.\p"
	.string "It reminded me of the ABANDONED SHIP\n"
	.string "near DEWFORD TOWN…$"

SlateportCity_OceanicMuseum_2F_Text_20C495: @ 820C495
	.string "Don't you dare run around inside\n"
	.string "the MUSEUM!$"

SlateportCity_OceanicMuseum_2F_Text_20C4C2: @ 820C4C2
	.string "Wow, the submarine's awesome!\n"
	.string "I want to go for a ride!$"

SlateportCity_OceanicMuseum_2F_Text_20C4F9: @ 820C4F9
	.string "“WATER QUALITY SAMPLE 1,” the\n"
	.string "label says.\p"
	.string "The sea is all connected, but the\n"
	.string "water seems to differ by region.$"

SlateportCity_OceanicMuseum_2F_Text_20C566: @ 820C566
	.string "“WATER QUALITY SAMPLE 2,” the\n"
	.string "label says.\p"
	.string "Does the saltiness of seawater differ\n"
	.string "by region, too?$"

SlateportCity_OceanicMuseum_2F_Text_20C5C6: @ 820C5C6
	.string "A rubber ball is expanding and\n"
	.string "shrinking.\p"
	.string "“In the sea, the weight of water itself\n"
	.string "exerts pressure.\p"
	.string "“In shallow water, the pressure is not\n"
	.string "very heavy.\p"
	.string "“However, in extremely deep water,\n"
	.string "the pressure can reach even tens of\l"
	.string "thousands of tons on a small area.”$"

SlateportCity_OceanicMuseum_2F_Text_20C6C7: @ 820C6C7
	.string "“MODEL OF HOENN REGION”\p"
	.string "It's a miniature diorama of the\n"
	.string "HOENN region.\p"
	.string "Where is LITTLEROOT TOWN on this?$"

SlateportCity_OceanicMuseum_2F_Text_20C72F: @ 820C72F
	.string "It's a display on the flow of seawater.\p"
	.string "“Near the bottom of the sea, water\n"
	.string "flows due to differences in such\l"
	.string "factors as temperature and salinity.”$"

SlateportCity_OceanicMuseum_2F_Text_20C7C1: @ 820C7C1
	.string "It's a display on the flow of seawater.\p"
	.string "“Toward the surface, seawater flows\n"
	.string "as currents driven by the winds.”$"

SlateportCity_OceanicMuseum_2F_Text_20C82F: @ 820C82F
	.string "“THE FERRY S.S. TIDAL\p"
	.string "“A scale replica of the ship under\n"
	.string "construction at STERN'S SHIPYARD.”$"

SlateportCity_OceanicMuseum_2F_Text_20C88B: @ 820C88B
	.string "“SUBMARINE EXPLORER 1\p"
	.string "“A replica of the high-performance\n"
	.string "ocean floor exploration submarine.”$"

SlateportCity_OceanicMuseum_2F_Text_20C8E8: @ 820C8E8
	.string "“SUBMERSIBLE POD\p"
	.string "“A replica of a compact, unmanned\n"
	.string "pod for seafloor exploration.”$"

SlateportCity_OceanicMuseum_2F_Text_20C93A: @ 820C93A
	.string "“S.S. ANNE\p"
	.string "“A replica of the luxury liner that\n"
	.string "circles the globe.”$"

