	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8021A28
sub_8021A28: @ 8021A28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsls r3, 24
	movs r0, 0
	str r0, [sp, 0x18]
	movs r1, 0
	str r1, [sp, 0x1C]
	ldr r2, [sp, 0xC]
	adds r2, 0x68
	str r2, [sp, 0x20]
	movs r4, 0xF0
	lsls r4, 24
	adds r3, r4
	lsrs r3, 24
	ldr r0, [sp, 0x10]
	cmp r0, 0x2
	bne _08021A68
	adds r0, r3, 0
	subs r0, 0x2A
	lsls r0, 24
	lsrs r3, r0, 24
_08021A68:
	ldr r2, [sp, 0xC]
	ldrb r1, [r2, 0x9]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	subs r6, r3, r0
	cmp r6, 0
	ble _08021A84
	lsrs r0, r6, 31
	adds r0, r6, r0
	asrs r0, 1
	adds r6, r0, 0
	adds r6, 0x10
	b _08021A86
_08021A84:
	movs r6, 0x10
_08021A86:
	movs r5, 0
	ldr r3, [sp, 0xC]
	ldrb r3, [r3, 0x9]
	cmp r5, r3
	bcc _08021A92
	b _08021D14
_08021A92:
	ldr r4, [sp, 0x10]
	lsls r4, 2
	str r4, [sp, 0x24]
_08021A98:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	beq _08021B48
	cmp r0, 0x1
	bgt _08021AC0
	cmp r0, 0
	beq _08021ADE
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r1, r6, 24
	mov r10, r1
	ldr r2, [sp, 0x1C]
	adds r2, 0xA2
	mov r9, r2
	ldr r3, [sp, 0x18]
	lsls r3, 5
	mov r8, r3
	b _08021C5A
_08021AC0:
	ldr r4, [sp, 0x10]
	cmp r4, 0x2
	bne _08021AC8
	b _08021C1C
_08021AC8:
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r0, r6, 24
	mov r10, r0
	ldr r1, [sp, 0x1C]
	adds r1, 0xA2
	mov r9, r1
	ldr r2, [sp, 0x18]
	lsls r2, 5
	mov r8, r2
	b _08021C5A
_08021ADE:
	ldr r0, [sp, 0x20]
	adds r0, 0x20
	adds r0, r5
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	lsls r3, r5, 1
	ldr r2, [sp, 0x20]
	adds r2, 0xC
	cmp r5, 0
	beq _08021B04
	adds r0, r2, r3
	subs r1, r5, 0x1
	lsls r1, 1
	adds r1, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08021B04
	str r5, [sp, 0x1C]
_08021B04:
	ldr r4, [sp, 0x24]
	ldr r1, [sp, 0x10]
	adds r0, r4, r1
	lsls r0, 1
	adds r0, r3, r0
	adds r0, r2, r0
	ldrh r1, [r0]
	ldr r0, =gStringVar4
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_082F43B4
	adds r0, r4, r0
	ldr r1, [r0]
	ldr r0, =gStringVar4
	bl StringAppend
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r2, r6, 24
	mov r10, r2
	ldr r3, [sp, 0x1C]
	adds r3, 0xA2
	mov r9, r3
	ldr r0, [sp, 0x18]
	lsls r0, 5
	mov r8, r0
	b _08021C5A
	.pool
_08021B48:
	ldr r1, [sp, 0x20]
	adds r0, r1, r5
	adds r0, 0x28
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	lsls r3, r5, 1
	adds r2, r1, 0
	adds r2, 0xC
	cmp r5, 0
	beq _08021B72
	adds r0, r3, 0
	adds r0, 0xA
	adds r0, r2, r0
	adds r1, r3, 0
	adds r1, 0x8
	adds r1, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08021B72
	str r5, [sp, 0x1C]
_08021B72:
	ldr r0, [sp, 0x24]
	ldr r1, [sp, 0x10]
	adds r4, r0, r1
	lsls r4, 1
	adds r4, r3, r4
	adds r4, r2, r4
	ldrh r1, [r4]
	lsrs r1, 4
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r7, 0
	ldrb r0, [r4]
	movs r3, 0xF
	ands r3, r0
	movs r2, 0
	ldr r4, [sp, 0x10]
	lsls r4, 2
	str r4, [sp, 0x28]
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r0, r6, 24
	mov r10, r0
	ldr r1, [sp, 0x1C]
	adds r1, 0xA2
	mov r9, r1
	ldr r0, [sp, 0x18]
	lsls r0, 5
	mov r8, r0
	adds r6, 0xE
	adds r5, 0x1
	ldr r1, =gUnknown_082F334C
	mov r12, r1
_08021BB8:
	movs r0, 0x3
	subs r1, r0, r2
	adds r0, r3, 0
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08021BD0
	lsls r0, r2, 2
	add r0, r12
	ldr r0, [r0]
	adds r7, r0
_08021BD0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _08021BB8
	adds r0, r7, 0
	ldr r1, =0x000f4240
	bl __udivsi3
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gStringVar2
	adds r1, r3, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_082F43B4
	ldr r2, [sp, 0x28]
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
	b _08021C5E
	.pool
_08021C1C:
	str r5, [sp, 0x18]
	str r5, [sp, 0x1C]
	lsls r7, r5, 5
	ldr r3, [sp, 0xC]
	adds r0, r3, r7
	adds r0, 0xA4
	ldrb r2, [r0]
	cmp r2, 0x2B
	bls _08021C30
	movs r2, 0
_08021C30:
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, =gBerries
	adds r1, r0
	ldr r0, =gStringVar1
	bl StringCopy
	ldr r0, =gUnknown_082F43B4
	ldr r1, [r0, 0x8]
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r0, r6, 24
	mov r10, r0
	movs r1, 0xA2
	adds r1, r5
	mov r9, r1
	mov r8, r7
_08021C5A:
	adds r6, 0xE
	adds r5, 0x1
_08021C5E:
	movs r0, 0x2
	ldr r1, =gStringVar4
	adds r2, r4, 0
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	ldr r3, [sp, 0xC]
	movs r4, 0xDD
	lsls r4, 1
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r2, 24
	lsrs r2, 24
	mov r1, r10
	lsrs r3, r1, 24
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r1, =gStringVar4
	str r1, [sp, 0x8]
	movs r1, 0x2
	bl AddTextPrinterParameterized3
	ldr r3, [sp, 0x18]
	ldr r2, [sp, 0xC]
	ldrb r2, [r2, 0x8]
	cmp r3, r2
	bne _08021CC0
	ldr r0, =gStringVar3
	ldr r1, =gText_1DotBlueF700
	bl StringCopy
	b _08021CC8
	.pool
_08021CC0:
	ldr r0, =gStringVar3
	ldr r1, =gText_1DotF700
	bl StringCopy
_08021CC8:
	ldr r4, =gStringVar3
	mov r3, r9
	strb r3, [r4]
	mov r1, r8
	adds r1, 0x98
	ldr r0, [sp, 0xC]
	adds r1, r0, r1
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, =gStringVar4
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r1, [sp, 0xC]
	movs r2, 0xDD
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	mov r4, r10
	lsrs r3, r4, 24
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r2, =gStringVar4
	str r2, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	lsls r0, r5, 24
	lsrs r5, r0, 24
	ldr r3, [sp, 0xC]
	ldrb r3, [r3, 0x9]
	cmp r5, r3
	bcs _08021D14
	b _08021A98
_08021D14:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8021A28

	thumb_func_start sub_8021D34
sub_8021D34: @ 8021D34
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r8, r0
	movs r0, 0
	mov r10, r0
	movs r6, 0
	movs r1, 0
	str r1, [sp, 0xC]
	mov r2, r8
	adds r2, 0x68
	str r2, [sp, 0x10]
	movs r4, 0xDD
	lsls r4, 1
	add r4, r8
	mov r9, r4
	ldrb r0, [r4]
	movs r1, 0x4
	bl GetWindowAttribute
	lsls r0, 27
	movs r1, 0xD6
	lsls r1, 24
	adds r0, r1
	lsrs r7, r0, 24
	movs r0, 0x9C
	lsls r0, 1
	add r0, r8
	ldr r2, [sp, 0x10]
	ldrh r1, [r2, 0x4]
	bl sub_8021944
	ldrb r0, [r4]
	ldr r4, =gUnknown_082F32D8
	str r4, [sp]
	str r6, [sp, 0x4]
	ldr r1, =gText_TimeColon
	str r1, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r4, =gText_SpaceSec
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r1, 0xB0
	subs r0, r1, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r2, r9
	ldrb r0, [r2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	movs r0, 0x9F
	lsls r0, 1
	add r0, r8
	movs r4, 0
	ldrsh r1, [r0, r4]
	ldr r0, =gStringVar1
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	movs r1, 0xA0
	lsls r1, 1
	add r1, r8
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r5, =gStringVar4
	ldr r1, =gText_XDotY2
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x2
	adds r1, r5, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r4, r9
	ldrb r0, [r4]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r4, =gText_SpaceMin
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, =gUnknown_082F32D8
	str r2, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r0, =gStringVar1
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_StrVar1
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x2
	adds r1, r5, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r4, r9
	ldrb r0, [r4]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	adds r0, r7, 0
	adds r0, 0xE
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r4]
	ldr r4, =gUnknown_082F32D8
	str r4, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r1, =gText_PressingSpeed
	str r1, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r4, =gText_TimesPerSec
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r2, 0xB0
	subs r0, r2, r0
	lsls r0, 24
	str r0, [sp, 0x18]
	lsrs r6, r0, 24
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, =gUnknown_082F32D8
	str r2, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	mov r4, r8
	ldrb r2, [r4, 0x16]
	ldrh r0, [r4, 0x16]
	mov r12, r0
	movs r1, 0x7
	mov r9, r1
	movs r5, 0x1
	ldr r3, =gUnknown_082F334C
_08021EEC:
	mov r4, r9
	mov r0, r10
	subs r1, r4, r0
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _08021F0A
	mov r1, r10
	lsls r0, r1, 2
	adds r0, r3
	ldr r0, [r0]
	ldr r4, [sp, 0xC]
	adds r4, r0
	str r4, [sp, 0xC]
_08021F0A:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0x7
	bls _08021EEC
	ldr r0, =gStringVar1
	mov r2, r12
	lsrs r1, r2, 8
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	ldr r1, =0x000f4240
	ldr r0, [sp, 0xC]
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_XDotY3
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x2
	adds r1, r4, 0
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r0, r8
	adds r0, 0x25
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08021FC4
	movs r0, 0xDD
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	ldr r1, =gUnknown_082F32E7
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	b _08021FDE
	.pool
_08021FC4:
	movs r0, 0xDD
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	str r2, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
_08021FDE:
	adds r0, r7, 0
	adds r0, 0xE
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0xDD
	lsls r4, 1
	add r8, r4
	mov r1, r8
	ldrb r0, [r1]
	ldr r2, =gUnknown_082F32D8
	mov r9, r2
	str r2, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	ldr r1, =gText_Silkiness
	str r1, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r0, =gStringVar1
	ldr r4, [sp, 0x10]
	ldrh r1, [r4, 0x8]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_Var1Percent
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x2
	adds r1, r4, 0
	bl GetStringWidth
	movs r1, 0xB0
	subs r1, r0
	lsls r1, 24
	lsrs r6, r1, 24
	mov r1, r8
	ldrb r0, [r1]
	mov r2, r9
	str r2, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8021D34

	thumb_func_start sub_8022070
sub_8022070: @ 8022070
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r1, 0
	adds r0, r6, 0
	adds r0, 0x80
	ldrb r0, [r0]
	cmp r0, 0x5
	bls _08022084
	b _08022218
_08022084:
	lsls r0, 2
	ldr r1, =_08022094
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08022094:
	.4byte _080220AC
	.4byte _080220F8
	.4byte _0802210C
	.4byte _08022130
	.4byte _080221F8
	.4byte _08022200
_080220AC:
	ldrb r0, [r4, 0x9]
	subs r0, 0x2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0
	bl sub_8022554
	ldrh r0, [r4, 0x12]
	lsls r0, 3
	ldr r2, =gUnknown_082F32CC
	mov r1, sp
	adds r0, r2
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	ldrh r0, [r4, 0x12]
	cmp r0, 0xD
	bne _080220DC
	ldr r0, =gUnknown_082F3344
	adds r0, 0x4
	b _080220DE
	.pool
_080220DC:
	ldr r0, =gUnknown_082F3344
_080220DE:
	adds r0, r5, r0
	ldrb r1, [r0]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r0, sp
	bl AddWindow
	adds r1, r6, 0
	adds r1, 0x82
	strb r0, [r1]
	b _08022218
	.pool
_080220F8:
	adds r4, r6, 0
	adds r4, 0x82
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	b _08022218
_0802210C:
	adds r5, r6, 0
	adds r5, 0x82
	ldrb r0, [r5]
	ldr r4, =0x0000021d
	adds r1, r4, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0xD
	bl DrawStdFrameWithCustomTileAndPalette
	b _08022218
	.pool
_08022130:
	ldrb r0, [r4, 0x9]
	subs r0, 0x2
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4, 0x12]
	cmp r0, 0xC
	beq _08022184
	cmp r0, 0xC
	bgt _08022148
	cmp r0, 0xB
	beq _0802214E
	b _08022218
_08022148:
	cmp r0, 0xD
	beq _080221C8
	b _08022218
_0802214E:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	ldr r3, =gText_PressesRankings
	movs r1, 0x14
	movs r2, 0x3
	bl sub_80219C8
	ldr r0, =gUnknown_082F3344
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, 27
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xA0
	bl sub_8021A28
	adds r1, r6, 0
	adds r1, 0x80
	movs r0, 0x5
	b _08022220
	.pool
_08022184:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	ldr r2, =gUnknown_082F43B4
	adds r1, r4, 0
	adds r1, 0x8F
	ldrb r1, [r1]
	adds r1, 0x3
	lsls r1, 2
	adds r1, r2
	ldr r3, [r1]
	movs r1, 0x14
	movs r2, 0x4
	bl sub_80219C8
	ldr r0, =gUnknown_082F3344
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, 27
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0xA0
	bl sub_8021A28
	adds r1, r6, 0
	adds r1, 0x80
	movs r0, 0x5
	b _08022220
	.pool
_080221C8:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	ldr r3, =gText_CrushingResults
	movs r1, 0x16
	movs r2, 0x3
	bl sub_80219C8
	ldr r0, =gUnknown_082F3344
	adds r0, 0x4
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, 27
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0xB0
	bl sub_8021A28
	b _08022218
	.pool
_080221F8:
	adds r0, r4, 0
	bl sub_8021D34
	b _08022218
_08022200:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	adds r1, r6, 0
	adds r1, 0x80
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _08022224
_08022218:
	adds r1, r6, 0
	adds r1, 0x80
	ldrb r0, [r1]
	adds r0, 0x1
_08022220:
	strb r0, [r1]
	movs r0, 0
_08022224:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8022070

	thumb_func_start sub_802222C
sub_802222C: @ 802222C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xDD
	lsls r0, 1
	adds r5, r4, r0
	ldrb r0, [r5]
	movs r1, 0x1
	bl ClearStdWindowAndFrameToTransparent
	ldrb r0, [r5]
	bl RemoveWindow
	adds r0, r4, 0
	bl sub_8022600
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802222C

	thumb_func_start sub_8022250
sub_8022250: @ 8022250
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0
	str r1, [sp, 0xC]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080222D0
	cmp r0, 0x1
	bgt _08022288
	cmp r0, 0
	beq _08022296
	b _080224BA
	.pool
_08022288:
	cmp r0, 0x2
	bne _0802228E
	b _08022480
_0802228E:
	cmp r0, 0x3
	bne _08022294
	b _08022494
_08022294:
	b _080224BA
_08022296:
	ldr r0, =gUnknown_082F32EC
	bl AddWindow
	strh r0, [r6, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r6, 0x2]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r6, 0x2]
	ldr r4, =0x0000021d
	adds r1, r4, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r6, 0x2]
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0xD
	bl DrawStdFrameWithCustomTileAndPalette
	b _080224BA
	.pool
_080222D0:
	ldr r0, =gText_BerryCrush2
	mov r10, r0
	movs r1, 0x1
	negs r1, r1
	mov r8, r1
	movs r0, 0x1
	mov r1, r10
	mov r2, r8
	bl GetStringWidth
	lsrs r0, 1
	movs r4, 0x60
	subs r0, r4, r0
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x2]
	ldr r5, =gUnknown_082F32E1
	str r5, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldr r0, =gText_PressingSpeedRankings
	mov r10, r0
	movs r0, 0x1
	mov r1, r10
	mov r2, r8
	bl GetStringWidth
	lsrs r0, 1
	subs r4, r0
	lsls r4, 24
	lsrs r7, r4, 24
	ldrb r0, [r6, 0x2]
	str r5, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0x11
	bl AddTextPrinterParameterized3
	movs r0, 0x29
	mov r10, r0
_08022336:
	mov r1, r9
	adds r1, 0x2
	ldr r0, =gStringVar1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar4
	ldr r1, =gText_Var1Players
	bl StringExpandPlaceholders
	ldrb r0, [r6, 0x2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gStringVar4
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	mov r3, r10
	bl AddTextPrinterParameterized3
	movs r0, 0x1
	ldr r1, =gText_TimesPerSec
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r1, 0xC0
	subs r1, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldrb r0, [r6, 0x2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gText_TimesPerSec
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	mov r3, r10
	bl AddTextPrinterParameterized3
	movs r2, 0
	mov r0, r9
	lsls r4, r0, 1
	mov r1, r10
	adds r1, 0x10
	str r1, [sp, 0x10]
	movs r0, 0x1
	add r9, r0
	adds r0, r4, r6
	ldrb r3, [r0, 0x4]
	movs r1, 0x7
	mov r12, r1
	movs r0, 0x1
	mov r8, r0
	ldr r5, =gUnknown_082F334C
_080223AE:
	mov r0, r12
	subs r1, r0, r2
	adds r0, r3, 0
	asrs r0, r1
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _080223CA
	lsls r0, r2, 2
	adds r0, r5
	ldr r0, [r0]
	ldr r1, [sp, 0xC]
	adds r1, r0
	str r1, [sp, 0xC]
_080223CA:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _080223AE
	adds r0, r4, r6
	ldrh r1, [r0, 0x4]
	lsrs r1, 8
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, [sp, 0xC]
	ldr r1, =0x000f4240
	bl __udivsi3
	adds r1, r0, 0
	ldr r0, =gStringVar2
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar4
	ldr r1, =gText_XDotY3
	bl StringExpandPlaceholders
	movs r0, 0x1
	ldr r1, =gStringVar4
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r7, r0
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gStringVar4
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	mov r3, r10
	bl AddTextPrinterParameterized3
	ldr r1, [sp, 0x10]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r10, r0
	movs r0, 0
	str r0, [sp, 0xC]
	mov r1, r9
	lsls r0, r1, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0x3
	bhi _08022444
	b _08022336
_08022444:
	ldrb r0, [r6, 0x2]
	movs r1, 0x3
	bl CopyWindowToVram
	b _080224BA
	.pool
_08022480:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080224BA
	b _080224C0
	.pool
_08022494:
	ldrb r0, [r6, 0x2]
	movs r1, 0x1
	bl ClearStdWindowAndFrameToTransparent
	ldrb r0, [r6, 0x2]
	bl ClearWindowTilemap
	ldrb r0, [r6, 0x2]
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	bl ScriptContext2_Disable
	mov r0, r9
	b _080224BE
_080224BA:
	ldrh r0, [r6]
	adds r0, 0x1
_080224BE:
	strh r0, [r6]
_080224C0:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022250

	thumb_func_start ShowBerryCrushRankings
ShowBerryCrushRankings: @ 80224D0
	push {lr}
	bl ScriptContext2_Enable
	ldr r0, =sub_8022250
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	movs r3, 0xF6
	lsls r3, 1
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0xC]
	adds r3, 0x2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	adds r3, 0x2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0x10]
	adds r3, 0x2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0x12]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowBerryCrushRankings

	thumb_func_start sub_8022524
sub_8022524: @ 8022524
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	bl sub_8021944
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl sub_8035044
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	bl sub_8035044
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	movs r0, 0x2
	bl sub_8035044
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022524

	thumb_func_start sub_8022554
sub_8022554: @ 8022554
	push {lr}
	ldr r2, [r0, 0x78]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r2]
	ldr r1, [r0, 0x7C]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x1
	bl sub_803547C
	movs r0, 0x1
	movs r1, 0x1
	bl sub_803547C
	movs r0, 0
	movs r1, 0x1
	bl sub_803547C
	pop {r0}
	bx r0
	thumb_func_end sub_8022554

	thumb_func_start sub_8022588
sub_8022588: @ 8022588
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r6, 0
	ldrb r0, [r5, 0x9]
	cmp r6, r0
	bcs _080225E8
	ldr r7, =gUnknown_082F417C
_08022596:
	lsls r0, r6, 2
	movs r1, 0xA2
	lsls r1, 1
	adds r2, r5, r1
	adds r2, r0
	ldrb r1, [r5, 0x9]
	subs r1, 0x2
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r6, r0
	adds r0, r7
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_082F4190
	adds r0, r1
	str r0, [r2]
	ldrb r0, [r0]
	lsls r0, 3
	ldr r1, =gUnknown_082F32F4
	adds r0, r1
	bl AddWindow
	ldr r1, =0x000001bb
	adds r4, r5, r1
	adds r4, r6
	strb r0, [r4]
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r6, r0
	bcc _08022596
_080225E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022588

	thumb_func_start sub_8022600
sub_8022600: @ 8022600
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	movs r7, 0
	ldrb r0, [r6, 0x9]
	cmp r7, r0
	bcs _080226B6
	movs r1, 0
	mov r8, r1
_08022616:
	ldr r1, =0x000001bb
	adds r0, r6, r1
	adds r5, r0, r7
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r6, 0x8]
	cmp r7, r0
	bne _08022668
	lsls r4, r7, 5
	adds r4, 0x98
	adds r4, r6, r4
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	lsrs r0, 1
	movs r2, 0x24
	subs r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r5]
	mov r1, r8
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_082F32DB
	str r1, [sp, 0x8]
	mov r1, r8
	str r1, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	b _0802269C
	.pool
_08022668:
	lsls r4, r7, 5
	adds r4, 0x98
	adds r4, r6, r4
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	lsrs r0, 1
	movs r2, 0x24
	subs r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r5]
	mov r1, r8
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_082F32DE
	str r1, [sp, 0x8]
	mov r1, r8
	str r1, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized4
_0802269C:
	ldr r1, =0x000001bb
	adds r0, r6, r1
	adds r0, r7
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x9]
	cmp r7, r0
	bcc _08022616
_080226B6:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022600

	thumb_func_start sub_80226D0
sub_80226D0: @ 80226D0
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r5, 0
	ldr r0, =gUnknown_08DE3FD4
	ldr r4, =gDecompressionBuffer
	adds r1, r4, 0
	bl LZ77UnCompWram
	b _0802271A
	.pool
_080226EC:
	lsls r1, r5, 2
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	adds r0, r1
	ldr r3, [r0]
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4, r1
	ldrb r2, [r3, 0x1]
	ldrb r3, [r3, 0x2]
	movs r0, 0xA
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x3
	bl CopyToBgTilemapBufferRect
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0802271A:
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcc _080226EC
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80226D0

	thumb_func_start sub_8022730
sub_8022730: @ 8022730
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r0, =0x0000ff98
	strh r0, [r6, 0x2A]
	strh r5, [r6, 0x2C]
	ldr r1, =gSpriteCoordOffsetX
	strh r5, [r1]
	ldr r1, =gSpriteCoordOffsetY
	strh r0, [r1]
	ldr r4, =gUnknown_082F41F4
_08022746:
	lsls r0, r5, 3
	adds r0, r4
	bl LoadCompressedSpriteSheet
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08022746
	ldr r0, =gUnknown_082F421C
	bl LoadSpritePalettes
	ldr r0, =gUnknown_082F430C
	movs r1, 0x78
	movs r2, 0x58
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xAC
	lsls r0, 1
	adds r3, r6, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, 0x2C
	ldrb r0, [r1]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1]
	movs r5, 0
	ldrb r1, [r6, 0x9]
	cmp r5, r1
	bcs _08022822
	movs r7, 0x4
_080227AA:
	lsls r4, r5, 2
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r6, r3
	adds r0, r4
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	adds r1, 0x78
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r0, 0x6]
	adds r2, 0x20
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_082F4324
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xAE
	lsls r0, 1
	adds r3, r6, r0
	adds r3, r4
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r3]
	ldrb r0, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r0, r2
	orrs r0, r7
	strb r0, [r1, 0x5]
	ldr r1, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcc _080227AA
_08022822:
	movs r5, 0
	ldr r4, =gUnknown_082F41CC+6
	adds r7, r4, 0x1
_08022828:
	lsls r2, r5, 1
	adds r0, r2, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r1, 0x78
	adds r2, r7
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	adds r2, 0x88
	ldr r0, =gUnknown_082F433C
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r5, 2
	movs r1, 0xC2
	lsls r1, 1
	adds r3, r6, r1
	adds r3, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	strh r5, [r0, 0x2E]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08022828
	movs r5, 0
_0802288E:
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 19
	movs r3, 0xB0
	lsls r3, 16
	adds r1, r3
	asrs r1, 16
	ldr r0, =gUnknown_082F4354
	movs r2, 0x8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r5, 2
	movs r4, 0xD8
	lsls r4, 1
	adds r3, r6, r4
	adds r3, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r1, [r0, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r1, r2
	strb r1, [r0, 0x5]
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	adds r4, 0x8
	adds r1, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r3, 0x41
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _0802288E
	ldr r4, =gUnknown_082F4384
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_8034D14
	adds r2, r4, 0
	adds r2, 0x10
	movs r0, 0x1
	movs r1, 0
	bl sub_8034D14
	adds r4, 0x20
	movs r0, 0x2
	movs r1, 0
	adds r2, r4, 0
	bl sub_8034D14
	ldrh r0, [r6, 0x12]
	cmp r0, 0x1
	bne _08022928
	movs r4, 0x9C
	lsls r4, 1
	adds r0, r6, r4
	bl sub_8022554
_08022928:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022730

	thumb_func_start sub_8022960
sub_8022960: @ 8022960
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	movs r0, 0x4
	bl FreeSpriteTilesByTag
	movs r0, 0x3
	bl FreeSpriteTilesByTag
	movs r0, 0x2
	bl FreeSpriteTilesByTag
	movs r0, 0x1
	bl FreeSpriteTilesByTag
	movs r0, 0x4
	bl FreeSpritePaletteByTag
	movs r0, 0x2
	bl FreeSpritePaletteByTag
	movs r0, 0x1
	bl FreeSpritePaletteByTag
	movs r0, 0xD8
	lsls r0, 1
	adds r6, r5, r0
_08022996:
	lsls r0, r4, 2
	adds r0, r6, r0
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _08022996
	movs r0, 0x2
	bl sub_80353DC
	movs r0, 0x1
	bl sub_80353DC
	movs r0, 0
	bl sub_80353DC
	movs r4, 0
	movs r1, 0xC2
	lsls r1, 1
	adds r6, r5, r1
_080229C4:
	lsls r0, r4, 2
	adds r0, r6, r0
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xA
	bls _080229C4
	movs r4, 0
	ldrb r2, [r5, 0x9]
	cmp r4, r2
	bcs _080229FC
_080229E0:
	lsls r1, r4, 2
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r5, r2
	adds r0, r1
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r4, r0
	bcc _080229E0
_080229FC:
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08022A18
	adds r0, r2, 0
	bl DestroySprite
_08022A18:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8022960

	thumb_func_start sub_8022A20
sub_8022A20: @ 8022A20
	push {lr}
	adds r3, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08022A46
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
_08022A46:
	pop {r0}
	bx r0
	thumb_func_end sub_8022A20

	thumb_func_start sub_8022A4C
sub_8022A4C: @ 8022A4C
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r1, 0
	ldr r5, =SpriteCallbackDummy
	adds r2, r3, 0
	adds r2, 0x2E
	movs r4, 0
_08022A5A:
	lsls r0, r1, 1
	adds r0, r2, r0
	strh r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x7
	bls _08022A5A
	movs r0, 0
	strh r0, [r3, 0x24]
	strh r0, [r3, 0x26]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	str r5, [r3, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022A4C

	thumb_func_start sub_8022A94
sub_8022A94: @ 8022A94
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	ldrh r0, [r4, 0x4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r5, 0x26]
	adds r0, r2
	strh r0, [r5, 0x26]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r6, 0x80
	lsls r6, 8
	ands r0, r6
	cmp r0, 0
	beq _08022AFA
	ldrh r0, [r4, 0x6]
	ldrh r2, [r5, 0x2E]
	adds r0, r2
	strh r0, [r5, 0x2E]
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 23
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r5, 0x24]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	ands r0, r6
	cmp r0, 0
	beq _08022AFA
	ldrh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 23
	cmp r0, 0x7E
	ble _08022AFA
	movs r0, 0
	strh r0, [r5, 0x24]
	ldrh r1, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xE]
_08022AFA:
	ldrh r0, [r4]
	lsls r0, 16
	asrs r0, 23
	strh r0, [r5, 0x20]
	movs r2, 0x22
	ldrsh r1, [r5, r2]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	ldrh r2, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r2
	cmp r1, r0
	ble _08022B1A
	ldr r0, =sub_8022A4C
	str r0, [r5, 0x1C]
_08022B1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022A94

	thumb_func_start sub_8022B28
sub_8022B28: @ 8022B28
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r6, 0
	adds r7, 0x2E
	movs r0, 0
	mov r8, r0
	movs r2, 0xA0
	lsls r2, 2
	strh r2, [r7, 0x2]
	movs r0, 0x20
	strh r0, [r7, 0x4]
	movs r1, 0xA8
	strh r1, [r7, 0xE]
	movs r0, 0x24
	ldrsh r4, [r6, r0]
	lsls r4, 23
	lsrs r4, 16
	ldrh r0, [r6, 0x22]
	subs r1, r0
	lsls r1, 23
	asrs r1, 16
	adds r2, 0x20
	asrs r2, 1
	movs r0, 0x7
	bl sub_81515D4
	adds r5, r0, 0
	ldrh r0, [r6, 0x20]
	lsls r0, 7
	strh r0, [r6, 0x2E]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	movs r0, 0x7
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81515D4
	strh r0, [r7, 0x6]
	movs r0, 0x7
	adds r1, r5, 0
	movs r2, 0x55
	bl sub_8151550
	adds r2, r0, 0
	mov r1, r8
	strh r1, [r7, 0x8]
	movs r1, 0xFE
	lsls r1, 6
	lsls r2, 16
	asrs r2, 16
	movs r0, 0x7
	bl sub_81515D4
	strh r0, [r7, 0xA]
	movs r2, 0x24
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bge _08022BA6
	adds r0, 0x3
_08022BA6:
	asrs r0, 2
	strh r0, [r7, 0xC]
	ldrh r0, [r7, 0xE]
	ldr r2, =0xffff8000
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r7, 0xE]
	mov r0, r8
	strh r0, [r6, 0x26]
	strh r0, [r6, 0x24]
	ldr r0, =sub_8022A94
	str r0, [r6, 0x1C]
	adds r2, r6, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r2, 0x12
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022B28

	thumb_func_start sub_8022BEC
sub_8022BEC: @ 8022BEC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r2, 0
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	mov r8, r4
	bl sub_8020C00
	adds r6, r0, 0
	cmp r5, 0x19
	bls _08022C0A
	movs r5, 0
_08022C0A:
	cmp r4, 0
	beq _08022C14
	cmp r4, 0x1
	beq _08022C40
	b _08022C4A
_08022C14:
	cmp r5, 0
	beq _08022C28
	ldr r0, =gUnknown_082F43CC
	lsls r1, r5, 2
	adds r1, r0
	ldr r2, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl _call_via_r2
_08022C28:
	ldrb r0, [r6, 0xE]
	cmp r0, 0x19
	bls _08022C32
	mov r0, r8
	strb r0, [r6, 0xE]
_08022C32:
	ldr r0, =gUnknown_082F43CC
	ldrb r1, [r6, 0xE]
	lsls r1, 2
	b _08022C44
	.pool
_08022C40:
	ldr r0, =gUnknown_082F43CC
	lsls r1, r5, 2
_08022C44:
	adds r1, r0
	ldr r0, [r1]
	str r0, [r6, 0x4]
_08022C4A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022BEC

	thumb_func_start sub_8022C58
sub_8022C58: @ 8022C58
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r2, [r1]
	ldrb r3, [r1, 0x1]
	lsls r3, 8
	orrs r2, r3
	ldrb r3, [r1, 0x2]
	lsls r3, 16
	orrs r2, r3
	ldrb r3, [r1, 0x3]
	lsls r3, 24
	adds r0, r2, 0
	orrs r0, r3
	ldrb r2, [r1, 0x9]
	strb r2, [r1]
	ldrb r4, [r1, 0x8]
	lsls r4, 8
	ldrb r2, [r1, 0x7]
	orrs r4, r2
	ldr r5, =gPaletteFade
	ldrb r3, [r5, 0x8]
	movs r2, 0x7F
	ands r2, r3
	strb r2, [r5, 0x8]
	movs r5, 0x4
	ldrsb r5, [r1, r5]
	ldrb r2, [r1, 0x5]
	ldrb r3, [r1, 0x6]
	str r4, [sp]
	adds r1, r5, 0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	movs r0, 0x2
	strb r0, [r6, 0xE]
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8022C58

	thumb_func_start sub_8022CB0
sub_8022CB0: @ 8022CB0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08022CE4
	cmp r0, 0x1
	bgt _08022CC6
	cmp r0, 0
	beq _08022CD0
	b _08022D06
_08022CC6:
	cmp r0, 0x2
	beq _08022CEA
	cmp r0, 0x3
	beq _08022CF6
	b _08022D06
_08022CD0:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08022D0C
	ldrb r0, [r5]
	cmp r0, 0
	bne _08022D06
	movs r0, 0x3
	b _08022D0A
_08022CE4:
	bl sub_8010434
	b _08022D06
_08022CEA:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	bne _08022D06
	b _08022D0C
_08022CF6:
	ldrb r0, [r4, 0xF]
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strb r0, [r4, 0xC]
	b _08022D0E
_08022D06:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
_08022D0A:
	strb r0, [r4, 0xC]
_08022D0C:
	movs r0, 0
_08022D0E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8022CB0

	thumb_func_start sub_8022D14
sub_8022D14: @ 8022D14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r7, r0, 0
	adds r5, r1, 0
	ldrb r4, [r5, 0x3]
	lsls r4, 8
	ldrb r0, [r5, 0x2]
	orrs r4, r0
	ldrb r6, [r7, 0xC]
	cmp r6, 0x1
	beq _08022DC0
	cmp r6, 0x1
	bgt _08022D38
	cmp r6, 0
	beq _08022D42
	b _08022E08
_08022D38:
	cmp r6, 0x2
	beq _08022DD8
	cmp r6, 0x3
	beq _08022DE8
	b _08022E08
_08022D42:
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldrb r1, [r5, 0x1]
	movs r0, 0x2
	mov r8, r0
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08022D90
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_082F32A4
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldrb r3, [r7, 0xB]
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized2
	b _08022DB2
	.pool
_08022D90:
	ldr r1, =gUnknown_082F32A4
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldrb r3, [r7, 0xB]
	str r4, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
_08022DB2:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _08022E08
	.pool
_08022DC0:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _08022E0E
	cmp r4, 0
	bne _08022E08
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
	strb r0, [r7, 0xC]
	b _08022E08
_08022DD8:
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	ands r4, r0
	cmp r4, 0
	bne _08022E08
	b _08022E0E
	.pool
_08022DE8:
	ldrb r1, [r5, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08022DFA
	movs r0, 0
	movs r1, 0x1
	bl ClearDialogWindowAndFrame
_08022DFA:
	ldrb r0, [r7, 0xE]
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	ldrb r0, [r5, 0x4]
	b _08022E0C
_08022E08:
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
_08022E0C:
	strb r0, [r7, 0xC]
_08022E0E:
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8022D14

	thumb_func_start sub_8022E1C
sub_8022E1C: @ 8022E1C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_802104C
	cmp r0, 0
	beq _08022E34
	ldrb r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x36
	movs r1, 0
	bl sub_8022BEC
_08022E34:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8022E1C

	thumb_func_start sub_8022E3C
sub_8022E3C: @ 8022E3C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_802130C
	cmp r0, 0
	beq _08022E54
	ldrb r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x36
	movs r1, 0
	bl sub_8022BEC
_08022E54:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8022E3C

	thumb_func_start sub_8022E5C
sub_8022E5C: @ 8022E5C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	beq _08022E6C
	cmp r0, 0x1
	beq _08022E72
	b _08022E9C
_08022E6C:
	bl sub_8010434
	b _08022E9C
_08022E72:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08022EA2
	ldr r0, =0x000001e5
	bl PlayNewMapMusic
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x3
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _08022EA2
	.pool
_08022E9C:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_08022EA2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8022E5C

	thumb_func_start sub_8022EAC
sub_8022EAC: @ 8022EAC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	beq _08022EC2
	cmp r0, 0x1
	beq _08022EE8
	adds r0, 0x1
	b _08022EF8
_08022EC2:
	adds r0, r4, 0
	bl sub_8024578
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8024644
	movs r0, 0x7
	strb r0, [r4, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08022EFA
_08022EE8:
	movs r0, 0x8
	strb r0, [r4, 0xE]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0x2
_08022EF8:
	strb r0, [r4, 0xC]
_08022EFA:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8022EAC

	thumb_func_start sub_8022F04
sub_8022F04: @ 8022F04
	push {lr}
	movs r1, 0
	str r1, [r0, 0x4]
	ldr r0, =sub_8020E1C
	bl SetMainCallback2
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8022F04

	thumb_func_start sub_8022F1C
sub_8022F1C: @ 8022F1C
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r2, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x5
	bls _08022F2C
	b _08023060
_08022F2C:
	lsls r0, 2
	ldr r1, =_08022F3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08022F3C:
	.4byte _08022F54
	.4byte _08022F74
	.4byte _08022F7A
	.4byte _08022FAA
	.4byte _08022FBA
	.4byte _08023044
_08022F54:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r2, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x9
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08023066
_08022F74:
	bl sub_8010434
	b _08023060
_08022F7A:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023066
	adds r4, r5, 0
	adds r4, 0x42
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xC
	bl memset
	ldrb r0, [r5, 0x8]
	lsls r0, 5
	adds r0, r5, r0
	adds r0, 0xA4
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl SendBlock
	b _08023060
_08022FAA:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023066
	movs r0, 0
	strh r0, [r5, 0x10]
	b _08023060
_08022FBA:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r4, [r5, 0x9]
	subs r1, r4, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _08023066
	movs r3, 0
	cmp r3, r4
	bcs _0802301E
	ldr r7, =gBlockRecvBuffer
	movs r6, 0
	ldr r4, =gUnknown_0858AB24
_08022FDC:
	lsls r0, r3, 5
	adds r0, r5, r0
	lsls r1, r3, 8
	adds r1, r7
	ldrh r1, [r1]
	adds r2, r0, 0
	adds r2, 0xA4
	strh r1, [r2]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xB0
	bls _08022FF6
	strh r6, [r2]
_08022FF6:
	ldrh r1, [r2]
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x18]
	ldrb r1, [r1]
	adds r0, r1
	strh r0, [r5, 0x18]
	ldrh r0, [r2]
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x2]
	ldr r0, [r5, 0x1C]
	adds r0, r1
	str r0, [r5, 0x1C]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r3, r0
	bcc _08022FDC
_0802301E:
	movs r0, 0
	strh r0, [r5, 0x10]
	bl ResetBlockReceivedFlags
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	lsls r0, 8
	movs r1, 0x80
	lsls r1, 6
	bl sub_81515FC
	str r0, [r5, 0x20]
	b _08023060
	.pool
_08023044:
	movs r0, 0
	movs r1, 0x1
	bl ClearDialogWindowAndFrame
	movs r0, 0xA
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x4
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _08023066
_08023060:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_08023066:
	movs r0, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8022F1C

	thumb_func_start sub_8023070
sub_8023070: @ 8023070
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x6
	bls _0802307C
	b _080231A8
_0802307C:
	lsls r0, 2
	ldr r1, =_0802308C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802308C:
	.4byte _080230A8
	.4byte _080230BA
	.4byte _080230E8
	.4byte _08023120
	.4byte _08023150
	.4byte _08023172
	.4byte _08023184
_080230A8:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	adds r0, r4, 0
	bl sub_80214A8
	bl sub_8010434
	b _080231A8
_080230BA:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080231AE
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	ldr r3, =0x00000139
	adds r1, r4, r3
	strb r0, [r1]
	adds r2, 0x2
	adds r1, r4, r2
	strb r0, [r1]
	adds r3, 0x2
	adds r1, r4, r3
	strb r0, [r1]
	b _080231A8
	.pool
_080230E8:
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	ldrb r0, [r3]
	lsls r0, 2
	movs r2, 0xB8
	lsls r2, 1
	adds r1, r4, r2
	adds r0, r1, r0
	ldr r2, [r0]
	ldr r0, =sub_8021608
	str r0, [r2, 0x1C]
	ldrb r0, [r3]
	lsls r0, 2
	adds r1, r0
	ldr r1, [r1]
	adds r1, 0x2C
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	movs r0, 0x3D
	bl PlaySE
	b _080231A8
	.pool
_08023120:
	movs r3, 0x9C
	lsls r3, 1
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r0, 2
	adds r3, 0x38
	adds r1, r4, r3
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r1, [r0, 0x1C]
	ldr r0, =sub_8021608
	cmp r1, r0
	beq _080231AE
	movs r0, 0
	str r0, [r3]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	bl sub_8010434
	b _080231A8
	.pool
_08023150:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080231AE
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	ldrb r0, [r1]
	ldrb r2, [r4, 0x9]
	cmp r0, r2
	bcs _0802316C
	movs r0, 0x2
	b _080231AC
_0802316C:
	movs r0, 0
	strb r0, [r1]
	b _080231A8
_08023172:
	movs r3, 0x9C
	lsls r3, 1
	adds r1, r4, r3
	adds r0, r4, 0
	bl sub_80216A8
	bl sub_8010434
	b _080231A8
_08023184:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080231AE
	movs r0, 0x2B
	bl PlaySE
	movs r0, 0xB
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x5
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _080231AE
_080231A8:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
_080231AC:
	strb r0, [r4, 0xC]
_080231AE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023070

	thumb_func_start sub_80231B8
sub_80231B8: @ 80231B8
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0xC]
	cmp r1, 0x1
	beq _0802321C
	cmp r1, 0x1
	bgt _080231CC
	cmp r1, 0
	beq _080231D6
	b _080232DC
_080231CC:
	cmp r1, 0x2
	beq _0802329C
	cmp r1, 0x3
	beq _080232BE
	b _080232DC
_080231D6:
	ldrh r0, [r4, 0x2A]
	adds r0, 0x4
	strh r0, [r4, 0x2A]
	lsls r0, 16
	cmp r0, 0
	bge _080231E4
	b _080232E2
_080231E4:
	strh r1, [r4, 0x2A]
	ldr r0, =0x00000139
	adds r3, r4, r0
	movs r0, 0x4
	strb r0, [r3]
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	ldr r2, =gUnknown_082F326C
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r2
	ldrb r0, [r0]
	movs r2, 0x9D
	lsls r2, 1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, 0xD6
	bl PlaySE
	b _080232DC
	.pool
_0802321C:
	ldr r7, =gUnknown_082F326C
	movs r0, 0x9C
	lsls r0, 1
	adds r6, r4, r0
	ldr r1, =0x00000139
	adds r5, r4, r1
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	ldrb r2, [r6]
	adds r0, r2
	adds r0, r7
	movs r1, 0
	ldrsb r1, [r0, r1]
	strh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	movs r1, 0x9D
	lsls r1, 1
	adds r2, r4, r1
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2]
	cmp r0, r1
	bcc _080232E2
	ldrb r0, [r5]
	cmp r0, 0
	beq _080232DC
	subs r0, 0x1
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0
	strb r0, [r6]
	b _080232E2
	.pool
_0802329C:
	movs r0, 0
	strh r0, [r4, 0x2C]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	bl sub_8010434
	b _080232DC
_080232BE:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080232E2
	movs r0, 0xC
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x6
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _080232E2
_080232DC:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_080232E2:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80231B8

	thumb_func_start sub_80232EC
sub_80232EC: @ 80232EC
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _0802330C
	cmp r0, 0x1
	bgt _08023302
	cmp r0, 0
	beq _08023332
	b _0802338C
_08023302:
	cmp r0, 0x2
	beq _0802332A
	cmp r0, 0x3
	beq _08023338
	b _0802338C
_0802330C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023392
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x78
	movs r3, 0x50
	bl sub_802EB24
	b _0802338C
_0802332A:
	bl sub_802EB84
	cmp r0, 0
	bne _08023392
_08023332:
	bl sub_8010434
	b _0802338C
_08023338:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023392
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	ldr r2, =0x00000139
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, 0x1
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, 0x1
	adds r1, r4, r2
	strb r0, [r1]
	strh r0, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _08023378
	movs r0, 0xD
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08023382
	.pool
_08023378:
	movs r0, 0xE
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_08023382:
	movs r1, 0
	movs r0, 0x7
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _08023392
_0802338C:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_08023392:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80232EC

	thumb_func_start sub_802339C
sub_802339C: @ 802339C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	movs r0, 0
	mov r8, r0
	movs r2, 0
	adds r7, r2, 0
	ldrb r1, [r4, 0x9]
	cmp r7, r1
	bcs _080234AA
	movs r2, 0x5E
	adds r2, r4
	mov r9, r2
	ldr r3, =gUnknown_082F325C
	mov r10, r3
_080233C0:
	lsls r0, r7, 4
	ldr r1, =gRecvCmds
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r3, 0xBC
	lsls r3, 6
	cmp r0, r3
	bne _0802349E
	ldrh r0, [r2, 0x2]
	cmp r0, 0x2
	bne _0802349E
	ldrb r1, [r2, 0x4]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08023496
	mov r0, r9
	ldrb r2, [r0]
	lsrs r1, r2, 3
	mov r3, r10
	adds r0, r7, r3
	ldrb r0, [r0]
	orrs r1, r0
	lsls r1, 3
	movs r0, 0x7
	ands r0, r2
	orrs r0, r1
	mov r1, r9
	strb r0, [r1]
	lsls r2, r7, 5
	adds r3, r4, r2
	mov r12, r3
	mov r1, r12
	adds r1, 0xB5
	movs r0, 0x1
	strb r0, [r1]
	subs r1, 0x7
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	subs r1, 0x8
	ldrh r0, [r4, 0x28]
	ldrh r1, [r1]
	subs r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	mov r5, r12
	adds r5, 0xAA
	ldrh r1, [r5]
	subs r0, r1, 0x1
	adds r6, r2, 0
	cmp r3, r0
	blt _08023468
	adds r0, r1, 0x1
	cmp r3, r0
	bgt _08023468
	mov r1, r12
	adds r1, 0xA8
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	strh r3, [r5]
	mov r0, r12
	adds r0, 0xAC
	ldrh r1, [r1]
	ldrh r2, [r0]
	cmp r1, r2
	bls _08023476
	strh r1, [r0]
	b _08023476
	.pool
_08023468:
	adds r0, r4, r6
	adds r2, r0, 0
	adds r2, 0xA8
	movs r1, 0
	strh r1, [r2]
	adds r0, 0xAA
	strh r3, [r0]
_08023476:
	adds r1, r4, r6
	ldrh r0, [r4, 0x28]
	adds r3, r1, 0
	adds r3, 0xA6
	movs r2, 0
	strh r0, [r3]
	adds r1, 0xB4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _0802349E
	strb r2, [r1]
	b _0802349E
_08023496:
	lsls r0, r7, 5
	adds r0, r4, r0
	adds r0, 0xB5
	strb r1, [r0]
_0802349E:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r3, [r4, 0x9]
	cmp r7, r3
	bcc _080233C0
_080234AA:
	mov r0, r8
	cmp r0, 0x1
	bls _080234E0
	movs r7, 0
	ldrb r1, [r4, 0x9]
	cmp r7, r1
	bcs _080234E0
	movs r3, 0x2
_080234BA:
	lsls r0, r7, 5
	adds r1, r4, r0
	adds r2, r1, 0
	adds r2, 0xB5
	ldrb r0, [r2]
	cmp r0, 0
	beq _080234D4
	orrs r0, r3
	strb r0, [r2]
	adds r1, 0xB0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080234D4:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r2, [r4, 0x9]
	cmp r7, r2
	bcc _080234BA
_080234E0:
	mov r3, r8
	cmp r3, 0
	beq _08023548
	ldrh r0, [r4, 0x2E]
	add r0, r8
	strh r0, [r4, 0x2E]
	ldr r1, =gUnknown_082F3264
	mov r0, r8
	subs r0, 0x1
	adds r0, r1
	ldrb r0, [r0]
	add r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r0, [r4, 0x34]
	add r0, r8
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x1A]
	add r0, r8
	strh r0, [r4, 0x1A]
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	movs r3, 0x1A
	ldrsh r2, [r4, r3]
	subs r0, r2
	cmp r0, 0
	ble _08023534
	lsls r2, 8
	ldr r1, [r4, 0x20]
	adds r0, r2, 0
	bl sub_81515FC
	adds r2, r0, 0
	asrs r2, 8
	adds r0, r4, 0
	adds r0, 0x24
	strb r2, [r0]
	b _08023548
	.pool
_08023534:
	adds r1, r4, 0
	adds r1, 0x24
	movs r0, 0x20
	strb r0, [r1]
	adds r2, r4, 0
	adds r2, 0x5E
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_08023548:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802339C

	thumb_func_start sub_8023558
sub_8023558: @ 8023558
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r6, 0
	movs r1, 0
	adds r4, r1, 0
	ldrb r0, [r3, 0x9]
	cmp r4, r0
	bcs _080235B0
	adds r5, r3, 0
	adds r5, 0x64
_0802356C:
	lsls r0, r4, 5
	adds r1, r3, r0
	adds r0, r1, 0
	adds r0, 0xB5
	ldrb r2, [r0]
	cmp r2, 0
	beq _080235A4
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r1, 0
	adds r0, 0xB4
	ldrb r0, [r0]
	adds r1, r0, 0x1
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _08023594
	movs r0, 0x4
	orrs r1, r0
_08023594:
	lsls r0, r4, 1
	adds r0, r4
	lsls r1, r0
	lsls r0, r1, 16
	lsrs r1, r0, 16
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
_080235A4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r1, [r3, 0x9]
	cmp r4, r1
	bcc _0802356C
_080235B0:
	adds r0, r3, 0
	adds r0, 0x24
	ldrb r1, [r0]
	adds r0, 0x3C
	strh r1, [r0]
	cmp r6, 0
	bne _080235D4
	ldr r2, =0x0000013b
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080236A0
	movs r4, 0x9C
	lsls r4, 1
	adds r1, r3, r4
	b _08023612
	.pool
_080235D4:
	ldr r5, =0x0000013b
	adds r2, r3, r5
	ldrb r0, [r2]
	cmp r0, 0
	beq _0802361A
	ldr r0, =0x00000139
	adds r1, r3, r0
	ldrb r2, [r1]
	cmp r6, r2
	beq _0802360C
	subs r0, r6, 0x1
	strb r0, [r1]
	ldr r1, =gUnknown_082F3290
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x9D
	lsls r4, 1
	adds r1, r3, r4
	strb r0, [r1]
	b _08023640
	.pool
_0802360C:
	movs r5, 0x9C
	lsls r5, 1
	adds r1, r3, r5
_08023612:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08023640
_0802361A:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0
	strb r0, [r1]
	subs r0, r6, 0x1
	ldr r4, =0x00000139
	adds r1, r3, r4
	strb r0, [r1]
	ldr r1, =gUnknown_082F3290
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r5, 0x9D
	lsls r5, 1
	adds r1, r3, r5
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r2]
_08023640:
	ldr r0, =0x0000013b
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, 0
	beq _080236A0
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r3, r2
	movs r5, 0x9D
	lsls r5, 1
	adds r2, r3, r5
	ldrb r0, [r1]
	ldrb r5, [r2]
	cmp r0, r5
	bcc _0802367C
	movs r0, 0
	strb r0, [r1]
	ldr r5, =0x00000139
	adds r1, r3, r5
	strb r0, [r1]
	strb r0, [r2]
	strb r0, [r4]
	movs r1, 0
	b _08023690
	.pool
_0802367C:
	ldr r2, =gUnknown_082F3290
	ldrb r1, [r1]
	ldr r4, =0x00000139
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, 0x1
	adds r1, r0
	adds r1, r2
	ldrb r1, [r1]
_08023690:
	adds r0, r3, 0
	adds r0, 0x5F
	strb r1, [r0]
	b _080236A8
	.pool
_080236A0:
	adds r1, r3, 0
	adds r1, 0x5F
	movs r0, 0
	strb r0, [r1]
_080236A8:
	ldrh r1, [r3, 0x26]
	adds r0, r3, 0
	adds r0, 0x62
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8023558

	thumb_func_start sub_80236B8
sub_80236B8: @ 80236B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	ldr r3, =gMain
	ldrh r1, [r3, 0x2E]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080236DA
	adds r2, r5, 0
	adds r2, 0x5E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080236DA:
	ldrh r1, [r3, 0x2C]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080236FA
	ldrb r0, [r5, 0x8]
	lsls r0, 5
	adds r0, r5, r0
	adds r1, r0, 0
	adds r1, 0xB2
	ldrh r0, [r1]
	ldrh r2, [r5, 0x28]
	cmp r0, r2
	bcs _080236FA
	adds r0, 0x1
	strh r0, [r1]
_080236FA:
	ldrb r0, [r5, 0x8]
	adds r7, r5, 0
	adds r7, 0x5E
	cmp r0, 0
	beq _08023710
	ldrb r1, [r7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08023710
	b _0802384C
_08023710:
	adds r4, r5, 0
	adds r4, 0x5C
	movs r0, 0x2
	strh r0, [r4]
	ldrh r0, [r5, 0x28]
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	mov r8, r4
	adds r6, r5, 0
	adds r6, 0x25
	cmp r0, 0
	bne _08023768
	movs r0, 0x2E
	ldrsh r2, [r5, r0]
	ldr r1, =gUnknown_082F4444
	ldrb r0, [r5, 0x9]
	subs r0, 0x2
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	ble _08023754
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	ldrb r0, [r6]
	movs r1, 0x10
	orrs r0, r1
	b _0802375C
	.pool
_08023754:
	ldrb r1, [r6]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
_0802375C:
	strb r0, [r6]
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
_08023768:
	ldrh r0, [r5, 0x28]
	movs r1, 0xF
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _080237DE
	movs r0, 0x34
	ldrsh r2, [r5, r0]
	ldr r3, =gUnknown_082F4434
	ldrb r0, [r5, 0x9]
	subs r0, 0x2
	lsls r1, r0, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bge _08023798
	ldrb r1, [r6]
	movs r0, 0x1F
	ands r0, r1
	strb r0, [r6]
	b _080237D8
	.pool
_08023798:
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _080237AC
	ldrb r0, [r6]
	movs r1, 0x1F
	ands r1, r0
	movs r0, 0x20
	b _080237D4
_080237AC:
	adds r0, r3, 0x2
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _080237BC
	movs r0, 0x2
	strh r0, [r5, 0x34]
	b _080237D8
_080237BC:
	adds r0, r3, 0x3
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _080237CC
	movs r0, 0x3
	strh r0, [r5, 0x34]
	b _080237D8
_080237CC:
	ldrb r0, [r6]
	movs r1, 0x1F
	ands r1, r0
	movs r0, 0x80
_080237D4:
	orrs r1, r0
	strb r1, [r6]
_080237D8:
	movs r0, 0
	strh r0, [r5, 0x34]
	b _0802380A
_080237DE:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3C
	bls _0802380A
	cmp r0, 0x46
	bls _080237FA
	bl sub_8011AC8
	movs r0, 0
	strh r0, [r5, 0x10]
	b _0802380A
_080237FA:
	ldrb r0, [r7]
	movs r4, 0xF8
	ands r4, r0
	cmp r4, 0
	bne _0802380A
	bl sub_8011AC8
	strh r4, [r5, 0x10]
_0802380A:
	ldrh r1, [r5, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _0802381A
	ldrb r0, [r7]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r7]
_0802381A:
	ldrb r1, [r6]
	lsls r1, 27
	lsrs r1, 31
	lsls r1, 1
	ldrb r2, [r7]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7]
	ldrb r0, [r6]
	lsrs r0, 5
	adds r2, r5, 0
	adds r2, 0x66
	strh r0, [r2]
	adds r4, r5, 0
	adds r4, 0x42
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0xC
	bl memcpy
	adds r0, r4, 0
	bl sub_800FE50
_0802384C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80236B8

	thumb_func_start sub_802385C
sub_802385C: @ 802385C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r3, =gRecvCmds
	ldrb r0, [r5, 0x9]
	cmp r4, r0
	bcs _08023880
	movs r1, 0
_0802386C:
	lsls r0, r4, 5
	adds r0, r5, r0
	adds r0, 0xB5
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r4, r0
	bcc _0802386C
_08023880:
	adds r2, r3, 0
	ldrh r0, [r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _08023898
	ldrh r0, [r2, 0x2]
	cmp r0, 0x2
	beq _080238AC
_08023898:
	adds r2, r5, 0
	adds r2, 0x25
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _080238EA
	.pool
_080238AC:
	adds r4, r5, 0
	adds r4, 0x4E
	adds r0, r4, 0
	adds r1, r3, 0
	movs r2, 0xE
	bl memcpy
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x2A]
	movs r0, 0x5
	ldrsb r0, [r4, r0]
	strh r0, [r5, 0x2C]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x28]
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_80216E0
	ldrb r1, [r4, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080238EA
	adds r0, r5, 0
	adds r0, 0x25
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_080238EA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802385C

	thumb_func_start sub_80238F0
sub_80238F0: @ 80238F0
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0xC
	bl memset
	adds r0, r4, 0
	adds r0, 0x4E
	movs r1, 0
	movs r2, 0xE
	bl memset
	adds r0, r4, 0
	bl sub_802385C
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	adds r0, r4, 0
	adds r0, 0x25
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08023978
	ldrh r1, [r4, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08023964
	adds r0, 0x1
	strh r0, [r4, 0x28]
	movs r0, 0x10
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _0802396E
	.pool
_08023964:
	movs r0, 0xF
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_0802396E:
	movs r1, 0
	movs r0, 0
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _08023992
_08023978:
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	bl sub_802339C
	adds r0, r4, 0
	bl sub_8023558
	adds r0, r4, 0
	bl sub_80236B8
	movs r0, 0
_08023992:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80238F0

	thumb_func_start sub_8023998
sub_8023998: @ 8023998
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0xC
	bl memset
	adds r0, r4, 0
	adds r0, 0x4E
	movs r1, 0
	movs r2, 0xE
	bl memset
	adds r0, r4, 0
	bl sub_802385C
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	adds r0, r4, 0
	adds r0, 0x25
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08023A20
	ldrh r1, [r4, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08023A0C
	adds r0, 0x1
	strh r0, [r4, 0x28]
	movs r0, 0x10
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08023A16
	.pool
_08023A0C:
	movs r0, 0xF
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_08023A16:
	movs r1, 0
	movs r0, 0
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _08023A28
_08023A20:
	adds r0, r4, 0
	bl sub_80236B8
	movs r0, 0
_08023A28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023998

	thumb_func_start sub_8023A30
sub_8023A30: @ 8023A30
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x5
	bls _08023A3C
	b _08023BB2
_08023A3C:
	lsls r0, 2
	ldr r1, =_08023A4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08023A4C:
	.4byte _08023A64
	.4byte _08023A8C
	.4byte _08023ADC
	.4byte _08023B5C
	.4byte _08023B7A
	.4byte _08023B94
_08023A64:
	movs r0, 0x8
	strh r0, [r4, 0x12]
	movs r0, 0xD6
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x000003ff
	movs r1, 0x8
	bl BlendPalettes
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x2
	strb r0, [r1]
	b _08023BB2
	.pool
_08023A8C:
	movs r1, 0x9C
	lsls r1, 1
	adds r5, r4, r1
	ldrb r0, [r5]
	subs r0, 0x1
	strb r0, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08023AA2
	b _08023BB8
_08023AA2:
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x000003ff
	movs r1, 0
	bl BlendPalettes
	ldr r2, =0x00000139
	adds r1, r4, r2
	movs r0, 0x4
	strb r0, [r1]
	movs r0, 0
	strb r0, [r5]
	ldr r2, =gUnknown_082F326C
	ldrb r1, [r1]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r2
	ldrb r0, [r0]
	movs r2, 0x9D
	lsls r2, 1
	adds r1, r4, r2
	strb r0, [r1]
	b _08023BB2
	.pool
_08023ADC:
	ldr r7, =gUnknown_082F326C
	movs r0, 0x9C
	lsls r0, 1
	adds r6, r4, r0
	ldr r1, =0x00000139
	adds r5, r4, r1
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	ldrb r2, [r6]
	adds r0, r2
	adds r0, r7
	movs r1, 0
	ldrsb r1, [r0, r1]
	strh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	movs r1, 0x9D
	lsls r1, 1
	adds r2, r4, r1
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2]
	cmp r0, r1
	bcc _08023BB8
	ldrb r0, [r5]
	cmp r0, 0
	beq _08023BB2
	subs r0, 0x1
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0
	strb r0, [r6]
	b _08023BB8
	.pool
_08023B5C:
	movs r0, 0
	strh r0, [r4, 0x2C]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	b _08023BB2
_08023B7A:
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r4, r2
	adds r0, r4, 0
	bl sub_80218D4
	cmp r0, 0
	beq _08023BB8
	bl sub_8010434
	movs r0, 0
	strh r0, [r4, 0x10]
	b _08023BB2
_08023B94:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023BB8
	movs r0, 0x11
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _08023BBA
_08023BB2:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_08023BB8:
	movs r0, 0
_08023BBA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8023A30

	thumb_func_start sub_8023BC0
sub_8023BC0: @ 8023BC0
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	beq _08023C04
	cmp r0, 0x1
	bgt _08023BD8
	cmp r0, 0
	beq _08023BE2
	b _08023C9C
_08023BD8:
	cmp r0, 0x2
	beq _08023C2A
	cmp r0, 0x3
	beq _08023C5C
	b _08023C9C
_08023BE2:
	movs r0, 0x9
	strh r0, [r5, 0x12]
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x8
	movs r2, 0x1F
	bl BlendPalettes
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	strb r0, [r1]
	b _08023C9C
_08023C04:
	movs r0, 0x9C
	lsls r0, 1
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08023CA2
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	movs r2, 0x1F
	bl BlendPalettes
	movs r0, 0
	strb r0, [r4]
	b _08023C9C
_08023C2A:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_80218D4
	cmp r0, 0
	beq _08023CA2
	bl sub_8010434
	movs r0, 0
	strh r0, [r5, 0x10]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	b _08023C9C
_08023C5C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023CA2
	ldr r0, =gStringVar1
	ldr r1, [r5, 0x1C]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x7
	movs r2, 0x1
	movs r3, 0
	bl sub_8024644
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strh r4, [r5, 0x10]
	b _08023CA0
	.pool
_08023C9C:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
_08023CA0:
	strb r0, [r5, 0xC]
_08023CA2:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8023BC0

	thumb_func_start sub_8023CAC
sub_8023CAC: @ 8023CAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r0, 0
	ldrb r0, [r7, 0xC]
	cmp r0, 0x7
	bls _08023CC2
	b _0802402E
_08023CC2:
	lsls r0, 2
	ldr r1, =_08023CD0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08023CD0:
	.4byte _08023CF0
	.4byte _08023D2A
	.4byte _08023D38
	.4byte _08023DA0
	.4byte _08023F20
	.4byte _08023FD0
	.4byte _08023FDC
	.4byte _08024010
_08023CF0:
	adds r4, r7, 0
	adds r4, 0x42
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x4
	bl memset
	ldrb r0, [r7, 0x8]
	lsls r0, 5
	adds r0, r7, r0
	adds r2, r0, 0
	adds r2, 0xB2
	ldrh r1, [r7, 0x28]
	ldrh r0, [r2]
	cmp r0, r1
	bls _08023D12
	strh r1, [r2]
_08023D12:
	ldrb r0, [r7, 0x8]
	lsls r0, 5
	adds r0, r7, r0
	adds r0, 0xB2
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl SendBlock
	b _0802402E
_08023D2A:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	bne _08023D36
	b _08024034
_08023D36:
	b _08024004
_08023D38:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r3, [r7, 0x9]
	subs r1, r3, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _08023D50
	b _08024034
_08023D50:
	movs r0, 0
	mov r8, r0
	adds r4, r7, 0
	adds r4, 0x42
	cmp r8, r3
	bcs _08023D7E
	ldr r2, =gBlockRecvBuffer
_08023D5E:
	mov r3, r8
	lsls r1, r3, 5
	adds r1, r7, r1
	lsls r0, r3, 8
	adds r0, r2
	ldrh r0, [r0]
	adds r1, 0xB2
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r6, [r7, 0x9]
	cmp r8, r6
	bcc _08023D5E
_08023D7E:
	movs r0, 0
	strh r0, [r7, 0x10]
	strh r0, [r4]
	bl ResetBlockReceivedFlags
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _08023D9C
	movs r0, 0x3
	b _08024032
	.pool
_08023D9C:
	movs r0, 0x6
	b _08024032
_08023DA0:
	adds r0, r7, 0
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldrh r1, [r7, 0x28]
	adds r0, r7, 0
	adds r0, 0x6C
	strh r1, [r0]
	movs r0, 0x18
	ldrsh r4, [r7, r0]
	ldrh r0, [r7, 0x28]
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl __divsi3
	adds r1, r7, 0
	adds r1, 0x6E
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	lsls r0, 8
	movs r4, 0xC8
	lsls r4, 6
	adds r1, r4, 0
	bl sub_8151574
	adds r2, r0, 0
	movs r3, 0x32
	ldrsh r1, [r7, r3]
	lsls r1, 8
	bl sub_81515FC
	adds r2, r0, r4
	asrs r2, 8
	movs r1, 0x7F
	adds r0, r2, 0
	ands r0, r1
	adds r1, r7, 0
	adds r1, 0x70
	strh r0, [r1]
	lsls r2, 8
	movs r1, 0xC8
	lsls r1, 7
	adds r0, r2, 0
	bl sub_81515FC
	adds r2, r0, 0
	ldrb r1, [r7, 0x9]
	ldr r0, [r7, 0x1C]
	muls r0, r1
	lsls r4, r0, 8
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_8151574
	adds r4, r0, 0
	asrs r0, r4, 8
	str r0, [r7, 0x68]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r1, r7, 0
	adds r1, 0x8F
	strb r0, [r1]
	movs r6, 0
	mov r8, r6
	mov r9, r1
	ldrb r0, [r7, 0x9]
	cmp r8, r0
	bcc _08023E44
	b _0802402E
_08023E44:
	adds r0, r7, 0
	adds r0, 0x88
	add r0, r8
	mov r1, r8
	strb r1, [r0]
	adds r0, r7, 0
	adds r0, 0x90
	add r0, r8
	strb r1, [r0]
	mov r3, r8
	lsls r2, r3, 1
	adds r1, r7, 0
	adds r1, 0x74
	adds r1, r2
	lsls r0, r3, 5
	adds r3, r7, r0
	adds r5, r3, 0
	adds r5, 0xAE
	ldrh r0, [r5]
	strh r0, [r1]
	adds r1, r7, 0
	adds r1, 0x72
	ldrh r6, [r1]
	adds r0, r6
	strh r0, [r1]
	mov r1, r9
	ldrb r0, [r1]
	adds r6, r2, 0
	cmp r0, 0x1
	beq _08023EAE
	cmp r0, 0x1
	bgt _08023E8A
	cmp r0, 0
	beq _08023E90
	b _08023F04
_08023E8A:
	cmp r0, 0x2
	beq _08023ECC
	b _08023F04
_08023E90:
	ldrh r0, [r5]
	cmp r0, 0
	beq _08023ED2
	adds r0, r3, 0
	adds r0, 0xAC
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r5]
	b _08023EFA
_08023EAE:
	ldrh r0, [r5]
	cmp r0, 0
	beq _08023ED2
	adds r0, r3, 0
	adds r0, 0xB0
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r5]
	b _08023EFA
_08023ECC:
	ldrh r0, [r5]
	cmp r0, 0
	bne _08023ED6
_08023ED2:
	movs r4, 0
	b _08023F04
_08023ED6:
	adds r1, r3, 0
	adds r1, 0xB2
	ldrh r0, [r1]
	ldrh r2, [r7, 0x28]
	cmp r0, r2
	bcc _08023EE8
	movs r4, 0xC8
	lsls r4, 7
	b _08023F04
_08023EE8:
	ldrh r2, [r1]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r7, 0x28]
_08023EFA:
	lsls r4, 8
	adds r1, r4, 0
	bl sub_81515FC
	adds r4, r0, 0
_08023F04:
	asrs r4, 4
	adds r0, r7, 0
	adds r0, 0x7E
	adds r0, r6
	strh r4, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r7, 0x9]
	cmp r8, r3
	bcc _08023E44
	b _0802402E
_08023F20:
	movs r6, 0
	mov r8, r6
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	adds r1, r7, 0
	adds r1, 0x68
	str r1, [sp, 0xC]
	cmp r8, r0
	bge _08023FC4
_08023F32:
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r2, r8
	adds r2, 0x1
	str r2, [sp, 0x8]
	cmp r4, r8
	bls _08023FB4
	adds r3, r7, 0
	adds r3, 0x74
	str r3, [sp]
	adds r6, r7, 0
	adds r6, 0x88
	str r6, [sp, 0x4]
	movs r0, 0x90
	adds r0, r7
	mov r10, r0
	movs r1, 0x7E
	adds r1, r7
	mov r9, r1
_08023F5C:
	subs r2, r4, 0x1
	mov r12, r2
	lsls r6, r2, 1
	ldr r0, [sp]
	adds r3, r0, r6
	lsls r5, r4, 1
	adds r1, r0, r5
	ldrh r2, [r3]
	ldrh r0, [r1]
	cmp r2, r0
	bcs _08023F86
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	ldr r1, [sp, 0x4]
	adds r2, r1, r4
	ldrb r3, [r2]
	add r1, r12
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023F86:
	mov r2, r9
	adds r3, r2, r6
	adds r1, r2, r5
	ldrh r2, [r3]
	ldrh r6, [r1]
	cmp r2, r6
	bcs _08023FAA
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	mov r0, r10
	adds r2, r0, r4
	ldrb r3, [r2]
	mov r1, r10
	add r1, r12
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023FAA:
	mov r1, r12
	lsls r0, r1, 24
	lsrs r4, r0, 24
	cmp r4, r8
	bhi _08023F5C
_08023FB4:
	ldr r2, [sp, 0x8]
	lsls r0, r2, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	cmp r8, r0
	blt _08023F32
_08023FC4:
	movs r0, 0
	ldr r1, [sp, 0xC]
	movs r2, 0x30
	bl SendBlock
	b _0802402E
_08023FD0:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08024034
	b _08024004
_08023FDC:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08024034
	adds r4, r7, 0
	adds r4, 0x68
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldr r1, =gBlockRecvBuffer
	adds r0, r4, 0
	movs r2, 0x30
	bl memcpy
	bl ResetBlockReceivedFlags
_08024004:
	movs r0, 0
	strh r0, [r7, 0x10]
	b _0802402E
	.pool
_08024010:
	bl sub_8020E58
	movs r0, 0x12
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	movs r1, 0xB
	strh r1, [r7, 0x12]
	strb r0, [r7, 0xC]
	adds r1, r7, 0
	adds r1, 0x24
	strb r0, [r1]
	b _08024034
_0802402E:
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
_08024032:
	strb r0, [r7, 0xC]
_08024034:
	movs r0, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8023CAC

	thumb_func_start sub_8024048
sub_8024048: @ 8024048
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x4
	bhi _08024124
	lsls r0, 2
	ldr r1, =_08024064
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024064:
	.4byte _08024078
	.4byte _0802408A
	.4byte _0802409C
	.4byte _080240CC
	.4byte _080240DC
_08024078:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_8022070
	cmp r0, 0
	bne _08024124
	b _0802412A
_0802408A:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1E
	strb r0, [r1]
	b _08024124
_0802409C:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080240AE
	subs r0, 0x1
	strb r0, [r1]
	b _0802412A
_080240AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0802412A
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_802222C
	b _08024124
	.pool
_080240CC:
	ldrh r0, [r5, 0x12]
	cmp r0, 0xC
	bhi _08024124
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _0802412A
_080240DC:
	ldr r0, =gStringVar1
	ldr r1, [r5, 0x1C]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	bl GetBerryPowder
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x3
	movs r3, 0
	bl sub_8024644
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802412A
	.pool
_08024124:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802412A:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8024048

	thumb_func_start sub_8024134
sub_8024134: @ 8024134
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x4
	bhi _08024218
	lsls r0, 2
	ldr r1, =_08024150
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024150:
	.4byte _08024164
	.4byte _080241A0
	.4byte _080241A6
	.4byte _080241F0
	.4byte _08024204
_08024164:
	ldrh r1, [r5, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08024176
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r5, r1
	bl sub_8022554
_08024176:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r4, 0
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802421E
	.pool
_080241A0:
	bl sub_8010434
	b _08024218
_080241A6:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802421E
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldr r2, =gText_SavingDontTurnOffPower
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized2
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_8153688
	movs r1, 0
	bl CreateTask
	b _08024218
	.pool
_080241F0:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _08024218
	b _0802421E
	.pool
_08024204:
	movs r0, 0x14
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0xF
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _0802421E
_08024218:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802421E:
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024134

	thumb_func_start sub_8024228
sub_8024228: @ 8024228
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	beq _0802426A
	cmp r0, 0x1
	bgt _08024240
	cmp r0, 0
	beq _08024246
	b _080242D0
_08024240:
	cmp r0, 0x2
	beq _08024270
	b _080242D0
_08024246:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0x4
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x14
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strb r0, [r5, 0xC]
	b _080242D8
_0802426A:
	bl DisplayYesNoMenuDefaultYes
	b _080242D0
_08024270:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _080242D6
	adds r0, r5, 0
	adds r0, 0x42
	movs r1, 0
	movs r2, 0xC
	bl memset
	cmp r4, 0
	bne _080242A2
	bl HasAtLeastOneBerry
	lsls r0, 24
	cmp r0, 0
	beq _0802429E
	strh r4, [r5, 0x14]
	b _080242A6
_0802429E:
	movs r0, 0x3
	b _080242A4
_080242A2:
	movs r0, 0x1
_080242A4:
	strh r0, [r5, 0x14]
_080242A6:
	movs r0, 0
	movs r1, 0x1
	bl ClearDialogWindowAndFrame
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x15
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _080242D6
_080242D0:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_080242D6:
	movs r0, 0
_080242D8:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8024228

	thumb_func_start sub_80242E0
sub_80242E0: @ 80242E0
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08024306
	cmp r0, 0x1
	bgt _080242F6
	cmp r0, 0
	beq _08024300
	b _080243AC
_080242F6:
	cmp r0, 0x2
	beq _08024328
	cmp r0, 0x3
	beq _08024336
	b _080243AC
_08024300:
	bl sub_8010434
	b _080243AC
_08024306:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080243B2
	ldrh r0, [r4, 0x14]
	adds r1, r4, 0
	adds r1, 0x42
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x4E
	strh r5, [r0]
	movs r0, 0
	movs r2, 0x2
	bl SendBlock
	b _080243AC
_08024328:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080243B2
	strh r5, [r4, 0x10]
	b _080243AC
_08024336:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r3, [r4, 0x9]
	subs r1, r3, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _080243B2
	adds r7, r4, 0
	adds r7, 0x42
	adds r6, r4, 0
	adds r6, 0x4E
	cmp r5, r3
	bcs _08024374
	adds r1, r6, 0
	ldr r2, =gBlockRecvBuffer
_0802435C:
	lsls r0, r5, 8
	adds r0, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r4, 0x9]
	cmp r5, r0
	bcc _0802435C
_08024374:
	ldrh r0, [r6]
	cmp r0, 0
	beq _08024390
	movs r0, 0x17
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _0802439A
	.pool
_08024390:
	movs r0, 0x16
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_0802439A:
	bl ResetBlockReceivedFlags
	movs r1, 0
	movs r0, 0
	strh r0, [r7]
	strh r0, [r6]
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _080243B4
_080243AC:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_080243B2:
	movs r0, 0
_080243B4:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80242E0

	thumb_func_start sub_80243BC
sub_80243BC: @ 80243BC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _080243EA
	cmp r4, 0x1
	bgt _080243D2
	cmp r4, 0
	beq _080243DC
	b _08024434
_080243D2:
	cmp r4, 0x2
	beq _080243F6
	cmp r4, 0x3
	beq _0802441A
	b _08024434
_080243DC:
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	b _08024410
_080243EA:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _08024434
	b _0802443A
_080243F6:
	movs r0, 0
	movs r1, 0x1
	bl ClearDialogWindowAndFrame
	adds r0, r5, 0
	bl sub_8021488
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
_08024410:
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _08024434
_0802441A:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0802443A
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strh r4, [r5, 0x12]
	b _08024438
_08024434:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
_08024438:
	strb r0, [r5, 0xC]
_0802443A:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80243BC

	thumb_func_start sub_8024444
sub_8024444: @ 8024444
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _080244BC
	cmp r4, 0x1
	bgt _0802445A
	cmp r4, 0
	beq _08024460
	b _080244F6
_0802445A:
	cmp r4, 0x2
	beq _080244D4
	b _080244F6
_08024460:
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldrh r1, [r5, 0x14]
	cmp r1, 0x3
	bne _08024490
	ldr r0, =gUnknown_082F32A4
	ldr r2, [r0, 0x14]
	ldrb r3, [r5, 0xB]
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
	b _080244AC
	.pool
_08024490:
	ldr r0, =gUnknown_082F32A4
	ldr r2, [r0, 0x18]
	ldrb r3, [r5, 0xB]
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
_080244AC:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _080244F6
	.pool
_080244BC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080244FC
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x78
	strb r0, [r1]
	b _080244F6
_080244D4:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r4, r0, 0
	cmp r4, 0
	beq _080244E8
	subs r0, 0x1
	strb r0, [r1]
	b _080244FC
_080244E8:
	movs r0, 0x18
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _080244FC
_080244F6:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_080244FC:
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024444

	thumb_func_start sub_8024508
sub_8024508: @ 8024508
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _08024528
	cmp r4, 0x1
	bgt _0802451C
	cmp r4, 0
	beq _08024522
	b _08024558
_0802451C:
	cmp r4, 0x2
	beq _08024538
	b _08024558
_08024522:
	bl sub_8010434
	b _08024558
_08024528:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802455E
	bl sub_800AC34
	b _08024558
_08024538:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802455E
	movs r0, 0x19
	strb r0, [r5, 0xE]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802455E
	.pool
_08024558:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802455E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024508

	thumb_func_start sub_8024568
sub_8024568: @ 8024568
	push {lr}
	movs r0, 0
	bl sub_8020C0C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8024568

	thumb_func_start sub_8024578
sub_8024578: @ 8024578
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0x33
	bl IncrementGameStat
	strb r5, [r4, 0xD]
	movs r1, 0
	strh r5, [r4, 0x10]
	movs r0, 0x2
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	str r5, [r4, 0x1C]
	strh r5, [r4, 0x18]
	strh r5, [r4, 0x1A]
	str r5, [r4, 0x20]
	adds r0, r4, 0
	adds r0, 0x24
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x25
	movs r0, 0
	strb r0, [r1]
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x28]
	strh r5, [r4, 0x2E]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x34]
	movs r6, 0
	movs r3, 0
_080245B8:
	lsls r0, r5, 5
	adds r2, r4, r0
	adds r1, r2, 0
	adds r1, 0xA4
	ldr r0, =0x0000ffff
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xA6
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r1, 0x6
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xAC
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strb r6, [r0]
	adds r0, 0x1
	strb r6, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _080245B8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024578

	thumb_func_start sub_8024604
sub_8024604: @ 8024604
	push {r4-r6,lr}
	sub sp, 0x8
	str r2, [sp, 0x4]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	ldr r4, [sp, 0x20]
	mov r2, sp
	strh r4, [r2]
	add r4, sp, 0x4
	ldrb r2, [r4]
	strb r2, [r0]
	ldrb r2, [r4, 0x1]
	strb r2, [r0, 0x1]
	ldrb r2, [r4, 0x2]
	strb r2, [r0, 0x2]
	ldrb r2, [r4, 0x3]
	strb r2, [r0, 0x3]
	strb r3, [r0, 0x4]
	strb r5, [r0, 0x5]
	strb r6, [r0, 0x6]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0, 0x7]
	mov r2, sp
	ldrb r2, [r2, 0x1]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8024604

	thumb_func_start sub_8024644
sub_8024644: @ 8024644
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, [sp, 0x10]
	mov r4, sp
	strh r3, [r4]
	strb r1, [r0]
	strb r2, [r0, 0x1]
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0, 0x2]
	mov r1, sp
	ldrb r1, [r1, 0x1]
	strb r1, [r0, 0x3]
	strb r5, [r0, 0x4]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8024644

	.align 2, 0 @ don't pad with nop
