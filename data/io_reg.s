	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata



.align 2
gUnref_82EC784:: @ 82EC784
    .4byte 0x00000000
    .4byte 0x00000000
    .4byte 0x04000008
    .4byte 0x0400000A
    .4byte 0x0400000C
    .4byte 0x0400000E
    .4byte 0x04000010
    .4byte 0x04000014
    .4byte 0x04000018
    .4byte 0x0400001C
    .4byte 0x04000012
    .4byte 0x04000016
    .4byte 0x0400001A
    .4byte 0x0400001E
    .4byte 0x02000100
    .4byte 0x08000400

gOverworldBackgroundLayerFlags:: @ 82EC7C4
	.2byte 0x0100 /* BLDCNT_TGT2_BG0 */
	.2byte 0x0200 /* BLDCNT_TGT2_BG1 */
	.2byte 0x0400 /* BLDCNT_TGT2_BG2 */
	.2byte 0x0800 /* BLDCNT_TGT2_BG3 */

gUnknown_82EC7CC:: @ 82EC7CC
	.2byte 0x0001
	.2byte 0x0002
	.2byte 0x0004
	.2byte 0x0008
