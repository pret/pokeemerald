SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Tu connais le POKéMON GRAINIPIOT?\n"
	.string "Il se fait rare à ATALANOPOLIS.\p"
	.string "Moi, j’adore les grands GRAINIPIOT.\n"
	.string "Plus ils sont grands et mieux c’est.\p"
	.string "Mais mon p’tit frère, il dit que les\n"
	.string "NENUPIOT sont plus grands.\p"
	.string "C’est pas vrai. Les GRAINIPIOT\n"
	.string "sont encore plus grands!\p"
	.string "Hum? Tu as un GRAINIPIOT avec toi?\n"
	.string "Oh, fais-moi voir, s’il te plaît!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} cm!\n"
	.string "Waouh, il est grand celui-là!\p"
	.string "Il pourrait même dépasser le grand\n"
	.string "NENUPIOT que mon p’tit frère a vu!\p"
	.string "Merci de me l’avoir montré.\n"
	.string "Tiens, c’est ma façon de te remercier!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} received a POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Oh?\n"
	.string "Ton SAC est carrément plein.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} cm, c’est ça?\p"
	.string "Hum… J’ai vu un plus grand GRAINIPIOT\n"
	.string "que celui-là.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Ah oui, c’est quelque chose!\n"
	.string "Mais c’est pas un GRAINIPIOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Tu n’as pas de grand GRAINIPIOT?\n"
	.string "Quel dommage!\p"
	.string "Si tu trouves un grand GRAINIPIOT,\n"
	.string "viens me le montrer.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "Le plus grand GRAINIPIOT jamais vu!\n"
	.string "Un géant de {STR_VAR_3} cm appartenant\l"
	.string "à {STR_VAR_2}!\p"
	.string "Un GRAINIPIOT encore plus\n"
	.string "grand qu’un NENUPIOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Tu connais le POKéMON NENUPIOT?\n"
	.string "On en voit rarement à ATALANOPOLIS.\p"
	.string "J’adore, j’adore les grands NENUPIOT!\p"
	.string "Mon grand frère dit que le GRAINIPIOT\n"
	.string "est plus grand.\p"
	.string "Mais c’est faux! Tout le monde sait\n"
	.string "bien que le NENUPIOT est plus grand.\p"
	.string "Hum? Tu as un NENUPIOT?\n"
	.string "Fais-moi voir, s’il te plaît!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} cm!\n"
	.string "Waouh, c’est beaucoup!\p"
	.string "C’est peut-être encore plus grand que\n"
	.string "l’énorme GRAINIPIOT que mon frère a vu.\p"
	.string "Merci de me l’avoir montré!\n"
	.string "Tiens, c’est pour te remercier!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} received a POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Oh?\n"
	.string "Ton SAC est carrément plein.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} cm?\p"
	.string "Hum… J’ai vu un plus grand NENUPIOT\n"
	.string "que celui-là.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Eh bien, ça c’est quelque chose!\n"
	.string "Mais c’est pas un NENUPIOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Tu n’as pas de grand NENUPIOT?\n"
	.string "C’est dommage…\p"
	.string "Si tu trouves un grand NENUPIOT,\n"
	.string "viens me le montrer.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "Le plus grand NENUPIOT jamais vu!\n"
	.string "Un colosse de {STR_VAR_3} cm appartenant\l"
	.string "à {STR_VAR_2}!\p"
	.string "Un NENUPIOT encore plus\n"
	.string "grand qu’un GRAINIPIOT!$"

