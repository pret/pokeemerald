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
