AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "Dan: While searching for treasures,\n"
	.string "we discovered a Trainer!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "Dan: We couldn't win even though\n"
	.string "we worked together…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "Dan: We can't find any treasures…\n"
	.string "I wonder if someone got them already?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "Dan: You don't even have two Pokémon.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "Kira: Oh?\n"
	.string "We were searching for treasures.\l"
	.string "But we discovered a Trainer instead!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "Kira: Ooh, so strong!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "Kira: Where could the treasures be?\p"
	.string "I've already decided what I'm buying\n"
	.string "when we find the treasures!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "Kira: Oh, you don't have two Pokémon?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "Kira: Oh, you make me so angry!\n"
	.string "I'm going to register you for that!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "Dan: We've been searching for\n"
	.string "treasures all this time.\p"
	.string "Our Pokémon have grown stronger, too.\n"
	.string "Let us show you, okay?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "Dan: You're strong, as usual!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "Dan: We can't find any treasures,\n"
	.string "we lose at Pokémon…\p"
	.string "I want to go home… But if I say that,\n"
	.string "she gets all angry with me…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "Dan: You don't even have two Pokémon.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "Kira: Oh? We meet again!\p"
	.string "Just like us, you still haven't given up\n"
	.string "searching for treasures, have you?\p"
	.string "Want to make it so the loser has\n"
	.string "to give up searching?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "Kira: Oh, we lost again…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "Kira: We're not leaving until we raise\n"
	.string "our Pokémon some more and we find\l"
	.string "the treasures here!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "Kira: Oh, you don't have two Pokémon?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "I'm not good at swimming,\n"
	.string "but I am good at battles!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oops.\n"
	.string "That didn't go very well.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Walking around barefoot in this ship\n"
	.string "is kind of gross.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Strength and compassion…\n"
	.string "Those are a Trainer's treasures!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, there is something about you\n"
	.string "that sparkles.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "In a cabin somewhere on board,\n"
	.string "I saw something sparkle.$"
