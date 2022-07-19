SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM49, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM49
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM49
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Ah, un lit!\n"
	.string "Je vais me reposer.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Je vais souvent à NENUCRIQUE.\p"
	.string "C’est parce que j’aime faire des\n"
	.string "CONCOURS POKéMON, tu vois.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "C’était un match très intéressant!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Je suis tout nerveux à l’idée de\n"
	.string "découvrir de nouveaux POKéMON pendant\l"
	.string "les CONCOURS. J’ai hâte d’y être!$"

SSTidalRooms_Text_MicahIntro:
	.string "Tes amis sont-ils puissants?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Ah oui, tes amis sont puissants!$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Les amis ne sont pas forcément humains.\n"
	.string "Mes POKéMON sont mes meilleurs amis!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Dis-moi…\n"
	.string "Tu as frappé avant d’entrer?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "On doit accepter la défaite calmement,\n"
	.string "sans paniquer.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Un véritable GENTLEMAN ne doit jamais\n"
	.string "s’énerver, quelle que soit la situation.$"

SSTidalRooms_Text_JedIntro:
	.string "ALI: Ça me gêne un peu, mais… On va\n"
	.string "te montrer le pouvoir de notre amour!$"

SSTidalRooms_Text_JedDefeat:
	.string "ALI: Soupir…$"

SSTidalRooms_Text_JedPostBattle:
	.string "ALI: C’est la première fois que le\n"
	.string "pouvoir de notre amour n’est pas le\l"
	.string "plus fort! Tu es un DRESSEUR puissant!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "ALI: Tu n’as qu’un POKéMON?\n"
	.string "La solitude ne te pèse pas trop?$"

SSTidalRooms_Text_LeaIntro:
	.string "LISE: C’est un peu naïf, mais… On va\n"
	.string "te montrer le pouvoir de notre amour!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LISE: Ouin-ouin!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LISE: Je n’y crois pas! Le pouvoir de\n"
	.string "notre amour n’a pas été le plus fort…\p"
	.string "Tu es un DRESSEUR très puissant!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LISE: Je voulais me battre…\n"
	.string "Mais tu n’as même pas deux POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, tu arrives à temps.\p"
	.string "Je m’ennuie terriblement, tu sais.\n"
	.string "Tu vas me divertir.$"

SSTidalRooms_Text_GarretDefeat:
	.string "Pfff… Tu m’as bien diverti.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Je devrais peut-être demander à mon\n"
	.string "père de m’acheter un yacht.\p"
	.string "Un yacht rien que pour mes POKéMON\n"
	.string "et moi!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, quel DRESSEUR adorable tu es.\n"
	.string "Veux-tu prendre un thé?\p"
	.string "Ou préfères-tu te battre?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Je vois.\n"
	.string "Tu es du genre entreprenant.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Une croisière autour du monde dans un\n"
	.string "yacht de luxe n’est pas sans charme…\p"
	.string "Mais je dois bien avouer que voyager\n"
	.string "dans un ferry est plutôt plaisant.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Heu… Salut! Je… Non, je n’ai pas l’air\n"
	.string "suspect! Hé… Tu veux ça? C’est gratuit!\p"
	.string "C’est… Je le jure, je ne l’ai pas volé!\n"
	.string "Je n’oserais jamais voler! SAISIE?\p"
	.string "Ne crains rien! Tu peux t’en servir!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SAISIE permet de voler l’attaque\n"
	.string "ennemie et d’en obtenir les effets.$"

