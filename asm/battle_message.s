	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sub_814F8F8
sub_814F8F8: @ 814F8F8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r2, 0
	ldr r5, =gStringInfo
	ldr r3, =gUnknown_085CD336
_0814F902:
	cmp r2, 0x4
	beq _0814F918
	ldrh r1, [r3]
	cmp r1, 0
	bne _0814F90E
	adds r2, 0x1
_0814F90E:
	ldr r0, [r5]
	adds r3, 0x2
	ldrh r0, [r0]
	cmp r1, r0
	bne _0814F902
_0814F918:
	cmp r2, 0
	blt _0814F944
	cmp r2, 0x2
	bgt _0814F938
	ldr r1, =gText_SpaceIs
	adds r0, r4, 0
	bl StringCopy
	b _0814F944
	.pool
_0814F938:
	cmp r2, 0x4
	bgt _0814F944
	ldr r1, =gText_ApostropheS
	adds r0, r4, 0
	bl StringCopy
_0814F944:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814F8F8

	thumb_func_start sub_814F950
sub_814F950: @ 814F950
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	b _0814F95A
_0814F958:
	adds r3, 0x1
_0814F95A:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _0814F958
	ldr r1, =gUnknown_085CD336
	ldr r5, =gStringInfo
	movs r0, 0
	lsls r0, 1
	adds r2, r0, r1
_0814F96A:
	cmp r4, 0x4
	beq _0814F984
	ldrh r1, [r2]
	cmp r1, 0
	bne _0814F976
	adds r4, 0x1
_0814F976:
	ldr r0, [r5]
	adds r2, 0x2
	ldrh r0, [r0]
	cmp r1, r0
	bne _0814F96A
	cmp r4, 0x4
	bhi _0814F9E0
_0814F984:
	lsls r0, r4, 2
	ldr r1, =_0814F99C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814F99C:
	.4byte _0814F9B0
	.4byte _0814F9B8
	.4byte _0814F9C0
	.4byte _0814F9C8
	.4byte _0814F9D8
_0814F9B0:
	ldr r1, =gText_ExclamationMark
	b _0814F9CA
	.pool
_0814F9B8:
	ldr r1, =gText_ExclamationMark2
	b _0814F9CA
	.pool
_0814F9C0:
	ldr r1, =gText_ExclamationMark3
	b _0814F9CA
	.pool
_0814F9C8:
	ldr r1, =gText_ExclamationMark4
_0814F9CA:
	adds r0, r3, 0
	bl StringCopy
	b _0814F9E0
	.pool
_0814F9D8:
	ldr r1, =gText_ExclamationMark5
	adds r0, r3, 0
	bl StringCopy
_0814F9E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814F950

	thumb_func_start sub_814F9EC
sub_814F9EC: @ 814F9EC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r1, =gUnknown_085CD660
	ldr r0, =gBattleScripting
	adds r0, 0x24
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r0, 0x80
	ands r0, r7
	cmp r0, 0
	beq _0814FA24
	movs r0, 0x7F
	ands r7, r0
	movs r0, 0
	b _0814FA36
	.pool
_0814FA24:
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	add r0, r8
	ldrb r1, [r0]
	adds r0, r7, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
_0814FA36:
	mov r9, r0
	str r4, [sp]
	mov r0, sp
	strb r7, [r0, 0x4]
	mov r1, sp
	lsls r6, r7, 1
	adds r3, r6, r7
	lsls r3, 2
	add r3, r8
	ldrb r0, [r3, 0x1]
	strb r0, [r1, 0x5]
	ldrb r0, [r3, 0x2]
	strb r0, [r1, 0x6]
	ldrb r0, [r3, 0x3]
	strb r0, [r1, 0x7]
	mov r0, sp
	ldrb r0, [r0, 0x6]
	strb r0, [r1, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	ldrb r0, [r3, 0x4]
	strb r0, [r1, 0xA]
	ldrb r0, [r3, 0x5]
	strb r0, [r1, 0xB]
	mov r4, sp
	ldrb r2, [r4, 0xC]
	movs r1, 0x10
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4, 0xC]
	mov r2, sp
	ldrb r0, [r3, 0x7]
	lsls r0, 4
	movs r5, 0xF
	strb r0, [r2, 0xC]
	ldrb r2, [r3, 0x8]
	adds r0, r5, 0
	ands r0, r2
	ldrb r2, [r4, 0xD]
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xD]
	mov r2, sp
	ldrb r0, [r3, 0x9]
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strb r1, [r2, 0xD]
	mov r0, sp
	ldrb r0, [r0, 0x6]
	cmp r0, 0xFF
	bne _0814FAC6
	ldr r0, =gBattleScripting
	adds r0, 0x24
	ldrb r0, [r0]
	adds r1, r7, 0
	bl sub_80397C4
	adds r2, r0, 0
	mov r0, sp
	ldrb r0, [r0, 0x5]
	ldr r1, [sp]
	mov r3, sp
	ldrb r3, [r3, 0xA]
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	mov r2, sp
	mov r1, sp
	strb r0, [r1, 0x8]
	strb r0, [r2, 0x6]
_0814FAC6:
	cmp r7, 0x16
	bne _0814FAE0
	ldr r0, =gTextFlags
	ldrb r2, [r0]
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	b _0814FAE8
	.pool
_0814FAE0:
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
_0814FAE8:
	strb r1, [r0]
	adds r3, r0, 0
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r2, =0x01000002
	ands r1, r2
	adds r2, r0, 0
	cmp r1, 0
	beq _0814FB10
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	b _0814FB18
	.pool
_0814FB10:
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
_0814FB18:
	strb r0, [r3]
	cmp r7, 0
	beq _0814FB22
	cmp r7, 0x16
	bne _0814FB6C
_0814FB22:
	ldr r1, [r2]
	ldr r0, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0814FB34
	movs r6, 0x1
	b _0814FB5C
	.pool
_0814FB34:
	movs r0, 0x80
	lsls r0, 17
	ands r1, r0
	cmp r1, 0
	beq _0814FB54
	ldr r4, =gUnknown_085CD668
	bl sub_8185FC4
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r6, [r0]
	b _0814FB5C
	.pool
_0814FB54:
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r6, r0, 24
_0814FB5C:
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _0814FB7E
	.pool
_0814FB6C:
	adds r0, r6, r7
	lsls r0, 2
	add r0, r8
	ldrb r6, [r0, 0x6]
	ldrb r1, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_0814FB7E:
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0
	bl AddTextPrinter
	mov r0, r9
	cmp r0, 0
	beq _0814FB9C
	adds r0, r7, 0
	bl PutWindowTilemap
	adds r0, r7, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0814FB9C:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_814F9EC

	thumb_func_start sub_814FBAC
sub_814FBAC: @ 814FBAC
	push {r4,r5,lr}
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r1, r2, 9
	ldr r0, =gBattleBufferA + 4
	adds r1, r0
	ldr r4, =gUnknown_08D85620
	ldr r0, =gMoveSelectionCursor
	adds r2, r0
	ldrb r2, [r2]
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r2
	ldrb r0, [r0]
	adds r1, 0xC
	adds r1, r2
	ldrb r1, [r1]
	bl sub_814FC20
	lsls r0, 24
	ldr r5, =gPlttBufferUnfaded
	lsrs r0, 22
	adds r0, r4
	ldrh r1, [r0]
	adds r2, r5, 0
	adds r2, 0xB8
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	adds r5, 0xB6
	strh r0, [r5]
	ldr r4, =gPlttBufferFaded + 0xB8
	adds r0, r2, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl CpuSet
	subs r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl CpuSet
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814FBAC

	thumb_func_start sub_814FC20
sub_814FC20: @ 814FC20
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, r2
	beq _0814FC68
	cmp r0, 0x2
	bhi _0814FC3A
	cmp r2, 0x1
	bhi _0814FC68
	b _0814FC42
_0814FC3A:
	cmp r0, 0x7
	bhi _0814FC4C
	cmp r2, 0x2
	bhi _0814FC68
_0814FC42:
	movs r0, 0x2
	subs r0, r2
	lsls r0, 24
	lsrs r0, 24
	b _0814FC6A
_0814FC4C:
	cmp r2, 0
	bne _0814FC54
	movs r0, 0x2
	b _0814FC6A
_0814FC54:
	lsrs r0, r1, 26
	cmp r2, r0
	bhi _0814FC5E
	movs r0, 0x1
	b _0814FC6A
_0814FC5E:
	lsrs r0, r1, 25
	cmp r3, r0
	bhi _0814FC68
	movs r0, 0
	b _0814FC6A
_0814FC68:
	movs r0, 0x3
_0814FC6A:
	pop {r1}
	bx r1
	thumb_func_end sub_814FC20

	.align 2, 0 @ Don't pad with nop.
