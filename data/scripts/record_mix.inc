@ Seems this was superseded by the Record Center, and the below scripts are now unused
EventScript_MixRecordsPrompt:: @ 8271D5E
	lock
	faceplayer
	msgbox Text_WouldYouLikeToMixRecords, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_MixRecords
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DeclineMixRecords
	goto EventScript_DeclineMixRecords

EventScript_MixRecords:: @ 8271D83
	special RecordMixingPlayerSpotTriggered
	waitstate
	lock
	faceplayer

EventScript_DeclineMixRecords:: @ 8271D89
	message Text_WeHopeToSeeYouAgain
	waitmessage
	waitbuttonpress
	release
	end
