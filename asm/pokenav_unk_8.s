	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(7)

    thumb_func_start sub_81CEF3C
sub_81CEF3C: @ 81CEF3C
	push {r4,lr}
	movs r0, 0x7
	movs r1, 0x24
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CEF90
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl AllocSubstruct
	str r0, [r4, 0x20]
	cmp r0, 0
	beq _081CEF90
	ldr r0, =sub_81CF010
	str r0, [r4]
	ldr r0, =sub_81CF11C
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	movs r0, 0
	str r0, [r4, 0x18]
	bl sub_81C76AC
	ldr r1, =gUnknown_086233A0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CEF92
	.pool
_081CEF90:
	movs r0, 0
_081CEF92:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CEF3C

	thumb_func_start sub_81CEF98
sub_81CEF98: @ 81CEF98
	push {r4,lr}
	movs r0, 0x7
	movs r1, 0x24
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CEFD4
	movs r0, 0x12
	bl GetSubstructPtr
	str r0, [r4, 0x20]
	ldr r0, =sub_81CF030
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0x18]
	bl sub_81C76AC
	ldr r1, =gUnknown_086233A0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CEFD6
	.pool
_081CEFD4:
	movs r0, 0
_081CEFD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CEF98

	thumb_func_start sub_81CEFDC
sub_81CEFDC: @ 81CEFDC
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CEFDC

	thumb_func_start sub_81CEFF0
sub_81CEFF0: @ 81CEFF0
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	ldr r0, [r0, 0x1C]
	cmp r0, 0
	bne _081CF004
	movs r0, 0x12
	bl FreePokenavSubstruct
_081CF004:
	movs r0, 0x7
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_81CEFF0

	thumb_func_start sub_81CF010
sub_81CF010: @ 81CF010
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4]
	bl IsLoopedTaskActive
	cmp r0, 0
	bne _081CF022
	ldr r0, =sub_81CF030
	str r0, [r4]
_081CF022:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF010

	thumb_func_start sub_81CF030
sub_81CF030: @ 81CF030
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CF048
	movs r0, 0x1
	b _081CF0A6
	.pool
_081CF048:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CF054
	movs r0, 0x2
	b _081CF0A6
_081CF054:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CF062
	movs r0, 0x3
	b _081CF0A6
_081CF062:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CF072
	movs r0, 0x4
	b _081CF0A6
_081CF072:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CF088
	str r2, [r4, 0x1C]
	ldr r0, =sub_81CF0B0
	str r0, [r4]
	movs r0, 0x5
	b _081CF0A6
	.pool
_081CF088:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081CF096
	movs r0, 0
	b _081CF0A6
_081CF096:
	bl GetSelectedMatchCall
	ldr r1, [r4, 0x20]
	strh r0, [r1, 0x2]
	str r5, [r4, 0x1C]
	ldr r0, =sub_81CF0B8
	str r0, [r4]
	movs r0, 0x6
_081CF0A6:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF030

	thumb_func_start sub_81CF0B0
sub_81CF0B0: @ 81CF0B0
	ldr r0, =0x000186a3
	bx lr
	.pool
	thumb_func_end sub_81CF0B0

	thumb_func_start sub_81CF0B8
sub_81CF0B8: @ 81CF0B8
	ldr r0, =0x000186a9
	bx lr
	.pool
	thumb_func_end sub_81CF0B8

	thumb_func_start sub_81CF0C0
sub_81CF0C0: @ 81CF0C0
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	ldr r0, [r0, 0x18]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0C0

	thumb_func_start sub_81CF0D0
sub_81CF0D0: @ 81CF0D0
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	ldr r0, [r0, 0x20]
	adds r0, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0D0

	thumb_func_start sub_81CF0E0
sub_81CF0E0: @ 81CF0E0
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	ldr r0, [r0, 0x20]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0E0

	thumb_func_start sub_81CF0F0
sub_81CF0F0: @ 81CF0F0
	push {r4,lr}
	movs r0, 0x7
	bl GetSubstructPtr
	adds r4, r0, 0
	bl GetSelectedMatchCall
	ldr r1, [r4, 0x20]
	lsls r0, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0F0

	thumb_func_start sub_81CF10C
sub_81CF10C: @ 81CF10C
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	ldr r0, [r0, 0x20]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF10C

	thumb_func_start sub_81CF11C
sub_81CF11C: @ 81CF11C
	push {lr}
	ldr r2, =gUnknown_086233B4
	lsls r1, r0, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF11C

	thumb_func_start sub_81CF134
sub_81CF134: @ 81CF134
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x7
	bl GetSubstructPtr
	adds r6, r0, 0
	ldr r0, [r6, 0x20]
	movs r1, 0
	strh r1, [r0]
	ldr r0, [r6, 0x20]
	strh r1, [r0, 0x2]
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xE
	orrs r0, r1
	str r0, [sp]
	movs r5, 0
_081CF158:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CF1AA
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CF1A4
	lsls r1, r5, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r6, 0x14]
	adds r0, r4, 0
	bl GetMonData
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CF2C4
_081CF1A4:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CF158
_081CF1AA:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF134

	thumb_func_start sub_81CF1C4
sub_81CF1C4: @ 81CF1C4
	push {lr}
	movs r0, 0x7
	bl GetSubstructPtr
	movs r1, 0
	str r1, [r0, 0x10]
	str r1, [r0, 0xC]
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81CF1C4

	thumb_func_start sub_81CF1D8
sub_81CF1D8: @ 81CF1D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r0, 0x7
	bl GetSubstructPtr
	adds r6, r0, 0
	ldr r5, [r6, 0xC]
	ldr r4, [r6, 0x10]
	movs r0, 0
	mov r8, r0
	cmp r5, 0xD
	bgt _081CF268
_081CF1F4:
	cmp r4, 0x1D
	bgt _081CF260
	lsls r0, r5, 24
	lsrs r7, r0, 24
_081CF1FC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081CF23A
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r7
	lsls r1, r4, 24
	lsrs r1, 24
	lsls r3, r1, 8
	ldr r2, =0xffff00ff
	ands r0, r2
	orrs r0, r3
	str r0, [sp]
	ldr r2, [r6, 0x14]
	adds r0, r7, 0
	bl GetBoxMonDataAt
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CF2C4
_081CF23A:
	movs r0, 0x1
	add r8, r0
	adds r4, 0x1
	mov r0, r8
	cmp r0, 0xE
	ble _081CF25C
	str r5, [r6, 0xC]
	str r4, [r6, 0x10]
	movs r0, 0x3
	b _081CF26A
	.pool
_081CF25C:
	cmp r4, 0x1D
	ble _081CF1FC
_081CF260:
	movs r4, 0
	adds r5, 0x1
	cmp r5, 0xD
	ble _081CF1F4
_081CF268:
	movs r0, 0x1
_081CF26A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF1D8

	thumb_func_start sub_81CF278
sub_81CF278: @ 81CF278
	push {r4-r6,lr}
	movs r0, 0x7
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, [r5, 0x20]
	ldrh r6, [r0]
	ldrh r4, [r0, 0x6]
	movs r1, 0x1
	strh r1, [r0, 0x6]
	movs r3, 0x1
	cmp r3, r6
	bge _081CF2B8
_081CF292:
	ldr r2, [r5, 0x20]
	lsls r0, r3, 2
	adds r1, r2, r0
	ldrh r0, [r1, 0x6]
	cmp r0, r4
	bne _081CF2AC
	subs r0, r3, 0x1
	lsls r0, 2
	adds r0, r2, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r1, 0x6]
	adds r0, r3, 0x1
	b _081CF2B2
_081CF2AC:
	adds r4, r0, 0
	adds r0, r3, 0x1
	strh r0, [r1, 0x6]
_081CF2B2:
	adds r3, r0, 0
	cmp r3, r6
	blt _081CF292
_081CF2B8:
	movs r0, 0x1
	str r0, [r5, 0x18]
	movs r0, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF278

	thumb_func_start sub_81CF2C4
sub_81CF2C4: @ 81CF2C4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldr r0, [r5, 0x20]
	ldrh r2, [r0]
	lsrs r3, r2, 1
	cmp r2, r3
	beq _081CF2F4
	adds r6, r0, 0
	ldrh r4, [r7, 0x2]
_081CF2DA:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x6]
	cmp r4, r0
	bls _081CF2E8
	adds r2, r3, 0
	b _081CF2EA
_081CF2E8:
	adds r1, r3, 0x1
_081CF2EA:
	subs r0, r2, r1
	lsrs r0, 1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CF2DA
_081CF2F4:
	ldr r0, [r5, 0x20]
	ldrh r2, [r0]
	lsls r6, r3, 2
	cmp r2, r3
	bls _081CF318
	lsls r0, r2, 2
	subs r4, r0, 0x4
_081CF302:
	ldr r0, [r5, 0x20]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, 0x4
	subs r2, 0x1
	cmp r2, r3
	bhi _081CF302
_081CF318:
	ldr r0, [r5, 0x20]
	adds r0, 0x4
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, 0x20]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CF2C4

	thumb_func_start sub_81CF330
sub_81CF330: @ 81CF330
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0x8
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF360
	ldr r0, =sub_81CF418
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r4]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081CF362
	.pool
_081CF360:
	movs r0, 0
_081CF362:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF330

	thumb_func_start sub_81CF368
sub_81CF368: @ 81CF368
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0x8
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF398
	ldr r0, =sub_81CF418
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0xC]
	b _081CF39A
	.pool
_081CF398:
	movs r0, 0
_081CF39A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF368

	thumb_func_start sub_81CF3A0
sub_81CF3A0: @ 81CF3A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, =gUnknown_08623598
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r5, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF3A0

	thumb_func_start sub_81CF3D0
sub_81CF3D0: @ 81CF3D0
	push {lr}
	movs r0, 0x8
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CF3D0

	thumb_func_start sub_81CF3E4
sub_81CF3E4: @ 81CF3E4
	push {lr}
	movs r0, 0x8
	bl GetSubstructPtr
	ldr r0, [r0, 0x4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	thumb_func_end sub_81CF3E4

	thumb_func_start sub_81CF3F8
sub_81CF3F8: @ 81CF3F8
	push {r4,lr}
	movs r0, 0x8
	bl GetSubstructPtr
	adds r4, r0, 0
	bl sub_81C8234
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x8
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CF3F8

	thumb_func_start sub_81CF418
sub_81CF418: @ 81CF418
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x8
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x5
	bls _081CF42C
	b _081CF56E
_081CF42C:
	lsls r0, r4, 2
	ldr r1, =_081CF43C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CF43C:
	.4byte _081CF454
	.4byte _081CF4AC
	.4byte _081CF4C0
	.4byte _081CF4E0
	.4byte _081CF4F6
	.4byte _081CF55A
_081CF454:
	ldr r0, =gUnknown_08623590
	movs r1, 0x2
	bl InitBgTemplates
	ldr r1, =gUnknown_086233E4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x10
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086234AC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_086233C4
	movs r1, 0x10
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081CF498:
	movs r0, 0
	b _081CF570
	.pool
_081CF4AC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	bl sub_81CF0C0
	cmp r0, 0
	beq _081CF56A
	b _081CF498
_081CF4C0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	ldr r0, =gUnknown_08623570
	movs r1, 0x20
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	bl sub_81CF88C
	b _081CF498
	.pool
_081CF4E0:
	bl sub_81C8224
	cmp r0, 0
	bne _081CF56A
	adds r0, r5, 0
	bl sub_81CF7C8
	movs r0, 0x3
	bl sub_81C7BA4
	b _081CF498
_081CF4F6:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _081CF552
	bl sub_81C76AC
	adds r4, r0, 0
	adds r4, 0x8
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl LoadLeftHeaderGfxForIndex
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
_081CF552:
	movs r0, 0x1
	bl sub_81C7AC0
	b _081CF498
_081CF55A:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CF56A
	bl sub_81C8010
	cmp r0, 0
	beq _081CF56E
_081CF56A:
	movs r0, 0x2
	b _081CF570
_081CF56E:
	movs r0, 0x4
_081CF570:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF418

	thumb_func_start sub_81CF578
sub_81CF578: @ 81CF578
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF5C6
	cmp r4, 0x1
	bgt _081CF592
	cmp r4, 0
	beq _081CF59C
	b _081CF5E6
_081CF592:
	cmp r4, 0x2
	beq _081CF5CE
	cmp r4, 0x3
	beq _081CF5D8
	b _081CF5E6
_081CF59C:
	bl MatchCall_MoveCursorUp
	cmp r0, 0x1
	beq _081CF5B4
	cmp r0, 0x1
	bgt _081CF5AE
	cmp r0, 0
	beq _081CF5E6
	b _081CF5D4
_081CF5AE:
	cmp r0, 0x2
	beq _081CF5BE
	b _081CF5D4
_081CF5B4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF5E8
_081CF5BE:
	movs r0, 0x5
	bl PlaySE
	b _081CF5D4
_081CF5C6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF5E2
_081CF5CE:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF5D4:
	movs r0, 0
	b _081CF5E8
_081CF5D8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF5E6
_081CF5E2:
	movs r0, 0x2
	b _081CF5E8
_081CF5E6:
	movs r0, 0x4
_081CF5E8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF578

	thumb_func_start sub_81CF5F0
sub_81CF5F0: @ 81CF5F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF63E
	cmp r4, 0x1
	bgt _081CF60A
	cmp r4, 0
	beq _081CF614
	b _081CF65E
_081CF60A:
	cmp r4, 0x2
	beq _081CF646
	cmp r4, 0x3
	beq _081CF650
	b _081CF65E
_081CF614:
	bl MatchCall_MoveCursorDown
	cmp r0, 0x1
	beq _081CF62C
	cmp r0, 0x1
	bgt _081CF626
	cmp r0, 0
	beq _081CF65E
	b _081CF64C
_081CF626:
	cmp r0, 0x2
	beq _081CF636
	b _081CF64C
_081CF62C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF660
_081CF636:
	movs r0, 0x5
	bl PlaySE
	b _081CF64C
_081CF63E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF65A
_081CF646:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF64C:
	movs r0, 0
	b _081CF660
_081CF650:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF65E
_081CF65A:
	movs r0, 0x2
	b _081CF660
_081CF65E:
	movs r0, 0x4
_081CF660:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF5F0

	thumb_func_start sub_81CF668
sub_81CF668: @ 81CF668
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF6B6
	cmp r4, 0x1
	bgt _081CF682
	cmp r4, 0
	beq _081CF68C
	b _081CF6D6
_081CF682:
	cmp r4, 0x2
	beq _081CF6BE
	cmp r4, 0x3
	beq _081CF6C8
	b _081CF6D6
_081CF68C:
	bl MatchCall_PageUp
	cmp r0, 0x1
	beq _081CF6A4
	cmp r0, 0x1
	bgt _081CF69E
	cmp r0, 0
	beq _081CF6D6
	b _081CF6C4
_081CF69E:
	cmp r0, 0x2
	beq _081CF6AE
	b _081CF6C4
_081CF6A4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF6D8
_081CF6AE:
	movs r0, 0x5
	bl PlaySE
	b _081CF6C4
_081CF6B6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF6D2
_081CF6BE:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF6C4:
	movs r0, 0
	b _081CF6D8
_081CF6C8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF6D6
_081CF6D2:
	movs r0, 0x2
	b _081CF6D8
_081CF6D6:
	movs r0, 0x4
_081CF6D8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF668

	thumb_func_start sub_81CF6E0
sub_81CF6E0: @ 81CF6E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF72E
	cmp r4, 0x1
	bgt _081CF6FA
	cmp r4, 0
	beq _081CF704
	b _081CF74E
_081CF6FA:
	cmp r4, 0x2
	beq _081CF736
	cmp r4, 0x3
	beq _081CF740
	b _081CF74E
_081CF704:
	bl MatchCall_PageDown
	cmp r0, 0x1
	beq _081CF71C
	cmp r0, 0x1
	bgt _081CF716
	cmp r0, 0
	beq _081CF74E
	b _081CF73C
_081CF716:
	cmp r0, 0x2
	beq _081CF726
	b _081CF73C
_081CF71C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF750
_081CF726:
	movs r0, 0x5
	bl PlaySE
	b _081CF73C
_081CF72E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF74A
_081CF736:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF73C:
	movs r0, 0
	b _081CF750
_081CF740:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF74E
_081CF74A:
	movs r0, 0x2
	b _081CF750
_081CF74E:
	movs r0, 0x4
_081CF750:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF6E0

	thumb_func_start sub_81CF758
sub_81CF758: @ 81CF758
	push {lr}
	cmp r0, 0
	beq _081CF764
	cmp r0, 0x1
	beq _081CF778
	b _081CF790
_081CF764:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081CF792
_081CF778:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CF788
	bl MainMenuLoopedTaskIsBusy
	cmp r0, 0
	beq _081CF78C
_081CF788:
	movs r0, 0x2
	b _081CF792
_081CF78C:
	bl sub_81C7FDC
_081CF790:
	movs r0, 0x4
_081CF792:
	pop {r1}
	bx r1
	thumb_func_end sub_81CF758

	thumb_func_start sub_81CF798
sub_81CF798: @ 81CF798
	push {lr}
	cmp r0, 0
	beq _081CF7A4
	cmp r0, 0x1
	beq _081CF7B4
	b _081CF7C0
_081CF7A4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081CF7C2
_081CF7B4:
	bl IsPaletteFadeActive
	cmp r0, 0
	beq _081CF7C0
	movs r0, 0x2
	b _081CF7C2
_081CF7C0:
	movs r0, 0x4
_081CF7C2:
	pop {r1}
	bx r1
	thumb_func_end sub_81CF798

	thumb_func_start sub_81CF7C8
sub_81CF7C8: @ 81CF7C8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086235B4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	adds r0, r4, 0
	bl sub_81CF7F4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF7C8

	thumb_func_start sub_81CF7F4
sub_81CF7F4: @ 81CF7F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	bl sub_81CF0F0
	adds r7, r0, 0
	bl DynamicPlaceholderTextUtil_Reset
	ldr r4, =gStringVar1
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0xFF
	strb r0, [r4]
	ldr r5, =gStringVar2
	ldr r1, =gText_NumberF700
	adds r0, r5, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	mov r1, r8
	ldrb r0, [r1, 0x8]
	movs r1, 0x1
	mov r10, r1
	str r1, [sp]
	movs r1, 0xFF
	mov r9, r1
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r1, r8
	ldrb r0, [r1, 0x8]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x22
	bl AddTextPrinterParameterized
	mov r1, r8
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF7F4

	thumb_func_start sub_81CF88C
sub_81CF88C: @ 81CF88C
	push {r4,lr}
	sub sp, 0x18
	bl sub_81CF0D0
	str r0, [sp]
	bl sub_81CF0E0
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_81CF10C
	mov r1, sp
	strh r0, [r1, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x11
	strb r0, [r1, 0xA]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0xD]
	mov r0, sp
	strb r2, [r0, 0xE]
	ldr r0, =sub_81CF8E4
	str r0, [sp, 0x10]
	str r4, [sp, 0x14]
	ldr r0, =gUnknown_08623594
	movs r2, 0
	bl sub_81C81D4
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF88C

	thumb_func_start sub_81CF8E4
sub_81CF8E4: @ 81CF8E4
	push {r4-r7,lr}
	adds r2, r0, 0
	adds r6, r1, 0
	ldrb r0, [r2]
	cmp r0, 0xE
	bne _081CF924
	ldrb r1, [r2, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromMonExp
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMonData
	b _081CF94A
	.pool
_081CF924:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBoxMonData
_081CF94A:
	ldr r4, =gStringVar3
	adds r0, r4, 0
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3C
	bl sub_81DB494
	adds r6, r0, 0
	cmp r5, 0
	beq _081CF974
	cmp r5, 0xFE
	beq _081CF97C
	ldr r1, =gUnknown_086235D4
	b _081CF97E
	.pool
_081CF974:
	ldr r1, =gUnknown_086235BC
	b _081CF97E
	.pool
_081CF97C:
	ldr r1, =gUnknown_086235C8
_081CF97E:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x28
	bl sub_81DB494
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF8E4    

    .align 2, 0 @ Don't pad with nop.
