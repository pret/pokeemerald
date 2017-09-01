	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8179B68
sub_8179B68: @ 8179B68
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_8179B68

	thumb_func_start sub_8179B84
sub_8179B84: @ 8179B84
	push {lr}
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8179B84

	thumb_func_start sub_8179B98
sub_8179B98: @ 8179B98
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xD
	bls _08179BAC
	b _08179D4C
_08179BAC:
	lsls r0, 2
	ldr r1, =_08179BC0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08179BC0:
	.4byte _08179BF8
	.4byte _08179C20
	.4byte _08179C34
	.4byte _08179C48
	.4byte _08179C4E
	.4byte _08179C60
	.4byte _08179C66
	.4byte _08179C78
	.4byte _08179C98
	.4byte _08179CB0
	.4byte _08179CDC
	.4byte _08179CF8
	.4byte _08179CFE
	.4byte _08179D18
_08179BF8:
	ldr r4, =gUnknown_0203BD18
	ldr r0, =0x00001084
	bl AllocZeroed
	str r0, [r4]
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08179D3A
	.pool
_08179C20:
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	b _08179D30
	.pool
_08179C34:
	bl ResetSpriteData
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08179D3A
	.pool
_08179C48:
	bl ResetObjectPaletteAllocator
	b _08179D32
_08179C4E:
	bl init_uns_table_pokemon_copy
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08179D3A
	.pool
_08179C60:
	bl sub_8179D9C
	b _08179D32
_08179C66:
	bl sub_8179FAC
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08179D3A
	.pool
_08179C78:
	ldr r0, =gUnknown_0203BC9C
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl sub_8179DF4
	lsls r0, 24
	cmp r0, 0
	beq _08179D64
	b _08179D32
	.pool
_08179C98:
	bl sub_817A4A4
	ldr r1, =gUnknown_0203BD18
	ldr r1, [r1]
	ldr r2, =0x0000105e
	adds r1, r2
	strb r0, [r1]
	b _08179D32
	.pool
_08179CB0:
	ldr r0, =gUnknown_0203BC9C
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl sub_817A358
	ldr r1, =gUnknown_0203BD18
	ldr r1, [r1]
	ldr r2, =0x0000105d
	adds r1, r2
	strb r0, [r1]
	b _08179D32
	.pool
_08179CDC:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08179D3A
	.pool
_08179CF8:
	bl sub_817A168
	b _08179D32
_08179CFE:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08179D3A
	.pool
_08179D18:
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
_08179D30:
	strb r0, [r2, 0x8]
_08179D32:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_08179D3A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08179D64
	.pool
_08179D4C:
	ldr r0, =sub_8179B84
	bl SetVBlankCallback
	ldr r0, =sub_8179B68
	bl SetMainCallback2
	movs r0, 0x1
	b _08179D66
	.pool
_08179D64:
	movs r0, 0
_08179D66:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8179B98

	thumb_func_start sub_8179D70
sub_8179D70: @ 8179D70
	push {lr}
_08179D72:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08179D96
	bl sub_8179B98
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08179D96
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08179D72
_08179D96:
	pop {r0}
	bx r0
	thumb_func_end sub_8179D70

	thumb_func_start sub_8179D9C
sub_8179D9C: @ 8179D9C
	push {lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085F0550
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	adds r1, 0x48
	movs r0, 0x1
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179D9C

	thumb_func_start sub_8179DF4
sub_8179DF4: @ 8179DF4
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	ldr r1, =0x0000107e
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x8
	bls _08179E0C
	b _08179FA0
_08179E0C:
	lsls r0, 2
	ldr r1, =_08179E24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08179E24:
	.4byte _08179E48
	.4byte _08179E84
	.4byte _08179EC4
	.4byte _08179ED8
	.4byte _08179EEC
	.4byte _08179F00
	.4byte _08179F20
	.4byte _08179F44
	.4byte _08179F78
_08179E48:
	adds r0, r6, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r6, 0
	movs r1, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	adds r2, r5, 0
	adds r3, r4, 0
	bl DecompressMonPic_DetectFrontOrBack_2
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179E84:
	adds r0, r6, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r6, 0
	movs r1, 0
	bl GetMonData
	adds r4, r0, 0
	adds r0, r6, 0
	movs r1, 0x1
	bl GetMonData
	adds r1, r0, 0
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_806E7CC
	adds r4, r0, 0
	bl LoadCompressedObjectPalette
	ldrh r0, [r4, 0x4]
	movs r1, 0x1
	bl sub_806A068
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179EC4:
	ldr r0, =gUnknown_085B26F4
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179ED8:
	ldr r0, =gUnknown_085B26FC
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179EEC:
	ldr r0, =gUnknown_085F06A0
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179F00:
	ldr r0, =gUnknown_0203CE7C
	ldrb r0, [r0]
	bl sub_8179FEC
	ldr r0, =gUnknown_0203BD1C
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179F20:
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08D7C440
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	b _08179F5E
	.pool
_08179F44:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08179FA0
	ldr r0, =gUnknown_08D9BA44
	ldr r4, =gUnknown_0203BD18
	ldr r1, [r4]
	adds r1, 0x48
	bl LZDecompressWram
	ldr r1, [r4]
_08179F5E:
	ldr r0, =0x0000107e
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _08179FA0
	.pool
_08179F78:
	ldr r0, =gUnknown_08D7C9EC
	movs r1, 0x20
	movs r2, 0x60
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	ldr r1, =0x0000107e
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _08179FA2
	.pool
_08179FA0:
	movs r0, 0
_08179FA2:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8179DF4

	thumb_func_start sub_8179FAC
sub_8179FAC: @ 8179FAC
	push {lr}
	ldr r0, =gUnknown_085F0558
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_809882C
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179FAC

	thumb_func_start sub_8179FEC
sub_8179FEC: @ 8179FEC
	push {lr}
	lsls r0, 24
	ldr r1, =gSaveBlock1Ptr
	lsrs r0, 21
	ldr r2, =0x00000848
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	movs r1, 0
	bl sub_8136F9C
	lsls r0, 24
	ldr r2, =gUnknown_0203BD1C
	ldr r1, =gUnknown_085F0568
	lsrs r0, 22
	subs r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, =0x000039e2
	strh r0, [r2, 0x4]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179FEC

	thumb_func_start sub_817A030
sub_817A030: @ 817A030
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0817A044
	b _0817A154
_0817A044:
	ldr r0, =gTasks
	lsls r2, r4, 2
	adds r1, r2, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x8
	ldrsh r3, [r1, r0]
	ldr r0, =0x0000010d
	adds r5, r2, 0
	cmp r3, r0
	beq _0817A0C8
	cmp r3, r0
	bgt _0817A074
	cmp r3, 0
	beq _0817A088
	cmp r3, 0xFF
	beq _0817A0AC
	b _0817A104
	.pool
_0817A074:
	ldr r0, =0x00000119
	cmp r3, r0
	beq _0817A0E0
	adds r0, 0x10
	cmp r3, r0
	beq _0817A0F8
	b _0817A104
	.pool
_0817A088:
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	ldr r2, =0x00001050
	adds r1, r2
	strb r3, [r1]
	ldr r0, [r0]
	ldr r1, =0x00001058
	adds r0, r1
	strh r3, [r0]
	bl sub_817A5CC
	b _0817A104
	.pool
_0817A0AC:
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	ldr r2, =0x0000105e
	adds r0, r2
	ldrb r0, [r0]
	ldrb r1, [r1, 0xA]
	bl sub_817A4F8
	b _0817A104
	.pool
_0817A0C8:
	bl sub_817A56C
	ldr r1, =gUnknown_0203BD18
	ldr r1, [r1]
	ldr r2, =0x0000105f
	adds r1, r2
	strb r0, [r1]
	b _0817A104
	.pool
_0817A0E0:
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	ldr r1, =0x0000105d
	adds r0, r1
	ldrb r0, [r0]
	bl sub_817A434
	b _0817A104
	.pool
_0817A0F8:
	ldr r0, =sub_817A1C4
	str r0, [r1]
	b _0817A154
	.pool
_0817A104:
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	ldr r2, =0x00001058
	adds r1, r0, r2
	subs r2, 0x2
	adds r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bcs _0817A128
	bl sub_817A634
	b _0817A138
	.pool
_0817A128:
	cmp r1, r0
	bne _0817A138
	ldr r0, =gTasks
	adds r1, r5, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0xFE
	strh r0, [r1, 0x8]
_0817A138:
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	ldr r0, =0x00001058
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r0, =gTasks
	adds r1, r5, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0817A154:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A030

	thumb_func_start sub_817A168
sub_817A168: @ 817A168
	push {lr}
	ldr r0, =sub_817A030
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	movs r0, 0x1
	strh r0, [r1, 0xA]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A168

	thumb_func_start sub_817A194
sub_817A194: @ 817A194
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	bl sub_8121F20
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	beq _0817A1B6
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_817A320
	str r0, [r1]
_0817A1B6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A194

	thumb_func_start sub_817A1C4
sub_817A1C4: @ 817A1C4
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0203BC9C
	ldrb r1, [r0]
	movs r0, 0x64
	adds r5, r1, 0
	muls r5, r0
	ldr r0, =gPlayerParty
	adds r5, r0
	ldr r1, =gSaveBlock1Ptr
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	lsls r0, 3
	ldr r2, =0x00000848
	adds r0, r2
	ldr r4, [r1]
	adds r4, r0
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_8136FE4
	ldr r6, =gUnknown_0203BC9E
	strh r0, [r6]
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r1, =gStringVar2
	adds r0, r4, 0
	bl sub_8137044
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0817A248
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085E937F
	bl StringExpandPlaceholders
	b _0817A268
	.pool
_0817A248:
	cmp r0, 0
	ble _0817A260
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085E9390
	bl StringExpandPlaceholders
	b _0817A268
	.pool
_0817A260:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085E93A9
	bl StringExpandPlaceholders
_0817A268:
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	bl sav2_get_text_speed
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r2, =gStringVar4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParametrized
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_817A194
	str r1, [r0]
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A1C4

	thumb_func_start sub_817A2C0
sub_817A2C0: @ 817A2C0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817A304
	bl ResetSpriteData
	bl ResetObjectPaletteAllocator
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	bl Free
	bl sub_805F094
_0817A304:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A2C0

	thumb_func_start sub_817A320
sub_817A320: @ 817A320
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_817A2C0
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A320

	thumb_func_start sub_817A358
sub_817A358: @ 817A358
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r1, 0x41
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_0202499C
	movs r1, 0x30
	movs r2, 0x50
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203BD18
	mov r9, r0
	ldr r0, [r0]
	ldr r2, =0x00001054
	adds r1, r0, r2
	strh r4, [r1]
	ldr r1, =0x0000105b
	adds r0, r1
	mov r2, r8
	strb r2, [r0]
	adds r0, r5, 0
	bl GetNature
	mov r2, r9
	ldr r1, [r2]
	ldr r2, =0x0000105a
	adds r1, r2
	strb r0, [r1]
	ldr r7, =gSprites
	mov r1, r8
	lsls r0, r1, 4
	add r0, r8
	lsls r5, r0, 2
	adds r6, r5, r7
	strh r4, [r6, 0x32]
	adds r0, r7, 0
	adds r0, 0x1C
	adds r0, r5, r0
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	mov r2, r9
	ldr r0, [r2]
	ldr r1, =0x00001053
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_806E840
	lsls r0, 24
	cmp r0, 0
	bne _0817A402
	adds r0, r7, 0
	adds r0, 0x10
	adds r0, r5, r0
	ldr r1, =gUnknown_085F05B0
	str r1, [r0]
	ldrb r3, [r6, 0x1]
	movs r0, 0x3
	orrs r3, r0
	strb r3, [r6, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r6, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r6, 0
	bl CalcCenterToCornerVec
	mov r2, r9
	ldr r0, [r2]
	ldr r1, =0x00001053
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_0817A402:
	mov r0, r8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817A358

	thumb_func_start sub_817A434
sub_817A434: @ 817A434
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r2, r1, r3
	movs r0, 0x30
	strh r0, [r2, 0x20]
	movs r0, 0x50
	strh r0, [r2, 0x22]
	ldr r0, =0x0000fff8
	strh r0, [r2, 0x2E]
	movs r0, 0x1
	strh r0, [r2, 0x30]
	adds r3, 0x1C
	adds r1, r3
	ldr r0, =sub_817A468
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_817A434

	thumb_func_start sub_817A468
sub_817A468: @ 817A468
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x2E]
	ldrh r2, [r4, 0x22]
	adds r1, r0, r2
	strh r1, [r4, 0x22]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _0817A48E
	ldrh r0, [r4, 0x32]
	movs r1, 0
	bl cry_related
_0817A48E:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	bne _0817A49A
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_0817A49A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A468

	thumb_func_start sub_817A4A4
sub_817A4A4: @ 817A4A4
	push {r4,r5,lr}
	movs r0, 0xBC
	movs r1, 0x64
	movs r2, 0x2
	bl sub_8136444
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gSprites
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r0, r3, r5
	ldrb r2, [r0, 0x1]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x1]
	adds r1, r5, 0
	adds r1, 0x10
	adds r1, r3, r1
	ldr r2, =gUnknown_085F0664
	str r2, [r1]
	adds r5, 0x1C
	adds r3, r5
	ldr r1, =SpriteCallbackDummy
	str r1, [r3]
	bl InitSpriteAffineAnim
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817A4A4

	thumb_func_start sub_817A4F8
sub_817A4F8: @ 817A4F8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gSprites
	mov r8, r0
	lsls r0, r7, 4
	adds r0, r7
	lsls r6, r0, 2
	mov r0, r8
	adds r4, r6, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	cmp r5, 0
	bne _0817A540
	mov r0, r8
	adds r0, 0x10
	adds r0, r6, r0
	ldr r1, =gUnknown_085F0668
	b _0817A548
	.pool
_0817A540:
	mov r0, r8
	adds r0, 0x10
	adds r0, r6, r0
	ldr r1, =gUnknown_085F066C
_0817A548:
	str r1, [r0]
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl InitSpriteAffineAnim
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A4F8

	thumb_func_start sub_817A56C
sub_817A56C: @ 817A56C
	push {lr}
	ldr r0, =gUnknown_085F06A8
	movs r1, 0xAE
	movs r2, 0x54
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r2, =0x0000fff4
	strh r2, [r1, 0x2E]
	movs r2, 0x1
	strh r2, [r1, 0x30]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817A56C

	thumb_func_start sub_817A5A0
sub_817A5A0: @ 817A5A0
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x20]
	subs r0, 0x4
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x2E]
	ldrh r3, [r2, 0x22]
	adds r1, r0, r3
	strh r1, [r2, 0x22]
	ldrh r1, [r2, 0x30]
	adds r0, r1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _0817A5C6
	adds r0, r2, 0
	bl DestroySprite
_0817A5C6:
	pop {r0}
	bx r0
	thumb_func_end sub_817A5A0

	thumb_func_start sub_817A5CC
sub_817A5CC: @ 817A5CC
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203BD18
	ldr r1, [r0]
	ldr r0, =0x00001056
	adds r3, r1, r0
	movs r0, 0x1
	strh r0, [r3]
	ldr r2, =gUnknown_085EFEBC
	ldr r7, =0x0000105a
	adds r1, r7
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r2
	ldrb r2, [r0]
	movs r4, 0
	ldr r5, =gUnknown_085EFF00
	adds r6, r5, 0
	subs r6, 0xA
_0817A5F0:
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r0, r1, r6
	ldrh r0, [r0]
	ldrh r7, [r3]
	adds r0, r7
	strh r0, [r3]
	adds r1, r5
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0x1
	beq _0817A61A
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0x7
	bls _0817A5F0
_0817A61A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A5CC

	thumb_func_start sub_817A634
sub_817A634: @ 817A634
	push {r4,lr}
	ldr r0, =gUnknown_0203BD18
	ldr r4, [r0]
	ldr r1, =0x00001050
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0x5A
	bls _0817A646
	b _0817A90E
_0817A646:
	lsls r0, 2
	ldr r1, =_0817A65C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0817A65C:
	.4byte _0817A7C8
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A818
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A858
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A8A2
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A8FC
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
_0817A7C8:
	ldr r1, =gUnknown_085EFEBC
	ldr r2, =0x0000105a
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrb r1, [r0]
	ldr r3, =0x00001051
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, =0x0000105b
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	adds r0, r4, 0
	stm r0!, {r1}
	movs r2, 0x44
	bl memcpy
	ldr r2, =0x00001050
	adds r1, r4, r2
	movs r0, 0xA
	strb r0, [r1]
	b _0817A90E
	.pool
_0817A818:
	bl sub_817A91C
	ldr r1, =gUnknown_085EFEBC
	ldr r3, =0x0000105a
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0817A850
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r0, [r4]
	ldr r1, =gUnknown_085F04FC
	str r1, [r0, 0x10]
	bl InitSpriteAffineAnim
_0817A850:
	ldr r0, =0x00001050
	adds r1, r4, r0
	movs r0, 0x32
	strb r0, [r1]
_0817A858:
	ldr r1, =gUnknown_085EFEBC
	ldr r2, =0x0000105a
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x1
	adds r2, r0, r1
	ldrb r1, [r2]
	cmp r1, 0
	beq _0817A8C8
	ldr r3, =0x00001053
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0817A898
	ldr r0, [r4]
	adds r1, 0xA
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectRotScalAnim
	b _0817A8C8
	.pool
_0817A898:
	ldr r0, [r4]
	ldrb r1, [r2]
	bl StartObjectRotScalAnim
	b _0817A8C8
_0817A8A2:
	bl sub_817A9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0817A90E
	ldr r1, =0x00001072
	adds r0, r4, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0817A8E0
	ldr r3, =0x00001051
	adds r1, r4, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_817A91C
_0817A8C8:
	ldr r0, =0x00001050
	adds r1, r4, r0
	movs r0, 0x3C
	strb r0, [r1]
	b _0817A90E
	.pool
_0817A8E0:
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	ldr r2, =0x00001050
	adds r1, r4, r2
	movs r0, 0x46
	strb r0, [r1]
	b _0817A90E
	.pool
_0817A8FC:
	bl sub_817AA3C
	ldr r3, =0x00001051
	adds r0, r4, r3
	movs r1, 0
	strb r1, [r0]
	ldr r2, =0x00001050
	adds r0, r4, r2
	strb r1, [r0]
_0817A90E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A634

	thumb_func_start sub_817A91C
sub_817A91C: @ 817A91C
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203BD18
	ldr r5, [r0]
	movs r4, 0
	movs r0, 0x83
	lsls r0, 5
	adds r7, r5, r0
	ldr r1, =gUnknown_085EFEEE
	mov r12, r1
	ldr r2, =0x00001051
	adds r6, r5, r2
_0817A932:
	lsls r2, r4, 1
	adds r3, r7, r2
	ldrb r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	add r2, r12
	ldrh r0, [r2]
	strh r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _0817A932
	ldr r0, =0x00001068
	adds r6, r5, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0817A9DC
	movs r2, 0x83
	lsls r2, 5
	adds r4, r5, r2
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r2, 0x4
	adds r1, r5, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl Sin
	ldr r2, =0x00001074
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, 0
	ldrsh r0, [r4, r1]
	subs r2, 0xE
	adds r1, r5, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl Cos
	ldr r2, =0x00001076
	adds r1, r5, r2
	strh r0, [r1]
	ldrh r0, [r6]
	ldr r1, =0x00001078
	adds r4, r5, r1
	strh r0, [r4]
	ldr r0, [r5]
	ldrh r1, [r0, 0x24]
	adds r2, 0x4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, [r5]
	ldrh r1, [r0, 0x26]
	adds r2, 0x2
	adds r0, r5, r2
	strh r1, [r0]
	bl sub_817AB68
	ldrh r0, [r4]
	strh r0, [r6]
	bl sub_817AA54
	ldrh r0, [r4]
	strh r0, [r6]
	movs r0, 0
	b _0817A9DE
	.pool
_0817A9DC:
	movs r0, 0x1
_0817A9DE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_817A91C

	thumb_func_start sub_817A9E4
sub_817A9E4: @ 817A9E4
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203BD18
	ldr r2, [r0]
	ldr r1, =0x00001078
	adds r0, r2, r1
	ldr r5, =0x00001068
	adds r4, r2, r5
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r0
	lsls r1, 16
	ldr r3, [r2]
	lsrs r1, 15
	movs r5, 0x85
	lsls r5, 4
	adds r0, r2, r5
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3, 0x24]
	ldr r3, [r2]
	movs r0, 0xC5
	lsls r0, 4
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	strh r0, [r3, 0x26]
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	beq _0817AA34
	movs r0, 0
	b _0817AA36
	.pool
_0817AA34:
	movs r0, 0x1
_0817AA36:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_817A9E4

	thumb_func_start sub_817AA3C
sub_817AA3C: @ 817AA3C
	push {lr}
	ldr r0, =gUnknown_0203BD18
	ldr r0, [r0]
	ldr r0, [r0]
	bl obj_free_rotscale_entry
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817AA3C

	thumb_func_start sub_817AA54
sub_817AA54: @ 817AA54
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r0, =gUnknown_0203BD18
	ldr r7, [r0]
	ldr r1, =0x00001070
	adds r0, r7, r1
	ldrh r0, [r0]
	mov r9, r0
	ldr r2, =0x00001078
	adds r0, r7, r2
	ldrh r0, [r0]
	mov r3, r9
	subs r0, r3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r4, =0x0000107a
	adds r1, r7, r4
	subs r2, 0xC
	adds r0, r7, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	ldr r3, =0x0000107c
	adds r1, r7, r3
	subs r4, 0xC
	adds r0, r7, r4
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	movs r5, 0
	mov r0, r8
	subs r0, 0x1
	cmp r5, r0
	bge _0817AB20
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r0, 16
	str r0, [sp, 0x8]
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	asrs r0, 16
	mov r10, r0
_0817AABE:
	mov r3, r9
	adds r0, r3, r5
	lsls r0, 1
	movs r4, 0x85
	lsls r4, 4
	adds r2, r7, r4
	adds r2, r0
	ldrh r6, [r2]
	ldr r3, [sp, 0x8]
	subs r1, r6, r3
	movs r4, 0xC5
	lsls r4, 4
	adds r3, r7, r4
	adds r3, r0
	ldrh r4, [r3]
	mov r0, r10
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r5, 0x1
	adds r0, r1, 0
	muls r0, r5
	mov r1, r8
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	bl __divsi3
	subs r6, r0
	ldr r2, [sp, 0xC]
	strh r6, [r2]
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	muls r0, r5
	mov r1, r8
	bl __divsi3
	ldr r3, [sp, 0x10]
	ldrh r1, [r3]
	subs r1, r0
	strh r1, [r3]
	lsls r5, 16
	lsrs r5, 16
	mov r0, r8
	subs r0, 0x1
	cmp r5, r0
	blt _0817AABE
_0817AB20:
	mov r0, r9
	add r0, r8
	subs r0, 0x1
	lsls r0, 1
	movs r2, 0x85
	lsls r2, 4
	adds r1, r7, r2
	adds r1, r0
	mov r3, sp
	ldrh r3, [r3]
	strh r3, [r1]
	movs r4, 0xC5
	lsls r4, 4
	adds r1, r7, r4
	adds r1, r0
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r1]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817AA54

	thumb_func_start sub_817AB68
sub_817AB68: @ 817AB68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gUnknown_0203BD18
	ldr r6, [r0]
	movs r0, 0
	str r0, [sp]
	ldr r1, =0x0000107a
	adds r0, r6, r1
	ldr r2, =0x00001074
	adds r1, r6, r2
	ldrh r2, [r0]
	ldrh r0, [r1]
	subs r2, r0
	ldr r3, =0x0000107c
	adds r0, r6, r3
	ldr r1, =0x00001076
	adds r3, r6, r1
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r0
	ldr r3, =0x00001068
	adds r3, r6
	mov r9, r3
	movs r0, 0x83
	lsls r0, 5
	adds r0, r6
	mov r8, r0
	lsls r2, 16
	asrs r2, 16
	str r2, [sp, 0x4]
	lsls r1, 16
	asrs r1, 16
	mov r10, r1
_0817ABB2:
	ldr r1, =0x0000106a
	adds r0, r6, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _0817ABC0
	negs r0, r0
_0817ABC0:
	lsls r0, 16
	ldr r3, =0x00001066
	adds r7, r6, r3
	lsrs r0, 16
	ldrh r1, [r7]
	adds r0, r1
	lsls r4, r0, 16
	strh r0, [r7]
	ldr r2, =0x00001064
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bge _0817ABE2
	movs r0, 0x1
	str r0, [sp]
_0817ABE2:
	ldr r1, =0x00001078
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r3, r9
	ldrh r1, [r3]
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r1, 0
	beq _0817ACB8
	ldr r0, [sp]
	cmp r0, 0
	bne _0817AC54
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	lsrs r4, 24
	adds r1, r2, r4
	lsls r1, 16
	asrs r1, 16
	bl Sin
	lsls r5, 1
	movs r2, 0x85
	lsls r2, 4
	adds r1, r6, r2
	adds r1, r5
	ldr r3, [sp, 0x4]
	adds r0, r3, r0
	strh r0, [r1]
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldrh r1, [r7]
	adds r1, r4
	b _0817AC80
	.pool
_0817AC54:
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	lsrs r4, 24
	subs r1, r2, r4
	lsls r1, 16
	asrs r1, 16
	bl Sin
	lsls r5, 1
	movs r2, 0x85
	lsls r2, 4
	adds r1, r6, r2
	adds r1, r5
	ldr r3, [sp, 0x4]
	adds r0, r3, r0
	strh r0, [r1]
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldrh r1, [r7]
	subs r1, r4
_0817AC80:
	lsls r1, 16
	asrs r1, 16
	bl Cos
	movs r3, 0xC5
	lsls r3, 4
	adds r1, r6, r3
	adds r1, r5
	add r0, r10
	strh r0, [r1]
	ldr r1, =0x00001062
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r2, r8
	ldrh r2, [r2]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	mov r3, r8
	strh r0, [r3]
	mov r1, r9
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	b _0817ABB2
	.pool
_0817ACB8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_817AB68

	.align 2, 0 @ Don't pad with nop.
