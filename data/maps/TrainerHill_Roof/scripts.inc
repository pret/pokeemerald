TrainerHill_Roof_MapScripts:: @ 8268FA7
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	.byte 0

TrainerHill_Roof_EventScript_Owner:: @ 8268FB2
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_Arrived
	case 1, TrainerHill_Roof_EventScript_GivePrize
	case 2, TrainerHill_Roof_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_EventScript_Arrived:: @ 8268FEA
	msgbox TrainerHill_Roof_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_EventScript_GivePrize:: @ 8268FF2
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_EventScript_CheckFinalTime
TrainerHill_Roof_EventScript_ReceivePrize:: @ 8269020
	msgbox TrainerHill_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_EventScript_CheckFinalTime

TrainerHill_Roof_EventScript_NoRoomForPrize:: @ 8269037
	msgbox TrainerHill_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_EventScript_CheckFinalTime

TrainerHill_Roof_EventScript_CheckFinalTime:: @ 8269054
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_EventScript_NewRecord
	case 1, TrainerHill_Roof_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_EventScript_EndSpeakToOwner
TrainerHill_Roof_EventScript_NewRecord:: @ 8269082
	msgbox TrainerHill_Roof_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_EventScript_NoNewRecord:: @ 8269090
	msgbox TrainerHill_Roof_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_EventScript_EndSpeakToOwner:: @ 826909E
	msgbox TrainerHill_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_EventScript_AlreadyReceivedPrize:: @ 82690A8
	msgbox TrainerHill_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

