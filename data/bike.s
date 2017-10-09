	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0859744C:: @ 859744C
	.4byte sub_8119224
	.4byte sub_8119238
	.4byte sub_8119280
	.4byte sub_8119344

	.align 2
gUnknown_0859745C:: @ 859745C
	.4byte PlayerGoSpeed0
	.4byte PlayerGoSpeed1
	.4byte PlayerGoSpeed3

	.align 2
gUnknown_08597468:: @ 8597468
	.4byte sub_81197E4
	.4byte sub_81197F4
	.4byte sub_8119830
	.4byte sub_81198C0
	.4byte sub_81198FC
	.4byte sub_8119938
	.4byte sub_8119974
	.4byte sub_81199B0
	.4byte sub_8119A24
	.4byte sub_8119A94
	.4byte sub_8119AA4
	.4byte sub_8119B34
	.4byte sub_8119BC4

	.align 2
gUnknown_0859749C:: @ 859749C
	.4byte CheckMovementInputAcroBikeNormal
	.4byte CheckMovementInputAcroBikeChangingDirection
	.4byte CheckMovementInputAcroBikeStandingWheelie
	.4byte CheckMovementInputAcroBikeBunnyHop
	.4byte CheckMovementInputAcroBikeMovingWheelie
	.4byte CheckMovementInputAcroBikeUnknownMode5
	.4byte CheckMovementInputAcroBikeUnknownMode6

	.align 2
gUnknown_085974B8:: @ 85974B8
	.2byte 0x0001, 0x0002, 0x0004

	.align 1
gUnknown_085974BE:: @ 85974BE
	.2byte 0x0004

	.align 2
gUnknown_085974C0:: @ 85974C0
	.4byte 0x00000001, 0x00000002, 0x0000000f, 0x0000000f, gUnknown_085974BE, gUnknown_085974BE, 0x00000001
    .4byte 0x00000002, 0x00000002, 0x0000000f, 0x0000000f, gUnknown_085974BE, gUnknown_085974BE, 0x00000002
    .4byte 0x00000003, 0x00000002, 0x0000000f, 0x0000000f, gUnknown_085974BE, gUnknown_085974BE, 0x00000003
    .4byte 0x00000004, 0x00000002, 0x0000000f, 0x0000000f, gUnknown_085974BE, gUnknown_085974BE, 0x00000004
