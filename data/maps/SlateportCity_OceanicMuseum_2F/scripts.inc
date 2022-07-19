.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Oui? Si tu cherches POUPE,\n"
	.string "c’est bien moi.\p"
	.string "Ah! Ça doit être ce que j’avais\n"
	.string "commandé à M. ROCHARD de DEVON.\p"
	.string "Merci. Formidable! Nous allons désormais\n"
	.string "pouvoir préparer l’expédition!$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hé, hé, hé, pas si vite!\n"
	.string "On va prendre ces pièces!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. POUPE: Qu… quoi?\n"
	.string "Qui êtes-vous, jeunes gens?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "On est la TEAM AQUA!\p"
	.string "Notre CHEF veut ces pièces!\n"
	.string "Ferme-la et balance-les!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaaah!\n"
	.string "Se faire battre par un gosse!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, mon dieu, quel désastre…\n"
	.string "Le CHEF va être furieux…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Hum, espèce de mauviette!\n"
	.string "Laisse-moi régler ça!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Quoi?!\n"
	.string "Moi aussi, j’ai perdu!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Et maintenant? Si on ne récupère\n"
	.string "pas les pièces, on est faits!\p"
	.string "Ah, j’avais pas prévu d’être gêné\n"
	.string "par un mouflet qui se mêle de tout!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Je venais voir pourquoi vous mettiez\n"
	.string "tant de temps à récupérer les pièces et\p"
	.string "je constate que vous êtes retenus par\n"
	.string "un simple mioche!$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Nous sommes la TEAM AQUA,\n"
	.string "et nous adorons la mer!\p"
	.string "Moi, je suis ARTHUR, le leader\n"
	.string "de la TEAM AQUA.\p"
	.string "Dis-moi, pourquoi te mêles-tu de\n"
	.string "nos affaires?\p"
	.string "Attends un peu, appartiendrais-tu\n"
	.string "à la TEAM MAGMA?\p"
	.string "Non, ce n’est pas possible, tu ne\n"
	.string "portes pas leur uniforme.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Les POKéMON, les gens, toute la vie\n"
	.string "dépend de la mer.\p"
	.string "C’est pourquoi le but premier de la\n"
	.string "TEAM AQUA est l’expansion de la mer.\p"
	.string "Nous défendons une noble cause.\n"
	.string "Tu ne crois pas? \p"
	.string "Ah, oui…\n"
	.string "Tu es trop jeune pour comprendre.\p"
	.string "Ça ne facilite pas les choses que tu\n"
	.string "ne comprennes pas nos idéaux.\p"
	.string "Mais je te préviens, ne t’avise pas\n"
	.string "de te mêler encore de nos histoires.\p"
	.string "Les conséquences seraient terribles.\p"
	.string "N’oublie pas ce conseil!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPT. POUPE: Tu es…\n"
	.string "Ah oui, tu es {PLAYER}{KUN}…\p"
	.string "En tout cas, que de tension!\n"
	.string "Merci de nous avoir sauvés!\p"
	.string "Ah oui, j’avais presque oublié que tu\n"
	.string "avais apporté les pièces de DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. POUPE: Zou!\n"
	.string "Il n’y a pas de temps à perdre!\p"
	.string "Il faut qu’on prépare cette expédition\n"
	.string "sous-marine au plus vite.\p"
	.string "Merci encore, mais il faut que j’y\n"
	.string "aille maintenant.\p"
	.string "Mais n’hésite pas à jeter un œil\n"
	.string "ici si tu en as envie.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "J’ai vu la maquette d’un bateau ici.\p"
	.string "Ça m’a fait penser à l’EPAVE,\n"
	.string "près du VILLAGE MYOKARA…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "N’essaie même pas de courir\n"
	.string "dans le MUSEE!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Waouh, quel sous-marin imposant!\n"
	.string "Je veux faire un tour!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "L’étiquette indique: “ECHANTILLON\n"
	.string "POUR TEST DE LA QUALITE DE L’EAU”.\p"
	.string "La mer forme un seul ensemble, mais\n"
	.string "l’eau est différente selon les régions.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "L’étiquette indique: “ECHANTILLON\n"
	.string "POUR TEST DE LA QUALITE DE L’EAU”.\p"
	.string "La salinité de l’eau diffère peut-être\n"
	.string "d’une région à l’autre…$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Une balle en caoutchouc s’allonge\n"
	.string "et rétrécit.\p"
	.string "“Dans la mer, le poids de l’eau\n"
	.string "exerce lui-même une pression.”\p"
	.string "“En eau peu profonde, la pression\n"
	.string "n’est pas très élevée.”\p"
	.string "“Par contre, en profondeur, la pression\n"
	.string "peut atteindre des dizaines de milliers\l"
	.string "de tonnes sur une petite surface.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "MAQUETTE DE LA REGION DE HOENN\p"
	.string "C’est un diorama de la région de HOENN.\p"
	.string "Où est représenté BOURG-EN-VOL?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "C’est la représentation du mouvement\n"
	.string "de l’eau de mer.\p"
	.string "“Au fond de la mer, les variations de\n"
	.string "certains facteurs tels que la\l"
	.string "température et la salinité provoquent\l"
	.string "le mouvement de l’eau.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "C’est la représentation du mouvement\n"
	.string "de l’eau de mer.\p"
	.string "“En surface, l’eau de mer circule comme\n"
	.string "des courants poussés par le vent.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "Le ferry LE MARINA\p"
	.string "Réplique à l’échelle du bateau en\n"
	.string "construction au CHANTIER NAVAL\l"
	.string "DE POUPE.$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "SOUS-MARIN D’EXPLORATION 1\p"
	.string "Réplique du performant sous-marin\n"
	.string "d’exploration des fonds marins.$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "CAPSULE SUBMERSIBLE\p"
	.string "Réplique d’une capsule compacte\n"
	.string "pour explorer les fonds marins.$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "L’OCEANE\p"
	.string "Réplique du luxueux paquebot\n"
	.string "qui fait le tour de la planète.$"

