	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8121A1C
sub_8121A1C: @ 8121A1C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	movs r5, 0
	ldr r2, =gUnknown_0203A134
	ldr r0, [r2]
	movs r1, 0x8A
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r5, r0
	bcs _08121A8A
	mov r8, r2
	adds r7, r1, 0
_08121A3C:
	lsls r0, r5, 6
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r0
	movs r3, 0x85
	lsls r3, 2
	adds r1, r2, r3
	lsls r3, r6, 1
	ldr r1, [r1]
	adds r1, r3
	adds r2, r7
	ldr r2, [r2]
	ldr r2, [r2, 0x8]
	lsls r4, r5, 2
	adds r2, r4, r2
	ldr r2, [r2]
	lsls r2, 30
	lsrs r2, 30
	movs r3, 0x1
	bl ConvertEasyChatWordsToString
	mov r1, r8
	ldr r0, [r1]
	adds r0, r7
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r4, r0
	ldr r0, [r4]
	lsls r0, 30
	lsrs r0, 30
	adds r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r1, [r1]
	cmp r5, r1
	bcc _08121A3C
_08121A8A:
	ldr r4, =gUnknown_0203A134
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r1, r2
	movs r3, 0x85
	lsls r3, 2
	adds r1, r3
	ldr r1, [r1]
	adds r1, 0x12
	bl StringCopy
	adds r2, r0, 0
	ldr r1, [r4]
	ldr r3, =0x0000021e
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08121AF0
	ldr r1, =gText_FromSpace
	adds r0, r2, 0
	bl StringCopy
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1
	bl StringLength
	ldr r2, [r4]
	movs r3, 0x8A
	lsls r3, 2
	adds r1, r2, r3
	ldr r1, [r1]
	lsls r0, 16
	lsrs r0, 13
	subs r0, 0x60
	ldrb r1, [r1, 0x2]
	subs r1, r0
	ldr r0, =0x00000219
	adds r2, r0
	strb r1, [r2]
	b _08121B0C
	.pool
_08121AF0:
	movs r2, 0x80
	lsls r2, 2
	adds r0, r1, r2
	bl sub_81DB52C
	ldr r0, [r4]
	movs r3, 0x8A
	lsls r3, 2
	adds r1, r0, r3
	ldr r1, [r1]
	ldrb r1, [r1, 0x2]
	ldr r2, =0x00000219
	adds r0, r2
	strb r1, [r0]
_08121B0C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121A1C

	thumb_func_start sub_8121B1C
sub_8121B1C: @ 8121B1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	movs r7, 0
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r6, 0
	ldr r1, =gUnknown_0203A134
	ldr r0, [r1]
	movs r2, 0x8A
	lsls r2, 2
	mov r10, r2
	add r0, r10
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r6, r0
	bcs _08121BCC
	mov r9, r1
	mov r8, r10
_08121B60:
	mov r0, r9
	ldr r1, [r0]
	lsls r0, r6, 6
	adds r5, r1, r0
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _08121BB8
	cmp r0, 0
	beq _08121BB8
	mov r2, r8
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	lsls r4, r6, 2
	adds r0, r4, r0
	ldr r2, [r0]
	lsls r2, 24
	lsrs r2, 26
	ldrb r0, [r1, 0x4]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r1, 0x3]
	adds r3, r7, r3
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0859F2AC
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	bl box_print
	mov r1, r9
	ldr r0, [r1]
	add r0, r8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r4, r0
	ldrb r0, [r4, 0x1]
	adds r0, r7, r0
	lsls r0, 24
	lsrs r7, r0, 24
_08121BB8:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r2, =gUnknown_0203A134
	ldr r0, [r2]
	add r0, r10
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08121B60
_08121BCC:
	ldr r1, =gText_FromSpace
	add r0, sp, 0xC
	bl StringCopy
	ldr r4, =gUnknown_0203A134
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00000219
	adds r0, r1
	ldrb r2, [r0]
	movs r0, 0x1
	add r1, sp, 0xC
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	adds r2, 0x68
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r3, [r0, 0x1]
	adds r3, 0x58
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0859F2AC
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121B1C

	thumb_func_start sub_8121C50
sub_8121C50: @ 8121C50
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8121C50

	thumb_func_start sub_8121C64
sub_8121C64: @ 8121C64
	push {r4,lr}
	ldr r4, =gUnknown_0203A134
	ldr r0, [r4]
	ldr r1, =0x0000021b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08121C7C
	bl AnimateSprites
	bl BuildOamBuffer
_08121C7C:
	ldr r0, [r4]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121C64

	thumb_func_start sub_8121C98
sub_8121C98: @ 8121C98
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08121CB2
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r1, =sub_8121CC0
	str r1, [r0]
_08121CB2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121C98

	thumb_func_start sub_8121CC0
sub_8121CC0: @ 8121CC0
	push {lr}
	sub sp, 0x4
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08121CEE
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203A134
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 2
	adds r0, r1
	ldr r1, =sub_8121D00
	str r1, [r0]
_08121CEE:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121CC0

	thumb_func_start sub_8121D00
sub_8121D00: @ 8121D00
	push {r4,lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08121D88
	ldr r4, =gUnknown_0203A134
	ldr r0, [r4]
	movs r1, 0x83
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r1, [r4]
	ldr r2, =0x0000021b
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bgt _08121D58
	cmp r0, 0x1
	blt _08121D58
	subs r2, 0x7
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r0, [r0, 0x1E]
	bl sub_80D2E84
	lsls r0, 16
	lsrs r0, 16
	bl sub_80D2FF0
	ldr r0, [r4]
	movs r1, 0x87
	lsls r1, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D2EF8
_08121D58:
	ldr r4, =gUnknown_0203A134
	ldr r0, [r4]
	ldr r2, =0x0000222c
	movs r1, 0
	bl memset
	bl ResetPaletteFade
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	bl FreeAllWindowBuffers
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_08121D88:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121D00

	.align 2, 0 @ Don't pad with nop.
