	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




	thumb_func_start sub_81D8C38
sub_81D8C38: @ 81D8C38
	push {r4,lr}
	bl ResetVramOamAndBgCntRegs
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AD08
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =sRayScene
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000804
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001004
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl ResetAllBgsCoordinates
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8C38

	thumb_func_start sub_81D8CC4
sub_81D8CC4: @ 81D8CC4
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gRaySceneHushRing_Gfx
	movs r4, 0
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRaySceneHushBg_Gfx
	str r4, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D8CEA:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D8CEA
	ldr r0, =gRaySceneHushRing_Tilemap
	ldr r4, =sRayScene
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneHushBg_Tilemap
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gRaySceneHushRing_Map
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneHushBg_Pal
	movs r1, 0
	movs r2, 0x60
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0862AC28
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC30
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC38
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC40
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC48
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC50
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC58
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862AC60
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862AC68
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862AC70
	bl LoadCompressedObjectPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8CC4

	thumb_func_start sub_81D8DB4
sub_81D8DB4: @ 81D8DB4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	bl sub_81D8C38
	bl sub_81D8CC4
	bl sub_81D68C8
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl ClearGpuRegBits
	ldr r1, =0x00000241
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000e09
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81D8E80
	str r0, [r4]
	ldr r0, =sub_81D8FB0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x4]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0
	strh r2, [r0, 0x8]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0xA]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0xC]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0x1
	strh r2, [r0, 0xE]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0x10]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8DB4

	thumb_func_start sub_81D8E80
sub_81D8E80: @ 81D8E80
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r4, r7, r0
	movs r1, 0
	ldrsh r5, [r4, r1]
	cmp r5, 0x1
	beq _081D8EDE
	cmp r5, 0x1
	bgt _081D8EB0
	cmp r5, 0
	beq _081D8EBA
	b _081D8FA0
	.pool
_081D8EB0:
	cmp r5, 0x2
	beq _081D8F1E
	cmp r5, 0x3
	beq _081D8F84
	b _081D8FA0
_081D8EBA:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _081D8F18
	adds r0, r6, 0
	bl sub_81D90A8
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x2]
	b _081D8F30
_081D8EDE:
	ldr r2, =gSprites
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =sub_81D97E0
	cmp r1, r0
	bne _081D8FA0
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x40
	bne _081D8F18
	adds r0, r6, 0
	bl sub_81D94D4
	adds r0, r6, 0
	bl sub_81D93D8
	b _081D8F2C
	.pool
_081D8F18:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _081D8FA0
_081D8F1E:
	ldrh r2, [r4, 0x2]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	bne _081D8F38
_081D8F2C:
	movs r0, 0
	strh r0, [r4, 0x2]
_081D8F30:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D8FA0
_081D8F38:
	adds r0, r2, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r1, 0x90
	bl __modsi3
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	bne _081D8FA0
	ldr r0, =0x0000fffe
	ldr r1, =0x0000ffff
	str r1, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	b _081D8FA0
	.pool
_081D8F84:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_81D9034
	str r1, [r0]
_081D8FA0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8E80

	thumb_func_start sub_81D8FB0
sub_81D8FB0: @ 81D8FB0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _081D9024
	ldrh r1, [r4, 0x2]
	adds r1, 0xE
	lsls r1, 8
	movs r2, 0xF8
	lsls r2, 5
	adds r0, r2, 0
	ands r1, r0
	ldrh r0, [r4, 0x4]
	adds r0, 0x9
	movs r2, 0xF
	ands r0, r2
	orrs r1, r0
	movs r0, 0x52
	bl SetGpuReg
	ldrh r1, [r4, 0x2]
	ldrh r0, [r4, 0x6]
	subs r1, r0
	strh r1, [r4, 0x2]
	ldrh r0, [r4, 0x8]
	ldrh r2, [r4, 0x4]
	adds r0, r2
	strh r0, [r4, 0x4]
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	beq _081D9008
	cmp r1, 0
	bne _081D9010
_081D9008:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x6]
_081D9010:
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	beq _081D901C
	cmp r0, 0
	bne _081D9024
_081D901C:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x8]
_081D9024:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8FB0

	thumb_func_start sub_81D9034
sub_81D9034: @ 81D9034
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r7, =gTasks + 0x8
	adds r4, r6, r7
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081D90A0
	bl StopMapMusic
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D9078
	movs r0, 0
	bl SetVBlankCallback
	bl sub_81D6904
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldrb r0, [r4, 0x4]
	bl DestroyTask
_081D9078:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x20
	bne _081D909C
	strh r5, [r4, 0x2]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =Task_SetNextAnim
	str r1, [r0]
	b _081D90A0
	.pool
_081D909C:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
_081D90A0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9034

	thumb_func_start sub_81D90A8
sub_81D90A8: @ 81D90A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gUnknown_0862AC78
	movs r1, 0x40
	movs r2, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x6]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites + 0x2E
	mov r10, r1
	adds r7, r0, r1
	ldr r0, =gUnknown_0862AC90
	movs r1, 0x10
	movs r2, 0x82
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	movs r2, 0x2E
	negs r2, r2
	add r2, r10
	mov r8, r2
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	movs r2, 0x4
	mov r9, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r5, =gUnknown_0862ACA8
	adds r0, r5, 0
	movs r1, 0xA0
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x8]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r7, r0, r1
	adds r0, r5, 0
	movs r1, 0xC0
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	adds r0, r5, 0
	movs r1, 0xE0
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x2]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x1
	bl StartSpriteAnim
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x2
	bl StartSpriteAnim
	ldr r0, =gUnknown_0862ACC0
	movs r2, 0x41
	negs r2, r2
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r7, r0, r1
	ldr r0, =gUnknown_0862ACD8
	movs r2, 0x71
	negs r2, r2
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r1, [r0, 0x5]
	ands r6, r1
	orrs r6, r2
	strb r6, [r0, 0x5]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D90A8

	thumb_func_start sub_81D9274
sub_81D9274: @ 81D9274
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldr r3, =gSprites
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	movs r1, 0x1C
	adds r1, r3
	mov r8, r1
	add r0, r8
	ldr r6, =pokemon_alive_on_battle_side
	str r6, [r0]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r4, 0
	strh r4, [r0, 0x36]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x38]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r5, 0x4
	strh r5, [r0, 0x3A]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x3C]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r6, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x36]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x38]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r5, [r0, 0x3A]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x1
	strh r1, [r0, 0x3C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9274

	thumb_func_start pokemon_alive_on_battle_side
pokemon_alive_on_battle_side: @ 81D9338
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x36]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _081D93CC
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D9370
	ldrh r0, [r4, 0x20]
	ldrh r3, [r4, 0x3A]
	subs r0, r3
	strh r0, [r4, 0x20]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, r3
	b _081D939E
	.pool
_081D9370:
	ldrh r2, [r4, 0x3A]
	ldrh r1, [r4, 0x20]
	adds r0, r2, r1
	strh r0, [r4, 0x20]
	ldr r3, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x20]
	adds r2, r1
	strh r2, [r0, 0x20]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r4, 0x3A]
	ldrh r2, [r0, 0x20]
	adds r1, r2
_081D939E:
	strh r1, [r0, 0x20]
	ldrh r1, [r4, 0x38]
	adds r1, 0x1
	movs r2, 0
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	subs r0, r1
	strh r0, [r4, 0x3A]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3
	bne _081D93CC
	strh r2, [r4, 0x36]
	strh r2, [r4, 0x38]
	strh r2, [r4, 0x3A]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	b _081D93D2
	.pool
_081D93CC:
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
_081D93D2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemon_alive_on_battle_side

	thumb_func_start sub_81D93D8
sub_81D93D8: @ 81D93D8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldr r3, =gSprites
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81D9420
	str r1, [r0]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x1
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D93D8

	thumb_func_start sub_81D9420
sub_81D9420: @ 81D9420
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081D9488
	cmp r0, 0x1
	bgt _081D9436
	cmp r0, 0
	beq _081D9440
	b _081D94C4
_081D9436:
	cmp r0, 0x2
	beq _081D9440
	cmp r0, 0x3
	beq _081D9488
	b _081D94C4
_081D9440:
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0xC
	bl __umodsi3
	lsls r0, 24
	ldr r2, =gSprites
	cmp r0, 0
	bne _081D9470
	ldrh r0, [r4, 0x20]
	subs r0, 0x2
	strh r0, [r4, 0x20]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x2
	strh r1, [r0, 0x20]
_081D9470:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x26]
	b _081D94C4
	.pool
_081D9488:
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x26]
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	lsls r1, 26
	lsrs r1, 26
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _081D94C4
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x1
	strh r1, [r0, 0x22]
_081D94C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9420

	thumb_func_start sub_81D94D4
sub_81D94D4: @ 81D94D4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	movs r0, 0x8
	ldrsh r1, [r1, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r2, =gSprites + 0x2E
	adds r4, r0, r2
	subs r2, 0x12
	adds r0, r2
	ldr r3, =sub_81D9528
	str r3, [r0]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	str r3, [r0]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	str r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D94D4

	thumb_func_start sub_81D9528
sub_81D9528: @ 81D9528
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	ldrh r1, [r7, 0x36]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081D9550
	ldrh r1, [r7, 0x24]
	movs r2, 0x24
	ldrsh r0, [r7, r2]
	cmp r0, 0x1
	bne _081D954C
	ldr r0, =0x0000ffff
	b _081D954E
	.pool
_081D954C:
	movs r0, 0x1
_081D954E:
	strh r0, [r7, 0x24]
_081D9550:
	movs r1, 0x38
	ldrsh r0, [r7, r1]
	cmp r0, 0x80
	bne _081D95CE
	ldr r2, =gUnknown_0862ACF0
	mov r8, r2
	mov r0, r8
	movs r1, 0x98
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x3C]
	ldr r5, =gSprites
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	movs r6, 0x4
	orrs r0, r6
	strb r0, [r1, 0x5]
	mov r0, r8
	movs r1, 0xE0
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x3C]
	movs r2, 0x3C
	ldrsh r1, [r7, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x5]
	ands r4, r1
	orrs r4, r6
	strb r4, [r0, 0x5]
	movs r0, 0x3C
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldrh r0, [r7, 0x38]
	adds r0, 0x1
	strh r0, [r7, 0x38]
_081D95CE:
	ldrh r1, [r7, 0x38]
	movs r2, 0x38
	ldrsh r0, [r7, r2]
	cmp r0, 0x7F
	ble _081D95F8
	movs r1, 0x26
	ldrsh r0, [r7, r1]
	cmp r0, 0x20
	beq _081D95FC
	ldrh r0, [r7, 0x3A]
	adds r0, 0x1
	strh r0, [r7, 0x3A]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r7, 0x26]
	b _081D95FC
	.pool
_081D95F8:
	adds r0, r1, 0x1
	strh r0, [r7, 0x38]
_081D95FC:
	ldrh r0, [r7, 0x36]
	movs r1, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _081D960C
	movs r0, 0xA5
	bl PlaySE
_081D960C:
	ldrh r0, [r7, 0x36]
	adds r0, 0x1
	strh r0, [r7, 0x36]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9528

	thumb_func_start sub_81D961C
sub_81D961C: @ 81D961C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	cmp r1, 0x40
	bgt _081D968C
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	ldr r5, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	adds r1, 0x2
	strh r1, [r0, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	beq _081D964C
	b _081D979E
_081D964C:
	movs r3, 0x30
	negs r3, r3
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_81D9868
	movs r2, 0x5
	strh r2, [r4, 0x36]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x38]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x3
	strh r1, [r0, 0x36]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x38]
	b _081D979E
	.pool
_081D968C:
	cmp r1, 0x6F
	bgt _081D96BE
	adds r0, r4, 0
	bl sub_81D97E0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D96A4
	movs r0, 0x68
	bl PlaySE
_081D96A4:
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	bne _081D979E
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0x30
	movs r3, 0x10
	bl sub_81D9868
	b _081D979E
_081D96BE:
	cmp r1, 0x70
	bne _081D96EC
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x7
	strh r1, [r0, 0x36]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strh r1, [r0, 0x38]
	b _081D96F2
	.pool
_081D96EC:
	ldr r0, =0x00000147
	cmp r1, r0
	bgt _081D9700
_081D96F2:
	adds r0, r4, 0
	bl sub_81D97E0
	b _081D979E
	.pool
_081D9700:
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	bne _081D974C
	adds r0, r4, 0
	bl sub_81D97E0
	adds r0, r4, 0
	movs r1, 0x3
	movs r2, 0x30
	movs r3, 0x10
	bl sub_81D9868
	movs r3, 0x1
	strh r3, [r4, 0x24]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	movs r0, 0xCB
	lsls r0, 1
	movs r1, 0
	bl PlayCry1
	ldr r0, =sub_81D98B4
	movs r1, 0
	bl CreateTask
	b _081D979E
	.pool
_081D974C:
	movs r0, 0xB0
	lsls r0, 1
	cmp r1, r0
	beq _081D9790
	adds r0, 0x18
	cmp r1, r0
	bne _081D979E
	movs r3, 0
	strh r3, [r4, 0x24]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	adds r0, r4, 0
	bl sub_81D97E0
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0x30
	movs r3, 0x10
	bl sub_81D9868
	ldr r0, =sub_81D97E0
	str r0, [r4, 0x1C]
	b _081D97D2
	.pool
_081D9790:
	ldr r0, =sub_81D8E80
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl sub_81D9274
_081D979E:
	ldrh r2, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	ble _081D97CC
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _081D97CC
	movs r1, 0x24
	ldrsh r2, [r4, r1]
	negs r2, r2
	strh r2, [r4, 0x24]
	ldr r3, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x24]
_081D97CC:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
_081D97D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D961C

	thumb_func_start sub_81D97E0
sub_81D97E0: @ 81D97E0
	push {r4-r7,lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r4, r0, r5
	ldrh r1, [r3, 0x3A]
	ldrh r0, [r4, 0x36]
	ands r0, r1
	cmp r0, 0
	bne _081D985C
	ldrh r2, [r3, 0x36]
	ldrh r1, [r3, 0x26]
	adds r0, r2, r1
	strh r0, [r3, 0x26]
	movs r7, 0x2E
	ldrsh r1, [r3, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	adds r2, r1
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x38]
	ldrh r2, [r3, 0x36]
	adds r0, r2
	strh r0, [r3, 0x36]
	lsls r0, 16
	asrs r5, r0, 16
	ldrh r6, [r4, 0x38]
	movs r7, 0x38
	ldrsh r2, [r4, r7]
	cmp r5, r2
	bge _081D9836
	movs r0, 0x36
	ldrsh r1, [r3, r0]
	adds r0, r2, 0
	cmn r1, r0
	bgt _081D985C
_081D9836:
	cmp r5, r2
	ble _081D9844
	strh r6, [r3, 0x36]
	b _081D9854
	.pool
_081D9844:
	movs r0, 0x36
	ldrsh r1, [r3, r0]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bge _081D9854
	negs r0, r6
	strh r0, [r3, 0x36]
_081D9854:
	movs r7, 0x38
	ldrsh r0, [r3, r7]
	negs r0, r0
	strh r0, [r3, 0x38]
_081D985C:
	ldrh r0, [r3, 0x3A]
	adds r0, 0x1
	strh r0, [r3, 0x3A]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D97E0

	thumb_func_start sub_81D9868
sub_81D9868: @ 81D9868
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r5, 24
	lsrs r5, 24
	movs r4, 0x2E
	ldrsh r1, [r0, r4]
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r1, =gSprites
	adds r4, r1
	lsls r2, 16
	asrs r2, 16
	ldrh r1, [r0, 0x20]
	adds r2, r1
	strh r2, [r4, 0x20]
	lsls r3, 16
	asrs r3, 16
	ldrh r1, [r0, 0x22]
	adds r3, r1
	strh r3, [r4, 0x22]
	ldrh r1, [r0, 0x24]
	strh r1, [r4, 0x24]
	ldrh r1, [r0, 0x26]
	strh r1, [r4, 0x26]
	adds r1, r5, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	adds r1, r5, 0
	bl StartSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9868

	thumb_func_start sub_81D98B4
sub_81D98B4: @ 81D98B4
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _081D990C
	cmp r1, 0x1
	bgt _081D98DC
	cmp r1, 0
	beq _081D98E2
	b _081D99B4
	.pool
_081D98DC:
	cmp r1, 0x2
	beq _081D99A4
	b _081D99B4
_081D98E2:
	movs r2, 0x80
	lsls r2, 7
	movs r0, 0x40
	str r0, [sp]
	adds r0, 0xC0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0x2
	adds r1, r2, 0
	movs r3, 0x78
	bl SetBgAffine
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x10
	strh r0, [r4, 0x8]
	b _081D9922
_081D990C:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bne _081D991A
	movs r0, 0x12
	bl PlaySE
_081D991A:
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0x2
	bne _081D992A
_081D9922:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D99B4
_081D992A:
	ldrh r5, [r4, 0x8]
	ldrh r1, [r4, 0x2]
	adds r0, r5, r1
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D9954
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _081D9954
	subs r0, r5, 0x2
	strh r0, [r4, 0x8]
_081D9954:
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
	movs r2, 0x80
	lsls r2, 7
	movs r0, 0x40
	str r0, [sp]
	ldrh r0, [r4, 0x2]
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x4]
	ldrh r0, [r4, 0x2]
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	str r1, [sp, 0x8]
	movs r5, 0
	str r5, [sp, 0xC]
	movs r0, 0x2
	adds r1, r2, 0
	movs r3, 0x78
	bl SetBgAffine
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _081D99B4
	strh r5, [r4, 0x2]
	strh r5, [r4, 0x6]
	strh r5, [r4, 0xA]
	movs r0, 0x10
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	b _081D99B4
_081D99A4:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl ClearGpuRegBits
	adds r0, r5, 0
	bl DestroyTask
_081D99B4:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D98B4


	.align 2, 0 @ Don't pad with nop.
