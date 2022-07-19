.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Mon papa m’a tout raconté.\p"
	.string "Il dit que ce tunnel est rempli de\n"
	.string "POKéMON craintifs.\p"
	.string "Ils ont tous peur du bruit et font\n"
	.string "beaucoup de brouhaha.\p"
	.string "Alors ils ont été obligés d’arrêter le\n"
	.string "projet du tunnel.\p"
	.string "Mais il y a encore un homme. Il essaie de\n"
	.string "creuser le tunnel tout seul!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Il y a un type qui a creusé un\n"
	.string "tunnel pour la fille qu’il aime.\p"
	.string "Moi, je n’le ferais pas, mais bon,\n"
	.string "après tout…$"

VerdanturfTown_Text_AirCleanHere:
	.string "Le vent n’amène jamais les cendres\n"
	.string "volcaniques par là.\p"
	.string "L’air est sain et délicieux ici.\n"
	.string "Vivre ici est très bénéfique, surtout\l"
	.string "pour les personnes chétives et malades.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mes POKéMON et moi venons de réussir\n"
	.string "une grande série de victoires\l"
	.string "consécutives.\p"
	.string "Alors j’ai décidé de nous essayer à la\n"
	.string "TENTE DE COMBAT de cette ville.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "As-tu vu la caverne près de la\n"
	.string "BOUTIQUE POKéMON?\p"
	.string "Il y a un type là-bas qui essaie de\n"
	.string "casser des rochers pour pouvoir passer\l"
	.string "et se rendre de ce côté.\p"
	.string "Ce serait super de pouvoir passer…\n"
	.string "Ça serait facile d’aller à MEROUVILLE.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Tu sais, cette caverne près de la\n"
	.string "BOUTIQUE POKéMON, elle relie\l"
	.string "désormais les deux côtés.\p"
	.string "C’est super! Plus de problème pour faire\n"
	.string "des courses chez DEVON à MEROUVILLE.$"

VerdanturfTown_Text_TownSign:
	.string "VERGAZON\p"
	.string "“Les montagnes où le vent souffle et\n"
	.string "où le doux parfum de l’herbe se dégage.”$"

VerdanturfTown_Text_WandasHouse:
	.string "MAISON DE SYLVIE$"

VerdanturfTown_Text_BattleTentSign:
	.string "TENTE DE COMBAT de VERGAZON\n"
	.string "“Venez admirer nos combats!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TUNNEL MERAZON\n"
	.string "“Passage entre MEROUVILLE\l"
	.string "et VERGAZON”.\p"
	.string "“Le projet de création du tunnel\n"
	.string "a été annulé.”$"

