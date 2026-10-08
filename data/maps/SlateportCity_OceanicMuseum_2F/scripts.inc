SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applywaitmovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applywaitmovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Ja? Zoek je STERN?\n"
	.string "Dat ben ik.\p"
	.string "Ah! Dat zijn vast de onderdelen die\n"
	.string "ik bij MR. STONE van DEVON bestelde.\p"
	.string "Dank je wel! Geweldig!\n"
	.string "Nu kunnen we onze reis voorbereiden.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, stop!\n"
	.string "Wij nemen die onderdelen!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. STERN: W-wat?\n"
	.string "Wie zijn jullie?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Wij zijn TEAM AQUA!\p"
	.string "Onze BAAS wil die onderdelen!\n"
	.string "Hou je mond en geef ze hier!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaaah!\n"
	.string "Een kind heeft me verslagen!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "O nee, wat een ramp…\n"
	.string "De BAAS wordt woedend…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Hmpf, jankerd!\n"
	.string "Laat mij dit maar doen!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Wat?!\n"
	.string "Ik verlies ook!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Wat nu? Zonder die onderdelen\n"
	.string "zijn we de klos!\p"
	.string "Argh, ik had niet gedacht dat een\n"
	.string "bemoeizuchtig kind ons zou dwarsbomen!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Ik kwam kijken waarom het zo lang\n"
	.string "duurt om wat onderdelen te jatten.\l"
	.string "En jullie sukkels worden tegengehouden\l"
	.string "door een kind?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Wij zijn TEAM AQUA,\n"
	.string "en wij houden van de zee!\p"
	.string "En ik ben de leider van TEAM AQUA,\n"
	.string "ARCHIE!\p"
	.string "Waarom zit jij ons dwars?\p"
	.string "…Nee! Dat kan niet!\n"
	.string "Jij bent toch niet van TEAM MAGMA?\p"
	.string "Wacht, dat klopt niet.\n"
	.string "Je draagt hun kleren niet.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, mensen… Al het leven\n"
	.string "hangt af van de zee.\p"
	.string "Daarom wil TEAM AQUA de zee\n"
	.string "groter maken.\p"
	.string "Vind je ook niet? Wat wij doen,\n"
	.string "is een prachtig plan.\p"
	.string "Ah, laat maar…\n"
	.string "Je bent nog te jong om ons\l"
	.string "mooie doel te snappen.\p"
	.string "Maar ik waarschuw je: bemoei je\n"
	.string "niet meer met onze plannen.\p"
	.string "Anders krijg je daar flink\n"
	.string "spijt van!\p"
	.string "Vergeet dat niet!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPT. STERN: Jij bent…\n"
	.string "Ah, oké, jij bent {PLAYER}{KUN}…\p"
	.string "Dat was best eng, zeg!\n"
	.string "Bedankt dat je ons hebt gered!\p"
	.string "O ja, ik vergat bijna dat jij ook\n"
	.string "de onderdelen van DEVON bracht!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. STERN: Oeps!\n"
	.string "Er is geen tijd te verliezen!\p"
	.string "We gaan heel snel op reis naar\n"
	.string "de zeebodem.\p"
	.string "Nogmaals bedankt, maar nu\n"
	.string "moet ik gaan!\p"
	.string "Kijk gerust rond in ons\n"
	.string "MUSEUM.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Ik zag hier een model van een schip.\p"
	.string "Het deed me denken aan het ABANDONED\n"
	.string "SHIP bij DEWFORD TOWN…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Je mag niet rennen in\n"
	.string "het MUSEUM!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Wauw, die duikboot is supertof!\n"
	.string "Ik wil er een ritje in maken!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“WATERMONSTER 1,” staat er\n"
	.string "op het etiket.\p"
	.string "De zee hangt overal aan elkaar,\n"
	.string "maar het water is overal anders.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“WATERMONSTER 2,” staat er\n"
	.string "op het etiket.\p"
	.string "Is zeewater ook niet overal\n"
	.string "even zout?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Een rubberen bal wordt groter\n"
	.string "en weer kleiner.\p"
	.string "“In de zee drukt het gewicht van\n"
	.string "het water zelf op alles.\p"
	.string "“In ondiep water is die druk\n"
	.string "niet zo groot.\p"
	.string "“Maar heel diep in de zee kan de\n"
	.string "druk wel duizenden tonnen zijn,\l"
	.string "op een heel klein stukje.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODEL VAN DE HOENN REGIO”\p"
	.string "Het is een mini-model van\n"
	.string "de HOENN regio.\p"
	.string "Waar ligt LITTLEROOT TOWN hierop?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Uitleg over hoe zeewater stroomt.\p"
	.string "“Diep in de zee stroomt water door\n"
	.string "verschillen in bijvoorbeeld\l"
	.string "warmte en zout.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Uitleg over hoe zeewater stroomt.\p"
	.string "“Bovenin de zee stroomt het water\n"
	.string "door de wind.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“DE VEERBOOT S.S. TIDAL\p"
	.string "“Een schaalmodel van het schip dat\n"
	.string "wordt gebouwd bij STERN.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“SUBMARINE EXPLORER 1\p"
	.string "“Een model van de supersnelle\n"
	.string "duikboot voor de zeebodem.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“DUIKCAPSULE\p"
	.string "“Een model van een kleine capsule\n"
	.string "zonder mensen, voor de zeebodem.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Een model van het luxe schip dat\n"
	.string "de hele wereld rond vaart.”$"

