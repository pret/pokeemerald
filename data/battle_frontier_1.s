#include "constants/flags.h"

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2, 0
gUnknown_0860B358:: @ 860B358
	.incbin "baserom.gba", 0x60b358, 0x1630

gUnknown_0860C988:: @ 860C988
	.incbin "baserom.gba", 0x60c988, 0x269

gUnknown_0860CBF1:: @ 860CBF1
	.byte 0x07, 0x01, 0x08, 0x10, 0x07, 0x01, 0x08, 0x10, 0x07, 0x01, 0x08, 0x10, 0x07, 0x01, 0x08, 0x10, 0x07, 0x01, 0x08, 0x10, 0x00, 0x02, 0x09, 0x10, 0x00, 0x02, 0x09, 0x10, 0x00, 0x02, 0x09, 0x10
	.byte 0x00, 0x02, 0x09, 0x10, 0x00, 0x02, 0x09, 0x10, 0x01, 0x03, 0x0a, 0x11, 0x01, 0x03, 0x0a, 0x11, 0x01, 0x03, 0x0a, 0x11, 0x01, 0x03, 0x0a, 0x11, 0x01, 0x03, 0x0a, 0x11, 0x02, 0x04, 0x0b, 0x11
	.byte 0x02, 0x04, 0x0b, 0x11, 0x02, 0x04, 0x0b, 0x11, 0x02, 0x04, 0x0b, 0x11, 0x02, 0x04, 0x0b, 0x11, 0x03, 0x05, 0x0c, 0x12, 0x03, 0x05, 0x0c, 0x12, 0x03, 0x05, 0x0c, 0x12, 0x03, 0x05, 0x0c, 0x12
	.byte 0x03, 0x05, 0x0c, 0x12, 0x04, 0x06, 0x0d, 0x12, 0x04, 0x06, 0x0d, 0x12, 0x04, 0x06, 0x0d, 0x12, 0x04, 0x06, 0x0d, 0x12, 0x04, 0x06, 0x0d, 0x12, 0x05, 0x07, 0x0e, 0x13, 0x05, 0x07, 0x0e, 0x13
	.byte 0x05, 0x07, 0x0e, 0x13, 0x05, 0x07, 0x0e, 0x13, 0x05, 0x07, 0x0e, 0x13, 0x06, 0x00, 0x0f, 0x13, 0x06, 0x00, 0x0f, 0x13, 0x06, 0x00, 0x0f, 0x13, 0x06, 0x00, 0x0f, 0x13, 0x06, 0x00, 0x0f, 0x13
	.byte 0x1f, 0x09, 0x14, 0x1f, 0x1f, 0x09, 0x14, 0x1f, 0x1f, 0x09, 0x14, 0x1f, 0x1f, 0x09, 0x14, 0x1f, 0x1f, 0x09, 0x14, 0x1f, 0x08, 0x0a, 0x14, 0x01, 0x08, 0x0a, 0x14, 0x01, 0x08, 0x0a, 0x14, 0x01
	.byte 0x08, 0x0a, 0x14, 0x01, 0x08, 0x0a, 0x14, 0x01, 0x09, 0x0b, 0x15, 0x02, 0x09, 0x0b, 0x15, 0x02, 0x09, 0x0b, 0x15, 0x02, 0x09, 0x0b, 0x15, 0x02, 0x09, 0x0b, 0x15, 0x02, 0x0a, 0x0c, 0x15, 0x03
	.byte 0x0a, 0x0c, 0x15, 0x03, 0x0a, 0x0c, 0x15, 0x03, 0x0a, 0x0c, 0x15, 0x03, 0x0a, 0x0c, 0x15, 0x03, 0x0b, 0x0d, 0x16, 0x04, 0x0b, 0x0d, 0x16, 0x04, 0x0b, 0x0d, 0x16, 0x04, 0x0b, 0x0d, 0x16, 0x04
	.byte 0x0b, 0x0d, 0x16, 0x04, 0x0c, 0x0e, 0x16, 0x05, 0x0c, 0x0e, 0x16, 0x05, 0x0c, 0x0e, 0x16, 0x05, 0x0c, 0x0e, 0x16, 0x05, 0x0c, 0x0e, 0x16, 0x05, 0x0d, 0x0f, 0x17, 0x06, 0x0d, 0x0f, 0x17, 0x06
	.byte 0x0d, 0x0f, 0x17, 0x06, 0x0d, 0x0f, 0x17, 0x06, 0x0d, 0x0f, 0x17, 0x06, 0x0e, 0x1f, 0x17, 0x07, 0x0e, 0x1f, 0x17, 0x07, 0x0e, 0x1f, 0x17, 0x07, 0x0e, 0x1f, 0x17, 0x07, 0x0e, 0x1f, 0x17, 0x07
	.byte 0x13, 0x11, 0x00, 0x14, 0x13, 0x11, 0x00, 0x18, 0x13, 0x11, 0x00, 0x18, 0x13, 0x11, 0x00, 0x18, 0x13, 0x11, 0x00, 0x18, 0x10, 0x12, 0x02, 0x15, 0x10, 0x12, 0x02, 0x18, 0x10, 0x12, 0x02, 0x18
	.byte 0x10, 0x12, 0x02, 0x18, 0x10, 0x12, 0x02, 0x18, 0x11, 0x13, 0x04, 0x16, 0x11, 0x13, 0x04, 0x19, 0x11, 0x13, 0x04, 0x19, 0x11, 0x13, 0x04, 0x19, 0x11, 0x13, 0x04, 0x19, 0x12, 0x10, 0x06, 0x17
	.byte 0x12, 0x10, 0x06, 0x19, 0x12, 0x10, 0x06, 0x19, 0x12, 0x10, 0x06, 0x19, 0x12, 0x10, 0x06, 0x19, 0x17, 0x15, 0x10, 0x08, 0x17, 0x15, 0x1a, 0x08, 0x17, 0x15, 0x1a, 0x08, 0x17, 0x15, 0x1a, 0x08
	.byte 0x17, 0x15, 0x1a, 0x08, 0x14, 0x16, 0x11, 0x0a, 0x14, 0x16, 0x1a, 0x0a, 0x14, 0x16, 0x1a, 0x0a, 0x14, 0x16, 0x1a, 0x0a, 0x14, 0x16, 0x1a, 0x0a, 0x15, 0x17, 0x12, 0x0c, 0x15, 0x17, 0x1b, 0x0c
	.byte 0x15, 0x17, 0x1b, 0x0c, 0x15, 0x17, 0x1b, 0x0c, 0x15, 0x17, 0x1b, 0x0c, 0x16, 0x14, 0x13, 0x0e, 0x16, 0x14, 0x1b, 0x0e, 0x16, 0x14, 0x1b, 0x0e, 0x16, 0x14, 0x1b, 0x0e, 0x16, 0x14, 0x1b, 0x0e
	.byte 0xff, 0xff, 0xff, 0xff, 0x19, 0x19, 0x10, 0x1a, 0x19, 0x19, 0x10, 0x1c, 0x19, 0x19, 0x10, 0x1c, 0x19, 0x19, 0x10, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x18, 0x18, 0x12, 0x1b, 0x18, 0x18, 0x12, 0x1c
	.byte 0x18, 0x18, 0x12, 0x1c, 0x18, 0x18, 0x12, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x1b, 0x1b, 0x18, 0x14, 0x1b, 0x1b, 0x1d, 0x14, 0x1b, 0x1b, 0x1d, 0x14, 0x1b, 0x1b, 0x1d, 0x14, 0xff, 0xff, 0xff, 0xff
	.byte 0x1a, 0x1a, 0x19, 0x16, 0x1a, 0x1a, 0x1d, 0x16, 0x1a, 0x1a, 0x1d, 0x16, 0x1a, 0x1a, 0x1d, 0x16, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x1d, 0xff, 0xff, 0x18, 0x1e
	.byte 0xff, 0xff, 0x18, 0x1e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x1a, 0xff, 0xff, 0x1e, 0x1a, 0xff, 0xff, 0x1e, 0x1a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
	.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x1d, 0xff, 0xff, 0x1c, 0x1d, 0x0f, 0x08, 0x08, 0x00, 0x0f, 0x08, 0x08, 0x00, 0x0f, 0x08, 0x08, 0x00, 0x0f, 0x08, 0x08, 0x00, 0x0f, 0x08, 0x08, 0x00
	.byte 0x00, 0x00, 0x00

gUnknown_0860CE74:: @ 860CE74
	.incbin "baserom.gba", 0x60ce74, 0x10

gUnknown_0860CE84:: @ 860CE84
	.incbin "baserom.gba", 0x60ce84, 0x10

gUnknown_0860CE94:: @ 860CE94
	window_template 0x00, 0x00, 0x03, 0x08, 0x10, 0x0f, 0x0010
	window_template 0x00, 0x16, 0x03, 0x08, 0x10, 0x0f, 0x0090
	window_template 0x00, 0x08, 0x01, 0x0e, 0x02, 0x0f, 0x0110
	window_template_terminator

gUnknown_0860CEB4:: @ 860CEB4
	window_template 0x00, 0x02, 0x02, 0x1a, 0x02, 0x0f, 0x0001
	window_template 0x00, 0x10, 0x05, 0x08, 0x02, 0x0f, 0x0035
	window_template 0x00, 0x13, 0x07, 0x09, 0x03, 0x0f, 0x0045
	window_template 0x00, 0x10, 0x0a, 0x08, 0x02, 0x0f, 0x0060
	window_template 0x00, 0x02, 0x0c, 0x1a, 0x07, 0x0f, 0x0070
	window_template 0x00, 0x05, 0x02, 0x17, 0x02, 0x0f, 0x0126
	window_template 0x00, 0x02, 0x05, 0x08, 0x02, 0x0f, 0x0154
	window_template 0x00, 0x14, 0x05, 0x08, 0x02, 0x0f, 0x0164
	window_template 0x00, 0x02, 0x10, 0x1a, 0x02, 0x0f, 0x0174
	window_template 0x01, 0x02, 0x02, 0x1a, 0x02, 0x0f, 0x0001
	window_template 0x01, 0x10, 0x05, 0x08, 0x02, 0x0f, 0x0035
	window_template 0x01, 0x13, 0x07, 0x09, 0x03, 0x0f, 0x0045
	window_template 0x01, 0x10, 0x0a, 0x08, 0x02, 0x0f, 0x0060
	window_template 0x01, 0x02, 0x0c, 0x1a, 0x07, 0x0f, 0x0070
	window_template 0x01, 0x05, 0x02, 0x17, 0x02, 0x0f, 0x0126
	window_template 0x01, 0x02, 0x05, 0x08, 0x02, 0x0f, 0x0154
	window_template 0x01, 0x14, 0x05, 0x08, 0x02, 0x0f, 0x0164
	window_template 0x01, 0x02, 0x10, 0x1a, 0x02, 0x0f, 0x0174

gUnknown_0860CF44:: @ 860CF44
	.incbin "baserom.gba", 0x60cf44, 0xc

gUnknown_0860CF50:: @ 860CF50
	.incbin "baserom.gba", 0x60cf50, 0x58

gUnknown_0860CFA8:: @ 860CFA8
	.incbin "baserom.gba", 0x60cfa8, 0x30

gUnknown_0860CFD8:: @ 860CFD8
	.incbin "baserom.gba", 0x60cfd8, 0x30

gUnknown_0860D008:: @ 860D008
	.incbin "baserom.gba", 0x60d008, 0x48

gUnknown_0860D050:: @ 860D050
	.incbin "baserom.gba", 0x60d050, 0x18

gUnknown_0860D068:: @ 860D068
	.incbin "baserom.gba", 0x60d068, 0x18

gUnknown_0860D080:: @ 860D080
	.byte 0x00, 0x08, 0x0c, 0x04, 0x07, 0x0f, 0x0b, 0x03, 0x02, 0x0a, 0x0e, 0x06, 0x05, 0x0d, 0x09, 0x01

gUnknown_0860D090:: @ 860D090
	.4byte sub_818E9CC
	.4byte sub_818EA84
	.4byte sub_818ED28
	.4byte sub_818F9B0
	.4byte sub_818F9E0
	.4byte sub_818FA20
	.4byte sub_81903B8
	.4byte sub_81938A4
	.4byte sub_81938E0
	.4byte sub_8190298
	.4byte sub_81902E4
	.4byte sub_8193D40
	.4byte sub_8193D7C
	.4byte sub_81902F8
	.4byte sub_819033C
	.4byte sub_8194D48
	.4byte sub_8194D68
	.4byte sub_8194E44
	.4byte sub_8194EB4
	.4byte sub_8194EC0
	.4byte sub_8194EF8
	.4byte sub_8194F58
	.4byte sub_818F02C

gUnknown_0860D0EC:: @ 860D0EC
	.4byte 0x00000004, 0x00000008, 0x00100000, 0x00200000

gUnknown_0860D0FC:: @ 860D0FC
	.4byte 0xfffffffb, 0xfffffff7, 0xffefffff, 0xffdfffff

gUnknown_0860D10C:: @ 860D10C
	.byte 0x08, 0x00, 0x04, 0x08, 0x09, 0x0c, 0x08, 0x00, 0x0a, 0x08, 0x0c, 0x00, 0x0b, 0x04, 0x00, 0x08, 0x0c, 0x00, 0x04, 0x08, 0x0d, 0x0c, 0x08, 0x00, 0x0e, 0x08, 0x0c, 0x00, 0x0f, 0x04, 0x00, 0x08
	.byte 0x00, 0x00, 0x04, 0x08, 0x01, 0x0c, 0x08, 0x00, 0x02, 0x08, 0x0c, 0x00, 0x03, 0x04, 0x00, 0x08, 0x04, 0x00, 0x04, 0x08, 0x05, 0x0c, 0x08, 0x00, 0x06, 0x08, 0x0c, 0x00, 0x07, 0x04, 0x00, 0x08

gUnknown_0860D14C:: @ 860D14C
	.byte 0x00, 0x08, 0x04, 0x0c, 0x07, 0x0f, 0x03, 0x0b, 0x02, 0x0a, 0x06, 0x0e, 0x05, 0x0d, 0x01, 0x09

gUnknown_0860D15C:: @ 860D15C
	.byte 0x00, 0x08, 0x0c, 0x0e, 0x00, 0x08, 0x0c, 0x0e, 0x01, 0x08, 0x0c, 0x0e, 0x01, 0x08, 0x0c, 0x0e, 0x02, 0x09, 0x0c, 0x0e, 0x02, 0x09, 0x0c, 0x0e, 0x03, 0x09, 0x0c, 0x0e, 0x03, 0x09, 0x0c, 0x0e
	.byte 0x04, 0x0a, 0x0d, 0x0e, 0x04, 0x0a, 0x0d, 0x0e, 0x05, 0x0a, 0x0d, 0x0e, 0x05, 0x0a, 0x0d, 0x0e, 0x06, 0x0b, 0x0d, 0x0e, 0x06, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e

gUnknown_0860D19C:: @ 860D19C
	.byte 0x17, 0x1b, 0x1d, 0x1e

gUnknown_0860D1A0:: @ 860D1A0
	.byte 0x10, 0x18, 0x1c, 0x1e, 0x11, 0x18, 0x1c, 0x1e, 0x12, 0x19, 0x1c, 0x1e, 0x13, 0x19, 0x1c, 0x1e, 0x14, 0x1a, 0x1d, 0x1e, 0x15, 0x1a, 0x1d, 0x1e, 0x16, 0x1b, 0x1d, 0x1e, 0x17, 0x1b, 0x1d, 0x1e

gUnknown_0860D1C0:: @ 860D1C0
	.byte 0x00, 0x0f, 0x08, 0x07, 0x03, 0x0c, 0x0b, 0x04, 0x01, 0x0e, 0x09, 0x06, 0x02, 0x0d, 0x0a, 0x05

gBattleDomePotentialPointers:: @ 860D1D0
	.4byte gBattleDomeOpponentPotential1
	.4byte gBattleDomeOpponentPotential2
	.4byte gBattleDomeOpponentPotential3
	.4byte gBattleDomeOpponentPotential4
	.4byte gBattleDomeOpponentPotential5
	.4byte gBattleDomeOpponentPotential6
	.4byte gBattleDomeOpponentPotential7
	.4byte gBattleDomeOpponentPotential8
	.4byte gBattleDomeOpponentPotential9
	.4byte gBattleDomeOpponentPotential10
	.4byte gBattleDomeOpponentPotential11
	.4byte gBattleDomeOpponentPotential12
	.4byte gBattleDomeOpponentPotential13
	.4byte gBattleDomeOpponentPotential14
	.4byte gBattleDomeOpponentPotential15
	.4byte gBattleDomeOpponentPotential16
	.4byte gBattleDomeOpponentPotential17

gBattleDomeOpponentStylePointers:: @ 860D214
	.4byte gBattleDomeOpponentStyle1
	.4byte gBattleDomeOpponentStyle2
	.4byte gBattleDomeOpponentStyle3
	.4byte gBattleDomeOpponentStyle4
	.4byte gBattleDomeOpponentStyle5
	.4byte gBattleDomeOpponentStyle6
	.4byte gBattleDomeOpponentStyle7
	.4byte gBattleDomeOpponentStyle8
	.4byte gBattleDomeOpponentStyle9
	.4byte gBattleDomeOpponentStyle10
	.4byte gBattleDomeOpponentStyle11
	.4byte gBattleDomeOpponentStyle12
	.4byte gBattleDomeOpponentStyle13
	.4byte gBattleDomeOpponentStyle14
	.4byte gBattleDomeOpponentStyle15
	.4byte gBattleDomeOpponentStyle16
	.4byte gBattleDomeOpponentStyle17
	.4byte gBattleDomeOpponentStyle18
	.4byte gBattleDomeOpponentStyle19
	.4byte gBattleDomeOpponentStyle20
	.4byte gBattleDomeOpponentStyle21
	.4byte gBattleDomeOpponentStyle22
	.4byte gBattleDomeOpponentStyle23
	.4byte gBattleDomeOpponentStyle24
	.4byte gBattleDomeOpponentStyle25
	.4byte gBattleDomeOpponentStyle26
	.4byte gBattleDomeOpponentStyle27
	.4byte gBattleDomeOpponentStyle28
	.4byte gBattleDomeOpponentStyleUnused1
	.4byte gBattleDomeOpponentStyleUnused2
	.4byte gBattleDomeOpponentStyleUnused3
	.4byte gBattleDomeOpponentStyleUnused4

gBattleDomeOpponentStatsPointers:: @ 860D294
	.4byte gBattleDomeOpponentStats1
	.4byte gBattleDomeOpponentStats2
	.4byte gBattleDomeOpponentStats3
	.4byte gBattleDomeOpponentStats4
	.4byte gBattleDomeOpponentStats5
	.4byte gBattleDomeOpponentStats6
	.4byte gBattleDomeOpponentStats7
	.4byte gBattleDomeOpponentStats8
	.4byte gBattleDomeOpponentStats9
	.4byte gBattleDomeOpponentStats10
	.4byte gBattleDomeOpponentStats11
	.4byte gBattleDomeOpponentStats12
	.4byte gBattleDomeOpponentStats13
	.4byte gBattleDomeOpponentStats14
	.4byte gBattleDomeOpponentStats15
	.4byte gBattleDomeOpponentStats16
	.4byte gBattleDomeOpponentStats17
	.4byte gBattleDomeOpponentStats18
	.4byte gBattleDomeOpponentStats19
	.4byte gBattleDomeOpponentStats20
	.4byte gBattleDomeOpponentStats21
	.4byte gBattleDomeOpponentStats22
	.4byte gBattleDomeOpponentStats23
	.4byte gBattleDomeOpponentStats24
	.4byte gBattleDomeOpponentStats25
	.4byte gBattleDomeOpponentStats26
	.4byte gBattleDomeOpponentStats27
	.4byte gBattleDomeOpponentStats28
	.4byte gBattleDomeOpponentStats29
	.4byte gBattleDomeOpponentStats30
	.4byte gBattleDomeOpponentStats31
	.4byte gBattleDomeOpponentStats32
	.4byte gBattleDomeOpponentStats33
	.4byte gBattleDomeOpponentStats34
	.4byte gBattleDomeOpponentStats35
	.4byte gBattleDomeOpponentStats36
	.4byte gBattleDomeOpponentStats37
	.4byte gBattleDomeOpponentStats38
	.4byte gBattleDomeOpponentStats39
	.4byte gBattleDomeOpponentStats40
	.4byte gBattleDomeOpponentStats41
	.4byte gBattleDomeOpponentStats42
	.4byte gBattleDomeOpponentStats43

gUnknown_0860D340:: @ 860D340
	.byte 0x68, 0x88, 0x68

gUnknown_0860D343:: @ 860D343
	.byte 0x26, 0x3e, 0x4e

gUnknown_0860D346:: @ 860D346
	.byte 0x00, 0x04, 0x00

gUnknown_0860D349:: @ 860D349
	.byte 0x00, 0x05, 0x09, 0x0c, 0x0e, 0x00, 0x00

gBattleDomeMatchNumberPointers:: @ 860D350
	.4byte gBattleDomeMatchNumber1
	.4byte gBattleDomeMatchNumber2
	.4byte gBattleDomeMatchNumber3
	.4byte gBattleDomeMatchNumber4
	.4byte gBattleDomeMatchNumber5
	.4byte gBattleDomeMatchNumber6
	.4byte gBattleDomeMatchNumber7
	.4byte gBattleDomeMatchNumber8
	.4byte gBattleDomeMatchNumber9
	.4byte gBattleDomeMatchNumber10
	.4byte gBattleDomeMatchNumber11
	.4byte gBattleDomeMatchNumber12
	.4byte gBattleDomeMatchNumber13
	.4byte gBattleDomeMatchNumber14
	.4byte gBattleDomeMatchNumber15

gBattleDomeWinStringsPointers:: @ 860D38C
	.4byte gBattleDomeWinStrings1
	.4byte gBattleDomeWinStrings2
	.4byte gBattleDomeWinStrings3
	.4byte gBattleDomeWinStrings4
	.4byte gBattleDomeWinStrings5
	.4byte gBattleDomeWinStrings6
	.4byte gBattleDomeWinStrings7

gUnknown_0860D3A8:: @ 860D3A8
	.byte 0x60, 0x60, 0x60

gUnknown_0860D3AB:: @ 860D3AB
	.byte 0x38, 0x50, 0x68

gUnknown_0860D3AE:: @ 860D3AE
	.byte 0x90, 0x90, 0x90

gUnknown_0860D3B1:: @ 860D3B1
	.byte 0x38, 0x50, 0x68

gUnknown_0860D3B4:: @ 860D3B4
	.byte 0x00, 0x08, 0x0c, 0x04, 0x07, 0x0f, 0x0b, 0x03, 0x02, 0x0a, 0x0e, 0x06, 0x05, 0x0d, 0x09, 0x01

gUnknown_0860D3C4:: @ 860D3C4
	.byte 0x00, 0x02

gUnknown_0860D3C6:: @ 860D3C6
	.byte 0x00, 0x02, 0x02, 0x00, 0x04, 0x02, 0x00, 0x06, 0x02, 0x00, 0x08, 0x02, 0x00, 0x0a, 0x02, 0x00, 0x0c, 0x02, 0x00, 0x0e, 0x02, 0x00, 0x00, 0x04, 0x01, 0x04, 0x04, 0x01, 0x08, 0x04, 0x01, 0x0c
	.byte 0x04, 0x01, 0x00, 0x08, 0x02, 0x08, 0x08, 0x02, 0x00, 0x10, 0x03

gUnknown_0860D3F1:: @ 860D3F1
	.byte 0x00

gUnknown_0860D3F2:: @ 860D3F2
	.byte 0x00, 0x01, 0x70, 0x01, 0x00, 0x00, 0x70, 0x00, 0x30, 0x01, 0x40, 0x01, 0x30, 0x00, 0x40, 0x00, 0x10, 0x01, 0x60, 0x01, 0x10, 0x00, 0x60, 0x00, 0x20, 0x01, 0x50, 0x01, 0x20, 0x00, 0x50

gUnknown_0860D411:: @ 860D411
	.incbin "baserom.gba", 0x60d411, 0x3f	//struct - byte 1 and 2 loaded seperately, 2 added to move 1 addr across

gUnknown_0860d450:: @ 860D450
	.4byte 0x60210409
	.4byte 0x6023040a
	.4byte 0x6047050a
	.4byte 0x6043050b

gUnknown_0860d460:: @ 860D460
	.4byte 0x60210409
	.4byte 0x6023040a
	.4byte 0x6047050a
	.4byte 0x6023050b
	.4byte 0x6027060b
	.4byte 0x6047070b
	.4byte 0x6043070c

gUnknown_0860d47c:: @ 860D47C
	.4byte 0x60210409
	.4byte 0x6023040a
	.4byte 0x6047050a
	.4byte 0x6023050b
	.4byte 0x6027060b
	.4byte 0x6047070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c

gUnknown_0860d4a8:: @ 860D4A8
	.4byte 0x60210409
	.4byte 0x6023040a
	.4byte 0x6047050a
	.4byte 0x6023050b
	.4byte 0x6027060b
	.4byte 0x6047070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d4dc:: @ 860D4DC
	.4byte 0x60210609
	.4byte 0x6021060a
	.4byte 0x6027050a
	.4byte 0x6043050b

gUnknown_0860d4ec:: @ 860D4EC
	.4byte 0x60210609
	.4byte 0x6021060a
	.4byte 0x6027050a
	.4byte 0x6023050b
	.4byte 0x6027060b
	.4byte 0x6047070b
	.4byte 0x6043070c

gUnknown_0860d508:: @ 860D508
	.4byte 0x60210609
	.4byte 0x6021060a
	.4byte 0x6027050a
	.4byte 0x6023050b
	.4byte 0x6027060b
	.4byte 0x6047070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c

gUnknown_0860d534:: @ 860D534
	.4byte 0x60210609
	.4byte 0x6021060a
	.4byte 0x6027050a
	.4byte 0x6023050b
	.4byte 0x6027060b
	.4byte 0x6047070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d568:: @ 860D568
	.4byte 0x60210809
	.4byte 0x6023080a
	.4byte 0x6047090a
	.4byte 0x6021090b

gUnknown_0860d578:: @ 860D578
	.4byte 0x60210809
	.4byte 0x6023080a
	.4byte 0x6047090a
	.4byte 0x6021090b
	.4byte 0x6027080b
	.4byte 0x6027070b
	.4byte 0x6043070c

gUnknown_0860d594:: @ 860D594
	.4byte 0x60210809
	.4byte 0x6023080a
	.4byte 0x6047090a
	.4byte 0x6021090b
	.4byte 0x6027080b
	.4byte 0x6027070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c

gUnknown_0860d5c0:: @ 860D5C0
	.4byte 0x60210809
	.4byte 0x6023080a
	.4byte 0x6047090a
	.4byte 0x6021090b
	.4byte 0x6027080b
	.4byte 0x6027070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d5f4:: @ 860D5F4
	.4byte 0x60210a09
	.4byte 0x60210a0a
	.4byte 0x6027090a
	.4byte 0x6021090b

gUnknown_0860d604:: @ 860D604
	.4byte 0x60210a09
	.4byte 0x60210a0a
	.4byte 0x6027090a
	.4byte 0x6021090b
	.4byte 0x6027080b
	.4byte 0x6027070b
	.4byte 0x6043070c

gUnknown_0860d620:: @ 860D620
	.4byte 0x60210a09
	.4byte 0x60210a0a
	.4byte 0x6027090a
	.4byte 0x6021090b
	.4byte 0x6027080b
	.4byte 0x6027070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c

gUnknown_0860d64c:: @ 860D64C
	.4byte 0x60210a09
	.4byte 0x60210a0a
	.4byte 0x6027090a
	.4byte 0x6021090b
	.4byte 0x6027080b
	.4byte 0x6027070b
	.4byte 0x6023070c
	.4byte 0x6027080c
	.4byte 0x6027090c
	.4byte 0x60270a0c
	.4byte 0x603b0b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d680:: @ 860D680
	.4byte 0x60210c09
	.4byte 0x60230c0a
	.4byte 0x60470d0a
	.4byte 0x60430d0b

gUnknown_0860d690:: @ 860D690
	.4byte 0x60210c09
	.4byte 0x60230c0a
	.4byte 0x60470d0a
	.4byte 0x60230d0b
	.4byte 0x60270e0b
	.4byte 0x60470f0b
	.4byte 0x60210f0c

gUnknown_0860d6ac:: @ 860D6AC
	.4byte 0x60210c09
	.4byte 0x60230c0a
	.4byte 0x60470d0a
	.4byte 0x60230d0b
	.4byte 0x60270e0b
	.4byte 0x60470f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c

gUnknown_0860d6d8:: @ 860D6D8
	.4byte 0x60210c09
	.4byte 0x60230c0a
	.4byte 0x60470d0a
	.4byte 0x60230d0b
	.4byte 0x60270e0b
	.4byte 0x60470f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d70c:: @ 860D70C
	.4byte 0x60210e09
	.4byte 0x60210e0a
	.4byte 0x60270d0a
	.4byte 0x60430d0b

gUnknown_0860d71c:: @ 860D71C
	.4byte 0x60210e09
	.4byte 0x60210e0a
	.4byte 0x60270d0a
	.4byte 0x60230d0b
	.4byte 0x60270e0b
	.4byte 0x60470f0b
	.4byte 0x60210f0c

gUnknown_0860d738:: @ 860D738
	.4byte 0x60210e09
	.4byte 0x60210e0a
	.4byte 0x60270d0a
	.4byte 0x60230d0b
	.4byte 0x60270e0b
	.4byte 0x60470f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c

gUnknown_0860d764:: @ 860D764
	.4byte 0x60210e09
	.4byte 0x60210e0a
	.4byte 0x60270d0a
	.4byte 0x60230d0b
	.4byte 0x60270e0b
	.4byte 0x60470f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d798:: @ 860D798
	.4byte 0x60211009
	.4byte 0x6023100a
	.4byte 0x6047110a
	.4byte 0x6021110b

gUnknown_0860d7a8:: @ 860D7A8
	.4byte 0x60211009
	.4byte 0x6023100a
	.4byte 0x6047110a
	.4byte 0x6021110b
	.4byte 0x6027100b
	.4byte 0x60270f0b
	.4byte 0x60210f0c

gUnknown_0860d7c4:: @ 860D7C4
	.4byte 0x60211009
	.4byte 0x6023100a
	.4byte 0x6047110a
	.4byte 0x6021110b
	.4byte 0x6027100b
	.4byte 0x60270f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c
	
gUnknown_0860d7f0:: @ 860D7F0
	.4byte 0x60211009
	.4byte 0x6023100a
	.4byte 0x6047110a
	.4byte 0x6021110b
	.4byte 0x6027100b
	.4byte 0x60270f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e

gUnknown_0860d824:: @ 860D824
	.4byte 0x602b1209
	.4byte 0x602b120a
	.4byte 0x6027110a
	.4byte 0x6021110b

gUnknown_0860d834:: @ 860D834
	.4byte 0x602b1209
	.4byte 0x602b120a
	.4byte 0x6027110a
	.4byte 0x6021110b
	.4byte 0x6027100b
	.4byte 0x60270f0b
	.4byte 0x60210f0c
	
gUnknown_0860d850:: @ 860D850
	.4byte 0x602b1209
	.4byte 0x602b120a
	.4byte 0x6027110a
	.4byte 0x6021110b
	.4byte 0x6027100b
	.4byte 0x60270f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c

gUnknown_0860d87c:: @ 860D87C
	.4byte 0x602b1209
	.4byte 0x602b120a
	.4byte 0x6027110a
	.4byte 0x6021110b
	.4byte 0x6027100b
	.4byte 0x60270f0b
	.4byte 0x60210f0c
	.4byte 0x60330e0c
	.4byte 0x60320d0c
	.4byte 0x60310c0c
	.4byte 0x60300b0c
	.4byte 0x602c0b0d
	.4byte 0x602d0b0e
	
gUnknown_0860d8b0:: @ 860D8B0
	.4byte 0x60210414
	.4byte 0x60250413
	.4byte 0x60490513
	.4byte 0x60450512

gUnknown_0860d8c0:: @ 860D8C0
	.4byte 0x60210414
	.4byte 0x60250413
	.4byte 0x60490513
	.4byte 0x60250512
	.4byte 0x60290612
	.4byte 0x60490712
	.4byte 0x60450711

gUnknown_0860d8dc:: @ 860D8DC
	.4byte 0x60210414
	.4byte 0x60250413
	.4byte 0x60490513
	.4byte 0x60250512
	.4byte 0x60290612
	.4byte 0x60490712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11

gUnknown_0860d908:: @ 860D908
	.4byte 0x60210414
	.4byte 0x60250413
	.4byte 0x60490513
	.4byte 0x60250512
	.4byte 0x60290612
	.4byte 0x60490712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860d93c:: @ 860D93C
	.4byte 0x60210614
	.4byte 0x60210613
	.4byte 0x60290513
	.4byte 0x60450512

gUnknown_0860d94c:: @ 860D94C
	.4byte 0x60210614
	.4byte 0x60210613
	.4byte 0x60290513
	.4byte 0x60250512
	.4byte 0x60290612
	.4byte 0x60490712
	.4byte 0x60450711

gUnknown_0860d968:: @ 860D968
	.4byte 0x60210614
	.4byte 0x60210613
	.4byte 0x60290513
	.4byte 0x60250512
	.4byte 0x60290612
	.4byte 0x60490712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11

gUnknown_0860d994:: @ 860D994
	.4byte 0x60210614
	.4byte 0x60210613
	.4byte 0x60290513
	.4byte 0x60250512
	.4byte 0x60290612
	.4byte 0x60490712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860d9c8:: @ 860D9C8
	.4byte 0x60210814
	.4byte 0x60250813
	.4byte 0x60490913
	.4byte 0x60210912

gUnknown_0860d9d8:: @ 860D9D8
	.4byte 0x60210814
	.4byte 0x60250813
	.4byte 0x60490913
	.4byte 0x60210912
	.4byte 0x60290812
	.4byte 0x60290712
	.4byte 0x60450711

gUnknown_0860d9f4:: @ 860D9F4
	.4byte 0x60210814
	.4byte 0x60250813
	.4byte 0x60490913
	.4byte 0x60210912
	.4byte 0x60290812
	.4byte 0x60290712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11

gUnknown_0860da20:: @ 860DA20
	.4byte 0x60210814
	.4byte 0x60250813
	.4byte 0x60490913
	.4byte 0x60210912
	.4byte 0x60290812
	.4byte 0x60290712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860da54:: @ 860DA54
	.4byte 0x60210a14
	.4byte 0x60210a13
	.4byte 0x60290913
	.4byte 0x60210912

gUnknown_0860da64:: @ 860DA64
	.4byte 0x60210a14
	.4byte 0x60210a13
	.4byte 0x60290913
	.4byte 0x60210912
	.4byte 0x60290812
	.4byte 0x60290712
	.4byte 0x60450711

gUnknown_0860da80:: @ 860DA80
	.4byte 0x60210a14
	.4byte 0x60210a13
	.4byte 0x60290913
	.4byte 0x60210912
	.4byte 0x60290812
	.4byte 0x60290712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11

gUnknown_0860daac:: @ 860DAAC
	.4byte 0x60210a14
	.4byte 0x60210a13
	.4byte 0x60290913
	.4byte 0x60210912
	.4byte 0x60290812
	.4byte 0x60290712
	.4byte 0x60250711
	.4byte 0x60290811
	.4byte 0x60290911
	.4byte 0x60290a11
	.4byte 0x603c0b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860dae0:: @ 860DAE0
	.4byte 0x60210c14
	.4byte 0x60250c13
	.4byte 0x60490d13
	.4byte 0x60450d12
	
gUnknown_0860daf0:: @ 860DAF0
	.4byte 0x60210c14
	.4byte 0x60250c13
	.4byte 0x60490d13
	.4byte 0x60250d12
	.4byte 0x60290e12
	.4byte 0x60490f12
	.4byte 0x60210f11

gUnknown_0860db0c:: @ 860DB0C
	.4byte 0x60210c14
	.4byte 0x60250c13
	.4byte 0x60490d13
	.4byte 0x60250d12
	.4byte 0x60290e12
	.4byte 0x60490f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11

gUnknown_0860db38:: @ 860DB38
	.4byte 0x60210c14
	.4byte 0x60250c13
	.4byte 0x60490d13
	.4byte 0x60250d12
	.4byte 0x60290e12
	.4byte 0x60490f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860db6c:: @ 860DB6C
	.4byte 0x60210e14
	.4byte 0x60210e13
	.4byte 0x60290d13
	.4byte 0x60450d12

gUnknown_0860db7c:: @ 860DB7C
	.4byte 0x60210e14
	.4byte 0x60210e13
	.4byte 0x60290d13
	.4byte 0x60250d12
	.4byte 0x60290e12
	.4byte 0x60490f12
	.4byte 0x60210f11

gUnknown_0860db98:: @ 860DB98
	.4byte 0x60210e14
	.4byte 0x60210e13
	.4byte 0x60290d13
	.4byte 0x60250d12
	.4byte 0x60290e12
	.4byte 0x60490f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11

gUnknown_0860dbc4:: @ 860DBC4
	.4byte 0x60210e14
	.4byte 0x60210e13
	.4byte 0x60290d13
	.4byte 0x60250d12
	.4byte 0x60290e12
	.4byte 0x60490f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860dbf8:: @ 860DBF8
	.4byte 0x60211014
	.4byte 0x60251013
	.4byte 0x60491113
	.4byte 0x60211112

gUnknown_0860dc08:: @ 860DC08
	.4byte 0x60211014
	.4byte 0x60251013
	.4byte 0x60491113
	.4byte 0x60211112
	.4byte 0x60291012
	.4byte 0x60290f12
	.4byte 0x60210f11

gUnknown_0860dc24:: @ 860DC24
	.4byte 0x60211014
	.4byte 0x60251013
	.4byte 0x60491113
	.4byte 0x60211112
	.4byte 0x60291012
	.4byte 0x60290f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11
	
gUnknown_0860dc50:: @ 860DC50
	.4byte 0x60211014
	.4byte 0x60251013
	.4byte 0x60491113
	.4byte 0x60211112
	.4byte 0x60291012
	.4byte 0x60290f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860dc84:: @ 860DC84
	.4byte 0x602b1214
	.4byte 0x602b1213
	.4byte 0x60291113
	.4byte 0x60211112

gUnknown_0860dc94:: @ 860DC94
	.4byte 0x602b1214
	.4byte 0x602b1213
	.4byte 0x60291113
	.4byte 0x60211112
	.4byte 0x60291012
	.4byte 0x60290f12
	.4byte 0x60210f11
	
gUnknown_0860dcb0:: @ 860DCB0
	.4byte 0x602b1214
	.4byte 0x602b1213
	.4byte 0x60291113
	.4byte 0x60211112
	.4byte 0x60291012
	.4byte 0x60290f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11

gUnknown_0860dcdc:: @ 860DCDC
	.4byte 0x602b1214
	.4byte 0x602b1213
	.4byte 0x60291113
	.4byte 0x60211112
	.4byte 0x60291012
	.4byte 0x60290f12
	.4byte 0x60210f11
	.4byte 0x60380e11
	.4byte 0x60370d11
	.4byte 0x60360c11
	.4byte 0x60350b11
	.4byte 0x602f0b10
	.4byte 0x602e0b0f

gUnknown_0860DD10:: @ 860DD10
	.4byte gUnknown_0860d450
	.4byte gUnknown_0860d460
	.4byte gUnknown_0860d47c
	.4byte gUnknown_0860d4a8
	.4byte gUnknown_0860dc84
	.4byte gUnknown_0860dc94
	.4byte gUnknown_0860dcb0
	.4byte gUnknown_0860dcdc
	.4byte gUnknown_0860d8b0
	.4byte gUnknown_0860d8c0
	.4byte gUnknown_0860d8dc
	.4byte gUnknown_0860d908
	.4byte gUnknown_0860d824
	.4byte gUnknown_0860d834
	.4byte gUnknown_0860d850
	.4byte gUnknown_0860d87c
	.4byte gUnknown_0860d5f4
	.4byte gUnknown_0860d604
	.4byte gUnknown_0860d620
	.4byte gUnknown_0860d64c
	.4byte gUnknown_0860dae0
	.4byte gUnknown_0860daf0
	.4byte gUnknown_0860db0c
	.4byte gUnknown_0860db38
	.4byte gUnknown_0860da54
	.4byte gUnknown_0860da64
	.4byte gUnknown_0860da80
	.4byte gUnknown_0860daac
	.4byte gUnknown_0860d680
	.4byte gUnknown_0860d690
	.4byte gUnknown_0860d6ac
	.4byte gUnknown_0860d6d8
	.4byte gUnknown_0860d4dc
	.4byte gUnknown_0860d4ec
	.4byte gUnknown_0860d508
	.4byte gUnknown_0860d534
	.4byte gUnknown_0860dbf8
	.4byte gUnknown_0860dc08
	.4byte gUnknown_0860dc24
	.4byte gUnknown_0860dc50
	.4byte gUnknown_0860d93c
	.4byte gUnknown_0860d94c
	.4byte gUnknown_0860d968
	.4byte gUnknown_0860d994
	.4byte gUnknown_0860d798
	.4byte gUnknown_0860d7a8
	.4byte gUnknown_0860d7c4
	.4byte gUnknown_0860d7f0
	.4byte gUnknown_0860d568
	.4byte gUnknown_0860d578
	.4byte gUnknown_0860d594
	.4byte gUnknown_0860d5c0
	.4byte gUnknown_0860db6c
	.4byte gUnknown_0860db7c
	.4byte gUnknown_0860db98
	.4byte gUnknown_0860dbc4
	.4byte gUnknown_0860d9c8
	.4byte gUnknown_0860d9d8
	.4byte gUnknown_0860d9f4
	.4byte gUnknown_0860da20
	.4byte gUnknown_0860d70c
	.4byte gUnknown_0860d71c
	.4byte gUnknown_0860d738
	.4byte gUnknown_0860d764

gUnknown_0860DE10:: @ 860DE10
	.byte 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d
	.byte 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d, 0x04, 0x07, 0x0b, 0x0d

gUnknown_0860DE50:: @ 860DE50
	.4byte sub_8195980
	.4byte sub_8195A38
	.4byte sub_8195AE4
	.4byte sub_8195BB0
	.4byte sub_8195C20
	.4byte sub_8195C50
	.4byte sub_8195C7C
	.4byte sub_8195CE4
	.4byte sub_8195D28
	.4byte sub_8195DB8
	
gUnknown_0860DE78:: @ 860DE78
	.2byte 0x003f, 0x0040, 0x0041, 0x0043, 0x0042, 0x0046

gUnknown_0860DE84:: @ 860DE84
	.2byte 0x00b3, 0x00b4, 0x00b7, 0x00c8, 0x00b9, 0x00bb, 0x00c4, 0x00c6, 0x00ba, 0x0000

gUnknown_0860DE98:: @ 860DE98
	.4byte 0x00000010, 0x00000020, 0x00400000, 0x00800000

gUnknown_0860DEA8:: @ 860DEA8
	.4byte 0xffffffef, 0xffffffdf, 0xffbfffff, 0xff7fffff

gUnknown_0860DEB8:: @ 860DEB8 //struct
	.incbin "baserom.gba", 0x60deb8, 0x500
	
gUnknown_0860E3B8:: @ 860E3B8
	.4byte BattleFrontier_PokeNav_2A971C, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9798, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9813, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A98A8, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9977, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A99FD, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9A78, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9AE8, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9BA7, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9C36, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9CC8, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9D44, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9DD7, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9E70, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2A9EFD, 0x00ff0200

gUnknown_0860E430:: @ 860E430
	.4byte BattleFrontier_PokeNav_2A9FAB, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA028, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA099, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA100, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA188, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA214, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA2A1, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA31B, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA3A8, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA442, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA4C5, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA520, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA5AD, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AA64D, 0x00ffff00

gUnknown_0860E4A0:: @ 860E4A0
	.4byte BattleFrontier_PokeNav_2AA6AF, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AA730, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AA77A, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AA81C, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AA88C, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AA934, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AA9D3, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAA40, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAAE4, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAB8C, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAC25, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAC9D, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAD41, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AAE00, 0x00ff0300
	
gUnknown_0860E510:: @ 860E510
	.4byte BattleFrontier_PokeNav_2AAE7F, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AAEF1, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AAF69, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB010, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB076, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB11A, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB1B4, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB23D, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB2E9, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB382, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB410, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB4B0, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB538, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB5E4, 0x00ff0100
	
gUnknown_0860E580:: @ 860E580
	.4byte BattleFrontier_PokeNav_2AB670, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB6CD, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB73C, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB808, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB8B7, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AB95D, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABA03, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABA9F, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABB62, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABC26, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABCE9, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABDA2, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABE5E, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2ABF36, 0x00ff0100

gUnknown_0860E5F0:: @ 860E5F0
	.4byte BattleFrontier_PokeNav_2AC009, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AC0BD, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC18C, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC228, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC30C, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC3B6, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC446, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC5C7, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC682, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC755, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC82C, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AC914, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ACA59, 0x00ff0200
	.4byte BattleFrontier_PokeNav_2ACB02, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ACC3F, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ACD2F, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ACE1E, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ACF32, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2ACFBE, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD0AC, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD194, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD1DF, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD2A8, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD34F, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD44E, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD53A, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD642, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AD801, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AD92E, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2ADA8F, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ADB9B, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ADC92, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ADE08, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2ADF07, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE0D9, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE1FD, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE327, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE3DA, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE489, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE5CD, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE698, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE704, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AE78F, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE859, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AE8E6, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AE998, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AEA8F, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AEB77, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AEBFA, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AECC1, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AED52, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AEE35, 0x00ff0300
	.4byte BattleFrontier_PokeNav_2AEEF4, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AEFDA, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF0E7, 0x00ff0100
	.4byte BattleFrontier_PokeNav_2AF1B8, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF2C4, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF371, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF480, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF671, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF7D8, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AF8F7, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AFA39, 0x00ffff00
	.4byte BattleFrontier_PokeNav_2AFB26, 0x00ffff00

gUnknown_0860E7F0:: @860E7F0
	.4byte BattleFrontier_PokeNav_2AFC07, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFC78, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFCFF, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFDA7, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFE3D, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFECA, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFF64, 0x00050400
	.4byte BattleFrontier_PokeNav_2AFFF0, 0x00050400
	.4byte BattleFrontier_PokeNav_2B00B5, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0129, 0x00050400
	.4byte BattleFrontier_PokeNav_2B01A5, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0232, 0x00050400
	.4byte BattleFrontier_PokeNav_2B02D9, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0366, 0x00050400

gUnknown_0860E860:: @860E860
	.4byte BattleFrontier_PokeNav_2B03E6, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0457, 0x00050400
	.4byte BattleFrontier_PokeNav_2B04DE, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0586, 0x00050400
	.4byte BattleFrontier_PokeNav_2B061C, 0x00050400
	.4byte BattleFrontier_PokeNav_2B06A3, 0x00050400
	.4byte BattleFrontier_PokeNav_2B073B, 0x00050400
	.4byte BattleFrontier_PokeNav_2B07C7, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0894, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0908, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0984, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0A11, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0AB8, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0B45, 0x00050400

gUnknown_0860E8D0:: @860E8D0
	.4byte BattleFrontier_PokeNav_2B0BC5, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0C4A, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0CC7, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0D4A, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0DC8, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0E35, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0ED1, 0x00050400
	.4byte BattleFrontier_PokeNav_2B0F72, 0x00050400
	.4byte BattleFrontier_PokeNav_2B102A, 0x00050400
	.4byte BattleFrontier_PokeNav_2B10A7, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1121, 0x00050400
	.4byte BattleFrontier_PokeNav_2B11D3, 0x00050400
	.4byte BattleFrontier_PokeNav_2B124D, 0x00050400
	.4byte BattleFrontier_PokeNav_2B12D0, 0x00050400

gUnknown_0860E940:: @860E940
	.4byte BattleFrontier_PokeNav_2B1347, 0x00050400
	.4byte BattleFrontier_PokeNav_2B13B1, 0x00050400
	.4byte BattleFrontier_PokeNav_2B142B, 0x00050400
	.4byte BattleFrontier_PokeNav_2B14B4, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1525, 0x00050400
	.4byte BattleFrontier_PokeNav_2B158E, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1622, 0x00050400
	.4byte BattleFrontier_PokeNav_2B169D, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1775, 0x00050400
	.4byte BattleFrontier_PokeNav_2B17F8, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1877, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1946, 0x00050400
	.4byte BattleFrontier_PokeNav_2B19C7, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1A4C, 0x00050400

gUnknown_0860E9B0:: @860E9B0
	.4byte BattleFrontier_PokeNav_2B1ACA, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1B50, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1BE4, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1C6A, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1CCF, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1D38, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1DCD, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1E4B, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1F24, 0x00050400
	.4byte BattleFrontier_PokeNav_2B1FA8, 0x00050400
	.4byte BattleFrontier_PokeNav_2B2022, 0x00050400
	.4byte BattleFrontier_PokeNav_2B20F3, 0x00050400
	.4byte BattleFrontier_PokeNav_2B2175, 0x00050400
	.4byte BattleFrontier_PokeNav_2B21FC, 0x00050400

gUnknown_0860EA20:: @ 860EA20
	.4byte gUnknown_0860E3B8
	.4byte gUnknown_0860E430
	.4byte gUnknown_0860E4A0

gUnknown_0860EA2C:: @ 860EA2C
	.4byte gUnknown_0860E510
	.4byte gUnknown_0860E580

gUnknown_0860EA34:: @ 860EA34
	.4byte gUnknown_0860E5F0
	.4byte gUnknown_0860E7F0
	.4byte gUnknown_0860E860
	.4byte gUnknown_0860E8D0
	.4byte gUnknown_0860E940
	.4byte gUnknown_0860E9B0

gUnknown_0860EA4C:: @ 860EA4C
	.incbin "baserom.gba", 0x60ea4c, 0x20

gUnknown_0860EA6C:: @ 860EA6C
	.incbin "baserom.gba", 0x60ea6c, 0x100

gUnknown_0860EB6C:: @ 860EB6C
	.incbin "baserom.gba", 0x60eb6c, 0x20

gUnknown_0860EB8C:: @ 860EB8C
	.incbin "baserom.gba", 0x60eb8c, 0x3e4

gUnknown_0860EF70:: @ 860EF70
	.incbin "baserom.gba", 0x60ef70, 0x8

gUnknown_0860EF78:: @ 860EF78
	.4byte sub_819612C
	.4byte sub_81961F0
	.4byte sub_8196274
	.4byte sub_81962B0
	.4byte sub_81962D8
	.4byte sub_8196330
	.4byte sub_8196390
	.4byte sub_81963F0

gUnknown_0860EF98:: @ 860EF98
	.incbin "baserom.gba", 0x60ef98, 0x8

gUnknown_0860EFA0:: @ 860EFA0
	.4byte gStringVar1
	.4byte gStringVar2
	.4byte gStringVar3

gUnknown_0860EFAC:: @ 860EFAC
	.4byte sub_8196A44
	.4byte sub_8196A9C
	.4byte sub_8196B98
	.4byte sub_8196C70
	.4byte sub_8196CF4
	.4byte sub_8196D14

gUnknown_0860EFC4:: @ 860EFC4
	.2byte 0x0282, 0x0000, 0xfa72, 0x085e, 0x01e1, 0x0000, 0xfa77, 0x085e, 0x02a9, 0x0000, 0xfa7b, 0x085e, 0x02af, 0x0000, 0xfa80, 0x085e
	.2byte 0x0033, 0x0000, 0xfa84, 0x085e, 0x011f, 0x0000, 0xfa8a, 0x085e

gUnknown_0860EFF4:: @ 860EFF4
	.4byte gText_BattleTower2
	.4byte gText_BattleDome
	.4byte gText_BattlePalace
	.4byte gText_BattleArena
	.4byte gText_BattlePike
	.4byte gText_BattleFactory
	.4byte gText_BattlePyramid

gUnknown_0860F010:: @ 860F010
	.2byte FLAG_BADGE01_GET
	.2byte FLAG_BADGE02_GET
	.2byte FLAG_BADGE03_GET
	.2byte FLAG_BADGE04_GET
	.2byte FLAG_BADGE05_GET
	.2byte FLAG_BADGE06_GET
	.2byte FLAG_BADGE07_GET
	.2byte FLAG_BADGE08_GET

gUnknown_0860F020:: @ 860F020
	.4byte gUnknown_082A5D6C
	.4byte gUnknown_082A5DAB
	.4byte gUnknown_082A5DF1
	.4byte gUnknown_082A5E34
	.4byte gUnknown_082A5E83
	.4byte gUnknown_082A5EB9
	.4byte gUnknown_082A5EF4
	.4byte gUnknown_082A5F39
	.4byte gUnknown_082A5F82
	.4byte gUnknown_082A5FB9
	.4byte gUnknown_082A6018
	.4byte gUnknown_082A6061
	.4byte gUnknown_082A609C
	.4byte gUnknown_082A60D5
	.4byte gUnknown_082A6124
	.4byte gUnknown_082A616F
	.4byte gUnknown_082A61D6
	.4byte gUnknown_082A623A
	.4byte gUnknown_082A6287
	.4byte gUnknown_082A62C9
	.4byte gUnknown_082A6312
