	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

@ file boundary?

	thumb_func_start sub_800DB84
sub_800DB84: @ 800DB84
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	movs r1, 0x80
	lsls r1, 2
	adds r0, r3, r1
	adds r1, 0x1
	adds r4, r3, r1
	ldrb r1, [r0]
	ldrb r0, [r4]
	cmp r1, r0
	beq _0800DBA6
	ldr r1, =0x00000203
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800DBB0
_0800DBA6:
	movs r0, 0
	b _0800DBEA
	.pool
_0800DBB0:
	movs r2, 0
_0800DBB2:
	adds r0, r5, r2
	ldrb r1, [r4]
	lsls r1, 8
	adds r1, r2, r1
	adds r1, r3, r1
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xFF
	ble _0800DBB2
	ldr r0, =0x00000201
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r0, =0x00000202
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0x1
_0800DBEA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800DB84

	thumb_func_start sub_800DBF8
sub_800DBF8: @ 800DBF8
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1, 0
	movs r5, 0
	cmp r1, 0x1
	beq _0800DC36
	cmp r1, 0x1
	bgt _0800DC12
	cmp r1, 0
	beq _0800DC1C
	b _0800DCAA
_0800DC12:
	cmp r0, 0x2
	beq _0800DC56
	cmp r0, 0x3
	beq _0800DC76
	b _0800DCAA
_0800DC1C:
	movs r4, 0
_0800DC1E:
	adds r0, r6, r4
	adds r1, r4, 0x1
	strb r1, [r0]
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, r1, 0
	cmp r4, 0xC7
	ble _0800DC1E
	b _0800DC70
_0800DC36:
	movs r4, 0
	adds r2, r6, 0
	adds r2, 0xC8
_0800DC3C:
	adds r0, r6, r4
	adds r1, r4, 0x1
	strb r1, [r0]
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, r1, 0
	cmp r4, 0x63
	ble _0800DC3C
	strh r5, [r2]
	b _0800DCAA
_0800DC56:
	movs r4, 0
_0800DC58:
	bl Random
	lsls r0, 24
	lsrs r0, 24
	adds r1, r6, r4
	strb r0, [r1]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x1
	cmp r4, 0xC7
	ble _0800DC58
_0800DC70:
	adds r0, r6, r4
	strh r5, [r0]
	b _0800DCAA
_0800DC76:
	movs r4, 0
	ldr r3, =gUnknown_03000D74
	ldrb r1, [r3]
	ldrb r0, [r3]
	adds r7, r0, 0x1
	adds r2, r1, 0x1
	movs r0, 0xFF
	mov r12, r0
_0800DC86:
	adds r0, r6, r4
	adds r1, r4, 0x1
	strb r2, [r0]
	adds r0, r4, r7
	mov r4, r12
	ands r0, r4
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r2, 0x1
	adds r4, r1, 0
	cmp r1, 0xC7
	ble _0800DC86
	adds r0, r6, r1
	strh r5, [r0]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_0800DCAA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DBF8

	thumb_func_start sub_800DCB4
sub_800DCB4: @ 800DCB4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0800DCD8
	ldr r5, =gUnknown_082ED470
	adds r2, r1, 0
_0800DCC4:
	adds r1, r4, r3
	ldrb r0, [r2]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	adds r3, 0x1
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _0800DCC4
_0800DCD8:
	adds r1, r4, r3
	movs r0, 0
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DCB4

	thumb_func_start sub_800DCE8
sub_800DCE8: @ 800DCE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800DD0C
	ldr r5, =gUnknown_082ED370
	adds r2, r1, 0
_0800DCF8:
	adds r1, r4, r3
	ldrb r0, [r2]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	adds r3, 0x1
	ldrb r0, [r2]
	cmp r0, 0
	bne _0800DCF8
_0800DD0C:
	adds r1, r4, r3
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DCE8

	thumb_func_start sub_800DD1C
sub_800DD1C: @ 800DD1C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r0, =gUnknown_03007890
	ldr r4, [r0]
	ldrb r2, [r4, 0x2]
	ldrb r1, [r4]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _0800DD72
	movs r3, 0
	ands r1, r2
	cmp r1, 0
	beq _0800DD4E
	cmp r5, 0x1
	bne _0800DD48
	ldrb r0, [r4, 0xA]
	b _0800DD8C
	.pool
_0800DD48:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0800DD4E:
	lsrs r2, 1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bhi _0800DD8A
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0800DD4E
	adds r0, r6, 0x1
	cmp r5, r0
	bne _0800DD48
_0800DD68:
	ldr r0, [r7]
	adds r0, 0xA
	adds r0, r3
	ldrb r0, [r0]
	b _0800DD8C
_0800DD72:
	movs r3, 0
	movs r1, 0x1
_0800DD76:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0800DD68
	lsrs r2, 1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800DD76
_0800DD8A:
	movs r0, 0
_0800DD8C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800DD1C

	thumb_func_start sub_800DD94
sub_800DD94: @ 800DD94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r4, 0
	ldr r0, =gSaveBlock2Ptr
	mov r8, r0
	adds r6, r7, 0x2
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0xA
_0800DDB2:
	adds r0, r6, r4
	adds r1, r5, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x1
	ble _0800DDB2
	movs r4, 0
	lsls r2, 7
	mov r12, r2
	adds r1, r7, 0x4
_0800DDC8:
	adds r0, r1, r4
	strb r3, [r0]
	asrs r3, 8
	adds r4, 0x1
	cmp r4, 0x3
	ble _0800DDC8
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	movs r6, 0x1
	movs r1, 0x1
	ands r1, r0
	ldrb r2, [r7, 0xB]
	movs r5, 0x2
	negs r5, r5
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0xB]
	movs r4, 0x7F
	mov r1, r9
	ands r1, r4
	ldrb r2, [r7, 0xA]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	ands r0, r4
	mov r1, r12
	orrs r0, r1
	strb r0, [r7, 0xA]
	ldrb r0, [r7]
	movs r1, 0x10
	negs r1, r1
	ands r1, r0
	movs r0, 0x2
	orrs r1, r0
	ldrb r2, [r7, 0x1]
	movs r0, 0x3D
	negs r0, r0
	ands r0, r2
	movs r2, 0xC
	orrs r0, r2
	strb r0, [r7, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r1, r0
	subs r0, 0x10
	ands r1, r0
	subs r0, 0x20
	ands r1, r0
	strb r1, [r7]
	ldr r0, =0x0000087f
	bl FlagGet
	lsls r0, 7
	ldrb r1, [r7]
	ands r4, r1
	orrs r4, r0
	strb r4, [r7]
	bl IsNationalPokedexEnabled
	ands r0, r6
	ldrb r1, [r7, 0x1]
	ands r5, r1
	orrs r5, r0
	strb r5, [r7, 0x1]
	ldr r0, =0x00000864
	bl FlagGet
	ands r6, r0
	lsls r6, 1
	ldrb r1, [r7, 0x1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	orrs r0, r6
	strb r0, [r7, 0x1]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DD94

	thumb_func_start sub_800DE7C
sub_800DE7C: @ 800DE7C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r5, r2, 24
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x6]
	cmp r0, 0x1
	bne _0800DED8
	movs r0, 0x1
	mov r9, r0
	ldr r6, =gUnknown_03007890
	ldr r0, [r6]
	lsls r4, r5, 5
	adds r0, r4
	ldrh r0, [r0, 0x18]
	bl sub_8010454
	cmp r0, 0
	beq _0800DEB8
	ldr r1, [r6]
	ldrb r0, [r1, 0x7]
	asrs r0, r5
	mov r2, r9
	ands r0, r2
	cmp r0, 0
	bne _0800DEF0
_0800DEB8:
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0xD
	bl memset
	mov r0, r8
	movs r1, 0
	movs r2, 0x8
	bl memset
	b _0800DF24
	.pool
_0800DED8:
	movs r0, 0
	mov r9, r0
	ldr r6, =gUnknown_03007890
	ldr r0, [r6]
	lsls r4, r5, 5
	adds r0, r4
	ldrh r0, [r0, 0x18]
	bl sub_8010454
	cmp r0, 0
	beq _0800DF10
	ldr r1, [r6]
_0800DEF0:
	adds r1, r4, r1
	adds r1, 0x1A
	adds r0, r7, 0
	movs r2, 0xD
	bl memcpy
	ldr r1, [r6]
	adds r1, r4, r1
	adds r1, 0x29
	mov r0, r8
	movs r2, 0x8
	bl memcpy
	b _0800DF24
	.pool
_0800DF10:
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0xD
	bl memset
	mov r0, r8
	movs r1, 0
	movs r2, 0x8
	bl memset
_0800DF24:
	mov r0, r9
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800DE7C

	thumb_func_start sub_800DF34
sub_800DF34: @ 800DF34
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	movs r7, 0
	ldr r6, =gUnknown_03007890
	ldr r0, [r6]
	lsrs r4, r2, 19
	adds r2, r0, r4
	ldrh r1, [r2, 0x18]
	ldr r0, =0x00007f7d
	cmp r1, r0
	bne _0800DF74
	adds r1, r2, 0
	adds r1, 0x1A
	adds r0, r3, 0
	movs r2, 0xD
	bl memcpy
	ldr r1, [r6]
	adds r1, r4, r1
	adds r1, 0x29
	adds r0, r5, 0
	movs r2, 0x8
	bl memcpy
	movs r7, 0x1
	b _0800DF88
	.pool
_0800DF74:
	adds r0, r3, 0
	movs r1, 0
	movs r2, 0xD
	bl memset
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
_0800DF88:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800DF34

	thumb_func_start sub_800DF90
sub_800DF90: @ 800DF90
	push {r4,lr}
	adds r4, r1, 0
	ldr r1, =gUnknown_02022B14
	movs r2, 0xD
	bl memcpy
	ldr r1, =gUnknown_02022B14 + 0xE
	adds r0, r4, 0
	movs r2, 0x8
	bl memcpy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DF90

	thumb_func_start sub_800DFB4
sub_800DFB4: @ 800DFB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r3, 0
	bne _0800DFCA
	cmp r2, 0
	bne _0800DFCA
	movs r3, 0xE7
	movs r2, 0x8
_0800DFCA:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800E024
	ldr r0, =gUnknown_082ED5F0
	adds r1, r3, 0
	movs r3, 0
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r4, r0
	ldr r0, =0x00001234
	strh r0, [r4, 0x3C]
	ldr r0, =gUnknown_082ED5E0
	ldrh r0, [r0, 0x6]
	bl GetSpriteTileStartByTag
	strh r0, [r4, 0x3A]
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	ldr r0, =gUnknown_02022B10
	strb r5, [r0]
	b _0800E06A
	.pool
_0800E024:
	ldr r0, =gUnknown_082ED5F0
	adds r1, r3, 0
	movs r3, 0
	bl CreateSprite
	ldr r4, =gUnknown_02022B10
	strb r0, [r4]
	ldr r5, =gSprites
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x00001234
	strh r1, [r0, 0x3C]
	ldr r0, =gUnknown_082ED5E0
	ldrh r0, [r0, 0x6]
	bl GetSpriteTileStartByTag
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	strh r0, [r1, 0x3A]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0800E06A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DFB4

	thumb_func_start sub_800E084
sub_800E084: @ 800E084
	push {r4,lr}
	ldr r4, =gSprites
	ldr r3, =gUnknown_02022B10
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r4
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	ldr r0, =0x00001234
	cmp r1, r0
	bne _0800E0CA
	movs r0, 0
	strh r0, [r2, 0x3C]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r3, =gMain
	movs r0, 0x84
	lsls r0, 3
	adds r3, r0
	ldr r0, =gDummyOamData
	ldr r1, [r0]
	ldr r2, [r0, 0x4]
	str r1, [r3]
	str r2, [r3, 0x4]
	ldr r1, =0x070003e8
	movs r2, 0x4
	bl CpuSet
_0800E0CA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E084

	thumb_func_start sub_800E0E8
sub_800E0E8: @ 800E0E8
	push {r4,lr}
	ldr r4, =gUnknown_082ED5E0
	ldrh r0, [r4, 0x6]
	bl GetSpriteTileStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _0800E100
	adds r0, r4, 0
	bl LoadCompressedObjectPic
_0800E100:
	ldr r0, =gUnknown_082ED5E8
	bl LoadSpritePalette
	ldr r1, =gUnknown_02022B10
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E0E8

	thumb_func_start sub_800E124
sub_800E124: @ 800E124
	push {r4,lr}
	ldr r1, =gUnknown_03007890
	ldr r0, [r1]
	ldrb r2, [r0, 0x2]
	movs r3, 0
	movs r4, 0x1
_0800E130:
	adds r0, r2, 0
	ands r0, r4
	cmp r0, 0
	beq _0800E148
	ldr r0, [r1]
	adds r0, 0xA
	adds r0, r3
	ldrb r0, [r0]
	b _0800E156
	.pool
_0800E148:
	lsrs r2, 1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800E130
	movs r0, 0
_0800E156:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800E124

	thumb_func_start sub_800E15C
sub_800E15C: @ 800E15C
	push {lr}
	adds r2, r0, 0
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	cmp r0, r1
	beq _0800E170
	movs r0, 0
	strh r1, [r2, 0x32]
	strh r0, [r2, 0x34]
	strh r0, [r2, 0x36]
_0800E170:
	pop {r0}
	bx r0
	thumb_func_end sub_800E15C

	thumb_func_start sub_800E174
sub_800E174: @ 800E174
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, =gUnknown_02022B10
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0800E184
	b _0800E346
_0800E184:
	ldr r2, =gSprites
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	ldr r0, =0x00001234
	cmp r1, r0
	beq _0800E19C
	b _0800E346
_0800E19C:
	adds r6, r2, 0
	movs r5, 0xFF
	movs r4, 0
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800E1F6
	adds r7, r6, 0
	adds r7, 0x28
	movs r1, 0x29
	adds r1, r6
	mov r8, r1
	b _0800E1E6
	.pool
_0800E1C8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_800DD1C
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bcc _0800E1E6
	adds r0, r4, 0
	bl sub_800DD1C
	lsls r0, 24
	lsrs r5, r0, 24
_0800E1E6:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r4, r0
	blt _0800E1C8
	b _0800E208
_0800E1F6:
	bl sub_800E124
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r6, 0
	adds r7, 0x28
	movs r2, 0x29
	adds r2, r6
	mov r8, r2
_0800E208:
	bl sub_8012224
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0800E218
	movs r0, 0x4
	b _0800E246
_0800E218:
	cmp r5, 0x18
	bhi _0800E220
	movs r0, 0x3
	b _0800E246
_0800E220:
	adds r0, r5, 0
	subs r0, 0x19
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x65
	bhi _0800E230
	movs r0, 0x2
	b _0800E246
_0800E230:
	adds r0, r5, 0
	subs r0, 0x7F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x65
	bhi _0800E240
	movs r0, 0x1
	b _0800E246
_0800E240:
	cmp r5, 0xE4
	bls _0800E248
	movs r0, 0
_0800E246:
	strh r0, [r6, 0x2E]
_0800E248:
	movs r3, 0x2E
	ldrsh r1, [r6, r3]
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	cmp r1, r0
	beq _0800E25E
	adds r0, r6, 0
	bl sub_800E15C
	ldrh r0, [r6, 0x2E]
	strh r0, [r6, 0x30]
_0800E25E:
	movs r0, 0x32
	ldrsh r1, [r6, r0]
	ldr r2, [r6, 0x8]
	lsls r1, 2
	adds r1, r2
	movs r3, 0x36
	ldrsh r0, [r6, r3]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r0, 10
	lsrs r0, 26
	movs r3, 0x34
	ldrsh r1, [r6, r3]
	cmp r0, r1
	bge _0800E2AC
	ldrh r0, [r6, 0x36]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r6, 0x36]
	strh r3, [r6, 0x34]
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 2
	adds r0, r2
	movs r2, 0x36
	ldrsh r1, [r6, r2]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	bne _0800E2B2
	strh r3, [r6, 0x36]
	b _0800E2B2
_0800E2AC:
	ldrh r0, [r6, 0x34]
	adds r0, 0x1
	strh r0, [r6, 0x34]
_0800E2B2:
	ldr r4, =gMain
	movs r1, 0x84
	lsls r1, 3
	adds r0, r4, r1
	ldr r1, =gUnknown_082ED570
	ldr r2, [r1, 0x4]
	ldr r1, [r1]
	str r1, [r0]
	str r2, [r0, 0x4]
	movs r3, 0x20
	ldrsh r2, [r6, r3]
	movs r1, 0
	ldrsb r1, [r7, r1]
	adds r2, r1
	ldr r1, =0x00000422
	adds r5, r4, r1
	ldr r3, =0x000001ff
	adds r1, r3, 0
	ands r2, r1
	ldrh r3, [r5]
	ldr r1, =0xfffffe00
	ands r1, r3
	orrs r1, r2
	strh r1, [r5]
	ldrh r1, [r6, 0x22]
	mov r2, r8
	ldrb r2, [r2]
	adds r1, r2
	strb r1, [r0]
	ldrb r2, [r6, 0x5]
	ldr r3, =0x00000425
	adds r5, r4, r3
	lsrs r2, 4
	lsls r2, 4
	ldrb r3, [r5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r2
	strb r1, [r5]
	movs r1, 0x32
	ldrsh r2, [r6, r1]
	ldr r1, [r6, 0x8]
	lsls r2, 2
	adds r2, r1
	movs r3, 0x36
	ldrsh r1, [r6, r3]
	ldr r2, [r2]
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1]
	ldrh r6, [r6, 0x3A]
	adds r2, r6
	ldr r1, =0x00000424
	adds r4, r1
	ldr r3, =0x000003ff
	adds r1, r3, 0
	ands r2, r1
	ldrh r3, [r4]
	ldr r1, =0xfffffc00
	ands r1, r3
	orrs r1, r2
	strh r1, [r4]
	ldr r1, =0x070003e8
	movs r2, 0x4
	bl CpuSet
	bl sub_8011A74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0800E346
	bl sub_800E084
_0800E346:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E174

	thumb_func_start sub_800E378
sub_800E378: @ 800E378
	push {lr}
	stm r0!, {r1}
	adds r1, r2, 0
	bl StringCopy
	pop {r0}
	bx r0
	thumb_func_end sub_800E378

	thumb_func_start sub_800E388
sub_800E388: @ 800E388
	push {lr}
	adds r2, r0, 0
	movs r1, 0
_0800E38E:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800E39A
	movs r0, 0x1
	b _0800E3A2
_0800E39A:
	adds r1, 0x1
	cmp r1, 0x7
	ble _0800E38E
	movs r0, 0
_0800E3A2:
	pop {r1}
	bx r1
	thumb_func_end sub_800E388

	thumb_func_start sub_800E3A8
sub_800E3A8: @ 800E3A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800E3BE
	b _0800E520
_0800E3BE:
	movs r0, 0xF0
	bl AllocZeroed
	str r0, [sp, 0x14]
	movs r4, 0
	b _0800E434
	.pool
_0800E3D0:
	lsls r2, r4, 2
	mov r0, sp
	adds r1, r0, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	movs r5, 0
	mov r8, r2
	lsls r0, r4, 3
	adds r1, r4, 0x1
	mov r9, r1
	subs r0, r4
	lsls r0, 2
	str r0, [sp, 0x1C]
	ldr r7, =gLinkPlayers + 8
	mov r10, r7
	ldr r6, =0x00003b98
	movs r4, 0
	mov r0, r10
	subs r0, 0x4
	ldr r1, [sp, 0x1C]
	adds r3, r1, r0
_0800E3FC:
	ldrh r1, [r3]
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r7, =0x00003b98
	adds r0, r2, r7
	adds r0, r4
	ldr r0, [r0]
	cmp r1, r0
	bne _0800E428
	adds r1, r2, r6
	adds r1, 0x4
	ldr r0, [sp, 0x1C]
	add r0, r10
	str r3, [sp, 0x18]
	bl StringCompare
	ldr r3, [sp, 0x18]
	cmp r0, 0
	bne _0800E428
	mov r0, sp
	add r0, r8
	str r5, [r0]
_0800E428:
	adds r6, 0xC
	adds r4, 0xC
	adds r5, 0x1
	cmp r5, 0x13
	ble _0800E3FC
	mov r4, r9
_0800E434:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _0800E3D0
	movs r0, 0
	mov r8, r0
	movs r4, 0
	mov r7, sp
	movs r5, 0
	ldr r6, [sp, 0x14]
	b _0800E4AC
	.pool
_0800E45C:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _0800E4A6
	ldr r2, =gLinkPlayers
	adds r0, r5, r2
	ldrh r0, [r0, 0x1A]
	cmp r0, 0x1
	beq _0800E4A6
	adds r0, r2, 0x4
	adds r0, r5, r0
	ldrh r1, [r0]
	adds r2, 0x8
	adds r2, r5, r2
	adds r0, r6, 0
	bl sub_800E378
	ldr r2, [r7]
	cmp r2, 0
	blt _0800E4A0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldr r1, =0x00003b9c
	adds r0, r1
	movs r1, 0
	movs r2, 0x8
	bl memset
_0800E4A0:
	adds r6, 0xC
	movs r0, 0x1
	add r8, r0
_0800E4A6:
	adds r7, 0x4
	adds r5, 0x1C
	adds r4, 0x1
_0800E4AC:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _0800E45C
	movs r4, 0
	ldr r1, =gSaveBlock1Ptr
	mov r9, r1
	ldr r6, =0x00003b98
	movs r7, 0
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 2
	ldr r1, [sp, 0x14]
	adds r5, r0, r1
_0800E4CE:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r6
	adds r0, 0x4
	bl sub_800E388
	cmp r0, 0
	beq _0800E500
	mov r0, r9
	ldr r2, [r0]
	ldr r1, =0x00003b98
	adds r0, r2, r1
	adds r0, r7
	ldr r1, [r0]
	adds r2, r6
	adds r2, 0x4
	adds r0, r5, 0
	bl sub_800E378
	adds r5, 0xC
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x13
	bgt _0800E50A
_0800E500:
	adds r6, 0xC
	adds r7, 0xC
	adds r4, 0x1
	cmp r4, 0x13
	ble _0800E4CE
_0800E50A:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r7, =0x00003b98
	adds r0, r7
	ldr r1, [sp, 0x14]
	movs r2, 0xF0
	bl memcpy
	ldr r0, [sp, 0x14]
	bl Free
_0800E520:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E3A8

	thumb_func_start sub_800E540
sub_800E540: @ 800E540
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	movs r7, 0
	ldr r6, =gSaveBlock1Ptr
	ldr r4, =0x00003b98
	movs r5, 0
_0800E558:
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x4
	mov r1, r9
	bl StringCompare
	cmp r0, 0
	bne _0800E584
	ldr r0, [r6]
	ldr r1, =0x00003b98
	adds r0, r1
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r8
	bne _0800E584
	movs r0, 0x1
	b _0800E59E
	.pool
_0800E584:
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x4
	bl sub_800E388
	cmp r0, 0
	beq _0800E59C
	adds r4, 0xC
	adds r5, 0xC
	adds r7, 0x1
	cmp r7, 0x13
	ble _0800E558
_0800E59C:
	movs r0, 0
_0800E59E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E540

	thumb_func_start sub_800E5AC
sub_800E5AC: @ 800E5AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r0, =0x00003b98
	mov r8, r0
	movs r7, 0
	mov r6, r8
	movs r5, 0
	movs r4, 0x13
_0800E5C0:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	mov r2, r8
	adds r0, r1, r2
	adds r0, r5
	str r7, [r0]
	mov r0, sp
	strh r7, [r0]
	adds r1, r6
	adds r1, 0x4
	ldr r2, =0x01000004
	bl CpuSet
	adds r6, 0xC
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _0800E5C0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E5AC

@ file boundary?

	thumb_func_start nullsub_5
nullsub_5: @ 800E5FC
	bx lr
	thumb_func_end nullsub_5

	thumb_func_start nullsub_13
nullsub_13: @ 800E600
	bx lr
	thumb_func_end nullsub_13

	thumb_func_start sub_800E604
sub_800E604: @ 800E604
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r6, =gUnknown_03005000
	adds r5, r6, 0
	adds r5, 0xEE
	ldrb r4, [r5]
	mov r0, sp
	movs r7, 0
	strh r7, [r0]
	ldr r2, =0x0100067a
	adds r1, r6, 0
	bl CpuSet
	ldrb r0, [r5]
	strb r4, [r5]
	movs r0, 0xFF
	strb r0, [r6, 0xC]
	ldrb r0, [r5]
	cmp r0, 0x4
	beq _0800E636
	ldrb r0, [r5]
	strb r7, [r5]
_0800E636:
	mov r7, sp
	adds r7, 0x2
	add r0, sp, 0x4
	mov r8, r0
	movs r0, 0x6
	add r0, sp
	mov r9, r0
	adds r5, r6, 0
	adds r5, 0x80
	movs r4, 0x4
_0800E64A:
	adds r0, r5, 0
	bl sub_800FCC4
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _0800E64A
	movs r5, 0
	ldr r4, =gUnknown_03005000+0x6C
	adds r0, r4, 0
	bl sub_800FCC4
	adds r0, r4, 0
	adds r0, 0xB8
	bl sub_800D6C8
	ldr r0, =0x0000097c
	adds r4, r0
	adds r0, r4, 0
	bl sub_800D724
	strh r5, [r7]
	ldr r1, =gSendCmd
	ldr r2, =0x01000008
	adds r0, r7, 0
	bl CpuSet
	mov r0, r8
	strh r5, [r0]
	ldr r1, =gRecvCmds
	ldr r2, =0x01000028
	bl CpuSet
	mov r0, r9
	strh r5, [r0]
	ldr r1, =gLinkPlayers
	ldr r2, =0x01000046
	bl CpuSet
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E604

	thumb_func_start sub_800E6D0
sub_800E6D0: @ 800E6D0
	push {r4-r6,lr}
	ldr r4, =gIntrTable
	ldr r5, [r4, 0x4]
	ldr r6, [r4, 0x8]
	bl sub_800E700
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	ldr r1, =0x04000208
	movs r0, 0
	strh r0, [r1]
	str r5, [r4, 0x4]
	str r6, [r4, 0x8]
	movs r0, 0x1
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E6D0

	thumb_func_start sub_800E700
sub_800E700: @ 800E700
	push {r4,lr}
	ldr r0, =gUnknown_03004140+0x50
	ldr r1, =0x00000e64
	ldr r4, =gIntrTable + 0x4
	adds r2, r4, 0
	movs r3, 0x1
	bl rfu_initializeAPI
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _0800E732
	ldr r0, =gLinkType
	strh r1, [r0]
	bl sub_800AAF4
	movs r0, 0
	bl sub_80111B0
	bl sub_800E604
	adds r1, r4, 0x4
	movs r0, 0x3
	bl rfu_setTimerInterrupt
_0800E732:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E700

	thumb_func_start sub_800E748
sub_800E748: @ 800E748
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8010750
	ldr r0, =gUnknown_03005000
	ldrh r0, [r0, 0x4]
	cmp r0, 0x12
	bls _0800E75C
	b _0800E862
_0800E75C:
	lsls r0, 2
	ldr r1, =_0800E770
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800E770:
	.4byte _0800E7BC
	.4byte _0800E862
	.4byte _0800E7E4
	.4byte _0800E862
	.4byte _0800E814
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E862
	.4byte _0800E828
_0800E7BC:
	ldr r0, =gUnknown_02022B2C
	bl sub_800BFCC
	ldr r0, =gUnknown_03005000
	movs r2, 0x1
	strh r2, [r0, 0x4]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0xA]
	b _0800E862
	.pool
_0800E7E4:
	ldr r4, =gUnknown_03005000
	ldrb r0, [r4, 0xC]
	ldr r3, =gUnknown_082ED6E0
	movs r1, 0
	movs r2, 0xF0
	bl sub_800C054
	movs r0, 0x3
	strh r0, [r4, 0x4]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x6
	strh r1, [r0, 0xA]
	b _0800E862
	.pool
_0800E814:
	movs r0, 0
	bl sub_800C27C
	ldr r1, =gUnknown_03005000
	movs r0, 0x5
	strh r0, [r1, 0x4]
	b _0800E862
	.pool
_0800E828:
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000cdb
	adds r1, r4, r0
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r0, =sub_800EDBC
	bl sub_800D52C
	bl sub_800EAB4
	bl sub_800EAFC
	movs r0, 0x14
	strh r0, [r4, 0x4]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	strh r1, [r0, 0xA]
	ldr r0, =sub_801084C
	movs r1, 0x5
	bl CreateTask
	adds r0, r5, 0
	bl DestroyTask
_0800E862:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E748

	thumb_func_start sub_800E87C
sub_800E87C: @ 800E87C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_082ED6A5
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800E87C

	thumb_func_start sub_800E88C
sub_800E88C: @ 800E88C
	push {r4-r7,lr}
	adds r2, r0, 0
	adds r5, r1, 0
	movs r4, 0x1
	adds r1, r2, 0
	movs r6, 0
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0800E8CC
	movs r3, 0
	movs r5, 0x1
	ldr r1, =gUnknown_03005000+0xCDE
_0800E8A6:
	adds r0, r2, 0
	ands r0, r5
	cmp r0, 0
	beq _0800E8B8
	adds r0, r3, r1
	strb r4, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_0800E8B8:
	asrs r2, 1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800E8A6
	b _0800E942
	.pool
_0800E8CC:
	movs r3, 0
	mvns r0, r1
	mov r12, r0
	movs r7, 0x1
	ldr r4, =gUnknown_03005000+0xCDE
_0800E8D6:
	adds r2, r1, 0
	ands r2, r7
	cmp r2, 0
	bne _0800E8E2
	adds r0, r3, r4
	strb r2, [r0]
_0800E8E2:
	asrs r1, 1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800E8D6
	movs r4, 0x4
	ldr r0, =gUnknown_03005000+0xCDE
	ldrb r7, [r0]
_0800E8F4:
	movs r3, 0
	subs r1, r4, 0x1
	cmp r7, r4
	beq _0800E910
	ldr r2, =gUnknown_03005000+0xCDE
_0800E8FE:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bhi _0800E910
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, r4
	bne _0800E8FE
_0800E910:
	cmp r3, 0x4
	bne _0800E916
	adds r6, r4, 0
_0800E916:
	lsls r0, r1, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0800E8F4
	mov r0, r12
	ands r5, r0
	movs r3, 0
	movs r2, 0x1
	ldr r1, =gUnknown_03005000+0xCDE
_0800E928:
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _0800E936
	adds r0, r3, r1
	strb r6, [r0]
	adds r6, 0x1
_0800E936:
	asrs r5, 1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800E928
_0800E942:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E88C

	thumb_func_start sub_800E94C
sub_800E94C: @ 800E94C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_03005000
	ldrh r3, [r0, 0x4]
	adds r7, r0, 0
	cmp r3, 0xC
	bls _0800E95E
	b _0800EA9A
_0800E95E:
	lsls r0, r3, 2
	ldr r1, =_0800E970
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800E970:
	.4byte _0800E9A4
	.4byte _0800EA9A
	.4byte _0800EA9A
	.4byte _0800EA9A
	.4byte _0800EA9A
	.4byte _0800EA9A
	.4byte _0800E9BC
	.4byte _0800EA9A
	.4byte _0800EA9A
	.4byte _0800E9E4
	.4byte _0800EA9A
	.4byte _0800E9F8
	.4byte _0800EA3C
_0800E9A4:
	ldr r0, =gUnknown_082ED608
	bl sub_800BFCC
	ldr r0, =gUnknown_03005000
	movs r2, 0x1
	strh r2, [r0, 0x4]
	b _0800E9CC
	.pool
_0800E9BC:
	ldrb r0, [r7, 0xC]
	ldr r3, =gUnknown_082ED6E0
	movs r1, 0
	movs r2, 0xF0
	bl sub_800C054
	movs r2, 0x7
	strh r2, [r7, 0x4]
_0800E9CC:
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0xA]
	b _0800EA9A
	.pool
_0800E9E4:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0xA
	strh r0, [r1, 0xA]
	b _0800EA9A
	.pool
_0800E9F8:
	bl sub_80107A0
	cmp r0, 0x6
	beq _0800EA1C
	cmp r0, 0x6
	bgt _0800EA0A
	cmp r0, 0x5
	beq _0800EA10
	b _0800EA9A
_0800EA0A:
	cmp r0, 0x9
	beq _0800EA1C
	b _0800EA9A
_0800EA10:
	ldr r1, =gUnknown_03005000
	movs r0, 0xC
	strh r0, [r1, 0x4]
	b _0800EA9A
	.pool
_0800EA1C:
	bl sub_800D630
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce4
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r6, 0
	bl DestroyTask
	b _0800EA9A
	.pool
_0800EA3C:
	ldr r0, =0x00000c3e
	adds r4, r7, r0
	ldrb r0, [r4]
	movs r5, 0x80
	lsls r5, 17
	lsls r5, r0
	lsrs r5, 24
	ldrb r1, [r4]
	movs r0, 0xC
	bl rfu_clearSlot
	ldrb r1, [r4]
	ldr r0, =0x00000c3f
	adds r2, r7, r0
	movs r0, 0x10
	movs r3, 0x46
	bl rfu_setRecvBuffer
	adds r1, r7, 0
	adds r1, 0x4C
	adds r0, r5, 0
	movs r2, 0xE
	bl rfu_UNI_setSendData
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	strh r1, [r0, 0xA]
	adds r0, r6, 0
	bl DestroyTask
	ldr r4, =gUnknown_02022B44
	ldrb r0, [r4, 0xF]
	cmp r0, 0
	bne _0800EA92
	bl sub_801227C
	ldrb r0, [r4, 0xF]
	adds r0, 0x1
	strb r0, [r4, 0xF]
_0800EA92:
	ldr r0, =sub_801084C
	movs r1, 0x5
	bl CreateTask
_0800EA9A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800E94C

	thumb_func_start sub_800EAB4
sub_800EAB4: @ 800EAB4
	push {r4,r5,lr}
	ldr r0, =gUnknown_03004140
	ldrb r5, [r0]
	movs r4, 0
_0800EABC:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0800EAE0
	lsls r2, r4, 3
	subs r2, r4
	lsls r2, 1
	ldr r0, =gUnknown_03005000+0x14
	adds r2, r0
	movs r0, 0x10
	adds r1, r4, 0
	movs r3, 0xE
	bl rfu_setRecvBuffer
	movs r0, 0x3
	adds r1, r4, 0
	bl rfu_clearSlot
_0800EAE0:
	lsrs r5, 1
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800EABC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EAB4

	thumb_func_start sub_800EAFC
sub_800EAFC: @ 800EAFC
	push {r4-r6,lr}
	ldr r0, =gUnknown_03004140
	ldrb r5, [r0]
	ldr r4, =gUnknown_03005000+0xC87
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x46
	bl rfu_UNI_setSendData
	adds r0, r5, 0
	bl sub_800E87C
	ldr r1, =0xfffff379
	adds r6, r4, r1
	adds r1, r4, 0
	adds r1, 0x53
	strb r0, [r1]
	adds r4, 0x5B
	strb r5, [r4]
	movs r1, 0x1
	negs r1, r1
	adds r0, r5, 0
	bl sub_800E88C
	movs r0, 0x1
	strb r0, [r6, 0xC]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EAFC

	thumb_func_start sub_800EB44
sub_800EB44: @ 800EB44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x54
	bne _0800EB78
	bl sub_8011A74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _0800EB78
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, 0
	movs r1, 0
	bl sub_8011A64
_0800EB78:
	ldr r0, =gUnknown_03005000
	ldrh r2, [r0, 0x4]
	adds r6, r0, 0
	cmp r2, 0x12
	bls _0800EB84
	b _0800ECF4
_0800EB84:
	lsls r0, r2, 2
	ldr r1, =_0800EB9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800EB9C:
	.4byte _0800EBE8
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800ECF4
	.4byte _0800EC38
	.4byte _0800EC98
	.4byte _0800ECF4
	.4byte _0800ECAC
	.4byte _0800EC10
	.4byte _0800ECF4
_0800EBE8:
	ldr r0, =gUnknown_02022B2C
	bl sub_800BFCC
	ldr r0, =gUnknown_03005000
	movs r2, 0x1
	strh r2, [r0, 0x4]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0xA]
	b _0800ECF4
	.pool
_0800EC10:
	ldr r3, =gUnknown_082ED6E0
	movs r0, 0x2
	movs r1, 0
	movs r2, 0xF0
	bl sub_800C054
	ldr r0, =sub_800ED34
	bl sub_800D52C
	ldr r1, =gUnknown_03005000
	movs r0, 0x12
	strh r0, [r1, 0x4]
	b _0800ECF4
	.pool
_0800EC38:
	ldr r1, =0x00000c3e
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r0, 24
	adds r1, r6, 0
	adds r1, 0x4C
	movs r2, 0xE
	bl rfu_UNI_setSendData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _0800ECF4
	strb r0, [r6, 0xC]
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x16
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0800EC88
	ldr r0, =sub_8010D0C
	movs r1, 0x1
	bl CreateTask
	b _0800ECF4
	.pool
_0800EC88:
	ldr r0, =sub_801084C
	movs r1, 0x5
	bl CreateTask
	b _0800ECF4
	.pool
_0800EC98:
	movs r0, 0
	bl sub_800C27C
	ldr r1, =gUnknown_03005000
	movs r0, 0xF
	strh r0, [r1, 0x4]
	b _0800ECF4
	.pool
_0800ECAC:
	ldr r0, =0x00000cdb
	adds r1, r6, r0
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r0, =sub_800EDBC
	bl sub_800D52C
	movs r0, 0x1
	bl sub_8011068
	bl sub_800EAB4
	bl sub_800EAFC
	movs r0, 0x14
	strh r0, [r6, 0x4]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	strh r1, [r0, 0xA]
	movs r4, 0x1
	strb r4, [r6, 0xC]
	ldr r0, =sub_801084C
	movs r1, 0x5
	bl CreateTask
	ldr r1, =0x00000ce8
	adds r0, r6, r1
	strb r4, [r0]
	adds r0, r5, 0
	bl DestroyTask
_0800ECF4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EB44

	thumb_func_start sub_800ED10
sub_800ED10: @ 800ED10
	push {lr}
	ldr r3, =gUnknown_082ED6E0
	movs r0, 0x1
	movs r1, 0
	movs r2, 0xF0
	bl sub_800C054
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800ED10

	thumb_func_start sub_800ED28
sub_800ED28: @ 800ED28
	push {lr}
	movs r0, 0
	bl sub_800C27C
	pop {r0}
	bx r0
	thumb_func_end sub_800ED28

	thumb_func_start sub_800ED34
sub_800ED34: @ 800ED34
	push {r4,lr}
	ldr r0, =gUnknown_03005000
	movs r2, 0
	movs r1, 0xD
	adds r0, 0x59
_0800ED3E:
	strb r2, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _0800ED3E
	bl rfu_REQ_recvData
	bl rfu_waitREQComplete
	ldr r1, =gUnknown_03007870
	ldr r3, =gUnknown_03005000
	ldr r0, =0x00000c3e
	adds r4, r3, r0
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x12]
	cmp r0, 0
	beq _0800ED9A
	movs r2, 0xCD
	lsls r2, 4
	adds r1, r3, r2
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	adds r0, r3, r1
	ldr r2, =0x00000c3f
	adds r1, r3, r2
	bl sub_800D7D8
	ldr r1, =gUnknown_02022B44
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	bl sub_800F048
	ldrb r0, [r4]
	bl rfu_UNI_readySendData
	ldrb r0, [r4]
	bl rfu_UNI_clearRecvNewDataFlag
_0800ED9A:
	movs r0, 0x1
	bl rfu_REQ_sendData_wrapper
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800ED34

	thumb_func_start sub_800EDBC
sub_800EDBC: @ 800EDBC
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cdb
	adds r0, r1
	ldrb r1, [r0]
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_800EDBC

	thumb_func_start sub_800EDD4
sub_800EDD4: @ 800EDD4
	push {r4-r6,lr}
	bl sub_800C048
	ldr r4, =gUnknown_03005000
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	bne _0800EDF0
	ldr r0, =sub_800E748
	b _0800EDF6
	.pool
_0800EDF0:
	cmp r0, 0
	bne _0800EE18
	ldr r0, =sub_800E94C
_0800EDF6:
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0800EE38
	adds r0, r4, 0
	adds r0, 0x67
	ldrb r0, [r0]
	bl DestroyTask
	bl sub_800E604
	b _0800EE38
	.pool
_0800EE18:
	cmp r0, 0x2
	bne _0800EE38
	ldr r0, =sub_800EB44
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0800EE38
	adds r0, r4, 0
	adds r0, 0x67
	ldrb r0, [r0]
	bl DestroyTask
	bl sub_800E604
_0800EE38:
	movs r5, 0
	ldr r6, =gUnknown_082ED7E0
_0800EE3C:
	lsls r0, r5, 2
	adds r0, r6
	ldr r4, [r0]
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0800EE5E
	adds r0, r4, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0800EE5E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _0800EE3C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EDD4

	thumb_func_start sub_800EE78
sub_800EE78: @ 800EE78
	push {lr}
	ldr r0, =sub_800E748
	movs r1, 0x1
	bl CreateTask
	ldr r1, =gUnknown_03005000
	adds r1, 0x67
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EE78

	thumb_func_start sub_800EE94
sub_800EE94: @ 800EE94
	push {lr}
	ldr r1, =gUnknown_03005000
	ldrh r0, [r1, 0x4]
	cmp r0, 0x7
	bne _0800EEB4
	ldr r2, =0x00000ccd
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800EEB4
	movs r0, 0x1
	b _0800EEB6
	.pool
_0800EEB4:
	movs r0, 0
_0800EEB6:
	pop {r1}
	bx r1
	thumb_func_end sub_800EE94

	thumb_func_start sub_800EEBC
sub_800EEBC: @ 800EEBC
	push {r4,lr}
	ldr r4, =gUnknown_03005000
	ldrh r0, [r4, 0x4]
	cmp r0, 0x7
	bne _0800EEF8
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	ldr r2, =0x00000c3d
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, 5
	adds r1, r0
	ldrh r0, [r1, 0x14]
	movs r1, 0xF0
	bl sub_800C12C
	lsls r0, 24
	cmp r0, 0
	bne _0800EEF8
	movs r0, 0x9
	strh r0, [r4, 0x4]
	movs r0, 0x1
	b _0800EEFA
	.pool
_0800EEF8:
	movs r0, 0
_0800EEFA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800EEBC

	thumb_func_start sub_800EF00
sub_800EF00: @ 800EF00
	push {lr}
	ldr r0, =sub_800E94C
	movs r1, 0x1
	bl CreateTask
	ldr r1, =gUnknown_03005000
	adds r1, 0x67
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EF00

	thumb_func_start sub_800EF1C
sub_800EF1C: @ 800EF1C
	push {lr}
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800EF30
	movs r0, 0
	b _0800EF32
	.pool
_0800EF30:
	movs r0, 0x1
_0800EF32:
	pop {r1}
	bx r1
	thumb_func_end sub_800EF1C

	thumb_func_start sub_800EF38
sub_800EF38: @ 800EF38
	ldr r1, =gUnknown_03005000
	movs r0, 0x4
	strh r0, [r1, 0x4]
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	ldr r2, =0x00000ce7
	adds r1, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_800EF38

	thumb_func_start sub_800EF58
sub_800EF58: @ 800EF58
	push {lr}
	adds r1, r0, 0
	ldr r2, =gUnknown_03005000
	ldrh r0, [r2, 0x4]
	cmp r0, 0x11
	beq _0800EF68
	cmp r1, 0
	beq _0800EF74
_0800EF68:
	movs r0, 0x12
	strh r0, [r2, 0x4]
	movs r0, 0x1
	b _0800EF76
	.pool
_0800EF74:
	movs r0, 0
_0800EF76:
	pop {r1}
	bx r1
	thumb_func_end sub_800EF58

	thumb_func_start sub_800EF7C
sub_800EF7C: @ 800EF7C
	ldr r1, =gUnknown_03005000
	movs r0, 0xE
	strh r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_800EF7C

	thumb_func_start sub_800EF88
sub_800EF88: @ 800EF88
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0
	b _0800EF9A
_0800EF92:
	lsrs r1, 1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_0800EF9A:
	cmp r2, 0x3
	bhi _0800EFAC
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800EF92
	adds r0, r2, 0
	bl rfu_UNI_readySendData
_0800EFAC:
	pop {r0}
	bx r0
	thumb_func_end sub_800EF88

	thumb_func_start sub_800EFB0
sub_800EFB0: @ 800EFB0
	push {r4-r7,lr}
	sub sp, 0x4
	movs r2, 0
	ldr r7, =gRecvCmds
	ldr r0, =gUnknown_03005000
	adds r6, r7, 0
	ldr r1, =0x00000c87
	adds r5, r0, r1
_0800EFC0:
	movs r3, 0
	lsls r0, r2, 3
	lsls r1, r2, 4
	adds r4, r2, 0x1
	subs r0, r2
	lsls r0, 1
	adds r2, r0, r5
	adds r1, r6
_0800EFD0:
	ldrh r0, [r1]
	lsrs r0, 8
	strb r0, [r2, 0x1]
	ldrh r0, [r1]
	strb r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, 0x6
	ble _0800EFD0
	adds r2, r4, 0
	cmp r2, 0x4
	ble _0800EFC0
	movs r0, 0
	mov r1, sp
	strh r0, [r1]
	ldr r2, =0x01000028
	mov r0, sp
	adds r1, r7, 0
	bl CpuSet
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800EFB0

	thumb_func_start sub_800F014
sub_800F014: @ 800F014
	push {lr}
	ldr r3, =gSendCmd
	ldr r2, =gRecvCmds
	movs r1, 0x6
_0800F01C:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0800F01C
	ldr r1, =gSendCmd
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0xC
_0800F032:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _0800F032
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800F014

	thumb_func_start sub_800F048
sub_800F048: @ 800F048
	push {r4,r5,lr}
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000c3c
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, 0
	beq _0800F07A
	ldr r1, =0x00000c1c
	adds r0, r4, r1
	adds r1, r4, 0
	adds r1, 0x4C
	bl sub_800DAC8
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x00000c3a
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r1, r0, 0
	cmp r1, 0
	bne _0800F076
	ldrb r0, [r5]
	strb r1, [r5]
_0800F076:
	cmp r2, 0
	bne _0800F09E
_0800F07A:
	ldr r5, =gUnknown_03005000
	ldr r1, =0x00000c3c
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800F09E
	ldr r1, =0x000009e8
	adds r0, r5, r1
	adds r4, r5, 0
	adds r4, 0x4C
	adds r1, r4, 0
	bl sub_800D9DC
	ldr r1, =0x00000c1c
	adds r0, r5, r1
	adds r1, r4, 0
	bl sub_800DA68
_0800F09E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800F048

	thumb_func_start sub_800F0B8
sub_800F0B8: @ 800F0B8
	push {r4,lr}
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0800F0CC
_0800F0C4:
	movs r0, 0
	b _0800F0EC
	.pool
_0800F0CC:
	movs r3, 0
	ldr r4, =gRecvCmds
_0800F0D0:
	movs r2, 0
	lsls r0, r3, 4
	adds r1, r0, r4
_0800F0D6:
	ldrh r0, [r1]
	cmp r0, 0
	bne _0800F0C4
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x6
	ble _0800F0D6
	adds r3, 0x1
	cmp r3, 0x4
	ble _0800F0D0
	movs r0, 0x1
_0800F0EC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800F0B8

	thumb_func_start sub_800F0F8
sub_800F0F8: @ 800F0F8
	push {r4-r6,lr}
	ldr r6, =gUnknown_03005000
	ldrh r0, [r6, 0x4]
	cmp r0, 0x13
	bhi _0800F118
	bl rfu_REQ_recvData
	bl rfu_waitREQComplete
	movs r0, 0
	bl rfu_REQ_sendData_wrapper
	b _0800F1D2
	.pool
_0800F118:
	ldr r0, =0x00000cdb
	adds r1, r6, r0
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r0, =0x00000ce2
	adds r1, r6, r0
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r1, [r1]
	ldrb r0, [r0, 0x2]
	ands r0, r1
	cmp r0, r1
	bne _0800F1D2
	cmp r0, 0
	beq _0800F1D2
	ldr r1, =0x00000cdc
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r5, r0, 0
	cmp r5, 0
	bne _0800F1C8
	ldr r0, =0x00000ce3
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800F1A8
	bl sub_8011D6C
	strb r5, [r4]
	ldr r1, =0x00000ce4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800F18C
	movs r4, 0x80
	lsls r4, 8
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	adds r0, r4, 0
	bl sub_8011170
	b _0800F1D2
	.pool
_0800F18C:
	ldr r0, =gUnknown_03004140
	ldrb r4, [r0]
	cmp r4, 0
	bne _0800F1A8
	bl sub_800EDD4
	ldr r0, =gReceivedRemoteLinkPlayers
	strb r4, [r0]
	b _0800F1D2
	.pool
_0800F1A8:
	bl sub_800EFB0
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cda
	adds r0, r1
	ldrb r0, [r0]
	bl rfu_UNI_readySendData
	movs r0, 0x1
	bl rfu_REQ_sendData_wrapper
	b _0800F1CC
	.pool
_0800F1C8:
	bl rfu_REQ_PARENT_resumeRetransmitAndChange
_0800F1CC:
	ldr r1, =gUnknown_03005000
	movs r0, 0x1
	strb r0, [r1, 0xE]
_0800F1D2:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800F0F8

	thumb_func_start sub_800F1E0
sub_800F1E0: @ 800F1E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gUnknown_03005000
	ldrh r1, [r0, 0x4]
	adds r6, r0, 0
	cmp r1, 0x13
	bhi _0800F1F8
	b _0800F45A
_0800F1F8:
	ldrb r0, [r6, 0xE]
	cmp r0, 0x1
	beq _0800F200
	b _0800F45A
_0800F200:
	bl rfu_waitREQComplete
	ldr r0, =0x00000cdb
	adds r2, r6, r0
	ldrb r0, [r2]
	cmp r0, 0
	bne _0800F220
	adds r1, r6, 0
	adds r1, 0xEE
_0800F212:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800F21A
	b _0800F480
_0800F21A:
	ldrb r0, [r2]
	cmp r0, 0
	beq _0800F212
_0800F220:
	bl rfu_REQ_recvData
	bl rfu_waitREQComplete
	ldr r2, =gUnknown_03004140
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ce2
	adds r0, r4, r1
	ldrb r1, [r2, 0x3]
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, r0
	beq _0800F23C
	b _0800F444
_0800F23C:
	ldr r6, =0x00000cdc
	adds r1, r4, r6
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_02022B44
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	ldrb r7, [r2]
	movs r5, 0
_0800F252:
	movs r0, 0x1
	ands r0, r7
	lsrs r1, r7, 1
	str r1, [sp, 0x4]
	adds r2, r5, 0x1
	str r2, [sp]
	cmp r0, 0
	bne _0800F264
	b _0800F364
_0800F264:
	ldr r1, =gUnknown_03005000
	lsls r2, r5, 3
	subs r0, r2, r5
	lsls r4, r0, 1
	adds r0, r1, 0
	adds r0, 0x15
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r6, r1, 0
	adds r3, r2, 0
	lsls r1, r5, 24
	mov r10, r1
	cmp r0, 0
	beq _0800F35C
	ldr r2, =0x00000cee
	adds r0, r6, r2
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0800F2E0
	adds r0, r6, 0
	adds r0, 0x14
	adds r0, r4, r0
	ldrb r2, [r0]
	lsrs r2, 5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	cmp r2, r0
	beq _0800F2E0
	ldr r0, =0x00000cea
	adds r1, r6, r0
	adds r1, r5, r1
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _0800F35C
	movs r0, 0x81
	lsls r0, 8
	bl sub_8011170
	b _0800F35C
	.pool
_0800F2E0:
	ldr r2, =gUnknown_03005000
	ldr r6, =0x00000cee
	adds r1, r2, r6
	adds r1, r5, r1
	subs r3, r5
	lsls r3, 1
	adds r4, r2, 0
	adds r4, 0x14
	adds r2, r3, r4
	ldrb r0, [r2]
	lsrs r0, 5
	strb r0, [r1]
	ldr r1, =gUnknown_03005000
	subs r6, 0x4
	adds r0, r1, r6
	adds r0, r5, r0
	movs r1, 0
	strb r1, [r0]
	ldrb r1, [r2]
	movs r0, 0x1F
	ands r0, r1
	strb r0, [r2]
	ldr r2, =gUnknown_03005000+0xCDE
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r6, 0
	lsls r1, r5, 24
	mov r10, r1
	lsrs r2, r7, 1
	str r2, [sp, 0x4]
	adds r5, 0x1
	str r5, [sp]
	ldr r1, =gRecvCmds
	mov r9, r1
	adds r5, r3, 0
	adds r7, r4, 0
	lsls r0, 4
	mov r8, r0
	adds r2, r5, 0x1
	mov r12, r2
_0800F330:
	lsls r1, r6, 1
	mov r0, r8
	adds r4, r1, r0
	add r4, r9
	mov r2, r12
	adds r3, r1, r2
	adds r3, r7
	ldrb r2, [r3]
	lsls r2, 8
	adds r1, r5
	adds r1, r7
	ldrb r0, [r1]
	orrs r0, r2
	strh r0, [r4]
	movs r0, 0
	strb r0, [r3]
	strb r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x6
	bls _0800F330
_0800F35C:
	mov r1, r10
	lsrs r0, r1, 24
	bl rfu_UNI_clearRecvNewDataFlag
_0800F364:
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	lsrs r7, r0, 16
	ldr r6, [sp]
	lsls r0, r6, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bhi _0800F376
	b _0800F252
_0800F376:
	bl sub_800F014
	movs r0, 0
	bl sub_800F86C
	bl sub_8010528
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ce5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800F452
	ldr r2, =0x00000cd9
	adds r0, r4, r2
	ldrb r2, [r0]
	cmp r2, 0
	bne _0800F452
	ldr r0, =gUnknown_02022B44
	ldrb r1, [r0, 0xE]
	strb r2, [r0, 0xE]
	ldr r6, =0x00000cda
	adds r0, r4, r6
	ldrb r1, [r0]
	movs r0, 0x3
	bl rfu_clearSlot
	movs r5, 0
	adds r7, r4, 0
	adds r7, 0x14
_0800F3B2:
	ldr r0, =0x00000ce5
	adds r6, r4, r0
	ldrb r0, [r6]
	asrs r0, r5
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800F3D6
	lsls r1, r5, 24
	lsrs r1, 24
	lsls r2, r5, 3
	subs r2, r5
	lsls r2, 1
	adds r2, r7
	movs r0, 0x10
	movs r3, 0xE
	bl rfu_setRecvBuffer
_0800F3D6:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _0800F3B2
	subs r4, r6, 0x3
	ldrb r0, [r4]
	ldrb r2, [r6]
	adds r1, r0, 0
	orrs r1, r2
	bl sub_800E88C
	ldrb r1, [r6]
	movs r2, 0
	strb r1, [r6, 0x4]
	ldrb r0, [r4]
	orrs r0, r1
	strb r0, [r4]
	strb r2, [r6]
	ldrb r0, [r4]
	adds r1, r6, 0
	subs r1, 0x5E
	movs r2, 0x46
	bl rfu_UNI_setSendData
	ldrb r0, [r4]
	bl sub_800E87C
	adds r1, r6, 0
	subs r1, 0xB
	strb r0, [r1]
	ldr r0, =sub_8010AAC
	movs r1, 0
	bl CreateTask
	b _0800F452
	.pool
_0800F444:
	ldr r2, =0x00000cdc
	adds r1, r4, r2
	ldrb r0, [r1]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	strb r2, [r4, 0xE]
_0800F452:
	ldr r1, =gUnknown_03005000
	movs r0, 0
	strb r0, [r1, 0xE]
	adds r6, r1, 0
_0800F45A:
	ldr r1, =0x00000cdc
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r1, r0, 0
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0800F484
	movs r0, 0x1
	ands r0, r1
	b _0800F486
	.pool
_0800F480:
	movs r0, 0
	b _0800F486
_0800F484:
	movs r0, 0
_0800F486:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800F1E0

	thumb_func_start sub_800F498
sub_800F498: @ 800F498
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r2, r1, 0
	ldrh r1, [r4]
	cmp r1, 0
	beq _0800F4DC
	ldr r0, =gUnknown_03005000
	movs r5, 0x81
	lsls r5, 1
	adds r3, r0, r5
	ldrb r0, [r3]
	lsls r0, 5
	orrs r0, r1
	strh r0, [r4]
	ldrb r0, [r3]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strb r0, [r3]
	adds r3, r4, 0
	movs r4, 0x6
_0800F4C2:
	ldrh r1, [r3]
	lsrs r0, r1, 8
	strb r0, [r2, 0x1]
	strb r1, [r2]
	adds r2, 0x2
	adds r3, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0800F4C2
	b _0800F4EA
	.pool
_0800F4DC:
	movs r1, 0
	adds r0, r2, 0
	adds r0, 0xD
_0800F4E2:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r2
	bge _0800F4E2
_0800F4EA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800F498

	thumb_func_start sub_800F4F0
sub_800F4F0: @ 800F4F0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x58
	ldr r0, =gUnknown_03005000+0x124
	mov r1, sp
	bl sub_800D934
	movs r1, 0
	ldr r0, =gRecvCmds
	mov r12, r0
_0800F506:
	movs r4, 0
	lsls r0, r1, 3
	adds r2, r1, 0x1
	mov r8, r2
	lsls r6, r1, 4
	subs r0, r1
	lsls r5, r0, 1
_0800F514:
	lsls r1, r4, 1
	adds r3, r1, r6
	add r3, r12
	adds r1, r5, r1
	adds r0, r1, 0x1
	add r0, sp
	ldrb r2, [r0]
	lsls r2, 8
	mov r7, sp
	adds r0, r7, r1
	ldrb r0, [r0]
	orrs r0, r2
	strh r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _0800F514
	mov r1, r8
	lsls r0, r1, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _0800F506
	movs r0, 0
	bl sub_800F86C
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	bne _0800F5C0
	ldr r0, =gUnknown_03005000
	ldr r2, =0x00000ce4
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800F5C0
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	ldrb r0, [r0, 0x3]
	orrs r0, r1
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	bl sub_8011A74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0800F58C
	cmp r0, 0x6
	beq _0800F58C
	cmp r0, 0x9
	beq _0800F58C
	movs r1, 0x90
	lsls r1, 8
	movs r0, 0x2
	bl sub_8011A64
_0800F58C:
	bl rfu_clearAllSlot
	ldr r1, =gReceivedRemoteLinkPlayers
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gUnknown_03005000
	movs r5, 0
	str r5, [r0]
	ldr r7, =0x00000ce4
	adds r6, r0, r7
	ldrb r0, [r6]
	cmp r0, 0x1
	bne _0800F5B8
	movs r4, 0x90
	lsls r4, 8
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	adds r0, r4, 0
	bl sub_8011170
_0800F5B8:
	ldr r0, =gUnknown_03004140
	strb r5, [r0, 0x5]
	strb r5, [r0, 0x4]
	strb r5, [r6]
_0800F5C0:
	ldr r6, =gUnknown_03005000
	movs r0, 0xCD
	lsls r0, 4
	adds r2, r6, r0
	ldrb r0, [r2]
	cmp r0, 0
	beq _0800F604
	ldrb r0, [r2]
	subs r0, 0x1
	ldrb r1, [r2]
	strb r0, [r2]
	bl sub_8010528
	ldr r5, =gSendCmd
	add r4, sp, 0x48
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_800F498
	ldr r1, =0x000009e8
	adds r0, r6, r1
	adds r1, r4, 0
	bl sub_800D888
	movs r1, 0
	movs r2, 0
_0800F5F4:
	lsls r0, r1, 1
	adds r0, r5
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x6
	bls _0800F5F4
_0800F604:
	bl sub_800F0B8
	add sp, 0x58
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800F4F0

	thumb_func_start sub_800F638
sub_800F638: @ 800F638
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_03005000
	ldr r2, [r0, 0x70]
	mov r10, r2
	movs r5, 0
	adds r2, r0, 0
	adds r2, 0x6E
	ldrh r3, [r2]
	cmp r5, r3
	bge _0800F6D4
	mov r9, r0
	ldr r0, =gUnknown_03000D90
	mov r8, r0
_0800F65A:
	movs r0, 0x1
	ands r0, r1
	lsrs r7, r1, 1
	adds r6, r5, 0x1
	cmp r0, 0
	bne _0800F6C8
	ldr r1, =0xffff8900
	adds r0, r1, 0
	adds r1, r5, 0
	orrs r1, r0
	mov r2, r8
	strh r1, [r2]
	movs r4, 0
	lsls r0, r5, 1
	ldr r3, =gUnknown_03000D80
	mov r12, r3
	adds r0, r5
	lsls r0, 2
	mov r1, r10
	adds r2, r0, r1
	mov r3, r8
	adds r3, 0x2
_0800F686:
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	ldrb r0, [r2]
	orrs r0, r1
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x6
	ble _0800F686
	movs r4, 0
	ldr r2, =gUnknown_03000D90
	ldr r1, =gUnknown_03000D80
_0800F6A0:
	ldrh r0, [r2]
	lsrs r0, 8
	strb r0, [r1, 0x1]
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x6
	ble _0800F6A0
	ldr r0, =gUnknown_03005000+0x9E8
	mov r1, r12
	bl sub_800D888
	movs r1, 0x1
	lsls r1, r5
	mov r2, r9
	ldr r0, [r2, 0x78]
	orrs r0, r1
	str r0, [r2, 0x78]
_0800F6C8:
	adds r1, r7, 0
	adds r5, r6, 0
	ldr r3, =gUnknown_03005000+0x6E
	ldrh r3, [r3]
	cmp r5, r3
	blt _0800F65A
_0800F6D4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800F638

	thumb_func_start sub_800F6FC
sub_800F6FC: @ 800F6FC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_03005000
	ldrb r2, [r0, 0xC]
	cmp r2, 0x1
	bne _0800F71C
	cmp r1, 0
	beq _0800F71C
	adds r0, 0x61
	adds r0, r1, r0
	strb r2, [r0]
	b _0800F724
	.pool
_0800F71C:
	adds r0, 0x5C
	adds r0, r1, r0
	movs r1, 0x1
	strb r1, [r0]
_0800F724:
	pop {r0}
	bx r0
	thumb_func_end sub_800F6FC

	thumb_func_start sub_800F728
sub_800F728: @ 800F728
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_03005000
	adds r1, r3, 0
	adds r1, 0x5C
	adds r1, r0, r1
	movs r2, 0
	strb r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	adds r1, 0x92
	strb r2, [r1]
	bx lr
	.pool
	thumb_func_end sub_800F728

	thumb_func_start sub_800F74C
sub_800F74C: @ 800F74C
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_03005000
	ldrb r1, [r0, 0xC]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _0800F764
	movs r0, 0
	b _0800F786
	.pool
_0800F764:
	movs r2, 0
	ldr r0, =0x00000cde
	adds r4, r5, r0
_0800F76A:
	adds r1, r2, r4
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0800F76A
	ldr r1, =0x00000c3e
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r3
	ldrb r0, [r0]
_0800F786:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800F74C

	thumb_func_start rfu_func_080F97B8
rfu_func_080F97B8: @ 800F794
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800F7C6
	ldr r3, =gUnknown_03005DA8
	ldrh r2, [r3]
	cmp r2, 0
	beq _0800F7C6
	ldr r0, =gLinkTransferringData
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0800F7C6
	ldr r1, =gUnknown_03000D78
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldrb r0, [r1]
	lsls r0, 8
	orrs r0, r2
	strh r0, [r3]
	movs r0, 0xBE
	lsls r0, 8
	bl sub_800FD14
_0800F7C6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end rfu_func_080F97B8

	thumb_func_start sub_800F7DC
sub_800F7DC: @ 800F7DC
	ldr r0, =gUnknown_02022B14
	bx lr
	.pool
	thumb_func_end sub_800F7DC

	thumb_func_start sub_800F7E4
sub_800F7E4: @ 800F7E4
	push {lr}
	movs r2, 0
	ldr r0, =gUnknown_03005000
	ldr r1, [r0]
	ldr r0, =rfu_func_080F97B8
	cmp r1, r0
	bne _0800F7F4
	movs r2, 0x1
_0800F7F4:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800F7E4

	thumb_func_start sub_800F804
sub_800F804: @ 800F804
	ldr r1, =gUnknown_03005000
	ldr r0, =rfu_func_080F97B8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_800F804

	thumb_func_start Rfu_set_zero
Rfu_set_zero: @ 800F814
	ldr r1, =gUnknown_03005000
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end Rfu_set_zero

	thumb_func_start sub_800F820
sub_800F820: @ 800F820
	push {lr}
	movs r0, 0x88
	lsls r0, 7
	bl sub_800FD14
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0800F83C
	bl GetBlenderArrowPosition
	ldr r1, =gSendCmd
	strh r0, [r1, 0xC]
_0800F83C:
	ldr r1, =gUnknown_020223C0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800F820

	thumb_func_start sub_800F850
sub_800F850: @ 800F850
	push {lr}
	ldr r1, =gUnknown_03005000
	ldr r0, [r1]
	cmp r0, 0
	bne _0800F85E
	ldr r0, =sub_800F820
	str r0, [r1]
_0800F85E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800F850

	thumb_func_start sub_800F86C
sub_800F86C: @ 800F86C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r8, r0
_0800F87A:
	mov r1, r8
	lsls r0, r1, 4
	ldr r2, =gRecvCmds
	adds r1, r0, r2
	ldrh r7, [r1]
	movs r3, 0xFF
	lsls r3, 8
	adds r1, r3, 0
	ands r1, r7
	movs r2, 0x88
	lsls r2, 8
	adds r5, r0, 0
	cmp r1, r2
	beq _0800F960
	cmp r1, r2
	bgt _0800F8D6
	movs r0, 0xCC
	lsls r0, 7
	cmp r1, r0
	bne _0800F8A4
	b _0800FAE0
_0800F8A4:
	cmp r1, r0
	bgt _0800F8C4
	movs r0, 0x88
	lsls r0, 7
	cmp r1, r0
	bne _0800F8B2
	b _0800FBF4
_0800F8B2:
	movs r0, 0xBE
	lsls r0, 7
	cmp r1, r0
	bne _0800F8BC
	b _0800FAD0
_0800F8BC:
	b _0800FC04
	.pool
_0800F8C4:
	movs r0, 0xEE
	lsls r0, 7
	cmp r1, r0
	beq _0800F920
	movs r0, 0xF0
	lsls r0, 7
	cmp r1, r0
	beq _0800F90E
	b _0800FC04
_0800F8D6:
	movs r0, 0xBE
	lsls r0, 8
	cmp r1, r0
	bne _0800F8E0
	b _0800FBF4
_0800F8E0:
	cmp r1, r0
	bgt _0800F8F8
	movs r0, 0x89
	lsls r0, 8
	cmp r1, r0
	beq _0800F9C8
	movs r0, 0xA1
	lsls r0, 8
	cmp r1, r0
	bne _0800F8F6
	b _0800FAAC
_0800F8F6:
	b _0800FC04
_0800F8F8:
	movs r0, 0xED
	lsls r0, 8
	cmp r1, r0
	bne _0800F902
	b _0800FB10
_0800F902:
	movs r0, 0xEE
	lsls r0, 8
	cmp r1, r0
	bne _0800F90C
	b _0800FBB0
_0800F90C:
	b _0800FC04
_0800F90E:
	ldr r4, =gUnknown_03005000
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	bne _0800F920
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800F920
	b _0800FC50
_0800F920:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	mov r6, r8
	adds r6, 0x1
	cmp r0, 0
	beq _0800F930
	b _0800FC08
_0800F930:
	ldr r1, =gRecvCmds+0x2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldr r2, =gUnknown_03005000
	strb r0, [r2, 0xD]
	ldr r3, =gRecvCmds+0x4
	adds r0, r5, r3
	bl sub_800F74C
	ldr r4, =gUnknown_03005000+0xCCE
	strb r0, [r4]
	b _0800FC08
	.pool
_0800F960:
	ldr r0, =gUnknown_03005000
	mov r9, r0
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r7, r0, 2
	mov r2, r9
	adds r3, r7, r2
	movs r4, 0x92
	adds r4, r3
	mov r12, r4
	ldrb r4, [r4]
	mov r6, r8
	adds r6, 0x1
	cmp r4, 0
	beq _0800F982
	b _0800FC08
_0800F982:
	adds r0, r3, 0
	adds r0, 0x80
	movs r2, 0
	strh r4, [r0]
	ldr r1, =gRecvCmds+0x2
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r1, r3, 0
	adds r1, 0x82
	strh r0, [r1]
	ldr r1, =gRecvCmds+0x4
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r3, 0
	adds r0, 0x91
	strb r1, [r0]
	mov r0, r9
	adds r0, 0x88
	adds r0, r7, r0
	str r4, [r0]
	movs r0, 0x1
	mov r3, r12
	strb r0, [r3]
	mov r0, r9
	adds r0, 0x5C
	add r0, r8
	strb r2, [r0]
	b _0800FC08
	.pool
_0800F9C8:
	ldr r4, =gUnknown_03005000
	mov r9, r4
	mov r0, r8
	lsls r1, r0, 2
	adds r0, r1, r0
	lsls r4, r0, 2
	mov r3, r9
	adds r2, r4, r3
	adds r0, r2, 0
	adds r0, 0x92
	ldrb r3, [r0]
	mov r10, r1
	mov r6, r8
	adds r6, 0x1
	cmp r3, 0x1
	beq _0800F9EA
	b _0800FC08
_0800F9EA:
	movs r0, 0xFF
	ands r0, r7
	adds r2, 0x80
	strh r0, [r2]
	mov r1, r9
	adds r1, 0x88
	adds r1, r4, r1
	lsls r3, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r4, 0
	ldr r0, =gBlockRecvBuffer
	mov r9, r0
	mov r12, r2
	mov r1, r8
	lsls r7, r1, 8
	adds r3, r5, 0
_0800FA0E:
	mov r2, r12
	ldrh r0, [r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	adds r1, r4
	lsls r1, 1
	adds r1, r7
	add r1, r9
	adds r2, r4, 0x1
	lsls r0, r2, 1
	adds r0, r3
	ldr r4, =gRecvCmds
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, 16
	lsrs r4, r2, 16
	cmp r4, 0x5
	bls _0800FA0E
	ldr r4, =gUnknown_03005000
	mov r0, r10
	add r0, r8
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x88
	adds r1, r0, r1
	adds r2, r0, r4
	adds r0, r2, 0
	adds r0, 0x82
	ldrh r0, [r0]
	lsls r0, 2
	ldr r3, =gUnknown_082ED628
	adds r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _0800FA5C
	b _0800FC08
_0800FA5C:
	adds r1, r2, 0
	adds r1, 0x92
	movs r0, 0x2
	strb r0, [r1]
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_800F6FC
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	beq _0800FA7E
	b _0800FC08
_0800FA7E:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800FA88
	b _0800FC08
_0800FA88:
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	beq _0800FA90
	b _0800FC08
_0800FA90:
	ldr r0, =gBlockRecvBuffer
	bl sub_8010A70
	b _0800FC08
	.pool
_0800FAAC:
	ldr r2, =gUnknown_082ED6B8
	ldr r3, =gRecvCmds+0x2
	adds r0, r5, r3
	ldrh r1, [r0]
	lsls r1, 3
	adds r0, r1, r2
	ldr r0, [r0]
	adds r2, 0x4
	adds r1, r2
	ldrh r1, [r1]
	bl sub_800FE84
	b _0800FC04
	.pool
_0800FAD0:
	ldr r1, =gUnknown_03005000+0xE4
	add r1, r8
	movs r0, 0x1
	strb r0, [r1]
	b _0800FC04
	.pool
_0800FAE0:
	ldr r2, =gUnknown_03005000
	movs r4, 0x80
	lsls r4, 1
	adds r0, r2, r4
	ldr r3, =gRecvCmds+0x2
	adds r1, r5, r3
	ldrh r0, [r0]
	mov r6, r8
	adds r6, 0x1
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800FAFA
	b _0800FC08
_0800FAFA:
	adds r0, r2, 0
	adds r0, 0xE9
	add r0, r8
	movs r1, 0x1
	strb r1, [r0]
	b _0800FC08
	.pool
_0800FB10:
	ldr r7, =gUnknown_03005000
	ldrb r2, [r7, 0xC]
	cmp r2, 0
	bne _0800FB78
	ldr r3, =gReceivedRemoteLinkPlayers
	ldrb r0, [r3]
	mov r6, r8
	adds r6, 0x1
	cmp r0, 0
	beq _0800FC08
	ldr r0, =gRecvCmds+0x2
	adds r4, r5, r0
	ldrh r1, [r4]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	ands r1, r0
	cmp r1, 0
	beq _0800FB48
	strb r2, [r3]
	bl sub_800D630
	ldr r1, =gRecvCmds+0x4
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, =0x00000ce4
	adds r0, r7, r2
	strb r1, [r0]
_0800FB48:
	ldr r0, =gRecvCmds
	adds r0, 0x6
	adds r0, r5, r0
	ldrh r0, [r0]
	strb r0, [r7, 0xD]
	ldrh r0, [r4]
	bl sub_80109E8
	b _0800FC08
	.pool
_0800FB78:
	movs r0, 0xEE
	lsls r0, 8
	bl sub_800FD14
	ldr r1, =gSendCmd
	ldr r3, =gRecvCmds+0x2
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r1, 0x2]
	ldr r4, =gRecvCmds+0x4
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	ldr r0, =gRecvCmds
	adds r0, 0x6
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r1, 0x6]
	b _0800FC04
	.pool
_0800FBB0:
	ldr r4, =gUnknown_03005000
	ldrb r0, [r4, 0xC]
	mov r6, r8
	adds r6, 0x1
	cmp r0, 0x1
	bne _0800FC44
	ldr r0, =0x00000ce3
	adds r2, r4, r0
	ldr r1, =gRecvCmds+0x2
	adds r3, r5, r1
	ldrb r1, [r3]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, =gRecvCmds+0x4
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r2, =0x00000ce4
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r0, [r3]
	bl sub_80109E8
	b _0800FC08
	.pool
_0800FBF4:
	ldr r0, =gLinkPartnersHeldKeys
	mov r3, r8
	lsls r1, r3, 1
	adds r1, r0
	ldr r4, =gRecvCmds+0x2
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1]
_0800FC04:
	mov r6, r8
	adds r6, 0x1
_0800FC08:
	ldr r3, =gUnknown_03005000
	ldrb r4, [r3, 0xC]
	cmp r4, 0x1
	bne _0800FC44
	adds r0, r3, 0
	adds r0, 0x61
	mov r1, r8
	adds r2, r1, r0
	ldrb r0, [r2]
	adds r1, r0, 0
	cmp r1, 0
	beq _0800FC44
	cmp r1, 0x4
	bne _0800FC40
	adds r0, r3, 0
	adds r0, 0x5C
	add r0, r8
	movs r1, 0
	strb r4, [r0]
	strb r1, [r2]
	b _0800FC44
	.pool
_0800FC40:
	adds r0, 0x1
	strb r0, [r2]
_0800FC44:
	lsls r0, r6, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0x4
	bhi _0800FC50
	b _0800F87A
_0800FC50:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800F86C

	thumb_func_start sub_800FC60
sub_800FC60: @ 800FC60
	push {lr}
	movs r2, 0
	ldr r0, =gUnknown_03005000
	adds r1, r0, 0
	adds r1, 0x92
_0800FC6A:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800FC78
	movs r0, 0
	b _0800FC82
	.pool
_0800FC78:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x4
	ble _0800FC6A
	movs r0, 0x1
_0800FC82:
	pop {r1}
	bx r1
	thumb_func_end sub_800FC60

	thumb_func_start sub_800FC88
sub_800FC88: @ 800FC88
	push {r4,lr}
	movs r1, 0
	ldr r2, =gUnknown_03005000
	ldrb r0, [r2, 0xD]
	cmp r1, r0
	bge _0800FCBC
	adds r4, r0, 0
	adds r3, r2, 0
	adds r3, 0x92
	adds r2, 0x5C
_0800FC9C:
	ldrb r0, [r3]
	cmp r0, 0x2
	bne _0800FCAA
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0800FCB4
_0800FCAA:
	movs r0, 0
	b _0800FCBE
	.pool
_0800FCB4:
	adds r3, 0x14
	adds r1, 0x1
	cmp r1, r4
	blt _0800FC9C
_0800FCBC:
	movs r0, 0x1
_0800FCBE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800FC88

	thumb_func_start sub_800FCC4
sub_800FCC4: @ 800FCC4
	movs r2, 0
	movs r1, 0
	strh r1, [r0]
	strh r1, [r0, 0x2]
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	strb r2, [r0, 0x10]
	strb r2, [r0, 0x11]
	strb r2, [r0, 0x12]
	bx lr
	thumb_func_end sub_800FCC4

	thumb_func_start sub_800FCD8
sub_800FCD8: @ 800FCD8
	push {r4,lr}
	movs r2, 0
	movs r1, 0
	ldr r0, =gUnknown_03005000
	adds r3, r0, 0
	adds r3, 0x92
	adds r4, r0, 0
	adds r4, 0x5C
_0800FCE8:
	ldrb r0, [r3]
	cmp r0, 0x2
	bne _0800FCFE
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800FCFE
	lsls r0, r1
	orrs r2, r0
	lsls r0, r2, 24
	lsrs r2, r0, 24
_0800FCFE:
	adds r3, 0x14
	adds r1, 0x1
	cmp r1, 0x4
	ble _0800FCE8
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800FCD8

	thumb_func_start sub_800FD14
sub_800FD14: @ 800FD14
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r5, =gSendCmd
	strh r1, [r5]
	movs r0, 0xF0
	lsls r0, 7
	adds r4, r5, 0
	cmp r1, r0
	beq _0800FDB0
	cmp r1, r0
	bgt _0800FD62
	movs r0, 0xBE
	lsls r0, 7
	cmp r1, r0
	beq _0800FE00
	cmp r1, r0
	bgt _0800FD50
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	beq _0800FE20
	movs r0, 0x88
	lsls r0, 7
	cmp r1, r0
	beq _0800FE14
	b _0800FE46
	.pool
_0800FD50:
	movs r0, 0xCC
	lsls r0, 7
	cmp r1, r0
	beq _0800FE00
	movs r0, 0xEE
	lsls r0, 7
	cmp r1, r0
	beq _0800FDB0
	b _0800FE46
_0800FD62:
	movs r0, 0xBE
	lsls r0, 8
	cmp r1, r0
	beq _0800FE40
	cmp r1, r0
	bgt _0800FE46
	movs r0, 0x88
	lsls r0, 8
	cmp r1, r0
	beq _0800FD80
	movs r0, 0xA1
	lsls r0, 8
	cmp r1, r0
	beq _0800FD98
	b _0800FE46
_0800FD80:
	ldr r0, =gUnknown_03005000
	adds r1, r0, 0
	adds r1, 0x6E
	ldrh r1, [r1]
	strh r1, [r5, 0x2]
	adds r0, 0x7D
	ldrb r0, [r0]
	adds r0, 0x80
	strh r0, [r5, 0x4]
	b _0800FE46
	.pool
_0800FD98:
	bl sub_800FC60
	lsls r0, 24
	cmp r0, 0
	beq _0800FE46
	ldr r0, =gUnknown_03005000
	adds r0, 0x5A
	ldrb r0, [r0]
	b _0800FE44
	.pool
_0800FDB0:
	ldr r3, =gUnknown_03005000
	ldr r1, =0x00000ce2
	adds r0, r3, r1
	ldr r2, =0x00000ce3
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	eors r0, r2
	ldr r1, =gUnknown_082ED695
	adds r0, r1
	ldrb r0, [r0]
	adds r0, 0x1
	strb r0, [r3, 0xD]
	ldrb r0, [r3, 0xD]
	strh r0, [r4, 0x2]
	adds r2, r4, 0x4
	movs r4, 0
	ldr r0, =0x00000cde
	adds r3, r0
_0800FDD6:
	adds r1, r2, r4
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800FDD6
	b _0800FE46
	.pool
_0800FE00:
	ldr r0, =gUnknown_03005000
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4, 0x2]
	b _0800FE46
	.pool
_0800FE14:
	strh r1, [r5]
	ldr r0, =gMain
	ldrh r0, [r0, 0x2C]
	b _0800FE44
	.pool
_0800FE20:
	movs r4, 0
	ldr r3, =gUnknown_03005000+0xF2
_0800FE24:
	adds r2, r4, 0x1
	lsls r1, r2, 1
	adds r1, r5
	lsls r0, r4, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0x5
	bls _0800FE24
	b _0800FE46
	.pool
_0800FE40:
	ldr r0, =gUnknown_03005DA8
	ldrh r0, [r0]
_0800FE44:
	strh r0, [r5, 0x2]
_0800FE46:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800FD14

	thumb_func_start sub_800FE50
sub_800FE50: @ 800FE50
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800FE76
	bl sub_8011A80
	cmp r0, 0
	bne _0800FE76
	ldr r0, =gUnknown_03005000+0xF2
	adds r1, r4, 0
	movs r2, 0xC
	bl memcpy
	movs r0, 0xBC
	lsls r0, 6
	bl sub_800FD14
_0800FE76:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800FE50

	thumb_func_start sub_800FE84
@ bool8 sub_800FE84(u32 a1, u32 size)
sub_800FE84: @ 800FE84
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r6, r1, 0
	ldr r5, =gUnknown_03005000
	ldr r0, [r5]
	cmp r0, 0
	bne _0800FEB8
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800FEB8
	movs r0, 0x7C
	adds r0, r5
	mov r9, r0
	ldrb r1, [r0]
	mov r8, r1
	cmp r1, 0
	beq _0800FEC8
	ldr r1, =gUnknown_02022B44
	adds r1, 0x83
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0800FEB8:
	movs r0, 0
	b _0800FF32
	.pool
_0800FEC8:
	adds r0, r6, 0
	movs r1, 0xC
	bl __umodsi3
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl GetMultiplayerId
	adds r1, r5, 0
	adds r1, 0x7D
	strb r0, [r1]
	movs r0, 0x1
	mov r1, r9
	strb r0, [r1]
	adds r0, r6, 0
	movs r1, 0xC
	bl __udivsi3
	adds r0, r4
	adds r1, r5, 0
	adds r1, 0x6E
	strh r0, [r1]
	adds r0, r5, 0
	adds r0, 0x6C
	mov r1, r8
	strh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	cmp r6, r0
	bls _0800FF0A
	str r7, [r5, 0x70]
	b _0800FF1C
_0800FF0A:
	ldr r4, =gBlockSendBuffer
	cmp r7, r4
	beq _0800FF1A
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl memcpy
_0800FF1A:
	str r4, [r5, 0x70]
_0800FF1C:
	movs r0, 0x88
	lsls r0, 8
	bl sub_800FD14
	ldr r0, =gUnknown_03005000
	ldr r1, =rfufunc_80F9F44
	str r1, [r0]
	adds r0, 0x5B
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
_0800FF32:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800FE84

	thumb_func_start rfufunc_80F9F44
rfufunc_80F9F44: @ 800FF4C
	push {r4,r5,lr}
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800FFA0
	movs r5, 0x88
	lsls r5, 8
	adds r0, r5, 0
	bl sub_800FD14
	ldr r4, =gUnknown_03005000
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	bne _0800FF84
	adds r1, r4, 0
	adds r1, 0x5B
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _0800FFA0
	b _0800FF9C
	.pool
_0800FF84:
	bl GetMultiplayerId
	ldr r1, =gRecvCmds
	lsls r0, 24
	lsrs r0, 20
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, r5
	bne _0800FFA0
_0800FF9C:
	ldr r0, =sub_800FFB0
	str r0, [r4]
_0800FFA0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end rfufunc_80F9F44

	thumb_func_start sub_800FFB0
sub_800FFB0: @ 800FFB0
	push {r4-r6,lr}
	ldr r0, =gUnknown_03005000
	mov r12, r0
	ldr r5, [r0, 0x70]
	ldr r3, =gSendCmd
	mov r2, r12
	adds r2, 0x6C
	ldrh r1, [r2]
	movs r4, 0x89
	lsls r4, 8
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r3]
	movs r4, 0
	adds r6, r2, 0
	adds r3, 0x2
_0800FFD0:
	lsls r2, r4, 1
	ldrh r1, [r6]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	lsls r1, 8
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x6
	ble _0800FFD0
	mov r0, r12
	adds r0, 0x6C
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	adds r0, 0x2
	ldrh r0, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r0, r1
	bhi _08010014
	mov r0, r12
	adds r0, 0x7C
	movs r1, 0
	strb r1, [r0]
	ldr r0, =rfufunc_80FA020
	mov r1, r12
	str r0, [r1]
_08010014:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800FFB0

	thumb_func_start rfufunc_80FA020
rfufunc_80FA020: @ 8010028
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r5, =gUnknown_03005000
	ldr r0, [r5, 0x70]
	mov r8, r0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _080100F0
	ldr r3, =gSendCmd
	adds r2, r5, 0
	adds r2, 0x6E
	ldrh r0, [r2]
	subs r0, 0x1
	ldr r4, =0xffff8900
	adds r1, r4, 0
	orrs r0, r1
	strh r0, [r3]
	movs r4, 0
	mov r9, r5
	ldr r0, =gRecvCmds
	mov r12, r0
	lsls r5, r6, 4
	adds r7, r2, 0
	adds r3, 0x2
_08010064:
	lsls r2, r4, 1
	ldrh r1, [r7]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	add r0, r8
	adds r1, r0, 0
	subs r1, 0xB
	ldrb r1, [r1]
	lsls r1, 8
	subs r0, 0xC
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x6
	ble _08010064
	mov r1, r12
	adds r0, r5, r1
	ldrb r1, [r0]
	mov r3, r9
	adds r0, r3, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _080100F4
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x88
	adds r1, r0, r1
	ldr r2, =gUnknown_082ED628
	adds r0, r3
	adds r0, 0x82
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _080100E8
	adds r0, r6, 0
	bl sub_800F638
	ldr r1, =gUnknown_02022B44
	adds r1, 0x64
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _080100F4
	.pool
_080100E8:
	movs r0, 0
	mov r4, r9
	str r0, [r4]
	b _080100F4
_080100F0:
	movs r0, 0
	str r0, [r5]
_080100F4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end rfufunc_80FA020

	thumb_func_start sub_8010100
sub_8010100: @ 8010100
	push {lr}
	ldr r1, =gUnknown_03005000
	adds r1, 0x5A
	strb r0, [r1]
	movs r0, 0xA1
	lsls r0, 8
	bl sub_800FD14
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8010100

	thumb_func_start sub_801011C
sub_801011C: @ 801011C
	push {lr}
	bl rfu_clearAllSlot
	bl sub_800C048
	ldr r1, =gReceivedRemoteLinkPlayers
	movs r0, 0
	strb r0, [r1]
	ldr r2, =gUnknown_03005000
	adds r3, r2, 0
	adds r3, 0xEF
	movs r1, 0
	movs r0, 0x1
	strb r0, [r3]
	str r1, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801011C

	thumb_func_start sub_8010148
sub_8010148: @ 8010148
	push {lr}
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	ldrb r0, [r0, 0x3]
	orrs r0, r1
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	bl sub_801011C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010148

	thumb_func_start sub_8010168
sub_8010168: @ 8010168
	push {r4,lr}
	ldr r4, =gUnknown_03005000
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	bne _08010188
	bl sub_800D630
	ldr r0, =0x00000ce4
	adds r1, r4, r0
	movs r0, 0x2
	strb r0, [r1]
	b _0801018C
	.pool
_08010188:
	ldr r0, =sub_8010148
	str r0, [r4]
_0801018C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010168

	thumb_func_start sub_8010198
sub_8010198: @ 8010198
	push {lr}
	bl sub_800D630
	ldr r2, =gUnknown_03005000
	ldr r0, =0x00000ce4
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	ldr r1, =0x00000ce3
	adds r2, r1
	strb r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010198

	thumb_func_start sub_80101CC
sub_80101CC: @ 80101CC
	push {r4,r5,lr}
	ldr r0, =gUnknown_03005000
	ldrb r5, [r0, 0xD]
	movs r2, 0
	movs r1, 0
	adds r3, r0, 0
	adds r4, r3, 0
	adds r4, 0xE4
_080101DC:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080101E6
	adds r2, 0x1
_080101E6:
	adds r1, 0x1
	cmp r1, 0x4
	ble _080101DC
	cmp r2, r5
	bne _08010220
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r3, 0xC]
	cmp r0, 0
	bne _0801021C
	adds r0, r3, 0
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0x3
	strb r1, [r0]
	bl sub_8010168
	b _08010220
	.pool
_0801021C:
	ldr r0, =sub_8010168
	str r0, [r3]
_08010220:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80101CC

	thumb_func_start sub_801022C
sub_801022C: @ 801022C
	push {r4,lr}
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801024E
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ce8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801024E
	movs r0, 0xBE
	lsls r0, 7
	bl sub_800FD14
	ldr r0, =sub_80101CC
	str r0, [r4]
_0801024E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801022C

	thumb_func_start sub_8010264
sub_8010264: @ 8010264
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gUnknown_03005000
	ldr r0, [r2]
	cmp r0, 0
	bne _08010284
	ldr r1, =0x00000cd9
	adds r0, r2, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, =sub_801022C
	str r0, [r2]
	adds r0, r3, 0
	bl DestroyTask
_08010284:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010264

	thumb_func_start task_add_05_task_del_08FA224_when_no_RfuFunc
task_add_05_task_del_08FA224_when_no_RfuFunc: @ 8010294
	push {r4,lr}
	ldr r4, =sub_8010264
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080102AC
	adds r0, r4, 0
	movs r1, 0x5
	bl CreateTask
_080102AC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_add_05_task_del_08FA224_when_no_RfuFunc

	thumb_func_start sub_80102B8
sub_80102B8: @ 80102B8
	push {r4,r5,lr}
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _080102E6
	ldr r1, =gUnknown_03005000
	ldr r2, =0x000009e6
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r4, r0, 0
	cmp r4, 0
	bne _080102E6
	adds r5, r1, 0
	adds r5, 0xFE
	ldrh r0, [r5]
	cmp r0, 0x3C
	bls _080102E6
	movs r0, 0xCC
	lsls r0, 7
	bl sub_800FD14
	strh r4, [r5]
_080102E6:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	cmp r1, r2
	bcs _08010312
	ldr r0, =gUnknown_03005000
	adds r3, r0, 0
	adds r3, 0xE9
	ldrb r0, [r3]
	cmp r0, 0
	beq _08010312
_08010300:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r2
	bcs _08010312
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08010300
_08010312:
	ldr r4, =gUnknown_03005000
	cmp r1, r2
	bne _0801033E
	movs r1, 0
	adds r3, r4, 0
	adds r3, 0xE9
	movs r2, 0
_08010320:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _08010320
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, 0x1
	movs r2, 0
	strh r1, [r0]
	str r2, [r4]
_0801033E:
	adds r1, r4, 0
	adds r1, 0xFE
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80102B8

	thumb_func_start sub_8010358
sub_8010358: @ 8010358
	push {r4,lr}
	ldr r4, =gUnknown_03005000
	ldr r1, =0x000009e6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801037A
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801037A
	movs r0, 0xCC
	lsls r0, 7
	bl sub_800FD14
	ldr r0, =sub_80102B8
	str r0, [r4]
_0801037A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010358

	thumb_func_start sub_8010390
sub_8010390: @ 8010390
	push {r4,lr}
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _080103CC
	ldr r4, =gUnknown_03005000
	ldr r1, =0x000009e6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801041E
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801041E
	movs r0, 0xCC
	lsls r0, 7
	bl sub_800FD14
	ldr r0, =sub_80102B8
	b _0801041C
	.pool
_080103CC:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0x1
	cmp r1, r2
	bcs _080103FA
	ldr r3, =gUnknown_03005000
	adds r0, r3, 0
	adds r0, 0xEA
	ldrb r0, [r0]
	cmp r0, 0
	beq _080103FA
	adds r3, 0xE9
_080103E8:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r2
	bcs _080103FA
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080103E8
_080103FA:
	cmp r1, r2
	bne _0801041E
	ldr r4, =gUnknown_03005000
	ldr r1, =0x000009e6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801041E
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801041E
	movs r0, 0xCC
	lsls r0, 7
	bl sub_800FD14
	ldr r0, =sub_8010358
_0801041C:
	str r0, [r4]
_0801041E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010390

	thumb_func_start sub_8010434
sub_8010434: @ 8010434
	push {lr}
	ldr r1, =gUnknown_03005000
	ldr r2, [r1]
	cmp r2, 0
	bne _08010448
	ldr r0, =sub_8010390
	str r0, [r1]
	adds r0, r1, 0
	adds r0, 0xFE
	strh r2, [r0]
_08010448:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010434

	thumb_func_start sub_8010454
sub_8010454: @ 8010454
	push {r4,lr}
	adds r3, r0, 0
	ldr r1, =gUnknown_082ED6E0
	ldrh r0, [r1]
	cmp r0, r3
	beq _08010482
	ldr r4, =0x0000ffff
	adds r2, r1, 0
_08010464:
	ldrh r0, [r2]
	cmp r0, r4
	bne _08010478
	movs r0, 0
	b _08010484
	.pool
_08010478:
	adds r1, 0x2
	adds r2, 0x2
	ldrh r0, [r1]
	cmp r0, r3
	bne _08010464
_08010482:
	movs r0, 0x1
_08010484:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8010454

	thumb_func_start sub_801048C
sub_801048C: @ 801048C
	push {lr}
	cmp r0, 0
	beq _080104A0
	movs r1, 0x96
	lsls r1, 2
	movs r0, 0x1
	bl sub_800D550
	movs r0, 0
	b _080104AC
_080104A0:
	movs r0, 0
	movs r1, 0
	bl sub_800D550
	lsls r0, 24
	lsrs r0, 24
_080104AC:
	pop {r1}
	bx r1
	thumb_func_end sub_801048C

	thumb_func_start sub_80104B0
sub_80104B0: @ 80104B0
	push {lr}
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cd9
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0
	bl sub_800C27C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80104B0

	thumb_func_start rfu_get_multiplayer_id
rfu_get_multiplayer_id: @ 80104D0
	push {lr}
	ldr r1, =gUnknown_03005000
	ldrb r0, [r1, 0xC]
	cmp r0, 0x1
	beq _080104EC
	ldr r2, =0x00000cce
	adds r0, r1, r2
	ldrb r0, [r0]
	b _080104EE
	.pool
_080104EC:
	movs r0, 0
_080104EE:
	pop {r1}
	bx r1
	thumb_func_end rfu_get_multiplayer_id

	thumb_func_start sub_80104F4
sub_80104F4: @ 80104F4
	ldr r0, =gUnknown_03005000
	ldrb r0, [r0, 0xD]
	bx lr
	.pool
	thumb_func_end sub_80104F4

	thumb_func_start sub_8010500
sub_8010500: @ 8010500
	push {lr}
	ldr r2, =gUnknown_03005000
	adds r0, r2, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08010518
	movs r0, 0
	b _08010524
	.pool
_08010518:
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08010522
	movs r1, 0x1
_08010522:
	adds r0, r1, 0
_08010524:
	pop {r1}
	bx r1
	thumb_func_end sub_8010500

	thumb_func_start sub_8010528
sub_8010528: @ 8010528
	push {lr}
	ldr r0, =gUnknown_03005000
	ldr r0, [r0]
	cmp r0, 0
	beq _08010536
	bl _call_via_r0
_08010536:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010528

	thumb_func_start sub_8010540
sub_8010540: @ 8010540
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	movs r5, 0
	ldr r6, =gUnknown_03005000
	ldr r0, =0x00000c3e
	adds r0, r6
	mov r8, r0
_08010552:
	ldr r1, =0x00000cd1
	adds r0, r6, r1
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080105DA
	ldr r1, =gUnknown_03007880
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, 0x34]
	cmp r0, 0x46
	beq _08010576
	cmp r0, 0x48
	bne _080105C0
_08010576:
	ldr r2, =0x00000cd5
	adds r0, r6, r2
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0x8
	bne _080105DA
	movs r0, 0x9
	strb r0, [r4]
	movs r0, 0xA
	strb r0, [r1]
	lsls r1, r5, 24
	lsrs r1, 24
	movs r0, 0x8
	bl rfu_clearSlot
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r5
	lsrs r0, 24
	movs r1, 0x8
	adds r2, r4, 0
	movs r3, 0x1
	bl rfu_NI_setSendData
	movs r7, 0x1
	b _080105DA
	.pool
_080105C0:
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, 0x34]
	cmp r0, 0x47
	bne _080105DA
	lsls r1, r5, 24
	lsrs r1, 24
	movs r0, 0x8
	bl rfu_clearSlot
_080105DA:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08010552
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8010540

	thumb_func_start sub_80105EC
sub_80105EC: @ 80105EC
	push {r4-r6,lr}
	movs r3, 0
	movs r1, 0
	ldr r5, =gUnknown_03005000+0xCD5
	movs r6, 0x1
	movs r4, 0
_080105F8:
	adds r2, r1, r5
	ldrb r0, [r2]
	cmp r0, 0xB
	bne _0801060C
	adds r0, r6, 0
	lsls r0, r1
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	strb r4, [r2]
_0801060C:
	adds r1, 0x1
	cmp r1, 0x3
	ble _080105F8
	cmp r3, 0
	beq _08010620
	adds r0, r3, 0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08010620:
	movs r1, 0
	ldr r2, =gUnknown_03005000+0xCD5
_08010624:
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, 0xA
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0801063C
	movs r0, 0x1
	b _08010644
	.pool
_0801063C:
	adds r1, 0x1
	cmp r1, 0x3
	ble _08010624
	movs r0, 0
_08010644:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80105EC

	thumb_func_start sub_801064C
sub_801064C: @ 801064C
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	lsls r2, 16
	lsrs r2, 16
	adds r1, r2, 0
	bl sub_8011CE4
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08010680
	ldr r0, =gUnknown_03005000
	ldr r2, =0x00000cd1
	adds r0, r2
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x9
	beq _08010680
	movs r0, 0
	b _08010682
	.pool
_08010680:
	movs r0, 0x1
_08010682:
	pop {r1}
	bx r1
	thumb_func_end sub_801064C

	thumb_func_start sub_8010688
sub_8010688: @ 8010688
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r0, r2, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 16
	lsrs r1, 16
	bl sub_8011CE4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_03005000
	ldr r0, =0x00000cd1
	adds r5, r0
	adds r5, r4, r5
	strb r6, [r5]
	movs r0, 0x4
	adds r1, r4, 0
	bl rfu_clearSlot
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r4
	lsrs r0, 24
	movs r1, 0x8
	adds r2, r5, 0
	movs r3, 0x1
	bl rfu_NI_setSendData
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010688

	thumb_func_start sub_80106D4
sub_80106D4: @ 80106D4
	push {r4,r5,lr}
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000c85
	adds r5, r4, r0
	movs r0, 0x8
	strb r0, [r5]
	ldr r0, =0x00000c3e
	adds r4, r0
	ldrb r1, [r4]
	movs r0, 0x4
	bl rfu_clearSlot
	ldrb r1, [r4]
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r0, 24
	movs r1, 0x8
	adds r2, r5, 0
	movs r3, 0x1
	bl rfu_NI_setSendData
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80106D4

	thumb_func_start sub_8010714
sub_8010714: @ 8010714
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	lsls r2, 16
	lsrs r2, 16
	adds r1, r2, 0
	bl sub_8011CE4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08010730
	movs r0, 0x2
	b _0801074A
_08010730:
	ldr r1, =gUnknown_03007880
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0
	beq _08010748
	movs r0, 0
	b _0801074A
	.pool
_08010748:
	movs r0, 0x1
_0801074A:
	pop {r1}
	bx r1
	thumb_func_end sub_8010714

	thumb_func_start sub_8010750
sub_8010750: @ 8010750
	push {r4,r5,lr}
	bl sub_8010540
	movs r4, 0
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cd5
	adds r5, r0, r1
_0801075E:
	ldr r1, =gUnknown_03007880
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	subs r0, 0x26
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _08010788
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, 0xA
	bne _0801077E
	movs r0, 0xB
	strb r0, [r1]
_0801077E:
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x4
	bl rfu_clearSlot
_08010788:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801075E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010750

	thumb_func_start sub_80107A0
sub_80107A0: @ 80107A0
	push {r4,r5,lr}
	movs r4, 0
	ldr r1, =gUnknown_03005000
	ldr r2, =0x00000c85
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _080107DA
	ldr r2, =gUnknown_03007880
	ldr r0, =0x00000c3e
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x26
	beq _080107D2
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x27
	bne _080107DA
_080107D2:
	ldrb r1, [r1]
	movs r0, 0x4
	bl rfu_clearSlot
_080107DA:
	ldr r2, =gUnknown_03007880
	ldr r5, =gUnknown_03005000
	ldr r0, =0x00000c3e
	adds r1, r5, r0
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, 0x34]
	cmp r0, 0x46
	beq _080107FE
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, 0x34]
	cmp r0, 0x48
	bne _0801082C
_080107FE:
	ldrb r1, [r1]
	movs r0, 0x8
	bl rfu_clearSlot
	ldr r2, =0x00000c86
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, 0
	bl sub_8011A64
	ldrb r4, [r4]
	b _08010844
	.pool
_0801082C:
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, 0x34]
	cmp r0, 0x47
	bne _08010844
	ldrb r1, [r1]
	movs r0, 0x8
	bl rfu_clearSlot
	movs r4, 0x6
_08010844:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80107A0

	thumb_func_start sub_801084C
sub_801084C: @ 801084C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gUnknown_03005000
	adds r0, r5, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08010872
	ldr r0, =0x00000ce8
	adds r1, r5, r0
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	bl DestroyTask
_08010872:
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r0, r1, r6
	lsls r0, 3
	adds r4, r0, r2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0x3
	beq _0801091C
	cmp r0, 0x3
	bgt _080108A4
	cmp r0, 0x1
	beq _080108CC
	cmp r0, 0x1
	bgt _08010918
	cmp r0, 0
	beq _080108B6
	b _080109D2
	.pool
_080108A4:
	cmp r0, 0x5
	beq _08010950
	cmp r0, 0x5
	blt _0801093E
	cmp r0, 0x6
	beq _08010984
	cmp r0, 0x65
	beq _08010904
	b _080109D2
_080108B6:
	bl sub_800FC60
	lsls r0, 24
	cmp r0, 0
	bne _080108C2
	b _080109D2
_080108C2:
	bl ResetBlockReceivedFlags
	bl sub_800B348
	b _08010948
_080108CC:
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	bne _0801090C
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080108E8
	movs r0, 0xF0
	lsls r0, 7
	bl sub_800FD14
	b _080108F0
	.pool
_080108E8:
	movs r0, 0xEE
	lsls r0, 7
	bl sub_800FD14
_080108F0:
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0x65
	strh r0, [r1, 0x8]
	b _080109D2
	.pool
_08010904:
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	bne _080109D2
_0801090C:
	movs r0, 0x2
	strh r0, [r4, 0x8]
	b _080109D2
	.pool
_08010918:
	ldrb r0, [r5, 0xD]
	b _08010944
_0801091C:
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	bne _08010948
	bl sub_800FC60
	lsls r0, 24
	cmp r0, 0
	beq _080109D2
	adds r1, r5, 0
	adds r1, 0x5A
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xA1
	lsls r0, 8
	bl sub_800FD14
	b _08010948
_0801093E:
	bl sub_800FC88
	lsls r0, 24
_08010944:
	cmp r0, 0
	beq _080109D2
_08010948:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080109D2
_08010950:
	movs r4, 0
	ldrb r0, [r5, 0xD]
	cmp r4, r0
	bge _0801096E
_08010958:
	adds r0, r4, 0
	bl sub_800B3A4
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_800F728
	adds r4, 0x1
	ldrb r2, [r5, 0xD]
	cmp r4, r2
	blt _08010958
_0801096E:
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080109D2
	.pool
_08010984:
	adds r0, r6, 0
	bl DestroyTask
	ldr r1, =gReceivedRemoteLinkPlayers
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x00000ce8
	adds r1, r5, r0
	movs r0, 0
	strb r0, [r1]
	movs r1, 0x96
	lsls r1, 2
	movs r0, 0x1
	bl sub_800D550
	ldr r2, =0x00000ce6
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080109D2
	movs r4, 0
	adds r2, r1, 0
	movs r3, 0x1
	ldr r0, =0x00000ce5
	adds r5, r0
_080109B6:
	ldrb r0, [r2]
	asrs r0, r4
	ands r0, r3
	cmp r0, 0
	beq _080109CC
	adds r0, r3, 0
	lsls r0, r4
	strb r0, [r5]
	ldrb r1, [r2]
	eors r0, r1
	strb r0, [r2]
_080109CC:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080109B6
_080109D2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801084C

	thumb_func_start sub_80109E8
sub_80109E8: @ 80109E8
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	movs r5, 0x1
	ldr r4, =gUnknown_03005000+0xCDE
	movs r3, 0
_080109F6:
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _08010A04
	adds r0, r1, r4
	strb r3, [r0]
_08010A04:
	adds r1, 0x1
	cmp r1, 0x3
	ble _080109F6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80109E8

	thumb_func_start sub_8010A14
sub_8010A14: @ 8010A14
	push {r4-r7,lr}
	adds r2, r0, 0
	ldr r1, =gUnknown_03005000
	ldrb r0, [r2, 0xF]
	strb r0, [r1, 0xD]
	movs r4, 0
	ldr r0, =0x00000cde
	adds r5, r1, r0
	adds r3, r2, 0
	adds r3, 0x10
_08010A28:
	adds r0, r4, r5
	adds r1, r3, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _08010A28
	adds r6, r2, 0
	ldr r5, =gLinkPlayers
	movs r4, 0x4
_08010A3C:
	adds r0, r5, 0
	adds r1, r6, 0
	adds r1, 0x14
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldr r1, [r1]
	str r1, [r0]
	adds r0, r5, 0
	bl sub_800B524
	adds r6, 0x1C
	adds r5, 0x1C
	subs r4, 0x1
	cmp r4, 0
	bge _08010A3C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010A14

	thumb_func_start sub_8010A70
sub_8010A70: @ 8010A70
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =gUnknown_082ED7EC
	adds r1, r4, 0
	bl strcmp
	adds r5, r0, 0
	cmp r5, 0
	bne _08010A9C
	adds r0, r4, 0
	bl sub_8010A14
	mov r0, sp
	strh r5, [r0]
	ldr r2, =0x0100007e
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0
	bl ResetBlockReceivedFlag
_08010A9C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010A70

	thumb_func_start sub_8010AAC
sub_8010AAC: @ 8010AAC
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, =gUnknown_03005000
	ldr r2, =gUnknown_082ED68C
	ldr r1, =0x00000ce9
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r1, r2
	ldr r2, =0x00000cde
	adds r0, r3, r2
	ldrb r1, [r1]
	adds r0, r1
	ldrb r4, [r0]
	adds r0, r3, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08010AE8
	ldr r5, =0x00000ce8
	adds r1, r3, r5
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	bl DestroyTask
_08010AE8:
	ldr r0, =gTasks
	lsls r2, r6, 2
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	movs r3, 0x8
	ldrsh r1, [r1, r3]
	adds r3, r0, 0
	adds r7, r2, 0
	cmp r1, 0x5
	bls _08010B00
	b _08010CF0
_08010B00:
	lsls r0, r1, 2
	ldr r1, =_08010B28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08010B28:
	.4byte _08010B40
	.4byte _08010B60
	.4byte _08010B78
	.4byte _08010BC0
	.4byte _08010C0A
	.4byte _08010C94
_08010B40:
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	beq _08010B4A
	b _08010CF0
_08010B4A:
	adds r0, r4, 0
	bl ResetBlockReceivedFlag
	movs r0, 0xF0
	lsls r0, 7
	bl sub_800FD14
	b _08010C4A
	.pool
_08010B60:
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	beq _08010B6A
	b _08010CF0
_08010B6A:
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r3
	b _08010C52
	.pool
_08010B78:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08010B8C
	b _08010CF0
_08010B8C:
	adds r0, r4, 0
	bl ResetBlockReceivedFlag
	lsls r2, r4, 8
	ldr r0, =gBlockRecvBuffer
	adds r2, r0
	ldr r1, =gLinkPlayers
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	adds r1, r0, 0
	adds r2, 0x10
	ldm r2!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r2!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r2, [r2]
	str r2, [r1]
	bl sub_800B524
	b _08010C4A
	.pool
_08010BC0:
	ldr r5, =gBlockSendBuffer
	adds r1, r5, 0
	ldr r0, =gUnknown_082ED7EC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldrh r2, [r0]
	strh r2, [r1]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x2]
	ldr r1, =gUnknown_03005000
	ldrb r0, [r1, 0xD]
	strb r0, [r5, 0xF]
	movs r2, 0
	adds r4, r5, 0
	adds r4, 0x10
	ldr r0, =0x00000cde
	adds r3, r1, r0
_08010BE2:
	adds r0, r4, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08010BE2
	ldr r1, =gLinkPlayers
	adds r0, r5, 0
	adds r0, 0x14
	movs r2, 0x8C
	bl memcpy
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_08010C0A:
	ldr r5, =gBlockSendBuffer
	ldr r1, =gUnknown_03005000
	ldrb r0, [r1, 0xD]
	strb r0, [r5, 0xF]
	movs r2, 0
	ldr r3, =gLinkPlayers
	mov r12, r3
	adds r4, r5, 0
	adds r4, 0x10
	ldr r0, =0x00000cde
	adds r3, r1, r0
_08010C20:
	adds r0, r4, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08010C20
	adds r0, r5, 0
	adds r0, 0x14
	mov r1, r12
	movs r2, 0x8C
	bl memcpy
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0xA0
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _08010CF0
_08010C4A:
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
_08010C52:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08010CF0
	.pool
_08010C74:
	adds r0, r3, 0
	lsls r0, r2
	ldr r2, =0x00000ce5
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r4]
	eors r0, r1
	strb r0, [r4]
	ldr r4, =0x00000ce8
	adds r0, r5, r4
	strb r3, [r0]
	b _08010CEA
	.pool
_08010C94:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08010CF0
	bl GetBlockReceivedStatus
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08010CF0
	mov r0, sp
	movs r4, 0
	strh r4, [r0]
	ldr r1, =gBlockRecvBuffer
	ldr r2, =0x0100007e
	bl CpuSet
	movs r0, 0
	bl ResetBlockReceivedFlag
	ldr r1, =gUnknown_03005000
	ldr r5, =0x00000ce8
	adds r0, r1, r5
	strb r4, [r0]
	ldr r0, =0x00000ce6
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, 0
	beq _08010CEA
	movs r2, 0
	adds r5, r1, 0
	adds r4, r3, 0
	ldrb r1, [r4]
	movs r3, 0x1
_08010CDA:
	adds r0, r1, 0
	asrs r0, r2
	ands r0, r3
	cmp r0, 0
	bne _08010C74
	adds r2, 0x1
	cmp r2, 0x3
	ble _08010CDA
_08010CEA:
	adds r0, r6, 0
	bl DestroyTask
_08010CF0:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010AAC

	thumb_func_start sub_8010D0C
sub_8010D0C: @ 8010D0C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gUnknown_03005000
	adds r0, r6, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08010D2A
	adds r0, r5, 0
	bl DestroyTask
_08010D2A:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08010D70
	cmp r0, 0x1
	bgt _08010D50
	cmp r0, 0
	beq _08010D56
	b _08010DA6
	.pool
_08010D50:
	cmp r0, 0x2
	beq _08010D82
	b _08010DA6
_08010D56:
	ldrb r0, [r6, 0xD]
	cmp r0, 0
	beq _08010DA6
	bl sub_800B348
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0x3C
	bl SendBlock
	b _08010D7A
	.pool
_08010D70:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08010DA6
_08010D7A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08010DA6
_08010D82:
	bl GetBlockReceivedStatus
	movs r4, 0x1
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	beq _08010DA6
	ldr r0, =gBlockRecvBuffer
	bl sub_8010A14
	movs r0, 0
	bl ResetBlockReceivedFlag
	ldr r0, =gReceivedRemoteLinkPlayers
	strb r4, [r0]
	adds r0, r5, 0
	bl DestroyTask
_08010DA6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010D0C

	thumb_func_start sub_8010DB4
sub_8010DB4: @ 8010DB4
	push {r4-r7,lr}
	ldr r0, =gUnknown_03005000
	adds r1, r0, 0
	adds r1, 0xEE
	ldrb r1, [r1]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _08010E5C
	ldr r2, =gUnknown_03004140
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _08010E5C
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8018438
	cmp r1, r0
	beq _08010DDE
	ldr r0, [r2, 0x3C]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08010DE4
_08010DDE:
	ldr r1, =gWirelessCommType
	movs r0, 0x2
	strb r0, [r1]
_08010DE4:
	ldr r4, =CB2_LinkError
	adds r0, r4, 0
	bl SetMainCallback2
	ldr r0, =gMain
	str r4, [r0, 0x8]
	ldr r5, =gUnknown_03005000
	ldrh r0, [r5, 0xA]
	lsls r4, r0, 16
	ldrh r0, [r5, 0x10]
	lsls r0, 8
	orrs r4, r0
	ldrh r0, [r5, 0x12]
	orrs r4, r0
	ldr r1, =0x000009e6
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r0, 0
	ldr r1, =0x00000c1a
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r6, r0, 0
	bl sub_8011A74
	movs r3, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08010E20
	movs r3, 0x1
_08010E20:
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_800AF18
	adds r0, r5, 0
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0x2
	strb r1, [r0]
	bl CloseLink
	b _08010E8E
	.pool
_08010E5C:
	ldr r1, =0x00000c1b
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08010E70
	ldr r1, =0x000009e7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08010E8E
_08010E70:
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _08010E7C
	bl sub_800D630
_08010E7C:
	movs r4, 0xE0
	lsls r4, 7
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	adds r0, r4, 0
	bl sub_8011170
_08010E8E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010DB4

	thumb_func_start rfu_REQ_recvData_then_sendData
rfu_REQ_recvData_then_sendData: @ 8010EA0
	push {lr}
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x6]
	cmp r0, 0x1
	bne _08010EB8
	bl rfu_REQ_recvData
	bl rfu_waitREQComplete
	movs r0, 0
	bl rfu_REQ_sendData_wrapper
_08010EB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end rfu_REQ_recvData_then_sendData

	thumb_func_start sub_8010EC0
sub_8010EC0: @ 8010EC0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ccd
	adds r0, r4, r1
	strb r5, [r0]
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C54C
	adds r0, r4, 0
	adds r0, 0xEF
	ldrb r0, [r0]
	cmp r0, 0
	bne _08010F14
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08010F02
	cmp r0, 0x1
	bgt _08010EFC
	cmp r0, 0
	beq _08010F08
	b _08010F14
	.pool
_08010EFC:
	cmp r0, 0x2
	beq _08010F10
	b _08010F14
_08010F02:
	bl sub_800F0F8
	b _08010F14
_08010F08:
	bl sub_800F4F0
	adds r5, r0, 0
	b _08010F14
_08010F10:
	bl rfu_REQ_recvData_then_sendData
_08010F14:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8010EC0

	thumb_func_start sub_8010F1C
sub_8010F1C: @ 8010F1C
	push {r4,lr}
	movs r4, 0
	ldr r1, =gUnknown_03005000
	adds r0, r1, 0
	adds r0, 0xEF
	ldrb r0, [r0]
	cmp r0, 0
	bne _08010F3C
	ldrb r0, [r1, 0xC]
	cmp r0, 0x1
	bne _08010F38
	bl sub_800F1E0
	adds r4, r0, 0
_08010F38:
	bl sub_8010DB4
_08010F3C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8010F1C

	thumb_func_start sub_8010F48
sub_8010F48: @ 8010F48
	push {lr}
	ldr r0, =gUnknown_02022B14 + 0xE
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010F48

	thumb_func_start sub_8010F60
sub_8010F60: @ 8010F60
	push {r4,lr}
	ldr r4, =gUnknown_02022B14
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xD
	bl memset
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_800DD94
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010F60

	thumb_func_start sub_8010F84
sub_8010F84: @ 8010F84
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02022B14
	adds r1, r4, 0
	bl sub_800DD94
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010F84

	thumb_func_start sub_8010FA0
sub_8010FA0: @ 8010FA0
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022B14
	movs r4, 0x1
	ands r0, r4
	lsls r0, 4
	ldrb r3, [r5]
	movs r2, 0x11
	negs r2, r2
	ands r2, r3
	orrs r2, r0
	ands r1, r4
	lsls r1, 5
	movs r0, 0x21
	negs r0, r0
	ands r2, r0
	orrs r2, r1
	strb r2, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010FA0

	thumb_func_start sub_8010FCC
sub_8010FCC: @ 8010FCC
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022B14
	lsls r0, 2
	ldrb r4, [r5, 0x9]
	movs r3, 0x3
	ands r3, r4
	orrs r3, r0
	strb r3, [r5, 0x9]
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldrh r3, [r5, 0x8]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r1
	strh r0, [r5, 0x8]
	lsls r2, 1
	ldrb r1, [r5, 0xB]
	movs r0, 0x1
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0xB]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010FCC

	thumb_func_start sub_801100C
sub_801100C: @ 801100C
	push {r4,lr}
	movs r4, 0x80
	ldr r3, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r0, r1, r3
	ldrb r2, [r0, 0x13]
	lsls r2, 3
	orrs r2, r4
	adds r3, 0x4
	adds r1, r3
	ldr r0, [r1]
	movs r1, 0x7
	ands r0, r1
	orrs r0, r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801100C

	thumb_func_start sub_801103C
sub_801103C: @ 801103C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022B14
	movs r4, 0x1
	b _08011054
	.pool
_08011048:
	adds r0, r4, 0
	bl sub_801100C
	adds r1, r5, r4
	strb r0, [r1, 0x3]
	adds r4, 0x1
_08011054:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _08011048
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801103C

	thumb_func_start sub_8011068
sub_8011068: @ 8011068
	push {lr}
	lsls r0, 24
	ldr r2, =gUnknown_02022B14
	lsrs r0, 17
	ldrb r3, [r2, 0xA]
	movs r1, 0x7F
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0xA]
	ldr r3, =gUnknown_02022B14 + 0xE
	movs r0, 0
	movs r1, 0x2
	bl rfu_REQ_configGameData
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011068

	thumb_func_start sub_8011090
sub_8011090: @ 8011090
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0801109E
	bl sub_8010F84
_0801109E:
	ldr r2, =gUnknown_02022B14
	ldr r3, =gUnknown_02022B14 + 0xE
	movs r0, 0
	movs r1, 0x2
	bl rfu_REQ_configGameData
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011090

	thumb_func_start sub_80110B8
sub_80110B8: @ 80110B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	bne _0801114C
	movs r5, 0
	movs r7, 0
	ldr r3, =gUnknown_03005000
	ldr r1, =0x00000ce2
	adds r0, r3, r1
	ldr r2, =0x00000ce3
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	adds r1, r0, 0
	eors r1, r2
	mov r8, r1
	movs r4, 0
	movs r6, 0x1
	ldr r2, =gLinkPlayers
	mov r12, r2
	ldr r0, =0x00000cde
	adds r0, r3
	mov r10, r0
	mov r3, r12
	adds r3, 0x4
_080110FC:
	mov r0, r8
	asrs r0, r4
	ands r0, r6
	cmp r0, 0
	beq _0801113C
	mov r1, r10
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r2, r12
	adds r1, r0, r2
	ldrb r1, [r1, 0x13]
	adds r2, r6, 0
	ands r2, r1
	lsls r2, 3
	adds r0, r3
	ldr r1, [r0]
	movs r0, 0x7
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	orrs r2, r1
	lsls r0, r5, 3
	lsls r2, r0
	orrs r7, r2
	adds r5, 0x1
	mov r0, r9
	subs r0, 0x1
	cmp r5, r0
	beq _08011142
_0801113C:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080110FC
_08011142:
	movs r0, 0x45
	adds r1, r7, 0
	movs r2, 0
	bl sub_8011090
_0801114C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80110B8

	thumb_func_start sub_8011170
sub_8011170: @ 8011170
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_03005000
	adds r3, r2, 0
	adds r3, 0xEE
	ldrb r0, [r3]
	cmp r0, 0
	bne _08011192
	ldr r1, =gUnknown_03004140
	ldrh r0, [r1, 0x14]
	strh r0, [r2, 0x10]
	ldrh r0, [r1, 0x16]
	strh r0, [r2, 0x12]
	strh r4, [r2, 0xA]
	ldrb r0, [r3]
	movs r0, 0x1
	strb r0, [r3]
_08011192:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011170

	thumb_func_start sub_80111A0
sub_80111A0: @ 80111A0
	ldr r0, =gUnknown_03005000
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80111A0

	thumb_func_start sub_80111B0
sub_80111B0: @ 80111B0
	push {lr}
	adds r2, r0, 0
	cmp r2, 0
	bne _080111C8
	ldr r0, =gUnknown_03005000
	adds r0, 0xEE
	ldrb r1, [r0]
	strb r2, [r0]
	b _080111D2
	.pool
_080111C8:
	ldr r0, =gUnknown_03005000
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0x4
	strb r1, [r0]
_080111D2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80111B0

	thumb_func_start sub_80111DC
sub_80111DC: @ 80111DC
	push {lr}
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_8011E94
	ldr r1, =gUnknown_03005000
	movs r0, 0
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80111DC

	thumb_func_start sub_80111FC
sub_80111FC: @ 80111FC
	ldr r1, =gUnknown_03005000
	ldr r0, =sub_80111DC
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80111FC

	thumb_func_start sub_801120C
sub_801120C: @ 801120C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r6, 0
	cmp r4, 0x32
	bne _08011222
	b _08011360
_08011222:
	cmp r4, 0x32
	bgt _08011252
	cmp r4, 0x13
	bgt _08011240
	cmp r4, 0x12
	blt _08011230
	b _080113EE
_08011230:
	cmp r4, 0x10
	bne _08011236
	b _080113EE
_08011236:
	cmp r4, 0x10
	bgt _0801128C
	cmp r4, 0
	beq _0801127E
	b _080113EE
_08011240:
	cmp r4, 0x30
	bne _08011246
	b _0801136C
_08011246:
	cmp r4, 0x30
	ble _0801124C
	b _08011354
_0801124C:
	cmp r4, 0x14
	beq _08011328
	b _080113EE
_08011252:
	cmp r4, 0x44
	bgt _08011264
	cmp r4, 0x42
	blt _0801125C
	b _080113EE
_0801125C:
	cmp r4, 0x33
	bne _08011262
	b _0801136C
_08011262:
	b _080113EE
_08011264:
	cmp r4, 0xF3
	bne _0801126A
	b _080113BA
_0801126A:
	cmp r4, 0xF3
	bgt _08011276
	cmp r4, 0xF0
	bge _08011274
	b _080113EE
_08011274:
	b _080113D4
_08011276:
	cmp r4, 0xFF
	bne _0801127C
	b _080113D4
_0801127C:
	b _080113EE
_0801127E:
	ldr r1, =gUnknown_03005000
	movs r0, 0x2
	strh r0, [r1, 0x4]
	b _080113EE
	.pool
_0801128C:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	bl sub_80115EC
	movs r5, 0
	movs r0, 0x1
	mov r8, r0
	ldr r1, =gUnknown_03005000
	mov r9, r1
	ldr r3, =0x00000cd5
	add r3, r9
	mov r10, r3
	movs r7, 0x7F
_080112A6:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	asrs r0, r5
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0801130E
	ldr r0, =gUnknown_03007890
	lsls r1, r5, 5
	adds r1, 0x14
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0, 0x10]
	adds r4, r7, 0
	ands r4, r0
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	adds r0, r7, 0
	ands r0, r1
	cmp r4, r0
	bne _08011304
	ldr r0, =0x00000cd1
	add r0, r9
	adds r0, r5, r0
	movs r1, 0
	strb r1, [r0]
	mov r3, r10
	adds r2, r5, r3
	strb r1, [r2]
	movs r0, 0x20
	adds r1, r5, 0
	movs r3, 0x1
	bl rfu_setRecvBuffer
	b _0801130E
	.pool
_08011304:
	mov r0, r8
	lsls r0, r5
	orrs r6, r0
	lsls r0, r6, 24
	lsrs r6, r0, 24
_0801130E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080112A6
	cmp r6, 0
	beq _080113EE
	adds r0, r6, 0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	b _080113EE
_08011328:
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ce7
	adds r0, r4, r1
	ldr r1, =gUnknown_03004140
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	beq _08011342
	eors r0, r2
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08011342:
	movs r0, 0x11
	strh r0, [r4, 0x4]
	b _080113EE
	.pool
_08011354:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	b _080113EA
	.pool
_08011360:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x3
	b _080113EC
	.pool
_0801136C:
	ldr r1, =gUnknown_03005000
	adds r2, r1, 0
	adds r2, 0xF0
	movs r0, 0x4
	strb r0, [r2]
	ldr r3, =0x00000ce2
	adds r1, r3
	ldr r0, =gUnknown_03004140
	ldrb r2, [r0, 0x14]
	ldrb r0, [r1]
	adds r3, r0, 0
	bics r3, r2
	adds r2, r3, 0
	strb r2, [r1]
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080113B0
	cmp r2, 0
	bne _080113AC
	adds r0, r4, 0
	bl sub_8011170
	b _080113B0
	.pool
_080113AC:
	bl sub_80111FC
_080113B0:
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	b _080113EE
_080113BA:
	movs r0, 0x1
	movs r1, 0xF3
	bl sub_8011A64
	movs r0, 0xF3
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	adds r0, 0xEF
	b _080113EA
	.pool
_080113D4:
	adds r0, r4, 0
	bl sub_8011170
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cdb
	adds r0, r1
	ldrb r1, [r0]
_080113EA:
	movs r1, 0x1
_080113EC:
	strb r1, [r0]
_080113EE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801120C

	thumb_func_start sub_8011404
sub_8011404: @ 8011404
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x31
	bne _08011410
	b _08011570
_08011410:
	cmp r4, 0x31
	bgt _0801143E
	cmp r4, 0x22
	beq _08011494
	cmp r4, 0x22
	bgt _0801142C
	cmp r4, 0x20
	beq _0801147C
	cmp r4, 0x20
	ble _08011426
	b _080115DE
_08011426:
	cmp r4, 0
	beq _0801146E
	b _080115DE
_0801142C:
	cmp r4, 0x24
	beq _080114BA
	cmp r4, 0x24
	blt _080114B0
	cmp r4, 0x25
	beq _08011504
	cmp r4, 0x30
	beq _0801150E
	b _080115DE
_0801143E:
	cmp r4, 0x44
	bgt _08011454
	cmp r4, 0x42
	blt _08011448
	b _080115DE
_08011448:
	cmp r4, 0x33
	beq _08011522
	cmp r4, 0x33
	bge _08011452
	b _0801158C
_08011452:
	b _080115DE
_08011454:
	cmp r4, 0xF3
	bne _0801145A
	b _080115AC
_0801145A:
	cmp r4, 0xF3
	bgt _08011466
	cmp r4, 0xF0
	bge _08011464
	b _080115DE
_08011464:
	b _080115C4
_08011466:
	cmp r4, 0xFF
	bne _0801146C
	b _080115C4
_0801146C:
	b _080115DE
_0801146E:
	ldr r1, =gUnknown_03005000
	movs r0, 0x6
	strh r0, [r1, 0x4]
	b _080115DE
	.pool
_0801147C:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r2, =0x00000ccd
	adds r0, r2
	b _080115DC
	.pool
_08011494:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r2, =0x00000c3e
	adds r0, r2
	ldrb r2, [r0]
	b _080115DC
	.pool
_080114B0:
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	b _080115DE
_080114BA:
	ldr r4, =gUnknown_03005000
	movs r1, 0
	movs r0, 0xB
	strh r0, [r4, 0x4]
	ldr r2, =0x00000c85
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, =0x00000c86
	adds r2, r4, r0
	strb r1, [r2]
	ldr r1, =0x00000c3e
	adds r5, r4, r1
	ldrb r1, [r5]
	movs r0, 0x20
	movs r3, 0x1
	bl rfu_setRecvBuffer
	ldrb r1, [r5]
	ldr r2, =0x00000c3f
	adds r4, r2
	movs r0, 0x10
	adds r2, r4, 0
	movs r3, 0x46
	bl rfu_setRecvBuffer
	b _080115DE
	.pool
_08011504:
	movs r0, 0x2
	movs r1, 0x25
	bl sub_8011A64
	b _080115DE
_0801150E:
	ldr r0, =gUnknown_03005000
	adds r2, r0, 0
	adds r2, 0xF0
	movs r1, 0x2
	strb r1, [r2]
	ldr r1, =0x00000c86
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _080115DE
_08011522:
	ldr r2, =gUnknown_03005000
	adds r1, r2, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08011532
	movs r0, 0x4
	strb r0, [r1]
_08011532:
	ldr r1, =0x00000c86
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x9
	beq _08011544
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
_08011544:
	ldr r0, =gUnknown_082ED7FC
	movs r1, 0x5
	movs r2, 0x5
	bl nullsub_5
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080115DE
	adds r0, r4, 0
	bl sub_8011170
	b _080115DE
	.pool
_08011570:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, =gUnknown_082ED814
	movs r1, 0x5
	movs r2, 0x5
	bl nullsub_5
	b _080115DE
	.pool
_0801158C:
	ldr r1, =gUnknown_03005000
	adds r2, r1, 0
	adds r2, 0xF0
	movs r0, 0x3
	strb r0, [r2]
	ldr r2, =0x00000c3c
	adds r1, r2
	ldrb r0, [r1]
	movs r0, 0x1
	strb r0, [r1]
	b _080115DE
	.pool
_080115AC:
	movs r0, 0x1
	movs r1, 0xF3
	bl sub_8011A64
	movs r0, 0xF3
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	adds r0, 0xEF
	b _080115DA
	.pool
_080115C4:
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	adds r0, r4, 0
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cdb
	adds r0, r1
	ldrb r1, [r0]
_080115DA:
	movs r1, 0x1
_080115DC:
	strb r1, [r0]
_080115DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011404

	thumb_func_start sub_80115EC
sub_80115EC: @ 80115EC
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r2, 0
	movs r6, 0x1
	ldr r0, =gUnknown_03005000
	ldr r4, =0x00000cea
	adds r1, r0, r4
	movs r5, 0
	movs r4, 0xFF
_080115FE:
	adds r0, r3, 0
	asrs r0, r2
	ands r0, r6
	cmp r0, 0
	beq _08011610
	strb r5, [r1]
	ldrb r0, [r1, 0x4]
	orrs r0, r4
	strb r0, [r1, 0x4]
_08011610:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, 0x3
	ble _080115FE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80115EC

	thumb_func_start sub_8011628
sub_8011628: @ 8011628
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r3, 0
	movs r2, 0
	movs r4, 0x1
	ldr r6, =gUnknown_03007890
	movs r7, 0x7F
_08011636:
	adds r0, r5, 0
	asrs r0, r2
	ands r0, r4
	cmp r0, 0
	beq _0801165C
	lsls r1, r2, 5
	adds r1, 0x14
	ldr r0, [r6]
	adds r0, r1
	ldrb r1, [r0, 0x10]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x45
	bne _0801165C
	adds r0, r4, 0
	lsls r0, r2
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
_0801165C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _08011636
	adds r0, r3, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8011628

	thumb_func_start sub_8011674
sub_8011674: @ 8011674
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x25
	bne _08011680
	b _080118EC
_08011680:
	cmp r4, 0x25
	bgt _080116C2
	cmp r4, 0x14
	bne _0801168A
	b _08011804
_0801168A:
	cmp r4, 0x14
	bgt _080116A2
	cmp r4, 0x11
	beq _08011722
	cmp r4, 0x11
	ble _08011698
	b _08011A42
_08011698:
	cmp r4, 0
	beq _0801170C
	cmp r4, 0x10
	beq _08011718
	b _08011A42
_080116A2:
	cmp r4, 0x22
	bne _080116A8
	b _08011868
_080116A8:
	cmp r4, 0x22
	bgt _080116B4
	cmp r4, 0x20
	bne _080116B2
	b _08011850
_080116B2:
	b _08011A42
_080116B4:
	cmp r4, 0x23
	bne _080116BA
	b _08011884
_080116BA:
	cmp r4, 0x24
	bne _080116C0
	b _080118BA
_080116C0:
	b _08011A42
_080116C2:
	cmp r4, 0x44
	bgt _080116F2
	cmp r4, 0x42
	blt _080116CC
	b _08011A42
_080116CC:
	cmp r4, 0x32
	bne _080116D2
	b _08011914
_080116D2:
	cmp r4, 0x32
	bgt _080116E4
	cmp r4, 0x30
	bne _080116DC
	b _08011940
_080116DC:
	cmp r4, 0x31
	bne _080116E2
	b _080118F6
_080116E2:
	b _08011A42
_080116E4:
	cmp r4, 0x33
	bne _080116EA
	b _08011948
_080116EA:
	cmp r4, 0x40
	bne _080116F0
	b _080119FC
_080116F0:
	b _08011A42
_080116F2:
	cmp r4, 0xF3
	bne _080116F8
	b _08011A0C
_080116F8:
	cmp r4, 0xF3
	bgt _08011704
	cmp r4, 0xF0
	bge _08011702
	b _08011A42
_08011702:
	b _08011A28
_08011704:
	cmp r4, 0xFF
	bne _0801170A
	b _08011A28
_0801170A:
	b _08011A42
_0801170C:
	ldr r1, =gUnknown_03005000
	movs r0, 0x11
	strh r0, [r1, 0x4]
	b _08011A42
	.pool
_08011718:
	movs r0, 0x4
	movs r1, 0
	bl sub_8011A64
	b _08011A42
_08011722:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	bne _080117DC
	ldr r5, =gUnknown_03005000
	ldr r1, =0x00000cd9
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080117DC
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	bl sub_8011628
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080117A6
	adds r0, r4, 0
	bl sub_800E87C
	movs r2, 0x1
	mov r12, r2
	mov r1, r12
	lsls r1, r0
	lsls r1, 24
	lsrs r1, 24
	ldr r7, =0x00000ce6
	adds r6, r5, r7
	ldrb r2, [r6]
	cmp r2, 0
	bne _08011798
	ldr r0, =0x00000ce8
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, 0
	bne _08011798
	subs r7, 0x1
	adds r0, r5, r7
	strb r1, [r0]
	eors r1, r4
	orrs r1, r2
	strb r1, [r6]
	mov r0, r12
	strb r0, [r3]
	b _080117A6
	.pool
_08011798:
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrb r2, [r0]
	adds r1, r4, 0
	orrs r1, r2
	strb r1, [r0]
_080117A6:
	ldr r0, =gUnknown_03004140
	ldrh r1, [r0, 0x14]
	cmp r4, r1
	beq _080117F6
	ldr r2, =gUnknown_03005000
	ldr r7, =0x00000ce3
	adds r3, r2, r7
	adds r0, r4, 0
	eors r0, r1
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r3]
	ldr r0, =0x00000ce4
	adds r2, r0
	movs r0, 0x2
	strb r0, [r2]
	b _080117F6
	.pool
_080117DC:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x54
	bne _080117F6
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_080117F6:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	bl sub_80115EC
	b _08011A42
	.pool
_08011804:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	beq _08011836
	ldr r4, =gUnknown_03004140
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	bls _08011836
	ldrb r0, [r4, 0x14]
	bl sub_800E87C
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldrb r0, [r4]
	eors r1, r0
	adds r0, r1, 0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08011836:
	ldr r1, =gUnknown_03005000
	ldrh r0, [r1, 0x4]
	cmp r0, 0xF
	beq _08011840
	b _08011A42
_08011840:
	movs r0, 0x10
	strh r0, [r1, 0x4]
	b _08011A42
	.pool
_08011850:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r2, =0x00000ccd
	adds r0, r2
	b _08011A40
	.pool
_08011868:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r7, =0x00000c3e
	adds r0, r7
	ldrb r2, [r0]
	b _08011A40
	.pool
_08011884:
	ldr r1, =gUnknown_03005000
	movs r0, 0x12
	strh r0, [r1, 0x4]
	ldr r0, =0x00000ccf
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x1
	bhi _080118B0
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =sub_801209C
	movs r1, 0x2
	bl CreateTask
	b _08011A42
	.pool
_080118B0:
	movs r0, 0x2
	movs r1, 0x23
	bl sub_8011A64
	b _08011A42
_080118BA:
	ldr r4, =gUnknown_03005000
	movs r0, 0xD
	strh r0, [r4, 0x4]
	movs r0, 0x3
	movs r1, 0
	bl sub_8011A64
	ldr r1, =0x00000c3e
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, =0x00000c3f
	adds r4, r2
	movs r0, 0x10
	adds r2, r4, 0
	movs r3, 0x46
	bl rfu_setRecvBuffer
	b _08011A42
	.pool
_080118EC:
	movs r0, 0x2
	movs r1, 0x25
	bl sub_8011A64
	b _08011A42
_080118F6:
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0]
	ldrh r0, [r0, 0x14]
	ands r1, r0
	cmp r1, 0
	bne _08011904
	b _08011A42
_08011904:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x1
	b _08011A40
	.pool
_08011914:
	ldr r2, =gUnknown_03005000
	adds r1, r2, 0
	adds r1, 0xF0
	movs r0, 0x3
	strb r0, [r1]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801192A
	b _08011A42
_0801192A:
	ldr r7, =0x00000c3c
	adds r0, r2, r7
	ldrb r1, [r0]
	movs r1, 0x1
	b _08011A40
	.pool
_08011940:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x2
	strb r1, [r0]
_08011948:
	ldr r2, =gUnknown_03005000
	adds r1, r2, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08011958
	movs r0, 0x4
	strb r0, [r1]
_08011958:
	ldrb r0, [r2, 0xC]
	cmp r0, 0x1
	bne _08011996
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080119B4
	ldr r0, =0x00000ce2
	adds r2, r0
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	cmp r0, 0
	bne _08011990
	adds r0, r4, 0
	bl sub_8011170
	b _080119B4
	.pool
_08011990:
	bl sub_80111FC
	b _080119B4
_08011996:
	ldr r1, =0x00000ce4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080119B4
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080119B4
	adds r0, r4, 0
	bl sub_8011170
	movs r0, 0
	bl sub_800C27C
_080119B4:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080119DA
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080119DA
	ldr r0, =sub_800EB44
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080119DA
	ldr r1, =gUnknown_03005000
	movs r0, 0x11
	strh r0, [r1, 0x4]
_080119DA:
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	b _08011A42
	.pool
_080119FC:
	ldr r0, =gUnknown_03005000
	ldr r2, =0x00000ce3
	adds r0, r2
	b _08011A3E
	.pool
_08011A0C:
	movs r0, 0x1
	movs r1, 0xF3
	bl sub_8011A64
	movs r0, 0xF3
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	adds r0, 0xEF
	movs r1, 0x1
	b _08011A40
	.pool
_08011A28:
	adds r0, r4, 0
	bl sub_8011170
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	ldr r0, =gUnknown_03005000
	ldr r7, =0x00000cdb
	adds r0, r7
	ldrb r1, [r0]
_08011A3E:
	movs r1, 0
_08011A40:
	strb r1, [r0]
_08011A42:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011674

	thumb_func_start sub_8011A50
sub_8011A50: @ 8011A50
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce4
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8011A50

	thumb_func_start sub_8011A64
sub_8011A64: @ 8011A64
	ldr r2, =gUnknown_03005000
	adds r3, r2, 0
	adds r3, 0xF1
	strb r0, [r3]
	strh r1, [r2, 0xA]
	bx lr
	.pool
	thumb_func_end sub_8011A64

	thumb_func_start sub_8011A74
sub_8011A74: @ 8011A74
	ldr r0, =gUnknown_03005000
	adds r0, 0xF1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8011A74

	thumb_func_start sub_8011A80
sub_8011A80: @ 8011A80
	push {lr}
	bl sub_8011A74
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x1
	bls _08011A94
	movs r0, 0
	b _08011A96
_08011A94:
	movs r0, 0x1
_08011A96:
	pop {r1}
	bx r1
	thumb_func_end sub_8011A80

	thumb_func_start sub_8011A9C
sub_8011A9C: @ 8011A9C
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce8
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8011A9C

	thumb_func_start Rfu_IsMaster
Rfu_IsMaster: @ 8011AB0
	ldr r0, =gUnknown_03005000
	ldrb r0, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end Rfu_IsMaster

	thumb_func_start RfuVSync
RfuVSync: @ 8011ABC
	push {lr}
	bl rfu_syncVBlank_
	pop {r0}
	bx r0
	thumb_func_end RfuVSync

	thumb_func_start sub_8011AC8
sub_8011AC8: @ 8011AC8
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r1, =gRecvCmds
	ldr r2, =0x05000014
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011AC8

	thumb_func_start sub_8011AE8
sub_8011AE8: @ 8011AE8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8011AE8

	thumb_func_start sub_8011AFC
sub_8011AFC: @ 8011AFC
	push {r4,lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl ResetPaletteFade
	ldr r0, =sub_8011AE8
	bl SetVBlankCallback
	bl sub_80093CC
	lsls r0, 24
	cmp r0, 0
	beq _08011B70
	ldr r1, =gLinkType
	ldr r2, =0x00001111
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_800B488
	bl OpenLink
	ldr r0, =gMain
	ldrh r0, [r0, 0x24]
	bl SeedRng
	movs r4, 0
_08011B38:
	bl Random
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	adds r1, 0xA
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x3
	ble _08011B38
	movs r1, 0xAA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	bl sub_8011BA4
	ldr r0, =sub_8011BF8
	bl SetMainCallback2
_08011B70:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011AFC

	thumb_func_start sub_8011B90
sub_8011B90: @ 8011B90
	push {lr}
	ldr r0, =sub_800EB44
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8011B90

	thumb_func_start sub_8011BA4
sub_8011BA4: @ 8011BA4
	push {r4,lr}
	ldr r4, =nullsub_89
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _08011BC2
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	ldr r1, =gUnknown_03005000
	adds r1, 0x66
	strb r0, [r1]
_08011BC2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011BA4

	thumb_func_start sub_8011BD0
sub_8011BD0: @ 8011BD0
	push {lr}
	ldr r0, =nullsub_89
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08011BEA
	ldr r0, =gUnknown_03005000
	adds r0, 0x66
	ldrb r0, [r0]
	bl DestroyTask
_08011BEA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011BD0

	thumb_func_start sub_8011BF8
sub_8011BF8: @ 8011BF8
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_8011BF8

	thumb_func_start sub_8011C10
sub_8011C10: @ 8011C10
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_03005000
	movs r0, 0x1
	strb r0, [r1, 0xC]
	bl sub_8010F48
	ldr r0, =sub_801120C
	movs r1, 0
	bl sub_800BF4C
	ldr r2, =gUnknown_02022B2C
	adds r1, r2, 0
	ldr r0, =gUnknown_082ED608
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, =gUnknown_082ED620
	subs r4, 0x1
	adds r4, r0
	ldrb r0, [r4]
	strh r0, [r2, 0x2]
	bl sub_800EE78
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011C10

	thumb_func_start sub_8011C5C
sub_8011C5C: @ 8011C5C
	push {lr}
	ldr r1, =gUnknown_03005000
	movs r0, 0
	strb r0, [r1, 0xC]
	bl sub_8010F48
	ldr r0, =sub_8011404
	ldr r1, =sub_800ED34
	bl sub_800BF4C
	bl sub_800EF00
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011C5C

	thumb_func_start sub_8011C84
sub_8011C84: @ 8011C84
	push {r4-r7,lr}
	ldr r4, =gUnknown_03005000
	movs r5, 0
	movs r0, 0x2
	strb r0, [r4, 0xC]
	bl sub_8010F48
	ldr r0, =sub_8011674
	movs r1, 0
	bl sub_800BF4C
	ldr r2, =gUnknown_02022B2C
	adds r1, r2, 0
	ldr r0, =gUnknown_082ED608
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	strb r5, [r2, 0x11]
	movs r0, 0x96
	lsls r0, 2
	strh r0, [r2, 0x12]
	ldr r0, =sub_800EB44
	movs r1, 0x1
	bl CreateTask
	adds r4, 0x67
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011C84

	thumb_func_start sub_8011CD8
sub_8011CD8: @ 8011CD8
	ldrb r1, [r0, 0x1]
	lsls r1, 8
	ldrb r0, [r0]
	orrs r0, r1
	bx lr
	thumb_func_end sub_8011CD8

	thumb_func_start sub_8011CE4
sub_8011CE4: @ 8011CE4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	movs r0, 0xFF
	mov r9, r0
	movs r7, 0
	ldr r1, =gUnknown_03007890
	mov r8, r1
_08011D02:
	lsls r4, r7, 5
	adds r5, r4, 0
	adds r5, 0x14
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	adds r0, 0x8
	bl sub_8011CD8
	lsls r0, 16
	lsrs r6, r0, 16
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	ldrh r0, [r0, 0x18]
	bl sub_8010454
	cmp r0, 0
	beq _08011D4C
	mov r0, r8
	ldr r1, [r0]
	adds r1, r5
	adds r1, 0x15
	ldr r0, [sp]
	bl StringCompare
	cmp r0, 0
	bne _08011D4C
	cmp r10, r6
	bne _08011D4C
	mov r9, r7
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0, 0x16]
	cmp r0, 0xFF
	bne _08011D56
_08011D4C:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _08011D02
_08011D56:
	mov r0, r9
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8011CE4

	thumb_func_start sub_8011D6C
sub_8011D6C: @ 8011D6C
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r0, r6, 24
	lsrs r0, 24
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000ce2
	adds r5, r4, r0
	ldrb r0, [r5]
	bics r0, r6
	strb r0, [r5]
	ldr r1, =0x00000cda
	adds r6, r4, r1
	ldrb r1, [r6]
	movs r0, 0x1
	bl rfu_clearSlot
	ldrb r0, [r5]
	ldr r1, =0x00000c87
	adds r4, r1
	adds r1, r4, 0
	movs r2, 0x46
	bl rfu_UNI_setSendData
	ldrb r0, [r5]
	bl sub_800E87C
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011D6C

	thumb_func_start sub_8011DC0
sub_8011DC0: @ 8011DC0
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_8011CE4
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08011DDA
	movs r0, 0x1
	lsls r0, r1
	bl sub_8011D6C
_08011DDA:
	pop {r0}
	bx r0
	thumb_func_end sub_8011DC0

	thumb_func_start sub_8011DE0
sub_8011DE0: @ 8011DE0
	push {r4-r6,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _08011E20
	movs r3, 0
	movs r2, 0
	ldr r5, =gUnknown_03005000+0xCDE
	adds r6, r5, 0x4
_08011DF0:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _08011E0E
	ldrb r0, [r6]
	asrs r0, r2
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08011E0E
	adds r0, r1, 0
	lsls r0, r2
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
_08011E0E:
	adds r2, 0x1
	cmp r2, 0x3
	ble _08011DF0
	cmp r3, 0
	beq _08011E20
	adds r0, r3, 0
	movs r1, 0x2
	bl sub_8011E94
_08011E20:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011DE0

	thumb_func_start sub_8011E2C
sub_8011E2C: @ 8011E2C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gSendCmd
	ldrh r0, [r6]
	cmp r0, 0
	bne _08011E7A
	ldr r5, =gUnknown_03005000
	ldr r1, =0x00000ce8
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08011E7A
	movs r0, 0xED
	lsls r0, 8
	bl sub_800FD14
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	strh r1, [r6, 0x2]
	ldrh r1, [r0, 0xA]
	strh r1, [r6, 0x4]
	ldr r1, =gUnknown_082ED695
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r1, [r5, 0xD]
	ldrb r0, [r0]
	subs r1, r0
	strb r1, [r5, 0xD]
	ldrb r0, [r5, 0xD]
	strh r0, [r6, 0x6]
	adds r0, r4, 0
	bl DestroyTask
_08011E7A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011E2C

	thumb_func_start sub_8011E94
sub_8011E94: @ 8011E94
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r5, =sub_8011E2C
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _08011ECC
	adds r0, r5, 0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	b _08011EDC
	.pool
_08011ECC:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	orrs r4, r0
	strh r4, [r1, 0x8]
_08011EDC:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0xA]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011E94

	thumb_func_start sub_8011EF4
sub_8011EF4: @ 8011EF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_800EE94
	lsls r0, 24
	cmp r0, 0
	beq _08011FA4
	adds r0, r4, 0
	adds r0, 0x10
	bl sub_8011CD8
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_8011CE4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _08011F8C
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	lsls r1, r2, 5
	adds r0, r1
	ldrb r0, [r0, 0x16]
	cmp r0, 0xFF
	beq _08011F5C
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c3d
	adds r0, r1
	strb r2, [r0]
	bl sub_800EEBC
	cmp r0, 0
	beq _08011FAA
	b _08011F84
	.pool
_08011F5C:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r5, 0x7F
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x15
	beq _08011FA4
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x16
	beq _08011FA4
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
_08011F84:
	adds r0, r6, 0
	bl DestroyTask
	b _08011FAA
_08011F8C:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c3d
	adds r0, r1
	strb r2, [r0]
	b _08011FAA
	.pool
_08011FA4:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
_08011FAA:
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF0
	ble _08011FC2
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	adds r0, r6, 0
	bl DestroyTask
_08011FC2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8011EF4

	thumb_func_start sub_8011FC8
sub_8011FC8: @ 8011FC8
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r5, r1, 16
	lsrs r5, 16
	ldr r0, =gUnknown_03005000
	adds r0, 0xF1
	movs r1, 0
	strb r1, [r0]
	ldr r0, =sub_8011EF4
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	adds r0, r4, 0
	adds r1, r6, 0
	bl StringCopy
	strh r5, [r4, 0x10]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011FC8

	thumb_func_start sub_801200C
sub_801200C: @ 801200C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r5, r0, 16
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r2, 0x7F
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x45
	bne _08012032
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x45
	beq _08012092
_0801202E:
	movs r0, 0x1
	b _08012094
_08012032:
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x40
	bne _0801202E
	cmp r5, 0x44
	bne _08012092
	ldr r5, =gUnknown_03005000+0x10A
	ldrh r0, [r5, 0x8]
	ldr r3, =0x000003ff
	adds r2, r3, 0
	ands r2, r0
	movs r0, 0xCE
	lsls r0, 1
	cmp r2, r0
	bne _08012068
	ldrh r1, [r4, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, r2
	beq _08012092
	b _0801202E
	.pool
_08012068:
	ldrh r1, [r4, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, r2
	bne _0801202E
	ldrb r2, [r4, 0xB]
	movs r0, 0xFE
	ldrb r3, [r5, 0xB]
	adds r1, r0, 0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _0801202E
	ldrb r2, [r4, 0x9]
	movs r0, 0xFC
	ldrb r3, [r5, 0x9]
	adds r1, r0, 0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _0801202E
_08012092:
	movs r0, 0
_08012094:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801200C

	thumb_func_start sub_801209C
sub_801209C: @ 801209C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	mov r8, r5
	ldr r6, =gUnknown_03005000
	adds r0, r6, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080120BA
	adds r0, r5, 0
	bl DestroyTask
_080120BA:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 17
	cmp r0, r1
	ble _080120E4
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	adds r0, r5, 0
	bl DestroyTask
_080120E4:
	ldr r1, =0x00000ccd
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801217C
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0801217C
	movs r2, 0x86
	lsls r2, 1
	adds r0, r6, r2
	bl sub_8011CD8
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =0x00000119
	adds r0, r6, r2
	bl sub_8011CE4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _0801217C
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	ldr r7, =gUnknown_03007890
	lsls r4, r2, 5
	adds r2, r4, 0
	adds r2, 0x14
	ldr r1, [r7]
	adds r1, r2
	adds r1, 0x6
	bl sub_801200C
	cmp r0, 0
	bne _0801216C
	ldr r0, [r7]
	adds r1, r0, r4
	ldrb r0, [r1, 0x16]
	cmp r0, 0xFF
	beq _0801217C
	ldrh r0, [r1, 0x14]
	movs r1, 0x5A
	bl sub_800C12C
	lsls r0, 24
	cmp r0, 0
	bne _0801217C
	movs r0, 0xA
	strh r0, [r6, 0x4]
	adds r0, r5, 0
	bl DestroyTask
	b _0801217C
	.pool
_0801216C:
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	mov r0, r8
	bl DestroyTask
_0801217C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801209C

	thumb_func_start sub_8012188
sub_8012188: @ 8012188
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	ldr r6, =gUnknown_03005000
	ldr r1, =0x00000ccf
	adds r0, r6, r1
	movs r7, 0
	strb r7, [r0]
	adds r0, r6, 0
	adds r0, 0xF1
	strb r7, [r0]
	ldr r1, =0x00000119
	adds r0, r6, r1
	adds r1, r3, 0
	bl StringCopy
	movs r1, 0x85
	lsls r1, 1
	adds r0, r6, r1
	adds r1, r5, 0
	movs r2, 0xD
	bl memcpy
	bl sub_800D658
	ldr r0, =sub_801209C
	movs r1, 0x2
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	strh r4, [r1, 0xA]
	ldr r0, =sub_800EB44
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	cmp r4, 0x45
	bne _08012210
	cmp r1, 0xFF
	beq _0801221E
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0, 0x16]
	b _0801221E
	.pool
_08012210:
	cmp r2, 0xFF
	beq _0801221E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r5
	strh r7, [r0, 0x16]
_0801221E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012188

	thumb_func_start sub_8012224
sub_8012224: @ 8012224
	push {lr}
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08012238
	movs r0, 0
	b _0801223A
	.pool
_08012238:
	movs r0, 0x1
_0801223A:
	pop {r1}
	bx r1
	thumb_func_end sub_8012224

	thumb_func_start sub_8012240
sub_8012240: @ 8012240
	push {r4,lr}
	movs r1, 0
	ldr r0, =gUnknown_03004140
	ldrb r2, [r0]
	ldr r4, =gUnknown_03005000+0xCD1
	movs r3, 0x1
_0801224C:
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0801226C
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801226C
	movs r0, 0
	b _08012274
	.pool
_0801226C:
	adds r1, 0x1
	cmp r1, 0x3
	ble _0801224C
	movs r0, 0x1
_08012274:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8012240

	thumb_func_start sub_801227C
sub_801227C: @ 801227C
	push {r4,lr}
	movs r4, 0
_08012280:
	lsls r2, r4, 24
	lsrs r2, 24
	ldr r0, =gUnknown_082ED82C
	movs r1, 0
	bl nullsub_5
	adds r4, 0x1
	cmp r4, 0x13
	ble _08012280
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801227C

	thumb_func_start sub_801229C
sub_801229C: @ 801229C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1C
	movs r2, 0x13
	movs r3, 0x2
	bl nullsub_13
	ldr r4, =gUnknown_03007890
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	movs r1, 0x14
	movs r2, 0x1
	movs r3, 0x1
	bl nullsub_13
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	movs r1, 0x17
	movs r2, 0x1
	movs r3, 0x1
	bl nullsub_13
	ldr r0, =gUnknown_03005000
	ldrb r0, [r0, 0xC]
	cmp r0, 0x1
	bne _08012378
	movs r6, 0
	adds r7, r4, 0
	movs r5, 0x14
_080122E0:
	ldr r2, [r7]
	ldrb r0, [r2, 0x7]
	asrs r0, r6
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801231E
	lsls r0, r6, 5
	adds r0, r2, r0
	ldrh r0, [r0, 0x18]
	adds r4, r6, 0x3
	lsls r4, 24
	lsrs r4, 24
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r5
	adds r0, 0x6
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, [r7]
	adds r0, r5
	adds r0, 0x15
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
_0801231E:
	adds r5, 0x20
	adds r6, 0x1
	cmp r6, 0x3
	ble _080122E0
	movs r6, 0
	ldr r0, =gUnknown_03005000
	mov r8, r0
_0801232C:
	movs r5, 0
	adds r7, r6, 0x1
	lsls r0, r6, 3
	adds r2, r6, 0
	adds r2, 0xB
	subs r0, r6
	lsls r0, 1
	mov r1, r8
	adds r1, 0x14
	adds r4, r0, r1
	lsls r6, r2, 24
_08012342:
	ldrb r0, [r4]
	lsls r1, r5, 25
	lsrs r1, 24
	lsrs r2, r6, 24
	movs r3, 0x2
	bl nullsub_13
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0xD
	ble _08012342
	adds r6, r7, 0
	cmp r6, 0x3
	ble _0801232C
	ldr r0, =gUnknown_082ED868
	movs r1, 0x1
	movs r2, 0xF
	bl nullsub_5
	b _080124AA
	.pool
_08012378:
	ldr r1, [r4]
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08012414
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08012414
	movs r6, 0
	movs r5, 0xC0
	lsls r5, 18
_0801238C:
	lsrs r4, r5, 24
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, =gUnknown_082ED84B
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, =gUnknown_082ED85B
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
	movs r1, 0x80
	lsls r1, 17
	adds r5, r1
	adds r6, 0x1
	cmp r6, 0x3
	ble _0801238C
	ldr r5, =gUnknown_03007890
	ldr r1, [r5]
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000c3e
	adds r4, r0
	ldrb r0, [r4]
	lsls r0, 5
	adds r1, r0
	ldrh r0, [r1, 0x18]
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x4
	bl nullsub_13
	ldrb r1, [r4]
	lsls r1, 5
	adds r1, 0x14
	ldr r0, [r5]
	adds r0, r1
	adds r0, 0x6
	movs r1, 0x6
	movs r2, 0x3
	bl nullsub_5
	ldrb r1, [r4]
	lsls r1, 5
	adds r1, 0x14
	ldr r0, [r5]
	adds r0, r1
	adds r0, 0x15
	movs r1, 0x16
	movs r2, 0x3
	bl nullsub_5
	b _080124AA
	.pool
_08012414:
	movs r6, 0
	ldr r1, =gUnknown_03007890
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	bge _08012470
	adds r7, r1, 0
	movs r1, 0x14
	mov r8, r1
_08012426:
	ldr r0, [r7]
	lsls r5, r6, 5
	adds r1, r0, r5
	ldrb r0, [r1, 0x16]
	cmp r0, 0xFF
	beq _08012462
	ldrh r0, [r1, 0x18]
	adds r4, r6, 0x3
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r5
	ldrh r0, [r0, 0x14]
	movs r1, 0x6
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	add r0, r8
	adds r0, 0x15
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
_08012462:
	movs r0, 0x20
	add r8, r0
	adds r6, 0x1
	ldr r0, [r7]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	blt _08012426
_08012470:
	cmp r6, 0x3
	bgt _080124AA
	lsls r0, r6, 24
	movs r1, 0xC0
	lsls r1, 18
	adds r5, r0, r1
_0801247C:
	lsrs r4, r5, 24
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, =gUnknown_082ED84B
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, =gUnknown_082ED85B
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
	movs r0, 0x80
	lsls r0, 17
	adds r5, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _0801247C
_080124AA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801229C

	thumb_func_start sub_80124C0
sub_80124C0: @ 80124C0
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c1a
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80124C0

	thumb_func_start sub_80124D4
sub_80124D4: @ 80124D4
	ldr r0, =gUnknown_03005000
	ldr r1, =0x000009e6
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80124D4

	.align 2, 0 @ don't pad with nop
