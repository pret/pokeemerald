@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0


gUnknown_084973FC:: @ 84973FC
	.4byte MetatileBehavior_IsTrickHouseSlipperyFloor
	.4byte MetatileBehavior_IsIce_2
	.4byte MetatileBehavior_IsWalkSouth
	.4byte MetatileBehavior_IsWalkNorth
	.4byte MetatileBehavior_IsWalkWest
	.4byte MetatileBehavior_IsWalkEast
	.4byte MetatileBehavior_IsSouthwardCurrent
	.4byte MetatileBehavior_IsNorthwardCurrent
	.4byte MetatileBehavior_IsWestwardCurrent
	.4byte MetatileBehavior_IsEastwardCurrent
	.4byte MetatileBehavior_IsSlideSouth
	.4byte MetatileBehavior_IsSlideNorth
	.4byte MetatileBehavior_IsSlideWest
	.4byte MetatileBehavior_IsSlideEast
	.4byte MetatileBehavior_IsWaterfall
	.4byte MetatileBehavior_IsSecretBaseJumpMat
	.4byte MetatileBehavior_IsSecretBaseSpinMat
	.4byte MetatileBehavior_IsMuddySlope

gUnknown_08497444:: @ 8497444
	.4byte ForcedMovement_None
	.4byte ForcedMovement_Slip
	.4byte ForcedMovement_Slip
	.4byte ForcedMovement_WalkSouth
	.4byte ForcedMovement_WalkNorth
	.4byte ForcedMovement_WalkWest
	.4byte ForcedMovement_WalkEast
	.4byte ForcedMovement_PushedSouthByCurrent
	.4byte ForcedMovement_PushedNorthByCurrent
	.4byte ForcedMovement_PushedWestByCurrent
	.4byte ForcedMovement_PushedEastByCurrent
	.4byte ForcedMovement_SlideSouth
	.4byte ForcedMovement_SlideNorth
	.4byte ForcedMovement_SlideWest
	.4byte ForcedMovement_SlideEast
	.4byte ForcedMovement_PushedSouthByCurrent
	.4byte ForcedMovement_0xBB
	.4byte ForcedMovement_0xBC
	.4byte ForcedMovement_MuddySlope

gUnknown_08497490:: @ 8497490
	.4byte PlayerNotOnBikeNotMoving
	.4byte PlayerNotOnBikeTurningInPlace
	.4byte PlayerNotOnBikeMoving

gUnknown_0849749C:: @ 849749C
	.4byte MetatileBehavior_IsBumpySlope
	.4byte MetatileBehavior_IsIsolatedVerticalRail
	.4byte MetatileBehavior_IsIsolatedHorizontalRail
	.4byte MetatileBehavior_IsVerticalRail
	.4byte MetatileBehavior_IsHorizontalRail

gUnknown_084974B0:: @ 84974B0
	.byte 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x00, 0x00, 0x00

gUnknown_084974B8:: @ 84974B8
	.4byte PlayerAvatarTransition_Normal
	.4byte PlayerAvatarTransition_MachBike
	.4byte PlayerAvatarTransition_AcroBike
	.4byte PlayerAvatarTransition_Surfing
	.4byte PlayerAvatarTransition_Underwater
	.4byte PlayerAvatarTransition_ReturnToField
	.4byte PlayerAvatarTransition_Dummy
	.4byte PlayerAvatarTransition_Dummy

gUnknown_084974D8:: @ 84974D8
	.4byte MetatileBehavior_IsSouthArrowWarp
	.4byte MetatileBehavior_IsNorthArrowWarp
	.4byte MetatileBehavior_IsWestArrowWarp
	.4byte MetatileBehavior_IsEastArrowWarp

gUnknown_084974E8:: @ 84974E8
	.byte 0x64, 0x69, 0x65, 0x6a, 0x66, 0x6b, 0x67, 0x6c, 0x6f, 0x70, 0x68, 0x6d, 0x89, 0x8a, 0xbf, 0xc0

gUnknown_084974F8:: @ 84974F8
	.byte 0x00, 0x59, 0x01, 0x5a, 0x3f, 0x5b, 0x02, 0x5c, 0x6f, 0x70, 0x03, 0x5d, 0x89, 0x8a, 0xbf, 0xc0

gUnknown_08497508:: @ 8497508
	.byte 0xe6, 0xe7

gUnknown_0849750A:: @ 849750A
	.byte 0xeb, 0xec

gUnknown_0849750C:: @ 849750C
	.byte 0x00, 0x01, 0x01, 0x02, 0x3f, 0x04, 0x02, 0x08, 0x6f, 0x10, 0x59, 0x01, 0x5a, 0x02, 0x5b, 0x04, 0x5c, 0x08, 0x70, 0x10

gUnknown_08497520:: @ 8497520
	.4byte MetatileBehavior_IsSouthArrowWarp
	.4byte MetatileBehavior_IsNorthArrowWarp
	.4byte MetatileBehavior_IsWestArrowWarp
	.4byte MetatileBehavior_IsEastArrowWarp

gUnknown_08497530:: @ 8497530
	.4byte sub_808C3A4
	.4byte do_boulder_dust
	.4byte sub_808C484

gUnknown_0849753C:: @ 849753C
	.4byte sub_808C544

gUnknown_08497540:: @ 8497540
	.4byte sub_808C61C
	.4byte sub_808C644
	.4byte sub_808C6BC
	.4byte sub_808C6FC

gUnknown_08497550:: @ 8497550
	.byte 3, 4, 2, 1

gUnknown_08497554:: @ 8497554
	.byte 16, 16, 17, 18, 19

	.align 2
gUnknown_0849755C:: @ 849755C
	.4byte fish0
	.4byte fish1
	.4byte fish2
	.4byte fish3
	.4byte fish4
	.4byte fish5
	.4byte fish6
	.4byte fish7
	.4byte fish8
	.4byte fish9
	.4byte fishA_wait_for_a_pressed
	.4byte fishB
	.4byte fishC
	.4byte fishD
	.4byte fishE
	.4byte fishF

gUnknown_0849759C:: @ 849759C
	.2byte 1, 1, 1

gUnknown_084975A2:: @ 84975A2
	.2byte 1, 3, 6

gUnknown_084975A8:: @ 84975A8
	.string "·$"

gUnknown_084975AA:: @ 84975AA
	.2byte 36, 33, 30

gUnknown_084975B0:: @ 84975B0
	.2byte 0, 0
	.2byte 0x28, 10
	.2byte 0x46, 30

gUnknown_084975BC:: @ 84975BC
	.byte 0x01, 0x03, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00

