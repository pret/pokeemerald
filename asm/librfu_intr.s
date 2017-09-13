	.include "asm/macros.inc"

	.syntax unified

	.text

	arm_func_start IntrSIO32
IntrSIO32: @ 82E3554
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	ldr r3, _082E35B4
	ldr r0, [r3]
	ldr r2, [r0]
	sub r11, r12, 0x4
	cmp r2, 0xA
	bne _082E3590
	ldr r0, [r0, 0x20]
	cmp r0, 0
	ldmdbeq r11, {r11,sp,lr}
	bxeq lr
	bl sub_82E3EB0
	ldmdb r11, {r11,sp,lr}
	bx lr
_082E3590:
	ldrb r3, [r0, 0x14]
	cmp r3, 0x1
	bne _082E35A8
	bl sio32intr_clock_master
	ldmdb r11, {r11,sp,lr}
	bx lr
_082E35A8:
	bl sio32intr_clock_slave
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E35B4: .4byte gRfuState
	arm_func_end IntrSIO32

	arm_func_start sio32intr_clock_master
sio32intr_clock_master: @ 82E35B8
	mov r12, sp
	stmdb sp!, {r4-r6,r11,r12,lr,pc}
	mov r0, 0x50
	sub r11, r12, 0x4
	bl STWI_set_timer_in_RAM
	mov r4, 0x120
	ldr r2, _082E382C
	add r4, r4, 0x4000000
	ldr lr, [r4]
	ldr r12, [r2]
	ldr r3, [r12]
	mov r6, r2
	cmp r3, 0
	bne _082E3638
	cmp lr, 0x80000000
	bne _082E36B8
	ldrb r2, [r12, 0x5]
	ldrb r3, [r12, 0x4]
	cmp r2, r3
	bhi _082E3628
	ldr r3, [r12, 0x24]
	mov r1, r2
	ldr r2, [r3, r1, lsl 2]
	str r2, [r4]
	ldrb r3, [r12, 0x5]
	add r3, r3, 0x1
	strb r3, [r12, 0x5]
	b _082E3714
_082E3628:
	mov r3, 0x1
	str r3, [r12]
	str lr, [r4]
	b _082E3714
_082E3638:
	ldr r3, [r12]
	cmp r3, 0x1
	bne _082E36C8
	mov r3, 0x99000000
	add r3, r3, 0x660000
	mov r5, 0x80000000
	and r2, lr, r5, asr 15
	cmp r2, r3
	bne _082E36B8
	mov r3, 0
	strb r3, [r12, 0x8]
	ldr r1, [r6]
	ldrb r0, [r1, 0x8]
	ldr r2, [r1, 0x28]
	str lr, [r2, r0, lsl 2]
	ldrb r3, [r1, 0x8]
	add r3, r3, 0x1
	strb r3, [r1, 0x8]
	ldr r2, [r6]
	strb lr, [r2, 0x9]
	ldr r3, [r6]
	mov r2, lr, lsr 8
	strb r2, [r3, 0x7]
	ldr r1, [r6]
	ldrb r2, [r1, 0x7]
	ldrb r3, [r1, 0x8]
	cmp r2, r3
	bcc _082E3700
	mov r3, 0x2
	str r3, [r1]
	str r5, [r4]
	b _082E3714
_082E36B8:
	bl STWI_stop_timer_in_RAM
	mov r0, 0x82
	bl STWI_set_timer_in_RAM
	b _082E3840
_082E36C8:
	ldr r3, [r12]
	cmp r3, 0x2
	bne _082E3714
	ldrb r1, [r12, 0x8]
	ldr r2, [r12, 0x28]
	str lr, [r2, r1, lsl 2]
	ldrb r3, [r12, 0x8]
	add r3, r3, 0x1
	strb r3, [r12, 0x8]
	ldr r1, [r6]
	ldrb r2, [r1, 0x7]
	ldrb r3, [r1, 0x8]
	cmp r2, r3
	bcs _082E370C
_082E3700:
	mov r3, 0x3
	str r3, [r1]
	b _082E3714
_082E370C:
	mov r3, 0x80000000
	str r3, [r4]
_082E3714:
	mov r0, 0x1
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	beq _082E3840
	mov r4, 0x128
	add r4, r4, 0x4000000
	mov r5, 0x5000
	add r3, r5, 0xB
	strh r3, [r4]
	mov r0, 0
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	beq _082E3840
	bl STWI_stop_timer_in_RAM
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x3
	bne _082E3830
	ldrb r3, [r1, 0x9]
	cmp r3, 0xA5
	cmpne r3, 0xA7
	beq _082E3788
	and r3, r3, 0xFF
	cmp r3, 0xB5
	beq _082E3788
	cmp r3, 0xB7
	bne _082E37D0
_082E3788:
	mov r1, 0x120
	add r1, r1, 0x4000000
	mov r12, 0x128
	add r12, r12, 0x4000000
	ldr r0, [r6]
	mov r3, 0
	strb r3, [r0, 0x14]
	mov r2, 0x80000000
	str r2, [r1]
	add r3, r3, 0x5000
	add r2, r3, 0x2
	strh r2, [r12]
	add r3, r3, 0x82
	strh r3, [r12]
	ldr r2, [r6]
	mov r3, 0x5
	str r3, [r2]
	b _082E3800
_082E37D0:
	cmp r3, 0xEE
	bne _082E37F0
	add r3, r5, 0x3
	strh r3, [r4]
	mov r2, 0x4
	str r2, [r1]
	strh r0, [r1, 0x12]
	b _082E3800
_082E37F0:
	add r3, r5, 0x3
	strh r3, [r4]
	mov r2, 0x4
	str r2, [r1]
_082E3800:
	ldr r2, [r6]
	mov r3, 0
	strb r3, [r2, 0x2C]
	ldr r0, [r6]
	ldr r2, [r0, 0x18]
	cmp r2, r3
	beq _082E3840
	ldrh r1, [r0, 0x12]
	ldrb r0, [r0, 0x6]
	bl sub_82E3EA8
	b _082E3840
	.align 2, 0
_082E382C: .4byte gRfuState
_082E3830:
	add r3, r5, 0x3
	strh r3, [r4]
	add r2, r5, 0x83
	strh r2, [r4]
_082E3840:
	ldmdb r11, {r4-r6,r11,sp,lr}
	bx lr
	arm_func_end sio32intr_clock_master

	arm_func_start sio32intr_clock_slave
sio32intr_clock_slave: @ 82E3848
	mov r12, sp
	stmdb sp!, {r4-r6,r11,r12,lr,pc}
	ldr r4, _082E3BF4
	mov r0, 0x64
	ldr r3, [r4]
	mov r6, 0
	strb r6, [r3, 0x10]
	sub r11, r12, 0x4
	bl STWI_set_timer_in_RAM
	mov r0, r6
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	mov r5, r4
	beq _082E3C4C
	mov r3, 0x128
	add r3, r3, 0x4000000
	mov r2, 0x5000
	add r2, r2, 0xA
	strh r2, [r3]
	mov lr, 0x120
	ldr r0, [r5]
	add lr, lr, 0x4000000
	ldr r12, [lr]
	ldr r3, [r0]
	cmp r3, 0x5
	bne _082E3978
	ldr r3, [r0, 0x28]
	mov r4, 0x1
	mov r0, 0x99000000
	str r12, [r3]
	add r0, r0, 0x660000
	ldr r2, [r5]
	mov r3, r0, lsr 16
	strb r4, [r2, 0x5]
	cmp r3, r12, lsr 16
	bne _082E3AC4
	ldr r3, [r5]
	mov r2, r12, lsr 8
	strb r2, [r3, 0x4]
	ldr r2, [r5]
	strb r12, [r2, 0x6]
	ldr r1, [r5]
	ldrb r3, [r1, 0x4]
	cmp r3, r6
	bne _082E395C
	ldrb r2, [r1, 0x6]
	sub r3, r2, 0x27
	cmp r2, 0x36
	cmpne r3, 0x2
	bhi _082E3930
	add r3, r2, 0x80
	strb r3, [r1, 0x9]
	ldr r2, [r5]
	ldrb r3, [r2, 0x9]
	ldr r1, [r2, 0x24]
	add r3, r3, r0
	b _082E39E0
_082E3930:
	ldr r2, [r1, 0x24]
	ldr r3, _082E3BF8
	str r3, [r2]
	ldr r2, [r5]
	ldrb r3, [r2, 0x6]
	sub r3, r3, 0x10
	cmp r3, 0x2D
	bhi _082E3A18
	ldr r3, [r2, 0x24]
	str r4, [r3, 0x4]
	b _082E3A24
_082E395C:
	mov r3, 0x80000000
	str r3, [lr]
	strb r4, [r1, 0x5]
	ldr r2, [r5]
	add r3, r3, 0x80000006
	str r3, [r2]
	b _082E3AD4
_082E3978:
	ldr r3, [r0]
	cmp r3, 0x6
	bne _082E3A78
	ldrb r1, [r0, 0x5]
	ldr r2, [r0, 0x28]
	str r12, [r2, r1, lsl 2]
	ldrb r3, [r0, 0x5]
	add r3, r3, 0x1
	strb r3, [r0, 0x5]
	ldr r1, [r5]
	ldrb r2, [r1, 0x4]
	ldrb r3, [r1, 0x5]
	cmp r2, r3
	bcs _082E3A6C
	ldrb r2, [r1, 0x6]
	sub r3, r2, 0x28
	cmp r2, 0x36
	cmpne r3, 0x1
	bhi _082E39F0
	add r3, r2, 0x80
	strb r3, [r1, 0x9]
	ldr r2, [r5]
	ldrb r3, [r2, 0x9]
	ldr r1, [r2, 0x24]
	orr r3, r3, 0x99000000
	orr r3, r3, 0x660000
_082E39E0:
	str r3, [r1]
	ldr r2, [r5]
	strb r6, [r2, 0x7]
	b _082E3A3C
_082E39F0:
	ldr r2, [r1, 0x24]
	ldr r3, _082E3BF8
	str r3, [r2]
	ldr r2, [r5]
	ldrb r3, [r2, 0x6]
	sub r3, r3, 0x10
	cmp r3, 0x2D
	ldrls r2, [r2, 0x24]
	movls r3, 0x1
	bls _082E3A20
_082E3A18:
	ldr r2, [r2, 0x24]
	mov r3, 0x2
_082E3A20:
	str r3, [r2, 0x4]
_082E3A24:
	ldr r2, [r5]
	mov r3, 0x1
	strb r3, [r2, 0x7]
	ldr r1, [r5]
	add r3, r3, 0x2
	strh r3, [r1, 0x12]
_082E3A3C:
	ldr r0, [r5]
	ldr r2, [r0, 0x24]
	mov r3, 0x120
	ldr r1, [r2]
	add r3, r3, 0x4000000
	str r1, [r3]
	mov r2, 0x1
	strb r2, [r0, 0x8]
	ldr r1, [r5]
	mov r3, 0x7
	str r3, [r1]
	b _082E3AD4
_082E3A6C:
	mov r3, 0x80000000
	str r3, [lr]
	b _082E3AD4
_082E3A78:
	ldr r3, [r0]
	cmp r3, 0x7
	bne _082E3AD4
	cmp r12, 0x80000000
	bne _082E3AC4
	ldrb r2, [r0, 0x7]
	ldrb r3, [r0, 0x8]
	cmp r2, r3
	movcc r3, 0x8
	strcc r3, [r0]
	bcc _082E3AD4
	ldrb r1, [r0, 0x8]
	ldr r3, [r0, 0x24]
	ldr r2, [r3, r1, lsl 2]
	str r2, [lr]
	ldrb r3, [r0, 0x8]
	add r3, r3, 0x1
	strb r3, [r0, 0x8]
	b _082E3AD4
_082E3AC4:
	bl STWI_stop_timer_in_RAM
	mov r0, 0x64
	bl STWI_set_timer_in_RAM
	b _082E3C4C
_082E3AD4:
	mov r0, 0x1
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	beq _082E3C4C
	mov r6, r5
	ldr r3, [r6]
	ldr r2, [r3]
	cmp r2, 0x8
	bne _082E3B9C
	mov r4, 0x128
	add r4, r4, 0x4000000
	mov r3, 0x5000
	add r3, r3, 0x2
	strh r3, [r4]
	bl STWI_stop_timer_in_RAM
	ldr r0, [r6]
	ldrh r3, [r0, 0x12]
	cmp r3, 0x3
	bne _082E3B48
	bl STWI_init_slave
	ldr r3, [r6]
	ldr r1, [r3, 0x1C]
	cmp r1, 0
	beq _082E3C4C
	mov r0, 0x1EC
	add r0, r0, 0x2
	bl sub_82E3EAC
	b _082E3C4C
_082E3B48:
	mov r3, 0x120
	add r3, r3, 0x4000000
	mov r1, 0
	str r1, [r3]
	mov r2, 0x5000
	strh r1, [r4]
	add r2, r2, 0x3
	strh r2, [r4]
	mov r3, 0x1
	strb r3, [r0, 0x14]
	ldr r0, [r5]
	ldr r2, [r0, 0x1C]
	str r1, [r0]
	cmp r2, r1
	beq _082E3C4C
	ldrb r3, [r0, 0x4]
	ldrb r0, [r0, 0x6]
	mov r1, r2
	orr r0, r0, r3, lsl 8
	bl sub_82E3EAC
	b _082E3C4C
_082E3B9C:
	mov r3, 0x208
	add r3, r3, 0x4000000
	mov r2, 0
	strh r2, [r3]
	mov r1, 0x100
	add r2, r1, 0x4000002
	ldrh r3, [r2]
	tst r3, 0x80
	beq _082E3C20
	ldrh r3, [r2]
	tst r3, 0x3
	bne _082E3BFC
	mov r2, 0xFF00
	add r1, r1, 0x4000000
	ldrh r3, [r1]
	add r2, r2, 0x9B
	cmp r3, r2
	bls _082E3C20
_082E3BE4:
	ldrh r3, [r1]
	cmp r3, r2
	bhi _082E3BE4
	b _082E3C20
	.align 2, 0
_082E3BF4: .4byte gRfuState
_082E3BF8: .4byte 0x996601ee
_082E3BFC:
	mov r2, 0xFF00
	add r1, r1, 0x4000000
	ldrh r3, [r1]
	add r2, r2, 0xFE
	cmp r3, r2
	bls _082E3C20
_082E3C14:
	ldrh r3, [r1]
	cmp r3, r2
	bhi _082E3C14
_082E3C20:
	mov r1, 0x128
	add r1, r1, 0x4000000
	mov r0, 0x208
	add r0, r0, 0x4000000
	mov r3, 0x5000
	add r2, r3, 0x2
	strh r2, [r1]
	add r3, r3, 0x82
	strh r3, [r1]
	mov r2, 0x1
	strh r2, [r0]
_082E3C4C:
	ldmdb r11, {r4-r6,r11,sp,lr}
	bx lr
	arm_func_end sio32intr_clock_slave

	arm_func_start handshake_wait
handshake_wait: @ 82E3C54
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	mov r1, 0x128
	add r1, r1, 0x4000000
	mov r0, r0, lsl 16
	ldr r2, _082E3CB8
	sub r11, r12, 0x4
	mov lr, r0, lsr 14
	ldr r12, [r2]
_082E3C78:
	ldrb r3, [r12, 0x10]
	and r0, r3, 0xFF
	cmp r0, 0x1
	beq _082E3CA4
	ldrh r3, [r1]
	and r3, r3, 0x4
	cmp r3, lr
	bne _082E3C78
	mov r0, 0
	ldmdb r11, {r11,sp,lr}
	bx lr
_082E3CA4:
	ldr r2, [r2]
	mov r3, 0
	strb r3, [r2, 0x10]
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E3CB8: .4byte gRfuState
	arm_func_end handshake_wait

	arm_func_start STWI_set_timer_in_RAM
STWI_set_timer_in_RAM: @ 82E3CBC
	mov r12, sp
	stmdb sp!, {r4,r5,r11,r12,lr,pc}
	mov r1, 0x208
	add r1, r1, 0x4000000
	mov r3, 0
	sub r11, r12, 0x4
	ldr r12, _082E3D74
	and lr, r0, 0xFF
	ldr r2, [r12]
	cmp lr, 0x50
	ldrb r0, [r2, 0xA]
	mov r4, r12
	mov r2, lr
	strh r3, [r1]
	mov r0, r0, lsl 2
	add r3, r3, 0x100
	add r1, r3, 0x4000000
	add r3, r3, 0x4000002
	add r5, r0, r3
	beq _082E3D44
	bgt _082E3D1C
	cmp lr, 0x32
	beq _082E3D30
	b _082E3D90
_082E3D1C:
	cmp r2, 0x64
	beq _082E3D5C
	cmp r2, 0x82
	beq _082E3D78
	b _082E3D90
_082E3D30:
	mvn r3, 0x334
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x1
	b _082E3D8C
_082E3D44:
	mov r3, 0xAE000000
	mov r3, r3, asr 20
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x2
	b _082E3D8C
_082E3D5C:
	mvn r3, 0x660
	sub r3, r3, 0x9
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x3
	b _082E3D8C
	.align 2, 0
_082E3D74: .4byte gRfuState
_082E3D78:
	mvn r3, 0x850
	sub r3, r3, 0x2
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x4
_082E3D8C:
	str r3, [r2, 0xC]
_082E3D90:
	mov r12, 0x200
	add r12, r12, 0x4000002
	mov r3, 0xC3
	strh r3, [r5]
	mov r1, 0x208
	ldr r2, [r4]
	add r1, r1, 0x4000000
	ldrb r0, [r2, 0xA]
	sub r3, r3, 0xBB
	mov r3, r3, lsl r0
	strh r3, [r12]
	mov r2, 0x1
	strh r2, [r1]
	ldmdb r11, {r4,r5,r11,sp,lr}
	bx lr
	arm_func_end STWI_set_timer_in_RAM

	arm_func_start STWI_stop_timer_in_RAM
STWI_stop_timer_in_RAM: @ 82E3DCC
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	mov r1, 0x100
	ldr lr, _082E3E18
	add r0, r1, 0x4000000
	ldr r2, [lr]
	sub r11, r12, 0x4
	ldrb r3, [r2, 0xA]
	mov r12, 0
	str r12, [r2, 0xC]
	mov r3, r3, lsl 2
	strh r12, [r3, r0]
	ldr r2, [lr]
	ldrb r3, [r2, 0xA]
	add r1, r1, 0x4000002
	mov r3, r3, lsl 2
	strh r12, [r3, r1]
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E3E18: .4byte gRfuState
	arm_func_end STWI_stop_timer_in_RAM

	arm_func_start STWI_init_slave
STWI_init_slave: @ 82E3E1C
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	ldr r0, _082E3EA4
	ldr r2, [r0]
	mov r3, 0x5
	str r3, [r2]
	mov r1, 0
	strb r1, [r2, 0x14]
	ldr r3, [r0]
	strb r1, [r3, 0x4]
	ldr r2, [r0]
	strb r1, [r2, 0x5]
	ldr r3, [r0]
	strb r1, [r3, 0x6]
	ldr r2, [r0]
	strb r1, [r2, 0x7]
	ldr r3, [r0]
	strb r1, [r3, 0x8]
	ldr r2, [r0]
	strb r1, [r2, 0x9]
	ldr r3, [r0]
	str r1, [r3, 0xC]
	sub r11, r12, 0x4
	strb r1, [r3, 0x10]
	mov r2, 0x128
	ldr r12, [r0]
	add r2, r2, 0x4000000
	strh r1, [r12, 0x12]
	mov r3, 0x5000
	strb r1, [r12, 0x15]
	add r3, r3, 0x82
	strh r3, [r2]
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E3EA4: .4byte gRfuState
	arm_func_end STWI_init_slave

	arm_func_start sub_82E3EA8
sub_82E3EA8: @ 82E3EA8
	bx r2
	arm_func_end sub_82E3EA8

	arm_func_start sub_82E3EAC
sub_82E3EAC: @ 82E3EAC
	bx r1
	arm_func_end sub_82E3EAC

	arm_func_start sub_82E3EB0
sub_82E3EB0: @ 82E3EB0
	bx r0
	arm_func_end sub_82E3EB0
