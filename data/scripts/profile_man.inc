ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Salut, DRESSEUR!\n"
	.string "Quel magnifique sourire tu as là!\p"
	.string "J’ai une passion. Je rassemble les\n"
	.string "profils de DRESSEURS de POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Alors, qu’en dis-tu?\n"
	.string "Je peux voir ton profil?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Pour créer son propre profil,\n"
	.string "il faut associer quatre mots ou\l"
	.string "groupes de mots.\p"
	.string "Je vais donner un exemple de profil\n"
	.string "constitué de quatre segments de texte.\p"
	.string "Chacun remplace, à sa guise, ces quatre\n"
	.string "segments de texte par d’autres, de\l"
	.string "façon à dépeindre son propre profil.\p"
	.string "Les mots que l’on peut utiliser sont\n"
	.string "nombreux.\p"
	.string "Ils sont classés par catégories, telles\n"
	.string "que POKéMON, vie quotidienne, hobbies,\l"
	.string "permettant de les trouver facilement.\p"
	.string "Il faut d’abord choisir une catégorie\n"
	.string "pour afficher une liste de choix.\p"
	.string "Ensuite, il faut sélectionner son choix.\p"
	.string "Il suffit de refaire pareil pour les\n"
	.string "autres choix et le profil est déterminé.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Oui! Merci!\n"
	.string "Alors, voyons ton profil!$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh non, vraiment?\p"
	.string "J’imagine que quelqu’un comme toi\n"
	.string "doit avoir un merveilleux profil…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh? Tu ne veux pas le faire maintenant?\p"
	.string "Comme tu veux!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Salut, DRESSEUR!\n"
	.string "Quel magnifique sourire tu as!$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Puis-je voir ton nouveau profil?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Oui! Merci!\p"
	.string "J’espère que ce sera encore mieux que\n"
	.string "le profil que tu m’as déjà montré.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, tu aimes ton profil tel qu’il est.\p"
	.string "Je ne t’en blâme pas. C’est devenu un\n"
	.string "très bon profil.$"

ProfileMan_Text_FantasticProfile:
	.string "F… Fantastique!\p"
	.string "Ton profil est génial!\n"
	.string "Il révèle vraiment qui tu es.\p"
	.string "Tu sais, en voyant ce profil, on est\n"
	.string "forcément captivé par toi!\p"
	.string "Merci!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you’re now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
