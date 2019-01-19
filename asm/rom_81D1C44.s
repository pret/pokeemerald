
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text
	

	thumb_func_start sub_81D1C44
sub_81D1C44: @ 81D1C44
	push {r4,lr}
	lsls r0, 24
	ldr r4, =gUnknown_0203CF4C
	lsrs r0, 21
	adds r0, 0x8
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081D1C60
	movs r0, 0
	b _081D1C7A
	.pool
_081D1C60:
	movs r2, 0
	ldr r4, =gUnknown_0203CF48
	movs r3, 0xFF
_081D1C66:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _081D1C66
	movs r0, 0x1
_081D1C7A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1C44

	thumb_func_start sub_81D1C84
sub_81D1C84: @ 81D1C84
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_0203CF48
	adds r5, r4, r6
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _081D1CEC
	cmp r4, 0x2
	bne _081D1CD4
	ldr r0, =gUnknown_086253E8
	ldr r1, [r0, 0x14]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gMailboxMailOptions
	movs r1, 0x4
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strb r0, [r6, 0x2]
	b _081D1CE0
	.pool
_081D1CD4:
	lsls r0, r4, 3
	ldr r1, =gUnknown_086253E8
	adds r0, r1
	bl AddWindow
	strb r0, [r5]
_081D1CE0:
	ldr r0, =gUnknown_0203CF48
	adds r0, r4, r0
	ldrb r0, [r0]
	movs r1, 0
	bl SetStandardWindowBorderStyle
_081D1CEC:
	ldr r0, =gUnknown_0203CF48
	adds r0, r4, r0
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1C84

	thumb_func_start sub_81D1D04
sub_81D1D04: @ 81D1D04
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF48
	adds r4, r0
	ldrb r0, [r4]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1D04

	thumb_func_start sub_81D1D34
sub_81D1D34: @ 81D1D34
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF48
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D1D34

	thumb_func_start sub_81D1D44
sub_81D1D44: @ 81D1D44
	push {r4,r5,lr}
	sub sp, 0x34
	adds r3, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _081D1DAC
	ldr r0, =gSaveBlock1Ptr
	lsls r1, r3, 3
	adds r1, r3
	lsls r1, 2
	ldr r0, [r0]
	adds r1, r0
	ldr r0, =0x00002cca
	adds r1, r0
	add r0, sp, 0x14
	bl StringCopy
	add r0, sp, 0x14
	bl sub_81DB52C
	add r0, sp, 0x14
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081D1D8C
	add r0, sp, 0x14
	movs r1, 0x1
	bl ConvertInternationalString
_081D1D8C:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_08625400
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	add r0, sp, 0x14
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x8
	adds r3, r5, 0
	bl AddTextPrinterParameterized4
_081D1DAC:
	add sp, 0x34
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1D44

	thumb_func_start sub_81D1DC0
sub_81D1DC0: @ 81D1DC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	movs r3, 0
	ldr r7, =gUnknown_0203CF4C
	ldr r0, =gText_Cancel2
	mov r12, r0
	ldr r4, =gMultiuseListMenuTemplate
	ldr r1, =gUnknown_0203CF48
	mov r8, r1
	ldr r2, =sub_81D1E7C
	mov r9, r2
	ldr r0, =sub_81D1D44
	mov r10, r0
	ldrb r1, [r5, 0x5]
	cmp r3, r1
	bcs _081D1E02
	adds r6, r7, 0
	ldr r2, =gUnknown_08625403
_081D1DEC:
	ldr r1, [r6]
	lsls r0, r3, 3
	adds r0, r1
	str r2, [r0]
	str r3, [r0, 0x4]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrb r0, [r5, 0x5]
	cmp r3, r0
	bcc _081D1DEC
_081D1E02:
	ldr r2, [r7]
	lsls r0, r3, 3
	adds r0, r2
	mov r1, r12
	str r1, [r0]
	movs r1, 0x2
	negs r1, r1
	str r1, [r0, 0x4]
	str r2, [r4]
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0xC]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	strb r0, [r4, 0x10]
	strb r1, [r4, 0x11]
	movs r0, 0x8
	strb r0, [r4, 0x12]
	strb r1, [r4, 0x13]
	strh r0, [r4, 0xE]
	movs r0, 0x29
	strb r0, [r4, 0x14]
	movs r0, 0x31
	strb r0, [r4, 0x15]
	mov r0, r9
	str r0, [r4, 0x4]
	mov r1, r10
	str r1, [r4, 0x8]
	movs r0, 0x1
	strb r0, [r4, 0x17]
	movs r0, 0
	strb r0, [r4, 0x16]
	ldrh r1, [r5, 0x2]
	ldrh r2, [r5]
	adds r0, r4, 0
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1DC0

	thumb_func_start sub_81D1E7C
sub_81D1E7C: @ 81D1E7C
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D1E8C
	movs r0, 0x5
	bl PlaySE
_081D1E8C:
	pop {r0}
	bx r0
	thumb_func_end sub_81D1E7C

	thumb_func_start sub_81D1E90
sub_81D1E90: @ 81D1E90
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldrb r0, [r4, 0x5]
	ldrb r1, [r4, 0x4]
	subs r0, r1
	adds r0, 0x1
	str r0, [sp]
	movs r0, 0x6E
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xC8
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParameterized
	strb r0, [r4, 0x9]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1E90

	thumb_func_start sub_81D1EC0
sub_81D1EC0: @ 81D1EC0
	push {lr}
	ldr r0, =gUnknown_0203CF4C
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1EC0

	thumb_func_start sub_81D1ED4
sub_81D1ED4: @ 81D1ED4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r3, r0, 0
	movs r6, 0
	movs r7, 0
_081D1EE6:
	movs r2, 0
	lsls r5, r6, 2
	adds r0, r6, 0x1
	mov r10, r0
	adds r4, r5, 0
_081D1EF0:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r3, r0
	adds r1, r0, 0
	adds r1, 0x64
	strh r7, [r1]
	adds r0, 0x66
	strh r7, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9
	bls _081D1EF0
	movs r2, 0
	mov r9, r2
	str r5, [sp]
	movs r1, 0x9B
	mov r8, r1
	movs r4, 0x5B
	mov r12, r4
_081D1F1C:
	lsls r0, r2, 2
	adds r0, r2
	adds r1, r6, r0
	adds r1, r3, r1
	mov r4, r9
	strb r4, [r1]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1, r0
	adds r0, r3, r0
	mov r4, r8
	strh r4, [r0, 0x14]
	mov r1, r12
	strh r1, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _081D1F1C
	adds r1, r3, r5
	movs r2, 0x96
	lsls r2, 1
	adds r0, r1, r2
	strh r7, [r0]
	movs r4, 0x97
	lsls r4, 1
	adds r0, r1, r4
	strh r7, [r0]
	mov r1, r10
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x4
	bls _081D1EE6
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r3, r2
	movs r1, 0
	strb r1, [r0]
	ldr r4, =0x00000352
	adds r0, r3, r4
	strh r1, [r0]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1ED4

	thumb_func_start sub_81D1F84
sub_81D1F84: @ 81D1F84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	str r1, [sp]
	mov r9, r2
	movs r7, 0
_081D1F98:
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r4, r1
	ldrh r1, [r0]
	lsls r5, r1, 8
	mov r2, r9
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	adds r7, 0x1
	mov r10, r7
	mov r12, r4
_081D1FBC:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	add r0, r12
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	movs r7, 0x1
	ands r1, r7
	adds r2, r1
	adds r0, 0x64
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D1FBC
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r1, r9
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r0, 0x64
	strh r1, [r0]
	ldr r7, [sp]
	adds r0, r4, r7
	ldrh r1, [r0, 0x2]
	lsls r5, r1, 8
	ldrh r0, [r2, 0x2]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	str r4, [sp, 0x4]
	movs r0, 0x1
	mov r12, r0
_081D2012:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	ldr r1, [sp, 0x4]
	adds r0, r1, r0
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	mov r7, r12
	ands r1, r7
	adds r2, r1
	adds r0, 0x66
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D2012
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r2, r9
	adds r1, r4, r2
	ldrh r1, [r1, 0x2]
	adds r0, 0x66
	strh r1, [r0]
	mov r7, r10
	lsls r0, r7, 16
	lsrs r7, r0, 16
	cmp r7, 0x4
	bls _081D1F98
	ldr r1, =0x00000352
	add r1, r8
	movs r0, 0
	strh r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1F84

	thumb_func_start sub_81D2074
sub_81D2074: @ 81D2074
	push {r4,lr}
	adds r1, r0, 0
	ldr r0, =0x00000352
	adds r4, r1, r0
	ldrh r0, [r4]
	cmp r0, 0x9
	bls _081D208C
	movs r0, 0
	b _081D20A6
	.pool
_081D208C:
	adds r0, r1, 0
	bl sub_81D2230
	ldrh r1, [r4]
	adds r1, 0x1
	strh r1, [r4]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0xA
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_081D20A6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2074

	thumb_func_start sub_81D20AC
sub_81D20AC: @ 81D20AC
	ldr r1, =0x00000355
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D20AC

	thumb_func_start sub_81D20BC
sub_81D20BC: @ 81D20BC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =0x00000355
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D20D4
	cmp r0, 0x1
	beq _081D20E2
	b _081D20FA
	.pool
_081D20D4:
	bl ScanlineEffect_Clear
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	b _081D20FC
_081D20E2:
	mov r0, sp
	ldr r1, =gUnknown_08625404
	ldm r1!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_081D20FA:
	movs r0, 0
_081D20FC:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D20BC

	thumb_func_start sub_81D2108
sub_81D2108: @ 81D2108
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	movs r1, 0xD5
	lsls r1, 2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D21BE
	adds r0, r6, 0
	bl sub_81D24A4
	adds r0, r6, 0
	bl sub_81D2634
	movs r7, 0
	ldr r5, =gScanlineEffectRegBuffers
	mov r12, r5
	movs r0, 0xF0
	lsls r0, 3
	add r0, r12
	mov r9, r0
	movs r1, 0xA0
	lsls r1, 1
	adds r1, r6, r1
	str r1, [sp]
	ldr r5, =0x0000ffff
	mov r8, r5
	movs r0, 0xA1
	lsls r0, 1
	adds r0, r6, r0
	str r0, [sp, 0x4]
	movs r1, 0x92
	lsls r1, 2
	adds r1, r6, r1
	str r1, [sp, 0x8]
	ldr r5, =0x0000024a
	adds r5, r6
	mov r10, r5
_081D215E:
	adds r2, r7, 0
	adds r2, 0x37
	lsls r3, r2, 2
	mov r0, r9
	adds r0, r3, r0
	str r0, [sp, 0xC]
	add r3, r12
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	ldr r5, [sp, 0x4]
	adds r1, r5, r4
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r3]
	mov r1, r8
	ands r0, r1
	ldr r5, [sp, 0xC]
	strh r0, [r5]
	lsls r2, 1
	adds r2, 0x1
	lsls r2, 1
	mov r0, r9
	adds r3, r2, r0
	add r2, r12
	ldr r1, [sp, 0x8]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	add r4, r10
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r2]
	mov r5, r8
	ands r0, r5
	strh r0, [r3]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x41
	bls _081D215E
	movs r0, 0xD5
	lsls r0, 2
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_081D21BE:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2108

	thumb_func_start sub_81D21DC
sub_81D21DC: @ 81D21DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D21E8
	movs r1, 0
_081D21E8:
	movs r0, 0x1
	lsls r0, r1
	movs r5, 0x1F
	bics r5, r0
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0x9B
	bl SetGpuReg
	ldr r4, =0x00003879
	movs r0, 0x44
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x46
	adds r1, r4, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D21DC

	thumb_func_start sub_81D2230
sub_81D2230: @ 81D2230
	push {r4-r7,lr}
	mov r12, r0
	movs r4, 0
	movs r7, 0x96
	lsls r7, 1
	add r7, r12
	ldr r6, =0x00000352
	add r6, r12
	mov r5, r12
	adds r5, 0x64
_081D2244:
	lsls r2, r4, 2
	adds r3, r7, r2
	ldrh r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, r5, r2
	ldr r0, [r2]
	str r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _081D2244
	movs r1, 0xD5
	lsls r1, 2
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2230

	thumb_func_start sub_81D2278
sub_81D2278: @ 81D2278
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	adds r6, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x38]
	ldr r7, [sp, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	str r0, [sp, 0xC]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r3, 0x2]
	cmp r0, r1
	bcs _081D22B2
	adds r2, r0, 0
	mov r10, r2
	ldrh r0, [r3, 0x2]
	ldrh r1, [r5]
	lsls r4, r1, 10
	ldrh r3, [r3]
	str r3, [sp, 0x8]
	b _081D22C6
_081D22B2:
	ldrh r0, [r5, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r1, [r1, 0x2]
	mov r10, r1
	ldr r2, [sp, 0x4]
	ldrh r1, [r2]
	lsls r4, r1, 10
	ldrh r3, [r5]
	str r3, [sp, 0x8]
	mov r2, r10
_081D22C6:
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	beq _081D22DE
	subs r0, r3, r1
	lsls r0, 10
	mov r1, r8
	bl __divsi3
	str r0, [sp, 0xC]
_081D22DE:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r7, 0
	bne _081D2328
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r7, r8
	bcs _081D23B6
	movs r7, 0x1
_081D2308:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r1, [sp, 0xC]
	adds r4, r1
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2308
	b _081D23B6
_081D2328:
	ldr r2, [sp, 0xC]
	cmp r2, 0
	ble _081D23C0
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r5, r8
	bcs _081D237A
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D237A
	mov r1, r12
	str r1, [sp, 0x14]
_081D2352:
	ldr r3, [sp, 0x14]
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r3, 0x1
	ands r0, r3
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D237A
	ldr r1, =0x00026bff
	cmp r4, r1
	ble _081D2352
_081D237A:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	cmp r5, r8
	bcs _081D23B6
	mov r3, r12
	movs r7, 0x1
_081D2398:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2398
_081D23B6:
	subs r0, r6, 0x4
	b _081D248C
	.pool
_081D23C0:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	bge _081D2464
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r2, r9
	lsls r2, 1
	mov r12, r2
	ldr r3, [sp, 0x8]
	add r3, r9
	str r3, [sp, 0x10]
	cmp r5, r8
	bcs _081D241E
	adds r3, r2, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r2, 0x1
	ands r0, r2
	adds r1, r0
	add r1, r9
	strh r1, [r3]
	b _081D2414
_081D23F2:
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D241E
	mov r1, r12
	adds r3, r1, r6
	asrs r2, r4, 10
	asrs r0, r4, 9
	movs r1, 0x1
	ands r0, r1
	adds r2, r0
	add r2, r9
	strh r2, [r3]
_081D2414:
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D23F2
	movs r0, 0x9B
	strh r0, [r3]
_081D241E:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	cmp r5, r8
	bcs _081D245A
	mov r3, r12
	movs r6, 0x1
_081D243C:
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r6
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D243C
_081D245A:
	subs r0, r7, 0x4
	b _081D248C
	.pool
_081D2464:
	ldr r1, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r1, r2
	mov r3, r10
	strh r3, [r0]
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	adds r7, r0
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1]
	strh r0, [r7]
	movs r0, 0x9B
	strh r0, [r7, 0x2]
	b _081D2494
_081D248C:
	add r0, r12
	mov r2, sp
	ldrh r2, [r2, 0x10]
	strh r2, [r0]
_081D2494:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2278

	thumb_func_start sub_81D24A4
sub_81D24A4: @ 81D24A4
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x99
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcs _081D24E0
	adds r7, r0, 0
	movs r0, 0xA0
	lsls r0, 1
	adds r1, r4, r0
	movs r3, 0x96
	lsls r3, 1
	adds r2, r4, r3
	subs r0, 0x10
	adds r3, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2500
_081D24E0:
	ldrh r7, [r1]
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x96
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2500:
	movs r1, 0xA0
	lsls r1, 1
	adds r5, r4, r1
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x9A
	lsls r0, 1
	adds r6, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_81D2278
	movs r2, 0
	movs r1, 0x9B
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0x9D
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D253C
	movs r2, 0x1
_081D253C:
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	str r2, [sp]
	movs r1, 0x92
	lsls r1, 2
	adds r0, r4, r1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D2278
	movs r2, 0x38
	cmp r2, r7
	bcs _081D257E
	adds r6, r5, 0
	movs r3, 0
	movs r0, 0xA1
	lsls r0, 1
	adds r5, r4, r0
_081D2566:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r7
	bcc _081D2566
_081D257E:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r1, [r0]
	cmp r2, r1
	bhi _081D25B2
	movs r1, 0xA0
	lsls r1, 1
	adds r3, r4, r1
	movs r5, 0x9B
	adds r1, r0, 0
_081D259C:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r0, r3, r0
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r1]
	cmp r2, r0
	bls _081D259C
_081D25B2:
	movs r2, 0x9B
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _081D25C8
	adds r0, r1, 0
_081D25C8:
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bhi _081D25F8
	movs r0, 0xA0
	lsls r0, 1
	adds r6, r4, r0
	movs r3, 0
	movs r1, 0xA1
	lsls r1, 1
	adds r5, r4, r1
_081D25E0:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D25E0
_081D25F8:
	movs r2, 0x38
	movs r3, 0xA0
	lsls r3, 1
	adds r5, r4, r3
	movs r0, 0xA1
	lsls r0, 1
	adds r4, r0
	movs r6, 0x9B
_081D2608:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r1, r0, 2
	adds r3, r5, r1
	ldrh r0, [r3]
	cmp r0, 0
	bne _081D2620
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081D2620
	strh r6, [r3]
_081D2620:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D2608
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D24A4

	thumb_func_start sub_81D2634
sub_81D2634: @ 81D2634
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x9F
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r5, [r1]
	cmp r0, r5
	bcs _081D266E
	adds r6, r0, 0
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	subs r3, 0x12
	adds r2, r4, r3
	movs r5, 0x9E
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2690
_081D266E:
	ldrh r6, [r1]
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	movs r3, 0x9E
	lsls r3, 1
	adds r2, r4, r3
	movs r5, 0x96
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2690:
	movs r0, 0x92
	lsls r0, 2
	adds r5, r4, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r2, r4, r1
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D2278
	cmp r6, 0x38
	ble _081D26C8
	movs r0, 0
	adds r1, r5, 0
	adds r2, r6, 0
	subs r2, 0x38
_081D26BC:
	strh r0, [r1]
	strh r0, [r1, 0x2]
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _081D26BC
_081D26C8:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r5, [r0]
	cmp r2, r5
	bgt _081D26F6
	movs r3, 0x9B
	adds r1, r0, 0
	lsls r0, r2, 2
	movs r5, 0xB5
	lsls r5, 1
	adds r0, r5
	adds r0, r4
_081D26EA:
	strh r3, [r0]
	adds r0, 0x4
	adds r2, 0x1
	ldrh r5, [r1]
	cmp r2, r5
	ble _081D26EA
_081D26F6:
	movs r1, 0x9D
	lsls r1, 1
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r0, 0x1
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _081D270E
	adds r0, r1, 0
_081D270E:
	adds r2, r0, 0
	cmp r2, 0x79
	bgt _081D272C
	movs r1, 0
	lsls r0, r2, 2
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3
	adds r0, r4
_081D2720:
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	adds r2, 0x1
	cmp r2, 0x79
	ble _081D2720
_081D272C:
	movs r3, 0
	movs r5, 0x92
	lsls r5, 2
	adds r1, r4, r5
	movs r2, 0x41
_081D2736:
	ldrh r0, [r1]
	ldrh r4, [r1, 0x2]
	cmp r0, r4
	bcc _081D2742
	strh r3, [r1, 0x2]
	strh r3, [r1]
_081D2742:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _081D2736
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2634

	thumb_func_start sub_81D2754
sub_81D2754: @ 81D2754
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r1, =gUnknown_08625410
	ldrb r0, [r6]
	adds r0, r1
	ldrb r2, [r0]
	adds r6, 0x1
	movs r0, 0x9B
	mov r3, r8
	strh r0, [r3]
	movs r0, 0x5B
	subs r0, r2
	strh r0, [r3, 0x2]
	movs r7, 0x40
	movs r0, 0
	mov r12, r0
	movs r2, 0x1
	mov r9, r2
	ldr r3, =gSineTable
	mov r10, r3
_081D2786:
	adds r0, r7, 0
	adds r0, 0x33
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, r12
	lsls r0, r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r3, r0, 24
	mov r12, r3
	cmp r0, 0
	bge _081D27A4
	movs r0, 0x4
	mov r12, r0
_081D27A4:
	mov r1, r12
	lsls r0, r1, 24
	asrs r4, r0, 24
	cmp r4, 0x2
	bne _081D27B4
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_081D27B4:
	ldrb r0, [r6]
	ldr r2, =gUnknown_08625410
	adds r0, r2
	ldrb r2, [r0]
	adds r6, 0x1
	lsls r0, r4, 2
	mov r1, r8
	adds r3, r0, r1
	adds r0, r7, 0
	adds r0, 0x40
	lsls r0, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r2
	asrs r5, r0, 8
	adds r0, r5, 0
	adds r0, 0x9B
	strh r0, [r3]
	lsls r0, r7, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r1, r2, 0
	muls r1, r0
	asrs r1, 8
	movs r0, 0x5B
	subs r0, r1
	strh r0, [r3, 0x2]
	cmp r4, 0x2
	bgt _081D2800
	cmp r2, 0x20
	bne _081D27FA
	cmp r4, 0x2
	beq _081D2800
_081D27FA:
	adds r0, r5, 0
	adds r0, 0x9C
	strh r0, [r3]
_081D2800:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0x4
	bls _081D2786
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2754

	thumb_func_start sub_81D2824
sub_81D2824: @ 81D2824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_08625510
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081D284A:
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081D284A
	cmp r5, 0
	bne _081D287C
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	b _081D288E
	.pool
_081D287C:
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
_081D288E:
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x3
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	bl nullsub_79
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2824

	thumb_func_start nullsub_79
nullsub_79: @ 81D28C4
	bx lr
	thumb_func_end nullsub_79

	thumb_func_start sub_81D28C8
sub_81D28C8: @ 81D28C8
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gMultiuseListMenuTemplate
	adds r2, r3, 0
	ldr r1, =gUnknown_08625548
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	strh r4, [r3, 0xC]
	str r0, [r3]
	cmp r4, 0x5
	bhi _081D28F0
	strh r4, [r3, 0xE]
	b _081D28F4
	.pool
_081D28F0:
	movs r0, 0x6
	strh r0, [r3, 0xE]
_081D28F4:
	ldrb r0, [r3, 0xE]
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D28C8

	thumb_func_start sub_81D28FC
sub_81D28FC: @ 81D28FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_BattleMoves2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	mov r8, r0
	str r0, [sp, 0x4]
	movs r7, 0
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_PPSlash
	movs r1, 0x29
	mov r10, r1
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r5, =gText_PowerSlash
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r1, 0x19
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_AccuracySlash
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	negs r0, r0
	cmp r9, r0
	bne _081D29C4
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2AB6
	.pool
_081D29C4:
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 2
	ldr r1, =gBattleMoves
	adds r6, r0, r1
	ldrb r1, [r6, 0x2]
	lsls r0, r1, 3
	subs r0, r1
	ldr r1, =gTypeNames
	adds r5, r0, r1
	movs r0, 0x19
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r1, =gText_PPSlash
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0x4
	ldrb r1, [r6, 0x4]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	lsls r3, r4, 24
	lsrs r3, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	ldrb r0, [r6, 0x1]
	cmp r0, 0x1
	bhi _081D2A3C
	ldr r5, =gText_ThreeDashes
	b _081D2A4A
	.pool
_081D2A3C:
	ldrb r1, [r6, 0x1]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A4A:
	movs r0, 0x19
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl AddTextPrinterParameterized
	ldrb r0, [r6, 0x3]
	cmp r0, 0
	bne _081D2A70
	ldr r5, =gText_ThreeDashes
	b _081D2A7E
	.pool
_081D2A70:
	ldrb r1, [r6, 0x3]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A7E:
	movs r0, 0x29
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl AddTextPrinterParameterized
	ldr r1, =gMoveDescriptionPointers
	mov r0, r9
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
_081D2AB6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D28FC

	thumb_func_start sub_81D2ACC
sub_81D2ACC: @ 81D2ACC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	bl ShowHideHearts
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_ContestMoves2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r7, 0xFF
	str r7, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_Appeal2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x19
	mov r8, r0
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_Jam2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x29
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081D2B6C
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2BB8
	.pool
_081D2B6C:
	lsls r4, 3
	ldr r0, =gContestMoves
	adds r4, r0
	ldr r1, =gContestMoveTypeTextPointers
	ldrb r0, [r4, 0x1]
	lsls r0, 29
	lsrs r0, 27
	adds r0, r1
	ldr r5, [r0]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r1, =gContestEffectDescriptionPointers
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_081D2BB8:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2ACC

	thumb_func_start sub_81D2BD0
sub_81D2BD0: @ 81D2BD0
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D2BE2
	movs r0, 0x5
	bl PlaySE
_081D2BE2:
	adds r0, r4, 0
	bl sub_81D28FC
	adds r0, r4, 0
	bl sub_81D2ACC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2BD0

	thumb_func_start sub_81D2BF4
sub_81D2BF4: @ 81D2BF4
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	bl GetPlayerTextSpeedDelay
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized2
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2BF4

	thumb_func_start sub_81D2C3C
sub_81D2C3C: @ 81D2C3C
	push {lr}
	bl RunTextPrinters
	movs r0, 0x3
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C3C

	thumb_func_start sub_81D2C50
sub_81D2C50: @ 81D2C50
	push {lr}
	ldr r0, =gUnknown_08625540
	movs r1, 0x1
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2C50

	thumb_func_start sub_81D2C68
sub_81D2C68: @ 81D2C68
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r0, 0xE
	bne _081D2CA8
	cmp r2, 0x2
	beq _081D2C7E
	cmp r2, 0x7
	bne _081D2C94
_081D2C7E:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	adds r2, r3, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2C94:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2CA8:
	cmp r2, 0x2
	beq _081D2CB0
	cmp r2, 0x7
	bne _081D2CBE
_081D2CB0:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl GetAndCopyBoxMonDataAt
	b _081D2CCA
_081D2CBE:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl GetBoxMonDataAt
_081D2CCA:
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C68

	thumb_func_start sub_81D2CD0
sub_81D2CD0: @ 81D2CD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	movs r0, 0xFC
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x4
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x8
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x9
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2D
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0
	beq _081D2D20
	ldr r1, =gText_EggNickname
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081D2E70
	.pool
_081D2D20:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_81D2C68
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81D2C68
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081D2D70
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	b _081D2D92
	.pool
_081D2D70:
	lsls r0, r4, 24
	lsrs r0, 24
	lsls r1, r6, 24
	lsrs r1, 24
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_081D2D92:
	cmp r7, 0x1D
	beq _081D2D9A
	cmp r7, 0x20
	bne _081D2DB0
_081D2D9A:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081D2DB0
	movs r6, 0xFF
_081D2DB0:
	adds r3, r5, 0
	b _081D2DBA
	.pool
_081D2DB8:
	adds r3, 0x1
_081D2DBA:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081D2DB8
	movs r1, 0xFC
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x12
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x3C
	strb r0, [r3]
	adds r3, 0x1
	cmp r6, 0
	beq _081D2DDE
	cmp r6, 0xFE
	beq _081D2E02
	movs r0, 0
	b _081D2E24
_081D2DDE:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB5
	b _081D2E24
_081D2E02:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x6
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x7
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB6
_081D2E24:
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x8
	strb r0, [r3]
	adds r3, 0x1
	movs r4, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0x9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xBA
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xF9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	adds r0, r3, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081D2E70:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2CD0

	thumb_func_start sub_81D2E7C
sub_81D2E7C: @ 81D2E7C
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081D2E94
_081D2E86:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081D2E94:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081D2E86
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081D2EC2
	movs r3, 0
_081D2EAE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081D2EAE
_081D2EC2:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D2E7C

	thumb_func_start sub_81D2ED4
sub_81D2ED4: @ 81D2ED4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D2EFC
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2EFC:
	cmp r2, r0
	beq _081D2F42
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r3, 0
	bl sub_81D2CD0
	movs r0, 0xFC
	strb r0, [r5]
	movs r0, 0x4
	strb r0, [r5, 0x1]
	movs r0, 0x8
	strb r0, [r5, 0x2]
	movs r0, 0
	strb r0, [r5, 0x3]
	movs r0, 0x9
	strb r0, [r5, 0x4]
	cmp r7, 0xE
	bne _081D2F2C
	adds r0, r5, 0x5
	ldr r1, =gText_InParty
	b _081D2F3A
	.pool
_081D2F2C:
	adds r4, r5, 0x5
	lsls r0, r7, 24
	lsrs r0, 24
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
_081D2F3A:
	movs r2, 0x8
	bl sub_81D2E7C
	b _081D2F72
_081D2F42:
	movs r1, 0
	movs r2, 0
_081D2F46:
	adds r0, r6, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081D2F46
	adds r1, r6, r1
	movs r0, 0xFF
	strb r0, [r1]
	movs r1, 0
	movs r2, 0
_081D2F5E:
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081D2F5E
	adds r1, r5, r1
	movs r0, 0xFF
	strb r0, [r1]
_081D2F72:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2ED4

	thumb_func_start sub_81D2F78
sub_81D2F78: @ 81D2F78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r0, r4, 16
	lsls r5, 24
	cmp r5, 0
	bne _081D2FB0
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2FB0:
	cmp r2, r0
	beq _081D305C
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x16
	movs r3, 0
	bl sub_81D2C68
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	mov r2, r8
	adds r1, r2, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x2F
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x21
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x2
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x18
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x3
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x17
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x4
	adds r1, r4
	strb r0, [r1]
	mov r4, r10
	add r4, r9
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _081D3044
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	movs r1, 0x1D
	bl __udivsi3
	b _081D3046
_081D3044:
	movs r0, 0x9
_081D3046:
	strb r0, [r4]
	mov r0, r9
	adds r1, r5, r0
	mov r2, r8
	adds r0, r2, r1
	lsls r1, 2
	adds r1, 0x14
	add r1, r8
	bl sub_81D2754
	b _081D3086
_081D305C:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	adds r1, r5, r0
	movs r6, 0
	lsls r3, r1, 2
	movs r5, 0x9B
	movs r4, 0x5B
_081D306C:
	adds r0, r2, r1
	add r0, r8
	strb r6, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	strh r5, [r0, 0x14]
	strh r4, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081D306C
_081D3086:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2F78

	thumb_func_start sub_81D3094
sub_81D3094: @ 81D3094
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	mov r9, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D30C4
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D30C4:
	cmp r2, r0
	beq _081D311A
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x41
	movs r3, 0
	bl sub_81D2C68
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_81D2C68
	adds r6, r0, 0
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_81D2C68
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0x1
	str r1, [sp]
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl LoadSpecialPokePic
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GetFrontSpritePalFromSpeciesAndPersonality
	mov r1, r9
	bl LZ77UnCompWram
_081D311A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3094

	thumb_func_start sub_81D312C
sub_81D312C: @ 81D312C
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	adds r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	ble _081D3140
	movs r0, 0
	strh r0, [r1]
_081D3140:
	movs r0, 0
	ldrsh r1, [r1, r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D312C

	thumb_func_start sub_81D3150
sub_81D3150: @ 81D3150
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	subs r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x50
	negs r2, r2
	cmp r0, r2
	bge _081D3168
	strh r2, [r1]
_081D3168:
	movs r0, 0
	ldrsh r1, [r1, r0]
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D3150

	thumb_func_start sub_81D3178
sub_81D3178: @ 81D3178
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D312C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D319A
	cmp r0, 0
	beq _081D319C
_081D319A:
	movs r1, 0x1
_081D319C:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3178

	thumb_func_start sub_81D31A4
sub_81D31A4: @ 81D31A4
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D3150
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D31C6
	cmp r0, 0
	beq _081D31C8
_081D31C6:
	movs r1, 0x1
_081D31C8:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D31A4

	thumb_func_start sub_81D31D0
sub_81D31D0: @ 81D31D0
	push {r4-r7,lr}
	sub sp, 0x20
	ldr r3, =gUnknown_08625A48
	ldr r4, [r3]
	ldr r5, [r3, 0x4]
	str r4, [sp, 0x18]
	str r5, [sp, 0x1C]
	mov r4, sp
	ldr r3, =gUnknown_08625A50
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldr r3, =gUnknown_08625A68
	ldr r4, [r3, 0x4]
	ldr r3, [r3]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	str r5, [r0]
	str r6, [r0, 0x4]
	mov r0, sp
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	str r3, [r2]
	str r4, [r2, 0x4]
	add sp, 0x20
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D31D0

	thumb_func_start sub_81D321C
sub_81D321C: @ 81D321C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r5, r0, 0
	mov r12, r1
	mov r8, r2
	mov r1, sp
	ldr r0, =gUnknown_08625A70
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	add r3, sp, 0x20
	adds r1, r3, 0
	ldr r0, =gUnknown_08625A90
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	add r2, sp, 0x38
	adds r1, r2, 0
	ldr r0, =gUnknown_08625AA8
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	movs r4, 0
_081D3258:
	lsls r0, r4, 3
	add r0, sp
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081D3258
	mov r1, r12
	adds r0, r2, 0
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	movs r4, 0
_081D327A:
	lsls r0, r4, 3
	adds r0, r3, r0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	mov r5, r8
	adds r5, 0x8
	mov r8, r5
	subs r5, 0x8
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081D327A
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D321C

	thumb_func_start sub_81D32B0
sub_81D32B0: @ 81D32B0
	push {r4,r5,lr}
	ldr r2, =gUnknown_08625AC0
	ldr r4, [r2]
	ldr r5, [r2, 0x4]
	ldr r2, =gUnknown_08625AC8
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r4, [r0]
	str r5, [r0, 0x4]
	str r2, [r1]
	str r3, [r1, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32B0

	thumb_func_start sub_81D32D4
sub_81D32D4: @ 81D32D4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081D32F0
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r0, r1, 0
	bl sub_81D3408
_081D32F0:
	pop {r0}
	bx r0
	thumb_func_end sub_81D32D4

	thumb_func_start sub_81D32F4
sub_81D32F4: @ 81D32F4
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D330C
	movs r0, 0
	strh r0, [r2, 0x30]
	ldr r0, =sub_81D32D4
	str r0, [r2, 0x1C]
_081D330C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32F4

	thumb_func_start sub_81D3314
sub_81D3314: @ 81D3314
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r3, r1, r0
	cmp r3, 0
	beq _081D3360
	ldrh r1, [r3, 0x24]
	ldrh r2, [r3, 0x20]
	adds r1, r2
	ldr r2, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r1, [r3, 0x26]
	ldrh r3, [r3, 0x22]
	adds r1, r3
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r2, 0x2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	b _081D337E
	.pool
_081D3360:
	ldr r1, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x28
	strh r0, [r4, 0x20]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r1, 0x2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x68
_081D337E:
	strh r0, [r4, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3314

	thumb_func_start sub_81D338C
sub_81D338C: @ 81D338C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	movs r5, 0
_081D339E:
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq _081D33F0
	strh r5, [r0, 0x2E]
	ldr r1, [r4]
	lsls r0, r5, 4
	adds r0, 0x1
	strh r0, [r1, 0x30]
	ldr r0, [r4]
	strh r6, [r0, 0x32]
	ldr r0, [r4]
	strh r5, [r0, 0x34]
	cmp r7, 0
	beq _081D33C4
	cmp r6, 0x9
	beq _081D33D0
_081D33C4:
	ldr r1, [r4]
	ldr r0, =sub_81D3564
	str r0, [r1, 0x1C]
	b _081D33F0
	.pool
_081D33D0:
	ldr r0, [r4]
	bl sub_81D3314
	ldr r0, [r4]
	bl sub_81D35E8
	ldr r2, [r4]
	ldr r0, =sub_81D32F4
	str r0, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r3, 0x5
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
_081D33F0:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _081D339E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D338C

	thumb_func_start sub_81D3408
sub_81D3408: @ 81D3408
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	bge _081D3454
	ldr r5, =gSprites
	movs r7, 0x1C
	adds r7, r5
	mov r12, r7
	ldr r6, =sub_81D3564
_081D3428:
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r5
	movs r7, 0x2E
	ldrsh r0, [r2, r7]
	lsls r0, 4
	adds r0, 0x1
	strh r0, [r2, 0x30]
	add r1, r12
	str r6, [r1]
	ldrh r0, [r2, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	blt _081D3428
_081D3454:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3408

	thumb_func_start sub_81D3464
sub_81D3464: @ 81D3464
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	movs r3, 0
_081D346C:
	lsls r0, r1, 2
	adds r0, r2
	str r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _081D346C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3464

	thumb_func_start sub_81D3480
sub_81D3480: @ 81D3480
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	movs r0, 0
	mov r9, r0
	lsrs r7, r2, 24
	movs r5, 0
	adds r0, r7, 0x1
	cmp r9, r0
	bge _081D34FE
_081D34A2:
	ldr r0, =gUnknown_08625B14
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	cmp r3, 0x40
	beq _081D34FE
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r4]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	mov r1, r10
	strh r1, [r0, 0x36]
	cmp r5, 0
	beq _081D34F0
	subs r0, r4, 0x4
	ldr r0, [r0]
	strh r3, [r0, 0x38]
	b _081D34F2
	.pool
_081D34F0:
	mov r9, r6
_081D34F2:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r7, 0x1
	cmp r5, r0
	blt _081D34A2
_081D34FE:
	lsls r0, r7, 2
	add r0, r8
	ldr r0, [r0]
	mov r1, r9
	strh r1, [r0, 0x38]
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r8
	bl sub_81D338C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3480

	thumb_func_start sub_81D3520
sub_81D3520: @ 81D3520
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
_081D3526:
	cmp r5, 0x9
	bhi _081D3544
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	cmp r0, 0
	beq _081D3544
	bl DestroySprite
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _081D3526
_081D3544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3520

	thumb_func_start sub_81D354C
sub_81D354C: @ 81D354C
	push {lr}
	bl sub_81D3520
	movs r0, 0x68
	bl FreeSpriteTilesByTag
	movs r0, 0x68
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_81D354C

	thumb_func_start sub_81D3564
sub_81D3564: @ 81D3564
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081D3592
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _081D35DC
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081D3592:
	adds r0, r4, 0
	bl sub_81D3314
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D35DC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081D35D8
	cmp r1, 0x9
	bne _081D35D0
	adds r0, r4, 0
	bl sub_81D35E8
	ldr r0, =sub_81D32F4
	b _081D35DA
	.pool
_081D35D0:
	ldr r0, =sub_81D32D4
	b _081D35DA
	.pool
_081D35D8:
	ldr r0, =SpriteCallbackDummy
_081D35DA:
	str r0, [r4, 0x1C]
_081D35DC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3564

	thumb_func_start sub_81D35E8
sub_81D35E8: @ 81D35E8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r5, 0
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	bge _081D3636
	movs r0, 0x5
	negs r0, r0
	adds r7, r0, 0
_081D3604:
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r1, r4, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	ands r0, r7
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	blt _081D3604
_081D3636:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D35E8

	thumb_func_start sub_81D3640
sub_81D3640: @ 81D3640
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	ldr r3, [sp, 0x4C]
	ldr r0, [sp, 0x50]
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r3, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r2, sp, 0xC
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r6, 0x2]
	subs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r6, 0x4]
	subs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r5, 0x8]
	ldrh r1, [r6, 0x8]
	subs r0, r1
	strh r0, [r2, 0x6]
	ldrh r0, [r5, 0xA]
	ldrh r1, [r6, 0xA]
	subs r0, r1
	strh r0, [r2, 0x8]
	ldrh r0, [r5, 0x6]
	ldrh r1, [r6, 0x6]
	subs r0, r1
	strh r0, [r2, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	ldr r3, [sp, 0x28]
	strb r3, [r0, 0x1]
	mov r1, r9
	strb r1, [r0, 0x2]
	movs r7, 0
	mov r10, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	add r6, sp, 0x18
_081D36CA:
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	lsls r0, r7, 1
	mov r4, sp
	adds r4, r0
	adds r4, 0xC
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r1, =gText_Dash
	cmp r0, 0
	blt _081D3704
	ldr r1, =gText_UnkCtrlF904
_081D3704:
	adds r0, r6, 0
	bl StringCopy
	mov r0, r10
	str r0, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0x38
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081D372C
	negs r0, r1
_081D372C:
	movs r4, 0xC
	cmp r0, 0x9
	bgt _081D3734
	movs r4, 0x12
_081D3734:
	cmp r1, 0
	bge _081D373A
	negs r1, r1
_081D373A:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r2, r4, 0
	adds r2, 0x38
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _081D36CA
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3640

	thumb_func_start sub_81D3784
sub_81D3784: @ 81D3784
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	ldr r2, [sp, 0x4C]
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r2, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r1, sp, 0xC
	ldrh r0, [r5]
	strh r0, [r1]
	ldrh r0, [r5, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r5, 0x4]
	strh r0, [r1, 0x4]
	ldrh r0, [r5, 0x8]
	strh r0, [r1, 0x6]
	ldrh r0, [r5, 0xA]
	strh r0, [r1, 0x8]
	ldrh r0, [r5, 0x6]
	strh r0, [r1, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	strb r6, [r0, 0x1]
	ldr r2, [sp, 0x28]
	strb r2, [r0, 0x2]
	movs r6, 0
	add r1, sp, 0x18
	mov r9, r1
	mov r7, r8
	mov r10, r0
	movs r2, 0x1
	negs r2, r2
	mov r8, r2
_081D37EE:
	lsls r1, r6, 1
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r4, 0x3
	cmp r0, 0x63
	bgt _081D3808
	movs r4, 0x1
	cmp r0, 0x9
	ble _081D3808
	movs r4, 0x2
_081D3808:
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r0, r9
	movs r2, 0
	adds r3, r4, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0x4
	subs r0, r4
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 17
	lsrs r4, 16
	lsls r5, r6, 4
	subs r5, r6
	lsls r5, 24
	lsrs r5, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	mov r2, r10
	str r2, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _081D37EE
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3784

	thumb_func_start sub_81D388C
sub_81D388C: @ 81D388C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	strh r0, [r5, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	strh r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	strh r0, [r5, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	strh r0, [r5, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	strh r0, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D388C

	thumb_func_start sub_81D38D4
sub_81D38D4: @ 81D38D4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6d
	adds r0, r1
	ldrb r1, [r0]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 8
	lsls r0, 8
	subs r0, r2, r0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D38D4

	thumb_func_start sub_81D38FC
sub_81D38FC: @ 81D38FC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x9C
	lsls r5, 2
	adds r1, r5, 0
	bl CalcByteArraySum
	adds r4, r5
	ldr r1, [r4]
	cmp r0, r1
	bne _081D3916
	movs r0, 0x1
	b _081D3918
_081D3916:
	movs r0, 0
_081D3918:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D38FC

	thumb_func_start sub_81D3920
sub_81D3920: @ 81D3920
	push {r4-r7,lr}
	adds r7, r0, 0
	ldrb r6, [r7]
	subs r0, r6, 0x1
	cmp r0, 0x7
	bhi _081D3964
	movs r5, 0
	cmp r5, r6
	bcs _081D394C
	adds r4, r7, 0
	adds r4, 0x8
_081D3936:
	adds r0, r4, 0
	bl sub_81D38FC
	cmp r0, 0
	beq _081D3964
	movs r0, 0x9D
	lsls r0, 2
	adds r4, r0
	adds r5, 0x1
	cmp r5, r6
	bcc _081D3936
_081D394C:
	adds r0, r7, 0
	adds r0, 0x8
	movs r1, 0x9D
	lsls r1, 2
	muls r1, r6
	bl CalcByteArraySum
	ldr r1, [r7, 0x4]
	cmp r0, r1
	bne _081D3964
	movs r0, 0x1
	b _081D3966
_081D3964:
	movs r0, 0
_081D3966:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3920

	thumb_func_start sub_81D396C
sub_81D396C: @ 81D396C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _081D398E
	adds r0, r4, 0
	adds r0, 0x8
	movs r1, 0xEE
	lsls r1, 4
	bl CalcByteArraySum
	ldr r1, [r4, 0x4]
	cmp r0, r1
	bne _081D398E
	movs r0, 0x1
	b _081D3990
_081D398E:
	movs r0, 0
_081D3990:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D396C

	thumb_func_start sub_81D3998
sub_81D3998: @ 81D3998
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	mov r8, r1
	movs r2, 0x80
	lsls r2, 5
	mov r0, r8
	movs r1, 0
	bl memset
	ldrb r0, [r7]
	mov r1, r8
	strb r0, [r1]
	bl sub_81D38D4
	mov r2, r8
	strb r0, [r2, 0x1]
	ldrb r0, [r7]
	adds r0, 0x1
	asrs r0, 1
	strb r0, [r2, 0x2]
	movs r6, 0
	b _081D3A42
_081D39C8:
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	bne _081D3A14
	lsrs r0, r6, 31
	adds r0, r6, r0
	asrs r0, 1
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 3
	subs r4, r0
	lsls r4, 3
	add r4, r8
	movs r0, 0x9D
	lsls r0, 2
	adds r5, r6, 0
	muls r5, r0
	adds r5, r7, r5
	ldrb r0, [r5, 0x8]
	strb r0, [r4, 0x8]
	movs r1, 0xA7
	lsls r1, 2
	adds r0, r4, r1
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r5, r2
	subs r2, 0x30
	bl memcpy
	adds r4, 0xC
	adds r5, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA4
	lsls r2, 1
	bl memcpy
	b _081D3A40
_081D3A14:
	lsrs r1, r6, 31
	adds r1, r6, r1
	asrs r1, 1
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	add r0, r8
	movs r1, 0x9D
	lsls r1, 2
	muls r1, r6
	adds r1, r7, r1
	ldrb r2, [r1, 0x8]
	strb r2, [r0, 0x9]
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	adds r1, 0xC
	subs r2, 0xC
	bl memcpy
_081D3A40:
	adds r6, 0x1
_081D3A42:
	ldrb r0, [r7]
	cmp r6, r0
	blt _081D39C8
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	beq _081D3A7E
	lsrs r2, r6, 31
	adds r2, r6, r2
	asrs r2, 1
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	lsls r0, 3
	add r0, r8
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	ldr r3, =gUnknown_08625B6C
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r2
	lsls r1, 3
	adds r1, r3
	movs r2, 0xA4
	lsls r2, 1
	bl memcpy
_081D3A7E:
	mov r0, r8
	adds r0, 0x8
	movs r1, 0xEE
	lsls r1, 4
	bl CalcByteArraySum
	mov r2, r8
	str r0, [r2, 0x4]
	movs r0, 0x1E
	mov r1, r8
	bl sub_8153634
	cmp r0, 0x1
	bne _081D3AA4
	movs r0, 0x1
	b _081D3AA6
	.pool
_081D3AA4:
	movs r0, 0
_081D3AA6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3998

	thumb_func_start sub_81D3AB0
sub_81D3AB0: @ 81D3AB0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3998
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3AB0

	thumb_func_start sub_81D3AD8
sub_81D3AD8: @ 81D3AD8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0x1E
	bl TryCopySpecialSaveSection
	cmp r0, 0x1
	bne _081D3B04
	ldr r2, =0x00000ee8
	adds r0, r5, 0
	adds r1, r4, 0
	bl memcpy
	adds r0, r5, 0
	bl sub_81D396C
	cmp r0, 0
	beq _081D3B04
	movs r0, 0x1
	b _081D3B06
	.pool
_081D3B04:
	movs r0, 0
_081D3B06:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3AD8

	thumb_func_start sub_81D3B0C
sub_81D3B0C: @ 81D3B0C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3AD8
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3B0C

	thumb_func_start sub_81D3B34
sub_81D3B34: @ 81D3B34
	push {r4,r5,lr}
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r4, r0, 0
	bl sub_81D3B0C
	adds r5, r0, 0
	adds r0, r4, 0
	bl Free
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3B34

	thumb_func_start sub_81D3B54
sub_81D3B54: @ 81D3B54
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_81D41A0
	movs r7, 0x2
	ldr r4, =gShouldAdvanceLinkState
_081D3B64:
	bl sub_81D4170
	ldr r0, =gUnknown_030012E2
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D3B76
	strb r7, [r4]
_081D3B76:
	movs r0, 0x1
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	ldr r0, =gUnknown_030012E4
	strh r1, [r0]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D3BA0
	movs r4, 0
	b _081D3BC2
	.pool
_081D3BA0:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D3BAC
	movs r4, 0x1
	b _081D3BC2
_081D3BAC:
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081D3BC0
	strb r0, [r4]
	bl VBlankIntrWait
	b _081D3B64
_081D3BC0:
	movs r4, 0x2
_081D3BC2:
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	bl sub_81D41F4
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3B54

	thumb_func_start sub_81D3BE8
sub_81D3BE8: @ 81D3BE8
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	bl sub_81D41A0
	movs r6, 0x2
	ldr r4, =gShouldAdvanceLinkState
_081D3BF6:
	bl sub_81D4170
	ldr r0, =gUnknown_030012E2
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D3C08
	strb r6, [r4]
_081D3C08:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_81D3D70
	adds r1, r0, 0
	ldr r0, =gUnknown_030012E4
	strh r1, [r0]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D3C34
	movs r4, 0
	b _081D3C56
	.pool
_081D3C34:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D3C40
	movs r4, 0x1
	b _081D3C56
_081D3C40:
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081D3C54
	strb r0, [r4]
	bl VBlankIntrWait
	b _081D3BF6
_081D3C54:
	movs r4, 0x2
_081D3C56:
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	bl sub_81D41F4
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3BE8

	thumb_func_start sub_81D3C7C
sub_81D3C7C: @ 81D3C7C
	push {r4,lr}
	ldr r4, =0x04000208
	movs r3, 0
	strh r3, [r4]
	ldr r2, =0x04000200
	ldrh r1, [r2]
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r4]
	ldr r0, =0x04000128
	strh r3, [r0]
	subs r0, 0x1A
	strh r3, [r0]
	ldr r1, =0x04000202
	movs r0, 0xC0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3C7C

	thumb_func_start sub_81D3CBC
sub_81D3CBC: @ 81D3CBC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r5, =0x04000208
	movs r4, 0
	strh r4, [r5]
	ldr r3, =0x04000200
	ldrh r1, [r3]
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r3]
	movs r6, 0x1
	strh r6, [r5]
	ldr r0, =0x04000134
	strh r4, [r0]
	ldr r2, =0x04000128
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r7, =0x00004003
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	strh r4, [r5]
	ldrh r0, [r3]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r3]
	strh r6, [r5]
	ldr r1, =gUnknown_030012C8
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _081D3D0A
	str r0, [sp]
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
_081D3D0A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3CBC

	thumb_func_start sub_81D3D34
sub_81D3D34: @ 81D3D34
	ldr r0, =0x04000134
	movs r3, 0
	strh r3, [r0]
	ldr r2, =0x04000128
	movs r1, 0xA0
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strh r0, [r2]
	ldr r0, =gShouldAdvanceLinkState
	strb r3, [r0]
	ldr r0, =gUnknown_030012E6
	strh r3, [r0]
	ldr r1, =gUnknown_030012E8
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D3D34

	thumb_func_start sub_81D3D70
sub_81D3D70: @ 81D3D70
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030012C8
	ldrb r0, [r0, 0x1]
	cmp r0, 0x6
	bls _081D3D86
	b _081D3ECC
_081D3D86:
	lsls r0, 2
	ldr r1, =_081D3D98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D3D98:
	.4byte _081D3DB4
	.4byte _081D3DC8
	.4byte _081D3DE8
	.4byte _081D3DFC
	.4byte _081D3E74
	.4byte _081D3E84
	.4byte _081D3EBC
_081D3DB4:
	bl sub_81D3CBC
	ldr r1, =gUnknown_030012C8
	movs r0, 0x1
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3DC8:
	adds r0, r2, 0
	bl sub_81D3EE8
	lsls r0, 16
	cmp r0, 0
	beq _081D3DD8
	bl sub_81D413C
_081D3DD8:
	ldr r0, =gShouldAdvanceLinkState
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081D3DE2
	b _081D3ECC
_081D3DE2:
	b _081D3E04
	.pool
_081D3DE8:
	bl sub_81D3D34
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D3F1C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x3
	strb r0, [r1, 0x1]
_081D3DFC:
	ldr r0, =gShouldAdvanceLinkState
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081D3E18
_081D3E04:
	ldr r1, =gUnknown_030012C8
	strb r0, [r1, 0x4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3E18:
	ldr r2, =gUnknown_030012E6
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	ldr r1, =gUnknown_030012E8
	ldr r0, [r1]
	adds r3, r0, 0x1
	str r3, [r1]
	ldr r1, =gUnknown_030012C8
	ldrb r0, [r1]
	cmp r0, 0
	bne _081D3E3C
	cmp r3, 0x3C
	bls _081D3E3C
	movs r0, 0x1
	strb r0, [r1, 0x4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
_081D3E3C:
	ldr r4, =gUnknown_030012C8
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _081D3ECC
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D3E64
	ldrh r0, [r2]
	cmp r0, 0x2
	bls _081D3E64
	bl sub_81D413C
	movs r0, 0x2
	b _081D3ECA
	.pool
_081D3E64:
	bl sub_81D413C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x2
	strb r0, [r1, 0x2]
	b _081D3ECC
	.pool
_081D3E74:
	bl sub_81D3CBC
	ldr r1, =gUnknown_030012C8
	movs r0, 0x5
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3E84:
	ldr r0, =gUnknown_030012C8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081D3E98
	ldr r0, =gUnknown_030012E6
	ldrh r0, [r0]
	cmp r0, 0x2
	bls _081D3E98
	bl sub_81D413C
_081D3E98:
	ldr r1, =gUnknown_030012E6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3C
	bls _081D3ECC
	ldr r0, =gUnknown_030012C8
	movs r1, 0x1
	strb r1, [r0, 0x4]
	movs r1, 0x6
	strb r1, [r0, 0x1]
	b _081D3ECC
	.pool
_081D3EBC:
	ldr r4, =gUnknown_030012C8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _081D3ECC
	bl sub_81D3C7C
	movs r0, 0
_081D3ECA:
	strb r0, [r4, 0x2]
_081D3ECC:
	ldr r2, =gUnknown_030012C8
	ldrb r0, [r2, 0x2]
	ldrb r1, [r2, 0x4]
	lsls r1, 2
	orrs r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 4
	orrs r0, r1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3D70

	thumb_func_start sub_81D3EE8
sub_81D3EE8: @ 81D3EE8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =0x04000128
	ldr r0, [r0]
	movs r1, 0xC
	ands r0, r1
	cmp r0, 0x8
	bne _081D3F0C
	cmp r2, 0
	beq _081D3F0C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x1
	b _081D3F10
	.pool
_081D3F0C:
	ldr r1, =gUnknown_030012C8
	movs r0, 0
_081D3F10:
	strb r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3EE8

	thumb_func_start sub_81D3F1C
sub_81D3F1C: @ 81D3F1C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r3, =gUnknown_030012C8
	ldrb r0, [r3]
	cmp r0, 0
	beq _081D3F54
	ldr r2, =0x04000128
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	str r5, [r3, 0x8]
	ldr r0, =0x04000120
	str r4, [r0]
	lsrs r0, r4, 2
	adds r0, 0x1
	str r0, [r3, 0x10]
	bl sub_81D3F68
	b _081D3F5C
	.pool
_081D3F54:
	ldr r1, =0x04000128
	ldrh r0, [r1]
	strh r0, [r1]
	str r2, [r3, 0x8]
_081D3F5C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3F1C

	thumb_func_start sub_81D3F68
sub_81D3F68: @ 81D3F68
	ldr r1, =0x0400010c
	ldr r2, =0x0000fda7
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x0400010e
	movs r2, 0x40
	strh r2, [r0]
	ldr r3, =0x04000208
	movs r0, 0
	strh r0, [r3]
	adds r1, 0xF4
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	movs r0, 0x1
	strh r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_81D3F68

	thumb_func_start sub_81D3F9C
sub_81D3F9C: @ 81D3F9C
	push {lr}
	bl sub_81D414C
	bl sub_81D413C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3F9C

	thumb_func_start sub_81D3FAC
sub_81D3FAC: @ 81D3FAC
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r2, =gUnknown_030012C8
	ldrb r0, [r2, 0x1]
	adds r3, r2, 0
	cmp r0, 0x3
	beq _081D4034
	cmp r0, 0x3
	bgt _081D3FC8
	cmp r0, 0x1
	beq _081D3FD0
	b _081D412A
	.pool
_081D3FC8:
	cmp r0, 0x5
	bne _081D3FCE
	b _081D40FC
_081D3FCE:
	b _081D412A
_081D3FD0:
	ldr r1, =0x0400012a
	ldr r2, =0x0000ccd0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r2, 0
	movs r4, 0
	ldr r6, =0x0000ccd0
	ldr r5, =0x0000ffff
_081D3FEC:
	lsls r0, r1, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D4010
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	b _081D401A
	.pool
_081D4010:
	cmp r0, r5
	beq _081D401A
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081D401A:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bls _081D3FEC
	cmp r2, 0x2
	beq _081D402A
	b _081D412A
_081D402A:
	cmp r4, 0
	beq _081D4030
	b _081D412A
_081D4030:
	strb r2, [r3, 0x1]
	b _081D412A
_081D4034:
	ldr r0, =0x04000120
	ldr r4, [r0]
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _081D404A
	ldrb r0, [r2]
	cmp r0, 0
	bne _081D404A
	lsrs r0, r4, 2
	adds r0, 0x1
	str r0, [r2, 0x10]
_081D404A:
	ldrb r0, [r3]
	cmp r0, 0x1
	bne _081D4080
	ldr r1, [r3, 0xC]
	ldr r0, [r3, 0x10]
	cmp r1, r0
	bge _081D4074
	ldr r2, =0x04000120
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r3, 0x14]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r3, 0x14]
	b _081D40BA
	.pool
_081D4074:
	ldr r1, =0x04000120
	ldr r0, [r3, 0x14]
	b _081D40B8
	.pool
_081D4080:
	ldr r1, [r3, 0xC]
	cmp r1, 0
	ble _081D40A0
	ldr r0, [r3, 0x10]
	adds r0, 0x1
	cmp r1, r0
	bge _081D40A0
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	subs r1, 0x4
	str r4, [r1]
	ldr r0, [r3, 0x14]
	adds r0, r4
	str r0, [r3, 0x14]
	b _081D40B4
_081D40A0:
	ldr r0, [r3, 0xC]
	cmp r0, 0
	beq _081D40B4
	ldr r0, [r3, 0x14]
	cmp r0, r4
	bne _081D40B0
	movs r0, 0x1
	b _081D40B2
_081D40B0:
	movs r0, 0x2
_081D40B2:
	strb r0, [r3, 0x3]
_081D40B4:
	ldr r1, =gUnknown_030012E8
	movs r0, 0
_081D40B8:
	str r0, [r1]
_081D40BA:
	ldr r1, [r3, 0xC]
	adds r1, 0x1
	str r1, [r3, 0xC]
	ldr r0, [r3, 0x10]
	adds r0, 0x2
	cmp r1, r0
	bge _081D40EA
	ldrb r0, [r3]
	cmp r0, 0
	beq _081D40E4
	ldr r0, =0x0400010e
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	b _081D412A
	.pool
_081D40E4:
	bl sub_81D413C
	b _081D412A
_081D40EA:
	movs r0, 0
	movs r1, 0x4
	strb r1, [r3, 0x1]
	ldr r1, =gUnknown_030012E6
	strh r0, [r1]
	b _081D412A
	.pool
_081D40FC:
	ldrb r3, [r2]
	cmp r3, 0
	bne _081D4108
	ldr r1, =0x0400012a
	ldrb r0, [r2, 0x3]
	strh r0, [r1]
_081D4108:
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r1, [r0, 0x2]
	subs r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D412A
	cmp r3, 0x1
	bne _081D4126
	strb r1, [r2, 0x3]
_081D4126:
	movs r0, 0x6
	strb r0, [r2, 0x1]
_081D412A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3FAC

	thumb_func_start sub_81D413C
sub_81D413C: @ 81D413C
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D413C

	thumb_func_start sub_81D414C
sub_81D414C: @ 81D414C
	ldr r2, =0x0400010e
	ldrh r1, [r2]
	ldr r0, =0x0000ff7f
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0400010c
	ldr r2, =0x0000fda7
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D414C

	thumb_func_start sub_81D4170
sub_81D4170: @ 81D4170
	push {r4,lr}
	ldr r0, =0x04000130
	ldrh r0, [r0]
	ldr r2, =0x000003ff
	adds r1, r2, 0
	eors r1, r0
	ldr r4, =gUnknown_030012E2
	ldr r3, =gUnknown_030012E0
	ldrh r2, [r3]
	adds r0, r1, 0
	bics r0, r2
	strh r0, [r4]
	strh r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4170

	thumb_func_start sub_81D41A0
sub_81D41A0: @ 81D41A0
	ldr r1, =gUnknown_030012EC
	ldr r0, =0x04000208
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012EE
	ldr r0, =0x04000200
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F0
	ldr r0, =0x0400010e
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F2
	ldr r0, =0x04000128
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F4
	ldr r0, =0x04000134
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D41A0

	thumb_func_start sub_81D41F4
sub_81D41F4: @ 81D41F4
	ldr r1, =0x04000208
	ldr r0, =gUnknown_030012EC
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =gUnknown_030012EE
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, 0xF2
	ldr r0, =gUnknown_030012F0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0x1A
	ldr r0, =gUnknown_030012F2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0xC
	ldr r0, =gUnknown_030012F4
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D41F4

	thumb_func_start sub_81D4238
sub_81D4238: @ 81D4238
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4238

	thumb_func_start sub_81D4258
sub_81D4258: @ 81D4258
	push {lr}
	sub sp, 0x4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x1
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4258

	thumb_func_start sub_81D427C
sub_81D427C: @ 81D427C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r2, =gEventObjects
	adds r5, r1, r2
	ldr r4, =gUnknown_030012F8
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x14]
	ldrh r1, [r5, 0x10]
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gUnknown_030012FA
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x16]
	ldrh r1, [r5, 0x12]
	subs r0, r1
	strh r0, [r4]
	movs r0, 0
	mov r8, r0
	ldr r2, =gUnknown_030012FC
	movs r1, 0
_081D42CA:
	mov r3, r8
	adds r0, r3, r2
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bls _081D42CA
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	movs r4, 0x14
	ldrsh r1, [r2, r4]
	movs r6, 0x10
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bne _081D4304
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	movs r3, 0x12
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _081D4356
_081D4304:
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	cmp r1, 0
	bne _081D4338
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	b _081D433E
	.pool
_081D4338:
	ldrb r0, [r5, 0x1]
	movs r1, 0x20
	orrs r0, r1
_081D433E:
	strb r0, [r5, 0x1]
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D4360
_081D4356:
	movs r0, 0
	b _081D4816
	.pool
_081D4360:
	movs r4, 0
	mov r8, r4
	ldr r6, =gEventObjects
	mov r10, r6
_081D4368:
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r4, r0, r1
	mov r2, r8
	lsls r1, r2, 2
	ldr r6, =gUnknown_0862608C
	adds r0, r1, r6
	movs r6, 0x14
	ldrsh r2, [r4, r6]
	movs r6, 0
	ldrsh r0, [r0, r6]
	ldr r6, =gEventObjects
	mov r9, r6
	mov r12, r3
	adds r7, r1, 0
	cmp r2, r0
	beq _081D4394
	b _081D449E
_081D4394:
	movs r3, 0
	ldr r1, =gUnknown_0862608C + 2
	adds r0, r7, r1
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D43C0
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D43CA
	b _081D449E
	.pool
_081D43C0:
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D43CA
	movs r3, 0x1
_081D43CA:
	cmp r3, 0
	bne _081D449E
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4410
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
_081D4408:
	movs r0, 0x4
	b _081D4816
	.pool
_081D4410:
	cmp r0, 0
	bge _081D4446
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
	b _081D45AA
_081D4446:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	movs r4, 0x14
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _081D449E
	ldr r0, =gUnknown_030012FA
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	ble _081D4488
	adds r0, r1, 0
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D449E
_081D447C:
	movs r0, 0x2
	b _081D4816
	.pool
_081D4488:
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	bne _081D4538
_081D449E:
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r3, r10
	adds r4, r0, r3
	ldr r6, =gUnknown_0862608C
	ldr r1, =gUnknown_0862608C + 2
	adds r0, r7, r1
	movs r3, 0x16
	ldrsh r1, [r4, r3]
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r3, =gEventObjects
	mov r9, r3
	mov r12, r2
	cmp r1, r0
	beq _081D44C6
	b _081D45D0
_081D44C6:
	movs r3, 0
	adds r0, r7, r6
	movs r6, 0x14
	ldrsh r1, [r4, r6]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D44F0
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D44FA
	b _081D45D0
	.pool
_081D44F0:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D44FA
	movs r3, 0x1
_081D44FA:
	cmp r3, 0
	bne _081D45D0
	ldr r0, =gUnknown_030012FA
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4540
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
_081D4538:
	movs r0, 0x1
	b _081D4816
	.pool
_081D4540:
	cmp r0, 0
	bge _081D4576
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
	b _081D447C
_081D4576:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	movs r3, 0x16
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _081D45D0
	ldr r0, =gUnknown_030012F8
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	ble _081D45B8
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
_081D45AA:
	movs r0, 0x3
	b _081D4816
	.pool
_081D45B8:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
	b _081D4408
_081D45D0:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bhi _081D45E0
	b _081D4368
_081D45E0:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D461C
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4604
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4604:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4614
	b _081D447C
_081D4614:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D461C:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	beq _081D4658
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4640
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4640:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4650
	b _081D4538
_081D4650:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4658:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4694
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D467C
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D467C:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D468C
	b _081D4408
_081D468C:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4694:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	beq _081D46D0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D46B8
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46B8:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D46C8
	b _081D45AA
_081D46C8:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46D0:
	ldr r0, =gUnknown_030012FA
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _081D476E
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r4, 0x12
	ldrsh r1, [r0, r4]
	ldrh r2, [r5, 0x12]
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D470C
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	subs r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D470C
	b _081D447C
_081D470C:
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x12]
	movs r3, 0x12
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D473E
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	adds r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D473E
	b _081D4538
_081D473E:
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4756
	b _081D447C
_081D4756:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D476E
	b _081D4538
_081D476E:
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081D480C
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	ldrh r2, [r5, 0x10]
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	cmp r1, r0
	ble _081D47AA
	subs r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47AA
	b _081D45AA
_081D47AA:
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x10]
	movs r3, 0x10
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D47DC
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r4, 0x12
	ldrsh r1, [r5, r4]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47DC
	b _081D4408
_081D47DC:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47F4
	b _081D4408
_081D47F4:
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D480C
	b _081D45AA
_081D480C:
	movs r0, 0
	bl sub_81D4890
_081D4812:
	lsls r0, 24
	lsrs r0, 24
_081D4816:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D427C

	thumb_func_start sub_81D4834
sub_81D4834: @ 81D4834
	push {r4,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gEventObjects
	ldr r1, =gPlayerAvatar
	ldrb r2, [r1, 0x5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r3
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0x12
	ldrsh r1, [r2, r0]
	lsls r0, r4, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0
	b _081D4888
	.pool
_081D4870:
	lsls r0, r3, 16
	asrs r0, 16
	lsls r1, r4, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsPokeGrass
	lsls r0, 24
	lsrs r0, 24
_081D4888:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4834

	thumb_func_start sub_81D4890
sub_81D4890: @ 81D4890
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r4, r1, r0
	movs r1, 0
	ldr r3, =gUnknown_030012FC
	movs r2, 0
_081D48B0:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D48B0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D48E8
	cmp r6, 0x2
	beq _081D48E8
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D48E8:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4912
	cmp r6, 0x4
	beq _081D4912
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4912:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _081D493A
	cmp r6, 0x1
	beq _081D493A
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D493A:
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4964
	cmp r6, 0x3
	beq _081D4964
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x3
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4964:
	cmp r5, 0x1
	bhi _081D4974
	ldr r0, =gUnknown_030012FC
	b _081D4988
	.pool
_081D4974:
	ldr r4, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	adds r0, r4
_081D4988:
	ldrb r0, [r0]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4890

	thumb_func_start sub_81D4998
sub_81D4998: @ 81D4998
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D49E0
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000270e
	cmp r2, r0
	bls _081D49D8
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	b _081D49E0
	.pool
_081D49D8:
	adds r0, r4, 0
	adds r1, r2, 0
	bl VarSet
_081D49E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D4998

	thumb_func_start EventObjectIsFarawayIslandMew
@ bool8 EventObjectIsFarawayIslandMew(struct npc_state *eventObject)
EventObjectIsFarawayIslandMew: @ 81D49E8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A0C
	ldrb r0, [r2, 0x5]
	cmp r0, 0xE5
	bne _081D4A0C
	movs r0, 0x1
	b _081D4A0E
	.pool
_081D4A0C:
	movs r0, 0
_081D4A0E:
	pop {r1}
	bx r1
	thumb_func_end EventObjectIsFarawayIslandMew

	thumb_func_start IsMewPlayingHideAndSeek
IsMewPlayingHideAndSeek: @ 81D4A14
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A50
	movs r0, 0xE5
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	ldr r0, =0x000002ce
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	movs r0, 0x1
	b _081D4A52
	.pool
_081D4A50:
	movs r0, 0
_081D4A52:
	pop {r1}
	bx r1
	thumb_func_end IsMewPlayingHideAndSeek

	thumb_func_start sub_81D4A58
sub_81D4A58: @ 81D4A58
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _081D4A88
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _081D4A88
	movs r0, 0x1
	b _081D4A8A
	.pool
_081D4A88:
	movs r0, 0
_081D4A8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4A58

	thumb_func_start sub_81D4A90
sub_81D4A90: @ 81D4A90
	push {r4-r6,lr}
	sub sp, 0x4
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r5, r1, r0
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r0, =gSpecialVar_0x8004
	ldrh r4, [r0]
	cmp r4, 0x1
	bne _081D4AF8
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r3, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x43
	strb r4, [r0]
	b _081D4BC4
	.pool
_081D4AF8:
	ldr r0, =0x0000403a
	ldr r1, =0x0000ffff
	bl VarSet
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r6, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gSpecialVar_Facing
	ldrh r0, [r0]
	cmp r0, 0x2
	beq _081D4B3A
	ldrb r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
_081D4B3A:
	ldr r4, =gFieldEffectObjectPaletteInfo1
	adds r0, r4, 0
	bl LoadSpritePalette
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	bl UpdateSpritePaletteWithWeather
	ldrh r1, [r5, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x3C]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	ldrb r4, [r5, 0x4]
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r3, r6
	adds r3, 0x43
	ldrb r3, [r3]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSpriteAtEnd
	ldr r1, =gUnknown_0203CF50
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081D4BC4
	ldrb r0, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_081D4BC4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4A90

	thumb_func_start sub_81D4BEC
sub_81D4BEC: @ 81D4BEC
	push {lr}
	ldr r1, =gUnknown_0203CF50
	ldrb r0, [r1]
	cmp r0, 0x40
	beq _081D4C06
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_081D4C06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4BEC

	thumb_func_start sub_81D4C14
sub_81D4C14: @ 81D4C14
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4C50
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C50
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C52
	.pool
_081D4C50:
	movs r0, 0
_081D4C52:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C14

	thumb_func_start sub_81D4C58
sub_81D4C58: @ 81D4C58
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4C94
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C94
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x4
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C96
	.pool
_081D4C94:
	movs r0, 0
_081D4C96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C58

	thumb_func_start sub_81D4C9C
sub_81D4C9C: @ 81D4C9C
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4CD8
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4CD8
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	b _081D4CDA
	.pool
_081D4CD8:
	movs r0, 0
_081D4CDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C9C

	thumb_func_start sub_81D4CE0
sub_81D4CE0: @ 81D4CE0
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4D1C
	ldrh r0, [r2, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4D1C
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x3
	strb r1, [r0]
	movs r0, 0x1
	b _081D4D1E
	.pool
_081D4D1C:
	movs r0, 0
_081D4D1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4CE0

	thumb_func_start sub_81D4D24
sub_81D4D24: @ 81D4D24
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	adds r0, r5
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4D24

	thumb_func_start sub_81D4D50
sub_81D4D50: @ 81D4D50
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	ldr r1, =gIntrTable
	ldr r0, =sub_81D3FAC
	str r0, [r1, 0x4]
	ldr r0, =sub_81D3F9C
	str r0, [r1, 0x8]
	bl sub_81D41A0
	bl sub_81D4238
	ldr r2, =0x04000200
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	strh r0, [r5]
	str r6, [r5, 0x4]
	mov r0, r8
	str r0, [r5, 0x8]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4D50

	thumb_func_start sub_81D4DB8
sub_81D4DB8: @ 81D4DB8
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	bl sub_81D4238
	bl sub_81D41F4
	bl RestoreSerialTimer3IntrHandlers
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4DB8

	thumb_func_start sub_81D4DE8
sub_81D4DE8: @ 81D4DE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	movs r0, 0x1
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	strh r1, [r4]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D4E08
	movs r5, 0x1
_081D4E08:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D4E12
	movs r5, 0x2
_081D4E12:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D4E1C
	movs r5, 0x3
_081D4E1C:
	ldr r1, =gShouldAdvanceLinkState
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4DE8

	thumb_func_start sub_81D4E30
sub_81D4E30: @ 81D4E30
	push {lr}
	ldr r0, =gDecompressionBuffer
	movs r2, 0x80
	lsls r2, 6
	movs r1, 0
	bl memset
	ldr r1, =gLinkType
	ldr r2, =0x00005503
	adds r0, r2, 0
	strh r0, [r1]
	bl OpenLink
	movs r0, 0x1
	bl SetSuppressLinkErrorMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4E30

	thumb_func_start sub_81D4E60
sub_81D4E60: @ 81D4E60
	push {lr}
	sub sp, 0xC
	mov r1, sp
	ldr r2, =0x04000208
	ldrh r0, [r2]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r2]
	ldr r0, =gLink+0x4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2]
	add r2, sp, 0x4
	ldrh r1, [r2]
	ldr r0, =0x0000b9a0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ccd0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x4]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081D4EB8
	ldrh r0, [r2, 0x6]
	cmp r0, r1
	bne _081D4EB8
	movs r0, 0x1
	b _081D4EBA
	.pool
_081D4EB8:
	movs r0, 0
_081D4EBA:
	add sp, 0xC
	pop {r1}
	bx r1
	thumb_func_end sub_81D4E60

	thumb_func_start sub_81D4EC0
sub_81D4EC0: @ 81D4EC0
	push {lr}
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4EDC
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4EDC
	movs r0, 0x1
	b _081D4EDE
_081D4EDC:
	movs r0, 0
_081D4EDE:
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EC0

	thumb_func_start sub_81D4EE4
sub_81D4EE4: @ 81D4EE4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081D4F08
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D4F08
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x3
	b _081D500E
_081D4F08:
	ldrb r0, [r4]
	cmp r0, 0x5
	bls _081D4F10
	b _081D500C
_081D4F10:
	lsls r0, 2
	ldr r1, =_081D4F20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D4F20:
	.4byte _081D4F38
	.4byte _081D4F54
	.4byte _081D4F6C
	.4byte _081D4FA0
	.4byte _081D4FEC
	.4byte _081D4FF8
_081D4F38:
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4F88
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D4F88
	movs r0, 0x1
	strb r0, [r4]
	b _081D500C
_081D4F54:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _081D500C
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x2
	strb r0, [r4]
	b _081D500C
_081D4F6C:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4F88
	movs r0, 0x49
	bl PlaySE
	bl sub_800A620
	movs r0, 0
	strh r0, [r5]
	b _081D4FE6
_081D4F88:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D500C
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x1
	b _081D500E
	.pool
_081D4FA0:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _081D4FB6
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x5
	b _081D500E
_081D4FB6:
	bl IsLinkConnectionEstablished
	lsls r0, 24
	cmp r0, 0
	beq _081D500C
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D4FE6
	bl IsLinkPlayerDataExchangeComplete
	lsls r0, 24
	cmp r0, 0
	beq _081D4FE0
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x2
	b _081D500E
	.pool
_081D4FE0:
	movs r0, 0x4
	strb r0, [r4]
	b _081D500C
_081D4FE6:
	movs r0, 0x3
	strb r0, [r4]
	b _081D500C
_081D4FEC:
	movs r0, 0
	bl sub_800ABF4
	movs r0, 0x5
	strb r0, [r4]
	b _081D500C
_081D4FF8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D500C
	strb r0, [r4]
	movs r0, 0x4
	b _081D500E
	.pool
_081D500C:
	movs r0, 0
_081D500E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EE4

	thumb_func_start sub_81D5014
sub_81D5014: @ 81D5014
	push {r4,lr}
	ldr r0, =sub_81D5084
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0
	strb r0, [r4, 0x8]
	strb r0, [r4, 0x9]
	strb r0, [r4, 0xA]
	strb r0, [r4, 0xB]
	strb r0, [r4, 0xC]
	strb r0, [r4, 0xD]
	movs r1, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	strb r1, [r4, 0xE]
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5014

	thumb_func_start sub_81D505C
sub_81D505C: @ 81D505C
	movs r1, 0
	strh r1, [r0]
	bx lr
	thumb_func_end sub_81D505C

	thumb_func_start sub_81D5064
sub_81D5064: @ 81D5064
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, r1
	bhi _081D507A
	movs r0, 0
	b _081D5080
_081D507A:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
_081D5080:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5064

	thumb_func_start sub_81D5084
sub_81D5084: @ 81D5084
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1A
	bls _081D509C
	b _081D548A
_081D509C:
	lsls r0, 2
	ldr r1, =_081D50B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D50B0:
	.4byte _081D511C
	.4byte _081D5138
	.4byte _081D5148
	.4byte _081D515C
	.4byte _081D516C
	.4byte _081D5198
	.4byte _081D51D0
	.4byte _081D524C
	.4byte _081D5268
	.4byte _081D5290
	.4byte _081D52AC
	.4byte _081D52DC
	.4byte _081D52F2
	.4byte _081D5308
	.4byte _081D536A
	.4byte _081D5390
	.4byte _081D53A8
	.4byte _081D53C6
	.4byte _081D53F2
	.4byte _081D5418
	.4byte _081D5448
	.4byte _081D5454
	.4byte _081D5460
	.4byte _081D5430
	.4byte _081D548A
	.4byte _081D548A
	.4byte _081D5478
_081D511C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFD6
	bl mevent_0814257C
	cmp r0, 0
	bne _081D512C
	b _081D548A
_081D512C:
	movs r0, 0x1
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5138:
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _081D548A
_081D5148:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D5156
	b _081D548A
_081D5156:
	movs r0, 0x3
	strb r0, [r4, 0x8]
	b _081D548A
_081D515C:
	bl sub_81D4EC0
	cmp r0, 0
	beq _081D5166
	b _081D52FC
_081D5166:
	bl CloseLink
	b _081D525C
_081D516C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFF5
	bl mevent_0814257C
	cmp r0, 0
	bne _081D517C
	b _081D548A
_081D517C:
	ldr r0, =gUnknown_085EE014
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5198:
	adds r0, r4, 0
	movs r1, 0x5A
	bl sub_81D5064
	cmp r0, 0
	beq _081D51AE
	bl sub_81D4E30
	movs r0, 0x6
	strb r0, [r4, 0x8]
	b _081D548A
_081D51AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D51BC
	b _081D548A
_081D51BC:
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	bl PlaySE
	b _081D535A
	.pool
_081D51D0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D51F4
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	b _081D535A
	.pool
_081D51F4:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D5210
	adds r0, r4, 0
	bl sub_81D505C
	bl CloseLink
	movs r0, 0x7
	strb r0, [r4, 0x8]
	b _081D548A
_081D5210:
	bl sub_81D4E60
	cmp r0, 0
	beq _081D522E
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x8
	strb r0, [r4, 0x8]
	b _081D548A
_081D522E:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D523C
	b _081D548A
_081D523C:
	bl CloseLink
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	b _081D548A
_081D524C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE05C
	bl mevent_0814257C
	cmp r0, 0
	bne _081D525C
	b _081D548A
_081D525C:
	movs r0, 0x4
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5268:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	ldr r0, =gUnknown_03006370
	ldr r1, =gMultiBootProgram_BerryGlitchFix_Start
	ldr r2, =gUnknown_089A3470
	subs r1, r2
	bl sub_81D4D50
	movs r0, 0x9
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5290:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DE8
	strb r0, [r4, 0xE]
	lsls r0, 24
	cmp r0, 0
	bne _081D52A0
	b _081D548A
_081D52A0:
	movs r0, 0xA
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52AC:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DB8
	ldrb r0, [r4, 0xE]
	cmp r0, 0x3
	bne _081D52BA
	b _081D53C0
_081D52BA:
	cmp r0, 0x1
	beq _081D52C0
	b _081D546E
_081D52C0:
	adds r0, r4, 0
	bl sub_81D505C
	ldr r0, =gUnknown_085EE120
	bl sub_8018884
	movs r0, 0xB
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52DC:
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r4, 0
	bl sub_81D5064
	cmp r0, 0
	bne _081D52EC
	b _081D548A
_081D52EC:
	movs r0, 0xC
	strb r0, [r4, 0x8]
	b _081D548A
_081D52F2:
	bl sub_81D4E30
	ldr r0, =gUnknown_085EE0DC
	bl sub_8018884
_081D52FC:
	movs r0, 0xD
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5308:
	adds r0, r4, 0
	adds r0, 0x9
	adds r1, r4, 0
	bl sub_81D4EE4
	cmp r0, 0x5
	bls _081D5318
	b _081D548A
_081D5318:
	lsls r0, 2
	ldr r1, =_081D5328
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D5328:
	.4byte _081D548A
	.4byte _081D5350
	.4byte _081D5340
	.4byte _081D5374
	.4byte _081D5374
	.4byte _081D5360
_081D5340:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	movs r0, 0xE
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5350:
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
_081D535A:
	movs r0, 0x17
	strb r0, [r4, 0x8]
	b _081D548A
_081D5360:
	bl CloseLink
	movs r0, 0x15
	strb r0, [r4, 0x8]
	b _081D548A
_081D536A:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D537A
_081D5374:
	bl CloseLink
	b _081D53C0
_081D537A:
	bl GetBlockReceivedStatus
	lsls r0, 24
	cmp r0, 0
	bne _081D5386
	b _081D548A
_081D5386:
	bl ResetBlockReceivedFlags
	movs r0, 0xF
	strb r0, [r4, 0x8]
	b _081D548A
_081D5390:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3920
	strb r0, [r4, 0xE]
	ldrb r0, [r4, 0xE]
	bl sub_800ABF4
	movs r0, 0x10
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53A8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D548A
	ldrb r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081D53C0
	movs r0, 0x11
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53C0:
	movs r0, 0x14
	strb r0, [r4, 0x8]
	b _081D548A
_081D53C6:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3AB0
	cmp r0, 0
	beq _081D53EC
	ldr r0, =gUnknown_085EE0FA
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x12
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53EC:
	movs r0, 0x16
	strb r0, [r4, 0x8]
	b _081D548A
_081D53F2:
	adds r0, r4, 0
	movs r1, 0x78
	bl sub_81D5064
	cmp r0, 0
	beq _081D548A
	ldr r0, =gUnknown_085EE107
	bl sub_8018884
	movs r0, 0xB9
	lsls r0, 1
	bl PlayFanfare
	movs r0, 0x13
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5418:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _081D548A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	b _081D543A
	.pool
_081D5430:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE06B
	bl mevent_0814257C
_081D543A:
	cmp r0, 0
	beq _081D548A
	movs r0, 0x1A
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5448:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0A3
	b _081D5466
	.pool
_081D5454:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0BF
	b _081D5466
	.pool
_081D5460:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE12D
_081D5466:
	bl mevent_0814257C
	cmp r0, 0
	beq _081D548A
_081D546E:
	movs r0, 0
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5478:
	ldr r0, [r4, 0x10]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =sub_80186A4
	bl SetMainCallback2
_081D548A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5084

	.align 2, 0 @ Don't pad with nop.
