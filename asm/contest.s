	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start TaskDummy1
TaskDummy1: @ 80D7668
	bx lr
	thumb_func_end TaskDummy1

	thumb_func_start ResetLinkContestBoolean
ResetLinkContestBoolean: @ 80D766C
	ldr r1, =gUnknown_02039F2A
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetLinkContestBoolean

	thumb_func_start sub_80D7678
sub_80D7678: @ 80D7678
	push {r4,lr}
	movs r0, 0
	movs r1, 0x40
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	movs r1, 0xFE
	lsls r1, 7
	movs r0, 0
	bl SetGpuRegBits
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG1_X
	strh r1, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG2_X
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG3_X
	strh r1, [r0]
	ldr r0, =gBattle_BG3_Y
	strh r1, [r0]
	ldr r0, =gBattle_WIN0H
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r0, =gBattle_WIN1H
	strh r1, [r0]
	ldr r0, =gBattle_WIN1V
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7678

	thumb_func_start sub_80D7724
sub_80D7724: @ 80D7724
	push {r4,r5,lr}
	ldr r0, =gUnknown_08C17AB0
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	ldr r0, =gUnknown_08C1850C
	ldr r1, =0x06002000
	bl LZDecompressVram
	ldr r1, =gUnknown_08C16FA8
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_08C16E90
	movs r2, 0x80
	lsls r2, 2
	movs r1, 0
	bl LoadCompressedPalette
	bl sub_80D782C
	movs r4, 0
	movs r5, 0xA0
_080D775E:
	ldr r0, =0x0201a004
	adds r0, r5, r0
	ldr r1, =gUnknown_02039F26
	adds r1, r4, r1
	ldrb r1, [r1]
	adds r1, 0x5
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	adds r5, 0x20
	adds r4, 0x1
	cmp r4, 0x3
	ble _080D775E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7724

	thumb_func_start sub_80D779C
sub_80D779C: @ 80D779C
	push {r4,lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08587F34
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r0, 0x3
	movs r1, 0x6
	movs r2, 0x1
	bl SetBgAttribute
	movs r4, 0
_080D77BA:
	lsls r0, r4, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	lsls r2, r4, 2
	adds r1, 0x24
	adds r1, r2
	ldr r1, [r1]
	bl SetBgTilemapBuffer
	adds r4, 0x1
	cmp r4, 0x3
	ble _080D77BA
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D779C

	thumb_func_start sub_80D77E4
sub_80D77E4: @ 80D77E4
	push {lr}
	ldr r0, =gUnknown_08587F44
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D7818
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _080D7822
	.pool
_080D7818:
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
_080D7822:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D77E4

	thumb_func_start sub_80D782C
sub_80D782C: @ 80D782C
	push {r4,r5,lr}
	ldr r0, =gUnknown_08587C30
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	movs r5, 0xA
	movs r4, 0xFA
	lsls r4, 16
_080D7848:
	lsrs r1, r4, 16
	ldr r0, =gPlttBufferUnfaded + 0x1E2
	movs r2, 0x2
	bl LoadPalette
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r5, 0x1
	cmp r5, 0xD
	ble _080D7848
	ldr r0, =0x00007e3f
	movs r1, 0xF3
	movs r2, 0x2
	bl FillPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D782C

	thumb_func_start sub_80D787C
sub_80D787C: @ 80D787C
	push {r4-r7,lr}
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x5C
	bl memset
	movs r5, 0
	movs r2, 0xFF
_080D7890:
	ldr r0, [r4]
	ldr r1, [r0]
	adds r1, 0x2
	adds r1, r5
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080D7890
	movs r4, 0
	ldr r6, =gUnknown_02039F34
	movs r5, 0x3
_080D78AA:
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	movs r1, 0
	movs r2, 0x1C
	bl memset
	adds r4, 0x1C
	subs r5, 0x1
	cmp r5, 0
	bge _080D78AA
	ldr r4, =gUnknown_02039F34
	movs r7, 0x4
	negs r7, r7
	movs r6, 0xFF
	movs r3, 0
	movs r5, 0x3
_080D78CC:
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, r3, r1
	ldrb r2, [r1, 0xB]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1, 0xB]
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, r3, r1
	ldrb r0, [r1, 0x13]
	orrs r0, r6
	strb r0, [r1, 0x13]
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, r3, r1
	ldrb r0, [r1, 0x14]
	orrs r0, r6
	strb r0, [r1, 0x14]
	adds r3, 0x1C
	subs r5, 0x1
	cmp r5, 0
	bge _080D78CC
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r1, 0
	movs r2, 0x14
	bl memset
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	movs r1, 0
	movs r2, 0x44
	bl memset
	ldr r2, [r4]
	ldr r1, [r2, 0x10]
	movs r0, 0
	str r0, [r1]
	ldr r0, [r2, 0x14]
	movs r1, 0
	movs r2, 0x10
	bl memset
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080D7938
	movs r0, 0
	bl sub_80DCE58
_080D7938:
	movs r5, 0
	adds r2, r4, 0
	movs r6, 0xFF
	movs r3, 0
	ldr r4, =gUnknown_02039F26
_080D7942:
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	adds r1, r3, r1
	ldrb r0, [r1, 0x19]
	orrs r0, r6
	strb r0, [r1, 0x19]
	ldr r0, [r2]
	ldr r1, [r0]
	adds r1, 0x14
	adds r1, r5
	adds r0, r5, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080D7942
	bl sub_80DD590
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	movs r1, 0
	movs r2, 0x40
	bl memset
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D787C

	thumb_func_start sub_80D7988
sub_80D7988: @ 80D7988
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039F34
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x5C
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x70
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r0, 0x14
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x8]
	movs r0, 0x44
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x14]
	movs r0, 0x14
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x18]
	movs r0, 0x40
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x1C]
	movs r0, 0xC
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x20]
	movs r5, 0x80
	lsls r5, 5
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x24]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x28]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x2C]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x30]
	movs r5, 0x80
	lsls r5, 4
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x34]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x38]
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	ldr r2, [r4]
	str r0, [r2, 0x3C]
	ldr r1, =gUnknown_0202305C
	str r0, [r1]
	ldr r1, =gUnknown_02023060
	ldr r0, [r2, 0x28]
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7988

	thumb_func_start sub_80D7A5C
sub_80D7A5C: @ 80D7A5C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x4]
	ldr r0, [r0, 0x8]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x8]
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0xC]
	ldr r0, [r0, 0x10]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x10]
	ldr r0, [r0, 0x14]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x14]
	ldr r0, [r0, 0x18]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x18]
	ldr r0, [r0, 0x1C]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x1C]
	ldr r0, [r0, 0x20]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x20]
	ldr r0, [r0, 0x24]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x24]
	ldr r0, [r0, 0x28]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x28]
	ldr r0, [r0, 0x2C]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x2C]
	ldr r0, [r0, 0x30]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x30]
	ldr r0, [r0, 0x34]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x34]
	ldr r0, [r0, 0x38]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x38]
	ldr r0, [r0, 0x3C]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x3C]
	bl Free
	str r4, [r5]
	ldr r0, =gUnknown_0202305C
	str r4, [r0]
	ldr r0, =gUnknown_02023060
	str r4, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7A5C

	thumb_func_start sub_80D7B24
sub_80D7B24: @ 80D7B24
	push {r4-r6,lr}
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r6, r0, r1
	ldrb r5, [r6]
	cmp r5, 0x1
	beq _080D7BD4
	cmp r5, 0x1
	bgt _080D7B44
	cmp r5, 0
	beq _080D7B4E
	b _080D7C56
	.pool
_080D7B44:
	cmp r5, 0x2
	beq _080D7BDA
	cmp r5, 0x3
	beq _080D7C04
	b _080D7C56
_080D7B4E:
	ldr r0, =gUnknown_02039F38
	strb r5, [r0]
	bl sub_80D7988
	bl AllocateMonSpritesGfx
	ldr r4, =gMonSpritesGfxPtr
	ldr r0, [r4]
	ldr r0, [r0]
	bl Free
	ldr r0, [r4]
	str r5, [r0]
	movs r0, 0x80
	lsls r0, 7
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	bl sub_80D779C
	bl sub_80D77E4
	bl sub_80D7678
	bl dp12_8087EA4
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	bl ResetSpriteData
	bl ResetTasks
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, =0x02000000
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	strb r5, [r0]
	bl ClearBattleMonForms
	bl sub_80D787C
	b _080D7BF6
	.pool
_080D7BD4:
	movs r0, 0x2
	strb r0, [r6]
	b _080D7C56
_080D7BDA:
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	adds r0, 0x59
	bl sub_80D7E44
	lsls r0, 24
	cmp r0, 0
	beq _080D7C56
	ldr r0, [r4]
	ldr r0, [r0]
	adds r0, 0x59
	movs r1, 0
	strb r1, [r0]
_080D7BF6:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _080D7C56
	.pool
_080D7C04:
	bl sub_80DE224
	ldr r0, =gBattle_BG1_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	movs r0, 0x2
	bl BeginFastPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =vblank_cb_battle
	bl SetVBlankCallback
	ldr r0, =sub_80D7C7C
	movs r1, 0xA
	bl CreateTask
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	ldr r0, =sub_80D823C
	bl SetMainCallback2
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080D7C56
	bl sub_800E0E8
	movs r0, 0x8
	movs r1, 0x8
	bl sub_800DFB4
_080D7C56:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7B24

	thumb_func_start sub_80D7C7C
sub_80D7C7C: @ 80D7C7C
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080D7CA2
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0x8]
	ldr r0, =sub_80D7CB4
	str r0, [r1]
_080D7CA2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7C7C

	thumb_func_start sub_80D7CB4
sub_80D7CB4: @ 80D7CB4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D7D90
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080D7D3A
	ldr r2, =gTasks
	lsls r1, r5, 2
	adds r0, r1, r5
	lsls r0, 3
	adds r4, r0, r2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	adds r6, r1, 0
	cmp r0, 0x1
	beq _080D7D04
	cmp r0, 0x1
	bgt _080D7CF4
	cmp r0, 0
	beq _080D7CFA
	b _080D7D3A
	.pool
_080D7CF4:
	cmp r0, 0x2
	beq _080D7D28
	b _080D7D3A
_080D7CFA:
	bl sub_80DBF68
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080D7D04:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080D7D9E
	bl sub_800ADF8
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080D7D9E
	.pool
_080D7D28:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D7D9E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080D7D3A:
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080D7D9E
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080D7D62
	bl sub_80DBF68
_080D7D62:
	ldr r0, =sub_80D7DAC
	movs r1, 0
	bl CreateTask
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	ldr r1, =TaskDummy1
	str r1, [r0]
	b _080D7D9E
	.pool
_080D7D90:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D80C8
	str r0, [r1]
_080D7D9E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7CB4

	thumb_func_start sub_80D7DAC
sub_80D7DAC: @ 80D7DAC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FC998
	ldr r2, =sub_80D7DC8
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7DAC

	thumb_func_start sub_80D7DC8
sub_80D7DC8: @ 80D7DC8
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	ldr r0, =sub_80D7DE8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80D7DC8

	thumb_func_start sub_80D7DE8
sub_80D7DE8: @ 80D7DE8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	ldrh r1, [r0, 0x8]
	subs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	cmp r1, 0
	bgt _080D7E2A
	bl GetMultiplayerId
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldr r1, =sub_80D80C8
	str r1, [r0]
	ldr r1, =gRngValue
	ldr r0, =gUnknown_030060B8
	ldr r0, [r0]
	str r0, [r1]
_080D7E2A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D7DE8

	thumb_func_start sub_80D7E44
sub_80D7E44: @ 80D7E44
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	mov r10, r0
	ldrb r0, [r0]
	cmp r0, 0x6
	bls _080D7E5A
	b _080D80A4
_080D7E5A:
	lsls r0, 2
	ldr r1, =_080D7E68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D7E68:
	.4byte _080D7E84
	.4byte _080D7EC8
	.4byte _080D7ED8
	.4byte _080D7F28
	.4byte _080D7F40
	.4byte _080D7F7C
	.4byte _080D8004
_080D7E84:
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	movs r1, 0xC0
	lsls r1, 19
	movs r4, 0x80
	lsls r4, 8
	movs r0, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldr r1, =0x06008000
	movs r0, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldr r1, =0x06010000
	movs r0, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RequestDma3Fill
	b _080D80AE
	.pool
_080D7EC8:
	ldr r0, =gUnknown_08C17AB0
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	b _080D80AE
	.pool
_080D7ED8:
	ldr r0, =gUnknown_08C1850C
	ldr r4, =0x06002000
	adds r1, r4, 0
	bl LZDecompressVram
	ldr r3, =0x02018000
	movs r5, 0x80
	lsls r5, 6
	ldr r1, =0x040000d4
	ldr r6, =0x84000400
	movs r2, 0x80
	lsls r2, 5
	movs r7, 0x84
	lsls r7, 24
_080D7EF4:
	str r4, [r1]
	str r3, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r4, r2
	adds r3, r2
	subs r5, r2
	cmp r5, r2
	bhi _080D7EF4
	str r4, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r5, 2
	orrs r0, r7
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	b _080D80AE
	.pool
_080D7F28:
	ldr r1, =gUnknown_08C16FA8
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080D80AE
	.pool
_080D7F40:
	ldr r1, =gUnknown_08C17170
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x2C]
	ldr r2, =0x0201aa04
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x84000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	b _080D80AE
	.pool
_080D7F7C:
	ldr r0, =gUnknown_08C16E90
	movs r2, 0x80
	lsls r2, 2
	movs r1, 0
	bl LoadCompressedPalette
	ldr r5, =gPlttBufferUnfaded + 0x100
	ldr r6, =0x04000008
	adds r0, r5, 0
	mov r1, sp
	adds r2, r6, 0
	bl CpuSet
	ldr r0, =gUnknown_02039F25
	mov r9, r0
	ldrb r0, [r0]
	adds r0, 0x5
	lsls r0, 5
	ldr r1, =0xffffff00
	adds r1, r5
	mov r8, r1
	add r0, r8
	add r4, sp, 0x20
	adds r1, r4, 0
	adds r2, r6, 0
	bl CpuSet
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl CpuSet
	mov r2, r9
	ldrb r1, [r2]
	adds r1, 0x5
	lsls r1, 5
	add r1, r8
	mov r0, sp
	adds r2, r6, 0
	bl CpuSet
	ldr r1, =0x0201a004
	ldr r0, =0x040000d4
	mov r2, r8
	str r2, [r0]
	str r1, [r0, 0x4]
	ldr r1, =0x84000080
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	bl sub_80D782C
	b _080D80AE
	.pool
_080D8004:
	bl sub_80DD04C
	bl sub_80DBF90
	bl sub_80DB2BC
	bl sub_80DB120
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	movs r4, 0
	strb r0, [r1, 0x12]
	bl sub_80DC2BC
	bl sub_80DC4F0
	bl sub_80DC594
	bl sub_80DC5E8
	bl sub_80DC7EC
	ldr r1, =gBanksBySide
	strb r4, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r3, 0x3
	strb r3, [r1, 0x2]
	movs r2, 0x2
	strb r2, [r1, 0x3]
	ldr r0, =gBattleTypeFlags
	str r4, [r0]
	ldr r4, =gBankAttacker
	strb r2, [r4]
	ldr r0, =gBankTarget
	strb r3, [r0]
	bl sub_80DB0C4
	ldr r2, =gBankSpriteIds
	ldrb r1, [r4]
	adds r1, r2
	strb r0, [r1]
	bl sub_80DEA20
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	b _080D80AE
	.pool
_080D80A4:
	movs r0, 0
	mov r1, r10
	strb r0, [r1]
	movs r0, 0x1
	b _080D80B8
_080D80AE:
	mov r2, r10
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	movs r0, 0
_080D80B8:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D7E44

	thumb_func_start sub_80D80C8
sub_80D80C8: @ 80D80C8
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gPaletteFade
	ldrb r2, [r1, 0x8]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x8]
	ldrb r1, [r1, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080D80F8
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0x8]
	strh r2, [r1, 0xA]
	ldr r0, =sub_80D8108
	str r0, [r1]
_080D80F8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D80C8

	thumb_func_start sub_80D8108
sub_80D8108: @ 80D8108
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _080D8208
	lsls r0, 2
	ldr r1, =_080D8138
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D8138:
	.4byte _080D814C
	.4byte _080D8176
	.4byte _080D8194
	.4byte _080D81B0
	.4byte _080D8208
_080D814C:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0xA]
	adds r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _080D822C
	movs r0, 0
	strh r0, [r4, 0xA]
	movs r0, 0x61
	movs r1, 0
	bl PlaySE12WithPanning
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080D822C
_080D8176:
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	adds r0, 0x7
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA0
	ble _080D822C
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	b _080D81FA
	.pool
_080D8194:
	bl sub_80DE350
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080D822C
	.pool
_080D81B0:
	movs r0, 0x8
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	movs r0, 0xC
	bl GetGpuReg
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r3, sp
	ldrb r2, [r3]
	movs r1, 0x4
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	ldrb r0, [r4]
	ands r1, r0
	strb r1, [r4]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, 0x8
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0xC
	bl SetGpuReg
	bl sub_80DDB0C
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
_080D81FA:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080D822C
	.pool
_080D8208:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080D822C
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	ldr r1, =sub_80D833C
	str r1, [r0]
_080D822C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8108

	thumb_func_start sub_80D823C
sub_80D823C: @ 80D823C
	push {r4,r5,lr}
	bl AnimateSprites
	bl RunTasks
	bl BuildOamBuffer
	bl UpdatePaletteFade
	movs r4, 0
_080D8250:
	ldr r5, =gUnknown_02039F38
	ldrb r0, [r5]
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D8266
	lsls r0, r4, 24
	lsrs r0, 24
	bl CopyBgTilemapBufferToVram
_080D8266:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080D8250
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D823C

	thumb_func_start vblank_cb_battle
vblank_cb_battle: @ 80D827C
	push {lr}
	ldr r0, =gBattle_BG0_X
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, =gBattle_BG0_Y
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =gBattle_BG1_X
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gBattle_BG1_Y
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, =gBattle_BG2_X
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	ldr r0, =gBattle_BG2_Y
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, =gBattle_BG3_X
	ldrh r1, [r0]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, =gBattle_BG3_Y
	ldrh r1, [r0]
	movs r0, 0x1E
	bl SetGpuReg
	ldr r0, =gBattle_WIN0H
	ldrh r1, [r0]
	movs r0, 0x40
	bl SetGpuReg
	ldr r0, =gBattle_WIN0V
	ldrh r1, [r0]
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =gBattle_WIN1H
	ldrh r1, [r0]
	movs r0, 0x42
	bl SetGpuReg
	ldr r0, =gBattle_WIN1V
	ldrh r1, [r0]
	movs r0, 0x46
	bl SetGpuReg
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl sub_80BA0A8
	pop {r0}
	bx r0
	.pool
	thumb_func_end vblank_cb_battle

	thumb_func_start sub_80D833C
sub_80D833C: @ 80D833C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _080D840C
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	bl sub_80DCD48
	ldr r1, =gPlttBufferUnfaded
	ldr r2, =0x0201a204
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x84000100
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	ldrb r1, [r1, 0x1]
	adds r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	bne _080D83CC
	ldr r0, =gDisplayedStringBattle
	ldr r1, =gUnknown_0827D507
	bl StringCopy
	b _080D83D4
	.pool
_080D83CC:
	ldr r0, =gDisplayedStringBattle
	ldr r1, =gUnknown_0827D531
	bl StringCopy
_080D83D4:
	bl sub_80DB89C
	ldr r4, =gStringVar4
	ldr r1, =gDisplayedStringBattle
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080D841A
	.pool
_080D840C:
	bl sub_80DED4C
	cmp r0, 0
	bne _080D841A
	strh r0, [r4, 0x8]
	ldr r0, =sub_80D8424
	str r0, [r4]
_080D841A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D833C

	thumb_func_start sub_80D8424
sub_80D8424: @ 80D8424
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080D843C
	cmp r1, 0x2
	bne _080D8482
_080D843C:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	bne _080D8474
	movs r0, 0x1
	bl sub_80DC490
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D8490
	b _080D8480
	.pool
_080D8474:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D8894
_080D8480:
	str r0, [r1]
_080D8482:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8424

	thumb_func_start sub_80D8490
sub_80D8490: @ 80D8490
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gBattle_BG0_Y
	movs r1, 0xA0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	movs r6, 0
	ldr r0, =gUnknown_02039F25
	mov r8, r0
	ldr r2, =gUnknown_02039E1E
	mov r10, r2
	ldr r7, =gUnknown_02039F34
_080D84B8:
	lsls r1, r6, 1
	mov r0, r8
	ldrb r2, [r0]
	lsls r0, r2, 6
	adds r1, r0
	add r1, r10
	ldrh r4, [r1]
	add r5, sp, 0x4
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _080D853C
	adds r0, r2, 0
	bl sub_80DE1E8
	lsls r0, 24
	cmp r0, 0
	beq _080D853C
	ldr r0, [r7]
	mov r2, r8
	ldrb r1, [r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x8]
	adds r1, r4, 0
	bl AreMovesContestCombo
	lsls r0, 24
	cmp r0, 0
	beq _080D853C
	ldr r0, [r7]
	mov r2, r8
	ldrb r1, [r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080D853C
	add r0, sp, 0x4
	ldr r1, =gText_ColorLightShadowDarkGrey
	b _080D8566
	.pool
_080D853C:
	cmp r4, 0
	beq _080D856C
	ldr r0, [r7]
	mov r2, r8
	ldrb r1, [r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x8]
	cmp r0, r4
	bne _080D856C
	ldr r0, =gContestMoves
	lsls r1, r4, 3
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _080D856C
	add r0, sp, 0x4
	ldr r1, =gText_ColorBlue
_080D8566:
	bl StringCopy
	adds r5, r0, 0
_080D856C:
	movs r0, 0xD
	adds r1, r4, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCopy
	adds r4, r6, 0x5
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x7
	str r0, [sp]
	adds r0, r4, 0
	add r1, sp, 0x4
	movs r2, 0x5
	movs r3, 0x1
	bl sub_80DEBD0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _080D84B8
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80D880C
	ldr r2, =gUnknown_02039E00
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 1
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	bl prints_contest_move_description
	ldr r1, =gTasks
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80D8610
	str r1, [r0]
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8490

	thumb_func_start sub_80D8610
sub_80D8610: @ 80D8610
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	ldr r3, =gMain
	ldr r1, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, 0x1E
	adds r1, r0, r1
	movs r2, 0x3
_080D8628:
	ldrh r0, [r1]
	cmp r0, 0
	beq _080D8634
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080D8634:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080D8628
	ldrh r0, [r3, 0x2E]
	movs r5, 0x1
	ands r5, r0
	cmp r5, 0
	beq _080D8670
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D8894
	str r0, [r1]
	b _080D87FA
	.pool
_080D8670:
	ldrh r0, [r3, 0x30]
	cmp r0, 0x20
	bne _080D8678
	b _080D87FA
_080D8678:
	cmp r0, 0x20
	bgt _080D8682
	cmp r0, 0x2
	beq _080D868E
	b _080D87FA
_080D8682:
	cmp r0, 0x40
	beq _080D8730
	cmp r0, 0x80
	bne _080D868C
	b _080D879C
_080D868C:
	b _080D87FA
_080D868E:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_80DC490
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	ldrb r1, [r1, 0x1]
	adds r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	bne _080D86DC
	ldr r0, =gDisplayedStringBattle
	ldr r1, =gUnknown_0827D507
	bl StringCopy
	b _080D86E4
	.pool
_080D86DC:
	ldr r0, =gDisplayedStringBattle
	ldr r1, =gUnknown_0827D531
	bl StringCopy
_080D86E4:
	bl sub_80DB89C
	ldr r4, =gStringVar4
	ldr r1, =gDisplayedStringBattle
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	bl sub_80DEC30
	ldr r0, =gBattle_BG0_Y
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80D8424
	str r1, [r0]
	b _080D87FA
	.pool
_080D8730:
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80D883C
	ldr r0, [r4]
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, 0
	bne _080D8754
	subs r0, r6, 0x1
	b _080D8756
	.pool
_080D8754:
	subs r0, 0x1
_080D8756:
	strb r0, [r1]
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80D880C
	ldr r2, =gUnknown_02039E00
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 1
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	bl prints_contest_move_description
	cmp r6, 0x1
	bls _080D87FA
	movs r0, 0x5
	bl PlaySE
	b _080D87FA
	.pool
_080D879C:
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80D883C
	ldr r0, [r4]
	ldr r1, [r0]
	ldrb r2, [r1]
	subs r0, r6, 0x1
	cmp r2, r0
	bne _080D87C0
	strb r5, [r1]
	b _080D87C4
	.pool
_080D87C0:
	adds r0, r2, 0x1
	strb r0, [r1]
_080D87C4:
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80D880C
	ldr r2, =gUnknown_02039E00
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 1
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	bl prints_contest_move_description
	cmp r6, 0x1
	bls _080D87FA
	movs r0, 0x5
	bl PlaySE
_080D87FA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8610

	thumb_func_start sub_80D880C
sub_80D880C: @ 80D880C
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 25
	movs r0, 0xF8
	lsls r0, 21
	adds r3, r0
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0x37
	movs r2, 0
	bl sub_80DECB8
	add sp, 0x10
	pop {r0}
	bx r0
	thumb_func_end sub_80D880C

	thumb_func_start sub_80D883C
sub_80D883C: @ 80D883C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	asrs r4, 23
	adds r3, r4, 0
	adds r3, 0x1F
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	mov r8, r0
	str r0, [sp]
	movs r5, 0x1
	str r5, [sp, 0x4]
	movs r6, 0x11
	str r6, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r1, 0xB
	movs r2, 0
	bl sub_80DECB8
	adds r4, 0x20
	lsls r4, 24
	lsrs r4, 24
	mov r0, r8
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xB
	movs r2, 0
	adds r3, r4, 0
	bl sub_80DECB8
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D883C

	thumb_func_start sub_80D8894
sub_80D8894: @ 80D8894
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D890C
	ldr r4, =gUnknown_02039F25
	ldrb r0, [r4]
	bl sub_80DB8B8
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldrb r2, [r4]
	ldr r3, [r1, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r3
	strh r0, [r1, 0x6]
	ldr r4, =sub_80FC9F8
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sub_80D892C
	adds r1, r4, 0
	bl SetTaskFuncWithFollowupFunc
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =TaskDummy1
	str r1, [r0]
	bl sub_80DBF68
	movs r0, 0
	bl sub_80DC490
	b _080D891E
	.pool
_080D890C:
	bl sub_80DB918
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D895C
	str r0, [r1]
_080D891E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8894

	thumb_func_start sub_80D892C
sub_80D892C: @ 80D892C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldr r2, =gTasks
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_80D895C
	str r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D892C

	thumb_func_start sub_80D895C
sub_80D895C: @ 80D895C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	bl sub_80DB89C
	ldr r0, =gBattle_BG0_Y
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	movs r0, 0
	bl sub_80DC490
	movs r6, 0
	movs r5, 0xA0
	lsls r5, 19
_080D897C:
	lsrs r4, r5, 24
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x80
	lsls r0, 17
	adds r5, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _080D897C
	movs r0, 0
	bl sub_80DED60
	ldr r1, =gPlttBufferFaded
	ldr r0, =0x0201a604
	movs r2, 0x80
	lsls r2, 3
	ldr r4, =0x040000d4
	str r1, [r4]
	str r0, [r4, 0x4]
	lsrs r1, r2, 2
	movs r3, 0x84
	lsls r3, 24
	orrs r1, r3
	str r1, [r4, 0x8]
	ldr r1, [r4, 0x8]
	ldr r1, =0xfffffc00
	adds r0, r1
	movs r1, 0
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	ldr r1, =sub_80D8A04
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D895C

	thumb_func_start sub_80D8A04
sub_80D8A04: @ 80D8A04
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080D8A42
	movs r0, 0
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080D8A42
	bl sub_80DDBE8
	movs r0, 0x1
	bl sub_80DE69C
	ldr r0, =sub_80D8A50
	str r0, [r4]
_080D8A42:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8A04

	thumb_func_start sub_80D8A50
sub_80D8A50: @ 80D8A50
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r1, [r0, 0x6]
	movs r0, 0x90
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _080D8A76
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D8A88
	str r0, [r1]
_080D8A76:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8A50

	thumb_func_start sub_80D8A88
sub_80D8A88: @ 80D8A88
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gTasks
	lsls r3, r6, 2
	adds r1, r3, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080D8B18
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldr r1, [r0]
	ldr r0, =gRngValue
	ldr r0, [r0]
	str r0, [r1, 0x18]
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r7, r3, 0
	cmp r0, 0
	beq _080D8B08
	bl sub_80DA8A4
	lsls r0, 24
	cmp r0, 0
	beq _080D8B08
	movs r4, 0
	ldr r1, =gUnknown_02039F30
	ldrb r0, [r1]
	cmp r0, 0x3
	bgt _080D8B08
	adds r5, r1, 0
_080D8ADE:
	ldrb r0, [r5]
	adds r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_80DB8B8
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldrb r2, [r5]
	adds r2, r4
	ldr r3, [r1, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r3
	strh r0, [r1, 0x6]
	adds r4, 0x1
	ldrb r0, [r5]
	adds r0, r4, r0
	cmp r0, 0x3
	ble _080D8ADE
_080D8B08:
	ldr r1, =gTasks
	adds r0, r7, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	ldr r1, =sub_80D8B38
	str r1, [r0]
_080D8B18:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D8A88

	thumb_func_start sub_80D8B38
sub_80D8B38: @ 80D8B38
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r0, [r0]
	ldrb r6, [r0, 0x11]
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	mov r9, r2
	adds r4, r1, 0
	cmp r0, 0x3B
	bls _080D8B6E
	bl _080DA100
_080D8B6E:
	lsls r0, 2
	ldr r1, =_080D8B84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D8B84:
	.4byte _080D8C74
	.4byte _080D8D30
	.4byte _080D8D56
	.4byte _080D8DC4
	.4byte _080D8E7C
	.4byte _080D8EC8
	.4byte _080D8F84
	.4byte _080D8FB8
	.4byte _080D9010
	.4byte _080D908C
	.4byte _080D9FC0
	.4byte _080D9FEC
	.4byte _080D9238
	.4byte _080D926C
	.4byte _080D9774
	.4byte _080D9864
	.4byte _080D98D4
	.4byte _080D9904
	.4byte _080D99EC
	.4byte _080D999E
	.4byte _080DA024
	.4byte _080DA0A0
	.4byte _080DA0C2
	.4byte _080D90B4
	.4byte _080D9180
	.4byte _080D9388
	.4byte _080D939E
	.4byte _080D947C
	.4byte _080D94A0
	.4byte _080D9508
	.4byte _080D95EC
	.4byte _080DA038
	.4byte _080DA080
	.4byte _080D9EBC
	.4byte _080D9F48
	.4byte _080D929A
	.4byte _080D92D0
	.4byte _080D92F6
	.4byte _080D9334
	.4byte _080D955C
	.4byte _080D95C4
	.4byte _080D9A2C
	.4byte _080DA100
	.4byte _080D9DAC
	.4byte _080DA100
	.4byte _080D9830
	.4byte _080D997C
	.4byte _080D921A
	.4byte _080D91A4
	.4byte _080D91F4
	.4byte _080D935C
	.4byte _080D9690
	.4byte _080D971C
	.4byte _080D9BAA
	.4byte _080D9C68
	.4byte _080D9F68
	.4byte _080D9F84
	.4byte _080D9DD4
	.4byte _080D9E60
	.4byte _080D9EA0
_080D8C74:
	bl sub_80DCD48
	movs r7, 0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r1, 0x10]
	mov r5, r8
	lsls r5, 2
	mov r10, r5
	ldrb r2, [r0]
	cmp r1, r2
	beq _080D8C9C
	adds r2, r0, 0
_080D8C92:
	adds r7, 0x1
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r1, r0
	bne _080D8C92
_080D8C9C:
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	strb r7, [r0, 0x11]
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r6, [r2, 0x11]
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080D8D14
	ldrb r0, [r2, 0x7]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x7]
	bl sub_80DA8A4
	lsls r0, 24
	cmp r0, 0
	beq _080D8CD4
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0, 0x11]
	bl sub_80DD080
_080D8CD4:
	ldr r4, =sub_80FCC88
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sub_80DA110
	adds r1, r4, 0
	bl SetTaskFuncWithFollowupFunc
	bl sub_80DBF68
	ldr r1, =gTasks
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	bl _080DA100
	.pool
_080D8D14:
	adds r0, r6, 0
	bl sub_80DD080
	ldr r0, =gTasks
	mov r1, r10
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D8D30:
	mov r3, r9
	ldr r0, [r3]
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080D8D44
	bl _080DA100
_080D8D44:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x8]
	bl _080DA100
_080D8D56:
	adds r0, r6, 0
	bl sub_80DF080
	bl sub_80DF750
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0xC]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	bne _080D8D86
	ldrb r1, [r2, 0xB]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _080D8DA4
_080D8D86:
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1F
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D8DA4:
	bl sub_80DB89C
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	strh r6, [r1, 0x1C]
	movs r0, 0x3
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D8DC4:
	mov r4, r8
	lsls r4, 2
	mov r10, r4
	ldr r1, =gBattleMonForms
	movs r2, 0
	adds r0, r1, 0x3
_080D8DD0:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080D8DD0
	movs r7, 0x4
	mov r5, r9
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	movs r1, 0
	movs r2, 0x14
	bl memset
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x11]
	bl sub_80DE9DC
	ldr r4, =gUnknown_02039E00
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r3, [r0, 0x11]
	lsls r2, r3, 6
	adds r0, r2, r4
	ldrh r0, [r0]
	adds r1, r4, 0
	adds r1, 0x3C
	adds r1, r2, r1
	ldr r1, [r1]
	adds r4, 0x38
	adds r2, r4
	ldr r2, [r2]
	bl sub_80DB174
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r3, r0, r2
	movs r1, 0x78
	strh r1, [r3, 0x24]
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_80DA134
	str r1, [r0]
	ldr r0, =gTasks
	mov r4, r10
	add r4, r8
	lsls r4, 3
	adds r4, r0
	strh r5, [r4, 0xC]
	ldr r1, =gBankSpriteIds
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	strb r5, [r0]
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	ldrb r0, [r0, 0x11]
	bl sub_80DC9EC
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80DCBE8
	strh r7, [r4, 0x8]
	bl _080DA100
	.pool
_080D8E7C:
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r2, r0, r4
	ldrb r5, [r2, 0xC]
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _080D8EA0
	bl _080DA100
_080D8EA0:
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r0, 0x14]
	lsls r0, r6, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080D8EB8
	bl _080DA100
_080D8EB8:
	movs r0, 0x5
	strh r0, [r2, 0x8]
	bl _080DA100
	.pool
_080D8EC8:
	mov r5, r9
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r5, r0, 2
	adds r1, r5, r1
	ldrb r1, [r1, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D8EF2
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x21
	strh r1, [r0, 0x8]
	bl _080DA100
_080D8EF2:
	bl sub_80DB89C
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	mov r2, r9
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	adds r3, r5, r0
	ldrh r1, [r3, 0x6]
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bhi _080D8F38
	ldr r0, =gStringVar2
	adds r2, r1, 0
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	b _080D8F48
	.pool
_080D8F38:
	ldr r0, =gStringVar2
	ldr r2, =gUnknown_08587F1C
	ldrb r1, [r3, 0xA]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
_080D8F48:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827D55A
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x6
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D8F84:
	bl sub_80DED4C
	adds r1, r0, 0
	cmp r1, 0
	beq _080D8F92
	bl _080DA100
_080D8F92:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x5A
	strb r1, [r0]
	ldr r1, =gTasks
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x7
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D8FB8:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r1]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	bl sub_80DE834
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x11]
	bl sub_80DE864
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x11]
	bl sub_80DE9DC
	adds r0, r4, 0
	bl sub_80DEAA8
	adds r0, r4, 0
	bl move_anim_start_t1
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D9010:
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r4, [r0]
	cmp r4, 0
	beq _080D9024
	bl _080DA100
_080D9024:
	adds r0, r6, 0
	bl sub_80DE9B0
	ldr r0, =gUnknown_02039F34
	ldr r1, [r0]
	ldr r0, [r1]
	adds r0, 0x5A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D9060
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	strh r4, [r1, 0x1C]
	movs r0, 0x9
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D9060:
	ldr r1, [r1, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080D907A
	adds r0, r6, 0
	bl sub_80DC674
_080D907A:
	bl sub_80DE12C
	ldr r0, =gTasks
	mov r4, r8
	lsls r1, r4, 2
	b _080D9192
	.pool
_080D908C:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r2, r0, r4
	ldrh r0, [r2, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r2, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	bgt _080D90A8
	bl _080DA100
_080D90A8:
	movs r0, 0
	strh r0, [r2, 0x1C]
	movs r0, 0x7
	strh r0, [r2, 0x8]
	bl _080DA100
_080D90B4:
	mov r0, r8
	lsls r2, r0, 2
	adds r0, r2, r0
	lsls r0, 3
	adds r7, r0, r4
	movs r0, 0
	strh r0, [r7, 0xA]
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	mov r12, r0
	lsls r1, r6, 3
	subs r0, r1, r6
	lsls r5, r0, 2
	mov r0, r12
	adds r3, r5, r0
	ldrb r0, [r3, 0x13]
	mov r10, r2
	str r1, [sp, 0x4]
	cmp r0, 0xFF
	beq _080D90FA
	ldrb r1, [r3, 0x13]
	adds r0, r6, 0
	bl sub_80DD45C
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r5, r0
	movs r1, 0xFF
	strb r1, [r0, 0x13]
	movs r0, 0x18
	strh r0, [r7, 0x8]
	bl _080DA100
_080D90FA:
	ldrb r0, [r3, 0x14]
	cmp r0, 0xFF
	beq _080D9178
	movs r7, 0
	cmp r7, r6
	beq _080D910E
	mov r2, r12
	ldrb r0, [r2, 0x13]
	cmp r0, 0xFF
	bne _080D912C
_080D910E:
	adds r7, 0x1
	cmp r7, 0x3
	bgt _080D912C
	cmp r7, r6
	beq _080D910E
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x13]
	cmp r0, 0xFF
	beq _080D910E
_080D912C:
	cmp r7, 0x4
	bne _080D9168
	mov r4, r9
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	ldr r5, [sp, 0x4]
	subs r4, r5, r6
	lsls r4, 2
	adds r0, r4, r0
	ldrb r1, [r0, 0x14]
	adds r0, r6, 0
	bl sub_80DD45C
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r0
	movs r0, 0xFF
	strb r0, [r4, 0x14]
	ldr r1, =gTasks
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x18
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D9168:
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x30
	strh r1, [r0, 0x8]
	bl _080DA100
_080D9178:
	movs r0, 0x30
	strh r0, [r7, 0x8]
	bl _080DA100
_080D9180:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D918C
	bl _080DA100
_080D918C:
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
_080D9192:
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x17
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D91A4:
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x11]
	movs r3, 0x3
	ands r3, r0
	cmp r3, 0x1
	bne _080D91C4
	movs r0, 0x5
	bl sub_80DD720
	b _080D91DA
_080D91C4:
	cmp r3, 0x2
	bne _080D91D0
	movs r0, 0x6
	bl sub_80DD720
	b _080D91DA
_080D91D0:
	cmp r3, 0x3
	bne _080D9208
	movs r0, 0x7
	bl sub_80DD720
_080D91DA:
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x31
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D91F4:
	mov r3, r9
	ldr r0, [r3]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080D9208
	bl _080DA100
_080D9208:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2F
	strh r1, [r0, 0x8]
	bl _080DA100
_080D921A:
	movs r0, 0x1
	bl sub_80DE008
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0xC
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D9238:
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	movs r0, 0
	adds r2, r6, 0
	bl sub_80DC028
	ldr r1, =gTasks
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0xD
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D926C:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r1]
	ldrb r0, [r0, 0x11]
	ldr r1, [r1, 0x14]
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080D9288
	bl _080DA100
_080D9288:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x23
	strh r1, [r0, 0x8]
	bl _080DA100
_080D929A:
	mov r2, r9
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x10]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0x10
	bne _080D92B8
	movs r0, 0x8
	bl sub_80DD720
_080D92B8:
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x24
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D92D0:
	mov r5, r9
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080D92E4
	bl _080DA100
_080D92E4:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x25
	strh r1, [r0, 0x8]
	bl _080DA100
_080D92F6:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80DB5B8
	lsls r0, 24
	cmp r0, 0
	beq _080D9320
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	movs r1, 0x26
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D9320:
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	b _080D9354
	.pool
_080D9334:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r4
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bgt _080D9350
	bl _080DA100
_080D9350:
	movs r0, 0
	strh r0, [r1, 0x1C]
_080D9354:
	movs r0, 0x32
	strh r0, [r1, 0x8]
	bl _080DA100
_080D935C:
	adds r0, r6, 0
	bl sub_80DB798
	lsls r0, 24
	cmp r0, 0
	beq _080D936E
	movs r0, 0x63
	bl PlaySE
_080D936E:
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x19
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D9388:
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0
	strh r1, [r0, 0xA]
	movs r1, 0x1A
	strh r1, [r0, 0x8]
	bl _080DA100
_080D939E:
	movs r3, 0
	movs r5, 0
	str r5, [sp]
	mov r0, r8
	lsls r1, r0, 2
	adds r0, r1, r0
	lsls r0, 3
	adds r0, r4
	movs r2, 0xA
	ldrsh r7, [r0, r2]
	mov r10, r1
	cmp r7, 0x3
	bgt _080D9418
	ldr r5, =gUnknown_02039F26
	ldr r2, =gUnknown_02039F34
_080D93BC:
	movs r3, 0
	str r3, [sp]
	adds r0, r3, 0
	cmp r0, r6
	beq _080D93E4
	ldrb r0, [r5]
	cmp r0, r7
	bne _080D93E4
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	ldrb r0, [r0, 0x13]
	cmp r0, 0xFF
	beq _080D93E4
	movs r1, 0x1
	str r1, [sp]
	b _080D940C
	.pool
_080D93E4:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _080D940C
	cmp r3, r6
	beq _080D93E4
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, r7
	bne _080D93E4
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x13]
	cmp r0, 0xFF
	beq _080D93E4
	movs r0, 0x1
	str r0, [sp]
_080D940C:
	ldr r1, [sp]
	cmp r1, 0
	bne _080D9422
	adds r7, 0x1
	cmp r7, 0x3
	ble _080D93BC
_080D9418:
	ldr r2, [sp]
	lsls r0, r2, 24
	asrs r2, r0, 24
	cmp r2, 0
	beq _080D9464
_080D9422:
	mov r5, r10
	add r5, r8
	lsls r5, 3
	adds r5, r4
	ldr r0, =gUnknown_02039F26
	adds r0, r3, r0
	ldrb r0, [r0]
	strh r0, [r5, 0xA]
	lsls r0, r3, 24
	lsrs r0, 24
	mov r4, r9
	ldr r1, [r4]
	ldr r1, [r1, 0x4]
	lsls r4, r3, 3
	subs r4, r3
	lsls r4, 2
	adds r1, r4, r1
	ldrb r1, [r1, 0x13]
	bl sub_80DD45C
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r0
	movs r0, 0xFF
	strb r0, [r4, 0x13]
	movs r0, 0x1B
	strh r0, [r5, 0x8]
	bl _080DA100
	.pool
_080D9464:
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r4
	strh r2, [r0, 0xA]
	strh r2, [r0, 0x1C]
	movs r1, 0x33
	strh r1, [r0, 0x8]
	bl sub_80DB884
	bl _080DA100
_080D947C:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9488
	bl _080DA100
_080D9488:
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1C
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D94A0:
	movs r7, 0
	mov r3, r8
	lsls r0, r3, 2
	adds r1, r0, r3
	lsls r1, 3
	adds r1, r4
	movs r4, 0xA
	ldrsh r2, [r1, r4]
	ldr r1, =gUnknown_02039F26
	mov r10, r0
	adds r5, r1, 0
	ldrb r0, [r5]
	cmp r2, r0
	beq _080D94CA
	adds r1, r2, 0
	adds r2, r5, 0
_080D94C0:
	adds r7, 0x1
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r1, r0
	bne _080D94C0
_080D94CA:
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0xE]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	negs r1, r1
	lsls r2, r7, 24
	lsrs r2, 24
	bl sub_80DC028
	ldr r1, =gTasks
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1D
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D9508:
	movs r7, 0
	mov r2, r8
	lsls r0, r2, 2
	adds r1, r0, r2
	lsls r1, 3
	adds r1, r4
	movs r5, 0xA
	ldrsh r3, [r1, r5]
	ldr r1, =gUnknown_02039F26
	mov r10, r0
	adds r5, r1, 0
	ldrb r0, [r5]
	cmp r3, r0
	beq _080D952E
_080D9524:
	adds r7, 0x1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r3, r0
	bne _080D9524
_080D952E:
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x14]
	lsls r0, r7, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080D9546
	bl _080DA100
_080D9546:
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x27
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D955C:
	movs r7, 0
	mov r2, r8
	lsls r0, r2, 2
	adds r1, r0, r2
	lsls r1, 3
	adds r1, r4
	movs r3, 0xA
	ldrsh r2, [r1, r3]
	ldr r1, =gUnknown_02039F26
	mov r10, r0
	adds r5, r1, 0
	ldrb r4, [r5]
	cmp r2, r4
	beq _080D9586
	adds r1, r2, 0
	adds r2, r5, 0
_080D957C:
	adds r7, 0x1
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r1, r0
	bne _080D957C
_080D9586:
	lsls r0, r7, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_80DB5B8
	lsls r0, 24
	cmp r0, 0
	beq _080D95B4
	ldr r1, =gTasks
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	movs r1, 0x28
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D95B4:
	ldr r0, =gTasks
	mov r1, r10
	add r1, r8
	lsls r1, 3
	adds r1, r0
	b _080D95E4
	.pool
_080D95C4:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r4
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bgt _080D95E0
	bl _080DA100
_080D95E0:
	movs r0, 0
	strh r0, [r1, 0x1C]
_080D95E4:
	movs r0, 0x1E
	strh r0, [r1, 0x8]
	bl _080DA100
_080D95EC:
	movs r7, 0
	ldr r2, =gUnknown_02039F26
	ldrb r3, [r2]
	mov r0, r8
	lsls r1, r0, 2
	adds r0, r1, r0
	lsls r0, 3
	adds r4, r0, r4
	movs r5, 0xA
	ldrsh r0, [r4, r5]
	mov r10, r1
	adds r5, r2, 0
	cmp r3, r0
	beq _080D961E
	adds r3, r5, 0
	adds r2, r4, 0
_080D960C:
	adds r7, 0x1
	cmp r7, 0x3
	bgt _080D961E
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r4, 0xA
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bne _080D960C
_080D961E:
	lsls r4, r7, 24
	lsrs r0, r4, 24
	bl sub_80DB798
	lsls r0, 24
	adds r6, r4, 0
	cmp r0, 0
	beq _080D963C
	movs r0, 0x63
	bl PlaySE
	b _080D9642
	.pool
_080D963C:
	movs r0, 0x64
	bl PlaySE
_080D9642:
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r4, r0, 2
	adds r1, r4, r1
	ldrb r1, [r1, 0x15]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080D9670
	lsrs r0, r6, 24
	bl sub_80DC674
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
_080D9670:
	ldr r0, =gTasks
	mov r1, r10
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	movs r0, 0x1A
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D9690:
	mov r5, r8
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r4, r0, r4
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	mov r10, r2
	cmp r0, 0x9
	bgt _080D96AE
	bl _080DA100
_080D96AE:
	movs r0, 0
	strh r0, [r4, 0x1C]
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0xC]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	bne _080D96D4
	ldrb r1, [r2, 0x11]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080D96F6
_080D96D4:
	bl sub_80DB89C
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827E793
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
_080D96F6:
	ldr r0, =gTasks
	mov r1, r10
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x34
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D971C:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9728
	bl _080DA100
_080D9728:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080D975C
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x11
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D975C:
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0xE
	strh r0, [r1, 0x8]
	bl _080DA100
	.pool
_080D9774:
	mov r4, r9
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
	lsls r4, r0, 24
	lsrs r5, r4, 24
	cmp r5, 0
	beq _080D97DC
	bl sub_80DB89C
	asrs r0, r4, 24
	cmp r0, 0x1
	bne _080D97A0
	ldr r0, =gUnknown_0827E32E
	b _080D97A6
	.pool
_080D97A0:
	cmp r0, 0x2
	bne _080D97B4
	ldr r0, =gUnknown_0827E35B
_080D97A6:
	movs r1, 0x1
	bl sub_80DEC30
	b _080D97BC
	.pool
_080D97B4:
	ldr r0, =gUnknown_0827E38D
	movs r1, 0x1
	bl sub_80DEC30
_080D97BC:
	movs r0, 0x3
	bl sub_80DD720
	ldr r1, =gTasks
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	b _080D9812
	.pool
_080D97DC:
	bl sub_80DB89C
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827E2FE
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	movs r0, 0x2
	bl sub_80DD720
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x1C]
_080D9812:
	movs r1, 0x2D
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D9830:
	mov r3, r9
	ldr r0, [r3]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080D9844
	bl _080DA100
_080D9844:
	ldrb r0, [r2, 0x11]
	bl sub_80DC9B4
	ldr r1, =gTasks
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0xF
	strh r1, [r0, 0x8]
	bl _080DA100
	.pool
_080D9864:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9870
	bl _080DA100
_080D9870:
	ldr r1, =gTasks
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x32
	bgt _080D988E
	bl _080DA100
_080D988E:
	ldr r7, =gUnknown_02039F34
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r5, r0, 2
	adds r2, r5, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x10
	mov r8, r0
	ands r0, r1
	cmp r0, 0
	bne _080D98C2
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	ldrb r1, [r2, 0x17]
	adds r2, r6, 0
	bl sub_80DC028
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrh r0, [r1, 0x2]
	ldrb r2, [r1, 0x17]
	adds r0, r2
	strh r0, [r1, 0x2]
_080D98C2:
	mov r3, r8
	strh r3, [r4, 0x8]
	bl _080DA100
	.pool
_080D98D4:
	mov r5, r9
	ldr r0, [r5]
	ldr r1, [r0, 0x14]
	lsls r0, r6, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080D98F0
	bl _080DA100
_080D98F0:
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	strh r1, [r0, 0x1C]
	movs r1, 0x11
	strh r1, [r0, 0x8]
	bl _080DA100
_080D9904:
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D996C
	bl sub_80DB89C
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827E6E3
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r0, =gTasks
	mov r5, r8
	lsls r4, r5, 2
	add r4, r8
	lsls r4, 3
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x1C]
	bl sub_80DD720
	movs r0, 0x2E
	strh r0, [r4, 0x8]
	b _080DA100
	.pool
_080D996C:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x29
	strh r1, [r0, 0x8]
	b _080DA100
_080D997C:
	mov r2, r9
	ldr r0, [r2]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080D998E
	b _080DA100
_080D998E:
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x13
	strh r1, [r0, 0x8]
	b _080DA100
_080D999E:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D99A8
	b _080DA100
_080D99A8:
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r4, r6, 3
	subs r4, r6
	lsls r4, 2
	adds r1, r4, r1
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	ldrb r1, [r1, 0x18]
	negs r1, r1
	adds r2, r6, 0
	bl sub_80DC028
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r4, r0
	ldrb r1, [r4, 0x18]
	ldrh r0, [r4, 0x2]
	subs r0, r1
	strh r0, [r4, 0x2]
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x12
	strh r1, [r0, 0x8]
	b _080DA100
	.pool
_080D99EC:
	bl sub_80DCD48
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	lsls r0, r6, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080D9A0A
	b _080DA100
_080D9A0A:
	ldr r0, =gTasks
	mov r5, r8
	lsls r4, r5, 2
	add r4, r8
	lsls r4, 3
	adds r4, r0
	strh r3, [r4, 0x1C]
	bl sub_80DB89C
	movs r0, 0x29
	strh r0, [r4, 0x8]
	b _080DA100
	.pool
_080D9A2C:
	mov r1, r9
	ldr r0, [r1]
	ldr r2, [r0, 0x10]
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D9A56
	ldr r0, [r2]
	lsls r0, 20
	lsrs r0, 29
	cmp r6, r0
	beq _080D9A56
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0x39
	strh r1, [r0, 0x8]
	b _080DA100
_080D9A56:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r1, 0x10]
	ldrb r0, [r0]
	str r0, [sp]
	ldr r1, [r1, 0x4]
	lsls r2, r6, 3
	subs r0, r2, r6
	lsls r0, 2
	adds r5, r0, r1
	ldrb r1, [r5, 0x11]
	movs r0, 0x10
	ands r0, r1
	str r2, [sp, 0x4]
	cmp r0, 0
	beq _080D9A94
	movs r4, 0x1
	str r4, [sp]
	ldr r0, =gStringVar3
	ldrh r2, [r5, 0x6]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	b _080D9AAE
	.pool
_080D9A94:
	ldr r0, =gStringVar3
	ldr r3, =gUnknown_08587F08
	ldr r2, =gContestMoves
	ldrh r1, [r5, 0x6]
	lsls r1, 3
	adds r1, r2
	ldrb r1, [r1, 0x1]
	lsls r1, 29
	lsrs r1, 27
	adds r1, r3
	ldr r1, [r1]
	bl StringCopy
_080D9AAE:
	ldr r5, [sp]
	lsls r0, r5, 24
	cmp r0, 0
	ble _080D9AD2
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldr r2, [sp, 0x4]
	subs r0, r2, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D9AD2
	movs r3, 0
	str r3, [sp]
_080D9AD2:
	bl sub_80DB89C
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r1, [r0]
	ldrb r0, [r1, 0x13]
	ldr r5, [sp]
	lsls r2, r5, 24
	asrs r3, r2, 24
	adds r0, r3, r0
	strb r0, [r1, 0x13]
	ldr r0, [r4]
	ldr r1, [r0]
	movs r0, 0x13
	ldrsb r0, [r1, r0]
	adds r5, r2, 0
	cmp r0, 0
	bge _080D9B06
	movs r0, 0
	strb r0, [r1, 0x13]
_080D9B06:
	cmp r3, 0
	bne _080D9B30
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	b _080D9F58
	.pool
_080D9B30:
	cmp r3, 0
	bge _080D9B48
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0827E73C
	bl StringExpandPlaceholders
	b _080D9B74
	.pool
_080D9B48:
	cmp r3, 0
	ble _080D9B6C
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bgt _080D9B6C
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0827E717
	bl StringExpandPlaceholders
	b _080D9B74
	.pool
_080D9B6C:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0827E76A
	bl StringExpandPlaceholders
_080D9B74:
	ldr r0, =gStringVar4
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r1
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	cmp r5, 0
	bge _080D9BA4
	movs r0, 0x35
	strh r0, [r1, 0x8]
	b _080DA100
	.pool
_080D9BA4:
	movs r0, 0x36
	strh r0, [r1, 0x8]
	b _080DA100
_080D9BAA:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r4
	movs r0, 0x1C
	ldrsh r3, [r4, r0]
	cmp r3, 0x1
	beq _080D9BE8
	cmp r3, 0x1
	bgt _080D9BC6
	cmp r3, 0
	beq _080D9BD0
	b _080DA100
_080D9BC6:
	cmp r3, 0x2
	beq _080D9C0C
	cmp r3, 0x3
	beq _080D9C46
	b _080DA100
_080D9BD0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x1
	bl sub_80DDED0
	ldr r0, =0x00000187
	bl PlayFanfare
	b _080D9C3E
	.pool
_080D9BE8:
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	ands r3, r0
	cmp r3, 0
	beq _080D9BF8
	b _080DA100
_080D9BF8:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9C02
	b _080DA100
_080D9C02:
	movs r0, 0x1
	negs r0, r0
	bl sub_80DDCDC
	b _080D9C3E
_080D9C0C:
	mov r2, r9
	ldr r0, [r2]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x20
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _080D9C22
	b _080DA100
_080D9C22:
	ldrh r0, [r4, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	bgt _080D9C32
	b _080DA100
_080D9C32:
	strh r2, [r4, 0x1E]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	bl sub_80DDED0
_080D9C3E:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	b _080DA100
_080D9C46:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080D9C58
	b _080DA100
_080D9C58:
	strh r0, [r4, 0x1C]
	strh r0, [r4, 0x1E]
	movs r0, 0x2B
	strh r0, [r4, 0x8]
	b _080DA100
	.pool
_080D9C68:
	mov r3, r8
	lsls r1, r3, 2
	adds r0, r1, r3
	lsls r0, 3
	adds r0, r4
	movs r5, 0x1C
	ldrsh r0, [r0, r5]
	mov r10, r1
	cmp r0, 0x4
	bls _080D9C7E
	b _080DA100
_080D9C7E:
	lsls r0, 2
	ldr r1, =_080D9C8C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D9C8C:
	.4byte _080D9CA0
	.4byte _080D9CB0
	.4byte _080D9CD4
	.4byte _080D9D3E
	.4byte _080D9D84
_080D9CA0:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9CAA
	b _080DA100
_080D9CAA:
	movs r0, 0x1
	movs r1, 0x1
	b _080D9D68
_080D9CB0:
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080D9CC2
	b _080DA100
_080D9CC2:
	bl sub_80DDE0C
	movs r0, 0xDF
	bl PlaySE
	movs r0, 0x1
	bl sub_80DDCDC
	b _080D9D6C
_080D9CD4:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r2]
	ldrb r1, [r0, 0x6]
	movs r0, 0x20
	ands r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080D9CEA
	b _080DA100
_080D9CEA:
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r5, r0, r4
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	bgt _080D9D02
	b _080DA100
_080D9D02:
	strh r3, [r5, 0x1E]
	ldr r0, [r2, 0x4]
	lsls r4, r6, 3
	subs r4, r6
	lsls r4, 2
	adds r0, r4, r0
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [r2, 0x10]
	ldrb r1, [r1, 0x2]
	lsls r1, 24
	asrs r1, 24
	adds r2, r6, 0
	bl sub_80DC028
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r1, 0x4]
	adds r4, r0
	ldr r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	ldrh r3, [r4, 0x2]
	adds r0, r3
	strh r0, [r4, 0x2]
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	b _080DA100
_080D9D3E:
	mov r4, r9
	ldr r2, [r4]
	ldr r1, [r2, 0x14]
	lsls r0, r6, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080D9D54
	b _080DA100
_080D9D54:
	ldr r0, [r2]
	ldrb r1, [r0, 0x6]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080D9D62
	b _080DA100
_080D9D62:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0x1
_080D9D68:
	bl sub_80DDED0
_080D9D6C:
	ldr r0, =gTasks
	mov r1, r10
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	b _080DA100
	.pool
_080D9D84:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080D9D96
	b _080DA100
_080D9D96:
	mov r0, r10
	add r0, r8
	lsls r0, 3
	adds r0, r4
	strh r3, [r0, 0x1C]
	strh r3, [r0, 0x1E]
	movs r1, 0x2B
	strh r1, [r0, 0x8]
	b _080DA100
	.pool
_080D9DAC:
	mov r5, r9
	ldr r0, [r5]
	ldr r1, [r0, 0x14]
	lsls r0, r6, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080D9DC2
	b _080DA100
_080D9DC2:
	bl sub_80DB89C
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	b _080D9F58
	.pool
_080D9DD4:
	bl sub_80DB89C
	ldr r0, =gStringVar3
	ldr r5, =gUnknown_02039F34
	ldr r1, [r5]
	ldr r1, [r1, 0x10]
	ldr r1, [r1]
	lsls r1, 20
	lsrs r1, 29
	lsls r1, 6
	ldr r4, =gUnknown_02039E02
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	lsls r1, r6, 3
	subs r1, r6
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x6]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827E7EA
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x3A
	strh r1, [r0, 0x8]
	b _080DA100
	.pool
_080D9E60:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9E6A
	b _080DA100
_080D9E6A:
	bl sub_80DB89C
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827E817
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x3B
	strh r1, [r0, 0x8]
	b _080DA100
	.pool
_080D9EA0:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9EAA
	b _080DA100
_080D9EAA:
	bl sub_80DB89C
	ldr r0, =gTasks
	mov r5, r8
	lsls r1, r5, 2
	b _080D9F58
	.pool
_080D9EBC:
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r4, r0, 2
	adds r2, r4, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080D9EDC
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
_080D9EDC:
	adds r0, r6, 0
	bl sub_80DC9B4
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	mov r2, r9
	ldr r1, [r2]
	ldr r1, [r1, 0x4]
	adds r1, r4, r1
	ldrh r2, [r1, 0x6]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827E58A
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x22
	strh r1, [r0, 0x8]
	b _080DA100
	.pool
_080D9F48:
	bl sub_80DED4C
	cmp r0, 0
	beq _080D9F52
	b _080DA100
_080D9F52:
	ldr r0, =gTasks
	mov r4, r8
	lsls r1, r4, 2
_080D9F58:
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x37
	strh r0, [r1, 0x8]
	b _080DA100
	.pool
_080D9F68:
	bl sub_80DDBE8
	ldr r0, =gTasks
	mov r5, r8
	lsls r1, r5, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x38
	strh r0, [r1, 0x8]
	b _080DA100
	.pool
_080D9F84:
	mov r1, r9
	ldr r0, [r1]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080D9F9A
	b _080DA100
_080D9F9A:
	movs r0, 0x13
	ldrsb r0, [r2, r0]
	cmp r0, 0x4
	ble _080D9FA8
	strb r1, [r2, 0x13]
	bl sub_80DD940
_080D9FA8:
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0xA
	strh r0, [r1, 0x8]
	b _080DA100
	.pool
_080D9FC0:
	mov r3, r8
	lsls r2, r3, 2
	add r2, r8
	lsls r2, 3
	adds r2, r4
	ldrb r5, [r2, 0xC]
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80DA164
	str r1, [r0]
	movs r0, 0xB
	strh r0, [r2, 0x8]
	b _080DA100
	.pool
_080D9FEC:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r4
	ldrb r5, [r4, 0xC]
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r6, r0, r1
	adds r0, r6, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080DA100
	adds r0, r6, 0
	bl FreeSpriteOamMatrix
	adds r0, r6, 0
	bl DestroySprite
	movs r0, 0x14
	strh r0, [r4, 0x8]
	b _080DA100
	.pool
_080DA024:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	movs r1, 0
	strh r1, [r0, 0x1C]
	movs r1, 0x15
	strh r1, [r0, 0x8]
	b _080DA100
_080DA038:
	bl sub_80DB89C
	ldr r0, =gStringVar1
	lsls r1, r6, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827D56F
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x20
	strh r1, [r0, 0x8]
	b _080DA100
	.pool
_080DA080:
	bl sub_80DED4C
	cmp r0, 0
	bne _080DA100
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x15
	strh r0, [r1, 0x8]
	b _080DA100
	.pool
_080DA0A0:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r4
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	ble _080DA100
	movs r0, 0
	strh r0, [r1, 0x1C]
	movs r0, 0x16
	strh r0, [r1, 0x8]
	b _080DA100
_080DA0C2:
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1, 0x10]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _080DA0F4
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	strh r2, [r0, 0x8]
	strh r2, [r0, 0xA]
	strh r2, [r0, 0xC]
	ldr r1, =sub_80DA198
	str r1, [r0]
	b _080DA100
	.pool
_080DA0F4:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	adds r0, r4
	strh r2, [r0, 0x8]
_080DA100:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D8B38

	thumb_func_start sub_80DA110
sub_80DA110: @ 80DA110
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r3, [r1]
	ldrb r2, [r3, 0x7]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r3, 0x7]
	bl DestroyTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA110

	thumb_func_start sub_80DA134
sub_80DA134: @ 80DA134
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x24]
	movs r3, 0x24
	ldrsh r2, [r1, r3]
	cmp r2, 0
	beq _080DA148
	subs r0, 0x2
	strh r0, [r1, 0x24]
	b _080DA15C
_080DA148:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _080DA15C
	strh r2, [r1, 0x2E]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_080DA15C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA134

	thumb_func_start sub_80DA164
sub_80DA164: @ 80DA164
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x24]
	subs r0, 0x6
	strh r0, [r2, 0x24]
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	movs r3, 0x24
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _080DA18E
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080DA18E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA164

	thumb_func_start sub_80DA198
sub_80DA198: @ 80DA198
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080DA22E
	cmp r0, 0x1
	bgt _080DA1C0
	cmp r0, 0
	beq _080DA1C6
	b _080DA250
	.pool
_080DA1C0:
	cmp r0, 0x2
	beq _080DA248
	b _080DA250
_080DA1C6:
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080DA224
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x7]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x7]
	bl sub_80DA8A4
	lsls r0, 24
	cmp r0, 0
	beq _080DA1F4
	bl sub_80DB944
	bl sub_80DBA18
_080DA1F4:
	ldr r4, =sub_80FCC88
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sub_80DA110
	adds r1, r4, 0
	bl SetTaskFuncWithFollowupFunc
	bl sub_80DBF68
	strh r6, [r5, 0x8]
	b _080DA250
	.pool
_080DA224:
	bl sub_80DB944
	bl sub_80DBA18
	b _080DA23E
_080DA22E:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080DA250
_080DA23E:
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080DA250
	.pool
_080DA248:
	movs r0, 0
	strh r0, [r5, 0x8]
	ldr r0, =sub_80DA25C
	str r0, [r5]
_080DA250:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA198

	thumb_func_start sub_80DA25C
sub_80DA25C: @ 80DA25C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_80DE008
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	ldr r1, =sub_80DA28C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA25C

	thumb_func_start sub_80DA28C
sub_80DA28C: @ 80DA28C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _080DA2D2
	cmp r5, 0x1
	bgt _080DA2B4
	cmp r5, 0
	beq _080DA2BA
	b _080DA312
	.pool
_080DA2B4:
	cmp r5, 0x2
	beq _080DA304
	b _080DA312
_080DA2BA:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080DA312
	movs r0, 0x2
	bl sub_80DE69C
	strh r5, [r4, 0xA]
	b _080DA2F6
_080DA2D2:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080DA312
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080DA312
	strh r1, [r4, 0xA]
_080DA2F6:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080DA312
	.pool
_080DA304:
	bl sub_80DC3AC
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	ldr r0, =sub_80DA31C
	str r0, [r4]
_080DA312:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA28C

	thumb_func_start sub_80DA31C
sub_80DA31C: @ 80DA31C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80DC3C4
	lsls r0, 24
	cmp r0, 0
	beq _080DA33A
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80DA348
	str r0, [r1]
_080DA33A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA31C

	thumb_func_start sub_80DA348
sub_80DA348: @ 80DA348
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x0201a204
	ldr r3, =gPlttBufferUnfaded
	ldr r1, =0x040000d4
	str r2, [r1]
	str r3, [r1, 0x4]
	ldr r2, =0x84000100
	str r2, [r1, 0x8]
	ldr r1, [r1, 0x8]
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0xA]
	ldr r0, =sub_80DA38C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80DA348

	thumb_func_start sub_80DA38C
sub_80DA38C: @ 80DA38C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080DA3BE
	movs r0, 0
	strh r0, [r1, 0x8]
	ldrh r0, [r1, 0xA]
	subs r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _080DA3BE
	ldr r0, =sub_80DA3CC
	str r0, [r1]
_080DA3BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA38C

	thumb_func_start sub_80DA3CC
sub_80DA3CC: @ 80DA3CC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080DA448
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r5, =gUnknown_02039F25
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r4, [r0, 0x1A]
	bl sub_80DB89C
	ldr r0, =gStringVar1
	ldrb r1, [r5]
	lsls r1, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r5, =gStringVar4
	ldr r0, =gUnknown_08587D90
	lsls r4, 2
	adds r4, r0
	ldr r1, [r4]
	adds r0, r5, 0
	bl StringExpandPlaceholders
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _080DA45A
	.pool
_080DA448:
	bl sub_80DED4C
	cmp r0, 0
	bne _080DA45A
	strh r0, [r6, 0x8]
	ldr r0, =sub_80DA464
	str r0, [r6]
	bl sub_80DCD48
_080DA45A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA3CC

	thumb_func_start sub_80DA464
sub_80DA464: @ 80DA464
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	ble _080DA48E
	movs r0, 0
	strh r0, [r4, 0x8]
	bl sub_80DC3AC
	ldr r0, =sub_80DA49C
	str r0, [r4]
_080DA48E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA464

	thumb_func_start sub_80DA49C
sub_80DA49C: @ 80DA49C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80DC3C4
	lsls r0, 24
	cmp r0, 0
	beq _080DA4BE
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	ldr r1, =sub_80DA4CC
	str r1, [r0]
_080DA4BE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA49C

	thumb_func_start sub_80DA4CC
sub_80DA4CC: @ 80DA4CC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80DE224
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80DE424
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA4CC

	thumb_func_start sub_80DA4F4
sub_80DA4F4: @ 80DA4F4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80DE350
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80DA51C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA4F4

	thumb_func_start sub_80DA51C
sub_80DA51C: @ 80DA51C
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x8
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	movs r0, 0xC
	bl GetGpuReg
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r3, sp
	ldrb r2, [r3]
	movs r1, 0x4
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	ldrb r0, [r4]
	ands r1, r0
	strb r1, [r4]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, 0x8
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0xC
	bl SetGpuReg
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	ldr r0, [r2]
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x5
	bne _080DA590
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80DA5E8
	b _080DA5A0
	.pool
_080DA590:
	bl sub_80DDB0C
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80DA5B4
_080DA5A0:
	str r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA51C

	thumb_func_start sub_80DA5B4
sub_80DA5B4: @ 80DA5B4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080DA5D8
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80D833C
	str r0, [r1]
_080DA5D8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA5B4

	thumb_func_start sub_80DA5E8
sub_80DA5E8: @ 80DA5E8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gBattle_BG0_Y
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	ldr r4, =gUnknown_02039F34
	movs r3, 0
	ldr r2, =gUnknown_02039F10
	movs r1, 0x3
_080DA600:
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r0, r3, r0
	ldrh r0, [r0, 0x4]
	strh r0, [r2]
	adds r3, 0x1C
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080DA600
	bl sub_80DBD18
	bl sub_80DB89C
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DA65C
	ldr r0, =gUnknown_02039F34
	ldr r2, [r0]
	ldr r0, =gUnknown_02039F25
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x8]
	bl sub_80ED03C
	b _080DA668
	.pool
_080DA65C:
	bl sub_80DF250
	bl sub_80DF4F8
	bl sub_80DF750
_080DA668:
	ldr r1, =gUnknown_030060B8
	ldr r0, =gRngValue
	ldr r0, [r0]
	str r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0827D597
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_80DA6B4
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA5E8

	thumb_func_start sub_80DA6B4
sub_80DA6B4: @ 80DA6B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_80DED4C
	adds r4, r0, 0
	cmp r4, 0
	bne _080DA6EA
	bl sub_80DE224
	ldr r0, =gBattle_BG1_X
	strh r4, [r0]
	ldr r1, =gBattle_BG1_Y
	movs r0, 0xA0
	strh r0, [r1]
	movs r0, 0x62
	movs r1, 0
	bl PlaySE12WithPanning
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	ldr r1, =sub_80DA700
	str r1, [r0]
_080DA6EA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA6B4

	thumb_func_start sub_80DA700
sub_80DA700: @ 80DA700
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	subs r0, 0x7
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bge _080DA718
	movs r0, 0
	strh r0, [r1]
_080DA718:
	ldrh r2, [r1]
	cmp r2, 0
	bne _080DA72E
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80DA740
	str r0, [r1]
	strh r2, [r1, 0x8]
_080DA72E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA700

	thumb_func_start sub_80DA740
sub_80DA740: @ 80DA740
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x31
	ble _080DA794
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_02039F2A
	ldrb r0, [r0]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _080DA780
	ldr r0, =sub_80DA7A0
	b _080DA792
	.pool
_080DA780:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_80DA830
_080DA792:
	str r0, [r4]
_080DA794:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA740

	thumb_func_start sub_80DA7A0
sub_80DA7A0: @ 80DA7A0
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =sub_80FCACC
	adds r0, r5, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sub_80DA7EC
	adds r1, r5, 0
	bl SetTaskFuncWithFollowupFunc
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =TaskDummy1
	str r1, [r0]
	bl sub_80DBF68
	movs r0, 0
	bl sub_80DC490
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA7A0

	thumb_func_start sub_80DA7EC
sub_80DA7EC: @ 80DA7EC
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r2, =gTasks
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_80DA830
	str r1, [r0]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA7EC

	thumb_func_start sub_80DA830
sub_80DA830: @ 80DA830
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080DA860
	adds r0, r2, 0
	bl DestroyTask
	ldr r0, =gFieldCallback
	ldr r1, =sub_80DA874
	str r1, [r0]
	bl FreeAllWindowBuffers
	bl sub_80D7A5C
	bl FreeMonSpritesGfx
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
_080DA860:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA830

	thumb_func_start sub_80DA874
sub_80DA874: @ 80DA874
	push {lr}
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80DA874

	thumb_func_start sub_80DA884
sub_80DA884: @ 80DA884
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DA898
	ldr r1, =gUnknown_02039F25
	movs r0, 0x3
	strb r0, [r1]
_080DA898:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA884

	thumb_func_start sub_80DA8A4
sub_80DA8A4: @ 80DA8A4
	push {lr}
	ldr r0, =gUnknown_02039F25
	ldr r1, =gUnknown_02039F2B
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080DA8C0
	movs r0, 0
	b _080DA8C2
	.pool
_080DA8C0:
	movs r0, 0x1
_080DA8C2:
	pop {r1}
	bx r1
	thumb_func_end sub_80DA8A4

	thumb_func_start sub_80DA8C8
sub_80DA8C8: @ 80DA8C8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gSaveBlock2Ptr
	ldr r1, [r6]
	mov r0, sp
	bl StringCopy
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DA8F2
	mov r0, sp
	bl sub_80DF9D4
_080DA8F2:
	ldr r5, =gUnknown_02039F25
	ldrb r0, [r5]
	lsls r0, 6
	ldr r4, =gUnknown_02039E0D
	adds r0, r4
	mov r1, sp
	movs r2, 0x8
	bl memcpy
	ldr r0, [r6]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _080DA928
	ldrb r0, [r5]
	lsls r0, 6
	adds r0, r4, r0
	movs r1, 0xD8
	b _080DA930
	.pool
_080DA928:
	ldrb r0, [r5]
	lsls r0, 6
	adds r0, r4, r0
	movs r1, 0xD9
_080DA930:
	strb r1, [r0, 0x8]
	ldr r7, =gUnknown_02039E00
	ldr r6, =gUnknown_02039F25
	ldrb r0, [r6]
	lsls r0, 6
	adds r1, r7, 0
	adds r1, 0x18
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	ldrb r0, [r6]
	lsls r0, 6
	adds r0, r7
	adds r0, 0x2C
	strb r1, [r0]
	movs r0, 0x64
	mov r1, r8
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	strh r0, [r1]
	adds r0, r5, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DA994
	adds r0, r5, 0
	movs r1, 0x3
	bl GetMonData
	adds r1, r0, 0
	mov r0, sp
	bl sub_80DF9E0
_080DA994:
	ldrb r0, [r6]
	lsls r0, 6
	adds r4, r7, 0x2
	adds r0, r4
	mov r1, sp
	movs r2, 0xB
	bl memcpy
	ldrb r0, [r6]
	lsls r0, 6
	adds r0, r4
	mov r1, sp
	bl StringCopy
	adds r0, r5, 0
	movs r1, 0x16
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	adds r1, 0x26
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x17
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	adds r1, 0x27
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x18
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	adds r1, 0x28
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x21
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	adds r1, 0x29
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x2F
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	adds r1, 0x2A
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x30
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	adds r1, 0x2B
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0xD
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	strh r0, [r1, 0x1E]
	adds r0, r5, 0
	movs r1, 0xE
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	strh r0, [r1, 0x20]
	adds r0, r5, 0
	movs r1, 0xF
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	strh r0, [r1, 0x22]
	adds r0, r5, 0
	movs r1, 0x10
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r1, r7
	strh r0, [r1, 0x24]
	adds r0, r5, 0
	movs r1, 0
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r2, r7, 0
	adds r2, 0x38
	adds r1, r2
	str r0, [r1]
	adds r0, r5, 0
	movs r1, 0x1
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 6
	adds r2, r7, 0
	adds r2, 0x3C
	adds r1, r2
	str r0, [r1]
	adds r0, r5, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r2, r0, 16
	ldrb r0, [r6]
	lsls r0, 6
	adds r1, r0, r7
	adds r0, r1, 0
	adds r0, 0x26
	ldrb r3, [r0]
	adds r0, 0x1
	ldrb r5, [r0]
	adds r0, 0x1
	ldrb r6, [r0]
	adds r0, 0x1
	ldrb r7, [r0]
	adds r0, 0x1
	ldrb r4, [r0]
	cmp r2, 0xFE
	bne _080DAAC4
	adds r3, 0x14
	b _080DAB12
	.pool
_080DAAC4:
	cmp r2, 0xFF
	bne _080DAAD4
	lsls r0, r5, 16
	movs r1, 0xA0
	lsls r1, 13
	adds r0, r1
	lsrs r5, r0, 16
	b _080DAB12
_080DAAD4:
	movs r0, 0x80
	lsls r0, 1
	cmp r2, r0
	bne _080DAAE8
	lsls r0, r6, 16
	movs r1, 0xA0
	lsls r1, 13
	adds r0, r1
	lsrs r6, r0, 16
	b _080DAB12
_080DAAE8:
	ldr r0, =0x00000101
	cmp r2, r0
	bne _080DAB00
	lsls r0, r7, 16
	movs r1, 0xA0
	lsls r1, 13
	adds r0, r1
	lsrs r7, r0, 16
	b _080DAB12
	.pool
_080DAB00:
	movs r0, 0x81
	lsls r0, 1
	cmp r2, r0
	bne _080DAB12
	lsls r0, r4, 16
	movs r1, 0xA0
	lsls r1, 13
	adds r0, r1
	lsrs r4, r0, 16
_080DAB12:
	cmp r3, 0xFF
	ble _080DAB18
	movs r3, 0xFF
_080DAB18:
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080DAB22
	movs r5, 0xFF
_080DAB22:
	lsls r0, r6, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080DAB2C
	movs r6, 0xFF
_080DAB2C:
	lsls r0, r7, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080DAB36
	movs r7, 0xFF
_080DAB36:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080DAB40
	movs r4, 0xFF
_080DAB40:
	ldr r2, =gUnknown_02039E00
	ldr r1, =gUnknown_02039F25
	ldrb r0, [r1]
	lsls r0, 6
	adds r0, r2
	adds r0, 0x26
	strb r3, [r0]
	ldrb r0, [r1]
	lsls r0, 6
	adds r0, r2
	adds r0, 0x27
	strb r5, [r0]
	ldrb r0, [r1]
	lsls r0, 6
	adds r0, r2
	adds r0, 0x28
	strb r6, [r0]
	ldrb r0, [r1]
	lsls r0, 6
	adds r0, r2
	adds r0, 0x29
	strb r7, [r0]
	ldrb r0, [r1]
	lsls r0, 6
	adds r0, r2
	adds r0, 0x2A
	strb r4, [r0]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DA8C8

	thumb_func_start sub_80DAB8C
sub_80DAB8C: @ 80DAB8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x64
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r6, 0
	movs r7, 0
	bl sub_80DA884
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080DABC0
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DABC0
	movs r7, 0x1
_080DABC0:
	movs r5, 0
	ldr r2, =gUnknown_085880A4
	ldr r3, =gUnknown_085898A4
_080DABC6:
	ldrb r0, [r2, 0x1C]
	lsls r0, 30
	lsrs r0, 30
	cmp r8, r0
	bne _080DAC3A
	cmp r7, 0x1
	bne _080DABEC
	ldrb r0, [r3]
	cmp r0, 0x1
	beq _080DAC3A
	b _080DABF2
	.pool
_080DABEC:
	ldrb r0, [r3]
	cmp r0, 0x2
	beq _080DAC3A
_080DABF2:
	cmp r4, 0
	bne _080DABFE
	ldrb r0, [r2, 0x1C]
	lsls r0, 29
	cmp r0, 0
	blt _080DAC2E
_080DABFE:
	cmp r4, 0x1
	bne _080DAC0A
	ldrb r0, [r2, 0x1C]
	lsls r0, 28
	cmp r0, 0
	blt _080DAC2E
_080DAC0A:
	cmp r4, 0x2
	bne _080DAC16
	ldrb r0, [r2, 0x1C]
	lsls r0, 27
	cmp r0, 0
	blt _080DAC2E
_080DAC16:
	cmp r4, 0x3
	bne _080DAC22
	ldrb r0, [r2, 0x1C]
	lsls r0, 26
	cmp r0, 0
	blt _080DAC2E
_080DAC22:
	cmp r4, 0x4
	bne _080DAC3A
	ldrb r0, [r2, 0x1C]
	lsls r0, 25
	cmp r0, 0
	bge _080DAC3A
_080DAC2E:
	adds r0, r6, 0
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r6, r1, 24
	add r0, sp
	strb r5, [r0]
_080DAC3A:
	adds r2, 0x40
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x5F
	bls _080DABC6
	mov r0, sp
	adds r1, r0, r6
	movs r0, 0xFF
	strb r0, [r1]
	movs r5, 0
	ldr r7, =gUnknown_085880A4
_080DAC50:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_02039E00
	lsls r2, r5, 6
	adds r2, r1
	mov r1, sp
	adds r4, r1, r0
	ldrb r1, [r4]
	lsls r1, 6
	adds r1, r7
	adds r0, r2, 0
	movs r2, 0x40
	bl memcpy
	ldrb r0, [r4]
	adds r2, r5, 0x1
	subs r1, r6, 0x1
	cmp r0, 0xFF
	beq _080DAC92
	adds r3, r4, 0
_080DAC86:
	ldrb r0, [r3, 0x1]
	strb r0, [r3]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _080DAC86
_080DAC92:
	lsls r0, r1, 24
	lsrs r6, r0, 24
	adds r5, r2, 0
	cmp r5, 0x2
	ble _080DAC50
	ldr r0, =gUnknown_02039F24
	ldrb r0, [r0]
	bl sub_80DA8C8
	add sp, 0x64
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DAB8C

	thumb_func_start sub_80DACBC
sub_80DACBC: @ 80DACBC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x64
	mov r8, r2
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	movs r7, 0
	ldr r0, =gUnknown_02039F30
	ldrb r1, [r0]
	mov r9, r0
	cmp r1, 0x4
	bne _080DACDE
	b _080DADF6
_080DACDE:
	movs r5, 0
	ldr r3, =gUnknown_085880A4
	ldr r6, =gUnknown_085898A4
_080DACE4:
	ldrb r0, [r3, 0x1C]
	lsls r0, 30
	lsrs r0, 30
	cmp r2, r0
	bne _080DAD56
	mov r0, r8
	cmp r0, 0x1
	bne _080DAD08
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _080DAD56
	b _080DAD0E
	.pool
_080DAD08:
	ldrb r0, [r6]
	cmp r0, 0x2
	beq _080DAD56
_080DAD0E:
	cmp r4, 0
	bne _080DAD1A
	ldrb r0, [r3, 0x1C]
	lsls r0, 29
	cmp r0, 0
	blt _080DAD4A
_080DAD1A:
	cmp r4, 0x1
	bne _080DAD26
	ldrb r0, [r3, 0x1C]
	lsls r0, 28
	cmp r0, 0
	blt _080DAD4A
_080DAD26:
	cmp r4, 0x2
	bne _080DAD32
	ldrb r0, [r3, 0x1C]
	lsls r0, 27
	cmp r0, 0
	blt _080DAD4A
_080DAD32:
	cmp r4, 0x3
	bne _080DAD3E
	ldrb r0, [r3, 0x1C]
	lsls r0, 26
	cmp r0, 0
	blt _080DAD4A
_080DAD3E:
	cmp r4, 0x4
	bne _080DAD56
	ldrb r0, [r3, 0x1C]
	lsls r0, 25
	cmp r0, 0
	bge _080DAD56
_080DAD4A:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r7, r1, 24
	add r0, sp
	strb r5, [r0]
_080DAD56:
	adds r3, 0x40
	adds r6, 0x1
	adds r5, 0x1
	cmp r5, 0x5F
	bls _080DACE4
	mov r3, sp
	adds r1, r3, r7
	movs r0, 0xFF
	strb r0, [r1]
	movs r5, 0
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x4
	subs r0, r1
	cmp r5, r0
	bge _080DADF6
	ldr r3, =gUnknown_02039E00
	mov r8, r3
	mov r6, r9
	movs r0, 0x2
	add r0, r8
	mov r9, r0
_080DAD82:
	bl sub_80F903C
	lsls r0, 16
	lsrs r0, 16
	adds r1, r7, 0
	bl __modsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldrb r0, [r6]
	adds r0, r5
	lsls r0, 6
	add r0, r8
	ldr r2, =gUnknown_085880A4
	mov r3, sp
	adds r4, r3, r1
	ldrb r1, [r4]
	lsls r1, 6
	adds r1, r2
	movs r2, 0x40
	bl memcpy
	ldrb r0, [r6]
	adds r0, r5
	lsls r0, 6
	mov r1, r8
	adds r1, 0xD
	adds r0, r1
	bl sub_80DF9D4
	ldrb r0, [r6]
	adds r0, r5
	lsls r0, 6
	add r0, r9
	movs r1, 0x2
	bl sub_80DF9E0
	ldrb r0, [r4]
	adds r3, r5, 0x1
	subs r1, r7, 0x1
	cmp r0, 0xFF
	beq _080DADE6
	adds r2, r4, 0
_080DADDA:
	ldrb r0, [r2, 0x1]
	strb r0, [r2]
	adds r2, 0x1
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _080DADDA
_080DADE6:
	lsls r0, r1, 24
	lsrs r7, r0, 24
	adds r5, r3, 0
	ldrb r1, [r6]
	movs r0, 0x4
	subs r0, r1
	cmp r5, r0
	blt _080DAD82
_080DADF6:
	add sp, 0x64
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DACBC

	thumb_func_start sub_80DAE0C
sub_80DAE0C: @ 80DAE0C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	beq _080DAE1E
	movs r0, 0x3
	b _080DAE9A
_080DAE1E:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080DAE2E
	movs r0, 0x4
	b _080DAE9A
_080DAE2E:
	ldr r0, =gScriptContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080DAE82
	lsls r0, 2
	ldr r1, =_080DAE48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DAE48:
	.4byte _080DAE5C
	.4byte _080DAE62
	.4byte _080DAE68
	.4byte _080DAE6E
	.4byte _080DAE74
_080DAE5C:
	adds r0, r4, 0
	movs r1, 0x32
	b _080DAE78
_080DAE62:
	adds r0, r4, 0
	movs r1, 0x33
	b _080DAE78
_080DAE68:
	adds r0, r4, 0
	movs r1, 0x34
	b _080DAE78
_080DAE6E:
	adds r0, r4, 0
	movs r1, 0x35
	b _080DAE78
_080DAE74:
	adds r0, r4, 0
	movs r1, 0x36
_080DAE78:
	bl GetMonData
	lsls r0, 24
	lsrs r1, r0, 24
	b _080DAE86
_080DAE82:
	movs r0, 0
	b _080DAE9A
_080DAE86:
	ldr r0, =gUnknown_02039F2E
	adds r2, r1, 0
	ldrh r1, [r0]
	movs r0, 0x2
	cmp r2, r1
	bhi _080DAE9A
	movs r0, 0
	cmp r2, r1
	bcc _080DAE9A
	movs r0, 0x1
_080DAE9A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DAE0C

	thumb_func_start sub_80DAEA4
sub_80DAEA4: @ 80DAEA4
	push {r4,r5,lr}
	movs r5, 0
_080DAEA8:
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	lsls r4, r5, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80DAF04
	adds r0, r4, 0
	bl sub_80DAF88
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DAEA8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DAEA4

	thumb_func_start sub_80DAED4
sub_80DAED4: @ 80DAED4
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r0, =gDisplayedStringBattle
	ldr r1, =gText_ColorTransparent
	bl StringCopy
	adds r1, r0, 0
	subs r0, r1, 0x1
	strb r4, [r0]
	adds r0, r1, 0
	adds r1, r5, 0
	bl StringCopy
	adds r1, r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DAED4

	thumb_func_start sub_80DAF04
sub_80DAF04: @ 80DAF04
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r0, r1, 24
	movs r2, 0xA0
	lsls r2, 20
	adds r1, r2
	lsrs r1, 24
	bl sub_80DAF1C
	pop {r0}
	bx r0
	thumb_func_end sub_80DAF04

	thumb_func_start sub_80DAF1C
sub_80DAF1C: @ 80DAF1C
	push {r4,r5,lr}
	sub sp, 0x24
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gText_Slash
	add r0, sp, 0x4
	bl StringCopy
	lsls r1, r5, 6
	ldr r0, =gUnknown_02039E0D
	adds r1, r0
	add r0, sp, 0x4
	bl StringAppend
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_80DAED4
	ldr r4, =gDisplayedStringBattle
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	cmp r2, 0x37
	ble _080DAF5C
	movs r2, 0x37
_080DAF5C:
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x7
	str r1, [sp]
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_80DEBD0
	add sp, 0x24
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DAF1C

	thumb_func_start sub_80DAF88
sub_80DAF88: @ 80DAF88
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r0, r1, 24
	movs r2, 0xA0
	lsls r2, 20
	adds r1, r2
	lsrs r1, 24
	bl sub_80DAFA0
	pop {r0}
	bx r0
	thumb_func_end sub_80DAF88

	thumb_func_start sub_80DAFA0
sub_80DAFA0: @ 80DAFA0
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r4, 6
	ldr r2, =gUnknown_02039E02
	adds r0, r2
	bl sub_80DAED4
	ldr r0, =gUnknown_02039F26
	adds r4, r0
	ldrb r0, [r4]
	ldr r1, =gDisplayedStringBattle
	movs r2, 0x7
	str r2, [sp]
	movs r2, 0x5
	movs r3, 0x1
	bl sub_80DEBD0
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DAFA0

	thumb_func_start sub_80DAFE0
sub_80DAFE0: @ 80DAFE0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0x4
	bhi _080DB06C
	lsls r0, 2
	ldr r1, =_080DAFFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DAFFC:
	.4byte _080DB010
	.4byte _080DB028
	.4byte _080DB040
	.4byte _080DB050
	.4byte _080DB06C
_080DB010:
	ldr r0, =gUnknown_02039E00
	lsls r2, 6
	adds r1, r2, r0
	adds r3, r1, 0
	adds r3, 0x26
	ldrb r5, [r3]
	adds r3, 0x4
	ldrb r4, [r3]
	adds r1, 0x27
	b _080DB07E
	.pool
_080DB028:
	ldr r0, =gUnknown_02039E00
	lsls r2, 6
	adds r1, r2, r0
	adds r3, r1, 0
	adds r3, 0x27
	ldrb r5, [r3]
	subs r3, 0x1
	ldrb r4, [r3]
	adds r1, 0x28
	b _080DB07E
	.pool
_080DB040:
	ldr r1, =gUnknown_02039E00
	lsls r2, 6
	adds r3, r2, r1
	adds r0, r3, 0
	adds r0, 0x28
	b _080DB05A
	.pool
_080DB050:
	ldr r1, =gUnknown_02039E00
	lsls r2, 6
	adds r3, r2, r1
	adds r0, r3, 0
	adds r0, 0x29
_080DB05A:
	ldrb r5, [r0]
	subs r0, 0x1
	ldrb r4, [r0]
	adds r0, 0x2
	ldrb r3, [r0]
	adds r0, r1, 0
	b _080DB080
	.pool
_080DB06C:
	ldr r0, =gUnknown_02039E00
	lsls r2, 6
	adds r1, r2, r0
	adds r3, r1, 0
	adds r3, 0x2A
	ldrb r5, [r3]
	subs r3, 0x1
	ldrb r4, [r3]
	adds r1, 0x26
_080DB07E:
	ldrb r3, [r1]
_080DB080:
	adds r1, r2, r0
	adds r1, 0x2B
	adds r0, r4, r3
	ldrb r1, [r1]
	adds r0, r1
	asrs r0, 1
	adds r0, r5, r0
	lsls r0, 16
	lsrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DAFE0

	thumb_func_start sub_80DB09C
sub_80DB09C: @ 80DB09C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r5, =gUnknown_02039F00
_080DB0A6:
	lsls r0, r4, 24
	lsrs r0, 24
	adds r1, r6, 0
	bl sub_80DAFE0
	strh r0, [r5]
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DB0A6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DB09C

	thumb_func_start sub_80DB0C4
sub_80DB0C4: @ 80DB0C4
	push {r4,r5,lr}
	ldr r0, =gUnknown_08587C00
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08C1C6B8
	movs r1, 0x88
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08587BE8
	movs r1, 0x70
	movs r2, 0x24
	movs r3, 0x1E
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r5, r2, r4
	ldrb r3, [r5, 0x5]
	movs r1, 0xF
	ands r1, r3
	movs r3, 0x10
	orrs r1, r3
	strb r1, [r5, 0x5]
	adds r4, 0x1C
	adds r2, r4
	ldr r1, =SpriteCallbackDummy
	str r1, [r2]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DB0C4

	thumb_func_start sub_80DB120
sub_80DB120: @ 80DB120
	push {lr}
	ldr r0, =gUnknown_08587C08
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08587C10
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_08587C18
	movs r1, 0x60
	movs r2, 0xA
	movs r3, 0x1D
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	movs r1, 0x3E
	adds r1, r2
	mov r12, r1
	ldrb r1, [r1]
	movs r3, 0x4
	orrs r1, r3
	mov r3, r12
	strb r1, [r3]
	ldrh r1, [r2, 0x4]
	lsls r1, 22
	lsrs r1, 22
	strh r1, [r2, 0x2E]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DB120

	thumb_func_start sub_80DB174
sub_80DB174: @ 80DB174
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r1, 0
	adds r6, r2, 0
	adds r4, r3, 0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r5, 0
	bl sub_80DE84C
	adds r5, r0, 0
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	cmp r4, r0
	bne _080DB1B8
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	adds r2, r5, 0
	adds r3, r6, 0
	bl HandleLoadSpecialPokePic_2
	b _080DB1CC
	.pool
_080DB1B8:
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	adds r2, r5, 0
	adds r3, r6, 0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
_080DB1CC:
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl species_and_otid_get_pal
	movs r1, 0x90
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	adds r0, r5, 0
	movs r1, 0
	bl sub_806A068
	ldr r4, =gUnknown_0202499C
	movs r0, 0x2
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A600C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	movs r1, 0x70
	movs r3, 0x1E
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gSprites
	mov r8, r0
	lsls r0, r7, 4
	adds r0, r7
	lsls r6, r0, 2
	mov r0, r8
	adds r4, r6, r0
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	movs r1, 0xD
	negs r1, r1
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4, 0x5]
	movs r0, 0x2
	bl sub_80A82E4
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	mov r0, r8
	adds r0, 0x1C
	adds r0, r6, r0
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	strh r0, [r4, 0x2E]
	strh r5, [r4, 0x32]
	adds r0, r5, 0
	bl sub_80DB2A8
	lsls r0, 24
	cmp r0, 0
	beq _080DB278
	mov r0, r8
	adds r0, 0x10
	adds r0, r6, r0
	ldr r1, =gUnknown_082FF6C0
	b _080DB280
	.pool
_080DB278:
	mov r0, r8
	adds r0, 0x10
	adds r0, r6, r0
	ldr r1, =gUnknown_082FF694
_080DB280:
	str r1, [r0]
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DB174

	thumb_func_start sub_80DB2A8
sub_80DB2A8: @ 80DB2A8
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC9
	beq _080DB2B6
	movs r0, 0x1
	b _080DB2B8
_080DB2B6:
	movs r0, 0
_080DB2B8:
	pop {r1}
	bx r1
	thumb_func_end sub_80DB2A8

	thumb_func_start sub_80DB2BC
sub_80DB2BC: @ 80DB2BC
	push {r4-r6,lr}
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	movs r4, 0xA0
	lsls r4, 3
	adds r1, r0, r4
	movs r6, 0xA0
	lsls r6, 1
	adds r2, r6, 0
	bl CpuSet
	ldr r0, [r5]
	ldr r0, [r0, 0x2C]
	adds r4, r0, r4
	adds r1, r4, 0
	adds r2, r6, 0
	bl CpuSet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DB2BC

	thumb_func_start sub_80DB2EC
sub_80DB2EC: @ 80DB2EC
	push {lr}
	lsls r0, 16
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r2, =gContestEffects
	ldr r1, =gContestMoves
	lsrs r0, 13
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _080DB354
	lsls r0, 2
	ldr r1, =_080DB320
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DB320:
	.4byte _080DB344
	.4byte _080DB344
	.4byte _080DB34C
	.4byte _080DB34C
	.4byte _080DB354
	.4byte _080DB354
	.4byte _080DB354
	.4byte _080DB354
	.4byte _080DB344
_080DB344:
	ldr r0, =0x00009082
	b _080DB356
	.pool
_080DB34C:
	ldr r0, =0x00009088
	b _080DB356
	.pool
_080DB354:
	ldr r0, =0x00009086
_080DB356:
	lsls r1, r3, 12
	movs r2, 0x90
	lsls r2, 8
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DB2EC

	thumb_func_start prints_contest_move_description
prints_contest_move_description: @ 80DB370
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 29
	ldr r7, =0x00004040
	cmp r0, 0
	beq _080DB3A4
	adds r7, 0x5
	cmp r0, 0x1
	beq _080DB3A4
	adds r7, 0x5
	cmp r0, 0x2
	beq _080DB3A4
	adds r7, 0x40
	cmp r0, 0x3
	bne _080DB3A4
	subs r7, 0x20
_080DB3A4:
	movs r6, 0x5
	str r6, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0
	adds r1, r7, 0
	movs r2, 0xB
	movs r3, 0x1F
	bl sub_80DECB8
	adds r1, r7, 0
	adds r1, 0x10
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0
	movs r2, 0xB
	movs r3, 0x20
	bl sub_80DECB8
	ldr r2, =gContestEffects
	ldr r0, =gContestMoves
	mov r3, r8
	lsls r1, r3, 3
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x1]
	adds r7, r1, 0
	cmp r0, 0xFF
	bne _080DB3FC
	movs r6, 0
	b _080DB408
	.pool
_080DB3FC:
	ldrb r0, [r2, 0x1]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
_080DB408:
	cmp r6, 0x8
	bls _080DB40E
	movs r6, 0x8
_080DB40E:
	ldr r1, =0x00005035
	movs r0, 0x8
	str r0, [sp]
	movs r5, 0x1
	str r5, [sp, 0x4]
	movs r4, 0x11
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0x15
	movs r3, 0x1F
	bl sub_80DED10
	ldr r1, =0x00005012
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0x15
	movs r3, 0x1F
	bl sub_80DED10
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x2]
	cmp r0, 0xFF
	bne _080DB460
	movs r6, 0
	b _080DB46C
	.pool
_080DB460:
	ldrb r0, [r1, 0x2]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
_080DB46C:
	cmp r6, 0x8
	bls _080DB472
	movs r6, 0x8
_080DB472:
	ldr r1, =0x00005036
	movs r0, 0x8
	str r0, [sp]
	movs r5, 0x1
	str r5, [sp, 0x4]
	movs r4, 0x11
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0x15
	movs r3, 0x20
	bl sub_80DED10
	ldr r1, =0x00005014
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r2, 0x15
	movs r3, 0x20
	bl sub_80DED10
	movs r0, 0xA
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r1, =gContestEffectDescriptionPointers
	ldr r0, =gContestMoves
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0xA
	bl sub_80DEB70
	ldr r1, =gText_Slash
	movs r0, 0x9
	bl sub_80DEB70
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end prints_contest_move_description

	thumb_func_start sub_80DB4E0
sub_80DB4E0: @ 80DB4E0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_02039F26
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, 0x2
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	bne _080DB560
	cmp r5, 0
	beq _080DB560
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80DB2EC
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x2
	mov r8, r0
	str r0, [sp]
	movs r5, 0x1
	str r5, [sp, 0x4]
	movs r6, 0x11
	str r6, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x14
	adds r3, r7, 0
	bl sub_80DECB8
	adds r4, 0x10
	lsls r4, 16
	lsrs r4, 16
	adds r3, r7, 0x1
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x14
	bl sub_80DECB8
	b _080DB576
	.pool
_080DB560:
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x14
	adds r3, r7, 0
	bl sub_80DED10
_080DB576:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DB4E0

	thumb_func_start sub_80DB584
sub_80DB584: @ 80DB584
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0
_080DB58A:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	adds r0, r5, r0
	ldrh r0, [r0, 0x6]
	lsls r1, r4, 24
	lsrs r1, 24
	bl sub_80DB4E0
	adds r5, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DB58A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DB584

	thumb_func_start sub_80DB5B0
sub_80DB5B0: @ 80DB5B0
	ldr r0, =0x00002034
	bx lr
	.pool
	thumb_func_end sub_80DB5B0

	thumb_func_start sub_80DB5B8
sub_80DB5B8: @ 80DB5B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	mov r10, r8
	ldr r0, =gUnknown_02039F34
	mov r9, r0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r7, r0, 2
	adds r3, r7, r1
	ldrb r0, [r3, 0x10]
	movs r5, 0x30
	ands r5, r0
	cmp r5, 0
	bne _080DB5F4
	movs r0, 0
	b _080DB68A
	.pool
_080DB5F4:
	ldr r0, =gUnknown_02039F26
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, 0x2
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0xD
	ldrsb r0, [r3, r0]
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	asrs r4, r0, 24
	cmp r5, 0x10
	bne _080DB648
	bl sub_80DB5B0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1
	str r0, [sp]
	lsls r0, r4, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r2, 0x13
	adds r3, r6, 0
	bl sub_80DED10
	mov r1, r8
	cmp r1, 0
	beq _080DB688
	movs r0, 0x5B
	b _080DB672
	.pool
_080DB648:
	adds r3, r6, r4
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x3
	subs r0, r4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x13
	bl sub_80DED10
	mov r0, r10
	cmp r0, 0
	beq _080DB688
	movs r0, 0x26
_080DB672:
	bl PlaySE
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x4]
	adds r1, r7, r1
	ldrb r2, [r1, 0x10]
	movs r0, 0x31
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x10]
_080DB688:
	movs r0, 0x1
_080DB68A:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80DB5B8

	thumb_func_start sub_80DB69C
sub_80DB69C: @ 80DB69C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r7, 0
	movs r0, 0x1
	mov r10, r0
	movs r1, 0x11
	mov r9, r1
	movs r0, 0
	mov r8, r0
_080DB6B6:
	ldr r0, =gUnknown_02039F26
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r4, r0, 2
	adds r4, r0
	adds r4, 0x2
	lsls r4, 24
	lsrs r4, 24
	bl sub_80DB5B0
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	add r0, r8
	ldrb r0, [r0, 0xD]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	mov r1, r10
	str r1, [sp]
	asrs r6, r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0x13
	adds r3, r4, 0
	bl sub_80DED10
	adds r4, r6
	lsls r4, 24
	lsrs r4, 24
	mov r1, r10
	str r1, [sp]
	movs r0, 0x3
	subs r0, r6
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x13
	adds r3, r4, 0
	bl sub_80DED10
	movs r1, 0x1C
	add r8, r1
	adds r7, 0x1
	cmp r7, 0x3
	ble _080DB6B6
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DB69C

	thumb_func_start sub_80DB748
sub_80DB748: @ 80DB748
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0
	cmp r1, 0x4
	bhi _080DB78A
	lsls r0, r1, 2
	ldr r1, =_080DB764
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DB764:
	.4byte _080DB778
	.4byte _080DB77C
	.4byte _080DB780
	.4byte _080DB784
	.4byte _080DB788
_080DB778:
	movs r0, 0x80
	b _080DB78A
_080DB77C:
	movs r0, 0x84
	b _080DB78A
_080DB780:
	movs r0, 0x86
	b _080DB78A
_080DB784:
	movs r0, 0x88
	b _080DB78A
_080DB788:
	movs r0, 0x82
_080DB78A:
	movs r1, 0x90
	lsls r1, 8
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_80DB748

	thumb_func_start sub_80DB798
sub_80DB798: @ 80DB798
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	mov r9, r1
	movs r1, 0
	mov r8, r1
	ldr r1, =gUnknown_02039F26
	adds r1, r0, r1
	ldrb r2, [r1]
	lsls r1, r2, 2
	adds r1, r2
	adds r1, 0x2
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldr r0, [r2, 0x10]
	ldr r1, =0x00ff0003
	ands r0, r1
	cmp r0, 0
	bne _080DB7DC
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	beq _080DB7EC
_080DB7DC:
	movs r0, 0
	b _080DB80E
	.pool
_080DB7EC:
	ldrb r1, [r2, 0xC]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _080DB7FA
	movs r0, 0x1
	b _080DB80E
_080DB7FA:
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	bne _080DB80C
	ldrb r1, [r2, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080DB81A
_080DB80C:
	movs r0, 0x2
_080DB80E:
	bl sub_80DB748
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	b _080DB81E
_080DB81A:
	movs r0, 0
	mov r9, r0
_080DB81E:
	mov r1, r9
	cmp r1, 0
	beq _080DB85E
	movs r6, 0x2
	str r6, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0
	mov r1, r8
	movs r2, 0x14
	adds r3, r7, 0
	bl sub_80DECB8
	mov r1, r8
	adds r1, 0x10
	lsls r1, 16
	lsrs r1, 16
	adds r3, r7, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0
	movs r2, 0x14
	bl sub_80DECB8
	b _080DB874
_080DB85E:
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x14
	adds r3, r7, 0
	bl sub_80DED10
_080DB874:
	mov r0, r9
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80DB798

	thumb_func_start sub_80DB884
sub_80DB884: @ 80DB884
	push {r4,lr}
	movs r4, 0
_080DB888:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80DB798
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DB888
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DB884

	thumb_func_start sub_80DB89C
sub_80DB89C: @ 80DB89C
	push {lr}
	movs r0, 0x4
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x4
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl sub_80DED60
	pop {r0}
	bx r0
	thumb_func_end sub_80DB89C

	thumb_func_start sub_80DB8B8
sub_80DB8B8: @ 80DB8B8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	adds r0, r4, 0
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	beq _080DB8D0
	movs r0, 0
	b _080DB90A
_080DB8D0:
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	cmp r4, r0
	beq _080DB8F4
	adds r0, r4, 0
	bl sub_81562C4
	bl sub_8156324
	lsls r0, 24
	ldr r2, =gUnknown_02039E00
	lsrs r0, 23
	lsls r1, r4, 6
	b _080DB902
	.pool
_080DB8F4:
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 1
	lsls r1, r5, 6
_080DB902:
	adds r0, r1
	adds r2, 0x1E
	adds r0, r2
	ldrh r0, [r0]
_080DB90A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DB8B8

	thumb_func_start sub_80DB918
sub_80DB918: @ 80DB918
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0
_080DB91E:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80DB8B8
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	adds r1, r5, r1
	strh r0, [r1, 0x6]
	adds r5, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DB91E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DB918

	thumb_func_start sub_80DB944
sub_80DB944: @ 80DB944
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r5, =gUnknown_02039F34
	mov r4, sp
	movs r3, 0
	movs r6, 0x3
_080DB956:
	ldr r2, [r5]
	ldr r1, [r2, 0x4]
	adds r1, r3, r1
	ldrh r0, [r1, 0x2]
	ldrh r7, [r1, 0x4]
	adds r0, r7
	strh r0, [r1, 0x4]
	ldr r0, [r2, 0x4]
	adds r0, r3, r0
	ldrh r0, [r0, 0x4]
	strh r0, [r4]
	adds r4, 0x2
	adds r3, 0x1C
	subs r6, 0x1
	cmp r6, 0
	bge _080DB956
	movs r6, 0
_080DB978:
	movs r4, 0x3
	cmp r4, r6
	ble _080DB9A4
_080DB97E:
	subs r5, r4, 0x1
	lsls r0, r5, 1
	mov r1, sp
	adds r3, r1, r0
	lsls r0, r4, 1
	adds r2, r1, r0
	ldrh r4, [r3]
	movs r7, 0
	ldrsh r1, [r3, r7]
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DB99E
	ldrh r0, [r2]
	strh r4, [r2]
	strh r0, [r3]
_080DB99E:
	adds r4, r5, 0
	cmp r4, r6
	bgt _080DB97E
_080DB9A4:
	adds r6, 0x1
	cmp r6, 0x2
	ble _080DB978
	movs r6, 0
	movs r0, 0x4
	negs r0, r0
	mov r9, r0
	ldr r1, =gUnknown_02039F34
	mov r8, r1
	movs r7, 0x3
	mov r12, r7
_080DB9BA:
	movs r4, 0
	lsls r0, r6, 3
	adds r7, r6, 0x1
	subs r0, r6
	lsls r5, r0, 2
	mov r3, sp
_080DB9C6:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r5, r0
	movs r6, 0x4
	ldrsh r1, [r2, r6]
	movs r6, 0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bne _080DB9F0
	mov r0, r12
	ands r4, r0
	ldrb r1, [r2, 0xB]
	mov r0, r9
	ands r0, r1
	orrs r0, r4
	strb r0, [r2, 0xB]
	b _080DB9F8
	.pool
_080DB9F0:
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DB9C6
_080DB9F8:
	adds r6, r7, 0
	cmp r6, 0x3
	ble _080DB9BA
	movs r0, 0x1
	bl sub_80DCE58
	bl sub_80DD590
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DB944

	thumb_func_start sub_80DBA18
sub_80DBA18: @ 80DBA18
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039F34
	movs r2, 0
	movs r3, 0x3
_080DBA20:
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r1, r2, r0
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	bne _080DBA34
	movs r1, 0x5
	b _080DBA52
	.pool
_080DBA34:
	movs r5, 0x2
	ldrsh r0, [r1, r5]
	movs r1, 0
	cmp r0, 0
	ble _080DBA52
	movs r1, 0x1
	cmp r0, 0x1D
	ble _080DBA52
	movs r1, 0x2
	cmp r0, 0x3B
	ble _080DBA52
	movs r1, 0x4
	cmp r0, 0x4F
	bgt _080DBA52
	movs r1, 0x3
_080DBA52:
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r0, r2, r0
	strb r1, [r0, 0x1A]
	adds r2, 0x1C
	subs r3, 0x1
	cmp r3, 0
	bge _080DBA20
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DBA18

	thumb_func_start sub_80DBA68
sub_80DBA68: @ 80DBA68
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r1, [r2, 0xC]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	bne _080DBA90
	ldrb r1, [r2, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080DBA98
_080DBA90:
	movs r0, 0
	b _080DBA9A
	.pool
_080DBA98:
	movs r0, 0x1
_080DBA9A:
	pop {r1}
	bx r1
	thumb_func_end sub_80DBA68

	thumb_func_start sub_80DBAA0
sub_80DBAA0: @ 80DBAA0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r5, =gUnknown_02039F34
	movs r0, 0
	mov r8, r0
	movs r1, 0x7
	negs r1, r1
	mov r10, r1
	movs r0, 0x2
	negs r0, r0
	mov r9, r0
	movs r4, 0
	movs r6, 0x3
_080DBAC0:
	ldr r1, [r5]
	ldr r0, [r1, 0x4]
	adds r0, r4, r0
	movs r2, 0
	strh r2, [r0, 0x2]
	ldr r0, [r1, 0x4]
	adds r0, r4, r0
	strh r2, [r0]
	ldr r0, [r1, 0x4]
	adds r0, r4, r0
	mov r1, r8
	strb r1, [r0, 0x12]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r3, r4, r0
	ldrb r2, [r3, 0xC]
	movs r0, 0x6
	ands r0, r2
	cmp r0, 0
	beq _080DBAFC
	lsls r0, r2, 29
	lsrs r0, 30
	subs r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 1
	mov r1, r10
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
_080DBAFC:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	mov r1, r8
	strb r1, [r0, 0xE]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x10]
	mov r0, r9
	ands r0, r2
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	mov r1, r8
	strb r1, [r0, 0xF]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x10]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x10]
	movs r7, 0x5
	negs r7, r7
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x10]
	movs r0, 0x9
	negs r0, r0
	mov r12, r0
	ands r0, r2
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0xC]
	mov r0, r9
	ands r0, r2
	strb r0, [r1, 0xC]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	movs r1, 0xFF
	strb r1, [r0, 0x13]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0, 0x14]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x10]
	movs r0, 0x31
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	ldr r2, [r0, 0x4]
	adds r2, r4, r2
	ldrb r3, [r2, 0x15]
	lsls r1, r3, 31
	lsrs r1, 31
	lsls r1, 2
	adds r0, r7, 0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x15]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	mov r0, r9
	ands r0, r2
	strb r0, [r1, 0x15]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x11]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x11]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x11]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x11]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r2, r4, r0
	ldrb r1, [r2, 0x11]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080DBBF4
	ldrb r1, [r2, 0xC]
	mov r0, r10
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x11]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1, 0x11]
_080DBBF4:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r2, r4, r0
	ldrb r1, [r2, 0x11]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080DBC1A
	ldrb r0, [r2, 0xB]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xB]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x11]
	mov r0, r12
	ands r0, r2
	strb r0, [r1, 0x11]
_080DBC1A:
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x11]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x11]
	adds r4, 0x1C
	subs r6, 0x1
	cmp r6, 0
	blt _080DBC34
	b _080DBAC0
_080DBC34:
	movs r6, 0
	ldr r5, =gUnknown_02039F34
	movs r7, 0
	movs r4, 0
_080DBC3C:
	ldr r3, [r5]
	ldr r0, [r3, 0x4]
	adds r0, r4, r0
	ldrh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	ldr r2, [r3]
	lsls r1, r6, 1
	ldrb r0, [r2, 0x1]
	lsls r0, 3
	adds r1, r0
	adds r2, 0x1C
	adds r2, r1
	ldr r0, [r3, 0x4]
	adds r0, r4, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r2]
	ldr r0, [r3, 0x4]
	adds r0, r4, r0
	ldrh r0, [r0, 0x6]
	bl sub_80DD9F0
	ldr r1, [r5]
	ldr r2, [r1]
	ldrb r1, [r2, 0x1]
	lsls r1, 2
	adds r1, r6, r1
	adds r2, 0x44
	adds r2, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	strh r7, [r0, 0x6]
	adds r4, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _080DBC3C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0x10]
	ldrb r1, [r2, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DBAA0

	thumb_func_start sub_80DBCA8
sub_80DBCA8: @ 80DBCA8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r1, [r2, 0xC]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	bne _080DBCD0
	ldrb r1, [r2, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080DBCD8
_080DBCD0:
	movs r0, 0x1
	b _080DBCDA
	.pool
_080DBCD8:
	movs r0, 0
_080DBCDA:
	pop {r1}
	bx r1
	thumb_func_end sub_80DBCA8

	thumb_func_start sub_80DBCE0
sub_80DBCE0: @ 80DBCE0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80DBD34
	ldr r1, =gUnknown_02039F18
	lsls r4, 1
	adds r1, r4, r1
	strh r0, [r1]
	ldr r2, =gUnknown_02039F08
	adds r2, r4, r2
	ldr r1, =gUnknown_02039F00
	adds r4, r1
	ldrh r4, [r4]
	adds r0, r4
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DBCE0

	thumb_func_start sub_80DBD18
sub_80DBD18: @ 80DBD18
	push {r4,lr}
	movs r4, 0
_080DBD1C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80DBCE0
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DBD1C
	bl sub_80DBD4C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DBD18

	thumb_func_start sub_80DBD34
sub_80DBD34: @ 80DBD34
	lsls r0, 24
	ldr r1, =gUnknown_02039F10
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 17
	asrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_80DBD34

	thumb_func_start sub_80DBD4C
sub_80DBD4C: @ 80DBD4C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x70
	mov r0, sp
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r0, 0
	mov r9, r0
	mov r1, sp
	adds r1, 0x8
	str r1, [sp, 0x64]
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x68]
	mov r6, sp
	adds r6, 0x14
	str r6, [sp, 0x6C]
	mov r4, sp
_080DBD7A:
	bl Random
	strh r0, [r4]
	movs r2, 0
	cmp r2, r9
	bge _080DBDB8
	mov r1, sp
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bne _080DBD9C
	subs r4, 0x2
	movs r7, 0x1
	negs r7, r7
	add r9, r7
	b _080DBDB8
_080DBD9C:
	adds r2, 0x1
	cmp r2, r9
	bge _080DBDB8
	lsls r0, r2, 1
	mov r3, sp
	adds r1, r3, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080DBD9C
	subs r4, 0x2
	movs r6, 0x1
	negs r6, r6
	add r9, r6
_080DBDB8:
	adds r4, 0x2
	movs r7, 0x1
	add r9, r7
	mov r0, r9
	cmp r0, 0x3
	ble _080DBD7A
	movs r1, 0
	mov r9, r1
	mov r4, sp
	ldr r6, =gUnknown_02039F08
	ldr r2, [sp, 0x64]
	ldr r5, =gUnknown_02039F00
	ldr r3, [sp, 0x68]
_080DBDD2:
	mov r7, r9
	lsls r1, r7, 4
	movs r7, 0
	ldrsh r0, [r6, r7]
	str r0, [r2]
	movs r7, 0
	ldrsh r0, [r5, r7]
	str r0, [r3]
	ldrh r0, [r4]
	str r0, [r2, 0x8]
	ldr r0, [sp, 0x6C]
	adds r1, r0, r1
	mov r7, r9
	str r7, [r1]
	adds r4, 0x2
	adds r6, 0x2
	adds r2, 0x10
	adds r5, 0x2
	adds r3, 0x10
	movs r0, 0x1
	add r9, r0
	mov r1, r9
	cmp r1, 0x3
	ble _080DBDD2
	movs r3, 0
	mov r9, r3
_080DBE06:
	movs r4, 0x3
	cmp r4, r9
	ble _080DBE90
	add r7, sp, 0x48
	ldr r6, [sp, 0x68]
	str r6, [sp, 0x58]
	ldr r0, [sp, 0x64]
	adds r0, 0x8
	str r0, [sp, 0x5C]
	ldr r1, [sp, 0x6C]
	str r1, [sp, 0x60]
_080DBE1C:
	subs r3, r4, 0x1
	mov r10, r3
	mov r0, r10
	adds r1, r4, 0
	ldr r2, [sp, 0x64]
	bl sub_80DBF30
	lsls r0, 24
	cmp r0, 0
	beq _080DBE8A
	mov r6, r10
	lsls r2, r6, 4
	ldr r0, [sp, 0x64]
	adds r3, r0, r2
	ldr r0, [r3]
	str r0, [sp, 0x48]
	ldr r1, [sp, 0x58]
	adds r6, r1, r2
	ldr r0, [r6]
	str r0, [r7, 0x4]
	ldr r0, [sp, 0x5C]
	adds r0, r2
	mov r8, r0
	ldr r0, [r0]
	str r0, [r7, 0x8]
	ldr r1, [sp, 0x60]
	adds r2, r1, r2
	ldr r0, [r2]
	str r0, [r7, 0xC]
	lsls r1, r4, 4
	ldr r0, [sp, 0x64]
	adds r5, r0, r1
	ldr r0, [r5]
	str r0, [r3]
	ldr r3, [sp, 0x58]
	adds r4, r3, r1
	ldr r0, [r4]
	str r0, [r6]
	ldr r6, [sp, 0x5C]
	adds r3, r6, r1
	ldr r0, [r3]
	mov r6, r8
	str r0, [r6]
	ldr r0, [sp, 0x60]
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [sp, 0x48]
	str r0, [r5]
	ldr r0, [r7, 0x4]
	str r0, [r4]
	ldr r0, [r7, 0x8]
	str r0, [r3]
	ldr r0, [r7, 0xC]
	str r0, [r1]
_080DBE8A:
	mov r4, r10
	cmp r4, r9
	bgt _080DBE1C
_080DBE90:
	movs r1, 0x1
	add r9, r1
	mov r3, r9
	cmp r3, 0x2
	ble _080DBE06
	movs r6, 0
	mov r9, r6
	ldr r2, =gUnknown_02039F20
	ldr r1, [sp, 0x6C]
_080DBEA2:
	ldr r0, [r1]
	adds r0, r2
	mov r7, r9
	strb r7, [r0]
	adds r1, 0x10
	movs r0, 0x1
	add r9, r0
	mov r3, r9
	cmp r3, 0x3
	ble _080DBEA2
	add sp, 0x70
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DBD4C

	thumb_func_start sub_80DBED4
sub_80DBED4: @ 80DBED4
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DBF0E
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_02039F20
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 1
	ldr r0, =gScriptContestCategory
	ldrh r0, [r0]
	lsls r0, 3
	adds r1, r0
	ldr r0, =0x00000624
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	adds r0, 0x1
	ldr r1, =0x0000270f
	cmp r0, r1
	ble _080DBF0C
	adds r0, r1, 0
_080DBF0C:
	strh r0, [r2]
_080DBF0E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DBED4

	thumb_func_start sub_80DBF30
sub_80DBF30: @ 80DBF30
	push {lr}
	lsls r0, 4
	adds r0, r2
	lsls r1, 4
	adds r3, r1, r2
	ldr r2, [r0]
	ldr r1, [r3]
	cmp r2, r1
	blt _080DBF60
	cmp r2, r1
	bgt _080DBF52
	ldr r2, [r0, 0x4]
	ldr r1, [r3, 0x4]
	cmp r2, r1
	blt _080DBF60
	cmp r2, r1
	ble _080DBF56
_080DBF52:
	movs r2, 0
	b _080DBF62
_080DBF56:
	ldr r1, [r0, 0x8]
	ldr r0, [r3, 0x8]
	movs r2, 0
	cmp r1, r0
	bge _080DBF62
_080DBF60:
	movs r2, 0x1
_080DBF62:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80DBF30

	thumb_func_start sub_80DBF68
sub_80DBF68: @ 80DBF68
	push {lr}
	ldr r0, =gBattle_BG0_Y
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	bl sub_80DB89C
	ldr r0, =gUnknown_0827E8DA
	movs r1, 0
	bl sub_80DEC30
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DBF68

	thumb_func_start sub_80DBF90
sub_80DBF90: @ 80DBF90
	push {r4,r5,lr}
	sub sp, 0xC
	movs r5, 0x80
	lsls r5, 18
	movs r4, 0x3
_080DBF9A:
	lsrs r3, r5, 24
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x16
	bl sub_80DED10
	movs r0, 0xA0
	lsls r0, 19
	adds r5, r0
	subs r4, 0x1
	cmp r4, 0
	bge _080DBF9A
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DBF90

	thumb_func_start sub_80DBFC8
sub_80DBFC8: @ 80DBFC8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x00005011
	cmp r0, 0
	beq _080DBFE2
	ldr r1, =0x00006011
	cmp r0, 0x1
	beq _080DBFE2
	ldr r1, =0x00008011
	cmp r0, 0x2
	bne _080DBFE2
	ldr r1, =0x00007011
_080DBFE2:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DBFC8

	thumb_func_start sub_80DBFFC
sub_80DBFFC: @ 80DBFFC
	push {lr}
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	lsrs r1, r0, 24
	asrs r2, r0, 24
	cmp r2, 0x10
	ble _080DC016
	movs r1, 0x10
	b _080DC020
_080DC016:
	movs r0, 0x10
	negs r0, r0
	cmp r2, r0
	bge _080DC020
	movs r1, 0xF0
_080DC020:
	lsls r0, r1, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80DBFFC

	thumb_func_start sub_80DC028
sub_80DC028: @ 80DC028
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x2]
	ldr r0, =sub_80DC0F4
	movs r1, 0x14
	bl CreateTask
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r5, 16
	asrs r5, 16
	adds r0, r5, 0
	bl sub_80DBFFC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 16
	asrs r6, 16
	adds r5, r6
	lsls r5, 16
	asrs r5, 16
	adds r0, r5, 0
	bl sub_80DBFFC
	lsls r4, 24
	asrs r4, 24
	subs r0, r4
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	bl sub_80DBFC8
	ldr r2, =gTasks
	lsls r3, r7, 2
	adds r0, r3, r7
	lsls r0, 3
	adds r1, r0, r2
	adds r0, r4, 0
	cmp r4, 0
	bge _080DC0A0
	negs r0, r4
_080DC0A0:
	strh r0, [r1, 0x8]
	lsls r0, r5, 24
	asrs r0, 24
	strh r0, [r1, 0xA]
	cmp r4, 0
	bgt _080DC0B4
	cmp r4, 0
	bne _080DC0C8
	cmp r0, 0
	ble _080DC0C8
_080DC0B4:
	movs r0, 0x1
	strh r0, [r1, 0xC]
	b _080DC0D6
	.pool
_080DC0C8:
	ldr r2, =gTasks
	lsls r3, r7, 2
	adds r0, r3, r7
	lsls r0, 3
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0xC]
_080DC0D6:
	adds r0, r3, r7
	lsls r0, 3
	adds r0, r2
	mov r1, r8
	strh r1, [r0, 0xE]
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DC028

	thumb_func_start sub_80DC0F4
sub_80DC0F4: @ 80DC0F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r4, r0, r1
	ldrb r0, [r4, 0xE]
	mov r9, r0
	ldrh r3, [r4, 0x8]
	ldrh r1, [r4, 0xA]
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bgt _080DC126
	b _080DC2A8
_080DC126:
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r2, [r4, 0xA]
	movs r5, 0xA
	ldrsh r0, [r4, r5]
	cmp r0, 0
	bne _080DC15C
	adds r0, r7, 0
	bl DestroyTask
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	mov r2, r9
	lsls r1, r2, 2
	adds r1, r0
	ldrb r2, [r1, 0x2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x2]
	b _080DC2A8
	.pool
_080DC15C:
	cmp r3, 0
	bne _080DC1A4
	lsls r0, r1, 16
	mov r8, r0
	cmp r0, 0
	bge _080DC17A
	mov r0, r9
	bl sub_80DBFC8
	adds r0, 0x2
	lsls r0, 16
	lsrs r6, r0, 16
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	b _080DC188
_080DC17A:
	mov r0, r9
	bl sub_80DBFC8
	lsls r0, 16
	lsrs r6, r0, 16
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
_080DC188:
	strh r0, [r4, 0xA]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r2, r1, 0x1
	strh r2, [r0, 0x8]
	lsls r1, 24
	lsrs r5, r1, 24
	b _080DC210
	.pool
_080DC1A4:
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bge _080DC1DE
	lsls r0, r1, 16
	mov r8, r0
	cmp r0, 0
	bge _080DC1CC
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r2, 0x1
	strh r0, [r4, 0xA]
	mov r0, r9
	bl sub_80DBFC8
	adds r0, 0x2
	b _080DC20C
_080DC1CC:
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	subs r0, r2, 0x1
	strh r0, [r4, 0xA]
	b _080DC210
_080DC1DE:
	lsls r0, r1, 16
	mov r8, r0
	cmp r0, 0
	bge _080DC1F8
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	adds r0, r2, 0x1
	strh r0, [r4, 0xA]
	b _080DC210
_080DC1F8:
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 24
	lsrs r5, r0, 24
	subs r0, r2, 0x1
	strh r0, [r4, 0xA]
	mov r0, r9
	bl sub_80DBFC8
_080DC20C:
	lsls r0, 16
	lsrs r6, r0, 16
_080DC210:
	str r5, [sp, 0xC]
	movs r0, 0
	mov r10, r0
	cmp r5, 0x7
	bls _080DC226
	movs r2, 0x1
	mov r10, r2
	adds r0, r5, 0
	subs r0, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
_080DC226:
	adds r2, r5, 0
	adds r2, 0x16
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_02039F26
	add r0, r9
	ldrb r0, [r0]
	lsls r3, r0, 2
	adds r3, r0
	adds r3, 0x2
	add r3, r10
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	adds r1, r6, 0
	bl sub_80DED10
	mov r3, r8
	cmp r3, 0
	ble _080DC284
	movs r0, 0x60
	bl PlaySE
	ldr r4, =gMPlay_SE1
	adds r0, r4, 0
	bl m4aMPlayImmInit
	ldr r1, =0x0000ffff
	ldr r0, [sp, 0xC]
	lsls r2, r0, 24
	asrs r2, 16
	adds r0, r4, 0
	bl m4aMPlayPitchControl
	b _080DC28A
	.pool
_080DC284:
	movs r0, 0x16
	bl PlaySE
_080DC28A:
	mov r2, r10
	cmp r2, 0
	bne _080DC2A8
	cmp r5, 0
	bne _080DC2A8
	cmp r6, 0
	bne _080DC2A8
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	negs r0, r0
	strh r0, [r1, 0xC]
_080DC2A8:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC0F4

	thumb_func_start sub_80DC2BC
sub_80DC2BC: @ 80DC2BC
	push {r4,r5,lr}
	ldr r0, =gUnknown_08587A74
	bl LoadSpriteSheet
	movs r4, 0
	ldr r5, =gUnknown_08587A6C
_080DC2C8:
	ldr r0, =gUnknown_02039F26
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r0, r5
	ldrb r2, [r0]
	ldr r0, =gUnknown_08587AD0
	movs r1, 0xB4
	movs r3, 0x1
	bl CreateSprite
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r2, [r1, 0x14]
	lsls r1, r4, 2
	adds r1, r2
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DC2C8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC2BC

	thumb_func_start sub_80DC308
sub_80DC308: @ 80DC308
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r2, [r0, 0x14]
	lsls r3, r6, 2
	adds r2, r3, r2
	ldrb r0, [r2, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r1, [r4]
	ldr r0, [r1, 0x14]
	adds r3, r0
	ldrb r7, [r3]
	ldr r1, [r1, 0x4]
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0xA
	bl __divsi3
	lsls r0, 17
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x38
	ble _080DC350
	movs r5, 0x38
	b _080DC356
	.pool
_080DC350:
	cmp r0, 0
	bge _080DC356
	movs r5, 0
_080DC356:
	ldr r2, =gSprites
	lsls r3, r7, 4
	adds r0, r3, r7
	lsls r0, 2
	adds r4, r0, r2
	movs r0, 0x3E
	adds r0, r4
	mov r12, r0
	ldrb r1, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	mov r1, r12
	strb r0, [r1]
	strh r6, [r4, 0x2E]
	strh r5, [r4, 0x30]
	lsls r0, r5, 16
	asrs r0, 16
	movs r5, 0x24
	ldrsh r1, [r4, r5]
	cmp r0, r1
	ble _080DC38C
	movs r0, 0x1
	b _080DC38E
	.pool
_080DC38C:
	ldr r0, =0x0000ffff
_080DC38E:
	strh r0, [r4, 0x32]
	adds r0, r3, r7
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80DC408
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC308

	thumb_func_start sub_80DC3AC
sub_80DC3AC: @ 80DC3AC
	push {r4,lr}
	movs r4, 0
_080DC3B0:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80DC308
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DC3B0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DC3AC

	thumb_func_start sub_80DC3C4
sub_80DC3C4: @ 80DC3C4
	push {r4,lr}
	movs r2, 0
	ldr r3, =gUnknown_02039F34
	ldr r0, [r3]
	ldr r0, [r0, 0x14]
	ldrb r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DC3F2
	movs r4, 0x1
_080DC3DA:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080DC3F2
	ldr r0, [r3]
	ldr r1, [r0, 0x14]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0, 0x2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080DC3DA
_080DC3F2:
	cmp r2, 0x4
	beq _080DC400
	movs r0, 0
	b _080DC402
	.pool
_080DC400:
	movs r0, 0x1
_080DC402:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80DC3C4

	thumb_func_start sub_80DC408
sub_80DC408: @ 80DC408
	push {r4,lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x24]
	movs r0, 0x24
	ldrsh r1, [r3, r0]
	movs r4, 0x30
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bne _080DC440
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	ldr r0, [r0, 0x14]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x2]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
	b _080DC446
	.pool
_080DC440:
	ldrh r0, [r3, 0x32]
	adds r0, r2, r0
	strh r0, [r3, 0x24]
_080DC446:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DC408

	thumb_func_start sub_80DC44C
sub_80DC44C: @ 80DC44C
	push {r4-r6,lr}
	movs r2, 0
	ldr r6, =gSprites
	ldr r5, =gUnknown_02039F34
	ldr r4, =gUnknown_08587A6C
	ldr r3, =gUnknown_02039F26
_080DC458:
	ldr r0, [r5]
	ldr r1, [r0, 0x14]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	strh r0, [r1, 0x22]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DC458
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC44C

	thumb_func_start sub_80DC490
sub_80DC490: @ 80DC490
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r3, 0
	ldr r7, =gUnknown_02039F26
	ldr r5, =gSprites
	ldr r4, =gUnknown_02039F34
	movs r2, 0
_080DC4A0:
	adds r0, r3, r7
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _080DC4E2
	cmp r6, 0
	bne _080DC4CC
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0xB4
	b _080DC4E0
	.pool
_080DC4CC:
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x80
	lsls r1, 1
_080DC4E0:
	strh r1, [r0, 0x20]
_080DC4E2:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DC4A0
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DC490

	thumb_func_start sub_80DC4F0
sub_80DC4F0: @ 80DC4F0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_08587B08
	bl LoadSpritePalette
	movs r5, 0
	ldr r7, =gUnknown_02039F34
	ldr r0, =gSprites
	mov r8, r0
	movs r6, 0
_080DC506:
	lsls r0, r5, 3
	ldr r1, =gUnknown_08587AE8
	adds r0, r1
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08587B18
	adds r0, r6, r0
	ldr r2, =gUnknown_08587A70
	ldr r1, =gUnknown_02039F26
	adds r1, r5, r1
	ldrb r1, [r1]
	adds r1, r2
	ldrb r2, [r1]
	movs r1, 0xCC
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	ldr r1, [r1, 0x14]
	lsls r4, r5, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1]
	ldr r0, [r7]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldr r1, =gUnknown_08587B80
	bl SetSubspriteTables
	ldr r0, [r7]
	ldr r0, [r0, 0x14]
	adds r4, r0
	ldrb r1, [r4, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r6, 0x18
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DC506
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC4F0

	thumb_func_start sub_80DC594
sub_80DC594: @ 80DC594
	push {lr}
	ldr r0, =gUnknown_08587BB0
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08587BB8
	bl LoadSpritePalette
	ldr r0, =gUnknown_08587BC8
	movs r1, 0x1E
	movs r2, 0x2C
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r3, 0x4
	orrs r2, r3
	strb r2, [r1]
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	adds r1, 0x58
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC594

	thumb_func_start sub_80DC5E8
sub_80DC5E8: @ 80DC5E8
	push {r4,lr}
	ldr r0, =sub_80DC728
	movs r1, 0x1E
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	strb r0, [r1, 0xD]
	movs r2, 0
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r4, =gTasks + 0x8
	movs r3, 0xFF
_080DC60A:
	lsls r0, r2, 3
	adds r0, r1
	adds r0, r4
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080DC60A
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC5E8

	thumb_func_start sub_80DC630
sub_80DC630: @ 80DC630
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	ldr r1, =gUnknown_02039F34
	ldr r5, [r1]
	ldr r1, [r5]
	ldrb r2, [r1, 0xD]
	lsls r1, r2, 2
	adds r1, r2
	adds r1, r0
	lsls r1, 3
	adds r3, 0x8
	adds r1, r3
	movs r4, 0
	strh r4, [r1]
	lsls r0, 2
	adds r0, 0x1
	lsls r0, 1
	ldr r1, [r5]
	ldrb r2, [r1, 0xD]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, r3
	strh r4, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC630

	thumb_func_start sub_80DC674
sub_80DC674: @ 80DC674
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80DC6A4
	movs r1, 0x1F
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
	thumb_func_end sub_80DC674

	thumb_func_start sub_80DC6A4
sub_80DC6A4: @ 80DC6A4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r2, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x8]
	adds r5, r0, 0
	ldr r0, =gUnknown_02039F34
	ldr r4, [r0]
	ldr r0, [r4]
	ldrb r1, [r0, 0xD]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r5
	lsls r0, 3
	adds r7, r2, 0
	adds r7, 0x8
	adds r1, r0, r7
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080DC6DC
	cmp r0, 0xFF
	bne _080DC716
_080DC6DC:
	movs r3, 0
	movs r0, 0xFF
	strh r0, [r1]
	lsls r1, r5, 2
	adds r1, 0x1
	lsls r1, 1
	ldr r0, [r4]
	ldrb r2, [r0, 0xD]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r7
	strh r3, [r1]
	ldr r0, [r4]
	adds r0, 0x14
	adds r0, r5
	ldrb r0, [r0]
	adds r0, 0x5
	lsls r0, 4
	adds r0, 0x6
	ldr r3, =0x00004bff
	movs r1, 0x2
	movs r2, 0
	bl BlendPalette
	adds r0, r6, 0
	bl DestroyTask
_080DC716:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC6A4

	thumb_func_start sub_80DC728
sub_80DC728: @ 80DC728
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0
	lsls r1, r0, 2
	adds r1, r0
	mov r9, r1
	lsls r7, r1, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	movs r1, 0x8
	negs r1, r1
	add r1, r8
	mov r10, r1
_080DC74C:
	lsls r0, r6, 26
	lsrs r3, r0, 24
	lsls r0, r3, 1
	adds r0, r7
	mov r4, r8
	adds r2, r0, r4
	ldrh r4, [r2]
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, 0xFF
	beq _080DC7CA
	adds r0, r3, 0x1
	lsls r1, r0, 1
	adds r1, r7
	add r1, r8
	movs r5, 0
	ldrsh r1, [r1, r5]
	adds r5, r0, 0
	cmp r1, 0
	bne _080DC77C
	adds r0, r4, 0x1
	b _080DC77E
	.pool
_080DC77C:
	subs r0, r4, 0x1
_080DC77E:
	strh r0, [r2]
	lsls r1, r3, 1
	mov r0, r9
	lsls r2, r0, 3
	adds r0, r1, r2
	mov r3, r10
	adds r3, 0x8
	adds r0, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r4, r1, 0
	cmp r0, 0x10
	beq _080DC79C
	cmp r0, 0
	bne _080DC7AA
_080DC79C:
	lsls r0, r5, 1
	adds r0, r2
	adds r0, r3
	ldrh r1, [r0]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0]
_080DC7AA:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x14
	adds r0, r6
	ldrb r0, [r0]
	adds r0, 0x5
	lsls r0, 4
	adds r0, 0x6
	adds r1, r4, r7
	add r1, r8
	ldrb r2, [r1]
	movs r1, 0x2
	ldr r3, =0x00004bff
	bl BlendPalette
_080DC7CA:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _080DC74C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC728

	thumb_func_start sub_80DC7EC
sub_80DC7EC: @ 80DC7EC
	push {r4,lr}
	ldr r0, =sub_80DC8D0
	movs r1, 0x1E
	bl CreateTask
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r1, [r1]
	strb r0, [r1, 0xE]
	movs r4, 0
_080DC800:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80DC81C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DC800
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC7EC

	thumb_func_start sub_80DC81C
sub_80DC81C: @ 80DC81C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	ldr r1, =gUnknown_02039F34
	ldr r4, [r1]
	ldr r1, [r4]
	ldrb r2, [r1, 0xE]
	lsls r1, r2, 2
	adds r1, r2
	adds r1, r0
	lsls r1, 3
	adds r3, 0x8
	adds r1, r3
	movs r5, 0
	movs r2, 0xFF
	strh r2, [r1]
	lsls r0, 2
	adds r0, 0x1
	lsls r0, 1
	ldr r1, [r4]
	ldrb r2, [r1, 0xE]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, r3
	strh r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC81C

	thumb_func_start sub_80DC864
sub_80DC864: @ 80DC864
	push {r4,lr}
	movs r4, 0
_080DC868:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80DC87C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DC868
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DC864

	thumb_func_start sub_80DC87C
sub_80DC87C: @ 80DC87C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80DC81C
	adds r0, r4, 0x5
	lsls r2, r0, 5
	ldr r3, =gPlttBufferUnfaded + 0x14
	adds r6, r2, r3
	ldr r5, =gPlttBufferFaded + 0x14
	adds r2, r5
	ldr r1, =0x040000d4
	str r6, [r1]
	str r2, [r1, 0x4]
	ldr r2, =0x80000001
	str r2, [r1, 0x8]
	ldr r6, [r1, 0x8]
	lsls r0, 4
	adds r4, 0xC
	adds r0, r4
	lsls r0, 1
	subs r3, 0x14
	adds r3, r0, r3
	subs r5, 0x14
	adds r0, r5
	str r3, [r1]
	str r0, [r1, 0x4]
	str r2, [r1, 0x8]
	ldr r0, [r1, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC87C

	thumb_func_start sub_80DC8D0
sub_80DC8D0: @ 80DC8D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	movs r7, 0
	lsls r1, r0, 2
	adds r1, r0
	mov r9, r1
	lsls r6, r1, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	ldr r1, =0x00004bff
	mov r10, r1
_080DC8F0:
	lsls r0, r7, 26
	lsrs r3, r0, 24
	lsls r0, r3, 1
	adds r0, r6
	mov r4, r8
	adds r2, r0, r4
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, 0xFF
	beq _080DC996
	adds r0, r3, 0x2
	lsls r0, 1
	adds r0, r6
	adds r1, r0, r4
	ldrh r0, [r1]
	adds r0, 0x1
	movs r4, 0
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080DC996
	strh r4, [r1]
	adds r0, r3, 0x1
	lsls r1, r0, 1
	adds r1, r6
	add r1, r8
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r4, r0, 0
	cmp r1, 0
	bne _080DC940
	ldrh r0, [r2]
	adds r0, 0x1
	b _080DC944
	.pool
_080DC940:
	ldrh r0, [r2]
	subs r0, 0x1
_080DC944:
	strh r0, [r2]
	lsls r1, r3, 1
	mov r5, r9
	lsls r2, r5, 3
	adds r0, r1, r2
	ldr r3, =gTasks
	adds r3, 0x8
	adds r0, r3
	movs r5, 0
	ldrsh r0, [r0, r5]
	adds r5, r1, 0
	cmp r0, 0x10
	beq _080DC962
	cmp r0, 0
	bne _080DC970
_080DC962:
	lsls r0, r4, 1
	adds r0, r2
	adds r0, r3
	ldrh r1, [r0]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0]
_080DC970:
	adds r4, r7, 0x5
	lsls r4, 4
	adds r0, r4, 0
	adds r0, 0xA
	adds r5, r6
	add r5, r8
	ldrb r2, [r5]
	movs r1, 0x1
	mov r3, r10
	bl BlendPalette
	adds r4, 0xC
	adds r4, r7
	ldrb r2, [r5]
	adds r0, r4, 0
	movs r1, 0x1
	mov r3, r10
	bl BlendPalette
_080DC996:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DC8F0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DC8D0

	thumb_func_start sub_80DC9B4
sub_80DC9B4: @ 80DC9B4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DC9E0
	adds r0, r2, 0
	bl sub_80DC630
	b _080DC9E6
	.pool
_080DC9E0:
	adds r0, r2, 0
	bl sub_80DC674
_080DC9E6:
	pop {r0}
	bx r0
	thumb_func_end sub_80DC9B4

	thumb_func_start sub_80DC9EC
sub_80DC9EC: @ 80DC9EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	ldr r6, =gUnknown_02039F26
	adds r6, r0, r6
	ldrb r0, [r6]
	lsls r5, r0, 2
	adds r5, r0
	lsls r5, 27
	movs r0, 0x80
	lsls r0, 22
	adds r5, r0
	lsrs r5, 24
	ldr r1, [sp, 0xC]
	lsls r4, r1, 3
	ldr r0, =gUnknown_08589904
	adds r0, r4, r0
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08589924
	adds r4, r0
	adds r0, r4, 0
	bl LoadSpritePalette
	ldr r2, [sp, 0xC]
	lsls r4, r2, 1
	adds r4, r2
	lsls r4, 3
	ldr r0, =gUnknown_0858998C
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB8
	adds r2, r5, 0
	movs r3, 0x1D
	bl CreateSprite
	mov r9, r0
	mov r3, r9
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	adds r0, r4, 0
	movs r1, 0xF8
	adds r2, r5, 0
	movs r3, 0x1D
	bl CreateSprite
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r5, r0, 4
	add r5, r8
	lsls r5, 2
	ldr r1, =gSprites
	adds r5, r1
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x40
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	movs r4, 0xC0
	lsls r4, 19
	ldrb r0, [r6]
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 6
	ldr r0, =0x0600e026
	adds r3, r0
	ldr r7, =gUnknown_02039F34
	ldr r0, [r7]
	ldr r0, [r0, 0x34]
	str r0, [sp]
	movs r0, 0
	movs r1, 0x3
	adds r2, r4, 0
	bl CopySpriteTiles
	ldrb r0, [r6]
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 6
	ldr r1, =0x0600e036
	adds r3, r1
	ldr r0, [r7]
	ldr r0, [r0, 0x38]
	str r0, [sp]
	movs r0, 0
	movs r1, 0x3
	adds r2, r4, 0
	bl CopySpriteTiles
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r0, [r7]
	ldr r1, [r0, 0x34]
	movs r6, 0xA0
	lsls r6, 3
	adds r1, r6
	ldr r2, =0x050000c0
	mov r10, r2
	add r0, sp, 0x4
	bl CpuSet
	str r4, [sp, 0x8]
	add r0, sp, 0x8
	ldr r1, [r7]
	ldr r1, [r1, 0x38]
	adds r1, r6
	mov r2, r10
	bl CpuSet
	ldr r0, [r7]
	ldr r0, [r0, 0x34]
	mov r3, r9
	lsls r4, r3, 4
	add r4, r9
	lsls r4, 2
	ldr r1, =gSprites
	adds r4, r1
	ldrh r1, [r4, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r6, =0x06010000
	adds r1, r6
	movs r2, 0x80
	lsls r2, 4
	mov r10, r2
	movs r3, 0x1
	bl RequestDma3Copy
	ldr r0, [r7]
	ldr r0, [r0, 0x38]
	ldrh r1, [r5, 0x4]
	lsls r1, 22
	lsrs r1, 17
	adds r1, r6
	mov r2, r10
	movs r3, 0x1
	bl RequestDma3Copy
	mov r3, r8
	strh r3, [r4, 0x2E]
	mov r0, r9
	strh r0, [r5, 0x2E]
	mov r1, sp
	ldrh r1, [r1, 0xC]
	strh r1, [r4, 0x30]
	mov r2, sp
	ldrh r2, [r2, 0xC]
	strh r2, [r5, 0x30]
	mov r0, r9
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DC9EC

	thumb_func_start sub_80DCB78
sub_80DCB78: @ 80DCB78
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	adds r5, r1
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r4, r1
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	adds r0, r5, 0
	bl DestroySpriteAndFreeResources
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCB78

	thumb_func_start sub_80DCBB4
sub_80DCBB4: @ 80DCBB4
	push {lr}
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000907
	movs r0, 0x52
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCBB4

	thumb_func_start sub_80DCBD0
sub_80DCBD0: @ 80DCBD0
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_80DCBD0

	thumb_func_start sub_80DCBE8
sub_80DCBE8: @ 80DCBE8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	mov r9, r1
	lsls r4, 24
	lsrs r4, 24
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	bl sub_80DCBB4
	ldr r0, =gUnknown_02039F34
	ldr r1, [r0]
	ldr r2, =gSprites
	mov r8, r2
	lsls r6, r4, 4
	adds r6, r4
	lsls r6, 2
	adds r0, r6, r2
	movs r3, 0x30
	ldrsh r2, [r0, r3]
	ldr r1, [r1, 0x14]
	lsls r2, 2
	adds r2, r1
	ldrb r1, [r2, 0x2]
	movs r3, 0x2
	orrs r1, r3
	strb r1, [r2, 0x2]
	ldrh r5, [r0, 0x2E]
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x1
	bl StartSpriteAffineAnim
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	mov r1, r8
	adds r0, r4, r1
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r2, 0x1C
	add r8, r2
	add r6, r8
	ldr r0, =sub_80DCC84
	str r0, [r6]
	add r4, r8
	ldr r0, =SpriteCallbackDummy
	str r0, [r4]
	mov r3, r9
	cmp r3, 0
	bne _080DCC70
	movs r0, 0x65
	bl PlaySE
	b _080DCC76
	.pool
_080DCC70:
	movs r0, 0x2
	bl PlaySE
_080DCC76:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80DCBE8

	thumb_func_start sub_80DCC84
sub_80DCC84: @ 80DCC84
	push {lr}
	mov r12, r0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080DCCCC
	mov r0, r12
	ldrh r1, [r0, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080DCCCC
	mov r3, r12
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =sub_80DCCD8
	mov r1, r12
	str r0, [r1, 0x1C]
_080DCCCC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCC84

	thumb_func_start sub_80DCCD8
sub_80DCCD8: @ 80DCCD8
	push {lr}
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	movs r3, 0x30
	ldrsh r2, [r0, r3]
	ldr r1, [r1, 0x14]
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x2]
	movs r1, 0x3
	negs r1, r1
	ands r1, r3
	strb r1, [r2, 0x2]
	ldrh r0, [r0, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80DCB78
	bl sub_80DCBD0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCCD8

	thumb_func_start sub_80DCD08
sub_80DCD08: @ 80DCD08
	push {lr}
	ldr r0, =0x02000000
	movs r1, 0xD0
	lsls r1, 9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _080DCD24
	movs r0, 0
	b _080DCD26
	.pool
_080DCD24:
	movs r0, 0x1
_080DCD26:
	strb r0, [r2]
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DCD3E
	bl sub_80DAEA4
	bl sub_80DB2BC
	b _080DCD42
_080DCD3E:
	bl sub_80DCD48
_080DCD42:
	pop {r0}
	bx r0
	thumb_func_end sub_80DCD08

	thumb_func_start sub_80DCD48
sub_80DCD48: @ 80DCD48
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_020322D5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DCE44
	ldr r0, =0x02000000
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DCE44
	cmp r0, 0
	blt _080DCD7C
	cmp r0, 0x3
	bgt _080DCD7C
	cmp r0, 0x2
	blt _080DCD7C
	bl sub_80DF750
	b _080DCE44
	.pool
_080DCD7C:
	movs r5, 0
_080DCD7E:
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080DCD7E
	movs r5, 0
_080DCD92:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	add r2, sp, 0x4
	ldrh r4, [r0, 0x4]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080DCDBC
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r2, 0
	ldr r1, =gText_OneDash
	bl StringCopy
	adds r2, r0, 0
_080DCDBC:
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x7
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x37
	movs r3, 0x1
	bl sub_80DEBD0
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080DCD92
	movs r5, 0
_080DCDEA:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	add r2, sp, 0x4
	ldrh r4, [r0, 0x2]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080DCE14
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r2, 0
	ldr r1, =gText_OneDash
	bl StringCopy
	adds r2, r0, 0
_080DCE14:
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x7
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x5
	movs r3, 0x1
	bl sub_80DEBD0
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080DCDEA
	bl sub_80DB2BC
_080DCE44:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCD48

	thumb_func_start sub_80DCE58
sub_80DCE58: @ 80DCE58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	add r4, sp, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r5, 0
	add r4, sp, 0x4
	adds r6, r4, 0
	movs r7, 0
_080DCE7E:
	bl Random
	adds r1, r0, 0
	mov r0, sp
	adds r0, r7
	adds r0, 0x4
	strh r1, [r0]
	movs r2, 0
	cmp r2, r5
	bge _080DCEB6
	lsls r0, r1, 16
	lsrs r0, 16
	mov r1, sp
	ldrh r1, [r1, 0x4]
	cmp r0, r1
	beq _080DCEB0
_080DCE9E:
	adds r2, 0x1
	cmp r2, r5
	bge _080DCEB6
	lsls r0, r2, 1
	adds r0, r4, r0
	ldrh r1, [r6]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080DCE9E
_080DCEB0:
	subs r6, 0x2
	subs r7, 0x2
	subs r5, 0x1
_080DCEB6:
	adds r6, 0x2
	adds r7, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCE7E
	mov r2, r8
	cmp r2, 0
	bne _080DCF80
	movs r5, 0
	ldr r3, =gUnknown_02039F26
	mov r8, r3
_080DCECC:
	mov r6, r8
	strb r5, [r6]
	movs r4, 0
	cmp r4, r5
	bge _080DCF48
	ldr r7, =gUnknown_02039F00
	mov r9, r7
	lsls r0, r5, 1
	adds r1, r0, 0
	add r1, r9
	mov r12, r1
	mov r2, sp
	adds r2, 0x4
	str r2, [sp, 0xC]
	add r0, sp
	adds r0, 0x4
	str r0, [sp, 0x10]
	ldr r3, =gUnknown_02039F26
	adds r6, r3, 0
	mov r10, r6
_080DCEF4:
	ldrb r0, [r3]
	lsls r2, r0, 1
	mov r7, r9
	adds r0, r2, r7
	movs r6, 0
	ldrsh r1, [r0, r6]
	mov r7, r12
	movs r6, 0
	ldrsh r0, [r7, r6]
	cmp r1, r0
	blt _080DCF1C
	cmp r1, r0
	bne _080DCF40
	ldr r7, [sp, 0xC]
	adds r0, r7, r2
	ldrh r0, [r0]
	ldr r1, [sp, 0x10]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _080DCF40
_080DCF1C:
	adds r2, r5, 0
	cmp r5, r4
	ble _080DCF34
	subs r0, r5, 0x1
	mov r6, r10
	adds r1, r0, r6
_080DCF28:
	ldrb r0, [r1]
	strb r0, [r1, 0x1]
	subs r1, 0x1
	subs r2, 0x1
	cmp r2, r4
	bgt _080DCF28
_080DCF34:
	strb r5, [r3]
	b _080DCF48
	.pool
_080DCF40:
	adds r3, 0x1
	adds r4, 0x1
	cmp r4, r5
	blt _080DCEF4
_080DCF48:
	cmp r4, r5
	bne _080DCF50
	mov r7, r8
	strb r5, [r7]
_080DCF50:
	movs r0, 0x1
	add r8, r0
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCECC
	ldr r4, =gUnknown_02039F26
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
	movs r5, 0
_080DCF68:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	adds r0, r4
	strb r5, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCF68
	b _080DD034
	.pool
_080DCF80:
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0x4
	bl memset
	movs r5, 0
	ldr r3, =gUnknown_02039F26
	movs r6, 0
_080DCF90:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r0, [r0, 0xB]
	lsls r0, 30
	lsrs r2, r0, 30
	mov r7, sp
	adds r1, r7, r2
	b _080DCFB6
	.pool
_080DCFAC:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	mov r0, sp
	adds r1, r0, r2
_080DCFB6:
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _080DCFAC
	strb r5, [r1]
	strb r2, [r3]
	adds r3, 0x1
	adds r6, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCF90
	movs r5, 0
_080DCFCC:
	movs r4, 0x3
	adds r1, r5, 0x1
	mov r10, r1
	cmp r4, r5
	ble _080DD02E
	mov r9, r4
	ldr r2, =gUnknown_02039F26
	mov r8, r2
	add r3, sp, 0x4
	mov r12, r3
_080DCFE0:
	ldr r6, =gUnknown_02039F34
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	adds r1, r0, 0
	subs r1, 0x1C
	ldrb r2, [r1, 0xB]
	ldrb r3, [r0, 0xB]
	mov r1, r9
	ands r1, r2
	mov r0, r9
	ands r0, r3
	subs r3, r4, 0x1
	cmp r1, r0
	bne _080DD028
	mov r0, r8
	adds r7, r3, r0
	adds r2, r4, r0
	ldrb r6, [r7]
	ldrb r1, [r2]
	cmp r6, r1
	bcs _080DD028
	lsls r0, r3, 1
	add r0, r12
	lsls r1, r4, 1
	add r1, r12
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _080DD028
	ldrb r0, [r2]
	strb r6, [r2]
	strb r0, [r7]
_080DD028:
	adds r4, r3, 0
	cmp r4, r5
	bgt _080DCFE0
_080DD02E:
	mov r5, r10
	cmp r5, 0x2
	ble _080DCFCC
_080DD034:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCE58

	thumb_func_start sub_80DD04C
sub_80DD04C: @ 80DD04C
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0xA0
_080DD052:
	ldr r0, =0x0201a004
	adds r0, r5, r0
	ldr r1, =gUnknown_02039F26
	adds r1, r4, r1
	ldrb r1, [r1]
	adds r1, 0x5
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	adds r5, 0x20
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD052
	bl sub_80DAEA4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD04C

	thumb_func_start sub_80DD080
sub_80DD080: @ 80DD080
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_02039F34
	ldr r3, [r4]
	ldr r1, [r3, 0x4]
	lsls r7, r6, 3
	subs r0, r7, r6
	lsls r5, r0, 2
	adds r1, r5, r1
	movs r2, 0
	strh r2, [r1, 0x2]
	ldr r0, [r3, 0x4]
	adds r0, r5, r0
	strh r2, [r0]
	adds r0, r6, 0
	bl sub_80DBA68
	lsls r0, 24
	mov r8, r4
	cmp r0, 0
	bne _080DD0B4
	b _080DD3C4
_080DD0B4:
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrh r0, [r1, 0x6]
	ldr r2, =gContestMoves
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0]
	mov r9, r2
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 29
	strb r0, [r1, 0xA]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r2, r5, r0
	ldrh r0, [r2, 0x6]
	ldrh r1, [r2, 0x8]
	cmp r0, r1
	bne _080DD110
	cmp r0, 0
	beq _080DD110
	ldrb r0, [r2, 0x15]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x15]
	ldr r0, [r4]
	ldr r2, [r0, 0x4]
	adds r2, r5, r2
	ldrb r3, [r2, 0xB]
	lsls r1, r3, 25
	lsrs r1, 29
	adds r1, 0x1
	movs r0, 0x7
	ands r1, r0
	lsls r1, 4
	movs r0, 0x71
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0xB]
	b _080DD12C
	.pool
_080DD110:
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	lsls r3, r6, 3
	subs r1, r3, r6
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0xB]
	movs r0, 0x71
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xB]
	mov r8, r4
	adds r7, r3, 0
_080DD12C:
	mov r2, r8
	ldr r4, [r2]
	ldr r2, [r4, 0x4]
	subs r0, r7, r6
	lsls r0, 2
	adds r2, r0, r2
	ldr r3, =gContestEffects
	mov r1, r9
	lsls r5, r1, 2
	adds r3, r5, r3
	ldrb r1, [r3, 0x1]
	strh r1, [r2]
	ldr r1, [r4, 0x4]
	adds r0, r1
	ldrh r1, [r0]
	strh r1, [r0, 0x2]
	ldr r1, [r4, 0x8]
	ldrb r0, [r3, 0x2]
	strh r0, [r1, 0x4]
	ldr r1, [r4, 0x8]
	ldrh r0, [r1, 0x4]
	strh r0, [r1, 0x6]
	ldr r0, [r4, 0x8]
	strb r6, [r0, 0x11]
	movs r2, 0
	mov r9, r5
	mov r4, r8
	movs r3, 0
	movs r1, 0
_080DD166:
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r0, r1, r0
	strb r3, [r0, 0xE]
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	adds r0, 0xD
	adds r0, r2
	strb r3, [r0]
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DD166
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r2, r4, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DD1B4
	ldrh r0, [r2, 0x8]
	ldrh r1, [r2, 0x6]
	bl AreMovesContestCombo
	lsls r0, 24
	cmp r0, 0
	bne _080DD1B4
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
_080DD1B4:
	ldr r0, =gContestEffectFunctionTable
	add r0, r9
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x10]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0x10
	bne _080DD1EC
	ldrh r1, [r2, 0x2]
	subs r1, 0xA
	movs r0, 0xD
	ldrsb r0, [r2, r0]
	b _080DD206
	.pool
_080DD1EC:
	ldrb r1, [r2, 0x11]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080DD200
	movs r1, 0xD
	ldrsb r1, [r2, r1]
	lsls r0, r1, 1
	adds r0, r1
	b _080DD204
_080DD200:
	movs r0, 0xD
	ldrsb r0, [r2, r0]
_080DD204:
	ldrh r1, [r2, 0x2]
_080DD206:
	adds r0, r1
	strh r0, [r2, 0x2]
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r1, r4, r1
	movs r0, 0
	strb r0, [r1, 0x16]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
	adds r0, r6, 0
	bl sub_80DE1E8
	lsls r0, 24
	cmp r0, 0
	beq _080DD2E2
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrh r0, [r1, 0x8]
	ldrh r1, [r1, 0x6]
	bl AreMovesContestCombo
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080DD29C
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r2, r4, r0
	ldrb r1, [r2, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DD29C
	strb r3, [r2, 0x16]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x15]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1, 0x15]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	movs r1, 0
	ldrsh r2, [r0, r1]
	ldrb r1, [r0, 0x16]
	muls r1, r2
	strb r1, [r0, 0x17]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x15]
	movs r2, 0x8
	b _080DD2C8
	.pool
_080DD29C:
	ldr r2, =gContestMoves
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r3, r4, r1
	ldrh r0, [r3, 0x6]
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _080DD2D8
	ldrb r0, [r3, 0x15]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r3, 0x15]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x15]
	movs r2, 0x40
_080DD2C8:
	orrs r0, r2
	strb r0, [r1, 0x15]
	b _080DD2E2
	.pool
_080DD2D8:
	ldrb r1, [r3, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x15]
_080DD2E2:
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r2, r4, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x1
	mov r8, r0
	ands r0, r1
	cmp r0, 0
	beq _080DD30A
	ldrb r0, [r2, 0xB]
	lsls r0, 25
	lsrs r0, 29
	adds r0, 0x1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	strb r1, [r2, 0x18]
_080DD30A:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r2, r4, r0
	ldrb r1, [r2, 0xC]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _080DD334
	ldrb r1, [r2, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
	ldr r2, [r5]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	strh r1, [r0]
_080DD334:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	ldrh r0, [r0, 0x6]
	bl sub_80DD9F0
	ldr r1, [r5]
	ldr r1, [r1, 0x10]
	strb r0, [r1]
	ldr r2, [r5]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldrb r1, [r0, 0x11]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DD35C
	ldr r0, [r2, 0x10]
	mov r1, r8
	strb r1, [r0]
_080DD35C:
	ldr r1, [r5]
	ldr r3, [r1, 0x10]
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0
	ble _080DD388
	ldr r0, [r1]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r3, r1]
	adds r0, r1
	cmp r0, 0x4
	ble _080DD384
	movs r0, 0x3C
	b _080DD38A
	.pool
_080DD384:
	movs r0, 0xA
	b _080DD38A
_080DD388:
	movs r0, 0
_080DD38A:
	strb r0, [r3, 0x2]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	b _080DD3AE
_080DD3A2:
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
_080DD3A8:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080DD3B6
_080DD3AE:
	cmp r2, r6
	beq _080DD3A8
	cmp r0, 0
	bne _080DD3A2
_080DD3B6:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x1B]
_080DD3C4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD080

	thumb_func_start sub_80DD3D4
sub_80DD3D4: @ 80DD3D4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02039F34
	ldr r2, [r2]
	ldr r3, [r2, 0x4]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r2, r3
	strb r1, [r2, 0x13]
	bx lr
	.pool
	thumb_func_end sub_80DD3D4

	thumb_func_start sub_80DD3F0
sub_80DD3F0: @ 80DD3F0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02039F34
	ldr r2, [r2]
	ldr r3, [r2, 0x4]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r2, r3
	strb r1, [r2, 0x14]
	bx lr
	.pool
	thumb_func_end sub_80DD3F0

	thumb_func_start sub_80DD40C
sub_80DD40C: @ 80DD40C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0x3B
	bls _080DD426
	movs r1, 0x35
	bl sub_80DD3D4
	b _080DD456
_080DD426:
	cmp r1, 0x27
	bls _080DD432
	movs r1, 0x34
	bl sub_80DD3D4
	b _080DD456
_080DD432:
	cmp r1, 0x1D
	bls _080DD43E
	movs r1, 0x33
	bl sub_80DD3D4
	b _080DD456
_080DD43E:
	cmp r1, 0x13
	bls _080DD44A
	movs r1, 0x32
	bl sub_80DD3D4
	b _080DD456
_080DD44A:
	cmp r2, 0x9
	bls _080DD456
	adds r0, r3, 0
	movs r1, 0x31
	bl sub_80DD3D4
_080DD456:
	pop {r0}
	bx r0
	thumb_func_end sub_80DD40C

	thumb_func_start sub_80DD45C
sub_80DD45C: @ 80DD45C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r0, =gStringVar1
	lsls r1, r4, 6
	ldr r2, =gUnknown_02039E02
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r5, =gUnknown_02039F34
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x6]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r3, =gContestMoves
	ldr r1, [r5]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 29
	cmp r1, 0
	bne _080DD4DC
	ldr r0, =gStringVar3
	ldr r1, =gUnknown_0827E837
	bl StringCopy
	b _080DD52C
	.pool
_080DD4DC:
	lsrs r0, r1, 29
	cmp r0, 0x1
	bne _080DD4F4
	ldr r0, =gStringVar3
	ldr r1, =gUnknown_0827E83F
	bl StringCopy
	b _080DD52C
	.pool
_080DD4F4:
	lsrs r0, r1, 29
	cmp r0, 0x2
	bne _080DD50C
	ldr r0, =gStringVar3
	ldr r1, =gUnknown_0827E847
	bl StringCopy
	b _080DD52C
	.pool
_080DD50C:
	lsrs r0, r1, 29
	cmp r0, 0x3
	bne _080DD524
	ldr r0, =gStringVar3
	ldr r1, =gUnknown_0827E850
	bl StringCopy
	b _080DD52C
	.pool
_080DD524:
	ldr r0, =gStringVar3
	ldr r1, =gUnknown_0827E85A
	bl StringCopy
_080DD52C:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_08587E10
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringExpandPlaceholders
	bl sub_80DB89C
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80DEC30
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD45C

	thumb_func_start sub_80DD560
sub_80DD560: @ 80DD560
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_02039F34
	ldr r1, [r4]
	ldr r3, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r3, r1, r3
	ldrb r0, [r3, 0xC]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r3, 0xC]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD560

	thumb_func_start sub_80DD590
sub_80DD590: @ 80DD590
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	movs r0, 0
	mov r12, r0
	movs r4, 0
	ldr r1, =gUnknown_02039F26
	mov r9, r1
	add r2, sp, 0x4
	mov r6, r9
	movs r5, 0
	adds r3, r2, 0
_080DD5AC:
	mov r0, sp
	adds r1, r0, r4
	adds r0, r4, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r4
	strb r5, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD5AC
	movs r4, 0
	ldr r7, =gUnknown_02039F34
	ldr r1, [r7]
	mov r8, r1
	adds r5, r2, 0
_080DD5CA:
	movs r2, 0
	mov r0, r8
	ldr r1, [r0, 0x4]
_080DD5D0:
	ldrb r0, [r1, 0x19]
	cmp r0, r4
	beq _080DD604
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DD5D0
_080DD5DE:
	cmp r2, 0x4
	bne _080DD684
	movs r2, 0
	ldrb r0, [r5]
	cmp r0, 0
	bne _080DD612
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	ldrb r0, [r0, 0x19]
	cmp r0, 0xFF
	bne _080DD612
	mov r12, r2
	movs r2, 0x1
	b _080DD63A
	.pool
_080DD604:
	mov r1, sp
	adds r0, r1, r2
	strb r4, [r0]
	adds r1, r5, r2
	movs r0, 0x1
	strb r0, [r1]
	b _080DD5DE
_080DD612:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080DD676
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DD612
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x19]
	cmp r0, 0xFF
	bne _080DD612
	lsls r0, r2, 24
	lsrs r0, 24
	mov r12, r0
	adds r2, 0x1
_080DD63A:
	cmp r2, 0x3
	bgt _080DD676
	ldr r6, =gUnknown_02039F26
	lsls r0, r2, 3
	subs r0, r2
	lsls r3, r0, 2
_080DD646:
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DD66E
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r0, r3, r0
	ldrb r0, [r0, 0x19]
	cmp r0, 0xFF
	bne _080DD66E
	mov r1, r12
	adds r0, r1, r6
	adds r1, r2, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080DD66E
	lsls r0, r2, 24
	lsrs r0, 24
	mov r12, r0
_080DD66E:
	adds r3, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DD646
_080DD676:
	mov r0, sp
	add r0, r12
	strb r4, [r0]
	mov r0, r12
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080DD684:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD5CA
	movs r4, 0
	ldr r6, =gUnknown_02039F34
	movs r5, 0
_080DD690:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	adds r1, r4
	mov r0, sp
	adds r3, r0, r4
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r5, r0
	movs r1, 0xFF
	strb r1, [r0, 0x19]
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrb r2, [r1, 0x10]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x10]
	mov r0, r9
	adds r1, r4, r0
	ldrb r0, [r3]
	strb r0, [r1]
	adds r5, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD690
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD590

	thumb_func_start sub_80DD6DC
sub_80DD6DC: @ 80DD6DC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0x1
	strh r1, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x54
	ble _080DD712
	movs r0, 0
	strh r0, [r2, 0x30]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
_080DD712:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD6DC

	thumb_func_start sub_80DD720
sub_80DD720: @ 80DD720
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r5, [r0, 0x12]
	cmp r1, 0x8
	bls _080DD734
	b _080DD8D4
_080DD734:
	lsls r0, r1, 2
	ldr r1, =_080DD748
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DD748:
	.4byte _080DD76C
	.4byte _080DD76C
	.4byte _080DD79C
	.4byte _080DD7D0
	.4byte _080DD804
	.4byte _080DD838
	.4byte _080DD86C
	.4byte _080DD8D4
	.4byte _080DD8A0
_080DD76C:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x2E]
	ldr r2, =0x000003ff
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x20
	bl PlaySE
	b _080DD8F8
	.pool
_080DD79C:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x4
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x1F
	bl PlaySE
	b _080DD8F8
	.pool
_080DD7D0:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x8
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x1F
	bl PlaySE
	b _080DD8F8
	.pool
_080DD804:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0xC
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
	b _080DD8F8
	.pool
_080DD838:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0xC
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
	b _080DD8F8
	.pool
_080DD86C:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
	b _080DD8F8
	.pool
_080DD8A0:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x18
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0xC3
	bl PlaySE
	b _080DD8F8
	.pool
_080DD8D4:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x14
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
_080DD8F8:
	adds r2, r4, 0
	ldr r4, =gSprites
	adds r2, r5
	lsls r2, 2
	adds r1, r2, r4
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r1, 0x3E
	ldrb r3, [r1]
	subs r0, 0x5
	ands r0, r3
	strb r0, [r1]
	adds r4, 0x1C
	adds r2, r4
	ldr r0, =sub_80DD6DC
	str r0, [r2]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD720

	thumb_func_start sub_80DD940
sub_80DD940: @ 80DD940
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	ldr r6, =gUnknown_02039F34
	ldr r0, =gSprites
	mov r9, r0
	ldr r0, =0x06010000
	mov r8, r0
	ldr r7, =0x04000008
_080DD956:
	ldr r0, [r6]
	ldr r1, [r0]
	movs r0, 0x13
	ldrsb r0, [r1, r0]
	ldr r4, =gUnknown_08D8EC24
	cmp r5, r0
	bge _080DD966
	adds r4, 0x40
_080DD966:
	adds r0, r1, 0
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r0, r5, 0
	adds r0, 0x11
	adds r1, r0
	lsls r1, 5
	add r1, r8
	adds r0, r4, 0
	adds r2, r7, 0
	bl CpuSet
	adds r0, r4, 0
	adds r0, 0x20
	ldr r1, [r6]
	ldr r1, [r1]
	adds r1, 0x58
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r9
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r2, r5, 0
	adds r2, 0x19
	adds r1, r2
	lsls r1, 5
	add r1, r8
	adds r2, r7, 0
	bl CpuSet
	ldr r0, [r6]
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	ble _080DD9C8
	bl sub_80DDA20
_080DD9C8:
	adds r5, 0x1
	cmp r5, 0x4
	ble _080DD956
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD940

	thumb_func_start sub_80DD9F0
sub_80DD9F0: @ 80DD9F0
	lsls r0, 16
	ldr r3, =gUnknown_085899EC
	ldr r1, =gContestMoves
	lsrs r0, 13
	adds r0, r1
	ldrb r1, [r0, 0x1]
	lsls r1, 29
	lsrs r1, 29
	ldr r0, =gScriptContestCategory
	ldrh r2, [r0]
	lsls r0, r2, 2
	adds r0, r2
	adds r1, r0
	adds r1, r3
	movs r0, 0
	ldrsb r0, [r1, r0]
	bx lr
	.pool
	thumb_func_end sub_80DD9F0

	thumb_func_start sub_80DDA20
sub_80DDA20: @ 80DDA20
	push {r4,r5,lr}
	ldr r0, =c3_08130B10
	movs r1, 0xA
	bl CreateTask
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0x1
	strh r0, [r4, 0xA]
	ldr r0, =0x0000abe2
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DDA20

	thumb_func_start c3_08130B10
c3_08130B10: @ 80DDA60
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _080DDAFE
	movs r0, 0
	strh r0, [r2, 0x8]
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _080DDA94
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	b _080DDA98
	.pool
_080DDA94:
	ldrh r0, [r2, 0x10]
	subs r0, 0x1
_080DDA98:
	strh r0, [r2, 0x10]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	lsls r0, 4
	movs r3, 0x84
	lsls r3, 1
	adds r6, r3, 0
	adds r0, r6
	lsls r0, 16
	lsrs r0, 16
	ldrb r2, [r4, 0x10]
	ldr r3, =0x00007fff
	movs r1, 0x1
	bl BlendPalette
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080DDACA
	cmp r0, 0x10
	bne _080DDAFE
_080DDACA:
	ldrh r0, [r4, 0xE]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0xE]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bgt _080DDAFE
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 4
	adds r0, r6
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1F
	bl BlendPalette
	adds r0, r5, 0
	bl DestroyTask
_080DDAFE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_08130B10

	thumb_func_start sub_80DDB0C
sub_80DDB0C: @ 80DDB0C
	push {r4,lr}
	ldr r0, =sub_80DDB6C
	movs r1, 0xA
	bl CreateTask
	ldr r3, =gSprites
	ldr r4, =gUnknown_02039F34
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r1, =0x0000ffba
	strh r1, [r0, 0x24]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDB0C

	thumb_func_start sub_80DDB6C
sub_80DDB6C: @ 80DDB6C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	movs r5, 0xD0
	lsls r5, 3
	adds r0, r5, 0
	ldrh r5, [r1, 0x1C]
	adds r0, r5
	strh r0, [r1, 0x1C]
	lsls r0, 16
	asrs r0, 24
	ldrh r5, [r2, 0x24]
	adds r0, r5
	strh r0, [r2, 0x24]
	ldrb r0, [r1, 0x1C]
	strh r0, [r1, 0x1C]
	movs r1, 0x24
	ldrsh r0, [r2, r1]
	cmp r0, 0
	ble _080DDBB8
	movs r0, 0
	strh r0, [r2, 0x24]
_080DDBB8:
	movs r5, 0x24
	ldrsh r0, [r2, r5]
	cmp r0, 0
	bne _080DDBD4
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r3, 0
	bl DestroyTask
_080DDBD4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDB6C

	thumb_func_start sub_80DDBE8
sub_80DDBE8: @ 80DDBE8
	push {r4,r5,lr}
	ldr r5, =gSprites
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080DDC1C
	ldrb r1, [r2, 0x6]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	b _080DDC40
	.pool
_080DDC1C:
	ldr r0, =task08_080CD1CC
	movs r1, 0xA
	bl CreateTask
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r2, [r2]
	ldrb r0, [r2, 0x6]
	movs r1, 0x40
	orrs r0, r1
_080DDC40:
	strb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDBE8

	thumb_func_start task08_080CD1CC
task08_080CD1CC: @ 80DDC4C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	ldr r0, =gTasks
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	adds r2, r0
	movs r1, 0xD0
	lsls r1, 3
	adds r0, r1, 0
	ldrh r1, [r2, 0x1C]
	adds r0, r1
	strh r0, [r2, 0x1C]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r3, 0x24]
	subs r1, r0
	strh r1, [r3, 0x24]
	ldrb r0, [r2, 0x1C]
	strh r0, [r2, 0x1C]
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	movs r1, 0x46
	negs r1, r1
	cmp r0, r1
	bge _080DDC9C
	ldr r0, =0x0000ffba
	strh r0, [r3, 0x24]
_080DDC9C:
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	cmp r0, r1
	bne _080DDCC4
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r4, 0
	bl DestroyTask
_080DDCC4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task08_080CD1CC

	thumb_func_start sub_80DDCDC
sub_80DDCDC: @ 80DDCDC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80DDD20
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0x8]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDCDC

	thumb_func_start sub_80DDD20
sub_80DDD20: @ 80DDD20
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080DDD54
	cmp r0, 0x1
	bgt _080DDD48
	cmp r0, 0
	beq _080DDD4E
	b _080DDD9C
	.pool
_080DDD48:
	cmp r0, 0x2
	beq _080DDD70
	b _080DDD9C
_080DDD4E:
	bl sub_80DDB0C
	b _080DDD64
_080DDD54:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080DDD9C
_080DDD64:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	b _080DDD9C
	.pool
_080DDD70:
	ldrh r0, [r4, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080DDD9C
	movs r0, 0
	strh r0, [r4, 0x1E]
	bl sub_80DD940
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r5, 0
	bl DestroyTask
_080DDD9C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDD20

	thumb_func_start sub_80DDDA8
sub_80DDDA8: @ 80DDDA8
	ldr r3, =gSprites
	ldr r0, =gUnknown_02039F34
	ldr r2, [r0]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80DDDA8

	thumb_func_start sub_80DDDE4
sub_80DDDE4: @ 80DDDE4
	ldr r2, =gSprites
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80DDDE4

	thumb_func_start sub_80DDE0C
sub_80DDE0C: @ 80DDE0C
	push {lr}
	ldr r0, =sub_80DDE30
	movs r1, 0xF
	bl CreateTask
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDE0C

	thumb_func_start sub_80DDE30
sub_80DDE30: @ 80DDE30
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _080DDEBA
	movs r0, 0
	strh r0, [r4, 0x1C]
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080DDE78
	ldr r0, =0x02019000
	ldr r1, =0x06002000
	movs r2, 0x80
	lsls r2, 5
	movs r3, 0x1
	bl RequestDma3Copy
	b _080DDE8C
	.pool
_080DDE78:
	ldr r0, =0x02018000
	ldr r1, =0x06002000
	movs r2, 0x80
	lsls r2, 5
	movs r3, 0x1
	bl RequestDma3Copy
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
_080DDE8C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x1E]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0, 0x1E]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	bne _080DDEBA
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r5, 0
	bl DestroyTask
_080DDEBA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDE30

	thumb_func_start sub_80DDED0
sub_80DDED0: @ 80DDED0
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =sub_80DDF80
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, 24
	cmp r4, 0
	ble _080DDF38
	ldr r7, =0x0000237e
	lsls r0, r5, 24
	adds r4, r0, 0
	cmp r4, 0
	ble _080DDF1C
	movs r5, 0
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, 0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	b _080DDF4E
	.pool
_080DDF1C:
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, 0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	b _080DDF4E
	.pool
_080DDF38:
	movs r7, 0
	lsls r0, r5, 24
	adds r4, r0, 0
	cmp r4, 0
	ble _080DDF48
	movs r5, 0
	movs r3, 0xC
	b _080DDF4C
_080DDF48:
	movs r5, 0xC
	movs r3, 0
_080DDF4C:
	ldr r2, =gUnknown_02039F34
_080DDF4E:
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r7, [r0, 0x8]
	strh r5, [r0, 0xA]
	asrs r1, r4, 24
	strh r1, [r0, 0xC]
	strh r3, [r0, 0xE]
	ldr r0, [r2]
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDED0

	thumb_func_start sub_80DDF80
sub_80DDF80: @ 80DDF80
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r3, 0x1C]
	lsls r0, 16
	cmp r0, 0
	blt _080DDFFC
	movs r0, 0
	strh r0, [r3, 0x1C]
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	cmp r0, 0
	ble _080DDFB4
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	b _080DDFB8
	.pool
_080DDFB4:
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
_080DDFB8:
	strh r0, [r3, 0xA]
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r2
	ldrb r2, [r4, 0xA]
	ldrh r3, [r4, 0x8]
	movs r0, 0x11
	movs r1, 0x1
	bl BlendPalette
	ldrb r2, [r4, 0xA]
	ldrh r3, [r4, 0x8]
	movs r0, 0x1A
	movs r1, 0x1
	bl BlendPalette
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _080DDFFC
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
_080DDFFC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDF80

	thumb_func_start sub_80DE008
sub_80DE008: @ 80DE008
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r5, 0
	ldr r0, =gUnknown_02039F34
	mov r9, r0
	mov r8, r9
	ldr r6, =gSprites
	movs r4, 0
	movs r7, 0
_080DE026:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r7, r0
	ldrb r1, [r0, 0x10]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _080DE0BC
	mov r2, r10
	cmp r2, 0
	beq _080DE0BC
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80DE0F0
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1, 0x14]
	adds r1, r4, r1
	ldrb r2, [r1, 0x1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r2, =0x060100c0
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	mov r0, r8
	ldr r3, [r0]
	ldr r0, [r3, 0x14]
	adds r0, r4, r0
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldr r2, =gUnknown_08587A70
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1, 0x22]
	ldr r0, [r3, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	b _080DE0D6
	.pool
_080DE0BC:
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_080DE0D6:
	strb r1, [r0]
	adds r4, 0x4
	adds r7, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DE026
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DE008

	thumb_func_start sub_80DE0F0
sub_80DE0F0: @ 80DE0F0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r1, [r2, 0x10]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	bne _080DE120
	ldrb r0, [r2, 0x19]
	lsls r0, 5
	ldr r1, =gUnknown_08D8E9B4
	adds r0, r1
	b _080DE122
	.pool
_080DE120:
	ldr r0, =gUnknown_08D8EA34
_080DE122:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DE0F0

	thumb_func_start sub_80DE12C
sub_80DE12C: @ 80DE12C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	movs r7, 0
	movs r0, 0x2
	mov r10, r0
	movs r0, 0x1
	mov r8, r0
	movs r0, 0x11
	mov r9, r0
_080DE146:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0xD
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DE1CA
	lsls r0, r7, 24
	lsrs r0, 24
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	bne _080DE1CA
	ldr r0, =gUnknown_02039F26
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r5, r0, 2
	adds r5, r0
	adds r6, r5, 0x2
	movs r0, 0x3
	bl sub_80DB748
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r6, 24
	lsrs r6, 24
	mov r0, r10
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x14
	adds r3, r6, 0
	bl sub_80DECB8
	adds r4, 0x10
	lsls r4, 16
	lsrs r4, 16
	adds r5, 0x3
	lsls r5, 24
	lsrs r5, 24
	mov r0, r10
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x14
	adds r3, r5, 0
	bl sub_80DECB8
	movs r0, 0x63
	bl PlaySE
_080DE1CA:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080DE146
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE12C

	thumb_func_start sub_80DE1E8
sub_80DE1E8: @ 80DE1E8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r1, [r2, 0x15]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080DE212
	ldrb r1, [r2, 0xC]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080DE21C
_080DE212:
	movs r0, 0
	b _080DE21E
	.pool
_080DE21C:
	movs r0, 0x1
_080DE21E:
	pop {r1}
	bx r1
	thumb_func_end sub_80DE1E8

	thumb_func_start sub_80DE224
sub_80DE224: @ 80DE224
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	movs r0, 0xA
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	ldrb r1, [r2]
	movs r4, 0x4
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r2, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r1, [r2, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x1]
	ldrb r1, [r2]
	movs r0, 0xD
	negs r0, r0
	mov r8, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, 0xA
	bl SetGpuReg
	movs r0, 0x8
	bl GetGpuReg
	mov r6, sp
	adds r6, 0x2
	strh r0, [r6]
	movs r0, 0xC
	bl GetGpuReg
	add r5, sp, 0x4
	strh r0, [r5]
	ldrb r1, [r6]
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r5]
	ands r4, r0
	orrs r4, r1
	strb r4, [r5]
	ldrh r1, [r6]
	movs r0, 0x8
	bl SetGpuReg
	ldrh r1, [r5]
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =gBattle_BG1_X
	movs r0, 0xF0
	strh r0, [r1]
	ldr r4, =gBattle_BG1_Y
	movs r0, 0xA0
	strh r0, [r4]
	movs r0, 0x14
	movs r1, 0xF0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	movs r0, 0
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	ldr r4, =gUnknown_02039F34
	ldr r1, [r4]
	ldr r1, [r1, 0x28]
	ldr r2, =0x05000400
	bl CpuSet
	ldr r1, =gUnknown_08C17980
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl sub_80DED60
	movs r5, 0
	ldr r7, =gSprites
	movs r6, 0x4
_080DE2F0:
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	lsls r3, r5, 2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, 0x5]
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	adds r3, r0
	ldrb r0, [r3, 0x1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, 0x5]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DE2F0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE224

	thumb_func_start sub_80DE350
sub_80DE350: @ 80DE350
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, =0x06008000
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	movs r5, 0
	str r5, [sp]
	ldr r6, =gUnknown_02039F34
	ldr r0, [r6]
	ldr r1, [r0, 0x28]
	ldr r2, =0x05000400
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	bl sub_80DED60
	movs r0, 0xA
	bl GetGpuReg
	add r3, sp, 0x4
	strh r0, [r3]
	ldrb r1, [r3]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r3]
	mov r1, sp
	adds r1, 0x5
	ldrb r2, [r1]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r3]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r3]
	ldrh r1, [r3]
	movs r0, 0xA
	bl SetGpuReg
	ldr r0, =gBattle_BG1_X
	strh r5, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r5, [r0]
	ldr r7, =gSprites
_080DE3CA:
	ldr r0, [r6]
	ldr r0, [r0, 0x14]
	lsls r3, r5, 2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r6]
	ldr r0, [r0, 0x14]
	adds r3, r0
	ldrb r0, [r3, 0x1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x5]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DE3CA
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE350

	thumb_func_start sub_80DE424
sub_80DE424: @ 80DE424
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gBattle_BG1_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG1_Y
	movs r0, 0xA0
	strh r0, [r1]
	movs r0, 0x62
	movs r1, 0
	bl PlaySE12WithPanning
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80DE464
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE424

	thumb_func_start sub_80DE464
sub_80DE464: @ 80DE464
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	subs r0, 0x7
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bge _080DE47C
	movs r0, 0
	strh r0, [r1]
_080DE47C:
	ldrh r2, [r1]
	cmp r2, 0
	bne _080DE496
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0x8]
	strh r2, [r1, 0xA]
	strh r2, [r1, 0xC]
	ldr r0, =sub_80DE4A8
	str r0, [r1]
_080DE496:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE464

	thumb_func_start sub_80DE4A8
sub_80DE4A8: @ 80DE4A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r3, r4, 2
	adds r0, r3, r4
	lsls r0, 3
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0x1
	beq _080DE52C
	cmp r1, 0x1
	bgt _080DE4D0
	cmp r1, 0
	beq _080DE4DA
	b _080DE5B4
	.pool
_080DE4D0:
	cmp r1, 0x2
	beq _080DE58A
	cmp r1, 0x3
	beq _080DE5A4
	b _080DE5B4
_080DE4DA:
	movs r2, 0
	adds r6, r3, 0
	ldr r5, =gUnknown_02039F34
	ldr r3, =gUnknown_02039F26
_080DE4E2:
	ldr r0, [r5]
	ldr r1, [r0]
	adds r1, 0x14
	adds r1, r2
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DE4E2
	bl sub_80DBF90
	bl sub_80DC864
	bl sub_80DB69C
	bl sub_80DD04C
	movs r0, 0x1
	bl sub_80DE008
	bl sub_80DC44C
	ldr r0, =gTasks
	adds r1, r6, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x8]
	b _080DE5B4
	.pool
_080DE52C:
	ldr r0, =gUnknown_02039F2A
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _080DE584
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x7]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x7]
	bl sub_80DA8A4
	lsls r0, 24
	cmp r0, 0
	beq _080DE552
	bl sub_80DBAA0
_080DE552:
	ldr r4, =sub_80FCC88
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sub_80DA110
	adds r1, r4, 0
	bl SetTaskFuncWithFollowupFunc
	bl sub_80DBF68
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080DE5B4
	.pool
_080DE584:
	bl sub_80DBAA0
	b _080DE59A
_080DE58A:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080DE5B4
_080DE59A:
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080DE5B4
	.pool
_080DE5A4:
	bl sub_80DB884
	bl sub_80DB2BC
	movs r0, 0
	strh r0, [r5, 0x8]
	ldr r0, =sub_80DE5F4
	str r0, [r5]
_080DE5B4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE4A8

	thumb_func_start sub_80DE5C0
sub_80DE5C0: @ 80DE5C0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	adds r0, 0x7
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA0
	ble _080DE5E4
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80DA4F4
	str r0, [r1]
_080DE5E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE5C0

	thumb_func_start sub_80DE5F4
sub_80DE5F4: @ 80DE5F4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0x9
	bgt _080DE618
	adds r0, r2, 0x1
	strh r0, [r1, 0xC]
	b _080DE654
	.pool
_080DE618:
	ldrh r3, [r1, 0xA]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080DE636
	ldrh r2, [r1, 0x8]
	movs r4, 0x8
	ldrsh r0, [r1, r4]
	cmp r0, 0x10
	bne _080DE632
	adds r0, r3, 0x1
	strh r0, [r1, 0xA]
	b _080DE654
_080DE632:
	adds r0, r2, 0x1
	b _080DE652
_080DE636:
	ldrh r0, [r1, 0x8]
	movs r3, 0x8
	ldrsh r2, [r1, r3]
	cmp r2, 0
	bne _080DE650
	strh r2, [r1, 0xA]
	strh r2, [r1, 0xC]
	ldr r0, =sub_80DE65C
	str r0, [r1]
	b _080DE654
	.pool
_080DE650:
	subs r0, 0x1
_080DE652:
	strh r0, [r1, 0x8]
_080DE654:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DE5F4

	thumb_func_start sub_80DE65C
sub_80DE65C: @ 80DE65C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x9
	bgt _080DE680
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	b _080DE690
	.pool
_080DE680:
	movs r0, 0
	strh r0, [r4, 0xC]
	movs r0, 0x61
	movs r1, 0
	bl PlaySE12WithPanning
	ldr r0, =sub_80DE5C0
	str r0, [r4]
_080DE690:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE65C

	thumb_func_start sub_80DE69C
sub_80DE69C: @ 80DE69C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	ldr r6, =gSprites
	ldr r5, =gUnknown_02039F34
_080DE6AE:
	bl AllocOamMatrix
	ldr r1, [r5]
	ldr r1, [r1, 0x14]
	lsls r4, r7, 2
	adds r1, r4, r1
	ldrb r1, [r1]
	lsls r3, r1, 4
	adds r3, r1
	lsls r3, 2
	adds r3, r6
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1F
	ands r0, r1
	lsls r0, 1
	ldrb r1, [r3, 0x3]
	movs r2, 0x3F
	negs r2, r2
	mov r12, r2
	mov r2, r12
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x3]
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r2, [r0, 0x1]
	movs r3, 0x4
	negs r3, r3
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strb r2, [r0, 0x1]
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r8
	bl StartSpriteAffineAnim
	mov r0, r8
	cmp r0, 0x2
	bne _080DE74C
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl AnimateSprite
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
_080DE74C:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080DE6AE
	ldr r0, =sub_80DE794
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	mov r0, r8
	strh r0, [r1, 0x8]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x7]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x7]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE69C

	thumb_func_start sub_80DE794
sub_80DE794: @ 80DE794
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSprites
	ldr r3, =gUnknown_02039F34
	ldr r0, [r3]
	ldr r0, [r0, 0x14]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080DE822
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	bne _080DE7EC
	movs r4, 0
	adds r5, r2, 0
	movs r2, 0x4
_080DE7CC:
	ldr r0, [r3]
	ldr r1, [r0, 0x14]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DE7CC
_080DE7EC:
	movs r4, 0
_080DE7EE:
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0x14]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl FreeSpriteOamMatrix
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DE7EE
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
	adds r0, r6, 0
	bl DestroyTask
_080DE822:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE794

	thumb_func_start sub_80DE834
sub_80DE834: @ 80DE834
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bls _080DE844
	movs r1, 0x1
_080DE844:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80DE834

	thumb_func_start sub_80DE84C
sub_80DE84C: @ 80DE84C
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000019b
	cmp r1, r0
	bls _080DE85A
	movs r1, 0
_080DE85A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DE84C

	thumb_func_start sub_80DE864
sub_80DE864: @ 80DE864
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	bl sub_80DE834
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gUnknown_02039E00
	lsls r0, r7, 6
	adds r0, r1
	ldrh r0, [r0]
	bl sub_80DE84C
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	movs r1, 0
	movs r2, 0x14
	bl memset
	bl sub_80A3934
	ldr r1, =gBattleMonForms
	movs r2, 0
	adds r0, r1, 0x3
_080DE8A8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080DE8A8
	cmp r5, 0x90
	beq _080DE920
	cmp r5, 0x90
	bgt _080DE8DE
	cmp r5, 0x4C
	beq _080DE978
	cmp r5, 0x4C
	bgt _080DE8D4
	cmp r5, 0xD
	beq _080DE978
	b _080DE9A2
	.pool
_080DE8D4:
	cmp r5, 0x82
	beq _080DE978
	cmp r5, 0x8F
	beq _080DE978
	b _080DE9A2
_080DE8DE:
	cmp r5, 0xD8
	beq _080DE960
	cmp r5, 0xD8
	bgt _080DE8EC
	cmp r5, 0xAE
	beq _080DE8FA
	b _080DE9A2
_080DE8EC:
	cmp r5, 0xDA
	beq _080DE96C
	movs r0, 0x88
	lsls r0, 1
	cmp r5, r0
	beq _080DE920
	b _080DE9A2
_080DE8FA:
	ldr r0, =gBaseStats
	lsls r1, r6, 3
	subs r1, r6
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x6]
	cmp r0, 0x7
	beq _080DE910
	ldrb r0, [r1, 0x7]
	cmp r0, 0x7
	bne _080DE99C
_080DE910:
	ldr r1, =gUnknown_02038432
	movs r0, 0
	b _080DE9A0
	.pool
_080DE920:
	ldr r6, =gUnknown_02039F34
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x1B]
	ldr r5, =gUnknown_02039E00
	lsls r4, 6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl sub_80DE84C
	ldr r2, [r6]
	ldr r1, [r2, 0x18]
	strh r0, [r1, 0x2]
	ldr r2, [r2, 0x18]
	adds r5, 0x38
	adds r4, r5
	ldr r0, [r4]
	str r0, [r2, 0x10]
	ldrb r0, [r2, 0x4]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x4]
	b _080DE9A2
	.pool
_080DE960:
	ldr r1, =gHappinessMoveAnim
	movs r0, 0xFF
	b _080DE9A0
	.pool
_080DE96C:
	ldr r1, =gHappinessMoveAnim
	movs r0, 0
	b _080DE9A0
	.pool
_080DE978:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0x5A
	ldrb r1, [r2]
	cmp r1, 0
	bne _080DE99C
	movs r0, 0x2
	strb r0, [r2]
	ldr r0, =gUnknown_02038432
	strb r1, [r0]
	b _080DE9A2
	.pool
_080DE99C:
	ldr r1, =gUnknown_02038432
	movs r0, 0x1
_080DE9A0:
	strb r0, [r1]
_080DE9A2:
	bl sub_80DEA5C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE864

	thumb_func_start sub_80DE9B0
sub_80DE9B0: @ 80DE9B0
	push {r4,lr}
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	movs r1, 0
	movs r2, 0x14
	bl memset
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x5A
	ldrb r0, [r1]
	cmp r0, 0
	beq _080DE9D2
	subs r0, 0x1
	strb r0, [r1]
_080DE9D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE9B0

	thumb_func_start sub_80DE9DC
sub_80DE9DC: @ 80DE9DC
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gUnknown_02039F34
	ldr r0, [r6]
	ldr r0, [r0, 0x18]
	strb r4, [r0, 0x5]
	ldr r5, =gUnknown_02039E00
	lsls r4, 6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl sub_80DE84C
	ldr r2, [r6]
	ldr r1, [r2, 0x18]
	strh r0, [r1]
	ldr r1, [r2, 0x18]
	adds r0, r5, 0
	adds r0, 0x38
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1, 0x8]
	adds r5, 0x3C
	adds r4, r5
	ldr r0, [r4]
	str r0, [r1, 0xC]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE9DC

	thumb_func_start sub_80DEA20
sub_80DEA20: @ 80DEA20
	push {lr}
	ldr r0, =SpriteCallbackDummy
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gBankSpriteIds
	strb r0, [r1, 0x3]
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl InitSpriteAffineAnim
	bl sub_80DEA5C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DEA20

	thumb_func_start sub_80DEA5C
sub_80DEA5C: @ 80DEA5C
	push {r4,lr}
	ldr r0, =gBankSpriteIds
	ldrb r0, [r0, 0x3]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0x3
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	movs r0, 0x3
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DEA5C

	thumb_func_start sub_80DEAA8
sub_80DEAA8: @ 80DEAA8
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x6]
	cmp r0, 0x20
	bhi _080DEB60
	lsls r0, 2
	ldr r1, =_080DEAD0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DEAD0:
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB54
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB54
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
_080DEB54:
	ldr r1, =gBankTarget
	movs r0, 0x2
	b _080DEB64
	.pool
_080DEB60:
	ldr r1, =gBankTarget
	movs r0, 0x3
_080DEB64:
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DEAA8

	thumb_func_start sub_80DEB70
sub_80DEB70: @ 80DEB70
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	strb r4, [r0, 0x4]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r1, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r2, [r0, 0xA]
	strb r2, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x11
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0xF0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	mov r1, sp
	movs r0, 0x80
	strb r0, [r1, 0xD]
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	movs r0, 0
	bl sub_80DED60
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DEB70

	thumb_func_start sub_80DEBD0
sub_80DEBD0: @ 80DEBD0
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r4, [sp, 0x1C]
	str r1, [sp]
	mov r0, sp
	movs r1, 0
	strb r5, [r0, 0x4]
	strb r4, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r3, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r3, [r0, 0x9]
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x10
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0xF0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	mov r1, sp
	movs r0, 0x80
	strb r0, [r1, 0xD]
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl PutWindowTilemap
	movs r0, 0
	bl sub_80DED60
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DEBD0

	thumb_func_start sub_80DEC30
sub_80DEC30: @ 80DEC30
	push {r4,r5,lr}
	sub sp, 0x10
	str r0, [sp]
	mov r2, sp
	movs r3, 0
	movs r0, 0x4
	strb r0, [r2, 0x4]
	mov r0, sp
	movs r5, 0x1
	strb r5, [r0, 0x5]
	strb r3, [r0, 0x6]
	strb r5, [r0, 0x7]
	strb r3, [r0, 0x8]
	strb r5, [r0, 0x9]
	strb r3, [r0, 0xA]
	strb r3, [r0, 0xB]
	mov r4, sp
	ldrb r3, [r4, 0xC]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r4, 0xC]
	mov r3, sp
	movs r0, 0x10
	strb r0, [r3, 0xC]
	ldrb r0, [r3, 0xD]
	ands r2, r0
	strb r2, [r3, 0xD]
	mov r2, sp
	movs r0, 0x80
	strb r0, [r2, 0xD]
	cmp r1, 0
	bne _080DEC80
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	b _080DECA4
_080DEC80:
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080DEC94
	movs r1, 0x4
	b _080DEC9C
	.pool
_080DEC94:
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r1, r0, 24
_080DEC9C:
	mov r0, sp
	movs r2, 0
	bl AddTextPrinter
_080DECA4:
	movs r0, 0x4
	bl PutWindowTilemap
	movs r0, 0
	bl sub_80DED60
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DEC30

	thumb_func_start sub_80DECB8
sub_80DECB8: @ 80DECB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	ldr r0, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	mov r7, r8
	lsls r7, 24
	lsrs r7, 24
	mov r8, r7
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	lsls r6, 16
	asrs r6, 16
	str r6, [sp, 0xC]
	mov r0, r8
	bl WriteSequenceToBgTilemapBuffer
	mov r0, r8
	bl sub_80DED60
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DECB8

	thumb_func_start sub_80DED10
sub_80DED10: @ 80DED10
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r4, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r6, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r4, 0
	str r4, [sp, 0xC]
	bl sub_80DECB8
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80DED10

	thumb_func_start sub_80DED4C
sub_80DED4C: @ 80DED4C
	push {lr}
	bl RunTextPrinters
	movs r0, 0x4
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_80DED4C

	thumb_func_start sub_80DED60
sub_80DED60: @ 80DED60
	ldr r2, =gUnknown_02039F38
	movs r1, 0x1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_80DED60

	thumb_func_start ResetContestLinkResults
ResetContestLinkResults: @ 80DED74
	push {r4-r6,lr}
	movs r0, 0
	ldr r6, =gSaveBlock2Ptr
	ldr r5, =0x00000624
	movs r4, 0
_080DED7E:
	adds r3, r0, 0x1
	lsls r1, r0, 3
	movs r2, 0x3
_080DED84:
	ldr r0, [r6]
	adds r0, r5
	adds r0, r1
	strh r4, [r0]
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080DED84
	adds r0, r3, 0
	cmp r0, 0x4
	ble _080DED7E
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetContestLinkResults

	thumb_func_start sub_80DEDA8
sub_80DEDA8: @ 80DEDA8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r1, =gUnknown_02039F20
	ldrb r0, [r1]
	cmp r0, 0
	beq _080DEDE6
_080DEDD8:
	adds r5, 0x1
	cmp r5, 0x2
	bgt _080DEDE6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DEDD8
_080DEDE6:
	ldr r0, [sp]
	cmp r0, 0xFF
	bne _080DEE00
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	cmp r5, r0
	beq _080DEE00
	movs r0, 0
	b _080DEF90
	.pool
_080DEE00:
	ldr r0, =gScriptContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080DEE4C
	lsls r0, 2
	ldr r1, =_080DEE1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DEE1C:
	.4byte _080DEE4C
	.4byte _080DEE30
	.4byte _080DEE36
	.4byte _080DEE3C
	.4byte _080DEE42
_080DEE30:
	mov r0, r8
	adds r0, 0x3
	b _080DEE46
_080DEE36:
	mov r0, r8
	adds r0, 0x6
	b _080DEE46
_080DEE3C:
	mov r0, r8
	adds r0, 0x9
	b _080DEE46
_080DEE42:
	mov r0, r8
	adds r0, 0xC
_080DEE46:
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_080DEE4C:
	ldr r1, [sp]
	cmp r1, 0xFE
	bne _080DEE54
	b _080DEF50
_080DEE54:
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_80DEFA8
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r2, =gSaveBlock1Ptr
	mov r10, r2
	ldr r0, [r2]
	mov r3, r9
	lsls r7, r3, 5
	ldr r6, =0x00002e90
	adds r2, r0, r6
	adds r2, r7
	ldr r4, =gUnknown_02039E00
	lsls r5, 6
	adds r1, r4, 0
	adds r1, 0x38
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r1, r0, r7
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r3, =0x00002e98
	adds r1, r3
	strh r2, [r1]
	ldr r1, =0x00002e94
	adds r2, r0, r1
	adds r2, r7
	adds r1, r4, 0
	adds r1, 0x3C
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r6, r7, r6
	adds r0, r6
	adds r0, 0xB
	adds r1, r4, 0x2
	adds r1, r5, r1
	bl StringCopy
	mov r2, r10
	ldr r0, [r2]
	adds r0, r6
	adds r0, 0x16
	adds r4, 0xD
	adds r5, r4
	adds r1, r5, 0
	bl StringCopy
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DEEF4
	mov r3, r10
	ldr r0, [r3]
	adds r0, r7
	ldr r1, =0x00002eae
	adds r0, r1
	movs r1, 0x4
	b _080DEF02
	.pool
_080DEEF4:
	mov r2, r10
	ldr r0, [r2]
	adds r0, r7
	ldr r1, =gUnknown_02039F2E
	ldrh r1, [r1]
	ldr r3, =0x00002eae
	adds r0, r3
_080DEF02:
	strb r1, [r0]
	ldr r0, [sp]
	cmp r0, 0xFF
	beq _080DEF34
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	mov r2, r9
	lsls r1, r2, 5
	adds r0, r1
	ldr r1, =gScriptContestCategory
	ldrh r1, [r1]
	ldr r3, =0x00002e9a
	adds r0, r3
	strb r1, [r0]
	b _080DEF8E
	.pool
_080DEF34:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	mov r2, r9
	lsls r1, r2, 5
	adds r0, r1
	ldr r3, =0x00002e9a
	adds r0, r3
	mov r1, r8
	strb r1, [r0]
	b _080DEF8E
	.pool
_080DEF50:
	ldr r6, =gUnknown_02039F3C
	ldr r4, =gUnknown_02039E00
	lsls r5, 6
	adds r0, r4, 0
	adds r0, 0x38
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6]
	adds r0, r4, 0
	adds r0, 0x3C
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6, 0x4]
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r6, 0x8]
	adds r0, r6, 0
	adds r0, 0xB
	adds r1, r4, 0x2
	adds r1, r5, r1
	bl StringCopy
	adds r0, r6, 0
	adds r0, 0x16
	adds r4, 0xD
	adds r5, r4
	adds r1, r5, 0
	bl StringCopy
	mov r2, r8
	strb r2, [r6, 0xA]
_080DEF8E:
	movs r0, 0x1
_080DEF90:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DEDA8

	thumb_func_start sub_80DEFA8
sub_80DEFA8: @ 80DEFA8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r0, 0x3
	bgt _080DEFF8
	cmp r0, 0
	blt _080DEFF8
	cmp r1, 0
	beq _080DEFE6
	movs r2, 0x5
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	ldr r4, =0x00002e90
	ldr r3, =0x00002e70
_080DEFC8:
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r2, 5
	adds r1, r0
	adds r0, r1, r4
	adds r1, r3
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5,r6}
	stm r0!, {r5,r6}
	subs r2, 0x1
	cmp r2, 0
	bgt _080DEFC8
_080DEFE6:
	movs r0, 0
	b _080DF03A
	.pool
_080DEFF8:
	ldr r0, =gScriptContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080DF038
	lsls r0, 2
	ldr r1, =_080DF014
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DF014:
	.4byte _080DF028
	.4byte _080DF02C
	.4byte _080DF030
	.4byte _080DF034
	.4byte _080DF038
_080DF028:
	movs r0, 0x8
	b _080DF03A
_080DF02C:
	movs r0, 0x9
	b _080DF03A
_080DF030:
	movs r0, 0xA
	b _080DF03A
_080DF034:
	movs r0, 0xB
	b _080DF03A
_080DF038:
	movs r0, 0xC
_080DF03A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80DEFA8

	thumb_func_start ClearContestWinnerPicsInContestHall
ClearContestWinnerPicsInContestHall: @ 80DF040
	push {r4-r7,lr}
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	ldr r4, =0x00002e90
	ldr r3, =gUnknown_08587FA4
_080DF04C:
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r2, 5
	adds r0, r1
	adds r0, r4
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5,r6}
	stm r0!, {r5,r6}
	adds r3, 0x20
	adds r2, 0x1
	cmp r2, 0x7
	ble _080DF04C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearContestWinnerPicsInContestHall

	thumb_func_start sub_80DF080
sub_80DF080: @ 80DF080
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gUnknown_02039F34
	ldr r3, [r2]
	ldr r5, [r3, 0x10]
	ldrb r1, [r5, 0x1]
	movs r7, 0x1
	adds r0, r7, 0
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	bne _080DF0D2
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	ble _080DF0D2
	ldr r1, [r3, 0x4]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF0D2
	ldr r1, [r3, 0x1C]
	lsls r2, r4, 4
	adds r1, r2, r1
	ldrb r3, [r1, 0xC]
	movs r0, 0x1
	orrs r0, r3
	strb r0, [r1, 0xC]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	adds r2, r0
	ldrb r0, [r2, 0xE]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0xE]
_080DF0D2:
	ldr r3, [r6]
	ldr r1, [r3, 0x4]
	lsls r2, r4, 3
	subs r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	adds r7, r2, 0
	cmp r0, 0
	beq _080DF0FA
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF0FA:
	ldr r3, [r6]
	ldr r2, [r3, 0x10]
	ldrb r1, [r2, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF126
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _080DF126
	movs r0, 0x2
	ldrsb r0, [r2, r0]
	cmp r0, 0x3C
	bne _080DF126
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x4
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF126:
	ldr r3, [r6]
	ldr r1, [r3, 0x4]
	subs r0, r7, r4
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080DF14E
	ldrb r0, [r2, 0x16]
	cmp r0, 0
	beq _080DF14E
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF14E:
	movs r3, 0
	movs r5, 0
_080DF152:
	cmp r3, r4
	beq _080DF180
	ldr r1, [r6]
	ldr r0, [r1, 0x4]
	adds r0, r5, r0
	ldrb r0, [r0, 0xE]
	cmp r0, 0
	beq _080DF180
	ldr r0, [r1, 0x1C]
	lsls r2, r4, 4
	adds r2, r0
	ldrb r0, [r2, 0xC]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	lsls r2, r3, 4
	adds r2, r0
	ldrb r0, [r2, 0xC]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xC]
_080DF180:
	adds r5, 0x1C
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF152
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	subs r0, r7, r4
	lsls r5, r0, 2
	adds r1, r5, r1
	ldrb r3, [r1, 0xC]
	movs r0, 0x6
	ands r0, r3
	cmp r0, 0
	bne _080DF1A6
	ldrb r1, [r1, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080DF1BC
_080DF1A6:
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x20
	orrs r0, r2
	strb r0, [r1, 0xC]
	b _080DF1F6
	.pool
_080DF1BC:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	bne _080DF1F6
	ldr r2, [r2, 0x1C]
	lsls r3, r4, 4
	adds r2, r3, r2
	ldrb r0, [r2, 0xC]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r6]
	ldr r1, [r0, 0x1C]
	adds r1, r3, r1
	ldrb r0, [r1, 0xE]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1, 0xE]
	ldr r1, [r6]
	ldr r0, [r1, 0x1C]
	adds r3, r0
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	adds r3, r0
	ldr r0, [r1, 0x4]
	adds r0, r5, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r3]
_080DF1F6:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	subs r0, r7, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080DF21A
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1, 0xD]
_080DF21A:
	ldr r2, [r6]
	ldr r0, [r2]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bne _080DF24A
	ldr r3, [r2, 0x10]
	ldrb r1, [r3, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF24A
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0
	bge _080DF24A
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x20
	orrs r0, r2
	strb r0, [r1, 0xD]
_080DF24A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF080

	thumb_func_start sub_80DF250
sub_80DF250: @ 80DF250
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	movs r1, 0
	movs r0, 0
	str r0, [sp, 0x20]
	movs r4, 0
	ldr r6, =gUnknown_02039F34
	mov r2, sp
	adds r2, 0xC
	str r2, [sp, 0x28]
	mov r3, sp
	adds r3, 0x14
	str r3, [sp, 0x2C]
	mov r7, sp
	adds r7, 0x2
	str r7, [sp, 0x24]
	ldr r5, =gUnknown_02039F20
	movs r2, 0
	movs r3, 0x80
	lsls r3, 17
_080DF280:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF298
	lsrs r0, r2, 24
	str r0, [sp, 0x20]
	b _080DF29E
	.pool
_080DF298:
	cmp r0, 0x3
	bne _080DF29E
	lsrs r1, r2, 24
_080DF29E:
	adds r2, r3
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DF280
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	lsls r1, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x1
	orrs r0, r2
	strb r0, [r1, 0xD]
	movs r4, 0
	ldr r1, [sp, 0x20]
	lsls r1, 4
	str r1, [sp, 0x30]
	mov r9, r4
	mov r10, r4
_080DF2C2:
	ldr r2, [sp, 0x20]
	cmp r4, r2
	beq _080DF2EE
	ldr r1, =gUnknown_02039F08
	lsls r0, r2, 1
	adds r0, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	add r1, r10
	movs r6, 0
	ldrsh r0, [r1, r6]
	subs r2, r0
	cmp r2, 0x32
	bgt _080DF2EE
	ldr r7, =gUnknown_02039F34
	ldr r0, [r7]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF2EE:
	ldr r1, =gUnknown_02039F34
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	mov r3, r9
	adds r2, r3, r0
	ldrb r1, [r2, 0xE]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080DF30A
	ldrb r0, [r2, 0xD]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF30A:
	movs r5, 0
	ldr r2, =gUnknown_02039F00
	add r2, r10
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r7, =gUnknown_02039F00
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r1, r0
	blt _080DF336
	adds r3, r2, 0
	adds r2, r7, 0
_080DF322:
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	bgt _080DF336
	movs r6, 0
	ldrsh r1, [r3, r6]
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DF322
_080DF336:
	cmp r5, 0x4
	bne _080DF354
	ldr r1, =gUnknown_02039F20
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DF354
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF354:
	movs r3, 0
	mov r12, r3
	mov r8, r3
	movs r5, 0
	ldr r0, =gUnknown_02039F00
	add r0, r10
	movs r7, 0
	ldrsh r6, [r0, r7]
	str r6, [sp, 0x34]
	ldr r2, =gUnknown_02039F00
	ldr r0, =gUnknown_02039F18
	mov r1, r10
	adds r6, r1, r0
	adds r3, r0, 0
_080DF370:
	movs r7, 0
	ldrsh r0, [r2, r7]
	ldr r1, [sp, 0x34]
	cmp r1, r0
	ble _080DF37E
	movs r7, 0x1
	mov r12, r7
_080DF37E:
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble _080DF38E
	movs r0, 0x1
	mov r8, r0
_080DF38E:
	adds r2, 0x2
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DF370
	mov r1, r12
	cmp r1, 0
	bne _080DF3B4
	mov r2, r8
	cmp r2, 0
	bne _080DF3B4
	ldr r3, =gUnknown_02039F34
	ldr r0, [r3]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF3B4:
	ldr r6, =gUnknown_02039F34
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	mov r7, r9
	adds r2, r7, r0
	ldrb r1, [r2, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DF3D0
	ldrb r0, [r2, 0xD]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF3D0:
	movs r0, 0x10
	add r9, r0
	movs r1, 0x2
	add r10, r1
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080DF3E0
	b _080DF2C2
_080DF3E0:
	movs r4, 0
	movs r5, 0
	movs r3, 0
	ldr r2, [sp, 0x28]
	mov r1, sp
_080DF3EA:
	strh r3, [r1]
	adds r0, r2, r4
	strb r5, [r0]
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x4
	ble _080DF3EA
	mov r1, sp
	ldr r0, =0x0000ffff
	strh r0, [r1, 0xA]
	movs r0, 0
	ldr r2, [sp, 0x28]
	strb r0, [r2, 0x5]
	movs r4, 0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [sp, 0x30]
_080DF40E:
	mov r3, r8
	ldr r0, [r3, 0x1C]
	adds r0, r7, r0
	lsls r1, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	adds r4, 0x1
	mov r12, r4
	cmp r0, 0
	beq _080DF450
	ldr r0, =gUnknown_02039F34
	ldr r6, [r0]
	ldr r3, [sp, 0x28]
	mov r4, sp
	movs r5, 0x4
_080DF42C:
	ldr r0, [r6, 0x1C]
	adds r0, r7, r0
	adds r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _080DF440
	cmp r2, 0
	bne _080DF446
	strh r0, [r4]
_080DF440:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_080DF446:
	adds r3, 0x1
	adds r4, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _080DF42C
_080DF450:
	mov r4, r12
	cmp r4, 0x4
	ble _080DF40E
	mov r0, sp
	ldrh r0, [r0]
	ldr r6, [sp, 0x2C]
	strh r0, [r6]
	ldr r7, [sp, 0x28]
	ldrb r3, [r7]
	movs r6, 0
	movs r4, 0x1
	ldr r1, [sp, 0x24]
	ldrh r0, [r1]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _080DF4C0
	ldr r5, [sp, 0x2C]
	adds r7, r1, 0
	mov r2, sp
	adds r2, 0x2
_080DF478:
	ldr r0, [sp, 0x28]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r3, r0
	bcs _080DF4A4
	ldrh r0, [r2]
	strh r0, [r5]
	ldrb r3, [r1]
	movs r6, 0x1
	b _080DF4B6
	.pool
_080DF4A4:
	cmp r3, r0
	bne _080DF4B6
	lsls r0, r6, 1
	adds r0, r5, r0
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080DF4B6:
	adds r2, 0x2
	adds r4, 0x1
	ldrh r0, [r2]
	cmp r0, r7
	bne _080DF478
_080DF4C0:
	bl Random
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r4, [r1, 0x1C]
	ldr r1, [sp, 0x30]
	adds r4, r1, r4
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 1
	ldr r2, [sp, 0x2C]
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r4, 0xA]
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF250

	thumb_func_start sub_80DF4F8
sub_80DF4F8: @ 80DF4F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r1, =gUnknown_02039F20
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DF514
	b _080DF6EE
_080DF514:
	movs r7, 0
	movs r3, 0
	ldr r0, =gUnknown_02039F34
	mov r12, r0
_080DF51C:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF528
	lsls r0, r3, 24
	lsrs r7, r0, 24
_080DF528:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF51C
	movs r1, 0
	mov r9, r1
	mov r10, r1
	movs r3, 0
	lsls r2, r7, 1
	lsls r4, r7, 4
	mov r8, r4
	ldr r1, =gUnknown_02039F00
	adds r0, r2, r1
	movs r6, 0
	ldrsh r5, [r0, r6]
	str r5, [sp, 0x8]
	adds r5, r1, 0
	ldr r0, =gUnknown_02039F18
	adds r2, r0
	adds r4, r0, 0
_080DF54E:
	movs r1, 0
	ldrsh r0, [r5, r1]
	ldr r6, [sp, 0x8]
	cmp r6, r0
	bge _080DF562
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080DF562:
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bge _080DF578
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_080DF578:
	adds r5, 0x2
	adds r4, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF54E
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrb r1, [r0, 0xC]
	movs r4, 0
	movs r2, 0x1
	movs r3, 0x7
_080DF592:
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _080DF5A0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080DF5A0:
	lsrs r1, 1
	subs r3, 0x1
	cmp r3, 0
	bge _080DF592
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrb r1, [r0, 0xC]
	movs r4, 0
	movs r2, 0
	movs r3, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DF5DC
	cmp r5, 0
	beq _080DF5F6
_080DF5D6:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080DF5DC:
	lsrs r1, 1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, 0x1
	cmp r3, 0x7
	bgt _080DF5F6
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DF5DC
	cmp r5, r4
	bne _080DF5D6
_080DF5F6:
	movs r1, 0x1
	adds r0, r1, 0
	lsls r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r7, 0
	bne _080DF628
	mov r0, sp
	strb r1, [r0]
	ldr r1, =gUnknown_02039F34
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	ldrb r4, [r0, 0x1D]
	movs r3, 0x2
	b _080DF638
	.pool
_080DF628:
	mov r1, sp
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_02039F34
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	ldrb r4, [r0, 0xD]
	movs r3, 0x1
_080DF638:
	mov r12, r1
	movs r5, 0x1
	lsls r2, 24
	str r2, [sp, 0x4]
	cmp r3, 0x3
	bgt _080DF682
_080DF644:
	cmp r3, r7
	beq _080DF67C
	mov r6, r12
	ldr r2, [r6]
	ldr r0, [r2, 0x1C]
	lsls r1, r3, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0xD]
	cmp r4, r0
	bcs _080DF66C
	mov r0, sp
	strb r3, [r0]
	ldr r0, [r2, 0x1C]
	adds r0, r1, r0
	ldrb r4, [r0, 0xD]
	movs r5, 0x1
	b _080DF67C
	.pool
_080DF66C:
	cmp r4, r0
	bne _080DF67C
	mov r1, sp
	adds r0, r1, r5
	strb r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080DF67C:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF644
_080DF682:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	add r0, sp
	ldrb r6, [r0]
	movs r2, 0x80
	movs r3, 0
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0, 0x1C]
	lsls r1, r6, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0xD]
	ands r0, r2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080DF6C4
_080DF6AE:
	lsrs r2, 1
	adds r3, 0x1
	cmp r3, 0x7
	bgt _080DF6C4
	ldr r0, [r5]
	ldr r0, [r0, 0x1C]
	adds r0, r1, r0
	ldrb r4, [r0, 0xD]
	ands r4, r2
	cmp r4, 0
	beq _080DF6AE
_080DF6C4:
	mov r0, r9
	bl sub_80ECDA4
	mov r0, r10
	bl sub_80ECDF4
	ldr r5, [sp, 0x4]
	lsrs r0, r5, 24
	bl sub_80ECE34
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrh r0, [r0, 0xA]
	bl sub_80ECE74
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80ECEB4
_080DF6EE:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF4F8

	thumb_func_start sub_80DF704
sub_80DF704: @ 80DF704
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =0x02000000
	movs r1, 0xD0
	lsls r1, 9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r4, r0, 0
	cmp r1, 0
	bne _080DF72C
	cmp r3, 0
	bne _080DF728
	movs r0, 0x2
	b _080DF72E
	.pool
_080DF728:
	movs r0, 0x3
	b _080DF72E
_080DF72C:
	movs r0, 0
_080DF72E:
	strb r0, [r2]
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF746
	bl sub_80DAEA4
	bl sub_80DB2BC
	b _080DF74A
_080DF746:
	bl sub_80DF750
_080DF74A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF704

	thumb_func_start sub_80DF750
sub_80DF750: @ 80DF750
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r0, =gUnknown_020322D5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF766
	b _080DF924
_080DF766:
	ldr r0, =0x02000000
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080DF77C
	b _080DF924
_080DF77C:
	movs r7, 0
	mov r2, sp
	adds r2, 0x18
	str r2, [sp, 0x30]
_080DF784:
	adds r0, r7, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF784
	ldr r0, =0x02000000
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080DF874
	movs r7, 0
	movs r2, 0x7
	mov r10, r2
	ldr r0, [sp, 0x30]
	mov r9, r0
_080DF7AE:
	add r0, sp, 0x4
	ldr r1, =gText_CDot
	bl StringCopy
	adds r5, r0, 0
	ldr r0, =gUnknown_02039F26
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r1, r10
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x5
	movs r3, 0x1
	bl sub_80DEBD0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	lsls r0, r7, 4
	adds r0, r1
	ldrb r4, [r0, 0xC]
	movs r6, 0x7
	adds r2, r7, 0x1
	mov r8, r2
_080DF7DE:
	movs r1, 0x1
	ands r1, r4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	lsrs r4, 1
	lsls r0, r6, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r6, r0, 24
	asrs r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bgt _080DF7DE
	movs r6, 0
	ldr r4, =gUnknown_02039F26
	ldr r3, [sp, 0x30]
_080DF80A:
	lsls r0, r6, 24
	asrs r0, 24
	adds r2, r3, r0
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r5, r0, 24
	cmp r5, 0x4
	ble _080DF80A
	mov r0, r9
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r4, r7, r4
	ldrb r0, [r4]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	movs r2, 0x5
	movs r3, 0x1
	bl sub_80DEBD0
	ldrb r0, [r4]
	mov r1, sp
	adds r1, r5
	adds r1, 0x4
	mov r2, r10
	str r2, [sp]
	movs r2, 0x37
	movs r3, 0x1
	bl sub_80DEBD0
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF7AE
	b _080DF920
	.pool
_080DF874:
	movs r7, 0
	mov r2, sp
	adds r2, 0x6
	str r2, [sp, 0x2C]
	ldr r0, [sp, 0x30]
	mov r9, r0
	movs r1, 0x7
	mov r10, r1
_080DF884:
	add r0, sp, 0x4
	ldr r1, =gText_BDot
	bl StringCopy
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	lsls r0, r7, 4
	adds r0, r1
	ldrb r4, [r0, 0xD]
	ldr r5, [sp, 0x2C]
	movs r6, 0x7
	adds r2, r7, 0x1
	mov r8, r2
_080DF8A0:
	movs r1, 0x1
	ands r1, r4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	lsrs r4, 1
	lsls r0, r6, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r6, r0, 24
	asrs r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bgt _080DF8A0
	movs r6, 0
	ldr r4, =gUnknown_02039F26
	ldr r3, [sp, 0x30]
_080DF8CC:
	lsls r0, r6, 24
	asrs r0, 24
	adds r2, r3, r0
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r5, r0, 24
	cmp r5, 0x4
	ble _080DF8CC
	mov r0, r9
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r4, r7, r4
	ldrb r0, [r4]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	movs r2, 0x5
	movs r3, 0x1
	bl sub_80DEBD0
	ldrb r0, [r4]
	mov r1, sp
	adds r1, r5
	adds r1, 0x4
	mov r2, r10
	str r2, [sp]
	movs r2, 0x37
	movs r3, 0x1
	bl sub_80DEBD0
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF884
_080DF920:
	bl sub_80DB2BC
_080DF924:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF750

	thumb_func_start sub_80DF940
sub_80DF940: @ 80DF940
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x2
	ldrb r0, [r4]
	cmp r0, 0xFC
	bne _080DF956
	ldrb r0, [r4, 0x1]
	cmp r0, 0x15
	bne _080DF956
	movs r0, 0x2
	b _080DF9CC
_080DF956:
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _080DF9CA
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _080DF9CA
_080DF96A:
	ldrb r1, [r4]
	adds r0, r1, 0
	adds r0, 0x45
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x33
	bls _080DF9BE
	adds r0, r1, 0
	adds r0, 0x5F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bls _080DF9BE
	adds r0, r1, 0
	cmp r0, 0
	beq _080DF9BE
	cmp r0, 0xAD
	beq _080DF9BE
	cmp r0, 0xB8
	beq _080DF9BE
	cmp r0, 0xAB
	beq _080DF9BE
	cmp r0, 0xAC
	beq _080DF9BE
	cmp r0, 0xB5
	beq _080DF9BE
	cmp r0, 0xB6
	beq _080DF9BE
	cmp r0, 0xBA
	beq _080DF9BE
	cmp r0, 0xAE
	beq _080DF9BE
	cmp r0, 0xB0
	beq _080DF9BE
	cmp r0, 0xB1
	beq _080DF9BE
	cmp r0, 0xB2
	beq _080DF9BE
	cmp r0, 0xB3
	beq _080DF9BE
	cmp r0, 0xB1
	bne _080DF9C8
_080DF9BE:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _080DF96A
	b _080DF9CA
_080DF9C8:
	movs r5, 0x1
_080DF9CA:
	adds r0, r5, 0
_080DF9CC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80DF940

	thumb_func_start sub_80DF9D4
sub_80DF9D4: @ 80DF9D4
	ldrb r2, [r0, 0x5]
	movs r1, 0xFF
	strb r1, [r0, 0x5]
	strb r2, [r0, 0x7]
	bx lr
	thumb_func_end sub_80DF9D4

	thumb_func_start sub_80DF9E0
sub_80DF9E0: @ 80DF9E0
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl StripExtCtrlCodes
	cmp r4, 0x1
	bne _080DF9F8
	movs r0, 0xFF
	strb r0, [r5, 0x5]
	movs r0, 0xFC
	strb r0, [r5, 0xA]
	b _080DFA00
_080DF9F8:
	ldrb r1, [r5, 0x5]
	movs r0, 0xFF
	strb r0, [r5, 0x5]
	strb r1, [r5, 0xA]
_080DFA00:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF9E0

	thumb_func_start sub_80DFA08
sub_80DFA08: @ 80DFA08
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r5, 0x2
	cmp r6, 0x1
	bne _080DFA28
	adds r0, r4, 0
	bl sub_80DF940
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl ConvertInternationalString
	b _080DFA3E
_080DFA28:
	ldrb r0, [r4, 0xA]
	cmp r0, 0xFC
	bne _080DFA38
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _080DFA3E
_080DFA38:
	strb r0, [r4, 0x5]
	movs r0, 0xFF
	strb r0, [r4, 0xA]
_080DFA3E:
	adds r4, r5, 0
	adds r4, 0xD
	cmp r6, 0x1
	bne _080DFA68
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	ldrb r0, [r4, 0x4]
	strb r0, [r4, 0x6]
	ldrb r0, [r4, 0x3]
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0x2]
	strb r0, [r4, 0x4]
	ldrb r0, [r4, 0x1]
	strb r0, [r4, 0x3]
	ldrb r0, [r5, 0xD]
	strb r0, [r4, 0x2]
	movs r0, 0x15
	strb r0, [r4, 0x1]
	movs r0, 0xFC
	strb r0, [r5, 0xD]
	b _080DFA70
_080DFA68:
	ldrb r0, [r4, 0x7]
	strb r0, [r4, 0x5]
	movs r0, 0xFF
	strb r0, [r4, 0x7]
_080DFA70:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80DFA08

	.align 2, 0 @ Don't pad with nop.
