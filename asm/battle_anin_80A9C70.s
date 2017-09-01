	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text
    
    
	thumb_func_start sub_80A9C70
sub_80A9C70: @ 80A9C70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r6, [r0]
	ldr r0, =sub_80A9DB4
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_08524F84
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0852588C
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r1
	strh r4, [r1, 0x8]
	cmp r5, 0
	beq _080A9D30
	movs r0, 0x1F
	strh r0, [r1, 0xA]
	movs r5, 0
	lsls r0, r6, 4
	ldr r7, =gSprites
	adds r0, r6
	lsls r0, 2
	adds r6, r0, r7
_080A9CC4:
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	ldrh r2, [r6, 0x22]
	adds r2, 0x20
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_0853EF60
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r7
	lsls r0, r5, 1
	adds r0, r5
	lsls r1, r0, 4
	adds r0, r1
	strh r0, [r3, 0x2E]
	movs r0, 0xFF
	lsls r0, 8
	strh r0, [r3, 0x30]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	cmp r5, 0x4
	bls _080A9D08
	movs r0, 0x15
	strh r0, [r3, 0x3A]
_080A9D08:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _080A9CC4
	b _080A9D90
	.pool
_080A9D30:
	movs r0, 0xF8
	lsls r0, 7
	strh r0, [r1, 0xA]
	movs r5, 0
	lsls r0, r6, 4
	ldr r7, =gSprites
	adds r0, r6
	lsls r0, 2
	adds r6, r0, r7
_080A9D42:
	movs r2, 0x20
	ldrsh r1, [r6, r2]
	ldrh r2, [r6, 0x22]
	subs r2, 0x20
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_0853EF60
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r7
	lsls r0, r5, 1
	adds r0, r5
	lsls r1, r0, 4
	adds r0, r1
	strh r0, [r3, 0x2E]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r3, 0x30]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	cmp r5, 0x4
	bls _080A9D86
	movs r0, 0x15
	strh r0, [r3, 0x3A]
_080A9D86:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _080A9D42
_080A9D90:
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A9C70

	thumb_func_start sub_80A9DB4
sub_80A9DB4: @ 80A9DB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x2
	bne _080A9E3A
	movs r0, 0
	strh r0, [r4, 0xC]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 16
	ldrb r2, [r4, 0x10]
	ldrh r3, [r4, 0xA]
	movs r1, 0x10
	bl BlendPalette
	ldrh r2, [r4, 0x12]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080A9E10
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _080A9E3E
	movs r0, 0x1
	eors r0, r2
	strh r0, [r4, 0x12]
	b _080A9E3E
	.pool
_080A9E10:
	ldrh r1, [r4, 0x10]
	subs r0, r1, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bge _080A9E3E
	strh r1, [r4, 0x10]
	movs r0, 0x1
	eors r0, r2
	strh r0, [r4, 0x12]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080A9E3E
	adds r0, r5, 0
	bl DestroyTask
	b _080A9E3E
_080A9E3A:
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
_080A9E3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A9DB4

	thumb_func_start sub_80A9E44
sub_80A9E44: @ 80A9E44
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _080A9E70
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r3]
	ldr r1, =sub_80A9E78
	str r1, [r2, 0x1C]
	adds r0, r2, 0
	bl _call_via_r1
	b _080A9E74
	.pool
_080A9E70:
	subs r0, r1, 0x1
	strh r0, [r2, 0x3A]
_080A9E74:
	pop {r0}
	bx r0
	thumb_func_end sub_80A9E44

	thumb_func_start sub_80A9E78
sub_80A9E78: @ 80A9E78
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	bgt _080A9EA4
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1D
	b _080A9EAA
_080A9EA4:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1F
_080A9EAA:
	strb r0, [r1]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x34
	bne _080A9EEC
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080A9EE6
	adds r0, r4, 0
	bl ResetSpriteAndFreeResources
	b _080A9EEC
_080A9EE6:
	adds r0, r4, 0
	bl DestroySprite
_080A9EEC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A9E78

	thumb_func_start sub_80A9EF4
sub_80A9EF4: @ 80A9EF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	ldr r1, =0xffe00000
	adds r0, r1
	lsrs r5, r0, 16
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	ldr r1, =0xffdc0000
	adds r0, r1
	lsrs r4, r0, 16
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _080A9F32
	lsls r0, r5, 16
	ldr r1, =0xfffa0000
	adds r0, r1
	lsrs r5, r0, 16
_080A9F32:
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =gUnknown_0853EF48
	lsls r1, r5, 16
	asrs r1, 16
	lsls r2, r4, 16
	asrs r2, 16
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x0000271a
	bl GetSpriteTileStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _080A9F7C
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080A9F7C:
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldr r1, =gUnknown_0853EF40
	bl SetSpriteOamTables_NoPriorityFromTable
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x26]
	ldr r1, =sub_80A9FD0
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A9EF4

	thumb_func_start sub_80A9FD0
sub_80A9FD0: @ 80A9FD0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	adds r2, r0, 0
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _080AA004
	ldr r0, =sub_80AA020
	str r0, [r1]
	movs r0, 0
	strh r0, [r1, 0xA]
	b _080AA01A
	.pool
_080AA004:
	lsls r0, r2, 24
	lsrs r0, 24
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_080AA01A:
	pop {r0}
	bx r0
	thumb_func_end sub_80A9FD0

	thumb_func_start sub_80AA020
sub_80AA020: @ 80AA020
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000271a
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0xA]
	adds r1, r0, 0x1
	strh r1, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	ble _080AA0B0
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _080AA0B0
	ldr r3, =gPlttBufferFaded
	lsls r2, 4
	mov r12, r2
	ldr r1, =0x0000010d
	add r1, r12
	lsls r1, 1
	adds r1, r3
	ldrh r4, [r1]
	movs r2, 0x87
	lsls r2, 1
	add r2, r12
	lsls r2, 1
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r0, =0x0000010f
	add r0, r12
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	strh r1, [r2]
	strh r4, [r0]
	strh r6, [r5, 0xC]
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _080AA0B0
	strh r6, [r5, 0xE]
	strh r6, [r5, 0xA]
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080AA0B0
	movs r0, 0x9
	strh r0, [r5, 0xA]
	ldr r0, =sub_80AA0D0
	str r0, [r5]
_080AA0B0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA020

	thumb_func_start sub_80AA0D0
sub_80AA0D0: @ 80AA0D0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r0, [r2, 0xA]
	subs r0, 0x1
	adds r3, r0, 0
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080AA108
	ldr r0, =sub_80AA124
	str r0, [r2]
	movs r0, 0
	strh r0, [r2, 0xA]
	b _080AA11E
	.pool
_080AA108:
	lsls r0, r3, 24
	lsrs r0, 24
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_080AA11E:
	pop {r0}
	bx r0
	thumb_func_end sub_80AA0D0

	thumb_func_start sub_80AA124
sub_80AA124: @ 80AA124
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x25
	bne _080AA16C
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl DestroySprite
	b _080AA186
	.pool
_080AA16C:
	cmp r0, 0x27
	bne _080AA186
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_task_del
_080AA186:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AA124

	thumb_func_start sub_80AA18C
sub_80AA18C: @ 80AA18C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	subs r0, 0xF
	cmp r0, 0x2B
	bls _080AA1A4
	b _080AA328
_080AA1A4:
	lsls r0, 2
	ldr r1, =_080AA1B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AA1B8:
	.4byte _080AA268
	.4byte _080AA26E
	.4byte _080AA274
	.4byte _080AA27A
	.4byte _080AA280
	.4byte _080AA286
	.4byte _080AA28C
	.4byte _080AA292
	.4byte _080AA298
	.4byte _080AA29E
	.4byte _080AA2A4
	.4byte _080AA2AA
	.4byte _080AA2B0
	.4byte _080AA2B6
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA2BC
	.4byte _080AA2C0
	.4byte _080AA2C4
	.4byte _080AA2C8
	.4byte _080AA2CC
	.4byte _080AA2D0
	.4byte _080AA2D4
	.4byte _080AA2D8
	.4byte _080AA2E0
	.4byte _080AA2E8
	.4byte _080AA2F0
	.4byte _080AA2F8
	.4byte _080AA300
	.4byte _080AA308
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA310
	.4byte _080AA314
	.4byte _080AA318
	.4byte _080AA320
_080AA268:
	movs r5, 0
	movs r2, 0
	b _080AA330
_080AA26E:
	movs r5, 0
	movs r2, 0x1
	b _080AA330
_080AA274:
	movs r5, 0
	movs r2, 0x3
	b _080AA330
_080AA27A:
	movs r5, 0
	movs r2, 0x5
	b _080AA330
_080AA280:
	movs r5, 0
	movs r2, 0x6
	b _080AA330
_080AA286:
	movs r5, 0
	movs r2, 0x2
	b _080AA330
_080AA28C:
	movs r5, 0
	movs r2, 0x4
	b _080AA330
_080AA292:
	movs r5, 0x1
	movs r2, 0
	b _080AA330
_080AA298:
	movs r5, 0x1
	movs r2, 0x1
	b _080AA330
_080AA29E:
	movs r5, 0x1
	movs r2, 0x3
	b _080AA330
_080AA2A4:
	movs r5, 0x1
	movs r2, 0x5
	b _080AA330
_080AA2AA:
	movs r5, 0x1
	movs r2, 0x6
	b _080AA330
_080AA2B0:
	movs r5, 0x1
	movs r2, 0x2
	b _080AA330
_080AA2B6:
	movs r5, 0x1
	movs r2, 0x4
	b _080AA330
_080AA2BC:
	movs r5, 0
	b _080AA2DA
_080AA2C0:
	movs r5, 0
	b _080AA2E2
_080AA2C4:
	movs r5, 0
	b _080AA2EA
_080AA2C8:
	movs r5, 0
	b _080AA2F2
_080AA2CC:
	movs r5, 0
	b _080AA2FA
_080AA2D0:
	movs r5, 0
	b _080AA302
_080AA2D4:
	movs r5, 0
	b _080AA30A
_080AA2D8:
	movs r5, 0x1
_080AA2DA:
	movs r2, 0
	movs r3, 0x1
	b _080AA330
_080AA2E0:
	movs r5, 0x1
_080AA2E2:
	movs r2, 0x1
	movs r3, 0x1
	b _080AA330
_080AA2E8:
	movs r5, 0x1
_080AA2EA:
	movs r2, 0x3
	movs r3, 0x1
	b _080AA330
_080AA2F0:
	movs r5, 0x1
_080AA2F2:
	movs r2, 0x5
	movs r3, 0x1
	b _080AA330
_080AA2F8:
	movs r5, 0x1
_080AA2FA:
	movs r2, 0x6
	movs r3, 0x1
	b _080AA330
_080AA300:
	movs r5, 0x1
_080AA302:
	movs r2, 0x2
	movs r3, 0x1
	b _080AA330
_080AA308:
	movs r5, 0x1
_080AA30A:
	movs r2, 0x4
	movs r3, 0x1
	b _080AA330
_080AA310:
	movs r5, 0
	b _080AA31A
_080AA314:
	movs r5, 0
	b _080AA322
_080AA318:
	movs r5, 0x1
_080AA31A:
	movs r2, 0xFF
	movs r3, 0
	b _080AA330
_080AA320:
	movs r5, 0x1
_080AA322:
	movs r2, 0xFF
	movs r3, 0x1
	b _080AA330
_080AA328:
	adds r0, r4, 0
	bl move_anim_task_del
	b _080AA352
_080AA330:
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	strh r5, [r0]
	strh r2, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r3, [r0, 0x8]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8116EB4
	str r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
_080AA352:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA18C

	thumb_func_start move_anim_start_t2
move_anim_start_t2: @ 80AA364
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02038436
	strb r4, [r0]
	ldr r0, =gUnknown_02038437
	strb r4, [r0]
	ldr r0, =gUnknown_082C92FC
	movs r2, 0
	bl move_something
	ldr r0, =task0A_80788BC
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_start_t2

	thumb_func_start task0A_80788BC
task0A_80788BC: @ 80AA3B4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AA3F6
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	ldr r2, [r2, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_080AA3F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_80788BC

	.align 2, 0 @ Don't pad with nop.
