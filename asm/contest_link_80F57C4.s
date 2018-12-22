	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80F57C4
sub_80F57C4: @ 80F57C4
	push {r4,lr}
	movs r0, 0
	movs r1, 0x40
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0858D888
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r4, 0
_080F57E0:
	lsls r0, r4, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203A034
	ldr r1, [r1]
	lsls r2, r4, 2
	adds r1, 0xC
	adds r1, r2
	ldr r1, [r1]
	bl SetBgTilemapBuffer
	adds r4, 0x1
	cmp r4, 0x3
	ble _080F57E0
	ldr r0, =gUnknown_0858D898
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f2e
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0
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
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r1, 0xFF
	lsls r1, 8
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
	thumb_func_end sub_80F57C4

	thumb_func_start sub_80F591C
sub_80F591C: @ 80F591C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r0, =gUnknown_08C19588
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	ldr r1, =gUnknown_08C1A12C
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gUnknown_08C1A000
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gUnknown_08C19EEC
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	bl sub_80F71C8
	ldr r0, =gUnknown_08C1A2B4
	movs r2, 0x80
	lsls r2, 2
	movs r1, 0
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0858D6B0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r7, 0
	movs r0, 0x1
	mov r8, r0
_080F5976:
	lsls r5, r7, 24
	lsrs r5, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80F7310
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80F7364
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	movs r6, 0
	lsls r1, r7, 1
	adds r2, r7, 0x1
	str r2, [sp, 0xC]
	lsls r4, 24
	asrs r4, 24
	mov r10, r4
	adds r1, r7
	adds r0, r1, 0x6
	lsls r0, 24
	mov r9, r0
	adds r1, 0x5
	lsls r7, r1, 24
_080F59B0:
	ldr r1, =0x000060b2
	cmp r6, r10
	bge _080F59B8
	adds r1, 0x2
_080F59B8:
	ldr r4, [sp, 0x8]
	lsls r0, r4, 24
	asrs r0, 24
	adds r2, r0, 0
	cmp r0, 0
	bge _080F59C6
	negs r2, r0
_080F59C6:
	cmp r6, r2
	bge _080F59F4
	ldr r5, =0x000060a4
	cmp r0, 0
	bge _080F59F6
	adds r5, 0x2
	b _080F59F6
	.pool
_080F59F4:
	ldr r5, =0x000060a2
_080F59F6:
	adds r4, r6, 0
	adds r4, 0x13
	lsls r4, 24
	lsrs r4, 24
	mov r0, r8
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	adds r2, r4, 0
	lsrs r3, r7, 24
	bl FillBgTilemapBufferRect_Palette0
	mov r2, r8
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r0, 0x1
	adds r1, r5, 0
	adds r2, r4, 0
	mov r4, r9
	lsrs r3, r4, 24
	bl FillBgTilemapBufferRect_Palette0
	adds r6, 0x1
	cmp r6, 0x9
	ble _080F59B0
	ldr r7, [sp, 0xC]
	cmp r7, 0x3
	ble _080F5976
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F591C

	thumb_func_start sub_80F5A74
sub_80F5A74: @ 80F5A74
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r1, r5, 6
	ldr r0, =gContestMons
	adds r7, r1, r0
	ldr r6, =gDisplayedStringBattle
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	cmp r5, r0
	bne _080F5A96
	ldr r1, =gText_ColorDarkGrey
	adds r0, r6, 0
	bl StringCopy
	adds r6, r0, 0
_080F5A96:
	adds r1, r7, 0x2
	adds r0, r6, 0
	bl StringCopy
	ldr r4, =gDisplayedStringBattle
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_80F7ED0
	ldr r1, =gText_Slash
	adds r0, r6, 0
	bl StringCopy
	adds r1, r7, 0
	adds r1, 0xD
	adds r0, r6, 0
	bl StringAppend
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x32
	bl sub_80F7ED0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5A74

	thumb_func_start sub_80F5AE0
sub_80F5AE0: @ 80F5AE0
	push {r4,lr}
	movs r4, 0
_080F5AE4:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80F5A74
	adds r4, 0x1
	cmp r4, 0x3
	ble _080F5AE4
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80F5AE0

	thumb_func_start sub_80F5B00
sub_80F5B00: @ 80F5B00
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gPaletteFade
	ldrb r0, [r5, 0x8]
	movs r6, 0x80
	orrs r0, r6
	strb r0, [r5, 0x8]
	movs r0, 0
	bl SetVBlankCallback
	bl sub_80F7DF4
	bl sub_80F57C4
	bl ScanlineEffect_Clear
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	bl FreeAllSpritePalettes
	bl sub_80F591C
	bl sub_80F6A9C
	movs r0, 0
	movs r1, 0x1
	bl sub_80F6A64
	bl sub_80F5AE0
	ldr r4, =gUnknown_0203A034
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x18
	bl memset
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0
	movs r2, 0x50
	bl memset
	bl sub_80F6DC0
	bl sub_80F6AE8
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldrb r1, [r5, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r5, 0x8]
	ldr r0, =sub_80F5CE4
	movs r1, 0x5
	bl CreateTask
	ldr r1, [r4]
	ldr r1, [r1]
	strb r0, [r1, 0x2]
	ldr r0, =sub_80F5C00
	bl SetMainCallback2
	ldr r1, =gBattle_WIN1H
	movs r0, 0xF0
	strh r0, [r1]
	ldr r1, =gBattle_WIN1V
	ldr r2, =0x000080a0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =sub_80F68B4
	movs r1, 0x14
	bl CreateTask
	bl sub_80F7880
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080F5BE4
	ldrb r0, [r5, 0x8]
	orrs r0, r6
	strb r0, [r5, 0x8]
	b _080F5BEC
	.pool
_080F5BE4:
	movs r0, 0xDF
	lsls r0, 1
	bl PlayBGM
_080F5BEC:
	ldr r0, =sub_80F5C24
	bl SetVBlankCallback
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5B00

	thumb_func_start sub_80F5C00
sub_80F5C00: @ 80F5C00
	push {lr}
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTasks
	bl UpdatePaletteFade
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	pop {r0}
	bx r0
	thumb_func_end sub_80F5C00

	thumb_func_start sub_80F5C24
sub_80F5C24: @ 80F5C24
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
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5C24

	thumb_func_start sub_80F5CE4
sub_80F5CE4: @ 80F5CE4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, =gIsLinkContest
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080F5CF8
	b _080F5E2E
_080F5CF8:
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r0, r1, r6
	lsls r0, 3
	adds r4, r0, r2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0x1
	beq _080F5DE0
	cmp r0, 0x1
	bgt _080F5D20
	cmp r0, 0
	beq _080F5D2A
	b _080F5E2E
	.pool
_080F5D20:
	cmp r0, 0x2
	beq _080F5DF4
	cmp r0, 0x3
	beq _080F5E0A
	b _080F5E2E
_080F5D2A:
	bl sub_80DBED4
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F5D58
	movs r0, 0x23
	bl IncrementGameStat
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x8
	strh r0, [r1]
	bl InterviewBefore
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080F5D58
	bl InterviewAfter
_080F5D58:
	movs r0, 0x2
	bl sub_813BADC
	ldr r0, =gSpecialVar_ContestRank
	ldrb r0, [r0]
	bl sub_80DEDA8
	movs r0, 0xFE
	bl sub_80DEDA8
	ldr r1, =gUnknown_02039F5C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0xFE
	movs r1, 0
	bl sub_80DEFA8
	ldr r1, =gUnknown_02039F5D
	strb r0, [r1]
	ldr r5, =0x00004086
	adds r0, r5, 0
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	bl sub_8076D5C
	movs r0, 0x1
	bl TrySavingData
	bl sav2_gender2_inplace_and_xFE
	adds r0, r5, 0
	adds r1, r4, 0
	bl VarSet
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080F5E2E
	.pool
_080F5DE0:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldrb r1, [r3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080F5E2E
	movs r0, 0x64
	b _080F5E2C
_080F5DF4:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080F5EBA
	bl sub_800ADF8
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080F5EBA
_080F5E0A:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080F5EBA
	movs r0, 0xDF
	lsls r0, 1
	bl PlayBGM
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
_080F5E2C:
	strh r0, [r4, 0x8]
_080F5E2E:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080F5EBA
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	strh r2, [r4, 0x8]
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080F5E78
	ldr r0, =gText_CommunicationStandby
	bl sub_80F707C
	ldr r0, =sub_80F5ED8
	b _080F5EB8
	.pool
_080F5E78:
	movs r0, 0x24
	bl IncrementGameStat
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F5E92
	movs r0, 0x25
	bl IncrementGameStat
_080F5E92:
	ldr r0, =gSpecialVar_ContestRank
	ldrb r0, [r0]
	bl sub_80DEDA8
	movs r0, 0xFE
	bl sub_80DEDA8
	ldr r0, =gUnknown_02039F5C
	strb r5, [r0]
	movs r0, 0xFE
	movs r1, 0
	bl sub_80DEFA8
	ldr r1, =gUnknown_02039F5D
	strb r0, [r1]
	movs r0, 0x2
	bl sub_813BADC
	ldr r0, =sub_80F5F74
_080F5EB8:
	str r0, [r4]
_080F5EBA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5CE4

	thumb_func_start sub_80F5ED8
sub_80F5ED8: @ 80F5ED8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F5EFC
	ldr r0, =sub_80F5F14
	movs r1, 0
	bl CreateTask
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =TaskDummy
	str r1, [r0]
_080F5EFC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5ED8

	thumb_func_start sub_80F5F14
sub_80F5F14: @ 80F5F14
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FC998
	ldr r2, =sub_80F5F30
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5F14

	thumb_func_start sub_80F5F30
sub_80F5F30: @ 80F5F30
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080F5F60
	adds r0, r4, 0
	bl DestroyTask
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_80F5F74
	str r1, [r0]
	bl sub_80F7144
_080F5F60:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5F30

	thumb_func_start sub_80F5F74
sub_80F5F74: @ 80F5F74
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080F5FC4
	ldr r0, =sub_80F68F0
	movs r1, 0x14
	bl CreateTask
	ldr r0, =gText_AnnouncingResults
	ldr r1, =gUnknown_0203A034
	ldr r1, [r1]
	ldr r1, [r1]
	ldrb r1, [r1]
	bl sub_80F6B78
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x88
	lsls r3, 3
	movs r1, 0x90
	movs r2, 0x78
	b _080F6016
	.pool
_080F5FC4:
	cmp r0, 0x1
	bne _080F5FDC
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _080F6048
	b _080F5FF0
	.pool
_080F5FDC:
	cmp r0, 0x2
	bne _080F5FF8
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _080F6048
	movs r0, 0
_080F5FF0:
	strh r0, [r4, 0xA]
	adds r0, r1, 0x1
	strh r0, [r4, 0x8]
	b _080F6048
_080F5FF8:
	cmp r0, 0x3
	bne _080F6030
	ldr r0, =gText_PreliminaryResults
	ldr r1, =gUnknown_0203A034
	ldr r1, [r1]
	ldr r1, [r1]
	ldrb r1, [r1]
	bl sub_80F6B78
	lsls r0, 16
	asrs r0, 16
	ldr r2, =0x0000ffff
	movs r3, 0x88
	lsls r3, 3
	movs r1, 0x90
_080F6016:
	bl sub_80F6E9C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080F6048
	.pool
_080F6030:
	cmp r0, 0x4
	bne _080F6048
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2
	bne _080F6048
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =sub_80F6058
	str r0, [r4]
_080F6048:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F5F74

	thumb_func_start sub_80F6058
sub_80F6058: @ 80F6058
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080F60C0
	cmp r0, 0x1
	bgt _080F6080
	cmp r0, 0
	beq _080F6086
	b _080F60E6
	.pool
_080F6080:
	cmp r0, 0x2
	beq _080F60D4
	b _080F60E6
_080F6086:
	ldr r5, =gUnknown_0203A034
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	bne _080F60E6
	ldrh r1, [r4, 0xC]
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_80F7A80
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080F60B8
	movs r0, 0x2
	strh r0, [r4, 0x8]
	b _080F60E6
	.pool
_080F60B8:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080F60E6
_080F60C0:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080F60E6
	strh r0, [r4, 0x8]
	b _080F60E6
	.pool
_080F60D4:
	movs r0, 0x88
	lsls r0, 3
	bl sub_80F6EF4
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xC]
	ldr r0, =sub_80F60F0
	str r0, [r4]
_080F60E6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6058

	thumb_func_start sub_80F60F0
sub_80F60F0: @ 80F60F0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r4, r2, 0
	ldr r0, =gUnknown_0203A034
	ldr r5, [r0]
	ldr r0, [r5]
	ldrb r3, [r0, 0x4]
	cmp r3, 0
	bne _080F614C
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _080F615E
	strh r3, [r1, 0xA]
	ldr r0, =gText_Round2Results
	ldr r1, [r5]
	ldrb r1, [r1]
	bl sub_80F6B78
	lsls r0, 16
	asrs r0, 16
	ldr r2, =0x0000ffff
	movs r3, 0x88
	lsls r3, 3
	movs r1, 0x90
	bl sub_80F6E9C
	b _080F615E
	.pool
_080F614C:
	cmp r3, 0x2
	bne _080F615E
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80F616C
	str r0, [r1]
_080F615E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F60F0

	thumb_func_start sub_80F616C
sub_80F616C: @ 80F616C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080F61D4
	cmp r0, 0x1
	bgt _080F6194
	cmp r0, 0
	beq _080F619A
	b _080F61F8
	.pool
_080F6194:
	cmp r0, 0x2
	beq _080F61E8
	b _080F61F8
_080F619A:
	ldr r5, =gUnknown_0203A034
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	bne _080F61F8
	ldrh r1, [r4, 0xC]
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	bl sub_80F7A80
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080F61CC
	movs r0, 0x2
	strh r0, [r4, 0x8]
	b _080F61F8
	.pool
_080F61CC:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080F61F8
_080F61D4:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080F61F8
	strh r0, [r4, 0x8]
	b _080F61F8
	.pool
_080F61E8:
	movs r0, 0x88
	lsls r0, 3
	bl sub_80F6EF4
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =sub_80F6204
	str r0, [r4]
_080F61F8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F616C

	thumb_func_start sub_80F6204
sub_80F6204: @ 80F6204
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x64
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
	cmp r0, 0x5
	bls _080F6226
	b _080F63F4
_080F6226:
	lsls r0, 2
	ldr r1, =_080F6238
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F6238:
	.4byte _080F6250
	.4byte _080F6274
	.4byte _080F6292
	.4byte _080F62CC
	.4byte _080F6334
	.4byte _080F63E4
_080F6250:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080F625E
	b _080F63F4
_080F625E:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080F63F4
	.pool
_080F6274:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	beq _080F628C
	b _080F63F4
_080F628C:
	movs r0, 0
	strh r0, [r1, 0xA]
	b _080F63BC
_080F6292:
	movs r4, 0
	lsls r6, r5, 2
	ldr r7, =gTasks
_080F6298:
	ldr r0, =sub_80F73DC
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r7
	ldr r0, =gContestFinalStandings
	adds r0, r4, r0
	ldrb r0, [r0]
	strh r0, [r1, 0x8]
	strh r4, [r1, 0xA]
	adds r4, 0x1
	cmp r4, 0x3
	ble _080F6298
	b _080F63B4
	.pool
_080F62CC:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x5]
	cmp r0, 0x4
	beq _080F62DA
	b _080F63F4
_080F62DA:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	beq _080F62F2
	b _080F63F4
_080F62F2:
	movs r0, 0
	strh r0, [r4, 0xA]
	ldr r0, =sub_80F74BC
	movs r1, 0xA
	bl CreateTask
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r4, 0
	ldr r1, =gContestFinalStandings
	ldrb r0, [r1]
	cmp r0, 0
	beq _080F631C
_080F630E:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080F631C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F630E
_080F631C:
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0xE
	bl sub_80F77E0
	b _080F63F4
	.pool
_080F6334:
	lsls r1, r5, 2
	adds r0, r1, r5
	lsls r0, 3
	adds r2, r0, r2
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	adds r6, r1, 0
	cmp r0, 0x15
	bne _080F63F4
	movs r0, 0
	strh r0, [r2, 0xA]
	movs r4, 0
	ldr r1, =gContestFinalStandings
	ldrb r0, [r1]
	ldr r7, =gStringVar1
	ldr r2, =gContestMons + 13
	mov r8, r2
	cmp r0, 0
	beq _080F636E
_080F6360:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080F636E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F6360
_080F636E:
	lsls r4, 6
	mov r0, r8
	adds r1, r4, r0
	adds r0, r7, 0
	bl StringCopy
	adds r0, r7, 0
	bl sub_81DB5AC
	ldr r0, =gStringVar2
	mov r1, r8
	subs r1, 0xB
	adds r4, r1
	adds r1, r4, 0
	bl StringCopy
	ldr r1, =gText_Var1sVar2Won
	mov r0, sp
	bl StringExpandPlaceholders
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0]
	mov r0, sp
	bl sub_80F6B78
	lsls r0, 16
	asrs r0, 16
	ldr r2, =0x0000ffff
	movs r3, 0x88
	lsls r3, 3
	movs r1, 0x90
	bl sub_80F6E9C
_080F63B4:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
_080F63BC:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080F63F4
	.pool
_080F63E4:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x8]
	ldr r1, =sub_80F6404
	str r1, [r0]
_080F63F4:
	add sp, 0x64
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6204

	thumb_func_start sub_80F6404
sub_80F6404: @ 80F6404
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _080F6428
	b _080F669C
_080F6428:
	lsls r0, 2
	ldr r1, =_080F643C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F643C:
	.4byte _080F6454
	.4byte _080F658C
	.4byte _080F65DC
	.4byte _080F65F0
	.4byte _080F6638
	.4byte _080F667C
_080F6454:
	ldr r1, =gBattle_WIN0H
	movs r0, 0xF0
	strh r0, [r1]
	ldr r1, =gBattle_WIN0V
	ldr r3, =0x00005050
	adds r0, r3, 0
	strh r0, [r1]
	movs r2, 0
	ldr r1, =gContestFinalStandings
	ldrb r0, [r1]
	lsls r4, r7, 2
	mov r10, r4
	ldr r3, =gContestMons
	ldr r4, =gContestPlayerMonIndex
	mov r9, r4
	ldr r4, =gMonFrontPicTable
	mov r12, r4
	ldr r4, =gMonSpritesGfxPtr
	mov r8, r4
	cmp r0, 0
	beq _080F648C
_080F647E:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080F648C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F647E
_080F648C:
	lsls r1, r2, 6
	adds r0, r1, r3
	ldrh r6, [r0]
	adds r0, r3, 0
	adds r0, 0x38
	adds r0, r1, r0
	ldr r4, [r0]
	adds r0, r3, 0
	adds r0, 0x3C
	adds r1, r0
	ldr r5, [r1]
	mov r0, r9
	ldrb r0, [r0]
	cmp r2, r0
	bne _080F64E0
	lsls r0, r6, 3
	add r0, r12
	mov r2, r8
	ldr r1, [r2]
	ldr r1, [r1, 0x8]
	adds r2, r6, 0
	adds r3, r4, 0
	bl HandleLoadSpecialPokePic_2
	b _080F64F2
	.pool
_080F64E0:
	lsls r0, r6, 3
	add r0, r12
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1, 0x8]
	adds r2, r6, 0
	adds r3, r4, 0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
_080F64F2:
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl GetMonSpritePalStructFromOtIdPersonality
	adds r4, r0, 0
	bl LoadCompressedSpritePalette
	adds r0, r6, 0
	movs r1, 0x1
	bl SetMultiuseSpriteTemplateToPokemon
	ldr r0, =gMultiuseSpriteTemplate
	ldrh r1, [r4, 0x4]
	strh r1, [r0, 0x2]
	movs r1, 0x88
	lsls r1, 1
	movs r2, 0x50
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r3, r2, r5
	strh r6, [r3, 0x30]
	ldrb r4, [r3, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r4
	strb r1, [r3, 0x5]
	adds r5, 0x1C
	adds r2, r5
	ldr r1, =sub_80F75A8
	str r1, [r2]
	ldr r1, =gUnknown_0203A034
	ldr r1, [r1]
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	ldr r0, =gUnknown_0858D878
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_0858D880
	bl LoadCompressedSpritePalette
	ldr r0, =sub_80F7670
	movs r1, 0xA
	bl CreateTask
	ldr r0, =gTasks
	mov r4, r10
	adds r1, r4, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080F669C
	.pool
_080F658C:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r4, r0, r4
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _080F65A4
	b _080F669C
_080F65A4:
	movs r0, 0
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0xC]
	adds r0, 0x2
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	ble _080F65BA
	movs r0, 0x20
	strh r0, [r4, 0xC]
_080F65BA:
	ldrb r2, [r4, 0xC]
	ldr r3, =gBattle_WIN0V
	movs r0, 0x50
	subs r0, r2
	lsls r0, 8
	adds r1, r2, 0
	adds r1, 0x50
	orrs r0, r1
	strh r0, [r3]
	cmp r2, 0x20
	bne _080F669C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080F669C
	.pool
_080F65DC:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0x1
	bne _080F669C
	b _080F6664
	.pool
_080F65F0:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r3, r0, r4
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x79
	bne _080F669C
	movs r0, 0
	strh r0, [r3, 0xA]
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_80F7620
	str r1, [r0]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _080F669C
	.pool
_080F6638:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0x2
	bne _080F669C
	ldr r3, =gBattle_WIN0V
	ldrh r0, [r3]
	lsrs r2, r0, 8
	adds r0, r2, 0x2
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x50
	bls _080F6656
	movs r2, 0x50
_080F6656:
	lsls r1, r2, 8
	movs r0, 0xA0
	subs r0, r2
	orrs r1, r0
	strh r1, [r3]
	cmp r2, 0x50
	bne _080F669C
_080F6664:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r4
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080F669C
	.pool
_080F667C:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	cmp r0, 0x2
	bne _080F669C
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x9]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r4
	strh r1, [r0, 0x8]
	ldr r1, =sub_80F66B4
	str r1, [r0]
_080F669C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6404

	thumb_func_start sub_80F66B4
sub_80F66B4: @ 80F66B4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080F6702
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	lsls r6, r7, 2
	cmp r0, 0
	bne _080F66F2
	ldr r5, =gContestMons
	movs r4, 0x3
_080F66DA:
	ldrh r0, [r5]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2
	bl GetSetPokedexFlag
	adds r5, 0x40
	subs r4, 0x1
	cmp r4, 0
	bge _080F66DA
_080F66F2:
	ldr r1, =gTasks
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	ldr r1, =sub_80F671C
	str r1, [r0]
_080F6702:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F66B4

	thumb_func_start sub_80F671C
sub_80F671C: @ 80F671C
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F6760
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r4, r1, r0
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080F676E
	ldr r0, =gText_CommunicationStandby
	bl sub_80F707C
	bl sub_800AC34
	ldr r0, =sub_80F677C
	str r0, [r4]
	b _080F676E
	.pool
_080F6760:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_repel
	str r0, [r1]
_080F676E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F671C

	thumb_func_start sub_80F677C
sub_80F677C: @ 80F677C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F67AC
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080F679A
	bl sub_800E084
_080F679A:
	bl sub_80F7144
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_repel
	str r0, [r1]
_080F67AC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F677C

	thumb_func_start task_repel
task_repel: @ 80F67C4
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080F67E6
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	bl BravoTrainerPokemonProfile_BeforeInterview2
_080F67E6:
	movs r0, 0
	str r0, [sp]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginHardwarePaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80F6820
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_repel

	thumb_func_start sub_80F6820
sub_80F6820: @ 80F6820
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r5, r2, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080F68A8
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080F6868
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	bl DestroyTask
	ldr r0, =0x0000ffff
	b _080F686E
	.pool
_080F6868:
	cmp r0, 0x1
	bne _080F6884
	ldr r0, =0xffff0000
_080F686E:
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _080F68A8
	.pool
_080F6884:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
	bl FreeAllWindowBuffers
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	bl SetMainCallback2
	bl sub_80F7E64
_080F68A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6820

	thumb_func_start sub_80F68B4
sub_80F68B4: @ 80F68B4
	push {r4,r5,lr}
	ldr r2, =gBattle_BG3_X
	ldrh r3, [r2]
	adds r0, r3, 0x2
	strh r0, [r2]
	ldr r4, =gBattle_BG3_Y
	ldrh r5, [r4]
	adds r1, r5, 0x1
	strh r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xFF
	bls _080F68D4
	adds r0, r3, 0
	subs r0, 0xFD
	strh r0, [r2]
_080F68D4:
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0xFF
	bls _080F68E2
	adds r0, r5, 0
	subs r0, 0xFE
	strh r0, [r4]
_080F68E2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F68B4

	thumb_func_start sub_80F68F0
sub_80F68F0: @ 80F68F0
	push {r4,r5,lr}
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
	cmp r0, 0x2
	bne _080F6972
	movs r0, 0
	strh r0, [r2, 0x8]
	movs r3, 0xC
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _080F6924
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	b _080F6928
	.pool
_080F6924:
	ldrh r0, [r2, 0xA]
	subs r0, 0x1
_080F6928:
	strh r0, [r2, 0xA]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0x10
	bne _080F693E
	movs r0, 0x1
	b _080F6942
_080F693E:
	cmp r0, 0
	bne _080F6944
_080F6942:
	strh r0, [r1, 0xC]
_080F6944:
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrb r2, [r4, 0xA]
	ldr r3, =0x00002ede
	movs r0, 0x6B
	movs r1, 0x1
	bl BlendPalette
	ldrb r2, [r4, 0xA]
	ldr r3, =0x00007fff
	movs r0, 0x68
	movs r1, 0x1
	bl BlendPalette
	ldrb r2, [r4, 0xA]
	ldr r3, =0x000077be
	movs r0, 0x6E
	movs r1, 0x1
	bl BlendPalette
_080F6972:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r3, 0xA
	ldrsh r4, [r0, r3]
	cmp r4, 0
	bne _080F69A4
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	strb r4, [r0, 0xA]
	b _080F69AE
	.pool
_080F69A4:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xA]
_080F69AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F68F0

	thumb_func_start sub_80F69B8
sub_80F69B8: @ 80F69B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	mov r8, r4
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	ldr r0, =gContestPlayerMonIndex
	movs r2, 0
	ldrb r0, [r0]
	cmp r4, r0
	bne _080F69DE
	movs r2, 0x1
_080F69DE:
	adds r0, r7, 0
	ldr r1, [sp, 0x28]
	bl GetMonIconPtr
	adds r3, r0, 0
	lsls r0, r5, 9
	adds r0, 0x80
	adds r3, r0
	cmp r6, 0
	beq _080F6A40
	lsls r1, r4, 9
	ldr r0, =0x06004000
	adds r1, r0
	movs r2, 0xC0
	lsls r2, 1
	adds r0, r3, 0
	movs r3, 0x1
	bl RequestDma3Copy
	adds r0, r4, 0
	adds r0, 0xA
	lsls r0, 28
	lsls r1, r4, 20
	movs r2, 0x80
	lsls r2, 18
	adds r1, r2
	orrs r1, r0
	lsrs r1, 16
	lsls r3, r4, 1
	adds r3, r4
	adds r3, 0x4
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r2, 0x3
	bl WriteSequenceToBgTilemapBuffer
	b _080F6A54
	.pool
_080F6A40:
	mov r0, r8
	lsls r1, r0, 9
	ldr r2, =0x06004000
	adds r1, r2
	movs r2, 0xC0
	lsls r2, 1
	adds r0, r3, 0
	movs r3, 0x1
	bl RequestDma3Copy
_080F6A54:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F69B8

	thumb_func_start sub_80F6A64
sub_80F6A64: @ 80F6A64
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	movs r5, 0
	ldr r4, =gContestMons
_080F6A74:
	ldrh r0, [r4]
	lsls r1, r5, 24
	lsrs r1, 24
	ldr r2, [r4, 0x38]
	str r2, [sp]
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_80F69B8
	adds r4, 0x40
	adds r5, 0x1
	cmp r5, 0x3
	ble _080F6A74
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6A64

	thumb_func_start sub_80F6A9C
sub_80F6A9C: @ 80F6A9C
	push {r4-r6,lr}
	movs r4, 0
	ldr r6, =gMonIconPaletteIndices
	movs r5, 0xA0
	lsls r5, 16
_080F6AA6:
	ldr r1, =gContestMons
	lsls r0, r4, 6
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0
	bl GetIconSpecies
	lsls r0, 16
	lsrs r0, 16
	adds r0, r6
	ldrb r0, [r0]
	lsls r0, 5
	ldr r1, =gMonIconPalettes
	adds r0, r1
	lsrs r1, r5, 16
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x80
	lsls r0, 13
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x3
	ble _080F6AA6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6A9C

	thumb_func_start sub_80F6AE8
sub_80F6AE8: @ 80F6AE8
	push {r4,lr}
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080F6B58
	bl sub_800E0E8
	movs r0, 0x8
	movs r1, 0x8
	bl CreateWirelessStatusIndicatorSprite
	ldr r4, =gSprites
	ldr r0, =gWirelessStatusIndicatorSpriteId
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x43
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, =gUnknown_0858D8E0
	bl LoadSpriteSheet
	adds r1, r0, 0
	lsls r1, 16
	movs r0, 0x1
	negs r0, r0
	lsrs r1, 11
	ldr r2, =0x06010000
	adds r1, r2
	movs r2, 0x80
	movs r3, 0x1
	bl RequestDma3Fill
	ldr r0, =gSpriteTemplate_858D8C8
	movs r1, 0x8
	movs r2, 0x8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x1]
_080F6B58:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6AE8

	thumb_func_start sub_80F6B78
sub_80F6B78: @ 80F6B78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	adds r5, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	add r4, sp, 0x20
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r0, 0x1E
	strb r0, [r4, 0x3]
	movs r0, 0x2
	strb r0, [r4, 0x4]
	adds r0, r4, 0
	bl AddWindow
	lsls r6, r0, 24
	lsrs r4, r6, 24
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r2, r0, 0
	adds r2, 0x9
	cmp r2, 0
	bge _080F6BC4
	adds r2, 0x7
_080F6BC4:
	asrs r2, 3
	mov r10, r2
	cmp r2, 0x1E
	ble _080F6BD0
	movs r1, 0x1E
	mov r10, r1
_080F6BD0:
	mov r1, r10
	lsls r2, r1, 3
	subs r2, r0
	lsrs r0, r2, 31
	adds r2, r0
	asrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0858D8E8
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	adds r0, r4, 0
	movs r1, 0x7
	bl GetWindowAttribute
	mov r9, r0
	ldr r2, =gUnknown_0858D6D0
	mov r8, r2
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	ldr r3, =gSprites
	adds r1, r3
	ldrh r0, [r1, 0x4]
	lsls r0, 22
	lsrs r0, 17
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [sp, 0xC]
	str r6, [sp, 0x38]
	mov r7, sp
	adds r7, 0x1C
	str r7, [sp, 0x2C]
	mov r0, r10
	adds r0, 0x2
	str r0, [sp, 0x30]
	movs r5, 0
	add r7, sp, 0x10
	mov r12, r7
	adds r6, r1, 0
	adds r6, 0x2E
	movs r4, 0x2
_080F6C34:
	adds r0, r6, r5
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x4]
	lsls r0, 22
	lsrs r0, 17
	adds r0, r2
	mov r1, r12
	adds r1, 0x4
	mov r12, r1
	subs r1, 0x4
	stm r1!, {r0}
	adds r5, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _080F6C34
	mov r7, r8
	adds r7, 0x80
	mov r2, r8
	adds r2, 0x40
	str r2, [sp, 0x28]
	mov r0, r8
	adds r0, 0x20
	str r0, [sp, 0x3C]
	mov r1, r8
	adds r1, 0xA0
	str r1, [sp, 0x40]
	adds r2, 0x20
	str r2, [sp, 0x34]
	add r5, sp, 0xC
	movs r6, 0
	movs r4, 0x3
_080F6C7C:
	str r6, [sp, 0x1C]
	ldm r5!, {r1}
	ldr r0, [sp, 0x2C]
	ldr r2, =0x05000100
	bl CpuSet
	subs r4, 0x1
	cmp r4, 0
	bge _080F6C7C
	ldr r5, [sp, 0xC]
	ldr r6, =0x04000008
	mov r0, r8
	adds r1, r5, 0
	adds r2, r6, 0
	bl CpuSet
	movs r0, 0x80
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r7, 0
	adds r2, r6, 0
	bl CpuSet
	movs r2, 0x80
	lsls r2, 2
	adds r1, r5, r2
	adds r0, r7, 0
	adds r2, r6, 0
	bl CpuSet
	movs r7, 0xC0
	lsls r7, 2
	adds r1, r5, r7
	ldr r0, [sp, 0x28]
	adds r2, r6, 0
	bl CpuSet
	movs r4, 0
	cmp r4, r10
	bge _080F6D32
	adds r7, r6, 0
_080F6CCE:
	adds r6, r4, 0x1
	adds r0, r6, 0
	cmp r6, 0
	bge _080F6CDA
	adds r0, r4, 0
	adds r0, 0x8
_080F6CDA:
	asrs r0, 3
	lsls r1, r0, 2
	add r1, sp
	adds r1, 0xC
	lsls r0, 3
	subs r0, r6, r0
	lsls r0, 5
	ldr r1, [r1]
	adds r5, r1, r0
	mov r0, r8
	adds r0, 0xC0
	adds r1, r5, 0
	adds r2, r7, 0
	bl CpuSet
	movs r0, 0x80
	lsls r0, 1
	adds r1, r5, r0
	mov r0, r9
	adds r2, r7, 0
	bl CpuSet
	movs r0, 0xF0
	lsls r0, 2
	add r0, r9
	movs r2, 0x80
	lsls r2, 2
	adds r1, r5, r2
	adds r2, r7, 0
	bl CpuSet
	movs r0, 0xC0
	lsls r0, 2
	adds r1, r5, r0
	mov r0, r8
	adds r0, 0xE0
	adds r2, r7, 0
	bl CpuSet
	movs r1, 0x20
	add r9, r1
	adds r4, r6, 0
	cmp r4, r10
	blt _080F6CCE
_080F6D32:
	adds r2, r4, 0x1
	adds r0, r2, 0
	cmp r2, 0
	bge _080F6D3E
	adds r0, r4, 0
	adds r0, 0x8
_080F6D3E:
	asrs r0, 3
	lsls r1, r0, 2
	add r1, sp
	adds r1, 0xC
	lsls r0, 3
	subs r0, r2, r0
	lsls r0, 5
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r4, =0x04000008
	ldr r0, [sp, 0x3C]
	adds r1, r5, 0
	adds r2, r4, 0
	bl CpuSet
	movs r2, 0x80
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, [sp, 0x40]
	adds r2, r4, 0
	bl CpuSet
	movs r7, 0x80
	lsls r7, 2
	adds r1, r5, r7
	ldr r0, [sp, 0x40]
	adds r2, r4, 0
	bl CpuSet
	movs r0, 0xC0
	lsls r0, 2
	adds r1, r5, r0
	ldr r0, [sp, 0x34]
	adds r2, r4, 0
	bl CpuSet
	ldr r1, [sp, 0x38]
	lsrs r0, r1, 24
	bl RemoveWindow
	ldr r2, [sp, 0x30]
	lsls r1, r2, 3
	movs r0, 0xF0
	subs r0, r1
	asrs r0, 1
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F6B78

	thumb_func_start sub_80F6DC0
sub_80F6DC0: @ 80F6DC0
	push {r4-r6,lr}
	sub sp, 0x20
	mov r1, sp
	ldr r0, =gSpriteTemplate_858D7F8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r5, sp, 0x18
	ldr r6, =gUnknown_0858D810
	movs r4, 0x7
_080F6DD6:
	adds r0, r6, 0
	bl LoadSpriteSheet
	adds r6, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _080F6DD6
	ldr r0, =gUnknown_0858D850
	bl LoadSpritePalette
	movs r4, 0
	mov r6, sp
_080F6DEE:
	mov r0, sp
	movs r1, 0x88
	lsls r1, 1
	movs r2, 0x90
	movs r3, 0xA
	bl CreateSprite
	adds r1, r5, r4
	strb r0, [r1]
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	adds r4, 0x1
	cmp r4, 0x7
	ble _080F6DEE
	ldr r2, =gSprites
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r5, 0x1]
	movs r3, 0
	strh r1, [r0, 0x2E]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r5, 0x2]
	strh r1, [r0, 0x30]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r5, 0x3]
	strh r1, [r0, 0x32]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r5, 0x5]
	strh r1, [r0, 0x2E]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r5, 0x6]
	strh r1, [r0, 0x30]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r5, 0x7]
	strh r1, [r0, 0x32]
	ldr r1, =gUnknown_0203A034
	ldr r0, [r1]
	ldr r2, [r0]
	ldrb r0, [r5]
	strb r0, [r2]
	ldr r0, [r1]
	ldr r0, [r0]
	strb r3, [r0, 0x4]
	ldr r0, [r1]
	ldr r1, [r0]
	ldrb r0, [r5, 0x4]
	strb r0, [r1, 0x1]
	bl sub_80F7144
	add sp, 0x20
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6DC0

	thumb_func_start sub_80F6E9C
sub_80F6E9C: @ 80F6E9C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r4, =gUnknown_0203A034
	ldr r4, [r4]
	mov r8, r4
	ldr r4, [r4]
	ldrb r5, [r4]
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	ldr r5, =gSprites
	adds r4, r5
	movs r6, 0
	movs r5, 0x88
	lsls r5, 1
	strh r5, [r4, 0x20]
	strh r1, [r4, 0x22]
	strh r6, [r4, 0x24]
	strh r6, [r4, 0x26]
	lsls r0, 16
	asrs r0, 16
	adds r0, 0x20
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x38]
	strh r3, [r4, 0x3A]
	strh r6, [r4, 0x3C]
	ldr r0, =sub_80F6F68
	str r0, [r4, 0x1C]
	mov r0, r8
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6E9C

	thumb_func_start sub_80F6EF4
sub_80F6EF4: @ 80F6EF4
	push {r4,r5,lr}
	ldr r1, =gUnknown_0203A034
	ldr r4, [r1]
	ldr r1, [r4]
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gSprites
	adds r1, r2
	ldrh r2, [r1, 0x24]
	ldrh r3, [r1, 0x20]
	adds r2, r3
	movs r3, 0
	strh r2, [r1, 0x20]
	ldrh r2, [r1, 0x26]
	ldrh r5, [r1, 0x22]
	adds r2, r5
	strh r2, [r1, 0x22]
	strh r3, [r1, 0x26]
	strh r3, [r1, 0x24]
	strh r0, [r1, 0x3A]
	strh r3, [r1, 0x3C]
	ldr r0, =sub_80F7014
	str r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r0, 0x3
	strb r0, [r1, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6EF4

	thumb_func_start sub_80F6F40
sub_80F6F40: @ 80F6F40
	movs r3, 0
	movs r2, 0
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	movs r1, 0x90
	strh r1, [r0, 0x22]
	strh r2, [r0, 0x26]
	strh r2, [r0, 0x24]
	ldr r1, =SpriteCallbackDummy
	str r1, [r0, 0x1C]
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	strb r3, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_80F6F40

	thumb_func_start sub_80F6F68
sub_80F6F68: @ 80F6F68
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x3A]
	ldrh r0, [r3, 0x3C]
	adds r2, r0
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r3, 0x20]
	subs r0, r1
	strh r0, [r3, 0x20]
	movs r1, 0xFF
	ands r2, r1
	strh r2, [r3, 0x3C]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r3, 0x36]
	movs r4, 0x36
	ldrsh r1, [r3, r4]
	cmp r0, r1
	bge _080F6F92
	strh r2, [r3, 0x20]
_080F6F92:
	movs r4, 0
	ldr r6, =gSprites
	movs r5, 0x40
	adds r2, r3, 0
	adds r2, 0x2E
_080F6F9C:
	movs r7, 0
	ldrsh r0, [r2, r7]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r3, 0x24]
	ldrh r7, [r3, 0x20]
	adds r0, r7
	adds r0, r5
	strh r0, [r1, 0x20]
	adds r5, 0x40
	adds r2, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _080F6F9C
	movs r0, 0x20
	ldrsh r1, [r3, r0]
	movs r2, 0x36
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bne _080F6FCC
	ldr r0, =sub_80F6FDC
	str r0, [r3, 0x1C]
_080F6FCC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6F68

	thumb_func_start sub_80F6FDC
sub_80F6FDC: @ 80F6FDC
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1, 0x4]
	ldrh r3, [r2, 0x38]
	ldr r1, =0xffff0000
	lsrs r0, r1, 16
	cmp r3, r0
	beq _080F7008
	subs r0, r3, 0x1
	strh r0, [r2, 0x38]
	lsls r0, 16
	asrs r0, 16
	asrs r1, 16
	cmp r0, r1
	bne _080F7008
	ldrh r0, [r2, 0x3A]
	bl sub_80F6EF4
_080F7008:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F6FDC

	thumb_func_start sub_80F7014
sub_80F7014: @ 80F7014
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x3A]
	ldrh r0, [r3, 0x3C]
	adds r2, r0
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r3, 0x20]
	subs r0, r1
	strh r0, [r3, 0x20]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r3, 0x3C]
	movs r4, 0
	ldr r6, =gSprites
	movs r5, 0x40
	adds r2, r3, 0
	adds r2, 0x2E
_080F7038:
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r3, 0x24]
	ldrh r7, [r3, 0x20]
	adds r0, r7
	adds r0, r5
	strh r0, [r1, 0x20]
	adds r5, 0x40
	adds r2, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _080F7038
	movs r1, 0x20
	ldrsh r0, [r3, r1]
	movs r2, 0x24
	ldrsh r1, [r3, r2]
	adds r0, r1
	movs r1, 0xE0
	negs r1, r1
	cmp r0, r1
	bge _080F7070
	adds r0, r3, 0
	bl sub_80F6F40
_080F7070:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7014

	thumb_func_start sub_80F707C
sub_80F707C: @ 80F707C
	push {r4-r7,lr}
	ldr r4, =gUnknown_0203A034
	ldr r1, [r4]
	ldr r1, [r1]
	ldrb r1, [r1, 0x1]
	bl sub_80F6B78
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4]
	ldr r1, [r1]
	ldrb r2, [r1, 0x1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r3, =gSprites
	adds r4, r1, r3
	adds r0, 0x20
	strh r0, [r4, 0x20]
	movs r0, 0x50
	strh r0, [r4, 0x22]
	adds r5, r4, 0
	adds r5, 0x3E
	ldrb r1, [r5]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	strb r0, [r5]
	movs r5, 0
	adds r6, r3, 0
	mov r12, r2
	movs r3, 0x40
_080F70BE:
	lsls r0, r5, 1
	adds r2, r4, 0
	adds r2, 0x2E
	adds r2, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r4, 0x24]
	ldrh r7, [r4, 0x20]
	adds r0, r7
	adds r0, r3
	strh r0, [r1, 0x20]
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r4, 0x22]
	strh r1, [r0, 0x22]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x3E
	ldrb r2, [r1]
	mov r0, r12
	ands r0, r2
	strb r0, [r1]
	adds r3, 0x40
	adds r5, 0x1
	cmp r5, 0x2
	ble _080F70BE
	ldr r1, =gBattle_WIN0H
	movs r0, 0xF0
	strh r0, [r1]
	ldr r2, =gBattle_WIN0V
	ldrh r1, [r4, 0x22]
	adds r0, r1, 0
	subs r0, 0x10
	lsls r0, 8
	adds r1, 0x10
	orrs r0, r1
	strh r0, [r2]
	ldr r1, =0x00003f3e
	movs r0, 0x48
	bl SetGpuReg
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F707C

	thumb_func_start sub_80F7144
sub_80F7144: @ 80F7144
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r3, =gSprites
	adds r2, r3
	movs r0, 0x3E
	adds r0, r2
	mov r12, r0
	ldrb r0, [r0]
	movs r1, 0x4
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldr r7, =gBattle_WIN0H
	ldr r6, =gBattle_WIN0V
	adds r5, r3, 0
	movs r4, 0x4
	adds r2, 0x2E
	movs r3, 0x2
_080F7174:
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _080F7174
	movs r0, 0
	strh r0, [r7]
	strh r0, [r6]
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r6]
	movs r0, 0x44
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7144

	thumb_func_start sub_80F71C8
sub_80F71C8: @ 80F71C8
	push {r4-r6,lr}
	sub sp, 0xC
	movs r5, 0x5
	movs r4, 0x1
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080F71F8
	ldr r1, =gUnknown_08DC6498
	str r5, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r2, 0x5
	movs r3, 0x1
	bl CopyToBgTilemapBufferRect
	movs r5, 0xA
	b _080F7240
	.pool
_080F71F8:
	ldr r0, =gSpecialVar_ContestRank
	ldrh r2, [r0]
	cmp r2, 0
	bne _080F720C
	ldr r1, =gUnknown_08DC63F8
	b _080F722E
	.pool
_080F720C:
	cmp r2, 0x1
	bne _080F7218
	ldr r1, =gUnknown_08DC6420
	b _080F722E
	.pool
_080F7218:
	cmp r2, 0x2
	bne _080F722C
	ldr r1, =gUnknown_08DC6448
	movs r0, 0xA
	str r0, [sp]
	str r2, [sp, 0x4]
	movs r0, 0x2
	b _080F7236
	.pool
_080F722C:
	ldr r1, =gUnknown_08DC6470
_080F722E:
	movs r0, 0xA
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
_080F7236:
	movs r2, 0x5
	movs r3, 0x1
	bl CopyToBgTilemapBufferRect
	movs r5, 0xF
_080F7240:
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0
	bne _080F725C
	movs r6, 0
	ldr r1, =gUnknown_08DC64AC
	b _080F7298
	.pool
_080F725C:
	cmp r0, 0x1
	bne _080F726C
	movs r6, 0x1
	ldr r1, =gUnknown_08DC64C0
	b _080F7298
	.pool
_080F726C:
	cmp r0, 0x2
	bne _080F7290
	movs r6, 0x2
	ldr r1, =gUnknown_08DC64D4
	lsls r2, r5, 24
	lsrs r2, 24
	lsls r4, 24
	lsrs r3, r4, 24
	movs r0, 0x5
	str r0, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x2
	bl CopyToBgTilemapBufferRect
	b _080F72CC
	.pool
_080F7290:
	cmp r0, 0x3
	bne _080F72B4
	movs r6, 0x3
	ldr r1, =gUnknown_08DC64E8
_080F7298:
	lsls r2, r5, 24
	lsrs r2, 24
	lsls r4, 24
	lsrs r3, r4, 24
	movs r0, 0x5
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	bl CopyToBgTilemapBufferRect
	b _080F72CC
	.pool
_080F72B4:
	movs r6, 0x4
	ldr r1, =gUnknown_08DC64FC
	lsls r2, r5, 24
	lsrs r2, 24
	lsls r4, 24
	lsrs r3, r4, 24
	movs r0, 0x5
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	bl CopyToBgTilemapBufferRect
_080F72CC:
	adds r5, 0x5
	ldr r1, =gUnknown_08DC6510
	lsls r2, r5, 24
	lsrs r2, 24
	lsrs r3, r4, 24
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	bl CopyToBgTilemapBufferRect
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F71C8

	thumb_func_start sub_80F7310
sub_80F7310: @ 80F7310
	push {r4,r5,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, =gContestMonConditions
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r4, r0, 16
	adds r0, r4, 0
	movs r1, 0x3F
	bl __udivsi3
	adds r1, r0, 0
	ldr r0, =0x0000ffff
	ands r0, r1
	cmp r0, 0
	beq _080F733C
	movs r0, 0x80
	lsls r0, 9
	adds r1, r0
_080F733C:
	lsrs r1, 16
	cmp r1, 0
	bne _080F7348
	cmp r4, 0
	beq _080F7348
	movs r1, 0x1
_080F7348:
	cmp r5, 0
	beq _080F7352
	cmp r1, 0xA
	bls _080F7352
	movs r1, 0xA
_080F7352:
	lsls r0, r1, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F7310

	thumb_func_start sub_80F7364
sub_80F7364: @ 80F7364
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r1, =gUnknown_02039F18
	lsls r0, r5, 1
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r7, r1, 0
	cmp r0, 0
	bge _080F7380
	negs r0, r0
_080F7380:
	lsls r4, r0, 16
	adds r0, r4, 0
	movs r1, 0x50
	bl __udivsi3
	adds r2, r0, 0
	ldr r0, =0x0000ffff
	ands r0, r2
	cmp r0, 0
	beq _080F739A
	movs r0, 0x80
	lsls r0, 9
	adds r2, r0
_080F739A:
	lsrs r2, 16
	cmp r2, 0
	bne _080F73A6
	cmp r4, 0
	beq _080F73A6
	movs r2, 0x1
_080F73A6:
	cmp r6, 0
	beq _080F73B0
	cmp r2, 0xA
	bls _080F73B0
	movs r2, 0xA
_080F73B0:
	lsls r0, r5, 1
	adds r0, r7
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080F73CC
	negs r0, r2
	lsls r0, 24
	b _080F73CE
	.pool
_080F73CC:
	lsls r0, r2, 24
_080F73CE:
	lsrs r0, 24
	lsls r0, 24
	asrs r0, 24
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80F7364

	thumb_func_start sub_80F73DC
sub_80F73DC: @ 80F73DC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r7, r0, r1
	ldrh r2, [r7, 0x1C]
	movs r0, 0x1C
	ldrsh r6, [r7, r0]
	cmp r6, 0
	bne _080F741C
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	movs r1, 0x3
	subs r1, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	strh r0, [r7, 0x1E]
	adds r0, r2, 0x1
	strh r0, [r7, 0x1C]
	b _080F74A4
	.pool
_080F741C:
	cmp r6, 0x1
	bne _080F74A4
	ldrh r0, [r7, 0x1E]
	subs r0, 0x1
	strh r0, [r7, 0x1E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080F74A4
	movs r2, 0x8
	ldrsh r4, [r7, r2]
	lsls r4, 17
	ldr r0, =0x50430000
	adds r4, r0
	lsrs r4, 16
	movs r1, 0xA
	ldrsh r0, [r7, r1]
	lsls r3, r0, 1
	adds r3, r0
	adds r3, 0x5
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0x2
	mov r9, r2
	str r2, [sp]
	str r6, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x10
	lsls r4, 16
	lsrs r4, 16
	movs r1, 0xA
	ldrsh r0, [r7, r1]
	lsls r3, r0, 1
	adds r3, r0
	adds r3, 0x6
	lsls r3, 24
	lsrs r3, 24
	mov r2, r9
	str r2, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	bl WriteSequenceToBgTilemapBuffer
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	adds r0, 0x1
	strb r0, [r1, 0x5]
	mov r0, r8
	bl DestroyTask
	movs r0, 0x18
	bl PlaySE
_080F74A4:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F73DC

	thumb_func_start sub_80F74BC
sub_80F74BC: @ 80F74BC
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r1, =gContestFinalStandings
	ldrb r0, [r1]
	ldr r6, =gUnknown_0203A034
	cmp r0, 0
	beq _080F74DE
_080F74D0:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080F74DE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F74D0
_080F74DE:
	ldr r1, [r6]
	lsls r3, r4, 1
	adds r3, r4
	lsls r0, r3, 6
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	ldr r1, [r1, 0x14]
	adds r1, r0
	adds r3, 0x4
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x9
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x1C]
	movs r1, 0x1
	strh r1, [r0, 0x20]
	ldr r1, =sub_80F753C
	str r1, [r0]
	ldr r0, [r6]
	ldr r0, [r0]
	strb r5, [r0, 0x3]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F74BC

	thumb_func_start sub_80F753C
sub_80F753C: @ 80F753C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0x1
	bne _080F75A0
	movs r0, 0
	strh r0, [r4, 0x1E]
	ldrh r2, [r4, 0x20]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =0x00006f8d
	movs r0, 0x91
	movs r1, 0x1
	bl BlendPalette
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080F7590
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _080F75A0
	strh r5, [r4, 0x22]
	b _080F75A0
	.pool
_080F7590:
	ldrh r0, [r4, 0x20]
	subs r0, 0x1
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _080F75A0
	strh r0, [r4, 0x22]
_080F75A0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F753C

	thumb_func_start sub_80F75A8
sub_80F75A8: @ 80F75A8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x9
	bgt _080F75D0
	adds r0, r1, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _080F7610
	ldrh r0, [r4, 0x30]
	movs r1, 0
	bl PlayCry1
	movs r0, 0
	strh r0, [r4, 0x30]
	b _080F7610
_080F75D0:
	movs r0, 0xC0
	lsls r0, 3
	adds r2, r0, 0
	ldrh r1, [r4, 0x30]
	adds r2, r1
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x20]
	subs r0, r1
	strh r0, [r4, 0x20]
	movs r1, 0xFF
	ands r2, r1
	strh r2, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x77
	bgt _080F75F6
	movs r0, 0x78
	strh r0, [r4, 0x20]
_080F75F6:
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x78
	bne _080F7610
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x30]
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x6]
_080F7610:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F75A8

	thumb_func_start sub_80F7620
sub_80F7620: @ 80F7620
	push {lr}
	adds r3, r0, 0
	movs r0, 0xC0
	lsls r0, 3
	adds r2, r0, 0
	ldrh r0, [r3, 0x30]
	adds r2, r0
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r3, 0x20]
	subs r0, r1
	strh r0, [r3, 0x20]
	movs r1, 0xFF
	ands r2, r1
	strh r2, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _080F7664
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1, 0x6]
_080F7664:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7620

	thumb_func_start sub_80F7670
sub_80F7670: @ 80F7670
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _080F7732
	movs r0, 0
	strh r0, [r1, 0x8]
	ldr r0, =gUnknown_0203A034
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	cmp r0, 0x27
	bhi _080F7732
	ldr r4, =gSpriteTemplate_858D860
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r1, r0, 0
	subs r1, 0x14
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0x2C
	movs r3, 0x5
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl Random
	ldr r1, =gSprites
	lsls r5, r4, 4
	adds r5, r4
	lsls r5, 2
	adds r5, r1
	lsls r0, 23
	lsrs r0, 23
	strh r0, [r5, 0x2E]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x18
	bl __umodsi3
	adds r0, 0x10
	strh r0, [r5, 0x30]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xFF
	ands r0, r1
	adds r0, 0x30
	strh r0, [r5, 0x32]
	bl Random
	ldrh r6, [r5, 0x4]
	lsls r4, r6, 22
	lsrs r4, 22
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	adds r4, r0
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r4, r0
	ldr r0, =0xfffffc00
	ands r0, r6
	orrs r0, r4
	strh r0, [r5, 0x4]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	adds r0, 0x1
	strb r0, [r1, 0x7]
_080F7732:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080F7744
	adds r0, r7, 0
	bl DestroyTask
_080F7744:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7670

	thumb_func_start sub_80F7768
sub_80F7768: @ 80F7768
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r1, [r4, 0x32]
	ldrh r0, [r4, 0x36]
	adds r1, r0
	lsls r0, r1, 16
	asrs r0, 24
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0x36]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	ldr r5, =gUnknown_0203A034
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080F77B6
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080F77B6:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0xF8
	bgt _080F77C6
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0x74
	ble _080F77D6
_080F77C6:
	adds r0, r4, 0
	bl DestroySprite
	ldr r0, [r5]
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	subs r0, 0x1
	strb r0, [r1, 0x7]
_080F77D6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7768

	thumb_func_start sub_80F77E0
sub_80F77E0: @ 80F77E0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sub_80F7824
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	strh r5, [r1, 0xA]
	ldr r0, =gContestMons
	lsls r4, 6
	adds r4, r0
	ldrh r0, [r4]
	strh r0, [r1, 0xC]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F77E0

	thumb_func_start sub_80F7824
sub_80F7824: @ 80F7824
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrb r5, [r4, 0x8]
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _080F786E
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r0, [r4, 0xC]
	ldrb r2, [r4, 0x1E]
	ldr r1, =gContestMons
	lsls r3, r5, 6
	adds r1, 0x38
	adds r3, r1
	ldr r1, [r3]
	str r1, [sp]
	adds r1, r5, 0
	movs r3, 0
	bl sub_80F69B8
	ldrh r0, [r4, 0x1E]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x1E]
_080F786E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7824

	thumb_func_start sub_80F7880
sub_80F7880: @ 80F7880
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gUnknown_02039F08
	ldrh r2, [r0]
	adds r4, r0, 0
	adds r3, r4, 0x2
	movs r0, 0x2
	mov r8, r0
_080F7898:
	lsls r0, r2, 16
	asrs r0, 16
	movs r5, 0
	ldrsh r1, [r3, r5]
	cmp r0, r1
	bge _080F78A6
	ldrh r2, [r3]
_080F78A6:
	adds r3, 0x2
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, 0
	bge _080F7898
	lsls r0, r2, 16
	str r0, [sp]
	cmp r0, 0
	bge _080F78E4
	ldrh r2, [r4]
	adds r3, r4, 0x2
	movs r4, 0x2
	mov r8, r4
_080F78C4:
	lsls r0, r2, 16
	asrs r0, 16
	movs r5, 0
	ldrsh r1, [r3, r5]
	cmp r0, r1
	ble _080F78D2
	ldrh r2, [r3]
_080F78D2:
	adds r3, 0x2
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	lsls r1, r2, 16
	str r1, [sp]
	mov r4, r8
	cmp r4, 0
	bge _080F78C4
_080F78E4:
	movs r5, 0
	mov r8, r5
	mov r10, r5
_080F78EA:
	ldr r0, =gContestMonConditions
	mov r1, r8
	lsls r7, r1, 1
	adds r0, r7, r0
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	ldr r4, [sp]
	asrs r5, r4, 16
	adds r1, r5, 0
	cmp r5, 0
	bge _080F790C
	negs r1, r5
_080F790C:
	bl __divsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __modsi3
	cmp r0, 0x4
	ble _080F791E
	adds r4, 0xA
_080F791E:
	ldr r0, =gUnknown_0203A034
	mov r9, r0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r6, r1, r0
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	str r0, [r6]
	ldr r0, =gUnknown_02039F18
	adds r7, r0
	movs r2, 0
	ldrsh r1, [r7, r2]
	cmp r1, 0
	bge _080F7942
	negs r1, r1
_080F7942:
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r5, 0
	cmp r1, 0
	bge _080F7954
	negs r1, r1
_080F7954:
	bl __divsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __modsi3
	cmp r0, 0x4
	ble _080F7966
	adds r4, 0xA
_080F7966:
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	str r0, [r6, 0x4]
	movs r4, 0
	ldrsh r0, [r7, r4]
	cmp r0, 0
	bge _080F797C
	movs r0, 0x1
	strb r0, [r6, 0x10]
_080F797C:
	mov r5, r9
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r4, r1, r0
	ldr r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	subs r0, r1
	lsls r0, 11
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	movs r5, 0xFF
	ands r0, r5
	cmp r0, 0x7F
	bls _080F79A8
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2
_080F79A8:
	lsrs r0, r1, 8
	str r0, [r4, 0x8]
	ldr r1, [r4, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	subs r0, r1
	lsls r0, 11
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	ands r0, r5
	cmp r0, 0x7F
	bls _080F79CC
	movs r5, 0x80
	lsls r5, 1
	adds r1, r5
_080F79CC:
	lsrs r0, r1, 8
	str r0, [r4, 0xC]
	mov r0, r8
	lsls r4, r0, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80F7310
	mov r2, r9
	ldr r1, [r2]
	ldr r1, [r1, 0x4]
	add r1, r10
	strb r0, [r1, 0x11]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80F7364
	mov r4, r9
	ldr r1, [r4]
	ldr r1, [r1, 0x4]
	add r1, r10
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _080F7A02
	negs r0, r0
_080F7A02:
	strb r0, [r1, 0x12]
	ldr r0, =gContestFinalStandings
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F7A60
	mov r5, r9
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	mov r2, r10
	adds r1, r2, r0
	ldr r5, [r1, 0x8]
	ldrh r3, [r1, 0x8]
	ldr r4, [r1, 0xC]
	ldrh r2, [r1, 0xC]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _080F7A2C
	lsls r0, r2, 16
	negs r0, r0
	lsrs r2, r0, 16
_080F7A2C:
	lsls r0, r3, 16
	asrs r3, r0, 16
	lsls r0, r2, 16
	asrs r2, r0, 16
	adds r0, r3, r2
	cmp r0, 0x58
	bne _080F7A60
	cmp r2, 0
	ble _080F7A58
	subs r0, r4, 0x1
	str r0, [r1, 0xC]
	b _080F7A60
	.pool
_080F7A58:
	cmp r3, 0
	ble _080F7A60
	subs r0, r5, 0x1
	str r0, [r1, 0x8]
_080F7A60:
	movs r4, 0x14
	add r10, r4
	movs r5, 0x1
	add r8, r5
	mov r0, r8
	cmp r0, 0x3
	bgt _080F7A70
	b _080F78EA
_080F7A70:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F7880

	thumb_func_start sub_80F7A80
sub_80F7A80: @ 80F7A80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	str r1, [sp, 0x8]
	movs r3, 0
	str r3, [sp, 0xC]
	cmp r0, 0
	bne _080F7B5C
	mov r9, r3
	ldr r4, =gUnknown_0203A034
	mov r10, r4
	movs r7, 0xA0
	lsls r7, 19
	movs r6, 0
_080F7AAC:
	mov r1, r10
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r2, [r0, 0x11]
	cmp r8, r2
	bcs _080F7B2E
	adds r2, 0x13
	mov r3, r8
	subs r2, r3
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	lsrs r3, r7, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r1, =0x000060b3
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =sub_80F7CA8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r10
	ldr r4, [r0]
	ldr r1, [r4, 0x4]
	adds r1, r6, r1
	ldr r0, [r1, 0x8]
	lsls r0, 16
	ldrb r1, [r1, 0x11]
	bl __udivsi3
	mov r1, r8
	adds r1, 0x1
	adds r3, r0, 0
	muls r3, r1
	ldr r0, =0x0000ffff
	ands r0, r3
	ldr r1, =0x00007fff
	cmp r0, r1
	bls _080F7B0A
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1
_080F7B0A:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	mov r1, r9
	strh r1, [r0, 0x8]
	lsrs r1, r3, 16
	strh r1, [r0, 0xA]
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
_080F7B2E:
	movs r3, 0xC0
	lsls r3, 18
	adds r7, r3
	adds r6, 0x14
	movs r4, 0x1
	add r9, r4
	mov r0, r9
	cmp r0, 0x3
	ble _080F7AAC
	b _080F7C7E
	.pool
_080F7B5C:
	movs r1, 0
	mov r9, r1
	mov r10, r1
	movs r3, 0xC0
	lsls r3, 19
	str r3, [sp, 0x10]
_080F7B68:
	ldr r4, =gUnknown_0203A034
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	add r0, r10
	ldrb r2, [r0, 0x12]
	ldrb r0, [r0, 0x10]
	ldr r1, =0x000060a3
	cmp r0, 0
	beq _080F7B7C
	adds r1, 0x2
_080F7B7C:
	lsls r0, r2, 24
	asrs r0, 24
	cmp r8, r0
	bge _080F7C64
	mov r3, r8
	lsls r2, r3, 24
	asrs r2, 24
	subs r2, 0x13
	subs r2, r0, r2
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r4, [sp, 0x10]
	lsrs r3, r4, 24
	movs r7, 0x1
	str r7, [sp]
	str r7, [sp, 0x4]
	movs r0, 0x1
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =sub_80F7CA8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A034
	ldr r6, [r0]
	ldr r1, [r6, 0x4]
	add r1, r10
	ldr r0, [r1, 0xC]
	lsls r0, 16
	ldrb r1, [r1, 0x12]
	bl __udivsi3
	mov r1, r8
	adds r1, 0x1
	adds r3, r0, 0
	muls r3, r1
	ldr r0, =0x0000ffff
	ands r0, r3
	ldr r1, =0x00007fff
	cmp r0, r1
	bls _080F7BDA
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1
_080F7BDA:
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r4, r0, r1
	mov r0, r9
	strh r0, [r4, 0x8]
	ldr r0, [r6, 0x4]
	add r0, r10
	ldrb r0, [r0, 0x10]
	adds r6, r1, 0
	cmp r0, 0
	beq _080F7C1C
	strh r7, [r4, 0xC]
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	b _080F7C26
	.pool
_080F7C1C:
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
_080F7C26:
	ldr r1, =gUnknown_0203A034
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	mov r4, r10
	adds r1, r4, r0
	ldrb r0, [r1, 0x10]
	ldr r4, =gUnknown_0203A034
	cmp r0, 0
	beq _080F7C4C
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r6
	lsrs r2, r3, 16
	ldr r1, [r1, 0x8]
	subs r1, r2
	b _080F7C58
	.pool
_080F7C4C:
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r6
	lsrs r2, r3, 16
	ldr r1, [r1, 0x8]
	adds r1, r2
_080F7C58:
	strh r1, [r0, 0xA]
	ldr r0, [r4]
	ldr r1, [r0]
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
_080F7C64:
	movs r0, 0x14
	add r10, r0
	ldr r1, [sp, 0x10]
	movs r3, 0xC0
	lsls r3, 18
	adds r1, r3
	str r1, [sp, 0x10]
	movs r4, 0x1
	add r9, r4
	mov r0, r9
	cmp r0, 0x3
	bgt _080F7C7E
	b _080F7B68
_080F7C7E:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _080F7C8A
	movs r0, 0x16
	bl PlaySE
_080F7C8A:
	ldr r3, [sp, 0x8]
	cmp r3, 0
	beq _080F7C96
	movs r0, 0x15
	bl PlaySE
_080F7C96:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F7A80

	thumb_func_start sub_80F7CA8
sub_80F7CA8: @ 80F7CA8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r4, 0
	mov r9, r4
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r6, [r0, 0x8]
	ldrh r7, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	mov r12, r1
	movs r2, 0xC
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _080F7CF8
	ldr r2, =gUnknown_0203A034
	ldr r0, [r2]
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0xC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r5, r1, 0
	cmp r0, 0
	bgt _080F7D10
	b _080F7D0E
	.pool
_080F7CF8:
	ldr r2, =gUnknown_0203A034
	ldr r0, [r2]
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0xC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r5, r1, 0
	cmp r0, 0x57
	ble _080F7D10
_080F7D0E:
	movs r4, 0x1
_080F7D10:
	ldr r0, [r2]
	ldr r0, [r0]
	adds r0, 0xC
	adds r2, r0, r5
	ldrh r3, [r2]
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r7, 16
	asrs r0, 16
	cmp r1, r0
	bne _080F7D2A
	movs r1, 0x1
	mov r9, r1
_080F7D2A:
	mov r0, r9
	cmp r0, 0
	bne _080F7D4A
	cmp r4, 0
	beq _080F7D3C
	strh r7, [r2]
	b _080F7D4A
	.pool
_080F7D3C:
	mov r1, r12
	cmp r1, 0
	beq _080F7D46
	subs r0, r3, 0x1
	b _080F7D48
_080F7D46:
	adds r0, r3, 0x1
_080F7D48:
	strh r0, [r2]
_080F7D4A:
	cmp r4, 0
	bne _080F7DC4
	mov r2, r9
	cmp r2, 0
	bne _080F7DCA
	movs r2, 0
_080F7D56:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0xC
	adds r0, r5
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r0, r2, 0x1
	lsls r1, r0, 3
	adds r4, r0, 0
	cmp r3, r1
	blt _080F7D78
	movs r0, 0x8
	b _080F7D94
	.pool
_080F7D78:
	lsls r0, r2, 3
	cmp r3, r0
	blt _080F7D92
	adds r0, r3, 0
	cmp r3, 0
	bge _080F7D86
	adds r0, r3, 0x7
_080F7D86:
	asrs r0, 3
	lsls r0, 3
	subs r0, r3, r0
	lsls r0, 24
	lsrs r0, 24
	b _080F7D94
_080F7D92:
	movs r0, 0
_080F7D94:
	cmp r0, 0x3
	bhi _080F7DA0
	ldr r3, =0x0000504c
	b _080F7DA2
	.pool
_080F7DA0:
	ldr r3, =0x00005057
_080F7DA2:
	adds r1, r0, r3
	adds r2, 0x7
	lsls r2, 24
	lsrs r2, 24
	adds r3, r5, r6
	adds r3, 0x6
	lsls r3, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x2
	lsrs r3, 24
	bl FillBgTilemapBufferRect_Palette0
	adds r2, r4, 0
	cmp r2, 0xA
	ble _080F7D56
_080F7DC4:
	mov r0, r9
	cmp r0, 0
	beq _080F7DDC
_080F7DCA:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	ldrb r0, [r1, 0x14]
	subs r0, 0x1
	strb r0, [r1, 0x14]
	mov r0, r8
	bl DestroyTask
_080F7DDC:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7CA8

	thumb_func_start sub_80F7DF4
sub_80F7DF4: @ 80F7DF4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203A034
	movs r0, 0x20
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x18
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x50
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r5, 0x80
	lsls r5, 4
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x8]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x10]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x14]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x18]
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x1C]
	bl AllocateMonSpritesGfx
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7DF4

	thumb_func_start sub_80F7E64
sub_80F7E64: @ 80F7E64
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A034
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
	bl Free
	str r4, [r5]
	bl FreeMonSpritesGfx
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7E64

	thumb_func_start sub_80F7ED0
sub_80F7ED0: @ 80F7ED0
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	str r1, [sp]
	mov r0, sp
	movs r3, 0
	strb r4, [r0, 0x4]
	mov r1, sp
	movs r0, 0x7
	strb r0, [r1, 0x5]
	mov r0, sp
	strb r2, [r0, 0x6]
	movs r1, 0x2
	strb r1, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r3, [r0, 0xA]
	strb r3, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x12
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0x10
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
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80F7ED0

	thumb_func_start sub_80F7F30
sub_80F7F30: @ 80F7F30
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl sub_80DAE0C
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	cmp r5, 0
	beq _080F7F5E
	ldr r4, =gSpecialVar_ContestCategory
	ldrb r0, [r4]
	ldr r1, =gSpecialVar_ContestRank
	ldrb r1, [r1]
	bl sub_80DAB8C
	ldrb r0, [r4]
	bl sub_80DB09C
_080F7F5E:
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7F30

	thumb_func_start sub_80F7F7C
sub_80F7F7C: @ 80F7F7C
	push {r4,lr}
	movs r4, 0
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r2, r1, r0
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080F7FEE
	lsls r0, 2
	ldr r1, =_080F7FB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F7FB0:
	.4byte _080F7FC4
	.4byte _080F7FCA
	.4byte _080F7FD0
	.4byte _080F7FD6
	.4byte _080F7FDC
_080F7FC4:
	adds r0, r2, 0
	movs r1, 0x32
	b _080F7FE0
_080F7FCA:
	adds r0, r2, 0
	movs r1, 0x33
	b _080F7FE0
_080F7FD0:
	adds r0, r2, 0
	movs r1, 0x34
	b _080F7FE0
_080F7FD6:
	adds r0, r2, 0
	movs r1, 0x35
	b _080F7FE0
_080F7FDC:
	adds r0, r2, 0
	movs r1, 0x36
_080F7FE0:
	bl GetMonData
	ldr r1, =gSpecialVar_ContestRank
	ldrh r1, [r1]
	cmp r0, r1
	bls _080F7FEE
	movs r4, 0x1
_080F7FEE:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F7F7C

	thumb_func_start sub_80F7FFC
sub_80F7FFC: @ 80F7FFC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F8010
	b _080F8250
_080F8010:
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bls _080F801A
	b _080F8250
_080F801A:
	lsls r0, 2
	ldr r1, =_080F8034
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F8034:
	.4byte _080F8048
	.4byte _080F80B8
	.4byte _080F8124
	.4byte _080F8190
	.4byte _080F81F8
_080F8048:
	ldr r6, =gUnknown_02039F24
	ldrb r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x32
	bl GetMonData
	lsls r0, 24
	lsrs r1, r0, 24
	mov r0, sp
	strb r1, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r1, r0
	bls _080F806C
	b _080F8250
_080F806C:
	adds r0, r1, 0
	cmp r0, 0x3
	bls _080F8074
	b _080F8250
_080F8074:
	adds r1, r0, 0x1
	mov r0, sp
	strb r1, [r0]
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x32
	mov r2, sp
	bl SetMonData
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080F809C
	b _080F8250
_080F809C:
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x32
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F80B8:
	mov r4, sp
	ldr r7, =gUnknown_02039F24
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x33
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bls _080F80DC
	b _080F8250
_080F80DC:
	cmp r2, 0x3
	bls _080F80E2
	b _080F8250
_080F80E2:
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x33
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080F810A
	b _080F8250
_080F810A:
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x33
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F8124:
	mov r4, sp
	ldr r7, =gUnknown_02039F24
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x34
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bls _080F8148
	b _080F8250
_080F8148:
	cmp r2, 0x3
	bls _080F814E
	b _080F8250
_080F814E:
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x34
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8250
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x34
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F8190:
	mov r4, sp
	ldr r7, =gUnknown_02039F24
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x35
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bhi _080F8250
	cmp r2, 0x3
	bhi _080F8250
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x35
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8250
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x35
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F81F8:
	mov r4, sp
	ldr r7, =gUnknown_02039F24
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x36
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bhi _080F8250
	cmp r2, 0x3
	bhi _080F8250
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x36
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8250
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x36
	bl sub_80EE4DC
_080F8250:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7FFC

	thumb_func_start sub_80F8264
sub_80F8264: @ 80F8264
	push {r4,lr}
	ldr r4, =gStringVar1
	ldr r0, =gSpecialVar_0x8006
	ldrh r1, [r0]
	lsls r1, 6
	ldr r0, =gContestMons + 13
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	bl sub_81DB5AC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8264

	thumb_func_start sub_80F8290
sub_80F8290: @ 80F8290
	push {lr}
	ldr r0, =gStringVar3
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	lsls r1, 6
	ldr r2, =gContestMons + 2
	adds r1, r2
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8290

	thumb_func_start sub_80F82B4
sub_80F82B4: @ 80F82B4
	push {r4-r6,lr}
	movs r1, 0
	movs r2, 0
	ldr r5, =gSpecialVar_0x8004
	ldr r4, =gContestMonConditions
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r4
	movs r6, 0
	ldrsh r3, [r0, r6]
_080F82CA:
	lsls r0, r1, 1
	adds r0, r4
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r3, r0
	bge _080F82DC
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080F82DC:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _080F82CA
	strh r2, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F82B4

	thumb_func_start sub_80F82FC
sub_80F82FC: @ 80F82FC
	ldr r2, =gSpecialVar_0x8004
	ldr r1, =gContestMonConditions
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80F82FC

	thumb_func_start sub_80F831C
sub_80F831C: @ 80F831C
	push {lr}
	movs r1, 0
	ldr r2, =gContestFinalStandings
	ldrb r0, [r2]
	ldr r3, =gSpecialVar_0x8005
	cmp r0, 0
	beq _080F833C
_080F832A:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _080F833C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F832A
_080F833C:
	strh r1, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F831C

	thumb_func_start sub_80F834C
sub_80F834C: @ 80F834C
	push {r4,lr}
	movs r1, 0
	ldr r2, =gContestFinalStandings
	ldrb r0, [r2]
	ldr r4, =gStringVar3
	ldr r3, =gContestMons + 13
	cmp r0, 0
	beq _080F836E
_080F835C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _080F836E
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F835C
_080F836E:
	lsls r1, 6
	adds r1, r3
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	bl sub_81DB5AC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F834C

	thumb_func_start sub_80F8390
sub_80F8390: @ 80F8390
	push {r4,lr}
	movs r1, 0
	ldr r2, =gContestFinalStandings
	ldrb r0, [r2]
	ldr r4, =gStringVar1
	ldr r3, =gContestMons + 2
	cmp r0, 0
	beq _080F83B2
_080F83A0:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _080F83B2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F83A0
_080F83B2:
	lsls r1, 6
	adds r1, r3
	adds r0, r4, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8390

	thumb_func_start sub_80F83D0
sub_80F83D0: @ 80F83D0
	push {lr}
	ldr r0, =sub_80D7B24
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F83D0

	thumb_func_start sub_80F83E0
sub_80F83E0: @ 80F83E0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080F83FE
	adds r0, r2, 0
	bl DestroyTask
	ldr r0, =sub_80F83D0
	bl SetMainCallback2
_080F83FE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F83E0

	thumb_func_start sub_80F840C
sub_80F840C: @ 80F840C
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_80F83E0
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F840C

	thumb_func_start sub_80F8438
sub_80F8438: @ 80F8438
	ldr r2, =gSpecialVar_0x8004
	ldr r1, =gContestMons
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 6
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80F8438

	thumb_func_start sub_80F8458
sub_80F8458: @ 80F8458
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080F8476
	adds r0, r2, 0
	bl DestroyTask
	ldr r0, =sub_80F5B00
	bl SetMainCallback2
_080F8476:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8458

	thumb_func_start sub_80F8484
sub_80F8484: @ 80F8484
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_80F8458
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8484

	thumb_func_start sub_80F84B0
sub_80F84B0: @ 80F84B0
	ldr r0, =gSpecialVar_0x8004
	ldr r1, =gContestPlayerMonIndex
	ldrb r1, [r1]
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80F84B0

	thumb_func_start sub_80F84C4
sub_80F84C4: @ 80F84C4
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	bl ScriptContext2_Enable
	ldr r6, =sub_80FC580
	adds r0, r6, 0
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r2, =sub_80F8508
	adds r0, r4, 0
	adds r1, r6, 0
	bl SetTaskFuncWithFollowupFunc
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x1A]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F84C4

	thumb_func_start sub_80F8508
sub_80F8508: @ 80F8508
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080F8540
	ldr r0, =gUnknown_02039F24
	ldrb r0, [r0]
	bl sub_80DA8C8
	ldr r1, =sub_80FC6BC
	ldr r2, =sub_80F8568
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	b _080F8556
	.pool
_080F8540:
	ldr r0, =gUnknown_02039F24
	ldrb r0, [r0]
	bl sub_80DA8C8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D9DE4
	str r1, [r0]
_080F8556:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8508

	thumb_func_start sub_80F8568
sub_80F8568: @ 80F8568
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FC804
	ldr r2, =sub_80F8584
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8568

	thumb_func_start sub_80F8584
sub_80F8584: @ 80F8584
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FCE48
	ldr r2, =sub_80F85A0
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8584

	thumb_func_start sub_80F85A0
sub_80F85A0: @ 80F85A0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FC894
	ldr r2, =sub_80F85BC
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F85A0

	thumb_func_start sub_80F85BC
sub_80F85BC: @ 80F85BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r3, 0
	ldr r5, =gUnknown_02039F30
	mov r12, r5
	ldr r0, =gSpecialVar_0x8004
	mov r9, r0
	add r1, sp, 0x4
	mov r8, r1
	ldrb r0, [r5]
	cmp r3, r0
	bcs _080F8606
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 3
	ldr r7, =gTasks + 0x8
_080F85EC:
	mov r1, sp
	adds r2, r1, r3
	adds r1, r3, 0x1
	lsls r0, r1, 1
	adds r0, r4
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r3, r1, 24
	ldrb r0, [r5]
	cmp r3, r0
	bcc _080F85EC
_080F8606:
	movs r3, 0
	mov r1, r12
	ldrb r0, [r1]
	cmp r3, r0
	bcs _080F862A
	adds r4, r0, 0
	mov r2, sp
_080F8614:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcs _080F862A
	mov r0, sp
	adds r1, r0, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080F8614
_080F862A:
	mov r1, r12
	ldrb r1, [r1]
	cmp r3, r1
	bne _080F8644
	movs r0, 0
	b _080F8646
	.pool
_080F8644:
	movs r0, 0x1
_080F8646:
	mov r1, r9
	strh r0, [r1]
	movs r3, 0
	mov r4, r12
	ldrb r0, [r4]
	cmp r3, r0
	bcs _080F8678
	mov r5, r8
	lsls r0, r6, 2
	adds r0, r6
	lsls r2, r0, 3
	ldr r7, =gTasks + 0x8
_080F865E:
	adds r1, r5, r3
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r2
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r4]
	cmp r3, r1
	bcc _080F865E
_080F8678:
	mov r0, r8
	bl sub_80F86E0
	ldr r1, =gUnknown_02039F2B
	strb r0, [r1]
	ldr r0, =gSpecialVar_ContestCategory
	ldrb r0, [r0]
	bl sub_80DB09C
	ldr r1, =sub_80FCF40
	ldr r2, =sub_80F86B8
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F85BC

	thumb_func_start sub_80F86B8
sub_80F86B8: @ 80F86B8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_80DCE58
	ldr r1, =sub_80FCFD0
	ldr r2, =sub_80F8714
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F86B8

	thumb_func_start sub_80F86E0
sub_80F86E0: @ 80F86E0
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	movs r2, 0x1
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r2, r0
	bge _080F8708
	adds r5, r0, 0
_080F86F2:
	adds r0, r3, r4
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080F8702
	lsls r0, r2, 24
	lsrs r4, r0, 24
_080F8702:
	adds r2, 0x1
	cmp r2, r5
	blt _080F86F2
_080F8708:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F86E0

	thumb_func_start sub_80F8714
sub_80F8714: @ 80F8714
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _080F8748
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080F877E
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80F878C
	str r0, [r1]
	b _080F877E
	.pool
_080F8748:
	ldr r5, =gContestMons + 2
	movs r4, 0x3
_080F874C:
	adds r0, r5, 0
	bl StringGetEnd10
	adds r5, 0x40
	subs r4, 0x1
	cmp r4, 0
	bge _080F874C
	adds r0, r6, 0
	bl DestroyTask
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl saved_warp2_set
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
_080F877E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8714

	thumb_func_start sub_80F878C
sub_80F878C: @ 80F878C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_800AC34
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80F87B4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F878C

	thumb_func_start sub_80F87B4
sub_80F87B4: @ 80F87B4
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F87D0
	adds r0, r1, 0
	bl DestroyTask
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
_080F87D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F87B4

	.align 2, 0 @ Don't pad with nop.
