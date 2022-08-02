AbandonedShip_Rooms2_B1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_B1F_EventScript_Camper::
	msgbox AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring, MSGBOX_NPC
	end

AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring:
.ifdef ENGLISH
	.string "This is a perfect place to go exploring!\n"
	.string "It's exciting here!\p"
	.string "I bet there're amazing treasures on\n"
	.string "board.$"
.else
.ifdef FRENCH
	.string "C’est l’endroit idéal pour une petite\n"
	.string "exploration! C’est passionnant ici!\p"
	.string "Je parie qu’il y a de stupéfiants\n"
	.string "trésors à bord.$"
.endif
.endif
