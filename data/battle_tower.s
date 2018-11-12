#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 85CECB0
	.include "data/battle_frontier/battle_frontier_held_items.inc"

@ 85CED2E
	.include "data/battle_frontier/battle_frontier_trainer_mons.inc"

@ 85D5ACC
	.include "data/battle_frontier/battle_frontier_trainers.inc"

@ 85D97BC
	.include "data/battle_frontier/battle_frontier_mons.inc"

gTowerMaleFacilityClasses:: @ 85DCEDC
	.byte 0x0e, 0x11, 0x03, 0x15, 0x17, 0x07, 0x0a, 0x19, 0x1a, 0x1b, 0x1d, 0x1e, 0x20, 0x26, 0x29, 0x09, 0x2b, 0x2d, 0x2e, 0x30, 0x32, 0x34, 0x04, 0x35, 0x3a, 0x05, 0x42, 0x44, 0x43, 0x00

gTowerFemaleFacilityClasses:: @ 85DCEFA
	.byte 0x0d, 0x10, 0x12, 0x0c, 0x13, 0x14, 0x1f, 0x27, 0x2a, 0x16, 0x2f, 0x31, 0x33, 0x36, 0x37, 0x38, 0x1c, 0x02, 0x45, 0x47

gTowerMaleTrainerGfxIds:: @ 85DCF0E
	.byte 0x37, 0x36, 0x21, 0x0f, 0x27, 0x33, 0x2c, 0x42, 0x42, 0x1f, 0x27, 0x25, 0x30, 0x26, 0x19, 0x15, 0x23, 0x32, 0x38, 0x33, 0x33, 0x21, 0x42, 0x05, 0x31, 0x27, 0x41, 0x1f, 0x24, 0x37

gTowerFemaleTrainerGfxIds:: @ 85DCF2C
	.byte 0x14, 0x35, 0x22, 0x28, 0x14, 0x2d, 0x2f, 0x0e, 0x12, 0x16, 0x39, 0x34, 0x34, 0x0e, 0x22, 0x34, 0x20, 0x14, 0x20, 0x2f

sRubyFacilityClassToEmerald:: @ 85DCF40
	.byte 0x00, 0x0b, 0x01, 0x01, 0x02, 0x06, 0x03, 0x0d, 0x04, 0x0e, 0x05, 0x0f, 0x06, 0x10, 0x07, 0x11, 0x08, 0x03, 0x09, 0x12, 0x0a, 0x0c, 0x0b, 0x13, 0x0c, 0x14, 0x0d, 0x15, 0x0e, 0x17, 0x0f, 0x07
	.byte 0x10, 0x0a, 0x11, 0x19, 0x12, 0x1a, 0x13, 0x1b, 0x14, 0x1d, 0x15, 0x1e, 0x16, 0x1f, 0x17, 0x20, 0x18, 0x21, 0x19, 0x22, 0x1a, 0x23, 0x1b, 0x24, 0x1c, 0x25, 0x1d, 0x26, 0x1e, 0x27, 0x1f, 0x28
	.byte 0x20, 0x29, 0x21, 0x2a, 0x22, 0x09, 0x23, 0x16, 0x24, 0x2b, 0x25, 0x2c, 0x26, 0x2d, 0x27, 0x2e, 0x28, 0x2f, 0x29, 0x30, 0x2a, 0x31, 0x2b, 0x32, 0x2c, 0x33, 0x2d, 0x34, 0x2e, 0x04, 0x2f, 0x35
	.byte 0x30, 0x36, 0x31, 0x37, 0x32, 0x38, 0x33, 0x1c, 0x34, 0x39, 0x35, 0x3a, 0x38, 0x05, 0x39, 0x3b, 0x3a, 0x3c, 0x3b, 0x3d, 0x3c, 0x3e, 0x3d, 0x3f, 0x3e, 0x40, 0x3f, 0x41, 0x40, 0x42, 0x41, 0x02
	.byte 0x42, 0x44, 0x43, 0x45, 0x44, 0x46, 0x45, 0x08, 0x46, 0x18, 0x47, 0x47, 0x48, 0x43, 0x49, 0x00, 0x4a, 0x48, 0x4b, 0x49, 0x4c, 0x4a, 0x00, 0x00

	.align 2
gUnknown_085DCFD8:: @ 85DCFD8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244383
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2443E7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244413
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24444B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2444D6

	.align 2
gUnknown_085DCFEC:: @ 85DCFEC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2444EF
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24451E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244549
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24459B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2445C5

	.align 2
gUnknown_085DD000:: @ 85DD000
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2445E8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244618
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244643
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24468F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2446B4

	.align 2
gUnknown_085DD014:: @ 85DD014
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2446E5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24474D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24479E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24480C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2448A7

	.align 2
gUnknown_085DD028:: @ 85DD028
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2448CD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2448F5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244939
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244989
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2449E6

	.align 2
gUnknown_085DD03C:: @ 85DD03C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244A23
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244AA9
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244AD6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244B52
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244B93

	.align 2
gUnknown_085DD050:: @ 85DD050
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244BD2
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244C18
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244C6E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244CD6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244D07

	.align 2
gUnknown_085DD064:: @ 85DD064
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244D36
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244D82
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244DC6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244DFE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244E5B

	.align 2
gUnknown_085DD078:: @ 85DD078
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244E7E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244ECA
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244EF4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244F4F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244F98

	.align 2
gUnknown_085DD08C:: @ 85DD08C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_244FD3
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245013
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24503D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245087
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2450C0

	.align 2
gUnknown_085DD0A0:: @ 85DD0A0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2450E6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245196
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2451BD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24522F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24529A

	.align 2
gUnknown_085DD0B4:: @ 85DD0B4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2452EF
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2453B4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245406
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245464
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2454A3

	.align 2
gUnknown_085DD0C8:: @ 85DD0C8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2454D6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245535
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24555F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2455EC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245656

	.align 2
gUnknown_085DD0DC:: @ 85DD0DC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24568A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2456F5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245740
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2457D9
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24581F

	.align 2
gUnknown_085DD0F0:: @ 85DD0F0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245851
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24589C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2458CE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245923
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24597F

	.align 2
gUnknown_085DD104:: @ 85DD104
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2459BE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2459F7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245A5F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245AB4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245B3E

	.align 2
gUnknown_085DD118:: @ 85DD118
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245B79
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245B91
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245BBD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245C05
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245C2D

	.align 2
gUnknown_085DD12C:: @ 85DD12C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245C66
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245C7F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245CAC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245CE6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245D07

	.align 2
gUnknown_085DD140:: @ 85DD140
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245D4B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245D60
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245D8D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245DC7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245DF0

	.align 2
gUnknown_085DD154:: @ 85DD154
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245E20
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245E41
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245E78
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245EBD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245EEC

	.align 2
gUnknown_085DD168:: @ 85DD168
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245F2B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245F58
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245F87
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_245FC6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246002

	.align 2
gUnknown_085DD17C:: @ 85DD17C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246020
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246051
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246082
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2460D5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24610D

	.align 2
gUnknown_085DD190:: @ 85DD190
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24614A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24615D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24617D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2461C7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2461F5

	.align 2
gUnknown_085DD1A4:: @ 85DD1A4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24622A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246244
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24626E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2462AA
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2462E4

	.align 2
gUnknown_085DD1B8:: @ 85DD1B8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24631F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24633C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24636B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2463C5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2463FF

	.align 2
gUnknown_085DD1CC:: @ 85DD1CC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246449
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246478
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24649D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2464EE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246529

	.align 2
gUnknown_085DD1E0:: @ 85DD1E0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246571
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24658C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2465B5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246605
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24662A

	.align 2
gUnknown_085DD1F4:: @ 85DD1F4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246662
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246686
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2466B4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2466E6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24670A

	.align 2
gUnknown_085DD208:: @ 85DD208
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246741
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246760
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246791
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2467C4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2467E6

	.align 2
gUnknown_085DD21C:: @ 85DD21C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2467FF
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246831
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246864
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2468A7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2468FE

	.align 2
gUnknown_085DD230:: @ 85DD230
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24692B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24694B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24697C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2469B4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2469F1

	.align 2
gUnknown_085DD244:: @ 85DD244
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246A22
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246A4E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246A85
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246ACF
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246AF7

	.align 2
gUnknown_085DD258:: @ 85DD258
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246B2B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246B3F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246B6B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246BB2
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246BE9

	.align 2
gUnknown_085DD26C:: @ 85DD26C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246C22
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246C35
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246C6C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246CB3
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246CE9

	.align 2
gUnknown_085DD280:: @ 85DD280
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246D2D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246D3F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246D6A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246D9E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246DD3

	.align 2
gUnknown_085DD294:: @ 85DD294
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246E1A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246E39
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246E64
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246EB6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246EEE

	.align 2
gUnknown_085DD2A8:: @ 85DD2A8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246F21
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246F4C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246F7B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_246FCC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247013

	.align 2
gUnknown_085DD2BC:: @ 85DD2BC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24705B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24707D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2470B2
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2470FD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24712A

	.align 2
gUnknown_085DD2D0:: @ 85DD2D0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24716C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24718D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2471C7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2471FB
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247238

	.align 2
gUnknown_085DD2E4:: @ 85DD2E4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247268
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247291
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2472C7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247313
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247348

	.align 2
gUnknown_085DD2F8:: @ 85DD2F8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24737A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24738F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2473C6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2473FB
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247438

	.align 2
gUnknown_085DD30C:: @ 85DD30C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247470
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247484
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2474AF
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2474EC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24751D

	.align 2
gUnknown_085DD320:: @ 85DD32
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24754A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24755C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24758B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2475BC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2475D5

	.align 2
gUnknown_085DD334:: @ 85DD334
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24760D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247629
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247655
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24769B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2476ED

	.align 2
gUnknown_085DD348:: @ 85DD348
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247724
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247749
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24777A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2477CE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247807

	.align 2
gUnknown_085DD35C:: @ 85DD35C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247838
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247854
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247889
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2478DD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24790D

	.align 2
gUnknown_085DD370:: @ 85DD370
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247942
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24795F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247991
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2479CE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247A18

	.align 2
gUnknown_085DD384:: @ 85DD384
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247A51
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247A76
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247AA1
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247AE3
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247B16

	.align 2
gUnknown_085DD398:: @ 85DD398
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247B3E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247B62
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247B9B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247BE7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247C23

	.align 2
gUnknown_085DD3AC:: @ 85DD3AC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247C4E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247C8C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247CB2
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247D07
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247D4E

	.align 2
gUnknown_085DD3C0:: @ 85DD3C0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247D97
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247DC7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247DFE
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247E3E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247E7E

	.align 2
gUnknown_085DD3D4:: @ 85DD3D4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247EA1
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247EB5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247EE9
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247F3F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247F6D

	.align 2
gUnknown_085DD3E8:: @ 85DD3E8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247FA3
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247FB7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_247FE9
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248031
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24805E

	.align 2
gUnknown_085DD3FC:: @ 85DD3FC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24808D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2480AB
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2480DC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248128
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248151

	.align 2
gUnknown_085DD410:: @ 85DD410
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24818E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2481A9
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2481E1
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248221
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24824F

	.align 2
gUnknown_085DD424:: @ 85DD424
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248297
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2482B1
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2482DC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248321
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24833D

	.align 2
gUnknown_085DD438:: @ 85DD438
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248369
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24838D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2483C1
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248401
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248431

	.align 2
gUnknown_085DD44C:: @ 85DD44C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248467
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248477
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2484AC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2484E7
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248517

	.align 2
gUnknown_085DD460:: @ 85DD460
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248553
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24856A
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24857D
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2485E5
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248614

	.align 2
gUnknown_085DD474:: @ 85DD474
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24864E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248661
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248671
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2486C6
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2486FF

	.align 2
gUnknown_085DD488:: @ 85DD488
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248725
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248751
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248781
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2487C9
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2487F7

	.align 2
gUnknown_085DD49C:: @ 85DD49C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248829
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24885B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248892
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2488D8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248908

	.align 2
gUnknown_085DD4B0:: @ 85DD4B0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24894B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24895F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_24896F
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2489BD
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_2489E7

	.align 2
gUnknown_085DD4C4:: @ 85DD4C4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248A10
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248A40
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248A72
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248AC0
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248AEB

	.align 2
gUnknown_085DD4D8:: @ 85DD4D8
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248B22
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248B39
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248B4C
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248BB4
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248BEE

	.align 2
gUnknown_085DD4EC:: @ 85DD4EC
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248C2E
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248C5B
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248C90
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248CCF
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_Text_248D04

	.align 2
gUnknown_085DD500:: @ 85DD500
	.4byte 0x00000047, gUnknown_085DD118
	.4byte 0x0000002b, gUnknown_085DD12C
	.4byte 0x00000000, gUnknown_085DD140
	.4byte 0x00000014, gUnknown_085DD154
	.4byte 0x0000002d, gUnknown_085DD168
	.4byte 0x00000013, gUnknown_085DD17C
	.4byte 0x0000002f, gUnknown_085DD190
	.4byte 0x00000043, gUnknown_085DD1A4
	.4byte 0x00000026, gUnknown_085DD1B8
	.4byte 0x00000015, gUnknown_085DD1CC
	.4byte 0x0000000a, gUnknown_085DD1E0
	.4byte 0x00000010, gUnknown_085DD1F4
	.4byte 0x0000000c, gUnknown_085DD208
	.4byte 0x00000042, gUnknown_085DD21C
	.4byte 0x00000031, gUnknown_085DD230
	.4byte 0x00000030, gUnknown_085DD244
	.4byte 0x00000036, gUnknown_085DD258
	.4byte 0x0000002e, gUnknown_085DD26C
	.4byte 0x00000011, gUnknown_085DD280
	.4byte 0x00000019, gUnknown_085DD294
	.4byte 0x00000020, gUnknown_085DD2A8
	.4byte 0x00000029, gUnknown_085DD2BC
	.4byte 0x00000009, gUnknown_085DD2D0
	.4byte 0x00000016, gUnknown_085DD2E4
	.4byte 0x00000034, gUnknown_085DD2F8
	.4byte 0x00000004, gUnknown_085DD30C
	.4byte 0x00000035, gUnknown_085DD320
	.4byte 0x00000037, gUnknown_085DD334
	.4byte 0x0000001d, gUnknown_085DD348
	.4byte 0x0000003a, gUnknown_085DD35C
	.4byte 0x00000005, gUnknown_085DD370
	.4byte 0x00000044, gUnknown_085DD384
	.4byte 0x00000045, gUnknown_085DD398
	.4byte 0x0000000d, gUnknown_085DD3AC
	.4byte 0x0000000e, gUnknown_085DD3C0
	.4byte 0x00000003, gUnknown_085DD3D4
	.4byte 0x00000012, gUnknown_085DD3E8
	.4byte 0x00000017, gUnknown_085DD3FC
	.4byte 0x0000001a, gUnknown_085DD410
	.4byte 0x0000001b, gUnknown_085DD424
	.4byte 0x0000001c, gUnknown_085DD438
	.4byte 0x0000001e, gUnknown_085DD44C
	.4byte 0x0000001f, gUnknown_085DD460
	.4byte 0x00000027, gUnknown_085DD474
	.4byte 0x00000002, gUnknown_085DD488
	.4byte 0x0000002a, gUnknown_085DD49C
	.4byte 0x00000038, gUnknown_085DD4B0
	.4byte 0x00000032, gUnknown_085DD4C4
	.4byte 0x00000033, gUnknown_085DD4D8
	.4byte 0x00000007, gUnknown_085DD4EC

	.align 2
gUnknown_085DD690:: @ 85DD690
	.4byte gUnknown_085DCFD8
	.4byte gUnknown_085DCFEC
	.4byte gUnknown_085DD000
	.4byte gUnknown_085DD014
	.4byte gUnknown_085DD028
	.4byte gUnknown_085DD03C
	.4byte gUnknown_085DD050
	.4byte gUnknown_085DD064
	.4byte gUnknown_085DD078
	.4byte gUnknown_085DD08C
	.4byte gUnknown_085DD0A0
	.4byte gUnknown_085DD0B4
	.4byte gUnknown_085DD0C8
	.4byte gUnknown_085DD0DC
	.4byte gUnknown_085DD0F0
	.4byte gUnknown_085DD104

sStevenMons:: @ 85DD6D0
	.byte 0x8f, 0x01, 0x1f, 0x2a, 0x02

gUnknown_085DD6D5:: @ 85DD6D5
	.byte 0x00, 0xfc, 0xfc, 0x00, 0x06, 0x00, 0x00

	.align 1
gUnknown_085DD6DC:: @ 85DD6DC
	.2byte 0x0071, 0x005e, 0x0073, 0x00e8, 0x00e3, 0x2b1f, 0xfc08, 0x0000, 0x0600, 0x00fc, 0x005c, 0x014c, 0x00b6, 0x00d3, 0x0180, 0x2c1f
	.2byte 0x0003, 0x00fc, 0xfc00, 0x0006, 0x0057, 0x00b6, 0x004c, 0x0151

@ 85DD70C
	.include "data/battle_frontier/slateport_battle_tent_trainer_mons.inc"

@ 85DDA14
	.include "data/battle_frontier/slateport_battle_tent_trainers.inc"

@ 85DE02C
	.include "data/battle_frontier/slateport_battle_tent_mons.inc"

@ 85DE48C
	.include "data/battle_frontier/verdanturf_battle_tent_trainer_mons.inc"

@ 85DE610
	.include "data/battle_frontier/verdanturf_battle_tent_trainers.inc"

@ 85DEC28
	.include "data/battle_frontier/verdanturf_battle_tent_mons.inc"

@ 85DEEF8
	.include "data/battle_frontier/fallarbor_battle_tent_trainer_mons.inc"

@ 85DF084
	.include "data/battle_frontier/fallarbor_battle_tent_trainers.inc"

@ 85DF69C
	.include "data/battle_frontier/fallarbor_battle_tent_mons.inc"
