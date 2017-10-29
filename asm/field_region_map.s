	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8170428
sub_8170428: @ 8170428
	push {r4,lr}
	sub sp, 0xC
	ldr r4, =gUnknown_0203BCD0
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08170460
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, [r4]
	adds r2, 0xC
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	b _08170470
	.pool
_08170460:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08170470:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8170428

	.align 2, 0 @ Don't pad with nop.
