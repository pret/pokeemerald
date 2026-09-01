SafariZone_East_RestHouse_Frlg_MapScripts::
	.byte 0

SafariZone_East_RestHouse_EventScript_Rocker::
	msgbox SafariZone_East_Text_CaughtChanseyAllWorthwhile, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_HowManyDidYouCatch, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_BaldingMan::
	msgbox SafariZone_East_Text_TiredFromAllTheFun, MSGBOX_NPC
	end

SafariZone_East_Text_HowManyDidYouCatch::
	.string "How many did you catch?\n"
	.string "I'm bushed from the effort!$"

SafariZone_East_Text_CaughtChanseyAllWorthwhile::
	.string "I caught a CHANSEY!\p"
	.string "That makes this all worthwhile.$"

SafariZone_East_Text_TiredFromAllTheFun::
	.string "Whew!\n"
	.string "I'm tired from all the fun!$"

