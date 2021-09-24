FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM40
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM40
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Fortree Gym Leader Winona is\n"
	.string "a master of Flying-type Pokémon.\p"
	.string "She's waiting at the back of this Gym,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Behold the elegant battle style of\n"
	.string "Bird Pokémon!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "You…\n"
	.string "You're strong…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "A Trainer has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our Leader?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "The lovers of Bird Pokémon aspire\n"
	.string "to join this Gym.\p"
	.string "As a member of the Fortree Gym,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "The world is huge, and there are\n"
	.string "countless tough Trainers.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "There's no need for Winona, our Gym\n"
	.string "Leader, to deal with you!\p"
	.string "I'm plenty good enough for you!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "Winona, I…\n"
	.string "I lost!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "Winona is cute and she's strong.\n"
	.string "She's the ultimate Leader!\p"
	.string "Blush…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "Winona taught me personally!\n"
	.string "You can't beat me easily!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "I was beaten…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Thanks to Winona, the people of\n"
	.string "Fortree can live without fear.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "When Winona takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk!\n"
	.string "I couldn't stop you.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at Winona\l"
	.string "or you'll go crashing down in a heap!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "You'd better know that there are all\n"
	.string "sorts of Flying-type Pokémon.\p"
	.string "You do know that, right?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "You seem to know your stuff!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our Leader\l"
	.string "Winona's Pokémon are all business.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "I am Winona. I am the Leader of\n"
	.string "the Fortree Pokémon Gym.\p"
	.string "I have become one with Bird Pokémon\n"
	.string "and have soared the skies…\p"
	.string "However grueling the battle, we have\n"
	.string "triumphed with grace…\p"
	.string "Witness the elegant choreography\n"
	.string "of Bird Pokémon and I!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Never before have I seen a Trainer\n"
	.string "command Pokémon with more grace\l"
	.string "than I…\p"
	.string "In recognition of your prowess,\n"
	.string "I present to you this Gym Badge.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the Feather Badge\n"
	.string "from Winona.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "With the Feather Badge, all Pokémon up\n"
	.string "to Lv 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move Fly outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 contains Aerial Ace.\p"
	.string "Its speed…\n"
	.string "No Pokémon should be able to avoid it.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registered Gym Leader Winona\n"
	.string "in the Pokénav.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Though I fell to you, I will remain\n"
	.string "devoted to Bird Pokémon.$"

FortreeCity_Gym_Text_GymStatue:
	.string "Fortree City Pokémon Gym$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "Fortree City Pokémon Gym\p"
	.string "Winona's certified Trainers:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "Winona: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "Pokémon with you?\p"
	.string "Please return with two Pokémon\n"
	.string "at the very least.$"
