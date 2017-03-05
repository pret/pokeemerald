	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_809D7BC
sub_809D7BC: @ 809D7BC
	push {lr}
	movs r0, 0x1
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7BC

	thumb_func_start sub_809D7C8
sub_809D7C8: @ 809D7C8
	push {lr}
	movs r0, 0x2
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7C8

	thumb_func_start sub_809D7D4
sub_809D7D4: @ 809D7D4
	push {lr}
	movs r0, 0x3
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7D4

	thumb_func_start sub_809D7E0
sub_809D7E0: @ 809D7E0
	push {lr}
	movs r0, 0x4
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7E0

	thumb_func_start sub_809D7EC
sub_809D7EC: @ 809D7EC
	push {lr}
	movs r0, 0x5
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7EC

	thumb_func_start sub_809D7F8
sub_809D7F8: @ 809D7F8
	push {lr}
	movs r0, 0x6
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7F8

	thumb_func_start sub_809D804
sub_809D804: @ 809D804
	push {lr}
	movs r0, 0x9
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D804

	thumb_func_start sub_809D810
sub_809D810: @ 809D810
	push {lr}
	movs r0, 0x7
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D810

	thumb_func_start sub_809D81C
sub_809D81C: @ 809D81C
	push {lr}
	movs r0, 0x8
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D81C

	thumb_func_start sub_809D828
sub_809D828: @ 809D828
	push {lr}
	movs r0, 0xB
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D828

	thumb_func_start sub_809D834
sub_809D834: @ 809D834
	push {lr}
	movs r0, 0xC
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D834

	thumb_func_start sub_809D840
sub_809D840: @ 809D840
	push {lr}
	movs r0, 0x14
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D840

	thumb_func_start sub_809D84C
sub_809D84C: @ 809D84C
	push {lr}
	movs r0, 0x15
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D84C

	thumb_func_start trigger_activate_weather
trigger_activate_weather: @ 809D858
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r2, 0
	ldr r3, =gUnknown_085102E0
_0809D862:
	lsls r1, r2, 3
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r4
	bne _0809D87C
	adds r0, r3, 0x4
	adds r0, r1, r0
	ldr r0, [r0]
	bl _call_via_r0
	b _0809D886
	.pool
_0809D87C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xC
	bls _0809D862
_0809D886:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end trigger_activate_weather

	.align 2, 0 @ Don't pad with nop.
