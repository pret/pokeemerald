	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start EmitCmd13
EmitCmd13: @ 8033E10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x13
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitCmd13

	thumb_func_start EmitChooseMove
EmitChooseMove: @ 8033E30
	push {r4-r6,lr}
	adds r5, r3, 0
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, =gBattleBuffersTransferData
	movs r4, 0
	movs r0, 0x14
	strb r0, [r3]
	strb r1, [r3, 0x1]
	strb r2, [r3, 0x2]
	strb r4, [r3, 0x3]
	movs r2, 0
	adds r1, r3, 0
	adds r4, r1, 0x4
_08033E4C:
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	adds r2, 0x1
	cmp r2, 0x13
	bls _08033E4C
	adds r0, r6, 0
	movs r2, 0x18
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitChooseMove

	thumb_func_start EmitOpenBag
EmitOpenBag: @ 8033E6C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r0, 0x15
	strb r0, [r1]
	movs r2, 0
	adds r3, r1, 0x1
_08033E7E:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2
	ble _08033E7E
	adds r0, r5, 0
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitOpenBag

	thumb_func_start EmitChoosePokemon
EmitChoosePokemon: @ 8033EA0
	push {r4-r6,lr}
	ldr r6, [sp, 0x10]
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gBattleBuffersTransferData
	movs r0, 0x16
	strb r0, [r4]
	strb r1, [r4, 0x1]
	strb r2, [r4, 0x2]
	strb r3, [r4, 0x3]
	movs r2, 0
	adds r1, r4, 0
	adds r3, r1, 0x4
_08033EBA:
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2
	ble _08033EBA
	adds r0, r5, 0
	movs r2, 0x8
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitChoosePokemon

	thumb_func_start dp01_build_cmdbuf_x17_17_17_17
dp01_build_cmdbuf_x17_17_17_17: @ 8033EDC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x17
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x17_17_17_17

	thumb_func_start EmitHealthBarUpdate
EmitHealthBarUpdate: @ 8033EFC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gBattleBuffersTransferData
	movs r4, 0
	movs r2, 0x18
	strb r2, [r3]
	strb r4, [r3, 0x1]
	strb r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 16
	movs r2, 0xFF
	lsls r2, 8
	ands r1, r2
	asrs r1, 8
	strb r1, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitHealthBarUpdate

	thumb_func_start EmitExpUpdate
EmitExpUpdate: @ 8033F34
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gBattleBuffersTransferData
	movs r3, 0x19
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsls r2, 16
	asrs r2, 16
	movs r3, 0xFF
	lsls r3, 8
	ands r2, r3
	asrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitExpUpdate

	thumb_func_start EmitStatusIconUpdate
EmitStatusIconUpdate: @ 8033F68
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r3, 0x1A
	strb r3, [r1]
	strb r4, [r1, 0x1]
	movs r6, 0xFF
	lsls r6, 8
	adds r3, r4, 0
	ands r3, r6
	lsrs r3, 8
	strb r3, [r1, 0x2]
	movs r5, 0xFF
	lsls r5, 16
	adds r3, r4, 0
	ands r3, r5
	lsrs r3, 16
	strb r3, [r1, 0x3]
	lsrs r4, 24
	strb r4, [r1, 0x4]
	strb r2, [r1, 0x5]
	adds r3, r2, 0
	ands r3, r6
	lsrs r3, 8
	strb r3, [r1, 0x6]
	adds r3, r2, 0
	ands r3, r5
	lsrs r3, 16
	strb r3, [r1, 0x7]
	lsrs r2, 24
	strb r2, [r1, 0x8]
	movs r2, 0x9
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitStatusIconUpdate

	thumb_func_start EmitStatusAnimation
EmitStatusAnimation: @ 8033FBC
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r3, 0x1B
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	movs r3, 0xFF
	lsls r3, 8
	ands r3, r2
	lsrs r3, 8
	strb r3, [r1, 0x3]
	movs r3, 0xFF
	lsls r3, 16
	ands r3, r2
	lsrs r3, 16
	strb r3, [r1, 0x4]
	lsrs r2, 24
	strb r2, [r1, 0x5]
	movs r2, 0x6
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitStatusAnimation

	thumb_func_start dp01_build_cmdbuf_x1C_a
dp01_build_cmdbuf_x1C_a: @ 8033FF8
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x1C
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x1C_a

	thumb_func_start dp01_build_cmdbuf_x1D_1D_numargs_varargs
dp01_build_cmdbuf_x1D_1D_numargs_varargs: @ 8034018
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r1, =gBattleBuffersTransferData
	movs r0, 0x1D
	strb r0, [r1]
	strb r0, [r1, 0x1]
	strb r4, [r1, 0x2]
	lsrs r0, r4, 8
	strb r0, [r1, 0x3]
	adds r5, r1, 0
	cmp r4, 0
	beq _08034048
	adds r1, r5, 0x4
	adds r3, r4, 0
_0803403A:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _0803403A
_08034048:
	adds r2, r4, 0x4
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x1D_1D_numargs_varargs

	thumb_func_start sub_8034060
sub_8034060: @ 8034060
	push {r4-r6,lr}
	adds r4, r3, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 16
	lsrs r5, r2, 16
	ldr r2, =gBattleBuffersTransferData
	movs r0, 0x1E
	strb r0, [r2]
	strb r1, [r2, 0x1]
	movs r3, 0xFF
	lsls r3, 8
	adds r0, r1, 0
	ands r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x2]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r2, 0x3]
	lsrs r1, 24
	strb r1, [r2, 0x4]
	strb r5, [r2, 0x5]
	adds r0, r5, 0
	ands r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x6]
	adds r1, r2, 0
	cmp r5, 0
	beq _080340B0
	adds r3, r1, 0x7
	adds r2, r5, 0
_080340A2:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, 0x1
	adds r3, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _080340A2
_080340B0:
	adds r2, r5, 0x7
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034060

	thumb_func_start sub_80340C8
sub_80340C8: @ 80340C8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r1, =gBattleBuffersTransferData
	movs r0, 0x1F
	strb r0, [r1]
	strb r4, [r1, 0x1]
	lsrs r0, r4, 8
	strb r0, [r1, 0x2]
	adds r5, r1, 0
	cmp r4, 0
	beq _080340F6
	adds r1, r5, 0x3
	adds r3, r4, 0
_080340E8:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080340E8
_080340F6:
	adds r2, r4, 0x3
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80340C8

	thumb_func_start sub_8034110
sub_8034110: @ 8034110
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r1, =gBattleBuffersTransferData
	movs r0, 0x20
	strb r0, [r1]
	strb r4, [r1, 0x1]
	lsrs r0, r4, 8
	strb r0, [r1, 0x2]
	adds r5, r1, 0
	cmp r4, 0
	beq _0803413E
	adds r1, r5, 0x3
	adds r3, r4, 0
_08034130:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _08034130
_0803413E:
	adds r2, r4, 0x3
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034110

	thumb_func_start EmitCmd_x21
EmitCmd_x21: @ 8034158
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gBattleBuffersTransferData
	movs r3, 0x21
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitCmd_x21

	thumb_func_start dp01_build_cmdbuf_x22_a_three_bytes
dp01_build_cmdbuf_x22_a_three_bytes: @ 8034184
	push {r4,r5,lr}
	adds r4, r2, 0
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gBattleBuffersTransferData
	movs r0, 0x22
	strb r0, [r2]
	strb r1, [r2, 0x1]
	movs r3, 0
	adds r1, r2, 0x2
_08034198:
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x2
	ble _08034198
	adds r0, r5, 0
	adds r1, r2, 0
	movs r2, 0x5
	bl PrepareBufferDataTransfer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x22_a_three_bytes

	thumb_func_start dp01_build_cmdbuf_x23_aa_0
dp01_build_cmdbuf_x23_aa_0: @ 80341BC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gBattleBuffersTransferData
	movs r4, 0
	movs r2, 0x23
	strb r2, [r3]
	strb r1, [r3, 0x1]
	lsrs r1, 8
	strb r1, [r3, 0x2]
	strb r4, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x23_aa_0

	thumb_func_start dp01_build_cmdbuf_x24_aa_0
dp01_build_cmdbuf_x24_aa_0: @ 80341E8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gBattleBuffersTransferData
	movs r4, 0
	movs r2, 0x24
	strb r2, [r3]
	strb r1, [r3, 0x1]
	lsrs r1, 8
	strb r1, [r3, 0x2]
	strb r4, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x24_aa_0

	thumb_func_start dp01_build_cmdbuf_x25_25_25_25
dp01_build_cmdbuf_x25_25_25_25: @ 8034214
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x25
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x25_25_25_25

	thumb_func_start dp01_build_cmdbuf_x26_a
dp01_build_cmdbuf_x26_a: @ 8034234
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x26
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x26_a

	thumb_func_start dp01_build_cmdbuf_x27_27_27_27
dp01_build_cmdbuf_x27_27_27_27: @ 8034254
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x27
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x27_27_27_27

	thumb_func_start dp01_build_cmdbuf_x28_28_28_28
dp01_build_cmdbuf_x28_28_28_28: @ 8034274
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x28
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x28_28_28_28

	thumb_func_start EmitHitAnimation
EmitHitAnimation: @ 8034294
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x29
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitHitAnimation

	thumb_func_start Emit_x2A
Emit_x2A: @ 80342B4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x2A
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end Emit_x2A

	thumb_func_start EmitEffectivenessSound
EmitEffectivenessSound: @ 80342D4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gBattleBuffersTransferData
	movs r4, 0
	movs r2, 0x2B
	strb r2, [r3]
	strb r1, [r3, 0x1]
	lsrs r1, 8
	strb r1, [r3, 0x2]
	strb r4, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitEffectivenessSound

	thumb_func_start EmitPlaySound
EmitPlaySound: @ 8034300
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gBattleBuffersTransferData
	movs r3, 0x2C
	strb r3, [r4]
	strb r1, [r4, 0x1]
	lsrs r1, 8
	strb r1, [r4, 0x2]
	strb r2, [r4, 0x3]
	adds r1, r4, 0
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitPlaySound

	thumb_func_start EmitFaintingCry
EmitFaintingCry: @ 803432C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x2D
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitFaintingCry

	thumb_func_start EmitIntroSlide
EmitIntroSlide: @ 803434C
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x2E
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitIntroSlide

	thumb_func_start EmitIntroTrainerBallThrow
EmitIntroTrainerBallThrow: @ 803436C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x2F
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitIntroTrainerBallThrow

	thumb_func_start EmitDrawPartyStatusSummary
EmitDrawPartyStatusSummary: @ 803438C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gBattleBuffersTransferData
	movs r3, 0x30
	strb r3, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x1]
	movs r0, 0x80
	ands r0, r2
	lsls r0, 24
	lsrs r0, 31
	strb r0, [r1, 0x2]
	strb r3, [r1, 0x3]
	movs r2, 0
	adds r3, r1, 0x4
_080343B4:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2F
	ble _080343B4
	adds r0, r5, 0
	movs r2, 0x34
	bl PrepareBufferDataTransfer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitDrawPartyStatusSummary

	thumb_func_start EmitCmd49
EmitCmd49: @ 80343D4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x31
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitCmd49

	thumb_func_start Emit_x32
Emit_x32: @ 80343F4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x32
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end Emit_x32

	thumb_func_start EmitSpriteInvisibility
EmitSpriteInvisibility: @ 8034414
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x33
	strb r2, [r1]
	strb r3, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitSpriteInvisibility

	thumb_func_start EmitBattleAnimation
EmitBattleAnimation: @ 8034438
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gBattleBuffersTransferData
	movs r3, 0x34
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitBattleAnimation

	thumb_func_start EmitLinkStandbyMsg
EmitLinkStandbyMsg: @ 8034464
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r4, =gBattleBuffersTransferData
	movs r0, 0x35
	strb r0, [r4]
	strb r1, [r4, 0x1]
	cmp r2, 0
	beq _0803448C
	adds r0, r4, 0x4
	bl sub_81850DC
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	b _08034490
	.pool
_0803448C:
	strb r2, [r4, 0x2]
	strb r2, [r4, 0x3]
_08034490:
	ldr r1, =gBattleBuffersTransferData
	ldrb r2, [r1, 0x2]
	adds r2, 0x4
	adds r0, r5, 0
	bl PrepareBufferDataTransfer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitLinkStandbyMsg

	thumb_func_start EmitResetActionMoveSelection
EmitResetActionMoveSelection: @ 80344A8
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleBuffersTransferData
	movs r2, 0x36
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitResetActionMoveSelection

	thumb_func_start Emit_x37
Emit_x37: @ 80344C8
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gBattleBuffersTransferData
	movs r0, 0x37
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 31
	strb r0, [r4, 0x2]
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 31
	strb r0, [r4, 0x3]
	adds r0, r4, 0x6
	bl sub_81850DC
	strb r0, [r4, 0x4]
	strb r0, [r4, 0x5]
	ldrb r2, [r4, 0x4]
	adds r2, 0x6
	adds r0, r5, 0
	adds r1, r4, 0
	bl PrepareBufferDataTransfer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Emit_x37

	.align 2, 0 @ Don't pad with nop.
