RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Heel lang geleden was DEVON nog\n"
	.string "maar een piepklein bedrijfje.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Mijn papa werkt bij het BEDRIJF.\p"
	.string "Mijn papa heeft dit gemaakt!\n"
	.string "Maar ik kan er niks mee, dus jij mag het.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Mijn papa werkt bij het BEDRIJF.\p"
	.string "Als ik groot ben, ga ik ook\n"
	.string "bij DEVON werken.$"

