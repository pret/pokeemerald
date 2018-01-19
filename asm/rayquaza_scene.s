	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81D6720
sub_81D6720: @ 81D6720
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gUnknown_0203CF60
	ldr r0, =0x00002018
	bl AllocZeroed
	str r0, [r6]
	ldr r1, =0x00002006
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0]
	ldr r1, =0x00002007
	adds r0, r1
	strb r5, [r0]
	ldr r0, =sub_81D6774
	bl SetMainCallback2
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6720

	thumb_func_start sub_81D6774
sub_81D6774: @ 81D6774
	push {lr}
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	bl remove_some_task
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	movs r0, 0
	movs r1, 0xF0
	movs r2, 0x20
	bl FillPalette
	ldr r1, =gUnknown_0862A6A0
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r2, =0x00002006
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81D67D0
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6774

	thumb_func_start sub_81D67D0
sub_81D67D0: @ 81D67D0
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81D67D0

	thumb_func_start sub_81D67EC
sub_81D67EC: @ 81D67EC
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81D67EC

	thumb_func_start sub_81D6800
sub_81D6800: @ 81D6800
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D6830
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r4, =gUnknown_0203CF60
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
_081D6830:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6800

	thumb_func_start sub_81D6840
sub_81D6840: @ 81D6840
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081D68B2
	ldr r2, =gUnknown_0203CF60
	ldr r1, [r2]
	ldr r4, =0x00002007
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081D6888
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81D6800
	b _081D68B0
	.pool
_081D6888:
	ldr r4, =0x00002006
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r2, [r2]
	ldr r1, =0x00002004
	adds r0, r2, r1
	strh r5, [r0]
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r3, =gUnknown_0862A6A0
	adds r2, r4
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
_081D68B0:
	str r0, [r1]
_081D68B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6840

	thumb_func_start sub_81D68C8
sub_81D68C8: @ 81D68C8
	push {lr}
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r1, =0x00001888
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =gPlttBufferUnfaded
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gPlttBufferFaded
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D68C8

	thumb_func_start sub_81D6904
sub_81D6904: @ 81D6904
	push {lr}
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81D6904

	thumb_func_start sub_81D691C
sub_81D691C: @ 81D691C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	bl sub_81D750C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D697E
	movs r0, 0
	ldrsh r1, [r5, r0]
	cmp r1, 0x40
	bne _081D6954
	bl sub_81D7438
	b _081D6978
	.pool
_081D6954:
	cmp r1, 0x90
	bne _081D695E
	bl sub_81D7480
	b _081D6978
_081D695E:
	cmp r1, 0x94
	beq _081D6974
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	bne _081D6978
	adds r0, r4, 0
	movs r1, 0
	bl sub_81D75B4
	b _081D697E
_081D6974:
	bl sub_81D74C8
_081D6978:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_081D697E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D691C

	thumb_func_start sub_81D6984
sub_81D6984: @ 81D6984
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0862A72C
	mov r8, r0
	movs r1, 0x58
	movs r2, 0x48
	movs r3, 0x3
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gSprites
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D6A20
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	mov r0, r8
	movs r1, 0x38
	movs r2, 0x68
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r0, =gUnknown_0862A750
	movs r1, 0x4B
	movs r2, 0x65
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2]
	ldr r0, =gUnknown_0862A774
	movs r1, 0x6D
	movs r2, 0x72
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6984

	thumb_func_start sub_81D6A20
sub_81D6A20: @ 81D6A20
	push {r4,lr}
	adds r3, r0, 0
	movs r0, 0x2E
	adds r0, r3
	mov r12, r0
	ldrh r0, [r0, 0xA]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	mov r1, r12
	strh r0, [r1, 0xA]
	cmp r0, 0
	bne _081D6A84
	ldrh r1, [r3, 0x20]
	movs r2, 0x20
	ldrsh r0, [r3, r2]
	cmp r0, 0x48
	beq _081D6A84
	subs r0, r1, 0x1
	strh r0, [r3, 0x20]
	ldr r2, =gSprites
	movs r4, 0x2E
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
_081D6A84:
	adds r0, r3, 0
	adds r0, 0x2B
	ldrb r3, [r0]
	cmp r3, 0x1
	beq _081D6AE4
	cmp r3, 0x1
	bgt _081D6A9C
	cmp r3, 0
	beq _081D6AA6
	b _081D6B68
	.pool
_081D6A9C:
	cmp r3, 0x2
	beq _081D6B24
	cmp r3, 0x3
	beq _081D6AE4
	b _081D6B68
_081D6AA6:
	ldr r2, =gSprites
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	b _081D6B5E
	.pool
_081D6AE4:
	ldr r2, =gSprites
	mov r0, r12
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	mov r4, r12
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0
	strh r3, [r0, 0x26]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	negs r1, r1
	b _081D6B58
	.pool
_081D6B24:
	ldr r2, =gSprites
	mov r3, r12
	movs r4, 0x2
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x1
	strh r3, [r0, 0x26]
	mov r4, r12
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
_081D6B58:
	strh r1, [r0, 0x24]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
_081D6B5E:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
_081D6B68:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6A20

	thumb_func_start sub_81D6B7C
sub_81D6B7C: @ 81D6B7C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r5, =gUnknown_0862A81C
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gSprites
	lsls r4, r0, 4
	add r4, r8
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D6D20
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0xA8
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0xA8
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	orrs r0, r1
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0xA8
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x68
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x6]
	adds r0, r5, 0
	movs r1, 0xB8
	movs r2, 0x80
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	orrs r0, r1
	strh r0, [r4, 0x6]
	ldr r0, =gUnknown_0862A84C
	movs r1, 0xD0
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0862A864
	movs r1, 0xC8
	movs r2, 0x78
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x8]
	orrs r0, r1
	strh r0, [r4, 0x8]
	ldrh r1, [r4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartSpriteAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	bl StartSpriteAnim
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x3
	bl StartSpriteAnim
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x4
	bl StartSpriteAnim
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	bl StartSpriteAnim
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x6
	bl StartSpriteAnim
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x7
	bl StartSpriteAnim
	ldrb r1, [r4, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x8
	bl StartSpriteAnim
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6B7C

	thumb_func_start sub_81D6D20
sub_81D6D20: @ 81D6D20
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r3, r4, 0
	adds r3, 0x2E
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r3, 0xA]
	ldr r7, =gSprites
	cmp r0, 0
	bne _081D6E0E
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x98
	beq _081D6E0E
	adds r0, r1, 0x1
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r4, 0x2E]
	movs r2, 0xFF
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x2]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x4]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x6]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x8]
	ands r2, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
_081D6E0E:
	adds r6, r7, 0
	movs r5, 0xFF
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2B
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _081D6EE0
	cmp r2, 0x1
	bgt _081D6E34
	cmp r2, 0
	beq _081D6E40
	b _081D6FC8
	.pool
_081D6E34:
	cmp r2, 0x2
	bne _081D6E3A
	b _081D6F68
_081D6E3A:
	cmp r2, 0x3
	beq _081D6EE0
	b _081D6FC8
_081D6E40:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x4]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x6]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	b _081D6FC6
_081D6EE0:
	movs r2, 0x1
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x8]
	b _081D6FBE
_081D6F68:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
_081D6FBE:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
_081D6FC6:
	strh r2, [r0, 0x26]
_081D6FC8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D6D20

	thumb_func_start sub_81D6FD0
sub_81D6FD0: @ 81D6FD0
	push {lr}
	bl sub_81D67EC
	bl sub_80BA0A8
	pop {r0}
	bx r0
	thumb_func_end sub_81D6FD0

	thumb_func_start sub_81D6FE0
sub_81D6FE0: @ 81D6FE0
	push {r4,lr}
	bl ResetVramOamAndBgCntRegs
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862A888
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
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
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6FE0

	thumb_func_start sub_81D706C
sub_81D706C: @ 81D706C
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gRaySceneClouds_Gfx
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D7082:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D7082
	ldr r0, =gRaySceneClouds2_Tilemap
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gRaySceneClouds1_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneClouds3_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneClouds_Pal
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0862A8C4
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A8F8
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A924
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A9D4
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AA14
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AA34
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A8CC
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862A9DC
	bl LoadCompressedObjectPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D706C

	thumb_func_start sub_81D7134
sub_81D7134: @ 81D7134
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r7, =gTasks + 0x8
	adds r5, r6, r7
	bl dp12_8087EA4
	bl sub_81D6FE0
	bl sub_81D706C
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r1, =gUnknown_02038C28
	ldr r2, =0x010003c0
	add r0, sp, 0x4
	bl CpuFastSet
	ldr r2, =gUnknown_0862A87C
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80BA038
	strh r4, [r5]
	ldr r0, =sub_81D7228
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x2]
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r1, =0x00002006
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D71CC
	bl sub_81D6984
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x4]
	bl sub_81D6B7C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x6]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D691C
	str r1, [r0]
	b _081D71EE
	.pool
_081D71CC:
	bl sub_81D7664
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x4]
	bl sub_81D78BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x6]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D736C
	str r1, [r0]
	bl StopMapMusic
_081D71EE:
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
	ldr r0, =sub_81D6FD0
	bl SetVBlankCallback
	movs r0, 0x53
	bl PlaySE
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7134

	thumb_func_start sub_81D7228
sub_81D7228: @ 81D7228
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r3, r1, r0
	movs r1, 0x18
	ldr r7, =gUnknown_0203CF60
	ldr r4, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r4, r0
_081D7244:
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r0, 0
	cmp r1, 0x2F
	bgt _081D726C
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3]
	b _081D72CA
	.pool
_081D726C:
	cmp r1, 0x3F
	bgt _081D7280
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x2]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x2]
	b _081D72CA
_081D7280:
	cmp r1, 0x4B
	bgt _081D7294
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x4]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x4]
	b _081D72CA
_081D7294:
	cmp r1, 0x53
	bgt _081D72A8
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x6]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x6]
	b _081D72CA
_081D72A8:
	cmp r1, 0x57
	bgt _081D72BC
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x8]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x8]
	b _081D72CA
_081D72BC:
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0xA]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0xA]
_081D72CA:
	lsrs r0, 8
	strh r0, [r1]
	movs r1, 0x80
	lsls r1, 9
	adds r0, r6, r1
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x5B
	ble _081D7244
	ldr r0, [r7]
	ldr r1, =0x00002006
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D7324
	movs r1, 0xE0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x2]
	adds r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x4]
	adds r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x6]
	adds r0, r1
	strh r0, [r3, 0x6]
	ldrh r0, [r3, 0x8]
	adds r0, 0xC0
	b _081D735E
	.pool
_081D7324:
	movs r1, 0xC0
	lsls r1, 2
	adds r0, r1, 0
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	movs r1, 0xA0
	lsls r1, 2
	adds r0, r1, 0
	ldrh r1, [r3, 0x2]
	adds r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	ldrh r1, [r3, 0x4]
	adds r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x6]
	adds r0, r1
	strh r0, [r3, 0x6]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x8]
	adds r0, r1
_081D735E:
	strh r0, [r3, 0x8]
	ldrh r0, [r3, 0xA]
	adds r0, 0x80
	strh r0, [r3, 0xA]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D7228

	thumb_func_start sub_81D736C
sub_81D736C: @ 81D736C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r7, =gTasks + 0x8
	adds r4, r0, r7
	bl sub_81D750C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _081D742E
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0x20
	beq _081D739C
	cmp r1, 0x70
	bne _081D73AC
_081D739C:
	bl sub_81D7438
	b _081D7428
	.pool
_081D73AC:
	cmp r1, 0xD8
	bne _081D73B6
	bl sub_81D7480
	b _081D7428
_081D73B6:
	cmp r1, 0xDC
	bne _081D73C0
	bl sub_81D74C8
	b _081D7428
_081D73C0:
	movs r0, 0xBE
	lsls r0, 1
	cmp r1, r0
	beq _081D73D8
	adds r0, 0x20
	cmp r1, r0
	bne _081D7428
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_81D75B4
	b _081D742E
_081D73D8:
	movs r1, 0x91
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	adds r2, r7, 0
	subs r2, 0x8
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_81D752C
	str r1, [r0]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r6, [r0, 0x8]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r4, 0x4]
	strh r1, [r0, 0xC]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r4, 0x6]
	strh r1, [r0, 0xE]
	bl remove_some_task
_081D7428:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081D742E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D736C

	thumb_func_start sub_81D7438
sub_81D7438: @ 81D7438
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0x57
	bl PlaySE
	ldr r0, =0x00007fff
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r4, 0
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
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7438

	thumb_func_start sub_81D7480
sub_81D7480: @ 81D7480
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0x57
	bl PlaySE
	ldr r0, =0x00007fff
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x10
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x10
	bl sub_80A2C44
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7480

	thumb_func_start sub_81D74C8
sub_81D74C8: @ 81D74C8
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =0x00007fff
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x4
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0x4
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D74C8

	thumb_func_start sub_81D750C
sub_81D750C: @ 81D750C
	push {lr}
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0x2
	movs r2, 0x1
	bl ChangeBgX
	movs r1, 0x80
	lsls r1, 4
	movs r0, 0x2
	movs r2, 0x2
	bl ChangeBgY
	pop {r0}
	bx r0
	thumb_func_end sub_81D750C

	thumb_func_start sub_81D752C
sub_81D752C: @ 81D752C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl sub_81D7860
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl sub_81D7D14
	movs r0, 0x1
	bl GetBgY
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	bl GetBgY
	cmp r0, 0
	beq _081D757A
	movs r0, 0x80
	lsls r0, 8
	cmp r4, r0
	bls _081D7586
_081D757A:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgY
_081D7586:
	ldrh r2, [r5]
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x10
	beq _081D75A6
	adds r2, 0x1
	strh r2, [r5]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_081D75A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D752C

	thumb_func_start sub_81D75B4
sub_81D75B4: @ 81D75B4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x54
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	lsls r4, 24
	asrs r4, 24
	movs r1, 0
	str r1, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D7600
	str r1, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D75B4

	thumb_func_start sub_81D7600
sub_81D7600: @ 81D7600
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r7, =gTasks + 0x8
	adds r5, r6, r7
	bl sub_81D750C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081D7652
	ldrb r0, [r5, 0x2]
	bl DestroyTask
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0
	bl SetVBlankCallback
	bl remove_some_task
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	strh r4, [r5]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D6840
	str r1, [r0]
_081D7652:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7600

	thumb_func_start sub_81D7664
sub_81D7664: @ 81D7664
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0862A8D4
	mov r8, r0
	movs r1, 0x62
	movs r2, 0x48
	movs r3, 0x3
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gSprites
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D7700
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	mov r0, r8
	movs r1, 0x42
	movs r2, 0x68
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r0, =gUnknown_0862A900
	movs r1, 0x55
	movs r2, 0x65
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2]
	ldr r0, =gUnknown_0862A92C
	movs r1, 0x77
	movs r2, 0x72
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D7664

	thumb_func_start sub_81D7700
sub_81D7700: @ 81D7700
	push {r4,lr}
	adds r3, r0, 0
	movs r0, 0x2E
	adds r0, r3
	mov r12, r0
	ldrh r0, [r0, 0xA]
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	mov r1, r12
	strh r0, [r1, 0xA]
	movs r1, 0x7
	ands r1, r0
	cmp r1, 0
	bne _081D7768
	ldrh r1, [r3, 0x20]
	movs r2, 0x20
	ldrsh r0, [r3, r2]
	cmp r0, 0x48
	beq _081D7768
	subs r0, r1, 0x1
	strh r0, [r3, 0x20]
	ldr r2, =gSprites
	movs r4, 0x2E
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
_081D7768:
	adds r0, r3, 0
	adds r0, 0x2B
	ldrb r3, [r0]
	cmp r3, 0x1
	beq _081D77C8
	cmp r3, 0x1
	bgt _081D7780
	cmp r3, 0
	beq _081D778A
	b _081D784C
	.pool
_081D7780:
	cmp r3, 0x2
	beq _081D7808
	cmp r3, 0x3
	beq _081D77C8
	b _081D784C
_081D778A:
	ldr r2, =gSprites
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	b _081D7842
	.pool
_081D77C8:
	ldr r2, =gSprites
	mov r0, r12
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	mov r4, r12
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0
	strh r3, [r0, 0x26]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	negs r1, r1
	b _081D783C
	.pool
_081D7808:
	ldr r2, =gSprites
	mov r3, r12
	movs r4, 0x2
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x1
	strh r3, [r0, 0x26]
	mov r4, r12
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
_081D783C:
	strh r1, [r0, 0x24]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
_081D7842:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
_081D784C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7700

	thumb_func_start sub_81D7860
sub_81D7860: @ 81D7860
	push {r4,lr}
	adds r1, r0, 0
	adds r3, r1, 0
	adds r3, 0x2E
	ldrh r2, [r1, 0x22]
	movs r4, 0x22
	ldrsh r0, [r1, r4]
	cmp r0, 0xA0
	bgt _081D78B0
	adds r0, r2, 0
	adds r0, 0x8
	strh r0, [r1, 0x22]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r1, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	movs r4, 0x2
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
_081D78B0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7860

	thumb_func_start sub_81D78BC
sub_81D78BC: @ 81D78BC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r5, =gUnknown_0862A9E4
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gSprites
	lsls r4, r0, 4
	add r4, r8
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D7A60
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0x9E
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x9E
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	orrs r0, r1
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0x9E
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x5E
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x6]
	adds r0, r5, 0
	movs r1, 0xAE
	movs r2, 0x80
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	orrs r0, r1
	strh r0, [r4, 0x6]
	ldr r0, =gUnknown_0862AA1C
	movs r1, 0xC6
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0862AA3C
	movs r1, 0xBE
	movs r2, 0x78
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x8]
	orrs r0, r1
	strh r0, [r4, 0x8]
	ldrh r1, [r4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartSpriteAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	bl StartSpriteAnim
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x3
	bl StartSpriteAnim
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x4
	bl StartSpriteAnim
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	bl StartSpriteAnim
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x6
	bl StartSpriteAnim
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x7
	bl StartSpriteAnim
	ldrb r1, [r4, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x8
	bl StartSpriteAnim
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D78BC

	thumb_func_start sub_81D7A60
sub_81D7A60: @ 81D7A60
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r3, r4, 0
	adds r3, 0x2E
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r3, 0xA]
	movs r1, 0x7
	ands r1, r0
	ldr r7, =gSprites
	cmp r1, 0
	bne _081D7B52
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x98
	beq _081D7B52
	adds r0, r1, 0x1
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r4, 0x2E]
	movs r2, 0xFF
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x2]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x4]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x6]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x8]
	ands r2, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
_081D7B52:
	adds r6, r7, 0
	movs r5, 0xFF
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2B
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _081D7C24
	cmp r2, 0x1
	bgt _081D7B78
	cmp r2, 0
	beq _081D7B84
	b _081D7D0C
	.pool
_081D7B78:
	cmp r2, 0x2
	bne _081D7B7E
	b _081D7CAC
_081D7B7E:
	cmp r2, 0x3
	beq _081D7C24
	b _081D7D0C
_081D7B84:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x4]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x6]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	b _081D7D0A
_081D7C24:
	movs r2, 0x1
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x8]
	b _081D7D02
_081D7CAC:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
_081D7D02:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
_081D7D0A:
	strh r2, [r0, 0x26]
_081D7D0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D7A60

	thumb_func_start sub_81D7D14
sub_81D7D14: @ 81D7D14
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	adds r0, r2
	mov r12, r0
	ldrh r1, [r2, 0x22]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r0, 0xA0
	bgt _081D7E08
	adds r0, r1, 0
	adds r0, 0x8
	strh r0, [r2, 0x22]
	ldr r3, =gSprites
	ldrh r1, [r2, 0x2E]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	ldrh r0, [r2, 0x2E]
	movs r2, 0xFF
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x2]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x4]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x6]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x8]
	ands r2, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
_081D7E08:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7D14

	thumb_func_start sub_81D7E10
sub_81D7E10: @ 81D7E10
	push {r4,lr}
	bl ResetVramOamAndBgCntRegs
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AA54
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
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
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7E10

	thumb_func_start sub_81D7E9C
sub_81D7E9C: @ 81D7E9C
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gRaySceneClouds_Gfx
	movs r4, 0
	str r4, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRaySceneOvercast_Gfx
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRaySceneRayquaza_Gfx
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D7ED0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D7ED0
	ldr r0, =gRaySceneClouds2_Tilemap
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gRaySceneOvercast_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneRayquaza_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneRayquaza_Pal
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0862AA90
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AA98
	bl LoadCompressedObjectPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7E9C

	thumb_func_start sub_81D7F4C
sub_81D7F4C: @ 81D7F4C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	movs r0, 0xE8
	lsls r0, 1
	bl PlayNewMapMusic
	bl sub_81D7E10
	bl sub_81D7E9C
	movs r1, 0x94
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000808
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	ldr r0, =sub_81D81A4
	movs r1, 0
	bl CreateTask
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81D7FC0
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7F4C

	thumb_func_start sub_81D7FC0
sub_81D7FC0: @ 81D7FC0
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _081D802A
	cmp r5, 0x1
	bgt _081D7FE8
	cmp r5, 0
	beq _081D7FF4
	b _081D815A
	.pool
_081D7FE8:
	cmp r5, 0x2
	beq _081D80A4
	cmp r5, 0x3
	bne _081D7FF2
	b _081D8124
_081D7FF2:
	b _081D815A
_081D7FF4:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _081D8024
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x4]
	movs r0, 0x1E
	strh r0, [r4, 0x6]
	strh r5, [r4, 0x8]
	movs r0, 0x7
	strh r0, [r4, 0xA]
	strh r5, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D815A
_081D8024:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _081D815A
_081D802A:
	ldrh r1, [r4, 0x6]
	ldrh r3, [r4, 0x4]
	adds r0, r1, r3
	strh r0, [r4, 0x4]
	ldrh r2, [r4, 0xA]
	ldrh r3, [r4, 0x8]
	adds r0, r2, r3
	strh r0, [r4, 0x8]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081D8046
	subs r0, r1, 0x3
	strh r0, [r4, 0x6]
_081D8046:
	lsls r0, r2, 16
	cmp r0, 0
	beq _081D8050
	subs r0, r2, 0x1
	strh r0, [r4, 0xA]
_081D8050:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _081D8078
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r4, 0x4]
	movs r1, 0
	strh r1, [r4, 0x6]
	movs r0, 0xC
	strh r0, [r4, 0xC]
	movs r3, 0x1
	negs r3, r3
	adds r0, r3, 0
	strh r0, [r4, 0xE]
	strh r1, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081D8078:
	movs r1, 0xF0
	lsls r1, 7
	movs r2, 0xC0
	lsls r2, 5
	ldrh r0, [r4, 0x8]
	adds r0, 0x20
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x4]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r3, 0x78
	bl SetBgAffine
	b _081D815A
_081D80A4:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0xF0
	lsls r1, 7
	movs r2, 0xC0
	lsls r2, 5
	ldrh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 18
	adds r0, 0x20
	ldrh r3, [r4, 0x8]
	adds r0, r3
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x4]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x8]
	movs r5, 0
	str r5, [sp, 0xC]
	movs r0, 0x2
	movs r3, 0x78
	bl SetBgAffine
	ldrh r0, [r4, 0xE]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0xC
	beq _081D80F4
	movs r0, 0xC
	negs r0, r0
	cmp r1, r0
	bne _081D815A
_081D80F4:
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	negs r0, r0
	strh r0, [r4, 0xE]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	ldr r0, =0x00000127
	cmp r1, r0
	ble _081D815A
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0x6
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _081D815A
	.pool
_081D8124:
	ldrh r0, [r4, 0x4]
	adds r0, 0x10
	strh r0, [r4, 0x4]
	movs r1, 0xF0
	lsls r1, 7
	movs r2, 0xC0
	lsls r2, 5
	ldrh r0, [r4, 0x8]
	adds r0, 0x20
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x4]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r3, 0x78
	bl SetBgAffine
	adds r0, r6, 0
	bl sub_81D8164
_081D815A:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D7FC0

	thumb_func_start sub_81D8164
sub_81D8164: @ 81D8164
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D8192
	movs r0, 0
	bl SetVBlankCallback
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81D6840
	str r0, [r1]
_081D8192:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8164

	thumb_func_start sub_81D81A4
sub_81D81A4: @ 81D81A4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r1, [r4, 0x2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081D8254
	ldr r0, =gUnknown_0862AAA0
	ldr r3, =gUnknown_0862AAB8
	movs r1, 0
	ldrsh r2, [r4, r1]
	lsls r2, 1
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 18
	movs r6, 0xF0
	lsls r6, 15
	adds r1, r6
	asrs r1, 16
	adds r3, 0x1
	adds r2, r3
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	lsls r2, 18
	movs r3, 0xA0
	lsls r3, 15
	adds r2, r3
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r1
	movs r0, 0
	ldrsb r0, [r4, r0]
	strh r0, [r3, 0x2E]
	ldrb r2, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	movs r2, 0x3
	orrs r0, r2
	strb r0, [r3, 0x1]
	ldrb r0, [r3, 0x5]
	ands r1, r0
	movs r0, 0x8
	orrs r1, r0
	strb r1, [r3, 0x5]
	adds r0, r3, 0
	bl InitSpriteAffineAnim
	ldrh r1, [r4]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r0, 0x9
	bne _081D8250
	adds r0, r5, 0
	bl DestroyTask
	b _081D825A
	.pool
_081D8250:
	adds r0, r1, 0x1
	strh r0, [r4]
_081D8254:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
_081D825A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D81A4

	thumb_func_start sub_81D8260
sub_81D8260: @ 81D8260
	push {lr}
	adds r2, r0, 0
	movs r1, 0x30
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _081D8270
	strh r0, [r2, 0x24]
	b _081D829A
_081D8270:
	ldr r1, =gUnknown_0862AAB8
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r3, [r2, 0x24]
	adds r0, r3
	strh r0, [r2, 0x24]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	adds r0, r1
_081D829A:
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r2, 0x30]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8260

	thumb_func_start sub_81D82B0
sub_81D82B0: @ 81D82B0
	push {r4,lr}
	bl ResetVramOamAndBgCntRegs
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AACC
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
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
	ldr r1, [r4]
	ldr r0, =0x00001804
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl ResetAllBgsCoordinates
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
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
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D82B0

	thumb_func_start sub_81D8358
sub_81D8358: @ 81D8358
	push {r4-r7,lr}
	sub sp, 0xC
	bl reset_temp_tile_data_buffers
	ldr r1, =gRaySceneRayquazaLight_Gfx
	movs r4, 0
	str r4, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRaySceneOvercast2_Gfx
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	add r7, sp, 0x8
_081D8380:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _081D8380
	ldr r0, =gRaySceneRayquazaLight_Tilemap
	ldr r5, =gUnknown_0203CF60
	ldr r1, [r5]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gRaySceneOvercast2_Tilemap
	ldr r1, [r5]
	ldr r4, =0x00001804
	adds r1, r4
	bl LZDecompressWram
	str r6, [sp, 0x4]
	ldr r1, [r5]
	ldr r0, =0x00001004
	adds r1, r0
	ldr r2, =0x01000200
	add r0, sp, 0x4
	bl CpuFastSet
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r0, =0x00000804
	adds r1, r0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r4, 0
	bl CpuFastSet
	str r6, [sp, 0x8]
	ldr r1, [r5]
	ldr r0, =0x00000904
	adds r1, r0
	ldr r2, =0x010000d0
	adds r0, r7, 0
	bl CpuFastSet
	ldr r0, =gRaySceneOvercast2_Pal
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	ldr r0, =gPlttBufferUnfaded
	ldr r1, =0x00007fff
	strh r1, [r0]
	ldr r0, =gPlttBufferFaded
	strh r1, [r0]
	ldr r0, =gUnknown_0862AAFC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AB04
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AB0C
	bl LoadCompressedObjectPalette
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8358

	thumb_func_start sub_81D844C
sub_81D844C: @ 81D844C
	push {r4,r5,lr}
	movs r0, 0x6
	bl GetGpuReg
	lsls r0, 16
	lsrs r2, r0, 16
	adds r1, r2, 0
	subs r1, 0x18
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x6F
	bhi _081D848C
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r3, =0x00002008
	adds r0, r3
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _081D848C
	ldr r1, =0x04000052
	ldr r3, =0x00000d08
	b _081D8492
	.pool
_081D848C:
	ldr r1, =0x04000052
	movs r3, 0x80
	lsls r3, 5
_081D8492:
	adds r0, r3, 0
	strh r0, [r1]
	cmp r2, 0
	bne _081D84E0
	ldr r0, =gUnknown_0203CF60
	ldr r1, [r0]
	ldr r2, =0x00002008
	adds r3, r1, r2
	ldrh r4, [r3]
	movs r1, 0
	ldrsh r2, [r3, r1]
	ldr r1, =0x00001fff
	adds r5, r0, 0
	cmp r2, r1
	bgt _081D84D4
	cmp r2, 0x27
	bgt _081D84C8
	adds r0, r4, 0x4
	b _081D84D2
	.pool
_081D84C8:
	cmp r2, 0x4F
	bgt _081D84D0
	adds r0, r4, 0x2
	b _081D84D2
_081D84D0:
	adds r0, r4, 0x1
_081D84D2:
	strh r0, [r3]
_081D84D4:
	ldr r1, [r5]
	ldr r2, =0x0000200a
	adds r1, r2
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_081D84E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D844C

	thumb_func_start sub_81D84EC
sub_81D84EC: @ 81D84EC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	bl sub_81D82B0
	bl sub_81D8358
	ldr r1, =0x00001e41
	movs r0, 0x50
	bl SetGpuRegBits
	movs r0, 0x80
	lsls r0, 5
	mov r8, r0
	movs r0, 0x52
	mov r1, r8
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r1, =0x00002008
	adds r2, r0, r1
	movs r1, 0
	strh r1, [r2]
	ldr r2, =0x0000200a
	adds r0, r2
	strh r1, [r0]
	strh r1, [r5]
	strh r1, [r5, 0x2]
	strh r1, [r5, 0x4]
	strh r1, [r5, 0x6]
	mov r0, r8
	strh r0, [r5, 0x8]
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_81D857C
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D84EC

	thumb_func_start sub_81D857C
sub_81D857C: @ 81D857C
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bhi _081D8674
	lsls r0, 2
	ldr r1, =_081D85A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D85A8:
	.4byte _081D85BC
	.4byte _081D85DC
	.4byte _081D861A
	.4byte _081D863A
	.4byte _081D8656
_081D85BC:
	ldrh r1, [r5, 0x2]
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x8
	bne _081D8634
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r4, [r5, 0x2]
	b _081D864E
_081D85DC:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081D8674
	ldrh r2, [r5, 0x2]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	cmp r0, 0xA
	bne _081D8614
	strh r1, [r5, 0x2]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	ldr r0, =sub_81D844C
	bl SetHBlankCallback
	movs r0, 0x3
	bl EnableInterrupts
	b _081D8674
	.pool
_081D8614:
	adds r0, r2, 0x1
	strh r0, [r5, 0x2]
	b _081D8674
_081D861A:
	ldrh r1, [r5, 0x2]
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x50
	bne _081D8634
	movs r0, 0
	strh r0, [r5, 0x2]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	bl sub_81D86CC
	b _081D8674
_081D8634:
	adds r0, r1, 0x1
	strh r0, [r5, 0x2]
	b _081D8674
_081D863A:
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
	lsls r0, 16
	movs r1, 0xB8
	lsls r1, 17
	cmp r0, r1
	bne _081D8674
	movs r0, 0
	strh r0, [r5, 0x2]
_081D864E:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _081D8674
_081D8656:
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
	ldr r1, =sub_81D8684
	str r1, [r0]
_081D8674:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D857C

	thumb_func_start sub_81D8684
sub_81D8684: @ 81D8684
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D86B8
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81D6840
	str r0, [r1]
_081D86B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8684

	thumb_func_start sub_81D86CC
sub_81D86CC: @ 81D86CC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0862AB14
	movs r1, 0xA0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r5, r6, 4
	adds r5, r6
	lsls r5, 2
	ldr r4, =gSprites + 0x2E
	adds r0, r5, r4
	mov r8, r0
	ldr r0, =gUnknown_0862AB2C
	movs r2, 0x30
	negs r2, r2
	movs r1, 0xB8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1]
	adds r3, r4, 0
	subs r3, 0x2E
	subs r4, 0x12
	adds r4, r5, r4
	ldr r0, =sub_81D874C
	str r0, [r4]
	adds r5, r3
	ldrb r0, [r5, 0x5]
	movs r2, 0xC
	orrs r0, r2
	strb r0, [r5, 0x5]
	movs r4, 0
	ldrsh r1, [r1, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x5]
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D86CC

	thumb_func_start sub_81D874C
sub_81D874C: @ 81D874C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081D8764
	movs r0, 0xC
	strh r0, [r4, 0x6]
	movs r0, 0x8
	b _081D87C2
_081D8764:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _081D8774
	movs r0, 0x9
	strh r0, [r4, 0x6]
	movs r0, 0x7
	b _081D87C2
_081D8774:
	movs r0, 0x86
	lsls r0, 1
	cmp r1, r0
	bne _081D8784
	movs r0, 0x8
	strh r0, [r4, 0x6]
	movs r0, 0x6
	b _081D87C2
_081D8784:
	movs r0, 0x8C
	lsls r0, 1
	cmp r1, r0
	bne _081D8794
	movs r0, 0x7
	strh r0, [r4, 0x6]
	movs r0, 0x5
	b _081D87C2
_081D8794:
	movs r0, 0x92
	lsls r0, 1
	cmp r1, r0
	bne _081D87A4
	movs r0, 0x6
	strh r0, [r4, 0x6]
	movs r0, 0x4
	b _081D87C2
_081D87A4:
	movs r0, 0x98
	lsls r0, 1
	cmp r1, r0
	bne _081D87B4
	movs r0, 0x5
	strh r0, [r4, 0x6]
	movs r0, 0x3
	b _081D87C2
_081D87B4:
	movs r0, 0xA0
	lsls r0, 1
	cmp r1, r0
	bne _081D87C4
	movs r0, 0x4
	strh r0, [r4, 0x6]
	movs r0, 0x2
_081D87C2:
	strh r0, [r4, 0x8]
_081D87C4:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _081D87EE
	ldrh r0, [r5, 0x24]
	subs r0, 0x1
	strh r0, [r5, 0x24]
	ldr r2, =gSprites
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	subs r1, 0x1
	strh r1, [r0, 0x24]
_081D87EE:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _081D8818
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	ldr r2, =gSprites
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x1
	strh r1, [r0, 0x26]
_081D8818:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D874C

	thumb_func_start sub_81D8828
sub_81D8828: @ 81D8828
	push {r4,lr}
	bl ResetVramOamAndBgCntRegs
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AB44
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
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
	ldr r1, [r4]
	ldr r0, =0x00001804
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl ResetAllBgsCoordinates
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
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
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8828

	thumb_func_start sub_81D88D0
sub_81D88D0: @ 81D88D0
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gRaySceneRayquazaChase_Gfx
	movs r4, 0
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRaySceneChaseStreaks_Gfx
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRaySceneChaseBg_Gfx
	str r4, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D8904:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D8904
	ldr r0, =gRayChaseRayquazaChase2_Tilemap
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gRayChaseRayquazaChase_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneChaseStreaks_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneChaseBg_Tilemap
	ldr r1, [r4]
	ldr r2, =0x00001804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gRaySceneChase_Pal
	movs r1, 0
	movs r2, 0x80
	bl LoadCompressedPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D88D0

	thumb_func_start sub_81D8980
sub_81D8980: @ 81D8980
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	bl sub_81D8828
	bl sub_81D88D0
	bl sub_81D68C8
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
	ldr r0, =sub_81D8AD8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x4]
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81D89E0
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8980

	thumb_func_start sub_81D89E0
sub_81D89E0: @ 81D89E0
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81D8BB4
	ldrh r1, [r4, 0x6]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _081D8A16
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bgt _081D8A16
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x59
	bgt _081D8A16
	movs r0, 0x67
	bl PlaySE
_081D8A16:
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
	movs r0, 0
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _081D8A5C
	cmp r5, 0x1
	bgt _081D8A34
	cmp r5, 0
	beq _081D8A3E
	b _081D8AC6
	.pool
_081D8A34:
	cmp r5, 0x2
	beq _081D8A8C
	cmp r5, 0x3
	beq _081D8AA8
	b _081D8AC6
_081D8A3E:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _081D8AA2
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x2]
	b _081D8A9A
_081D8A5C:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x7F
	bne _081D8AA2
	movs r0, 0
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldr r2, =gTasks
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_81D8B2C
	b _081D8AC4
	.pool
_081D8A8C:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0xC
	bne _081D8AA2
	movs r0, 0
	strh r0, [r4, 0x2]
_081D8A9A:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D8AC6
_081D8AA2:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _081D8AC6
_081D8AA8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D8BEC
_081D8AC4:
	str r1, [r0]
_081D8AC6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D89E0

	thumb_func_start sub_81D8AD8
sub_81D8AD8: @ 81D8AD8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	ldrh r1, [r5, 0x1E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081D8B1C
	bl Random
	movs r4, 0x7
	adds r1, r4, 0
	ands r1, r0
	subs r1, 0x4
	lsls r1, 8
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgX
	bl Random
	ands r4, r0
	subs r4, 0x4
	lsls r4, 8
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgY
_081D8B1C:
	ldrh r0, [r5, 0x1E]
	adds r0, 0x1
	strh r0, [r5, 0x1E]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8AD8

	thumb_func_start sub_81D8B2C
sub_81D8B2C: @ 81D8B2C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D8B70
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0xA
	strh r0, [r4, 0x2]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _081D8BAA
	.pool
_081D8B70:
	cmp r0, 0x1
	bne _081D8BAC
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r1, 8
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgX
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r1, 8
	movs r0, 0x1
	movs r2, 0x1
	bl ChangeBgY
	ldrh r0, [r4, 0x4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA
	negs r1, r1
	cmp r0, r1
	bne _081D8BAC
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	negs r0, r0
_081D8BAA:
	strh r0, [r4, 0x4]
_081D8BAC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D8B2C

	thumb_func_start sub_81D8BB4
sub_81D8BB4: @ 81D8BB4
	push {r4,lr}
	movs r4, 0x80
	lsls r4, 3
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgX
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	movs r4, 0x80
	lsls r4, 4
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgX
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D8BB4

	thumb_func_start sub_81D8BEC
sub_81D8BEC: @ 81D8BEC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	bl sub_81D8BB4
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D8C26
	movs r0, 0
	bl SetVBlankCallback
	bl sub_81D6904
	ldrb r0, [r4, 0x4]
	bl DestroyTask
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_81D6840
	str r1, [r0]
_081D8C26:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8BEC

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
	ldr r4, =gUnknown_0203CF60
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
	ldr r4, =gUnknown_0203CF60
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
	ldr r1, =sub_81D6840
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
