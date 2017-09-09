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

gUnknown_085E8264:: @ 85E8264

.string "EGG$"

gUnknown_085E8268:: @ 85E8268

.string "POKéMON$"
.string "PROF. BIRCH$"

gUnknown_085E827C:: @ 85E827C

.string "NEW GAME$"

gUnknown_085E8285:: @ 85E8285

.string "CONTINUE$"

gUnknown_085E828E:: @ 85E828E

.string "OPTION$"

gUnknown_085E8295:: @ 85E8295

.string "MYSTERY GIFT$"

gUnknown_085E82A2:: @ 85E82A2

.string "MYSTERY GIFT$"

gUnknown_085E82AF:: @ 85E82AF

.string "MYSTERY EVENTS$"

gUnknown_085E82BE:: @ 85E82BE

.string "The Wireless Adapter is not\nconnected.$"

gUnknown_085E82E5:: @ 85E82E5

.string "MYSTERY GIFT can’t be used while\nthe Wireless Adapter is attached.$"

gUnknown_085E8328:: @ 85E8328

.string "MYSTERY EVENTS can’t be used while\nthe Wireless Adapter is attached.$"
.string "Updating save file using external\ndata. Please wait.$"
.string "The save file has been updated.$"

gUnknown_085E83C2:: @ 85E83C2

.string "The save file is corrupted. The\nprevious save file will be loaded.$"

gUnknown_085E8405:: @ 85E8405

.string "The save file has been erased\ndue to corruption or damage.$"

gUnknown_085E8440:: @ 85E8440

.string "1M%ブÊば+が ÎÎっÛÁまÓ+!$"

gUnknown_085E8453:: @ 85E8453

.string "The internal battery has run dry.\nThe game can be played.\pHowever, clock-based events will\nno longer occur.$"
.string "PLAYER$"
.string "POKéDEX$"

gUnknown_085E84CE:: @ 85E84CE
	.incbin "baserom.gba", 0x5e84ce, 0x8e

gUnknown_085E855C:: @ 85E855C
	.incbin "baserom.gba", 0x5e855c, 0x18

gUnknown_085E8574:: @ 85E8574
	.incbin "baserom.gba", 0x5e8574, 0x14

gUnknown_085E8588:: @ 85E8588

.string "{248} EXIT$"
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

gUnknown_085E8692:: @ 85E8692

.string "This is what we call a “POKéMON.”{PAUSE 96}\p$"

gUnknown_085E86B8:: @ 85E86B8

.string "????? POKéMON$"

gUnknown_085E86C6:: @ 85E86C6

.string "{CLEAR_TO}Ï??’??”$"

gUnknown_085E86D0:: @ 85E86D0

.string "????.? lbs.$"
.string "                       POKéMON$"
.string "{CLEAR_TO}Ï    ’    ”$"
.string "        .   lbs.$"
.string "$"

gUnknown_085E871B:: @ 85E871B

.string "CRY OF$"
.string "$"

gUnknown_085E8723:: @ 85E8723

.string "SIZE COMPARED TO $"

gUnknown_085E8735:: @ 85E8735

.string "POKéDEX registration completed.$"

gUnknown_085E8755:: @ 85E8755

.string "HT$"

gUnknown_085E8758:: @ 85E8758

.string "WT$"

gUnknown_085E875B:: @ 85E875B

.string "Searching…\nPlease wait.$"

gUnknown_085E8773:: @ 85E8773

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

gUnknown_085E8B3A:: @ 85E8B3A

.string "▶$"
.string " $"

gUnknown_085E8B3E:: @ 85E8B3E

.string "Welcome to the HALL OF FAME!$"
.string "Spotted POKéMON: {STR_VAR_1}!\nOwned POKéMON: {STR_VAR_2}!\pPROF. BIRCH’s POKéDEX rating!\pPROF. BIRCH: Let’s see…\p$"
.string "SAVING…\nDON’T TURN OFF THE POWER.$"

gUnknown_085E8BDC:: @ 85E8BDC

.string "The HALL OF FAME data is corrupted.$"

gUnknown_085E8C00:: @ 85E8C00

.string "HALL OF FAME No. {STR_VAR_1}$"

gUnknown_085E8C14:: @ 85E8C14

.string "LEAGUE CHAMPION!\nCONGRATULATIONS!$"

gUnknown_085E8C36:: @ 85E8C36

.string "No. $"

gUnknown_085E8C3B:: @ 85E8C3B

.string "Lv. $"
.string "IDNo. /$"

gUnknown_085E8C48:: @ 85E8C48

.string "NAME$"

gUnknown_085E8C4D:: @ 85E8C4D

.string "IDNo.$"

gUnknown_085E8C53:: @ 85E8C53

.string "PROF. BIRCH is in trouble!\nRelease a POKéMON and rescue him!$"

gUnknown_085E8C90:: @ 85E8C90

.string "Do you choose this POKéMON?$"
.string "POKéMON$"

gUnknown_085E8CB4:: @ 85E8CB4

.string "FLY to where?$"
.string "USE$"
.string "TOSS$"
.string "REGISTER$"
.string "GIVE$"
.string "CHECK TAG$"

gUnknown_085E8CE3:: @ 85E8CE3

.string "CONFIRM$"
.string "WALK$"

gUnknown_085E8CF0:: @ 85E8CF0

.string "CANCEL$"

gUnknown_085E8CF7:: @ 85E8CF7

.string "CANCEL$"
.string "SHOW$"

gUnknown_085E8D03:: @ 85E8D03

.string "$"
.string "CANCEL$"
.string "ITEM$"
.string "MAIL$"
.string "TAKE$"
.string "STORE$"
.string "CHECK$"

gUnknown_085E8D26:: @ 85E8D26

.string "NONE$"
.string "DESELECT$"

gUnknown_085E8D34:: @ 85E8D34

.string "???$"

gUnknown_085E8D38:: @ 85E8D38

.string "?????$"

gUnknown_085E8D3E:: @ 85E8D3E

.string "/$"

gUnknown_085E8D40:: @ 85E8D40

.string "-$"

gUnknown_085E8D42:: @ 85E8D42

.string "--$"

gUnknown_085E8D45:: @ 85E8D45

.string "---$"

gUnknown_085E8D49:: @ 85E8D49

.string "♂$"

gUnknown_085E8D4B:: @ 85E8D4B

.string "♀$"

gUnknown_085E8D4D:: @ 85E8D4D

.string "{LV}$"

gUnknown_085E8D4F:: @ 85E8D4F

.string "{249 8}{CLEAR}À$"
.string "+$"
.string "{RIGHT_ARROW}$"

gUnknown_085E8D59:: @ 85E8D59

.string "{249 7}{249 8}$"

gUnknown_085E8D5E:: @ 85E8D5E

.string " $"

gUnknown_085E8D60:: @ 85E8D60

.string "▶$"

gUnknown_085E8D62:: @ 85E8D62

.string "Go back to the\nprevious menu.$"

gUnknown_085E8D80:: @ 85E8D80

.string "What would you like to do?$"
.string "GIVE$"

gUnknown_085E8DA0:: @ 85E8DA0

.string "×{STR_VAR_1}$"
.string " BERRY$"

gOtherText_Coins2:: @ 85E8DAB

.string "{STR_VAR_1} COINS$"

gUnknown_085E8DB4:: @ 85E8DB4

.string "CLOSE BAG$"

gUnknown_085E8DBE:: @ 85E8DBE

.string "{STR_VAR_1} is\nselected.$"

gUnknown_085E8DCE:: @ 85E8DCE

.string "You can’t write\nMAIL here.$"

gUnknown_085E8DE9:: @ 85E8DE9

.string "There is no\nPOKéMON.$"

gUnknown_085E8DFE:: @ 85E8DFE

.string "Move the\n{STR_VAR_1}\nwhere?$"

gUnknown_085E8E11:: @ 85E8E11

.string "The {STR_VAR_1} can’t be held.$"

gUnknown_085E8E27:: @ 85E8E27

.string "The {STR_VAR_1} can’t be held\nhere.$"

gUnknown_085E8E42:: @ 85E8E42

.string "Deposit how many\n{STR_VAR_1}(s)?$"

gUnknown_085E8E5A:: @ 85E8E5A

.string "Deposited {STR_VAR_2}\n{STR_VAR_1}(s).$"

gUnknown_085E8E6E:: @ 85E8E6E

.string "There’s no room to\nstore items.$"

gUnknown_085E8E8E:: @ 85E8E8E

.string "Important items\ncan’t be stored in\nthe PC!$"

gUnknown_085E8EB9:: @ 85E8EB9

.string "That’s much too\nimportant to toss\nout!$"

gUnknown_085E8EE0:: @ 85E8EE0

.string "Toss out how many\n{STR_VAR_1}(s)?$"

gUnknown_085E8EF9:: @ 85E8EF9

.string "Threw away {STR_VAR_2}\n{STR_VAR_1}(s).$"

gUnknown_085E8F0E:: @ 85E8F0E

.string "Is it okay to\nthrow away {STR_VAR_2}\n{STR_VAR_1}(s)?$"

gUnknown_085E8F31:: @ 85E8F31

.string "DAD’s advice…\n{PLAYER}, there’s a time and place for\leverything!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E8F6E:: @ 85E8F6E

.string "You can’t dismount your BIKE here.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E8F93:: @ 85E8F93

.string "Huh?\nThe ITEMFINDER’s responding!\pThere’s an item buried around here!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E8FDB:: @ 85E8FDB

.string "Oh!\nThe ITEMFINDER’s shaking wildly!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9002:: @ 85E9002

.string "… … … …Nope!\nThere’s no response.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9026:: @ 85E9026

.string "Your COINS:\n{STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9037:: @ 85E9037

.string "Booted up a TM.$"

gUnknown_085E9047:: @ 85E9047

.string "Booted up an HM.$"

gUnknown_085E9058:: @ 85E9058

.string "It contained\n{STR_VAR_1}.\pTeach {STR_VAR_1}\nto a POKéMON?$"

gUnknown_085E9080:: @ 85E9080

.string "{PLAYER} used the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9092:: @ 85E9092

.string "But the effects of a REPEL\nlingered from earlier.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E90C6:: @ 85E90C6

.string "{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be lured.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E90F4:: @ 85E90F4

.string "{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be repelled.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9125:: @ 85E9125

.string "The BOX is full.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9138:: @ 85E9138
	.incbin "baserom.gba", 0x5e9138, 0x48

gUnknown_085E9180:: @ 85E9180
	.incbin "baserom.gba", 0x5e9180, 0x30

gUnknown_085E91B0:: @ 85E91B0
	.incbin "baserom.gba", 0x5e91b0, 0x10

gUnknown_085E91C0:: @ 85E91C0
	.incbin "baserom.gba", 0x5e91c0, 0x3c

gUnknown_085E91FC:: @ 85E91FC
	.incbin "baserom.gba", 0x5e91fc, 0x14

gUnknown_085E9210:: @ 85E9210

.string "{249 8}{STR_VAR_1}{CLEAR}Ê{STR_VAR_2}$"

gUnknown_085E921A:: @ 85E921A

.string "{CLEAR_TO}Ù{STR_VAR_1}{CLEAR}È{STR_VAR_2}$"

gUnknown_085E9225:: @ 85E9225

.string "SIZE /$"

gUnknown_085E922C:: @ 85E922C

.string "FIRM /$"

gUnknown_085E9233:: @ 85E9233

.string "{STR_VAR_1}.{STR_VAR_2}”$"


	.include "data/text/berry_firmness_strings.inc"

gUnknown_085E9263:: @ 85E9263

.string "{249 8}{STR_VAR_1} {STR_VAR_2}$"

gUnknown_085E926B:: @ 85E926B

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

gUnknown_085E931D:: @ 85E931D

.string "SPICY$"

gUnknown_085E9323:: @ 85E9323

.string "DRY$"

gUnknown_085E9327:: @ 85E9327

.string "SWEET$"

gUnknown_085E932D:: @ 85E932D

.string "BITTER$"

gUnknown_085E9334:: @ 85E9334

.string "SOUR$"
.string "TASTY$"
.string "FEEL$"

gUnknown_085E9344:: @ 85E9344

.string "Stow CASE.$"

gUnknown_085E934F:: @ 85E934F

.string "{LV}{STR_VAR_1}$"

gUnknown_085E9353:: @ 85E9353

.string "Throw away this\n{STR_VAR_1}?$"

gUnknown_085E9367:: @ 85E9367

.string "The {STR_VAR_1}\nwas thrown away.$"

gUnknown_085E937F:: @ 85E937F

.string "{STR_VAR_1} ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9390:: @ 85E9390

.string "{STR_VAR_1} happily ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E93A9:: @ 85E93A9

.string "{STR_VAR_1} disdainfully ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"
.string "BUY$"
.string "SELL$"
.string "QUIT$"

gUnknown_085E93D5:: @ 85E93D5

.string "IN BAG: {STR_VAR_1}$"

gUnknown_085E93E0:: @ 85E93E0

.string "Quit shopping.$"

gUnknown_085E93EF:: @ 85E93EF

.string "{STR_VAR_1}? Certainly.\nHow many would you like?$"

gUnknown_085E9417:: @ 85E9417

.string "{STR_VAR_1}? Certainly.\nHow many would you like?$"

gUnknown_085E943F:: @ 85E943F

.string "{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be ¥{STR_VAR_3}.$"

gUnknown_085E9468:: @ 85E9468

.string "{STR_VAR_1}, is it?\nThat’ll be ¥{STR_VAR_2}. Do you want it?$"

gUnknown_085E9493:: @ 85E9493

.string "You wanted {STR_VAR_1}?\nThat’ll be ¥{STR_VAR_2}. Will that be okay?$"

gUnknown_085E94C5:: @ 85E94C5

.string "Here you go!\nThank you very much.$"

gUnknown_085E94E7:: @ 85E94E7

.string "Thank you!\nI’ll send it to your home PC.$"

gUnknown_085E9510:: @ 85E9510

.string "Thanks!\nI’ll send it to your PC at home.$"

gUnknown_085E9539:: @ 85E9539

.string "You don’t have enough money.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9558:: @ 85E9558

.string "You have no more room for this\nitem.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E957F:: @ 85E957F

.string "The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E959B:: @ 85E959B

.string "Is there anything else I can help\nyou with?$"

gUnknown_085E95C7:: @ 85E95C7

.string "Can I help you with anything else?$"

gUnknown_085E95EA:: @ 85E95EA

.string "I’ll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E960F:: @ 85E960F

.string "{STR_VAR_2}? Oh, no.\nI can’t buy that.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E962F:: @ 85E962F

.string "{STR_VAR_2}?\nHow many would you like to sell?$"

gUnknown_085E9654:: @ 85E9654

.string "I can pay ¥{STR_VAR_1}.\nWould that be okay?$"

gUnknown_085E9677:: @ 85E9677

.string "Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}.$"

gUnknown_085E969C:: @ 85E969C

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

gUnknown_085E96E3:: @ 85E96E3

.string "HP$"

gUnknown_085E96E6:: @ 85E96E6

.string "SP. ATK$"

gUnknown_085E96EE:: @ 85E96EE

.string "SP. DEF$"

gUnknown_085E96F6:: @ 85E96F6

.string "It won’t have any effect.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9712:: @ 85E9712

.string "This can’t be used on\nthat POKéMON.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9738:: @ 85E9738

.string "{STR_VAR_1} can’t be switched\nout!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9754:: @ 85E9754

.string "{STR_VAR_1} is already\nin battle!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E976F:: @ 85E976F

.string "{STR_VAR_1} has already been\nselected.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E978F:: @ 85E978F

.string "{STR_VAR_1} has no energy\nleft to battle!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E97B2:: @ 85E97B2

.string "You can’t switch {STR_VAR_1}’s\nPOKéMON with one of yours!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E97E5:: @ 85E97E5

.string "An EGG can’t battle!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E97FC:: @ 85E97FC

.string "This can’t be used until a new\nBADGE is obtained.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9830:: @ 85E9830

.string "No more than {STR_VAR_1} POKéMON\nmay enter.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9855:: @ 85E9855

.string "Send the removed MAIL to\nyour PC?$"

gUnknown_085E9877:: @ 85E9877

.string "The MAIL was sent to your PC.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9897:: @ 85E9897

.string "Your PC’s MAILBOX is full.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E98B4:: @ 85E98B4

.string "If the MAIL is removed, the\nmessage will be lost. Okay?$"

gUnknown_085E98EC:: @ 85E98EC

.string "MAIL must be removed before\nholding an item.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E991B:: @ 85E991B

.string "{STR_VAR_1} was given the\n{STR_VAR_2} to hold.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E993A:: @ 85E993A

.string "{STR_VAR_1} is already holding\none {STR_VAR_2}.\pWould you like to switch the\ntwo items?$"

gUnknown_085E9980:: @ 85E9980

.string "{STR_VAR_1} isn’t holding\nanything.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E999D:: @ 85E999D

.string "Received the {STR_VAR_2}\nfrom {STR_VAR_1}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E99B8:: @ 85E99B8

.string "MAIL was taken from the\nPOKéMON.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E99DB:: @ 85E99DB

.string "The {STR_VAR_2} was taken and\nreplaced with the {STR_VAR_1}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9A08:: @ 85E9A08

.string "This POKéMON is holding an\nitem. It cannot hold MAIL.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9A40:: @ 85E9A40

.string "MAIL was transferred from\nthe MAILBOX.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9A69:: @ 85E9A69

.string "The BAG is full. The POKéMON’s\nitem could not be removed.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9AA5:: @ 85E9AA5

.string "{STR_VAR_1} learned\n{STR_VAR_2}!$"

gUnknown_085E9AB4:: @ 85E9AB4

.string "{STR_VAR_1} and {STR_VAR_2}\nare not compatible.\p{STR_VAR_2} can’t be\nlearned.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9AE9:: @ 85E9AE9

.string "{STR_VAR_1} wants to learn the\nmove {STR_VAR_2}.\pHowever, {STR_VAR_1} already\nknows four moves.\pShould a move be deleted and\nreplaced with {STR_VAR_2}?$"

gUnknown_085E9B5D:: @ 85E9B5D

.string "Stop trying to teach\n{STR_VAR_2}?$"

gUnknown_085E9B76:: @ 85E9B76

.string "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9B96:: @ 85E9B96

.string "Which move should be forgotten?{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9BB8:: @ 85E9BB8

.string "1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p{STR_VAR_1} forgot how to\nuse {STR_VAR_2}.\pAnd…{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9C00:: @ 85E9C00

.string "{STR_VAR_1} already knows\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9C17:: @ 85E9C17

.string "{STR_VAR_1}’s HP was restored\nby {STR_VAR_2} point(s).{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9C3E:: @ 85E9C3E

.string "{STR_VAR_1} was cured of its\npoisoning.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9C5F:: @ 85E9C5F

.string "{STR_VAR_1} was cured of\nparalysis.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9C7C:: @ 85E9C7C

.string "{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9C8A:: @ 85E9C8A

.string "{STR_VAR_1}’s burn was healed.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9CA2:: @ 85E9CA2

.string "{STR_VAR_1} was thawed out.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9CB7:: @ 85E9CB7

.string "PP was restored.{PAUSE_UNTIL_PRESS}$"
.string "{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9CE0:: @ 85E9CE0

.string "{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9CF5:: @ 85E9CF5

.string "{STR_VAR_1}’s PP increased.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9D0A:: @ 85E9D0A

.string "{STR_VAR_1} was elevated to\nLv. {STR_VAR_2}.$"

gUnknown_085E9D25:: @ 85E9D25

.string "{STR_VAR_1}’s base {STR_VAR_2}\nstat was raised.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9D45:: @ 85E9D45

.string "{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9D6D:: @ 85E9D6D

.string "{STR_VAR_1} adores you!\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9D90:: @ 85E9D90

.string "{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} can’t fall!{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9DBE:: @ 85E9DBE

.string "{STR_VAR_1} snapped out of its\nconfusion.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9DE1:: @ 85E9DE1

.string "{STR_VAR_1} got over its\ninfatuation.{PAUSE_UNTIL_PRESS}$"

gUnknown_085E9E00:: @ 85E9E00

.string "Throw away this\n{STR_VAR_1}?$"

gUnknown_085E9E14:: @ 85E9E14

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

gUnknown_085EA0EE:: @ 85EA0EE

.string "That POKéMON can’t participate.{PAUSE_UNTIL_PRESS}$"

gUnknown_085EA110:: @ 85EA110

.string "Cancel participation?$"

gUnknown_085EA126:: @ 85EA126

.string "Cancel the battle?$"

gUnknown_085EA139:: @ 85EA139

.string "Return to the WAITING ROOM?$"

gUnknown_085EA155:: @ 85EA155

.string "Cancel the challenge?$"

gUnknown_085EA16B:: @ 85EA16B

.string "Want to escape from here and return\nto {STR_VAR_1}?$"

gUnknown_085EA196:: @ 85EA196

.string "Want to return to the healing spot\nused last in {STR_VAR_1}?$"

gUnknown_085EA1CA:: @ 85EA1CA

.string "{PAUSE_UNTIL_PRESS}$"

gUnknown_085EA1CD:: @ 85EA1CD

.string "{STR_VAR_1}& ぐñぐñこÂÉ+à\nだÏÛ ùªÏÁでÒÉ?$"

gUnknown_085EA1E8:: @ 85EA1E8
	.incbin "baserom.gba", 0x5ea1e8, 0x28

gUnknown_085EA210:: @ 85EA210
	.incbin "baserom.gba", 0x5ea210, 0x24

gUnknown_085EA234:: @ 85EA234

.string "An EGG can’t be traded now.$"
.string "The other TRAINER’s POKéMON\ncan’t be traded now.$"
.string "   The other TRAINER can’t accept\nthat POKéMON now.$"
.string "   You can’t trade with that\nTRAINER now.$"
.string " That isn’t the type of POKéMON\nthat the other TRAINER wants.$"
.string "   That isn’t an EGG.$"
.string "REGISTER$"

gUnknown_085EA33C:: @ 85EA33C

.string "ATTACK$"

gUnknown_085EA343:: @ 85EA343

.string "DEFENSE$"

gUnknown_085EA34B:: @ 85EA34B

.string "SP. ATK$"

gUnknown_085EA353:: @ 85EA353

.string "SP. DEF$"

gUnknown_085EA35B:: @ 85EA35B

.string "SPEED$"

gUnknown_085EA361:: @ 85EA361

.string "HP$"
.string "$"

gUnknown_085EA365:: @ 85EA365

.string "OT/$"

gUnknown_085EA369:: @ 85EA369

.string "RENTAL POKéMON$"

gUnknown_085EA378:: @ 85EA378

.string "TYPE/$"

gUnknown_085EA37E:: @ 85EA37E

.string "POWER$"

gUnknown_085EA384:: @ 85EA384

.string "ACCURACY$"

gUnknown_085EA38D:: @ 85EA38D

.string "APPEAL$"

gUnknown_085EA394:: @ 85EA394

.string "JAM$"

gUnknown_085EA398:: @ 85EA398

.string "STATUS$"

gUnknown_085EA39F:: @ 85EA39F

.string "EXP. POINTS$"

gUnknown_085EA3AB:: @ 85EA3AB

.string "NEXT LV.$"

gUnknown_085EA3B4:: @ 85EA3B4

.string "RIBBONS: {STR_VAR_1}$"

gUnknown_085EA3C0:: @ 85EA3C0

.string "$"
.string "EVENTS$"

gUnknown_085EA3C8:: @ 85EA3C8

.string "SWITCH$"

gUnknown_085EA3CF:: @ 85EA3CF

.string "POKéMON INFO$"

gUnknown_085EA3DC:: @ 85EA3DC

.string "POKéMON SKILLS$"

gUnknown_085EA3EB:: @ 85EA3EB

.string "BATTLE MOVES$"

gUnknown_085EA3F8:: @ 85EA3F8

.string "C0NTEST MOVES$"

gUnknown_085EA406:: @ 85EA406

.string "INFO$"

gUnknown_085EA40B:: @ 85EA40B

.string "It looks like this EGG will\ntake a long time to hatch.$"

gUnknown_085EA442:: @ 85EA442

.string "What will hatch from this?\nIt will take some time.$"

gUnknown_085EA475:: @ 85EA475

.string "It moves occasionally.\nIt should hatch soon.$"

gUnknown_085EA4A2:: @ 85EA4A2

.string "It’s making sounds.\nIt’s about to hatch!$"

gUnknown_085EA4CB:: @ 85EA4CB

.string "HM moves can’t be\nforgotten now.$"

gUnknown_085EA4EC:: @ 85EA4EC
	.incbin "baserom.gba", 0x5ea4ec, 0x2a

gUnknown_085EA516:: @ 85EA516
	.incbin "baserom.gba", 0x5ea516, 0x2e

gUnknown_085EA544:: @ 85EA544
	.incbin "baserom.gba", 0x5ea544, 0x26

gUnknown_085EA56A:: @ 85EA56A
	.incbin "baserom.gba", 0x5ea56a, 0x3e

gUnknown_085EA5A8:: @ 85EA5A8
	.incbin "baserom.gba", 0x5ea5a8, 0x33

gUnknown_085EA5DB:: @ 85EA5DB
	.incbin "baserom.gba", 0x5ea5db, 0x10

gUnknown_085EA5EB:: @ 85EA5EB
	.incbin "baserom.gba", 0x5ea5eb, 0x2c

gUnknown_085EA617:: @ 85EA617
	.incbin "baserom.gba", 0x5ea617, 0x30
    
gUnknown_085EA647:: @ 85EA647

.string "An odd POKéMON EGG found\nby the DAY CARE couple.$"

gUnknown_085EA678:: @ 85EA678

.string "A peculiar POKéMON EGG\nobtained at the nice place.$"

gUnknown_085EA6AB:: @ 85EA6AB

.string "A peculiar POKéMON EGG\nobtained in a trade.$"

gUnknown_085EA6D7:: @ 85EA6D7

.string "A POKéMON EGG obtained\nat the hot springs.$"

gUnknown_085EA702:: @ 85EA702

.string "An odd POKéMON EGG\nobtained from a traveler.$"

gUnknown_085EA72F:: @ 85EA72F

.string "’s BASE$"

gUnknown_085EA737:: @ 85EA737

.string "Is it okay to delete {STR_VAR_1}\nfrom the REGISTRY?$"

gUnknown_085EA762:: @ 85EA762

.string "The registered data was deleted.{PAUSE_UNTIL_PRESS}$"

gUnknown_085EA785:: @ 85EA785

.string "There is no REGISTRY.{PAUSE_UNTIL_PRESS}$"
.string "DEL REGIST.$"
.string "{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}$"
.string "DECORATE$"
.string "PUT AWAY$"
.string "TOSS$"

gUnknown_085EA7C8:: @ 85EA7C8

.string "{COLOR 161}{SHADOW 161}$"
.string "Put out the selected decoration item.$"
.string "Store the chosen decoration in the PC.$"
.string "Throw away unwanted decorations.$"

gUnknown_085EA83D:: @ 85EA83D

.string "There are no decorations.{PAUSE_UNTIL_PRESS}$"
.string "DESK$"
.string "CHAIR$"
.string "PLANT$"
.string "ORNAMENT$"
.string "MAT$"
.string "POSTER$"
.string "DOLL$"
.string "CUSHION$"

gUnknown_085EA88B:: @ 85EA88B

.string "GOLD$"

gUnknown_085EA890:: @ 85EA890

.string "SILVER$"

gUnknown_085EA897:: @ 85EA897

.string "Place it here?$"

gUnknown_085EA8A6:: @ 85EA8A6

.string "It can’t be placed here.$"

gUnknown_085EA8BF:: @ 85EA8BF

.string "Cancel decorating?$"

gUnknown_085EA8D2:: @ 85EA8D2

.string "This is in use already.$"

gUnknown_085EA8EA:: @ 85EA8EA

.string "No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.$"

gUnknown_085EA931:: @ 85EA931

.string "No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.$"
.string "This can’t be placed here.\nIt must be on a DESK, etc.$"

gUnknown_085EA9AE:: @ 85EA9AE

.string "This decoration can’t be placed in\nyour own room.$"

gUnknown_085EA9E0:: @ 85EA9E0

.string "This decoration is in use.\nIt can’t be thrown away.$"

gUnknown_085EAA14:: @ 85EAA14

.string "This {STR_VAR_1} will be discarded.\nIs that okay?$"

gUnknown_085EAA3D:: @ 85EAA3D

.string "The decoration item was thrown away.$"

gUnknown_085EAA62:: @ 85EAA62

.string "Stop putting away decorations?$"

gUnknown_085EAA81:: @ 85EAA81

.string "There is no decoration item here.$"

gUnknown_085EAAA3:: @ 85EAAA3

.string "Return this decoration to the PC?$"

gUnknown_085EAAC5:: @ 85EAAC5

.string "The decoration was returned to the PC.$"

gUnknown_085EAAEC:: @ 85EAAEC

.string "There are no decorations in use.{PAUSE_UNTIL_PRESS}$"
.string "TRISTAN$"
.string "PHILIP$"
.string "DENNIS$"
.string "ROBERTO$"
.string "TURN OFF$"
.string "DECORATION$"
.string "ITEM STORAGE$"

gUnknown_085EAB4E:: @ 85EAB4E

.string "MAILBOX$"
.string "DEPOSIT ITEM$"

gUnknown_085EAB63:: @ 85EAB63

.string "WITHDRAW ITEM$"

gUnknown_085EAB71:: @ 85EAB71

.string "TOSS ITEM$"
.string "Store items in the PC.$"
.string "Take out items from the PC.$"
.string "Throw away items stored in the PC.$"

gUnknown_085EABD1:: @ 85EABD1

.string "There are no items.{PAUSE_UNTIL_PRESS}$"

gUnknown_085EABE7:: @ 85EABE7

.string "There is no more\nroom in the BAG.$"

gUnknown_085EAC09:: @ 85EAC09

.string "Withdraw how many\n{STR_VAR_1}(s)?$"

gUnknown_085EAC22:: @ 85EAC22

.string "Withdrew {STR_VAR_2}\n{STR_VAR_1}(s).$"
.string "READ$"
.string "MOVE TO BAG$"
.string "GIVE$"

gUnknown_085EAC4B:: @ 85EAC4B

.string "There’s no MAIL here.{PAUSE_UNTIL_PRESS}$"

gUnknown_085EAC63:: @ 85EAC63

.string "What would you like to do with\n{STR_VAR_1}’s MAIL?$"

gUnknown_085EAC8D:: @ 85EAC8D

.string "The message will be lost.\nIs that okay?$"

gUnknown_085EACB5:: @ 85EACB5

.string "The BAG is full.{PAUSE_UNTIL_PRESS}$"

gUnknown_085EACC8:: @ 85EACC8

.string "The MAIL was returned to the BAG\nwith its message erased.{PAUSE_UNTIL_PRESS}$"

gUnknown_085EAD04:: @ 85EAD04

.string "DAD$"

gUnknown_085EAD08:: @ 85EAD08

.string "MOM$"

gUnknown_085EAD0C:: @ 85EAD0C

.string "WALLACE$"

gUnknown_085EAD14:: @ 85EAD14

.string "STEVEN$"

gUnknown_085EAD1B:: @ 85EAD1B

.string "BRAWLY$"

gUnknown_085EAD22:: @ 85EAD22

.string "WINONA$"

gUnknown_085EAD29:: @ 85EAD29

.string "PHOEBE$"

gUnknown_085EAD30:: @ 85EAD30

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
.string "COOLNESS CONTEST$"
.string "BEAUTY CONTEST$"
.string "CUTENESS CONTEST$"
.string "SMARTNESS CONTEST$"
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

gUnknown_085EAE62:: @ 85EAE62

.string "YES$"

gUnknown_085EAE66:: @ 85EAE66

.string "NO$"
.string "INFO$"
.string "SINGLE BATTLE$"
.string "DOUBLE BATTLE$"
.string "MULTI BATTLE$"
.string "MR. BRINEY$"
.string "CHALLENGE$"
.string "INFO$"

gUnknown_085EAEB1:: @ 85EAEB1

.string "LV. 50$"

gUnknown_085EAEB8:: @ 85EAEB8

.string "OPEN LEVEL$"
.string "FRESH WATER{CLEAR_TO}ぶ¥200$"
.string "SODA POP{CLEAR_TO}ぶ¥300$"
.string "LEMONADE{CLEAR_TO}ぶ¥350$"
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
.string "TM32{CLEAR_TO}ぶ1,500 COINS$"
.string "TM29{CLEAR_TO}ぶ3,500 COINS$"
.string "TM35{CLEAR_TO}ぶ4,000 COINS$"
.string "TM24{CLEAR_TO}ぶ4,000 COINS$"
.string "TM13{CLEAR_TO}ぶ4,000 COINS$"

gUnknown_085EB0E8:: @ 85EB0E8

.string "COOL$"

gUnknown_085EB0ED:: @ 85EB0ED

.string "BEAUTY$"

gUnknown_085EB0F4:: @ 85EB0F4

.string "CUTE$"

gUnknown_085EB0F9:: @ 85EB0F9

.string "SMART$"

gUnknown_085EB0FF:: @ 85EB0FF

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

gUnknown_085EB169:: @ 85EB169

.string "SOMEONE’S PC$"

gUnknown_085EB176:: @ 85EB176

.string "LANETTE’S PC$"

gUnknown_085EB183:: @ 85EB183

.string "{PLAYER}’s PC$"

gUnknown_085EB18B:: @ 85EB18B

.string "HALL OF FAME$"

gUnknown_085EB198:: @ 85EB198

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

gUnknown_085EB25C:: @ 85EB25C

.string "POKéDEX$"

gUnknown_085EB264:: @ 85EB264

.string "POKéMON$"

gUnknown_085EB26C:: @ 85EB26C

.string "BAG$"

gUnknown_085EB270:: @ 85EB270

.string "POKéNAV$"
.string "$"

gUnknown_085EB279:: @ 85EB279

.string "SAVE$"

gUnknown_085EB27E:: @ 85EB27E

.string "OPTION$"

gUnknown_085EB285:: @ 85EB285

.string "EXIT$"
.string "  5BP$"
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

gUnknown_085EB5CF:: @ 85EB5CF

.string "99 times +$"

gUnknown_085EB5DA:: @ 85EB5DA

.string "1 minute +$"

gUnknown_085EB5E5:: @ 85EB5E5

.string " seconds$"

gUnknown_085EB5EE:: @ 85EB5EE

.string " time(s)$"
.string ".$"

gUnknown_085EB5F9:: @ 85EB5F9

.string "Big guy$"

gUnknown_085EB601:: @ 85EB601

.string "Big girl$"

gUnknown_085EB60A:: @ 85EB60A

.string "son$"

gUnknown_085EB60E:: @ 85EB60E

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

gUnknown_085EB6A5:: @ 85EB6A5

.string "Now on:$"

gUnknown_085EB6AD:: @ 85EB6AD

.string "BP$"
.string "ENERGYPOWDER{CLEAR_TO}メ{SIZE 0}50$"
.string "ENERGY ROOT{CLEAR_TO}メ{SIZE 0}80$"
.string "HEAL POWDER{CLEAR_TO}メ{SIZE 0}50$"
.string "REVIVAL HERB{CLEAR_TO}フ{SIZE 0}300$"
.string "PROTEIN{CLEAR_TO}テ{SIZE 0}1,000$"
.string "IRON{CLEAR_TO}テ{SIZE 0}1,000$"
.string "CARBOS{CLEAR_TO}テ{SIZE 0}1,000$"
.string "CALCIUM{CLEAR_TO}テ{SIZE 0}1,000$"
.string "ZINC{CLEAR_TO}テ{SIZE 0}1,000$"
.string "HP UP{CLEAR_TO}テ{SIZE 0}1,000$"
.string "PP UP{CLEAR_TO}テ{SIZE 0}3,000$"
.string "RANKING HALL$"
.string "EXCHANGE SERVICE$"
.string "LILYCOVE CITY$"
.string "SLATEPORT CITY$"
.string "CAVE OF ORIGIN$"
.string "MT. PYRE$"
.string "SKY PILLAR$"
.string "Don’t remember$"

gUnknown_085EB7EA:: @ 85EB7EA

.string "EXIT$"
.string "Exit from the BOX?$"
.string "What do you want to do?$"
.string "Please pick a theme.$"
.string "Pick the wallpaper.$"
.string "{SPECIAL_F7}  is selected.$"
.string "Jump to which BOX?$"
.string "Deposit in which BOX?$"
.string "{SPECIAL_F7}  was deposited.$"
.string "The BOX is full.$"
.string "Release this POKéMON?$"
.string "{SPECIAL_F7}  was released.$"
.string "Bye-bye, {SPECIAL_F7} !$"
.string "Mark your POKéMON.$"
.string "That’s your last POKéMON!$"
.string "Your party’s full!$"
.string "You’re holding a POKéMON!$"
.string "Which one will you take?$"
.string "You can’t release an EGG.$"
.string "Continue BOX operations?$"
.string "{SPECIAL_F7}  came back!$"
.string "Was it worried about you?$"
.string "… … … … !$"
.string "Please remove the MAIL.$"
.string "GIVE to a POKéMON?$"
.string "Placed item in the BAG.$"
.string "The BAG is full.$"
.string "Put this item in the BAG?$"
.string "{SPECIAL_F7}  is now held.$"
.string "Changed to {SPECIAL_F7} .$"
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

gUnknown_085EBC89:: @ 85EBC89

.string "There is just one POKéMON with you.$"

gUnknown_085EBCAD:: @ 85EBCAD

.string "Your party is full!$"

gUnknown_085EBCC1:: @ 85EBCC1

.string "BOX$"
.string "Check the map of the HOENN region.$"
.string "Check POKéMON in detail.$"
.string "Call a registered TRAINER.$"
.string "Check obtained RIBBONS.$"
.string "Put away the POKéNAV.$"

gUnknown_085EBD4A:: @ 85EBD4A

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

gUnknown_085EBE5F:: @ 85EBE5F

.string "No. registered$"

gUnknown_085EBE6E:: @ 85EBE6E

.string "No. of battles$"
.string "DETAIL$"
.string "CALL$"
.string "EXIT$"
.string "Can’t call opponent here.$"
.string "STRATEGY$"
.string "TRAINER’S POKéMON$"
.string "SELF-INTRODUCTION$"
.string "{CLEAR}ィ$"
.string "{248} ZOOM {248}ÀCANCEL$"
.string "{248} FULL {248}ÀCANCEL$"
.string "{248} CONDITION {248}ÀCANCEL$"
.string "{248} MARKINGS {248}ÀCANCEL$"
.string "{248} SELECT MARK {248}ÀCANCEL$"
.string "{248} MENU {248}ÀCANCEL$"
.string "{248} OK {248}ÀCANCEL$"
.string "{248}ÀCANCEL$"
.string "{248} RIBBONS {248}ÀCANCEL$"
.string "{248} CHECK {248}ÀCANCEL$"
.string "{248}ÀCANCEL$"

gUnknown_085EBF8D:: @ 85EBF8D

.string "NATURE/$"

gUnknown_085EBF95:: @ 85EBF95

.string "That TRAINER is close by.\nTalk to the TRAINER in person!$"

gUnknown_085EBFCE:: @ 85EBFCE

.string "IN PARTY$"

gUnknown_085EBFD7:: @ 85EBFD7

.string "No. $"
.string "RIBBONS$"
.string "{SPECIAL_F7} {COLOR_HIGHLIGHT_SHADOW YELLOW DARK_GREY}É♂{COLOR_HIGHLIGHT_SHADOW RED DARK_GREY}Â/{LV}{SPECIAL_F7}À$"
.string "{SPECIAL_F7} {COLOR_HIGHLIGHT_SHADOW MAGENTA DARK_GREY}Ë♀{COLOR_HIGHLIGHT_SHADOW RED DARK_GREY}Â/{LV}{SPECIAL_F7}À$"
.string "{SPECIAL_F7} /{LV}{SPECIAL_F7}À$"

gUnknown_085EC00F:: @ 85EC00F

.string "UNKNOWN$"
.string "CALL$"
.string "CHECK$"
.string "CANCEL$"

gUnknown_085EC029:: @ 85EC029

.string "No. {SPECIAL_F7} $"

gUnknown_085EC030:: @ 85EC030

.string "RIBBONS {SPECIAL_F7} $"
.string "{SPECIAL_F7} {COLOR_HIGHLIGHT_SHADOW YELLOW DARK_GREY}É♂{COLOR_HIGHLIGHT_SHADOW RED DARK_GREY}Â/{LV}{SPECIAL_F7}À{SPECIAL_F7}Á$"
.string "{SPECIAL_F7} {COLOR_HIGHLIGHT_SHADOW MAGENTA DARK_GREY}Ë♀{COLOR_HIGHLIGHT_SHADOW RED DARK_GREY}Â/{LV}{SPECIAL_F7}À{SPECIAL_F7}Á$"
.string "{SPECIAL_F7} /{LV}{SPECIAL_F7}À{SPECIAL_F7}Á$"
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

gUnknown_085EC3A6:: @ 85EC3A6

.string "Quit editing?$"

gUnknown_085EC3B4:: @ 85EC3B4

.string "Stop giving the POKéMON MAIL?$"
.string "and fill out the questionnaire.$"
.string "Let’s reply to the interview!$"

gUnknown_085EC410:: @ 85EC410

.string "All the text being edited will$"

gUnknown_085EC42F:: @ 85EC42F

.string "be deleted. Is that okay?$"
.string "Quit editing?$"
.string "The edited text will not be saved.$"
.string "Is that okay?$"
.string "Please enter a phrase or word.$"
.string "The entire text can’t be deleted.$"

gUnknown_085EC4C9:: @ 85EC4C9

.string "Only one phrase may be changed.$"

gUnknown_085EC4E9:: @ 85EC4E9

.string "The original song will be used.$"
.string "That’s trendy already!$"

gUnknown_085EC520:: @ 85EC520
	.incbin "baserom.gba", 0x5ec520, 0x152

gUnknown_085EC672:: @ 85EC672

.string "You cannot quit here.$"

gUnknown_085EC688:: @ 85EC688

.string "This section must be completed.$"

gUnknown_085EC6A8:: @ 85EC6A8

.string "{SPECIAL_F7} ’s quiz$"

gUnknown_085EC6B2:: @ 85EC6B2

.string "Lady$"
.string "After you have read the quiz$"
.string "question, press the A Button.$"
.string "The quiz answer is?$"

gUnknown_085EC706:: @ 85EC706

.string "Would you like to quit this quiz$"

gUnknown_085EC727:: @ 85EC727

.string "challenge?$"
.string "Is this quiz OK?$"

gUnknown_085EC743:: @ 85EC743

.string "Create a quiz!$"

gUnknown_085EC752:: @ 85EC752

.string "Select the answer!$"

gUnknown_085EC765:: @ 85EC765

.string "The lyrics can’t be deleted.$"
.string "POKéMON LEAGUE$"
.string "POKéMON CENTER$"

gUnknown_085EC7A0:: @ 85EC7A0

.string " gets a {POKEBLOCK}?$"
.string "Coolness $"
.string "Beauty $"
.string "Cuteness $"
.string "Smartness $"
.string "Toughness $"

gUnknown_085EC7E1:: @ 85EC7E1

.string "was enhanced!$"

gUnknown_085EC7EF:: @ 85EC7EF

.string "Nothing changed!$"

gUnknown_085EC800:: @ 85EC800

.string "It won’t eat anymore…$"

gUnknown_085EC816:: @ 85EC816

.string "Save failed. Checking the backup\nmemory… Please wait.\n{COLOR BLUE}“Time required: about 1 minute”$"

gUnknown_085EC86F:: @ 85EC86F

.string "The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save.$"

gUnknown_085EC8D4:: @ 85EC8D4

.string "{COLOR BLUE}“Game play cannot be continued.\nReturning to the title screen…”$"

gUnknown_085EC917:: @ 85EC917

.string "Check completed.\nAttempting to save again.\nPlease wait.$"

gUnknown_085EC94F:: @ 85EC94F

.string "Save completed.\n{COLOR BLUE}“Game play cannot be continued.\nReturning to the title screen.”$"

gUnknown_085EC9A2:: @ 85EC9A2

.string "Save completed.\n{COLOR BLUE}“Please press the A Button.”$"

gUnknown_085EC9D2:: @ 85EC9D2

.string "FERRY$"

gUnknown_085EC9D8:: @ 85EC9D8

.string "SECRET BASE$"

gUnknown_085EC9E4:: @ 85EC9E4

.string "HIDEOUT$"

gUnknown_085EC9EC:: @ 85EC9EC

.string "Reset RTC?\nA: Confirm, B: Cancel$"

gUnknown_085ECA0D:: @ 85ECA0D

.string "Present time in game$"

gUnknown_085ECA22:: @ 85ECA22

.string "Previous time in game$"

gUnknown_085ECA38:: @ 85ECA38

.string "Please reset the time.$"

gUnknown_085ECA4F:: @ 85ECA4F

.string "The clock has been reset.\nData will be saved. Please wait.$"

gUnknown_085ECA8A:: @ 85ECA8A

.string "Save completed.$"

gUnknown_085ECA9A:: @ 85ECA9A

.string "Save failed…$"

gUnknown_085ECAA7:: @ 85ECAA7

.string "There is no save file, so the time\ncan’t be set.$"

gUnknown_085ECAD8:: @ 85ECAD8

.string "The in-game clock adjustment system\nis now useable.$"

gUnknown_085ECB0C:: @ 85ECB0C

.string "SLOTS$"

gUnknown_085ECB12:: @ 85ECB12

.string "ROULETTE$"

gUnknown_085ECB1B:: @ 85ECB1B

.string "Good$"

gUnknown_085ECB20:: @ 85ECB20

.string "Very good$"

gUnknown_085ECB2A:: @ 85ECB2A

.string "Excellent$"

gUnknown_085ECB34:: @ 85ECB34

.string "So-so$"

gUnknown_085ECB3A:: @ 85ECB3A

.string "Bad$"

gUnknown_085ECB3E:: @ 85ECB3E

.string "The worst$"

gUnknown_085ECB48:: @ 85ECB48

.string "spicy$"

gUnknown_085ECB4E:: @ 85ECB4E

.string "dry$"

gUnknown_085ECB52:: @ 85ECB52

.string "sweet$"

gUnknown_085ECB58:: @ 85ECB58

.string "bitter$"

gUnknown_085ECB5F:: @ 85ECB5F

.string "sour$"

gUnknown_085ECB64:: @ 85ECB64

.string "SINGLE$"

gUnknown_085ECB6B:: @ 85ECB6B

.string "DOUBLE$"

gUnknown_085ECB72:: @ 85ECB72

.string "jackpot$"

gUnknown_085ECB7A:: @ 85ECB7A

.string "first$"

gUnknown_085ECB80:: @ 85ECB80

.string "second$"

gUnknown_085ECB87:: @ 85ECB87
	.incbin "baserom.gba", 0x5ecb87, 0x3d6
    
gUnknown_085ECF5D:: @ 85ECF5D

.string "{STR_VAR_1} fainted…\p\n$"

gOtherText_Marco:: @ 85ECF6B

.string "MARCO$"

gUnknown_085ECF71:: @ 85ECF71

.string "NAME: $"

gUnknown_085ECF78:: @ 85ECF78

.string "IDNo.$"

gUnknown_085ECF7E:: @ 85ECF7E

.string "MONEY$"
.string "¥$"

gUnknown_085ECF86:: @ 85ECF86

.string "POKéDEX$"

gUnknown_085ECF8E:: @ 85ECF8E

.string "$"

gUnknown_085ECF8F:: @ 85ECF8F

.string ":$"
.string " points$"

gUnknown_085ECF99:: @ 85ECF99

.string "TIME$"
.string "ゲ-ムポ¡ント$"

gUnknown_085ECFA6:: @ 85ECFA6

.string "{STR_VAR_1}’s TRAINER CARD$"

gUnknown_085ECFB8:: @ 85ECFB8

.string "HALL OF FAME DEBUT  $"
.string "LINK BATTLES$"
.string "LINK CABLE BATTLES$"

gUnknown_085ECFED:: @ 85ECFED

.string "W:{COLOR BLUE}{SHADOW YELLOW}{STR_VAR_1}{COLOR RED}{SHADOW GREEN}  L:{COLOR BLUE}{SHADOW YELLOW}{STR_VAR_2}{COLOR RED}{SHADOW GREEN}$"

gUnknown_085ED010:: @ 85ED010

.string "POKéMON TRADES$"

gUnknown_085ED01F:: @ 85ED01F

.string "UNION TRADES & BATTLES$"

gUnknown_085ED036:: @ 85ED036

.string "BERRY CRUSH$"

gUnknown_085ED042:: @ 85ED042

.string "Waiting for the other TRAINER to\nfinish reading your TRAINER CARD.$"

gUnknown_085ED085:: @ 85ED085

.string "{POKEBLOCK}S W/FRIENDS$"

gUnknown_085ED096:: @ 85ED096

.string "{STR_VAR_1}{COLOR RED}{SHADOW GREEN}$"

gUnknown_085ED09F:: @ 85ED09F

.string "WON CONTESTS W/FRIENDS$"

gUnknown_085ED0B6:: @ 85ED0B6

.string "BATTLE POINTS WON$"

gUnknown_085ED0C8:: @ 85ED0C8

.string "{STR_VAR_1}{COLOR RED}{SHADOW GREEN}BP$"

gUnknown_085ED0D3:: @ 85ED0D3

.string "BATTLE TOWER$"

gUnknown_085ED0E0:: @ 85ED0E0

.string "W/{COLOR BLUE}{SHADOW YELLOW}{STR_VAR_1}{COLOR RED}{SHADOW GREEN}  STRAIGHT/{COLOR BLUE}{SHADOW YELLOW}{STR_VAR_2}$"
.string "BATTLE TOWER$"
.string "BATTLE DOME$"
.string "BATTLE PALACE$"
.string "BATTLE FACTORY$"
.string "BATTLE ARENA$"
.string "BATTLE PIKE$"
.string "BATTLE PYRAMID$"
.string "  {STR_VAR_1} SINGLE$"
.string "  {STR_VAR_1} DOUBLE$"
.string "  {STR_VAR_1} MULTI$"
.string "   {STR_VAR_1} LINK$"
.string "{STR_VAR_1}$"

gUnknown_085ED193:: @ 85ED193

.string "Give$"

gUnknown_085ED198:: @ 85ED198

.string "No need$"

gUnknown_085ED1A0:: @ 85ED1A0

.string "{COLOR GREEN}{SHADOW RED}$"

gUnknown_085ED1A7:: @ 85ED1A7

.string "{COLOR LIGHT_GREY}$"

gUnknown_085ED1AB:: @ 85ED1AB

.string "{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}$"

gUnknown_085ED1B2:: @ 85ED1B2

.string "C.$"

gUnknown_085ED1B5:: @ 85ED1B5

.string "B.$"

gUnknown_085ED1B8:: @ 85ED1B8

.string "Announcing the results!$"

gUnknown_085ED1D0:: @ 85ED1D0

.string "The preliminary results!$"

gUnknown_085ED1E9:: @ 85ED1E9

.string "Round 2 results!$"

gUnknown_085ED1FA:: @ 85ED1FA

.string "{STR_VAR_1}’s {STR_VAR_2} won!$"

gUnknown_085ED207:: @ 85ED207

.string "Communication standby…$"

gUnknown_085ED21E:: @ 85ED21E

.string "{COLOR RED}$"
.string "{COLOR_HIGHLIGHT_SHADOW WHITE2 DARK_GREY}Ó$"

gUnknown_085ED228:: @ 85ED228

.string "{HIGHLIGHT RED}$"
.string " $"

gUnknown_085ED22E:: @ 85ED22E

.string "{COLOR SILVER}♂$"

gUnknown_085ED233:: @ 85ED233

.string "{COLOR BLACK2}♀$"

gUnknown_085ED238:: @ 85ED238

.string "{COLOR SILVER}$"
.string "UPPER$"
.string "lower$"
.string "OTHERS$"
.string "SYMBOLS$"
.string "REGISTER$"
.string "EXIT$"
.string "Quit chatting?$"
.string "Register text where?$"
.string "Register text here?$"
.string "Input text.$"

gUnknown_085ED2A9:: @ 85ED2A9

.string "{SPECIAL_F7}  joined the chat!$"

gUnknown_085ED2BD:: @ 85ED2BD

.string "{SPECIAL_F7}  left the chat.$"
.string "{SPECIAL_F7} ç{SPECIAL_F7}ÀéÊò:$"
.string "{SPECIAL_F7} ç{SPECIAL_F7}ÀéÊòè ÁまÓ+$"
.string "Exiting the chat…$"
.string "The LEADER, {SPECIAL_F7} , has\nleft, ending the chat.$"
.string "The registered text has been changed.\nIs it okay to save the game?$"
.string "There is already a saved file.\nIs it okay to overwrite it?$"
.string "SAVING…\nDON’T TURN OFF THE POWER.$"
.string "{SPECIAL_F7}  saved the game.$"
.string "If the LEADER leaves, the chat\nwill end. Is that okay?$"

gUnknown_085ED40F:: @ 85ED40F

.string "HELLO$"

gUnknown_085ED415:: @ 85ED415

.string "POKéMON$"

gUnknown_085ED41D:: @ 85ED41D

.string "TRADE$"

gUnknown_085ED423:: @ 85ED423

.string "BATTLE$"

gUnknown_085ED42A:: @ 85ED42A

.string "LET’S$"

gUnknown_085ED430:: @ 85ED430

.string "OK!$"

gUnknown_085ED434:: @ 85ED434

.string "SORRY$"

gUnknown_085ED43A:: @ 85ED43A

.string "YAY{249}{249}$"

gUnknown_085ED440:: @ 85ED440

.string "THANK YOU$"

gUnknown_085ED44A:: @ 85ED44A

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

gUnknown_085ED5A5:: @ 85ED5A5

.string "{STR_VAR_1} hatched from the EGG!$"

gUnknown_085ED5BE:: @ 85ED5BE
	.incbin "baserom.gba", 0x5ed5be, 0x216

gUnknown_085ED7D4:: @ 85ED7D4

.string "1. {COLOR LIGHT_GREY}{SHADOW BLACK}{SPECIAL_F7} $"

gUnknown_085ED7E0:: @ 85ED7E0
	.incbin "baserom.gba", 0x5ed7e0, 0x28

gUnknown_085ED808:: @ 85ED808
	.incbin "baserom.gba", 0x5ed808, 0x8

gUnknown_085ED810:: @ 85ED810

.string "Pressing Speed:$"

gUnknown_085ED820:: @ 85ED820
	.incbin "baserom.gba", 0x5ed820, 0xc

gUnknown_085ED82C:: @ 85ED82C
	.incbin "baserom.gba", 0x5ed82c, 0x4

gUnknown_085ED830:: @ 85ED830
	.incbin "baserom.gba", 0x5ed830, 0x8

gUnknown_085ED838:: @ 85ED838
	.incbin "baserom.gba", 0x5ed838, 0x8

gUnknown_085ED840:: @ 85ED840
	.incbin "baserom.gba", 0x5ed840, 0x8

gUnknown_085ED848:: @ 85ED848
	.incbin "baserom.gba", 0x5ed848, 0x8

gUnknown_085ED850:: @ 85ED850

.string " Times/sec.$"

gUnknown_085ED85C:: @ 85ED85C

.string "{STR_VAR_1}%$"

gUnknown_085ED860:: @ 85ED860

.string "No. of Presses Rankings$"

gUnknown_085ED878:: @ 85ED878

.string "Crushing Results$"
.string "   Neatness Rankings$"
.string "  Cooperative Rankings$"
.string "   Pressing-Power Rankings$"

gUnknown_085ED8D0:: @ 85ED8D0

.string "BERRY CRUSH$"

gUnknown_085ED8DC:: @ 85ED8DC

.string "Pressing-Speed Rankings$"

gUnknown_085ED8F4:: @ 85ED8F4

.string "{STR_VAR_1} PLAYERS$"

gUnknown_085ED8FF:: @ 85ED8FF

.string "Symbols Earned$"

gUnknown_085ED90E:: @ 85ED90E

.string "Battle Record$"

gUnknown_085ED91C:: @ 85ED91C

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

gUnknown_085EDCC3:: @ 85EDCC3

.string "PLAYER$"

gUnknown_085EDCCA:: @ 85EDCCA

.string "TIME$"

gUnknown_085EDCCF:: @ 85EDCCF

.string "POKéDEX$"

gUnknown_085EDCD7:: @ 85EDCD7

.string "BADGES$"

gUnknown_085EDCDE:: @ 85EDCDE

.string "POWDER$"

gUnknown_085EDCE5:: @ 85EDCE5

.string "DODRIO BERRY-PICKING RECORDS$"
.string "BERRIES picked:$"
.string "Best score:$"
.string "BERRIES picked in a row with\nfive players:$"

gUnknown_085EDD49:: @ 85EDD49

.string "Announcing BERRY-PICKING results!$"

gUnknown_085EDD6B:: @ 85EDD6B
	.incbin "baserom.gba", 0x5edd6b, 0x1b
    
gUnknown_085EDD86:: @ 85EDD86

.string "Announcing rankings!$"

gUnknown_085EDD9B:: @ 85EDD9B

.string "Announcing prizes!$"
.string "1:$"
.string "2:$"
.string "3:$"
.string "4:$"
.string "5:$"

gUnknown_085EDDBD:: @ 85EDDBD

.string "The first-place winner gets\nthis {SPECIAL_F7} !$"

gUnknown_085EDDE2:: @ 85EDDE2

.string "You can’t hold any more!$"

gUnknown_085EDDFB:: @ 85EDDFB

.string "It filled its storage space.$"

gUnknown_085EDE18:: @ 85EDE18

.string "Want to play again?$"

gUnknown_085EDE2C:: @ 85EDE2C

.string "Somebody dropped out.\nThe link will be canceled.$"

gUnknown_085EDE5D:: @ 85EDE5D

.string " points$"

gUnknown_085EDE65:: @ 85EDE65

.string "Communication standby…$"

gUnknown_085EDE7C:: @ 85EDE7C

.string " points$"

gUnknown_085EDE84:: @ 85EDE84

.string " time(s)$"

gUnknown_085EDE8D:: @ 85EDE8D

.string "POKéMON JUMP RECORDS$"
.string "Jumps in a row:$"
.string "Best score:$"
.string "EXCELLENTS in a row:$"

gUnknown_085EDED3:: @ 85EDED3

.string "Awesome score! You’ve\nwon {SPECIAL_F7}À {SPECIAL_F7} !$"

gUnknown_085EDEF4:: @ 85EDEF4

.string "It filled its storage space.$"

gUnknown_085EDF11:: @ 85EDF11

.string "You can’t hold any more!$"

gUnknown_085EDF2A:: @ 85EDF2A

.string "Want to play again?$"

gUnknown_085EDF3E:: @ 85EDF3E

.string "Somebody dropped out.\nThe link will be canceled.$"

gUnknown_085EDF6F:: @ 85EDF6F

.string "Communication standby…$"

gUnknown_085EDF86:: @ 85EDF86

.string "{PLAYER}’s Link Contest Results$"

gUnknown_085EDFA0:: @ 85EDFA0

.string "1st$"

gUnknown_085EDFA4:: @ 85EDFA4

.string "2nd$"

gUnknown_085EDFA8:: @ 85EDFA8

.string "3rd$"

gUnknown_085EDFAC:: @ 85EDFAC

.string "4th$"

gUnknown_085EDFB0:: @ 85EDFB0

.string "Friend$"
.string "POKeMON$"

gUnknown_085EDFBF:: @ 85EDFBF

.string "êÏぎßóúÁóç$"

gUnknown_085EDFC9:: @ 85EDFC9

.string "{248} ÌっÛÁ {248}Àôòñ$"

gUnknown_085EDFD6:: @ 85EDFD6
	.incbin "baserom.gba", 0x5edfd6, 0x1f

gUnknown_085EDFF5:: @ 85EDFF5
	.incbin "baserom.gba", 0x5edff5, 0x1f

gUnknown_085EE014:: @ 85EE014
	.incbin "baserom.gba", 0x5ee014, 0x48

gUnknown_085EE05C:: @ 85EE05C
	.incbin "baserom.gba", 0x5ee05c, 0xf

gUnknown_085EE06B:: @ 85EE06B
	.incbin "baserom.gba", 0x5ee06b, 0x2c

gUnknown_085EE097:: @ 85EE097
	.incbin "baserom.gba", 0x5ee097, 0xc

gUnknown_085EE0A3:: @ 85EE0A3
	.incbin "baserom.gba", 0x5ee0a3, 0x1c

gUnknown_085EE0BF:: @ 85EE0BF
	.incbin "baserom.gba", 0x5ee0bf, 0x1d

gUnknown_085EE0DC:: @ 85EE0DC
	.incbin "baserom.gba", 0x5ee0dc, 0x1e

gUnknown_085EE0FA:: @ 85EE0FA
	.incbin "baserom.gba", 0x5ee0fa, 0xd

gUnknown_085EE107:: @ 85EE107
	.incbin "baserom.gba", 0x5ee107, 0x19

gUnknown_085EE120:: @ 85EE120
	.incbin "baserom.gba", 0x5ee120, 0xd

gUnknown_085EE12D:: @ 85EE12D
	.incbin "baserom.gba", 0x5ee12d, 0x2b
    
gUnknown_085EE158:: @ 85EE158

.string "{PLAYER}’s Single Battle Room Results$"

gUnknown_085EE178:: @ 85EE178

.string "{PLAYER}’s Double Battle Room Results$"

gUnknown_085EE198:: @ 85EE198

.string "{PLAYER}’s Multi Battle Room Results$"

gUnknown_085EE1B7:: @ 85EE1B7

.string "{PLAYER}’s Link Multi Battle Room Results$"

gUnknown_085EE1DB:: @ 85EE1DB

.string "{PLAYER}’s Single Battle Tourney Results$"

gUnknown_085EE1FE:: @ 85EE1FE

.string "{PLAYER}’s Double Battle Tourney Results$"

gUnknown_085EE221:: @ 85EE221

.string "{PLAYER}’s Single Battle Hall Results$"

gUnknown_085EE241:: @ 85EE241

.string "{PLAYER}’s Double Battle Hall Results$"

gUnknown_085EE261:: @ 85EE261

.string "{PLAYER}’s Battle Choice Results$"

gUnknown_085EE27C:: @ 85EE27C

.string "{PLAYER}’s Set KO Tourney Results$"

gUnknown_085EE298:: @ 85EE298

.string "{PLAYER}’s Battle Swap Single Results$"

gUnknown_085EE2B8:: @ 85EE2B8

.string "{PLAYER}’s Battle Swap Double Results$"

gUnknown_085EE2D8:: @ 85EE2D8

.string "{PLAYER}’s Battle Quest Results$"

gUnknown_085EE2F2:: @ 85EE2F2

.string "LV. 50$"

gUnknown_085EE2F9:: @ 85EE2F9

.string "OPEN LV.$"

gUnknown_085EE302:: @ 85EE302

.string "Win streak: {STR_VAR_1}$"

gUnknown_085EE311:: @ 85EE311

.string "CURRENT$"

gUnknown_085EE319:: @ 85EE319

.string "RECORD$"

gUnknown_085EE320:: @ 85EE320

.string "PREV.$"

gUnknown_085EE326:: @ 85EE326

.string "Rental/Swap$"

gUnknown_085EE332:: @ 85EE332

.string "Total$"

gUnknown_085EE338:: @ 85EE338

.string "Clear streak: {STR_VAR_1}$"

gUnknown_085EE349:: @ 85EE349

.string "Championships: {STR_VAR_1}$"

gUnknown_085EE35B:: @ 85EE35B

.string "Rooms cleared: {STR_VAR_1}$"

gUnknown_085EE36D:: @ 85EE36D

.string "Times cleared:{CLEAR}È{STR_VAR_1}$"

gUnknown_085EE381:: @ 85EE381

.string "KOs in a row: {STR_VAR_1}$"

gUnknown_085EE392:: @ 85EE392

.string "Times: {STR_VAR_1}$"

gUnknown_085EE39C:: @ 85EE39C
	.incbin "baserom.gba", 0x5ee39c, 0x88

gUnknown_085EE424:: @ 85EE424

.string "1.$"
.string "2.$"
.string "3.$"

gUnknown_085EE42D:: @ 85EE42D

.string "SAVING…\nDON’T TURN OFF THE POWER.$"

gUnknown_085EE44F:: @ 85EE44F

.string "BERRY BLENDER\nMAXIMUM SPEED RECORD!$"

gUnknown_085EE473:: @ 85EE473

.string "2 PLAYERS\n3 PLAYERS\n4 PLAYERS$"

gUnknown_085EE491:: @ 85EE491

.string "YES\nNO$"

gUnknown_085EE498:: @ 85EE498

.string "▶$"

gUnknown_085EE49A:: @ 85EE49A

.string "PEEKABOO!$"

gUnknown_085EE4A4:: @ 85EE4A4

.string "Communication error…\nPlease check all connections,\nthen turn the power OFF and ON.$"

gUnknown_085EE4F7:: @ 85EE4F7

.string "Communication error…$"

gUnknown_085EE50C:: @ 85EE50C

.string "Move closer to your link partner(s).\nAvoid obstacles between partners.$"

gUnknown_085EE553:: @ 85EE553

.string "A Button: Registration Counter$"

gUnknown_085EE572:: @ 85EE572

.string "A Button: Title Screen$"

gUnknown_085EE589:: @ 85EE589

.string "OPTION$"
.string "TEXT SPEED$"
.string "BATTLE SCENE$"
.string "BATTLE STYLE$"
.string "SOUND$"
.string "FRAME$"
.string "CANCEL$"
.string "BUTTON MODE$"

gUnknown_085EE5D4:: @ 85EE5D4

.string "{COLOR CYAN}{SHADOW MAGENTA}SLOW$"

gUnknown_085EE5DF:: @ 85EE5DF

.string "{COLOR CYAN}{SHADOW MAGENTA}MID$"

gUnknown_085EE5E9:: @ 85EE5E9

.string "{COLOR CYAN}{SHADOW MAGENTA}FAST$"

gUnknown_085EE5F4:: @ 85EE5F4

.string "{COLOR CYAN}{SHADOW MAGENTA}ON$"

gUnknown_085EE5FD:: @ 85EE5FD

.string "{COLOR CYAN}{SHADOW MAGENTA}OFF$"

gUnknown_085EE607:: @ 85EE607

.string "{COLOR CYAN}{SHADOW MAGENTA}SHIFT$"

gUnknown_085EE613:: @ 85EE613

.string "{COLOR CYAN}{SHADOW MAGENTA}SET$"

gUnknown_085EE61D:: @ 85EE61D

.string "{COLOR CYAN}{SHADOW MAGENTA}MONO$"

gUnknown_085EE628:: @ 85EE628

.string "{COLOR CYAN}{SHADOW MAGENTA}STEREO$"

gUnknown_085EE635:: @ 85EE635

.string "{COLOR CYAN}{SHADOW MAGENTA}TYPE$"

gUnknown_085EE640:: @ 85EE640

.string "{COLOR CYAN}{SHADOW MAGENTA}$"

gUnknown_085EE647:: @ 85EE647

.string "{COLOR CYAN}{SHADOW MAGENTA}NORMAL$"

gUnknown_085EE654:: @ 85EE654

.string "{COLOR CYAN}{SHADOW MAGENTA}LR$"

gUnknown_085EE65D:: @ 85EE65D

.string "{COLOR CYAN}{SHADOW MAGENTA}L=A$"

gUnknown_085EE667:: @ 85EE667

.string "{STR_VAR_1}P LINK$"
.string "BRONZE$"
.string "COPPER$"
.string "SILVER$"
.string "GOLD$"

gUnknown_085EE68A:: @ 85EE68A

.string "DAY$"

gUnknown_085EE68E:: @ 85EE68E

.string ":$"

gUnknown_085EE690:: @ 85EE690

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

gOtherText_SafariStock:: @ 85EE6FF

.string "SAFARI BALLS\nStock: {STR_VAR_1}$"

gOtherText_BattlePyramid_X:: @ 85EE716

.string "Battle Pyramid\n{STR_VAR_1}$"
.string "Floor 1$"
.string "Floor 2$"
.string "Floor 3$"
.string "Floor 4$"
.string "Floor 5$"
.string "Floor 6$"
.string "Floor 7$"
.string "Peak$"

gUnknown_085EE765:: @ 85EE765

.string "Link standby…\n… … B Button: Cancel$"

gUnknown_085EE788:: @ 85EE788

.string "Press the A Button to load event.\n… … B Button: Cancel$"

gUnknown_085EE7BF:: @ 85EE7BF

.string "Loading event…$"

gUnknown_085EE7CE:: @ 85EE7CE

.string "Don’t remove the Game Link cable.\nDon’t turn off the power.$"

gUnknown_085EE80A:: @ 85EE80A

.string "The event was safely loaded.$"

gUnknown_085EE827:: @ 85EE827
	.incbin "baserom.gba", 0x5ee827, 0x28

gUnknown_085EE84F:: @ 85EE84F

.string "HOENN$"

gUnknown_085EE855:: @ 85EE855

.string "NATIONAL$"

gUnknown_085EE85E:: @ 85EE85E
	.incbin "baserom.gba", 0x5ee85e, 0x93

gUnknown_085EE8F1:: @ 85EE8F1

.string "HOENN$"

gUnknown_085EE8F7:: @ 85EE8F7

.string "Oh! A bite!$"

gUnknown_085EE903:: @ 85EE903

.string "A POKéMON’s on the hook!{PAUSE_UNTIL_PRESS}$"

gUnknown_085EE91E:: @ 85EE91E

.string "Not even a nibble…{PAUSE_UNTIL_PRESS}$"

gUnknown_085EE933:: @ 85EE933

.string "It got away…{PAUSE_UNTIL_PRESS}$"

gUnknown_085EE942:: @ 85EE942

.string "{STR_VAR_2} will be\nsent to {STR_VAR_1}.$"

gUnknown_085EE959:: @ 85EE959

.string "Bye-bye, {STR_VAR_2}!$"

gUnknown_085EE966:: @ 85EE966

.string "{STR_VAR_1} sent over {STR_VAR_3}.$"

gUnknown_085EE977:: @ 85EE977

.string "Take good care of {STR_VAR_3}!$"


	.include "data/text/easy_chat/easy_chat_group_names.inc"

gUnknown_085EEA42:: @ 85EEA42

.string "???$"
.string "MAX. HP$"
.string "ATTACK$"
.string "DEFENSE$"
.string "SPEED$"
.string "SP. ATK$"
.string "SP. DEF$"

gUnknown_085EEA73:: @ 85EEA73

.string "{249}Ç$"

gUnknown_085EEA76:: @ 85EEA76

.string "-$"

gUnknown_085EEA78:: @ 85EEA78

.string "From $"

gUnknown_085EEA7E:: @ 85EEA7E

.string "Mixing records…$"

gUnknown_085EEA8E:: @ 85EEA8E

.string "Record mixing completed.\nThank you for waiting.$"
.string "YOUR NAME?$"
.string "BOX NAME?$"
.string "{STR_VAR_1}’s nickname?$"
.string "Tell him the words.$"

gUnknown_085EEAF6:: @ 85EEAF6

.string "{248}ÏMOVE  {248} OK  {248}ÀBACK$"

gUnknown_085EEB0B:: @ 85EEB0B

.string "A call can’t be made from here.$"
.string "HANDSOME$"
.string "VINNY$"
.string "MOREME$"
.string "IRONHARD$"
.string "MUSCLE$"
.string "coolness$"
.string "beauty$"
.string "cuteness$"
.string "smartness$"
.string "toughness$"

gUnknown_085EEB7E:: @ 85EEB7E

.string "Lady$"
.string "slippery$"
.string "roundish$"
.string "wham-ish$"
.string "shiny$"
.string "sticky$"
.string "pointy$"

gUnknown_085EEBB2:: @ 85EEBB2

.string "RENTAL POKéMON$"

gUnknown_085EEBC1:: @ 85EEBC1

.string "Select the first POKéMON.$"

gUnknown_085EEBDB:: @ 85EEBDB

.string "Select the second POKéMON.$"

gUnknown_085EEBF6:: @ 85EEBF6

.string "Select the third POKéMON.$"

gUnknown_085EEC10:: @ 85EEC10

.string "RENT$"

gUnknown_085EEC15:: @ 85EEC15

.string "SUMMARY$"

gUnknown_085EEC1D:: @ 85EEC1D

.string "OTHERS$"

gUnknown_085EEC24:: @ 85EEC24

.string "DESELECT$"

gUnknown_085EEC2D:: @ 85EEC2D

.string "Are these three POKéMON OK?$"

gUnknown_085EEC49:: @ 85EEC49

.string "YES$"

gUnknown_085EEC4D:: @ 85EEC4D

.string "NO$"

gUnknown_085EEC50:: @ 85EEC50

.string "Can’t select same {PKMN}.$"

gUnknown_085EEC66:: @ 85EEC66

.string "POKéMON SWAP$"

gUnknown_085EEC73:: @ 85EEC73

.string "Select POKéMON to swap.$"

gUnknown_085EEC8B:: @ 85EEC8B

.string "Select POKéMON to accept.$"

gUnknown_085EECA5:: @ 85EECA5

.string "SWAP$"

gUnknown_085EECAA:: @ 85EECAA

.string "SUMMARY$"

gUnknown_085EECB2:: @ 85EECB2

.string "RECHOOSE$"

gUnknown_085EECBB:: @ 85EECBB

.string "Quit swapping?$"

gUnknown_085EECCA:: @ 85EECCA

.string "YES$"

gUnknown_085EECCE:: @ 85EECCE

.string "NO$"

gUnknown_085EECD1:: @ 85EECD1

.string "{PKMN} FOR SWAP$"

gUnknown_085EECDD:: @ 85EECDD

.string "CANCEL$"
.string "SWAP$"
.string "ACCEPT$"

gUnknown_085EECF0:: @ 85EECF0

.string "Accept this POKéMON?$"
.string "    $"

gUnknown_085EED0A:: @ 85EED0A

.string "Same {PKMN} in party already.$"

gOtherText_DecimalPoint:: @ 85EED24

.string ".$"

gUnknown_085EED26:: @ 85EED26

.string "PLAYER$"

gUnknown_085EED2D:: @ 85EED2D

.string "BADGES$"

gUnknown_085EED34:: @ 85EED34

.string "POKéDEX$"

gUnknown_085EED3C:: @ 85EED3C

.string "TIME$"
.string "Wireless Communication Status$"
.string "People trading:$"
.string "People battling:$"
.string "People in the UNION ROOM:$"
.string "People communicating:$"
.string "{SPECIAL_F7}  players$"
.string "{SPECIAL_F7}À players$"
.string "{SPECIAL_F7}Á players$"
.string "{SPECIAL_F7}Â players$"
.string "…yセËAyセËLyセËWyセËWONDER CARDS$"
.string "   WONDER NEWS$"
.string "WIRELESS COMMUNICATION$"
.string " FRIEND$"
.string " EXIT$"
.string "   RECEIVE$"
.string "SEND$"
.string "   TOSS$"
.string "   A variety of events will be imported\nover Wireless Communication.$"
.string "  Read the WONDER CARDS in your\npossession.$"
.string "  Read the NEWS that arrived.$"
.string "Return to the title screen.$"

gUnknown_085EEEF0:: @ 85EEEF0
	.incbin "baserom.gba", 0x5eeef0, 0x3c

gUnknown_085EEF2C:: @ 85EEF2C
	.incbin "baserom.gba", 0x5eef2c, 0x3c

gUnknown_085EEF68:: @ 85EEF68
	.incbin "baserom.gba", 0x5eef68, 0x2c

gUnknown_085EEF94:: @ 85EEF94

.string "Where should the WONDER NEWS\nbe accessed?$"
.string "  Communication standby…\nB Button: Cancel$"

gUnknown_085EEFE8:: @ 85EEFE8
	.incbin "baserom.gba", 0x5eefe8, 0x10

gUnknown_085EEFF8:: @ 85EEFF8
	.incbin "baserom.gba", 0x5eeff8, 0x1c

gUnknown_085EF014:: @ 85EF014
	.incbin "baserom.gba", 0x5ef014, 0x18

gUnknown_085EF02C:: @ 85EF02C
	.incbin "baserom.gba", 0x5ef02c, 0x24

gUnknown_085EF050:: @ 85EF050
	.incbin "baserom.gba", 0x5ef050, 0x34

gUnknown_085EF084:: @ 85EF084
	.incbin "baserom.gba", 0x5ef084, 0x44

gUnknown_085EF0C8:: @ 85EF0C8
	.incbin "baserom.gba", 0x5ef0c8, 0x2c

gUnknown_085EF0F4:: @ 85EF0F4
	.incbin "baserom.gba", 0x5ef0f4, 0x30

gUnknown_085EF124:: @ 85EF124
	.incbin "baserom.gba", 0x5ef124, 0x28

gUnknown_085EF14C:: @ 85EF14C
	.incbin "baserom.gba", 0x5ef14c, 0x2c

gUnknown_085EF178:: @ 85EF178
	.incbin "baserom.gba", 0x5ef178, 0x20

gUnknown_085EF198:: @ 85EF198
	.incbin "baserom.gba", 0x5ef198, 0x1c

gUnknown_085EF1B4:: @ 85EF1B4
	.incbin "baserom.gba", 0x5ef1b4, 0x24

gUnknown_085EF1D8:: @ 85EF1D8
	.incbin "baserom.gba", 0x5ef1d8, 0x28

gUnknown_085EF200:: @ 85EF200

.string "You already had that\nSTAMP.$"

gUnknown_085EF21C:: @ 85EF21C

.string "There’s no more room for adding\nSTAMPS.$"

gUnknown_085EF244:: @ 85EF244
	.incbin "baserom.gba", 0x5ef244, 0x3c

gUnknown_085EF280:: @ 85EF280
	.incbin "baserom.gba", 0x5ef280, 0x34

gUnknown_085EF2B4:: @ 85EF2B4

.string "You can’t accept WONDER NEWS\nfrom this TRAINER.$"

gUnknown_085EF2E4:: @ 85EF2E4
	.incbin "baserom.gba", 0x5ef2e4, 0x18

gUnknown_085EF2FC:: @ 85EF2FC
	.incbin "baserom.gba", 0x5ef2fc, 0x34

gUnknown_085EF330:: @ 85EF330

.string "What would you like to do\nwith the WONDER NEWS?$"

gUnknown_085EF360:: @ 85EF360
	.incbin "baserom.gba", 0x5ef360, 0x1c

gUnknown_085EF37C:: @ 85EF37C
	.incbin "baserom.gba", 0x5ef37c, 0x20

gUnknown_085EF39C:: @ 85EF39C
	.incbin "baserom.gba", 0x5ef39c, 0x28

gUnknown_085EF3C4:: @ 85EF3C4
	.incbin "baserom.gba", 0x5ef3c4, 0x2c

gUnknown_085EF3F0:: @ 85EF3F0
	.incbin "baserom.gba", 0x5ef3f0, 0x20

gUnknown_085EF410:: @ 85EF410

.string "A GIFT has been sent to {STR_VAR_1}.$"

gUnknown_085EF42C:: @ 85EF42C

.string "The other TRAINER has the same\nWONDER CARD already.$"

gUnknown_085EF460:: @ 85EF460

.string "The other TRAINER has the same\nWONDER NEWS already.$"

gUnknown_085EF494:: @ 85EF494
	.incbin "baserom.gba", 0x5ef494, 0x30

gUnknown_085EF4C4:: @ 85EF4C4
	.incbin "baserom.gba", 0x5ef4c4, 0x2c

gUnknown_085EF4F0:: @ 85EF4F0
	.incbin "baserom.gba", 0x5ef4f0, 0x30

gUnknown_085EF520:: @ 85EF520
	.incbin "baserom.gba", 0x5ef520, 0x3c

gUnknown_085EF55C:: @ 85EF55C
	.incbin "baserom.gba", 0x5ef55c, 0x28

gUnknown_085EF584:: @ 85EF584
	.incbin "baserom.gba", 0x5ef584, 0x38

gUnknown_085EF5BC:: @ 85EF5BC
	.incbin "baserom.gba", 0x5ef5bc, 0x24

gUnknown_085EF5E0:: @ 85EF5E0
	.incbin "baserom.gba", 0x5ef5e0, 0x2c

gUnknown_085EF60C:: @ 85EF60C
	.incbin "baserom.gba", 0x5ef60c, 0x24

gUnknown_085EF630:: @ 85EF630
	.incbin "baserom.gba", 0x5ef630, 0x24

gUnknown_085EF654:: @ 85EF654
	.incbin "baserom.gba", 0x5ef654, 0x10

gUnknown_085EF664:: @ 85EF664
	.incbin "baserom.gba", 0x5ef664, 0x14

gUnknown_085EF678:: @ 85EF678

.string "{248}こPICK {248} OK {248}ÀCANCEL$"

gUnknown_085EF68D:: @ 85EF68D

.string "{PLAYER}’s BATTLE RESULTS$"

gUnknown_085EF6A1:: @ 85EF6A1

.string "TOTAL RECORD W:{STR_VAR_1} L:{STR_VAR_2} D:{STR_VAR_3}$"

gUnknown_085EF6BD:: @ 85EF6BD
	.incbin "baserom.gba", 0x5ef6bd, 0x15
    
gUnknown_085EF6D2:: @ 85EF6D2

.string "Communication standby…$"

gUnknown_085EF6E9:: @ 85EF6E9

.string "Quit the game?$"

gUnknown_085EF6F8:: @ 85EF6F8

.string "You’ve got 9,999 COINS.$"

gUnknown_085EF710:: @ 85EF710

.string "You’ve run out of COINS.\nGame over!$"

gUnknown_085EF734:: @ 85EF734

.string "You don’t have three COINS.$"

gUnknown_085EF750:: @ 85EF750

.string "REEL TIME\nHere’s your chance to take\naim and nail marks!\nReel Time continues for the\nawarded number of spins.\nIt all ends on a Big Bonus.$"
.string "The two seem to get along\nvery well.$"
.string "The two seem to get along.$"
.string "The two don’t seem to like\neach other much.$"
.string "The two prefer to play with other\nPOKéMON than each other.$"

gUnknown_085EF881:: @ 85EF881

.string "\n$"

gUnknown_085EF883:: @ 85EF883

.string "EXIT$"

gUnknown_085EF888:: @ 85EF888

.string "{LV}$"

gUnknown_085EF88A:: @ 85EF88A

.string "TIME BOARD$"

gUnknown_085EF895:: @ 85EF895

.string "TIME CLEARED $"

gUnknown_085EF8A3:: @ 85EF8A3

.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"
.string "1F$"
.string "2F$"
.string "3F$"
.string "4F$"

gUnknown_085EF8C2:: @ 85EF8C2

.string "Teach which move to {STR_VAR_1}?$"

gUnknown_085EF8DA:: @ 85EF8DA

.string "Teach {STR_VAR_2}?$"

gUnknown_085EF8E4:: @ 85EF8E4

.string "{STR_VAR_1} learned\n{STR_VAR_2}!$"

gUnknown_085EF8F3:: @ 85EF8F3

.string "{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can’t learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?$"

gUnknown_085EF960:: @ 85EF960

.string "Stop trying to teach\n{STR_VAR_2}?$"

gUnknown_085EF979:: @ 85EF979

.string "{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p$"

gUnknown_085EF9A6:: @ 85EF9A6

.string "{STR_VAR_1} forgot {STR_VAR_3}.\pAnd…\p{STR_VAR_1} learned {STR_VAR_2}.$"
.string "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.$"

gUnknown_085EF9E6:: @ 85EF9E6

.string "Give up trying to teach a new\nmove to {STR_VAR_1}?$"

gUnknown_085EFA10:: @ 85EFA10

.string "Which move should be\nforgotten?\p$"

gUnknown_085EFA31:: @ 85EFA31

.string "BATTLE MOVES$"

gUnknown_085EFA3E:: @ 85EFA3E

.string "CONTEST MOVES$"
.string "TYPE/$"

gUnknown_085EFA52:: @ 85EFA52

.string "PP/$"

gUnknown_085EFA56:: @ 85EFA56

.string "POWER/$"

gUnknown_085EFA5D:: @ 85EFA5D

.string "ACCURACY/$"

gUnknown_085EFA67:: @ 85EFA67

.string "APPEAL$"

gUnknown_085EFA6E:: @ 85EFA6E

.string "JAM$"
.string "KIRA$"
.string "AMY$"
.string "JOHN$"
.string "ROY$"
.string "GABBY$"
.string "ANNA$"

gUnknown_085EFA8F:: @ 85EFA8F

.string "Clear all save data areas?$"

gUnknown_085EFAAA:: @ 85EFAAA

.string "Clearing data…\nPlease wait.$"

gUnknown_085EFAC6:: @ 85EFAC6

.string "Is this the correct time?$"

gUnknown_085EFAE0:: @ 85EFAE0

.string "CONFIRM$"

gUnknown_085EFAE8:: @ 85EFAE8

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

gUnknown_085EFBD2:: @ 85EFBD2

.string "Communication standby…\nAwaiting another player to choose.$"

gUnknown_085EFC0C:: @ 85EFC0C

.string "The battle was refused.{PAUSE 60}$"

gUnknown_085EFC27:: @ 85EFC27

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

gOtherText_PokeBalls:: @ 85EFCD4

.string "POKé BALLS$"

gOtherText_Berry:: @ 85EFCDF

.string "BERRY$"

gOtherText_Berries:: @ 85EFCE5
	.incbin "baserom.gba", 0x5efce5, 0xb

