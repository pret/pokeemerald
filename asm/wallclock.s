	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8135380
sub_8135380: @ 8135380
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081353C0
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0
	subs r0, 0x69
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _081353AC
	adds r0, r1, 0x5
	strh r0, [r4, 0x30]
_081353AC:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x68
	bgt _081353E0
	adds r0, r1, 0x1
	b _081353DE
	.pool
_081353C0:
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0
	subs r0, 0x5B
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _081353D2
	subs r0, r1, 0x5
	strh r0, [r4, 0x30]
_081353D2:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x78
	ble _081353E0
	subs r0, r1, 0x1
_081353DE:
	strh r0, [r4, 0x30]
_081353E0:
	ldrh r0, [r4, 0x30]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r0, r1, 1
	cmp r0, 0
	bge _081353F8
	ldr r1, =0x00000fff
	adds r0, r1
_081353F8:
	asrs r0, 12
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r0, r1, 1
	cmp r0, 0
	bge _08135414
	ldr r2, =0x00000fff
	adds r0, r2
_08135414:
	asrs r0, 12
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135380

	.align 2, 0 @ Don't pad with nop.
