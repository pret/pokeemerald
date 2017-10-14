	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8158B30
sub_8158B30: @ 8158B30
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r6, r0, 2
	adds r6, r0
	lsls r6, 3
	adds r6, r1
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r6, 0x8]
	ldrh r0, [r1, 0x2]
	strh r0, [r6, 0xA]
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x3F
	bl BattleAnimAdjustPanning
	adds r5, r0, 0
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_80A5314
	strh r4, [r6, 0xC]
	strh r5, [r6, 0xE]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r6, 0x10]
	movs r0, 0xA
	strh r0, [r6, 0x1C]
	ldr r0, =sub_8158B98
	str r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158B30

	thumb_func_start sub_8158B98
sub_8158B98: @ 8158B98
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r5, [r4, 0xC]
	ldrb r6, [r4, 0x10]
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	bne _08158BD0
	movs r0, 0x5
	strh r0, [r4, 0x1C]
	strh r1, [r4, 0x1E]
	ldr r0, =sub_8158C04
	str r0, [r4]
	b _08158BFE
	.pool
_08158BD0:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _08158BEA
	strh r1, [r4, 0x1C]
	ldrh r0, [r4, 0x8]
	lsls r1, r5, 24
	asrs r1, 24
	bl PlaySE12WithPanning
_08158BEA:
	lsls r1, r6, 24
	asrs r1, 24
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	bl sub_80A52EC
	strh r0, [r4, 0xC]
_08158BFE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8158B98

	thumb_func_start sub_8158C04
sub_8158C04: @ 8158C04
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _08158C4C
	movs r0, 0
	strh r0, [r4, 0x1C]
	movs r0, 0x3F
	bl BattleAnimAdjustPanning
	adds r1, r0, 0
	ldrh r0, [r4, 0xA]
	lsls r1, 24
	asrs r1, 24
	bl PlaySE12WithPanning
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _08158C4C
	adds r0, r5, 0
	bl DestroyAnimSoundTask
_08158C4C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158C04

	thumb_func_start mas_80DCF38
mas_80DCF38: @ 8158C58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	str r1, [sp]
	ldrb r5, [r0, 0x4]
	ldrb r6, [r0, 0x6]
	ldrb r3, [r0, 0x8]
	mov r10, r3
	ldrb r7, [r0, 0xA]
	ldrb r1, [r0, 0xC]
	mov r9, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	bl BattleAnimAdjustPanning
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	asrs r5, 24
	adds r0, r5, 0
	bl BattleAnimAdjustPanning
	adds r5, r0, 0
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A5314
	ldr r2, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	mov r6, sp
	ldrh r6, [r6]
	strh r6, [r1, 0x8]
	strh r4, [r1, 0xA]
	strh r5, [r1, 0xC]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0xE]
	mov r0, r10
	strh r0, [r1, 0x10]
	strh r7, [r1, 0x12]
	mov r3, r9
	strh r3, [r1, 0x14]
	strh r2, [r1, 0x1C]
	strh r4, [r1, 0x1E]
	strh r3, [r1, 0x20]
	ldr r2, =sub_8158D08
	str r2, [r1]
	mov r0, r8
	bl _call_via_r2
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mas_80DCF38

	thumb_func_start sub_8158D08
sub_8158D08: @ 8158D08
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x20]
	adds r1, r0, 0x1
	strh r1, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08158D50
	movs r0, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x8]
	movs r1, 0x1E
	ldrsb r1, [r4, r1]
	bl PlaySE12WithPanning
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bne _08158D50
	adds r0, r5, 0
	bl DestroyAnimSoundTask
	b _08158D82
	.pool
_08158D50:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08158D82
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r0, [r4, 0xE]
	ldrh r1, [r4, 0x1E]
	adds r0, r1
	strh r0, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	bl sub_80A52EC
	strh r0, [r4, 0x1E]
_08158D82:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158D08

	thumb_func_start sub_8158D8C
sub_8158D8C: @ 8158D8C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning
	lsls r0, 24
	lsrs r6, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08158DD0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158DC8
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r4, [r0]
	b _08158E76
	.pool
_08158DC8:
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	b _08158E76
_08158DD0:
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0
	bne _08158DEC
	ldr r0, =gAnimBankAttacker
	ldrb r4, [r0]
	b _08158E12
	.pool
_08158DEC:
	cmp r1, 0x1
	bne _08158DFC
	ldr r0, =gAnimBankTarget
	ldrb r4, [r0]
	b _08158E12
	.pool
_08158DFC:
	cmp r1, 0x2
	bne _08158E08
	ldr r0, =gAnimBankAttacker
	b _08158E0A
	.pool
_08158E08:
	ldr r0, =gAnimBankTarget
_08158E0A:
	ldrb r1, [r0]
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r1
_08158E12:
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _08158E1E
	cmp r0, 0x3
	bne _08158E38
_08158E1E:
	adds r0, r4, 0
	bl IsAnimBankSpriteVisible
	lsls r0, 24
	cmp r0, 0
	bne _08158E38
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	b _08158E8C
	.pool
_08158E38:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08158E5C
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08158E6A
	.pool
_08158E5C:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08158E6A:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
_08158E76:
	cmp r4, 0
	beq _08158E86
	lsls r1, r6, 24
	asrs r1, 24
	adds r0, r4, 0
	movs r2, 0x3
	bl PlayCry3
_08158E86:
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08158E8C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158D8C

	thumb_func_start sub_8158E9C
sub_8158E9C: @ 8158E9C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning
	lsls r0, 24
	lsrs r5, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08158EE0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158ED8
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r4, [r0]
	b _08158F86
	.pool
_08158ED8:
	adds r0, r6, 0
	bl DestroyAnimVisualTask
	b _08158F86
_08158EE0:
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0
	bne _08158EFC
	ldr r0, =gAnimBankAttacker
	ldrb r4, [r0]
	b _08158F22
	.pool
_08158EFC:
	cmp r1, 0x1
	bne _08158F0C
	ldr r0, =gAnimBankTarget
	ldrb r4, [r0]
	b _08158F22
	.pool
_08158F0C:
	cmp r1, 0x2
	bne _08158F18
	ldr r0, =gAnimBankAttacker
	b _08158F1A
	.pool
_08158F18:
	ldr r0, =gAnimBankTarget
_08158F1A:
	ldrb r1, [r0]
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r1
_08158F22:
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _08158F2E
	cmp r0, 0x3
	bne _08158F48
_08158F2E:
	adds r0, r4, 0
	bl IsAnimBankSpriteVisible
	lsls r0, 24
	cmp r0, 0
	bne _08158F48
	adds r0, r6, 0
	bl DestroyAnimVisualTask
	b _08158FEE
	.pool
_08158F48:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08158F6C
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08158F7A
	.pool
_08158F6C:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08158F7A:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
_08158F86:
	ldr r1, =gTasks
	lsls r2, r6, 2
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3, 0x2]
	strh r1, [r0, 0x8]
	strh r4, [r0, 0xA]
	lsls r1, r5, 24
	asrs r1, 24
	strh r1, [r0, 0xC]
	adds r5, r2, 0
	cmp r4, 0
	beq _08158FE8
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	cmp r0, 0xFF
	bne _08158FC8
	adds r0, r4, 0
	movs r2, 0x9
	bl PlayCry3
	b _08158FD0
	.pool
_08158FC8:
	adds r0, r4, 0
	movs r2, 0x7
	bl PlayCry3
_08158FD0:
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8158FF4
	str r0, [r1]
	b _08158FEE
	.pool
_08158FE8:
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_08158FEE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8158E9C

	thumb_func_start sub_8158FF4
sub_8158FF4: @ 8158FF4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	mov r9, r4
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r6, [r1, 0xA]
	mov r8, r6
	ldrb r5, [r1, 0xC]
	adds r7, r5, 0
	ldrh r2, [r1, 0x1A]
	movs r3, 0x1A
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bgt _08159028
	adds r0, r2, 0x1
	strh r0, [r1, 0x1A]
	b _0815906A
	.pool
_08159028:
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0xFF
	bne _0815904E
	bl IsCryPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0815906A
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0xA
	bl PlayCry3
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	b _0815906A
_0815904E:
	bl IsCryPlaying
	lsls r0, 24
	cmp r0, 0
	bne _0815906A
	lsls r1, r7, 24
	asrs r1, 24
	mov r0, r8
	movs r2, 0x8
	bl PlayCry3
	mov r0, r9
	bl DestroyAnimVisualTask
_0815906A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8158FF4

	thumb_func_start sub_8159078
sub_8159078: @ 8159078
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0x1A]
	movs r3, 0x1A
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bgt _081590A0
	adds r0, r2, 0x1
	strh r0, [r1, 0x1A]
	b _081590B0
	.pool
_081590A0:
	bl IsCryPlaying
	lsls r0, 24
	cmp r0, 0
	bne _081590B0
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_081590B0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8159078

	thumb_func_start sub_81590B8
sub_81590B8: @ 81590B8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =gBattleAnimArgs
	ldrh r1, [r1]
	strh r1, [r0, 0x1C]
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning
	lsls r0, 24
	lsrs r5, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _081590F8
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	b _08159102
	.pool
_081590F8:
	ldr r1, =gAnimSpeciesByBanks
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
_08159102:
	ldrh r2, [r0]
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0xA]
	lsls r0, r5, 24
	asrs r0, 24
	strh r0, [r1, 0xC]
	cmp r2, 0
	beq _08159130
	ldr r0, =sub_815913C
	str r0, [r1]
	b _08159136
	.pool
_08159130:
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_08159136:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81590B8

	thumb_func_start sub_815913C
sub_815913C: @ 815913C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r6, [r0, 0xA]
	mov r8, r6
	ldrb r3, [r0, 0xC]
	adds r5, r3, 0
	movs r7, 0x1A
	ldrsh r2, [r0, r7]
	mov r12, r1
	cmp r2, 0x5
	bhi _081591DC
	lsls r0, r2, 2
	ldr r1, =_08159174
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08159174:
	.4byte _081591C2
	.4byte _081591A8
	.4byte _0815918C
	.4byte _081591A8
	.4byte _081591A8
	.4byte _081591B8
_0815918C:
	lsls r1, r5, 24
	asrs r1, 24
	mov r0, r8
	movs r2, 0x4
	bl PlayCry6
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	b _081591B0
	.pool
_081591A8:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r12
_081591B0:
	ldrh r1, [r0, 0x1A]
	adds r1, 0x1
	strh r1, [r0, 0x1A]
	b _08159204
_081591B8:
	bl IsCryPlaying
	lsls r0, 24
	cmp r0, 0
	bne _08159204
_081591C2:
	bl StopCryAndClearCrySongs
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1A]
	adds r0, 0x1
	strh r0, [r1, 0x1A]
	b _08159204
	.pool
_081591DC:
	movs r1, 0x1C
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081591F2
	lsls r1, r3, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0x6
	bl PlayCry6
	b _081591FE
_081591F2:
	lsls r1, r5, 24
	asrs r1, 24
	mov r0, r8
	movs r2, 0x6
	bl PlayCry3
_081591FE:
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_08159204:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815913C

	thumb_func_start sub_8159210
sub_8159210: @ 8159210
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimArgs
	ldrh r5, [r0]
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	bl BattleAnimAdjustPanning
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r5, 0
	bl PlaySE1WithPanning
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159210

	thumb_func_start sub_8159244
sub_8159244: @ 8159244
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimArgs
	ldrh r5, [r0]
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	bl BattleAnimAdjustPanning
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r5, 0
	bl PlaySE2WithPanning
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159244

	thumb_func_start sub_8159278
sub_8159278: @ 8159278
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gBattleAnimArgs
	ldrb r5, [r0, 0x2]
	ldrb r6, [r0, 0x4]
	ldrh r1, [r0, 0x6]
	mov r9, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl BattleAnimAdjustPanning
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	asrs r5, 24
	adds r0, r5, 0
	bl BattleAnimAdjustPanning
	adds r5, r0, 0
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A5314
	ldr r2, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r4, [r1, 0xA]
	strh r5, [r1, 0xC]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0xE]
	mov r0, r9
	strh r0, [r1, 0x12]
	strh r2, [r1, 0x1C]
	strh r4, [r1, 0x1E]
	ldr r2, =sub_8159308
	str r2, [r1]
	mov r0, r8
	bl _call_via_r2
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159278

	thumb_func_start sub_8159308
sub_8159308: @ 8159308
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r2, [r4, 0xE]
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _08159342
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	adds r0, r2, r1
	strh r0, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	bl sub_80A52EC
	strh r0, [r4, 0x1E]
_08159342:
	ldr r1, =gUnknown_02038440
	ldrh r0, [r4, 0x1E]
	strb r0, [r1]
	movs r3, 0x1E
	ldrsh r1, [r4, r3]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0815935A
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_0815935A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159308

	.align 2, 0 @ Don't pad with nop.
