	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	
	thumb_func_start sub_8105100
sub_8105100: @ 812E33C
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r4, =gUnknown_0203AAE4
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E350
	movs r0, 0x28
	bl AllocZeroed
	str r0, [r4]
_0812E350:
	ldr r2, [r4]
	ldr r0, =gUnknown_0203AAD8
	ldr r1, [r0]
	str r1, [r2]
	movs r3, 0x80
	lsls r3, 4
	strh r3, [r2, 0x4]
	adds r0, r1, r3
	str r0, [r2, 0x8]
	strh r3, [r2, 0xC]
	movs r4, 0x80
	lsls r4, 5
	adds r0, r1, r4
	str r0, [r2, 0x10]
	strh r3, [r2, 0x14]
	movs r5, 0xC0
	lsls r5, 5
	adds r0, r1, r5
	str r0, [r2, 0x18]
	strh r3, [r2, 0x1C]
	movs r0, 0x80
	lsls r0, 6
	adds r1, r0
	str r1, [r2, 0x20]
	strh r3, [r2, 0x24]
	mov r1, sp
	ldr r0, =gSpriteTemplate_83ED45C
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	str r2, [sp, 0xC]
	movs r1, 0x8C
	lsls r1, 1
	mov r0, sp
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x2
	orrs r1, r3
	strb r1, [r2]
	ldr r1, =sSlotMachine
	ldr r1, [r1]
	adds r1, 0x3F
	strb r0, [r1]
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105100

	thumb_func_start sub_810514C
sub_810514C: @ 812E3E8
	push {r4,lr}
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r4, =gUnknown_0203AAE4
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E410
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E410:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810514C

	thumb_func_start sub_812E424
sub_812E424: @ 812E424
	push {lr}
	adds r2, r0, 0
	movs r0, 0
	strh r0, [r2, 0x24]
	strh r0, [r2, 0x26]
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0812E46A
	movs r0, 0x8
	strh r0, [r2, 0x24]
	strh r0, [r2, 0x26]
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812E458
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _0812E466
	b _0812E46A
_0812E458:
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _0812E46A
_0812E466:
	ldr r0, =0x0000fff8
	strh r0, [r2, 0x26]
_0812E46A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E424

	thumb_func_start sub_81051C0
sub_81051C0: @ 812E474
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	ldr r4, =gUnknown_0203AAE8
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E490
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
_0812E490:
	ldr r2, [r4]
	ldr r0, =gUnknown_0203AAD8
	mov r10, r0
	ldr r0, [r0]
	movs r1, 0xA0
	lsls r1, 6
	adds r0, r1
	str r0, [r2]
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_085A7D40
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	str r2, [sp, 0xC]
	mov r0, sp
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0x34
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r5, =gSprites
	mov r9, r5
	adds r2, r0, r5
	ldrb r1, [r2, 0x5]
	movs r7, 0xD
	negs r7, r7
	mov r8, r7
	mov r0, r8
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r6, 0x2
	orrs r0, r6
	strb r0, [r1]
	ldr r1, =gUnknown_085A7FE0
	adds r0, r2, 0
	bl SetSubspriteTables
	ldr r5, =sSlotMachine
	ldr r0, [r5]
	adds r0, 0x49
	strb r4, [r0]
	ldr r4, =gUnknown_0203AAEC
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E510
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
_0812E510:
	ldr r2, [r4]
	mov r3, r10
	ldr r0, [r3]
	movs r4, 0xAC
	lsls r4, 6
	adds r0, r4
	str r0, [r2]
	movs r0, 0xA0
	lsls r0, 3
	strh r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_085A7D58
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	str r2, [sp, 0xC]
	mov r0, sp
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0x54
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	mov r7, r9
	adds r2, r0, r7
	ldrb r1, [r2, 0x5]
	mov r0, r8
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	ldr r1, =gUnknown_085A7FF4
	adds r0, r2, 0
	bl SetSubspriteTables
	ldr r0, [r5]
	adds r0, 0x4A
	strb r4, [r0]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81051C0

	thumb_func_start sub_8105284_
sub_8105284_: @ 812E5A8
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r4, =gUnknown_0203AAF0
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E5BC
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
_0812E5BC:
	ldr r2, [r4]
	ldr r0, =gUnknown_0203AAD8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	str r0, [r2]
	movs r0, 0xC0
	lsls r0, 3
	strh r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_085A7D70
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	str r2, [sp, 0xC]
	ldr r0, =gSpriteCoordOffsetX
	ldrh r0, [r0]
	movs r1, 0xA8
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	movs r2, 0x50
	movs r3, 0x7
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	ldr r1, =gUnknown_085A8010
	bl SetSubspriteTables
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x42
	strb r4, [r0]
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105284_

	thumb_func_start sub_81052EC
sub_81052EC: @ 812E650
	push {r4-r6,lr}
	movs r4, 0
	movs r5, 0
_0812E656:
	ldr r0, =gUnknown_085A7D88
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	ldr r1, =gSprites
	adds r3, r1
	ldrb r2, [r3, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r1, r6, 0
	ands r2, r1
	movs r1, 0x4
	orrs r2, r1
	strb r2, [r3, 0x5]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r1, [r1]
	movs r2, 0x2
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	strh r5, [r3, 0x3C]
	ldr r1, =sSlotMachine
	ldr r1, [r1]
	adds r1, 0x4B
	adds r1, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r5, 16
	movs r6, 0xA0
	lsls r6, 13
	adds r0, r6
	lsrs r5, r0, 16
	cmp r4, 0x2
	bls _0812E656
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81052EC

	thumb_func_start sub_810535C
sub_810535C: @ 812E6C4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sSlotMachine
	ldr r1, [r0]
	ldrh r0, [r4, 0x3C]
	ldrh r1, [r1, 0x14]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x28
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	adds r1, 0x3B
	strh r1, [r4, 0x22]
	movs r1, 0x14
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	bl sub_8102C48
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnimIfDifferent
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810535C

	thumb_func_start sub_81053A0
sub_81053A0: @ 812E70C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r1, 0xB8
	lsls r1, 1
	ldr r0, =gUnknown_085A7DA0
	movs r2, 0x64
	movs r3, 0x9
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r7, =gSprites
	adds r2, r0, r7
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r3, 0x2
	mov r10, r3
	mov r3, r10
	orrs r0, r3
	strb r0, [r1]
	ldrb r1, [r2, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	movs r1, 0x4
	mov r8, r1
	mov r3, r8
	orrs r0, r3
	strb r0, [r2, 0x5]
	ldr r0, =gUnknown_085A8028
	mov r9, r0
	adds r0, r2, 0
	mov r1, r9
	bl SetSubspriteTables
	ldr r6, =sSlotMachine
	ldr r0, [r6]
	adds r0, 0x4E
	strb r4, [r0]
	movs r1, 0x90
	lsls r1, 1
	ldr r0, =gUnknown_085A7DA0
	movs r2, 0x68
	movs r3, 0x4
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r2, r0, r7
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	mov r3, r10
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, 0x5]
	ands r5, r0
	mov r0, r8
	orrs r5, r0
	strb r5, [r2, 0x5]
	adds r0, r2, 0
	mov r1, r9
	bl SetSubspriteTables
	ldr r0, [r6]
	adds r0, 0x4F
	strb r4, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81053A0

	thumb_func_start sub_810545C
sub_810545C: @ 812E7CC
	push {r4,lr}
	ldr r0, =gUnknown_085A7DB8
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0x4C
	movs r3, 0xB
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, =gUnknown_085A803C
	bl SetSubspriteTables
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x40
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810545C

	thumb_func_start sub_81054B8
sub_81054B8: @ 812E82C
	push {r4,lr}
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r4, 0
_0812E846:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x49
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0812E846
	ldr r4, =gUnknown_0203AAE8
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E878
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E878:
	ldr r4, =gUnknown_0203AAEC
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E888
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E888:
	movs r4, 0
_0812E88A:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x4B
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0812E88A
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81054B8

	thumb_func_start sub_8105524
sub_8105524: @ 812E8C4
	push {r4,lr}
	movs r4, 0
_0812E8C8:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x4E
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0812E8C8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105524

	thumb_func_start sub_8105554
sub_8105554: @ 812E8F8
	push {r4,lr}
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x42
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r4, =gUnknown_0203AAF0
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E920
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E920:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105554

	thumb_func_start sub_8105578
sub_8105578: @ 812E934
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	ldr r0, =gUnknown_085A7DD0
	mov r10, r0
	movs r1, 0x98
	movs r2, 0x20
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r2, =gSprites
	mov r9, r2
	adds r3, r1, r2
	ldrb r2, [r3, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r1, r4, 0
	ands r1, r2
	movs r2, 0x4
	mov r8, r2
	mov r2, r8
	orrs r1, r2
	strb r1, [r3, 0x5]
	adds r5, r3, 0
	adds r5, 0x3F
	ldrb r1, [r5]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r5]
	ldr r6, =sSlotMachine
	ldr r1, [r6]
	adds r1, 0x50
	strb r0, [r1]
	movs r0, 0x8
	strh r0, [r3, 0x2E]
	ldr r0, =0x0000ffff
	strh r0, [r3, 0x30]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r3, 0x32]
	movs r5, 0x20
	strh r5, [r3, 0x3C]
	mov r0, r10
	movs r1, 0xB8
	movs r2, 0x20
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	mov r2, r9
	adds r3, r1, r2
	ldrb r1, [r3, 0x5]
	ands r4, r1
	mov r1, r8
	orrs r4, r1
	strb r4, [r3, 0x5]
	ldr r1, [r6]
	adds r1, 0x51
	strb r0, [r1]
	movs r0, 0x1
	strh r0, [r3, 0x30]
	subs r0, 0x2
	strh r0, [r3, 0x32]
	strh r5, [r3, 0x3C]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105578

	thumb_func_start sub_812E9E8
sub_812E9E8: @ 812E9E8
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	movs r1, 0x2E
	ldrsh r4, [r2, r1]
	cmp r4, 0
	beq _0812EA0C
	subs r0, 0x1
	movs r1, 0
	strh r0, [r2, 0x2E]
	strh r1, [r2, 0x24]
	strh r1, [r2, 0x26]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	b _0812EA3E
_0812EA0C:
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0812EA3E
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x2E]
	strh r4, [r2, 0x34]
_0812EA3E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812E9E8

	thumb_func_start sub_8105688
sub_8105688: @ 812EA44
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gSprites
	ldr r1, =sSlotMachine
	ldr r3, [r1]
	adds r1, r3, 0
	adds r1, 0x50
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x3C]
	adds r3, 0x51
	ldrb r2, [r3]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105688

	thumb_func_start sub_81056C0
sub_81056C0: @ 812EA7C
	push {r4,lr}
	movs r4, 0
_0812EA80:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x50
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0812EA80
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81056C0

	thumb_func_start sub_81056F0
sub_81056F0: @ 812EAB0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r0, =gUnknown_085A7DE8
	mov r8, r0
	movs r1, 0x48
	movs r2, 0x50
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	mov r9, r1
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	ldrb r3, [r2, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r1, r4, 0
	ands r1, r3
	movs r6, 0x4
	orrs r1, r6
	strb r1, [r2, 0x5]
	movs r3, 0
	movs r1, 0x1
	strh r1, [r2, 0x2E]
	strh r3, [r2, 0x38]
	movs r1, 0x10
	strh r1, [r2, 0x3A]
	movs r1, 0x8
	strh r1, [r2, 0x3C]
	ldr r5, =sSlotMachine
	ldr r1, [r5]
	adds r1, 0x52
	strb r0, [r1]
	mov r0, r8
	movs r1, 0x68
	movs r2, 0x50
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x5]
	ands r4, r2
	orrs r4, r6
	strb r4, [r1, 0x5]
	adds r1, 0x3F
	ldrb r2, [r1]
	movs r3, 0x1
	orrs r2, r3
	strb r2, [r1]
	ldr r1, [r5]
	adds r1, 0x53
	strb r0, [r1]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81056F0

	thumb_func_start sub_812EB48
sub_812EB48: @ 812EB48
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_085A7614
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0812EB9A
	ldrh r0, [r4, 0x3A]
	subs r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	cmp r0, 0
	bgt _0812EB9A
	movs r0, 0x7
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r2, =0x01030000
	adds r0, r2
	lsrs r0, 16
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	add r1, sp
	ldrb r3, [r1]
	adds r1, r3, 0
	adds r2, r3, 0
	bl MultiplyInvertedPaletteRGBComponents
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r1, 0x1
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3C]
	strh r0, [r4, 0x3A]
_0812EB9A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EB48

	thumb_func_start sub_81057E8
sub_81057E8: @ 812EBAC
	ldr r3, =gSprites
	ldr r1, =sSlotMachine
	ldr r1, [r1]
	adds r1, 0x52
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	strh r0, [r1, 0x3C]
	bx lr
	.pool
	thumb_func_end sub_81057E8

	thumb_func_start sub_8105804
sub_8105804: @ 812EBCC
	push {r4,lr}
	movs r0, 0x7
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r1, =0x01030000
	adds r0, r1
	lsrs r0, 16
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl MultiplyInvertedPaletteRGBComponents
	movs r4, 0
_0812EBEA:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x52
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0812EBEA
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105804

	thumb_func_start sub_8105854
sub_8105854: @ 812EC20
	push {lr}
	ldr r0, =gUnknown_085A7E00
	movs r1, 0xA8
	movs r2, 0x50
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r3, [r1, 0x5]
	movs r2, 0xD
	negs r2, r2
	ands r2, r3
	movs r3, 0x4
	orrs r2, r3
	strb r2, [r1, 0x5]
	ldr r1, =sSlotMachine
	ldr r1, [r1]
	adds r1, 0x41
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105854

	thumb_func_start sub_812EC64
sub_812EC64: @ 812EC64
	ldr r1, =gSpriteCoordOffsetY
	ldrh r1, [r1]
	strh r1, [r0, 0x26]
	bx lr
	.pool
	thumb_func_end sub_812EC64

	thumb_func_start sub_81058A0
sub_81058A0: @ 812EC70
	push {lr}
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x41
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81058A0

	thumb_func_start sub_81058C4
sub_81058C4: @ 812EC94
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r1, =gUnknown_085A7616
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	movs r4, 0
_0812ECA4:
	ldr r0, =gSpriteCoordOffsetX
	ldrh r0, [r0]
	movs r1, 0x50
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_085A7E18
	movs r2, 0x44
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	ldr r1, =gSprites
	adds r3, r1
	ldrb r2, [r3, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r1, r5, 0
	ands r2, r1
	movs r1, 0x4
	orrs r2, r1
	strb r2, [r3, 0x5]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r1, [r1]
	movs r2, 0x2
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	lsls r1, r4, 1
	add r1, sp
	ldrh r1, [r1]
	strh r1, [r3, 0x2E]
	ldr r1, =sSlotMachine
	ldr r1, [r1]
	adds r1, 0x54
	adds r1, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0812ECA4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81058C4

	thumb_func_start sub_812ED20
sub_812ED20: @ 812ED20
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	subs r0, 0x2
	movs r4, 0
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r1, 0x14
	bl Cos
	strh r0, [r5, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	movs r1, 0x6
	bl Sin
	strh r0, [r5, 0x26]
	adds r1, r5, 0
	adds r1, 0x43
	strb r4, [r1]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x7F
	ble _0812ED5A
	movs r0, 0x2
	strb r0, [r1]
_0812ED5A:
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0812ED84
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r0, r2, 31
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0
	strh r0, [r5, 0x30]
_0812ED84:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_812ED20

	thumb_func_start sub_81059B8
sub_81059B8: @ 812ED8C
	push {r4,lr}
	movs r4, 0
_0812ED90:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x54
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0812ED90
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81059B8

	thumb_func_start sub_81059E8
sub_81059E8: @ 812EDC0
	push {r4,lr}
	ldr r0, =gUnknown_085A7E30
	movs r1, 0xA8
	movs r2, 0x3C
	movs r3, 0x8
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	bl InitSpriteAffineAnim
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x43
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81059E8

	thumb_func_start sub_812EE14
sub_812EE14: @ 812EE14
	push {lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _0812EE36
	adds r0, r3, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812EE90
	adds r0, r2, 0x1
	strh r0, [r3, 0x2E]
	b _0812EE90
_0812EE36:
	cmp r0, 0x1
	bne _0812EE72
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	ble _0812EE90
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	movs r0, 0
	strh r0, [r3, 0x32]
	b _0812EE90
_0812EE72:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0812EE90
	movs r0, 0x1
	strh r0, [r3, 0x3C]
_0812EE90:
	ldrh r0, [r3, 0x30]
	movs r1, 0xFF
	ands r1, r0
	adds r1, 0x10
	strh r1, [r3, 0x30]
	lsrs r1, 8
	ldrh r0, [r3, 0x26]
	subs r0, r1
	strh r0, [r3, 0x26]
	pop {r0}
	bx r0
	thumb_func_end sub_812EE14

	thumb_func_start sub_8105ACC
sub_8105ACC: @ 812EEA8
	ldr r2, =gSprites
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x43
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_8105ACC

	thumb_func_start sub_8105AEC
sub_8105AEC: @ 812EECC
	push {r4,lr}
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	adds r0, 0x43
	ldrb r0, [r0]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105AEC

	thumb_func_start sub_8105B1C
sub_8105B1C: @ 812EF00
	push {r4,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gUnknown_085A7F98
	lsls r3, 16
	asrs r3, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r3, 0
	movs r3, 0xC
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	bl InitSpriteAffineAnim
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8105B1C

	thumb_func_start sub_812EF54
sub_812EF54: @ 812EF54
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812EF68
	movs r0, 0x1
	strh r0, [r2, 0x3C]
_0812EF68:
	pop {r0}
	bx r0
	thumb_func_end sub_812EF54

	thumb_func_start sub_8105B88
sub_8105B88: @ 812EF6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105B88

	thumb_func_start sub_8105BB4
sub_8105BB4: @ 812EF98
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gUnknown_085A78C8
	lsrs r1, 22
	adds r3, r1, r3
	ldr r5, [r3]
	ldr r3, =gUnknown_085A783A
	adds r4, r1, r3
	movs r6, 0
	ldrsh r4, [r4, r6]
	adds r3, 0x2
	adds r1, r3
	movs r6, 0
	ldrsh r3, [r1, r6]
	lsls r2, 16
	asrs r2, 16
	str r2, [sp]
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8105BF8
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8105BB4

	thumb_func_start sub_8105BF8
sub_8105BF8: @ 812EFDC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	adds r4, r0, 0
	mov r8, r1
	adds r1, r2, 0
	adds r2, r3, 0
	ldr r5, [sp, 0x34]
	lsls r4, 24
	lsls r5, 16
	lsrs r5, 16
	mov r9, r5
	ldr r0, =gUnknown_085A8264
	lsrs r4, 22
	adds r0, r4, r0
	mov r3, sp
	ldr r0, [r0]
	ldm r0!, {r5-r7}
	stm r3!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r3!, {r5-r7}
	ldr r0, =gUnknown_03001188
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r3, 0x10
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	ldrb r0, [r2, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r2, 0x5]
	mov r0, r8
	str r0, [r2, 0x1C]
	mov r5, r9
	strh r5, [r2, 0x3A]
	movs r0, 0x1
	strh r0, [r2, 0x3C]
	ldr r0, =gUnknown_085A82CC
	adds r4, r0
	ldr r1, [r4]
	cmp r1, 0
	beq _0812F056
	adds r0, r2, 0
	bl SetSubspriteTables
_0812F056:
	adds r0, r7, 0
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8105BF8

	thumb_func_start sub_812F078
sub_812F078: @ 812F078
	movs r1, 0
	strh r1, [r0, 0x3C]
	bx lr
	thumb_func_end sub_812F078

	thumb_func_start sub_812F080
sub_812F080: @ 812F080
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r1, =gUnknown_085A761E
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	add r5, sp, 0x8
	ldr r1, =gUnknown_085A7626
	adds r0, r5, 0
	movs r2, 0x8
	bl memcpy
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0812F0C6
	adds r3, r4, 0
	adds r3, 0x42
	ldrb r2, [r3]
	lsls r0, r2, 26
	lsrs r0, 26
	movs r1, 0x1
	eors r1, r0
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0
	strh r0, [r4, 0x30]
_0812F0C6:
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x42
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	beq _0812F0F2
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r4, 0x26]
_0812F0F2:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F080

	thumb_func_start sub_812F104
sub_812F104: @ 812F104
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3F
	ldrb r1, [r3]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r3]
	bl sub_812F080
	pop {r0}
	bx r0
	thumb_func_end sub_812F104

	thumb_func_start sub_812F11C
sub_812F11C: @ 812F11C
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3F
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	bl sub_812F080
	pop {r0}
	bx r0
	thumb_func_end sub_812F11C

	thumb_func_start sub_812F134
sub_812F134: @ 812F134
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3F
	ldrb r1, [r3]
	movs r2, 0x1
	orrs r1, r2
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	bl sub_812F080
	pop {r0}
	bx r0
	thumb_func_end sub_812F134

	thumb_func_start sub_812F150
sub_812F150: @ 812F150
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _0812F184
	cmp r0, 0x1
	bgt _0812F166
	cmp r0, 0
	beq _0812F170
	b _0812F1B4
_0812F166:
	cmp r0, 0x2
	beq _0812F194
	cmp r0, 0x3
	beq _0812F1B0
	b _0812F1B4
_0812F170:
	ldrh r0, [r2, 0x20]
	adds r0, 0x4
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xCF
	ble _0812F1B4
	movs r0, 0xD0
	strh r0, [r2, 0x20]
	b _0812F1A2
_0812F184:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	ble _0812F1B4
	b _0812F1A2
_0812F194:
	ldrh r0, [r2, 0x20]
	adds r0, 0x4
	strh r0, [r2, 0x20]
	lsls r0, 16
	ldr r1, =0x010f0000
	cmp r0, r1
	ble _0812F1B4
_0812F1A2:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _0812F1B4
	.pool
_0812F1B0:
	movs r0, 0
	strh r0, [r2, 0x3C]
_0812F1B4:
	pop {r0}
	bx r0
	thumb_func_end sub_812F150

	thumb_func_start sub_812F1B8
sub_812F1B8: @ 812F1B8
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0812F1EC
	cmp r0, 0x1
	bgt _0812F1CE
	cmp r0, 0
	beq _0812F1D8
	b _0812F216
_0812F1CE:
	cmp r0, 0x2
	beq _0812F1FC
	cmp r0, 0x3
	beq _0812F212
	b _0812F216
_0812F1D8:
	ldrh r0, [r1, 0x20]
	subs r0, 0x4
	strh r0, [r1, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD0
	bgt _0812F216
	movs r0, 0xD0
	strh r0, [r1, 0x20]
	b _0812F20A
_0812F1EC:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	ble _0812F216
	b _0812F20A
_0812F1FC:
	ldrh r0, [r1, 0x20]
	subs r0, 0x4
	strh r0, [r1, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x90
	bgt _0812F216
_0812F20A:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _0812F216
_0812F212:
	movs r0, 0
	strh r0, [r1, 0x3C]
_0812F216:
	pop {r0}
	bx r0
	thumb_func_end sub_812F1B8

	thumb_func_start sub_812F21C
sub_812F21C: @ 812F21C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bhi _0812F2C6
	lsls r0, 2
	ldr r1, =_0812F238
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812F238:
	.4byte _0812F250
	.4byte _0812F268
	.4byte _0812F288
	.4byte _0812F29C
	.4byte _0812F2AC
	.4byte _0812F2C2
_0812F250:
	ldr r0, =sSlotMachine
	ldr r0, [r0]
	ldrb r1, [r0, 0xA]
	subs r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0812F268:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0812F2C6
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0
	strh r0, [r4, 0x30]
	b _0812F2C6
	.pool
_0812F288:
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xCF
	ble _0812F2C6
	movs r0, 0xD0
	strh r0, [r4, 0x20]
	b _0812F2BA
_0812F29C:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	ble _0812F2C6
	b _0812F2BA
_0812F2AC:
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF7
	ble _0812F2C6
_0812F2BA:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0812F2C6
_0812F2C2:
	movs r0, 0
	strh r0, [r4, 0x3C]
_0812F2C6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812F21C

	thumb_func_start sub_812F2CC
sub_812F2CC: @ 812F2CC
	push {lr}
	adds r3, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	beq _0812F2FA
	cmp r0, 0x1
	bgt _0812F2E2
	cmp r0, 0
	beq _0812F2E8
	b _0812F368
_0812F2E2:
	cmp r0, 0x2
	beq _0812F318
	b _0812F368
_0812F2E8:
	adds r2, r3, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
_0812F2FA:
	ldrh r0, [r3, 0x22]
	adds r0, 0x8
	strh r0, [r3, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	ble _0812F368
	movs r0, 0x70
	strh r0, [r3, 0x22]
	movs r0, 0x10
	strh r0, [r3, 0x30]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _0812F368
_0812F318:
	movs r0, 0x32
	ldrsh r2, [r3, r0]
	cmp r2, 0
	bne _0812F35E
	ldrh r0, [r3, 0x22]
	ldrh r1, [r3, 0x30]
	subs r0, r1
	strh r0, [r3, 0x22]
	negs r1, r1
	strh r1, [r3, 0x30]
	ldrh r0, [r3, 0x34]
	adds r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0812F35E
	lsls r0, r1, 16
	asrs r0, 18
	strh r0, [r3, 0x30]
	strh r2, [r3, 0x34]
	adds r1, r0, 0
	cmp r1, 0
	bne _0812F35E
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	strh r1, [r3, 0x3C]
	adds r2, r3, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0812F35E:
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r3, 0x32]
_0812F368:
	pop {r0}
	bx r0
	thumb_func_end sub_812F2CC

	thumb_func_start sub_812F36C
sub_812F36C: @ 812F36C
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0812F37E
	cmp r0, 0x1
	beq _0812F394
	b _0812F3B0
_0812F37E:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0812F3B0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _0812F3B0
_0812F394:
	ldrh r0, [r1, 0x22]
	adds r0, 0x2
	strh r0, [r1, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2F
	ble _0812F3B0
	movs r0, 0x30
	strh r0, [r1, 0x22]
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	movs r0, 0
	strh r0, [r1, 0x3C]
_0812F3B0:
	pop {r0}
	bx r0
	thumb_func_end sub_812F36C

	thumb_func_start sub_812F3B4
sub_812F3B4: @ 812F3B4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0812F3C6
	cmp r0, 0x1
	beq _0812F416
	b _0812F468
_0812F3C6:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	ble _0812F468
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x5
	strh r0, [r4, 0x30]
	ldrb r0, [r4, 0x1]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r4, 0x30]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	b _0812F468
_0812F416:
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r4, 0x30]
	subs r0, r1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _0812F42C
	movs r0, 0
	strh r0, [r4, 0x30]
_0812F42C:
	ldrh r0, [r4, 0x30]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	ldrh r1, [r4, 0x32]
	movs r0, 0xFF
	ands r0, r1
	adds r0, 0x80
	strh r0, [r4, 0x32]
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _0812F468
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x3C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
_0812F468:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812F3B4

	thumb_func_start sub_812F470
sub_812F470: @ 812F470
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x2
	bgt _0812F4C0
	ldr r1, =gUnknown_085A8510
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0812F4FC
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	movs r0, 0
	strh r0, [r5, 0x32]
	b _0812F4FC
	.pool
_0812F4C0:
	ldr r1, =gUnknown_085A8510
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	ble _0812F4FC
	strh r1, [r5, 0x30]
	strh r1, [r5, 0x32]
_0812F4FC:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnimIfDifferent
	movs r0, 0
	strh r0, [r5, 0x3C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F470

	thumb_func_start sub_812F514
sub_812F514: @ 812F514
	push {r4-r6,lr}
	sub sp, 0x30
	adds r4, r0, 0
	ldr r1, =gUnknown_085A762E
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	add r6, sp, 0x10
	ldr r1, =gUnknown_085A763E
	adds r0, r6, 0
	movs r2, 0x10
	bl memcpy
	add r5, sp, 0x20
	ldr r1, =gUnknown_085A764E
	adds r0, r5, 0
	movs r2, 0x10
	bl memcpy
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0812F58C
	cmp r0, 0x1
	bgt _0812F55C
	cmp r0, 0
	beq _0812F562
	b _0812F5D8
	.pool
_0812F55C:
	cmp r0, 0x2
	beq _0812F5A0
	b _0812F5D8
_0812F562:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	adds r0, r6, r0
	ldrh r0, [r0]
	strh r0, [r4, 0x26]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0812F58C:
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0812F5D8
	b _0812F5D2
_0812F5A0:
	ldrh r0, [r4, 0x24]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	cmp r1, 0
	ble _0812F5AE
	subs r0, 0x4
	b _0812F5B4
_0812F5AE:
	cmp r1, 0
	bge _0812F5B6
	adds r0, 0x4
_0812F5B4:
	strh r0, [r4, 0x24]
_0812F5B6:
	ldrh r0, [r4, 0x26]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	cmp r1, 0
	ble _0812F5C4
	subs r0, 0x4
	b _0812F5CA
_0812F5C4:
	cmp r1, 0
	bge _0812F5CC
	adds r0, 0x4
_0812F5CA:
	strh r0, [r4, 0x26]
_0812F5CC:
	ldr r0, [r4, 0x24]
	cmp r0, 0
	bne _0812F5D8
_0812F5D2:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0812F5D8:
	add sp, 0x30
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_812F514

	thumb_func_start sub_812F5E0
sub_812F5E0: @ 812F5E0
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r1, =gUnknown_085A765E
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0812F602
	adds r0, r1, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0xC
	strh r0, [r4, 0x30]
_0812F602:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0812F63C
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
_0812F63C:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F5E0

	thumb_func_start sub_812F648
sub_812F648: @ 812F648
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0812F694
	cmp r0, 0x1
	bgt _0812F660
	cmp r0, 0
	beq _0812F66A
	b _0812F76C
_0812F660:
	cmp r0, 0x2
	beq _0812F6E0
	cmp r0, 0x3
	beq _0812F71C
	b _0812F76C
_0812F66A:
	ldr r0, =sSlotMachine
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x5C
	movs r0, 0x2F
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x3F
	strh r0, [r1]
	subs r1, 0x4
	ldr r0, =0x00002088
	strh r0, [r1]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0812F694:
	ldrh r0, [r5, 0x30]
	adds r2, r0, 0x2
	strh r2, [r5, 0x30]
	adds r0, 0xB2
	strh r0, [r5, 0x32]
	movs r1, 0xF0
	subs r1, r2
	strh r1, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD0
	ble _0812F6B0
	movs r0, 0xD0
	strh r0, [r5, 0x32]
_0812F6B0:
	movs r1, 0x34
	ldrsh r0, [r5, r1]
	cmp r0, 0xCF
	bgt _0812F6BC
	movs r0, 0xD0
	strh r0, [r5, 0x34]
_0812F6BC:
	ldr r0, =sSlotMachine
	ldr r2, [r0]
	ldrh r0, [r5, 0x32]
	lsls r0, 8
	ldrh r1, [r5, 0x34]
	orrs r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x33
	ble _0812F76C
	b _0812F75E
	.pool
_0812F6E0:
	ldr r6, =sSlotMachine
	ldr r0, [r6]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0812F76C
	ldr r1, =SpriteCallbackDummy
	movs r4, 0
	str r4, [sp]
	movs r0, 0x5
	movs r2, 0xD0
	movs r3, 0x74
	bl sub_8104D30
	ldr r2, [r6]
	adds r1, r2, 0
	adds r1, 0x58
	ldr r0, =0x0000c0e0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0xD1
	lsls r0, 7
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x2F
	strh r0, [r1]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	strh r4, [r5, 0x30]
_0812F71C:
	ldrh r0, [r5, 0x30]
	adds r2, r0, 0x2
	strh r2, [r5, 0x30]
	adds r0, 0xC2
	strh r0, [r5, 0x32]
	movs r1, 0xE0
	subs r1, r2
	strh r1, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD0
	ble _0812F738
	movs r0, 0xD0
	strh r0, [r5, 0x32]
_0812F738:
	movs r1, 0x34
	ldrsh r0, [r5, r1]
	cmp r0, 0xCF
	bgt _0812F744
	movs r0, 0xD0
	strh r0, [r5, 0x34]
_0812F744:
	ldr r0, =sSlotMachine
	ldr r2, [r0]
	ldrh r0, [r5, 0x32]
	lsls r0, 8
	ldrh r1, [r5, 0x34]
	orrs r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0xF
	ble _0812F76C
_0812F75E:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	adds r1, r2, 0
	adds r1, 0x5C
	movs r0, 0x3F
	strh r0, [r1]
_0812F76C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F648

	thumb_func_start nullsub_101
nullsub_101: @ 812F780
	bx lr
	thumb_func_end nullsub_101

	thumb_func_start sub_812F784
sub_812F784: @ 812F784
	push {lr}
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_812F784

	thumb_func_start sub_812F794
sub_812F794: @ 812F794
	push {r4,lr}
	ldr r0, =gUnknown_085A8520
	ldr r4, [r0]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F794

	thumb_func_start sub_812F7C0
sub_812F7C0: @ 812F7C0
	ldr r0, =sSlotMachine
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x58
	movs r0, 0xF0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0xA0
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x5C
	movs r1, 0x3F
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_812F7C0

	thumb_func_start sub_812F7E4
sub_812F7E4: @ 812F7E4
	push {r4-r6,lr}
	bl sub_812F8A0
	ldr r4, =gUnknown_0203AAD4
	movs r0, 0xC8
	lsls r0, 6
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gSlotMachineReelTime_Gfx
	bl LZDecompressWram
	ldr r4, =gUnknown_0203AAD8
	movs r0, 0xD8
	lsls r0, 6
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gUnknown_085A858C
	bl LZDecompressWram
	ldr r4, =gUnknown_0203AB30
	movs r0, 0xB0
	bl AllocZeroed
	str r0, [r4]
	movs r3, 0
	ldr r5, =gUnknown_085A8334
	adds r6, r4, 0
_0812F822:
	ldr r2, [r4]
	lsls r1, r3, 3
	adds r2, r1, r2
	adds r1, r5
	ldr r0, [r1]
	str r0, [r2]
	ldrh r0, [r1, 0x4]
	strh r0, [r2, 0x4]
	ldrh r0, [r1, 0x6]
	strh r0, [r2, 0x6]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x15
	bls _0812F822
	ldr r3, [r6]
	adds r2, r3, 0
	adds r2, 0x88
	ldr r0, =gUnknown_0203AAD4
	ldr r1, [r0]
	movs r4, 0xA0
	lsls r4, 4
	adds r0, r1, r4
	str r0, [r2]
	adds r2, 0x8
	movs r4, 0xA0
	lsls r4, 5
	adds r0, r1, r4
	str r0, [r2]
	adds r2, 0x8
	movs r4, 0xB0
	lsls r4, 5
	adds r0, r1, r4
	str r0, [r2]
	adds r0, r3, 0
	adds r0, 0xA0
	movs r2, 0xC8
	lsls r2, 5
	adds r1, r2
	str r1, [r0]
	adds r0, r3, 0
	bl LoadSpriteSheets
	ldr r0, =gUnknown_085A8544
	bl LoadSpritePalettes
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F7E4

	thumb_func_start sub_812F8A0
sub_812F8A0: @ 812F8A0
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203AB2C
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r5]
	ldr r4, =gUnknown_0203AAE0
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	adds r3, r0, 0
	movs r1, 0
	adds r6, r4, 0
	ldr r0, =gUnknown_085A83E4
	ldr r4, [r0]
_0812F8C2:
	movs r2, 0
	adds r1, 0x1
_0812F8C6:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, 0x1
	cmp r2, 0x1F
	bls _0812F8C6
	lsls r0, r1, 24
	lsrs r1, r0, 24
	cmp r1, 0x3F
	bls _0812F8C2
	ldr r0, [r5]
	ldr r1, [r6]
	str r1, [r0]
	movs r1, 0x80
	lsls r1, 4
	strh r1, [r0, 0x4]
	movs r1, 0x11
	strh r1, [r0, 0x6]
	bl LoadSpriteSheet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F8A0

	thumb_func_start sub_812F908
sub_812F908: @ 812F908
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203AAC8
	movs r5, 0x88
	lsls r5, 6
	adds r0, r5, 0
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gSlotMachineMenu_Gfx
	bl LZDecompressWram
	ldr r1, [r4]
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r0, =gSlotMachineMenu_Pal
	movs r1, 0
	movs r2, 0xA0
	bl LoadPalette
	ldr r0, =gUnknown_085A8524
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F908

	thumb_func_start sub_812F958
sub_812F958: @ 812F958
	push {lr}
	bl sub_812F968
	bl sub_812F980
	pop {r0}
	bx r0
	thumb_func_end sub_812F958

	thumb_func_start sub_812F968
sub_812F968: @ 812F968
	push {lr}
	ldr r1, =gSlotMachineMenu_Tilemap
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F968

	thumb_func_start sub_812F980
sub_812F980: @ 812F980
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r1, 0x4
	ldr r0, =gUnknown_0203AAD0
	mov r8, r0
_0812F98E:
	movs r0, 0
	lsls r1, 16
	mov r9, r1
_0812F994:
	mov r2, r8
	ldr r1, [r2]
	mov r2, r9
	asrs r6, r2, 16
	lsls r4, r0, 16
	asrs r4, 16
	adds r5, r6, r4
	adds r3, r5, 0
	adds r3, 0xA0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0x2
	movs r2, 0xD0
	lsls r2, 1
	adds r3, r5, r2
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0x4
	adds r3, r5, 0
	adds r3, 0xC0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r2, r8
	ldr r1, [r2]
	adds r1, 0x6
	movs r0, 0xC0
	lsls r0, 1
	adds r7, r0, 0
	adds r3, r5, r7
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	adds r4, 0x1
	lsls r4, 16
	lsrs r0, r4, 16
	asrs r4, 16
	cmp r4, 0x3
	ble _0812F994
	mov r2, r8
	ldr r1, [r2]
	adds r1, 0x8
	adds r3, r6, 0
	adds r3, 0xC0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0xA
	adds r3, r6, r7
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	movs r0, 0x7
_0812FA32:
	mov r2, r8
	ldr r1, [r2]
	adds r1, 0xC
	lsls r4, r0, 16
	asrs r4, 16
	lsls r3, r4, 5
	mov r0, r9
	asrs r5, r0, 16
	adds r3, r5, r3
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	adds r4, 0x1
	lsls r4, 16
	lsrs r0, r4, 16
	asrs r4, 16
	cmp r4, 0xB
	ble _0812FA32
	adds r0, r5, 0x5
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x11
	ble _0812F98E
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F980

	thumb_func_start sub_81065A8
sub_81065A8: @ 812FA78
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, [sp, 0x10]
	ldr r6, =gUnknown_0203AADC
	ldr r0, [r6]
	strh r1, [r0]
	ldr r1, [r6]
	strh r2, [r1, 0x2]
	strh r3, [r1, 0x4]
	strh r5, [r1, 0x6]
	lsls r4, 16
	asrs r5, r4, 16
	movs r0, 0xF0
	lsls r0, 17
	adds r4, r0
	lsrs r4, 16
	movs r0, 0x2
	movs r2, 0x2
	adds r3, r4, 0
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, 0x2
	ldr r0, =0x000001e1
	adds r3, r5, r0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, 0x4
	movs r0, 0x80
	lsls r0, 2
	adds r3, r5, r0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, 0x6
	ldr r0, =0x00000201
	adds r5, r0
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0x2
	movs r2, 0x2
	adds r3, r5, 0
	bl LoadBgTilemap
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81065A8

	thumb_func_start sub_81065DC
sub_81065DC: @ 812FAF4
	push {lr}
	ldr r1, =gUnknown_08DCEC70
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	movs r0, 0x3
	bl HideBg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81065DC

	thumb_func_start SlotMachineSetup_9_0
SlotMachineSetup_9_0: @ 812FB14
	ldr r1, =gUnknown_03001188
	ldr r0, =gUnknown_0203AAF4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, =gUnknown_0203AAF8
	ldr r0, [r0]
	str r0, [r1, 0x4]
	ldr r0, =gUnknown_0203AAFC
	ldr r0, [r0]
	str r0, [r1, 0x8]
	ldr r0, =gUnknown_0203AB04
	ldr r0, [r0]
	str r0, [r1, 0xC]
	ldr r0, =gUnknown_0203AB08
	ldr r0, [r0]
	str r0, [r1, 0x10]
	ldr r0, =gUnknown_0203AB18
	ldr r0, [r0]
	str r0, [r1, 0x14]
	ldr r0, =gUnknown_0203AB1C
	ldr r0, [r0]
	str r0, [r1, 0x18]
	ldr r0, =gUnknown_0203AB20
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	ldr r0, =gUnknown_0203AB24
	ldr r0, [r0]
	str r0, [r1, 0x20]
	ldr r0, =gUnknown_0203AB28
	ldr r0, [r0]
	str r0, [r1, 0x24]
	ldr r0, =gUnknown_0203AB00
	ldr r0, [r0]
	str r0, [r1, 0x28]
	str r0, [r1, 0x2C]
	str r0, [r1, 0x30]
	str r0, [r1, 0x34]
	ldr r0, =gUnknown_0203AB0C
	ldr r0, [r0]
	str r0, [r1, 0x38]
	str r0, [r1, 0x3C]
	str r0, [r1, 0x40]
	str r0, [r1, 0x44]
	str r0, [r1, 0x48]
	ldr r0, =gUnknown_0203AB10
	ldr r0, [r0]
	str r0, [r1, 0x4C]
	str r0, [r1, 0x50]
	str r0, [r1, 0x54]
	ldr r0, =gUnknown_0203AB14
	ldr r0, [r0]
	str r0, [r1, 0x58]
	str r0, [r1, 0x5C]
	str r0, [r1, 0x60]
	movs r0, 0
	str r0, [r1, 0x64]
	bx lr
	.pool
	thumb_func_end SlotMachineSetup_9_0

	thumb_func_start SlotMachineSetup_8_0
SlotMachineSetup_8_0: @ 812FBC4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r4, =gUnknown_0203AAF4
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r6, =gUnknown_0203AAD4
	ldr r1, [r6]
	str r1, [r0]
	movs r5, 0xC0
	lsls r5, 3
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AAF8
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	adds r1, r5
	str r1, [r0]
	movs r1, 0x80
	lsls r1, 2
	mov r8, r1
	mov r2, r8
	strh r2, [r0, 0x4]
	ldr r4, =gUnknown_0203AAFC
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, 0x80
	lsls r3, 4
	adds r1, r3
	str r1, [r0]
	mov r4, r8
	strh r4, [r0, 0x4]
	ldr r4, =gUnknown_0203AB00
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, 0xA0
	lsls r2, 4
	adds r1, r2
	str r1, [r0]
	mov r3, r8
	strh r3, [r0, 0x4]
	ldr r4, =gUnknown_0203AB04
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, 0xC0
	lsls r4, 4
	adds r1, r4
	str r1, [r0]
	movs r5, 0xC0
	lsls r5, 2
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AB08
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	str r1, [r0]
	movs r1, 0x80
	lsls r1, 3
	strh r1, [r0, 0x4]
	ldr r4, =gUnknown_0203AB0C
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, 0xA0
	lsls r3, 5
	adds r1, r3
	str r1, [r0]
	mov r4, r8
	strh r4, [r0, 0x4]
	ldr r4, =gUnknown_0203AB10
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, 0xB0
	lsls r2, 5
	adds r1, r2
	str r1, [r0]
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AB14
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, 0xC8
	lsls r3, 5
	adds r1, r3
	str r1, [r0]
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AB18
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, 0xE0
	lsls r4, 5
	adds r2, r1, r4
	str r2, [r0]
	mov r2, r8
	strh r2, [r0, 0x4]
	movs r3, 0xF0
	lsls r3, 5
	adds r1, r3
	str r1, [r0, 0x8]
	strh r2, [r0, 0xC]
	ldr r4, =gUnknown_0203AB1C
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, 0x80
	lsls r4, 6
	adds r1, r4
	str r1, [r0]
	movs r1, 0xA0
	lsls r1, 2
	strh r1, [r0, 0x4]
	ldr r4, =gUnknown_0203AB20
	movs r0, 0x28
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, 0x8A
	lsls r3, 6
	adds r1, r2, r3
	str r1, [r0]
	movs r3, 0x80
	strh r3, [r0, 0x4]
	movs r4, 0x8C
	lsls r4, 6
	adds r1, r2, r4
	str r1, [r0, 0x8]
	strh r3, [r0, 0xC]
	adds r4, 0x80
	adds r1, r2, r4
	str r1, [r0, 0x10]
	strh r3, [r0, 0x14]
	adds r4, 0x80
	adds r1, r2, r4
	str r1, [r0, 0x18]
	strh r3, [r0, 0x1C]
	movs r1, 0x92
	lsls r1, 6
	adds r2, r1
	str r2, [r0, 0x20]
	strh r3, [r0, 0x24]
	ldr r4, =gUnknown_0203AB24
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, 0x98
	lsls r3, 6
	adds r1, r2, r3
	str r1, [r0]
	movs r1, 0x90
	lsls r1, 3
	strh r1, [r0, 0x4]
	movs r4, 0xAA
	lsls r4, 6
	adds r2, r4
	str r2, [r0, 0x8]
	strh r1, [r0, 0xC]
	ldr r4, =gUnknown_0203AB28
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, 0xBC
	lsls r3, 6
	adds r1, r2, r3
	str r1, [r0]
	movs r1, 0xC0
	lsls r1, 1
	strh r1, [r0, 0x4]
	movs r4, 0xC2
	lsls r4, 6
	adds r2, r4
	str r2, [r0, 0x8]
	strh r1, [r0, 0xC]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SlotMachineSetup_8_0

	.align 2, 0 @ Don't pad with nop.
