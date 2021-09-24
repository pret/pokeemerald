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
	.string "This Pokémon won the Beauty Contest\n"
	.string "here before.\p"
	.string "Well, guess what? Today, I made it\n"
	.string "win a Smartness Contest!\p"
	.string "My abilities scare even me…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "I've entered a bunch of Contests,\n"
	.string "so I'm seeing how things work.\p"
	.string "If you're in a Coolness Contest,\n"
	.string "cool moves go over as appeals.\p"
	.string "But smart moves and cute moves\n"
	.string "don't go over well, for instance.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "That young man who won earlier had\n"
	.string "a whole bunch of different {POKEBLOCK}s.\p"
	.string "Can you win if you had that many\n"
	.string "of those things?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Whoa, isn't this place humongous!\p"
	.string "The tension in the air… It's not\n"
	.string "like a Contest hall in the sticks.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Okay, Smart Pokémon and their\n"
	.string "Trainers, are you ready?!\p"
	.string "Give it your best showing!\n"
	.string "Let's appeal!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "Judge: Are you enjoying this Contest?\p"
	.string "Come back with three friends, and\n"
	.string "all of you may enter a Contest!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "I entered the wrong Contest.\p"
	.string "I entered this tough Pokémon in\n"
	.string "the Smartness Contest…\p"
	.string "Come on, wow them with a smart-looking\n"
	.string "Rock Smash.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "I've spent many a year, and all my\n"
	.string "wisdom besides, raising this Pokémon\l"
	.string "to be smart.\p"
	.string "It won't be easily bested by some\n"
	.string "young pup's Pokémon.\p"
	.string "My dear wife, are you seeing this?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "There it is!\p"
	.string "If my Pokémon pulls a smart move next,\n"
	.string "the audience's excitement will peak!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, dear, no!\p"
	.string "My darling Zubat's Leech Life is so\n"
	.string "cute I kept using it over and over!\p"
	.string "But these mean people don't appreciate\n"
	.string "it at all!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! You're beautiful, Grandpa!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Even when Trainers enter the same\n"
	.string "kind of Pokémon, they all seem to use\l"
	.string "different moves for appeals.\p"
	.string "It's just like the way people have\n"
	.string "different styles for battling.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "I think the Pokémon look smarter\n"
	.string "than their Trainers. By a lot.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "When all's said and done, I still love\n"
	.string "Smartness Contests.\p"
	.string "That intellectual green color…\n"
	.string "It's so… So… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Are you entering the Beauty\n"
	.string "Contest, too? Good luck!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "Judge: Ah, every Pokémon here is\n"
	.string "a model of pristine beauty!\p"
	.string "Why, I almost forgot to score them!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "A Pokémon this beautiful…\n"
	.string "There isn't another one like it.\p"
	.string "Everyone's eyes will be glued to\n"
	.string "my beauty.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "I brushed and groomed my Pokémon\n"
	.string "carefully for this Contest…\p"
	.string "But I overdid it…\n"
	.string "My Pokémon's coat turned all scraggly…\p"
	.string "What should I do?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "This Aurora Beam is so dazzling,\n"
	.string "the Judge won't be able to see it.\p"
	.string "Uh, wait a second…\n"
	.string "That'll be meaningless, then!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "This pretty Pokémon looks just like\n"
	.string "me when I was younger.\p"
	.string "Right when I said that, my husband\n"
	.string "spewed the coffee he was drinking.\p"
	.string "Did I say something funny?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "You know, if I win at a Beauty\n"
	.string "Contest, sure it makes me\l"
	.string "happy. More than usual, anyway.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Will you take a gander at all those\n"
	.string "pretty Pokémon!\l"
	.string "I just love this sort of glitz!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "You can't always win on just beauty\n"
	.string "alone.\p"
	.string "You have to groom your Pokémon so\n"
	.string "it's nice and glossy like mine.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Uh-oh! Hello!\n"
	.string "We're in the middle of a Contest!\p"
	.string "Please enter at our registration\n"
	.string "counter and come out, okay?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "Judge: Oh, such charming and cute\n"
	.string "appeals!\p"
	.string "Oh, my goodness! What a perfectly\n"
	.string "adorable Water Sport appeal!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, no… My sweet Azurill was\n"
	.string "distracted by another Pokémon.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "My Pokémon has never won in a battle,\n"
	.string "but put it in a Contest and look out!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "My Pokémon's Petal Dance is a marvel\n"
	.string "of elegance.\p"
	.string "I won't let anyone disturb its\n"
	.string "performance.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Everyone's Pokémon are very cute.\p"
	.string "However, if my Pokémon were to make\n"
	.string "a cute appeal…\p"
	.string "I'm sure that it would be so much \n"
	.string "cuter than the others.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "My child is in this Contest.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Come on, dear. Go for it!\n"
	.string "Your Pokémon is the best!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "I think that girl over there is\n"
	.string "the cutest of the lot.\p"
	.string "What's that? They're judging\n"
	.string "Pokémon by their looks?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, seeing all these cute Pokémon,\n"
	.string "they make we want to get my own!\p"
	.string "I'm going to go catch some!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "Beauty Contest Stage\n"
	.string "Be allured by beautiful Pokémon!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "Cuteness Contest Stage\n"
	.string "Be charmed by cute Pokémon!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "Smartness Contest Stage\n"
	.string "Be impressed by smart Pokémon!$"

