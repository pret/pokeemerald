	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8145EF4
sub_8145EF4: @ 8145EF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x030022c0
	ldr r1, =sub_8085E50
	str r1, [r2, 0x4]
	bl sub_8145F6C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145EF4

	thumb_func_start sub_8145F10
sub_8145F10: @ 8145F10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8145F6C
	pop {r0}
	bx r0
	thumb_func_end sub_8145F10

	thumb_func_start sub_8145F20
sub_8145F20: @ 8145F20
	push {r4,lr}
	ldr r0, =sub_8145FA8
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08145F4C
	movs r0, 0
	b _08145F60
	.pool
_08145F4C:
	adds r0, r2, 0
	bl DestroyTask
	ldr r4, =0x0203aba0
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	movs r0, 0x1
_08145F60:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8145F20

	thumb_func_start sub_8145F6C
sub_8145F6C: @ 8145F6C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_8145FA8
	movs r1, 0x2
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xA]
	ldr r4, =0x0203aba0
	movs r0, 0x3C
	bl AllocZeroed
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145F6C

	thumb_func_start sub_8145FA8
sub_8145FA8: @ 8145FA8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8A98
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08145FBA:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08145FBA
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145FA8

	thumb_func_start sub_8145FE0
sub_8145FE0: @ 8145FE0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80AC3D0
	ldr r0, =0x02037b14
	ldr r1, =0x02037714
	ldr r2, =0x04000100
	bl CpuSet
	ldr r1, =gUnknown_085C8948
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0814601C
	movs r0, 0x2
	strh r0, [r4, 0x8]
	movs r0, 0x1
	b _0814602A
	.pool
_0814601C:
	movs r1, 0x4
	bl CreateTask
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
_0814602A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8145FE0

	thumb_func_start sub_8146030
sub_8146030: @ 8146030
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_085C8948
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08146054
	movs r0, 0
	b _0814605C
	.pool
_08146054:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
_0814605C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8146030

	thumb_func_start sub_8146064
sub_8146064: @ 8146064
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_085C89F0
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl CreateTask
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146064

	thumb_func_start sub_814608C
sub_814608C: @ 814608C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	strh r0, [r4, 0x26]
	ldr r1, =gUnknown_085C89F0
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _081460B0
	movs r0, 0x1
	strh r0, [r4, 0x26]
_081460B0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814608C

	thumb_func_start sub_81460BC
sub_81460BC: @ 81460BC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0x8]
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _081460F4
	adds r0, r2, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x2
	bl sub_8149D78
	b _08146104
	.pool
_081460F4:
	bl sub_8149DDC
	lsls r0, 24
	cmp r0, 0
	beq _08146104
	adds r0, r4, 0
	bl DestroyTask
_08146104:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81460BC

	thumb_func_start sub_814610C
sub_814610C: @ 814610C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8AA8
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814611E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814611E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814610C

	thumb_func_start sub_8146144
sub_8146144: @ 8146144
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0x40
	bl SetGpuRegBits
	movs r0, 0xC
	movs r1, 0x40
	bl SetGpuRegBits
	movs r0, 0xE
	movs r1, 0x40
	bl SetGpuRegBits
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8146144

	thumb_func_start sub_8146178
sub_8146178: @ 8146178
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	movs r1, 0xA
	ldrsh r2, [r4, r1]
	cmp r2, 0
	beq _0814618E
	subs r0, 0x1
	strh r0, [r4, 0xA]
	b _081461CE
_0814618E:
	movs r0, 0x4
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _081461B0
	movs r1, 0x1
	negs r1, r1
	str r2, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
_081461B0:
	ldrh r1, [r4, 0xC]
	movs r0, 0xF
	ands r0, r1
	lsls r1, r0, 4
	orrs r1, r0
	movs r0, 0x4C
	bl SetGpuReg
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0xE
	ble _081461CE
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081461CE:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8146178

	thumb_func_start sub_81461D8
sub_81461D8: @ 81461D8
	push {lr}
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081461F4
	ldr r0, =sub_814610C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081461F4:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81461D8

	thumb_func_start sub_8146204
sub_8146204: @ 8146204
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8AB4
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146216:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146216
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146204

	thumb_func_start sub_814623C
sub_814623C: @ 814623C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	ldr r0, =0x020393a8
	ldr r1, =0x0203aba0
	ldr r1, [r1]
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	str r4, [sp]
	movs r2, 0xA0
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0x2
	bl sub_8149F98
	ldr r0, =sub_8146320
	bl SetVBlankCallback
	ldr r0, =sub_8146358
	bl SetHBlankCallback
	movs r0, 0x3
	bl EnableInterrupts
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814623C

	thumb_func_start sub_81462A8
sub_81462A8: @ 81462A8
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r4, =0x0203aba0
	ldr r2, [r4]
	ldrb r1, [r2]
	movs r1, 0
	strb r1, [r2]
	ldrh r1, [r0, 0xA]
	adds r1, 0x4
	strh r1, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	adds r1, 0x8
	strh r1, [r0, 0xC]
	ldr r3, =0x02038c28
	ldr r1, [r4]
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	movs r5, 0xA
	ldrsh r2, [r0, r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	str r0, [sp]
	movs r0, 0xA0
	str r0, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x2
	bl sub_8149F98
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081462FA
	ldr r0, =sub_8146204
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081462FA:
	ldr r0, [r4]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81462A8

	thumb_func_start sub_8146320
sub_8146320: @ 8146320
	push {lr}
	bl sub_8149F2C
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08146344
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08146344:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146320

	thumb_func_start sub_8146358
sub_8146358: @ 8146358
	ldr r1, =0x02038c28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000014
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8146358

	thumb_func_start sub_8146384
sub_8146384: @ 8146384
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8ABC
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146396:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146396
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146384

	thumb_func_start sub_81463BC
sub_81463BC: @ 81463BC
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldr r0, =0x020393a8
	movs r2, 0x16
	ldrsh r1, [r1, r2]
	movs r2, 0xA0
	lsls r2, 1
	bl memset
	ldr r0, =sub_81464B0
	bl SetVBlankCallback
	ldr r0, =sub_81464E8
	bl SetHBlankCallback
	movs r0, 0x3
	bl EnableInterrupts
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81463BC

	thumb_func_start sub_8146420
sub_8146420: @ 8146420
	push {r4-r7,lr}
	ldr r1, =0x0203aba0
	ldr r2, [r1]
	ldrb r1, [r2]
	movs r1, 0
	strb r1, [r2]
	ldrh r4, [r0, 0xA]
	ldrh r2, [r0, 0xC]
	lsls r3, r2, 16
	asrs r3, 24
	movs r5, 0x84
	lsls r5, 5
	adds r1, r4, r5
	strh r1, [r0, 0xA]
	movs r1, 0xC0
	lsls r1, 1
	adds r2, r1
	strh r2, [r0, 0xC]
	movs r5, 0
	lsls r7, r3, 16
_08146448:
	lsrs r0, r4, 8
	asrs r1, r7, 16
	bl sine
	ldr r1, =0x02038c28
	lsls r2, r5, 1
	adds r2, r1
	ldr r6, =0x0203aba0
	ldr r1, [r6]
	ldrh r1, [r1, 0x16]
	adds r0, r1
	strh r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x84
	lsls r1, 5
	adds r0, r4, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r5, 0x9F
	bls _08146448
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814648E
	ldr r0, =sub_8146384
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0814648E:
	ldr r0, [r6]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146420

	thumb_func_start sub_81464B0
sub_81464B0: @ 81464B0
	push {lr}
	bl sub_8149F2C
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _081464D4
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_081464D4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81464B0

	thumb_func_start sub_81464E8
sub_81464E8: @ 81464E8
	ldr r1, =0x02038c28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000016
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81464E8

	thumb_func_start sub_8146514
sub_8146514: @ 8146514
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8AFC
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146526:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146526
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146514

	thumb_func_start sub_814654C
sub_814654C: @ 814654C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8AC4
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814655E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814655E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814654C

	thumb_func_start sub_8146584
sub_8146584: @ 8146584
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8AE0
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146596:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146596
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146584

	thumb_func_start sub_81465BC
sub_81465BC: @ 81465BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8B14
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081465CE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081465CE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81465BC

	thumb_func_start sub_81465F4
sub_81465F4: @ 81465F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8B2C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146606:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146606
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81465F4

	thumb_func_start sub_814662C
sub_814662C: @ 814662C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8B44
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814663E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814663E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814662C

	thumb_func_start sub_8146664
sub_8146664: @ 8146664
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8B5C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146676:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146676
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146664

	thumb_func_start sub_814669C
sub_814669C: @ 814669C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r1, 0
	movs r0, 0x10
	strh r0, [r4, 0xA]
	strh r1, [r4, 0xC]
	strh r1, [r4, 0x10]
	movs r0, 0x80
	lsls r0, 7
	strh r0, [r4, 0x12]
	ldr r0, =0x0203aba0
	ldr r2, [r0]
	movs r0, 0x3F
	strh r0, [r2, 0x2]
	strh r1, [r2, 0x4]
	movs r0, 0xF0
	strh r0, [r2, 0x6]
	movs r0, 0xA0
	strh r0, [r2, 0x8]
	ldr r0, =0x00003f41
	strh r0, [r2, 0xE]
	ldrh r0, [r4, 0xA]
	lsls r0, 8
	ldrh r1, [r4, 0xC]
	orrs r0, r1
	strh r0, [r2, 0x10]
	ldr r0, =0x02038c28
	movs r2, 0xF0
	movs r1, 0x9F
	ldr r3, =0x000008be
	adds r0, r3
_081466E2:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _081466E2
	ldr r0, =sub_8146F3C
	bl SetVBlankCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814669C

	thumb_func_start sub_814670C
sub_814670C: @ 814670C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0x3C
	strh r0, [r4, 0x18]
	adds r0, r4, 0
	bl sub_814669C
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r0, sp
	strh r5, [r0]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	bl CpuSet
	ldr r0, =gUnknown_085BAED0
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085BAEB0
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814670C

	thumb_func_start sub_8146760
sub_8146760: @ 8146760
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0x3C
	strh r0, [r4, 0x18]
	adds r0, r4, 0
	bl sub_814669C
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r0, sp
	strh r5, [r0]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	bl CpuSet
	ldr r0, =gUnknown_085BB4A4
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085BAEB0
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146760

	thumb_func_start sub_81467B4
sub_81467B4: @ 81467B4
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0x3C
	strh r0, [r4, 0x18]
	adds r0, r4, 0
	bl sub_814669C
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r0, sp
	strh r5, [r0]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	bl CpuSet
	ldr r0, =gUnknown_085BBC14
	ldr r1, [sp, 0x8]
	movs r2, 0x80
	lsls r2, 5
	bl CpuSet
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81467B4

	thumb_func_start sub_8146800
sub_8146800: @ 8146800
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_814669C
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085B9330
	ldr r1, [sp, 0x8]
	movs r2, 0xB0
	lsls r2, 2
	bl CpuSet
	ldr r0, =gFieldEffectObjectPalette10
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146800

	thumb_func_start sub_8146854
sub_8146854: @ 8146854
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r7, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r5, =gUnknown_085C9020
	movs r1, 0
	ldr r0, [sp, 0x8]
	mov r9, r0
	ldr r6, =0x02038c28
	mov r8, r6
	movs r0, 0xF0
	lsls r0, 8
	mov r12, r0
_0814687A:
	movs r0, 0
	lsls r3, r1, 16
	asrs r4, r3, 11
_08146880:
	lsls r2, r0, 16
	asrs r2, 16
	adds r1, r4, r2
	lsls r1, 1
	add r1, r9
	ldrh r0, [r5]
	mov r6, r12
	orrs r0, r6
	strh r0, [r1]
	adds r2, 0x1
	lsls r2, 16
	adds r5, 0x2
	lsrs r0, r2, 16
	asrs r2, 16
	cmp r2, 0x1D
	ble _08146880
	movs r1, 0x80
	lsls r1, 9
	adds r0, r3, r1
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0814687A
	movs r6, 0x10
	ldrsh r2, [r7, r6]
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, 0xA0
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
	movs r0, 0x1
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146854

	thumb_func_start sub_81468E4
sub_81468E4: @ 81468E4
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085BB248
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =0x02038c28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81468E4

	thumb_func_start sub_814692C
sub_814692C: @ 814692C
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085BB930
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =0x02038c28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814692C

	thumb_func_start sub_8146974
sub_8146974: @ 8146974
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085BC2B4
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r0, =gUnknown_085BC314
	ldr r1, [sp, 0x8]
	movs r2, 0xA0
	lsls r2, 2
	bl CpuSet
	ldr r0, =0x02038c28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146974

	thumb_func_start sub_81469CC
sub_81469CC: @ 81469CC
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085BC2D4
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r0, =gUnknown_085BCB14
	ldr r1, [sp, 0x8]
	movs r2, 0xA0
	lsls r2, 2
	bl CpuSet
	ldr r0, =0x02038c28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81469CC

	thumb_func_start sub_8146A24
sub_8146A24: @ 8146A24
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085BC2F4
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r0, =gUnknown_085BD314
	ldr r1, [sp, 0x8]
	movs r2, 0xA0
	lsls r2, 2
	bl CpuSet
	ldr r0, =0x02038c28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146A24

	thumb_func_start sub_8146A7C
sub_8146A7C: @ 8146A7C
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085BDB34
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085BE1E8
	ldr r1, [sp, 0x4]
	bl LZ77UnCompVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146A7C

	thumb_func_start sub_8146AC8
sub_8146AC8: @ 8146AC8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	adds r0, r5, 0
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08146B00
	adds r0, r5, 0
	movs r1, 0x1E
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 11
	ldr r1, =gUnknown_085BEDA0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
_08146B00:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3A
	ble _08146B18
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0xA]
_08146B18:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146AC8

	thumb_func_start sub_8146B24
sub_8146B24: @ 8146B24
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	adds r0, r5, 0
	movs r1, 0x5
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08146B52
	adds r0, r5, 0
	movs r1, 0x5
	bl __divsi3
	lsls r0, 16
	asrs r0, 11
	ldr r1, =gUnknown_085BEEE0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
_08146B52:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x44
	ble _08146B6E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0xA]
	movs r0, 0x1E
	strh r0, [r4, 0x18]
_08146B6E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146B24

	thumb_func_start sub_8146B7C
sub_8146B7C: @ 8146B7C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =0xffff8000
	movs r1, 0
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146B7C

	thumb_func_start sub_8146BA8
sub_8146BA8: @ 8146BA8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08146BDE
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
	bl sub_8149F84
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_08146BDE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146BA8

	thumb_func_start sub_8146BF8
sub_8146BF8: @ 8146BF8
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r1, [r3, 0xE]
	movs r4, 0xE
	ldrsh r0, [r3, r4]
	adds r4, r2, 0
	cmp r0, 0
	beq _08146C1E
	subs r0, r1, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08146C28
_08146C1E:
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	movs r0, 0x2
	strh r0, [r3, 0xE]
_08146C28:
	ldr r2, [r4]
	ldrh r0, [r3, 0xA]
	lsls r0, 8
	ldrh r1, [r3, 0xC]
	orrs r0, r1
	strh r0, [r2, 0x10]
	movs r5, 0xC
	ldrsh r0, [r3, r5]
	cmp r0, 0xF
	ble _08146C42
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_08146C42:
	ldrh r0, [r3, 0x10]
	adds r0, 0x8
	strh r0, [r3, 0x10]
	ldr r0, =0xffffff00
	adds r1, r0, 0
	ldrh r5, [r3, 0x12]
	adds r1, r5
	strh r1, [r3, 0x12]
	ldr r0, =0x02038c28
	movs r5, 0x10
	ldrsh r2, [r3, r5]
	lsls r1, 16
	asrs r1, 24
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146BF8

	thumb_func_start sub_8146C8C
sub_8146C8C: @ 8146C8C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r1, [r3, 0xE]
	movs r4, 0xE
	ldrsh r0, [r3, r4]
	adds r4, r2, 0
	cmp r0, 0
	beq _08146CB2
	subs r0, r1, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08146CBC
_08146CB2:
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
	strh r0, [r3, 0xA]
	movs r0, 0x2
	strh r0, [r3, 0xE]
_08146CBC:
	ldr r2, [r4]
	ldrh r0, [r3, 0xA]
	lsls r0, 8
	ldrh r1, [r3, 0xC]
	orrs r0, r1
	strh r0, [r2, 0x10]
	movs r5, 0xA
	ldrsh r0, [r3, r5]
	cmp r0, 0
	bne _08146CD6
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_08146CD6:
	ldrh r0, [r3, 0x10]
	adds r0, 0x8
	strh r0, [r3, 0x10]
	ldr r0, =0xffffff00
	adds r1, r0, 0
	ldrh r5, [r3, 0x12]
	adds r1, r5
	strh r1, [r3, 0x12]
	ldr r0, =0x02038c28
	movs r5, 0x10
	ldrsh r2, [r3, r5]
	lsls r1, 16
	asrs r1, 24
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146C8C

	thumb_func_start sub_8146D20
sub_8146D20: @ 8146D20
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r7, =0x0203aba0
	ldr r0, [r7]
	ldrb r1, [r0]
	movs r6, 0
	strb r6, [r0]
	ldrh r0, [r4, 0x10]
	adds r0, 0x8
	strh r0, [r4, 0x10]
	ldr r0, =0xffffff00
	adds r1, r0, 0
	ldrh r3, [r4, 0x12]
	adds r1, r3
	strh r1, [r4, 0x12]
	ldr r0, =0x02038c28
	movs r3, 0x10
	ldrsh r2, [r4, r3]
	lsls r1, 16
	asrs r1, 24
	str r1, [sp]
	movs r5, 0xA0
	str r5, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _08146D70
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	strh r5, [r4, 0xA]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0xC]
	strh r6, [r4, 0xE]
_08146D70:
	ldr r0, [r7]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146D20

	thumb_func_start sub_8146D90
sub_8146D90: @ 8146D90
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x18]
	subs r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	cmp r0, 0
	bne _08146DA6
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_08146DA6:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8146D90

	thumb_func_start sub_8146DAC
sub_8146DAC: @ 8146DAC
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =0x0000ffff
	movs r1, 0
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146DAC

	thumb_func_start sub_8146DD8
sub_8146DD8: @ 8146DD8
	push {lr}
	adds r2, r0, 0
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08146DEE
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_08146DEE:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146DD8

	thumb_func_start sub_8146DF8
sub_8146DF8: @ 8146DF8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r3, 0
	strb r3, [r0]
	ldrh r2, [r4, 0xC]
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	ldr r0, =0x000003ff
	cmp r1, r0
	bgt _08146E18
	adds r0, r2, 0
	adds r0, 0x80
	strh r0, [r4, 0xC]
_08146E18:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08146E34
	ldrh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 24
	subs r0, r1, r0
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bge _08146E34
	strh r3, [r4, 0xA]
_08146E34:
	ldr r0, =0x02038c28
	movs r1, 0xA
	ldrsh r3, [r4, r1]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A014
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08146E90
	movs r0, 0
	bl SetVBlankCallback
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
	bl sub_8149F84
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _08146EB0
	.pool
_08146E90:
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08146EA4
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
	ldr r0, =sub_8146F68
	bl SetVBlankCallback
_08146EA4:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
_08146EB0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146DF8

	thumb_func_start sub_8146EC0
sub_8146EC0: @ 8146EC0
	push {lr}
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
	bl sub_8149F2C
	ldr r2, =0x0203aba0
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08146EF8
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r3, 0xF0
	lsls r3, 3
	adds r0, r3
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08146EF8:
	ldr r1, =0x04000048
	ldr r2, [r2]
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x4]
	strh r0, [r1]
	subs r1, 0x6
	ldrh r0, [r2, 0x8]
	strh r0, [r1]
	adds r1, 0xC
	ldrh r0, [r2, 0xE]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x10]
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146EC0

	thumb_func_start sub_8146F3C
sub_8146F3C: @ 8146F3C
	push {lr}
	bl sub_8146EC0
	ldr r1, =0x040000b0
	ldr r0, =0x020393a8
	str r0, [r1]
	ldr r0, =0x04000010
	str r0, [r1, 0x4]
	ldr r0, =0xa2400001
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146F3C

	thumb_func_start sub_8146F68
sub_8146F68: @ 8146F68
	push {lr}
	bl sub_8146EC0
	ldr r1, =0x040000b0
	ldr r0, =0x020393a8
	str r0, [r1]
	ldr r0, =0x04000040
	str r0, [r1, 0x4]
	ldr r0, =0xa2400001
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146F68

	thumb_func_start sub_8146F94
sub_8146F94: @ 8146F94
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8B7C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08146FA6:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08146FA6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8146F94

	thumb_func_start sub_8146FCC
sub_8146FCC: @ 8146FCC
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085B98B0
	ldr r1, [sp, 0x8]
	movs r2, 0x20
	bl CpuSet
	movs r0, 0
	str r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	ldr r0, =gFieldEffectObjectPalette10
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8146FCC

	thumb_func_start sub_8147018
sub_8147018: @ 8147018
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r7, r0, 0
	ldr r1, =gUnknown_085C8B88
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	add r4, sp, 0x4
	ldr r1, =gUnknown_085C8B8C
	adds r0, r4, 0
	movs r2, 0xA
	bl memcpy
	bl GenerateRandomNumber
	movs r5, 0x1
	ands r5, r0
	movs r1, 0
	mov r8, r4
	ldr r6, =0x02038c08
_08147046:
	lsls r5, 16
	asrs r5, 16
	lsls r0, r5, 1
	add r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	str r0, [r6]
	lsls r4, r1, 16
	asrs r4, 16
	lsls r0, r4, 5
	adds r0, 0x10
	str r0, [r6, 0x4]
	str r5, [r6, 0x8]
	lsls r0, r4, 1
	add r0, r8
	movs r1, 0
	ldrsh r0, [r0, r1]
	str r0, [r6, 0xC]
	movs r0, 0x2D
	bl FieldEffectStart
	adds r4, 0x1
	lsls r4, 16
	movs r0, 0x1
	eors r5, r0
	lsls r5, 16
	lsrs r5, 16
	lsrs r1, r4, 16
	asrs r4, 16
	cmp r4, 0x4
	ble _08147046
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147018

	thumb_func_start sub_81470A4
sub_81470A4: @ 81470A4
	push {lr}
	movs r0, 0x2D
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _081470C4
	bl sub_8149F84
	ldr r0, =sub_8146F94
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081470C4:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81470A4

	thumb_func_start sub_81470D0
sub_81470D0: @ 81470D0
	push {r4,r5,lr}
	ldr r0, =gUnknown_085C8E68
	ldr r5, =0x02038c08
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r3, 0x4
	ldrsh r2, [r5, r3]
	movs r3, 0
	bl AddObjectToBack
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x02020630
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r4, r1
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x5]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, [r5, 0x8]
	strh r0, [r4, 0x2E]
	ldr r0, [r5, 0xC]
	strh r0, [r4, 0x30]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl obj_alloc_rotscale_entry
	ldrb r1, [r5, 0x8]
	adds r0, r4, 0
	bl StartObjectRotScalAnim
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81470D0

	thumb_func_start sub_814713C
sub_814713C: @ 814713C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_085C8B96
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08147160
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	b _081471F2
	.pool
_08147160:
	ldrh r0, [r4, 0x20]
	lsls r1, r0, 16
	lsrs r0, r1, 16
	cmp r0, 0xF0
	bhi _081471CE
	asrs r0, r1, 19
	lsls r0, 16
	ldrh r1, [r4, 0x22]
	lsls r1, 16
	asrs r1, 19
	lsls r1, 16
	lsrs r1, 16
	lsrs r2, r0, 16
	asrs r5, r0, 16
	movs r3, 0x32
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _081471CE
	strh r2, [r4, 0x32]
	ldr r0, =0x04000008
	ldrh r2, [r0]
	lsrs r2, 8
	movs r0, 0x1F
	ands r2, r0
	lsls r2, 11
	movs r0, 0xC0
	lsls r0, 19
	adds r2, r0
	lsls r1, 16
	asrs r1, 16
	subs r0, r1, 0x2
	lsls r0, 5
	adds r0, r5
	lsls r0, 1
	adds r0, r2
	ldr r6, =0x0000f001
	adds r3, r6, 0
	strh r3, [r0]
	subs r0, r1, 0x1
	lsls r0, 5
	adds r0, r5
	lsls r0, 1
	adds r0, r2
	strh r3, [r0]
	lsls r0, r1, 5
	adds r0, r5
	lsls r0, 1
	adds r0, r2
	strh r3, [r0]
	adds r1, 0x1
	lsls r1, 5
	adds r1, r5
	lsls r1, 1
	adds r1, r2
	strh r3, [r1]
_081471CE:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	adds r0, 0xF
	lsls r0, 16
	movs r1, 0x87
	lsls r1, 17
	cmp r0, r1
	bls _081471F2
	adds r0, r4, 0
	movs r1, 0x2D
	bl FieldEffectStop
_081471F2:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814713C

	thumb_func_start sub_8147204
sub_8147204: @ 8147204
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8B9C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08147216:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08147216
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147204

	thumb_func_start sub_814723C
sub_814723C: @ 814723C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x2]
	movs r0, 0x3F
	strh r0, [r1, 0x4]
	ldr r0, =0x0000f0f1
	strh r0, [r1, 0x6]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r3, =0x020393a8
	ldr r2, =0x0000f3f4
_08147262:
	lsls r0, r1, 1
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _08147262
	ldr r0, =sub_8147688
	bl SetVBlankCallback
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0x78
	strh r0, [r1, 0x2C]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814723C

	thumb_func_start sub_81472A4
sub_81472A4: @ 81472A4
	push {r4-r7,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x24
	movs r2, 0x2C
	ldrsh r3, [r1, r2]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A1AC
	ldr r5, =0x02038c28
_081472D4:
	ldr r4, =0x0203aba0
	ldr r0, [r4]
	movs r7, 0x2A
	ldrsh r3, [r0, r7]
	lsls r3, 1
	adds r3, r5
	ldrh r1, [r0, 0x28]
	adds r1, 0x1
	movs r7, 0xF0
	lsls r7, 7
	adds r2, r7, 0
	orrs r1, r2
	strh r1, [r3]
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	lsls r0, 24
	cmp r0, 0
	beq _081472D4
	ldr r1, [r4]
	ldrh r0, [r1, 0x2C]
	adds r0, 0x10
	strh r0, [r1, 0x2C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xEF
	ble _08147318
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_08147318:
	ldr r0, [r4]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81472A4

	thumb_func_start sub_8147334
sub_8147334: @ 8147334
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	add r1, sp, 0xC
	movs r0, 0
	strb r0, [r1]
	ldr r4, =0x0203aba0
	ldr r1, [r4]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	movs r2, 0x2E
	ldrsh r1, [r1, r2]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0xF0
	bl sub_814A1AC
	mov r9, r4
	mov r7, r9
	add r5, sp, 0xC
_08147372:
	movs r1, 0x78
	ldr r3, [r7]
	ldrh r0, [r3, 0x28]
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	movs r2, 0x2E
	ldrsh r0, [r3, r2]
	cmp r0, 0x4F
	ble _0814738A
	ldrh r1, [r3, 0x28]
	movs r4, 0xF0
_0814738A:
	ldr r6, =0x02038c28
	movs r0, 0x2A
	ldrsh r2, [r3, r0]
	lsls r2, 1
	adds r2, r6
	lsls r1, 16
	asrs r1, 8
	lsls r0, r4, 16
	asrs r4, r0, 16
	orrs r4, r1
	strh r4, [r2]
	ldrb r0, [r5]
	cmp r0, 0
	bne _081473C0
	adds r0, r3, 0
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	strb r0, [r5]
	b _08147372
	.pool
_081473C0:
	ldr r1, [r7]
	ldrh r0, [r1, 0x2E]
	adds r0, 0x8
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0x9F
	ble _081473DE
	movs r0, 0xF0
	strh r0, [r1, 0x2C]
	mov r1, r8
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08147406
_081473DE:
	movs r3, 0x2A
	ldrsh r0, [r1, r3]
	cmp r0, r2
	bge _08147406
	adds r3, r4, 0
	ldr r5, =0x0203aba0
_081473EA:
	ldr r2, [r5]
	ldrh r0, [r2, 0x2A]
	adds r0, 0x1
	strh r0, [r2, 0x2A]
	lsls r0, 16
	asrs r0, 15
	adds r0, r6
	strh r3, [r0]
	movs r4, 0x2A
	ldrsh r1, [r2, r4]
	movs r4, 0x2E
	ldrsh r0, [r2, r4]
	cmp r1, r0
	blt _081473EA
_08147406:
	mov r1, r9
	ldr r0, [r1]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147334

	thumb_func_start sub_8147428
sub_8147428: @ 8147428
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x24
	movs r2, 0x2C
	ldrsh r3, [r1, r2]
	movs r1, 0xA0
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A1AC
	ldr r5, =0x02038c28
_08147456:
	ldr r4, =0x0203aba0
	ldr r0, [r4]
	movs r1, 0x2A
	ldrsh r3, [r0, r1]
	lsls r3, 1
	adds r3, r5
	ldrh r1, [r0, 0x28]
	lsls r1, 8
	movs r2, 0xF0
	orrs r1, r2
	strh r1, [r3]
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	lsls r0, 24
	cmp r0, 0
	beq _08147456
	ldr r1, [r4]
	ldrh r0, [r1, 0x2C]
	subs r0, 0x10
	strh r0, [r1, 0x2C]
	lsls r0, 16
	cmp r0, 0
	bgt _08147494
	movs r0, 0xA0
	strh r0, [r1, 0x2E]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_08147494:
	ldr r0, [r4]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147428

	thumb_func_start sub_81474B0
sub_81474B0: @ 81474B0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r0
	add r1, sp, 0xC
	movs r0, 0
	strb r0, [r1]
	ldr r4, =0x0203aba0
	ldr r1, [r4]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	movs r2, 0x2E
	ldrsh r1, [r1, r2]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl sub_814A1AC
	ldr r7, =0x02038c28
	mov r10, r7
	ldr r0, =0x0203aba0
	mov r8, r0
	add r6, sp, 0xC
_081474F4:
	mov r1, r8
	ldr r4, [r1]
	movs r2, 0x2A
	ldrsh r0, [r4, r2]
	lsls r0, 1
	mov r7, r10
	adds r5, r0, r7
	ldrb r1, [r5]
	ldrh r2, [r4, 0x28]
	adds r3, r2, 0
	movs r7, 0x2E
	ldrsh r0, [r4, r7]
	cmp r0, 0x50
	bgt _08147514
	movs r2, 0x78
	adds r1, r3, 0
_08147514:
	lsls r0, r2, 16
	asrs r0, 8
	lsls r1, 16
	asrs r1, 16
	orrs r1, r0
	movs r7, 0
	strh r1, [r5]
	ldrb r0, [r6]
	cmp r0, 0
	bne _08147540
	adds r0, r4, 0
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	strb r0, [r6]
	b _081474F4
	.pool
_08147540:
	mov r0, r8
	ldr r2, [r0]
	ldrh r0, [r2, 0x2E]
	subs r0, 0x8
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	bgt _0814755E
	strh r7, [r2, 0x2C]
	mov r1, r9
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08147588
_0814755E:
	movs r4, 0x2A
	ldrsh r0, [r2, r4]
	cmp r0, r3
	ble _08147588
	ldr r6, =0x02038c28
	adds r3, r1, 0
	ldr r5, =0x0203aba0
_0814756C:
	ldr r2, [r5]
	ldrh r0, [r2, 0x2A]
	subs r0, 0x1
	strh r0, [r2, 0x2A]
	lsls r0, 16
	asrs r0, 15
	adds r0, r6
	strh r3, [r0]
	movs r7, 0x2A
	ldrsh r1, [r2, r7]
	movs r4, 0x2E
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bgt _0814756C
_08147588:
	ldr r7, =0x0203aba0
	ldr r0, [r7]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81474B0

	thumb_func_start sub_81475B0
sub_81475B0: @ 81475B0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	ldr r1, =0x0203aba0
	ldr r0, [r1]
	ldrb r2, [r0]
	movs r2, 0
	strb r2, [r0]
	ldr r1, [r1]
	adds r0, r1, 0
	adds r0, 0x24
	movs r4, 0x2C
	ldrsh r3, [r1, r4]
	str r2, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A1AC
	ldr r6, =0x02038c28
_081475DC:
	movs r2, 0x78
	ldr r5, =0x0203aba0
	ldr r3, [r5]
	ldrh r4, [r3, 0x28]
	movs r1, 0x28
	ldrsh r0, [r3, r1]
	cmp r0, 0x77
	ble _081475F0
	movs r2, 0
	movs r4, 0xF0
_081475F0:
	movs r0, 0x2A
	ldrsh r1, [r3, r0]
	lsls r1, 1
	adds r1, r6
	lsls r2, 8
	lsls r0, r4, 16
	asrs r0, 16
	orrs r0, r2
	strh r0, [r1]
	adds r0, r3, 0
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	lsls r0, 24
	cmp r0, 0
	beq _081475DC
	ldr r0, [r5]
	ldrh r1, [r0, 0x2C]
	adds r1, 0x10
	strh r1, [r0, 0x2C]
	movs r1, 0x28
	ldrsh r0, [r0, r1]
	cmp r0, 0x78
	ble _0814762A
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
_0814762A:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81475B0

	thumb_func_start sub_8147648
sub_8147648: @ 8147648
	push {lr}
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
	bl sub_8149F84
	ldr r0, =sub_8147204
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147648

	thumb_func_start sub_8147688
sub_8147688: @ 8147688
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r3, =0x0203aba0
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r0, 0
	beq _081476C0
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_081476C0:
	ldr r2, =0x04000048
	ldr r1, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	subs r2, 0x4
	ldr r0, =0x02038c28
	movs r1, 0xF0
	lsls r1, 3
	adds r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	str r0, [r4]
	str r2, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147688

	thumb_func_start sub_8147718
sub_8147718: @ 8147718
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8BB8
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814772A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814772A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147718

	thumb_func_start sub_8147750
sub_8147750: @ 8147750
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r2, 0
	ldr r4, =0x020393a8
	ldr r3, =0x0203aba0
_08147762:
	lsls r1, r2, 1
	adds r1, r4
	ldr r0, [r3]
	ldrh r0, [r0, 0x16]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9F
	bls _08147762
	ldr r0, =sub_8147888
	bl SetVBlankCallback
	ldr r0, =sub_81478C0
	bl SetHBlankCallback
	movs r0, 0x2
	bl EnableInterrupts
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147750

	thumb_func_start sub_81477A8
sub_81477A8: @ 81477A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r2, [r6, 0xC]
	lsls r1, r2, 16
	asrs r0, r1, 24
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r4, [r6, 0xA]
	movs r0, 0xC0
	lsls r0, 1
	mov r8, r0
	movs r5, 0x80
	lsls r5, 3
	adds r0, r4, r5
	strh r0, [r6, 0xA]
	ldr r0, =0x1fff0000
	cmp r1, r0
	bgt _081477E4
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r2, r1
	strh r0, [r6, 0xC]
_081477E4:
	movs r5, 0
	lsls r7, r3, 16
_081477E8:
	lsrs r0, r4, 8
	asrs r1, r7, 16
	bl sine
	ldr r1, =0x02038c28
	lsls r2, r5, 1
	adds r2, r1
	ldr r1, =0x0203aba0
	ldr r1, [r1]
	ldrh r1, [r1, 0x16]
	adds r0, r1
	strh r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r8
	adds r0, r4, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r5, 0x9F
	bls _081477E8
	ldrh r0, [r6, 0xE]
	adds r0, 0x1
	strh r0, [r6, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _08147838
	ldrh r0, [r6, 0x10]
	adds r0, 0x1
	strh r0, [r6, 0x10]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
	movs r3, 0x10
	bl pal_fade_maybe
_08147838:
	movs r5, 0x10
	ldrsh r0, [r6, r5]
	cmp r0, 0
	beq _0814785A
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814785A
	ldr r0, =sub_8147718
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0814785A:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81477A8

	thumb_func_start sub_8147888
sub_8147888: @ 8147888
	push {lr}
	bl sub_8149F2C
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _081478AC
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_081478AC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147888

	thumb_func_start sub_81478C0
sub_81478C0: @ 81478C0
	ldr r1, =0x02038c28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000016
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81478C0

	thumb_func_start sub_81478EC
sub_81478EC: @ 81478EC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8BC0
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081478FE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081478FE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81478EC

	thumb_func_start sub_8147924
sub_8147924: @ 8147924
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	movs r0, 0xF0
	strh r0, [r1, 0x6]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r3, =0x020393a8
	movs r2, 0xF2
_0814794A:
	lsls r0, r1, 1
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9F
	bls _0814794A
	ldr r0, =sub_8147A58
	bl SetVBlankCallback
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147924

	thumb_func_start sub_814797C
sub_814797C: @ 814797C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r7, =0x02038c28
	ldrh r0, [r4, 0xC]
	ldrb r5, [r4, 0xC]
	adds r0, 0x10
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	adds r0, 0x8
	strh r0, [r4, 0xA]
	movs r6, 0
	movs r0, 0x1
	mov r8, r0
_081479A4:
	adds r0, r5, 0
	movs r1, 0x28
	bl sine
	ldrh r1, [r4, 0xA]
	adds r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r0, 0
	bge _081479BA
	movs r1, 0
_081479BA:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xF0
	ble _081479C4
	movs r1, 0xF0
_081479C4:
	lsls r0, r1, 16
	asrs r0, 16
	lsls r1, r0, 8
	movs r2, 0xF1
	orrs r1, r2
	strh r1, [r7]
	cmp r0, 0xEF
	bgt _081479D8
	movs r0, 0
	mov r8, r0
_081479D8:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, 0x2
	cmp r6, 0x9F
	bls _081479A4
	mov r1, r8
	cmp r1, 0
	beq _081479F6
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081479F6:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814797C

	thumb_func_start sub_8147A18
sub_8147A18: @ 8147A18
	push {lr}
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
	bl sub_8149F84
	ldr r0, =sub_81478EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147A18

	thumb_func_start sub_8147A58
sub_8147A58: @ 8147A58
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r3, =0x0203aba0
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08147A90
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08147A90:
	ldr r2, =0x04000048
	ldr r1, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	ldr r0, =0x020393a8
	str r0, [r4]
	ldr r0, =0x04000040
	str r0, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147A58

	thumb_func_start sub_8147AE4
sub_8147AE4: @ 8147AE4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x26]
	bl sub_8147B84
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147AE4

	thumb_func_start sub_8147B04
sub_8147B04: @ 8147B04
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x1
	strh r2, [r1, 0x26]
	bl sub_8147B84
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147B04

	thumb_func_start sub_8147B24
sub_8147B24: @ 8147B24
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x2
	strh r2, [r1, 0x26]
	bl sub_8147B84
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147B24

	thumb_func_start sub_8147B44
sub_8147B44: @ 8147B44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x3
	strh r2, [r1, 0x26]
	bl sub_8147B84
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147B44

	thumb_func_start sub_8147B64
sub_8147B64: @ 8147B64
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x4
	strh r2, [r1, 0x26]
	bl sub_8147B84
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147B64

	thumb_func_start sub_8147B84
sub_8147B84: @ 8147B84
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8BCC
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08147B96:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08147B96
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8147B84

	thumb_func_start sub_8147BBC
sub_8147BBC: @ 8147BBC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	adds r0, r4, 0
	bl sub_8148218
	movs r0, 0
	strh r0, [r4, 0xA]
	movs r0, 0x1
	strh r0, [r4, 0xC]
	movs r0, 0xEF
	strh r0, [r4, 0xE]
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	movs r0, 0x3E
	strh r0, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r3, =0x020393a8
	ldr r2, =0x0000f0f1
_08147BF0:
	lsls r0, r1, 1
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9F
	bls _08147BF0
	ldr r0, =sub_81480CC
	bl SetVBlankCallback
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147BBC

	thumb_func_start sub_8147C24
sub_8147C24: @ 8147C24
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r8, r0
	ldr r6, =gUnknown_085C94D0
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_085B9AF0
	ldr r1, [sp, 0x4]
	movs r2, 0xF0
	bl CpuSet
	ldr r1, =gUnknown_085C8FDC
	mov r2, r8
	movs r3, 0x26
	ldrsh r0, [r2, r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r1, =gUnknown_085C8FF0
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xFA
	movs r2, 0xC
	bl gpu_pal_apply
	movs r1, 0
	ldr r5, [sp]
	movs r0, 0xF0
	lsls r0, 8
	adds r7, r0, 0
_08147C78:
	movs r0, 0
	lsls r3, r1, 16
	asrs r4, r3, 11
_08147C7E:
	lsls r2, r0, 16
	asrs r2, 16
	adds r1, r4, r2
	lsls r1, 1
	adds r1, r5
	ldrh r0, [r6]
	orrs r0, r7
	strh r0, [r1]
	adds r2, 0x1
	lsls r2, 16
	adds r6, 0x2
	lsrs r0, r2, 16
	asrs r2, 16
	cmp r2, 0x1F
	ble _08147C7E
	movs r1, 0x80
	lsls r1, 9
	adds r0, r3, r1
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _08147C78
	movs r0, 0x2
	bl EnableInterrupts
	ldr r0, =sub_81481E0
	bl SetHBlankCallback
	mov r2, r8
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147C24

	thumb_func_start sub_8147CE4
sub_8147CE4: @ 8147CE4
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r7, =0x02038c28
	ldrh r0, [r4, 0xA]
	ldrb r5, [r4, 0xA]
	adds r0, 0x10
	strh r0, [r4, 0xA]
	movs r6, 0
_08147CFE:
	adds r0, r5, 0
	movs r1, 0x10
	bl sine
	ldrh r1, [r4, 0xC]
	adds r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r0, 0
	bge _08147D14
	movs r2, 0x1
_08147D14:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0xF0
	ble _08147D1E
	movs r2, 0xF0
_08147D1E:
	strh r2, [r7]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r7, 0x2
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r6, 0x4F
	bls _08147CFE
	cmp r6, 0x9F
	bhi _08147D76
_08147D38:
	adds r0, r5, 0
	movs r1, 0x10
	bl sine
	ldrh r1, [r4, 0xE]
	subs r1, r0
	lsls r1, 16
	lsrs r2, r1, 16
	cmp r1, 0
	bge _08147D4E
	movs r2, 0
_08147D4E:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0xEF
	ble _08147D58
	movs r2, 0xEF
_08147D58:
	lsls r0, r2, 16
	asrs r0, 8
	movs r1, 0xF0
	orrs r0, r1
	strh r0, [r7]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r7, 0x2
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r6, 0x9F
	bls _08147D38
_08147D76:
	ldrh r1, [r4, 0xC]
	adds r1, 0x8
	strh r1, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	subs r0, 0x8
	strh r0, [r4, 0xE]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xF0
	ble _08147D8E
	movs r0, 0xF0
	strh r0, [r4, 0xC]
_08147D8E:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _08147D9A
	movs r0, 0
	strh r0, [r4, 0xE]
_08147D9A:
	ldr r0, [r4, 0xC]
	cmp r0, 0xF0
	bne _08147DA6
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08147DA6:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r1, 0x18]
	subs r0, 0x8
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x1A]
	adds r0, 0x8
	strh r0, [r1, 0x1A]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147CE4

	thumb_func_start sub_8147DD0
sub_8147DD0: @ 8147DD0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r1, =0x02038c28
	adds r5, r2, 0
	movs r2, 0xF0
_08147DE4:
	strh r2, [r1]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	adds r1, 0x2
	cmp r0, 0x9F
	bls _08147DE4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xA]
	strh r1, [r4, 0xC]
	strh r1, [r4, 0xE]
	ldr r1, [r5]
	ldrh r0, [r1, 0x18]
	subs r0, 0x8
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x1A]
	adds r0, 0x8
	strh r0, [r1, 0x1A]
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r1, 0
	bl sub_8148484
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	bl sub_8148484
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	bl sub_814849C
	movs r0, 0x68
	bl audio_play
	ldr r1, [r5]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147DD0

	thumb_func_start sub_8147E4C
sub_8147E4C: @ 8147E4C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r1, 0x18]
	subs r0, 0x8
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x1A]
	adds r0, 0x8
	strh r0, [r1, 0x1A]
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	bl sub_81484B8
	lsls r0, 16
	cmp r0, 0
	beq _08147E7C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	bl sub_814849C
_08147E7C:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147E4C

	thumb_func_start sub_8147E88
sub_8147E88: @ 8147E88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldr r7, =0x0203aba0
	ldr r1, [r7]
	ldrh r0, [r1, 0x18]
	subs r0, 0x8
	movs r2, 0
	mov r8, r2
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x1A]
	adds r0, 0x8
	strh r0, [r1, 0x1A]
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	bl sub_81484B8
	lsls r0, 16
	cmp r0, 0
	beq _08147F1C
	ldr r1, [r7]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
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
	ldr r4, =0x02038c28
	movs r5, 0xA0
	lsls r5, 1
	adds r0, r4, 0
	movs r1, 0
	adds r2, r5, 0
	bl memset
	movs r2, 0xF0
	lsls r2, 3
	adds r4, r2
	adds r0, r4, 0
	movs r1, 0
	adds r2, r5, 0
	bl memset
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	mov r0, r8
	strh r0, [r6, 0xE]
	strh r0, [r6, 0x10]
	ldr r1, [r7]
	movs r0, 0xBF
	strh r0, [r1, 0xE]
	ldr r0, =sub_8148160
	bl SetVBlankCallback
_08147F1C:
	movs r0, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147E88

	thumb_func_start sub_8147F40
sub_8147F40: @ 8147F40
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	movs r6, 0x1
	ldr r1, [r2]
	ldrh r0, [r1, 0x18]
	subs r0, 0x8
	strh r0, [r1, 0x18]
	ldrh r0, [r1, 0x1A]
	adds r0, 0x8
	strh r0, [r1, 0x1A]
	ldrh r1, [r4, 0x10]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	mov r12, r2
	cmp r0, 0x4F
	bgt _08147F6E
	adds r0, r1, 0x2
	strh r0, [r4, 0x10]
_08147F6E:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0x50
	ble _08147F7A
	movs r0, 0x50
	strh r0, [r4, 0x10]
_08147F7A:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	movs r1, 0x1
	ands r0, r1
	ldrh r3, [r4, 0x10]
	cmp r0, 0
	beq _08147FDC
	movs r2, 0
	lsls r0, r3, 16
	movs r6, 0
	cmp r0, 0
	blt _08147FDC
	movs r7, 0x50
	ldr r5, =0x02038c28
_08147F98:
	lsls r0, r2, 16
	asrs r3, r0, 16
	subs r1, r7, r3
	adds r0, r3, 0
	adds r0, 0x50
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	asrs r1, 15
	adds r1, r5
	ldrh r0, [r1]
	cmp r0, 0xF
	bhi _08147FB8
	movs r6, 0x1
	adds r0, 0x1
	strh r0, [r1]
_08147FB8:
	lsls r0, r2, 16
	asrs r0, 15
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, 0xF
	bhi _08147FCA
	movs r6, 0x1
	adds r0, 0x1
	strh r0, [r1]
_08147FCA:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	asrs r0, 16
	movs r3, 0x10
	ldrsh r1, [r4, r3]
	ldrh r3, [r4, 0x10]
	cmp r0, r1
	ble _08147F98
_08147FDC:
	cmp r3, 0x50
	bne _08147FEA
	cmp r6, 0
	bne _08147FEA
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08147FEA:
	mov r1, r12
	ldr r0, [r1]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8147F40

	thumb_func_start sub_8148008
sub_8148008: @ 8148008
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =0x0203aba0
	ldr r0, [r5]
	ldrb r1, [r0]
	movs r6, 0
	strb r6, [r0]
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x00007fff
	movs r1, 0x10
	bl sub_80A2A20
	ldr r1, [r5]
	movs r0, 0xFF
	strh r0, [r1, 0xE]
	strh r6, [r4, 0xE]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148008

	thumb_func_start sub_8148040
sub_8148040: @ 8148040
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =0x0203aba0
	ldr r1, [r5]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	ldr r0, =0x02038c28
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	movs r2, 0xA0
	lsls r2, 1
	bl memset
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	ble _08148070
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08148070:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148040

	thumb_func_start sub_814808C
sub_814808C: @ 814808C
	push {r4,lr}
	adds r4, r0, 0
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
	bl sub_8149F84
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814808C

	thumb_func_start sub_81480CC
sub_81480CC: @ 81480CC
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r3, =0x0203aba0
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08148104
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08148104:
	ldr r2, =0x04000012
	ldr r1, [r3]
	ldrh r0, [r1, 0x1C]
	strh r0, [r2]
	adds r2, 0x36
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	ldr r0, =0x020393a8
	str r0, [r4]
	ldr r0, =0x04000040
	str r0, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81480CC

	thumb_func_start sub_8148160
sub_8148160: @ 8148160
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r2, =0x0203aba0
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08148198
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r3, 0xF0
	lsls r3, 3
	adds r0, r3
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08148198:
	ldr r1, =0x04000050
	ldr r0, [r2]
	ldrh r0, [r0, 0xE]
	strh r0, [r1]
	ldr r0, =0x020393a8
	str r0, [r4]
	ldr r0, =0x04000054
	str r0, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148160

	thumb_func_start sub_81481E0
sub_81481E0: @ 81481E0
	push {lr}
	ldr r0, =0x04000006
	ldrh r0, [r0]
	cmp r0, 0x4F
	bhi _08148200
	ldr r1, =0x04000010
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	ldrh r0, [r0, 0x18]
	b _08148208
	.pool
_08148200:
	ldr r1, =0x04000010
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	ldrh r0, [r0, 0x1A]
_08148208:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81481E0

	thumb_func_start sub_8148218
sub_8148218: @ 8148218
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =gUnknown_085C8BF4
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	mov r8, r1
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gUnknown_085C8C0E
	lsls r1, 2
	mov r8, r1
	adds r1, r2
	ldrh r1, [r1]
	subs r1, 0x20
	lsls r1, 16
	asrs r1, 16
	adds r2, 0x2
	add r2, r8
	ldrh r2, [r2]
	adds r2, 0x2A
	lsls r2, 16
	asrs r2, 16
	ldr r5, =0x0201c000
	str r5, [sp]
	movs r3, 0
	bl sub_80B5E6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl sub_806F000
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x88
	lsls r1, 1
	str r5, [sp]
	movs r2, 0x6A
	movs r3, 0
	bl sub_80B5E6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x24]
	movs r3, 0x22
	ldrsh r0, [r4, r3]
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r1, =0x02020630
	adds r5, r1
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	lsls r6, r0, 4
	adds r6, r0
	lsls r6, 2
	adds r6, r1
	ldr r0, =sub_8148380
	str r0, [r5, 0x1C]
	str r0, [r6, 0x1C]
	ldrb r0, [r5, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldrb r0, [r6, 0x1]
	orrs r0, r1
	strb r0, [r6, 0x1]
	bl rotscale_alloc_entry
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0x1F
	mov r9, r3
	mov r4, r9
	ands r0, r4
	lsls r0, 1
	ldrb r2, [r5, 0x3]
	movs r4, 0x3F
	negs r4, r4
	adds r1, r4, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x3]
	bl rotscale_alloc_entry
	lsls r0, 24
	lsrs r0, 24
	mov r1, r9
	ands r0, r1
	lsls r0, 1
	ldrb r1, [r6, 0x3]
	ands r4, r1
	orrs r4, r0
	strb r4, [r6, 0x3]
	ldrb r2, [r5, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r2
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r5, 0x1]
	ldrb r0, [r6, 0x1]
	ands r1, r0
	orrs r1, r2
	strb r1, [r6, 0x1]
	ldrb r0, [r5, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldrb r0, [r6, 0x3]
	orrs r0, r1
	strb r0, [r6, 0x3]
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x3
	bl CalcVecFromObjectCenterToObjectUpperLeft
	adds r0, r6, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x3
	bl CalcVecFromObjectCenterToObjectUpperLeft
	ldrb r0, [r5, 0x3]
	lsls r0, 26
	lsrs r0, 27
	ldr r2, =gUnknown_085C8BFA
	mov r3, r8
	adds r1, r3, r2
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r2, 0x2
	add r8, r2
	mov r3, r8
	movs r4, 0
	ldrsh r2, [r3, r4]
	movs r3, 0
	bl sub_8008478
	ldrb r0, [r6, 0x3]
	lsls r0, 26
	lsrs r0, 27
	ldr r1, =0xfffffe00
	movs r2, 0x80
	lsls r2, 2
	movs r3, 0
	bl sub_8008478
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148218

	thumb_func_start sub_8148380
sub_8148380: @ 8148380
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_085C8C24
_08148386:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08148386
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148380

	thumb_func_start sub_81483A8
sub_81483A8: @ 81483A8
	movs r0, 0
	bx lr
	thumb_func_end sub_81483A8

	thumb_func_start sub_81483AC
sub_81483AC: @ 81483AC
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r1, =gUnknown_085C8C40
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	add r4, sp, 0x4
	ldr r1, =gUnknown_085C8C44
	adds r0, r4, 0
	movs r2, 0x4
	bl memcpy
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r5, 0x30]
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r4, r0
	ldrh r0, [r4]
	strh r0, [r5, 0x32]
	movs r0, 0x1
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81483AC

	thumb_func_start sub_81483F8
sub_81483F8: @ 81483F8
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	ldrh r3, [r1, 0x20]
	adds r2, r0, r3
	strh r2, [r1, 0x20]
	movs r3, 0x3C
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08148416
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x84
	bgt _08148424
	b _0814841E
_08148416:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x67
	ble _08148424
_0814841E:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
_08148424:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_81483F8

	thumb_func_start sub_814842C
sub_814842C: @ 814842C
	push {lr}
	adds r2, r0, 0
	ldrh r3, [r2, 0x32]
	ldrh r0, [r2, 0x30]
	adds r1, r3, r0
	strh r1, [r2, 0x30]
	ldrh r0, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
	lsls r1, 16
	cmp r1, 0
	bne _08148452
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	negs r0, r3
	strh r0, [r2, 0x32]
	movs r0, 0x1
	strh r0, [r2, 0x3A]
_08148452:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_814842C

	thumb_func_start sub_8148458
sub_8148458: @ 8148458
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x30]
	adds r0, r1
	strh r0, [r2, 0x30]
	ldrh r1, [r2, 0x20]
	adds r1, r0
	strh r1, [r2, 0x20]
	adds r1, 0x1F
	lsls r1, 16
	movs r0, 0x97
	lsls r0, 17
	cmp r1, r0
	bls _0814847C
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
_0814847C:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8148458

	thumb_func_start sub_8148484
sub_8148484: @ 8148484
	ldr r3, =0x02020630
	lsls r0, 16
	asrs r0, 16
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	strh r1, [r2, 0x3C]
	bx lr
	.pool
	thumb_func_end sub_8148484

	thumb_func_start sub_814849C
sub_814849C: @ 814849C
	ldr r2, =0x02020630
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	bx lr
	.pool
	thumb_func_end sub_814849C

	thumb_func_start sub_81484B8
sub_81484B8: @ 81484B8
	ldr r2, =0x02020630
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0x3A
	ldrsh r0, [r1, r2]
	bx lr
	.pool
	thumb_func_end sub_81484B8

	thumb_func_start sub_81484D0
sub_81484D0: @ 81484D0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8C48
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081484E2:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081484E2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81484D0

	thumb_func_start sub_8148508
sub_8148508: @ 8148508
	push {r4-r6,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r4, 0
	movs r3, 0
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0xC]
	movs r0, 0x1
	strh r0, [r5, 0xE]
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	strh r3, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	ldrb r0, [r1]
	strb r4, [r1]
	ldr r4, =0x020393a8
	adds r6, r2, 0
	movs r2, 0xF0
_0814853A:
	lsls r1, r3, 1
	adds r1, r4
	ldr r0, [r6]
	ldrh r0, [r0, 0x14]
	strh r0, [r1]
	adds r0, r3, 0
	adds r0, 0xA0
	lsls r0, 1
	adds r0, r4
	strh r2, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x9F
	bls _0814853A
	movs r0, 0x2
	bl EnableInterrupts
	movs r0, 0x4
	movs r1, 0x10
	bl SetGpuRegBits
	ldr r0, =sub_814869C
	bl SetVBlankCallback
	ldr r0, =sub_8148728
	bl SetHBlankCallback
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148508

	thumb_func_start sub_8148590
sub_8148590: @ 8148590
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r3, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r3, 0xC]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r3, 0xA]
	adds r0, r1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	mov r8, r2
	cmp r0, 0xF0
	ble _081485BC
	movs r0, 0xF0
	strh r0, [r3, 0xA]
_081485BC:
	ldrh r4, [r3, 0xC]
	movs r0, 0xC
	ldrsh r1, [r3, r0]
	ldr r0, =0x00000fff
	ldrh r2, [r3, 0xE]
	cmp r1, r0
	bgt _081485CE
	adds r0, r4, r2
	strh r0, [r3, 0xC]
_081485CE:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x7F
	bgt _081485DA
	lsls r0, r2, 1
	strh r0, [r3, 0xE]
_081485DA:
	movs r5, 0
	ldr r7, =0x02038c28
	movs r1, 0xA0
	lsls r1, 1
	adds r1, r7
	mov r12, r1
	mov r6, r8
_081485E8:
	lsls r0, r5, 1
	adds r2, r0, r7
	mov r1, r12
	adds r4, r0, r1
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _08148618
	ldr r1, [r6]
	ldrh r0, [r3, 0xA]
	ldrh r1, [r1, 0x14]
	adds r0, r1
	strh r0, [r2]
	ldrh r1, [r3, 0xA]
	movs r0, 0xF0
	subs r0, r1
	b _0814862A
	.pool
_08148618:
	ldr r0, [r6]
	ldrh r0, [r0, 0x14]
	ldrh r1, [r3, 0xA]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r3, 0xA]
	lsls r0, 8
	movs r1, 0xF1
	orrs r0, r1
_0814862A:
	strh r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9F
	bls _081485E8
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	cmp r0, 0xEF
	ble _08148644
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_08148644:
	mov r1, r8
	ldr r0, [r1]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8148590

	thumb_func_start sub_814865C
sub_814865C: @ 814865C
	push {lr}
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
	bl sub_8149F84
	ldr r0, =sub_81484D0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814865C

	thumb_func_start sub_814869C
sub_814869C: @ 814869C
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r2, =0x04000048
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	ldrb r0, [r1]
	cmp r0, 0
	beq _081486E6
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x80000140
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_081486E6:
	ldr r0, =0x020394e8
	str r0, [r4]
	ldr r0, =0x04000040
	str r0, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814869C

	thumb_func_start sub_8148728
sub_8148728: @ 8148728
	push {lr}
	ldr r2, =0x04000006
	ldrh r0, [r2]
	cmp r0, 0x9F
	bhi _0814874E
	ldr r1, =0x02038c28
	ldrh r0, [r2]
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000014
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
	adds r0, 0x4
	strh r1, [r0]
_0814874E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148728

	thumb_func_start sub_8148760
sub_8148760: @ 8148760
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8C54
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08148772:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08148772
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148760

	thumb_func_start sub_8148798
sub_8148798: @ 8148798
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r4, 0
	ldr r5, =0x02038c28
	movs r0, 0xF0
	lsls r0, 3
	adds r0, r5
	mov r12, r0
	mov r8, r4
	movs r1, 0xF0
	mov r9, r1
_081487CC:
	lsls r2, r4, 1
	mov r7, r12
	adds r1, r2, r7
	ldr r0, =0x0203aba0
	ldr r3, [r0]
	ldrh r0, [r3, 0x14]
	strh r0, [r1]
	adds r1, r4, 0
	adds r1, 0xA0
	lsls r1, 1
	adds r0, r1, r7
	mov r7, r9
	strh r7, [r0]
	adds r2, r5
	ldrh r0, [r3, 0x14]
	strh r0, [r2]
	adds r1, r5
	mov r0, r9
	strh r0, [r1]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r4, r1
	lsls r0, 1
	adds r0, r5
	mov r7, r8
	strh r7, [r0]
	adds r1, 0xA0
	adds r0, r4, r1
	lsls r0, 1
	adds r0, r5
	subs r1, 0xE0
	strh r1, [r0]
	movs r7, 0xA0
	lsls r7, 2
	adds r0, r4, r7
	lsls r0, 1
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9F
	bls _081487CC
	movs r0, 0
	strh r0, [r6, 0x10]
	strh r0, [r6, 0x12]
	movs r0, 0x7
	strh r0, [r6, 0x14]
	movs r0, 0x2
	bl EnableInterrupts
	ldr r0, =sub_814869C
	bl SetVBlankCallback
	ldr r0, =sub_8148728
	bl SetHBlankCallback
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148798

	thumb_func_start sub_8148864
sub_8148864: @ 8148864
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r9, r0
	ldr r1, =gUnknown_085C8C64
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	add r4, sp, 0x4
	ldr r1, =gUnknown_085C8C66
	adds r0, r4, 0
	movs r2, 0x4
	bl memcpy
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	str r0, [sp, 0x8]
	mov r10, r0
	mov r1, r9
	movs r3, 0x12
	ldrsh r0, [r1, r3]
	ldr r1, [sp, 0x8]
	cmp r1, r0
	ble _081488A4
	b _08148A68
_081488A4:
	movs r7, 0
	mov r2, r10
	negs r2, r2
	str r2, [sp, 0xC]
	mov r3, r10
	adds r3, 0x1
	str r3, [sp, 0x10]
_081488B2:
	movs r6, 0
	mov r0, sp
	adds r0, r7
	mov r12, r0
_081488BA:
	lsls r0, r6, 1
	add r0, sp
	adds r0, 0x4
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, 0xC]
	muls r0, r2
	lsls r0, 1
	mov r3, r12
	ldrb r3, [r3]
	adds r0, r3
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _08148966
	cmp r0, 0x4F
	bne _081488E2
	cmp r7, 0x1
	beq _08148966
_081488E2:
	lsls r1, r0, 1
	ldr r0, =0x02038ea8
	adds r4, r1, r0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2
	adds r3, r1, r0
	ldr r0, =0x02039128
	adds r1, r0
	ldrh r2, [r4]
	cmp r2, 0xEF
	bls _08148920
	movs r1, 0xF0
	strh r1, [r4]
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	b _08148940
	.pool
_08148920:
	ldrh r0, [r3]
	lsrs r0, 8
	adds r0, r2, r0
	strh r0, [r4]
	ldrh r0, [r1]
	cmp r0, 0x7F
	bhi _08148932
	lsls r0, 1
	strh r0, [r1]
_08148932:
	ldrh r2, [r3]
	ldr r0, =0x00000fff
	cmp r2, r0
	bhi _08148940
	ldrh r0, [r1]
	adds r0, r2, r0
	strh r0, [r3]
_08148940:
	lsls r0, r5, 16
	asrs r0, 15
	ldr r1, =0x02038c28
	adds r2, r0, r1
	ldr r1, =0x02038d68
	adds r3, r0, r1
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r4]
	ldrh r1, [r1, 0x14]
	adds r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	movs r1, 0xF0
	subs r0, r1, r0
	strh r0, [r3]
	mov r2, r10
	cmp r2, 0
	beq _08148970
_08148966:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1
	bls _081488BA
_08148970:
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x1
	bls _081488B2
	movs r7, 0
	ldr r3, =0x02038ea8
	mov r8, r3
_08148980:
	movs r6, 0
	mov r0, sp
	adds r0, r7
	mov r12, r0
	adds r1, r7, 0x1
	str r1, [sp, 0x14]
_0814898C:
	mov r2, r12
	ldrb r1, [r2]
	adds r1, 0x1
	lsls r0, r6, 1
	add r0, sp
	adds r0, 0x4
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r2, [sp, 0xC]
	muls r0, r2
	lsls r0, 1
	adds r1, r0
	lsls r1, 16
	lsrs r5, r1, 16
	asrs r1, 16
	cmp r1, 0xA0
	bgt _08148A40
	cmp r1, 0x50
	bne _081489B6
	cmp r7, 0x1
	beq _08148A40
_081489B6:
	lsls r1, 1
	mov r3, r8
	adds r4, r1, r3
	movs r0, 0xA0
	lsls r0, 1
	add r0, r8
	adds r3, r1, r0
	ldr r0, =0x02039128
	adds r1, r0
	ldrh r2, [r4]
	cmp r2, 0xEF
	bls _081489F8
	movs r1, 0xF0
	strh r1, [r4]
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	b _08148A18
	.pool
_081489F8:
	ldrh r0, [r3]
	lsrs r0, 8
	adds r0, r2, r0
	strh r0, [r4]
	ldrh r0, [r1]
	cmp r0, 0x7F
	bhi _08148A0A
	lsls r0, 1
	strh r0, [r1]
_08148A0A:
	ldrh r2, [r3]
	ldr r0, =0x00000fff
	cmp r2, r0
	bhi _08148A18
	ldrh r0, [r1]
	adds r0, r2, r0
	strh r0, [r3]
_08148A18:
	lsls r0, r5, 16
	asrs r0, 15
	ldr r1, =0x02038c28
	adds r2, r0, r1
	ldr r1, =0x02038d68
	adds r3, r0, r1
	ldr r1, =0x0203aba0
	ldr r0, [r1]
	ldrh r1, [r0, 0x14]
	ldrh r0, [r4]
	subs r1, r0
	strh r1, [r2]
	ldrh r0, [r4]
	lsls r0, 8
	movs r1, 0xF1
	orrs r0, r1
	strh r0, [r3]
	mov r2, r10
	cmp r2, 0
	beq _08148A4A
_08148A40:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1
	bls _0814898C
_08148A4A:
	ldr r3, [sp, 0x14]
	lsls r0, r3, 16
	lsrs r7, r0, 16
	cmp r7, 0x1
	bls _08148980
	ldr r1, [sp, 0x10]
	lsls r0, r1, 16
	lsrs r0, 16
	mov r10, r0
	mov r2, r9
	movs r3, 0x12
	ldrsh r0, [r2, r3]
	cmp r10, r0
	bgt _08148A68
	b _081488A4
_08148A68:
	mov r1, r9
	ldrh r0, [r1, 0x10]
	subs r0, 0x1
	strh r0, [r1, 0x10]
	lsls r0, 16
	cmp r0, 0
	bge _08148A7A
	movs r0, 0
	strh r0, [r1, 0x10]
_08148A7A:
	mov r2, r9
	movs r3, 0x10
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bgt _08148A98
	movs r1, 0x12
	ldrsh r0, [r2, r1]
	adds r0, 0x1
	cmp r0, 0x14
	bgt _08148A98
	ldrh r0, [r2, 0x14]
	strh r0, [r2, 0x10]
	ldrh r0, [r2, 0x12]
	adds r0, 0x1
	strh r0, [r2, 0x12]
_08148A98:
	ldr r2, [sp, 0x8]
	cmp r2, 0x9F
	bls _08148AA6
	mov r3, r9
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_08148AA6:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148864

	thumb_func_start sub_8148AD4
sub_8148AD4: @ 8148AD4
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r2, 0x1
	ldr r5, =0x0000ff10
	movs r1, 0
	ldr r4, =0x020393a8
_08148AE0:
	lsls r0, r1, 1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0xF0
	beq _08148AF0
	cmp r0, r5
	beq _08148AF0
	movs r2, 0
_08148AF0:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _08148AE0
	cmp r2, 0x1
	bne _08148B04
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_08148B04:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148AD4

	thumb_func_start sub_8148B14
sub_8148B14: @ 8148B14
	push {lr}
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
	bl sub_8149F84
	ldr r0, =sub_8148760
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148B14

	thumb_func_start sub_8148B54
sub_8148B54: @ 8148B54
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8C6C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08148B66:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08148B66
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148B54

	thumb_func_start sub_8148B8C
sub_8148B8C: @ 8148B8C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8C78
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08148B9E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08148B9E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148B8C

	thumb_func_start sub_8148BC4
sub_8148BC4: @ 8148BC4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x2]
	movs r0, 0x3F
	strh r0, [r1, 0x4]
	movs r0, 0xF0
	strh r0, [r1, 0x6]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	ldr r0, =0x02038c28
	movs r2, 0
	movs r1, 0x9F
	ldr r3, =0x000008be
	adds r0, r3
_08148BEE:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08148BEE
	movs r4, 0
	ldr r0, =sub_8146F68
	bl SetVBlankCallback
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	strh r0, [r5, 0xA]
	adds r0, 0xFF
	strh r0, [r5, 0xC]
	strh r4, [r5, 0x16]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148BC4

	thumb_func_start sub_8148C28
sub_8148C28: @ 8148C28
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08148C6C
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
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _08148CDE
	.pool
_08148C6C:
	ldr r5, =0x0203aba0
	ldr r1, [r5]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r2, [r4, 0xC]
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	ldr r0, =0x000003ff
	cmp r1, r0
	bgt _08148C88
	adds r0, r2, 0
	adds r0, 0x80
	strh r0, [r4, 0xC]
_08148C88:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x9F
	bgt _08148C9C
	ldrh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 24
	adds r0, r1, r0
	strh r0, [r4, 0xA]
_08148C9C:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xA0
	ble _08148CA8
	movs r0, 0xA0
	strh r0, [r4, 0xA]
_08148CA8:
	ldr r0, =0x02038c28
	movs r2, 0xA
	ldrsh r3, [r4, r2]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A014
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xA0
	bne _08148CD4
	movs r0, 0x1
	strh r0, [r4, 0x16]
	bl sub_8149F84
	b _08148CDE
	.pool
_08148CD4:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
_08148CDE:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8148C28

	thumb_func_start sub_8148CE8
sub_8148CE8: @ 8148CE8
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =0x0203aba0
	ldr r0, [r6]
	ldrb r1, [r0]
	movs r5, 0
	strb r5, [r0]
	ldrh r1, [r4, 0x16]
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08148D0A
	adds r0, r1, 0x1
	strh r0, [r4, 0x16]
	movs r0, 0x30
	strh r0, [r4, 0xA]
	strh r5, [r4, 0x14]
_08148D0A:
	ldr r1, =gUnknown_085C8C80
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, 0xA]
	adds r0, r1
	strh r0, [r4, 0xA]
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	adds r1, 0x1
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	strh r1, [r4, 0x14]
	ldr r0, =0x02038c28
	movs r1, 0xA
	ldrsh r3, [r4, r1]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A014
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bgt _08148D4C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	strh r5, [r4, 0x16]
_08148D4C:
	ldr r0, [r6]
	ldrb r1, [r0]
	adds r1, 0x1
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148CE8

	thumb_func_start sub_8148D6C
sub_8148D6C: @ 8148D6C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldrh r1, [r4, 0x16]
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08148D8E
	adds r0, r1, 0x1
	strh r0, [r4, 0x16]
	movs r0, 0x2
	strh r0, [r4, 0x12]
	strh r0, [r4, 0x14]
_08148D8E:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xA0
	ble _08148D9A
	movs r0, 0xA0
	strh r0, [r4, 0xA]
_08148D9A:
	ldr r0, =0x02038c28
	movs r2, 0xA
	ldrsh r3, [r4, r2]
	movs r1, 0x78
	movs r2, 0x50
	bl sub_814A014
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xA0
	bne _08148DD6
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
	bl sub_8149F84
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_08148DD6:
	ldrh r2, [r4, 0x12]
	ldrb r0, [r4, 0x12]
	cmp r0, 0x80
	bgt _08148DFC
	ldrh r1, [r4, 0x14]
	adds r0, r2, 0
	adds r0, 0x8
	b _08148E08
	.pool
_08148DFC:
	ldrh r0, [r4, 0x14]
	subs r0, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	adds r0, r2, 0
	adds r0, 0x10
_08148E08:
	strh r0, [r4, 0x12]
	movs r0, 0xFF
	ands r2, r0
	lsls r1, 16
	asrs r1, 16
	adds r0, r2, 0
	bl sine
	ldrh r2, [r4, 0xA]
	adds r0, r2
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bgt _08148E28
	movs r0, 0x1
	strh r0, [r4, 0xA]
_08148E28:
	ldrh r0, [r4, 0x12]
	lsls r1, r0, 16
	asrs r0, r1, 16
	cmp r0, 0xFE
	ble _08148E3C
	asrs r0, r1, 24
	strh r0, [r4, 0x12]
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	strh r0, [r4, 0x14]
_08148E3C:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148D6C

	thumb_func_start sub_8148E54
sub_8148E54: @ 8148E54
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8C84
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08148E66:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08148E66
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8148E54

	thumb_func_start sub_8148E8C
sub_8148E8C: @ 8148E8C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	ldr r4, =gUnknown_085BACD0
	ldr r1, [sp, 0x8]
	adds r0, r4, 0
	movs r2, 0x10
	bl CpuSet
	movs r0, 0xE0
	lsls r0, 1
	adds r4, r0
	ldr r1, [sp, 0x8]
	adds r1, 0x40
	adds r0, r4, 0
	movs r2, 0x10
	bl CpuSet
	mov r1, sp
	movs r2, 0xF0
	lsls r2, 8
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gFieldEffectObjectPalette10
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	movs r1, 0
	movs r4, 0x1
	movs r0, 0x1
	strh r0, [r5, 0xE]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	ldr r5, =0x03001210
	strb r1, [r5]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0x2]
	strb r4, [r5, 0x4]
	movs r2, 0x9A
	lsls r2, 1
	strh r2, [r5, 0x6]
	strb r1, [r5, 0x8]
	strb r1, [r5, 0xC]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r5, 0xE]
	strb r4, [r5, 0x10]
	strh r2, [r5, 0x12]
	strb r1, [r5, 0x14]
	strb r1, [r5, 0x18]
	ldr r2, =0x0000fffd
	strh r2, [r5, 0x1A]
	strb r4, [r5, 0x1C]
	ldr r3, =0x00000133
	strh r3, [r5, 0x1E]
	adds r0, r5, 0
	adds r0, 0x20
	strb r1, [r0]
	adds r0, 0x4
	strb r1, [r0]
	strh r2, [r5, 0x26]
	adds r0, 0x4
	strb r4, [r0]
	strh r3, [r5, 0x2A]
	adds r0, 0x4
	strb r1, [r0]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148E8C

	thumb_func_start sub_8148F4C
sub_8148F4C: @ 8148F4C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r8, r0
	movs r7, 0x1
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	movs r0, 0
_08148F62:
	movs r5, 0
	adds r6, r0, 0x1
_08148F66:
	ldr r1, =gUnknown_085C8D38
	lsrs r0, r5, 1
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	ldr r2, =0x03001210
	adds r4, r1, r2
	adds r1, r4, 0
	bl sub_8149048
	lsls r0, 16
	cmp r0, 0
	beq _08148FCA
	movs r7, 0
	ldrh r2, [r4, 0x2]
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0x1
	bne _08148FA0
	ldr r0, =0x0000027d
	adds r1, r0, 0
	lsls r0, r2, 16
	asrs r0, 16
	subs r1, r0
	lsls r1, 16
	lsrs r2, r1, 16
_08148FA0:
	lsls r0, r2, 16
	asrs r1, r0, 16
	adds r0, r1, 0
	cmp r1, 0
	bge _08148FAC
	adds r0, 0x1F
_08148FAC:
	asrs r2, r0, 5
	lsls r0, r2, 5
	subs r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r2, 5
	lsls r0, 16
	asrs r0, 16
	adds r1, r0
	ldr r0, [sp]
	lsls r1, 1
	adds r1, r0
	ldr r2, =0x0000f002
	adds r0, r2, 0
	strh r0, [r1]
_08148FCA:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _08148F66
	lsls r0, r6, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08148F62
	cmp r7, 0x1
	bne _08148FE8
	mov r1, r8
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_08148FE8:
	movs r0, 0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8148F4C

	thumb_func_start sub_8149008
sub_8149008: @ 8149008
	push {r4,lr}
	adds r4, r0, 0
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
	bl sub_8149F84
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149008

	thumb_func_start sub_8149048
sub_8149048: @ 8149048
	push {r4,lr}
	adds r2, r1, 0
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r0
	ldr r3, [r1]
	ldrb r0, [r2, 0x4]
	lsls r0, 1
	adds r0, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _081490CE
	ldr r1, =0x03001208
	ldrh r0, [r3]
	strh r0, [r1]
	ldrh r0, [r3, 0x2]
	strh r0, [r1]
	ldrh r0, [r3, 0x4]
	strh r0, [r1]
	ldrh r0, [r3, 0x6]
	strh r0, [r1]
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0x2
	beq _081490A0
	cmp r0, 0x2
	bgt _08149090
	cmp r0, 0x1
	beq _0814909A
	b _081490B2
	.pool
_08149090:
	cmp r0, 0x3
	beq _081490A6
	cmp r0, 0x4
	beq _081490AC
	b _081490B2
_0814909A:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	b _081490B0
_081490A0:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	b _081490B0
_081490A6:
	ldrh r0, [r2, 0x2]
	subs r0, 0x20
	b _081490B0
_081490AC:
	ldrh r0, [r2, 0x2]
	adds r0, 0x20
_081490B0:
	strh r0, [r2, 0x2]
_081490B2:
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	ldr r0, =0x0000027f
	cmp r1, r0
	bgt _081490CE
	ldrb r0, [r2, 0x4]
	lsls r0, 1
	adds r0, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _081490D8
_081490CE:
	movs r0, 0
	b _08149138
	.pool
_081490D8:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _081490F4
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	bne _081490F4
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r2, 0x4]
	ldrh r0, [r2, 0x6]
	strh r0, [r2, 0x2]
	movs r0, 0x4
	strb r0, [r2]
_081490F4:
	ldrb r0, [r2, 0x4]
	lsls r0, 1
	adds r0, r3
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _08149136
	ldrb r0, [r2]
	adds r1, r0, 0x1
	strb r1, [r2]
	ldrb r0, [r2, 0x8]
	cmp r0, 0x1
	bne _08149124
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x7
	bls _08149136
	ldrb r0, [r2, 0x4]
	adds r0, 0x1
	strb r0, [r2, 0x4]
	movs r0, 0x4
	b _08149134
_08149124:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08149136
	ldrb r0, [r2, 0x4]
	adds r0, 0x1
	strb r0, [r2, 0x4]
	movs r0, 0
_08149134:
	strb r0, [r2]
_08149136:
	movs r0, 0x1
_08149138:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8149048

	thumb_func_start sub_8149140
sub_8149140: @ 8149140
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8D40
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08149152:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08149152
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149140

	thumb_func_start sub_8149178
sub_8149178: @ 8149178
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085BE51C
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085BEA88
	ldr r1, [sp, 0x4]
	bl LZ77UnCompVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xA]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149178

	thumb_func_start sub_81491C8
sub_81491C8: @ 81491C8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	adds r0, r5, 0
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08149200
	adds r0, r5, 0
	movs r1, 0x1E
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r0, 11
	ldr r1, =gUnknown_085BF0A0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
_08149200:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3A
	ble _08149218
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0xA]
_08149218:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81491C8

	thumb_func_start sub_8149224
sub_8149224: @ 8149224
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	adds r0, r5, 0
	movs r1, 0x5
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08149252
	adds r0, r5, 0
	movs r1, 0x5
	bl __divsi3
	lsls r0, 16
	asrs r0, 11
	ldr r1, =gUnknown_085BF2A0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
_08149252:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x44
	ble _0814926E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0xA]
	movs r0, 0x1E
	strh r0, [r4, 0x18]
_0814926E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149224

	thumb_func_start sub_814927C
sub_814927C: @ 814927C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8D60
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814928E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814928E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814927C

	thumb_func_start sub_81492B4
sub_81492B4: @ 81492B4
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r1, =0x00009a08
	movs r0, 0x8
	bl SetGpuReg
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085BF6A0
	ldr r1, [sp, 0x8]
	movs r2, 0x80
	lsls r2, 5
	bl CpuSet
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x20]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_085BF540
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	movs r2, 0
	ldr r3, =0x02038c28
	movs r6, 0
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r3, r0
	movs r4, 0x80
	lsls r4, 1
_08149316:
	lsls r1, r2, 1
	adds r0, r1, r3
	strh r6, [r0]
	adds r1, r5
	strh r4, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9F
	bls _08149316
	ldr r0, =sub_8149508
	bl SetVBlankCallback
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81492B4

	thumb_func_start sub_8149358
sub_8149358: @ 8149358
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_085C6BE0
	ldr r1, [sp]
	movs r2, 0x80
	lsls r2, 4
	bl CpuSet
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149358

	thumb_func_start sub_8149388
sub_8149388: @ 8149388
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081493B4
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _081493A0
	adds r0, 0x3
_081493A0:
	lsls r0, 14
	lsrs r0, 16
	adds r0, 0x5
	lsls r0, 5
	ldr r1, =gUnknown_085BF4A0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
_081493B4:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _081493CC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0xA]
_081493CC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149388

	thumb_func_start sub_81493D8
sub_81493D8: @ 81493D8
	push {lr}
	sub sp, 0x4
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08149402
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	strh r2, [r1, 0xA]
	ldr r0, =0xffff8000
	str r2, [sp]
	movs r1, 0x2
	movs r3, 0x10
	bl pal_fade_maybe
_08149402:
	movs r0, 0
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81493D8

	thumb_func_start sub_8149410
sub_8149410: @ 8149410
	push {lr}
	adds r2, r0, 0
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814942E
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x20]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_0814942E:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149410

	thumb_func_start sub_814943C
sub_814943C: @ 814943C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x00007fff
	movs r1, 0x8
	movs r2, 0
	bl sub_80A2A20
	ldr r0, =0xffff8000
	movs r1, 0
	movs r2, 0
	bl sub_80A2A20
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814943C

	thumb_func_start sub_814946C
sub_814946C: @ 814946C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	adds r0, r5, 0
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0814949A
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r0, 11
	ldr r1, =gUnknown_085BF4A0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
_0814949A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _081494F0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x2]
	movs r0, 0x3F
	strh r0, [r1, 0x4]
	movs r0, 0xF0
	strh r0, [r1, 0x6]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r5, =sub_8146F68
	ldr r3, =0x020393a8
	movs r2, 0
_081494C4:
	lsls r0, r1, 1
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _081494C4
	adds r0, r5, 0
	bl SetVBlankCallback
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x8]
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r4, 0xC]
	strh r2, [r4, 0x16]
	movs r0, 0
	bl ClearGpuRegBits
_081494F0:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814946C

	thumb_func_start sub_8149508
sub_8149508: @ 8149508
	push {lr}
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
	bl sub_8149F2C
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08149548
	ldr r2, =0x02038c28
	b _08149554
	.pool
_08149548:
	ldr r2, =0x02038c28
	cmp r0, 0x1
	bne _08149554
	movs r0, 0xF0
	lsls r0, 3
	adds r2, r0
_08149554:
	ldr r1, =0x040000b0
	str r2, [r1]
	ldr r0, =0x04000012
	str r0, [r1, 0x4]
	ldr r0, =0xa2400001
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149508

	thumb_func_start sub_8149578
sub_8149578: @ 8149578
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8D8C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814958A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814958A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149578

	thumb_func_start sub_81495B0
sub_81495B0: @ 81495B0
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0xBF
	strh r0, [r1, 0xE]
	strh r2, [r1, 0x12]
	movs r0, 0x1E
	strh r0, [r1, 0x2]
	movs r0, 0x3F
	strh r0, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r2, =0x020393a8
	movs r4, 0
	movs r3, 0xF0
_081495DC:
	lsls r0, r1, 1
	adds r0, r2
	strh r4, [r0]
	adds r0, r1, 0
	adds r0, 0xA0
	lsls r0, 1
	adds r0, r2
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _081495DC
	movs r0, 0x2
	bl EnableInterrupts
	ldr r0, =sub_8149840
	bl SetHBlankCallback
	ldr r0, =sub_8149774
	bl SetVBlankCallback
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81495B0

	thumb_func_start sub_8149628
sub_8149628: @ 8149628
	push {r4-r6,lr}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r1, =gUnknown_085C8DA0
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	movs r5, 0
	movs r4, 0
_0814963C:
	ldr r0, =sub_8149864
	bl obj_add_empty_with_callback
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =0x02020630
	adds r2, r1, r0
	movs r0, 0xF0
	strh r0, [r2, 0x20]
	strh r4, [r2, 0x22]
	lsls r1, r5, 16
	asrs r1, 16
	lsls r0, r1, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r2, 0x38]
	adds r1, 0x1
	lsls r1, 16
	lsls r0, r4, 16
	movs r3, 0xA0
	lsls r3, 13
	adds r0, r3
	lsrs r4, r0, 16
	lsrs r5, r1, 16
	asrs r1, 16
	cmp r1, 0x7
	ble _0814963C
	ldrh r0, [r2, 0x3A]
	adds r0, 0x1
	strh r0, [r2, 0x3A]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149628

	thumb_func_start sub_814969C
sub_814969C: @ 814969C
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =0x0203aba0
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r0, [r2]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0x7
	ble _081496C6
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x00007fff
	movs r1, 0x10
	bl sub_80A2A20
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081496C6:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814969C

	thumb_func_start sub_81496D8
sub_81496D8: @ 81496D8
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =0x0203aba0
	ldr r0, [r4]
	ldrb r1, [r0]
	movs r5, 0
	strb r5, [r0]
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
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	ldr r1, [r4]
	movs r0, 0xF0
	strh r0, [r1, 0x6]
	strh r5, [r1, 0x12]
	movs r0, 0xFF
	strh r0, [r1, 0xE]
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	ldr r0, =sub_8149804
	bl SetVBlankCallback
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81496D8

	thumb_func_start sub_8149740
sub_8149740: @ 8149740
	push {lr}
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x10
	bls _08149766
	bl sub_8149F84
	ldr r0, =sub_8149578
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_08149766:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149740

	thumb_func_start sub_8149774
sub_8149774: @ 8149774
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r2, =0x04000050
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r1, 0xE]
	strh r0, [r2]
	subs r2, 0x8
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	ldrb r0, [r1]
	cmp r0, 0
	beq _081497C4
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x80000140
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_081497C4:
	ldr r0, =0x020394e8
	str r0, [r4]
	ldr r0, =0x04000040
	str r0, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149774

	thumb_func_start sub_8149804
sub_8149804: @ 8149804
	push {lr}
	bl sub_8149F2C
	ldr r1, =0x04000054
	ldr r0, =0x0203aba0
	ldr r2, [r0]
	ldrh r0, [r2, 0x12]
	strh r0, [r1]
	subs r1, 0x4
	ldrh r0, [r2, 0xE]
	strh r0, [r1]
	subs r1, 0x8
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x4]
	strh r0, [r1]
	subs r1, 0xA
	ldrh r0, [r2, 0x6]
	strh r0, [r1]
	adds r1, 0x4
	ldrh r0, [r2, 0x8]
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149804

	thumb_func_start sub_8149840
sub_8149840: @ 8149840
	ldr r2, =0x04000054
	ldr r1, =0x02038c28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r3, 0xF0
	lsls r3, 3
	adds r1, r3
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8149840

	thumb_func_start sub_8149864
sub_8149864: @ 8149864
	push {r4-r6,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x38]
	movs r2, 0x38
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08149890
	subs r0, r1, 0x1
	strh r0, [r3, 0x38]
	movs r1, 0x3A
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0814994C
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0x1
	strb r0, [r1]
	b _0814994C
	.pool
_08149890:
	movs r2, 0x22
	ldrsh r1, [r3, r2]
	lsls r1, 1
	ldr r0, =0x02038c28
	adds r6, r1, r0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2
	adds r5, r1, r0
	movs r4, 0
_081498A4:
	lsls r1, r4, 1
	adds r2, r1, r6
	ldrh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x20]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _081498A4
	movs r1, 0x20
	ldrsh r0, [r3, r1]
	ldrh r2, [r3, 0x20]
	cmp r0, 0
	bne _081498DE
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _081498DE
	movs r0, 0x1
	strh r0, [r3, 0x30]
_081498DE:
	adds r1, r2, 0
	subs r1, 0x10
	strh r1, [r3, 0x20]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x80
	strh r0, [r3, 0x2E]
	lsls r1, 16
	cmp r1, 0
	bge _081498F4
	movs r0, 0
	strh r0, [r3, 0x20]
_081498F4:
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	movs r1, 0x80
	lsls r1, 5
	cmp r0, r1
	ble _08149902
	strh r1, [r3, 0x2E]
_08149902:
	movs r2, 0x3A
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08149914
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0x1
	strb r0, [r1]
_08149914:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0814994C
	movs r2, 0x3A
	ldrsh r0, [r3, r2]
	ldr r2, =0x0203aba0
	cmp r0, 0
	beq _0814993E
	ldr r0, [r2]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	ble _0814994C
	ldrh r0, [r3, 0x32]
	adds r1, r0, 0x1
	strh r1, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0814994C
_0814993E:
	ldr r1, [r2]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	adds r0, r3, 0
	bl RemoveObjectAndFreeTiles
_0814994C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149864

	thumb_func_start sub_814995C
sub_814995C: @ 814995C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8DB0
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814996E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814996E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814995C

	thumb_func_start sub_8149994
sub_8149994: @ 8149994
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085BACD0
	ldr r1, [sp, 0x8]
	movs r2, 0x10
	bl CpuSet
	mov r1, sp
	movs r2, 0xF0
	lsls r2, 8
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gFieldEffectObjectPalette10
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149994

	thumb_func_start sub_81499E8
sub_81499E8: @ 81499E8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08149A2A
	mov r0, sp
	bl sub_8149F40
	movs r0, 0x3
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	lsls r0, 5
	ldr r1, =gUnknown_085BACD0
	adds r0, r1
	ldr r1, [sp]
	movs r2, 0x10
	bl CpuSet
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0xD
	ble _08149A2A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x10
	strh r0, [r4, 0xA]
_08149A2A:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81499E8

	thumb_func_start sub_8149A40
sub_8149A40: @ 8149A40
	push {lr}
	ldrh r1, [r0, 0xA]
	subs r1, 0x1
	strh r1, [r0, 0xA]
	lsls r1, 16
	cmp r1, 0
	bne _08149A60
	bl sub_8149F84
	ldr r0, =sub_814995C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_08149A60:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149A40

	thumb_func_start sub_8149A6C
sub_8149A6C: @ 8149A6C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8DBC
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08149A7E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08149A7E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149A6C

	thumb_func_start sub_8149AA4
sub_8149AA4: @ 8149AA4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r2, =0x02038c28
	movs r3, 0xF0
	adds r4, r2, 0
_08149AC8:
	lsls r0, r1, 1
	adds r0, r2
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _08149AC8
	movs r0, 0xF0
	lsls r0, 3
	adds r1, r4, r0
	adds r0, r4, 0
	movs r2, 0xA0
	bl CpuSet
	ldr r0, =sub_8149CE8
	bl SetVBlankCallback
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149AA4

	thumb_func_start sub_8149B08
sub_8149B08: @ 8149B08
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r8, r0
	ldr r0, =0x0203aba0
	ldr r0, [r0]
	adds r0, 0x24
	ldr r6, =gUnknown_085C8DD0
	mov r2, r8
	movs r3, 0xA
	ldrsh r1, [r2, r3]
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 1
	adds r1, r4, r6
	movs r5, 0
	ldrsh r1, [r1, r5]
	adds r2, r6, 0x2
	adds r2, r4, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r3, r6, 0x4
	adds r3, r4, r3
	movs r5, 0
	ldrsh r3, [r3, r5]
	adds r5, r6, 0x6
	adds r4, r5
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	bl sub_814A1AC
	mov r0, r8
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r6, 0x8
	adds r0, r6
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	movs r0, 0x1
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149B08

	thumb_func_start sub_8149B84
sub_8149B84: @ 8149B84
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	mov r8, r0
	movs r7, 0
	ldr r0, =0x02038c28
	mov r9, r0
_08149BA0:
	ldr r1, =0x02038c28
	ldr r0, =0x0203aba0
	ldr r2, [r0]
	movs r3, 0x2A
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsrs r3, r0, 8
	movs r5, 0xFF
	ands r5, r0
	movs r4, 0xC
	ldrsh r0, [r6, r4]
	cmp r0, 0
	bne _08149BDC
	movs r1, 0x28
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bge _08149BC8
	ldrh r3, [r2, 0x28]
_08149BC8:
	lsls r0, r3, 16
	lsls r1, r5, 16
	cmp r0, r1
	ble _08149BF4
	lsrs r3, r1, 16
	b _08149BF4
	.pool
_08149BDC:
	lsls r0, r5, 16
	asrs r0, 16
	movs r4, 0x28
	ldrsh r1, [r2, r4]
	cmp r0, r1
	ble _08149BEA
	ldrh r5, [r2, 0x28]
_08149BEA:
	lsls r0, r5, 16
	lsls r1, r3, 16
	cmp r0, r1
	bgt _08149BF4
	lsrs r5, r1, 16
_08149BF4:
	ldr r0, =0x0203aba0
	ldr r4, [r0]
	movs r0, 0x2A
	ldrsh r2, [r4, r0]
	lsls r2, 1
	add r2, r9
	lsls r1, r3, 16
	asrs r1, 8
	lsls r0, r5, 16
	asrs r0, 16
	orrs r0, r1
	strh r0, [r2]
	cmp r7, 0
	beq _08149C1C
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _08149C40
	.pool
_08149C1C:
	adds r0, r4, 0
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, r8
	lsls r0, r1, 16
	movs r3, 0x80
	lsls r3, 9
	adds r0, r3
	lsrs r4, r0, 16
	mov r8, r4
	asrs r0, 16
	cmp r0, 0xF
	ble _08149BA0
_08149C40:
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149B84

	thumb_func_start sub_8149C60
sub_8149C60: @ 8149C60
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _08149CAC
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
	bl sub_8149F84
	ldr r0, =sub_8149A6C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	b _08149CC4
	.pool
_08149CAC:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	ldr r1, =gUnknown_085C8E16
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	subs r0, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2, 0xE]
	movs r0, 0x1
_08149CC4:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149C60

	thumb_func_start sub_8149CCC
sub_8149CCC: @ 8149CCC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xE]
	subs r0, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	cmp r0, 0
	beq _08149CE0
	movs r0, 0
	b _08149CE4
_08149CE0:
	movs r0, 0x1
	strh r0, [r1, 0x8]
_08149CE4:
	pop {r1}
	bx r1
	thumb_func_end sub_8149CCC

	thumb_func_start sub_8149CE8
sub_8149CE8: @ 8149CE8
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl sub_8149F2C
	ldr r3, =0x0203aba0
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08149D20
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08149D20:
	ldr r2, =0x04000048
	ldr r1, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	subs r2, 0x4
	ldr r0, =0x02038c28
	movs r1, 0xF0
	lsls r1, 3
	adds r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	str r0, [r4]
	str r2, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149CE8

	thumb_func_start sub_8149D78
sub_8149D78: @ 8149D78
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r3, [sp, 0x18]
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r0, =sub_8149DFC
	movs r1, 0x3
	str r3, [sp]
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	mov r0, r8
	strh r0, [r1, 0xA]
	strh r4, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r6, [r1, 0x10]
	ldr r3, [sp]
	strh r3, [r1, 0x12]
	strh r0, [r1, 0x14]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149D78

	thumb_func_start sub_8149DDC
sub_8149DDC: @ 8149DDC
	push {lr}
	ldr r0, =sub_8149DFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08149DF4
	movs r0, 0
	b _08149DF6
	.pool
_08149DF4:
	movs r0, 0x1
_08149DF6:
	pop {r1}
	bx r1
	thumb_func_end sub_8149DDC

	thumb_func_start sub_8149DFC
sub_8149DFC: @ 8149DFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8E24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08149E0E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08149E0E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149DFC

	thumb_func_start sub_8149E34
sub_8149E34: @ 8149E34
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08149E4C
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	bne _08149E70
_08149E4C:
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x10]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	strh r0, [r4, 0x16]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08149E64
	movs r0, 0x10
	strh r0, [r4, 0x16]
_08149E64:
	movs r0, 0x1
	negs r0, r0
	ldrb r1, [r4, 0x16]
	ldr r2, =0x00002d6b
	bl sub_80A2A20
_08149E70:
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	ble _08149E82
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0x14]
_08149E82:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149E34

	thumb_func_start sub_8149E90
sub_8149E90: @ 8149E90
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08149EA8
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	bne _08149ECA
_08149EA8:
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x16]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x16]
	lsls r0, 16
	cmp r0, 0
	bge _08149EBE
	movs r0, 0
	strh r0, [r4, 0x16]
_08149EBE:
	movs r0, 0x1
	negs r0, r0
	ldrb r1, [r4, 0x16]
	ldr r2, =0x00002d6b
	bl sub_80A2A20
_08149ECA:
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _08149EFE
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08149EF8
	ldr r0, =sub_8149DFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _08149EFE
	.pool
_08149EF8:
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0x14]
	strh r1, [r4, 0x8]
_08149EFE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8149E90

	thumb_func_start sub_8149F08
sub_8149F08: @ 8149F08
	push {r4,lr}
	ldr r4, =0x0203aba0
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x3C
	bl memset
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x14
	adds r1, 0x16
	bl sub_8089C08
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149F08

	thumb_func_start sub_8149F2C
sub_8149F2C: @ 8149F2C
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl copy_pal_bg_faded_to_pal_ram
	pop {r0}
	bx r0
	thumb_func_end sub_8149F2C

	thumb_func_start sub_8149F40
sub_8149F40: @ 8149F40
	ldr r1, =0x04000008
	ldrh r1, [r1]
	lsrs r1, 2
	lsls r1, 30
	lsrs r1, 16
	movs r2, 0xC0
	lsls r2, 19
	adds r1, r2
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8149F40

	thumb_func_start sub_8149F58
sub_8149F58: @ 8149F58
	push {r4,lr}
	ldr r3, =0x04000008
	ldrh r2, [r3]
	lsrs r2, 8
	ldrh r3, [r3]
	lsrs r3, 2
	lsls r2, 27
	lsrs r2, 16
	lsls r3, 30
	lsrs r3, 16
	movs r4, 0xC0
	lsls r4, 19
	adds r2, r4
	str r2, [r0]
	adds r3, r4
	str r3, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149F58

	thumb_func_start sub_8149F84
sub_8149F84: @ 8149F84
	push {lr}
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	pop {r0}
	bx r0
	thumb_func_end sub_8149F84

	thumb_func_start sub_8149F98
sub_8149F98: @ 8149F98
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	ldr r0, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r1, r0, 16
	lsls r4, 16
	movs r6, 0
	lsrs r5, r4, 16
	cmp r4, 0
	ble _0814A000
	lsls r0, r7, 16
	asrs r0, 16
	mov r9, r0
	lsls r1, 16
	mov r8, r1
	lsls r0, r3, 16
	asrs r7, r0, 16
_08149FD0:
	lsls r4, r2, 16
	asrs r4, 16
	movs r0, 0xFF
	ands r0, r4
	mov r2, r8
	asrs r1, r2, 16
	bl sine
	lsls r1, r6, 1
	add r1, r10
	add r0, r9
	strh r0, [r1]
	lsls r1, r5, 16
	ldr r0, =0xffff0000
	adds r1, r0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, r7
	lsls r4, 16
	lsrs r2, r4, 16
	lsrs r5, r1, 16
	cmp r1, 0
	bgt _08149FD0
_0814A000:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149F98

	thumb_func_start sub_814A014
sub_814A014: @ 814A014
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r9, r0
	adds r5, r2, 0
	adds r4, r3, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	movs r2, 0xA0
	lsls r2, 1
	movs r1, 0xA
	bl memset
	movs r1, 0
	lsls r4, 16
	asrs r4, 16
	str r4, [sp, 0x4]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x8]
_0814A04C:
	lsls r5, r1, 16
	asrs r0, r5, 16
	mov r10, r0
	ldr r1, [sp, 0x4]
	bl sine
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r10
	ldr r1, [sp, 0x4]
	bl cosine
	ldr r2, [sp]
	lsls r1, r2, 16
	asrs r1, 16
	lsls r4, 16
	asrs r4, 16
	subs r2, r1, r4
	lsls r2, 16
	adds r1, r4
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r0, 16
	asrs r0, 16
	ldr r3, [sp, 0x8]
	subs r1, r3, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r3, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsrs r1, r2, 16
	str r5, [sp, 0x10]
	cmp r2, 0
	bge _0814A098
	movs r1, 0
_0814A098:
	lsls r0, r6, 16
	asrs r0, 16
	cmp r0, 0xF0
	ble _0814A0A2
	movs r6, 0xF0
_0814A0A2:
	lsls r0, r7, 16
	cmp r0, 0
	bge _0814A0AA
	movs r7, 0
_0814A0AA:
	mov r2, r8
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _0814A0B8
	movs r3, 0x9F
	mov r8, r3
_0814A0B8:
	lsls r0, r1, 24
	lsrs r0, 16
	orrs r6, r0
	lsls r0, r7, 16
	asrs r0, 16
	str r0, [sp, 0xC]
	lsls r0, 1
	add r0, r9
	strh r6, [r0]
	mov r0, r8
	lsls r4, r0, 16
	asrs r0, r4, 15
	add r0, r9
	strh r6, [r0]
	mov r0, r10
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	ldr r1, [sp, 0x4]
	bl cosine
	lsls r0, 16
	asrs r0, 16
	ldr r2, [sp, 0x8]
	subs r1, r2, r0
	lsls r1, 16
	adds r0, r2, r0
	lsls r0, 16
	lsrs r2, r0, 16
	lsrs r3, r1, 16
	cmp r1, 0
	bge _0814A0FA
	movs r3, 0
_0814A0FA:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _0814A104
	movs r2, 0x9F
_0814A104:
	lsls r0, r3, 16
	asrs r1, r0, 16
	adds r3, r0, 0
	lsls r5, r2, 16
	ldr r0, [sp, 0xC]
	cmp r0, r1
	ble _0814A128
	adds r2, r1, 0
_0814A114:
	lsls r1, r7, 16
	ldr r0, =0xffff0000
	adds r1, r0
	asrs r0, r1, 15
	add r0, r9
	strh r6, [r0]
	lsrs r7, r1, 16
	asrs r1, 16
	cmp r1, r2
	bgt _0814A114
_0814A128:
	lsls r1, r7, 16
	asrs r0, r3, 16
	cmp r1, r3
	bge _0814A146
	adds r2, r0, 0
_0814A132:
	movs r3, 0x80
	lsls r3, 9
	adds r0, r1, r3
	asrs r1, r0, 15
	add r1, r9
	strh r6, [r1]
	adds r1, r0, 0
	asrs r0, r1, 16
	cmp r0, r2
	blt _0814A132
_0814A146:
	asrs r0, r5, 16
	cmp r4, r5
	ble _0814A164
	adds r1, r0, 0
_0814A14E:
	ldr r2, =0xffff0000
	adds r0, r4, r2
	lsrs r3, r0, 16
	mov r8, r3
	asrs r0, 15
	add r0, r9
	strh r6, [r0]
	lsls r4, r3, 16
	asrs r0, r4, 16
	cmp r0, r1
	bgt _0814A14E
_0814A164:
	mov r0, r8
	lsls r4, r0, 16
	asrs r0, r5, 16
	cmp r4, r5
	bge _0814A184
	adds r2, r0, 0
_0814A170:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r4, r1
	asrs r1, r0, 15
	add r1, r9
	strh r6, [r1]
	adds r4, r0, 0
	asrs r0, r4, 16
	cmp r0, r2
	blt _0814A170
_0814A184:
	ldr r2, [sp, 0x10]
	movs r3, 0x80
	lsls r3, 9
	adds r0, r2, r3
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	bgt _0814A196
	b _0814A04C
_0814A196:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A014

	thumb_func_start sub_814A1AC
sub_814A1AC: @ 814A1AC
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, [sp, 0x14]
	ldr r5, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r0, 16
	adds r7, r0, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	strh r1, [r6]
	strh r2, [r6, 0x2]
	strh r1, [r6, 0x4]
	strh r2, [r6, 0x6]
	strh r3, [r6, 0x8]
	strh r7, [r6, 0xA]
	strh r5, [r6, 0xC]
	strh r4, [r6, 0xE]
	lsls r3, 16
	asrs r3, 16
	lsls r1, 16
	asrs r1, 16
	subs r3, r1
	strh r3, [r6, 0x10]
	lsls r0, r3, 16
	cmp r0, 0
	bge _0814A1FE
	negs r0, r3
	strh r0, [r6, 0x10]
	lsls r0, r5, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r6, 0xC]
_0814A1FE:
	lsls r0, r7, 16
	asrs r0, 16
	lsls r1, r2, 16
	asrs r1, 16
	subs r1, r0, r1
	strh r1, [r6, 0x12]
	lsls r0, r1, 16
	cmp r0, 0
	bge _0814A21C
	negs r0, r1
	strh r0, [r6, 0x12]
	lsls r0, r4, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r6, 0xE]
_0814A21C:
	movs r0, 0
	strh r0, [r6, 0x14]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_814A1AC

	thumb_func_start sub_814A228
sub_814A228: @ 814A228
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	ldrh r0, [r3, 0x10]
	mov r8, r0
	movs r1, 0x10
	ldrsh r6, [r3, r1]
	ldrh r2, [r3, 0x12]
	mov r12, r2
	movs r4, 0x12
	ldrsh r5, [r3, r4]
	cmp r6, r5
	ble _0814A278
	ldrh r0, [r3, 0xC]
	ldrh r2, [r3, 0x4]
	adds r1, r0, r2
	strh r1, [r3, 0x4]
	ldrh r2, [r3, 0x14]
	add r2, r12
	strh r2, [r3, 0x14]
	lsls r1, r2, 16
	asrs r1, 16
	adds r4, r0, 0
	ldrh r7, [r3, 0xE]
	cmp r1, r6
	ble _0814A29E
	ldrh r1, [r3, 0x6]
	adds r0, r7, r1
	strh r0, [r3, 0x6]
	mov r1, r8
	b _0814A29A
_0814A278:
	ldrh r0, [r3, 0xE]
	ldrh r2, [r3, 0x6]
	adds r1, r0, r2
	strh r1, [r3, 0x6]
	ldrh r2, [r3, 0x14]
	add r2, r8
	strh r2, [r3, 0x14]
	lsls r1, r2, 16
	asrs r1, 16
	ldrh r4, [r3, 0xC]
	adds r7, r0, 0
	cmp r1, r5
	ble _0814A29E
	ldrh r1, [r3, 0x4]
	adds r0, r4, r1
	strh r0, [r3, 0x4]
	mov r1, r12
_0814A29A:
	subs r0, r2, r1
	strh r0, [r3, 0x14]
_0814A29E:
	movs r5, 0
	lsls r0, r4, 16
	asrs r2, r0, 16
	cmp r2, 0
	ble _0814A2B6
	movs r4, 0x4
	ldrsh r1, [r3, r4]
	movs r4, 0x8
	ldrsh r0, [r3, r4]
	ldrh r4, [r3, 0x8]
	cmp r1, r0
	bge _0814A2C8
_0814A2B6:
	cmp r2, 0
	bge _0814A2D6
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0x8
	ldrsh r0, [r3, r2]
	ldrh r4, [r3, 0x8]
	cmp r1, r0
	bgt _0814A2D6
_0814A2C8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r9
	cmp r0, 0
	beq _0814A2D6
	strh r4, [r3, 0x4]
_0814A2D6:
	lsls r0, r7, 16
	asrs r2, r0, 16
	cmp r2, 0
	ble _0814A2EC
	movs r4, 0x6
	ldrsh r1, [r3, r4]
	movs r4, 0xA
	ldrsh r0, [r3, r4]
	ldrh r4, [r3, 0xA]
	cmp r1, r0
	bge _0814A2FE
_0814A2EC:
	cmp r2, 0
	bge _0814A30C
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0xA
	ldrsh r0, [r3, r2]
	ldrh r4, [r3, 0xA]
	cmp r1, r0
	bgt _0814A30C
_0814A2FE:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r10
	cmp r0, 0
	beq _0814A30C
	strh r4, [r3, 0x6]
_0814A30C:
	cmp r5, 0x2
	beq _0814A314
	movs r0, 0
	b _0814A316
_0814A314:
	movs r0, 0x1
_0814A316:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_814A228

	thumb_func_start sub_814A324
sub_814A324: @ 814A324
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_814669C
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085C7C00
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085C7BE0
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A324

	thumb_func_start sub_814A374
sub_814A374: @ 814A374
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085C828C
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =0x02038c28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A374

	thumb_func_start sub_814A3BC
sub_814A3BC: @ 814A3BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C99D0
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A3CE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A3CE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A3BC

	thumb_func_start sub_814A3F4
sub_814A3F4: @ 814A3F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C99E8
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A406:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A406
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A3F4

	thumb_func_start sub_814A42C
sub_814A42C: @ 814A42C
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r1, 0xC0
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
	movs r5, 0
	movs r0, 0x80
	lsls r0, 6
	strh r0, [r4, 0xC]
	ldr r0, =0x00007fff
	strh r0, [r4, 0xA]
	strh r5, [r4, 0x12]
	movs r0, 0x10
	strh r0, [r4, 0x14]
	movs r0, 0xA0
	lsls r0, 4
	strh r0, [r4, 0x16]
	ldr r6, =0x0203aba0
	ldr r2, [r6]
	ldr r3, =0x00003f41
	strh r3, [r2, 0xE]
	ldrh r0, [r4, 0x14]
	lsls r0, 8
	ldrh r1, [r4, 0x12]
	orrs r0, r1
	strh r0, [r2, 0x10]
	ldr r0, =0x04000050
	strh r3, [r0]
	ldr r1, =0x04000052
	ldrh r0, [r2, 0x10]
	strh r0, [r1]
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r0, sp
	strh r5, [r0]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	bl CpuSet
	ldr r0, =gUnknown_085C7C00
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085C7BE0
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r0, [r6]
	strh r5, [r0, 0x16]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A42C

	thumb_func_start sub_814A4D4
sub_814A4D4: @ 814A4D4
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_085C828C
	ldr r1, [sp]
	bl LZ77UnCompVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A4D4

	thumb_func_start sub_814A500
sub_814A500: @ 814A500
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r2, 0
	ldr r6, =sub_814A684
	ldr r4, =0x020393a8
	ldr r3, =0x0203aba0
_0814A50C:
	lsls r1, r2, 1
	adds r1, r4
	ldr r0, [r3]
	ldrh r0, [r0, 0x16]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9F
	bls _0814A50C
	adds r0, r6, 0
	bl SetVBlankCallback
	ldr r0, =sub_814A6CC
	bl SetHBlankCallback
	movs r0, 0x2
	bl EnableInterrupts
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A500

	thumb_func_start sub_814A550
sub_814A550: @ 814A550
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =0x0203aba0
	ldr r0, [r1]
	ldrb r2, [r0]
	movs r3, 0
	strb r3, [r0]
	ldrh r2, [r4, 0xC]
	lsls r0, r2, 16
	asrs r0, 24
	lsls r0, 16
	lsrs r7, r0, 16
	ldrh r6, [r4, 0xA]
	movs r0, 0xC0
	lsls r0, 1
	mov r8, r0
	ldrh r0, [r4, 0x16]
	subs r0, r6, r0
	strh r0, [r4, 0xA]
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	adds r5, r1, 0
	cmp r0, 0x45
	ble _0814A5A2
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	ldr r1, =0xfffffe80
	adds r0, r1
	cmp r0, 0
	blt _0814A5A0
	adds r0, r2, r1
	strh r0, [r4, 0xC]
	b _0814A5A2
	.pool
_0814A5A0:
	strh r3, [r4, 0xC]
_0814A5A2:
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _0814A5E0
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0814A5E0
	ldrh r1, [r4, 0x12]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _0814A5C6
	adds r0, r1, 0x1
	strh r0, [r4, 0x12]
	b _0814A5D4
_0814A5C6:
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0814A5D4
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
_0814A5D4:
	ldr r0, [r5]
	ldrh r1, [r4, 0x14]
	lsls r1, 8
	ldrh r2, [r4, 0x12]
	orrs r1, r2
	strh r1, [r0, 0x10]
_0814A5E0:
	movs r5, 0
	lsls r7, 16
_0814A5E4:
	lsrs r0, r6, 8
	asrs r1, r7, 16
	bl sine
	ldr r1, =0x02038c28
	lsls r2, r5, 1
	adds r2, r1
	ldr r1, =0x0203aba0
	ldr r1, [r1]
	ldrh r1, [r1, 0x16]
	adds r0, r1
	strh r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r8
	adds r0, r6, r1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r5, 0x9F
	bls _0814A5E4
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x65
	bne _0814A632
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
_0814A632:
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0814A654
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814A654
	ldr r0, =sub_814A3F4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0814A654:
	ldrh r0, [r4, 0x16]
	subs r0, 0x11
	strh r0, [r4, 0x16]
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A550

	thumb_func_start sub_814A684
sub_814A684: @ 814A684
	push {lr}
	bl sub_8149F2C
	ldr r2, =0x04000050
	ldr r0, =0x0203aba0
	ldr r1, [r0]
	ldrh r0, [r1, 0xE]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x10]
	strh r0, [r2]
	ldrb r0, [r1]
	cmp r0, 0
	beq _0814A6B4
	ldr r1, =0x040000d4
	ldr r0, =0x02038c28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_0814A6B4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A684

	thumb_func_start sub_814A6CC
sub_814A6CC: @ 814A6CC
	ldr r1, =0x02038c28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000012
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_814A6CC

	thumb_func_start sub_814A6F0
sub_814A6F0: @ 814A6F0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C99F8
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A702:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A702
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A6F0

	thumb_func_start sub_814A728
sub_814A728: @ 814A728
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C9A08
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A73A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A73A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A728

	thumb_func_start sub_814A760
sub_814A760: @ 814A760
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C9A1C
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A772:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A772
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A760

	thumb_func_start sub_814A798
sub_814A798: @ 814A798
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0x10]
	bl LZ77UnCompVram
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, 0x1
	str r6, [sp]
	str r4, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1D
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_085C8578
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	movs r0, 0
	mov r1, r8
	strh r6, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	movs r0, 0xA
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A798

	thumb_func_start sub_814A828
sub_814A828: @ 814A828
	push {r4,r5,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_085C8928
	movs r2, 0x4
	str r2, [sp]
	str r2, [sp, 0x4]
	ldrb r0, [r4, 0xC]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0xE]
	str r0, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r5, 0
	str r5, [sp, 0x1C]
	str r5, [sp, 0x20]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x4
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bne _0814A88A
	movs r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x4
	strh r0, [r4, 0xE]
	strh r5, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0814A88A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814A88A:
	movs r0, 0
	add sp, 0x24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A828

	thumb_func_start sub_814A898
sub_814A898: @ 814A898
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldrh r0, [r4, 0x14]
	adds r1, r0, 0x1
	strh r1, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0814A956
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0814A8FC
	cmp r0, 0x1
	bgt _0814A8CA
	cmp r0, 0
	beq _0814A8D4
	b _0814A92C
_0814A8CA:
	cmp r0, 0x2
	beq _0814A914
	cmp r0, 0x3
	beq _0814A91C
	b _0814A92C
_0814A8D4:
	movs r2, 0xFA
	ldr r6, =0x02037714
	movs r3, 0
	ldr r5, =0x02037b14
_0814A8DC:
	lsls r1, r2, 1
	adds r0, r1, r6
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFE
	bls _0814A8DC
	b _0814A94C
	.pool
_0814A8FC:
	ldr r0, =0xffff7fff
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	ldr r0, =gUnknown_085C86F4
	b _0814A91E
	.pool
_0814A914:
	ldr r0, =gUnknown_085C87F4
	b _0814A91E
	.pool
_0814A91C:
	ldr r0, =gUnknown_085C88A4
_0814A91E:
	ldr r1, [sp, 0xC]
	bl LZ77UnCompVram
	b _0814A94C
	.pool
_0814A92C:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0814A956
_0814A94C:
	movs r0, 0
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
_0814A956:
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_814A898

	thumb_func_start sub_814A960
sub_814A960: @ 814A960
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0x10]
	bl LZ77UnCompVram
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, 0x1
	str r6, [sp]
	str r4, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1D
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r4, =gUnknown_085C8578
	adds r0, r4, 0
	movs r1, 0xE0
	movs r2, 0x20
	bl gpu_pal_apply
	adds r0, r4, 0
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	movs r0, 0xE0
	movs r1, 0x10
	movs r2, 0x8
	movs r3, 0
	bl pal_fade_1
	movs r1, 0
	movs r0, 0x22
	mov r2, r8
	strh r0, [r2, 0xC]
	strh r1, [r2, 0xE]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	movs r0, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A960

	thumb_func_start sub_814AA04
sub_814AA04: @ 814AA04
	push {r4-r6,lr}
	sub sp, 0x24
	adds r6, r0, 0
	ldr r1, =gUnknown_085C9A30
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x7
	bl __udivsi3
	ldr r1, =gUnknown_085C8928
	movs r2, 0x4
	str r2, [sp]
	str r2, [sp, 0x4]
	lsls r4, 2
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x8]
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	str r0, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	cmp r0, 0
	bge _0814AA70
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_0814AA70:
	movs r0, 0
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AA04

	thumb_func_start sub_814AA84
sub_814AA84: @ 814AA84
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xE0
	movs r1, 0x10
	movs r2, 0x3
	movs r3, 0
	bl pal_fade_1
	ldr r0, =0xffff3fff
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	movs r0, 0
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AA84

	thumb_func_start sub_814AAB8
sub_814AAB8: @ 814AAB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	adds r7, r0, 0
	ldrh r0, [r7, 0xE]
	movs r1, 0x1
	eors r0, r1
	movs r6, 0
	strh r0, [r7, 0xE]
	cmp r0, 0
	beq _0814AB2C
	ldr r0, =gUnknown_085C8928
	mov r8, r0
	movs r4, 0x4
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r5, =gUnknown_085C9A30
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x7
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	movs r2, 0xC
	ldrsh r0, [r7, r2]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	movs r0, 0xE
	str r0, [sp, 0x18]
	str r6, [sp, 0x1C]
	str r6, [sp, 0x20]
	movs r0, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	b _0814AB78
	.pool
_0814AB2C:
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0
	ble _0814AB72
	ldr r1, =gUnknown_085C9A30
	subs r0, 0x1
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 22
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x7
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 26
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl FillBgTilemapBufferRect
_0814AB72:
	ldrh r0, [r7, 0xC]
	adds r0, 0x1
	strh r0, [r7, 0xC]
_0814AB78:
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0x22
	ble _0814AB86
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
_0814AB86:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AAB8

	thumb_func_start sub_814ABA0
sub_814ABA0: @ 814ABA0
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_814ABA0

	thumb_func_start sub_814ABE4
sub_814ABE4: @ 814ABE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	ldrh r0, [r6, 0xC]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r6, 0xC]
	cmp r0, 0
	bne _0814AC24
	ldr r5, =0x02022e14
	ldrh r1, [r5]
	movs r0, 0x12
	bl SetGpuReg
	ldr r4, =0x02022e16
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	ldrh r0, [r6, 0x8]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	ldrh r0, [r6, 0xA]
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r4]
_0814AC24:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814ABE4

	thumb_func_start sub_814AC38
sub_814AC38: @ 814AC38
	push {r4-r6,lr}
	sub sp, 0x10
	adds r6, r0, 0
	movs r5, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0xC]
	bl LZ77UnCompVram
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_085C8578
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r0, =0x02022e14
	strh r5, [r0]
	ldr r4, =0x02022e16
	strh r5, [r4]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	strh r5, [r6, 0xC]
	ldr r0, =sub_814ABE4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	bl GenerateRandomNumber
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 16
	cmp r1, 0x1
	beq _0814ACE4
	cmp r1, 0x1
	bgt _0814ACC8
	cmp r1, 0
	beq _0814ACCE
	b _0814AD1C
	.pool
_0814ACC8:
	cmp r1, 0x2
	beq _0814AD00
	b _0814AD1C
_0814ACCE:
	ldr r0, =0x03005e00
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	b _0814AD2E
	.pool
_0814ACE4:
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x8]
	movs r1, 0x1
	negs r1, r1
	b _0814AD2C
	.pool
_0814AD00:
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	ldr r1, =0x0000ffff
	b _0814AD2C
	.pool
_0814AD1C:
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x8]
	movs r1, 0x1
_0814AD2C:
	strh r1, [r0, 0xA]
_0814AD2E:
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AC38

	thumb_func_start sub_814AD48
sub_814AD48: @ 814AD48
	push {r4,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_085C9A53
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, 3
	movs r0, 0x7
	ands r3, r0
	ldr r1, =gUnknown_085C8928
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	lsls r2, 2
	adds r2, 0x1
	str r2, [sp, 0x8]
	lsls r3, 2
	str r3, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	str r0, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0814ADA0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814ADA0:
	movs r0, 0
	add sp, 0x24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AD48

	thumb_func_start sub_814ADB4
sub_814ADB4: @ 814ADB4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0xffff7fff
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814ADB4

	thumb_func_start sub_814ADD8
sub_814ADD8: @ 814ADD8
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r1, =gUnknown_085C9A53
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, 3
	movs r0, 0x7
	ands r3, r0
	lsls r2, 2
	adds r2, 0x1
	lsls r3, 2
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0814AE2E
	ldr r0, =sub_814ABE4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814AE2E:
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814ADD8

	thumb_func_start sub_814AE40
sub_814AE40: @ 814AE40
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, =0x02022e14
	movs r1, 0
	strh r1, [r0]
	ldr r4, =0x02022e16
	strh r1, [r4]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	ldr r0, [r5]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AE40

	.align 2, 0 @ Don't pad with nop.
