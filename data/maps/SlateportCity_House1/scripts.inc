SlateportCity_House1_MapScripts:: @ 8209AA4
	.byte 0

SlateportCity_House1_EventScript_209AA5:: @ 8209AA5
	lock
	faceplayer
	msgbox SlateportCity_House1_Text_209B8E, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209AC6
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_House1_EventScript_209AE9
	end

SlateportCity_House1_EventScript_209AC6:: @ 8209AC6
	msgbox SlateportCity_House1_Text_209BFF, MSGBOX_DEFAULT
	special sub_81B94B0
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne SlateportCity_House1_EventScript_209AF3
	compare VAR_0x8004, 255
	goto_if_eq SlateportCity_House1_EventScript_209AE9
	end

SlateportCity_House1_EventScript_209AE9:: @ 8209AE9
	msgbox SlateportCity_House1_Text_209D42, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209AF3:: @ 8209AF3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq SlateportCity_House1_EventScript_209B46
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	special TV_CheckMonOTIDEqualsPlayerID
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B50
	specialvar VAR_RESULT, MonOTNameMatchesPlayer
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B50
	msgbox SlateportCity_House1_Text_209C2B, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B5A
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_House1_EventScript_209AE9
	end

SlateportCity_House1_EventScript_209B46:: @ 8209B46
	msgbox SlateportCity_House1_Text_209E74, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209B50:: @ 8209B50
	msgbox SlateportCity_House1_Text_209DF0, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209B5A:: @ 8209B5A
	msgbox SlateportCity_House1_Text_209CA4, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TV_PutNameRaterShowOnTheAirIfNicknameChanged
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House1_EventScript_209B84
	msgbox SlateportCity_House1_Text_209D5E, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_EventScript_209B84:: @ 8209B84
	msgbox SlateportCity_House1_Text_209CD4, MSGBOX_DEFAULT
	release
	end

SlateportCity_House1_Text_209B8E: @ 8209B8E
	.string "Hi, hi! I'm the NAME RATER!\n"
	.string "I'm the fortune-teller of names!\p"
	.string "I shall be pleased to rate your\n"
	.string "POKéMON's nickname.$"

SlateportCity_House1_Text_209BFF: @ 8209BFF
	.string "Which POKéMON's nickname should\n"
	.string "I critique?$"

SlateportCity_House1_Text_209C2B: @ 8209C2B
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine name you bestowed.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better name?$"

SlateportCity_House1_Text_209CA4: @ 8209CA4
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

SlateportCity_House1_Text_209CD4: @ 8209CD4
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"

SlateportCity_House1_Text_209D42: @ 8209D42
	.string "I see.\n"
	.string "Do come visit again.$"

SlateportCity_House1_Text_209D5E: @ 8209D5E
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"

SlateportCity_House1_Text_209DF0: @ 8209DF0
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nickname!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "{STR_VAR_1} now and beyond.$"

SlateportCity_House1_Text_209E74: @ 8209E74
	.string "Now, now.\n"
	.string "That is merely an EGG!$"

