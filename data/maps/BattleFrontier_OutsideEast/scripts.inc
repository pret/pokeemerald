.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "TOUR DE COMBAT\n"
	.string "“Enchaînez les victoires!”$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "PALACE DE COMBAT\n"
	.string "“Gardez un œil sur vos POKéMON!”$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "DOJO DE COMBAT\n"
	.string "“Que les équipes se forment!”$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "PYRAMIDE DE COMBAT\n"
	.string "“Découvrez l’aventure du COMBAT\l"
	.string "QUETE!”$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "HALL DE CLASSEMENT\n"
	.string "“Jetez un œil aux records des\l"
	.string "meilleurs!”$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "SERVICE D’ECHANGE\n"
	.string "“Echangez vos POINTS DE COMBAT!”$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Waouh!\n"
	.string "C’est immense!\p"
	.string "La TOUR DE COMBAT est un endroit\n"
	.string "unique. Il ne ressemble à aucun autre.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Ma grande ambition est de conquérir la\n"
	.string "ZONE DE COMBAT et la LIGUE POKéMON.\p"
	.string "Si mon rêve se réalise…\p"
	.string "Je demanderai à MIMI si elle veut bien\n"
	.string "être mon amie!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PYRAMIDE DE COMBAT est trop dure!\n"
	.string "Je n’arrive pas à atteindre le sommet!\p"
	.string "Je pense que je vais essayer de\n"
	.string "l’atteindre par l’extérieur…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Je m’épanouis dans l’obscurité…\n"
	.string "Oui… Ce qui compte à mes yeux?\l"
	.string "La PYRAMIDE DE COMBAT…\p"
	.string "J’aime me promener dans l’obscurité la\n"
	.string "plus totale, au bord du désespoir.$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Je n’ai pas dormi depuis une semaine,\n"
	.string "mais j’ai réuni une super équipe!\p"
	.string "Franchement, je ne peux pas perdre.\n"
	.string "A moi le DOJO DE COMBAT!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Tu es ici grâce à SCOTT?\n"
	.string "Il est bizarre, quand même, non?\p"
	.string "Il est très fort pour repérer les\n"
	.string "DRESSEURS qui ont du talent, oui…\p"
	.string "Mais je ne l’ai absolument jamais vu\n"
	.string "se battre.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Je crois en toi, mon bébé!\p"
	.string "Je te préparerai tout ce que tu voudras\n"
	.string "si tu gagnes, mon petit ZIGG!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZATON a l’air absent…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Les cuisiniers du PALACE disent que je\n"
	.string "suis un fouineur. C’est peut-être vrai…\p"
	.string "Ta toque est de travers!\n"
	.string "C’est tombé par terre, ramasse vite!\l"
	.string "Vite, c’est presque l’heure du dîner!\p"
	.string "Je ne peux pas m’empêcher de mettre\n"
	.string "mon grain de sel…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Je ne fais plus très peur, mais dans le\n"
	.string "temps, j’ai battu un CHAMPION D’ARENE.\p"
	.string "Qui sait, peut-être que je devrais m’y\n"
	.string "remettre!?!$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sur mon VELO, je suis rapide.\n"
	.string "Aux combats aussi!\p"
	.string "Je gagne mes combats en un clin\n"
	.string "d’œil!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Je suis plus forte que mon père\n"
	.string "aux POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Allez, mon bébé!\n"
	.string "Va gagner pour papa!\p"
	.string "Tu ressembles à ta mère, tu vas les\n"
	.string "mener par le bout du nez!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Je viens de très loin, j’avais entendu\n"
	.string "dire qu’il y avait une jolie fille au DOJO\l"
	.string "DE COMBAT.\p"
	.string "Tu sais ce que j’ai trouvé à\n"
	.string "la place?\p"
	.string "Un ramassis de fanas d’arts\n"
	.string "martiaux!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Des fois, je vois un vieil homme à l’air\n"
	.string "très important qui entre ici.\p"
	.string "Il a des POKéMON magnifiques.\n"
	.string "Il a l’air très gentil.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Tu la connais, la légende de la\n"
	.string "PYRAMIDE DE COMBAT?\p"
	.string "Quand un DRESSEUR sûr de lui\n"
	.string "atteindra le sommet doré, un homme\l"
	.string "apparaîtra parmi les hommes.\p"
	.string "Tu ne connais pas cette légende?\n"
	.string "Pas étonnant, je viens de l’inventer!\p"
	.string "Il y a un sens caché, tu sais.\n"
	.string "Désolé, motus et bouche cousue!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Mince, alors!\n"
	.string "C’est la première fois que je perds!\p"
	.string "Je me suis fait écraser comme un\n"
	.string "moucheron!\p"
	.string "Et en plus, on vient me dire que je\n"
	.string "n’ai aucun talent! Mince…$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Cet homme a dû se battre contre un\n"
	.string "DRESSEUR horriblement fort à la TOUR\l"
	.string "DE COMBAT.\p"
	.string "Et maintenant, regarde-le…\p"
	.string "Si tu décides d’aller à la TOUR DE\n"
	.string "COMBAT, fais bien attention.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Chouette!\n"
	.string "J’ai enfin assez de POINTS DE COMBAT!\p"
	.string "Je pense que je vais les échanger\n"
	.string "contre une autre POUPEE!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Waouh… Alors comme ça, c’est le\n"
	.string "HALL DE CLASSEMENT!\p"
	.string "J’aimerais qu’on se souvienne de moi.\n"
	.string "J’aimerais que mon nom soit inscrit ici.\l"
	.string "Je veux passer à la postérité!$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Avec toi à mes côtés, rien ne peut\n"
	.string "m’arrêter.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Oh, mon chéri! Tu es formidable!\p"
	.string "Je ne veux plus attendre!\p"
	.string "Allons vite dans une SALLE DE COMBAT\n"
	.string "MULTI!\p"
	.string "Si nous allons dans le SALON DE\n"
	.string "COMBAT ensemble, ils vont tous trembler\l"
	.string "devant la force de notre amour.\p"
	.string "Ils vont tous s’effondrer comme des\n"
	.string "dominos devant nous!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "La ZONE DE COMBAT n’est pas réservée\n"
	.string "qu’aux bons DRESSEURS.\p"
	.string "Il paraît que des gens ayant d’autres\n"
	.string "aptitudes ont été invités aussi.\p"
	.string "Ce SCOTT…\p"
	.string "Peut-être qu’il avait une idée derrière\n"
	.string "la tête en construisant cet endroit…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Pardon, petit.\n"
	.string "As-tu une bonne vue?\p"
	.string "Il y a un arbre bizarre là-bas.\n"
	.string "J’ai l’impression qu’il bouge.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Pardon, petit.\n"
	.string "As-tu une bonne mémoire?\p"
	.string "Il me semble qu’il y avait un arbre\n"
	.string "bizarre là-bas, avant.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "…\n"
	.string "Je l’ai vu!\p"
	.string "J’ai vu un POKéMON du genre gluant\n"
	.string "avec une longue queue!\p"
	.string "Il se cachait derrière un rocher et\n"
	.string "n’arrêtait pas de me regarder!$"
