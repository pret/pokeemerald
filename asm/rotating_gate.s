	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetCurrentMapRotatingGatePuzzleType
GetCurrentMapRotatingGatePuzzleType: @ 80FB7E8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0x86
	lsls r0, 1
	cmp r1, r0
	bne _080FB800
	movs r0, 0x1
	b _080FB812
	.pool
_080FB800:
	ldr r0, =0x0000081d
	cmp r1, r0
	beq _080FB810
	movs r0, 0
	b _080FB812
	.pool
_080FB810:
	movs r0, 0x2
_080FB812:
	pop {r1}
	bx r1
	thumb_func_end GetCurrentMapRotatingGatePuzzleType

	thumb_func_start sub_80FB818
sub_80FB818: @ 80FB818
	push {r4-r6,lr}
	movs r0, 0x80
	lsls r0, 7
	bl GetVarPointer
	adds r5, r0, 0
	movs r3, 0
	ldr r4, =gUnknown_0203A048
	ldrb r0, [r4]
	cmp r3, r0
	bge _080FB844
	ldr r6, =gUnknown_0203A044
_080FB830:
	adds r2, r5, r3
	ldr r1, [r6]
	lsls r0, r3, 3
	adds r0, r1
	ldrb r0, [r0, 0x5]
	strb r0, [r2]
	adds r3, 0x1
	ldrb r0, [r4]
	cmp r3, r0
	blt _080FB830
_080FB844:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB818

	thumb_func_start sub_80FB854
sub_80FB854: @ 80FB854
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x80
	lsls r0, 7
	bl GetVarPointer
	adds r0, r4
	ldrb r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80FB854

	thumb_func_start sub_80FB870
sub_80FB870: @ 80FB870
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x80
	lsls r0, 7
	bl GetVarPointer
	adds r0, r4
	strb r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FB870

	thumb_func_start sub_80FB890
sub_80FB890: @ 80FB890
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_80FB854
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0x1
	bne _080FB8B4
	cmp r1, 0
	beq _080FB8B0
	subs r0, r1, 0x1
	lsls r0, 24
	b _080FB8BE
_080FB8B0:
	movs r1, 0x3
	b _080FB8C0
_080FB8B4:
	adds r1, 0x1
	lsls r1, 24
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r1
_080FB8BE:
	lsrs r1, r0, 24
_080FB8C0:
	adds r0, r5, 0
	bl sub_80FB870
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FB890

	thumb_func_start sub_80FB8CC
sub_80FB8CC: @ 80FB8CC
	push {lr}
	bl GetCurrentMapRotatingGatePuzzleType
	cmp r0, 0x1
	beq _080FB8E0
	cmp r0, 0x1
	ble _080FB914
	cmp r0, 0x2
	beq _080FB8F8
	b _080FB914
_080FB8E0:
	ldr r1, =gUnknown_0203A044
	ldr r0, =gUnknown_0858E8B0
	str r0, [r1]
	ldr r1, =gUnknown_0203A048
	movs r0, 0x8
	b _080FB902
	.pool
_080FB8F8:
	ldr r1, =gUnknown_0203A044
	ldr r0, =gUnknown_0858E8F0
	str r0, [r1]
	ldr r1, =gUnknown_0203A048
	movs r0, 0xB
_080FB902:
	strb r0, [r1]
	movs r1, 0
	ldr r3, =gUnknown_0203A038
	movs r2, 0x40
_080FB90A:
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0xA
	bls _080FB90A
_080FB914:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB8CC

	thumb_func_start sub_80FB928
sub_80FB928: @ 80FB928
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r1, [r2]
	subs r0, r1, 0x2
	lsls r0, 16
	lsrs r3, r0, 16
	adds r1, 0x11
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldrh r1, [r2, 0x2]
	subs r0, r1, 0x2
	lsls r0, 16
	lsrs r2, r0, 16
	adds r1, 0xE
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	movs r5, 0
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r5, r0
	bcs _080FB9DA
	lsls r0, r2, 16
	asrs r7, r0, 16
	lsls r0, r3, 16
	asrs r6, r0, 16
_080FB976:
	ldr r0, =gUnknown_0203A044
	ldr r0, [r0]
	lsls r1, r5, 3
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x7
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r1, 0x2]
	adds r0, 0x7
	lsls r0, 16
	asrs r1, r0, 16
	cmp r7, r1
	bgt _080FB9CC
	mov r3, r8
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	blt _080FB9CC
	lsls r0, r2, 16
	asrs r1, r0, 16
	cmp r6, r1
	bgt _080FB9CC
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r1
	blt _080FB9CC
	ldr r0, =gUnknown_0203A038
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, 0x40
	bne _080FB9CC
	ldr r3, [sp]
	lsls r1, r3, 16
	mov r0, r10
	lsls r2, r0, 16
	adds r0, r5, 0
	asrs r1, 16
	asrs r2, 16
	bl sub_80FB9FC
	strb r0, [r4]
_080FB9CC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r5, r0
	bcc _080FB976
_080FB9DA:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB928

	thumb_func_start sub_80FB9FC
sub_80FB9FC: @ 80FB9FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	ldr r0, =gUnknown_0203A044
	lsls r1, r6, 3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _080FBA24
	cmp r0, 0x4
	bne _080FBA34
_080FBA24:
	mov r1, sp
	ldr r0, =gUnknown_08591FE0
	b _080FBA38
	.pool
_080FBA34:
	mov r1, sp
	ldr r0, =gUnknown_08591FC8
_080FBA38:
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r2, sp
	ldrb r0, [r4, 0x4]
	movs r3, 0x98
	lsls r3, 5
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r2]
	mov r0, sp
	movs r1, 0
	movs r2, 0
	movs r3, 0x94
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _080FBAD4
	ldrh r0, [r4]
	adds r0, 0x7
	ldrh r1, [r4, 0x2]
	adds r1, 0x7
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	ldr r2, =gSprites
	adds r4, r2
	strh r6, [r4, 0x2E]
	movs r2, 0x3E
	adds r2, r4
	mov r12, r2
	ldrb r2, [r2]
	movs r3, 0x2
	orrs r2, r3
	mov r3, r12
	strb r2, [r3]
	lsls r0, 16
	asrs r0, 16
	lsls r2, r7, 16
	asrs r2, 16
	adds r0, r2
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	mov r3, r8
	lsls r2, r3, 16
	asrs r2, 16
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	bl sub_8092FF0
	adds r0, r4, 0
	bl sub_80FBB64
	adds r0, r6, 0
	bl sub_80FB854
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	adds r0, r5, 0
	b _080FBAD6
	.pool
_080FBAD4:
	movs r0, 0x40
_080FBAD6:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80FB9FC

	thumb_func_start sub_80FBAE4
sub_80FBAE4: @ 80FBAE4
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x30]
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r6, 0x32]
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	adds r0, r6, 0
	bl sub_80FBB64
	cmp r5, 0x1
	bne _080FBB2A
	adds r0, r4, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_811A138
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _080FBB1A
	adds r0, r4, 0
	adds r0, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
_080FBB1A:
	movs r0, 0x30
	bl audio_play
	adds r0, r6, 0
	adds r1, r4, 0
	bl StartSpriteAffineAnim
	b _080FBB58
_080FBB2A:
	cmp r5, 0x2
	bne _080FBB58
	adds r0, r7, 0
	adds r0, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_811A138
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _080FBB4A
	adds r0, r4, 0
	adds r0, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
_080FBB4A:
	movs r0, 0x30
	bl audio_play
	adds r0, r6, 0
	adds r1, r4, 0
	bl StartSpriteAffineAnim
_080FBB58:
	movs r0, 0
	strh r0, [r6, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80FBAE4

	thumb_func_start sub_80FBB64
sub_80FBB64: @ 80FBB64
	push {r4-r6,lr}
	mov r12, r0
	mov r4, r12
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r5, 0x5
	negs r5, r5
	ands r5, r0
	strb r5, [r4]
	mov r0, r12
	ldrh r1, [r0, 0x24]
	ldrh r2, [r0, 0x20]
	adds r1, r2
	adds r0, 0x28
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r0, =gSpriteCoordOffsetX
	adds r2, r1
	ldrh r0, [r0]
	adds r2, r0
	lsls r2, 16
	mov r3, r12
	ldrh r1, [r3, 0x26]
	ldrh r0, [r3, 0x22]
	adds r1, r0
	mov r0, r12
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldr r3, =gSpriteCoordOffsetY
	adds r0, r1
	ldrh r3, [r3]
	adds r0, r3
	lsls r0, 16
	movs r3, 0x80
	lsls r3, 15
	adds r1, r2, r3
	lsrs r1, 16
	lsrs r6, r0, 16
	adds r0, r3
	lsrs r3, r0, 16
	asrs r2, 16
	cmp r2, 0xFF
	bgt _080FBBCA
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080FBBD2
_080FBBCA:
	movs r1, 0x4
	adds r0, r5, 0
	orrs r0, r1
	strb r0, [r4]
_080FBBD2:
	lsls r0, r6, 16
	asrs r0, 16
	cmp r0, 0xAF
	bgt _080FBBE6
	lsls r0, r3, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080FBBF2
_080FBBE6:
	mov r0, r12
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080FBBF2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FBB64

	thumb_func_start LoadRotatingGatePics
@ void LoadRotatingGatePics()
LoadRotatingGatePics: @ 80FBC00
	push {lr}
	ldr r0, =gUnknown_08591D58
	bl LoadSpriteSheets
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadRotatingGatePics

	thumb_func_start sub_80FBC10
sub_80FBC10: @ 80FBC10
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r1, [r2]
	subs r0, r1, 0x2
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	adds r1, 0x11
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldrh r1, [r2, 0x2]
	subs r0, r1, 0x2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r1, 0xE
	lsls r1, 16
	lsrs r7, r1, 16
	movs r6, 0
	b _080FBCB6
	.pool
_080FBC48:
	ldr r0, =gUnknown_0203A044
	ldr r0, [r0]
	lsls r1, r6, 3
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x7
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r1, 0x2]
	adds r0, 0x7
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_0203A038
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, 0x40
	beq _080FBCB4
	lsls r0, r2, 16
	mov r2, r10
	lsls r1, r2, 16
	asrs r2, r0, 16
	cmp r0, r1
	blt _080FBC94
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	cmp r2, r0
	bgt _080FBC94
	lsls r0, r3, 16
	mov r2, r8
	lsls r1, r2, 16
	asrs r2, r0, 16
	cmp r0, r1
	blt _080FBC94
	lsls r0, r7, 16
	asrs r0, 16
	cmp r2, r0
	ble _080FBCB4
_080FBC94:
	ldr r0, =gUnknown_0203A038
	adds r5, r6, r0
	ldrb r0, [r5]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	movs r0, 0x40
	strb r0, [r5]
_080FBCB4:
	adds r6, 0x1
_080FBCB6:
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r6, r0
	blt _080FBC48
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FBC10

	thumb_func_start sub_80FBCDC
sub_80FBCDC: @ 80FBCDC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r1, 0x1
	bne _080FBCFC
	ldr r0, =gUnknown_08592058
	mov r10, r0
	b _080FBD08
	.pool
_080FBCFC:
	cmp r1, 0x2
	beq _080FBD04
_080FBD00:
	movs r0, 0
	b _080FBD98
_080FBD04:
	ldr r1, =gUnknown_08592038
	mov r10, r1
_080FBD08:
	adds r0, r4, 0
	bl sub_80FB854
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	ldr r0, =gUnknown_0203A044
	ldr r1, [r0]
	lsls r0, r4, 3
	adds r0, r1
	ldrb r2, [r0, 0x4]
	ldrh r1, [r0]
	adds r1, 0x7
	ldrh r0, [r0, 0x2]
	adds r0, 0x7
	movs r3, 0
	lsls r2, 3
	str r2, [sp, 0x4]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
_080FBD38:
	movs r6, 0
	ldr r2, [sp]
	adds r7, r2, r3
	lsls r0, r3, 1
	adds r5, r7, 0
	ldr r1, [sp, 0x4]
	adds r0, r1
	ldr r2, =gUnknown_08592078
	adds r4, r0, r2
_080FBD4A:
	adds r0, r5, 0
	cmp r5, 0
	bge _080FBD52
	adds r0, r7, 0x3
_080FBD52:
	asrs r0, 2
	lsls r0, 2
	subs r0, r5, r0
	lsls r0, 1
	adds r0, r6
	lsls r0, 24
	lsrs r1, r0, 24
	ldrb r0, [r4]
	cmp r0, 0
	beq _080FBD88
	lsls r1, 2
	add r1, r10
	movs r0, 0
	ldrsb r0, [r1, r0]
	add r0, r9
	ldrb r1, [r1, 0x1]
	lsls r1, 24
	asrs r1, 24
	add r1, r8
	str r3, [sp, 0x8]
	bl MapGridIsImpassableAt
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [sp, 0x8]
	cmp r0, 0x1
	beq _080FBD00
_080FBD88:
	adds r4, 0x1
	adds r6, 0x1
	cmp r6, 0x1
	ble _080FBD4A
	adds r3, 0x1
	cmp r3, 0x3
	ble _080FBD38
	movs r0, 0x1
_080FBD98:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FBCDC

	thumb_func_start sub_80FBDB4
sub_80FBDB4: @ 80FBDB4
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r4, 24
	lsrs r5, r4, 24
	lsrs r4, 25
	movs r0, 0x1
	ands r5, r0
	adds r0, r6, 0
	bl sub_80FB854
	subs r4, r0
	adds r1, r4, 0x4
	adds r0, r1, 0
	cmp r1, 0
	bge _080FBDDA
	adds r0, r4, 0x7
_080FBDDA:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	ldr r1, =gUnknown_0203A044
	ldr r2, [r1]
	lsls r1, r6, 3
	adds r1, r2
	ldrb r1, [r1, 0x4]
	ldr r2, =gUnknown_08592078
	lsls r0, 24
	asrs r0, 23
	adds r0, r5
	lsls r1, 3
	adds r0, r1
	adds r0, r2
	ldrb r0, [r0]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FBDB4

	thumb_func_start sub_80FBE08
sub_80FBE08: @ 80FBE08
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gUnknown_0203A038
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, 0x40
	beq _080FBE2C
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	strh r1, [r4, 0x30]
	adds r0, r3, 0
	bl sub_80FB854
	strh r0, [r4, 0x32]
_080FBE2C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FBE08

	thumb_func_start sub_80FBE3C
sub_80FBE3C: @ 80FBE3C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	cmp r0, 0x2
	bne _080FBE58
	ldr r3, =gUnknown_08591FF8
	b _080FBE7A
	.pool
_080FBE58:
	cmp r0, 0x1
	bne _080FBE64
	ldr r3, =gUnknown_08592008
	b _080FBE7A
	.pool
_080FBE64:
	cmp r0, 0x3
	bne _080FBE70
	ldr r3, =gUnknown_08592018
	b _080FBE7A
	.pool
_080FBE70:
	cmp r3, 0x4
	beq _080FBE78
	movs r0, 0xFF
	b _080FBE88
_080FBE78:
	ldr r3, =gUnknown_08592028
_080FBE7A:
	lsls r0, r2, 16
	lsls r1, 16
	asrs r1, 16
	asrs r0, 14
	adds r0, r1
	adds r0, r3, r0
	ldrb r0, [r0]
_080FBE88:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FBE3C

	thumb_func_start sub_80FBE90
sub_80FBE90: @ 80FBE90
	push {lr}
	bl GetCurrentMapRotatingGatePuzzleType
	cmp r0, 0
	beq _080FBEA2
	bl sub_80FB8CC
	bl sub_80FB818
_080FBEA2:
	pop {r0}
	bx r0
	thumb_func_end sub_80FBE90

	thumb_func_start RotatingGatePuzzleCameraUpdate
@ void RotatingGatePuzzleCameraUpdate(s32 deltaX, s32 deltaY)
RotatingGatePuzzleCameraUpdate: @ 80FBEA8
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	bl GetCurrentMapRotatingGatePuzzleType
	cmp r0, 0
	beq _080FBECA
	lsls r0, r4, 16
	asrs r0, 16
	lsls r1, r5, 16
	asrs r1, 16
	bl sub_80FB928
	bl sub_80FBC10
_080FBECA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end RotatingGatePuzzleCameraUpdate

	thumb_func_start sub_80FBED0
sub_80FBED0: @ 80FBED0
	push {lr}
	bl GetCurrentMapRotatingGatePuzzleType
	cmp r0, 0
	beq _080FBEEA
	bl LoadRotatingGatePics
	bl sub_80FB8CC
	movs r0, 0
	movs r1, 0
	bl sub_80FB928
_080FBEEA:
	pop {r0}
	bx r0
	thumb_func_end sub_80FBED0

	thumb_func_start CheckForRotatingGatePuzzleCollision
CheckForRotatingGatePuzzleCollision: @ 80FBEF0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	bl GetCurrentMapRotatingGatePuzzleType
	cmp r0, 0
	bne _080FBF24
	b _080FBFC2
_080FBF12:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80FBE08
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80FB890
	b _080FBFC2
_080FBF24:
	movs r6, 0
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r6, r0
	bge _080FBFC2
	lsls r0, r4, 16
	asrs r7, r0, 16
_080FBF32:
	ldr r0, =gUnknown_0203A044
	ldr r1, [r0]
	lsls r0, r6, 3
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0x7
	ldrh r0, [r0, 0x2]
	adds r0, 0x7
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	subs r0, r4, 0x2
	cmp r0, r7
	bgt _080FBFB8
	adds r0, r4, 0x1
	cmp r7, r0
	bgt _080FBFB8
	lsls r0, r2, 16
	asrs r3, r0, 16
	subs r1, r3, 0x2
	mov r2, r8
	lsls r0, r2, 16
	asrs r2, r0, 16
	cmp r1, r2
	bgt _080FBFB8
	adds r0, r3, 0x1
	cmp r2, r0
	bgt _080FBFB8
	subs r1, r7, r4
	adds r1, 0x2
	subs r2, r3
	adds r2, 0x2
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	mov r0, r9
	bl sub_80FBE3C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080FBFB8
	lsrs r5, r0, 4
	movs r1, 0xF
	ands r1, r0
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80FBDB4
	cmp r0, 0
	beq _080FBFB8
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80FBCDC
	cmp r0, 0
	bne _080FBF12
	movs r0, 0x1
	b _080FBFC4
	.pool
_080FBFB8:
	adds r6, 0x1
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r6, r0
	blt _080FBF32
_080FBFC2:
	movs r0, 0
_080FBFC4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckForRotatingGatePuzzleCollision

	thumb_func_start sub_80FBFD4
sub_80FBFD4: @ 80FBFD4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	bl GetCurrentMapRotatingGatePuzzleType
	cmp r0, 0
	bne _080FBFFA
	b _080FC08A
_080FBFF6:
	movs r0, 0x1
	b _080FC08C
_080FBFFA:
	movs r6, 0
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r6, r0
	bge _080FC08A
	lsls r0, r4, 16
	asrs r7, r0, 16
_080FC008:
	ldr r0, =gUnknown_0203A044
	ldr r1, [r0]
	lsls r0, r6, 3
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0x7
	ldrh r0, [r0, 0x2]
	adds r0, 0x7
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	subs r0, r4, 0x2
	cmp r0, r7
	bgt _080FC080
	adds r0, r4, 0x1
	cmp r7, r0
	bgt _080FC080
	lsls r0, r2, 16
	asrs r3, r0, 16
	subs r1, r3, 0x2
	mov r2, r8
	lsls r0, r2, 16
	asrs r2, r0, 16
	cmp r1, r2
	bgt _080FC080
	adds r0, r3, 0x1
	cmp r2, r0
	bgt _080FC080
	subs r1, r7, r4
	adds r1, 0x2
	subs r2, r3
	adds r2, 0x2
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	mov r0, r9
	bl sub_80FBE3C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080FC080
	lsrs r5, r0, 4
	movs r1, 0xF
	ands r1, r0
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80FBDB4
	cmp r0, 0
	beq _080FC080
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80FBCDC
	cmp r0, 0
	beq _080FBFF6
_080FC080:
	adds r6, 0x1
	ldr r0, =gUnknown_0203A048
	ldrb r0, [r0]
	cmp r6, r0
	blt _080FC008
_080FC08A:
	movs r0, 0
_080FC08C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FBFD4

	.align 2, 0 @ Don't pad with nop.
