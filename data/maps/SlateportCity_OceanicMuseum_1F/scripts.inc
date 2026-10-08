SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applywaitmovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applywaitmovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Welkom in het OCEANIC MUSEUM.\p"
	.string "De toegang kost ¥50.\n"
	.string "Wil je naar binnen?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Veel plezier!$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Sorry, maar je hebt niet\n"
	.string "genoeg geld.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Hoor jij bij die groep die\n"
	.string "net naar binnen ging?\p"
	.string "Jij bent de enige die te laat is.\n"
	.string "Snel, haal ze maar in!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Wij, TEAM AQUA, zijn er voor\n"
	.string "het welzijn van iedereen!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "We moesten hier verzamelen,\n"
	.string "dus dat deden we, maar…\p"
	.string "Onze BAAS, de belangrijkste,\n"
	.string "is er niet.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Als ik de spullen hier jat,\n"
	.string "word ik dan rijk?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Wat ik hier leer, kan ik gebruiken\n"
	.string "voor gemene plannen…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Als onze maten het in RUSTBORO niet\n"
	.string "hadden verknoeid, waren we hier niet!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Ik had geen ¥50, dus het duurde\n"
	.string "lang om langs de balie te komen.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Ik wil alles over de zee leren en\n"
	.string "dat gebruiken in gevechten.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Ik word helemaal blij en week\n"
	.string "als ik de zee zie!\p"
	.string "CAPT. STERN is mijn grote\n"
	.string "voorbeeld!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "De zee is eindeloos groot en\n"
	.string "superdiep…\p"
	.string "Er zijn vast veel POKéMON die\n"
	.string "we nog niet kennen.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Ik wil een zee-POKéMON.\p"
	.string "Die is vast lekker koel om\n"
	.string "te knuffelen.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aaaah!\n"
	.string "Wat doe jij hier?\p"
	.string "Ik? Ik ben dat lid van TEAM AQUA\n"
	.string "dat jij hebt verslagen, weet je nog?\l"
	.string "In de RUSTURF TUNNEL?\p"
	.string "Hier, neem dit!\n"
	.string "Vergeef het me alsjeblieft!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Die TM past beter bij jou\n"
	.string "dan bij mij.\p"
	.string "Ik hoop dat ik je nooit meer zie!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Ah, kom op!\n"
	.string "Neem dit nou en laat me gaan!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "In een glazen pot draait een\n"
	.string "blauwe vloeistof rond.\p"
	.string "“Dit is een proef om met wind\n"
	.string "een DRAAIKOLK te maken.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "In een glazen pot dobbert een\n"
	.string "rode bal op en neer.\p"
	.string "“Dit is een proef die een WATERVAL\n"
	.string "nadoet met een drijvende bal.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Dit is wat grond van de\n"
	.string "zeebodem.\p"
	.string "“Na vele jaren zakken de resten van\n"
	.string "dieren en planten naar de bodem\l"
	.string "van de zee. Zo ontstaan lagen.\p"
	.string "“Door die lagen te onderzoeken,\n"
	.string "leren we over het verre verleden.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Dit is wat zand van het strand.\p"
	.string "“Rivieren nemen stenen uit de\n"
	.string "bergen mee. Onderweg breken\l"
	.string "ze en slijten ze af.\p"
	.string "“Ze worden heel kleine korrels en\n"
	.string "eindigen als zand op het strand.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“ZEEWEETJE 1\n"
	.string "Waarom is zeewater blauw?\p"
	.string "“Licht bestaat uit veel kleuren.\p"
	.string "“Als licht door water gaat,\n"
	.string "verdwijnen de meeste kleuren.\p"
	.string "“Maar blauw licht blijft over.\n"
	.string "Daarom lijkt de zee blauw.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“ZEEWEETJE 2\n"
	.string "Waarom is de zee zout?\p"
	.string "“In zeewater zit opgelost zout.\n"
	.string "Dat zijn kleine deeltjes.\p"
	.string "“Die deeltjes komen uit stenen.\n"
	.string "Regen brengt ze naar zee.\p"
	.string "“Door al dat zout is de zee\n"
	.string "zout.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“ZEEWEETJE 3\n"
	.string "Wat is groter? De zee of het land?\p"
	.string "“De zee is ongeveer 70% van de\n"
	.string "aarde. De rest is land.\p"
	.string "“De zee is dus meer dan twee\n"
	.string "keer zo groot als het land.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Een fossiel met golfjes erop.\p"
	.string "“Het getij schuurt over de grond\n"
	.string "op de zeebodem.\p"
	.string "“Het stromende water maakt kleine\n"
	.string "richels en dalen in de grond.\p"
	.string "“Als die grond een fossiel wordt,\n"
	.string "heet dat een ribbel.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Onder een glazen koepel draait\n"
	.string "een vreemde machine.\p"
	.string "Misschien meet hij hoe diep\n"
	.string "iets is…$"

