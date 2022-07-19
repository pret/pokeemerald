.set LOCALID_NURSE, 1
.set LOCALID_LANETTE, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Oh, bonjour.\n"
	.string "Qui es-tu?\p"
	.string "D’accord, tu t’appelles {PLAYER}{KUN}.\n"
	.string "Tu es DRESSEUR, apparemment.\p"
	.string "Cela veut donc dire que tu utilises ce\n"
	.string "programme de Gestion de Stocks de\l"
	.string "POKéMON que j’ai développé.\p"
	.string "Enfin, c’est une conclusion que je tire\n"
	.string "d’un processus de déduction simple.\p"
	.string "Tu me parles parce que tu veux\n"
	.string "accéder à quelque chose sur ce PC.\p"
	.string "Oh, pardon, je ne me suis pas présentée.\n"
	.string "Je m’appelle ANNETTE.\p"
	.string "Enchantée. Je suis contente que tu\n"
	.string "utilises la Gestion de Stocks.\p"
	.string "Si tu en as l’occasion, viens me rendre\n"
	.string "visite. J’habite sur la ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Je me demande à quoi ressemblaient les\n"
	.string "POKéMON durant la préhistoire.\p"
	.string "Le MANIAQUE DES FOSSILES qui vit\n"
	.string "en bordure de la ville doit le savoir.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Dans les champs d’AUTEQUIA,\n"
	.string "nous mettons de jeunes plants en\l"
	.string "terre. Ce sont des arbres très vivaces\l"
	.string "qui poussent dans la cendre volcanique.$"

