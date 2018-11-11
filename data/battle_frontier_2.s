#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_08611CB0:: @ 8611CB0
	.4byte gText_BattleTower2
	.4byte gUnknown_085ED164
	.4byte gText_BattleTower2
	.4byte gUnknown_085ED170
	.4byte gText_BattleTower2
	.4byte gUnknown_085ED17C
	.4byte gText_BattleDome
	.4byte gUnknown_085ED164
	.4byte gText_BattlePalace
	.4byte gUnknown_085ED164
	.4byte gText_BattleArena
	.4byte gUnknown_085ED190
	.4byte gText_BattleFactory
	.4byte gUnknown_085ED164
	.4byte gText_BattlePike
	.4byte gUnknown_085ED190
	.4byte gText_BattlePyramid
	.4byte gUnknown_085ED190
	.4byte gText_BattleTower2
	.4byte gUnknown_085ED188

	.align 2
gUnknown_08611D00:: @ 8611D00
	.4byte gUnknown_085EE3B0
	.4byte gUnknown_085EE3B8

	.align 2
gUnknown_08611D08:: @ 8611D08
	.4byte gUnknown_085EE3C4
	.4byte gUnknown_085EE3C4
	.4byte gUnknown_085EE3C4
	.4byte gUnknown_085EE3D4
	.4byte gUnknown_085EE3C4
	.4byte gUnknown_085EE3FC
	.4byte gUnknown_085EE3C4
	.4byte gUnknown_085EE3E8
	.4byte gUnknown_085EE410
	.4byte gUnknown_085EE3C4

	.align 1
gFacilityToBrainTrainerId:: @ 8611D30
	.2byte TRAINER_ANABEL, TRAINER_TUCKER, TRAINER_SPENSER
	.2byte TRAINER_GRETA, TRAINER_NOLAND, TRAINER_LUCY
	.2byte TRAINER_BRANDON

	.align 2
gUnknown_08611D40:: @ 8611D40
	.4byte gText_082C843F
	.4byte gText_082C848B
	.4byte gText_082C8628
	.4byte gText_082C85B4
	.4byte gText_082C8512
	.4byte gText_082C859D
	.4byte gText_082C86C3

	.align 2
gUnknown_08611D5C:: @ 8611D5C
	.4byte gText_082C8458
	.4byte gText_082C84C1
	.4byte gText_082C8662
	.4byte gText_082C85E3
	.4byte gText_082C853B
	.4byte gText_082C85A4
	.4byte gText_082C86FE

	.align 2
gUnknown_08611D78:: @ 8611D78
	.4byte gText_082C846C
	.4byte gText_082C84D0
	.4byte gText_082C8682
	.4byte gText_082C85F5
	.4byte gText_082C8561
	.4byte gText_082C85A9
	.4byte gText_082C8739

	.align 2
gUnknown_08611D94:: @ 8611D94
	.4byte gText_082C8480
	.4byte gText_082C84F7
	.4byte gText_082C86B3
	.4byte gText_082C8611
	.4byte gText_082C8589
	.4byte gText_082C85AE
	.4byte gText_082C877B

	.align 2
gUnknown_08611DB0:: @ 8611DB0
	.4byte gUnknown_08611D40
	.4byte gUnknown_08611D78

	.align 2
gUnknown_08611DB8:: @ 8611DB8
	.4byte gUnknown_08611D5C
	.4byte gUnknown_08611D94

@ 8611DC0
	.include "data/battle_frontier/battle_arena_move_mind_ratings.inc"

	.align 2
gUnknown_08611F24:: @ 8611F24
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0xf0, 0x00, 0x00

	.align 2
gUnknown_08611F2C:: @ 8611F2C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08611F34:: @ 8611F34
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08611F3C:: @ 8611F3C
	.2byte 0x0008, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08611F44:: @ 8611F44
	.2byte 0x000c, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08611F4C:: @ 8611F4C
	.4byte gUnknown_08611F2C
	.4byte gUnknown_08611F34
	.4byte gUnknown_08611F3C
	.4byte gUnknown_08611F44

	.align 2
gUnknown_08611F5C:: @ 8611F5C
	spr_template 0x03e8, 0xffff, gUnknown_08611F24, gUnknown_08611F4C, NULL, gDummySpriteAffineAnimTable, sub_81A5698
