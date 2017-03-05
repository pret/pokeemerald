	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_817C7DC
sub_817C7DC: @ 817C7DC
	ldr r2, =gUnknown_0860A320
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	bx lr
	.pool
	thumb_func_end sub_817C7DC

	thumb_func_start sub_817C7F4
sub_817C7F4: @ 817C7F4
	push {r4,r5,lr}
	lsls r4, r0, 16
	lsrs r5, r4, 16
	adds r0, r5, 0
	bl sub_811EB10
	lsls r0, 24
	cmp r0, 0
	beq _0817C810
	ldr r0, =gUnknown_0860A3AC
	b _0817C84E
	.pool
_0817C810:
	lsrs r0, r4, 25
	ldr r2, =0x000001ff
	ands r2, r5
	cmp r0, 0x13
	bhi _0817C828
	cmp r0, 0x12
	bcs _0817C834
	cmp r0, 0
	beq _0817C82C
	b _0817C83C
	.pool
_0817C828:
	cmp r0, 0x15
	bne _0817C83C
_0817C82C:
	ldr r1, =gUnknown_085F5494
	b _0817C844
	.pool
_0817C834:
	ldr r1, =gUnknown_085FA1D8
	b _0817C844
	.pool
_0817C83C:
	ldr r1, =gUnknown_0860A168
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
_0817C844:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r1, r0
	adds r0, r1, 0
_0817C84E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817C7F4

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
