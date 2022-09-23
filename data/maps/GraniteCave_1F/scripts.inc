GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox GraniteCave_1F_Text_NoFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_NoFlash:
	.string "Hey, you. No need to worry about\n"
	.string "darkness.\p"
	.string "All the caves in HOENN happen to be well\n"
	.string "lit.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He should be up ahead.$"

