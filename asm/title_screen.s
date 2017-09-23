	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80AA40C
sub_80AA40C: @ 80AA40C
	push {lr}
	adds r3, r0, 0
	ldr r2, =gTasks
	movs r0, 0x30
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080AA43C
	ldrb r0, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	strb r1, [r3, 0x1]
	movs r0, 0x42
	strh r0, [r3, 0x22]
	b _080AA46A
	.pool
_080AA43C:
	ldrh r1, [r3, 0x22]
	movs r2, 0x22
	ldrsh r0, [r3, r2]
	cmp r0, 0x42
	beq _080AA44A
	adds r0, r1, 0x1
	strh r0, [r3, 0x22]
_080AA44A:
	ldrh r1, [r3, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _080AA458
	subs r0, r1, 0x1
	strh r0, [r3, 0x2E]
_080AA458:
	ldr r0, =gUnknown_0853FF70
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	lsls r1, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x52
	bl SetGpuReg
_080AA46A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA40C

	thumb_func_start sub_80AA474
sub_80AA474: @ 80AA474
	push {lr}
	adds r3, r0, 0
	ldr r2, =gTasks
	movs r0, 0x30
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080AA4A0
	ldrb r0, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	strb r1, [r3, 0x1]
	movs r0, 0x42
	b _080AA4AC
	.pool
_080AA4A0:
	ldrh r1, [r3, 0x22]
	movs r2, 0x22
	ldrsh r0, [r3, r2]
	cmp r0, 0x42
	beq _080AA4AE
	adds r0, r1, 0x1
_080AA4AC:
	strh r0, [r3, 0x22]
_080AA4AE:
	pop {r0}
	bx r0
	thumb_func_end sub_80AA474

	thumb_func_start sub_80AA4B4
sub_80AA4B4: @ 80AA4B4
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	bne _080AA4DC
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080AA4DC
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _080AA4E8
_080AA4DC:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_080AA4E8:
	pop {r0}
	bx r0
	thumb_func_end sub_80AA4B4

	thumb_func_start sub_80AA4EC
sub_80AA4EC: @ 80AA4EC
	push {r4-r7,lr}
	lsls r0, 16
	ldr r2, =0xffc00000
	adds r0, r2
	lsrs r0, 16
	movs r6, 0
	lsls r7, r1, 16
_080AA4FA:
	lsls r5, r0, 16
	asrs r5, 16
	ldr r0, =gUnknown_085400D8
	adds r1, r5, 0
	asrs r2, r7, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	adds r1, r6, 0
	bl StartSpriteAnim
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r5, 0x20
	lsls r5, 16
	lsrs r0, r5, 16
	cmp r6, 0x4
	bls _080AA4FA
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA4EC

	thumb_func_start sub_80AA548
sub_80AA548: @ 80AA548
	push {r4-r6,lr}
	lsls r0, 16
	ldr r2, =0xffc00000
	adds r0, r2
	lsrs r0, 16
	movs r5, 0
	lsls r6, r1, 16
_080AA556:
	lsls r4, r0, 16
	asrs r4, 16
	ldr r0, =gUnknown_085400D8
	adds r1, r4, 0
	asrs r2, r6, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r1, r5, 0x5
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl StartSpriteAnim
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x20
	lsls r4, 16
	lsrs r0, r4, 16
	cmp r5, 0x4
	bls _080AA556
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA548

	thumb_func_start title_screen_logo_shine_obj_callback_type1
@ void title_screen_logo_shine_obj_callback_type1(struct obj *obj)
title_screen_logo_shine_obj_callback_type1: @ 80AA5A4
	push {r4,lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x20]
	movs r0, 0x20
	ldrsh r1, [r3, r0]
	ldr r0, =0x0000010f
	cmp r1, r0
	bgt _080AA63C
	movs r4, 0x2E
	ldrsh r0, [r3, r4]
	adds r4, r2, 0
	cmp r0, 0
	beq _080AA630
	cmp r1, 0x77
	bgt _080AA5E0
	ldrh r1, [r3, 0x30]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r0, 0x1E
	bgt _080AA5F8
	adds r1, 0x1
	strh r1, [r3, 0x30]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x1E
	bgt _080AA5F8
	adds r0, r1, 0x1
	b _080AA5F6
	.pool
_080AA5E0:
	ldrh r1, [r3, 0x30]
	movs r4, 0x30
	ldrsh r0, [r3, r4]
	cmp r0, 0
	beq _080AA5F8
	subs r0, r1, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	cmp r0, 0
	beq _080AA5F8
	subs r0, r1, 0x2
_080AA5F6:
	strh r0, [r3, 0x30]
_080AA5F8:
	ldrh r1, [r3, 0x30]
	movs r0, 0x1F
	ands r0, r1
	lsls r2, r0, 10
	lsls r1, r0, 5
	adds r2, r1
	orrs r2, r0
	movs r1, 0x20
	ldrsh r0, [r3, r1]
	ldrh r4, [r3, 0x20]
	cmp r0, 0x84
	beq _080AA61C
	cmp r0, 0x88
	beq _080AA61C
	cmp r0, 0x8C
	beq _080AA61C
	cmp r0, 0x90
	bne _080AA62C
_080AA61C:
	ldr r1, =gPlttBufferFaded
	ldr r0, =0x000033f8
	strh r0, [r1]
	b _080AA630
	.pool
_080AA62C:
	ldr r0, =gPlttBufferFaded
	strh r2, [r0]
_080AA630:
	adds r0, r4, 0x4
	strh r0, [r3, 0x20]
	b _080AA648
	.pool
_080AA63C:
	ldr r1, =gPlttBufferFaded
	movs r0, 0
	strh r0, [r1]
	adds r0, r3, 0
	bl DestroySprite
_080AA648:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end title_screen_logo_shine_obj_callback_type1

	thumb_func_start title_screen_logo_shine_obj_callback_type2
@ void title_screen_logo_shine_obj_callback_type2(struct obj *obj)
title_screen_logo_shine_obj_callback_type2: @ 80AA654
	push {lr}
	adds r2, r0, 0
	ldrh r3, [r2, 0x20]
	movs r0, 0x20
	ldrsh r1, [r2, r0]
	ldr r0, =0x0000010f
	cmp r1, r0
	bgt _080AA670
	adds r0, r3, 0
	adds r0, 0x8
	strh r0, [r2, 0x20]
	b _080AA676
	.pool
_080AA670:
	adds r0, r2, 0
	bl DestroySprite
_080AA676:
	pop {r0}
	bx r0
	thumb_func_end title_screen_logo_shine_obj_callback_type2

	thumb_func_start title_screen_add_logo_shine_obj
@ void title_screen_add_logo_shine_obj(int a1)
title_screen_add_logo_shine_obj: @ 80AA67C
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	beq _080AA6D0
	cmp r5, 0x1
	bgt _080AA698
	cmp r5, 0
	beq _080AA69C
	b _080AA766
_080AA698:
	cmp r5, 0x2
	bne _080AA766
_080AA69C:
	ldr r0, =gUnknown_08540124
	movs r1, 0
	movs r2, 0x44
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x1]
	strh r5, [r0, 0x2E]
	b _080AA766
	.pool
_080AA6D0:
	ldr r0, =gUnknown_08540124
	mov r9, r0
	movs r1, 0
	movs r2, 0x44
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r6, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x1]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	movs r2, 0x8
	mov r8, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x1]
	strh r5, [r1, 0x2E]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	mov r0, r9
	movs r1, 0
	movs r2, 0x44
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r5, r6, 0
	adds r5, 0x1C
	adds r0, r1, r5
	ldr r2, =title_screen_logo_shine_obj_callback_type2
	mov r10, r2
	str r2, [r0]
	adds r1, r6
	ldrb r2, [r1, 0x1]
	adds r0, r4, 0
	ands r0, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x1]
	movs r1, 0x50
	negs r1, r1
	mov r0, r9
	movs r2, 0x44
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r5
	mov r1, r10
	str r1, [r5]
	adds r0, r6
	ldrb r1, [r0, 0x1]
	ands r4, r1
	mov r2, r8
	orrs r4, r2
	strb r4, [r0, 0x1]
_080AA766:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end title_screen_add_logo_shine_obj

	thumb_func_start title_screen_vblank_callback
@ void title_screen_vblank_callback()
title_screen_vblank_callback: @ 80AA780
	push {lr}
	bl sub_80BA0A8
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	ldr r0, =gUnknown_02022E1A
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end title_screen_vblank_callback

	thumb_func_start c2_title_screen_1
@ void c2_title_screen_1()
c2_title_screen_1: @ 80AA7A4
	push {r4,lr}
	sub sp, 0x14
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _080AA7E0
	lsls r0, 2
	ldr r1, =_080AA7C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AA7C8:
	.4byte _080AA7E0
	.4byte _080AA8C4
	.4byte _080AA998
	.4byte _080AA9E0
	.4byte _080AAA14
	.4byte _080AAAF0
_080AA7E0:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x00007fff
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
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
	add r1, sp, 0xC
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	add r0, sp, 0xC
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0
	str r2, [sp, 0x10]
	add r0, sp, 0x10
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add r0, sp, 0xC
	strh r2, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl ResetPaletteFade
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _080AAB1E
	.pool
_080AA8C4:
	ldr r0, =gTitleScreenPokemonLogoTiles
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_08DE0644
	ldr r1, =0x06004800
	bl LZ77UnCompVram
	ldr r0, =gTitleScreenBgPalettes
	movs r2, 0xF0
	lsls r2, 1
	movs r1, 0
	bl LoadPalette
	ldr r0, =gTitleScreenRayquazaTiles
	ldr r1, =0x06008000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_0853F83C
	ldr r1, =0x0600d000
	bl LZ77UnCompVram
	ldr r0, =gTitleScreenCloudsTiles
	ldr r1, =0x0600c000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_08DDE458
	ldr r1, =0x0600d800
	bl LZ77UnCompVram
	bl remove_some_task
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x9
	strb r0, [r1]
	ldr r0, =gUnknown_08540048
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085400F0
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0854013C
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08DDE438
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08540100
	bl LoadSpritePalette
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0]
	b _080AAB1E
	.pool
_080AA998:
	ldr r0, =task_title_screen_1
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r1, 0x8]
	strh r2, [r1, 0xA]
	ldr r0, =0x0000fff0
	strh r0, [r1, 0xC]
	subs r0, 0x10
	strh r0, [r1, 0xE]
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
	b _080AAB1E
	.pool
_080AA9E0:
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =title_screen_vblank_callback
	bl SetVBlankCallback
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x4
	strb r1, [r0]
	b _080AAB1E
	.pool
_080AAA14:
	movs r2, 0x80
	lsls r2, 1
	movs r0, 0x78
	movs r1, 0x50
	movs r3, 0
	bl sub_816F2A8
	movs r1, 0xE3
	lsls r1, 8
	movs r0, 0x28
	bl SetGpuReg
	ldr r4, =0x0000ffff
	movs r0, 0x2A
	adds r1, r4, 0
	bl SetGpuReg
	movs r1, 0xE0
	lsls r1, 8
	movs r0, 0x2C
	bl SetGpuReg
	movs r0, 0x2E
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001f1f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f1f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0x84
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0xC
	bl SetGpuReg
	ldr r1, =0x00001a0b
	movs r0, 0x8
	bl SetGpuReg
	ldr r1, =0x00001b0e
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =0x00004981
	movs r0, 0xC
	bl SetGpuReg
	movs r0, 0x1
	bl EnableInterrupts
	ldr r1, =0x0000b441
	movs r0, 0
	bl SetGpuReg
	ldr r0, =0x0000019d
	bl m4aSongNumStart
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	b _080AAB1E
	.pool
_080AAAF0:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080AAB1E
	movs r0, 0
	bl title_screen_add_logo_shine_obj
	str r4, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0xA0
	movs r2, 0x4
	movs r3, 0x4
	bl sub_80BA384
	ldr r0, =c2_title_screen_2
	bl SetMainCallback2
_080AAB1E:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_title_screen_1

	thumb_func_start c2_title_screen_2
@ void c2_title_screen_2()
c2_title_screen_2: @ 80AAB2C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end c2_title_screen_2

	thumb_func_start task_title_screen_1
@ void task_title_screen_1(int task_id)
task_title_screen_1: @ 80AAB44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF
	ands r0, r1
	ldr r6, =gTasks
	cmp r0, 0
	bne _080AAB6A
	lsls r0, r5, 2
	adds r1, r0, r5
	lsls r1, 3
	adds r1, r6
	movs r2, 0xA
	ldrsh r1, [r1, r2]
	adds r4, r0, 0
	cmp r1, 0
	beq _080AAB7C
_080AAB6A:
	lsls r3, r5, 2
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r6
	movs r2, 0
	movs r1, 0x1
	strh r1, [r0, 0xA]
	strh r2, [r0, 0x8]
	adds r4, r3, 0
_080AAB7C:
	adds r0, r4, r5
	lsls r0, 3
	adds r6, r0, r6
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _080AABC0
	ldrh r0, [r6, 0x8]
	cmp r0, 0xB0
	bne _080AABA0
	movs r0, 0x1
	bl title_screen_add_logo_shine_obj
	b _080AABAA
	.pool
_080AABA0:
	cmp r0, 0x40
	bne _080AABAA
	movs r0, 0x2
	bl title_screen_add_logo_shine_obj
_080AABAA:
	ldr r0, =gTasks
	adds r1, r4, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	subs r0, 0x1
	strh r0, [r1, 0x8]
	b _080AAC32
	.pool
_080AABC0:
	ldr r1, =0x00001441
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00003f50
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_08540018
	movs r1, 0x62
	movs r2, 0x2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	movs r0, 0x40
	strh r0, [r1, 0x2E]
	strh r5, [r1, 0x30]
	ldr r0, =gUnknown_08540030
	movs r1, 0xA2
	movs r2, 0x2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	strh r5, [r1, 0x30]
	movs r0, 0x90
	strh r0, [r6, 0x8]
	ldr r0, =task_title_screen_2
	str r0, [r6]
_080AAC32:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_title_screen_1

	thumb_func_start task_title_screen_2
@ void task_title_screen_2(int task_id)
task_title_screen_2: @ 80AAC50
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF
	ands r0, r1
	ldr r2, =gTasks
	cmp r0, 0
	bne _080AAC76
	lsls r0, r4, 2
	adds r1, r0, r4
	lsls r1, 3
	adds r1, r2
	movs r3, 0xA
	ldrsh r1, [r1, r3]
	adds r6, r0, 0
	cmp r1, 0
	beq _080AAC88
_080AAC76:
	lsls r3, r4, 2
	adds r0, r3, r4
	lsls r0, 3
	adds r0, r2
	movs r2, 0
	movs r1, 0x1
	strh r1, [r0, 0xA]
	strh r2, [r0, 0x8]
	adds r6, r3, 0
_080AAC88:
	ldr r1, =gTasks
	adds r0, r6, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x8]
	movs r1, 0x8
	ldrsh r7, [r5, r1]
	cmp r7, 0
	beq _080AACA8
	subs r0, 0x1
	strh r0, [r5, 0x8]
	b _080AACE2
	.pool
_080AACA8:
	movs r0, 0x1
	strh r0, [r5, 0xA]
	ldr r1, =0x00002142
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000f06
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001741
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x80
	movs r1, 0x6C
	bl sub_80AA4EC
	movs r0, 0x80
	movs r1, 0x94
	bl sub_80AA548
	strh r7, [r5, 0x10]
	ldr r0, =task_title_screen_3
	str r0, [r5]
_080AACE2:
	ldr r2, =gTasks
	adds r0, r6, r4
	lsls r0, 3
	adds r3, r0, r2
	ldrh r1, [r3, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080AAD02
	ldrh r1, [r3, 0xC]
	movs r5, 0xC
	ldrsh r0, [r3, r5]
	cmp r0, 0
	beq _080AAD02
	adds r0, r1, 0x1
	strh r0, [r3, 0xC]
_080AAD02:
	adds r0, r6, r4
	lsls r0, 3
	adds r3, r0, r2
	ldrh r1, [r3, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080AAD20
	ldrh r1, [r3, 0xE]
	movs r5, 0xE
	ldrsh r0, [r3, r5]
	cmp r0, 0
	beq _080AAD20
	adds r0, r1, 0x1
	strh r0, [r3, 0xE]
_080AAD20:
	adds r4, r6, r4
	lsls r4, 3
	adds r4, r2
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r5, r1, 8
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x2C
	bl SetGpuReg
	lsrs r5, 16
	movs r0, 0x2E
	adds r1, r5, 0
	bl SetGpuReg
	movs r0, 0xF
	strh r0, [r4, 0x12]
	movs r0, 0x6
	strh r0, [r4, 0x14]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_title_screen_2

	thumb_func_start task_title_screen_3
@ void task_title_screen_3(int task_id)
task_title_screen_3: @ 80AAD64
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080AAD84
	movs r0, 0x8
	ands r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080AADB0
_080AAD84:
	movs r0, 0x4
	bl FadeOutBGM
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =Cb2_GoToMainMenu
	bl SetMainCallback2
	b _080AAE98
	.pool
_080AADB0:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x46
	ands r0, r1
	cmp r0, 0x46
	bne _080AADC8
	ldr r0, =c2_clear_save_data_screen_1
	bl SetMainCallback2
	b _080AAE98
	.pool
_080AADC8:
	movs r0, 0x26
	ands r0, r1
	cmp r0, 0x26
	bne _080AADFC
	bl CanResetRTC
	cmp r0, 0x1
	bne _080AADFC
	movs r0, 0x4
	bl FadeOutBGM
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =c2_reset_rtc_screen_1
	bl SetMainCallback2
	b _080AAE98
	.pool
_080AADFC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0x6
	bne _080AAE30
	movs r0, 0x4
	bl FadeOutBGM
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =c2_berry_program_update_screen_1
	bl SetMainCallback2
	b _080AAE98
	.pool
_080AAE30:
	movs r0, 0x2C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x2E
	movs r1, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r1
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080AAE72
	ldrh r0, [r3, 0x10]
	adds r0, 0x1
	strh r0, [r3, 0x10]
	ldr r2, =gUnknown_02022E1A
	movs r1, 0x10
	ldrsh r0, [r3, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r2]
	ldr r1, =gUnknown_02022E18
	movs r0, 0
	strh r0, [r1]
_080AAE72:
	ldrb r0, [r3, 0x8]
	bl title_screen_update_rayquaza_ring_palette
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	bne _080AAE98
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =c2_show_copyright_and_intro_again_1
	bl SetMainCallback2
_080AAE98:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_title_screen_3

	thumb_func_start Cb2_GoToMainMenu
Cb2_GoToMainMenu: @ 80AAEB8
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080AAECA
	ldr r0, =CB2_InitMainMenu
	bl SetMainCallback2
_080AAECA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end Cb2_GoToMainMenu

	thumb_func_start c2_show_copyright_and_intro_again_1
c2_show_copyright_and_intro_again_1: @ 80AAED4
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080AAEE6
	ldr r0, =c2_show_copyright_and_intro_again_2
	bl SetMainCallback2
_080AAEE6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_show_copyright_and_intro_again_1

	thumb_func_start c2_clear_save_data_screen_1
c2_clear_save_data_screen_1: @ 80AAEF0
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080AAF02
	ldr r0, =c2_clear_save_data_screen_2
	bl SetMainCallback2
_080AAF02:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_clear_save_data_screen_1

	thumb_func_start c2_reset_rtc_screen_1
c2_reset_rtc_screen_1: @ 80AAF0C
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080AAF1E
	ldr r0, =sub_809EF88
	bl SetMainCallback2
_080AAF1E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_reset_rtc_screen_1

	thumb_func_start c2_berry_program_update_screen_1
c2_berry_program_update_screen_1: @ 80AAF28
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080AAF3E
	bl m4aMPlayAllStop
	ldr r0, =InitBerryFixProgram
	bl SetMainCallback2
_080AAF3E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_berry_program_update_screen_1

	thumb_func_start title_screen_update_rayquaza_ring_palette
@ void title_screen_update_rayquaza_ring_palette(u8 a1)
title_screen_update_rayquaza_ring_palette: @ 80AAF48
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080AAF9C
	adds r0, r1, 0
	movs r1, 0x80
	bl Cos
	lsls r0, 16
	asrs r0, 16
	adds r2, r0, 0
	adds r2, 0x80
	lsls r0, r2, 5
	subs r0, r2
	cmp r0, 0
	bge _080AAF72
	adds r0, 0xFF
_080AAF72:
	asrs r0, 8
	movs r3, 0x1F
	subs r1, r3, r0
	movs r0, 0x16
	muls r0, r2
	cmp r0, 0
	bge _080AAF82
	adds r0, 0xFF
_080AAF82:
	asrs r0, 8
	subs r0, r3, r0
	lsls r0, 5
	orrs r1, r0
	movs r0, 0xC0
	lsls r0, 6
	orrs r1, r0
	mov r0, sp
	strh r1, [r0]
	movs r1, 0xEF
	movs r2, 0x2
	bl LoadPalette
_080AAF9C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end title_screen_update_rayquaza_ring_palette

	.align 2, 0 @ Don't pad with nop.
