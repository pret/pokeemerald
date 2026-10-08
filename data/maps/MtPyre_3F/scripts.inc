MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "De sfeer van de berg heeft mijn\n"
	.string "paranormale kracht vergroot!\p"
	.string "Een kind zoals jij…\n"
	.string "Droom je ervan te winnen?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Ik verdrink in zelfmedelijden…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mijn paranormale kracht is vast\n"
	.string "vele malen gegroeid, maar…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Dit is geen plek voor kinderen,\n"
	.string "zeker niet voor jou!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Dat verloor ik helemaal netjes…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Dit betekent dat mijn training\n"
	.string "nog niet genoeg is…\p"
	.string "Ik moet blijven werken richting\n"
	.string "de top…\p"
	.string "Aan de slag!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Waarom ben je hier gekomen?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Geweldig!\n"
	.string "Je bent een bijzondere TRAINER.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON die niet meer van deze\n"
	.string "wereld zijn.\l"
	.string "POKéMON die nu bij je zijn.\p"
	.string "En de POKéMON die je in de\n"
	.string "toekomst zult ontmoeten…\p"
	.string "Ze verdienen allemaal evenveel\n"
	.string "liefde. Onthoud dat.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Ik wil je POKéMON zien als ze\n"
	.string "wat meer gegroeid zijn…\p"
	.string "Alsjeblieft, ik moet je POKéNAV zien.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, jij bent het…\p"
	.string "Kom je me je gegroeide POKéMON\n"
	.string "laten zien?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Geweldig!\n"
	.string "Je bent een bijzonder mens.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON die niet meer van deze\n"
	.string "wereld zijn.\l"
	.string "POKéMON die nu bij je zijn.\p"
	.string "En de POKéMON die je in de\n"
	.string "toekomst zult ontmoeten…\p"
	.string "Ze verdienen allemaal evenveel\n"
	.string "liefde. Ik zie dat je het onthield.$"

