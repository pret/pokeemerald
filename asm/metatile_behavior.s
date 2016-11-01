	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ShouldDoJumpLandingDustEffect
ShouldDoJumpLandingDustEffect: @ 8088DEC
	movs r0, 0x1
	bx lr
	thumb_func_end ShouldDoJumpLandingDustEffect

	thumb_func_start sub_8088DF0
sub_8088DF0: @ 8088DF0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_08486EFC
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08088E0C
	movs r0, 0
	b _08088E0E
	.pool
_08088E0C:
	movs r0, 0x1
_08088E0E:
	pop {r1}
	bx r1
	thumb_func_end sub_8088DF0

	thumb_func_start MetatileBehavior_IsJumpEast
MetatileBehavior_IsJumpEast: @ 8088E14
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x38
	beq _08088E22
	movs r0, 0
	b _08088E24
_08088E22:
	movs r0, 0x1
_08088E24:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsJumpEast

	thumb_func_start MetatileBehavior_IsJumpWest
MetatileBehavior_IsJumpWest: @ 8088E28
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x39
	beq _08088E36
	movs r0, 0
	b _08088E38
_08088E36:
	movs r0, 0x1
_08088E38:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsJumpWest

	thumb_func_start MetatileBehavior_IsJumpNorth
MetatileBehavior_IsJumpNorth: @ 8088E3C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3A
	beq _08088E4A
	movs r0, 0
	b _08088E4C
_08088E4A:
	movs r0, 0x1
_08088E4C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsJumpNorth

	thumb_func_start MetatileBehavior_IsJumpSouth
MetatileBehavior_IsJumpSouth: @ 8088E50
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	beq _08088E5E
	movs r0, 0
	b _08088E60
_08088E5E:
	movs r0, 0x1
_08088E60:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsJumpSouth

	thumb_func_start sub_8088E64
sub_8088E64: @ 8088E64
	push {lr}
	lsls r0, 24
	movs r1, 0xFE
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _08088E78
	movs r0, 0
	b _08088E7A
_08088E78:
	movs r0, 0x1
_08088E7A:
	pop {r1}
	bx r1
	thumb_func_end sub_8088E64

	thumb_func_start MetatileBehavior_IsSandOrDeepSand
MetatileBehavior_IsSandOrDeepSand: @ 8088E80
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x21
	beq _08088E8E
	cmp r0, 0x6
	bne _08088E92
_08088E8E:
	movs r0, 0x1
	b _08088E94
_08088E92:
	movs r0, 0
_08088E94:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSandOrDeepSand

	thumb_func_start MetatileBehavior_IsDeepSand
MetatileBehavior_IsDeepSand: @ 8088E98
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _08088EA6
	movs r0, 0
	b _08088EA8
_08088EA6:
	movs r0, 0x1
_08088EA8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsDeepSand

	thumb_func_start MetatileBehavior_IsReflective
MetatileBehavior_IsReflective: @ 8088EAC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _08088ECA
	cmp r0, 0x16
	beq _08088ECA
	cmp r0, 0x1A
	beq _08088ECA
	cmp r0, 0x20
	beq _08088ECA
	cmp r0, 0x14
	beq _08088ECA
	cmp r0, 0x2B
	bne _08088ECE
_08088ECA:
	movs r0, 0x1
	b _08088ED0
_08088ECE:
	movs r0, 0
_08088ED0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsReflective

	thumb_func_start MetatileBehavior_IsIce
MetatileBehavior_IsIce: @ 8088ED4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x20
	beq _08088EE2
	movs r0, 0
	b _08088EE4
_08088EE2:
	movs r0, 0x1
_08088EE4:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsIce

	thumb_func_start is_tile_x69_2_warp_door
is_tile_x69_2_warp_door: @ 8088EE8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x69
	beq _08088EF6
	movs r0, 0
	b _08088EF8
_08088EF6:
	movs r0, 0x1
_08088EF8:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x69_2_warp_door

	thumb_func_start sub_8088EFC
sub_8088EFC: @ 8088EFC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8D
	beq _08088F0A
	cmp r0, 0x69
	bne _08088F0E
_08088F0A:
	movs r0, 0x1
	b _08088F10
_08088F0E:
	movs r0, 0
_08088F10:
	pop {r1}
	bx r1
	thumb_func_end sub_8088EFC

	thumb_func_start MetatileBehavior_IsEscalator
MetatileBehavior_IsEscalator: @ 8088F14
	push {lr}
	lsls r0, 24
	movs r1, 0x96
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _08088F28
	movs r0, 0
	b _08088F2A
_08088F28:
	movs r0, 0x1
_08088F2A:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsEscalator

	thumb_func_start sub_8088F30
sub_8088F30: @ 8088F30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _08088F3E
	movs r0, 0
	b _08088F40
_08088F3E:
	movs r0, 0x1
_08088F40:
	pop {r1}
	bx r1
	thumb_func_end sub_8088F30

	thumb_func_start MetatileBehavior_IsLadder
MetatileBehavior_IsLadder: @ 8088F44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x61
	beq _08088F52
	movs r0, 0
	b _08088F54
_08088F52:
	movs r0, 0x1
_08088F54:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsLadder

	thumb_func_start sub_8088F58
sub_8088F58: @ 8088F58
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x60
	beq _08088F6A
	cmp r0, 0x6C
	beq _08088F6A
	cmp r0, 0x6E
	bne _08088F6E
_08088F6A:
	movs r0, 0x1
	b _08088F70
_08088F6E:
	movs r0, 0
_08088F70:
	pop {r1}
	bx r1
	thumb_func_end sub_8088F58

	thumb_func_start sub_8088F74
sub_8088F74: @ 8088F74
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6E
	beq _08088F82
	movs r0, 0
	b _08088F84
_08088F82:
	movs r0, 0x1
_08088F84:
	pop {r1}
	bx r1
	thumb_func_end sub_8088F74

	thumb_func_start MetatileBehavior_IsSurfableWaterOrUnderwater
MetatileBehavior_IsSurfableWaterOrUnderwater: @ 8088F88
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_08486EFC
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08088FA4
	movs r0, 0
	b _08088FA6
	.pool
_08088FA4:
	movs r0, 0x1
_08088FA6:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSurfableWaterOrUnderwater

	thumb_func_start MetatileBehavior_IsEastArrowWarp
MetatileBehavior_IsEastArrowWarp: @ 8088FAC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x62
	beq _08088FBA
	movs r0, 0
	b _08088FBC
_08088FBA:
	movs r0, 0x1
_08088FBC:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsEastArrowWarp

	thumb_func_start MetatileBehavior_IsWestArrowWarp
MetatileBehavior_IsWestArrowWarp: @ 8088FC0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x63
	beq _08088FCE
	movs r0, 0
	b _08088FD0
_08088FCE:
	movs r0, 0x1
_08088FD0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWestArrowWarp

	thumb_func_start MetatileBehavior_IsNorthArrowWarp
MetatileBehavior_IsNorthArrowWarp: @ 8088FD4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x64
	beq _08088FE2
	cmp r0, 0x1B
	bne _08088FE6
_08088FE2:
	movs r0, 0x1
	b _08088FE8
_08088FE6:
	movs r0, 0
_08088FE8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsNorthArrowWarp

	thumb_func_start MetatileBehavior_IsSouthArrowWarp
MetatileBehavior_IsSouthArrowWarp: @ 8088FEC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x65
	beq _08088FFE
	cmp r0, 0x6D
	beq _08088FFE
	cmp r0, 0x1C
	bne _08089002
_08088FFE:
	movs r0, 0x1
	b _08089004
_08089002:
	movs r0, 0
_08089004:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSouthArrowWarp

	thumb_func_start sub_8089008
sub_8089008: @ 8089008
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	adds r0, r4, 0
	bl MetatileBehavior_IsEastArrowWarp
	lsls r0, 24
	cmp r0, 0
	bne _08089040
	adds r0, r4, 0
	bl MetatileBehavior_IsWestArrowWarp
	lsls r0, 24
	cmp r0, 0
	bne _08089040
	adds r0, r4, 0
	bl MetatileBehavior_IsNorthArrowWarp
	lsls r0, 24
	cmp r0, 0
	bne _08089040
	adds r0, r4, 0
	bl MetatileBehavior_IsSouthArrowWarp
	lsls r0, 24
	cmp r0, 0
	beq _08089042
_08089040:
	movs r5, 0x1
_08089042:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8089008

	thumb_func_start sub_808904C
sub_808904C: @ 808904C
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC0
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x8
	bls _08089082
	adds r0, r1, 0
	subs r0, 0x50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08089082
	cmp r1, 0xD0
	beq _08089082
	cmp r1, 0xD2
	beq _08089082
	cmp r1, 0x13
	beq _08089082
	cmp r1, 0x20
	beq _08089082
	cmp r1, 0xBB
	beq _08089082
	cmp r1, 0xBC
	bne _08089086
_08089082:
	movs r0, 0x1
	b _08089088
_08089086:
	movs r0, 0
_08089088:
	pop {r1}
	bx r1
	thumb_func_end sub_808904C

	thumb_func_start MetatileBehavior_IsIce_2
@ bool8 MetatileBehavior_IsIce_2(u8 metatileBehavior)
MetatileBehavior_IsIce_2: @ 808908C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x20
	beq _0808909A
	movs r0, 0
	b _0808909C
_0808909A:
	movs r0, 0x1
_0808909C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsIce_2

	thumb_func_start MetatileBehavior_IsTrickHouseSlipperyFloor
@ bool8 MetatileBehavior_IsTrickHouseSlipperyFloor(u8 metatileBehavior)
MetatileBehavior_IsTrickHouseSlipperyFloor: @ 80890A0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x48
	beq _080890AE
	movs r0, 0
	b _080890B0
_080890AE:
	movs r0, 0x1
_080890B0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsTrickHouseSlipperyFloor

	thumb_func_start MetatileBehavior_0x05
MetatileBehavior_0x05: @ 80890B4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	beq _080890C2
	movs r0, 0
	b _080890C4
_080890C2:
	movs r0, 0x1
_080890C4:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_0x05

	thumb_func_start MetatileBehavior_IsWalkNorth
@ bool8 MetatileBehavior_IsWalkNorth(u8 metatileBehavior)
MetatileBehavior_IsWalkNorth: @ 80890C8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x42
	beq _080890D6
	movs r0, 0
	b _080890D8
_080890D6:
	movs r0, 0x1
_080890D8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWalkNorth

	thumb_func_start MetatileBehavior_IsWalkSouth
@ bool8 MetatileBehavior_IsWalkSouth(u8 metatileBehavior)
MetatileBehavior_IsWalkSouth: @ 80890DC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x43
	beq _080890EA
	movs r0, 0
	b _080890EC
_080890EA:
	movs r0, 0x1
_080890EC:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWalkSouth

	thumb_func_start MetatileBehavior_IsWalkWest
@ bool8 MetatileBehavior_IsWalkWest(u8 metatileBehavior)
MetatileBehavior_IsWalkWest: @ 80890F0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x41
	beq _080890FE
	movs r0, 0
	b _08089100
_080890FE:
	movs r0, 0x1
_08089100:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWalkWest

	thumb_func_start MetatileBehavior_IsWalkEast
@ bool8 MetatileBehavior_IsWalkEast(u8 metatileBehavior)
MetatileBehavior_IsWalkEast: @ 8089104
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08089112
	movs r0, 0
	b _08089114
_08089112:
	movs r0, 0x1
_08089114:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWalkEast

	thumb_func_start MetatileBehavior_IsNorthwardCurrent
@ bool8 MetatileBehavior_IsNorthwardCurrent(u8 metatileBehavior)
MetatileBehavior_IsNorthwardCurrent: @ 8089118
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x52
	beq _08089126
	movs r0, 0
	b _08089128
_08089126:
	movs r0, 0x1
_08089128:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsNorthwardCurrent

	thumb_func_start MetatileBehavior_IsSouthwardCurrent
@ bool8 MetatileBehavior_IsSouthwardCurrent(u8 metatileBehavior)
MetatileBehavior_IsSouthwardCurrent: @ 808912C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x53
	beq _0808913A
	movs r0, 0
	b _0808913C
_0808913A:
	movs r0, 0x1
_0808913C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSouthwardCurrent

	thumb_func_start MetatileBehavior_IsWestwardCurrent
@ bool8 MetatileBehavior_IsWestwardCurrent(u8 metatileBehavior)
MetatileBehavior_IsWestwardCurrent: @ 8089140
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x51
	beq _0808914E
	movs r0, 0
	b _08089150
_0808914E:
	movs r0, 0x1
_08089150:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWestwardCurrent

	thumb_func_start MetatileBehavior_IsEastwardCurrent
@ bool8 MetatileBehavior_IsEastwardCurrent(u8 metatileBehavior)
MetatileBehavior_IsEastwardCurrent: @ 8089154
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x50
	beq _08089162
	movs r0, 0
	b _08089164
_08089162:
	movs r0, 0x1
_08089164:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsEastwardCurrent

	thumb_func_start MetatileBehavior_IsSlideNorth
@ bool8 MetatileBehavior_IsSlideNorth(u8 metatileBehavior)
MetatileBehavior_IsSlideNorth: @ 8089168
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x46
	beq _08089176
	movs r0, 0
	b _08089178
_08089176:
	movs r0, 0x1
_08089178:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSlideNorth

	thumb_func_start MetatileBehavior_IsSlideSouth
@ bool8 MetatileBehavior_IsSlideSouth(u8 metatileBehavior)
MetatileBehavior_IsSlideSouth: @ 808917C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x47
	beq _0808918A
	movs r0, 0
	b _0808918C
_0808918A:
	movs r0, 0x1
_0808918C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSlideSouth

	thumb_func_start MetatileBehavior_IsSlideWest
@ bool8 MetatileBehavior_IsSlideWest(u8 metatileBehavior)
MetatileBehavior_IsSlideWest: @ 8089190
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x45
	beq _0808919E
	movs r0, 0
	b _080891A0
_0808919E:
	movs r0, 0x1
_080891A0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSlideWest

	thumb_func_start MetatileBehavior_IsSlideEast
@ bool8 MetatileBehavior_IsSlideEast(u8 metatileBehavior)
MetatileBehavior_IsSlideEast: @ 80891A4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x44
	beq _080891B2
	movs r0, 0
	b _080891B4
_080891B2:
	movs r0, 0x1
_080891B4:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSlideEast

	thumb_func_start MetatileBehavior_IsCounter
MetatileBehavior_IsCounter: @ 80891B8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x80
	beq _080891C6
	movs r0, 0
	b _080891C8
_080891C6:
	movs r0, 0x1
_080891C8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsCounter

	thumb_func_start MetatileBehavior_IsPlayerFacingTVScreen
@ bool8 MetatileBehavior_IsPlayerFacingTVScreen(u8 behavior, u8 direction)
MetatileBehavior_IsPlayerFacingTVScreen: @ 80891CC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x2
	bne _080891DE
	cmp r0, 0x86
	beq _080891E2
_080891DE:
	movs r0, 0
	b _080891E4
_080891E2:
	movs r0, 0x1
_080891E4:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsPlayerFacingTVScreen

	thumb_func_start MetatileBehavior_IsPC
MetatileBehavior_IsPC: @ 80891E8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x83
	beq _080891F6
	movs r0, 0
	b _080891F8
_080891F6:
	movs r0, 0x1
_080891F8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsPC

	thumb_func_start is_tile_x84
is_tile_x84: @ 80891FC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x84
	beq _0808920A
	movs r0, 0
	b _0808920C
_0808920A:
	movs r0, 0x1
_0808920C:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x84

	thumb_func_start sub_8089210
sub_8089210: @ 8089210
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x91
	beq _08089232
	cmp r0, 0x93
	beq _08089232
	cmp r0, 0x95
	beq _08089232
	cmp r0, 0x97
	beq _08089232
	cmp r0, 0x99
	beq _08089232
	cmp r0, 0x9B
	beq _08089232
	cmp r0, 0x9D
	bne _08089236
_08089232:
	movs r0, 0x1
	b _08089238
_08089236:
	movs r0, 0
_08089238:
	pop {r1}
	bx r1
	thumb_func_end sub_8089210

	thumb_func_start sub_808923C
sub_808923C: @ 808923C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x90
	beq _08089252
	cmp r0, 0x92
	beq _08089252
	cmp r0, 0x94
	beq _08089252
	cmp r0, 0x9A
	bne _08089256
_08089252:
	movs r0, 0x1
	b _08089258
_08089256:
	movs r0, 0
_08089258:
	pop {r1}
	bx r1
	thumb_func_end sub_808923C

	thumb_func_start sub_808925C
sub_808925C: @ 808925C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x96
	beq _0808926A
	cmp r0, 0x9C
	bne _0808926E
_0808926A:
	movs r0, 0x1
	b _08089270
_0808926E:
	movs r0, 0
_08089270:
	pop {r1}
	bx r1
	thumb_func_end sub_808925C

	thumb_func_start is_tile_x98
is_tile_x98: @ 8089274
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x98
	beq _08089282
	movs r0, 0
	b _08089284
_08089282:
	movs r0, 0x1
_08089284:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x98

	thumb_func_start sub_8089288
sub_8089288: @ 8089288
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB0
	beq _08089296
	movs r0, 0
	b _08089298
_08089296:
	movs r0, 0x1
_08089298:
	pop {r1}
	bx r1
	thumb_func_end sub_8089288

	thumb_func_start sub_808929C
sub_808929C: @ 808929C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB1
	beq _080892AA
	movs r0, 0
	b _080892AC
_080892AA:
	movs r0, 0x1
_080892AC:
	pop {r1}
	bx r1
	thumb_func_end sub_808929C

	thumb_func_start sub_80892B0
sub_80892B0: @ 80892B0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB2
	beq _080892BE
	movs r0, 0
	b _080892C0
_080892BE:
	movs r0, 0x1
_080892C0:
	pop {r1}
	bx r1
	thumb_func_end sub_80892B0

	thumb_func_start sub_80892C4
sub_80892C4: @ 80892C4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB3
	beq _080892D2
	movs r0, 0
	b _080892D4
_080892D2:
	movs r0, 0x1
_080892D4:
	pop {r1}
	bx r1
	thumb_func_end sub_80892C4

	thumb_func_start sub_80892D8
sub_80892D8: @ 80892D8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB9
	beq _080892E6
	movs r0, 0
	b _080892E8
_080892E6:
	movs r0, 0x1
_080892E8:
	pop {r1}
	bx r1
	thumb_func_end sub_80892D8

	thumb_func_start sub_80892EC
sub_80892EC: @ 80892EC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC6
	beq _080892FA
	movs r0, 0
	b _080892FC
_080892FA:
	movs r0, 0x1
_080892FC:
	pop {r1}
	bx r1
	thumb_func_end sub_80892EC

	thumb_func_start sub_8089300
sub_8089300: @ 8089300
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC7
	beq _0808930E
	movs r0, 0
	b _08089310
_0808930E:
	movs r0, 0x1
_08089310:
	pop {r1}
	bx r1
	thumb_func_end sub_8089300

	thumb_func_start sub_8089314
sub_8089314: @ 8089314
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _08089320
	movs r0, 0
	b _08089322
_08089320:
	movs r0, 0x1
_08089322:
	pop {r1}
	bx r1
	thumb_func_end sub_8089314

	thumb_func_start sub_8089328
sub_8089328: @ 8089328
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB7
	beq _08089336
	movs r0, 0
	b _08089338
_08089336:
	movs r0, 0x1
_08089338:
	pop {r1}
	bx r1
	thumb_func_end sub_8089328

	thumb_func_start sub_808933C
sub_808933C: @ 808933C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB2
	beq _0808934A
	movs r0, 0
	b _0808934C
_0808934A:
	movs r0, 0x1
_0808934C:
	pop {r1}
	bx r1
	thumb_func_end sub_808933C

	thumb_func_start sub_8089350
sub_8089350: @ 8089350
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB5
	beq _0808935E
	movs r0, 0
	b _08089360
_0808935E:
	movs r0, 0x1
_08089360:
	pop {r1}
	bx r1
	thumb_func_end sub_8089350

	thumb_func_start sub_8089364
sub_8089364: @ 8089364
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC3
	beq _08089372
	movs r0, 0
	b _08089374
_08089372:
	movs r0, 0x1
_08089374:
	pop {r1}
	bx r1
	thumb_func_end sub_8089364

	thumb_func_start sub_8089378
sub_8089378: @ 8089378
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC2
	beq _08089386
	movs r0, 0
	b _08089388
_08089386:
	movs r0, 0x1
_08089388:
	pop {r1}
	bx r1
	thumb_func_end sub_8089378

	thumb_func_start sub_808938C
sub_808938C: @ 808938C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB8
	beq _0808939A
	movs r0, 0
	b _0808939C
_0808939A:
	movs r0, 0x1
_0808939C:
	pop {r1}
	bx r1
	thumb_func_end sub_808938C

	thumb_func_start sub_80893A0
sub_80893A0: @ 80893A0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xBE
	beq _080893AE
	movs r0, 0
	b _080893B0
_080893AE:
	movs r0, 0x1
_080893B0:
	pop {r1}
	bx r1
	thumb_func_end sub_80893A0

	thumb_func_start sub_80893B4
sub_80893B4: @ 80893B4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xBD
	beq _080893C2
	movs r0, 0
	b _080893C4
_080893C2:
	movs r0, 0x1
_080893C4:
	pop {r1}
	bx r1
	thumb_func_end sub_80893B4

	thumb_func_start sub_80893C8
sub_80893C8: @ 80893C8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xBA
	beq _080893D6
	movs r0, 0
	b _080893D8
_080893D6:
	movs r0, 0x1
_080893D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80893C8

	thumb_func_start sub_80893DC
sub_80893DC: @ 80893DC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xBF
	beq _080893EA
	movs r0, 0
	b _080893EC
_080893EA:
	movs r0, 0x1
_080893EC:
	pop {r1}
	bx r1
	thumb_func_end sub_80893DC

	thumb_func_start sub_80893F0
sub_80893F0: @ 80893F0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC4
	beq _080893FE
	movs r0, 0
	b _08089400
_080893FE:
	movs r0, 0x1
_08089400:
	pop {r1}
	bx r1
	thumb_func_end sub_80893F0

	thumb_func_start sub_8089404
sub_8089404: @ 8089404
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC5
	beq _08089412
	movs r0, 0
	b _08089414
_08089412:
	movs r0, 0x1
_08089414:
	pop {r1}
	bx r1
	thumb_func_end sub_8089404

	thumb_func_start MetatileBehavior_HasRipples
MetatileBehavior_HasRipples: @ 8089418
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _0808942A
	cmp r0, 0x16
	beq _0808942A
	cmp r0, 0x14
	bne _0808942E
_0808942A:
	movs r0, 0x1
	b _08089430
_0808942E:
	movs r0, 0
_08089430:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_HasRipples

	thumb_func_start MetatileBehavior_IsPuddle
MetatileBehavior_IsPuddle: @ 8089434
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x16
	beq _08089442
	movs r0, 0
	b _08089444
_08089442:
	movs r0, 0x1
_08089444:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsPuddle

	thumb_func_start MetatileBehavior_IsTallGrass
MetatileBehavior_IsTallGrass: @ 8089448
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _08089456
	movs r0, 0
	b _08089458
_08089456:
	movs r0, 0x1
_08089458:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsTallGrass

	thumb_func_start MetatileBehavior_IsLongGrass
MetatileBehavior_IsLongGrass: @ 808945C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0808946A
	movs r0, 0
	b _0808946C
_0808946A:
	movs r0, 0x1
_0808946C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsLongGrass

	thumb_func_start MetatileBehavior_IsBerryTreeSoil
MetatileBehavior_IsBerryTreeSoil: @ 8089470
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA0
	beq _0808947E
	movs r0, 0
	b _08089480
_0808947E:
	movs r0, 0x1
_08089480:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsBerryTreeSoil

	thumb_func_start MetatileBehavior_IsAsh
MetatileBehavior_IsAsh: @ 8089484
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x24
	beq _08089492
	movs r0, 0
	b _08089494
_08089492:
	movs r0, 0x1
_08089494:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsAsh

	thumb_func_start MetatileBehavior_IsUnusedFootprintMetatile
MetatileBehavior_IsUnusedFootprintMetatile: @ 8089498
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x25
	beq _080894A6
	movs r0, 0
	b _080894A8
_080894A6:
	movs r0, 0x1
_080894A8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsUnusedFootprintMetatile

	thumb_func_start sub_80894AC
sub_80894AC: @ 80894AC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0x90
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x3
	bls _080894CA
	adds r0, r1, 0
	subs r0, 0x7C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080894CE
_080894CA:
	movs r0, 0x1
	b _080894D0
_080894CE:
	movs r0, 0
_080894D0:
	pop {r1}
	bx r1
	thumb_func_end sub_80894AC

	thumb_func_start sub_80894D4
sub_80894D4: @ 80894D4
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	adds r0, r1, 0
	subs r0, 0x70
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0808950A
	adds r0, r1, 0
	subs r0, 0x7A
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080894F8
	movs r0, 0x2
	b _0808950A
_080894F8:
	adds r0, r2, 0
	subs r0, 0x7C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08089508
	movs r0, 0
	b _0808950A
_08089508:
	movs r0, 0x3
_0808950A:
	pop {r1}
	bx r1
	thumb_func_end sub_80894D4

	thumb_func_start sub_8089510
sub_8089510: @ 8089510
	push {lr}
	lsls r0, 24
	movs r1, 0x90
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x3
	bls _08089524
	movs r0, 0
	b _08089526
_08089524:
	movs r0, 0x1
_08089526:
	pop {r1}
	bx r1
	thumb_func_end sub_8089510

	thumb_func_start sub_808952C
sub_808952C: @ 808952C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _08089550
	adds r0, r4, 0
	bl sub_8088DF0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08089550
	movs r0, 0x1
	b _08089552
_08089550:
	movs r0, 0
_08089552:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808952C

	thumb_func_start sub_8089558
sub_8089558: @ 8089558
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0808957E
	adds r0, r4, 0
	bl sub_8088DF0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0808957E
	movs r0, 0x1
	b _08089580
_0808957E:
	movs r0, 0
_08089580:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8089558

	thumb_func_start sub_8089588
sub_8089588: @ 8089588
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB
	beq _08089596
	movs r0, 0
	b _08089598
_08089596:
	movs r0, 0x1
_08089598:
	pop {r1}
	bx r1
	thumb_func_end sub_8089588

	thumb_func_start sub_808959C
sub_808959C: @ 808959C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC
	beq _080895AA
	movs r0, 0
	b _080895AC
_080895AA:
	movs r0, 0x1
_080895AC:
	pop {r1}
	bx r1
	thumb_func_end sub_808959C

	thumb_func_start sub_80895B0
sub_80895B0: @ 80895B0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xEF
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bls _080895C6
	cmp r1, 0x14
	bne _080895CA
_080895C6:
	movs r0, 0x1
	b _080895CC
_080895CA:
	movs r0, 0
_080895CC:
	pop {r1}
	bx r1
	thumb_func_end sub_80895B0

	thumb_func_start sub_80895D0
sub_80895D0: @ 80895D0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	beq _080895DE
	cmp r0, 0x2A
	bne _080895E2
_080895DE:
	movs r0, 0x1
	b _080895E4
_080895E2:
	movs r0, 0
_080895E4:
	pop {r1}
	bx r1
	thumb_func_end sub_80895D0

	thumb_func_start MetatileBehavior_IsShallowFlowingWater
MetatileBehavior_IsShallowFlowingWater: @ 80895E8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x17
	beq _080895FA
	cmp r0, 0x1B
	beq _080895FA
	cmp r0, 0x1C
	bne _080895FE
_080895FA:
	movs r0, 0x1
	b _08089600
_080895FE:
	movs r0, 0
_08089600:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsShallowFlowingWater

	thumb_func_start sub_8089604
sub_8089604: @ 8089604
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x26
	beq _08089612
	movs r0, 0
	b _08089614
_08089612:
	movs r0, 0x1
_08089614:
	pop {r1}
	bx r1
	thumb_func_end sub_8089604

	thumb_func_start sub_8089618
sub_8089618: @ 8089618
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x27
	beq _08089626
	movs r0, 0
	b _08089628
_08089626:
	movs r0, 0x1
_08089628:
	pop {r1}
	bx r1
	thumb_func_end sub_8089618

	thumb_func_start sub_808962C
sub_808962C: @ 808962C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x15
	beq _0808963E
	cmp r0, 0x11
	beq _0808963E
	cmp r0, 0x12
	bne _08089642
_0808963E:
	movs r0, 0x1
	b _08089644
_08089642:
	movs r0, 0
_08089644:
	pop {r1}
	bx r1
	thumb_func_end sub_808962C

	thumb_func_start sub_8089648
sub_8089648: @ 8089648
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x18
	beq _08089656
	cmp r0, 0x1A
	bne _0808965A
_08089656:
	movs r0, 0x1
	b _0808965C
_0808965A:
	movs r0, 0
_0808965C:
	pop {r1}
	bx r1
	thumb_func_end sub_8089648

	thumb_func_start sub_8089660
sub_8089660: @ 8089660
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	beq _08089682
	adds r0, r4, 0
	bl MetatileBehavior_IsWaterfall
	lsls r0, 24
	cmp r0, 0
	bne _08089682
	movs r0, 0x1
	b _08089684
_08089682:
	movs r0, 0
_08089684:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8089660

	thumb_func_start MetatileBehavior_IsEastBlocked
MetatileBehavior_IsEastBlocked: @ 808968C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x30
	beq _080896A6
	cmp r0, 0x34
	beq _080896A6
	cmp r0, 0x36
	beq _080896A6
	cmp r0, 0xC1
	beq _080896A6
	cmp r0, 0xBE
	bne _080896AA
_080896A6:
	movs r0, 0x1
	b _080896AC
_080896AA:
	movs r0, 0
_080896AC:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsEastBlocked

	thumb_func_start MetatileBehavior_IsWestBlocked
MetatileBehavior_IsWestBlocked: @ 80896B0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	beq _080896CA
	cmp r0, 0x35
	beq _080896CA
	cmp r0, 0x37
	beq _080896CA
	cmp r0, 0xC1
	beq _080896CA
	cmp r0, 0xBE
	bne _080896CE
_080896CA:
	movs r0, 0x1
	b _080896D0
_080896CE:
	movs r0, 0
_080896D0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWestBlocked

	thumb_func_start MetatileBehavior_IsNorthBlocked
MetatileBehavior_IsNorthBlocked: @ 80896D4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x32
	beq _080896EA
	cmp r0, 0x34
	beq _080896EA
	cmp r0, 0x35
	beq _080896EA
	cmp r0, 0xC0
	bne _080896EE
_080896EA:
	movs r0, 0x1
	b _080896F0
_080896EE:
	movs r0, 0
_080896F0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsNorthBlocked

	thumb_func_start MetatileBehavior_IsSouthBlocked
MetatileBehavior_IsSouthBlocked: @ 80896F4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x33
	beq _0808970A
	cmp r0, 0x36
	beq _0808970A
	cmp r0, 0x37
	beq _0808970A
	cmp r0, 0xC0
	bne _0808970E
_0808970A:
	movs r0, 0x1
	b _08089710
_0808970E:
	movs r0, 0
_08089710:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSouthBlocked

	thumb_func_start MetatileBehavior_IsShortGrass
MetatileBehavior_IsShortGrass: @ 8089714
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x7
	beq _08089722
	movs r0, 0
	b _08089724
_08089722:
	movs r0, 0x1
_08089724:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsShortGrass

	thumb_func_start MetatileBehavior_IsHotSprings
MetatileBehavior_IsHotSprings: @ 8089728
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x28
	beq _08089736
	movs r0, 0
	b _08089738
_08089736:
	movs r0, 0x1
_08089738:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsHotSprings

	thumb_func_start MetatileBehavior_IsWaterfall
@ bool8 MetatileBehavior_IsWaterfall(u8 metatileBehavior)
MetatileBehavior_IsWaterfall: @ 808973C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	beq _0808974A
	movs r0, 0
	b _0808974C
_0808974A:
	movs r0, 0x1
_0808974C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWaterfall

	thumb_func_start MetatileBehavior_IsFortreeBridge
MetatileBehavior_IsFortreeBridge: @ 8089750
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x78
	beq _0808975E
	movs r0, 0
	b _08089760
_0808975E:
	movs r0, 0x1
_08089760:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsFortreeBridge

	thumb_func_start sub_8089764
sub_8089764: @ 8089764
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x74
	beq _08089772
	movs r0, 0
	b _08089774
_08089772:
	movs r0, 0x1
_08089774:
	pop {r1}
	bx r1
	thumb_func_end sub_8089764

	thumb_func_start sub_8089778
sub_8089778: @ 8089778
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x75
	beq _08089786
	movs r0, 0
	b _08089788
_08089786:
	movs r0, 0x1
_08089788:
	pop {r1}
	bx r1
	thumb_func_end sub_8089778

	thumb_func_start sub_808978C
sub_808978C: @ 808978C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x76
	beq _0808979A
	movs r0, 0
	b _0808979C
_0808979A:
	movs r0, 0x1
_0808979C:
	pop {r1}
	bx r1
	thumb_func_end sub_808978C

	thumb_func_start sub_80897A0
sub_80897A0: @ 80897A0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x77
	beq _080897AE
	movs r0, 0
	b _080897B0
_080897AE:
	movs r0, 0x1
_080897B0:
	pop {r1}
	bx r1
	thumb_func_end sub_80897A0

	thumb_func_start MetatileBehavior_IsPacifidlogLog
MetatileBehavior_IsPacifidlogLog: @ 80897B4
	push {lr}
	lsls r0, 24
	movs r1, 0x8C
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x3
	bls _080897C8
	movs r0, 0
	b _080897CA
_080897C8:
	movs r0, 0x1
_080897CA:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsPacifidlogLog

	thumb_func_start is_tile_x8C
is_tile_x8C: @ 80897D0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8C
	beq _080897DE
	movs r0, 0
	b _080897E0
_080897DE:
	movs r0, 0x1
_080897E0:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x8C

	thumb_func_start is_tile_x85
is_tile_x85: @ 80897E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x85
	beq _080897F2
	movs r0, 0
	b _080897F4
_080897F2:
	movs r0, 0x1
_080897F4:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x85

	thumb_func_start is_tile_x8B
is_tile_x8B: @ 80897F8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8B
	beq _08089806
	movs r0, 0
	b _08089808
_08089806:
	movs r0, 0x1
_08089808:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x8B

	thumb_func_start is_tile_xEA
is_tile_xEA: @ 808980C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xEA
	beq _0808981A
	movs r0, 0
	b _0808981C
_0808981A:
	movs r0, 0x1
_0808981C:
	pop {r1}
	bx r1
	thumb_func_end is_tile_xEA

	thumb_func_start is_tile_x8A
is_tile_x8A: @ 8089820
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8A
	beq _0808982E
	movs r0, 0
	b _08089830
_0808982E:
	movs r0, 0x1
_08089830:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x8A

	thumb_func_start is_tile_x87
is_tile_x87: @ 8089834
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x87
	beq _08089842
	movs r0, 0
	b _08089844
_08089842:
	movs r0, 0x1
_08089844:
	pop {r1}
	bx r1
	thumb_func_end is_tile_x87

	thumb_func_start MetatileBehavior_0xBB
@ bool8 MetatileBehavior_0xBB(u8 metatileBehavior)
MetatileBehavior_0xBB: @ 8089848
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xBB
	beq _08089856
	movs r0, 0
	b _08089858
_08089856:
	movs r0, 0x1
_08089858:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_0xBB

	thumb_func_start MetatileBehavior_0xBC
@ bool8 MetatileBehavior_0xBC(u8 metatileBehavior)
MetatileBehavior_0xBC: @ 808985C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xBC
	beq _0808986A
	movs r0, 0
	b _0808986C
_0808986A:
	movs r0, 0x1
_0808986C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_0xBC

	thumb_func_start sub_8089870
sub_8089870: @ 8089870
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x29
	beq _0808987E
	movs r0, 0
	b _08089880
_0808987E:
	movs r0, 0x1
_08089880:
	pop {r1}
	bx r1
	thumb_func_end sub_8089870

	thumb_func_start is_role_x68
is_role_x68: @ 8089884
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x68
	beq _08089892
	movs r0, 0
	b _08089894
_08089892:
	movs r0, 0x1
_08089894:
	pop {r1}
	bx r1
	thumb_func_end is_role_x68

	thumb_func_start MetatileBehavior_IsAquaHideoutWarp
MetatileBehavior_IsAquaHideoutWarp: @ 8089898
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x67
	beq _080898A6
	movs r0, 0
	b _080898A8
_080898A6:
	movs r0, 0x1
_080898A8:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsAquaHideoutWarp

	thumb_func_start sub_80898AC
sub_80898AC: @ 80898AC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x70
	beq _080898BA
	movs r0, 0
	b _080898BC
_080898BA:
	movs r0, 0x1
_080898BC:
	pop {r1}
	bx r1
	thumb_func_end sub_80898AC

	thumb_func_start sub_80898C0
sub_80898C0: @ 80898C0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE
	beq _080898CE
	movs r0, 0
	b _080898D0
_080898CE:
	movs r0, 0x1
_080898D0:
	pop {r1}
	bx r1
	thumb_func_end sub_80898C0

	thumb_func_start MetatileBehavior_IsSurfableFishableWater
MetatileBehavior_IsSurfableFishableWater: @ 80898D4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _080898F8
	cmp r0, 0x15
	beq _080898F8
	cmp r0, 0x11
	beq _080898F8
	cmp r0, 0x12
	beq _080898F8
	cmp r0, 0x14
	beq _080898F8
	subs r0, 0x50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080898FC
_080898F8:
	movs r0, 0x1
	b _080898FE
_080898FC:
	movs r0, 0
_080898FE:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSurfableFishableWater

	thumb_func_start sub_8089904
sub_8089904: @ 8089904
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	beq _08089912
	movs r0, 0
	b _08089914
_08089912:
	movs r0, 0x1
_08089914:
	pop {r1}
	bx r1
	thumb_func_end sub_8089904

	thumb_func_start sub_8089918
sub_8089918: @ 8089918
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x66
	beq _08089926
	movs r0, 0
	b _08089928
_08089926:
	movs r0, 0x1
_08089928:
	pop {r1}
	bx r1
	thumb_func_end sub_8089918

	thumb_func_start sub_808992C
sub_808992C: @ 808992C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD2
	beq _0808993A
	movs r0, 0
	b _0808993C
_0808993A:
	movs r0, 0x1
_0808993C:
	pop {r1}
	bx r1
	thumb_func_end sub_808992C

	thumb_func_start MetatileBehavior_IsMuddySlope
@ bool8 MetatileBehavior_IsMuddySlope(u8 metatileBehavior)
MetatileBehavior_IsMuddySlope: @ 8089940
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD0
	beq _0808994E
	movs r0, 0
	b _08089950
_0808994E:
	movs r0, 0x1
_08089950:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsMuddySlope

	thumb_func_start MetatileBehavior_IsBumpySlope
MetatileBehavior_IsBumpySlope: @ 8089954
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD1
	beq _08089962
	movs r0, 0
	b _08089964
_08089962:
	movs r0, 0x1
_08089964:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsBumpySlope

	thumb_func_start MetatileBehavior_IsIsolatedVerticalRail
MetatileBehavior_IsIsolatedVerticalRail: @ 8089968
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD3
	beq _08089976
	movs r0, 0
	b _08089978
_08089976:
	movs r0, 0x1
_08089978:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsIsolatedVerticalRail

	thumb_func_start MetatileBehavior_IsIsolatedHorizontalRail
MetatileBehavior_IsIsolatedHorizontalRail: @ 808997C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD4
	beq _0808998A
	movs r0, 0
	b _0808998C
_0808998A:
	movs r0, 0x1
_0808998C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsIsolatedHorizontalRail

	thumb_func_start MetatileBehavior_IsVerticalRail
MetatileBehavior_IsVerticalRail: @ 8089990
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD5
	beq _0808999E
	movs r0, 0
	b _080899A0
_0808999E:
	movs r0, 0x1
_080899A0:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsVerticalRail

	thumb_func_start MetatileBehavior_IsHorizontalRail
MetatileBehavior_IsHorizontalRail: @ 80899A4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD6
	beq _080899B2
	movs r0, 0
	b _080899B4
_080899B2:
	movs r0, 0x1
_080899B4:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsHorizontalRail

	thumb_func_start MetatileBehavior_IsSeaweed
MetatileBehavior_IsSeaweed: @ 80899B8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x22
	beq _080899C6
	cmp r0, 0x2A
	bne _080899CA
_080899C6:
	movs r0, 0x1
	b _080899CC
_080899CA:
	movs r0, 0
_080899CC:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsSeaweed

	thumb_func_start MetatileBehavior_IsRunningDisallowed
MetatileBehavior_IsRunningDisallowed: @ 80899D0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA
	beq _080899EC
	cmp r0, 0x3
	beq _080899EC
	cmp r0, 0x28
	beq _080899EC
	bl MetatileBehavior_IsPacifidlogLog
	lsls r0, 24
	cmp r0, 0
	beq _080899F0
_080899EC:
	movs r0, 0x1
	b _080899F2
_080899F0:
	movs r0, 0
_080899F2:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsRunningDisallowed

	thumb_func_start sub_80899F8
sub_80899F8: @ 80899F8
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFE
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bls _08089A12
	cmp r1, 0x24
	beq _08089A12
	cmp r1, 0x9
	bne _08089A16
_08089A12:
	movs r0, 0x1
	b _08089A18
_08089A16:
	movs r0, 0
_08089A18:
	pop {r1}
	bx r1
	thumb_func_end sub_80899F8

	thumb_func_start sub_8089A1C
sub_8089A1C: @ 8089A1C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8E
	beq _08089A2A
	movs r0, 0
	b _08089A2C
_08089A2A:
	movs r0, 0x1
_08089A2C:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A1C

	thumb_func_start sub_8089A30
sub_8089A30: @ 8089A30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE0
	beq _08089A3E
	movs r0, 0
	b _08089A40
_08089A3E:
	movs r0, 0x1
_08089A40:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A30

	thumb_func_start sub_8089A44
sub_8089A44: @ 8089A44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE1
	beq _08089A52
	movs r0, 0
	b _08089A54
_08089A52:
	movs r0, 0x1
_08089A54:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A44

	thumb_func_start sub_8089A58
sub_8089A58: @ 8089A58
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE2
	beq _08089A66
	movs r0, 0
	b _08089A68
_08089A66:
	movs r0, 0x1
_08089A68:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A58

	thumb_func_start sub_8089A6C
sub_8089A6C: @ 8089A6C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE3
	beq _08089A7A
	movs r0, 0
	b _08089A7C
_08089A7A:
	movs r0, 0x1
_08089A7C:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A6C

	thumb_func_start sub_8089A80
sub_8089A80: @ 8089A80
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE4
	beq _08089A8E
	movs r0, 0
	b _08089A90
_08089A8E:
	movs r0, 0x1
_08089A90:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A80

	thumb_func_start sub_8089A94
sub_8089A94: @ 8089A94
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE5
	beq _08089AA2
	movs r0, 0
	b _08089AA4
_08089AA2:
	movs r0, 0x1
_08089AA4:
	pop {r1}
	bx r1
	thumb_func_end sub_8089A94

	thumb_func_start sub_8089AA8
sub_8089AA8: @ 8089AA8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE6
	beq _08089AB6
	movs r0, 0
	b _08089AB8
_08089AB6:
	movs r0, 0x1
_08089AB8:
	pop {r1}
	bx r1
	thumb_func_end sub_8089AA8

	thumb_func_start sub_8089ABC
sub_8089ABC: @ 8089ABC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD
	beq _08089ACA
	movs r0, 0
	b _08089ACC
_08089ACA:
	movs r0, 0x1
_08089ACC:
	pop {r1}
	bx r1
	thumb_func_end sub_8089ABC

	thumb_func_start sub_8089AD0
sub_8089AD0: @ 8089AD0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x2
	bne _08089AE2
	cmp r0, 0xE8
	beq _08089AE6
_08089AE2:
	movs r0, 0
	b _08089AE8
_08089AE6:
	movs r0, 0x1
_08089AE8:
	pop {r1}
	bx r1
	thumb_func_end sub_8089AD0

	thumb_func_start sub_8089AEC
sub_8089AEC: @ 8089AEC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x2
	bne _08089AFE
	cmp r0, 0xE7
	beq _08089B02
_08089AFE:
	movs r0, 0
	b _08089B04
_08089B02:
	movs r0, 0x1
_08089B04:
	pop {r1}
	bx r1
	thumb_func_end sub_8089AEC

	thumb_func_start MetatileBehavior_IsQuestionnaire
MetatileBehavior_IsQuestionnaire: @ 8089B08
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8F
	beq _08089B16
	movs r0, 0
	b _08089B18
_08089B16:
	movs r0, 0x1
_08089B18:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsQuestionnaire

	thumb_func_start MetatileBehavior_IsLongGrass2
MetatileBehavior_IsLongGrass2: @ 8089B1C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08089B2A
	movs r0, 0
	b _08089B2C
_08089B2A:
	movs r0, 0x1
_08089B2C:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsLongGrass2

	thumb_func_start MetatileBehavior_IsLongGrassSouthEdge
MetatileBehavior_IsLongGrassSouthEdge: @ 8089B30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	beq _08089B3E
	movs r0, 0
	b _08089B40
_08089B3E:
	movs r0, 0x1
_08089B40:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsLongGrassSouthEdge

	thumb_func_start MetatileBehavior_IsTrainerHillTimer
MetatileBehavior_IsTrainerHillTimer: @ 8089B44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE9
	beq _08089B52
	movs r0, 0
	b _08089B54
_08089B52:
	movs r0, 0x1
_08089B54:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsTrainerHillTimer

	.align 2, 0 @ Don't pad with nop.
