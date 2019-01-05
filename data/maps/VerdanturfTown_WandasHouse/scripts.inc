VerdanturfTown_WandasHouse_MapScripts:: @ 82028BE
	.byte 0

VerdanturfTown_WandasHouse_EventScript_2028BF:: @ 82028BF
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_2028D7
	msgbox VerdanturfTown_WandasHouse_Text_202993, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_2028D7:: @ 82028D7
	msgbox VerdanturfTown_WandasHouse_Text_202ABE, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_2028E1:: @ 82028E1
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_202909
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_2028FF
	msgbox VerdanturfTown_WandasHouse_Text_202B37, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_2028FF:: @ 82028FF
	msgbox VerdanturfTown_WandasHouse_Text_202C20, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202909:: @ 8202909
	msgbox VerdanturfTown_WandasHouse_Text_202C4E, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202913:: @ 8202913
	msgbox VerdanturfTown_WandasHouse_Text_202E00, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_20291C:: @ 820291C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_202944
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_20293A
	msgbox VerdanturfTown_WandasHouse_Text_202D91, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_20293A:: @ 820293A
	msgbox VerdanturfTown_WandasHouse_Text_202CCF, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202944:: @ 8202944
	msgbox VerdanturfTown_WandasHouse_Text_202D91, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_20294E:: @ 820294E
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_202989
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_20297F
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_202975
	msgbox VerdanturfTown_WandasHouse_Text_202E47, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202975:: @ 8202975
	msgbox VerdanturfTown_WandasHouse_Text_202F19, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_20297F:: @ 820297F
	msgbox VerdanturfTown_WandasHouse_Text_202F73, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_202989:: @ 8202989
	msgbox VerdanturfTown_WandasHouse_Text_202FDB, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_202993: @ 8202993
	.string "WALLY: I lost to you, {PLAYER}, but I'm\n"
	.string "not feeling down anymore.\p"
	.string "Because I have a new purpose in life.\n"
	.string "Together with my RALTS, I'm going\l"
	.string "to challenge POKéMON GYMS and become\l"
	.string "a great TRAINER.\p"
	.string "Please watch me, {PLAYER}.\n"
	.string "I'm going to be stronger than you.\p"
	.string "When I do, I'm going to challenge you\n"
	.string "to another battle.$"

VerdanturfTown_WandasHouse_Text_202ABE: @ 8202ABE
	.string "WALLY: Please watch me, {PLAYER}.\n"
	.string "I'm going to get stronger than you.\p"
	.string "When I do, I'm going to challenge you\n"
	.string "to another battle.$"

VerdanturfTown_WandasHouse_Text_202B37: @ 8202B37
	.string "UNCLE: Oh! {PLAYER}{KUN}!\n"
	.string "WALLY's next door.\p"
	.string "But, boy, there's something I have to\n"
	.string "tell you.\p"
	.string "This natural environment is doing\n"
	.string "wonders for WALLY's health.\p"
	.string "Maybe it's not just the environment.\n"
	.string "It could be POKéMON that are giving\l"
	.string "the boy hope.$"

VerdanturfTown_WandasHouse_Text_202C20: @ 8202C20
	.string "WALLY's gone away…\n"
	.string "He slipped off on his own…$"

VerdanturfTown_WandasHouse_Text_202C4E: @ 8202C4E
	.string "UNCLE: Is that right?\n"
	.string "WALLY's gone away that far all by\l"
	.string "himself…\p"
	.string "Well, I have to give him credit--he is\n"
	.string "my little brother's son.$"

VerdanturfTown_WandasHouse_Text_202CCF: @ 8202CCF
	.string "WANDA: You are?\n"
	.string "Oh, right, I get it!\p"
	.string "You're the {PLAYER} who WALLY was\n"
	.string "telling me about.\p"
	.string "I'm WALLY's cousin.\n"
	.string "Glad to meet you!\p"
	.string "I think WALLY's become a lot more lively\n"
	.string "and healthy since he came here.$"

VerdanturfTown_WandasHouse_Text_202D91: @ 8202D91
	.string "WANDA: Don't worry about WALLY.\n"
	.string "He'll be just fine.\p"
	.string "I know my little cousin, and he has\n"
	.string "POKéMON with him, too.$"

VerdanturfTown_WandasHouse_Text_202E00: @ 8202E00
	.string "Thanks to you, I can see my girlfriend\n"
	.string "every day.\l"
	.string "Happy? You bet I am!$"

VerdanturfTown_WandasHouse_Text_202E47: @ 8202E47
	.string "My daughter's boyfriend is a very\n"
	.string "driven and passionate sort of person.\p"
	.string "He's been digging a tunnel nonstop\n"
	.string "just so he can see my daughter.\p"
	.string "My daughter's a little concerned,\n"
	.string "so she goes out to the tunnel a lot.$"

VerdanturfTown_WandasHouse_Text_202F19: @ 8202F19
	.string "It's amazing. My daughter's boyfriend\n"
	.string "was digging the tunnel by hand!\p"
	.string "It's so incredible!$"

VerdanturfTown_WandasHouse_Text_202F73: @ 8202F73
	.string "If anything were to happen to WALLY,\n"
	.string "I would never be able to look his\l"
	.string "parents in PETALBURG in the eye…$"

VerdanturfTown_WandasHouse_Text_202FDB: @ 8202FDB
	.string "WALLY was in EVER GRANDE?\p"
	.string "His parents in PETALBURG would be\n"
	.string "astonished to hear that!$"

