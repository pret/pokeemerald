	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text






	thumb_func_start sub_801BAAC
sub_801BAAC: @ 801BAAC
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r5, 0
	beq _0801BAC8
	cmp r6, 0
	beq _0801BAC8
	ldr r7, =gUnknown_02022C74
	ldr r0, =0x0000145c
	bl AllocZeroed
	str r0, [r7]
	cmp r0, 0
	bne _0801BAD4
_0801BAC8:
	movs r0, 0
	b _0801BB3E
	.pool
_0801BAD4:
	movs r4, 0xA6
	lsls r4, 1
	adds r1, r5, 0
	adds r2, r4, 0
	bl memcpy
	ldr r1, [r7]
	adds r1, r4
	adds r0, r6, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r7]
	ldrb r1, [r2, 0x8]
	lsls r0, r1, 26
	lsrs r0, 28
	cmp r0, 0x7
	bls _0801BB06
	movs r0, 0x3D
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x8]
_0801BB06:
	ldr r2, [r7]
	ldrb r1, [r2, 0x8]
	lsls r0, r1, 30
	lsrs r0, 30
	cmp r0, 0x2
	bls _0801BB1A
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x8]
_0801BB1A:
	ldr r1, [r7]
	ldrb r0, [r1, 0x9]
	cmp r0, 0x7
	bls _0801BB26
	movs r0, 0
	strb r0, [r1, 0x9]
_0801BB26:
	ldr r0, [r7]
	movs r1, 0xB8
	lsls r1, 1
	adds r2, r0, r1
	ldrb r0, [r0, 0x8]
	lsls r0, 26
	lsrs r0, 28
	lsls r0, 4
	ldr r1, =gUnknown_082F1D60
	adds r0, r1
	str r0, [r2]
	movs r0, 0x1
_0801BB3E:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801BAAC

	thumb_func_start sub_801BB48
sub_801BB48: @ 801BB48
	push {r4,lr}
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	cmp r0, 0
	beq _0801BB64
	ldr r2, =0x0000145c
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801BB64:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801BB48

	thumb_func_start sub_801BB74
sub_801BB74: @ 801BB74
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	cmp r0, 0
	bne _0801BB8C
	movs r0, 0x1
	negs r0, r0
	b _0801BD98
	.pool
_0801BB8C:
	movs r4, 0xBA
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _0801BB9A
	b _0801BD70
_0801BB9A:
	lsls r0, 2
	ldr r1, =_0801BBA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801BBA8:
	.4byte _0801BBC8
	.4byte _0801BBDA
	.4byte _0801BBE8
	.4byte _0801BC8C
	.4byte _0801BD14
	.4byte _0801BD1A
	.4byte _0801BD34
	.4byte _0801BD3A
_0801BBC8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801BD86
_0801BBDA:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801BBE6
	b _0801BD86
_0801BBE6:
	b _0801BD96
_0801BBE8:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0x8
	bl decompress_and_copy_tile_data_to_vram
	ldr r4, =gUnknown_082F0E1C
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xBB
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x8
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xBC
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	adds r4, 0x10
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xBD
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	b _0801BD86
	.pool
_0801BC8C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _0801BC9A
	b _0801BD96
_0801BC9A:
	movs r0, 0x1
	bl stdpal_get
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldr r4, =0x0000045c
	adds r1, r4
	bl LZ77UnCompWram
	ldr r1, [r5]
	adds r1, r4
	movs r2, 0x1E
	str r2, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	str r6, [sp, 0xC]
	str r2, [sp, 0x10]
	str r0, [sp, 0x14]
	movs r0, 0x1
	str r0, [sp, 0x18]
	movs r0, 0x8
	str r0, [sp, 0x1C]
	str r6, [sp, 0x20]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _0801BD86
	.pool
_0801BD14:
	bl sub_801BEF8
	b _0801BD86
_0801BD1A:
	movs r0, 0
	bl sub_801C178
	movs r0, 0x1
	bl sub_801C178
	movs r0, 0x2
	bl sub_801C178
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _0801BD86
_0801BD34:
	bl LoadMonIconPalettes
	b _0801BD86
_0801BD3A:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	bl sub_801C4C0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _0801BD86
	.pool
_0801BD70:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0801BD96
	ldr r0, [r5]
	adds r0, r4
	strb r1, [r0]
	movs r0, 0x1
	b _0801BD98
_0801BD86:
	ldr r0, =gUnknown_02022C74
	ldr r1, [r0]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0801BD96:
	movs r0, 0
_0801BD98:
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801BB74

	thumb_func_start sub_801BDA4
sub_801BDA4: @ 801BDA4
	push {r4,r5,lr}
	sub sp, 0x8
	adds r2, r0, 0
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	cmp r0, 0
	bne _0801BDBC
	movs r0, 0x1
	negs r0, r0
	b _0801BEEC
	.pool
_0801BDBC:
	movs r4, 0xBA
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x5
	bls _0801BDCA
	b _0801BEC4
_0801BDCA:
	lsls r0, 2
	ldr r1, =_0801BDD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801BDD8:
	.4byte _0801BDF0
	.4byte _0801BE02
	.4byte _0801BE0E
	.4byte _0801BE56
	.4byte _0801BE94
	.4byte _0801BE9E
_0801BDF0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801BEDA
_0801BE02:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801BEDA
	b _0801BEEA
_0801BE0E:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _0801BEDA
_0801BE56:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	movs r1, 0xBD
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	movs r1, 0xBB
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	b _0801BEDA
	.pool
_0801BE94:
	bl sub_801C61C
	bl FreeMonIconPalettes
	b _0801BEDA
_0801BE9E:
	ldr r0, =gUnknown_02022C60
	ldrb r0, [r0]
	adds r1, r2, 0
	bl sub_80186EC
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0801BEDA
	.pool
_0801BEC4:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0801BEEA
	ldr r0, [r5]
	adds r0, r4
	strb r1, [r0]
	movs r0, 0x1
	b _0801BEEC
_0801BEDA:
	ldr r0, =gUnknown_02022C74
	ldr r1, [r0]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0801BEEA:
	movs r0, 0
_0801BEEC:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801BDA4

	thumb_func_start sub_801BEF8
sub_801BEF8: @ 801BEF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r5, 0
	mov r0, sp
	movs r1, 0
	movs r2, 0x6
	bl memset
	ldr r4, =gUnknown_02022C74
	ldr r1, [r4]
	ldr r2, =0x0000018b
	adds r0, r1, r2
	adds r1, 0xA
	movs r2, 0x28
	bl memcpy
	ldr r0, [r4]
	ldr r3, =0x000001b3
	adds r1, r0, r3
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, [r4]
	movs r2, 0xDA
	lsls r2, 1
	adds r0, r1, r2
	adds r1, 0x32
	movs r2, 0x28
	bl memcpy
	ldr r0, [r4]
	movs r3, 0xEE
	lsls r3, 1
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	ldr r2, =0x000f423f
	cmp r0, r2
	bls _0801BF54
	str r2, [r1, 0x4]
_0801BF54:
	ldr r1, [r4]
	ldr r2, =0x000001dd
	adds r0, r1, r2
	ldr r1, [r1, 0x4]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	adds r6, r4, 0
_0801BF66:
	ldr r2, [r6]
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r5
	adds r0, r4, r2
	movs r3, 0xF2
	lsls r3, 1
	adds r0, r3
	adds r1, r2
	adds r1, 0x5A
	movs r2, 0x28
	bl memcpy
	ldr r1, [r6]
	movs r0, 0x83
	lsls r0, 2
	adds r1, r0
	adds r1, r4
	movs r2, 0x1
	negs r2, r2
	adds r7, r2, 0
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _0801BF66
	ldr r6, =gUnknown_02022C74
	ldr r1, [r6]
	movs r3, 0xA2
	lsls r3, 2
	adds r0, r1, r3
	adds r1, 0xFA
	movs r2, 0x28
	bl memcpy
	ldr r0, [r6]
	movs r4, 0xAC
	lsls r4, 2
	adds r0, r4
	movs r1, 0x1
	negs r1, r1
	adds r4, r1, 0
	movs r1, 0xFF
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, 0x8]
	lsls r0, 30
	lsrs r0, 30
	cmp r0, 0x1
	beq _0801C018
	cmp r0, 0x1
	bgt _0801BFF0
	cmp r0, 0
	beq _0801BFF6
	b _0801C168
	.pool
_0801BFF0:
	cmp r0, 0x2
	beq _0801C028
	b _0801C168
_0801BFF6:
	ldr r2, =0x000002b1
	adds r0, r1, r2
	movs r3, 0x91
	lsls r3, 1
	adds r1, r3
	movs r2, 0x28
	bl memcpy
	ldr r1, [r6]
	ldr r0, =0x000002d9
	adds r1, r0
	b _0801C01C
	.pool
_0801C018:
	ldr r2, =0x000002b1
	adds r1, r2
_0801C01C:
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	b _0801C168
	.pool
_0801C028:
	ldr r3, =0x000002b1
	adds r0, r1, r3
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	mov r3, sp
	ldr r1, [r6]
	movs r4, 0xA6
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	ldr r2, =0x000003e7
	cmp r0, r2
	bls _0801C046
	adds r0, r2, 0
_0801C046:
	strh r0, [r3]
	mov r3, sp
	movs r4, 0xA7
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, r2
	bls _0801C058
	adds r0, r2, 0
_0801C058:
	strh r0, [r3, 0x2]
	mov r3, sp
	movs r4, 0xA8
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, r2
	bls _0801C06A
	adds r0, r2, 0
_0801C06A:
	strh r0, [r3, 0x4]
	movs r5, 0
_0801C06E:
	lsls r4, r5, 1
	adds r4, r5
	lsls r4, 4
	movs r0, 0xB7
	lsls r0, 2
	adds r4, r0
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x2A
	movs r1, 0xFF
	movs r2, 0x4
	bl memset
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x1
	movs r1, 0xFF
	movs r2, 0x29
	bl memset
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _0801C06E
	movs r5, 0
	movs r6, 0
	ldr r1, =gUnknown_02022C74
	mov r8, r1
	movs r2, 0x91
	lsls r2, 1
	mov r10, r2
	ldr r7, =0x00000175
	movs r3, 0xB7
	lsls r3, 2
	mov r9, r3
_0801C0B6:
	mov r4, r8
	ldr r2, [r4]
	mov r0, r10
	adds r1, r2, r0
	adds r0, r1, r5
	ldrb r3, [r0]
	cmp r3, 0xF7
	beq _0801C0F8
	ldr r1, =0x00000175
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	adds r0, r6, r0
	ldr r4, =0x000002dd
	adds r1, r2, r4
	adds r1, r0
	strb r3, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	b _0801C15E
	.pool
_0801C0F8:
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	cmp r3, 0x2
	bls _0801C108
	adds r0, r5, 0x2
	lsls r0, 16
	b _0801C15C
_0801C108:
	adds r0, r2, r7
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	add r0, r9
	adds r0, r2, r0
	adds r0, 0x2A
	lsls r1, r3, 1
	add r1, sp
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, r7
	ldrb r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r0, r1, r0
	adds r4, r5, 0x2
	add r1, r10
	adds r1, r4
	ldrb r1, [r1]
	add r0, r9
	strb r1, [r0]
	mov r2, r8
	ldr r1, [r2]
	adds r1, r7
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0x7
	bhi _0801C168
	movs r6, 0
	lsls r0, r4, 16
_0801C15C:
	lsrs r5, r0, 16
_0801C15E:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x27
	bls _0801C0B6
_0801C168:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801BEF8

	thumb_func_start sub_801C178
sub_801C178: @ 801C178
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	movs r0, 0
	str r0, [sp, 0xC]
	ldr r7, =gUnknown_02022C74
	ldr r0, [r7]
	lsls r1, r4, 1
	movs r2, 0xBB
	lsls r2, 1
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	lsls r6, r0, 24
	lsrs r5, r6, 24
	adds r0, r5, 0
	bl PutWindowTilemap
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0x1
	beq _0801C2A0
	cmp r4, 0x1
	bgt _0801C1C4
	cmp r4, 0
	beq _0801C1D0
	mov r9, r6
	b _0801C498
	.pool
_0801C1C4:
	mov r0, r8
	cmp r0, 0x2
	bne _0801C1CC
	b _0801C304
_0801C1CC:
	mov r9, r6
	b _0801C498
_0801C1D0:
	ldr r2, [r7]
	movs r1, 0xB8
	lsls r1, 1
	mov r10, r1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 28
	lsrs r0, 28
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, =gUnknown_082F0E10
	mov r8, r0
	add r1, r8
	str r1, [sp]
	ldr r1, [sp, 0xC]
	str r1, [sp, 0x4]
	ldr r0, =0x0000018b
	adds r2, r0
	str r2, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldr r4, [r7]
	movs r1, 0xDA
	lsls r1, 1
	mov r9, r1
	add r4, r9
	movs r0, 0x3
	movs r1, 0x2
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x3
	adds r1, r4, 0
	bl GetStringWidth
	movs r1, 0xA0
	subs r1, r0
	cmp r1, 0
	bge _0801C22E
	movs r1, 0
_0801C22E:
	lsls r2, r1, 24
	lsrs r2, 24
	ldr r3, [r7]
	mov r1, r10
	adds r0, r3, r1
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	add r0, r8
	str r0, [sp]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x4]
	add r3, r9
	str r3, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r3, 0x11
	bl AddTextPrinterParameterized3
	ldr r2, [r7]
	ldr r0, [r2, 0x4]
	mov r9, r6
	cmp r0, 0
	bne _0801C266
	b _0801C498
_0801C266:
	mov r1, r10
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	add r0, r8
	str r0, [sp]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x4]
	ldr r1, =0x000001dd
	adds r0, r2, r1
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0xA6
	movs r3, 0x11
	bl AddTextPrinterParameterized3
	b _0801C498
	.pool
_0801C2A0:
	mov r9, r6
_0801C2A2:
	ldr r2, [sp, 0xC]
	lsls r4, r2, 24
	asrs r4, 24
	lsls r3, r4, 4
	adds r3, 0x2
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_02022C74
	ldr r2, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	lsrs r0, 4
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, =gUnknown_082F0E10
	adds r1, r0
	str r1, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r4
	movs r1, 0xF2
	lsls r1, 1
	adds r0, r1
	adds r2, r0
	str r2, [sp, 0x8]
	mov r2, r9
	lsrs r0, r2, 24
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	adds r4, 0x1
	lsls r4, 24
	lsrs r0, r4, 24
	str r0, [sp, 0xC]
	asrs r4, 24
	cmp r4, 0x3
	ble _0801C2A2
	b _0801C498
	.pool
_0801C304:
	ldr r4, =gUnknown_082F0E18
	ldr r2, [r7]
	ldrb r0, [r2, 0x8]
	lsls r0, 30
	lsrs r0, 30
	adds r0, r4
	ldrb r3, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsls r0, 28
	lsrs r0, 28
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, =gUnknown_082F0E10
	mov r10, r0
	add r1, r10
	str r1, [sp]
	ldr r1, [sp, 0xC]
	str r1, [sp, 0x4]
	movs r1, 0xA2
	lsls r1, 2
	adds r0, r2, r1
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	ldr r2, [r7]
	ldrb r1, [r2, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _0801C398
	lsls r0, r1, 30
	lsrs r0, 30
	adds r0, r4
	ldrb r3, [r0]
	adds r3, 0x10
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	add r0, r10
	str r0, [sp]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x4]
	ldr r1, =0x000002b1
	adds r0, r2, r1
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	mov r9, r6
	b _0801C498
	.pool
_0801C398:
	movs r2, 0
	mov r8, r2
	lsls r0, r1, 30
	lsrs r0, 30
	adds r0, r4
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
	movs r0, 0x3
	movs r1, 0x2
	bl GetFontAttribute
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r7]
	ldr r1, =0x00000175
	adds r0, r1
	mov r9, r6
	ldr r1, [sp, 0xC]
	ldrb r0, [r0]
	cmp r1, r0
	bge _0801C498
	str r5, [sp, 0x10]
	lsls r0, r4, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	mov r10, r2
_0801C3CE:
	mov r0, r8
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r3, [r7]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	ldr r1, =gUnknown_082F0E10
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0xC]
	lsls r0, r1, 24
	asrs r6, r0, 24
	lsls r0, r6, 1
	adds r0, r6
	lsls r5, r0, 4
	movs r0, 0xB7
	lsls r0, 2
	adds r4, r5, r0
	adds r3, r4
	adds r3, 0x1
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x10]
	movs r1, 0x3
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized3
	ldr r1, [r7]
	adds r0, r1, r5
	ldr r2, =0x00000306
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0801C482
	adds r1, r4
	adds r1, 0x1
	movs r0, 0x3
	mov r2, r10
	bl GetStringWidth
	add r8, r0
	mov r0, r8
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r3, [r7]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	ldr r1, =gUnknown_082F0E10
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r3, r4
	adds r3, 0x2A
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x10]
	movs r1, 0x3
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized3
	ldr r1, [r7]
	adds r1, r4
	adds r1, 0x2A
	movs r0, 0x3
	mov r2, r10
	bl GetStringWidth
	ldr r1, [r7]
	adds r1, r5
	movs r2, 0xB7
	lsls r2, 2
	adds r1, r2
	ldrb r1, [r1]
	adds r0, r1
	add r8, r0
_0801C482:
	adds r1, r6, 0x1
	lsls r1, 24
	lsrs r0, r1, 24
	str r0, [sp, 0xC]
	asrs r1, 24
	ldr r0, [r7]
	ldr r2, =0x00000175
	adds r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _0801C3CE
_0801C498:
	mov r1, r9
	lsrs r0, r1, 24
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C178

	thumb_func_start sub_801C4C0
sub_801C4C0: @ 801C4C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r7, 0
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, 0xA9
	lsls r2, 1
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _0801C52C
	bl sub_80D2E84
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =SpriteCallbackDummy
	str r7, [sp]
	str r7, [sp, 0x4]
	movs r2, 0xDC
	movs r3, 0x14
	bl sub_80D2D78
	ldr r1, [r4]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	ldr r2, =gSprites
	ldr r0, [r4]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
_0801C52C:
	ldr r1, [r4]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	beq _0801C5EE
	ldrb r1, [r1, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801C5EE
	ldr r0, =gUnknown_082F1D00
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, [r4]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsrs r0, 4
	lsls r0, 3
	ldr r1, =gUnknown_082F1D08
	adds r0, r1
	bl LoadSpritePalette
	ldr r0, [r4]
	ldrb r0, [r0, 0x9]
	cmp r7, r0
	bcs _0801C5EE
	adds r6, r4, 0
	ldr r0, =0x0000017d
	mov r10, r0
	movs r1, 0
	mov r9, r1
	movs r2, 0xFF
	mov r8, r2
_0801C572:
	ldr r1, [r6]
	lsls r4, r7, 1
	add r1, r10
	adds r1, r4
	ldrb r0, [r1]
	mov r2, r8
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	movs r0, 0xBF
	lsls r0, 1
	adds r1, r0
	adds r1, r4
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	lsls r1, r7, 5
	movs r0, 0xD8
	subs r5, r0, r1
	ldr r0, =gUnknown_082F1D48
	adds r1, r5, 0
	movs r2, 0x90
	movs r3, 0x8
	bl CreateSprite
	ldr r1, [r6]
	add r1, r10
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, 0
	beq _0801C5E0
	bl sub_80D2E84
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r1, =SpriteCallbackDummy
	adds r2, r5, 0
	movs r3, 0x88
	bl sub_80D2D78
	ldr r1, [r6]
	movs r2, 0xBF
	lsls r2, 1
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
_0801C5E0:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, [r6]
	ldrb r0, [r0, 0x9]
	cmp r7, r0
	bcc _0801C572
_0801C5EE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C4C0

	thumb_func_start sub_801C61C
sub_801C61C: @ 801C61C
	push {r4-r7,lr}
	movs r5, 0
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801C640
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D2EF8
_0801C640:
	ldr r0, [r4]
	ldrb r2, [r0, 0x9]
	cmp r2, 0
	beq _0801C6B4
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801C6B4
	cmp r5, r2
	bcs _0801C6A4
	adds r6, r4, 0
	ldr r7, =gSprites
_0801C65A:
	ldr r0, [r6]
	lsls r4, r5, 1
	ldr r1, =0x0000017d
	adds r0, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801C678
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl DestroySprite
_0801C678:
	ldr r0, [r6]
	movs r2, 0xBF
	lsls r2, 1
	adds r0, r2
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801C696
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl sub_80D2EF8
_0801C696:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r6]
	ldrb r0, [r0, 0x9]
	cmp r5, r0
	bcc _0801C65A
_0801C6A4:
	movs r4, 0x80
	lsls r4, 8
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
_0801C6B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C61C

	thumb_func_start sub_801C6C8
sub_801C6C8: @ 801C6C8
	push {r4-r6,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0801C6DE
	ldr r5, =gUnknown_02022C78
	ldr r0, =0x000013a4
	bl AllocZeroed
	str r0, [r5]
	cmp r0, 0
	bne _0801C6EC
_0801C6DE:
	movs r0, 0
	b _0801C71C
	.pool
_0801C6EC:
	movs r6, 0xDE
	lsls r6, 1
	adds r1, r4, 0
	adds r2, r6, 0
	bl memcpy
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	cmp r0, 0x7
	bls _0801C704
	movs r0, 0
	strb r0, [r1, 0x3]
_0801C704:
	ldr r2, [r5]
	adds r3, r2, r6
	ldrb r0, [r2, 0x3]
	lsls r0, 4
	ldr r1, =gUnknown_082F24C8
	adds r0, r1
	str r0, [r3]
	ldr r0, =0x000001c1
	adds r1, r2, r0
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
_0801C71C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801C6C8

	thumb_func_start sub_801C72C
sub_801C72C: @ 801C72C
	push {r4,lr}
	ldr r4, =gUnknown_02022C78
	ldr r0, [r4]
	cmp r0, 0
	beq _0801C748
	ldr r2, =0x000013a4
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801C748:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C72C

	thumb_func_start sub_801C758
sub_801C758: @ 801C758
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r5, =gUnknown_02022C78
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C778
	movs r0, 0x1
	negs r0, r0
	b _0801CA3A
	.pool
_0801C778:
	movs r4, 0xE0
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	lsrs r0, 1
	cmp r0, 0x6
	bls _0801C788
	b _0801CA04
_0801C788:
	lsls r0, 2
	ldr r1, =_0801C798
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801C798:
	.4byte _0801C7B4
	.4byte _0801C7C6
	.4byte _0801C82C
	.4byte _0801C8D4
	.4byte _0801C990
	.4byte _0801C996
	.4byte _0801C9A8
_0801C7B4:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801CA1E
_0801C7C6:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801C7D2
	b _0801CA38
_0801C7D2:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r1, =0x00001a98
	movs r0, 0x44
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x1F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x1B
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	b _0801CA1E
	.pool
_0801C82C:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r5, =gUnknown_02022C78
	ldr r0, [r5]
	movs r1, 0xDE
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x8
	bl decompress_and_copy_tile_data_to_vram
	ldr r4, =gUnknown_082F1DE8
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xE4
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	adds r4, 0x8
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r3, 0xE5
	lsls r3, 1
	adds r1, r3
	strh r0, [r1]
	b _0801CA1E
	.pool
_0801C8D4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _0801C8E2
	b _0801CA38
_0801C8E2:
	movs r0, 0x1
	bl stdpal_get
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =gUnknown_02022C78
	mov r8, r0
	ldr r0, [r0]
	movs r4, 0xDE
	lsls r4, 1
	adds r0, r4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r4
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r6, 0xE9
	lsls r6, 2
	adds r1, r6
	bl LZ77UnCompWram
	mov r3, r8
	ldr r1, [r3]
	adds r1, r6
	movs r4, 0x1E
	str r4, [sp]
	movs r5, 0x3
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	str r7, [sp, 0xC]
	str r4, [sp, 0x10]
	str r5, [sp, 0x14]
	movs r0, 0x1
	mov r10, r0
	str r0, [sp, 0x18]
	movs r2, 0x8
	mov r9, r2
	str r2, [sp, 0x1C]
	str r7, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	mov r3, r8
	ldr r1, [r3]
	adds r1, r6
	str r4, [sp]
	movs r0, 0x17
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	str r5, [sp, 0xC]
	str r4, [sp, 0x10]
	str r0, [sp, 0x14]
	mov r0, r10
	str r0, [sp, 0x18]
	mov r2, r9
	str r2, [sp, 0x1C]
	str r7, [sp, 0x20]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x3
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0801CA1E
	.pool
_0801C990:
	bl sub_801CDCC
	b _0801CA1E
_0801C996:
	bl sub_801CE7C
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _0801CA1E
_0801C9A8:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r4, =gUnknown_02022C78
	ldr r1, [r4]
	movs r3, 0xE5
	lsls r3, 2
	adds r0, r1, r3
	movs r2, 0xE3
	lsls r2, 1
	adds r1, r2
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r3, =0x000001c1
	adds r2, r1, r3
	movs r1, 0
	strb r0, [r2]
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _0801CA1E
	.pool
_0801CA04:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801CA38
	ldr r0, [r5]
	adds r0, r4
	ldrb r2, [r0]
	movs r1, 0x1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1
	b _0801CA3A
_0801CA1E:
	ldr r0, =gUnknown_02022C78
	ldr r2, [r0]
	movs r0, 0xE0
	lsls r0, 1
	adds r2, r0
	ldrb r3, [r2]
	lsrs r1, r3, 1
	adds r1, 0x1
	lsls r1, 1
	movs r0, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0801CA38:
	movs r0, 0
_0801CA3A:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801C758

	thumb_func_start sub_801CA50
sub_801CA50: @ 801CA50
	push {r4,r5,lr}
	sub sp, 0x8
	adds r2, r0, 0
	ldr r5, =gUnknown_02022C78
	ldr r0, [r5]
	cmp r0, 0
	bne _0801CA68
	movs r0, 0x1
	negs r0, r0
	b _0801CC2A
	.pool
_0801CA68:
	movs r4, 0xE0
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	lsrs r0, 1
	cmp r0, 0x5
	bls _0801CA78
	b _0801CBF4
_0801CA78:
	lsls r0, 2
	ldr r1, =_0801CA88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801CA88:
	.4byte _0801CAA0
	.4byte _0801CAB2
	.4byte _0801CAF4
	.4byte _0801CB54
	.4byte _0801CB84
	.4byte _0801CBC0
_0801CAA0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801CC0E
_0801CAB2:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801CABE
	b _0801CC28
_0801CABE:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	b _0801CC0E
_0801CAF4:
	movs r4, 0x1E
	str r4, [sp]
	movs r5, 0x14
	str r5, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r5, 0x18
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0801CC0E
_0801CB54:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	ldr r4, =gUnknown_02022C78
	ldr r0, [r4]
	movs r1, 0xE5
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	movs r2, 0xE4
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	bl RemoveWindow
	b _0801CC0E
	.pool
_0801CB84:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r4, =gUnknown_02022C78
	ldr r0, [r4]
	ldr r2, =0x000001c1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801CC0E
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x000001c1
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
	b _0801CC0E
	.pool
_0801CBC0:
	ldr r0, =gUnknown_02022C60
	ldrb r0, [r0]
	adds r1, r2, 0
	bl sub_80186EC
	movs r0, 0x3
	bl sub_8018798
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0801CC0E
	.pool
_0801CBF4:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801CC28
	ldr r0, [r5]
	adds r0, r4
	ldrb r2, [r0]
	movs r1, 0x1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1
	b _0801CC2A
_0801CC0E:
	ldr r0, =gUnknown_02022C78
	ldr r2, [r0]
	movs r0, 0xE0
	lsls r0, 1
	adds r2, r0
	ldrb r3, [r2]
	lsrs r1, r3, 1
	adds r1, 0x1
	lsls r1, 1
	movs r0, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0801CC28:
	movs r0, 0
_0801CC2A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801CA50

	thumb_func_start sub_801CC38
sub_801CC38: @ 801CC38
	push {r4,r5,lr}
	ldr r4, =gUnknown_02022C78
	ldr r2, [r4]
	movs r5, 0xE0
	lsls r5, 1
	adds r0, r2, r5
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801CC72
	ldr r0, =0x000001c1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801CC72
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x000001c1
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
_0801CC72:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CC38

	thumb_func_start sub_801CC80
sub_801CC80: @ 801CC80
	push {r4,lr}
	ldr r4, =gUnknown_02022C78
	ldr r2, [r4]
	movs r1, 0xE0
	lsls r1, 1
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801CCC0
	movs r3, 0xE5
	lsls r3, 2
	adds r0, r2, r3
	movs r3, 0xE3
	lsls r3, 1
	adds r1, r2, r3
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r2, =0x000001c1
	adds r1, r2
	strb r0, [r1]
	ldr r1, [r4]
	movs r3, 0xE0
	lsls r3, 1
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_0801CCC0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CC80

	thumb_func_start sub_801CCD0
sub_801CCD0: @ 801CCD0
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r3, r4, 0
	ldr r2, =gUnknown_02022C78
	ldr r0, [r2]
	mov r12, r0
	movs r0, 0xE1
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _0801CD00
	bl sub_801CFA4
_0801CCF6:
	movs r0, 0xFF
	b _0801CDC6
	.pool
_0801CD00:
	cmp r4, 0x2
	beq _0801CD1C
	cmp r4, 0x2
	bgt _0801CD0E
	cmp r4, 0x1
	beq _0801CD18
	b _0801CCF6
_0801CD0E:
	cmp r3, 0x40
	beq _0801CD20
	cmp r3, 0x80
	beq _0801CD50
	b _0801CCF6
_0801CD18:
	movs r0, 0
	b _0801CDC6
_0801CD1C:
	movs r0, 0x1
	b _0801CDC6
_0801CD20:
	movs r0, 0xE3
	lsls r0, 1
	add r0, r12
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CCF6
	movs r0, 0xE0
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0801CCF6
	ldr r2, =0x000001c3
	add r2, r12
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	b _0801CD7E
	.pool
_0801CD50:
	movs r0, 0xE3
	lsls r0, 1
	add r0, r12
	movs r1, 0xE2
	lsls r1, 1
	add r1, r12
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0801CCF6
	movs r0, 0xE0
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0801CCF6
	ldr r2, =0x000001c3
	add r2, r12
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
_0801CD7E:
	strb r0, [r2]
	ldr r2, [r6]
	movs r4, 0xE1
	lsls r4, 1
	adds r2, r4
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r3, [r6]
	adds r3, r4
	ldrb r1, [r3]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r6]
	adds r4, 0x1
	adds r1, r4
	ldrb r3, [r1]
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _0801CDC4
	movs r0, 0x3
	b _0801CDC6
	.pool
_0801CDC4:
	movs r0, 0x2
_0801CDC6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801CCD0

	thumb_func_start sub_801CDCC
sub_801CDCC: @ 801CDCC
	push {r4-r6,lr}
	movs r5, 0
	ldr r4, =gUnknown_02022C78
	ldr r1, [r4]
	movs r2, 0xE7
	lsls r2, 1
	adds r0, r1, r2
	adds r1, 0x4
	movs r2, 0x28
	bl memcpy
	ldr r0, [r4]
	movs r3, 0xFB
	lsls r3, 1
	adds r1, r0, r3
	movs r0, 0xFF
	strb r0, [r1]
	adds r6, r4, 0
_0801CDF0:
	ldr r2, [r6]
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r5
	adds r0, r4, r2
	ldr r3, =0x000001f7
	adds r0, r3
	adds r1, r2
	adds r1, 0x2C
	movs r2, 0x28
	bl memcpy
	ldr r0, [r6]
	ldr r1, =0x0000021f
	adds r0, r1
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
	cmp r5, 0x7
	bls _0801CE34
	ldr r1, [r6]
	ldr r2, =0x000001f7
	adds r0, r1, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0801CE34
	movs r3, 0xE2
	lsls r3, 1
	adds r1, r3
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0801CE34:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _0801CDF0
	ldr r2, =gUnknown_02022C78
	ldr r1, [r2]
	movs r4, 0xE5
	lsls r4, 2
	adds r1, r4
	ldr r0, =gUnknown_082F1DF8
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, [r2]
	movs r5, 0xE2
	lsls r5, 1
	adds r0, r2, r5
	ldrh r1, [r0]
	movs r3, 0xE7
	lsls r3, 2
	adds r0, r2, r3
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CDCC

	thumb_func_start sub_801CE7C
sub_801CE7C: @ 801CE7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	movs r5, 0
	ldr r6, =gUnknown_02022C78
	ldr r0, [r6]
	movs r7, 0xE4
	lsls r7, 1
	adds r0, r7
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r4, 0xE5
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	adds r0, r7
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r4, [r6]
	movs r0, 0xE7
	lsls r0, 1
	mov r8, r0
	add r4, r8
	movs r0, 0x3
	movs r1, 0x2
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x3
	adds r1, r4, 0
	bl GetStringWidth
	movs r1, 0xE0
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	cmp r1, 0
	bge _0801CEEC
	movs r1, 0
_0801CEEC:
	ldr r4, [r6]
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r2, r1, 24
	lsrs r2, 24
	movs r3, 0xDE
	lsls r3, 1
	adds r1, r4, r3
	ldr r1, [r1]
	ldrb r1, [r1]
	lsls r1, 28
	lsrs r1, 28
	lsls r3, r1, 1
	adds r3, r1
	ldr r1, =gUnknown_082F1DE0
	adds r3, r1
	str r3, [sp]
	str r5, [sp, 0x4]
	add r4, r8
	str r4, [sp, 0x8]
	movs r1, 0x3
	movs r3, 0x6
	bl AddTextPrinterParameterized3
_0801CF1C:
	ldr r6, =gUnknown_02022C78
	ldr r4, [r6]
	movs r1, 0xE5
	lsls r1, 1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r3, r5, 4
	adds r3, 0x2
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0xDE
	lsls r2, 1
	adds r1, r4, r2
	ldr r1, [r1]
	ldrb r1, [r1]
	lsrs r1, 4
	lsls r2, r1, 1
	adds r2, r1
	ldr r1, =gUnknown_082F1DE0
	adds r2, r1
	str r2, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r5
	ldr r2, =0x000001f7
	adds r1, r2
	adds r4, r1
	str r4, [sp, 0x8]
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _0801CF1C
	ldr r0, [r6]
	movs r3, 0xE4
	lsls r3, 1
	adds r0, r3
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, [r6]
	movs r1, 0xE5
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CE7C

	thumb_func_start sub_801CFA4
sub_801CFA4: @ 801CFA4
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C78
	ldr r1, [r0]
	movs r2, 0xE1
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsrs r4, r0, 1
	lsls r4, 8
	ldr r6, =0x000001c3
	adds r0, r1, r6
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801CFE4
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	b _0801CFF8
	.pool
_0801CFE4:
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgY
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgY
_0801CFF8:
	ldr r3, =gUnknown_02022C78
	ldr r0, [r3]
	ldr r2, =0x000001c3
	adds r5, r0, r2
	ldrb r4, [r5]
	lsrs r1, r4, 1
	movs r6, 0xE1
	lsls r6, 1
	adds r0, r6
	ldrb r0, [r0]
	lsrs r0, 1
	adds r1, r0
	lsls r1, 1
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r5]
	ldr r1, [r3]
	adds r2, r1, r2
	ldrb r2, [r2]
	lsrs r0, r2, 1
	cmp r0, 0xF
	bls _0801D070
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	beq _0801D044
	movs r0, 0xE3
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	b _0801D04E
	.pool
_0801D044:
	movs r2, 0xE3
	lsls r2, 1
	adds r1, r2
	ldrh r0, [r1]
	subs r0, 0x1
_0801D04E:
	strh r0, [r1]
	ldr r0, [r3]
	movs r6, 0xE1
	lsls r6, 1
	adds r2, r0, r6
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldr r1, =0x000001c3
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	strb r0, [r2]
_0801D070:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CFA4

	.align 2, 0 @ don't pad with nop
