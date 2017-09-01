	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start CreateInvisibleSpriteWithCallback
CreateInvisibleSpriteWithCallback: @ 806F640
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gUnknown_0832A3A8
	movs r1, 0xF8
	movs r2, 0xA8
	movs r3, 0xE
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r3, r2, r5
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r4, 0x4
	orrs r1, r4
	strb r1, [r3]
	adds r5, 0x1C
	adds r2, r5
	str r6, [r2]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CreateInvisibleSpriteWithCallback

	thumb_func_start StoreWordInTwoHalfwords
StoreWordInTwoHalfwords: @ 806F67C
	strh r1, [r0]
	lsrs r1, 16
	strh r1, [r0, 0x2]
	bx lr
	thumb_func_end StoreWordInTwoHalfwords

	thumb_func_start LoadWordFromTwoHalfwords
LoadWordFromTwoHalfwords: @ 806F684
	ldrh r2, [r0]
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	lsls r0, 16
	orrs r2, r0
	str r2, [r1]
	bx lr
	thumb_func_end LoadWordFromTwoHalfwords

	thumb_func_start SetBgAffineStruct
SetBgAffineStruct: @ 806F694
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, 0x18]
	ldr r5, [sp, 0x1C]
	ldr r6, [sp, 0x20]
	ldr r7, [sp, 0x24]
	mov r8, r7
	str r1, [r0]
	str r2, [r0, 0x4]
	strh r3, [r0, 0x8]
	strh r4, [r0, 0xA]
	strh r5, [r0, 0xC]
	strh r6, [r0, 0xE]
	mov r1, r8
	strh r1, [r0, 0x10]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SetBgAffineStruct

	thumb_func_start DoBgAffineSet
DoBgAffineSet: @ 806F6C0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x24
	mov r8, r0
	ldr r0, [sp, 0x38]
	ldr r4, [sp, 0x3C]
	ldr r5, [sp, 0x40]
	ldr r6, [sp, 0x44]
	lsls r6, 16
	lsrs r6, 16
	lsls r3, 16
	asrs r3, 16
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	lsls r4, 16
	asrs r4, 16
	str r4, [sp, 0x4]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	add r0, sp, 0x10
	bl SetBgAffineStruct
	add r0, sp, 0x10
	mov r1, r8
	movs r2, 0x1
	bl BgAffineSet
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end DoBgAffineSet

	thumb_func_start CopySpriteTiles
CopySpriteTiles: @ 806F70C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	str r2, [sp, 0x20]
	adds r4, r3, 0
	ldr r7, [sp, 0x58]
	lsls r0, 24
	lsls r1, 24
	ldr r2, =gUnknown_0832A3C0
	lsrs r1, 23
	lsrs r0, 21
	adds r1, r0
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	str r0, [sp, 0x24]
	adds r1, r2
	ldrb r1, [r1]
	str r1, [sp, 0x28]
	movs r0, 0
	b _0806F88C
	.pool
_0806F740:
	movs r5, 0
	adds r0, 0x1
	str r0, [sp, 0x30]
	b _0806F874
_0806F748:
	ldrh r0, [r4]
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r1, r0
	lsls r1, 5
	mov r8, r1
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	ands r1, r0
	mov r2, sp
	strh r0, [r2, 0x34]
	cmp r1, 0
	bne _0806F788
	ldr r0, [sp, 0x20]
	add r0, r8
	adds r1, r7, 0
	ldr r2, =0x04000008
	bl CpuSet
	adds r4, 0x2
	str r4, [sp, 0x2C]
	adds r7, 0x20
	mov r10, r7
	adds r5, 0x1
	mov r9, r5
	b _0806F86A
	.pool
_0806F788:
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	bne _0806F7CC
	movs r1, 0
	adds r4, 0x2
	str r4, [sp, 0x2C]
	movs r2, 0x20
	adds r2, r7
	mov r10, r2
	adds r5, 0x1
	mov r9, r5
_0806F7A0:
	lsls r4, r1, 24
	asrs r4, 24
	movs r0, 0x7
	subs r0, r4
	lsls r0, 2
	add r0, r8
	ldr r1, [sp, 0x20]
	adds r0, r1, r0
	lsls r1, r4, 2
	adds r1, r7, r1
	ldr r2, =0x04000001
	bl CpuSet
	adds r4, 0x1
	lsls r4, 24
	lsrs r1, r4, 24
	asrs r4, 24
	cmp r4, 0x7
	ble _0806F7A0
	b _0806F86A
	.pool
_0806F7CC:
	movs r1, 0
	adds r4, 0x2
	str r4, [sp, 0x2C]
	movs r2, 0x20
	adds r2, r7
	mov r10, r2
	adds r5, 0x1
	mov r9, r5
	movs r0, 0xF
	mov r12, r0
_0806F7E0:
	movs r2, 0
	lsls r4, r1, 24
	lsls r0, r4, 2
	lsrs r0, 24
	adds r6, r0, 0x3
	mov r1, r8
	adds r5, r1, r0
_0806F7EE:
	lsls r1, r2, 24
	asrs r1, 24
	subs r0, r6, r1
	mov r2, sp
	adds r3, r2, r0
	adds r0, r5, r1
	ldr r2, [sp, 0x20]
	adds r0, r2, r0
	ldrb r2, [r0]
	mov r0, r12
	ands r0, r2
	lsls r0, 4
	lsrs r2, 4
	orrs r0, r2
	strb r0, [r3]
	adds r1, 0x1
	lsls r1, 24
	lsrs r2, r1, 24
	asrs r1, 24
	cmp r1, 0x3
	ble _0806F7EE
	movs r1, 0x80
	lsls r1, 17
	adds r0, r4, r1
	lsrs r1, r0, 24
	asrs r0, 24
	cmp r0, 0x7
	ble _0806F7E0
	mov r2, sp
	ldrh r0, [r2, 0x34]
	movs r2, 0x80
	lsls r2, 4
	ands r0, r2
	cmp r0, 0
	beq _0806F860
	movs r1, 0
_0806F836:
	lsls r4, r1, 24
	asrs r4, 24
	movs r0, 0x7
	subs r0, r4
	lsls r0, 2
	add r0, sp
	lsls r1, r4, 2
	adds r1, r7, r1
	ldr r2, =0x04000001
	bl CpuSet
	adds r4, 0x1
	lsls r4, 24
	lsrs r1, r4, 24
	asrs r4, 24
	cmp r4, 0x7
	ble _0806F836
	b _0806F86A
	.pool
_0806F860:
	mov r0, sp
	adds r1, r7, 0
	ldr r2, =0x04000008
	bl CpuSet
_0806F86A:
	ldr r4, [sp, 0x2C]
	mov r7, r10
	mov r1, r9
	lsls r0, r1, 24
	lsrs r5, r0, 24
_0806F874:
	ldr r2, [sp, 0x28]
	cmp r5, r2
	bcs _0806F87C
	b _0806F748
_0806F87C:
	movs r0, 0x20
	ldr r1, [sp, 0x28]
	subs r0, r1
	lsls r0, 1
	adds r4, r0
	ldr r2, [sp, 0x30]
	lsls r0, r2, 24
	lsrs r0, 24
_0806F88C:
	ldr r1, [sp, 0x24]
	cmp r0, r1
	bcs _0806F894
	b _0806F740
_0806F894:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopySpriteTiles

	thumb_func_start CountTrailingZeroBits
CountTrailingZeroBits: @ 806F8A8
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	movs r3, 0x1
_0806F8B0:
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _0806F8BC
	adds r0, r1, 0
	b _0806F8CA
_0806F8BC:
	lsrs r2, 1
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1F
	bls _0806F8B0
	movs r0, 0
_0806F8CA:
	pop {r1}
	bx r1
	thumb_func_end CountTrailingZeroBits

	thumb_func_start CalcCRC16
CalcCRC16: @ 806F8D0
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r2, =0x00001121
	movs r3, 0
	cmp r3, r4
	bge _0806F91C
	movs r6, 0x1
	ldr r0, =0x00008408
	adds r5, r0, 0
_0806F8E4:
	adds r0, r7, r3
	ldrb r0, [r0]
	eors r2, r0
	movs r1, 0
	adds r3, 0x1
_0806F8EE:
	adds r0, r2, 0
	ands r0, r6
	cmp r0, 0
	beq _0806F908
	lsrs r0, r2, 1
	eors r0, r5
	lsls r0, 16
	lsrs r2, r0, 16
	b _0806F90A
	.pool
_0806F908:
	lsrs r2, 1
_0806F90A:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _0806F8EE
	lsls r0, r3, 16
	lsrs r3, r0, 16
	cmp r3, r4
	blt _0806F8E4
_0806F91C:
	mvns r0, r2
	lsls r0, 16
	lsrs r0, 16
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CalcCRC16

	thumb_func_start CalcCRC16WithTable
CalcCRC16WithTable: @ 806F928
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r2, =0x00001121
	movs r3, 0
	cmp r3, r4
	bcs _0806F956
	ldr r6, =gUnknown_0832A3D8
_0806F938:
	lsrs r1, r2, 8
	adds r0, r5, r3
	ldrb r0, [r0]
	eors r2, r0
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r6
	ldrh r0, [r0]
	adds r2, r0, 0
	eors r2, r1
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r4
	bcc _0806F938
_0806F956:
	mvns r0, r2
	lsls r0, 16
	lsrs r0, 16
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CalcCRC16WithTable

	thumb_func_start CalcByteArraySum
CalcByteArraySum: @ 806F96C
	push {r4,lr}
	adds r4, r0, 0
	movs r3, 0
	movs r2, 0
	cmp r3, r1
	bcs _0806F984
_0806F978:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r3, r0
	adds r2, 0x1
	cmp r2, r1
	bcc _0806F978
_0806F984:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end CalcByteArraySum

	.align 2, 0 @ Don't pad with nop.
