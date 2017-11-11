	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start SetLinkDebugValues
SetLinkDebugValues: @ 800A994
	ldr r2, =gUnknown_0300302C
	str r0, [r2]
	ldr r0, =gUnknown_03003070
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end SetLinkDebugValues

	thumb_func_start sub_800A9A8
sub_800A9A8: @ 800A9A8
	push {r4,lr}
	movs r1, 0
	movs r2, 0
	ldr r0, =gUnknown_03003100
	ldrb r0, [r0]
	cmp r1, r0
	bge _0800A9CA
	movs r4, 0x1
	adds r3, r0, 0
_0800A9BA:
	adds r0, r4, 0
	lsls r0, r2
	orrs r1, r0
	lsls r0, r1, 24
	lsrs r1, r0, 24
	adds r2, 0x1
	cmp r2, r3
	blt _0800A9BA
_0800A9CA:
	adds r0, r1, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800A9A8

	thumb_func_start sub_800A9D8
sub_800A9D8: @ 800A9D8
	push {r4-r6,lr}
	movs r4, 0
	movs r5, 0
	movs r6, 0x1
	b _0800A9EE
_0800A9E2:
	adds r0, r6, 0
	lsls r0, r5
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
	adds r5, 0x1
_0800A9EE:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	blt _0800A9E2
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800A9D8

	thumb_func_start sub_800AA04
sub_800AA04: @ 800AA04
	push {r4-r7,lr}
	ldr r1, =gUnknown_03003100
	strb r0, [r1]
	bl GetMultiplayerId
	ldr r1, =gUnknown_03003120
	strb r0, [r1]
	ldr r4, =gLinkPlayers
	ldr r3, =gUnknown_02022A74
	movs r2, 0x4
_0800AA18:
	adds r0, r3, 0
	adds r1, r4, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldr r1, [r1]
	str r1, [r0]
	adds r4, 0x1C
	adds r3, 0x1C
	subs r2, 0x1
	cmp r2, 0
	bge _0800AA18
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AA04

	thumb_func_start sub_800AA48
sub_800AA48: @ 800AA48
	ldr r0, =gUnknown_03003100
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800AA48

	thumb_func_start sub_800AA54
sub_800AA54: @ 800AA54
	ldr r0, =gUnknown_03003120
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800AA54

	thumb_func_start sub_800AA60
sub_800AA60: @ 800AA60
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r3, 0
	ldr r0, =gUnknown_03003100
	ldrb r1, [r0]
	mov r9, r0
	cmp r3, r1
	bge _0800AAB4
	ldr r0, =gLinkPlayers
	mov r12, r0
	ldr r0, =gUnknown_02022A74
	ldr r2, =0x00002288
	mov r8, r2
	ldr r7, =gLinkType
	mov r6, r12
	adds r6, 0x14
	adds r5, r0, 0x4
	movs r4, 0
	adds r2, r1, 0
_0800AA8A:
	mov r0, r12
	adds r0, 0x4
	adds r0, r4, r0
	ldr r1, [r0]
	ldr r0, [r5]
	cmp r1, r0
	bne _0800AAA8
	ldrh r0, [r7]
	cmp r0, r8
	bne _0800AAA6
	adds r1, r0, 0
	ldr r0, [r6]
	cmp r1, r0
	bne _0800AAA8
_0800AAA6:
	adds r3, 0x1
_0800AAA8:
	adds r6, 0x1C
	adds r5, 0x1C
	adds r4, 0x1C
	subs r2, 0x1
	cmp r2, 0
	bne _0800AA8A
_0800AAB4:
	mov r0, r9
	ldrb r0, [r0]
	cmp r3, r0
	bne _0800AAE4
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r9
	ldrb r1, [r1]
	cmp r0, r1
	bne _0800AAE4
	movs r0, 0x1
	b _0800AAE6
	.pool
_0800AAE4:
	movs r0, 0
_0800AAE6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800AA60

	thumb_func_start sub_800AAF4
sub_800AAF4: @ 800AAF4
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022A74
	movs r4, 0x3
_0800AAFA:
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x1C
	bl CpuSet
	adds r5, 0x1C
	subs r4, 0x1
	cmp r4, 0
	bge _0800AAFA
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AAF4

	thumb_func_start sub_800AB18
sub_800AB18: @ 800AB18
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r4, 0
	ldr r0, =gUnknown_03003100
	ldrb r0, [r0]
	cmp r4, r0
	bcs _0800AB78
	ldr r6, =gUnknown_02022A74
	ldr r5, =gLinkPlayers
	movs r0, 0x8
	adds r0, r6
	mov r8, r0
	adds r7, r5, 0
	adds r7, 0x8
_0800AB36:
	lsls r0, r4, 3
	subs r0, r4
	lsls r2, r0, 2
	adds r1, r6, 0x4
	adds r1, r2, r1
	adds r0, r5, 0x4
	adds r0, r2, r0
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	bne _0800AB5A
	mov r1, r8
	adds r0, r2, r1
	adds r1, r2, r7
	bl StringCompare
	cmp r0, 0
	beq _0800AB6A
_0800AB5A:
	ldr r1, =gLinkErrorOccurred
	movs r0, 0x1
	strb r0, [r1]
	bl CloseLink
	ldr r0, =CB2_LinkError
	bl SetMainCallback2
_0800AB6A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_03003100
	ldrb r0, [r0]
	cmp r4, r0
	bcc _0800AB36
_0800AB78:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AB18

	thumb_func_start sub_800AB98
sub_800AB98: @ 800AB98
	ldr r0, =gUnknown_03003100
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_03003120
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_800AB98

	thumb_func_start sub_800ABAC
sub_800ABAC: @ 800ABAC
	ldr r0, =gLinkStatus
	ldr r0, [r0]
	movs r1, 0x1C
	ands r0, r1
	lsrs r0, 2
	bx lr
	.pool
	thumb_func_end sub_800ABAC

	thumb_func_start sub_800ABBC
sub_800ABBC: @ 800ABBC
	push {lr}
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800ABDC
	ldr r0, =gLinkStatus
	ldr r0, [r0]
	lsrs r0, 5
	movs r1, 0x1
	ands r0, r1
	b _0800ABE4
	.pool
_0800ABDC:
	bl sub_8011AB0
	lsls r0, 24
	lsrs r0, 24
_0800ABE4:
	pop {r1}
	bx r1
	thumb_func_end sub_800ABBC

	thumb_func_start sub_800ABE8
sub_800ABE8: @ 800ABE8
	ldr r0, =gUnknown_03000D58
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800ABE8

	thumb_func_start sub_800ABF4
sub_800ABF4: @ 800ABF4
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800AC0C
	bl task_add_05_task_del_08FA224_when_no_RfuFunc
	b _0800AC20
	.pool
_0800AC0C:
	ldr r2, =gLinkCallback
	ldr r1, [r2]
	cmp r1, 0
	bne _0800AC20
	ldr r0, =sub_800AC80
	str r0, [r2]
	ldr r0, =gUnknown_030030E4
	strb r1, [r0]
	ldr r0, =gUnknown_030030F4
	strh r3, [r0]
_0800AC20:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800ABF4

	thumb_func_start sub_800AC34
sub_800AC34: @ 800AC34
	push {lr}
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800AC48
	bl task_add_05_task_del_08FA224_when_no_RfuFunc
	b _0800AC70
	.pool
_0800AC48:
	ldr r2, =gLinkCallback
	ldr r1, [r2]
	cmp r1, 0
	beq _0800AC64
	ldr r1, =gUnknown_02022B08
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0800AC70
	.pool
_0800AC64:
	ldr r0, =sub_800AC80
	str r0, [r2]
	ldr r0, =gUnknown_030030E4
	strb r1, [r0]
	ldr r0, =gUnknown_030030F4
	strh r1, [r0]
_0800AC70:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AC34

	thumb_func_start sub_800AC80
sub_800AC80: @ 800AC80
	push {lr}
	ldr r0, =gUnknown_03004130
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800AC96
	ldr r0, =0x00005fff
	bl BuildSendCmd
	ldr r1, =gLinkCallback
	ldr r0, =sub_800ACAC
	str r0, [r1]
_0800AC96:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AC80

	thumb_func_start sub_800ACAC
sub_800ACAC: @ 800ACAC
	push {r4,lr}
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0
	movs r1, 0
	cmp r3, r2
	bge _0800ACD0
	ldr r4, =gUnknown_030030F0
_0800ACC0:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800ACCA
	adds r3, 0x1
_0800ACCA:
	adds r1, 0x1
	cmp r1, r2
	blt _0800ACC0
_0800ACD0:
	cmp r3, r2
	bne _0800ACF4
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	ldr r0, =gLinkVSyncDisabled
	movs r4, 0x1
	strb r4, [r0]
	bl CloseLink
	ldr r1, =gLinkCallback
	movs r0, 0
	str r0, [r1]
	ldr r0, =gUnknown_030030E4
	strb r4, [r0]
_0800ACF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800ACAC

	thumb_func_start sub_800AD10
sub_800AD10: @ 800AD10
	push {lr}
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800AD24
	bl task_add_05_task_del_08FA224_when_no_RfuFunc
	b _0800AD4C
	.pool
_0800AD24:
	ldr r2, =gLinkCallback
	ldr r1, [r2]
	cmp r1, 0
	beq _0800AD40
	ldr r1, =gUnknown_02022B08
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0800AD4C
	.pool
_0800AD40:
	ldr r0, =sub_800AD5C
	str r0, [r2]
	ldr r0, =gUnknown_030030E4
	strb r1, [r0]
	ldr r0, =gUnknown_030030F4
	strh r1, [r0]
_0800AD4C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AD10

	thumb_func_start sub_800AD5C
sub_800AD5C: @ 800AD5C
	push {lr}
	ldr r0, =gUnknown_03004130
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800AD72
	ldr r0, =0x00005fff
	bl BuildSendCmd
	ldr r1, =gLinkCallback
	ldr r0, =sub_800AD88
	str r0, [r1]
_0800AD72:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AD5C

	thumb_func_start sub_800AD88
sub_800AD88: @ 800AD88
	push {r4,r5,lr}
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r3, r0, 24
	movs r1, 0
	movs r2, 0
	cmp r1, r3
	bge _0800ADB6
	ldr r5, =gUnknown_030030F0
	ldr r4, =gLinkPlayers
_0800AD9E:
	ldrh r0, [r4, 0x1A]
	cmp r0, 0x1
	beq _0800ADAC
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800ADAE
_0800ADAC:
	adds r1, 0x1
_0800ADAE:
	adds r4, 0x1C
	adds r2, 0x1
	cmp r2, r3
	blt _0800AD9E
_0800ADB6:
	cmp r1, r3
	bne _0800ADDA
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	ldr r0, =gLinkVSyncDisabled
	movs r4, 0x1
	strb r4, [r0]
	bl CloseLink
	ldr r1, =gLinkCallback
	movs r0, 0
	str r0, [r1]
	ldr r0, =gUnknown_030030E4
	strb r4, [r0]
_0800ADDA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AD88

	thumb_func_start sub_800ADF8
sub_800ADF8: @ 800ADF8
	push {lr}
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800AE0C
	bl sub_8010434
	b _0800AE1E
	.pool
_0800AE0C:
	ldr r1, =gLinkCallback
	ldr r0, [r1]
	cmp r0, 0
	bne _0800AE18
	ldr r0, =sub_800AE30
	str r0, [r1]
_0800AE18:
	ldr r1, =gUnknown_030030E4
	movs r0, 0
	strb r0, [r1]
_0800AE1E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800ADF8

	thumb_func_start sub_800AE30
sub_800AE30: @ 800AE30
	push {lr}
	ldr r0, =gUnknown_03004130
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800AE46
	ldr r0, =0x00002ffe
	bl BuildSendCmd
	ldr r1, =gLinkCallback
	ldr r0, =sub_800AE5C
	str r0, [r1]
_0800AE46:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AE30

	thumb_func_start sub_800AE5C
sub_800AE5C: @ 800AE5C
	push {r4,lr}
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	cmp r1, r2
	bcs _0800AE86
	ldr r3, =gUnknown_030030EC
	ldrb r0, [r3]
	cmp r0, 0
	beq _0800AE86
_0800AE74:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r2
	bcs _0800AE86
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800AE74
_0800AE86:
	cmp r1, r2
	bne _0800AEA4
	movs r1, 0
	ldr r4, =gLinkCallback
	ldr r3, =gUnknown_030030EC
	movs r2, 0
_0800AE92:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _0800AE92
	movs r0, 0
	str r0, [r4]
_0800AEA4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AE5C

	thumb_func_start sub_800AEB4
sub_800AEB4: @ 800AEB4
	push {lr}
	ldr r0, =gLinkOpen
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800AEF4
	ldr r0, =gLinkStatus
	ldr r2, [r0]
	movs r0, 0xFE
	lsls r0, 11
	ands r0, r2
	cmp r0, 0
	beq _0800AEF4
	ldr r0, =gSuppressLinkErrorMessage
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800AEEA
	ldr r1, =gUnknown_02022B00
	str r2, [r1]
	ldr r0, =gUnknown_03004130
	ldrb r0, [r0]
	strb r0, [r1, 0x4]
	ldr r0, =gUnknown_03003160
	ldrb r0, [r0]
	strb r0, [r1, 0x5]
	ldr r0, =CB2_LinkError
	bl SetMainCallback2
_0800AEEA:
	ldr r1, =gLinkErrorOccurred
	movs r0, 0x1
	strb r0, [r1]
	bl CloseLink
_0800AEF4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AEB4

	thumb_func_start sub_800AF18
sub_800AF18: @ 800AF18
	push {r4,lr}
	ldr r4, =gUnknown_02022B00
	str r0, [r4]
	strb r1, [r4, 0x5]
	strb r2, [r4, 0x4]
	strb r3, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800AF18

	thumb_func_start CB2_LinkError
CB2_LinkError: @ 800AF30
	push {r4,lr}
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE3
	bl m4aMPlayStop
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetPaletteFadeControl
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	bl ResetTasks
	bl remove_some_task
	ldr r1, =gSerialIsRFU
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800AF8C
	ldr r0, =gUnknown_02022B00
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0800AF88
	movs r0, 0x3
	strb r0, [r1]
_0800AF88:
	bl sub_800E604
_0800AF8C:
	ldr r0, =sub_80096BC
	bl SetVBlankCallback
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082ED1FC
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_02022B0C
	movs r0, 0x80
	lsls r0, 4
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_082ED204
	bl InitWindows
	lsls r0, 16
	cmp r0, 0
	beq _0800B03C
	bl DeactivateAllTextPrinters
	bl reset_temp_tile_data_buffers
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
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
	movs r1, 0xE0
	lsls r1, 8
	movs r0, 0
	bl ClearGpuRegBits
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gSoftResetDisabled
	movs r0, 0
	strb r0, [r1]
	ldr r0, =Task_DestroySelf
	movs r1, 0
	bl CreateTask
	bl StopMapMusic
	ldr r1, =gMain
	movs r0, 0
	str r0, [r1]
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	ldr r0, =sub_800B1A0
	bl SetMainCallback2
_0800B03C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_LinkError

	thumb_func_start sub_800B080
sub_800B080: @ 800B080
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =g2BlankTilesGfx
	movs r0, 0
	movs r2, 0x20
	movs r3, 0
	bl LoadBgTiles
	ldr r1, =gWirelessLinkDisplayGfx
	movs r5, 0
	str r5, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gWirelessLinkDisplayTilemap
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =gWirelessLinkDisplayPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_082ED224
	str r4, [sp]
	str r5, [sp, 0x4]
	ldr r0, =gText_CommErrorEllipsis
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0x6
	bl box_print
	str r4, [sp]
	str r5, [sp, 0x4]
	ldr r0, =gText_MoveCloserToLinkPartner
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0x1
	bl box_print
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	bl CopyWindowToVram
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B080

	thumb_func_start sub_800B138
sub_800B138: @ 800B138
	push {lr}
	sub sp, 0xC
	ldr r1, =g2BlankTilesGfx
	movs r0, 0
	movs r2, 0x20
	movs r3, 0
	bl LoadBgTiles
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_082ED224
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r0, =gText_CommErrorCheckConnections
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0
	bl box_print
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0
	bl CopyWindowToVram
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B138

	thumb_func_start sub_800B1A0
sub_800B1A0: @ 800B1A0
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1E
	beq _0800B20C
	cmp r0, 0x1E
	bgt _0800B1C4
	cmp r0, 0
	beq _0800B1D8
	cmp r0, 0x2
	beq _0800B1F2
	b _0800B260
	.pool
_0800B1C4:
	cmp r0, 0x5A
	beq _0800B20C
	cmp r0, 0x5A
	bgt _0800B1D2
	cmp r0, 0x3C
	beq _0800B20C
	b _0800B260
_0800B1D2:
	cmp r0, 0x82
	beq _0800B214
	b _0800B260
_0800B1D8:
	ldr r0, =gUnknown_02022B00
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0800B1EC
	bl sub_800B080
	b _0800B260
	.pool
_0800B1EC:
	bl sub_800B138
	b _0800B260
_0800B1F2:
	movs r0, 0
	bl ShowBg
	ldr r0, =gUnknown_02022B00
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0800B260
	movs r0, 0x1
	bl ShowBg
	b _0800B260
	.pool
_0800B20C:
	movs r0, 0x16
	bl PlaySE
	b _0800B260
_0800B214:
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0800B244
	ldr r0, =gUnknown_082ED224
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r0, =gText_ABtnTitleScreen
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0x14
	bl box_print
	b _0800B260
	.pool
_0800B244:
	cmp r0, 0x1
	bne _0800B260
	ldr r0, =gUnknown_082ED224
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r0, =gText_ABtnRegistrationCounter
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0x14
	bl box_print
_0800B260:
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, 0xA0
	bne _0800B2D0
	ldr r4, =gSerialIsRFU
	ldrb r2, [r4]
	cmp r2, 0x1
	bne _0800B2A8
	ldrh r0, [r0, 0x2E]
	ands r2, r0
	cmp r2, 0
	beq _0800B2C2
	movs r0, 0x15
	bl PlaySE
	movs r0, 0
	strb r0, [r4]
	ldr r1, =gUnknown_02022B00
	movs r0, 0
	strb r0, [r1, 0x6]
	bl sub_81700F8
	b _0800B2C2
	.pool
_0800B2A8:
	cmp r2, 0x2
	bne _0800B2C2
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800B2C2
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	bl DoSoftReset
_0800B2C2:
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, 0xA0
	beq _0800B2DC
_0800B2D0:
	movs r2, 0x87
	lsls r2, 3
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0800B2DC:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B1A0

	thumb_func_start sub_800B2E8
sub_800B2E8: @ 800B2E8
	ldr r0, =0x04000128
	ldrh r0, [r0]
	lsrs r0, 2
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_800B2E8

	thumb_func_start sub_800B2F8
sub_800B2F8: @ 800B2F8
	push {lr}
	movs r3, 0
	ldr r2, =0x04000128
	ldrh r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0800B314
	ldrh r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0800B314
	movs r3, 0x1
_0800B314:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800B2F8

	thumb_func_start sub_800B320
sub_800B320: @ 800B320
	ldr r0, =gLinkStatus
	ldr r0, [r0]
	lsrs r0, 6
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_800B320

	thumb_func_start SetSuppressLinkErrorMessage
SetSuppressLinkErrorMessage: @ 800B330
	ldr r1, =gSuppressLinkErrorMessage
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end SetSuppressLinkErrorMessage

	thumb_func_start sub_800B33C
sub_800B33C: @ 800B33C
	ldr r0, =gLinkErrorOccurred
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800B33C

	thumb_func_start sub_800B348
sub_800B348: @ 800B348
	push {r4-r6,lr}
	bl InitLocalLinkPlayer
	ldr r1, =gLocalLinkPlayerBlock
	adds r2, r1, 0
	adds r2, 0x10
	ldr r0, =gLocalLinkPlayer
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r2]
	ldr r3, =gASCIIGameFreakInc
	adds r2, r1, 0
	adds r0, r3, 0
	ldm r0!, {r4-r6}
	stm r2!, {r4-r6}
	ldrh r4, [r0]
	strh r4, [r2]
	ldrb r0, [r0, 0x2]
	strb r0, [r2, 0x2]
	adds r0, r1, 0
	adds r0, 0x2C
	ldm r3!, {r2,r5,r6}
	stm r0!, {r2,r5,r6}
	ldrh r2, [r3]
	strh r2, [r0]
	ldrb r2, [r3, 0x2]
	strb r2, [r0, 0x2]
	ldr r0, =gBlockSendBuffer
	movs r2, 0x3C
	bl memcpy
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B348

	thumb_func_start sub_800B3A4
sub_800B3A4: @ 800B3A4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 8
	ldr r1, =gBlockRecvBuffer
	adds r4, r2, r1
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	ldr r0, =gLinkPlayers
	adds r2, r0
	adds r1, r2, 0
	adds r0, r4, 0
	adds r0, 0x10
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r2, 0
	bl sub_800B524
	ldr r5, =gASCIIGameFreakInc
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	bne _0800B3EE
	adds r0, r4, 0
	adds r0, 0x2C
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _0800B3F4
_0800B3EE:
	ldr r0, =CB2_LinkError
	bl SetMainCallback2
_0800B3F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B3A4

	thumb_func_start HandleLinkConnection
HandleLinkConnection: @ 800B40C
	push {r4,r5,lr}
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800B45C
	ldr r0, =gShouldAdvanceLinkState
	ldr r1, =gSendCmd
	ldr r2, =gRecvCmds
	bl sub_800B638
	ldr r4, =gLinkStatus
	str r0, [r4]
	ldr r0, =gMain+0x2c
	bl LinkMain2
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _0800B480
	bl sub_808766C
	cmp r0, 0x1
	bne _0800B480
_0800B43E:
	movs r0, 0x1
	b _0800B482
	.pool
_0800B45C:
	bl sub_8010EC0
	adds r4, r0, 0
	bl sub_8010F1C
	adds r5, r0, 0
	bl sub_808766C
	cmp r0, 0x1
	bne _0800B480
	cmp r4, 0x1
	beq _0800B43E
	bl sub_800F0B8
	cmp r0, 0
	bne _0800B43E
	cmp r5, 0
	bne _0800B43E
_0800B480:
	movs r0, 0
_0800B482:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end HandleLinkConnection

	thumb_func_start sub_800B488
sub_800B488: @ 800B488
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800B498
	ldr r1, =gSerialIsRFU
	movs r0, 0x1
	strb r0, [r1]
_0800B498:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B488

	thumb_func_start sub_800B4A4
sub_800B4A4: @ 800B4A4
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r1, [r0]
	cmp r1, 0
	bne _0800B4B2
	ldr r0, =gSerialIsRFU
	strb r1, [r0]
_0800B4B2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B4A4

	thumb_func_start sub_800B4C0
sub_800B4C0: @ 800B4C0
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r1, [r0]
	cmp r1, 0
	bne _0800B4CE
	ldr r0, =gSerialIsRFU
	strb r1, [r0]
_0800B4CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B4C0

	thumb_func_start sub_800B4DC
sub_800B4DC: @ 800B4DC
	push {lr}
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800B4FC
	ldr r0, =gLink
	ldr r1, =0x00000fbd
	adds r0, r1
	ldrb r0, [r0]
	b _0800B500
	.pool
_0800B4FC:
	bl sub_80124D4
_0800B500:
	pop {r1}
	bx r1
	thumb_func_end sub_800B4DC

	thumb_func_start sub_800B504
sub_800B504: @ 800B504
	push {lr}
	bl sub_800B4DC
	cmp r0, 0x2
	bhi _0800B512
	movs r0, 0
	b _0800B514
_0800B512:
	movs r0, 0x1
_0800B514:
	pop {r1}
	bx r1
	thumb_func_end sub_800B504

	thumb_func_start sub_800B518
sub_800B518: @ 800B518
	ldr r0, =gSerialIsRFU
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800B518

	thumb_func_start sub_800B524
sub_800B524: @ 800B524
	push {lr}
	ldrb r1, [r0, 0x10]
	strb r1, [r0, 0x12]
	adds r2, r0, 0
	adds r2, 0x8
	ldrb r1, [r0, 0x1A]
	adds r0, r2, 0
	bl ConvertInternationalString
	pop {r0}
	bx r0
	thumb_func_end sub_800B524

	thumb_func_start DisableSerial
DisableSerial: @ 800B53C
	push {lr}
	sub sp, 0x4
	movs r0, 0xC0
	bl DisableInterrupts
	ldr r1, =0x04000128
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x0400010e
	movs r2, 0
	strh r2, [r0]
	adds r1, 0xDA
	movs r0, 0xC0
	strh r0, [r1]
	ldr r0, =0x0400012a
	strh r2, [r0]
	ldr r2, =0x04000120
	movs r0, 0
	movs r1, 0
	str r0, [r2]
	str r1, [r2, 0x4]
	str r0, [sp]
	ldr r1, =gLink
	ldr r2, =0x050003f0
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisableSerial

	thumb_func_start EnableSerial
EnableSerial: @ 800B594
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0xC0
	bl DisableInterrupts
	ldr r0, =0x04000134
	movs r4, 0
	strh r4, [r0]
	ldr r2, =0x04000128
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, =0x00004003
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x80
	bl EnableInterrupts
	ldr r0, =0x0400012a
	strh r4, [r0]
	movs r5, 0
	str r5, [sp]
	ldr r1, =gLink
	ldr r2, =0x050003f0
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_03000D6C
	strb r4, [r0]
	ldr r0, =gUnknown_03000D6E
	strh r5, [r0]
	ldr r0, =gUnknown_03000D70
	strh r5, [r0]
	ldr r0, =gUnknown_03000D72
	strb r4, [r0]
	ldr r0, =gUnknown_03000D73
	strb r4, [r0]
	ldr r0, =gUnknown_03003160
	strb r4, [r0]
	ldr r0, =gUnknown_03004130
	strb r4, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EnableSerial

	thumb_func_start ResetSerial
ResetSerial: @ 800B628
	push {lr}
	bl EnableSerial
	bl DisableSerial
	pop {r0}
	bx r0
	thumb_func_end ResetSerial

	thumb_func_start sub_800B638
sub_800B638: @ 800B638
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, =gLink
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bhi _0800B6EA
	lsls r0, 2
	ldr r1, =_0800B65C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800B65C:
	.4byte _0800B670
	.4byte _0800B680
	.4byte _0800B698
	.4byte _0800B6D4
	.4byte _0800B6DE
_0800B670:
	bl DisableSerial
	ldr r1, =gLink
	movs r0, 0x1
	strb r0, [r1, 0x1]
	b _0800B6EA
	.pool
_0800B680:
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _0800B6EA
	bl EnableSerial
	ldr r1, =gLink
	movs r0, 0x2
	strb r0, [r1, 0x1]
	b _0800B6EA
	.pool
_0800B698:
	ldrb r1, [r4]
	cmp r1, 0x1
	beq _0800B6A8
	cmp r1, 0x2
	beq _0800B6C0
	bl sub_800B764
	b _0800B6EA
_0800B6A8:
	ldr r2, =gLink
	ldrb r0, [r2]
	cmp r0, 0x8
	bne _0800B6EA
	ldrb r0, [r2, 0x3]
	cmp r0, 0x1
	bls _0800B6EA
	strb r1, [r2, 0xE]
	b _0800B6EA
	.pool
_0800B6C0:
	ldr r0, =gLink
	movs r1, 0
	strb r1, [r0, 0x1]
	ldr r0, =0x0400012a
	strh r1, [r0]
	b _0800B6EA
	.pool
_0800B6D4:
	bl sub_800B790
	ldr r1, =gLink
	movs r0, 0x4
	strb r0, [r1, 0x1]
_0800B6DE:
	adds r0, r5, 0
	bl sub_800B7C0
	adds r0, r6, 0
	bl sub_800B8A8
_0800B6EA:
	movs r0, 0
	strb r0, [r4]
	ldr r1, =gLink
	ldrb r2, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r1]
	cmp r0, 0x8
	bne _0800B702
	movs r0, 0x20
	orrs r2, r0
_0800B702:
	ldrb r0, [r1, 0xC]
	lsls r3, r0, 8
	ldrb r0, [r1, 0xF]
	lsls r4, r0, 9
	ldrb r0, [r1, 0x10]
	lsls r5, r0, 12
	ldrb r0, [r1, 0x11]
	lsls r6, r0, 13
	ldrb r0, [r1, 0x12]
	lsls r7, r0, 14
	ldrb r0, [r1, 0x1]
	cmp r0, 0x4
	bne _0800B728
	movs r0, 0x40
	orrs r0, r3
	orrs r0, r2
	b _0800B72C
	.pool
_0800B728:
	adds r0, r2, 0
	orrs r0, r3
_0800B72C:
	orrs r0, r4
	orrs r0, r5
	orrs r0, r6
	orrs r0, r7
	adds r2, r0, 0
	ldrb r3, [r1, 0x13]
	cmp r3, 0x1
	bne _0800B742
	movs r0, 0x80
	lsls r0, 9
	orrs r2, r0
_0800B742:
	ldrb r0, [r1, 0x2]
	cmp r0, 0x3
	bls _0800B74E
	movs r0, 0x80
	lsls r0, 10
	orrs r2, r0
_0800B74E:
	adds r1, r2, 0
	cmp r3, 0x2
	bne _0800B75A
	movs r0, 0x80
	lsls r0, 11
	orrs r1, r0
_0800B75A:
	adds r0, r1, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800B638

	thumb_func_start sub_800B764
sub_800B764: @ 800B764
	push {lr}
	ldr r0, =0x04000128
	ldr r1, [r0]
	movs r0, 0xC
	ands r1, r0
	ldr r2, =gLink
	cmp r1, 0x8
	bne _0800B788
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0800B788
	strb r1, [r2]
	b _0800B78C
	.pool
_0800B788:
	movs r0, 0
	strb r0, [r2]
_0800B78C:
	pop {r0}
	bx r0
	thumb_func_end sub_800B764

	thumb_func_start sub_800B790
sub_800B790: @ 800B790
	push {lr}
	ldr r0, =gLink
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800B7AE
	ldr r1, =0x0400010c
	ldr r2, =0x0000ff3b
	adds r0, r2, 0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x41
	strh r0, [r1]
	movs r0, 0x40
	bl EnableInterrupts
_0800B7AE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B790

	thumb_func_start sub_800B7C0
sub_800B7C0: @ 800B7C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r3, r0, 0
	ldr r2, =gUnknown_03004134
	ldr r1, =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gLink
	ldr r4, =0x00000339
	adds r0, r1, r4
	ldrb r4, [r0]
	adds r6, r1, 0
	cmp r4, 0x31
	bhi _0800B850
	movs r1, 0xCE
	lsls r1, 2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800B7FE
	subs r0, 0x32
	lsls r0, 24
	lsrs r0, 24
_0800B7FE:
	movs r2, 0
	ldr r4, =gUnknown_03000D6E
	mov r9, r4
	ldr r1, =gUnknown_03003160
	mov r10, r1
	lsls r5, r0, 1
	movs r0, 0x18
	adds r0, r6
	mov r8, r0
	mov r12, r2
	movs r7, 0x64
_0800B814:
	ldrh r0, [r4]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r2, 0
	muls r0, r7
	adds r0, r5, r0
	add r0, r8
	strh r1, [r0]
	mov r1, r12
	strh r1, [r3]
	adds r3, 0x2
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0800B814
	b _0800B85C
	.pool
_0800B850:
	movs r0, 0x1
	strb r0, [r6, 0x12]
	ldr r2, =gUnknown_03000D6E
	mov r9, r2
	ldr r4, =gUnknown_03003160
	mov r10, r4
_0800B85C:
	mov r1, r9
	ldrh r0, [r1]
	cmp r0, 0
	beq _0800B874
	ldr r2, =0x00000339
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r1, 0x1
	movs r2, 0
	strb r1, [r0]
	mov r4, r9
	strh r2, [r4]
_0800B874:
	ldr r1, =0x04000208
	ldr r2, =gUnknown_03004134
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r4, =0x00000339
	adds r0, r6, r4
	ldrb r0, [r0]
	mov r1, r10
	strb r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B7C0

	thumb_func_start sub_800B8A8
sub_800B8A8: @ 800B8A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	ldr r2, =gUnknown_03004134
	ldr r1, =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gLink
	ldr r3, =0x00000fbd
	adds r0, r1, r3
	ldrb r0, [r0]
	mov r12, r1
	cmp r0, 0
	bne _0800B914
	movs r3, 0
	ldrb r0, [r1, 0x3]
	cmp r3, r0
	bcs _0800B8FA
	movs r5, 0
	adds r6, r0, 0
_0800B8DA:
	movs r2, 0
	lsls r1, r3, 4
	adds r4, r3, 0x1
	add r1, r9
_0800B8E2:
	lsls r0, r2, 1
	adds r0, r1
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0800B8E2
	lsls r0, r4, 24
	lsrs r3, r0, 24
	cmp r3, r6
	bcc _0800B8DA
_0800B8FA:
	movs r0, 0x1
	mov r7, r12
	strb r0, [r7, 0xC]
	b _0800B990
	.pool
_0800B914:
	movs r3, 0
	mov r0, r12
	ldrb r1, [r0, 0x3]
	cmp r3, r1
	bcs _0800B96A
	ldr r0, =0x00000fbc
	add r0, r12
	ldrb r0, [r0]
	lsls r6, r0, 1
	movs r2, 0xCF
	lsls r2, 2
	add r2, r12
	mov r8, r2
	mov r10, r1
_0800B930:
	movs r2, 0
	lsls r1, r3, 4
	adds r4, r3, 0x1
	lsls r0, r3, 1
	mov r7, r9
	adds r5, r1, r7
	adds r0, r3
	lsls r0, 3
	adds r0, r3
	lsls r3, r0, 5
_0800B944:
	lsls r1, r2, 1
	adds r1, r5
	movs r7, 0x64
	adds r0, r2, 0
	muls r0, r7
	adds r0, r6, r0
	adds r0, r3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0800B944
	lsls r0, r4, 24
	lsrs r3, r0, 24
	cmp r3, r10
	bcc _0800B930
_0800B96A:
	mov r2, r12
	ldr r0, =0x00000fbd
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, 0x1
	movs r3, 0
	strb r0, [r1]
	ldr r1, =0x00000fbc
	adds r2, r1
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800B98C
	strb r3, [r2]
_0800B98C:
	mov r2, r12
	strb r3, [r2, 0xC]
_0800B990:
	ldr r1, =0x04000208
	ldr r3, =gUnknown_03004134
	ldrh r0, [r3]
	strh r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B8A8

	thumb_func_start sub_800B9B8
sub_800B9B8: @ 800B9B8
	push {r4,lr}
	ldr r3, =gLink
	ldrb r4, [r3]
	cmp r4, 0
	beq _0800B9F4
	ldrb r0, [r3, 0x1]
	cmp r0, 0x2
	beq _0800B9EE
	cmp r0, 0x4
	bne _0800BA1E
	movs r0, 0xD
	ldrsb r0, [r3, r0]
	cmp r0, 0x8
	bgt _0800B9E4
	ldrb r0, [r3, 0x10]
	cmp r0, 0x1
	beq _0800B9EE
	movs r0, 0x1
	strb r0, [r3, 0x13]
	b _0800BA1E
	.pool
_0800B9E4:
	ldrb r0, [r3, 0x13]
	cmp r0, 0x1
	beq _0800BA1E
	movs r0, 0
	strb r0, [r3, 0xD]
_0800B9EE:
	bl sub_800BAC0
	b _0800BA1E
_0800B9F4:
	ldrb r2, [r3, 0x1]
	cmp r2, 0x4
	beq _0800B9FE
	cmp r2, 0x2
	bne _0800BA1E
_0800B9FE:
	ldr r1, =gUnknown_03000D6C
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA
	bls _0800BA1E
	cmp r2, 0x4
	bne _0800BA16
	movs r0, 0x2
	strb r0, [r3, 0x13]
_0800BA16:
	cmp r2, 0x2
	bne _0800BA1E
	strb r4, [r3, 0x3]
	strb r4, [r3, 0xF]
_0800BA1E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B9B8

	thumb_func_start Timer3Intr
Timer3Intr: @ 800BA28
	push {lr}
	bl sub_800BD98
	bl sub_800BAC0
	pop {r0}
	bx r0
	thumb_func_end Timer3Intr

	thumb_func_start sub_800BA38
sub_800BA38: @ 800BA38
	push {r4,lr}
	ldr r4, =gLink
	ldr r0, =0x04000128
	ldr r1, [r0]
	lsls r0, r1, 26
	lsrs r0, 30
	strb r0, [r4, 0x2]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _0800BA6C
	cmp r0, 0x4
	bne _0800BA8A
	lsls r0, r1, 25
	lsrs r0, 31
	strb r0, [r4, 0x10]
	bl sub_800BBCC
	bl sub_800BCE4
	bl sub_800BDCC
	b _0800BA8A
	.pool
_0800BA6C:
	bl sub_800BAD0
	lsls r0, 24
	cmp r0, 0
	beq _0800BA8A
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800BA86
	movs r0, 0x3
	strb r0, [r4, 0x1]
	movs r0, 0x8
	strb r0, [r4, 0xD]
	b _0800BA8A
_0800BA86:
	movs r0, 0x4
	strb r0, [r4, 0x1]
_0800BA8A:
	ldr r3, =gLink
	ldrb r0, [r3, 0xD]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r3, 0xD]
	ldr r1, =gUnknown_03000D6C
	strb r2, [r1]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x8
	bne _0800BAAA
	ldr r0, =gUnknown_03004130
	ldr r2, =0x00000fbd
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
_0800BAAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BA38

	thumb_func_start sub_800BAC0
sub_800BAC0: @ 800BAC0
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_800BAC0

	thumb_func_start sub_800BAD0
sub_800BAD0: @ 800BAD0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	ldr r6, =0x0000ffff
	ldr r0, =gLink
	ldrb r1, [r0, 0xE]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _0800BAFC
	ldr r1, =0x0400012a
	ldr r2, =0x00008fff
	b _0800BB00
	.pool
_0800BAFC:
	ldr r1, =0x0400012a
	ldr r2, =0x0000b9a0
_0800BB00:
	adds r0, r2, 0
	strh r0, [r1]
	ldr r2, =gLink+0x4
	ldr r3, =0x04000120
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
	movs r1, 0
	str r0, [r3]
	str r1, [r3, 0x4]
	strb r0, [r2, 0xA]
	movs r4, 0
	ldr r0, =gUnknown_03000D73
	mov r9, r0
	mov r8, r2
	ldr r2, =0x00008fff
	ldr r1, =0x0000ffff
	mov r12, r1
_0800BB28:
	lsls r0, r4, 1
	add r0, r8
	ldrh r3, [r0]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	ldr r1, =0x0000b9a0
	cmp r0, r1
	beq _0800BB40
	adds r0, r3, 0
	cmp r0, r2
	bne _0800BB70
_0800BB40:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r3, 0
	cmp r6, r0
	bls _0800BB78
	cmp r0, 0
	beq _0800BB78
	adds r6, r3, 0
	b _0800BB78
	.pool
_0800BB70:
	cmp r0, r12
	beq _0800BB82
	movs r5, 0
	b _0800BB82
_0800BB78:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800BB28
_0800BB82:
	strb r5, [r7, 0x3]
	adds r0, r5, 0
	cmp r0, 0x1
	bls _0800BBB2
	mov r2, r9
	ldrb r2, [r2]
	cmp r0, r2
	bne _0800BBA4
	ldrh r1, [r7, 0x4]
	ldr r0, =0x00008fff
	cmp r1, r0
	bne _0800BBA4
	movs r0, 0x1
	b _0800BBBE
	.pool
_0800BBA4:
	ldrb r0, [r7, 0x3]
	cmp r0, 0x1
	bls _0800BBB2
	movs r0, 0x3
	ands r6, r0
	adds r0, r6, 0x1
	b _0800BBB4
_0800BBB2:
	movs r0, 0
_0800BBB4:
	strb r0, [r7, 0xF]
	ldrb r0, [r7, 0x3]
	mov r1, r9
	strb r0, [r1]
	movs r0, 0
_0800BBBE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800BAD0

	thumb_func_start sub_800BBCC
sub_800BBCC: @ 800BBCC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gLink
	ldrb r1, [r0, 0x16]
	adds r6, r0, 0
	cmp r1, 0
	bne _0800BC30
	movs r4, 0
	ldr r7, =gUnknown_03000D72
	ldrb r0, [r6, 0x3]
	cmp r4, r0
	bcs _0800BC1A
	adds r5, r6, 0
	ldrh r1, [r6, 0x14]
	adds r3, r7, 0
	adds r2, r6, 0
_0800BBFA:
	lsls r0, r4, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r1, r0
	beq _0800BC0E
	ldrb r0, [r3]
	cmp r0, 0
	beq _0800BC0E
	movs r0, 0x1
	strb r0, [r5, 0x11]
_0800BC0E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r2, 0x3]
	cmp r4, r0
	bcc _0800BBFA
_0800BC1A:
	movs r0, 0
	strh r0, [r6, 0x14]
	movs r0, 0x1
	strb r0, [r7]
	b _0800BCD0
	.pool
_0800BC30:
	ldr r2, =0x00000fbc
	adds r1, r6, r2
	adds r2, 0x1
	adds r0, r6, r2
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r0, r2, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800BC4C
	subs r0, 0x32
	lsls r0, 24
	lsrs r0, 24
_0800BC4C:
	cmp r2, 0x31
	bhi _0800BCA8
	movs r4, 0
	ldrb r1, [r6, 0x3]
	cmp r4, r1
	bcs _0800BCAC
	adds r5, r6, 0
	ldr r7, =gUnknown_03000D70
	lsls r0, 1
	mov r12, r0
	movs r2, 0xCF
	lsls r2, 2
	adds r2, r6
	mov r8, r2
_0800BC68:
	lsls r1, r4, 1
	mov r2, sp
	adds r0, r2, r1
	ldrh r3, [r0]
	ldrh r2, [r5, 0x14]
	adds r0, r3, r2
	strh r0, [r5, 0x14]
	ldrh r0, [r7]
	orrs r0, r3
	strh r0, [r7]
	ldrb r2, [r5, 0x17]
	movs r0, 0x64
	muls r0, r2
	add r0, r12
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 5
	adds r0, r1
	add r0, r8
	strh r3, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5, 0x3]
	cmp r4, r0
	bcc _0800BC68
	b _0800BCAC
	.pool
_0800BCA8:
	movs r0, 0x2
	strb r0, [r6, 0x12]
_0800BCAC:
	ldrb r0, [r6, 0x17]
	adds r0, 0x1
	strb r0, [r6, 0x17]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bne _0800BCD0
	ldr r2, =gUnknown_03000D70
	ldrh r0, [r2]
	cmp r0, 0
	beq _0800BCD0
	ldr r1, =0x00000fbd
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	movs r0, 0
	strh r0, [r2]
_0800BCD0:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BBCC

	thumb_func_start sub_800BCE4
sub_800BCE4: @ 800BCE4
	push {r4,lr}
	ldr r0, =gLink
	ldrb r1, [r0, 0x16]
	adds r4, r0, 0
	cmp r1, 0x8
	bne _0800BD36
	ldr r1, =0x0400012a
	ldrh r0, [r4, 0x14]
	strh r0, [r1]
	ldr r1, =gUnknown_03000D6D
	ldrb r2, [r1]
	cmp r2, 0
	bne _0800BD30
	ldr r0, =0x00000339
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	movs r0, 0xCE
	lsls r0, 2
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800BD8C
	strb r2, [r1]
	b _0800BD8C
	.pool
_0800BD30:
	movs r0, 0
	strb r0, [r1]
	b _0800BD8C
_0800BD36:
	ldr r1, =gUnknown_03000D6D
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800BD52
	ldr r2, =0x00000339
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800BD4C
	movs r0, 0x1
	strb r0, [r1]
_0800BD4C:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800BD68
_0800BD52:
	ldr r1, =0x0400012a
	movs r0, 0
	strh r0, [r1]
	b _0800BD86
	.pool
_0800BD68:
	ldr r3, =0x0400012a
	movs r1, 0xCE
	lsls r1, 2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, 1
	ldrb r2, [r4, 0x16]
	movs r1, 0x64
	muls r1, r2
	adds r0, r1
	adds r1, r4, 0
	adds r1, 0x18
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
_0800BD86:
	ldrb r0, [r4, 0x16]
	adds r0, 0x1
	strb r0, [r4, 0x16]
_0800BD8C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BCE4

	thumb_func_start sub_800BD98
sub_800BD98: @ 800BD98
	push {lr}
	ldr r0, =gLink
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800BDB4
	ldr r2, =0x0400010e
	ldrh r1, [r2]
	ldr r0, =0x0000ff7f
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0400010c
	ldr r2, =0x0000ff3b
	adds r0, r2, 0
	strh r0, [r1]
_0800BDB4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BD98

	thumb_func_start sub_800BDCC
sub_800BDCC: @ 800BDCC
	push {lr}
	ldr r1, =gLink
	ldrb r0, [r1, 0x17]
	cmp r0, 0x8
	bne _0800BDE4
	movs r0, 0
	strb r0, [r1, 0x16]
	strb r0, [r1, 0x17]
	b _0800BDF4
	.pool
_0800BDE4:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800BDF4
	ldr r0, =0x0400010e
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
_0800BDF4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BDCC

	thumb_func_start sub_800BDFC
sub_800BDFC: @ 800BDFC
	push {r4-r6,lr}
	ldr r1, =gLink
	ldr r2, =0x00000339
	adds r0, r1, r2
	movs r2, 0
	strb r2, [r0]
	movs r3, 0xCE
	lsls r3, 2
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, 0
	movs r6, 0x64
	adds r5, r1, 0
	adds r5, 0x18
	ldr r4, =0x0000efff
_0800BE1A:
	movs r2, 0
	adds r1, r0, 0x1
	adds r3, r0, 0
	muls r3, r6
_0800BE22:
	lsls r0, r2, 1
	adds r0, r3
	adds r0, r5
	strh r4, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x31
	bls _0800BE22
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x7
	bls _0800BE1A
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BDFC

	thumb_func_start sub_800BE50
sub_800BE50: @ 800BE50
	push {r4-r7,lr}
	ldr r1, =gLink
	ldr r2, =0x00000fbd
	adds r0, r1, r2
	movs r2, 0
	strb r2, [r0]
	ldr r3, =0x00000fbc
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, 0x64
	mov r12, r0
	movs r3, 0xCF
	lsls r3, 2
	adds r7, r1, r3
	ldr r6, =0x0000efff
_0800BE6E:
	movs r3, 0
	lsls r0, r2, 1
	adds r5, r2, 0x1
	adds r0, r2
	lsls r0, 3
	adds r0, r2
	lsls r4, r0, 5
_0800BE7C:
	movs r2, 0
	adds r1, r3, 0x1
	mov r0, r12
	muls r0, r3
	adds r3, r0, 0
_0800BE86:
	lsls r0, r2, 1
	adds r0, r3
	adds r0, r4
	adds r0, r7
	strh r6, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x31
	bls _0800BE86
	lsls r0, r1, 24
	lsrs r3, r0, 24
	cmp r3, 0x7
	bls _0800BE7C
	lsls r0, r5, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0800BE6E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BE50

@  break

	.align 2, 0 @ Don't pad with nop.
