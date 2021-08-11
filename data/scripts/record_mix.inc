@ Seems this was superseded by the Record Center, and the below scripts are now unused
EventScript_MixRecordsPrompt::
	lock
	faceplayer
	msgbox Text_WouldYouLikeToMixRecords, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_MixRecords
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndMixRecords
	goto EventScript_EndMixRecords

EventScript_MixRecords::
	special RecordMixingPlayerSpotTriggered
	waitstate
	lock
	faceplayer
EventScript_EndMixRecords::
	message Text_WeHopeToSeeYouAgain
	waitmessage
	waitbuttonpress
	release
	end
