	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start StringCopyN_Multibyte
@ u8 *CopyString_LimitN_Multibyte(u8 *dest, u8 *src, u32 n)
StringCopyN_Multibyte: @ 800918C
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
	thumb_func_end StringCopyN_Multibyte

	thumb_func_start StringLength_Multibyte
@ u32 GetStringLength_Multibyte(u8 *s)
StringLength_Multibyte: @ 80091CC
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
	thumb_func_end StringLength_Multibyte

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

	thumb_func_start GetExtCtrlCodeLength
@ u8 GetExtendedControlCodeLength(u8 code)
GetExtCtrlCodeLength: @ 800927C
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
	thumb_func_end GetExtCtrlCodeLength

	thumb_func_start SkipExtCtrlCode
@ u8 *SkipExtendedControlCode(u8 *s)
SkipExtCtrlCode: @ 8009298
	push {r4,lr}
	adds r4, r0, 0
	b _080092AC
_0800929E:
	adds r4, 0x1
	ldrb r0, [r4]
	bl GetExtCtrlCodeLength
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
	thumb_func_end SkipExtCtrlCode

	thumb_func_start StringCompareWithoutExtCtrlCodes
@ u8 CompareStringWithoutExtendedControlCodes(u8 *s1, u8 *s2)
StringCompareWithoutExtCtrlCodes: @ 80092BC
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
	bl SkipExtCtrlCode
	adds r4, r0, 0
	adds r0, r5, 0
	bl SkipExtCtrlCode
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
	thumb_func_end StringCompareWithoutExtCtrlCodes

	thumb_func_start ConvertInternationalString
@ void StopMusicWhileStringIsPrinted(u8 *s, bool8 stopMusic)
ConvertInternationalString: @ 8009308
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	bne _08009368
	bl StripExtCtrlCodes
	adds r0, r4, 0
	bl StringLength
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
	thumb_func_end ConvertInternationalString

	thumb_func_start StripExtCtrlCodes
@ void StripExtendedControlCodes(u8 *s)
StripExtCtrlCodes: @ 8009370
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
	bl GetExtCtrlCodeLength
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
	thumb_func_end StripExtCtrlCodes

	.align 2, 0 @ Don't pad with nop.
