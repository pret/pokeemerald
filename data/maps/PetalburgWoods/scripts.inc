PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applywaitmovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Nergens te vinden…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hallo, heb je hier een POKéMON gezien\n"
	.string "die SHROOMISH heet?\p"
	.string "Ik vind die POKéMON echt geweldig.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Ik wilde je overvallen, maar jij bleef\n"
	.string "maar treuzelen in PETALBURG WOODS!\p"
	.string "Ik was het wachten zat, dus\n"
	.string "hier ben ik!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Jij! DEVON-ONDERZOEKER!\p"
	.string "Geef die papieren hier!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aaaah!\p"
	.string "Je bent een POKéMON TRAINER, toch?\n"
	.string "Help me, alsjeblieft!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hè? Wat doe jij nou?\n"
	.string "Wat, ga je hem beschermen?\p"
	.string "Wie TEAM AQUA dwarszit, krijgt geen\n"
	.string "genade, ook geen kind!\p"
	.string "Kom op, vecht tegen mij!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Dat meen je niet! Jij bent sterk!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Jij durft wel, je bemoeien\n"
	.string "met TEAM AQUA!\l"
	.string "Kom op, vecht nog eens tegen me!\p"
	.string "Dat zou ik willen zeggen, maar mijn\n"
	.string "POKéMON zijn op…\p"
	.string "En trouwens, TEAM AQUA zoekt ook\n"
	.string "iets in RUSTBORO.\p"
	.string "Vandaag laat ik je gaan!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Pfoe…\n"
	.string "Dat was op het nippertje!\p"
	.string "Dankzij jou heeft hij deze belangrijke\n"
	.string "papieren niet gestolen.\p"
	.string "Weet je wat? Als bedankje krijg je\n"
	.string "een SUPERBALL!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Zei die boef van TEAM AQUA niet dat\n"
	.string "ze ook iets in RUSTBORO\l"
	.string "zochten?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "O jee! Dit is een noodgeval!\n"
	.string "Ik heb geen tijd te verliezen!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Je hebt veel te veel spullen.\n"
	.string "Ik kan je deze SUPERBALL niet geven.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Ik heb heel veel POKéMON gevangen!\p"
	.string "Ga, ga, ga!\n"
	.string "Mijn INSECT-team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Ik heb al die POKéMON,\n"
	.string "maar ik kon niet winnen…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Ik heb veel POKéMON gevangen.\n"
	.string "Nu zijn mijn POKé BALLS op.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Als je INSECT-POKéMON meeneemt naar\n"
	.string "school, ben je meteen populair!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Als ik verlies, ben ik niet populair.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Als je een grote INSECT-POKéMON hebt,\n"
	.string "hebben mensen respect voor je.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Ik wil nog eens vechten als mijn\n"
	.string "INSECTEN groot zijn!\p"
	.string "Ik zet je in mijn POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Ik wil nog eens vechten als mijn\n"
	.string "INSECTEN groot zijn!\p"
	.string "Ik zet je in mijn POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mijn INSECTEN zijn gegroeid.\n"
	.string "Ik word weer populair.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Als ik verlies, ben ik niet populair.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Met sterke POKéMON word je\n"
	.string "populair, toch?\l"
	.string "Dus ik heb hard getraind.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Hé, jij daar!\n"
	.string "Gaat het goed met je POKéMON?\p"
	.string "Zijn je POKéMON zwak en wil je niet\n"
	.string "vechten? Blijf dan uit het\l"
	.string "hoge gras.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Soms liggen er dingen op de grond,\n"
	.string "ook al zie je ze niet.\p"
	.string "Daarom kijk ik altijd goed waar\n"
	.string "ik loop.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "O, gaaf!\n"
	.string "Dat is de BADGE van RUSTBORO GYM!\p"
	.string "Jij bent vast een TRAINER.\n"
	.string "Probeer dit voorwerp eens.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Dat is een WONDERZAAD.\n"
	.string "Als een POKéMON dat vasthoudt,\l"
	.string "worden GRAS-aanvallen sterker.\p"
	.string "Behalve WONDERZAAD zijn er nog meer\n"
	.string "handige voorwerpen om je POKéMON\l"
	.string "te laten vasthouden.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TRAINERTIPS\p"
	.string "Elke POKéMON die in een gevecht\n"
	.string "meedoet, krijgt EXP.-punten.\p"
	.string "Wil je een zwakke POKéMON trainen?\n"
	.string "Zet hem dan eerst in je team.\p"
	.string "Wissel hem meteen als het gevecht\n"
	.string "begint. Dan krijgt hij EXP.-punten\l"
	.string "zonder dat hij pijn heeft.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "TRAINERTIPS\p"
	.string "Naast HP hebben POKéMON ook PP.\n"
	.string "Die gebruiken ze voor aanvallen\l"
	.string "in een gevecht.\p"
	.string "Als de PP op is, moet je je POKéMON\n"
	.string "naar een POKéMON CENTER brengen.$"

