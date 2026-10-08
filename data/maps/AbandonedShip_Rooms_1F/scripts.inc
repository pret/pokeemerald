AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Zulke schepen zijn zeldzaam,\n"
	.string "dus ik kijk even rond.\p"
	.string "Hmhm…\n"
	.string "Er lijken nog meer hutten te zijn…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Waarom kom jij hier nou?\n"
	.string "Je bent vast heel nieuwsgierig!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Niet alleen nieuwsgierig, maar\n"
	.string "ook sterk…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Die man hiernaast…\p"
	.string "Hij zegt dat hij alleen rondkijkt,\n"
	.string "maar ik weet het niet, hoor.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Jij bent een sterke TRAINER!\n"
	.string "Ik zet je in mijn POKéNAV!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Waarom kom je nou terug?\n"
	.string "Je bent echt heel nieuwsgierig!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Ben jij niet té sterk?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Die man is vast iets van plan!\n"
	.string "Hij doet zo raar!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "Ik ben gevonden! …Huh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "O, jij bent mijn mama niet.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Mama is boos op me, dus ik ben\n"
	.string "weggerend. Zeg niet waar ik ben!$"

