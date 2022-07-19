.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, c’est chaque jour si difficile…\p"
	.string "Ce qui est difficile?\n"
	.string "Tu me le demandes?\p"
	.string "Tous les jours, je dois décider ce que\n"
	.string "je vais préparer pour le repas.\p"
	.string "C’est vraiment pas facile de trouver\n"
	.string "des idées différentes chaque jour.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, bonjour!\n"
	.string "Bienvenue chez les BOFOND.\p"
	.string "J’ai une question à te poser. As-tu\n"
	.string "déjà fait du baby-sitting?\p"
	.string "Tu vois, je viens d’être papa, alors\n"
	.string "élever un enfant est quelque chose\l"
	.string "de nouveau pour moi.\p"
	.string "Et j’ai un problème, ma fille BERCIA\n"
	.string "ne rit pas beaucoup.\p"
	.string "Je pense qu’elle rirait plus si je lui\n"
	.string "disais quelque chose d’amusant.\p"
	.string "Connaîtrais-tu un mot ou une phrase\n"
	.string "amusante que je pourrais lui dire?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Je lui ai déjà dit “{STR_VAR_1}”\n"
	.string "pour la faire rire.\p"
	.string "Connaîtrais-tu une autre phrase ou un\n"
	.string "autre mot qui pourrait la faire rire?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, formidable!\n"
	.string "Alors donne-moi ta suggestion.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, vraiment?\p"
	.string "N’hésite pas à me le dire si tu\n"
	.string "as une suggestion.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, je vois.\n"
	.string "Eh bien, nous n’avons plus qu’à essayer.\l"
	.string "D’accord?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "“{STR_VAR_1}”\n"
	.string "“{STR_VAR_1}”\p"
	.string "Oh oui! Elle rigole!\n"
	.string "Oh, je suis aussi heureux qu’elle!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, je vois.\n"
	.string "Eh bien, nous n’avons plus qu’à essayer.\l"
	.string "D’accord?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "“{STR_VAR_1}”\n"
	.string "“{STR_VAR_1}”\p"
	.string "Hmmm… Ça n’a pas l’air de fonctionner.\p"
	.string "Peut-être que BERCIA est juste un\n"
	.string "bébé trop sérieux…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Tu ne connais pas de bons mots alors… \n"
	.string "Je vais continuer d’essayer.\p"
	.string "Hmm…\n"
	.string "Et “{STR_VAR_1}”?\l"
	.string "Voyons si ça marche.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "“{STR_VAR_1}”\n"
	.string "“{STR_VAR_1}”\p"
	.string "Hmmm… Ça n’a pas l’air de fonctionner.\p"
	.string "Peut-être que BERCIA est juste un\n"
	.string "bébé trop sérieux…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Tu ne connais pas de bons mots alors…\n"
	.string "Je vais essayer de l’amuser avec les\l"
	.string "mots que j’utilisais avant.\p"
	.string "Quoi qu’il en soit, n’hésite pas à me le\n"
	.string "dire si tu as une suggestion.$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Merci!\p"
	.string "Grâce à toi, ma petite BERCIA m’a\n"
	.string "montré son sourire!\p"
	.string "Au fait, je ne te l’ai pas dit mais je\n"
	.string "suis chercheur chez DEVON.\p"
	.string "Alors que pourrais-je faire en retour\n"
	.string "pour toi?\p"
	.string "Je sais, je vais ajouter de nouveaux\n"
	.string "fonds aux BOITES de Gestion de\l"
	.string "Stocks de POKéMON sur ton PC. \p"
	.string "Dans le menu des fonds, sélectionne\n"
	.string "“AMIS”.\p"
	.string "Tu auras alors accès à un nouveau fond \n"
	.string "chaque fois que tu feras rire ma fille.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "C’est une POUPEE POKéMON!$"

