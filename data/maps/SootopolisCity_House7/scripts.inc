SootopolisCity_House7_MapScripts:: @ 82270CB
	.byte 0

SootopolisCity_House7_EventScript_OldMan:: @ 82270CC
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF:: @ 82270D5
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano: @ 82270DE
	.string "An underwater volcano erupted and\n"
	.string "forced itself up from the depths.\p"
	.string "Its crater emerged from the sea and\n"
	.string "became filled with rainwater.\p"
	.string "That's how SOOTOPOLIS CITY came into\n"
	.string "being.$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething: @ 8227190
	.string "The cave that links SOOTOPOLIS and\n"
	.string "the outside world…\p"
	.string "It seems as if the cave was made to\n"
	.string "keep something from getting out.\p"
	.string "Or am I just imagining things?$"

