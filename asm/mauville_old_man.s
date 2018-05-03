	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8120E08
sub_8120E08: @ 8120E08
	push {r4,r5,lr}
	ldr r2, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	str r0, [r2]
	movs r3, 0
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r2]
	strb r3, [r0, 0x1]
	movs r5, 0
	movs r4, 0xFF
_08120E24:
	ldr r0, [r2]
	adds r0, 0x4
	adds r0, r3
	strb r5, [r0]
	ldr r1, [r2]
	adds r1, 0x8
	adds r1, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x3
	ble _08120E24
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120E08

	thumb_func_start sub_8120E50
sub_8120E50: @ 8120E50
	ldr r3, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	str r0, [r3]
	movs r2, 0
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r3]
	strb r2, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_8120E50

	thumb_func_start sub_8120E74
sub_8120E74: @ 8120E74
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x32
	bne _08120E80
	movs r0, 0
_08120E80:
	bl GetGameStat
	pop {r1}
	bx r1
	thumb_func_end sub_8120E74

	thumb_func_start sub_8120E88
sub_8120E88: @ 8120E88
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =gUnknown_0859F048
_08120E90:
	ldrb r0, [r1]
	cmp r0, r3
	bne _08120EA0
	adds r0, r1, 0
	b _08120EAA
	.pool
_08120EA0:
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x23
	ble _08120E90
	ldr r0, =gUnknown_0859F048+0x230
_08120EAA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8120E88

	thumb_func_start sub_8120EB4
sub_8120EB4: @ 8120EB4
	push {lr}
	bl sub_8120E88
	ldr r0, [r0, 0x4]
	pop {r1}
	bx r1
	thumb_func_end sub_8120EB4

	thumb_func_start sub_8120EC0
sub_8120EC0: @ 8120EC0
	push {lr}
	bl sub_8120E88
	ldr r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_8120EC0

	thumb_func_start sub_8120ECC
sub_8120ECC: @ 8120ECC
	push {lr}
	bl sub_8120E88
	ldr r0, [r0, 0x8]
	pop {r1}
	bx r1
	thumb_func_end sub_8120ECC

	thumb_func_start sub_8120ED8
sub_8120ED8: @ 8120ED8
	push {lr}
	movs r1, 0
	ldr r2, =gUnknown_0203A12C
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08120EFC
_08120EE6:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _08120EFC
	ldr r0, [r2]
	adds r0, 0x4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08120EE6
_08120EFC:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8120ED8

	thumb_func_start sub_8120F08
sub_8120F08: @ 8120F08
	ldr r1, =gUnknown_0203A12C
	lsls r0, 2
	adds r0, 0x24
	ldr r2, [r1]
	adds r2, r0
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	orrs r0, r1
	ldrb r1, [r2, 0x2]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 24
	orrs r0, r1
	bx lr
	.pool
	thumb_func_end sub_8120F08

	thumb_func_start sub_8120F2C
sub_8120F2C: @ 8120F2C
	ldr r2, =gUnknown_0203A12C
	lsls r0, 2
	adds r0, 0x24
	ldr r2, [r2]
	adds r2, r0
	strb r1, [r2]
	lsrs r0, r1, 8
	strb r0, [r2, 0x1]
	lsrs r0, r1, 16
	strb r0, [r2, 0x2]
	lsrs r1, 24
	strb r1, [r2, 0x3]
	bx lr
	.pool
	thumb_func_end sub_8120F2C

	thumb_func_start sub_8120F4C
sub_8120F4C: @ 8120F4C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8120E74
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_8120F08
	cmp r4, r0
	bhi _08120F74
	movs r0, 0
	b _08120F76
	.pool
_08120F74:
	movs r0, 0x1
_08120F76:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8120F4C

	thumb_func_start sub_8120F7C
sub_8120F7C: @ 8120F7C
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r2, =gUnknown_0203A12C
	lsls r1, r0, 3
	subs r1, r0
	adds r1, 0x8
	ldr r4, [r2]
	adds r4, r1
	adds r0, r5, 0
	movs r1, 0xFF
	movs r2, 0x8
	bl memset
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl memcpy
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120F7C

	thumb_func_start sub_8120FAC
sub_8120FAC: @ 8120FAC
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r2, =gUnknown_0203A12C
	lsls r1, r0, 3
	subs r1, r0
	adds r1, 0x8
	ldr r4, [r2]
	adds r4, r1
	adds r0, r4, 0
	movs r1, 0xFF
	movs r2, 0x7
	bl memset
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl memcpy
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120FAC

	thumb_func_start sub_8120FDC
sub_8120FDC: @ 8120FDC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r8, r0
	adds r6, r1, 0
	ldr r0, =gUnknown_0203A12C
	mov r9, r0
	ldr r0, [r0]
	adds r0, 0x4
	add r0, r8
	strb r6, [r0]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	mov r0, r8
	bl sub_8120FAC
	lsls r4, r6, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8120E74
	adds r1, r0, 0
	mov r0, r8
	bl sub_8120F2C
	ldr r5, =gStringVar1
	adds r0, r4, 0
	bl sub_8120E74
	adds r1, r0, 0
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xA
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	adds r0, r6, 0
	bl sub_8120ECC
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x34
	add r0, r8
	ldr r1, =gGameLanguage
	ldrb r1, [r1]
	strb r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120FDC

	thumb_func_start sub_8121064
sub_8121064: @ 8121064
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	movs r5, 0
	cmp r5, r6
	bge _0812107A
_08121070:
	adds r0, r7, r5
	strb r5, [r0]
	adds r5, 0x1
	cmp r5, r6
	blt _08121070
_0812107A:
	cmp r6, 0
	ble _081210B0
	adds r5, r6, 0
_08121080:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	adds r4, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	adds r4, r7, r4
	ldrb r2, [r4]
	adds r0, r7, r0
	ldrb r1, [r0]
	strb r1, [r4]
	strb r2, [r0]
	subs r5, 0x1
	cmp r5, 0
	bne _08121080
_081210B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8121064

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
