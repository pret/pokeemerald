	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start CopyString_Limit10
@ u8 *CopyString_Limit10(u8 *dest, u8 *src)
CopyString_Limit10: @ 8008B10
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0xA
	movs r3, 0
_08008B18:
	adds r2, r4, r3
	adds r0, r1, r3
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08008B2C
	adds r0, r2, 0
	b _08008B3C
_08008B2C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r5
	bcc _08008B18
	adds r0, r4, r3
	movs r1, 0xFF
	strb r1, [r0]
_08008B3C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CopyString_Limit10

	thumb_func_start GetStringEnd_Limit7
@ u8 *GetStringEnd_Limit7(u8 *s)
GetStringEnd_Limit7: @ 8008B44
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0xA
	movs r2, 0
_08008B4C:
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _08008B58
	adds r0, r1, 0
	b _08008B68
_08008B58:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r4
	bcc _08008B4C
	adds r0, r3, r2
	movs r1, 0xFF
	strb r1, [r0]
_08008B68:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetStringEnd_Limit7

	thumb_func_start CopyString_Limit7
@ u8 *CopyString_Limit7(u8 *dest, u8 *src)
CopyString_Limit7: @ 8008B70
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x7
	movs r3, 0
_08008B78:
	adds r2, r4, r3
	adds r0, r1, r3
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08008B8C
	adds r0, r2, 0
	b _08008B98
_08008B8C:
	adds r3, 0x1
	cmp r3, r5
	blt _08008B78
	adds r0, r4, r3
	movs r1, 0xFF
	strb r1, [r0]
_08008B98:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CopyString_Limit7

	thumb_func_start CopyString
@ u8 *CopyString(u8 *dest, u8 *src)
CopyString: @ 8008BA0
	push {lr}
	adds r3, r0, 0
	b _08008BAC
_08008BA6:
	strb r2, [r3]
	adds r3, 0x1
	adds r1, 0x1
_08008BAC:
	ldrb r2, [r1]
	adds r0, r2, 0
	cmp r0, 0xFF
	bne _08008BA6
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end CopyString

	thumb_func_start AppendString
@ u8 *AppendString(u8 *dest, u8 *src)
AppendString: @ 8008BC0
	push {lr}
	adds r2, r0, 0
	b _08008BC8
_08008BC6:
	adds r2, 0x1
_08008BC8:
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _08008BC6
	adds r0, r2, 0
	bl CopyString
	pop {r1}
	bx r1
	thumb_func_end AppendString

	thumb_func_start CopyString_LimitN
@ u8 *CopyString_LimitN(u8 *dest, u8 *src, u8 n)
CopyString_LimitN: @ 8008BD8
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r5, r2, 24
	movs r3, 0
	adds r0, r5, 0
	cmp r3, r0
	bcs _08008BFE
	adds r2, r0, 0
_08008BEC:
	adds r1, r4, r3
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r2
	bcc _08008BEC
_08008BFE:
	adds r0, r4, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CopyString_LimitN

	thumb_func_start AppendString_LimitN
@ u8 *AppendString_LimitN(u8 *dest, u8 *src, u8 n)
AppendString_LimitN: @ 8008C08
	push {lr}
	adds r3, r0, 0
	lsls r2, 24
	lsrs r2, 24
	b _08008C14
_08008C12:
	adds r3, 0x1
_08008C14:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _08008C12
	adds r0, r3, 0
	bl CopyString_LimitN
	pop {r1}
	bx r1
	thumb_func_end AppendString_LimitN

	thumb_func_start GetStringLength
@ u16 GetStringLength(u8 *s)
GetStringLength: @ 8008C24
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08008C3E
_08008C30:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08008C30
_08008C3E:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end GetStringLength

	thumb_func_start CompareString
@ u8 CompareString(u8 *s1, u8 *s2)
CompareString: @ 8008C44
	push {lr}
	adds r2, r0, 0
	b _08008C56
_08008C4A:
	cmp r0, 0xFF
	bne _08008C52
	movs r0, 0
	b _08008C64
_08008C52:
	adds r2, 0x1
	adds r1, 0x1
_08008C56:
	ldrb r0, [r2]
	ldrb r3, [r1]
	cmp r0, r3
	beq _08008C4A
	ldrb r0, [r2]
	ldrb r1, [r1]
	subs r0, r1
_08008C64:
	pop {r1}
	bx r1
	thumb_func_end CompareString

	thumb_func_start CompareString_LimitN
@ u8 CompareString_LimitN(u8 *s1, u8 *s2, u32 n)
CompareString_LimitN: @ 8008C68
	push {r4,lr}
	adds r3, r0, 0
	b _08008C80
_08008C6E:
	cmp r0, 0xFF
	beq _08008C7C
	adds r3, 0x1
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _08008C80
_08008C7C:
	movs r0, 0
	b _08008C8E
_08008C80:
	ldrb r0, [r3]
	ldrb r4, [r1]
	cmp r0, r4
	beq _08008C6E
	ldrb r0, [r3]
	ldrb r1, [r1]
	subs r0, r1
_08008C8E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end CompareString_LimitN

	thumb_func_start IsStringLengthLessThanN
@ bool8 IsStringLengthLessThanN(u8 *s, s32 n)
IsStringLengthLessThanN: @ 8008C94
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	cmp r2, r1
	bge _08008CB8
_08008C9E:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08008CAE
	cmp r0, 0xFF
	beq _08008CAE
	movs r0, 0x1
	b _08008CBA
_08008CAE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r1
	blt _08008C9E
_08008CB8:
	movs r0, 0
_08008CBA:
	pop {r1}
	bx r1
	thumb_func_end IsStringLengthLessThanN

	thumb_func_start ConvertIntToDecimalString
@ u8 *ConvertIntToDecimalString(u8 *dest, s32 value, u8 mode, u8 numDigits)
ConvertIntToDecimalString: @ 8008CC0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r3, 24
	ldr r0, =gPowersOfTen
	lsrs r3, 22
	subs r3, 0x4
	adds r3, r0
	ldr r0, [r3]
	movs r7, 0
	cmp r2, 0x1
	bne _08008CDE
	movs r7, 0x2
_08008CDE:
	cmp r2, 0x2
	bne _08008CE4
	movs r7, 0x1
_08008CE4:
	adds r5, r0, 0
	cmp r5, 0
	ble _08008D60
	ldr r0, =gDigits
	mov r8, r0
_08008CEE:
	adds r0, r6, 0
	adds r1, r5, 0
	bl __divsi3
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, r2, 0
	adds r0, r5, 0
	muls r0, r2
	subs r1, r6, r0
	cmp r7, 0x1
	bne _08008D26
	adds r3, r4, 0
	adds r4, 0x1
	cmp r2, 0x9
	bhi _08008D20
	mov r6, r8
	adds r0, r2, r6
	ldrb r0, [r0]
	b _08008D22
	.pool
_08008D20:
	movs r0, 0xAC
_08008D22:
	strb r0, [r3]
	b _08008D50
_08008D26:
	cmp r2, 0
	bne _08008D2E
	cmp r5, 0x1
	bne _08008D46
_08008D2E:
	movs r7, 0x1
	adds r2, r4, 0
	adds r4, 0x1
	cmp r3, 0x9
	bhi _08008D40
	mov r6, r8
	adds r0, r3, r6
	ldrb r0, [r0]
	b _08008D42
_08008D40:
	movs r0, 0xAC
_08008D42:
	strb r0, [r2]
	b _08008D50
_08008D46:
	cmp r7, 0x2
	bne _08008D50
	movs r0, 0x77
	strb r0, [r4]
	adds r4, 0x1
_08008D50:
	adds r6, r1, 0
	adds r0, r5, 0
	movs r1, 0xA
	bl __divsi3
	adds r5, r0, 0
	cmp r5, 0
	bgt _08008CEE
_08008D60:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ConvertIntToDecimalString

	thumb_func_start ConvertUnsignedIntToDecimalString
@ u8 *ConvertUnsignedIntToDecimalString(u8 *dest, u32 value, u8 mode, u8 numDigits)
ConvertUnsignedIntToDecimalString: @ 8008D70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r3, 24
	ldr r0, =gPowersOfTen
	lsrs r3, 22
	subs r3, 0x4
	adds r3, r0
	ldr r0, [r3]
	movs r7, 0
	cmp r2, 0x1
	bne _08008D8E
	movs r7, 0x2
_08008D8E:
	cmp r2, 0x2
	bne _08008D94
	movs r7, 0x1
_08008D94:
	adds r5, r0, 0
	cmp r5, 0
	ble _08008E10
	ldr r0, =gDigits
	mov r8, r0
_08008D9E:
	adds r0, r6, 0
	adds r1, r5, 0
	bl __udivsi3
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, r2, 0
	adds r0, r5, 0
	muls r0, r2
	subs r1, r6, r0
	cmp r7, 0x1
	bne _08008DD6
	adds r3, r4, 0
	adds r4, 0x1
	cmp r2, 0x9
	bhi _08008DD0
	mov r6, r8
	adds r0, r2, r6
	ldrb r0, [r0]
	b _08008DD2
	.pool
_08008DD0:
	movs r0, 0xAC
_08008DD2:
	strb r0, [r3]
	b _08008E00
_08008DD6:
	cmp r2, 0
	bne _08008DDE
	cmp r5, 0x1
	bne _08008DF6
_08008DDE:
	movs r7, 0x1
	adds r2, r4, 0
	adds r4, 0x1
	cmp r3, 0x9
	bhi _08008DF0
	mov r6, r8
	adds r0, r3, r6
	ldrb r0, [r0]
	b _08008DF2
_08008DF0:
	movs r0, 0xAC
_08008DF2:
	strb r0, [r2]
	b _08008E00
_08008DF6:
	cmp r7, 0x2
	bne _08008E00
	movs r0, 0x77
	strb r0, [r4]
	adds r4, 0x1
_08008E00:
	adds r6, r1, 0
	adds r0, r5, 0
	movs r1, 0xA
	bl __divsi3
	adds r5, r0, 0
	cmp r5, 0
	bgt _08008D9E
_08008E10:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ConvertUnsignedIntToDecimalString

	thumb_func_start ConvertIntToHexString
@ u8 *ConvertIntToHexString(u8 *dest, s32 value, u8 mode, u8 numDigits)
ConvertIntToHexString: @ 8008E20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	movs r0, 0x1
	cmp r1, r3
	bcs _08008E46
_08008E3A:
	lsls r1, 4
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r3
	bcc _08008E3A
_08008E46:
	movs r3, 0
	cmp r2, 0x1
	bne _08008E4E
	movs r3, 0x2
_08008E4E:
	cmp r2, 0x2
	bne _08008E54
	movs r3, 0x1
_08008E54:
	adds r5, r1, 0
	cmp r5, 0
	ble _08008ECA
	ldr r0, =gDigits
	mov r9, r0
_08008E5E:
	mov r0, r8
	adds r1, r5, 0
	str r3, [sp]
	bl __divsi3
	adds r4, r0, 0
	adds r7, r4, 0
	mov r0, r8
	adds r1, r5, 0
	bl __modsi3
	adds r1, r0, 0
	ldr r3, [sp]
	cmp r3, 0x1
	bne _08008E90
	adds r2, r6, 0
	adds r6, 0x1
	cmp r4, 0xF
	bhi _08008EAA
	mov r7, r9
	adds r0, r4, r7
	ldrb r0, [r0]
	b _08008EAC
	.pool
_08008E90:
	cmp r4, 0
	bne _08008E98
	cmp r5, 0x1
	bne _08008EB0
_08008E98:
	movs r3, 0x1
	adds r2, r6, 0
	adds r6, 0x1
	cmp r7, 0xF
	bhi _08008EAA
	mov r4, r9
	adds r0, r7, r4
	ldrb r0, [r0]
	b _08008EAC
_08008EAA:
	movs r0, 0xAC
_08008EAC:
	strb r0, [r2]
	b _08008EBA
_08008EB0:
	cmp r3, 0x2
	bne _08008EBA
	movs r0, 0x77
	strb r0, [r6]
	adds r6, 0x1
_08008EBA:
	mov r8, r1
	adds r0, r5, 0
	cmp r5, 0
	bge _08008EC4
	adds r0, 0xF
_08008EC4:
	asrs r5, r0, 4
	cmp r5, 0
	bgt _08008E5E
_08008ECA:
	movs r0, 0xFF
	strb r0, [r6]
	adds r0, r6, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ConvertIntToHexString

	thumb_func_start ExpandStringRefs
@ u8 *ExpandStringRefs(u8 *dest, u8 *src)
ExpandStringRefs: @ 8008EE0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
_08008EE6:
	ldrb r2, [r5]
	adds r5, 0x1
	adds r0, r2, 0
	subs r0, 0xFA
	cmp r0, 0x5
	bhi _08008FBA
	lsls r0, 2
	ldr r1, =_08008F00
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08008F00:
	.4byte _08008FBA
	.4byte _08008FBA
	.4byte _08008F2C
	.4byte _08008F18
	.4byte _08008FBA
	.4byte _08008FC0
_08008F18:
	ldrb r0, [r5]
	adds r5, 0x1
	bl GetExpandedStringRef
	adds r1, r0, 0
	adds r0, r4, 0
	bl ExpandStringRefs
	adds r4, r0, 0
	b _08008EE6
_08008F2C:
	strb r2, [r4]
	adds r4, 0x1
	ldrb r2, [r5]
	adds r5, 0x1
	strb r2, [r4]
	adds r4, 0x1
	subs r0, r2, 0x4
	cmp r0, 0x14
	bhi _08008FB0
	lsls r0, 2
	ldr r1, =_08008F4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08008F4C:
	.4byte _08008FA0
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008EE6
	.4byte _08008FB0
	.4byte _08008EE6
	.4byte _08008FB0
	.4byte _08008FA8
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008EE6
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008FB0
	.4byte _08008EE6
	.4byte _08008EE6
	.4byte _08008EE6
	.4byte _08008EE6
_08008FA0:
	ldrb r0, [r5]
	strb r0, [r4]
	adds r5, 0x1
	adds r4, 0x1
_08008FA8:
	ldrb r0, [r5]
	strb r0, [r4]
	adds r5, 0x1
	adds r4, 0x1
_08008FB0:
	ldrb r0, [r5]
	strb r0, [r4]
	adds r5, 0x1
	adds r4, 0x1
	b _08008EE6
_08008FBA:
	strb r2, [r4]
	adds r4, 0x1
	b _08008EE6
_08008FC0:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end ExpandStringRefs

	thumb_func_start sub_8008FCC
@ u8 *sub_8008FCC(u8 *dest, u8 *src)
sub_8008FCC: @ 8008FCC
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r1, =gUnknown_082EC80C
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	add r4, sp, 0x4
	ldr r1, =gUnknown_082EC810
	adds r0, r4, 0
	movs r2, 0x5
	bl memcpy
	adds r0, r5, 0
	mov r1, sp
_08008FEE:
	bl CopyString
	adds r5, r0, 0
_08008FF4:
	ldrb r0, [r6]
	adds r6, 0x1
	cmp r0, 0xFE
	beq _0800900C
	cmp r0, 0xFF
	bne _08009012
	b _0800901E
	.pool
_0800900C:
	adds r0, r5, 0
	adds r1, r4, 0
	b _08008FEE
_08009012:
	strb r0, [r5]
	adds r5, 0x1
	adds r0, 0x40
	strb r0, [r5]
	adds r5, 0x1
	b _08008FF4
_0800901E:
	strb r0, [r5]
	adds r0, r5, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8008FCC

	thumb_func_start StringRef_GetPossiblyUnusedStringVar
@ u8 *StringRef_GetPossiblyUnusedStringVar()
StringRef_GetPossiblyUnusedStringVar: @ 800902C
	ldr r0, =0x020223ac
	bx lr
	.pool
	thumb_func_end StringRef_GetPossiblyUnusedStringVar

	thumb_func_start StringRef_GetPlayerName
@ u8 *StringRef_GetPlayerName()
StringRef_GetPlayerName: @ 8009034
	ldr r0, =0x03005d90
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end StringRef_GetPlayerName

	thumb_func_start StringRef_GetStringVar1
@ u8 *StringRef_GetStringVar1()
StringRef_GetStringVar1: @ 8009040
	ldr r0, =0x02021cc4
	bx lr
	.pool
	thumb_func_end StringRef_GetStringVar1

	thumb_func_start StringRef_GetStringVar2
@ u8 *StringRef_GetStringVar2()
StringRef_GetStringVar2: @ 8009048
	ldr r0, =0x02021dc4
	bx lr
	.pool
	thumb_func_end StringRef_GetStringVar2

	thumb_func_start StringRef_GetStringVar3
@ u8 *StringRef_GetStringVar3()
StringRef_GetStringVar3: @ 8009050
	ldr r0, =0x02021ec4
	bx lr
	.pool
	thumb_func_end StringRef_GetStringVar3

	thumb_func_start StringRef_GetDummiedOutGenderDependentString
@ u8 *StringRef_GetDummiedOutGenderDependentString()
StringRef_GetDummiedOutGenderDependentString: @ 8009058
	push {lr}
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _08009070
	ldr r0, =gUnknown_085E821A
	b _08009072
	.pool
_08009070:
	ldr r0, =gUnknown_085E8219
_08009072:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StringRef_GetDummiedOutGenderDependentString

	thumb_func_start StringRef_GetRivalName
@ u8 *StringRef_GetRivalName()
StringRef_GetRivalName: @ 800907C
	push {lr}
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _08009094
	ldr r0, =gUnknown_085E8258
	b _08009096
	.pool
_08009094:
	ldr r0, =gUnknown_085E8260
_08009096:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StringRef_GetRivalName

	thumb_func_start StringRef_GetEmeraldString
@ u8 *StringRef_GetEmeraldString()
StringRef_GetEmeraldString: @ 80090A0
	ldr r0, =gUnknown_085E8229
	bx lr
	.pool
	thumb_func_end StringRef_GetEmeraldString

	thumb_func_start StringRef_GetAquaString
@ u8 *StringRef_GetAquaString()
StringRef_GetAquaString: @ 80090A8
	ldr r0, =gUnknown_085E8231
	bx lr
	.pool
	thumb_func_end StringRef_GetAquaString

	thumb_func_start StringRef_GetMagmaString
@ u8 *StringRef_GetMagmaString()
StringRef_GetMagmaString: @ 80090B0
	ldr r0, =gUnknown_085E8236
	bx lr
	.pool
	thumb_func_end StringRef_GetMagmaString

	thumb_func_start StringRef_GetArchieString
@ u8 *StringRef_GetArchieString()
StringRef_GetArchieString: @ 80090B8
	ldr r0, =gUnknown_085E823C
	bx lr
	.pool
	thumb_func_end StringRef_GetArchieString

	thumb_func_start StringRef_GetMaxieString
@ u8 *StringRef_GetMaxieString()
StringRef_GetMaxieString: @ 80090C0
	ldr r0, =gUnknown_085E8243
	bx lr
	.pool
	thumb_func_end StringRef_GetMaxieString

	thumb_func_start StringRef_GetKyogreString
@ u8 *StringRef_GetKyogreString()
StringRef_GetKyogreString: @ 80090C8
	ldr r0, =gUnknown_085E8249
	bx lr
	.pool
	thumb_func_end StringRef_GetKyogreString

	thumb_func_start StringRef_GetGroudonString
@ u8 *StringRef_GetGroudonString()
StringRef_GetGroudonString: @ 80090D0
	ldr r0, =gUnknown_085E8250
	bx lr
	.pool
	thumb_func_end StringRef_GetGroudonString

	thumb_func_start GetExpandedStringRef
@ u8 *GetExpandedStringRef(u8 code)
GetExpandedStringRef: @ 80090D8
	push {lr}
	cmp r0, 0xD
	bhi _080090F0
	ldr r1, =gStringRefFunctionTable
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	b _080090F2
	.pool
_080090F0:
	ldr r0, =gUnknown_085E8218
_080090F2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetExpandedStringRef

	thumb_func_start RepeatChar
@ u8 *RepeatChar(u8 *dest, u8 c, u16 n)
RepeatChar: @ 80090FC
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	cmp r0, r2
	bcs _0800911C
_0800910E:
	strb r1, [r3]
	adds r3, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r2
	bcc _0800910E
_0800911C:
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end RepeatChar

	thumb_func_start CopyStringPadded
@ u8 *CopyStringPadded(u8 *dest, u8 *src, u8 c, u16 n)
CopyStringPadded: @ 8009128
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 16
	lsrs r3, 16
	b _08009148
_08009138:
	strb r1, [r4]
	adds r5, 0x1
	adds r4, 0x1
	cmp r3, 0
	beq _08009148
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
_08009148:
	ldrb r1, [r5]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _08009138
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _0800916C
	adds r1, r0, 0
_0800915E:
	strb r2, [r4]
	adds r4, 0x1
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	bne _0800915E
_0800916C:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CopyStringPadded

	thumb_func_start RepeatStringTerminator
@ u8 *RepeatStringTerminator(u8 *dest, u16 n)
RepeatStringTerminator: @ 800917C
	push {lr}
	lsls r2, r1, 16
	lsrs r2, 16
	movs r1, 0xFF
	bl RepeatChar
	pop {r1}
	bx r1
	thumb_func_end RepeatStringTerminator

	thumb_func_start CopyString_LimitN_Multibyte
@ u8 *CopyString_LimitN_Multibyte(u8 *dest, u8 *src, u32 n)
CopyString_LimitN_Multibyte: @ 800918C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	subs r2, 0x1
	movs r5, 0x1
	negs r5, r5
	b _080091B2
_0800919A:
	strb r0, [r4]
	adds r3, 0x1
	adds r4, 0x1
	subs r0, r3, 0x1
	ldrb r0, [r0]
	cmp r0, 0xF9
	bne _080091B0
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, 0x1
	adds r4, 0x1
_080091B0:
	subs r2, 0x1
_080091B2:
	cmp r2, r5
	beq _080091BE
	ldrb r0, [r3]
	adds r1, r0, 0
	cmp r1, 0xFF
	bne _0800919A
_080091BE:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CopyString_LimitN_Multibyte

	thumb_func_start GetStringLength_Multibyte
@ u32 GetStringLength_Multibyte(u8 *s)
GetStringLength_Multibyte: @ 80091CC
	push {lr}
	adds r2, r0, 0
	movs r3, 0
	b _080091DE
_080091D4:
	cmp r1, 0xF9
	bne _080091DA
	adds r2, 0x1
_080091DA:
	adds r2, 0x1
	adds r3, 0x1
_080091DE:
	ldrb r1, [r2]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _080091D4
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end GetStringLength_Multibyte

	thumb_func_start WriteColorChangeControlCode
@ u8 *WriteColorChangeControlCode(u8 *dest, u8 colorType, u8 color)
WriteColorChangeControlCode: @ 80091EC
	push {lr}
	adds r3, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	cmp r1, 0x1
	beq _0800920E
	cmp r1, 0x1
	bcc _08009208
	cmp r1, 0x2
	beq _08009214
	b _08009218
_08009208:
	movs r0, 0x1
	strb r0, [r3]
	b _08009216
_0800920E:
	movs r0, 0x3
	strb r0, [r3]
	b _08009216
_08009214:
	strb r1, [r3]
_08009216:
	adds r3, 0x1
_08009218:
	strb r2, [r3]
	adds r3, 0x1
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end WriteColorChangeControlCode

	thumb_func_start sub_8009228
@ bool8 sub_8009228(u8 *s)
sub_8009228: @ 8009228
	push {lr}
	adds r2, r0, 0
	b _0800923E
_0800922E:
	adds r0, r1, 0
	cmp r0, 0xA0
	bhi _0800923C
	cmp r0, 0
	beq _0800923C
	movs r0, 0x1
	b _08009248
_0800923C:
	adds r2, 0x1
_0800923E:
	ldrb r1, [r2]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0800922E
	movs r0, 0
_08009248:
	pop {r1}
	bx r1
	thumb_func_end sub_8009228

	thumb_func_start sub_800924C
@ bool8 sub_800924C(u8 *s, u32 n)
sub_800924C: @ 800924C
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r1, 0
	b _08009268
_08009256:
	adds r0, r2, 0
	cmp r0, 0xA0
	bhi _08009264
	cmp r0, 0
	beq _08009264
	movs r0, 0x1
	b _08009276
_08009264:
	adds r3, 0x1
	adds r1, 0x1
_08009268:
	ldrb r2, [r3]
	adds r0, r2, 0
	cmp r0, 0xFF
	beq _08009274
	cmp r1, r4
	blt _08009256
_08009274:
	movs r0, 0
_08009276:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800924C

	thumb_func_start GetExtendedControlCodeLength
@ u8 GetExtendedControlCodeLength(u8 code)
GetExtendedControlCodeLength: @ 800927C
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0
	cmp r1, 0x18
	bhi _0800928E
	ldr r0, =gExtendedControlCodeLengths
	adds r0, r1, r0
	ldrb r0, [r0]
_0800928E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetExtendedControlCodeLength

	thumb_func_start SkipExtendedControlCode
@ u8 *SkipExtendedControlCode(u8 *s)
SkipExtendedControlCode: @ 8009298
	push {r4,lr}
	adds r4, r0, 0
	b _080092AC
_0800929E:
	adds r4, 0x1
	ldrb r0, [r4]
	bl GetExtendedControlCodeLength
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
_080092AC:
	ldrb r0, [r4]
	cmp r0, 0xFC
	beq _0800929E
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end SkipExtendedControlCode

	thumb_func_start CompareStringWithoutExtendedControlCodes
@ u8 CompareStringWithoutExtendedControlCodes(u8 *s1, u8 *s2)
CompareStringWithoutExtendedControlCodes: @ 80092BC
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r6, 0
	b _080092DE
_080092C6:
	cmp r1, r0
	bcs _080092D4
	movs r6, 0x1
	negs r6, r6
	cmp r0, 0xFF
	bne _080092D4
	movs r6, 0x1
_080092D4:
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _080092FE
	adds r4, 0x1
	adds r5, 0x1
_080092DE:
	adds r0, r4, 0
	bl SkipExtendedControlCode
	adds r4, r0, 0
	adds r0, r5, 0
	bl SkipExtendedControlCode
	adds r5, r0, 0
	ldrb r1, [r4]
	ldrb r0, [r5]
	cmp r1, r0
	bls _080092C6
	movs r6, 0x1
	cmp r1, 0xFF
	bne _080092FE
	subs r6, 0x2
_080092FE:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CompareStringWithoutExtendedControlCodes

	thumb_func_start StopMusicWhileStringIsPrinted
@ void StopMusicWhileStringIsPrinted(u8 *s, bool8 stopMusic)
StopMusicWhileStringIsPrinted: @ 8009308
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	bne _08009368
	bl StripExtendedControlCodes
	adds r0, r4, 0
	bl GetStringLength
	lsls r0, 24
	lsrs r2, r0, 24
	adds r1, r2, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	adds r1, r4, r1
	movs r0, 0xFC
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r4, r3
	movs r0, 0x16
	strb r0, [r3]
	adds r0, r2, 0x1
	lsls r0, 24
	adds r2, r4, r2
	movs r1, 0xFF
	strb r1, [r2]
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	b _0800935A
_08009350:
	adds r1, r2, r4
	ldrb r0, [r1]
	strb r0, [r1, 0x2]
	subs r0, r2, 0x1
	lsls r0, 24
_0800935A:
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _08009350
	movs r0, 0xFC
	strb r0, [r4]
	movs r0, 0x15
	strb r0, [r4, 0x1]
_08009368:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end StopMusicWhileStringIsPrinted

	thumb_func_start StripExtendedControlCodes
@ void StripExtendedControlCodes(u8 *s)
StripExtendedControlCodes: @ 8009370
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	movs r6, 0
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _080093C0
_0800937E:
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, 0xFC
	bne _080093A0
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r5, r4
	ldrb r0, [r0]
	bl GetExtendedControlCodeLength
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	b _080093B8
_080093A0:
	adds r2, r6, 0
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	adds r2, r5, r2
	adds r1, r4, 0
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r1, r5, r1
	ldrb r0, [r1]
	strb r0, [r2]
_080093B8:
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0800937E
_080093C0:
	adds r1, r5, r6
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end StripExtendedControlCodes

	.align 2, 0 @ Don't pad with nop.
