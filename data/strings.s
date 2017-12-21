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

gUnknown_085E8270:: @ 85E8270
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

gUnknown_085E836D:: @ 85E836D
	.string "Updating save file using external\ndata. Please wait.$"

gUnknown_085E83A2:: @ 85E83A2
	.string "The save file has been updated.$"

gText_SaveFileCorrupted:: @ 85E83C2
	.string "The save file is corrupted. The\nprevious save file will be loaded.$"

gText_SaveFileErased:: @ 85E8405
	.string "The save file has been erased\ndue to corruption or damage.$"

gJPText_No1MSubCircuit:: @ 85E8440
	.string "1Mサブきばんが ささっていません！$" @ "1Msabukibanga sasatteimasen!" ("The 1M sub-circuit board is not installed!" in Japanese)

gText_BatteryRunDry:: @ 85E8453
	.string "The internal battery has run dry.\nThe game can be played.\pHowever, clock-based events will\nno longer occur.$"

gUnknown_085E84BF:: @ 85E84BF
	.string "PLAYER$"

gUnknown_085E84C6:: @ 85E84C6
	.string "POKéDEX$"

gText_MainMenuTime:: @ 85E84CE
	.string "TIME$"

gUnknown_085E84D3:: @ 85E84D3
	.string "BADGES$"

gUnknown_085E84DA:: @ 85E84DA
	.string "A Button$"

gUnknown_085E84E3:: @ 85E84E3
	.string "B Button$"

gUnknown_085E84EC:: @ 85E84EC
	.string "R Button$"

gUnknown_085E84F5:: @ 85E84F5
	.string "L Button$"

gUnknown_085E84FE:: @ 85E84FE
	.string "START$"

gUnknown_085E8504:: @ 85E8504
	.string "SELECT$"

gUnknown_085E850B:: @ 85E850B
	.string "+ Control Pad$"

gUnknown_085E8519:: @ 85E8519
	.string "L Button  R Button$"

gUnknown_085E852C:: @ 85E852C
	.string "CONTROLS$"

	.align 2

gUnknown_085E8538:: @ 85E8538
	.string "{UNK_CTRL_F80A}PICK {UNK_CTRL_F800}OK$"

	.align 2

gUnknown_085E8544:: @ 85E8544
	.string "{UNK_CTRL_F800}NEXT$"

	.align 2

gUnknown_085E854C:: @ 85E854C
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

gText_BirchBoy:: @ 85E858F
	.string "BOY$"

gText_BirchGirl:: @ 85E8593
	.string "GIRL$"

gText_DefaultNameStu:: @ 85E8598
	.string "STU$"

gText_DefaultNameMilton:: @ 85E859C
	.string "MILTON$"

gText_DefaultNameTom:: @ 85E85A3
	.string "TOM$"

gText_DefaultNameKenny:: @ 85E85A7
	.string "KENNY$"

gText_DefaultNameReid:: @ 85E85AD
	.string "REID$"

gText_DefaultNameJude:: @ 85E85B2
	.string "JUDE$"

gText_DefaultNameJaxson:: @ 85E85B7
	.string "JAXSON$"

gText_DefaultNameEaston:: @ 85E85BE
	.string "EASTON$"

gText_DefaultNameWalker:: @ 85E85C5
	.string "WALKER$"

gText_DefaultNameTeru:: @ 85E85CC
	.string "TERU$"

gText_DefaultNameJohnny:: @ 85E85D1
	.string "JOHNNY$"

gText_DefaultNameBrett:: @ 85E85D8
	.string "BRETT$"

gText_DefaultNameSeth:: @ 85E85DE
	.string "SETH$"

gText_DefaultNameTerry:: @ 85E85E3
	.string "TERRY$"

gText_DefaultNameCasey:: @ 85E85E9
	.string "CASEY$"

gText_DefaultNameDarren:: @ 85E85EF
	.string "DARREN$"

gText_DefaultNameLandon:: @ 85E85F6
	.string "LANDON$"

gText_DefaultNameCollin:: @ 85E85FD
	.string "COLLIN$"

gText_DefaultNameStanley:: @ 85E8604
	.string "STANLEY$"

gText_DefaultNameQuincy:: @ 85E860C
	.string "QUINCY$"

gText_DefaultNameKimmy:: @ 85E8613
	.string "KIMMY$"

gText_DefaultNameTiara:: @ 85E8619
	.string "TIARA$"

gText_DefaultNameBella:: @ 85E861F
	.string "BELLA$"

gText_DefaultNameJayla:: @ 85E8625
	.string "JAYLA$"

gText_DefaultNameAllie:: @ 85E862B
	.string "ALLIE$"

gText_DefaultNameLianna:: @ 85E8631
	.string "LIANNA$"

gText_DefaultNameSara:: @ 85E8638
	.string "SARA$"

gText_DefaultNameMonica:: @ 85E863D
	.string "MONICA$"

gText_DefaultNameCamila:: @ 85E8644
	.string "CAMILA$"

gText_DefaultNameAubree:: @ 85E864B
	.string "AUBREE$"

gText_DefaultNameRuthie:: @ 85E8652
	.string "RUTHIE$"

gText_DefaultNameHazel:: @ 85E8659
	.string "HAZEL$"

gText_DefaultNameNadine:: @ 85E865F
	.string "NADINE$"

gText_DefaultNameTanja:: @ 85E8666
	.string "TANJA$"

gText_DefaultNameYasmin:: @ 85E866C
	.string "YASMIN$"

gText_DefaultNameNicola:: @ 85E8673
	.string "NICOLA$"

gText_DefaultNameLillie:: @ 85E867A
	.string "LILLIE$"

gText_DefaultNameTerra:: @ 85E8681
	.string "TERRA$"

gText_DefaultNameLucy:: @ 85E8687
	.string "LUCY$"

gText_DefaultNameHalie:: @ 85E868C
	.string "HALIE$"

gText_ThisIsAPokemon:: @ 85E8692
	.string "This is what we call a “POKéMON.”{PAUSE 96}\p$"

gText_5MarksPokemon:: @ 85E86B8
	.string "????? POKéMON$"

gText_UnkHeight:: @ 85E86C6
	.string "{CLEAR_TO 0x0C}??’??”$"

gText_UnkWeight:: @ 85E86D0
	.string "????.? lbs.$"

gUnknown_085E86DC:: @ 85E86DC
	.string "                       POKéMON$"

gUnknown_085E86FB:: @ 85E86FB
	.string "{CLEAR_TO 0x0C}    ’    ”$"

gUnknown_085E8709:: @ 85E8709
	.string "        .   lbs.$"

gUnknown_085E871A:: @ 85E871A
	.string "$"

gText_CryOf:: @ 85E871B
	.string "CRY OF$"

gUnknown_085E8722:: @ 85E8722
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

gUnknown_085E87A5:: @ 85E87A5
	.string "Search for POKéMON based on\nselected parameters.$"

gUnknown_085E87D6:: @ 85E87D6
	.string "Switch POKéDEX listings.$"

gUnknown_085E87EF:: @ 85E87EF
	.string "Return to the POKéDEX.$"

gUnknown_085E8806:: @ 85E8806
	.string "Select the POKéDEX mode.$"

gUnknown_085E881F:: @ 85E881F
	.string "Select the POKéDEX listing mode.$"

gUnknown_085E8840:: @ 85E8840
	.string "List by the first letter in the name.\nSpotted POKéMON only.$"

gUnknown_085E887C:: @ 85E887C
	.string "List by body color.\nSpotted POKéMON only.$"

gUnknown_085E88A6:: @ 85E88A6
	.string "List by type.\nOwned POKéMON only.$"

gUnknown_085E88C8:: @ 85E88C8
	.string "Execute search/switch.$"

gUnknown_085E88DF:: @ 85E88DF
	.string "HOENN DEX$"

gUnknown_085E88E9:: @ 85E88E9
	.string "NATIONAL DEX$"

gUnknown_085E88F6:: @ 85E88F6
	.string "NUMERICAL MODE$"

gUnknown_085E8905:: @ 85E8905
	.string "A TO Z MODE$"

gUnknown_085E8911:: @ 85E8911
	.string "HEAVIEST MODE$"

gUnknown_085E891F:: @ 85E891F
	.string "LIGHTEST MODE$"

gUnknown_085E892D:: @ 85E892D
	.string "TALLEST MODE$"

gUnknown_085E893A:: @ 85E893A
	.string "SMALLEST MODE$"

gUnknown_085E8948:: @ 85E8948
	.string "ABC$"

gUnknown_085E894C:: @ 85E894C
	.string "DEF$"

gUnknown_085E8950:: @ 85E8950
	.string "GHI$"

gUnknown_085E8954:: @ 85E8954
	.string "JKL$"

gUnknown_085E8958:: @ 85E8958
	.string "MNO$"

gUnknown_085E895C:: @ 85E895C
	.string "PQR$"

gUnknown_085E8960:: @ 85E8960
	.string "STU$"

gUnknown_085E8964:: @ 85E8964
	.string "VWX$"

gUnknown_085E8968:: @ 85E8968
	.string "YZ$"

gUnknown_085E896B:: @ 85E896B
	.string "RED$"

gUnknown_085E896F:: @ 85E896F
	.string "BLUE$"

gUnknown_085E8974:: @ 85E8974
	.string "YELLOW$"

gUnknown_085E897B:: @ 85E897B
	.string "GREEN$"

gUnknown_085E8981:: @ 85E8981
	.string "BLACK$"

gUnknown_085E8987:: @ 85E8987
	.string "BROWN$"

gUnknown_085E898D:: @ 85E898D
	.string "PURPLE$"

gUnknown_085E8994:: @ 85E8994
	.string "GRAY$"

gUnknown_085E8999:: @ 85E8999
	.string "WHITE$"

gUnknown_085E899F:: @ 85E899F
	.string "PINK$"

gUnknown_085E89A4:: @ 85E89A4
	.string "HOENN region’s POKéDEX$"

gUnknown_085E89BB:: @ 85E89BB
	.string "National edition POKéDEX$"

gUnknown_085E89D4:: @ 85E89D4
	.string "POKéMON are listed according to their\nnumber.$"

gUnknown_085E8A02:: @ 85E8A02
	.string "Spotted and owned POKéMON are listed\nalphabetically.$"

gUnknown_085E8A37:: @ 85E8A37
	.string "Owned POKéMON are listed from the\nheaviest to the lightest.$"

gUnknown_085E8A73:: @ 85E8A73
	.string "Owned POKéMON are listed from the\nlightest to the heaviest.$"

gUnknown_085E8AAF:: @ 85E8AAF
	.string "Owned POKéMON are listed from the\ntallest to the smallest.$"

gUnknown_085E8AEA:: @ 85E8AEA
	.string "Owned POKéMON are listed from the\nsmallest to the tallest.$"

gUnknown_085E8B25:: @ 85E8B25
	.string "$"

gUnknown_085E8B26:: @ 85E8B26
	.string "DON’T SPECIFY.$"

gUnknown_085E8B35:: @ 85E8B35
	.string "NONE$"

gText_SelectorArrow:: @ 85E8B3A
	.string "▶$"

gUnknown_085E8B3C:: @ 85E8B3C
	.string " $"

gText_WelcomeToHOF:: @ 85E8B3E
	.string "Welcome to the HALL OF FAME!$"

gUnknown_085E8B5B:: @ 85E8B5B
	.string "Spotted POKéMON: {STR_VAR_1}!\nOwned POKéMON: {STR_VAR_2}!\pPROF. BIRCH’s POKéDEX rating!\pPROF. BIRCH: Let’s see…\p$"

gUnknown_085E8BBA:: @ 85E8BBA
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

gUnknown_085E8C40:: @ 85E8C40
	.string "IDNo. /$"

gText_Name:: @ 85E8C48
	.string "NAME$"

gText_IDNumber:: @ 85E8C4D
	.string "IDNo.$"

gText_BirchInTrouble:: @ 85E8C53
	.string "PROF. BIRCH is in trouble!\nRelease a POKéMON and rescue him!$"

gText_ConfirmStarterChoice:: @ 85E8C90
	.string "Do you choose this POKéMON?$"

gUnknown_085E8CAC:: @ 85E8CAC
	.string "POKéMON$"

gText_FlyToWhere:: @ 85E8CB4
	.string "FLY to where?$"

gMenuText_Use:: @ 85E8CC2
	.string "USE$"

gMenuText_Toss:: @ 85E8CC6
	.string "TOSS$"

gMenuText_Register:: @ 85E8CCB
	.string "REGISTER$"

gMenuText_Give:: @ 85E8CD4
	.string "GIVE$"

gMenuText_CheckTag:: @ 85E8CD9
	.string "CHECK TAG$"

gMenuText_Confirm:: @ 85E8CE3
	.string "CONFIRM$"

gMenuText_Walk:: @ 85E8CEB
	.string "WALK$"

gText_Cancel:: @ 85E8CF0
	.string "CANCEL$"

gText_Cancel2:: @ 85E8CF7
	.string "CANCEL$"

gMenuText_Show:: @ 85E8CFE
	.string "SHOW$"

gText_EmptyString2:: @ 85E8D03
	.string "$"

gUnknown_085E8D04:: @ 85E8D04
	.string "CANCEL$"

gUnknown_085E8D0B:: @ 85E8D0B
	.string "ITEM$"

gUnknown_085E8D10:: @ 85E8D10
	.string "MAIL$"

gUnknown_085E8D15:: @ 85E8D15
	.string "TAKE$"

gUnknown_085E8D1A:: @ 85E8D1A
	.string "STORE$"

gMenuText_Check:: @ 85E8D20
	.string "CHECK$"

gText_None:: @ 85E8D26
	.string "NONE$"

gMenuText_Deselect:: @ 85E8D2B
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

gUnknown_085E8D55:: @ 85E8D55
	.string "+$"

gUnknown_085E8D57:: @ 85E8D57
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

gMenuText_Give2:: @ 85E8D9B
	.string "GIVE$"

gText_xVar1:: @ 85E8DA0
	.string "×{STR_VAR_1}$"

gUnknown_085E8DA4:: @ 85E8DA4
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

gUnknown_085E9275:: @ 85E9275
	.string "RED {POKEBLOCK}$"

gUnknown_085E927F:: @ 85E927F
	.string "BLUE {POKEBLOCK}$"

gUnknown_085E928A:: @ 85E928A
	.string "PINK {POKEBLOCK}$"

gUnknown_085E9295:: @ 85E9295
	.string "GREEN {POKEBLOCK}$"

gUnknown_085E92A1:: @ 85E92A1
	.string "YELLOW {POKEBLOCK}$"

gUnknown_085E92AE:: @ 85E92AE
	.string "PURPLE {POKEBLOCK}$"

gUnknown_085E92BB:: @ 85E92BB
	.string "INDIGO {POKEBLOCK}$"

gUnknown_085E92C8:: @ 85E92C8
	.string "BROWN {POKEBLOCK}$"

gUnknown_085E92D4:: @ 85E92D4
	.string "LITEBLUE {POKEBLOCK}$"

gUnknown_085E92E3:: @ 85E92E3
	.string "OLIVE {POKEBLOCK}$"

gUnknown_085E92EF:: @ 85E92EF
	.string "GRAY {POKEBLOCK}$"

gUnknown_085E92FA:: @ 85E92FA
	.string "BLACK {POKEBLOCK}$"

gUnknown_085E9306:: @ 85E9306
	.string "WHITE {POKEBLOCK}$"

gUnknown_085E9312:: @ 85E9312
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

gUnknown_085E9339:: @ 85E9339
	.string "TASTY$"

gUnknown_085E933F:: @ 85E933F
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

gUnknown_085E93C7:: @ 85E93C7
	.string "BUY$"

gUnknown_085E93CB:: @ 85E93CB
	.string "SELL$"

gUnknown_085E93D0:: @ 85E93D0
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

gUnknown_085E96A0:: @ 85E96A0
	.string "SHIFT$"

gUnknown_085E96A6:: @ 85E96A6
	.string "SEND OUT$"

gUnknown_085E96AF:: @ 85E96AF
	.string "SWITCH$"

gUnknown_085E96B6:: @ 85E96B6
	.string "SUMMARY$"

gUnknown_085E96BE:: @ 85E96BE
	.string "MOVES$"

gUnknown_085E96C4:: @ 85E96C4
	.string "ENTER$"

gUnknown_085E96CA:: @ 85E96CA
	.string "NO ENTRY$"

gUnknown_085E96D3:: @ 85E96D3
	.string "TAKE$"

gUnknown_085E96D8:: @ 85E96D8
	.string "READ$"

gUnknown_085E96DD:: @ 85E96DD
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

gUnknown_085E9CCA:: @ 85E9CCA
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

gUnknown_085E9E2E:: @ 85E9E2E
	.string "Teach which POKéMON?$"

gUnknown_085E9E43:: @ 85E9E43
	.string "Choose a POKéMON.$"

gUnknown_085E9E55:: @ 85E9E55
	.string "Move to where?$"

gUnknown_085E9E64:: @ 85E9E64
	.string "Teach which POKéMON?$"

gUnknown_085E9E79:: @ 85E9E79
	.string "Use on which POKéMON?$"

gUnknown_085E9E8F:: @ 85E9E8F
	.string "Give to which POKéMON?$"

gUnknown_085E9EA6:: @ 85E9EA6
	.string "Do what with this {PKMN}?$"

gUnknown_085E9EBC:: @ 85E9EBC
	.string "There’s nothing to CUT.$"

gUnknown_085E9ED4:: @ 85E9ED4
	.string "You can’t SURF here.$"

gUnknown_085E9EE9:: @ 85E9EE9
	.string "You’re already SURFING.$"

gUnknown_085E9F01:: @ 85E9F01
	.string "Can’t use that here.$"

gUnknown_085E9F16:: @ 85E9F16
	.string "Restore which move?$"

gUnknown_085E9F2A:: @ 85E9F2A
	.string "Boost PP of which move?$"

gUnknown_085E9F42:: @ 85E9F42
	.string "Do what with an item?$"

gUnknown_085E9F58:: @ 85E9F58
	.string "No POKéMON for battle!$"

gUnknown_085E9F6F:: @ 85E9F6F
	.string "Choose a POKéMON.$"

gUnknown_085E9F81:: @ 85E9F81
	.string "Not enough HP…$"

gUnknown_085E9F90:: @ 85E9F90
	.string "{STR_VAR_1} POKéMON are needed.$"

gUnknown_085E9FA7:: @ 85E9FA7
	.string "POKéMON can’t be the same.$"

gUnknown_085E9FC2:: @ 85E9FC2
	.string "No identical hold items.$"

gUnknown_085E9FDB:: @ 85E9FDB
	.string "The current is much too fast!$"

gUnknown_085E9FF9:: @ 85E9FF9
	.string "Do what with the MAIL?$"

gUnknown_085EA010:: @ 85EA010
	.string "Choose POKéMON or CANCEL.$"

gUnknown_085EA02A:: @ 85EA02A
	.string "Choose POKéMON and confirm.$"

gUnknown_085EA046:: @ 85EA046
	.string "Let’s enjoy cycling!$"

gUnknown_085EA05B:: @ 85EA05B
	.string "This is in use already.$"

gUnknown_085EA073:: @ 85EA073
	.string "{STR_VAR_1} is already holding\none {STR_VAR_2}.$"

gUnknown_085EA091:: @ 85EA091
	.string "No use.$"

gUnknown_085EA099:: @ 85EA099
	.string "ABLE$"

gUnknown_085EA09E:: @ 85EA09E
	.string "FIRST$"

gUnknown_085EA0A4:: @ 85EA0A4
	.string "SECOND$"

gUnknown_085EA0AB:: @ 85EA0AB
	.string "THIRD$"

gUnknown_085EA0B1:: @ 85EA0B1
	.string "ABLE$"

gUnknown_085EA0B6:: @ 85EA0B6
	.string "NOT ABLE$"

gUnknown_085EA0BF:: @ 85EA0BF
	.string "ABLE!$"

gUnknown_085EA0C5:: @ 85EA0C5
	.string "NOT ABLE!$"

gUnknown_085EA0CF:: @ 85EA0CF
	.string "LEARNED$"

gUnknown_085EA0D7:: @ 85EA0D7
	.string "HAVE$"

gUnknown_085EA0DC:: @ 85EA0DC
	.string "DON’T HAVE$"

gUnknown_085EA0E7:: @ 85EA0E7
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

gUnknown_085EA250:: @ 85EA250
	.string "The other TRAINER’s POKéMON\ncan’t be traded now.$"

	.align 2

gUnknown_085EA284:: @ 85EA284
	.string "The other TRAINER can’t accept\nthat POKéMON now.$"

	.align 2

gUnknown_085EA2B8:: @ 85EA2B8
	.string "You can’t trade with that\nTRAINER now.$"

	.align 2

gUnknown_085EA2E0:: @ 85EA2E0
	.string "That isn’t the type of POKéMON\nthat the other TRAINER wants.$"

	.align 2

gUnknown_085EA320:: @ 85EA320
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

gUnknown_085EA364:: @ 85EA364
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

gUnknown_085EA3C1:: @ 85EA3C1
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

gUnknown_085EA79D:: @ 85EA79D
	.string "DEL REGIST.$"

gUnknown_085EA7A9:: @ 85EA7A9
	.string "{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}$"

gText_Decorate:: @ 85EA7B1
	.string "DECORATE$"

gText_PutAway:: @ 85EA7BA
	.string "PUT AWAY$"

gText_Toss2:: @ 85EA7C3
	.string "TOSS$"

gText_Color161Shadow161:: @ 85EA7C8
	.string "{COLOR 161}{SHADOW 161}$"

gText_PutOutSelectedDecorItem:: @ 85EA7CF
	.string "Put out the selected decoration item.$"

gText_StoreChosenDecorInPC:: @ 85EA7F5
	.string "Store the chosen decoration in the PC.$"

gText_ThrowAwayUnwantedDecors:: @ 85EA81C
	.string "Throw away unwanted decorations.$"

gText_NoDecorations:: @ 85EA83D
	.string "There are no decorations.{PAUSE_UNTIL_PRESS}$"

gText_Desk:: @ 85EA859
	.string "DESK$"

gText_Chair:: @ 85EA85E
	.string "CHAIR$"

gText_Plant:: @ 85EA864
	.string "PLANT$"

gText_Ornament:: @ 85EA86A
	.string "ORNAMENT$"

gText_Mat:: @ 85EA873
	.string "MAT$"

gText_Poster:: @ 85EA877
	.string "POSTER$"

gText_Doll:: @ 85EA87E
	.string "DOLL$"

gText_Cushion:: @ 85EA883
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

gUnknown_085EA978:: @ 85EA978
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

gUnknown_085EAB0F:: @ 85EAB0F
	.string "TRISTAN$"

gUnknown_085EAB17:: @ 85EAB17
	.string "PHILIP$"

gUnknown_085EAB1E:: @ 85EAB1E
	.string "DENNIS$"

gUnknown_085EAB25:: @ 85EAB25
	.string "ROBERTO$"

gText_TurnOff:: @ 85EAB2D
	.string "TURN OFF$"

gText_Decoration:: @ 85EAB36
	.string "DECORATION$"

gText_ItemStorage:: @ 85EAB41
	.string "ITEM STORAGE$"

gText_Mailbox:: @ 85EAB4E
	.string "MAILBOX$"

gText_DepositItem:: @ 85EAB56
	.string "DEPOSIT ITEM$"

gText_WithdrawItem:: @ 85EAB63
	.string "WITHDRAW ITEM$"

gText_TossItem:: @ 85EAB71
	.string "TOSS ITEM$"

gText_StoreItemsInPC:: @ 85EAB7B
	.string "Store items in the PC.$"

gText_TakeOutItemsFromPC:: @ 85EAB92
	.string "Take out items from the PC.$"

gText_ThrowAwayItemsInPC:: @ 85EABAE
	.string "Throw away items stored in the PC.$"

gText_NoItems:: @ 85EABD1
	.string "There are no items.{PAUSE_UNTIL_PRESS}$"

gText_NoRoomInBag:: @ 85EABE7
	.string "There is no more\nroom in the BAG.$"

gText_WithdrawHowManyItems:: @ 85EAC09
	.string "Withdraw how many\n{STR_VAR_1}(s)?$"

gText_WithdrawXItems:: @ 85EAC22
	.string "Withdrew {STR_VAR_2}\n{STR_VAR_1}(s).$"

gText_Read:: @ 85EAC35
	.string "READ$"

gText_MoveToBag:: @ 85EAC3A
	.string "MOVE TO BAG$"

gText_Give2:: @ 85EAC46
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

gUnknown_085EAD37:: @ 85EAD37
	.string "PETALBURG$"

gUnknown_085EAD41:: @ 85EAD41
	.string "SLATEPORT$"

gUnknown_085EAD4B:: @ 85EAD4B
	.string "LITTLEROOT$"

gUnknown_085EAD56:: @ 85EAD56
	.string "LILYCOVE$"

gUnknown_085EAD5F:: @ 85EAD5F
	.string "DEWFORD$"

gUnknown_085EAD67:: @ 85EAD67
	.string "ENTER$"

gUnknown_085EAD6D:: @ 85EAD6D
	.string "INFO$"

gUnknown_085EAD72:: @ 85EAD72
	.string "What’s a CONTEST?$"

gUnknown_085EAD84:: @ 85EAD84
	.string "Types of CONTESTS$"

gUnknown_085EAD96:: @ 85EAD96
	.string "Ranks$"

gUnknown_085EAD9C:: @ 85EAD9C
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

gUnknown_085EADF9:: @ 85EADF9
	.string "DECORATION$"

gUnknown_085EAE04:: @ 85EAE04
	.string "PACK UP$"

gUnknown_085EAE0C:: @ 85EAE0C
	.string "COUNT$"

gUnknown_085EAE12:: @ 85EAE12
	.string "REGISTRY$"

gUnknown_085EAE1B:: @ 85EAE1B
	.string "INFORMATION$"

gUnknown_085EAE27:: @ 85EAE27
	.string "MACH$"

gUnknown_085EAE2C:: @ 85EAE2C
	.string "ACRO$"

gUnknown_085EAE31:: @ 85EAE31
	.string "PSN$"

gUnknown_085EAE35:: @ 85EAE35
	.string "PAR$"

gUnknown_085EAE39:: @ 85EAE39
	.string "SLP$"

gUnknown_085EAE3D:: @ 85EAE3D
	.string "BRN$"

gUnknown_085EAE41:: @ 85EAE41
	.string "FRZ$"

gUnknown_085EAE45:: @ 85EAE45
	.string "TOXIC$"

gUnknown_085EAE4B:: @ 85EAE4B
	.string "OK$"

gUnknown_085EAE4E:: @ 85EAE4E
	.string "QUIT$"

gUnknown_085EAE53:: @ 85EAE53
	.string "Saw it$"

gUnknown_085EAE5A:: @ 85EAE5A
	.string "Not yet$"

gText_Yes:: @ 85EAE62
	.string "YES$"

gText_No:: @ 85EAE66
	.string "NO$"

gUnknown_085EAE69:: @ 85EAE69
	.string "INFO$"

gUnknown_085EAE6E:: @ 85EAE6E
	.string "SINGLE BATTLE$"

gUnknown_085EAE7C:: @ 85EAE7C
	.string "DOUBLE BATTLE$"

gUnknown_085EAE8A:: @ 85EAE8A
	.string "MULTI BATTLE$"

gUnknown_085EAE97:: @ 85EAE97
	.string "MR. BRINEY$"

gUnknown_085EAEA2:: @ 85EAEA2
	.string "CHALLENGE$"

gUnknown_085EAEAC:: @ 85EAEAC
	.string "INFO$"

gText_Lv50:: @ 85EAEB1
	.string "LV. 50$"

gText_OpenLevel:: @ 85EAEB8
	.string "OPEN LEVEL$"

gUnknown_085EAEC3:: @ 85EAEC3
	.string "FRESH WATER{CLEAR_TO 0x48}¥200$"

gUnknown_085EAED6:: @ 85EAED6
	.string "SODA POP{CLEAR_TO 0x48}¥300$"

gUnknown_085EAEE6:: @ 85EAEE6
	.string "LEMONADE{CLEAR_TO 0x48}¥350$"

gUnknown_085EAEF6:: @ 85EAEF6
	.string "HOW TO RIDE$"

gUnknown_085EAF02:: @ 85EAF02
	.string "HOW TO TURN$"

gUnknown_085EAF0E:: @ 85EAF0E
	.string "SANDY SLOPES$"

gUnknown_085EAF1B:: @ 85EAF1B
	.string "WHEELIES$"

gUnknown_085EAF24:: @ 85EAF24
	.string "BUNNY-HOPS$"

gUnknown_085EAF2F:: @ 85EAF2F
	.string "JUMP$"

gUnknown_085EAF34:: @ 85EAF34
	.string "Satisfied$"

gUnknown_085EAF3E:: @ 85EAF3E
	.string "Dissatisfied$"

gUnknown_085EAF4B:: @ 85EAF4B
	.string "DEEPSEATOOTH$"

gUnknown_085EAF58:: @ 85EAF58
	.string "DEEPSEASCALE$"

gUnknown_085EAF65:: @ 85EAF65
	.string "BLUE FLUTE$"

gUnknown_085EAF70:: @ 85EAF70
	.string "YELLOW FLUTE$"

gUnknown_085EAF7D:: @ 85EAF7D
	.string "RED FLUTE$"

gUnknown_085EAF87:: @ 85EAF87
	.string "WHITE FLUTE$"

gUnknown_085EAF93:: @ 85EAF93
	.string "BLACK FLUTE$"

gUnknown_085EAF9F:: @ 85EAF9F
	.string "GLASS CHAIR$"

gUnknown_085EAFAB:: @ 85EAFAB
	.string "GLASS DESK$"

gUnknown_085EAFB6:: @ 85EAFB6
	.string "TREECKO DOLL 1,000 COINS$"

gUnknown_085EAFCF:: @ 85EAFCF
	.string "TORCHIC DOLL 1,000 COINS$"

gUnknown_085EAFE8:: @ 85EAFE8
	.string "MUDKIP DOLL   1,000 COINS$"

gUnknown_085EB002:: @ 85EB002
	.string "  50 COINS    ¥1,000$"

gUnknown_085EB017:: @ 85EB017
	.string "500 COINS  ¥10,000$"

gUnknown_085EB02A:: @ 85EB02A
	.string "Excellent$"

gUnknown_085EB034:: @ 85EB034
	.string "Not so good$"

gUnknown_085EB040:: @ 85EB040
	.string "RED SHARD$"

gUnknown_085EB04A:: @ 85EB04A
	.string "YELLOW SHARD$"

gUnknown_085EB057:: @ 85EB057
	.string "BLUE SHARD$"

gUnknown_085EB062:: @ 85EB062
	.string "GREEN SHARD$"

gText_BattleFrontier:: @ 85EB06E
	.string "BATTLE FRONTIER$"

gUnknown_085EB07E:: @ 85EB07E
	.string "Right$"

gUnknown_085EB084:: @ 85EB084
	.string "Left$"

gUnknown_085EB089:: @ 85EB089
	.string "TM32{CLEAR_TO 0x48}1,500 COINS$"

gUnknown_085EB09C:: @ 85EB09C
	.string "TM29{CLEAR_TO 0x48}3,500 COINS$"

gUnknown_085EB0AF:: @ 85EB0AF
	.string "TM35{CLEAR_TO 0x48}4,000 COINS$"

gUnknown_085EB0C2:: @ 85EB0C2
	.string "TM24{CLEAR_TO 0x48}4,000 COINS$"

gUnknown_085EB0D5:: @ 85EB0D5
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

gText_Normal:: @ 85EB105
	.string "NORMAL$"

gText_Super:: @ 85EB10C
	.string "SUPER$"

gText_Hyper:: @ 85EB112
	.string "HYPER$"

gText_Master:: @ 85EB118
	.string "MASTER$"

gText_Cool2:: @ 85EB11F
	.string "COOL$"

gText_Beauty2:: @ 85EB124
	.string "BEAUTY$"

gText_Cute2:: @ 85EB12B
	.string "CUTE$"

gText_Smart2:: @ 85EB130
	.string "SMART$"

gText_Tough2:: @ 85EB136
	.string "TOUGH$"

gText_Items:: @ 85EB13C
	.string "ITEMS$"

gText_Key_Items:: @ 85EB142
	.string "KEY ITEMS$"

gText_Poke_Balls:: @ 85EB14C
	.string "POKé BALLS$"

gText_TMs_Hms:: @ 85EB157
	.string "TMs & HMs$"

gText_Berries2:: @ 85EB161
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

gText_Opponent:: @ 85EB1A0
	.string "OPPONENT$"

gText_Tourney_Tree:: @ 85EB1A9
	.string "TOURNEY TREE$"

gText_ReadyToStart:: @ 85EB1B6
	.string "READY TO START$"

gText_NormalRank:: @ 85EB1C5
	.string "NORMAL RANK$"

gText_SuperRank:: @ 85EB1D1
	.string "SUPER RANK$"

gText_HyperRank:: @ 85EB1DC
	.string "HYPER RANK$"

gText_MasterRank:: @ 85EB1E7
	.string "MASTER RANK$"

gText_Single2:: @ 85EB1F3
	.string "SINGLE$"

gText_Double2:: @ 85EB1FA
	.string "DOUBLE$"

gText_Multi:: @ 85EB201
	.string "MULTI$"

gText_MultiLink:: @ 85EB207
	.string "MULTI-LINK$"

gText_BattleBag:: @ 85EB212
	.string "BATTLE BAG$"

gText_HeldItem:: @ 85EB21D
	.string "HELD ITEM$"

gText_LinkContest:: @ 85EB227
	.string "LINK CONTEST$"

gText_AboutE_Mode:: @ 85EB234
	.string "ABOUT E-MODE$"

gText_AboutG_Mode:: @ 85EB241
	.string "ABOUT G-MODE$"

gText_E_Mode:: @ 85EB24E
	.string "E-MODE$"

gText_G_Mode:: @ 85EB255
	.string "G-MODE$"

gText_MenuOptionPokedex:: @ 85EB25C
	.string "POKéDEX$"

gText_MenuOptionPokemon:: @ 85EB264
	.string "POKéMON$"

gText_MenuOptionBag:: @ 85EB26C
	.string "BAG$"

gText_MenuOptionPokenav:: @ 85EB270
	.string "POKéNAV$"

gUnknown_085EB278:: @ 85EB278
	.string "$"

gText_MenuOptionSave:: @ 85EB279
	.string "SAVE$"

gText_MenuOptionOption:: @ 85EB27E
	.string "OPTION$"

gText_MenuOptionExit:: @ 85EB285
	.string "EXIT$"

gUnknown_085EB28A:: @ 85EB28A
    .string "  "

gUnknown_085EB28C:: @ 85EB28C
	.string "5BP$"

gUnknown_085EB290:: @ 85EB290
	.string "10BP$"

gUnknown_085EB295:: @ 85EB295
	.string "15BP$"

gUnknown_085EB29A:: @ 85EB29A
	.string "RED TENT$"

gUnknown_085EB2A3:: @ 85EB2A3
	.string "BLUE TENT$"

gText_SouthernIsland:: @ 85EB2AD
	.string "SOUTHERN ISLAND$"

gText_BirthIsland:: @ 85EB2BD
	.string "BIRTH ISLAND$"

gText_FarawayIsland:: @ 85EB2CA
	.string "FARAWAY ISLAND$"

gText_NavelRock:: @ 85EB2D9
	.string "NAVEL ROCK$"

gUnknown_085EB2E4:: @ 85EB2E4
	.string "CLAW FOSSIL$"

gUnknown_085EB2F0:: @ 85EB2F0
	.string "ROOT FOSSIL$"

gUnknown_085EB2FC:: @ 85EB2FC
	.string "NO$"

gUnknown_085EB2FF:: @ 85EB2FF
	.string "I’ll battle now!$"

gUnknown_085EB310:: @ 85EB310
	.string "I won!$"

gUnknown_085EB317:: @ 85EB317
	.string "I lost!$"

gUnknown_085EB31F:: @ 85EB31F
	.string "I won’t tell.$"

gUnknown_085EB32D:: @ 85EB32D
	.string "NORMAL TAG MATCH$"

gUnknown_085EB33E:: @ 85EB33E
	.string "VARIETY TAG MATCH$"

gUnknown_085EB350:: @ 85EB350
	.string "UNIQUE TAG MATCH$"

gUnknown_085EB361:: @ 85EB361
	.string "EXPERT TAG MATCH$"

gUnknown_085EB372:: @ 85EB372
	.string "TRADE CENTER$"

gUnknown_085EB37F:: @ 85EB37F
	.string "COLOSSEUM$"

gUnknown_085EB389:: @ 85EB389
	.string "RECORD CORNER$"

gUnknown_085EB397:: @ 85EB397
	.string "BERRY CRUSH$"

gUnknown_085EB3A3:: @ 85EB3A3
	.string "$"

gUnknown_085EB3A4:: @ 85EB3A4
	.string "POKéMON JUMP$"

gUnknown_085EB3B1:: @ 85EB3B1
	.string "DODRIO BERRY-PICKING$"

gUnknown_085EB3C6:: @ 85EB3C6
	.string "BECOME LEADER$"

gUnknown_085EB3D4:: @ 85EB3D4
	.string "JOIN GROUP$"

gUnknown_085EB3DF:: @ 85EB3DF
	.string "TWO STYLES$"

gUnknown_085EB3EA:: @ 85EB3EA
	.string "LV. 50$"

gUnknown_085EB3F1:: @ 85EB3F1
	.string "OPEN LEVEL$"

gUnknown_085EB3FC:: @ 85EB3FC
	.string "{PKMN} TYPE & NO.$"

gUnknown_085EB40A:: @ 85EB40A
	.string "HOLD ITEMS$"

gUnknown_085EB415:: @ 85EB415
	.string "SYMBOLS$"

gUnknown_085EB41D:: @ 85EB41D
	.string "RECORD$"

gUnknown_085EB424:: @ 85EB424
	.string "BATTLE PTS$"

gUnknown_085EB42F:: @ 85EB42F
	.string "TOWER INFO$"

gUnknown_085EB43A:: @ 85EB43A
	.string "BATTLE {PKMN}$"

gUnknown_085EB444:: @ 85EB444
	.string "BATTLE SALON$"

gUnknown_085EB451:: @ 85EB451
	.string "MULTI-LINK$"

gUnknown_085EB45C:: @ 85EB45C
	.string "BATTLE RULES$"

gUnknown_085EB469:: @ 85EB469
	.string "JUDGE: MIND$"

gUnknown_085EB475:: @ 85EB475
	.string "JUDGE: SKILL$"

gUnknown_085EB482:: @ 85EB482
	.string "JUDGE: BODY$"

gUnknown_085EB48E:: @ 85EB48E
	.string "MATCHUP$"

gUnknown_085EB496:: @ 85EB496
	.string "TOURNEY TREE$"

gUnknown_085EB4A3:: @ 85EB4A3
	.string "DOUBLE KO$"

gUnknown_085EB4AD:: @ 85EB4AD
	.string "BASIC RULES$"

gUnknown_085EB4B9:: @ 85EB4B9
	.string "SWAP: PARTNER$"

gUnknown_085EB4C7:: @ 85EB4C7
	.string "SWAP: NUMBER$"

gUnknown_085EB4D4:: @ 85EB4D4
	.string "SWAP: NOTES$"

gUnknown_085EB4E0:: @ 85EB4E0
	.string "OPEN LEVEL$"

gUnknown_085EB4EB:: @ 85EB4EB
	.string "BATTLE BASICS$"

gUnknown_085EB4F9:: @ 85EB4F9
	.string "POKéMON NATURE$"

gUnknown_085EB508:: @ 85EB508
	.string "POKéMON MOVES$"

gUnknown_085EB516:: @ 85EB516
	.string "UNDERPOWERED$"

gUnknown_085EB523:: @ 85EB523
	.string "WHEN IN DANGER$"

gUnknown_085EB532:: @ 85EB532
	.string "PYRAMID: POKéMON$"

gUnknown_085EB543:: @ 85EB543
	.string "PYRAMID: TRAINERS$"

gUnknown_085EB555:: @ 85EB555
	.string "PYRAMID: MAZE$"

gUnknown_085EB563:: @ 85EB563
	.string "BATTLE BAG$"

gUnknown_085EB56E:: @ 85EB56E
	.string "POKéNAV AND BAG$"

gUnknown_085EB57E:: @ 85EB57E
	.string "HELD ITEMS$"

gUnknown_085EB589:: @ 85EB589
	.string "POKéMON ORDER$"

gUnknown_085EB597:: @ 85EB597
	.string "BATTLE POKéMON$"

gUnknown_085EB5A6:: @ 85EB5A6
	.string "BATTLE TRAINERS$"

gUnknown_085EB5B6:: @ 85EB5B6
	.string "GO ON$"

gUnknown_085EB5BC:: @ 85EB5BC
	.string "RECORD$"

gUnknown_085EB5C3:: @ 85EB5C3
	.string "REST$"

gUnknown_085EB5C8:: @ 85EB5C8
	.string "RETIRE$"

gText_99TimesPlus:: @ 85EB5CF
	.string "99 times +$"

gText_1MinutePlus:: @ 85EB5DA
	.string "1 minute +$"

gText_SpaceSeconds:: @ 85EB5E5
	.string " seconds$"

gText_SpaceTimes:: @ 85EB5EE
	.string " time(s)$"

gUnknown_085EB5F7:: @ 85EB5F7
	.string ".$"

gText_BigGuy:: @ 85EB5F9
	.string "Big guy$"

gText_BigGirl:: @ 85EB601
	.string "Big girl$"

gText_Son:: @ 85EB60A
	.string "son$"

gText_Daughter:: @ 85EB60E
	.string "daughter$"

gUnknown_085EB617:: @ 85EB617
	.string "BLUE FLUTE$"

gUnknown_085EB622:: @ 85EB622
	.string "YELLOW FLUTE$"

gUnknown_085EB62F:: @ 85EB62F
	.string "RED FLUTE$"

gUnknown_085EB639:: @ 85EB639
	.string "WHITE FLUTE$"

gUnknown_085EB645:: @ 85EB645
	.string "BLACK FLUTE$"

gUnknown_085EB651:: @ 85EB651
	.string "PRETTY CHAIR$"

gUnknown_085EB65E:: @ 85EB65E
	.string "PRETTY DESK$"

gUnknown_085EB66A:: @ 85EB66A
	.string "1F$"

gUnknown_085EB66D:: @ 85EB66D
	.string "2F$"

gUnknown_085EB670:: @ 85EB670
	.string "3F$"

gUnknown_085EB673:: @ 85EB673
	.string "4F$"

gUnknown_085EB676:: @ 85EB676
	.string "5F$"

gUnknown_085EB679:: @ 85EB679
	.string "6F$"

gUnknown_085EB67C:: @ 85EB67C
	.string "7F$"

gUnknown_085EB67F:: @ 85EB67F
	.string "8F$"

gUnknown_085EB682:: @ 85EB682
	.string "9F$"

gUnknown_085EB685:: @ 85EB685
	.string "10F$"

gUnknown_085EB689:: @ 85EB689
	.string "11F$"

gUnknown_085EB68D:: @ 85EB68D
	.string "B1F$"

gUnknown_085EB691:: @ 85EB691
	.string "B2F$"

gUnknown_085EB695:: @ 85EB695
	.string "B3F$"

gUnknown_085EB699:: @ 85EB699
	.string "B4F$"

gUnknown_085EB69D:: @ 85EB69D
	.string "ROOFTOP$"

gText_ElevatorNowOn:: @ 85EB6A5
	.string "Now on:$"

gText_BP:: @ 85EB6AD
	.string "BP$"

gUnknown_085EB6B0:: @ 85EB6B0
	.string "ENERGYPOWDER{CLEAR_TO 0x72}{SIZE 0}50$"

gUnknown_085EB6C5:: @ 85EB6C5
	.string "ENERGY ROOT{CLEAR_TO 0x72}{SIZE 0}80$"

gUnknown_085EB6D9:: @ 85EB6D9
	.string "HEAL POWDER{CLEAR_TO 0x72}{SIZE 0}50$"

gUnknown_085EB6ED:: @ 85EB6ED
	.string "REVIVAL HERB{CLEAR_TO 0x6C}{SIZE 0}300$"

gUnknown_085EB703:: @ 85EB703
	.string "PROTEIN{CLEAR_TO 0x63}{SIZE 0}1,000$"

gUnknown_085EB716:: @ 85EB716
	.string "IRON{CLEAR_TO 0x63}{SIZE 0}1,000$"

gUnknown_085EB726:: @ 85EB726
	.string "CARBOS{CLEAR_TO 0x63}{SIZE 0}1,000$"

gUnknown_085EB738:: @ 85EB738
	.string "CALCIUM{CLEAR_TO 0x63}{SIZE 0}1,000$"

gUnknown_085EB74B:: @ 85EB74B
	.string "ZINC{CLEAR_TO 0x63}{SIZE 0}1,000$"

gUnknown_085EB75B:: @ 85EB75B
	.string "HP UP{CLEAR_TO 0x63}{SIZE 0}1,000$"

gUnknown_085EB76C:: @ 85EB76C
	.string "PP UP{CLEAR_TO 0x63}{SIZE 0}3,000$"

gUnknown_085EB77D:: @ 85EB77D
	.string "RANKING HALL$"

gUnknown_085EB78A:: @ 85EB78A
	.string "EXCHANGE SERVICE$"

gText_LilycoveCity:: @ 85EB79B
	.string "LILYCOVE CITY$"

gText_SlateportCity:: @ 85EB7A9
	.string "SLATEPORT CITY$"

gText_CaveOfOrigin:: @ 85EB7B8
	.string "CAVE OF ORIGIN$"

gText_MtPyre:: @ 85EB7C7
	.string "MT. PYRE$"

gText_SkyPillar:: @ 85EB7D0
	.string "SKY PILLAR$"

gText_DontRemember:: @ 85EB7DB
	.string "Don’t remember$"

gText_Exit:: @ 85EB7EA
	.string "EXIT$"

gUnknown_085EB7EF:: @ 85EB7EF
	.string "Exit from the BOX?$"

gUnknown_085EB802:: @ 85EB802
	.string "What do you want to do?$"

gUnknown_085EB81A:: @ 85EB81A
	.string "Please pick a theme.$"

gUnknown_085EB82F:: @ 85EB82F
	.string "Pick the wallpaper.$"

gUnknown_085EB843:: @ 85EB843
	.string "{SPECIAL_F7 0x00} is selected.$"

gUnknown_085EB853:: @ 85EB853
	.string "Jump to which BOX?$"

gUnknown_085EB866:: @ 85EB866
	.string "Deposit in which BOX?$"

gUnknown_085EB87C:: @ 85EB87C
	.string "{SPECIAL_F7 0x00} was deposited.$"

gUnknown_085EB88E:: @ 85EB88E
	.string "The BOX is full.$"

gUnknown_085EB89F:: @ 85EB89F
	.string "Release this POKéMON?$"

gUnknown_085EB8B5:: @ 85EB8B5
	.string "{SPECIAL_F7 0x00} was released.$"

gUnknown_085EB8C6:: @ 85EB8C6
	.string "Bye-bye, {SPECIAL_F7 0x00}!$"

gUnknown_085EB8D3:: @ 85EB8D3
	.string "Mark your POKéMON.$"

gUnknown_085EB8E6:: @ 85EB8E6
	.string "That’s your last POKéMON!$"

gUnknown_085EB900:: @ 85EB900
	.string "Your party’s full!$"

gUnknown_085EB913:: @ 85EB913
	.string "You’re holding a POKéMON!$"

gUnknown_085EB92D:: @ 85EB92D
	.string "Which one will you take?$"

gUnknown_085EB946:: @ 85EB946
	.string "You can’t release an EGG.$"

gUnknown_085EB960:: @ 85EB960
	.string "Continue BOX operations?$"

gUnknown_085EB979:: @ 85EB979
	.string "{SPECIAL_F7 0x00} came back!$"

gUnknown_085EB987:: @ 85EB987
	.string "Was it worried about you?$"

gUnknown_085EB9A1:: @ 85EB9A1
	.string "… … … … !$"

gUnknown_085EB9AB:: @ 85EB9AB
	.string "Please remove the MAIL.$"

gUnknown_085EB9C3:: @ 85EB9C3
	.string "GIVE to a POKéMON?$"

gUnknown_085EB9D6:: @ 85EB9D6
	.string "Placed item in the BAG.$"

gUnknown_085EB9EE:: @ 85EB9EE
	.string "The BAG is full.$"

gUnknown_085EB9FF:: @ 85EB9FF
	.string "Put this item in the BAG?$"

gUnknown_085EBA19:: @ 85EBA19
	.string "{SPECIAL_F7 0x00} is now held.$"

gUnknown_085EBA29:: @ 85EBA29
	.string "Changed to {SPECIAL_F7 0x00}.$"

gUnknown_085EBA38:: @ 85EBA38
	.string "MAIL can’t be stored!$"

gUnknown_085EBA4E:: @ 85EBA4E
	.string "CANCEL$"

gUnknown_085EBA55:: @ 85EBA55
	.string "STORE$"

gUnknown_085EBA5B:: @ 85EBA5B
	.string "WITHDRAW$"

gUnknown_085EBA64:: @ 85EBA64
	.string "SHIFT$"

gUnknown_085EBA6A:: @ 85EBA6A
	.string "MOVE$"

gUnknown_085EBA6F:: @ 85EBA6F
	.string "PLACE$"

gUnknown_085EBA75:: @ 85EBA75
	.string "SUMMARY$"

gUnknown_085EBA7D:: @ 85EBA7D
	.string "RELEASE$"

gUnknown_085EBA85:: @ 85EBA85
	.string "MARK$"

gUnknown_085EBA8A:: @ 85EBA8A
	.string "NAME$"

gUnknown_085EBA8F:: @ 85EBA8F
	.string "JUMP$"

gUnknown_085EBA94:: @ 85EBA94
	.string "WALLPAPER$"

gUnknown_085EBA9E:: @ 85EBA9E
	.string "TAKE$"

gUnknown_085EBAA3:: @ 85EBAA3
	.string "GIVE$"

gUnknown_085EBAA8:: @ 85EBAA8
	.string "SWITCH$"

gUnknown_085EBAAF:: @ 85EBAAF
	.string "BAG$"

gUnknown_085EBAB3:: @ 85EBAB3
	.string "INFO$"

gUnknown_085EBAB8:: @ 85EBAB8
	.string "SCENERY 1$"

gUnknown_085EBAC2:: @ 85EBAC2
	.string "SCENERY 2$"

gUnknown_085EBACC:: @ 85EBACC
	.string "SCENERY 3$"

gUnknown_085EBAD6:: @ 85EBAD6
	.string "ETCETERA$"

gUnknown_085EBADF:: @ 85EBADF
	.string "FRIENDS$"

gUnknown_085EBAE7:: @ 85EBAE7
	.string "FOREST$"

gUnknown_085EBAEE:: @ 85EBAEE
	.string "CITY$"

gUnknown_085EBAF3:: @ 85EBAF3
	.string "DESERT$"

gUnknown_085EBAFA:: @ 85EBAFA
	.string "SAVANNA$"

gUnknown_085EBB02:: @ 85EBB02
	.string "CRAG$"

gUnknown_085EBB07:: @ 85EBB07
	.string "VOLCANO$"

gUnknown_085EBB0F:: @ 85EBB0F
	.string "SNOW$"

gUnknown_085EBB14:: @ 85EBB14
	.string "CAVE$"

gUnknown_085EBB19:: @ 85EBB19
	.string "BEACH$"

gUnknown_085EBB1F:: @ 85EBB1F
	.string "SEAFLOOR$"

gUnknown_085EBB28:: @ 85EBB28
	.string "RIVER$"

gUnknown_085EBB2E:: @ 85EBB2E
	.string "SKY$"

gUnknown_085EBB32:: @ 85EBB32
	.string "POLKA-DOT$"

gUnknown_085EBB3C:: @ 85EBB3C
	.string "POKéCENTER$"

gUnknown_085EBB47:: @ 85EBB47
	.string "MACHINE$"

gUnknown_085EBB4F:: @ 85EBB4F
	.string "SIMPLE$"

gUnknown_085EBB56:: @ 85EBB56
	.string "What would you like to do?$"

gUnknown_085EBB71:: @ 85EBB71
	.string "WITHDRAW POKéMON$"

gUnknown_085EBB82:: @ 85EBB82
	.string "DEPOSIT POKéMON$"

gUnknown_085EBB92:: @ 85EBB92
	.string "MOVE POKéMON$"

gUnknown_085EBB9F:: @ 85EBB9F
	.string "MOVE ITEMS$"

gUnknown_085EBBAA:: @ 85EBBAA
	.string "SEE YA!$"

gUnknown_085EBBB2:: @ 85EBBB2
	.string "Move POKéMON stored in BOXES to\nyour party.$"

gUnknown_085EBBDE:: @ 85EBBDE
	.string "Store POKéMON in your party in BOXES.$"

gUnknown_085EBC04:: @ 85EBC04
	.string "Organize the POKéMON in BOXES and\nin your party.$"

gUnknown_085EBC35:: @ 85EBC35
	.string "Move items held by any POKéMON\nin a BOX or your party.$"

gUnknown_085EBC6C:: @ 85EBC6C
	.string "Return to the previous menu.$"

gText_JustOnePkmn:: @ 85EBC89
	.string "There is just one POKéMON with you.$"

gText_PartyFull:: @ 85EBCAD
	.string "Your party is full!$"

gText_Box:: @ 85EBCC1
	.string "BOX$"

gUnknown_085EBCC5:: @ 85EBCC5
	.string "Check the map of the HOENN region.$"

gUnknown_085EBCE8:: @ 85EBCE8
	.string "Check POKéMON in detail.$"

gUnknown_085EBD01:: @ 85EBD01
	.string "Call a registered TRAINER.$"

gUnknown_085EBD1C:: @ 85EBD1C
	.string "Check obtained RIBBONS.$"

gUnknown_085EBD34:: @ 85EBD34
	.string "Put away the POKéNAV.$"

gText_NoRibbonWinners:: @ 85EBD4A
	.string "There are no RIBBON winners.$"

gUnknown_085EBD67:: @ 85EBD67
	.string "No TRAINERS are registered.$"

gUnknown_085EBD83:: @ 85EBD83
	.string "Check party POKéMON in detail.$"

gUnknown_085EBDA2:: @ 85EBDA2
	.string "Check all POKéMON in detail.$"

gUnknown_085EBDBF:: @ 85EBDBF
	.string "Return to the POKéNAV menu.$"

gUnknown_085EBDDB:: @ 85EBDDB
	.string "Find cool POKéMON.$"

gUnknown_085EBDEE:: @ 85EBDEE
	.string "Find beautiful POKéMON.$"

gUnknown_085EBE06:: @ 85EBE06
	.string "Find cute POKéMON.$"

gUnknown_085EBE19:: @ 85EBE19
	.string "Find smart POKéMON.$"

gUnknown_085EBE2D:: @ 85EBE2D
	.string "Find tough POKéMON.$"

gUnknown_085EBE41:: @ 85EBE41
	.string "Return to the CONDITION menu.$"

gText_NumberRegistered:: @ 85EBE5F
	.string "No. registered$"

gText_NumberOfBattles:: @ 85EBE6E
	.string "No. of battles$"

gUnknown_085EBE7D:: @ 85EBE7D
	.string "DETAIL$"

gUnknown_085EBE84:: @ 85EBE84
	.string "CALL$"

gUnknown_085EBE89:: @ 85EBE89
	.string "EXIT$"

gUnknown_085EBE8E:: @ 85EBE8E
	.string "Can’t call opponent here.$"

gUnknown_085EBEA8:: @ 85EBEA8
	.string "STRATEGY$"

gUnknown_085EBEB1:: @ 85EBEB1
	.string "TRAINER’S POKéMON$"

gUnknown_085EBEC3:: @ 85EBEC3
	.string "SELF-INTRODUCTION$"

gUnknown_085EBED5:: @ 85EBED5
	.string "{CLEAR 0x80}$"

gUnknown_085EBED9:: @ 85EBED9
	.string "{UNK_CTRL_F800}ZOOM {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBEE9:: @ 85EBEE9
	.string "{UNK_CTRL_F800}FULL {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBEF9:: @ 85EBEF9
	.string "{UNK_CTRL_F800}CONDITION {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF0E:: @ 85EBF0E
	.string "{UNK_CTRL_F800}MARKINGS {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF22:: @ 85EBF22
	.string "{UNK_CTRL_F800}SELECT MARK {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF39:: @ 85EBF39
	.string "{UNK_CTRL_F800}MENU {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF49:: @ 85EBF49
	.string "{UNK_CTRL_F800}OK {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF57:: @ 85EBF57
	.string "{UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF60:: @ 85EBF60
	.string "{UNK_CTRL_F800}RIBBONS {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF73:: @ 85EBF73
	.string "{UNK_CTRL_F800}CHECK {UNK_CTRL_F801}CANCEL$"

gUnknown_085EBF84:: @ 85EBF84
	.string "{UNK_CTRL_F801}CANCEL$"

gText_NatureSlash:: @ 85EBF8D
	.string "NATURE/$"

gText_TrainerCloseBy:: @ 85EBF95
	.string "That TRAINER is close by.\nTalk to the TRAINER in person!$"

gText_InParty:: @ 85EBFCE
	.string "IN PARTY$"

gText_Number2:: @ 85EBFD7
	.string "No. $"

gUnknown_085EBFDC:: @ 85EBFDC
	.string "RIBBONS$"

gUnknown_085EBFE4:: @ 85EBFE4
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}$"

gUnknown_085EBFF6:: @ 85EBFF6
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}$"

gUnknown_085EC008:: @ 85EC008
	.string "{SPECIAL_F7 0x00}/{LV}{SPECIAL_F7 0x01}$"

gText_Unknown:: @ 85EC00F
	.string "UNKNOWN$"

gUnknown_085EC017:: @ 85EC017
	.string "CALL$"

gUnknown_085EC01C:: @ 85EC01C
	.string "CHECK$"

gUnknown_085EC022:: @ 85EC022
	.string "CANCEL$"

gText_NumberF700:: @ 85EC029
	.string "No. {SPECIAL_F7 0x00}$"

gText_RibbonsF700:: @ 85EC030
	.string "RIBBONS {SPECIAL_F7 0x00}$"

gUnknown_085EC03B:: @ 85EC03B
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}$"

gUnknown_085EC04F:: @ 85EC04F
	.string "{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}$"

gUnknown_085EC063:: @ 85EC063
	.string "{SPECIAL_F7 0x00}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}$"

gUnknown_085EC06C:: @ 85EC06C
	.string "Combine four words or phrases$"

gUnknown_085EC08A:: @ 85EC08A
	.string "and make your profile.$"

gUnknown_085EC0A1:: @ 85EC0A1
	.string "Combine six words or phrases$"

gUnknown_085EC0BE:: @ 85EC0BE
	.string "and make a message.$"

gUnknown_085EC0D2:: @ 85EC0D2
	.string "Find words that describe your$"

gUnknown_085EC0F0:: @ 85EC0F0
	.string "feelings right now.$"

gUnknown_085EC104:: @ 85EC104
	.string "With four phrases,$"

gUnknown_085EC117:: @ 85EC117
	.string "Combine nine words or phrases$"

gUnknown_085EC135:: @ 85EC135
	.string "and make a message.$"

gUnknown_085EC149:: @ 85EC149
	.string "Change just one word or phrase$"

gUnknown_085EC168:: @ 85EC168
	.string "and improve the BARD’s song.$"

gUnknown_085EC185:: @ 85EC185
	.string "Your profile$"

gUnknown_085EC192:: @ 85EC192
	.string "Your feeling at the battle’s start$"

gUnknown_085EC1B5:: @ 85EC1B5
	.string "What you say if you win a battle$"

gUnknown_085EC1D6:: @ 85EC1D6
	.string "What you say if you lose a battle$"

gUnknown_085EC1F8:: @ 85EC1F8
	.string "The answer$"

gUnknown_085EC203:: @ 85EC203
	.string "The MAIL message$"

gUnknown_085EC214:: @ 85EC214
	.string "The MAIL salutation$"

gUnknown_085EC228:: @ 85EC228
	.string "The new song$"

gUnknown_085EC235:: @ 85EC235
	.string "Combine two words or phrases$"

gUnknown_085EC252:: @ 85EC252
	.string "and make a trendy saying.$"

gUnknown_085EC26C:: @ 85EC26C
	.string "The trendy saying$"

gUnknown_085EC27E:: @ 85EC27E
	.string "is as shown. Okay?$"

gUnknown_085EC291:: @ 85EC291
	.string "Combine two words or phrases$"

gUnknown_085EC2AE:: @ 85EC2AE
	.string "to teach her a good saying.$"

gUnknown_085EC2CA:: @ 85EC2CA
	.string "Find words which fit$"

gUnknown_085EC2DF:: @ 85EC2DF
	.string "the TRAINER’s image.$"

gUnknown_085EC2F4:: @ 85EC2F4
	.string "The image:$"

gUnknown_085EC2FF:: @ 85EC2FF
	.string "Out of the listed choices,$"

gUnknown_085EC31A:: @ 85EC31A
	.string "select the answer to the quiz!$"

gUnknown_085EC339:: @ 85EC339
	.string "and create a quiz!$"

gUnknown_085EC34C:: @ 85EC34C
	.string "Pick a word or phrase and$"

gUnknown_085EC366:: @ 85EC366
	.string "set the quiz answer.$"

gUnknown_085EC37B:: @ 85EC37B
	.string "The answer:$"

gUnknown_085EC387:: @ 85EC387
	.string "The quiz:$"

gUnknown_085EC391:: @ 85EC391
	.string "Apprentice’s phrase:$"

gText_QuitEditing:: @ 85EC3A6
	.string "Quit editing?$"

gText_StopGivingPkmnMail:: @ 85EC3B4
	.string "Stop giving the POKéMON MAIL?$"

gUnknown_085EC3D2:: @ 85EC3D2
	.string "and fill out the questionnaire.$"

gUnknown_085EC3F2:: @ 85EC3F2
	.string "Let’s reply to the interview!$"

gText_AllTextBeingEditedWill:: @ 85EC410
	.string "All the text being edited will$"

gText_BeDeletedThatOkay:: @ 85EC42F
	.string "be deleted. Is that okay?$"

gUnknown_085EC449:: @ 85EC449
	.string "Quit editing?$"

gUnknown_085EC457:: @ 85EC457
	.string "The edited text will not be saved.$"

gUnknown_085EC47A:: @ 85EC47A
	.string "Is that okay?$"

gUnknown_085EC488:: @ 85EC488
	.string "Please enter a phrase or word.$"

gUnknown_085EC4A7:: @ 85EC4A7
	.string "The entire text can’t be deleted.$"

gText_OnlyOnePhrase:: @ 85EC4C9
	.string "Only one phrase may be changed.$"

gText_OriginalSongWillBeUsed:: @ 85EC4E9
	.string "The original song will be used.$"

gUnknown_085EC509:: @ 85EC509
	.string "That’s trendy already!$"

gText_CombineTwoWordsOrPhrases:: @ 85EC520
	.string "Combine two words or phrases.$"

gUnknown_085EC53E:: @ 85EC53E
	.string "Quit giving information?$"

gUnknown_085EC557:: @ 85EC557
	.string "Stop giving the POKéMON MAIL?$"

gUnknown_085EC575:: @ 85EC575
	.string "Create a quiz!$"

gUnknown_085EC584:: @ 85EC584
	.string "Set the answer!$"

gUnknown_085EC594:: @ 85EC594
	.string "Cancel the selection?$"

gUnknown_085EC5AA:: @ 85EC5AA
	.string "PROFILE$"

gUnknown_085EC5B2:: @ 85EC5B2
	.string "At the battle’s start:$"

gUnknown_085EC5C9:: @ 85EC5C9
	.string "Upon winning a battle:$"

gUnknown_085EC5E0:: @ 85EC5E0
	.string "Upon losing a battle:$"

gUnknown_085EC5F6:: @ 85EC5F6
	.string "The BARD’s Song$"

gUnknown_085EC606:: @ 85EC606
	.string "What’s hip and happening?$"

gUnknown_085EC620:: @ 85EC620
	.string "Interview$"

gUnknown_085EC62A:: @ 85EC62A
	.string "Good saying$"

gUnknown_085EC636:: @ 85EC636
	.string "Fan’s question$"

gUnknown_085EC645:: @ 85EC645
	.string "クイズの こたえは？$" @ "kuizuno kotaeha?" ("The quiz's answer is?" in Japanese)

gUnknown_085EC650:: @ 85EC650
	.string "Apprentice’s phrase$"

gUnknown_085EC664:: @ 85EC664
	.string "QUESTIONNAIRE$"

gText_YouCannotQuitHere:: @ 85EC672
	.string "You cannot quit here.$"

gText_SectionMustBeCompleted:: @ 85EC688
	.string "This section must be completed.$"

gText_F700sQuiz:: @ 85EC6A8
	.string "{SPECIAL_F7 0x00}’s quiz$"

gText_Lady:: @ 85EC6B2
	.string "Lady$"

gUnknown_085EC6B7:: @ 85EC6B7
	.string "After you have read the quiz$"

gUnknown_085EC6D4:: @ 85EC6D4
	.string "question, press the A Button.$"

gUnknown_085EC6F2:: @ 85EC6F2
	.string "The quiz answer is?$"

gText_LikeToQuitQuiz:: @ 85EC706
	.string "Would you like to quit this quiz$"

gText_ChallengeQuestionMark:: @ 85EC727
	.string "challenge?$"

gUnknown_085EC732:: @ 85EC732
	.string "Is this quiz OK?$"

gText_CreateAQuiz:: @ 85EC743
	.string "Create a quiz!$"

gText_SelectTheAnswer:: @ 85EC752
	.string "Select the answer!$"

gText_LyricsCantBeDeleted:: @ 85EC765
	.string "The lyrics can’t be deleted.$"

gText_PokemonLeague:: @ 85EC782
	.string "POKéMON LEAGUE$"

gText_PokemonCenter:: @ 85EC791
	.string "POKéMON CENTER$"

gText_GetsAPokeBlockQuestion:: @ 85EC7A0
	.string " gets a {POKEBLOCK}?$"

gUnknown_085EC7AF:: @ 85EC7AF
	.string "Coolness $"

gUnknown_085EC7B9:: @ 85EC7B9
	.string "Beauty $"

gUnknown_085EC7C1:: @ 85EC7C1
	.string "Cuteness $"

gUnknown_085EC7CB:: @ 85EC7CB
	.string "Smartness $"

gUnknown_085EC7D6:: @ 85EC7D6
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

gUnknown_085ECB8D:: @ 85ECB8D
	.string "0 pts$"

gUnknown_085ECB93:: @ 85ECB93
	.string "10 pts$"

gUnknown_085ECB9A:: @ 85ECB9A
	.string "20 pts$"

gUnknown_085ECBA1:: @ 85ECBA1
	.string "30 pts$"

gUnknown_085ECBA8:: @ 85ECBA8
	.string "40 pts$"

gUnknown_085ECBAF:: @ 85ECBAF
	.string "50 pts$"

gUnknown_085ECBB6:: @ 85ECBB6
	.string "60 pts$"

gUnknown_085ECBBD:: @ 85ECBBD
	.string "70 pts$"

gUnknown_085ECBC4:: @ 85ECBC4
	.string "80 pts$"

gUnknown_085ECBCB:: @ 85ECBCB
	.string "90 pts$"

gUnknown_085ECBD2:: @ 85ECBD2
	.string "100 pts$"

gUnknown_085ECBDA:: @ 85ECBDA
	.string "?$"

gUnknown_085ECBDC:: @ 85ECBDC
	.string "KISS POSTER{CLEAR_TO 0x5E}16BP$"

gUnknown_085ECBEF:: @ 85ECBEF
	.string "KISS CUSHION{CLEAR_TO 0x5E}32BP$"

gUnknown_085ECC03:: @ 85ECC03
	.string "SMOOCHUM DOLL{CLEAR_TO 0x5E}32BP$"

gUnknown_085ECC18:: @ 85ECC18
	.string "TOGEPI DOLL{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECC2B:: @ 85ECC2B
	.string "MEOWTH DOLL{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECC3E:: @ 85ECC3E
	.string "CLEFAIRY DOLL{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECC53:: @ 85ECC53
	.string "DITTO DOLL{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECC65:: @ 85ECC65
	.string "CYNDAQUIL DOLL{CLEAR_TO 0x5E}80BP$"

gUnknown_085ECC7B:: @ 85ECC7B
	.string "CHIKORITA DOLL{CLEAR_TO 0x5E}80BP$"

gUnknown_085ECC91:: @ 85ECC91
	.string "TOTODILE DOLL{CLEAR_TO 0x5E}80BP$"

gUnknown_085ECCA6:: @ 85ECCA6
	.string "LAPRAS DOLL{CLEAR_TO 0x58}128BP$"

gUnknown_085ECCBA:: @ 85ECCBA
	.string "SNORLAX DOLL{CLEAR_TO 0x58}128BP$"

gUnknown_085ECCCF:: @ 85ECCCF
	.string "VENUSAUR DOLL{CLEAR_TO 0x58}256BP$"

gUnknown_085ECCE5:: @ 85ECCE5
	.string "CHARIZARD DOLL{CLEAR_TO 0x58}256BP$"

gUnknown_085ECCFC:: @ 85ECCFC
	.string "BLASTOISE DOLL{CLEAR_TO 0x58}256BP$"

gUnknown_085ECD13:: @ 85ECD13
	.string "PROTEIN{CLEAR_TO 0x64}1BP$"

gUnknown_085ECD21:: @ 85ECD21
	.string "CALCIUM{CLEAR_TO 0x64}1BP$"

gUnknown_085ECD2F:: @ 85ECD2F
	.string "IRON{CLEAR_TO 0x64}1BP$"

gUnknown_085ECD3A:: @ 85ECD3A
	.string "ZINC{CLEAR_TO 0x64}1BP$"

gUnknown_085ECD45:: @ 85ECD45
	.string "CARBOS{CLEAR_TO 0x64}1BP$"

gUnknown_085ECD52:: @ 85ECD52
	.string "HP UP{CLEAR_TO 0x64}1BP$"

gUnknown_085ECD5E:: @ 85ECD5E
	.string "LEFTOVERS{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECD6F:: @ 85ECD6F
	.string "WHITE HERB{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECD81:: @ 85ECD81
	.string "QUICK CLAW{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECD93:: @ 85ECD93
	.string "MENTAL HERB{CLEAR_TO 0x5E}48BP$"

gUnknown_085ECDA6:: @ 85ECDA6
	.string "BRIGHTPOWDER{CLEAR_TO 0x5E}64BP$"

gUnknown_085ECDBA:: @ 85ECDBA
	.string "CHOICE BAND{CLEAR_TO 0x5E}64BP$"

gUnknown_085ECDCD:: @ 85ECDCD
	.string "KING’S ROCK{CLEAR_TO 0x5E}64BP$"

gUnknown_085ECDE0:: @ 85ECDE0
	.string "FOCUS BAND{CLEAR_TO 0x5E}64BP$"

gUnknown_085ECDF2:: @ 85ECDF2
	.string "SCOPE LENS{CLEAR_TO 0x5E}64BP$"

gUnknown_085ECE04:: @ 85ECE04
	.string "SOFTBOILED{CLEAR_TO 0x4E}16BP$"

gUnknown_085ECE16:: @ 85ECE16
	.string "SEISMIC TOSS{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECE2A:: @ 85ECE2A
	.string "DREAM EATER{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECE3D:: @ 85ECE3D
	.string "MEGA PUNCH{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECE4F:: @ 85ECE4F
	.string "MEGA KICK{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECE60:: @ 85ECE60
	.string "BODY SLAM{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECE71:: @ 85ECE71
	.string "ROCK SLIDE{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECE83:: @ 85ECE83
	.string "COUNTER{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECE92:: @ 85ECE92
	.string "THUNDER WAVE{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECEA6:: @ 85ECEA6
	.string "SWORDS DANCE{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECEBA:: @ 85ECEBA
	.string "DEFENSE CURL{CLEAR_TO 0x4E}16BP$"

gUnknown_085ECECE:: @ 85ECECE
	.string "SNORE{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECEDB:: @ 85ECEDB
	.string "MUD-SLAP{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECEEB:: @ 85ECEEB
	.string "SWIFT{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECEF8:: @ 85ECEF8
	.string "ICY WIND{CLEAR_TO 0x4E}24BP$"

gUnknown_085ECF08:: @ 85ECF08
	.string "ENDURE{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECF16:: @ 85ECF16
	.string "PSYCH UP{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECF26:: @ 85ECF26
	.string "ICE PUNCH{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECF37:: @ 85ECF37
	.string "THUNDERPUNCH{CLEAR_TO 0x4E}48BP$"

gUnknown_085ECF4B:: @ 85ECF4B
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

gUnknown_085ECF84:: @ 85ECF84
	.string "¥$"

gText_TrainerCardPokedex:: @ 85ECF86
	.string "POKéDEX$"

gText_EmptyString6:: @ 85ECF8E
	.string "$"

gText_Colon2:: @ 85ECF8F
	.string ":$"

gUnknown_085ECF91:: @ 85ECF91
	.string " points$"

gText_TrainerCardTime:: @ 85ECF99
	.string "TIME$"

gUnknown_085ECF9E:: @ 85ECF9E
	.string "ゲ-ムポイント$" @ "geemupointo" ("game point" in Japanese)

gText_Var1sTrainerCard:: @ 85ECFA6
	.string "{STR_VAR_1}’s TRAINER CARD$"

gText_HallOfFameDebut:: @ 85ECFB8
	.string "HALL OF FAME DEBUT  $"

gUnknown_085ECFCD:: @ 85ECFCD
	.string "LINK BATTLES$"

gUnknown_085ECFDA:: @ 85ECFDA
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

gText_BattleTower2:: @ 85ED104
	.string "BATTLE TOWER$"

gText_BattleDome:: @ 85ED111
	.string "BATTLE DOME$"

gText_BattlePalace:: @ 85ED11D
	.string "BATTLE PALACE$"

gText_BattleFactory:: @ 85ED12B
	.string "BATTLE FACTORY$"

gText_BattleArena:: @ 85ED13A
	.string "BATTLE ARENA$"

gText_BattlePike:: @ 85ED147
	.string "BATTLE PIKE$"

gText_BattlePyramid:: @ 85ED153
	.string "BATTLE PYRAMID$"

	.align 2

gUnknown_085ED164:: @ 85ED164
	.string "{STR_VAR_1} SINGLE$"

	.align 2

gUnknown_085ED170:: @ 85ED170
	.string "{STR_VAR_1} DOUBLE$"

	.align 2

gUnknown_085ED17C:: @ 85ED17C
	.string "{STR_VAR_1} MULTI$"

	.align 2

gUnknown_085ED188:: @ 85ED188
	.string "{STR_VAR_1} LINK$"

	.align 2

gUnknown_085ED190:: @ 85ED190
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

gUnknown_085ED222:: @ 85ED222
	.string "{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}$"

gText_HighlightDarkGrey:: @ 85ED228
	.string "{HIGHLIGHT DARK_GREY}$"

gUnknown_085ED22C:: @ 85ED22C
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

gUnknown_085ED2CF:: @ 85ED2CF
	.string "{SPECIAL_F7 0x00}の{SPECIAL_F7 0x01}ひきめ:$" @ "{SPECIAL_F7 0x00}'s {SPECIAL_F7 0x01}hikime"

gUnknown_085ED2D9:: @ 85ED2D9
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

gUnknown_085ED453:: @ 85ED453
	.string "Attack the weak points!$"

gUnknown_085ED46B:: @ 85ED46B
	.string "Ultimate STEEL POKéMON.$"

gUnknown_085ED483:: @ 85ED483
	.string "I’d climb even waterfalls$"

gUnknown_085ED49D:: @ 85ED49D
	.string "to find a rare stone!$"

gUnknown_085ED4B3:: @ 85ED4B3
	.string "I’m the strongest and most$"

gUnknown_085ED4CE:: @ 85ED4CE
	.string "energetic after all!$"

gUnknown_085ED4E3:: @ 85ED4E3
	.string "Battle with knowledge!$"

gUnknown_085ED4FA:: @ 85ED4FA
	.string "I will use various POKéMON.$"

gUnknown_085ED516:: @ 85ED516
	.string "I’ll be a better POKéMON$"

gUnknown_085ED52F:: @ 85ED52F
	.string "prof than my father is!$"

gUnknown_085ED547:: @ 85ED547
	.string "I’m not so good at battles.$"

gUnknown_085ED563:: @ 85ED563
	.string "I’ll use any POKéMON!$"

gUnknown_085ED579:: @ 85ED579
	.string "My POKéMON and I help$"

gUnknown_085ED58F:: @ 85ED58F
	.string "my father’s research.$"

gText_HatchedFromEgg:: @ 85ED5A5
	.string "{STR_VAR_1} hatched from the EGG!$"

gText_NickHatchPrompt:: @ 85ED5BE
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

gUnknown_085ED92A:: @ 85ED92A
	.string "CANCEL$"

gUnknown_085ED931:: @ 85ED931
	.string "$"

gUnknown_085ED932:: @ 85ED932
	.string "Check BATTLE FRONTIER MAP.$"

gUnknown_085ED94D:: @ 85ED94D
	.string "Check TRAINER CARD.$"

gUnknown_085ED961:: @ 85ED961
	.string "View recorded battle.$"

gUnknown_085ED977:: @ 85ED977
	.string "Put away the FRONTIER PASS.$"

gUnknown_085ED993:: @ 85ED993
	.string "Your current Battle Points.$"

gUnknown_085ED9AF:: @ 85ED9AF
	.string "Your collected Symbols.$"

gUnknown_085ED9C7:: @ 85ED9C7
	.string "Battle Tower - Ability Symbol$"

gUnknown_085ED9E5:: @ 85ED9E5
	.string "Battle Dome - Tactics Symbol$"

gUnknown_085EDA02:: @ 85EDA02
	.string "Battle Palace - Spirits Symbol$"

gUnknown_085EDA21:: @ 85EDA21
	.string "Battle Arena - Guts Symbol$"

gUnknown_085EDA3C:: @ 85EDA3C
	.string "Battle Factory - Knowledge Symbol$"

gUnknown_085EDA5E:: @ 85EDA5E
	.string "Battle Pike - Luck Symbol$"

gUnknown_085EDA78:: @ 85EDA78
	.string "Battle Pyramid - Brave Symbol$"

gUnknown_085EDA96:: @ 85EDA96
	.string "There is no Battle Record.$"

gUnknown_085EDAB1:: @ 85EDAB1
	.string "BATTLE TOWER$"

gUnknown_085EDABE:: @ 85EDABE
	.string "BATTLE DOME$"

gUnknown_085EDACA:: @ 85EDACA
	.string "BATTLE PALACE$"

gUnknown_085EDAD8:: @ 85EDAD8
	.string "BATTLE ARENA$"

gUnknown_085EDAE5:: @ 85EDAE5
	.string "BATTLE FACTORY$"

gUnknown_085EDAF4:: @ 85EDAF4
	.string "BATTLE PIKE$"

gUnknown_085EDB00:: @ 85EDB00
	.string "BATTLE PYRAMID$"

gUnknown_085EDB0F:: @ 85EDB0F
	.string "KO opponents and aim for the top!\nYour ability will be tested.$"

gUnknown_085EDB4E:: @ 85EDB4E
	.string "Keep winning at the tournament!\nYour tactics will be tested.$"

gUnknown_085EDB8B:: @ 85EDB8B
	.string "Watch your POKéMON battle!\nYour spirit will be tested.$"

gUnknown_085EDBC2:: @ 85EDBC2
	.string "Win battles with teamed-up POKéMON!\nYour guts will be tested.$"

gUnknown_085EDC00:: @ 85EDC00
	.string "Aim for victory using rental POKéMON!\nYour knowledge will be tested.$"

gUnknown_085EDC45:: @ 85EDC45
	.string "Select one of three paths to battle!\nYour luck will be tested.$"

gUnknown_085EDC84:: @ 85EDC84
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

gUnknown_085EDFB7:: @ 85EDFB7
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

gUnknown_085EE14B:: @ 85EE14B
	.string "RED$"

gUnknown_085EE14F:: @ 85EE14F
	.string "BLUE$"

gUnknown_085EE154:: @ 85EE154
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

gUnknown_085EE3B0:: @ 85EE3B0
	.string "LV. 50$"

	.align 2

gUnknown_085EE3B8:: @ 85EE3B8
	.string "OPEN LEVEL$"

	.align 2

gUnknown_085EE3C4:: @ 85EE3C4
	.string "Win streak: {STR_VAR_2}$"

	.align 2

gUnknown_085EE3D4:: @ 85EE3D4
	.string "Clear streak: {STR_VAR_2}$"

	.align 2

gUnknown_085EE3E8:: @ 85EE3E8
	.string "Rooms cleared: {STR_VAR_2}$"

	.align 2

gUnknown_085EE3FC:: @ 85EE3FC
	.string "KOs in a row: {STR_VAR_2}$"

	.align 2

gUnknown_085EE410:: @ 85EE410
	.string "Floors cleared: {STR_VAR_2}$"

	.align 2
gText_1Dot:: @ 85EE424
	.string "1.$"

gUnknown_085EE427:: @ 85EE427
	.string "2.$"

gUnknown_085EE42A:: @ 85EE42A
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

gUnknown_085EE590:: @ 85EE590
	.string "TEXT SPEED$"

gUnknown_085EE59B:: @ 85EE59B
	.string "BATTLE SCENE$"

gUnknown_085EE5A8:: @ 85EE5A8
	.string "BATTLE STYLE$"

gUnknown_085EE5B5:: @ 85EE5B5
	.string "SOUND$"

gUnknown_085EE5BB:: @ 85EE5BB
	.string "FRAME$"

gUnknown_085EE5C1:: @ 85EE5C1
	.string "CANCEL$"

gUnknown_085EE5C8:: @ 85EE5C8
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

gText_BronzeCard:: @ 85EE670
	.string "BRONZE$"

gText_CopperCard:: @ 85EE677
	.string "COPPER$"

gText_SilverCard:: @ 85EE67E
	.string "SILVER$"

gText_GoldCard:: @ 85EE685
	.string "GOLD$"

gText_Day:: @ 85EE68A
	.string "DAY$"

gText_Colon3:: @ 85EE68E
	.string ":$"

gText_Confirm2:: @ 85EE690
	.string "CONFIRM$"

gUnknown_085EE698:: @ 85EE698
	.string "Days$"

gUnknown_085EE69D:: @ 85EE69D
	.string "Time:$"

gUnknown_085EE6A3:: @ 85EE6A3
	.string "Game time$"

gUnknown_085EE6AD:: @ 85EE6AD
	.string "RTC time$"

gUnknown_085EE6B6:: @ 85EE6B6
	.string "Updated time$"

gUnknown_085EE6C3:: @ 85EE6C3
	.string "POKéDEX$"

gUnknown_085EE6CB:: @ 85EE6CB
	.string "POKéMON$"

gUnknown_085EE6D3:: @ 85EE6D3
	.string "BAG$"

gUnknown_085EE6D7:: @ 85EE6D7
	.string "POKéNAV$"

gUnknown_085EE6DF:: @ 85EE6DF
	.string "{PLAYER}$"

gUnknown_085EE6E2:: @ 85EE6E2
	.string "SAVE$"

gUnknown_085EE6E7:: @ 85EE6E7
	.string "OPTION$"

gUnknown_085EE6EE:: @ 85EE6EE
	.string "EXIT$"

gUnknown_085EE6F3:: @ 85EE6F3
	.string "RETIRE$"

gUnknown_085EE6FA:: @ 85EE6FA
	.string "REST$"

gText_SafariBallStock:: @ 85EE6FF
	.string "SAFARI BALLS\nStock: {STR_VAR_1}$"

gText_BattlePyramidFloor:: @ 85EE716
	.string "Battle Pyramid\n{STR_VAR_1}$"

gUnknown_085EE728:: @ 85EE728
	.string "Floor 1$"

gUnknown_085EE730:: @ 85EE730
	.string "Floor 2$"

gUnknown_085EE738:: @ 85EE738
	.string "Floor 3$"

gUnknown_085EE740:: @ 85EE740
	.string "Floor 4$"

gUnknown_085EE748:: @ 85EE748
	.string "Floor 5$"

gUnknown_085EE750:: @ 85EE750
	.string "Floor 6$"

gUnknown_085EE758:: @ 85EE758
	.string "Floor 7$"

gUnknown_085EE760:: @ 85EE760
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

gUnknown_085EE846:: @ 85EE846
	.string "プレイヤー$" @ "pureiyaa" ("player" in Japanese)

gUnknown_085EE84C:: @ 85EE84C
	.string "さま$" @ "sama" (a very high honorific)

gText_DexHoenn:: @ 85EE84F
	.string "HOENN$"

gText_DexNational:: @ 85EE855
	.string "NATIONAL$"

gText_PokedexDiploma:: @ 85EE85E
	.string "PLAYER: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK$"

gUnknown_085EE8DC:: @ 85EE8DC
	.string "{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク$" @ geemufuriku ("Game Freak" in Japanese)

gUnknown_085EE8EA:: @ 85EE8EA
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

gUnknown_085EEA46:: @ 85EEA46
	.string "MAX. HP$"

gUnknown_085EEA4E:: @ 85EEA4E
	.string "ATTACK$"

gUnknown_085EEA55:: @ 85EEA55
	.string "DEFENSE$"

gUnknown_085EEA5D:: @ 85EEA5D
	.string "SPEED$"

gUnknown_085EEA63:: @ 85EEA63
	.string "SP. ATK$"

gUnknown_085EEA6B:: @ 85EEA6B
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

gUnknown_085EEABE:: @ 85EEABE
	.string "YOUR NAME?$"

gUnknown_085EEAC9:: @ 85EEAC9
	.string "BOX NAME?$"

gUnknown_085EEAD3:: @ 85EEAD3
	.string "{STR_VAR_1}’s nickname?$"

gUnknown_085EEAE2:: @ 85EEAE2
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

gUnknown_085EECE4:: @ 85EECE4
	.string "SWAP$"

gUnknown_085EECE9:: @ 85EECE9
	.string "ACCEPT$"

gText_AcceptThisPkmn:: @ 85EECF0
	.string "Accept this POKéMON?$"

gUnknown_085EED05:: @ 85EED05
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
gText_WonderCardsInPossession:: @ 85EEE8C
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

gUnknown_085EEFC0:: @ 85EEFC0
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

gDaycareText_GetAlongVeryWell:: @ 85EF7DA
	.string "The two seem to get along\nvery well.$"

gDaycareText_GetAlong:: @ 85EF7FF
	.string "The two seem to get along.$"

gDaycareText_DontLikeOther:: @ 85EF81A
	.string "The two don’t seem to like\neach other much.$"

gDaycareText_PlayOther:: @ 85EF846
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

gUnknown_085EF8B6:: @ 85EF8B6
	.string "1F$"

gUnknown_085EF8B9:: @ 85EF8B9
	.string "2F$"

gUnknown_085EF8BC:: @ 85EF8BC
	.string "3F$"

gUnknown_085EF8BF:: @ 85EF8BF
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

gUnknown_085EF9C8:: @ 85EF9C8
	.string "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.$"

gText_GiveUpTeachingNewMove:: @ 85EF9E6
	.string "Give up trying to teach a new\nmove to {STR_VAR_1}?$"

gText_WhichMoveToForget2:: @ 85EFA10
	.string "Which move should be\nforgotten?\p$"

gText_BattleMoves2:: @ 85EFA31
	.string "BATTLE MOVES$"

gText_ContestMoves2:: @ 85EFA3E
	.string "CONTEST MOVES$"

gUnknown_085EFA4C:: @ 85EFA4C
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

gUnknown_085EFA72:: @ 85EFA72
	.string "KIRA$"

gUnknown_085EFA77:: @ 85EFA77
	.string "AMY$"

gUnknown_085EFA7B:: @ 85EFA7B
	.string "JOHN$"

gUnknown_085EFA80:: @ 85EFA80
	.string "ROY$"

gUnknown_085EFA84:: @ 85EFA84
	.string "GABBY$"

gUnknown_085EFA8A:: @ 85EFA8A
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

gUnknown_085EFAEF:: @ 85EFAEF
	.string "DEVON PRES$"

gUnknown_085EFAFA:: @ 85EFAFA
	.string "MR. STONE$"

gUnknown_085EFB04:: @ 85EFB04
	.string "HARD AS ROCK$"

gUnknown_085EFB11:: @ 85EFB11
	.string "STEVEN$"

gUnknown_085EFB18:: @ 85EFB18
	.string "RAD NEIGHBOR$"

gUnknown_085EFB25:: @ 85EFB25
	.string "RELIABLE ONE$"

gUnknown_085EFB32:: @ 85EFB32
	.string "CALM & KIND$"

gUnknown_085EFB3E:: @ 85EFB3E
	.string "{PKMN} LOVER$"

gUnknown_085EFB47:: @ 85EFB47
	.string "DAD$"

gUnknown_085EFB4B:: @ 85EFB4B
	.string "MOM$"

gUnknown_085EFB4F:: @ 85EFB4F
	.string "ELUSIVE EYES$"

gUnknown_085EFB5C:: @ 85EFB5C
	.string "SCOTT$"

gUnknown_085EFB62:: @ 85EFB62
	.string "ROCKIN’ WHIZ$"

gUnknown_085EFB6F:: @ 85EFB6F
	.string "THE BIG HIT$"

gUnknown_085EFB7B:: @ 85EFB7B
	.string "SWELL SHOCK$"

gUnknown_085EFB87:: @ 85EFB87
	.string "PASSION BURN$"

gUnknown_085EFB94:: @ 85EFB94
	.string "SKY TAMER$"

gUnknown_085EFB9E:: @ 85EFB9E
	.string "MYSTIC DUO$"

gUnknown_085EFBA9:: @ 85EFBA9
	.string "DANDY CHARM$"

gUnknown_085EFBB5:: @ 85EFBB5
	.string "ELITE FOUR$"

gUnknown_085EFBC0:: @ 85EFBC0
	.string "CHAMPION$"

gUnknown_085EFBC9:: @ 85EFBC9
	.string "{PKMN} PROF.$"

gText_CommStandbyAwaitingOtherPlayer:: @ 85EFBD2
	.string "Communication standby…\nAwaiting another player to choose.$"

gText_BattleWasRefused:: @ 85EFC0C
	.string "The battle was refused.{PAUSE 60}$"

gText_RefusedBattle:: @ 85EFC27
	.string "Refused the battle.{PAUSE 60}$"

gUnknown_085EFC3E:: @ 85EFC3E
	.string "NO WEATHER$"

gUnknown_085EFC49:: @ 85EFC49
	.string "SUNNY$"

gUnknown_085EFC4F:: @ 85EFC4F
	.string "SUNNY2$"

gUnknown_085EFC56:: @ 85EFC56
	.string "RAIN$"

gUnknown_085EFC5B:: @ 85EFC5B
	.string "SNOW$"

gUnknown_085EFC60:: @ 85EFC60
	.string "LIGHTNING$"

gUnknown_085EFC6A:: @ 85EFC6A
	.string "FOG$"

gUnknown_085EFC6E:: @ 85EFC6E
	.string "VOLCANO ASH$"

gUnknown_085EFC7A:: @ 85EFC7A
	.string "SANDSTORM$"

gUnknown_085EFC84:: @ 85EFC84
	.string "FOG2$"

gUnknown_085EFC89:: @ 85EFC89
	.string "SEAFLOOR$"

gUnknown_085EFC92:: @ 85EFC92
	.string "CLOUDY$"

gUnknown_085EFC99:: @ 85EFC99
	.string "SUNNY3$"

gUnknown_085EFCA0:: @ 85EFCA0
	.string "HEAVY RAIN$"

gUnknown_085EFCAB:: @ 85EFCAB
	.string "SEAFLOOR2$"

gUnknown_085EFCB5:: @ 85EFCB5
	.string "DEL. ALL$"

gUnknown_085EFCBE:: @ 85EFCBE
	.string "CANCEL$"

gUnknown_085EFCC5:: @ 85EFCC5
	.string "OK$"

gUnknown_085EFCC8:: @ 85EFCC8
	.string "QUIZ$"

gUnknown_085EFCCD:: @ 85EFCCD
	.string "ANSWER$"

gText_PokeBalls:: @ 85EFCD4
	.string "POKé BALLS$"

gText_Berry:: @ 85EFCDF
	.string "BERRY$"

gText_Berries:: @ 85EFCE5
	.string "BERRIES$"

