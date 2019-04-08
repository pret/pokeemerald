	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(3)

	thumb_func_start sub_81CC4D4
sub_81CC4D4: @ 81CC4D4
	push {r4,lr}
	movs r0, 0x3
	movs r1, 0x14
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CC4F0
	ldr r1, =0x00000884
	movs r0, 0x10
	bl AllocSubstruct
	cmp r0, 0
	bne _081CC4F8
_081CC4F0:
	movs r0, 0
	b _081CC51A
	.pool
_081CC4F8:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	bl sub_8124668
	str r0, [r4, 0xC]
	cmp r0, 0
	bne _081CC514
	ldr r0, =sub_81CC568
	b _081CC516
	.pool
_081CC514:
	ldr r0, =sub_81CC5B4
_081CC516:
	str r0, [r4, 0x10]
	movs r0, 0x1
_081CC51A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC4D4

	thumb_func_start sub_81CC524
sub_81CC524: @ 81CC524
	push {lr}
	bl sub_8124658
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3, 0x15]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x15]
	movs r0, 0x10
	bl FreePokenavSubstruct
	movs r0, 0x3
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC524

	thumb_func_start sub_81CC554
sub_81CC554: @ 81CC554
	push {lr}
	movs r0, 0x3
	bl GetSubstructPtr
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CC554

	thumb_func_start sub_81CC568
sub_81CC568: @ 81CC568
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _081CC58C
	cmp r0, 0x4
	bgt _081CC582
	cmp r0, 0x3
	beq _081CC588
	b _081CC5AC
_081CC582:
	cmp r0, 0x5
	beq _081CC59E
	b _081CC5AC
_081CC588:
	movs r0, 0x1
	b _081CC5AE
_081CC58C:
	bl sub_8124658
	lsls r0, 24
	cmp r0, 0
	bne _081CC59A
	movs r0, 0x3
	b _081CC5AE
_081CC59A:
	movs r0, 0x2
	b _081CC5AE
_081CC59E:
	ldr r0, =sub_81CC5DC
	str r0, [r4, 0x10]
	movs r0, 0x4
	b _081CC5AE
	.pool
_081CC5AC:
	movs r0, 0
_081CC5AE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC568

	thumb_func_start sub_81CC5B4
sub_81CC5B4: @ 81CC5B4
	push {lr}
	adds r2, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CC5CC
	movs r0, 0
	b _081CC5D2
	.pool
_081CC5CC:
	ldr r0, =sub_81CC5DC
	str r0, [r2, 0x10]
	movs r0, 0x4
_081CC5D2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC5B4

	thumb_func_start sub_81CC5DC
sub_81CC5DC: @ 81CC5DC
	ldr r0, =0x000186a1
	bx lr
	.pool
	thumb_func_end sub_81CC5DC

	thumb_func_start sub_81CC5E4
sub_81CC5E4: @ 81CC5E4
	push {lr}
	movs r0, 0x3
	bl GetSubstructPtr
	ldr r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81CC5E4

	thumb_func_start sub_81CC5F4
sub_81CC5F4: @ 81CC5F4
	push {r4,lr}
	ldr r1, =0x00001948
	movs r0, 0x4
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CC624
	ldr r0, =sub_81CC6F4
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81CC6BC
	str r0, [r4]
	movs r0, 0x1
	b _081CC626
	.pool
_081CC624:
	movs r0, 0
_081CC626:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC5F4

	thumb_func_start sub_81CC62C
sub_81CC62C: @ 81CC62C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, =gUnknown_086230E4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r5, 0x4]
	ldr r0, =sub_81CC6BC
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC62C

	thumb_func_start sub_81CC65C
sub_81CC65C: @ 81CC65C
	push {lr}
	movs r0, 0x4
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CC65C

	thumb_func_start sub_81CC670
sub_81CC670: @ 81CC670
	push {r4,lr}
	movs r0, 0x4
	bl GetSubstructPtr
	adds r4, r0, 0
	bl FreeRegionMapIconResources
	bl sub_81CC9EC
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x10
	bl FreePokenavSubstruct
	movs r0, 0x4
	bl FreePokenavSubstruct
	bl SetPokenavVBlankCallback
	movs r0, 0
	bl SetBgMode
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC670

	thumb_func_start sub_81CC6A4
sub_81CC6A4: @ 81CC6A4
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl UpdateRegionMapVideoRegs
	pop {r0}
	bx r0
	thumb_func_end sub_81CC6A4

	thumb_func_start sub_81CC6BC
sub_81CC6BC: @ 81CC6BC
	push {lr}
	movs r0, 0x4
	bl GetSubstructPtr
	ldr r0, [r0, 0x4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6BC

	thumb_func_start sub_81CC6D0
sub_81CC6D0: @ 81CC6D0
	push {lr}
	bl sub_81CC5E4
	cmp r0, 0
	bne _081CC6EC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsrs r0, 3
	movs r1, 0x1
	ands r0, r1
	b _081CC6EE
	.pool
_081CC6EC:
	movs r0, 0
_081CC6EE:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6D0

	thumb_func_start sub_81CC6F4
sub_81CC6F4: @ 81CC6F4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x7
	bls _081CC706
	b _081CC83E
_081CC706:
	lsls r0, r4, 2
	ldr r1, =_081CC714
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CC714:
	.4byte _081CC734
	.4byte _081CC784
	.4byte _081CC7B6
	.4byte _081CC7BE
	.4byte _081CC7CE
	.4byte _081CC7E2
	.4byte _081CC804
	.4byte _081CC82A
_081CC734:
	movs r0, 0
	bl SetVBlankCallback_
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	bl SetBgMode
	ldr r4, =gUnknown_086230D8
	adds r0, r4, 0
	movs r1, 0x2
	bl InitBgTemplates
	movs r0, 0x10
	bl GetSubstructPtr
	adds r5, r0, 0
	adds r4, 0x4
	bl sub_81CC6D0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8122CF8
	bl sub_81CC9C0
_081CC77C:
	movs r0, 0
	b _081CC840
	.pool
_081CC784:
	bl sub_8122DB0
	lsls r0, 24
	cmp r0, 0
	bne _081CC83A
	bl sub_81CC5E4
	cmp r0, 0
	bne _081CC7AC
	movs r0, 0x4
	movs r1, 0x9
	bl CreateRegionMapPlayerIcon
	movs r0, 0x5
	movs r1, 0xA
	bl CreateRegionMapCursor
	bl sub_812454C
	b _081CC77C
_081CC7AC:
	movs r0, 0
	movs r1, 0x6
	bl sub_8123030
	b _081CC77C
_081CC7B6:
	bl sub_81CCD10
_081CC7BA:
	movs r0, 0x1
	b _081CC840
_081CC7BE:
	bl sub_81CCD24
	cmp r0, 0
	bne _081CC83A
	adds r0, r5, 0
	bl sub_81CCA1C
	b _081CC7BA
_081CC7CE:
	bl sub_81CCAFC
	cmp r0, 0
	bne _081CC83A
	adds r0, r5, 0
	bl sub_81CCB0C
	bl sub_81C7B40
	b _081CC77C
_081CC7E2:
	adds r0, r5, 0
	bl sub_81CCC4C
	cmp r0, 0
	bne _081CC83A
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =sub_81CC6A4
	bl SetVBlankCallback_
	b _081CC77C
	.pool
_081CC804:
	bl sub_81CC6D0
	lsls r0, 24
	movs r4, 0x5
	cmp r0, 0
	bne _081CC812
	movs r4, 0x4
_081CC812:
	adds r0, r4, 0
	bl LoadLeftHeaderGfxForIndex
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_81C7FA0
	movs r0, 0x1
	bl sub_81C7AC0
	b _081CC77C
_081CC82A:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CC83A
	bl sub_81C8010
	cmp r0, 0
	beq _081CC7BA
_081CC83A:
	movs r0, 0x2
	b _081CC840
_081CC83E:
	movs r0, 0x4
_081CC840:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6F4

	thumb_func_start sub_81CC848
sub_81CC848: @ 81CC848
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetSubstructPtr
	cmp r4, 0
	beq _081CC85C
	cmp r4, 0x1
	beq _081CC864
	b _081CC870
_081CC85C:
	bl sub_81CCB0C
	movs r0, 0
	b _081CC872
_081CC864:
	bl sub_81CCC4C
	cmp r0, 0
	beq _081CC870
	movs r0, 0x2
	b _081CC872
_081CC870:
	movs r0, 0x4
_081CC872:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC848

	thumb_func_start sub_81CC878
sub_81CC878: @ 81CC878
	push {lr}
	cmp r0, 0x1
	beq _081CC8A2
	cmp r0, 0x1
	bgt _081CC888
	cmp r0, 0
	beq _081CC88E
	b _081CC8D0
_081CC888:
	cmp r0, 0x2
	beq _081CC8BE
	b _081CC8D0
_081CC88E:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81CCC5C
	bl sub_8123418
	movs r0, 0
	b _081CC8D2
_081CC8A2:
	bl sub_8123514
	lsls r0, 24
	cmp r0, 0
	bne _081CC8C6
	bl sub_81CCC88
	cmp r0, 0
	bne _081CC8C6
	movs r0, 0x1
	bl sub_81C7BA4
	movs r0, 0
	b _081CC8D2
_081CC8BE:
	bl IsDma3ManagerBusyWithBgCopy_
	cmp r0, 0
	beq _081CC8CA
_081CC8C6:
	movs r0, 0x2
	b _081CC8D2
_081CC8CA:
	movs r0, 0x4
	bl sub_81C7E14
_081CC8D0:
	movs r0, 0x4
_081CC8D2:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC878

	thumb_func_start sub_81CC8D8
sub_81CC8D8: @ 81CC8D8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CC90C
	cmp r4, 0x1
	bgt _081CC8F2
	cmp r4, 0
	beq _081CC8FC
	b _081CC952
_081CC8F2:
	cmp r4, 0x2
	beq _081CC924
	cmp r4, 0x3
	beq _081CC940
	b _081CC952
_081CC8FC:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81CCB0C
	movs r0, 0
	b _081CC954
_081CC90C:
	adds r0, r5, 0
	bl sub_81CCC4C
	cmp r0, 0
	bne _081CC948
	movs r0, 0x1
	bl sub_81CCC5C
	bl sub_8123418
	movs r0, 0
	b _081CC954
_081CC924:
	bl sub_8123514
	lsls r0, 24
	cmp r0, 0
	bne _081CC948
	bl sub_81CCC88
	cmp r0, 0
	bne _081CC948
	movs r0, 0x2
	bl sub_81C7BA4
	movs r0, 0
	b _081CC954
_081CC940:
	bl IsDma3ManagerBusyWithBgCopy_
	cmp r0, 0
	beq _081CC94C
_081CC948:
	movs r0, 0x2
	b _081CC954
_081CC94C:
	movs r0, 0x5
	bl sub_81C7E14
_081CC952:
	movs r0, 0x4
_081CC954:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC8D8

	thumb_func_start sub_81CC95C
sub_81CC95C: @ 81CC95C
	push {lr}
	cmp r0, 0x1
	beq _081CC982
	cmp r0, 0x1
	bgt _081CC96C
	cmp r0, 0
	beq _081CC972
	b _081CC9B8
_081CC96C:
	cmp r0, 0x2
	beq _081CC996
	b _081CC9B8
_081CC972:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081CC9BA
_081CC982:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CC99E
	bl sub_81C7FDC
	bl sub_81C78A0
	movs r0, 0
	b _081CC9BA
_081CC996:
	bl MainMenuLoopedTaskIsBusy
	cmp r0, 0
	beq _081CC9A2
_081CC99E:
	movs r0, 0x2
	b _081CC9BA
_081CC9A2:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0
	b _081CC9BA
_081CC9B8:
	movs r0, 0x4
_081CC9BA:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC95C

	thumb_func_start sub_81CC9C0
sub_81CC9C0: @ 81CC9C0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_086230F8
_081CC9C6:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081CC9C6
	ldr r0, =gUnknown_08623100
	bl Pokenav_AllocAndLoadPalettes
	bl sub_81CCE58
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC9C0

	thumb_func_start sub_81CC9EC
sub_81CC9EC: @ 81CC9EC
	push {r4,r5,lr}
	movs r0, 0x4
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r0, 0x6
	bl FreeSpriteTilesByTag
	movs r0, 0xB
	bl FreeSpritePaletteByTag
	adds r5, r4, 0
	adds r5, 0xC
	movs r4, 0x2
_081CCA08:
	ldm r5!, {r0}
	bl DestroySprite
	subs r4, 0x1
	cmp r4, 0
	bge _081CCA08
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC9EC

	thumb_func_start sub_81CCA1C
sub_81CCA1C: @ 81CCA1C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x40
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0x1
	movs r1, 0x11
	movs r2, 0x41
	movs r3, 0x1
	bl sub_8199DF0
	add r1, sp, 0x4
	movs r2, 0x82
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	adds r4, r5, 0
	adds r4, 0x18
	ldr r2, =0x01000400
	adds r0, r1, 0
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0x1
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_08623110
	bl AddWindow
	movs r4, 0
	strh r0, [r5, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x42
	movs r2, 0x40
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r5, 0x8]
	movs r1, 0x42
	movs r2, 0x4
	bl DrawTextBorderOuter
	ldr r1, =gUnknown_08622888
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldrb r0, [r5, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r5, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_08622868
	movs r1, 0x10
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, =gHoennMapZoomIcons_Pal
	movs r1, 0x30
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	bl sub_8124658
	lsls r0, 24
	cmp r0, 0
	bne _081CCAE0
	ldr r1, =0xffffa000
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgY
	b _081CCAEA
	.pool
_081CCAE0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
_081CCAEA:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCA1C

	thumb_func_start sub_81CCAFC
sub_81CCAFC: @ 81CCAFC
	push {lr}
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CCAFC

	thumb_func_start sub_81CCB0C
sub_81CCB0C: @ 81CCB0C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0x10
	bl GetSubstructPtr
	adds r5, r0, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x4
	bls _081CCB22
	b _081CCC40
_081CCB22:
	lsls r0, 2
	ldr r1, =_081CCB30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CCB30:
	.4byte _081CCC1C
	.4byte _081CCBDC
	.4byte _081CCB44
	.4byte _081CCB8E
	.4byte _081CCBDC
_081CCB44:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl PutWindowRectTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrh r1, [r5]
	ldrb r2, [r5, 0x3]
	adds r0, r4, 0
	bl sub_81CCD70
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl sub_81CCFA4
	b _081CCC40
_081CCB8E:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl PutWindowRectTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x6
	bl FillBgTilemapBufferRect
	b _081CCC0C
	.pool
_081CCBDC:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrh r1, [r5]
	ldrb r2, [r5, 0x3]
	adds r0, r4, 0
	bl sub_81CCDE8
_081CCC0C:
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl sub_81CCFA4
	b _081CCC40
_081CCC1C:
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xD
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x4
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl sub_81CCFA4
_081CCC40:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCB0C

	thumb_func_start sub_81CCC4C
sub_81CCC4C: @ 81CCC4C
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CCC4C

	thumb_func_start sub_81CCC5C
sub_81CCC5C: @ 81CCC5C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sub_81CCC9C
	movs r1, 0x3
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
	thumb_func_end sub_81CCC5C

	thumb_func_start sub_81CCC88
sub_81CCC88: @ 81CCC88
	push {lr}
	ldr r0, =sub_81CCC9C
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCC88

	thumb_func_start sub_81CCC9C
sub_81CCC9C: @ 81CCC9C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081CCCE0
	movs r1, 0x90
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x1
	bl ChangeBgY
	cmp r0, 0
	blt _081CCCD6
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	adds r0, r4, 0
	bl DestroyTask
_081CCCD6:
	bl sub_81CCF78
	b _081CCD04
	.pool
_081CCCE0:
	movs r1, 0x90
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgY
	ldr r1, =0xffffa000
	cmp r0, r1
	bgt _081CCD00
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgY
	adds r0, r5, 0
	bl DestroyTask
_081CCD00:
	bl sub_81CCF78
_081CCD04:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCC9C

	thumb_func_start sub_81CCD10
sub_81CCD10: @ 81CCD10
	push {lr}
	ldr r0, =sub_81CCD34
	movs r1, 0x1
	bl CreateLoopedTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCD10

	thumb_func_start sub_81CCD24
sub_81CCD24: @ 81CCD24
	push {lr}
	ldr r0, =sub_81CCD34
	bl FuncIsActiveLoopedTask
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCD24

	thumb_func_start sub_81CCD34
sub_81CCD34: @ 81CCD34
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetSubstructPtr
	adds r2, r0, 0
	cmp r4, 0x15
	ble _081CCD48
	movs r0, 0x4
	b _081CCD62
_081CCD48:
	ldr r0, =gUnknown_08623118
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	movs r1, 0xC8
	muls r1, r4
	ldr r3, =0x00000818
	adds r1, r3
	adds r1, r2, r1
	bl LZ77UnCompWram
	movs r0, 0x1
_081CCD62:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCD34

	thumb_func_start sub_81CCD70
sub_81CCD70: @ 81CCD70
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r3, r1, 0
	movs r4, 0
	ldr r0, =gUnknown_08623118
	ldrh r1, [r0]
	adds r5, r0, 0
	cmp r1, r3
	bne _081CCD8A
	ldrh r0, [r5, 0x2]
	cmp r0, r2
	beq _081CCDA0
_081CCD8A:
	adds r4, 0x1
	cmp r4, 0x15
	bgt _081CCDA0
	lsls r0, r4, 3
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, r3
	bne _081CCD8A
	ldrh r0, [r1, 0x2]
	cmp r0, r2
	bne _081CCD8A
_081CCDA0:
	cmp r4, 0x16
	beq _081CCDD4
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x6
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0xC8
	adds r1, r4, 0
	muls r1, r0
	ldr r0, =0x00000818
	adds r1, r0
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x12
	movs r3, 0x6
	bl CopyToBgTilemapBufferRect
_081CCDD4:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCD70

	thumb_func_start sub_81CCDE8
sub_81CCDE8: @ 81CCDE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	mov r9, r0
	movs r5, 0
	ldr r6, =gStringVar1
	movs r4, 0x88
	lsls r4, 21
	lsls r1, 24
	mov r8, r1
	lsls r7, r2, 24
	b _081CCE34
	.pool
_081CCE08:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	mov r1, r9
	ldrb r0, [r1, 0x8]
	lsrs r1, r4, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r6, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x80
	lsls r0, 21
	adds r4, r0
	adds r5, 0x1
_081CCE34:
	lsls r2, r5, 24
	lsrs r2, 24
	mov r1, r8
	lsrs r0, r1, 24
	lsrs r1, r7, 24
	bl GetLandmarkName
	adds r1, r0, 0
	cmp r1, 0
	bne _081CCE08
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCDE8

	thumb_func_start sub_81CCE58
sub_81CCE58: @ 81CCE58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x4
	bl GetSubstructPtr
	adds r4, r0, 0
	bl sub_8124658
	lsls r0, 24
	movs r2, 0x84
	cmp r0, 0
	bne _081CCE74
	movs r2, 0xE4
_081CCE74:
	movs r5, 0
	lsls r7, r2, 16
	adds r4, 0xC
	mov r8, r4
	movs r6, 0x98
	lsls r6, 16
_081CCE80:
	asrs r1, r6, 16
	ldr r0, =gUnknown_086231D0
	asrs r2, r7, 16
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	movs r0, 0
	strh r0, [r2, 0x2E]
	lsls r4, r5, 2
	strh r4, [r2, 0x30]
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r0, r1, 22
	adds r1, r0, 0
	strh r0, [r2, 0x32]
	movs r0, 0x96
	strh r0, [r2, 0x34]
	strh r4, [r2, 0x36]
	adds r1, r4
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r3, r0
	orrs r3, r1
	strh r3, [r2, 0x4]
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r2}
	movs r4, 0x80
	lsls r4, 14
	adds r6, r4
	adds r5, 0x1
	cmp r5, 0x2
	ble _081CCE80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCE58

	thumb_func_start sub_81CCEF4
sub_81CCEF4: @ 81CCEF4
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x34]
	movs r1, 0x34
	ldrsh r4, [r3, r1]
	cmp r4, 0
	beq _081CCF06
	subs r0, 0x1
	b _081CCF6E
_081CCF06:
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _081CCF16
	strh r4, [r3, 0x2E]
_081CCF16:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081CCF26
	strh r4, [r3, 0x30]
_081CCF26:
	ldrh r5, [r3, 0x30]
	ldrh r2, [r3, 0x32]
	adds r1, r5, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x38]
	movs r2, 0x38
	ldrsh r0, [r3, r2]
	cmp r0, 0x3
	bgt _081CCF5C
	movs r2, 0x2E
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _081CCF70
	adds r0, r1, 0x1
	strh r0, [r3, 0x38]
	b _081CCF6C
	.pool
_081CCF5C:
	lsls r0, r5, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bne _081CCF70
	strh r4, [r3, 0x38]
	strh r4, [r3, 0x2E]
_081CCF6C:
	movs r0, 0x78
_081CCF6E:
	strh r0, [r3, 0x34]
_081CCF70:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCEF4

	thumb_func_start sub_81CCF78
sub_81CCF78: @ 81CCF78
	push {r4,lr}
	movs r0, 0x4
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r0, 0x1
	bl GetBgY
	asrs r0, 8
	movs r1, 0x84
	subs r1, r0
	adds r4, 0xC
	movs r2, 0x2
_081CCF92:
	ldm r4!, {r0}
	strh r1, [r0, 0x22]
	subs r2, 0x1
	cmp r2, 0
	bge _081CCF92
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCF78

	thumb_func_start sub_81CCFA4
sub_81CCFA4: @ 81CCFA4
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetSubstructPtr
	movs r1, 0x1
	ands r4, r1
	lsls r5, r4, 2
	movs r6, 0x5
	negs r6, r6
	adds r4, r0, 0
	adds r4, 0xC
	movs r3, 0x2
_081CCFBE:
	ldm r4!, {r0}
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r6, 0
	ands r1, r2
	orrs r1, r5
	strb r1, [r0]
	subs r3, 0x1
	cmp r3, 0
	bge _081CCFBE
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCFA4

	.align 2, 0 @ Don't pad with nop.
