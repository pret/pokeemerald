MauvilleCity_House1_MapScripts:: @ 820F975
	.byte 0

MauvilleCity_House1_EventScript_20F976:: @ 820F976
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM06, MauvilleCity_House1_EventScript_20F9A5
	msgbox MauvilleCity_House1_Text_20F9AF, MSGBOX_DEFAULT
	giveitem_std ITEM_HM06
	setflag FLAG_RECEIVED_HM06
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_20FAA9, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_20F9A5:: @ 820F9A5
	msgbox MauvilleCity_House1_Text_20FB67, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_20F9AF: @ 820F9AF
	.string "Woohoo!\p"
	.string "I hear people call me the ROCK SMASH\n"
	.string "GUY, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the ROCK SMASH DUDE.\p"
	.string "Woohoo!\p"
	.string "Anyways, your POKéMON look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this HIDDEN MACHINE!$"

MauvilleCity_House1_Text_20FAA9: @ 820FAA9
	.string "That HM contains ROCK SMASH.\p"
	.string "If you come across large boulders\n"
	.string "that block your path…\p"
	.string "Well, use that HM move and smash\n"
	.string "them right out of your way!\p"
	.string "Yes, sir! Smash rocks aside, I say!\n"
	.string "Woohoo!$"

MauvilleCity_House1_Text_20FB67: @ 820FB67
	.string "Oh, yes, if you smash a rock, a POKéMON\n"
	.string "could come flying out of hiding.\p"
	.string "Woohoo!$"

