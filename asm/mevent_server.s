	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text






	thumb_func_start mevent_srv_init_wnews
mevent_srv_init_wnews: @ 801D07C
	push {r4,lr}
	ldr r4, =gUnknown_02022C7C
	movs r0, 0x60
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gUnknown_082F298C
	movs r2, 0
	movs r3, 0x1
	bl mevent_srv_init_common
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mevent_srv_init_wnews

	thumb_func_start mevent_srv_new_wcard
mevent_srv_new_wcard: @ 801D0A0
	push {r4,lr}
	ldr r4, =gUnknown_02022C7C
	movs r0, 0x60
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gUnknown_082F29EC
	movs r2, 0
	movs r3, 0x1
	bl mevent_srv_init_common
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mevent_srv_new_wcard

	thumb_func_start sub_801D0C4
sub_801D0C4: @ 801D0C4
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =gUnknown_02022C7C
	ldr r0, [r4]
	cmp r0, 0
	bne _0801D0D8
	movs r0, 0x3
	b _0801D0F8
	.pool
_0801D0D8:
	bl mevent_dispatch_08145600
	adds r5, r0, 0
	cmp r5, 0x3
	bne _0801D0F6
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	strh r1, [r6]
	bl mevent_srv_free_resources
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801D0F6:
	adds r0, r5, 0
_0801D0F8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801D0C4

	thumb_func_start mevent_srv_init_common
mevent_srv_init_common: @ 801D100
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r9, r3
	movs r5, 0
	str r5, [r4]
	str r5, [r4, 0x8]
	movs r0, 0xA6
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4, 0x18]
	movs r0, 0xDE
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4, 0x1C]
	movs r0, 0x80
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4, 0x14]
	movs r0, 0x64
	bl AllocZeroed
	str r0, [r4, 0x20]
	str r6, [r4, 0x10]
	str r5, [r4, 0xC]
	adds r4, 0x38
	adds r0, r4, 0
	mov r1, r8
	mov r2, r9
	bl sub_801D8D8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_init_common

	thumb_func_start mevent_srv_free_resources
mevent_srv_free_resources: @ 801D158
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x18]
	bl Free
	ldr r0, [r4, 0x1C]
	bl Free
	ldr r0, [r4, 0x14]
	bl Free
	ldr r0, [r4, 0x20]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_free_resources

	thumb_func_start mevent_srv_814501C
mevent_srv_814501C: @ 801D17C
	push {lr}
	adds r0, 0x38
	bl sub_801D904
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_814501C

	thumb_func_start sub_801D188
sub_801D188: @ 801D188
	push {lr}
	cmp r0, 0
	bne _0801D190
	adds r0, r1, 0
_0801D190:
	pop {r1}
	bx r1
	thumb_func_end sub_801D188

	thumb_func_start sub_801D194
sub_801D194: @ 801D194
	push {lr}
	cmp r1, r0
	bcs _0801D19E
	movs r0, 0
	b _0801D1A8
_0801D19E:
	cmp r1, r0
	beq _0801D1A6
	movs r0, 0x2
	b _0801D1A8
_0801D1A6:
	movs r0, 0x1
_0801D1A8:
	pop {r1}
	bx r1
	thumb_func_end sub_801D194

	thumb_func_start sub_801D1AC
sub_801D1AC: @ 801D1AC
	movs r1, 0x4
	str r1, [r0, 0x8]
	movs r0, 0
	bx lr
	thumb_func_end sub_801D1AC

	thumb_func_start sub_801D1B4
sub_801D1B4: @ 801D1B4
	movs r0, 0x3
	bx lr
	thumb_func_end sub_801D1B4

	thumb_func_start sub_801D1B8
sub_801D1B8: @ 801D1B8
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x38
	bl sub_801D8C0
	cmp r0, 0
	beq _0801D1CA
	movs r0, 0x4
	str r0, [r4, 0x8]
_0801D1CA:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D1B8

	thumb_func_start sub_801D1D4
sub_801D1D4: @ 801D1D4
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x38
	bl sub_801D8CC
	cmp r0, 0
	beq _0801D1E6
	movs r0, 0x4
	str r0, [r4, 0x8]
_0801D1E6:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D1D4

	thumb_func_start sub_801D1F0
sub_801D1F0: @ 801D1F0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0xC]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r2, [r5, 0x10]
	adds r3, r2, r1
	adds r0, 0x1
	str r0, [r5, 0xC]
	ldr r0, [r3]
	cmp r0, 0x1E
	bls _0801D20C
	b _0801D464
_0801D20C:
	lsls r0, 2
	ldr r1, =_0801D21C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801D21C:
	.4byte _0801D298
	.4byte _0801D2A2
	.4byte _0801D2A8
	.4byte _0801D2E2
	.4byte _0801D2D8
	.4byte _0801D2BA
	.4byte _0801D2C6
	.4byte _0801D2EC
	.4byte _0801D300
	.4byte _0801D308
	.4byte _0801D31E
	.4byte _0801D32E
	.4byte _0801D33A
	.4byte _0801D360
	.4byte _0801D348
	.4byte _0801D390
	.4byte _0801D378
	.4byte _0801D3DC
	.4byte _0801D3A8
	.4byte _0801D3C0
	.4byte _0801D3CE
	.4byte _0801D406
	.4byte _0801D3EA
	.4byte _0801D3F8
	.4byte _0801D40E
	.4byte _0801D418
	.4byte _0801D422
	.4byte _0801D43C
	.4byte _0801D450
	.4byte _0801D458
	.4byte _0801D2CC
_0801D298:
	movs r0, 0x1
	str r0, [r5, 0x8]
	ldr r0, [r3, 0x4]
	str r0, [r5, 0x4]
	b _0801D464
_0801D2A2:
	movs r0, 0x3
	str r0, [r5, 0x8]
	b _0801D464
_0801D2A8:
	adds r0, r5, 0
	adds r0, 0x38
	ldr r1, [r3, 0x4]
	ldr r2, [r5, 0x14]
	bl sub_801D928
	movs r0, 0x2
	str r0, [r5, 0x8]
	b _0801D464
_0801D2BA:
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	movs r2, 0x64
	bl memcpy
	b _0801D464
_0801D2C6:
	ldr r0, [r5, 0x20]
	movs r1, 0
	b _0801D2D0
_0801D2CC:
	ldr r0, [r5, 0x20]
	movs r1, 0x1
_0801D2D0:
	bl sub_801B6A0
	str r0, [r5, 0x4]
	b _0801D464
_0801D2D8:
	ldr r1, [r5, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	beq _0801D2E2
	b _0801D464
_0801D2E2:
	movs r0, 0
	str r0, [r5, 0xC]
	ldr r0, [r3, 0x8]
	str r0, [r5, 0x10]
	b _0801D464
_0801D2EC:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x18]
	bl sub_801D188
	adds r2, r0, 0
	ldr r1, [r5, 0x20]
	bl sub_801B6EC
	str r0, [r5, 0x4]
	b _0801D464
_0801D300:
	ldr r0, [r5, 0x14]
	ldr r0, [r0]
	str r0, [r5, 0x4]
	b _0801D464
_0801D308:
	ldr r0, [r3, 0x8]
	adds r1, r5, 0
	adds r1, 0x34
	bl sub_801D188
	adds r2, r0, 0
	ldr r1, [r5, 0x20]
	bl sub_801B708
	str r0, [r5, 0x4]
	b _0801D464
_0801D31E:
	ldr r0, [r5, 0x20]
	ldr r1, [r3, 0x4]
	bl sub_801B784
	lsls r0, 16
	lsrs r0, 16
	str r0, [r5, 0x4]
	b _0801D464
_0801D32E:
	ldr r0, [r5, 0x20]
	ldr r1, [r3, 0x8]
	bl sub_801B748
	str r0, [r5, 0x4]
	b _0801D464
_0801D33A:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x14]
	ldr r1, [r1]
	bl sub_801D194
	str r0, [r5, 0x4]
	b _0801D464
_0801D348:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x1C]
	bl sub_801D188
	adds r2, r0, 0
	movs r3, 0xDE
	lsls r3, 1
	adds r0, r5, 0
	movs r1, 0x17
	bl mevent_srv_814501C
	b _0801D464
_0801D360:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x18]
	bl sub_801D188
	adds r2, r0, 0
	movs r3, 0xA6
	lsls r3, 1
	adds r0, r5, 0
	movs r1, 0x16
	bl mevent_srv_814501C
	b _0801D464
_0801D378:
	ldr r0, [r3, 0x8]
	adds r1, r5, 0
	adds r1, 0x34
	bl sub_801D188
	adds r2, r0, 0
	adds r0, r5, 0
	movs r1, 0x18
	movs r3, 0x4
	bl mevent_srv_814501C
	b _0801D464
_0801D390:
	ldr r2, [r3, 0x8]
	cmp r2, 0
	bne _0801D39C
	ldr r2, [r5, 0x24]
	ldr r3, [r5, 0x28]
	b _0801D39E
_0801D39C:
	ldr r3, [r3, 0x4]
_0801D39E:
	adds r0, r5, 0
	movs r1, 0x19
	bl mevent_srv_814501C
	b _0801D464
_0801D3A8:
	ldr r2, [r3, 0x8]
	cmp r2, 0
	bne _0801D3B4
	ldr r2, [r5, 0x2C]
	ldr r3, [r5, 0x30]
	b _0801D3B6
_0801D3B4:
	ldr r3, [r3, 0x4]
_0801D3B6:
	adds r0, r5, 0
	movs r1, 0x10
	bl mevent_srv_814501C
	b _0801D464
_0801D3C0:
	ldr r2, [r3, 0x8]
	adds r0, r5, 0
	movs r1, 0x1A
	movs r3, 0xBC
	bl mevent_srv_814501C
	b _0801D464
_0801D3CE:
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0x4]
	adds r0, r5, 0
	movs r1, 0x15
	bl mevent_srv_814501C
	b _0801D464
_0801D3DC:
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0x4]
	adds r0, r5, 0
	movs r1, 0x1C
	bl mevent_srv_814501C
	b _0801D464
_0801D3EA:
	ldr r0, [r5, 0x18]
	ldr r1, [r3, 0x8]
	movs r2, 0xA6
	lsls r2, 1
	bl memcpy
	b _0801D464
_0801D3F8:
	ldr r0, [r5, 0x1C]
	ldr r1, [r3, 0x8]
	movs r2, 0xDE
	lsls r2, 1
	bl memcpy
	b _0801D464
_0801D406:
	ldr r0, [r3, 0x8]
	ldr r0, [r0]
	str r0, [r5, 0x34]
	b _0801D464
_0801D40E:
	ldr r0, [r3, 0x8]
	str r0, [r5, 0x24]
	ldr r0, [r3, 0x4]
	str r0, [r5, 0x28]
	b _0801D464
_0801D418:
	ldr r0, [r3, 0x8]
	str r0, [r5, 0x2C]
	ldr r0, [r3, 0x4]
	str r0, [r5, 0x30]
	b _0801D464
_0801D422:
	ldr r4, [r5, 0x18]
	bl sav1_get_mevent_buffer_1
	adds r1, r0, 0
	movs r2, 0xA6
	lsls r2, 1
	adds r0, r4, 0
	bl memcpy
	ldr r0, [r5, 0x18]
	bl sub_801B3C0
	b _0801D464
_0801D43C:
	ldr r4, [r5, 0x1C]
	bl sub_801B00C
	adds r1, r0, 0
	movs r2, 0xDE
	lsls r2, 1
	adds r0, r4, 0
	bl memcpy
	b _0801D464
_0801D450:
	bl sub_8099244
	str r0, [r5, 0x24]
	b _0801D464
_0801D458:
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0x4]
	adds r0, r5, 0
	movs r1, 0x1B
	bl mevent_srv_814501C
_0801D464:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801D1F0

	thumb_func_start mevent_dispatch_08145600
mevent_dispatch_08145600: @ 801D46C
	push {lr}
	ldr r2, =gUnknown_082F2548
	ldr r1, [r0, 0x8]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end mevent_dispatch_08145600

	.align 2, 0 @ don't pad with nop
