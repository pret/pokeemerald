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

LilycoveCity_ContestHall_MapScripts:: @ 821B484
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1:: @ 821B485
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2:: @ 821B48E
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl:: @ 821B497
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor:: @ 821B4A0
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC:: @ 821B4A9
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge:: @ 821B4C0
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1:: @ 821B4D7
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2:: @ 821B4EE
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3:: @ 821B505
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4:: @ 821B51C
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1:: @ 821B533
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2:: @ 821B53C
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3:: @ 821B553
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4:: @ 821B56A
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC:: @ 821B581
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge:: @ 821B598
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1:: @ 821B5AF
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2:: @ 821B5C6
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3:: @ 821B5DD
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4:: @ 821B5F4
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1:: @ 821B60B
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2:: @ 821B622
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3:: @ 821B639
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC:: @ 821B650
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge:: @ 821B667
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1:: @ 821B67E
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2:: @ 821B695
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3:: @ 821B6AC
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4:: @ 821B6C3
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1:: @ 821B6DA
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

LilycoveCity_ContestHall_EventScript_CuteContestAudience2:: @ 821B705
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3:: @ 821B71C
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign:: @ 821B733
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign:: @ 821B73C
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign:: @ 821B745
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest: @ 821B74E
	.string "This POKéMON won the BEAUTY CONTEST\n"
	.string "here before.\p"
	.string "Well, guess what? Today, I made it\n"
	.string "win a SMARTNESS CONTEST!\p"
	.string "My abilities scare even me…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests: @ 821B7D7
	.string "I've entered a bunch of CONTESTS,\n"
	.string "so I'm seeing how things work.\p"
	.string "If you're in a COOLNESS CONTEST,\n"
	.string "cool moves go over as appeals.\p"
	.string "But smart moves and cute moves\n"
	.string "don't go over well, for instance.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks: @ 821B899
	.string "That young man who won earlier had\n"
	.string "a whole bunch of different {POKEBLOCK}S.\p"
	.string "Can you win if you had that many\n"
	.string "of those things?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous: @ 821B911
	.string "Whoa, isn't this place humongous!\p"
	.string "The tension in the air… It's not\n"
	.string "like a CONTEST hall in the sticks.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal: @ 821B977
	.string "MC: Okay, SMART POKéMON and their\n"
	.string "TRAINERS, are you ready?!\p"
	.string "Give it your best showing!\n"
	.string "Let's appeal!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest: @ 821B9DC
	.string "JUDGE: Are you enjoying this CONTEST?\p"
	.string "Come back with three friends, and\n"
	.string "all of you may enter a CONTEST!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest: @ 821BA44
	.string "Ayayayay…\n"
	.string "I entered the wrong CONTEST.\p"
	.string "I entered this tough POKéMON in\n"
	.string "the SMARTNESS CONTEST…\p"
	.string "Come on, wow them with a smart-looking\n"
	.string "ROCK SMASH.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart: @ 821BAD5
	.string "I've spent many a year, and all my\n"
	.string "wisdom besides, raising this POKéMON\l"
	.string "to be smart.\p"
	.string "It won't be easily bested by some\n"
	.string "young pup's POKéMON.\p"
	.string "My dear wife, are you seeing this?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext: @ 821BB84
	.string "There it is!\p"
	.string "If my POKéMON pulls a smart move next,\n"
	.string "the audience's excitement will peak!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife: @ 821BBDD
	.string "Oh, dear, no!\p"
	.string "My darling ZUBAT's LEECH LIFE is so\n"
	.string "cute I kept using it over and over!\p"
	.string "But these mean people don't appreciate\n"
	.string "it at all!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa: @ 821BC65
	.string "Kiyaaah! You're beautiful, Grandpa!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves: @ 821BC89
	.string "Even when TRAINERS enter the same\n"
	.string "kind of POKéMON, they all seem to use\l"
	.string "different moves for appeals.\p"
	.string "It's just like the way people have\n"
	.string "different styles for battling.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers: @ 821BD30
	.string "I think the POKéMON look smarter\n"
	.string "than their TRAINERS. By a lot.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests: @ 821BD70
	.string "When all's said and done, I still love\n"
	.string "SMARTNESS CONTESTS.\p"
	.string "That intellectual green color…\n"
	.string "It's so… So… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest: @ 821BDDD
	.string "MC: Are you entering the BEAUTY\n"
	.string "CONTEST, too? Good luck!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty: @ 821BE16
	.string "JUDGE: Ah, every POKéMON here is\n"
	.string "a model of pristine beauty!\p"
	.string "Why, I almost forgot to score them!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty: @ 821BE77
	.string "A POKéMON this beautiful…\n"
	.string "There isn't another one like it.\p"
	.string "Everyone's eyes will be glued to\n"
	.string "my beauty.$"

LilycoveCity_ContestHall_Text_OverdidGrooming: @ 821BEDE
	.string "Waaaah!\p"
	.string "I brushed and groomed my POKéMON\n"
	.string "carefully for this CONTEST…\p"
	.string "But I overdid it…\n"
	.string "My POKéMON's coat turned all scraggly…\p"
	.string "What should I do?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam: @ 821BF6E
	.string "This AURORA BEAM is so dazzling,\n"
	.string "the JUDGE won't be able to see it.\p"
	.string "Uh, wait a second…\n"
	.string "That'll be meaningless, then!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe: @ 821BFE3
	.string "This pretty POKéMON looks just like\n"
	.string "me when I was younger.\p"
	.string "Right when I said that, my husband\n"
	.string "spewed the coffee he was drinking.\p"
	.string "Did I say something funny?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy: @ 821C07F
	.string "You know, if I win at a BEAUTY\n"
	.string "CONTEST, sure it makes me\l"
	.string "happy. More than usual, anyway.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon: @ 821C0D8
	.string "Wahahahah!\p"
	.string "Will you take a gander at all those\n"
	.string "pretty POKéMON!\l"
	.string "I just love this sort of glitz!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone: @ 821C137
	.string "You can't always win on just beauty\n"
	.string "alone.\p"
	.string "You have to groom your POKéMON so\n"
	.string "it's nice and glossy like mine.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest: @ 821C1A4
	.string "MC: Uh-oh! Hello!\n"
	.string "We're in the middle of a CONTEST!\p"
	.string "Please enter at our registration\n"
	.string "counter and come out, okay?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals: @ 821C215
	.string "JUDGE: Oh, such charming and cute\n"
	.string "appeals!\p"
	.string "Oh, my goodness! What a perfectly\n"
	.string "adorable WATER SPORT appeal!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted: @ 821C27F
	.string "Oh, no… My sweet AZURILL was\n"
	.string "distracted by another POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest: @ 821C2BB
	.string "My POKéMON has never won in a battle,\n"
	.string "but put it in a CONTEST and look out!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel: @ 821C307
	.string "My POKéMON's PETAL DANCE is a marvel\n"
	.string "of elegance.\p"
	.string "I won't let anyone disturb its\n"
	.string "performance.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter: @ 821C365
	.string "Everyone's POKéMON are very cute.\p"
	.string "However, if my POKéMON were to make\n"
	.string "a cute appeal…\p"
	.string "I'm sure that it would be so much \n"
	.string "cuter than the others.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest: @ 821C3F4
	.string "My child is in this CONTEST.$"

LilycoveCity_ContestHall_Text_ComeOnDear: @ 821C411
	.string "Come on, dear. Go for it!\n"
	.string "Your POKéMON is the best!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest: @ 821C445
	.string "I think that girl over there is\n"
	.string "the cutest of the lot.\p"
	.string "What's that? They're judging\n"
	.string "POKéMON by their looks?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn: @ 821C4B1
	.string "Ohh, seeing all these cute POKéMON,\n"
	.string "they make we want to get my own!\p"
	.string "I'm going to go catch some!$"

LilycoveCity_ContestHall_Text_BeautyContestStage: @ 821C512
	.string "BEAUTY CONTEST STAGE\n"
	.string "BE ALLURED BY BEAUTIFUL POKéMON!$"

LilycoveCity_ContestHall_Text_CuteContestStage: @ 821C548
	.string "CUTENESS CONTEST STAGE\n"
	.string "BE CHARMED BY CUTE POKéMON!$"

LilycoveCity_ContestHall_Text_SmartContestStage: @ 821C57B
	.string "SMARTNESS CONTEST STAGE\n"
	.string "BE IMPRESSED BY SMART POKéMON!$"

