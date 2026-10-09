BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
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
	.string "Ik weet wat POKéMON denken!\p"
	.string "Alsjeblieft!\n"
	.string "Mag ik je POKéMON zien?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Boe!\n"
	.string "Wat flauw!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Hij vecht ook als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "slaat hij terug!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "gaat hij aan zichzelf denken!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Hij vecht ook als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "slaat hij terug!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "gaat hij aan zichzelf denken!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Hij vecht ook als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "slaat hij terug!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "gaat hij aan zichzelf denken!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Hij is ook stiekem als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "wordt hij stiekem!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Hij vecht ook als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Hij is ook stiekem als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "gaat hij aan zichzelf denken!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Hij denkt ook aan zichzelf als hij\l"
	.string "veel auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "wordt hij stiekem!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Hij denkt ook aan zichzelf als hij\l"
	.string "veel auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag stiekem is!\n"
	.string "Hij is ook stiekem als hij veel\l"
	.string "auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Hij denkt ook aan zichzelf als hij\l"
	.string "veel auwtjes heeft!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "slaat hij terug!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij graag vecht!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "wordt hij stiekem!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Deze zegt dat hij op zichzelf let!\n"
	.string "Maar met genoeg auwtjes\l"
	.string "wordt hij stiekem!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Dat is gek! Een EI slaapt!\n"
	.string "Ik kan er niet mee praten!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Wat schattig!\n"
	.string "Dat meisje beweert dat ze\l"
	.string "POKéMON kan verstaan!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Ik heb het gevoel dat het meisje\n"
	.string "ietsbetekenends zegt.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Ik weet iets!\p"
	.string "Dat meisje speelt vaak bij het\n"
	.string "rode huis!$"

