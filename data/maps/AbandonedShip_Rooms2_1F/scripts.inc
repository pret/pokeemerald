AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "JOE: En cherchant des trésors,\n"
	.string "on a découvert un DRESSEUR!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "JOE: On n’a pas réussi à gagner,\n"
	.string "même en se mettant ensemble…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "JOE: On n’a pas trouvé de trésors…\n"
	.string "Quelqu’un les aurait-il déjà pris?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "JOE: Tu n’as même pas deux POKéMON.\n"
	.string "N’espère pas nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "RITA: Oh?! On cherchait des trésors,\n"
	.string "mais on n’a trouvé qu’un DRESSEUR.$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "RITA: Oh, waouh, quelle force!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "RITA: Je me demande où les trésors\n"
	.string "peuvent bien être cachés.\p"
	.string "Je sais déjà ce que je vais m’acheter\n"
	.string "quand on les aura trouvés!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "RITA: Tu n’as pas deux POKéMON?\n"
	.string "On se battra une autre fois alors!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "RITA: Tu m’as mise en colère!\n"
	.string "Je vais t’enregistrer pour la peine!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "JOE: On a passé tout ce temps à\n"
	.string "chercher des trésors.\p"
	.string "Nos POKéMON sont devenus plus forts.\n"
	.string "On t’fait voir, OK?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "JOE: Toujours autant de force!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "JOE: On n’a pas trouvé de trésors,\n"
	.string "on a perdu notre combat de POKéMON…\p"
	.string "Je veux rentrer à la maison… Mais si je\n"
	.string "dis ça, elle va m’en vouloir…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "JOE: Tu n’as même pas deux POKéMON.\n"
	.string "N’espère pas nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "RITA: Oh, salut! Comme on s’retrouve!\p"
	.string "Tout comme nous, t’as pas arrêté de\n"
	.string "chercher des trésors!\p"
	.string "Si on se battait? Et le perdant arrête\n"
	.string "de chercher!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "RITA: Oh, on a encore perdu…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "RITA: On va élever le niveau de nos\n"
	.string "POKéMON.\p"
	.string "Et on ne rentrera pas à la maison avant\n"
	.string "d’avoir trouvé des trésors!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "RITA: Tu n’as pas deux POKéMON?\n"
	.string "On se battra une autre fois alors!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Je ne sais pas bien nager, mais quand\n"
	.string "il s’agit de se battre…$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oups, ça n’a pas vraiment bien marché.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Ça ne se fait pas vraiment de marcher\n"
	.string "pieds nus sur un bateau.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Force et compassion…\n"
	.string "Ce sont les trésors d’un DRESSEUR!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Quelque chose brille en toi, ça se\n"
	.string "voit tout de suite.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "J’ai vu quelque chose briller dans une\n"
	.string "des cabines du bateau.$"
