	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81448B8
sub_81448B8: @ 81448B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	ldr r1, =gUnknown_085B7B12
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	ldrh r0, [r7, 0x3C]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r0, =gSpriteTemplate_85B7A10
	movs r1, 0x2E
	ldrsh r2, [r7, r1]
	lsls r2, 2
	mov r3, sp
	adds r1, r3, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	mov r4, sp
	adds r4, 0x2
	adds r2, r4, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r3, 0x32
	bl CreateSprite
	ldr r5, =gUnknown_0203AB88
	ldr r1, [r5]
	adds r1, 0x73
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x73
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r6, =gSprites
	adds r0, r6
	ldrh r1, [r7, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAnim
	ldr r0, =gUnknown_085B7AEC
	movs r1, 0x2E
	ldrsh r2, [r7, r1]
	lsls r2, 2
	mov r3, sp
	adds r1, r3, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r4, r2
	movs r3, 0
	ldrsh r2, [r4, r3]
	movs r3, 0x33
	bl CreateSprite
	ldr r1, [r5]
	adds r1, 0x74
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	mov r0, r9
	lsls r2, r0, 16
	asrs r2, 16
	ldr r3, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r1, [r0, 0x4]
	lsls r1, 30
	lsrs r0, r1, 25
	adds r0, r3
	ldrb r0, [r0, 0x1]
	muls r2, r0
	lsrs r1, 25
	adds r1, r3
	ldrh r0, [r1, 0x10]
	adds r0, 0x2D
	adds r2, r0
	strh r2, [r7, 0x3C]
_08144992:
	ldr r0, =gUnknown_0203AB88
	ldr r4, [r0]
	mov r1, r8
	adds r2, r4, r1
	adds r2, 0x73
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r1, r4, 0
	adds r1, 0x73
	ldrb r1, [r1]
	strh r1, [r0, 0x36]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r3, r4, 0
	adds r3, 0x74
	ldrb r1, [r3]
	strh r1, [r0, 0x38]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r3]
	strh r1, [r0, 0x3A]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r3, r9
	strh r3, [r0, 0x32]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r7, 0x3C]
	subs r0, 0x2D
	strh r0, [r1, 0x34]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x1
	bls _08144992
	str r7, [r4, 0x38]
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81448B8

	thumb_func_start sub_8144A24
sub_8144A24: @ 8144A24
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r7, r0, 0
	movs r0, 0
	mov r9, r0
	movs r1, 0x5
	mov r8, r1
	str r0, [sp, 0xC]
	mov r0, sp
	movs r1, 0
	movs r2, 0xA
	bl memset
	bl Random
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	ldr r3, _08144B10  @ =gUnknown_0203AB88
	ldr r0, [r3]
	adds r0, 0x7D
	movs r5, 0x1
	strb r5, [r0]
	ldr r2, [r3]
	ldrb r0, [r2, 0x3]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x3]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r0, [r3]
	adds r0, 0x7E
	movs r1, 0xFF
	strb r1, [r0]
	ldr r6, [r3]
	adds r4, r6, 0
	adds r4, 0x88
	movs r1, 0x34
	ldrsh r0, [r7, r1]
	bl __floatsisf
	str r0, [r4]
	adds r1, r6, 0
	adds r1, 0x98
	ldr r0, _08144B14  @ =0x00000000
	str r0, [r1]
	adds r2, r6, 0
	adds r2, 0x8C
	ldr r1, _08144B18  @ =gUnknown_085B6348
	ldrb r0, [r6, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r0, [r6, 0x4]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	adds r1, 0x21
	ldrb r0, [r6, 0x3]
	lsls r0, 27
	lsrs r0, 27
	subs r5, r0
	lsls r0, r5, 4
	subs r0, r5
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r5, r9
	movs r0, 0x34
	ldrsh r2, [r7, r0]
_08144ACA:
	cmp r1, r2
	bge _08144AD6
	adds r0, r1, 0
	adds r0, 0x5A
	cmp r2, r0
	ble _08144B38
_08144AD6:
	cmp r5, 0x3
	beq _08144B1C
	adds r0, r1, 0
	adds r0, 0x5A
	lsls r0, 16
	lsrs r1, r0, 16
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08144ACA
_08144AEC:
	ldr r0, _08144B10  @ =gUnknown_0203AB88
	ldr r0, [r0]
	ldrb r1, [r0, 0x3]
	movs r0, 0x1F
	ands r0, r1
	cmp r0, 0
	beq _08144B64
	movs r1, 0x2E
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _08144B58
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	bl PlayCry1
	b _08144B70
	.align 2, 0
_08144B10:
	.4byte gUnknown_0203AB88
_08144B14:
	.4byte 0x00000000
_08144B18:
	.4byte gUnknown_085B6348
_08144B1C:
	movs r0, 0x1
	strh r0, [r7, 0x2E]
	ldr r0, =gUnknown_0203AB88
	ldr r2, [r0]
	ldrb r1, [r2, 0x3]
	movs r0, 0x20
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x3]
	b _08144AEC
	.pool
_08144B38:
	lsrs r0, r5, 1
	strh r0, [r7, 0x2E]
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	movs r1, 0x1
	ands r1, r5
	ldrb r2, [r3, 0x3]
	movs r0, 0x20
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	b _08144AEC
	.pool
_08144B58:
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	bl PlayCry1
	b _08144B70
_08144B64:
	movs r0, 0x99
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	bl PlayCry1
_08144B70:
	movs r0, 0x2
	mov r10, r0
	ldr r4, =gUnknown_0203AB88
	ldr r5, [r4]
	adds r0, r5, 0
	adds r0, 0x7F
	ldrb r0, [r0]
	adds r0, 0x2
	movs r1, 0xC
	bl __modsi3
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r1, [r5, 0x3]
	movs r0, 0x1F
	ands r0, r1
	cmp r0, 0x1
	bne _08144BA8
	ldrb r1, [r5, 0x4]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _08144BA8
	mov r0, r8
	adds r0, 0x6
	b _08144BAC
	.pool
_08144BA8:
	mov r0, r8
	add r0, r10
_08144BAC:
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r5, r10
	cmp r5, r8
	bcs _08144C18
	ldr r1, =gUnknown_085B6154+0xC
	mov r10, r1
_08144BBC:
	ldr r3, [r4]
	lsls r0, r6, 3
	ldr r1, =gUnknown_085B62E4+0x4
	adds r0, r1
	ldr r1, [r3, 0x8]
	ldr r2, [r0]
	ands r1, r2
	cmp r1, 0
	bne _08144C02
	mov r0, r9
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	add r0, sp
	strb r5, [r0]
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _08144C02
	ldrb r1, [r3, 0x1A]
	lsls r1, 28
	lsrs r1, 28
	adds r0, r3, 0
	adds r0, 0x1B
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _08144C02
	str r5, [sp, 0xC]
_08144C02:
	adds r0, r6, 0x1
	movs r1, 0xC
	bl __modsi3
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r8
	bcc _08144BBC
_08144C18:
	ldr r0, [r4]
	ldrb r1, [r0, 0x3]
	lsls r1, 27
	lsrs r1, 27
	adds r1, 0x1
	ldrb r0, [r0, 0x2]
	ands r1, r0
	cmp r1, 0
	beq _08144C48
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _08144C48
	movs r0, 0xFF
	ldr r1, [sp, 0x10]
	ands r0, r1
	cmp r0, 0xBF
	bhi _08144C48
	mov r0, sp
	ldrh r0, [r0, 0xC]
	b _08144C54
	.pool
_08144C48:
	ldr r0, [sp, 0x10]
	mov r1, r9
	bl __modsi3
	add r0, sp
	ldrb r0, [r0]
_08144C54:
	strh r0, [r7, 0x3C]
	ldr r1, =sub_8144168
	str r1, [r7, 0x1C]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144A24

	thumb_func_start sub_8144C70
sub_8144C70: @ 8144C70
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0x1
	strh r1, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _08144CC0
	ldrh r0, [r2, 0x20]
	subs r0, 0x2
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _08144CC0
	ldr r4, =gUnknown_0203AB88
	ldr r3, [r4]
	ldrb r1, [r3, 0x3]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08144CAC
	movs r0, 0x40
	orrs r0, r1
	strb r0, [r3, 0x3]
_08144CAC:
	adds r0, r2, 0
	bl DestroySprite
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x1]
	ldr r1, [r4]
	ldr r0, =gUnknown_085B7B1A
	ldrh r0, [r0]
	strh r0, [r1, 0x34]
_08144CC0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144C70

	thumb_func_start sub_8144CD0
sub_8144CD0: @ 8144CD0
	push {r4,lr}
	sub sp, 0x18
	adds r4, r0, 0
	ldr r1, =gUnknown_085B7B2E
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	ldrh r0, [r4, 0x30]
	adds r2, r0, 0x1
	strh r2, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _08144D54
	movs r0, 0x1
	ands r2, r0
	cmp r2, 0
	beq _08144D2E
	ldr r3, =gSpriteCoordOffsetY
	movs r0, 0x3C
	ldrsh r2, [r4, r0]
	lsls r2, 1
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 3
	adds r2, r0
	mov r1, sp
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r3]
	movs r3, 0x3C
	ldrsh r2, [r4, r3]
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _08144D26
	adds r0, r2, 0x4
_08144D26:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	strh r0, [r4, 0x3C]
_08144D2E:
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08144D7E
	.pool
_08144D54:
	ldr r1, =gSpriteCoordOffsetY
	movs r0, 0
	strh r0, [r1]
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x73
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2C
	ldrb r2, [r0]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	adds r0, r4, 0
	bl DestroySprite
_08144D7E:
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144CD0

	thumb_func_start sub_8144D94
sub_8144D94: @ 8144D94
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	bl __floatsisf
	adds r4, r0, 0
	ldr r1, =0x3d1fbe77
	bl __mulsf3
	adds r1, r4, 0
	bl __mulsf3
	bl __fixsfsi
	strh r0, [r5, 0x26]
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r2, =gUnknown_085B7B1A
	ldrb r0, [r3, 0x1]
	subs r0, 0x1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3, 0x34]
	ldrb r0, [r3, 0x1]
	cmp r0, 0x12
	bhi _08144DDC
	adds r0, 0x1
	strb r0, [r3, 0x1]
_08144DDC:
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x3C
	ble _08144E3E
	movs r0, 0
	strh r0, [r5, 0x30]
	ldr r3, =sub_8144C70
	str r3, [r5, 0x1C]
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r2, 0
	adds r4, 0x1C
	adds r0, r4
	str r3, [r0]
	movs r0, 0x3A
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x30]
	movs r0, 0x38
	ldrsh r1, [r5, r0]
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
	movs r0, 0x38
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8144CD0
	str r1, [r0]
	movs r0, 0xD6
	bl m4aSongNumStart
_08144E3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144D94

	thumb_func_start sub_8144E60
sub_8144E60: @ 8144E60
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08144EE4
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r1, [r3, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08144E94
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x8]
	b _08144EA6
	.pool
_08144E94:
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x8]
	adds r0, 0xB4
_08144EA6:
	cmp r2, r0
	bne _08144F7C
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	movs r0, 0x2B
	bl m4aSongNumStart
	ldr r2, =gUnknown_0203AB88
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	ldr r1, [r2]
	ldr r0, =gUnknown_085B7B1A
	ldrh r0, [r0]
	strh r0, [r1, 0x34]
	b _08144F7C
	.pool
_08144EE4:
	ldr r5, =gUnknown_0203AB88
	ldr r3, [r5]
	ldr r2, =gUnknown_085B7B1A
	ldrb r0, [r3, 0x1]
	subs r0, 0x1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3, 0x34]
	ldrb r0, [r3, 0x1]
	cmp r0, 0x12
	bhi _08144F06
	adds r0, 0x1
	strb r0, [r3, 0x1]
_08144F06:
	ldr r3, [r5]
	ldr r1, [r3, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08144F30
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0xA]
	b _08144F42
	.pool
_08144F30:
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0xA]
	adds r0, 0xB4
_08144F42:
	cmp r2, r0
	bne _08144F7C
	ldr r2, =gSprites
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8144D94
	str r1, [r0]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
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
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3C]
_08144F7C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144E60

	thumb_func_start sub_8144F94
sub_8144F94: @ 8144F94
	adds r0, 0x3E
	ldrb r3, [r0]
	lsls r1, r3, 29
	lsrs r1, 31
	movs r2, 0x1
	eors r2, r1
	lsls r2, 2
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_8144F94

	thumb_func_start sub_8144FB0
sub_8144FB0: @ 8144FB0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x22]
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	ble _08144FC8
	subs r0, r2, 0x1
	strh r0, [r4, 0x22]
	b _0814501C
_08144FC8:
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x5E
	bl m4aSongNumStop
	adds r0, r4, 0
	bl DestroySprite
	ldr r5, =gSprites
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldr r0, [r4]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
_0814501C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144FB0

	thumb_func_start sub_8145030
sub_8145030: @ 8145030
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _0814505A
	subs r1, 0x1
	strh r1, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	subs r0, 0x1
	strh r0, [r4, 0x22]
	lsls r1, 16
	cmp r1, 0
	bne _081450C6
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081450C6
	b _08145080
_0814505A:
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _08145090
	subs r0, r1, 0x1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _081450C6
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08145088
_08145080:
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	b _081450C6
_08145088:
	ldrh r0, [r4, 0x26]
	subs r0, 0x1
	strh r0, [r4, 0x26]
	b _081450C6
_08145090:
	movs r0, 0x2B
	bl m4aSongNumStart
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	ldrh r1, [r0, 0x2E]
	adds r1, 0x4
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_8144FB0
	str r0, [r4, 0x1C]
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2C
	ldrb r2, [r0]
	movs r1, 0x7F
	ands r1, r2
	strb r1, [r0]
_081450C6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145030

	thumb_func_start sub_81450D8
sub_81450D8: @ 81450D8
	push {r4,r5,lr}
	sub sp, 0x14
	adds r4, r0, 0
	ldr r1, =gUnknown_085B7B46
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	add r5, sp, 0x4
	ldr r1, =gUnknown_085B7B48
	adds r0, r5, 0
	movs r2, 0x10
	bl memcpy
	ldrh r0, [r4, 0x30]
	subs r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0814516C
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	add r0, sp
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _08145208
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r4, 0x74
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	negs r4, r4
	ldr r0, =gMPlayInfo_SE1
	ldr r5, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	ldr r0, =gMPlayInfo_SE2
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	b _08145208
	.pool
_0814516C:
	lsls r0, r1, 16
	cmp r0, 0
	blt _081451BC
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r0, r2]
	add r0, sp
	movs r2, 0
	ldrsb r2, [r0, r2]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x7
	subs r0, r1, r0
	lsls r0, 1
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	muls r0, r2
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	subs r1, r0
	lsls r1, 1
	mov r0, sp
	adds r0, 0x5
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	b _08145208
	.pool
_081451BC:
	movs r0, 0x5E
	bl m4aSongNumStartOrChange
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081451E0
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	bl PlayCry1
	b _081451EC
	.pool
_081451E0:
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	bl PlayCry1
_081451EC:
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	ldrh r1, [r0, 0x2E]
	adds r1, 0x2
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0x2D
	strh r0, [r4, 0x30]
	ldr r0, =sub_8145030
	str r0, [r4, 0x1C]
_08145208:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81450D8

	thumb_func_start sub_8145218
sub_8145218: @ 8145218
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_085B7B46
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	ldrh r0, [r4, 0x30]
	subs r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	blt _08145284
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	add r0, sp
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldr r1, =gSprites
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	adds r2, 0x3E
	ldrb r3, [r2]
	lsls r0, r3, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	b _08145288
	.pool
_08145284:
	ldr r0, =sub_8144F94
	str r0, [r4, 0x1C]
_08145288:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145218

	thumb_func_start sub_8145294
sub_8145294: @ 8145294
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r1, [r3, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _081452DC
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x12]
	adds r0, 0x5A
	cmp r2, r0
	bne _0814533E
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x34
	b _08145306
	.pool
_081452DC:
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x14]
	movs r1, 0x87
	lsls r1, 1
	adds r0, r1
	cmp r2, r0
	bne _0814533E
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x2E
_08145306:
	strh r3, [r0, 0x30]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x30]
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8145218
	str r1, [r0]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =sub_81450D8
	str r1, [r0]
	movs r0, 0x2B
	bl m4aSongNumStart
_0814533E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145294

	.align 2, 0 @ Don't pad with nop.
