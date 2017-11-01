	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8124904
sub_8124904: @ 8124904
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r2, =gUnknown_0203A148
	ldr r0, [r2]
	ldrb r0, [r0, 0xA]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0812491A
	b _08124A2C
_0812491A:
	movs r7, 0
	movs r3, 0
	ldr r0, =gUnknown_085A1EDC
	mov r12, r0
	adds r5, r2, 0
	movs r6, 0
_08124926:
	ldr r0, [r5]
	lsls r1, r3, 3
	mov r2, r12
	adds r4, r1, r2
	ldrh r0, [r0, 0x8]
	ldrh r1, [r4, 0x4]
	cmp r0, r1
	bne _081249C4
	ldrh r0, [r4, 0x6]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081249CE
	ldr r0, [r5]
	ldrb r0, [r0, 0xB]
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl StringLength
	movs r7, 0x1
	movs r0, 0
	movs r1, 0
	bl sub_8198070
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x65
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r2, [r5]
	adds r2, 0xC
	str r7, [sp]
	str r6, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldr r0, [r5]
	ldrb r0, [r0, 0xB]
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x11
	str r0, [sp]
	str r6, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_03001180
	str r7, [r0]
	b _081249CE
	.pool
_081249C4:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _08124926
_081249CE:
	cmp r7, 0
	bne _08124A62
	ldr r0, =gUnknown_03001180
	ldr r0, [r0]
	cmp r0, 0x1
	bne _081249F4
	movs r0, 0x1
	movs r1, 0
	bl sub_8198070
	movs r0, 0
	movs r1, 0
	movs r2, 0x65
	movs r3, 0xD
	bl SetWindowBorderStyle
	b _081249FC
	.pool
_081249F4:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
_081249FC:
	ldr r0, =gUnknown_0203A148
	ldr r2, [r0]
	adds r2, 0xC
	movs r0, 0x1
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_03001180
	str r4, [r0]
	b _08124A62
	.pool
_08124A2C:
	ldr r4, =gUnknown_03001180
	ldr r0, [r4]
	cmp r0, 0x1
	bne _08124A48
	movs r0, 0x1
	movs r1, 0
	bl sub_8198070
	movs r0, 0
	movs r1, 0
	movs r2, 0x65
	movs r3, 0xD
	bl SetWindowBorderStyle
_08124A48:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	str r0, [r4]
_08124A62:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124904

	thumb_func_start sub_8124A70
sub_8124A70: @ 8124A70
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_085A1D68
	ldr r5, =gUnknown_0203A148
	ldr r1, [r5]
	ldr r4, =0x0000088c
	adds r1, r4
	bl LZ77UnCompWram
	ldr r0, [r5]
	adds r0, r4
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0xE0
	lsls r1, 1
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 10
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085A1F10
	bl LoadSpritePalette
	bl sub_8124AD4
	bl sub_8124BE4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124A70

	thumb_func_start sub_8124AD4
sub_8124AD4: @ 8124AD4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =0x0000086f
	str r0, [sp, 0xC]
	movs r1, 0
	mov r9, r1
	mov r2, sp
	adds r2, 0x6
	str r2, [sp, 0x14]
	mov r3, sp
	adds r3, 0xA
	str r3, [sp, 0x18]
	mov r0, sp
	adds r0, 0x8
	str r0, [sp, 0x10]
	add r1, sp, 0x4
	mov r10, r1
_08124AFE:
	ldr r2, [sp, 0x18]
	str r2, [sp]
	mov r0, r9
	add r1, sp, 0x4
	mov r2, sp
	adds r2, 0x6
	ldr r3, [sp, 0x10]
	bl sub_8124630
	mov r3, r10
	ldrh r0, [r3]
	adds r0, 0x1
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r3]
	mov r1, sp
	ldrh r0, [r1, 0x6]
	adds r0, 0x2
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r1, 0x6]
	ldr r2, [sp, 0x10]
	ldrh r0, [r2]
	cmp r0, 0x2
	bne _08124B38
	movs r7, 0x1
	b _08124B44
	.pool
_08124B38:
	ldr r3, [sp, 0x18]
	ldrh r0, [r3]
	movs r7, 0
	cmp r0, 0x2
	bne _08124B44
	movs r7, 0x2
_08124B44:
	mov r0, r10
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, [sp, 0x14]
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r0, =gUnknown_085A1F7C
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _08124BB8
	ldr r1, =gSprites
	mov r8, r1
	lsls r4, r5, 4
	adds r0, r4, r5
	lsls r6, r0, 2
	adds r2, r6, r1
	lsls r3, r7, 6
	ldrb r1, [r2, 0x1]
	movs r0, 0x3F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x1]
	ldr r0, [sp, 0xC]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08124B9C
	mov r0, r8
	adds r0, 0x1C
	adds r0, r6, r0
	ldr r1, =sub_8124CBC
	str r1, [r0]
	b _08124BA2
	.pool
_08124B9C:
	adds r0, r7, 0x3
	lsls r0, 16
	lsrs r7, r0, 16
_08124BA2:
	adds r4, r5
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	lsls r1, r7, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	mov r2, r9
	strh r2, [r4, 0x2E]
_08124BB8:
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0xF
	bls _08124AFE
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124AD4

	thumb_func_start sub_8124BE4
sub_8124BE4: @ 8124BE4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r0, 0
	mov r8, r0
	ldr r6, =gUnknown_085A1F18
	ldrh r0, [r6, 0x2]
	cmp r0, 0xD5
	beq _08124C9C
	mov r5, sp
	adds r5, 0x6
	add r7, sp, 0x4
	ldr r1, =gSprites
	mov r9, r1
	movs r0, 0x1C
	add r0, r9
	mov r10, r0
_08124C0C:
	mov r1, r8
	lsls r4, r1, 2
	adds r0, r4, r6
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08124C84
	adds r0, r6, 0x2
	adds r0, r4, r0
	ldrh r6, [r0]
	mov r0, sp
	adds r0, 0xA
	str r0, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	add r3, sp, 0x8
	bl sub_8124630
	ldrh r0, [r7]
	adds r0, 0x1
	lsls r0, 3
	strh r0, [r7]
	ldrh r0, [r5]
	adds r0, 0x2
	lsls r0, 3
	strh r0, [r5]
	movs r0, 0
	ldrsh r1, [r7, r0]
	movs r0, 0
	ldrsh r2, [r5, r0]
	ldr r0, =gUnknown_085A1F7C
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08124C84
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	mov r1, r9
	adds r4, r2, r1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x3]
	add r2, r10
	ldr r0, =sub_8124CBC
	str r0, [r2]
	adds r0, r4, 0
	movs r1, 0x6
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
_08124C84:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r6, =gUnknown_085A1F18
	lsls r0, 2
	adds r1, r6, 0x2
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0xD5
	bne _08124C0C
_08124C9C:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124BE4

	thumb_func_start sub_8124CBC
sub_8124CBC: @ 8124CBC
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldrh r1, [r0, 0x8]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _08124D00
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08124D0E
	movs r0, 0
	strh r0, [r2, 0x30]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08124D0E
	.pool
_08124D00:
	movs r0, 0x10
	strh r0, [r2, 0x30]
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x15
	ands r0, r1
	strb r0, [r2]
_08124D0E:
	pop {r0}
	bx r0
	thumb_func_end sub_8124CBC

	thumb_func_start sub_8124D14
sub_8124D14: @ 8124D14
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	ldrh r1, [r0, 0x4]
	cmp r1, 0
	beq _08124D2C
	cmp r1, 0x1
	beq _08124D46
	b _08124D56
	.pool
_08124D2C:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _08124D56
_08124D46:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08124D56
	ldr r0, =sub_8124D64
	bl sub_81248F4
_08124D56:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124D14

	thumb_func_start sub_8124D64
sub_8124D64: @ 8124D64
	push {r4,lr}
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	bne _08124DF8
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bhi _08124DF8
	lsls r0, 2
	ldr r1, =_08124D90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08124D90:
	.4byte _08124DF8
	.4byte _08124DF8
	.4byte _08124DF8
	.4byte _08124DA8
	.4byte _08124DAE
	.4byte _08124DE0
_08124DA8:
	bl sub_8124904
	b _08124DF8
_08124DAE:
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0x2
	beq _08124DBC
	cmp r0, 0x4
	bne _08124DF8
_08124DBC:
	movs r0, 0x5
	bl m4aSongNumStart
	ldr r0, [r4]
	ldr r1, =0x00000a72
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, =sub_8124E0C
	bl sub_81248F4
	b _08124DF8
	.pool
_08124DE0:
	movs r0, 0x5
	bl m4aSongNumStart
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldr r1, =0x00000a72
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, =sub_8124E0C
	bl sub_81248F4
_08124DF8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124D64

	thumb_func_start sub_8124E0C
sub_8124E0C: @ 8124E0C
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	ldrh r1, [r0, 0x4]
	cmp r1, 0
	beq _08124E24
	cmp r1, 0x1
	beq _08124E3E
	b _08124F1A
	.pool
_08124E24:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _08124F1A
_08124E3E:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08124F1A
	bl FreeRegionMapIconResources
	ldr r1, [r4]
	ldr r2, =0x00000a72
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08124F00
	ldrh r0, [r1, 0x8]
	cmp r0, 0xF
	beq _08124E98
	cmp r0, 0xF
	bgt _08124E6C
	cmp r0, 0
	beq _08124E84
	b _08124EBC
	.pool
_08124E6C:
	cmp r0, 0x3A
	beq _08124E7C
	cmp r0, 0x49
	bne _08124EBC
	movs r0, 0x15
	bl sub_8084CCC
	b _08124EFA
_08124E7C:
	movs r0, 0x16
	bl sub_8084CCC
	b _08124EFA
_08124E84:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	movs r1, 0xD
	cmp r0, 0
	bne _08124EB0
	movs r1, 0xC
	b _08124EB0
	.pool
_08124E98:
	ldr r0, =0x000008b4
	bl FlagGet
	lsls r0, 24
	movs r1, 0xB
	cmp r0, 0
	beq _08124EB0
	ldr r0, [r4]
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	bne _08124EB0
	movs r1, 0x14
_08124EB0:
	adds r0, r1, 0
	bl sub_8084CCC
	b _08124EFA
	.pool
_08124EBC:
	ldr r3, =gUnknown_085A1E3C
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldrh r1, [r0, 0x8]
	lsls r0, r1, 1
	adds r2, r0, r1
	adds r0, r3, 0x2
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08124EE0
	bl sub_8084CCC
	b _08124EFA
	.pool
_08124EE0:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	bl warp1_set_2
_08124EFA:
	bl sub_80B69DC
	b _08124F06
_08124F00:
	ldr r0, =sub_81B58A8
	bl SetMainCallback2
_08124F06:
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	cmp r0, 0
	beq _08124F16
	bl Free
	movs r0, 0
	str r0, [r4]
_08124F16:
	bl FreeAllWindowBuffers
_08124F1A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124E0C

	.align 2, 0 @ Don't pad with nop.
