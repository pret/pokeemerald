VictoryRoad_B2F_MapScripts:: @ 82368D4
	.byte 0

VictoryRoad_B2F_EventScript_Vito:: @ 82368D5
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen:: @ 82368EC
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline:: @ 8236903
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie:: @ 823691A
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix:: @ 8236931
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne:: @ 8236948
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro: @ 823695F
	.string "I trained together with my whole family,\n"
	.string "every one of us!\l"
	.string "I'm not losing to anyone!$"

VictoryRoad_B2F_Text_VitoDefeat: @ 82369B3
	.string "Better than my family?!\n"
	.string "Is that possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle: @ 82369DE
	.string "I was better than everyone in my\n"
	.string "family. I've never lost before…\p"
	.string "I've lost my confidence…\n"
	.string "Maybe I'll go home…$"

VictoryRoad_B2F_Text_OwenIntro: @ 8236A4C
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"

VictoryRoad_B2F_Text_OwenDefeat: @ 8236A92
	.string "The little shrimp is tough!$"

VictoryRoad_B2F_Text_OwenPostBattle: @ 8236AAE
	.string "The rumors I heard, that tough little\n"
	.string "kid is from PETALBURG CITY.$"

VictoryRoad_B2F_Text_CarolineIntro: @ 8236AF0
	.string "You must be getting a little tired.$"

VictoryRoad_B2F_Text_CarolineDefeat: @ 8236B14
	.string "No signs of tiring at all!$"

VictoryRoad_B2F_Text_CarolinePostBattle: @ 8236B2F
	.string "VICTORY ROAD and the POKéMON LEAGUE\n"
	.string "are long and grueling challenges.\l"
	.string "Beware of fatigue!$"

VictoryRoad_B2F_Text_JulieIntro: @ 8236B88
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of GYM BADGES.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!$"

VictoryRoad_B2F_Text_JulieDefeat: @ 8236C0A
	.string "You're better than me!$"

VictoryRoad_B2F_Text_JuliePostBattle: @ 8236C21
	.string "Gaze on your collected BADGES and\n"
	.string "remember the TRAINERS you've faced.$"

VictoryRoad_B2F_Text_FelixIntro: @ 8236C67
	.string "I've come this far, but the tension's\n"
	.string "giving me awful stomach pain…$"

VictoryRoad_B2F_Text_FelixDefeat: @ 8236CAB
	.string "Ooh…\n"
	.string "It hurts…$"

VictoryRoad_B2F_Text_FelixPostBattle: @ 8236CBA
	.string "I can't help getting all tense knowing\n"
	.string "that I'm nearing the POKéMON LEAGUE.\p"
	.string "It's all I can do to feign calm.$"

VictoryRoad_B2F_Text_DianneIntro: @ 8236D27
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"

VictoryRoad_B2F_Text_DianneDefeat: @ 8236D6E
	.string "Not rattled in the least bit!$"

VictoryRoad_B2F_Text_DiannePostBattle: @ 8236D8C
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"

