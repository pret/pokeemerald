	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start sub_80296A8
sub_80296A8: @ 80296A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x6C
	lsls r0, 24
	movs r1, 0
	mov r8, r1
	movs r6, 0
	lsrs r7, r0, 24
	add r4, sp, 0x2C
	ldr r1, =gUnknown_082FB45C
	adds r0, r4, 0
	movs r2, 0x5
	bl memcpy
	movs r5, 0
	cmp r5, r7
	bcs _080296F8
	add r4, sp, 0x34
_080296D2:
	mov r0, sp
	adds r0, r5
	adds r0, 0x2C
	strb r5, [r0]
	add r0, sp, 0x5C
	adds r1, r5, 0
	bl sub_802793C
	lsls r2, r5, 3
	adds r2, r4, r2
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x60]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _080296D2
_080296F8:
	bl sub_8027748
	cmp r0, 0
	beq _0802972E
_08029700:
	movs r5, 0
	cmp r5, r7
	bcs _08029728
	add r2, sp, 0x34
	add r1, sp, 0x2C
_0802970A:
	lsls r0, r5, 3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r8
	bne _0802971E
	adds r0, r1, r6
	strb r5, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0802971E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0802970A
_08029728:
	mov r8, r6
	cmp r6, r7
	bcc _08029700
_0802972E:
	movs r5, 0
	ldr r4, =gText_SpacePoints
	cmp r5, r7
	bcs _08029754
	add r1, sp, 0x34
	add r6, sp, 0x38
	subs r3, r7, 0x1
_0802973C:
	lsls r2, r5, 3
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0802974A
	adds r0, r1, r2
	strb r3, [r0]
_0802974A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0802973C
_08029754:
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	movs r1, 0xD8
	subs r1, r0
	str r1, [sp, 0x64]
	movs r5, 0
	cmp r5, r7
	bcs _08029860
	mov r2, sp
	adds r2, 0x34
	str r2, [sp, 0x68]
	ldr r3, =0x00003009
	mov r10, r3
_08029774:
	movs r0, 0
	mov r8, r0
	mov r0, sp
	adds r0, r5
	adds r0, 0x2C
	ldrb r0, [r0]
	adds r4, r0, 0
	lsls r1, r4, 3
	add r0, sp, 0x38
	adds r0, r1
	ldr r0, [r0]
	mov r9, r0
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gUnknown_082FB3DC
	ldr r3, [sp, 0x68]
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r3, =gUnknown_082FB402
	lsls r1, r5, 1
	adds r1, r3
	ldrb r6, [r1]
	str r6, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	mov r3, r8
	str r3, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080297CC
	movs r0, 0x2
	mov r8, r0
_080297CC:
	adds r0, r4, 0
	bl sub_8027660
	adds r3, r0, 0
	ldr r1, =gUnknown_02022CF8
	ldr r0, [r1]
	add r0, r10
	ldrb r0, [r0]
	mov r2, r8
	lsls r1, r2, 1
	add r1, r8
	ldr r2, =gUnknown_082FB380
	adds r1, r2
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0x1C
	adds r3, r6, 0
	bl AddTextPrinterParameterized3
	add r0, sp, 0xC
	mov r1, r9
	movs r2, 0
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r3, r0, 0
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r1, [sp, 0x64]
	subs r3, r1, r3
	lsls r3, 24
	lsrs r3, 24
	str r6, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r1, [sp, 0x64]
	lsls r3, r1, 24
	str r6, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gText_SpacePoints
	lsrs r3, 24
	bl AddTextPrinterParameterized
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _08029774
_08029860:
	add sp, 0x6C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80296A8

	thumb_func_start sub_802988C
sub_802988C: @ 802988C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	bl sub_8027650
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	ldr r6, =gUnknown_02022CF8
	ldr r1, [r6]
	ldr r2, =0x00003014
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xB
	bls _080298B2
	b _08029FA8
_080298B2:
	lsls r0, 2
	ldr r1, =_080298C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080298C8:
	.4byte _080298F8
	.4byte _08029914
	.4byte _0802996C
	.4byte _08029B6C
	.4byte _08029BB8
	.4byte _08029BFC
	.4byte _08029C60
	.4byte _08029C9C
	.4byte _08029CE0
	.4byte _08029DA0
	.4byte _08029F08
	.4byte _08029F5C
_080298F8:
	bl sub_802784C
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x0000301c
	adds r2, r1, r0
	movs r0, 0
	strh r0, [r2]
	b _08029F8A
	.pool
_08029914:
	ldr r6, =gUnknown_082F7BBC
	adds r0, r6, 0
	bl AddWindow
	ldr r4, =gUnknown_02022CF8
	ldr r1, [r4]
	ldr r2, =0x00003008
	mov r8, r2
	add r1, r8
	strb r0, [r1]
	movs r0, 0x8
	adds r0, r6
	mov r9, r0
	bl AddWindow
	ldr r1, [r4]
	ldr r5, =0x00003009
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, 0
	bl sub_8029174
	mov r0, r9
	bl sub_8029174
	b _08029F88
	.pool
_0802996C:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r5, =0x00003008
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	mov r9, r1
	add r0, r9
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_BerryPickingResults
	mov r8, r2
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	mov r1, r8
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r6, 0xFF
	str r6, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	mov r2, r8
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	add r0, r9
	ldrb r0, [r0]
	ldr r2, =gText_10P30P50P50P
	movs r1, 0x11
	str r1, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x44
	bl AddTextPrinterParameterized
	mov r9, r5
	ldr r0, [sp, 0xC]
	cmp r9, r0
	bcc _080299E2
	b _08029B2A
_080299E2:
	movs r4, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r9, r0
	bne _080299F2
	movs r4, 0x2
_080299F2:
	mov r0, r9
	bl sub_8027660
	adds r6, r0, 0
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	mov r2, r9
	lsls r5, r2, 1
	ldr r2, =gUnknown_082FB3F8
	adds r1, r5, r2
	ldrb r3, [r1]
	lsls r1, r4, 1
	adds r1, r4
	ldr r2, =gUnknown_082FB380
	adds r1, r2
	str r1, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	movs r7, 0
	mov r8, r5
	mov r0, r9
	adds r0, 0x1
	str r0, [sp, 0x10]
	ldr r1, =gStringVar4
	mov r10, r1
_08029A36:
	mov r0, r9
	adds r1, r7, 0
	bl sub_80276A0
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	bl Min
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl sub_802778C
	ldr r1, =0x0000270f
	bl Min
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	mov r1, r10
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r5, r0, 0
	cmp r6, r4
	bne _08029AE0
	cmp r6, 0
	beq _08029AE0
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	lsls r1, r7, 1
	ldr r2, =gUnknown_082FB3F0
	adds r1, r2
	ldrb r2, [r1]
	subs r2, r5
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_082FB3F8
	add r1, r8
	ldrb r3, [r1]
	ldr r1, =gUnknown_082FB380 + 3
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	b _08029B10
	.pool
_08029AE0:
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	lsls r1, r7, 1
	ldr r2, =gUnknown_082FB3F0
	adds r1, r2
	ldrb r3, [r1]
	subs r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r1, =gUnknown_082FB3F8
	add r1, r8
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar4
	bl AddTextPrinterParameterized
_08029B10:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _08029A36
	ldr r1, [sp, 0x10]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r9, r0
	ldr r2, [sp, 0xC]
	cmp r9, r2
	bcs _08029B2A
	b _080299E2
_08029B2A:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029B6C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029B90
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029B90:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl sub_8028C30
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029BB8:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08029BD0
	b _08029FF8
_08029BD0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08029BDE
	b _08029FF8
_08029BDE:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl sub_8028C30
	b _08029F88
	.pool
_08029BFC:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r5, =0x00003008
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r6, =gText_AnnouncingRankings
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized
	b _08029F88
	.pool
_08029C60:
	ldr r0, [sp, 0xC]
	bl sub_80296A8
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029C9C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029CC0
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029CC0:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029CE0:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08029CF8
	b _08029FF8
_08029CF8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08029D06
	b _08029FF8
_08029D06:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
	bl sub_8027748
	ldr r1, =0x00000bb7
	cmp r0, r1
	bhi _08029D3C
	ldr r0, [r4]
	ldr r2, =0x00003014
	adds r0, r2
	movs r1, 0x7F
	strb r1, [r0]
	b _08029D4C
	.pool
_08029D3C:
	bl StopMapMusic
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08029D4C:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x5
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003009
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r6, =gUnknown_082F7BCC
	adds r0, r6, 0
	bl AddWindow
	ldr r1, [r5]
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, 0
	bl sub_8029174
	b _08029FF8
	.pool
_08029DA0:
	ldr r0, =0x0000016f
	bl PlayNewMapMusic
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r6, =0x00003008
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_AnnouncingPrizes
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r5, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0x1
	mov r9, r2
	str r2, [sp]
	movs r1, 0xFF
	mov r8, r1
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_802762C
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gStringVar1
	adds r1, r5, 0
	bl CopyItemName
	movs r0, 0
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r7, =gStringVar4
	ldr r1, =gText_FirstPlacePrize
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r4]
	add r0, r10
	ldrb r0, [r0]
	mov r2, r9
	str r2, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	bl sub_80279C8
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	cmp r4, 0
	beq _08029EC8
	cmp r4, 0x3
	beq _08029EC8
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_802762C
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl CopyItemName
	movs r0, 0
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r4, 0x2
	bne _08029E9C
	ldr r1, =gText_CantHoldAnyMore
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08029EA8
	.pool
_08029E9C:
	cmp r6, 0x1
	bne _08029EA8
	ldr r1, =gText_FilledStorageSpace
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
_08029EA8:
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	ldr r2, =gStringVar4
	movs r1, 0x29
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
_08029EC8:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029F08:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029F2C
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029F2C:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =0x0000020b
	movs r1, 0x14
	movs r2, 0xA
	bl FadeOutAndFadeInNewMapMusic
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029F5C:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bls _08029FF8
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08029FF8
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
_08029F88:
	ldr r1, [r4]
_08029F8A:
	ldr r2, =0x00003014
	adds r1, r2
_08029F8E:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08029FF8
	.pool
_08029FA8:
	ldr r5, =0x00003008
	adds r0, r1, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, =0x00003009
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_08029FF8:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802988C

	thumb_func_start sub_802A010
sub_802A010: @ 802A010
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r1, =gUnknown_02022CF8
	ldr r2, [r1]
	ldr r3, =0x00003014
	adds r0, r2, r3
	ldrb r6, [r0]
	adds r7, r1, 0
	cmp r6, 0x1
	beq _0802A0CC
	cmp r6, 0x1
	bgt _0802A040
	cmp r6, 0
	beq _0802A04E
	b _0802A2FC
	.pool
_0802A040:
	cmp r6, 0x2
	bne _0802A046
	b _0802A194
_0802A046:
	cmp r6, 0x3
	bne _0802A04C
	b _0802A1D0
_0802A04C:
	b _0802A2FC
_0802A04E:
	ldr r0, =gUnknown_082F7BD4
	mov r9, r0
	bl AddWindow
	ldr r1, [r7]
	ldr r4, =0x00003008
	adds r1, r4
	strb r0, [r1]
	movs r1, 0x8
	add r1, r9
	mov r8, r1
	mov r0, r8
	bl AddWindow
	ldr r1, [r7]
	ldr r2, =0x00003009
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	ldr r3, =0x00003009
	adds r0, r3
	ldrb r0, [r0]
	bl ClearWindowTilemap
	mov r0, r9
	bl sub_8029174
	mov r0, r8
	bl sub_8029074
	ldr r1, [r7]
	ldr r0, =0x00003014
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r1, =0x00003020
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r7]
	ldr r2, =0x00003024
	adds r0, r2
	strb r6, [r0]
	b _0802A35E
	.pool
_0802A0CC:
	ldr r3, =0x00003008
	mov r8, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	ldr r1, =0x00003009
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_WantToPlayAgain
	movs r1, 0x5
	str r1, [sp]
	movs r3, 0xFF
	mov r9, r3
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_Yes
	str r6, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_SelectorArrow2
	str r6, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r7]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A2EA
	.pool
_0802A194:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A1B6
	ldr r0, [r7]
	ldr r3, =0x00003008
	adds r0, r3
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r7]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A1B6:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r7]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A2EA
	.pool
_0802A1D0:
	ldr r3, =0x00003020
	adds r0, r2, r3
	ldrb r5, [r0]
	cmp r5, 0
	bne _0802A1DC
	movs r5, 0x1
_0802A1DC:
	ldr r0, =0x00003009
	mov r8, r0
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_Yes
	movs r1, 0x1
	str r1, [sp]
	movs r3, 0xFF
	mov r10, r3
	str r3, [sp, 0x4]
	movs r1, 0
	mov r9, r1
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_SelectorArrow2
	subs r1, r5, 0x1
	lsls r1, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r5, 0x1
	movs r2, 0x1
	ands r2, r1
	cmp r2, 0
	beq _0802A294
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r3, =0x00003020
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802A2E4
	strb r5, [r1]
	b _0802A2E4
	.pool
_0802A294:
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0802A2CC
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r2, =0x00003020
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0802A2C2
	cmp r0, 0x1
	bgt _0802A2BC
	cmp r0, 0
	beq _0802A2C2
	b _0802A35E
	.pool
_0802A2BC:
	cmp r0, 0x2
	beq _0802A2C8
	b _0802A35E
_0802A2C2:
	movs r0, 0x2
	strb r0, [r1]
	b _0802A35E
_0802A2C8:
	strb r5, [r1]
	b _0802A35E
_0802A2CC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0802A35E
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r3, =0x00003020
	adds r0, r3
	movs r1, 0x2
	strb r1, [r0]
_0802A2E4:
	ldr r1, [r7]
	ldr r0, =0x00003014
	adds r1, r0
_0802A2EA:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A35E
	.pool
_0802A2FC:
	ldr r0, [r7]
	ldr r2, =0x00003020
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, =0x00003024
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r7]
	ldr r6, =0x00003008
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	adds r0, r6
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r7]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r7]
	movs r3, 0xC0
	lsls r3, 6
	adds r0, r3
	movs r1, 0x1
	str r1, [r0]
_0802A35E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A010

	thumb_func_start sub_802A380
sub_802A380: @ 802A380
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r6, =0x00003014
	adds r0, r6
	ldrb r4, [r0]
	cmp r4, 0x1
	beq _0802A3D8
	cmp r4, 0x1
	bgt _0802A3A4
	cmp r4, 0
	beq _0802A3AE
	b _0802A420
	.pool
_0802A3A4:
	cmp r4, 0x2
	beq _0802A3EC
	cmp r4, 0x3
	beq _0802A404
	b _0802A420
_0802A3AE:
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldr r2, =gText_SavingDontTurnOffPower
	str r4, [sp]
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
	b _0802A410
	.pool
_0802A3D8:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802A414
	.pool
_0802A3EC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A448
	ldr r0, =sub_8153688
	movs r1, 0
	bl CreateTask
	b _0802A410
	.pool
_0802A404:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0802A448
_0802A410:
	ldr r1, [r5]
	adds r1, r6
_0802A414:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A448
	.pool
_0802A420:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_0802A448:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A380

	thumb_func_start sub_802A454
sub_802A454: @ 802A454
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r1, =gUnknown_02022CF8
	ldr r2, [r1]
	ldr r6, =0x00003014
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _0802A4AC
	cmp r0, 0x1
	bgt _0802A47C
	cmp r0, 0
	beq _0802A482
	b _0802A520
	.pool
_0802A47C:
	cmp r0, 0x2
	beq _0802A4F4
	b _0802A520
_0802A482:
	ldr r4, =gUnknown_082F7BEC
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	ldr r2, =0x00003008
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl sub_8029174
	b _0802A510
	.pool
_0802A4AC:
	ldr r4, =0x00003008
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	ldr r2, =gText_CommunicationStandby3
	movs r1, 0x5
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802A514
	.pool
_0802A4F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A50A
	ldr r0, [r5]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A50A:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802A510:
	ldr r1, [r5]
	adds r1, r6
_0802A514:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A52C
	.pool
_0802A520:
	ldr r0, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_0802A52C:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802A454

	thumb_func_start sub_802A534
sub_802A534: @ 802A534
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003008
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A534

	thumb_func_start sub_802A588
sub_802A588: @ 802A588
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r7, =0x00003014
	adds r2, r1, r7
	ldrb r5, [r2]
	adds r6, r0, 0
	cmp r5, 0x1
	beq _0802A610
	cmp r5, 0x1
	bgt _0802A5B0
	cmp r5, 0
	beq _0802A5BA
	b _0802A6A4
	.pool
_0802A5B0:
	cmp r5, 0x2
	beq _0802A658
	cmp r5, 0x3
	beq _0802A684
	b _0802A6A4
_0802A5BA:
	ldr r4, =gUnknown_082F7BE4
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r6]
	ldr r2, =0x00003008
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl sub_8029174
	ldr r1, [r6]
	adds r1, r7
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, =0x0000301c
	adds r1, r0, r2
	movs r2, 0
	strh r5, [r1]
	ldr r1, =0x00003020
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	b _0802A6EA
	.pool
_0802A610:
	ldr r4, =0x00003008
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ldr r2, =gText_SomeoneDroppedOut
	movs r1, 0x5
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A678
	.pool
_0802A658:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A66E
	ldr r0, [r6]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A66E:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r6]
	adds r1, r7
_0802A678:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A6EA
	.pool
_0802A684:
	ldr r0, =0x0000301c
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x77
	bls _0802A6EA
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _0802A6EA
	.pool
_0802A6A4:
	ldr r0, [r6]
	ldr r1, =0x00003024
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, =0x00003008
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r2, 0xC0
	lsls r2, 6
	adds r0, r2
	movs r1, 0x1
	str r1, [r0]
_0802A6EA:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A588

	thumb_func_start unused_0
unused_0: @ 802A6FC
	push {r4,lr}
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003004
	adds r0, r1
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unused_0

	thumb_func_start nullsub_16
nullsub_16: @ 802A728
	bx lr
	thumb_func_end nullsub_16

	thumb_func_start sub_802A72C
sub_802A72C: @ 802A72C
	push {r4,lr}
	ldr r2, =gUnknown_02022CF8
	ldr r1, [r2]
	ldr r3, =0x00003014
	adds r1, r3
	movs r3, 0
	strb r3, [r1]
	ldr r1, [r2]
	movs r4, 0xC0
	lsls r4, 6
	adds r2, r1, r4
	str r3, [r2]
	ldr r2, =0x00003028
	adds r1, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A72C

	thumb_func_start sub_802A75C
sub_802A75C: @ 802A75C
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003028
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802A75C

	thumb_func_start sub_802A770
sub_802A770: @ 802A770
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0802A78C
	movs r0, 0x1
	b _0802A78E
	.pool
_0802A78C:
	movs r0, 0
_0802A78E:
	pop {r1}
	bx r1
	thumb_func_end sub_802A770

	thumb_func_start sub_802A794
sub_802A794: @ 802A794
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003024
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802A794

	thumb_func_start sub_802A7A8
sub_802A7A8: @ 802A7A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x4
	mov r8, r0
	mov r2, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_0802A7CE:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _0802A7CE
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F7BA4
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	bl InitStandardTextBoxWindows
	bl sub_8197200
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r4, =gUnknown_02022CF8
	ldr r1, [r4]
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 6
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A7A8

	thumb_func_start sub_802A8E8
sub_802A8E8: @ 802A8E8
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003018
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x5
	bhi _0802A982
	lsls r0, 2
	ldr r1, =_0802A910
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802A910:
	.4byte _0802A928
	.4byte _0802A938
	.4byte _0802A93E
	.4byte _0802A94C
	.4byte _0802A964
	.4byte _0802A972
_0802A928:
	ldr r0, =gDodrioBerryBgPal1
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	b _0802A98A
	.pool
_0802A938:
	bl reset_temp_tile_data_buffers
	b _0802A98A
_0802A93E:
	ldr r1, =gDodrioBerryBgGfx1
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	b _0802A954
	.pool
_0802A94C:
	ldr r1, =gDodrioBerryBgGfx2
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
_0802A954:
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _0802A98A
	.pool
_0802A964:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802A98A
	b _0802A998
_0802A972:
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	b _0802A98A
_0802A982:
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _0802A99A
_0802A98A:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003018
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0802A998:
	movs r0, 0
_0802A99A:
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802A8E8

	.align 2, 0 @ don't pad with nop
