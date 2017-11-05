	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text






	thumb_func_start HallOfFame_PrintWelcomeText
HallOfFame_PrintWelcomeText: @ 8174A38
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	ldr r4, =gText_WelcomeToHOF
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
	thumb_func_end HallOfFame_PrintWelcomeText

	thumb_func_start HallOfFame_PrintMonInfo
HallOfFame_PrintMonInfo: @ 8174A88
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
	ldr r1, =gText_Number
	add r0, sp, 0xC
	bl StringCopy
	adds r6, r0, 0
	ldrh r0, [r7, 0x8]
	lsls r0, 23
	lsrs r0, 23
	bl SpeciesToPokedexNum
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
	bl GetGenderFromSpeciesAndPersonality
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
	ldr r1, =gText_Level
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
	ldr r1, =gText_IDNumber
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
	thumb_func_end HallOfFame_PrintMonInfo

	thumb_func_start HallOfFame_PrintPlayerInfo
HallOfFame_PrintPlayerInfo: @ 8174C98
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
	ldr r0, =gText_Name
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
	ldr r0, =gText_IDNumber
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
	ldr r0, =gText_MainMenuTime
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
	thumb_func_end HallOfFame_PrintPlayerInfo

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
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
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
	bl DoMonFrontSpriteAnimation
	b _0817519C
_08175190:
	lsrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x3
	bl DoMonFrontSpriteAnimation
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
	ldr r4, =gSpecialVar_0x8004
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
	ldr r0, =gSpecialVar_0x8005
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
	ldr r0, =gSpecialVar_0x8004
	strh r7, [r0]
	ldr r1, =gSpecialVar_0x8005
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
	ldr r0, =gSpecialVar_0x8004
	strh r7, [r0]
	ldr r1, =gSpecialVar_0x8005
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
