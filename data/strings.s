	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gExpandedPlaceholder_Empty:: @ 85E8218
	.string "$"

gExpandedPlaceholder_Kun:: @ 85E8219
	.string "$"

gExpandedPlaceholder_Chan:: @ 85E821A
	.string "$"

gExpandedPlaceholder_Sapphire:: @ 85E821B
	.string "SAPPHIRE$"

gExpandedPlaceholder_Ruby:: @ 85E8224
	.string "RUBY$"

gExpandedPlaceholder_Emerald:: @ 85E8229
	.string "EMERALD$"

gExpandedPlaceholder_Aqua:: @ 85E8231
	.string "AQUA$"

gExpandedPlaceholder_Magma:: @ 85E8236
	.string "MAGMA$"

gExpandedPlaceholder_Archie:: @ 85E823C
	.string "ARCHIE$"

gExpandedPlaceholder_Maxie:: @ 85E8243
	.string "MAXIE$"

gExpandedPlaceholder_Kyogre:: @ 85E8249
	.string "KYOGRE$"

gExpandedPlaceholder_Groudon:: @ 85E8250
	.string "GROUDON$"

gExpandedPlaceholder_Brendan:: @ 85E8258
	.string "BRENDAN$"

gExpandedPlaceholder_May:: @ 85E8260
	.string "MAY$"

gText_EggNickname:: @ 85E8264
	.string "EGG$"

gText_Pokemon:: @ 85E8268
	.string "POKéMON$"
	.string "PROF. BIRCH$"

gText_MainMenuNewGame:: @ 85E827C
	.string "NEW GAME$"

gText_MainMenuContinue:: @ 85E8285
	.string "CONTINUE$"

gText_MainMenuOption:: @ 85E828E
	.string "OPTION$"

gText_MainMenuMysteryGift:: @ 85E8295
	.string "MYSTERY GIFT$"

gText_MainMenuMysteryGift2:: @ 85E82A2
	.string "MYSTERY GIFT$"

gText_MainMenuMysteryEvents:: @ 85E82AF
	.string "MYSTERY EVENTS$"

gText_WirelessNotConnected:: @ 85E82BE
	.string "The Wireless Adapter is not\nconnected.$"

gText_MysteryGiftCantUse:: @ 85E82E5
	.string "MYSTERY GIFT can’t be used while\nthe Wireless Adapter is attached.$"

gText_MysteryEventsCantUse:: @ 85E8328
	.string "MYSTERY EVENTS can’t be used while\nthe Wireless Adapter is attached.$"
	.string "Updating save file using external\ndata. Please wait.$"
	.string "The save file has been updated.$"

gText_SaveFileCorrupted:: @ 85E83C2
	.string "The save file is corrupted. The\nprevious save file will be loaded.$"

gText_SaveFileErased:: @ 85E8405
	.string "The save file has been erased\ndue to corruption or damage.$"

gJPText_No1MSubCircuit:: @ 85E8440
	.string "1Mサブきばんが ささっていません！$" @ "1Msabukibanga sasatteimasen!" ("The 1M sub-circuit board is not installed!" in Japanese)

gText_BatteryRunDry:: @ 85E8453
	.string "The internal battery has run dry.\nThe game can be played.\pHowever, clock-based events will\nno longer occur.$"
	.string "PLAYER$"
	.string "POKéDEX$"

gText_MainMenuTime:: @ 85E84CE
	.string "TIME$"
	.string "BADGES$"
	.string "A Button$"
	.string "B Button$"
	.string "R Button$"
	.string "L Button$"
	.string "START$"
	.string "SELECT$"
	.string "+ Control Pad$"
	.string "L Button  R Button$"
	.string "CONTROLS$"

	.align 2
	.string "{UNK_CTRL_F80A}PICK {UNK_CTRL_F800}OK$"

	.align 2
	.string "{UNK_CTRL_F800}NEXT$"

	.align 2
	.string "{UNK_CTRL_F800}NEXT {UNK_CTRL_F801}BACK$"

	.align 2
gText_PickNextCancel:: @ 85E855C
	.string "{UNK_CTRL_F80A}PICK {UNK_CTRL_F800}NEXT {UNK_CTRL_F801}CANCEL$"

	.align 2
gText_PickCancel:: @ 85E8574
	.string "{UNK_CTRL_F80A}PICK {UNK_CTRL_F800}{UNK_CTRL_F801}CANCEL$"

	.align 2
gText_UnkCtrlF800Exit:: @ 85E8588
	.string "{UNK_CTRL_F800}EXIT$"
	.string "BOY$"
	.string "GIRL$"
	.string "STU$"
	.string "MILTON$"
	.string "TOM$"
	.string "KENNY$"
	.string "REID$"
	.string "JUDE$"
	.string "JAXSON$"
	.string "EASTON$"
	.string "WALKER$"
	.string "TERU$"
	.string "JOHNNY$"
	.string "BRETT$"
	.string "SETH$"
	.string "TERRY$"
	.string "CASEY$"
	.string "DARREN$"
	.string "LANDON$"
	.string "COLLIN$"
	.string "STANLEY$"
	.string "QUINCY$"
	.string "KIMMY$"
	.string "TIARA$"
	.string "BELLA$"
	.string "JAYLA$"
	.string "ALLIE$"
	.string "LIANNA$"
	.string "SARA$"
	.string "MONICA$"
	.string "CAMILA$"
	.string "AUBREE$"
	.string "RUTHIE$"
	.string "HAZEL$"
	.string "NADINE$"
	.string "TANJA$"
	.string "YASMIN$"
	.string "NICOLA$"
	.string "LILLIE$"
	.string "TERRA$"
	.string "LUCY$"
	.string "HALIE$"

gText_ThisIsAPokemon:: @ 85E8692
	.string "This is what we call a “POKéMON.”{PAUSE 96}\p$"

gText_5MarksPokemon:: @ 85E86B8
	.string "????? POKéMON$"

gText_UnkHeight:: @ 85E86C6
	.string "{CLEAR_TO 0x0C}??’??”$"

gText_UnkWeight:: @ 85E86D0
	.string "????.? lbs.$"
	.string "                       POKéMON$"
	.string "{CLEAR_TO 0x0C}    ’    ”$"
	.string "        .   lbs.$"
	.string "$"

gText_CryOf:: @ 85E871B
	.string "CRY OF$"
	.string "$"

gText_SizeComparedTo:: @ 85E8723
	.string "SIZE COMPARED TO $"

gText_PokedexRegistration:: @ 85E8735
	.string "POKéDEX registration completed.$"

gText_HTHeight:: @ 85E8755
	.string "HT$"

gText_WTWeight:: @ 85E8758
	.string "WT$"

gText_SearchingPleaseWait:: @ 85E875B
	.string "Searching…\nPlease wait.$"

gText_SearchCompleted:: @ 85E8773
	.string "Search completed.$"

gUnknown_085E8785:: @ 85E8785
	.string "No matching POKéMON were found.$"
	.string "Search for POKéMON based on\nselected parameters.$"
	.string "Switch POKéDEX listings.$"
	.string "Return to the POKéDEX.$"
	.string "Select the POKéDEX mode.$"
	.string "Select the POKéDEX listing mode.$"
	.string "List by the first letter in the name.\nSpotted POKéMON only.$"
	.string "List by body color.\nSpotted POKéMON only.$"
	.string "List by type.\nOwned POKéMON only.$"
	.string "Execute search/switch.$"
	.string "HOENN DEX$"
	.string "NATIONAL DEX$"
	.string "NUMERICAL MODE$"
	.string "A TO Z MODE$"
	.string "HEAVIEST MODE$"
	.string "LIGHTEST MODE$"
	.string "TALLEST MODE$"
	.string "SMALLEST MODE$"
	.string "ABC$"
	.string "DEF$"
	.string "GHI$"
	.string "JKL$"
	.string "MNO$"
	.string "PQR$"
	.string "STU$"
	.string "VWX$"
	.string "YZ$"
	.string "RED$"
	.string "BLUE$"
	.string "YELLOW$"
	.string "GREEN$"
	.string "BLACK$"
	.string "BROWN$"
	.string "PURPLE$"
	.string "GRAY$"
	.string "WHITE$"
	.string "PINK$"
	.string "HOENN region’s POKéDEX$"
	.string "National edition POKéDEX$"
	.string "POKéMON are listed according to their\nnumber.$"
	.string "Spotted and owned POKéMON are listed\nalphabetically.$"
	.string "Owned POKéMON are listed from the\nheaviest to the lightest.$"
	.string "Owned POKéMON are listed from the\nlightest to the heaviest.$"
	.string "Owned POKéMON are listed from the\ntallest to the smallest.$"
	.string "Owned POKéMON are listed from the\nsmallest to the tallest.$"
	.string "$"
	.string "DON’T SPECIFY.$"
	.string "NONE$"

gText_SelectorArrow:: @ 85E8B3A
	.string "▶$"
	.string " $"

gText_WelcomeToHOF:: @ 85E8B3E
	.string "Welcome to the HALL OF FAME!$"
	.string "Spotted POKéMON: {STR_VAR_1}!\nOwned POKéMON: {STR_VAR_2}!\pPROF. BIRCH’s POKéDEX rating!\pPROF. BIRCH: Let’s see…\p$"
	.string "SAVING…\nDON’T TURN OFF THE POWER.$"

gText_HOFCorrupted:: @ 85E8BDC
	.string "The HALL OF FAME data is corrupted.$"

gText_HOFNumber:: @ 85E8C00
	.string "HALL OF FAME No. {STR_VAR_1}$"

gText_LeagueChamp:: @ 85E8C14
	.string "LEAGUE CHAMPION!\nCONGRATULATIONS!$"

gText_Number:: @ 85E8C36
	.string "No. $"

gText_Level:: @ 85E8C3B
	.string "Lv. $"
	.string "IDNo. /$"

gText_Name:: @ 85E8C48
	.string "NAME$"

gText_IDNumber:: @ 85E8C4D
	.string "IDNo.$"

gText_BirchInTrouble:: @ 85E8C53
	.string "PROF. BIRCH is in trouble!\nRelease a POKéMON and rescue him!$"

gText_ConfirmStarterChoice:: @ 85E8C90
	.string "Do you choose this POKéMON?$"
	.string "POKéMON$"

gText_FlyToWhere:: @ 85E8CB4
	.string "FLY to where?$"
	.string "USE$"
	.string "TOSS$"
	.string "REGISTER$"
	.string "GIVE$"
	.string "CHECK TAG$"

gText_Confirm:: @ 85E8CE3
	.string "CONFIRM$"
	.string "WALK$"

gText_Cancel:: @ 85E8CF0
	.string "CANCEL$"

gText_Cancel2:: @ 85E8CF7
	.string "CANCEL$"
	.string "SHOW$"

gText_EmptyString2:: @ 85E8D03
	.string "$"
	.string "CANCEL$"
	.string "ITEM$"
	.string "MAIL$"
	.string "TAKE$"
	.string "STORE$"
	.string "CHECK$"

gText_None:: @ 85E8D26
	.string "NONE$"
	.string "DESELECT$"

gText_ThreeMarks:: @ 85E8D34
	.string "???$"

gText_FiveMarks:: @ 85E8D38
	.string "?????$"

gText_Slash:: @ 85E8D3E
	.string "/$"

gText_OneDash:: @ 85E8D40
	.string "-$"

gText_TwoDashes:: @ 85E8D42
	.string "--$"

gText_ThreeDashes:: @ 85E8D45
	.string "---$"

gText_MaleSymbol:: @ 85E8D49
	.string "♂$"

gText_FemaleSymbol:: @ 85E8D4B
	.string "♀$"

gText_LevelSymbol:: @ 85E8D4D
	.string "{LV}$"

gText_UnkCtrlF908Clear01:: @ 85E8D4F
	.string "{UNK_CTRL_F908}{CLEAR 0x01}$"
	.string "+$"
	.string "{RIGHT_ARROW}$"

gText_UnkCtrlF907F908:: @ 85E8D59
	.string "{UNK_CTRL_F907}{UNK_CTRL_F908}$"

gText_Space:: @ 85E8D5E
	.string " $"

gText_SelectorArrow2:: @ 85E8D60
	.string "▶$"

gText_GoBackPrevMenu:: @ 85E8D62
	.string "Go back to the\nprevious menu.$"

gText_WhatWouldYouLike:: @ 85E8D80
	.string "What would you like to do?$"
	.string "GIVE$"

gText_xVar1:: @ 85E8DA0
	.string "×{STR_VAR_1}$"
	.string " BERRY$"

gText_Coins:: @ 85E8DAB
	.string "{STR_VAR_1} COINS$"

gText_CloseBag:: @ 85E8DB4
	.string "CLOSE BAG$"

gText_Var1IsSelected:: @ 85E8DBE
	.string "{STR_VAR_1} is\nselected.$"

gText_CantWriteMail:: @ 85E8DCE
	.string "You can’t write\nMAIL here.$"

gText_NoPokemon:: @ 85E8DE9
	.string "There is no\nPOKéMON.$"

gText_MoveVar1Where:: @ 85E8DFE
	.string "Move the\n{STR_VAR_1}\nwhere?$"

gText_Var1CantBeHeld:: @ 85E8E11
	.string "The {STR_VAR_1} can’t be held.$"

gText_Var1CantBeHeldHere:: @ 85E8E27
	.string "The {STR_VAR_1} can’t be held\nhere.$"

gText_DepositHowManyVar1:: @ 85E8E42
	.string "Deposit how many\n{STR_VAR_1}(s)?$"

gText_DepositedVar2Var1s:: @ 85E8E5A
	.string "Deposited {STR_VAR_2}\n{STR_VAR_1}(s).$"

gText_NoRoomForItems:: @ 85E8E6E
	.string "There’s no room to\nstore items.$"

gText_CantStoreImportantItems:: @ 85E8E8E
	.string "Important items\ncan’t be stored in\nthe PC!$"

gText_TooImportantToToss:: @ 85E8EB9
	.string "That’s much too\nimportant to toss\nout!$"

gText_TossHowManyVar1s:: @ 85E8EE0
	.string "Toss out how many\n{STR_VAR_1}(s)?$"

gText_ThrewAwayVar2Var1s:: @ 85E8EF9
	.string "Threw away {STR_VAR_2}\n{STR_VAR_1}(s).$"

gText_ConfirmTossItems:: @ 85E8F0E
	.string "Is it okay to\nthrow away {STR_VAR_2}\n{STR_VAR_1}(s)?$"

gText_DadsAdvice:: @ 85E8F31
	.string "DAD’s advice…\n{PLAYER}, there’s a time and place for\leverything!{PAUSE_UNTIL_PRESS}$"

gText_CantDismountBike:: @ 85E8F6E
	.string "You can’t dismount your BIKE here.{PAUSE_UNTIL_PRESS}$"

gText_ItemFinderNearby:: @ 85E8F93
	.string "Huh?\nThe ITEMFINDER’s responding!\pThere’s an item buried around here!{PAUSE_UNTIL_PRESS}$"

gText_ItemFinderOnTop:: @ 85E8FDB
	.string "Oh!\nThe ITEMFINDER’s shaking wildly!{PAUSE_UNTIL_PRESS}$"

gText_ItemFinderNothing:: @ 85E9002
	.string "… … … …Nope!\nThere’s no response.{PAUSE_UNTIL_PRESS}$"

gText_CoinCase:: @ 85E9026
	.string "Your COINS:\n{STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gText_BootedUpTM:: @ 85E9037
	.string "Booted up a TM.$"

gText_BootedUpHM:: @ 85E9047
	.string "Booted up an HM.$"

gText_TMHMContainedVar1:: @ 85E9058
	.string "It contained\n{STR_VAR_1}.\pTeach {STR_VAR_1}\nto a POKéMON?$"

gText_PlayerUsedVar2:: @ 85E9080
	.string "{PLAYER} used the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gText_RepelEffectsLingered:: @ 85E9092
	.string "But the effects of a REPEL\nlingered from earlier.{PAUSE_UNTIL_PRESS}$"

gText_UsedVar2WildLured:: @ 85E90C6
	.string "{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be lured.{PAUSE_UNTIL_PRESS}$"

gText_UsedVar2WildRepelled:: @ 85E90F4
	.string "{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be repelled.{PAUSE_UNTIL_PRESS}$"

gText_BoxFull:: @ 85E9125
	.string "The BOX is full.{PAUSE_UNTIL_PRESS}$"

gText_PowderQty:: @ 85E9138
	.string "POWDER QTY: {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gText_TheField:: @ 85E9149
	.string "the field$"

gText_TheBattle:: @ 85E9153
	.string "the battle$"

gText_ThePokemonList:: @ 85E915E
	.string "the POKéMON LIST$"

gText_TheShop:: @ 85E916F
	.string "the shop$"

gText_ThePC:: @ 85E9178
	.string "the PC$"

	.align 2
gReturnToXStringsTable:: @ 85E9180
	.4byte gText_TheField
	.4byte gText_TheBattle
	.4byte gText_ThePokemonList
	.4byte gText_TheShop
	.4byte gText_TheField
	.4byte gText_TheField
	.4byte gText_ThePC
	.4byte gText_TheField
	.4byte gText_TheField
	.4byte gText_TheField
	.4byte gText_TheBattle
	.4byte gText_ThePC

	.align 2
gReturnToXStringsTable2:: @ 85E91B0
	.4byte gText_TheField
	.4byte gText_TheBattle
	.4byte gText_ThePokemonList
	.4byte gText_TheField

	.align 2
gText_ReturnToVar1:: @ 85E91C0
	.string "Return to\n{STR_VAR_1}.$"

gText_ItemsPocket:: @ 85E91CE
	.string "ITEMS$"

gText_PokeBallsPocket:: @ 85E91D4
	.string "POKé BALLS$"

gText_TMHMPocket:: @ 85E91DF
	.string "TMs & HMs$"

gText_BerriesPocket:: @ 85E91E9
	.string "BERRIES$"

gText_KeyItemsPocket:: @ 85E91F1
	.string "KEY ITEMS$"

	.align 2
gPocketNamesStringsTable:: @ 85E91FC
	.4byte gText_ItemsPocket
	.4byte gText_PokeBallsPocket
	.4byte gText_TMHMPocket
	.4byte gText_BerriesPocket
	.4byte gText_KeyItemsPocket

	.align 2
gText_UnkF908Var1Clear7Var2:: @ 85E9210
	.string "{UNK_CTRL_F908}{STR_VAR_1}{CLEAR 0x07}{STR_VAR_2}$"

gText_ClearTo11Var1Clear5Var2:: @ 85E921A
	.string "{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}$"

gText_SizeSlash:: @ 85E9225
	.string "SIZE /$"

gText_FirmSlash:: @ 85E922C
	.string "FIRM /$"

gText_Var1DotVar2:: @ 85E9233
	.string "{STR_VAR_1}.{STR_VAR_2}”$"


	.include "data/text/berry_firmness_strings.inc"

gText_UnkF908Var1Var2:: @ 85E9263
	.string "{UNK_CTRL_F908}{STR_VAR_1} {STR_VAR_2}$"

gText_BerryTag:: @ 85E926B
	.string "BERRY TAG$"

	.string "RED {POKEBLOCK}$"
	.string "BLUE {POKEBLOCK}$"
	.string "PINK {POKEBLOCK}$"
	.string "GREEN {POKEBLOCK}$"
	.string "YELLOW {POKEBLOCK}$"
	.string "PURPLE {POKEBLOCK}$"
	.string "INDIGO {POKEBLOCK}$"
	.string "BROWN {POKEBLOCK}$"
	.string "LITEBLUE {POKEBLOCK}$"
	.string "OLIVE {POKEBLOCK}$"
	.string "GRAY {POKEBLOCK}$"
	.string "BLACK {POKEBLOCK}$"
	.string "WHITE {POKEBLOCK}$"
	.string "GOLD {POKEBLOCK}$"

gText_Spicy:: @ 85E931D
	.string "SPICY$"

gText_Dry:: @ 85E9323
	.string "DRY$"

gText_Sweet:: @ 85E9327
	.string "SWEET$"

gText_Bitter:: @ 85E932D
	.string "BITTER$"

gText_Sour:: @ 85E9334
	.string "SOUR$"

	.string "TASTY$"
	.string "FEEL$"

gText_StowCase:: @ 85E9344
	.string "Stow CASE.$"

gText_LvVar1:: @ 85E934F
	.string "{LV}{STR_VAR_1}$"

gText_ThrowAwayVar1:: @ 85E9353
	.string "Throw away this\n{STR_VAR_1}?$"

gText_Var1ThrownAway:: @ 85E9367
	.string "The {STR_VAR_1}\nwas thrown away.$"

gText_Var1AteTheVar2:: @ 85E937F
	.string "{STR_VAR_1} ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gText_Var1HappilyAteVar2:: @ 85E9390
	.string "{STR_VAR_1} happily ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gText_Var1DisdainfullyAteVar2:: @ 85E93A9
	.string "{STR_VAR_1} disdainfully ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

	.string "BUY$"
	.string "SELL$"
	.string "QUIT$"

gText_InBagVar1:: @ 85E93D5
	.string "IN BAG: {STR_VAR_1}$"

gText_QuitShopping:: @ 85E93E0
	.string "Quit shopping.$"

gText_Var1CertainlyHowMany:: @ 85E93EF
	.string "{STR_VAR_1}? Certainly.\nHow many would you like?$"

gText_Var1CertainlyHowMany2:: @ 85E9417
	.string "{STR_VAR_1}? Certainly.\nHow many would you like?$"

gText_Var1AndYouWantedVar2:: @ 85E943F
	.string "{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be ¥{STR_VAR_3}.$"

gText_Var1IsItThatllBeVar2:: @ 85E9468
	.string "{STR_VAR_1}, is it?\nThat’ll be ¥{STR_VAR_2}. Do you want it?$"

gText_YouWantedVar1ThatllBeVar2:: @ 85E9493
	.string "You wanted {STR_VAR_1}?\nThat’ll be ¥{STR_VAR_2}. Will that be okay?$"

gText_HereYouGoThankYou:: @ 85E94C5
	.string "Here you go!\nThank you very much.$"

gText_ThankYouIllSendItHome:: @ 85E94E7
	.string "Thank you!\nI’ll send it to your home PC.$"

gText_ThanksIllSendItHome:: @ 85E9510
	.string "Thanks!\nI’ll send it to your PC at home.$"

gText_YouDontHaveMoney:: @ 85E9539
	.string "You don’t have enough money.{PAUSE_UNTIL_PRESS}$"

gText_NoMoreRoomForThis:: @ 85E9558
	.string "You have no more room for this\nitem.{PAUSE_UNTIL_PRESS}$"

gText_SpaceForVar1Full:: @ 85E957F
	.string "The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}$"

gText_AnythingElseICanHelp:: @ 85E959B
	.string "Is there anything else I can help\nyou with?$"

gText_CanIHelpWithAnythingElse:: @ 85E95C7
	.string "Can I help you with anything else?$"

gText_ThrowInPremierBall:: @ 85E95EA
	.string "I’ll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}$"

gText_CantBuyKeyItem:: @ 85E960F
	.string "{STR_VAR_2}? Oh, no.\nI can’t buy that.{PAUSE_UNTIL_PRESS}$"

gText_HowManyToSell:: @ 85E962F
	.string "{STR_VAR_2}?\nHow many would you like to sell?$"

gText_ICanPayVar1:: @ 85E9654
	.string "I can pay ¥{STR_VAR_1}.\nWould that be okay?$"

gText_TurnedOverVar1ForVar2:: @ 85E9677
	.string "Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}.$"

gText_PokedollarVar1:: @ 85E969C
	.string "¥{STR_VAR_1}$"

	.string "SHIFT$"
	.string "SEND OUT$"
	.string "SWITCH$"
	.string "SUMMARY$"
	.string "MOVES$"
	.string "ENTER$"
	.string "NO ENTRY$"
	.string "TAKE$"
	.string "READ$"
	.string "TRADE$"

gText_HP3:: @ 85E96E3
	.string "HP$"

gText_SpAtk3:: @ 85E96E6
	.string "SP. ATK$"

gText_SpDef3:: @ 85E96EE
	.string "SP. DEF$"

gText_WontHaveEffect:: @ 85E96F6
	.string "It won’t have any effect.{PAUSE_UNTIL_PRESS}$"

gText_CantBeUsedOnPkmn:: @ 85E9712
	.string "This can’t be used on\nthat POKéMON.{PAUSE_UNTIL_PRESS}$"

gText_PkmnCantSwitchOut:: @ 85E9738
	.string "{STR_VAR_1} can’t be switched\nout!{PAUSE_UNTIL_PRESS}$"

gText_PkmnAlreadyInBattle:: @ 85E9754
	.string "{STR_VAR_1} is already\nin battle!{PAUSE_UNTIL_PRESS}$"

gText_PkmnAlreadySelected:: @ 85E976F
	.string "{STR_VAR_1} has already been\nselected.{PAUSE_UNTIL_PRESS}$"

gText_PkmnHasNoEnergy:: @ 85E978F
	.string "{STR_VAR_1} has no energy\nleft to battle!{PAUSE_UNTIL_PRESS}$"

gText_CantSwitchWithAlly:: @ 85E97B2
	.string "You can’t switch {STR_VAR_1}’s\nPOKéMON with one of yours!{PAUSE_UNTIL_PRESS}$"

gText_EggCantBattle:: @ 85E97E5
	.string "An EGG can’t battle!{PAUSE_UNTIL_PRESS}$"

gText_CantUseUntilNewBadge:: @ 85E97FC
	.string "This can’t be used until a new\nBADGE is obtained.{PAUSE_UNTIL_PRESS}$"

gText_NoMoreThanVar1Pkmn:: @ 85E9830
	.string "No more than {STR_VAR_1} POKéMON\nmay enter.{PAUSE_UNTIL_PRESS}$"

gText_SendMailToPC:: @ 85E9855
	.string "Send the removed MAIL to\nyour PC?$"

gText_MailSentToPC:: @ 85E9877
	.string "The MAIL was sent to your PC.{PAUSE_UNTIL_PRESS}$"

gText_PCMailboxFull:: @ 85E9897
	.string "Your PC’s MAILBOX is full.{PAUSE_UNTIL_PRESS}$"

gText_MailMessageWillBeLost:: @ 85E98B4
	.string "If the MAIL is removed, the\nmessage will be lost. Okay?$"

gText_RemoveMailBeforeItem:: @ 85E98EC
	.string "MAIL must be removed before\nholding an item.{PAUSE_UNTIL_PRESS}$"

gText_PkmnWasGivenItem:: @ 85E991B
	.string "{STR_VAR_1} was given the\n{STR_VAR_2} to hold.{PAUSE_UNTIL_PRESS}$"

gText_SwitchPkmnItem:: @ 85E993A
	.string "{STR_VAR_1} is already holding\none {STR_VAR_2}.\pWould you like to switch the\ntwo items?$"

gText_PkmnNotHolding:: @ 85E9980
	.string "{STR_VAR_1} isn’t holding\nanything.{PAUSE_UNTIL_PRESS}$"

gText_RecievedItemFromPkmn:: @ 85E999D
	.string "Received the {STR_VAR_2}\nfrom {STR_VAR_1}.{PAUSE_UNTIL_PRESS}$"

gText_MailTakenFromPkmn:: @ 85E99B8
	.string "MAIL was taken from the\nPOKéMON.{PAUSE_UNTIL_PRESS}$"

gText_SwitchedPkmnItem:: @ 85E99DB
	.string "The {STR_VAR_2} was taken and\nreplaced with the {STR_VAR_1}.{PAUSE_UNTIL_PRESS}$"

gText_PkmnHoldingItemCantHoldMail:: @ 85E9A08
	.string "This POKéMON is holding an\nitem. It cannot hold MAIL.{PAUSE_UNTIL_PRESS}$"

gText_MailTransferredFromMailbox:: @ 85E9A40
	.string "MAIL was transferred from\nthe MAILBOX.{PAUSE_UNTIL_PRESS}$"

gText_BagFullCouldNotRemoveItem:: @ 85E9A69
	.string "The BAG is full. The POKéMON’s\nitem could not be removed.{PAUSE_UNTIL_PRESS}$"

gText_PkmnLearnedMove3:: @ 85E9AA5
	.string "{STR_VAR_1} learned\n{STR_VAR_2}!$"

gText_PkmnCantLearnMove:: @ 85E9AB4
	.string "{STR_VAR_1} and {STR_VAR_2}\nare not compatible.\p{STR_VAR_2} can’t be\nlearned.{PAUSE_UNTIL_PRESS}$"

gText_PkmnNeedsToReplaceMove:: @ 85E9AE9
	.string "{STR_VAR_1} wants to learn the\nmove {STR_VAR_2}.\pHowever, {STR_VAR_1} already\nknows four moves.\pShould a move be deleted and\nreplaced with {STR_VAR_2}?$"

gText_StopLearningMove2:: @ 85E9B5D
	.string "Stop trying to teach\n{STR_VAR_2}?$"

gText_MoveNotLearned:: @ 85E9B76
	.string "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gText_WhichMoveToForget:: @ 85E9B96
	.string "Which move should be forgotten?{PAUSE_UNTIL_PRESS}$"

gText_12PoofForgotMove:: @ 85E9BB8
	.string "1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p{STR_VAR_1} forgot how to\nuse {STR_VAR_2}.\pAnd…{PAUSE_UNTIL_PRESS}$"

gText_PkmnAlreadyKnows:: @ 85E9C00
	.string "{STR_VAR_1} already knows\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gText_PkmnHPRestoredByVar2:: @ 85E9C17
	.string "{STR_VAR_1}’s HP was restored\nby {STR_VAR_2} point(s).{PAUSE_UNTIL_PRESS}$"

gText_PkmnCuredOfPoison:: @ 85E9C3E
	.string "{STR_VAR_1} was cured of its\npoisoning.{PAUSE_UNTIL_PRESS}$"

gText_PkmnCuredOfParalysis:: @ 85E9C5F
	.string "{STR_VAR_1} was cured of\nparalysis.{PAUSE_UNTIL_PRESS}$"

gText_PkmnWokeUp2:: @ 85E9C7C
	.string "{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}$"

gText_PkmnBurnHealed:: @ 85E9C8A
	.string "{STR_VAR_1}’s burn was healed.{PAUSE_UNTIL_PRESS}$"

gText_PkmnThawedOut:: @ 85E9CA2
	.string "{STR_VAR_1} was thawed out.{PAUSE_UNTIL_PRESS}$"

gText_PPWasRestored:: @ 85E9CB7
	.string "PP was restored.{PAUSE_UNTIL_PRESS}$"

	.string "{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}$"

gText_PkmnBecameHealthy:: @ 85E9CE0
	.string "{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}$"

gText_MovesPPIncreased:: @ 85E9CF5
	.string "{STR_VAR_1}’s PP increased.{PAUSE_UNTIL_PRESS}$"

gText_PkmnElevatedToLvVar2:: @ 85E9D0A
	.string "{STR_VAR_1} was elevated to\nLv. {STR_VAR_2}.$"

gText_PkmnBaseVar2StatIncreased:: @ 85E9D25
	.string "{STR_VAR_1}’s base {STR_VAR_2}\nstat was raised.{PAUSE_UNTIL_PRESS}$"

gText_PkmnFriendlyBaseVar2Fell:: @ 85E9D45
	.string "{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}$"

gText_PkmnAdoresBaseVar2Fell:: @ 85E9D6D
	.string "{STR_VAR_1} adores you!\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}$"

gText_PkmnFriendlyBaseVar2CantFall:: @ 85E9D90
	.string "{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} can’t fall!{PAUSE_UNTIL_PRESS}$"

gText_PkmnSnappedOutOfConfusion:: @ 85E9DBE
	.string "{STR_VAR_1} snapped out of its\nconfusion.{PAUSE_UNTIL_PRESS}$"

gText_PkmnGotOverInfatuation:: @ 85E9DE1
	.string "{STR_VAR_1} got over its\ninfatuation.{PAUSE_UNTIL_PRESS}$"

gText_ThrowAwayItem:: @ 85E9E00
	.string "Throw away this\n{STR_VAR_1}?$"

gText_ItemThrownAway:: @ 85E9E14
	.string "The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}$"

	.string "Teach which POKéMON?$"
	.string "Choose a POKéMON.$"
	.string "Move to where?$"
	.string "Teach which POKéMON?$"
	.string "Use on which POKéMON?$"
	.string "Give to which POKéMON?$"
	.string "Do what with this {PKMN}?$"
	.string "There’s nothing to CUT.$"
	.string "You can’t SURF here.$"
	.string "You’re already SURFING.$"
	.string "Can’t use that here.$"
	.string "Restore which move?$"
	.string "Boost PP of which move?$"
	.string "Do what with an item?$"
	.string "No POKéMON for battle!$"
	.string "Choose a POKéMON.$"
	.string "Not enough HP…$"
	.string "{STR_VAR_1} POKéMON are needed.$"
	.string "POKéMON can’t be the same.$"
	.string "No identical hold items.$"
	.string "The current is much too fast!$"
	.string "Do what with the MAIL?$"
	.string "Choose POKéMON or CANCEL.$"
	.string "Choose POKéMON and confirm.$"
	.string "Let’s enjoy cycling!$"
	.string "This is in use already.$"
	.string "{STR_VAR_1} is already holding\none {STR_VAR_2}.$"
	.string "No use.$"
	.string "ABLE$"
	.string "FIRST$"
	.string "SECOND$"
	.string "THIRD$"
	.string "ABLE$"
	.string "NOT ABLE$"
	.string "ABLE!$"
	.string "NOT ABLE!$"
	.string "LEARNED$"
	.string "HAVE$"
	.string "DON’T HAVE$"
	.string "FOURTH$"

gText_PkmnCantParticipate:: @ 85EA0EE
	.string "That POKéMON can’t participate.{PAUSE_UNTIL_PRESS}$"

gText_CancelParticipation:: @ 85EA110
	.string "Cancel participation?$"

gText_CancelBattle:: @ 85EA126
	.string "Cancel the battle?$"

gText_ReturnToWaitingRoom:: @ 85EA139
	.string "Return to the WAITING ROOM?$"

gText_CancelChallenge:: @ 85EA155
	.string "Cancel the challenge?$"

gText_EscapeFromHere:: @ 85EA16B
	.string "Want to escape from here and return\nto {STR_VAR_1}?$"

gText_ReturnToHealingSpot:: @ 85EA196
	.string "Want to return to the healing spot\nused last in {STR_VAR_1}?$"

gText_PauseUntilPress:: @ 85EA1CA
	.string "{PAUSE_UNTIL_PRESS}$"

gJPText_PutVar1IntoSpinner:: @ 85EA1CD
    .string "{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？$" @ "{STR_VAR_1}wo gurugurukoukanni\ndashite yoroshiidesuka?" ("do you want to put {STR_VAR_1} into the spinner?" in Japanese)

    .align 2
gText_OnlyPkmnForBattle:: @ 85EA1E8
	.string "That’s your only\nPOKéMON for battle.$"

    .align 2
gText_PkmnCantBeTradedNow:: @ 85EA210
	.string "That POKéMON can’t be traded\nnow.$"

    .align 2
gText_EggCantBeTradedNow:: @ 85EA234
    .string "An EGG can’t be traded now.$"
    
    .align 2
    .string "The other TRAINER’s POKéMON\ncan’t be traded now.$"
    
    .align 2
    .string "The other TRAINER can’t accept\nthat POKéMON now.$"
    
    .align 2
    .string "You can’t trade with that\nTRAINER now.$"
    
    .align 2
    .string "That isn’t the type of POKéMON\nthat the other TRAINER wants.$"
    
    .align 2
    .string "That isn’t an EGG.$"

gText_Register:: @ 85EA333
	.string "REGISTER$"

gText_Attack3:: @ 85EA33C
	.string "ATTACK$"

gText_Defense3:: @ 85EA343
	.string "DEFENSE$"

gText_SpAtk4:: @ 85EA34B
	.string "SP. ATK$"

gText_SpDef4:: @ 85EA353
	.string "SP. DEF$"

gText_Speed2:: @ 85EA35B
	.string "SPEED$"

gText_HP4:: @ 85EA361
	.string "HP$"

	.string "$"

gText_OTSlash:: @ 85EA365
	.string "OT/$"

gText_RentalPkmn:: @ 85EA369
	.string "RENTAL POKéMON$"

gText_TypeSlash:: @ 85EA378
	.string "TYPE/$"

gText_Power:: @ 85EA37E
	.string "POWER$"

gText_Accuracy2:: @ 85EA384
	.string "ACCURACY$"

gText_Appeal:: @ 85EA38D
	.string "APPEAL$"

gText_Jam:: @ 85EA394
	.string "JAM$"

gText_Status:: @ 85EA398
	.string "STATUS$"

gText_ExpPoints:: @ 85EA39F
	.string "EXP. POINTS$"

gText_NextLv:: @ 85EA3AB
	.string "NEXT LV.$"

gText_RibbonsVar1:: @ 85EA3B4
	.string "RIBBONS: {STR_VAR_1}$"

gText_EmptyString5:: @ 85EA3C0
	.string "$"

	.string "EVENTS$"

gText_Switch:: @ 85EA3C8
	.string "SWITCH$"

gText_PkmnInfo:: @ 85EA3CF
	.string "POKéMON INFO$"

gText_PkmnSkills:: @ 85EA3DC
	.string "POKéMON SKILLS$"

gText_BattleMoves:: @ 85EA3EB
	.string "BATTLE MOVES$"

gText_ContestMoves:: @ 85EA3F8
	.string "C0NTEST MOVES$"

gText_Info:: @ 85EA406
	.string "INFO$"

gText_EggWillTakeALongTime:: @ 85EA40B
	.string "It looks like this EGG will\ntake a long time to hatch.$"

gText_EggWillTakeSomeTime:: @ 85EA442
	.string "What will hatch from this?\nIt will take some time.$"

gText_EggWillHatchSoon:: @ 85EA475
	.string "It moves occasionally.\nIt should hatch soon.$"

gText_EggAboutToHatch:: @ 85EA4A2
	.string "It’s making sounds.\nIt’s about to hatch!$"

gText_HMMovesCantBeForgotten2:: @ 85EA4CB
	.string "HM moves can’t be\nforgotten now.$"

gText_XNatureMetAtYZ:: @ 85EA4EC
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nmet at {UNK_CTRL_F905}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01},\n{SPECIAL_F7 0x00}{SPECIAL_F7 0x04}{SPECIAL_F7 0x01}.$"

gText_XNatureHatchedAtYZ:: @ 85EA516
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nhatched at {UNK_CTRL_F905}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01},\n{SPECIAL_F7 0x00}{SPECIAL_F7 0x04}{SPECIAL_F7 0x01}.$"

gText_XNatureObtainedInTrade:: @ 85EA544
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nobtained in a trade.$"

gText_XNatureFatefulEncounter:: @ 85EA56A
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nobtained in a fateful\nencounter at {UNK_CTRL_F905}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01}.$"

gText_XNatureProbablyMetAt:: @ 85EA5A8
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nprobably met at {UNK_CTRL_F905}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01},\n{SPECIAL_F7 0x00}{SPECIAL_F7 0x04}{SPECIAL_F7 0x01}.$"

gText_XNature:: @ 85EA5DB
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature$"

gText_XNatureMetSomewhereAt:: @ 85EA5EB
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nmet somewhere at {UNK_CTRL_F905}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01}.$"

gText_XNatureHatchedSomewhereAt:: @ 85EA617
	.string "{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nhatched somewhere at {UNK_CTRL_F905}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01}.$"

gText_OddEggFoundByCouple:: @ 85EA647
	.string "An odd POKéMON EGG found\nby the DAY CARE couple.$"

gText_PeculiarEggNicePlace:: @ 85EA678
	.string "A peculiar POKéMON EGG\nobtained at the nice place.$"

gText_PeculiarEggTrade:: @ 85EA6AB
	.string "A peculiar POKéMON EGG\nobtained in a trade.$"

gText_EggFromHotSprings:: @ 85EA6D7
	.string "A POKéMON EGG obtained\nat the hot springs.$"

gText_EggFromTraveler:: @ 85EA702
	.string "An odd POKéMON EGG\nobtained from a traveler.$"

gText_ApostropheSBase:: @ 85EA72F
	.string "’s BASE$"

gText_OkayToDeleteFromRegistry:: @ 85EA737
	.string "Is it okay to delete {STR_VAR_1}\nfrom the REGISTRY?$"

gText_RegisteredDataDeleted:: @ 85EA762
	.string "The registered data was deleted.{PAUSE_UNTIL_PRESS}$"

gText_NoRegistry:: @ 85EA785
	.string "There is no REGISTRY.{PAUSE_UNTIL_PRESS}$"

	.string "DEL REGIST.$"
	.string "{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}$"
	.string "DECORATE$"
	.string "PUT AWAY$"
	.string "TOSS$"

gText_Color161Shadow161:: @ 85EA7C8
	.string "{COLOR 161}{SHADOW 161}$"

	.string "Put out the selected decoration item.$"
	.string "Store the chosen decoration in the PC.$"
	.string "Throw away unwanted decorations.$"

gText_NoDecorations:: @ 85EA83D
	.string "There are no decorations.{PAUSE_UNTIL_PRESS}$"

	.string "DESK$"
	.string "CHAIR$"
	.string "PLANT$"
	.string "ORNAMENT$"
	.string "MAT$"
	.string "POSTER$"
	.string "DOLL$"
	.string "CUSHION$"

gText_Gold:: @ 85EA88B
	.string "GOLD$"

gText_Silver:: @ 85EA890
	.string "SILVER$"

gText_PlaceItHere:: @ 85EA897
	.string "Place it here?$"

gText_CantBePlacedHere:: @ 85EA8A6
	.string "It can’t be placed here.$"

gText_CancelDecorating:: @ 85EA8BF
	.string "Cancel decorating?$"

gText_InUseAlready:: @ 85EA8D2
	.string "This is in use already.$"

gText_NoMoreDecorations:: @ 85EA8EA
	.string "No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.$"

gText_NoMoreDecorations2:: @ 85EA931
	.string "No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.$"

	.string "This can’t be placed here.\nIt must be on a DESK, etc.$"

gText_CantPlaceInRoom:: @ 85EA9AE
	.string "This decoration can’t be placed in\nyour own room.$"

gText_CantThrowAwayInUse:: @ 85EA9E0
	.string "This decoration is in use.\nIt can’t be thrown away.$"

gText_DecorationWillBeDiscarded:: @ 85EAA14
	.string "This {STR_VAR_1} will be discarded.\nIs that okay?$"

gText_DecorationThrownAway:: @ 85EAA3D
	.string "The decoration item was thrown away.$"

gText_StopPuttingAwayDecorations:: @ 85EAA62
	.string "Stop putting away decorations?$"

gText_NoDecorationHere:: @ 85EAA81
	.string "There is no decoration item here.$"

gText_ReturnDecorationToPC:: @ 85EAAA3
	.string "Return this decoration to the PC?$"

gText_DecorationReturnedToPC:: @ 85EAAC5
	.string "The decoration was returned to the PC.$"

gText_NoDecorationsInUse:: @ 85EAAEC
	.string "There are no decorations in use.{PAUSE_UNTIL_PRESS}$"

	.string "TRISTAN$"
	.string "PHILIP$"
	.string "DENNIS$"
	.string "ROBERTO$"
	.string "TURN OFF$"
	.string "DECORATION$"
	.string "ITEM STORAGE$"

gText_Mailbox:: @ 85EAB4E
	.string "MAILBOX$"

	.string "DEPOSIT ITEM$"

gText_WithdrawItem:: @ 85EAB63
	.string "WITHDRAW ITEM$"

gText_TossItem:: @ 85EAB71
	.string "TOSS ITEM$"

	.string "Store items in the PC.$"
	.string "Take out items from the PC.$"
	.string "Throw away items stored in the PC.$"

gText_NoItems:: @ 85EABD1
	.string "There are no items.{PAUSE_UNTIL_PRESS}$"

gText_NoRoomInBag:: @ 85EABE7
	.string "There is no more\nroom in the BAG.$"

gText_WithdrawHowManyItems:: @ 85EAC09
	.string "Withdraw how many\n{STR_VAR_1}(s)?$"

gText_WithdrawXItems:: @ 85EAC22
	.string "Withdrew {STR_VAR_2}\n{STR_VAR_1}(s).$"

	.string "READ$"
	.string "MOVE TO BAG$"
	.string "GIVE$"

gText_NoMailHere:: @ 85EAC4B
	.string "There’s no MAIL here.{PAUSE_UNTIL_PRESS}$"

gText_WhatToDoWithVar1sMail:: @ 85EAC63
	.string "What would you like to do with\n{STR_VAR_1}’s MAIL?$"

gText_MessageWillBeLost:: @ 85EAC8D
	.string "The message will be lost.\nIs that okay?$"

gText_BagIsFull:: @ 85EACB5
	.string "The BAG is full.{PAUSE_UNTIL_PRESS}$"

gText_MailToBagMessageErased:: @ 85EACC8
	.string "The MAIL was returned to the BAG\nwith its message erased.{PAUSE_UNTIL_PRESS}$"

gText_Dad:: @ 85EAD04
	.string "DAD$"

gText_Mom:: @ 85EAD08
	.string "MOM$"

gText_Wallace:: @ 85EAD0C
	.string "WALLACE$"

gText_Steven:: @ 85EAD14
	.string "STEVEN$"

gText_Brawly:: @ 85EAD1B
	.string "BRAWLY$"

gText_Winona:: @ 85EAD22
	.string "WINONA$"

gText_Phoebe:: @ 85EAD29
	.string "PHOEBE$"

gText_Glacia:: @ 85EAD30
	.string "GLACIA$"

	.string "PETALBURG$"
	.string "SLATEPORT$"
	.string "LITTLEROOT$"
	.string "LILYCOVE$"
	.string "DEWFORD$"
	.string "ENTER$"
	.string "INFO$"
	.string "What’s a CONTEST?$"
	.string "Types of CONTESTS$"
	.string "Ranks$"
	.string "Judging$"

gUnknown_085EADA4::
	.string "COOLNESS CONTEST$"

gUnknown_085EADB5::
	.string "BEAUTY CONTEST$"

gUnknown_085EADC4::
	.string "CUTENESS CONTEST$"

gUnknown_085EADD5::
	.string "SMARTNESS CONTEST$"

gUnknown_085EADE7::
	.string "TOUGHNESS CONTEST$"
	.string "DECORATION$"
	.string "PACK UP$"
	.string "COUNT$"
	.string "REGISTRY$"
	.string "INFORMATION$"
	.string "MACH$"
	.string "ACRO$"
	.string "PSN$"
	.string "PAR$"
	.string "SLP$"
	.string "BRN$"
	.string "FRZ$"
	.string "TOXIC$"
	.string "OK$"
	.string "QUIT$"
	.string "Saw it$"
	.string "Not yet$"

gText_Yes:: @ 85EAE62
	.string "YES$"

gText_No:: @ 85EAE66
	.string "NO$"

	.string "INFO$"
	.string "SINGLE BATTLE$"
	.string "DOUBLE BATTLE$"
	.string "MULTI BATTLE$"
	.string "MR. BRINEY$"
	.string "CHALLENGE$"
	.string "INFO$"

gText_Lv50:: @ 85EAEB1
	.string "LV. 50$"

gText_OpenLevel:: @ 85EAEB8
	.string "OPEN LEVEL$"

	.string "FRESH WATER{CLEAR_TO 0x48}¥200$"
	.string "SODA POP{CLEAR_TO 0x48}¥300$"
	.string "LEMONADE{CLEAR_TO 0x48}¥350$"
	.string "HOW TO RIDE$"
	.string "HOW TO TURN$"
	.string "SANDY SLOPES$"
	.string "WHEELIES$"
	.string "BUNNY-HOPS$"
	.string "JUMP$"
	.string "Satisfied$"
	.string "Dissatisfied$"
	.string "DEEPSEATOOTH$"
	.string "DEEPSEASCALE$"
	.string "BLUE FLUTE$"
	.string "YELLOW FLUTE$"
	.string "RED FLUTE$"
	.string "WHITE FLUTE$"
	.string "BLACK FLUTE$"
	.string "GLASS CHAIR$"
	.string "GLASS DESK$"
	.string "TREECKO DOLL 1,000 COINS$"
	.string "TORCHIC DOLL 1,000 COINS$"
	.string "MUDKIP DOLL   1,000 COINS$"
	.string "  50 COINS    ¥1,000$"
	.string "500 COINS  ¥10,000$"
	.string "Excellent$"
	.string "Not so good$"
	.string "RED SHARD$"
	.string "YELLOW SHARD$"
	.string "BLUE SHARD$"
	.string "GREEN SHARD$"
	.string "BATTLE FRONTIER$"
	.string "Right$"
	.string "Left$"
	.string "TM32{CLEAR_TO 0x48}1,500 COINS$"
	.string "TM29{CLEAR_TO 0x48}3,500 COINS$"
	.string "TM35{CLEAR_TO 0x48}4,000 COINS$"
	.string "TM24{CLEAR_TO 0x48}4,000 COINS$"
	.string "TM13{CLEAR_TO 0x48}4,000 COINS$"

gText_Cool:: @ 85EB0E8
	.string "COOL$"

gText_Beauty:: @ 85EB0ED
	.string "BEAUTY$"

gText_Cute:: @ 85EB0F4
	.string "CUTE$"

gText_Smart:: @ 85EB0F9
	.string "SMART$"

gText_Tough:: @ 85EB0FF
	.string "TOUGH$"

	.string "NORMAL$"
	.string "SUPER$"
	.string "HYPER$"
	.string "MASTER$"
	.string "COOL$"
	.string "BEAUTY$"
	.string "CUTE$"
	.string "SMART$"
	.string "TOUGH$"
	.string "ITEMS$"
	.string "KEY ITEMS$"
	.string "POKé BALLS$"
	.string "TMs & HMs$"
	.string "BERRIES$"

gText_SomeonesPC:: @ 85EB169
	.string "SOMEONE’S PC$"

gText_LanettesPC:: @ 85EB176
	.string "LANETTE’S PC$"

gText_PlayersPC:: @ 85EB183
	.string "{PLAYER}’s PC$"

gText_HallOfFame:: @ 85EB18B
	.string "HALL OF FAME$"

gText_LogOff:: @ 85EB198
	.string "LOG OFF$"

	.string "OPPONENT$"
	.string "TOURNEY TREE$"
	.string "READY TO START$"
	.string "NORMAL RANK$"
	.string "SUPER RANK$"
	.string "HYPER RANK$"
	.string "MASTER RANK$"
	.string "SINGLE$"
	.string "DOUBLE$"
	.string "MULTI$"
	.string "MULTI-LINK$"
	.string "BATTLE BAG$"
	.string "HELD ITEM$"
	.string "LINK CONTEST$"
	.string "ABOUT E-MODE$"
	.string "ABOUT G-MODE$"
	.string "E-MODE$"
	.string "G-MODE$"

gText_MenuOptionPokedex:: @ 85EB25C
	.string "POKéDEX$"

gText_MenuOptionPokemon:: @ 85EB264
	.string "POKéMON$"

gText_MenuOptionBag:: @ 85EB26C
	.string "BAG$"

gText_MenuOptionPokenav:: @ 85EB270
	.string "POKéNAV$"

	.string "$"

gText_MenuOptionSave:: @ 85EB279
	.string "SAVE$"

gText_MenuOptionOption:: @ 85EB27E
	.string "OPTION$"

gText_MenuOptionExit:: @ 85EB285
	.string "EXIT$"

	.align 2
	.string "5BP$"
	.string "10BP$"
	.string "15BP$"
	.string "RED TENT$"
	.string "BLUE TENT$"
	.string "SOUTHERN ISLAND$"
	.string "BIRTH ISLAND$"
	.string "FARAWAY ISLAND$"
	.string "NAVEL ROCK$"
	.string "CLAW FOSSIL$"
	.string "ROOT FOSSIL$"
	.string "NO$"
	.string "I’ll battle now!$"
	.string "I won!$"
	.string "I lost!$"
	.string "I won’t tell.$"
	.string "NORMAL TAG MATCH$"
	.string "VARIETY TAG MATCH$"
	.string "UNIQUE TAG MATCH$"
	.string "EXPERT TAG MATCH$"
	.string "TRADE CENTER$"
	.string "COLOSSEUM$"
	.string "RECORD CORNER$"
	.string "BERRY CRUSH$"
	.string "$"
	.string "POKéMON JUMP$"
	.string "DODRIO BERRY-PICKING$"
	.string "BECOME LEADER$"
	.string "JOIN GROUP$"
	.string "TWO STYLES$"
	.string "LV. 50$"
	.string "OPEN LEVEL$"
	.string "{PKMN} TYPE & NO.$"
	.string "HOLD ITEMS$"
	.string "SYMBOLS$"
	.string "RECORD$"
	.string "BATTLE PTS$"
	.string "TOWER INFO$"
	.string "BATTLE {PKMN}$"
	.string "BATTLE SALON$"
	.string "MULTI-LINK$"
	.string "BATTLE RULES$"
	.string "JUDGE: MIND$"
	.string "JUDGE: SKILL$"
	.string "JUDGE: BODY$"
	.string "MATCHUP$"
	.string "TOURNEY TREE$"
	.string "DOUBLE KO$"
	.string "BASIC RULES$"
	.string "SWAP: PARTNER$"
	.string "SWAP: NUMBER$"
	.string "SWAP: NOTES$"
	.string "OPEN LEVEL$"
	.string "BATTLE BASICS$"
	.string "POKéMON NATURE$"
	.string "POKéMON MOVES$"
	.string "UNDERPOWERED$"
	.string "WHEN IN DANGER$"
	.string "PYRAMID: POKéMON$"
	.string "PYRAMID: TRAINERS$"
	.string "PYRAMID: MAZE$"
	.string "BATTLE BAG$"
	.string "POKéNAV AND BAG$"
	.string "HELD ITEMS$"
	.string "POKéMON ORDER$"
	.string "BATTLE POKéMON$"
	.string "BATTLE TRAINERS$"
	.string "GO ON$"
	.string "RECORD$"
	.string "REST$"
	.string "RETIRE$"

gText_99TimesPlus:: @ 85EB5CF
	.string "99 times +$"

gText_1MinutePlus:: @ 85EB5DA
	.string "1 minute +$"

gText_SpaceSeconds:: @ 85EB5E5
	.string " seconds$"

gText_SpaceTimes:: @ 85EB5EE
	.string " time(s)$"

	.string ".$"

gText_BigGuy:: @ 85EB5F9
	.string "Big guy$"

gText_BigGirl:: @ 85EB601
	.string "Big girl$"

gText_Son:: @ 85EB60A
	.string "son$"

gText_Daughter:: @ 85EB60E
	.string "daughter$"

	.string "BLUE FLUTE$"
	.string "YELLOW FLUTE$"
	.string "RED FLUTE$"
	.string "WHITE FLUTE$"
	.string "BLACK FLUTE$"
	.string "PRETTY CHAIR$"
	.string "PRETTY DESK$"
	.string "1F$"
	.string "2F$"
	.string "3F$"
	.string "4F$"
	.string "5F$"
	.string "6F$"
	.string "7F$"
	.string "8F$"
	.string "9F$"
	.string "10F$"
	.string "11F$"
	.string "B1F$"
	.string "B2F$"
	.string "B3F$"
	.string "B4F$"
	.string "ROOFTOP$"

gText_ElevatorNowOn:: @ 85EB6A5
	.string "Now on:$"

gText_BP:: @ 85EB6AD
	.string "BP$"

	.string "ENERGYPOWDER{CLEAR_TO 0x72}{SIZE 0}50$"
	.string "ENERGY ROOT{CLEAR_TO 0x72}{SIZE 0}80$"
	.string "HEAL POWDER{CLEAR_TO 0x72}{SIZE 0}50$"
	.string "REVIVAL HERB{CLEAR_TO 0x6C}{SIZE 0}300$"
	.string "PROTEIN{CLEAR_TO 0x63}{SIZE 0}1,000$"
	.string "IRON{CLEAR_TO 0x63}{SIZE 0}1,000$"
	.string "CARBOS{CLEAR_TO 0x63}{SIZE 0}1,000$"
	.string "CALCIUM{CLEAR_TO 0x63}{SIZE 0}1,000$"
	.string "ZINC{CLEAR_TO 0x63}{SIZE 0}1,000$"
	.string "HP UP{CLEAR_TO 0x63}{SIZE 0}1,000$"
	.string "PP UP{CLEAR_TO 0x63}{SIZE 0}3,000$"
	.string "RANKING HALL$"
	.string "EXCHANGE SERVICE$"
	.string "LILYCOVE CITY$"
	.string "SLATEPORT CITY$"
	.string "CAVE OF ORIGIN$"
	.string "MT. PYRE$"
	.string "SKY PILLAR$"
	.string "Don’t remember$"

gText_Exit:: @ 85EB7EA
	.string "EXIT$"

	.string "Exit from the BOX?$"
	.string "What do you want to do?$"
	.string "Please pick a theme.$"
	.string "Pick the wallpaper.$"
	.string "{SPECIAL_F7 0x00} is selected.$"
	.string "Jump to which BOX?$"
	.string "Deposit in which BOX?$"
	.string "{SPECIAL_F7 0x00} was deposited.$"
	.string "The BOX is full.$"
	.string "Release this POKéMON?$"
	.string "{SPECIAL_F7 0x00} was released.$"
	.string "Bye-bye, {SPECIAL_F7 0x00}!$"
	.string "Mark your POKéMON.$"
	.string "That’s your last POKéMON!$"
	.string "Your party’s full!$"
	.string "You’re holding a POKéMON!$"
	.string "Which one will you take?$"
	.string "You can’t release an EGG.$"
	.string "Continue BOX operations?$"
	.string "{SPECIAL_F7 0x00} came back!$"
	.string "Was it worried about you?$"
	.string "… … … … !$"
	.string "Please remove the MAIL.$"
	.string "GIVE to a POKéMON?$"
	.string "Placed item in the BAG.$"
	.string "The BAG is full.$"
	.string "Put this item in the BAG?$"
	.string "{SPECIAL_F7 0x00} is now held.$"
	.string "Changed to {SPECIAL_F7 0x00}.$"
	.string "MAIL can’t be stored!$"
	.string "CANCEL$"
	.string "STORE$"
	.string "WITHDRAW$"
	.string "SHIFT$"
	.string "MOVE$"
	.string "PLACE$"
	.string "SUMMARY$"
	.string "RELEASE$"
	.string "MARK$"
	.string "NAME$"
	.string "JUMP$"
	.string "WALLPAPER$"
	.string "TAKE$"
	.string "GIVE$"
	.string "SWITCH$"
	.string "BAG$"
	.string "INFO$"
	.string "SCENERY 1$"
	.string "SCENERY 2$"
	.string "SCENERY 3$"
	.string "ETCETERA$"
	.string "FRIENDS$"
	.string "FOREST$"
	.string "CITY$"
	.string "DESERT$"
	.string "SAVANNA$"
	.string "CRAG$"
	.string "VOLCANO$"
	.string "SNOW$"
	.string "CAVE$"
	.string "BEACH$"
	.string "SEAFLOOR$"
	.string "RIVER$"
	.string "SKY$"
	.string "POLKA-DOT$"
	.string "POKéCENTER$"
	.string "MACHINE$"
	.string "SIMPLE$"
	.string "What would you like to do?$"
	.string "WITHDRAW POKéMON$"
	.string "DEPOSIT POKéMON$"
	.string "MOVE POKéMON$"
	.string "MOVE ITEMS$"
	.string "SEE YA!$"
	.string "Move POKéMON stored in BOXES to\nyour party.$"
	.string "Store POKéMON in your party in BOXES.$"
	.string "Organize the POKéMON in BOXES and\nin your party.$"
	.string "Move items held by any POKéMON\nin a BOX or your party.$"
	.string "Return to the previous menu.$"

gText_JustOnePkmn:: @ 85EBC89
	.string "There is just one POKéMON with you.$"

gText_PartyFull:: @ 85EBCAD
	.string "Your party is full!$"

gText_Box:: @ 85EBCC1
	.string "BOX$"

	.string "Check the map of the HOENN region.$"
	.string "Check POKéMON in detail.$"
	.string "Call a registered TRAINER.$"
	.string "Check obtained RIBBONS.$"
	.string "Put away the POKéNAV.$"

gText_NoRibbonWinners:: @ 85EBD4A
	.string "There are no RIBBON winners.$"

	.string "No TRAINERS are registered.$"
	.string "Check party POKéMON in detail.$"
	.string "Check all POKéMON in detail.$"
	.string "Return to the POKéNAV menu.$"
	.string "Find cool POKéMON.$"
	.string "Find beautiful POKéMON.$"
	.string "Find cute POKéMON.$"
	.string "Find smart POKéMON.$"
	.string "Find tough POKéMON.$"
	.string "Return to the CONDITION menu.$"

gText_NumberRegistered:: @ 85EBE5F
	.string "No. registered$"

gText_NumberOfBattles:: @ 85EBE6E
	.string "No. of battles$"

	.string "DETAIL$"
	.string "CALL$"
	.string "EXIT$"
	.string "Can’t call opponent here.$"
	.string "STRATEGY$"
	.string "TRAINER’S POKéMON$"
	.string "SELF-INTRODUCTION$"
	.string "{CLEAR 0x80}$"
	.string "{UNK_CTRL_F800}ZOOM {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}FULL {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}CONDITION {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}MARKINGS {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}SELECT MARK {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}MENU {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}OK {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}RIBBONS {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F800}CHECK {UNK_CTRL_F801}CANCEL$"
	.string "{UNK_CTRL_F801}CANCEL$"

gText_NatureSlash:: @ 85EBF8D
	.string "NATURE/$"

gText_TrainerCloseBy:: @ 85EBF95
	.string "That TRAINER is close by.\nTalk to the TRAINER in person!$"

gText_InParty:: @ 85EBFCE
	.string "IN PARTY$"

gText_Number2:: @ 85EBFD7
	.string "No. $"

	.string "RIBBONS$"
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}$"
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}$"
	.string "{SPECIAL_F7 0x00}/{LV}{SPECIAL_F7 0x01}$"

gText_Unknown:: @ 85EC00F
	.string "UNKNOWN$"

	.string "CALL$"
	.string "CHECK$"
	.string "CANCEL$"

gText_NumberF700:: @ 85EC029
	.string "No. {SPECIAL_F7 0x00}$"

gText_RibbonsF700:: @ 85EC030
	.string "RIBBONS {SPECIAL_F7 0x00}$"

	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}$"
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}$"
	.string "{SPECIAL_F7 0x00}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}$"
	.string "Combine four words or phrases$"
	.string "and make your profile.$"
	.string "Combine six words or phrases$"
	.string "and make a message.$"
	.string "Find words that describe your$"
	.string "feelings right now.$"
	.string "With four phrases,$"
	.string "Combine nine words or phrases$"
	.string "and make a message.$"
	.string "Change just one word or phrase$"
	.string "and improve the BARD’s song.$"
	.string "Your profile$"
	.string "Your feeling at the battle’s start$"
	.string "What you say if you win a battle$"
	.string "What you say if you lose a battle$"
	.string "The answer$"
	.string "The MAIL message$"
	.string "The MAIL salutation$"
	.string "The new song$"
	.string "Combine two words or phrases$"
	.string "and make a trendy saying.$"
	.string "The trendy saying$"
	.string "is as shown. Okay?$"
	.string "Combine two words or phrases$"
	.string "to teach her a good saying.$"
	.string "Find words which fit$"
	.string "the TRAINER’s image.$"
	.string "The image:$"
	.string "Out of the listed choices,$"
	.string "select the answer to the quiz!$"
	.string "and create a quiz!$"
	.string "Pick a word or phrase and$"
	.string "set the quiz answer.$"
	.string "The answer:$"
	.string "The quiz:$"
	.string "Apprentice’s phrase:$"

gText_QuitEditing:: @ 85EC3A6
	.string "Quit editing?$"

gText_StopGivingPkmnMail:: @ 85EC3B4
	.string "Stop giving the POKéMON MAIL?$"

	.string "and fill out the questionnaire.$"
	.string "Let’s reply to the interview!$"

gText_AllTextBeingEditedWill:: @ 85EC410
	.string "All the text being edited will$"

gText_BeDeletedThatOkay:: @ 85EC42F
	.string "be deleted. Is that okay?$"

	.string "Quit editing?$"
	.string "The edited text will not be saved.$"
	.string "Is that okay?$"
	.string "Please enter a phrase or word.$"
	.string "The entire text can’t be deleted.$"

gText_OnlyOnePhrase:: @ 85EC4C9
	.string "Only one phrase may be changed.$"

gText_OriginalSongWillBeUsed:: @ 85EC4E9
	.string "The original song will be used.$"

	.string "That’s trendy already!$"

gText_CombineTwoWordsOrPhrases:: @ 85EC520
	.string "Combine two words or phrases.$"

	.string "Quit giving information?$"
	.string "Stop giving the POKéMON MAIL?$"
	.string "Create a quiz!$"
	.string "Set the answer!$"
	.string "Cancel the selection?$"
	.string "PROFILE$"
	.string "At the battle’s start:$"
	.string "Upon winning a battle:$"
	.string "Upon losing a battle:$"
	.string "The BARD’s Song$"
	.string "What’s hip and happening?$"
	.string "Interview$"
	.string "Good saying$"
	.string "Fan’s question$"
	.string "クイズの こたえは？$" @ "kuizuno kotaeha?" ("The quiz's answer is?" in Japanese)
	.string "Apprentice’s phrase$"
	.string "QUESTIONNAIRE$"

gText_YouCannotQuitHere:: @ 85EC672
	.string "You cannot quit here.$"

gText_SectionMustBeCompleted:: @ 85EC688
	.string "This section must be completed.$"

gText_F700sQuiz:: @ 85EC6A8
	.string "{SPECIAL_F7 0x00}’s quiz$"

gText_Lady:: @ 85EC6B2
	.string "Lady$"

	.string "After you have read the quiz$"
	.string "question, press the A Button.$"
	.string "The quiz answer is?$"

gText_LikeToQuitQuiz:: @ 85EC706
	.string "Would you like to quit this quiz$"

gText_ChallengeQuestionMark:: @ 85EC727
	.string "challenge?$"

	.string "Is this quiz OK?$"

gText_CreateAQuiz:: @ 85EC743
	.string "Create a quiz!$"

gText_SelectTheAnswer:: @ 85EC752
	.string "Select the answer!$"

gText_LyricsCantBeDeleted:: @ 85EC765
	.string "The lyrics can’t be deleted.$"

	.string "POKéMON LEAGUE$"
	.string "POKéMON CENTER$"

gText_GetsAPokeBlockQuestion:: @ 85EC7A0
	.string " gets a {POKEBLOCK}?$"

	.string "Coolness $"
	.string "Beauty $"
	.string "Cuteness $"
	.string "Smartness $"
	.string "Toughness $"

gText_WasEnhanced:: @ 85EC7E1
	.string "was enhanced!$"

gText_NothingChanged:: @ 85EC7EF
	.string "Nothing changed!$"

gText_WontEatAnymore:: @ 85EC800
	.string "It won’t eat anymore…$"

gText_SaveFailedCheckingBackup:: @ 85EC816
	.string "Save failed. Checking the backup\nmemory… Please wait.\n{COLOR RED}“Time required: about 1 minute”$"

gText_BackupMemoryDamaged:: @ 85EC86F
	.string "The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save.$"

gText_GamePlayCannotBeContinued:: @ 85EC8D4
	.string "{COLOR RED}“Game play cannot be continued.\nReturning to the title screen…”$"

gText_CheckCompleted:: @ 85EC917
	.string "Check completed.\nAttempting to save again.\nPlease wait.$"

gText_SaveCompleteGameCannotContinue:: @ 85EC94F
	.string "Save completed.\n{COLOR RED}“Game play cannot be continued.\nReturning to the title screen.”$"

gText_SaveCompletePressA:: @ 85EC9A2
	.string "Save completed.\n{COLOR RED}“Please press the A Button.”$"

gText_Ferry:: @ 85EC9D2
	.string "FERRY$"

gText_SecretBase:: @ 85EC9D8
	.string "SECRET BASE$"

gText_Hideout:: @ 85EC9E4
	.string "HIDEOUT$"

gText_ResetRTCConfirmCancel:: @ 85EC9EC
	.string "Reset RTC?\nA: Confirm, B: Cancel$"

gText_PresentTime:: @ 85ECA0D
	.string "Present time in game$"

gText_PreviousTime:: @ 85ECA22
	.string "Previous time in game$"

gText_PleaseResetTime:: @ 85ECA38
	.string "Please reset the time.$"

gText_ClockHasBeenReset:: @ 85ECA4F
	.string "The clock has been reset.\nData will be saved. Please wait.$"

gText_SaveCompleted:: @ 85ECA8A
	.string "Save completed.$"

gText_SaveFailed:: @ 85ECA9A
	.string "Save failed…$"

gText_NoSaveFileCantSetTime:: @ 85ECAA7
	.string "There is no save file, so the time\ncan’t be set.$"

gText_InGameClockUsable:: @ 85ECAD8
	.string "The in-game clock adjustment system\nis now useable.$"

gText_Slots:: @ 85ECB0C
	.string "SLOTS$"

gText_Roulette:: @ 85ECB12
	.string "ROULETTE$"

gText_Good:: @ 85ECB1B
	.string "Good$"

gText_VeryGood:: @ 85ECB20
	.string "Very good$"

gText_Excellent:: @ 85ECB2A
	.string "Excellent$"

gText_SoSo:: @ 85ECB34
	.string "So-so$"

gText_Bad:: @ 85ECB3A
	.string "Bad$"

gText_TheWorst:: @ 85ECB3E
	.string "The worst$"

gText_Spicy2:: @ 85ECB48
	.string "spicy$"

gText_Dry2:: @ 85ECB4E
	.string "dry$"

gText_Sweet2:: @ 85ECB52
	.string "sweet$"

gText_Bitter2:: @ 85ECB58
	.string "bitter$"

gText_Sour2:: @ 85ECB5F
	.string "sour$"

gText_Single:: @ 85ECB64
	.string "SINGLE$"

gText_Double:: @ 85ECB6B
	.string "DOUBLE$"

gText_Jackpot:: @ 85ECB72
	.string "jackpot$"

gText_First:: @ 85ECB7A
	.string "first$"

gText_Second:: @ 85ECB80
	.string "second$"

gText_Third:: @ 85ECB87
	.string "third$"

	.string "0 pts$"
	.string "10 pts$"
	.string "20 pts$"
	.string "30 pts$"
	.string "40 pts$"
	.string "50 pts$"
	.string "60 pts$"
	.string "70 pts$"
	.string "80 pts$"
	.string "90 pts$"
	.string "100 pts$"
	.string "?$"
	.string "KISS POSTER{CLEAR_TO 0x5E}16BP$"
	.string "KISS CUSHION{CLEAR_TO 0x5E}32BP$"
	.string "SMOOCHUM DOLL{CLEAR_TO 0x5E}32BP$"
	.string "TOGEPI DOLL{CLEAR_TO 0x5E}48BP$"
	.string "MEOWTH DOLL{CLEAR_TO 0x5E}48BP$"
	.string "CLEFAIRY DOLL{CLEAR_TO 0x5E}48BP$"
	.string "DITTO DOLL{CLEAR_TO 0x5E}48BP$"
	.string "CYNDAQUIL DOLL{CLEAR_TO 0x5E}80BP$"
	.string "CHIKORITA DOLL{CLEAR_TO 0x5E}80BP$"
	.string "TOTODILE DOLL{CLEAR_TO 0x5E}80BP$"
	.string "LAPRAS DOLL{CLEAR_TO 0x58}128BP$"
	.string "SNORLAX DOLL{CLEAR_TO 0x58}128BP$"
	.string "VENUSAUR DOLL{CLEAR_TO 0x58}256BP$"
	.string "CHARIZARD DOLL{CLEAR_TO 0x58}256BP$"
	.string "BLASTOISE DOLL{CLEAR_TO 0x58}256BP$"
	.string "PROTEIN{CLEAR_TO 0x64}1BP$"
	.string "CALCIUM{CLEAR_TO 0x64}1BP$"
	.string "IRON{CLEAR_TO 0x64}1BP$"
	.string "ZINC{CLEAR_TO 0x64}1BP$"
	.string "CARBOS{CLEAR_TO 0x64}1BP$"
	.string "HP UP{CLEAR_TO 0x64}1BP$"
	.string "LEFTOVERS{CLEAR_TO 0x5E}48BP$"
	.string "WHITE HERB{CLEAR_TO 0x5E}48BP$"
	.string "QUICK CLAW{CLEAR_TO 0x5E}48BP$"
	.string "MENTAL HERB{CLEAR_TO 0x5E}48BP$"
	.string "BRIGHTPOWDER{CLEAR_TO 0x5E}64BP$"
	.string "CHOICE BAND{CLEAR_TO 0x5E}64BP$"
	.string "KING’S ROCK{CLEAR_TO 0x5E}64BP$"
	.string "FOCUS BAND{CLEAR_TO 0x5E}64BP$"
	.string "SCOPE LENS{CLEAR_TO 0x5E}64BP$"
	.string "SOFTBOILED{CLEAR_TO 0x4E}16BP$"
	.string "SEISMIC TOSS{CLEAR_TO 0x4E}24BP$"
	.string "DREAM EATER{CLEAR_TO 0x4E}24BP$"
	.string "MEGA PUNCH{CLEAR_TO 0x4E}24BP$"
	.string "MEGA KICK{CLEAR_TO 0x4E}48BP$"
	.string "BODY SLAM{CLEAR_TO 0x4E}48BP$"
	.string "ROCK SLIDE{CLEAR_TO 0x4E}48BP$"
	.string "COUNTER{CLEAR_TO 0x4E}48BP$"
	.string "THUNDER WAVE{CLEAR_TO 0x4E}48BP$"
	.string "SWORDS DANCE{CLEAR_TO 0x4E}48BP$"
	.string "DEFENSE CURL{CLEAR_TO 0x4E}16BP$"
	.string "SNORE{CLEAR_TO 0x4E}24BP$"
	.string "MUD-SLAP{CLEAR_TO 0x4E}24BP$"
	.string "SWIFT{CLEAR_TO 0x4E}24BP$"
	.string "ICY WIND{CLEAR_TO 0x4E}24BP$"
	.string "ENDURE{CLEAR_TO 0x4E}48BP$"
	.string "PSYCH UP{CLEAR_TO 0x4E}48BP$"
	.string "ICE PUNCH{CLEAR_TO 0x4E}48BP$"
	.string "THUNDERPUNCH{CLEAR_TO 0x4E}48BP$"
	.string "FIRE PUNCH{CLEAR_TO 0x4E}48BP$"
    
gText_PkmnFainted3:: @ 85ECF5D
	.string "{STR_VAR_1} fainted…\p\n$"

gText_Marco:: @ 85ECF6B
	.string "MARCO$"

gText_TrainerCardName:: @ 85ECF71
	.string "NAME: $"

gText_TrainerCardIDNo:: @ 85ECF78
	.string "IDNo.$"

gText_TrainerCardMoney:: @ 85ECF7E
	.string "MONEY$"

	.string "¥$"

gText_TrainerCardPokedex:: @ 85ECF86
	.string "POKéDEX$"

gText_EmptyString6:: @ 85ECF8E
	.string "$"

gText_Colon2:: @ 85ECF8F
	.string ":$"

	.string " points$"

gText_TrainerCardTime:: @ 85ECF99
	.string "TIME$"

	.string "ゲ-ムポイント$" @ "geemupointo" ("game point" in Japanese)

gText_Var1sTrainerCard:: @ 85ECFA6
	.string "{STR_VAR_1}’s TRAINER CARD$"

gText_HallOfFameDebut:: @ 85ECFB8
	.string "HALL OF FAME DEBUT  $"

	.string "LINK BATTLES$"
	.string "LINK CABLE BATTLES$"

gText_WinsLosses:: @ 85ECFED
	.string "W:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}  L:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}$"

gText_PokemonTrades:: @ 85ED010
	.string "POKéMON TRADES$"

gText_UnionTradesAndBattles:: @ 85ED01F
	.string "UNION TRADES & BATTLES$"

gText_BerryCrush:: @ 85ED036
	.string "BERRY CRUSH$"

gText_WaitingTrainerFinishReading:: @ 85ED042
	.string "Waiting for the other TRAINER to\nfinish reading your TRAINER CARD.$"

gText_PokeblocksWithFriends:: @ 85ED085
	.string "{POKEBLOCK}S W/FRIENDS$"

gText_Var1DarkGreyShadowLightGrey:: @ 85ED096
	.string "{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}$"

gText_WonContestsWFriends:: @ 85ED09F
	.string "WON CONTESTS W/FRIENDS$"

gText_BattlePtsWon:: @ 85ED0B6
	.string "BATTLE POINTS WON$"

gText_Var1DarkLightGreyBP:: @ 85ED0C8
	.string "{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}BP$"

gText_BattleTower:: @ 85ED0D3
	.string "BATTLE TOWER$"

gText_WSlashStraightSlash:: @ 85ED0E0
	.string "W/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}  STRAIGHT/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}$"

	.string "BATTLE TOWER$"
	.string "BATTLE DOME$"
	.string "BATTLE PALACE$"
	.string "BATTLE FACTORY$"
	.string "BATTLE ARENA$"
	.string "BATTLE PIKE$"
	.string "BATTLE PYRAMID$"

	.align 2
	.string "{STR_VAR_1} SINGLE$"

	.align 2
	.string "{STR_VAR_1} DOUBLE$"

	.align 2
	.string "{STR_VAR_1} MULTI$"

	.align 2
	.string "{STR_VAR_1} LINK$"

	.align 2
	.string "{STR_VAR_1}$"

gText_Give:: @ 85ED193
	.string "Give$"

gText_NoNeed:: @ 85ED198
	.string "No need$"

gText_ColorLightShadowDarkGrey:: @ 85ED1A0
	.string "{COLOR LIGHT_GREY}{SHADOW DARK_GREY}$"

gText_ColorBlue:: @ 85ED1A7
	.string "{COLOR BLUE}$"

gText_ColorTransparent:: @ 85ED1AB
	.string "{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}$"

gText_CDot:: @ 85ED1B2
	.string "C.$"

gText_BDot:: @ 85ED1B5
	.string "B.$"

gText_AnnouncingResults:: @ 85ED1B8
	.string "Announcing the results!$"

gText_PreliminaryResults:: @ 85ED1D0
	.string "The preliminary results!$"

gText_Round2Results:: @ 85ED1E9
	.string "Round 2 results!$"

gText_Var1sVar2Won:: @ 85ED1FA
	.string "{STR_VAR_1}’s {STR_VAR_2} won!$"

gText_CommunicationStandby:: @ 85ED207
	.string "Communication standby…$"

gText_ColorDarkGrey:: @ 85ED21E
	.string "{COLOR DARK_GREY}$"

	.string "{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}$"

gText_HighlightDarkGrey:: @ 85ED228
	.string "{HIGHLIGHT DARK_GREY}$"

	.string " $"

gText_DynColor2Male:: @ 85ED22E
	.string "{COLOR DYNAMIC_COLOR2}♂$"

gText_DynColor1Female:: @ 85ED233
	.string "{COLOR DYNAMIC_COLOR1}♀$"

gText_DynColor2:: @ 85ED238
	.string "{COLOR DYNAMIC_COLOR2}$"
	
gText_Upper:: @ 85ED23C
	.string "UPPER$"
	
gText_Lower:: @ 85ED242
	.string "lower$"
	
gText_Others:: @ 85ED248
	.string "OTHERS$"
	
gText_Symbols:: @ 85ED24F
	.string "SYMBOLS$"
	
gText_Register2:: @ 85ED257
	.string "REGISTER$"
	
gText_Exit2:: @ 85ED260
	.string "EXIT$"

gText_QuitChatting:: @ 85ED265
	.string "Quit chatting?$"

gText_RegisterTextWhere:: @ 85ED274
	.string "Register text where?$"

gText_RegisterTextHere:: @ 85ED289
	.string "Register text here?$"

gText_InputText:: @ 85ED29D
	.string "Input text.$"

gText_F700JoinedChat:: @ 85ED2A9
	.string "{SPECIAL_F7 0x00} joined the chat!$"

gText_F700LeftChat:: @ 85ED2BD
	.string "{SPECIAL_F7 0x00} left the chat.$"

	.string "{SPECIAL_F7 0x00}の{SPECIAL_F7 0x01}ひきめ:$" @ "{SPECIAL_F7 0x00}'s {SPECIAL_F7 0x01}hikime"
	.string "{SPECIAL_F7 0x00}の{SPECIAL_F7 0x01}ひきめは いません$" @ "{SPECIAL_F7 0x00}'s {SPECIAL_F7 0x01}hikimeha imasen"

gText_ExitingChat:: @ 85ED2E8
	.string "Exiting the chat…$"

gText_LeaderLeftEndingChat:: @ 85ED2FA
	.string "The LEADER, {SPECIAL_F7 0x00}, has\nleft, ending the chat.$"

gText_RegisteredTextChanged:: @ 85ED325
	.string "The registered text has been changed.\nIs it okay to save the game?$"

gText_AlreadySavedFile:: @ 85ED368
	.string "There is already a saved file.\nIs it okay to overwrite it?$"

gText_SavingDontTurnOff:: @ 85ED3A3
	.string "SAVING…\nDON’T TURN OFF THE POWER.$"

gText_PlayerSavedGame:: @ 85ED3C5
	.string "{SPECIAL_F7 0x00} saved the game.$"

gText_IfLeaderLeavesChatEnds:: @ 85ED3D8
	.string "If the LEADER leaves, the chat\nwill end. Is that okay?$"

gText_Hello:: @ 85ED40F
	.string "HELLO$"

gText_Pokemon2:: @ 85ED415
	.string "POKéMON$"

gText_Trade:: @ 85ED41D
	.string "TRADE$"

gText_Battle:: @ 85ED423
	.string "BATTLE$"

gText_Lets:: @ 85ED42A
	.string "LET’S$"

gText_Ok:: @ 85ED430
	.string "OK!$"

gText_Sorry:: @ 85ED434
	.string "SORRY$"

gText_YayUnkF9F9:: @ 85ED43A
	.string "YAY{UNK_CTRL_F9F9}$"

gText_ThankYou:: @ 85ED440
	.string "THANK YOU$"

gText_ByeBye:: @ 85ED44A
	.string "BYE-BYE!$"

	.string "Attack the weak points!$"
	.string "Ultimate STEEL POKéMON.$"
	.string "I’d climb even waterfalls$"
	.string "to find a rare stone!$"
	.string "I’m the strongest and most$"
	.string "energetic after all!$"
	.string "Battle with knowledge!$"
	.string "I will use various POKéMON.$"
	.string "I’ll be a better POKéMON$"
	.string "prof than my father is!$"
	.string "I’m not so good at battles.$"
	.string "I’ll use any POKéMON!$"
	.string "My POKéMON and I help$"
	.string "my father’s research.$"

gText_PkmnHatchedFromEgg:: @ 85ED5A5
	.string "{STR_VAR_1} hatched from the EGG!$"

gText_NameHatchedPkmn:: @ 85ED5BE
	.string "Would you like to nickname the newly\nhatched {STR_VAR_1}?$"

	.align 2
gText_ReadyToBerryCrush:: @ 85ED5F0
	.string "Are you ready to BERRY-CRUSH?\nPlease pick a BERRY for use.\p$"

	.align 2
gText_WaitForAllChooseBerry:: @ 85ED62C
	.string "Please wait while each member\nchooses a BERRY.$"

	.align 2
gText_EndedWithXUnitsPowder:: @ 85ED65C
	.string "{PAUSE_MUSIC}{PLAY_BGM BGM_FANFA1}You ended up with {STR_VAR_1} units of\nsilky-smooth BERRY POWDER.{RESUME_MUSIC}\pYour total amount of BERRY POWDER\nis {STR_VAR_2}.\p$"

	.align 2
gText_RecordingGameResults:: @ 85ED6C8
	.string "Recording your game results in the\nsave file.\lPlease wait.$"

	.align 2
gText_PlayBerryCrushAgain:: @ 85ED704
	.string "Want to play BERRY CRUSH again?$"

	.align 2
gText_YouHaveNoBerries:: @ 85ED724
	.string "You have no BERRIES.\nThe game will be canceled.$"

	.align 2
gText_MemberDroppedOut:: @ 85ED754
	.string "A member dropped out.\nThe game will be canceled.$"

	.align 2
gText_TimesUpNoGoodPowder:: @ 85ED788
	.string "Time’s up.\pGood BERRY POWDER could not be\nmade…\p$"

	.align 2
gText_CommunicationStandby2:: @ 85ED7BC
	.string "Communication standby…$"

	.align 2
gText_1DotBlueF700:: @ 85ED7D4
	.string "1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{SPECIAL_F7 0x00}$"

	.align 2
gText_1DotF700:: @ 85ED7E0
	.string "1. {SPECIAL_F7 0x00}$"

	.align 2
gText_SpaceTimes2:: @ 85ED7E8
	.string " time(s)$"

	.align 2
gText_XDotY:: @ 85ED7F4
	.string "{STR_VAR_1}.{STR_VAR_2}$"

	.align 2
gText_Var1Berry:: @ 85ED7FC
	.string "{STR_VAR_1} BERRY$"

	.align 2
gText_TimeColon:: @ 85ED808
	.string "Time:$"
	
	.align 2
gText_PressingSpeed:: @ 85ED810
	.string "Pressing Speed:$"

	.align 2
gText_Silkiness:: @ 85ED820
	.string "Silkiness:$"

	.align 2
gText_StrVar1:: @ 85ED82C
	.string "{STR_VAR_1}$"

	.align 2
gText_SpaceMin:: @ 85ED830
	.string " min. $"

	.align 2
gText_XDotY2:: @ 85ED838
	.string "{STR_VAR_1}.{STR_VAR_2}$"

	.align 2
gText_SpaceSec:: @ 85ED840
	.string " sec.$"

	.align 2
gText_XDotY3:: @ 85ED848
	.string "{STR_VAR_1}.{STR_VAR_2}$"

	.align 2
gText_TimesPerSec:: @ 85ED850
	.string " Times/sec.$"

	.align 2
gText_Var1Percent:: @ 85ED85C
	.string "{STR_VAR_1}%$"

	.align 2
gText_PressesRankings:: @ 85ED860
	.string "No. of Presses Rankings$"

	.align 2
gText_CrushingResults:: @ 85ED878
	.string "Crushing Results$"

	.align 2
gText_NeatnessRankings:: @ 85ED88C
	.string "Neatness Rankings$"

	.align 2
gText_CoopRankings:: @ 85ED8A0
	.string "Cooperative Rankings$"

	.align 2
gText_PressingPowerRankings:: @ 85ED8B8
	.string "Pressing-Power Rankings$"

gText_BerryCrush2:: @ 85ED8D0
	.string "BERRY CRUSH$"

gText_PressingSpeedRankings:: @ 85ED8DC
	.string "Pressing-Speed Rankings$"

gText_Var1Players:: @ 85ED8F4
	.string "{STR_VAR_1} PLAYERS$"

gText_SymbolsEarned:: @ 85ED8FF
	.string "Symbols Earned$"

gText_BattleRecord:: @ 85ED90E
	.string "Battle Record$"

gText_BattlePoints:: @ 85ED91C
	.string "Battle Points$"

	.string "CANCEL$"
	.string "$"
	.string "Check BATTLE FRONTIER MAP.$"
	.string "Check TRAINER CARD.$"
	.string "View recorded battle.$"
	.string "Put away the FRONTIER PASS.$"
	.string "Your current Battle Points.$"
	.string "Your collected Symbols.$"
	.string "Battle Tower - Ability Symbol$"
	.string "Battle Dome - Tactics Symbol$"
	.string "Battle Palace - Spirits Symbol$"
	.string "Battle Arena - Guts Symbol$"
	.string "Battle Factory - Knowledge Symbol$"
	.string "Battle Pike - Luck Symbol$"
	.string "Battle Pyramid - Brave Symbol$"
	.string "There is no Battle Record.$"
	.string "BATTLE TOWER$"
	.string "BATTLE DOME$"
	.string "BATTLE PALACE$"
	.string "BATTLE ARENA$"
	.string "BATTLE FACTORY$"
	.string "BATTLE PIKE$"
	.string "BATTLE PYRAMID$"
	.string "KO opponents and aim for the top!\nYour ability will be tested.$"
	.string "Keep winning at the tournament!\nYour tactics will be tested.$"
	.string "Watch your POKéMON battle!\nYour spirit will be tested.$"
	.string "Win battles with teamed-up POKéMON!\nYour guts will be tested.$"
	.string "Aim for victory using rental POKéMON!\nYour knowledge will be tested.$"
	.string "Select one of three paths to battle!\nYour luck will be tested.$"
	.string "Aim for the top with exploration!\nYour bravery will be tested.$"

gText_ContinueMenuPlayer:: @ 85EDCC3
	.string "PLAYER$"

gText_ContinueMenuTime:: @ 85EDCCA
	.string "TIME$"

gText_ContinueMenuPokedex:: @ 85EDCCF
	.string "POKéDEX$"

gText_ContinueMenuBadges:: @ 85EDCD7
	.string "BADGES$"

gText_Powder:: @ 85EDCDE
	.string "POWDER$"

gText_BerryPickingRecords:: @ 85EDCE5
	.string "DODRIO BERRY-PICKING RECORDS$"

gText_BerriesPicked:: @ 85EDD02
	.string "BERRIES picked:$"

gText_BestScore:: @ 85EDD12
	.string "Best score:$"

gText_BerriesInRowFivePlayers:: @ 85EDD1E
	.string "BERRIES picked in a row with\nfive players:$"

gText_BerryPickingResults:: @ 85EDD49
	.string "Announcing BERRY-PICKING results!$"

gText_10P30P50P50P:: @ 85EDD6B
	.string "{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{UNK_CTRL_F9DD}50P$"
    
gText_AnnouncingRankings:: @ 85EDD86
	.string "Announcing rankings!$"

gText_AnnouncingPrizes:: @ 85EDD9B
	.string "Announcing prizes!$"

gText_1Colon:: @ 85EDDAE
	.string "1:$"

gText_2Colon:: @ 85EDDB1
	.string "2:$"

gText_3Colon:: @ 85EDDB4
	.string "3:$"

gText_4Colon:: @ 85EDDB7
	.string "4:$"

gText_5Colon:: @ 85EDDBA
	.string "5:$"

gText_FirstPlacePrize:: @ 85EDDBD
	.string "The first-place winner gets\nthis {SPECIAL_F7 0x00}!$"

gText_CantHoldAnyMore:: @ 85EDDE2
	.string "You can’t hold any more!$"

gText_FilledStorageSpace:: @ 85EDDFB
	.string "It filled its storage space.$"

gText_WantToPlayAgain:: @ 85EDE18
	.string "Want to play again?$"

gText_SomeoneDroppedOut:: @ 85EDE2C
	.string "Somebody dropped out.\nThe link will be canceled.$"

gText_SpacePoints:: @ 85EDE5D
	.string " points$"

gText_CommunicationStandby3:: @ 85EDE65
	.string "Communication standby…$"

gText_SpacePoints2:: @ 85EDE7C
	.string " points$"

gText_SpaceTimes3:: @ 85EDE84
	.string " time(s)$"

gText_PkmnJumpRecords:: @ 85EDE8D
	.string "POKéMON JUMP RECORDS$"

gText_JumpsInARow:: @ 85EDEA2
	.string "Jumps in a row:$"

gText_BestScore2:: @ 85EDEB2
	.string "Best score:$"

gText_ExcellentsInARow:: @ 85EDEBE
	.string "EXCELLENTS in a row:$"

gText_AwesomeWonF701F700:: @ 85EDED3
	.string "Awesome score! You’ve\nwon {SPECIAL_F7 0x01} {SPECIAL_F7 0x00}!$"

gText_FilledStorageSpace2:: @ 85EDEF4
	.string "It filled its storage space.$"

gText_CantHoldMore:: @ 85EDF11
	.string "You can’t hold any more!$"

gText_WantToPlayAgain2:: @ 85EDF2A
	.string "Want to play again?$"

gText_SomeoneDroppedOut2:: @ 85EDF3E
	.string "Somebody dropped out.\nThe link will be canceled.$"

gText_CommunicationStandby4:: @ 85EDF6F
	.string "Communication standby…$"

gText_LinkContestResults:: @ 85EDF86
	.string "{PLAYER}’s Link Contest Results$"

gText_1st:: @ 85EDFA0
	.string "1st$"

gText_2nd:: @ 85EDFA4
	.string "2nd$"

gText_3rd:: @ 85EDFA8
	.string "3rd$"

gText_4th:: @ 85EDFAC
	.string "4th$"

gText_Friend:: @ 85EDFB0
	.string "Friend$"

	.string "POKeMON$"

gJPText_MysteryGift:: @ 85EDFBF
	.string "ふしぎなもらいもの$" @ "fushiginamoraimono" ("Mystery Gift" in Japanese)

gJPText_DecideStop:: @ 85EDFC9
	.string "{UNK_CTRL_F800}けってい {UNK_CTRL_F801}やめる$" @ "{UNK_CTRL_F800}kettei {UNK_CTRL_F801}yameru" ("{UNK_CTRL_F800}decide {UNK_CTRL_F801}stop" in Japanese)

@ A bunch of Japanese strings here, waiting for updated datadump to dump properly
gUnknown_085EDFD6:: @ 85EDFD6
	.byte 0x56, 0xae, 0x95, 0xd9, 0x78, 0xae, 0x91, 0xae, 0xf9, 0x04, 0x00, 0x44, 0xfe, 0x1c, 0x0c, 0x38, 0x15, 0x23, 0x27, 0x02, 0x23, 0x19, 0x2d, 0x00, 0x26, 0x20, 0x0a, 0x20, 0x1f, 0x0d, 0xff

gUnknown_085EDFF5:: @ 85EDFF5
	.byte 0x56, 0xae, 0x95, 0xd9, 0x78, 0xae, 0x91, 0xae, 0xf9, 0x04, 0x19, 0x00, 0x72, 0x66, 0x85, 0xae, 0x06, 0x27, 0xfe, 0xb3, 0x12, 0x03, 0x0c, 0x2e, 0xb4, 0x2d, 0x00, 0x04, 0x27, 0x47, 0xff

gUnknown_085EE014:: @ 85EE014
	.byte 0xb3, 0x8a, 0xae, 0x71, 0x9a, 0xae, 0x52, 0x51, 0x95, 0x96, 0x7e, 0x5d, 0x14, 0x12, 0x03, 0x0c, 0x2e, 0xb4, 0xfe, 0x2d, 0x00, 0x0e, 0x2e, 0x10, 0x08, 0x00, 0x0c, 0x13, 0x08, 0x41, 0x0b, 0x02
	.byte 0xff, 0x56, 0xae, 0x95, 0xd9, 0x78, 0xae, 0x91, 0xae, 0xf9, 0x04, 0x19, 0x00, 0xb3, 0x12, 0x03, 0x0c, 0x2e, 0xb4, 0x2d, 0xfe, 0x04, 0x27, 0x2e, 0x44, 0x00, 0xbb, 0x9a, 0x60, 0x7e, 0x2d, 0x00
	.byte 0x05, 0x0c, 0x13, 0x08, 0x41, 0x0b, 0x02, 0xff

gUnknown_085EE05C:: @ 85EE05C
	.byte 0x0e, 0x12, 0x40, 0x08, 0x37, 0x00, 0x1f, 0x11, 0x37, 0x50, 0x13, 0x02, 0x1f, 0x0d, 0xff

gUnknown_085EE06B:: @ 85EE06B
	.byte 0x56, 0xae, 0x95, 0x19, 0x00, 0x26, 0x20, 0x0a, 0x20, 0x2d, 0xfe, 0x11, 0x35, 0x03, 0x0c, 0x00, 0x0c, 0x1f, 0x0c, 0x10, 0xff, 0x56, 0xae, 0x95, 0xd9, 0x78, 0xae, 0x91, 0xae, 0xf9, 0x04, 0x14
	.byte 0xfe, 0x12, 0x03, 0x0c, 0x2e, 0x00, 0x44, 0x07, 0x1f, 0x0e, 0x2e, 0xff

gUnknown_085EE097:: @ 85EE097
	.byte 0x12, 0x03, 0x0c, 0x2e, 0x00, 0x11, 0x35, 0x03, 0x00, 0x44, 0x0d, 0xff

gUnknown_085EE0A3:: @ 85EE0A3
	.byte 0x12, 0x03, 0x0c, 0x2e, 0x00, 0x54, 0x77, 0xae, 0x44, 0x0d, 0xfe, 0x0e, 0x12, 0x40, 0x08, 0x2d, 0x00, 0x10, 0x0c, 0x06, 0x22, 0x13, 0x00, 0x08, 0x41, 0x0b, 0x02, 0xff

gUnknown_085EE0BF:: @ 85EE0BF
	.byte 0x12, 0x03, 0x0c, 0x2e, 0x00, 0x54, 0x77, 0xae, 0x44, 0x0d, 0xfe, 0x1a, 0x3d, 0x22, 0x06, 0x27, 0x00, 0x24, 0x28, 0x15, 0x05, 0x0c, 0x13, 0x00, 0x08, 0x41, 0x0b, 0x02, 0xff

gUnknown_085EE0DC:: @ 85EE0DC
	.byte 0x56, 0xae, 0x95, 0xd9, 0x78, 0xae, 0x91, 0xae, 0xf9, 0x04, 0x00, 0x16, 0xfe, 0x56, 0xae, 0x95, 0x2d, 0x00, 0x26, 0x20, 0x0a, 0x1f, 0x0e, 0x13, 0x00, 0x08, 0x41, 0x0b, 0x02, 0xff

gUnknown_085EE0FA:: @ 85EE0FA
	.byte 0x12, 0x03, 0x0c, 0x2e, 0x00, 0x0c, 0x35, 0x03, 0x28, 0x36, 0x03, 0xab, 0xff

gUnknown_085EE107:: @ 85EE107
	.byte 0x01, 0x27, 0x10, 0x15, 0x00, 0x64, 0x7a, 0xae, 0x65, 0xae, 0x37, 0xfe, 0x6e, 0x53, 0x54, 0x7e, 0x16, 0x00, 0x24, 0x50, 0x13, 0x07, 0x10, 0xab, 0xff

gUnknown_085EE120:: @ 85EE120
	.byte 0x0c, 0x46, 0x27, 0x08, 0x00, 0x05, 0x1f, 0x11, 0x08, 0x41, 0x0b, 0x02, 0xff

gUnknown_085EE12D:: @ 85EE12D
	.byte 0x06, 0x07, 0x0a, 0x20, 0x00, 0x54, 0x77, 0xae, 0x00, 0x44, 0x0d, 0xfe, 0x94, 0xae, 0x60, 0x37, 0x00, 0x1e, 0x40, 0x2e, 0x00, 0x44, 0x07, 0x1f, 0x0e, 0x2e, 0x44, 0x0c, 0x10, 0xff

	.string "RED$"
	.string "BLUE$"
	.string "---$"

gText_SingleBattleRoomResults:: @ 85EE158
	.string "{PLAYER}’s Single Battle Room Results$"

gText_DoubleBattleRoomResults:: @ 85EE178
	.string "{PLAYER}’s Double Battle Room Results$"

gText_MultiBattleRoomResults:: @ 85EE198
	.string "{PLAYER}’s Multi Battle Room Results$"

gText_LinkMultiBattleRoomResults:: @ 85EE1B7
	.string "{PLAYER}’s Link Multi Battle Room Results$"

gText_SingleBattleTourneyResults:: @ 85EE1DB
	.string "{PLAYER}’s Single Battle Tourney Results$"

gText_DoubleBattleTourneyResults:: @ 85EE1FE
	.string "{PLAYER}’s Double Battle Tourney Results$"

gText_SingleBattleHallResults:: @ 85EE221
	.string "{PLAYER}’s Single Battle Hall Results$"

gText_DoubleBattleHallResults:: @ 85EE241
	.string "{PLAYER}’s Double Battle Hall Results$"

gText_BattleChoiceResults:: @ 85EE261
	.string "{PLAYER}’s Battle Choice Results$"

gText_SetKOTourneyResults:: @ 85EE27C
	.string "{PLAYER}’s Set KO Tourney Results$"

gText_BattleSwapSingleResults:: @ 85EE298
	.string "{PLAYER}’s Battle Swap Single Results$"

gText_BattleSwapDoubleResults:: @ 85EE2B8
	.string "{PLAYER}’s Battle Swap Double Results$"

gText_BattleQuestResults:: @ 85EE2D8
	.string "{PLAYER}’s Battle Quest Results$"

gText_Lv502:: @ 85EE2F2
	.string "LV. 50$"

gText_OpenLv:: @ 85EE2F9
	.string "OPEN LV.$"

gText_WinStreak:: @ 85EE302
	.string "Win streak: {STR_VAR_1}$"

gText_Current:: @ 85EE311
	.string "CURRENT$"

gText_Record:: @ 85EE319
	.string "RECORD$"

gText_Prev:: @ 85EE320
	.string "PREV.$"

gText_RentalSwap:: @ 85EE326
	.string "Rental/Swap$"

gText_Total:: @ 85EE332
	.string "Total$"

gText_ClearStreak:: @ 85EE338
	.string "Clear streak: {STR_VAR_1}$"

gText_Championships:: @ 85EE349
	.string "Championships: {STR_VAR_1}$"

gText_RoomsCleared:: @ 85EE35B
	.string "Rooms cleared: {STR_VAR_1}$"

gText_TimesCleared:: @ 85EE36D
	.string "Times cleared:{CLEAR 0x05}{STR_VAR_1}$"

gText_KOsInARow:: @ 85EE381
	.string "KOs in a row: {STR_VAR_1}$"

gText_TimesVar1:: @ 85EE392
	.string "Times: {STR_VAR_1}$"

gText_FloorsCleared:: @ 85EE39C
	.string "Floors cleared: {STR_VAR_1}$"

	.align 2
	.string "LV. 50$"

	.align 2
	.string "OPEN LEVEL$"

	.align 2
	.string "Win streak: {STR_VAR_2}$"

	.align 2
	.string "Clear streak: {STR_VAR_2}$"

	.align 2
	.string "Rooms cleared: {STR_VAR_2}$"

	.align 2
	.string "KOs in a row: {STR_VAR_2}$"

	.align 2
	.string "Floors cleared: {STR_VAR_2}$"

	.align 2
gText_1Dot:: @ 85EE424
	.string "1.$"

	.string "2.$"
	.string "3.$"

gText_SavingDontTurnOff2:: @ 85EE42D
	.string "SAVING…\nDON’T TURN OFF THE POWER.$"

gText_BlenderMaxSpeedRecord:: @ 85EE44F
	.string "BERRY BLENDER\nMAXIMUM SPEED RECORD!$"

gText_234Players:: @ 85EE473
	.string "2 PLAYERS\n3 PLAYERS\n4 PLAYERS$"

gText_YesNo:: @ 85EE491
	.string "YES\nNO$"

gText_SelectorArrow3:: @ 85EE498
	.string "▶$"

gText_Peekaboo:: @ 85EE49A
	.string "PEEKABOO!$"

gText_CommErrorCheckConnections:: @ 85EE4A4
	.string "Communication error…\nPlease check all connections,\nthen turn the power OFF and ON.$"

gText_CommErrorEllipsis:: @ 85EE4F7
	.string "Communication error…$"

gText_MoveCloserToLinkPartner:: @ 85EE50C
	.string "Move closer to your link partner(s).\nAvoid obstacles between partners.$"

gText_ABtnRegistrationCounter:: @ 85EE553
	.string "A Button: Registration Counter$"

gText_ABtnTitleScreen:: @ 85EE572
	.string "A Button: Title Screen$"

gText_Option:: @ 85EE589
	.string "OPTION$"

	.string "TEXT SPEED$"
	.string "BATTLE SCENE$"
	.string "BATTLE STYLE$"
	.string "SOUND$"
	.string "FRAME$"
	.string "CANCEL$"
	.string "BUTTON MODE$"

gText_TextSpeedSlow:: @ 85EE5D4
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}SLOW$"

gText_TextSpeedMid:: @ 85EE5DF
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}MID$"

gText_TextSpeedFast:: @ 85EE5E9
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST$"

gText_BattleSceneOn:: @ 85EE5F4
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}ON$"

gText_BattleSceneOff:: @ 85EE5FD
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF$"

gText_BattleStyleShift:: @ 85EE607
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}SHIFT$"

gText_BattleStyleSet:: @ 85EE613
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}SET$"

gText_SoundMono:: @ 85EE61D
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}MONO$"

gText_SoundStereo:: @ 85EE628
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}STEREO$"

gText_FrameType:: @ 85EE635
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE$"

gText_FrameTypeNumber:: @ 85EE640
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}$"

gText_ButtonTypeNormal:: @ 85EE647
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL$"

gText_ButtonTypeLR:: @ 85EE654
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}LR$"

gText_ButtonTypeLEqualsA:: @ 85EE65D
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A$"

gText_XPLink:: @ 85EE667
	.string "{STR_VAR_1}P LINK$"

	.string "BRONZE$"
	.string "COPPER$"
	.string "SILVER$"
	.string "GOLD$"

gText_Day:: @ 85EE68A
	.string "DAY$"

gText_Colon3:: @ 85EE68E
	.string ":$"

gText_Confirm2:: @ 85EE690
	.string "CONFIRM$"

	.string "Days$"
	.string "Time:$"
	.string "Game time$"
	.string "RTC time$"
	.string "Updated time$"
	.string "POKéDEX$"
	.string "POKéMON$"
	.string "BAG$"
	.string "POKéNAV$"
	.string "{PLAYER}$"
	.string "SAVE$"
	.string "OPTION$"
	.string "EXIT$"
	.string "RETIRE$"
	.string "REST$"

gText_SafariBallStock:: @ 85EE6FF
	.string "SAFARI BALLS\nStock: {STR_VAR_1}$"

gText_BattlePyramidFloor:: @ 85EE716
	.string "Battle Pyramid\n{STR_VAR_1}$"

	.string "Floor 1$"
	.string "Floor 2$"
	.string "Floor 3$"
	.string "Floor 4$"
	.string "Floor 5$"
	.string "Floor 6$"
	.string "Floor 7$"
	.string "Peak$"

gText_LinkStandby2:: @ 85EE765
	.string "Link standby…\n… … B Button: Cancel$"

gText_PressAToLoadEvent:: @ 85EE788
	.string "Press the A Button to load event.\n… … B Button: Cancel$"

gText_LoadingEvent:: @ 85EE7BF
	.string "Loading event…$"

gText_DontRemoveCableTurnOff:: @ 85EE7CE
	.string "Don’t remove the Game Link cable.\nDon’t turn off the power.$"

gText_EventSafelyLoaded:: @ 85EE80A
	.string "The event was safely loaded.$"

gText_LoadErrorEndingSession:: @ 85EE827
	.string "Loading error.\nEnding session.$"

	.string "プレイヤー$" @ "pureiyaa" ("player" in Japanese)
	.string "さま$" @ "sama" (a very high honorific)

gText_DexHoenn:: @ 85EE84F
	.string "HOENN$"

gText_DexNational:: @ 85EE855
	.string "NATIONAL$"

gText_PokedexDiploma:: @ 85EE85E
	.string "PLAYER: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK$"
	
	.string "{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク$" @ geemufuriku ("Game Freak" in Japanese)
	.string "{COLOR RED}{SHADOW LIGHT_RED}$"

gText_Hoenn:: @ 85EE8F1
	.string "HOENN$"

gText_OhABite:: @ 85EE8F7
	.string "Oh! A bite!$"

gText_PokemonOnHook:: @ 85EE903
	.string "A POKéMON’s on the hook!{PAUSE_UNTIL_PRESS}$"

gText_NotEvenANibble:: @ 85EE91E
	.string "Not even a nibble…{PAUSE_UNTIL_PRESS}$"

gText_ItGotAway:: @ 85EE933
	.string "It got away…{PAUSE_UNTIL_PRESS}$"

gText_XWillBeSentToY:: @ 85EE942
	.string "{STR_VAR_2} will be\nsent to {STR_VAR_1}.$"

gText_ByeByeVar1:: @ 85EE959
	.string "Bye-bye, {STR_VAR_2}!$"

gText_XSentOverY:: @ 85EE966
	.string "{STR_VAR_1} sent over {STR_VAR_3}.$"

gText_TakeGoodCareOfX:: @ 85EE977
	.string "Take good care of {STR_VAR_3}!$"


	.include "data/text/easy_chat/easy_chat_group_names.inc"

gText_ThreeQuestionMarks:: @ 85EEA42
	.string "???$"

	.string "MAX. HP$"
	.string "ATTACK$"
	.string "DEFENSE$"
	.string "SPEED$"
	.string "SP. ATK$"
	.string "SP. DEF$"

gText_UnkCtrlF904:: @ 85EEA73
	.string "{UNK_CTRL_F904}$"

gText_Dash:: @ 85EEA76
	.string "-$"

gText_FromSpace:: @ 85EEA78
	.string "From $"

gText_MixingRecords:: @ 85EEA7E
	.string "Mixing records…$"

gText_RecordMixingComplete:: @ 85EEA8E
	.string "Record mixing completed.\nThank you for waiting.$"

	.string "YOUR NAME?$"
	.string "BOX NAME?$"
	.string "{STR_VAR_1}’s nickname?$"
	.string "Tell him the words.$"

gText_MoveOkBack:: @ 85EEAF6
	.string "{UNK_CTRL_F80C}MOVE  {UNK_CTRL_F800}OK  {UNK_CTRL_F801}BACK$"

gText_CallCantBeMadeHere:: @ 85EEB0B
	.string "A call can’t be made from here.$"

gUnknown_085EEB2B::
	.string "HANDSOME$"

gUnknown_085EEB34::
	.string "VINNY$"

gUnknown_085EEB3A::
	.string "MOREME$"

gUnknown_085EEB41::
	.string "IRONHARD$"

gUnknown_085EEB4A::
	.string "MUSCLE$"

gUnknown_085EEB51::
	.string "coolness$"

gUnknown_085EEB5A::
	.string "beauty$"

gUnknown_085EEB61::
	.string "cuteness$"

gUnknown_085EEB6A::
	.string "smartness$"

gUnknown_085EEB74::
	.string "toughness$"

gText_Lady2:: @ 85EEB7E
	.string "Lady$"

gUnknown_085EEB83::
	.string "slippery$"

gUnknown_085EEB8C::
	.string "roundish$"

gUnknown_085EEB95::
	.string "wham-ish$"

gUnknown_085EEB9E::
	.string "shiny$"

gUnknown_085EEBA4::
	.string "sticky$"

gUnknown_085EEBAB::
	.string "pointy$"

gText_RentalPkmn2:: @ 85EEBB2
	.string "RENTAL POKéMON$"

gText_SelectFirstPkmn:: @ 85EEBC1
	.string "Select the first POKéMON.$"

gText_SelectSecondPkmn:: @ 85EEBDB
	.string "Select the second POKéMON.$"

gText_SelectThirdPkmn:: @ 85EEBF6
	.string "Select the third POKéMON.$"

gText_Rent:: @ 85EEC10
	.string "RENT$"

gText_Summary:: @ 85EEC15
	.string "SUMMARY$"

gText_Others2:: @ 85EEC1D
	.string "OTHERS$"

gText_Deselect:: @ 85EEC24
	.string "DESELECT$"

gText_TheseThreePkmnOkay:: @ 85EEC2D
	.string "Are these three POKéMON OK?$"

gText_Yes2:: @ 85EEC49
	.string "YES$"

gText_No2:: @ 85EEC4D
	.string "NO$"

gText_CantSelectSamePkmn:: @ 85EEC50
	.string "Can’t select same {PKMN}.$"

gText_PkmnSwap:: @ 85EEC66
	.string "POKéMON SWAP$"

gText_SelectPkmnToSwap:: @ 85EEC73
	.string "Select POKéMON to swap.$"

gText_SelectPkmnToAccept:: @ 85EEC8B
	.string "Select POKéMON to accept.$"

gText_Swap:: @ 85EECA5
	.string "SWAP$"

gText_Summary2:: @ 85EECAA
	.string "SUMMARY$"

gText_Rechoose:: @ 85EECB2
	.string "RECHOOSE$"

gText_QuitSwapping:: @ 85EECBB
	.string "Quit swapping?$"

gText_Yes3:: @ 85EECCA
	.string "YES$"

gText_No3:: @ 85EECCE
	.string "NO$"

gText_PkmnForSwap:: @ 85EECD1
	.string "{PKMN} FOR SWAP$"

gText_Cancel3:: @ 85EECDD
	.string "CANCEL$"

	.string "SWAP$"
	.string "ACCEPT$"

gText_AcceptThisPkmn:: @ 85EECF0
	.string "Accept this POKéMON?$"

	.string "    $"

gText_SamePkmnInPartyAlready:: @ 85EED0A
	.string "Same {PKMN} in party already.$"

gText_DecimalPoint:: @ 85EED24
	.string ".$"

gText_SavingPlayer:: @ 85EED26
	.string "PLAYER$"

gText_SavingBadges:: @ 85EED2D
	.string "BADGES$"

gText_SavingPokedex:: @ 85EED34
	.string "POKéDEX$"

gText_SavingTime:: @ 85EED3C
	.string "TIME$"

gText_WirelessCommStatus:: @ 85EED41
	.string "Wireless Communication Status$"

gText_PeopleTrading:: @ 85EED5F
	.string "People trading:$"

gText_PeopleBattling:: @ 85EED6F
	.string "People battling:$"
	
gText_PeopleInUnionRoom:: @ 85EED80
	.string "People in the UNION ROOM:$"

gText_PeopleCommunicating:: @ 85EED9A
	.string "People communicating:$"

gText_F700Players:: @ 85EEDB0
	.string "{SPECIAL_F7 0} players$"
	
gText_F701Players:: @ 85EEDBB
	.string "{SPECIAL_F7 1} players$"
	
gText_F702Players:: @ 85EEDC6
	.string "{SPECIAL_F7 2} players$"
	
gText_F703Players:: @ 85EEDD1
	.string "{SPECIAL_F7 3} players$"

	.align 2
	.4byte gText_F700Players
	.4byte gText_F701Players
	.4byte gText_F702Players
	.4byte gText_F703Players

    .align 2
gText_WonderCards:: @ 85EEDEC
    .string "WONDER CARDS$"

    .align 2
gText_WonderNews:: @ 85EEDFC
    .string "WONDER NEWS$"

    .align 2
gText_WirelessCommunication:: @ 85EEE08
    .string "WIRELESS COMMUNICATION$"

    .align 2
gText_Friend2:: @ 85EEE20
    .string "FRIEND$"

    .align 2
gText_Exit3:: @ 85EEE28
    .string "EXIT$"

    .align 2
gText_Receive:: @ 85EEE30
    .string "RECEIVE$"

    .align 2
gText_Send:: @ 85EEE38
    .string "SEND$"

    .align 2
gText_Toss:: @ 85EEE40
    .string "TOSS$"

    .align 2
gText_VarietyOfEventsImportedWireless:: @ 85EEE48
    .string "A variety of events will be imported\nover Wireless Communication.$"

    .align 2
gText_WonderCardsInPossession:: @ 85EEE40
    .string "Read the WONDER CARDS in your\npossession.$"

    .align 2
gText_ReadNewsThatArrived:: @ 85EEEB8
    .string "Read the NEWS that arrived.$"

    .align 2
gText_ReturnToTitle:: @ 85EEED4
    .string "Return to the title screen.$"

	.align 2
gText_DontHaveCardNewOneInput:: @ 85EEEF0
	.string "You don’t have a WONDER CARD,\nso a new CARD will be input.$"

	.align 2
gText_DontHaveNewsNewOneInput:: @ 85EEF2C
	.string "You don’t have any WONDER NEWS,\nso new NEWS will be input.$"

	.align 2
gText_WhereShouldCardBeAccessed:: @ 85EEF68
	.string "Where should the WONDER CARD\nbe accessed?$"

	.align 2
gText_WhereShouldNewsBeAccessed:: @ 85EEF94
	.string "Where should the WONDER NEWS\nbe accessed?$"

	.align 2
	.string "Communication standby…\nB Button: Cancel$"

	.align 2
gText_Communicating:: @ 85EEFE8
    .string "Communicating…$"

	.align 2
gText_CommunicationCompleted:: @ 85EEFF8
    .string "Communication completed.$"

	.align 2
gText_CommunicationError:: @ 85EF014
    .string "Communication error.$"

	.align 2
gText_CommunicationCanceled:: @ 85EF02C
    .string "Communication has been canceled.$"

	.align 2
gText_ThrowAwayWonderCard:: @ 85EF050
    .string "Throw away the WONDER CARD\nand input a new CARD?$"

	.align 2
gText_HaventReceivedCardsGift:: @ 85EF084
    .string "You haven’t received the CARD’s gift\nyet. Input a new CARD anyway?$"

	.align 2
gText_WonderCardReceivedFrom:: @ 85EF0C8
    .string "A WONDER CARD has been received\nfrom {STR_VAR_1}.$"

	.align 2
gText_WonderNewsReceivedFrom:: @ 85EF0F4
    .string "A WONDER NEWS item has been\nreceived from {STR_VAR_1}.$"

	.align 2
gText_WonderCardReceived:: @ 85EF124
    .string "A new WONDER CARD has been\nreceived.$"

	.align 2
gText_WonderNewsReceived:: @ 85EF14C
    .string "A new WONDER NEWS item has been\nreceived.$"

	.align 2
gText_NewStampReceived:: @ 85EF178
    .string "A new STAMP has been received.$"

	.align 2
gText_NewTrainerReceived:: @ 85EF198
    .string "A new TRAINER has arrived.$"

	.align 2
gText_AlreadyHadCard:: @ 85EF1B4
    .string "You already had that\nWONDER CARD.$"

	.align 2
gText_AlreadyHadNews:: @ 85EF1D8
    .string "You already had that\nWONDER NEWS item.$"

	.align 2
gText_AlreadyHadStamp:: @ 85EF200
	.string "You already had that\nSTAMP.$"

	.align 2
gText_NoMoreRoomForStamps:: @ 85EF21C
	.string "There’s no more room for adding\nSTAMPS.$"

	.align 2
gText_RecordUploadedViaWireless:: @ 85EF244
	.string "Your record has been uploaded via\nWIRELESS COMMUNICATION.$"

	.align 2
gText_CantAcceptCardFromTrainer:: @ 85EF280
	.string "You can’t accept a WONDER CARD\nfrom this TRAINER.$"

	.align 2
gText_CantAcceptNewsFromTrainer:: @ 85EF2B4
	.string "You can’t accept WONDER NEWS\nfrom this TRAINER.$"

	.align 2
gText_NothingSentOver:: @ 85EF2E4
	.string "Nothing was sent over…$"

	.align 2
gText_WhatToDoWithCards:: @ 85EF2FC
	.string "What would you like to do\nwith the WONDER CARDS?$"

	.align 2
gText_WhatToDoWithNews:: @ 85EF330
	.string "What would you like to do\nwith the WONDER NEWS?$"

	.align 2
gText_SendingWonderCard:: @ 85EF360
	.string "Sending your WONDER CARD…$"

	.align 2
gText_SendingWonderNews:: @ 85EF37C
	.string "Sending your WONDER NEWS item…$"

	.align 2
gText_WonderCardSentTo:: @ 85EF39C
	.string "Your WONDER CARD has been sent\nto {STR_VAR_1}.$"

	.align 2
gText_WonderNewsSentTo:: @ 85EF3C4
	.string "Your WONDER NEWS item has been\nsent to {STR_VAR_1}.$"

	.align 2
gText_StampSentTo:: @ 85EF3F0
	.string "A STAMP has been sent to {STR_VAR_1}.$"

	.align 2
gText_GiftSentTo:: @ 85EF410
	.string "A GIFT has been sent to {STR_VAR_1}.$"

	.align 2
gText_OtherTrainerHasCard:: @ 85EF42C
	.string "The other TRAINER has the same\nWONDER CARD already.$"

	.align 2
gText_OtherTrainerHasNews:: @ 85EF460
	.string "The other TRAINER has the same\nWONDER NEWS already.$"

	.align 2
gText_OtherTrainerHasStamp:: @ 85EF494
	.string "The other TRAINER has the same\nSTAMP already.$"

	.align 2
gText_OtherTrainerCanceled:: @ 85EF4C4
	.string "The other TRAINER canceled\ncommunication.$"

	.align 2
gText_CantSendGiftToTrainer:: @ 85EF4F0
	.string "You can’t send a MYSTERY GIFT to\nthis TRAINER.$"

	.align 2
gText_IfThrowAwayCardEventWontHappen:: @ 85EF520
	.string "If you throw away the CARD,\nits event won’t happen. Okay?$"

	.align 2
gText_OkayToDiscardNews:: @ 85EF55C
	.string "Is it okay to discard this\nNEWS item?$"

	.align 2
gText_HaventReceivedGiftOkayToDiscard:: @ 85EF584
	.string "You haven’t received the\nGIFT. Is it okay to discard?$"

	.align 2
gText_DataWillBeSaved:: @ 85EF5BC
	.string "Data will be saved.\nPlease wait.$"

	.align 2
gText_SaveCompletedPressA:: @ 85EF5E0
	.string "Save completed.\nPlease press the A Button.$"

	.align 2
gText_WonderCardThrownAway:: @ 85EF60C
	.string "The WONDER CARD was thrown away.$"

	.align 2
gText_WonderNewsThrownAway:: @ 85EF630
	.string "The WONDER NEWS was thrown away.$"

	.align 2
gText_MysteryGift:: @ 85EF654
	.string "MYSTERY GIFT$"

	.align 2
gText_PickOKExit:: @ 85EF664
	.string "{UNK_CTRL_F80A}PICK {UNK_CTRL_F800}OK {UNK_CTRL_F801}EXIT$"

	.align 2
gText_PickOKCancel:: @ 85EF678
	.string "{UNK_CTRL_F80A}PICK {UNK_CTRL_F800}OK {UNK_CTRL_F801}CANCEL$"

gText_PlayersBattleResults:: @ 85EF68D
	.string "{PLAYER}’s BATTLE RESULTS$"

gText_TotalRecordWLD:: @ 85EF6A1
	.string "TOTAL RECORD W:{STR_VAR_1} L:{STR_VAR_2} D:{STR_VAR_3}$"

gText_WinLoseDraw:: @ 85EF6BD
	.string "{CLEAR_TO 0x53}WIN{CLEAR_TO 0x80}LOSE{CLEAR_TO 0xB0}DRAW$"
    
gText_CommunicationStandby5:: @ 85EF6D2
	.string "Communication standby…$"

gText_QuitTheGame:: @ 85EF6E9
	.string "Quit the game?$"

gText_YouveGot9999Coins:: @ 85EF6F8
	.string "You’ve got 9,999 COINS.$"

gText_YouveRunOutOfCoins:: @ 85EF710
	.string "You’ve run out of COINS.\nGame over!$"

gText_YouDontHaveThreeCoins:: @ 85EF734
	.string "You don’t have three COINS.$"

gText_ReelTimeHelp:: @ 85EF750
	.string "REEL TIME\nHere’s your chance to take\naim and nail marks!\nReel Time continues for the\nawarded number of spins.\nIt all ends on a Big Bonus.$"

	.string "The two seem to get along\nvery well.$"
	.string "The two seem to get along.$"
	.string "The two don’t seem to like\neach other much.$"
	.string "The two prefer to play with other\nPOKéMON than each other.$"

gText_NewLine2:: @ 85EF881
	.string "\n$"

gText_Exit4:: @ 85EF883
	.string "EXIT$"

gText_Lv:: @ 85EF888
	.string "{LV}$"

gText_TimeBoard:: @ 85EF88A
	.string "TIME BOARD$"

gText_TimeCleared:: @ 85EF895
	.string "TIME CLEARED $"

gText_XMinYDotZSec:: @ 85EF8A3
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

	.string "1F$"
	.string "2F$"
	.string "3F$"
	.string "4F$"

gText_TeachWhichMoveToPkmn:: @ 85EF8C2
	.string "Teach which move to {STR_VAR_1}?$"

gText_TeachX:: @ 85EF8DA
	.string "Teach {STR_VAR_2}?$"

gText_PkmnLearnedMove4:: @ 85EF8E4
	.string "{STR_VAR_1} learned\n{STR_VAR_2}!$"

gText_PkmnTryingToLearnMove:: @ 85EF8F3
	.string "{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can’t learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?$"

gText_StopTryingToTeachMove:: @ 85EF960
	.string "Stop trying to teach\n{STR_VAR_2}?$"

gText_12AndPoof:: @ 85EF979
	.string "{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p$"

gText_PkmnForgotMoveAndLearnedNew:: @ 85EF9A6
	.string "{STR_VAR_1} forgot {STR_VAR_3}.\pAnd…\p{STR_VAR_1} learned {STR_VAR_2}.$"

	.string "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.$"

gText_GiveUpTeachingNewMove:: @ 85EF9E6
	.string "Give up trying to teach a new\nmove to {STR_VAR_1}?$"

gText_WhichMoveToForget2:: @ 85EFA10
	.string "Which move should be\nforgotten?\p$"

gText_BattleMoves2:: @ 85EFA31
	.string "BATTLE MOVES$"

gText_ContestMoves2:: @ 85EFA3E
	.string "CONTEST MOVES$"

	.string "TYPE/$"

gText_PPSlash:: @ 85EFA52
	.string "PP/$"

gText_PowerSlash:: @ 85EFA56
	.string "POWER/$"

gText_AccuracySlash:: @ 85EFA5D
	.string "ACCURACY/$"

gText_Appeal2:: @ 85EFA67
	.string "APPEAL$"

gText_Jam2:: @ 85EFA6E
	.string "JAM$"

	.string "KIRA$"
	.string "AMY$"
	.string "JOHN$"
	.string "ROY$"
	.string "GABBY$"
	.string "ANNA$"

gText_ClearAllSaveData:: @ 85EFA8F
	.string "Clear all save data areas?$"

gText_ClearingData:: @ 85EFAAA
	.string "Clearing data…\nPlease wait.$"

gText_IsThisTheCorrectTime:: @ 85EFAC6
	.string "Is this the correct time?$"

gText_Confirm3:: @ 85EFAE0
	.string "CONFIRM$"

gText_Cancel4:: @ 85EFAE8
	.string "CANCEL$"

	.string "DEVON PRES$"
	.string "MR. STONE$"
	.string "HARD AS ROCK$"
	.string "STEVEN$"
	.string "RAD NEIGHBOR$"
	.string "RELIABLE ONE$"
	.string "CALM & KIND$"
	.string "{PKMN} LOVER$"
	.string "DAD$"
	.string "MOM$"
	.string "ELUSIVE EYES$"
	.string "SCOTT$"
	.string "ROCKIN’ WHIZ$"
	.string "THE BIG HIT$"
	.string "SWELL SHOCK$"
	.string "PASSION BURN$"
	.string "SKY TAMER$"
	.string "MYSTIC DUO$"
	.string "DANDY CHARM$"
	.string "ELITE FOUR$"
	.string "CHAMPION$"
	.string "{PKMN} PROF.$"

gText_CommStandbyAwaitingOtherPlayer:: @ 85EFBD2
	.string "Communication standby…\nAwaiting another player to choose.$"

gText_BattleWasRefused:: @ 85EFC0C
	.string "The battle was refused.{PAUSE 60}$"

gText_RefusedBattle:: @ 85EFC27
	.string "Refused the battle.{PAUSE 60}$"

	.string "NO WEATHER$"
	.string "SUNNY$"
	.string "SUNNY2$"
	.string "RAIN$"
	.string "SNOW$"
	.string "LIGHTNING$"
	.string "FOG$"
	.string "VOLCANO ASH$"
	.string "SANDSTORM$"
	.string "FOG2$"
	.string "SEAFLOOR$"
	.string "CLOUDY$"
	.string "SUNNY3$"
	.string "HEAVY RAIN$"
	.string "SEAFLOOR2$"
	.string "DEL. ALL$"
	.string "CANCEL$"
	.string "OK$"
	.string "QUIZ$"
	.string "ANSWER$"

gText_PokeBalls:: @ 85EFCD4
	.string "POKé BALLS$"

gText_Berry:: @ 85EFCDF
	.string "BERRY$"

gText_Berries:: @ 85EFCE5
	.string "BERRIES$"

