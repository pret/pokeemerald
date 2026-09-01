BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Boo!\n"
	.string "Cheapie!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"

