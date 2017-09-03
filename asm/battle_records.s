	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_813BF94
sub_813BF94: @ 813BF94
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r2, =0x01000008
	mov r0, sp
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0xFF
	strb r0, [r4]
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BF94

	thumb_func_start sub_813BFC4
sub_813BFC4: @ 813BFC4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x4
_0813BFCA:
	adds r0, r4, 0
	bl sub_813BF94
	adds r4, 0x10
	subs r5, 0x1
	cmp r5, 0
	bge _0813BFCA
	movs r0, 0x17
	movs r1, 0
	bl sav12_xor_set
	movs r0, 0x18
	movs r1, 0
	bl sav12_xor_set
	movs r0, 0x19
	movs r1, 0
	bl sav12_xor_set
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_813BFC4

	thumb_func_start sub_813BFF8
sub_813BFF8: @ 813BFF8
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	ldrh r2, [r1, 0xC]
	adds r0, r2
	ldrh r1, [r1, 0xE]
	adds r0, r1
	bx lr
	thumb_func_end sub_813BFF8

	thumb_func_start sub_813C008
sub_813C008: @ 813C008
	push {r4-r7,lr}
	adds r7, r1, 0
	lsls r2, 16
	lsrs r6, r2, 16
	movs r5, 0
	adds r4, r0, 0
_0813C014:
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x7
	bl StringCompareN
	cmp r0, 0
	bne _0813C02C
	ldrh r0, [r4, 0x8]
	cmp r0, r6
	bne _0813C02C
	adds r0, r5, 0
	b _0813C036
_0813C02C:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x4
	ble _0813C014
	movs r0, 0x5
_0813C036:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813C008

	thumb_func_start sub_813C03C
sub_813C03C: @ 813C03C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	movs r1, 0x4
_0813C04C:
	subs r3, r1, 0x1
	adds r6, r3, 0
	cmp r3, 0
	blt _0813C0BA
	lsls r0, r1, 4
	add r0, r10
	str r0, [sp, 0x14]
	lsls r0, r3, 4
	mov r2, r10
	adds r5, r0, r2
	movs r4, 0x50
	add r4, r10
	mov r9, r4
	add r1, r9
	mov r8, r1
_0813C06A:
	ldr r0, [sp, 0x14]
	str r3, [sp, 0x10]
	bl sub_813BFF8
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_813BFF8
	ldr r3, [sp, 0x10]
	cmp r4, r0
	ble _0813C0B2
	mov r1, sp
	ldr r0, [sp, 0x14]
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, [sp, 0x14]
	adds r0, r5, 0
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldr r0, [r0]
	str r0, [r1]
	adds r1, r5, 0
	mov r0, sp
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldr r0, [r0]
	str r0, [r1]
	mov r7, r8
	ldrb r2, [r7]
	mov r0, r9
	adds r1, r0, r6
	ldrb r0, [r1]
	strb r0, [r7]
	strb r2, [r1]
_0813C0B2:
	subs r5, 0x10
	subs r6, 0x1
	cmp r6, 0
	bge _0813C06A
_0813C0BA:
	adds r1, r3, 0
	cmp r1, 0
	bgt _0813C04C
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_813C03C

	thumb_func_start sub_813C0D0
sub_813C0D0: @ 813C0D0
	push {lr}
	adds r2, r0, 0
	cmp r1, 0x2
	beq _0813C100
	cmp r1, 0x2
	bgt _0813C0E2
	cmp r1, 0x1
	beq _0813C0E8
	b _0813C12A
_0813C0E2:
	cmp r1, 0x3
	beq _0813C118
	b _0813C12A
_0813C0E8:
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0813C12A
	strh r1, [r2, 0xA]
	b _0813C12A
	.pool
_0813C100:
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0813C12A
	strh r1, [r2, 0xC]
	b _0813C12A
	.pool
_0813C118:
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0813C12A
	strh r1, [r2, 0xE]
_0813C12A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C0D0

	thumb_func_start sub_813C134
sub_813C134: @ 813C134
	push {r4,lr}
	cmp r0, 0x2
	beq _0813C14E
	cmp r0, 0x2
	bgt _0813C144
	cmp r0, 0x1
	beq _0813C14A
	b _0813C166
_0813C144:
	cmp r0, 0x3
	beq _0813C152
	b _0813C166
_0813C14A:
	movs r4, 0x17
	b _0813C154
_0813C14E:
	movs r4, 0x18
	b _0813C154
_0813C152:
	movs r4, 0x19
_0813C154:
	adds r0, r4, 0
	bl GetGameStat
	ldr r1, =0x0000270e
	cmp r0, r1
	bhi _0813C166
	adds r0, r4, 0
	bl IncrementGameStat
_0813C166:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C134

	thumb_func_start sub_813C170
sub_813C170: @ 813C170
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	mov r10, r3
	ldr r0, [sp, 0x20]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r10
	bl sub_813C134
	adds r0, r6, 0
	bl sub_813C03C
	adds r0, r6, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_813C008
	adds r5, r0, 0
	cmp r5, 0x5
	bne _0813C1D4
	movs r5, 0x4
	adds r4, r6, 0
	adds r4, 0x40
	adds r0, r4, 0
	bl sub_813BF94
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0x7
	bl StringCopyN
	strh r7, [r4, 0x8]
	adds r2, r6, 0
	adds r2, 0x54
	ldr r1, =gUnknown_020229E8
	mov r3, r9
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x1A]
	strb r0, [r2]
_0813C1D4:
	lsls r0, r5, 4
	adds r0, r6, r0
	mov r1, r10
	bl sub_813C0D0
	adds r0, r6, 0
	bl sub_813C03C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C170

	thumb_func_start sub_813C1F8
sub_813C1F8: @ 813C1F8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003150
	adds r0, r1
	bl sub_813BFC4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C1F8

	thumb_func_start sub_813C214
sub_813C214: @ 813C214
	push {lr}
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gUnknown_02039B6C
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =0x0000270f
	cmp r0, r2
	bls _0813C230
	strh r2, [r1]
_0813C230:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C214

	thumb_func_start sub_813C23C
sub_813C23C: @ 813C23C
	push {lr}
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gUnknown_02039B6E
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =0x0000270f
	cmp r0, r2
	bls _0813C258
	strh r2, [r1]
_0813C258:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C23C

	thumb_func_start sub_813C264
sub_813C264: @ 813C264
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0813C27C
	cmp r0, 0x2
	beq _0813C28A
	b _0813C298
	.pool
_0813C27C:
	eors r0, r4
	bl sub_813C214
	adds r0, r4, 0
	bl sub_813C23C
	b _0813C298
_0813C28A:
	movs r0, 0x1
	eors r0, r4
	bl sub_813C23C
	adds r0, r4, 0
	bl sub_813C214
_0813C298:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_813C264

	thumb_func_start sub_813C2A0
sub_813C2A0: @ 813C2A0
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl InUnionRoom
	cmp r0, 0x1
	beq _0813C2DA
	adds r0, r4, 0
	bl sub_813C264
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003150
	adds r0, r1
	movs r1, 0x64
	adds r3, r4, 0
	muls r3, r1
	ldr r2, =gUnknown_02039B88
	adds r1, r3, r2
	subs r2, 0x30
	adds r3, r2
	ldrh r2, [r3, 0xE]
	ldr r3, =gBattleOutcome
	ldrb r3, [r3]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	bl sub_813C170
_0813C2DA:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C2A0

	thumb_func_start sub_813C2F4
sub_813C2F4: @ 813C2F4
	push {r4,lr}
	sub sp, 0xC
	ldr r4, =gStringVar1
	movs r0, 0x17
	bl GetGameStat
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	movs r0, 0x18
	bl GetGameStat
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar3
	movs r0, 0x19
	bl GetGameStat
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF6A1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldr r0, =gUnknown_0203AB74
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x11
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	bl Print
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C2F4

	thumb_func_start sub_813C384
sub_813C384: @ 813C384
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r6, r0, 0
	adds r5, r2, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldrh r0, [r6, 0xA]
	cmp r0, 0
	bne _0813C40C
	ldr r7, [r6, 0xC]
	cmp r7, 0
	bne _0813C40C
	ldr r0, =gUnknown_0203AB74
	mov r8, r0
	ldrb r0, [r0]
	ldr r2, =gUnknown_085B3D84
	lsls r4, 3
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	str r7, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	mov r1, r8
	ldrb r0, [r1]
	ldr r5, =gUnknown_085B3D8C
	str r4, [sp]
	str r7, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x50
	bl Print
	mov r1, r8
	ldrb r0, [r1]
	str r4, [sp]
	str r7, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x80
	bl Print
	mov r1, r8
	ldrb r0, [r1]
	str r4, [sp]
	str r7, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0xB0
	bl Print
	b _0813C4A8
	.pool
_0813C40C:
	ldr r0, =gStringVar1
	movs r1, 0x8
	bl StringFillWithTerminator
	ldr r0, =gStringVar1
	adds r1, r6, 0
	movs r2, 0x7
	bl StringCopyN
	lsls r1, r5, 24
	lsrs r1, 24
	ldr r0, =gStringVar1
	bl ConvertInternationalString
	ldr r0, =gUnknown_0203AB74
	mov r8, r0
	ldrb r0, [r0]
	lsls r4, 3
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar1
	movs r3, 0x8
	bl Print
	ldrh r1, [r6, 0xA]
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	mov r1, r8
	ldrb r0, [r1]
	str r4, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar1
	movs r3, 0x50
	bl Print
	ldrh r1, [r6, 0xC]
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	mov r1, r8
	ldrb r0, [r1]
	str r4, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar1
	movs r3, 0x80
	bl Print
	ldrh r1, [r6, 0xE]
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	mov r1, r8
	ldrb r0, [r1]
	str r4, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar1
	movs r3, 0xB0
	bl Print
_0813C4A8:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C384

	thumb_func_start sub_813C4BC
sub_813C4BC: @ 813C4BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r6, =gUnknown_0203AB74
	ldr r0, =gUnknown_085B3D7C
	bl AddWindow
	strb r0, [r6]
	ldrb r0, [r6]
	movs r1, 0
	bl sub_81973FC
	ldrb r0, [r6]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gStringVar4
	ldr r1, =gUnknown_085EF68D
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldrb r0, [r6]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r2, r5, 0
	bl Print
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r0, [r0]
	ldr r1, =0x00003150
	mov r9, r1
	add r0, r9
	bl sub_813C2F4
	ldr r1, =gUnknown_085EF6BD
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldrb r0, [r6]
	movs r1, 0x29
	str r1, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0
	bl Print
	mov r7, r8
	movs r6, 0xE0
	lsls r6, 19
	mov r5, r9
_0813C540:
	ldr r2, [r7]
	adds r0, r2, r5
	lsrs r1, r6, 24
	ldr r3, =0x000031a0
	adds r2, r3
	adds r2, r4
	ldrb r2, [r2]
	bl sub_813C384
	movs r0, 0x80
	lsls r0, 18
	adds r6, r0
	adds r5, 0x10
	adds r4, 0x1
	cmp r4, 0x4
	ble _0813C540
	ldr r4, =gUnknown_0203AB74
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C4BC

	thumb_func_start sub_813C5A0
sub_813C5A0: @ 813C5A0
	push {r4,lr}
	ldr r4, =gUnknown_0203AB74
	ldrb r0, [r4]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C5A0

	.align 2, 0 @ Don't pad with nop.
