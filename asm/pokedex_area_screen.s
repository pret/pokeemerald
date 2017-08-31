	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_813CA54
sub_813CA54: @ 813CA54
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_813CA54

	thumb_func_start sub_813CA68
sub_813CA68: @ 813CA68
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _0813CB20
	lsls r0, 2
	ldr r1, =_0813CA90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813CA90:
	.4byte _0813CAA4
	.4byte _0813CAB4
	.4byte _0813CABA
	.4byte _0813CAEC
	.4byte _0813CB10
_0813CAA4:
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	bl sub_813CB40
	b _0813CB24
	.pool
_0813CAB4:
	bl sub_813CF0C
	b _0813CB24
_0813CABA:
	ldr r1, =gUnknown_085B3DB4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_0203AB7C
	ldr r1, [r0]
	movs r0, 0x8B
	lsls r0, 1
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	b _0813CB24
	.pool
_0813CAEC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _0813CB34
	ldr r0, =gUnknown_085B3D94
	ldr r1, =gPlttBufferUnfaded + 0x140
	ldr r2, =0x04000008
	bl CpuSet
	b _0813CB24
	.pool
_0813CB10:
	ldr r1, =0xfffff800
	movs r0, 0x2
	movs r2, 0
	bl ChangeBgY
	b _0813CB24
	.pool
_0813CB20:
	movs r0, 0
	b _0813CB36
_0813CB24:
	ldr r0, =gUnknown_0203AB7C
	ldr r1, [r0]
	movs r0, 0x8A
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0813CB34:
	movs r0, 0x1
_0813CB36:
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813CA68

	thumb_func_start sub_813CB40
sub_813CB40: @ 813CB40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r5, =gUnknown_0203AB7C
	ldr r0, [r5]
	ldr r1, =0x000006e2
	adds r0, r1
	movs r4, 0
	strh r4, [r0]
	ldr r0, =0x0000403e
	bl VarGet
	ldr r1, [r5]
	ldr r2, =0x000006e4
	adds r1, r2
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	bls _0813CB70
	strh r4, [r1]
_0813CB70:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x000031dc
	adds r0, r3
	ldrh r1, [r0, 0x8]
	cmp r7, r1
	bne _0813CB80
	b _0813CCB8
_0813CB80:
	ldr r1, [r5]
	movs r2, 0x88
	lsls r2, 1
	adds r0, r1, r2
	strh r4, [r0]
	movs r3, 0x89
	lsls r3, 1
	adds r0, r1, r3
	strh r4, [r0]
	movs r6, 0
	ldr r1, =gUnknown_085B3EE8
_0813CB96:
	lsls r0, r6, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	bne _0813CBA2
	b _0813CCF8
_0813CBA2:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _0813CB96
	movs r6, 0
	ldr r4, =gUnknown_085B3EF0
	ldrh r0, [r4]
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _0813CC44
	mov r8, r4
	adds r5, r4, 0x4
	mov r9, r1
_0813CBC0:
	lsls r0, r6, 1
	adds r1, r0, r6
	lsls r2, r1, 1
	mov r3, r8
	adds r1, r2, r3
	adds r3, r0, 0
	ldrh r1, [r1]
	cmp r7, r1
	bne _0813CC2E
	adds r0, r4, 0x2
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, 0x18
	beq _0813CC1A
	cmp r0, 0x18
	bgt _0813CC08
	cmp r0, 0
	beq _0813CC0E
	b _0813CC2E
	.pool
_0813CC08:
	cmp r0, 0x1A
	beq _0813CC1A
	b _0813CC2E
_0813CC0E:
	adds r0, r2, r5
	ldrh r1, [r0]
	movs r0, 0
	bl sub_813CD04
	b _0813CC2E
_0813CC1A:
	adds r1, r3, r6
	lsls r1, 1
	mov r0, r8
	adds r0, 0x2
	adds r0, r1, r0
	ldrh r0, [r0]
	adds r1, r5
	ldrh r1, [r1]
	bl sub_813CD64
_0813CC2E:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r4, =gUnknown_085B3EF0
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r9
	bne _0813CBC0
_0813CC44:
	movs r6, 0
	ldr r1, =gWildMonHeaders
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0813CCF8
_0813CC4E:
	lsls r4, r6, 2
	adds r0, r4, r6
	lsls r0, 2
	adds r5, r0, r1
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_813CE48
	lsls r0, 24
	cmp r0, 0
	beq _0813CC9C
	ldrb r0, [r5]
	cmp r0, 0x18
	beq _0813CC8C
	cmp r0, 0x18
	bgt _0813CC7C
	cmp r0, 0
	beq _0813CC82
	b _0813CC9C
	.pool
_0813CC7C:
	cmp r0, 0x1A
	beq _0813CC8C
	b _0813CC9C
_0813CC82:
	ldrb r1, [r5, 0x1]
	movs r0, 0
	bl sub_813CD04
	b _0813CC9C
_0813CC8C:
	ldr r0, =gWildMonHeaders
	adds r1, r4, r6
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl sub_813CD64
_0813CC9C:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, =gWildMonHeaders
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0813CC4E
	b _0813CCF8
	.pool
_0813CCB8:
	ldr r2, [r5]
	movs r3, 0x89
	lsls r3, 1
	adds r1, r2, r3
	strh r4, [r1]
	ldrb r1, [r0, 0x13]
	cmp r1, 0
	beq _0813CCF0
	adds r0, r2, 0
	adds r0, 0x10
	adds r1, r2, 0
	adds r1, 0x11
	bl sub_8161F64
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	ldrb r1, [r1, 0x11]
	bl get_mapheader_by_bank_and_number
	ldr r1, [r5]
	ldrb r0, [r0, 0x14]
	strh r0, [r1, 0x12]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1]
	b _0813CCF8
_0813CCF0:
	movs r3, 0x88
	lsls r3, 1
	adds r0, r2, r3
	strh r1, [r0]
_0813CCF8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_813CB40

	thumb_func_start sub_813CD04
sub_813CD04: @ 813CD04
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r3, r1, 16
	ldr r4, =gUnknown_0203AB7C
	ldr r2, [r4]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, 0x3F
	bhi _0813CD58
	lsls r0, 2
	adds r0, r2, r0
	strb r5, [r0, 0x10]
	ldr r1, [r4]
	movs r2, 0x88
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, 2
	adds r1, r0
	strb r3, [r1, 0x11]
	adds r0, r5, 0
	adds r1, r3, 0
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x14]
	bl sub_8123F9C
	ldr r2, [r4]
	movs r1, 0x88
	lsls r1, 1
	adds r3, r2, r1
	ldrh r1, [r3]
	lsls r1, 2
	adds r2, r1
	strh r0, [r2, 0x12]
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
_0813CD58:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813CD04

	thumb_func_start sub_813CD64
sub_813CD64: @ 813CD64
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	movs r3, 0x89
	lsls r3, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, 0x1F
	bhi _0813CE22
	lsls r0, r2, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl sub_813CE34
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xD4
	bhi _0813CE22
	movs r3, 0
	ldr r0, =gUnknown_085B3EEA
_0813CD96:
	ldrh r4, [r0]
	cmp r5, r4
	beq _0813CE22
	adds r0, 0x2
	adds r3, 0x1
	cmp r3, 0x2
	bls _0813CD96
	ldr r1, =gUnknown_085B3EFC
	ldrh r0, [r1]
	cmp r0, 0xD5
	beq _0813CDD2
	adds r4, r1, 0
	adds r7, r4, 0
	movs r6, 0
_0813CDB2:
	ldrh r0, [r4]
	cmp r5, r0
	bne _0813CDC8
	adds r0, r7, 0x2
	adds r0, r6, r0
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813CE22
_0813CDC8:
	adds r4, 0x4
	adds r6, 0x4
	ldrh r0, [r4]
	cmp r0, 0xD5
	bne _0813CDB2
_0813CDD2:
	movs r3, 0
	ldr r0, =gUnknown_0203AB7C
	ldr r2, [r0]
	movs r4, 0x89
	lsls r4, 1
	adds r1, r2, r4
	ldrh r4, [r1]
	adds r1, r0, 0
	cmp r3, r4
	bge _0813CE02
	movs r6, 0xC4
	lsls r6, 3
	adds r0, r2, r6
	ldrh r0, [r0]
	cmp r0, r5
	beq _0813CE02
	adds r2, r6
_0813CDF4:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r4
	bge _0813CE02
	ldrh r0, [r2]
	cmp r0, r5
	bne _0813CDF4
_0813CE02:
	ldr r1, [r1]
	movs r0, 0x89
	lsls r0, 1
	adds r2, r1, r0
	ldrh r4, [r2]
	cmp r3, r4
	bne _0813CE22
	lsls r0, r3, 1
	movs r6, 0xC4
	lsls r6, 3
	adds r1, r6
	adds r1, r0
	strh r5, [r1]
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
_0813CE22:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813CD64

	thumb_func_start sub_813CE34
sub_813CE34: @ 813CE34
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	thumb_func_end sub_813CE34

	thumb_func_start sub_813CE48
sub_813CE48: @ 813CE48
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl sub_813CE34
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xD2
	bne _0813CE7C
	ldr r0, =gUnknown_0203AB7C
	ldr r2, [r0]
	ldr r0, =0x000006e2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	ldr r0, =0x000006e4
	adds r2, r0
	ldrh r0, [r2]
	adds r0, 0x1
	cmp r1, r0
	bne _0813CEBC
_0813CE7C:
	ldr r0, [r4, 0x4]
	adds r1, r5, 0
	movs r2, 0xC
	bl sub_813CED4
	lsls r0, 24
	cmp r0, 0
	bne _0813CECC
	ldr r0, [r4, 0x8]
	adds r1, r5, 0
	movs r2, 0x5
	bl sub_813CED4
	lsls r0, 24
	cmp r0, 0
	bne _0813CECC
	ldr r0, [r4, 0x10]
	adds r1, r5, 0
	movs r2, 0xC
	bl sub_813CED4
	lsls r0, 24
	cmp r0, 0
	bne _0813CECC
	ldr r0, [r4, 0xC]
	adds r1, r5, 0
	movs r2, 0x5
	bl sub_813CED4
	lsls r0, 24
	cmp r0, 0
	bne _0813CECC
_0813CEBC:
	movs r0, 0
	b _0813CECE
	.pool
_0813CECC:
	movs r0, 0x1
_0813CECE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_813CE48

	thumb_func_start sub_813CED4
sub_813CED4: @ 813CED4
	push {r4,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	cmp r0, 0
	beq _0813CF02
	movs r3, 0
	cmp r3, r2
	bcs _0813CF02
	ldr r1, [r0, 0x4]
_0813CEEA:
	lsls r0, r3, 2
	adds r0, r1
	ldrh r0, [r0, 0x2]
	cmp r0, r4
	bne _0813CEF8
	movs r0, 0x1
	b _0813CF04
_0813CEF8:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r2
	bcc _0813CEEA
_0813CF02:
	movs r0, 0
_0813CF04:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813CED4

	thumb_func_start sub_813CF0C
sub_813CF0C: @ 813CF0C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r4, 0
	ldr r2, =gUnknown_0203AB7C
	adds r7, r2, 0
	movs r6, 0x8B
	lsls r6, 1
	movs r5, 0
	ldr r3, =0x0000027f
_0813CF26:
	ldr r0, [r7]
	lsls r1, r4, 1
	adds r0, r6
	adds r0, r1
	strh r5, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r3
	bls _0813CF26
	movs r4, 0
	ldr r0, [r2]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bcs _0813CFB2
	adds r3, r2, 0
_0813CF4C:
	movs r5, 0
	movs r6, 0
	adds r2, r4, 0x1
	mov r8, r2
	lsls r4, 2
	mov r9, r4
_0813CF58:
	movs r4, 0
_0813CF5A:
	adds r0, r4, 0
	adds r1, r6, 0
	str r3, [sp]
	bl sub_8123E9C
	ldr r3, [sp]
	ldr r2, [r3]
	mov r7, r9
	adds r1, r2, r7
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1, 0x12]
	cmp r0, r1
	bne _0813CF84
	lsls r0, r5, 1
	movs r7, 0x8B
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, =0x0000ffff
	strh r0, [r1]
_0813CF84:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1F
	bls _0813CF5A
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x13
	bls _0813CF58
	mov r1, r8
	lsls r0, r1, 16
	lsrs r4, r0, 16
	ldr r0, [r3]
	movs r2, 0x88
	lsls r2, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r4, r0
	bcc _0813CF4C
_0813CFB2:
	movs r5, 0
	movs r6, 0
	ldr r7, =gUnknown_0203AB7C
	mov r12, r7
	movs r7, 0x8B
	lsls r7, 1
	ldr r3, =0x0000ffff
_0813CFC0:
	movs r4, 0
	adds r1, r6, 0x1
	mov r9, r1
_0813CFC6:
	mov r2, r12
	ldr r0, [r2]
	lsls r1, r5, 1
	adds r2, r0, r7
	adds r1, r2, r1
	ldrh r0, [r1]
	adds r1, r5, 0x1
	mov r8, r1
	cmp r0, r3
	bne _0813D0D2
	cmp r4, 0
	beq _0813CFF0
	subs r0, r5, 0x1
	lsls r0, 1
	adds r1, r2, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813CFF0
	movs r0, 0x2
	orrs r0, r2
	strh r0, [r1]
_0813CFF0:
	adds r2, r5, 0x1
	mov r8, r2
	cmp r4, 0x1F
	beq _0813D00E
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r2, 1
	adds r0, r7
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, r3
	beq _0813D00E
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2]
_0813D00E:
	cmp r6, 0
	beq _0813D02C
	mov r2, r12
	ldr r1, [r2]
	adds r0, r5, 0
	subs r0, 0x20
	lsls r0, 1
	adds r1, r7
	adds r1, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813D02C
	movs r0, 0x8
	orrs r0, r2
	strh r0, [r1]
_0813D02C:
	cmp r6, 0x13
	beq _0813D04A
	mov r0, r12
	ldr r1, [r0]
	adds r0, r5, 0
	adds r0, 0x20
	lsls r0, 1
	adds r1, r7
	adds r1, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813D04A
	movs r0, 0x4
	orrs r0, r2
	strh r0, [r1]
_0813D04A:
	cmp r4, 0
	beq _0813D06C
	cmp r6, 0
	beq _0813D06C
	mov r2, r12
	ldr r1, [r2]
	adds r0, r5, 0
	subs r0, 0x21
	lsls r0, 1
	adds r1, r7
	adds r1, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813D06C
	movs r0, 0x10
	orrs r0, r2
	strh r0, [r1]
_0813D06C:
	cmp r4, 0x1F
	beq _0813D08E
	cmp r6, 0
	beq _0813D08E
	mov r0, r12
	ldr r1, [r0]
	adds r0, r5, 0
	subs r0, 0x1F
	lsls r0, 1
	adds r1, r7
	adds r1, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813D08E
	movs r0, 0x40
	orrs r0, r2
	strh r0, [r1]
_0813D08E:
	cmp r4, 0
	beq _0813D0B0
	cmp r6, 0x13
	beq _0813D0B0
	mov r2, r12
	ldr r1, [r2]
	adds r0, r5, 0
	adds r0, 0x1F
	lsls r0, 1
	adds r1, r7
	adds r1, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813D0B0
	movs r0, 0x20
	orrs r0, r2
	strh r0, [r1]
_0813D0B0:
	cmp r4, 0x1F
	beq _0813D0D2
	cmp r6, 0x13
	beq _0813D0D2
	mov r0, r12
	ldr r1, [r0]
	adds r0, r5, 0
	adds r0, 0x21
	lsls r0, 1
	adds r1, r7
	adds r1, r0
	ldrh r2, [r1]
	cmp r2, r3
	beq _0813D0D2
	movs r0, 0x80
	orrs r0, r2
	strh r0, [r1]
_0813D0D2:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r5, r0, 16
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1F
	bhi _0813D0E4
	b _0813CFC6
_0813D0E4:
	mov r2, r9
	lsls r0, r2, 16
	lsrs r6, r0, 16
	cmp r6, 0x13
	bhi _0813D0F0
	b _0813CFC0
_0813D0F0:
	movs r4, 0
	ldr r6, =gUnknown_0203AB7C
	movs r5, 0x8B
	lsls r5, 1
	ldr r7, =0x0000ffff
	mov r12, r7
	movs r0, 0xA0
	lsls r0, 8
	mov r9, r0
	ldr r7, =0x0000a010
	ldr r1, =0x0000ffcf
	mov r8, r1
_0813D108:
	ldr r0, [r6]
	lsls r3, r4, 1
	adds r0, r5
	adds r2, r0, r3
	ldrh r1, [r2]
	adds r0, r1, 0
	cmp r0, r12
	bne _0813D130
	strh r7, [r2]
	b _0813D198
	.pool
_0813D130:
	cmp r0, 0
	beq _0813D198
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0813D142
	mov r0, r8
	ands r0, r1
	strh r0, [r2]
_0813D142:
	ldr r0, [r6]
	adds r0, r5
	adds r2, r0, r3
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0813D158
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r2]
_0813D158:
	ldr r0, [r6]
	adds r0, r5
	adds r2, r0, r3
	ldrh r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0813D16E
	ldr r0, =0x0000ffaf
	ands r0, r1
	strh r0, [r2]
_0813D16E:
	ldr r0, [r6]
	adds r0, r5
	adds r2, r0, r3
	ldrh r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0813D184
	ldr r0, =0x0000ff5f
	ands r0, r1
	strh r0, [r2]
_0813D184:
	ldr r1, [r6]
	adds r1, r5
	adds r1, r3
	ldr r2, =gUnknown_085B3F18
	ldrh r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	mov r2, r9
	orrs r0, r2
	strh r0, [r1]
_0813D198:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000027f
	cmp r4, r0
	bls _0813D108
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813CF0C

	thumb_func_start sub_813D1C8
sub_813D1C8: @ 813D1C8
	push {lr}
	ldr r1, =gUnknown_0203AB7C
	ldr r2, [r1]
	movs r3, 0x89
	lsls r3, 1
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r3, r1, 0
	cmp r0, 0
	beq _0813D1FC
	movs r1, 0x88
	lsls r1, 1
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813D1FC
	ldr r0, =0x0000061e
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
	b _0813D206
	.pool
_0813D1FC:
	ldr r0, [r3]
	ldr r1, =0x0000061e
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_0813D206:
	ldr r1, [r3]
	ldr r2, =0x00000616
	adds r0, r1, r2
	movs r2, 0
	strh r2, [r0]
	movs r3, 0xC3
	lsls r3, 3
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, 0x2
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =0x0000061c
	adds r2, r1, r0
	movs r0, 0x40
	strh r0, [r2]
	ldr r2, =0x0000061f
	adds r1, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	bl sub_813D25C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D1C8

	thumb_func_start sub_813D25C
sub_813D25C: @ 813D25C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_0203AB7C
	ldr r2, [r0]
	ldr r3, =0x0000061e
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r7, r0, 0
	cmp r1, 0
	bne _0813D32A
	ldr r0, =0x00000616
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0813D324
	movs r1, 0xC3
	lsls r1, 3
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0813D2A4
	subs r3, 0x4
	adds r0, r2, r3
	b _0813D2A8
	.pool
_0813D2A4:
	ldr r1, =0x0000061c
	adds r0, r2, r1
_0813D2A8:
	ldrh r1, [r0]
	adds r1, 0x4
	movs r2, 0x7F
	ands r1, r2
	strh r1, [r0]
	ldr r3, =gSineTable
	ldr r1, [r7]
	ldr r2, =0x0000061a
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r3
	ldrh r2, [r0]
	lsls r2, 16
	asrs r2, 20
	lsls r2, 16
	ldr r0, =0x0000061c
	adds r1, r0
	ldrh r0, [r1]
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 20
	lsls r1, 24
	orrs r1, r2
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, [r7]
	ldr r2, =0x00000616
	adds r0, r1, r2
	movs r3, 0
	strh r3, [r0]
	movs r0, 0xC3
	lsls r0, 3
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, 0x40
	bne _0813D3C6
	strh r3, [r2]
	movs r2, 0x89
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	beq _0813D3C6
	ldr r3, =0x0000061e
	adds r1, r3
	movs r0, 0x1
	b _0813D3C4
	.pool
_0813D324:
	subs r0, 0x1
	strh r0, [r1]
	b _0813D3C6
_0813D32A:
	ldr r0, =0x00000616
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC
	bls _0813D3C6
	movs r0, 0
	strh r0, [r1]
	ldr r3, =0x0000061f
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r4, 0
	ldr r0, [r7]
	movs r6, 0x89
	lsls r6, 1
	adds r0, r6
	ldrh r0, [r0]
	cmp r4, r0
	bcs _0813D3A0
	adds r5, r7, 0
	movs r0, 0x1
	mov r12, r0
	movs r1, 0x5
	negs r1, r1
	mov r8, r1
_0813D366:
	ldr r1, [r5]
	lsls r2, r4, 2
	movs r3, 0xCC
	lsls r3, 3
	adds r0, r1, r3
	adds r0, r2
	ldr r3, [r0]
	ldr r0, =0x0000061f
	adds r1, r0
	ldrb r0, [r1]
	movs r1, 0x1
	adds r3, 0x3E
	ands r1, r0
	mov r2, r12
	ands r1, r2
	lsls r1, 2
	ldrb r2, [r3]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	adds r0, r6
	ldrh r0, [r0]
	cmp r4, r0
	bcc _0813D366
_0813D3A0:
	ldr r0, [r7]
	ldr r3, =0x0000061f
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0x4
	bls _0813D3C6
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, [r7]
	movs r2, 0x88
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	beq _0813D3C6
	subs r3, 0x1
	adds r1, r3
	movs r0, 0
_0813D3C4:
	strb r0, [r1]
_0813D3C6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D25C

	thumb_func_start sub_813D3D8
sub_813D3D8: @ 813D3D8
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r5, =gUnknown_0203AB7C
	ldr r0, =0x000015bc
	bl AllocZeroed
	str r0, [r5]
	movs r1, 0
	movs r5, 0
	strh r4, [r0, 0xE]
	movs r2, 0xDD
	lsls r2, 3
	adds r0, r2
	str r6, [r0]
	strb r1, [r6]
	ldr r0, =sub_813D42C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D3D8

	thumb_func_start sub_813D42C
sub_813D42C: @ 813D42C
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0xB
	bls _0813D44A
	b _0813D584
_0813D44A:
	lsls r0, 2
	ldr r1, =_0813D45C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813D45C:
	.4byte _0813D48C
	.4byte _0813D4A8
	.4byte _0813D4D4
	.4byte _0813D4E6
	.4byte _0813D4EC
	.4byte _0813D4F8
	.4byte _0813D520
	.4byte _0813D526
	.4byte _0813D52C
	.4byte _0813D532
	.4byte _0813D544
	.4byte _0813D56C
_0813D48C:
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	movs r0, 0x3
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0
	bl HideBg
	b _0813D584
_0813D4A8:
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x3
	bl SetBgAttribute
	ldr r0, =gUnknown_085B4018
	bl sub_81C4D70
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	movs r1, 0xF7
	lsls r1, 4
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl StringFill
	b _0813D584
	.pool
_0813D4D4:
	bl sub_81C4E90
	cmp r0, 0x1
	beq _0813D594
	movs r0, 0x8
	negs r0, r0
	bl sub_81C4ED0
	b _0813D584
_0813D4E6:
	bl sub_813CA54
	b _0813D584
_0813D4EC:
	bl sub_813CA68
	lsls r0, 24
	cmp r0, 0
	bne _0813D594
	b _0813D584
_0813D4F8:
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	ldr r2, =0x000006ec
	adds r0, r2
	bl sub_8122D88
	movs r0, 0x1
	movs r1, 0x1
	bl sub_8124288
	movs r1, 0x8
	negs r1, r1
	movs r0, 0
	bl sub_8123824
	b _0813D584
	.pool
_0813D520:
	bl sub_813D6D0
	b _0813D584
_0813D526:
	bl sub_813D8A8
	b _0813D584
_0813D52C:
	bl sub_813D8E8
	b _0813D584
_0813D532:
	movs r0, 0x15
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0813D584
_0813D544:
	ldr r1, =0x00003f41
	movs r0, 0x50
	bl SetGpuReg
	bl sub_813D1C8
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	b _0813D584
	.pool
_0813D56C:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_813D5A0
	str r1, [r0]
	movs r1, 0
	strh r1, [r0, 0x8]
	b _0813D594
	.pool
_0813D584:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0813D594:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D42C

	thumb_func_start sub_813D5A0
sub_813D5A0: @ 813D5A0
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_813D25C
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r6, r0, r1
	movs r0, 0x8
	ldrsh r1, [r6, r0]
	cmp r1, 0x1
	beq _0813D5F8
	cmp r1, 0x1
	bgt _0813D5CC
	cmp r1, 0
	beq _0813D5E2
	b _0813D5D4
	.pool
_0813D5CC:
	cmp r1, 0x2
	beq _0813D640
	cmp r1, 0x3
	beq _0813D652
_0813D5D4:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
_0813D5E2:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0813D6A8
	b _0813D698
	.pool
_0813D5F8:
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r3, 0x2
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _0813D614
	strh r1, [r6, 0xA]
	movs r0, 0x3
	bl audio_play
	b _0813D698
	.pool
_0813D614:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	bne _0813D630
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0813D6A8
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _0813D6A8
_0813D630:
	strh r3, [r6, 0xA]
	movs r0, 0x6D
	bl audio_play
	b _0813D698
	.pool
_0813D640:
	movs r0, 0x15
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0813D698
_0813D652:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _0813D6A8
	bl sub_813D824
	ldr r4, =gUnknown_0203AB7C
	ldr r0, [r4]
	movs r1, 0xDD
	lsls r1, 3
	adds r0, r1
	ldr r1, [r0]
	ldrh r0, [r6, 0xA]
	strb r0, [r1]
	bl sub_813D6B4
	adds r0, r5, 0
	bl DestroyTask
	bl sub_81C4EB4
	ldr r0, [r4]
	bl Free
	str r7, [r4]
	b _0813D6A8
	.pool
_0813D698:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0813D6A8:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D5A0

	thumb_func_start sub_813D6B4
sub_813D6B4: @ 813D6B4
	push {lr}
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x3
	movs r1, 0x4
	movs r2, 0
	bl SetBgAttribute
	pop {r0}
	bx r0
	thumb_func_end sub_813D6B4

	thumb_func_start sub_813D6D0
sub_813D6D0: @ 813D6D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_085B401C
	bl LoadObjectPic
	ldr r0, =gUnknown_085B4024
	bl LoadTaggedObjectPalette
	ldr r0, =gUnknown_03001204
	movs r1, 0
	strh r1, [r0]
	ldr r2, =gUnknown_03001200
	strh r1, [r2]
	ldr r1, =gUnknown_0203AB7C
	ldr r0, [r1]
	movs r3, 0x89
	lsls r3, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _0813D7D8
	ldr r5, =gUnknown_03001202
	mov r10, r1
	adds r7, r2, 0
	ldr r0, =gUnknown_030011FC
	mov r9, r0
	ldr r6, =gRegionMapEntries
	ldr r1, =gUnknown_030011FE
	mov r8, r1
_0813D710:
	mov r2, r10
	ldr r1, [r2]
	movs r3, 0
	ldrsh r0, [r7, r3]
	lsls r0, 1
	movs r2, 0xC4
	lsls r2, 3
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
	movs r3, 0
	ldrsh r0, [r5, r3]
	lsls r0, 3
	adds r0, r6
	ldrb r1, [r0]
	adds r1, 0x1
	lsls r1, 3
	adds r1, 0x4
	mov r0, r9
	strh r1, [r0]
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r0, r6
	ldrb r2, [r0, 0x1]
	lsls r2, 3
	adds r2, 0x1C
	mov r3, r8
	strh r2, [r3]
	movs r3, 0
	ldrsh r0, [r5, r3]
	lsls r0, 3
	adds r0, r6
	ldrb r0, [r0, 0x2]
	subs r0, 0x1
	lsls r0, 2
	adds r1, r0
	mov r0, r9
	strh r1, [r0]
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r0, 3
	adds r0, r6
	ldrb r0, [r0, 0x3]
	subs r0, 0x1
	lsls r0, 2
	adds r2, r0
	mov r3, r8
	strh r2, [r3]
	mov r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r0, =gUnknown_085B4034
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0813D7BE
	ldr r0, =gSprites
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	mov r1, r10
	ldr r3, [r1]
	ldr r4, =gUnknown_03001204
	ldrh r1, [r4]
	adds r0, r1, 0x1
	strh r0, [r4]
	lsls r1, 16
	asrs r1, 14
	movs r0, 0xCC
	lsls r0, 3
	adds r3, r0
	adds r3, r1
	str r2, [r3]
_0813D7BE:
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	movs r2, 0
	ldrsh r1, [r7, r2]
	mov r3, r10
	ldr r0, [r3]
	movs r2, 0x89
	lsls r2, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _0813D710
_0813D7D8:
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	ldr r1, =gUnknown_03001204
	ldrh r1, [r1]
	movs r3, 0xDC
	lsls r3, 3
	adds r0, r3
	strh r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D6D0

	thumb_func_start sub_813D824
sub_813D824: @ 813D824
	push {r4,r5,lr}
	movs r0, 0x2
	bl FreeObjectTilesByTag
	movs r0, 0x2
	bl FreeObjectPaletteByTag
	movs r4, 0
	ldr r1, =gUnknown_0203AB7C
	ldr r0, [r1]
	movs r2, 0xDC
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	cmp r4, r0
	bcs _0813D86C
	adds r5, r1, 0
_0813D846:
	ldr r0, [r5]
	lsls r1, r4, 2
	movs r2, 0xCC
	lsls r2, 3
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl RemoveObjectAndFreeTiles
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	movs r1, 0xDC
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bcc _0813D846
_0813D86C:
	movs r0, 0x3
	bl FreeObjectTilesByTag
	movs r0, 0x3
	bl FreeObjectPaletteByTag
	movs r4, 0
_0813D87A:
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	lsls r1, r4, 2
	movs r2, 0xFB
	lsls r2, 4
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0813D892
	bl RemoveObjectAndFreeTiles
_0813D892:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x2
	bls _0813D87A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D824

	thumb_func_start sub_813D8A8
sub_813D8A8: @ 813D8A8
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203AB7C
	ldr r1, [r0]
	ldr r0, =0x00000fbc
	adds r1, r0
	str r1, [sp]
	ldr r0, =0x00030600
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_08DC4140
	bl LZ77UnCompWram
	mov r0, sp
	bl LoadObjectPic
	ldr r0, =gUnknown_085B40EC
	bl LoadTaggedObjectPalette
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D8A8

	thumb_func_start sub_813D8E8
sub_813D8E8: @ 813D8E8
	push {r4-r6,lr}
	ldr r1, =gUnknown_0203AB7C
	ldr r0, [r1]
	movs r2, 0x88
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0813D920
	movs r4, 0
	adds r5, r1, 0
	movs r3, 0xFB
	lsls r3, 4
	movs r2, 0
_0813D904:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r0, r3
	adds r0, r1
	str r2, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x2
	bls _0813D904
	b _0813D9A4
	.pool
_0813D920:
	movs r4, 0
	ldr r5, =gSprites
_0813D924:
	lsls r1, r4, 21
	movs r6, 0xA0
	lsls r6, 16
	adds r1, r6
	asrs r1, 16
	ldr r0, =gUnknown_085B40FC
	movs r2, 0x8C
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0813D988
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r5
	ldrh r2, [r3, 0x4]
	lsls r0, r2, 22
	lsrs r0, 22
	lsls r1, r4, 4
	adds r0, r1
	ldr r6, =0x000003ff
	adds r1, r6, 0
	ands r0, r1
	ldr r6, =0xfffffc00
	adds r1, r6, 0
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x4]
	ldr r0, =gUnknown_0203AB7C
	ldr r0, [r0]
	lsls r1, r4, 2
	movs r2, 0xFB
	lsls r2, 4
	adds r0, r2
	adds r0, r1
	str r3, [r0]
	b _0813D99A
	.pool
_0813D988:
	ldr r0, =gUnknown_0203AB7C
	ldr r1, [r0]
	lsls r0, r4, 2
	movs r6, 0xFB
	lsls r6, 4
	adds r1, r6
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_0813D99A:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x2
	bls _0813D924
_0813D9A4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813D8E8

	.align 2, 0 @ Don't pad with nop.
