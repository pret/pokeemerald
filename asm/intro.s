	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_816CBE8
sub_816CBE8: @ 816CBE8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl sub_80BA0A8
	pop {r0}
	bx r0
	thumb_func_end sub_816CBE8

	thumb_func_start sub_816CC00
sub_816CC00: @ 816CC00
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	beq _0816CC3C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816CC3C
	ldr r0, =sub_816CC54
	bl SetMainCallback2
	b _0816CC4C
	.pool
_0816CC3C:
	ldr r2, =gUnknown_030062A0
	ldr r1, [r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0816CC4C
	adds r0, r1, 0x1
	str r0, [r2]
_0816CC4C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CC00

	thumb_func_start sub_816CC54
sub_816CC54: @ 816CC54
	push {lr}
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0816CC66
	ldr r0, =c2_title_screen_1
	bl SetMainCallback2
_0816CC66:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CC54

	thumb_func_start load_copyright_graphics
@ void load_copyright_graphics(u16 tile_patterns_dest, u16 tilemap_dest, u16 unknown_dest)
load_copyright_graphics: @ 816CC70
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gIntroCopyright_Gfx
	movs r6, 0xC0
	lsls r6, 19
	adds r3, r6
	adds r1, r3, 0
	bl LZ77UnCompVram
	ldr r0, =gIntroCopyright_Tilemap
	adds r4, r6
	adds r1, r4, 0
	bl LZ77UnCompVram
	ldr r0, =gIntroCopyright_Pal
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end load_copyright_graphics

	thumb_func_start SerialCb_CopyrightScreen
SerialCb_CopyrightScreen: @ 816CCB8
	push {lr}
	ldr r0, =gUnknown_030062B0
	bl GameCubeMultiBoot_HandleSerialInterrupt
	pop {r0}
	bx r0
	.pool
	thumb_func_end SerialCb_CopyrightScreen

	thumb_func_start do_copyright_screen
do_copyright_screen: @ 816CCC8
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r5, r0, r1
	ldrb r4, [r5]
	cmp r4, 0x8C
	bne _0816CCDC
	b _0816CE00
_0816CCDC:
	cmp r4, 0x8C
	bgt _0816CCEC
	cmp r4, 0
	beq _0816CCF4
	b _0816CDBC
	.pool
_0816CCEC:
	cmp r4, 0x8D
	bne _0816CCF2
	b _0816CE2C
_0816CCF2:
	b _0816CDBC
_0816CCF4:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x00007fff
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	str r4, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	add r0, sp, 0x4
	bl CpuSet
	str r4, [sp, 0x8]
	add r0, sp, 0x8
	movs r1, 0xE0
	lsls r1, 19
	ldr r2, =0x05000100
	bl CpuSet
	add r0, sp, 0xC
	strh r4, [r0]
	ldr r1, =0x05000002
	ldr r2, =0x010001ff
	bl CpuSet
	bl ResetPaletteFade
	movs r1, 0xE0
	lsls r1, 6
	movs r0, 0
	movs r2, 0
	bl load_copyright_graphics
	bl remove_some_task
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r1, 0xE0
	lsls r1, 3
	movs r0, 0x8
	bl SetGpuReg
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_816CBE8
	bl SetVBlankCallback
	movs r1, 0x80
	lsls r1, 19
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =SerialCb_CopyrightScreen
	bl SetSerialCallback
	ldr r0, =gUnknown_030062B0
	bl GameCubeMultiBoot_Init
_0816CDBC:
	bl UpdatePaletteFade
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, =gUnknown_030062B0
	bl GameCubeMultiBoot_Main
	b _0816CEA0
	.pool
_0816CE00:
	ldr r4, =gUnknown_030062B0
	adds r0, r4, 0
	bl GameCubeMultiBoot_Main
	ldrb r0, [r4, 0x2]
	cmp r0, 0x1
	beq _0816CEA0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0816CEA0
	.pool
_0816CE2C:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0816CEA0
	ldr r0, =task_intro_1
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_816CC00
	bl SetMainCallback2
	ldr r5, =gUnknown_030062B0
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	beq _0816CE8C
	ldrb r0, [r5, 0x2]
	cmp r0, 0x2
	bne _0816CE96
	ldr r6, =0x020000ac
	ldr r4, [r6]
	ldr r0, =0x65366347
	cmp r4, r0
	bne _0816CE6C
	ldr r0, =gMultiBootProgram_PokemonColosseum_Start
	movs r1, 0x80
	lsls r1, 18
	movs r2, 0xA0
	lsls r2, 9
	bl CpuSet
	str r4, [r6]
_0816CE6C:
	adds r0, r5, 0
	bl GameCubeMultiBoot_ExecuteProgram
	b _0816CE96
	.pool
_0816CE8C:
	bl GameCubeMultiBoot_Quit
	ldr r0, =sub_800BA38
	bl SetSerialCallback
_0816CE96:
	movs r0, 0
	b _0816CEA2
	.pool
_0816CEA0:
	movs r0, 0x1
_0816CEA2:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end do_copyright_screen

	thumb_func_start c2_copyright_1
c2_copyright_1: @ 816CEAC
	push {lr}
	bl do_copyright_screen
	lsls r0, 24
	cmp r0, 0
	bne _0816CEFA
	bl sub_815355C
	lsls r0, 16
	lsrs r0, 16
	bl SetSaveBlocksPointers
	bl sub_808447C
	bl ResetSaveCounters
	movs r0, 0
	bl sub_81534D0
	ldr r0, =gSaveFileStatus
	ldrh r0, [r0]
	cmp r0, 0
	beq _0816CEDE
	cmp r0, 0x2
	bne _0816CEE2
_0816CEDE:
	bl Sav2_ClearSetDefault
_0816CEE2:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsls r0, 31
	lsrs r0, 31
	bl SetPokemonCryStereo
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
_0816CEFA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_copyright_1

	thumb_func_start c2_show_copyright_and_intro_again_2
c2_show_copyright_and_intro_again_2: @ 816CF0C
	push {lr}
	bl do_copyright_screen
	pop {r0}
	bx r0
	thumb_func_end c2_show_copyright_and_intro_again_2

	thumb_func_start task_intro_1
@ void task_intro_1(int task_id)
task_intro_1: @ 816CF18
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCC8
	bl Random
	movs r1, 0x1
	ands r1, r0
	strh r1, [r4]
	bl intro_reset_and_hide_bgs
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0x50
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0x18
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0x28
	bl SetGpuReg
	ldr r0, =gIntro1BGLeavesGfx
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gIntro1BG0_Tilemap
	ldr r1, =0x06008000
	bl LZ77UnCompVram
	ldr r1, =0x06008800
	add r0, sp, 0x8
	movs r6, 0
	strh r6, [r0]
	ldr r4, =0x040000d4
	str r0, [r4]
	str r1, [r4, 0x4]
	ldr r5, =0x81000400
	str r5, [r4, 0x8]
	ldr r0, [r4, 0x8]
	ldr r0, =gIntro1BG1_Tilemap
	ldr r1, =0x06009000
	bl LZ77UnCompVram
	ldr r1, =0x06009800
	add r0, sp, 0x8
	strh r6, [r0]
	str r0, [r4]
	str r1, [r4, 0x4]
	str r5, [r4, 0x8]
	ldr r0, [r4, 0x8]
	ldr r0, =gIntro1BG2_Tilemap
	ldr r1, =0x0600a000
	bl LZ77UnCompVram
	ldr r1, =0x0600a800
	add r0, sp, 0x8
	strh r6, [r0]
	str r0, [r4]
	str r1, [r4, 0x4]
	str r5, [r4, 0x8]
	ldr r0, [r4, 0x8]
	ldr r0, =gIntro1BG3_Tilemap
	ldr r1, =0x0600b000
	bl LZ77UnCompVram
	ldr r1, =0x0600b800
	add r0, sp, 0x8
	strh r6, [r0]
	str r0, [r4]
	str r1, [r4, 0x4]
	str r5, [r4, 0x8]
	ldr r0, [r4, 0x8]
	ldr r0, =gIntro1BGPals
	movs r5, 0x80
	lsls r5, 2
	movs r1, 0
	adds r2, r5, 0
	bl LoadPalette
	ldr r1, =0x00009603
	movs r0, 0xE
	bl SetGpuReg
	ldr r1, =0x00009402
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =0x00009201
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0x90
	lsls r1, 8
	movs r0, 0x8
	bl SetGpuReg
	ldr r0, =gUnknown_085E4FDC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E4FEC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E4FFC
	bl LoadSpritePalettes
	ldr r0, =gUnknown_085E4A74
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E4A84
	bl LoadSpritePalettes
	ldr r4, =gPlttBufferUnfaded + 0x200
	movs r3, 0xF0
	lsls r3, 1
	adds r1, r4, r3
	adds r0, r4, 0
	movs r2, 0x10
	bl CpuSet
	movs r0, 0xE1
	lsls r0, 1
	adds r1, r4, r0
	adds r0, r4, 0
	movs r2, 0xF
	bl CpuSet
	movs r3, 0xD2
	lsls r3, 1
	adds r1, r4, r3
	adds r0, r4, 0
	movs r2, 0xE
	bl CpuSet
	movs r0, 0xC3
	lsls r0, 1
	adds r1, r4, r0
	adds r0, r4, 0
	movs r2, 0xD
	bl CpuSet
	movs r3, 0xB4
	lsls r3, 1
	adds r1, r4, r3
	adds r0, r4, 0
	movs r2, 0xC
	bl CpuSet
	movs r0, 0xA5
	lsls r0, 1
	adds r1, r4, r0
	adds r0, r4, 0
	movs r2, 0xB
	bl CpuSet
	movs r3, 0x96
	lsls r3, 1
	adds r1, r4, r3
	adds r0, r4, 0
	movs r2, 0xA
	bl CpuSet
	movs r0, 0x78
	movs r1, 0x50
	movs r2, 0
	bl sub_816FDB8
	movs r1, 0xE
	negs r1, r1
	movs r0, 0x78
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0xEC
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_816F7D0
	ldr r2, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x8]
	ldr r0, =task_intro_2
	str r0, [r1]
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_1

	thumb_func_start task_intro_2
task_intro_2: @ 816D12C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r5, 0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_816CBE8
	bl SetVBlankCallback
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_3
	str r1, [r0]
	ldr r0, =gUnknown_030062A0
	str r5, [r0]
	movs r0, 0xCF
	lsls r0, 1
	bl m4aSongNumStart
	bl sub_800B628
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_2

	thumb_func_start task_intro_3
task_intro_3: @ 816D190
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r5, =gUnknown_030062A0
	ldr r0, [r5]
	cmp r0, 0x4C
	bne _0816D1BE
	ldr r2, =gSprites
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r3, 0x8
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x2E]
_0816D1BE:
	ldr r0, [r5]
	cmp r0, 0x80
	bne _0816D1CC
	ldr r0, =task_intro_3_1
	movs r1, 0
	bl CreateTask
_0816D1CC:
	ldr r0, [r5]
	cmp r0, 0xFB
	bne _0816D1EE
	ldr r2, =gSprites
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r3, 0x8
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x2E]
_0816D1EE:
	ldr r1, [r5]
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _0816D200
	ldr r0, =task_intro_3_2
	movs r1, 0
	bl CreateTask
_0816D200:
	ldr r1, [r5]
	movs r0, 0xB8
	lsls r0, 1
	cmp r1, r0
	bne _0816D220
	movs r2, 0x80
	lsls r2, 3
	movs r0, 0x70
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x30
	movs r1, 0
	movs r3, 0x5
	bl sub_816F7D0
_0816D220:
	ldr r1, [r5]
	movs r0, 0xC0
	lsls r0, 1
	cmp r1, r0
	bne _0816D240
	movs r2, 0x80
	lsls r2, 3
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0xC8
	movs r1, 0x3C
	movs r3, 0x9
	bl sub_816F7D0
_0816D240:
	ldr r0, [r5]
	movs r4, 0x8C
	lsls r4, 2
	cmp r0, r4
	bne _0816D252
	ldr r0, =task_intro_3_3
	movs r1, 0
	bl CreateTask
_0816D252:
	ldr r0, [r5]
	cmp r0, r4
	bls _0816D27A
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x50
	strh r1, [r0, 0xA]
	strh r2, [r0, 0xC]
	movs r1, 0x18
	strh r1, [r0, 0xE]
	strh r2, [r0, 0x10]
	movs r1, 0x28
	strh r1, [r0, 0x12]
	strh r2, [r0, 0x14]
	ldr r1, =task_intro_4
	str r1, [r0]
_0816D27A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_3

	thumb_func_start task_intro_3_3
task_intro_3_3: @ 816D2A0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816D2C4
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
_0816D2C4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0816D2D8
	cmp r0, 0x1
	beq _0816D314
	b _0816D324
	.pool
_0816D2D8:
	ldr r0, =gUnknown_085E4AB8
	ldr r2, =gUnknown_085E4AD0
	movs r1, 0x8
	ldrsh r3, [r4, r1]
	lsls r3, 1
	adds r1, r3, r2
	ldrb r1, [r1]
	adds r2, 0x1
	adds r3, r2
	ldrh r2, [r4, 0x6]
	ldrb r3, [r3]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0xC
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0816D324
	.pool
_0816D314:
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _0816D324
	strh r0, [r4]
_0816D324:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0x3C
	ble _0816D332
	adds r0, r5, 0
	bl DestroyTask
_0816D332:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_intro_3_3

	thumb_func_start sub_816D338
sub_816D338: @ 816D338
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _0816D350
	adds r0, r1, 0
	bl DestroySprite
_0816D350:
	pop {r0}
	bx r0
	thumb_func_end sub_816D338

	thumb_func_start task_intro_4
task_intro_4: @ 816D354
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r1, r0, 24
	adds r4, r1, 0
	ldr r5, =gUnknown_030062A0
	ldr r2, [r5]
	ldr r0, =0x00000387
	cmp r2, r0
	bhi _0816D418
	ldr r0, =gTasks
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 3
	adds r4, r0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsls r0, 16
	ldrh r1, [r4, 0xC]
	adds r1, r0, r1
	ldr r0, =0xffffa000
	adds r1, r0
	asrs r0, r1, 16
	strh r0, [r4, 0xA]
	strh r1, [r4, 0xC]
	ldrh r1, [r4, 0xA]
	movs r0, 0x1A
	bl SetGpuReg
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r0, 16
	ldrh r1, [r4, 0x10]
	adds r1, r0, r1
	ldr r0, =0xffff8000
	adds r1, r0
	asrs r0, r1, 16
	strh r0, [r4, 0xE]
	strh r1, [r4, 0x10]
	ldrh r1, [r4, 0xE]
	movs r0, 0x16
	bl SetGpuReg
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r0, 16
	ldrh r1, [r4, 0x14]
	adds r1, r0, r1
	ldr r0, =0xffff4000
	adds r1, r0
	asrs r0, r1, 16
	strh r0, [r4, 0x12]
	strh r1, [r4, 0x14]
	ldrh r1, [r4, 0x12]
	movs r0, 0x12
	bl SetGpuReg
	ldr r1, [r5]
	movs r0, 0xD0
	lsls r0, 2
	cmp r1, r0
	bne _0816D43E
	ldr r0, =gUnknown_085E4FC4
	movs r1, 0x78
	movs r2, 0xA0
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	b _0816D43E
	.pool
_0816D418:
	ldr r0, =0x000003ef
	cmp r2, r0
	bls _0816D43E
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_5
	str r1, [r0]
_0816D43E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_4

	thumb_func_start task_intro_5
task_intro_5: @ 816D458
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	ldr r0, =0x00000402
	cmp r1, r0
	bls _0816D476
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_intro_6
	str r0, [r1]
_0816D476:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_5

	thumb_func_start task_intro_6
task_intro_6: @ 816D48C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl intro_reset_and_hide_bgs
	movs r0, 0
	bl SetVBlankCallback
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =gUnknown_0203BD24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0203BD26
	strh r1, [r0]
	ldr r0, =gUnknown_0203BCCC
	strh r1, [r0]
	movs r0, 0x1
	bl load_intro_part2_graphics
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_7
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_6

	thumb_func_start task_intro_7
task_intro_7: @ 816D4E4
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203BCC8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0816D504
	ldr r0, =gUnknown_085F52BC
	bl LoadCompressedObjectPic
	b _0816D50A
	.pool
_0816D504:
	ldr r0, =gUnknown_085F52CC
	bl LoadCompressedObjectPic
_0816D50A:
	ldr r0, =gUnknown_085F52DC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F52FC
	bl LoadCompressedObjectPic
	movs r6, 0
	lsls r7, r4, 2
	ldr r5, =gUnknown_085E4AE8
_0816D51C:
	lsls r0, r6, 3
	adds r0, r5
	bl LoadCompressedObjectPic
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _0816D51C
	ldr r0, =gUnknown_085F530C
	bl LoadSpritePalettes
	ldr r0, =gUnknown_085E4B08
	bl LoadSpritePalettes
	ldr r0, =gUnknown_085E4BDC
	movs r5, 0x88
	lsls r5, 1
	adds r1, r5, 0
	movs r2, 0x80
	movs r3, 0
	bl CreateSprite
	ldr r0, =gUnknown_085E4BA4
	movs r1, 0x90
	lsls r1, 1
	movs r2, 0x6E
	movs r3, 0x1
	bl CreateSprite
	ldr r0, =gUnknown_0203BCC8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0816D590
	adds r0, r5, 0
	movs r1, 0x64
	bl sub_817B834
	b _0816D598
	.pool
_0816D590:
	adds r0, r5, 0
	movs r1, 0x64
	bl sub_817B88C
_0816D598:
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r5, r2, 0
	adds r5, 0x1C
	adds r3, r0, r5
	ldr r1, =sub_816F9D4
	str r1, [r3]
	adds r2, 0x8
	adds r0, r2
	ldr r1, =gUnknown_085E4DC4
	str r1, [r0]
	ldr r0, =gTasks
	adds r4, r7, r4
	lsls r4, 3
	adds r4, r0
	strh r6, [r4, 0xA]
	ldr r0, =gUnknown_085E4B40
	movs r1, 0x88
	lsls r1, 1
	movs r2, 0x50
	movs r3, 0x4
	bl CreateSprite
	movs r0, 0x40
	negs r0, r0
	movs r1, 0x3C
	bl sub_817B9C4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r5
	ldr r1, =sub_816FAB0
	str r1, [r0]
	strh r6, [r4, 0xC]
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_816CBE8
	bl SetVBlankCallback
	movs r1, 0x80
	lsls r1, 7
	movs r2, 0x80
	lsls r2, 3
	movs r0, 0x1
	movs r3, 0x10
	bl sub_817B3DC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x8]
	movs r0, 0x1
	bl sub_817B150
	ldr r0, =task_intro_8
	str r0, [r4]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_7

	thumb_func_start task_intro_8
@ void task_intro_8(int task_id)
task_intro_8: @ 816D650
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r5, =gUnknown_030062A0
	ldr r1, [r5]
	movs r0, 0xE8
	lsls r0, 3
	cmp r1, r0
	bne _0816D67C
	ldr r1, =gUnknown_0203BD28
	movs r0, 0x2
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x8]
	bl DestroyTask
_0816D67C:
	ldr r1, [r5]
	ldr r0, =0x0000079a
	cmp r1, r0
	bls _0816D6A4
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
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
	ldr r1, =task_intro_9
	str r1, [r0]
_0816D6A4:
	ldr r1, [r5]
	ldr r0, =0x00000455
	ldr r3, =gTasks
	cmp r1, r0
	bne _0816D6C8
	ldr r2, =gSprites
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r7, 0xA
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x2E]
_0816D6C8:
	ldr r1, [r5]
	ldr r0, =0x000004be
	cmp r1, r0
	bne _0816D6EA
	ldr r2, =gSprites
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r7, 0xA
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x2E]
_0816D6EA:
	ldr r1, [r5]
	ldr r0, =0x00000572
	cmp r1, r0
	bne _0816D70C
	ldr r2, =gSprites
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r7, 0xC
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x2E]
_0816D70C:
	ldr r1, [r5]
	ldr r0, =0x00000576
	cmp r1, r0
	bne _0816D72E
	ldr r2, =gSprites
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r7, 0xA
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x2E]
_0816D72E:
	ldr r1, [r5]
	movs r0, 0xC5
	lsls r0, 3
	cmp r1, r0
	bne _0816D752
	ldr r2, =gSprites
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r7, 0xA
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strh r1, [r0, 0x2E]
_0816D752:
	ldr r1, [r5]
	ldr r0, =0x000006bf
	cmp r1, r0
	bne _0816D774
	ldr r2, =gSprites
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r4, 0xA
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x4
	strh r1, [r0, 0x2E]
_0816D774:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 18
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0x30
	bl Sin
	ldr r1, =gUnknown_0203BCCC
	strh r0, [r1]
	ldrh r2, [r4, 0xE]
	movs r7, 0xE
	ldrsh r1, [r4, r7]
	ldr r0, =0x000001ff
	cmp r1, r0
	bgt _0816D7A0
	adds r0, r2, 0x1
	strh r0, [r4, 0xE]
_0816D7A0:
	movs r0, 0
	bl sub_817B540
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_8

	thumb_func_start task_intro_9
task_intro_9: @ 816D7E8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	ldr r0, =0x00000814
	cmp r1, r0
	bls _0816D806
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_intro_10
	str r0, [r1]
_0816D806:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_9

	thumb_func_start sub_816D81C
sub_816D81C: @ 816D81C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	adds r0, 0x4
	strh r0, [r4, 0x34]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bls _0816D830
	b _0816D9BA
_0816D830:
	lsls r0, 2
	ldr r1, =_0816D840
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816D840:
	.4byte _0816D864
	.4byte _0816D87A
	.4byte _0816D898
	.4byte _0816D8BC
	.4byte _0816D8D8
	.4byte _0816D8FA
	.4byte _0816D912
	.4byte _0816D96E
	.4byte _0816D99C
_0816D864:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB3
	bgt _0816D874
	b _0816D9BA
_0816D874:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0816D87A:
	ldrh r0, [r4, 0x20]
	subs r0, 0x4
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	beq _0816D88A
	b _0816D9BA
_0816D88A:
	movs r0, 0x8
	strh r0, [r4, 0x2E]
	movs r0, 0x14
	strh r0, [r4, 0x30]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	b _0816D9BA
_0816D898:
	ldrh r1, [r4, 0x20]
	adds r1, 0x8
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	subs r0, 0x2
	strh r0, [r4, 0x22]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7C
	beq _0816D8AE
	b _0816D9BA
_0816D8AE:
	movs r0, 0x8
	strh r0, [r4, 0x2E]
	movs r0, 0x14
	strh r0, [r4, 0x30]
	movs r0, 0x3
	strh r0, [r4, 0x32]
	b _0816D9BA
_0816D8BC:
	ldrh r0, [r4, 0x22]
	adds r0, 0x4
	strh r0, [r4, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x50
	bne _0816D9BA
	movs r0, 0x8
	strh r0, [r4, 0x2E]
	movs r0, 0xA
	strh r0, [r4, 0x30]
	movs r0, 0x4
	strh r0, [r4, 0x32]
	b _0816D9BA
_0816D8D8:
	ldrh r1, [r4, 0x20]
	subs r1, 0x8
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	subs r0, 0x2
	strh r0, [r4, 0x22]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3C
	bne _0816D9BA
	movs r0, 0x8
	strh r0, [r4, 0x2E]
	movs r0, 0xA
	strh r0, [r4, 0x30]
	movs r0, 0x5
	strh r0, [r4, 0x32]
	b _0816D9BA
_0816D8FA:
	ldrh r0, [r4, 0x20]
	adds r0, 0x3C
	strh r0, [r4, 0x20]
	movs r0, 0xC0
	strh r0, [r4, 0x36]
	movs r0, 0x80
	strh r0, [r4, 0x38]
	movs r0, 0x3
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0816D912:
	ldrh r0, [r4, 0x36]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3C
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x36]
	adds r1, 0x2
	strh r1, [r4, 0x36]
	ldrh r0, [r4, 0x38]
	adds r0, 0x4
	strh r0, [r4, 0x38]
	movs r0, 0xFF
	ands r1, r0
	cmp r1, 0x40
	bne _0816D9BA
	adds r2, r4, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x2
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	ldrh r0, [r4, 0x3A]
	subs r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _0816D9BA
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	b _0816D9B8
_0816D96E:
	ldrh r0, [r4, 0x20]
	subs r0, 0x2
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0x4
	strh r0, [r4, 0x38]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0816D9BA
	adds r0, r4, 0
	bl DestroySprite
	b _0816D9BA
_0816D99C:
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _0816D9BA
	ldrh r0, [r4, 0x32]
_0816D9B8:
	strh r0, [r4, 0x2E]
_0816D9BA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816D81C

	thumb_func_start sub_816D9C0
sub_816D9C0: @ 816D9C0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bls _0816D9CE
	b _0816DADA
_0816D9CE:
	lsls r0, 2
	ldr r1, =_0816D9DC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816D9DC:
	.4byte _0816D9F4
	.4byte _0816DA08
	.4byte _0816DA20
	.4byte _0816DA64
	.4byte _0816DA9A
	.4byte _0816DACA
_0816D9F4:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x99
	lsls r0, 3
	cmp r1, r0
	bne _0816DADA
	b _0816DABA
	.pool
_0816DA08:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0xC5
	lsls r0, 3
	cmp r1, r0
	bne _0816DA70
	adds r0, r4, 0
	movs r1, 0
	b _0816DABE
	.pool
_0816DA20:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	ldr r0, =0x000006c7
	cmp r1, r0
	beq _0816DA50
	ldrh r0, [r4, 0x30]
	adds r2, r0, 0
	adds r2, 0x20
	strh r2, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0816DADA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	b _0816DA8A
	.pool
_0816DA50:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x50
	strh r0, [r4, 0x32]
	b _0816DADA
_0816DA64:
	ldrh r0, [r4, 0x32]
	subs r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	beq _0816DA94
_0816DA70:
	ldrh r0, [r4, 0x30]
	adds r2, r0, 0
	adds r2, 0x40
	strh r2, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0816DADA
	ldrh r0, [r4, 0x20]
	subs r0, 0x1
_0816DA8A:
	strh r0, [r4, 0x20]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r4, 0x30]
	b _0816DADA
_0816DA94:
	adds r0, r4, 0
	movs r1, 0x2
	b _0816DABE
_0816DA9A:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0816DAAE
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
_0816DAAE:
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0xA8
	lsls r0, 1
	cmp r1, r0
	ble _0816DADA
_0816DABA:
	adds r0, r4, 0
	movs r1, 0x1
_0816DABE:
	bl StartSpriteAnim
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0816DADA
_0816DACA:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	ldr r0, =0x0000073f
	cmp r1, r0
	bls _0816DADA
	ldrh r0, [r4, 0x20]
	subs r0, 0x2
	strh r0, [r4, 0x20]
_0816DADA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816D9C0

	thumb_func_start sub_816DAE8
sub_816DAE8: @ 816DAE8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816DB1C
	cmp r0, 0x1
	bgt _0816DAFE
	cmp r0, 0
	beq _0816DB04
	b _0816DBA4
_0816DAFE:
	cmp r0, 0x2
	beq _0816DB42
	b _0816DBA4
_0816DB04:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x88
	lsls r0, 3
	cmp r1, r0
	bne _0816DBA4
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0816DBA4
	.pool
_0816DB1C:
	ldrh r0, [r4, 0x20]
	subs r0, 0x2
	strh r0, [r4, 0x20]
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x92
	lsls r0, 3
	cmp r1, r0
	bne _0816DBA4
	ldrh r0, [r4, 0x22]
	subs r0, 0xC
	strh r0, [r4, 0x22]
	movs r0, 0x80
	strh r0, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0816DB42:
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bgt _0816DB60
	adds r0, r4, 0
	bl DestroySprite
	b _0816DBA4
	.pool
_0816DB60:
	ldrh r0, [r4, 0x30]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0x3F
	bgt _0816DB72
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x10
	b _0816DB84
_0816DB72:
	cmp r1, 0x40
	bne _0816DB7C
	ldrh r0, [r4, 0x20]
	subs r0, 0x30
	strh r0, [r4, 0x20]
_0816DB7C:
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x40
_0816DB84:
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xC
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_0816DBA4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816DAE8

	thumb_func_start task_intro_10
task_intro_10: @ 816DBAC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	bl intro_reset_and_hide_bgs
	ldr r0, =gIntro3Pokeball_Gfx
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gIntro3Pokeball_Tilemap
	ldr r1, =0x06004000
	bl LZ77UnCompVram
	ldr r0, =gIntro3PokeballPal
	movs r2, 0x80
	lsls r2, 2
	movs r1, 0
	bl LoadPalette
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r5, 0
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	movs r0, 0x78
	movs r1, 0x50
	movs r2, 0
	movs r3, 0
	bl sub_816F2A8
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =0x00004883
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =0x00001441
	movs r0, 0
	bl SetGpuReg
	ldr r0, =task_intro_11
	str r0, [r4]
	ldr r0, =gUnknown_030062A0
	str r5, [r0]
	movs r0, 0xDD
	lsls r0, 1
	bl m4aSongNumStart
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_10

	thumb_func_start task_intro_11
task_intro_11: @ 816DC64
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	movs r1, 0x80
	lsls r1, 3
	adds r0, r1, 0
	ldrh r1, [r3, 0x8]
	adds r0, r1
	strh r0, [r3, 0x8]
	ldrh r4, [r3, 0xA]
	movs r0, 0xA
	ldrsh r1, [r3, r0]
	ldr r0, =0x000006bf
	cmp r1, r0
	bgt _0816DCA4
	ldrh r0, [r3, 0xC]
	adds r1, r4, r0
	strh r1, [r3, 0xA]
	adds r0, 0x2
	strh r0, [r3, 0xC]
	b _0816DCA8
	.pool
_0816DCA4:
	ldr r0, =task_intro_12
	str r0, [r3]
_0816DCA8:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r2
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 9
	bl __divsi3
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	ldrh r3, [r4, 0x8]
	movs r0, 0x78
	movs r1, 0x50
	bl sub_816F2A8
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	cmp r0, 0x1C
	bne _0816DCE6
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0816DCE6:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_11

	thumb_func_start task_intro_12
task_intro_12: @ 816DCFC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	cmp r0, 0x2B
	bls _0816DD18
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_intro_13
	str r0, [r1]
_0816DD18:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_12

	thumb_func_start task_intro_13
task_intro_13: @ 816DD28
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816DD94
	bl intro_reset_and_hide_bgs
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gUnknown_08D88494
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	ldr r0, =gUnknown_08D88D40
	ldr r1, =0x0600c000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D89F7C
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8A818
	ldr r1, =0x0600e000
	bl LZDecompressVram
	ldr r0, =gUnknown_08524D14
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0852561C
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r0, =gUnknown_08D85CD0
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 1
	bl CpuSet
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_14
	str r1, [r0]
_0816DD94:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_13

	thumb_func_start task_intro_14
task_intro_14: @ 816DDD8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0xA0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x0000b880
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =0x00001c05
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =0x00003641
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =0x0000ffa0
	strh r0, [r4, 0xA]
	ldr r1, =0x0000ff51
	strh r1, [r4, 0xC]
	movs r2, 0x80
	lsls r2, 1
	strh r2, [r4, 0xE]
	movs r3, 0
	bl sub_816F2A8
	ldr r0, =task_intro_15
	str r0, [r4]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_14

	thumb_func_start task_intro_15
task_intro_15: @ 816DE7C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r2, [r4, 0x8]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	beq _0816DEB8
	adds r0, r2, 0x4
	strh r0, [r4, 0x8]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r1, 8
	adds r0, r2, 0
	subs r0, 0x9C
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	b _0816DEC6
	.pool
_0816DEB8:
	movs r1, 0x82
	lsls r1, 6
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =task_intro_16
	str r0, [r4]
_0816DEC6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_15

	thumb_func_start task_intro_16
task_intro_16: @ 816DED0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =task_intro_17
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end task_intro_16

	thumb_func_start task_intro_17
task_intro_17: @ 816DEEC
	push {lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	ldr r0, =task_intro_18
	str r0, [r1]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0
	movs r1, 0xA0
	movs r2, 0x4
	movs r3, 0x4
	bl sub_80BA384
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_17

	thumb_func_start task_intro_18
task_intro_18: @ 816DF2C
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bhi _0816DF62
	ldrh r0, [r4, 0xA]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0816DF62
	ldrh r0, [r4, 0x8]
	movs r1, 0x3
	eors r0, r1
	strh r0, [r4, 0x8]
_0816DF62:
	ldrh r0, [r4, 0x2]
	ldrh r1, [r4, 0x8]
	ldrh r2, [r4, 0x4]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r4, 0x6]
	movs r3, 0
	bl sub_816F2A8
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	bls _0816DF80
	b _0816E176
_0816DF80:
	lsls r0, 2
	ldr r1, =_0816DF94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816DF94:
	.4byte _0816DFBC
	.4byte _0816DFE6
	.4byte _0816E024
	.4byte _0816E038
	.4byte _0816E07C
	.4byte _0816E09A
	.4byte _0816E0C8
	.4byte _0816E0DE
	.4byte _0816E13C
	.4byte _0816E156
_0816DFBC:
	ldrh r0, [r4, 0x2]
	adds r0, 0x10
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA0
	beq _0816DFCC
	b _0816E176
_0816DFCC:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0x2
	strh r0, [r4, 0xC]
	movs r2, 0xF1
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r4, 0xE]
	adds r0, r5, 0
	bl sub_816E190
	b _0816E176
_0816DFE6:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816DFF4
	b _0816E176
_0816DFF4:
	movs r0, 0x2
	strh r0, [r4, 0xC]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	ldr r1, =gUnknown_08D85CD0
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0x3E
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r4, 0xE]
	adds r0, 0x2
	strh r0, [r4, 0xE]
	lsls r0, 16
	movs r1, 0xF6
	lsls r1, 17
	cmp r0, r1
	beq _0816E01A
	b _0816E176
_0816E01A:
	b _0816E14E
	.pool
_0816E024:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E032
	b _0816E176
_0816E032:
	movs r0, 0x2
	strh r0, [r4, 0xC]
	b _0816E14E
_0816E038:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E046
	b _0816E176
_0816E046:
	movs r0, 0x2
	strh r0, [r4, 0xC]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	ldr r1, =gUnknown_08D85CD0
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0x3E
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r4, 0xE]
	subs r0, 0x2
	strh r0, [r4, 0xE]
	lsls r0, 16
	movs r1, 0xF0
	lsls r1, 17
	cmp r0, r1
	beq _0816E06C
	b _0816E176
_0816E06C:
	movs r0, 0x8
	strh r0, [r4, 0xC]
	b _0816E14E
	.pool
_0816E07C:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816E176
	movs r1, 0x60
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r4, 0x2]
	movs r0, 0xA9
	strh r0, [r4, 0x4]
	movs r0, 0x3
	strh r0, [r4, 0xC]
	b _0816E14E
_0816E09A:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _0816E176
	movs r0, 0x50
	strh r0, [r4, 0x2]
	movs r0, 0x29
	strh r0, [r4, 0x4]
	movs r0, 0x10
	strh r0, [r4, 0xC]
	ldr r0, =0x00000195
	str r1, [sp]
	movs r1, 0
	movs r2, 0x64
	movs r3, 0xA
	bl PlayCryInternal
	b _0816E14E
	.pool
_0816E0C8:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816E176
	movs r0, 0x50
	strh r0, [r4, 0x2]
	movs r0, 0x28
	strh r0, [r4, 0x4]
	b _0816E14E
_0816E0DE:
	ldrh r0, [r4, 0x2]
	adds r0, 0x4
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	adds r0, 0x4
	strh r0, [r4, 0x4]
	ldr r2, =0x00000666
	adds r0, r2, 0
	ldrh r1, [r4, 0xC]
	adds r0, r1
	strh r0, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	lsrs r0, 8
	movs r1, 0x40
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	strh r0, [r4, 0x6]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x78
	bne _0816E176
	movs r0, 0x2
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x6]
	movs r0, 0
	strh r0, [r4, 0x8]
	b _0816E14E
	.pool
_0816E13C:
	ldrh r1, [r4, 0x6]
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0816E14E
	adds r0, r1, 0
	subs r0, 0x8
	strh r0, [r4, 0x6]
	b _0816E176
_0816E14E:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0816E176
_0816E156:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816E176
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_19
	str r1, [r0]
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_0816E176:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_18

	thumb_func_start sub_816E190
sub_816E190: @ 816E190
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0
	ldr r6, =gSprites
	ldr r5, =gUnknown_085E4C64
_0816E19C:
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r3, r4, 24
	lsrs r3, 24
	ldr r0, =gUnknown_08596C10
	movs r2, 0xA0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, =sub_816E1F8
	str r1, [r0]
	adds r2, r6
	ldrb r0, [r2, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2, 0x5]
	strh r4, [r2, 0x30]
	strh r7, [r2, 0x36]
	ldrb r1, [r5, 0x2]
	adds r0, r2, 0
	bl StartSpriteAnim
	adds r5, 0x6
	adds r4, 0x1
	cmp r4, 0x5
	ble _0816E19C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816E190

	thumb_func_start sub_816E1F8
sub_816E1F8: @ 816E1F8
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x34]
	adds r0, 0x1
	strh r0, [r3, 0x34]
	ldrh r0, [r3, 0x34]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0816E214
	ldrh r0, [r3, 0x26]
	movs r1, 0x3
	eors r0, r1
	strh r0, [r3, 0x26]
_0816E214:
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0816E222
	cmp r0, 0x1
	beq _0816E278
	b _0816E29C
_0816E222:
	ldr r2, =gUnknown_085E4C64
	movs r0, 0x30
	ldrsh r1, [r3, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r2, 0x4
	adds r0, r2
	ldrh r2, [r0]
	ldrh r1, [r3, 0x32]
	adds r2, r1
	strh r2, [r3, 0x32]
	movs r0, 0x32
	ldrsh r1, [r3, r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r1, r0
	asrs r1, 8
	ldrh r0, [r3, 0x22]
	subs r0, r1
	strh r0, [r3, 0x22]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r3, 0x32]
	ldr r2, =gTasks
	movs r0, 0x36
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x7
	ble _0816E29C
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _0816E29C
	.pool
_0816E278:
	ldrh r1, [r3, 0x20]
	movs r2, 0x20
	ldrsh r0, [r3, r2]
	cmp r0, 0x77
	bgt _0816E286
	subs r0, r1, 0x2
	b _0816E288
_0816E286:
	adds r0, r1, 0x2
_0816E288:
	strh r0, [r3, 0x20]
	ldrh r1, [r3, 0x22]
	movs r2, 0x22
	ldrsh r0, [r3, r2]
	cmp r0, 0x4F
	bgt _0816E298
	subs r0, r1, 0x2
	b _0816E29A
_0816E298:
	adds r0, r1, 0x2
_0816E29A:
	strh r0, [r3, 0x22]
_0816E29C:
	pop {r0}
	bx r0
	thumb_func_end sub_816E1F8

	thumb_func_start task_intro_19
task_intro_19: @ 816E2A0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetSpriteData
	ldr r0, =gUnknown_08D89224
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	ldr r0, =gUnknown_08D89ABC
	ldr r1, =0x0600c000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8A934
	ldr r1, =0x0600e000
	bl LZDecompressVram
	ldr r0, =gUnknown_085E4C88
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E4C98
	bl LoadSpritePalette
	movs r0, 0x2
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_intro_20
	str r0, [r1]
	movs r4, 0
	strh r4, [r1, 0x8]
	movs r0, 0xA8
	lsls r0, 1
	strh r0, [r1, 0xA]
	movs r2, 0x50
	strh r2, [r1, 0xC]
	movs r2, 0x10
	strh r2, [r1, 0x14]
	adds r2, 0xF0
	strh r2, [r1, 0xE]
	movs r1, 0x50
	movs r3, 0
	bl sub_816F2A8
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0xA0
	movs r2, 0x4
	movs r3, 0x4
	bl sub_80BA384
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_19

	thumb_func_start task_intro_20
task_intro_20: @ 816E358
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrh r0, [r5, 0x2]
	ldrh r1, [r5, 0x4]
	ldrh r2, [r5, 0x6]
	movs r3, 0
	bl sub_816F2A8
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0xD
	bls _0816E380
	b _0816E6BC
_0816E380:
	lsls r0, 2
	ldr r1, =_0816E394
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816E394:
	.4byte _0816E3CC
	.4byte _0816E3E0
	.4byte _0816E43C
	.4byte _0816E488
	.4byte _0816E4C4
	.4byte _0816E4EC
	.4byte _0816E544
	.4byte _0816E560
	.4byte _0816E5A0
	.4byte _0816E5BC
	.4byte _0816E5FC
	.4byte _0816E61A
	.4byte _0816E664
	.4byte _0816E69C
_0816E3CC:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E3DA
	b _0816E6BC
_0816E3DA:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_0816E3E0:
	ldrh r0, [r5, 0xC]
	adds r0, 0x4
	strh r0, [r5, 0xC]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	movs r1, 0x80
	lsls r1, 1
	bl Sin
	ldr r1, =gTasks
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r1
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	strh r1, [r4, 0xA]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	movs r1, 0x40
	bl Cos
	movs r1, 0x54
	subs r1, r0
	strh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0x40
	beq _0816E420
	b _0816E6BC
_0816E420:
	movs r0, 0x19
	strh r0, [r5, 0xC]
	movs r0, 0x1
	strh r0, [r5, 0xE]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	movs r0, 0
	bl sub_816E6D4
	b _0816E6BC
	.pool
_0816E43C:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E44A
	b _0816E6BC
_0816E44A:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ldrh r2, [r1, 0xA]
	adds r0, r2
	strh r0, [r1, 0xA]
	ldr r2, =0xfffffefe
	adds r0, r2, 0
	ldrh r2, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	movs r0, 0x8
	strh r0, [r5, 0xC]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	movs r0, 0
	bl sub_816E6D4
	bl sub_816E74C
	b _0816E6BC
	.pool
_0816E488:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E496
	b _0816E6BC
_0816E496:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r2, =0xffffff00
	adds r0, r2, 0
	ldrh r2, [r1, 0xA]
	adds r0, r2
	strh r0, [r1, 0xA]
	movs r2, 0x81
	lsls r2, 1
	adds r0, r2, 0
	ldrh r2, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	movs r0, 0x8
	strh r0, [r5, 0xC]
	b _0816E690
	.pool
_0816E4C4:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E4D2
	b _0816E6BC
_0816E4D2:
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0xC]
	subs r1, 0xFC
	strh r1, [r0, 0xC]
	movs r0, 0x8
	strh r0, [r5, 0xC]
	b _0816E690
	.pool
_0816E4EC:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E4FA
	b _0816E6BC
_0816E4FA:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	adds r0, 0xFC
	strh r0, [r1, 0xC]
	ldrh r2, [r5, 0xE]
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _0816E528
	movs r0, 0xC
	strh r0, [r5, 0xC]
	subs r0, r2, 0x1
	strh r0, [r5, 0xE]
	movs r0, 0x2
	strh r0, [r5]
	b _0816E6BC
	.pool
_0816E528:
	movs r0, 0x1
	strh r0, [r5, 0xC]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	movs r0, 0xCA
	lsls r0, 1
	str r1, [sp]
	movs r1, 0
	movs r2, 0x78
	movs r3, 0xA
	bl PlayCryInternal
	b _0816E6BC
_0816E544:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E552
	b _0816E6BC
_0816E552:
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r1, 0xF5
	lsls r1, 1
	adds r0, r1, 0
	strh r0, [r5, 0xE]
	b _0816E690
_0816E560:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E56E
	b _0816E6BC
_0816E56E:
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	ldr r1, =gUnknown_08D85CD0
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0x5E
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r5, 0xE]
	subs r0, 0x2
	strh r0, [r5, 0xE]
	lsls r0, 16
	movs r1, 0xF0
	lsls r1, 17
	cmp r0, r1
	beq _0816E594
	b _0816E6BC
_0816E594:
	b _0816E690
	.pool
_0816E5A0:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0816E5AE
	b _0816E6BC
_0816E5AE:
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r1, 0xF1
	lsls r1, 1
	adds r0, r1, 0
	strh r0, [r5, 0xE]
	b _0816E690
_0816E5BC:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816E6BC
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	ldr r1, =gUnknown_08D85CD0
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0x5E
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r5, 0xE]
	adds r0, 0x2
	strh r0, [r5, 0xE]
	lsls r0, 16
	movs r1, 0xF7
	lsls r1, 17
	cmp r0, r1
	bne _0816E6BC
	movs r0, 0x10
	strh r0, [r5, 0xC]
	b _0816E690
	.pool
_0816E5FC:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _0816E6BC
	strh r0, [r5, 0xC]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_816E6D4
	b _0816E6BC
_0816E61A:
	ldrh r0, [r5, 0xC]
	adds r0, 0x4
	strh r0, [r5, 0xC]
	ldrh r0, [r5, 0x6]
	subs r0, 0x8
	strh r0, [r5, 0x6]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	movs r1, 0x3C
	bl Sin
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r2
	adds r0, 0x58
	strh r0, [r1, 0xA]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0x40
	bne _0816E6BC
	movs r0, 0x2
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0816E690
	.pool
_0816E664:
	ldrh r0, [r5, 0xC]
	adds r0, 0x4
	strh r0, [r5, 0xC]
	ldrh r0, [r5, 0x6]
	subs r0, 0x8
	strh r0, [r5, 0x6]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	movs r1, 0x14
	bl Sin
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r2
	adds r0, 0x80
	strh r0, [r1, 0xA]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0x80
	bne _0816E6BC
_0816E690:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _0816E6BC
	.pool
_0816E69C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816E6BC
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_21
	str r1, [r0]
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_0816E6BC:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_20

	thumb_func_start sub_816E6D4
sub_816E6D4: @ 816E6D4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r7, =gUnknown_085E4CA8
	ldr r0, =gSprites
	mov r9, r0
	adds r4, r7, 0
	movs r6, 0
_0816E6EE:
	movs r3, 0
	ldrsh r1, [r4, r3]
	adds r0, r7, 0x2
	adds r0, r6, r0
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r3, r5, 24
	lsrs r3, 24
	ldr r0, =gUnknown_085E4D14
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	mov r0, r8
	strh r0, [r2, 0x38]
	ldrh r0, [r4, 0x4]
	strh r0, [r2, 0x3A]
	movs r0, 0x40
	strh r0, [r2, 0x3C]
	adds r4, 0x6
	adds r6, 0x6
	adds r5, 0x1
	cmp r5, 0x5
	ble _0816E6EE
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816E6D4

	thumb_func_start sub_816E74C
sub_816E74C: @ 816E74C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	ldr r7, =gUnknown_085E4CA8
	adds r4, r7, 0x4
	movs r6, 0x24
	ldr r0, =gSprites
	mov r8, r0
_0816E75E:
	movs r3, 0x20
	ldrsh r1, [r4, r3]
	adds r0, r7, 0x2
	adds r0, r6, r0
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r3, r5, 24
	lsrs r3, 24
	ldr r0, =gUnknown_085E4D14
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r8
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4]
	strh r0, [r2, 0x3A]
	movs r0, 0x40
	strh r0, [r2, 0x3C]
	adds r4, 0x6
	adds r6, 0x6
	adds r5, 0x1
	cmp r5, 0x5
	ble _0816E75E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816E74C

	thumb_func_start sub_816E7B4
sub_816E7B4: @ 816E7B4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0816E7C6
	cmp r0, 0x1
	beq _0816E84C
	b _0816E882
_0816E7C6:
	ldrh r1, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0816E80A
	ldrh r0, [r4, 0x30]
	adds r0, 0xB
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x30
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0816E82A
	adds r0, r4, 0
	bl DestroySprite
	b _0816E82A
_0816E80A:
	subs r0, r1, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	cmp r0, 0
	bne _0816E82A
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0816E82A:
	ldr r2, =gTasks
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0xB
	ble _0816E882
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0816E882
	.pool
_0816E84C:
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x77
	bgt _0816E85A
	subs r0, r1, 0x3
	b _0816E85C
_0816E85A:
	adds r0, r1, 0x3
_0816E85C:
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x22]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0x4F
	bgt _0816E86C
	subs r0, r1, 0x3
	b _0816E86E
_0816E86C:
	adds r0, r1, 0x3
_0816E86E:
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x22]
	subs r0, 0x14
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8C
	bls _0816E882
	adds r0, r4, 0
	bl DestroySprite
_0816E882:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816E7B4

	thumb_func_start task_intro_21
task_intro_21: @ 816E888
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x50
	movs r1, 0x87
	bl SetGpuReg
	ldr r1, =0x00001f1f
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x1F
	bl SetGpuReg
	movs r1, 0xB0
	lsls r1, 7
	movs r0, 0x8
	bl SetGpuReg
	ldr r1, =0x00005a04
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =0x00001c06
	movs r0, 0xC
	bl SetGpuReg
	movs r1, 0xDD
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0x50
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x0000ffb0
	movs r0, 0x14
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
	ldr r4, =gUnknown_08D8AA54
	movs r1, 0xC0
	lsls r1, 19
	adds r0, r4, 0
	bl LZDecompressVram
	ldr r1, =0x06004000
	adds r0, r4, 0
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8B6E8
	ldr r1, =0x0600e000
	bl LZDecompressVram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_22
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_21

	thumb_func_start task_intro_22
task_intro_22: @ 816E954
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_08D8B180
	ldr r1, =0x0600c000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8B440
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_23
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_22

	thumb_func_start task_intro_23
task_intro_23: @ 816E998
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_24
	str r1, [r0]
	movs r1, 0
	strh r1, [r0, 0x8]
	movs r1, 0x10
	strh r1, [r0, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_23

	thumb_func_start task_intro_24
task_intro_24: @ 816E9DC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	ldrh r1, [r4, 0xC]
	lsls r1, 16
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x10
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	lsls r1, 16
	asrs r1, 24
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x14
	bl SetGpuReg
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0816EA24
	cmp r0, 0x1
	beq _0816EA58
	b _0816EAA6
	.pool
_0816EA24:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816EAA6
	movs r0, 0x2
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r2, 0xA0
	lsls r2, 7
	adds r0, r2, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0816EAA6
	.pool
_0816EA58:
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r0, 0xA0
	lsls r0, 6
	cmp r1, r0
	bne _0816EA74
	ldr r0, =0x0000fffe
	ldr r1, =0x00002949
	str r1, [sp]
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0816EA74:
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0816EA90
	adds r0, r1, 0
	subs r0, 0x80
	strh r0, [r4, 0xC]
	b _0816EAA6
	.pool
_0816EA90:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816EAA6
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =task_intro_25
	str r1, [r0]
_0816EAA6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_24

	thumb_func_start task_intro_25
task_intro_25: @ 816EAB8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_08D8C16C
	ldr r1, =0x0600e000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8CCC8
	ldr r1, =0x0600c000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8BA74
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D8C838
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	movs r1, 0xD5
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_intro_26
	str r1, [r0]
	movs r2, 0
	strh r2, [r0, 0x8]
	movs r1, 0x1
	strh r1, [r0, 0x14]
	strh r2, [r0, 0x16]
	ldr r0, =gUnknown_085E4BF4
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_085E4C04
	bl LoadSpritePalettes
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_25

	thumb_func_start task_intro_26
task_intro_26: @ 816EB44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r2, =gTasks + 0x8
	adds r6, r1, r2
	movs r3, 0
	ldrsh r0, [r6, r3]
	cmp r0, 0x1
	beq _0816EBE0
	cmp r0, 0x1
	bgt _0816EB6C
	cmp r0, 0
	beq _0816EB72
	b _0816EC62
	.pool
_0816EB6C:
	cmp r0, 0x2
	beq _0816EC4C
	b _0816EC62
_0816EB72:
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816EC62
	ldr r4, =gUnknown_085E4C4C
	adds r0, r4, 0
	movs r1, 0xC8
	movs r2, 0x30
	movs r3, 0
	bl CreateSprite
	adds r0, r4, 0
	movs r1, 0xC8
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0xC8
	movs r2, 0x70
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x2
	bl StartSpriteAnim
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r0, 0x48
	strh r0, [r6, 0xC]
	b _0816EC62
	.pool
_0816EBE0:
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816EC62
	ldr r4, =gUnknown_085E4C4C
	adds r0, r4, 0
	movs r1, 0x28
	movs r2, 0x30
	movs r3, 0
	bl CreateSprite
	adds r0, r4, 0
	movs r1, 0x28
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0x28
	movs r2, 0x70
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x2
	bl StartSpriteAnim
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r0, 0x30
	strh r0, [r6, 0xC]
	b _0816EC62
	.pool
_0816EC4C:
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0816EC62
	adds r0, r2, 0
	subs r0, 0x8
	adds r0, r1, r0
	ldr r1, =task_intro_27
	str r1, [r0]
_0816EC62:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_26

	thumb_func_start sub_816EC6C
sub_816EC6C: @ 816EC6C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0816EC88
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0816EC88:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816ECAC
	cmp r0, 0x1
	bgt _0816EC9A
	cmp r0, 0
	beq _0816ECA0
	b _0816ED12
_0816EC9A:
	cmp r0, 0x2
	beq _0816ECDC
	b _0816ED12
_0816ECA0:
	movs r0, 0xE1
	lsls r0, 1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0816ECAC:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldr r1, =gUnknown_08D85CD0
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0xBA
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	strh r0, [r4, 0x30]
	lsls r0, 16
	movs r1, 0xE7
	lsls r1, 17
	cmp r0, r1
	bne _0816ED12
	movs r0, 0xE6
	lsls r0, 1
	strh r0, [r4, 0x30]
	movs r0, 0x4
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0816ECDC:
	ldrh r0, [r4, 0x32]
	subs r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne _0816ED12
	movs r0, 0x4
	strh r0, [r4, 0x32]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldr r1, =gUnknown_08D85CD0
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0xBA
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r4, 0x30]
	subs r0, 0x2
	strh r0, [r4, 0x30]
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 17
	cmp r0, r1
	bne _0816ED12
	adds r0, r4, 0
	bl DestroySprite
_0816ED12:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816EC6C

	thumb_func_start task_intro_27
task_intro_27: @ 816ED20
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_085E5048
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E5058
	bl LoadSpritePalettes
	movs r1, 0xD5
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	ldr r6, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r6
	ldr r0, =task_intro_28
	str r0, [r4]
	ldr r0, =0x0000ffde
	ldr r1, =0x00002949
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	strh r0, [r4, 0x8]
	movs r0, 0xA8
	strh r0, [r4, 0xA]
	ldr r1, =0x0000fff0
	strh r1, [r4, 0xC]
	ldr r0, =0x0000ff78
	strh r0, [r4, 0xE]
	strh r1, [r4, 0x10]
	ldr r0, =sub_816EEA8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r6
	strh r5, [r1, 0x10]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_27

	thumb_func_start task_intro_28
task_intro_28: @ 816EDB4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r4, r1, 3
	ldr r5, =gTasks + 0x8
	adds r2, r4, r5
	ldrh r0, [r2, 0xE]
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	bne _0816EDD6
	ldrh r0, [r2, 0xC]
	movs r1, 0x2
	eors r0, r1
	strh r0, [r2, 0xC]
_0816EDD6:
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0x1
	beq _0816EE2E
	cmp r1, 0x1
	bgt _0816EDF4
	cmp r1, 0
	beq _0816EDFE
	b _0816EE86
	.pool
_0816EDF4:
	cmp r1, 0x2
	beq _0816EE3A
	cmp r1, 0x3
	beq _0816EE70
	b _0816EE86
_0816EDFE:
	ands r0, r3
	cmp r0, 0
	beq _0816EE1C
	ldrh r0, [r2, 0x2]
	subs r0, 0x2
	strh r0, [r2, 0x2]
	ldrh r0, [r2, 0x4]
	adds r0, 0x1
	strh r0, [r2, 0x4]
	ldrh r0, [r2, 0x6]
	adds r0, 0x2
	strh r0, [r2, 0x6]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_0816EE1C:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	cmp r0, 0x68
	bne _0816EE86
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	strh r3, [r2, 0xA]
	b _0816EE86
_0816EE2E:
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	movs r0, 0x4
	strh r0, [r2, 0xA]
	b _0816EE86
_0816EE3A:
	ldrh r0, [r2, 0x2]
	adds r0, 0x4
	strh r0, [r2, 0x2]
	ldrh r0, [r2, 0x4]
	subs r0, 0x2
	strh r0, [r2, 0x4]
	ldrh r0, [r2, 0x6]
	subs r0, 0x4
	strh r0, [r2, 0x6]
	ldrh r0, [r2, 0x8]
	subs r0, 0x2
	strh r0, [r2, 0x8]
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816EE86
	movs r0, 0x8C
	strh r0, [r2, 0xA]
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _0816EE86
	.pool
_0816EE70:
	ldrh r0, [r2, 0xA]
	subs r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _0816EE86
	adds r0, r5, 0
	subs r0, 0x8
	adds r0, r4, r0
	ldr r1, =task_intro_29
	str r1, [r0]
_0816EE86:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_28

	thumb_func_start task_intro_29
task_intro_29: @ 816EE90
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldr r0, =sub_816CC54
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_intro_29

	thumb_func_start sub_816EEA8
sub_816EEA8: @ 816EEA8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrh r0, [r5, 0x4]
	adds r0, 0x1
	strh r0, [r5, 0x4]
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x5
	bls _0816EECA
	b _0816F0B2
_0816EECA:
	lsls r0, 2
	ldr r1, =_0816EEDC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816EEDC:
	.4byte _0816EEF4
	.4byte _0816EF34
	.4byte _0816EF80
	.4byte _0816F00A
	.4byte _0816F074
	.4byte _0816F0A0
_0816EEF4:
	ldrh r1, [r5, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816EF16
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	lsls r0, 1
	ldr r1, =gUnknown_08D85E72
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0xBC
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
_0816EF16:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x6
	beq _0816EF20
	b _0816F0B2
_0816EF20:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	movs r0, 0
	strh r0, [r5, 0x2]
	b _0816EF70
	.pool
_0816EF34:
	ldrh r1, [r5, 0x6]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _0816F004
	ldrh r1, [r5, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816EF60
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	lsls r0, 1
	ldr r1, =gUnknown_08D85E72
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0xB0
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
_0816EF60:
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x6
	beq _0816EF6A
	b _0816F0B2
_0816EF6A:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_0816EF70:
	movs r0, 0xA
	strh r0, [r5, 0x6]
	b _0816F0B2
	.pool
_0816EF80:
	ldrh r1, [r5, 0x6]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _0816F004
	ldrh r1, [r5, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816EFAC
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	lsls r0, 1
	ldr r1, =gUnknown_08D85E52
	adds r0, r1
	ldr r1, =gPlttBufferFaded + 0xB8
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
_0816EFAC:
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x6
	beq _0816EFB6
	b _0816F0B2
_0816EFB6:
	ldr r0, =gUnknown_085E5030
	movs r1, 0x78
	movs r2, 0x58
	movs r3, 0xF
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x67
	bl PlaySE
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r3]
	ldrh r1, [r5, 0x8]
	strh r1, [r0, 0x34]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	movs r0, 0x10
	strh r0, [r5, 0x6]
	b _0816F0B2
	.pool
_0816F004:
	subs r0, r1, 0x1
	strh r0, [r5, 0x6]
	b _0816F0B2
_0816F00A:
	ldrh r1, [r5, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816F0B2
	ldrh r0, [r5, 0x6]
	subs r0, 0x1
	adds r2, r0, 0
	strh r0, [r5, 0x6]
	lsls r0, 16
	cmp r0, 0
	beq _0816F068
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =0x00002949
	movs r0, 0x50
	movs r1, 0x10
	bl BlendPalette
	ldr r4, =gUnknown_08D85E7C
	ldr r5, =gPlttBufferFaded + 0xBC
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	adds r1, r5, 0
	subs r1, 0xC
	adds r0, r4, 0
	movs r2, 0x1
	bl CpuSet
	subs r4, 0x20
	subs r5, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	b _0816F0B2
	.pool
_0816F068:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	movs r0, 0x35
	strh r0, [r5, 0x6]
	b _0816F0B2
_0816F074:
	ldrh r0, [r5, 0x6]
	subs r0, 0x1
	strh r0, [r5, 0x6]
	lsls r0, 16
	cmp r0, 0
	bne _0816F0B2
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _0816F0B2
	.pool
_0816F0A0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816F0B2
	adds r0, r2, 0
	bl DestroyTask
_0816F0B2:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816EEA8

	thumb_func_start intro_reset_and_hide_bgs
@ void intro_reset_and_hide_bgs()
intro_reset_and_hide_bgs: @ 816F0C0
	push {lr}
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
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
	pop {r0}
	bx r0
	thumb_func_end intro_reset_and_hide_bgs

	thumb_func_start task_intro_3_1
task_intro_3_1: @ 816F128
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816F170
	cmp r0, 0x1
	ble _0816F148
	cmp r0, 0x2
	beq _0816F1BC
_0816F148:
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gUnknown_0853FF70
	ldrh r1, [r0, 0x3E]
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	b _0816F1AC
	.pool
_0816F170:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0816F1A0
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	movs r1, 0xFF
	lsls r1, 1
	ldr r2, =gUnknown_0853FF70
	ands r0, r1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x52
	bl SetGpuReg
	b _0816F1DA
	.pool
_0816F1A0:
	ldr r0, =gUnknown_0853FF70
	ldrh r1, [r0]
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x10
_0816F1AC:
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0816F1DA
	.pool
_0816F1BC:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
_0816F1DA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_intro_3_1

	thumb_func_start task_intro_3_2
task_intro_3_2: @ 816F1E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816F228
	cmp r0, 0x1
	ble _0816F200
	cmp r0, 0x2
	beq _0816F274
_0816F200:
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gUnknown_0853FF70
	ldrh r1, [r0]
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	b _0816F264
	.pool
_0816F228:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x3D
	bgt _0816F258
	adds r0, r1, 0x1
	strh r0, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	movs r1, 0xFF
	lsls r1, 1
	ldr r2, =gUnknown_0853FF70
	ands r0, r1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x52
	bl SetGpuReg
	b _0816F2A2
	.pool
_0816F258:
	ldr r0, =gUnknown_0853FF70
	ldrh r1, [r0, 0x3E]
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x10
_0816F264:
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0816F2A2
	.pool
_0816F274:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0816F284
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	b _0816F2A2
_0816F284:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
_0816F2A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_intro_3_2

	thumb_func_start sub_816F2A8
sub_816F2A8: @ 816F2A8
	push {r4,lr}
	sub sp, 0x24
	lsls r2, 16
	lsrs r2, 16
	movs r4, 0x80
	lsls r4, 8
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r4, sp
	strh r0, [r4, 0x8]
	mov r0, sp
	strh r1, [r0, 0xA]
	strh r2, [r0, 0xC]
	strh r2, [r0, 0xE]
	strh r3, [r0, 0x10]
	add r4, sp, 0x14
	adds r1, r4, 0
	movs r2, 0x1
	bl BgAffineSet
	ldrh r1, [r4]
	movs r0, 0x20
	bl SetGpuReg
	ldrh r1, [r4, 0x2]
	movs r0, 0x22
	bl SetGpuReg
	ldrh r1, [r4, 0x4]
	movs r0, 0x24
	bl SetGpuReg
	ldrh r1, [r4, 0x6]
	movs r0, 0x26
	bl SetGpuReg
	ldrh r1, [r4, 0x8]
	movs r0, 0x28
	bl SetGpuReg
	ldrh r1, [r4, 0xA]
	movs r0, 0x2A
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	movs r0, 0x2C
	bl SetGpuReg
	ldrh r1, [r4, 0xE]
	movs r0, 0x2E
	bl SetGpuReg
	add sp, 0x24
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816F2A8

	thumb_func_start sub_816F318
sub_816F318: @ 816F318
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0xBF
	ble _0816F394
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0816F336
	subs r0, r1, 0x1
	strh r0, [r4, 0x34]
	b _0816F39A
_0816F336:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x32]
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 5
	subs r0, r1
	movs r1, 0x64
	bl __divsi3
	strh r0, [r4, 0x32]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	subs r0, 0xC0
	cmp r0, 0
	bge _0816F378
	adds r0, 0x7F
_0816F378:
	asrs r0, 7
	adds r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	bls _0816F386
	movs r0, 0xF
_0816F386:
	lsls r2, r0, 4
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x5]
	b _0816F39A
_0816F394:
	adds r0, r4, 0
	bl DestroySprite
_0816F39A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816F318

	thumb_func_start sub_816F3A4
sub_816F3A4: @ 816F3A4
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gSprites
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r3, 0x3C
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0816F420
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAnim
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 3
	strh r0, [r4, 0x34]
	ldr r0, =sub_816F318
	str r0, [r4, 0x1C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x2
	bl CalcCenterToCornerVec
	b _0816F44C
	.pool
_0816F420:
	ldrh r0, [r1, 0x24]
	strh r0, [r4, 0x24]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x26]
	strh r0, [r4, 0x26]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x20]
	strh r0, [r4, 0x20]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x22]
_0816F44C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816F3A4

	thumb_func_start sub_816F454
sub_816F454: @ 816F454
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0816F464
	ldr r0, =sub_816F46C
	str r0, [r1, 0x1C]
_0816F464:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F454

	thumb_func_start sub_816F46C
sub_816F46C: @ 816F46C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	ldrh r4, [r7, 0x20]
	movs r1, 0x20
	ldrsh r0, [r7, r1]
	cmp r0, 0x74
	bgt _0816F4AC
	ldrh r0, [r7, 0x26]
	ldrh r1, [r7, 0x22]
	adds r0, r1
	movs r1, 0
	strh r0, [r7, 0x22]
	strh r1, [r7, 0x26]
	adds r0, r4, 0x4
	strh r0, [r7, 0x20]
	ldr r0, =0x0000fffc
	strh r0, [r7, 0x24]
	movs r0, 0x80
	strh r0, [r7, 0x36]
	ldr r0, =sub_816F5B4
	str r0, [r7, 0x1C]
	b _0816F59E
	.pool
_0816F4AC:
	ldrh r1, [r7, 0x36]
	ldr r5, =gSineTable
	lsls r0, r1, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r2, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r3, [r0]
	adds r1, 0x2
	strh r1, [r7, 0x36]
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, 0
	bge _0816F4D2
	adds r0, 0x1F
_0816F4D2:
	asrs r0, 5
	strh r0, [r7, 0x26]
	subs r0, r4, 0x1
	strh r0, [r7, 0x20]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816F4E8
	ldrh r0, [r7, 0x22]
	adds r0, 0x1
	strh r0, [r7, 0x22]
_0816F4E8:
	lsls r0, r3, 16
	asrs r0, 16
	negs r0, r0
	cmp r0, 0
	bge _0816F4F4
	adds r0, 0xF
_0816F4F4:
	lsls r1, r0, 12
	lsrs r1, 16
	ldrh r4, [r7, 0x32]
	ldrh r3, [r7, 0x34]
	adds r0, r1, 0
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r2, [r0]
	adds r1, 0x30
	lsls r1, 24
	lsrs r1, 23
	adds r1, r5
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r1, 0
	muls r0, r4
	cmp r0, 0
	bge _0816F51E
	adds r0, 0xFF
_0816F51E:
	lsls r0, 8
	lsrs r0, 16
	mov r8, r0
	lsls r0, r2, 16
	asrs r2, r0, 16
	negs r0, r2
	muls r0, r3
	cmp r0, 0
	bge _0816F532
	adds r0, 0xFF
_0816F532:
	lsls r0, 8
	lsrs r0, 16
	mov r10, r0
	adds r0, r2, 0
	muls r0, r4
	cmp r0, 0
	bge _0816F542
	adds r0, 0xFF
_0816F542:
	lsls r0, 8
	lsrs r5, r0, 16
	adds r0, r1, 0
	muls r0, r3
	cmp r0, 0
	bge _0816F550
	adds r0, 0xFF
_0816F550:
	lsls r6, r0, 8
	lsrs r6, 16
	ldrh r0, [r7, 0x30]
	lsls r0, 24
	lsrs r0, 24
	str r3, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldrh r0, [r7, 0x30]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r5
	mov r1, r10
	lsls r5, r1, 16
	lsrs r3, r5, 16
	lsls r4, r6, 16
	str r6, [sp]
	mov r1, r8
	mov r2, r9
	bl SetOamMatrix
	ldrh r0, [r7, 0x30]
	adds r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 1
	lsrs r5, 16
	lsls r4, 1
	lsrs r4, 16
	str r4, [sp]
	mov r1, r8
	mov r2, r9
	adds r3, r5, 0
	bl SetOamMatrix
_0816F59E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F46C

	thumb_func_start sub_816F5B4
sub_816F5B4: @ 816F5B4
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	adds r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	adds r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	adds r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldrh r1, [r4, 0x36]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0x40
	beq _0816F64C
	adds r0, r1, 0
	subs r0, 0x8
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x36]
	adds r1, r0, 0
	ldr r2, =gSineTable
	adds r0, 0x40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bge _0816F62E
	adds r0, 0x3F
_0816F62E:
	asrs r0, 6
	strh r0, [r4, 0x24]
	lsls r0, r1, 24
	lsrs r0, 23
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _0816F642
	adds r0, 0x3F
_0816F642:
	asrs r0, 6
	strh r0, [r4, 0x26]
	b _0816F654
	.pool
_0816F64C:
	movs r0, 0
	strh r0, [r4, 0x36]
	ldr r0, =sub_816F660
	str r0, [r4, 0x1C]
_0816F654:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F5B4

	thumb_func_start sub_816F660
sub_816F660: @ 816F660
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x2
	beq _0816F6C0
	ldrh r0, [r1, 0x36]
	adds r0, 0x8
	strh r0, [r1, 0x36]
	ldr r3, =gSineTable
	lsls r0, 24
	lsrs r0, 23
	adds r0, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	bge _0816F684
	adds r0, 0xF
_0816F684:
	asrs r0, 4
	adds r0, 0x40
	lsls r0, 16
	lsrs r2, r0, 16
	adds r0, r2, 0
	adds r0, 0x40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	bge _0816F6A0
	adds r0, 0x3F
_0816F6A0:
	asrs r0, 6
	strh r0, [r1, 0x24]
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _0816F6B4
	adds r0, 0x3F
_0816F6B4:
	asrs r0, 6
	strh r0, [r1, 0x26]
	b _0816F6C4
	.pool
_0816F6C0:
	ldr r0, =sub_816F6D0
	str r0, [r1, 0x1C]
_0816F6C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F660

	thumb_func_start sub_816F6D0
sub_816F6D0: @ 816F6D0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x22]
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _0816F6E8
	adds r0, r2, 0x4
	strh r0, [r4, 0x22]
	b _0816F744
_0816F6E8:
	movs r0, 0x1
	strh r0, [r4, 0x3C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAnim
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 3
	strh r0, [r4, 0x34]
	ldr r0, =sub_816F318
	str r0, [r4, 0x1C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x2
	bl CalcCenterToCornerVec
_0816F744:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F6D0

	thumb_func_start sub_816F750
sub_816F750: @ 816F750
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x22]
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _0816F768
	adds r0, r2, 0x4
	strh r0, [r4, 0x22]
	b _0816F7C4
_0816F768:
	movs r0, 0x1
	strh r0, [r4, 0x3C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAnim
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 3
	strh r0, [r4, 0x34]
	ldr r0, =sub_816F318
	str r0, [r4, 0x1C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x2
	bl CalcCenterToCornerVec
_0816F7C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F750

	thumb_func_start sub_816F7D0
sub_816F7D0: @ 816F7D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r6, [sp, 0x34]
	ldr r0, [sp, 0x38]
	mov r8, r0
	lsls r4, 16
	lsls r5, 16
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x8]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0xC]
	lsls r6, 16
	lsrs r6, 16
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r0, =gUnknown_085E4D64
	lsrs r2, r4, 16
	mov r10, r2
	asrs r4, 16
	lsrs r1, r5, 16
	str r1, [sp, 0x4]
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gSprites
	mov r9, r2
	lsls r0, r7, 4
	adds r0, r7
	lsls r5, r0, 2
	adds r4, r5, r2
	movs r0, 0
	strh r0, [r4, 0x2E]
	strh r0, [r4, 0x3C]
	mov r0, sp
	ldrh r0, [r0, 0xC]
	strh r0, [r4, 0x30]
	mov r1, sp
	ldrh r1, [r1, 0x8]
	strh r1, [r4, 0x32]
	mov r2, sp
	ldrh r2, [r2, 0x8]
	strh r2, [r4, 0x34]
	strh r6, [r4, 0x38]
	mov r0, sp
	ldrh r0, [r0, 0x8]
	strh r0, [r4, 0x3A]
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x1F
	ldr r1, [sp, 0xC]
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl CalcCenterToCornerVec
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	mov r1, r8
	cmp r1, 0
	bne _0816F898
	mov r0, r9
	adds r0, 0x1C
	adds r0, r5, r0
	ldr r1, =sub_816F454
	b _0816F8A0
	.pool
_0816F898:
	mov r0, r9
	adds r0, 0x1C
	adds r0, r5, r0
	ldr r1, =sub_816F750
_0816F8A0:
	str r1, [r0]
	str r7, [sp, 0x10]
	mov r2, r10
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	ldr r0, [sp, 0x4]
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, =gUnknown_085E4D64
	mov r1, r10
	mov r2, r8
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gSprites
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	adds r0, r4, r5
	mov r1, sp
	ldrh r1, [r1, 0x10]
	strh r1, [r0, 0x3C]
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	mov r9, r2
	strh r2, [r0, 0x30]
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r2, r9
	movs r1, 0x1F
	ands r2, r1
	lsls r2, 1
	ldrb r3, [r0, 0x3]
	movs r6, 0x3F
	negs r6, r6
	adds r1, r6, 0
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x3]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl CalcCenterToCornerVec
	ldr r2, =gSprites + 0x1C
	adds r4, r2
	ldr r0, =sub_816F3A4
	str r0, [r4]
	ldr r0, =gUnknown_085E4D64
	mov r1, r10
	mov r2, r8
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	adds r5, r4, r5
	mov r1, sp
	ldrh r1, [r1, 0x10]
	strh r1, [r5, 0x3C]
	ldr r2, [sp, 0xC]
	adds r2, 0x2
	mov r8, r2
	strh r2, [r5, 0x30]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrb r0, [r5, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r5, 0x1]
	mov r0, r8
	movs r2, 0x1F
	ands r0, r2
	lsls r0, 1
	ldrb r1, [r5, 0x3]
	ands r6, r1
	orrs r6, r0
	strb r6, [r5, 0x3]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl CalcCenterToCornerVec
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r1, =sub_816F3A4
	str r1, [r4]
	ldr r2, [sp, 0xC]
	lsls r0, r2, 24
	lsrs r0, 24
	ldr r5, [sp, 0x8]
	adds r5, 0x20
	lsls r4, r5, 16
	lsrs r4, 16
	str r4, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	str r4, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r5, 17
	lsrs r5, 16
	str r5, [sp]
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	ldr r0, [sp, 0x10]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816F7D0

	thumb_func_start sub_816F9D4
sub_816F9D4: @ 816F9D4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _0816FA62
	lsls r0, 2
	ldr r1, =_0816F9F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816F9F0:
	.4byte _0816FA04
	.4byte _0816FA12
	.4byte _0816FA30
	.4byte _0816FA62
	.4byte _0816FA50
_0816FA04:
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	ldrh r0, [r4, 0x20]
	subs r0, 0x1
	b _0816FA60
_0816FA12:
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0816FAAA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	b _0816FA60
	.pool
_0816FA30:
	ldrh r2, [r4, 0x20]
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	ble _0816FA46
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0816FA6E
_0816FA46:
	adds r0, r2, 0x1
	b _0816FA60
	.pool
_0816FA50:
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _0816FA62
	subs r0, r2, 0x2
_0816FA60:
	strh r0, [r4, 0x20]
_0816FA62:
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0816FAAA
_0816FA6E:
	movs r1, 0x26
	ldrsh r5, [r4, r1]
	cmp r5, 0
	beq _0816FA80
	movs r0, 0
	strh r0, [r4, 0x26]
	b _0816FAAA
	.pool
_0816FA80:
	bl Random
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x1
	beq _0816FAA8
	cmp r1, 0x1
	bgt _0816FA96
	cmp r1, 0
	beq _0816FA9E
	b _0816FAAA
_0816FA96:
	cmp r1, 0x3
	bgt _0816FAAA
	strh r5, [r4, 0x26]
	b _0816FAAA
_0816FA9E:
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x26]
	b _0816FAAA
	.pool
_0816FAA8:
	strh r1, [r4, 0x26]
_0816FAAA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_816F9D4

	thumb_func_start sub_816FAB0
sub_816FAB0: @ 816FAB0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816FACA
	cmp r0, 0x1
	ble _0816FB12
	cmp r0, 0x2
	beq _0816FAEA
	cmp r0, 0x3
	beq _0816FB04
	b _0816FB12
_0816FACA:
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	adds r0, r1
	ldr r1, =0x0000012f
	cmp r0, r1
	bgt _0816FAE4
	ldrh r0, [r4, 0x24]
	adds r0, 0x8
	b _0816FB10
	.pool
_0816FAE4:
	movs r0, 0x2
	strh r0, [r4, 0x2E]
	b _0816FB12
_0816FAEA:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	adds r0, r1
	cmp r0, 0x78
	ble _0816FAFE
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	b _0816FB10
_0816FAFE:
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	b _0816FB12
_0816FB04:
	ldrh r1, [r4, 0x24]
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0816FB12
	subs r0, r1, 0x2
_0816FB10:
	strh r0, [r4, 0x24]
_0816FB12:
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x8
	bl Sin
	ldr r1, =gUnknown_0203BCCC
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x4
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816FAB0

	thumb_func_start sub_816FB38
sub_816FB38: @ 816FB38
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	cmp r0, 0x5
	bls _0816FB46
	b _0816FD38
_0816FB46:
	lsls r0, 2
	ldr r1, =_0816FB54
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816FB54:
	.4byte _0816FB6C
	.4byte _0816FB94
	.4byte _0816FBB4
	.4byte _0816FC5C
	.4byte _0816FCC4
	.4byte _0816FCF4
_0816FB6C:
	ldrh r1, [r6, 0x30]
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _0816FB7C
	subs r0, r1, 0x1
	strh r0, [r6, 0x30]
	b _0816FD38
_0816FB7C:
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	adds r0, r6, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _0816FCE6
_0816FB94:
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	cmp r0, 0x90
	beq _0816FB9E
	b _0816FD38
_0816FB9E:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
	movs r0, 0x9
	strh r0, [r6, 0x30]
	movs r0, 0x2
	strh r0, [r6, 0x34]
	b _0816FD38
	.pool
_0816FBB4:
	ldrh r1, [r6, 0x34]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0816FC66
	movs r0, 0x2
	strh r0, [r6, 0x34]
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0816FC14
	lsls r0, 1
	ldr r4, =gUnknown_08D85C50
	adds r0, r4
	ldr r5, =gPlttBufferFaded + 0x23E
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r1
	adds r1, r5, 0
	subs r1, 0x16
	movs r2, 0x1
	bl CpuSet
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r4, 0x40
	adds r0, r4
	subs r5, 0xA
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r6, 0x30]
	subs r0, 0x1
	strh r0, [r6, 0x30]
	b _0816FD38
	.pool
_0816FC14:
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	ldr r4, =gUnknown_08D85C50
	adds r0, r4
	ldr r5, =gPlttBufferFaded + 0x23E
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r1
	adds r1, r5, 0
	subs r1, 0x16
	movs r2, 0x1
	bl CpuSet
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r4, 0x40
	adds r0, r4
	subs r5, 0xA
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	b _0816FCE6
	.pool
_0816FC5C:
	ldrh r1, [r6, 0x34]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _0816FC6C
_0816FC66:
	subs r0, r1, 0x1
	strh r0, [r6, 0x34]
	b _0816FD38
_0816FC6C:
	movs r0, 0x2
	strh r0, [r6, 0x34]
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0x9
	bgt _0816FCE6
	lsls r0, 1
	ldr r4, =gUnknown_08D85C50
	adds r0, r4
	ldr r5, =gPlttBufferFaded + 0x23E
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r1
	adds r1, r5, 0
	subs r1, 0x16
	movs r2, 0x1
	bl CpuSet
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r4, 0x40
	adds r0, r4
	subs r5, 0xA
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r6, 0x30]
	adds r0, 0x1
	strh r0, [r6, 0x30]
	b _0816FD38
	.pool
_0816FCC4:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bne _0816FD38
	adds r0, r6, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldrb r1, [r6, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6, 0x1]
_0816FCE6:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
	b _0816FD38
	.pool
_0816FCF4:
	ldr r1, =gUnknown_085E4F48
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, 0x34]
	adds r0, r1
	strh r0, [r6, 0x34]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	asrs r0, 8
	strh r0, [r6, 0x24]
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x3
	bgt _0816FD24
	movs r2, 0x24
	ldrsh r0, [r6, r2]
	negs r0, r0
	strh r0, [r6, 0x24]
_0816FD24:
	adds r0, r6, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0816FD38
	adds r0, r6, 0
	bl DestroySprite
_0816FD38:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816FB38

	thumb_func_start sub_816FD44
sub_816FD44: @ 816FD44
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816FD7C
	cmp r0, 0x1
	bgt _0816FD5A
	cmp r0, 0
	beq _0816FD60
	b _0816FDB0
_0816FD5A:
	cmp r0, 0x2
	beq _0816FD9C
	b _0816FDB0
_0816FD60:
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	cmp r0, 0x80
	bne _0816FDB0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	b _0816FD90
	.pool
_0816FD7C:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bne _0816FDB0
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAffineAnim
_0816FD90:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0816FDB0
	.pool
_0816FD9C:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0816FDB0
	adds r0, r4, 0
	bl DestroySprite
_0816FDB0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816FD44

	thumb_func_start sub_816FDB8
sub_816FDB8: @ 816FDB8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x4]
	movs r7, 0
_0816FDD2:
	lsls r5, r7, 2
	ldr r0, =gUnknown_085E4E94
	adds r0, 0x2
	adds r0, r5, r0
	ldr r2, [sp]
	lsls r1, r2, 16
	asrs r1, 16
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	asrs r1, 16
	ldr r3, [sp, 0x4]
	lsls r2, r3, 16
	asrs r0, r2, 16
	str r0, [sp, 0x8]
	ldr r3, =0xfffc0000
	adds r2, r3
	ldr r0, =gUnknown_085E4F5C
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r1, 0
	strh r1, [r4, 0x2E]
	ldr r0, =gUnknown_085E4FA4
	adds r0, r7, r0
	ldrb r0, [r0]
	strh r0, [r4, 0x30]
	strh r7, [r4, 0x32]
	adds r1, r4, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	mov r10, r2
	mov r3, r10
	orrs r0, r3
	strb r0, [r1]
	adds r1, r7, 0
	adds r1, 0xC
	movs r0, 0x1F
	mov r9, r0
	mov r2, r9
	ands r1, r2
	lsls r1, 1
	ldrb r0, [r4, 0x3]
	movs r3, 0x3F
	negs r3, r3
	mov r8, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldr r3, =gUnknown_085E4E94
	adds r5, r3
	ldrb r1, [r5]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x8
	bls _0816FDD2
	ldr r0, =gUnknown_085E4F8C
	ldr r2, [sp, 0x8]
	subs r2, 0x6
	lsls r2, 16
	asrs r2, 16
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0
	strh r2, [r0, 0x2E]
	adds r2, r0, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	mov r3, r10
	orrs r1, r3
	strb r1, [r2]
	adds r2, r7, 0
	adds r2, 0xC
	mov r1, r9
	ands r2, r1
	lsls r2, 1
	ldrb r1, [r0, 0x3]
	mov r3, r8
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x3]
	movs r1, 0x1
	bl StartSpriteAffineAnim
	adds r0, r6, 0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816FDB8

	thumb_func_start sub_816FEDC
sub_816FEDC: @ 816FEDC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0816FF48
	ldr r2, =gSineTable
	ldrh r1, [r4, 0x32]
	lsls r0, r1, 24
	lsrs r0, 23
	adds r0, r2
	ldrh r3, [r0]
	adds r1, 0x40
	lsls r1, 24
	lsrs r1, 23
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r1, 0x30
	ldrsh r2, [r4, r1]
	adds r1, r0, 0
	muls r1, r2
	adds r0, r1, 0
	cmp r1, 0
	bge _0816FF18
	adds r0, 0xFF
_0816FF18:
	lsls r0, 8
	lsrs r6, r0, 16
	lsls r0, r3, 16
	asrs r3, r0, 16
	negs r0, r3
	muls r0, r2
	cmp r0, 0
	bge _0816FF2A
	adds r0, 0xFF
_0816FF2A:
	lsls r0, 8
	lsrs r5, r0, 16
	adds r0, r3, 0
	muls r0, r2
	cmp r0, 0
	bge _0816FF38
	adds r0, 0xFF
_0816FF38:
	lsls r0, 8
	lsrs r2, r0, 16
	adds r1, r6, 0
	adds r3, r5, 0
	str r1, [sp]
	movs r0, 0x1
	bl SetOamMatrix
_0816FF48:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _0816FF9C
	cmp r0, 0x1
	ble _0816FF58
	cmp r0, 0x2
	beq _0816FFFE
_0816FF58:
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x3
	bl CalcCenterToCornerVec
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x80
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x32]
	strh r1, [r4, 0x34]
	b _08170038
	.pool
_0816FF9C:
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x8C
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x78
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x7
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	strh r0, [r4, 0x34]
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bgt _08170038
	ldrb r0, [r4, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r4, 0x5]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x14
	strh r0, [r4, 0x20]
	movs r0, 0x28
	strh r0, [r4, 0x22]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	movs r0, 0x10
	b _08170036
_0816FFFE:
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x22
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3C
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	strh r0, [r4, 0x30]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08170038
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
_08170036:
	strh r0, [r4, 0x34]
_08170038:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_816FEDC

	thumb_func_start sub_8170040
sub_8170040: @ 8170040
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08170056
	adds r4, r5, 0
	adds r4, 0x3E
	cmp r0, 0x1
	beq _0817008E
_08170056:
	adds r4, r5, 0
	adds r4, 0x3E
	ldrb r1, [r4]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrb r0, [r5, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldrb r1, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x24
	orrs r0, r1
	strb r0, [r5, 0x3]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x3
	bl CalcCenterToCornerVec
	movs r0, 0
	strh r0, [r5, 0x30]
	movs r0, 0x1
	strh r0, [r5, 0x2E]
_0817008E:
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081700A6
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	b _081700BE
_081700A6:
	ldrb r0, [r4]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	ldrh r1, [r5, 0x30]
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	cmp r0, 0x3F
	bgt _081700BE
	adds r0, r1, 0x1
	strh r0, [r5, 0x30]
_081700BE:
	ldr r1, =gSineTable
	ldrh r0, [r5, 0x30]
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0x12
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170040

	.align 2, 0 @ Don't pad with nop.
