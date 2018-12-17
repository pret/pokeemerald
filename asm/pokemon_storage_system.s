	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start sub_80D140C
sub_80D140C: @ 80D140C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	cmp r5, 0x2
	bhi _080D150A
	cmp r1, 0
	beq _080D1438
	cmp r1, 0x1
	beq _080D1494
	ldr r4, =gUnknown_02039D08
	lsls r3, r5, 4
	b _080D14F4
	.pool
_080D1438:
	adds r0, r7, 0
	movs r1, 0x6
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_02039D08
	ldr r2, [r6]
	lsls r5, 4
	ldr r1, =0x00002204
	adds r2, r1
	adds r2, r5
	ldr r3, [r2]
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, 0x70
	strh r1, [r3, 0x20]
	ldr r3, [r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x38
	strh r1, [r3, 0x22]
	ldr r2, [r2]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r4, r6, 0
	adds r3, r5, 0
	b _080D14F4
	.pool
_080D1494:
	cmp r7, 0
	bne _080D14BC
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	lsls r3, r5, 4
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0x74
	strh r1, [r2, 0x20]
	ldr r1, [r0]
	movs r0, 0x4C
	strh r0, [r1, 0x22]
	b _080D14DC
	.pool
_080D14BC:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	lsls r3, r5, 4
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0xA4
	strh r1, [r2, 0x20]
	ldr r2, [r0]
	subs r1, r7, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x1C
	strh r0, [r2, 0x22]
_080D14DC:
	ldr r0, [r4]
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
_080D14F4:
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =0x0000220e
	adds r0, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =0x0000220f
	adds r0, r1
	strb r7, [r0]
_080D150A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D140C

	thumb_func_start sub_80D1524
sub_80D1524: @ 80D1524
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r1
	mov r9, r2
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x2
	bhi _080D15AC
	movs r0, 0
	str r0, [sp]
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r6, =0x000042c4
	adds r1, r6
	ldr r2, =0x01000080
	mov r0, sp
	bl CpuFastSet
	ldr r1, [r4]
	ldr r5, =0x000022c4
	adds r1, r5
	mov r0, r8
	bl LZ77UnCompWram
	lsls r7, 4
	mov r8, r7
	adds r7, r4, 0
	movs r4, 0x2
_080D1562:
	ldr r1, [r7]
	adds r0, r1, r5
	adds r1, r6
	movs r2, 0x18
	bl CpuFastSet
	adds r6, 0x80
	adds r5, 0x60
	subs r4, 0x1
	cmp r4, 0
	bge _080D1562
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldr r4, =0x000042c4
	adds r0, r1, r4
	ldr r2, =0x00002208
	adds r1, r2
	add r1, r8
	ldr r1, [r1]
	movs r2, 0x80
	bl CpuFastSet
	ldr r1, [r5]
	adds r1, r4
	mov r0, r9
	bl LZ77UnCompWram
	ldr r0, [r5]
	adds r4, r0, r4
	add r0, r8
	ldr r1, =0x0000220c
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
_080D15AC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1524

	thumb_func_start sub_80D15D4
sub_80D15D4: @ 80D15D4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	cmp r2, 0x2
	bhi _080D15F6
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r2, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	adds r1, r3, 0
	bl StartSpriteAffineAnim
_080D15F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D15D4

	thumb_func_start sub_80D1604
sub_80D1604: @ 80D1604
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	cmp r4, 0x2
	bls _080D161C
	b _080D172E
_080D161C:
	cmp r0, 0x7
	bls _080D1622
	b _080D172E
_080D1622:
	lsls r0, 2
	ldr r1, =_080D1630
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D1630:
	.4byte _080D1650
	.4byte _080D1674
	.4byte _080D1698
	.4byte _080D16C4
	.4byte _080D16F0
	.4byte _080D172E
	.4byte _080D172E
	.4byte _080D171C
_080D1650:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	strh r4, [r1, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80D1A48
	b _080D172C
	.pool
_080D1674:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80D1A74
	b _080D172C
	.pool
_080D1698:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	strh r5, [r1, 0x3A]
	ldr r1, [r0]
	strh r3, [r1, 0x3C]
	ldr r1, [r0]
	ldr r0, =sub_80D1B14
	b _080D172C
	.pool
_080D16C4:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r2, [r0]
	ldr r1, =sub_80D1B94
	str r1, [r2, 0x1C]
	strh r5, [r2, 0x3A]
	ldr r0, [r0]
	strh r3, [r0, 0x3C]
	b _080D172E
	.pool
_080D16F0:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	strh r5, [r1, 0x3A]
	ldr r1, [r0]
	strh r3, [r1, 0x3C]
	ldr r1, [r0]
	ldr r0, =sub_80D1C30
	b _080D172C
	.pool
_080D171C:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =sub_80D1CCC
_080D172C:
	str r0, [r1, 0x1C]
_080D172E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1604

	thumb_func_start sub_80D1740
sub_80D1740: @ 80D1740
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r2, 0x2
	bhi _080D1780
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	lsls r2, 4
	adds r0, r2
	ldr r3, =0x00002210
	adds r0, r3
	strb r4, [r0]
	ldr r0, [r1]
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	movs r3, 0
	cmp r4, 0
	bne _080D176E
	movs r3, 0x1
_080D176E:
	adds r2, r0, 0
	adds r2, 0x3E
	lsls r3, 2
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_080D1780:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1740

	thumb_func_start GetItemIconPic
GetItemIconPic: @ 80D1794
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPic

	thumb_func_start GetItemIconPalette
GetItemIconPalette: @ 80D17A4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPalette

	thumb_func_start sub_80D17B4
sub_80D17B4: @ 80D17B4
	push {r4,lr}
	sub sp, 0x14
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	beq _080D17D4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	b _080D17DA
	.pool
_080D17D4:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000ce6
_080D17DA:
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetDescription
	adds r4, r0, 0
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized5
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D17B4

	thumb_func_start sub_80D1818
sub_80D1818: @ 80D1818
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002236
	adds r0, r1
	movs r1, 0x15
	strh r1, [r0]
	ldr r1, =gUnknown_0857BB24
	movs r3, 0x9D
	lsls r3, 1
	movs r0, 0
	movs r2, 0x80
	bl LoadBgTiles
	movs r0, 0
	bl sub_80D19B4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1818

	thumb_func_start sub_80D184C
sub_80D184C: @ 80D184C
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0
	bne _080D186C
	movs r0, 0
	b _080D18D2
	.pool
_080D186C:
	subs r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, 0x15
	subs r5, r0, r1
	movs r4, 0
	cmp r4, r5
	bge _080D18BC
_080D187C:
	movs r0, 0
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r0, r2
	adds r1, 0x14
	ldrh r0, [r0]
	adds r1, r0
	adds r1, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x15
	str r0, [sp, 0xC]
	movs r0, 0
	movs r3, 0xD
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x1
	cmp r4, r5
	blt _080D187C
_080D18BC:
	adds r0, r5, 0
	bl sub_80D19B4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002236
	adds r0, r1
	ldrh r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080D18D2:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D184C

	thumb_func_start sub_80D18E4
sub_80D18E4: @ 80D18E4
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x00002236
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x16
	bne _080D1904
	movs r0, 0
	b _080D19A4
	.pool
_080D1904:
	cmp r0, 0
	bne _080D1920
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x15
	movs r3, 0xC
	bl FillBgTilemapBufferRect
_080D1920:
	ldr r1, [r5]
	adds r1, r4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, 0x15
	subs r5, r0, r1
	movs r4, 0
	cmp r4, r5
	bge _080D1976
_080D1936:
	movs r0, 0
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r0, r2
	adds r1, 0x14
	ldrh r0, [r0]
	adds r1, r0
	adds r1, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x15
	str r0, [sp, 0xC]
	movs r0, 0
	movs r3, 0xD
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x1
	cmp r4, r5
	blt _080D1936
_080D1976:
	cmp r5, 0
	blt _080D1980
	adds r0, r5, 0
	bl sub_80D19B4
_080D1980:
	adds r2, r5, 0x1
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
_080D19A4:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D18E4

	thumb_func_start sub_80D19B4
sub_80D19B4: @ 80D19B4
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	cmp r7, 0
	beq _080D19EC
	movs r1, 0x9D
	lsls r1, 1
	lsls r4, r7, 24
	lsrs r4, 24
	str r4, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000093a
	str r4, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0x14
	bl FillBgTilemapBufferRect
_080D19EC:
	ldr r1, =0x0000013b
	lsls r5, r7, 24
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r6, 0xF
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0xD
	bl FillBgTilemapBufferRect
	movs r1, 0x9E
	lsls r1, 1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000013d
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0x14
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D19B4

	thumb_func_start sub_80D1A48
sub_80D1A48: @ 80D1A48
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080D1A68
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80D1740
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D1A68:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1A48

	thumb_func_start sub_80D1A74
sub_80D1A74: @ 80D1A74
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _080D1A86
	cmp r1, 0x1
	beq _080D1AA2
	b _080D1AD0
_080D1A86:
	ldrh r0, [r3, 0x20]
	lsls r0, 4
	strh r0, [r3, 0x30]
	ldrh r0, [r3, 0x22]
	lsls r0, 4
	strh r0, [r3, 0x32]
	movs r0, 0xA
	strh r0, [r3, 0x34]
	movs r0, 0x15
	strh r0, [r3, 0x36]
	strh r1, [r3, 0x38]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
_080D1AA2:
	ldrh r1, [r3, 0x30]
	ldrh r0, [r3, 0x34]
	subs r1, r0
	strh r1, [r3, 0x30]
	ldrh r0, [r3, 0x32]
	ldrh r2, [r3, 0x36]
	subs r0, r2
	strh r0, [r3, 0x32]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r3, 0x20]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r3, 0x22]
	ldrh r0, [r3, 0x38]
	adds r0, 0x1
	strh r0, [r3, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1AD0
	ldr r0, =sub_80D1AD8
	str r0, [r3, 0x1C]
_080D1AD0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1A74

	thumb_func_start sub_80D1AD8
sub_80D1AD8: @ 80D1AD8
	ldr r1, =gUnknown_02039D08
	ldr r3, [r1]
	ldr r1, =0x00000cb4
	adds r3, r1
	ldr r1, [r3]
	ldrh r1, [r1, 0x20]
	adds r1, 0x4
	strh r1, [r0, 0x20]
	ldr r2, [r3]
	ldrh r1, [r2, 0x26]
	ldrh r2, [r2, 0x22]
	adds r1, r2
	adds r1, 0x8
	strh r1, [r0, 0x22]
	ldr r1, [r3]
	ldrb r1, [r1, 0x5]
	movs r2, 0xC
	ands r2, r1
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	bx lr
	.pool
	thumb_func_end sub_80D1AD8

	thumb_func_start sub_80D1B14
sub_80D1B14: @ 80D1B14
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1B26
	cmp r1, 0x1
	beq _080D1B42
	b _080D1B8A
_080D1B26:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1B42:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	ldrh r2, [r4, 0x32]
	adds r1, r2
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1B8A
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D1B8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1B14

	thumb_func_start sub_80D1B94
sub_80D1B94: @ 80D1B94
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1BA6
	cmp r1, 0x1
	beq _080D1BC2
	b _080D1C20
_080D1BA6:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1BC2:
	ldrh r1, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	subs r1, r0
	strh r1, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	subs r0, r2
	strh r0, [r4, 0x32]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x20]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x22]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1C20
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =sub_80D1AD8
	str r0, [r4, 0x1C]
_080D1C20:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1B94

	thumb_func_start sub_80D1C30
sub_80D1C30: @ 80D1C30
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1C42
	cmp r1, 0x1
	beq _080D1C5E
	b _080D1CBE
_080D1C42:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1C5E:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	ldrh r2, [r4, 0x32]
	adds r1, r2
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1CBE
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
_080D1CBE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1C30

	thumb_func_start sub_80D1CCC
sub_80D1CCC: @ 80D1CCC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x22]
	subs r0, 0x8
	strh r0, [r2, 0x22]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080D1CFC
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	adds r0, r2, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80D1740
_080D1CFC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1CCC

	thumb_func_start TaskDummy0
TaskDummy0: @ 80D1D04
	bx lr
	thumb_func_end TaskDummy0

	thumb_func_start nullsub_98
nullsub_98: @ 80D1D08
	bx lr
	thumb_func_end nullsub_98

	thumb_func_start StorageGetCurrentBox
@ char StorageGetCurrentBox()
StorageGetCurrentBox: @ 80D1D0C
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end StorageGetCurrentBox

	thumb_func_start SetCurrentBox
SetCurrentBox: @ 80D1D18
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bhi _080D1D28
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	strb r1, [r0]
_080D1D28:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetCurrentBox

	thumb_func_start GetBoxMonDataAt
GetBoxMonDataAt: @ 80D1D30
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1D6C
	cmp r4, 0x1D
	bhi _080D1D6C
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	bl GetBoxMonData
	b _080D1D6E
	.pool
_080D1D6C:
	movs r0, 0
_080D1D6E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetBoxMonDataAt

	thumb_func_start SetBoxMonDataFromAnyBox
SetBoxMonDataFromAnyBox: @ 80D1D74
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1DAC
	cmp r4, 0x1D
	bhi _080D1DAC
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	adds r2, r6, 0
	bl SetBoxMonData
_080D1DAC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonDataFromAnyBox

	thumb_func_start GetCurrentBoxMonData
GetCurrentBoxMonData: @ 80D1DB8
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r3, 0
	bl GetBoxMonDataAt
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetCurrentBoxMonData

	thumb_func_start SetCurrentBoxMonData
SetCurrentBoxMonData: @ 80D1DD8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl SetBoxMonDataFromAnyBox
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetCurrentBoxMonData

	thumb_func_start GetBoxMonNickFromAnyBox
GetBoxMonNickFromAnyBox: @ 80D1DFC
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1E38
	cmp r4, 0x1D
	bhi _080D1E38
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	movs r1, 0x2
	adds r2, r5, 0
	bl GetBoxMonData
	b _080D1E3C
	.pool
_080D1E38:
	movs r0, 0xFF
	strb r0, [r5]
_080D1E3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetBoxMonNickFromAnyBox

	thumb_func_start sub_80D1E44
sub_80D1E44: @ 80D1E44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r0, 0xD
	bhi _080D1E84
	cmp r2, 0x1D
	bhi _080D1E84
	ldr r6, =gPokemonStoragePtr
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	ldr r0, [r6]
	adds r0, r5
	lsls r1, r2, 2
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D1E84
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	bl GetLevelFromBoxMonExp
_080D1E84:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D1E44

	thumb_func_start SetBoxMonNickFromAnyBox
SetBoxMonNickFromAnyBox: @ 80D1E90
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1EC6
	cmp r4, 0x1D
	bhi _080D1EC6
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	movs r1, 0x2
	adds r2, r5, 0
	bl SetBoxMonData
_080D1EC6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonNickFromAnyBox

	thumb_func_start GetAndCopyBoxMonDataAt
GetAndCopyBoxMonDataAt: @ 80D1ED0
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1F10
	cmp r4, 0x1D
	bhi _080D1F10
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	adds r2, r6, 0
	bl GetBoxMonData
	b _080D1F12
	.pool
_080D1F10:
	movs r0, 0
_080D1F12:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetAndCopyBoxMonDataAt

	thumb_func_start SetBoxMonAt
SetBoxMonAt: @ 80D1F18
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r4, 0xD
	bhi _080D1F4E
	cmp r1, 0x1D
	bhi _080D1F4E
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	lsls r3, r1, 2
	adds r3, r1
	lsls r3, 4
	lsls r2, r4, 2
	adds r2, r4
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 5
	adds r3, r1
	adds r0, r3
	adds r0, 0x4
	adds r1, r5, 0
	movs r2, 0x50
	bl memcpy
_080D1F4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonAt

	thumb_func_start sub_80D1F58
sub_80D1F58: @ 80D1F58
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r4, 0xD
	bhi _080D1F8E
	cmp r2, 0x1D
	bhi _080D1F8E
	ldr r0, =gPokemonStoragePtr
	ldr r1, [r0]
	lsls r3, r2, 2
	adds r3, r2
	lsls r3, 4
	lsls r2, r4, 2
	adds r2, r4
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	adds r3, r0
	adds r1, r3
	adds r1, 0x4
	adds r0, r5, 0
	movs r2, 0x50
	bl memcpy
_080D1F8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1F58

	thumb_func_start sub_80D1F98
sub_80D1F98: @ 80D1F98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	ldr r4, [sp, 0x30]
	ldr r5, [sp, 0x34]
	ldr r6, [sp, 0x3C]
	mov r12, r6
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r0, r12
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r7, 0xD
	bhi _080D2004
	cmp r6, 0x1D
	bhi _080D2004
	ldr r2, =gPokemonStoragePtr
	lsls r0, r7, 2
	adds r0, r7
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 4
	adds r0, r1
	str r5, [sp]
	ldr r1, [sp, 0x38]
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r1, [sp, 0x40]
	str r1, [sp, 0xC]
	mov r1, r9
	mov r2, r8
	adds r3, r4, 0
	bl CreateBoxMon
_080D2004:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1F98

	thumb_func_start ZeroBoxMonAt
ZeroBoxMonAt: @ 80D2018
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D2048
	cmp r4, 0x1D
	bhi _080D2048
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	bl ZeroBoxMonData
_080D2048:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ZeroBoxMonAt

	thumb_func_start BoxMonAtToMon
BoxMonAtToMon: @ 80D2054
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D2088
	cmp r4, 0x1D
	bhi _080D2088
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	bl BoxMonToMon
_080D2088:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BoxMonAtToMon

	thumb_func_start GetBoxedMonPtr
@ pokemon *GetBoxedMonPtr(u8 box_id, u8 pos)
GetBoxedMonPtr: @ 80D2094
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D20C8
	cmp r4, 0x1D
	bhi _080D20C8
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	b _080D20CA
	.pool
_080D20C8:
	movs r0, 0
_080D20CA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBoxedMonPtr

	thumb_func_start GetBoxNamePtr
GetBoxNamePtr: @ 80D20D0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xD
	bls _080D20DE
	movs r0, 0
	b _080D20EC
_080D20DE:
	ldr r0, =gPokemonStoragePtr
	lsls r1, r2, 3
	adds r1, r2
	ldr r2, =0x00008344
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
_080D20EC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBoxNamePtr

	thumb_func_start GetBoxWallpaper
GetBoxWallpaper: @ 80D20F8
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bls _080D2106
	movs r0, 0
	b _080D2112
_080D2106:
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldr r2, =0x000083c2
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
_080D2112:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBoxWallpaper

	thumb_func_start SetBoxWallpaper
SetBoxWallpaper: @ 80D2120
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r2, 0xD
	bhi _080D213E
	cmp r1, 0x10
	bhi _080D213E
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldr r3, =0x000083c2
	adds r0, r3
	adds r0, r2
	strb r1, [r0]
_080D213E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxWallpaper

	thumb_func_start sub_80D214C
sub_80D214C: @ 80D214C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	adds r4, r3, 0
	ldr r2, =0x0000ffff
	cmp r3, 0x1
	bhi _080D216E
	movs r2, 0x1
	cmp r3, 0x1
	beq _080D2172
_080D216E:
	cmp r4, 0x3
	bne _080D21BC
_080D2172:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080D2208
	cmp r1, r7
	bgt _080D2208
_080D218A:
	asrs r4, r0, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	add r0, r8
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	bne _080D21B4
	asrs r0, r6, 16
	adds r0, r4, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080D2208
	cmp r2, r7
	ble _080D218A
	b _080D2208
	.pool
_080D21B4:
	adds r0, r4, 0
	b _080D220C
_080D21B8:
	adds r0, r5, 0
	b _080D220C
_080D21BC:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080D2208
	cmp r1, r7
	bgt _080D2208
_080D21D4:
	asrs r5, r0, 16
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 4
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _080D21F8
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetBoxMonData
	cmp r0, 0
	beq _080D21B8
_080D21F8:
	asrs r0, r6, 16
	adds r0, r5, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080D2208
	cmp r2, r7
	ble _080D21D4
_080D2208:
	movs r0, 0x1
	negs r0, r0
_080D220C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D214C

	thumb_func_start CheckFreePokemonStorageSpace
CheckFreePokemonStorageSpace: @ 80D2218
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gPokemonStoragePtr
	mov r8, r0
	movs r7, 0x4
_080D2228:
	movs r5, 0
	adds r6, r7, 0
	movs r4, 0
_080D222E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	adds r0, r4
	movs r1, 0x5
	str r2, [sp]
	bl GetBoxMonData
	ldr r2, [sp]
	cmp r0, 0
	bne _080D224C
	movs r0, 0x1
	b _080D2262
	.pool
_080D224C:
	adds r4, 0x50
	adds r5, 0x1
	cmp r5, 0x1D
	ble _080D222E
	movs r0, 0x96
	lsls r0, 4
	adds r7, r0
	adds r2, 0x1
	cmp r2, 0xD
	ble _080D2228
	movs r0, 0
_080D2262:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckFreePokemonStorageSpace

	thumb_func_start CheckBoxedMonSanity
CheckBoxedMonSanity: @ 80D2270
	push {r4-r6,lr}
	adds r2, r1, 0
	cmp r0, 0xD
	bhi _080D22C8
	cmp r2, 0x1D
	bhi _080D22C8
	ldr r6, =gPokemonStoragePtr
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	ldr r0, [r6]
	adds r0, r5
	lsls r1, r2, 2
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D22C8
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D22C8
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0x4
	bl GetBoxMonData
	cmp r0, 0
	bne _080D22C8
	movs r0, 0x1
	b _080D22CA
	.pool
_080D22C8:
	movs r0, 0
_080D22CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CheckBoxedMonSanity

	thumb_func_start sub_80D22D0
sub_80D22D0: @ 80D22D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	movs r0, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_080D22E0:
	lsls r1, r0, 2
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	movs r5, 0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r4, r0, 0x4
	movs r6, 0x1D
_080D22F4:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	adds r0, r5
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D231A
	mov r2, r9
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D231A
	adds r7, 0x1
_080D231A:
	adds r5, 0x50
	subs r6, 0x1
	cmp r6, 0
	bge _080D22F4
	mov r0, r8
	cmp r0, 0xD
	ble _080D22E0
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D22D0

	thumb_func_start sub_80D233C
sub_80D233C: @ 80D233C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	movs r0, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_080D234C:
	lsls r1, r0, 2
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	movs r5, 0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r4, r0, 0x4
	movs r6, 0x1D
_080D2360:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	adds r0, r5
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	bne _080D2384
	mov r2, r9
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2386
_080D2384:
	adds r7, 0x1
_080D2386:
	adds r5, 0x50
	subs r6, 0x1
	cmp r6, 0
	bge _080D2360
	mov r0, r8
	cmp r0, 0xD
	ble _080D234C
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D233C

	thumb_func_start sub_80D23A8
sub_80D23A8: @ 80D23A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	ldr r0, =0x00000163
	strh r0, [r1, 0x2]
	movs r0, 0
	mov r8, r0
	ldr r7, =gPokemonStoragePtr
	movs r5, 0x4
_080D23C0:
	movs r6, 0
	movs r4, 0
_080D23C4:
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2404
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D2404
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x51
	mov r2, sp
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2404
	movs r0, 0x1
	b _080D241E
	.pool
_080D2404:
	adds r4, 0x50
	adds r6, 0x1
	cmp r6, 0x1D
	ble _080D23C4
	movs r0, 0x96
	lsls r0, 4
	adds r5, r0
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0xD
	ble _080D23C0
	movs r0, 0
_080D241E:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D23A8

	thumb_func_start ResetWaldaWallpaper
ResetWaldaWallpaper: @ 80D242C
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x00003d84
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, =0x00003d85
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, =0x00003d70
	adds r2, r1, r0
	ldr r0, =0x00007b35
	strh r0, [r2]
	subs r3, 0x14
	adds r2, r1, r3
	ldr r0, =0x00006186
	strh r0, [r2]
	ldr r0, =0x00003d74
	adds r1, r0
	movs r0, 0xFF
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetWaldaWallpaper

	thumb_func_start SetWaldaWallpaperLockedOrUnlocked
SetWaldaWallpaperLockedOrUnlocked: @ 80D2480
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x00003d86
	adds r1, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end SetWaldaWallpaperLockedOrUnlocked

	thumb_func_start IsWaldaWallpaperUnlocked
IsWaldaWallpaperUnlocked: @ 80D2494
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d86
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end IsWaldaWallpaperUnlocked

	thumb_func_start GetWaldaWallpaperPatternId
GetWaldaWallpaperPatternId: @ 80D24A8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d85
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperPatternId

	thumb_func_start SetWaldaWallpaperPatternId
SetWaldaWallpaperPatternId: @ 80D24BC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bhi _080D24D0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d85
	adds r0, r2
	strb r1, [r0]
_080D24D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperPatternId

	thumb_func_start GetWaldaWallpaperIconId
GetWaldaWallpaperIconId: @ 80D24DC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d84
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperIconId

	thumb_func_start SetWaldaWallpaperIconId
SetWaldaWallpaperIconId: @ 80D24F0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1D
	bhi _080D2504
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d84
	adds r0, r2
	strb r1, [r0]
_080D2504:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperIconId

	thumb_func_start GetWaldaWallpaperColorsPtr
GetWaldaWallpaperColorsPtr: @ 80D2510
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d70
	adds r0, r1
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperColorsPtr

	thumb_func_start SetWaldaWallpaperColors
SetWaldaWallpaperColors: @ 80D2524
	push {r4,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	ldr r4, =0x00003d70
	adds r3, r2, r4
	strh r0, [r3]
	ldr r0, =0x00003d72
	adds r2, r0
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperColors

	thumb_func_start GetWaldaPhrasePtr
GetWaldaPhrasePtr: @ 80D2548
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d74
	adds r0, r1
	bx lr
	.pool
	thumb_func_end GetWaldaPhrasePtr

	thumb_func_start SetWaldaPhrase
SetWaldaPhrase: @ 80D255C
	push {lr}
	adds r1, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d74
	adds r0, r2
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaPhrase

	thumb_func_start IsWaldaPhraseEmpty
IsWaldaPhraseEmpty: @ 80D2578
	push {lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d74
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080D258C
	movs r1, 0x1
_080D258C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsWaldaPhraseEmpty

	thumb_func_start sub_80D259C
sub_80D259C: @ 80D259C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_02039D84
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 4
	bl Alloc
	str r0, [r6]
	ldr r5, =gUnknown_02039D88
	movs r1, 0
	cmp r0, 0
	beq _080D25BA
	adds r1, r4, 0
_080D25BA:
	strh r1, [r5]
	movs r2, 0
	cmp r2, r1
	bcs _080D25E2
	movs r3, 0
	adds r4, r5, 0
_080D25C6:
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 4
	adds r1, r0
	str r3, [r1, 0x18]
	adds r1, 0x2C
	strb r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r4]
	cmp r2, r0
	bcc _080D25C6
_080D25E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D259C

	thumb_func_start sub_80D25F0
sub_80D25F0: @ 80D25F0
	push {lr}
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D25F0

	thumb_func_start sub_80D2604
sub_80D2604: @ 80D2604
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	bge _080D2634
	movs r5, 0
_080D2612:
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	adds r0, r5, r0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D2628
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80D2918
_080D2628:
	adds r5, 0x30
	adds r4, 0x1
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	blt _080D2612
_080D2634:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2604

	thumb_func_start sub_80D2644
sub_80D2644: @ 80D2644
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r2, 0
	ldr r2, [sp, 0x24]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r3, 16
	lsrs r3, 16
	mov r10, r3
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080D272C
	ldr r0, =gUnknown_02039D84
	mov r9, r0
	ldr r0, [r0]
	lsls r1, r6, 1
	mov r8, r1
	adds r5, r1, r6
	lsls r5, 4
	adds r0, r5, r0
	movs r1, 0
	str r1, [r0, 0x18]
	str r4, [r0, 0x1C]
	adds r0, 0x2B
	strb r7, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, r5, r0
	mov r3, r10
	strh r3, [r0, 0x24]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x26]
	adds r0, r7, 0
	movs r1, 0x3
	bl GetBgAttribute
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	movs r1, 0x9
	bl GetBgAttribute
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	ldr r1, [r2]
	adds r5, r1
	ldr r2, =gSpriteTemplate_857BC88
	lsls r4, 2
	lsls r1, r0, 4
	adds r4, r1
	adds r4, r2
	ldrh r1, [r4]
	strh r1, [r5, 0x20]
	ldrh r1, [r4, 0x2]
	strh r1, [r5, 0x22]
	mov r2, r8
	cmp r0, 0
	beq _080D26E8
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x1
	b _080D26EE
	.pool
_080D26E8:
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x2
_080D26EE:
	strb r0, [r1]
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	adds r2, r6
	lsls r2, 4
	adds r1, r2, r1
	adds r0, r1, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	mov r3, r10
	muls r3, r0
	movs r0, 0
	strh r3, [r1, 0x28]
	mov r3, r10
	strh r3, [r1, 0x10]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1, 0x12]
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, [r4]
	adds r2, r0
	adds r2, 0x2C
	movs r0, 0x1
	strb r0, [r2]
_080D272C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2644

	thumb_func_start sub_80D2740
sub_80D2740: @ 80D2740
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2764
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r0, r1
	str r3, [r0, 0x18]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D2764:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2740

	thumb_func_start sub_80D2770
sub_80D2770: @ 80D2770
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r3, r0
	bcs _080D279C
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 4
	adds r0, r1
	strh r4, [r0, 0x14]
	strh r2, [r0, 0x16]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D279C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2770

	thumb_func_start sub_80D27AC
sub_80D27AC: @ 80D27AC
	push {r4-r6,lr}
	ldr r4, [sp, 0x10]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcs _080D27E6
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 4
	adds r0, r1
	strh r6, [r0, 0xC]
	strh r2, [r0, 0xE]
	strh r3, [r0, 0x10]
	strh r4, [r0, 0x12]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D27E6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27AC

	thumb_func_start sub_80D27F4
sub_80D27F4: @ 80D27F4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080D280C
	b _080D290E
_080D280C:
	ldr r4, =gUnknown_02039D84
	lsls r2, r5, 1
	cmp r1, 0x5
	bls _080D2816
	b _080D2900
_080D2816:
	lsls r0, r1, 2
	ldr r1, =_080D282C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D282C:
	.4byte _080D2844
	.4byte _080D2864
	.4byte _080D2888
	.4byte _080D28A8
	.4byte _080D28CC
	.4byte _080D28E8
_080D2844:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x14]
	adds r0, r2
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x10]
	subs r0, r2
	b _080D287E
	.pool
_080D2864:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x10]
	adds r0, r2
_080D287E:
	strh r0, [r1, 0x10]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D2888:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x16]
	adds r0, r2
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x12]
	subs r0, r2
	b _080D28C2
	.pool
_080D28A8:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xE]
	subs r0, r2
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x12]
	adds r0, r2
_080D28C2:
	strh r0, [r1, 0x12]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D28CC:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x14]
	adds r0, r4
	strh r0, [r1, 0x14]
	b _080D28FE
	.pool
_080D28E8:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x16]
	adds r0, r4
	strh r0, [r1, 0x16]
_080D28FE:
	adds r4, r3, 0
_080D2900:
	ldr r0, [r4]
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0x1
	strb r0, [r1]
_080D290E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27F4

	thumb_func_start sub_80D2918
sub_80D2918: @ 80D2918
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r6, r2, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2952
	ldr r5, =gUnknown_02039D84
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4, r0
	ldr r0, [r0, 0x18]
	cmp r0, 0
	beq _080D2940
	adds r0, r2, 0
	bl sub_80D2960
_080D2940:
	adds r0, r6, 0
	bl sub_80D29F8
	ldr r1, [r5]
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080D2952:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2918

	thumb_func_start sub_80D2960
sub_80D2960: @ 80D2960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x20]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x18]
	adds r1, r2
	movs r6, 0x8
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x6]
	cmp r6, r0
	bge _080D29E4
	mov r10, r4
_080D29AA:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x8]
	ldrb r3, [r1, 0xA]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x4]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x6]
	cmp r6, r4
	blt _080D29AA
_080D29E4:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2960

	thumb_func_start sub_80D29F8
sub_80D29F8: @ 80D29F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x24]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xE
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x1C]
	adds r1, r2
	movs r6, 0xC
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x12]
	cmp r6, r0
	bge _080D2A7C
	mov r10, r4
_080D2A42:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x14]
	ldrb r3, [r1, 0x16]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x10]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x12]
	cmp r6, r4
	blt _080D2A42
_080D2A7C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D29F8

	thumb_func_start sub_80D2A90
sub_80D2A90: @ 80D2A90
	ldr r3, =gUnknown_02039D8C
	str r0, [r3]
	str r1, [r0]
	movs r1, 0
	strb r2, [r0, 0x5]
	strb r1, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_80D2A90

	thumb_func_start sub_80D2AA4
sub_80D2AA4: @ 80D2AA4
	push {r4,r5,lr}
	ldr r2, =gUnknown_02039D8C
	ldr r1, [r2]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080D2AE2
	movs r4, 0
	ldrb r1, [r1, 0x4]
	cmp r4, r1
	bcs _080D2ADA
	adds r5, r2, 0
_080D2ABA:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r0, r1
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bcc _080D2ABA
_080D2ADA:
	ldr r0, =gUnknown_02039D8C
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x4]
_080D2AE2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2AA4

	thumb_func_start sub_80D2AEC
sub_80D2AEC: @ 80D2AEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	mov r10, r3
	ldr r0, [sp, 0x24]
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2B74
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r4, 1
	strh r0, [r1, 0x8]
	ldr r2, [sp]
	lsls r0, r2, 5
	add r0, r12
	lsls r0, 1
	add r0, r9
	str r0, [r1, 0x4]
	adds r0, r3, 0
	muls r0, r6
	add r0, r8
	lsls r0, 1
	add r0, r10
	str r0, [r1]
	strh r5, [r1, 0xC]
	strh r6, [r1, 0xA]
	ldr r0, =sub_80D2B88
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2B76
	.pool
_080D2B74:
	movs r0, 0
_080D2B76:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2AEC

	thumb_func_start sub_80D2B88
sub_80D2B88: @ 80D2B88
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	b _080D2BB2
_080D2B90:
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldrh r2, [r4, 0x8]
	lsrs r2, 1
	bl CpuSet
	ldr r0, [r4, 0x4]
	adds r0, 0x40
	str r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	lsls r1, 1
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080D2BB2:
	ldrh r0, [r4, 0xC]
	cmp r5, r0
	bcc _080D2B90
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80D2B88

	thumb_func_start sub_80D2BC0
sub_80D2BC0: @ 80D2BC0
	push {r4-r7,lr}
	mov r12, r0
	ldr r0, [sp, 0x14]
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2C14
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r3, 1
	strh r0, [r1, 0x8]
	lsls r0, r4, 5
	adds r0, r6
	lsls r0, 1
	add r0, r12
	str r0, [r1, 0x4]
	strh r5, [r1, 0xC]
	ldr r0, =sub_80D2C1C
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2C16
	.pool
_080D2C14:
	movs r0, 0
_080D2C16:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2BC0

	thumb_func_start sub_80D2C1C
sub_80D2C1C: @ 80D2C1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	movs r0, 0
	ldrh r1, [r6, 0xC]
	cmp r0, r1
	bcs _080D2CAA
	movs r7, 0x80
	lsls r7, 5
	mov r5, sp
	ldr r2, =0x040000d4
	mov r8, r2
	movs r1, 0x81
	lsls r1, 24
	mov r10, r1
_080D2C42:
	ldr r2, [r6, 0x4]
	ldrh r3, [r6, 0x8]
	mov r12, r2
	adds r0, 0x1
	mov r9, r0
	cmp r3, r7
	bhi _080D2C6C
	movs r0, 0
	strh r0, [r5]
	mov r2, sp
	mov r0, r8
	str r2, [r0]
	mov r1, r12
	str r1, [r0, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
	mov r1, r8
	b _080D2C94
	.pool
_080D2C6C:
	movs r4, 0
	strh r4, [r5]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x81000800
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r7
	subs r3, r7
	cmp r3, r7
	bhi _080D2C6C
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
_080D2C94:
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, r12
	adds r0, 0x40
	str r0, [r6, 0x4]
	mov r1, r9
	lsls r0, r1, 16
	lsrs r0, 16
	ldrh r2, [r6, 0xC]
	cmp r0, r2
	bcc _080D2C42
_080D2CAA:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2C1C

	.align 2, 0 @ Don't pad with nop.
