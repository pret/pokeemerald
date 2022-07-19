@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Ce POKéMON a déjà gagné le CONCOURS\n"
	.string "DE BEAUTE ici.\p"
	.string "Et tu sais quoi? Je lui ai fait gagner le\n"
	.string "CONCOURS D’INTELLIGENCE, aujourd’hui!\p"
	.string "Je m’effraie moi-même…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "J’ai fait pas mal de CONCOURS,\n"
	.string "donc je sais comment ça se passe.\p"
	.string "Dans un CONCOURS DE SANG-FROID, les\n"
	.string "capacités SANG-FROID ont du succès.\p"
	.string "Mais les capacités INTELLIGENCE et\n"
	.string "GRACE, par exemple, n’ont pas trop\l"
	.string "d’effet.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Le jeune garçon qui vient de gagner\n"
	.string "avait plein de {POKEBLOCK}S différents.\p"
	.string "Tu gagnerais, toi, si t’en avais autant?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Waouh, cet endroit est super!\p"
	.string "On peut sentir la tension dans l’air…\n"
	.string "Ça, c’est un vrai lieu de CONCOURS.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "ANIMATRICE: POKéMON INTELLIGENTS\n"
	.string "et leurs DRESSEURS, vous êtes prêts?!\p"
	.string "Montrez-vous sous votre meilleur jour!\n"
	.string "C’est parti!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JUGE: Vous aimez ce genre de CONCOURS?\p"
	.string "Revenez avec trois amis et vous\n"
	.string "pourrez tous participer à un CONCOURS!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Aïe, aïe, aïe…\n"
	.string "Je me suis trompé de CONCOURS.\p"
	.string "J’ai inscrit ce POKéMON ROBUSTE à un\n"
	.string "CONCOURS D’INTELLIGENCE…\p"
	.string "Allez, montre-leur ton ECLATE-ROC.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Cela m’a pris des années et beaucoup\n"
	.string "de sagesse, pour que ce POKéMON\l"
	.string "devienne aussi intelligent.\p"
	.string "Il ne se laisse pas battre par n’importe\n"
	.string "quel POKéMON inexpérimenté.$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Voilà!\p"
	.string "Une capacité INTELLIGENCE maintenant,\n"
	.string "et l’enthousiasme du public augmentera!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, non!\p"
	.string "J’utilise tout le temps le VAMPIRISME\n"
	.string "de mon NOSFERAPTI, il est si gracieux!\p"
	.string "Mais ces gens sont méchants et\n"
	.string "n’apprécient pas du tout!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Ouais! T’es super, pépé!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Même quand les DRESSEURS inscrivent\n"
	.string "le même genre de POKéMON, ils semblent\l"
	.string "utiliser des capacités différentes.\p"
	.string "C’est comme pour les combats, chacun\n"
	.string "a son propre style.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Je trouve que les POKéMON ont l’air bien\n"
	.string "plus intelligents que leurs DRESSEURS.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Par-dessus tout, j’adore les\n"
	.string "CONCOURS D’INTELLIGENCE.\p"
	.string "Cette couleur verte si intellectuelle…\n"
	.string "C’est… super cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "ANIMATRICE: Tu vas aussi participer au\n"
	.string "CONCOURS DE BEAUTE? Bonne chance!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JUGE: Ah, les POKéMON ici présents\n"
	.string "sont des spécimens d’une rare beauté!\p"
	.string "Oh, j’en ai presque oublié de les noter!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON de cette magnificence…\n"
	.string "Il n’y en a pas deux comme ça.\p"
	.string "Tout le monde sera subjugué par tant\n"
	.string "de beauté.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Ahhhhh!\p"
	.string "J’ai brossé et coiffé mon POKéMON\n"
	.string "avec soin pour ce CONCOURS…\p"
	.string "Mais j’ai exagéré…\n"
	.string "Maintenant, il a le poil tout ébouriffé…\p"
	.string "Qu’est-ce que je peux faire?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Cette ONDE BOREALE est si éblouissante\n"
	.string "que le JUGE ne pourra pas la voir.\p"
	.string "Euh, attends…\n"
	.string "Mais ça sert à rien, alors!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Ce joli POKéMON, c’est exactement moi\n"
	.string "quand j’étais plus jeune.\p"
	.string "Juste au moment où je l’ai dit, mon mari\n"
	.string "s’est étouffé avec son café.\p"
	.string "J’ai dit quelque chose d’amusant?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Tu sais, en tant que femme, je serais\n"
	.string "plus qu’heureuse de gagner un CONCOURS\l"
	.string "DE BEAUTE.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Waouhhhh!\p"
	.string "Tu devrais jeter un coup d’œil\n"
	.string "à ces jolis POKéMON.\p"
	.string "Quelle splendeur! J’adore!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Tu ne peux pas toujours compter\n"
	.string "sur la beauté uniquement.\p"
	.string "Tu dois aussi coiffer ton POKéMON, pour\n"
	.string "qu’il soit aussi brillant que le mien.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "ANIMATRICE: Hum! Ohé!\n"
	.string "On est en plein CONCOURS!\p"
	.string "Veuillez vous inscrire au guichet et\n"
	.string "revenez ensuite, vous voulez bien?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JUGE: Oh, quelles démonstrations\n"
	.string "ravissantes et gracieuses!\p"
	.string "Juste ciel! Quelle parfaite et adorable\n"
	.string "démonstration de TOURNIQUET!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, non… Mon doux AZURILL s’est\n"
	.string "laissé distraire par un autre POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mon POKéMON ne gagne jamais de combat,\n"
	.string "mais en CONCOURS, c’est le meilleur!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "La DANSE-FLEUR de mon POKéMON est une\n"
	.string "merveille d’élégance.\p"
	.string "Je ne laisserai personne perturber sa\n"
	.string "prestation.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Tous les POKéMON sont gracieux.\p"
	.string "Mais si mon POKéMON faisait une\n"
	.string "démonstration de grâce…\p"
	.string "Je suis sûre qu’il serait beaucoup plus\n"
	.string "gracieux que les autres.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mon enfant participe au CONCOURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Vas-y, courage!\n"
	.string "Ton POKéMON est le meilleur!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Je trouve que cette fille est vraiment\n"
	.string "la plus gracieuse.\p"
	.string "Comment? Ils jugent les POKéMON\n"
	.string "sur leur apparence?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Oh, regarder tous ces gracieux POKéMON\n"
	.string "me donne envie d’en avoir un!\p"
	.string "Je vais aller en attraper quelques-uns!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "EPREUVE DE BEAUTE\n"
	.string "POKéMON D’UNE BEAUTE EPOUSTOUFLANTE!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "EPREUVE DE GRACE\n"
	.string "POKéMON D’UNE GRACE EXTREME!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "EPREUVE D’INTELLIGENCE\n"
	.string "POKéMON D’UNE INTELLIGENCE INOUIE!$"

