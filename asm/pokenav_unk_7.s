	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(0xC)

	thumb_func_start sub_81CDDD4
sub_81CDDD4: @ 81CDDD4
	push {r4,lr}
	ldr r1, =0x000038ac
	movs r0, 0xC
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CDE24
	ldr r0, =0x00001816
	adds r1, r4, r0
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, =sub_81CDE94
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4]
	ldr r0, =0x00001810
	adds r1, r4, r0
	ldr r0, =sub_81CDE80
	str r0, [r1]
	ldr r0, =0x00002908
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CDE26
	.pool
_081CDE24:
	movs r0, 0
_081CDE26:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDDD4

	thumb_func_start sub_81CDE2C
sub_81CDE2C: @ 81CDE2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, =gUnknown_08623384
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r5]
	ldr r0, =0x00001810
	adds r5, r0
	ldr r0, =sub_81CDE80
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDE2C

	thumb_func_start sub_81CDE64
sub_81CDE64: @ 81CDE64
	push {lr}
	movs r0, 0xC
	bl GetSubstructPtr
	ldr r1, =0x00001810
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDE64

	thumb_func_start sub_81CDE80
sub_81CDE80: @ 81CDE80
	push {lr}
	movs r0, 0xC
	bl GetSubstructPtr
	ldr r0, [r0]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	thumb_func_end sub_81CDE80

	thumb_func_start sub_81CDE94
sub_81CDE94: @ 81CDE94
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x14
	bls _081CDEA8
	b _081CE2C4
_081CDEA8:
	lsls r0, r4, 2
	ldr r1, =_081CDEB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CDEB8:
	.4byte _081CDF0C
	.4byte _081CDF18
	.4byte _081CDF94
	.4byte _081CDFB8
	.4byte _081CE030
	.4byte _081CE074
	.4byte _081CE0B0
	.4byte _081CE118
	.4byte _081CE120
	.4byte _081CE126
	.4byte _081CE136
	.4byte _081CE146
	.4byte _081CE156
	.4byte _081CE16C
	.4byte _081CE1C8
	.4byte _081CE1EC
	.4byte _081CE218
	.4byte _081CE23C
	.4byte _081CE24A
	.4byte _081CE25A
	.4byte _081CE262
_081CDF0C:
	bl sub_81CD3C4
	cmp r0, 0x1
	beq _081CDF16
	b _081CE2C0
_081CDF16:
	b _081CDFB0
_081CDF18:
	ldr r0, =gUnknown_08623358
	movs r1, 0x3
	bl InitBgTemplates
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
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
	ldr r1, =0x00007940
	movs r0, 0
	bl SetGpuReg
	ldr r1, =0x00000844
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000040b
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =gPokenavCondition_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	b _081CDFA8
	.pool
_081CDF94:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081CDFA2
	b _081CE2C0
_081CDFA2:
	ldr r1, =gUnknown_08623228
	str r0, [sp]
	movs r0, 0x2
_081CDFA8:
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081CDFB0:
	movs r0, 0
	b _081CE2C6
	.pool
_081CDFB8:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CDFC4
	b _081CE2C0
_081CDFC4:
	ldr r0, =gPokenavCondition_Tilemap
	adds r4, r5, 0x4
	adds r1, r4, 0
	bl LZ77UnCompVram
	movs r0, 0x3
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CDFF2
	ldr r1, =gPokenavOptions_Tilemap
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x5
	bl CopyToBgTilemapBufferRect
_081CDFF2:
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, =gPokenavCondition_Pal
	movs r1, 0x10
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, =gUnknown_08623208
	movs r1, 0xF0
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, =0x00001814
	adds r1, r5, r0
	ldr r0, =0x0000ffb0
	strh r0, [r1]
	b _081CDFB0
	.pool
_081CE030:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CE03C
	b _081CE2C0
_081CE03C:
	ldr r0, =gUnknown_0862323C
	ldr r1, =0x00001004
	adds r4, r5, r1
	adds r1, r4, 0
	bl LZ77UnCompVram
	movs r0, 0x2
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_086231E8
	movs r1, 0x30
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0x2
	bl sub_81D21DC
	b _081CDFB0
	.pool
_081CE074:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0x1
	movs r1, 0x11
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r2, =0x00000804
	adds r4, r5, r2
	ldr r2, =0x05000200
	add r0, sp, 0x8
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0x1
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	b _081CDFB0
	.pool
_081CE0B0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CE0BC
	b _081CE2C0
_081CE0BC:
	ldr r0, =gUnknown_08623364
	bl AddWindow
	movs r2, 0xC1
	lsls r2, 5
	adds r1, r5, r2
	strb r0, [r1]
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CE0F6
	ldr r0, =gUnknown_0862336C
	bl AddWindow
	ldr r2, =0x00001821
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, =gUnknown_08623374
	bl AddWindow
	ldr r2, =0x00001822
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, =gUnknown_0862337C
	bl AddWindow
	ldr r2, =0x00001823
	adds r1, r5, r2
	strb r0, [r1]
_081CE0F6:
	bl DeactivateAllTextPrinters
	b _081CDFB0
	.pool
_081CE118:
	movs r0, 0
	bl sub_81CED30
	b _081CDFB0
_081CE120:
	bl sub_81CE9E4
	b _081CDFB0
_081CE126:
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE130
	b _081CDFB0
_081CE130:
	bl sub_81CE934
	b _081CDFB0
_081CE136:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE164
_081CE146:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE164
_081CE156:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE164:
	movs r2, 0x1
	bl sub_81CE754
	b _081CDFB0
_081CE16C:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0x1
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE186
	b _081CE2C0
_081CE186:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE19C
	b _081CDFB0
_081CE19C:
	ldr r2, =0x00001821
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r1, =0x00001822
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r2, =0x00001823
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	b _081CDFB0
	.pool
_081CE1C8:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl ShowBg
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE1E4
	b _081CDFB0
_081CE1E4:
	movs r0, 0x4
	bl sub_81C7BA4
	b _081CDFB0
_081CE1EC:
	movs r0, 0x1
	bl sub_81C7AC0
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CE1FC
	b _081CDFB0
_081CE1FC:
	movs r0, 0x6
	bl LoadLeftHeaderGfxForIndex
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	b _081CDFB0
_081CE218:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CE2C0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CE230
	bl sub_81C8010
	cmp r0, 0
	bne _081CE2C0
_081CE230:
	ldr r0, =sub_81CEE44
	bl SetVBlankCallback_
	b _081CDFB0
	.pool
_081CE23C:
	bl sub_81CEE90
	bl sub_81CDC70
	bl sub_81D20AC
	b _081CDFB0
_081CE24A:
	bl sub_81CDC70
	bl sub_81D20BC
	lsls r0, 24
	cmp r0, 0
	bne _081CE2C0
	b _081CDFB0
_081CE25A:
	movs r0, 0x1
	bl sub_81CEE74
	b _081CDFB0
_081CE262:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE2C0
	ldr r0, =0x000028e0
	adds r6, r5, r0
	adds r0, r6, 0
	bl sub_81D3464
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE298
	bl sub_81CDC60
	adds r4, r0, 0
	bl sub_81CDC50
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _081CE2C4
_081CE298:
	ldr r1, =0x00001816
	adds r0, r5, r1
	ldrb r4, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D3480
	b _081CE2C4
	.pool
_081CE2C0:
	movs r0, 0x2
	b _081CE2C6
_081CE2C4:
	movs r0, 0x4
_081CE2C6:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDE94

	thumb_func_start sub_81CE2D0
sub_81CE2D0: @ 81CE2D0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CE308
	cmp r4, 0x1
	bgt _081CE2EA
	cmp r4, 0
	beq _081CE2F4
	b _081CE374
_081CE2EA:
	cmp r4, 0x2
	beq _081CE328
	cmp r4, 0x3
	beq _081CE33E
	b _081CE374
_081CE2F4:
	bl sub_81CEEC8
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D3520
	movs r0, 0x1
	b _081CE376
	.pool
_081CE308:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	bne _081CE34E
	movs r0, 0
	bl sub_81CEE74
	movs r0, 0x1
	b _081CE376
	.pool
_081CE328:
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CE33A
	bl sub_81C78A0
_081CE33A:
	movs r0, 0
	b _081CE376
_081CE33E:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CE34E
	bl MainMenuLoopedTaskIsBusy
	cmp r0, 0
	beq _081CE352
_081CE34E:
	movs r0, 0x2
	b _081CE376
_081CE352:
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D354C
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	b _081CE376
	.pool
_081CE374:
	movs r0, 0x4
_081CE376:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE2D0

	thumb_func_start sub_81CE37C
sub_81CE37C: @ 81CE37C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	adds r6, r0, 0
	bl sub_81CDC70
	adds r2, r0, 0
	cmp r4, 0x9
	bls _081CE394
	b _081CE4D0
_081CE394:
	lsls r0, r4, 2
	ldr r1, =_081CE3A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE3A4:
	.4byte _081CE3CC
	.4byte _081CE3D0
	.4byte _081CE3DA
	.4byte _081CE3F0
	.4byte _081CE3F8
	.4byte _081CE418
	.4byte _081CE428
	.4byte _081CE438
	.4byte _081CE44E
	.4byte _081CE468
_081CE3CC:
	movs r0, 0
	b _081CE3D2
_081CE3D0:
	movs r0, 0x1
_081CE3D2:
	bl sub_81CD548
_081CE3D6:
	movs r0, 0x1
	b _081CE4D2
_081CE3DA:
	movs r0, 0x2
	bl sub_81CD548
	ldr r1, =0x000028e0
	adds r0, r6, r1
	bl sub_81D3520
	b _081CE3D6
	.pool
_081CE3F0:
	adds r0, r2, 0
	bl sub_81D2074
	b _081CE3D6
_081CE3F8:
	ldr r1, =0x00001814
	adds r0, r6, r1
	bl sub_81D3150
	lsls r0, 24
	cmp r0, 0
	bne _081CE4CC
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	bl sub_81CED30
	b _081CE3D6
	.pool
_081CE418:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE446
_081CE428:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE446
_081CE438:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE446:
	movs r2, 0
	bl sub_81CE754
	b _081CE3D6
_081CE44E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE3D6
	b _081CE4CC
_081CE468:
	bl sub_81CDC70
	adds r2, r0, 0
	ldr r0, =0x00001814
	adds r1, r6, r0
	adds r0, r2, 0
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE4CC
	ldr r1, =0x000028e0
	adds r0, r6, r1
	bl sub_81D3464
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE4A0
	bl sub_81CDC60
	adds r4, r0, 0
	bl sub_81CDC50
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _081CE3D6
_081CE4A0:
	ldr r0, =0x000028e0
	adds r5, r6, r0
	ldr r1, =0x00001816
	adds r0, r6, r1
	ldrb r4, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81D3480
	b _081CE3D6
	.pool
_081CE4CC:
	movs r0, 0x2
	b _081CE4D2
_081CE4D0:
	movs r0, 0x4
_081CE4D2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE37C

	thumb_func_start sub_81CE4D8
sub_81CE4D8: @ 81CE4D8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x8
	bhi _081CE5DC
	lsls r0, r4, 2
	ldr r1, =_081CE4F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE4F8:
	.4byte _081CE51C
	.4byte _081CE520
	.4byte _081CE524
	.4byte _081CE52E
	.4byte _081CE53E
	.4byte _081CE54E
	.4byte _081CE55E
	.4byte _081CE576
	.4byte _081CE592
_081CE51C:
	movs r0, 0
	b _081CE526
_081CE520:
	movs r0, 0x1
	b _081CE526
_081CE524:
	movs r0, 0x2
_081CE526:
	bl sub_81CD548
	movs r0, 0x1
	b _081CE5DE
_081CE52E:
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	bl sub_81CED30
	movs r0, 0x1
	b _081CE5DE
_081CE53E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE56C
_081CE54E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE56C
_081CE55E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE56C:
	movs r2, 0
	bl sub_81CE754
	movs r0, 0x1
	b _081CE5DE
_081CE576:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	bne _081CE5D8
	movs r0, 0x1
	b _081CE5DE
_081CE592:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE5D8
	ldr r0, =0x000028e0
	adds r4, r5, r0
	adds r0, r4, 0
	bl sub_81D3464
	ldr r1, =0x00001816
	adds r0, r5, r1
	ldrb r5, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3480
	movs r0, 0x1
	b _081CE5DE
	.pool
_081CE5D8:
	movs r0, 0x2
	b _081CE5DE
_081CE5DC:
	movs r0, 0x4
_081CE5DE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE4D8

	thumb_func_start sub_81CE5E4
sub_81CE5E4: @ 81CE5E4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x7
	bhi _081CE6B2
	lsls r0, r4, 2
	ldr r1, =_081CE604
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE604:
	.4byte _081CE624
	.4byte _081CE628
	.4byte _081CE632
	.4byte _081CE648
	.4byte _081CE660
	.4byte _081CE670
	.4byte _081CE680
	.4byte _081CE696
_081CE624:
	movs r0, 0
	b _081CE62A
_081CE628:
	movs r0, 0x1
_081CE62A:
	bl sub_81CD548
_081CE62E:
	movs r0, 0x1
	b _081CE6B4
_081CE632:
	movs r0, 0x2
	bl sub_81CD548
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D3520
	b _081CE62E
	.pool
_081CE648:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	beq _081CE62E
	b _081CE6AE
	.pool
_081CE660:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE68E
_081CE670:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE68E
_081CE680:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE68E:
	movs r2, 0
	bl sub_81CE754
	b _081CE62E
_081CE696:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE62E
_081CE6AE:
	movs r0, 0x2
	b _081CE6B4
_081CE6B2:
	movs r0, 0x4
_081CE6B4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE5E4

	thumb_func_start sub_81CE6BC
sub_81CE6BC: @ 81CE6BC
	push {lr}
	cmp r0, 0x1
	beq _081CE6E6
	cmp r0, 0x1
	bgt _081CE6CC
	cmp r0, 0
	beq _081CE6D2
	b _081CE6FA
_081CE6CC:
	cmp r0, 0x2
	beq _081CE6EE
	b _081CE6FA
_081CE6D2:
	bl sub_81CDD7C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xB0
	movs r2, 0x20
	bl sub_811FAA4
_081CE6E2:
	movs r0, 0x1
	b _081CE6FC
_081CE6E6:
	movs r0, 0x5
	bl sub_81C7BA4
	b _081CE6E2
_081CE6EE:
	bl IsDma3ManagerBusyWithBgCopy_
	cmp r0, 0x1
	bne _081CE6E2
	movs r0, 0x2
	b _081CE6FC
_081CE6FA:
	movs r0, 0x4
_081CE6FC:
	pop {r1}
	bx r1
	thumb_func_end sub_81CE6BC

	thumb_func_start sub_81CE700
sub_81CE700: @ 81CE700
	push {lr}
	cmp r0, 0x1
	beq _081CE71E
	cmp r0, 0x1
	bgt _081CE710
	cmp r0, 0
	beq _081CE716
	b _081CE732
_081CE710:
	cmp r0, 0x2
	beq _081CE726
	b _081CE732
_081CE716:
	bl sub_811FAF8
_081CE71A:
	movs r0, 0x1
	b _081CE734
_081CE71E:
	movs r0, 0x4
	bl sub_81C7BA4
	b _081CE71A
_081CE726:
	bl IsDma3ManagerBusyWithBgCopy_
	cmp r0, 0x1
	bne _081CE71A
	movs r0, 0x2
	b _081CE734
_081CE732:
	movs r0, 0x4
_081CE734:
	pop {r1}
	bx r1
	thumb_func_end sub_81CE700

	thumb_func_start sub_81CE738
sub_81CE738: @ 81CE738
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_Number2
	bl StringCopy
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CE738

	thumb_func_start sub_81CE754
sub_81CE754: @ 81CE754
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0xC
	bl GetSubstructPtr
	adds r6, r0, 0
	cmp r4, 0x1
	beq _081CE7B8
	cmp r4, 0x1
	bgt _081CE782
	cmp r4, 0
	beq _081CE78E
	b _081CE924
_081CE782:
	cmp r4, 0x2
	beq _081CE800
	cmp r4, 0x3
	bne _081CE78C
	b _081CE89C
_081CE78C:
	b _081CE924
_081CE78E:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE7A6
	b _081CE924
_081CE7A6:
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	b _081CE924
	.pool
_081CE7B8:
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	bne _081CE7DA
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE7DA
	b _081CE924
_081CE7DA:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81CDD04
	adds r2, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	str r7, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	b _081CE924
_081CE800:
	bl sub_81CDD5C
	adds r7, r0, 0
	cmp r7, 0x1
	beq _081CE80C
	b _081CE924
_081CE80C:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81CDD24
	adds r2, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x11
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	add r1, sp, 0xC
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	adds r0, r1, 0
	strb r4, [r0, 0x3]
	movs r0, 0x9
	strb r0, [r1, 0x4]
	mov r5, sp
	adds r5, 0x11
	ldr r1, =gText_Number2
	adds r0, r5, 0
	bl StringCopy
	ldr r0, =0x00001821
	adds r6, r0
	ldrb r0, [r6]
	str r7, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x4
	bl AddTextPrinterParameterized
	bl sub_81CDD48
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldrb r0, [r6]
	str r7, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x1C
	bl AddTextPrinterParameterized
	b _081CE924
	.pool
_081CE89C:
	ldr r1, =0x00002908
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CE8B0
	cmp r0, 0x1
	beq _081CE8EC
	b _081CE924
	.pool
_081CE8B0:
	cmp r5, 0
	beq _081CE8C4
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081CE8D2
_081CE8C4:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
_081CE8D2:
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CE910
	ldr r0, =0x00002908
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081CE924
	.pool
_081CE8EC:
	cmp r5, 0
	beq _081CE904
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081CE910
	.pool
_081CE904:
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
_081CE910:
	ldr r0, =0x00002908
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CE926
	.pool
_081CE924:
	movs r0, 0
_081CE926:
	add sp, 0x2C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE754

	thumb_func_start sub_81CE934
sub_81CE934: @ 81CE934
	push {r4,lr}
	movs r0, 0xC
	bl GetSubstructPtr
	adds r4, r0, 0
	ldr r1, =0x00001822
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =0x00001823
	adds r4, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CE934

	thumb_func_start sub_81CE964
sub_81CE964: @ 81CE964
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	bl sub_81CDC60
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	bne _081CE982
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAnim
	b _081CE98A
_081CE982:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_081CE98A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE964

	thumb_func_start sub_81CE990
sub_81CE990: @ 81CE990
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	bne _081CE9B0
	movs r0, 0x65
	b _081CE9B2
_081CE9B0:
	movs r0, 0x66
_081CE9B2:
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r5, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE990

	thumb_func_start sub_81CE9C8
sub_81CE9C8: @ 81CE9C8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CDD7C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE9C8

	thumb_func_start sub_81CE9E4
sub_81CE9E4: @ 81CE9E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	movs r0, 0xC
	bl GetSubstructPtr
	adds r6, r0, 0
	add r4, sp, 0x20
	add r5, sp, 0x38
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81D321C
	bl sub_81CDD5C
	adds r7, r4, 0
	mov r10, r5
	cmp r0, 0x1
	bne _081CEA78
	ldr r1, =0x00001824
	adds r0, r6, r1
	movs r2, 0x6A
	strh r2, [r0]
	ldr r3, =0x00001826
	adds r1, r6, r3
	strh r2, [r1]
	bl sub_811F90C
	bl sub_811FA90
	ldr r2, =gUnknown_08623338
	movs r0, 0x69
	movs r1, 0x69
	bl sub_811FF94
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0xC0
	strh r1, [r0, 0x20]
	movs r1, 0x20
	strh r1, [r0, 0x22]
	ldr r1, =sub_81CE9C8
	str r1, [r0, 0x1C]
	ldr r2, =0x000028dc
	adds r1, r6, r2
	str r0, [r1]
	movs r0, 0x69
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81C7990
	add r3, sp, 0x50
	mov r8, r3
	b _081CEBC6
	.pool
_081CEA78:
	mov r0, sp
	bl LoadSpriteSheets
	mov r0, r10
	bl Pokenav_AllocAndLoadPalettes
	movs r4, 0
	add r0, sp, 0x50
	mov r8, r0
	b _081CEAE8
_081CEA8C:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r1, 0x80
	lsls r1, 12
	adds r2, r1
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xE2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEAD8
	ldr r2, =0x00001806
	adds r0, r6, r2
	adds r0, r4
	strb r3, [r0]
	ldr r2, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r1, r0, r2
	strh r4, [r1, 0x2E]
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81CE964
	str r1, [r0]
	b _081CEAE2
	.pool
_081CEAD8:
	ldr r3, =0x00001806
	adds r0, r6, r3
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081CEAE2:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081CEAE8:
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	blt _081CEA8C
	movs r0, 0x67
	strh r0, [r7]
	ldr r0, =SpriteCallbackDummy
	str r0, [r7, 0x14]
	cmp r4, 0x5
	bhi _081CEB5C
	ldr r0, =0x00001806
	adds r5, r6, r0
	ldr r1, =gSprites
	mov r9, r1
_081CEB0A:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r3, 0x80
	lsls r3, 12
	adds r2, r3
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xE6
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEB4C
	adds r0, r5, r4
	strb r3, [r0]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x3]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x3]
	b _081CEB52
	.pool
_081CEB4C:
	adds r1, r5, r4
	movs r0, 0xFF
	strb r0, [r1]
_081CEB52:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x5
	bls _081CEB0A
_081CEB5C:
	movs r0, 0x66
	strh r0, [r7]
	ldr r0, =sub_81CE990
	str r0, [r7, 0x14]
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xDE
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEBBC
	ldr r1, =0x00001806
	adds r0, r6, r1
	adds r0, r4
	strb r3, [r0]
	ldr r0, =gSprites
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r0
	ldrb r3, [r2, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r3
	movs r3, 0x40
	orrs r0, r3
	strb r0, [r2, 0x1]
	ldrb r0, [r2, 0x3]
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	strb r1, [r2, 0x3]
	b _081CEBC6
	.pool
_081CEBBC:
	ldr r2, =0x00001806
	adds r0, r6, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081CEBC6:
	mov r0, r8
	mov r1, r10
	bl sub_81D32B0
	mov r0, r8
	bl LoadSpriteSheet
	movs r0, 0
	mov r3, r10
	str r0, [r3, 0x8]
	mov r0, r10
	bl Pokenav_AllocAndLoadPalettes
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CE9E4

	thumb_func_start sub_81CEBF4
sub_81CEBF4: @ 81CEBF4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CEC28
	ldr r1, =0x000028dc
	adds r0, r5, r1
	ldr r0, [r0]
	bl DestroySprite
	movs r0, 0x6A
	bl FreeSpriteTilesByTag
	movs r0, 0x69
	bl FreeSpriteTilesByTag
	movs r0, 0x6A
	bl FreeSpritePaletteByTag
	movs r0, 0x69
	bl FreeSpritePaletteByTag
	b _081CEC68
	.pool
_081CEC28:
	movs r4, 0
_081CEC2A:
	ldr r1, =0x00001806
	adds r0, r5, r1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _081CEC2A
	movs r0, 0x65
	bl FreeSpriteTilesByTag
	movs r0, 0x66
	bl FreeSpriteTilesByTag
	movs r0, 0x67
	bl FreeSpriteTilesByTag
	movs r0, 0x65
	bl FreeSpritePaletteByTag
	movs r0, 0x66
	bl FreeSpritePaletteByTag
_081CEC68:
	ldr r0, =0x00001816
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081CEC8E
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r0, 0x64
	bl FreeSpriteTilesByTag
	movs r0, 0x64
	bl FreeSpritePaletteByTag
_081CEC8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CEBF4

	thumb_func_start sub_81CECA0
sub_81CECA0: @ 81CECA0
	push {r4,lr}
	movs r0, 0xC
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CECEC
	ldr r1, =0x00001821
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, =0x00001822
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, =0x00001823
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	b _081CECF0
	.pool
_081CECEC:
	bl sub_81C7FDC
_081CECF0:
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_81CEBF4
	bl sub_81CEE68
	movs r0, 0xC
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CECA0

	thumb_func_start sub_81CED10
sub_81CED10: @ 81CED10
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl GetSubstructPtr
	ldr r1, =0x00001814
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x26
	strh r0, [r4, 0x20]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CED10

	thumb_func_start sub_81CED30
sub_81CED30: @ 81CED30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0xC
	bl GetSubstructPtr
	mov r8, r0
	ldr r7, =0x00001816
	add r7, r8
	ldrb r0, [r7]
	cmp r0, 0xFF
	bne _081CEDFC
	add r5, sp, 0x18
	add r4, sp, 0x20
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_81D31D0
	adds r0, r6, 0
	bl sub_81CDCB4
	str r0, [sp, 0x18]
	adds r0, r6, 0
	bl sub_81CDCD4
	str r0, [sp, 0x20]
	adds r0, r4, 0
	bl LoadSpritePalette
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =0x00001818
	add r4, r8
	strh r0, [r4]
	adds r0, r5, 0
	bl LoadSpriteSheet
	ldr r5, =0x0000181a
	add r5, r8
	strh r0, [r5]
	mov r0, sp
	movs r1, 0x26
	movs r2, 0x68
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r7]
	cmp r0, 0x40
	bne _081CEDBC
	movs r0, 0x64
	bl FreeSpriteTilesByTag
	movs r0, 0x64
	bl FreeSpritePaletteByTag
	movs r0, 0xFF
	strb r0, [r7]
	b _081CEE26
	.pool
_081CEDBC:
	strb r0, [r7]
	ldr r2, =gSprites
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81CED10
	str r1, [r0]
	ldr r1, =0x0000181c
	add r1, r8
	ldrh r0, [r5]
	lsls r0, 5
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4]
	b _081CEE26
	.pool
_081CEDFC:
	adds r0, r6, 0
	bl sub_81CDCB4
	ldr r1, =0x0000181c
	add r1, r8
	ldr r2, [r1]
	ldr r1, =0x040000d4
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x80000400
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r0, r6, 0
	bl sub_81CDCD4
	ldr r1, =0x00001818
	add r1, r8
	ldrh r1, [r1]
	movs r2, 0x20
	bl LoadPalette
_081CEE26:
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CED30

	thumb_func_start sub_81CEE44
sub_81CEE44: @ 81CEE44
	push {r4,lr}
	bl sub_81CDC70
	adds r4, r0, 0
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	adds r0, r4, 0
	bl sub_81D2108
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE44

	thumb_func_start sub_81CEE68
sub_81CEE68: @ 81CEE68
	push {lr}
	bl SetPokenavVBlankCallback
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE68

	thumb_func_start sub_81CEE74
sub_81CEE74: @ 81CEE74
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _081CEE84
	movs r0, 0x2
	bl ShowBg
	b _081CEE8A
_081CEE84:
	movs r0, 0x2
	bl HideBg
_081CEE8A:
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE74

	thumb_func_start sub_81CEE90
sub_81CEE90: @ 81CEE90
	push {r4,lr}
	bl sub_81CDC70
	adds r4, r0, 0
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_030012BC
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x50
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r2, 0x14
	adds r2, r4, r2
	adds r0, r4, 0
	bl sub_81D1F84
	adds r0, r4, 0
	bl sub_81D2074
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CEE90

	thumb_func_start sub_81CEEC8
sub_81CEEC8: @ 81CEEC8
	push {r4,r5,lr}
	bl sub_81CDC70
	adds r5, r0, 0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CEEF0
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	beq _081CEF0C
_081CEEF0:
	bl sub_81CDC84
	lsls r0, 24
	asrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x14
	adds r1, r5, r1
	adds r2, r5, 0
	adds r2, 0x50
	adds r0, r5, 0
	bl sub_81D1F84
_081CEF0C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CEEC8

	thumb_func_start sub_81CEF14
sub_81CEF14: @ 81CEF14
	push {r4,lr}
	movs r0, 0xC
	bl GetSubstructPtr
	adds r4, r0, 0
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CEF2A
	movs r0, 0
	b _081CEF30
_081CEF2A:
	ldr r1, =0x00001828
	adds r0, r4, r1
	ldrb r0, [r0]
_081CEF30:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CEF14
    
    .align 2, 0 @ Don't pad with nop.
