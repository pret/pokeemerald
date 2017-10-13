	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start EmitGetMonData
EmitGetMonData: @ 80338B4
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r3, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitGetMonData

	thumb_func_start dp01_build_cmdbuf_x01_a_b_0
dp01_build_cmdbuf_x01_a_b_0: @ 80338D8
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r4, 0
	movs r3, 0x1
	strb r3, [r1]
	strb r5, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r4, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x01_a_b_0

	thumb_func_start EmitSetMonData
EmitSetMonData: @ 8033900
	push {r4-r6,lr}
	ldr r4, [sp, 0x10]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r3, 24
	lsrs r5, r3, 24
	ldr r0, =gUnknown_02022D10
	movs r3, 0x2
	strb r3, [r0]
	strb r1, [r0, 0x1]
	strb r2, [r0, 0x2]
	adds r1, r0, 0
	cmp r5, 0
	beq _0803392E
	adds r3, r1, 0x3
	adds r2, r5, 0
_08033920:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, 0x1
	adds r3, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _08033920
_0803392E:
	adds r2, r5, 0x3
	adds r0, r6, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitSetMonData

	thumb_func_start sub_8033940
sub_8033940: @ 8033940
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r4, r2, 24
	ldr r0, =gUnknown_02022D10
	movs r2, 0x3
	strb r2, [r0]
	strb r1, [r0, 0x1]
	strb r4, [r0, 0x2]
	adds r5, r0, 0
	cmp r4, 0
	beq _0803396C
	adds r1, r5, 0x3
	adds r2, r4, 0
_0803395E:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, 0x1
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _0803395E
_0803396C:
	adds r2, r4, 0x3
	adds r0, r6, 0
	adds r1, r5, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033940

	thumb_func_start EmitLoadMonSprite
EmitLoadMonSprite: @ 8033980
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x4
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitLoadMonSprite

	thumb_func_start EmitSwitchInAnim
EmitSwitchInAnim: @ 80339A0
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0x5
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r3, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitSwitchInAnim

	thumb_func_start EmitReturnPokeToBall
EmitReturnPokeToBall: @ 80339C4
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x6
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitReturnPokeToBall

	thumb_func_start EmitDrawTrainerPic
EmitDrawTrainerPic: @ 80339E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x7
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitDrawTrainerPic

	thumb_func_start EmitTrainerSlide
EmitTrainerSlide: @ 8033A04
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x8
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitTrainerSlide

	thumb_func_start EmitTrainerSlideBack
EmitTrainerSlideBack: @ 8033A24
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x9
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitTrainerSlideBack

	thumb_func_start EmitFaintAnimation
EmitFaintAnimation: @ 8033A44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xA
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitFaintAnimation

	thumb_func_start dp01_build_cmdbuf_x0B_B_B_B
dp01_build_cmdbuf_x0B_B_B_B: @ 8033A64
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xB
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x0B_B_B_B

	thumb_func_start dp01_build_cmdbuf_x0C_C_C_C
dp01_build_cmdbuf_x0C_C_C_C: @ 8033A84
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xC
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x0C_C_C_C

	thumb_func_start EmitBallThrow
EmitBallThrow: @ 8033AA4
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xD
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitBallThrow

	thumb_func_start sub_8033AC4
sub_8033AC4: @ 8033AC4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r1, =gUnknown_02022D10
	movs r0, 0xE
	strb r0, [r1]
	strb r4, [r1, 0x1]
	lsls r0, r4, 1
	adds r0, r4
	adds r5, r1, 0
	cmp r0, 0
	beq _08033AF2
	adds r1, r5, 0x2
	adds r3, r0, 0
_08033AE4:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _08033AE4
_08033AF2:
	lsls r2, r4, 1
	adds r2, r4
	adds r2, 0x2
	adds r0, r6, 0
	adds r1, r5, 0
	bl PrepareBufferDataTransfer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033AC4

	thumb_func_start EmitMoveAnimation
EmitMoveAnimation: @ 8033B0C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r4, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r6, [sp, 0x2C]
	mov r8, r6
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r7, =gUnknown_02022D10
	movs r0, 0
	mov r12, r0
	movs r0, 0xF
	strb r0, [r7]
	strb r1, [r7, 0x1]
	lsrs r1, 8
	strb r1, [r7, 0x2]
	strb r2, [r7, 0x3]
	strb r3, [r7, 0x4]
	movs r6, 0xFF
	lsls r6, 8
	lsrs r3, 8
	strb r3, [r7, 0x5]
	strb r4, [r7, 0x6]
	adds r0, r4, 0
	ands r0, r6
	asrs r0, 8
	strb r0, [r7, 0x7]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r4
	asrs r0, 16
	strb r0, [r7, 0x8]
	lsrs r4, 24
	strb r4, [r7, 0x9]
	strb r5, [r7, 0xA]
	mov r0, r8
	strb r0, [r7, 0xB]
	mov r0, r12
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08033BAC
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08033BAC
	ldr r0, =gBattleWeather
	ldrh r0, [r0]
	strb r0, [r7, 0xC]
	ands r6, r0
	lsrs r0, r6, 8
	strb r0, [r7, 0xD]
	adds r4, r7, 0
	b _08033BB6
	.pool
_08033BAC:
	ldr r0, =gUnknown_02022D10
	movs r1, 0
	strb r1, [r0, 0xC]
	strb r1, [r0, 0xD]
	adds r4, r0, 0
_08033BB6:
	movs r0, 0
	strb r0, [r4, 0xE]
	strb r0, [r4, 0xF]
	adds r0, r4, 0
	adds r0, 0x10
	ldr r1, [sp, 0x28]
	movs r2, 0x1C
	bl memcpy
	mov r0, r9
	adds r1, r4, 0
	movs r2, 0x2C
	bl PrepareBufferDataTransfer
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitMoveAnimation

	thumb_func_start EmitPrintString
EmitPrintString: @ 8033BE4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_02022D10
	movs r0, 0x10
	strb r0, [r2]
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	strb r0, [r2, 0x1]
	strb r1, [r2, 0x2]
	lsrs r1, 8
	strb r1, [r2, 0x3]
	adds r0, r2, 0x4
	mov r12, r0
	ldr r4, =gCurrentMove
	ldrh r0, [r4]
	strh r0, [r2, 0x4]
	ldr r0, =gLastUsedMove
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1, 0x2]
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	ldr r0, =gLastUsedAbility
	ldrb r0, [r0]
	strb r0, [r1, 0x6]
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	strb r0, [r1, 0x7]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x52
	ldrb r1, [r1]
	mov r3, r12
	strb r1, [r3, 0x8]
	adds r0, 0xB1
	ldrb r0, [r0]
	strb r0, [r3, 0x9]
	ldr r0, =gStringBank
	ldrb r0, [r0]
	strb r0, [r3, 0xA]
	ldr r3, =gBattleMoves
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	mov r7, r12
	strb r0, [r7, 0xB]
	movs r3, 0
	mov r9, r2
	ldr r0, =gBattleTextBuff3
	mov r8, r0
	adds r2, 0x10
	ldr r0, =gBattleMons
	adds r4, r0, 0
	adds r4, 0x20
_08033C6A:
	adds r1, r2, r3
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, 0x58
	adds r3, 0x1
	cmp r3, 0x3
	ble _08033C6A
	movs r3, 0
	mov r5, r12
	adds r5, 0x10
	mov r4, r12
	adds r4, 0x20
	ldr r6, =gBattleTextBuff2
	mov r2, r12
	adds r2, 0x30
_08033C88:
	adds r1, r5, r3
	ldr r7, =gBattleTextBuff1
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	mov r7, r8
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0xF
	ble _08033C88
	mov r0, r10
	mov r1, r9
	movs r2, 0x44
	bl PrepareBufferDataTransfer
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitPrintString

	thumb_func_start EmitPrintStringPlayerOnly
EmitPrintStringPlayerOnly: @ 8033CFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_02022D10
	movs r0, 0x11
	strb r0, [r2]
	strb r0, [r2, 0x1]
	strb r1, [r2, 0x2]
	lsrs r1, 8
	strb r1, [r2, 0x3]
	adds r0, r2, 0x4
	mov r12, r0
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	strh r0, [r2, 0x4]
	ldr r0, =gLastUsedMove
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1, 0x2]
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	ldr r0, =gLastUsedAbility
	ldrb r0, [r0]
	strb r0, [r1, 0x6]
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	strb r0, [r1, 0x7]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x52
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	movs r3, 0
	mov r9, r2
	ldr r7, =gBattleTextBuff3
	mov r8, r7
	mov r4, r9
	adds r4, 0x10
	ldr r0, =gBattleMons
	adds r2, r0, 0
	adds r2, 0x20
_08033D5E:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x58
	adds r3, 0x1
	cmp r3, 0x3
	ble _08033D5E
	movs r3, 0
	mov r5, r12
	adds r5, 0x10
	mov r4, r12
	adds r4, 0x20
	ldr r6, =gBattleTextBuff2
	mov r2, r12
	adds r2, 0x30
_08033D7C:
	adds r1, r5, r3
	ldr r7, =gBattleTextBuff1
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	mov r7, r8
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0xF
	ble _08033D7C
	mov r0, r10
	mov r1, r9
	movs r2, 0x44
	bl PrepareBufferDataTransfer
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitPrintStringPlayerOnly

	thumb_func_start EmitChooseAction
EmitChooseAction: @ 8033DE4
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gUnknown_02022D10
	movs r3, 0x12
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
	thumb_func_end EmitChooseAction

	thumb_func_start EmitCmd13
EmitCmd13: @ 8033E10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
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
	ldr r3, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r4, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r3, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r2, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r2, =gUnknown_02022D10
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
	ldr r3, =gUnknown_02022D10
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
	ldr r3, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r3, =gUnknown_02022D10
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
	ldr r4, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r4, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r1, =gUnknown_02022D10
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
	ldr r4, =gUnknown_02022D10
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
