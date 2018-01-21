	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ScanlineEffect_Stop
ScanlineEffect_Stop: @ 80B9FB8
	push {r4,lr}
	ldr r4, =gUnknown_02039B28
	movs r0, 0
	strb r0, [r4, 0x15]
	ldr r1, =0x040000b0
	ldrh r2, [r1, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r0, =0x00007fff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	ldrb r0, [r4, 0x18]
	cmp r0, 0xFF
	beq _080B9FE2
	bl DestroyTask
	movs r0, 0xFF
	strb r0, [r4, 0x18]
_080B9FE2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ScanlineEffect_Stop

	thumb_func_start dp12_8087EA4
dp12_8087EA4: @ 80B9FF8
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	movs r4, 0
	strh r4, [r0]
	ldr r1, =gUnknown_02038C28
	ldr r2, =0x01000780
	bl CpuSet
	ldr r0, =gUnknown_02039B28
	movs r1, 0
	str r1, [r0]
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	strb r4, [r0, 0x14]
	strb r4, [r0, 0x15]
	strb r4, [r0, 0x16]
	strb r4, [r0, 0x17]
	movs r1, 0xFF
	strb r1, [r0, 0x18]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp12_8087EA4

	thumb_func_start sub_80BA038
sub_80BA038: @ 80BA038
	push {lr}
	sub sp, 0xC
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r0, =0xa2600001
	cmp r1, r0
	bne _080BA06C
	ldr r0, =gUnknown_02039B28
	ldr r1, =gUnknown_02038C2A
	str r1, [r0]
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	str r1, [r0, 0x4]
	ldr r1, =sub_80BA134
	b _080BA07C
	.pool
_080BA06C:
	ldr r0, =gUnknown_02039B28
	ldr r1, =gUnknown_02038C2C
	str r1, [r0]
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	str r1, [r0, 0x4]
	ldr r1, =sub_80BA154
_080BA07C:
	str r1, [r0, 0x10]
	adds r1, r0, 0
	ldr r0, [sp, 0x4]
	str r0, [r1, 0xC]
	ldr r0, [sp]
	str r0, [r1, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x8]
	strb r0, [r1, 0x15]
	mov r0, sp
	ldrb r0, [r0, 0x9]
	strb r0, [r1, 0x16]
	strb r0, [r1, 0x17]
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BA038

	thumb_func_start sub_80BA0A8
sub_80BA0A8: @ 80BA0A8
	push {r4,lr}
	ldr r4, =gUnknown_02039B28
	ldrb r0, [r4, 0x15]
	cmp r0, 0
	beq _080BA122
	cmp r0, 0x3
	bne _080BA0EC
	movs r0, 0
	strb r0, [r4, 0x15]
	ldr r1, =0x040000b0
	ldrh r2, [r1, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r0, =0x00007fff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	ldr r1, =gUnknown_02039B44
	movs r0, 0x1
	strb r0, [r1]
	b _080BA122
	.pool
_080BA0EC:
	ldr r1, =0x040000b0
	ldrh r2, [r1, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r0, =0x00007fff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	ldrb r0, [r4, 0x14]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r4, 0x8]
	str r0, [r1, 0x4]
	ldr r0, [r4, 0xC]
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldr r0, [r4, 0x10]
	bl _call_via_r0
	ldrb r0, [r4, 0x14]
	movs r1, 0x1
	eors r0, r1
	strb r0, [r4, 0x14]
_080BA122:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BA0A8

	thumb_func_start sub_80BA134
sub_80BA134: @ 80BA134
	ldr r0, =gUnknown_02039B28
	ldr r2, [r0, 0x8]
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	ldr r1, =gUnknown_02038C28
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80BA134

	thumb_func_start sub_80BA154
sub_80BA154: @ 80BA154
	ldr r0, =gUnknown_02039B28
	ldr r2, [r0, 0x8]
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	ldr r1, =gUnknown_02038C28
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80BA154

	thumb_func_start task00_for_dp12
task00_for_dp12: @ 80BA174
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	movs r6, 0
	ldr r0, =gUnknown_02039B44
	ldrb r0, [r0]
	cmp r0, 0
	beq _080BA1A4
	mov r0, r12
	bl DestroyTask
	ldr r1, =gUnknown_02039B28
	movs r0, 0xFF
	strb r0, [r1, 0x18]
	b _080BA324
	.pool
_080BA1A4:
	ldr r1, =gTasks
	mov r0, r12
	lsls r2, r0, 2
	adds r0, r2, r0
	lsls r0, 3
	adds r3, r0, r1
	movs r4, 0x16
	ldrsh r0, [r3, r4]
	mov r10, r1
	mov r9, r2
	cmp r0, 0
	beq _080BA250
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	cmp r0, 0xE
	bhi _080BA250
	lsls r0, 2
	ldr r1, =_080BA1D8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BA1D8:
	.4byte _080BA214
	.4byte _080BA250
	.4byte _080BA21C
	.4byte _080BA250
	.4byte _080BA224
	.4byte _080BA250
	.4byte _080BA22C
	.4byte _080BA250
	.4byte _080BA234
	.4byte _080BA250
	.4byte _080BA23C
	.4byte _080BA250
	.4byte _080BA244
	.4byte _080BA250
	.4byte _080BA24C
_080BA214:
	ldr r0, =gBattle_BG0_X
	b _080BA24E
	.pool
_080BA21C:
	ldr r0, =gBattle_BG0_Y
	b _080BA24E
	.pool
_080BA224:
	ldr r0, =gBattle_BG1_X
	b _080BA24E
	.pool
_080BA22C:
	ldr r0, =gBattle_BG1_Y
	b _080BA24E
	.pool
_080BA234:
	ldr r0, =gBattle_BG2_X
	b _080BA24E
	.pool
_080BA23C:
	ldr r0, =gBattle_BG2_Y
	b _080BA24E
	.pool
_080BA244:
	ldr r0, =gBattle_BG3_X
	b _080BA24E
	.pool
_080BA24C:
	ldr r0, =gBattle_BG3_Y
_080BA24E:
	ldrh r6, [r0]
_080BA250:
	mov r0, r9
	add r0, r12
	lsls r0, 3
	mov r2, r10
	adds r1, r0, r2
	ldrh r2, [r1, 0x10]
	movs r3, 0x10
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _080BA2BC
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	movs r4, 0xE
	ldrsh r0, [r1, r4]
	movs r3, 0xA0
	lsls r3, 1
	adds r2, r0, r3
	movs r4, 0x8
	ldrsh r3, [r1, r4]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r3, r0
	bge _080BA324
	ldr r5, =gUnknown_02038C28
	ldr r0, =gUnknown_02039B28
	mov r8, r0
	adds r7, r1, 0
	lsls r0, r2, 1
	adds r4, r0, r5
_080BA28A:
	lsls r2, r3, 1
	mov r0, r8
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r5
	ldrh r0, [r4]
	adds r0, r6
	strh r0, [r2]
	adds r4, 0x2
	adds r3, 0x1
	movs r1, 0xA
	ldrsh r0, [r7, r1]
	cmp r3, r0
	blt _080BA28A
	b _080BA324
	.pool
_080BA2BC:
	ldrh r0, [r1, 0x12]
	strh r0, [r1, 0x10]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	movs r3, 0xA0
	lsls r3, 1
	adds r2, r0, r3
	movs r4, 0x8
	ldrsh r3, [r1, r4]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r3, r0
	bge _080BA304
	ldr r5, =gUnknown_02038C28
	adds r7, r1, 0
	lsls r0, r2, 1
	adds r4, r0, r5
	ldr r0, =gUnknown_02039B28
	mov r8, r0
_080BA2E2:
	lsls r2, r3, 1
	mov r0, r8
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r5
	ldrh r0, [r4]
	adds r0, r6
	strh r0, [r2]
	adds r4, 0x2
	adds r3, 0x1
	movs r1, 0xA
	ldrsh r0, [r7, r1]
	cmp r3, r0
	blt _080BA2E2
_080BA304:
	mov r0, r9
	add r0, r12
	lsls r0, 3
	mov r3, r10
	adds r2, r0, r3
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r4, 0xC
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bne _080BA324
	movs r0, 0
	strh r0, [r2, 0xE]
_080BA324:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_for_dp12

	thumb_func_start sub_80BA33C
sub_80BA33C: @ 80BA33C
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	movs r1, 0
	movs r2, 0
	ldr r0, =gSineTable
	mov r12, r0
_080BA350:
	lsls r0, r1, 1
	adds r3, r0, r6
	lsls r0, r2, 1
	add r0, r12
	movs r7, 0
	ldrsh r0, [r0, r7]
	muls r0, r4
	cmp r0, 0
	bge _080BA364
	adds r0, 0xFF
_080BA364:
	asrs r0, 8
	strh r0, [r3]
	adds r0, r2, r5
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xFF
	bls _080BA350
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BA33C

	thumb_func_start sub_80BA384
sub_80BA384: @ 80BA384
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r5, r0, 0
	str r1, [sp, 0x10]
	ldr r0, [sp, 0x40]
	mov r8, r0
	ldr r1, [sp, 0x44]
	mov r9, r1
	ldr r0, [sp, 0x48]
	mov r10, r0
	lsls r5, 24
	lsrs r5, 24
	ldr r1, [sp, 0x10]
	lsls r1, 24
	str r1, [sp, 0x14]
	lsrs r0, r1, 24
	str r0, [sp, 0xC]
	lsls r1, r2, 24
	lsrs r1, 24
	str r1, [sp, 0x18]
	lsls r2, r3, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	mov r3, r9
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl dp12_8087EA4
	ldr r0, =0x04000010
	add r0, r9
	str r0, [sp]
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =task00_for_dp12
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	strh r5, [r4, 0x8]
	mov r3, sp
	ldrh r3, [r3, 0xC]
	strh r3, [r4, 0xA]
	movs r0, 0x80
	lsls r0, 1
	ldr r1, [sp, 0x18]
	bl __divsi3
	strh r0, [r4, 0xC]
	movs r0, 0
	strh r0, [r4, 0xE]
	mov r1, r8
	strh r1, [r4, 0x10]
	strh r1, [r4, 0x12]
	mov r3, r9
	strh r3, [r4, 0x14]
	mov r0, r10
	strh r0, [r4, 0x16]
	ldr r0, =gUnknown_02039B28
	strb r7, [r0, 0x18]
	ldr r0, =gUnknown_02039B44
	movs r1, 0
	strb r1, [r0]
	ldr r4, =gUnknown_02038EA8
	ldr r3, [sp, 0xC]
	subs r6, r3, r5
	lsls r3, r6, 24
	lsrs r3, 24
	adds r0, r4, 0
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	bl sub_80BA33C
	ldr r0, [sp, 0xC]
	cmp r5, r0
	bge _080BA47E
	ldr r1, =0xfffffd80
	adds r2, r4, r1
	lsls r1, r5, 1
	movs r3, 0xF0
	lsls r3, 3
	adds r0, r1, r3
	adds r3, r0, r2
	adds r1, r2
	adds r2, r4, 0
	adds r5, r6, 0
_080BA46A:
	ldrh r0, [r2]
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bne _080BA46A
_080BA47E:
	adds r0, r7, 0
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BA384

	.align 2, 0 @ Don't pad with nop.
