	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_814FC70
sub_814FC70: @ 814FC70
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814FC8E
	ldr r0, =sub_814FCC8
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_0814FC8E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814FC70

	thumb_func_start sub_814FC9C
sub_814FC9C: @ 814FC9C
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_814FC70
	movs r1, 0x1
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814FC9C

	thumb_func_start sub_814FCC8
sub_814FCC8: @ 814FCC8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	movs r4, 0
	str r4, [sp, 0x14]
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x9
	bhi _0814FD20
	lsls r0, 2
	ldr r1, =_0814FCF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814FCF8:
	.4byte _0814FD20
	.4byte _0814FDD8
	.4byte _0814FE90
	.4byte _0814FF50
	.4byte _0814FF7C
	.4byte _0814FF98
	.4byte _0814FFF8
	.4byte _08150090
	.4byte _08150190
	.4byte _081501C8
_0814FD20:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl sub_8150B6C
	bl remove_some_task
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x10
	mov r9, r0
	add r2, sp, 0xC
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r8, r0
_0814FD4E:
	strh r6, [r2]
	add r0, sp, 0xC
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _0814FD4E
	strh r6, [r2]
	add r2, sp, 0xC
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r3, r8
	orrs r0, r3
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x10]
	ldr r2, =0x040000d4
	mov r1, r9
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
	add r0, sp, 0xC
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	ldr r4, =gUnknown_0203ABAC
	ldr r0, =0x00004110
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FDD8:
	bl ResetSpriteData
	bl ResetTasks
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl reset_temp_tile_data_buffers
	bl sub_80AAFA4
	movs r4, 0
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_0814FDFC:
	lsls r0, r4, 2
	adds r0, r1, r0
	str r2, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _0814FDFC
	bl InitMapMusic
	bl ResetMapMusic
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085CD66C
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203ABAC
	ldr r1, [r4]
	adds r1, 0xFC
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r3, =0x000010fc
	adds r1, r3
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x000020fc
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r2, =0x000030fc
	adds r1, r2
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r2, =gSpriteCoordOffsetX
	ldr r1, =gSpriteCoordOffsetY
	movs r0, 0
	strh r0, [r1]
	strh r0, [r2]
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FE90:
	movs r4, 0
	add r5, sp, 0x14
	ldr r6, =gUnknown_085CDB54
_0814FE96:
	lsls r0, r4, 3
	adds r0, r6
	bl LoadCompressedObjectPic
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0814FE96
	ldr r0, =gUnknown_085CDB74
	bl LoadSpritePalettes
	ldr r0, =gUnknown_085CD67C
	adds r1, r5, 0
	bl malloc_and_decompress
	ldr r4, =gUnknown_0203ABAC
	ldr r1, [r4]
	ldr r2, =0x000040fc
	adds r1, r2
	str r0, [r1]
	ldr r0, =gUnknown_085CD7D4
	adds r1, r5, 0
	bl malloc_and_decompress
	ldr r1, [r4]
	movs r3, 0x82
	lsls r3, 7
	adds r1, r3
	str r0, [r1]
	ldr r0, =gUnknown_085CD958
	adds r1, r5, 0
	bl malloc_and_decompress
	ldr r1, [r4]
	ldr r2, =0x00004104
	adds r1, r2
	str r0, [r1]
	ldr r0, =gUnknown_085CDB30
	adds r1, r5, 0
	bl malloc_and_decompress
	ldr r1, [r4]
	ldr r3, =0x0000410c
	adds r2, r1, r3
	str r0, [r2]
	ldr r0, =0x00004108
	adds r1, r0
	ldr r0, =gUnknown_085CDB1C
	str r0, [r1]
	ldr r1, =gUnknown_08DBA5B8
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FF50:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _0814FF5C
	b _08150226
_0814FF5C:
	ldr r0, =gUnknown_08DBA518
	movs r1, 0
	movs r2, 0x80
	bl LoadPalette
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FF7C:
	bl sub_8150D28
	bl RunTasks
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FF98:
	ldr r0, =gUnknown_0203ABAC
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x7
	bne _0814FFB4
	movs r2, 0x87
	lsls r2, 3
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FFB4:
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	ldr r0, [r1]
	cmp r0, 0
	bne _0814FFC4
	b _08150226
_0814FFC4:
	movs r4, 0
	adds r3, r1, 0
	movs r5, 0xD
	negs r5, r5
_0814FFCC:
	lsls r0, r4, 2
	adds r0, r3, r0
	ldr r2, [r0]
	cmp r2, 0
	beq _0814FFDE
	ldrb r1, [r2, 0x5]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0x5]
_0814FFDE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _0814FFCC
	movs r3, 0x87
	lsls r3, 3
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_0814FFF8:
	ldr r6, =gUnknown_0203ABAC
	ldr r0, [r6]
	movs r1, 0x82
	lsls r1, 7
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0x11
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r0, [r6]
	ldr r2, =0x00004104
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0x1E
	str r0, [sp]
	movs r3, 0x14
	mov r8, r3
	str r3, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r0, [r6]
	ldr r1, =0x00004108
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r0, [r6]
	ldr r2, =0x0000410c
	adds r0, r2
	ldr r1, [r0]
	str r4, [sp]
	mov r3, r8
	str r3, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x2
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_08150090:
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	bl sub_81514C8
	ldr r1, =gUnknown_0203ABAC
	mov r9, r1
	ldr r0, [r1]
	ldr r2, =0x000040fc
	mov r8, r2
	add r0, r8
	ldr r1, [r0]
	adds r1, 0x90
	movs r6, 0xC
	str r6, [sp]
	movs r5, 0x3
	str r5, [sp, 0x4]
	movs r4, 0x11
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0xE
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r3, r9
	ldr r0, [r3]
	add r0, r8
	ldr r1, [r0]
	adds r1, 0xD8
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0xC
	movs r3, 0x11
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r1, r9
	ldr r0, [r1]
	add r0, r8
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	adds r1, r2
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0x18
	movs r3, 0x14
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r3, r9
	ldr r0, [r3]
	add r0, r8
	ldr r1, [r0]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0x11
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r1, r9
	ldr r0, [r1]
	add r0, r8
	ldr r1, [r0]
	adds r1, 0x48
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0x14
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r2, r9
	ldr r0, [r2]
	add r0, r8
	ldr r1, [r0]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0xC
	movs r3, 0x14
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r3, r9
	ldr r0, [r3]
	add r0, r8
	ldr r1, [r0]
	adds r1, 0x48
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0xC
	movs r3, 0x17
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r1, r9
	ldr r0, [r1]
	add r0, r8
	ldr r1, [r0]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0x18
	movs r3, 0x17
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_08150190:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x3
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =0x000001a9
	movs r1, 0x1
	bl FadeInNewBGM
	movs r0, 0x1
	bl sub_8150B6C
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	b _08150224
	.pool
_081501C8:
	ldr r3, =0x04000208
	ldrh r2, [r3]
	movs r0, 0
	strh r0, [r3]
	ldr r4, =0x04000200
	ldrh r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	ldr r0, =sub_8150800
	bl SetVBlankCallback
	ldr r0, =mainloop
	bl SetMainCallback2
	ldr r0, =sub_81503E4
	movs r1, 0
	bl CreateTask
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08150218
	ldr r0, =sub_8150550
	b _0815021A
	.pool
_08150218:
	ldr r0, =sub_8150664
_0815021A:
	movs r1, 0x1
	bl CreateTask
	ldr r1, =gUnknown_0203ABAC
	ldr r1, [r1]
_08150224:
	strb r0, [r1]
_08150226:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814FCC8

	thumb_func_start mainloop
mainloop: @ 815023C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	bl MapMusicMain
	pop {r0}
	bx r0
	thumb_func_end mainloop

	thumb_func_start c2_8011A1C
c2_8011A1C: @ 8150258
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r4, 0
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0
	bl sub_8150B6C
	ldr r0, =gSpriteCoordOffsetX
	strh r4, [r0]
	movs r0, 0
	bl sub_80AB130
	add r0, sp, 0x4
	mov r8, r0
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_08150298:
	lsls r0, r4, 2
	adds r0, r1, r0
	str r2, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _08150298
	bl ResetTasks
	bl ResetSpriteData
	bl ResetPaletteFade
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r6, =gUnknown_0203ABAC
	ldr r0, [r6]
	ldr r2, =0x00004108
	adds r1, r0, r2
	movs r5, 0
	str r5, [r1]
	ldr r4, =0x0000410c
	adds r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r4, r0, r4
	str r5, [r4]
	ldr r4, =0x00004104
	adds r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r4, r0, r4
	str r5, [r4]
	movs r4, 0x82
	lsls r4, 7
	adds r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r4, r0, r4
	str r5, [r4]
	ldr r4, =0x000040fc
	adds r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r4, r0, r4
	str r5, [r4]
	bl Free
	str r5, [r6]
	movs r2, 0xC0
	lsls r2, 19
	movs r3, 0xC0
	lsls r3, 9
	mov r4, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_08150340:
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r5
	subs r3, r5
	cmp r3, r5
	bhi _08150340
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
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
	bl warp_in
	ldr r0, =gFieldCallback
	str r4, [r0]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_8011A1C

	thumb_func_start sub_81503E4
sub_81503E4: @ 81503E4
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r5, =gUnknown_0203ABAC
	ldr r3, [r5]
	ldrh r0, [r3, 0x6]
	adds r0, 0x1
	strh r0, [r3, 0x6]
	ldrb r2, [r3, 0x1]
	adds r7, r5, 0
	cmp r2, 0x2
	beq _081504EA
	cmp r2, 0x2
	bgt _08150414
	cmp r2, 0
	beq _08150422
	cmp r2, 0x1
	beq _0815043C
	b _08150542
	.pool
_08150414:
	cmp r2, 0x3
	bne _0815041A
	b _08150510
_0815041A:
	cmp r2, 0xFF
	bne _08150420
	b _08150528
_08150420:
	b _08150542
_08150422:
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r3, 0x4]
	cmp r0, r1
	beq _0815042E
	b _08150542
_0815042E:
	ldrb r0, [r3, 0x2]
	bl weather_set
	ldr r1, [r5]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	b _08150542
_0815043C:
	ldrb r0, [r3, 0x2]
	cmp r0, 0x2
	beq _08150490
	cmp r0, 0x7
	beq _08150448
	b _08150542
_08150448:
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xF0
	ldr r0, [r2]
	cmp r0, 0
	beq _08150542
	ldrb r1, [r0, 0x5]
	movs r0, 0xC
	ands r0, r1
	cmp r0, 0
	beq _08150542
	adds r3, r2, 0
	movs r5, 0xD
	negs r5, r5
_08150466:
	lsls r0, r4, 2
	adds r0, r3, r0
	ldr r2, [r0]
	cmp r2, 0
	beq _08150478
	ldrb r1, [r2, 0x5]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0x5]
_08150478:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _08150466
	ldr r1, [r7]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	b _08150542
	.pool
_08150490:
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	movs r1, 0xDA
	lsls r1, 3
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081504A8
	strb r0, [r3, 0x1]
	b _08150542
	.pool
_081504A8:
	ldrh r1, [r3, 0x6]
	ldrh r0, [r3, 0x4]
	adds r0, 0x8
	cmp r1, r0
	blt _08150542
	adds r6, r2, 0
	adds r6, 0xF0
	movs r5, 0x1
	movs r7, 0x5
	negs r7, r7
_081504BC:
	lsls r0, r4, 2
	adds r0, r6, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _081504DE
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r1, r2, 29
	lsrs r1, 31
	eors r1, r5
	ands r1, r5
	lsls r1, 2
	adds r0, r7, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_081504DE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _081504BC
	b _08150542
_081504EA:
	lsls r1, r0, 16
	ldr r0, =0x023a0000
	cmp r1, r0
	bne _08150542
	movs r0, 0x3
	strb r0, [r3, 0x1]
	subs r0, 0x4
	str r4, [sp]
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	movs r0, 0x4
	bl FadeOutBGM
	b _08150542
	.pool
_08150510:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08150542
	movs r0, 0xFF
	strb r0, [r3, 0x1]
	b _08150542
	.pool
_08150528:
	movs r0, 0
	bl SetVBlankCallback
	adds r0, r6, 0
	bl DestroyTask
	ldr r0, [r5]
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, =c2_8011A1C
	bl SetMainCallback2
_08150542:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81503E4

	thumb_func_start sub_8150550
sub_8150550: @ 8150550
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r6, =gUnknown_0203ABAC
	ldr r1, [r6]
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	beq _08150630
	ldrb r0, [r1, 0x14]
	subs r0, 0x1
	strb r0, [r1, 0x14]
	ldr r1, [r6]
	ldrh r0, [r1, 0x6]
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	bne _08150576
	ldrb r0, [r1, 0x15]
	subs r0, 0x1
	strb r0, [r1, 0x15]
_08150576:
	ldr r2, [r6]
	ldrh r0, [r2, 0x6]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _08150590
	ldrb r0, [r2, 0xC]
	subs r0, 0x1
	strb r0, [r2, 0xC]
	ldr r1, [r6]
	ldrb r0, [r1, 0xD]
	subs r0, 0x1
	strb r0, [r1, 0xD]
_08150590:
	ldr r0, [r6]
	ldrb r1, [r0, 0x14]
	cmp r1, 0x20
	beq _081505DC
	cmp r1, 0x20
	bgt _081505A8
	cmp r1, 0x10
	beq _081505F4
	b _08150630
	.pool
_081505A8:
	cmp r1, 0x28
	beq _081505CA
	cmp r1, 0xAF
	bne _08150630
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0xA
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0x16
	bl FillBgTilemapBufferRect
	b _08150630
_081505CA:
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x3
	b _081505EC
_081505DC:
	str r3, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x2
_081505EC:
	movs r3, 0
	bl FillBgTilemapBufferRect
	b _08150630
_081505F4:
	ldr r1, =0x00004108
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r0, [r6]
	ldr r1, =0x0000410c
	adds r0, r1
	ldr r1, [r0]
	str r4, [sp]
	movs r0, 0x1E
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x2
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r1, [r6]
	movs r0, 0x40
	strb r0, [r1, 0x15]
_08150630:
	bl sub_815115C
	ldr r3, =gSpriteCoordOffsetX
	movs r0, 0
	ldrsh r2, [r3, r0]
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _08150646
	adds r0, r2, 0
	adds r0, 0x80
_08150646:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	strh r0, [r3]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8150550

	thumb_func_start sub_8150664
sub_8150664: @ 8150664
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r7, =gUnknown_0203ABAC
	ldr r1, [r7]
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	bne _08150674
	b _081507B6
_08150674:
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	ldr r1, [r7]
	ldrh r0, [r1, 0x6]
	movs r6, 0x1
	ands r0, r6
	cmp r0, 0
	bne _0815068C
	ldrb r0, [r1, 0x15]
	adds r0, 0x1
	strb r0, [r1, 0x15]
_0815068C:
	ldr r2, [r7]
	ldrh r0, [r2, 0x6]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _081506A6
	ldrb r0, [r2, 0xC]
	adds r0, 0x1
	strb r0, [r2, 0xC]
	ldr r1, [r7]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
_081506A6:
	ldr r0, [r7]
	ldrb r1, [r0, 0x14]
	cmp r1, 0x20
	beq _0815071A
	cmp r1, 0x20
	bgt _081506BC
	cmp r1, 0x10
	beq _081506E8
	b _081507B6
	.pool
_081506BC:
	cmp r1, 0x28
	beq _08150784
	cmp r1, 0xB0
	bne _081507B6
	ldr r1, =0x0000410c
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0x1E
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x2
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _081507B6
	.pool
_081506E8:
	movs r0, 0x3
	str r0, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	movs r0, 0xA
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0x16
	bl FillBgTilemapBufferRect
	ldr r1, [r7]
	movs r0, 0xC0
	strb r0, [r1, 0x15]
	b _081507B6
_0815071A:
	ldr r5, =0x00004108
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	str r6, [sp]
	str r6, [sp, 0x4]
	movs r4, 0x11
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0x2
	movs r3, 0
	bl FillBgTilemapBufferRect
	ldr r0, [r7]
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0, 0x6]
	str r6, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0x3
	movs r3, 0
	bl FillBgTilemapBufferRect
	ldr r0, [r7]
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0, 0xE]
	str r6, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0x2
	movs r3, 0x1
	bl FillBgTilemapBufferRect
	ldr r0, [r7]
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0, 0x10]
	str r6, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0x3
	movs r3, 0x1
	bl FillBgTilemapBufferRect
	b _081507B6
	.pool
_08150784:
	ldr r5, =0x00004108
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0, 0x8]
	str r6, [sp]
	str r6, [sp, 0x4]
	movs r4, 0x11
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0x4
	movs r3, 0
	bl FillBgTilemapBufferRect
	ldr r0, [r7]
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0, 0x12]
	str r6, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r2, 0x4
	movs r3, 0x1
	bl FillBgTilemapBufferRect
_081507B6:
	bl sub_81511B8
	ldr r0, =gUnknown_0203ABAC
	ldr r1, [r0]
	ldrh r0, [r1, 0x6]
	ldrh r1, [r1, 0x4]
	cmp r0, r1
	bcs _081507DC
	ldr r4, =gSpriteCoordOffsetX
	movs r1, 0
	ldrsh r0, [r4, r1]
	b _081507E6
	.pool
_081507DC:
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r0, =0x000006fc
	adds r4, r0
	ldrh r0, [r4]
_081507E6:
	adds r0, 0xF7
	movs r1, 0xF8
	bl __modsi3
	strh r0, [r4]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8150664

	thumb_func_start sub_8150800
sub_8150800: @ 8150800
	push {r4,lr}
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r4, =gUnknown_0203ABAC
	ldr r0, [r4]
	ldrb r1, [r0, 0x14]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0x15]
	movs r0, 0x1E
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0xD]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0x8]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0x9]
	movs r0, 0x12
	bl SetGpuReg
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8150800

	thumb_func_start nullsub_58
nullsub_58: @ 8150864
	bx lr
	thumb_func_end nullsub_58

	thumb_func_start sub_8150868
sub_8150868: @ 8150868
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203ABAC
	ldr r6, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0xFF
	beq _08150934
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _081508E4
	movs r0, 0x6
	ldrsh r4, [r6, r0]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08150892
	ldr r1, =0x47800000
	bl __addsf3
_08150892:
	ldr r1, =0x3e0f5c29
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x2E]
	subs r1, r0
	strh r1, [r5, 0x20]
	movs r1, 0x6
	ldrsh r4, [r6, r1]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _081508BA
	ldr r1, =0x47800000
	bl __addsf3
_081508BA:
	ldr r1, =0x3d89374c
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x30]
	subs r1, r0
	strh r1, [r5, 0x22]
	b _08150934
	.pool
_081508E4:
	movs r0, 0x6
	ldrsh r4, [r6, r0]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _081508F8
	ldr r1, =0x47800000
	bl __addsf3
_081508F8:
	ldr r1, =0x3e0f5c29
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x2E]
	adds r0, r1
	strh r0, [r5, 0x20]
	movs r0, 0x6
	ldrsh r4, [r6, r0]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08150920
	ldr r1, =0x47800000
	bl __addsf3
_08150920:
	ldr r1, =0x3d89374c
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x30]
	adds r0, r1
	strh r0, [r5, 0x22]
_08150934:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8150868

	thumb_func_start sub_8150948
sub_8150948: @ 8150948
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203ABAC
	ldr r6, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0xFF
	bne _08150958
	b _08150A60
_08150958:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _081509C8
	movs r0, 0x6
	ldrsh r4, [r6, r0]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08150974
	ldr r1, =0x47800000
	bl __addsf3
_08150974:
	ldr r1, =0x3e0f5c29
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x2E]
	subs r1, r0
	strh r1, [r5, 0x20]
	movs r1, 0x6
	ldrsh r4, [r6, r1]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _0815099C
	ldr r1, =0x47800000
	bl __addsf3
_0815099C:
	ldr r1, =0x3d89374c
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x30]
	subs r1, r0
	strh r1, [r5, 0x22]
	b _08150A18
	.pool
_081509C8:
	movs r0, 0x6
	ldrsh r4, [r6, r0]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _081509DC
	ldr r1, =0x47800000
	bl __addsf3
_081509DC:
	ldr r1, =0x3e0f5c29
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x2E]
	adds r0, r1
	strh r0, [r5, 0x20]
	movs r0, 0x6
	ldrsh r4, [r6, r0]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08150A04
	ldr r1, =0x47800000
	bl __addsf3
_08150A04:
	ldr r1, =0x3d89374c
	bl __mulsf3
	bl __fixunssfsi
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x30]
	adds r0, r1
	strh r0, [r5, 0x22]
_08150A18:
	movs r0, 0x32
	ldrsh r2, [r5, r0]
	cmp r2, 0
	bne _08150A48
	movs r0, 0x11
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x34]
	adds r1, r0, 0x1
	strh r1, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	ble _08150A60
	strh r2, [r5, 0x34]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	b _08150A60
	.pool
_08150A48:
	movs r2, 0
	movs r0, 0x10
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x34]
	adds r1, r0, 0x1
	strh r1, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	ble _08150A60
	strh r2, [r5, 0x34]
	strh r2, [r5, 0x32]
_08150A60:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8150948

	thumb_func_start sub_8150A68
sub_8150A68: @ 8150A68
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _08150A98
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r3, [r2, 0x20]
	adds r0, r3
	strh r0, [r2, 0x20]
	ldrh r1, [r2, 0x22]
	adds r1, 0x10
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	strh r0, [r2, 0x22]
_08150A98:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _08150AEE
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	cmp r1, 0
	beq _08150AB8
	cmp r1, 0x1
	beq _08150AC2
	b _08150AE0
_08150AB8:
	ldrh r0, [r2, 0x20]
	adds r0, 0x1
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x2E]
	b _08150AD2
_08150AC2:
	ldrh r0, [r2, 0x2E]
	ands r0, r1
	cmp r0, 0
	beq _08150AE0
	ldrh r0, [r2, 0x20]
	adds r0, 0x1
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x20]
_08150AD2:
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08150AE0
	ldrh r0, [r2, 0x22]
	adds r0, 0x1
	strh r0, [r2, 0x22]
_08150AE0:
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	cmp r0, 0xA0
	ble _08150AEE
	adds r0, r2, 0
	bl DestroySprite
_08150AEE:
	pop {r0}
	bx r0
	thumb_func_end sub_8150A68

	thumb_func_start sub_8150AF4
sub_8150AF4: @ 8150AF4
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _08150B12
	ldrh r1, [r2, 0x22]
	adds r1, 0x10
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	strh r0, [r2, 0x22]
_08150B12:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _08150B68
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	cmp r1, 0
	beq _08150B32
	cmp r1, 0x1
	beq _08150B3C
	b _08150B5A
_08150B32:
	ldrh r0, [r2, 0x20]
	subs r0, 0x1
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x2E]
	b _08150B4C
_08150B3C:
	ldrh r0, [r2, 0x2E]
	ands r0, r1
	cmp r0, 0
	beq _08150B5A
	ldrh r0, [r2, 0x20]
	subs r0, 0x1
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x20]
_08150B4C:
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08150B5A
	ldrh r0, [r2, 0x22]
	subs r0, 0x1
	strh r0, [r2, 0x22]
_08150B5A:
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	cmp r0, 0x4F
	bgt _08150B68
	adds r0, r2, 0
	bl DestroySprite
_08150B68:
	pop {r0}
	bx r0
	thumb_func_end sub_8150AF4

	thumb_func_start sub_8150B6C
sub_8150B6C: @ 8150B6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08150B7A
	cmp r0, 0x1
	beq _08150C1C
_08150B7A:
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	b _08150D1C
_08150C1C:
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gSpecialVar_0x8004
	ldrh r3, [r0]
	cmp r3, 0
	bne _08150C74
	ldr r1, =gUnknown_0203ABAC
	ldr r2, [r1]
	movs r0, 0xB0
	strb r0, [r2, 0x14]
	ldr r2, [r1]
	movs r0, 0x10
	strb r0, [r2, 0x15]
	ldr r0, [r1]
	strb r3, [r0, 0xC]
	ldr r2, [r1]
	movs r0, 0x50
	b _08150C8C
	.pool
_08150C74:
	ldr r1, =gUnknown_0203ABAC
	ldr r2, [r1]
	movs r3, 0
	movs r0, 0x60
	strb r0, [r2, 0x14]
	ldr r2, [r1]
	movs r0, 0xE8
	strb r0, [r2, 0x15]
	ldr r0, [r1]
	strb r3, [r0, 0xC]
	ldr r2, [r1]
	movs r0, 0x4
_08150C8C:
	strb r0, [r2, 0xD]
	ldr r0, [r1]
	strb r3, [r0, 0x9]
	ldr r0, [r1]
	strb r3, [r0, 0x9]
	adds r4, r1, 0
	ldr r0, [r4]
	ldrb r1, [r0, 0x14]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0x15]
	movs r0, 0x1E
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0xD]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0x8]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, 0x9]
	movs r0, 0x12
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r1, 0xFC
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
_08150D1C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8150B6C

	thumb_func_start sub_8150D28
sub_8150D28: @ 8150D28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	ldr r1, =gUnknown_085CDBE4
	add r0, sp, 0xC
	movs r2, 0x2
	bl memcpy
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	add r6, sp, 0x10
	ldr r1, =gUnknown_085CDBE6
	adds r0, r6, 0
	movs r2, 0x4
	bl memcpy
	add r5, sp, 0x14
	ldr r1, =gUnknown_085CDBEA
	adds r0, r5, 0
	movs r2, 0x8
	bl memcpy
	add r4, sp, 0x1C
	ldr r1, =gUnknown_085CDBF2
	adds r0, r4, 0
	movs r2, 0x4
	bl memcpy
	ldr r0, =gUnknown_085CDBF8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	mov r8, r6
	mov r10, r5
	cmp r0, 0
	beq _08150D86
	cmp r0, 0x1
	beq _08150E68
_08150D86:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	add r0, sp
	adds r0, 0xC
	ldrb r0, [r0]
	ldr r1, =sub_8150948
	movs r2, 0x66
	str r2, [sp]
	movs r2, 0xC8
	movs r3, 0x49
	bl AddPseudoFieldObject
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08150DD0
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x8
	strh r0, [r1, 0x24]
	movs r0, 0x10
	strh r0, [r1, 0x26]
	movs r0, 0xC8
	strh r0, [r1, 0x2E]
	movs r0, 0x49
	strh r0, [r1, 0x30]
_08150DD0:
	ldr r4, =gUnknown_085CDB9C
	adds r0, r4, 0
	movs r1, 0xB0
	movs r2, 0x2B
	movs r3, 0x67
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r5
	movs r1, 0x20
	strh r1, [r0, 0x26]
	strh r1, [r0, 0x24]
	movs r1, 0xB0
	strh r1, [r0, 0x2E]
	movs r1, 0x2B
	strh r1, [r0, 0x30]
	adds r4, 0x18
	adds r0, r4, 0
	movs r1, 0xC8
	movs r2, 0x63
	movs r3, 0x65
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r5
	movs r1, 0x8
	strh r1, [r0, 0x24]
	movs r1, 0x4
	strh r1, [r0, 0x26]
	movs r1, 0xC8
	strh r1, [r0, 0x2E]
	movs r1, 0x63
	strh r1, [r0, 0x30]
	ldr r2, =gUnknown_0203ABAC
	ldr r1, [r2]
	movs r0, 0x7
	strb r0, [r1, 0x2]
	ldr r1, [r2]
	movs r0, 0xAF
	lsls r0, 1
	strh r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_80AB130
	b _08150F3A
	.pool
_08150E68:
	ldr r7, =gUnknown_0203ABAC
	ldr r0, [r7]
	ldr r1, =0x000040fc
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x48
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r2, 0x18
	movs r3, 0x1A
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	add r0, sp
	adds r0, 0xC
	ldrb r0, [r0]
	ldr r1, =sub_8150948
	movs r2, 0x66
	str r2, [sp]
	movs r2, 0x80
	movs r3, 0x27
	bl AddPseudoFieldObject
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08150ED4
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x8
	strh r0, [r1, 0x24]
	movs r0, 0x10
	strh r0, [r1, 0x26]
	movs r0, 0x80
	strh r0, [r1, 0x2E]
	movs r0, 0x27
	strh r0, [r1, 0x30]
_08150ED4:
	ldr r4, =gUnknown_085CDB9C
	adds r0, r4, 0
	movs r1, 0x68
	movs r2, 0x9
	movs r3, 0x67
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r5
	movs r1, 0x20
	strh r1, [r0, 0x26]
	strh r1, [r0, 0x24]
	movs r1, 0x68
	strh r1, [r0, 0x2E]
	movs r1, 0x9
	strh r1, [r0, 0x30]
	adds r4, 0x18
	adds r0, r4, 0
	movs r1, 0x80
	movs r2, 0x41
	movs r3, 0x65
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r5
	movs r1, 0x8
	strh r1, [r0, 0x24]
	movs r1, 0x4
	strh r1, [r0, 0x26]
	movs r1, 0x80
	strh r1, [r0, 0x2E]
	movs r1, 0x41
	strh r1, [r0, 0x30]
	ldr r1, [r7]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	ldr r1, [r7]
	ldr r0, =0x00000109
	strh r0, [r1, 0x4]
	movs r0, 0x7
	bl sub_80AB130
_08150F3A:
	movs r4, 0
	ldr r5, =gSprites
_08150F3E:
	lsls r1, r4, 20
	movs r2, 0xC0
	lsls r2, 15
	adds r1, r2
	asrs r1, 16
	lsls r2, r4, 19
	ldr r3, =0xfff80000
	adds r2, r3
	asrs r2, 16
	ldr r0, =gUnknown_085CDBCC
	movs r3, 0x68
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r5
	movs r1, 0x8
	strh r1, [r0, 0x24]
	strh r1, [r0, 0x26]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x8
	bls _08150F3E
	movs r0, 0x3F
	mov r4, r9
	ands r0, r4
	cmp r0, 0
	bne _08151074
	mov r0, r9
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	add r0, r8
	ldrb r0, [r0]
	ldr r5, =gSpecialVar_0x8004
	ldrh r4, [r5]
	lsls r4, 2
	add r1, sp, 0x20
	adds r1, r4, r1
	ldr r1, [r1]
	mov r3, r10
	adds r2, r3, r4
	movs r3, 0
	ldrsh r2, [r2, r3]
	mov r3, sp
	adds r3, 0x16
	adds r3, r4
	movs r4, 0
	ldrsh r3, [r3, r4]
	movs r4, 0x6A
	str r4, [sp]
	bl AddPseudoFieldObject
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08151074
	ldr r1, =gSprites
	lsls r2, r6, 4
	adds r0, r2, r6
	lsls r0, 2
	adds r4, r0, r1
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r0, r4, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r5]
	mov r8, r2
	cmp r0, 0
	bne _08151036
	movs r7, 0x1
	mov r5, r9
	ands r5, r7
	cmp r5, 0
	beq _08151030
	adds r0, r4, 0
	movs r1, 0x6
	b _08151044
	.pool
_08151030:
	adds r0, r4, 0
	movs r1, 0x7
	b _08151056
_08151036:
	movs r7, 0x1
	mov r5, r9
	ands r5, r7
	cmp r5, 0
	beq _08151052
	adds r0, r4, 0
	movs r1, 0x7
_08151044:
	bl StartSpriteAnim
	strh r7, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	adds r0, 0x2
	strh r0, [r4, 0x22]
	b _0815105C
_08151052:
	adds r0, r4, 0
	movs r1, 0x6
_08151056:
	bl StartSpriteAnim
	strh r5, [r4, 0x30]
_0815105C:
	ldr r0, =gSprites
	mov r2, r8
	adds r1, r2, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x3
	mov r3, r9
	ands r0, r3
	add r0, sp
	adds r0, 0x1C
	ldrb r0, [r0]
	strh r0, [r1, 0x32]
_08151074:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8150D28

	thumb_func_start sub_8151088
sub_8151088: @ 8151088
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r3, 0
	mov r9, r3
	ldr r2, =gUnknown_0203ABAC
	ldr r0, [r2]
	ldrb r1, [r0, 0x1B]
	adds r1, 0x2
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 26
	lsrs r0, 24
	mov r12, r0
_081510AA:
	movs r7, 0
	lsls r0, r3, 1
	adds r1, r3, 0x3
	adds r2, r3, 0x6
	adds r4, r3, 0x1
	str r4, [sp, 0x4]
	adds r0, r3
	lsls r0, 3
	str r0, [sp]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	mov r10, r0
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	mov r8, r0
_081510CC:
	ldr r0, =gUnknown_0203ABAC
	ldr r6, [r0]
	lsls r3, r7, 1
	ldr r1, [sp]
	adds r2, r3, r1
	adds r4, r6, 0
	adds r4, 0x22
	adds r2, r4, r2
	mov r1, r12
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	ldr r0, =0x000040fc
	adds r5, r6, r0
	ldr r0, [r5]
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	mov r1, r10
	adds r2, r3, r1
	adds r2, r4, r2
	str r2, [sp, 0x8]
	ldr r0, [r5]
	mov r2, r9
	lsls r1, r2, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldr r2, [sp, 0x8]
	strh r0, [r2]
	add r3, r8
	adds r4, r3
	ldr r0, [r5]
	adds r1, r0
	adds r1, 0x48
	ldrh r0, [r1]
	strh r0, [r4]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xB
	bls _081510CC
	ldr r4, [sp, 0x4]
	lsls r0, r4, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _081510AA
	ldrb r0, [r6, 0x1B]
	adds r0, 0x1
	movs r1, 0x3
	bl __modsi3
	strb r0, [r6, 0x1B]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8151088

	thumb_func_start sub_815115C
sub_815115C: @ 815115C
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203ABAC
	ldr r4, [r5]
	ldrb r0, [r4, 0x1C]
	adds r0, 0x1
	movs r1, 0x60
	bl __modsi3
	strb r0, [r4, 0x1C]
	ldr r1, [r5]
	ldrb r0, [r1, 0x1F]
	ldrb r2, [r1, 0x1D]
	subs r0, r2
	strb r0, [r1, 0x8]
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x20
	ldrb r0, [r0]
	ldrb r1, [r2, 0x1E]
	subs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, [r5]
	ldrb r0, [r1, 0x1D]
	adds r0, 0x1
	strb r0, [r1, 0x1D]
	ldr r2, [r5]
	ldrb r0, [r2, 0x1D]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081511A0
	ldrb r0, [r2, 0x1E]
	adds r0, 0x1
	strb r0, [r2, 0x1E]
_081511A0:
	ldr r0, [r5]
	ldrb r0, [r0, 0x1D]
	cmp r0, 0x10
	bls _081511AC
	bl sub_8151214
_081511AC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815115C

	thumb_func_start sub_81511B8
sub_81511B8: @ 81511B8
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203ABAC
	ldr r4, [r5]
	ldrb r0, [r4, 0x1C]
	adds r0, 0x1
	movs r1, 0x60
	bl __modsi3
	strb r0, [r4, 0x1C]
	ldr r1, [r5]
	ldrb r0, [r1, 0x1D]
	ldrb r2, [r1, 0x1F]
	adds r0, r2
	strb r0, [r1, 0x8]
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0x20
	ldrb r0, [r1, 0x1E]
	ldrb r2, [r2]
	adds r0, r2
	strb r0, [r1, 0x9]
	ldr r1, [r5]
	ldrb r0, [r1, 0x1D]
	adds r0, 0x1
	strb r0, [r1, 0x1D]
	ldr r2, [r5]
	ldrb r0, [r2, 0x1D]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081511FC
	ldrb r0, [r2, 0x1E]
	adds r0, 0x1
	strb r0, [r2, 0x1E]
_081511FC:
	ldr r0, [r5]
	ldrb r0, [r0, 0x1D]
	cmp r0, 0x10
	bls _08151208
	bl sub_8151388
_08151208:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81511B8

	thumb_func_start sub_8151214
sub_8151214: @ 8151214
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r7, 0
	ldr r3, =gUnknown_0203ABAC
	ldr r0, [r3]
	strb r7, [r0, 0x1E]
	strb r7, [r0, 0x1D]
	ldr r1, [r3]
	ldrb r0, [r1, 0x8]
	strb r0, [r1, 0x1F]
	ldr r0, [r3]
	ldrb r1, [r0, 0x9]
	adds r0, 0x20
	strb r1, [r0]
	ldr r4, [r3]
	ldrb r1, [r4, 0x19]
	adds r2, r1, 0
	adds r2, 0x1E
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r4, 0x19]
	ldr r1, [r3]
	ldrb r0, [r1, 0x18]
	subs r0, 0x2
	strb r0, [r1, 0x18]
	ldr r4, =gUnknown_0203ABB2
	ldr r0, [r3]
	ldrb r1, [r0, 0x1A]
	adds r2, r1, 0
	adds r2, 0x17
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r4]
	ldr r6, =gUnknown_0203ABB0
	mov r9, r3
	ldr r0, =gUnknown_0203ABB1
	mov r8, r0
_0815126E:
	mov r1, r9
	ldr r2, [r1]
	ldrb r0, [r2, 0x19]
	strb r0, [r6]
	ldr r0, =gUnknown_0203ABB2
	ldrb r0, [r0]
	adds r1, r0, r7
	adds r0, r1, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r1, r0
	mov r1, r8
	strb r0, [r1]
	ldrb r1, [r2, 0x18]
	lsls r1, 1
	lsls r0, r7, 1
	adds r0, r7
	lsls r5, r0, 3
	adds r1, r5
	adds r0, r2, 0
	adds r0, 0x22
	adds r0, r1
	ldrh r1, [r0]
	ldrb r2, [r6]
	mov r0, r8
	ldrb r3, [r0]
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x11
	mov r10, r0
	str r0, [sp, 0x8]
	movs r0, 0
	bl FillBgTilemapBufferRect
	ldrb r1, [r6]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r6]
	mov r0, r9
	ldr r1, [r0]
	ldrb r0, [r1, 0x18]
	adds r0, 0x1
	lsls r0, 1
	adds r0, r5
	adds r1, 0x22
	adds r1, r0
	ldrh r1, [r1]
	ldrb r2, [r6]
	mov r0, r8
	ldrb r3, [r0]
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	movs r0, 0
	bl FillBgTilemapBufferRect
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x8
	bls _0815126E
	ldr r5, =gUnknown_0203ABB0
	ldr r4, =gUnknown_0203ABAC
	ldr r0, [r4]
	ldrb r1, [r0, 0x19]
	adds r2, r1, 0
	adds r2, 0x1E
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r5]
	ldrb r2, [r5]
	movs r0, 0x2
	str r0, [sp]
	movs r6, 0x20
	str r6, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	bne _08151368
	ldrb r2, [r1, 0x1A]
	adds r3, r2, 0
	adds r3, 0x1D
	adds r0, r3, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r3, r0
	strb r0, [r1, 0x1A]
	ldr r1, [r4]
	movs r0, 0xC
	strb r0, [r1, 0x18]
	bl sub_8151088
	ldr r0, [r4]
	ldrb r1, [r0, 0x1A]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r5]
	ldrb r3, [r5]
	str r6, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl FillBgTilemapBufferRect
_08151368:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8151214

	thumb_func_start sub_8151388
sub_8151388: @ 8151388
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r7, 0
	ldr r2, =gUnknown_0203ABAC
	ldr r0, [r2]
	strb r7, [r0, 0x1E]
	strb r7, [r0, 0x1D]
	ldr r1, [r2]
	ldrb r0, [r1, 0x8]
	strb r0, [r1, 0x1F]
	ldr r0, [r2]
	ldrb r1, [r0, 0x9]
	adds r0, 0x20
	strb r1, [r0]
	ldr r4, [r2]
	ldrb r1, [r4, 0x19]
	adds r3, r1, 0x2
	adds r0, r3, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r3, r0
	strb r0, [r4, 0x19]
	ldr r1, [r2]
	ldrb r0, [r1, 0x18]
	adds r0, 0x2
	strb r0, [r1, 0x18]
	ldr r1, =gUnknown_0203ABB5
	ldr r0, [r2]
	ldrb r0, [r0, 0x1A]
	strb r0, [r1]
	ldr r6, =gUnknown_0203ABB3
	mov r10, r2
	ldr r0, =gUnknown_0203ABB4
	mov r9, r0
_081513D4:
	mov r1, r10
	ldr r2, [r1]
	ldrb r0, [r2, 0x19]
	strb r0, [r6]
	ldr r0, =gUnknown_0203ABB5
	ldrb r0, [r0]
	adds r1, r0, r7
	adds r0, r1, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r1, r0
	mov r1, r9
	strb r0, [r1]
	ldrb r1, [r2, 0x18]
	lsls r1, 1
	lsls r0, r7, 1
	adds r0, r7
	lsls r5, r0, 3
	adds r1, r5
	adds r0, r2, 0
	adds r0, 0x22
	adds r0, r1
	ldrh r1, [r0]
	ldrb r2, [r6]
	mov r0, r9
	ldrb r3, [r0]
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x11
	mov r8, r0
	str r0, [sp, 0x8]
	movs r0, 0
	bl FillBgTilemapBufferRect
	ldrb r1, [r6]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r6]
	mov r0, r10
	ldr r1, [r0]
	ldrb r0, [r1, 0x18]
	adds r0, 0x1
	lsls r0, 1
	adds r0, r5
	adds r1, 0x22
	adds r1, r0
	ldrh r1, [r1]
	ldrb r2, [r6]
	mov r0, r9
	ldrb r3, [r0]
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	movs r0, 0
	bl FillBgTilemapBufferRect
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x8
	bls _081513D4
	ldr r4, =gUnknown_0203ABB4
	ldr r5, =gUnknown_0203ABAC
	ldr r3, [r5]
	ldrb r1, [r3, 0x1A]
	adds r2, r1, 0
	adds r2, 0x17
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	strb r0, [r4]
	ldrb r2, [r3, 0x19]
	ldrb r3, [r4]
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	bl FillBgTilemapBufferRect
	ldr r1, [r5]
	ldrb r0, [r1, 0x18]
	cmp r0, 0xA
	bne _081514A6
	ldrb r2, [r1, 0x1A]
	adds r3, r2, 0x3
	adds r0, r3, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r3, r0
	strb r0, [r1, 0x1A]
	ldr r1, [r5]
	movs r0, 0xFE
	strb r0, [r1, 0x18]
	bl sub_8151088
_081514A6:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8151388

	thumb_func_start sub_81514C8
sub_81514C8: @ 81514C8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081514D6
	cmp r0, 0x1
	beq _08151500
_081514D6:
	ldr r1, =gUnknown_0203ABAC
	ldr r2, [r1]
	movs r3, 0
	movs r0, 0x2
	strb r0, [r2, 0x1B]
	ldr r0, [r1]
	strb r3, [r0, 0x19]
	ldr r2, [r1]
	movs r0, 0x14
	strb r0, [r2, 0x1A]
	ldr r1, [r1]
	movs r0, 0xC
	strb r0, [r1, 0x18]
	bl sub_8151088
	bl sub_8151214
	b _08151522
	.pool
_08151500:
	ldr r1, =gUnknown_0203ABAC
	ldr r2, [r1]
	movs r0, 0x2
	strb r0, [r2, 0x1B]
	ldr r2, [r1]
	movs r0, 0x1C
	strb r0, [r2, 0x19]
	ldr r2, [r1]
	movs r0, 0x14
	strb r0, [r2, 0x1A]
	ldr r1, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x18]
	bl sub_8151088
	bl sub_8151388
_08151522:
	ldr r0, =gUnknown_0203ABAC
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x1C]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81514C8

	.align 2, 0 @ Don't pad with nop.
