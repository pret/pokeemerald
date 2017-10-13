	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
