PacifidlogTown_House2_MapScripts:: @ 8203791
	.byte 0

PacifidlogTown_House2_EventScript_203792:: @ 8203792
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_2037DE
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_20387E
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_2037F8
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_203801
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge PacifidlogTown_House2_EventScript_203816
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 2
	goto_if_ge PacifidlogTown_House2_EventScript_203845
	goto PacifidlogTown_House2_EventScript_20384F
	end

PacifidlogTown_House2_EventScript_2037DE:: @ 82037DE
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	compare VAR_RESULT, 0
	call_if_eq PacifidlogTown_House2_EventScript_203812
	return

PacifidlogTown_House2_EventScript_2037F8:: @ 82037F8
	msgbox PacifidlogTown_House2_Text_20395B, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_203801:: @ 8203801
	msgbox PacifidlogTown_House2_Text_2038C7, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_20395B, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_203812:: @ 8203812
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_203816:: @ 8203816
	msgbox PacifidlogTown_House2_Text_20396D, MSGBOX_DEFAULT
	giveitem_std ITEM_TM27
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_203A85, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_203845:: @ 8203845
	msgbox PacifidlogTown_House2_Text_2039CE, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_20384F:: @ 820384F
	msgbox PacifidlogTown_House2_Text_203A2F, MSGBOX_DEFAULT
	giveitem_std ITEM_TM21
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_203A85, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_20387E:: @ 820387E
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring 0, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_203AF4, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_203891:: @ 8203891
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox PacifidlogTown_House2_Text_203B8D, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_203B9D, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_2038AC:: @ 82038AC
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 2
	msgbox PacifidlogTown_House2_Text_203BCE, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_203BDF, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_2038C7: @ 82038C7
	.string "Er-hem!\p"
	.string "I am the POKéMON FAN CLUB's most\n"
	.string "important person, the CHAIRMAN's\l"
	.string "younger brother.\p"
	.string "I'm here enjoying my vacation with\n"
	.string "POKéMON, yes, indeed.$"

PacifidlogTown_House2_Text_20395B: @ 820395B
	.string "Ah!\n"
	.string "Your POKéMON…$"

PacifidlogTown_House2_Text_20396D: @ 820396D
	.string "It clearly likes you very much.\p"
	.string "A POKéMON that adoring and adorable\n"
	.string "deserves a TM like this, no?$"

PacifidlogTown_House2_Text_2039CE: @ 82039CE
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the TRAINER, need to put in\n"
	.string "some more effort.$"

PacifidlogTown_House2_Text_203A2F: @ 8203A2F
	.string "It has a vicious look to it.\p"
	.string "A frightening POKéMON like that\n"
	.string "deserves a TM like this.$"

PacifidlogTown_House2_Text_203A85: @ 8203A85
	.string "If a POKéMON likes you a lot, RETURN's\n"
	.string "power is enhanced.\p"
	.string "If it doesn't like you, FRUSTRATION's\n"
	.string "power goes up.$"

PacifidlogTown_House2_Text_203AF4: @ 8203AF4
	.string "Oh, yes. In about {STR_VAR_1} or so days,\n"
	.string "I should be getting a good TM or two.\p"
	.string "You should come see me then.\n"
	.string "I'll give you a TM that's suitable for\l"
	.string "your POKéMON.$"

PacifidlogTown_House2_Text_203B8D: @ 8203B8D
	.string "AZURILL: Rurii.$"

PacifidlogTown_House2_Text_203B9D: @ 8203B9D
	.string "It appears to be very friendly with the\n"
	.string "TRAINER.$"

PacifidlogTown_House2_Text_203BCE: @ 8203BCE
	.string "AZURILL: Rururi!$"

PacifidlogTown_House2_Text_203BDF: @ 8203BDF
	.string "It doesn't appear to like the TRAINER\n"
	.string "very much.$"

