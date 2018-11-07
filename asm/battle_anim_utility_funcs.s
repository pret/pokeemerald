	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8116620
sub_8116620: @ 8116620
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_811583C
	adds r6, r0, 0
	ldrh r3, [r4]
	lsls r3, 16
	asrs r0, r3, 23
	movs r4, 0x1
	ands r0, r4
	asrs r1, r3, 24
	ands r1, r4
	asrs r2, r3, 25
	ands r2, r4
	asrs r3, 26
	ands r3, r4
	bl sub_80A76C4
	orrs r6, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8116874
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116620

	thumb_func_start sub_8116664
sub_8116664: @ 8116664
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	movs r0, 0x1
	bl sub_811583C
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x7
	bhi _0811670E
	lsls r0, 2
	ldr r1, =_08116698
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08116698:
	.4byte _081166BA
	.4byte _081166C6
	.4byte _081166B8
	.4byte _081166C4
	.4byte _081166D4
	.4byte _081166EC
	.4byte _081166F4
	.4byte _08116700
_081166B8:
	movs r5, 0
_081166BA:
	mov r0, sp
	ldr r1, =gBattleAnimAttacker
	b _081166CA
	.pool
_081166C4:
	movs r5, 0
_081166C6:
	mov r0, sp
	ldr r1, =gBattleAnimTarget
_081166CA:
	ldrb r1, [r1]
	strb r1, [r0]
	b _0811670E
	.pool
_081166D4:
	mov r1, sp
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
	b _0811670E
	.pool
_081166EC:
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1]
	b _0811670E
_081166F4:
	movs r5, 0
	mov r2, sp
	ldr r0, =gBattleAnimAttacker
	b _08116706
	.pool
_08116700:
	movs r5, 0
	mov r2, sp
	ldr r0, =gBattleAnimTarget
_08116706:
	ldrb r0, [r0]
	movs r1, 0x2
	eors r0, r1
	strb r0, [r2]
_0811670E:
	movs r4, 0
	mov r6, sp
_08116712:
	ldrb r0, [r6]
	cmp r4, r0
	beq _0811673C
	ldrb r0, [r6, 0x1]
	cmp r4, r0
	beq _0811673C
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0811673C
	adds r0, r4, 0
	bl sub_80A77AC
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r0
	orrs r5, r1
_0811673C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _08116712
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_8116874
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116664

	thumb_func_start sub_811675C
sub_811675C: @ 811675C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_811583C
	adds r2, r0, 0
	ldr r0, =gBattleTerrain
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _08116832
	lsls r0, 2
	ldr r1, =_0811678C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811678C:
	.4byte _081167B4
	.4byte _081167C4
	.4byte _081167D0
	.4byte _081167E0
	.4byte _081167EC
	.4byte _081167FC
	.4byte _0811680C
	.4byte _0811681C
	.4byte _0811682C
	.4byte _0811682C
_081167B4:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00000b0c
	b _08116830
	.pool
_081167C4:
	ldr r1, =gBattleAnimArgs
	movs r0, 0x9E
	lsls r0, 4
	b _08116830
	.pool
_081167D0:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00002f1e
	b _08116830
	.pool
_081167E0:
	ldr r1, =gBattleAnimArgs
	movs r0, 0x90
	lsls r0, 7
	b _08116830
	.pool
_081167EC:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00007ecb
	b _08116830
	.pool
_081167FC:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00007ecb
	b _08116830
	.pool
_0811680C:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00002a16
	b _08116830
	.pool
_0811681C:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00000d2e
	b _08116830
	.pool
_0811682C:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00007fff
_08116830:
	strh r0, [r1, 0x8]
_08116832:
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_8116874
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811675C

	thumb_func_start AnimTask_BlendParticle
AnimTask_BlendParticle: @ 8116848
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r1, 0x1
	lsls r1, r0
	adds r0, r4, 0
	bl sub_8116874
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_BlendParticle

	thumb_func_start sub_8116874
sub_8116874: @ 8116874
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	strh r1, [r2, 0x8]
	lsrs r1, 16
	strh r1, [r2, 0xA]
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3, 0x2]
	strh r1, [r2, 0xC]
	ldrh r1, [r3, 0x4]
	strh r1, [r2, 0xE]
	ldrh r1, [r3, 0x6]
	strh r1, [r2, 0x10]
	ldrh r1, [r3, 0x8]
	strh r1, [r2, 0x12]
	ldrh r1, [r3, 0x4]
	strh r1, [r2, 0x1C]
	ldr r1, =sub_81168B8
	str r1, [r2]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116874

	thumb_func_start sub_81168B8
sub_81168B8: @ 81168B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	ldr r2, =gTasks
	lsls r5, r7, 2
	adds r0, r5, r7
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x1A]
	mov r8, r0
	movs r4, 0x1A
	ldrsh r1, [r3, r4]
	movs r4, 0xC
	ldrsh r0, [r3, r4]
	mov r9, r2
	cmp r1, r0
	bne _0811694E
	strh r6, [r3, 0x1A]
	movs r0, 0x8
	ldrsh r4, [r3, r0]
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	lsls r0, 16
	orrs r4, r0
	mov r8, r5
	cmp r4, 0
	beq _0811691A
	adds r5, r3, 0
_081168F8:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0811690C
	ldrb r2, [r5, 0x1C]
	ldrh r3, [r5, 0x12]
	adds r0, r6, 0
	movs r1, 0x10
	bl BlendPalette
_0811690C:
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	lsrs r4, 1
	cmp r4, 0
	bne _081168F8
_0811691A:
	mov r4, r8
	adds r0, r4, r7
	lsls r0, 3
	mov r1, r9
	adds r2, r0, r1
	ldrh r0, [r2, 0x1C]
	movs r4, 0x1C
	ldrsh r3, [r2, r4]
	movs r4, 0x10
	ldrsh r1, [r2, r4]
	cmp r3, r1
	bge _0811693C
	adds r0, 0x1
	strh r0, [r2, 0x1C]
	b _08116954
	.pool
_0811693C:
	cmp r3, r1
	ble _08116946
	subs r0, 0x1
	strh r0, [r2, 0x1C]
	b _08116954
_08116946:
	adds r0, r7, 0
	bl DestroyAnimVisualTask
	b _08116954
_0811694E:
	mov r0, r8
	adds r0, 0x1
	strh r0, [r3, 0x1A]
_08116954:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81168B8

	thumb_func_start sub_8116960
sub_8116960: @ 8116960
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gBattleAnimArgs
	ldrb r0, [r4]
	ldrb r1, [r4, 0x2]
	ldrb r2, [r4, 0x4]
	ldrb r3, [r4, 0x6]
	ldrb r4, [r4, 0x8]
	str r4, [sp]
	bl BeginHardwarePaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81169A0
	str r1, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116960

	thumb_func_start sub_81169A0
sub_81169A0: @ 81169A0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081169B8
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_081169B8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81169A0

	thumb_func_start sub_81169C0
sub_81169C0: @ 81169C0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	movs r3, 0
	strh r0, [r1, 0x8]
	strh r3, [r1, 0xA]
	ldrh r0, [r2, 0x2]
	strh r0, [r1, 0xC]
	ldrh r0, [r2, 0x4]
	strh r0, [r1, 0xE]
	ldrh r0, [r2, 0x6]
	strh r0, [r1, 0x10]
	strh r3, [r1, 0x12]
	ldr r0, =sub_81169F8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81169C0

	thumb_func_start sub_81169F8
sub_81169F8: @ 81169F8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08116ABC
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08116A28
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	b _08116ACA
	.pool
_08116A28:
	ldrb r0, [r4, 0x8]
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	blt _08116AA6
	ldr r6, =gSprites
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r3, r1, r6
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	movs r2, 0x2
	cmp r0, 0
	beq _08116A50
	movs r2, 0x1
_08116A50:
	lsls r2, 2
	ldrb r1, [r3, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x5]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r4, 0xE]
	strh r1, [r0, 0x2E]
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r5, [r0, 0x30]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	strh r1, [r0, 0x32]
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8116AD0
	str r1, [r0]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
_08116AA6:
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xA]
	b _08116ACA
	.pool
_08116ABC:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08116ACA
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_08116ACA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81169F8

	thumb_func_start sub_8116AD0
sub_8116AD0: @ 8116AD0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08116AE4
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
	b _08116B08
_08116AE4:
	ldr r3, =gTasks
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl obj_delete_but_dont_free_vram
_08116B08:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116AD0

	thumb_func_start sub_8116B14
sub_8116B14: @ 8116B14
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r7, 0
	ldr r0, =gBattle_WIN0H
	strh r7, [r0]
	ldr r0, =gBattle_WIN0V
	strh r7, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000c08
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0xA
	bl GetGpuReg
	add r4, sp, 0x10
	strh r0, [r4]
	ldrb r1, [r4]
	movs r0, 0x4
	negs r0, r0
	mov r8, r0
	ands r0, r1
	strb r0, [r4]
	mov r2, sp
	adds r2, 0x11
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116BA2
	ldrb r1, [r4]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
_08116BA2:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _08116C26
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116C26
	ldr r5, =gBattleAnimAttacker
	ldrb r0, [r5]
	bl GetBattlerPosition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08116BD2
	ldrb r0, [r5]
	bl GetBattlerPosition
	lsls r0, 24
	cmp r0, 0
	bne _08116C26
_08116BD2:
	ldrb r0, [r5]
	movs r6, 0x2
	eors r0, r6
	bl IsBattlerSpriteVisible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08116C26
	ldr r3, =gSprites
	ldr r1, =gBattlerSpriteIds
	ldrb r0, [r5]
	eors r0, r6
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4]
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
	movs r7, 0x1
_08116C26:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08116C64
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r5, [r0]
	b _08116CAC
	.pool
_08116C64:
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08116C90
	ldr r1, =gBattlerPartyIndexes
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08116CA0
	.pool
_08116C90:
	ldr r1, =gBattlerPartyIndexes
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08116CA0:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
_08116CAC:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A89C8
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r0, sp
	bl sub_80A6B30
	ldr r1, =gUnknown_08C20684
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C20668
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08597418
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	adds r1, 0x1
	movs r2, 0x2
	bl LoadPalette
	ldr r2, =gBattle_BG1_X
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x20]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r2]
	ldr r2, =gBattle_BG1_Y
	ldrh r0, [r1, 0x22]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r2]
	ldr r1, =gTasks
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	strh r7, [r0, 0x14]
	ldr r1, =sub_8116D64
	str r1, [r0]
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116B14

	thumb_func_start sub_8116D64
sub_8116D64: @ 8116D64
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x1C]
	adds r0, 0x4
	movs r1, 0
	mov r8, r1
	strh r0, [r5, 0x1C]
	ldr r7, =gBattle_BG1_Y
	ldrh r2, [r7]
	subs r1, r2, 0x4
	strh r1, [r7]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _08116E86
	mov r0, r8
	strh r0, [r5, 0x1C]
	adds r0, r2, 0
	adds r0, 0x3C
	strh r0, [r7]
	ldrh r0, [r5, 0x1E]
	adds r0, 0x1
	strh r0, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08116E86
	movs r0, 0
	bl sub_80A477C
	ldr r0, =gBattle_WIN0H
	mov r1, r8
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116DF6
	movs r0, 0xA
	bl GetGpuReg
	add r1, sp, 0x10
	strh r0, [r1]
	ldrb r2, [r1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrh r1, [r1]
	movs r0, 0xA
	bl SetGpuReg
_08116DF6:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl GetAnimBattlerSpriteId
	ldr r4, =gSprites
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08116E7C
	ldr r2, =gBattlerSpriteIds
	ldr r0, =gBattleAnimAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	adds r0, r2
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
_08116E7C:
	mov r2, r8
	strh r2, [r7]
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_08116E86:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116D64

	thumb_func_start sub_8116EB4
sub_8116EB4: @ 8116EB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203A110
	movs r0, 0x18
	bl AllocZeroed
	str r0, [r4]
	movs r2, 0
	ldr r3, =gBattleAnimArgs
_08116EC8:
	ldr r1, [r4]
	lsls r0, r2, 1
	adds r1, 0x4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _08116EC8
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8116F04
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116EB4

	thumb_func_start sub_8116F04
sub_8116F04: @ 8116F04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203A110
	ldr r1, [r0]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08116F24
	ldr r0, =gBattleAnimAttacker
	b _08116F26
	.pool
_08116F24:
	ldr r0, =gBattleAnimTarget
_08116F26:
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r4, =gUnknown_0203A110
	ldr r2, [r4]
	ldrb r0, [r2]
	movs r1, 0x2
	eors r0, r1
	strb r0, [r2, 0x1]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116F56
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08116F5C
	ldrb r0, [r1, 0x1]
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	bne _08116F5C
_08116F56:
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0xA]
_08116F5C:
	ldr r0, =gBattle_WIN0H
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0
	bl SetAnimBgAttribute
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116FBA
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetAnimBgAttribute
_08116FBA:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _08117036
	ldr r4, =gUnknown_0203A110
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08117036
	ldrb r0, [r1]
	bl GetBattlerPosition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08116FEC
	ldr r0, [r4]
	ldrb r0, [r0]
	bl GetBattlerPosition
	lsls r0, 24
	cmp r0, 0
	bne _08117036
_08116FEC:
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl IsBattlerSpriteVisible
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _08117036
	ldr r3, =gSprites
	ldr r1, =gBattlerSpriteIds
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	ldr r0, [r4]
	strb r5, [r0, 0x2]
_08117036:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08117078
	ldr r0, =gUnknown_0203A110
	ldr r1, [r0]
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	b _081170C4
	.pool
_08117078:
	ldr r4, =gUnknown_0203A110
	ldr r0, [r4]
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _081170A8
	ldr r1, =gBattlerPartyIndexes
	ldr r0, [r4]
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _081170BA
	.pool
_081170A8:
	ldr r1, =gBattlerPartyIndexes
	ldr r0, [r4]
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_081170BA:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	ldr r1, [r4]
_081170C4:
	strh r0, [r1, 0x14]
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81170EC
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116F04

	thumb_func_start sub_81170EC
sub_81170EC: @ 81170EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r6, =gBattlerSpriteIds
	ldr r4, =gUnknown_0203A110
	ldr r2, [r4]
	ldrb r0, [r2]
	adds r1, r0, r6
	ldrb r1, [r1]
	ldrh r2, [r2, 0x14]
	bl sub_80A89C8
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, [r4]
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0811712E
	ldrb r0, [r2, 0x1]
	adds r1, r0, r6
	ldrb r1, [r1]
	ldrh r2, [r2, 0x14]
	bl sub_80A89C8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_0811712E:
	mov r0, sp
	bl sub_80A6B30
	ldr r0, [r4]
	movs r4, 0x4
	ldrsh r0, [r0, r4]
	cmp r0, 0
	bne _08117158
	ldr r1, =gUnknown_08C2D930
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	b _08117162
	.pool
_08117158:
	ldr r1, =gUnknown_08C2DA4C
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
_08117162:
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2D720
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_0203A110
	ldr r0, [r0]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	bhi _081171F8
	lsls r0, 2
	ldr r1, =_08117198
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08117198:
	.4byte _081171B4
	.4byte _081171BC
	.4byte _081171C4
	.4byte _081171CC
	.4byte _081171D4
	.4byte _081171DC
	.4byte _081171E4
_081171B4:
	ldr r0, =gUnknown_08C2DB88
	b _081171E6
	.pool
_081171BC:
	ldr r0, =gUnknown_08C2DB68
	b _081171E6
	.pool
_081171C4:
	ldr r0, =gUnknown_08C2DBA8
	b _081171E6
	.pool
_081171CC:
	ldr r0, =gUnknown_08C2DBC8
	b _081171E6
	.pool
_081171D4:
	ldr r0, =gUnknown_08C2DC08
	b _081171E6
	.pool
_081171DC:
	ldr r0, =gUnknown_08C2DC28
	b _081171E6
	.pool
_081171E4:
	ldr r0, =gUnknown_08C2DC48
_081171E6:
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	b _08117206
	.pool
_081171F8:
	ldr r0, =gUnknown_08C2DBE8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
_08117206:
	ldr r3, =gBattle_BG1_X
	movs r2, 0
	strh r2, [r3]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
	ldr r1, =gUnknown_0203A110
	ldr r0, [r1]
	movs r4, 0x4
	ldrsh r0, [r0, r4]
	adds r4, r1, 0
	cmp r0, 0x1
	bne _08117248
	movs r0, 0x40
	strh r0, [r3]
	ldr r2, =gTasks
	lsls r3, r5, 2
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	ldr r1, =0x0000fffd
	b _08117254
	.pool
_08117248:
	ldr r2, =gTasks
	lsls r3, r5, 2
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x3
_08117254:
	strh r1, [r0, 0xA]
	ldr r0, [r4]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117274
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0xA
	strh r1, [r0, 0x10]
	movs r1, 0x14
	b _08117280
	.pool
_08117274:
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0xD
	strh r1, [r0, 0x10]
	movs r1, 0x1E
_08117280:
	strh r1, [r0, 0x12]
	adds r1, r3, r5
	lsls r1, 3
	adds r1, r2
	strh r7, [r1, 0x8]
	ldr r3, [r4]
	ldrh r0, [r3, 0xA]
	strh r0, [r1, 0xC]
	mov r4, r8
	strh r4, [r1, 0xE]
	ldrb r0, [r3, 0x2]
	strh r0, [r1, 0x14]
	ldr r2, =gBattlerSpriteIds
	ldrb r0, [r3, 0x1]
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1, 0x16]
	ldr r0, =sub_81172EC
	str r0, [r1]
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _081172CC
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning2
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xEF
	bl PlaySE12WithPanning
	b _081172E0
	.pool
_081172CC:
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning2
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xF5
	bl PlaySE12WithPanning
_081172E0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81170EC

	thumb_func_start sub_81172EC
sub_81172EC: @ 81172EC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gBattle_BG1_Y
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0xA]
	ldrh r1, [r2]
	adds r0, r1
	strh r0, [r2]
	movs r0, 0x26
	ldrsh r2, [r5, r0]
	cmp r2, 0x1
	beq _08117362
	cmp r2, 0x1
	bgt _08117320
	cmp r2, 0
	beq _0811732A
	b _08117478
	.pool
_08117320:
	cmp r2, 0x2
	beq _08117378
	cmp r2, 0x3
	beq _081173B6
	b _08117478
_0811732A:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	cmp r0, 0
	bgt _08117338
	b _08117478
_08117338:
	strh r2, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	adds r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _08117360
	b _08117478
_08117360:
	b _081173AE
_08117362:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	cmp r0, r1
	beq _08117376
	b _08117478
_08117376:
	b _081173AE
_08117378:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	cmp r0, 0
	ble _08117478
	movs r0, 0
	strh r0, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	subs r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08117478
	movs r0, 0
	bl sub_80A477C
_081173AE:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	b _08117478
_081173B6:
	ldr r0, =gBattle_WIN0H
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081173E6
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl SetAnimBgAttribute
_081173E6:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0811743A
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_0811743A:
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08117466
	movs r2, 0x16
	ldrsh r0, [r5, r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
_08117466:
	ldr r4, =gUnknown_0203A110
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_08117478:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81172EC

	thumb_func_start sub_8117494
sub_8117494: @ 8117494
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80A76C4
	adds r6, r0, 0
	movs r1, 0
	bl sub_81175C4
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	lsrs r0, r6, 16
	movs r5, 0
	strh r0, [r4, 0x24]
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r6, r0, 0
	ldr r1, =0x0000ffff
	ands r6, r1
	adds r0, r6, 0
	bl sub_81175C4
	strh r6, [r4, 0x26]
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	ldr r0, =sub_8117500
	str r0, [r4]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117494

	thumb_func_start sub_8117500
sub_8117500: @ 8117500
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _08117544
	cmp r1, 0x1
	bgt _08117528
	cmp r1, 0
	beq _0811752E
	b _081175BE
	.pool
_08117528:
	cmp r1, 0x2
	beq _081175B8
	b _081175BE
_0811752E:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _081175BE
	strh r1, [r4, 0xA]
	movs r0, 0x10
	strh r0, [r4, 0xC]
	b _081175AC
_08117544:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081175BE
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	movs r5, 0
	movs r6, 0x1
_08117560:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	asrs r0, r5
	ands r0, r6
	cmp r0, 0
	beq _0811757A
	lsls r0, r5, 20
	lsrs r0, 16
	ldrb r2, [r4, 0xC]
	movs r1, 0x10
	ldr r3, =0x0000ffff
	bl BlendPalette
_0811757A:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	asrs r0, r5
	ands r0, r6
	cmp r0, 0
	beq _0811759A
	lsls r0, r5, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	ldrb r2, [r4, 0xC]
	movs r1, 0x10
	movs r3, 0
	bl BlendPalette
_0811759A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _08117560
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081175BE
_081175AC:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081175BE
	.pool
_081175B8:
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_081175BE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8117500

	thumb_func_start sub_81175C4
sub_81175C4: @ 81175C4
	push {r4-r6,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	movs r2, 0
_081175CE:
	movs r0, 0x1
	ands r0, r3
	lsrs r4, r3, 1
	adds r5, r2, 0x1
	cmp r0, 0
	beq _081175FA
	lsls r0, r2, 20
	lsrs r2, r0, 16
	adds r0, r2, 0
	adds r0, 0x10
	cmp r2, r0
	bge _081175FA
	ldr r1, =gPlttBufferFaded
	adds r3, r0, 0
_081175EA:
	lsls r0, r2, 1
	adds r0, r1
	strh r6, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	blt _081175EA
_081175FA:
	adds r3, r4, 0
	lsls r0, r5, 16
	lsrs r2, r0, 16
	cmp r2, 0x1F
	bls _081175CE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81175C4

	thumb_func_start sub_8117610
sub_8117610: @ 8117610
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	movs r2, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r3, [r0]
	movs r5, 0x1
_08117620:
	cmp r3, r2
	beq _0811762E
	adds r1, r2, 0
	adds r1, 0x10
	adds r0, r5, 0
	lsls r0, r1
	orrs r4, r0
_0811762E:
	adds r2, 0x1
	cmp r2, 0x3
	bls _08117620
	movs r2, 0x5
	ldr r0, =gBattleAnimArgs
	adds r1, r0, 0
	adds r1, 0x8
_0811763C:
	ldrh r0, [r1]
	strh r0, [r1, 0x2]
	subs r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _0811763C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8116874
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117610

	thumb_func_start sub_8117660
sub_8117660: @ 8117660
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	bl sub_80A6DAC
	ldr r0, =sub_81176D8
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0811769C
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0811769C
	ldrh r0, [r4]
	negs r0, r0
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	negs r0, r0
	strh r0, [r4, 0x2]
_0811769C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	strh r0, [r1, 0xA]
	ldrh r0, [r2, 0x2]
	strh r0, [r1, 0xC]
	ldrh r0, [r2, 0x6]
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	adds r0, r6, 0
	bl DestroyAnimVisualTask
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117660

	thumb_func_start sub_81176D8
sub_81176D8: @ 81176D8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r3, [r1, 0xA]
	ldrh r0, [r1, 0x1C]
	adds r3, r0
	movs r4, 0
	mov r12, r4
	strh r3, [r1, 0x1C]
	ldrh r2, [r1, 0xC]
	ldrh r7, [r1, 0x1E]
	adds r2, r7
	strh r2, [r1, 0x1E]
	ldr r6, =gBattle_BG3_X
	lsls r0, r3, 16
	asrs r0, 24
	ldrh r4, [r6]
	adds r0, r4
	strh r0, [r6]
	ldr r4, =gBattle_BG3_Y
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r7, [r4]
	adds r0, r7
	strh r0, [r4]
	movs r0, 0xFF
	ands r3, r0
	strh r3, [r1, 0x1C]
	ands r2, r0
	strh r2, [r1, 0x1E]
	ldr r0, =gBattleAnimArgs
	movs r3, 0xE
	ldrsh r2, [r0, r3]
	movs r7, 0xE
	ldrsh r0, [r1, r7]
	cmp r2, r0
	bne _0811773E
	mov r0, r12
	strh r0, [r6]
	strh r0, [r4]
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r5, 0
	bl DestroyTask
_0811773E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81176D8

	thumb_func_start AnimTask_IsAttackerOpponentSide
AnimTask_IsAttackerOpponentSide: @ 8117754
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	ldr r1, =gBattleAnimArgs
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_IsAttackerOpponentSide

	thumb_func_start AnimTask_IsTargetOpponentSide
AnimTask_IsTargetOpponentSide: @ 8117780
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
	ldr r1, =gBattleAnimArgs
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_IsTargetOpponentSide

	thumb_func_start AnimTask_IsTargetPartner
AnimTask_IsTargetPartner: @ 81177AC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r5, =gBattleAnimArgs
	movs r4, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r2, [r0]
	movs r0, 0x2
	ldr r1, =gBattleAnimTarget
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bne _081177C8
	movs r4, 0x1
_081177C8:
	strh r4, [r5, 0xE]
	adds r0, r3, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_IsTargetPartner

	thumb_func_start sub_81177E4
sub_81177E4: @ 81177E4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r6, =gSprites
_081177EE:
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	cmp r4, r0
	beq _0811782C
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0811782C
	ldr r0, =gBattlerSpriteIds
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldr r1, =gBattleAnimArgs
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r3, [r1]
	ands r3, r0
	lsls r3, 2
	ldrb r0, [r2]
	movs r7, 0x5
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_0811782C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _081177EE
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81177E4

	thumb_func_start sub_8117854
sub_8117854: @ 8117854
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r1, [sp, 0x44]
	ldr r4, [sp, 0x48]
	ldr r5, [sp, 0x4C]
	ldr r6, [sp, 0x50]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x14]
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x18]
	lsls r5, 24
	lsrs r5, 24
	str r5, [sp, 0x1C]
	lsls r6, 24
	lsrs r6, 24
	mov r10, r6
	movs r0, 0
	str r0, [sp, 0x20]
	movs r0, 0x2
	adds r6, r7, 0
	eors r6, r0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081178B6
	mov r1, r8
	cmp r1, 0
	beq _081178BA
	adds r0, r6, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	bne _081178BA
_081178B6:
	movs r2, 0
	mov r8, r2
_081178BA:
	ldr r0, =gBattle_WIN0H
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0xA
	bl GetGpuReg
	add r4, sp, 0x10
	strh r0, [r4]
	ldrb r1, [r4]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	mov r2, sp
	adds r2, 0x11
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08117930
	ldrb r0, [r4]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r4]
_08117930:
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08117964
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r4, [r0]
	b _081179A2
	.pool
_08117964:
	adds r0, r7, 0
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08117988
	ldr r1, =gBattlerPartyIndexes
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08117996
	.pool
_08117988:
	ldr r1, =gBattlerPartyIndexes
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08117996:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
_081179A2:
	ldr r5, =gBattlerSpriteIds
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r0, r7, 0
	adds r2, r4, 0
	bl sub_80A89C8
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, r8
	cmp r0, 0
	beq _081179CC
	adds r0, r6, r5
	ldrb r1, [r0]
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_80A89C8
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x20]
_081179CC:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldr r1, [sp, 0x58]
	movs r2, 0
	bl sub_80A6D60
	mov r0, sp
	ldrb r0, [r0, 0x9]
	mov r1, sp
	ldrh r2, [r1, 0xA]
	ldr r1, [sp, 0x54]
	bl sub_80A6CC0
	mov r0, sp
	ldrb r1, [r0, 0x8]
	lsls r1, 4
	ldr r0, [sp, 0x5C]
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gBattle_BG1_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	ldr r1, =gTasks
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0xA]
	mov r2, sp
	ldrh r2, [r2, 0x18]
	strh r2, [r0, 0x10]
	mov r1, r10
	strh r1, [r0, 0x12]
	mov r2, sp
	ldrh r2, [r2, 0x1C]
	strh r2, [r0, 0x14]
	strh r7, [r0, 0x8]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r2, sp
	ldrh r2, [r2, 0x20]
	strh r2, [r0, 0xE]
	ldr r1, =sub_8117A60
	str r1, [r0]
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117854

	thumb_func_start sub_8117A60
sub_8117A60: @ 8117A60
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r3, r0, r1
	movs r0, 0xA
	ldrsh r2, [r3, r0]
	adds r5, r1, 0
	cmp r2, 0
	bge _08117A7E
	negs r2, r2
_08117A7E:
	ldrh r0, [r3, 0x22]
	adds r4, r0, r2
	strh r4, [r3, 0x22]
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bge _08117AA4
	ldr r2, =gBattle_BG1_Y
	lsls r1, r4, 16
	asrs r1, 24
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	b _08117AB0
	.pool
_08117AA4:
	ldr r1, =gBattle_BG1_Y
	lsls r0, r4, 16
	asrs r0, 24
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
_08117AB0:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r5
	ldrh r1, [r5, 0x22]
	movs r0, 0xFF
	ands r0, r1
	movs r2, 0
	strh r0, [r5, 0x22]
	movs r3, 0x26
	ldrsh r0, [r5, r3]
	cmp r0, 0x1
	beq _08117B1A
	cmp r0, 0x1
	bgt _08117AD8
	cmp r0, 0
	beq _08117ADE
	b _08117C0C
	.pool
_08117AD8:
	cmp r0, 0x2
	beq _08117B34
	b _08117C0C
_08117ADE:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x14
	ldrsh r1, [r5, r3]
	cmp r0, r1
	bge _08117AF2
	b _08117C0C
_08117AF2:
	strh r2, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	adds r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x20
	ldrsh r1, [r5, r0]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _08117C0C
	b _08117B2C
_08117B1A:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r5, r3]
	cmp r0, r1
	bne _08117C0C
_08117B2C:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	b _08117C0C
_08117B34:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x14
	ldrsh r1, [r5, r3]
	cmp r0, r1
	blt _08117C0C
	strh r2, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	subs r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x20
	ldrsh r4, [r5, r0]
	cmp r4, 0
	bne _08117C0C
	movs r0, 0
	bl sub_80A477C
	ldr r0, =gBattle_WIN0H
	strh r4, [r0]
	ldr r0, =gBattle_WIN0V
	strh r4, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08117BB2
	movs r0, 0xA
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	ldrb r1, [r2]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, 0xA
	bl SetGpuReg
_08117BB2:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r3, 0x8
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08117C06
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_08117C06:
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_08117C0C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117A60

	thumb_func_start AnimTask_GetBattleTerrain
AnimTask_GetBattleTerrain: @ 8117C24
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimArgs
	ldr r1, =gBattleTerrain
	ldrb r1, [r1]
	strh r1, [r2]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_GetBattleTerrain

	thumb_func_start sub_8117C44
sub_8117C44: @ 8117C44
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117C44

	thumb_func_start sub_8117C70
sub_8117C70: @ 8117C70
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gMonSpritesGfxPtr
	ldr r0, [r6]
	movs r5, 0xBE
	lsls r5, 1
	adds r0, r5
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0
	str r1, [r0]
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117C70

	thumb_func_start sub_8117CA0
sub_8117CA0: @ 8117CA0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117CE4
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08117CFC
	movs r2, 0x1
_08117CD2:
	lsrs r1, 1
	adds r4, 0x1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _08117CD2
	b _08117CFC
	.pool
_08117CE4:
	cmp r0, 0x1
	bne _08117CF0
	ldr r0, =gBattleAnimAttacker
	b _08117CF6
	.pool
_08117CF0:
	cmp r0, 0x2
	bne _08117CFC
	ldr r0, =gBattleAnimTarget
_08117CF6:
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
_08117CFC:
	ldr r0, =gMonSpritesGfxPtr
	ldr r1, [r0]
	ldr r0, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	lsls r1, r4, 5
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	movs r2, 0x20
	bl memcpy
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117CA0

	thumb_func_start sub_8117D3C
sub_8117D3C: @ 8117D3C
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117D80
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08117D98
	movs r2, 0x1
_08117D6E:
	lsrs r1, 1
	adds r4, 0x1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _08117D6E
	b _08117D98
	.pool
_08117D80:
	cmp r0, 0x1
	bne _08117D8C
	ldr r0, =gBattleAnimAttacker
	b _08117D92
	.pool
_08117D8C:
	cmp r0, 0x2
	bne _08117D98
	ldr r0, =gBattleAnimTarget
_08117D92:
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
_08117D98:
	lsls r0, r4, 5
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r2, [r1]
	ldr r1, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	movs r3, 0xBE
	lsls r3, 1
	adds r2, r3
	ldr r2, [r2]
	lsls r1, 5
	adds r1, r2
	movs r2, 0x20
	bl memcpy
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117D3C

	thumb_func_start sub_8117DD8
sub_8117DD8: @ 8117DD8
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117E1C
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08117E34
	movs r2, 0x1
_08117E0A:
	lsrs r1, 1
	adds r4, 0x1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _08117E0A
	b _08117E34
	.pool
_08117E1C:
	cmp r0, 0x1
	bne _08117E28
	ldr r0, =gBattleAnimAttacker
	b _08117E2E
	.pool
_08117E28:
	cmp r0, 0x2
	bne _08117E34
	ldr r0, =gBattleAnimTarget
_08117E2E:
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
_08117E34:
	lsls r1, r4, 5
	ldr r0, =gPlttBufferUnfaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferFaded
	adds r1, r2
	movs r2, 0x20
	bl memcpy
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117DD8

	thumb_func_start AnimTask_IsContest
AnimTask_IsContest: @ 8117E60
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08117E80
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	strh r0, [r1, 0xE]
	b _08117E84
	.pool
_08117E80:
	ldr r0, =gBattleAnimArgs
	strh r1, [r0, 0xE]
_08117E84:
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_IsContest

	thumb_func_start sub_8117E94
sub_8117E94: @ 8117E94
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimAttacker
	ldr r1, =gBattlerTarget
	ldrb r1, [r1]
	strb r1, [r2]
	ldr r2, =gBattleAnimTarget
	ldr r1, =gEffectBattler
	ldrb r1, [r1]
	strb r1, [r2]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117E94

	thumb_func_start AnimTask_IsTargetSameSide
AnimTask_IsTargetSameSide: @ 8117EC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	adds r4, r0, 0
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _08117EF8
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	b _08117EFC
	.pool
_08117EF8:
	ldr r1, =gBattleAnimArgs
	movs r0, 0
_08117EFC:
	strh r0, [r1, 0xE]
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_IsTargetSameSide

	thumb_func_start sub_8117F10
sub_8117F10: @ 8117F10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimTarget
	ldr r1, =gBattlerTarget
	ldrb r1, [r1]
	strb r1, [r2]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117F10

	thumb_func_start sub_8117F30
sub_8117F30: @ 8117F30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimAttacker
	ldr r1, =gBattlerAttacker
	ldrb r1, [r1]
	strb r1, [r2]
	ldr r2, =gBattleAnimTarget
	ldr r1, =gEffectBattler
	ldrb r1, [r1]
	strb r1, [r2]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117F30

	thumb_func_start sub_8117F60
sub_8117F60: @ 8117F60
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08117F78
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	b _08117FB4
_08117F78:
	ldr r0, =gTasks
	lsls r3, r4, 2
	adds r3, r4
	lsls r3, 3
	adds r3, r0
	ldr r0, =gBattleSpritesDataPtr
	ldr r4, [r0]
	ldr r2, =gBattleAnimAttacker
	ldrb r0, [r2]
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	strh r0, [r3, 0x8]
	ldrb r1, [r2]
	ldr r0, [r4]
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =sub_8117FD0
	str r0, [r3]
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_08117FB4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117F60

	thumb_func_start sub_8117FD0
sub_8117FD0: @ 8117FD0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _08118014
	ldr r0, =gBattleSpritesDataPtr
	ldr r1, [r0]
	ldr r0, =gBattleAnimAttacker
	ldrb r3, [r0]
	ldr r0, [r1]
	lsls r3, 2
	adds r3, r0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x8]
	movs r1, 0x1
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, 0
	bl DestroyTask
_08118014:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117FD0

	.align 2, 0
