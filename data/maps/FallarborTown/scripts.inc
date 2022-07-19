FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Il se passe quelque chose d’étrange,\n"
	.string "je n’aime pas trop ça!\p"
	.string "J’ai aperçu quelqu’un entrer et sortir\n"
	.string "du LABO du PROF. KOSMO.$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Cela fait très longtemps que cette\n"
	.string "région est connue pour ses météorites.\p"
	.string "Un météorite se serait jadis écrasé,\n"
	.string "creusant le SITE METEORE.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Tu vois! Regarde!\n"
	.string "C’est mon cher AZURILL!\p"
	.string "Il est adroit, et en plus il est doux!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Azuzuuu.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "As-tu déjà affronté ADRIANE, le\n"
	.string "CHAMPION de l’ARENE de VERMILAVA?\p"
	.string "Son grand-père était célèbre.\n"
	.string "Il a fait partie du CONSEIL 4\l"
	.string "de la LIGUE POKéMON.\p"
	.string "Ça ne me surprendrait pas de voir\n"
	.string "ADRIANE devenir un grand DRESSEUR\l"
	.string "à son tour.$"

FallarborTown_Text_BattleTentSign:
	.string "TENTE DE COMBAT d’AUTEQUIA\n"
	.string "“Que les meilleures équipes\l"
	.string "se rencontrent!”$"

FallarborTown_Text_TownSign:
	.string "AUTEQUIA\n"
	.string "“Une communauté agricole et ses\l"
	.string "petits jardins.”$"

FallarborTown_Text_MoveTutorSign:
	.string "MAISON DU MAITRE DES CAPACITES\n"
	.string "“Venez apprendre de nouvelles\l"
	.string "capacités à vos POKéMON!”$"

