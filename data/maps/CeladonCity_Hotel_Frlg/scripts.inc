CeladonCity_Hotel_Frlg_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
	.string "POKéMON?\n"
	.string "No, this is a hotel for people.\p"
	.string "We're full up, unfortunately.$"

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
	.string "I'm on vacation with my brother and\n"
	.string "boyfriend.\p"
	.string "CELADON is such a pretty city!$"

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
	.string "Why?\n"
	.string "Why did she bring her brother?$"

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
	.string "Yippee! I'm on vacation!\n"
	.string "My sis brought me along! Awesome!$"

