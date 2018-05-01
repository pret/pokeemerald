	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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

	thumb_func_start CreateDexDisplayMonDataTask
CreateDexDisplayMonDataTask: @ 80BFDF4
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
	thumb_func_end CreateDexDisplayMonDataTask

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
	ldr r1, =gPokedexMenu_Gfx
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
	bl IsNationalPokedexEnabled
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
	bl PlayCry1
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
	ldr r0, =gPokedexText_Pal + 2
	movs r1, 0x31
	movs r2, 0xE
	bl LoadPalette
	b _080C011E
	.pool
_080C0114:
	ldr r0, =gPokedexCaughtScreenFade_Pal + 0x2
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
	bl GetFrontSpritePalFromSpeciesAndPersonality
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
	ldr r4, =gText_PokedexRegistration
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
	ldr r1, =gText_UnkCtrlF908Clear01
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
	ldr r0, =sText_TenDashes2
_080C028E:
	movs r1, 0x84
	movs r2, 0x19
	bl sub_80BE8DC
	cmp r7, 0
	beq _080C02AC
	add r4, sp, 0x10
	adds r0, r6, 0
	adds r1, r4, 0
	bl CopyMonCategoryText
	adds r0, r4, 0
	b _080C02AE
	.pool
_080C02AC:
	ldr r0, =gText_5MarksPokemon
_080C02AE:
	movs r1, 0x64
	movs r2, 0x29
	bl sub_80BE8DC
	ldr r0, =gText_HTHeight
	movs r1, 0x60
	movs r2, 0x39
	bl sub_80BE8DC
	ldr r0, =gText_WTWeight
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
	ldr r0, =gText_UnkHeight
	movs r1, 0x81
	movs r2, 0x39
	bl sub_80BE8DC
	ldr r0, =gText_UnkWeight
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

	thumb_func_start GetPokedexHeightWeight
GetPokedexHeightWeight: @ 80C0630
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
	thumb_func_end GetPokedexHeightWeight

	thumb_func_start GetSetPokedexFlag
@ u8 GetSetPokedexFlag(u16 nationalPokedexNum, u8 op)
GetSetPokedexFlag: @ 80C0664
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
	thumb_func_end GetSetPokedexFlag

	thumb_func_start GetNationalPokedexCount
GetNationalPokedexCount: @ 80C07F4
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
	bl GetSetPokedexFlag
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
	thumb_func_end GetNationalPokedexCount

	thumb_func_start GetHoennPokedexCount
GetHoennPokedexCount: @ 80C0844
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
	bl GetSetPokedexFlag
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
	thumb_func_end GetHoennPokedexCount

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
	bl GetSetPokedexFlag
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
	bl GetSetPokedexFlag
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
	bl GetSetPokedexFlag
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
	bl GetSetPokedexFlag
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
	bl GetSetPokedexFlag
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
	bl GetSetPokedexFlag
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
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
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
	bl AddTextPrinterParameterized2
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
	bl AddTextPrinterParameterized2
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
	ldr r1, =gPokedexSearchMenu_Gfx
	movs r2, 0x80
	lsls r2, 6
	str r5, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	bl IsNationalPokedexEnabled
	cmp r0, 0
	bne _080C13E4
	ldr r1, =gPokedexSearch2_Tilemap
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	b _080C13F0
	.pool
_080C13E4:
	ldr r1, =gPokedexSearch1_Tilemap
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
_080C13F0:
	ldr r0, =gPokedexSearchMenu_Pal + 0x2
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
	ldr r0, =gSpriteSheets_0855D26C
	bl LoadCompressedObjectPic
	ldr r0, =gSpritePalettes_0855D26C
	bl LoadSpritePalettes
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
	bl PlaySE
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
	bl PlaySE
	strh r4, [r5, 0xA]
	b _080C1626
_080C161C:
	movs r0, 0x15
	bl PlaySE
	movs r0, 0x4
	strh r0, [r5, 0xA]
_080C1626:
	ldr r0, =sub_80C16CC
	str r0, [r5]
	b _080C16BC
	.pool
_080C1630:
	movs r0, 0x3
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl IsNationalPokedexEnabled
	ldr r6, =gUnknown_0856EDB8
	cmp r0, 0
	bne _080C174C
	ldr r6, =gUnknown_0856EDF0
	b _080C174C
	.pool
_080C1740:
	bl IsNationalPokedexEnabled
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
	bl PlaySE
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
	bl IsNationalPokedexEnabled
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
	bl PlaySE
	ldr r0, =sub_80C1D38
	str r0, [r6]
	b _080C1994
	.pool
_080C183C:
	ldr r0, =gText_SearchingPleaseWait
	bl sub_80C2618
	ldr r0, =sub_80C19A4
	str r0, [r6]
	movs r0, 0x70
	bl PlaySE
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _080C1994
	.pool
_080C1860:
	movs r0, 0x15
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl IsSEPlaying
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
	bl PlaySE
	ldr r0, =gText_SearchCompleted
	bl sub_80C2618
	b _080C1A90
	.pool
_080C1A84:
	movs r0, 0x20
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl PlaySE
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
	bl IsNationalPokedexEnabled
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
	bl IsNationalPokedexEnabled
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
	ldr r0, =gText_SelectorArrow
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
