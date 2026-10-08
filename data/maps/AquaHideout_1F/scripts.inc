AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Wat? Wat? Wat moet je van\n"
	.string "TEAM AQUA?\p"
	.string "Onze BAAS is er niet! Hij is iets\n"
	.string "belangrijks gaan pakken!\p"
	.string "… …\n"
	.string "Waar hij heen ging?\p"
	.string "Hahaha! Denk je echt dat ik zoiets\n"
	.string "belangrijks aan jou vertel?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Wat? Wat?\n"
	.string "Ben jij een TEAM MAGMA-HANDLANGER?\p"
	.string "Ik hoor dat TEAM MAGMA een gaaf\n"
	.string "POKéMON wil wekken in hun\l"
	.string "SCHUILPLAATS.\p"
	.string "Maar waar zou die zijn?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Wat? Wat? Wat moet je van\n"
	.string "TEAM AQUA?\p"
	.string "Onze BAAS is er niet!\n"
	.string "Hij is een duikboot gaan jatten!\p"
	.string "… …\n"
	.string "Waar hij heen ging?\p"
	.string "Hahaha! Denk je echt dat ik zoiets\n"
	.string "belangrijks aan jou vertel?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Wat? Wat? Wat moet je van\n"
	.string "TEAM AQUA?\p"
	.string "Onze BAAS is er niet! Hij is op weg\n"
	.string "naar MT. PYRE op ROUTE 122!\p"
	.string "… …\n"
	.string "Waarom hij ging?\p"
	.string "Hahaha! Denk je echt dat ik zoiets\n"
	.string "belangrijks aan jou vertel?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Wat? Wat?\n"
	.string "Ben jij een TEAM MAGMA-HANDLANGER?\p"
	.string "Ik hoor dat TEAM MAGMA een gaaf\n"
	.string "POKéMON zoekt bij MT. CHIMNEY.\p"
	.string "Maar wat voor POKéMON is dat?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Wat? Wat? Wat moet je van\n"
	.string "TEAM AQUA?\p"
	.string "Onze BAAS is er niet!\n"
	.string "Hij is op weg naar SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Waarom hij ging?\p"
	.string "Hahaha! Denk je echt dat ik zoiets\n"
	.string "belangrijks aan jou vertel?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Aaaah!\n"
	.string "Ik zie een verdacht figuur!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "Ik heb verloren!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Ik verloor voor het TEAM,\n"
	.string "maar ik deed mijn werk…$"

