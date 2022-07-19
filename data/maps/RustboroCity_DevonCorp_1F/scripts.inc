.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Bonjour et bienvenue à la DEVON SARL.\p"
	.string "Nous produisons avec fierté des objets\n"
	.string "et médicaments qui simplifient la vie.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Une de nos équipes de chercheurs s’est\n"
	.string "fait voler un important paquet.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, ces CHAUSSURES DE SPORT!\n"
	.string "Elles sortent de nos ateliers!\p"
	.string "J’aime constater que ce que nous\n"
	.string "avons produit sert à quelqu’un.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Ce paquet qui a été volé…\p"
	.string "Bien sûr, c’est important, mais ce n’est\n"
	.string "pas utile à tout le monde.\p"
	.string "Et d’après mes calculs, le voleur ne\n"
	.string "doit pas être très intelligent.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Ils ont l’air d’avoir retrouvé le\n"
	.string "PACK DEVON qui avait été volé.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Désolé, mais seules les personnes\n"
	.string "autorisées peuvent entrer ici.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "C’est trop bête!\n"
	.string "Comment a-t-on pu se faire voler?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Bonjour! C’est toujours avec grand\n"
	.string "plaisir que nous vous accueillons ici!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Des échantillons de pierres et de\n"
	.string "métaux sont placés dans une vitrine.\p"
	.string "Il y a un panneau avec quelque chose\n"
	.string "d’écrit…\p"
	.string "“DEVON était à l’origine une\n"
	.string "compagnie d’exploitation minière.\p"
	.string "La compagnie a également produit de\n"
	.string "l’acier en exploitant la limaille se\l"
	.string "trouvant dans le sable.\p"
	.string "DEVON s’est sans cesse développé\n"
	.string "depuis ses humbles débuts.\p"
	.string "DEVON fabrique maintenant\n"
	.string "une grande variété de produits\l"
	.string "industriels.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "La vitrine est pleine de prototypes et\n"
	.string "d’échantillons.\p"
	.string "Il y a un panneau avec une inscription…\p"
	.string "“En plus de ses produits industriels,\n"
	.string "DEVON souhaite se développer sur le\p"
	.string "marché pharmaceutique pour\n"
	.string "améliorer notre qualité de vie.\p"
	.string "Récemment, DEVON a commercialisé des\n"
	.string "outils pour les DRESSEURS, comme les\p"
	.string "POKé BALLS et les systèmes POKéNAV.”$"

