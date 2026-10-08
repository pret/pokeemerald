LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applywaitmovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, dus ze kregen dubbel zoveel\n"
	.string "gasten met POKéMON als attractie?\p"
	.string "Hm, misschien maak ik een schattige\n"
	.string "POKéMON de mascotte van onze herberg.\p"
	.string "Zou dat meer gasten trekken?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, sorry, sorry!\n"
	.string "Ik was druk met tv kijken!\p"
	.string "Sinds TEAM AQUA in de stad is,\n"
	.string "blijven de toeristen weg.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hé, ga opzij!\n"
	.string "Ik kan de tv niet zien!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Wauw! Heeft een POKéMON iemands\n"
	.string "verloren voorwerp gevonden?\p"
	.string "Dat is wat. Met zo'n slimme\n"
	.string "POKéMON…\p"
	.string "Konden we alles terugvinden wat\n"
	.string "onze gasten kwijtraken…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, sorry, sorry!\n"
	.string "Ik was druk met tv kijken!\p"
	.string "Ik hoorde dat iemand de SCHUILPLAATS\n"
	.string "van TEAM AQUA heeft opgerold.\p"
	.string "Daardoor kregen we net een\n"
	.string "boeking van een grote groep.\p"
	.string "Een bedrijf dat… Eh…\n"
	.string "GAME iets heet…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Wauw! Heeft een POKéMON die op\n"
	.string "het huis paste een inbreker gepakt?\p"
	.string "Dat is wat. Met zo'n sterke\n"
	.string "POKéMON als bewaker…\p"
	.string "Konden we onze gasten meer\n"
	.string "veiligheid bieden.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, sorry, sorry!\n"
	.string "Ik was druk met tv kijken.\p"
	.string "O ja. Een grote groep gasten kwam\n"
	.string "net binnen.\p"
	.string "Ze boekten als GAME FREAK, dus\n"
	.string "ze maken vast spelletjes.\p"
	.string "Oeps, ik moet snel aan hun\n"
	.string "diner beginnen!$"

