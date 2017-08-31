	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8121478
sub_8121478: @ 8121478
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r4, =gUnknown_0203A134
	ldr r0, =0x0000222c
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =0x0000021d
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, =0x0000021e
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	ldr r4, [r4]
	movs r3, 0x88
	lsls r3, 2
	adds r1, r4, r3
	ldr r0, =CopyEasyChatWord
	str r0, [r1]
	movs r0, 0x89
	lsls r0, 2
	adds r1, r4, r0
	ldr r0, =ConvertEasyChatWordsToString
	str r0, [r1]
	ldrh r1, [r5, 0x20]
	adds r0, r1, 0
	subs r0, 0x79
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bhi _081214E8
	subs r1, 0x79
	subs r2, 0x4
	adds r0, r4, r2
	strb r1, [r0]
	b _081214F2
	.pool
_081214E8:
	ldr r3, =0x0000021a
	adds r1, r4, r3
	movs r0, 0
	strb r0, [r1]
	movs r6, 0
_081214F2:
	ldr r0, =gUnknown_0203A134
	ldr r1, [r0]
	ldr r2, =0x0000021e
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08121504
	cmp r0, 0x1
	beq _0812152C
_08121504:
	movs r3, 0x8A
	lsls r3, 2
	adds r2, r1, r3
	subs r3, 0xE
	adds r0, r1, r3
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0859F3B4
	b _08121540
	.pool
_0812152C:
	movs r0, 0x8A
	lsls r0, 2
	adds r2, r1, r0
	ldr r3, =0x0000021a
	adds r0, r1, r3
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0859F458
_08121540:
	adds r0, r1
	str r0, [r2]
	ldrh r0, [r5, 0x1E]
	mov r1, sp
	bl sub_80D45E8
	lsls r0, 16
	ldr r1, =0xffff0000
	adds r0, r1
	movs r1, 0xCD
	lsls r1, 17
	cmp r0, r1
	bhi _081215AC
	ldr r1, =gUnknown_0203A134
	ldr r2, [r1]
	ldr r3, =0x0000021a
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x6
	beq _0812158C
	cmp r0, 0x9
	beq _0812159C
	ldr r0, =0x0000021b
	adds r1, r2, r0
	movs r0, 0
	strb r0, [r1]
	b _081215BA
	.pool
_0812158C:
	ldr r0, =0x0000021b
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
	b _081215BA
	.pool
_0812159C:
	ldr r0, =0x0000021b
	adds r1, r2, r0
	movs r0, 0x2
	strb r0, [r1]
	b _081215BA
	.pool
_081215AC:
	ldr r0, =gUnknown_0203A134
	ldr r1, [r0]
	ldr r2, =0x0000021b
	adds r1, r2
	movs r2, 0
	strb r2, [r1]
	adds r3, r0, 0
_081215BA:
	ldr r1, [r3]
	movs r3, 0x85
	lsls r3, 2
	adds r0, r1, r3
	str r5, [r0]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r1, r2
	str r7, [r0]
	adds r3, 0x4
	adds r0, r1, r3
	strb r6, [r0]
	ldr r0, =sub_81219F0
	bl SetMainCallback2
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121478

	thumb_func_start sub_81215EC
sub_81215EC: @ 81215EC
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x12
	bls _08121600
	b _081219E2
_08121600:
	lsls r0, 2
	ldr r1, =_08121614
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08121614:
	.4byte _08121660
	.4byte _0812166E
	.4byte _08121688
	.4byte _0812168E
	.4byte _08121694
	.4byte _0812169A
	.4byte _081216F4
	.4byte _08121730
	.4byte _08121740
	.4byte _08121774
	.4byte _08121782
	.4byte _081217D8
	.4byte _081217EC
	.4byte _081218B0
	.4byte _081218CC
	.4byte _081218EC
	.4byte _081218F6
	.4byte _08121910
	.4byte _08121980
_08121660:
	movs r0, 0
	bl SetVBlankCallback
	bl remove_some_task
	movs r0, 0
	b _081216EC
_0812166E:
	add r1, sp, 0x8
	movs r0, 0
	strh r0, [r1]
	movs r1, 0xE0
	lsls r1, 19
	ldr r2, =0x01000200
	add r0, sp, 0x8
	bl CpuSet
	b _081219D4
	.pool
_08121688:
	bl ResetPaletteFade
	b _081219D4
_0812168E:
	bl ResetTasks
	b _081219D4
_08121694:
	bl ResetAllObjectData
	b _081219D4
_0812169A:
	bl ResetObjectPaletteAllocator
	bl reset_temp_tile_data_buffers
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
_081216EC:
	movs r1, 0
	bl SetGpuReg
	b _081219D4
_081216F4:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0859F290
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203A134
	ldr r1, [r4]
	movs r2, 0x8B
	lsls r2, 2
	adds r1, r2
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x0000122c
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	b _081219D4
	.pool
_08121730:
	ldr r0, =gUnknown_0859F29C
	bl InitWindows
	bl DeactivateAllTextPrinters
	b _081219D4
	.pool
_08121740:
	ldr r2, =gUnknown_0859F2B8
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	ldr r1, =0x0000021a
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081219D4
	.pool
_08121774:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _08121780
	b _081219D4
_08121780:
	b _081219E2
_08121782:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r2, =gUnknown_0859F2B8
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	ldr r1, =0x0000021a
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	b _081219D4
	.pool
_081217D8:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _081219D4
_081217EC:
	bl sub_8098C64
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r6, =gPlttBufferUnfaded
	ldr r4, =gUnknown_0859F2B8
	ldr r0, =gUnknown_0203A134
	ldr r3, [r0]
	ldr r2, =0x0000021a
	adds r3, r2
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x10]
	subs r2, 0x26
	adds r0, r6, r2
	strh r1, [r0]
	ldr r5, =gPlttBufferFaded
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x10]
	adds r2, r5, r2
	strh r0, [r2]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x12]
	movs r2, 0xFB
	lsls r2, 1
	adds r0, r6, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x12]
	adds r2, r5, r2
	strh r0, [r2]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_0859F2B0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r0, [r2, 0x8]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r6, 0x14]
	ldrb r0, [r2, 0x8]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x14]
	ldrb r0, [r2, 0x8]
	lsls r0, 2
	adds r1, 0x2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r6, 0x16]
	ldrb r0, [r2, 0x8]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x16]
	b _081219D4
	.pool
_081218B0:
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081218C2
	b _081219D4
_081218C2:
	bl sub_8121A1C
	b _081219D4
	.pool
_081218CC:
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _081218DE
	b _081219D4
_081218DE:
	bl sub_8121B1C
	bl RunTextPrinters
	b _081219D4
	.pool
_081218EC:
	bl sub_8087598
	cmp r0, 0x1
	bne _081219D4
	b _081219E2
_081218F6:
	ldr r0, =sub_8121C50
	bl SetVBlankCallback
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	b _081219D4
	.pool
_08121910:
	ldr r5, =gUnknown_0203A134
	ldr r0, [r5]
	movs r1, 0x85
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, 0x1E]
	bl sub_80D2E84
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldr r2, =0x0000021b
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08121940
	cmp r0, 0x2
	beq _08121958
	b _081219D4
	.pool
_08121940:
	adds r0, r4, 0
	bl sub_80D2F68
	ldr r1, =DummyObjectCallback
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0x60
	b _0812196A
	.pool
_08121958:
	adds r0, r4, 0
	bl sub_80D2F68
	ldr r1, =DummyObjectCallback
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0x28
_0812196A:
	movs r3, 0x80
	bl sub_80D2D78
	ldr r1, [r5]
	movs r2, 0x87
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	b _081219D4
	.pool
_08121980:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r1, =sub_8121C98
	str r1, [r0]
	movs r0, 0x1
	b _081219E4
	.pool
_081219D4:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081219E2:
	movs r0, 0
_081219E4:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81215EC

	thumb_func_start sub_81219F0
sub_81219F0: @ 81219F0
	push {lr}
_081219F2:
	bl sub_81215EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08121A0C
	ldr r0, =sub_8121C64
	bl SetMainCallback2
	b _08121A18
	.pool
_08121A0C:
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081219F2
_08121A18:
	pop {r0}
	bx r0
	thumb_func_end sub_81219F0

	thumb_func_start sub_8121A1C
sub_8121A1C: @ 8121A1C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	movs r5, 0
	ldr r2, =gUnknown_0203A134
	ldr r0, [r2]
	movs r1, 0x8A
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r5, r0
	bcs _08121A8A
	mov r8, r2
	adds r7, r1, 0
_08121A3C:
	lsls r0, r5, 6
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r0
	movs r3, 0x85
	lsls r3, 2
	adds r1, r2, r3
	lsls r3, r6, 1
	ldr r1, [r1]
	adds r1, r3
	adds r2, r7
	ldr r2, [r2]
	ldr r2, [r2, 0x8]
	lsls r4, r5, 2
	adds r2, r4, r2
	ldr r2, [r2]
	lsls r2, 30
	lsrs r2, 30
	movs r3, 0x1
	bl ConvertEasyChatWordsToString
	mov r1, r8
	ldr r0, [r1]
	adds r0, r7
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r4, r0
	ldr r0, [r4]
	lsls r0, 30
	lsrs r0, 30
	adds r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r1, [r1]
	cmp r5, r1
	bcc _08121A3C
_08121A8A:
	ldr r4, =gUnknown_0203A134
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r1, r2
	movs r3, 0x85
	lsls r3, 2
	adds r1, r3
	ldr r1, [r1]
	adds r1, 0x12
	bl StringCopy
	adds r2, r0, 0
	ldr r1, [r4]
	ldr r3, =0x0000021e
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08121AF0
	ldr r1, =gUnknown_085EEA78
	adds r0, r2, 0
	bl StringCopy
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1
	bl StringLength
	ldr r2, [r4]
	movs r3, 0x8A
	lsls r3, 2
	adds r1, r2, r3
	ldr r1, [r1]
	lsls r0, 16
	lsrs r0, 13
	subs r0, 0x60
	ldrb r1, [r1, 0x2]
	subs r1, r0
	ldr r0, =0x00000219
	adds r2, r0
	strb r1, [r2]
	b _08121B0C
	.pool
_08121AF0:
	movs r2, 0x80
	lsls r2, 2
	adds r0, r1, r2
	bl sub_81DB52C
	ldr r0, [r4]
	movs r3, 0x8A
	lsls r3, 2
	adds r1, r0, r3
	ldr r1, [r1]
	ldrb r1, [r1, 0x2]
	ldr r2, =0x00000219
	adds r0, r2
	strb r1, [r0]
_08121B0C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121A1C

	thumb_func_start sub_8121B1C
sub_8121B1C: @ 8121B1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	movs r7, 0
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r6, 0
	ldr r1, =gUnknown_0203A134
	ldr r0, [r1]
	movs r2, 0x8A
	lsls r2, 2
	mov r10, r2
	add r0, r10
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r6, r0
	bcs _08121BCC
	mov r9, r1
	mov r8, r10
_08121B60:
	mov r0, r9
	ldr r1, [r0]
	lsls r0, r6, 6
	adds r5, r1, r0
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _08121BB8
	cmp r0, 0
	beq _08121BB8
	mov r2, r8
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	lsls r4, r6, 2
	adds r0, r4, r0
	ldr r2, [r0]
	lsls r2, 24
	lsrs r2, 26
	ldrb r0, [r1, 0x4]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r1, 0x3]
	adds r3, r7, r3
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0859F2AC
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	bl box_print
	mov r1, r9
	ldr r0, [r1]
	add r0, r8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r4, r0
	ldrb r0, [r4, 0x1]
	adds r0, r7, r0
	lsls r0, 24
	lsrs r7, r0, 24
_08121BB8:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r2, =gUnknown_0203A134
	ldr r0, [r2]
	add r0, r10
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08121B60
_08121BCC:
	ldr r1, =gUnknown_085EEA78
	add r0, sp, 0xC
	bl StringCopy
	ldr r4, =gUnknown_0203A134
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00000219
	adds r0, r1
	ldrb r2, [r0]
	movs r0, 0x1
	add r1, sp, 0xC
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	adds r2, 0x68
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r3, [r0, 0x1]
	adds r3, 0x58
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0859F2AC
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121B1C

	thumb_func_start sub_8121C50
sub_8121C50: @ 8121C50
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8121C50

	thumb_func_start sub_8121C64
sub_8121C64: @ 8121C64
	push {r4,lr}
	ldr r4, =gUnknown_0203A134
	ldr r0, [r4]
	ldr r1, =0x0000021b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08121C7C
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
_08121C7C:
	ldr r0, [r4]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121C64

	thumb_func_start sub_8121C98
sub_8121C98: @ 8121C98
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08121CB2
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r1, =sub_8121CC0
	str r1, [r0]
_08121CB2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121C98

	thumb_func_start sub_8121CC0
sub_8121CC0: @ 8121CC0
	push {lr}
	sub sp, 0x4
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08121CEE
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r1, =sub_8121D00
	str r1, [r0]
_08121CEE:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121CC0

	thumb_func_start sub_8121D00
sub_8121D00: @ 8121D00
	push {r4,lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08121D88
	ldr r4, =gUnknown_0203A134
	ldr r0, [r4]
	movs r1, 0x83
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r1, [r4]
	ldr r2, =0x0000021b
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bgt _08121D58
	cmp r0, 0x1
	blt _08121D58
	subs r2, 0x7
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r0, [r0, 0x1E]
	bl sub_80D2E84
	lsls r0, 16
	lsrs r0, 16
	bl sub_80D2FF0
	ldr r0, [r4]
	movs r1, 0x87
	lsls r1, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D2EF8
_08121D58:
	ldr r4, =gUnknown_0203A134
	ldr r0, [r4]
	ldr r2, =0x0000222c
	movs r1, 0
	bl memset
	bl ResetPaletteFade
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	bl FreeAllWindowBuffers
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_08121D88:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121D00

	.align 2, 0 @ Don't pad with nop.
