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
	.string "Hallo, TRAINER!\n"
	.string "Wat heb jij een mooie lach.\p"
	.string "Ik heb een hobby: ik verzamel\n"
	.string "profielen van POKéMON TRAINERS.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Nou, wat denk je?\n"
	.string "Mag ik jouw profiel zien?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Je maakt je eigen profiel met\n"
	.string "vier woorden of zinnetjes.\p"
	.string "Ik laat je een voorbeeld zien van\n"
	.string "een profiel met vier stukjes tekst.\p"
	.string "Je kunt die vier stukjes ruilen\n"
	.string "voor andere stukjes tekst om je\l"
	.string "eigen profiel te maken.\p"
	.string "Er zijn veel stukjes tekst die\n"
	.string "je kunt gebruiken.\p"
	.string "Ze staan in groepen zoals\n"
	.string "POKéMON, leven en hobby's,\l"
	.string "zodat je ze makkelijk vindt.\p"
	.string "Kies eerst de groep stukjes tekst\n"
	.string "om een lijst met keuzes te zien.\p"
	.string "Kies dan wat je wilt.\p"
	.string "Doe dat voor de andere stukjes\n"
	.string "en je hebt je eigen profiel.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Ja! Bedankt!\n"
	.string "Laat maar zien dan.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh, nee, echt niet?\p"
	.string "Ik denk dat iemand als jij\n"
	.string "een prachtig profiel heeft…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh? Heb je er nu geen zin in?\p"
	.string "Nou, elk moment is goed voor mij!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Hallo, TRAINER!\n"
	.string "Wat heb jij een mooie lach.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Mag ik je nieuwe profiel zien?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Ja! Bedankt!\p"
	.string "Ik hoop dat het nog beter is dan\n"
	.string "het profiel dat je me eerder liet zien.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, je vindt je profiel goed zo.\p"
	.string "Dat snap ik: het is een prachtig\n"
	.string "profiel zoals het nu is.$"

ProfileMan_Text_FantasticProfile:
	.string "G-geweldig!\p"
	.string "Je profiel, het is prachtig!\n"
	.string "Het zegt echt wie je bent.\p"
	.string "Iedereen die dit profiel hoort,\n"
	.string "vindt je geweldig!\p"
	.string "Bedankt!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "Je kent de geheime zin!\p"
	.string "Dan ben je nu lid van de\n"
	.string "MYSTERY EVENT CLUB!$"
