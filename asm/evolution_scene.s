	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_813D9B0
sub_813D9B0: @ 813D9B0
	push {lr}
	bl UpdatePaletteFade
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_813D9B0

	thumb_func_start sub_813D9C0
sub_813D9C0: @ 813D9C0
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	movs r7, 0
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r6, r0, r1
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0813D9E8
	cmp r0, 0x1
	beq _0813DA00
	b _0813DA30
	.pool
_0813D9E8:
	movs r0, 0x1
	negs r0, r0
	str r7, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _0813DA30
_0813DA00:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0813DA30
	movs r0, 0x1C
	ldrsh r1, [r6, r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	ldrh r4, [r6, 0xC]
	ldrb r5, [r6, 0xE]
	ldrb r6, [r6, 0x1C]
	adds r0, r2, 0
	bl DestroyTask
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl evolution_cutscene
_0813DA30:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D9C0

	thumb_func_start sub_813DA40
sub_813DA40: @ 813DA40
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =sub_813D9C0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r4, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r6, [r1, 0x1C]
	ldr r0, =sub_813D9B0
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813DA40

	thumb_func_start evolution_cutscene
evolution_cutscene: @ 813DA8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	adds r4, r0, 0
	mov r10, r1
	mov r0, r10
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x1C]
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r1, 0
	str r1, [sp, 0x14]
	add r0, sp, 0x14
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	bl CpuSet
	movs r0, 0x4C
	movs r1, 0
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
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	bl ResetPaletteFade
	ldr r0, =gUnknown_02022E14
	movs r2, 0
	strh r2, [r0]
	ldr r0, =gUnknown_02022E16
	strh r2, [r0]
	ldr r0, =gUnknown_02022E18
	strh r2, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r2, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r2, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r2, [r0]
	ldr r1, =gUnknown_02022E20
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gUnknown_02022E22
	movs r1, 0
	strh r1, [r0]
	ldr r1, =gUnknown_02022FF0
	movs r0, 0x9
	strb r0, [r1]
	bl c2_berry_program_update_menu
	bl sub_8035AA4
	bl ResetSpriteData
	bl remove_some_task
	bl ResetTasks
	bl FreeAllSpritePalettes
	ldr r0, =gReservedSpritePaletteCount
	movs r2, 0x4
	strb r2, [r0]
	movs r0, 0x64
	bl AllocZeroed
	ldr r1, =gUnknown_0203AB80
	str r0, [r1]
	bl init_uns_table_pokemon_copy
	adds r0, r4, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar1
	mov r1, sp
	bl StringCopy10
	ldr r0, =gStringVar2
	movs r1, 0xB
	mov r2, r10
	muls r2, r1
	adds r1, r2, 0
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x20]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	mov r9, r0
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r2, =gUnknown_020244D4
	ldr r1, [r2]
	ldr r1, [r1, 0x8]
	adds r2, r5, 0
	bl DecompressPicFromTable_2
	adds r0, r5, 0
	ldr r1, [sp, 0x20]
	mov r2, r9
	bl sub_806E7CC
	ldr r0, [r0]
	movs r1, 0x88
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r8, r0
	ldr r1, =gDummySpriteAffineAnimTable
	str r1, [r0, 0x10]
	movs r1, 0x78
	movs r2, 0x40
	movs r3, 0x1E
	bl CreateSprite
	ldr r1, =gUnknown_0203AB80
	ldr r2, [r1]
	lsls r1, r0, 24
	lsrs r3, r1, 24
	strb r0, [r2]
	ldr r7, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r6, r7, 0
	adds r6, 0x1C
	adds r0, r1, r6
	ldr r2, =nullsub_18
	str r2, [r0]
	adds r1, r7
	ldrb r2, [r1, 0x5]
	movs r4, 0xF
	adds r0, r4, 0
	ands r0, r2
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x5]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	mov r1, r10
	lsls r0, r1, 3
	ldr r2, =gMonFrontPicTable
	adds r0, r2
	ldr r2, =gUnknown_020244D4
	ldr r1, [r2]
	ldr r1, [r1, 0x10]
	mov r2, r10
	bl DecompressPicFromTable_2
	mov r0, r10
	ldr r1, [sp, 0x20]
	mov r2, r9
	bl sub_806E7CC
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	mov r0, r10
	movs r1, 0x3
	bl sub_806A068
	ldr r0, =gDummySpriteAffineAnimTable
	mov r1, r8
	str r0, [r1, 0x10]
	mov r0, r8
	movs r1, 0x78
	movs r2, 0x40
	movs r3, 0x1E
	bl CreateSprite
	ldr r1, =gUnknown_0203AB80
	ldr r2, [r1]
	lsls r1, r0, 24
	lsrs r3, r1, 24
	strb r0, [r2, 0x1]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r6, r1, r6
	ldr r2, =nullsub_18
	str r2, [r6]
	adds r1, r7
	ldrb r0, [r1, 0x5]
	ands r4, r0
	movs r0, 0x20
	orrs r4, r0
	strb r4, [r1, 0x5]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl sub_817BE78
	ldr r0, =evovle_mon_maybe
	movs r1, 0
	bl CreateTask
	ldr r1, =gUnknown_0203AB80
	ldr r2, [r1]
	lsls r1, r0, 24
	lsrs r3, r1, 24
	strb r0, [r2, 0x2]
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	strh r2, [r0, 0x8]
	strh r5, [r0, 0xA]
	mov r1, r10
	strh r1, [r0, 0xC]
	mov r2, sp
	ldrh r2, [r2, 0x18]
	strh r2, [r0, 0xE]
	movs r1, 0x1
	strh r1, [r0, 0x10]
	movs r1, 0
	strh r1, [r0, 0x1A]
	mov r2, sp
	ldrh r2, [r2, 0x1C]
	strh r2, [r0, 0x1C]
	ldr r1, =gUnknown_0203AB80
	ldr r0, [r1]
	ldr r1, =gPlttBufferUnfaded + 0x40
	adds r0, 0x4
	movs r2, 0x60
	bl memcpy
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =nullsub_83
	bl SetHBlankCallback
	ldr r0, =sub_813FCDC
	bl SetVBlankCallback
	bl m4aMPlayAllStop
	ldr r0, =sub_813E3A4
	bl SetMainCallback2
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end evolution_cutscene

	thumb_func_start sub_813DD7C
sub_813DD7C: @ 813DD7C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203AB80
	mov r8, r0
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x1C
	ldrsh r2, [r0, r1]
	movs r1, 0x64
	adds r4, r2, 0
	muls r4, r1
	ldr r1, =gPlayerParty
	adds r4, r1
	ldrh r5, [r0, 0xC]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	mov r9, r0
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r6, r0, 0
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r4, 0
	str r4, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	add r0, sp, 0x4
	bl CpuSet
	movs r0, 0x4C
	movs r1, 0
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
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	bl ResetPaletteFade
	ldr r0, =gUnknown_02022E14
	strh r4, [r0]
	ldr r0, =gUnknown_02022E16
	strh r4, [r0]
	ldr r0, =gUnknown_02022E18
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r4, [r0]
	ldr r1, =gUnknown_02022E20
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gUnknown_02022E22
	strh r4, [r0]
	ldr r1, =gUnknown_02022FF0
	movs r0, 0x9
	strb r0, [r1]
	bl c2_berry_program_update_menu
	bl sub_8035AA4
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x10]
	adds r2, r5, 0
	bl DecompressPicFromTable_2
	adds r0, r5, 0
	mov r1, r9
	adds r2, r6, 0
	bl sub_806E7CC
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	ldr r1, =gDummySpriteAffineAnimTable
	str r1, [r0, 0x10]
	movs r1, 0x78
	movs r2, 0x40
	movs r3, 0x1E
	bl CreateSprite
	mov r2, r8
	ldr r1, [r2]
	lsls r2, r0, 24
	lsrs r2, 24
	strb r0, [r1, 0x1]
	ldr r3, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =nullsub_18
	str r2, [r0]
	adds r1, r3
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	movs r2, 0x20
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =nullsub_83
	bl SetHBlankCallback
	ldr r0, =sub_813FCDC
	bl SetVBlankCallback
	ldr r0, =sub_813E3A4
	bl SetMainCallback2
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813DD7C

	thumb_func_start sub_813DF70
sub_813DF70: @ 813DF70
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x1C
	ldrsh r2, [r0, r1]
	movs r1, 0x64
	muls r2, r1
	ldr r1, =gPlayerParty
	adds r4, r2, r1
	ldrh r6, [r0, 0xC]
	ldr r0, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _0813DFA2
	b _0813E1C8
_0813DFA2:
	lsls r0, 2
	ldr r1, =_0813DFC0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813DFC0:
	.4byte _0813DFE0
	.4byte _0813E050
	.4byte _0813E078
	.4byte _0813E07E
	.4byte _0813E0A8
	.4byte _0813E0F0
	.4byte _0813E160
	.4byte _0813E198
_0813DFE0:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r0, =gUnknown_02022E18
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r1, [r0]
	ldr r2, =gUnknown_02022E20
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	strh r0, [r2]
	ldr r0, =gUnknown_02022E22
	strh r1, [r0]
	b _0813E180
	.pool
_0813E050:
	bl ResetPaletteFade
	ldr r0, =nullsub_83
	bl SetHBlankCallback
	ldr r0, =sub_813FD64
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _0813E188
	.pool
_0813E078:
	bl sub_807F19C
	b _0813E180
_0813E07E:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _0813E188
	.pool
_0813E0A8:
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r0, r6, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x10]
	adds r2, r6, 0
	bl DecompressPicFromTable_2
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_806E7CC
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	b _0813E180
	.pool
_0813E0F0:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	ldr r1, =gDummySpriteAffineAnimTable
	str r1, [r0, 0x10]
	movs r1, 0x78
	movs r2, 0x40
	movs r3, 0x1E
	bl CreateSprite
	ldr r1, =gUnknown_0203AB80
	ldr r1, [r1]
	lsls r2, r0, 24
	lsrs r2, 24
	strb r0, [r1, 0x1]
	ldr r3, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =nullsub_18
	str r2, [r0]
	adds r1, r3
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	movs r2, 0x20
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r1, =gMain
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_807B154
	b _0813E1C8
	.pool
_0813E160:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _0813E174
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
_0813E174:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
_0813E180:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_0813E188:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0813E1C8
	.pool
_0813E198:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	bl sub_807B140
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	ldr r0, =sub_813E3C0
	bl SetMainCallback2
	movs r1, 0x9A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
_0813E1C8:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813DF70

	thumb_func_start sub_813E1D4
sub_813E1D4: @ 813E1D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar1
	mov r1, sp
	bl StringCopy10
	ldr r0, =gStringVar2
	movs r1, 0xB
	muls r1, r5
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r1, =gAffineAnimsDisabled
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r7, r0, 0
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	mov r10, r0
	ldr r1, =gUnknown_0203AB80
	mov r9, r1
	movs r0, 0x64
	bl AllocZeroed
	mov r2, r9
	str r0, [r2]
	movs r4, 0
	strb r6, [r0]
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	adds r2, r5, 0
	bl DecompressPicFromTable_2
	adds r0, r5, 0
	mov r1, r10
	adds r2, r7, 0
	bl sub_806E7CC
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 1
	movs r2, 0x20
	bl LoadCompressedPalette
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	ldr r1, =gDummySpriteAffineAnimTable
	str r1, [r0, 0x10]
	movs r1, 0x78
	movs r2, 0x40
	movs r3, 0x1E
	bl CreateSprite
	mov r1, r9
	ldr r2, [r1]
	lsls r1, r0, 24
	lsrs r6, r1, 24
	strb r0, [r2, 0x1]
	ldr r3, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =nullsub_18
	str r2, [r0]
	adds r1, r3
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	movs r2, 0x20
	orrs r0, r2
	strb r0, [r1, 0x5]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl sub_817BE78
	ldr r0, =sub_813F1B8
	movs r1, 0
	bl CreateTask
	mov r1, r9
	ldr r2, [r1]
	lsls r1, r0, 24
	lsrs r6, r1, 24
	strb r0, [r2, 0x2]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	mov r2, r8
	strh r2, [r0, 0xA]
	strh r5, [r0, 0xC]
	movs r1, 0x1
	strh r1, [r0, 0x10]
	strh r4, [r0, 0x1A]
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0x1C]
	ldr r0, =gUnknown_02022E14
	strh r4, [r0]
	ldr r0, =gUnknown_02022E16
	strh r4, [r0]
	ldr r0, =gUnknown_02022E18
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r4, [r0]
	ldr r1, =gUnknown_02022E20
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gUnknown_02022E22
	strh r4, [r0]
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_813FD64
	bl SetVBlankCallback
	ldr r0, =sub_813E3C0
	bl SetMainCallback2
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813E1D4

	thumb_func_start sub_813E3A4
sub_813E3A4: @ 813E3A4
	push {lr}
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_813E3A4

	thumb_func_start sub_813E3C0
sub_813E3C0: @ 813E3C0
	push {lr}
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_813E3C0

	thumb_func_start evovle_mon_internal_maybe
evovle_mon_internal_maybe: @ 813E3DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r1, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	movs r0, 0
	str r0, [sp]
	mov r0, r10
	lsls r0, 2
	str r0, [sp, 0x8]
	add r0, r10
	lsls r7, r0, 3
	ldr r1, =gEvolutionTable
	adds r1, r7
	mov r8, r1
	ldrh r0, [r1]
	cmp r0, 0xD
	beq _0813E40C
	b _0813E546
_0813E40C:
	ldr r6, =gPlayerPartyCount
	ldrb r0, [r6]
	cmp r0, 0x5
	bls _0813E416
	b _0813E546
_0813E416:
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	mov r9, r0
	ldr r1, [sp, 0x4]
	movs r2, 0x64
	bl CopyMon
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	ldr r1, =gEvolutionTable
	adds r2, r1, r7
	adds r2, 0xC
	movs r1, 0xB
	bl SetMonData
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	mov r1, r8
	ldrh r2, [r1, 0xC]
	movs r1, 0xB
	muls r2, r1
	ldr r1, =gSpeciesNames
	adds r2, r1
	movs r1, 0x2
	bl SetMonData
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x8
	mov r2, sp
	bl SetMonData
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0xA
	mov r2, sp
	bl SetMonData
	movs r4, 0x32
	ldr r0, [sp, 0x8]
	mov r8, r0
	adds r5, r6, 0
_0813E484:
	ldrb r1, [r5]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	mov r2, sp
	bl SetMonData
	adds r4, 0x1
	cmp r4, 0x36
	ble _0813E484
	movs r4, 0x43
	ldr r7, =gPlayerPartyCount
_0813E4A0:
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	adds r1, r4, 0
	mov r2, sp
	bl SetMonData
	adds r4, 0x1
	cmp r4, 0x4F
	ble _0813E4A0
	ldr r4, =gPlayerPartyCount
	ldrb r0, [r4]
	muls r0, r6
	adds r0, r5
	movs r1, 0x37
	mov r2, sp
	bl SetMonData
	movs r0, 0xFF
	str r0, [sp]
	ldrb r0, [r4]
	muls r0, r6
	adds r0, r5
	movs r1, 0x40
	mov r2, sp
	bl SetMonData
	ldrb r0, [r4]
	muls r0, r6
	adds r0, r5
	bl CalculateMonStats
	bl CalculatePlayerPartyCount
	ldr r0, =gEvolutionTable
	mov r4, r8
	add r4, r10
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0xC]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2
	bl pokedex_flag_operation
	ldrh r0, [r4, 0xC]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl pokedex_flag_operation
	mov r0, r9
	movs r1, 0xB
	bl GetMonData
	ldr r1, =0x0000012f
	cmp r0, r1
	bne _0813E546
	mov r0, r9
	movs r1, 0x3
	bl GetMonData
	cmp r0, 0x1
	bne _0813E546
	ldr r0, [sp, 0x4]
	movs r1, 0xB
	bl GetMonData
	movs r1, 0x97
	lsls r1, 1
	cmp r0, r1
	bne _0813E546
	ldr r2, =gUnknown_085B58C4
	mov r0, r9
	movs r1, 0x2
	bl SetMonData
_0813E546:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end evovle_mon_internal_maybe

	thumb_func_start evovle_mon_maybe
evovle_mon_maybe: @ 813E570
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r3, r0, r2
	movs r0, 0x1C
	ldrsh r1, [r3, r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	mov r9, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	adds r5, r2, 0
	adds r6, r0, 0
	cmp r1, 0x2
	bne _0813E5F0
	movs r1, 0x8
	ldrsh r0, [r3, r1]
	cmp r0, 0x8
	bne _0813E5F0
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813E5F0
	ldrh r1, [r3, 0xE]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0813E5F0
	movs r0, 0x11
	strh r0, [r3, 0x8]
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0x18]
	bl sub_8140134
	bl _0813F1A4
	.pool
_0813E5F0:
	lsls r1, r7, 2
	adds r0, r1, r7
	lsls r0, 3
	adds r0, r5
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	mov r8, r1
	cmp r0, 0x16
	bls _0813E606
	bl _0813F1A4
_0813E606:
	lsls r0, 2
	ldr r1, =_0813E614
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813E614:
	.4byte _0813E670
	.4byte _0813E6D4
	.4byte _0813E714
	.4byte _0813E740
	.4byte _0813E770
	.4byte _0813E7B0
	.4byte _0813E7E8
	.4byte _0813E828
	.4byte _0813E860
	.4byte _0813E8A4
	.4byte _0813E8C0
	.4byte _0813E8EC
	.4byte _0813E918
	.4byte _0813E964
	.4byte _0813E990
	.4byte _0813EA1C
	.4byte _0813EAC8
	.4byte _0813EB34
	.4byte _0813EB74
	.4byte _0813EBA8
	.4byte _0813EC10
	.4byte _0813EC6C
	.4byte _0813ECA8
_0813E670:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl _0813F1A4
	.pool
_0813E6D4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813E6E4
	bl _0813F1A4
_0813E6E4:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085CC990
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	b _0813EC52
	.pool
_0813E714:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813E724
	bl _0813F1A4
_0813E724:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0]
	ldr r1, =gTasks
	mov r3, r8
	adds r4, r3, r7
	lsls r4, 3
	adds r4, r1
	b _0813EB90
	.pool
_0813E740:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0]
	bl sub_8140208
	cmp r0, 0
	bne _0813E752
	bl _0813F1A4
_0813E752:
	movs r0, 0xBC
	lsls r0, 1
	bl PlaySE
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	b _0813EC52
	.pool
_0813E770:
	bl IsSEPlaying
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0813E780
	bl _0813F1A4
_0813E780:
	ldr r0, =0x00000179
	bl PlayNewMapMusic
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r4, [sp]
	movs r0, 0x1C
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl _0813F1A4
	.pool
_0813E7B0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813E7C0
	bl _0813F1A4
_0813E7C0:
	movs r0, 0
	bl sub_8140000
	movs r0, 0x11
	bl sub_817BE94
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x2]
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	b _0813EC52
	.pool
_0813E7E8:
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813E7FE
	bl _0813F1A4
_0813E7FE:
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r5
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r0, =gUnknown_0203AB80
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x3]
	bl sub_817BFB4
	strb r0, [r4, 0x2]
	bl _0813F1A4
	.pool
_0813E828:
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813E83E
	bl _0813F1A4
_0813E83E:
	ldr r0, =gUnknown_0203AB80
	ldr r1, [r0]
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl sub_817C3A0
	strb r0, [r4, 0x2]
	mov r0, r8
	adds r1, r0, r7
	lsls r1, 3
	adds r1, r5
	b _0813EC52
	.pool
_0813E860:
	ldr r2, =gUnknown_0203AB80
	ldr r1, [r2]
	ldrb r0, [r1, 0x3]
	subs r0, 0x1
	strb r0, [r1, 0x3]
	lsls r0, 24
	cmp r0, 0
	beq _0813E874
	bl _0813F1A4
_0813E874:
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x3]
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0813E890
	bl _0813F1A4
_0813E890:
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r5
	b _0813EC52
	.pool
_0813E8A4:
	bl sub_817C068
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x2]
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	b _0813EC52
	.pool
_0813E8C0:
	ldr r6, =gBattleCommunication
	ldrb r0, [r6, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813E8D6
	bl _0813F1A4
_0813E8D6:
	mov r0, r8
	adds r4, r0, r7
	lsls r4, 3
	adds r4, r5
	ldrh r0, [r4, 0xC]
	bl sub_817C144
	strb r0, [r6, 0x2]
	b _0813EB96
	.pool
_0813E8EC:
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0813E902
	bl _0813F1A4
_0813E902:
	movs r0, 0x21
	bl PlaySE
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r5
	b _0813EC52
	.pool
_0813E918:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813E926
	bl _0813F1A4
_0813E926:
	bl m4aMPlayAllStop
	ldr r0, =gPlttBufferUnfaded + 0x40
	ldr r1, =gUnknown_0203AB80
	ldr r1, [r1]
	adds r1, 0x4
	movs r2, 0x60
	bl memcpy
	bl sub_8140174
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1C
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	b _0813EC52
	.pool
_0813E964:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813E974
	bl _0813F1A4
_0813E974:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	mov r1, r8
	adds r4, r1, r7
	lsls r4, 3
	adds r4, r5
	ldrh r1, [r4, 0xC]
	b _0813EB92
	.pool
_0813E990:
	bl IsCryFinished
	lsls r0, 24
	cmp r0, 0
	bne _0813E99E
	bl _0813F1A4
_0813E99E:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085CC9A6
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =0x00000173
	bl PlayBGM
	ldr r2, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	adds r2, r1
	adds r2, 0xC
	mov r0, r9
	movs r1, 0xB
	bl SetMonData
	mov r0, r9
	bl CalculateMonStats
	ldrh r1, [r4, 0xA]
	ldrh r2, [r4, 0xC]
	mov r0, r9
	bl sub_806D778
	ldrh r0, [r4, 0xC]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2
	bl pokedex_flag_operation
	ldrh r0, [r4, 0xC]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl pokedex_flag_operation
	movs r0, 0xE
	bl IncrementGameStat
	b _0813F1A4
	.pool
_0813EA1C:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813EA2A
	b _0813F1A4
_0813EA2A:
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r4, r0, r1
	ldrb r1, [r4, 0x10]
	mov r0, r9
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _0813EAA8
	movs r3, 0x1A
	ldrsh r5, [r4, r3]
	cmp r5, 0
	bne _0813EAA8
	ldrh r1, [r4, 0xE]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0813EA5E
	bl StopMapMusic
	bl sub_8085784
_0813EA5E:
	ldrh r0, [r4, 0xE]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r4, 0xE]
	strh r5, [r4, 0x10]
	strh r5, [r4, 0x14]
	mov r0, r9
	movs r1, 0x2
	add r2, sp, 0x4
	bl GetMonData
	ldr r0, =gBattleTextBuff1
	add r1, sp, 0x4
	bl StringCopy10
	ldr r0, =0x0000ffff
	cmp r6, r0
	bne _0813EA94
	movs r0, 0x16
	strh r0, [r4, 0x8]
	b _0813F1A4
	.pool
_0813EA94:
	ldr r0, =0x0000fffe
	cmp r6, r0
	bne _0813EA9C
	b _0813F1A4
_0813EA9C:
	movs r0, 0x14
	strh r0, [r4, 0x8]
	b _0813F1A4
	.pool
_0813EAA8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	b _0813EC52
	.pool
_0813EAC8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r2, 0x80
	adds r0, r2, 0
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _0813EADC
	b _0813F1A4
_0813EADC:
	mov r3, r8
	adds r0, r3, r7
	lsls r0, 3
	adds r4, r0, r5
	ldrh r1, [r4, 0xE]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0813EAF6
	bl StopMapMusic
	bl sub_8085784
_0813EAF6:
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0813EB06
	ldrh r0, [r4, 0xA]
	mov r1, r9
	bl evovle_mon_internal_maybe
_0813EB06:
	adds r0, r7, 0
	bl DestroyTask
	bl sub_805F094
	ldr r4, =gUnknown_0203AB80
	ldr r0, [r4]
	bl Free
	str r6, [r4]
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_030061E8
	ldr r0, [r0]
	bl SetMainCallback2
	b _0813F1A4
	.pool
_0813EB34:
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0813EB48
	b _0813F1A4
_0813EB48:
	bl m4aMPlayAllStop
	ldr r0, =0x0006001c
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r5
	b _0813EC52
	.pool
_0813EB74:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813EB82
	b _0813F1A4
_0813EB82:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0]
	mov r3, r8
	adds r4, r3, r7
	lsls r4, 3
	adds r4, r5
_0813EB90:
	ldrh r1, [r4, 0xA]
_0813EB92:
	bl sub_81401E0
_0813EB96:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0813F1A4
	.pool
_0813EBA8:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0]
	bl sub_8140208
	cmp r0, 0
	bne _0813EBB8
	b _0813F1A4
_0813EBB8:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r3, 0x1A
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0813EBE4
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085CC9EE
	bl StringExpandPlaceholders
	b _0813EBEC
	.pool
_0813EBE4:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085CC9D3
	bl StringExpandPlaceholders
_0813EBEC:
	ldr r0, =gStringVar4
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x1A]
	b _0813F16E
	.pool
_0813EC10:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813EC1E
	b _0813F1A4
_0813EC1E:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813EC2A
	b _0813F1A4
_0813EC2A:
	bl sub_804F574
	ldr r0, =0x0000016f
	bl PlayFanfare
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0xC]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x40
	strh r0, [r1, 0x10]
_0813EC52:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0813F1A4
	.pool
_0813EC6C:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813EC7A
	b _0813F1A4
_0813EC7A:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813EC86
	b _0813F1A4
_0813EC86:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x10]
	subs r0, 0x1
	strh r0, [r1, 0x10]
	lsls r0, 16
	cmp r0, 0
	beq _0813EC9E
	b _0813F1A4
_0813EC9E:
	movs r0, 0xF
	strh r0, [r1, 0x8]
	b _0813F1A4
	.pool
_0813ECA8:
	mov r3, r8
	adds r0, r3, r7
	lsls r0, 3
	adds r0, r5
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	cmp r0, 0xC
	bls _0813ECBA
	b _0813F1A4
_0813ECBA:
	lsls r0, 2
	ldr r1, =_0813ECC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813ECC8:
	.4byte _0813ECFC
	.4byte _0813ED48
	.4byte _0813ED90
	.4byte _0813EDCE
	.4byte _0813EE34
	.4byte _0813EF30
	.4byte _0813EF88
	.4byte _0813F05C
	.4byte _0813F090
	.4byte _0813F0D8
	.4byte _0813F120
	.4byte _0813F154
	.4byte _0813F180
_0813ECFC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813ED0A
	b _0813F1A4
_0813ED0A:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813ED16
	b _0813F1A4
_0813ED16:
	bl sub_804F574
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x10]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813F1A2
	.pool
_0813ED48:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813ED56
	b _0813F1A4
_0813ED56:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813ED62
	b _0813F1A4
_0813ED62:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x14]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813F1A2
	.pool
_0813ED90:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813EDCE
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813EDCE
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x18]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x5
	strh r0, [r1, 0x16]
	movs r0, 0xA
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	strh r0, [r1, 0x14]
_0813EDCE:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813EDDC
	b _0813F1A4
_0813EDDC:
	bl IsSEPlaying
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0813EDEA
	b _0813F1A4
_0813EDEA:
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0x14]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x1]
	movs r0, 0
	bl sub_8056B74
	b _0813F1A4
	.pool
_0813EE34:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0813EE5C
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _0813EE5C
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0813EE5C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813EE84
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _0813EE84
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0813EE84:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0813EEF2
	str r2, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gBattleCommunication
	ldrb r2, [r0, 0x1]
	cmp r2, 0
	beq _0813EECC
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x18]
	strh r0, [r1, 0x14]
	b _0813EEF2
	.pool
_0813EECC:
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x16]
	strh r0, [r1, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0813EEF2
	movs r0, 0x1
	negs r0, r0
	str r2, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0813EEF2:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0813EF00
	b _0813F1A4
_0813EF00:
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x18]
	strh r1, [r0, 0x14]
	b _0813F1A4
	.pool
_0813EF30:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813EF3E
	b _0813F1A4
_0813EF3E:
	bl FreeAllWindowBuffers
	ldr r0, =gPlayerParty
	ldr r1, =gTasks
	mov r3, r8
	adds r5, r3, r7
	lsls r5, 3
	adds r5, r1
	ldrb r1, [r5, 0x1C]
	ldr r2, =gPlayerPartyCount
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_813DD7C
	ldr r4, =gMoveToLearn
	ldrh r4, [r4]
	str r4, [sp]
	bl sub_81BFA38
	ldrh r0, [r5, 0x14]
	adds r0, 0x1
	strh r0, [r5, 0x14]
	b _0813F1A4
	.pool
_0813EF88:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813EF96
	b _0813F1A4
_0813EF96:
	ldr r1, [r6, 0x4]
	ldr r0, =sub_813E3A4
	cmp r1, r0
	beq _0813EFA0
	b _0813F1A4
_0813EFA0:
	bl sub_81C1B94
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x4
	bne _0813EFC8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0xA
	b _0813F1A2
	.pool
_0813EFC8:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r9
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl IsHMMove2
	cmp r0, 0
	beq _0813F014
	ldr r0, =gUnknown_085CC270
	ldr r3, =0x000004cc
	adds r0, r3
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0xC
	strh r1, [r0, 0x14]
	b _0813F1A4
	.pool
_0813F014:
	ldr r1, =gBattleTextBuff2
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	strb r4, [r1, 0x2]
	lsrs r0, r4, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	lsls r4, r6, 24
	lsrs r4, 24
	mov r0, r9
	adds r1, r4, 0
	bl RemoveMonPPBonus
	ldr r0, =gMoveToLearn
	ldrh r1, [r0]
	mov r0, r9
	adds r2, r4, 0
	bl SetMonMoveSlot
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813F1A2
	.pool
_0813F05C:
	ldr r0, =gUnknown_085CC270
	movs r1, 0xCF
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813F1A2
	.pool
_0813F090:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F09E
	b _0813F1A4
_0813F09E:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813F0AA
	b _0813F1A4
_0813F0AA:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x1C]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813F1A2
	.pool
_0813F0D8:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813F1A4
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813F1A4
	ldr r0, =gUnknown_085CC270
	movs r1, 0xD0
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0x14
	strh r1, [r0, 0x8]
	b _0813F1A4
	.pool
_0813F120:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x20]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gTasks
	mov r3, r8
	adds r0, r3, r7
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0xB
	strh r1, [r0, 0x16]
	strh r2, [r0, 0x18]
	movs r1, 0x3
	strh r1, [r0, 0x14]
	b _0813F1A4
	.pool
_0813F154:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x24]
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
_0813F16E:
	movs r1, 0xF
	strh r1, [r0, 0x8]
	b _0813F1A4
	.pool
_0813F180:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813F1A4
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813F1A4
	ldr r0, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x5
_0813F1A2:
	strh r0, [r1, 0x14]
_0813F1A4:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end evovle_mon_maybe

	thumb_func_start sub_813F1B8
sub_813F1B8: @ 813F1B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r3
	movs r1, 0x1C
	ldrsh r2, [r0, r1]
	movs r1, 0x64
	muls r2, r1
	ldr r1, =gPlayerParty
	adds r2, r1
	mov r9, r2
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r5, r3, 0
	cmp r0, 0x14
	bls _0813F1EC
	bl _0813FCC4
_0813F1EC:
	lsls r0, 2
	ldr r1, =_0813F204
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813F204:
	.4byte _0813F258
	.4byte _0813F284
	.4byte _0813F2AC
	.4byte _0813F2DC
	.4byte _0813F314
	.4byte _0813F380
	.4byte _0813F3C0
	.4byte _0813F3F0
	.4byte _0813F42C
	.4byte _0813F448
	.4byte _0813F474
	.4byte _0813F498
	.4byte _0813F4E4
	.4byte _0813F570
	.4byte _0813F624
	.4byte _0813F668
	.4byte _0813F6D0
	.4byte _0813F704
	.4byte _0813F748
	.4byte _0813F7A4
	.4byte _0813F7E4
_0813F258:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085CC990
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	b _0813F6B4
	.pool
_0813F284:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F294
	bl _0813FCC4
_0813F294:
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0xA]
	movs r1, 0
	bl PlayCry1
	b _0813F6F2
	.pool
_0813F2AC:
	bl IsCryFinished
	lsls r0, 24
	cmp r0, 0
	bne _0813F2BA
	bl _0813FCC4
_0813F2BA:
	ldr r0, =0x00000179
	bl m4aSongNumStop
	movs r0, 0xBC
	lsls r0, 1
	bl PlaySE
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	b _0813F6B4
	.pool
_0813F2DC:
	bl IsSEPlaying
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0813F2EC
	bl _0813FCC4
_0813F2EC:
	ldr r0, =0x00000179
	bl PlayBGM
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	str r5, [sp]
	movs r0, 0x1C
	movs r1, 0x4
	b _0813F9C8
	.pool
_0813F314:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813F324
	bl _0813FCC4
_0813F324:
	movs r0, 0x1
	bl sub_8140000
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r6, r0, 0
	adds r6, 0x10
	adds r0, r6, 0
	bl sub_817BE94
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x2]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	ldr r1, =0x00000603
	movs r0, 0xE
	bl SetGpuReg
	bl _0813FCC4
	.pool
_0813F380:
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813F396
	bl _0813FCC4
_0813F396:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r5
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	ldr r0, =gUnknown_0203AB80
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x3]
	bl sub_817BFB4
	strb r0, [r4, 0x2]
	bl _0813FCC4
	.pool
_0813F3C0:
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813F3D6
	bl _0813FCC4
_0813F3D6:
	ldr r0, =gUnknown_0203AB80
	ldr r1, [r0]
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl sub_817C3A0
	strb r0, [r4, 0x2]
	b _0813F6AC
	.pool
_0813F3F0:
	ldr r2, =gUnknown_0203AB80
	ldr r1, [r2]
	ldrb r0, [r1, 0x3]
	subs r0, 0x1
	strb r0, [r1, 0x3]
	lsls r0, 24
	cmp r0, 0
	beq _0813F404
	bl _0813FCC4
_0813F404:
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x3]
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0813F420
	bl _0813FCC4
_0813F420:
	b _0813F6AC
	.pool
_0813F42C:
	bl sub_817C068
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x2]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	b _0813F6B4
	.pool
_0813F448:
	ldr r6, =gBattleCommunication
	ldrb r0, [r6, 0x2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0813F45E
	bl _0813FCC4
_0813F45E:
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r5
	ldrh r0, [r4, 0xC]
	bl sub_817C280
	strb r0, [r6, 0x2]
	b _0813F6F2
	.pool
_0813F474:
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0813F48A
	bl _0813FCC4
_0813F48A:
	movs r0, 0x21
	bl PlaySE
	b _0813F6AC
	.pool
_0813F498:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813F4A6
	bl _0813FCC4
_0813F4A6:
	ldr r0, =gUnknown_0203AB84
	ldr r0, [r0]
	bl Free
	ldr r5, =gUnknown_0203AB80
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	ldr r1, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r1
	ldrh r1, [r4, 0xC]
	bl sub_81401E0
	ldr r0, =gPlttBufferUnfaded + 0x40
	ldr r1, [r5]
	adds r1, 0x4
	movs r2, 0x60
	bl memcpy
	b _0813F6F2
	.pool
_0813F4E4:
	bl IsCryFinished
	lsls r0, 24
	cmp r0, 0
	bne _0813F4F2
	bl _0813FCC4
_0813F4F2:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085CC9A6
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =0x00000173
	bl PlayFanfare
	ldr r2, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	adds r2, r1
	adds r2, 0xC
	mov r0, r9
	movs r1, 0xB
	bl SetMonData
	mov r0, r9
	bl CalculateMonStats
	ldrh r1, [r4, 0xA]
	ldrh r2, [r4, 0xC]
	mov r0, r9
	bl sub_806D778
	ldrh r0, [r4, 0xC]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2
	bl pokedex_flag_operation
	ldrh r0, [r4, 0xC]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl pokedex_flag_operation
	movs r0, 0xE
	bl IncrementGameStat
	b _0813FCC4
	.pool
_0813F570:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F57E
	b _0813FCC4
_0813F57E:
	bl IsFanfareTaskInactive
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813F58C
	b _0813FCC4
_0813F58C:
	ldr r1, =gTasks
	lsls r4, r7, 2
	adds r0, r4, r7
	lsls r0, 3
	adds r5, r0, r1
	ldrb r1, [r5, 0x10]
	mov r0, r9
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r6, r0, 16
	mov r8, r4
	cmp r6, 0
	beq _0813F5FC
	movs r0, 0x1A
	ldrsh r2, [r5, r0]
	cmp r2, 0
	bne _0813F5FC
	ldrh r1, [r5, 0xE]
	movs r0, 0x80
	orrs r0, r1
	strh r0, [r5, 0xE]
	strh r2, [r5, 0x10]
	strh r2, [r5, 0x14]
	mov r0, r9
	movs r1, 0x2
	add r2, sp, 0x4
	bl GetMonData
	ldr r0, =gBattleTextBuff1
	add r1, sp, 0x4
	bl StringCopy10
	ldr r0, =0x0000ffff
	cmp r6, r0
	bne _0813F5E8
	movs r0, 0x14
	strh r0, [r5, 0x8]
	b _0813FCC4
	.pool
_0813F5E8:
	ldr r0, =0x0000fffe
	cmp r6, r0
	bne _0813F5F0
	b _0813FCC4
_0813F5F0:
	movs r0, 0x12
	strh r0, [r5, 0x8]
	b _0813FCC4
	.pool
_0813F5FC:
	ldr r0, =0x00000179
	bl PlayBGM
	ldr r1, =gUnknown_085EF6D2
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	b _0813F78C
	.pool
_0813F624:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _0813F634
	b _0813FCC4
_0813F634:
	adds r0, r7, 0
	bl DestroyTask
	ldr r4, =gUnknown_0203AB80
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_030061E8
	ldr r0, [r0]
	bl SetMainCallback2
	b _0813FCC4
	.pool
_0813F668:
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0813F67C
	b _0813FCC4
_0813F67C:
	bl m4aMPlayAllStop
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	ldr r1, =0x0004001c
	orrs r0, r1
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_0813F6AC:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r5
_0813F6B4:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0813FCC4
	.pool
_0813F6D0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813F6DE
	b _0813FCC4
_0813F6DE:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r5
	ldrh r1, [r4, 0xA]
	bl sub_81401E0
_0813F6F2:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0813FCC4
	.pool
_0813F704:
	ldr r0, =gUnknown_0203AB80
	ldr r0, [r0]
	ldrb r0, [r0]
	bl sub_8140208
	cmp r0, 0
	bne _0813F714
	b _0813FCC4
_0813F714:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085CC9EE
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x1A]
	b _0813FC8C
	.pool
_0813F748:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F756
	b _0813FCC4
_0813F756:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813F762
	b _0813FCC4
_0813F762:
	bl sub_804F574
	ldr r0, =0x0000016f
	bl PlayFanfare
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0xC]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x40
	strh r0, [r1, 0x10]
_0813F78C:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0813FCC4
	.pool
_0813F7A4:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F7B2
	b _0813FCC4
_0813F7B2:
	bl IsFanfareTaskInactive
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813F7C0
	b _0813FCC4
_0813F7C0:
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x10]
	subs r0, 0x1
	strh r0, [r1, 0x10]
	lsls r0, 16
	cmp r0, 0
	beq _0813F7D8
	b _0813FCC4
_0813F7D8:
	movs r0, 0xD
	strh r0, [r1, 0x8]
	b _0813FCC4
	.pool
_0813F7E4:
	lsls r1, r7, 2
	adds r0, r1, r7
	lsls r0, 3
	adds r0, r5
	movs r2, 0x14
	ldrsh r0, [r0, r2]
	mov r8, r1
	cmp r0, 0xB
	bls _0813F7F8
	b _0813FCC4
_0813F7F8:
	lsls r0, 2
	ldr r1, =_0813F808
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813F808:
	.4byte _0813F838
	.4byte _0813F884
	.4byte _0813F8CC
	.4byte _0813F90C
	.4byte _0813F96C
	.4byte _0813FA24
	.4byte _0813FAA8
	.4byte _0813FBA4
	.4byte _0813FBEC
	.4byte _0813FC38
	.4byte _0813FC70
	.4byte _0813FCA0
_0813F838:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F846
	b _0813FCC4
_0813F846:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813F852
	b _0813FCC4
_0813F852:
	bl sub_804F574
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x10]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813FCC2
	.pool
_0813F884:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F892
	b _0813FCC4
_0813F892:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813F89E
	b _0813FCC4
_0813F89E:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x14]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813FCC2
	.pool
_0813F8CC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813F90C
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813F90C
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x18]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x5
	strh r0, [r1, 0x16]
	movs r0, 0x9
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	strh r0, [r1, 0x14]
_0813F90C:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813F91A
	b _0813FCC4
_0813F91A:
	bl IsSEPlaying
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0813F928
	b _0813FCC4
_0813F928:
	movs r0, 0
	movs r1, 0xA8
	movs r2, 0xE0
	bl sub_809882C
	ldr r0, =gUnknown_0833900C
	movs r1, 0xA8
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	ldr r3, =gBattleCommunication
	strb r4, [r3, 0x1]
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0x14]
	strb r2, [r3, 0x1]
	b _0813FCC4
	.pool
_0813F96C:
	bl sub_8198C58
	lsls r0, 24
	asrs r6, r0, 24
	cmp r6, 0
	beq _0813F98C
	cmp r6, 0
	bgt _0813F986
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _0813F9E4
	b _0813FCC4
_0813F986:
	cmp r6, 0x1
	beq _0813F9E4
	b _0813FCC4
_0813F98C:
	ldr r0, =gBattleCommunication
	strb r6, [r0, 0x1]
	ldr r0, =gUnknown_085CC270
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x16]
	strh r1, [r0, 0x14]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x5
	beq _0813F9C0
	b _0813FCC4
_0813F9C0:
	movs r0, 0x1
	negs r0, r0
	str r6, [sp]
	movs r1, 0
_0813F9C8:
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0813FCC4
	.pool
_0813F9E4:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x1]
	ldr r0, =gUnknown_085CC270
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x18]
	strh r1, [r0, 0x14]
	b _0813FCC4
	.pool
_0813FA24:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813FA32
	b _0813FCC4
_0813FA32:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _0813FA3E
	bl sub_800E084
_0813FA3E:
	movs r0, 0x3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeAllWindowBuffers
	ldr r0, =gPlayerParty
	ldr r1, =gTasks
	mov r2, r8
	adds r5, r2, r7
	lsls r5, 3
	adds r5, r1
	ldrb r1, [r5, 0x1C]
	ldr r2, =gPlayerPartyCount
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_813DF70
	ldr r4, =gMoveToLearn
	ldrh r4, [r4]
	str r4, [sp]
	bl sub_81BFA38
	ldrh r0, [r5, 0x14]
	adds r0, 0x1
	strh r0, [r5, 0x14]
	b _0813FCC4
	.pool
_0813FAA8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0813FAB6
	b _0813FCC4
_0813FAB6:
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_813E3C0
	cmp r1, r0
	beq _0813FAC2
	b _0813FCC4
_0813FAC2:
	bl sub_81C1B94
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x4
	bne _0813FAEC
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x9
	b _0813FCC2
	.pool
_0813FAEC:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r9
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl IsHMMove2
	cmp r0, 0
	beq _0813FB3C
	ldr r0, =gUnknown_085CC270
	ldr r1, =0x000004cc
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0xB
	strh r1, [r0, 0x14]
	b _0813FCC4
	.pool
_0813FB3C:
	ldr r1, =gBattleTextBuff2
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	strb r4, [r1, 0x2]
	lsrs r0, r4, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	lsls r4, r6, 24
	lsrs r4, 24
	mov r0, r9
	adds r1, r4, 0
	bl RemoveMonPPBonus
	ldr r0, =gMoveToLearn
	ldrh r1, [r0]
	mov r0, r9
	adds r2, r4, 0
	bl SetMonMoveSlot
	ldr r0, =gUnknown_085CC270
	movs r1, 0xCF
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813FCC2
	.pool
_0813FBA4:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _0813FBB2
	b _0813FCC4
_0813FBB2:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0813FBBE
	b _0813FCC4
_0813FBBE:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x1C]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	b _0813FCC2
	.pool
_0813FBEC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813FCC4
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813FCC4
	ldr r0, =gUnknown_085CC270
	movs r1, 0xD0
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0x12
	strh r1, [r0, 0x8]
	b _0813FCC4
	.pool
_0813FC38:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x20]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0xA
	strh r1, [r0, 0x16]
	strh r2, [r0, 0x18]
	movs r1, 0x3
	strh r1, [r0, 0x14]
	b _0813FCC4
	.pool
_0813FC70:
	ldr r0, =gUnknown_085CC270
	ldr r0, [r0, 0x24]
	bl get_battle_strings_
	ldr r1, =gUnknown_02022E2C
	movs r0, 0
	movs r2, 0x1
	bl sub_807F1A8
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
_0813FC8C:
	movs r1, 0xD
	strh r1, [r0, 0x8]
	b _0813FCC4
	.pool
_0813FCA0:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813FCC4
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0813FCC4
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0x5
_0813FCC2:
	strh r0, [r1, 0x14]
_0813FCC4:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813F1B8

	thumb_func_start nullsub_83
nullsub_83: @ 813FCD8
	bx lr
	thumb_func_end nullsub_83

	thumb_func_start sub_813FCDC
sub_813FCDC: @ 813FCDC
	push {lr}
	ldr r0, =gUnknown_02022E14
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, =gUnknown_02022E16
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =gUnknown_02022E18
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1A
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1C
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1E
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, =gUnknown_02022E20
	ldrh r1, [r0]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, =gUnknown_02022E22
	ldrh r1, [r0]
	movs r0, 0x1E
	bl SetGpuReg
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl sub_80BA0A8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813FCDC

	thumb_func_start sub_813FD64
sub_813FD64: @ 813FD64
	push {lr}
	ldr r0, =gUnknown_02022E14
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, =gUnknown_02022E16
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =gUnknown_02022E18
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1A
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1C
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1E
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, =gUnknown_02022E20
	ldrh r1, [r0]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, =gUnknown_02022E22
	ldrh r1, [r0]
	movs r0, 0x1E
	bl SetGpuReg
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl sub_80BA0A8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813FD64

	thumb_func_start sub_813FDEC
sub_813FDEC: @ 813FDEC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0xC
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _0813FE9A
	ldrh r0, [r4, 0xA]
	adds r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0813FE9A
	ldrh r1, [r4]
	adds r0, r1, 0x1
	strh r0, [r4]
	lsls r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_085B58C9
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	lsls r2, r0, 2
	adds r0, r3, 0x3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r1, r0
	ble _0813FE8C
	adds r0, r3, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _0813FE74
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
	movs r0, 0x6
	ldrsh r2, [r4, r0]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r1, r3, 0x2
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0813FE5E
	strh r5, [r4, 0x6]
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
_0813FE5E:
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0]
	b _0813FE8A
	.pool
_0813FE74:
	ldr r0, =gUnknown_0203AB84
	lsls r1, 5
	ldr r0, [r0]
	adds r0, r1
	movs r1, 0xA0
	movs r2, 0x20
	bl LoadPalette
	strh r5, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
_0813FE8A:
	strh r0, [r4, 0x2]
_0813FE8C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bne _0813FE9A
	adds r0, r6, 0
	bl DestroyTask
_0813FE9A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813FDEC

	thumb_func_start sub_813FEA4
sub_813FEA4: @ 813FEA4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =sub_813FEE8
	movs r1, 0x7
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0
	bne _0813FED0
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0xC]
	b _0813FEDE
	.pool
_0813FED0:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0xC]
_0813FEDE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813FEA4

	thumb_func_start sub_813FEE8
sub_813FEE8: @ 813FEE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02022E18
	mov r8, r0
	ldr r1, =gUnknown_02022E1A
	mov r9, r1
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0xC
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0813FF28
	ldr r7, =gUnknown_02022E1C
	ldr r6, =gUnknown_02022E1E
	b _0813FF2C
	.pool
_0813FF28:
	ldr r7, =gUnknown_02022E20
	ldr r6, =gUnknown_02022E22
_0813FF2C:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x8]
	adds r0, 0x80
	ands r0, r1
	strh r0, [r4, 0xA]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Cos
	adds r0, 0x8
	mov r2, r8
	strh r0, [r2]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Sin
	adds r0, 0x10
	mov r2, r9
	strh r0, [r2]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Cos
	adds r0, 0x8
	strh r0, [r7]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	movs r1, 0x4
	bl Sin
	adds r0, 0x10
	strh r0, [r6]
	ldr r0, =sub_813FDEC
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0813FFA6
	adds r0, r5, 0
	bl DestroyTask
	mov r0, r8
	strh r4, [r0]
	mov r1, r9
	strh r4, [r1]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r7]
	strh r4, [r6]
_0813FFA6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813FEE8

	thumb_func_start sub_813FFC0
sub_813FFC0: @ 813FFC0
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r1, 0
	ldr r5, =gUnknown_085B5884
	ldr r7, =gUnknown_085B58D9
_0813FFCA:
	lsls r0, r1, 4
	adds r4, r1, 0x1
	adds r2, r0, r7
	lsls r0, r1, 5
	adds r1, r0, r6
	movs r3, 0xF
_0813FFD6:
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	strh r0, [r1]
	adds r2, 0x1
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0813FFD6
	adds r1, r4, 0
	cmp r1, 0x31
	ble _0813FFCA
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813FFC0

	thumb_func_start sub_8140000
sub_8140000: @ 8140000
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203AB84
	movs r0, 0xC8
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4]
	bl sub_813FFC0
	cmp r5, 0
	bne _08140028
	movs r6, 0x1
	movs r4, 0x2
	b _0814002C
	.pool
_08140028:
	movs r6, 0x1
	movs r4, 0x3
_0814002C:
	ldr r0, =gUnknown_085B51E4
	movs r1, 0xA0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_085B4134
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_085B482C
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gUnknown_085B4D10
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	adds r0, r4, 0
	bl CopyBgTilemapBufferToVram
	cmp r5, 0
	bne _081400C4
	ldr r1, =0x00000442
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000808
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xBA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	adds r0, r6, 0
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	b _081400DE
	.pool
_081400C4:
	ldr r1, =0x00000842
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000808
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xDA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
_081400DE:
	ldr r0, =sub_813FDEC
	movs r1, 0x5
	bl CreateTask
	adds r0, r5, 0
	bl sub_813FEA4
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140000

	thumb_func_start sub_8140100
sub_8140100: @ 8140100
	push {lr}
	ldr r0, =sub_813FDEC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _0814011E
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x14]
_0814011E:
	movs r0, 0
	movs r1, 0xA0
	movs r2, 0x20
	bl FillPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140100

	thumb_func_start sub_8140134
sub_8140134: @ 8140134
	push {lr}
	ldr r0, =sub_813FDEC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08140148
	bl DestroyTask
_08140148:
	ldr r0, =sub_813FEE8
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0814015A
	bl DestroyTask
_0814015A:
	movs r0, 0
	movs r1, 0xA0
	movs r2, 0x20
	bl FillPalette
	bl sub_8140174
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140134

	thumb_func_start sub_8140174
sub_8140174: @ 8140174
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r1, [r0]
	movs r0, 0x1
	movs r1, 0x5
	bl sub_80391E0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	movs r1, 0x7
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x5
	bl sub_80391E0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x2
	movs r1, 0x7
	bl SetBgAttribute
	movs r1, 0xCA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gUnknown_0203AB84
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140174

	thumb_func_start sub_81401E0
sub_81401E0: @ 81401E0
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	movs r2, 0
	movs r3, 0
	bl sub_806ED40
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81401E0

	thumb_func_start sub_8140208
sub_8140208: @ 8140208
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r2, 0x1C
	adds r1, r2
	ldr r1, [r1]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _08140230
	movs r0, 0
	b _08140232
	.pool
_08140230:
	movs r0, 0x1
_08140232:
	pop {r1}
	bx r1
	thumb_func_end sub_8140208

	.align 2, 0 @ Don't pad with nop.
