	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ 81DB67C
	.include "data/event_script_command_function_table.inc"

gScriptCmdTableEnd:: @ 81DBA08
	.incbin "baserom.gba", 0x1dba08, 0x4

gSpecialVars:: @ 81DBA0C
	.incbin "baserom.gba", 0x1dba0c, 0x58

gUnknown_081DBA64:: @ 81DBA64
	.incbin "baserom.gba", 0x1dba64, 0x83c

gUnknown_081DC2A0:: @ 81DC2A0
	.incbin "baserom.gba", 0x1dc2a0, 0x2c

gUnknown_081DC2CC:: @ 81DC2CC
	.incbin "baserom.gba", 0x1dc2cc, 0x34ee

gUnknown_081DF7BA:: @ 81DF7BA
	.incbin "baserom.gba", 0x1df7ba, 0x69a3

gUnknown_081E615D:: @ 81E615D
	.incbin "baserom.gba", 0x1e615d, 0xe88f

gUnknown_081F49EC:: @ 81F49EC
	.incbin "baserom.gba", 0x1f49ec, 0x3c21

gUnknown_081F860D:: @ 81F860D
	.incbin "baserom.gba", 0x1f860d, 0x32

gUnknown_081F863F:: @ 81F863F
	.incbin "baserom.gba", 0x1f863f, 0xf14

gUnknown_081F9553:: @ 81F9553
	.incbin "baserom.gba", 0x1f9553, 0x3c

gUnknown_081F958F:: @ 81F958F
	.incbin "baserom.gba", 0x1f958f, 0xf47

gUnknown_081FA4D6:: @ 81FA4D6
	.incbin "baserom.gba", 0x1fa4d6, 0x18ba5

gUnknown_0821307B:: @ 821307B
	.incbin "baserom.gba", 0x21307b, 0x110dd

gUnknown_08224158:: @ 8224158
	.incbin "baserom.gba", 0x224158, 0xf

gUnknown_08224167:: @ 8224167
	.incbin "baserom.gba", 0x224167, 0xe

gUnknown_08224175:: @ 8224175
	.incbin "baserom.gba", 0x224175, 0x14d3a

gUnknown_08238EAF:: @ 8238EAF
	.incbin "baserom.gba", 0x238eaf, 0x54a

gUnknown_082393F9:: @ 82393F9
	.incbin "baserom.gba", 0x2393f9, 0x20c2

gUnknown_0823B4BB:: @ 823B4BB
	.incbin "baserom.gba", 0x23b4bb, 0x2d

gUnknown_0823B4E8:: @ 823B4E8
	.incbin "baserom.gba", 0x23b4e8, 0xa1

gUnknown_0823B589:: @ 823B589
	.incbin "baserom.gba", 0x23b589, 0x60

gUnknown_0823B5E9:: @ 823B5E9
	.incbin "baserom.gba", 0x23b5e9, 0x9b

gUnknown_0823B684:: @ 823B684
	.incbin "baserom.gba", 0x23b684, 0x8

gUnknown_0823B68C:: @ 823B68C
	.incbin "baserom.gba", 0x23b68c, 0x9c4

gUnknown_0823C050:: @ 823C050
	.incbin "baserom.gba", 0x23c050, 0x6431

gText_BattleRecordCouldntBeSaved:: @ 8242481
	.incbin "baserom.gba", 0x242481, 0x87b

gUnknown_08242CFC:: @ 8242CFC
	.incbin "baserom.gba", 0x242cfc, 0x6a91

gText_LinkStandby3:: @ 824978D
	.string "Link standby…$"

gUnknown_0824979B:: @ 824979B
	.incbin "baserom.gba", 0x24979b, 0x944d

gUnknown_08252BE8:: @ 8252BE8
	.incbin "baserom.gba", 0x252be8, 0x67

gUnknown_08252C4F:: @ 8252C4F
	.incbin "baserom.gba", 0x252c4f, 0x1b

gUnknown_08252C6A:: @ 8252C6A
	.incbin "baserom.gba", 0x252c6a, 0x1e

gUnknown_08252C88:: @ 8252C88
	.incbin "baserom.gba", 0x252c88, 0x1f

gUnknown_08252CA7:: @ 8252CA7
	.incbin "baserom.gba", 0x252ca7, 0x54

gUnknown_08252CFB:: @ 8252CFB
	.incbin "baserom.gba", 0x252cfb, 0x151e0

gUnknown_08267EDB:: @ 8267EDB
	.incbin "baserom.gba", 0x267edb, 0x234f

gUnknown_0826A22A:: @ 826A22A
	.incbin "baserom.gba", 0x26a22a, 0x712a

gUnknown_08271354:: @ 8271354
	.incbin "baserom.gba", 0x271354, 0xe

gUnknown_08271362:: @ 8271362
	.incbin "baserom.gba", 0x271362, 0x28

gUnknown_0827138A:: @ 827138A
	.incbin "baserom.gba", 0x27138a, 0x38

gUnknown_082713C2:: @ 82713C2
	.incbin "baserom.gba", 0x2713c2, 0xf

gUnknown_082713D1:: @ 82713D1
	.incbin "baserom.gba", 0x2713d1, 0x27

gUnknown_082713F8:: @ 82713F8
	.incbin "baserom.gba", 0x2713f8, 0x1e6

gUnknown_082715DE:: @ 82715DE
	.incbin "baserom.gba", 0x2715de, 0x279

gUnknown_08271857:: @ 8271857
	.incbin "baserom.gba", 0x271857, 0xb

gUnknown_08271862:: @ 8271862
	.incbin "baserom.gba", 0x271862, 0x455

gUnknown_08271CB7:: @ 8271CB7
	.incbin "baserom.gba", 0x271cb7, 0xdb

gUnknown_08271D92:: @ 8271D92
	.incbin "baserom.gba", 0x271d92, 0x10e

gUnknown_08271EA0:: @ 8271EA0
	.incbin "baserom.gba", 0x271ea0, 0x1ef

gUnknown_0827208F:: @ 827208F
	.incbin "baserom.gba", 0x27208f, 0x53f

gUnknown_082725CE:: @ 82725CE
	.incbin "baserom.gba", 0x2725ce, 0x9

gUnknown_082725D7:: @ 82725D7
	.incbin "baserom.gba", 0x2725d7, 0x9

gUnknown_082725E0:: @ 82725E0
	.incbin "baserom.gba", 0x2725e0, 0x9

gUnknown_082725E9:: @ 82725E9
	.incbin "baserom.gba", 0x2725e9, 0x9

gUnknown_082725F2:: @ 82725F2
	.incbin "baserom.gba", 0x2725f2, 0x9

gUnknown_082725FB:: @ 82725FB
	.incbin "baserom.gba", 0x2725fb, 0x9

gUnknown_08272604:: @ 8272604
	.incbin "baserom.gba", 0x272604, 0x6b

gUnknown_0827266F:: @ 827266F
	.string "Which PC should be accessed?$"


gUnknown_0827268C:: @ 827268C
	.string "Accessed SOMEONE’S PC.$"


gUnknown_082726A3:: @ 82726A3
	.string "POKéMON Storage System opened.$"


gUnknown_082726C2:: @ 82726C2
	.string "Accessed {PLAYER}’s PC.$"


gUnknown_082726D4:: @ 82726D4
	.string "Accessed LANETTE’s PC.$"


gUnknown_082726EB:: @ 82726EB
	.string "Hello, and welcome to\nthe POKéMON CENTER.\pWe restore your tired POKéMON\nto full health.\pWould you like to rest your POKéMON?$"


gUnknown_08272768:: @ 8272768
	.string "Okay, I’ll take your POKéMON\nfor a few seconds.$"


gUnknown_08272798:: @ 8272798
	.string "Thank you for waiting.\pWe’ve restored your POKéMON\nto full health.$"


gUnknown_082727DB:: @ 82727DB
	.string "We hope to see you again!$"


gUnknown_082727F5:: @ 82727F5
	.string "Hello, and welcome to\nthe POKéMON CENTER.\pWe restore your tired POKéMON\nto full health.\pWould you like to…$"


gUnknown_08272860:: @ 8272860
	.string "Th-that card…\nCould it be… The GOLD CARD?!\pOh, the gold color is brilliant!\nThe four stars seem to sparkle!\pI’ve seen several TRAINERS with\na SILVER CARD before, but, {PLAYER},\lyou’re the first TRAINER I’ve ever\lseen with a GOLD CARD!\pOkay, {PLAYER}, please allow me\nthe honor of resting your POKéMON!$"


gUnknown_08272982:: @ 8272982
	.string "I’m delighted to see you, {PLAYER}!\nYou want the usual, am I right?$"


gUnknown_082729C0:: @ 82729C0
	.string "Okay, I’ll take your POKéMON\nfor a few seconds.$"


gUnknown_082729F0:: @ 82729F0
	.string "Thank you for waiting.$"


gUnknown_08272A07:: @ 8272A07
	.string "We hope to see you again!$"


gUnknown_08272A21:: @ 8272A21
	.string "Welcome!\pHow may I serve you?$"


gUnknown_08272A3F:: @ 8272A3F
	.string "Please come again!$"


gUnknown_08272A52:: @ 8272A52
	.string "{PLAYER}{STRING 5}, welcome!\pWhat can I do for you?$"


gUnknown_08272A78:: @ 8272A78
	.string "Obtained the {STR_VAR_2}!$"


gUnknown_08272A89:: @ 8272A89
	.string "The BAG is full…$"


gUnknown_08272A9A:: @ 8272A9A
	.string "{PLAYER} put away the {STR_VAR_2}\nin the {STR_VAR_3} POCKET.$"


gUnknown_08272ABF:: @ 8272ABF
	.string "{PLAYER} found one {STR_VAR_2}!$"


gUnknown_08272AD0:: @ 8272AD0
	.string "Too bad!\nThe BAG is full…$"


gUnknown_08272AEA:: @ 8272AEA
	.string "{PLAYER} put away the {STR_VAR_2}\nin the BAG.$"


gUnknown_08272B09:: @ 8272B09
	.string "Obtained the {STR_VAR_2}!$"


gUnknown_08272B1A:: @ 8272B1A
	.string "Too bad! There’s no room left for\nanother {STR_VAR_2}…$"


gUnknown_08272B48:: @ 8272B48
	.string "The {STR_VAR_2} was transferred\nto the PC.$"


gUnknown_08272B6A:: @ 8272B6A
	.string "“Selected items for your convenience!”\nPOKéMON MART$"


gUnknown_08272B9E:: @ 8272B9E
	.string "“Rejuvenate your tired partners!”\nPOKéMON CENTER$"


gUnknown_08272BCF:: @ 8272BCF
	.string "{STR_VAR_1} might like this program.\n… … … … … … … … … … … … … … … …\pBetter get going!$"


gUnknown_08272C1D:: @ 8272C1D
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\pWhich floor would you like?$"


gUnknown_08272C5F:: @ 8272C5F
	.string "The sandstorm is vicious.\nIt’s impossible to keep going.$"


gUnknown_08272C98:: @ 8272C98
	.string "An item in the BAG can be\nregistered to SELECT for easy use.$"


gUnknown_08272CD5:: @ 8272CD5
	.string "There’s an e-mail from POKéMON TRAINER\nSCHOOL.\p… … … … … …\pA POKéMON may learn up to four moves.\pA TRAINER’s expertise is tested on the\nmove sets chosen for POKéMON.\p… … … … … …$"


gUnknown_08272D87:: @ 8272D87
	.string "{PLAYER} booted up the PC.$"


gUnknown_08272D9C:: @ 8272D9C
	.string "The link was canceled.$"


gUnknown_08272DB3:: @ 8272DB3
	.string "Want to give a nickname to\nthe {STR_VAR_2} you received?$"


gUnknown_08272DE3:: @ 8272DE3
	.string "{PLAYER} is out of usable\nPOKéMON!\p{PLAYER} whited out!$"


gUnknown_08272E0F:: @ 8272E0F
	.string "Registered {STR_VAR_1} {STR_VAR_2}\nin the POKéNAV.$"


gUnknown_08272E30:: @ 8272E30
	.string "Do you know the TM SECRET POWER?\pOur group, we love the TM SECRET\nPOWER.\pOne of our members will give it to you.\nCome back and show me if you get it.\pWe’ll accept you as a member and sell\nyou good stuff in secrecy.$"


gUnknown_08272F07:: @ 8272F07
	.string "Your POKéMON may be infected with\nPOKéRUS.\pLittle is known about the POKéRUS\nexcept that they are microscopic life-\lforms that attach to POKéMON.\pWhile infected, POKéMON are said to\ngrow exceptionally well.$"


gUnknown_08272FD6:: @ 8272FD6
	.string "The water is dyed a deep blue…\nWould you like to SURF?$"


gUnknown_0827300D:: @ 827300D
	.string "{STR_VAR_1} used SURF!$"


gUnknown_0827301B:: @ 827301B
	.string "It sounded as if a door opened\nsomewhere far away.$"


gUnknown_0827304E:: @ 827304E
	.string "There is a big hole in the wall.$"


gUnknown_0827306F:: @ 827306F
	.string "I’m terribly sorry.\nThe POKéMON WIRELESS CLUB is\lundergoing adjustments now.$"


gUnknown_082730BC:: @ 82730BC
	.string "It appears to be undergoing\nadjustments…$"


gUnknown_082730E5:: @ 82730E5
	.string "I’m terribly sorry. The TRADE CENTER\nis undergoing inspections.$"


gUnknown_08273125:: @ 8273125
	.string "I’m terribly sorry. The RECORD CORNER\nis under preparation.$"


gUnknown_08273161:: @ 8273161
	.string "{PLAYER} handed over the\n{STR_VAR_1}.$"


gUnknown_08273178:: @ 8273178
	.string "Thank you for accessing the\nMYSTERY GIFT System.$"


gUnknown_082731A9:: @ 82731A9
	.string "{PLAYER} found one {STR_VAR_1}\n{STR_VAR_2}!$"


gUnknown_082731BD:: @ 82731BD
	.string "The weird tree doesn’t like the\nWAILMER PAIL!\pThe weird tree attacked!$"


gUnknown_08273204:: @ 8273204
	.string "The {STR_VAR_1} flew away!$"

gText_PkmnTransferredSomeonesPC:: @ 8273216
	.string "{STR_VAR_2} was transferred to\nSOMEONE’S PC.\pIt was placed in \nBOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC:: @ 8273256
	.string "{STR_VAR_2} was transferred to\nLANETTE’S PC.\pIt was placed in \nBOX “{STR_VAR_1}.”$"

gText_PkmnBoxSomeonesPCFull:: @ 8273296
	.string "BOX “{STR_VAR_3}” on\nSOMEONE’S PC was full.\p{STR_VAR_2} was transferred to\nBOX “{STR_VAR_1}.”$"

gText_PkmnBoxLanettesPCFull:: @ 82732D9
	.string "BOX “{STR_VAR_3}” on\nLANETTE’S PC was full.\p{STR_VAR_2} was transferred to\nBOX “{STR_VAR_1}.”$"


gUnknown_0827331C:: @ 827331C
	.string "There’s no more room for POKéMON!\pThe POKéMON BOXES are full and\ncan’t accept any more!$"


gUnknown_08273374:: @ 8273374
	.string "Do you want to give a nickname to\nthis {STR_VAR_1}?$"


gUnknown_0827339F:: @ 827339F
	.string "There is a questionnaire.\nWould you like to fill it out?$"


gUnknown_082733D8:: @ 82733D8
	.string "Thank you for taking the time to\nfill out our questionnaire.\pYour feedback will be used for\nfuture reference.$"


gUnknown_08273446:: @ 8273446
	.string "Oh, hello!\nYou know those words?\pThat means you must know about\nthe MYSTERY GIFT.\pFrom now on, you should be\nreceiving MYSTERY GIFTS!$"


gUnknown_082734CC:: @ 82734CC
	.string "Once you save your game, you can\naccess the MYSTERY GIFT.$"


gUnknown_08273506:: @ 8273506
	.string "Oh, hello!\nYou know those words?\pThat means you must know about\nthe MYSTERY EVENT.$"


gUnknown_08273559:: @ 8273559
	.string "Once you save your game, you can\naccess the MYSTERY EVENT.$"


gUnknown_08273594:: @ 8273594
	.string "Thank you for using the MYSTERY\nEVENT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"


gUnknown_082735F2:: @ 82735F2
	.string "It appears to be for use at\nthe LILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"


gUnknown_08273656:: @ 8273656
	.string "The massive downpour appears to\nhave stopped…$"


gUnknown_08273684:: @ 8273684
	.string "The intense sunshine appears to\nhave subsided…$"

gUnknown_082736B3:: @ 82736B3
	.incbin "baserom.gba", 0x2736b3, 0x9

gUnknown_082736BC:: @ 82736BC
	.incbin "baserom.gba", 0x2736bc, 0x15f

gUnknown_0827381B:: @ 827381B
	.incbin "baserom.gba", 0x27381b, 0x504

gUnknown_08273D1F:: @ 8273D1F
	.incbin "baserom.gba", 0x273d1f, 0x5c7

gUnknown_082742E6:: @ 82742E6
	.incbin "baserom.gba", 0x2742e6, 0x13

BerryTreeScript:: @ 82742F9
	.incbin "baserom.gba", 0x2742f9, 0x189

gUnknown_08274482:: @ 8274482
	.incbin "baserom.gba", 0x274482, 0x3e

gUnknown_082744C0:: @ 82744C0
	.incbin "baserom.gba", 0x2744c0, 0x4a6

gUnknown_08274966:: @ 8274966
	.incbin "baserom.gba", 0x274966, 0x1be

gUnknown_08274B24:: @ 8274B24
	.incbin "baserom.gba", 0x274b24, 0x1ef

gUnknown_08274D13:: @ 8274D13
	.incbin "baserom.gba", 0x274d13, 0x162

gUnknown_08274E75:: @ 8274E75
	.incbin "baserom.gba", 0x274e75, 0x189

gUnknown_08274FFE:: @ 8274FFE
	.incbin "baserom.gba", 0x274ffe, 0x1e3

gUnknown_082751E1:: @ 82751E1
	.incbin "baserom.gba", 0x2751e1, 0x186

gUnknown_08275367:: @ 8275367
	.incbin "baserom.gba", 0x275367, 0x18f

gUnknown_082754F6:: @ 82754F6
	.incbin "baserom.gba", 0x2754f6, 0x1d1

gUnknown_082756C7:: @ 82756C7
	.incbin "baserom.gba", 0x2756c7, 0x205

gUnknown_082758CC:: @ 82758CC
	.incbin "baserom.gba", 0x2758cc, 0x125

gUnknown_082759F1:: @ 82759F1
	.incbin "baserom.gba", 0x2759f1, 0x95

gUnknown_08275A86:: @ 8275A86
	.incbin "baserom.gba", 0x275a86, 0x59

gUnknown_08275ADF:: @ 8275ADF
	.incbin "baserom.gba", 0x275adf, 0x59

gUnknown_08275B38:: @ 8275B38
	.incbin "baserom.gba", 0x275b38, 0x7f

gUnknown_08275BB7:: @ 8275BB7
	.incbin "baserom.gba", 0x275bb7, 0x155

gUnknown_08275D0C:: @ 8275D0C
	.incbin "baserom.gba", 0x275d0c, 0x13

gUnknown_08275D1F:: @ 8275D1F
	.incbin "baserom.gba", 0x275d1f, 0xf

gUnknown_08275D2E:: @ 8275D2E
	.incbin "baserom.gba", 0x275d2e, 0x974

gUnknown_082766A2:: @ 82766A2
	.incbin "baserom.gba", 0x2766a2, 0x4

gUnknown_082766A6:: @ 82766A6
	.incbin "baserom.gba", 0x2766a6, 0xcbf

gUnknown_08277365:: @ 8277365
	.incbin "baserom.gba", 0x277365, 0xf

gUnknown_08277374:: @ 8277374
	.incbin "baserom.gba", 0x277374, 0xa

gUnknown_0827737E:: @ 827737E
	.incbin "baserom.gba", 0x27737e, 0xa

gUnknown_08277388:: @ 8277388
	.incbin "baserom.gba", 0x277388, 0x1b

gUnknown_082773A3:: @ 82773A3
	.incbin "baserom.gba", 0x2773a3, 0x1b

gUnknown_082773BE:: @ 82773BE
	.incbin "baserom.gba", 0x2773be, 0x1b

gUnknown_082773D9:: @ 82773D9
	.incbin "baserom.gba", 0x2773d9, 0x1c

gUnknown_082773F5:: @ 82773F5
	.incbin "baserom.gba", 0x2773f5, 0xa

gUnknown_082773FF:: @ 82773FF
	.incbin "baserom.gba", 0x2773ff, 0x1e

gUnknown_0827741D:: @ 827741D
	.incbin "baserom.gba", 0x27741d, 0x15

gUnknown_08277432:: @ 8277432
	.incbin "baserom.gba", 0x277432, 0x15

gUnknown_08277447:: @ 8277447
	.incbin "baserom.gba", 0x277447, 0x15

gUnknown_0827745C:: @ 827745C
	.incbin "baserom.gba", 0x27745c, 0x22

gUnknown_0827747E:: @ 827747E
	.incbin "baserom.gba", 0x27747e, 0xf

gUnknown_0827748D:: @ 827748D
	.incbin "baserom.gba", 0x27748d, 0xf

gUnknown_0827749C:: @ 827749C
	.incbin "baserom.gba", 0x27749c, 0x53

gUnknown_082774EF:: @ 82774EF
	.incbin "baserom.gba", 0x2774ef, 0x1a

gUnknown_08277509:: @ 8277509
	.incbin "baserom.gba", 0x277509, 0xa

gUnknown_08277513:: @ 8277513
	.incbin "baserom.gba", 0x277513, 0x677

gUnknown_08277B8A:: @ 8277B8A
	.incbin "baserom.gba", 0x277b8a, 0x507

gUnknown_08278091:: @ 8278091
	.incbin "baserom.gba", 0x278091, 0x22

gUnknown_082780B3:: @ 82780B3
	.incbin "baserom.gba", 0x2780b3, 0x3f

gUnknown_082780F2:: @ 82780F2
	.incbin "baserom.gba", 0x2780f2, 0x3f

gUnknown_08278131:: @ 8278131
	.incbin "baserom.gba", 0x278131, 0x4a51

@ 827CB82
	.include "data/text/contest_text.inc"

gUnknown_0827D507:: @ 827D507
	.incbin "baserom.gba", 0x27d507, 0x2a

gUnknown_0827D531:: @ 827D531
	.incbin "baserom.gba", 0x27d531, 0x29

gUnknown_0827D55A:: @ 827D55A
	.incbin "baserom.gba", 0x27d55a, 0x15

gUnknown_0827D56F:: @ 827D56F
	.incbin "baserom.gba", 0x27d56f, 0x28

gUnknown_0827D597:: @ 827D597
	.incbin "baserom.gba", 0x27d597, 0xd67

gUnknown_0827E2FE:: @ 827E2FE
	.incbin "baserom.gba", 0x27e2fe, 0x30

gUnknown_0827E32E:: @ 827E32E
	.incbin "baserom.gba", 0x27e32e, 0x2d

gUnknown_0827E35B:: @ 827E35B
	.incbin "baserom.gba", 0x27e35b, 0x32

gUnknown_0827E38D:: @ 827E38D
	.incbin "baserom.gba", 0x27e38d, 0x1fd

gUnknown_0827E58A:: @ 827E58A
	.incbin "baserom.gba", 0x27e58a, 0x159

gUnknown_0827E6E3:: @ 827E6E3
	.incbin "baserom.gba", 0x27e6e3, 0x34

gUnknown_0827E717:: @ 827E717
	.incbin "baserom.gba", 0x27e717, 0x25

gUnknown_0827E73C:: @ 827E73C
	.incbin "baserom.gba", 0x27e73c, 0x2e

gUnknown_0827E76A:: @ 827E76A
	.incbin "baserom.gba", 0x27e76a, 0x29

gUnknown_0827E793:: @ 827E793
	.incbin "baserom.gba", 0x27e793, 0x57

gUnknown_0827E7EA:: @ 827E7EA
	.incbin "baserom.gba", 0x27e7ea, 0x2d

gUnknown_0827E817:: @ 827E817
	.incbin "baserom.gba", 0x27e817, 0x20

gUnknown_0827E837:: @ 827E837
	.incbin "baserom.gba", 0x27e837, 0x8

gUnknown_0827E83F:: @ 827E83F
	.incbin "baserom.gba", 0x27e83f, 0x8

gUnknown_0827E847:: @ 827E847
	.incbin "baserom.gba", 0x27e847, 0x9

gUnknown_0827E850:: @ 827E850
	.incbin "baserom.gba", 0x27e850, 0xa

gUnknown_0827E85A:: @ 827E85A
	.incbin "baserom.gba", 0x27e85a, 0x80

gUnknown_0827E8DA:: @ 827E8DA
	.incbin "baserom.gba", 0x27e8da, 0x132

gUnknown_0827EA0C:: @ 827EA0C
	.incbin "baserom.gba", 0x27ea0c, 0x2b0

gUnknown_0827ECBC:: @ 27ECBC
	.incbin "baserom.gba", 0x27ecbc, 0x7

gUnknown_0827ECC3:: @ 27ECC3
	.incbin "baserom.gba", 0x27ecc3, 0xa

gUnknown_0827ECCD:: @ 27ECCD
	.incbin "baserom.gba", 0x27eccd, 0x8

gUnknown_0827ECD5:: @ 27ECD5
	.incbin "baserom.gba", 0x27ecd5, 0x8

gUnknown_0827ECDD:: @ 27ECDD
	.incbin "baserom.gba", 0x27ecdd, 0x6

gUnknown_0827ECE3:: @ 27ECE3
	.incbin "baserom.gba", 0x27ece3, 0x8

gUnknown_0827ECEB:: @ 27ECEB
	.incbin "baserom.gba", 0x27eceb, 0x7

gUnknown_0827ECF2:: @ 27ECF2
	.incbin "baserom.gba", 0x27ecf2, 0x6

gUnknown_0827ECF8:: @ 27ECF8
	.incbin "baserom.gba", 0x27ecf8, 0x8

gUnknown_0827ED00:: @ 27ED00
	.incbin "baserom.gba", 0x27ed00, 0x6

gUnknown_0827ED06:: @ 27ED06
	.incbin "baserom.gba", 0x27ed06, 0xa

gUnknown_0827ED10:: @ 27ED10
	.incbin "baserom.gba", 0x27ed10, 0x8

gUnknown_0827ED18:: @ 27ED18
	.incbin "baserom.gba", 0x27ed18, 0xa

gUnknown_0827ED22:: @ 27ED22
	.incbin "baserom.gba", 0x27ed22, 0xa

gUnknown_0827ED2C:: @ 27ED2C
	.incbin "baserom.gba", 0x27ed2c, 0xa

gUnknown_0827ED36:: @ 27ED36
	.incbin "baserom.gba", 0x27ed36, 0xa

gUnknown_0827ED40:: @ 27ED40
	.incbin "baserom.gba", 0x27ed40, 0x6

gUnknown_0827ED46:: @ 27ED46
	.incbin "baserom.gba", 0x27ed46, 0x9

gUnknown_0827ED4F:: @ 27ED4F
	.incbin "baserom.gba", 0x27ed4f, 0xa

gUnknown_0827ED59:: @ 27ED59
	.incbin "baserom.gba", 0x27ed59, 0xc

gUnknown_0827ED65:: @ 27ED65
	.incbin "baserom.gba", 0x27ed65, 0xb

gUnknown_0827ED70:: @ 27ED70
	.incbin "baserom.gba", 0x27ed70, 0x4

gUnknown_0827ED74:: @ 27ED74
	.incbin "baserom.gba", 0x27ed74, 0x4

gUnknown_0827ED78:: @ 27ED78
	.incbin "baserom.gba", 0x27ed78, 0x8

gUnknown_0827ED80:: @ 27ED80
	.incbin "baserom.gba", 0x27ed80, 0x15

gUnknown_0827ED95:: @ 27ED95
	.incbin "baserom.gba", 0x27ed95, 0x15

gUnknown_0827EDAA:: @ 27EDAA
	.incbin "baserom.gba", 0x27edaa, 0xb

gUnknown_0827EDB5:: @ 27EDB5
	.incbin "baserom.gba", 0x27edb5, 0x5

gUnknown_0827EDBA:: @ 27EDBA
	.incbin "baserom.gba", 0x27edba, 0x7

gUnknown_0827EDC1:: @ 27EDC1
	.incbin "baserom.gba", 0x27edc1, 0x8

gUnknown_0827EDC9:: @ 27EDC9
	.incbin "baserom.gba", 0x27edc9, 0xc

gUnknown_0827EDD5:: @ 27EDD5
	.incbin "baserom.gba", 0x27edd5, 0xf

gUnknown_0827EDE4:: @ 27EDE4
	.incbin "baserom.gba", 0x27ede4, 0xc

gUnknown_0827EDF0:: @ 27EDF0
	.incbin "baserom.gba", 0x27edf0, 0x5

gUnknown_0827EDF5:: @ 27EDF5
	.incbin "baserom.gba", 0x27edf5, 0x2

gUnknown_0827EDF7:: @ 27EDF7
	.incbin "baserom.gba", 0x27edf7, 0x2

gUnknown_0827EDF9:: @ 27EDF9
	.incbin "baserom.gba", 0x27edf9, 0x2

gUnknown_0827EDFB:: @ 27EDFB
	.incbin "baserom.gba", 0x27edfb, 0x2

gUnknown_0827EDFD:: @ 27EDFD
	.incbin "baserom.gba", 0x27edfd, 0x2

gUnknown_0827EDFF:: @ 27EDFF
	.incbin "baserom.gba", 0x27edff, 0x2

gUnknown_0827EE01:: @ 27EE01
	.incbin "baserom.gba", 0x27ee01, 0x2

gUnknown_0827EE03:: @ 27EE03
	.incbin "baserom.gba", 0x27ee03, 0x2

gUnknown_0827EE05:: @ 27EE05
	.incbin "baserom.gba", 0x27ee05, 0x2

gUnknown_0827EE07:: @ 27EE07
	.incbin "baserom.gba", 0x27ee07, 0x2

gUnknown_0827EE09:: @ 27EE09
	.incbin "baserom.gba", 0x27ee09, 0x2

gUnknown_0827EE0B:: @ 827EE0B
	.incbin "baserom.gba", 0x27ee0b, 0x46a

    .include "data/text/tv.inc"

    .incbin "baserom.gba", 0x28e066, 0x269f

gUnknown_08290705:: @ 8290705
	.incbin "baserom.gba", 0x290705, 0xeb

gUnknown_082907F0:: @ 82907F0
	.incbin "baserom.gba", 0x2907f0, 0x10d

gUnknown_082908FD:: @ 82908FD
	.incbin "baserom.gba", 0x2908fd, 0x14c

gUnknown_08290A49:: @ 8290A49
	.incbin "baserom.gba", 0x290a49, 0x3a

gUnknown_08290A83:: @ 8290A83
	.incbin "baserom.gba", 0x290a83, 0x8c

gUnknown_08290B0F:: @ 8290B0F
	.incbin "baserom.gba", 0x290b0f, 0x4b

gUnknown_08290B5A:: @ 8290B5A
	.incbin "baserom.gba", 0x290b5a, 0x154

gUnknown_08290CAE:: @ 8290CAE
	.incbin "baserom.gba", 0x290cae, 0x1312

gUnknown_08291FC0:: @ 8291FC0
	.incbin "baserom.gba", 0x291fc0, 0x738

gUnknown_082926F8:: @ 82926F8
	.incbin "baserom.gba", 0x2926f8, 0x6ed

gUnknown_08292DE5:: @ 8292DE5
	.incbin "baserom.gba", 0x292de5, 0x1518

gUnknown_082942FD:: @ 82942FD
	.incbin "baserom.gba", 0x2942fd, 0x4

gUnknown_08294301:: @ 8294301
	.incbin "baserom.gba", 0x294301, 0x10829

gUnknown_082A4B2A:: @ 82A4B2A
	.incbin "baserom.gba", 0x2a4b2a, 0x22

gUnknown_082A4B4C:: @ 82A4B4C
	.incbin "baserom.gba", 0x2a4b4c, 0x23

gUnknown_082A4B6F:: @ 82A4B6F
	.incbin "baserom.gba", 0x2a4b6f, 0x1b

gUnknown_082A4B8A:: @ 82A4B8A
	.incbin "baserom.gba", 0x2a4b8a, 0x11

gUnknown_082A4B9B:: @ 82A4B9B
	.incbin "baserom.gba", 0x2a4b9b, 0x11

gUnknown_082A4BAC:: @ 82A4BAC
	.incbin "baserom.gba", 0x2a4bac, 0xf66

gUnknown_082A5B12:: @ 82A5B12
	.incbin "baserom.gba", 0x2a5b12, 0x3c

gUnknown_082A5B4E:: @ 82A5B4E
	.incbin "baserom.gba", 0x2a5b4e, 0x1d

gUnknown_082A5B6B:: @ 82A5B6B
	.incbin "baserom.gba", 0x2a5b6b, 0x1e

gUnknown_082A5B89:: @ 82A5B89
	.incbin "baserom.gba", 0x2a5b89, 0x42

gUnknown_082A5BCB:: @ 82A5BCB
	.incbin "baserom.gba", 0x2a5bcb, 0xc

gUnknown_082A5BD7:: @ 82A5BD7
	.incbin "baserom.gba", 0x2a5bd7, 0x9

gUnknown_082A5BE0:: @ 82A5BE0
	.incbin "baserom.gba", 0x2a5be0, 0xf

gUnknown_082A5BEF:: @ 82A5BEF
	.incbin "baserom.gba", 0x2a5bef, 0x15

gUnknown_082A5C04:: @ 82A5C04
	.incbin "baserom.gba", 0x2a5c04, 0xf

gUnknown_082A5C13:: @ 82A5C13
	.incbin "baserom.gba", 0x2a5c13, 0xe

gUnknown_082A5C21:: @ 82A5C21
	.incbin "baserom.gba", 0x2a5c21, 0x40

gUnknown_082A5C61:: @ 82A5C61
	.incbin "baserom.gba", 0x2a5c61, 0x3b

gUnknown_082A5C9C:: @ 82A5C9C
	.incbin "baserom.gba", 0x2a5c9c, 0x90

gUnknown_082A5D2C:: @ 82A5D2C
	.incbin "baserom.gba", 0x2a5d2c, 0x40

gUnknown_082A5D6C:: @ 82A5D6C
	.incbin "baserom.gba", 0x2a5d6c, 0x3f

gUnknown_082A5DAB:: @ 82A5DAB
	.incbin "baserom.gba", 0x2a5dab, 0x46

gUnknown_082A5DF1:: @ 82A5DF1
	.incbin "baserom.gba", 0x2a5df1, 0x43

gUnknown_082A5E34:: @ 82A5E34
	.incbin "baserom.gba", 0x2a5e34, 0x4f

gUnknown_082A5E83:: @ 82A5E83
	.incbin "baserom.gba", 0x2a5e83, 0x36

gUnknown_082A5EB9:: @ 82A5EB9
	.incbin "baserom.gba", 0x2a5eb9, 0x3b

gUnknown_082A5EF4:: @ 82A5EF4
	.incbin "baserom.gba", 0x2a5ef4, 0x45

gUnknown_082A5F39:: @ 82A5F39
	.incbin "baserom.gba", 0x2a5f39, 0x49

gUnknown_082A5F82:: @ 82A5F82
	.incbin "baserom.gba", 0x2a5f82, 0x37

gUnknown_082A5FB9:: @ 82A5FB9
	.incbin "baserom.gba", 0x2a5fb9, 0x5f

gUnknown_082A6018:: @ 82A6018
	.incbin "baserom.gba", 0x2a6018, 0x49

gUnknown_082A6061:: @ 82A6061
	.incbin "baserom.gba", 0x2a6061, 0x3b

gUnknown_082A609C:: @ 82A609C
	.incbin "baserom.gba", 0x2a609c, 0x39

gUnknown_082A60D5:: @ 82A60D5
	.incbin "baserom.gba", 0x2a60d5, 0x4f

gUnknown_082A6124:: @ 82A6124
	.incbin "baserom.gba", 0x2a6124, 0x4b

gUnknown_082A616F:: @ 82A616F
	.incbin "baserom.gba", 0x2a616f, 0x67

gUnknown_082A61D6:: @ 82A61D6
	.incbin "baserom.gba", 0x2a61d6, 0x64

gUnknown_082A623A:: @ 82A623A
	.incbin "baserom.gba", 0x2a623a, 0x4d

gUnknown_082A6287:: @ 82A6287
	.incbin "baserom.gba", 0x2a6287, 0x42

gUnknown_082A62C9:: @ 82A62C9
	.incbin "baserom.gba", 0x2a62c9, 0x49

gUnknown_082A6312:: @ 82A6312
	.incbin "baserom.gba", 0x2a6312, 0x2b

gUnknown_082A633D:: @ 82A633D
	.incbin "baserom.gba", 0x2a633d, 0x1ffa

gUnknown_082A8337:: @ 82A8337
	.incbin "baserom.gba", 0x2a8337, 0x19

gUnknown_082A8350:: @ 82A8350
	.incbin "baserom.gba", 0x2a8350, 0x20043

gUnknown_082C8393:: @ 82C8393
	.incbin "baserom.gba", 0x2c8393, 0x5d

gUnknown_082C83F0:: @ 82C83F0
	.incbin "baserom.gba", 0x2c83f0, 0x46

gUnknown_082C8436:: @ 82C8436
	.incbin "baserom.gba", 0x2c8436, 0x37e

gUnknown_082C87B4:: @ 82C87B4
	.incbin "baserom.gba", 0x2c87b4, 0x21

gUnknown_082C87D5:: @ 82C87D5
	.incbin "baserom.gba", 0x2c87d5, 0x3b

gUnknown_082C8810:: @ 82C8810
	.incbin "baserom.gba", 0x2c8810, 0x22

gUnknown_082C8832:: @ 82C8832
	.incbin "baserom.gba", 0x2c8832, 0x13

gUnknown_082C8845:: @ 82C8845
	.incbin "baserom.gba", 0x2c8845, 0xe5

gUnknown_082C892A:: @ 82C892A
	.incbin "baserom.gba", 0x2c892a, 0x2f

gUnknown_082C8959:: @ 82C8959
	.incbin "baserom.gba", 0x2c8959, 0x22

gUnknown_082C897B:: @ 82C897B
	.incbin "baserom.gba", 0x2c897b, 0xa4

gUnknown_082C8A1F:: @ 82C8A1F
	.incbin "baserom.gba", 0x2c8a1f, 0x1b1

gUnknown_082C8BD0:: @ 82C8BD0
	.incbin "baserom.gba", 0x2c8bd0, 0xd

gUnknown_082C8BDD:: @ 82C8BDD
	.incbin "baserom.gba", 0x2c8bdd, 0x22

gUnknown_082C8BFF:: @ 82C8BFF
	.incbin "baserom.gba", 0x2c8bff, 0x1d

gUnknown_082C8C1C:: @ 82C8C1C
	.incbin "baserom.gba", 0x2c8c1c, 0xe

gUnknown_082C8C2A:: @ 82C8C2A
	.incbin "baserom.gba", 0x2c8c2a, 0x50

gUnknown_082C8C7A:: @ 82C8C7A
	.incbin "baserom.gba", 0x2c8c7a, 0xea
