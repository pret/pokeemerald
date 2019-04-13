	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_802CE9C
sub_802CE9C: @ 802CE9C
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	movs r4, 0
	ldr r6, =gUnknown_082FBE58
_0802CEA6:
	ldr r1, =gUnknown_082FBEB8
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r2, =gUnknown_082FBEA8
	lsls r1, r5, 1
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r6, r3]
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r5, 2
	ldr r3, =0x000081d0
	adds r2, r7, r3
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	adds r5, 0x1
	adds r6, 0x14
	adds r4, 0x1
	cmp r4, 0x3
	ble _0802CEA6
	movs r4, 0x3
	movs r6, 0x3C
_0802CEE8:
	ldr r1, =gUnknown_082FBEB8
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r2, =gUnknown_082FBEA8
	lsls r1, r5, 1
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	ldr r2, =gUnknown_082FBE58
	adds r2, r6, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r5, 2
	ldr r3, =0x000081d0
	adds r2, r7, r3
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	adds r5, 0x1
	subs r6, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _0802CEE8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CE9C

	thumb_func_start sub_802CF50
sub_802CF50: @ 802CF50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp, 0x8]
	cmp r1, 0x5
	ble _0802CF70
	movs r0, 0xA
	subs r1, r0, r1
	movs r0, 0x3
	str r0, [sp]
	ldr r2, [sp, 0x8]
	ldrb r0, [r2, 0xF]
	b _0802CF78
_0802CF70:
	movs r3, 0x2
	str r3, [sp]
	ldr r7, [sp, 0x8]
	ldrb r0, [r7, 0xE]
_0802CF78:
	movs r6, 0
	lsls r2, r1, 1
	str r2, [sp, 0x4]
	lsls r0, 4
	mov r9, r0
	lsls r1, 24
	mov r8, r1
	ldr r0, =gUnknown_082FBE58
	adds r4, r2, r0
	ldr r3, [sp]
	lsls r3, 2
	mov r10, r3
	movs r5, 0x3
_0802CF92:
	lsls r0, r6, 2
	ldr r7, [sp, 0x8]
	ldr r1, =0x000081d0
	adds r2, r7, r1
	adds r2, r0
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1, 0x22]
	ldr r3, [r2]
	ldrb r0, [r3, 0x5]
	movs r7, 0xD
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	mov r1, r10
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r3, [r2]
	ldrb r1, [r3, 0x5]
	movs r0, 0xF
	ands r0, r1
	mov r7, r9
	orrs r0, r7
	strb r0, [r3, 0x5]
	ldr r0, [r2]
	mov r2, r8
	lsrs r1, r2, 24
	bl StartSpriteAnim
	adds r6, 0x1
	adds r4, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _0802CF92
	movs r5, 0x3
	ldr r0, =gUnknown_082FBE58
	ldr r3, [sp, 0x4]
	adds r0, r3, r0
	adds r4, r0, 0
	adds r4, 0x3C
	ldr r7, [sp]
	lsls r7, 2
	mov r10, r7
_0802CFE8:
	lsls r0, r6, 2
	ldr r1, [sp, 0x8]
	ldr r3, =0x000081d0
	adds r2, r1, r3
	adds r2, r0
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1, 0x22]
	ldr r3, [r2]
	ldrb r0, [r3, 0x5]
	movs r7, 0xD
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	mov r1, r10
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r3, [r2]
	ldrb r1, [r3, 0x5]
	movs r0, 0xF
	ands r0, r1
	mov r7, r9
	orrs r0, r7
	strb r0, [r3, 0x5]
	ldr r0, [r2]
	mov r2, r8
	lsrs r1, r2, 24
	bl StartSpriteAnim
	adds r6, 0x1
	subs r4, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _0802CFE8
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CF50

	thumb_func_start sub_802D044
sub_802D044: @ 802D044
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x9
	movs r1, 0x7
	movs r2, 0x78
	movs r3, 0x50
	bl sub_802EB24
	adds r0, r4, 0
	bl sub_802CD3C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D044

	thumb_func_start sub_802D068
sub_802D068: @ 802D068
	push {lr}
	bl sub_802EB84
	pop {r1}
	bx r1
	thumb_func_end sub_802D068

	thumb_func_start sub_802D074
sub_802D074: @ 802D074
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	str r0, [r4]
	bl sub_802D0BC
	ldr r0, =sub_802D12C
	movs r1, 0x3
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0x6]
	ldr r2, [r4]
	ldrb r0, [r2, 0x6]
	movs r1, 0x2
	bl SetWordTaskArg
	ldr r0, =sub_802D150
	bl sub_802D108
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D074

	thumb_func_start sub_802D0AC
sub_802D0AC: @ 802D0AC
	push {lr}
	bl FreeAllWindowBuffers
	bl sub_8034CC8
	pop {r0}
	bx r0
	thumb_func_end sub_802D0AC

	thumb_func_start sub_802D0BC
sub_802D0BC: @ 802D0BC
	movs r1, 0
	strh r1, [r0, 0x4]
	str r1, [r0]
	movs r1, 0xFF
	strh r1, [r0, 0x12]
	bx lr
	thumb_func_end sub_802D0BC

	thumb_func_start sub_802D0C8
sub_802D0C8: @ 802D0C8
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_082FE18C
_0802D0D0:
	ldr r0, [r4]
	cmp r0, r6
	bne _0802D0DC
	ldr r0, [r4, 0x4]
	bl sub_802D108
_0802D0DC:
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x9
	bls _0802D0D0
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D0C8

	thumb_func_start sub_802D0F0
sub_802D0F0: @ 802D0F0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_802D0F0

	thumb_func_start sub_802D108
sub_802D108: @ 802D108
	push {r4,lr}
	adds r2, r0, 0
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	movs r1, 0
	bl SetWordTaskArg
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0x4]
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D108

	thumb_func_start sub_802D12C
sub_802D12C: @ 802D12C
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	bne _0802D148
	adds r0, r1, 0
	movs r1, 0
	bl GetWordTaskArg
	bl _call_via_r0
_0802D148:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D12C

	thumb_func_start sub_802D150
sub_802D150: @ 802D150
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, =gUnknown_02022D00
	ldr r1, [r6]
	ldrh r5, [r1, 0x4]
	cmp r5, 0x1
	bne _0802D160
	b _0802D298
_0802D160:
	cmp r5, 0x1
	bgt _0802D170
	cmp r5, 0
	beq _0802D178
	b _0802D2DA
	.pool
_0802D170:
	cmp r5, 0x2
	bne _0802D176
	b _0802D2D6
_0802D176:
	b _0802D2DA
_0802D178:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082FE164
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_082FE174
	bl InitWindows
	bl reset_temp_tile_data_buffers
	ldr r0, [r6]
	bl sub_802C974
	bl sub_802DD08
	ldr r0, =gPkmnJumpBgPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gPkmnJumpBgGfx
	str r5, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gPkmnJumpBgTilemap
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gPkmnJumpVenusaurPal
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gPkmnJumpVenusaurGfx
	str r5, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gPkmnJumpVenusaurTilemap
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gPkmnJumpResultsPal
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gPkmnJumpResultsGfx
	str r5, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gPkmnJumpResultsTilemap
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gPkmnJumpPal3
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r1, [r6]
	movs r0, 0xD3
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	bl SetBgTilemapBuffer
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	bl sub_802DB8C
	movs r0, 0
	bl sub_802DD64
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_8098C6C
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	bl ResetBgPositions
	b _0802D2CC
	.pool
_0802D298:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _0802D2DA
	bl sub_802DBF8
	ldr r0, [r6]
	bl sub_802CE9C
	ldr r0, [r6]
	movs r1, 0x6
	bl sub_802CF50
	movs r0, 0x3
	bl ShowBg
	movs r0, 0
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x1
	bl HideBg
_0802D2CC:
	ldr r1, [r6]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D2DA
_0802D2D6:
	movs r0, 0x1
	str r0, [r1]
_0802D2DA:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802D150

	thumb_func_start sub_802D2E4
sub_802D2E4: @ 802D2E4
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x1
	beq _0802D310
	cmp r0, 0x1
	bgt _0802D300
	cmp r0, 0
	beq _0802D30A
	b _0802D34A
	.pool
_0802D300:
	cmp r0, 0x2
	beq _0802D322
	cmp r0, 0x3
	beq _0802D33A
	b _0802D34A
_0802D30A:
	bl sub_802DE1C
	b _0802D330
_0802D310:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D34A
	movs r0, 0
	bl sub_802DF70
	b _0802D330
_0802D322:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D34A
	bl sub_802DFD4
_0802D330:
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D34A
_0802D33A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D34A
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
_0802D34A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D2E4

	thumb_func_start sub_802D350
sub_802D350: @ 802D350
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x1
	beq _0802D37C
	cmp r0, 0x1
	bgt _0802D36C
	cmp r0, 0
	beq _0802D376
	b _0802D3B6
	.pool
_0802D36C:
	cmp r0, 0x2
	beq _0802D38E
	cmp r0, 0x3
	beq _0802D3A6
	b _0802D3B6
_0802D376:
	bl sub_802DE1C
	b _0802D39C
_0802D37C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D3B6
	movs r0, 0x1
	bl sub_802DF70
	b _0802D39C
_0802D38E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D3B6
	bl sub_802DFD4
_0802D39C:
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D3B6
_0802D3A6:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D3B6
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
_0802D3B6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D350

	thumb_func_start sub_802D3BC
sub_802D3BC: @ 802D3BC
	push {r4,r5,lr}
	bl sub_802C8AC
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	beq _0802D3DC
	cmp r0, 0x1
	beq _0802D410
	b _0802D43E
	.pool
_0802D3DC:
	movs r4, 0
	cmp r4, r5
	bge _0802D3F8
_0802D3E2:
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r4, 0x1
	cmp r4, r5
	blt _0802D3E2
_0802D3F8:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022D00
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D43E
	.pool
_0802D410:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D43E
	movs r4, 0
	cmp r4, r5
	bge _0802D436
_0802D420:
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	adds r4, 0x1
	cmp r4, r5
	blt _0802D420
_0802D436:
	ldr r0, =gUnknown_02022D00
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1]
_0802D43E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D3BC

	thumb_func_start sub_802D448
sub_802D448: @ 802D448
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D4A4
	cmp r4, 0x1
	bgt _0802D464
	cmp r4, 0
	beq _0802D46A
	b _0802D4EC
	.pool
_0802D464:
	cmp r4, 0x2
	beq _0802D4DC
	b _0802D4EC
_0802D46A:
	movs r0, 0x1
	movs r1, 0x8
	movs r2, 0x14
	movs r3, 0x2
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_WantToPlayAgain2
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D4D2
	.pool
_0802D4A4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D4EC
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl DrawTextBorderOuter
	movs r0, 0x17
	movs r1, 0x7
	movs r2, 0
	bl sub_802DB18
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D4D2:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D4EC
_0802D4DC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D4EC
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D4EC:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D448

	thumb_func_start sub_802D4F4
sub_802D4F4: @ 802D4F4
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D550
	cmp r4, 0x1
	bgt _0802D510
	cmp r4, 0
	beq _0802D516
	b _0802D58E
	.pool
_0802D510:
	cmp r4, 0x2
	beq _0802D57E
	b _0802D58E
_0802D516:
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x1A
	movs r3, 0x4
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_SavingDontTurnOffPower
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D574
	.pool
_0802D550:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D58E
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl DrawTextBorderOuter
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D574:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D58E
_0802D57E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D58E
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D58E:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D4F4

	thumb_func_start sub_802D598
sub_802D598: @ 802D598
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0
	beq _0802D5B0
	cmp r4, 0x1
	beq _0802D5C8
	b _0802D5DE
	.pool
_0802D5B0:
	bl sub_802DA14
	bl sub_8198C78
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D5DE
_0802D5C8:
	bl sub_802DA44
	cmp r0, 0
	bne _0802D5DE
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D5DE
	ldr r0, [r5]
	str r4, [r0]
_0802D5DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D598

	thumb_func_start sub_802D5E4
sub_802D5E4: @ 802D5E4
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D640
	cmp r4, 0x1
	bgt _0802D600
	cmp r4, 0
	beq _0802D606
	b _0802D67E
	.pool
_0802D600:
	cmp r4, 0x2
	beq _0802D66E
	b _0802D67E
_0802D606:
	movs r0, 0x2
	movs r1, 0x8
	movs r2, 0x16
	movs r3, 0x4
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_SomeoneDroppedOut2
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D664
	.pool
_0802D640:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D67E
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl DrawTextBorderOuter
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D664:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D67E
_0802D66E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D67E
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D67E:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D5E4

	thumb_func_start sub_802D688
sub_802D688: @ 802D688
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D6E4
	cmp r4, 0x1
	bgt _0802D6A4
	cmp r4, 0
	beq _0802D6AA
	b _0802D722
	.pool
_0802D6A4:
	cmp r4, 0x2
	beq _0802D712
	b _0802D722
_0802D6AA:
	movs r0, 0x7
	movs r1, 0xA
	movs r2, 0x10
	movs r3, 0x2
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_CommunicationStandby4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D708
	.pool
_0802D6E4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D722
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl DrawTextBorderOuter
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D708:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D722
_0802D712:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D722
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D722:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D688

	thumb_func_start sub_802D72C
sub_802D72C: @ 802D72C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0
	beq _0802D744
	cmp r4, 0x1
	beq _0802D752
	b _0802D75E
	.pool
_0802D744:
	bl sub_802D044
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D75E
_0802D752:
	bl sub_802D068
	cmp r0, 0
	bne _0802D75E
	ldr r0, [r5]
	str r4, [r0]
_0802D75E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D72C

	thumb_func_start sub_802D764
sub_802D764: @ 802D764
	push {lr}
	ldr r1, =gUnknown_02022D00
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0xA]
	ldr r0, [r1]
	strb r2, [r0, 0xB]
	ldr r2, [r1]
	movs r0, 0x6
	strb r0, [r2, 0xC]
	ldr r0, [r1]
	ldrb r0, [r0, 0xC]
	bl sub_802DC9C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D764

	thumb_func_start sub_802D788
sub_802D788: @ 802D788
	push {r4,lr}
	ldr r0, =gUnknown_02022D00
	ldr r2, [r0]
	ldrb r3, [r2, 0xA]
	adds r4, r0, 0
	cmp r3, 0
	beq _0802D7A0
	cmp r3, 0x1
	beq _0802D7DA
	b _0802D7DE
	.pool
_0802D7A0:
	ldrb r0, [r2, 0xB]
	adds r0, 0x1
	strb r0, [r2, 0xB]
	ldr r1, [r4]
	ldrb r0, [r1, 0xB]
	cmp r0, 0xA
	bls _0802D7CA
	strb r3, [r1, 0xB]
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	adds r1, 0x1
	strb r1, [r0, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x9
	bls _0802D7CA
	strb r3, [r1, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0xA]
	adds r0, 0x1
	strb r0, [r1, 0xA]
_0802D7CA:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_802DC9C
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	cmp r0, 0x7
	bne _0802D7DE
_0802D7DA:
	movs r0, 0
	b _0802D7E0
_0802D7DE:
	movs r0, 0x1
_0802D7E0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802D788

	thumb_func_start sub_802D7E8
sub_802D7E8: @ 802D7E8
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	lsrs r4, 16
	ldr r5, =gUnknown_02022D00
	ldr r1, [r5]
	adds r1, 0x26
	adds r2, r4, 0
	bl CopyItemNameHandlePlural
	ldr r0, [r5]
	adds r0, 0x66
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r5]
	adds r1, 0x26
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, [r5]
	adds r1, 0x66
	movs r0, 0x1
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r5]
	adds r0, 0xA6
	ldr r1, =gText_AwesomeWonF701F700
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x4
	movs r1, 0x8
	movs r2, 0x16
	movs r3, 0x4
	bl sub_802DA9C
	ldr r2, [r5]
	movs r4, 0
	movs r3, 0
	strh r0, [r2, 0x12]
	lsls r0, 24
	lsrs r0, 24
	adds r2, 0xA6
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x1
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x0000016f
	strh r0, [r1, 0x14]
	strb r4, [r1, 0xD]
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D7E8

	thumb_func_start sub_802D884
sub_802D884: @ 802D884
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_02022D00
	ldr r1, [r4]
	adds r1, 0x26
	bl CopyItemName
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r4]
	adds r1, 0x26
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r4]
	adds r0, 0xA6
	ldr r1, =gText_FilledStorageSpace2
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x4
	movs r1, 0x8
	movs r2, 0x16
	movs r3, 0x4
	bl sub_802DA9C
	ldr r2, [r4]
	movs r6, 0
	movs r5, 0
	strh r0, [r2, 0x12]
	lsls r0, 24
	lsrs r0, 24
	adds r2, 0xA6
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	strh r5, [r0, 0x14]
	strb r6, [r0, 0xD]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D884

	thumb_func_start sub_802D8FC
sub_802D8FC: @ 802D8FC
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_02022D00
	ldr r1, [r4]
	adds r1, 0x26
	bl CopyItemName
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r4]
	adds r1, 0x26
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r4]
	adds r0, 0xA6
	ldr r1, =gText_CantHoldMore
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x4
	movs r1, 0x9
	movs r2, 0x16
	movs r3, 0x2
	bl sub_802DA9C
	ldr r2, [r4]
	movs r6, 0
	movs r5, 0
	strh r0, [r2, 0x12]
	lsls r0, 24
	lsrs r0, 24
	adds r2, 0xA6
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	strh r5, [r0, 0x14]
	strb r6, [r0, 0xD]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D8FC

	thumb_func_start sub_802D974
sub_802D974: @ 802D974
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrb r0, [r0, 0xD]
	cmp r0, 0x1
	beq _0802D9C8
	cmp r0, 0x1
	bgt _0802D990
	cmp r0, 0
	beq _0802D99A
	b _0802DA0C
	.pool
_0802D990:
	cmp r0, 0x2
	beq _0802D9EE
	cmp r0, 0x3
	beq _0802DA02
	b _0802DA0C
_0802D99A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802DA0C
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl DrawTextBorderOuter
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r4]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
	b _0802DA0C
_0802D9C8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802DA0C
	ldr r1, [r4]
	ldrh r0, [r1, 0x14]
	cmp r0, 0
	bne _0802D9E0
	ldrb r0, [r1, 0xD]
	adds r0, 0x2
	b _0802DA00
_0802D9E0:
	ldrh r0, [r1, 0x14]
	bl PlayFanfare
	ldr r1, [r4]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
_0802D9EE:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _0802DA0C
	ldr r0, =gUnknown_02022D00
	ldr r1, [r0]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
_0802DA00:
	strb r0, [r1, 0xD]
_0802DA02:
	movs r0, 0
	b _0802DA0E
	.pool
_0802DA0C:
	movs r0, 0x1
_0802DA0E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802D974

	thumb_func_start sub_802DA14
sub_802DA14: @ 802DA14
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrh r0, [r0, 0x12]
	cmp r0, 0xFF
	beq _0802DA38
	lsls r0, 24
	lsrs r0, 24
	bl rbox_fill_rectangle
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	bl CopyWindowToVram
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0xD]
_0802DA38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DA14

	thumb_func_start sub_802DA44
sub_802DA44: @ 802DA44
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r1, [r4]
	ldrh r0, [r1, 0x12]
	cmp r0, 0xFF
	bne _0802DA58
_0802DA50:
	movs r0, 0
	b _0802DA84
	.pool
_0802DA58:
	ldrb r0, [r1, 0xD]
	cmp r0, 0
	bne _0802DA7E
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802DA82
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x12]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
	b _0802DA50
_0802DA7E:
	cmp r0, 0x1
	beq _0802DA50
_0802DA82:
	movs r0, 0x1
_0802DA84:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802DA44

	thumb_func_start sub_802DA8C
sub_802DA8C: @ 802DA8C
	push {lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_802DA8C

	thumb_func_start sub_802DA9C
sub_802DA9C: @ 802DA9C
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, =0xffffff00
	ldr r4, [sp]
	ands r4, r6
	lsls r0, 24
	lsrs r0, 16
	ldr r5, =0xffff00ff
	ands r4, r5
	orrs r4, r0
	lsls r1, 24
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r4, r0
	orrs r4, r1
	lsls r2, 24
	ldr r0, =0x00ffffff
	ands r4, r0
	orrs r4, r2
	str r4, [sp]
	lsls r3, 24
	lsrs r3, 24
	ldr r0, [sp, 0x4]
	ands r0, r6
	orrs r0, r3
	ands r0, r5
	movs r1, 0xF0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x86
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DA9C

	thumb_func_start sub_802DB18
sub_802DB18: @ 802DB18
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r2, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r5, =0xffffff00
	ldr r2, [sp]
	ands r2, r5
	lsls r0, 24
	lsrs r0, 16
	ldr r4, =0xffff00ff
	ands r2, r4
	orrs r2, r0
	lsls r1, 24
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r2, r0
	orrs r2, r1
	ldr r0, =0x00ffffff
	ands r2, r0
	movs r0, 0xC0
	lsls r0, 19
	orrs r2, r0
	str r2, [sp]
	ldr r0, [sp, 0x4]
	ands r0, r5
	movs r1, 0x4
	orrs r0, r1
	ands r0, r4
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xAC
	lsls r1, 14
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	movs r1, 0x1
	movs r2, 0xD
	bl CreateYesNoMenu
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DB18

	thumb_func_start sub_802DB8C
sub_802DB8C: @ 802DB8C
	push {r4,lr}
	sub sp, 0x10
	ldr r1, =gUnknown_082FE1DC
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	add r0, sp, 0xC
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r0, =gText_SpacePoints2
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add r0, sp, 0xC
	str r0, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gText_SpaceTimes3
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DB8C

	thumb_func_start sub_802DBF8
sub_802DBF8: @ 802DBF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	bl sub_802C8AC
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	ldr r1, =gUnknown_082FE260
	subs r0, 0x2
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r6, 0
	cmp r6, r10
	bge _0802DC62
	ldr r0, =gMonFrontPicCoords
	mov r9, r0
	ldr r1, =gUnknown_02022D00
	mov r8, r1
_0802DC26:
	lsls r4, r6, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_802C8C8
	adds r1, r0, 0
	ldrh r0, [r1]
	lsls r0, 2
	add r0, r9
	ldrb r3, [r0, 0x1]
	mov r2, r8
	ldr r0, [r2]
	movs r7, 0
	ldrsh r2, [r5, r7]
	adds r3, 0x70
	str r4, [sp]
	bl sub_802C9D4
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r2, 0x70
	adds r3, r4, 0
	bl sub_802CE48
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, r10
	blt _0802DC26
_0802DC62:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DBF8

	thumb_func_start sub_802DC80
sub_802DC80: @ 802DC80
	ldr r2, =gUnknown_02022D00
	ldr r2, [r2]
	lsls r0, 2
	ldr r3, =0x000081a8
	adds r2, r3
	adds r2, r0
	ldr r0, [r2]
	strh r1, [r0, 0x26]
	bx lr
	.pool
	thumb_func_end sub_802DC80

	thumb_func_start sub_802DC9C
sub_802DC9C: @ 802DC9C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	adds r1, r4, 0
	bl sub_802CF50
	ldr r0, =gUnknown_082FE1DF
	adds r4, r0
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 13
	movs r0, 0x2
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DC9C

	thumb_func_start sub_802DCCC
sub_802DCCC: @ 802DCCC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	movs r6, 0
_0802DCD6:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0802DCEA
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_802CB14
	adds r6, 0x1
_0802DCEA:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x4
	ble _0802DCD6
	subs r0, r6, 0x2
	lsls r0, 24
	lsrs r0, 24
	bl sub_802E00C
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DCCC

	thumb_func_start sub_802DD08
sub_802DD08: @ 802DD08
	push {r4,lr}
	sub sp, 0x10
	mov r1, sp
	movs r0, 0x40
	strb r0, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	movs r0, 0x6C
	strh r0, [r1, 0x4]
	movs r4, 0x6
	strh r4, [r1, 0x6]
	ldr r0, =gUnknown_082FE1EC
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_082FE1F4
	str r0, [sp, 0xC]
	movs r0, 0x2
	bl sub_8034C54
	movs r0, 0
	movs r1, 0
	mov r2, sp
	bl sub_8034D14
	mov r1, sp
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x1E
	strh r0, [r1, 0x4]
	mov r0, sp
	strh r4, [r0, 0x6]
	movs r0, 0x1
	movs r1, 0
	mov r2, sp
	bl sub_8034D14
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DD08

	thumb_func_start sub_802DD64
sub_802DD64: @ 802DD64
	push {lr}
	adds r1, r0, 0
	movs r0, 0
	bl sub_8035044
	pop {r0}
	bx r0
	thumb_func_end sub_802DD64

	thumb_func_start sub_802DD74
sub_802DD74: @ 802DD74
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1
	bl sub_8035044
	pop {r0}
	bx r0
	thumb_func_end sub_802DD74

	thumb_func_start sub_802DD88
sub_802DD88: @ 802DD88
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CBF0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DD88

	thumb_func_start sub_802DDA0
sub_802DDA0: @ 802DDA0
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CC88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDA0

	thumb_func_start sub_802DDB8
sub_802DDB8: @ 802DDB8
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CC18
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DDB8

	thumb_func_start sub_802DDCC
sub_802DDCC: @ 802DDCC
	push {lr}
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CCB0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDCC

	thumb_func_start sub_802DDE0
sub_802DDE0: @ 802DDE0
	push {lr}
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CD3C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDE0

	thumb_func_start sub_802DDF4
sub_802DDF4: @ 802DDF4
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CD70
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDF4

	thumb_func_start sub_802DE08
sub_802DE08: @ 802DE08
	push {lr}
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CD98
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DE08

	thumb_func_start sub_802DE1C
sub_802DE1C: @ 802DE1C
	push {r4-r7,lr}
	sub sp, 0x8
	bl sub_802C8AC
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r1, =gUnknown_082FE234
	subs r0, r7, 0x2
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	ldr r2, =0xffffff00
	ldr r0, [sp]
	ands r0, r2
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 20
	orrs r0, r1
	str r0, [sp]
	ldr r0, [sp, 0x4]
	ands r0, r2
	movs r1, 0x2
	orrs r0, r1
	ldr r1, =0xffff00ff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xAC
	lsls r1, 14
	orrs r0, r1
	str r0, [sp, 0x4]
	movs r5, 0
	cmp r5, r7
	bge _0802DEAC
	mov r6, sp
_0802DE6A:
	ldrb r0, [r4]
	lsls r0, 8
	ldr r2, =0xffff00ff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrb r2, [r4, 0x2]
	lsls r2, 16
	ldr r0, =0xff00ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	ldr r1, =gUnknown_02022D00
	ldr r1, [r1]
	lsls r2, r5, 1
	adds r1, 0x1C
	adds r1, r2
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl ClearWindowTilemap
	ldrh r0, [r6, 0x6]
	adds r0, 0x10
	strh r0, [r6, 0x6]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r7
	blt _0802DE6A
_0802DEAC:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DE1C

	thumb_func_start sub_802DED8
sub_802DED8: @ 802DED8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	adds r5, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	strb r1, [r0]
	strb r2, [r0, 0x1]
	strb r3, [r0, 0x2]
	ldr r6, =gUnknown_02022D00
	ldr r0, [r6]
	lsls r1, r5, 1
	mov r8, r1
	adds r0, 0x1C
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl sub_802C8E8
	adds r1, r0, 0
	movs r2, 0x1
	negs r2, r2
	mov r9, r2
	movs r0, 0x1
	bl GetStringWidth
	movs r4, 0x40
	subs r4, r0
	lsrs r4, 1
	adds r0, r5, 0
	bl sub_802C8E8
	adds r1, r0, 0
	ldr r0, [r6]
	adds r0, 0x1C
	add r0, r8
	ldrb r0, [r0]
	lsls r4, 24
	lsrs r4, 24
	add r2, sp, 0xC
	str r2, [sp]
	mov r2, r9
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldr r0, [r6]
	adds r0, 0x1C
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DED8

	thumb_func_start sub_802DF70
sub_802DF70: @ 802DF70
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_802C8AC
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r4, 0
	bne _0802DF9A
	movs r4, 0
	cmp r4, r5
	bge _0802DFCC
_0802DF86:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x3
	bl sub_802DED8
	adds r4, 0x1
	cmp r4, r5
	blt _0802DF86
	b _0802DFCC
_0802DF9A:
	bl sub_802C8BC
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
	cmp r4, r5
	bge _0802DFCC
_0802DFA8:
	cmp r6, r4
	beq _0802DFBA
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x3
	bl sub_802DED8
	b _0802DFC6
_0802DFBA:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x4
	movs r3, 0x5
	bl sub_802DED8
_0802DFC6:
	adds r4, 0x1
	cmp r4, r5
	blt _0802DFA8
_0802DFCC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802DF70

	thumb_func_start sub_802DFD4
sub_802DFD4: @ 802DFD4
	push {r4,r5,lr}
	bl sub_802C8AC
	lsls r0, 16
	lsrs r5, r0, 16
	movs r4, 0
	cmp r4, r5
	bge _0802DFFA
_0802DFE4:
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r4, 0x1
	cmp r4, r5
	blt _0802DFE4
_0802DFFA:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DFD4

	thumb_func_start sub_802E00C
sub_802E00C: @ 802E00C
	push {r4,lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_02022D00
	ldr r2, [r0]
	movs r0, 0
	str r0, [r2, 0x18]
	lsrs r1, 25
	lsls r1, 16
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	ands r4, r0
	lsls r4, 8
	subs r4, 0x28
	lsls r4, 8
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	ldr r0, =sub_802E090
	movs r1, 0x4
	bl CreateTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E00C

	thumb_func_start sub_802E058
sub_802E058: @ 802E058
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	cmp r0, 0x1F
	bls _0802E06C
	movs r0, 0
	b _0802E08A
	.pool
_0802E06C:
	movs r0, 0x1
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgY
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r0, 0x1
	str r0, [r1, 0x18]
	cmp r0, 0x1F
	bls _0802E088
	movs r0, 0x1
	bl HideBg
_0802E088:
	movs r0, 0x1
_0802E08A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802E058

	thumb_func_start sub_802E090
sub_802E090: @ 802E090
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_802E058
	cmp r0, 0
	bne _0802E0A4
	adds r0, r4, 0
	bl DestroyTask
_0802E0A4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E090

	thumb_func_start sub_802E0AC
sub_802E0AC: @ 802E0AC
	push {lr}
	sub sp, 0xC
	mov r2, sp
	movs r1, 0x1
	strb r1, [r2]
	ldrh r1, [r0]
	strh r1, [r2, 0x2]
	ldr r1, [r0, 0x4]
	str r1, [sp, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_802E0AC

	thumb_func_start sub_802E0D0
sub_802E0D0: @ 802E0D0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r1, 0
	ldr r3, =gRecvCmds
	lsls r2, r0, 4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r1, 0xBC
	lsls r1, 6
	cmp r0, r1
	bne _0802E100
	adds r1, r3, 0x2
	adds r1, r2, r1
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0802E108
_0802E100:
	movs r0, 0
	b _0802E118
	.pool
_0802E108:
	mov r0, sp
	ldrh r0, [r0, 0x2]
	strh r0, [r4]
	ldr r0, [sp, 0x8]
	str r0, [r4, 0x4]
	ldr r0, [sp, 0x4]
	str r0, [r4, 0x8]
	movs r0, 0x1
_0802E118:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802E0D0

	thumb_func_start sub_802E120
sub_802E120: @ 802E120
	push {lr}
	sub sp, 0xC
	mov r2, sp
	movs r1, 0x2
	strb r1, [r2]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_802E120

	thumb_func_start sub_802E138
sub_802E138: @ 802E138
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r3, sp
	movs r2, 0x3
	strb r2, [r3]
	ldr r3, [r1, 0x8]
	lsls r3, 15
	ldr r2, [sp, 0x8]
	ldr r4, =0x00007fff
	mov r8, r4
	ands r2, r4
	orrs r2, r3
	str r2, [sp, 0x8]
	mov r6, sp
	ldrb r2, [r1, 0x1]
	movs r5, 0x1F
	adds r3, r5, 0
	ands r3, r2
	ldrb r4, [r6, 0x3]
	movs r2, 0x20
	negs r2, r2
	ands r2, r4
	orrs r2, r3
	strb r2, [r6, 0x3]
	mov r3, sp
	ldrb r2, [r1]
	strb r2, [r3, 0x1]
	ldrh r2, [r1, 0x2]
	strh r2, [r3, 0x6]
	mov r4, sp
	ldrh r2, [r1, 0x4]
	mov r1, r8
	ands r2, r1
	ldrh r3, [r4, 0x8]
	ldr r1, =0xffff8000
	ands r1, r3
	orrs r1, r2
	strh r1, [r4, 0x8]
	mov r2, sp
	ldrh r1, [r0, 0x10]
	strb r1, [r2, 0x2]
	mov r3, sp
	ldr r1, [r0, 0x14]
	lsls r1, 5
	ldrb r2, [r3, 0x3]
	ands r5, r2
	orrs r5, r1
	strb r5, [r3, 0x3]
	mov r1, sp
	ldrh r0, [r0, 0xE]
	strh r0, [r1, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E138

	thumb_func_start sub_802E1BC
sub_802E1BC: @ 802E1BC
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r2, =gRecvCmds
	ldrh r0, [r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _0802E228
	adds r1, r2, 0x2
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0802E228
	ldr r0, [sp, 0x8]
	lsrs r0, 15
	str r0, [r4, 0x8]
	mov r0, sp
	ldrb r1, [r0, 0x3]
	lsls r0, r1, 27
	lsrs r0, 27
	strb r0, [r4, 0x1]
	mov r0, sp
	ldrb r0, [r0, 0x1]
	strb r0, [r4]
	mov r0, sp
	ldrh r0, [r0, 0x6]
	strh r0, [r4, 0x2]
	mov r0, sp
	ldrh r0, [r0, 0x8]
	lsls r0, 17
	lsrs r0, 17
	strh r0, [r4, 0x4]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	strh r0, [r5, 0x10]
	lsls r1, 24
	lsrs r1, 29
	str r1, [r5, 0x14]
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0xE]
	movs r0, 0x1
	b _0802E22A
	.pool
_0802E228:
	movs r0, 0
_0802E22A:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802E1BC

	thumb_func_start sub_802E234
sub_802E234: @ 802E234
	push {r4,lr}
	sub sp, 0xC
	mov r4, sp
	movs r3, 0x4
	strb r3, [r4]
	ldrh r3, [r0, 0x10]
	strb r3, [r4, 0x1]
	ldr r3, [r0, 0x14]
	strb r3, [r4, 0x2]
	ldr r3, [r0, 0x18]
	strb r3, [r4, 0x3]
	mov r3, sp
	ldrh r0, [r0, 0xE]
	strh r0, [r3, 0x4]
	mov r0, sp
	strb r1, [r0, 0x6]
	strh r2, [r0, 0x8]
	bl sub_800FE50
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E234

	thumb_func_start sub_802E264
sub_802E264: @ 802E264
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r3, =gRecvCmds
	lsls r2, r1, 4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r1, 0xBC
	lsls r1, 6
	cmp r0, r1
	bne _0802E2C4
	adds r1, r3, 0x2
	adds r1, r2, r1
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0802E2C4
	mov r0, sp
	ldrb r0, [r0, 0x1]
	strh r0, [r4, 0x10]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	str r0, [r4, 0x14]
	mov r0, sp
	ldrb r0, [r0, 0x3]
	str r0, [r4, 0x18]
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0xE]
	mov r0, sp
	ldrb r0, [r0, 0x6]
	strb r0, [r5]
	mov r0, sp
	ldrh r0, [r0, 0x8]
	strh r0, [r6]
	movs r0, 0x1
	b _0802E2C6
	.pool
_0802E2C4:
	movs r0, 0
_0802E2C6:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_802E264

	thumb_func_start sub_802E2D0
sub_802E2D0: @ 802E2D0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r3, =gRecvCmds
	lsls r2, r1, 4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r1, 0xBC
	lsls r1, 6
	cmp r0, r1
	bne _0802E320
	adds r1, r3, 0x2
	adds r1, r2, r1
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0802E320
	mov r0, sp
	ldrb r0, [r0, 0x1]
	strh r0, [r4, 0x10]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	str r0, [r4, 0x14]
	mov r0, sp
	ldrb r0, [r0, 0x3]
	str r0, [r4, 0x18]
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0xE]
	movs r0, 0x1
	b _0802E322
	.pool
_0802E320:
	movs r0, 0
_0802E322:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802E2D0

	thumb_func_start sub_802E32C
sub_802E32C: @ 802E32C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_802E32C

	thumb_func_start ResetPokeJumpResults
ResetPokeJumpResults: @ 802E33C
	push {lr}
	bl sub_802E32C
	movs r1, 0
	strh r1, [r0]
	str r1, [r0, 0xC]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	str r1, [r0, 0x8]
	strh r1, [r0, 0x2]
	pop {r0}
	bx r0
	thumb_func_end ResetPokeJumpResults

	thumb_func_start sub_802E354
sub_802E354: @ 802E354
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	bl sub_802E32C
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r1, 0xC]
	cmp r0, r4
	bcs _0802E378
	ldr r0, =0x00018696
	cmp r4, r0
	bhi _0802E378
	str r4, [r1, 0xC]
	movs r2, 0x1
_0802E378:
	ldrh r0, [r1]
	cmp r0, r5
	bcs _0802E388
	ldr r0, =0x0000270f
	cmp r5, r0
	bhi _0802E388
	strh r5, [r1]
	movs r2, 0x1
_0802E388:
	ldrh r0, [r1, 0x4]
	cmp r0, r6
	bcs _0802E398
	ldr r0, =0x0000270f
	cmp r6, r0
	bhi _0802E398
	strh r6, [r1, 0x4]
	movs r2, 0x1
_0802E398:
	adds r0, r2, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802E354

	thumb_func_start sub_802E3A8
sub_802E3A8: @ 802E3A8
	push {lr}
	bl sub_802E32C
	adds r2, r0, 0
	ldrh r1, [r2, 0x6]
	ldr r0, =0x0000270e
	cmp r1, r0
	bhi _0802E3BC
	adds r0, r1, 0x1
	strh r0, [r2, 0x6]
_0802E3BC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E3A8

	thumb_func_start sub_802E3C4
sub_802E3C4: @ 802E3C4
	push {r4,lr}
	ldr r4, =sub_802E3E4
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E3C4

	thumb_func_start sub_802E3E4
sub_802E3E4: @ 802E3E4
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	beq _0802E4A8
	cmp r0, 0x1
	bgt _0802E40C
	cmp r0, 0
	beq _0802E416
	b _0802E4F6
	.pool
_0802E40C:
	cmp r0, 0x2
	beq _0802E4B4
	cmp r0, 0x3
	beq _0802E4DC
	b _0802E4F6
_0802E416:
	ldr r0, =gUnknown_082FE270
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gText_PkmnJumpRecords
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	movs r6, 0
	ldr r5, =gUnknown_082FE278
_0802E430:
	ldr r1, [r5]
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r0, 0x26
	cmp r0, r4
	ble _0802E442
	adds r4, r0, 0
_0802E442:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x2
	bls _0802E430
	adds r0, r4, 0x7
	cmp r0, 0
	bge _0802E452
	adds r0, 0x7
_0802E452:
	asrs r4, r0, 3
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0802E45E
	adds r4, 0x1
_0802E45E:
	movs r1, 0x1E
	subs r1, r4
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r4, 24
	ldr r1, =0x00ffffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r7, 0x2]
	ldrh r0, [r7, 0x2]
	adds r1, r4, 0
	bl sub_802E500
	ldrb r0, [r7, 0x2]
	movs r1, 0x3
	b _0802E4CA
	.pool
_0802E4A8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802E4F6
	b _0802E4CE
_0802E4B4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0802E4F6
	ldrb r0, [r7, 0x2]
	bl rbox_fill_rectangle
	ldrb r0, [r7, 0x2]
	movs r1, 0x1
_0802E4CA:
	bl CopyWindowToVram
_0802E4CE:
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	b _0802E4F6
	.pool
_0802E4DC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802E4F6
	ldrb r0, [r7, 0x2]
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_0802E4F6:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802E3E4

	thumb_func_start sub_802E500
sub_802E500: @ 802E500
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x1C]
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
	bl sub_802E32C
	ldrh r1, [r0]
	str r1, [sp, 0xC]
	ldr r1, [r0, 0xC]
	str r1, [sp, 0x10]
	ldrh r0, [r0, 0x4]
	str r0, [sp, 0x14]
	ldr r0, [sp, 0x18]
	lsls r4, r0, 24
	lsrs r4, 24
	ldr r5, =0x0000021d
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD
	bl DrawTextBorderOuter
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_PkmnJumpRecords
	ldr r1, [sp, 0x1C]
	lsls r2, r1, 3
	movs r0, 0x1
	adds r1, r5, 0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r6, 0
	adds r7, r4, 0
	movs r0, 0xFF
	mov r10, r0
	mov r9, r6
	mov r1, sp
	adds r1, 0xC
	str r1, [sp, 0x20]
	movs r0, 0xC8
	lsls r0, 21
	mov r8, r0
	ldr r5, =gStringVar1
_0802E58A:
	ldr r1, =gUnknown_082FE278
	lsls r0, r6, 2
	adds r0, r1
	ldr r2, [r0]
	mov r1, r8
	lsrs r4, r1, 24
	str r4, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [sp, 0x20]
	ldm r0!, {r1}
	str r0, [sp, 0x20]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0
	bl sub_802E620
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	ldr r1, [sp, 0x1C]
	lsls r3, r1, 3
	subs r3, r0
	lsls r3, 24
	lsrs r3, 24
	str r4, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x80
	lsls r0, 21
	add r8, r0
	adds r6, 0x1
	ldr r1, [sp, 0x18]
	lsls r0, r1, 24
	cmp r6, 0x2
	bls _0802E58A
	lsrs r0, 24
	bl PutWindowTilemap
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E500

	thumb_func_start sub_802E620
sub_802E620: @ 802E620
	push {lr}
	adds r1, r0, 0
	b _0802E628
_0802E626:
	adds r1, 0x1
_0802E628:
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0802E636
	cmp r0, 0
	bne _0802E626
	movs r0, 0xFF
	strb r0, [r1]
_0802E636:
	pop {r0}
	bx r0
	thumb_func_end sub_802E620

	thumb_func_start sub_802E63C
sub_802E63C: @ 802E63C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =sub_802E6D0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	strh r5, [r0, 0xA]
	ldr r0, =gUnknown_082FE748
	lsls r5, 4
	adds r5, r0
	ldr r1, [r5]
	adds r0, r4, 0
	bl _call_via_r1
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802E63C

	thumb_func_start sub_802E688
sub_802E688: @ 802E688
	push {lr}
	ldr r0, =sub_802E6D0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _0802E6B4
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	strh r0, [r1, 0x8]
	movs r0, 0x1
	b _0802E6B6
	.pool
_0802E6B4:
	movs r0, 0
_0802E6B6:
	pop {r1}
	bx r1
	thumb_func_end sub_802E688

	thumb_func_start sub_802E6BC
sub_802E6BC: @ 802E6BC
	push {lr}
	ldr r0, =sub_802E6D0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802E6BC

	thumb_func_start sub_802E6D0
sub_802E6D0: @ 802E6D0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _0802E71C
	cmp r0, 0x3
	bgt _0802E6F8
	cmp r0, 0x2
	beq _0802E6FE
	b _0802E752
	.pool
_0802E6F8:
	cmp r0, 0x4
	beq _0802E738
	b _0802E752
_0802E6FE:
	ldr r1, =gUnknown_082FE748
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r1, 0x8
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
	movs r0, 0x3
	strh r0, [r4]
	b _0802E752
	.pool
_0802E71C:
	ldr r0, =gUnknown_082FE748
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 4
	adds r0, 0xC
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl _call_via_r1
	b _0802E752
	.pool
_0802E738:
	ldr r0, =gUnknown_082FE748
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 4
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl _call_via_r1
	adds r0, r5, 0
	bl DestroyTask
_0802E752:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E6D0

	thumb_func_start sub_802E75C
sub_802E75C: @ 802E75C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	lsls r0, 3
	ldr r1, =gUnknown_082FE6C8
	adds r0, r1
	bl LoadCompressedSpriteSheet
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r0, 3
	ldr r1, =gUnknown_082FE6D8
	adds r0, r1
	bl LoadSpritePalette
	movs r5, 0
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r5, r0
	bge _0802E7C4
_0802E790:
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	ldr r1, =gUnknown_082FE730
	adds r0, r1
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	movs r3, 0x14
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0xE]
	bl CreateSprite
	lsls r1, r5, 1
	adds r1, r4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x1A]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E790
_0802E7C4:
	movs r5, 0
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r5, r0
	bge _0802E820
	movs r7, 0x3
	movs r3, 0xD
	negs r3, r3
	mov r12, r3
	ldr r6, =gSprites
_0802E7D8:
	lsls r0, r5, 1
	adds r0, r4
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrb r1, [r4, 0xC]
	ands r1, r7
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	mov r0, r12
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4, 0xA]
	strh r0, [r2, 0x30]
	mov r3, r8
	strh r3, [r2, 0x34]
	strh r5, [r2, 0x36]
	ldrh r0, [r4, 0x1A]
	strh r0, [r2, 0x38]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E7D8
_0802E820:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E75C

	thumb_func_start sub_802E83C
sub_802E83C: @ 802E83C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r1, =gTasks + 0x8
	adds r4, r1
	movs r5, 0
	strh r5, [r4, 0x4]
	strh r5, [r4, 0x6]
	strh r5, [r4, 0x8]
	movs r1, 0x3C
	strh r1, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	movs r1, 0x3
	strh r1, [r4, 0x10]
	movs r1, 0x78
	strh r1, [r4, 0x12]
	movs r1, 0x58
	strh r1, [r4, 0x14]
	adds r1, r4, 0
	bl sub_802E75C
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x4
	bl StartSpriteAnim
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x24]
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x5
	bl StartSpriteAnim
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x20
	strh r1, [r0, 0x24]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E83C

	thumb_func_start sub_802E8C8
sub_802E8C8: @ 802E8C8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	b _0802E8FC
	.pool
_0802E8E0:
	lsls r0, r5, 1
	adds r0, r4
	movs r2, 0x1A
	ldrsh r1, [r0, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0802E8FC:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E8E0
	ldr r1, =gUnknown_082FE6C8
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x6]
	bl FreeSpriteTilesByTag
	ldr r1, =gUnknown_082FE6D8
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E8C8

	thumb_func_start sub_802E938
sub_802E938: @ 802E938
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0x34
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	movs r2, 0xA
	ldrsh r1, [r5, r2]
	bl __modsi3
	cmp r0, 0
	bne _0802EA4A
	ldrh r2, [r5, 0x16]
	movs r3, 0x16
	ldrsh r1, [r5, r3]
	movs r3, 0x14
	ldrsh r0, [r5, r3]
	cmp r1, r0
	beq _0802EA4A
	strh r2, [r5, 0x14]
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x4
	bhi _0802EA44
	lsls r0, 2
	ldr r1, =_0802E984
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802E984:
	.4byte _0802E998
	.4byte _0802E9A6
	.4byte _0802E9A6
	.4byte _0802E9BA
	.4byte _0802EA04
_0802E998:
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0802E9A6:
	movs r0, 0x38
	bl PlaySE
	ldrh r1, [r6, 0x32]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl StartSpriteAnim
	b _0802EA44
_0802E9BA:
	movs r0, 0x15
	bl PlaySE
	ldrh r1, [r6, 0x32]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl StartSpriteAnim
	ldr r4, =gSprites
	movs r2, 0x1C
	ldrsh r0, [r5, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r3, 0x1E
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	b _0802EA44
	.pool
_0802EA04:
	adds r1, r6, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r3, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x1E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x4
	strh r0, [r5]
	b _0802EA4A
	.pool
_0802EA44:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
_0802EA4A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802E938

	thumb_func_start sub_802EA50
sub_802EA50: @ 802EA50
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	movs r0, 0x38
	bl PlaySE
	ldr r2, =gSprites
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_802E938
	str r1, [r0]
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
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
	subs r5, 0x8
	adds r4, r5
	movs r0, 0x3
	strh r0, [r4, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EA50

	thumb_func_start sub_802EAB0
sub_802EAB0: @ 802EAB0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802EB14
	ldr r1, =gRecvCmds
	ldrh r0, [r1, 0x2]
	ldr r5, =0x00007fff
	cmp r0, r5
	bne _0802EAD8
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x16]
_0802EAD8:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0802EB1A
	ldrh r0, [r4, 0x18]
	adds r0, 0x1
	strh r0, [r4, 0x18]
	mov r0, sp
	movs r1, 0
	movs r2, 0xC
	bl memset
	mov r0, sp
	strh r5, [r0]
	mov r1, sp
	ldrh r0, [r4, 0x18]
	strh r0, [r1, 0x2]
	mov r0, sp
	bl sub_800FE50
	b _0802EB1A
	.pool
_0802EB14:
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
_0802EB1A:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802EAB0

	thumb_func_start sub_802EB24
sub_802EB24: @ 802EB24
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, [sp, 0x18]
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =sub_802EB98
	movs r1, 0x50
	str r3, [sp]
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r6, [r1, 0x10]
	ldr r3, [sp]
	strh r3, [r1, 0x12]
	mov r0, r8
	strh r0, [r1, 0x14]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EB24

	thumb_func_start sub_802EB84
sub_802EB84: @ 802EB84
	push {lr}
	ldr r0, =sub_802EB98
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802EB84

	thumb_func_start sub_802EB98
sub_802EB98: @ 802EB98
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0802EC08
	cmp r0, 0x1
	bgt _0802EBC0
	cmp r0, 0
	beq _0802EBC6
	b _0802EC8A
	.pool
_0802EBC0:
	cmp r0, 0x2
	beq _0802EC4C
	b _0802EC8A
_0802EBC6:
	ldrh r0, [r5, 0x4]
	ldrh r1, [r5, 0x6]
	bl sub_802EF50
	ldrh r0, [r5, 0x4]
	ldrh r1, [r5, 0x6]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0xA
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, 0xC]
	str r4, [sp]
	bl sub_802EFA8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r5, 0x6]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0xA
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, 0xC]
	str r4, [sp]
	adds r4, r5, 0
	adds r4, 0x10
	str r4, [sp, 0x4]
	adds r4, 0x2
	str r4, [sp, 0x8]
	bl sub_802EFFC
	b _0802EC3E
_0802EC08:
	ldrb r0, [r5, 0xE]
	bl sub_802EC98
	cmp r0, 0
	bne _0802EC8A
	ldrb r0, [r5, 0xE]
	ldrb r1, [r5, 0x10]
	ldrb r2, [r5, 0x12]
	bl sub_802EDCC
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	movs r3, 0xE
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_0802EC3E:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _0802EC8A
	.pool
_0802EC4C:
	ldrb r0, [r5, 0x10]
	bl sub_802EE30
	cmp r0, 0
	bne _0802EC8A
	movs r4, 0x10
	ldrsh r1, [r5, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r0, 0x12
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldrh r0, [r5, 0x4]
	bl FreeSpriteTilesByTag
	ldrh r0, [r5, 0x6]
	bl FreeSpritePaletteByTag
	adds r0, r6, 0
	bl DestroyTask
_0802EC8A:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EB98

	thumb_func_start sub_802EC98
sub_802EC98: @ 802EC98
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r4, r1, r0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bls _0802ECB2
	b _0802EDC4
_0802ECB2:
	lsls r0, 2
	ldr r1, =_0802ECC4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802ECC4:
	.4byte _0802ECE4
	.4byte _0802ECF6
	.4byte _0802ED1C
	.4byte _0802ED2C
	.4byte _0802ED4E
	.4byte _0802ED86
	.4byte _0802EDAC
	.4byte _0802ED82
_0802ECE4:
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0x1A
	bl sub_8007E18
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0802ECF6:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0802ED04
	movs r0, 0x39
	bl PlaySE
_0802ED04:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0802EDC4
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	movs r1, 0x1
	b _0802EDA2
_0802ED1C:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0802EDC4
	b _0802EDA6
_0802ED2C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0802EDC4
	movs r0, 0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	b _0802EDC4
_0802ED4E:
	ldrh r0, [r4, 0x22]
	subs r0, 0x4
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0802EDC4
	ldrh r1, [r4, 0x36]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bgt _0802ED7E
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0
	strh r0, [r4, 0x32]
	b _0802EDA6
_0802ED7E:
	movs r0, 0x7
	strh r0, [r4, 0x2E]
_0802ED82:
	movs r0, 0
	b _0802EDC6
_0802ED86:
	ldrh r0, [r4, 0x22]
	adds r0, 0x4
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0802EDC4
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	movs r1, 0x3
_0802EDA2:
	bl StartSpriteAffineAnim
_0802EDA6:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	b _0802EDC2
_0802EDAC:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0802EDC4
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	movs r0, 0x1
_0802EDC2:
	strh r0, [r4, 0x2E]
_0802EDC4:
	movs r0, 0x1
_0802EDC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802EC98

	thumb_func_start sub_802EDCC
sub_802EDCC: @ 802EDCC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gSprites
	mov r8, r0
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r5, r4, r0
	ldr r0, =0x0000ffd8
	strh r0, [r5, 0x26]
	lsls r3, r2, 4
	adds r3, r2
	lsls r3, 2
	mov r1, r8
	adds r2, r3, r1
	strh r0, [r2, 0x26]
	adds r5, 0x3E
	ldrb r6, [r5]
	movs r1, 0x5
	negs r1, r1
	adds r0, r1, 0
	ands r0, r6
	strb r0, [r5]
	adds r2, 0x3E
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	movs r0, 0x1C
	add r8, r0
	add r4, r8
	ldr r0, =sub_802EE5C
	str r0, [r4]
	add r3, r8
	str r0, [r3]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EDCC

	thumb_func_start sub_802EE30
sub_802EE30: @ 802EE30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r2, 0x1C
	adds r1, r2
	ldr r1, [r1]
	ldr r0, =sub_802EE5C
	cmp r1, r0
	bne _0802EE4E
	movs r3, 0x1
_0802EE4E:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802EE30

	thumb_func_start sub_802EE5C
sub_802EE5C: @ 802EE5C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bhi _0802EF46
	lsls r0, 2
	ldr r1, =_0802EE7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802EE7C:
	.4byte _0802EE90
	.4byte _0802EEA0
	.4byte _0802EEC8
	.4byte _0802EEFC
	.4byte _0802EF34
_0802EE90:
	movs r0, 0x40
	strh r0, [r4, 0x8]
	ldrh r0, [r5, 0x26]
	lsls r0, 4
	strh r0, [r4, 0xA]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_0802EEA0:
	ldrh r1, [r4, 0x8]
	ldrh r2, [r4, 0xA]
	adds r0, r1, r2
	strh r0, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r5, 0x26]
	cmp r0, 0
	blt _0802EF46
	movs r0, 0x39
	bl PlaySE
	movs r0, 0
	strh r0, [r5, 0x26]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0802EF46
_0802EEC8:
	ldrh r0, [r4, 0x2]
	adds r0, 0xC
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0802EEE6
	movs r0, 0x39
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_0802EEE6:
	ldr r0, =gSineTable
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	asrs r0, 4
	b _0802EF2A
	.pool
_0802EEFC:
	ldrh r0, [r4, 0x2]
	adds r0, 0x10
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0802EF1A
	movs r0, 0x39
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_0802EF1A:
	ldr r1, =gSineTable
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
_0802EF2A:
	negs r0, r0
	strh r0, [r5, 0x26]
	b _0802EF46
	.pool
_0802EF34:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0802EF46
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
_0802EF46:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EE5C

	thumb_func_start sub_802EF50
sub_802EF50: @ 802EF50
	push {r4,lr}
	sub sp, 0x10
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_082FEBCC
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r2, [sp]
	str r3, [sp, 0x4]
	ldr r2, =gUnknown_082FEBD4
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	lsls r0, 16
	ldr r3, =0x0000ffff
	ldr r2, [sp, 0x4]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, 0x4]
	ldr r2, =0xffff0000
	add r4, sp, 0x8
	ldr r0, [r4, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [r4, 0x4]
	mov r0, sp
	bl LoadCompressedSpriteSheet
	adds r0, r4, 0
	bl LoadSpritePalette
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EF50

	thumb_func_start sub_802EFA8
sub_802EFA8: @ 802EFA8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r12, r3
	ldr r3, [sp, 0x30]
	lsls r1, 16
	lsrs r1, 16
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	mov r5, sp
	ldr r4, =gUnknown_082FEC90
	ldm r4!, {r3,r6,r7}
	stm r5!, {r3,r6,r7}
	ldm r4!, {r3,r6,r7}
	stm r5!, {r3,r6,r7}
	mov r4, sp
	strh r0, [r4]
	mov r0, sp
	strh r1, [r0, 0x2]
	lsls r2, 16
	asrs r2, 16
	mov r0, r12
	lsls r6, r0, 16
	asrs r6, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r6, 0
	mov r3, r8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802EFA8

	thumb_func_start sub_802EFFC
sub_802EFFC: @ 802EFFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r12, r3
	ldr r6, [sp, 0x38]
	ldr r3, [sp, 0x3C]
	mov r9, r3
	ldr r4, [sp, 0x40]
	mov r8, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r6, 24
	lsrs r6, 24
	mov r10, r6
	mov r4, sp
	ldr r3, =gUnknown_082FECA8
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	mov r3, sp
	strh r0, [r3]
	mov r0, sp
	strh r1, [r0, 0x2]
	lsls r2, 16
	asrs r4, r2, 16
	ldr r0, =0xffe00000
	adds r2, r0
	asrs r2, 16
	mov r1, r12
	lsls r5, r1, 16
	asrs r5, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r5, 0
	mov r3, r10
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r3, r9
	strh r0, [r3]
	adds r4, 0x20
	lsls r4, 16
	asrs r4, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r4, r8
	strh r0, [r4]
	ldr r2, =gSprites
	mov r5, r9
	movs r6, 0
	ldrsh r1, [r5, r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r0]
	movs r7, 0
	ldrsh r1, [r4, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	bl StartSpriteAnim
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EFFC

	.align 2, 0 @ don't pad with nop
