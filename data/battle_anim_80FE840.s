#include "constants/battle_anim.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

    .align 2
gUnknown_085924F4:: @ 85924F4
	.2byte 0x0000, 0x0007, 0x0010, 0x0007, 0x0020, 0x0007, 0x0030, 0x0007, 0xffff, 0x0000

    .align 2
gUnknown_08592508:: @ 8592508
	.2byte 0x0000, 0x0047, 0x0010, 0x0047, 0x0020, 0x0047, 0x0030, 0x0047, 0xffff, 0x0000

    .align 2
gUnknown_0859251C:: @ 859251C
	.2byte 0x0000, 0x0007, 0x0010, 0x0007, 0x0020, 0x0007, 0xffff, 0x0000

    .align 2
gUnknown_0859252C:: @ 859252C
	.2byte 0x0000, 0x0047, 0x0010, 0x0047, 0x0020, 0x0047, 0xffff, 0x0000

    .align 2
gUnknown_0859253C:: @ 859253C
	.4byte gUnknown_085924F4
	.4byte gUnknown_08592508
	.4byte gUnknown_0859251C
	.4byte gUnknown_0859252C

    .align 2
gUnknown_0859254C:: @ 859254C
	spr_template ANIM_TAG_ROOTS, ANIM_TAG_ROOTS, gUnknown_08524914, gUnknown_0859253C, NULL, gDummySpriteAffineAnimTable, sub_80FF768

    .align 2
gUnknown_08592564:: @ 8592564
	spr_template ANIM_TAG_ROOTS, ANIM_TAG_ROOTS, gUnknown_08524914, gUnknown_0859253C, NULL, gDummySpriteAffineAnimTable, sub_80FF7EC

    .align 2
gUnknown_0859257C:: @ 859257C
	.2byte 0x0003, 0x0003, 0x0000, 0x0005, 0xfffe, 0x0000

    .align 2
gUnknown_08592588:: @ 8592588
	.4byte gUnknown_0859257C

    .align 2
gUnknown_0859258C:: @ 859258C
	spr_template ANIM_TAG_ORBS, ANIM_TAG_ORBS, gUnknown_08524904, gUnknown_08592588, NULL, gDummySpriteAffineAnimTable, sub_80FF934

    .align 2
gUnknown_085925A4:: @ 85925A4
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

    .align 2
gUnknown_085925AC:: @ 85925AC
	.4byte gUnknown_085925A4

    .align 2
gUnknown_085925B0:: @ 85925B0
	.2byte 0x0000, 0x0000, 0x0afc, 0x0000, 0x0000, 0x0000, 0x1404, 0x0000
	.2byte 0x0000, 0x0000, 0x0afc, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

    .align 2
gUnknown_085925D0:: @ 85925D0
	.2byte 0x0000, 0x0000, 0x02ff, 0x0000, 0x0000, 0x0000, 0x0401, 0x0000
	.2byte 0x0000, 0x0000, 0x04ff, 0x0000, 0x0000, 0x0000, 0x0401, 0x0000
	.2byte 0x0000, 0x0000, 0x04ff, 0x0000, 0x0000, 0x0000, 0x0201, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

    .align 2
gUnknown_08592608:: @ 8592608
	.4byte gUnknown_085925B0
	.4byte gUnknown_085925D0

    .align 2
gUnknown_08592610:: @ 8592610
	spr_template ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gUnknown_08524974, gUnknown_085925AC, NULL, gUnknown_08592608, sub_80FFB18

    .align 2
gBattleAnimSpriteTemplate_8592628:: @ 8592628
	spr_template ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gUnknown_08524974, gUnknown_085925AC, NULL, gUnknown_08592608, sub_80FFBF4

    .align 2
gUnknown_08592640:: @ 8592640
	.2byte 0x0000, 0x0004, 0x0004, 0x0004, 0x0008, 0x0004, 0x000c, 0x0004, 0xffff, 0x0000

    .align 2
gUnknown_08592654:: @ 8592654
	.4byte gUnknown_08592640

    .align 2
gUnknown_08592658:: @ 8592658
	spr_template ANIM_TAG_GREEN_SPARKLE, ANIM_TAG_GREEN_SPARKLE, gUnknown_0852490C, gUnknown_08592654, NULL, gDummySpriteAffineAnimTable, sub_80FFC70

    .align 2
gUnknown_08592670:: @ 8592670
	spr_template ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gUnknown_08524974, gUnknown_085925AC, NULL, gUnknown_08592608, sub_80FFCB4

    .align 2
gUnknown_08592688:: @ 8592688
	.2byte 0x0000, 0x0000, 0x0300, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

    .align 2
gUnknown_08592698:: @ 8592698
	.2byte 0x0000, 0xfff6, 0x0300, 0x0000, 0x0000, 0xfffa, 0x0300, 0x0000
	.2byte 0x0000, 0xfffe, 0x0300, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000
	.2byte 0x0000, 0x0002, 0x0300, 0x0000, 0x0000, 0x0006, 0x0300, 0x0000
	.2byte 0x0000, 0x000a, 0x0300, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

    .align 2
gUnknown_085926D8:: @ 85926D8
	.4byte gUnknown_08592688
	.4byte gUnknown_08592698
	.4byte gUnknown_085925B0
	.4byte gUnknown_085925D0

    .align 2
gUnknown_085926E8:: @ 85926E8
	spr_template ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gUnknown_08524974, gUnknown_085925AC, NULL, gUnknown_085926D8, sub_80FFDBC

	.align 2
gUnknown_08592700:: @ 8592700
	.2byte 0x1805, 0x0001, 0x0004, 0x1008, 0x00ff, 0x0002, 0x1008, 0x0001
	.2byte 0x0002, 0x1008, 0x0001, 0x0002, 0x1008, 0x0001, 0x0010, 0x0000
	.2byte 0x007f, 0x0000

	.align 2
gUnknown_08592724:: @ 8592724
	.2byte 0x001c, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_0859272C:: @ 859272C
	.2byte 0x0020, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592734:: @ 8592734
	.2byte 0x0014, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_0859273C:: @ 859273C
	.2byte 0x001c, 0x0041, 0xffff, 0x0000

	.align 2
gUnknown_08592744:: @ 8592744
	.2byte 0x0010, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_0859274C:: @ 859274C
	.2byte 0x0010, 0x0041, 0xffff, 0x0000

	.align 2
gUnknown_08592754:: @ 8592754
	.2byte 0x001c, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_0859275C:: @ 859275C
	.4byte gUnknown_08592724
	.4byte gUnknown_0859272C
	.4byte gUnknown_08592734
	.4byte gUnknown_0859273C
	.4byte gUnknown_08592744
	.4byte gUnknown_0859274C
	.4byte gUnknown_08592754

	.align 2
gUnknown_08592778:: @ 8592778
	spr_template ANIM_TAG_LEAF, ANIM_TAG_LEAF, gUnknown_0852490C, gUnknown_0859275C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08592790:: @ 8592790
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0104, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085927A8:: @ 85927A8
	.4byte gUnknown_08592790

	.align 2
gUnknown_085927AC:: @ 85927AC
	spr_template ANIM_TAG_FLOWER, ANIM_TAG_FLOWER, gUnknown_08524904, gUnknown_08592318, NULL, gDummySpriteAffineAnimTable, sub_8100640

	.align 2
gUnknown_085927C4:: @ 85927C4
	spr_template ANIM_TAG_FLOWER, ANIM_TAG_FLOWER, gUnknown_0852496C, gUnknown_08592314, NULL, gUnknown_085927A8, sub_8100640

	.align 2
gUnknown_085927DC:: @ 85927DC
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x01f6, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085927F4:: @ 85927F4
	.2byte 0x00c0, 0x00c0, 0x0000, 0x0000, 0x0000, 0x0000, 0x01f4, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_0859280C:: @ 859280C
	.2byte 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 0x01f1, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08592824:: @ 8592824
	.4byte gUnknown_085927DC

	.align 2
gUnknown_08592828:: @ 8592828
	.4byte gUnknown_085927F4

	.align 2
gUnknown_0859282C:: @ 859282C
	.4byte gUnknown_0859280C

	.align 2
gUnknown_08592830:: @ 8592830
	spr_template ANIM_TAG_SPARKLE_6, ANIM_TAG_SPARKLE_6, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08592824, sub_8100640

	.align 2
gUnknown_08592848:: @ 8592848
	spr_template ANIM_TAG_SPARKLE_6, ANIM_TAG_SPARKLE_6, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08592828, sub_8100640

	.align 2
gUnknown_08592860:: @ 8592860
	spr_template ANIM_TAG_SPARKLE_6, ANIM_TAG_SPARKLE_6, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_0859282C, sub_8100640

	.align 2
gUnknown_08592878:: @ 8592878
	.2byte 0x001f, 0x027f, 0x03ff, 0x03e0, 0x7dc5, 0x7d56, 0x7eb6, 0x0000

	.align 2
gUnknown_08592888:: @ 8592888
	spr_template ANIM_TAG_GREEN_SPIKE, ANIM_TAG_GREEN_SPIKE, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8100898

	.align 2
gUnknown_085928A0:: @ 85928A0
	.2byte 0x0040, 0x0003, 0x0050, 0x0003, 0x0060, 0x0003, 0x0070, 0x0006, 0xffff, 0x0000

	.align 2
gUnknown_085928B4:: @ 85928B4
	.2byte 0x0040, 0x0043, 0x0050, 0x0043, 0x0060, 0x0043, 0x0070, 0x0046, 0xffff, 0x0000

	.align 2
gUnknown_085928C8:: @ 85928C8
	.4byte gUnknown_085928A0
	.4byte gUnknown_085928B4

	.align 2
gUnknown_085928D0:: @ 85928D0
	spr_template ANIM_TAG_SLAM_HIT, ANIM_TAG_SLAM_HIT, gUnknown_08524914, gUnknown_085928C8, NULL, gDummySpriteAffineAnimTable, sub_8100A50

	.align 2
gUnknown_085928E8:: @ 85928E8
	spr_template ANIM_TAG_WHIP_HIT, ANIM_TAG_WHIP_HIT, gUnknown_08524914, gUnknown_085928C8, NULL, gDummySpriteAffineAnimTable, sub_8100A50

	.align 2
gUnknown_08592900:: @ 8592900
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004, 0x0040, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08592918:: @ 8592918
	.4byte gUnknown_08592900

	.align 2
gUnknown_0859291C:: @ 859291C
	spr_template ANIM_TAG_UNUSED_HIT, ANIM_TAG_UNUSED_HIT, gUnknown_08524914, gUnknown_08592918, NULL, gDummySpriteAffineAnimTable, sub_81009F8

	.align 2
gUnknown_08592934:: @ 8592934
	spr_template 0x2726, 0x2726, gUnknown_08524914, gUnknown_08592918, NULL, gDummySpriteAffineAnimTable, sub_81009F8

	.align 2
gUnknown_0859294C:: @ 859294C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859295C:: @ 859295C
	.2byte 0x0100, 0x0100, 0x0020, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859296C:: @ 859296C
	.2byte 0x0100, 0x0100, 0x0040, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859297C:: @ 859297C
	.2byte 0x0100, 0x0100, 0x0060, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859298C:: @ 859298C
	.2byte 0x0100, 0x0100, 0x0080, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859299C:: @ 859299C
	.2byte 0x0100, 0x0100, 0x00a0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085929AC:: @ 85929AC
	.2byte 0x0100, 0x0100, 0x00c0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085929BC:: @ 85929BC
	.2byte 0x0100, 0x0100, 0x00e0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085929CC:: @ 85929CC
	.4byte gUnknown_0859294C
	.4byte gUnknown_0859295C
	.4byte gUnknown_0859296C
	.4byte gUnknown_0859297C
	.4byte gUnknown_0859298C
	.4byte gUnknown_0859299C
	.4byte gUnknown_085929AC
	.4byte gUnknown_085929BC

	.align 2
gUnknown_085929EC:: @ 85929EC
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_085929CC, sub_8100A94

	.align 2
gUnknown_08592A04:: @ 8592A04
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0030, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08592A18:: @ 8592A18
	.4byte gUnknown_08592A04

	.align 2
gCuttingSliceSpriteTemplate:: @ 8592A1C
	spr_template ANIM_TAG_CUT, ANIM_TAG_CUT, gUnknown_08524A34, gUnknown_08592A18, NULL, gDummySpriteAffineAnimTable, sub_8100AE0

	.align 2
gUnknown_08592A34:: @ 8592A34
	spr_template ANIM_TAG_CUT, ANIM_TAG_CUT, gUnknown_08524A34, gUnknown_08592A18, NULL, gDummySpriteAffineAnimTable, sub_8100B88

	.align 2
gUnknown_08592A4C:: @ 8592A4C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592A54:: @ 8592A54
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592A5C:: @ 8592A5C
	.2byte 0x0008, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592A64:: @ 8592A64
	.2byte 0x000c, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592A6C:: @ 8592A6C
	.2byte 0x0010, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592A74:: @ 8592A74
	.2byte 0x0014, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08592A7C:: @ 8592A7C
	.2byte 0x0000, 0x0081, 0xffff, 0x0000

	.align 2
gUnknown_08592A84:: @ 8592A84
	.2byte 0x0004, 0x0081, 0xffff, 0x0000

	.align 2
gUnknown_08592A8C:: @ 8592A8C
	.2byte 0x0008, 0x0081, 0xffff, 0x0000

	.align 2
gUnknown_08592A94:: @ 8592A94
	.2byte 0x000c, 0x0081, 0xffff, 0x0000

	.align 2
gUnknown_08592A9C:: @ 8592A9C
	.4byte gUnknown_08592A4C
	.4byte gUnknown_08592A54
	.4byte gUnknown_08592A5C
	.4byte gUnknown_08592A64
	.4byte gUnknown_08592A6C
	.4byte gUnknown_08592A74
	.4byte gUnknown_08592A7C
	.4byte gUnknown_08592A84
	.4byte gUnknown_08592A8C
	.4byte gUnknown_08592A94

	.align 2
gUnknown_08592AC4:: @ 8592AC4
	spr_template ANIM_TAG_MUSIC_NOTES, ANIM_TAG_MUSIC_NOTES, gUnknown_0852490C, gUnknown_08592A9C, NULL, gDummySpriteAffineAnimTable, sub_8100E1C

	.align 2
gUnknown_08592ADC:: @ 8592ADC
	spr_template ANIM_TAG_PROTECT, ANIM_TAG_PROTECT, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8100EF0

	.align 2
gUnknown_08592AF4:: @ 8592AF4
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08592B04:: @ 8592B04
	.2byte 0x0000, 0x0000, 0x0c02, 0x0000, 0x0000, 0x0000, 0x0600, 0x0000
	.2byte 0x0000, 0x0000, 0x18fe, 0x0000, 0x0000, 0x0000, 0x0600, 0x0000
	.2byte 0x0000, 0x0000, 0x0c02, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08592B34:: @ 8592B34
	.4byte gUnknown_08592AF4
	.4byte gUnknown_08592B04

	.align 2
gUnknown_08592B3C:: @ 8592B3C
	spr_template ANIM_TAG_MILK_BOTTLE, ANIM_TAG_MILK_BOTTLE, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08592B34, sub_81010CC

	.align 2
gUnknown_08592B54:: @ 8592B54
	.2byte 0x0000, 0x0007, 0x0010, 0x0007, 0x0020, 0x0007, 0x0030, 0x0007
	.2byte 0x0040, 0x0007, 0x0050, 0x0007, 0x0060, 0x0007, 0x0070, 0x0007
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_08592B78:: @ 8592B78
	.4byte gUnknown_08592B54

	.align 2
gUnknown_08592B7C:: @ 8592B7C
	spr_template ANIM_TAG_SPARKLE_2, ANIM_TAG_SPARKLE_2, gUnknown_08524914, gUnknown_08592B78, NULL, gDummySpriteAffineAnimTable, sub_810130C

	.align 2
gUnknown_08592B94:: @ 8592B94
	spr_template ANIM_TAG_SPARKLE_2, ANIM_TAG_SPARKLE_2, gUnknown_08524914, gUnknown_08592B78, NULL, gDummySpriteAffineAnimTable, sub_810135C

	.align 2
gUnknown_08592BAC:: @ 8592BAC
	.2byte 0x0000, 0x000a, 0x0004, 0x000a, 0x0008, 0x000a, 0x000c, 0x000a
	.2byte 0x0010, 0x001a, 0x0010, 0x0005, 0x0014, 0x0005, 0x0018, 0x000f
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_08592BD0:: @ 8592BD0
	.2byte 0x0000, 0x004a, 0x0004, 0x004a, 0x0008, 0x004a, 0x000c, 0x004a
	.2byte 0x0010, 0x005a, 0x0010, 0x0045, 0x0014, 0x0045, 0x0018, 0x004f
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_08592BF4:: @ 8592BF4
	.4byte gUnknown_08592BAC
	.4byte gUnknown_08592BD0

	.align 2
gUnknown_08592BFC:: @ 8592BFC
	spr_template ANIM_TAG_UNUSED_BUBBLE_BURST, ANIM_TAG_UNUSED_BUBBLE_BURST, gUnknown_0852490C, gUnknown_08592BF4, NULL, gDummySpriteAffineAnimTable, sub_8101440

	.align 2
gUnknown_08592C14:: @ 8592C14
	.2byte 0x0000, 0x0028, 0xffff, 0x0000

	.align 2
gUnknown_08592C1C:: @ 8592C1C
	.4byte gUnknown_08592C14

	.align 2
gUnknown_08592C20:: @ 8592C20
	.2byte 0x0014, 0x0014, 0x00e2, 0x0000, 0x0008, 0x0008, 0x1801, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000, 0x7ffd, 0x0000, 0x0000, 0x0000
	.2byte 0x0000, 0x0000, 0x1801, 0x0000, 0x7ffd, 0x000a, 0x0000, 0x0000

	.align 2
gUnknown_08592C50:: @ 8592C50
	.2byte 0x0014, 0x0014, 0x001e, 0x0000, 0x0008, 0x0008, 0x18ff, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000, 0x7ffd, 0x0000, 0x0000, 0x0000
	.2byte 0x0000, 0x0000, 0x18ff, 0x0000, 0x7ffd, 0x000a, 0x0000, 0x0000

	.align 2
gUnknown_08592C80:: @ 8592C80
	.4byte gUnknown_08592C20
	.4byte gUnknown_08592C50

	.align 2
gUnknown_08592C88:: @ 8592C88
	spr_template ANIM_TAG_LETTER_Z, ANIM_TAG_LETTER_Z, gUnknown_08524974, gUnknown_08592C1C, NULL, gUnknown_08592C80, sub_81014F4

	.align 2
gUnknown_08592CA0:: @ 8592CA0
	spr_template ANIM_TAG_LOCK_ON, ANIM_TAG_LOCK_ON, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81015AC

	.align 2
gUnknown_08592CB8:: @ 8592CB8
	spr_template ANIM_TAG_LOCK_ON, ANIM_TAG_LOCK_ON, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8101898

	.align 2
gUnknown_08592CD0:: @ 8592CD0
	.byte 0x40, 0x40, 0x00, 0xc0, 0xc0, 0x40, 0x20, 0xe0

	.align 2
gUnknown_08592CD8:: @ 8592CD8
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8101940

	.align 2
gUnknown_08592CF0:: @ 8592CF0
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8101B90

	.align 2
gUnknown_08592D08:: @ 8592D08
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08592D1C:: @ 8592D1C
	.2byte 0x0030, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08592D24:: @ 8592D24
	.4byte gUnknown_08592D08
	.4byte gUnknown_08592D1C

	.align 2
gUnknown_08592D2C:: @ 8592D2C
	spr_template ANIM_TAG_SLASH, ANIM_TAG_SLASH, gUnknown_08524914, gUnknown_08592D24, NULL, gDummySpriteAffineAnimTable, sub_8101F40

	.align 2
gUnknown_08592D44:: @ 8592D44
	spr_template ANIM_TAG_SLASH_2, ANIM_TAG_SLASH_2, gUnknown_08524914, gUnknown_08592D24, NULL, gDummySpriteAffineAnimTable, sub_8101FA8

	.align 2
gUnknown_08592D5C:: @ 8592D5C
	spr_template ANIM_TAG_SLASH_2, ANIM_TAG_SLASH_2, gUnknown_08524914, gUnknown_08592D24, NULL, gDummySpriteAffineAnimTable, sub_8101FF0

	.align 2
gUnknown_08592D74:: @ 8592D74
	.2byte 0x0000, 0x0004, 0x0008, 0x000c, 0x0010, 0x0004, 0x0018, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08592D88:: @ 8592D88
	.4byte gUnknown_08592D74

	.align 2
gUnknown_08592D8C:: @ 8592D8C
	spr_template ANIM_TAG_FOCUS_ENERGY, ANIM_TAG_FOCUS_ENERGY, gUnknown_08524954, gUnknown_08592D88, NULL, gDummySpriteAffineAnimTable, sub_81020D8

	.align 2
gUnknown_08592DA4:: @ 8592DA4
	.2byte 0x0000, 0x0012, 0x0000, 0x0006, 0x0010, 0x0012, 0x0000, 0x0006
	.2byte 0x0010, 0x0006, 0x0020, 0x0012, 0x0010, 0x0006, 0x0020, 0x0006
	.2byte 0x0030, 0x0012, 0x0020, 0x0006, 0x0030, 0x0006, 0x0040, 0x0012
	.2byte 0x0030, 0x0006, 0x0040, 0x0036, 0xffff, 0x0000

	.align 2
gUnknown_08592DE0:: @ 8592DE0
	.4byte gUnknown_08592DA4

	.align 2
gUnknown_08592DE4:: @ 8592DE4
	spr_template ANIM_TAG_SPHERE_TO_CUBE, ANIM_TAG_SPHERE_TO_CUBE, gUnknown_08524914, gUnknown_08592DE0, NULL, gDummySpriteAffineAnimTable, sub_810217C

	.align 2
gUnknown_08592DFC:: @ 8592DFC
	spr_template ANIM_TAG_BLACK_BALL, ANIM_TAG_BLACK_BALL, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TranslateAnimSpriteToTargetMonLocation

	.align 2
gUnknown_08592E14:: @ 8592E14
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_08592E2C:: @ 8592E2C
	.4byte gUnknown_08592E14

	.align 2
gUnknown_08592E30:: @ 8592E30
	spr_template ANIM_TAG_GRAY_SMOKE, ANIM_TAG_GRAY_SMOKE, gUnknown_08524914, gUnknown_08592E2C, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_08592E48:: @ 8592E48
	.2byte 0x0003, 0x0005, 0x0002, 0x0005, 0x0001, 0x0005, 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08592E5C:: @ 8592E5C
	.4byte gUnknown_08592E48

	.align 2
gUnknown_08592E60:: @ 8592E60
	.2byte 0x0200, 0x0200, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08592E70:: @ 8592E70
	.4byte gUnknown_08592E60

	.align 2
gUnknown_08592E74:: @ 8592E74
	spr_template ANIM_TAG_CONVERSION, ANIM_TAG_CONVERSION, gUnknown_08524AE4, gUnknown_08592E5C, NULL, gUnknown_08592E70, sub_8102268

	.align 2
gUnknown_08592E8C:: @ 8592E8C
	.2byte 0x0000, 0x0005, 0x0001, 0x0005, 0x0002, 0x0005, 0x0003, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08592EA0:: @ 8592EA0
	.4byte gUnknown_08592E8C

	.align 2
gUnknown_08592EA4:: @ 8592EA4
	spr_template ANIM_TAG_CONVERSION, ANIM_TAG_CONVERSION, gUnknown_08524AE4, gUnknown_08592EA0, NULL, gUnknown_08592E70, sub_810234C

	.align 2
gUnknown_08592EBC:: @ 8592EBC
	spr_template ANIM_TAG_MOON, ANIM_TAG_MOON, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81024E0

	.align 2
gUnknown_08592ED4:: @ 8592ED4
	.2byte 0x0000, 0x0008, 0x0004, 0x0008, 0x0008, 0x0008, 0x000c, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_08592EE8:: @ 8592EE8
	.4byte gUnknown_08592ED4

	.align 2
gBattleAnimSpriteTemplate_8592EEC:: @ 8592EEC
	spr_template ANIM_TAG_GREEN_SPARKLE, ANIM_TAG_GREEN_SPARKLE, gUnknown_0852490C, gUnknown_08592EE8, NULL, gDummySpriteAffineAnimTable, sub_8102540

	.align 2
gUnknown_08592F04:: @ 8592F04
	.2byte 0x0000, 0x0002, 0x0010, 0x0002, 0x0020, 0x0002, 0x0030, 0x0003
	.2byte 0x0040, 0x0005, 0x0050, 0x0003, 0x0060, 0x0002, 0x0000, 0x0002
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_08592F28:: @ 8592F28
	.4byte gUnknown_08592F04

	.align 2
gUnknown_08592F2C:: @ 8592F2C
	spr_template ANIM_TAG_BLUE_STAR, ANIM_TAG_BLUE_STAR, gUnknown_08524914, gUnknown_08592F28, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_08592F44:: @ 8592F44
	spr_template ANIM_TAG_HORN_HIT, ANIM_TAG_HORN_HIT, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8102844

	.align 2
gUnknown_08592F5C:: @ 8592F5C
	.2byte 0x0000, 0x0002, 0x0010, 0x0002, 0x0020, 0x0002, 0x0030, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_08592F70:: @ 8592F70
	.4byte gUnknown_08592F5C

	.align 2
gUnknown_08592F74:: @ 8592F74
	spr_template ANIM_TAG_FANG_ATTACK, ANIM_TAG_FANG_ATTACK, gUnknown_08524914, gUnknown_08592F70, NULL, gDummySpriteAffineAnimTable, sub_8102BCC

	.align 2
gUnknown_08592F8C:: @ 8592F8C
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_08592F94:: @ 8592F94
	.2byte 0x0004, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_08592F9C:: @ 8592F9C
	.2byte 0x0008, 0x0029, 0xffff, 0x0000

	.align 2
gUnknown_08592FA4:: @ 8592FA4
	.2byte 0x000c, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_08592FAC:: @ 8592FAC
	.2byte 0x0010, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_08592FB4:: @ 8592FB4
	.2byte 0x0014, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_08592FBC:: @ 8592FBC
	.2byte 0x0000, 0x008a, 0xffff, 0x0000

	.align 2
gUnknown_08592FC4:: @ 8592FC4
	.2byte 0x0004, 0x008a, 0xffff, 0x0000

	.align 2
gUnknown_08592FCC:: @ 8592FCC
	.4byte gUnknown_08592F8C
	.4byte gUnknown_08592F94
	.4byte gUnknown_08592F9C
	.4byte gUnknown_08592FA4
	.4byte gUnknown_08592FAC
	.4byte gUnknown_08592FB4
	.4byte gUnknown_08592FBC
	.4byte gUnknown_08592FC4

	.align 2
gUnknown_08592FEC:: @ 8592FEC
	.2byte 0x000c, 0x000c, 0x1000, 0x0000, 0xfff4, 0xfff4, 0x1000, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593004:: @ 8593004
	.4byte gUnknown_08592FEC

	.align 2
gUnknown_08593008:: @ 8593008
	spr_template ANIM_TAG_MUSIC_NOTES, ANIM_TAG_MUSIC_NOTES, gUnknown_085249CC, gUnknown_08592FCC, NULL, gUnknown_08593004, sub_8102CD4

	.align 2
gUnknown_08593020:: @ 8593020
	.2byte 0x2758, 0x7fff, 0x735f, 0x6adf, 0x623f, 0x59bf, 0x2771, 0x7fff
	.2byte 0x6bf9, 0x57f4, 0x43ef, 0x33ea, 0x27c9, 0x7fff, 0x63ff, 0x47ff
	.2byte 0x2bff, 0x0fff, 0x27bf, 0x7fff, 0x7f9a, 0x7f55, 0x7f10, 0x7ecc

	.align 2
gUnknown_08593050:: @ 8593050
	spr_template ANIM_TAG_MUSIC_NOTES, ANIM_TAG_MUSIC_NOTES, gUnknown_085249CC, gUnknown_08592FCC, NULL, gUnknown_08593004, sub_8102EB0

	.align 2
gUnknown_08593068:: @ 8593068
	spr_template ANIM_TAG_PURPLE_HAND_OUTLINE, ANIM_TAG_PURPLE_HAND_OUTLINE, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8102FB8

	.align 2
gUnknown_08593080:: @ 8593080
	.2byte 0x00a0, 0x00a0, 0x0000, 0x0000, 0x0004, 0x0004, 0x0100, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08593098:: @ 8593098
	.4byte gUnknown_08593080

	.align 2
gUnknown_0859309C:: @ 859309C
	spr_template ANIM_TAG_MUSIC_NOTES, ANIM_TAG_MUSIC_NOTES, gUnknown_085249CC, gUnknown_08592FCC, NULL, gUnknown_08593098, sub_8103028

	.align 2
gUnknown_085930B4:: @ 85930B4
	.2byte 0x0000, 0x0042, 0x0010, 0x0042, 0x0020, 0x0042, 0x0030, 0x0042, 0xffff, 0x0000

	.align 2
gUnknown_085930C8:: @ 85930C8
	.2byte 0x0030, 0x0042, 0x0020, 0x0042, 0x0010, 0x0042, 0x0000, 0x0042, 0xffff, 0x0000

	.align 2
gUnknown_085930DC:: @ 85930DC
	.2byte 0x0000, 0x0002, 0x0010, 0x0002, 0x0020, 0x0002, 0x0030, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_085930F0:: @ 85930F0
	.2byte 0x0030, 0x0002, 0x0020, 0x0002, 0x0010, 0x0002, 0x0000, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_08593104:: @ 8593104
	.4byte gUnknown_085930B4
	.4byte gUnknown_085930DC
	.4byte gUnknown_085930C8
	.4byte gUnknown_085930F0

	.align 2
gUnknown_08593114:: @ 8593114
	spr_template ANIM_TAG_THOUGHT_BUBBLE, ANIM_TAG_THOUGHT_BUBBLE, gUnknown_08524914, gUnknown_08593104, NULL, gDummySpriteAffineAnimTable, sub_8103164

	.align 2
gUnknown_0859312C:: @ 859312C
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x001e, 0x001e, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593144:: @ 8593144
	.2byte 0x0000, 0x0000, 0x0b04, 0x0000, 0x0000, 0x0000, 0x0bfc, 0x0000
	.2byte 0x7ffd, 0x0002, 0x0000, 0x0000, 0xffe2, 0xffe2, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000, 0x0010, 0x0010, 0x0000, 0x0000
	.2byte 0x001e, 0x001e, 0x0800, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000
	.2byte 0x7ffd, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0b04, 0x0000
	.2byte 0x0000, 0x0000, 0x0bfc, 0x0000, 0x7ffd, 0x0002, 0x0000, 0x0000
	.2byte 0xffe2, 0xffe2, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085931B4:: @ 85931B4
	.4byte gUnknown_0859312C
	.4byte gUnknown_08593144

	.align 2
gUnknown_085931BC:: @ 85931BC
	spr_template ANIM_TAG_FINGER, ANIM_TAG_FINGER, gUnknown_085249D4, gDummySpriteAnimTable, NULL, gUnknown_085931B4, sub_8103208

	.align 2
gUnknown_085931D4:: @ 85931D4
	spr_template ANIM_TAG_FINGER, ANIM_TAG_FINGER, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_085931B4, sub_8103284

	.align 2
gUnknown_085931EC:: @ 85931EC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085931F4:: @ 85931F4
	.2byte 0x0000, 0x0041, 0xffff, 0x0000

	.align 2
gUnknown_085931FC:: @ 85931FC
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0010, 0x0004
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_0859321C:: @ 859321C
	.2byte 0x0000, 0x0044, 0x0010, 0x0044, 0x0020, 0x0044, 0x0010, 0x0044
	.2byte 0x0000, 0x0044, 0x0010, 0x0044, 0x0020, 0x0044, 0xffff, 0x0000

	.align 2
gUnknown_0859323C:: @ 859323C
	.4byte gUnknown_085931EC
	.4byte gUnknown_085931F4
	.4byte gUnknown_085931FC
	.4byte gUnknown_0859321C

	.align 2
gUnknown_0859324C:: @ 859324C
	spr_template ANIM_TAG_FINGER_2, ANIM_TAG_FINGER_2, gUnknown_08524914, gUnknown_0859323C, NULL, gDummySpriteAffineAnimTable, sub_8103390

// BREAK ^effects_1

	.align 2
gUnknown_08593264:: @ 8593264
	spr_template ANIM_TAG_FINGER, ANIM_TAG_FINGER, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8103448

	.align 2
gUnknown_0859327C:: @ 859327C
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08593284:: @ 8593284
	.4byte gUnknown_0859327C

	.align 2
gUnknown_08593288:: @ 8593288
	spr_template ANIM_TAG_MUSIC_NOTES, ANIM_TAG_MUSIC_NOTES, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8103498

	.align 2
gUnknown_085932A0:: @ 85932A0
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810358C

	.align 2
gUnknown_085932B8:: @ 85932B8
	spr_template ANIM_TAG_CLAMP, ANIM_TAG_CLAMP, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08597060, sub_8103620

	.align 2
gUnknown_085932D0:: @ 85932D0
	.2byte 0x0000, 0x0009, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085932E4:: @ 85932E4
	.4byte gUnknown_085932D0

	.align 2
gUnknown_085932E8:: @ 85932E8
	.2byte 0x0050, 0x0050, 0x0000, 0x0000, 0x0009, 0x0009, 0x1200, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593300:: @ 8593300
	.4byte gUnknown_085932E8

	.align 2
gUnknown_08593304:: @ 8593304
	spr_template ANIM_TAG_UNUSED_EXPLOSION, ANIM_TAG_UNUSED_EXPLOSION, gUnknown_08524974, gUnknown_085932E4, NULL, gUnknown_08593300, sub_80A77C8

	.align 2
gUnknown_0859331C:: @ 859331C
	.2byte 0x0000, 0x0043, 0x0008, 0x0043, 0x0010, 0x0043, 0x0018, 0x0043
	.2byte 0x0020, 0x0043, 0x0028, 0x0043, 0x0030, 0x0043, 0xfffd, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_08593340:: @ 8593340
	.4byte gUnknown_0859331C

	.align 2
gUnknown_08593344:: @ 8593344
	spr_template ANIM_TAG_ALERT, ANIM_TAG_ALERT, gUnknown_08524934, gUnknown_08593340, NULL, gDummySpriteAffineAnimTable, sub_81037D8

	.align 2
gUnknown_0859335C:: @ 859335C
	.2byte 0x0010, 0x0100, 0x0000, 0x0000, 0x0014, 0x0000, 0x0c00, 0x0000
	.2byte 0x0000, 0x0000, 0x2000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859337C:: @ 859337C
	.4byte gUnknown_0859335C

	.align 2
gBattleAnimSpriteTemplate_8593380:: @ 8593380
	spr_template ANIM_TAG_SWORD, ANIM_TAG_SWORD, gUnknown_08524ADC, gDummySpriteAnimTable, NULL, gUnknown_0859337C, sub_810387C

	.align 2
gSonicBoomSpriteTemplate:: @ 8593398
	spr_template ANIM_TAG_AIR_WAVE, ANIM_TAG_AIR_WAVE, gUnknown_08524B14, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81038C8

	.align 2
gUnknown_085933B0:: @ 85933B0
	spr_template ANIM_TAG_AIR_WAVE, ANIM_TAG_AIR_WAVE, gUnknown_08524A54, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8103AA4

	.align 2
gUnknown_085933C8:: @ 85933C8
	.2byte 0x0020, 0x0020, 0x0000, 0x0000, 0x0007, 0x0007, 0xc800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085933E0:: @ 85933E0
	.2byte 0x0005, 0x0005, 0x0a00, 0x0000, 0xfff6, 0xfff6, 0x0a00, 0x0000
	.2byte 0x000a, 0x000a, 0x0a00, 0x0000, 0xfff6, 0xfff6, 0x0a00, 0x0000
	.2byte 0x000a, 0x000a, 0x0a00, 0x0000, 0xfff6, 0xfff6, 0x0a00, 0x0000
	.2byte 0x000a, 0x000a, 0x0a00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593420:: @ 8593420
	.4byte gUnknown_085933C8

	.align 2
gUnknown_08593424:: @ 8593424
	.4byte gUnknown_085933E0

	.align 2
gSupersonicWaveSpriteTemplate:: @ 8593428
	spr_template ANIM_TAG_GOLD_RING, ANIM_TAG_GOLD_RING, gUnknown_08524A14, gDummySpriteAnimTable, NULL, gUnknown_08593420, TranslateAnimSpriteToTargetMonLocation

	.align 2
gScreechWaveSpriteTemplate:: @ 8593440
	spr_template ANIM_TAG_PURPLE_RING, ANIM_TAG_PURPLE_RING, gUnknown_08524A14, gDummySpriteAnimTable, NULL, gUnknown_08593420, TranslateAnimSpriteToTargetMonLocation

	.align 2
gUnknown_08593458:: @ 8593458
	spr_template ANIM_TAG_METAL_SOUND_WAVES, ANIM_TAG_METAL_SOUND_WAVES, gUnknown_08524A1C, gDummySpriteAnimTable, NULL, gUnknown_08593420, TranslateAnimSpriteToTargetMonLocation

	.align 2
gUnknown_08593470:: @ 8593470
	spr_template ANIM_TAG_BLUE_RING_2, ANIM_TAG_BLUE_RING_2, gUnknown_08524A14, gDummySpriteAnimTable, NULL, gUnknown_08593424, sub_8108C94

@ BREAK ^ water

	.align 2
gUnknown_08593488:: @ 8593488
	spr_template ANIM_TAG_LARGE_FRESH_EGG, ANIM_TAG_LARGE_FRESH_EGG, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80A78AC

	.align 2
gUnknown_085934A0:: @ 85934A0
	spr_template ANIM_TAG_UNUSED_VOID_LINES, ANIM_TAG_UNUSED_VOID_LINES, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8103FE8

	.align 2
gUnknown_085934B8:: @ 85934B8
	.2byte 0x0008, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085934C0:: @ 85934C0
	.4byte gUnknown_085934B8

	.align 2
gUnknown_085934C4:: @ 85934C4
	.2byte 0x0000, 0x0000, 0x010a, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085934D4:: @ 85934D4
	.4byte gUnknown_085934C4

	.align 2
gUnknown_085934D8:: @ 85934D8
	spr_template ANIM_TAG_COIN, ANIM_TAG_COIN, gUnknown_0852496C, gUnknown_085934C0, NULL, gDummySpriteAffineAnimTable, sub_8104088

	.align 2
gUnknown_085934F0:: @ 85934F0
	spr_template ANIM_TAG_COIN, ANIM_TAG_COIN, gUnknown_0852496C, gUnknown_085934C0, NULL, gUnknown_085934D4, sub_810413C

	.align 2
gUnknown_08593508:: @ 8593508
	.2byte 0x0000, 0x0000, 0x0114, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593518:: @ 8593518
	.4byte gUnknown_08593508

	.align 2
gUnknown_0859351C:: @ 859351C
	spr_template ANIM_TAG_SEED, ANIM_TAG_SEED, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08593518, sub_81041C4

	.align 2
gUnknown_08593534:: @ 8593534
	.2byte 0x0010, 0x0100, 0x0000, 0x0000, 0x0004, 0x0000, 0x2800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859354C:: @ 859354C
	.4byte gUnknown_08593534

	.align 2
gUnknown_08593550:: @ 8593550
	spr_template ANIM_TAG_GUST, ANIM_TAG_GUST, gUnknown_085249BC, gDummySpriteAnimTable, NULL, gUnknown_0859354C, sub_8104304

	.align 2
gUnknown_08593568:: @ 8593568
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0014, 0xffff, 0x0000

	.align 2
gUnknown_08593578:: @ 8593578
	.2byte 0x0000, 0x00c3, 0x0010, 0x00c3, 0x0020, 0x00d4, 0xffff, 0x0000

	.align 2
gUnknown_08593588:: @ 8593588
	.4byte gUnknown_08593568
	.4byte gUnknown_08593578

	.align 2
gUnknown_08593590:: @ 8593590
	spr_template ANIM_TAG_CUT, ANIM_TAG_CUT, gUnknown_08524A34, gUnknown_08593588, NULL, gDummySpriteAffineAnimTable, sub_8104364

	.align 2
gUnknown_085935A8:: @ 85935A8
	.2byte 0x0000, 0x0002, 0x0010, 0x0002, 0x0020, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085935B8:: @ 85935B8
	.2byte 0x0000, 0x00c2, 0x0010, 0x00c2, 0x0020, 0x00c1, 0xffff, 0x0000

	.align 2
gUnknown_085935C8:: @ 85935C8
	.4byte gUnknown_085935A8
	.4byte gUnknown_085935B8

	.align 2
gUnknown_085935D0:: @ 85935D0
	spr_template ANIM_TAG_CUT, ANIM_TAG_CUT, gUnknown_08524A34, gUnknown_085935C8, NULL, gDummySpriteAffineAnimTable, sub_8104414

	.align 2
gUnknown_085935E8:: @ 85935E8
	.2byte 0xfffa, 0x0004, 0x0800, 0x0000, 0x000a, 0xfff6, 0x0800, 0x0000
	.2byte 0xfffc, 0x0006, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593608:: @ 8593608
	.2byte 0xfffc, 0xfffb, 0x0c00, 0x0000, 0x0000, 0x0000, 0x1800, 0x0000
	.2byte 0x0004, 0x0005, 0x0c00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593628:: @ 8593628
	.2byte 0x0000, 0x0044, 0x0004, 0x0068, 0x0008, 0x0044, 0x000c, 0x0044, 0xffff, 0x0000

	.align 2
gUnknown_0859363C:: @ 859363C
	.2byte 0x0000, 0x0004, 0x0004, 0x0028, 0x0008, 0x0004, 0x000c, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08593650:: @ 8593650
	.4byte gUnknown_08593628
	.4byte gUnknown_0859363C

	.align 2
gUnknown_08593658:: @ 8593658
	spr_template ANIM_TAG_BREATH, ANIM_TAG_BREATH, gUnknown_0852490C, gUnknown_08593650, NULL, gDummySpriteAffineAnimTable, sub_8104B1C

	.align 2
gUnknown_08593670:: @ 8593670
	.2byte 0x000b, 0x000b, 0x0800, 0x0000, 0xfff5, 0xfff5, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593688:: @ 8593688
	.4byte gUnknown_08593670

	.align 2
gUnknown_0859368C:: @ 859368C
	spr_template ANIM_TAG_ANGER, ANIM_TAG_ANGER, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08593688, sub_8104BAC

	.align 2
gUnknown_085936A4:: @ 85936A4
	.2byte 0xfff6, 0x0009, 0x0700, 0x0000, 0x0014, 0xffec, 0x0700, 0x0000
	.2byte 0xffec, 0x0014, 0x0700, 0x0000, 0x000a, 0xfff7, 0x0700, 0x0000
	.2byte 0x7ffd, 0x0002, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085936D4:: @ 85936D4
	spr_template ANIM_TAG_PENCIL, ANIM_TAG_PENCIL, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810501C

	.align 2
gUnknown_085936EC:: @ 85936EC
	spr_template ANIM_TAG_SNORE_Z, ANIM_TAG_SNORE_Z, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80A7938

	.align 2
gUnknown_08593704:: @ 8593704
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0030, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08593718:: @ 8593718
	.4byte gUnknown_08593704

	.align 2
gBattleAnimSpriteTemplate_859371C:: @ 859371C
	spr_template ANIM_TAG_EXPLOSION, ANIM_TAG_EXPLOSION, gUnknown_08524914, gUnknown_08593718, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_08593734:: @ 8593734
	.2byte 0x0000, 0x0000, 0x02f8, 0x0000, 0x0000, 0x0000, 0x0408, 0x0000
	.2byte 0x0000, 0x0000, 0x02f8, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593754:: @ 8593754
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593764:: @ 8593764
	.2byte 0xfff8, 0x0004, 0x0800, 0x0000, 0x7ffd, 0x0000, 0x0000, 0x0000
	.2byte 0x0010, 0xfff8, 0x0800, 0x0000, 0xfff0, 0x0008, 0x0800, 0x0000
	.2byte 0x7ffd, 0x0001, 0x0000, 0x0000, 0x0100, 0x0100, 0x0000, 0x0000
	.2byte 0x0000, 0x0000, 0x0f00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085937A4:: @ 85937A4
	.4byte gUnknown_08593734
	.4byte gUnknown_08593754
	.4byte gUnknown_08593764

	.align 2
gUnknown_085937B0:: @ 85937B0
	spr_template ANIM_TAG_BREAKING_EGG, ANIM_TAG_BREAKING_EGG, gUnknown_08524AF4, gDummySpriteAnimTable, NULL, gUnknown_085937A4, sub_8105538

	.align 2
gUnknown_085937C8:: @ 85937C8
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0010, 0x0010, 0x1e00, 0x0000
	.2byte 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085937E0:: @ 85937E0
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0020, 0x0020, 0x0f00, 0x0000
	.2byte 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085937F8:: @ 85937F8
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x000b, 0x000b, 0x2d00, 0x0000
	.2byte 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08593810:: @ 8593810
	.4byte gUnknown_085937C8
	.4byte gUnknown_085937E0

	.align 2
gUnknown_08593818:: @ 8593818
	.4byte gUnknown_085937F8

	.align 2
gUnknown_0859381C:: @ 859381C
	spr_template ANIM_TAG_THIN_RING, ANIM_TAG_THIN_RING, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_08593810, sub_80A77C8

	.align 2
gUnknown_08593834:: @ 8593834
	.2byte 0x0200, 0x0200, 0x0000, 0x0000, 0xfff0, 0xfff0, 0x1e00, 0x0000
	.2byte 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_0859384C:: @ 859384C
	.4byte gUnknown_08593834

	.align 2
gUnknown_08593850:: @ 8593850
	spr_template ANIM_TAG_THIN_RING, ANIM_TAG_THIN_RING, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_0859384C, sub_80A77C8

	.align 2
gUnknown_08593868:: @ 8593868
	spr_template ANIM_TAG_THIN_RING, ANIM_TAG_THIN_RING, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08593810, sub_81051C4

	.align 2
gUnknown_08593880:: @ 8593880
	spr_template ANIM_TAG_THIN_RING, ANIM_TAG_THIN_RING, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08593818, sub_81052A4

	.align 2
gBattleAnimSpriteTemplate_8593898:: @ 8593898
	spr_template ANIM_TAG_THIN_RING, ANIM_TAG_THIN_RING, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08593810, sub_81054E8

	.align 2
gUnknown_085938B0:: @ 85938B0
	.2byte 0x0060, 0xfff3, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085938C0:: @ 85938C0
	.2byte 0x0000, 0x0003, 0x0004, 0x0003, 0x0008, 0x0003, 0x0004, 0x0003
	.2byte 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085938D8:: @ 85938D8
	.4byte gUnknown_085938C0

	.align 2
gUnknown_085938DC:: @ 85938DC
	spr_template ANIM_TAG_SPEED_DUST, ANIM_TAG_SPEED_DUST, gUnknown_0852490C, gUnknown_085938D8, NULL, gDummySpriteAffineAnimTable, sub_8105C48

	.align 2
gUnknown_085938F4:: @ 85938F4
	.2byte 0x1c1e, 0x18ec, 0x1a10, 0x1cf6

	.align 2
gUnknown_085938FC:: @ 85938FC
	.2byte 0x0000, 0x0006, 0x0010, 0x0006, 0x0020, 0x000f, 0x0010, 0x0006
	.2byte 0x0000, 0x0006, 0x0010, 0x0046, 0x0020, 0x004f, 0x0010, 0x0046
	.2byte 0x0000, 0x0006, 0x0010, 0x0006, 0x0020, 0x000f, 0x0010, 0x0006
	.2byte 0x0000, 0x0006, 0xffff, 0x0000

	.align 2
gUnknown_08593934:: @ 8593934
	.4byte gUnknown_085938FC

	.align 2
gUnknown_08593938:: @ 8593938
	spr_template ANIM_TAG_BELL, ANIM_TAG_BELL, gUnknown_08524914, gUnknown_08593934, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_08593950:: @ 8593950
	.2byte 0x27de, 0x270f, 0x270e, 0x0000

	.align 2
gUnknown_08593958:: @ 8593958
	spr_template ANIM_TAG_MUSIC_NOTES_2, ANIM_TAG_MUSIC_NOTES_2, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8105DE8

	.align 2
gUnknown_08593970:: @ 8593970
	spr_template ANIM_TAG_MAGENTA_HEART, ANIM_TAG_MAGENTA_HEART, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8105E60

	.align 2
gUnknown_08593988:: @ 8593988
	.2byte 0x000a, 0xfff3, 0x0a00, 0x0000, 0xfff6, 0x000d, 0x0a00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085939A0:: @ 85939A0
	spr_template ANIM_TAG_RED_HEART, ANIM_TAG_RED_HEART, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8106140

	.align 2
gBattleAnimSpriteTemplate_85939B8:: @ 85939B8
	spr_template ANIM_TAG_RED_HEART, ANIM_TAG_RED_HEART, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81061C4

	.align 2
gUnknown_085939D0:: @ 85939D0
	spr_template ANIM_TAG_RED_HEART, ANIM_TAG_RED_HEART, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810624C

	.align 2
gUnknown_085939E8:: @ 85939E8
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x0008, 0x0008, 0x0100, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08593A00:: @ 8593A00
	.4byte gUnknown_085939E8

	.align 2
gHiddenPowerOrbSpriteTemplate:: @ 8593A04
	spr_template ANIM_TAG_RED_ORB, ANIM_TAG_RED_ORB, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08593A00, sub_810673C

	.align 2
gHiddenPowerOrbScatterSpriteTemplate:: @ 8593A1C
	spr_template ANIM_TAG_RED_ORB, ANIM_TAG_RED_ORB, gUnknown_085249CC, gDummySpriteAnimTable, NULL, gUnknown_08593A00, sub_8106878

	.align 2
gUnknown_08593A34:: @ 8593A34
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x0008, 0x0008, 0x0100, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08593A4C:: @ 8593A4C
	.4byte gUnknown_08593A34

	.align 2
gUnknown_08593A50:: @ 8593A50
	spr_template ANIM_TAG_RED_ORB_2, ANIM_TAG_RED_ORB_2, gUnknown_085249C4, gDummySpriteAnimTable, NULL, gUnknown_08593A4C, sub_8106944

	.align 2
gUnknown_08593A68:: @ 8593A68
	.2byte 0x0000, 0x0004, 0x0004, 0x0004, 0x0008, 0x0004, 0x0004, 0x0004
	.2byte 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08593A80:: @ 8593A80
	.4byte gUnknown_08593A68

	.align 2
gUnknown_08593A84:: @ 8593A84
	spr_template ANIM_TAG_EYE_SPARKLE, ANIM_TAG_EYE_SPARKLE, gUnknown_0852490C, gUnknown_08593A80, NULL, gDummySpriteAffineAnimTable, sub_81069B8

	.align 2
gUnknown_08593A9C:: @ 8593A9C
	.2byte 0x0000, 0x0018, 0xffff, 0x0000

	.align 2
gUnknown_08593AA4:: @ 8593AA4
	.4byte gUnknown_08593A9C

	.align 2
gUnknown_08593AA8:: @ 8593AA8
	spr_template ANIM_TAG_ANGEL, ANIM_TAG_ANGEL, gUnknown_08524914, gUnknown_08593AA4, NULL, gDummySpriteAffineAnimTable, sub_81069D0

	.align 2
gUnknown_08593AC0:: @ 8593AC0
	spr_template ANIM_TAG_PINK_HEART, ANIM_TAG_PINK_HEART, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8106AD0

	.align 2
gUnknown_08593AD8:: @ 8593AD8
	.2byte 0x0000, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_08593AE0:: @ 8593AE0
	.2byte 0x0010, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_08593AE8:: @ 8593AE8
	.4byte gUnknown_08593AD8
	.4byte gUnknown_08593AE0

	.align 2
gUnknown_08593AF0:: @ 8593AF0
	spr_template ANIM_TAG_DEVIL, ANIM_TAG_DEVIL, gUnknown_08524914, gUnknown_08593AE8, NULL, gDummySpriteAffineAnimTable, sub_8106B54

	.align 2
gUnknown_08593B08:: @ 8593B08
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08593B1C:: @ 8593B1C
	.2byte 0x0000, 0x0044, 0x0010, 0x0044, 0x0020, 0x0044, 0x0030, 0x0044, 0xffff, 0x0000

	.align 2
gUnknown_08593B30:: @ 8593B30
	.4byte gUnknown_08593B08
	.4byte gUnknown_08593B1C

	.align 2
gUnknown_08593B38:: @ 8593B38
	spr_template ANIM_TAG_SWIPE, ANIM_TAG_SWIPE, gUnknown_08524914, gUnknown_08593B30, NULL, gDummySpriteAffineAnimTable, sub_8106C80

	.align 2
gUnknown_08593B50:: @ 8593B50
	.2byte 0x0000, 0x0008, 0x0010, 0x0008, 0x0020, 0x0008, 0x0010, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_08593B64:: @ 8593B64
	.2byte 0x0010, 0x0048, 0x0020, 0x0048, 0x0010, 0x0048, 0x0000, 0x0048, 0xffff, 0x0000

	.align 2
gUnknown_08593B78:: @ 8593B78
	.4byte gUnknown_08593B50
	.4byte gUnknown_08593B64

	.align 2
gUnknown_08593B80:: @ 8593B80
	spr_template ANIM_TAG_MOVEMENT_WAVES, ANIM_TAG_MOVEMENT_WAVES, gUnknown_08524914, gUnknown_08593B78, NULL, gDummySpriteAffineAnimTable, sub_8106CD0

	.align 2
gUnknown_08593B98:: @ 8593B98
	.2byte 0xfff4, 0x0008, 0x0400, 0x0000, 0x0014, 0xffec, 0x0400, 0x0000
	.2byte 0xfff8, 0x000c, 0x0400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gBattleAnimSpriteTemplate_8593BB8:: @ 8593BB8
	spr_template ANIM_TAG_JAGGED_MUSIC_NOTE, ANIM_TAG_JAGGED_MUSIC_NOTE, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8106E00

	.align 2
gUnknown_08593BD0:: @ 8593BD0
	.2byte 0x0000, 0x0000, 0x0500, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593BE0:: @ 8593BE0
	.2byte 0x0000, 0x0000, 0x10f8, 0x0000, 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08593BF0:: @ 8593BF0
	.2byte 0x0000, 0x0000, 0x1008, 0x0000, 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08593C00:: @ 8593C00
	.4byte gUnknown_08593BD0
	.4byte gUnknown_08593BE0
	.4byte gUnknown_08593BF0

	.align 2
gUnknown_08593C0C:: @ 8593C0C
	spr_template ANIM_TAG_MUSIC_NOTES_2, ANIM_TAG_MUSIC_NOTES_2, gUnknown_0852496C, gUnknown_08592FCC, NULL, gUnknown_08593C00, sub_8106F60

	.align 2
gUnknown_08593C24:: @ 8593C24
	spr_template ANIM_TAG_MUSIC_NOTES_2, ANIM_TAG_MUSIC_NOTES_2, gUnknown_0852496C, gUnknown_08592FCC, NULL, gUnknown_08593C00, sub_8106F00

	.align 2
gUnknown_08593C3C:: @ 8593C3C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593C4C:: @ 8593C4C
	.2byte 0x0200, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08593C5C:: @ 8593C5C
	.4byte gUnknown_08593C3C
	.4byte gUnknown_08593C4C

	.align 2
gUnknown_08593C64:: @ 8593C64
	spr_template ANIM_TAG_GUARD_RING, ANIM_TAG_GUARD_RING, gUnknown_08524B1C, gDummySpriteAnimTable, NULL, gUnknown_08593C5C, sub_81070AC

	.align 2
	.incbin "graphics/unknown/unknown_593C80.4bpp"

	.align 2
	.incbin "graphics/unknown/unknown_593FFC.bin"

	.align 2
gUnknown_08594FFC:: @ 8594FFC
	.2byte 0x0000, 0x0002, 0x0008, 0x0002, 0x0010, 0x0002, 0x0018, 0x0006
	.2byte 0x0020, 0x0002, 0x0028, 0x0002, 0x0030, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_0859501C:: @ 859501C
	.4byte gUnknown_08594FFC

	.align 2
gUnknown_08595020:: @ 8595020
	spr_template ANIM_TAG_RAIN_DROPS, ANIM_TAG_RAIN_DROPS, gUnknown_08524954, gUnknown_0859501C, NULL, gDummySpriteAffineAnimTable, sub_810721C

	.align 2
gUnknown_08595038:: @ 8595038
	.2byte 0xfffb, 0xfffb, 0x0a00, 0x0000, 0x0005, 0x0005, 0x0a00, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595050:: @ 8595050
	.4byte gUnknown_08595038

	.align 2
gUnknown_08595054:: @ 8595054
	.2byte 0x0000, 0x0001, 0x0004, 0x0005, 0x0008, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08595064:: @ 8595064
	.4byte gUnknown_08595054

	.align 2
gBattleAnimSpriteTemplate_8595068:: @ 8595068
	spr_template ANIM_TAG_BUBBLE, ANIM_TAG_BUBBLE, gUnknown_08524A8C, gUnknown_08595064, NULL, gUnknown_08595050, sub_8107260

	.align 2
gUnknown_08595080:: @ 8595080
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595088:: @ 8595088
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595090:: @ 8595090
	.4byte gUnknown_08595080
	.4byte gUnknown_08595088

	.align 2
gUnknown_08595098:: @ 8595098
	.2byte 0x0000, 0x0000, 0x0100, 0x0000, 0x0060, 0x0060, 0x0100, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085950B0:: @ 85950B0
	.4byte gUnknown_08595098

	.align 2
gUnknown_085950B4:: @ 85950B4
	spr_template ANIM_TAG_RAINBOW_RINGS, ANIM_TAG_RAINBOW_RINGS, gUnknown_08524A04, gUnknown_08595090, NULL, gUnknown_085950B0, sub_810744C

	.align 2
gUnknown_085950CC:: @ 85950CC
	.2byte 0x0000, 0x0001, 0x0004, 0x0001, 0x0008, 0x0001, 0x000c, 0x0001, 0xfffe, 0x0000

	.align 2
gUnknown_085950E0:: @ 85950E0
	.4byte gUnknown_085950CC

	.align 2
gUnknown_085950E4:: @ 85950E4
	spr_template ANIM_TAG_WATER_ORB, ANIM_TAG_WATER_ORB, gUnknown_08524A2C, gUnknown_085950E0, NULL, gDummySpriteAffineAnimTable, sub_81075EC

	.align 2
gUnknown_085950FC:: @ 85950FC
	spr_template ANIM_TAG_BROWN_ORB, ANIM_TAG_BROWN_ORB, gUnknown_08524A2C, gUnknown_085950E0, NULL, gDummySpriteAffineAnimTable, sub_81075EC

	.align 2
gUnknown_08595114:: @ 8595114
	spr_template ANIM_TAG_GLOWY_RED_ORB, ANIM_TAG_GLOWY_RED_ORB, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81075EC

	.align 2
gUnknown_0859512C:: @ 859512C
	spr_template ANIM_TAG_GLOWY_GREEN_ORB, ANIM_TAG_GLOWY_GREEN_ORB, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81075EC

	.align 2
gUnknown_08595144:: @ 8595144
	.2byte 0x0010, 0x0002, 0x0020, 0x0002, 0x0030, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_08595154:: @ 8595154
	.4byte gUnknown_08595144

	.align 2
gUnknown_08595158:: @ 8595158
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08595154, NULL, gDummySpriteAffineAnimTable, sub_81075EC

	.align 2
gUnknown_08595170:: @ 8595170
	spr_template ANIM_TAG_BLUE_RING, ANIM_TAG_BLUE_RING, gUnknown_08524A14, gDummySpriteAnimTable, NULL, gUnknown_08593420, sub_81075EC

	.align 2
gUnknown_08595188:: @ 8595188
	.2byte 0x0003, 0x0003, 0x320a, 0x0000, 0x0000, 0x0000, 0x0a00, 0x0000
	.2byte 0xffec, 0xffec, 0x14f6, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085951A8:: @ 85951A8
	.2byte 0x0150, 0x0150, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085951B8:: @ 85951B8
	.4byte gUnknown_08595188

	.align 2
gUnknown_085951BC:: @ 85951BC
	.4byte gUnknown_085951A8

	.align 2
gUnknown_085951C0:: @ 85951C0
	spr_template ANIM_TAG_WATER_ORB, ANIM_TAG_WATER_ORB, gUnknown_08524AEC, gUnknown_085950E0, NULL, gUnknown_085951B8, sub_8107730

	.align 2
gUnknown_085951D8:: @ 85951D8
	spr_template ANIM_TAG_WATER_ORB, ANIM_TAG_WATER_ORB, gUnknown_08524AEC, gUnknown_085950E0, NULL, gUnknown_085951BC, sub_81077C0

	.align 2
gUnknown_085951F0:: @ 85951F0
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085951F8:: @ 85951F8
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595200:: @ 8595200
	.4byte gUnknown_085951F0

	.align 2
gUnknown_08595204:: @ 8595204
	.4byte gUnknown_085951F8

	.align 2
gUnknown_08595208:: @ 8595208
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_08524A2C, gUnknown_08595200, NULL, gDummySpriteAffineAnimTable, sub_80A78AC

	.align 2
gUnknown_08595220:: @ 8595220
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_08524AEC, gUnknown_08595204, NULL, gUnknown_08596208, sub_8107894

	.align 2
gUnknown_08595238:: @ 8595238
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524904, gUnknown_08595AB8, NULL, gDummySpriteAffineAnimTable, sub_81078D0

	.align 2
gUnknown_08595250:: @ 8595250
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8108034

	.align 2
gUnknown_08595268:: @ 8595268
	spr_template ANIM_TAG_GLOWY_BLUE_ORB, ANIM_TAG_GLOWY_BLUE_ORB, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810851C

	.align 2
gUnknown_08595280:: @ 8595280
	.2byte 0x0008, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595288:: @ 8595288
	.2byte 0x0009, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595290:: @ 8595290
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595298:: @ 8595298
	.4byte gUnknown_08595280
	.4byte gUnknown_08595288

	.align 2
gUnknown_085952A0:: @ 85952A0
	.4byte gUnknown_08595290

	.align 2
gUnknown_085952A4:: @ 85952A4
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfff6, 0xfff6, 0x0f00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085952BC:: @ 85952BC
	.2byte 0x00e0, 0x00e0, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0f00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085952D4:: @ 85952D4
	.2byte 0x0150, 0x0150, 0x0000, 0x0000, 0x0000, 0x0000, 0x0f00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085952EC:: @ 85952EC
	.4byte gUnknown_085952A4
	.4byte gUnknown_085952BC

	.align 2
gUnknown_085952F4:: @ 85952F4
	.4byte gUnknown_085952D4

	.align 2
gUnknown_085952F8:: @ 85952F8
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_08524904, gUnknown_08595298, NULL, gDummySpriteAffineAnimTable, sub_8108BE0

	.align 2
gUnknown_08595310:: @ 8595310
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_08524964, gUnknown_08595298, NULL, gUnknown_085952EC, sub_8108C54

	.align 2
gUnknown_08595328:: @ 8595328
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_0852496C, gUnknown_085952A0, NULL, gUnknown_085952F4, sub_80A8EE4

	.align 2
gUnknown_08595340:: @ 8595340
	.2byte 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_08595350:: @ 8595350
	.2byte 0x0010, 0x00c4, 0x0020, 0x00c4, 0x0030, 0x00c4, 0xfffe, 0x0000

	.align 2
gUnknown_08595360:: @ 8595360
	.4byte gUnknown_08595340
	.4byte gUnknown_08595350

	.align 2
gUnknown_08595368:: @ 8595368
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08595360, NULL, gDummySpriteAffineAnimTable, sub_8108EC8

	.align 2
gUnknown_08595380:: @ 8595380
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08595360, NULL, gDummySpriteAffineAnimTable, sub_8108F08

	.align 2
gUnknown_08595398:: @ 8595398
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0x0050, 0x0003, 0x0060, 0x0003, 0x0070, 0x0003
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_085953BC:: @ 85953BC
	.4byte gUnknown_08595398

	.align 2
gUnknown_085953C0:: @ 85953C0
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0030, 0x0005
	.2byte 0x0040, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_085953D8:: @ 85953D8
	.4byte gUnknown_085953C0

	.align 2
gUnknown_085953DC:: @ 85953DC
	.2byte 0x0032, 0x0100, 0x0000, 0x0000, 0x0020, 0x0000, 0x0700, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085953F4:: @ 85953F4
	.4byte gUnknown_085953DC

	.align 2
gUnknown_085953F8:: @ 85953F8
	spr_template ANIM_TAG_FIRE, ANIM_TAG_FIRE, gUnknown_08524974, gUnknown_085953BC, NULL, gUnknown_085953F4, sub_8108FBC

	.align 2
gUnknown_08595410:: @ 8595410
	spr_template ANIM_TAG_FIRE, ANIM_TAG_FIRE, gUnknown_08524914, gUnknown_085953BC, NULL, gDummySpriteAffineAnimTable, sub_8108FBC

	.align 2
gUnknown_08595428:: @ 8595428
	spr_template ANIM_TAG_FIRE_PLUME, ANIM_TAG_FIRE_PLUME, gUnknown_08524914, gUnknown_085953D8, NULL, gDummySpriteAffineAnimTable, sub_8108F4C

	.align 2
gUnknown_08595440:: @ 8595440
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085953D8, NULL, gDummySpriteAffineAnimTable, sub_8108F4C

	.align 2
gUnknown_08595458:: @ 8595458
	.2byte 0x0010, 0x0006, 0x0020, 0x0006, 0x0030, 0x0006, 0xfffe, 0x0000

	.align 2
gUnknown_08595468:: @ 8595468
	.4byte gUnknown_08595458

	.align 2
gUnknown_0859546C:: @ 859546C
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08595468, NULL, gDummySpriteAffineAnimTable, sub_8109064

	.align 2
gUnknown_08595484:: @ 8595484
	.2byte 0x0050, 0x0050, 0x0000, 0x0000, 0x0002, 0x0002, 0x010a, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_0859549C:: @ 859549C
	.4byte gUnknown_08595484

	.align 2
gUnknown_085954A0:: @ 85954A0
	spr_template ANIM_TAG_SUNLIGHT, ANIM_TAG_SUNLIGHT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_0859549C, sub_810916C

	.align 2
gUnknown_085954B8:: @ 85954B8
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004
	.2byte 0x0040, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_085954D0:: @ 85954D0
	.4byte gUnknown_085954B8

	.align 2
gEmberSpriteTemplate:: @ 85954D4
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TranslateAnimSpriteToTargetMonLocation

	.align 2
gEmberFlareSpriteTemplate:: @ 85954EC
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085954D0, NULL, gDummySpriteAffineAnimTable, sub_8109198

	.align 2
gUnknown_08595504:: @ 8595504
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085954D0, NULL, gDummySpriteAffineAnimTable, sub_8109200

	.align 2
gUnknown_0859551C:: @ 859551C
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085954D0, NULL, gDummySpriteAffineAnimTable, sub_810921C

	.align 2
gUnknown_08595534:: @ 8595534
	.2byte 0x0020, 0x0006, 0x0030, 0x0006, 0xfffe, 0x0000

	.align 2
gUnknown_08595540:: @ 8595540
	.4byte gUnknown_08595534

	.align 2
gUnknown_08595544:: @ 8595544
	.2byte 0x0000, 0x0000, 0x0100, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595554:: @ 8595554
	.2byte 0x00a0, 0x00a0, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595564:: @ 8595564
	.4byte gUnknown_08595544
	.4byte gUnknown_08595554

	.align 2
gUnknown_0859556C:: @ 859556C
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08595540, NULL, gDummySpriteAffineAnimTable, sub_8109364

	.align 2
gBattleAnimSpriteTemplate_8595584:: @ 8595584
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085954D0, NULL, gDummySpriteAffineAnimTable, sub_81093A4

	.align 2
gUnknown_0859559C:: @ 859559C
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085954D0, NULL, gDummySpriteAffineAnimTable, sub_80A8EE4

	.align 2
gUnknown_085955B4:: @ 85955B4
	spr_template ANIM_TAG_WARM_ROCK, ANIM_TAG_WARM_ROCK, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81098EC

	.align 2
gUnknown_085955CC:: @ 85955CC
	.2byte 0xfffe, 0xfffb, 0xffff, 0xffff, 0x0003, 0xfffa, 0x0004, 0xfffe
	.2byte 0x0002, 0xfff8, 0xfffb, 0xfffb, 0x0004, 0xfff9

	.align 2
gUnknown_085955E8:: @ 85955E8
	spr_template ANIM_TAG_WARM_ROCK, ANIM_TAG_WARM_ROCK, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8109A10

	.align 2
gUnknown_08595600:: @ 8595600
	.2byte 0x0000, 0x0005, 0x0004, 0x0005, 0x0008, 0x0005, 0x000c, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_08595614:: @ 8595614
	.2byte 0x0010, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_0859561C:: @ 859561C
	.2byte 0x0014, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08595624:: @ 8595624
	.2byte 0x0014, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_0859562C:: @ 859562C
	.4byte gUnknown_08595600
	.4byte gUnknown_08595614
	.4byte gUnknown_0859561C
	.4byte gUnknown_08595624

	.align 2
gUnknown_0859563C:: @ 859563C
	spr_template ANIM_TAG_WISP_ORB, ANIM_TAG_WISP_ORB, gUnknown_0852490C, gUnknown_0859562C, NULL, gDummySpriteAffineAnimTable, sub_8109AFC

	.align 2
gUnknown_08595654:: @ 8595654
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0030, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_08595668:: @ 8595668
	.4byte gUnknown_08595654

	.align 2
gUnknown_0859566C:: @ 859566C
	spr_template ANIM_TAG_WISP_FIRE, ANIM_TAG_WISP_FIRE, gUnknown_08524914, gUnknown_08595668, NULL, gDummySpriteAffineAnimTable, sub_8109CB0

	.align 2
gUnknown_08595684:: @ 8595684
	.2byte 0xffff, 0x0100, 0x0001, 0xff00, 0x01ff, 0x0001, 0xff00, 0x0100

	.align 2
gUnknown_08595694:: @ 8595694
	.2byte 0x00ff, 0x0001, 0x01ff, 0xff00, 0x0100, 0xff00, 0x0100, 0x0100

	.align 2
gUnknown_085956A4:: @ 85956A4
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0008, 0x0030, 0x0005
	.2byte 0x0040, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_085956BC:: @ 85956BC
	.4byte gUnknown_085956A4

	.align 2
gUnknown_085956C0:: @ 85956C0
	spr_template ANIM_TAG_LIGHTNING, ANIM_TAG_LIGHTNING, gUnknown_08524914, gUnknown_085956BC, NULL, gDummySpriteAffineAnimTable, sub_810A1A8

	.align 2
gUnknown_085956D8:: @ 85956D8
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x1400, 0x0000
	.2byte 0x0000, 0x0000, 0x3cf0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085956F8:: @ 85956F8
	.4byte gUnknown_085956D8

	.align 2
gUnknown_085956FC:: @ 85956FC
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_085956F8, sub_810A214

	.align 2
gUnknown_08595714:: @ 8595714
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0030, 0x0005
	.2byte 0x0040, 0x0005, 0x0050, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_08595730:: @ 8595730
	.4byte gUnknown_08595714

	.align 2
gUnknown_08595734:: @ 8595734
	spr_template 0x275f, 0x275f, gUnknown_08524914, gUnknown_08595730, NULL, gDummySpriteAffineAnimTable, sub_810A274

	.align 2
gBattleAnimSpriteTemplate_859574C:: @ 859574C
	spr_template ANIM_TAG_SPARK_2, ANIM_TAG_SPARK_2, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810A308

	.align 2
gUnknown_08595764:: @ 8595764
	spr_template ANIM_TAG_BLACK_BALL_2, ANIM_TAG_BLACK_BALL_2, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TranslateAnimSpriteToTargetMonLocation

	.align 2
gUnknown_0859577C:: @ 859577C
	.2byte 0x0000, 0x0000, 0x0114, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859578C:: @ 859578C
	.4byte gUnknown_0859577C

	.align 2
gUnknown_08595790:: @ 8595790
	spr_template ANIM_TAG_SPARK_2, ANIM_TAG_SPARK_2, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_0859578C, sub_810A46C

	.align 2
gUnknown_085957A8:: @ 85957A8
	.2byte 0x0000, 0x0006, 0x0010, 0x0006, 0x0020, 0x0006, 0xfffe, 0x0000

	.align 2
gUnknown_085957B8:: @ 85957B8
	.4byte gUnknown_085957A8

	.align 2
gUnknown_085957BC:: @ 85957BC
	.2byte 0x00e8, 0x00e8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0a00, 0x0000
	.2byte 0x0008, 0x0008, 0x0a00, 0x0000, 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085957DC:: @ 85957DC
	.4byte gUnknown_085957BC

	.align 2
gBattleAnimSpriteTemplate_85957E0:: @ 85957E0
	spr_template ANIM_TAG_SHOCK_3, ANIM_TAG_SHOCK_3, gUnknown_08524974, gUnknown_085957B8, NULL, gUnknown_085957DC, sub_810A5BC

	.align 2
gBattleAnimSpriteTemplate_85957F8:: @ 85957F8
	spr_template ANIM_TAG_SPARK_2, ANIM_TAG_SPARK_2, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_0859578C, sub_810A628

	.align 2
gElectricitySpriteTemplate:: @ 8595810
	spr_template ANIM_TAG_SPARK_2, ANIM_TAG_SPARK_2, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810A75C

	.align 2
gUnknown_08595828:: @ 8595828
	spr_template ANIM_TAG_SPARK, ANIM_TAG_SPARK, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810A9DC

	.align 2
gUnknown_08595840:: @ 8595840
	spr_template 0x27bd, 0x27bd, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810AA2C

	.align 2
gUnknown_08595858:: @ 8595858
	.byte 0x3a, 0xc4, 0xc8, 0xdc, 0x08, 0xc8, 0xf0, 0x38
	.byte 0x3a, 0xf6, 0xc6, 0x0a, 0x30, 0xee, 0xf8, 0x38
	.byte 0x10, 0xc8, 0xc6, 0xd6, 0x3a, 0x1e, 0xd0, 0x28
	.byte 0x0c, 0xd0, 0x30, 0xf4, 0xc8, 0x12, 0x30, 0x30

	.align 2
gUnknown_08595878:: @ 8595878
	.2byte 0x0003, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_0859588C:: @ 859588C
	.2byte 0x0000, 0x0005, 0x0001, 0x0005, 0x0002, 0x0005, 0x0003, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_085958A0:: @ 85958A0
	.4byte gUnknown_08595878
	.4byte gUnknown_0859588C

	.align 2
gUnknown_085958A8:: @ 85958A8
	spr_template ANIM_TAG_ELECTRIC_ORBS, ANIM_TAG_ELECTRIC_ORBS, gUnknown_08524904, gUnknown_085958A0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085958C0:: @ 85958C0
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0004, 0x0004, 0x3c00, 0x0000
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7ffd, 0x0000, 0x0000, 0x0000
	.2byte 0xfffc, 0xfffc, 0x0500, 0x0000, 0x0004, 0x0004, 0x0500, 0x0000
	.2byte 0x7ffd, 0x000a, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595900:: @ 8595900
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0008, 0x0008, 0x1e00, 0x0000
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfffc, 0xfffc, 0x0500, 0x0000
	.2byte 0x0004, 0x0004, 0x0500, 0x0000, 0x7ffe, 0x0003, 0x0000, 0x0000

	.align 2
gUnknown_08595930:: @ 8595930
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0008, 0x0008, 0x1e00, 0x0000
	.2byte 0xfff8, 0xfff8, 0x1e00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595950:: @ 8595950
	.4byte gUnknown_085958C0
	.4byte gUnknown_08595900
	.4byte gUnknown_08595930

	.align 2
gUnknown_0859595C:: @ 859595C
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08595950, sub_810ACD8

	.align 2
gUnknown_08595974:: @ 8595974
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_08595988:: @ 8595988
	.4byte gUnknown_08595974

	.align 2
gUnknown_0859598C:: @ 859598C
	spr_template ANIM_TAG_ELECTRICITY, ANIM_TAG_ELECTRICITY, gUnknown_08524914, gUnknown_08595988, NULL, gDummySpriteAffineAnimTable, sub_810AD30

	.align 2
gUnknown_085959A4:: @ 85959A4
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08595950, sub_810AD98

	.align 2
gUnknown_085959BC:: @ 85959BC
	.2byte 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085959C4:: @ 85959C4
	.2byte 0x0002, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085959CC:: @ 85959CC
	.2byte 0x0004, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085959D4:: @ 85959D4
	.2byte 0x0006, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085959DC:: @ 85959DC
	.4byte gUnknown_085959BC
	.4byte gUnknown_085959C4
	.4byte gUnknown_085959CC
	.4byte gUnknown_085959D4

	.align 2
gUnknown_085959EC:: @ 85959EC
	.2byte 0x0100, 0x0100, 0x0040, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085959FC:: @ 85959FC
	.4byte gUnknown_085959EC

	.align 2
gUnknown_08595A00:: @ 8595A00
	spr_template ANIM_TAG_SPARK, ANIM_TAG_SPARK, gUnknown_08524A04, gUnknown_085959DC, NULL, gUnknown_085959FC, sub_810B1F0

	.align 2
gUnknown_08595A18:: @ 8595A18
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08595950, sub_810B23C

	.align 2
gUnknown_08595A30:: @ 8595A30
	spr_template ANIM_TAG_SPARK, ANIM_TAG_SPARK, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810B51C

	.align 2
gUnknown_08595A48:: @ 8595A48
	.2byte 0x0000, 0x0045, 0x0001, 0x0045, 0xfffe, 0x0000

	.align 2
gUnknown_08595A54:: @ 8595A54
	.4byte gUnknown_08595A48

	.align 2
gUnknown_08595A58:: @ 8595A58
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810B6C4

	.align 2
gUnknown_08595A70:: @ 8595A70
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595A78:: @ 8595A78
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595A80:: @ 8595A80
	.2byte 0x0006, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595A88:: @ 8595A88
	.2byte 0x0007, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595A90:: @ 8595A90
	.2byte 0x0008, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595A98:: @ 8595A98
	.2byte 0x000c, 0x0006, 0x000d, 0x0006, 0xfffe, 0x0000

	.align 2
gUnknown_08595AA4:: @ 8595AA4
	.4byte gUnknown_08595A70

	.align 2
gUnknown_08595AA8:: @ 8595AA8
	.4byte gUnknown_08595A78

	.align 2
gUnknown_08595AAC:: @ 8595AAC
	.4byte gUnknown_08595A80

	.align 2
gUnknown_08595AB0:: @ 8595AB0
	.4byte gUnknown_08595A88

	.align 2
gUnknown_08595AB4:: @ 8595AB4
	.4byte gUnknown_08595A90

	.align 2
gUnknown_08595AB8:: @ 8595AB8
	.4byte gUnknown_08595A98

	.align 2
gUnknown_08595ABC:: @ 8595ABC
	.2byte 0x0000, 0x0000, 0x0128, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595ACC:: @ 8595ACC
	.4byte gUnknown_08595ABC

	.align 2
gUnknown_08595AD0:: @ 8595AD0
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524B24, gUnknown_08595AA8, NULL, gUnknown_08595ACC, sub_810B8AC

	.align 2
gUnknown_08595AE8:: @ 8595AE8
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524A24, gUnknown_08595AAC, NULL, gDummySpriteAffineAnimTable, sub_810B8AC

	.align 2
gUnknown_08595B00:: @ 8595B00
	.2byte 0x0000, 0x0000, 0x010a, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595B10:: @ 8595B10
	.4byte gUnknown_08595B00

	.align 2
gUnknown_08595B14:: @ 8595B14
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524AC4, gUnknown_08595AA8, NULL, gUnknown_08595B10, sub_810B8EC

	.align 2
gUnknown_08595B2C:: @ 8595B2C
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524A24, gUnknown_08595AAC, NULL, gDummySpriteAffineAnimTable, sub_810B8EC

	.align 2
gUnknown_08595B44:: @ 8595B44
	.2byte 0x00ce, 0x00ce, 0x0000, 0x0000, 0x0005, 0x0005, 0x0a00, 0x0000
	.2byte 0x0000, 0x0000, 0x0600, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595B64:: @ 8595B64
	.4byte gUnknown_08595B44

	.align 2
gUnknown_08595B68:: @ 8595B68
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524AC4, gUnknown_08595AA8, NULL, gUnknown_08595B64, sub_810B974

	.align 2
gUnknown_08595B80:: @ 8595B80
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524A84, gUnknown_08595AAC, NULL, gUnknown_08595B64, sub_810B974

	.align 2
gUnknown_08595B98:: @ 8595B98
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524904, gUnknown_08595AB0, NULL, gDummySpriteAffineAnimTable, sub_810BA24

	.align 2
gUnknown_08595BB0:: @ 8595BB0
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_0852490C, gUnknown_08595AB4, NULL, gDummySpriteAffineAnimTable, sub_810BC94

	.align 2
gUnknown_08595BC8:: @ 8595BC8
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524904, gUnknown_08595AB0, NULL, gDummySpriteAffineAnimTable, sub_810BC94

	.align 2
gUnknown_08595BE0:: @ 8595BE0
	.2byte 0x0000, 0x0005, 0x0002, 0x0005, 0x0004, 0x0005, 0x0006, 0x0005
	.2byte 0x0004, 0x0005, 0x0002, 0x0005, 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08595C00:: @ 8595C00
	.4byte gUnknown_08595BE0

	.align 2
gUnknown_08595C04:: @ 8595C04
	spr_template ANIM_TAG_ICE_SPIKES, ANIM_TAG_ICE_SPIKES, gUnknown_08524A64, gUnknown_08595C00, NULL, gDummySpriteAffineAnimTable, sub_810BE48

	.align 2
gUnknown_08595C1C:: @ 8595C1C
	.2byte 0x0000, 0x0008, 0x0008, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_08595C28:: @ 8595C28
	.4byte gUnknown_08595C1C

	.align 2
gUnknown_08595C2C:: @ 8595C2C
	spr_template ANIM_TAG_MIST_CLOUD, ANIM_TAG_MIST_CLOUD, gUnknown_08524A54, gUnknown_08595C28, NULL, gDummySpriteAffineAnimTable, sub_810BED0

	.align 2
gUnknown_08595C44:: @ 8595C44
	spr_template ANIM_TAG_PURPLE_GAS_CLOUD, ANIM_TAG_PURPLE_GAS_CLOUD, gUnknown_08524A54, gUnknown_08595C28, NULL, gDummySpriteAffineAnimTable, sub_810BED0

	.align 2
gUnknown_08595C5C:: @ 8595C5C
	.byte 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x04
	.byte 0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x06, 0x07
	.byte 0x08, 0x08, 0x08, 0x09

	.align 2
gUnknown_08595C70:: @ 8595C70
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810C2F0

	.align 2
gUnknown_08595C88:: @ 8595C88
	.byte 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02
	.byte 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04
	.byte 0x04, 0x04, 0x04, 0x05

	.align 2
gUnknown_08595C9C:: @ 8595C9C
	spr_template ANIM_TAG_PURPLE_GAS_CLOUD, ANIM_TAG_PURPLE_GAS_CLOUD, gUnknown_08524A54, gUnknown_08595C28, NULL, gDummySpriteAffineAnimTable, sub_810C560

	.align 2
gUnknown_08595CB4:: @ 8595CB4
	.byte 0x64, 0xe0, 0x01, 0x20, 0x55, 0xe0, 0x01, 0x00
	.byte 0xf2, 0xe0, 0x11, 0x10, 0x42, 0xe0, 0x21, 0x10
	.byte 0xb6, 0xe0, 0x31, 0x00, 0x3c, 0xe0, 0x01, 0x20
	.byte 0xd6, 0xe0, 0x11, 0x00, 0x71, 0xe0, 0x01, 0x10
	.byte 0xd2, 0xe0, 0x31, 0x10, 0x26, 0xe0, 0x21, 0x00

	.align 2
gUnknown_08595CDC:: @ 8595CDC
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595CEC:: @ 8595CEC
	.2byte 0x00f0, 0x00f0, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595CFC:: @ 8595CFC
	.2byte 0x00e0, 0x00e0, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595D0C:: @ 8595D0C
	.2byte 0x0150, 0x0150, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595D1C:: @ 8595D1C
	.4byte gUnknown_08595CDC
	.4byte gUnknown_08595CEC
	.4byte gUnknown_08595CFC

	.align 2
gUnknown_08595D28:: @ 8595D28
	.4byte gUnknown_08595D0C

	.align 2
gUnknown_08595D2C:: @ 8595D2C
	spr_template ANIM_TAG_HAIL, ANIM_TAG_HAIL, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08595D1C, sub_810CB58

	.align 2
gUnknown_08595D44:: @ 8595D44
	spr_template ANIM_TAG_HAIL, ANIM_TAG_HAIL, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08595D28, sub_80A8EE4

	.align 2
gUnknown_08595D5C:: @ 8595D5C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595D64:: @ 8595D64
	.2byte 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004, 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08595D78:: @ 8595D78
	.4byte gUnknown_08595D5C
	.4byte gUnknown_08595D64

	.align 2
gUnknown_08595D80:: @ 8595D80
	.2byte 0x00e0, 0x00e0, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595D90:: @ 8595D90
	.2byte 0x0118, 0x0118, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595DA0:: @ 8595DA0
	.2byte 0x0150, 0x0150, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595DB0:: @ 8595DB0
	.2byte 0x0180, 0x0180, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595DC0:: @ 8595DC0
	.2byte 0x01c0, 0x01c0, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08595DD0:: @ 8595DD0
	.4byte gUnknown_08595D80
	.4byte gUnknown_08595D90
	.4byte gUnknown_08595DA0
	.4byte gUnknown_08595DB0
	.4byte gUnknown_08595DC0

	.align 2
gUnknown_08595DE4:: @ 8595DE4
	spr_template ANIM_TAG_ICE_CHUNK, ANIM_TAG_ICE_CHUNK, gUnknown_085249D4, gUnknown_08595D78, NULL, gUnknown_08595DD0, unc_080B06FC

	.align 2
gUnknown_08595DFC:: @ 8595DFC
	spr_template ANIM_TAG_ICE_CRYSTALS, ANIM_TAG_ICE_CRYSTALS, gUnknown_08524904, gUnknown_08595AAC, NULL, gDummySpriteAffineAnimTable, sub_810CD4C

	.align 2
gUnknown_08595E14:: @ 8595E14
	spr_template ANIM_TAG_HUMANOID_FOOT, ANIM_TAG_HUMANOID_FOOT, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, unc_080B08A0

	.align 2
gUnknown_08595E2C:: @ 8595E2C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595E34:: @ 8595E34
	.2byte 0x0010, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595E3C:: @ 8595E3C
	.2byte 0x0020, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595E44:: @ 8595E44
	.2byte 0x0030, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08595E4C:: @ 8595E4C
	.2byte 0x0030, 0x0041, 0xffff, 0x0000

	.align 2
gUnknown_08595E54:: @ 8595E54
	.4byte gUnknown_08595E2C

	.align 2
gUnknown_08595E58:: @ 8595E58
	.4byte gUnknown_08595E34
	.4byte gUnknown_08595E3C

	.align 2
gUnknown_08595E60:: @ 8595E60
	.4byte gUnknown_08595E44
	.4byte gUnknown_08595E4C

	.align 2
gUnknown_08595E68:: @ 8595E68
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E54, NULL, gDummySpriteAffineAnimTable, sub_810CE68

	.align 2
gUnknown_08595E80:: @ 8595E80
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E54, NULL, gDummySpriteAffineAnimTable, sub_810CEB4

	.align 2
gFistFootSpriteTemplate:: @ 8595E98
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E54, NULL, gDummySpriteAffineAnimTable, sub_810CEE0

	.align 2
gUnknown_08595EB0:: @ 8595EB0
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E54, NULL, gDummySpriteAffineAnimTable, sub_810CF30

	.align 2
gUnknown_08595EC8:: @ 8595EC8
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E60, NULL, gDummySpriteAffineAnimTable, sub_810D10C

	.align 2
gUnknown_08595EE0:: @ 8595EE0
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E58, NULL, gDummySpriteAffineAnimTable, sub_810D1B4

	.align 2
gUnknown_08595EF8:: @ 8595EF8
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0114, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08595F10:: @ 8595F10
	.4byte gUnknown_08595EF8

	.align 2
gUnknown_08595F14:: @ 8595F14
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_085249D4, gUnknown_08595E54, NULL, gUnknown_08595F10, sub_810D278

	.align 2
gUnknown_08595F2C:: @ 8595F2C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfffc, 0xfffc, 0x0114, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08595F44:: @ 8595F44
	.4byte gUnknown_08595F2C

	.align 2
gMegaPunchKickSpriteTemplate:: @ 8595F48
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_085249D4, gUnknown_08595E54, NULL, gUnknown_08595F44, sub_810D278

	.align 2
gUnknown_08595F60:: @ 8595F60
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E58, NULL, gDummySpriteAffineAnimTable, sub_810D2E4

	.align 2
gUnknown_08595F78:: @ 8595F78
	spr_template ANIM_TAG_DUCK, ANIM_TAG_DUCK, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810D37C

	.align 2
gUnknown_08595F90:: @ 8595F90
	spr_template ANIM_TAG_BLUE_LIGHT_WALL, ANIM_TAG_BLUE_LIGHT_WALL, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810D40C

	.align 2
gUnknown_08595FA8:: @ 8595FA8
	spr_template ANIM_TAG_TORN_METAL, ANIM_TAG_TORN_METAL, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810D4F4

	.align 2
gUnknown_08595FC0:: @ 8595FC0
	.2byte 0x0020, 0x0020, 0x0000, 0x0000, 0x0004, 0x0004, 0x4000, 0x0000
	.2byte 0xfffa, 0xfffa, 0x0800, 0x0000, 0x0006, 0x0006, 0x0800, 0x0000
	.2byte 0x7ffe, 0x0002, 0x0000, 0x0000

	.align 2
gUnknown_08595FE8:: @ 8595FE8
	.4byte gUnknown_08595FC0

	.align 2
gUnknown_08595FEC:: @ 8595FEC
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08595FE8, sub_810D608

	.align 2
gUnknown_08596004:: @ 8596004
	spr_template ANIM_TAG_FLAT_ROCK, ANIM_TAG_FLAT_ROCK, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810D714

	.align 2
gUnknown_0859601C:: @ 859601C
	spr_template ANIM_TAG_METEOR, ANIM_TAG_METEOR, gUnknown_0852491C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810D874

	.align 2
gUnknown_08596034:: @ 8596034
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_08524914, gUnknown_08595E54, NULL, gDummySpriteAffineAnimTable, sub_810D984

	.align 2
gUnknown_0859604C:: @ 859604C
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_0859605C:: @ 859605C
	.2byte 0x0000, 0x0084, 0x0010, 0x0084, 0x0020, 0x0084, 0xffff, 0x0000

	.align 2
gUnknown_0859606C:: @ 859606C
	.2byte 0x0000, 0x0044, 0x0010, 0x0044, 0x0020, 0x0044, 0xffff, 0x0000

	.align 2
gUnknown_0859607C:: @ 859607C
	.4byte gUnknown_0859604C
	.4byte gUnknown_0859605C
	.4byte gUnknown_0859606C

	.align 2
gUnknown_08596088:: @ 8596088
	spr_template ANIM_TAG_PURPLE_SCRATCH, ANIM_TAG_PURPLE_SCRATCH, gUnknown_08524914, gUnknown_0859607C, NULL, gDummySpriteAffineAnimTable, sub_810DA10

	.align 2
gUnknown_085960A0:: @ 85960A0
	.2byte 0x0000, 0x0006, 0x0040, 0x0006, 0xffff, 0x0000

	.align 2
gUnknown_085960AC:: @ 85960AC
	.2byte 0x0000, 0x00c6, 0x0040, 0x00c6, 0xffff, 0x0000

	.align 2
gUnknown_085960B8:: @ 85960B8
	.2byte 0x0000, 0x0046, 0x0040, 0x0046, 0xffff, 0x0000

	.align 2
gUnknown_085960C4:: @ 85960C4
	.4byte gUnknown_085960A0
	.4byte gUnknown_085960AC
	.4byte gUnknown_085960B8

	.align 2
gUnknown_085960D0:: @ 85960D0
	spr_template ANIM_TAG_PURPLE_SWIPE, ANIM_TAG_PURPLE_SWIPE, gUnknown_0852491C, gUnknown_085960C4, NULL, gDummySpriteAffineAnimTable, sub_810DA10

	.align 2
gUnknown_085960E8:: @ 85960E8
	.2byte 0x0200, 0x0200, 0x0000, 0x0000, 0xffe0, 0xffe0, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596100:: @ 8596100
	.4byte gUnknown_085960E8

	.align 2
gUnknown_08596104:: @ 8596104
	spr_template ANIM_TAG_HANDS_AND_FEET, ANIM_TAG_HANDS_AND_FEET, gUnknown_085249D4, gUnknown_08595E54, NULL, gUnknown_08596100, sub_810DA7C

	.align 2
gUnknown_0859611C:: @ 859611C
	.2byte 0x0000, 0x0005, 0x0008, 0x0005, 0x0010, 0x0005, 0x0018, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08596130:: @ 8596130
	.4byte gUnknown_0859611C

	.align 2
gUnknown_08596134:: @ 8596134
	spr_template ANIM_TAG_TOXIC_BUBBLE, ANIM_TAG_TOXIC_BUBBLE, gUnknown_08524954, gUnknown_08596130, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
gUnknown_0859614C:: @ 859614C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596154:: @ 8596154
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_0859615C:: @ 859615C
	.2byte 0x0008, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596164:: @ 8596164
	.4byte gUnknown_0859614C

	.align 2
gUnknown_08596168:: @ 8596168
	.4byte gUnknown_08596154

	.align 2
gUnknown_0859616C:: @ 859616C
	.4byte gUnknown_0859615C

	.align 2
gUnknown_08596170:: @ 8596170
	.2byte 0x0160, 0x0160, 0x0000, 0x0000, 0xfff6, 0xfff6, 0x0a00, 0x0000
	.2byte 0x000a, 0x000a, 0x0a00, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596190:: @ 8596190
	.2byte 0x00ec, 0x00ec, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085961A0:: @ 85961A0
	.4byte gUnknown_08596170

	.align 2
gUnknown_085961A4:: @ 85961A4
	.4byte gUnknown_08596190

	.align 2
gUnknown_085961A8:: @ 85961A8
	spr_template ANIM_TAG_POISON_BUBBLE, ANIM_TAG_POISON_BUBBLE, gUnknown_085249CC, gUnknown_08596164, NULL, gUnknown_085961A0, sub_810DBAC

	.align 2
gUnknown_085961C0:: @ 85961C0
	spr_template ANIM_TAG_POISON_BUBBLE, ANIM_TAG_POISON_BUBBLE, gUnknown_085249CC, gUnknown_08596164, NULL, gUnknown_085961A0, sub_810DC2C

	.align 2
gUnknown_085961D8:: @ 85961D8
	spr_template ANIM_TAG_POISON_BUBBLE, ANIM_TAG_POISON_BUBBLE, gUnknown_0852496C, gUnknown_0859616C, NULL, gUnknown_085961A4, sub_810DCD0

	.align 2
gUnknown_085961F0:: @ 85961F0
	.2byte 0xfff0, 0x0010, 0x0600, 0x0000, 0x0010, 0xfff0, 0x0600, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596208:: @ 8596208
	.4byte gUnknown_085961F0

	.align 2
gUnknown_0859620C:: @ 859620C
	spr_template ANIM_TAG_POISON_BUBBLE, ANIM_TAG_POISON_BUBBLE, gUnknown_085249CC, gUnknown_08596168, NULL, gUnknown_08596208, sub_810DD50

	.align 2
gUnknown_08596224:: @ 8596224
	.2byte 0x009c, 0x009c, 0x0000, 0x0000, 0x0005, 0x0005, 0x1400, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859623C:: @ 859623C
	.4byte gUnknown_08596224

	.align 2
gPoisonBubbleSpriteTemplate:: @ 8596240
	spr_template ANIM_TAG_POISON_BUBBLE, ANIM_TAG_POISON_BUBBLE, gUnknown_0852496C, gUnknown_08596164, NULL, gUnknown_0859623C, sub_810DDC4

	.align 2
gWaterBubbleSpriteTemplate:: @ 8596258
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_08524A8C, gUnknown_08595200, NULL, gUnknown_0859623C, sub_810DDC4

	.align 2
gUnknown_08596270:: @ 8596270
	spr_template ANIM_TAG_GUST, ANIM_TAG_GUST, gUnknown_0852495C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810DE70

	.align 2
gUnknown_08596288:: @ 8596288
	.2byte 0x0010, 0x0100, 0x0000, 0x0000, 0x000a, 0x0000, 0x1800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085962A0:: @ 85962A0
	.4byte gUnknown_08596288

	.align 2
gBattleAnimSpriteTemplate_85962A4:: @ 85962A4
	spr_template ANIM_TAG_GUST, ANIM_TAG_GUST, gUnknown_085249BC, gDummySpriteAnimTable, NULL, gUnknown_085962A0, sub_810DFA8

	.align 2
gUnknown_085962BC:: @ 85962BC
	.2byte 0x0000, 0x0003, 0x0000, 0x0043, 0x0000, 0x0083, 0x0000, 0x00c3, 0xfffe, 0x0000

	.align 2
gUnknown_085962D0:: @ 85962D0
	.4byte gUnknown_085962BC

	.align 2
gUnknown_085962D4:: @ 85962D4
	spr_template ANIM_TAG_AIR_WAVE_2, ANIM_TAG_AIR_WAVE_2, gUnknown_08524934, gUnknown_085962D0, NULL, gDummySpriteAffineAnimTable, sub_810E044

	.align 2
gUnknown_085962EC:: @ 85962EC
	.2byte 0x0010, 0x0100, 0x0000, 0x0000, 0x0028, 0x0000, 0x0600, 0x0000
	.2byte 0x0000, 0xffe0, 0x0500, 0x0000, 0xfff0, 0x0020, 0x0a00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596314:: @ 8596314
	.4byte gUnknown_085962EC

	.align 2
gUnknown_08596318:: @ 8596318
	.2byte 0x0000, 0x0000, 0x0132, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596328:: @ 8596328
	.2byte 0x0000, 0x0000, 0x01d8, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596338:: @ 8596338
	.4byte gUnknown_08596318
	.4byte gUnknown_08596328

	.align 2
gUnknown_08596340:: @ 8596340
	spr_template ANIM_TAG_ROUND_SHADOW, ANIM_TAG_ROUND_SHADOW, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_08596314, sub_810E13C

	.align 2
gUnknown_08596358:: @ 8596358
	spr_template ANIM_TAG_ROUND_SHADOW, ANIM_TAG_ROUND_SHADOW, gUnknown_0852497C, gDummySpriteAnimTable, NULL, gUnknown_08596338, sub_810E1C8

	.align 2
gUnknown_08596370:: @ 8596370
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08596378:: @ 8596378
	.2byte 0x0010, 0x0040, 0xffff, 0x0000

	.align 2
gUnknown_08596380:: @ 8596380
	.4byte gUnknown_08596370
	.4byte gUnknown_08596378

	.align 2
gUnknown_08596388:: @ 8596388
	spr_template ANIM_TAG_WHITE_FEATHER, ANIM_TAG_WHITE_FEATHER, gUnknown_08524974, gUnknown_08596380, NULL, gDummySpriteAffineAnimTable, sub_810E314

	.align 2
gUnknown_085963A0:: @ 85963A0
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810EA4C

	.align 2
gUnknown_085963B8:: @ 85963B8
	.2byte 0x0000, 0x0001, 0x0008, 0x0001, 0x0010, 0x0001, 0x0008, 0x0041
	.2byte 0x0000, 0x0041, 0xffff, 0x0000

	.align 2
gUnknown_085963D0:: @ 85963D0
	.4byte gUnknown_085963B8

	.align 2
gUnknown_085963D4:: @ 85963D4
	spr_template ANIM_TAG_WHIRLWIND_LINES, ANIM_TAG_WHIRLWIND_LINES, gUnknown_08524934, gUnknown_085963D0, NULL, gDummySpriteAffineAnimTable, sub_810EAA0

	.align 2
gUnknown_085963EC:: @ 85963EC
	.2byte 0x0010, 0x0100, 0x0000, 0x0000, 0x0028, 0x0000, 0x0600, 0x0000
	.2byte 0x0000, 0xffe0, 0x0500, 0x0000, 0xffec, 0x0000, 0x0700, 0x0000
	.2byte 0xffec, 0xffec, 0x0500, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859641C:: @ 859641C
	.4byte gUnknown_085963EC

	.align 2
gUnknown_08596420:: @ 8596420
	spr_template ANIM_TAG_ROUND_SHADOW, ANIM_TAG_ROUND_SHADOW, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_0859641C, sub_810EC34

	.align 2
gUnknown_08596438:: @ 8596438
	.2byte 0x00a0, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596448:: @ 8596448
	.4byte gUnknown_08596438

	.align 2
gUnknown_0859644C:: @ 859644C
	spr_template ANIM_TAG_ROUND_SHADOW, ANIM_TAG_ROUND_SHADOW, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_08596448, sub_810EC94

	.align 2
gUnknown_08596464:: @ 8596464
	.2byte 0x0010, 0x0100, 0x0000, 0x0000, 0x0028, 0x0000, 0x0600, 0x0000
	.2byte 0x0000, 0xffe0, 0x0500, 0x0000, 0xfff0, 0x0020, 0x0a00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859648C:: @ 859648C
	.4byte gUnknown_08596464

	.align 2
gUnknown_08596490:: @ 8596490
	spr_template ANIM_TAG_ROUND_SHADOW, ANIM_TAG_ROUND_SHADOW, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_0859648C, sub_810ED28

	.align 2
gUnknown_085964A8:: @ 85964A8
	.2byte 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0c00, 0x0000
	.2byte 0x0000, 0xffe0, 0x0b00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085964C8:: @ 85964C8
	.4byte gUnknown_085964A8

	.align 2
gUnknown_085964CC:: @ 85964CC
	spr_template ANIM_TAG_SPLASH, ANIM_TAG_SPLASH, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810EE14

	.align 2
gUnknown_085964E4:: @ 85964E4
	spr_template ANIM_TAG_SWEAT_BEAD, ANIM_TAG_SWEAT_BEAD, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810EEF8

	.align 2
gUnknown_085964FC:: @ 85964FC
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F004

	.align 2
gUnknown_08596514:: @ 8596514
	spr_template ANIM_TAG_BIRD, ANIM_TAG_BIRD, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F084

	.align 2
gUnknown_0859652C:: @ 859652C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfffe, 0xfffe, 0x78f6, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596544:: @ 8596544
	.4byte gUnknown_0859652C

	.align 2
gUnknown_08596548:: @ 8596548
	spr_template ANIM_TAG_SPIRAL, ANIM_TAG_SPIRAL, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08596544, sub_80A77C8

	.align 2
gUnknown_08596560:: @ 8596560
	spr_template ANIM_TAG_GREEN_LIGHT_WALL, ANIM_TAG_GREEN_LIGHT_WALL, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F1EC

	.align 2
gUnknown_08596578:: @ 8596578
	spr_template ANIM_TAG_BLUE_LIGHT_WALL, ANIM_TAG_BLUE_LIGHT_WALL, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F1EC

	.align 2
gUnknown_08596590:: @ 8596590
	spr_template ANIM_TAG_RED_LIGHT_WALL, ANIM_TAG_RED_LIGHT_WALL, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F1EC

	.align 2
gUnknown_085965A8:: @ 85965A8
	spr_template ANIM_TAG_GRAY_LIGHT_WALL, ANIM_TAG_GRAY_LIGHT_WALL, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F1EC

	.align 2
gUnknown_085965C0:: @ 85965C0
	spr_template ANIM_TAG_ORANGE_LIGHT_WALL, ANIM_TAG_ORANGE_LIGHT_WALL, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810F1EC

	.align 2
gUnknown_085965D8:: @ 85965D8
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085965F0:: @ 85965F0
	.4byte gUnknown_085965D8

	.align 2
gUnknown_085965F4:: @ 85965F4
	spr_template ANIM_TAG_SPARKLE_4, ANIM_TAG_SPARKLE_4, gUnknown_08524914, gUnknown_085965F0, NULL, gDummySpriteAffineAnimTable, sub_810F58C

	.align 2
gUnknown_0859660C:: @ 859660C
	.2byte 0x0000, 0x0005, 0x0004, 0x0005, 0x0008, 0x0005, 0x000c, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08596620:: @ 8596620
	.4byte gUnknown_0859660C

	.align 2
gUnknown_08596624:: @ 8596624
	spr_template ANIM_TAG_SPARKLE_3, ANIM_TAG_SPARKLE_3, gUnknown_0852490C, gUnknown_08596620, NULL, gDummySpriteAffineAnimTable, sub_810F58C

	.align 2
gUnknown_0859663C:: @ 859663C
	spr_template ANIM_TAG_GOLD_RING, ANIM_TAG_GOLD_RING, gUnknown_08524954, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TranslateAnimSpriteToTargetMonLocation

	.align 2
gUnknown_08596654:: @ 8596654
	.2byte 0x0008, 0x007c, 0x0010, 0x0045, 0x0008, 0x0045, 0x0000, 0x0045
	.2byte 0x0008, 0x0056, 0xfffd, 0x0000, 0x0010, 0x0045, 0x0008, 0x0045
	.2byte 0x0000, 0x0045, 0x0008, 0x0045, 0xfffd, 0x0001, 0x0008, 0x0056
	.2byte 0x0018, 0x0043, 0x0020, 0x0043, 0x0028, 0x0056, 0xffff, 0x0000

	.align 2
gUnknown_08596694:: @ 8596694
	.2byte 0x0008, 0x003c, 0x0010, 0x0005, 0x0008, 0x0005, 0x0000, 0x0005
	.2byte 0x0008, 0x0016, 0xfffd, 0x0000, 0x0010, 0x0005, 0x0008, 0x0005
	.2byte 0x0000, 0x0005, 0x0008, 0x0005, 0xfffd, 0x0001, 0x0008, 0x0016
	.2byte 0x0018, 0x0003, 0x0020, 0x0003, 0x0028, 0x0016, 0xffff, 0x0000

	.align 2
gUnknown_085966D4:: @ 85966D4
	.4byte gUnknown_08596654
	.4byte gUnknown_08596694

	.align 2
gUnknown_085966DC:: @ 85966DC
	spr_template ANIM_TAG_BENT_SPOON, ANIM_TAG_BENT_SPOON, gUnknown_08524954, gUnknown_085966D4, NULL, gDummySpriteAffineAnimTable, sub_810F634

	.align 2
gUnknown_085966F4:: @ 85966F4
	.2byte 0x0000, 0x0006, 0x0010, 0x0006, 0x0020, 0x0006, 0x0030, 0x0006
	.2byte 0x0040, 0x0006, 0x0050, 0x0006, 0x0060, 0x0012, 0xffff, 0x0000

	.align 2
gUnknown_08596714:: @ 8596714
	.4byte gUnknown_085966F4

	.align 2
gUnknown_08596718:: @ 8596718
	.2byte 0x0000, 0x0000, 0x0404, 0x0000, 0x0000, 0x0000, 0x08fc, 0x0000
	.2byte 0x0000, 0x0000, 0x0404, 0x0000, 0x7ffd, 0x0002, 0x0000, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596740:: @ 8596740
	.4byte gUnknown_08596718

	.align 2
gUnknown_08596744:: @ 8596744
	spr_template ANIM_TAG_AMNESIA, ANIM_TAG_AMNESIA, gUnknown_08524914, gUnknown_08596714, NULL, gDummySpriteAffineAnimTable, sub_810F6B0

	.align 2
gUnknown_0859675C:: @ 859675C
	.2byte 0xfff8, 0x000a, 0x1000, 0x0000, 0x0012, 0xffee, 0x1000, 0x0000
	.2byte 0xffec, 0x0010, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859677C:: @ 859677C
	.2byte 0x0040, 0xfffc, 0x1400, 0x0000, 0x0000, 0x0000, 0xc800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596794:: @ 8596794
	spr_template ANIM_TAG_HOLLOW_ORB, ANIM_TAG_HOLLOW_ORB, gUnknown_08524A2C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085967AC:: @ 85967AC
	spr_template ANIM_TAG_X_SIGN, ANIM_TAG_X_SIGN, gUnknown_0852491C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_810FBA8

	.align 2
gUnknown_085967C4:: @ 85967C4
	.2byte 0xfff8, 0xfff8, 0x0800, 0x0000, 0x0008, 0x0008, 0x0800, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085967DC:: @ 85967DC
	.2byte 0x00f0, 0x00f0, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0600, 0x0000
	.2byte 0x0008, 0x0008, 0x0800, 0x0000, 0xfff8, 0xfff8, 0x0200, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08596804:: @ 8596804
	.2byte 0x00d0, 0x00d0, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0400, 0x0000
	.2byte 0x0008, 0x0008, 0x0800, 0x0000, 0xfff8, 0xfff8, 0x0400, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_0859682C:: @ 859682C
	.2byte 0x00b0, 0x00b0, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0200, 0x0000
	.2byte 0x0008, 0x0008, 0x0800, 0x0000, 0xfff8, 0xfff8, 0x0600, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08596854:: @ 8596854
	.4byte gUnknown_085967C4
	.4byte gUnknown_085967DC
	.4byte gUnknown_08596804
	.4byte gUnknown_0859682C

	.align 2
gUnknown_08596864:: @ 8596864
	spr_template ANIM_TAG_BLUEGREEN_ORB, ANIM_TAG_BLUEGREEN_ORB, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_08596854, sub_810FDF0

	.align 2
gUnknown_0859687C:: @ 859687C
	.2byte 0x0020, 0x0020, 0x0000, 0x0000, 0x0004, 0x0004, 0x7800, 0x0000
	.2byte 0x7fff, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08596894:: @ 8596894
	.4byte gUnknown_0859687C

	.align 2
gUnknown_08596898:: @ 8596898
	spr_template ANIM_TAG_WHITE_CIRCLE_OF_LIGHT, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08596894, sub_80A77C8

	.align 2
gUnknown_085968B0:: @ 85968B0
	.2byte 0x0020, 0x0020, 0x0000, 0x0000, 0x0010, 0x0010, 0x1100, 0x0000
	.2byte 0x7ffd, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0a00, 0x0000
	.2byte 0x0008, 0x0008, 0x0a00, 0x0000, 0x7ffd, 0x0004, 0x0000, 0x0000
	.2byte 0x7ffd, 0x0000, 0x0000, 0x0000, 0xfff0, 0xfff0, 0x0500, 0x0000
	.2byte 0x0010, 0x0010, 0x0500, 0x0000, 0x7ffd, 0x0007, 0x0000, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596908:: @ 8596908
	.2byte 0xffec, 0x0018, 0x0f00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596918:: @ 8596918
	.4byte gUnknown_085968B0
	.4byte gUnknown_08596908

	.align 2
gUnknown_08596920:: @ 8596920
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08596918, sub_8110240

	.align 2
gUnknown_08596938:: @ 8596938
	.2byte 0x0100, 0x0100, 0x001e, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596948:: @ 8596948
	.2byte 0x0100, 0x0100, 0x009d, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596958:: @ 8596958
	.2byte 0x0100, 0x0100, 0x005e, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596968:: @ 8596968
	.4byte gUnknown_08596938
	.4byte gUnknown_08596948
	.4byte gUnknown_08596958

	.align 2
gUnknown_08596974:: @ 8596974
	spr_template ANIM_TAG_HORN_HIT_2, ANIM_TAG_HORN_HIT_2, gUnknown_085249F4, gDummySpriteAnimTable, NULL, gUnknown_08596968, sub_8110368

	.align 2
gUnknown_0859698C:: @ 859698C
	.2byte 0x0000, 0x0000, 0x01df, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0859699C:: @ 859699C
	.2byte 0x0000, 0x0000, 0x0160, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085969AC:: @ 85969AC
	.2byte 0x0000, 0x0000, 0x01a0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085969BC:: @ 85969BC
	.4byte gUnknown_0859698C
	.4byte gUnknown_0859699C
	.4byte gUnknown_085969AC

	.align 2
gUnknown_085969C8:: @ 85969C8
	spr_template ANIM_TAG_NEEDLE, ANIM_TAG_NEEDLE, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_085969BC, sub_8110438

	.align 2
gUnknown_085969E0:: @ 85969E0
	spr_template ANIM_TAG_WEB_THREAD, ANIM_TAG_WEB_THREAD, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81104E4

	.align 2
gUnknown_085969F8:: @ 85969F8
	spr_template ANIM_TAG_STRING, ANIM_TAG_STRING, gUnknown_0852493C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81105B4

	.align 2
gUnknown_08596A10:: @ 8596A10
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0006, 0x0006, 0x0100, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08596A28:: @ 8596A28
	.4byte gUnknown_08596A10

	.align 2
gUnknown_08596A2C:: @ 8596A2C
	spr_template ANIM_TAG_SPIDER_WEB, ANIM_TAG_SPIDER_WEB, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_08596A28, sub_811067C

	.align 2
gLinearStingerSpriteTemplate:: @ 8596A44
	spr_template ANIM_TAG_NEEDLE, ANIM_TAG_NEEDLE, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8110720

	.align 2
gPinMissileSpriteTemplate:: @ 8596A5C
	spr_template ANIM_TAG_NEEDLE, ANIM_TAG_NEEDLE, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8110850

	.align 2
gIcicleSpearSpriteTemplate:: @ 8596A74
	spr_template ANIM_TAG_ICICLE_SPEAR, ANIM_TAG_ICICLE_SPEAR, gUnknown_08524974, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8110850

	.align 2
gUnknown_08596A8C:: @ 8596A8C
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0008, 0x0008, 0x1200, 0x0000
	.2byte 0x7ffd, 0x0000, 0x0000, 0x0000, 0xfffb, 0xfffb, 0x0800, 0x0000
	.2byte 0x0005, 0x0005, 0x0800, 0x0000, 0x7ffd, 0x0005, 0x0000, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596AC4:: @ 8596AC4
	.4byte gUnknown_08596A8C

	.align 2
gUnknown_08596AC8:: @ 8596AC8
	spr_template ANIM_TAG_CIRCLE_OF_LIGHT, ANIM_TAG_CIRCLE_OF_LIGHT, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08596AC4, sub_8110994

	.align 2
gUnknown_08596AE0:: @ 8596AE0
	.2byte 0x0020, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596AE8:: @ 8596AE8
	.2byte 0x0030, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596AF0:: @ 8596AF0
	.2byte 0x0040, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596AF8:: @ 8596AF8
	.4byte gUnknown_08596AE0
	.4byte gUnknown_08596AE8
	.4byte gUnknown_08596AF0

	.align 2
gUnknown_08596B04:: @ 8596B04
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gUnknown_08596AF8, NULL, gDummySpriteAffineAnimTable, sub_81109F0

	.align 2
gUnknown_08596B1C:: @ 8596B1C
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gUnknown_08596AF8, NULL, gDummySpriteAffineAnimTable, sub_8110AB4

	.align 2
gUnknown_08596B34:: @ 8596B34
	spr_template ANIM_TAG_MUD_SAND, ANIM_TAG_MUD_SAND, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8110B38

	.align 2
gUnknown_08596B4C:: @ 8596B4C
	.2byte 0x00c0, 0x00c0, 0x0000, 0x0000, 0x0002, 0xfffd, 0x0500, 0x0000
	.2byte 0xfffe, 0x0003, 0x0500, 0x0000, 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_08596B6C:: @ 8596B6C
	.4byte gUnknown_08596B4C

	.align 2
gUnknown_08596B70:: @ 8596B70
	spr_template ANIM_TAG_WATER_ORB, ANIM_TAG_WATER_ORB, gUnknown_08524A8C, gUnknown_085950E0, NULL, gUnknown_08596B6C, sub_8110B38

	.align 2
gUnknown_08596B88:: @ 8596B88
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_085954D0, NULL, gDummySpriteAffineAnimTable, sub_8110B38

	.align 2
gBattleAnimSpriteTemplate_8596BA0:: @ 8596BA0
	spr_template ANIM_TAG_FLYING_DIRT, ANIM_TAG_FLYING_DIRT, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8110E4C

	.align 2
gUnknown_08596BB8:: @ 8596BB8
	.2byte 0x00f0, 0x4009, 0x0010, 0x4089

	.align 2
gUnknown_08596BC0:: @ 8596BC0
	.2byte 0x0002, 0x0000

	.align 2
gUnknown_08596BC4:: @ 8596BC4
	.4byte gUnknown_08596BB8

	.align 2
gUnknown_08596BC8:: @ 8596BC8
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596BD0:: @ 8596BD0
	.2byte 0x0010, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596BD8:: @ 8596BD8
	.2byte 0x0020, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596BE0:: @ 8596BE0
	.2byte 0x0030, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596BE8:: @ 8596BE8
	.2byte 0x0040, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596BF0:: @ 8596BF0
	.2byte 0x0050, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08596BF8:: @ 8596BF8
	.4byte gUnknown_08596BC8
	.4byte gUnknown_08596BD0

	.align 2
gUnknown_08596C00:: @ 8596C00
	.4byte gUnknown_08596BD8
	.4byte gUnknown_08596BE0

	.align 2
gUnknown_08596C08:: @ 8596C08
	.4byte gUnknown_08596BE8
	.4byte gUnknown_08596BF0

	.align 2
gUnknown_08596C10:: @ 8596C10
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gUnknown_08596BF8, NULL, gDummySpriteAffineAnimTable, sub_8110F30

	.align 2
gUnknown_08596C28:: @ 8596C28
	spr_template ANIM_TAG_MUD_SAND, ANIM_TAG_MUD_SAND, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_811131C

	.align 2
gUnknown_08596C40:: @ 8596C40
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_811131C

	.align 2
gUnknown_08596C58:: @ 8596C58
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gUnknown_08596BF8, NULL, gDummySpriteAffineAnimTable, sub_8111388

	.align 2
gUnknown_08596C70:: @ 8596C70
	.2byte 0x0000, 0x0000, 0x05fb, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596C80:: @ 8596C80
	.2byte 0x0000, 0x0000, 0x0505, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596C90:: @ 8596C90
	.4byte gUnknown_08596C70
	.4byte gUnknown_08596C80

	.align 2
gUnknown_08596C98:: @ 8596C98
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524974, gUnknown_08596BF8, NULL, gUnknown_08596C90, sub_8111418

	.align 2
gUnknown_08596CB0:: @ 8596CB0
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524974, gUnknown_08596BF8, NULL, gUnknown_08596C90, sub_8111444

	.align 2
gUnknown_08596CC8:: @ 8596CC8
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gUnknown_08596C08, NULL, gUnknown_08596C90, sub_80FF268

	.align 2
gUnknown_08596CE0:: @ 8596CE0
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524974, gUnknown_08596C00, NULL, gUnknown_08596C90, sub_80A8EE4

	.align 2
gUnknown_08596CF8:: @ 8596CF8
	.2byte 0x001e, 0x001e, 0x050a, 0x0000, 0xffe2, 0xffe2, 0x050a, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596D10:: @ 8596D10
	.4byte gUnknown_08596CF8

	.align 2
gUnknown_08596D14:: @ 8596D14
	spr_template ANIM_TAG_YELLOW_BALL, ANIM_TAG_YELLOW_BALL, gUnknown_085249CC, gDummySpriteAnimTable, NULL, gUnknown_08596D10, sub_811160C

	.align 2
gUnknown_08596D2C:: @ 8596D2C
	spr_template ANIM_TAG_YELLOW_BALL, ANIM_TAG_YELLOW_BALL, gUnknown_08524A2C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81117F4

	.align 2
gUnknown_08596D44:: @ 8596D44
	.2byte 0x0000, 0x0000, 0x010a, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596D54:: @ 8596D54
	.4byte gUnknown_08596D44

	.align 2
gUnknown_08596D58:: @ 8596D58
	spr_template ANIM_TAG_SHADOW_BALL, ANIM_TAG_SHADOW_BALL, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_08596D54, sub_81119E0

	.align 2
gUnknown_08596D70:: @ 8596D70
	.2byte 0x0000, 0x0002, 0x0008, 0x0002, 0x0010, 0x0002, 0x0018, 0x0002
	.2byte 0x0020, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_08596D88:: @ 8596D88
	.4byte gUnknown_08596D70

	.align 2
gUnknown_08596D8C:: @ 8596D8C
	spr_template ANIM_TAG_LICK, ANIM_TAG_LICK, gUnknown_08524954, gUnknown_08596D88, NULL, gDummySpriteAffineAnimTable, sub_8111B9C

	.align 2
gUnknown_08596DA4:: @ 8596DA4
	.2byte 0x0200, 0x0200, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596DB4:: @ 8596DB4
	.4byte gUnknown_08596DA4

	.align 2
gUnknown_08596DB8:: @ 8596DB8
	spr_template ANIM_TAG_WHITE_SHADOW, ANIM_TAG_WHITE_SHADOW, gUnknown_08524A5C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8112264

	.align 2
gUnknown_08596DD0:: @ 8596DD0
	spr_template ANIM_TAG_NAIL, ANIM_TAG_NAIL, gUnknown_08524A54, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81129F0

	.align 2
gBattleAnimSpriteTemplate_8596DE8:: @ 8596DE8
	spr_template ANIM_TAG_GHOSTLY_SPIRIT, ANIM_TAG_GHOSTLY_SPIRIT, gUnknown_08524A34, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8112B78

	.align 2
gBattleAnimSpriteTemplate_8596E00:: @ 8596E00
	spr_template ANIM_TAG_DEVIL, ANIM_TAG_DEVIL, gUnknown_08524A34, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8112B78

	.align 2
gUnknown_08596E18:: @ 8596E18
	.2byte 0x0000, 0x0004, 0x0008, 0x0004, 0x0010, 0x0004, 0x0018, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_08596E2C:: @ 8596E2C
	.4byte gUnknown_08596E18

	.align 2
gUnknown_08596E30:: @ 8596E30
	spr_template ANIM_TAG_PURPLE_FLAME, ANIM_TAG_PURPLE_FLAME, gUnknown_08524A74, gUnknown_08596E2C, NULL, gDummySpriteAffineAnimTable, sub_8112E9C

	.align 2
gUnknown_08596E48:: @ 8596E48
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8112F60

	.align 2
gUnknown_08596E60:: @ 8596E60
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004
	.2byte 0x0040, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_08596E78:: @ 8596E78
	.4byte gUnknown_08596E60

	.align 2
gBattleAnimSpriteTemplate_8596E7C:: @ 8596E7C
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08596E78, NULL, gDummySpriteAffineAnimTable, sub_8113064

	.align 2
gUnknown_08596E94:: @ 8596E94
	.2byte 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_08596EA4:: @ 8596EA4
	.2byte 0x0010, 0x00c3, 0x0020, 0x00c3, 0x0030, 0x00c3, 0xfffe, 0x0000

	.align 2
gUnknown_08596EB4:: @ 8596EB4
	.4byte gUnknown_08596E94
	.4byte gUnknown_08596EA4

	.align 2
gUnknown_08596EBC:: @ 8596EBC
	.2byte 0x0050, 0x0050, 0x007f, 0x0000, 0x000d, 0x000d, 0x6400, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596ED4:: @ 8596ED4
	.2byte 0x0050, 0x0050, 0x0000, 0x0000, 0x000d, 0x000d, 0x6400, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596EEC:: @ 8596EEC
	.4byte gUnknown_08596EBC
	.4byte gUnknown_08596ED4

	.align 2
gUnknown_08596EF4:: @ 8596EF4
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_085249D4, gUnknown_08596EB4, NULL, gUnknown_08596EEC, sub_8113224

	.align 2
gUnknown_08596F0C:: @ 8596F0C
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0030, 0x0005
	.2byte 0x0040, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_08596F24:: @ 8596F24
	.4byte gUnknown_08596F0C

	.align 2
gUnknown_08596F28:: @ 8596F28
	spr_template ANIM_TAG_FIRE_PLUME, ANIM_TAG_FIRE_PLUME, gUnknown_08524914, gUnknown_08596F24, NULL, gDummySpriteAffineAnimTable, sub_81131B4

	.align 2
gUnknown_08596F40:: @ 8596F40
	.2byte 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_08596F50:: @ 8596F50
	.4byte gUnknown_08596F40
	.4byte gUnknown_08596F40

	.align 2
gUnknown_08596F58:: @ 8596F58
	.2byte 0x0064, 0x0064, 0x017f, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596F68:: @ 8596F68
	.2byte 0x0064, 0x0064, 0x0100, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596F78:: @ 8596F78
	.4byte gUnknown_08596F58
	.4byte gUnknown_08596F68

	.align 2
gUnknown_08596F80:: @ 8596F80
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_085249D4, gUnknown_08596F50, NULL, gUnknown_08596F78, sub_8113224

	.align 2
gUnknown_08596F98:: @ 8596F98
	spr_template ANIM_TAG_HOLLOW_ORB, ANIM_TAG_HOLLOW_ORB, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8113250

	.align 2
gUnknown_08596FB0:: @ 8596FB0
	spr_template ANIM_TAG_SMALL_EMBER, ANIM_TAG_SMALL_EMBER, gUnknown_08524914, gUnknown_08596E78, NULL, gDummySpriteAffineAnimTable, sub_81135EC

	.align 2
gUnknown_08596FC8:: @ 8596FC8
	spr_template ANIM_TAG_TIED_BAG, ANIM_TAG_TIED_BAG, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81138D4

	.align 2
gUnknown_08596FE0:: @ 8596FE0
	.2byte 0x0000, 0x0000, 0x0100, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08596FF0:: @ 8596FF0
	.2byte 0x0000, 0x0000, 0x0120, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597000:: @ 8597000
	.2byte 0x0000, 0x0000, 0x0140, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597010:: @ 8597010
	.2byte 0x0000, 0x0000, 0x0160, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597020:: @ 8597020
	.2byte 0x0000, 0x0000, 0x0180, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597030:: @ 8597030
	.2byte 0x0000, 0x0000, 0x01a0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597040:: @ 8597040
	.2byte 0x0000, 0x0000, 0x01c0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597050:: @ 8597050
	.2byte 0x0000, 0x0000, 0x01e0, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597060:: @ 8597060
	.4byte gUnknown_08596FE0
	.4byte gUnknown_08596FF0
	.4byte gUnknown_08597000
	.4byte gUnknown_08597010
	.4byte gUnknown_08597020
	.4byte gUnknown_08597030
	.4byte gUnknown_08597040
	.4byte gUnknown_08597050

	.align 2
gUnknown_08597080:: @ 8597080
	spr_template ANIM_TAG_SHARP_TEETH, ANIM_TAG_SHARP_TEETH, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08597060, sub_81139DC

	.align 2
gUnknown_08597098:: @ 8597098
	spr_template ANIM_TAG_CLAMP, ANIM_TAG_CLAMP, gUnknown_08524A9C, gDummySpriteAnimTable, NULL, gUnknown_08597060, sub_81139DC

	.align 2
gUnknown_085970B0:: @ 85970B0
	.2byte 0x00c0, 0x00c0, 0x0050, 0x0000, 0x0000, 0x0000, 0x08fe, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085970C8:: @ 85970C8
	.2byte 0x00c0, 0x00c0, 0x00b0, 0x0000, 0x0000, 0x0000, 0x0802, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085970E0:: @ 85970E0
	.4byte gUnknown_085970B0
	.4byte gUnknown_085970C8

	.align 2
gUnknown_085970E8:: @ 85970E8
	spr_template ANIM_TAG_SMALL_BUBBLES, ANIM_TAG_SMALL_BUBBLES, gUnknown_0852496C, gDummySpriteAnimTable, NULL, gUnknown_085970E0, sub_8113A90

	.align 2
gUnknown_08597100:: @ 8597100
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0x0030, 0x0004
	.2byte 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08597118:: @ 8597118
	.2byte 0x0000, 0x0044, 0x0010, 0x0044, 0x0020, 0x0044, 0x0030, 0x0044
	.2byte 0x0040, 0x0044, 0xffff, 0x0000

	.align 2
gUnknown_08597130:: @ 8597130
	.4byte gUnknown_08597100
	.4byte gUnknown_08597118

	.align 2
gBattleAnimSpriteTemplate_8597138:: @ 8597138
	spr_template ANIM_TAG_CLAW_SLASH, ANIM_TAG_CLAW_SLASH, gUnknown_08524914, gUnknown_08597130, NULL, gDummySpriteAffineAnimTable, sub_81144BC

	.align 2
gUnknown_08597150:: @ 8597150
	.2byte 0x0000, 0x0000, 0x010f, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597160:: @ 8597160
	.2byte 0x0000, 0x0000, 0x0114, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597170:: @ 8597170
	.4byte gUnknown_08597150

	.align 2
gUnknown_08597174:: @ 8597174
	.4byte gUnknown_08597160

	.align 2
gUnknown_08597178:: @ 8597178
	spr_template ANIM_TAG_BONE, ANIM_TAG_BONE, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_08597170, sub_8114994

	.align 2
gUnknown_08597190:: @ 8597190
	spr_template ANIM_TAG_BONE, ANIM_TAG_BONE, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_08597174, sub_8114A7C

	.align 2
gUnknown_085971A8:: @ 85971A8
	spr_template ANIM_TAG_MUD_SAND, ANIM_TAG_MUD_SAND, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8114AF0

	.align 2
gUnknown_085971C0:: @ 85971C0
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085971C8:: @ 85971C8
	.4byte gUnknown_085971C0

	.align 2
gUnknown_085971CC:: @ 85971CC
	spr_template ANIM_TAG_MUD_SAND, ANIM_TAG_MUD_SAND, gUnknown_0852490C, gUnknown_085971C8, NULL, gDummySpriteAffineAnimTable, sub_8114AF0

	.align 2
gUnknown_085971E4:: @ 85971E4
	spr_template ANIM_TAG_MUD_SAND, ANIM_TAG_MUD_SAND, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8114B80

	.align 2
gUnknown_085971FC:: @ 85971FC
	spr_template ANIM_TAG_MUD_SAND, ANIM_TAG_MUD_SAND, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81151A0

	.align 2
gUnknown_08597214:: @ 8597214
	spr_template ANIM_TAG_DIRT_MOUND, ANIM_TAG_DIRT_MOUND, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8115244

	.align 2
gUnknown_0859722C:: @ 859722C
	.2byte 0x0000, 0x0008, 0x0004, 0x0008, 0x0000, 0x0048, 0x0008, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_08597240:: @ 8597240
	.2byte 0x0000, 0x0048, 0x0004, 0x0008, 0x0000, 0x0008, 0x0008, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_08597254:: @ 8597254
	.4byte gUnknown_0859722C
	.4byte gUnknown_08597240

	.align 2
gConfusionDuckSpriteTemplate:: @ 859725C
	spr_template ANIM_TAG_DUCK, ANIM_TAG_DUCK, gUnknown_0852490C, gUnknown_08597254, NULL, gDummySpriteAffineAnimTable, sub_811572C

	.align 2
gSimplePaletteBlendSpriteTemplate:: @ 8597274
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81157FC

	.align 2
gComplexPaletteBlendSpriteTemplate:: @ 859728C
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81158A4

	.align 2
gUnknown_085972A4:: @ 85972A4
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_085972BC:: @ 85972BC
	.4byte gUnknown_085972A4

	.align 2
gUnknown_085972C0:: @ 85972C0
	spr_template ANIM_TAG_SPARKLE_4, ANIM_TAG_SPARKLE_4, gUnknown_08524914, gUnknown_085972BC, NULL, gDummySpriteAffineAnimTable, sub_81159B4

	.align 2
gBattleAnimSpriteTemplate_85972D8:: @ 85972D8
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81160A4

	.align 2
gUnknown_085972F0:: @ 85972F0
	.2byte 0x0000, 0x0000, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597300:: @ 8597300
	.2byte 0x00d8, 0x00d8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597318:: @ 8597318
	.2byte 0x00b0, 0x00b0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597330:: @ 8597330
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08597348:: @ 8597348
	.4byte gUnknown_085972F0
	.4byte gUnknown_08597300
	.4byte gUnknown_08597318
	.4byte gUnknown_08597330

	.align 2
gBasicHitSplatSpriteTemplate:: @ 8597358
	spr_template ANIM_TAG_IMPACT, ANIM_TAG_IMPACT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_8116388

	.align 2
gBattleAnimSpriteTemplate_8597370:: @ 8597370
	spr_template ANIM_TAG_IMPACT, ANIM_TAG_IMPACT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_8116420

	.align 2
gUnknown_08597388:: @ 8597388
	spr_template ANIM_TAG_WATER_IMPACT, ANIM_TAG_WATER_IMPACT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_8116388

	.align 2
gUnknown_085973A0:: @ 85973A0
	spr_template ANIM_TAG_IMPACT, ANIM_TAG_IMPACT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_8116458

	.align 2
gBattleAnimSpriteTemplate_85973B8:: @ 85973B8
	spr_template ANIM_TAG_IMPACT, ANIM_TAG_IMPACT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_81164F0

	.align 2
gUnknown_085973D0:: @ 85973D0
	spr_template ANIM_TAG_CROSS_IMPACT, ANIM_TAG_CROSS_IMPACT, gUnknown_08524A34, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8116560

	.align 2
gUnknown_085973E8:: @ 85973E8
	spr_template ANIM_TAG_IMPACT, ANIM_TAG_IMPACT, gUnknown_08524974, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_81165A8

	.align 2
gUnknown_08597400:: @ 8597400
	spr_template ANIM_TAG_IMPACT, ANIM_TAG_IMPACT, gUnknown_08524A94, gDummySpriteAnimTable, NULL, gUnknown_08597348, sub_81163D0

gUnknown_08597418:: @ 8597418
	.2byte 0x7fff

gUnknown_0859741A:: @ 859741A
	.byte 0x08, 0x0a, 0x0c, 0x0e

gUnknown_0859741E:: @ 859741E
	.byte 0x08, 0x0a, 0x0c, 0x0e

	.align 2
gUnknown_08597424:: @ 8597424
	.4byte task_battle_intro_80BC47C
	.4byte task_battle_intro_80BC47C
	.4byte task00_battle_intro_80BC6C8
	.4byte task00_battle_intro_80BC6C8
	.4byte task00_battle_intro_80BC6C8
	.4byte task_battle_intro_80BC47C
	.4byte task_battle_intro_80BC47C
	.4byte task_battle_intro_80BC47C
	.4byte task_battle_intro_anim
	.4byte task_battle_intro_anim
