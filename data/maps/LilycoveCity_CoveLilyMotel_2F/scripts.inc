LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Ik ben de GAME DESIGNER.\p"
	.string "O, echt?\n"
	.string "Werk je aan een POKéDEX?\p"
	.string "Het is lastig om hem vol te\n"
	.string "krijgen, maar geef niet op.\p"
	.string "Als het lukt, laat het me dan zien.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wauw! Dat is geweldig!\n"
	.string "Ja, echt geweldig!\p"
	.string "Deze POKéDEX is helemaal vol!\n"
	.string "Je houdt echt van POKéMON!\p"
	.string "Ik ben onder de indruk!\p"
	.string "Dit krijg je van mij voor\n"
	.string "je prestatie!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Ik? Praat je tegen mij?\n"
	.string "Ik ben de PROGRAMMEUR.\p"
	.string "Benieuwd hoe de SLOTS\n"
	.string "hier zijn.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Ik ben de GRAFISCH ONTWERPER!\n"
	.string "Zijn de POKéMON van HOENN niet leuk?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "De WATERRAT-meisjes zijn schattig,\n"
	.string "hè? Vechten tegen een schattige\l"
	.string "WATERRAT…\p"
	.string "Wauw, het is geweldig!\p"
	.string "En de TWEELINGEN! Zijn ze niet\n"
	.string "schattig? Een 2-tegen-2 met\l"
	.string "TWEELINGEN…\p"
	.string "Wauw, het is zo leuk!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "De zeebries kriebelt in mijn hart.\n"
	.string "Het voelt hier heerlijk!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Je weet nooit waar en wanneer\n"
	.string "iemand je uitdaagt.\p"
	.string "Daarom ga ik nooit de deur uit\n"
	.string "zonder mijn GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hè?!\n"
	.string "Oh, sorry, sorry! Ik sliep!\p"
	.string "Ik kwam die POKéMON WEDSTRIJD\n"
	.string "bekijken.\p"
	.string "Het ziet er best leuk uit, maar…\p"
	.string "Ik ben een purist: ik hou meer\n"
	.string "van gevechten en sterke TRAINERS.\p"
	.string "Maar dat ben ik maar.\p"
	.string "{PLAYER}{KUN}, ik hoop dat je van alles\n"
	.string "genoot: GYMS, WEDSTRIJDEN, de\l"
	.string "BATTLE TENT, het hele pakket!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Ik denk dat je een plan\n"
	.string "nodig hebt om een WEDSTRIJD te\l"
	.string "winnen.\p"
	.string "Plannen maken voor WEDSTRIJDEN helpt\n"
	.string "je een betere TRAINER te worden.$"

