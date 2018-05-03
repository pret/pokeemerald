	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81210B8
sub_81210B8: @ 81210B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r7, sp
	mov r8, sp
	ldr r0, =gUnknown_0859F288
	ldr r0, [r0]
	lsls r0, 3
	lsrs r0, 3
	adds r0, 0x3
	lsrs r0, 2
	lsls r0, 2
	mov r1, sp
	subs r1, r0
	mov sp, r1
	mov r9, sp
	mov r0, sp
	movs r1, 0x24
	bl sub_8121064
	movs r5, 0
_081210E4:
	ldr r1, =gUnknown_0859F048
	mov r2, r9
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r4, [r0]
	ldrb r6, [r0, 0x1]
	movs r1, 0
	ldr r2, =gUnknown_0203A12C
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	cmp r0, r4
	beq _08121112
_08121100:
	adds r1, 0x1
	cmp r1, 0x3
	bgt _08121112
	ldr r0, [r2]
	adds r0, 0x4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, r4
	bne _08121100
_08121112:
	cmp r1, 0x4
	bne _08121162
	adds r0, r4, 0
	bl sub_8120E74
	cmp r0, r6
	bcc _08121162
	ldr r0, =gUnknown_0203A12C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _08121150
	ldr r0, =gUnknown_03001178
	ldrb r0, [r0]
	adds r1, r4, 0
	bl sub_8120FDC
	b _0812115E
	.pool
_08121150:
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_8120FDC
_0812115E:
	movs r0, 0x1
	b _0812116A
_08121162:
	adds r5, 0x1
	cmp r5, 0x23
	ble _081210E4
	movs r0, 0
_0812116A:
	mov sp, r8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81210B8

	thumb_func_start sub_8121178
sub_8121178: @ 8121178
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	ldr r6, =gUnknown_0203A12C
	ldr r0, [r6]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	mov r8, r0
	ldr r4, =gStringVar1
	adds r0, r5, 0
	bl sub_8120F08
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0xA
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	mov r0, r8
	bl sub_8120ECC
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r4, =gStringVar3
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8120F7C
	ldr r0, [r6]
	adds r0, 0x34
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	bl ConvertInternationalString
	mov r0, r8
	bl sub_8120EC0
	bl ShowFieldMessage
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121178

	thumb_func_start sub_81211EC
sub_81211EC: @ 81211EC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =gText_Exit
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r5, r0, 0
	movs r4, 0
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08121230
_08121208:
	bl sub_8120EB4
	adds r1, r0, 0
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	cmp r0, r5
	ble _0812121C
	adds r5, r0, 0
_0812121C:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08121230
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	adds r0, 0x4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08121208
_08121230:
	adds r0, r5, 0
	bl convert_pixel_width_to_tile_width
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8120ED8
	adds r3, r0, 0
	lsls r3, 25
	movs r0, 0x80
	lsls r0, 18
	adds r3, r0
	lsrs r3, 24
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	bl CreateWindowFromRect
	ldr r1, =gUnknown_0203A130
	strb r0, [r1]
	ldrb r0, [r1]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	movs r4, 0
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _081212AA
	movs r5, 0x80
	lsls r5, 17
_08121272:
	bl sub_8120EB4
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A130
	ldrb r0, [r0]
	lsrs r1, r5, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
	movs r0, 0x80
	lsls r0, 21
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x3
	bgt _081212AA
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	adds r0, 0x4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08121272
_081212AA:
	ldr r5, =gUnknown_0203A130
	ldrb r0, [r5]
	ldr r2, =gText_Exit
	lsls r1, r4, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
	ldrb r4, [r5]
	bl sub_8120ED8
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81211EC

	thumb_func_start sub_81212FC
sub_81212FC: @ 81212FC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _08121320
	cmp r5, 0x1
	beq _0812132C
	b _08121376
	.pool
_08121320:
	bl sub_81211EC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08121376
_0812132C:
	bl ProcessMenuInput
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _08121376
	adds r0, 0x1
	cmp r4, r0
	beq _0812134E
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0812135C
_0812134E:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	b _08121364
	.pool
_0812135C:
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	ldr r0, =gUnknown_03001178
	strb r4, [r0]
_08121364:
	ldr r0, =gUnknown_0203A130
	ldrb r0, [r0]
	bl sub_80E2A78
	adds r0, r6, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_08121376:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81212FC

	thumb_func_start sub_8121388
sub_8121388: @ 8121388
	push {lr}
	ldr r0, =sub_81212FC
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121388

	thumb_func_start sub_812139C
sub_812139C: @ 812139C
	push {lr}
	ldr r0, =gUnknown_03001178
	ldrb r0, [r0]
	bl sub_8121178
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812139C

	thumb_func_start sub_81213B0
sub_81213B0: @ 81213B0
	push {lr}
	ldr r1, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	str r0, [r1]
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81213B0

	thumb_func_start sub_81213D8
sub_81213D8: @ 81213D8
	push {r4,r5,lr}
	ldr r2, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r3, =0x00002e28
	adds r0, r1, r3
	str r0, [r2]
	ldr r5, =gUnknown_03001178
	ldrb r0, [r5]
	ldr r2, =0x00002e2c
	adds r1, r2
	adds r1, r0
	ldrb r4, [r1]
	bl sub_8120F4C
	cmp r0, 0x1
	beq _08121414
	movs r0, 0
	b _0812141E
	.pool
_08121414:
	ldrb r0, [r5]
	adds r1, r4, 0
	bl sub_8120FDC
	movs r0, 0x1
_0812141E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81213D8

	thumb_func_start sub_8121424
sub_8121424: @ 8121424
	push {lr}
	ldr r1, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08121448
	movs r0, 0x1
	b _0812144A
	.pool
_08121448:
	movs r0, 0
_0812144A:
	pop {r1}
	bx r1
	thumb_func_end sub_8121424

	thumb_func_start sub_8121450
sub_8121450: @ 8121450
	push {lr}
	ldr r1, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	str r0, [r1]
	bl sub_81210B8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8121450

	.align 2, 0 @ Don't pad with nop.
