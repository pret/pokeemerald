PacifidlogTown_House1_MapScripts:: @ 820365C
	.byte 0

PacifidlogTown_House1_EventScript_Man:: @ 820365D
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman:: @ 8203666
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory: @ 820366F
	.string "In the HOENN region, there are three\n"
	.string "POKéMON that represent the power of\l"
	.string "rock, ice, and steel.\p"
	.string "Each of them is said to hide away deep\n"
	.string "inside caves.\p"
	.string "That's the story I heard when I was\n"
	.string "just a little kid.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors: @ 820373A
	.string "“Six dots open three doors.”\p"
	.string "Grandpa used to say that, but I don't\n"
	.string "know what he meant.$"

