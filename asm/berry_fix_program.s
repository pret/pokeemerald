	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81BF7A4
sub_81BF7A4: @ 81BF7A4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_030012B8
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	cmp r0, r4
	bne _081BF7BC
	adds r0, r4, 0
	b _081BF7DC
	.pool
_081BF7BC:
	cmp r0, 0x6
	bne _081BF7CC
	adds r0, r4, 0
	bl sub_81BF7E8
	ldr r0, [r5]
	strb r4, [r0, 0x1]
	b _081BF7D6
_081BF7CC:
	bl sub_81BF8D8
	ldr r1, [r5]
	movs r0, 0x6
	strb r0, [r1, 0x1]
_081BF7D6:
	ldr r0, =gUnknown_030012B8
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
_081BF7DC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81BF7A4

	thumb_func_start sub_81BF7E8
sub_81BF7E8: @ 81BF7E8
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	movs r1, 0xAA
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_08618158
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_08618160
	lsls r4, r6, 2
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl box_print
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	cmp r6, 0x5
	bhi _081BF87E
	ldr r0, =_081BF850
	adds r0, r4, r0
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BF850:
	.4byte _081BF868
	.4byte _081BF870
	.4byte _081BF868
	.4byte _081BF868
	.4byte _081BF868
	.4byte _081BF878
_081BF868:
	movs r0, 0x2
	bl PutWindowTilemap
	b _081BF87E
_081BF870:
	movs r0, 0x3
	bl PutWindowTilemap
	b _081BF87E
_081BF878:
	movs r0, 0
	bl PutWindowTilemap
_081BF87E:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r5, =gUnknown_08618178
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 2
	adds r0, r4, r5
	ldr r0, [r0]
	ldr r1, =0x06004000
	bl LZ77UnCompVram
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	adds r5, 0x8
	adds r4, r5
	ldr r0, [r4]
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x04000040
	bl CpuSet
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF7E8

	thumb_func_start sub_81BF8D8
sub_81BF8D8: @ 81BF8D8
	push {lr}
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	pop {r0}
	bx r0
	thumb_func_end sub_81BF8D8

	.align 2, 0 @ Don't pad with nop.
