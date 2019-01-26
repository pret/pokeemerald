	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start ShowFrontierMap
ShowFrontierMap: @ 80C6454
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
	ldr r0, =CB2_FrontierPass
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowFrontierMap

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
	ldr r0, =VblankCb_FrontierPass
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
