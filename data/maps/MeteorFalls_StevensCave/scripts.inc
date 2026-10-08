MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh wow, {PLAYER}{KUN}.\n"
	.string "Gaaf dat je wist waar ik was.\p"
	.string "Denk je dat ik… eh… alleen maar\n"
	.string "een steengek ben?\p"
	.string "Nee, dat kan niet kloppen.\p"
	.string "We vochten samen bij het\n"
	.string "SOOTOPOLIS SPACE CENTER.\p"
	.string "Je weet dus goed hoe sterk ik ben.\p"
	.string "Oké, {PLAYER}{KUN}, als je me serieus\n"
	.string "uitdaagt, verwacht het ergste!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Jij…\n"
	.string "Ik wist niet dat je zo sterk was…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Nu ik erover nadenk, sinds\n"
	.string "we elkaar zagen in GRANITE CAVE\l"
	.string "bij DEWFORD, voelde ik het al.\p"
	.string "Ik dacht dat je ooit\n"
	.string "KAMPIOEN zou worden.\p"
	.string "Mijn voorspellingen komen meestal uit.\p"
	.string "En waar ga je nu heen?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hihihi, dat weet zelfs ik niet.$"

