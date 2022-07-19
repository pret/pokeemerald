SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Voulez-vous quitter le PARC SAFARI\n"
	.string "tout de suite?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Le temps est écoulé!\n"
	.string "Votre partie de SAFARI est terminée.$"

SafariZone_Text_OutOfBalls:
	.string "Vous n’avez plus de SAFARI BALLS.\n"
	.string "Votre partie de SAFARI est terminée.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Voulez-vous placer un {POKEBLOCK}\n"
	.string "dans la MANGEOIRE {POKEBLOCK}?$"

SafariZone_Text_PokeblockStillHere:
	.string "Le {STR_VAR_1} que vous aviez\n"
	.string "placé là y est encore.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Le {STR_VAR_1} a été placé\n"
	.string "dans la MANGEOIRE {POKEBLOCK}.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Bienvenue dans le PARC SAFARI!\p"
	.string "Ici, vous pourrez admirer de nombreuses\n"
	.string "espèces de POKéMON rares à HOENN.\p"
	.string "Et vous pourrez les voir à l’état\n"
	.string "sauvage, dans leur habitat naturel.\p"
	.string "De plus, les DRESSEURS DE POKéMON\n"
	.string "sont les bienvenus dans ce parc.\p"
	.string "Vous êtes encouragés à attraper des\n"
	.string "POKéMON et à les garder!\p"
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Bienvenue au PARC SAFARI!\n"
	.string "C’est la première fois que vous venez?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Lorsque vous entrez dans le PARC\n"
	.string "SAFARI, vous recevez 30 SAFARI\l"
	.string "BALLS pour attraper des POKéMON.\p"
	.string "La partie de SAFARI se termine lorsque\n"
	.string "vous n’avez plus de SAFARI BALLS ou\l"
	.string "lorsque vous avez parcouru 500 pas.\p"
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Bienvenue au PARC SAFARI!\p"
	.string "Attrapez un max de POKéMON pour 500¥!\n"
	.string "Voulez-vous faire un SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "D’accord.\n"
	.string "Revenez nous voir une autre fois!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Vous n’avez pas assez d’argent.\n"
	.string "Désolé.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Cela fera 500¥, s’il vous plaît.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Voici vos SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} reçoit 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Nous vous préviendrons quand votre\n"
	.string "SAFARI sera terminé.\p"
	.string "En attendant, amusez-vous bien!\n"
	.string "Profitez de votre équipée sauvage!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Je regrette!\n"
	.string "La BOITE de votre PC est pleine.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Je regrette!\n"
	.string "Vous n’avez pas de BOITE {POKEBLOCK}S.\p"
	.string "Vous attraperez bien plus de POKéMON\n"
	.string "si vous utilisez des {POKEBLOCK}S.\p"
	.string "Revenez nous voir avec une\n"
	.string "BOITE {POKEBLOCK}S.\p"
	.string "On vous en fournira peut-être une dans\n"
	.string "la SALLE DE CONCOURS de NENUCRIQUE.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Votre temps n’est pas encore écoulé.\n"
	.string "Voulez-vous quitter le PARC SAFARI?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Amusez-vous bien et profitez de votre\n"
	.string "équipée sauvage!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Bien.\p"
	.string "Je vais reprendre vos SAFARI BALLS\n"
	.string "restantes.\p"
	.string "Merci d’avoir joué.\n"
	.string "Nous espérons vous revoir bientôt.$"

SafariZone_South_Text_GoodLuck:
	.string "Bonne chance!\p"
	.string "Si vous avez besoin de quoi que ce soit,\n"
	.string "n’hésitez pas à venir me voir!$"

SafariZone_South_Text_Boy:
	.string "Le savais-tu?\p"
	.string "Si tu mets un {POKEBLOCK} dans cette boîte\n"
	.string "carrée, les POKéMON tourneront autour.$"

SafariZone_South_Text_Man:
	.string "J’aimerais bien continuer plus loin, mais\n"
	.string "j’ai oublié d’apporter un VELO.\p"
	.string "Quelque chose me dit que des POKéMON\n"
	.string "rares vivent dans les zones reculées.$"

SafariZone_Southwest_Text_Woman:
	.string "Parfois, j’envoie un {POKEBLOCK} à un\n"
	.string "POKéMON, mais il l’ignore.\p"
	.string "Est-ce que les POKéMON ont des\n"
	.string "préférences en matière de nourriture?$"

SafariZone_Northwest_Text_Man:
	.string "Pfou… Pfou…\n"
	.string "Je… J’ai réussi à venir jusqu’ici, mais…\p"
	.string "Je suis épuisé… Je n’ai plus la force\n"
	.string "d’attraper des POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "J’ai pour mission de trouver des\n"
	.string "POKéMON EAU introuvables à HOENN.\p"
	.string "Tu sais où se trouve le lac?$"

SafariZone_North_Text_Man:
	.string "Je vais attraper plein de POKéMON rares\n"
	.string "ici et je les échangerai avec mes amis!$"

SafariZone_South_Text_Youngster:
	.string "J’ai mis un {POKEBLOCK} dans la MANGEOIRE.\n"
	.string "Mais apparemment, il a disparu.\p"
	.string "Je suppose qu’un POKéMON l’a mangé\n"
	.string "pendant que je ne regardais pas.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "PARC SAFARI - CONSEIL AUX DRESSEURS!\p"
	.string "Lancez des {POKEBLOCK}S aux POKéMON\n"
	.string "sauvages pour éviter qu’ils s’enfuient.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Reposez vos jambes fatiguées.”\n"
	.string "REFUGE$"

SafariZone_RestHouse_Text_Youngster:
	.string "Je n’ai pas de {POKEBLOCK}, mais j’ai quand\n"
	.string "même attrapé beaucoup de POKéMON.\p"
	.string "Tu peux augmenter tes chances\n"
	.string "d’attraper un POKéMON en t’approchant\l"
	.string "avant de jeter une SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Si tu leur donnes des {POKEBLOCK}S, les\n"
	.string "POKéMON s’enfuient moins vite.\p"
	.string "Ça ne sert pas à grand-chose de donner\n"
	.string "des {POKEBLOCK}S aux POKéMON qui ne\l"
	.string "sont pas farouches.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Si tu mets un {POKEBLOCK} dans la MANGEOIRE,\n"
	.string "ça attirera les POKéMON.\p"
	.string "Je crois que certains types de POKéMON\n"
	.string "sont attirés par certains {POKEBLOCK}S.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Cette zone est encore en construction.\n"
	.string "Vous ne pouvez pas entrer, désolé!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Les travaux d’agrandissement du\n"
	.string "PARC SAFARI sont terminés.\p"
	.string "Nous espérons que la nouvelle zone\n"
	.string "vous apportera entière satisfaction.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Cette zone est encore en construction.\n"
	.string "Vous ne pouvez pas entrer, désolé!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Waouh! Délire! C’est la première fois que\n"
	.string "je vois ce genre de POKéMON!$"

SafariZone_Southeast_Text_FatMan:
	.string "Je n’avais jamais vu aucun des POKéMON\n"
	.string "de cette zone.\p"
	.string "Et j’ai le droit d’attraper tous ces\n"
	.string "POKéMON rares? Trop cool!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Je ne pense pas que les POKéMON qui\n"
	.string "se trouvent ici soient de HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Il ne me reste que quelques\n"
	.string "SAFARI BALLS.\p"
	.string "J’ai du mal à décider ce que je dois\n"
	.string "attraper.$"

SafariZone_Northeast_Text_Woman:
	.string "On dit qu’il y a des PIKACHU ici.\n"
	.string "Je me demande bien où ils se cachent.$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, bouh!\n"
	.string "Je n’arrive à rien ici!\p"
	.string "J’ai payé l’entrée, il faut absolument\n"
	.string "que j’attrape quelque chose!$"
