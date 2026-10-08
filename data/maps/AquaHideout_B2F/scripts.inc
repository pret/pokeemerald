AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applywaitmovement VAR_0x8008, Common_Movement_ExclamationMark
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applywaitmovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	delay 20
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applywaitmovement VAR_0x8008, Common_Movement_FacePlayer
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Al hier, hè?\n"
	.string "We onderschatten je!\p"
	.string "Maar nu is het afgelopen!\p"
	.string "Ik ben beter dan de HANDLANGERS\n"
	.string "die je tot nu toe zag.\p"
	.string "Ik speel geen spelletjes.\n"
	.string "Ik ga je verpletteren!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "Ook ik verloor…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Terwijl ik met je speelde, was onze\n"
	.string "BAAS klaar met zijn voorbereidingen!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "Onze BAAS is al op weg naar een\n"
	.string "grot onder de zee!\p"
	.string "Wil je hem achterna? Zoek dan op\n"
	.string "de grote, wijde zee voorbij\l"
	.string "LILYCOVE.\p"
	.string "Maar vind je hem dan?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Hahaha, ik werd het wachten zat!\n"
	.string "Jij bent me ook een gevecht schuldig!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Wachten werd te veel…\n"
	.string "Verloren en suf…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BAAS…\n"
	.string "Was dit goed genoeg?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Warp-panelen, de trots van\n"
	.string "de SCHUILPLAATS!\p"
	.string "Je weet niet waar je bent, hè?\p"
	.string "Maak de vijand in de war en moe,\n"
	.string "dan slaan we toe! Dat is ons plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Wat is er mis met jou?\n"
	.string "Je bent helemaal niet moe!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Nu ik eraan denk… Ik weet niet\n"
	.string "meer waar ik de MASTER BALL liet.\p"
	.string "Als ik hem niet bewaak, krijg ik\n"
	.string "van onze BAAS op mijn kop…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Toen ik bij TEAM AQUA kwam, moest\n"
	.string "ik eerst leren hoe deze warp-\l"
	.string "panelen verbonden zijn.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Ik dacht te veel na over\n"
	.string "de warp-panelen…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Ik moet leren hoe ik beter\n"
	.string "kan vechten…$"
