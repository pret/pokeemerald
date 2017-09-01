	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80BB2D0
sub_80BB2D0: @ 80BB2D0
	push {r4-r6,lr}
	ldr r0, =gUnknown_02039B50
	movs r2, 0
	strh r2, [r0]
	ldr r1, =gUnknown_02039B52
	movs r0, 0x40
	strb r0, [r1]
	ldr r0, =gUnknown_030060B0
	strb r2, [r0]
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	movs r1, 0
	strb r2, [r0, 0x19]
	ldr r0, [r4]
	strb r2, [r0, 0x18]
	ldr r0, [r4]
	strb r2, [r0, 0x1A]
	ldr r0, [r4]
	strb r2, [r0, 0x1B]
	ldr r0, [r4]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	bl sub_809D3C0
	movs r1, 0
	movs r2, 0
	ldr r3, =gSaveBlock1Ptr
	ldr r6, =0x00000988
	ldr r5, =0x00003b24
_080BB30C:
	ldr r0, [r4]
	adds r0, 0x28
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x5C
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, r6
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, r5
	adds r0, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x33
	bls _080BB30C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB2D0

	thumb_func_start sub_80BB358
sub_80BB358: @ 80BB358
	ldr r1, =gUnknown_02039B50
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02039B52
	movs r0, 0x40
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80BB358

	thumb_func_start sub_80BB370
sub_80BB370: @ 80BB370
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_80BB370

	thumb_func_start sub_80BB384
sub_80BB384: @ 80BB384
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r0, =0x0000ffff
	adds r7, r0, 0
	movs r1, 0x2
	negs r1, r1
	mov r12, r1
	movs r6, 0x3
	negs r6, r6
	ldr r5, =0x00000181
_080BB39A:
	lsls r1, r3, 2
	adds r1, r4, r1
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	ldrb r2, [r1, 0x2]
	mov r0, r12
	ands r0, r2
	ands r0, r6
	strb r0, [r1, 0x2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r5
	bls _080BB39A
	movs r2, 0xC1
	lsls r2, 3
	adds r0, r4, r2
	movs r2, 0
	strh r2, [r0]
	ldr r0, =0x0000060a
	adds r3, r4, r0
	ldrb r1, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	movs r1, 0x3
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldr r1, =0x0000060c
	adds r0, r4, r1
	strh r2, [r0]
	ldr r3, =0x0000060e
	adds r0, r4, r3
	strh r2, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	strh r2, [r0]
	adds r3, 0x4
	adds r0, r4, r3
	strh r2, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	strh r2, [r0]
	adds r3, 0x4
	adds r0, r4, r3
	strh r2, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	strh r2, [r0]
	adds r3, 0x4
	adds r0, r4, r3
	strh r2, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	strh r2, [r0]
	movs r3, 0
	ldr r0, =0x0000061e
	adds r2, r4, r0
	ldr r1, =0x0000ffff
	adds r5, r1, 0
_080BB416:
	lsls r0, r3, 1
	adds r0, r2, r0
	ldrh r1, [r0]
	orrs r1, r5
	strh r1, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _080BB416
	movs r2, 0xC5
	lsls r2, 3
	adds r0, r4, r2
	movs r2, 0
	movs r1, 0
	strh r1, [r0]
	ldr r3, =0x0000062a
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, 0x2
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, 0x1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, 0x1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, 0x1
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, 0xC6
	lsls r2, 3
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, 0x3
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, 0x4
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, 0x4
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, 0x4
	adds r0, r4, r2
	strh r1, [r0]
	movs r3, 0
	ldr r0, =0x0000063a
	adds r1, r4, r0
	movs r2, 0
_080BB47C:
	lsls r0, r3, 1
	adds r0, r1, r0
	strh r2, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _080BB47C
	ldr r1, =0x0000064a
	adds r0, r4, r1
	movs r1, 0
	strb r1, [r0]
	ldr r2, =0x0000064b
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, =0x0000064c
	adds r3, r4, r0
	ldrb r2, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r3]
	ldr r2, =0x0000064d
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, =0x0000064e
	adds r0, r4, r3
	strb r1, [r0]
	adds r2, 0x2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, 0x2
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, 0x3
	adds r0, r4, r2
	strh r1, [r0]
	movs r3, 0
	ldr r0, =0x00000654
	adds r1, r4, r0
	movs r2, 0
_080BB4CE:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x7
	bls _080BB4CE
	movs r3, 0
	ldr r2, =0x0000065c
	adds r1, r4, r2
	movs r2, 0
_080BB4E4:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x7
	bls _080BB4E4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB384

	thumb_func_start sub_80BB534
sub_80BB534: @ 80BB534
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0x1
	beq _080BB5FC
	cmp r0, 0x1
	ble _080BB558
	cmp r0, 0x2
	beq _080BB628
	cmp r0, 0x3
	bne _080BB558
	b _080BB71C
_080BB558:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl sub_80C09B0
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r2, sp, 0x4
	mov r8, r2
	mov r2, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_080BB582:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _080BB582
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r3, r12
	orrs r0, r3
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
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _080BB74C
	.pool
_080BB5FC:
	bl remove_some_task
	bl ResetTasks
	bl ResetSpriteData
	bl ResetPaletteFade
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x8
	strb r0, [r1]
	bl dp13_810BB8C
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _080BB74C
	.pool
_080BB628:
	ldr r4, =gUnknown_02039B4C
	ldr r0, =0x00000664
	bl AllocZeroed
	str r0, [r4]
	bl sub_80BB384
	ldr r0, =sub_80BB78C
	movs r1, 0
	bl CreateTask
	ldr r1, [r4]
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldrb r0, [r0, 0x19]
	ldr r3, =0x00000612
	adds r1, r3
	strh r0, [r1]
	bl sub_809D42C
	adds r1, r0, 0
	cmp r1, 0
	bne _080BB65E
	ldr r0, [r4]
	ldr r2, =0x00000612
	adds r0, r2
	strh r1, [r0]
_080BB65E:
	ldr r1, [r4]
	ldr r0, [r5]
	ldrb r2, [r0, 0x18]
	ldr r3, =0x00000616
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =gUnknown_02039B50
	ldrh r2, [r0]
	subs r3, 0x8
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =gUnknown_02039B52
	ldrb r0, [r0]
	ldr r2, =0x0000062c
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r3, 0x3F
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
	bl sub_809D42C
	cmp r0, 0
	bne _080BB6D0
	movs r0, 0
	bl sub_80C0844
	ldr r1, [r4]
	ldr r2, =0x0000061a
	adds r1, r2
	strh r0, [r1]
	movs r0, 0x1
	bl sub_80C0844
	b _080BB6E4
	.pool
_080BB6D0:
	movs r0, 0
	bl pokedex_count
	ldr r1, [r4]
	ldr r2, =0x0000061a
	adds r1, r2
	strh r0, [r1]
	movs r0, 0x1
	bl pokedex_count
_080BB6E4:
	ldr r1, [r4]
	ldr r3, =0x0000061c
	adds r1, r3
	strh r0, [r1]
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000062d
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080BB74C
	.pool
_080BB71C:
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_80BB370
	bl SetVBlankCallback
	ldr r0, =sub_80BB774
	bl SetMainCallback2
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r3, =0x00000612
	adds r0, r1, r3
	ldrb r0, [r0]
	ldr r2, =0x00000616
	adds r1, r2
	ldrb r1, [r1]
	bl sub_80BC8D4
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	bl m4aMPlayVolumeControl
_080BB74C:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB534

	thumb_func_start sub_80BB774
sub_80BB774: @ 80BB774
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_80BB774

	thumb_func_start sub_80BB78C
sub_80BB78C: @ 80BB78C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r0, =0x0000064c
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	movs r0, 0
	bl sub_80BC514
	lsls r0, 24
	cmp r0, 0
	beq _080BB7BE
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BB7D4
	str r0, [r1]
_080BB7BE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB78C

	thumb_func_start sub_80BB7D4
sub_80BB7D4: @ 80BB7D4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gUnknown_02039B4C
	ldr r0, [r7]
	ldr r4, =0x00000652
	adds r0, r4
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r3, [r7]
	adds r1, r3, r4
	ldrh r0, [r1]
	movs r4, 0
	ldrsh r2, [r1, r4]
	mov r8, r2
	cmp r2, 0
	beq _080BB810
	subs r0, 0x8
	strh r0, [r1]
	b _080BBA06
	.pool
_080BB810:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	mov r9, r0
	ands r0, r1
	cmp r0, 0
	beq _080BB8A4
	ldr r1, =0x0000060e
	adds r0, r3, r1
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3, r0
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BB8A4
	bl sub_80BD8D0
	ldr r4, =gSprites
	ldr r0, [r7]
	ldr r5, =0x00000626
	adds r0, r5
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	mov r0, r9
	lsls r0, r1
	mvns r0, r0
	mov r2, r8
	str r2, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, [r7]
	adds r0, r5
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_80BE470
	str r1, [r0]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BBBF4
	str r1, [r0]
	movs r0, 0x15
	b _080BB976
	.pool
_080BB8A4:
	ldrh r2, [r2, 0x2E]
	movs r0, 0x8
	ands r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080BB8FC
	ldr r3, =gUnknown_02039B4C
	ldr r1, [r3]
	ldr r4, =0x00000652
	adds r0, r1, r4
	movs r2, 0
	strh r2, [r0]
	ldr r0, =0x0000064f
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, 0xCA
	lsls r1, 3
	adds r0, r1
	strh r2, [r0]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BBA78
	str r1, [r0]
	movs r0, 0x5
	bl audio_play
	b _080BBA06
	.pool
_080BB8FC:
	movs r0, 0x4
	ands r0, r2
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080BB9A0
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl sub_80C1258
	ldr r1, =gTasks
	lsls r3, r6, 2
	adds r3, r6
	lsls r3, 3
	adds r3, r1
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	strh r0, [r3, 0x8]
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r4, =0x0000064e
	adds r0, r4
	strb r2, [r0]
	ldr r0, [r1]
	ldr r2, =0x0000062c
	adds r1, r0, r2
	ldrb r2, [r1]
	subs r4, 0x24
	adds r1, r0, r4
	strh r2, [r1]
	ldr r2, =0x0000060e
	adds r1, r0, r2
	ldrh r2, [r1]
	subs r4, 0x1A
	adds r1, r0, r4
	strh r2, [r1]
	ldr r2, =0x00000612
	adds r1, r0, r2
	ldrh r2, [r1]
	adds r4, 0x4
	adds r1, r0, r4
	strh r2, [r1]
	ldr r2, =0x00000616
	adds r1, r0, r2
	ldrh r1, [r1]
	adds r4, 0x4
	adds r0, r4
	strh r1, [r0]
	ldr r0, =sub_80BBD1C
	str r0, [r3]
	movs r0, 0x2
_080BB976:
	bl audio_play
	bl sub_80BC890
	b _080BBA06
	.pool
_080BB9A0:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _080BB9D8
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BBDE8
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
	b _080BBA06
	.pool
_080BB9D8:
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r4, =0x0000060e
	adds r0, r4
	ldrh r0, [r0]
	movs r1, 0xE
	bl sub_80BD69C
	ldr r1, [r5]
	adds r4, r1, r4
	strh r0, [r4]
	ldr r0, =0x0000062e
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080BBA06
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BBA28
	str r0, [r1]
_080BBA06:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB7D4

	thumb_func_start sub_80BBA28
sub_80BBA28: @ 80BBA28
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r2, [r0]
	ldr r1, =0x0000062f
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r3, =0x00000634
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, 0x2
	adds r2, r3
	ldrb r2, [r2]
	bl sub_80BD404
	lsls r0, 24
	cmp r0, 0
	beq _080BBA5C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BB7D4
	str r0, [r1]
_080BBA5C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBA28

	thumb_func_start sub_80BBA78
sub_80BBA78: @ 80BBA78
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r6, =gUnknown_02039B4C
	ldr r0, [r6]
	ldr r4, =0x00000652
	adds r0, r4
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r3, [r6]
	adds r1, r3, r4
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0x50
	beq _080BBAB0
	adds r0, r2, 0
	adds r0, 0x8
	strh r0, [r1]
	b _080BBBE8
	.pool
_080BBAB0:
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080BBB58
	movs r2, 0xCA
	lsls r2, 3
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080BBADC
	cmp r0, 0x1
	ble _080BBB20
	cmp r0, 0x2
	beq _080BBAF4
	cmp r0, 0x3
	beq _080BBB34
	b _080BBB20
	.pool
_080BBADC:
	ldr r4, =0x0000060e
	adds r1, r3, r4
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x0000062c
	adds r1, r3, r0
	movs r0, 0x40
	b _080BBB0C
	.pool
_080BBAF4:
	ldr r1, =0x0000060c
	adds r2, r3, r1
	ldrh r0, [r2]
	subs r0, 0x1
	ldr r4, =0x0000060e
	adds r1, r3, r4
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, 4
	adds r0, 0x30
	ldr r2, =0x0000062c
	adds r1, r3, r2
_080BBB0C:
	strb r0, [r1]
	bl sub_80BDA40
	ldr r0, [r6]
	adds r0, r4
	ldrh r0, [r0]
	movs r1, 0xE
	bl sub_80BD2B4
	ldrh r1, [r5, 0x2E]
_080BBB20:
	movs r0, 0x8
	orrs r0, r1
	strh r0, [r5, 0x2E]
	b _080BBB58
	.pool
_080BBB34:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BBDE8
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
_080BBB58:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0xA
	ands r0, r1
	cmp r0, 0
	beq _080BBB98
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r3, =0x0000064f
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BB7D4
	str r1, [r0]
	b _080BBBB6
	.pool
_080BBB98:
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080BBBC4
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	movs r4, 0xCA
	lsls r4, 3
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, 0
	beq _080BBBC4
	subs r0, 0x1
	strh r0, [r1]
_080BBBB6:
	movs r0, 0x5
	bl audio_play
	b _080BBBE8
	.pool
_080BBBC4:
	ldrh r1, [r2, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BBBE8
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	movs r2, 0xCA
	lsls r2, 3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0x2
	bhi _080BBBE8
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x5
	bl audio_play
_080BBBE8:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBA78

	thumb_func_start sub_80BBBF4
sub_80BBBF4: @ 80BBBF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gSprites
	ldr r5, =gUnknown_02039B4C
	ldr r3, [r5]
	ldr r6, =0x00000626
	adds r0, r3, r6
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	movs r2, 0x20
	ldrsh r0, [r1, r2]
	cmp r0, 0x30
	bne _080BBC52
	movs r2, 0x22
	ldrsh r0, [r1, r2]
	cmp r0, 0x38
	bne _080BBC52
	ldr r1, =0x0000064a
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, =0x0000064b
	adds r0, r3, r2
	strb r1, [r0]
	ldr r1, [r5]
	subs r2, 0x3D
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1, r0
	adds r1, r6
	ldrb r1, [r1]
	bl sub_80BE91C
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x8]
	ldr r0, =sub_80BBC74
	str r0, [r1]
_080BBC52:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBBF4

	thumb_func_start sub_80BBC74
sub_80BBC74: @ 80BBC74
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080BBCE0
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r1, =0x0000064a
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080BBCFC
	ldrb r0, [r4, 0x8]
	bl sub_80BE9C4
	lsls r0, 24
	cmp r0, 0
	bne _080BBCFC
	bl sub_80BD930
	lsls r0, 24
	cmp r0, 0
	beq _080BBCFC
	ldr r0, [r5]
	ldr r2, =0x0000060e
	adds r1, r0, r2
	ldrh r1, [r1]
	lsls r1, 2
	adds r0, r1
	ldrb r1, [r4, 0x8]
	bl sub_80BE9F8
	b _080BBCFC
	.pool
_080BBCE0:
	ldr r2, =gUnknown_02039B50
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r3, =0x0000060e
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r2, =gUnknown_02039B52
	ldr r0, =0x0000062c
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	ldr r0, =sub_80BB78C
	str r0, [r4]
_080BBCFC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBC74

	thumb_func_start sub_80BBD1C
sub_80BBD1C: @ 80BBD1C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	movs r0, 0x8
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r4, [r0, 0x4]
	cmp r4, 0
	bne _080BBDCA
	bl sub_80BDA40
	ldr r5, =gUnknown_02039B4C
	ldr r2, [r5]
	ldr r1, =0x0000064e
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BBD7C
	ldr r3, =0x0000060e
	adds r0, r2, r3
	strh r4, [r0]
	ldr r0, =0x0000062c
	adds r1, r2, r0
	movs r0, 0x40
	strb r0, [r1]
	ldr r0, =sub_80BBE70
	b _080BBDC8
	.pool
_080BBD7C:
	ldr r1, =0x0000062a
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r3, =0x0000062c
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, [r5]
	movs r2, 0xC2
	lsls r2, 3
	adds r0, r1, r2
	ldrh r2, [r0]
	subs r3, 0x1E
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, =0x00000614
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r3, 0x4
	adds r1, r3
	strh r0, [r1]
	bl sub_809D42C
	adds r1, r0, 0
	cmp r1, 0
	bne _080BBDB6
	ldr r0, [r5]
	ldr r2, =0x00000612
	adds r0, r2
	strh r1, [r0]
_080BBDB6:
	ldr r0, [r5]
	movs r3, 0xC3
	lsls r3, 3
	adds r1, r0, r3
	ldrh r1, [r1]
	ldr r2, =0x00000616
	adds r0, r2
	strh r1, [r0]
	ldr r0, =sub_80BB78C
_080BBDC8:
	str r0, [r6]
_080BBDCA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBD1C

	thumb_func_start sub_80BBDE8
sub_80BBDE8: @ 80BBDE8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BBE4A
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r5, =gUnknown_02039B4C
	ldr r1, [r5]
	ldr r2, =0x00000612
	adds r1, r2
	ldrh r1, [r1]
	strb r1, [r0, 0x19]
	bl sub_809D42C
	adds r1, r0, 0
	cmp r1, 0
	bne _080BBE18
	ldr r0, [r4]
	strb r1, [r0, 0x19]
_080BBE18:
	ldr r1, [r4]
	ldr r0, [r5]
	ldr r2, =0x00000616
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x18]
	bl sub_80BDA40
	bl sub_80BC890
	adds r0, r6, 0
	bl DestroyTask
	ldr r0, =sub_8086194
	bl SetMainCallback2
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	ldr r0, [r5]
	bl Free
_080BBE4A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBDE8

	thumb_func_start sub_80BBE70
sub_80BBE70: @ 80BBE70
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r0, =0x0000064c
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	movs r0, 0x3
	bl sub_80BC514
	lsls r0, 24
	cmp r0, 0
	beq _080BBEA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BBEB8
	str r0, [r1]
_080BBEA0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBE70

	thumb_func_start sub_80BBEB8
sub_80BBEB8: @ 80BBEB8
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r4, =0x00000652
	adds r0, r4
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r3, [r5]
	adds r1, r3, r4
	ldrh r0, [r1]
	movs r2, 0
	ldrsh r4, [r1, r2]
	cmp r4, 0
	beq _080BBEEC
	subs r0, 0x8
	strh r0, [r1]
	b _080BC08A
	.pool
_080BBEEC:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r7, 0x1
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080BBF70
	ldr r1, =0x0000060e
	adds r0, r3, r1
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3, r0
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BBF70
	bl sub_80BD8D0
	ldr r3, =gSprites
	ldr r0, [r5]
	ldr r2, =0x00000626
	adds r0, r2
	ldrh r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r0, r2, r3
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	adds r0, r7, 0
	lsls r0, r1
	adds r3, 0x1C
	adds r2, r3
	ldr r1, =sub_80BE470
	str r1, [r2]
	mvns r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BC2D4
	str r1, [r0]
	movs r0, 0x15
	b _080BC00A
	.pool
_080BBF70:
	ldrh r2, [r2, 0x2E]
	movs r0, 0x8
	ands r0, r2
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080BBFC8
	ldr r3, =gUnknown_02039B4C
	ldr r1, [r3]
	ldr r2, =0x00000652
	adds r0, r1, r2
	movs r2, 0
	strh r2, [r0]
	ldr r0, =0x0000064f
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, 0xCA
	lsls r1, 3
	adds r0, r1
	strh r2, [r0]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BC0F8
	str r1, [r0]
	movs r0, 0x5
	bl audio_play
	b _080BC08A
	.pool
_080BBFC8:
	movs r0, 0x4
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _080BC024
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl sub_80C1258
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	strh r0, [r1, 0x8]
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r3, =0x0000064e
	adds r0, r3
	strb r2, [r0]
	ldr r0, =sub_80BBD1C
	str r0, [r1]
	movs r0, 0x2
_080BC00A:
	bl audio_play
	bl sub_80BC890
	b _080BC08A
	.pool
_080BC024:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _080BC05C
	movs r0, 0x1
	negs r0, r0
	str r3, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BC3DC
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
	b _080BC08A
	.pool
_080BC05C:
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r4, =0x0000060e
	adds r0, r4
	ldrh r0, [r0]
	movs r1, 0xE
	bl sub_80BD69C
	ldr r1, [r5]
	adds r4, r1, r4
	strh r0, [r4]
	ldr r0, =0x0000062e
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080BC08A
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BC0A8
	str r0, [r1]
_080BC08A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BBEB8

	thumb_func_start sub_80BC0A8
sub_80BC0A8: @ 80BC0A8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r2, [r0]
	ldr r1, =0x0000062f
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r3, =0x00000634
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, 0x2
	adds r2, r3
	ldrb r2, [r2]
	bl sub_80BD404
	lsls r0, 24
	cmp r0, 0
	beq _080BC0DC
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BBEB8
	str r0, [r1]
_080BC0DC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC0A8

	thumb_func_start sub_80BC0F8
sub_80BC0F8: @ 80BC0F8
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r4, =0x00000652
	adds r0, r4
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r5, [r5]
	adds r1, r5, r4
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x60
	beq _080BC130
	adds r0, r2, 0
	adds r0, 0x8
	strh r0, [r1]
	b _080BC2C8
	.pool
_080BC130:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080BC13E
	b _080BC238
_080BC13E:
	movs r1, 0xCA
	lsls r1, 3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080BC1C2
	lsls r0, 2
	ldr r1, =_080BC15C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BC15C:
	.4byte _080BC1C2
	.4byte _080BC170
	.4byte _080BC194
	.4byte _080BC1E4
	.4byte _080BC214
_080BC170:
	ldr r5, =gUnknown_02039B4C
	ldr r1, [r5]
	ldr r4, =0x0000060e
	adds r2, r1, r4
	movs r0, 0
	strh r0, [r2]
	ldr r2, =0x0000062c
	adds r1, r2
	movs r0, 0x40
	strb r0, [r1]
	b _080BC1B2
	.pool
_080BC194:
	ldr r5, =gUnknown_02039B4C
	ldr r2, [r5]
	ldr r0, =0x0000060c
	adds r3, r2, r0
	ldrh r0, [r3]
	subs r0, 0x1
	ldr r4, =0x0000060e
	adds r1, r2, r4
	strh r0, [r1]
	ldrh r0, [r3]
	lsls r0, 4
	adds r0, 0x30
	ldr r1, =0x0000062c
	adds r2, r1
	strb r0, [r2]
_080BC1B2:
	bl sub_80BDA40
	ldr r0, [r5]
	adds r0, r4
	ldrh r0, [r0]
	movs r1, 0xE
	bl sub_80BD2B4
_080BC1C2:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x8
	orrs r0, r1
	strh r0, [r2, 0x2E]
	b _080BC238
	.pool
_080BC1E4:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BC3DC
	str r1, [r0]
	movs r0, 0x34
	bl audio_play
	b _080BC238
	.pool
_080BC214:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BC47C
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
_080BC238:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0xA
	ands r0, r1
	cmp r0, 0
	beq _080BC278
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r2, =0x0000064f
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BBEB8
	str r1, [r0]
	b _080BC296
	.pool
_080BC278:
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080BC2A4
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	movs r3, 0xCA
	lsls r3, 3
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, 0
	beq _080BC2A4
	subs r0, 0x1
	strh r0, [r1]
_080BC296:
	movs r0, 0x5
	bl audio_play
	b _080BC2C8
	.pool
_080BC2A4:
	ldrh r1, [r2, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BC2C8
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	movs r2, 0xCA
	lsls r2, 3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0x3
	bhi _080BC2C8
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x5
	bl audio_play
_080BC2C8:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC0F8

	thumb_func_start sub_80BC2D4
sub_80BC2D4: @ 80BC2D4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSprites
	ldr r5, =gUnknown_02039B4C
	ldr r3, [r5]
	ldr r4, =0x00000626
	adds r0, r3, r4
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	movs r2, 0x20
	ldrsh r0, [r1, r2]
	cmp r0, 0x30
	bne _080BC33A
	movs r2, 0x22
	ldrsh r0, [r1, r2]
	cmp r0, 0x38
	bne _080BC33A
	ldr r1, =0x0000064a
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, =0x0000064b
	adds r0, r3, r2
	strb r1, [r0]
	ldr r1, [r5]
	subs r2, 0x3D
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1, r0
	adds r1, r4
	ldrb r1, [r1]
	bl sub_80BE91C
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x8]
	ldr r0, [r5]
	adds r0, r4
	ldr r2, =0x0000ffff
	strh r2, [r0]
	ldr r0, =sub_80BC360
	str r0, [r1]
_080BC33A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC2D4

	thumb_func_start sub_80BC360
sub_80BC360: @ 80BC360
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080BC3CC
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r1, =0x0000064a
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080BC3D0
	ldrb r0, [r4, 0x8]
	bl sub_80BE9C4
	lsls r0, 24
	cmp r0, 0
	bne _080BC3D0
	bl sub_80BD930
	lsls r0, 24
	cmp r0, 0
	beq _080BC3D0
	ldr r0, [r5]
	ldr r2, =0x0000060e
	adds r1, r0, r2
	ldrh r1, [r1]
	lsls r1, 2
	adds r0, r1
	ldrb r1, [r4, 0x8]
	bl sub_80BE9F8
	b _080BC3D0
	.pool
_080BC3CC:
	ldr r0, =sub_80BBE70
	str r0, [r4]
_080BC3D0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC360

	thumb_func_start sub_80BC3DC
sub_80BC3DC: @ 80BC3DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BC450
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r2, =0x0000062a
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, =0x0000062c
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r4]
	subs r2, 0x1A
	adds r0, r1, r2
	ldrh r2, [r0]
	subs r3, 0x1E
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, =0x00000614
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r3, 0x4
	adds r1, r3
	strh r0, [r1]
	bl sub_809D42C
	adds r1, r0, 0
	cmp r1, 0
	bne _080BC42A
	ldr r0, [r4]
	ldr r2, =0x00000612
	adds r0, r2
	strh r1, [r0]
_080BC42A:
	ldr r0, [r4]
	movs r3, 0xC3
	lsls r3, 3
	adds r1, r0, r3
	ldrh r1, [r1]
	ldr r2, =0x00000616
	adds r0, r2
	strh r1, [r0]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BB78C
	str r1, [r0]
	bl sub_80BDA40
	bl sub_80BC890
_080BC450:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC3DC

	thumb_func_start sub_80BC47C
sub_80BC47C: @ 80BC47C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BC4E8
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r2, =0x0000062a
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, =0x0000062c
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r4]
	subs r2, 0x1A
	adds r0, r1, r2
	ldrh r2, [r0]
	subs r3, 0x1E
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, =0x00000614
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r3, 0x4
	adds r1, r3
	strh r0, [r1]
	bl sub_809D42C
	adds r1, r0, 0
	cmp r1, 0
	bne _080BC4CA
	ldr r0, [r4]
	ldr r2, =0x00000612
	adds r0, r2
	strh r1, [r0]
_080BC4CA:
	ldr r0, [r4]
	movs r3, 0xC3
	lsls r3, 3
	adds r1, r0, r3
	ldrh r1, [r1]
	ldr r2, =0x00000616
	adds r0, r2
	strh r1, [r0]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BBDE8
	str r1, [r0]
_080BC4E8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC47C

	thumb_func_start sub_80BC514
sub_80BC514: @ 80BC514
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x6
	bhi _080BC55C
	lsls r0, 2
	ldr r1, =_080BC540
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BC540:
	.4byte _080BC55C
	.4byte _080BC6CC
	.4byte _080BC6FC
	.4byte _080BC704
	.4byte _080BC768
	.4byte _080BC790
	.4byte _080BC818
_080BC55C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _080BC56E
	b _080BC838
_080BC56E:
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r1, =0x0000064a
	adds r0, r1
	strb r5, [r0]
	movs r0, 0
	bl sub_80C09B0
	ldr r0, [r4]
	ldr r2, =0x0000062d
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0855D298
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DC1934
	movs r2, 0x80
	lsls r2, 6
	str r6, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08DC2C5C
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gUnknown_08DC2DAC
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	cmp r5, 0
	bne _080BC640
	ldr r1, =gUnknown_08DC2A08
	movs r3, 0xA0
	lsls r3, 2
	movs r0, 0
	movs r2, 0
	bl CopyToBgTilemapBuffer
	b _080BC64E
	.pool
_080BC640:
	ldr r1, =gUnknown_08DC2B1C
	movs r3, 0xA0
	lsls r3, 2
	movs r0, 0
	movs r2, 0
	bl CopyToBgTilemapBuffer
_080BC64E:
	bl ResetPaletteFade
	cmp r5, 0
	bne _080BC674
	ldr r3, =gUnknown_02039B4C
	ldr r1, [r3]
	ldr r0, =0x0000064c
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	b _080BC682
	.pool
_080BC674:
	ldr r3, =gUnknown_02039B4C
	ldr r1, [r3]
	ldr r2, =0x0000064c
	adds r1, r2
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
_080BC682:
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, =0x0000064c
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	bl sub_80BC844
	ldr r0, =gUnknown_0855D2A8
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _080BC838
	.pool
_080BC6CC:
	bl ResetSpriteData
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gUnknown_0855D26C
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0855D27C
	bl LoadTaggedObjectPalettes
	adds r0, r5, 0
	bl sub_80BDB7C
	b _080BC7F8
	.pool
_080BC6FC:
	movs r2, 0x87
	lsls r2, 3
	adds r1, r3, r2
	b _080BC800
_080BC704:
	cmp r5, 0
	bne _080BC71C
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r2, =0x00000612
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x4
	adds r1, r2
	ldrb r1, [r1]
	bl sub_80BC8D4
_080BC71C:
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r1, =0x0000060e
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0xE
	bl sub_80BD2B4
	ldr r0, [r4]
	ldr r2, =0x0000064f
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, 0x3
	adds r0, r2
	strh r1, [r0]
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080BC7F8
	.pool
_080BC768:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_80BB370
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _080BC800
	.pool
_080BC790:
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00001d3f
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
	ldr r1, =0x00009040
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_080BC7F8:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_080BC800:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080BC838
	.pool
_080BC818:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080BC838
	movs r1, 0x87
	lsls r1, 3
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, 0x1
	b _080BC83A
	.pool
_080BC838:
	movs r0, 0
_080BC83A:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80BC514

	thumb_func_start sub_80BC844
sub_80BC844: @ 80BC844
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080BC858
	ldr r0, =gUnknown_08DC17B6
	b _080BC862
	.pool
_080BC858:
	bl sub_809D42C
	cmp r0, 0
	bne _080BC870
	ldr r0, =gUnknown_08DC16F6
_080BC862:
	movs r1, 0x1
	movs r2, 0xBE
	bl LoadPalette
	b _080BC87A
	.pool
_080BC870:
	ldr r0, =gUnknown_08DC1876
	movs r1, 0x1
	movs r2, 0xBE
	bl LoadPalette
_080BC87A:
	bl sub_8098C64
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC844

	thumb_func_start sub_80BC890
sub_80BC890: @ 80BC890
	push {lr}
	bl FreeAllWindowBuffers
	movs r0, 0
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BC8A4
	bl Free
_080BC8A4:
	movs r0, 0x1
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BC8B2
	bl Free
_080BC8B2:
	movs r0, 0x2
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BC8C0
	bl Free
_080BC8C0:
	movs r0, 0x3
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BC8CE
	bl Free
_080BC8CE:
	pop {r0}
	bx r0
	thumb_func_end sub_80BC890

	thumb_func_start sub_80BC8D4
sub_80BC8D4: @ 80BC8D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000060c
	adds r0, r1
	movs r5, 0
	strh r5, [r0]
	cmp r4, 0
	beq _080BC8FC
	cmp r4, 0x1
	beq _080BC910
_080BC8FC:
	mov r1, sp
	movs r0, 0xCA
	strh r0, [r1]
	movs r0, 0x1
	strh r0, [r1, 0x2]
	b _080BC92C
	.pool
_080BC910:
	bl sub_809D42C
	cmp r0, 0
	beq _080BC924
	mov r0, sp
	movs r1, 0xC1
	lsls r1, 1
	strh r1, [r0]
	strh r5, [r0, 0x2]
	b _080BC92C
_080BC924:
	mov r0, sp
	movs r1, 0xCA
	strh r1, [r0]
	strh r4, [r0, 0x2]
_080BC92C:
	cmp r6, 0x5
	bls _080BC932
	b _080BCDB4
_080BC932:
	lsls r0, r6, 2
	ldr r1, =_080BC940
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BC940:
	.4byte _080BC958
	.4byte _080BCACC
	.4byte _080BCB78
	.4byte _080BCC08
	.4byte _080BCCA0
	.4byte _080BCD30
_080BC958:
	mov r0, sp
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _080BCA00
	movs r4, 0
	mov r0, sp
	ldrh r0, [r0]
	cmp r4, r0
	blt _080BC96C
	b _080BCDB4
_080BC96C:
	mov r5, sp
	ldr r2, =gUnknown_02039B4C
	mov r8, r2
	movs r3, 0x1
	mov r9, r3
_080BC976:
	lsls r4, 16
	asrs r4, 16
	adds r7, r4, 0x1
	mov r10, r7
	lsls r0, r7, 16
	lsrs r6, r0, 16
	adds r0, r6, 0
	bl HoennToNationalOrder
	strh r0, [r5, 0x4]
	mov r2, r8
	ldr r1, [r2]
	lsls r4, 2
	adds r1, r4
	strh r0, [r1]
	ldrh r0, [r5, 0x4]
	movs r1, 0
	bl pokedex_flag_operation
	mov r3, r8
	ldr r2, [r3]
	adds r2, r4
	mov r3, r9
	ands r3, r0
	ldrb r0, [r2, 0x2]
	movs r7, 0x2
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x2]
	ldrh r0, [r5, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	mov r1, r8
	ldr r3, [r1]
	adds r3, r4
	mov r2, r9
	ands r2, r0
	lsls r2, 1
	ldrb r0, [r3, 0x2]
	subs r7, 0x1
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x2]
	mov r0, r8
	ldr r1, [r0]
	adds r4, r1, r4
	ldrb r0, [r4, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BC9EA
	ldr r2, =0x0000060c
	adds r0, r1, r2
	mov r3, r10
	strh r3, [r0]
_080BC9EA:
	adds r4, r6, 0
	lsls r0, r4, 16
	asrs r0, 16
	ldrh r7, [r5]
	cmp r0, r7
	blt _080BC976
	b _080BCDB4
	.pool
_080BCA00:
	movs r4, 0
	movs r5, 0
	mov r10, r5
	mov r0, sp
	ldrh r0, [r0]
	cmp r4, r0
	blt _080BCA10
	b _080BCDB4
_080BCA10:
	mov r6, sp
	ldr r0, =gUnknown_02039B4C
	mov r8, r0
	movs r1, 0x1
	mov r9, r1
_080BCA1A:
	lsls r4, 16
	asrs r0, r4, 16
	adds r0, 0x1
	strh r0, [r6, 0x4]
	ldrh r0, [r6, 0x4]
	movs r1, 0
	bl pokedex_flag_operation
	lsls r0, 24
	adds r7, r4, 0
	cmp r0, 0
	beq _080BCA36
	movs r2, 0x1
	mov r10, r2
_080BCA36:
	mov r3, r10
	cmp r3, 0
	beq _080BCAB2
	mov r4, r8
	ldr r1, [r4]
	lsls r0, r5, 16
	asrs r5, r0, 16
	lsls r4, r5, 2
	adds r1, r4
	ldrh r0, [r6, 0x4]
	strh r0, [r1]
	ldrh r0, [r6, 0x4]
	movs r1, 0
	bl pokedex_flag_operation
	mov r1, r8
	ldr r2, [r1]
	adds r2, r4
	mov r3, r9
	ands r3, r0
	mov r12, r3
	ldrb r0, [r2, 0x2]
	movs r3, 0x2
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	mov r1, r12
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldrh r0, [r6, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	mov r2, r8
	ldr r3, [r2]
	adds r3, r4
	mov r2, r9
	ands r2, r0
	lsls r2, 1
	mov r12, r2
	ldrb r0, [r3, 0x2]
	movs r2, 0x3
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	mov r1, r12
	orrs r0, r1
	strb r0, [r3, 0x2]
	mov r3, r8
	ldr r2, [r3]
	adds r4, r2, r4
	ldrb r0, [r4, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BCAAC
	adds r1, r5, 0x1
	ldr r4, =0x0000060c
	adds r0, r2, r4
	strh r1, [r0]
_080BCAAC:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080BCAB2:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r7, r1
	lsrs r4, r0, 16
	asrs r0, 16
	ldrh r2, [r6]
	cmp r0, r2
	blt _080BCA1A
	b _080BCDB4
	.pool
_080BCACC:
	movs r4, 0
	mov r5, sp
	ldr r3, =gUnknown_02039B4C
	mov r8, r3
	ldr r6, =0x0000060c
	movs r7, 0x1
	mov r9, r7
_080BCADA:
	ldr r1, =gUnknown_0855C6A4
	lsls r4, 16
	asrs r0, r4, 15
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r0, 16
	adds r7, r4, 0
	ldrh r1, [r5]
	cmp r0, r1
	bhi _080BCB58
	ldrh r0, [r5, 0x4]
	movs r1, 0
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080BCB58
	mov r3, r8
	ldr r2, [r3]
	adds r3, r2, r6
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r2, r0
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	mov r4, r9
	orrs r0, r4
	strb r0, [r2, 0x2]
	ldrh r0, [r5, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	mov r1, r8
	ldr r3, [r1]
	adds r1, r3, r6
	ldrh r1, [r1]
	lsls r1, 2
	adds r3, r1
	mov r2, r9
	ands r2, r0
	lsls r2, 1
	ldrb r0, [r3, 0x2]
	movs r4, 0x3
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x2]
	mov r0, r8
	ldr r1, [r0]
	adds r1, r6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080BCB58:
	movs r2, 0x80
	lsls r2, 9
	adds r1, r7, r2
	lsrs r4, r1, 16
	movs r0, 0xCD
	lsls r0, 17
	cmp r1, r0
	ble _080BCADA
	b _080BCDB4
	.pool
_080BCB78:
	ldr r4, =0x00000181
	lsls r0, r4, 16
	mov r5, sp
	ldr r7, =gUnknown_02039B4C
	ldr r6, =0x0000060c
_080BCB82:
	ldr r1, =gUnknown_0855C9DA
	asrs r0, 15
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r0, 16
	ldrh r3, [r5]
	cmp r0, r3
	bhi _080BCBE2
	ldrh r0, [r5, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080BCBE2
	ldr r2, [r7]
	adds r3, r2, r6
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r2, r0
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r2, [r7]
	adds r0, r2, r6
	ldrh r0, [r0]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r1, [r7]
	adds r1, r6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080BCBE2:
	lsls r0, r4, 16
	ldr r4, =0xffff0000
	adds r0, r4
	lsrs r4, r0, 16
	lsls r0, r4, 16
	cmp r0, 0
	bge _080BCB82
	b _080BCDB4
	.pool
_080BCC08:
	movs r4, 0
	mov r5, sp
	ldr r7, =gUnknown_02039B4C
	mov r8, r7
	ldr r6, =0x0000060c
	ldr r0, =0x00000181
	mov r9, r0
_080BCC16:
	ldr r1, =gUnknown_0855C9DA
	lsls r4, 16
	asrs r0, r4, 15
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r0, 16
	adds r7, r4, 0
	ldrh r1, [r5]
	cmp r0, r1
	bhi _080BCC7E
	ldrh r0, [r5, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080BCC7E
	mov r3, r8
	ldr r2, [r3]
	adds r3, r2, r6
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r2, r0
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	mov r4, r8
	ldr r2, [r4]
	adds r0, r2, r6
	ldrh r0, [r0]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r1, [r4]
	adds r1, r6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080BCC7E:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r7, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, r9
	ble _080BCC16
	b _080BCDB4
	.pool
_080BCCA0:
	ldr r4, =0x00000181
	lsls r0, r4, 16
	mov r5, sp
	ldr r7, =gUnknown_02039B4C
	ldr r6, =0x0000060c
_080BCCAA:
	ldr r1, =gUnknown_0855CCDE
	asrs r0, 15
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r5]
	cmp r0, r2
	bhi _080BCD0A
	ldrh r0, [r5, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080BCD0A
	ldr r2, [r7]
	adds r3, r2, r6
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r2, r0
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r2, [r7]
	adds r0, r2, r6
	ldrh r0, [r0]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r1, [r7]
	adds r1, r6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080BCD0A:
	lsls r0, r4, 16
	ldr r3, =0xffff0000
	adds r0, r3
	lsrs r4, r0, 16
	lsls r0, r4, 16
	cmp r0, 0
	bge _080BCCAA
	b _080BCDB4
	.pool
_080BCD30:
	movs r4, 0
	mov r5, sp
	ldr r7, =gUnknown_02039B4C
	mov r8, r7
	ldr r6, =0x0000060c
	ldr r0, =0x00000181
	mov r9, r0
_080BCD3E:
	ldr r1, =gUnknown_0855CCDE
	lsls r4, 16
	asrs r0, r4, 15
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r0, 16
	adds r7, r4, 0
	ldrh r1, [r5]
	cmp r0, r1
	bhi _080BCDA6
	ldrh r0, [r5, 0x4]
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080BCDA6
	mov r3, r8
	ldr r2, [r3]
	adds r3, r2, r6
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r2, r0
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	mov r4, r8
	ldr r2, [r4]
	adds r0, r2, r6
	ldrh r0, [r0]
	lsls r0, 2
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r1, [r4]
	adds r1, r6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080BCDA6:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r7, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, r9
	ble _080BCD3E
_080BCDB4:
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r4, [r0]
	lsls r3, r4, 16
	asrs r0, r3, 16
	ldr r2, =0x00000181
	cmp r0, r2
	bgt _080BCE08
	adds r5, r1, 0
	movs r4, 0x2
	negs r4, r4
	mov r9, r4
	movs r7, 0x3
	negs r7, r7
	mov r8, r7
	adds r7, r2, 0
	ldr r0, =0x0000ffff
	adds r6, r0, 0
_080BCDDC:
	ldr r1, [r5]
	asrs r3, 16
	lsls r4, r3, 2
	adds r1, r4
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
	ldrb r2, [r1, 0x2]
	mov r0, r9
	ands r0, r2
	strb r0, [r1, 0x2]
	ldr r1, [r5]
	adds r1, r4
	ldrb r2, [r1, 0x2]
	mov r0, r8
	ands r0, r2
	strb r0, [r1, 0x2]
	adds r3, 0x1
	lsls r3, 16
	asrs r0, r3, 16
	cmp r0, r7
	ble _080BCDDC
_080BCE08:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BC8D4

	thumb_func_start sub_80BCE2C
sub_80BCE2C: @ 80BCE2C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x18
	mov r8, r3
	ldr r3, [sp, 0x2C]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r3, 24
	add r4, sp, 0x14
	movs r6, 0
	strb r6, [r4]
	adds r5, r4, 0
	movs r4, 0xF
	strb r4, [r5, 0x1]
	movs r4, 0x3
	strb r4, [r5, 0x2]
	mov r4, r8
	lsls r4, 27
	lsrs r4, 24
	mov r8, r4
	lsrs r3, 21
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r6, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0xC]
	str r2, [sp, 0x10]
	mov r2, r8
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80BCE2C

	thumb_func_start sub_80BCE84
sub_80BCE84: @ 80BCE84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r7, r2, 16
	cmp r0, 0x1
	beq _080BCF7C
	cmp r0, 0x1
	ble _080BCEA8
	cmp r0, 0x2
	bne _080BCEA8
	b _080BD074
_080BCEA8:
	subs r0, r1, 0x5
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0
	mov r9, r0
_080BCEB2:
	lsls r0, r1, 16
	lsrs r5, r0, 16
	mov r10, r0
	ldr r1, =0x00000181
	cmp r5, r1
	bhi _080BCED2
	ldr r2, =gUnknown_02039B4C
	mov r8, r2
	ldr r0, [r2]
	mov r3, r10
	asrs r6, r3, 14
	adds r0, r6
	ldrh r0, [r0]
	ldr r1, =0x0000ffff
	cmp r0, r1
	bne _080BCEF0
_080BCED2:
	mov r2, r9
	lsls r1, r2, 25
	lsrs r1, 24
	movs r0, 0x11
	adds r2, r7, 0
	bl sub_80BD28C
	b _080BCF64
	.pool
_080BCEF0:
	mov r3, r9
	lsls r0, r3, 25
	lsrs r4, r0, 24
	movs r0, 0x11
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_80BD28C
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BCF42
	adds r0, r5, 0
	movs r1, 0x12
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD154
	mov r2, r8
	ldr r0, [r2]
	adds r0, r6
	ldrb r0, [r0, 0x2]
	lsls r0, 30
	lsrs r0, 31
	movs r1, 0x11
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD1F4
	mov r3, r8
	ldr r0, [r3]
	adds r0, r6
	ldrh r0, [r0]
	movs r1, 0x16
	adds r2, r4, 0
	bl sub_80BD23C
	b _080BCF64
_080BCF42:
	adds r0, r5, 0
	movs r1, 0x12
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD154
	movs r0, 0
	movs r1, 0x11
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD1F4
	movs r0, 0
	movs r1, 0x16
	adds r2, r4, 0
	bl sub_80BD23C
_080BCF64:
	movs r0, 0x80
	lsls r0, 9
	add r0, r10
	lsrs r1, r0, 16
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0xA
	bls _080BCEB2
	b _080BD13E
_080BCF7C:
	subs r0, r1, 0x5
	lsls r1, r0, 16
	lsrs r5, r1, 16
	ldr r0, =0x00000181
	ldr r2, =gUnknown_02039B4C
	cmp r5, r0
	bhi _080BCF9A
	adds r6, r2, 0
	ldr r3, [r6]
	asrs r4, r1, 14
	adds r0, r3, r4
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080BCFB8
_080BCF9A:
	ldr r0, [r2]
	movs r1, 0xC6
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r1, 25
	b _080BD0B2
	.pool
_080BCFB8:
	movs r1, 0xC6
	lsls r1, 3
	adds r0, r3, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r1, 25
	lsrs r1, 24
	movs r0, 0x11
	adds r2, r7, 0
	bl sub_80BD28C
	ldr r1, [r6]
	adds r0, r1, r4
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BD028
	movs r3, 0xC6
	lsls r3, 3
	adds r0, r1, r3
	movs r1, 0
	ldrsh r2, [r0, r1]
	lsls r2, 25
	lsrs r2, 24
	adds r0, r5, 0
	movs r1, 0x12
	adds r3, r7, 0
	bl sub_80BD154
	ldr r1, [r6]
	adds r0, r1, r4
	ldrb r0, [r0, 0x2]
	lsls r0, 30
	lsrs r0, 31
	movs r2, 0xC6
	lsls r2, 3
	adds r1, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	lsls r2, 25
	lsrs r2, 24
	movs r1, 0x11
	adds r3, r7, 0
	bl sub_80BD1F4
	ldr r1, [r6]
	adds r0, r1, r4
	ldrh r0, [r0]
	movs r2, 0xC6
	lsls r2, 3
	adds r1, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	lsls r2, 25
	lsrs r2, 24
	b _080BD06C
_080BD028:
	movs r2, 0xC6
	lsls r2, 3
	adds r0, r1, r2
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r2, 25
	lsrs r2, 24
	adds r0, r5, 0
	movs r1, 0x12
	adds r3, r7, 0
	bl sub_80BD154
	ldr r0, [r6]
	movs r1, 0xC6
	lsls r1, 3
	adds r0, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r2, 25
	lsrs r2, 24
	movs r0, 0
	movs r1, 0x11
	adds r3, r7, 0
	bl sub_80BD1F4
	ldr r0, [r6]
	movs r1, 0xC6
	lsls r1, 3
	adds r0, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r2, 25
	lsrs r2, 24
	movs r0, 0
_080BD06C:
	movs r1, 0x16
	bl sub_80BD23C
	b _080BD13E
_080BD074:
	adds r0, r1, 0x5
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_02039B4C
	mov r8, r0
	ldr r3, [r0]
	movs r2, 0xC6
	lsls r2, 3
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r0, 0xA
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _080BD09A
	adds r0, r2, 0
	subs r0, 0x10
	lsls r0, 16
	lsrs r2, r0, 16
_080BD09A:
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r0, =0x00000181
	cmp r5, r0
	bhi _080BD0B0
	asrs r6, r1, 14
	adds r0, r3, r6
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080BD0CC
_080BD0B0:
	lsls r1, r2, 25
_080BD0B2:
	lsrs r1, 24
	movs r0, 0x11
	adds r2, r7, 0
	bl sub_80BD28C
	b _080BD13E
	.pool
_080BD0CC:
	lsls r0, r2, 25
	lsrs r4, r0, 24
	movs r0, 0x11
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_80BD28C
	mov r3, r8
	ldr r0, [r3]
	adds r0, r6
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080BD11C
	adds r0, r5, 0
	movs r1, 0x12
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD154
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	ldrb r0, [r0, 0x2]
	lsls r0, 30
	lsrs r0, 31
	movs r1, 0x11
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD1F4
	mov r2, r8
	ldr r0, [r2]
	adds r0, r6
	ldrh r0, [r0]
	movs r1, 0x16
	adds r2, r4, 0
	bl sub_80BD23C
	b _080BD13E
_080BD11C:
	adds r0, r5, 0
	movs r1, 0x12
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD154
	movs r0, 0
	movs r1, 0x11
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_80BD1F4
	movs r0, 0
	movs r1, 0x16
	adds r2, r4, 0
	bl sub_80BD23C
_080BD13E:
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80BCE84

	thumb_func_start sub_80BD154
sub_80BD154: @ 80BD154
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r1, =gUnknown_0855D2B8
	add r0, sp, 0x4
	movs r2, 0x6
	bl memcpy
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	lsls r4, 2
	adds r4, r0, r4
	ldrh r6, [r4]
	ldr r1, =0x00000612
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080BD194
	adds r0, r6, 0
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r6, r0, 16
_080BD194:
	add r4, sp, 0x4
	adds r0, r6, 0
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4, 0x2]
	add r5, sp, 0x4
	adds r0, r6, 0
	movs r1, 0x64
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x3]
	add r5, sp, 0x4
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x4]
	str r7, [sp]
	movs r0, 0
	movs r1, 0x7
	add r2, sp, 0x4
	mov r3, r8
	bl sub_80BCE2C
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BD154

	thumb_func_start sub_80BD1F4
sub_80BD1F4: @ 80BD1F4
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 16
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r0, 0
	beq _080BD220
	ldr r1, =gUnknown_0855D2BE
	lsls r2, r3, 3
	lsls r3, r4, 3
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0
	bl BlitBitmapToWindow
	b _080BD234
	.pool
_080BD220:
	lsls r2, r3, 3
	lsls r3, r4, 3
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelRect
_080BD234:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80BD1F4

	thumb_func_start sub_80BD23C
sub_80BD23C: @ 80BD23C
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	bl NationalPokedexNumToSpecies
	adds r1, r0, 0
	cmp r1, 0
	beq _080BD264
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r4, r1, r0
	b _080BD266
	.pool
_080BD264:
	ldr r4, =gUnknown_0855D2FE
_080BD266:
	str r5, [sp]
	movs r0, 0
	movs r1, 0x7
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_80BCE2C
	adds r0, r4, 0
	bl StringLength
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BD23C

	thumb_func_start sub_80BD28C
sub_80BD28C: @ 80BD28C
	push {lr}
	sub sp, 0x8
	adds r2, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	lsls r3, 24
	lsrs r2, 21
	lsrs r3, 21
	movs r0, 0x60
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80BD28C

	thumb_func_start sub_80BD2B4
sub_80BD2B4: @ 80BD2B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	movs r2, 0
	ldr r7, =gUnknown_02039B4C
	adds r5, r7, 0
	ldr r4, =0x0000061e
	ldr r0, =0x0000ffff
	adds r3, r0, 0
_080BD2DA:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080BD2DA
	ldr r0, [r7]
	ldr r1, =0x00000626
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0]
	subs r0, r6, 0x1
	lsls r0, 16
	lsrs r0, 16
	bl sub_80BDA8C
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =0x0000ffff
	cmp r0, r4
	beq _080BD334
	movs r1, 0x60
	movs r2, 0x50
	bl sub_80BDACC
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_80BE4E0
	str r2, [r1]
	adds r0, r3
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x38]
_080BD334:
	adds r0, r6, 0
	bl sub_80BDA8C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	beq _080BD366
	movs r1, 0x60
	movs r2, 0x50
	bl sub_80BDACC
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_80BE4E0
	str r2, [r1]
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x38]
_080BD366:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r0, 16
	bl sub_80BDA8C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	beq _080BD39C
	movs r1, 0x60
	movs r2, 0x50
	bl sub_80BDACC
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_80BE4E0
	str r2, [r1]
	adds r0, r3
	movs r1, 0x20
	strh r1, [r0, 0x38]
_080BD39C:
	movs r0, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_80BCE84
	ldr r0, [r7]
	ldr r2, =0x0000062d
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, [r7]
	movs r2, 0xC6
	lsls r2, 3
	adds r1, r0, r2
	movs r2, 0
	strh r2, [r1]
	ldr r1, =0x00000632
	adds r0, r1
	strh r2, [r0]
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BD2B4

	thumb_func_start sub_80BD404
sub_80BD404: @ 80BD404
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r3, =0x0000062e
	adds r2, r1, r3
	ldrb r3, [r2]
	adds r7, r0, 0
	cmp r3, 0
	bne _080BD428
	b _080BD578
_080BD428:
	subs r0, r3, 0x1
	strb r0, [r2]
	cmp r4, 0x1
	beq _080BD440
	cmp r4, 0x2
	beq _080BD4DC
	b _080BD558
	.pool
_080BD440:
	movs r3, 0
	ldr r4, =0x0000ffff
	mov r12, r4
	ldr r0, =gSprites
	mov r8, r0
	adds r2, r7, 0
_080BD44C:
	ldr r0, [r2]
	lsls r1, r3, 1
	ldr r4, =0x0000061e
	adds r0, r4
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r12
	beq _080BD46A
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrh r0, [r1, 0x38]
	adds r0, r5
	strh r0, [r1, 0x38]
_080BD46A:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _080BD44C
	ldr r4, [r7]
	ldr r1, =0x0000062e
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, =0x0000062d
	adds r0, r4, r3
	ldr r1, =0x00000632
	adds r4, r1
	movs r3, 0
	ldrsh r1, [r4, r3]
	lsls r1, 4
	ldrb r0, [r0]
	adds r1, r0
	subs r1, r2
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, [r7]
	ldr r4, =0x0000062c
	adds r2, r0, r4
	movs r1, 0xC5
	lsls r1, 3
	adds r0, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r0, r1
	strb r0, [r2]
	b _080BD558
	.pool
_080BD4DC:
	movs r3, 0
	ldr r2, =0x0000ffff
	mov r12, r2
	ldr r4, =gSprites
	mov r8, r4
	adds r2, r7, 0
_080BD4E8:
	ldr r0, [r2]
	lsls r1, r3, 1
	ldr r4, =0x0000061e
	adds r0, r4
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r12
	beq _080BD506
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrh r0, [r1, 0x38]
	subs r0, r5
	strh r0, [r1, 0x38]
_080BD506:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _080BD4E8
	ldr r4, [r7]
	ldr r1, =0x0000062e
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, =0x0000062d
	adds r0, r4, r3
	ldr r1, =0x00000632
	adds r4, r1
	movs r3, 0
	ldrsh r1, [r4, r3]
	lsls r1, 4
	ldrb r0, [r0]
	adds r1, r0
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, [r7]
	ldr r4, =0x0000062c
	adds r1, r0, r4
	movs r2, 0xC5
	lsls r2, 3
	adds r0, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	adds r0, r3
	strb r0, [r1]
_080BD558:
	movs r0, 0
	b _080BD598
	.pool
_080BD578:
	ldr r4, =0x0000062d
	adds r2, r1, r4
	movs r3, 0xC6
	lsls r3, 3
	adds r0, r1, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
	lsls r1, 4
	ldrb r2, [r2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	movs r0, 0x1
_080BD598:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BD404

	thumb_func_start sub_80BD5A8
sub_80BD5A8: @ 80BD5A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 16
	lsrs r3, r1, 16
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	movs r5, 0xC6
	lsls r5, 3
	adds r1, r0, r5
	ldrh r1, [r1]
	ldr r6, =0x00000632
	adds r0, r6
	strh r1, [r0]
	cmp r2, 0x1
	beq _080BD5D8
	cmp r2, 0x2
	beq _080BD638
	b _080BD694
	.pool
_080BD5D8:
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	bl sub_80BDA8C
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080BD612
	adds r0, r1, 0
	movs r1, 0x60
	movs r2, 0x50
	bl sub_80BDACC
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_80BE4E0
	str r2, [r1]
	adds r0, r3
	ldr r1, =0x0000ffc0
	strh r1, [r0, 0x38]
_080BD612:
	ldr r0, [r4]
	adds r1, r0, r5
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _080BD634
	subs r0, r2, 0x1
	b _080BD692
	.pool
_080BD634:
	movs r0, 0xF
	b _080BD692
_080BD638:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	bl sub_80BDA8C
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080BD672
	adds r0, r1, 0
	movs r1, 0x60
	movs r2, 0x50
	bl sub_80BDACC
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_80BE4E0
	str r2, [r1]
	adds r0, r3
	movs r1, 0x40
	strh r1, [r0, 0x38]
_080BD672:
	ldr r0, [r4]
	adds r1, r0, r5
	ldrh r2, [r1]
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0xE
	bgt _080BD690
	adds r0, r2, 0x1
	b _080BD692
	.pool
_080BD690:
	movs r0, 0
_080BD692:
	strh r0, [r1]
_080BD694:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80BD5A8

	thumb_func_start sub_80BD69C
sub_80BD69C: @ 80BD69C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	movs r0, 0
	mov r10, r0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080BD6FC
	cmp r7, 0
	beq _080BD6FC
	movs r1, 0x1
	mov r10, r1
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r3, [r0]
	subs r3, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0
	bl sub_80C0E0C
	adds r7, r0, 0
	movs r0, 0x1
	adds r1, r7, 0
	bl sub_80BD5A8
	movs r0, 0x1
	b _080BD734
	.pool
_080BD6FC:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BD74C
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r3, =0x0000060c
	adds r0, r3
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r7, r0
	bge _080BD74C
	movs r1, 0x2
	mov r10, r1
	lsls r3, r0, 16
	lsrs r3, 16
	movs r0, 0
	adds r1, r7, 0
	movs r2, 0
	bl sub_80C0E0C
	adds r7, r0, 0
	movs r0, 0x2
	adds r1, r7, 0
	bl sub_80BD5A8
	movs r0, 0x2
_080BD734:
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80BCE84
	movs r0, 0x6C
	bl audio_play
	b _080BD81A
	.pool
_080BD74C:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080BD7B4
	cmp r7, 0
	beq _080BD7B4
	adds r6, r7, 0
	movs r4, 0
_080BD75E:
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r3, [r0]
	subs r3, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0
	bl sub_80C0E0C
	adds r7, r0, 0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080BD75E
	ldr r1, [r5]
	ldr r3, =0x0000062c
	adds r1, r3
	subs r0, r7, r6
	lsls r0, 4
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
	bl sub_80BDA40
	adds r0, r7, 0
	movs r1, 0xE
	bl sub_80BD2B4
	movs r0, 0x6D
	bl audio_play
	b _080BD81A
	.pool
_080BD7B4:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080BD81A
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r3, =0x0000060c
	adds r0, r3
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r7, r0
	bge _080BD81A
	adds r6, r7, 0
	movs r4, 0
_080BD7D2:
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r1, =0x0000060c
	adds r0, r1
	ldrh r3, [r0]
	subs r3, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0
	adds r1, r7, 0
	movs r2, 0
	bl sub_80C0E0C
	adds r7, r0, 0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080BD7D2
	ldr r1, [r5]
	ldr r2, =0x0000062c
	adds r1, r2
	subs r0, r7, r6
	lsls r0, 4
	ldrb r3, [r1]
	adds r0, r3
	strb r0, [r1]
	bl sub_80BDA40
	adds r0, r7, 0
	movs r1, 0xE
	bl sub_80BD2B4
	movs r0, 0x6D
	bl audio_play
_080BD81A:
	mov r0, r10
	cmp r0, 0
	bne _080BD83C
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 3
	adds r0, r1
	mov r2, r10
	strh r2, [r0]
	b _080BD8A2
	.pool
_080BD83C:
	ldr r1, =gUnknown_0855D28C
	ldr r6, =gUnknown_02039B4C
	ldr r2, [r6]
	movs r3, 0xC7
	lsls r3, 3
	mov r9, r3
	adds r0, r2, r3
	ldrh r0, [r0]
	lsrs r0, 2
	adds r1, r0, r1
	ldrb r5, [r1]
	ldr r1, =gUnknown_0855D291
	adds r0, r1
	ldrb r3, [r0]
	ldr r0, =0x0000062e
	adds r2, r0
	strb r3, [r2]
	ldr r1, [r6]
	ldr r2, =0x00000636
	mov r8, r2
	adds r0, r1, r2
	strh r3, [r0]
	ldr r4, =0x00000634
	adds r0, r1, r4
	strh r5, [r0]
	ldr r3, =0x0000062f
	adds r1, r3
	mov r0, r10
	strb r0, [r1]
	ldr r2, [r6]
	lsrs r5, 1
	movs r1, 0xC5
	lsls r1, 3
	adds r0, r2, r1
	strh r5, [r0]
	adds r3, r2, r3
	ldrb r0, [r3]
	adds r4, r2, r4
	ldrb r1, [r4]
	add r2, r8
	ldrb r2, [r2]
	bl sub_80BD404
	ldr r0, [r6]
	mov r2, r9
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0xB
	bhi _080BD8A2
	adds r0, 0x1
	strh r0, [r1]
_080BD8A2:
	adds r0, r7, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BD69C

	thumb_func_start sub_80BD8D0
sub_80BD8D0: @ 80BD8D0
	push {r4-r7,lr}
	movs r4, 0
	ldr r0, =gUnknown_02039B4C
	mov r12, r0
	ldr r6, =gSprites
	ldr r5, =0x0000ffff
_080BD8DC:
	mov r1, r12
	ldr r3, [r1]
	lsls r1, r4, 1
	ldr r2, =0x0000061e
	adds r0, r3, r2
	adds r0, r1
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r6
	movs r7, 0x24
	ldrsh r0, [r1, r7]
	cmp r0, 0
	bne _080BD90C
	movs r7, 0x26
	ldrsh r0, [r1, r7]
	cmp r0, 0
	bne _080BD90C
	cmp r2, r5
	beq _080BD90C
	ldr r1, =0x00000626
	adds r0, r3, r1
	strh r2, [r0]
_080BD90C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _080BD8DC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BD8D0

	thumb_func_start sub_80BD930
sub_80BD930: @ 80BD930
	push {r4-r6,lr}
	ldr r3, =gUnknown_02039B4C
	ldr r0, [r3]
	ldr r1, =0x0000060e
	adds r0, r1
	ldrh r4, [r0]
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080BD9B8
	cmp r4, 0
	beq _080BD9B8
	adds r2, r4, 0
	adds r5, r3, 0
_080BD950:
	ldr r0, [r5]
	ldr r1, =0x0000060c
	adds r0, r1
	ldrh r3, [r0]
	subs r3, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x1
	adds r1, r2, 0
	movs r2, 0
	bl sub_80C0E0C
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	bne _080BD9A0
	cmp r2, 0
	bne _080BD950
_080BD97E:
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r0, =0x0000060e
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, r4
	bne _080BD9A4
	b _080BDA38
	.pool
_080BD9A0:
	adds r4, r2, 0
	b _080BD97E
_080BD9A4:
	strh r4, [r2]
	ldr r0, =0x0000062c
	adds r1, r0
	ldrb r0, [r1]
	subs r0, 0x10
	b _080BDA20
	.pool
_080BD9B4:
	adds r4, r2, 0
	b _080BDA08
_080BD9B8:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BDA38
	ldr r0, [r3]
	ldr r1, =0x0000060c
	adds r0, r1
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r4, r0
	bge _080BDA38
	adds r2, r4, 0
	adds r6, r3, 0
	adds r5, r1, 0
_080BD9D6:
	ldr r0, [r6]
	adds r0, r5
	ldrh r3, [r0]
	subs r3, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0
	adds r1, r2, 0
	movs r2, 0
	bl sub_80C0E0C
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, [r6]
	lsls r0, r2, 2
	adds r0, r1, r0
	ldrb r0, [r0, 0x2]
	lsls r0, 31
	cmp r0, 0
	bne _080BD9B4
	adds r0, r1, r5
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r2, r0
	blt _080BD9D6
_080BDA08:
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	ldr r0, =0x0000060e
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, r4
	beq _080BDA38
	strh r4, [r2]
	ldr r0, =0x0000062c
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x10
_080BDA20:
	strb r0, [r1]
	movs r0, 0x1
	b _080BDA3A
	.pool
_080BDA38:
	movs r0, 0
_080BDA3A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80BD930

	thumb_func_start sub_80BDA40
sub_80BDA40: @ 80BDA40
	push {r4-r7,lr}
	movs r5, 0
	ldr r6, =gUnknown_02039B4C
	ldr r7, =0x0000ffff
_080BDA48:
	ldr r0, [r6]
	lsls r4, r5, 1
	ldr r1, =0x0000061e
	adds r0, r1
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r7
	beq _080BDA6C
	bl sub_818D820
	ldr r1, [r6]
	ldr r0, =0x0000061e
	adds r1, r0
	adds r1, r4
	ldrh r2, [r1]
	adds r0, r7, 0
	orrs r0, r2
	strh r0, [r1]
_080BDA6C:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _080BDA48
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BDA40

	thumb_func_start sub_80BDA8C
sub_80BDA8C: @ 80BDA8C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x00000181
	cmp r2, r0
	bhi _080BDAA8
	ldr r0, =gUnknown_02039B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r2, r1, r0
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080BDAB8
_080BDAA8:
	ldr r0, =0x0000ffff
	b _080BDAC6
	.pool
_080BDAB8:
	ldrb r0, [r2, 0x2]
	lsls r0, 31
	cmp r0, 0
	bne _080BDAC4
	movs r0, 0
	b _080BDAC6
_080BDAC4:
	ldrh r0, [r2]
_080BDAC6:
	pop {r1}
	bx r1
	thumb_func_end sub_80BDA8C

	thumb_func_start sub_80BDACC
sub_80BDACC: @ 80BDACC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r2, 16
	lsrs r2, 16
	movs r6, 0
	ldr r0, =gUnknown_02039B4C
	mov r9, r0
	ldr r3, =0x0000ffff
	lsls r1, 16
_080BDAE8:
	mov r4, r9
	ldr r0, [r4]
	lsls r7, r6, 1
	ldr r4, =0x0000061e
	adds r0, r4
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, r3
	bne _080BDB60
	lsls r2, 16
	mov r0, r8
	asrs r1, 16
	asrs r2, 16
	adds r3, r6, 0
	bl sub_80C0E9C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r4, r0
	ldrb r1, [r4, 0x1]
	movs r2, 0x4
	negs r2, r2
	adds r0, r2, 0
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strb r1, [r4, 0x1]
	ldrb r0, [r4, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r4, 0x5]
	movs r0, 0
	strh r0, [r4, 0x2E]
	strh r6, [r4, 0x30]
	mov r0, r8
	bl NationalPokedexNumToSpecies
	strh r0, [r4, 0x32]
	mov r4, r9
	ldr r0, [r4]
	ldr r1, =0x0000061e
	adds r0, r1
	adds r0, r7
	strh r5, [r0]
	adds r0, r5, 0
	b _080BDB6C
	.pool
_080BDB60:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _080BDAE8
	ldr r0, =0x0000ffff
_080BDB6C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BDACC

	thumb_func_start sub_80BDB7C
sub_80BDB7C: @ 80BDB7C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_0855D1AC
	adds r0, r4, 0
	movs r1, 0xB8
	movs r2, 0x4
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gSprites
	mov r10, r1
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0
	strh r1, [r0, 0x30]
	adds r0, r4, 0
	movs r1, 0xB8
	movs r2, 0x9C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x1
	strh r1, [r0, 0x30]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gUnknown_0855D194
	movs r1, 0xE6
	movs r2, 0x14
	movs r3, 0
	bl CreateSprite
	ldr r5, =gUnknown_0855D1C4
	adds r0, r5, 0
	movs r1, 0x10
	movs r2, 0x78
	movs r3, 0
	bl CreateSprite
	adds r0, r5, 0
	movs r1, 0x30
	movs r2, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x3
	bl StartObjectImageAnim
	adds r0, r5, 0
	movs r1, 0x10
	movs r2, 0x90
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	add r4, r10
	adds r0, r4, 0
	movs r1, 0x2
	bl StartObjectImageAnim
	movs r0, 0x80
	mov r9, r0
	mov r1, r9
	strh r1, [r4, 0x32]
	adds r0, r5, 0
	movs r1, 0x30
	movs r2, 0x90
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r6, =gUnknown_0855D1DC
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x50
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	add r1, r10
	ldrb r2, [r1, 0x1]
	movs r4, 0x4
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	movs r5, 0x1
	orrs r0, r5
	strb r0, [r1, 0x1]
	ldrb r2, [r1, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	movs r2, 0x3C
	orrs r0, r2
	strb r0, [r1, 0x3]
	movs r0, 0x1E
	strh r0, [r1, 0x2E]
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x50
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	add r1, r10
	ldrb r0, [r1, 0x1]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0x1]
	ldrb r0, [r1, 0x3]
	movs r2, 0x3E
	orrs r0, r2
	strb r0, [r1, 0x3]
	movs r0, 0x1F
	strh r0, [r1, 0x2E]
	mov r0, r9
	strh r0, [r1, 0x30]
	mov r1, r8
	cmp r1, 0
	beq _080BDCCC
	b _080BE414
_080BDCCC:
	bl sub_809D42C
	cmp r0, 0
	beq _080BDCD6
	b _080BDF4C
_080BDCD6:
	ldr r4, =gUnknown_0855D1F4
	adds r0, r4, 0
	movs r1, 0x20
	movs r2, 0x28
	movs r3, 0x1
	bl CreateSprite
	adds r0, r4, 0
	movs r1, 0x20
	movs r2, 0x48
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x1
	bl StartObjectImageAnim
	movs r0, 0
	mov r8, r0
	ldr r0, =gUnknown_0855D224
	movs r1, 0x18
	movs r2, 0x30
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	mov r1, r10
	adds r4, r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	beq _080BDD6C
	movs r0, 0x1
	mov r8, r0
	b _080BDD78
	.pool
_080BDD6C:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BDD78:
	ldr r0, =gUnknown_0855D224
	movs r1, 0x20
	movs r2, 0x30
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080BDDB0
	mov r0, r8
	cmp r0, 0
	beq _080BDDD4
_080BDDB0:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BDDE8
	.pool
_080BDDD4:
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BDDE8:
	ldr r6, =gUnknown_0855D224
	adds r0, r6, 0
	movs r1, 0x28
	movs r2, 0x30
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r1, =0x0000061a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	movs r1, 0x18
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, [r5]
	ldr r1, =0x0000061c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r4
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	beq _080BDE80
	movs r0, 0x1
	mov r8, r0
	b _080BDE8C
	.pool
_080BDE80:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BDE8C:
	ldr r0, =gUnknown_0855D224
	movs r1, 0x20
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080BDEC4
	mov r0, r8
	cmp r0, 0
	beq _080BDEE8
_080BDEC4:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BDEFC
	.pool
_080BDEE8:
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BDEFC:
	ldr r0, =gUnknown_0855D224
	movs r1, 0x28
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BE3E2
	.pool
_080BDF4C:
	ldr r4, =gUnknown_0855D1F4
	adds r0, r4, 0
	movs r1, 0x20
	movs r2, 0x28
	movs r3, 0x1
	bl CreateSprite
	adds r0, r4, 0
	movs r1, 0x20
	movs r2, 0x4C
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r4, =gUnknown_0855D20C
	adds r0, r4, 0
	movs r1, 0x11
	movs r2, 0x2D
	movs r3, 0x1
	bl CreateSprite
	adds r0, r4, 0
	movs r1, 0x11
	movs r2, 0x37
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x1
	bl StartObjectImageAnim
	adds r0, r4, 0
	movs r1, 0x11
	movs r2, 0x51
	movs r3, 0x1
	bl CreateSprite
	adds r0, r4, 0
	movs r1, 0x11
	movs r2, 0x5B
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
	movs r1, 0x1
	bl StartObjectImageAnim
	movs r0, 0
	bl sub_80C0844
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0
	mov r8, r0
	ldr r0, =gUnknown_0855D23C
	movs r1, 0x28
	movs r2, 0x2D
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	mov r1, r10
	adds r4, r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	beq _080BE024
	movs r0, 0x1
	mov r8, r0
	b _080BE030
	.pool
_080BE024:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE030:
	ldr r0, =gUnknown_0855D23C
	movs r1, 0x30
	movs r2, 0x2D
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080BE060
	mov r1, r8
	cmp r1, 0
	beq _080BE07C
_080BE060:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BE090
	.pool
_080BE07C:
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE090:
	ldr r5, =gUnknown_0855D23C
	adds r0, r5, 0
	movs r1, 0x38
	movs r2, 0x2D
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	movs r0, 0
	mov r8, r0
	adds r0, r5, 0
	movs r1, 0x28
	movs r2, 0x37
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r4
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	beq _080BE11C
	movs r0, 0x1
	mov r8, r0
	b _080BE128
	.pool
_080BE11C:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE128:
	ldr r0, =gUnknown_0855D23C
	movs r1, 0x30
	movs r2, 0x37
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080BE160
	mov r0, r8
	cmp r0, 0
	beq _080BE184
_080BE160:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BE198
	.pool
_080BE184:
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE198:
	ldr r5, =gUnknown_0855D23C
	adds r0, r5, 0
	movs r1, 0x38
	movs r2, 0x37
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	movs r0, 0x1
	bl sub_80C0844
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0
	mov r8, r0
	adds r0, r5, 0
	movs r1, 0x28
	movs r2, 0x51
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r4
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	beq _080BE230
	movs r1, 0x1
	mov r8, r1
	b _080BE23C
	.pool
_080BE230:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE23C:
	ldr r0, =gUnknown_0855D23C
	movs r1, 0x30
	movs r2, 0x51
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080BE26C
	mov r0, r8
	cmp r0, 0
	beq _080BE288
_080BE26C:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BE29C
	.pool
_080BE288:
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE29C:
	ldr r5, =gUnknown_0855D23C
	adds r0, r5, 0
	movs r1, 0x38
	movs r2, 0x51
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	movs r1, 0
	mov r8, r1
	adds r0, r5, 0
	movs r1, 0x28
	movs r2, 0x5B
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r4
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	beq _080BE328
	movs r0, 0x1
	mov r8, r0
	b _080BE334
	.pool
_080BE328:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE334:
	ldr r0, =gUnknown_0855D23C
	movs r1, 0x30
	movs r2, 0x5B
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080BE36C
	mov r0, r8
	cmp r0, 0
	beq _080BE390
_080BE36C:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	b _080BE3A4
	.pool
_080BE390:
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE3A4:
	ldr r0, =gUnknown_0855D23C
	movs r1, 0x38
	movs r2, 0x5B
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000061c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
_080BE3E2:
	ldr r0, =gUnknown_0855D254
	movs r1, 0x88
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gSprites
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	b _080BE42C
	.pool
_080BE414:
	ldr r0, =gUnknown_0855D254
	movs r1, 0x88
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	add r0, r10
_080BE42C:
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BDB7C

	thumb_func_start nullsub_38
nullsub_38: @ 80BE448
	bx lr
	thumb_func_end nullsub_38

	thumb_func_start sub_80BE44C
sub_80BE44C: @ 80BE44C
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r2, =0x0000064a
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BE464
	adds r0, r1, 0
	bl DestroySprite
_080BE464:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BE44C

	thumb_func_start sub_80BE470
sub_80BE470: @ 80BE470
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x5]
	ldrb r1, [r2, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x1]
	movs r0, 0
	strh r0, [r2, 0x24]
	strh r0, [r2, 0x26]
	ldr r1, [r2, 0x20]
	ldr r0, =0x00380030
	cmp r1, r0
	beq _080BE4D4
	ldrh r1, [r2, 0x20]
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	cmp r0, 0x30
	ble _080BE4A4
	subs r0, r1, 0x1
	strh r0, [r2, 0x20]
_080BE4A4:
	ldrh r1, [r2, 0x20]
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	cmp r0, 0x2F
	bgt _080BE4B2
	adds r0, r1, 0x1
	strh r0, [r2, 0x20]
_080BE4B2:
	ldrh r1, [r2, 0x22]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r0, 0x38
	ble _080BE4C0
	subs r0, r1, 0x1
	strh r0, [r2, 0x22]
_080BE4C0:
	ldrh r1, [r2, 0x22]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r0, 0x37
	bgt _080BE4D8
	adds r0, r1, 0x1
	strh r0, [r2, 0x22]
	b _080BE4D8
	.pool
_080BE4D4:
	ldr r0, =nullsub_38
	str r0, [r2, 0x1C]
_080BE4D8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BE470

	thumb_func_start sub_80BE4E0
sub_80BE4E0: @ 80BE4E0
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gUnknown_02039B4C
	ldr r1, [r7]
	ldr r2, =0x0000064a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BE520
	cmp r0, 0x3
	beq _080BE520
	lsls r5, r6, 1
	ldr r4, =0x0000061e
	adds r0, r1, r4
	adds r0, r5
	ldrh r0, [r0]
	bl sub_818D820
	ldr r0, [r7]
	adds r0, r4
	adds r0, r5
	b _080BE5EC
	.pool
_080BE520:
	ldr r2, =gSineTable
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r0, 23
	adds r0, r2
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x4C
	muls r0, r1
	cmp r0, 0
	bge _080BE538
	adds r0, 0xFF
_080BE538:
	asrs r0, 8
	strh r0, [r4, 0x26]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	adds r0, 0x40
	lsls r0, 1
	adds r0, r2
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 9
	bl __divsi3
	adds r2, r0, 0
	ldr r0, =0x0000ffff
	cmp r2, r0
	bls _080BE55C
	adds r2, r0, 0
_080BE55C:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x80
	lsls r1, 1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	adds r1, r6, 0x1
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldrh r0, [r4, 0x38]
	adds r0, 0x3F
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7E
	bhi _080BE5B4
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	b _080BE5C0
	.pool
_080BE5B4:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080BE5C0:
	ldrh r0, [r4, 0x38]
	adds r0, 0x3F
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7E
	bls _080BE5F0
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _080BE5F0
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	lsls r6, 1
	ldr r4, =0x0000061e
	adds r0, r4
	adds r0, r6
	ldrh r0, [r0]
	bl sub_818D820
	ldr r0, [r5]
	adds r0, r4
	adds r0, r6
_080BE5EC:
	ldr r1, =0x0000ffff
	strh r1, [r0]
_080BE5F0:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BE4E0

	thumb_func_start sub_80BE604
sub_80BE604: @ 80BE604
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000064a
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BE62C
	cmp r0, 0x3
	beq _080BE62C
	adds r0, r4, 0
	bl DestroySprite
	b _080BE648
	.pool
_080BE62C:
	ldr r2, [r1]
	ldr r1, =0x0000060e
	adds r0, r2, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	ldr r1, =0x0000060c
	adds r2, r1
	ldrh r1, [r2]
	subs r1, 0x1
	bl __divsi3
	strh r0, [r4, 0x26]
_080BE648:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BE604

	thumb_func_start sub_80BE658
sub_80BE658: @ 80BE658
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000064a
	adds r0, r2
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0
	beq _080BE680
	cmp r0, 0x3
	beq _080BE680
	adds r0, r3, 0
	bl DestroySprite
	b _080BE750
	.pool
_080BE680:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _080BE6C2
	ldr r0, [r5]
	ldr r2, =0x0000060e
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, 0x2
	adds r0, r2
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _080BE6AC
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _080BE6B8
	.pool
_080BE6AC:
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_080BE6B8:
	strb r1, [r0]
	adds r2, r0, 0
	ldrh r1, [r3, 0x32]
	lsls r0, r1, 24
	b _080BE6F8
_080BE6C2:
	ldr r0, [r5]
	ldr r1, =0x0000060e
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080BE6E0
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _080BE6EC
	.pool
_080BE6E0:
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_080BE6EC:
	strb r1, [r0]
	adds r2, r0, 0
	ldrh r1, [r3, 0x32]
	adds r0, r1, 0
	subs r0, 0x80
	lsls r0, 24
_080BE6F8:
	lsrs r0, 24
	adds r4, r1, 0
	ldr r1, =gSineTable
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080BE70C
	adds r0, 0x3F
_080BE70C:
	asrs r0, 6
	strh r0, [r3, 0x26]
	adds r0, r4, 0
	adds r0, 0x8
	strh r0, [r3, 0x32]
	ldr r1, [r5]
	ldr r3, =0x0000064f
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080BE748
	adds r3, 0x3
	adds r0, r1, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080BE748
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080BE748
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	b _080BE74E
	.pool
_080BE748:
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
_080BE74E:
	strb r0, [r2]
_080BE750:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80BE658

	thumb_func_start sub_80BE758
sub_80BE758: @ 80BE758
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r2, =0x0000064a
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BE774
	cmp r0, 0x3
	beq _080BE774
	adds r0, r1, 0
	bl DestroySprite
_080BE774:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BE758

	thumb_func_start sub_80BE780
sub_80BE780: @ 80BE780
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000064a
	adds r0, r2
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0
	beq _080BE7AC
	cmp r0, 0x3
	beq _080BE7AC
	adds r0, r6, 0
	bl DestroySprite
	b _080BE824
	.pool
_080BE7AC:
	ldr r0, [r7]
	ldr r5, =0x0000062c
	adds r0, r5
	ldrb r1, [r0]
	ldrh r0, [r6, 0x30]
	adds r1, r0
	lsls r1, 24
	lsrs r1, 24
	ldr r4, =gSineTable
	lsls r0, r1, 1
	adds r0, r4
	ldrh r3, [r0]
	adds r1, 0x40
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r6, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r1]
	lsls r3, 16
	lsrs r2, r3, 16
	negs r3, r3
	lsrs r3, 16
	str r1, [sp]
	bl SetOamMatrix
	ldr r1, [r7]
	adds r1, r5
	ldrh r0, [r6, 0x30]
	adds r0, 0x40
	ldrb r1, [r1]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r4
	ldrh r3, [r1]
	adds r0, 0x40
	lsls r0, 1
	adds r0, r4
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	cmp r0, 0
	bge _080BE80C
	adds r0, 0xFF
_080BE80C:
	asrs r0, 8
	strh r0, [r6, 0x24]
	lsls r1, r3, 16
	asrs r1, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	cmp r0, 0
	bge _080BE820
	adds r0, 0xFF
_080BE820:
	asrs r0, 8
	strh r0, [r6, 0x26]
_080BE824:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BE780

	thumb_func_start sub_80BE834
sub_80BE834: @ 80BE834
	push {r4,lr}
	adds r3, r0, 0
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000064a
	adds r0, r2
	ldrb r2, [r0]
	cmp r2, 0
	beq _080BE85C
	cmp r2, 0x3
	beq _080BE85C
	adds r0, r3, 0
	bl DestroySprite
	b _080BE8D4
	.pool
_080BE85C:
	ldr r4, [r1]
	ldr r1, =0x0000064a
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x60
	cmp r0, 0
	bne _080BE86C
	movs r1, 0x50
_080BE86C:
	ldr r2, =0x0000064f
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BE8C8
	adds r2, 0x3
	adds r0, r4, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r1
	bne _080BE8C8
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r1, 0xCA
	lsls r1, 3
	adds r0, r4, r1
	ldrh r0, [r0]
	lsls r0, 4
	strh r0, [r3, 0x26]
	ldr r1, =gSineTable
	ldrh r2, [r3, 0x32]
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080BE8B0
	adds r0, 0x3F
_080BE8B0:
	asrs r0, 6
	strh r0, [r3, 0x24]
	adds r0, r2, 0
	adds r0, 0x8
	strh r0, [r3, 0x32]
	b _080BE8D4
	.pool
_080BE8C8:
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080BE8D4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80BE834

	thumb_func_start sub_80BE8DC
sub_80BE8DC: @ 80BE8DC
	push {r4,r5,lr}
	sub sp, 0x18
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	add r1, sp, 0x14
	movs r4, 0
	strb r4, [r1]
	adds r2, r1, 0
	movs r1, 0xF
	strb r1, [r2, 0x1]
	movs r1, 0x3
	strb r1, [r2, 0x2]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r2, [sp, 0x8]
	subs r1, 0x4
	str r1, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80BE8DC

	thumb_func_start sub_80BE91C
sub_80BE91C: @ 80BE91C
	push {r4,r5,lr}
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r1, =gUnknown_02039B54
	str r0, [r1]
	ldr r0, =sub_80BEA24
	movs r1, 0
	bl CreateTask
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	strh r2, [r0, 0x8]
	movs r1, 0x1
	strh r1, [r0, 0xA]
	strh r2, [r0, 0xC]
	strh r2, [r0, 0xE]
	strh r4, [r0, 0x10]
	movs r1, 0xFF
	strh r1, [r0, 0x12]
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0856E630
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_0856E640
	bl InitWindows
	bl DeactivateAllTextPrinters
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BE91C

	thumb_func_start sub_80BE9C4
sub_80BE9C4: @ 80BE9C4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _080BE9F0
	ldr r1, [r1]
	ldr r0, =sub_80BEDF4
	cmp r1, r0
	bne _080BE9F0
	movs r0, 0
	b _080BE9F2
	.pool
_080BE9F0:
	movs r0, 0x1
_080BE9F2:
	pop {r1}
	bx r1
	thumb_func_end sub_80BE9C4

	thumb_func_start sub_80BE9F8
sub_80BE9F8: @ 80BE9F8
	adds r2, r0, 0
	lsls r0, r1, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039B54
	str r2, [r1]
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r3, 0
	movs r2, 0x1
	strh r2, [r1, 0x8]
	strh r3, [r1, 0xA]
	strh r3, [r1, 0xC]
	strh r3, [r1, 0xE]
	bx lr
	.pool
	thumb_func_end sub_80BE9F8

	thumb_func_start sub_80BEA24
sub_80BEA24: @ 80BEA24
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0xA
	bhi _080BEA7C
	lsls r0, 2
	ldr r1, =_080BEA50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BEA50:
	.4byte _080BEA7C
	.4byte _080BEAF0
	.4byte _080BEB50
	.4byte _080BEB90
	.4byte _080BEB98
	.4byte _080BEC08
	.4byte _080BEC60
	.4byte _080BECBC
	.4byte _080BED04
	.4byte _080BED5E
	.4byte _080BED7C
_080BEA7C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BEA8A
	b _080BEDA0
_080BEA8A:
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r3, =0x0000064a
	adds r0, r3
	movs r6, 0x1
	strb r6, [r0]
	ldr r1, =gUnknown_030060B4
	ldr r0, [r5, 0xC]
	str r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	movs r2, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _080BEABA
	movs r2, 0x80
	lsls r2, 5
_080BEABA:
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _080BEACA
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	orrs r2, r0
_080BEACA:
	adds r0, r2, 0
	bl sub_80C09B0
	movs r2, 0x87
	lsls r2, 3
	adds r0, r5, r2
	strb r6, [r0]
	b _080BEDA0
	.pool
_080BEAF0:
	ldr r1, =gUnknown_08DC1934
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08DC3080
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, 0x1
	bl sub_80C0D30
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _080BED70
	.pool
_080BEB50:
	movs r0, 0xD
	bl sub_80BFCDC
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r1, =0x0000064d
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0xD
	bl sub_80BFD0C
	ldr r0, [r4]
	ldr r2, =0x0000064c
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	bl sub_80BC844
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _080BED70
	.pool
_080BEB90:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r5, r0
	b _080BED70
_080BEB98:
	ldr r4, =gUnknown_02039B54
	ldr r3, [r4]
	ldrh r0, [r3]
	ldr r1, =gUnknown_02039B4C
	ldr r1, [r1]
	ldr r2, =0x00000612
	adds r1, r2
	ldrh r2, [r1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	ldr r2, [r3]
	lsls r2, 14
	lsrs r2, 31
	movs r3, 0
	bl sub_80C020C
	ldr r0, [r4]
	ldrb r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080BEBD0
	ldr r0, =gPlttBufferUnfaded + 2
	movs r1, 0x31
	movs r2, 0x1E
	bl LoadPalette
_080BEBD0:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _080BED70
	.pool
_080BEC08:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r4, r1, r0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080BEC44
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r0, [r0]
	movs r1, 0x30
	movs r2, 0x38
	movs r3, 0
	bl sub_80C0E9C
	strh r0, [r4, 0x10]
	ldr r2, =gSprites
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
_080BEC44:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BED70
	.pool
_080BEC60:
	movs r3, 0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080BEC76
	movs r3, 0x14
_080BEC76:
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080BEC98
	ldr r2, =gSprites
	movs r0, 0x10
	ldrsh r1, [r1, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	orrs r3, r0
_080BEC98:
	mvns r0, r3
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_030060B4
	ldr r0, [r0]
	bl SetVBlankCallback
	b _080BED68
	.pool
_080BECBC:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _080BED70
	.pool
_080BED04:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BEDA0
	movs r0, 0x87
	lsls r0, 3
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r3, r0, 0x1
	strb r3, [r2]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080BED58
	bl sub_80A369C
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r0, [r0]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	movs r2, 0x7D
	movs r3, 0xA
	bl sub_80A32C0
	b _080BEDA0
	.pool
_080BED58:
	adds r0, r3, 0x1
	strb r0, [r2]
	b _080BEDA0
_080BED5E:
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _080BEDA0
_080BED68:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_080BED70:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080BEDA0
	.pool
_080BED7C:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	movs r1, 0x1
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	ldr r1, =sub_80BEDF4
	str r1, [r0]
	movs r3, 0x87
	lsls r3, 3
	adds r0, r5, r3
	strb r2, [r0]
_080BEDA0:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BEA24

	thumb_func_start sub_80BEDB0
sub_80BEDB0: @ 80BEDB0
	push {lr}
	bl FreeAllWindowBuffers
	movs r0, 0
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BEDC4
	bl Free
_080BEDC4:
	movs r0, 0x1
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BEDD2
	bl Free
_080BEDD2:
	movs r0, 0x2
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BEDE0
	bl Free
_080BEDE0:
	movs r0, 0x3
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080BEDEE
	bl Free
_080BEDEE:
	pop {r0}
	bx r0
	thumb_func_end sub_80BEDB0

	thumb_func_start sub_80BEDF4
sub_80BEDF4: @ 80BEDF4
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _080BEE34
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_80BF038
	str r0, [r4]
	movs r0, 0x6C
	bl audio_play
	b _080BEFBA
	.pool
_080BEE34:
	ldr r1, =gMain
	ldrh r2, [r1, 0x2E]
	movs r0, 0x2
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _080BEE50
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	b _080BEF0E
	.pool
_080BEE50:
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _080BEF28
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r1, =0x0000064d
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0x1
	beq _080BEEA0
	cmp r1, 0x1
	bgt _080BEE78
	cmp r1, 0
	beq _080BEE82
	b _080BEFBA
	.pool
_080BEE78:
	cmp r1, 0x2
	beq _080BEEC0
	cmp r1, 0x3
	beq _080BEF08
	b _080BEFBA
_080BEE82:
	movs r0, 0x15
	negs r0, r0
	str r3, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, [r5]
	ldr r3, =0x0000064e
	adds r0, r3
	movs r1, 0x1
	b _080BEEF0
	.pool
_080BEEA0:
	movs r0, 0x15
	negs r0, r0
	str r3, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, [r5]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0x2
	b _080BEEF0
	.pool
_080BEEC0:
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	ands r1, r0
	cmp r1, 0
	bne _080BEED8
	movs r0, 0x20
	bl audio_play
	b _080BEFBA
	.pool
_080BEED8:
	movs r0, 0x15
	negs r0, r0
	str r3, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, [r5]
	ldr r3, =0x0000064e
	adds r0, r3
	movs r1, 0x3
_080BEEF0:
	strb r1, [r0]
	ldr r0, =sub_80BEFD0
	str r0, [r4]
	movs r0, 0x15
	bl audio_play
	b _080BEFBA
	.pool
_080BEF08:
	movs r0, 0x1
	negs r0, r0
	str r3, [sp]
_080BEF0E:
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_80BF070
	str r0, [r4]
	movs r0, 0x3
	bl audio_play
	b _080BEFBA
	.pool
_080BEF28:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _080BEF44
	movs r0, 0x80
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	beq _080BEF78
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080BEF78
_080BEF44:
	ldr r3, =gUnknown_02039B4C
	ldr r0, [r3]
	ldr r4, =0x0000064d
	adds r2, r0, r4
	ldrb r0, [r2]
	cmp r0, 0
	beq _080BEF78
	subs r0, 0x1
	strb r0, [r2]
	ldr r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0xD
	bl sub_80BFD0C
	movs r0, 0x6D
	bl audio_play
	b _080BEFBA
	.pool
_080BEF78:
	ldrh r1, [r1, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080BEF96
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080BEFBA
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080BEFBA
_080BEF96:
	ldr r2, =gUnknown_02039B4C
	ldr r0, [r2]
	ldr r3, =0x0000064d
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _080BEFBA
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	movs r1, 0xD
	bl sub_80BFD0C
	movs r0, 0x6D
	bl audio_play
_080BEFBA:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BEDF4

	thumb_func_start sub_80BEFD0
sub_80BEFD0: @ 80BEFD0
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BF02C
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x10]
	bl sub_818D820
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080BF020
	cmp r0, 0x2
	ble _080BF008
	cmp r0, 0x3
	beq _080BF028
_080BF008:
	ldr r0, =sub_80BF0AC
	b _080BF02A
	.pool
_080BF020:
	ldr r0, =sub_80BF250
	b _080BF02A
	.pool
_080BF028:
	ldr r0, =sub_80BF82C
_080BF02A:
	str r0, [r4]
_080BF02C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BEFD0

	thumb_func_start sub_80BF038
sub_80BF038: @ 80BF038
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BF05E
	ldr r0, =gTasks
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x10]
	bl sub_818D820
	ldr r0, =sub_80BEA24
	str r0, [r4]
_080BF05E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF038

	thumb_func_start sub_80BF070
sub_80BF070: @ 80BF070
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BF09C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x10]
	bl sub_818D820
	bl sub_80BEDB0
	adds r0, r4, 0
	bl DestroyTask
_080BF09C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF070

	thumb_func_start sub_80BF0AC
sub_80BF0AC: @ 80BF0AC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r7, r2, r0
	ldrb r0, [r7]
	cmp r0, 0x1
	beq _080BF120
	cmp r0, 0x1
	ble _080BF0C8
	cmp r0, 0x2
	beq _080BF15C
_080BF0C8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _080BF196
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r1, =0x0000064a
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	ldr r1, =gUnknown_030060B4
	ldr r0, [r2, 0xC]
	str r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x80
	lsls r0, 2
	bl sub_80C09B0
	ldr r0, [r4]
	ldr r1, =0x0000064d
	adds r0, r1
	strb r5, [r0]
	movs r0, 0x1
	strb r0, [r7]
	b _080BF196
	.pool
_080BF120:
	movs r0, 0xD
	bl sub_80BFCF4
	movs r0, 0
	movs r1, 0xD
	bl sub_80BFD7C
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064c
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	bl sub_80BC844
	movs r1, 0xD0
	lsls r1, 4
	movs r0, 0xA
	bl SetGpuReg
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	b _080BF196
	.pool
_080BF15C:
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r0, [r0]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gUnknown_02039B4C
	ldr r1, [r5]
	ldr r4, =0x0000064e
	adds r1, r4
	bl sub_813D3D8
	ldr r0, =gUnknown_030060B4
	ldr r0, [r0]
	bl SetVBlankCallback
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	strb r1, [r0]
	strb r1, [r7]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BF1B4
	str r1, [r0]
_080BF196:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF0AC

	thumb_func_start sub_80BF1B4
sub_80BF1B4: @ 80BF1B4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BF1D6
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BF1EC
	str r0, [r1]
_080BF1D6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF1B4

	thumb_func_start sub_80BF1EC
sub_80BF1EC: @ 80BF1EC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BF242
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080BF210
	cmp r0, 0x2
	beq _080BF234
_080BF210:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BEA24
	b _080BF240
	.pool
_080BF234:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BF250
_080BF240:
	str r0, [r1]
_080BF242:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF1EC

	thumb_func_start sub_80BF250
sub_80BF250: @ 80BF250
	push {r4,r5,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0xA
	bhi _080BF2A8
	lsls r0, 2
	ldr r1, =_080BF27C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BF27C:
	.4byte _080BF2A8
	.4byte _080BF310
	.4byte _080BF360
	.4byte _080BF38C
	.4byte _080BF3A0
	.4byte _080BF3D0
	.4byte _080BF41C
	.4byte _080BF498
	.4byte _080BF514
	.4byte _080BF540
	.4byte _080BF590
_080BF2A8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BF2B6
	b _080BF5B2
_080BF2B6:
	ldr r0, =gMPlay_BGM
	bl m4aMPlayStop
	ldr r5, =gUnknown_02039B4C
	ldr r0, [r5]
	ldr r3, =0x0000064a
	adds r0, r3
	movs r1, 0x6
	strb r1, [r0]
	ldr r1, =gUnknown_030060B4
	ldr r4, =gMain
	ldr r0, [r4, 0xC]
	str r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x80
	lsls r0, 2
	bl sub_80C09B0
	ldr r0, [r5]
	ldr r1, =0x0000064d
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r2, 0x87
	lsls r2, 3
	adds r4, r2
	strb r1, [r4]
	b _080BF5B2
	.pool
_080BF310:
	ldr r1, =gUnknown_08DC1934
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08DC3198
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x3
	bl PutWindowTilemap
	movs r0, 0x2
	bl PutWindowTilemap
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _080BF582
	.pool
_080BF360:
	movs r0, 0xD
	bl sub_80BFCF4
	movs r0, 0x1
	movs r1, 0xD
	bl sub_80BFD7C
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r4, =0x0000064c
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	bl sub_80BC844
	b _080BF57A
	.pool
_080BF38C:
	bl ResetPaletteFade
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _080BF582
	.pool
_080BF3A0:
	ldr r0, =gUnknown_085E871B
	movs r1, 0x52
	movs r2, 0x21
	bl sub_80BE8DC
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, 0
	movs r2, 0x52
	movs r3, 0x31
	bl sub_80C0B44
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _080BF582
	.pool
_080BF3D0:
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r0, [r0]
	movs r1, 0x30
	movs r2, 0x38
	movs r3, 0
	bl sub_80C0E9C
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r2
	movs r3, 0
	strh r0, [r1, 0x10]
	ldr r2, =gSprites
	movs r4, 0x10
	ldrsh r0, [r1, r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_030061EC
	strb r3, [r0]
	b _080BF57A
	.pool
_080BF41C:
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	ldr r1, =0x00004020
	orrs r0, r1
	ldr r1, =0xff00ffff
	ands r0, r1
	movs r1, 0xF8
	lsls r1, 13
	orrs r0, r1
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 20
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r1, =0xffff00ff
	ldr r0, [sp, 0x8]
	ands r0, r1
	movs r1, 0xF0
	lsls r1, 5
	orrs r0, r1
	ldr r1, =0xffffff00
	ands r0, r1
	movs r1, 0xC
	orrs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	movs r1, 0x2
	bl sub_8145354
	lsls r0, 24
	cmp r0, 0
	bne _080BF462
	b _080BF5B2
_080BF462:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	ldr r0, =gUnknown_030061EC
	strb r2, [r0]
	b _080BF5B2
	.pool
_080BF498:
	ldr r1, =0x00ffffff
	ldr r0, [sp, 0xC]
	ands r0, r1
	movs r1, 0x90
	lsls r1, 20
	orrs r0, r1
	str r0, [sp, 0xC]
	ldr r2, =0xffffff00
	add r0, sp, 0xC
	ldr r1, [r0, 0x4]
	ands r1, r2
	movs r2, 0x12
	orrs r1, r2
	ldr r2, =0xffff00ff
	ands r1, r2
	movs r2, 0xC0
	lsls r2, 2
	orrs r1, r2
	str r1, [r0, 0x4]
	movs r1, 0x3
	bl sub_8145850
	lsls r0, 24
	cmp r0, 0
	beq _080BF4D8
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080BF4D8:
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080BF5B2
	.pool
_080BF514:
	movs r0, 0x15
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_030060B4
	ldr r0, [r0]
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r4, 0x87
	lsls r4, 3
	adds r1, r4
	b _080BF582
	.pool
_080BF540:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_080BF57A:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_080BF582:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080BF5B2
	.pool
_080BF590:
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	movs r3, 0x87
	lsls r3, 3
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BF5CC
	str r1, [r0]
_080BF5B2:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF250

	thumb_func_start sub_80BF5CC
sub_80BF5CC: @ 80BF5CC
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	bl sub_814545C
	bl sub_80A36EC
	lsls r0, 24
	cmp r0, 0
	beq _080BF5EC
	movs r0, 0x1
	bl sub_80BF7FC
	b _080BF5F2
_080BF5EC:
	movs r0, 0
	bl sub_80BF7FC
_080BF5F2:
	ldr r1, =gMain
	ldrh r2, [r1, 0x2E]
	movs r0, 0x1
	ands r0, r2
	adds r5, r1, 0
	cmp r0, 0
	beq _080BF624
	movs r0, 0x1
	bl sub_80BF7FC
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrh r0, [r0]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	bl sub_8145534
	b _080BF772
	.pool
_080BF624:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080BF636
	b _080BF772
_080BF636:
	movs r0, 0x2
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _080BF694
	movs r0, 0x15
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BF790
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
	b _080BF772
	.pool
_080BF694:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _080BF6B0
	movs r0, 0x80
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	beq _080BF700
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080BF700
_080BF6B0:
	movs r0, 0x15
	negs r0, r0
	str r3, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BF790
	str r1, [r0]
	movs r0, 0x6D
	bl audio_play
	b _080BF772
	.pool
_080BF700:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080BF71E
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080BF772
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080BF772
_080BF71E:
	ldr r0, =gUnknown_02039B54
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080BF73C
	movs r0, 0x20
	bl audio_play
	b _080BF772
	.pool
_080BF73C:
	movs r0, 0x15
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BF790
	str r1, [r0]
	movs r0, 0x6D
	bl audio_play
_080BF772:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF5CC

	thumb_func_start sub_80BF790
sub_80BF790: @ 80BF790
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BF7F0
	bl sub_8145914
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x10]
	bl sub_818D820
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080BF7E4
	cmp r0, 0x2
	ble _080BF7CC
	cmp r0, 0x3
	beq _080BF7EC
_080BF7CC:
	ldr r0, =sub_80BEA24
	b _080BF7EE
	.pool
_080BF7E4:
	ldr r0, =sub_80BF0AC
	b _080BF7EE
	.pool
_080BF7EC:
	ldr r0, =sub_80BF82C
_080BF7EE:
	str r0, [r4]
_080BF7F0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF790

	thumb_func_start sub_80BF7FC
sub_80BF7FC: @ 80BF7FC
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	beq _080BF810
	ldr r1, =0x00000392
	b _080BF812
	.pool
_080BF810:
	ldr r1, =0x000002af
_080BF812:
	mov r0, sp
	strh r1, [r0]
	mov r0, sp
	movs r1, 0x5D
	movs r2, 0x2
	bl LoadPalette
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF7FC

	thumb_func_start sub_80BF82C
sub_80BF82C: @ 80BF82C
	push {r4-r7,lr}
	sub sp, 0x44
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x9
	bhi _080BF880
	lsls r0, 2
	ldr r1, =_080BF858
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BF858:
	.4byte _080BF880
	.4byte _080BF8D8
	.4byte _080BF910
	.4byte _080BF93C
	.4byte _080BF97C
	.4byte _080BF982
	.4byte _080BFA34
	.4byte _080BFAE8
	.4byte _080BFB14
	.4byte _080BFB64
_080BF880:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BF88E
	b _080BFB94
_080BF88E:
	ldr r4, =gUnknown_02039B4C
	ldr r0, [r4]
	ldr r1, =0x0000064a
	adds r0, r1
	movs r1, 0x7
	strb r1, [r0]
	ldr r1, =gUnknown_030060B4
	ldr r0, [r5, 0xC]
	str r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x80
	lsls r0, 2
	bl sub_80C09B0
	ldr r0, [r4]
	ldr r2, =0x0000064d
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0x87
	lsls r0, 3
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
	b _080BFB94
	.pool
_080BF8D8:
	ldr r1, =gUnknown_08DC1934
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08DC2E6C
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	b _080BFB4E
	.pool
_080BF910:
	movs r0, 0xD
	bl sub_80BFCF4
	movs r0, 0x2
	movs r1, 0xD
	bl sub_80BFD7C
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064c
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	bl sub_80BC844
	b _080BFB4E
	.pool
_080BF93C:
	ldr r1, =gUnknown_085E8723
	add r0, sp, 0x4
	bl StringCopy
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	add r0, sp, 0x4
	bl StringAppend
	movs r0, 0x1
	add r1, sp, 0x4
	movs r2, 0xF0
	bl GetStringCenterAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	add r0, sp, 0x4
	movs r2, 0x79
	bl sub_80BE8DC
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BFB56
	.pool
_080BF97C:
	bl ResetPaletteFade
	b _080BFB4E
_080BF982:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl sub_806F000
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x98
	movs r2, 0x38
	movs r3, 0
	bl sub_80C0EF8
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gSprites
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	adds r4, r0
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x5]
	ldr r2, =gPokedexEntries
	ldr r0, =gUnknown_02039B54
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, 5
	adds r0, r2
	ldrh r0, [r0, 0x1C]
	strh r0, [r4, 0x26]
	ldrh r0, [r1]
	lsls r0, 5
	adds r0, r2
	ldrh r1, [r0, 0x1A]
	str r1, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldr r0, =gUnknown_0856E610
	ldrb r1, [r4, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0x12]
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BFB56
	.pool
_080BFA34:
	ldr r5, =gUnknown_02039B54
	ldr r0, [r5]
	ldrh r0, [r0]
	movs r1, 0x58
	movs r2, 0x38
	movs r3, 0x1
	bl sub_80C0E9C
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gSprites
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	adds r4, r0
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x5]
	ldr r2, =gPokedexEntries
	ldr r1, [r5]
	ldrh r0, [r1]
	lsls r0, 5
	adds r0, r2
	ldrh r0, [r0, 0x18]
	strh r0, [r4, 0x26]
	ldrh r0, [r1]
	lsls r0, 5
	adds r0, r2
	ldrh r1, [r0, 0x16]
	str r1, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldr r0, =gUnknown_0856E610
	ldrb r1, [r4, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0x10]
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080BFB4E
	.pool
_080BFAE8:
	movs r0, 0x15
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_030060B4
	ldr r0, [r0]
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BFB56
	.pool
_080BFB14:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_080BFB4E:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_080BFB56:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080BFB94
	.pool
_080BFB64:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080BFB94
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	strb r2, [r0]
	movs r1, 0x87
	lsls r1, 3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BFBB0
	str r1, [r0]
_080BFB94:
	add sp, 0x44
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BF82C

	thumb_func_start sub_80BFBB0
sub_80BFBB0: @ 80BFBB0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _080BFC10
	movs r0, 0x15
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BFC78
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
	b _080BFC5C
	.pool
_080BFC10:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080BFC2C
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080BFC5C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080BFC5C
_080BFC2C:
	movs r0, 0x15
	negs r0, r0
	str r2, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80BFC78
	str r1, [r0]
	movs r0, 0x6D
	bl audio_play
_080BFC5C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFBB0

	thumb_func_start sub_80BFC78
sub_80BFC78: @ 80BFC78
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BFCD0
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x10]
	bl sub_818D820
	ldrh r0, [r4, 0x12]
	bl sub_818D8F0
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064e
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080BFCB2
	cmp r0, 0x2
	beq _080BFCCC
_080BFCB2:
	ldr r0, =sub_80BEA24
	b _080BFCCE
	.pool
_080BFCCC:
	ldr r0, =sub_80BF250
_080BFCCE:
	str r0, [r4]
_080BFCD0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFC78

	thumb_func_start sub_80BFCDC
sub_80BFCDC: @ 80BFCDC
	push {lr}
	ldr r1, =gUnknown_08DC2F5C
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFCDC

	thumb_func_start sub_80BFCF4
sub_80BFCF4: @ 80BFCF4
	push {lr}
	ldr r1, =gUnknown_08DC2FEC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFCF4

	thumb_func_start sub_80BFD0C
sub_80BFD0C: @ 80BFD0C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x1
	bl GetBgTilemapBuffer
	adds r7, r0, 0
	movs r1, 0
_080BFD22:
	lsls r0, r1, 3
	subs r0, r1
	adds r0, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0x80
	lsls r3, 7
	cmp r1, r8
	bne _080BFD38
	movs r3, 0x80
	lsls r3, 6
_080BFD38:
	movs r2, 0
	adds r6, r1, 0x1
	ldr r4, =0x00000fff
_080BFD3E:
	adds r1, r5, r2
	lsls r1, 1
	adds r1, r7
	ldrh r0, [r1]
	ands r0, r4
	orrs r0, r3
	strh r0, [r1]
	adds r1, 0x40
	ldrh r0, [r1]
	ands r0, r4
	orrs r0, r3
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x6
	bls _080BFD3E
	lsls r0, r6, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _080BFD22
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFD0C

	thumb_func_start sub_80BFD7C
sub_80BFD7C: @ 80BFD7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x1
	bl GetBgTilemapBuffer
	adds r7, r0, 0
	movs r1, 0
_080BFD92:
	lsls r0, r1, 3
	subs r0, r1
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r1, r8
	beq _080BFDA4
	cmp r1, 0x3
	bne _080BFDAA
_080BFDA4:
	movs r3, 0x80
	lsls r3, 6
	b _080BFDAE
_080BFDAA:
	movs r3, 0x80
	lsls r3, 7
_080BFDAE:
	movs r2, 0
	adds r5, r1, 0x1
	ldr r4, =0x00000fff
_080BFDB4:
	adds r1, r6, r2
	lsls r1, 1
	adds r1, r7
	ldrh r0, [r1]
	ands r0, r4
	orrs r0, r3
	strh r0, [r1]
	adds r1, 0x40
	ldrh r0, [r1]
	ands r0, r4
	orrs r0, r3
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x6
	bls _080BFDB4
	lsls r0, r5, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _080BFD92
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFD7C

	thumb_func_start sub_80BFDF4
sub_80BFDF4: @ 80BFDF4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =sub_80BFE38
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	strh r4, [r1, 0xA]
	strh r5, [r1, 0x20]
	lsrs r5, 16
	strh r5, [r1, 0x22]
	strh r6, [r1, 0x24]
	lsrs r6, 16
	strh r6, [r1, 0x26]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BFDF4

	thumb_func_start sub_80BFE38
sub_80BFE38: @ 80BFE38
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r4, [r0, 0xA]
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080BFE84
	lsls r0, 2
	ldr r1, =_080BFE68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BFE68:
	.4byte _080BFE84
	.4byte _080BFF0C
	.4byte _080BFF78
	.4byte _080BFF82
	.4byte _080BFFA8
	.4byte _080C0000
	.4byte _080C0044
_080BFE84:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BFE92
	b _080C0074
_080BFE92:
	ldr r1, =gUnknown_030060B4
	ldr r0, =gMain
	ldr r0, [r0, 0xC]
	str r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x80
	lsls r0, 1
	bl sub_80C09B0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0856E668
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_0856E670
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	b _080C0074
	.pool
_080BFF0C:
	ldr r1, =gUnknown_08DC1934
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08DC3080
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrh r1, [r4, 0xA]
	movs r0, 0x1
	bl sub_80C0D30
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	bl ResetPaletteFade
	movs r0, 0
	bl sub_80BC844
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080C0074
	.pool
_080BFF78:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	b _080C0038
_080BFF82:
	bl sub_809D42C
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80C020C
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080C002E
_080BFFA8:
	adds r0, r4, 0
	movs r1, 0x30
	movs r2, 0x38
	movs r3, 0
	bl sub_80C0E9C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_030060B4
	ldr r0, [r0]
	bl SetVBlankCallback
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0xE]
	b _080C0038
	.pool
_080C0000:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_080C002E:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
_080C0038:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080C0074
	.pool
_080C0044:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _080C0074
	adds r0, r4, 0
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl cry_related
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0xC]
	ldr r1, =sub_80C0088
	str r1, [r0]
_080C0074:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BFE38

	thumb_func_start sub_80C0088
sub_80C0088: @ 80C0088
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080C00E8
	ldr r0, =0x0000ffff
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r3, =gSprites
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r2, =sub_80C01CC
	str r2, [r0]
	ldr r0, =blockset_load_palette_to_gpu
	str r0, [r1]
	b _080C011E
	.pool
_080C00E8:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0xC]
	adds r1, 0x1
	strh r1, [r0, 0xC]
	movs r0, 0x10
	ands r1, r0
	cmp r1, 0
	beq _080C0114
	ldr r0, =gUnknown_08DC16F6
	movs r1, 0x31
	movs r2, 0xE
	bl LoadPalette
	b _080C011E
	.pool
_080C0114:
	ldr r0, =gUnknown_08DC1756
	movs r1, 0x31
	movs r2, 0xE
	bl LoadPalette
_080C011E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C0088

	thumb_func_start blockset_load_palette_to_gpu
blockset_load_palette_to_gpu: @ 80C012C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080C01BA
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	bl FreeAllWindowBuffers
	movs r0, 0x2
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080C015A
	bl Free
_080C015A:
	movs r0, 0x3
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080C0168
	bl Free
_080C0168:
	ldr r0, =gTasks
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0xA]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0x22]
	lsls r1, 16
	ldrh r2, [r4, 0x20]
	orrs r1, r2
	ldrh r2, [r4, 0x26]
	lsls r2, 16
	ldrh r3, [r4, 0x24]
	orrs r2, r3
	ldr r5, =gSprites
	movs r3, 0xE
	ldrsh r4, [r4, r3]
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r3, r5
	ldrb r4, [r3, 0x5]
	lsrs r4, 4
	bl species_and_otid_get_pal
	lsls r4, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r4, r1
	adds r1, r4, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	adds r0, r6, 0
	bl DestroyTask
_080C01BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end blockset_load_palette_to_gpu

	thumb_func_start sub_80C01CC
sub_80C01CC: @ 80C01CC
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x77
	bgt _080C01DE
	adds r0, r2, 0x2
	strh r0, [r1, 0x20]
_080C01DE:
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x78
	ble _080C01EC
	subs r0, r2, 0x2
	strh r0, [r1, 0x20]
_080C01EC:
	ldrh r2, [r1, 0x22]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x4F
	bgt _080C01FA
	adds r0, r2, 0x1
	strh r0, [r1, 0x22]
_080C01FA:
	ldrh r2, [r1, 0x22]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x50
	ble _080C0208
	subs r0, r2, 0x1
	strh r0, [r1, 0x22]
_080C0208:
	pop {r0}
	bx r0
	thumb_func_end sub_80C01CC

	thumb_func_start sub_80C020C
sub_80C020C: @ 80C020C
	push {r4-r7,lr}
	sub sp, 0x30
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	cmp r3, 0
	beq _080C0234
	ldr r4, =gUnknown_085E8735
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xF0
	bl GetStringCenterAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_80BE8DC
_080C0234:
	cmp r5, 0
	bne _080C024C
	lsls r4, r6, 16
	lsrs r0, r4, 16
	bl NationalToHoennOrder
	lsls r0, 16
	lsrs r5, r0, 16
	b _080C0250
	.pool
_080C024C:
	adds r5, r6, 0
	lsls r4, r6, 16
_080C0250:
	ldr r1, =gUnknown_085E8D4F
	mov r0, sp
	bl StringCopy
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r0, sp
	movs r1, 0x60
	movs r2, 0x19
	bl sub_80BE8DC
	lsrs r0, r4, 16
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080C028C
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r0, r1, r0
	b _080C028E
	.pool
_080C028C:
	ldr r0, =gUnknown_0856E688
_080C028E:
	movs r1, 0x84
	movs r2, 0x19
	bl sub_80BE8DC
	cmp r7, 0
	beq _080C02AC
	add r4, sp, 0x10
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81DB468
	adds r0, r4, 0
	b _080C02AE
	.pool
_080C02AC:
	ldr r0, =gUnknown_085E86B8
_080C02AE:
	movs r1, 0x64
	movs r2, 0x29
	bl sub_80BE8DC
	ldr r0, =gUnknown_085E8755
	movs r1, 0x60
	movs r2, 0x39
	bl sub_80BE8DC
	ldr r0, =gUnknown_085E8758
	movs r1, 0x60
	movs r2, 0x49
	bl sub_80BE8DC
	cmp r7, 0
	beq _080C02FC
	ldr r0, =gPokedexEntries
	lsls r4, r6, 5
	adds r4, r0
	ldrh r0, [r4, 0xC]
	movs r1, 0x81
	movs r2, 0x39
	bl sub_80C0354
	ldrh r0, [r4, 0xE]
	movs r1, 0x81
	movs r2, 0x49
	bl sub_80C0460
	b _080C0310
	.pool
_080C02FC:
	ldr r0, =gUnknown_085E86C6
	movs r1, 0x81
	movs r2, 0x39
	bl sub_80BE8DC
	ldr r0, =gUnknown_085E86D0
	movs r1, 0x81
	movs r2, 0x49
	bl sub_80BE8DC
_080C0310:
	cmp r7, 0
	beq _080C032C
	ldr r0, =gPokedexEntries
	lsls r1, r6, 5
	adds r0, 0x10
	adds r1, r0
	ldr r4, [r1]
	b _080C032E
	.pool
_080C032C:
	ldr r4, =gUnknown_0855D30C
_080C032E:
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xF0
	bl GetStringCenterAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x5F
	bl sub_80BE8DC
	add sp, 0x30
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C020C

	thumb_func_start sub_80C0354
sub_80C0354: @ 80C0354
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r1, =0x00002710
	muls r0, r1
	movs r1, 0xFE
	bl __divsi3
	adds r7, r0, 0
	movs r1, 0xA
	bl __umodsi3
	cmp r0, 0x4
	bls _080C0386
	adds r7, 0xA
_080C0386:
	adds r0, r7, 0
	movs r1, 0x78
	bl __udivsi3
	adds r6, r0, 0
	lsls r0, r6, 4
	subs r0, r6
	lsls r0, 3
	subs r0, r7, r0
	movs r1, 0xA
	bl __udivsi3
	adds r7, r0, 0
	mov r1, sp
	movs r0, 0xFC
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x13
	strb r0, [r1]
	adds r0, r6, 0
	movs r1, 0xA
	bl __udivsi3
	adds r2, r0, 0
	cmp r2, 0
	bne _080C03D4
	mov r1, sp
	adds r1, 0x2
	movs r0, 0x12
	strb r0, [r1]
	movs r5, 0x4
	adds r1, 0x1
	adds r0, r6, 0
	adds r0, 0xA1
	strb r0, [r1]
	b _080C03F4
	.pool
_080C03D4:
	mov r1, sp
	adds r1, 0x2
	movs r0, 0xC
	strb r0, [r1]
	adds r1, 0x1
	adds r0, r2, 0
	adds r0, 0xA1
	strb r0, [r1]
	movs r5, 0x5
	add r4, sp, 0x4
	adds r0, r6, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r4]
_080C03F4:
	adds r1, r5, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	add r1, sp
	movs r0, 0xB4
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	mov r0, sp
	adds r4, r0, r2
	adds r0, r7, 0
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, sp
	adds r4, r1, r6
	adds r0, r7, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	adds r2, r1, r5
	movs r1, 0xB2
	strb r1, [r2]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0xFF
	strb r0, [r1]
	mov r0, sp
	mov r1, r9
	mov r2, r8
	bl sub_80BE8DC
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C0354

	thumb_func_start sub_80C0460
sub_80C0460: @ 80C0460
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x10]
	ldr r5, =0x000186a0
	muls r0, r5
	ldr r1, =0x000011b8
	bl __divsi3
	adds r7, r0, 0
	movs r1, 0xA
	bl __umodsi3
	cmp r0, 0x4
	bls _080C0494
	adds r7, 0xA
_080C0494:
	movs r0, 0
	mov r8, r0
	mov r4, sp
	adds r0, r7, 0
	adds r1, r5, 0
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA1
	bne _080C04C0
	movs r6, 0x1
	mov r1, sp
	movs r0, 0x77
	strb r0, [r1]
	b _080C04C6
	.pool
_080C04C0:
	movs r1, 0x1
	mov r8, r1
	movs r6, 0x1
_080C04C6:
	ldr r1, =0x000186a0
	adds r0, r7, 0
	bl __umodsi3
	adds r7, r0, 0
	mov r4, sp
	adds r4, 0x1
	ldr r1, =0x00002710
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA1
	bne _080C0504
	mov r2, r8
	cmp r2, 0
	bne _080C0504
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	add r1, sp
	movs r0, 0x77
	strb r0, [r1]
	b _080C050E
	.pool
_080C0504:
	movs r3, 0x1
	mov r8, r3
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080C050E:
	ldr r1, =0x00002710
	adds r0, r7, 0
	bl __umodsi3
	adds r7, r0, 0
	mov r0, sp
	adds r4, r0, r6
	movs r1, 0xFA
	lsls r1, 2
	adds r0, r7, 0
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA1
	bne _080C054C
	mov r1, r8
	cmp r1, 0
	bne _080C054C
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	add r1, sp
	movs r0, 0x77
	strb r0, [r1]
	b _080C0552
	.pool
_080C054C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080C0552:
	movs r1, 0xFA
	lsls r1, 2
	adds r0, r7, 0
	bl __umodsi3
	adds r7, r0, 0
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r5, r6, 0
	mov r2, sp
	adds r4, r2, r1
	adds r0, r7, 0
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	movs r3, 0
	mov r9, r3
	strb r0, [r4]
	adds r0, r7, 0
	movs r1, 0x64
	bl __umodsi3
	adds r7, r0, 0
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r1, r6, 0
	mov r2, sp
	adds r0, r2, r5
	movs r3, 0xAD
	mov r8, r3
	mov r2, r8
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r5, r6, 0
	mov r3, sp
	adds r4, r3, r1
	adds r0, r7, 0
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r1, r6, 0
	mov r2, sp
	adds r0, r2, r5
	mov r3, r9
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r2, r6, 0
	add r1, sp
	movs r0, 0xE0
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r3, r6, 0
	mov r0, sp
	adds r1, r0, r2
	movs r0, 0xD6
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r2, r6, 0
	mov r0, sp
	adds r1, r0, r3
	movs r0, 0xE7
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r3, sp
	adds r1, r3, r2
	mov r2, r8
	strb r2, [r1]
	adds r1, r3, r0
	movs r0, 0xFF
	strb r0, [r1]
	mov r0, sp
	mov r1, r10
	ldr r2, [sp, 0x10]
	bl sub_80BE8DC
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C0460

	thumb_func_start sub_80C0620
sub_80C0620: @ 80C0620
	lsls r0, 16
	lsrs r0, 11
	ldr r1, =gPokedexEntries
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_80C0620

	thumb_func_start sub_80C0630
sub_80C0630: @ 80C0630
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	beq _080C0646
	cmp r1, 0x1
	beq _080C0654
	movs r0, 0x1
	b _080C065C
_080C0646:
	ldr r0, =gPokedexEntries
	lsls r1, r2, 5
	adds r1, r0
	ldrh r0, [r1, 0xC]
	b _080C065C
	.pool
_080C0654:
	ldr r0, =gPokedexEntries
	lsls r1, r2, 5
	adds r1, r0
	ldrh r0, [r1, 0xE]
_080C065C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C0630

	thumb_func_start pokedex_flag_operation
@ u8 pokedex_flag_operation(u16 nationalPokedexNum, u8 op)
pokedex_flag_operation: @ 80C0664
	push {r4-r7,lr}
	lsls r0, 16
	lsls r1, 24
	lsrs r2, r1, 24
	adds r3, r2, 0
	ldr r1, =0xffff0000
	adds r0, r1
	lsrs r1, r0, 16
	lsrs r0, 19
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x7
	ands r1, r0
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r5, r0, 24
	movs r6, 0
	cmp r2, 0x1
	beq _080C06FC
	cmp r2, 0x1
	bgt _080C069C
	cmp r2, 0
	beq _080C06AA
	b _080C07E8
	.pool
_080C069C:
	cmp r3, 0x2
	bne _080C06A2
	b _080C079C
_080C06A2:
	cmp r3, 0x3
	bne _080C06A8
	b _080C07D8
_080C06A8:
	b _080C07E8
_080C06AA:
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	adds r0, 0x5C
	adds r0, r4
	ldrb r2, [r0]
	ands r2, r5
	adds r7, r1, 0
	cmp r2, 0
	bne _080C06BE
	b _080C07E8
_080C06BE:
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r6, =0x00000988
	adds r1, r3, r6
	adds r1, r4
	ldrb r1, [r1]
	ands r1, r5
	adds r6, r0, 0
	cmp r2, r1
	bne _080C06E0
	ldr r1, =0x00003b24
	adds r0, r3, r1
	adds r0, r4
	ldrb r0, [r0]
	ands r0, r5
	cmp r2, r0
	beq _080C073E
_080C06E0:
	ldr r1, [r7]
	adds r1, 0x5C
	adds r1, r4
	mvns r3, r5
	b _080C076A
	.pool
_080C06FC:
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	adds r0, r3, 0
	adds r0, 0x28
	adds r0, r4
	ldrb r2, [r0]
	ands r2, r5
	adds r7, r1, 0
	cmp r2, 0
	beq _080C07E8
	adds r0, r3, 0
	adds r0, 0x5C
	adds r0, r4
	ldrb r0, [r0]
	ands r0, r5
	ldr r6, =gSaveBlock1Ptr
	cmp r2, r0
	bne _080C0754
	ldr r1, [r6]
	ldr r3, =0x00000988
	adds r0, r1, r3
	adds r0, r4
	ldrb r0, [r0]
	ands r0, r5
	cmp r2, r0
	bne _080C0754
	ldr r3, =0x00003b24
	adds r0, r1, r3
	adds r0, r4
	ldrb r0, [r0]
	ands r0, r5
	cmp r2, r0
	bne _080C0754
_080C073E:
	movs r6, 0x1
	b _080C07E8
	.pool
_080C0754:
	ldr r1, [r7]
	adds r1, 0x28
	adds r1, r4
	mvns r3, r5
	ldrb r2, [r1]
	adds r0, r3, 0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, 0x5C
	adds r1, r4
_080C076A:
	ldrb r2, [r1]
	adds r0, r3, 0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	ldr r0, =0x00000988
	adds r1, r0
	adds r1, r4
	ldrb r2, [r1]
	adds r0, r3, 0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, =0x00003b24
	adds r0, r1
	adds r0, r4
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	movs r6, 0
	b _080C07E8
	.pool
_080C079C:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, 0x5C
	adds r1, r4
	ldrb r2, [r1]
	adds r0, r5, 0
	orrs r0, r2
	strb r0, [r1]
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	ldr r0, =0x00000988
	adds r1, r0
	adds r1, r4
	ldrb r2, [r1]
	adds r0, r5, 0
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	ldr r3, =0x00003b24
	adds r1, r3
	b _080C07DE
	.pool
_080C07D8:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, 0x28
_080C07DE:
	adds r1, r4
	ldrb r2, [r1]
	adds r0, r5, 0
	orrs r0, r2
	strb r0, [r1]
_080C07E8:
	adds r0, r6, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pokedex_flag_operation

	thumb_func_start pokedex_count
pokedex_count: @ 80C07F4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0
	ldr r7, =0x00000181
_080C0800:
	cmp r6, 0
	beq _080C0810
	cmp r6, 0x1
	beq _080C081A
	adds r4, r0, 0x1
	b _080C0832
	.pool
_080C0810:
	adds r4, r0, 0x1
	lsls r0, r4, 16
	lsrs r0, 16
	movs r1, 0
	b _080C0822
_080C081A:
	adds r4, r0, 0x1
	lsls r0, r4, 16
	lsrs r0, 16
	movs r1, 0x1
_080C0822:
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080C0832
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080C0832:
	lsls r0, r4, 16
	lsrs r0, 16
	cmp r0, r7
	bls _080C0800
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end pokedex_count

	thumb_func_start sub_80C0844
sub_80C0844: @ 80C0844
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0
_080C084E:
	cmp r6, 0
	beq _080C085A
	cmp r6, 0x1
	beq _080C086C
	adds r4, r0, 0x1
	b _080C088C
_080C085A:
	adds r4, r0, 0x1
	lsls r0, r4, 16
	lsrs r0, 16
	bl HoennToNationalOrder
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	b _080C087C
_080C086C:
	adds r4, r0, 0x1
	lsls r0, r4, 16
	lsrs r0, 16
	bl HoennToNationalOrder
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
_080C087C:
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080C088C
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080C088C:
	lsls r0, r4, 16
	lsrs r0, 16
	cmp r0, 0xC9
	bls _080C084E
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80C0844

	thumb_func_start sub_80C089C
sub_80C089C: @ 80C089C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0
_080C08A6:
	cmp r6, 0
	beq _080C08B2
	cmp r6, 0x1
	beq _080C08BC
	adds r4, r0, 0x1
	b _080C08D4
_080C08B2:
	adds r4, r0, 0x1
	lsls r0, r4, 16
	lsrs r0, 16
	movs r1, 0
	b _080C08C4
_080C08BC:
	adds r4, r0, 0x1
	lsls r0, r4, 16
	lsrs r0, 16
	movs r1, 0x1
_080C08C4:
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080C08D4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080C08D4:
	lsls r0, r4, 16
	lsrs r0, 16
	cmp r0, 0x96
	bls _080C08A6
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80C089C

	thumb_func_start sub_80C08E4
sub_80C08E4: @ 80C08E4
	push {r4,lr}
	movs r0, 0
_080C08E8:
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl HoennToNationalOrder
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	bne _080C0908
	movs r0, 0
	b _080C0910
_080C0908:
	adds r0, r4, 0
	cmp r0, 0xC7
	bls _080C08E8
	movs r0, 0x1
_080C0910:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C08E4

	thumb_func_start sub_80C0918
sub_80C0918: @ 80C0918
	push {r4,lr}
	movs r0, 0
_080C091C:
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	bne _080C0934
	movs r0, 0
	b _080C093C
_080C0934:
	adds r0, r4, 0
	cmp r0, 0x95
	bls _080C091C
	movs r0, 0x1
_080C093C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C0918

	thumb_func_start sub_80C0944
sub_80C0944: @ 80C0944
	push {r4,r5,lr}
	movs r0, 0
_080C0948:
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080C0996
	adds r0, r4, 0
	cmp r0, 0x95
	bls _080C0948
	movs r0, 0x97
_080C0964:
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _080C0996
	adds r0, r4, 0
	cmp r0, 0xF7
	bls _080C0964
	movs r0, 0xFB
	ldr r5, =0x0000017f
_080C0982:
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	bne _080C09A0
_080C0996:
	movs r0, 0
	b _080C09A8
	.pool
_080C09A0:
	adds r0, r4, 0
	cmp r0, r5
	bls _080C0982
	movs r0, 0x1
_080C09A8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80C0944

	thumb_func_start sub_80C09B0
sub_80C09B0: @ 80C09B0
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080C09E2
	movs r0, 0
	bl ClearGpuRegBits
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
_080C09E2:
	movs r1, 0x80
	lsls r1, 2
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080C0A0C
	movs r0, 0
	bl ClearGpuRegBits
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
_080C0A0C:
	movs r1, 0x80
	lsls r1, 3
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080C0A36
	movs r0, 0
	bl ClearGpuRegBits
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
_080C0A36:
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080C0A60
	movs r0, 0
	bl ClearGpuRegBits
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
_080C0A60:
	movs r1, 0x80
	lsls r1, 5
	ands r5, r1
	cmp r5, 0
	bne _080C0A7E
	movs r0, 0
	bl ClearGpuRegBits
	bl ResetSpriteData
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x8
	strb r0, [r1]
_080C0A7E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C09B0

	thumb_func_start sub_80C0A88
sub_80C0A88: @ 80C0A88
	push {r4-r6,lr}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	add r4, sp, 0x14
	movs r6, 0
	strb r6, [r4]
	adds r5, r4, 0
	movs r4, 0xF
	strb r4, [r5, 0x1]
	movs r4, 0x3
	strb r4, [r5, 0x2]
	str r6, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	subs r4, 0x4
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80C0A88

	thumb_func_start sub_80C0AC4
sub_80C0AC4: @ 80C0AC4
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	mov r9, r3
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r5, sp
	adds r0, r4, 0
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5]
	mov r5, sp
	adds r0, r4, 0
	movs r1, 0x64
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x1]
	mov r5, sp
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x2]
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	adds r0, r6, 0
	mov r2, r8
	mov r3, r9
	bl sub_80C0A88
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80C0AC4

	thumb_func_start sub_80C0B44
sub_80C0B44: @ 80C0B44
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	movs r4, 0
	movs r2, 0xFF
_080C0B62:
	mov r1, sp
	adds r0, r1, r4
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xA
	bls _080C0B62
	adds r0, r5, 0
	bl NationalPokedexNumToSpecies
	adds r5, r0, 0
	cmp r5, 0
	beq _080C0BC0
	movs r4, 0
	ldr r2, =gSpeciesNames
	movs r0, 0xB
	adds r1, r5, 0
	muls r1, r0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080C0BD4
	adds r3, r2, 0
	adds r2, r1, 0
_080C0B98:
	mov r0, sp
	adds r1, r0, r4
	adds r0, r4, r2
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, r2
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080C0BD4
	cmp r4, 0x9
	bls _080C0B98
	b _080C0BD4
	.pool
_080C0BC0:
	movs r4, 0
	movs r1, 0xAE
_080C0BC4:
	mov r2, sp
	adds r0, r2, r4
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _080C0BC4
_080C0BD4:
	mov r0, r8
	mov r1, sp
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_80C0A88
	adds r0, r4, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80C0B44

	thumb_func_start sub_80C0BF0
sub_80C0BF0: @ 80C0BF0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	lsls r3, 24
	lsrs r5, r3, 24
	movs r2, 0
	movs r1, 0
_080C0C08:
	mov r3, sp
	adds r0, r3, r2
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xA
	bls _080C0C08
	movs r3, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _080C0C32
_080C0C20:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C0C32
	cmp r3, 0xA
	bls _080C0C20
_080C0C32:
	movs r2, 0
	cmp r2, r3
	bcs _080C0C52
_080C0C38:
	adds r0, r2, 0
	adds r0, 0xB
	subs r0, r3
	mov r7, sp
	adds r1, r7, r0
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r3
	bcc _080C0C38
_080C0C52:
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0xB]
	adds r0, r6, 0
	mov r2, r12
	adds r3, r5, 0
	bl sub_80C0A88
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C0BF0

	thumb_func_start sub_80C0C6C
sub_80C0C6C: @ 80C0C6C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	movs r5, 0
	movs r1, 0xFA
	lsls r1, 2
	adds r0, r4, 0
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080C0CA2
	mov r1, sp
	movs r0, 0x77
	strb r0, [r1]
	b _080C0CAA
_080C0CA2:
	mov r1, sp
	adds r0, 0xA1
	strb r0, [r1]
	movs r5, 0x1
_080C0CAA:
	movs r1, 0xFA
	lsls r1, 2
	adds r0, r4, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080C0CD0
	cmp r5, 0
	bne _080C0CD0
	mov r1, sp
	movs r0, 0x77
	b _080C0CD4
_080C0CD0:
	mov r1, sp
	adds r0, 0xA1
_080C0CD4:
	strb r0, [r1, 0x1]
	mov r5, sp
	movs r1, 0xFA
	lsls r1, 2
	adds r0, r4, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x2]
	mov r1, sp
	movs r0, 0xAD
	strb r0, [r1, 0x3]
	mov r5, sp
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x4]
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x5]
	mov r0, r8
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_80C0A88
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C0C6C

	thumb_func_start sub_80C0D30
sub_80C0D30: @ 80C0D30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gMonFootprintTable
	adds r0, r1, 0
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 14
	adds r0, r4
	ldr r0, [r0]
	mov r12, r0
	movs r5, 0
	movs r1, 0
	movs r7, 0x2
_080C0D5A:
	mov r2, r12
	adds r0, r2, r1
	ldrb r3, [r0]
	movs r4, 0
	adds r6, r1, 0x1
_080C0D64:
	lsls r2, r4, 1
	adds r1, r3, 0
	asrs r1, r2
	movs r0, 0x1
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r1, r0, 31
	ands r1, r7
	adds r0, r7, 0
	lsls r0, r2
	ands r0, r3
	cmp r0, 0
	beq _080C0D84
	movs r0, 0x20
	orrs r1, r0
_080C0D84:
	mov r2, sp
	adds r0, r2, r5
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _080C0D64
	lsls r0, r6, 16
	lsrs r1, r0, 16
	cmp r1, 0x1F
	bls _080C0D5A
	mov r0, r8
	mov r1, sp
	movs r2, 0x80
	movs r3, 0
	bl CopyToWindowPixelBuffer
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C0D30

	thumb_func_start sub_80C0DC0
sub_80C0DC0: @ 80C0DC0
	push {r4,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsrs r0, 5
	ldr r2, =0x06000232
	adds r3, r0, r2
	movs r4, 0xF0
	lsls r4, 8
	adds r2, r1, r4
	strh r2, [r3]
	ldr r2, =0x06000234
	adds r3, r0, r2
	adds r4, 0x1
	adds r2, r1, r4
	strh r2, [r3]
	ldr r2, =0x06000272
	adds r3, r0, r2
	adds r4, 0x1
	adds r2, r1, r4
	strh r2, [r3]
	ldr r2, =0x06000274
	adds r0, r2
	adds r4, 0x1
	adds r1, r4
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C0DC0

	thumb_func_start sub_80C0E0C
sub_80C0E0C: @ 80C0E0C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	cmp r4, 0x1
	beq _080C0E38
	cmp r4, 0x1
	bgt _080C0E2E
	cmp r4, 0
	beq _080C0E40
	b _080C0E60
_080C0E2E:
	cmp r5, 0x2
	beq _080C0E52
	cmp r5, 0x3
	beq _080C0E46
	b _080C0E60
_080C0E38:
	cmp r0, r2
	bls _080C0E60
	subs r0, 0x1
	b _080C0E58
_080C0E40:
	cmp r0, r3
	bcs _080C0E60
	b _080C0E56
_080C0E46:
	cmp r0, r2
	bls _080C0E4E
	subs r0, 0x1
	b _080C0E58
_080C0E4E:
	adds r0, r3, 0
	b _080C0E60
_080C0E52:
	cmp r0, r3
	bcs _080C0E5E
_080C0E56:
	adds r0, 0x1
_080C0E58:
	lsls r0, 16
	lsrs r0, 16
	b _080C0E60
_080C0E5E:
	adds r0, r2, 0
_080C0E60:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80C0E0C

	thumb_func_start sub_80C0E68
sub_80C0E68: @ 80C0E68
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xC9
	beq _080C0E88
	movs r0, 0x9A
	lsls r0, 1
	cmp r1, r0
	bne _080C0E94
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	b _080C0E96
	.pool
_080C0E88:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	b _080C0E96
	.pool
_080C0E94:
	movs r0, 0
_080C0E96:
	pop {r1}
	bx r1
	thumb_func_end sub_80C0E68

	thumb_func_start sub_80C0E9C
sub_80C0E9C: @ 80C0E9C
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	bl NationalPokedexNumToSpecies
	adds r1, r0, 0
	adds r0, r1, 0
	str r1, [sp, 0x10]
	bl sub_80C0E68
	adds r2, r0, 0
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x8]
	ldr r0, =0x0000ffff
	str r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	adds r0, r1, 0
	movs r1, 0x8
	movs r3, 0x1
	bl sub_818D7D8
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C0E9C

	thumb_func_start sub_80C0EF8
sub_80C0EF8: @ 80C0EF8
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	ldr r1, =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_818D8AC
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C0EF8

	thumb_func_start sub_80C0F30
sub_80C0F30: @ 80C0F30
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x8]
	lsls r5, 24
	lsrs r5, 24
	mov r10, r5
	bl sub_80BC8D4
	movs r5, 0
	movs r6, 0
	ldr r4, =0x00000181
	ldr r3, =gUnknown_02039B4C
_080C0F6A:
	ldr r2, [r3]
	lsls r0, r5, 2
	adds r1, r2, r0
	ldrb r0, [r1, 0x2]
	lsls r0, 31
	cmp r0, 0
	beq _080C0F86
	lsls r0, r6, 2
	adds r0, r2, r0
	ldr r1, [r1]
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080C0F86:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r4
	bls _080C0F6A
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	adds r1, r6, 0
	strh r6, [r0]
	cmp r7, 0xFF
	beq _080C103C
	movs r5, 0
	lsls r0, r1, 16
	movs r6, 0
	cmp r0, 0
	beq _080C1032
	lsls r7, 2
	ldr r0, =gUnknown_0856ED08
	adds r0, 0x3
	adds r0, r7, r0
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_0856ED08
	adds r0, r7
	mov r9, r0
_080C0FBA:
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	lsls r4, r5, 2
	adds r0, r4
	ldrh r0, [r0]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gSpeciesNames
	movs r0, 0xB
	muls r0, r2
	adds r0, r1
	ldrb r2, [r0]
	adds r3, r2, 0
	mov r0, r9
	ldrb r0, [r0]
	cmp r2, r0
	bcc _080C0FF2
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_0856ED08
	adds r1, 0x1
	adds r1, r7, r1
	ldrb r1, [r1]
	adds r0, r1
	cmp r2, r0
	blt _080C100A
_080C0FF2:
	ldr r0, =gUnknown_0856ED08
	adds r0, 0x2
	adds r0, r7, r0
	ldrb r2, [r0]
	cmp r3, r2
	bcc _080C101E
	ldrb r1, [r0]
	ldr r2, [sp, 0xC]
	ldrb r0, [r2]
	adds r1, r0
	cmp r3, r1
	bge _080C101E
_080C100A:
	ldr r2, =gUnknown_02039B4C
	ldr r0, [r2]
	lsls r1, r6, 2
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080C101E:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080C0FBA
_080C1032:
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	strh r6, [r0]
_080C103C:
	ldr r0, [sp, 0x4]
	cmp r0, 0xFF
	beq _080C10AC
	movs r5, 0
	movs r6, 0
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080C10A2
	adds r7, r1, 0
	ldr r0, =gBaseStats
	mov r8, r0
_080C105A:
	ldr r0, [r7]
	lsls r4, r5, 2
	adds r0, r4
	ldrh r0, [r0]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x19]
	lsls r0, 25
	lsrs r0, 25
	ldr r1, [sp, 0x4]
	cmp r1, r0
	bne _080C1090
	ldr r0, [r7]
	lsls r1, r6, 2
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080C1090:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [r7]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080C105A
_080C10A2:
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	strh r6, [r0]
_080C10AC:
	ldr r0, [sp, 0x8]
	cmp r0, 0xFF
	bne _080C10C2
	mov r1, r10
	cmp r1, 0xFF
	bne _080C10BA
	b _080C11DE
_080C10BA:
	mov r2, r10
	str r2, [sp, 0x8]
	movs r0, 0xFF
	mov r10, r0
_080C10C2:
	mov r1, r10
	cmp r1, 0xFF
	bne _080C1158
	movs r5, 0
	movs r6, 0
	ldr r2, =gUnknown_02039B4C
	ldr r0, [r2]
	ldr r1, =0x0000060c
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080C11D4
	adds r3, r2, 0
	mov r7, sp
	mov r8, r2
_080C10E0:
	ldr r0, [r3]
	lsls r4, r5, 2
	adds r1, r0, r4
	ldrb r0, [r1, 0x2]
	lsls r0, 30
	cmp r0, 0
	bge _080C112A
	ldrh r0, [r1]
	str r3, [sp, 0x10]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gBaseStats
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x6]
	strb r1, [r7]
	ldrb r0, [r0, 0x7]
	strb r0, [r7, 0x1]
	ldr r3, [sp, 0x10]
	ldr r2, [sp, 0x8]
	cmp r1, r2
	beq _080C1118
	cmp r0, r2
	bne _080C112A
_080C1118:
	ldr r0, [r3]
	lsls r1, r6, 2
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080C112A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080C10E0
	b _080C11D4
	.pool
_080C1158:
	movs r5, 0
	movs r6, 0
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080C11D4
	mov r7, sp
_080C116C:
	ldr r0, [r1]
	lsls r1, r5, 2
	adds r2, r0, r1
	ldrb r0, [r2, 0x2]
	lsls r0, 30
	adds r4, r1, 0
	cmp r0, 0
	bge _080C11C0
	ldrh r0, [r2]
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gBaseStats
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x6]
	strb r1, [r7]
	ldrb r0, [r0, 0x7]
	strb r0, [r7, 0x1]
	ldr r2, [sp, 0x8]
	cmp r1, r2
	bne _080C11A2
	cmp r0, r10
	beq _080C11AC
_080C11A2:
	cmp r1, r10
	bne _080C11C0
	ldr r1, [sp, 0x8]
	cmp r0, r1
	bne _080C11C0
_080C11AC:
	ldr r2, =gUnknown_02039B4C
	ldr r0, [r2]
	lsls r1, r6, 2
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080C11C0:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080C116C
_080C11D4:
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r0, r2
	strh r6, [r0]
_080C11DE:
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x0000060c
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C1232
	adds r5, r0, 0
	ldr r0, =0x00000181
	cmp r5, r0
	bhi _080C1232
	ldr r4, =gUnknown_02039B4C
	movs r1, 0x2
	negs r1, r1
	mov r10, r1
	movs r2, 0x3
	negs r2, r2
	mov r9, r2
	mov r8, r0
	ldr r0, =0x0000ffff
	adds r7, r0, 0
_080C1208:
	ldr r1, [r4]
	lsls r3, r5, 2
	adds r1, r3
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	ldrb r2, [r1, 0x2]
	mov r0, r10
	ands r0, r2
	strb r0, [r1, 0x2]
	ldr r1, [r4]
	adds r1, r3
	ldrb r2, [r1, 0x2]
	mov r0, r9
	ands r0, r2
	strb r0, [r1, 0x2]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bls _080C1208
_080C1232:
	adds r0, r6, 0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C0F30

	thumb_func_start sub_80C1258
sub_80C1258: @ 80C1258
	push {lr}
	ldr r0, =sub_80C12E0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C1258

	thumb_func_start sub_80C1270
sub_80C1270: @ 80C1270
	push {r4,r5,lr}
	sub sp, 0x18
	adds r5, r1, 0
	adds r3, r2, 0
	add r1, sp, 0x14
	movs r4, 0
	strb r4, [r1]
	adds r2, r1, 0
	movs r1, 0xF
	strb r1, [r2, 0x1]
	movs r1, 0x2
	strb r1, [r2, 0x2]
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	str r2, [sp, 0x8]
	subs r1, 0x3
	str r1, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80C1270

	thumb_func_start sub_80C12B0
sub_80C12B0: @ 80C12B0
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80C12B0

	thumb_func_start sub_80C12E0
sub_80C12E0: @ 80C12E0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x4
	bhi _080C1320
	lsls r0, 2
	ldr r1, =_080C130C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C130C:
	.4byte _080C1320
	.4byte _080C1414
	.4byte _080C1480
	.4byte _080C14A0
	.4byte _080C14F0
_080C1320:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _080C1332
	b _080C1516
_080C1332:
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000064a
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0
	bl sub_80C09B0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0856EFF8
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_0856F008
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl PutWindowTilemap
	ldr r1, =gUnknown_08DC3304
	movs r2, 0x80
	lsls r2, 6
	str r5, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	bl sub_809D42C
	cmp r0, 0
	bne _080C13E4
	ldr r1, =gUnknown_08DC3A0C
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	b _080C13F0
	.pool
_080C13E4:
	ldr r1, =gUnknown_08DC3870
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
_080C13F0:
	ldr r0, =gUnknown_08DC3286
	movs r1, 0x1
	movs r2, 0x7E
	bl LoadPalette
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _080C1516
	.pool
_080C1414:
	ldr r0, =gUnknown_0855D26C
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0855D27C
	bl LoadTaggedObjectPalettes
	adds r0, r4, 0
	bl sub_80C2594
	movs r1, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r2, r0, 3
	ldr r5, =gTasks + 0x8
	movs r3, 0
_080C1432:
	lsls r0, r1, 1
	adds r0, r2
	adds r0, r5
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xF
	bls _080C1432
	adds r0, r4, 0
	bl sub_80C23B8
	movs r0, 0
	bl sub_80C2040
	adds r0, r4, 0
	bl sub_80C20F8
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080C14DA
	.pool
_080C1480:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _080C14E2
	.pool
_080C14A0:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_080C14DA:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_080C14E2:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C1516
	.pool
_080C14F0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080C1516
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80C1570
	str r1, [r0]
	movs r1, 0x87
	lsls r1, 3
	adds r0, r3, r1
	strb r2, [r0]
_080C1516:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C12E0

	thumb_func_start sub_80C152C
sub_80C152C: @ 80C152C
	push {lr}
	bl FreeAllWindowBuffers
	movs r0, 0
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080C1540
	bl Free
_080C1540:
	movs r0, 0x1
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080C154E
	bl Free
_080C154E:
	movs r0, 0x2
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080C155C
	bl Free
_080C155C:
	movs r0, 0x3
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _080C156A
	bl Free
_080C156A:
	pop {r0}
	bx r0
	thumb_func_end sub_80C152C

	thumb_func_start sub_80C1570
sub_80C1570: @ 80C1570
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r0
	ldrb r0, [r5, 0x8]
	bl sub_80C2040
	adds r0, r4, 0
	bl sub_80C20F8
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, =sub_80C15B0
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1570

	thumb_func_start sub_80C15B0
sub_80C15B0: @ 80C15B0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080C15E4
	movs r0, 0x3
	bl audio_play
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80C1D38
	str r0, [r1]
	b _080C16BC
	.pool
_080C15E4:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C1640
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r4, [r5, r0]
	cmp r4, 0x1
	beq _080C161C
	cmp r4, 0x1
	bgt _080C160C
	cmp r4, 0
	beq _080C1612
	b _080C16BC
	.pool
_080C160C:
	cmp r4, 0x2
	beq _080C1630
	b _080C16BC
_080C1612:
	movs r0, 0x15
	bl audio_play
	strh r4, [r5, 0xA]
	b _080C1626
_080C161C:
	movs r0, 0x15
	bl audio_play
	movs r0, 0x4
	strh r0, [r5, 0xA]
_080C1626:
	ldr r0, =sub_80C16CC
	str r0, [r5]
	b _080C16BC
	.pool
_080C1630:
	movs r0, 0x3
	bl audio_play
	ldr r0, =sub_80C1D38
	str r0, [r5]
	b _080C16BC
	.pool
_080C1640:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080C167C
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _080C167C
	movs r0, 0x6D
	bl audio_play
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80C2040
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
_080C167C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080C16BC
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bgt _080C16BC
	movs r0, 0x6D
	bl audio_play
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80C2040
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
_080C16BC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C15B0

	thumb_func_start sub_80C16CC
sub_80C16CC: @ 80C16CC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r0
	ldrb r0, [r5, 0x8]
	ldrb r1, [r5, 0xA]
	bl sub_80C2064
	adds r0, r4, 0
	bl sub_80C20F8
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, =sub_80C170C
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C16CC

	thumb_func_start sub_80C170C
sub_80C170C: @ 80C170C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080C1740
	bl sub_809D42C
	ldr r6, =gUnknown_0856EDB8
	cmp r0, 0
	bne _080C174C
	ldr r6, =gUnknown_0856EDF0
	b _080C174C
	.pool
_080C1740:
	bl sub_809D42C
	ldr r6, =gUnknown_0856ED9C
	cmp r0, 0
	bne _080C174C
	ldr r6, =gUnknown_0856EDD4
_080C174C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _080C178C
	movs r0, 0x17
	bl audio_play
	adds r0, r5, 0
	bl sub_80C23B8
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80C1570
	str r0, [r1]
	b _080C1994
	.pool
_080C178C:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C1870
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r6, r1, r0
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	cmp r0, 0x6
	bne _080C1860
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _080C183C
	ldr r1, =gUnknown_02039B52
	movs r0, 0x40
	strb r0, [r1]
	ldr r7, =gUnknown_02039B4C
	ldr r1, [r7]
	ldr r0, =0x0000062a
	adds r2, r1, r0
	movs r0, 0x40
	strh r0, [r2]
	ldr r0, =gUnknown_02039B50
	strh r3, [r0]
	movs r2, 0xC2
	lsls r2, 3
	adds r1, r2
	strh r3, [r1]
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80C2318
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	strb r0, [r1, 0x19]
	bl sub_809D42C
	cmp r0, 0
	bne _080C17E8
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x19]
_080C17E8:
	ldr r0, [r7]
	ldr r1, [r4]
	ldrb r1, [r1, 0x19]
	ldr r2, =0x00000614
	adds r0, r2
	strh r1, [r0]
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80C2318
	ldr r1, [r4]
	strb r0, [r1, 0x18]
	ldr r0, [r7]
	ldr r1, [r4]
	ldrb r1, [r1, 0x18]
	movs r2, 0xC3
	lsls r2, 3
	adds r0, r2
	strh r1, [r0]
	movs r0, 0x3
	bl audio_play
	ldr r0, =sub_80C1D38
	str r0, [r6]
	b _080C1994
	.pool
_080C183C:
	ldr r0, =gUnknown_085E875B
	bl sub_80C2618
	ldr r0, =sub_80C19A4
	str r0, [r6]
	movs r0, 0x70
	bl audio_play
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _080C1994
	.pool
_080C1860:
	movs r0, 0x15
	bl audio_play
	ldr r0, =sub_80C1B64
	str r0, [r6]
	b _080C1994
	.pool
_080C1870:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080C18B6
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080C18B6
	movs r0, 0x5
	bl audio_play
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0]
	strh r1, [r4, 0xA]
	ldrb r0, [r4, 0x8]
	bl sub_80C2064
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
_080C18B6:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080C1900
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x1]
	cmp r0, 0xFF
	beq _080C1900
	movs r0, 0x5
	bl audio_play
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x1]
	strh r1, [r4, 0xA]
	ldrb r0, [r4, 0x8]
	bl sub_80C2064
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
_080C1900:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C194A
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	cmp r0, 0xFF
	beq _080C194A
	movs r0, 0x5
	bl audio_play
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x2]
	strh r1, [r4, 0xA]
	ldrb r0, [r4, 0x8]
	bl sub_80C2064
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
_080C194A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C1994
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x3]
	cmp r0, 0xFF
	beq _080C1994
	movs r0, 0x5
	bl audio_play
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x3]
	strh r1, [r4, 0xA]
	ldrb r0, [r4, 0x8]
	bl sub_80C2064
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
_080C1994:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C170C

	thumb_func_start sub_80C19A4
sub_80C19A4: @ 80C19A4
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x8
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80C2318
	mov r10, r0
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80C2318
	mov r9, r0
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r5, 0
	movs r1, 0
	bl sub_80C2318
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80C2318
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80C2318
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80C2318
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp]
	str r0, [sp, 0x4]
	mov r0, r10
	mov r1, r9
	mov r2, r8
	adds r3, r6, 0
	bl sub_80C0F30
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80C1A4C
	str r1, [r0]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C19A4

	thumb_func_start sub_80C1A4C
sub_80C1A4C: @ 80C1A4C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl mplay_has_finished_maybe
	lsls r0, 24
	cmp r0, 0
	bne _080C1AA6
	ldr r0, =gUnknown_02039B4C
	ldr r0, [r0]
	ldr r1, =0x0000060c
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C1A84
	movs r0, 0x1F
	bl audio_play
	ldr r0, =gUnknown_085E8773
	bl sub_80C2618
	b _080C1A90
	.pool
_080C1A84:
	movs r0, 0x20
	bl audio_play
	ldr r0, =gUnknown_085E8785
	bl sub_80C2618
_080C1A90:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80C1AB8
	str r0, [r1]
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
_080C1AA6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1A4C

	thumb_func_start sub_80C1AB8
sub_80C1AB8: @ 80C1AB8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r2, r4, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C1B54
	ldr r5, =gUnknown_02039B4C
	ldr r1, [r5]
	ldr r3, =0x0000060c
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C1B40
	ldr r0, =0x0000064e
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x5
	bl sub_80C2318
	ldr r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x00000612
	adds r1, r2
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80C2318
	ldr r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0x00000616
	adds r1, r3
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80C1D38
	str r1, [r0]
	movs r0, 0x3
	bl audio_play
	b _080C1B54
	.pool
_080C1B40:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80C16CC
	str r0, [r1]
	movs r0, 0x17
	bl audio_play
_080C1B54:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1AB8

	thumb_func_start sub_80C1B64
sub_80C1B64: @ 80C1B64
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0
	bl sub_80C21D4
	ldr r2, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r6, r1, r2
	ldrb r0, [r6, 0xA]
	adds r2, 0x8
	adds r1, r2
	ldr r2, =gUnknown_0856EFC8
	lsls r0, 3
	adds r0, r2
	ldrb r4, [r0, 0x4]
	lsls r4, 1
	adds r4, r1, r4
	ldrb r0, [r0, 0x5]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r4]
	strh r0, [r6, 0x24]
	ldrh r0, [r1]
	strh r0, [r6, 0x26]
	adds r0, r5, 0
	bl sub_80C2294
	ldrh r0, [r4]
	bl sub_80C2650
	ldr r0, =sub_80C1BCC
	str r0, [r6]
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1B64

	thumb_func_start sub_80C1BCC
sub_80C1BCC: @ 80C1BCC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, =gTasks
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 3
	adds r5, r2, r3
	ldrb r1, [r5, 0xA]
	ldr r0, =gUnknown_0856EFC8
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	mov r8, r0
	adds r3, 0x8
	adds r2, r3
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r4, r2, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 1
	adds r6, r2, r0
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gMain
	mov r12, r0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C1C30
	movs r0, 0x15
	bl audio_play
	bl sub_80C267C
	movs r0, 0x1
	bl sub_80C21D4
	b _080C1C50
	.pool
_080C1C30:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080C1C68
	movs r0, 0x17
	bl audio_play
	bl sub_80C267C
	movs r0, 0x1
	bl sub_80C21D4
	ldrh r0, [r5, 0x24]
	strh r0, [r4]
	ldrh r0, [r5, 0x26]
	strh r0, [r6]
_080C1C50:
	ldr r0, =sub_80C16CC
	str r0, [r5]
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080C1D2E
	.pool
_080C1C68:
	movs r3, 0
	mov r0, r12
	ldrh r1, [r0, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C1CCA
	ldrh r0, [r4]
	cmp r0, 0
	beq _080C1C8E
	bl sub_80C2638
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r4]
	bl sub_80C2650
	b _080C1CAA
_080C1C8E:
	ldrh r0, [r6]
	cmp r0, 0
	beq _080C1CA6
	subs r0, 0x1
	strh r0, [r6]
	adds r0, r7, 0
	bl sub_80C2294
	ldrh r0, [r4]
	bl sub_80C2650
	movs r3, 0x1
_080C1CA6:
	cmp r3, 0
	beq _080C1D2E
_080C1CAA:
	movs r0, 0x5
	bl audio_play
	ldrh r0, [r4]
	ldrh r1, [r6]
	adds r0, r1
	lsls r0, 3
	add r0, r8
	ldr r0, [r0]
	bl sub_80C2618
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _080C1D2E
_080C1CCA:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C1D2E
	ldrh r0, [r4]
	cmp r0, 0x4
	bhi _080C1CEE
	cmp r0, r2
	bcs _080C1CEE
	bl sub_80C2638
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldrh r0, [r4]
	bl sub_80C2650
	b _080C1D10
_080C1CEE:
	cmp r2, 0x5
	bls _080C1D0C
	ldrh r1, [r6]
	subs r0, r2, 0x5
	cmp r1, r0
	bge _080C1D0C
	adds r0, r1, 0x1
	strh r0, [r6]
	adds r0, r7, 0
	bl sub_80C2294
	movs r0, 0x5
	bl sub_80C2650
	movs r3, 0x1
_080C1D0C:
	cmp r3, 0
	beq _080C1D2E
_080C1D10:
	movs r0, 0x5
	bl audio_play
	ldrh r0, [r4]
	ldrh r1, [r6]
	adds r0, r1
	lsls r0, 3
	add r0, r8
	ldr r0, [r0]
	bl sub_80C2618
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
_080C1D2E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C1BCC

	thumb_func_start sub_80C1D38
sub_80C1D38: @ 80C1D38
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80C1D70
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1D38

	thumb_func_start sub_80C1D70
sub_80C1D70: @ 80C1D70
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080C1D8C
	bl sub_80C152C
	adds r0, r4, 0
	bl DestroyTask
_080C1D8C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1D70

	thumb_func_start sub_80C1D98
sub_80C1D98: @ 80C1D98
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r3, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x3
	bl GetBgTilemapBuffer
	adds r2, r0, 0
	movs r3, 0
	cmp r3, r4
	bcs _080C1DEC
	lsls r0, r5, 6
	adds r7, r0, r2
	ldr r5, =0x00000fff
	lsls r2, r6, 12
_080C1DC8:
	mov r0, r8
	adds r1, r0, r3
	lsls r1, 1
	adds r1, r7
	ldrh r0, [r1]
	ands r0, r5
	orrs r0, r2
	strh r0, [r1]
	adds r1, 0x40
	ldrh r0, [r1]
	ands r0, r5
	orrs r0, r2
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r4
	bcc _080C1DC8
_080C1DEC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1D98

	thumb_func_start sub_80C1DFC
sub_80C1DFC: @ 80C1DFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	ands r5, r0
	ands r2, r0
	lsls r2, 1
	orrs r5, r2
	cmp r4, 0xA
	bhi _080C1EE8
	lsls r0, r4, 2
	ldr r1, =_080C1E28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C1E28:
	.4byte _080C1E54
	.4byte _080C1E54
	.4byte _080C1E54
	.4byte _080C1E64
	.4byte _080C1E64
	.4byte _080C1E7C
	.4byte _080C1E7C
	.4byte _080C1E64
	.4byte _080C1E64
	.4byte _080C1EA4
	.4byte _080C1E94
_080C1E54:
	ldr r1, =gUnknown_0856ED30
	lsls r0, r4, 3
	adds r0, r1
	ldrb r1, [r0, 0x4]
	ldrb r2, [r0, 0x5]
	b _080C1EC2
	.pool
_080C1E64:
	ldr r2, =gUnknown_0856ED48
	subs r1, r4, 0x3
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	ldrb r2, [r0, 0x5]
	ldrb r3, [r0, 0x6]
	adds r0, r5, 0
	bl sub_80C1D98
_080C1E7C:
	ldr r2, =gUnknown_0856ED48
	subs r1, r4, 0x3
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x7]
	ldrb r2, [r0, 0x8]
	ldrb r3, [r0, 0x9]
	b _080C1EC4
	.pool
_080C1E94:
	ldr r0, =gUnknown_0856ED48
	ldrb r1, [r0, 0x1C]
	ldrb r2, [r0, 0x1D]
	ldrb r3, [r0, 0x1E]
	b _080C1EC4
	.pool
_080C1EA4:
	bl sub_809D42C
	cmp r0, 0
	bne _080C1ED0
	ldr r2, =gUnknown_0856ED48
	subs r1, r4, 0x3
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	ldrb r2, [r0, 0x5]
	subs r2, 0x2
	lsls r2, 24
	lsrs r2, 24
_080C1EC2:
	ldrb r3, [r0, 0x6]
_080C1EC4:
	adds r0, r5, 0
	bl sub_80C1D98
	b _080C1EE8
	.pool
_080C1ED0:
	ldr r2, =gUnknown_0856ED48
	subs r1, r4, 0x3
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	ldrb r2, [r0, 0x5]
	ldrb r3, [r0, 0x6]
	adds r0, r5, 0
	bl sub_80C1D98
_080C1EE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C1DFC

	thumb_func_start sub_80C1EF4
sub_80C1EF4: @ 80C1EF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _080C1F5E
	cmp r0, 0x1
	bgt _080C1F0A
	cmp r0, 0
	beq _080C1F10
	b _080C203C
_080C1F0A:
	cmp r1, 0x2
	beq _080C1FCE
	b _080C203C
_080C1F10:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x4
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0xA
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0
	b _080C1FAA
_080C1F5E:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0xA
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0x1
_080C1FAA:
	bl sub_80C1DFC
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x8
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x9
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	b _080C203C
_080C1FCE:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0xA
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
	movs r0, 0x9
	movs r1, 0x1
	movs r2, 0x1
	bl sub_80C1DFC
_080C203C:
	pop {r0}
	bx r0
	thumb_func_end sub_80C1EF4

	thumb_func_start sub_80C2040
sub_80C2040: @ 80C2040
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80C1EF4
	ldr r0, =gUnknown_0856ED30
	lsls r4, 3
	adds r4, r0
	ldr r0, [r4]
	bl sub_80C2618
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2040

	thumb_func_start sub_80C2064
sub_80C2064: @ 80C2064
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	bl sub_80C1EF4
	cmp r4, 0x6
	bhi _080C20DE
	lsls r0, r4, 2
	ldr r1, =_080C2084
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C2084:
	.4byte _080C20A0
	.4byte _080C20A4
	.4byte _080C20A8
	.4byte _080C20B6
	.4byte _080C20C4
	.4byte _080C20C8
	.4byte _080C20D4
_080C20A0:
	movs r0, 0x3
	b _080C20CA
_080C20A4:
	movs r0, 0x4
	b _080C20CA
_080C20A8:
	movs r0, 0xA
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x5
	b _080C20CA
_080C20B6:
	movs r0, 0xA
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
	movs r0, 0x6
	b _080C20CA
_080C20C4:
	movs r0, 0x7
	b _080C20CA
_080C20C8:
	movs r0, 0x8
_080C20CA:
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
	b _080C20DE
_080C20D4:
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	bl sub_80C1DFC
_080C20DE:
	ldr r0, =gUnknown_0856ED48
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl sub_80C2618
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2064

	thumb_func_start sub_80C20F8
sub_80C20F8: @ 80C20F8
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x28
	movs r1, 0x10
	movs r2, 0x60
	movs r3, 0x50
	bl sub_80C12B0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x16]
	ldrh r1, [r5, 0x14]
	adds r0, r1
	lsls r0, 16
	ldr r1, =gUnknown_0856EE5C
	lsrs r0, 13
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2D
	movs r2, 0x11
	bl sub_80C1270
	ldrh r0, [r5, 0x1A]
	ldrh r1, [r5, 0x18]
	adds r0, r1
	lsls r0, 16
	ldr r1, =gUnknown_0856EEB4
	lsrs r0, 13
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2D
	movs r2, 0x21
	bl sub_80C1270
	ldrh r0, [r5, 0x1E]
	ldrh r1, [r5, 0x1C]
	adds r0, r1
	lsls r0, 16
	ldr r4, =gUnknown_0856EF14
	lsrs r0, 13
	adds r4, 0x4
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x2D
	movs r2, 0x31
	bl sub_80C1270
	ldrh r0, [r5, 0x22]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 13
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x5D
	movs r2, 0x31
	bl sub_80C1270
	ldrh r0, [r5, 0x12]
	ldrh r1, [r5, 0x10]
	adds r0, r1
	lsls r0, 16
	ldr r1, =gUnknown_0856EE24
	lsrs r0, 13
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2D
	movs r2, 0x41
	bl sub_80C1270
	bl sub_809D42C
	cmp r0, 0
	beq _080C21B6
	ldrh r0, [r5, 0xE]
	ldrh r5, [r5, 0xC]
	adds r0, r5
	lsls r0, 16
	ldr r1, =gUnknown_0856EE0C
	lsrs r0, 13
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2D
	movs r2, 0x51
	bl sub_80C1270
_080C21B6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C20F8

	thumb_func_start sub_80C21D4
sub_80C21D4: @ 80C21D4
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x3
	bl GetBgTilemapBuffer
	adds r5, r0, 0
	cmp r4, 0
	bne _080C2268
	ldr r1, =0x00000c0b
	adds r0, r1, 0
	strh r0, [r5, 0x22]
	movs r1, 0x12
	ldr r0, =0x0000080d
	adds r2, r0, 0
_080C21F4:
	lsls r0, r1, 1
	adds r0, r5
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1E
	bls _080C21F4
	movs r2, 0x1
	ldr r1, =0x0000040a
	adds r6, r1, 0
	movs r4, 0x2
_080C220C:
	lsls r0, r2, 6
	adds r0, r5
	strh r6, [r0, 0x22]
	movs r1, 0x12
	adds r3, r2, 0x1
	adds r2, r0, 0
_080C2218:
	lsls r0, r1, 1
	adds r0, r2
	strh r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1E
	bls _080C2218
	lsls r0, r3, 16
	lsrs r2, r0, 16
	cmp r2, 0xC
	bls _080C220C
	ldr r2, =0x00000362
	adds r1, r5, r2
	adds r2, 0xA9
	adds r0, r2, 0
	strh r0, [r1]
	movs r1, 0x12
	movs r3, 0xD0
	lsls r3, 2
	movs r2, 0xD
_080C2242:
	lsls r0, r1, 1
	adds r0, r5
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1E
	bls _080C2242
	b _080C228C
	.pool
_080C2268:
	movs r2, 0
	movs r4, 0x4F
_080C226C:
	movs r1, 0x11
	lsls r0, r2, 6
	adds r3, r2, 0x1
	adds r2, r0, r5
_080C2274:
	lsls r0, r1, 1
	adds r0, r2
	strh r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1D
	bls _080C2274
	lsls r0, r3, 16
	lsrs r2, r0, 16
	cmp r2, 0xD
	bls _080C226C
_080C228C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80C21D4

	thumb_func_start sub_80C2294
sub_80C2294: @ 80C2294
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_0856EFC8
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r0, r2, r3
	movs r5, 0xA
	ldrsh r1, [r0, r5]
	lsls r1, 3
	adds r1, r4
	ldr r6, [r1]
	adds r3, 0x8
	adds r2, r3
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r0, r2
	mov r8, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 1
	adds r7, r2, r0
	bl sub_80C267C
	movs r5, 0
	ldrh r4, [r7]
	b _080C22F2
	.pool
_080C22D8:
	adds r0, r1, r6
	ldr r1, [r0, 0x4]
	adds r0, r5, 0
	bl sub_80C2668
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r5, 0x5
	bhi _080C22FC
_080C22F2:
	lsls r1, r4, 3
	adds r0, r1, r6
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bne _080C22D8
_080C22FC:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldr r0, [r0]
	bl sub_80C2618
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C2294

	thumb_func_start sub_80C2318
sub_80C2318: @ 80C2318
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	ldr r2, =gUnknown_0856EFC8
	lsls r0, r3, 3
	adds r0, r2
	ldrb r2, [r0, 0x4]
	lsls r2, 1
	adds r2, r1, r2
	ldrb r0, [r0, 0x5]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r3, 0x5
	bhi _080C237C
	lsls r0, r3, 2
	ldr r1, =_080C2364
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C2364:
	.4byte _080C2390
	.4byte _080C239A
	.4byte _080C23AA
	.4byte _080C23AA
	.4byte _080C2388
	.4byte _080C2380
_080C237C:
	movs r0, 0
	b _080C23B0
_080C2380:
	ldr r0, =gUnknown_0856EFAC
	b _080C23AC
	.pool
_080C2388:
	ldr r0, =gUnknown_0856EFAE
	b _080C23AC
	.pool
_080C2390:
	cmp r2, 0
	beq _080C239E
	lsls r0, r2, 24
	lsrs r0, 24
	b _080C23B0
_080C239A:
	cmp r2, 0
	bne _080C23A2
_080C239E:
	movs r0, 0xFF
	b _080C23B0
_080C23A2:
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r0, 24
	b _080C23B0
_080C23AA:
	ldr r0, =gUnknown_0856EFB4
_080C23AC:
	adds r0, r2, r0
	ldrb r0, [r0]
_080C23B0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C2318

	thumb_func_start sub_80C23B8
sub_80C23B8: @ 80C23B8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_02039B4C
	ldr r0, [r1]
	ldr r2, =0x00000614
	adds r0, r2
	ldrh r0, [r0]
	adds r5, r1, 0
	cmp r0, 0
	beq _080C23D2
	cmp r0, 0x1
	beq _080C23E0
_080C23D2:
	movs r3, 0
	b _080C23E2
	.pool
_080C23E0:
	movs r3, 0x1
_080C23E2:
	ldr r1, =gTasks
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r1
	strh r3, [r0, 0xC]
	ldr r0, [r5]
	movs r3, 0xC3
	lsls r3, 3
	adds r0, r3
	ldrh r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x5
	bhi _080C2428
	lsls r0, 2
	ldr r1, =_080C2410
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C2410:
	.4byte _080C2428
	.4byte _080C242C
	.4byte _080C2430
	.4byte _080C2434
	.4byte _080C2438
	.4byte _080C243C
_080C2428:
	movs r3, 0
	b _080C243E
_080C242C:
	movs r3, 0x1
	b _080C243E
_080C2430:
	movs r3, 0x2
	b _080C243E
_080C2434:
	movs r3, 0x3
	b _080C243E
_080C2438:
	movs r3, 0x4
	b _080C243E
_080C243C:
	movs r3, 0x5
_080C243E:
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r5
	strh r3, [r0, 0x10]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80C23B8

	thumb_func_start sub_80C244C
sub_80C244C: @ 80C244C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r0, r1, r3
	ldrb r2, [r0, 0xA]
	adds r3, 0x8
	adds r1, r3
	ldr r0, =gUnknown_0856EFC8
	lsls r2, 3
	adds r2, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r2, 0x6]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _080C248C
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C248C
	movs r0, 0
	b _080C248E
	.pool
_080C248C:
	movs r0, 0x1
_080C248E:
	pop {r1}
	bx r1
	thumb_func_end sub_80C244C

	thumb_func_start sub_80C2494
sub_80C2494: @ 80C2494
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r0, r1, r3
	ldrb r2, [r0, 0xA]
	adds r3, 0x8
	adds r1, r3
	ldr r0, =gUnknown_0856EFC8
	lsls r2, 3
	adds r2, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r2, 0x6]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _080C24D8
	ldrh r1, [r1]
	subs r0, 0x5
	cmp r1, r0
	bge _080C24D8
	movs r0, 0
	b _080C24DA
	.pool
_080C24D8:
	movs r0, 0x1
_080C24DA:
	pop {r1}
	bx r1
	thumb_func_end sub_80C2494

	thumb_func_start sub_80C24E0
sub_80C24E0: @ 80C24E0
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =sub_80C1BCC
	cmp r1, r0
	bne _080C2580
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080C2528
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80C2494
	lsls r0, 24
	cmp r0, 0
	beq _080C2544
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _080C2550
	.pool
_080C2528:
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80C244C
	lsls r0, 24
	cmp r0, 0
	beq _080C2544
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _080C2550
_080C2544:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
_080C2550:
	strb r0, [r2]
	ldrh r2, [r4, 0x32]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	lsls r0, 7
	adds r0, r2, r0
	lsls r0, 24
	ldr r1, =gSineTable
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080C256E
	adds r0, 0x7F
_080C256E:
	asrs r0, 7
	strh r0, [r4, 0x26]
	adds r0, r2, 0
	adds r0, 0x8
	strh r0, [r4, 0x32]
	b _080C258C
	.pool
_080C2580:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080C258C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80C24E0

	thumb_func_start sub_80C2594
sub_80C2594: @ 80C2594
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gUnknown_0855D1AC
	adds r0, r6, 0
	movs r1, 0xB8
	movs r2, 0x4
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r0, r1, r4
	movs r2, 0
	strh r5, [r0, 0x2E]
	strh r2, [r0, 0x30]
	movs r0, 0x1C
	adds r0, r4
	mov r9, r0
	add r1, r9
	ldr r0, =sub_80C24E0
	mov r8, r0
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0xB8
	movs r2, 0x6C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r4, r1, r4
	strh r5, [r4, 0x2E]
	movs r0, 0x1
	strh r0, [r4, 0x30]
	adds r4, 0x3F
	ldrb r0, [r4]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r4]
	add r1, r9
	mov r0, r8
	str r0, [r1]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2594

	thumb_func_start sub_80C2618
sub_80C2618: @ 80C2618
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x8
	movs r1, 0x78
	movs r2, 0xE0
	movs r3, 0x20
	bl sub_80C12B0
	adds r0, r4, 0
	movs r1, 0x8
	movs r2, 0x79
	bl sub_80C1270
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80C2618

	thumb_func_start sub_80C2638
sub_80C2638: @ 80C2638
	push {lr}
	adds r1, r0, 0
	lsls r1, 4
	adds r1, 0x8
	movs r0, 0x90
	movs r2, 0x8
	movs r3, 0x10
	bl sub_80C12B0
	pop {r0}
	bx r0
	thumb_func_end sub_80C2638

	thumb_func_start sub_80C2650
sub_80C2650: @ 80C2650
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_085E8B3A
	lsls r2, 4
	adds r2, 0x9
	movs r1, 0x90
	bl sub_80C1270
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2650

	thumb_func_start sub_80C2668
sub_80C2668: @ 80C2668
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	lsls r2, 4
	adds r2, 0x9
	movs r1, 0x98
	bl sub_80C1270
	pop {r0}
	bx r0
	thumb_func_end sub_80C2668

	thumb_func_start sub_80C267C
sub_80C267C: @ 80C267C
	push {lr}
	movs r0, 0x90
	movs r1, 0x8
	movs r2, 0x60
	movs r3, 0x60
	bl sub_80C12B0
	pop {r0}
	bx r0
	thumb_func_end sub_80C267C

	.align 2, 0 @ Don't pad with nop.
