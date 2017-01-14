	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8098758
sub_8098758: @ 8098758
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _08098770
	lsls r0, 3
	ldr r1, =gUnknown_0851021C
	adds r0, r1
	b _08098772
	.pool
_08098770:
	ldr r0, =gUnknown_0851021C
_08098772:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8098758

	thumb_func_start copy_textbox_border_tile_patterns_to_vram
@ void copy_textbox_border_tile_patterns_to_vram(u8 rbox_id, u16 tile_pattern_dest_offset, u8 pal_dest_offset)
copy_textbox_border_tile_patterns_to_vram: @ 809877C
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_08DDD748
	movs r2, 0xE0
	lsls r2, 1
	adds r3, r4, 0
	bl LoadBgTiles
	bl sub_8098C64
	adds r1, r5, 0
	movs r2, 0x20
	bl gpu_pal_apply
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_textbox_border_tile_patterns_to_vram

	thumb_func_start box_border_load_tiles_and_pal
box_border_load_tiles_and_pal: @ 80987BC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	bl sub_809882C
	pop {r0}
	bx r0
	thumb_func_end box_border_load_tiles_and_pal

	thumb_func_start sub_80987D4
sub_80987D4: @ 80987D4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 16
	lsrs r6, 16
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0851021C
	lsls r4, 3
	adds r1, r4, r5
	ldr r1, [r1]
	movs r2, 0x90
	lsls r2, 1
	adds r3, r6, 0
	bl LoadBgTiles
	adds r5, 0x4
	adds r4, r5
	ldr r0, [r4]
	mov r1, r8
	movs r2, 0x20
	bl gpu_pal_apply
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80987D4

	thumb_func_start sub_809882C
sub_809882C: @ 809882C
	push {r4,lr}
	adds r4, r1, 0
	adds r3, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r3, 24
	lsrs r3, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldrb r1, [r1, 0x14]
	lsrs r1, 3
	adds r2, r4, 0
	bl sub_80987D4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809882C

	thumb_func_start sub_8098858
sub_8098858: @ 8098858
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 16
	lsrs r5, 16
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl GetWindowAttribute
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0x2
	bl GetWindowAttribute
	adds r6, r0, 0
	lsls r6, 16
	lsrs r6, 16
	adds r0, r4, 0
	movs r1, 0x3
	bl GetWindowAttribute
	mov r9, r0
	mov r2, r9
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	adds r0, r4, 0
	movs r1, 0x4
	bl GetWindowAttribute
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	mov r0, r8
	subs r0, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	subs r4, r6, 0x1
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	mov r10, r0
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0xC]
	str r2, [sp, 0x8]
	adds r0, r7, 0
	adds r1, r5, 0
	ldr r2, [sp, 0x14]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	adds r1, r5, 0x1
	lsls r1, 16
	lsrs r1, 16
	mov r0, r8
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	mov r2, r9
	lsls r0, r2, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	ldr r2, [sp, 0xC]
	str r2, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x18]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	adds r1, r5, 0x2
	lsls r1, 16
	lsrs r1, 16
	add r8, r9
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r2, r10
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	adds r1, r5, 0x3
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r6, 24
	lsrs r2, 24
	mov r9, r2
	mov r0, r10
	str r0, [sp]
	ldr r2, [sp, 0x10]
	lsls r4, r2, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x14]
	mov r3, r9
	bl FillBgTilemapBufferRect
	adds r1, r5, 0x5
	lsls r1, 16
	lsrs r1, 16
	mov r2, r10
	str r2, [sp]
	str r4, [sp, 0x4]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	mov r3, r9
	bl FillBgTilemapBufferRect
	adds r1, r5, 0x6
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x10]
	adds r6, r2
	lsls r6, 24
	lsrs r6, 24
	mov r0, r10
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0xC]
	str r2, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x14]
	adds r3, r6, 0
	bl FillBgTilemapBufferRect
	adds r1, r5, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x1C]
	str r0, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x18]
	adds r3, r6, 0
	bl FillBgTilemapBufferRect
	adds r5, 0x8
	lsls r5, 16
	lsrs r5, 16
	mov r2, r10
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r8
	adds r3, r6, 0
	bl FillBgTilemapBufferRect
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8098858

	thumb_func_start sub_80989E0
sub_80989E0: @ 80989E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r4, r0, 0
	mov r9, r1
	lsls r4, 24
	lsrs r4, 24
	mov r0, r9
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	adds r0, r4, 0
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl GetWindowAttribute
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0x2
	bl GetWindowAttribute
	adds r6, r0, 0
	lsls r6, 16
	lsrs r6, 16
	adds r0, r4, 0
	movs r1, 0x3
	bl GetWindowAttribute
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	movs r1, 0x4
	bl GetWindowAttribute
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, r8
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x10]
	lsls r4, r6, 24
	lsrs r4, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r1, r9
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	mov r1, r9
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	mov r0, r8
	adds r0, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	subs r0, r5, 0x2
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	mov r1, r9
	adds r1, 0x2
	lsls r1, 16
	lsrs r1, 16
	add r8, r5
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	mov r1, r9
	adds r1, 0x3
	lsls r1, 16
	lsrs r1, 16
	adds r5, r6, 0x1
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x1
	str r0, [sp]
	ldr r4, [sp, 0xC]
	subs r4, 0x2
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x10]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	mov r1, r9
	adds r1, 0x5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	mov r1, r9
	adds r1, 0x6
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0xC]
	adds r6, r0
	subs r6, 0x1
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x10]
	adds r3, r6, 0
	bl FillBgTilemapBufferRect
	mov r1, r9
	adds r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0x14]
	adds r3, r6, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x8
	add r9, r0
	mov r0, r9
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r1, r9
	mov r2, r8
	adds r3, r6, 0
	bl FillBgTilemapBufferRect
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80989E0

	thumb_func_start rbox_fill_rectangle
rbox_fill_rectangle: @ 8098B7C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	adds r0, r6, 0
	movs r1, 0
	bl GetWindowAttribute
	mov r9, r0
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r6, 0
	movs r1, 0x1
	bl GetWindowAttribute
	mov r8, r0
	mov r1, r8
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	adds r0, r6, 0
	movs r1, 0x2
	bl GetWindowAttribute
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	movs r1, 0x3
	bl GetWindowAttribute
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r6, 0
	movs r1, 0x4
	bl GetWindowAttribute
	movs r1, 0x1
	negs r1, r1
	add r8, r1
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	subs r5, 0x1
	lsls r5, 24
	lsrs r5, 24
	adds r4, 0x2
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	lsls r0, 24
	movs r1, 0x80
	lsls r1, 18
	adds r0, r1
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	mov r0, r9
	movs r1, 0
	mov r2, r8
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end rbox_fill_rectangle

	thumb_func_start stdpal_get
stdpal_get: @ 8098C18
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _08098C54
	lsls r0, 2
	ldr r1, =_08098C30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08098C30:
	.4byte _08098C44
	.4byte _08098C48
	.4byte _08098C4C
	.4byte _08098C50
	.4byte _08098C54
_08098C44:
	movs r0, 0
	b _08098C56
_08098C48:
	movs r0, 0x10
	b _08098C56
_08098C4C:
	movs r0, 0x20
	b _08098C56
_08098C50:
	movs r0, 0x30
	b _08098C56
_08098C54:
	movs r0, 0x40
_08098C56:
	lsls r0, 1
	ldr r1, =gUnknown_0851017C
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end stdpal_get

	thumb_func_start sub_8098C64
sub_8098C64: @ 8098C64
	ldr r0, =gUnknown_08DDD728
	bx lr
	.pool
	thumb_func_end sub_8098C64

	thumb_func_start sub_8098C6C
sub_8098C6C: @ 8098C6C
	push {r4,r5,lr}
	adds r3, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r2, =gUnknown_0851021C
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldrb r1, [r1, 0x14]
	lsrs r1, 3
	lsls r1, 3
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0x90
	lsls r2, 1
	bl LoadBgTiles
	ldr r0, [r5]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8098758
	ldr r0, [r0, 0x4]
	adds r1, r4, 0
	movs r2, 0x20
	bl gpu_pal_apply
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098C6C

	.align 2, 0 @ Don't pad with nop.
