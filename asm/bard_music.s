	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_817C858
sub_817C858: @ 817C858
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	movs r0, 0
	strh r0, [r5, 0x4]
	movs r6, 0
	ldr r0, =gUnknown_0860A3DC
	mov r8, r0
	adds r4, r5, 0
	adds r4, 0x18
_0817C872:
	lsls r0, r6, 3
	ldr r1, [r5, 0x30]
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _0817C8A0
	movs r1, 0x1
	ldrsb r1, [r2, r1]
	lsls r0, 2
	add r0, r8
	ldr r0, [r0]
	adds r1, r0
	strh r1, [r4]
	adds r0, r7, 0
	adds r0, 0x1E
	adds r1, r6, 0
	bl sub_817C7DC
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	ldrh r1, [r5, 0x4]
	adds r0, r1
	strh r0, [r5, 0x4]
_0817C8A0:
	adds r4, 0x4
	adds r6, 0x1
	cmp r6, 0x5
	ble _0817C872
	movs r0, 0
	strb r0, [r5, 0x1]
	strh r0, [r5, 0xA]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C858

	.align 2, 0 @ Don't pad with nop.
