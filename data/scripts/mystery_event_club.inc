MysteryEventClub_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, MysteryEventClub_EventScript_GivenProfileBefore
	msgbox MysteryEventClub_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_AskToSeeProfile
	end

MysteryEventClub_EventScript_AskToSeeProfile::
	msgbox MysteryEventClub_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, MysteryEventClub_EventScript_CreateProfile
	case 1, MysteryEventClub_EventScript_DeclineShowProfile
	case 2, MysteryEventClub_EventScript_Info
	case MULTI_B_PRESSED, MysteryEventClub_EventScript_DeclineShowProfile
	end

MysteryEventClub_EventScript_Info::
	msgbox MysteryEventClub_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_AskToSeeProfile
	end

MysteryEventClub_EventScript_CreateProfile::
	msgbox MysteryEventClub_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MysteryEventClub_EventScript_CancelShowProfile
	compare VAR_RESULT, 1
	goto_if_eq MysteryEventClub_EventScript_ShowProfile
	end

MysteryEventClub_EventScript_CancelShowProfile::
	msgbox MysteryEventClub_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox MysteryEventClub_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_DeclineShowProfile::
	msgbox MysteryEventClub_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

MysteryEventClub_EventScript_GivenProfileBefore::
	msgbox MysteryEventClub_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_AskToSeeNewProfile
	end

MysteryEventClub_EventScript_AskToSeeNewProfile::
	msgbox MysteryEventClub_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, MysteryEventClub_EventScript_CreateNewProfile
	case 1, MysteryEventClub_EventScript_DeclineNewProfile
	case 2, MysteryEventClub_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, MysteryEventClub_EventScript_DeclineNewProfile
	end

MysteryEventClub_EventScript_InfoNewProfile::
	msgbox MysteryEventClub_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto MysteryEventClub_EventScript_AskToSeeNewProfile
	end

MysteryEventClub_EventScript_CreateNewProfile::
	msgbox MysteryEventClub_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MysteryEventClub_EventScript_CancelShowProfile
	compare VAR_RESULT, 1
	goto_if_eq MysteryEventClub_EventScript_ShowProfile
	end

MysteryEventClub_EventScript_DeclineNewProfile::
	msgbox MysteryEventClub_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
MysteryEventClub_EventScript_Ret::
	return

MysteryEventClub_Text_CollectTrainerProfiles:
	.string "Hello there, TRAINER!\n"
	.string "You've got a wonderful smile, there.\p"
	.string "I have a hobby--collecting the profiles\n"
	.string "of POKéMON TRAINERS.$"

MysteryEventClub_Text_MayISeeYourProfile:
	.string "So, how about it?\n"
	.string "May I see your profile?$"

MysteryEventClub_Text_EasyChatExplanation:
	.string "You make your own profile by putting\n"
	.string "together four words or phrases.\p"
	.string "Here, I'll show you an example of a\n"
	.string "profile using four pieces of text.\p"
	.string "You can switch those four pieces with\n"
	.string "other text pieces any which way you\l"
	.string "like to make your own profile.\p"
	.string "There are a lot of text pieces that\n"
	.string "you can use.\p"
	.string "They are arranged in groups like\n"
	.string "POKéMON, lifestyles, and hobbies so\l"
	.string "it is easier to look them up.\p"
	.string "So, first, choose the group of text\n"
	.string "pieces to display a list of choices.\p"
	.string "Then, pick the choice you want.\p"
	.string "Repeat for the remaining text choices,\n"
	.string "and you'll have your very own profile.$"

MysteryEventClub_Text_LetsSeeItThen:
	.string "Yes! Thank you!\n"
	.string "So, let's see it, then.$"

MysteryEventClub_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh, no, really?\p"
	.string "I imagine someone like you would have\n"
	.string "a wonderful profile…$"

MysteryEventClub_Text_NotIntoItRightNow:
	.string "Oh? You're not into it right now?\p"
	.string "Well, anytime is good by me!$"

MysteryEventClub_Text_YouHaveWonderfulSmile:
	.string "Hello there, TRAINER!\n"
	.string "You've got a wonderful smile.$"

MysteryEventClub_Text_MayISeeYourNewProfile:
	.string "May I see your new profile?$"

MysteryEventClub_Text_EvenBetterThanLastProfile:
	.string "Yes! Thank you!\p"
	.string "I hope it's even better than the profile\n"
	.string "you showed me before.$"

MysteryEventClub_Text_LikeProfileWayItIs:
	.string "Oh, you like your profile the way it is.\p"
	.string "I don't blame you--it's a wonderful\n"
	.string "profile the way it is now.$"

MysteryEventClub_Text_FantasticProfile:
	.string "F-fantastic!\p"
	.string "Your profile, it's wonderful!\n"
	.string "It really says what you're about.\p"
	.string "Why, anyone hearing this profile would\n"
	.string "be captivated by you!\p"
	.string "Thank you!$"

@ Unused
MysteryEventClub_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
