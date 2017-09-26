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

gUnknown_08242481:: @ 8242481
	.incbin "baserom.gba", 0x242481, 0x87b

gUnknown_08242CFC:: @ 8242CFC
	.incbin "baserom.gba", 0x242cfc, 0x6a91

gUnknown_0824978D:: @ 824978D
	.incbin "baserom.gba", 0x24978d, 0xe

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

gUnknown_0827F275:: @ 0827F275
	.incbin "baserom.gba", 0x27f275, 0x8f

gUnknown_0827F304:: @ 0827F304
	.incbin "baserom.gba", 0x27f304, 0x5d

gUnknown_0827F361:: @ 0827F361
	.incbin "baserom.gba", 0x27f361, 0x83

gUnknown_0827F3E4:: @ 0827F3E4
	.incbin "baserom.gba", 0x27f3e4, 0xbb

gUnknown_0827F49F:: @ 0827F49F
	.incbin "baserom.gba", 0x27f49f, 0xc6

gUnknown_0827F565:: @ 0827F565
	.incbin "baserom.gba", 0x27f565, 0xbf

gUnknown_0827F624:: @ 0827F624
	.incbin "baserom.gba", 0x27f624, 0x38

gUnknown_0827F65C:: @ 0827F65C
	.incbin "baserom.gba", 0x27f65c, 0x8a

gUnknown_0827F6E6:: @ 0827F6E6
	.incbin "baserom.gba", 0x27f6e6, 0x43a

gUnknown_0827FB20:: @ 0827FB20
	.incbin "baserom.gba", 0x27fb20, 0x93

gUnknown_0827FBB3:: @ 0827FBB3
	.incbin "baserom.gba", 0x27fbb3, 0x51

gUnknown_0827FC04:: @ 0827FC04
	.incbin "baserom.gba", 0x27fc04, 0xcd

gUnknown_0827FCD1:: @ 0827FCD1
	.incbin "baserom.gba", 0x27fcd1, 0xc0

gUnknown_0827FD91:: @ 0827FD91
	.incbin "baserom.gba", 0x27fd91, 0x102

gUnknown_0827FE93:: @ 0827FE93
	.incbin "baserom.gba", 0x27fe93, 0xf6

gUnknown_0827FF89:: @ 0827FF89
	.incbin "baserom.gba", 0x27ff89, 0x113

gUnknown_0828009C:: @ 0828009C
	.incbin "baserom.gba", 0x28009c, 0x5

gUnknown_082800A1:: @ 082800A1
	.incbin "baserom.gba", 0x2800a1, 0x5

gUnknown_082800A6:: @ 082800A6
	.incbin "baserom.gba", 0x2800a6, 0x5

gUnknown_082800AB:: @ 082800AB
	.incbin "baserom.gba", 0x2800ab, 0x5

gUnknown_082800B0:: @ 082800B0
	.incbin "baserom.gba", 0x2800b0, 0x6

gUnknown_082800B6:: @ 082800B6
	.incbin "baserom.gba", 0x2800b6, 0x87

gUnknown_0828013D:: @ 0828013D
	.incbin "baserom.gba", 0x28013d, 0xa9

gUnknown_082801E6:: @ 082801E6
	.incbin "baserom.gba", 0x2801e6, 0x6a0

gUnknown_08280886:: @ 08280886
	.incbin "baserom.gba", 0x280886, 0x1be

gUnknown_08280A44:: @ 08280A44
	.incbin "baserom.gba", 0x280a44, 0xb8

gUnknown_08280AFC:: @ 08280AFC
	.incbin "baserom.gba", 0x280afc, 0xc8

gUnknown_08280BC4:: @ 08280BC4
	.incbin "baserom.gba", 0x280bc4, 0xb6

gUnknown_08280C7A:: @ 08280C7A
	.incbin "baserom.gba", 0x280c7a, 0x174

gUnknown_08280DEE:: @ 08280DEE
	.incbin "baserom.gba", 0x280dee, 0x17b

gUnknown_08280F69:: @ 08280F69
	.incbin "baserom.gba", 0x280f69, 0x1f

gUnknown_08280F88:: @ 08280F88
	.incbin "baserom.gba", 0x280f88, 0x21

gUnknown_08280FA9:: @ 08280FA9
	.incbin "baserom.gba", 0x280fa9, 0x2c

gUnknown_08280FD5:: @ 08280FD5
	.incbin "baserom.gba", 0x280fd5, 0x6b

gUnknown_08281040:: @ 08281040
	.incbin "baserom.gba", 0x281040, 0x33

gUnknown_08281073:: @ 08281073
	.incbin "baserom.gba", 0x281073, 0x74

gUnknown_082810E7:: @ 082810E7
	.incbin "baserom.gba", 0x2810e7, 0x3b7

gUnknown_0828149E:: @ 0828149E
	.incbin "baserom.gba", 0x28149e, 0x111

gUnknown_082815AF:: @ 082815AF
	.incbin "baserom.gba", 0x2815af, 0x87

gUnknown_08281636:: @ 08281636
	.incbin "baserom.gba", 0x281636, 0x30

gUnknown_08281666:: @ 08281666
	.incbin "baserom.gba", 0x281666, 0x54

gUnknown_082816BA:: @ 082816BA
	.incbin "baserom.gba", 0x2816ba, 0x31

gUnknown_082816EB:: @ 082816EB
	.incbin "baserom.gba", 0x2816eb, 0x9f

gUnknown_0828178A:: @ 0828178A
	.incbin "baserom.gba", 0x28178a, 0x16a

gUnknown_082818F4:: @ 082818F4
	.incbin "baserom.gba", 0x2818f4, 0xd3

gUnknown_082819C7:: @ 082819C7
	.incbin "baserom.gba", 0x2819c7, 0x68

gUnknown_08281A2F:: @ 08281A2F
	.incbin "baserom.gba", 0x281a2f, 0x7d

gUnknown_08281AAC:: @ 08281AAC
	.incbin "baserom.gba", 0x281aac, 0x7c

gUnknown_08281B28:: @ 08281B28
	.incbin "baserom.gba", 0x281b28, 0x6b

gUnknown_08281B93:: @ 08281B93
	.incbin "baserom.gba", 0x281b93, 0x268

gUnknown_08281DFB:: @ 08281DFB
	.incbin "baserom.gba", 0x281dfb, 0x195

gUnknown_08281F90:: @ 08281F90
	.incbin "baserom.gba", 0x281f90, 0x6a

gUnknown_08281FFA:: @ 08281FFA
	.incbin "baserom.gba", 0x281ffa, 0x58

gUnknown_08282052:: @ 08282052
	.incbin "baserom.gba", 0x282052, 0x60

gUnknown_082820B2:: @ 082820B2
	.incbin "baserom.gba", 0x2820b2, 0x5c

gUnknown_0828210E:: @ 0828210E
	.incbin "baserom.gba", 0x28210e, 0x7c

gUnknown_0828218A:: @ 0828218A
	.incbin "baserom.gba", 0x28218a, 0x114

gUnknown_0828229E:: @ 0828229E
	.incbin "baserom.gba", 0x28229e, 0x79

gUnknown_08282317:: @ 08282317
	.incbin "baserom.gba", 0x282317, 0x86

gUnknown_0828239D:: @ 0828239D
	.incbin "baserom.gba", 0x28239d, 0x7b

gUnknown_08282418:: @ 08282418
	.incbin "baserom.gba", 0x282418, 0x8e

gUnknown_082824A6:: @ 082824A6
	.incbin "baserom.gba", 0x2824a6, 0x7c

gUnknown_08282522:: @ 08282522
	.incbin "baserom.gba", 0x282522, 0x7f

gUnknown_082825A1:: @ 082825A1
	.incbin "baserom.gba", 0x2825a1, 0x82

gUnknown_08282623:: @ 08282623
	.incbin "baserom.gba", 0x282623, 0x91

gUnknown_082826B4:: @ 082826B4
	.incbin "baserom.gba", 0x2826b4, 0x99

gUnknown_0828274D:: @ 0828274D
	.incbin "baserom.gba", 0x28274d, 0x7e

gUnknown_082827CB:: @ 082827CB
	.incbin "baserom.gba", 0x2827cb, 0x7e

gUnknown_08282849:: @ 08282849
	.incbin "baserom.gba", 0x282849, 0x3a

gUnknown_08282883:: @ 08282883
	.incbin "baserom.gba", 0x282883, 0x61

gUnknown_082828E4:: @ 082828E4
	.incbin "baserom.gba", 0x2828e4, 0x2e

gUnknown_08282912:: @ 08282912
	.incbin "baserom.gba", 0x282912, 0x5a

gUnknown_0828296C:: @ 0828296C
	.incbin "baserom.gba", 0x28296c, 0x2a

gUnknown_08282996:: @ 08282996
	.incbin "baserom.gba", 0x282996, 0xa0

gUnknown_08282A36:: @ 08282A36
	.incbin "baserom.gba", 0x282a36, 0x99

gUnknown_08282ACF:: @ 08282ACF
	.incbin "baserom.gba", 0x282acf, 0x2ad

gUnknown_08282D7C:: @ 08282D7C
	.incbin "baserom.gba", 0x282d7c, 0x21f

gUnknown_08282F9B:: @ 08282F9B
	.incbin "baserom.gba", 0x282f9b, 0xb2

gUnknown_0828304D:: @ 0828304D
	.incbin "baserom.gba", 0x28304d, 0xe8

gUnknown_08283135:: @ 08283135
	.incbin "baserom.gba", 0x283135, 0xaa

gUnknown_082831DF:: @ 082831DF
	.incbin "baserom.gba", 0x2831df, 0xb5

gUnknown_08283294:: @ 08283294
	.incbin "baserom.gba", 0x283294, 0xa3

gUnknown_08283337:: @ 08283337
	.incbin "baserom.gba", 0x283337, 0x8f

gUnknown_082833C6:: @ 082833C6
	.incbin "baserom.gba", 0x2833c6, 0xda

gUnknown_082834A0:: @ 082834A0
	.incbin "baserom.gba", 0x2834a0, 0xb2

gUnknown_08283552:: @ 08283552
	.incbin "baserom.gba", 0x283552, 0x5c

gUnknown_082835AE:: @ 082835AE
	.incbin "baserom.gba", 0x2835ae, 0x71

gUnknown_0828361F:: @ 0828361F
	.incbin "baserom.gba", 0x28361f, 0x66

gUnknown_08283685:: @ 08283685
	.incbin "baserom.gba", 0x283685, 0x87

gUnknown_0828370C:: @ 0828370C
	.incbin "baserom.gba", 0x28370c, 0xb6

gUnknown_082837C2:: @ 082837C2
	.incbin "baserom.gba", 0x2837c2, 0x86

gUnknown_08283848:: @ 08283848
	.incbin "baserom.gba", 0x283848, 0x7a

gUnknown_082838C2:: @ 082838C2
	.incbin "baserom.gba", 0x2838c2, 0x88

gUnknown_0828394A:: @ 0828394A
	.incbin "baserom.gba", 0x28394a, 0xa0

gUnknown_082839EA:: @ 082839EA
	.incbin "baserom.gba", 0x2839ea, 0x75

gUnknown_08283A5F:: @ 08283A5F
	.incbin "baserom.gba", 0x283a5f, 0xa6

gUnknown_08283B05:: @ 08283B05
	.incbin "baserom.gba", 0x283b05, 0xaa

gUnknown_08283BAF:: @ 08283BAF
	.incbin "baserom.gba", 0x283baf, 0xd2

gUnknown_08283C81:: @ 08283C81
	.incbin "baserom.gba", 0x283c81, 0xb1

gUnknown_08283D32:: @ 08283D32
	.incbin "baserom.gba", 0x283d32, 0x67

gUnknown_08283D99:: @ 08283D99
	.incbin "baserom.gba", 0x283d99, 0x8f

gUnknown_08283E28:: @ 08283E28
	.incbin "baserom.gba", 0x283e28, 0xd9

gUnknown_08283F01:: @ 08283F01
	.incbin "baserom.gba", 0x283f01, 0x71

gUnknown_08283F72:: @ 08283F72
	.incbin "baserom.gba", 0x283f72, 0x37

gUnknown_08283FA9:: @ 08283FA9
	.incbin "baserom.gba", 0x283fa9, 0x3e

gUnknown_08283FE7:: @ 08283FE7
	.incbin "baserom.gba", 0x283fe7, 0xb7

gUnknown_0828409E:: @ 0828409E
	.incbin "baserom.gba", 0x28409e, 0x30

gUnknown_082840CE:: @ 082840CE
	.incbin "baserom.gba", 0x2840ce, 0x218

gUnknown_082842E6:: @ 082842E6
	.incbin "baserom.gba", 0x2842e6, 0xd4

gUnknown_082843BA:: @ 082843BA
	.incbin "baserom.gba", 0x2843ba, 0x143

gUnknown_082844FD:: @ 082844FD
	.incbin "baserom.gba", 0x2844fd, 0x5e

gUnknown_0828455B:: @ 0828455B
	.incbin "baserom.gba", 0x28455b, 0xe6

gUnknown_08284641:: @ 08284641
	.incbin "baserom.gba", 0x284641, 0x91

gUnknown_082846D2:: @ 082846D2
	.incbin "baserom.gba", 0x2846d2, 0x66

gUnknown_08284738:: @ 08284738
	.incbin "baserom.gba", 0x284738, 0x6d

gUnknown_082847A5:: @ 082847A5
	.incbin "baserom.gba", 0x2847a5, 0x52

gUnknown_082847F7:: @ 082847F7
	.incbin "baserom.gba", 0x2847f7, 0x68

gUnknown_0828485F:: @ 0828485F
	.incbin "baserom.gba", 0x28485f, 0x3b

gUnknown_0828489A:: @ 0828489A
	.incbin "baserom.gba", 0x28489a, 0x32

gUnknown_082848CC:: @ 082848CC
	.incbin "baserom.gba", 0x2848cc, 0x3f

gUnknown_0828490B:: @ 0828490B
	.incbin "baserom.gba", 0x28490b, 0x60

gUnknown_0828496B:: @ 0828496B
	.incbin "baserom.gba", 0x28496b, 0x43

gUnknown_082849AE:: @ 082849AE
	.incbin "baserom.gba", 0x2849ae, 0x90

gUnknown_08284A3E:: @ 08284A3E
	.incbin "baserom.gba", 0x284a3e, 0x217

gUnknown_08284C55:: @ 08284C55
	.incbin "baserom.gba", 0x284c55, 0x46

gUnknown_08284C9B:: @ 08284C9B
	.incbin "baserom.gba", 0x284c9b, 0x46

gUnknown_08284CE1:: @ 08284CE1
	.incbin "baserom.gba", 0x284ce1, 0xd5

gUnknown_08284DB6:: @ 08284DB6
	.incbin "baserom.gba", 0x284db6, 0x3f

gUnknown_08284DF5:: @ 08284DF5
	.incbin "baserom.gba", 0x284df5, 0x3f

gUnknown_08284E34:: @ 08284E34
	.incbin "baserom.gba", 0x284e34, 0xab

gUnknown_08284EDF:: @ 08284EDF
	.incbin "baserom.gba", 0x284edf, 0xc2

gUnknown_08284FA1:: @ 08284FA1
	.incbin "baserom.gba", 0x284fa1, 0x154

gUnknown_082850F5:: @ 082850F5
	.incbin "baserom.gba", 0x2850f5, 0x14b

gUnknown_08285240:: @ 08285240
	.incbin "baserom.gba", 0x285240, 0xb4

gUnknown_082852F4:: @ 082852F4
	.incbin "baserom.gba", 0x2852f4, 0x16f

gUnknown_08285463:: @ 08285463
	.incbin "baserom.gba", 0x285463, 0x9d

gUnknown_08285500:: @ 08285500
	.incbin "baserom.gba", 0x285500, 0xbf

gUnknown_082855BF:: @ 082855BF
	.incbin "baserom.gba", 0x2855bf, 0x12

gUnknown_082855D1:: @ 082855D1
	.incbin "baserom.gba", 0x2855d1, 0x6b

gUnknown_0828563C:: @ 0828563C
	.incbin "baserom.gba", 0x28563c, 0x46

gUnknown_08285682:: @ 08285682
	.incbin "baserom.gba", 0x285682, 0x83

gUnknown_08285705:: @ 08285705
	.incbin "baserom.gba", 0x285705, 0xab

gUnknown_082857B0:: @ 082857B0
	.incbin "baserom.gba", 0x2857b0, 0x74

gUnknown_08285824:: @ 08285824
	.incbin "baserom.gba", 0x285824, 0x46

gUnknown_0828586A:: @ 0828586A
	.incbin "baserom.gba", 0x28586a, 0x66

gUnknown_082858D0:: @ 082858D0
	.incbin "baserom.gba", 0x2858d0, 0x9f

gUnknown_0828596F:: @ 0828596F
	.incbin "baserom.gba", 0x28596f, 0x3d

gUnknown_082859AC:: @ 082859AC
	.incbin "baserom.gba", 0x2859ac, 0xa4

gUnknown_08285A50:: @ 08285A50
	.incbin "baserom.gba", 0x285a50, 0x63

gUnknown_08285AB3:: @ 08285AB3
	.incbin "baserom.gba", 0x285ab3, 0x74

gUnknown_08285B27:: @ 08285B27
	.incbin "baserom.gba", 0x285b27, 0xa3

gUnknown_08285BCA:: @ 08285BCA
	.incbin "baserom.gba", 0x285bca, 0x49

gUnknown_08285C13:: @ 08285C13
	.incbin "baserom.gba", 0x285c13, 0xec

gUnknown_08285CFF:: @ 08285CFF
	.incbin "baserom.gba", 0x285cff, 0x5e

gUnknown_08285D5D:: @ 08285D5D
	.incbin "baserom.gba", 0x285d5d, 0x83

gUnknown_08285DE0:: @ 08285DE0
	.incbin "baserom.gba", 0x285de0, 0x5b

gUnknown_08285E3B:: @ 08285E3B
	.incbin "baserom.gba", 0x285e3b, 0x62

gUnknown_08285E9D:: @ 08285E9D
	.incbin "baserom.gba", 0x285e9d, 0x61

gUnknown_08285EFE:: @ 08285EFE
	.incbin "baserom.gba", 0x285efe, 0x48

gUnknown_08285F46:: @ 08285F46
	.incbin "baserom.gba", 0x285f46, 0x103

gUnknown_08286049:: @ 08286049
	.incbin "baserom.gba", 0x286049, 0xf1

gUnknown_0828613A:: @ 0828613A
	.incbin "baserom.gba", 0x28613a, 0x10e

gUnknown_08286248:: @ 08286248
	.incbin "baserom.gba", 0x286248, 0xf8

gUnknown_08286340:: @ 08286340
	.incbin "baserom.gba", 0x286340, 0x8c

gUnknown_082863CC:: @ 082863CC
	.incbin "baserom.gba", 0x2863cc, 0x24a

gUnknown_08286616:: @ 08286616
	.incbin "baserom.gba", 0x286616, 0xa0

gUnknown_082866B6:: @ 082866B6
	.incbin "baserom.gba", 0x2866b6, 0x4a

gUnknown_08286700:: @ 08286700
	.incbin "baserom.gba", 0x286700, 0x3b

gUnknown_0828673B:: @ 0828673B
	.incbin "baserom.gba", 0x28673b, 0x1a

gUnknown_08286755:: @ 08286755
	.incbin "baserom.gba", 0x286755, 0x15

gUnknown_0828676A:: @ 0828676A
	.incbin "baserom.gba", 0x28676a, 0xd

gUnknown_08286777:: @ 08286777
	.incbin "baserom.gba", 0x286777, 0xef

gUnknown_08286866:: @ 08286866
	.incbin "baserom.gba", 0x286866, 0xf8

gUnknown_0828695E:: @ 0828695E
	.incbin "baserom.gba", 0x28695e, 0x2d

gUnknown_0828698B:: @ 0828698B
	.incbin "baserom.gba", 0x28698b, 0x25

gUnknown_082869B0:: @ 082869B0
	.incbin "baserom.gba", 0x2869b0, 0x3d

gUnknown_082869ED:: @ 082869ED
	.incbin "baserom.gba", 0x2869ed, 0x2a

gUnknown_08286A17:: @ 08286A17
	.incbin "baserom.gba", 0x286a17, 0x31

gUnknown_08286A48:: @ 08286A48
	.incbin "baserom.gba", 0x286a48, 0x34

gUnknown_08286A7C:: @ 08286A7C
	.incbin "baserom.gba", 0x286a7c, 0x32

gUnknown_08286AAE:: @ 08286AAE
	.incbin "baserom.gba", 0x286aae, 0x38

gUnknown_08286AE6:: @ 08286AE6
	.incbin "baserom.gba", 0x286ae6, 0x3d

gUnknown_08286B23:: @ 08286B23
	.incbin "baserom.gba", 0x286b23, 0x2c

gUnknown_08286B4F:: @ 08286B4F
	.incbin "baserom.gba", 0x286b4f, 0x240

gUnknown_08286D8F:: @ 08286D8F
	.incbin "baserom.gba", 0x286d8f, 0x10e

gUnknown_08286E9D:: @ 08286E9D
	.incbin "baserom.gba", 0x286e9d, 0x5f

gUnknown_08286EFC:: @ 08286EFC
	.incbin "baserom.gba", 0x286efc, 0x58

gUnknown_08286F54:: @ 08286F54
	.incbin "baserom.gba", 0x286f54, 0x56

gUnknown_08286FAA:: @ 08286FAA
	.incbin "baserom.gba", 0x286faa, 0x3a

gUnknown_08286FE4:: @ 08286FE4
	.incbin "baserom.gba", 0x286fe4, 0xbf

gUnknown_082870A3:: @ 082870A3
	.incbin "baserom.gba", 0x2870a3, 0xb7

gUnknown_0828715A:: @ 0828715A
	.incbin "baserom.gba", 0x28715a, 0xbb

gUnknown_08287215:: @ 08287215
	.incbin "baserom.gba", 0x287215, 0xb7

gUnknown_082872CC:: @ 082872CC
	.incbin "baserom.gba", 0x2872cc, 0xbb

gUnknown_08287387:: @ 08287387
	.incbin "baserom.gba", 0x287387, 0xbb

gUnknown_08287442:: @ 08287442
	.incbin "baserom.gba", 0x287442, 0xc6

gUnknown_08287508:: @ 08287508
	.incbin "baserom.gba", 0x287508, 0xd1

gUnknown_082875D9:: @ 082875D9
	.incbin "baserom.gba", 0x2875d9, 0xc8

gUnknown_082876A1:: @ 082876A1
	.incbin "baserom.gba", 0x2876a1, 0xd8

gUnknown_08287779:: @ 08287779
	.incbin "baserom.gba", 0x287779, 0x65

gUnknown_082877DE:: @ 082877DE
	.incbin "baserom.gba", 0x2877de, 0x5f

gUnknown_0828783D:: @ 0828783D
	.incbin "baserom.gba", 0x28783d, 0x76

gUnknown_082878B3:: @ 082878B3
	.incbin "baserom.gba", 0x2878b3, 0x76

gUnknown_08287929:: @ 08287929
	.incbin "baserom.gba", 0x287929, 0x75

gUnknown_0828799E:: @ 0828799E
	.incbin "baserom.gba", 0x28799e, 0x7a

gUnknown_08287A18:: @ 08287A18
	.incbin "baserom.gba", 0x287a18, 0x7f

gUnknown_08287A97:: @ 08287A97
	.incbin "baserom.gba", 0x287a97, 0x7f

gUnknown_08287B16:: @ 08287B16
	.incbin "baserom.gba", 0x287b16, 0x78

gUnknown_08287B8E:: @ 08287B8E
	.incbin "baserom.gba", 0x287b8e, 0x78

gUnknown_08287C06:: @ 08287C06
	.incbin "baserom.gba", 0x287c06, 0x77

gUnknown_08287C7D:: @ 08287C7D
	.incbin "baserom.gba", 0x287c7d, 0x76

gUnknown_08287CF3:: @ 08287CF3
	.incbin "baserom.gba", 0x287cf3, 0x77

gUnknown_08287D6A:: @ 08287D6A
	.incbin "baserom.gba", 0x287d6a, 0x77

gUnknown_08287DE1:: @ 08287DE1
	.incbin "baserom.gba", 0x287de1, 0x7a

gUnknown_08287E5B:: @ 08287E5B
	.incbin "baserom.gba", 0x287e5b, 0x60

gUnknown_08287EBB:: @ 08287EBB
	.incbin "baserom.gba", 0x287ebb, 0x59

gUnknown_08287F14:: @ 08287F14
	.incbin "baserom.gba", 0x287f14, 0x25

gUnknown_08287F39:: @ 08287F39
	.incbin "baserom.gba", 0x287f39, 0x3e

gUnknown_08287F77:: @ 08287F77
	.incbin "baserom.gba", 0x287f77, 0x69

gUnknown_08287FE0:: @ 08287FE0
	.incbin "baserom.gba", 0x287fe0, 0xe0

gUnknown_082880C0:: @ 082880C0
	.incbin "baserom.gba", 0x2880c0, 0x9f

gUnknown_0828815F:: @ 0828815F
	.incbin "baserom.gba", 0x28815f, 0xbb

gUnknown_0828821A:: @ 0828821A
	.incbin "baserom.gba", 0x28821a, 0xa4

gUnknown_082882BE:: @ 082882BE
	.incbin "baserom.gba", 0x2882be, 0x97

gUnknown_08288355:: @ 08288355
	.incbin "baserom.gba", 0x288355, 0xd6

gUnknown_0828842B:: @ 0828842B
	.incbin "baserom.gba", 0x28842b, 0x7a

gUnknown_082884A5:: @ 082884A5
	.incbin "baserom.gba", 0x2884a5, 0xe6

gUnknown_0828858B:: @ 0828858B
	.incbin "baserom.gba", 0x28858b, 0x7d

gUnknown_08288608:: @ 08288608
	.incbin "baserom.gba", 0x288608, 0xc0

gUnknown_082886C8:: @ 082886C8
	.incbin "baserom.gba", 0x2886c8, 0x16

gUnknown_082886DE:: @ 082886DE
	.incbin "baserom.gba", 0x2886de, 0x1a

gUnknown_082886F8:: @ 082886F8
	.incbin "baserom.gba", 0x2886f8, 0x41

gUnknown_08288739:: @ 08288739
	.incbin "baserom.gba", 0x288739, 0x3e

gUnknown_08288777:: @ 08288777
	.incbin "baserom.gba", 0x288777, 0x38

gUnknown_082887AF:: @ 082887AF
	.incbin "baserom.gba", 0x2887af, 0x3a

gUnknown_082887E9:: @ 082887E9
	.incbin "baserom.gba", 0x2887e9, 0x7f

gUnknown_08288868:: @ 08288868
	.incbin "baserom.gba", 0x288868, 0x62

gUnknown_082888CA:: @ 082888CA
	.incbin "baserom.gba", 0x2888ca, 0x66

gUnknown_08288930:: @ 08288930
	.incbin "baserom.gba", 0x288930, 0x90

gUnknown_082889C0:: @ 082889C0
	.incbin "baserom.gba", 0x2889c0, 0x7a

gUnknown_08288A3A:: @ 08288A3A
	.incbin "baserom.gba", 0x288a3a, 0x90

gUnknown_08288ACA:: @ 08288ACA
	.incbin "baserom.gba", 0x288aca, 0x54

gUnknown_08288B1E:: @ 08288B1E
	.incbin "baserom.gba", 0x288b1e, 0x5c

gUnknown_08288B7A:: @ 08288B7A
	.incbin "baserom.gba", 0x288b7a, 0x4f

gUnknown_08288BC9:: @ 08288BC9
	.incbin "baserom.gba", 0x288bc9, 0x77

gUnknown_08288C40:: @ 08288C40
	.incbin "baserom.gba", 0x288c40, 0x48

gUnknown_08288C88:: @ 08288C88
	.incbin "baserom.gba", 0x288c88, 0x40

gUnknown_08288CC8:: @ 08288CC8
	.incbin "baserom.gba", 0x288cc8, 0xb7

gUnknown_08288D7F:: @ 08288D7F
	.incbin "baserom.gba", 0x288d7f, 0x21

gUnknown_08288DA0:: @ 08288DA0
	.incbin "baserom.gba", 0x288da0, 0x3a

gUnknown_08288DDA:: @ 08288DDA
	.incbin "baserom.gba", 0x288dda, 0x44

gUnknown_08288E1E:: @ 08288E1E
	.incbin "baserom.gba", 0x288e1e, 0xab

gUnknown_08288EC9:: @ 08288EC9
	.incbin "baserom.gba", 0x288ec9, 0x8f

gUnknown_08288F58:: @ 08288F58
	.incbin "baserom.gba", 0x288f58, 0xb9

gUnknown_08289011:: @ 08289011
	.incbin "baserom.gba", 0x289011, 0x93

gUnknown_082890A4:: @ 082890A4
	.incbin "baserom.gba", 0x2890a4, 0x4c

gUnknown_082890F0:: @ 082890F0
	.incbin "baserom.gba", 0x2890f0, 0xa3

gUnknown_08289193:: @ 08289193
	.incbin "baserom.gba", 0x289193, 0x71

gUnknown_08289204:: @ 08289204
	.incbin "baserom.gba", 0x289204, 0x78

gUnknown_0828927C:: @ 0828927C
	.incbin "baserom.gba", 0x28927c, 0x97

gUnknown_08289313:: @ 08289313
	.incbin "baserom.gba", 0x289313, 0x62

gUnknown_08289375:: @ 08289375
	.incbin "baserom.gba", 0x289375, 0x8a

gUnknown_082893FF:: @ 082893FF
	.incbin "baserom.gba", 0x2893ff, 0x66

gUnknown_08289465:: @ 08289465
	.incbin "baserom.gba", 0x289465, 0x8d

gUnknown_082894F2:: @ 082894F2
	.incbin "baserom.gba", 0x2894f2, 0x72

gUnknown_08289564:: @ 08289564
	.incbin "baserom.gba", 0x289564, 0x87

gUnknown_082895EB:: @ 082895EB
	.incbin "baserom.gba", 0x2895eb, 0x5a

gUnknown_08289645:: @ 08289645
	.incbin "baserom.gba", 0x289645, 0x39

gUnknown_0828967E:: @ 0828967E
	.incbin "baserom.gba", 0x28967e, 0x7e

gUnknown_082896FC:: @ 082896FC
	.incbin "baserom.gba", 0x2896fc, 0x81

gUnknown_0828977D:: @ 0828977D
	.incbin "baserom.gba", 0x28977d, 0x96

gUnknown_08289813:: @ 08289813
	.incbin "baserom.gba", 0x289813, 0x11c

gUnknown_0828992F:: @ 0828992F
	.incbin "baserom.gba", 0x28992f, 0x6e

gUnknown_0828999D:: @ 0828999D
	.incbin "baserom.gba", 0x28999d, 0x3f

gUnknown_082899DC:: @ 082899DC
	.incbin "baserom.gba", 0x2899dc, 0x4d

gUnknown_08289A29:: @ 08289A29
	.incbin "baserom.gba", 0x289a29, 0x99

gUnknown_08289AC2:: @ 08289AC2
	.incbin "baserom.gba", 0x289ac2, 0x80

gUnknown_08289B42:: @ 08289B42
	.incbin "baserom.gba", 0x289b42, 0x83

gUnknown_08289BC5:: @ 08289BC5
	.incbin "baserom.gba", 0x289bc5, 0x76

gUnknown_08289C3B:: @ 08289C3B
	.incbin "baserom.gba", 0x289c3b, 0x5e

gUnknown_08289C99:: @ 08289C99
	.incbin "baserom.gba", 0x289c99, 0x9a

gUnknown_08289D33:: @ 08289D33
	.incbin "baserom.gba", 0x289d33, 0xa3

gUnknown_08289DD6:: @ 08289DD6
	.incbin "baserom.gba", 0x289dd6, 0x17d

gUnknown_08289F53:: @ 08289F53
	.incbin "baserom.gba", 0x289f53, 0x5d

gUnknown_08289FB0:: @ 08289FB0
	.incbin "baserom.gba", 0x289fb0, 0x97

gUnknown_0828A047:: @ 0828A047
	.incbin "baserom.gba", 0x28a047, 0x7f

gUnknown_0828A0C6:: @ 0828A0C6
	.incbin "baserom.gba", 0x28a0c6, 0x6c

gUnknown_0828A132:: @ 0828A132
	.incbin "baserom.gba", 0x28a132, 0x8c

gUnknown_0828A1BE:: @ 0828A1BE
	.incbin "baserom.gba", 0x28a1be, 0x44

gUnknown_0828A202:: @ 0828A202
	.incbin "baserom.gba", 0x28a202, 0x4c

gUnknown_0828A24E:: @ 0828A24E
	.incbin "baserom.gba", 0x28a24e, 0x3a

gUnknown_0828A288:: @ 0828A288
	.incbin "baserom.gba", 0x28a288, 0x13

gUnknown_0828A29B:: @ 0828A29B
	.incbin "baserom.gba", 0x28a29b, 0x18

gUnknown_0828A2B3:: @ 0828A2B3
	.incbin "baserom.gba", 0x28a2b3, 0x13

gUnknown_0828A2C6:: @ 0828A2C6
	.incbin "baserom.gba", 0x28a2c6, 0x14

gUnknown_0828A2DA:: @ 0828A2DA
	.incbin "baserom.gba", 0x28a2da, 0x14

gUnknown_0828A2EE:: @ 0828A2EE
	.incbin "baserom.gba", 0x28a2ee, 0x40

gUnknown_0828A32E:: @ 0828A32E
	.incbin "baserom.gba", 0x28a32e, 0x22

gUnknown_0828A350:: @ 0828A350
	.incbin "baserom.gba", 0x28a350, 0x1f

gUnknown_0828A36F:: @ 0828A36F
	.incbin "baserom.gba", 0x28a36f, 0x1e

gUnknown_0828A38D:: @ 0828A38D
	.incbin "baserom.gba", 0x28a38d, 0x29

gUnknown_0828A3B6:: @ 0828A3B6
	.incbin "baserom.gba", 0x28a3b6, 0x26

gUnknown_0828A3DC:: @ 0828A3DC
	.incbin "baserom.gba", 0x28a3dc, 0x79

gUnknown_0828A455:: @ 0828A455
	.incbin "baserom.gba", 0x28a455, 0x7a

gUnknown_0828A4CF:: @ 0828A4CF
	.incbin "baserom.gba", 0x28a4cf, 0x4d

gUnknown_0828A51C:: @ 0828A51C
	.incbin "baserom.gba", 0x28a51c, 0x90

gUnknown_0828A5AC:: @ 0828A5AC
	.incbin "baserom.gba", 0x28a5ac, 0x8c

gUnknown_0828A638:: @ 0828A638
	.incbin "baserom.gba", 0x28a638, 0x97

gUnknown_0828A6CF:: @ 0828A6CF
	.incbin "baserom.gba", 0x28a6cf, 0xc8

gUnknown_0828A797:: @ 0828A797
	.incbin "baserom.gba", 0x28a797, 0xd6

gUnknown_0828A86D:: @ 0828A86D
	.incbin "baserom.gba", 0x28a86d, 0xb3

gUnknown_0828A920:: @ 0828A920
	.incbin "baserom.gba", 0x28a920, 0xac

gUnknown_0828A9CC:: @ 0828A9CC
	.incbin "baserom.gba", 0x28a9cc, 0xa8

gUnknown_0828AA74:: @ 0828AA74
	.incbin "baserom.gba", 0x28aa74, 0x8d

gUnknown_0828AB01:: @ 0828AB01
	.incbin "baserom.gba", 0x28ab01, 0xcb

gUnknown_0828ABCC:: @ 0828ABCC
	.incbin "baserom.gba", 0x28abcc, 0x56

gUnknown_0828AC22:: @ 0828AC22
	.incbin "baserom.gba", 0x28ac22, 0x5c

gUnknown_0828AC7E:: @ 0828AC7E
	.incbin "baserom.gba", 0x28ac7e, 0x38

gUnknown_0828ACB6:: @ 0828ACB6
	.incbin "baserom.gba", 0x28acb6, 0x2d

gUnknown_0828ACE3:: @ 0828ACE3
	.incbin "baserom.gba", 0x28ace3, 0x9d

gUnknown_0828AD80:: @ 0828AD80
	.incbin "baserom.gba", 0x28ad80, 0x62

gUnknown_0828ADE2:: @ 0828ADE2
	.incbin "baserom.gba", 0x28ade2, 0x44

gUnknown_0828AE26:: @ 0828AE26
	.incbin "baserom.gba", 0x28ae26, 0xb06

gUnknown_0828B92C:: @ 0828B92C
	.incbin "baserom.gba", 0x28b92c, 0xf4

gUnknown_0828BA20:: @ 0828BA20
	.incbin "baserom.gba", 0x28ba20, 0xa8

gUnknown_0828BAC8:: @ 0828BAC8
	.incbin "baserom.gba", 0x28bac8, 0x150

gUnknown_0828BC18:: @ 0828BC18
	.incbin "baserom.gba", 0x28bc18, 0x108

gUnknown_0828BD20:: @ 0828BD20
	.incbin "baserom.gba", 0x28bd20, 0xe1

gUnknown_0828BE01:: @ 0828BE01
	.incbin "baserom.gba", 0x28be01, 0xed

gUnknown_0828BEEE:: @ 0828BEEE
	.incbin "baserom.gba", 0x28beee, 0x62

gUnknown_0828BF50:: @ 0828BF50
	.incbin "baserom.gba", 0x28bf50, 0xc1

gUnknown_0828C011:: @ 0828C011
	.incbin "baserom.gba", 0x28c011, 0x126

gUnknown_0828C137:: @ 0828C137
	.incbin "baserom.gba", 0x28c137, 0x155

gUnknown_0828C28C:: @ 0828C28C
	.incbin "baserom.gba", 0x28c28c, 0x1cf

gUnknown_0828C45B:: @ 0828C45B
	.incbin "baserom.gba", 0x28c45b, 0x207

gUnknown_0828C662:: @ 0828C662
	.incbin "baserom.gba", 0x28c662, 0xa96

gUnknown_0828D0F8:: @ 0828D0F8
	.incbin "baserom.gba", 0x28d0f8, 0x1a9

gUnknown_0828D2A1:: @ 0828D2A1
	.incbin "baserom.gba", 0x28d2a1, 0x154

gUnknown_0828D3F5:: @ 0828D3F5
	.incbin "baserom.gba", 0x28d3f5, 0x17c

gUnknown_0828D571:: @ 0828D571
	.incbin "baserom.gba", 0x28d571, 0xfe

gUnknown_0828D66F:: @ 0828D66F
	.incbin "baserom.gba", 0x28d66f, 0xf9

gUnknown_0828D768:: @ 0828D768
	.incbin "baserom.gba", 0x28d768, 0x10d

gUnknown_0828D875:: @ 0828D875
	.incbin "baserom.gba", 0x28d875, 0x11f

gUnknown_0828D994:: @ 0828D994
	.incbin "baserom.gba", 0x28d994, 0x12c

gUnknown_0828DAC0:: @ 0828DAC0
	.incbin "baserom.gba", 0x28dac0, 0x12c

gUnknown_0828DBEC:: @ 0828DBEC
	.incbin "baserom.gba", 0x28dbec, 0x1b2

gUnknown_0828DD9E:: @ 0828DD9E
	.incbin "baserom.gba", 0x28dd9e, 0x167

gUnknown_0828DF05:: @ 0828DF05
	.incbin "baserom.gba", 0x28df05, 0x2800

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
