	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	


	thumb_func_start sub_80C51C4
sub_80C51C4: @ 80C51C4
	push {lr}
	bl sub_80C51F0
	ldr r0, =sub_80C544C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C51C4

	thumb_func_start sub_80C51D8
sub_80C51D8: @ 80C51D8
	push {lr}
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldr r0, [r0]
	bl SetMainCallback2
	bl sub_80C52E4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C51D8

	thumb_func_start sub_80C51F0
sub_80C51F0: @ 80C51F0
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02039CEC
	ldr r0, [r5]
	cmp r0, 0
	beq _080C5204
	movs r0, 0x1
	b _080C52C8
	.pool
_080C5204:
	movs r0, 0x18
	bl AllocZeroed
	str r0, [r5]
	cmp r0, 0
	bne _080C5214
	movs r0, 0x2
	b _080C52C8
_080C5214:
	str r4, [r0]
	bl GetCurrentRegionMapSectionId
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3A
	beq _080C5232
	cmp r4, 0xCA
	beq _080C5232
	ldr r0, [r5]
	movs r1, 0xB0
	strh r1, [r0, 0x8]
	movs r1, 0x68
	strh r1, [r0, 0xA]
	b _080C5240
_080C5232:
	ldr r2, =gUnknown_02039CEC
	ldr r1, [r2]
	movs r0, 0xB0
	strh r0, [r1, 0x8]
	movs r0, 0x30
	strh r0, [r1, 0xA]
	adds r5, r2, 0
_080C5240:
	ldr r1, [r5]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000eb8
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1, 0x6]
	bl CanCopyRecordedBattleSaveData
	ldr r3, [r5]
	movs r1, 0x1
	ands r0, r1
	ldrb r2, [r3, 0xE]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xE]
	ldr r2, [r5]
	ldrb r1, [r2, 0xE]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xE]
	bl CountPlayerTrainerStars
	ldr r3, [r5]
	lsls r0, 4
	ldrb r2, [r3, 0xE]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xE]
	movs r4, 0
	adds r6, r5, 0
_080C5286:
	lsls r5, r4, 1
	ldr r1, =0x000008c4
	adds r0, r5, r1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C52A2
	ldr r1, [r6]
	adds r1, 0xF
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C52A2:
	ldr r2, =0x000008c5
	adds r0, r5, r2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C52BC
	ldr r1, [r6]
	adds r1, 0xF
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C52BC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080C5286
	movs r0, 0
_080C52C8:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C51F0

	thumb_func_start sub_80C52E4
sub_80C52E4: @ 80C52E4
	push {r4,lr}
	ldr r4, =gUnknown_02039CEC
	ldr r0, [r4]
	cmp r0, 0
	beq _080C5308
	movs r1, 0
	movs r2, 0x18
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	b _080C530A
	.pool
_080C5308:
	movs r0, 0x1
_080C530A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C52E4

	thumb_func_start sub_80C5310
sub_80C5310: @ 80C5310
	push {r4,lr}
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	cmp r0, 0
	beq _080C5324
	movs r0, 0x1
	b _080C533A
	.pool
_080C5324:
	ldr r0, =0x00002434
	bl AllocZeroed
	str r0, [r4]
	cmp r0, 0
	beq _080C5338
	movs r0, 0
	b _080C533A
	.pool
_080C5338:
	movs r0, 0x2
_080C533A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C5310

	thumb_func_start sub_80C5340
sub_80C5340: @ 80C5340
	push {r4,lr}
	bl FreeAllWindowBuffers
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	cmp r0, 0
	bne _080C5358
	movs r0, 0x1
	b _080C53A0
	.pool
_080C5358:
	ldr r0, [r0, 0x28]
	cmp r0, 0
	beq _080C5368
	bl Free
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x28]
_080C5368:
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	beq _080C537A
	bl Free
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x24]
_080C537A:
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	cmp r0, 0
	beq _080C538C
	bl Free
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x20]
_080C538C:
	ldr r0, [r4]
	ldr r2, =0x00002434
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_080C53A0:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C5340

	thumb_func_start pokemon_details
pokemon_details: @ 80C53AC
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02039CF0
	ldr r6, [r0]
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C5416
	ldr r3, =gUnknown_085713E0
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r4, [r0, 0xE]
	lsls r4, 28
	lsrs r0, r4, 29
	subs r0, 0x1
	lsls r0, 2
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r1, 8
	lsrs r0, r4, 29
	subs r0, 0x1
	lsls r0, 2
	adds r5, r3, 0x2
	adds r0, r5
	movs r7, 0
	ldrsh r2, [r0, r7]
	lsls r2, 8
	lsrs r0, r4, 29
	subs r0, 0x1
	lsls r0, 2
	adds r0, r3
	movs r7, 0
	ldrsh r3, [r0, r7]
	lsrs r4, 29
	subs r4, 0x1
	lsls r4, 2
	adds r4, r5
	movs r5, 0
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r7, 0x2E
	ldrsh r0, [r6, r7]
	str r0, [sp, 0x4]
	movs r4, 0x30
	ldrsh r0, [r6, r4]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	bl SetBgAffine
_080C5416:
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemon_details

	thumb_func_start sub_80C5438
sub_80C5438: @ 80C5438
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_80C5438

	thumb_func_start sub_80C544C
sub_80C544C: @ 80C544C
	push {lr}
	bl sub_80C5484
	cmp r0, 0
	beq _080C5464
	ldr r0, =sub_80C5A48
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_80C5438
	bl SetMainCallback2
_080C5464:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C544C

	thumb_func_start sub_80C5470
sub_80C5470: @ 80C5470
	push {lr}
	bl sub_80C570C
	cmp r0, 0
	beq _080C547E
	bl sub_80C51D8
_080C547E:
	pop {r0}
	bx r0
	thumb_func_end sub_80C5470

	thumb_func_start sub_80C5484
sub_80C5484: @ 80C5484
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0xA
	bls _080C5498
	b _080C56F4
_080C5498:
	lsls r0, 2
	ldr r1, =_080C54AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C54AC:
	.4byte _080C54D8
	.4byte _080C54EE
	.4byte _080C54F4
	.4byte _080C550A
	.4byte _080C5510
	.4byte _080C5560
	.4byte _080C5570
	.4byte _080C55D0
	.4byte _080C5624
	.4byte _080C5684
	.4byte _080C56D0
_080C54D8:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	movs r0, 0x2
	bl DisableInterrupts
	b _080C56F4
_080C54EE:
	bl sub_80C50D0
	b _080C56F4
_080C54F4:
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl reset_temp_tile_data_buffers
	b _080C56F4
_080C550A:
	bl sub_80C5310
	b _080C56F4
_080C5510:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085713E8
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_02039CF0
	ldr r1, [r4]
	adds r1, 0x32
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001032
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00002032
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	movs r0, 0x2
	movs r1, 0x6
	movs r2, 0x1
	bl SetBgAttribute
	b _080C56F4
	.pool
_080C5560:
	ldr r0, =gUnknown_08571400
	bl InitWindows
	bl DeactivateAllTextPrinters
	b _080C56F4
	.pool
_080C5570:
	ldr r0, =gUnknown_085712F8
	add r1, sp, 0x8
	bl malloc_and_decompress
	ldr r4, =gUnknown_02039CF0
	ldr r1, [r4]
	str r0, [r1, 0x20]
	ldr r0, =gUnknown_08571060
	add r1, sp, 0x8
	bl malloc_and_decompress
	ldr r1, [r4]
	str r0, [r1, 0x24]
	ldr r0, =gUnknown_085712C0
	add r1, sp, 0x8
	bl malloc_and_decompress
	ldr r1, [r4]
	str r0, [r1, 0x28]
	ldr r1, =gUnknown_08DE08C8
	movs r4, 0
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DE2084
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _080C56F4
	.pool
_080C55D0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _080C55DC
	b _080C56FE
_080C55DC:
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
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _080C56F4
_080C5624:
	ldr r4, =gUnknown_08DE07C8
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r4, 0
	movs r1, 0
	bl LoadPalette
	ldr r5, =gUnknown_02039CEC
	ldr r0, [r5]
	ldrb r0, [r0, 0xE]
	lsrs r0, 4
	lsls r0, 5
	adds r4, 0x20
	adds r0, r4
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl stdpal_get
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	bl sub_80C629C
	ldr r1, [r5]
	ldrb r0, [r1, 0xC]
	ldrb r1, [r1, 0xD]
	bl sub_80C6104
	ldr r5, [r5]
	ldrb r0, [r5, 0xE]
	movs r1, 0xE
	ands r1, r0
	cmp r1, 0x2
	beq _080C5674
	cmp r1, 0x4
	bne _080C56F4
_080C5674:
	movs r0, 0
	strh r0, [r5, 0x4]
	movs r0, 0x1
	b _080C5700
	.pool
_080C5684:
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
	bl sub_80C62DC
	ldr r0, =pokemon_details
	bl SetVBlankCallback
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _080C56F4
	.pool
_080C56D0:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080C56FE
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	strh r1, [r0, 0x4]
	movs r0, 0x1
	b _080C5700
	.pool
_080C56F4:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
_080C56FE:
	movs r0, 0
_080C5700:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C5484

	thumb_func_start sub_80C570C
sub_80C570C: @ 80C570C
	push {lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02039CEC
	ldr r0, [r1]
	ldrh r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0x5
	bhi _080C57E4
	lsls r0, 2
	ldr r1, =_080C5730
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C5730:
	.4byte _080C5748
	.4byte _080C5770
	.4byte _080C577C
	.4byte _080C57A6
	.4byte _080C57AC
	.4byte _080C57BE
_080C5748:
	ldr r0, [r2]
	ldrb r0, [r0, 0xE]
	movs r1, 0xE
	ands r1, r0
	cmp r1, 0x2
	beq _080C576A
	cmp r1, 0x4
	beq _080C576A
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _080C57E4
_080C576A:
	ldr r1, [r2]
	movs r0, 0x2
	b _080C57EC
_080C5770:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _080C57E4
	b _080C57EE
_080C577C:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	b _080C57E4
_080C57A6:
	bl sub_80C63FC
	b _080C57E4
_080C57AC:
	bl sub_80C50D0
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	b _080C57E4
_080C57BE:
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	bl sub_80C5340
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x4]
	movs r0, 0x1
	b _080C57F0
	.pool
_080C57E4:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
_080C57EC:
	strh r0, [r1, 0x4]
_080C57EE:
	movs r0, 0
_080C57F0:
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C570C

	thumb_func_start sub_80C57FC
sub_80C57FC: @ 80C57FC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
	ldr r7, =gUnknown_08571454
	lsls r1, 16
	asrs r5, r1, 16
_080C580A:
	lsls r0, r4, 3
	adds r3, r0, r7
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, r5
	bgt _080C5854
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r5
	blt _080C5854
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	lsls r0, r6, 16
	asrs r2, r0, 16
	cmp r1, r2
	bgt _080C5854
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r0, r2
	blt _080C5854
	cmp r4, 0x5
	bls _080C5842
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080C585E
_080C5842:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	b _080C5860
	.pool
_080C5854:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xC
	bls _080C580A
_080C585E:
	movs r0, 0
_080C5860:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80C57FC

	thumb_func_start sub_80C5868
sub_80C5868: @ 80C5868
	push {lr}
	bl sub_80C5484
	cmp r0, 0
	beq _080C58C6
	ldr r1, =gUnknown_02039CEC
	ldr r0, [r1]
	ldrb r0, [r0, 0xE]
	lsls r0, 28
	lsrs r0, 29
	cmp r0, 0x1
	blt _080C58AC
	cmp r0, 0x2
	bgt _080C58AC
	ldr r0, =sub_80C5BD8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	b _080C58C0
	.pool
_080C58AC:
	ldr r2, [r1]
	ldrb r1, [r2, 0xE]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xE]
	ldr r0, =sub_80C5A48
	movs r1, 0
	bl CreateTask
_080C58C0:
	ldr r0, =sub_80C5438
	bl SetMainCallback2
_080C58C6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5868

	thumb_func_start sub_80C58D4
sub_80C58D4: @ 80C58D4
	push {r4,lr}
	ldr r4, =gUnknown_02039CF8
	ldr r0, [r4]
	bl sub_80C51F0
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r4, 0x4]
	strh r0, [r1, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	bl InBattlePyramid
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080C5914
	cmp r0, 0x2
	beq _080C591C
	bl Overworld_PlaySpecialMapMusic
	b _080C5924
	.pool
_080C5914:
	ldr r0, =0x000001cd
	b _080C5920
	.pool
_080C591C:
	movs r0, 0xE7
	lsls r0, 1
_080C5920:
	bl PlayBGM
_080C5924:
	ldr r0, =sub_80C5868
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C58D4

	thumb_func_start sub_80C5934
sub_80C5934: @ 80C5934
	push {lr}
	bl sub_80C570C
	cmp r0, 0
	beq _080C599A
	ldr r0, =gUnknown_02039CEC
	ldr r2, [r0]
	ldrb r0, [r2, 0xE]
	lsls r0, 28
	lsrs r0, 29
	cmp r0, 0x2
	beq _080C5994
	cmp r0, 0x2
	bgt _080C595C
	cmp r0, 0x1
	beq _080C5962
	b _080C599A
	.pool
_080C595C:
	cmp r0, 0x3
	beq _080C5970
	b _080C599A
_080C5962:
	ldr r0, =sub_80C5868
	bl sub_80C6454
	b _080C599A
	.pool
_080C5970:
	ldr r1, =gUnknown_02039CF8
	ldr r0, [r2]
	str r0, [r1]
	ldrh r0, [r2, 0x8]
	strh r0, [r1, 0x4]
	ldrh r0, [r2, 0xA]
	strh r0, [r1, 0x6]
	bl sub_80C52E4
	ldr r0, =sub_80C58D4
	bl PlayRecordedBattle
	b _080C599A
	.pool
_080C5994:
	ldr r0, =sub_80C5868
	bl ShowPlayerTrainerCard
_080C599A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5934

	thumb_func_start sub_80C59A4
sub_80C59A4: @ 80C59A4
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, r3, 0
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0x1
	blt _080C59CC
	cmp r1, 0x2
	ble _080C59F4
	cmp r1, 0x3
	bne _080C59CC
	ldr r0, =gUnknown_02039CEC
	ldr r2, [r0]
	ldrb r1, [r2, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080C59D4
_080C59CC:
	movs r0, 0
	b _080C5A30
	.pool
_080C59D4:
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	movs r1, 0x6
	orrs r0, r1
	strb r0, [r2, 0xE]
	adds r0, r3, 0
	bl DestroyTask
	ldr r0, =sub_80C5934
	bl SetMainCallback2
	b _080C5A1A
	.pool
_080C59F4:
	ldr r0, =gUnknown_02039CEC
	ldr r3, [r0]
	movs r0, 0x7
	ands r2, r0
	lsls r2, 1
	ldrb r1, [r3, 0xE]
	subs r0, 0x16
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0xE]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80C5BD8
	str r1, [r0]
	movs r1, 0
	strh r1, [r0, 0x8]
_080C5A1A:
	ldr r0, =gUnknown_02039CEC
	ldr r2, [r0]
	ldr r0, =gUnknown_02039CF0
	ldr r1, [r0]
	ldr r0, [r1]
	ldrh r0, [r0, 0x20]
	strh r0, [r2, 0x8]
	ldr r0, [r1]
	ldrh r0, [r0, 0x22]
	strh r0, [r2, 0xA]
	movs r0, 0x1
_080C5A30:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C59A4

	thumb_func_start sub_80C5A48
sub_80C5A48: @ 80C5A48
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C5A80
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x22]
	movs r7, 0x22
	ldrsh r0, [r1, r7]
	cmp r0, 0x8
	ble _080C5A80
	subs r0, r3, 0x2
	strh r0, [r1, 0x22]
	ldr r1, [r4]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x7
	bgt _080C5A7E
	movs r0, 0x2
	strh r0, [r1, 0x22]
_080C5A7E:
	movs r5, 0x1
_080C5A80:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C5AAE
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x22]
	movs r7, 0x22
	ldrsh r0, [r1, r7]
	cmp r0, 0x87
	bgt _080C5AAE
	adds r0, r3, 0x2
	strh r0, [r1, 0x22]
	ldr r1, [r4]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x88
	ble _080C5AAC
	movs r0, 0x88
	strh r0, [r1, 0x22]
_080C5AAC:
	movs r5, 0x1
_080C5AAE:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080C5ADC
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x20]
	movs r7, 0x20
	ldrsh r0, [r1, r7]
	cmp r0, 0x5
	ble _080C5ADC
	subs r0, r3, 0x2
	strh r0, [r1, 0x20]
	ldr r1, [r4]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x4
	bgt _080C5ADA
	movs r0, 0x5
	strh r0, [r1, 0x20]
_080C5ADA:
	movs r5, 0x1
_080C5ADC:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080C5B0A
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x20]
	movs r7, 0x20
	ldrsh r0, [r1, r7]
	cmp r0, 0xE7
	bgt _080C5B0A
	adds r0, r3, 0x2
	strh r0, [r1, 0x20]
	ldr r1, [r4]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0xE8
	ble _080C5B08
	movs r0, 0xE8
	strh r0, [r1, 0x20]
_080C5B08:
	movs r5, 0x1
_080C5B0A:
	cmp r5, 0
	bne _080C5B88
	ldr r4, =gUnknown_02039CEC
	ldr r0, [r4]
	ldrb r3, [r0, 0xC]
	cmp r3, 0
	beq _080C5B5E
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C5B5E
	cmp r3, 0x3
	bhi _080C5B48
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	adds r0, r6, 0
	bl sub_80C59A4
	cmp r0, 0
	bne _080C5BCA
	b _080C5B5E
	.pool
_080C5B48:
	cmp r3, 0x4
	bne _080C5B5E
	movs r0, 0x3
	bl PlaySE
	ldr r0, =sub_80C5470
	bl SetMainCallback2
	adds r0, r6, 0
	bl DestroyTask
_080C5B5E:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080C5BCA
	movs r0, 0x3
	bl PlaySE
	ldr r0, =sub_80C5470
	bl SetMainCallback2
	adds r0, r6, 0
	bl DestroyTask
	b _080C5BCA
	.pool
_080C5B88:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0]
	ldrh r0, [r1, 0x20]
	subs r0, 0x5
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r1, 0x22]
	adds r1, 0x5
	lsls r1, 16
	asrs r1, 16
	bl sub_80C57FC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_02039CEC
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	cmp r0, r5
	beq _080C5BCA
	adds r0, r5, 0
	bl sub_80C5ED0
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	strb r0, [r1, 0xD]
	ldr r0, [r4]
	strb r5, [r0, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	ldrb r1, [r1, 0xD]
	bl sub_80C6104
_080C5BCA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5A48

	thumb_func_start sub_80C5BD8
sub_80C5BD8: @ 80C5BD8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r5, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r6, r5, r0
	ldr r7, =gUnknown_02039CEC
	ldr r0, [r7]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x1
	beq _080C5CD4
	cmp r0, 0x1
	bgt _080C5C0C
	cmp r0, 0
	beq _080C5C14
	b _080C5D9C
	.pool
_080C5C0C:
	cmp r0, 0x2
	bne _080C5C12
	b _080C5D2A
_080C5C12:
	b _080C5D9C
_080C5C14:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080C5C4C
	movs r0, 0x1
	movs r1, 0
	bl sub_80C5F58
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	strh r0, [r6, 0x2]
	strh r0, [r6, 0x4]
	movs r0, 0x15
	strh r0, [r6, 0x6]
	strh r0, [r6, 0x8]
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _080C5CA4
	.pool
_080C5C4C:
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r1, 0
	strh r0, [r6, 0x2]
	strh r0, [r6, 0x4]
	movs r1, 0x15
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r6, 0x6]
	strh r0, [r6, 0x8]
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
	bl sub_80C62DC
	ldr r0, =pokemon_details
	bl SetVBlankCallback
	movs r5, 0x1
	negs r5, r5
	ldr r4, =0x00007fff
	adds r0, r5, 0
	movs r1, 0x10
	adds r2, r4, 0
	bl BlendPalettes
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_080C5CA4:
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r1, [r4]
	strh r0, [r1, 0x2E]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r1, [r4]
	strh r0, [r1, 0x30]
	b _080C5D9C
	.pool
_080C5CD4:
	bl UpdatePaletteFade
	ldrh r0, [r6, 0x6]
	ldrh r1, [r6, 0x2]
	adds r0, r1
	strh r0, [r6, 0x2]
	ldrh r0, [r6, 0x8]
	ldrh r1, [r6, 0x4]
	adds r0, r1
	strh r0, [r6, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r4, =gUnknown_02039CF0
	ldr r1, [r4]
	strh r0, [r1, 0x2E]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r1, [r4]
	strh r0, [r1, 0x30]
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080C5D1C
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	movs r0, 0xFE
	lsls r0, 1
	cmp r1, r0
	ble _080C5DA6
	b _080C5D9C
	.pool
_080C5D1C:
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _080C5DA6
	b _080C5D9C
_080C5D2A:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x2C
	ldrb r0, [r1]
	cmp r0, 0
	beq _080C5D3C
	movs r0, 0
	strb r0, [r1]
_080C5D3C:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C5DA6
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080C5D64
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =sub_80C5934
	bl SetMainCallback2
	b _080C5D82
	.pool
_080C5D64:
	movs r0, 0
	movs r1, 0
	bl sub_80C5F58
	ldr r2, [r7]
	ldrb r1, [r2, 0xE]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xE]
	mov r0, r8
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_80C5A48
	str r1, [r0]
_080C5D82:
	movs r0, 0x2
	movs r1, 0x6
	movs r2, 0
	bl SetBgAttribute
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	movs r0, 0
	b _080C5DA4
	.pool
_080C5D9C:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
_080C5DA4:
	strh r0, [r1, 0x4]
_080C5DA6:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5BD8

	thumb_func_start sub_80C5DB8
sub_80C5DB8: @ 80C5DB8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	movs r4, 0
_080C5DC2:
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _080C5DC2
	ldr r4, =gText_SymbolsEarned
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r6, =gUnknown_08571448
	str r6, [sp]
	movs r0, 0
	mov r8, r0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x5
	bl AddTextPrinterParameterized3
	ldr r4, =gText_BattleRecord
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x5
	bl AddTextPrinterParameterized3
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	ldr r0, =gText_BattlePoints
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x8
	movs r2, 0x5
	movs r3, 0x4
	bl AddTextPrinterParameterized3
	ldr r4, =gStringVar4
	ldr r5, =gUnknown_02039CEC
	ldr r0, [r5]
	ldrh r1, [r0, 0x6]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	movs r0, 0x8
	adds r1, r4, 0
	movs r2, 0x5B
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x8
	movs r3, 0x10
	bl AddTextPrinterParameterized3
	ldr r1, [r5]
	ldrh r0, [r1, 0x8]
	subs r0, 0x5
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r1, 0xA]
	adds r1, 0x5
	lsls r1, 16
	asrs r1, 16
	bl sub_80C57FC
	ldr r1, [r5]
	strb r0, [r1, 0xC]
	ldr r0, [r5]
	mov r1, r8
	strb r1, [r0, 0xD]
	ldr r0, [r5]
	ldrb r0, [r0, 0xC]
	bl sub_80C5ED0
	movs r4, 0
_080C5E92:
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _080C5E92
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5DB8

	thumb_func_start sub_80C5ED0
sub_80C5ED0: @ 80C5ED0
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x3
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0x3
	bne _080C5F18
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _080C5F18
	ldr r0, =gUnknown_0857144B
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_08571614
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0
	bl AddTextPrinterParameterized3
	b _080C5F3A
	.pool
_080C5F18:
	cmp r4, 0
	beq _080C5F3A
	ldr r0, =gUnknown_0857144B
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08571614
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0
	bl AddTextPrinterParameterized3
_080C5F3A:
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5ED0

	thumb_func_start sub_80C5F58
sub_80C5F58: @ 80C5F58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	lsls r0, 28
	lsrs r0, 29
	cmp r0, 0x1
	beq _080C5F80
	cmp r0, 0x2
	beq _080C5FC2
	b _080C60EE
	.pool
_080C5F80:
	cmp r2, 0
	beq _080C5FA8
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x20]
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0x10
	movs r3, 0x3
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C6004
	.pool
_080C5FA8:
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x3
	bl FillBgTilemapBufferRect
	b _080C6004
_080C5FC2:
	cmp r2, 0
	beq _080C5FEC
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x20]
	adds r1, 0x54
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0x10
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C6004
	.pool
_080C5FEC:
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x10
	movs r3, 0xA
	bl FillBgTilemapBufferRect
_080C6004:
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	cmp r7, 0
	beq _080C6084
	movs r4, 0xFE
	lsls r4, 1
	adds r0, r4, 0
	bl sub_8151624
	adds r6, r0, 0
	lsls r6, 16
	asrs r6, 16
	adds r0, r4, 0
	bl sub_8151624
	lsls r0, 16
	asrs r0, 16
	ldr r5, =gUnknown_085713E0
	ldr r1, =gUnknown_02039CEC
	ldr r1, [r1]
	ldrb r4, [r1, 0xE]
	lsls r4, 28
	lsrs r1, r4, 29
	subs r1, 0x1
	lsls r1, 2
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 8
	lsrs r2, r4, 29
	subs r2, 0x1
	lsls r2, 2
	adds r3, r5, 0x2
	mov r8, r3
	add r2, r8
	movs r3, 0
	ldrsh r2, [r2, r3]
	lsls r2, 8
	lsrs r3, r4, 29
	subs r3, 0x1
	lsls r3, 2
	adds r3, r5
	movs r5, 0
	ldrsh r3, [r3, r5]
	lsrs r4, 29
	subs r4, 0x1
	lsls r4, 2
	add r4, r8
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	str r6, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	bl SetBgAffine
	b _080C60EE
	.pool
_080C6084:
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	bl sub_8151624
	adds r6, r0, 0
	lsls r6, 16
	asrs r6, 16
	adds r0, r4, 0
	bl sub_8151624
	lsls r0, 16
	asrs r0, 16
	ldr r5, =gUnknown_085713E0
	ldr r1, =gUnknown_02039CEC
	ldr r1, [r1]
	ldrb r4, [r1, 0xE]
	lsls r4, 28
	lsrs r1, r4, 29
	subs r1, 0x1
	lsls r1, 2
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 8
	lsrs r2, r4, 29
	subs r2, 0x1
	lsls r2, 2
	adds r3, r5, 0x2
	mov r8, r3
	add r2, r8
	movs r3, 0
	ldrsh r2, [r2, r3]
	lsls r2, 8
	lsrs r3, r4, 29
	subs r3, 0x1
	lsls r3, 2
	adds r3, r5
	movs r5, 0
	ldrsh r3, [r3, r5]
	lsrs r4, 29
	subs r4, 0x1
	lsls r4, 2
	add r4, r8
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	str r6, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r0, 0x2
	bl SetBgAffine
_080C60EE:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5F58

	thumb_func_start sub_80C6104
sub_80C6104: @ 80C6104
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r5, 0x2
	beq _080C614C
	cmp r5, 0x2
	bgt _080C611E
	cmp r5, 0x1
	beq _080C6128
	b _080C61C4
_080C611E:
	cmp r5, 0x3
	beq _080C6170
	cmp r5, 0x4
	beq _080C61A4
	b _080C61C4
_080C6128:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	movs r3, 0x3
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C61CE
	.pool
_080C614C:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	movs r0, 0xA8
	lsls r0, 1
	adds r1, r0
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	b _080C6192
	.pool
_080C6170:
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r1, [r0, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C61C4
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x28]
	movs r0, 0xC
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x2
_080C6192:
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C61CE
	.pool
_080C61A4:
	ldr r1, =gUnknown_08DE3350
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x15
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C61CE
	.pool
_080C61C4:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080C6294
_080C61CE:
	cmp r4, 0x2
	beq _080C620C
	cmp r4, 0x2
	bgt _080C61DC
	cmp r4, 0x1
	beq _080C61E6
	b _080C6284
_080C61DC:
	cmp r4, 0x3
	beq _080C6230
	cmp r4, 0x4
	beq _080C6264
	b _080C6284
_080C61E6:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	adds r1, 0xA8
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	movs r3, 0x3
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C628E
	.pool
_080C620C:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	movs r0, 0xFC
	lsls r0, 1
	adds r1, r0
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	b _080C6254
	.pool
_080C6230:
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r1, [r0, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C6294
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x28]
	adds r1, 0x48
	movs r0, 0xC
	str r0, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x2
_080C6254:
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C628E
	.pool
_080C6264:
	ldr r1, =gUnknown_08DE3374
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x15
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C628E
	.pool
_080C6284:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080C6294
_080C628E:
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_080C6294:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80C6104

	thumb_func_start sub_80C629C
sub_80C629C: @ 80C629C
	push {r4,lr}
	ldr r1, =gUnknown_08DE3060
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r4, =gUnknown_02039CEC
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	ldrb r1, [r1, 0xD]
	bl sub_80C6104
	ldr r0, [r4]
	ldrb r1, [r0, 0xE]
	lsls r1, 28
	lsrs r1, 29
	movs r0, 0x1
	bl sub_80C5F58
	bl sub_80C5DB8
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C629C

	thumb_func_start sub_80C62DC
sub_80C62DC: @ 80C62DC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	movs r5, 0
	bl FreeAllSpritePalettes
	bl ResetAffineAnimData
	ldr r0, =gUnknown_085714E4
	bl LoadSpritePalettes
	ldr r4, =gUnknown_085714BC
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x10
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_085715B4
	ldr r1, =gUnknown_02039CEC
	ldr r2, [r1]
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	movs r6, 0xA
	ldrsh r2, [r2, r6]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_02039CF0
	ldr r2, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	mov r8, sp
	mov r9, r3
_080C633C:
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	adds r0, 0xF
	adds r2, r0, r5
	ldrb r0, [r2]
	adds r4, r5, 0x1
	cmp r0, 0
	beq _080C63C2
	mov r1, sp
	ldr r0, =gUnknown_085715E4
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	mov r7, r8
	ldrh r0, [r7, 0x2]
	ldr r1, =0x0000ffff
	adds r0, r1
	ldrb r2, [r2]
	adds r0, r2
	strh r0, [r7, 0x2]
	ldr r1, =gUnknown_08571454
	adds r0, r5, 0x6
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x4]
	adds r1, 0x8
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r0]
	adds r2, 0x6
	lsls r2, 16
	asrs r2, 16
	lsls r3, r4, 24
	lsrs r3, 24
	mov r0, sp
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r3, r9
	ldr r2, [r3]
	lsls r3, r5, 2
	adds r2, 0x4
	adds r2, r3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	ldrb r2, [r1, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r2, r0
	movs r0, 0x8
	orrs r2, r0
	strb r2, [r1, 0x5]
	mov r7, r9
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r3
	ldr r0, [r0]
	adds r1, r5, 0
	bl StartSpriteAnim
_080C63C2:
	lsls r0, r4, 24
	lsrs r5, r0, 24
	cmp r5, 0x6
	bls _080C633C
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C62DC

	thumb_func_start sub_80C63FC
sub_80C63FC: @ 80C63FC
	push {r4-r6,lr}
	movs r5, 0
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r4]
	str r5, [r0]
	adds r6, r4, 0
_080C6410:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0x4
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080C642C
	bl DestroySprite
	ldr r0, [r6]
	adds r0, 0x4
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080C642C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x6
	bls _080C6410
	bl FreeAllSpritePalettes
	movs r0, 0x2
	bl FreeSpriteTilesByTag
	movs r0, 0
	bl FreeSpriteTilesByTag
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C63FC

	thumb_func_start nullsub_39
nullsub_39: @ 80C6450
	bx lr
	thumb_func_end nullsub_39

	thumb_func_start sub_80C6454
sub_80C6454: @ 80C6454
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02039CF4
	ldr r0, [r5]
	cmp r0, 0
	beq _080C6466
	adds r0, r4, 0
	bl SetMainCallback2
_080C6466:
	ldr r0, =0x00003014
	bl AllocZeroed
	str r0, [r5]
	str r4, [r0]
	bl ResetTasks
	ldr r0, =sub_80C67BC
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_80C5438
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6454

	thumb_func_start sub_80C6498
sub_80C6498: @ 80C6498
	push {r4,lr}
	bl ResetTasks
	ldr r4, =gUnknown_02039CF4
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	ldr r2, =0x00003014
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6498

	thumb_func_start sub_80C64CC
sub_80C64CC: @ 80C64CC
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x7
	bls _080C64DC
	b _080C6694
_080C64DC:
	lsls r0, 2
	ldr r1, =_080C64F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C64F0:
	.4byte _080C6510
	.4byte _080C6520
	.4byte _080C6526
	.4byte _080C6538
	.4byte _080C65C0
	.4byte _080C65E8
	.4byte _080C6628
	.4byte _080C6678
_080C6510:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	b _080C6694
_080C6520:
	bl sub_80C50D0
	b _080C6694
_080C6526:
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl reset_temp_tile_data_buffers
	b _080C6694
_080C6538:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085713F4
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_02039CF4
	ldr r1, [r4]
	adds r1, 0x12
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001012
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00002012
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
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
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _080C6618
	.pool
_080C65C0:
	ldr r0, =gUnknown_08571428
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl sub_80C6B94
	ldr r1, =gUnknown_0856FBBC
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _080C6694
	.pool
_080C65E8:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _080C669E
	ldr r0, =gUnknown_08DE07C8
	movs r2, 0xD0
	lsls r2, 1
	movs r1, 0
	bl LoadPalette
	movs r0, 0
	bl stdpal_get
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_08570E00
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
_080C6618:
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _080C6694
	.pool
_080C6628:
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
	bl sub_80C6974
	ldr r0, =pokemon_details
	bl SetVBlankCallback
	movs r5, 0x1
	negs r5, r5
	ldr r4, =0x00007fff
	adds r0, r5, 0
	movs r1, 0x10
	adds r2, r4, 0
	bl BlendPalettes
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _080C6694
	.pool
_080C6678:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080C669E
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	strh r1, [r0, 0x4]
	movs r0, 0x1
	b _080C66A0
	.pool
_080C6694:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
_080C669E:
	movs r0, 0
_080C66A0:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C64CC

	thumb_func_start sub_80C66AC
sub_80C66AC: @ 80C66AC
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x5
	bhi _080C67A4
	lsls r0, 2
	ldr r1, =_080C66CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C66CC:
	.4byte _080C66E4
	.4byte _080C66FC
	.4byte _080C6722
	.4byte _080C6732
	.4byte _080C6774
	.4byte _080C6782
_080C66E4:
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _080C67A4
	.pool
_080C66FC:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C67AE
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	b _080C67A4
_080C6722:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	b _080C67A4
_080C6732:
	ldr r4, =gUnknown_02039CF4
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	cmp r0, 0
	beq _080C6746
	bl DestroySprite
	movs r0, 0
	bl FreeSpriteTilesByTag
_080C6746:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	cmp r0, 0
	beq _080C6758
	bl DestroySprite
	movs r0, 0x1
	bl FreeSpriteTilesByTag
_080C6758:
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _080C676A
	bl DestroySprite
	movs r0, 0x4
	bl FreeSpriteTilesByTag
_080C676A:
	bl FreeAllWindowBuffers
	b _080C67A4
	.pool
_080C6774:
	bl sub_80C50D0
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	b _080C67A4
_080C6782:
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x4]
	movs r0, 0x1
	b _080C67B0
	.pool
_080C67A4:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
_080C67AE:
	movs r0, 0
_080C67B0:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C66AC

	thumb_func_start sub_80C67BC
sub_80C67BC: @ 80C67BC
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bls _080C67D6
	b _080C68DA
_080C67D6:
	lsls r0, 2
	ldr r1, =_080C67E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C67E8:
	.4byte _080C6800
	.4byte _080C6806
	.4byte _080C686C
	.4byte _080C6894
	.4byte _080C68C4
	.4byte _080C68CE
_080C6800:
	bl sub_80C64CC
	b _080C68C8
_080C6806:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x2
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080C6824
	movs r0, 0x3
	bl PlaySE
	movs r0, 0x4
	b _080C68DE
	.pool
_080C6824:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C6848
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x5
	bls _080C6844
	movs r0, 0
	bl sub_80C6C70
	b _080C68E0
	.pool
_080C6844:
	strh r2, [r4]
	b _080C68E0
_080C6848:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C68E0
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _080C6868
	movs r0, 0x1
	bl sub_80C6C70
	b _080C68E0
	.pool
_080C6868:
	movs r0, 0x3
	b _080C68DE
_080C686C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _080C6882
	movs r0, 0
	bl sub_80C6C70
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x1
	b _080C68DE
_080C6882:
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldrh r0, [r1, 0x22]
	adds r0, 0x4
	b _080C68B4
	.pool
_080C6894:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _080C68AA
	movs r0, 0x1
	bl sub_80C6C70
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x1
	b _080C68DE
_080C68AA:
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldrh r0, [r1, 0x22]
	subs r0, 0x4
_080C68B4:
	strh r0, [r1, 0x22]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _080C68E0
	.pool
_080C68C4:
	bl sub_80C66AC
_080C68C8:
	cmp r0, 0
	bne _080C68DA
	b _080C68E0
_080C68CE:
	adds r0, r2, 0
	bl DestroyTask
	bl sub_80C6498
	b _080C68E0
_080C68DA:
	ldrh r0, [r4]
	adds r0, 0x1
_080C68DE:
	strh r0, [r4]
_080C68E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80C67BC

	thumb_func_start sub_80C68E8
sub_80C68E8: @ 80C68E8
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xfffb0000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0x3
	bls _080C6904
	adds r0, r1, 0
	subs r0, 0xF
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C690C
_080C6904:
	movs r0, 0x1
	b _080C696E
	.pool
_080C690C:
	adds r0, r1, 0
	subs r0, 0x12
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080C691C
	movs r0, 0x2
	b _080C696E
_080C691C:
	adds r0, r1, 0
	subs r0, 0x16
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C692C
	movs r0, 0x3
	b _080C696E
_080C692C:
	adds r0, r1, 0
	subs r0, 0x1C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C693C
	movs r0, 0x4
	b _080C696E
_080C693C:
	adds r0, r1, 0
	subs r0, 0x1F
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C694C
	movs r0, 0x5
	b _080C696E
_080C694C:
	adds r0, r1, 0
	subs r0, 0x22
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _080C695C
	movs r0, 0x6
	b _080C696E
_080C695C:
	adds r0, r1, 0
	subs r0, 0x19
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080C696C
	movs r0, 0
	b _080C696E
_080C696C:
	movs r0, 0x7
_080C696E:
	pop {r1}
	bx r1
	thumb_func_end sub_80C68E8

	thumb_func_start sub_80C6974
sub_80C6974: @ 80C6974
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	movs r7, 0
	bl FreeAllSpritePalettes
	ldr r0, =gUnknown_085714E4
	bl LoadSpritePalettes
	ldr r6, =gUnknown_085714BC
	adds r0, r6, 0
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_085715B4
	mov r8, r0
	ldr r4, =gUnknown_02039CF4
	ldr r0, [r4]
	ldrb r2, [r0, 0x10]
	lsls r2, 4
	adds r2, 0x8
	mov r0, r8
	movs r1, 0x9B
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, [r4]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	ldr r2, =gSprites
	mov r9, r2
	add r1, r9
	str r1, [r0, 0x4]
	ldrb r2, [r1, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r0, r5, 0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, 0x3F
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0x1
	bl StartSpriteAnim
	adds r6, 0x8
	adds r0, r6, 0
	bl LoadCompressedSpriteSheet
	movs r3, 0x18
	add r8, r3
	ldr r6, =gUnknown_08571650
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	lsls r0, 4
	adds r0, r6
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r3, 0xA
	ldrsh r2, [r0, r3]
	mov r0, r8
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, [r4]
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	add r0, r9
	str r0, [r1, 0xC]
	ldrb r1, [r0, 0x5]
	ands r5, r1
	strb r5, [r0, 0x5]
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	ldrb r1, [r1, 0x10]
	lsls r1, 4
	adds r1, r6
	ldrb r1, [r1, 0xC]
	bl StartSpriteAnim
	bl GetCurrentRegionMapSectionId
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3A
	beq _080C6A40
	cmp r5, 0xCA
	beq _080C6A40
	b _080C6B7A
_080C6A40:
	ldr r4, =gSaveBlock1Ptr
	ldr r2, [r4]
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, 0x4
	beq _080C6A52
	cmp r0, 0xE
	bne _080C6A98
	movs r7, 0x37
_080C6A52:
	lsls r0, r7, 16
	asrs r0, 16
	ldrh r6, [r2]
	adds r0, r6
	ldrh r4, [r2, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6A66
	adds r0, 0x7
_080C6A66:
	lsls r0, 13
	lsrs r7, r0, 16
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6A74
	adds r0, 0x7
_080C6A74:
	lsls r0, 13
	lsrs r4, r0, 16
	movs r5, 0
	b _080C6AF2
	.pool
_080C6A98:
	lsls r0, 16
	lsrs r0, 16
	bl sub_80C68E8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _080C6AB4
	subs r0, r5, 0x1
	lsls r0, 4
	adds r0, r6
	ldrh r7, [r0, 0x8]
	ldrh r4, [r0, 0xA]
	b _080C6AF2
_080C6AB4:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x25
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xE
	bne _080C6ACE
	ldrh r0, [r1, 0x28]
	adds r0, 0x37
	lsls r0, 16
	lsrs r7, r0, 16
	b _080C6AD0
_080C6ACE:
	ldrh r7, [r1, 0x28]
_080C6AD0:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r4, [r0, 0x2A]
	lsls r0, r7, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6AE0
	adds r0, 0x7
_080C6AE0:
	lsls r0, 13
	lsrs r7, r0, 16
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6AEE
	adds r0, 0x7
_080C6AEE:
	lsls r0, 13
	lsrs r4, r0, 16
_080C6AF2:
	ldr r0, =gUnknown_085714D4
	bl LoadCompressedSpriteSheet
	mov r1, sp
	ldr r0, =gUnknown_085715FC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	mov r1, sp
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	adds r0, 0x4
	strh r0, [r1, 0x2]
	cmp r5, 0
	beq _080C6B2C
	lsls r1, r7, 16
	asrs r1, 16
	lsls r2, r4, 16
	b _080C6B3E
	.pool
_080C6B2C:
	lsls r1, r7, 19
	lsls r2, r4, 19
	movs r0, 0xA0
	lsls r0, 13
	adds r1, r0
	asrs r1, 16
	movs r3, 0x90
	lsls r3, 14
	adds r2, r3
_080C6B3E:
	asrs r2, 16
	mov r0, sp
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =gUnknown_02039CF4
	ldr r2, [r4]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2, 0x8]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _080C6B7A
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r1, 0x1
	bl StartSpriteAnim
_080C6B7A:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6974

	thumb_func_start sub_80C6B94
sub_80C6B94: @ 80C6B94
	push {r4-r6,lr}
	sub sp, 0xC
	movs r4, 0
_080C6B9A:
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C6B9A
	movs r4, 0
	movs r6, 0
	ldr r5, =gUnknown_08571650
_080C6BB8:
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r4, r0
	bne _080C6BF0
	lsls r1, r4, 4
	adds r3, r1, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0857144E
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	b _080C6C0E
	.pool
_080C6BF0:
	lsls r1, r4, 4
	adds r3, r1, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0857144B
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
_080C6C0E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080C6BB8
	ldr r0, =gUnknown_08571448
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08571650
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	lsls r0, 4
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0
	bl AddTextPrinterParameterized3
	movs r4, 0
_080C6C40:
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C6C40
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6B94

	thumb_func_start sub_80C6C70
sub_80C6C70: @ 80C6C70
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	lsls r0, 24
	cmp r0, 0
	beq _080C6C8C
	ldr r0, =gUnknown_02039CF4
	ldr r4, [r0]
	ldrb r5, [r4, 0x10]
	adds r0, r5, 0x6
	b _080C6C94
	.pool
_080C6C8C:
	ldr r0, =gUnknown_02039CF4
	ldr r4, [r0]
	ldrb r5, [r4, 0x10]
	adds r0, r5, 0x1
_080C6C94:
	movs r1, 0x7
	bl __modsi3
	strb r0, [r4, 0x10]
	lsls r0, r5, 4
	adds r3, r0, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r6, =gUnknown_0857144B
	str r6, [sp]
	movs r1, 0
	mov r8, r1
	str r1, [sp, 0x4]
	ldr r4, =gUnknown_08571650
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	ldr r5, =gUnknown_02039CF4
	ldr r1, [r5]
	ldrb r3, [r1, 0x10]
	lsls r3, 4
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0x3
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, 0x8
	strh r0, [r2, 0x22]
	ldr r0, [r1, 0xC]
	ldrb r1, [r1, 0x10]
	lsls r1, 4
	adds r1, r4
	ldrb r1, [r1, 0xC]
	bl StartSpriteAnim
	ldr r1, [r5]
	ldr r2, [r1, 0xC]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, r4
	ldrh r0, [r0, 0x8]
	strh r0, [r2, 0x20]
	ldr r2, [r1, 0xC]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, r4
	ldrh r0, [r0, 0xA]
	strh r0, [r2, 0x22]
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	subs r6, 0x3
	str r6, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	ldr r0, [r5]
	ldrb r0, [r0, 0x10]
	lsls r0, 4
	adds r4, 0x4
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0
	bl AddTextPrinterParameterized3
	movs r4, 0
_080C6D4A:
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C6D4A
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x6C
	bl PlaySE
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6C70

	thumb_func_start sub_80C6D80
sub_80C6D80: @ 80C6D80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp, 0x24]
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x28]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x1C]
	str r1, [sp, 0x20]
	ldr r1, =0x00ffffff
	ldr r0, [sp, 0x1C]
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 21
	orrs r0, r1
	str r0, [sp, 0x1C]
	ldr r1, =0xffffff00
	add r5, sp, 0x1C
	ldr r0, [r5, 0x4]
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	str r0, [r5, 0x4]
	adds r0, r5, 0
	bl AddWindow
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r4, r0, 24
	lsrs r4, 24
	mov r0, r9
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	movs r1, 0x7
	bl GetWindowAttribute
	adds r6, r0, 0
	ldrb r0, [r5, 0x3]
	lsls r0, 5
	adds r0, r6
	mov r8, r0
	ldr r1, [sp, 0x28]
	cmp r1, 0
	bne _080C6E04
	add r0, sp, 0x14
	b _080C6E08
	.pool
_080C6E04:
	add r0, sp, 0x14
	mov r1, r9
_080C6E08:
	strb r1, [r0]
	add r1, sp, 0x14
	movs r2, 0
	movs r0, 0xF
	strb r0, [r1, 0x1]
	movs r0, 0xE
	strb r0, [r1, 0x2]
	mov r0, r10
	lsls r4, r0, 24
	lsrs r0, r4, 24
	str r2, [sp]
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0xC]
	ldr r1, [sp, 0x24]
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	ldr r0, [sp, 0x4C]
	mov r10, r4
	cmp r0, 0x6
	bls _080C6E3E
	movs r0, 0x6
_080C6E3E:
	ldr r4, [sp, 0x4C]
	subs r4, 0x6
	cmp r0, 0
	ble _080C6E70
	adds r5, r0, 0
_080C6E48:
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x40
	bl CpuSet
	adds r1, r7, 0
	adds r1, 0x80
	mov r0, r8
	movs r2, 0x40
	bl CpuSet
	adds r6, 0x80
	movs r2, 0x80
	add r8, r2
	movs r0, 0x80
	lsls r0, 1
	adds r7, r0
	subs r5, 0x1
	cmp r5, 0
	bne _080C6E48
_080C6E70:
	cmp r4, 0
	ble _080C6E90
	add r0, sp, 0x18
	mov r2, r9
	lsls r1, r2, 4
	orrs r1, r2
	strh r1, [r0]
	lsls r2, r4, 7
	ldr r1, =0x001fffff
	ands r2, r1
	movs r1, 0x80
	lsls r1, 17
	orrs r2, r1
	adds r1, r7, 0
	bl CpuSet
_080C6E90:
	mov r1, r10
	lsrs r0, r1, 24
	bl RemoveWindow
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6D80

	thumb_func_start sub_80C6EAC
sub_80C6EAC: @ 80C6EAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	adds r6, r3, 0
	ldr r0, [sp, 0x4C]
	mov r9, r0
	ldr r1, [sp, 0x50]
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x28]
	lsls r6, 24
	lsrs r6, 24
	mov r2, r9
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	ldr r0, [sp, 0x20]
	bl StringLength_Multibyte
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp, 0x18]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x18]
	ldr r1, =0xffffff00
	add r2, sp, 0x18
	mov r8, r2
	ldr r0, [r2, 0x4]
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	str r0, [r2, 0x4]
	ldr r5, [sp, 0x18]
	lsrs r5, 24
	lsls r5, 5
	mov r0, r8
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, r6, 4
	orrs r1, r6
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	movs r1, 0x7
	bl GetWindowAttribute
	adds r7, r0, 0
	mov r0, r8
	ldrb r0, [r0, 0x3]
	lsls r0, 5
	mov r8, r0
	add r8, r7
	add r0, sp, 0x14
	movs r1, 0
	strb r6, [r0]
	mov r2, r9
	strb r2, [r0, 0x1]
	mov r2, r10
	strb r2, [r0, 0x2]
	str r1, [sp]
	str r1, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x20]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x2
	bl AddTextPrinterParameterized4
	lsrs r5, 1
	adds r0, r7, 0
	ldr r1, [sp, 0x24]
	adds r2, r5, 0
	bl CpuSet
	ldr r2, [sp, 0x24]
	ldr r0, [sp, 0x28]
	adds r1, r2, r0
	mov r0, r8
	adds r2, r5, 0
	bl CpuSet
	adds r0, r4, 0
	bl RemoveWindow
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6EAC

	.align 2, 0 @ Don't pad with nop.
