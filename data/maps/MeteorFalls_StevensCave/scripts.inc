.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "PIERRE: Oh, waouh, {PLAYER}{KUN}. Je suis\n"
	.string "surpris que tu aies su où me trouver.\p"
	.string "Est-ce que… tu me considères juste\n"
	.string "comme un maniaque du type ROCHE?\p"
	.string "Non, je ne pense pas…\p"
	.string "Nous nous sommes battus côte à côte\n"
	.string "au CENTRE SPATIAL d’ALGATIA.\p"
	.string "Tu dois savoir mieux que quiconque de\n"
	.string "quelle façon je me bats.\p"
	.string "OK, {PLAYER}{KUN}, si tu cherches un vrai défi,\n"
	.string "je suis ton homme!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Toi… Je ne pensais pas que tu\n"
	.string "avais progressé à ce point…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "PIERRE: En y repensant, j’en avais eu la\n"
	.string "certitude lors de notre première\p"
	.string "rencontre à la GROTTE GRANITE\n"
	.string "du VILLAGE MYOKARA.\p"
	.string "Ma première impression est souvent la\n"
	.string "bonne.\p"
	.string "Et où veux-tu te rendre?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Pfiuu, même moi, je n’aurais pas\n"
	.string "pu deviner ça.$"

