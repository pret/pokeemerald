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
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
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
	.string "Mijn papa heeft het me verteld.\p"
	.string "In deze tunnel wonen veel\n"
	.string "bange POKéMON.\p"
	.string "Van harde geluiden schrikken ze,\n"
	.string "en dan maken ze veel herrie.\p"
	.string "Daarom moest het grote tunnelplan\n"
	.string "stoppen.\p"
	.string "Maar er is één man. Hij graaft\n"
	.string "de tunnel helemaal alleen!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Er was een man die een tunnel\n"
	.string "groef voor een vrouw van wie hij hield.\p"
	.string "Ik snap het niet echt, maar ja!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Door de wind komt de as van de\n"
	.string "vulkaan nooit deze kant op.\p"
	.string "De lucht is hier schoon en fris.\n"
	.string "Hier wonen is heel gezond, ook\l"
	.string "voor zwakke en zieke mensen.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mijn POKéMON en ik winnen\n"
	.string "de laatste tijd steeds.\p"
	.string "Dus ik doe in deze stad voor het\n"
	.string "eerst mee aan de BATTLE TENT.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Heb je de grot naast de\n"
	.string "POKéMON MART gezien?\p"
	.string "Daar is een man die rotsen kapot\n"
	.string "slaat, zodat hij naar de andere\l"
	.string "kant kan.\p"
	.string "Het zou fijn zijn als we erdoor\n"
	.string "konden… Dan is RUSTBORO dichtbij.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Die grot naast de POKéMON MART is\n"
	.string "nu een tunnel naar de andere kant.\p"
	.string "Super! Nu kan ik makkelijk nieuwe\n"
	.string "DEVON-spullen kopen in RUSTBORO.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "“De winderige hooglanden met de\n"
	.string "zoete geur van gras.”$"

VerdanturfTown_Text_WandasHouse:
	.string "HUIS VAN WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF\n"
	.string "“Kijk je ogen uit bij gevechten!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "“Tussen RUSTBORO en VERDANTURF\p"
	.string "“Het tunnelplan is\n"
	.string "gestopt.”$"

