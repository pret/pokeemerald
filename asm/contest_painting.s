	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_812FDA8
sub_812FDA8: @ 812FDA8
	push {r4-r7,lr}
	ldr r3, =gUnknown_02039F5D
	ldr r4, =gUnknown_02039F5C
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	subs r0, 0x1
	lsls r1, r0, 5
	adds r2, r1
	ldr r1, =gUnknown_02039F3C
	ldr r5, =0x00002e90
	adds r2, r5
	ldm r2!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r2!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r2!, {r6,r7}
	stm r1!, {r6,r7}
	strb r0, [r3]
	movs r0, 0
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FDA8

	thumb_func_start sub_812FDEC
sub_812FDEC: @ 812FDEC
	push {lr}
	bl sub_812FE58
	pop {r0}
	bx r0
	thumb_func_end sub_812FDEC

	thumb_func_start sub_812FDF8
sub_812FDF8: @ 812FDF8
	push {lr}
	bl sub_812FFC8
	bl RunTextPrinters
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_812FDF8

	thumb_func_start sub_812FE0C
sub_812FE0C: @ 812FE0C
	push {r4,r5,lr}
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
	ldr r4, =gUnknown_030061C4
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r4, =gUnknown_03006190
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, =gUnknown_030011F7
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1
	bl GetBgTilemapBuffer
	bl Free
	bl sub_805F094
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FE0C

	thumb_func_start sub_812FE58
sub_812FE58: @ 812FE58
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _0812FE6E
	b _0812FFA0
_0812FE6E:
	lsls r0, 2
	ldr r1, =_0812FE80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812FE80:
	.4byte _0812FE94
	.4byte _0812FEC8
	.4byte _0812FF14
	.4byte _0812FF2A
	.4byte _0812FF54
_0812FE94:
	bl remove_some_task
	movs r0, 0
	bl SetVBlankCallback
	bl init_uns_table_pokemon_copy
	ldr r1, =gUnknown_030061C0
	ldr r0, =gUnknown_02039F3C
	str r0, [r1]
	movs r0, 0x1
	bl sub_8130238
	bl sub_81301EC
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0812FF3E
	.pool
_0812FEC8:
	bl ResetPaletteFade
	movs r2, 0xC0
	lsls r2, 19
	movs r3, 0xC0
	lsls r3, 9
	movs r5, 0
	ldr r1, =0x040000d4
	movs r4, 0x80
	lsls r4, 5
	ldr r6, =0x85000400
	movs r7, 0x85
	lsls r7, 24
_0812FEE2:
	str r5, [sp]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r4
	subs r3, r4
	cmp r3, r4
	bhi _0812FEE2
	str r5, [sp]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 2
	orrs r0, r7
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl ResetAllObjectData
	b _0812FF36
	.pool
_0812FF14:
	ldrh r0, [r4, 0x20]
	bl SeedRng
	bl InitKeys
	bl sub_8130098
	movs r0, 0x87
	lsls r0, 3
	adds r1, r4, r0
	b _0812FF3E
_0812FF2A:
	ldr r0, =gUnknown_02039F5D
	ldrb r0, [r0]
	ldr r1, =gUnknown_02039F5C
	ldrb r1, [r1]
	bl sub_8130884
_0812FF36:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_0812FF3E:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0812FFA0
	.pool
_0812FF54:
	ldr r0, =gUnknown_02039F5D
	ldrb r0, [r0]
	ldr r1, =gUnknown_02039F5C
	ldrb r1, [r1]
	bl sub_813010C
	ldr r0, =gUnknown_085B0838
	movs r1, 0
	movs r2, 0x2
	bl LoadPalette
	movs r1, 0xA0
	lsls r1, 19
	movs r4, 0
	str r4, [sp]
	ldr r0, =0x040000d4
	mov r2, sp
	str r2, [r0]
	str r1, [r0, 0x4]
	ldr r1, =0x85000100
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	movs r0, 0x2
	bl BeginFastPaletteFade
	ldr r0, =sub_81302D0
	bl SetVBlankCallback
	ldr r0, =gUnknown_030011F0
	strb r4, [r0]
	movs r1, 0x9A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =sub_812FDF8
	bl SetMainCallback2
_0812FFA0:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FE58

	thumb_func_start sub_812FFC8
sub_812FFC8: @ 812FFC8
	push {lr}
	sub sp, 0x4
	ldr r3, =gUnknown_030011F0
	ldrb r1, [r3]
	cmp r1, 0x1
	beq _0813001C
	cmp r1, 0x1
	bgt _0812FFE4
	cmp r1, 0
	beq _0812FFEA
	b _08130082
	.pool
_0812FFE4:
	cmp r1, 0x2
	beq _0813005C
	b _08130082
_0812FFEA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812FFFA
	movs r0, 0x1
	strb r0, [r3]
_0812FFFA:
	ldr r0, =gUnknown_030011F6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08130082
	ldr r1, =gUnknown_030011F4
	ldrh r0, [r1]
	cmp r0, 0
	beq _08130082
	subs r0, 0x1
	b _08130080
	.pool
_0813001C:
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	ands r1, r2
	cmp r1, 0
	bne _0813002E
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _08130040
_0813002E:
	movs r0, 0x2
	strb r0, [r3]
	subs r0, 0x3
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_08130040:
	ldr r0, =gUnknown_030011F6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08130082
	ldr r1, =gUnknown_030011F4
	movs r0, 0
	b _08130080
	.pool
_0813005C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0813006E
	ldr r0, =sub_812FE0C
	bl SetMainCallback2
_0813006E:
	ldr r0, =gUnknown_030011F6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08130082
	ldr r1, =gUnknown_030011F4
	ldrh r0, [r1]
	cmp r0, 0x1D
	bhi _08130082
	adds r0, 0x1
_08130080:
	strh r0, [r1]
_08130082:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FFC8

	thumb_func_start sub_8130098
sub_8130098: @ 8130098
	push {r4,lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085B07E8
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r4, =gUnknown_030011F7
	ldr r0, =gUnknown_085B07EC
	bl AddWindow
	strb r0, [r4]
	bl DeactivateAllTextPrinters
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl ShowBg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130098

	thumb_func_start sub_813010C
sub_813010C: @ 813010C
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081301D4
	ldr r6, =gUnknown_030061C0
	ldr r1, [r6]
	ldrb r5, [r1, 0xA]
	cmp r0, 0x7
	bhi _08130190
	ldr r4, =gStringVar1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_818E868
	ldr r1, =gUnknown_085E8D5E
	adds r0, r4, 0
	bl StringAppend
	ldr r1, =gUnknown_085B07D4
	ldr r0, [r6]
	ldrb r0, [r0, 0x1E]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringAppend
	ldr r4, =gStringVar2
	ldr r1, [r6]
	adds r1, 0x16
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	bl sub_81DB5AC
	ldr r0, =gStringVar3
	ldr r1, [r6]
	adds r1, 0xB
	bl StringCopy
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0827EA0C
	bl StringExpandPlaceholders
	b _081301A6
	.pool
_08130190:
	ldr r0, =gStringVar1
	adds r1, 0xB
	bl StringCopy
	ldr r0, =gStringVar4
	ldr r2, =gUnknown_085B07F4
	lsls r1, r5, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringExpandPlaceholders
_081301A6:
	ldr r4, =gStringVar4
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldr r0, =gUnknown_030011F7
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	bl Print
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081301D4:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813010C

	thumb_func_start sub_81301EC
sub_81301EC: @ 81301EC
	push {lr}
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r2, =0x04000200
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	ldr r1, =0x00000c42
	movs r0, 0x8
	bl SetGpuReg
	ldr r1, =0x00000a45
	movs r0, 0xA
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81301EC

	thumb_func_start sub_8130238
sub_8130238: @ 8130238
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0813025C
	ldr r0, =gUnknown_030011F6
	strb r1, [r0]
	ldr r0, =gUnknown_030011F2
	strh r1, [r0]
	ldr r0, =gUnknown_030011F4
	strh r1, [r0]
	b _0813026E
	.pool
_0813025C:
	ldr r1, =gUnknown_030011F6
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gUnknown_030011F2
	movs r0, 0xF
	strh r0, [r1]
	ldr r1, =gUnknown_030011F4
	movs r0, 0x1E
	strh r0, [r1]
_0813026E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130238

	thumb_func_start sub_8130280
sub_8130280: @ 8130280
	push {lr}
	ldr r0, =gUnknown_030011F6
	ldrb r0, [r0]
	cmp r0, 0
	bne _08130298
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	b _081302C0
	.pool
_08130298:
	ldr r1, =0x00000a45
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =gUnknown_030011F2
	ldr r0, =gUnknown_030011F4
	ldrh r0, [r0]
	lsrs r0, 1
	strh r0, [r1]
	lsls r1, r0, 12
	lsls r2, r0, 8
	orrs r1, r2
	lsls r2, r0, 4
	orrs r1, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
_081302C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130280

	thumb_func_start sub_81302D0
sub_81302D0: @ 81302D0
	push {lr}
	bl sub_8130280
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81302D0

	thumb_func_start sub_81302E8
sub_81302E8: @ 81302E8
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gUnknown_030061C0
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	ldr r2, [r0]
	adds r0, r5, 0
	bl species_and_otid_get_pal
	ldr r7, =gUnknown_030061C4
	ldr r1, [r7]
	bl LZDecompressVram
	cmp r4, 0
	bne _08130348
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r4, =gUnknown_020244D4
	ldr r1, [r4]
	ldr r1, [r1, 0x8]
	ldr r2, [r6]
	ldr r3, [r2]
	adds r2, r5, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldr r1, [r7]
	ldr r2, =gUnknown_03006190
	ldr r2, [r2]
	bl sub_8130380
	b _0813036C
	.pool
_08130348:
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r4, =gUnknown_020244D4
	ldr r1, [r4]
	ldr r1, [r1, 0x4]
	ldr r2, [r6]
	ldr r3, [r2]
	adds r2, r5, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	ldr r1, [r7]
	ldr r2, =gUnknown_03006190
	ldr r2, [r2]
	bl sub_8130380
_0813036C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81302E8

	thumb_func_start sub_8130380
sub_8130380: @ 8130380
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r10, r0
	mov r9, r1
	str r2, [sp]
	movs r0, 0
_08130394:
	movs r3, 0
	adds r1, r0, 0x1
	str r1, [sp, 0x4]
	lsls r0, 3
	str r0, [sp, 0x8]
_0813039E:
	movs r1, 0
	adds r2, r3, 0x1
	mov r8, r2
	ldr r7, [sp, 0x8]
	adds r0, r7, r3
	lsls r0, 5
	mov r12, r0
	lsls r4, r3, 3
_081303AE:
	movs r3, 0
	lsls r0, r1, 2
	adds r6, r1, 0x1
	mov r2, r12
	adds r5, r2, r0
	ldr r7, [sp, 0x8]
	adds r0, r7, r1
	lsls r0, 7
	ldr r1, [sp]
	adds r2, r0, r1
_081303C2:
	lsrs r0, r3, 1
	adds r0, r5, r0
	add r0, r10
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _081303D6
	lsrs r1, 4
	b _081303DA
_081303D6:
	movs r0, 0xF
	ands r1, r0
_081303DA:
	cmp r1, 0
	bne _081303EC
	adds r0, r4, r3
	lsls r0, 1
	adds r0, r2
	movs r7, 0x80
	lsls r7, 8
	adds r1, r7, 0
	b _081303F8
_081303EC:
	adds r0, r4, r3
	lsls r0, 1
	adds r0, r2
	lsls r1, 1
	add r1, r9
	ldrh r1, [r1]
_081303F8:
	strh r1, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x7
	bls _081303C2
	lsls r0, r6, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081303AE
	mov r1, r8
	lsls r0, r1, 16
	lsrs r3, r0, 16
	cmp r3, 0x7
	bls _0813039E
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r0, 0x7
	bls _08130394
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8130380

	thumb_func_start sub_8130430
sub_8130430: @ 8130430
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_085A989C
	movs r2, 0x80
	lsls r2, 1
	movs r1, 0
	bl LoadPalette
	cmp r4, 0x1
	beq _0813044E
	b _081305A4
_0813044E:
	ldr r0, =gUnknown_030061C0
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _0813050C
	lsls r0, 2
	ldr r1, =_08130478
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08130478:
	.4byte _0813048C
	.4byte _081304A4
	.4byte _081304BC
	.4byte _081304D4
	.4byte _081304F8
_0813048C:
	ldr r0, =gUnknown_085A9A9C
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AE974
	b _081304E0
	.pool
_081304A4:
	ldr r0, =gUnknown_085AAB20
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AEE80
	b _081304E0
	.pool
_081304BC:
	ldr r0, =gUnknown_085AB750
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AF38C
	b _081304E0
	.pool
_081304D4:
	ldr r0, =gUnknown_085AC288
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AF898
_081304E0:
	ldr r1, =gUnknown_03006190
	ldr r1, [r1]
	bl RLUnCompWram
	b _0813050C
	.pool
_081304F8:
	ldr r0, =gUnknown_085AD240
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AFDA4
	ldr r1, =gUnknown_03006190
	ldr r1, [r1]
	bl RLUnCompWram
_0813050C:
	movs r1, 0
	ldr r5, =0x06006000
	ldr r0, =0x00001015
	adds r4, r0, 0
_08130514:
	movs r3, 0
	lsls r2, r1, 5
_08130518:
	adds r0, r2, r3
	lsls r0, 1
	adds r0, r5
	strh r4, [r0]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1F
	bls _08130518
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x13
	bls _08130514
	movs r1, 0
	ldr r0, =0x0600608c
	mov r12, r0
	ldr r7, =gUnknown_03006190
_0813053C:
	movs r3, 0
	adds r6, r1, 0x1
	lsls r5, r1, 5
	lsls r4, r1, 6
_08130544:
	adds r2, r5, r3
	lsls r2, 1
	add r2, r12
	ldr r0, [r7]
	adds r0, r4, r0
	lsls r1, r3, 1
	adds r0, r1
	adds r0, 0x8C
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x11
	bls _08130544
	lsls r0, r6, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _0813053C
	movs r3, 0
	ldr r4, =0x0600608e
	ldr r2, =gUnknown_03006190
_08130570:
	lsls r1, r3, 1
	adds r1, r4
	ldr r0, [r2]
	adds r0, 0x8E
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xF
	bls _08130570
	b _08130676
	.pool
_081305A4:
	cmp r5, 0x7
	bhi _081305C0
	ldr r0, =gUnknown_085AE370
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085B02B0
	b _08130650
	.pool
_081305C0:
	ldr r0, =gUnknown_030061C0
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _08130676
	lsls r0, 2
	ldr r1, =_081305E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081305E8:
	.4byte _081305FC
	.4byte _08130614
	.4byte _0813062C
	.4byte _08130644
	.4byte _08130664
_081305FC:
	ldr r0, =gUnknown_085A9A9C
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AE974
	b _08130650
	.pool
_08130614:
	ldr r0, =gUnknown_085AAB20
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AEE80
	b _08130650
	.pool
_0813062C:
	ldr r0, =gUnknown_085AB750
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AF38C
	b _08130650
	.pool
_08130644:
	ldr r0, =gUnknown_085AC288
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AF898
_08130650:
	ldr r1, =0x06006000
	bl RLUnCompVram
	b _08130676
	.pool
_08130664:
	ldr r0, =gUnknown_085AD240
	movs r1, 0xC0
	lsls r1, 19
	bl RLUnCompVram
	ldr r0, =gUnknown_085AFDA4
	ldr r1, =0x06006000
	bl RLUnCompVram
_08130676:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130430

	thumb_func_start sub_8130688
sub_8130688: @ 8130688
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gMain
	ldr r1, =gUnknown_085B0830
	ldr r2, [r1, 0x4]
	ldr r1, [r1]
	str r1, [r3, 0x38]
	str r2, [r3, 0x3C]
	ldrh r2, [r3, 0x3C]
	ldr r1, =0xfffffc00
	ands r1, r2
	strh r1, [r3, 0x3C]
	ldrh r1, [r3, 0x3A]
	ldr r0, =0xfffffe00
	ands r0, r1
	movs r1, 0x58
	orrs r0, r1
	strh r0, [r3, 0x3A]
	adds r1, r3, 0
	adds r1, 0x38
	movs r0, 0x18
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130688

	thumb_func_start sub_81306CC
sub_81306CC: @ 81306CC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x7
	bhi _081306E4
	ldr r0, =gUnknown_030061C0
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	b _081306F4
	.pool
_081306E4:
	ldr r0, =gUnknown_030061C0
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
_081306F4:
	cmp r0, 0x4
	bhi _08130732
	lsls r0, 2
	ldr r1, =_0813070C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813070C:
	.4byte _08130720
	.4byte _08130724
	.4byte _08130728
	.4byte _0813072C
	.4byte _08130730
_08130720:
	movs r0, 0x9
	b _08130732
_08130724:
	movs r0, 0xD
	b _08130732
_08130728:
	movs r0, 0x2
	b _08130732
_0813072C:
	movs r0, 0x24
	b _08130732
_08130730:
	movs r0, 0x6
_08130732:
	pop {r1}
	bx r1
	thumb_func_end sub_81306CC

	thumb_func_start sub_8130738
sub_8130738: @ 8130738
	push {r4,lr}
	ldr r4, =gUnknown_030061C4
	movs r0, 0x80
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	ldr r4, =gUnknown_03006190
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130738

	thumb_func_start sub_8130760
sub_8130760: @ 8130760
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gUnknown_030061A0
	ldr r0, =gUnknown_03006190
	ldr r0, [r0]
	str r0, [r1, 0x4]
	ldr r0, =gUnknown_030061C4
	ldr r0, [r0]
	str r0, [r1, 0x8]
	movs r2, 0
	strb r2, [r1, 0x18]
	ldr r0, =gUnknown_030061C0
	ldr r0, [r0]
	ldrb r0, [r0]
	strb r0, [r1, 0x1F]
	strb r2, [r1, 0x19]
	strb r2, [r1, 0x1A]
	movs r0, 0x40
	strb r0, [r1, 0x1B]
	strb r0, [r1, 0x1C]
	strb r0, [r1, 0x1D]
	strb r0, [r1, 0x1E]
	subs r0, r3, 0x2
	adds r4, r1, 0
	cmp r0, 0x22
	bhi _08130844
	lsls r0, 2
	ldr r1, =_081307B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081307B4:
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130840
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130844
	.4byte _08130840
_08130840:
	movs r0, 0x3
	b _08130846
_08130844:
	movs r0, 0x1
_08130846:
	strh r0, [r4, 0x14]
	movs r0, 0x2
	strh r0, [r4, 0x16]
	strb r3, [r4]
	ldr r0, =0x06010000
	str r0, [r4, 0x10]
	adds r0, r4, 0
	bl sub_8124F2C
	adds r0, r4, 0
	bl sub_81261A4
	adds r0, r4, 0
	bl sub_8126058
	ldr r0, =gUnknown_030061C4
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x80
	lsls r2, 2
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130760

	thumb_func_start sub_8130884
sub_8130884: @ 8130884
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	bl sub_8130738
	ldr r0, =gUnknown_030061C0
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	movs r1, 0
	bl sub_81302E8
	adds r0, r4, 0
	bl sub_81306CC
	lsls r0, 24
	lsrs r0, 24
	bl sub_8130760
	adds r0, r4, 0
	bl sub_8130688
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8130430
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8130884

	.align 2, 0 @ Don't pad with nop.
