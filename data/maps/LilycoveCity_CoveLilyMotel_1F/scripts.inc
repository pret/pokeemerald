LilycoveCity_CoveLilyMotel_1F_MapScripts:: @ 8218188
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_218189:: @ 8218189
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_2181EA
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_2181C3
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_218264, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_21831E, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_2181C3:: @ 82181C3
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_2183C3, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_218470, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_2181EA:: @ 82181EA
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_218544, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_2185F4, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_218211:: @ 8218211
	lockall
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_21839B, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_218259
	applymovement 1, LilycoveCity_CoveLilyMotel_1F_Movement_21825E
	waitmovement 0
	applymovement 1, LilycoveCity_CoveLilyMotel_1F_Movement_218260
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_218259: @ 8218259
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_21825E: @ 821825E
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_218260: @ 8218260
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_218264: @ 8218264
	.string "Hm, so they doubled the guests by\n"
	.string "using POKéMON as attractions?\p"
	.string "Hm, well, maybe I should make a cute\n"
	.string "POKéMON our inn's mascot.\p"
	.string "I wonder if that will attract more\n"
	.string "guests to stay with us?$"

LilycoveCity_CoveLilyMotel_1F_Text_21831E: @ 821831E
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "Since that TEAM AQUA came to town,\n"
	.string "the tourists have been staying away.$"

LilycoveCity_CoveLilyMotel_1F_Text_21839B: @ 821839B
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_2183C3: @ 82183C3
	.string "Amazing! You're telling me a POKéMON\n"
	.string "found someone's lost item?\p"
	.string "That's something. If we had some smart\n"
	.string "POKéMON like that…\p"
	.string "We could recover anything that our\n"
	.string "guests mislaid…$"

LilycoveCity_CoveLilyMotel_1F_Text_218470: @ 8218470
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "I heard that someone busted\n"
	.string "the TEAM AQUA HIDEOUT.\p"
	.string "Thanks to that, we just booked\n"
	.string "a reservation from a big group.\p"
	.string "It was a company called… Uh…\n"
	.string "GAME something…$"

LilycoveCity_CoveLilyMotel_1F_Text_218544: @ 8218544
	.string "Amazing! A house-sitting POKéMON\n"
	.string "caught a burglar?\p"
	.string "That's something. If we had a tough\n"
	.string "POKéMON as a security guard…\p"
	.string "We would be able to provide our guests\n"
	.string "with greater safety.$"

LilycoveCity_CoveLilyMotel_1F_Text_2185F4: @ 82185F4
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV.\p"
	.string "Oh, yes. A big group of guests arrived\n"
	.string "a little while ago.\p"
	.string "They booked in as GAME FREAK,\n"
	.string "so I guess they must make games.\p"
	.string "Uh-oh, I'd better get working on\n"
	.string "their dinner!$"

