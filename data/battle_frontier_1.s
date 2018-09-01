#include "constants/flags.h"

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
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

	.align 2
gUnknown_0860DEB8:: @ 860DEB8 //struct
	.2byte 0x0025, 0x0000, 0x0108, 0x0208, 0x0308, 0x0103, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x02e1, 0x0000, 0x010c, 0x020c, 0x030c, 0x013e, 0x000c, 0x010c, 0x020c, 0x0000
	.2byte 0x002c, 0x0000, 0x010c, 0x020c, 0x030c, 0x0104, 0x000c, 0x010c, 0x020c, 0x0000
	.2byte 0x0039, 0x0000, 0x0102, 0x0202, 0x0302, 0x0105, 0x0002, 0x0102, 0x0202, 0x0000
	.2byte 0x0040, 0x0000, 0x0101, 0x0201, 0x0301, 0x0106, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x02af, 0x0004, 0x0101, 0x0201, 0x0301, 0x013d, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x02ff, 0x0000, 0x010a, 0x020a, 0x030a, 0x0140, 0x000a, 0x010a, 0x020a, 0x0000
	.2byte 0x005e, 0x0000, 0x0109, 0x0209, 0x0309, 0x0108, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x004e, 0x0000, 0x0106, 0x0206, 0x0306, 0x0107, 0x0006, 0x0106, 0x0206, 0x0000
	.2byte 0x006c, 0x0000, 0x0108, 0x0208, 0x0308, 0x0109, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x0072, 0x0000, 0x0108, 0x0208, 0x0308, 0x010a, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x0090, 0x0000, 0x0108, 0x020a, 0x030a, 0x010e, 0x000a, 0x0108, 0x020a, 0x0000
	.2byte 0x007f, 0x0000, 0x010a, 0x020a, 0x030a, 0x010b, 0x000a, 0x0108, 0x020a, 0x0000
	.2byte 0x0088, 0x0000, 0x0104, 0x0204, 0x0304, 0x010c, 0x0004, 0x0104, 0x0204, 0x0000
	.2byte 0x008f, 0x0000, 0x0107, 0x0207, 0x0307, 0x010d, 0x0007, 0x0107, 0x0207, 0x0000
	.2byte 0x009b, 0x0000, 0x0105, 0x0205, 0x0305, 0x010f, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x00b7, 0x0000, 0x0103, 0x0203, 0x0303, 0x0110, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x02a0, 0x0000, 0x0103, 0x0203, 0x0303, 0x013b, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x00c3, 0x0000, 0x0106, 0x0206, 0x0306, 0x0111, 0x0006, 0x0106, 0x0206, 0x0000
	.2byte 0x00c4, 0x0000, 0x0104, 0x0204, 0x0304, 0x0112, 0x0004, 0x0104, 0x0204, 0x0000
	.2byte 0x00ce, 0x0000, 0x010b, 0x020b, 0x030b, 0x0113, 0x000b, 0x010b, 0x020b, 0x0000
	.2byte 0x00d8, 0x0000, 0x0101, 0x0201, 0x0301, 0x0114, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x02a9, 0x0003, 0x010c, 0x020c, 0x030c, 0x013c, 0x000c, 0x010c, 0x020c, 0x0000
	.2byte 0x00e2, 0x0000, 0x0107, 0x0207, 0x0307, 0x0115, 0x0007, 0x0107, 0x0207, 0x0000
	.2byte 0x00ee, 0x0000, 0x0104, 0x0204, 0x0304, 0x0116, 0x0001, 0x0104, 0x0204, 0x0000
	.2byte 0x00f9, 0x0000, 0x0108, 0x0208, 0x0308, 0x0117, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x00fe, 0x0000, 0x010c, 0x020c, 0x030c, 0x0118, 0x000c, 0x010c, 0x020c, 0x0000
	.2byte 0x0118, 0x0000, 0x0102, 0x0202, 0x0302, 0x011a, 0x0002, 0x0102, 0x0202, 0x0000
	.2byte 0x0111, 0x0000, 0x0101, 0x0201, 0x0301, 0x0119, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x011f, 0x0006, 0x0109, 0x0209, 0x0309, 0x011b, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x012e, 0x0000, 0x010e, 0x020e, 0x030e, 0x011d, 0x000e, 0x010e, 0x020e, 0x0000
	.2byte 0x0125, 0x0000, 0x010b, 0x020b, 0x030b, 0x011c, 0x000b, 0x010b, 0x020b, 0x0000
	.2byte 0x0133, 0x0000, 0x010c, 0x020c, 0x030c, 0x011e, 0x000c, 0x010c, 0x020c, 0x0000
	.2byte 0x0139, 0x0000, 0x010d, 0x020d, 0x030d, 0x011f, 0x000d, 0x010d, 0x020d, 0x0000
	.2byte 0x013e, 0x0000, 0x0101, 0x0201, 0x0301, 0x0120, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x0153, 0x0000, 0x0103, 0x0203, 0x0303, 0x0121, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x0178, 0x0000, 0x0105, 0x0205, 0x0305, 0x0126, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x0171, 0x0000, 0x0109, 0x0209, 0x0309, 0x0125, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x0166, 0x0000, 0x0109, 0x0209, 0x0309, 0x0123, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x016c, 0x0000, 0x0105, 0x0205, 0x0305, 0x0124, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x0182, 0x0000, 0x0109, 0x0209, 0x0309, 0x0128, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x0161, 0x0000, 0x0105, 0x0205, 0x0305, 0x0122, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x0179, 0x0000, 0x0105, 0x0205, 0x0305, 0x0127, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x0188, 0x0000, 0x0104, 0x0204, 0x0304, 0x0129, 0x0004, 0x0104, 0x0204, 0x0000
	.2byte 0x0196, 0x0000, 0x0106, 0x0206, 0x0306, 0x012a, 0x0006, 0x0106, 0x0206, 0x0000
	.2byte 0x01a3, 0x0000, 0x0101, 0x0201, 0x0301, 0x012b, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x01ab, 0x0000, 0x0109, 0x0209, 0x0309, 0x012c, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x01b2, 0x0000, 0x0108, 0x0208, 0x0308, 0x012d, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x01c1, 0x0000, 0x0109, 0x0209, 0x0309, 0x012e, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x01da, 0x0000, 0x0102, 0x0202, 0x0302, 0x012f, 0x0002, 0x0102, 0x0202, 0x0000
	.2byte 0x01e1, 0x0002, 0x0102, 0x0202, 0x0302, 0x0130, 0x0001, 0x0102, 0x0202, 0x0000
	.2byte 0x01ec, 0x0000, 0x0103, 0x0203, 0x0303, 0x0131, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x02e4, 0x0000, 0x0103, 0x0203, 0x0303, 0x013f, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x0200, 0x0000, 0x0107, 0x0207, 0x0307, 0x0132, 0x0007, 0x0107, 0x0207, 0x0000
	.2byte 0x0221, 0x0000, 0x0108, 0x0208, 0x0308, 0x0134, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x021a, 0x0000, 0x0105, 0x0205, 0x0305, 0x0133, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x0009, 0x0000, 0x0108, 0x0208, 0x0308, 0x0102, 0x0008, 0x0108, 0x0208, 0x0000
	.2byte 0x022f, 0x0000, 0x0109, 0x0209, 0x0309, 0x0136, 0x0009, 0x0109, 0x0209, 0x0000
	.2byte 0x0228, 0x0000, 0x0105, 0x0205, 0x0305, 0x0135, 0x0005, 0x0105, 0x0205, 0x0000
	.2byte 0x025c, 0x0000, 0x0102, 0x0202, 0x0302, 0x0137, 0x0002, 0x0102, 0x0202, 0x0000
	.2byte 0x026d, 0x0000, 0x0101, 0x0201, 0x0301, 0x0138, 0x0001, 0x0101, 0x0201, 0x0000
	.2byte 0x0273, 0x0000, 0x0103, 0x0203, 0x0303, 0x0139, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x0001, 0x0000, 0x010f, 0x0203, 0x0303, 0x0101, 0x0003, 0x0103, 0x0203, 0x0000
	.2byte 0x0282, 0x0001, 0x0109, 0x0209, 0x0309, 0x013a, 0x0009, 0x0109, 0x0209, 0x0000

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
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

	.align 2
gUnknown_0860EA20:: @ 860EA20
	.4byte gUnknown_0860E3B8
	.4byte gUnknown_0860E430
	.4byte gUnknown_0860E4A0

	.align 2
gUnknown_0860EA2C:: @ 860EA2C
	.4byte gUnknown_0860E510
	.4byte gUnknown_0860E580

	.align 2
gUnknown_0860EA34:: @ 860EA34
	.4byte gUnknown_0860E5F0
	.4byte gUnknown_0860E7F0
	.4byte gUnknown_0860E860
	.4byte gUnknown_0860E8D0
	.4byte gUnknown_0860E940
	.4byte gUnknown_0860E9B0

	.align 2
gUnknown_0860EA4C:: @ 860EA4C
	.incbin "graphics/unknown/unknown_60EA4C.gbapal"

	.align 2
gUnknown_0860EA6C:: @ 860EA6C
	.incbin "graphics/interface/menu_border.4bpp"

	.align 2
gUnknown_0860EB6C:: @ 860EB6C
	.incbin "graphics/pokenav/icon.gbapal"

	.align 2
gUnknown_0860EB8C:: @ 860EB8C
	.incbin "graphics/pokenav/icon.4bpp.lz"

	.align 2
gText_PokenavCallEllipsis:: @ 860EF70
	.string "………………\p$"

	.align 2
gUnknown_0860EF78:: @ 860EF78
	.4byte sub_819612C
	.4byte sub_81961F0
	.4byte sub_8196274
	.4byte sub_81962B0
	.4byte sub_81962D8
	.4byte sub_8196330
	.4byte sub_8196390
	.4byte sub_81963F0

	.align 2
gUnknown_0860EF98:: @ 860EF98
	window_template 0x00, 0x01, 0x0f, 0x1c, 0x04, 0x0f, 0x0200

	.align 2
gUnknown_0860EFA0:: @ 860EFA0
	.4byte gStringVar1
	.4byte gStringVar2
	.4byte gStringVar3

	.align 2
gUnknown_0860EFAC:: @ 860EFAC
	.4byte sub_8196A44
	.4byte sub_8196A9C
	.4byte sub_8196B98
	.4byte sub_8196C70
	.4byte sub_8196CF4
	.4byte sub_8196D14

	.align 2
gUnknown_0860EFC4:: @ 860EFC4
    .4byte 0x00000282, gText_Kira
    .4byte 0x000001e1, gText_Amy
    .4byte 0x000002a9, gText_John
    .4byte 0x000002af, gText_Roy
    .4byte 0x00000033, gText_Gabby
    .4byte 0x0000011f, gText_Anna

	.align 2
gUnknown_0860EFF4:: @ 860EFF4
	.4byte gText_BattleTower2
	.4byte gText_BattleDome
	.4byte gText_BattlePalace
	.4byte gText_BattleArena
	.4byte gText_BattlePike
	.4byte gText_BattleFactory
	.4byte gText_BattlePyramid

	.align 2
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
	.4byte gBirchDexRatingText_LessThan10
	.4byte gBirchDexRatingText_LessThan20
	.4byte gBirchDexRatingText_LessThan30
	.4byte gBirchDexRatingText_LessThan40
	.4byte gBirchDexRatingText_LessThan50
	.4byte gBirchDexRatingText_LessThan60
	.4byte gBirchDexRatingText_LessThan70
	.4byte gBirchDexRatingText_LessThan80
	.4byte gBirchDexRatingText_LessThan90
	.4byte gBirchDexRatingText_LessThan100
	.4byte gBirchDexRatingText_LessThan110
	.4byte gBirchDexRatingText_LessThan120
	.4byte gBirchDexRatingText_LessThan130
	.4byte gBirchDexRatingText_LessThan140
	.4byte gBirchDexRatingText_LessThan150
	.4byte gBirchDexRatingText_LessThan160
	.4byte gBirchDexRatingText_LessThan170
	.4byte gBirchDexRatingText_LessThan180
	.4byte gBirchDexRatingText_LessThan190
	.4byte gBirchDexRatingText_LessThan200
	.4byte gBirchDexRatingText_DexCompleted
