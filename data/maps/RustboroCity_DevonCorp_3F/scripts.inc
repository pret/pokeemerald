RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	delay 80
	applywaitmovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Ik ben MR. STONE, de DIRECTEUR van\n"
	.string "de DEVON CORPORATION.\p"
	.string "Ik hoorde net over jou!\p"
	.string "Je hebt onze medewerker niet één,\n"
	.string "maar twee keer gered!\p"
	.string "Ik wil iemand zo geweldig als jij\n"
	.string "om een gunst vragen.\p"
	.string "Je brengt een pakket naar de\n"
	.string "SCHEEPSWERF in SLATEPORT, toch?\p"
	.string "Kun je onderweg even langs\n"
	.string "DEWFORD TOWN gaan?\p"
	.string "Ik wil graag dat je een BRIEF\n"
	.string "bezorgt aan STEVEN in DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Weet wel dat ik een\n"
	.string "geweldige DIRECTEUR ben.\p"
	.string "Ik zou nooit zo gierig zijn om iets\n"
	.string "te vragen zonder iets terug te geven.\p"
	.string "Daarom wil ik je dit geven!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} krijgt een POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. STONE: Dat apparaat…\p"
	.string "Is een POKéMON NAVIGATOR, of kortweg\n"
	.string "POKéNAV.\p"
	.string "Een TRAINER op avontuur kan er\n"
	.string "niet zonder.\p"
	.string "Er zit een kaart van HOENN in.\p"
	.string "Zo vind je DEWFORD en SLATEPORT\n"
	.string "heel makkelijk!\p"
	.string "Trouwens, ik hoorde dat gemene\n"
	.string "boeven, MAGMA en AQUA geloof ik,\l"
	.string "overal problemen maken.\p"
	.string "Rust even goed uit voordat je\n"
	.string "vertrekt.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Nou, {PLAYER}{KUN},\n"
	.string "wees voorzichtig onderweg!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. STONE: Ik reken op je!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: Heb je mijn BRIEF bezorgd?\n"
	.string "Heel erg bedankt!\p"
	.string "Hier, als bedankje.\n"
	.string "Handig voor een TRAINER zoals jij.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: Een POKéMON die een\n"
	.string "EXP. DELER vasthoudt, krijgt een deel\l"
	.string "van de EXP.-punten van gevechten.\p"
	.string "Ook als hij zelf niet heeft\n"
	.string "gevochten.\p"
	.string "Een EXP. DELER is heel handig om\n"
	.string "zwakke POKéMON te trainen.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Ik werk al mijn hele leven\n"
	.string "heel hard.\p"
	.string "Daarom weet ik niet zoveel van\n"
	.string "wat er nu hip is.\p"
	.string "Maar willen alle jongeren TRAINER\n"
	.string "worden in de POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Dit is de tweede verdieping van de\n"
	.string "DEVON CORPORATION.\p"
	.string "Hier is het KANTOOR van onze\n"
	.string "DIRECTEUR.\p"
	.string "Ik ben je zo dankbaar voor wat\n"
	.string "je hebt gedaan.\p"
	.string "Eh… Trouwens, dat pakket dat je\n"
	.string "voor ons hebt teruggehaald…\p"
	.string "Wil jij dat naar de SCHEEPSWERF\n"
	.string "in SLATEPORT brengen?\p"
	.string "Het zou vreselijk zijn als die\n"
	.string "boeven het weer zouden stelen.\p"
	.string "Eh… Hehehe, dus, eh, kan ik\n"
	.string "op je rekenen?\p"
	.string "O ja, dat is waar.\n"
	.string "Wacht je hier even?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Onze DIRECTEUR wil je graag\n"
	.string "even spreken.\p"
	.string "Kom maar met me mee.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Ga je gang.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Als je naar de SCHEEPSWERF in\n"
	.string "SLATEPORT gaat, zoek CAPT. STERN op.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "De nieuwe HERHAALBALL en KLOKBALL\n"
	.string "van DEVON zijn heel populair bij\l"
	.string "TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Een verzameling zeldzame stenen\n"
	.string "die de DIRECTEUR heeft verzameld.$"

