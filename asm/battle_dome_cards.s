	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start oamt_spawn_poke_or_trainer_picture
oamt_spawn_poke_or_trainer_picture: @ 818D1EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r1, [sp, 0xC]
	str r2, [sp, 0x10]
	ldr r1, [sp, 0x50]
	ldr r2, [sp, 0x54]
	ldr r4, [sp, 0x58]
	ldr r5, [sp, 0x5C]
	ldr r6, [sp, 0x60]
	ldr r7, [sp, 0x64]
	mov r8, r7
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x18]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x1C]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x20]
	lsls r5, 16
	lsrs r5, 16
	mov r10, r5
	lsls r6, 24
	lsrs r6, 24
	mov r9, r6
	mov r0, r8
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r1, =gUnknown_0203CD04
	ldrb r0, [r1, 0xB]
	cmp r0, 0
	beq _0818D25C
_0818D244:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bhi _0818D25C
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	bne _0818D244
_0818D25C:
	cmp r4, 0x8
	beq _0818D280
	movs r0, 0x80
	lsls r0, 6
	bl Alloc
	adds r7, r0, 0
	cmp r7, 0
	beq _0818D280
	movs r0, 0x20
	bl Alloc
	mov r8, r0
	cmp r0, 0
	bne _0818D28C
	adds r0, r7, 0
	bl Free
_0818D280:
	ldr r0, =0x0000ffff
	b _0818D356
	.pool
_0818D28C:
	mov r1, r9
	str r1, [sp]
	str r5, [sp, 0x4]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0x10]
	ldr r2, [sp, 0x14]
	adds r3, r7, 0
	bl load_pokemon_image_TODO
	lsls r0, 16
	cmp r0, 0
	bne _0818D280
	lsls r2, r4, 1
	str r2, [sp, 0x2C]
	ldr r5, =gUnknown_0203CCEC
	ldr r0, =gUnknown_0860B064
	mov r12, r0
	ldr r1, [sp, 0x18]
	lsls r1, 16
	str r1, [sp, 0x24]
	ldr r2, [sp, 0x1C]
	lsls r2, 16
	str r2, [sp, 0x28]
	movs r3, 0x80
	lsls r3, 4
	mov r0, r8
	adds r1, r7, 0
	adds r6, r3, 0
	movs r2, 0x3
_0818D2C6:
	str r1, [r0]
	strh r3, [r0, 0x4]
	adds r0, 0x8
	adds r1, r6
	subs r2, 0x1
	cmp r2, 0
	bge _0818D2C6
	ldr r0, =0x0000ffff
	strh r0, [r5]
	mov r0, r12
	str r0, [r5, 0x4]
	mov r0, r9
	bl uns_builder_assign_animtable1
	mov r1, r8
	str r1, [r5, 0xC]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [r5, 0x10]
	ldr r0, =nullsub_122
	str r0, [r5, 0x14]
	mov r2, r10
	str r2, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x20]
	bl sub_818D0C4
	ldr r2, [sp, 0x24]
	asrs r1, r2, 16
	ldr r0, [sp, 0x28]
	asrs r2, r0, 16
	adds r0, r5, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	adds r6, r2, 0
	ldr r0, =0x0000ffff
	cmp r10, r0
	bne _0818D336
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldr r2, [sp, 0x20]
	lsls r3, r2, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
_0818D336:
	ldr r1, =gUnknown_0203CD04
	ldr r2, [sp, 0x2C]
	adds r0, r2, r4
	lsls r0, 2
	adds r2, r0, r1
	str r7, [r2]
	adds r1, 0x4
	adds r0, r1
	mov r7, r8
	str r7, [r0]
	mov r0, r10
	strh r0, [r2, 0x8]
	strb r6, [r2, 0xA]
	movs r0, 0x1
	strb r0, [r2, 0xB]
	adds r0, r6, 0
_0818D356:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oamt_spawn_poke_or_trainer_picture

	thumb_func_start sub_818D384
sub_818D384: @ 818D384
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	ldr r6, [sp, 0x3C]
	ldr r7, [sp, 0x40]
	mov r8, r7
	ldr r7, [sp, 0x44]
	mov r9, r7
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r6, 24
	lsrs r6, 24
	mov r7, r8
	lsls r7, 16
	lsrs r7, 16
	mov r8, r7
	mov r7, r9
	lsls r7, 24
	lsrs r7, 24
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r4, r8
	str r4, [sp, 0xC]
	str r7, [sp, 0x10]
	movs r4, 0
	str r4, [sp, 0x14]
	bl oamt_spawn_poke_or_trainer_picture
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D384

	thumb_func_start sub_818D3E4
sub_818D3E4: @ 818D3E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r1, [sp, 0x4C]
	ldr r2, [sp, 0x50]
	ldr r4, [sp, 0x54]
	ldr r5, [sp, 0x58]
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r3, 24
	lsrs r6, r3, 24
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x14]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x18]
	lsls r5, 16
	lsrs r5, 16
	str r5, [sp, 0x1C]
	movs r5, 0
	ldr r1, =gUnknown_0203CD04
	ldrb r0, [r1, 0xB]
	cmp r0, 0
	beq _0818D440
_0818D428:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bhi _0818D440
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	bne _0818D428
_0818D440:
	cmp r5, 0x8
	beq _0818D47C
	movs r0, 0x80
	lsls r0, 6
	bl Alloc
	adds r7, r0, 0
	cmp r7, 0
	beq _0818D47C
	movs r0, 0x80
	ands r0, r6
	cmp r0, 0
	beq _0818D468
	movs r0, 0x7F
	ands r6, r0
	movs r0, 0x3
	mov r9, r0
	b _0818D46A
	.pool
_0818D468:
	mov r9, r6
_0818D46A:
	movs r0, 0x20
	bl Alloc
	mov r8, r0
	cmp r0, 0
	bne _0818D484
	adds r0, r7, 0
	bl Free
_0818D47C:
	ldr r0, =0x0000ffff
	b _0818D588
	.pool
_0818D484:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r7, 0
	bl load_pokemon_image_TODO
	lsls r0, 16
	cmp r0, 0
	bne _0818D47C
	lsls r1, r5, 1
	str r1, [sp, 0x28]
	ldr r4, =gUnknown_0203CCEC
	mov r2, r10
	lsls r2, 2
	mov r12, r2
	ldr r0, [sp, 0x10]
	lsls r0, 16
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x14]
	lsls r1, 16
	str r1, [sp, 0x24]
	movs r3, 0x80
	lsls r3, 4
	mov r0, r8
	adds r1, r7, 0
	adds r6, r3, 0
	movs r2, 0x3
_0818D4C0:
	str r1, [r0]
	strh r3, [r0, 0x4]
	adds r0, 0x8
	adds r1, r6
	subs r2, 0x1
	cmp r2, 0
	bge _0818D4C0
	ldr r0, =0x0000ffff
	strh r0, [r4]
	ldr r0, =gUnknown_08309AAC
	add r0, r12
	ldr r0, [r0]
	str r0, [r4, 0x8]
	mov r2, r8
	str r2, [r4, 0xC]
	mov r0, r9
	cmp r0, 0x1
	bne _0818D4F8
	ldr r0, =gUnknown_082FF694
	b _0818D500
	.pool
_0818D4F8:
	mov r1, r9
	cmp r1, 0
	bne _0818D510
	ldr r0, =gUnknown_082FF618
_0818D500:
	str r0, [r4, 0x10]
	ldr r0, =gUnknown_0860B06C
	str r0, [r4, 0x4]
	b _0818D518
	.pool
_0818D510:
	ldr r0, =gUnknown_0860B064
	str r0, [r4, 0x4]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [r4, 0x10]
_0818D518:
	ldr r2, =nullsub_122
	str r2, [r4, 0x14]
	ldr r0, [sp, 0x1C]
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x8]
	ldr r2, [sp, 0xC]
	ldr r3, [sp, 0x18]
	bl sub_818D0C4
	ldr r2, [sp, 0x20]
	asrs r1, r2, 16
	ldr r0, [sp, 0x24]
	asrs r2, r0, 16
	adds r0, r4, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	adds r6, r2, 0
	ldr r0, =0x0000ffff
	ldr r1, [sp, 0x1C]
	cmp r1, r0
	bne _0818D566
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldr r2, [sp, 0x18]
	lsls r3, r2, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
_0818D566:
	ldr r1, =gUnknown_0203CD04
	ldr r2, [sp, 0x28]
	adds r0, r2, r5
	lsls r0, 2
	adds r2, r0, r1
	str r7, [r2]
	adds r1, 0x4
	adds r0, r1
	mov r1, r8
	str r1, [r0]
	mov r0, sp
	ldrh r0, [r0, 0x1C]
	strh r0, [r2, 0x8]
	strb r6, [r2, 0xA]
	movs r0, 0x1
	strb r0, [r2, 0xB]
	adds r0, r6, 0
_0818D588:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D3E4

	thumb_func_start sub_818D5B0
sub_818D5B0: @ 818D5B0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r4, r0, 16
	movs r2, 0
	ldr r0, =gUnknown_0203CD04
	ldrb r1, [r0, 0xA]
	adds r3, r0, 0
	cmp r1, r4
	beq _0818D5E0
	adds r1, r3, 0
_0818D5C8:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bhi _0818D5E0
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0xA]
	cmp r0, r4
	bne _0818D5C8
_0818D5E0:
	cmp r2, 0x8
	bne _0818D5F0
	ldr r0, =0x0000ffff
	b _0818D646
	.pool
_0818D5F0:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r3
	ldr r1, [r5]
	mov r8, r1
	adds r1, r3, 0x4
	adds r0, r1
	ldr r7, [r0]
	ldrh r1, [r5, 0x8]
	ldr r0, =0x0000ffff
	lsls r6, r4, 4
	cmp r1, r0
	beq _0818D624
	ldr r1, =gSprites
	adds r0, r6, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	bl GetSpritePaletteTagByPaletteNum
	lsls r0, 16
	lsrs r0, 16
	bl FreeSpritePaletteByTag
_0818D624:
	adds r0, r6, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	mov r0, r8
	bl Free
	adds r0, r7, 0
	bl Free
	adds r1, r5, 0
	ldr r0, =gUnknown_0860B058
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0
_0818D646:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D5B0

	thumb_func_start sub_818D65C
sub_818D65C: @ 818D65C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r9, r1
	adds r7, r2, 0
	adds r4, r3, 0
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r3, [sp, 0x28]
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	adds r0, r2, 0
	movs r1, 0x7
	bl GetWindowAttribute
	adds r3, r0, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_818D09C
	lsls r0, 16
	cmp r0, 0
	bne _0818D6B8
	str r6, [sp]
	adds r0, r5, 0
	mov r1, r9
	adds r2, r7, 0
	mov r3, r8
	bl sub_818D180
	movs r0, 0
	b _0818D6BA
_0818D6B8:
	ldr r0, =0x0000ffff
_0818D6BA:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D65C

	thumb_func_start sub_818D6CC
sub_818D6CC: @ 818D6CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x18]
	str r2, [sp, 0x1C]
	ldr r1, [sp, 0x44]
	ldr r2, [sp, 0x48]
	ldr r4, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	ldr r6, [sp, 0x54]
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x20]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x80
	lsls r0, 6
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	beq _0818D762
	str r6, [sp]
	mov r0, r9
	ldr r1, [sp, 0x1C]
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_818D09C
	lsls r0, 16
	cmp r0, 0
	bne _0818D762
	movs r0, 0x40
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r1, r8
	str r1, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow
	str r6, [sp]
	mov r0, r9
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	ldr r3, [sp, 0x20]
	bl sub_818D180
	adds r0, r4, 0
	bl Free
	movs r0, 0
	b _0818D764
_0818D762:
	ldr r0, =0x0000ffff
_0818D764:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D6CC

	thumb_func_start sub_818D778
sub_818D778: @ 818D778
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	ldr r6, [sp, 0x3C]
	ldr r7, [sp, 0x40]
	mov r8, r7
	ldr r7, [sp, 0x44]
	mov r9, r7
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r6, 24
	lsrs r6, 24
	mov r7, r8
	lsls r7, 16
	lsrs r7, 16
	mov r8, r7
	mov r7, r9
	lsls r7, 24
	lsrs r7, 24
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r4, r8
	str r4, [sp, 0xC]
	movs r4, 0
	str r4, [sp, 0x10]
	str r7, [sp, 0x14]
	bl oamt_spawn_poke_or_trainer_picture
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D778

	thumb_func_start sub_818D7D8
sub_818D7D8: @ 818D7D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r7, [sp, 0x38]
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r7, 16
	lsrs r7, 16
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r4, 0
	str r4, [sp, 0x10]
	bl sub_818D778
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D7D8

	thumb_func_start sub_818D820
sub_818D820: @ 818D820
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_818D5B0
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_818D820

	thumb_func_start sub_818D834
sub_818D834: @ 818D834
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r4, [sp, 0x18]
	ldr r5, [sp, 0x1C]
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	bl sub_818D65C
	lsls r0, 16
	lsrs r0, 16
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818D834

	thumb_func_start sub_818D864
sub_818D864: @ 818D864
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r7, [sp, 0x38]
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	lsls r7, 24
	lsrs r7, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r4, 0
	str r4, [sp, 0x10]
	bl sub_818D6CC
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D864

	thumb_func_start sub_818D8AC
sub_818D8AC: @ 818D8AC
	push {r4,r5,lr}
	sub sp, 0x14
	adds r5, r1, 0
	ldr r1, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r0, 16
	lsrs r0, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r2, 16
	asrs r2, 16
	str r2, [sp]
	lsls r3, 16
	asrs r3, 16
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x1
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_818D384
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818D8AC

	thumb_func_start sub_818D8F0
sub_818D8F0: @ 818D8F0
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_818D5B0
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_818D8F0

	thumb_func_start sub_818D904
sub_818D904: @ 818D904
	push {r4,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0
	adds r3, r4, 0
	bl sub_818D65C
	lsls r0, 16
	lsrs r0, 16
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_818D904

	thumb_func_start sub_818D938
sub_818D938: @ 818D938
	push {r4,r5,lr}
	sub sp, 0x14
	adds r5, r1, 0
	ldr r1, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r0, 16
	lsrs r0, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 24
	lsrs r4, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x1
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_818D6CC
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818D938

	thumb_func_start sub_818D97C
sub_818D97C: @ 818D97C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	bne _0818D9A2
	cmp r0, 0
	beq _0818D99C
	ldr r0, =gUnknown_0831F578
	adds r0, 0x3F
	ldrb r0, [r0]
	b _0818D9A2
	.pool
_0818D99C:
	ldr r0, =gUnknown_0831F578
	adds r0, 0x3C
	ldrb r0, [r0]
_0818D9A2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D97C
           
	.align 2, 0 @ Don't pad with nop.
