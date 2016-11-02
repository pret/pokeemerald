	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	.text

	thumb_func_start CgbSound
CgbSound: @ 81DEA70
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =SOUND_INFO_PTR
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _081DEA94
	subs r0, 0x1
	ldr r1, [sp, 0x4]
	strb r0, [r1, 0xA]
	b _081DEA9A
	.pool
_081DEA94:
	movs r0, 0xE
	ldr r2, [sp, 0x4]
	strb r0, [r2, 0xA]
_081DEA9A:
	movs r6, 0x1
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
_081DEAA0:
	ldrb r1, [r4]
	movs r0, 0xC7
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	bne _081DEAB6
	b _081DEEA0
_081DEAB6:
	cmp r6, 0x2
	beq _081DEAE8
	cmp r6, 0x2
	bgt _081DEAC4
	cmp r6, 0x1
	beq _081DEACA
	b _081DEB20
_081DEAC4:
	cmp r6, 0x3
	beq _081DEB00
	b _081DEB20
_081DEACA:
	ldr r0, =REG_NR10
	str r0, [sp, 0x8]
	ldr r7, =REG_NR11
	ldr r2, =REG_NR12
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _081DEB30
	.pool
_081DEAE8:
	ldr r0, =REG_NR10 + 1
	str r0, [sp, 0x8]
	ldr r7, =REG_NR21
	ldr r2, =REG_NR22
	b _081DEB28
	.pool
_081DEB00:
	ldr r0, =REG_NR30
	str r0, [sp, 0x8]
	ldr r7, =REG_NR31
	ldr r2, =REG_NR32
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _081DEB30
	.pool
_081DEB20:
	ldr r0, =REG_NR30 + 1
	str r0, [sp, 0x8]
	ldr r7, =REG_NR41
	ldr r2, =REG_NR42
_081DEB28:
	str r2, [sp, 0xC]
	adds r0, 0xB
	str r0, [sp, 0x10]
	adds r2, 0x4
_081DEB30:
	str r2, [sp, 0x14]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	str r0, [sp]
	ldr r2, [sp, 0xC]
	ldrb r0, [r2]
	mov r8, r0
	adds r2, r1, 0
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _081DEC26
	movs r3, 0x40
	adds r0, r3, 0
	ands r0, r2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0x1
	mov r10, r0
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r5, 0
	bne _081DEC4A
	movs r0, 0x3
	strb r0, [r4]
	strb r0, [r4, 0x1D]
	adds r0, r4, 0
	str r3, [sp, 0x18]
	bl CgbModVol
	ldr r3, [sp, 0x18]
	cmp r6, 0x2
	beq _081DEB98
	cmp r6, 0x2
	bgt _081DEB8C
	cmp r6, 0x1
	beq _081DEB92
	b _081DEBEC
	.pool
_081DEB8C:
	cmp r6, 0x3
	beq _081DEBA4
	b _081DEBEC
_081DEB92:
	ldrb r0, [r4, 0x1F]
	ldr r2, [sp, 0x8]
	strb r0, [r2]
_081DEB98:
	ldr r0, [r4, 0x24]
	lsls r0, 6
	ldrb r1, [r4, 0x1E]
	adds r0, r1, r0
	strb r0, [r7]
	b _081DEBF8
_081DEBA4:
	ldr r1, [r4, 0x24]
	ldr r0, [r4, 0x28]
	cmp r1, r0
	beq _081DEBCC
	ldr r2, [sp, 0x8]
	strb r3, [r2]
	ldr r1, =REG_WAVE_RAM
	ldr r2, [r4, 0x24]
	ldr r0, [r2]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x8]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0xC]
	str r0, [r1]
	str r2, [r4, 0x28]
_081DEBCC:
	ldr r0, [sp, 0x8]
	strb r5, [r0]
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _081DEBE4
	movs r0, 0xC0
	b _081DEC06
	.pool
_081DEBE4:
	movs r1, 0x80
	negs r1, r1
	strb r1, [r4, 0x1A]
	b _081DEC08
_081DEBEC:
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldr r0, [r4, 0x24]
	lsls r0, 3
	ldr r2, [sp, 0x10]
	strb r0, [r2]
_081DEBF8:
	ldrb r0, [r4, 0x4]
	adds r0, 0x8
	mov r8, r0
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _081DEC06
	movs r0, 0x40
_081DEC06:
	strb r0, [r4, 0x1A]
_081DEC08:
	ldrb r1, [r4, 0x4]
	movs r2, 0
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	adds r1, r6, 0x1
	mov r10, r1
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r0, 0
	bne _081DEC22
	b _081DED5E
_081DEC22:
	strb r2, [r4, 0x9]
	b _081DED8C
_081DEC26:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _081DEC58
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	strb r0, [r4, 0xD]
	movs r2, 0xFF
	ands r0, r2
	lsls r0, 24
	adds r1, r6, 0x1
	mov r10, r1
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	ble _081DEC4A
	b _081DED9E
_081DEC4A:
	lsls r0, r6, 24
	lsrs r0, 24
	bl CgbOscOff
	movs r0, 0
	strb r0, [r4]
	b _081DEE9C
_081DEC58:
	movs r0, 0x40
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	beq _081DEC98
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081DEC98
	movs r0, 0xFC
	ands r0, r1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x7]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _081DECCA
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _081DED8C
	ldrb r2, [r4, 0x7]
	mov r8, r2
	b _081DED8C
_081DEC98:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _081DED8C
	cmp r6, 0x3
	bne _081DECAA
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
_081DECAA:
	adds r0, r4, 0
	bl CgbModVol
	movs r0, 0x3
	ldrb r2, [r4]
	ands r0, r2
	cmp r0, 0
	bne _081DECFE
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	cmp r0, 0
	bgt _081DECFA
_081DECCA:
	ldrb r2, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	muls r0, r1
	adds r0, 0xFF
	asrs r0, 8
	movs r1, 0
	strb r0, [r4, 0x9]
	lsls r0, 24
	cmp r0, 0
	beq _081DEC4A
	movs r0, 0x4
	ldrb r2, [r4]
	orrs r0, r2
	strb r0, [r4]
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _081DED9E
	movs r2, 0x8
	mov r8, r2
	b _081DED9E
_081DECFA:
	ldrb r0, [r4, 0x7]
	b _081DED8A
_081DECFE:
	cmp r0, 0x1
	bne _081DED0A
_081DED02:
	ldrb r0, [r4, 0x19]
	strb r0, [r4, 0x9]
	movs r0, 0x7
	b _081DED8A
_081DED0A:
	cmp r0, 0x2
	bne _081DED4E
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	ldrb r2, [r4, 0x19]
	lsls r1, r2, 24
	cmp r0, r1
	bgt _081DED4A
_081DED22:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _081DED32
	movs r0, 0xFC
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	b _081DECCA
_081DED32:
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	orrs r0, r2
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _081DED02
	movs r0, 0x8
	mov r8, r0
	b _081DED02
_081DED4A:
	ldrb r0, [r4, 0x5]
	b _081DED8A
_081DED4E:
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	ldrb r2, [r4, 0xA]
	cmp r0, r2
	bcc _081DED88
_081DED5E:
	ldrb r0, [r4]
	subs r0, 0x1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x5]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _081DED22
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	cmp r6, 0x3
	beq _081DED8C
	ldrb r2, [r4, 0x5]
	mov r8, r2
	b _081DED8C
_081DED88:
	ldrb r0, [r4, 0x4]
_081DED8A:
	strb r0, [r4, 0xB]
_081DED8C:
	ldrb r0, [r4, 0xB]
	subs r0, 0x1
	strb r0, [r4, 0xB]
	ldr r0, [sp]
	cmp r0, 0
	bne _081DED9E
	subs r0, 0x1
	str r0, [sp]
	b _081DEC98
_081DED9E:
	movs r0, 0x2
	ldrb r1, [r4, 0x1D]
	ands r0, r1
	cmp r0, 0
	beq _081DEE16
	cmp r6, 0x3
	bgt _081DEDDE
	movs r0, 0x8
	ldrb r2, [r4, 0x1]
	ands r0, r2
	cmp r0, 0
	beq _081DEDDE
	ldr r0, =REG_SOUNDBIAS + 1
	ldrb r0, [r0]
	cmp r0, 0x3F
	bgt _081DEDD0
	ldr r0, [r4, 0x20]
	adds r0, 0x2
	ldr r1, =0x000007fc
	b _081DEDDA
	.pool
_081DEDD0:
	cmp r0, 0x7F
	bgt _081DEDDE
	ldr r0, [r4, 0x20]
	adds r0, 0x1
	ldr r1, =0x000007fe
_081DEDDA:
	ands r0, r1
	str r0, [r4, 0x20]
_081DEDDE:
	cmp r6, 0x4
	beq _081DEDF0
	ldr r0, [r4, 0x20]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	b _081DEDFE
	.pool
_081DEDF0:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2]
	movs r1, 0x8
	ands r1, r0
	ldr r0, [r4, 0x20]
	orrs r0, r1
	strb r0, [r2]
_081DEDFE:
	movs r0, 0xC0
	ldrb r1, [r4, 0x1A]
	ands r0, r1
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r4, 0x1A]
	movs r2, 0xFF
	ands r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_081DEE16:
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	ands r0, r2
	cmp r0, 0
	beq _081DEE9C
	ldr r1, =REG_NR51
	ldrb r0, [r1]
	ldrb r2, [r4, 0x1C]
	bics r0, r2
	ldrb r2, [r4, 0x1B]
	orrs r0, r2
	strb r0, [r1]
	cmp r6, 0x3
	bne _081DEE68
	ldr r0, =gCgb3Vol
	ldrb r1, [r4, 0x9]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, [sp, 0xC]
	strb r0, [r2]
	movs r1, 0x80
	adds r0, r1, 0
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	cmp r0, 0
	beq _081DEE9C
	ldr r0, [sp, 0x8]
	strb r1, [r0]
	ldrb r0, [r4, 0x1A]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	movs r0, 0x7F
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	strb r0, [r4, 0x1A]
	b _081DEE9C
	.pool
_081DEE68:
	movs r0, 0xF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrb r2, [r4, 0x9]
	lsls r0, r2, 4
	add r0, r8
	ldr r1, [sp, 0xC]
	strb r0, [r1]
	movs r2, 0x80
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	cmp r6, 0x1
	bne _081DEE9C
	ldr r0, [sp, 0x8]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _081DEE9C
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_081DEE9C:
	movs r0, 0
	strb r0, [r4, 0x1D]
_081DEEA0:
	mov r6, r10
	mov r4, r9
	cmp r6, 0x4
	bgt _081DEEAA
	b _081DEAA0
_081DEEAA:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CgbSound

	.align 2, 0 @ Don't pad with nop.
