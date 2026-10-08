MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Hier trainen wij DRAAK-trainers.\p"
	.string "Zelfs de KAMPIOEN komt hier.\n"
	.string "Zie je nu hoe speciaal het is?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "Ik dacht niet dat je zo sterk was!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "De weg voor ons is nog lang\n"
	.string "en zwaar.\p"
	.string "Wanneer worden mijn POKéMON en ik\n"
	.string "de beste?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Ik wil meer weten over je kracht.\n"
	.string "Ik zet je in mijn POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Sinds we elkaar zagen, trainden we\n"
	.string "hard om de beste te worden.\p"
	.string "Laat zien hoeveel sterker\n"
	.string "we zijn geworden!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "Ik dacht niet dat je zo sterk was!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Je hebt duidelijk doorgetraind\n"
	.string "met je POKéMON.\p"
	.string "Zolang jij sterk blijft, kan ik\n"
	.string "ook sterker worden!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: We vechten altijd samen\n"
	.string "met POKéMON, als stel.\l"
	.string "We vertrouwen op onszelf.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Oei.\n"
	.string "We hebben verloren, lieve vrouw.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: We zijn al vijftig jaar\n"
	.string "getrouwd.\p"
	.string "Eigenlijk heb ik mijn lieve vrouw\n"
	.string "nog nooit verslagen.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Nou, wat een jonge TRAINER!\p"
	.string "Vecht je met ons? Kom dan terug\n"
	.string "met meer POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Jonge TRAINER, als het kan,\n"
	.string "vecht je dan nog eens met ons?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: We zijn al vijftig jaar\n"
	.string "getrouwd.\p"
	.string "Onze band als stel is\n"
	.string "onbreekbaar.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Oei.\n"
	.string "We hebben verloren, lieve man.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Vijftig jaar huwelijk…\p"
	.string "Als we ruzie hadden, losten we\n"
	.string "het altijd op met een POKéMON-gevecht…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Nou, wat een jonge TRAINER!\p"
	.string "Als je met ons wilt vechten,\n"
	.string "kom dan terug met meer POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: We vechten altijd samen\n"
	.string "met POKéMON, als stel.\l"
	.string "We vertrouwen op onszelf.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Oei.\n"
	.string "We hebben verloren, lieve vrouw.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Vijftig jaar getrouwd…\p"
	.string "Achteraf gezien vochten mijn vrouw\n"
	.string "en ik elke dag…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Nou, wat een jonge TRAINER!\p"
	.string "Vecht je met ons? Kom dan terug\n"
	.string "met meer POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: We zijn al vijftig jaar\n"
	.string "getrouwd.\p"
	.string "We steunden elkaar al die tijd.\n"
	.string "Zo werden we sterk.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Oei.\n"
	.string "We hebben verloren, lieve man.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Vijftig jaar huwelijk…\n"
	.string "Wat is er veel gebeurd.\p"
	.string "Ik hoop dat we samen nog veel\n"
	.string "fijne herinneringen maken.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Nou, wat een jonge TRAINER!\p"
	.string "Als je met ons wilt vechten,\n"
	.string "kom dan terug met meer POKéMON.$"

