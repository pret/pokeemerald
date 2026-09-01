SafariZone_East_Frlg_MapScripts::
	.byte 0

SafariZone_East_EventScript_RestHouseSign::
	msgbox SafariZone_East_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_East_EventScript_TrainerTips::
	msgbox SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk, MSGBOX_SIGN
	end

SafariZone_East_EventScript_AreaSign::
	msgbox SafariZone_East_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_East_Text_RestHouse::
	.string "REST HOUSE$"

SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk::
	.string "TRAINER TIPS\p"
	.string "The remaining time declines only\n"
	.string "while you walk.$"

SafariZone_East_Text_AreaSign::
	.string "AREA 1\n"
	.string "WEST: CENTER AREA$"

