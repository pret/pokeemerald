	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start ma1B_8073C2C
ma1B_8073C2C: @ 80A53B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleAnimScriptPtr
	mov r10, r0
	ldr r0, [r0]
	adds r1, r0, 0x1
	mov r2, r10
	str r1, [r2]
	ldrb r0, [r0, 0x1]
	mov r9, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	mov r2, r9
	orrs r2, r0
	mov r9, r2
	ldrb r4, [r1, 0x3]
	ldrb r6, [r1, 0x4]
	ldrb r7, [r1, 0x5]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimAdjustPanning
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	asrs r4, 24
	adds r0, r4, 0
	bl BattleAnimAdjustPanning
	mov r8, r0
	lsls r5, 24
	asrs r5, 24
	mov r0, r8
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	lsls r6, 24
	asrs r6, 24
	adds r0, r5, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_80A5314
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =c3_08073CEC
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	mov r2, r8
	strh r2, [r1, 0xA]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xC]
	strh r7, [r1, 0xE]
	strh r5, [r1, 0x10]
	mov r0, r9
	adds r1, r5, 0
	bl PlaySE12WithPanning
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r1, r10
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1B_8073C2C

	thumb_func_start c3_08073CEC
c3_08073CEC: @ 80A5478
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x18]
	adds r1, r0, 0x1
	strh r1, [r2, 0x18]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0xE
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _080A54FC
	strh r7, [r2, 0x18]
	ldrh r6, [r2, 0x8]
	ldrh r3, [r2, 0xA]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	movs r4, 0xC
	ldrsh r1, [r2, r4]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	strh r4, [r2, 0x10]
	cmp r1, 0
	bne _080A54C0
	lsls r2, r3, 16
	b _080A54E4
	.pool
_080A54C0:
	lsls r1, r6, 16
	lsls r0, r3, 16
	asrs r3, r0, 16
	adds r2, r0, 0
	cmp r1, r2
	bge _080A54D6
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, r3
	blt _080A54E0
	b _080A54E4
_080A54D6:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, r3
	bgt _080A54E0
	movs r7, 0x1
_080A54E0:
	cmp r7, 0
	beq _080A54F4
_080A54E4:
	lsrs r4, r2, 16
	adds r0, r5, 0
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_080A54F4:
	lsls r0, r4, 24
	asrs r0, 24
	bl SE12PanpotControl
_080A54FC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_08073CEC

	thumb_func_start sub_80A5508
sub_80A5508: @ 80A5508
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	ldr r0, =gBattleAnimScriptPtr
	mov r9, r0
	ldr r0, [r0]
	adds r1, r0, 0x1
	mov r2, r9
	str r1, [r2]
	ldrb r0, [r0, 0x1]
	mov r8, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	mov r2, r8
	orrs r2, r0
	mov r8, r2
	ldrb r4, [r1, 0x2]
	ldrb r5, [r1, 0x3]
	ldrb r6, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	mov r10, r1
	ldr r0, =c3_08073CEC
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0x8]
	lsls r5, 24
	asrs r5, 24
	strh r5, [r1, 0xA]
	lsls r6, 24
	asrs r6, 24
	strh r6, [r1, 0xC]
	mov r0, r10
	strh r0, [r1, 0xE]
	strh r4, [r1, 0x10]
	mov r0, r8
	adds r1, r4, 0
	bl PlaySE12WithPanning
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5508

	thumb_func_start sub_80A559C
sub_80A559C: @ 80A559C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleAnimScriptPtr
	mov r10, r0
	ldr r0, [r0]
	adds r1, r0, 0x1
	mov r2, r10
	str r1, [r2]
	ldrb r0, [r0, 0x1]
	mov r9, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	mov r2, r9
	orrs r2, r0
	mov r9, r2
	ldrb r4, [r1, 0x3]
	ldrb r0, [r1, 0x4]
	mov r8, r0
	ldrb r7, [r1, 0x5]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimAdjustPanning2
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	asrs r4, 24
	adds r0, r4, 0
	bl BattleAnimAdjustPanning2
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	mov r0, r8
	bl BattleAnimAdjustPanning2
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =c3_08073CEC
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsls r6, 24
	asrs r6, 24
	strh r6, [r1, 0x8]
	lsls r5, 24
	asrs r5, 24
	strh r5, [r1, 0xA]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xC]
	strh r7, [r1, 0xE]
	strh r6, [r1, 0x10]
	mov r0, r9
	adds r1, r6, 0
	bl PlaySE12WithPanning
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r2, r10
	ldr r0, [r2]
	adds r0, 0x6
	str r0, [r2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A559C

	thumb_func_start ma1C_8073ED0
ma1C_8073ED0: @ 80A565C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r6, =gBattleAnimScriptPtr
	ldr r0, [r6]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r5, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r5, r0
	ldrb r0, [r1, 0x3]
	mov r8, r0
	ldrb r2, [r1, 0x4]
	mov r9, r2
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimAdjustPanning
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80A56E4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xA]
	mov r2, r8
	strh r2, [r1, 0xC]
	mov r2, r9
	strh r2, [r1, 0xE]
	mov r2, r8
	strh r2, [r1, 0x18]
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x5
	str r0, [r6]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1C_8073ED0

	thumb_func_start sub_80A56E4
sub_80A56E4: @ 80A56E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x18]
	adds r1, r0, 0x1
	strh r1, [r2, 0x18]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _080A5732
	movs r0, 0
	strh r0, [r2, 0x18]
	ldrh r0, [r2, 0x8]
	ldrb r1, [r2, 0xA]
	ldrh r4, [r2, 0xE]
	subs r4, 0x1
	strh r4, [r2, 0xE]
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	asrs r1, 24
	bl PlaySE12WithPanning
	cmp r4, 0
	bne _080A5732
	adds r0, r5, 0
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_080A5732:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A56E4

	thumb_func_start ma1D_08073FB4
ma1D_08073FB4: @ 80A5740
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r6, =gBattleAnimScriptPtr
	ldr r0, [r6]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r5, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r5, r0
	ldrb r0, [r1, 0x3]
	mov r8, r0
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimAdjustPanning
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80A57B4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xA]
	mov r0, r8
	strh r0, [r1, 0xC]
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x4
	str r0, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1D_08073FB4

	thumb_func_start sub_80A57B4
sub_80A57B4: @ 80A57B4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0xC]
	subs r1, r0, 0x1
	strh r1, [r2, 0xC]
	lsls r0, 16
	cmp r0, 0
	bgt _080A57E8
	ldrh r0, [r2, 0x8]
	movs r1, 0xA
	ldrsb r1, [r2, r1]
	bl PlaySE12WithPanning
	adds r0, r4, 0
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_080A57E8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A57B4

	thumb_func_start sub_80A57F8
sub_80A57F8: @ 80A57F8
	push {r4-r6,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r1, [r4]
	adds r3, r1, 0x1
	str r3, [r4]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 24
	adds r6, r2, r0
	adds r0, r1, 0x5
	str r0, [r4]
	ldrb r0, [r1, 0x5]
	adds r1, 0x6
	str r1, [r4]
	cmp r0, 0
	beq _080A5842
	adds r5, r4, 0
	ldr r4, =gBattleAnimArgs
	adds r3, r0, 0
_080A582A:
	ldr r2, [r5]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r4]
	adds r2, 0x2
	str r2, [r5]
	adds r4, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _080A582A
_080A5842:
	adds r0, r6, 0
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r6
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A57F8

	thumb_func_start ma20_wait_for_something
ma20_wait_for_something: @ 80A586C
	push {r4,r5,lr}
	ldr r0, =gAnimSoundTaskCount
	ldrb r5, [r0]
	cmp r5, 0
	bne _080A58B4
	bl IsSEPlaying
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A58CC
	ldr r4, =gSoundAnimFramesToWait
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5A
	bls _080A58BA
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
	strh r5, [r4]
	b _080A58DE
	.pool
_080A58B4:
	ldr r1, =gSoundAnimFramesToWait
	movs r0, 0
	strh r0, [r1]
_080A58BA:
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
	b _080A58DE
	.pool
_080A58CC:
	ldr r0, =gSoundAnimFramesToWait
	movs r2, 0
	strh r1, [r0]
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, =gAnimFramesToWait
	strb r2, [r0]
_080A58DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma20_wait_for_something

	thumb_func_start ma21_08074164
ma21_08074164: @ 80A58F0
	push {r4-r6,lr}
	ldr r5, =gBattleAnimScriptPtr
	ldr r4, [r5]
	adds r3, r4, 0x1
	str r3, [r5]
	ldrb r2, [r4, 0x1]
	ldrb r1, [r3, 0x1]
	ldrb r0, [r3, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r0, =gBattleAnimArgs
	lsls r2, 1
	adds r2, r0
	lsls r1, 16
	asrs r1, 16
	movs r6, 0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bne _080A5938
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	adds r1, r0
	str r1, [r5]
	b _080A593E
	.pool
_080A5938:
	adds r0, r4, 0
	adds r0, 0x8
	str r0, [r5]
_080A593E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ma21_08074164

	thumb_func_start sub_80A5944
sub_80A5944: @ 80A5944
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A5978
	ldr r2, [r4]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r4]
	b _080A597E
	.pool
_080A5978:
	ldr r0, [r4]
	adds r0, 0x4
	str r0, [r4]
_080A597E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A5944

	thumb_func_start sub_80A5984
sub_80A5984: @ 80A5984
	push {r4,lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, [r0]
	ldrb r2, [r1, 0x1]
	adds r1, 0x2
	str r1, [r0]
	cmp r2, 0
	beq _080A59A0
	ldr r0, =gAnimBankTarget
	b _080A59A2
	.pool
_080A59A0:
	ldr r0, =gAnimBankAttacker
_080A59A2:
	ldrb r0, [r0]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A59D2
	cmp r4, 0
	beq _080A59BE
	cmp r4, 0x3
	bne _080A59D2
_080A59BE:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl SetAnimBgAttribute
_080A59D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5984

	thumb_func_start sub_80A59DC
sub_80A59DC: @ 80A59DC
	push {lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5A04
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl SetAnimBgAttribute
_080A5A04:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A59DC

	thumb_func_start sub_80A5A0C
sub_80A5A0C: @ 80A5A0C
	push {r4-r7,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	ldrb r6, [r0, 0x1]
	adds r0, 0x2
	str r0, [r1]
	ldr r7, =gAnimBankAttacker
	ldrb r0, [r7]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _080A5A78
	cmp r6, 0
	beq _080A5A48
	ldrb r0, [r5]
	b _080A5A4A
	.pool
_080A5A48:
	ldrb r0, [r7]
_080A5A4A:
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5A78
	cmp r4, 0
	beq _080A5A64
	cmp r4, 0x3
	bne _080A5A78
_080A5A64:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl SetAnimBgAttribute
_080A5A78:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A5A0C

	thumb_func_start ma2B_make_side_invisible
ma2B_make_side_invisible: @ 80A5A80
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5AA8
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080A5AA8:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma2B_make_side_invisible

	thumb_func_start ma2C_make_side_visible
ma2C_make_side_visible: @ 80A5ABC
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5AE6
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
_080A5AE6:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma2C_make_side_visible

	thumb_func_start sub_80A5AFC
sub_80A5AFC: @ 80A5AFC
	push {r4-r7,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	ldrb r7, [r0, 0x1]
	adds r0, 0x2
	str r0, [r1]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5BA6
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _080A5BA6
	ldr r6, =gAnimBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080A5BA6
	cmp r7, 0
	bne _080A5B54
	ldrb r0, [r6]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	b _080A5B60
	.pool
_080A5B54:
	ldrb r0, [r5]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1
_080A5B60:
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5BA6
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r2, r0, r1
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	cmp r4, 0x2
	bne _080A5B90
	ldrb r0, [r2, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r2, 0x5]
_080A5B90:
	cmp r4, 0x1
	bne _080A5BA0
	movs r0, 0
	bl sub_80A477C
	b _080A5BA6
	.pool
_080A5BA0:
	movs r0, 0x1
	bl sub_80A477C
_080A5BA6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A5AFC

	thumb_func_start sub_80A5BAC
sub_80A5BAC: @ 80A5BAC
	push {r4-r7,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	ldrb r7, [r0, 0x1]
	adds r0, 0x2
	str r0, [r1]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5C38
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _080A5C38
	ldr r6, =gAnimBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080A5C38
	cmp r7, 0
	bne _080A5C04
	ldrb r0, [r6]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	b _080A5C10
	.pool
_080A5C04:
	ldrb r0, [r5]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1
_080A5C10:
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5C38
	cmp r4, 0x2
	bne _080A5C38
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
_080A5C38:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5BAC

	thumb_func_start ma2F_stop_music
ma2F_stop_music: @ 80A5C44
	push {lr}
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma2F_stop_music

	.align 2, 0 @ Don't pad with nop.
