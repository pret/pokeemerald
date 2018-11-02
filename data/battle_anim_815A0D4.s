#include "constants/battle_anim.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085CE004:: @ 85CE004
	.2byte 0x0000, 0x0004, 0x0010, 0x0004
	.2byte 0x0020, 0x0004, 0x0030, 0x0004
	.2byte 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE01C:: @ 85CE01C
	.4byte gUnknown_085CE004

	.align 2
gUnknown_085CE020:: @ 85CE020
	spr_template ANIM_TAG_SCRATCH, ANIM_TAG_SCRATCH, gUnknown_08524A34, gUnknown_085CE01C, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_085CE038:: @ 85CE038
	spr_template ANIM_TAG_BLACK_SMOKE, ANIM_TAG_BLACK_SMOKE, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A0D4

	.align 2
gUnknown_085CE050:: @ 85CE050
	spr_template ANIM_TAG_BLACK_BALL, ANIM_TAG_BLACK_BALL, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80A78AC

	.align 2
gUnknown_085CE068:: @ 85CE068
	.2byte 0x0000, 0x0028, 0x0010, 0x0008
	.2byte 0x0020, 0x0028, 0xffff, 0x0000

	.align 2
gUnknown_085CE078:: @ 85CE078
	.4byte gUnknown_085CE068

	.align 2
gUnknown_085CE07C:: @ 85CE07C
	spr_template ANIM_TAG_OPENING_EYE, ANIM_TAG_OPENING_EYE, gUnknown_08524914, gUnknown_085CE078, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_085CE094::
	spr_template ANIM_TAG_ROUND_WHITE_HALO, ANIM_TAG_ROUND_WHITE_HALO, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A1B0

	.align 2
gUnknown_085CE0AC::
	spr_template ANIM_TAG_TEAL_ALERT, ANIM_TAG_TEAL_ALERT, gUnknown_08524974, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A254

	.align 2
gUnknown_085CE0C4:: @ 85CE0C4
	.2byte 0x0180, 0x0180, 0x0000, 0x0000
	.2byte 0xffe0, 0x0018, 0x0500, 0x0000
	.2byte 0x0018, 0xffe0, 0x0500, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085CE0E4:: @ 85CE0E4
	.2byte 0x0030, 0x0030, 0x0000, 0x0000
	.2byte 0x0020, 0x0020, 0x0600, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE0FC:: @ 85CE0FC
	.4byte gUnknown_085CE0C4
	.4byte gUnknown_085CE0E4

	.align 2
gUnknown_085CE104:: @ 85CE104
	spr_template ANIM_TAG_EYE, ANIM_TAG_EYE, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_085CE0FC, sub_815A2F0

	.align 2
gUnknown_085CE11C:: @ 85CE11C
	spr_template ANIM_TAG_SPIKES, ANIM_TAG_SPIKES, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A6C4

	.align 2
gUnknown_085CE134:: @ 85CE134
	.2byte 0x0000, 0x0003, 0x0010, 0x0003
	.2byte 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085CE14C:: @ 85CE14C
	.4byte gUnknown_085CE134

	.align 2
gUnknown_085CE150:: @ 85CE150
	spr_template ANIM_TAG_LEER, ANIM_TAG_LEER, gUnknown_08524914, gUnknown_085CE14C, NULL, gDummySpriteAffineAnimTable, sub_815A7B0

	.align 2
gUnknown_085CE168:: @ 85CE168
	.2byte 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085CE170:: @ 85CE170
	.4byte gUnknown_085CE168

	.align 2
gUnknown_085CE174:: @ 85CE174
	.2byte 0xfff9, 0xfff9, 0x10fd, 0x0000
	.2byte 0x0007, 0x0007, 0x1003, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE18C:: @ 85CE18C
	.4byte gUnknown_085CE174

	.align 2
gUnknown_085CE190:: @ 85CE190
	spr_template ANIM_TAG_LETTER_Z, ANIM_TAG_LETTER_Z, gUnknown_08524974, gUnknown_085CE170, NULL, gUnknown_085CE18C, sub_815A7EC

	.align 2
gUnknown_085CE1A8:: @ 85CE1A8
	.2byte 0x0000, 0x0008, 0x0010, 0x0010, 0x0020, 0x0004, 0x0030, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE1BC:: @ 85CE1BC
	.4byte gUnknown_085CE1A8

	.align 2
gUnknown_085CE1C0:: @ 85CE1C0
	.2byte 0x0200, 0x0200, 0x0000, 0x0000
	.2byte 0xffe0, 0xffe0, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE1D8:: @ 85CE1D8
	.4byte gUnknown_085CE1C0

	.align 2
gUnknown_085CE1DC:: @ 85CE1DC
	spr_template ANIM_TAG_FANG_ATTACK, ANIM_TAG_FANG_ATTACK, gUnknown_085249D4, gUnknown_085CE1BC, NULL, gUnknown_085CE1D8, sub_815A8AC

	.align 2
gUnknown_085CE1F4:: @ 85CE1F4
	.2byte 0x0000, 0x0180, 0x0000, 0x0000
	.2byte 0x0010, 0x0000, 0x1400, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE20C:: @ 85CE20C
	.2byte 0x0140, 0x0180, 0x0000, 0x0000
	.2byte 0xfff0, 0x0000, 0x1300, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE224:: @ 85CE224
	.4byte gUnknown_085CE1F4
	.4byte gUnknown_085CE20C

	.align 2
gUnknown_085CE22C:: @ 85CE22C
	spr_template ANIM_TAG_SPOTLIGHT, ANIM_TAG_SPOTLIGHT, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_085CE224, sub_815A934

	.align 2
gUnknown_085CE244::
	spr_template ANIM_TAG_TAG_HAND, ANIM_TAG_TAG_HAND, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815AAA4

	.align 2
gUnknown_085CE25C::
	spr_template ANIM_TAG_TAG_HAND, ANIM_TAG_TAG_HAND, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815ABD0

	.align 2
gUnknown_085CE274:: @ 85CE274
	.2byte 0x0000, 0x0002, 0x0008, 0x0002
	.2byte 0x0010, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_085CE284:: @ 85CE284
	.4byte gUnknown_085CE274

	.align 2
gUnknown_085CE288:: @ 85CE288
	spr_template ANIM_TAG_RAPID_SPIN, ANIM_TAG_RAPID_SPIN, gUnknown_08524934, gUnknown_085CE284, NULL, gDummySpriteAffineAnimTable, sub_815ACD0

	.align 2
gUnknown_085CE2A0:: @ 85CE2A0
	.2byte 0xfff4, 0x0008, 0x0400, 0x0000, 0x0014, 0xffec, 0x0400, 0x0000, 0xfff8, 0x000c, 0x0400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE2C0:: @ 85CE2C0
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085CE2C8:: @ 85CE2C8
	.4byte gUnknown_085CE2C0

	.align 2
gUnknown_085CE2CC:: @ 85CE2CC
	.2byte 0x0000, 0x0000, 0x2805, 0x0000, 0x0000, 0x0000, 0x0a0a, 0x0000, 0x0000, 0x0000, 0x0a0f, 0x0000, 0x0000, 0x0000, 0x2814, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE2F4:: @ 85CE2F4
	.4byte gUnknown_085CE2CC

	.align 2
gUnknown_085CE2F8:: @ 85CE2F8
	spr_template ANIM_TAG_TRI_FORCE_TRIANGLE, ANIM_TAG_TRI_FORCE_TRIANGLE, gUnknown_085249DC, gUnknown_085CE2C8, NULL, gUnknown_085CE2F4, sub_815B27C

	.align 2
gUnknown_085CE310:: @ 85CE310
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003, 0x0020, 0x0043, 0x0010, 0x0043, 0x0000, 0x0043, 0xfffd, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_085CE334:: @ 85CE334
	.4byte gUnknown_085CE310

	.align 2
gUnknown_085CE338:: @ 85CE338
	spr_template ANIM_TAG_ECLIPSING_ORB, ANIM_TAG_ECLIPSING_ORB, gUnknown_08524914, gUnknown_085CE334, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_085CE350:: @ 85CE350
	.2byte 0xfff4, 0x0014, 0x0800, 0x0000, 0x000c, 0xffec, 0x0800, 0x0000, 0x7ffd, 0x0002, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE370:: @ 85CE370
	spr_template ANIM_TAG_POKEBALL, ANIM_TAG_POKEBALL, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815B394

	.align 2
gUnknown_085CE388:: @ 85CE388
	spr_template ANIM_TAG_GOLD_STARS, ANIM_TAG_GOLD_STARS, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815B49C

	.align 2
gUnknown_085CE3A0:: @ 85CE3A0
	spr_template ANIM_TAG_GOLD_STARS, ANIM_TAG_GOLD_STARS, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815B570

	.align 2
gUnknown_085CE3B8:: @ 85CE3B8
	.2byte 0x0008, 0xfff8, 0x0c00, 0x0000, 0xfff0, 0x0010, 0x0c00, 0x0000, 0x0008, 0xfff8, 0x0c00, 0x0000, 0x7ffd, 0x0001, 0x0000, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE3E0:: @ 85CE3E0
	.2byte 0x0000, 0x0006, 0x1400, 0x0000, 0x0000, 0x0000, 0x1400, 0x0000, 0x0000, 0xffee, 0x0600, 0x0000, 0xffee, 0xffee, 0x0300, 0x0000
	.2byte 0x0000, 0x0000, 0x0f00, 0x0000, 0x0004, 0x0004, 0x0d00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE418:: @ 85CE418
	spr_template ANIM_TAG_BLUE_ORB, ANIM_TAG_BLUE_ORB, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815B70C

	.align 2
gUnknown_085CE430:: @ 85CE430
	.2byte 0x0000, 0x0006, 0x1400, 0x0000, 0x0000, 0x0000, 0x1400, 0x0000, 0x0007, 0xffe2, 0x0600, 0x0000, 0x0000, 0x0000, 0x1400, 0x0000
	.2byte 0xfffe, 0x0003, 0x1400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE460:: @ 85CE460
	.byte 0xe8, 0x18, 0xfc, 0x00

	.align 2
gUnknown_085CE464:: @ 85CE464
	.2byte 0x0000, 0x0006, 0x0004, 0x0006, 0xfffe, 0x0000

	.align 2
gUnknown_085CE470:: @ 85CE470
	.2byte 0x0008, 0x0006, 0xffff, 0x0000

	.align 2
gUnknown_085CE478:: @ 85CE478
	.2byte 0x000c, 0x0006, 0xffff, 0x0000

	.align 2
gUnknown_085CE480:: @ 85CE480
	.4byte gUnknown_085CE464
	.4byte gUnknown_085CE470
	.4byte gUnknown_085CE478

	.align 2
gUnknown_085CE48C:: @ 85CE48C
	spr_template ANIM_TAG_GREEN_STAR, ANIM_TAG_GREEN_STAR, gUnknown_0852490C, gUnknown_085CE480, NULL, gDummySpriteAffineAnimTable, sub_815BE04

	.align 2
gUnknown_085CE4A4:: @ 85CE4A4
	.byte 0x78, 0x50, 0x28, 0x00

	.align 2
gUnknown_085CE4A8:: @ 85CE4A8
	.2byte 0x0000, 0x0000, 0x0032, 0x0000

	.align 2
gUnknown_085CE4B0:: @ 85CE4B0
	.2byte 0x0000, 0xfff1, 0x0700, 0x0000, 0x0000, 0x000f, 0x0700, 0x0000, 0x7ffd, 0x0002, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE4D0:: @ 85CE4D0
	spr_template ANIM_TAG_ANGER, ANIM_TAG_ANGER, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815C400

	.align 2
gUnknown_085CE4E8:: @ 85CE4E8
	.2byte 0x0000, 0x0008, 0x0001, 0x0008, 0x0002, 0x0008, 0x0003, 0x0008, 0x0003, 0x0088, 0x0002, 0x0088, 0x0000, 0x0088, 0x0001, 0x0088
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_085CE50C:: @ 85CE50C
	.2byte 0x0000, 0x0048, 0x0001, 0x0048, 0x0002, 0x0048, 0x0003, 0x0048, 0x0003, 0x00c8, 0x0002, 0x00c8, 0x0000, 0x00c8, 0x0001, 0x00c8
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_085CE530:: @ 85CE530
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085CE538:: @ 85CE538
	.4byte gUnknown_085CE4E8
	.4byte gUnknown_085CE50C
	.4byte gUnknown_085CE530

	.align 2
gUnknown_085CE544:: @ 85CE544
	spr_template ANIM_TAG_PINK_PETAL, ANIM_TAG_PINK_PETAL, gUnknown_08524904, gUnknown_085CE538, NULL, gDummySpriteAffineAnimTable, sub_815C6B0

	.align 2
gUnknown_085CE55C:: @ 85CE55C
	.byte 0x0c, 0x18, 0x10, 0x16, 0x13, 0x13, 0x15, 0x10, 0x17, 0x0c, 0x16, 0x07, 0x13, 0x04, 0x10, 0x01, 0x0b, 0x00, 0x06, 0x01, 0x04, 0x04, 0x01, 0x07, 0x00, 0x0c, 0x02, 0x11, 0x04, 0x13, 0x08, 0x16

	.align 2
gUnknown_085CE57C:: @ 85CE57C
	.2byte 0x0000, 0x0005, 0x0004, 0x0009, 0x0008, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_085CE58C:: @ 85CE58C
	.4byte gUnknown_085CE57C

	.align 2
gUnknown_085CE590:: @ 85CE590
	spr_template ANIM_TAG_PAIN_SPLIT, ANIM_TAG_PAIN_SPLIT, gUnknown_0852490C, gUnknown_085CE58C, NULL, gDummySpriteAffineAnimTable, sub_815C95C
gUnknown_085CE5A8::
	spr_template ANIM_TAG_CONFETTI, ANIM_TAG_CONFETTI, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815CB88
gUnknown_085CE5C0::
	spr_template ANIM_TAG_SPOTLIGHT, ANIM_TAG_SPOTLIGHT, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_085CE224, sub_815CC94
gBattleAnimSpriteTemplate_85CE5D8::
	spr_template ANIM_TAG_BLUE_ORB, ANIM_TAG_BLUE_ORB, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815CDB4

	.align 2
gUnknown_085CE5F0:: @ 85CE5F0
	.2byte 0x0010, 0x0000, 0x0400, 0x0000, 0x0000, 0xfffd, 0x1000, 0x0000, 0x0004, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000, 0x1800, 0x0000
	.2byte 0xfffb, 0x0003, 0x1000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE620:: @ 85CE620
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0800, 0x0000, 0x0008, 0x0008, 0x0800, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE640:: @ 85CE640
	.2byte 0x00c0, 0x00c0, 0x0000, 0x0000, 0x0008, 0x0008, 0x0800, 0x0000, 0xfff8, 0xfff8, 0x0800, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE660:: @ 85CE660
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0008, 0x0008, 0x0800, 0x0000, 0xfff8, 0xfff8, 0x0800, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE680:: @ 85CE680
	.4byte gUnknown_085CE620
	.4byte gUnknown_085CE640
	.4byte gUnknown_085CE660

	.align 2
gUnknown_085CE68C:: @ 85CE68C
	spr_template ANIM_TAG_PINK_CLOUD, ANIM_TAG_PINK_CLOUD, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_085CE680, sub_815D7B4

	.align 2
gUnknown_085CE6A4:: @ 85CE6A4
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0xfffc, 0xfffa, 0x1000, 0x0000, 0x0004, 0x0006, 0x1000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE6C4:: @ 85CE6C4
	.2byte 0x00c0, 0x00c0, 0x0000, 0x0000, 0x0004, 0x0006, 0x1000, 0x0000, 0xfffc, 0xfffa, 0x1000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE6E4:: @ 85CE6E4
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0004, 0x0006, 0x1000, 0x0000, 0xfffc, 0xfffa, 0x1000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE704:: @ 85CE704
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0008, 0x000a, 0x1e00, 0x0000, 0xfff8, 0xfff6, 0x1000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE724:: @ 85CE724
	.4byte gUnknown_085CE6A4
	.4byte gUnknown_085CE6C4
	.4byte gUnknown_085CE6E4
	.4byte gUnknown_085CE704

	.align 2
gUnknown_085CE734:: @ 85CE734
	spr_template ANIM_TAG_PINK_CLOUD, ANIM_TAG_PINK_CLOUD, gUnknown_085249D4, gDummySpriteAnimTable, NULL, gUnknown_085CE724, sub_815D870

	.align 2
gUnknown_085CE74C:: @ 85CE74C
	.2byte 0xfff0, 0x0010, 0x0600, 0x0000, 0x0010, 0xfff0, 0x0c00, 0x0000, 0xfff0, 0x0010, 0x0600, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE76C:: @ 85CE76C
	spr_template ANIM_TAG_SWEAT_DROP, ANIM_TAG_SWEAT_DROP, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815DEBC

	.align 2
gUnknown_085CE784:: @ 85CE784
	.byte 0x3c, 0x07, 0xbc, 0x16, 0x5b, 0x22, 0xdb, 0x2d, 0x5a, 0x3d, 0xfa, 0x48, 0x79, 0x54, 0x19, 0x64, 0x19, 0x5c, 0x19, 0x50, 0x19, 0x40, 0x19, 0x34, 0x1a, 0x28, 0x1a, 0x18, 0x1a, 0x0c, 0x1b, 0x00
	.byte 0x3b, 0x00, 0xbb, 0x00, 0x3b, 0x01, 0x9b, 0x01, 0x1c, 0x02, 0x7c, 0x02, 0xfc, 0x02, 0x7d, 0x03

	.align 2
gUnknown_085CE7B4:: @ 85CE7B4
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_085CE7C0:: @ 85CE7C0
	.2byte 0x0020, 0x0003, 0x0030, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_085CE7CC:: @ 85CE7CC
	.4byte gUnknown_085CE7B4
	.4byte gUnknown_085CE7C0

	.align 2
gUnknown_085CE7D4:: @ 85CE7D4
	spr_template ANIM_TAG_NOISE_LINE, ANIM_TAG_NOISE_LINE, gUnknown_08524914, gUnknown_085CE7CC, NULL, gDummySpriteAffineAnimTable, sub_815E01C

	.align 2
gUnknown_085CE7EC:: @ 85CE7EC
	spr_template ANIM_TAG_SMALL_RED_EYE, ANIM_TAG_SMALL_RED_EYE, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815E404
gUnknown_085CE804::
	spr_template ANIM_TAG_PAW_PRINT, ANIM_TAG_PAW_PRINT, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815E444

	.align 2
gUnknown_085CE81C:: @ 85CE81C
	.2byte 0x0000, 0x0000, 0x18fc, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE82C:: @ 85CE82C
	.2byte 0x0100, 0x0100, 0x00c0, 0x0000, 0x0000, 0x0000, 0x1804, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE844:: @ 85CE844
	.4byte gUnknown_085CE81C
	.4byte gUnknown_085CE82C

	.align 2
gUnknown_085CE84C:: @ 85CE84C
	spr_template ANIM_TAG_RED_BALL, ANIM_TAG_RED_BALL, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_085CE844, SpriteCallbackDummy

	.align 2
gUnknown_085CE864::
	spr_template ANIM_TAG_TAG_HAND, ANIM_TAG_TAG_HAND, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815E6D8

	.align 2
gUnknown_085CE87C:: @ 85CE87C
	.2byte 0x0000, 0xfff0, 0x0600, 0x0000, 0x0000, 0x0010, 0x0600, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE894:: @ 85CE894
	spr_template ANIM_TAG_SMELLINGSALT_EFFECT, ANIM_TAG_SMELLINGSALT_EFFECT, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815E954
gUnknown_085CE8AC::
	spr_template ANIM_TAG_TAG_HAND, ANIM_TAG_TAG_HAND, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815EA14
gUnknown_085CE8C4::
	spr_template ANIM_TAG_MAGNIFYING_GLASS, ANIM_TAG_MAGNIFYING_GLASS, gUnknown_08524A34, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815EE84
gUnknown_085CE8DC::
	spr_template ANIM_TAG_GOLD_STARS, ANIM_TAG_GOLD_STARS, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815F18C
gUnknown_085CE8F4::
	spr_template ANIM_TAG_GOLD_STARS, ANIM_TAG_GOLD_STARS, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81061C4
gUnknown_085CE90C::
	spr_template ANIM_TAG_X_SIGN, ANIM_TAG_X_SIGN, gUnknown_0852491C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815F48C
gUnknown_085CE924::
	spr_template ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815FE80

	.align 2
gUnknown_085CE93C:: @ 85CE93C
	.2byte 0x0000, 0x0004, 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE948:: @ 85CE948
	.4byte gUnknown_085CE93C

	.align 2
gUnknown_085CE94C:: @ 85CE94C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x08fc, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE964:: @ 85CE964
	.2byte 0xff00, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0804, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE97C:: @ 85CE97C
	.4byte gUnknown_085CE94C
	.4byte gUnknown_085CE964

	.align 2
gUnknown_085CE984:: @ 85CE984
	spr_template ANIM_TAG_SLAM_HIT_2, ANIM_TAG_SLAM_HIT_2, gUnknown_0852497C, gUnknown_085CE948, NULL, gUnknown_085CE97C, sub_8160338

	.align 2
gUnknown_085CE99C:: @ 85CE99C
	.2byte 0x0000, 0x0000, 0x40fc, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE9AC:: @ 85CE9AC
	.4byte gUnknown_085CE99C

	.align 2
gUnknown_085CE9B0:: @ 85CE9B0
	spr_template ANIM_TAG_RECYCLE, ANIM_TAG_RECYCLE, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_085CE9AC, sub_81603A8

	.align 2
gUnknown_085CE9C8:: @ 85CE9C8
	.2byte 0x0000, 0x0010, 0x0400, 0x0000, 0xfffe, 0x0000, 0x0800, 0x0000, 0x0000, 0x0004, 0x0400, 0x0000, 0x0000, 0x0000, 0x1800, 0x0000
	.2byte 0x0001, 0xfffb, 0x1000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

