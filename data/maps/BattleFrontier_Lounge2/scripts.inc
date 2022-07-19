BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Bonjour! Si tu veux des infos sur la\n"
	.string "ZONE DE COMBAT, tu es au bon endroit.\p"
	.string "Je suis en quelque sorte le MORDU DE\n"
	.string "LA ZONE!\p"
	.string "Toi, tu es un DRESSEUR,\n"
	.string "n’est-ce pas?\p"
	.string "Je serais ravi de partager mes infos sur\n"
	.string "la ZONE DE COMBAT avec toi.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Bonjour! Je parierais que tu es là\n"
	.string "pour me faire parler un peu!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I’m sure my information’s been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Voyons voir…\p"
	.string "L’endroit le plus en vue en ce moment…\n"
	.string "{STR_VAR_1}, sans hésitation.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Voyons voir…\p"
	.string "Le {STR_VAR_1} de la TOUR DE COMBAT\n"
	.string "est le meilleur du moment.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Je suis sûr que je vais t’apprendre\n"
	.string "quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est un mystérieux DRESSEUR surnommé\n"
	.string "l’AS DU SALON.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "As-tu affronté l’AS DU SALON?\p"
	.string "Elle utilise ces POKéMON quand elle veut\n"
	.string "se mettre à la hauteur de l’adversaire:\p"
	.string "Un POKéMON de type PSY,\n"
	.string "un POKéMON VOLCAN de type FEU\l"
	.string "et un POKéMON PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "As-tu affonté l’AS DU SALON\n"
	.string "quand elle est sérieuse?\p"
	.string "Quand elle se bat à fond, elle utilise\n"
	.string "les POKéMON suivants:\p"
	.string "Un POKéMON EON de type DRAGON/PSY,\n"
	.string "un POKéMON FOUDRE de type ELECTRIK\l"
	.string "et un POKéMON PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Je vais t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est l’extravagant DRESSEUR appelé la\n"
	.string "STAR DU DOME.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "As-tu affronté la STAR DU DOME?\p"
	.string "Quand il ne prend pas l’adversaire au\n"
	.string "sérieux, il utilise ces POKéMON:\p"
	.string "Un POKéMON DRAGON du type DRAGON/VOL,\n"
	.string "un POKéMON POISSONBOUE du type EAU/\l"
	.string "SOL et un POKéMON FLAMME du type\l"
	.string "FEU/VOL.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "As-tu affronté la STAR DU DOME\n"
	.string "quand il se bat sérieusement?\p"
	.string "Quand il veut faire preuve de stratégie,\n"
	.string "il utilise ces trois POKéMON:\p"
	.string "Un POKéMON EON de type DRAGON/PSY,\n"
	.string "un POKéMON POISSONBOUE de type\l"
	.string "EAU/SOL et un POKéMON PATTEFER\l"
	.string "de type ACIER/PSY.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Je vais t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est l’étrange DRESSEUR appelé\n"
	.string "le CHEF D’USINE.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "As-tu déjà affronté le CHEF D’USINE?\p"
	.string "Tu sais… Au combat, il doit utiliser\n"
	.string "trois POKéMON de location.\p"
	.string "Il se bat dans les mêmes conditions que\n"
	.string "les autres, en fait.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "As-tu déjà affronté le CHEF D’USINE\n"
	.string "quand il se bat sérieusement?\p"
	.string "Même quand il veut se battre à fond, il\n"
	.string "doit utiliser trois POKéMON de location.\p"
	.string "En fin de compte, il se bat dans les\n"
	.string "mêmes conditions que les autres.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Je vais t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est le DRESSEUR effrayant appelé la\n"
	.string "REINE VENIN.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Tu as déjà affronté la REINE VENIN?\p"
	.string "Quand elle est de bonne humeur, elle\n"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON SERPACROC de type POISON,\n"
	.string "un POKéMON POURRI de type\l"
	.string "INSECTE/ROCHE et un POKéMON TENDRE\l"
	.string "de type EAU.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Tu as déjà affronté la REINE VENIN\n"
	.string "quand elle est énervée?\p"
	.string "Quand elle est vraiment agressive,\n"
	.string "elle utilise ces trois POKéMON:\p"
	.string "Un POKéMON SERPACROC de type POISON,\n"
	.string "Un POKéMON SERPENFER de type\l"
	.string "ACIER/SOL et un POKéMON TERRIFIANT\l"
	.string "de type EAU/VOL.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Je vais t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est le DRESSEUR pas mal appelé\n"
	.string "la PRO DU DOJO.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "As-tu déjà affronté la PRO DU DOJO?\p"
	.string "Quand elle veut laisser une chance à\n"
	.string "l’adversaire, elle utilise ces POKéMON:\p"
	.string "Un POKéMON UNICORNE de type INSECTE/\n"
	.string "COMBAT, un POKéMON LUNE de type\l"
	.string "TENEBRES et un POKéMON EXUVIE\l"
	.string "de type INSECTE/SPECTRE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "As-tu déjà affronté la PRO DU DOJO?\p"
	.string "Si elle ne veut laisser aucune chance à\n"
	.string "l’adversaire, elle utilise ces POKéMON:\p"
	.string "Un POKéMON LUNE de type TENEBRES,\n"
	.string "un POKéMON OMBRE de type\l"
	.string "SPECTRE/POISON et un POKéMON\l"
	.string "CHAMPIGNON de type PLANTE/COMBAT.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Je vais t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est ce DRESSEUR sinistre appelé\n"
	.string "le CAPT. PALACE.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Tu as déjà affronté le CAPT. PALACE?\p"
	.string "S’il veut tester l’adversaire, il utilise\n"
	.string "ces POKéMON:\p"
	.string "Un POKéMON CHOVSOURIS de type POISON/\n"
	.string "VOL, un POKéMON FAINEANT de type\l"
	.string "NORMAL et un POKéMON TRANSPORT\l"
	.string "de type EAU/GLACE.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Tu as déjà combattu le CAPT. PALACE?\p"
	.string "Quand il se bat à fond, il utilise ces\n"
	.string "POKéMON:\p"
	.string "Un POKéMON LEGENDAIRE de type FEU,\n"
	.string "un POKéMON FAINEANT de type NORMAL\l"
	.string "et un POKéMON AURORE de type EAU.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Je vais t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est ici.\p"
	.string "C’est ce DRESSEUR intrépide appelé\n"
	.string "le ROI PYRAMIDE.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "As-tu déjà affronté le ROI PYRAMIDE?\p"
	.string "Quand il veut évaluer l’adversaire,\n"
	.string "il utilise ces POKéMON:\p"
	.string "Un POKéMON PIC ROCHEUX de type ROCHE,\n"
	.string "un POKéMON ICEBERG de type GLACE\l"
	.string "et un POKéMON FER de type ACIER.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "As-tu déjà affronté le ROI PYRAMIDE\n"
	.string "quand il se bat pour de bon?\p"
	.string "Quand il est gonflé à bloc, il utilise\n"
	.string "ces POKéMON:\p"
	.string "Un POKéMON GLACIAIRE de type\n"
	.string "GLACE/VOL, un POKéMON ELECTRIQUE\l"
	.string "de type ELECTRIK/VOL et un POKéMON\l"
	.string "FLAMME de type FEU/VOL.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Oui, il y a plein d’endroits où faire des\n"
	.string "COMBATS DUO.\p"
	.string "Mais il vaut mieux commencer par les\n"
	.string "SALLES DE COMBAT DUO de la\l"
	.string "TOUR DE COMBAT!\p"
	.string "C’est là que tu apprendras ce qu’est un\n"
	.string "COMBAT DUO dans la ZONE DE COMBAT.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Fais bien attention à toi.\p"
	.string "Il paraît que certains DRESSEURS\n"
	.string "développent des stratégies spéciales\l"
	.string "pour les COMBATS DUO.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Quand tu y maîtriseras les COMBATS DUO,\n"
	.string "tu pourrais essayer d’en faire ailleurs.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Toutes sortes de DRESSEURS se\n"
	.string "trouvent dans le SALON DE COMBAT.\p"
	.string "Il se peut que tu rencontres des amis\n"
	.string "ou encore des fans! Ouvre les yeux!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si tu es avec un ami, dirige-toi vers\n"
	.string "la SALLE DE COMBAT MULTI LINK.\p"
	.string "Si ton ami est fort, les adversaires\n"
	.string "seront certainement de taille!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quelle capacité de synthèse!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quel talent d’observation!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quelle force de persuasion!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "C’est quoi, cet endroit?\n"
	.string "J’ai un peu peur…$"

