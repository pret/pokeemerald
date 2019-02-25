MossdeepCity_GameCorner_1F_MapScripts:: @ 8224B27
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_MapScript2_224B41
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_MapScript2_224B37
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_GameCorner_1F_MapScript1_276BBE
	.byte 0

MossdeepCity_GameCorner_1F_MapScript2_224B37: @ 8224B37
	map_script_2 VAR_CABLE_CLUB_STATE, 8, MossdeepCity_GameCorner_1F_EventScript_276BAE
	.2byte 0

MossdeepCity_GameCorner_1F_MapScript2_224B41: @ 8224B41
	map_script_2 VAR_CABLE_CLUB_STATE, 8, MossdeepCity_GameCorner_1F_EventScript_276C9D
	.2byte 0

MossdeepCity_GameCorner_1F_EventScript_224B4B:: @ 8224B4B
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_277C34
	release
	end

MossdeepCity_GameCorner_1F_EventScript_224B54:: @ 8224B54
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_277C91
	release
	end

MossdeepCity_GameCorner_1F_EventScript_224B5D:: @ 8224B5D
	msgbox MossdeepCity_GameCorner_1F_Text_224BFD, MSGBOX_SIGN
	end

MossdeepCity_GameCorner_1F_Text_224B66: @ 8224B66
	.string "When I was young, I traveled the world\n"
	.string "as a POKéMON TRAINER.\p"
	.string "Now that I've become an old buzzard,\n"
	.string "my only amusement is watching young\l"
	.string "TRAINERS battle.$"

MossdeepCity_GameCorner_1F_Text_224BFD: @ 8224BFD
	.string "The door appears to be locked.$"

MossdeepCity_GameCorner_1F_Text_224C1C: @ 8224C1C
	.string "A TRAINER named {STR_VAR_1} is\n"
	.string "visiting my home.\p"
	.string "Would you like to challenge\n"
	.string "{STR_VAR_1}?$"

MossdeepCity_GameCorner_1F_Text_224C64: @ 8224C64
	.string "You won't battle? I'm disappointed\n"
	.string "that I can't see you battle…$"

MossdeepCity_GameCorner_1F_Text_224CA4: @ 8224CA4
	.string "Oh, good, good!\p"
	.string "But my house isn't all that sturdy.\p"
	.string "Could I ask you to keep it down to\n"
	.string "a 3-on-3 match?$"

MossdeepCity_GameCorner_1F_Text_224D0B: @ 8224D0B
	.string "Before you two battle, you should\n"
	.string "save your progress.$"

MossdeepCity_GameCorner_1F_Text_224D41: @ 8224D41
	.string "I hope to see a good match!$"

MossdeepCity_GameCorner_1F_Text_224D5D: @ 8224D5D
	.string "So, it became a standoff.\p"
	.string "It was a brilliant match in which\n"
	.string "neither side conceded a step!$"

MossdeepCity_GameCorner_1F_Text_224DB7: @ 8224DB7
	.string "That was superlative!\p"
	.string "Why, it was like seeing myself in\n"
	.string "my youth again!$"

MossdeepCity_GameCorner_1F_Text_224DFF: @ 8224DFF
	.string "Ah, too bad for you!\p"
	.string "But it was a good match.\n"
	.string "I hope you can win next time.$"

