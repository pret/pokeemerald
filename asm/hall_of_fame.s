	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_817354C
sub_817354C: @ 817354C
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_817354C

	thumb_func_start sub_8173560
sub_8173560: @ 8173560
	push {lr}
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_8173560

	thumb_func_start sub_817357C
sub_817357C: @ 817357C
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _08173590
	b _08173688
_08173590:
	lsls r0, 2
	ldr r1, =_081735A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081735A4:
	.4byte _081735B8
	.4byte _081735E8
	.4byte _081735EE
	.4byte _08173620
	.4byte _0817365C
_081735B8:
	movs r0, 0
	bl SetVBlankCallback
	bl sub_8174EC4
	ldr r4, =gUnknown_0203BCDC
	ldr r0, =0x00002014
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _08173688
	.pool
_081735E8:
	bl sub_8174F70
	b _08173642
_081735EE:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0xE2
	lsls r1, 3
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	bl sub_8174FAC
	ldr r0, =gUnknown_0203BCDC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1]
	b _08173642
	.pool
_08173620:
	bl sub_8175024
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08173688
	ldr r0, =sub_817354C
	bl SetVBlankCallback
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_08173642:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08173688
	.pool
_0817365C:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08173688
	ldr r0, =sub_8173560
	bl SetMainCallback2
	movs r0, 0xDA
	lsls r0, 1
	bl song_play_for_text
	movs r0, 0
	b _0817368A
	.pool
_08173688:
	movs r0, 0x1
_0817368A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_817357C

	thumb_func_start sub_8173694
sub_8173694: @ 8173694
	push {r4,lr}
	bl sub_817357C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081736C4
	ldr r0, =sub_817371C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	ldr r4, =gUnknown_0203BCD8
	movs r0, 0x78
	bl AllocZeroed
	str r0, [r4]
_081736C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173694

	thumb_func_start sub_81736D8
sub_81736D8: @ 81736D8
	push {r4,lr}
	bl sub_817357C
	lsls r0, 24
	cmp r0, 0
	bne _08173708
	ldr r0, =sub_817371C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	ldr r4, =gUnknown_0203BCD8
	movs r0, 0x78
	bl AllocZeroed
	str r0, [r4]
_08173708:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81736D8

	thumb_func_start sub_817371C
sub_817371C: @ 817371C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	movs r7, 0
	ldr r0, =gUnknown_0203BCD8
	mov r9, r0
_08173740:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r6, r1, r0
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	cmp r5, 0
	beq _0817380C
	adds r0, r6, 0
	movs r1, 0x41
	bl GetMonData
	mov r1, r9
	ldr r3, [r1]
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 2
	adds r3, r4
	ldr r2, =0x000001ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r1, [r3, 0x8]
	ldr r5, =0xfffffe00
	adds r2, r5, 0
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	bl GetMonData
	mov r2, r9
	ldr r1, [r2]
	adds r1, r4
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0
	bl GetMonData
	mov r5, r9
	ldr r1, [r5]
	adds r1, 0x4
	adds r1, r4
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0x38
	bl GetMonData
	ldr r2, [r5]
	adds r2, r4
	lsls r0, 1
	ldrb r3, [r2, 0x9]
	movs r1, 0x1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x9]
	adds r0, r6, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	movs r2, 0
	mov r6, r8
	lsls r5, r6, 2
	ldr r3, =gUnknown_0203BCD8
_081737CA:
	ldr r0, [r3]
	adds r1, r2, r4
	adds r0, 0xA
	adds r0, r1
	mov r6, sp
	adds r1, r6, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9
	bls _081737CA
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r5, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	b _08173840
	.pool
_0817380C:
	mov r6, r9
	ldr r3, [r6]
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 2
	adds r4, r3, r2
	ldrh r0, [r4, 0x8]
	ldr r6, =0xfffffe00
	adds r1, r6, 0
	ands r0, r1
	strh r0, [r4, 0x8]
	str r5, [r4]
	adds r3, 0x4
	adds r3, r2
	str r5, [r3]
	ldrb r1, [r4, 0x9]
	movs r0, 0x1
	ands r0, r1
	strb r0, [r4, 0x9]
	mov r1, r9
	ldr r0, [r1]
	adds r0, r2
	movs r1, 0xFF
	strb r1, [r0, 0xA]
	mov r2, r8
	lsls r5, r2, 2
_08173840:
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bhi _0817384C
	b _08173740
_0817384C:
	ldr r0, =gUnknown_0203BCD4
	movs r3, 0
	str r3, [r0]
	ldr r4, =gTasks
	mov r6, r8
	adds r1, r5, r6
	lsls r1, 3
	adds r2, r1, r4
	strh r3, [r2, 0xA]
	movs r0, 0xFF
	strh r0, [r2, 0x10]
	movs r7, 0
	adds r3, r4, 0
	adds r3, 0x8
	movs r2, 0xFF
_0817386A:
	adds r0, r7, 0x5
	lsls r0, 1
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _0817386A
	mov r1, r8
	adds r0, r5, r1
	lsls r0, 3
	adds r1, r0, r4
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _081738A4
	ldr r0, =sub_8173A8C
	b _081738A6
	.pool
_081738A4:
	ldr r0, =sub_81738BC
_081738A6:
	str r0, [r1]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817371C

	thumb_func_start sub_81738BC
sub_81738BC: @ 81738BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r7, =0x0201c000
	ldr r0, =gUnknown_0203BCE4
	ldrb r0, [r0]
	cmp r0, 0
	bne _081738EC
	movs r2, 0x80
	lsls r2, 6
	adds r0, r7, 0
	movs r1, 0
	bl memset
	b _08173906
	.pool
_081738EC:
	movs r0, 0x3
	bl sub_81534D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08173906
	movs r2, 0x80
	lsls r2, 6
	adds r0, r7, 0
	movs r1, 0
	bl memset
_08173906:
	movs r5, 0
	ldrh r1, [r7, 0x8]
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r0, r1
	mov r1, r9
	lsls r1, 2
	mov r8, r1
	cmp r0, 0
	beq _08173930
_0817391A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r7, 0x78
	cmp r5, 0x31
	bhi _08173934
	ldrh r1, [r7, 0x8]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0817391A
_08173930:
	cmp r5, 0x31
	bls _08173956
_08173934:
	ldr r4, =0x0201c000
	adds r6, r4, 0
	adds r4, 0x78
	movs r5, 0
	subs r7, 0x78
_0817393E:
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x78
	bl memcpy
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, 0x78
	adds r4, 0x78
	cmp r5, 0x30
	bls _0817393E
_08173956:
	ldr r0, =gUnknown_0203BCD8
	ldr r1, [r0]
	adds r0, r7, 0
	movs r2, 0x78
	bl memcpy
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gUnknown_082C8959
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	mov r0, r8
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81739C4
	str r1, [r0]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81738BC

	thumb_func_start sub_81739C4
sub_81739C4: @ 81739C4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_03006214
	ldr r0, =sub_81736D8
	str r0, [r1]
	movs r0, 0x3
	bl save_game_when_memory_present
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08173A34
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08173A34
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	bl FreeAllWindowBuffers
	ldr r5, =gUnknown_0203BCDC
	ldr r0, [r5]
	cmp r0, 0
	beq _08173A06
	bl Free
	movs r0, 0
	str r0, [r5]
_08173A06:
	ldr r5, =gUnknown_0203BCD8
	ldr r0, [r5]
	cmp r0, 0
	beq _08173A16
	bl Free
	movs r0, 0
	str r0, [r5]
_08173A16:
	adds r0, r4, 0
	bl DestroyTask
	b _08173A4C
	.pool
_08173A34:
	movs r0, 0x37
	bl audio_play
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8173A5C
	str r1, [r0]
	movs r1, 0x20
	strh r1, [r0, 0xE]
_08173A4C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81739C4

	thumb_func_start sub_8173A5C
sub_8173A5C: @ 8173A5C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08173A80
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	b _08173A84
	.pool
_08173A80:
	ldr r0, =sub_8173A8C
	str r0, [r1]
_08173A84:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173A5C

	thumb_func_start sub_8173A8C
sub_8173A8C: @ 8173A8C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_8173AA8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8173A8C

	thumb_func_start sub_8173AA8
sub_8173AA8: @ 8173AA8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldrh r6, [r1, 0xA]
	ldr r2, =gUnknown_0203BCD8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	ldr r2, [r2]
	adds r7, r2, r0
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0x3
	ble _08173AEC
	ldr r1, =gUnknown_085E53B4
	b _08173AEE
	.pool
_08173AEC:
	ldr r1, =gUnknown_085E53E4
_08173AEE:
	lsls r2, r6, 3
	adds r0, r2, r1
	ldrh r3, [r0]
	adds r0, r1, 0x2
	adds r0, r2, r0
	ldrh r4, [r0]
	adds r0, r1, 0x4
	adds r0, r2, r0
	ldrh r0, [r0]
	mov r9, r0
	adds r1, 0x6
	adds r2, r1
	ldrh r5, [r2]
	ldrh r2, [r7, 0x8]
	ldr r0, =0x000001ff
	ands r0, r2
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _08173B20
	lsls r0, r5, 16
	movs r1, 0xA0
	lsls r1, 12
	adds r0, r1
	lsrs r5, r0, 16
_08173B20:
	lsls r0, r2, 23
	lsrs r0, 23
	ldr r1, [r7]
	ldr r2, [r7, 0x4]
	lsls r3, 16
	asrs r3, 16
	str r3, [sp]
	lsls r3, r4, 16
	asrs r3, 16
	str r3, [sp, 0x4]
	lsls r3, r6, 24
	lsrs r3, 24
	str r3, [sp, 0x8]
	ldr r3, =0x0000ffff
	str r3, [sp, 0xC]
	movs r3, 0x1
	bl sub_818D3E4
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r3, r2, r4
	movs r1, 0
	mov r12, r1
	mov r1, r9
	strh r1, [r3, 0x30]
	strh r5, [r3, 0x32]
	mov r1, r12
	strh r1, [r3, 0x2E]
	ldrh r1, [r7, 0x8]
	lsls r1, 23
	lsrs r1, 23
	strh r1, [r3, 0x3C]
	adds r4, 0x1C
	adds r2, r4
	ldr r1, =sub_8175120
	str r1, [r2]
	ldr r5, =gTasks
	adds r1, r6, 0x5
	lsls r1, 1
	mov r2, r8
	lsls r4, r2, 2
	add r4, r8
	lsls r4, 3
	adds r1, r4
	adds r2, r5, 0
	adds r2, 0x8
	adds r1, r2
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	adds r4, r5
	ldr r0, =sub_8173BC0
	str r0, [r4]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173AA8

	thumb_func_start sub_8173BC0
sub_8173BC0: @ 8173BC0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 3
	adds r5, r3, r4
	ldrh r0, [r5, 0xA]
	ldr r2, =gUnknown_0203BCD8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, [r2]
	adds r2, r1
	adds r0, 0x5
	lsls r0, 1
	adds r0, r3
	adds r4, 0x8
	adds r0, r4
	movs r3, 0
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	ldr r1, [r3, 0x1C]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _08173C1A
	ldrb r1, [r3, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x1]
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0xE
	bl sub_8174A88
	movs r0, 0x78
	strh r0, [r5, 0xE]
	ldr r0, =sub_8173C34
	str r0, [r5]
_08173C1A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173BC0

	thumb_func_start sub_8173C34
sub_8173C34: @ 8173C34
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r6, r0, 3
	adds r4, r6, r2
	ldrh r3, [r4, 0xA]
	ldr r1, =gUnknown_0203BCD8
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	mov r9, r1
	ldrh r1, [r4, 0xE]
	movs r7, 0xE
	ldrsh r0, [r4, r7]
	mov r12, r2
	cmp r0, 0
	beq _08173C78
	subs r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _08173D10
	.pool
_08173C78:
	ldr r2, =gUnknown_0203BCD4
	ldr r0, =gSprites
	mov r8, r0
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r6
	mov r1, r12
	adds r1, 0x8
	adds r6, r0, r1
	movs r7, 0
	ldrsh r1, [r6, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r0
	ldr r3, [r2]
	orrs r3, r1
	str r3, [r2]
	ldrh r2, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bgt _08173D04
	mov r7, r9
	ldrh r1, [r7, 0x1C]
	ldr r0, =0x000001ff
	ands r0, r1
	cmp r0, 0
	beq _08173D04
	adds r0, r2, 0x1
	strh r0, [r4, 0xA]
	ldr r0, =0x000063b0
	str r0, [sp]
	adds r0, r3, 0
	movs r1, 0
	movs r2, 0xC
	movs r3, 0xC
	bl BeginNormalPaletteFade
	movs r0, 0
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r0, =sub_8173AA8
	str r0, [r4]
	b _08173D10
	.pool
_08173D04:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	add r0, r12
	ldr r1, =sub_8173D24
	str r1, [r0]
_08173D10:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173C34

	thumb_func_start sub_8173D24
sub_8173D24: @ 8173D24
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0xffff0000
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r3, 0
	lsls r1, r4, 2
	adds r0, r1, r4
	lsls r5, r0, 3
	ldr r0, =gTasks + 0x8
	mov r12, r0
	mov r8, r1
	ldr r6, =gSprites
	movs r7, 0xD
	negs r7, r7
_08173D52:
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r5
	mov r2, r12
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xFF
	beq _08173D74
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x5]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1, 0x5]
_08173D74:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _08173D52
	movs r0, 0
	movs r1, 0xF
	bl sub_8174A38
	movs r0, 0x69
	bl audio_play
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0xC8
	lsls r1, 1
	strh r1, [r0, 0xE]
	ldr r1, =sub_8173DC0
	str r1, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173D24

	thumb_func_start sub_8173DC0
sub_8173DC0: @ 8173DC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gTasks
	lsls r4, r6, 2
	adds r0, r4, r6
	lsls r5, r0, 3
	adds r1, r5, r7
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08173E04
	subs r2, 0x1
	strh r2, [r1, 0xE]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0
	bne _08173E7E
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x6E
	ble _08173E7E
	bl sub_81751FC
	b _08173E7E
	.pool
_08173E04:
	movs r3, 0
	mov r9, r4
	ldr r0, =gUnknown_0203BCD4
	mov r10, r0
	adds r4, r5, 0
	adds r7, 0x8
	mov r8, r7
	ldr r7, =gSprites
	movs r1, 0xD
	negs r1, r1
	mov r12, r1
	movs r5, 0x4
_08173E1C:
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r4
	mov r2, r8
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xFF
	beq _08173E40
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	mov r0, r12
	ands r0, r2
	orrs r0, r5
	strb r0, [r1, 0x5]
_08173E40:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _08173E1C
	mov r3, r10
	ldr r0, [r3]
	ldr r1, =0x000063b0
	str r1, [sp]
	movs r1, 0
	movs r2, 0xC
	movs r3, 0xC
	bl BeginNormalPaletteFade
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	mov r2, r9
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x7
	strh r1, [r0, 0xE]
	ldr r1, =sub_8173EA4
	str r1, [r0]
_08173E7E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173DC0

	thumb_func_start sub_8173EA4
sub_8173EA4: @ 8173EA4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0xF
	ble _08173ECC
	ldr r0, =sub_8173EE4
	str r0, [r1]
	b _08173EDE
	.pool
_08173ECC:
	adds r0, r2, 0x1
	strh r0, [r1, 0xE]
	movs r0, 0xE
	ldrsh r1, [r1, r0]
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_08173EDE:
	pop {r0}
	bx r0
	thumb_func_end sub_8173EA4

	thumb_func_start sub_8173EE4
sub_8173EE4: @ 8173EE4
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldrb r0, [r0, 0x8]
	movs r1, 0x1
	bl sub_818D97C
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	str r1, [sp]
	ldr r1, =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	movs r2, 0x78
	movs r3, 0x48
	bl sub_818D8AC
	ldr r1, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r1
	strh r0, [r4, 0x10]
	ldr r0, =gUnknown_085E5380
	bl AddWindow
	ldr r0, [r6]
	ldrb r1, [r0, 0x14]
	lsrs r1, 3
	ldr r2, =0x0000021d
	movs r0, 0x1
	movs r3, 0xD0
	bl sub_80987D4
	movs r0, 0x1
	bl stdpal_get
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x78
	strh r0, [r4, 0xE]
	ldr r0, =sub_8173F84
	str r0, [r4]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173EE4

	thumb_func_start sub_8173F84
sub_8173F84: @ 8173F84
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0xE]
	movs r1, 0xE
	ldrsh r5, [r4, r1]
	cmp r5, 0
	beq _08173FAC
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _08174018
	.pool
_08173FAC:
	ldr r2, =gSprites
	movs r3, 0x10
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0xC0
	beq _08173FD0
	adds r0, r2, 0x1
	strh r0, [r1, 0x20]
	b _08174018
	.pool
_08173FD0:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	movs r1, 0x2
	bl sub_8174C98
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gUnknown_085E8C14
	str r5, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_8174028
	str r0, [r4]
_08174018:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173F84

	thumb_func_start sub_8174028
sub_8174028: @ 8174028
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0817404E
	movs r0, 0x4
	bl play_sound_effect
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8174060
	str r0, [r1]
_0817404E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174028

	thumb_func_start sub_8174060
sub_8174060: @ 8174060
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPlttBufferFaded
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 2
	bl CpuSet
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81740B0
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174060

	thumb_func_start sub_81740B0
sub_81740B0: @ 81740B0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08174164
	lsls r0, r7, 2
	mov r8, r0
	ldr r1, =gTasks
	adds r0, r7
	lsls r0, 3
	adds r1, 0x12
	adds r5, r0, r1
	ldr r2, =gSprites
	mov r9, r2
	movs r6, 0x5
_081740DC:
	ldrb r4, [r5]
	cmp r4, 0xFF
	beq _081740FA
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	add r0, r9
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl sub_818D820
_081740FA:
	adds r5, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _081740DC
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x10]
	bl sub_818D8F0
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x3
	bl HideBg
	bl FreeAllWindowBuffers
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	adds r0, r7, 0
	bl DestroyTask
	ldr r4, =gUnknown_0203BCDC
	ldr r0, [r4]
	cmp r0, 0
	beq _08174150
	bl Free
	movs r0, 0
	str r0, [r4]
_08174150:
	ldr r4, =gUnknown_0203BCD8
	ldr r0, [r4]
	cmp r0, 0
	beq _08174160
	bl Free
	movs r0, 0
	str r0, [r4]
_08174160:
	bl sub_8174184
_08174164:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81740B0

	thumb_func_start sub_8174184
sub_8174184: @ 8174184
	push {lr}
	ldr r0, =sub_8175620
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174184

	thumb_func_start sub_8174194
sub_8174194: @ 8174194
	push {r4,lr}
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _081741D0
	lsls r0, 2
	ldr r1, =_081741B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081741B8:
	.4byte _081741D0
	.4byte _08174200
	.4byte _08174214
	.4byte _08174240
	.4byte _08174280
	.4byte _081742B0
_081741D0:
	movs r0, 0
	bl SetVBlankCallback
	bl sub_8174EC4
	ldr r4, =gUnknown_0203BCDC
	ldr r0, =0x00002014
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _08174308
	.pool
_08174200:
	bl sub_8174F70
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _081742A2
	.pool
_08174214:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	bl sub_8174FAC
	ldr r1, =gMain
	movs r4, 0x87
	lsls r4, 3
	adds r1, r4
	b _081742A2
	.pool
_08174240:
	bl sub_8175024
	lsls r0, 24
	cmp r0, 0
	bne _08174308
	ldr r1, =0x0201c000
	ldr r0, =gUnknown_085E56D4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_80F9BCC
	ldr r0, =sub_817354C
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r4, 0x87
	lsls r4, 3
	adds r1, r4
	b _081742A2
	.pool
_08174280:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	bl sub_80F9C1C
	lsls r0, 24
	cmp r0, 0
	bne _08174308
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_081742A2:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08174308
	.pool
_081742B0:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0xE2
	lsls r1, 3
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r0, =sub_8174324
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r4, =gTasks + 0x8
	movs r3, 0xFF
_081742E2:
	adds r0, r2, 0x5
	lsls r0, 1
	adds r0, r1
	adds r0, r4
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bls _081742E2
	ldr r4, =gUnknown_0203BCD8
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =sub_8173560
	bl SetMainCallback2
_08174308:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174194

	thumb_func_start sub_8174324
sub_8174324: @ 8174324
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x00000226
	str r0, [sp]
	movs r0, 0
	movs r1, 0x1E
	movs r2, 0
	movs r3, 0xC
	bl sub_81980F0
	movs r0, 0x3
	bl sub_81534D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08174364
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81749A0
	b _081743DA
	.pool
_08174364:
	ldr r0, =0x0201c000
	ldr r4, =gUnknown_0203BCD8
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 5
	bl CpuSet
	ldr r4, [r4]
	movs r2, 0
	ldrh r1, [r4, 0x8]
	ldr r3, =0x000001ff
	adds r0, r3, 0
	ands r0, r1
	lsls r5, r6, 2
	cmp r0, 0
	beq _0817439A
_08174384:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	adds r4, 0x78
	cmp r2, 0x31
	bhi _081743BC
	ldrh r1, [r4, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08174384
_0817439A:
	cmp r2, 0x31
	bhi _081743BC
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	subs r0, r2, 0x1
	b _081743C6
	.pool
_081743BC:
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0x31
_081743C6:
	strh r0, [r1, 0x8]
	movs r0, 0xA
	bl sub_80847F8
	ldr r2, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r2
	strh r0, [r1, 0xA]
	ldr r0, =sub_81743EC
_081743DA:
	str r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174324

	thumb_func_start sub_81743EC
sub_81743EC: @ 81743EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203BCD8
	ldr r3, [r0]
	movs r5, 0
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	adds r4, r1, 0
	ldr r2, =gUnknown_0203BCD4
	cmp r5, r0
	bge _0817442A
	adds r1, r0, 0
_0817441E:
	adds r3, 0x78
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r1
	blt _0817441E
_0817442A:
	adds r6, r3, 0
	movs r0, 0
	str r0, [r2]
	mov r5, r8
	lsls r2, r5, 2
	adds r1, r2, r5
	lsls r1, 3
	adds r1, r4
	strh r0, [r1, 0xC]
	strh r0, [r1, 0x10]
	movs r5, 0
	str r2, [sp, 0x14]
	ldr r4, =0x000001ff
	adds r2, r1, 0
_08174446:
	ldrh r1, [r6, 0x8]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08174456
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	strh r0, [r2, 0x10]
_08174456:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, 0x14
	cmp r5, 0x5
	bls _08174446
	adds r6, r3, 0
	movs r5, 0
	ldr r1, =gTasks
	ldr r0, [sp, 0x14]
	add r0, r8
	lsls r0, 3
	mov r9, r0
	adds r0, r1
	str r0, [sp, 0x10]
	ldr r1, =0x000001ff
	mov r10, r1
_08174478:
	ldrh r0, [r6, 0x8]
	mov r1, r10
	ands r1, r0
	adds r7, r0, 0
	cmp r1, 0
	beq _08174540
	ldr r2, [sp, 0x10]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	cmp r0, 0x3
	ble _081744B8
	lsls r1, r5, 3
	ldr r0, =gUnknown_085E53B4
	adds r0, 0x4
	adds r0, r1, r0
	ldrh r3, [r0]
	ldr r0, =gUnknown_085E53BA
	adds r1, r0
	ldrh r4, [r1]
	b _081744C8
	.pool
_081744B8:
	ldr r0, =gUnknown_085E53E4
	lsls r2, r5, 3
	adds r1, r0, 0x4
	adds r1, r2, r1
	ldrh r3, [r1]
	adds r0, 0x6
	adds r2, r0
	ldrh r4, [r2]
_081744C8:
	mov r1, r10
	ands r1, r7
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bne _081744DE
	lsls r0, r4, 16
	movs r1, 0xA0
	lsls r1, 12
	adds r0, r1
	lsrs r4, r0, 16
_081744DE:
	lsls r0, r7, 23
	lsrs r0, 23
	ldr r1, [r6]
	ldr r2, [r6, 0x4]
	lsls r3, 16
	asrs r3, 16
	str r3, [sp]
	lsls r3, r4, 16
	asrs r3, 16
	str r3, [sp, 0x4]
	lsls r3, r5, 24
	lsrs r3, 24
	str r3, [sp, 0x8]
	ldr r3, =0x0000ffff
	str r3, [sp, 0xC]
	movs r3, 0x1
	bl sub_818D7D8
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r3, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r3, r2
	movs r2, 0x4
	orrs r3, r2
	strb r3, [r1, 0x5]
	adds r1, r5, 0x5
	lsls r1, 1
	add r1, r9
	ldr r2, =gTasks + 0x8
	adds r1, r2
	strh r0, [r1]
	b _0817454E
	.pool
_08174540:
	adds r0, r5, 0x5
	lsls r0, 1
	add r0, r9
	ldr r4, =gTasks + 0x8
	adds r0, r4
	movs r1, 0xFF
	strh r1, [r0]
_0817454E:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, 0x14
	cmp r5, 0x5
	bls _08174478
	ldr r0, =0xffff0000
	ldr r2, =0x000063b0
	movs r1, 0xC
	bl BlendPalettes
	ldr r0, =gStringVar1
	ldr r1, =gTasks
	ldr r4, [sp, 0x14]
	add r4, r8
	lsls r4, 3
	adds r4, r1
	movs r5, 0xA
	ldrsh r1, [r4, r5]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r5, =gStringVar4
	ldr r1, =gUnknown_085E8C00
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _081745C0
	ldr r1, =gUnknown_085E8574
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_8198204
	b _081745D0
	.pool
_081745C0:
	ldr r1, =gUnknown_085E855C
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_8198204
_081745D0:
	ldr r0, =gTasks
	ldr r1, [sp, 0x14]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81745FC
	str r0, [r1]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81743EC

	thumb_func_start sub_81745FC
sub_81745FC: @ 81745FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203BCD8
	ldr r5, [r0]
	movs r3, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	cmp r3, r0
	bge _08174630
	adds r1, r0, 0
_08174624:
	adds r5, 0x78
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	blt _08174624
_08174630:
	movs r3, 0
	lsls r7, r4, 2
	adds r0, r7, r4
	lsls r6, r0, 3
	ldr r0, =gTasks + 0x8
	mov r10, r0
	ldr r1, =gSprites
	mov r8, r1
	movs r2, 0xD
	negs r2, r2
	mov r9, r2
	movs r0, 0x4
	mov r12, r0
_0817464A:
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r6
	add r0, r10
	ldrh r1, [r0]
	cmp r1, 0xFF
	beq _0817466C
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r2, [r0, 0x5]
	mov r1, r9
	ands r1, r2
	mov r2, r12
	orrs r1, r2
	strb r1, [r0, 0x5]
_0817466C:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _0817464A
	adds r1, r7, r4
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, 0x5
	lsls r0, 1
	adds r0, r1
	ldr r1, =gTasks
	adds r1, 0x8
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	strb r1, [r0, 0x5]
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r1
	ldr r1, =0xffff0000
	eors r0, r1
	ldr r2, =gUnknown_0203BCD4
	str r0, [r2]
	ldr r2, =0x000063b0
	movs r1, 0xC
	bl BlendPalettesUnfaded
	movs r0, 0xC
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r4, r5, r0
	ldrh r1, [r4, 0x8]
	ldr r0, =0x000001ff
	ands r0, r1
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _081746E6
	bl sub_80A369C
	ldrh r0, [r4, 0x8]
	lsls r0, 23
	lsrs r0, 23
	movs r1, 0
	bl cry_related
_081746E6:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xE
	bl sub_8174A88
	ldr r0, =sub_8174728
	str r0, [r6]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81745FC

	thumb_func_start sub_8174728
sub_8174728: @ 8174728
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gMain
	ldrh r2, [r1, 0x2E]
	movs r0, 0x1
	ands r0, r2
	adds r3, r1, 0
	cmp r0, 0
	beq _081747E4
	ldr r0, =gTasks
	mov r12, r0
	lsls r0, r6, 2
	adds r1, r0, r6
	lsls r3, r1, 3
	mov r1, r12
	adds r4, r3, r1
	ldrh r2, [r4, 0x8]
	movs r5, 0x8
	ldrsh r1, [r4, r5]
	mov r9, r0
	cmp r1, 0
	beq _081747B8
	subs r0, r2, 0x1
	strh r0, [r4, 0x8]
	movs r5, 0
	adds r7, r3, 0
	movs r0, 0x8
	add r0, r12
	mov r8, r0
_0817476A:
	adds r0, r5, 0x5
	lsls r0, 1
	adds r0, r7
	mov r1, r8
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08174782
	bl sub_818D820
	movs r0, 0xFF
	strh r0, [r4]
_08174782:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _0817476A
	ldr r0, =gTasks
	mov r2, r9
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _081747A4
	subs r0, r2, 0x1
	strh r0, [r1, 0xA]
_081747A4:
	ldr r0, =sub_81743EC
	str r0, [r1]
	b _08174884
	.pool
_081747B8:
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	beq _081747D2
	bl sub_80A369C
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_081747D2:
	ldr r0, =sub_8174898
	str r0, [r4]
	b _08174884
	.pool
_081747E4:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _08174828
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	beq _08174806
	bl sub_80A369C
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_08174806:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8174898
	str r0, [r1]
	b _08174884
	.pool
_08174828:
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08174858
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xC]
	movs r4, 0xC
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08174858
	subs r0, r2, 0x1
	strh r0, [r1, 0xC]
	ldr r0, =sub_81745FC
	str r0, [r1]
	b _08174884
	.pool
_08174858:
	ldrh r1, [r3, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08174884
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r2, r0, r1
	movs r5, 0xC
	ldrsh r1, [r2, r5]
	movs r3, 0x10
	ldrsh r0, [r2, r3]
	subs r0, 0x1
	cmp r1, r0
	bge _08174884
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	ldr r0, =sub_81745FC
	str r0, [r2]
_08174884:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174728

	thumb_func_start sub_8174898
sub_8174898: @ 8174898
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPlttBufferFaded
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 2
	bl CpuSet
	ldr r1, =0x0201c000
	ldr r0, =gUnknown_085E56D4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_80F9BF4
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81748F0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174898

	thumb_func_start sub_81748F0
sub_81748F0: @ 81748F0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_80F9C30
	lsls r0, 24
	cmp r0, 0
	bne _08174988
	movs r5, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
_08174910:
	adds r0, r5, 0x5
	lsls r0, 1
	adds r0, r7
	mov r1, r8
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0xFF
	beq _08174928
	bl sub_818D820
	movs r0, 0xFF
	strh r0, [r4]
_08174928:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08174910
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x3
	bl HideBg
	bl sub_8198314
	bl FreeAllWindowBuffers
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	adds r0, r6, 0
	bl DestroyTask
	ldr r4, =gUnknown_0203BCDC
	ldr r0, [r4]
	cmp r0, 0
	beq _08174974
	bl Free
	movs r0, 0
	str r0, [r4]
_08174974:
	ldr r4, =gUnknown_0203BCD8
	ldr r0, [r4]
	cmp r0, 0
	beq _08174984
	bl Free
	movs r0, 0
	str r0, [r4]
_08174984:
	bl sub_8137C3C
_08174988:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81748F0

	thumb_func_start sub_81749A0
sub_81749A0: @ 81749A0
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_085E8588
	movs r1, 0x8
	movs r2, 0x1
	bl sub_8198180
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gUnknown_085E8BDC
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8174A08
	str r1, [r0]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81749A0

	thumb_func_start sub_8174A08
sub_8174A08: @ 8174A08
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08174A28
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8174898
	str r0, [r1]
_08174A28:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174A08

	thumb_func_start sub_8174A38
sub_8174A38: @ 8174A38
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	ldr r4, =gUnknown_085E8B3E
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174A38

	thumb_func_start sub_8174A88
sub_8174A88: @ 8174A88
	push {r4-r7,lr}
	sub sp, 0x2C
	adds r7, r0, 0
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	ldrh r0, [r7, 0x8]
	ldr r1, =0x000001ff
	ands r1, r0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _08174B30
	ldr r1, =gUnknown_085E8C36
	add r0, sp, 0xC
	bl StringCopy
	adds r6, r0, 0
	ldrh r0, [r7, 0x8]
	lsls r0, 23
	lsrs r0, 23
	bl sub_806E3C0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _08174B04
	adds r0, r4, 0
	movs r1, 0x64
	bl __divsi3
	subs r0, 0x5F
	strb r0, [r6]
	adds r6, 0x1
	adds r0, r4, 0
	movs r1, 0x64
	bl __modsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __divsi3
	subs r0, 0x5F
	strb r0, [r6]
	adds r6, 0x1
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	subs r0, 0x5F
	b _08174B0E
	.pool
_08174B04:
	movs r0, 0xAC
	strb r0, [r6]
	adds r6, 0x1
	strb r0, [r6]
	adds r6, 0x1
_08174B0E:
	strb r0, [r6]
	adds r6, 0x1
	movs r0, 0xFF
	strb r0, [r6]
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x1
	bl box_print
_08174B30:
	adds r1, r7, 0
	adds r1, 0xA
	add r0, sp, 0xC
	movs r2, 0xA
	bl memcpy
	add r1, sp, 0xC
	movs r0, 0xFF
	strb r0, [r1, 0xA]
	ldrh r1, [r7, 0x8]
	ldr r4, =0x000001ff
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _08174B8C
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _08174C82
	.pool
_08174B8C:
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x80
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	add r1, sp, 0xC
	movs r0, 0xBA
	strb r0, [r1]
	mov r0, sp
	adds r0, 0xD
	ldrh r1, [r7, 0x8]
	lsls r1, 23
	lsrs r1, 23
	movs r2, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	adds r6, r0, 0
	ldrh r1, [r7, 0x8]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x20
	beq _08174C0A
	cmp r0, 0x1D
	beq _08174C0A
	lsls r0, r1, 23
	lsrs r0, 23
	ldr r1, [r7, 0x4]
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08174C00
	cmp r0, 0xFE
	beq _08174C04
	b _08174C0A
	.pool
_08174C00:
	movs r0, 0xB5
	b _08174C06
_08174C04:
	movs r0, 0xB6
_08174C06:
	strb r0, [r6]
	adds r6, 0x1
_08174C0A:
	movs r0, 0xFF
	strb r0, [r6]
	ldr r5, =gUnknown_085E5388
	str r5, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x80
	movs r3, 0x1
	bl box_print
	ldr r1, =gUnknown_085E8C3B
	add r0, sp, 0xC
	bl StringCopy
	adds r6, r0, 0
	ldrb r1, [r7, 0x9]
	lsrs r1, 1
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	str r5, [sp]
	str r4, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x24
	movs r3, 0x11
	bl box_print
	ldr r1, =gUnknown_085E8C4D
	add r0, sp, 0xC
	bl StringCopy
	adds r6, r0, 0
	ldrh r1, [r7]
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	str r5, [sp]
	str r4, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x68
	movs r3, 0x11
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08174C82:
	add sp, 0x2C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174A88

	thumb_func_start sub_8174C98
sub_8174C98: @ 8174C98
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r2, =0x0000021d
	movs r0, 0x1
	movs r1, 0
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r0, =gUnknown_085E538C
	mov r8, r0
	str r0, [sp]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_085E8C48
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	ldr r0, =gSaveBlock2Ptr
	mov r10, r0
	ldr r1, [r0]
	movs r0, 0x1
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	mov r1, r8
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	mov r1, r10
	ldr r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	mov r1, r10
	ldr r0, [r1]
	ldrb r4, [r0, 0xA]
	ldrb r0, [r0, 0xB]
	lsls r0, 8
	orrs r4, r0
	mov r0, r8
	str r0, [sp]
	movs r7, 0
	str r7, [sp, 0x4]
	ldr r0, =gUnknown_085E8C4D
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x11
	bl box_print
	add r6, sp, 0xC
	ldr r1, =0x000186a0
	adds r0, r4, 0
	bl __modsi3
	ldr r5, =0x00002710
	adds r1, r5, 0
	bl __divsi3
	subs r0, 0x5F
	strb r0, [r6]
	add r6, sp, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r5, 0xFA
	lsls r5, 2
	adds r1, r5, 0
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r6, 0x1]
	add r6, sp, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r6, 0x2]
	add r5, sp, 0xC
	adds r0, r4, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x3]
	add r5, sp, 0xC
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x4]
	add r1, sp, 0xC
	movs r0, 0xFF
	strb r0, [r1, 0x5]
	movs r0, 0x1
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	mov r1, r8
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	mov r0, r8
	str r0, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_085E84CE
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x21
	bl box_print
	add r5, sp, 0xC
	mov r0, r10
	ldr r4, [r0]
	ldrh r0, [r4, 0xE]
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5]
	add r5, sp, 0xC
	ldrh r0, [r4, 0xE]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x1]
	add r5, sp, 0xC
	ldrh r0, [r4, 0xE]
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x2]
	add r0, sp, 0xC
	ldrb r0, [r0]
	cmp r0, 0xA1
	bne _08174E1E
	add r0, sp, 0xC
	strb r7, [r0]
_08174E1E:
	add r0, sp, 0xC
	ldrb r1, [r0]
	cmp r1, 0
	bne _08174E30
	ldrb r0, [r0, 0x1]
	cmp r0, 0xA1
	bne _08174E30
	add r0, sp, 0xC
	strb r1, [r0, 0x8]
_08174E30:
	add r1, sp, 0xC
	movs r0, 0xF0
	strb r0, [r1, 0x3]
	adds r4, r1, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r5, [r0]
	ldrb r0, [r5, 0x10]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4, 0x4]
	add r4, sp, 0xC
	ldrb r0, [r5, 0x10]
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r4, 0x5]
	add r1, sp, 0xC
	movs r0, 0xFF
	strb r0, [r1, 0x6]
	movs r0, 0x1
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E538C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x21
	bl box_print
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174C98

	thumb_func_start sub_8174EC4
sub_8174EC4: @ 8174EC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x4
	mov r8, r0
	mov r2, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_08174EEA:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _08174EEA
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	bl ResetPaletteFade
	ldr r0, =gUnknown_085E54E8
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174EC4

	thumb_func_start sub_8174F70
sub_8174F70: @ 8174F70
	push {lr}
	bl remove_some_task
	bl ResetTasks
	bl ResetSpriteData
	bl reset_temp_tile_data_buffers
	bl dp13_810BB8C
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gUnknown_085E5394
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E53A4
	bl LoadCompressedObjectPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174F70

	thumb_func_start sub_8174FAC
sub_8174FAC: @ 8174FAC
	push {r4,lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E5374
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203BCDC
	ldr r1, [r4]
	adds r1, 0x12
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001012
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
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
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174FAC

	thumb_func_start sub_8175024
sub_8175024: @ 8175024
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203BCDC
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _08175108
	lsls r0, 2
	ldr r1, =_08175044
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08175044:
	.4byte _08175058
	.4byte _08175070
	.4byte _0817507C
	.4byte _081750D2
	.4byte _081750DC
_08175058:
	ldr r1, =gUnknown_085E5508
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _08175108
	.pool
_08175070:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _08175108
	b _08175112
_0817507C:
	movs r4, 0x20
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x3
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0xE
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _08175108
_081750D2:
	bl sub_81971D0
	bl sub_8197200
	b _08175108
_081750DC:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r0, =gUnknown_0203BCDC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1]
	b _08175114
	.pool
_08175108:
	ldr r0, =gUnknown_0203BCDC
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_08175112:
	movs r0, 0x1
_08175114:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8175024

	thumb_func_start sub_8175120
sub_8175120: @ 8175120
	push {r4,lr}
	adds r2, r0, 0
	ldr r1, [r2, 0x20]
	ldr r0, [r2, 0x30]
	cmp r1, r0
	beq _08175176
	ldrh r3, [r2, 0x20]
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	movs r4, 0x30
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bge _08175140
	adds r0, r3, 0
	adds r0, 0xF
	strh r0, [r2, 0x20]
_08175140:
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, r1
	ble _08175150
	adds r0, r3, 0
	subs r0, 0xF
	strh r0, [r2, 0x20]
_08175150:
	ldrh r3, [r2, 0x22]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r4, 0x32
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bge _08175164
	adds r0, r3, 0
	adds r0, 0xA
	strh r0, [r2, 0x22]
_08175164:
	ldrh r3, [r2, 0x22]
	movs r4, 0x22
	ldrsh r0, [r2, r4]
	cmp r0, r1
	ble _0817519C
	adds r0, r3, 0
	subs r0, 0xA
	strh r0, [r2, 0x22]
	b _0817519C
_08175176:
	ldrh r0, [r2, 0x3C]
	lsls r1, r0, 16
	movs r0, 0xCE
	lsls r0, 17
	cmp r1, r0
	bne _08175190
	lsrs r1, 16
	adds r0, r2, 0
	movs r2, 0x1
	movs r3, 0x3
	bl sub_806ED40
	b _0817519C
_08175190:
	lsrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x3
	bl sub_806ED40
_0817519C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8175120

	thumb_func_start sub_81751A4
sub_81751A4: @ 81751A4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x26]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	cmp r0, 0x78
	ble _081751BA
	adds r0, r5, 0
	bl DestroySprite
	b _081751F2
_081751BA:
	adds r0, r1, 0x1
	ldrh r1, [r5, 0x30]
	adds r0, r1
	strh r0, [r5, 0x26]
	ldrh r4, [r5, 0x2E]
	lsls r4, 24
	lsrs r4, 24
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r0, 0x8
	ldr r1, =gSineTable
	lsls r4, 1
	adds r4, r1
	movs r2, 0
	ldrsh r1, [r4, r2]
	muls r0, r1
	cmp r0, 0
	bge _081751E8
	adds r0, 0xFF
_081751E8:
	asrs r0, 8
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x4
	strh r0, [r5, 0x2E]
_081751F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81751A4

	thumb_func_start sub_81751FC
sub_81751FC: @ 81751FC
	push {r4,lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl Random
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x7
	ands r2, r0
	negs r2, r2
	ldr r0, =gUnknown_085E54D0
	lsls r4, 16
	asrs r4, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r4, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r4, r1, r0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	bl Random
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	beq _08175274
	movs r0, 0
	b _08175276
	.pool
_08175274:
	movs r0, 0x1
_08175276:
	strh r0, [r4, 0x30]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81751FC

	thumb_func_start sub_8175280
sub_8175280: @ 8175280
	push {r4,lr}
	ldr r4, =gUnknown_020375E0
	movs r0, 0xB4
	strh r0, [r4]
	ldr r0, =sub_8175364
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081752AA
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r4]
	strh r1, [r0, 0xA]
	ldr r0, =gUnknown_020375E2
	strh r2, [r0]
_081752AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175280

	thumb_func_start sub_81752C0
sub_81752C0: @ 81752C0
	push {r4,lr}
	ldr r0, =sub_8175364
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _081752D4
	bl DestroyTask
_081752D4:
	bl sub_8152254
	ldr r4, =0x000003e9
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81752C0

	thumb_func_start sub_81752F4
sub_81752F4: @ 81752F4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0xE]
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r0, 0x6E
	ble _08175324
	ldr r2, =gTasks
	movs r0, 0x28
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x1
	strh r1, [r0, 0x26]
	ldrb r0, [r5, 0x16]
	bl sub_81525D0
	b _08175358
	.pool
_08175324:
	adds r0, r1, 0x1
	ldrh r1, [r5, 0x1C]
	adds r0, r1
	strh r0, [r5, 0xE]
	ldrb r4, [r5, 0x1A]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r0, 0x8
	ldr r1, =gSineTable
	lsls r4, 1
	adds r4, r1
	movs r2, 0
	ldrsh r1, [r4, r2]
	muls r0, r1
	cmp r0, 0
	bge _0817534E
	adds r0, 0xFF
_0817534E:
	asrs r0, 8
	strh r0, [r5, 0xC]
	ldrh r0, [r5, 0x1A]
	adds r0, 0x4
	strh r0, [r5, 0x1A]
_08175358:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81752F4

	thumb_func_start sub_8175364
sub_8175364: @ 8175364
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	movs r7, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldrh r0, [r6]
	cmp r0, 0x1
	beq _081753E0
	cmp r0, 0x1
	bgt _08175394
	cmp r0, 0
	beq _0817539C
	b _081754B0
	.pool
_08175394:
	cmp r0, 0xFF
	bne _0817539A
	b _081754A0
_0817539A:
	b _081754B0
_0817539C:
	movs r0, 0x40
	bl sub_81521C0
	cmp r0, 0
	bne _081753B8
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =gUnknown_020375E0
	strh r7, [r0]
	ldr r1, =gUnknown_020375E2
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_081753B8:
	ldr r0, =gUnknown_085E5394
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E53A4
	bl LoadCompressedObjectPalette
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	b _081754B0
	.pool
_081753E0:
	ldrh r0, [r6, 0x2]
	cmp r0, 0
	beq _08175478
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08175478
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r5, r0, 0
	lsls r5, 16
	asrs r5, 16
	bl Random
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x7
	ands r4, r0
	negs r4, r4
	lsls r4, 16
	asrs r4, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_085E53FC
	ldr r2, =0x000003e9
	str r4, [sp]
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	adds r0, r1, 0
	adds r1, r2, 0
	adds r3, r5, 0
	bl sub_81524C4
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xFF
	beq _08175478
	adds r4, r7, 0
	ldr r1, =sub_81752F4
	adds r0, r4, 0
	bl sub_8152438
	bl Random
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	bne _08175468
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8152474
_08175468:
	adds r0, r4, 0
	movs r1, 0x7
	mov r2, r8
	bl sub_8152474
	ldrh r0, [r6, 0x1E]
	adds r0, 0x1
	strh r0, [r6, 0x1E]
_08175478:
	bl sub_81522D4
	ldrh r0, [r6, 0x2]
	cmp r0, 0
	beq _08175494
	subs r0, 0x1
	strh r0, [r6, 0x2]
	b _081754B0
	.pool
_08175494:
	ldrh r0, [r6, 0x1E]
	cmp r0, 0
	bne _081754B0
	movs r0, 0xFF
	strh r0, [r6]
	b _081754B0
_081754A0:
	bl sub_81752C0
	ldr r0, =gUnknown_020375E0
	strh r7, [r0]
	ldr r1, =gUnknown_020375E2
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_081754B0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175364

	.align 2, 0 @ Don't pad with nop.
