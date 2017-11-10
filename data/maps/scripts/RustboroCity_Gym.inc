RustboroCity_Gym_MapScripts:: @ 8212F30
	.byte 0

RustboroCity_Gym_EventScript_212F31:: @ 8212F31
	trainerbattle 1, TRAINER_ROXANNE_1, 0, RustboroCity_Gym_Text_21362A, RustboroCity_Gym_Text_21370B, RustboroCity_Gym_EventScript_212F66
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq RustboroCity_Gym_EventScript_212FC8
	checkflag FLAG_0x0A5
	goto_if 0, RustboroCity_Gym_EventScript_212FA4
	msgbox RustboroCity_Gym_Text_2139A7, 4
	release
	end

RustboroCity_Gym_EventScript_212F66:: @ 8212F66
	message RustboroCity_Gym_Text_2137EC
	waitmessage
	call RustboroCity_Gym_EventScript_27207E
	msgbox RustboroCity_Gym_Text_213816, 4
	setflag FLAG_0x4F0
	setflag FLAG_BADGE01_GET
	setvar VAR_0x405A, 1
	addvar VAR_0x4085, 1
	setvar VAR_0x8008, 1
	call RustboroCity_Gym_EventScript_271F43
	compare_var_to_value VAR_0x4085, 6
	call_if 1, RustboroCity_Gym_EventScript_271E84
	goto RustboroCity_Gym_EventScript_212FA4
	end

RustboroCity_Gym_EventScript_212FA4:: @ 8212FA4
	giveitem_std ITEM_TM39
	compare_var_to_value VAR_RESULT, 0
	goto_eq RustboroCity_Gym_EventScript_272054
	setflag FLAG_0x0A5
	msgbox RustboroCity_Gym_Text_2138B1, 4
	release
	end

RustboroCity_Gym_EventScript_212FC8:: @ 8212FC8
	trainerbattle 7, TRAINER_ROXANNE_1, 0, RustboroCity_Gym_Text_213C2F, RustboroCity_Gym_Text_213CF9, RustboroCity_Gym_Text_213D93
	msgbox RustboroCity_Gym_Text_213D12, 6
	end

RustboroCity_Gym_EventScript_212FE3:: @ 8212FE3
	trainerbattle 0, TRAINER_JOSH, 0, RustboroCity_Gym_Text_2133E9, RustboroCity_Gym_Text_21342D
	msgbox RustboroCity_Gym_Text_213447, 6
	end

RustboroCity_Gym_EventScript_212FFA:: @ 8212FFA
	trainerbattle 0, TRAINER_TOMMY, 0, RustboroCity_Gym_Text_213486, RustboroCity_Gym_Text_2134C6
	msgbox RustboroCity_Gym_Text_2134E6, 6
	end

RustboroCity_Gym_EventScript_213011:: @ 8213011
	trainerbattle 0, TRAINER_MARC, 0, RustboroCity_Gym_Text_213533, RustboroCity_Gym_Text_213589
	msgbox RustboroCity_Gym_Text_2135C0, 6
	end

RustboroCity_Gym_EventScript_213028:: @ 8213028
	lock
	faceplayer
	checkflag FLAG_0x4F0
	goto_eq RustboroCity_Gym_EventScript_21303D
	msgbox RustboroCity_Gym_Text_21309D, 4
	release
	end

RustboroCity_Gym_EventScript_21303D:: @ 821303D
	msgbox RustboroCity_Gym_Text_2132E2, 4
	release
	end

RustboroCity_Gym_EventScript_213047:: @ 8213047
	lockall
	checkflag FLAG_BADGE01_GET
	goto_eq RustboroCity_Gym_EventScript_213067
	goto RustboroCity_Gym_EventScript_213071
	end

RustboroCity_Gym_EventScript_213057:: @ 8213057
	lockall
	checkflag FLAG_BADGE01_GET
	goto_eq RustboroCity_Gym_EventScript_213067
	goto RustboroCity_Gym_EventScript_213071
	end

RustboroCity_Gym_EventScript_213067:: @ 8213067
	msgbox RustboroCity_Gym_Text_213A3B, 4
	releaseall
	end

RustboroCity_Gym_EventScript_213071:: @ 8213071
	msgbox RustboroCity_Gym_Text_213A21, 4
	releaseall
	end

