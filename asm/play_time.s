	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start reset_playtime
reset_playtime: @ 80841E4
	ldr r1, =0x03000e08
	movs r0, 0
	strb r0, [r1]
	ldr r2, =0x03005d90
	ldr r3, [r2]
	movs r1, 0
	movs r0, 0
	strh r0, [r3, 0xE]
	strb r1, [r3, 0x10]
	ldr r0, [r2]
	strb r1, [r0, 0x11]
	ldr r0, [r2]
	strb r1, [r0, 0x12]
	bx lr
	.pool
	thumb_func_end reset_playtime

	thumb_func_start set_max_playtime_if_appropriate
set_max_playtime_if_appropriate: @ 8084208
	push {lr}
	ldr r1, =0x03000e08
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrh r1, [r0, 0xE]
	ldr r0, =0x000003e7
	cmp r1, r0
	bls _08084220
	bl set_max_playtime
_08084220:
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_max_playtime_if_appropriate

	thumb_func_start sub_8084230
sub_8084230: @ 8084230
	ldr r1, =0x03000e08
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8084230

	thumb_func_start gametime_increment
gametime_increment: @ 808423C
	push {lr}
	ldr r0, =0x03000e08
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08084294
	ldr r2, =0x03005d90
	ldr r0, [r2]
	ldrb r1, [r0, 0x12]
	adds r1, 0x1
	movs r3, 0
	strb r1, [r0, 0x12]
	ldr r1, [r2]
	ldrb r0, [r1, 0x12]
	cmp r0, 0x3B
	bls _08084294
	strb r3, [r1, 0x12]
	ldr r0, [r2]
	ldrb r1, [r0, 0x11]
	adds r1, 0x1
	strb r1, [r0, 0x11]
	ldr r1, [r2]
	ldrb r0, [r1, 0x11]
	cmp r0, 0x3B
	bls _08084294
	strb r3, [r1, 0x11]
	ldr r0, [r2]
	ldrb r1, [r0, 0x10]
	adds r1, 0x1
	strb r1, [r0, 0x10]
	ldr r1, [r2]
	ldrb r0, [r1, 0x10]
	cmp r0, 0x3B
	bls _08084294
	strb r3, [r1, 0x10]
	ldr r0, [r2]
	ldrh r1, [r0, 0xE]
	adds r1, 0x1
	strh r1, [r0, 0xE]
	lsls r1, 16
	ldr r0, =0x03e70000
	cmp r1, r0
	bls _08084294
	bl set_max_playtime
_08084294:
	pop {r0}
	bx r0
	.pool
	thumb_func_end gametime_increment

	thumb_func_start set_max_playtime
set_max_playtime: @ 80842A4
	ldr r1, =0x03000e08
	movs r0, 0x2
	strb r0, [r1]
	ldr r2, =0x03005d90
	ldr r3, [r2]
	ldr r0, =0x000003e7
	strh r0, [r3, 0xE]
	movs r1, 0x3B
	strb r1, [r3, 0x10]
	ldr r0, [r2]
	strb r1, [r0, 0x11]
	ldr r0, [r2]
	strb r1, [r0, 0x12]
	bx lr
	.pool
	thumb_func_end set_max_playtime

	.align 2, 0 @ Don't pad with nop.
