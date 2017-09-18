	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81BF5A4
sub_81BF5A4: @ 81BF5A4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0
	str r1, [sp, 0xC]
	ldr r4, =0x040000d4
	add r0, sp, 0xC
	str r0, [r4]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r4, 0x4]
	ldr r0, =0x85006000
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	str r0, [r4]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r4, 0x4]
	ldr r2, =0x85000100
	str r2, [r4, 0x8]
	ldr r0, [r4, 0x8]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	str r0, [r4]
	movs r0, 0xA0
	lsls r0, 19
	str r0, [r4, 0x4]
	str r2, [r4, 0x8]
	ldr r0, [r4, 0x8]
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08618108
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_08618110
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r0, =gUnknown_08618138
	str r0, [r4]
	ldr r0, =0x050001e0
	str r0, [r4, 0x4]
	ldr r0, =0x84000008
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	movs r0, 0
	movs r1, 0x40
	bl SetGpuReg
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0xAA
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_08617E9B
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r4, 0x78
	subs r0, r4, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r6, =gUnknown_0861815B
	str r6, [sp]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r3, 0x3
	bl box_print
	ldr r5, =gUnknown_08617E8D
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	subs r4, r1
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r0, r4, 0
	adds r0, 0x78
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r3, 0x3
	bl box_print
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0x70
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r3, 0
	bl box_print
	ldr r4, =gUnknown_08617E78
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xD0
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_08618158
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x2
	bl box_print
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF5A4

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
