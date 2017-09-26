	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80EC18C
sub_80EC18C: @ 80EC18C
	push {r4,lr}
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
_080EC194:
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r1, r3, r0
	ldr r4, =0x000027cc
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080EC1C0
	cmp r0, 0x29
	beq _080EC1C0
	adds r4, 0x1
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EC1C0
	adds r0, r2, 0
	b _080EC1CC
	.pool
_080EC1C0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x17
	bls _080EC194
	movs r0, 0xFF
_080EC1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EC18C

	thumb_func_start special_0x4a
special_0x4a: @ 80EC1D4
	push {lr}
	ldr r3, =gSaveBlock1Ptr
	ldr r2, =gSpecialVar_0x8004
	ldrh r1, [r2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r3, [r3]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0x29
	bne _080EC214
	ldr r1, =0x00002b90
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080EC214
	bl sub_80EC18C
	lsls r0, 24
	lsrs r0, 24
	b _080EC216
	.pool
_080EC214:
	ldrb r0, [r2]
_080EC216:
	pop {r1}
	bx r1
	thumb_func_end special_0x4a

	thumb_func_start ResetGabbyAndTy
ResetGabbyAndTy: @ 80EC21C
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	ldr r3, =gSaveBlock1Ptr
	ldr r2, [r3]
	ldr r1, =0x00002ba4
	adds r0, r2, r1
	movs r4, 0
	mov r10, r4
	movs r1, 0
	strh r1, [r0]
	ldr r4, =0x00002ba6
	adds r0, r2, r4
	strh r1, [r0]
	adds r4, 0x2
	adds r0, r2, r4
	strh r1, [r0]
	ldr r0, =0x00002baa
	adds r1, r2, r0
	ldr r0, =0x0000ffff
	strh r0, [r1]
	adds r4, 0x6
	adds r2, r4
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	mov r9, r0
	ands r0, r1
	strb r0, [r2]
	ldr r1, [r3]
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	mov r8, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, r4
	ldrb r2, [r1]
	movs r6, 0x5
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, r4
	ldrb r2, [r1]
	movs r5, 0x9
	negs r5, r5
	adds r0, r5, 0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x1F
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r2, =0x00002baf
	adds r0, r2
	ldrb r1, [r0]
	mov r4, r9
	ands r4, r1
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldrb r1, [r0]
	mov r4, r8
	ands r4, r1
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldrb r1, [r0]
	ands r6, r1
	strb r6, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldrb r1, [r0]
	ands r5, r1
	strb r5, [r0]
	ldr r1, [r3]
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, =0x00002bac
	adds r0, r1
	mov r4, r10
	strb r4, [r0]
	ldr r0, [r3]
	adds r1, 0x1
	adds r0, r1
	strb r4, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetGabbyAndTy

	thumb_func_start GabbyAndTyBeforeInterview
GabbyAndTyBeforeInterview: @ 80EC31C
	push {r4,lr}
	ldr r3, =gSaveBlock1Ptr
	ldr r2, [r3]
	ldr r0, =gBattleResults
	mov r12, r0
	ldrh r1, [r0, 0x6]
	ldr r4, =0x00002ba4
	adds r0, r2, r4
	strh r1, [r0]
	mov r0, r12
	ldrh r1, [r0, 0x26]
	adds r4, 0x2
	adds r0, r2, r4
	strh r1, [r0]
	mov r0, r12
	ldrh r1, [r0, 0x22]
	adds r4, 0x2
	adds r0, r2, r4
	strh r1, [r0]
	ldr r0, =0x00002bad
	adds r2, r0
	ldrb r1, [r2]
	adds r0, r1, 0
	adds r4, r3, 0
	cmp r0, 0xFF
	beq _080EC354
	adds r0, r1, 0x1
	strb r0, [r2]
_080EC354:
	ldr r2, [r4]
	mov r0, r12
	ldrb r1, [r0, 0x5]
	lsls r1, 31
	ldr r0, =0x00002bae
	adds r2, r0
	lsrs r1, 31
	ldrb r3, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _080EC398
	ldr r0, [r4]
	ldr r1, =0x00002bae
	adds r0, r1
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	b _080EC3A6
	.pool
_080EC398:
	ldr r0, [r4]
	ldr r1, =0x00002bae
	adds r0, r1
	ldrb r2, [r0]
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
_080EC3A6:
	strb r1, [r0]
	mov r1, r12
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _080EC3C4
	ldr r0, [r4]
	ldr r1, =0x00002bae
	adds r0, r1
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _080EC3D2
	.pool
_080EC3C4:
	ldr r0, [r4]
	ldr r1, =0x00002bae
	adds r0, r1
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_080EC3D2:
	strb r1, [r0]
	mov r0, r12
	ldrb r1, [r0, 0x5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080EC410
	movs r1, 0
	mov r0, r12
	adds r0, 0x36
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EC410
_080EC3EC:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xA
	bhi _080EC41E
	mov r0, r12
	adds r0, 0x36
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _080EC3EC
	ldr r0, [r4]
	ldr r4, =0x00002bae
	adds r0, r4
	b _080EC416
	.pool
_080EC410:
	ldr r0, [r4]
	ldr r1, =0x00002bae
	adds r0, r1
_080EC416:
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_080EC41E:
	bl TakeTVShowInSearchOfTrainersOffTheAir
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r4, =0x00002ba8
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EC436
	movs r0, 0x1
	bl FlagSet
_080EC436:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GabbyAndTyBeforeInterview

	thumb_func_start GabbyAndTyAfterInterview
GabbyAndTyAfterInterview: @ 80EC448
	push {r4-r6,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r2, [r5]
	ldr r6, =0x00002bae
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r1, 31
	ldr r4, =0x00002baf
	adds r2, r4
	lsrs r1, 31
	ldrb r3, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r5]
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r2, r4
	movs r1, 0x2
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r5]
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r2, r4
	movs r1, 0x4
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r5]
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r2, r4
	movs r1, 0x8
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x9
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r5]
	adds r1, r6
	ldrb r0, [r1]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, =gMapHeader
	ldrb r1, [r1, 0x14]
	ldr r2, =0x00002bac
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x6
	bl IncrementGameStat
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GabbyAndTyAfterInterview

	thumb_func_start TakeTVShowInSearchOfTrainersOffTheAir
TakeTVShowInSearchOfTrainersOffTheAir: @ 80EC4E8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002bae
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end TakeTVShowInSearchOfTrainersOffTheAir

	thumb_func_start GabbyAndTyGetBattleNum
GabbyAndTyGetBattleNum: @ 80EC504
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002bad
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x5
	bls _080EC522
	ldrb r0, [r1]
	movs r1, 0x3
	bl __umodsi3
	adds r0, 0x6
	lsls r0, 24
	lsrs r0, 24
_080EC522:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GabbyAndTyGetBattleNum

	thumb_func_start IsTVShowInSearchOfTrainersAiring
IsTVShowInSearchOfTrainersAiring: @ 80EC530
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002bae
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end IsTVShowInSearchOfTrainersAiring

	thumb_func_start GabbyAndTyGetLastQuote
GabbyAndTyGetLastQuote: @ 80EC548
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r2, =0x00002baa
	adds r1, r0, r2
	ldrh r0, [r1]
	ldr r4, =0x0000ffff
	cmp r0, r4
	beq _080EC584
	ldr r0, =gStringVar1
	ldrh r1, [r1]
	bl CopyEasyChatWord
	ldr r1, [r5]
	ldr r0, =0x00002baa
	adds r1, r0
	ldrh r2, [r1]
	adds r0, r4, 0
	orrs r0, r2
	strh r0, [r1]
	movs r0, 0x1
	b _080EC586
	.pool
_080EC584:
	movs r0, 0
_080EC586:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GabbyAndTyGetLastQuote

	thumb_func_start GabbyAndTyGetLastBattleTrivia
GabbyAndTyGetLastBattleTrivia: @ 80EC58C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002baf
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080EC5AC
	movs r0, 0x1
	b _080EC5D2
	.pool
_080EC5AC:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080EC5B8
	movs r0, 0x2
	b _080EC5D2
_080EC5B8:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080EC5C4
	movs r0, 0x3
	b _080EC5D2
_080EC5C4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080EC5D0
	movs r0, 0
	b _080EC5D2
_080EC5D0:
	movs r0, 0x4
_080EC5D2:
	pop {r1}
	bx r1
	thumb_func_end GabbyAndTyGetLastBattleTrivia

	thumb_func_start GabbyAndTySetScriptVarsToFieldObjectLocalIds
GabbyAndTySetScriptVarsToFieldObjectLocalIds: @ 80EC5D8
	push {lr}
	bl GabbyAndTyGetBattleNum
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x7
	bhi _080EC6B0
	lsls r0, 2
	ldr r1, =_080EC5F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EC5F8:
	.4byte _080EC618
	.4byte _080EC62C
	.4byte _080EC640
	.4byte _080EC654
	.4byte _080EC668
	.4byte _080EC67C
	.4byte _080EC690
	.4byte _080EC6A4
_080EC618:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0xE
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0xD
	b _080EC6AE
	.pool
_080EC62C:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x6
	b _080EC6AE
	.pool
_080EC640:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x12
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x11
	b _080EC6AE
	.pool
_080EC654:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x15
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x16
	b _080EC6AE
	.pool
_080EC668:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x8
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x9
	b _080EC6AE
	.pool
_080EC67C:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x13
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x14
	b _080EC6AE
	.pool
_080EC690:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x17
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x18
	b _080EC6AE
	.pool
_080EC6A4:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0xA
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0xB
_080EC6AE:
	strh r0, [r1]
_080EC6B0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end GabbyAndTySetScriptVarsToFieldObjectLocalIds

	thumb_func_start InterviewAfter
InterviewAfter: @ 80EC6BC
	push {lr}
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _080EC724
	lsls r0, 2
	ldr r1, =_080EC6DC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EC6DC:
	.4byte _080EC6FC
	.4byte _080EC702
	.4byte _080EC708
	.4byte _080EC70E
	.4byte _080EC724
	.4byte _080EC714
	.4byte _080EC71A
	.4byte _080EC720
_080EC6FC:
	bl sub_80ED548
	b _080EC724
_080EC702:
	bl sub_80ED5B8
	b _080EC724
_080EC708:
	bl sub_80ED610
	b _080EC724
_080EC70E:
	bl TaskDummy5
	b _080EC724
_080EC714:
	bl sub_80ECF5C
	b _080EC724
_080EC71A:
	bl sub_80ED164
	b _080EC724
_080EC720:
	bl sub_80ECA38
_080EC724:
	pop {r0}
	bx r0
	thumb_func_end InterviewAfter

	thumb_func_start sub_80EC728
sub_80EC728: @ 80EC728
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r4, 0
	bl sub_80EED88
	bl sub_80ED718
	ldr r5, =gBattleResults
	ldrh r0, [r5, 0x28]
	cmp r0, 0
	bne _080EC74C
	bl sub_80EC8FC
	b _080EC888
	.pool
_080EC74C:
	bl sub_80EC8A4
	ldr r0, =0x0000ffff
	bl sub_80EFB38
	lsls r0, 24
	cmp r0, 0
	beq _080EC75E
	b _080EC888
_080EC75E:
	ldrh r1, [r5, 0x28]
	movs r0, 0xB
	muls r0, r1
	ldr r1, =gSpeciesNames
	adds r0, r1
	adds r1, r5, 0
	adds r1, 0x2A
	bl StringCompare
	cmp r0, 0
	bne _080EC776
	b _080EC888
_080EC776:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EC888
	movs r0, 0x15
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EC888
	movs r2, 0
	adds r1, r5, 0
	adds r1, 0x36
_080EC7A8:
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xA
	bls _080EC7A8
	cmp r4, 0
	bne _080EC7CA
	ldrb r1, [r5, 0x5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080EC888
_080EC7CA:
	movs r4, 0
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	movs r0, 0x15
	strb r0, [r6]
	strb r4, [r6, 0x1]
	ldrb r1, [r5, 0x5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080EC81C
	movs r4, 0x1
	movs r0, 0x1
	adds r3, r6, 0
	adds r3, 0x13
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	adds r7, r6, 0x4
	b _080EC84E
	.pool
_080EC81C:
	movs r2, 0
	ldr r0, =gLastUsedItem
	mov r12, r0
	adds r3, r6, 0
	adds r3, 0x13
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	adds r7, r6, 0x4
	adds r1, r5, 0
	adds r1, 0x36
_080EC830:
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xA
	bls _080EC830
	cmp r4, 0xFF
	bls _080EC84A
	movs r4, 0xFF
_080EC84A:
	mov r1, r12
	ldrh r0, [r1]
_080EC84E:
	strb r4, [r6, 0x12]
	strb r0, [r6, 0xF]
	mov r0, r8
	ldr r1, [r0]
	adds r0, r3, 0
	bl StringCopy
	ldr r4, =gUnknown_03005D3A
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringCopy
	adds r0, r7, 0
	bl sub_81DB604
	adds r5, r0, 0
	adds r0, r7, 0
	bl StripExtCtrlCodes
	subs r4, 0x2A
	ldrh r0, [r4, 0x28]
	strh r0, [r6, 0x10]
	adds r0, r6, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r6, 0x2]
	strb r5, [r6, 0x3]
_080EC888:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EC728

	thumb_func_start sub_80EC8A4
sub_80EC8A4: @ 80EC8A4
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002b2c
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0x19
	beq _080EC8CA
	ldr r2, =0x000027cc
	adds r0, r1, r2
	movs r1, 0x18
	bl sub_80EF910
	movs r0, 0x5
	bl GetGameStat
	strh r0, [r4, 0x6]
	movs r0, 0x19
	strb r0, [r4]
_080EC8CA:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	ldr r1, =gBattleResults
	ldrh r0, [r1, 0x28]
	strh r0, [r4, 0x4]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x8]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	strb r0, [r4, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EC8A4

	thumb_func_start sub_80EC8FC
sub_80EC8FC: @ 80EC8FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =0x0000ffff
	bl sub_80EFB38
	lsls r0, 24
	cmp r0, 0
	bne _080EC9B4
	movs r1, 0
	movs r5, 0
	ldr r2, =gUnknown_03005D46
_080EC914:
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xA
	bls _080EC914
	cmp r5, 0xFF
	bls _080EC92E
	movs r5, 0xFF
_080EC92E:
	cmp r5, 0x2
	bls _080EC9B4
	ldr r0, =gBattleOutcome
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _080EC940
	cmp r0, 0x1
	bne _080EC9B4
_080EC940:
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	ldr r6, =0x000027cc
	adds r0, r6
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EC9B4
	movs r0, 0x17
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EC9B4
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r4, [r7]
	adds r4, r0
	movs r1, 0
	movs r0, 0x17
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r1, =gBattleResults
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x20]
	strh r0, [r4, 0xE]
	strb r5, [r4, 0x10]
	mov r1, r8
	ldrb r0, [r1]
	strb r0, [r4, 0x11]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	strb r0, [r4, 0x12]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x2]
_080EC9B4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EC8FC

	thumb_func_start sub_80EC9E8
sub_80EC9E8: @ 80EC9E8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80F0020
	strb r0, [r4, 0x1E]
	lsrs r2, r0, 8
	strb r2, [r4, 0x1F]
	adds r1, r4, 0
	adds r1, 0x20
	strb r0, [r1]
	adds r1, 0x1
	strb r2, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x23
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80EC9E8

	thumb_func_start sub_80ECA10
sub_80ECA10: @ 80ECA10
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80F0020
	adds r1, r4, 0
	adds r1, 0x20
	strb r0, [r1]
	lsrs r1, r0, 8
	adds r2, r4, 0
	adds r2, 0x21
	strb r1, [r2]
	adds r2, 0x1
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x23
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80ECA10

	thumb_func_start sub_80ECA38
sub_80ECA38: @ 80ECA38
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r7, [r0]
	ldr r1, =0x00002b2c
	adds r6, r7, r1
	ldrb r1, [r6]
	cmp r1, 0x8
	bne _080ECACE
	ldr r0, =gUnknown_030060BC
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r5, =0x000027cc
	adds r4, r5
	adds r4, r7, r4
	strb r1, [r4]
	movs r0, 0x1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x14
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02039F2C
	ldrh r0, [r0]
	strb r0, [r4, 0x1C]
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r4, 0x12]
	ldrh r0, [r6, 0x2]
	strh r0, [r4, 0x2]
	ldrb r0, [r6, 0xC]
	strb r0, [r4, 0xC]
	ldrb r0, [r6, 0xD]
	strb r0, [r4, 0xD]
	ldrb r0, [r6, 0xE]
	strb r0, [r4, 0xE]
	ldrh r0, [r6, 0x10]
	strh r0, [r4, 0x10]
	ldrb r0, [r6, 0xF]
	strb r0, [r4, 0xF]
	adds r0, r4, 0x4
	ldr r2, =0x00002b30
	adds r1, r7, r2
	bl StringCopy
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x1D]
	ldrb r0, [r6, 0x1E]
	strb r0, [r4, 0x1E]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	movs r1, 0x18
	bl sub_80EF910
_080ECACE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECA38

	thumb_func_start sub_80ECB00
sub_80ECB00: @ 80ECB00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	lsls r3, 16
	lsrs r3, 16
	mov r8, r3
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFADC
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECBEC
	movs r0, 0xA
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080ECBEC
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, [r6]
	adds r4, r1, r0
	movs r0, 0xA
	strb r0, [r4]
	movs r5, 0x1
	strb r5, [r4, 0x1]
	adds r0, r4, 0x4
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080ECBA0
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080ECBA2
	strb r5, [r4, 0x18]
	b _080ECBA4
	.pool
_080ECBA0:
	movs r0, 0x2
_080ECBA2:
	strb r0, [r4, 0x18]
_080ECBA4:
	mov r0, r10
	strh r0, [r4, 0x14]
	mov r0, r9
	strh r0, [r4, 0x16]
	mov r0, r8
	strh r0, [r4, 0x2]
	lsls r0, r7, 3
	subs r0, r7
	lsls r5, r0, 2
	ldr r6, =gLinkPlayers + 8
	adds r1, r5, r6
	mov r0, sp
	bl StringCopy
	mov r0, sp
	bl StripExtCtrlCodes
	adds r0, r4, 0
	adds r0, 0xC
	mov r1, sp
	bl StringCopy
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x19]
	cmp r0, 0x1
	beq _080ECBE8
	adds r0, r6, r5
	ldrh r0, [r0, 0x12]
	cmp r0, 0x1
	bne _080ECBEA
_080ECBE8:
	movs r0, 0x1
_080ECBEA:
	strb r0, [r4, 0x1A]
_080ECBEC:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECB00

	thumb_func_start sub_80ECC04
sub_80ECC04: @ 80ECC04
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	mov r10, r0
	ldr r0, [sp, 0x44]
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x20]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r0, [r0]
	ldr r7, =0x000027cc
	adds r0, r7
	bl sub_80EFADC
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECC54
	movs r0, 0x9
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _080ECC68
_080ECC54:
	movs r0, 0
	b _080ECCEE
	.pool
_080ECC68:
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r0
	movs r0, 0x9
	strb r0, [r4]
	movs r7, 0x1
	strb r7, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0xC
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	mov r0, sp
	mov r1, r10
	bl StringCopy
	mov r0, sp
	bl StripExtCtrlCodes
	adds r0, r4, 0x4
	mov r1, sp
	bl StringCopy
	movs r0, 0x7
	ands r5, r0
	ldrb r1, [r4, 0x3]
	subs r0, 0xF
	ands r0, r1
	orrs r0, r5
	movs r1, 0x3
	ands r6, r1
	lsls r2, r6, 3
	subs r1, 0x1C
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x3]
	add r0, sp, 0x20
	ldrb r0, [r0]
	strb r0, [r4, 0x2]
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x14]
	cmp r0, 0x1
	beq _080ECCDA
	mov r1, r9
	cmp r1, 0x1
	bne _080ECCE8
_080ECCDA:
	strb r7, [r4, 0x15]
	b _080ECCEC
	.pool
_080ECCE8:
	mov r2, r9
	strb r2, [r4, 0x15]
_080ECCEC:
	movs r0, 0x1
_080ECCEE:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ECC04

	thumb_func_start sub_80ECD00
sub_80ECD00: @ 80ECD00
	push {r4-r6,lr}
	sub sp, 0x20
	ldr r6, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8006
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r6]
	adds r4, r1, r0
	ldr r0, =gSpecialVar_0x8005
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	strb r0, [r4, 0x16]
	adds r0, r4, 0x2
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	movs r0, 0xB
	strb r0, [r4]
	movs r5, 0x1
	strb r5, [r4, 0x1]
	bl sub_80F0020
	strb r0, [r4, 0xA]
	lsrs r0, 8
	strb r0, [r4, 0xB]
	ldr r1, =gStringVar1
	mov r0, sp
	bl StringCopy
	mov r0, sp
	bl StripExtCtrlCodes
	adds r0, r4, 0
	adds r0, 0xC
	mov r1, sp
	bl StringCopy
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x17]
	cmp r0, 0x1
	beq _080ECD74
	ldr r0, [r6]
	ldr r1, =0x000031a0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080ECD98
_080ECD74:
	strb r5, [r4, 0x18]
	b _080ECD9A
	.pool
_080ECD98:
	strb r0, [r4, 0x18]
_080ECD9A:
	add sp, 0x20
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80ECD00

	thumb_func_start sub_80ECDA4
sub_80ECDA4: @ 80ECDA4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x000027cc
	adds r0, r4
	movs r1, 0x18
	bl sub_80EF910
	ldr r0, [r5]
	adds r0, r4
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECDDC
	ldr r0, [r5]
	ldr r1, =0x00002b2c
	adds r0, r1
	strb r6, [r0, 0xD]
	movs r1, 0x8
	strb r1, [r0]
_080ECDDC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECDA4

	thumb_func_start sub_80ECDF4
sub_80ECDF4: @ 80ECDF4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002b2c
	adds r4, r0, r1
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECE1C
	strb r5, [r4, 0xE]
_080ECE1C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECDF4

	thumb_func_start sub_80ECE34
sub_80ECE34: @ 80ECE34
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002b2c
	adds r4, r0, r1
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECE5C
	strb r5, [r4, 0xF]
_080ECE5C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECE34

	thumb_func_start sub_80ECE74
sub_80ECE74: @ 80ECE74
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002b2c
	adds r4, r0, r1
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECE9C
	strh r5, [r4, 0x10]
_080ECE9C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECE74

	thumb_func_start sub_80ECEB4
sub_80ECEB4: @ 80ECEB4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00002b2c
	adds r5, r4, r0
	ldr r1, =0x000027cc
	adds r0, r4, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ECF4C
	ldr r2, =gUnknown_02039E00
	lsls r1, r6, 6
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r5, 0x2]
	ldr r0, =0x00002b30
	adds r4, r0
	adds r2, 0xD
	adds r1, r2
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	bl StripExtCtrlCodes
	strb r7, [r5, 0xC]
	adds r1, r6, 0x1
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r1, r0
	ble _080ECF30
	ldr r0, =gLinkPlayers
	ldrh r0, [r0, 0x1A]
	b _080ECF4A
	.pool
_080ECF30:
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080ECF48
	ldr r1, =gLinkPlayers
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x1A]
	cmp r0, 0x1
	bne _080ECF4A
_080ECF48:
	movs r0, 0x1
_080ECF4A:
	strb r0, [r5, 0x1E]
_080ECF4C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECEB4

	thumb_func_start sub_80ECF5C
sub_80ECF5C: @ 80ECF5C
	push {r4-r7,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r6, [r0]
	ldr r0, =0x00002b2c
	adds r5, r6, r0
	ldrb r2, [r5]
	cmp r2, 0x6
	bne _080ED02C
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	adds r4, r6, r0
	strb r2, [r4]
	movs r7, 0x1
	strb r7, [r4, 0x1]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x2]
	adds r0, r4, 0
	adds r0, 0x16
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	adds r0, 0x8
	ldr r2, =0x00002b34
	adds r1, r6, r2
	bl StringCopy
	ldrb r0, [r5, 0x13]
	lsls r0, 29
	lsrs r0, 29
	ldrb r2, [r4, 0x13]
	movs r3, 0x8
	negs r3, r3
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x13]
	ldrb r2, [r5, 0x13]
	movs r0, 0x18
	ands r0, r2
	movs r2, 0x19
	negs r2, r2
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, 0x13]
	ldrh r0, [r5, 0x14]
	strh r0, [r4, 0x14]
	ldrb r0, [r5, 0x13]
	movs r1, 0x60
	ands r1, r0
	movs r0, 0x61
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x13]
	ldrb r1, [r5, 0x13]
	lsls r1, 29
	lsrs r1, 29
	ands r0, r3
	orrs r0, r1
	strb r0, [r4, 0x13]
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x1E]
	cmp r0, 0x1
	beq _080ECFFA
	ldrb r0, [r5, 0x1F]
	cmp r0, 0x1
	bne _080ED01C
_080ECFFA:
	strb r7, [r4, 0x1F]
	b _080ED01E
	.pool
_080ED01C:
	strb r0, [r4, 0x1F]
_080ED01E:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	movs r1, 0x18
	bl sub_80EF910
_080ED02C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ECF5C

	thumb_func_start sub_80ED03C
sub_80ED03C: @ 80ED03C
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00002b2c
	adds r5, r0, r1
	bl sub_80EF7B4
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ED07A
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	movs r1, 0x18
	bl sub_80EF910
	strh r6, [r5, 0x14]
	movs r0, 0x6
	strb r0, [r5]
_080ED07A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED03C

	thumb_func_start sub_80ED090
sub_80ED090: @ 80ED090
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00002b2c
	adds r7, r4, r0
	ldr r1, =0x000027cc
	adds r0, r4, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ED134
	movs r3, 0x3
	adds r0, r5, 0
	ands r0, r3
	lsls r0, 5
	ldrb r1, [r7, 0x13]
	movs r2, 0x61
	negs r2, r2
	ands r2, r1
	orrs r2, r0
	strb r2, [r7, 0x13]
	ldr r0, =gUnknown_02039F2C
	ldrb r0, [r0]
	movs r1, 0x7
	ands r1, r0
	movs r0, 0x8
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x13]
	ldr r1, =gUnknown_02039F2E
	ldrb r1, [r1]
	ands r3, r1
	lsls r3, 3
	movs r1, 0x19
	negs r1, r1
	ands r0, r1
	orrs r0, r3
	strb r0, [r7, 0x13]
	ldr r0, =gUnknown_02039F24
	mov r8, r0
	ldrb r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x2]
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r6
	adds r0, r5
	ldr r1, =0x00002b34
	adds r4, r1
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	adds r0, r4, 0
	bl StripExtCtrlCodes
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3
	bl GetMonData
	strb r0, [r7, 0x1F]
_080ED134:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED090

	thumb_func_start sub_80ED164
sub_80ED164: @ 80ED164
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	movs r0, 0x7
	strb r0, [r6]
	movs r0, 0x1
	strb r0, [r6, 0x1]
	adds r0, r6, 0x2
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	bl StringCopy
	adds r0, r6, 0
	adds r0, 0xC
	ldr r1, [r4]
	ldr r2, =0x00000bd8
	adds r1, r2
	bl StringCopy
	ldr r1, [r4]
	ldr r2, =0x00000bd4
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r6, 0xA]
	adds r2, 0x2
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r6, 0x14]
	ldr r5, =0x00000d07
	adds r1, r5
	ldrb r0, [r1]
	movs r1, 0
	bl sub_8164FCC
	strh r0, [r6, 0x16]
	ldr r0, [r4]
	ldr r1, =0x00000d06
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r6, 0x1C]
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080ED1F4
	movs r0, 0x32
	b _080ED1F6
	.pool
_080ED1F4:
	movs r0, 0x64
_080ED1F6:
	strb r0, [r6, 0x1A]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	strb r0, [r6, 0x1B]
	adds r0, r6, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r6, 0x1D]
	cmp r0, 0x1
	beq _080ED21C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000beb
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080ED21E
_080ED21C:
	movs r0, 0x1
_080ED21E:
	strb r0, [r6, 0x1E]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED164

	thumb_func_start SaveRecordedItemPurchasesForTVShow
@ void SaveRecordedItemPurchasesForTVShow()
SaveRecordedItemPurchasesForTVShow: @ 80ED238
	push {r4-r7,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00003c1a
	cmp r1, r0
	beq _080ED2F2
	ldr r0, =0x0000371a
	cmp r1, r0
	beq _080ED2F2
	ldr r0, =0x00005555
	bl sub_80EFB38
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080ED2F2
	ldr r0, [r5]
	ldr r7, =0x000027cc
	adds r0, r7
	bl sub_80EFB08
	ldr r6, =gUnknown_030060BC
	strb r0, [r6]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ED2F2
	movs r0, 0x16
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080ED2F2
	bl sub_80EF500
	ldr r2, =gUnknown_02039F80
	ldrh r0, [r2, 0x2]
	cmp r0, 0x13
	bls _080ED2F2
	movs r1, 0
	ldrsb r1, [r6, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, [r5]
	adds r5, r1, r0
	movs r0, 0x16
	strb r0, [r5]
	strb r4, [r5, 0x1]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	strb r0, [r5, 0x12]
	movs r4, 0
	adds r7, r5, 0x6
	mov r12, r2
	adds r6, r5, 0
	adds r6, 0xC
_080ED2B6:
	lsls r2, r4, 1
	adds r3, r7, r2
	lsls r1, r4, 2
	add r1, r12
	ldrh r0, [r1]
	strh r0, [r3]
	adds r2, r6, r2
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080ED2B6
	movs r0, 0x1
	bl GetPriceReduction
	strb r0, [r5, 0x2]
	adds r0, r5, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r5, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r5, 0x3]
_080ED2F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SaveRecordedItemPurchasesForTVShow

	thumb_func_start sub_80ED320
sub_80ED320: @ 80ED320
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	bl sub_80EF7A8
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080ED400
	ldr r0, =gSpecialVar_0x8004
	mov r8, r0
	ldrh r0, [r0]
	movs r7, 0x64
	muls r0, r7
	ldr r6, =gPlayerParty
	adds r0, r6
	ldr r4, =gStringVar1
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	ldr r1, =gSaveBlock2Ptr
	mov r9, r1
	ldr r0, [r1]
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080ED400
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080ED400
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r2]
	adds r4, r0
	movs r0, 0x5
	strb r0, [r4]
	movs r5, 0x1
	strb r5, [r4, 0x1]
	mov r2, r8
	ldrh r0, [r2]
	muls r0, r7
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r4, 0x2]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	strb r0, [r4, 0x1A]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ands r0, r5
	strb r0, [r4, 0x1B]
	ldrh r0, [r4, 0x2]
	bl sub_80EFA24
	strh r0, [r4, 0x1C]
	adds r0, r4, 0
	adds r0, 0xF
	mov r2, r9
	ldr r1, [r2]
	bl StringCopy
	mov r1, r8
	ldrh r0, [r1]
	muls r0, r7
	adds r0, r6
	adds r5, r4, 0x4
	movs r1, 0x2
	adds r2, r5, 0
	bl GetMonData
	adds r0, r5, 0
	bl StripExtCtrlCodes
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x1E]
	mov r2, r8
	ldrh r0, [r2]
	muls r0, r7
	adds r0, r6
	movs r1, 0x3
	bl GetMonData
	strb r0, [r4, 0x1F]
_080ED400:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED320

	thumb_func_start StartMassOutbreak
StartMassOutbreak: @ 80ED430
	push {r4,r5,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =0x000027cc
	adds r1, r0
	ldr r2, [r4]
	adds r1, r2, r1
	ldrh r3, [r1, 0xC]
	ldr r5, =0x00002b90
	adds r0, r2, r5
	strh r3, [r0]
	ldrb r0, [r1, 0x10]
	ldr r3, =0x00002b92
	adds r2, r3
	strb r0, [r2]
	ldr r0, [r4]
	ldrb r2, [r1, 0x11]
	adds r5, 0x3
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r4]
	ldrb r2, [r1, 0x14]
	adds r3, 0x2
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	ldrb r2, [r1, 0x2]
	adds r5, 0x2
	adds r0, r5
	strb r2, [r0]
	ldr r2, [r4]
	ldrh r3, [r1, 0xE]
	adds r5, 0x1
	adds r0, r2, r5
	strh r3, [r0]
	ldrh r3, [r1, 0x4]
	adds r5, 0x2
	adds r0, r2, r5
	strh r3, [r0]
	ldrh r3, [r1, 0x6]
	adds r5, 0x2
	adds r0, r2, r5
	strh r3, [r0]
	ldrh r3, [r1, 0x8]
	adds r5, 0x2
	adds r0, r2, r5
	strh r3, [r0]
	ldrh r3, [r1, 0xA]
	adds r5, 0x2
	adds r0, r2, r5
	strh r3, [r0]
	ldrb r0, [r1, 0x3]
	ldr r3, =0x00002ba0
	adds r2, r3
	strb r0, [r2]
	ldr r0, [r4]
	ldrb r1, [r1, 0x13]
	adds r5, 0x3
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, =0x00002ba2
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end StartMassOutbreak

	thumb_func_start sub_80ED4DC
sub_80ED4DC: @ 80ED4DC
	push {r4,lr}
	bl sub_80EFA88
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080ED532
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	adds r0, r4, 0
	adds r0, 0x17
	bl sub_818E848
	movs r0, 0x2
	strb r0, [r4, 0x18]
	movs r0, 0xC
	strb r0, [r4]
	movs r0, 0x1
	strb r0, [r4, 0x1]
	adds r0, r4, 0x2
	bl sub_818E81C
	adds r0, r4, 0
	adds r0, 0xA
	adds r1, r4, 0
	adds r1, 0xB
	bl sub_818E7E0
	bl sub_818E880
	strb r0, [r4, 0x16]
	adds r0, r4, 0
	bl sub_80ECA10
_080ED532:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED4DC

	thumb_func_start sub_80ED548
sub_80ED548: @ 80ED548
	push {r4,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r2]
	adds r4, r0
	movs r0, 0x1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x10
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r4, 0x2]
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x18]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED548

	thumb_func_start sub_80ED5B8
sub_80ED5B8: @ 80ED5B8
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r2]
	adds r4, r0
	movs r5, 0
	movs r0, 0x2
	strb r0, [r4]
	movs r0, 0x1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x10
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	strh r5, [r4, 0x2]
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x18]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED5B8

	thumb_func_start sub_80ED610
sub_80ED610: @ 80ED610
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	movs r0, 0x3
	strb r0, [r5]
	movs r0, 0x1
	mov r8, r0
	mov r1, r8
	strb r1, [r5, 0x1]
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r7, 0x64
	muls r0, r7
	ldr r6, =gPlayerParty
	adds r0, r6
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	lsrs r0, 4
	movs r1, 0xF
	ands r0, r1
	ldrb r2, [r5, 0x4]
	movs r1, 0x10
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x4]
	ldr r0, =gSpecialVar_0x8007
	ldrb r0, [r0]
	lsls r0, 4
	movs r2, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x4]
	adds r0, r5, 0x5
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	adds r0, r6
	adds r4, r5, 0
	adds r4, 0x10
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	adds r0, r4, 0
	bl StripExtCtrlCodes
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r5, 0x2]
	adds r0, r5, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r5, 0xD]
	cmp r0, 0x1
	beq _080ED6D4
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	adds r0, r6
	movs r1, 0x3
	bl GetMonData
	cmp r0, 0x1
	bne _080ED6F4
_080ED6D4:
	mov r0, r8
	b _080ED706
	.pool
_080ED6F4:
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	adds r0, r6
	movs r1, 0x3
	bl GetMonData
_080ED706:
	strb r0, [r5, 0xE]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80ED610

	thumb_func_start TaskDummy5
TaskDummy5: @ 80ED714
	bx lr
	thumb_func_end TaskDummy5

	thumb_func_start sub_80ED718
sub_80ED718: @ 80ED718
	push {r4-r6,lr}
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080ED7E4
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r3, =0x000027cc
_080ED72E:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2, r0
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x29
	beq _080ED7E4
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x17
	bls _080ED72E
	ldr r0, =0x00000147
	bl sub_80EFB38
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _080ED7E4
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080ED7E4
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r2, 0
	ldrsb r2, [r4, r2]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	ldr r2, =0x000027cc
	adds r1, r2
	ldr r4, [r6]
	adds r4, r1
	movs r1, 0x29
	strb r1, [r4]
	movs r3, 0x1
	strb r3, [r4, 0x1]
	ldr r2, =gUnknown_0858D094
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0xA]
	strb r0, [r4, 0x14]
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x3]
	ldrh r0, [r1]
	movs r2, 0
	strh r0, [r4, 0xC]
	strh r5, [r4, 0xE]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x4]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x6]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x8]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0xA]
	ldrb r0, [r1, 0xB]
	strb r0, [r4, 0x10]
	strb r2, [r4, 0x11]
	strb r2, [r4, 0x12]
	movs r0, 0x32
	strb r0, [r4, 0x13]
	strb r2, [r4, 0x15]
	strh r3, [r4, 0x16]
	adds r0, r4, 0
	bl sub_80ECA10
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x18]
_080ED7E4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED718

	thumb_func_start EndMassOutbreak
EndMassOutbreak: @ 80ED808
	push {r4,r5,lr}
	ldr r3, =gSaveBlock1Ptr
	ldr r0, [r3]
	ldr r2, =0x00002b90
	adds r1, r0, r2
	movs r4, 0
	movs r2, 0
	strh r2, [r1]
	ldr r5, =0x00002b92
	adds r0, r5
	strb r4, [r0]
	ldr r0, [r3]
	ldr r1, =0x00002b93
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r3]
	adds r5, 0x2
	adds r0, r5
	strb r4, [r0]
	ldr r0, [r3]
	adds r1, 0x2
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r3]
	adds r5, 0x2
	adds r1, r0, r5
	strh r2, [r1]
	adds r5, 0x2
	adds r1, r0, r5
	strh r2, [r1]
	adds r5, 0x2
	adds r1, r0, r5
	strh r2, [r1]
	adds r5, 0x2
	adds r1, r0, r5
	strh r2, [r1]
	adds r5, 0x2
	adds r1, r0, r5
	strh r2, [r1]
	ldr r1, =0x00002ba0
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r3]
	adds r5, 0x3
	adds r0, r5
	strb r4, [r0]
	ldr r0, [r3]
	adds r1, 0x2
	adds r0, r1
	strh r2, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EndMassOutbreak

	thumb_func_start sub_80ED888
sub_80ED888: @ 80ED888
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	bl sub_80ED8B4
	adds r0, r4, 0
	bl UpdateMassOutbreakTimeLeft
	adds r0, r4, 0
	bl sub_80EF120
	adds r0, r4, 0
	bl sub_80EDA48
	adds r0, r4, 0
	bl sub_80EEB98
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80ED888

	thumb_func_start sub_80ED8B4
sub_80ED8B4: @ 80ED8B4
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	ldr r2, =0x00002b90
	adds r0, r2
	ldrh r0, [r0]
	mov r12, r1
	cmp r0, 0
	bne _080ED91C
	movs r1, 0
	ldr r6, =0x000027cc
_080ED8CE:
	mov r7, r12
	ldr r4, [r7]
	lsls r0, r1, 3
	adds r0, r1
	lsls r3, r0, 2
	adds r2, r4, r3
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, 0x29
	bne _080ED912
	ldr r7, =0x000027cd
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080ED912
	adds r0, r3, r6
	adds r1, r4, r0
	ldrh r0, [r1, 0x16]
	cmp r0, r5
	bcs _080ED90C
	movs r0, 0
	strh r0, [r1, 0x16]
	b _080ED91C
	.pool
_080ED90C:
	subs r0, r5
	strh r0, [r1, 0x16]
	b _080ED91C
_080ED912:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x17
	bls _080ED8CE
_080ED91C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80ED8B4

	thumb_func_start UpdateMassOutbreakTimeLeft
UpdateMassOutbreakTimeLeft: @ 80ED924
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00002ba2
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, r2
	bhi _080ED948
	bl EndMassOutbreak
	b _080ED94C
	.pool
_080ED948:
	subs r0, r2
	strh r0, [r1]
_080ED94C:
	pop {r0}
	bx r0
	thumb_func_end UpdateMassOutbreakTimeLeft

	thumb_func_start sub_80ED950
sub_80ED950: @ 80ED950
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	beq _080ED978
	ldr r4, =gUnknown_0203A026
	ldrh r0, [r4]
	lsrs r0, 8
	cmp r0, 0x4
	bls _080ED966
	bl sub_80ED9A8
_080ED966:
	ldrb r0, [r4]
	strh r0, [r4]
	cmp r0, 0xFF
	beq _080ED99C
	adds r0, 0x1
	b _080ED99A
	.pool
_080ED978:
	ldr r4, =gUnknown_0203A026
	ldrb r0, [r4]
	cmp r0, 0x4
	bls _080ED984
	bl sub_80ED9A8
_080ED984:
	ldrh r0, [r4]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	strh r1, [r4]
	lsrs r0, r1, 8
	cmp r0, 0xFF
	beq _080ED99C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r1, r2
_080ED99A:
	strh r0, [r4]
_080ED99C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED950

	thumb_func_start sub_80ED9A8
sub_80ED9A8: @ 80ED9A8
	push {r4-r6,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EDA18
	movs r0, 0x18
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EDA18
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r4, [r6]
	adds r4, r0
	movs r1, 0
	movs r0, 0x18
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r1, =gUnknown_0203A026
	ldrh r0, [r1]
	strb r0, [r4, 0x2]
	ldrh r0, [r1]
	lsrs r0, 8
	strb r0, [r4, 0x3]
	ldr r0, =gUnknown_0203A024
	ldrh r0, [r0]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x6]
_080EDA18:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ED9A8

	thumb_func_start sub_80EDA3C
sub_80EDA3C: @ 80EDA3C
	ldr r1, =gUnknown_0203A024
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80EDA3C

	thumb_func_start sub_80EDA48
sub_80EDA48: @ 80EDA48
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r2, =0x00002b2c
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x19
	bne _080EDA6E
	ldrh r0, [r1, 0x2]
	cmp r0, 0x13
	bls _080EDA62
	bl sub_80EDA80
_080EDA62:
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	movs r1, 0x18
	bl sub_80EF910
_080EDA6E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDA48

	thumb_func_start sub_80EDA80
sub_80EDA80: @ 80EDA80
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	ldr r1, =0x00002b2c
	adds r5, r0, r1
	ldr r0, =0x0000ffff
	bl sub_80EFB38
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _080EDB1C
	ldr r0, [r7]
	ldr r1, =0x000027cc
	mov r8, r1
	add r0, r8
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EDB1C
	movs r0, 0x19
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EDB1C
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldr r4, [r7]
	adds r4, r0
	movs r0, 0x19
	strb r0, [r4]
	strb r6, [r4, 0x1]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x2]
	movs r0, 0x5
	bl GetGameStat
	ldrh r1, [r5, 0x6]
	subs r0, r1
	strh r0, [r4, 0x6]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x4]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x8]
	ldrb r0, [r5, 0xA]
	strb r0, [r4, 0xA]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0xB]
	ldr r0, [r7]
	add r0, r8
	movs r1, 0x18
	bl sub_80EF910
_080EDB1C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDA80

	thumb_func_start sub_80EDB44
sub_80EDB44: @ 80EDB44
	push {r4-r7,lr}
	movs r0, 0x1A
	movs r1, 0x1
	bl sub_80EF46C
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r2, =gUnknown_030060BC
	strb r0, [r2]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EDC40
	movs r1, 0
	ldrsb r1, [r2, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r2, =0x000027cc
	adds r0, r2
	ldr r1, [r4]
	adds r4, r1, r0
	movs r1, 0
	movs r0, 0x1A
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r6, =0x00000867
	movs r5, 0
_080EDB88:
	lsls r0, r6, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080EDB9C
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080EDB9C:
	adds r6, 0x1
	ldr r0, =0x0000086e
	cmp r6, r0
	bls _080EDB88
	strb r5, [r4, 0x4]
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _080EDBCC
	movs r0, 0x1
	bl pokedex_count
	b _080EDBD2
	.pool
_080EDBCC:
	movs r0, 0x1
	bl sub_80C0844
_080EDBD2:
	strh r0, [r4, 0x2]
	ldr r1, =gMapHeader
	ldrb r0, [r1, 0x14]
	strb r0, [r4, 0x7]
	ldrh r0, [r1, 0x12]
	movs r1, 0
	strh r0, [r4, 0xA]
	strb r1, [r4, 0x5]
	strb r1, [r4, 0x6]
	movs r6, 0
	adds r7, r4, 0
	adds r7, 0x13
_080EDBEA:
	ldr r0, =gUnknown_0858D0DE
	lsls r5, r6, 1
	adds r0, r5, r0
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EDC04
	ldrb r0, [r4, 0x5]
	adds r0, 0x1
	strb r0, [r4, 0x5]
_080EDC04:
	ldr r0, =gUnknown_0858D0D0
	adds r0, r5, r0
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EDC1C
	ldrb r0, [r4, 0x6]
	adds r0, 0x1
	strb r0, [r4, 0x6]
_080EDC1C:
	adds r6, 0x1
	cmp r6, 0x6
	bls _080EDBEA
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000eb8
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4, 0x8]
	adds r0, r7, 0
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0xC]
_080EDC40:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDB44

	thumb_func_start sub_80EDC60
sub_80EDC60: @ 80EDC60
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	ldr r6, =0x000027cc
	adds r0, r6
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EDCCE
	movs r0, 0x1B
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EDCCE
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r4, [r7]
	adds r4, r0
	movs r1, 0
	movs r0, 0x1B
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	strb r0, [r4, 0x8]
	ldrh r0, [r5]
	strh r0, [r4, 0x4]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x6]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x9]
_080EDCCE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDC60

	thumb_func_start sub_80EDCE8
sub_80EDCE8: @ 80EDCE8
	push {r4-r6,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EDD56
	movs r0, 0x1C
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EDD56
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r4, [r6]
	adds r4, r0
	movs r1, 0
	movs r0, 0x1C
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	strh r0, [r4, 0x2]
	ldr r1, =gMapHeader
	ldrb r0, [r1, 0x14]
	strb r0, [r4, 0x4]
	ldrh r0, [r1, 0x12]
	strh r0, [r4, 0x6]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x5]
_080EDD56:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDCE8

	thumb_func_start sub_80EDD78
sub_80EDD78: @ 80EDD78
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EDE54
	movs r0, 0x1D
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EDE54
	movs r5, 0
	ldr r0, =gUnknown_0203A02A
	ldrb r1, [r0]
	adds r6, r0, 0
	cmp r1, 0
	beq _080EDDCC
	cmp r1, 0x1
	beq _080EDDEE
	b _080EDE54
	.pool
_080EDDCC:
	ldr r0, =gUnknown_0203A028
	ldrh r1, [r0]
	adds r0, r1, 0
	adds r0, 0xC8
	cmp r4, r0
	blt _080EDDE4
	movs r5, 0x1
	subs r0, r4, r1
	b _080EDE12
	.pool
_080EDDE4:
	cmp r1, 0x63
	bls _080EDE54
	adds r0, r1, 0
	subs r0, 0x64
	b _080EDE0C
_080EDDEE:
	ldr r0, =gUnknown_0203A028
	ldrh r1, [r0]
	adds r0, r1, 0
	adds r0, 0x32
	cmp r4, r0
	blt _080EDE04
	movs r5, 0x1
	subs r0, r4, r1
	b _080EDE12
	.pool
_080EDE04:
	cmp r1, 0x31
	bls _080EDE54
	adds r0, r1, 0
	subs r0, 0x32
_080EDE0C:
	cmp r4, r0
	bgt _080EDE54
	subs r0, r1, r4
_080EDE12:
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r2]
	adds r4, r0
	movs r1, 0
	movs r0, 0x1D
	strb r0, [r4]
	strb r1, [r4, 0x1]
	strh r3, [r4, 0x4]
	ldrb r0, [r6]
	strb r0, [r4, 0x3]
	strb r5, [r4, 0x2]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x8]
_080EDE54:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDD78

	thumb_func_start sub_80EDE70
sub_80EDE70: @ 80EDE70
	ldr r2, =gUnknown_0203A02A
	movs r1, 0
	strb r1, [r2]
	ldr r1, =gUnknown_0203A028
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80EDE70

	thumb_func_start sub_80EDE84
sub_80EDE84: @ 80EDE84
	ldr r2, =gUnknown_0203A02A
	movs r1, 0x1
	strb r1, [r2]
	ldr r1, =gUnknown_0203A028
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80EDE84

	thumb_func_start sub_80EDE98
sub_80EDE98: @ 80EDE98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	movs r3, 0
	ldr r6, =gUnknown_030060D0
	ldr r7, =gSaveBlock1Ptr
	adds r2, r6, 0
	movs r1, 0
_080EDEAC:
	adds r0, r3, r2
	strb r1, [r0]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xF
	bls _080EDEAC
	movs r3, 0
	movs r5, 0
_080EDEBE:
	ldr r0, [r7]
	ldr r1, =0x00001aae
	adds r0, r1
	adds r0, r3
	ldrb r4, [r0]
	adds r3, 0x1
	cmp r4, 0
	beq _080EDF0A
	movs r1, 0
	ldrb r0, [r6]
	cmp r0, 0
	bne _080EDEE8
	strb r4, [r6]
	b _080EDF04
	.pool
_080EDEE8:
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, r4
	beq _080EDF0A
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bhi _080EDF0A
	adds r2, r1, r6
	ldrb r0, [r2]
	cmp r0, 0
	bne _080EDEE8
	strb r4, [r2]
_080EDF04:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080EDF0A:
	lsls r0, r3, 24
	lsrs r3, r0, 24
	cmp r3, 0xF
	bls _080EDEBE
	cmp r5, 0x4
	bls _080EDF1E
	movs r0, 0x4
	mov r1, r8
	strb r0, [r1, 0x3]
	b _080EDF22
_080EDF1E:
	mov r0, r8
	strb r5, [r0, 0x3]
_080EDF22:
	mov r1, r8
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _080EDFA4
	cmp r0, 0x1
	bne _080EDF34
	ldrb r0, [r6]
	strb r0, [r1, 0x4]
	b _080EDFA4
_080EDF34:
	movs r6, 0
	adds r7, r5, 0
	muls r7, r5
	cmp r6, r7
	bge _080EDF7E
	ldr r0, =gUnknown_030060D0
	mov r9, r0
_080EDF42:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 24
	lsrs r4, r0, 24
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 24
	lsrs r1, r0, 24
	mov r0, r9
	adds r2, r4, r0
	ldrb r3, [r2]
	add r1, r9
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r7
	blt _080EDF42
_080EDF7E:
	movs r3, 0
	mov r1, r8
	ldrb r1, [r1, 0x3]
	cmp r3, r1
	bcs _080EDFA4
	mov r2, r8
	adds r2, 0x4
	ldr r4, =gUnknown_030060D0
_080EDF8E:
	adds r1, r2, r3
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	mov r0, r8
	ldrb r0, [r0, 0x3]
	cmp r3, r0
	bcc _080EDF8E
_080EDFA4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDE98

	thumb_func_start sub_80EDFB4
sub_80EDFB4: @ 80EDFB4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	movs r7, 0
	movs r0, 0
	mov r9, r0
	ldr r1, =gUnknown_030060C0
	mov r8, r1
_080EDFCA:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _080EE094
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _080EE094
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r2, =gUnknown_030060E0
	mov r3, r9
	lsls r1, r3, 3
	adds r6, r1, r2
	strb r0, [r6]
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	strh r0, [r6, 0x2]
	movs r5, 0
	adds r0, r4, 0
	movs r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080EE020
	mov r0, r8
	strh r1, [r0]
	movs r5, 0x1
_080EE020:
	adds r0, r4, 0
	movs r1, 0xE
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080EE03C
	lsls r0, r5, 1
	add r0, r8
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080EE03C:
	adds r0, r4, 0
	movs r1, 0xF
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080EE058
	lsls r0, r5, 1
	add r0, r8
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080EE058:
	adds r0, r4, 0
	movs r1, 0x10
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080EE074
	lsls r0, r5, 1
	add r0, r8
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080EE074:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, 0x4]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080EE094:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x5
	bls _080EDFCA
	movs r7, 0
	movs r1, 0
	cmp r1, r9
	bcs _080EE0BE
	ldr r2, =gUnknown_030060E0
_080EE0A8:
	lsls r0, r7, 3
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r1, r0
	lsls r0, 16
	lsrs r1, r0, 16
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, r9
	bcc _080EE0A8
_080EE0BE:
	adds r0, r1, 0
	mov r1, r9
	bl __divsi3
	mov r1, r10
	strb r0, [r1, 0x2]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r9
	bl __modsi3
	lsls r0, 16
	ldr r1, =gUnknown_030060E0
	lsrs r0, 13
	adds r0, r1
	ldrh r1, [r0, 0x2]
	mov r2, r10
	strh r1, [r2, 0x8]
	ldrh r0, [r0, 0x4]
	strh r0, [r2, 0xA]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EDFB4

	thumb_func_start sub_80EE104
sub_80EE104: @ 80EE104
	push {r4,lr}
	movs r0, 0x1F
	movs r1, 0x1
	bl sub_80EF46C
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r2, =gUnknown_030060BC
	strb r0, [r2]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE168
	movs r1, 0
	ldrsb r1, [r2, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r4]
	adds r4, r0
	movs r1, 0
	movs r0, 0x1F
	strb r0, [r4]
	strb r1, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0
	bl sub_80EDE98
	adds r0, r4, 0
	bl sub_80EDFB4
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0xC]
_080EE168:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE104

	thumb_func_start sub_80EE184
sub_80EE184: @ 80EE184
	push {r4-r7,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080EE1A4
	b _080EE2C2
_080EE1A4:
	movs r0, 0x1E
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EE1B6
	b _080EE2C2
_080EE1B6:
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, [r6]
	adds r4, r1, r0
	movs r1, 0
	movs r0, 0x1E
	strb r0, [r4]
	strb r1, [r4, 0x1]
	movs r5, 0
	ldr r6, =gBattleResults
	ldr r3, =gMapHeader
	ldr r7, =gSaveBlock2Ptr
	adds r2, r6, 0
	adds r2, 0x36
_080EE1DA:
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xA
	bls _080EE1DA
	ldrb r1, [r6, 0x5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080EE1FE
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080EE1FE:
	ldrb r0, [r3, 0x14]
	strb r0, [r4, 0x4]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, [r7]
	bl StringCopy
	ldrh r0, [r6, 0x6]
	strh r0, [r4, 0xA]
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r0, 0x9
	bhi _080EE282
	lsls r0, 2
	ldr r1, =_080EE244
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EE244:
	.4byte _080EE276
	.4byte _080EE26C
	.4byte _080EE26C
	.4byte _080EE27A
	.4byte _080EE27A
	.4byte _080EE27E
	.4byte _080EE272
	.4byte _080EE27A
	.4byte _080EE282
	.4byte _080EE27E
_080EE26C:
	movs r0, 0
	strb r0, [r4]
	b _080EE2C2
_080EE272:
	movs r0, 0
	b _080EE280
_080EE276:
	movs r0, 0x1
	b _080EE280
_080EE27A:
	movs r0, 0x2
	b _080EE280
_080EE27E:
	movs r0, 0x3
_080EE280:
	strb r0, [r4, 0x5]
_080EE282:
	ldr r1, =gBattleResults
	ldrh r0, [r1, 0x20]
	strh r0, [r4, 0x2]
	ldrb r0, [r4, 0x5]
	cmp r0, 0x1
	beq _080EE2B2
	cmp r0, 0x1
	bgt _080EE2B6
	cmp r0, 0
	bne _080EE2B6
	ldrb r1, [r1, 0x5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080EE2A8
	movs r0, 0x1
	b _080EE2AC
	.pool
_080EE2A8:
	lsls r0, r1, 26
	lsrs r0, 28
_080EE2AC:
	strh r0, [r4, 0x6]
	strh r5, [r4, 0x8]
	b _080EE2B6
_080EE2B2:
	ldrh r0, [r1, 0x22]
	strh r0, [r4, 0xC]
_080EE2B6:
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0xE]
_080EE2C2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE184

	thumb_func_start sub_80EE2CC
sub_80EE2CC: @ 80EE2CC
	push {r4-r6,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE33A
	movs r0, 0x20
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EE33A
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r4, [r6]
	adds r4, r0
	movs r1, 0
	movs r0, 0x20
	strb r0, [r4]
	strb r1, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gSpecialVar_0x8004
	ldrb r1, [r0]
	movs r0, 0x4
	subs r0, r1
	strb r0, [r4, 0x4]
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	strh r0, [r4, 0x2]
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x5]
_080EE33A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE2CC

	thumb_func_start sub_80EE35C
sub_80EE35C: @ 80EE35C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r3, 0
	ldr r3, [sp, 0x24]
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp]
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r0, [r0]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE426
	movs r0, 0x21
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EE426
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r0
	movs r1, 0
	movs r0, 0x21
	strb r0, [r4]
	strb r1, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	mov r0, r10
	strh r0, [r4, 0x4]
	mov r1, r9
	strh r1, [r4, 0x6]
	lsls r0, r6, 1
	adds r0, r7
	ldrh r0, [r0]
	strh r0, [r4, 0x2]
	movs r2, 0
	movs r3, 0
	adds r5, r4, 0
	adds r5, 0x8
_080EE3EE:
	cmp r2, r6
	beq _080EE408
	lsls r0, r2, 1
	adds r0, r7
	ldrh r1, [r0]
	cmp r1, 0
	beq _080EE408
	lsls r0, r3, 1
	adds r0, r5, r0
	strh r1, [r0]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_080EE408:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080EE3EE
	strb r3, [r4, 0x10]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r4, 0xE]
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x11]
_080EE426:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE35C

	thumb_func_start sub_80EE44C
sub_80EE44C: @ 80EE44C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE4BE
	movs r0, 0x27
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EE4BE
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r4, [r6]
	adds r4, r0
	movs r1, 0
	movs r0, 0x27
	strb r0, [r4]
	strb r1, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	mov r0, r8
	strb r0, [r4, 0x2]
	strb r7, [r4, 0x3]
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x4]
_080EE4BE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE44C

	thumb_func_start sub_80EE4DC
sub_80EE4DC: @ 80EE4DC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	ldr r5, =0x000027cc
	adds r0, r5
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE59A
	movs r0, 0x23
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EE59A
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, [r7]
	adds r5, r1, r0
	movs r1, 0
	movs r0, 0x23
	strb r0, [r5]
	strb r1, [r5, 0x1]
	adds r0, r5, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r4, r5, 0x4
	adds r0, r6, 0
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	adds r0, r4, 0
	bl StripExtCtrlCodes
	adds r0, r6, 0
	bl sub_80EE5A4
	strb r0, [r5, 0x2]
	mov r0, r8
	bl sub_80EE69C
	strb r0, [r5, 0x3]
	adds r0, r5, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r5, 0xF]
	cmp r0, 0x1
	beq _080EE578
	adds r0, r6, 0
	movs r1, 0x3
	bl GetMonData
	cmp r0, 0x1
	bne _080EE590
_080EE578:
	movs r0, 0x1
	b _080EE598
	.pool
_080EE590:
	adds r0, r6, 0
	movs r1, 0x3
	bl GetMonData
_080EE598:
	strb r0, [r5, 0x10]
_080EE59A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EE4DC

	thumb_func_start sub_80EE5A4
sub_80EE5A4: @ 80EE5A4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x32
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x33
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x34
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x35
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x36
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x43
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x44
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x45
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x46
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x47
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x48
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x49
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x4A
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x4B
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x4C
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x4D
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x4E
	bl GetMonData
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80EE5A4

	thumb_func_start sub_80EE69C
sub_80EE69C: @ 80EE69C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x43
	beq _080EE722
	cmp r0, 0x32
	bne _080EE6AE
	movs r0, 0x1
	b _080EE728
_080EE6AE:
	cmp r0, 0x33
	bne _080EE6B6
	movs r0, 0x5
	b _080EE728
_080EE6B6:
	cmp r0, 0x34
	bne _080EE6BE
	movs r0, 0x9
	b _080EE728
_080EE6BE:
	cmp r0, 0x35
	bne _080EE6C6
	movs r0, 0xD
	b _080EE728
_080EE6C6:
	cmp r0, 0x36
	bne _080EE6CE
	movs r0, 0x11
	b _080EE728
_080EE6CE:
	cmp r0, 0x44
	bne _080EE6D6
	movs r0, 0x15
	b _080EE728
_080EE6D6:
	cmp r0, 0x45
	bne _080EE6DE
	movs r0, 0x16
	b _080EE728
_080EE6DE:
	cmp r0, 0x46
	bne _080EE6E6
	movs r0, 0x17
	b _080EE728
_080EE6E6:
	cmp r0, 0x47
	bne _080EE6EE
	movs r0, 0x18
	b _080EE728
_080EE6EE:
	cmp r0, 0x48
	bne _080EE6F6
	movs r0, 0x19
	b _080EE728
_080EE6F6:
	cmp r0, 0x49
	bne _080EE6FE
	movs r0, 0x1A
	b _080EE728
_080EE6FE:
	cmp r0, 0x4A
	bne _080EE706
	movs r0, 0x1B
	b _080EE728
_080EE706:
	cmp r0, 0x4B
	bne _080EE70E
	movs r0, 0x1C
	b _080EE728
_080EE70E:
	cmp r0, 0x4C
	bne _080EE716
	movs r0, 0x1D
	b _080EE728
_080EE716:
	cmp r0, 0x4D
	bne _080EE71E
	movs r0, 0x1E
	b _080EE728
_080EE71E:
	cmp r0, 0x4E
	beq _080EE726
_080EE722:
	movs r0, 0
	b _080EE728
_080EE726:
	movs r0, 0x1F
_080EE728:
	pop {r1}
	bx r1
	thumb_func_end sub_80EE69C

	thumb_func_start sub_80EE72C
sub_80EE72C: @ 80EE72C
	push {r4-r6,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r6, =0x000027cc
	adds r0, r6
	bl sub_80EFB08
	ldr r4, =gUnknown_030060BC
	strb r0, [r4]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE79C
	movs r0, 0x22
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EE79C
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r4, [r5]
	adds r4, r0
	movs r1, 0
	movs r0, 0x22
	strb r0, [r4]
	strb r1, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, [r5]
	ldr r2, =0x00002bb0
	adds r1, r0, r2
	ldrh r1, [r1]
	strh r1, [r4, 0x4]
	ldr r1, =0x00002bb2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4, 0x6]
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x8]
_080EE79C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE72C

	thumb_func_start sub_80EE7C0
sub_80EE7C0: @ 80EE7C0
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE810
	movs r0, 0xB
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080EE810
	ldr r0, [r4]
	ldr r1, =0x00003150
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080EE810
	movs r0, 0
	b _080EE812
	.pool
_080EE810:
	movs r0, 0x1
_080EE812:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EE7C0

	thumb_func_start sub_80EE818
sub_80EE818: @ 80EE818
	push {r4-r7,lr}
	movs r0, 0x24
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EE870
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r7, r0, r1
	bl sub_80F0020
	adds r4, r0, 0
	movs r6, 0x5
	lsrs r5, r4, 8
_080EE83C:
	lsls r0, r6, 3
	adds r0, r6
	lsls r0, 2
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, 0x24
	bne _080EE866
	movs r3, 0xFF
	adds r0, r4, 0
	ands r0, r3
	adds r2, r1, 0
	adds r2, 0x22
	ldrb r2, [r2]
	cmp r0, r2
	bne _080EE866
	adds r0, r5, 0
	ands r0, r3
	adds r1, 0x23
	ldrb r1, [r1]
	cmp r0, r1
	beq _080EE89C
_080EE866:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x17
	bls _080EE83C
_080EE870:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EE8C0
	movs r0, 0x1
	b _080EE8C2
	.pool
_080EE89C:
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x000027cc
	adds r0, r4
	adds r1, r6, 0
	bl sub_80EF910
	ldr r0, [r5]
	adds r0, r4
	bl sub_80EF93C
	movs r0, 0x1
	b _080EE8C2
	.pool
_080EE8C0:
	movs r0, 0
_080EE8C2:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80EE818

	thumb_func_start sub_80EE8C8
sub_80EE8C8: @ 80EE8C8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r2, =gUnknown_030060BC
	strb r0, [r2]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080EE8F4
	b _080EEA52
_080EE8F4:
	movs r1, 0
	ldrsb r1, [r2, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r2, =0x000027cc
	adds r0, r2
	ldr r1, [r5]
	adds r7, r1, r0
	movs r1, 0
	movs r0, 0x24
	strb r0, [r7]
	strb r1, [r7, 0x1]
	adds r0, r7, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	strh r6, [r7, 0x2]
	strb r4, [r7, 0xD]
	subs r0, r4, 0x1
	cmp r0, 0xC
	bls _080EE926
	b _080EEA46
_080EE926:
	lsls r0, 2
	ldr r1, =_080EE944
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EE944:
	.4byte _080EE978
	.4byte _080EE9A8
	.4byte _080EE9E8
	.4byte _080EEA00
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
	.4byte _080EE978
_080EE978:
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x4]
	adds r0, r4, 0
	adds r0, 0x64
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x6]
	adds r4, 0xC8
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x8]
	b _080EEA46
	.pool
_080EE9A8:
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x4]
	adds r0, r4, 0
	adds r0, 0x64
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x6]
	adds r0, r4, 0
	adds r0, 0xC8
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x8]
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0xA]
	b _080EEA46
	.pool
_080EE9E8:
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x4]
	adds r4, 0x64
	adds r0, r4, 0
	b _080EEA3C
	.pool
_080EEA00:
	ldr r2, =gSaveBlock1Ptr
	mov r8, r2
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r1, =0x00000caa
	adds r0, r1
	ldrh r0, [r0]
	movs r5, 0x64
	adds r1, r0, 0
	muls r1, r5
	movs r4, 0xEA
	lsls r4, 1
	adds r1, r4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x4]
	ldr r0, [r6]
	ldr r2, =0x00000cac
	adds r0, r2
	ldrh r0, [r0]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r4
	mov r2, r8
	ldr r0, [r2]
	adds r0, r1
_080EEA3C:
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x6]
_080EEA46:
	adds r0, r7, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r7, 0xC]
_080EEA52:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EE8C8

	thumb_func_start sub_80EEA70
sub_80EEA70: @ 80EEA70
	push {r4-r7,lr}
	sub sp, 0x20
	movs r0, 0x26
	movs r1, 0
	bl sub_80EF46C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EEA86
	b _080EEB8C
_080EEA86:
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r2, =gUnknown_030060BC
	strb r0, [r2]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EEB8C
	movs r1, 0
	ldrsb r1, [r2, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r7]
	adds r5, r1, r0
	movs r1, 0
	movs r0, 0x26
	strb r0, [r5]
	strb r1, [r5, 0x1]
	adds r0, r5, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =0x000040ec
	bl VarGet
	strh r0, [r5, 0x2]
	bl sub_80E980C
	ldr r1, =gStringVar1
	mov r0, sp
	bl StringCopy
	mov r0, sp
	bl StripExtCtrlCodes
	adds r0, r5, 0x4
	mov r1, sp
	bl StringCopy
	ldr r0, =0x000040ed
	bl VarGet
	strh r0, [r5, 0x10]
	ldr r0, =0x000040ee
	bl VarGet
	adds r4, r0, 0
	ldr r0, =0x000040ef
	bl VarGet
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	adds r4, r0
	str r4, [r5, 0xC]
	adds r0, r5, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r5, 0x1B]
	cmp r0, 0x1
	beq _080EEB3A
	ldr r4, [r7]
	ldr r6, =0x00004054
	adds r0, r6, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r4, r1
	ldr r0, =0x00001aa9
	adds r4, r0
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _080EEB70
_080EEB3A:
	movs r0, 0x1
	b _080EEB8A
	.pool
_080EEB70:
	adds r0, r6, 0
	bl VarGet
	ldr r2, [r7]
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r2, r1
	ldr r1, =0x00001aa9
	adds r2, r1
	ldrb r0, [r2]
_080EEB8A:
	strb r0, [r5, 0x1C]
_080EEB8C:
	add sp, 0x20
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EEA70

	thumb_func_start sub_80EEB98
sub_80EEB98: @ 80EEB98
	push {r4-r7,lr}
	movs r5, 0
	ldr r6, =gUnknown_0858D0EC
	adds r7, r6, 0x2
	b _080EEBAE
	.pool
_080EEBA8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080EEBAE:
	cmp r5, 0x6
	bhi _080EEBCE
	lsls r4, r5, 2
	adds r0, r4, r6
	ldrh r0, [r0]
	bl VarGet
	adds r4, r7
	lsls r0, 16
	lsrs r0, 16
	ldrh r4, [r4]
	cmp r0, r4
	bcc _080EEBA8
	adds r0, r5, 0
	bl sub_80EEBF4
_080EEBCE:
	movs r5, 0
	ldr r4, =gUnknown_0858D0EC
_080EEBD2:
	lsls r0, r5, 2
	adds r0, r4
	ldrh r0, [r0]
	movs r1, 0
	bl VarSet
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x6
	bls _080EEBD2
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EEB98

	thumb_func_start sub_80EEBF4
sub_80EEBF4: @ 80EEBF4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x25
	movs r1, 0x1
	bl sub_80EF46C
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFB08
	ldr r2, =gUnknown_030060BC
	strb r0, [r2]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EEC60
	movs r1, 0
	ldrsb r1, [r2, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r4]
	adds r4, r0
	movs r1, 0
	movs r0, 0x25
	strb r0, [r4]
	strb r1, [r4, 0x1]
	adds r0, r4, 0
	adds r0, 0x13
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	strb r5, [r4, 0x4]
	ldr r1, =gUnknown_0858D0EC
	lsls r0, r5, 2
	adds r0, r1
	ldrh r0, [r0]
	bl VarGet
	strh r0, [r4, 0x2]
	adds r0, r4, 0
	bl sub_80EC9E8
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r4, 0x5]
_080EEC60:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EEBF4

	thumb_func_start sub_80EEC80
sub_80EEC80: @ 80EEC80
	push {r4,lr}
	ldr r4, =0x000040e6
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EEC80

	thumb_func_start sub_80EECA4
sub_80EECA4: @ 80EECA4
	push {r4,lr}
	ldr r4, =0x000040eb
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EECA4

	thumb_func_start sub_80EECC8
sub_80EECC8: @ 80EECC8
	push {r4,lr}
	ldr r4, =0x000040e7
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EECC8

	thumb_func_start sub_80EECEC
sub_80EECEC: @ 80EECEC
	push {r4,lr}
	ldr r4, =0x000040e8
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EECEC

	thumb_func_start sub_80EED10
sub_80EED10: @ 80EED10
	push {r4,lr}
	ldr r4, =0x000040e9
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EED10

	thumb_func_start sub_80EED34
sub_80EED34: @ 80EED34
	push {r4,lr}
	ldr r4, =0x000040ea
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EED34

	thumb_func_start sub_80EED60
sub_80EED60: @ 80EED60
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r5, =0x000040f1
	adds r0, r5, 0
	bl VarGet
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl VarSet
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EED60

	thumb_func_start sub_80EED88
sub_80EED88: @ 80EED88
	push {r4-r7,lr}
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080EEE0C
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r7, =0x00002b50
	adds r0, r7
	bl sub_80EEE30
	ldr r5, =gUnknown_030060BC
	strb r0, [r5]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080EEE0C
	ldr r0, =0x0000028f
	bl sub_80EFB38
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EEE0C
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r4, r0, 0x1
	adds r0, r4, 0
	bl sub_80EF0E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EEE0C
	ldr r1, [r6]
	movs r0, 0
	ldrsb r0, [r5, r0]
	lsls r0, 2
	adds r1, r0
	adds r1, r7
	strb r4, [r1]
	ldr r2, [r6]
	movs r0, 0
	ldrsb r0, [r5, r0]
	lsls r0, 2
	adds r0, r2, r0
	ldr r1, =0x00002b52
	adds r0, r1
	movs r1, 0x4
	strh r1, [r0]
	movs r0, 0
	ldrsb r0, [r5, r0]
	lsls r0, 2
	adds r2, r0
	ldr r0, =0x00002b51
	adds r2, r0
	movs r0, 0x1
	strb r0, [r2]
_080EEE0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EED88

	thumb_func_start sub_80EEE30
sub_80EEE30: @ 80EEE30
	push {lr}
	adds r2, r0, 0
	movs r1, 0
_080EEE36:
	lsls r0, r1, 24
	asrs r1, r0, 24
	lsls r0, r1, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EEE48
	adds r0, r1, 0
	b _080EEE58
_080EEE48:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	asrs r0, 24
	cmp r0, 0xF
	ble _080EEE36
	movs r0, 0x1
	negs r0, r0
_080EEE58:
	pop {r1}
	bx r1
	thumb_func_end sub_80EEE30

	thumb_func_start sub_80EEE5C
sub_80EEE5C: @ 80EEE5C
	push {r4,lr}
	movs r4, 0
_080EEE60:
	adds r0, r4, 0
	bl sub_80EEE78
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080EEE60
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80EEE5C

	thumb_func_start sub_80EEE78
sub_80EEE78: @ 80EEE78
	push {r4,lr}
	lsls r0, 24
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	lsrs r0, 22
	adds r1, r0
	ldr r2, =0x00002b50
	adds r1, r2
	movs r2, 0
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	ldr r4, =0x00002b51
	adds r1, r4
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =0x00002b52
	adds r1, r0
	strh r2, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EEE78

	thumb_func_start sub_80EEEB8
sub_80EEEB8: @ 80EEEB8
	push {r4-r7,lr}
	movs r2, 0
	ldr r6, =gSaveBlock1Ptr
_080EEEBE:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, r2, 2
	adds r0, r1
	ldr r3, =0x00002b50
	adds r0, r3
	ldrb r0, [r0]
	adds r5, r2, 0x1
	cmp r0, 0
	bne _080EEF12
	lsls r0, r5, 24
	b _080EEF0C
	.pool
_080EEEE0:
	ldr r3, [r6]
	lsls r4, r2, 2
	adds r0, r3, r4
	ldr r7, =0x00002b50
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _080EEF08
	adds r0, r3, r7
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r2, 0
	bl sub_80EEE78
	b _080EEF12
	.pool
_080EEF08:
	adds r0, r2, 0x1
	lsls r0, 24
_080EEF0C:
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080EEEE0
_080EEF12:
	lsls r0, r5, 24
	lsrs r2, r0, 24
	cmp r2, 0xE
	bls _080EEEBE
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EEEB8

	thumb_func_start sub_80EEF20
sub_80EEF20: @ 80EEF20
	push {r4,lr}
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
_080EEF28:
	lsls r0, r2, 2
	adds r1, r3, r0
	ldr r4, =0x00002b50
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080EEF58
	adds r4, 0x1
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EEF58
	adds r4, 0x1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0x2
	bhi _080EEF58
	adds r0, r2, 0
	b _080EEF64
	.pool
_080EEF58:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080EEF28
	movs r0, 0xFF
_080EEF64:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EEF20

	thumb_func_start sub_80EEF6C
sub_80EEF6C: @ 80EEF6C
	push {r4,r5,lr}
	bl sub_80EEF20
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _080EEF84
	ldr r1, =gScriptResult
	movs r0, 0
	b _080EF01A
	.pool
_080EEF84:
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	lsls r4, r2, 2
	adds r1, r0, r4
	ldr r0, =0x00002b52
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, 0
	bne _080EEFE8
	ldr r2, =0x00002b51
	adds r1, r2
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x13
	bgt _080EEFC8
	ldr r1, =gUnknown_0858D11C
	ldr r0, [r5]
	adds r0, r4
	subs r2, 0x1
	b _080EEFD0
	.pool
_080EEFC8:
	ldr r1, =gUnknown_0858D130
	ldr r0, [r5]
	adds r0, r4
	ldr r2, =0x00002b50
_080EEFD0:
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	b _080EF016
	.pool
_080EEFE8:
	ldrh r1, [r2]
	ldr r0, =gStringVar1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =0x00002b51
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gUnknown_0858D108
	ldr r0, [r5]
	adds r0, r4
	ldr r2, =0x00002b50
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
_080EF016:
	ldr r1, =gScriptResult
	movs r0, 0x1
_080EF01A:
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EEF6C

	thumb_func_start GetPriceReduction
GetPriceReduction: @ 80EF038
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _080EF048
	b _080EF08A
_080EF044:
	movs r0, 0x1
	b _080EF08C
_080EF048:
	movs r2, 0
	ldr r4, =gSaveBlock1Ptr
_080EF04C:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r1, r0
	ldr r5, =0x00002b50
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, r3
	bne _080EF080
	ldr r2, =0x00002b51
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080EF08A
	adds r0, r3, 0
	bl IsPriceDiscounted
	lsls r0, 24
	cmp r0, 0
	bne _080EF044
	b _080EF08A
	.pool
_080EF080:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080EF04C
_080EF08A:
	movs r0, 0
_080EF08C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetPriceReduction

	thumb_func_start IsPriceDiscounted
IsPriceDiscounted: @ 80EF094
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080EF0A6
	cmp r0, 0x3
	beq _080EF0C8
_080EF0A2:
	movs r0, 0x1
	b _080EF0D6
_080EF0A6:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _080EF0D4
	ldr r0, =gScriptLastTalked
	ldrh r0, [r0]
	cmp r0, 0x19
	beq _080EF0A2
	b _080EF0D4
	.pool
_080EF0C8:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000150d
	cmp r1, r0
	beq _080EF0A2
_080EF0D4:
	movs r0, 0
_080EF0D6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsPriceDiscounted

	thumb_func_start sub_80EF0E4
sub_80EF0E4: @ 80EF0E4
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080EF0F2
_080EF0EE:
	movs r0, 0x1
	b _080EF112
_080EF0F2:
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r4, =0x00002b50
_080EF0FA:
	lsls r0, r1, 2
	adds r0, r3, r0
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r2
	beq _080EF0EE
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _080EF0FA
	movs r0, 0
_080EF112:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80EF0E4

	thumb_func_start sub_80EF120
sub_80EF120: @ 80EF120
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r7, r0, 16
	movs r6, 0
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
_080EF130:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, 2
	adds r2, r0, r1
	ldr r3, =0x00002b50
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0
	beq _080EF196
	ldr r1, =0x00002b52
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, r7
	bcs _080EF164
	adds r0, r6, 0
	bl sub_80EEE78
	b _080EF196
	.pool
_080EF164:
	ldr r5, =0x00002b51
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EF186
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _080EF186
	mov r2, r8
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	strb r1, [r0]
_080EF186:
	mov r3, r8
	ldr r1, [r3]
	adds r1, r4
	ldr r0, =0x00002b52
	adds r1, r0
	ldrh r0, [r1]
	subs r0, r7
	strh r0, [r1]
_080EF196:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xF
	bls _080EF130
	bl sub_80EEEB8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF120

	thumb_func_start CopyContestRankToStringVar
CopyContestRankToStringVar: @ 80EF1BC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0x1
	beq _080EF1FC
	cmp r1, 0x1
	bgt _080EF1D6
	cmp r1, 0
	beq _080EF1E0
	b _080EF244
_080EF1D6:
	cmp r2, 0x2
	beq _080EF218
	cmp r2, 0x3
	beq _080EF234
	b _080EF244
_080EF1E0:
	ldr r1, =gUnknown_0858D144
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x14]
	bl StringCopy
	b _080EF244
	.pool
_080EF1FC:
	ldr r1, =gUnknown_0858D144
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x18]
	bl StringCopy
	b _080EF244
	.pool
_080EF218:
	ldr r1, =gUnknown_0858D144
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x1C]
	bl StringCopy
	b _080EF244
	.pool
_080EF234:
	ldr r1, =gUnknown_0858D144
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x20]
	bl StringCopy
_080EF244:
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyContestRankToStringVar

	thumb_func_start CopyContestCategoryToStringVar
@ void CopyContestCategoryToStringVar(u8 stringVarIndex, u8 contestCategoryId)
CopyContestCategoryToStringVar: @ 80EF250
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0x4
	bhi _080EF300
	lsls r0, 2
	ldr r1, =_080EF26C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EF26C:
	.4byte _080EF280
	.4byte _080EF29C
	.4byte _080EF2B8
	.4byte _080EF2D4
	.4byte _080EF2F0
_080EF280:
	ldr r1, =gUnknown_0858D144
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1]
	bl StringCopy
	b _080EF300
	.pool
_080EF29C:
	ldr r1, =gUnknown_0858D144
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x4]
	bl StringCopy
	b _080EF300
	.pool
_080EF2B8:
	ldr r1, =gUnknown_0858D144
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x8]
	bl StringCopy
	b _080EF300
	.pool
_080EF2D4:
	ldr r1, =gUnknown_0858D144
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0xC]
	bl StringCopy
	b _080EF300
	.pool
_080EF2F0:
	ldr r1, =gUnknown_0858D144
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =gUnknown_0858BAF0
	ldr r1, [r1, 0x10]
	bl StringCopy
_080EF300:
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyContestCategoryToStringVar

	thumb_func_start SetContestCategoryStringVarForInterview
@ void SetContestCategoryStringVarForInterview()
SetContestCategoryStringVarForInterview: @ 80EF30C
	push {lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	ldrb r1, [r1, 0x13]
	lsls r1, 29
	lsrs r1, 29
	movs r0, 0x1
	bl CopyContestCategoryToStringVar
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetContestCategoryStringVarForInterview

	thumb_func_start TV_ConvertNumberToOrdinal
TV_ConvertNumberToOrdinal: @ 80EF340
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80EF370
	adds r3, r0, 0
	ldr r0, =gUnknown_0858D144
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	lsls r3, 24
	lsrs r3, 24
	adds r1, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TV_ConvertNumberToOrdinal

	thumb_func_start sub_80EF370
sub_80EF370: @ 80EF370
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xA
	bl __divsi3
	cmp r0, 0
	beq _080EF3FC
	adds r0, r4, 0
	movs r1, 0x64
	bl __divsi3
	cmp r0, 0
	bne _080EF38E
	movs r0, 0x2
	b _080EF406
_080EF38E:
	movs r1, 0xFA
	lsls r1, 2
	adds r0, r4, 0
	bl __divsi3
	cmp r0, 0
	bne _080EF3A0
	movs r0, 0x3
	b _080EF406
_080EF3A0:
	ldr r1, =0x00002710
	adds r0, r4, 0
	bl __divsi3
	cmp r0, 0
	bne _080EF3B4
	movs r0, 0x4
	b _080EF406
	.pool
_080EF3B4:
	ldr r1, =0x000186a0
	adds r0, r4, 0
	bl __divsi3
	cmp r0, 0
	bne _080EF3C8
	movs r0, 0x5
	b _080EF406
	.pool
_080EF3C8:
	ldr r1, =0x000f4240
	adds r0, r4, 0
	bl __divsi3
	cmp r0, 0
	bne _080EF3DC
	movs r0, 0x6
	b _080EF406
	.pool
_080EF3DC:
	ldr r1, =0x00989680
	adds r0, r4, 0
	bl __divsi3
	cmp r0, 0
	bne _080EF3F0
	movs r0, 0x7
	b _080EF406
	.pool
_080EF3F0:
	ldr r1, =0x05f5e100
	adds r0, r4, 0
	bl __divsi3
	cmp r0, 0
	beq _080EF404
_080EF3FC:
	movs r0, 0x1
	b _080EF406
	.pool
_080EF404:
	movs r0, 0x8
_080EF406:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EF370

	thumb_func_start sub_80EF40C
sub_80EF40C: @ 80EF40C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	movs r5, 0
_080EF41E:
	lsls r4, r5, 1
	adds r0, r6, 0x6
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, 0
	beq _080EF43E
	bl itemid_get_market_price
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	adds r1, 0xC
	adds r1, r4
	ldrh r1, [r1]
	muls r0, r1
	adds r7, r0
_080EF43E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _080EF41E
	ldrb r0, [r6, 0x2]
	cmp r0, 0x1
	bne _080EF458
	asrs r1, r7, 1
	mov r0, r8
	bl TV_ConvertNumberToOrdinal
	b _080EF460
_080EF458:
	mov r0, r8
	adds r1, r7, 0
	bl TV_ConvertNumberToOrdinal
_080EF460:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EF40C

	thumb_func_start sub_80EF46C
sub_80EF46C: @ 80EF46C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x000027cc
	adds r0, r4
	mov r8, r0
	bl sub_80F0020
	adds r7, r0, 0
	movs r6, 0x5
_080EF494:
	lsls r0, r6, 3
	adds r0, r6
	lsls r0, 2
	mov r2, r8
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, r10
	bne _080EF4E4
	movs r3, 0xFF
	adds r0, r7, 0
	ands r0, r3
	adds r2, r1, 0
	adds r2, 0x22
	ldrb r2, [r2]
	cmp r0, r2
	bne _080EF4E4
	lsrs r0, r7, 8
	ands r0, r3
	adds r1, 0x23
	ldrb r1, [r1]
	cmp r0, r1
	bne _080EF4E4
	mov r0, r9
	cmp r0, 0x1
	bne _080EF4D8
	ldr r0, [r5]
	adds r0, r4
	adds r1, r6, 0
	bl sub_80EF910
	ldr r0, [r5]
	adds r0, r4
	bl sub_80EF93C
_080EF4D8:
	movs r0, 0x1
	b _080EF4F0
	.pool
_080EF4E4:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x17
	bls _080EF494
	movs r0, 0
_080EF4F0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80EF46C

	thumb_func_start sub_80EF500
sub_80EF500: @ 80EF500
	push {r4-r7,lr}
	movs r2, 0
_080EF504:
	adds r1, r2, 0x1
	lsls r0, r1, 24
	lsrs r5, r0, 24
	adds r7, r1, 0
	cmp r5, 0x2
	bhi _080EF53C
	ldr r6, =gUnknown_02039F80
	lsls r0, r2, 2
	adds r4, r0, r6
_080EF516:
	lsls r0, r5, 2
	adds r3, r0, r6
	ldrh r0, [r4, 0x2]
	ldrh r1, [r3, 0x2]
	cmp r0, r1
	bcs _080EF532
	ldrh r1, [r4]
	adds r2, r0, 0
	ldrh r0, [r3]
	strh r0, [r4]
	ldrh r0, [r3, 0x2]
	strh r0, [r4, 0x2]
	strh r1, [r3]
	strh r2, [r3, 0x2]
_080EF532:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _080EF516
_080EF53C:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bls _080EF504
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF500

	thumb_func_start sub_80EF550
sub_80EF550: @ 80EF550
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x000027cc
_080EF55C:
	ldr r3, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r3, r0
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, r6
	bne _080EF5A4
	ldr r6, =0x000027cd
	adds r0, r2, r6
	ldrb r2, [r0]
	cmp r2, 0x1
	bne _080EF590
	ldr r0, =gScriptResult
	strh r2, [r0]
	b _080EF5B2
	.pool
_080EF590:
	adds r0, r3, r4
	bl sub_80EF910
	ldr r0, [r5]
	adds r0, r4
	bl sub_80EF93C
	bl sub_80EFA88
	b _080EF5B2
_080EF5A4:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _080EF55C
	bl sub_80EFA88
_080EF5B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EF550

	thumb_func_start InterviewBefore
InterviewBefore: @ 80EF5B8
	push {lr}
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r0, 0xA
	bhi _080EF646
	lsls r0, 2
	ldr r1, =_080EF5E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EF5E0:
	.4byte _080EF60C
	.4byte _080EF612
	.4byte _080EF618
	.4byte _080EF61E
	.4byte _080EF624
	.4byte _080EF62A
	.4byte _080EF630
	.4byte _080EF636
	.4byte _080EF63C
	.4byte _080EF646
	.4byte _080EF642
_080EF60C:
	bl sub_80EF64C
	b _080EF646
_080EF612:
	bl sub_80EF6C4
	b _080EF646
_080EF618:
	bl sub_80EF704
	b _080EF646
_080EF61E:
	bl sub_80EF79C
	b _080EF646
_080EF624:
	bl sub_80EF7A8
	b _080EF646
_080EF62A:
	bl sub_80EF7B4
	b _080EF646
_080EF630:
	bl sub_80EF80C
	b _080EF646
_080EF636:
	bl sub_80EF7F4
	b _080EF646
_080EF63C:
	bl sub_80EF800
	b _080EF646
_080EF642:
	bl sub_80EF84C
_080EF646:
	pop {r0}
	bx r0
	thumb_func_end InterviewBefore

	thumb_func_start sub_80EF64C
sub_80EF64C: @ 80EF64C
	push {r4,lr}
	movs r0, 0x1
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EF6A0
	ldr r4, =gStringVar1
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	movs r1, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r0, r1
	ldr r1, =0x000027d0
	adds r0, r1
	movs r1, 0x6
	bl sub_811F88C
_080EF6A0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF64C

	thumb_func_start sub_80EF6C4
sub_80EF6C4: @ 80EF6C4
	push {lr}
	movs r0, 0x2
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EF6F0
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r0, r1
	ldr r1, =0x000027d0
	adds r0, r1
	movs r1, 0x6
	bl sub_811F88C
_080EF6F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF6C4

	thumb_func_start sub_80EF704
sub_80EF704: @ 80EF704
	push {r4-r6,lr}
	movs r0, 0x3
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EF774
	ldr r6, =gStringVar1
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	movs r1, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r6, 0
	bl StringCopy
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	muls r0, r5
	adds r0, r4
	ldr r4, =gStringVar2
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	adds r0, r4, 0
	bl StringGetEnd10
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r0, r1
	ldr r1, =0x000027e8
	adds r0, r1
	movs r1, 0x2
	bl sub_811F88C
_080EF774:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF704

	thumb_func_start sub_80EF79C
sub_80EF79C: @ 80EF79C
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80EF79C

	thumb_func_start sub_80EF7A8
sub_80EF7A8: @ 80EF7A8
	push {lr}
	movs r0, 0x5
	bl sub_80EF550
	pop {r0}
	bx r0
	thumb_func_end sub_80EF7A8

	thumb_func_start sub_80EF7B4
sub_80EF7B4: @ 80EF7B4
	push {lr}
	movs r0, 0x6
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EF7E0
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r0, r1
	ldr r1, =0x000027d0
	adds r0, r1
	movs r1, 0x2
	bl sub_811F88C
_080EF7E0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF7B4

	thumb_func_start sub_80EF7F4
sub_80EF7F4: @ 80EF7F4
	push {lr}
	movs r0, 0x8
	bl sub_80EF550
	pop {r0}
	bx r0
	thumb_func_end sub_80EF7F4

	thumb_func_start sub_80EF800
sub_80EF800: @ 80EF800
	push {lr}
	movs r0, 0x9
	bl sub_80EF550
	pop {r0}
	bx r0
	thumb_func_end sub_80EF800

	thumb_func_start sub_80EF80C
sub_80EF80C: @ 80EF80C
	push {lr}
	movs r0, 0x7
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EF838
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r0, r1
	ldr r1, =0x000027e4
	adds r0, r1
	movs r1, 0x1
	bl sub_811F88C
_080EF838:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF80C

	thumb_func_start sub_80EF84C
sub_80EF84C: @ 80EF84C
	push {lr}
	movs r0, 0xB
	bl sub_80EF550
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080EF878
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r0, r1
	ldr r1, =0x000027e0
	adds r0, r1
	movs r1, 0x1
	bl sub_811F88C
_080EF878:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EF84C

	thumb_func_start sub_80EF88C
sub_80EF88C: @ 80EF88C
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	ldr r6, =gStringVar1
	adds r0, r5, 0
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
	mov r4, sp
	adds r0, r5, 0
	movs r1, 0x3
	mov r2, sp
	bl GetMonData
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080EF8EC
	adds r0, r5, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	movs r1, 0xB
	muls r0, r1
	ldr r1, =gSpeciesNames
	adds r0, r1
	adds r1, r6, 0
	bl StringCompare
	cmp r0, 0
	bne _080EF8EC
	movs r0, 0
	b _080EF8EE
	.pool
_080EF8EC:
	movs r0, 0x1
_080EF8EE:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80EF88C

	thumb_func_start sub_80EF8F8
sub_80EF8F8: @ 80EF8F8
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	bl sub_80EF88C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80EF8F8

	thumb_func_start sub_80EF910
sub_80EF910: @ 80EF910
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 2
	adds r2, r0
	movs r0, 0
	strb r0, [r2]
	strb r0, [r2, 0x1]
	movs r1, 0
	adds r2, 0x2
	movs r3, 0
_080EF92A:
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x21
	bls _080EF92A
	pop {r0}
	bx r0
	thumb_func_end sub_80EF910

	thumb_func_start sub_80EF93C
sub_80EF93C: @ 80EF93C
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
_080EF942:
	lsls r0, r5, 3
	adds r0, r5
	lsls r1, r0, 2
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EF986
	adds r0, r5, 0x1
	b _080EF97E
_080EF954:
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r4
	ldrb r0, [r3]
	cmp r0, 0
	beq _080EF97C
	adds r1, r4
	adds r0, r3, 0
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_80EF910
	b _080EF986
_080EF97C:
	adds r0, r2, 0x1
_080EF97E:
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x4
	bls _080EF954
_080EF986:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080EF942
	movs r5, 0x5
_080EF992:
	lsls r0, r5, 3
	adds r0, r5
	lsls r1, r0, 2
	adds r0, r1, r4
	ldrb r0, [r0]
	adds r5, 0x1
	cmp r0, 0
	bne _080EF9D8
	lsls r0, r5, 24
	b _080EF9D2
_080EF9A6:
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r4
	ldrb r0, [r3]
	cmp r0, 0
	beq _080EF9CE
	adds r1, r4
	adds r0, r3, 0
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_80EF910
	b _080EF9D8
_080EF9CE:
	adds r0, r2, 0x1
	lsls r0, 24
_080EF9D2:
	lsrs r2, r0, 24
	cmp r2, 0x17
	bls _080EF9A6
_080EF9D8:
	lsls r0, r5, 24
	lsrs r5, r0, 24
	cmp r5, 0x17
	bls _080EF992
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EF93C

	thumb_func_start sub_80EF9E8
sub_80EF9E8: @ 80EF9E8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	lsrs r0, 16
	bl sub_80EFA24
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gUnknown_0858D144
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0xB
	muls r1, r5
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80EF9E8

	thumb_func_start sub_80EFA24
sub_80EFA24: @ 80EFA24
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000019b
	bl __umodsi3
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	b _080EFA62
	.pool
_080EFA48:
	cmp r4, 0x1
	bne _080EFA54
	ldr r4, =0x0000019b
	b _080EFA5A
	.pool
_080EFA54:
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080EFA5A:
	cmp r4, r6
	bne _080EFA62
	adds r4, r5, 0
	b _080EFA7E
_080EFA62:
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080EFA48
	cmp r4, r5
	beq _080EFA48
_080EFA7E:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80EFA24

	thumb_func_start sub_80EFA88
sub_80EFA88: @ 80EFA88
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	bl sub_80EFADC
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	ldr r2, =gSpecialVar_0x8006
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	strh r1, [r2]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080EFACC
	ldr r1, =gScriptResult
	movs r0, 0x1
	b _080EFAD0
	.pool
_080EFACC:
	ldr r1, =gScriptResult
	movs r0, 0
_080EFAD0:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFA88

	thumb_func_start sub_80EFADC
sub_80EFADC: @ 80EFADC
	push {lr}
	adds r2, r0, 0
	movs r1, 0
_080EFAE2:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EFAF6
	lsls r0, r1, 24
	asrs r0, 24
	b _080EFB04
_080EFAF6:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _080EFAE2
	movs r0, 0x1
	negs r0, r0
_080EFB04:
	pop {r1}
	bx r1
	thumb_func_end sub_80EFADC

	thumb_func_start sub_80EFB08
sub_80EFB08: @ 80EFB08
	push {lr}
	adds r2, r0, 0
	movs r1, 0x5
_080EFB0E:
	lsls r0, r1, 24
	asrs r1, r0, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EFB24
	adds r0, r1, 0
	b _080EFB34
_080EFB24:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	asrs r0, 24
	cmp r0, 0x17
	ble _080EFB0E
	movs r0, 0x1
	negs r0, r0
_080EFB34:
	pop {r1}
	bx r1
	thumb_func_end sub_80EFB08

	thumb_func_start sub_80EFB38
sub_80EFB38: @ 80EFB38
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bls _080EFB50
	movs r0, 0x1
	b _080EFB52
_080EFB50:
	movs r0, 0
_080EFB52:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EFB38

	thumb_func_start sub_80EFB58
sub_80EFB58: @ 80EFB58
	push {r4-r6,lr}
	adds r4, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r2, r0, 24
	adds r5, r4, 0x4
	ldr r6, =0x0000ffff
	b _080EFB7E
	.pool
_080EFB78:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080EFB7E:
	cmp r2, 0x6
	bne _080EFB84
	movs r2, 0
_080EFB84:
	lsls r1, r2, 1
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r3, r4, 0x4
	cmp r0, r6
	beq _080EFB78
	ldr r0, =gStringVar3
	adds r1, r3, r1
	ldrh r1, [r1]
	bl CopyEasyChatWord
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFB58

	thumb_func_start sub_80EFBA4
sub_80EFBA4: @ 80EFBA4
	push {lr}
	adds r2, r0, 0
	movs r3, 0
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0xFF
	beq _080EFBD0
	adds r2, 0x4
_080EFBB4:
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r0, r3, r0
	lsls r0, 16
	lsrs r3, r0, 16
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xA
	bhi _080EFBD0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EFBB4
_080EFBD0:
	movs r0, 0x7
	ands r3, r0
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80EFBA4

	thumb_func_start sub_80EFBDC
sub_80EFBDC: @ 80EFBDC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	movs r2, 0
	movs r7, 0xFF
_080EFC06:
	mov r1, sp
	adds r0, r1, r2
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _080EFC06
	cmp r3, 0
	bne _080EFC72
	mov r4, r8
	adds r4, 0xF
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r6, 0
	bne _080EFC36
	mov r0, sp
	adds r1, r4, r5
	b _080EFC40
_080EFC36:
	cmp r6, 0x1
	bne _080EFC46
	mov r0, sp
	subs r1, r2, r5
	adds r1, r4, r1
_080EFC40:
	ldrb r1, [r1]
	strb r1, [r0]
	b _080EFC6C
_080EFC46:
	cmp r6, 0x2
	bne _080EFC56
	mov r1, sp
	adds r0, r4, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, 0x1
	b _080EFC66
_080EFC56:
	mov r1, sp
	subs r0, r2, 0x2
	subs r0, r5
	adds r0, r4, r0
	ldrb r0, [r0]
	strb r0, [r1]
	subs r0, r2, 0x1
	subs r0, r5
_080EFC66:
	adds r0, r4, r0
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
_080EFC6C:
	mov r2, r8
	ldrb r1, [r2, 0x1E]
	b _080EFCC8
_080EFC72:
	cmp r3, 0x1
	bne _080EFCD0
	mov r4, r8
	adds r4, 0x4
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r6, 0
	bne _080EFC8E
	mov r0, sp
	adds r1, r4, r5
	b _080EFC98
_080EFC8E:
	cmp r6, 0x1
	bne _080EFC9E
	mov r0, sp
	subs r1, r2, r5
	adds r1, r4, r1
_080EFC98:
	ldrb r1, [r1]
	strb r1, [r0]
	b _080EFCC4
_080EFC9E:
	cmp r6, 0x2
	bne _080EFCAE
	mov r1, sp
	adds r0, r4, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, 0x1
	b _080EFCBE
_080EFCAE:
	mov r1, sp
	subs r0, r2, 0x2
	subs r0, r5
	adds r0, r4, r0
	ldrb r0, [r0]
	strb r0, [r1]
	subs r0, r2, 0x1
	subs r0, r5
_080EFCBE:
	adds r0, r4, r0
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
_080EFCC4:
	mov r5, r8
	ldrb r1, [r5, 0x1F]
_080EFCC8:
	mov r0, sp
	bl ConvertInternationalString
	b _080EFD30
_080EFCD0:
	movs r0, 0xB
	muls r4, r0
	ldr r7, =gSpeciesNames
	adds r0, r4, r7
	bl StringLength
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r6, 0
	bne _080EFCF0
	mov r0, sp
	adds r1, r5, r4
	b _080EFCFA
	.pool
_080EFCF0:
	cmp r6, 0x1
	bne _080EFD02
	mov r0, sp
	subs r1, r2, r5
	adds r1, r4
_080EFCFA:
	adds r1, r7
	ldrb r1, [r1]
	strb r1, [r0]
	b _080EFD30
_080EFD02:
	cmp r6, 0x2
	bne _080EFD16
	mov r1, sp
	adds r0, r5, r4
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, 0x1
	adds r0, r5, r0
	b _080EFD2A
_080EFD16:
	mov r1, sp
	subs r0, r2, 0x2
	subs r0, r5
	adds r0, r4
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r1]
	subs r0, r2, 0x1
	subs r0, r5
	adds r0, r4
_080EFD2A:
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
_080EFD30:
	ldr r0, =gUnknown_0858D144
	mov r2, r9
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	mov r1, sp
	bl StringCopy
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFBDC

	thumb_func_start sub_80EFD54
sub_80EFD54: @ 80EFD54
	push {r4,lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r2, [r0]
	ldr r4, =0x000027cc
_080EFD62:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3, r0
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r2
	bne _080EFD84
	movs r0, 0x1
	b _080EFD90
	.pool
_080EFD84:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _080EFD62
	movs r0, 0
_080EFD90:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EFD54

	thumb_func_start sub_80EFD98
sub_80EFD98: @ 80EFD98
	push {r4,lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r4, =gStringVar1
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	ldr r0, =gStringVar3
	adds r1, r4, 0
	bl StringCompare
	cmp r0, 0
	beq _080EFDD4
	bl sub_80ED320
	movs r0, 0x1
	b _080EFDD6
	.pool
_080EFDD4:
	movs r0, 0
_080EFDD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EFD98

	thumb_func_start sub_80EFDDC
sub_80EFDDC: @ 80EFDDC
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x8
	ldr r0, =gSpecialVar_0x8004
	mov r9, r0
	ldrh r0, [r0]
	movs r1, 0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r6, =gPlayerParty
	adds r0, r6
	ldr r2, =gStringVar3
	movs r1, 0x2
	bl GetMonData
	mov r1, r9
	ldrh r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	ldr r1, =gStringVar2
	mov r10, r1
	movs r1, 0x2
	mov r2, r10
	bl GetMonData
	mov r1, r9
	ldrh r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	mov r1, r9
	ldrh r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	bl GetMonGender
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, r9
	ldrh r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	movs r1, 0
	movs r2, 0
	bl GetMonData
	str r0, [sp]
	ldr r0, =c2_080CC144
	str r0, [sp, 0x4]
	movs r0, 0x3
	mov r1, r10
	adds r2, r5, 0
	adds r3, r4, 0
	bl DoNamingScreen
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFDDC

	thumb_func_start c2_080CC144
c2_080CC144: @ 80EFE98
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r2, =gStringVar2
	movs r1, 0x2
	bl SetMonData
	bl c2_exit_to_overworld_1_continue_scripts_restart_music
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_080CC144

	thumb_func_start sub_80EFEC4
sub_80EFEC4: @ 80EFEC4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	ldr r0, =gSpecialVar_0x8012
	ldrb r0, [r0]
	ldr r1, =gSpecialVar_0x8013
	ldrb r1, [r1]
	bl GetBoxedMonPtr
	adds r6, r0, 0
	ldr r2, =gStringVar3
	movs r1, 0x2
	bl GetBoxMonData
	ldr r0, =gStringVar2
	mov r8, r0
	adds r0, r6, 0
	movs r1, 0x2
	mov r2, r8
	bl GetBoxMonData
	adds r0, r6, 0
	movs r1, 0xB
	movs r2, 0
	bl GetBoxMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	bl GetBoxMonGender
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	bl GetBoxMonData
	str r0, [sp]
	ldr r0, =sub_80EFF48
	str r0, [sp, 0x4]
	movs r0, 0x3
	mov r1, r8
	adds r2, r5, 0
	adds r3, r4, 0
	bl DoNamingScreen
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFEC4

	thumb_func_start sub_80EFF48
sub_80EFF48: @ 80EFF48
	push {lr}
	ldr r0, =gSpecialVar_0x8012
	ldrb r0, [r0]
	ldr r1, =gSpecialVar_0x8013
	ldrb r1, [r1]
	ldr r2, =gStringVar2
	bl SetBoxMonNickFromAnyBox
	bl c2_exit_to_overworld_1_continue_scripts_restart_music
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFF48

	thumb_func_start sub_80EFF6C
sub_80EFF6C: @ 80EFF6C
	push {r4,lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r4, =gStringVar1
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	adds r0, r4, 0
	bl StringGetEnd10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFF6C

	thumb_func_start sub_80EFF9C
sub_80EFF9C: @ 80EFF9C
	push {r4,lr}
	bl sub_80F0020
	adds r4, r0, 0
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	cmp r4, r0
	bne _080EFFD0
	ldr r1, =gScriptResult
	movs r0, 0
	b _080EFFD4
	.pool
_080EFFD0:
	ldr r1, =gScriptResult
	movs r0, 0x1
_080EFFD4:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EFF9C

	thumb_func_start sub_80EFFE0
sub_80EFFE0: @ 80EFFE0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	cmp r1, 0
	beq _080F0016
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _080EFFFA
	movs r0, 0x2
	b _080F001C
_080EFFFA:
	adds r0, r1, 0
	subs r0, 0x15
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _080F000A
	movs r0, 0x3
	b _080F001C
_080F000A:
	adds r0, r2, 0
	subs r0, 0x29
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bls _080F001A
_080F0016:
	movs r0, 0
	b _080F001C
_080F001A:
	movs r0, 0x4
_080F001C:
	pop {r1}
	bx r1
	thumb_func_end sub_80EFFE0

	thumb_func_start sub_80F0020
sub_80F0020: @ 80F0020
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r0, [r2, 0xD]
	lsls r0, 24
	ldrb r1, [r2, 0xC]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0xB]
	lsls r1, 8
	orrs r0, r1
	ldrb r1, [r2, 0xA]
	orrs r0, r1
	bx lr
	.pool
	thumb_func_end sub_80F0020

	thumb_func_start CheckForBigMovieOrEmergencyNewsOnTV
CheckForBigMovieOrEmergencyNewsOnTV: @ 80F0040
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	cmp r0, 0x1
	bne _080F0060
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _080F006C
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0
	beq _080F0074
_080F0060:
	movs r0, 0
	b _080F009E
	.pool
_080F006C:
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0x2
	bne _080F0060
_080F0074:
	ldr r0, =0x000008bd
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080F0092
	movs r0, 0x89
	lsls r0, 4
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080F009C
_080F0092:
	movs r0, 0x1
	b _080F009E
	.pool
_080F009C:
	movs r0, 0x2
_080F009E:
	pop {r1}
	bx r1
	thumb_func_end CheckForBigMovieOrEmergencyNewsOnTV

	thumb_func_start GetMomOrDadStringForTVMessage
GetMomOrDadStringForTVMessage: @ 80F00A4
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	cmp r0, 0x1
	bne _080F0104
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _080F00EC
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bne _080F0104
	ldr r0, =gStringVar1
	ldr r1, =gText_Mom
	bl StringCopy
	ldr r0, =0x00004003
	movs r1, 0x1
	bl VarSet
	b _080F0104
	.pool
_080F00EC:
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0x2
	bne _080F0104
	ldr r0, =gStringVar1
	ldr r1, =gText_Mom
	bl StringCopy
	ldr r0, =0x00004003
	movs r1, 0x1
	bl VarSet
_080F0104:
	ldr r4, =0x00004003
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	beq _080F0142
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	beq _080F0158
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080F016C
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080F0158
_080F0142:
	ldr r0, =gStringVar1
	ldr r1, =gText_Mom
	bl StringCopy
	b _080F01A8
	.pool
_080F0158:
	ldr r0, =gStringVar1
	ldr r1, =gText_Dad
	bl StringCopy
	b _080F01A8
	.pool
_080F016C:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F0198
	ldr r0, =gStringVar1
	ldr r1, =gText_Mom
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0x1
	bl VarSet
	b _080F01A8
	.pool
_080F0198:
	ldr r0, =gStringVar1
	ldr r1, =gText_Dad
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0x2
	bl VarSet
_080F01A8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetMomOrDadStringForTVMessage

	thumb_func_start sub_80F01B8
sub_80F01B8: @ 80F01B8
	push {lr}
	ldr r0, =0x000040bc
	movs r1, 0
	bl VarSet
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x5
	bl RemoveFieldObjectByLocalIdAndMap
	ldr r0, =0x00000396
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F01B8

	thumb_func_start sub_80F01E8
sub_80F01E8: @ 80F01E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	movs r0, 0xE1
	lsls r0, 4
	bl Alloc
	mov r8, r0
	cmp r0, 0
	bne _080F0206
	b _080F0344
_080F0206:
	movs r4, 0
_080F0208:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 5
	adds r0, r4
	lsls r0, 2
	add r0, r8
	adds r1, r4, 0
	muls r1, r5
	adds r1, r7, r1
	movs r2, 0xE1
	lsls r2, 2
	bl memcpy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _080F0208
	mov r5, r8
	movs r4, 0
	ldr r7, =gLinkPlayers
	b _080F0276
	.pool
_080F0238:
	lsls r0, r4, 3
	subs r2, r0, r4
	lsls r0, r2, 2
	adds r3, r0, r7
	ldrb r1, [r3]
	subs r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080F025A
	lsls r0, r2, 5
	adds r0, r4
	lsls r0, 2
	adds r0, r5, r0
	bl sub_80F1254
	b _080F0270
_080F025A:
	cmp r1, 0x3
	bne _080F0270
	ldrh r0, [r3, 0x1A]
	cmp r0, 0x1
	bne _080F0270
	lsls r0, r2, 5
	adds r0, r4
	lsls r0, 2
	adds r0, r5, r0
	bl sub_80F12A4
_080F0270:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080F0276:
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _080F0238
	cmp r6, 0x1
	beq _080F02C4
	cmp r6, 0x1
	bgt _080F0290
	cmp r6, 0
	beq _080F029A
	b _080F031E
_080F0290:
	cmp r6, 0x2
	beq _080F02DC
	cmp r6, 0x3
	beq _080F0304
	b _080F031E
_080F029A:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	movs r2, 0xE1
	lsls r2, 2
	adds r1, r5, r2
	movs r3, 0xE1
	lsls r3, 3
	adds r2, r5, r3
	ldr r4, =0x00000a8c
	adds r3, r5, r4
	bl sub_80F0358
	b _080F031E
	.pool
_080F02C4:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x000027cc
	adds r1, r0
	movs r3, 0xE1
	lsls r3, 3
	adds r2, r5, r3
	b _080F02EA
	.pool
_080F02DC:
	movs r0, 0xE1
	lsls r0, 2
	adds r1, r5, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r3, =0x000027cc
	adds r2, r3
_080F02EA:
	ldr r4, =0x00000a8c
	adds r3, r5, r4
	adds r0, r5, 0
	bl sub_80F0358
	b _080F031E
	.pool
_080F0304:
	movs r0, 0xE1
	lsls r0, 2
	adds r1, r5, r0
	movs r3, 0xE1
	lsls r3, 3
	adds r2, r5, r3
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r4, =0x000027cc
	adds r3, r4
	adds r0, r5, 0
	bl sub_80F0358
_080F031E:
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x000027cc
	adds r0, r4
	bl sub_80EF93C
	bl sub_80F0C04
	ldr r0, [r5]
	adds r0, r4
	bl sub_80EF93C
	bl sub_80F0708
	bl sub_80F0B64
	mov r0, r8
	bl Free
_080F0344:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F01E8

	thumb_func_start sub_80F0358
sub_80F0358: @ 80F0358
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	str r2, [sp, 0x18]
	str r3, [sp, 0x1C]
	add r0, sp, 0x10
	str r0, [sp]
	add r0, sp, 0x14
	str r0, [sp, 0x4]
	add r0, sp, 0x18
	str r0, [sp, 0x8]
	add r0, sp, 0x1C
	str r0, [sp, 0xC]
	bl sub_8009FCC
	ldr r1, =gUnknown_03001174
	strb r0, [r1]
_080F0384:
	movs r6, 0
	ldr r0, =gUnknown_03001174
	ldrb r1, [r0]
	cmp r6, r1
	bcs _080F0384
	mov r10, r0
_080F0390:
	cmp r6, 0
	bne _080F0398
	ldr r2, =gUnknown_0203A02C
	strb r6, [r2]
_080F0398:
	lsls r4, r6, 2
	mov r3, sp
	adds r0, r3, r4
	ldr r0, [r0]
	ldr r0, [r0]
	bl sub_80F06D0
	ldr r1, =gUnknown_03001176
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	adds r7, r4, 0
	cmp r0, r1
	bne _080F03E0
	ldr r1, =gUnknown_0203A02C
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	mov r2, r10
	ldrb r2, [r2]
	cmp r0, r2
	beq _080F048C
	adds r6, 0x1
	mov r9, r6
	b _080F0470
	.pool
_080F03E0:
	movs r5, 0
	mov r3, r10
	ldrb r0, [r3]
	subs r0, 0x1
	adds r2, r6, 0x1
	mov r9, r2
	cmp r5, r0
	bge _080F0456
	ldr r3, =gUnknown_03001174
	mov r8, r3
_080F03F4:
	adds r0, r6, r5
	adds r4, r0, 0x1
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r4, 0
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	ldr r0, [r0]
	bl sub_80EFB08
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080F0446
	mov r2, r8
	ldrb r1, [r2]
	adds r0, r4, 0
	bl __modsi3
	adds r2, r0, 0
	lsls r0, r2, 2
	add r0, sp
	ldr r0, [r0]
	mov r3, sp
	adds r1, r3, r7
	ldr r1, [r1]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80F049C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080F0456
_080F0446:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r8
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r5, r0
	blt _080F03F4
_080F0456:
	mov r2, r10
	ldrb r0, [r2]
	subs r0, 0x1
	cmp r5, r0
	bne _080F0470
	mov r3, sp
	adds r0, r3, r7
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, =gUnknown_03001176
	ldrb r1, [r1]
	bl sub_80EF910
_080F0470:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r6, r0, 24
	mov r2, r10
	ldrb r2, [r2]
	cmp r6, r2
	bcc _080F0390
	b _080F0384
	.pool
_080F048C:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F0358

	thumb_func_start sub_80F049C
sub_80F049C: @ 80F049C
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r4, [r0]
	ldr r6, [r1]
	movs r5, 0
	ldr r2, =gUnknown_03001176
	movs r1, 0
	ldrsb r1, [r2, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0]
	str r2, [sp]
	bl sub_80EFFE0
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	ldr r2, [sp]
	cmp r0, 0x3
	beq _080F050C
	cmp r0, 0x3
	bgt _080F04DC
	cmp r0, 0x2
	beq _080F04E2
	b _080F055A
	.pool
_080F04DC:
	cmp r1, 0x4
	beq _080F0534
	b _080F055A
_080F04E2:
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r6, r1
	adds r2, r7, 0
	bl sub_80F0580
	b _080F0556
	.pool
_080F050C:
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r6, r1
	adds r2, r7, 0
	bl sub_80F05E8
	b _080F0556
	.pool
_080F0534:
	ldr r0, =gUnknown_030060BC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r6, r1
	adds r2, r7, 0
	bl sub_80F0668
_080F0556:
	lsls r0, 24
	lsrs r5, r0, 24
_080F055A:
	cmp r5, 0x1
	beq _080F0568
	movs r0, 0
	b _080F0574
	.pool
_080F0568:
	ldr r0, =gUnknown_03001176
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80EF910
	movs r0, 0x1
_080F0574:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F049C

	thumb_func_start sub_80F0580
sub_80F0580: @ 80F0580
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_800A2A4
	adds r5, r0, 0
	movs r2, 0xFF
	ands r0, r2
	adds r1, r4, 0
	adds r1, 0x22
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F05B0
	lsrs r0, r5, 8
	ands r0, r2
	adds r1, r4, 0
	adds r1, 0x23
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F05B0
	movs r0, 0
	b _080F05E0
_080F05B0:
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r0, [r1]
	adds r2, r4, 0
	adds r2, 0x22
	strb r0, [r2]
	adds r3, r4, 0
	adds r3, 0x21
	ldrb r0, [r3]
	adds r2, 0x1
	strb r0, [r2]
	strb r5, [r1]
	lsrs r0, r5, 8
	strb r0, [r3]
	adds r1, r6, 0
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	strb r0, [r6, 0x1]
_080F05E0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F0580

	thumb_func_start sub_80F05E8
sub_80F05E8: @ 80F05E8
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_800A2A4
	adds r2, r0, 0
	movs r3, 0xFF
	ands r0, r3
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F0614
	lsrs r0, r2, 8
	ands r0, r3
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	cmp r0, r1
	beq _080F0634
_080F0614:
	movs r3, 0xFF
	adds r0, r2, 0
	ands r0, r3
	adds r1, r4, 0
	adds r1, 0x22
	lsrs r5, r2, 8
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F0638
	adds r0, r5, 0
	ands r0, r3
	adds r1, r4, 0
	adds r1, 0x23
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F0638
_080F0634:
	movs r0, 0
	b _080F0660
_080F0638:
	ldrb r1, [r4, 0x1E]
	adds r0, r4, 0
	adds r0, 0x20
	strb r1, [r0]
	ldrb r0, [r4, 0x1F]
	adds r1, r4, 0
	adds r1, 0x21
	strb r0, [r1]
	strb r2, [r4, 0x1E]
	strb r5, [r4, 0x1F]
	adds r1, r6, 0
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	strb r0, [r6, 0x1]
_080F0660:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F05E8

	thumb_func_start sub_80F0668
sub_80F0668: @ 80F0668
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_800A2A4
	adds r5, r0, 0
	movs r2, 0xFF
	ands r0, r2
	adds r1, r4, 0
	adds r1, 0x22
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F0698
	lsrs r0, r5, 8
	ands r0, r2
	adds r1, r4, 0
	adds r1, 0x23
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F0698
	movs r0, 0
	b _080F06CA
_080F0698:
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r0, [r1]
	adds r2, r4, 0
	adds r2, 0x22
	strb r0, [r2]
	adds r3, r4, 0
	adds r3, 0x21
	ldrb r0, [r3]
	adds r2, 0x1
	strb r0, [r2]
	strb r5, [r1]
	lsrs r0, r5, 8
	strb r0, [r3]
	adds r1, r6, 0
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	strb r0, [r6, 0x1]
	strh r0, [r6, 0x16]
_080F06CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F0668

	thumb_func_start sub_80F06D0
sub_80F06D0: @ 80F06D0
	push {lr}
	adds r3, r0, 0
	movs r2, 0
_080F06D6:
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r3
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _080F06F6
	ldrb r0, [r1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bhi _080F06F6
	lsls r0, r2, 24
	asrs r0, 24
	b _080F0704
_080F06F6:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x17
	bls _080F06D6
	movs r0, 0x1
	negs r0, r0
_080F0704:
	pop {r1}
	bx r1
	thumb_func_end sub_80F06D0

	thumb_func_start sub_80F0708
sub_80F0708: @ 80F0708
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	movs r0, 0
	mov r9, r0
_080F0716:
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	mov r4, r9
	lsls r2, r4, 3
	adds r0, r2, r4
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x000027cc
	adds r1, r0
	ldrb r0, [r1]
	adds r7, r2, 0
	cmp r0, 0x29
	bls _080F0732
	b _080F0AD8
_080F0732:
	lsls r0, 2
	ldr r1, =_080F0748
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F0748:
	.4byte _080F0AE2
	.4byte _080F0848
	.4byte _080F0AE2
	.4byte _080F0860
	.4byte _080F0878
	.4byte _080F0890
	.4byte _080F08BC
	.4byte _080F08D4
	.4byte _080F07F0
	.4byte _080F0AE2
	.4byte _080F081C
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0AD8
	.4byte _080F0900
	.4byte _080F0AE2
	.4byte _080F0918
	.4byte _080F0944
	.4byte _080F095C
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0974
	.4byte _080F09A0
	.4byte _080F0AE2
	.4byte _080F09C0
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F09F4
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0AD8
	.4byte _080F0AE2
_080F07F0:
	ldr r0, [r3]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0x12]
	lsls r5, r1, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0x2]
	b _080F09E6
	.pool
_080F081C:
	ldr r0, [r3]
	mov r2, r9
	adds r4, r7, r2
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0x16]
	lsls r5, r2, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0x2]
	b _080F09E6
	.pool
_080F0848:
	ldr r0, [r3]
	mov r4, r9
	adds r1, r7, r4
	lsls r1, 2
	adds r1, r0
	ldr r0, =0x000027cc
	adds r1, r0
	ldrh r0, [r1, 0x2]
	b _080F09B0
	.pool
_080F0860:
	ldr r0, [r3]
	mov r2, r9
	adds r1, r7, r2
	lsls r1, 2
	adds r1, r0
	ldr r4, =0x000027cc
	adds r1, r4
	ldrh r0, [r1, 0x2]
	lsls r1, r2, 24
	b _080F09B2
	.pool
_080F0878:
	ldr r0, [r3]
	mov r2, r9
	adds r1, r7, r2
	lsls r1, 2
	adds r1, r0
	ldr r4, =0x000027cc
	adds r1, r4
	ldrh r0, [r1, 0x6]
	lsls r1, r2, 24
	b _080F09B2
	.pool
_080F0890:
	ldr r0, [r3]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0x2]
	lsls r5, r1, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0x1C]
	b _080F09E6
	.pool
_080F08BC:
	ldr r0, [r3]
	mov r2, r9
	adds r1, r7, r2
	lsls r1, 2
	adds r1, r0
	ldr r4, =0x000027cc
	adds r1, r4
	ldrh r0, [r1, 0x2]
	lsls r1, r2, 24
	b _080F09B2
	.pool
_080F08D4:
	ldr r0, [r3]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0xA]
	lsls r5, r1, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0x14]
	b _080F09E6
	.pool
_080F0900:
	ldr r0, [r3]
	mov r2, r9
	adds r1, r7, r2
	lsls r1, 2
	adds r1, r0
	ldr r4, =0x000027cc
	adds r1, r4
	ldrh r0, [r1, 0x10]
	lsls r1, r2, 24
	b _080F09B2
	.pool
_080F0918:
	ldr r0, [r3]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0xC]
	lsls r5, r1, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0xE]
	b _080F09E6
	.pool
_080F0944:
	ldr r0, [r3]
	mov r2, r9
	adds r1, r7, r2
	lsls r1, 2
	adds r1, r0
	ldr r4, =0x000027cc
	adds r1, r4
	ldrh r0, [r1, 0x4]
	lsls r1, r2, 24
	b _080F09B2
	.pool
_080F095C:
	ldr r0, [r3]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0x8]
	b _080F09D0
	.pool
_080F0974:
	ldr r0, [r3]
	mov r2, r9
	adds r4, r7, r2
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0x2]
	lsls r5, r2, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0xA]
	b _080F09E6
	.pool
_080F09A0:
	ldr r0, [r3]
	mov r4, r9
	adds r1, r7, r4
	lsls r1, 2
	adds r1, r0
	ldr r0, =0x000027cc
	adds r1, r0
	ldrh r0, [r1, 0x8]
_080F09B0:
	lsls r1, r4, 24
_080F09B2:
	lsrs r1, 24
	bl sub_80F0B24
	b _080F0AE2
	.pool
_080F09C0:
	ldr r0, [r3]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r6, =0x000027cc
	adds r0, r6
	ldrh r0, [r0, 0x6]
_080F09D0:
	lsls r5, r1, 24
	lsrs r5, 24
	adds r1, r5, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r6
	ldrh r0, [r4, 0x4]
_080F09E6:
	adds r1, r5, 0
	bl sub_80F0B24
	b _080F0AE2
	.pool
_080F09F4:
	ldr r0, [r3]
	mov r2, r9
	adds r4, r7, r2
	lsls r4, 2
	adds r0, r4, r0
	ldr r5, =0x000027cc
	adds r0, r5
	ldrh r0, [r0, 0x4]
	lsls r2, 24
	mov r8, r2
	lsrs r6, r2, 24
	adds r1, r6, 0
	str r3, [sp, 0x4]
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r0, r4, r0
	adds r0, r5
	ldrh r0, [r0, 0x6]
	adds r1, r6, 0
	bl sub_80F0B24
	ldr r3, [sp, 0x4]
	ldr r0, [r3]
	adds r4, r0
	adds r4, r5
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	mov r6, r8
	cmp r0, 0xC
	bhi _080F0AE2
	lsls r0, 2
	ldr r1, =_080F0A48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F0A48:
	.4byte _080F0A7C
	.4byte _080F0AA0
	.4byte _080F0AE2
	.4byte _080F0AE2
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
	.4byte _080F0A7C
_080F0A7C:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	mov r4, r9
	adds r0, r7, r4
	lsls r0, 2
	adds r0, r1
	ldr r1, =0x000027cc
	adds r0, r1
	ldrh r0, [r0, 0x8]
	lsrs r1, r6, 24
	bl sub_80F0B24
	b _080F0AE2
	.pool
_080F0AA0:
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	mov r1, r9
	adds r4, r7, r1
	lsls r4, 2
	adds r0, r4, r0
	ldr r5, =0x000027cc
	adds r0, r5
	ldrh r0, [r0, 0x8]
	lsrs r6, 24
	adds r1, r6, 0
	str r2, [sp]
	bl sub_80F0B24
	ldr r2, [sp]
	ldr r0, [r2]
	adds r4, r0
	adds r4, r5
	ldrh r0, [r4, 0xA]
	adds r1, r6, 0
	bl sub_80F0B24
	b _080F0AE2
	.pool
_080F0AD8:
	mov r2, r9
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_80F0B00
_080F0AE2:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0x17
	bhi _080F0AF2
	b _080F0716
_080F0AF2:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F0708

	thumb_func_start sub_80F0B00
sub_80F0B00: @ 80F0B00
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	ldr r0, =0x000027cd
	adds r2, r0
	movs r0, 0
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80F0B00

	thumb_func_start sub_80F0B24
sub_80F0B24: @ 80F0B24
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
	lsls r0, 24
	asrs r2, r0, 24
	cmp r2, 0
	bne _080F0B56
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x000027cd
	adds r1, r0
	strb r2, [r1]
_080F0B56:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0B24

	thumb_func_start sub_80F0B64
sub_80F0B64: @ 80F0B64
	push {r4-r6,lr}
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080F0BA2
	movs r2, 0
	ldr r4, =0x000027cd
	movs r3, 0
	ldr r5, =gSaveBlock1Ptr
_080F0B7C:
	ldr r0, [r5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r0, r1
	ldr r6, =0x000027cc
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0x7
	beq _080F0B94
	cmp r0, 0x29
	bne _080F0B98
_080F0B94:
	adds r0, r1, r4
	strb r3, [r0]
_080F0B98:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x17
	bls _080F0B7C
_080F0BA2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0B64

	thumb_func_start sub_80F0BB8
sub_80F0BB8: @ 80F0BB8
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gSaveBlock1Ptr
_080F0BBE:
	ldr r1, [r6]
	lsls r0, r5, 3
	adds r0, r5
	lsls r4, r0, 2
	adds r1, r4
	ldr r0, =0x000027cc
	adds r1, r0
	ldrb r0, [r1]
	bl sub_80EFFE0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080F0BE6
	ldr r0, [r6]
	adds r0, r4
	ldr r1, =0x000027cd
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080F0BE6:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _080F0BBE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0BB8

	thumb_func_start sub_80F0C04
sub_80F0C04: @ 80F0C04
	push {r4,r5,lr}
	movs r3, 0
	movs r2, 0x5
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r5, =0x000027cc
_080F0C10:
	lsls r0, r2, 24
	asrs r1, r0, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F0C2E
	lsls r0, r3, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r3, r0, 24
_080F0C2E:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x17
	ble _080F0C10
	movs r2, 0
	lsls r0, r3, 24
	asrs r0, 24
	movs r1, 0x5
	subs r0, r1, r0
	cmp r2, r0
	bge _080F0C6E
	adds r5, r0, 0
_080F0C4A:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000027cc
	adds r0, r1
	lsls r1, r2, 24
	asrs r4, r1, 24
	movs r2, 0xA0
	lsls r2, 19
	adds r1, r2
	lsrs r1, 24
	bl sub_80EF910
	adds r4, 0x1
	lsls r4, 24
	lsrs r2, r4, 24
	asrs r4, 24
	cmp r4, r5
	blt _080F0C4A
_080F0C6E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0C04

	thumb_func_start sub_80F0C7C
sub_80F0C7C: @ 80F0C7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	movs r0, 0x80
	lsls r0, 1
	bl Alloc
	adds r5, r0, 0
	cmp r5, 0
	beq _080F0D4C
	movs r4, 0
_080F0C9A:
	lsls r0, r4, 6
	adds r0, r5
	adds r1, r4, 0
	muls r1, r7
	add r1, r8
	movs r2, 0x40
	bl memcpy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _080F0C9A
	cmp r6, 0x1
	beq _080F0CF0
	cmp r6, 0x1
	bgt _080F0CC2
	cmp r6, 0
	beq _080F0CCC
	b _080F0D3E
_080F0CC2:
	cmp r6, 0x2
	beq _080F0D08
	cmp r6, 0x3
	beq _080F0D28
	b _080F0D3E
_080F0CCC:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002b50
	adds r0, r1
	adds r1, r5, 0
	adds r1, 0x40
	adds r2, r5, 0
	adds r2, 0x80
	adds r3, r5, 0
	adds r3, 0xC0
	bl sub_80F0D60
	b _080F0D3E
	.pool
_080F0CF0:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002b50
	adds r1, r0
	adds r2, r5, 0
	adds r2, 0x80
	b _080F0D14
	.pool
_080F0D08:
	adds r1, r5, 0
	adds r1, 0x40
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00002b50
	adds r2, r0
_080F0D14:
	adds r3, r5, 0
	adds r3, 0xC0
	adds r0, r5, 0
	bl sub_80F0D60
	b _080F0D3E
	.pool
_080F0D28:
	adds r1, r5, 0
	adds r1, 0x40
	adds r2, r5, 0
	adds r2, 0x80
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r0, =0x00002b50
	adds r3, r0
	adds r0, r5, 0
	bl sub_80F0D60
_080F0D3E:
	bl sub_80F0EEC
	bl sub_80F0F24
	adds r0, r5, 0
	bl Free
_080F0D4C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0C7C

	thumb_func_start sub_80F0D60
sub_80F0D60: @ 80F0D60
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	str r2, [sp, 0x18]
	str r3, [sp, 0x1C]
	add r0, sp, 0x10
	str r0, [sp]
	add r0, sp, 0x14
	str r0, [sp, 0x4]
	add r0, sp, 0x18
	str r0, [sp, 0x8]
	add r0, sp, 0x1C
	str r0, [sp, 0xC]
	bl sub_8009FCC
	ldr r1, =gUnknown_03001175
	strb r0, [r1]
	movs r0, 0
	mov r10, r0
_080F0D90:
	movs r7, 0
	mov r1, r10
	adds r1, 0x1
	str r1, [sp, 0x20]
	b _080F0E28
	.pool
_080F0DA0:
	lsls r4, r7, 2
	mov r1, sp
	adds r0, r1, r4
	ldr r0, [r0]
	ldr r0, [r0]
	mov r1, r10
	bl sub_80F0ECC
	ldr r1, =gUnknown_03001176
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	mov r8, r4
	adds r1, r7, 0x1
	mov r9, r1
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080F0E22
	movs r5, 0
	ldr r1, =gUnknown_03001175
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r5, r0
	bge _080F0E22
	adds r6, r1, 0
_080F0DD4:
	adds r0, r7, r5
	adds r4, r0, 0x1
	ldrb r1, [r6]
	adds r0, r4, 0
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	ldr r0, [r0]
	bl sub_80EEE30
	ldr r1, =gUnknown_030060BC
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080F0E14
	ldrb r1, [r6]
	adds r0, r4, 0
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	mov r1, sp
	add r1, r8
	ldr r1, [r1]
	bl sub_80F0E58
_080F0E14:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r6]
	subs r0, 0x1
	cmp r5, r0
	blt _080F0DD4
_080F0E22:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r7, r0, 24
_080F0E28:
	ldr r0, =gUnknown_03001175
	ldrb r0, [r0]
	cmp r7, r0
	bcc _080F0DA0
	ldr r1, [sp, 0x20]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0xF
	bls _080F0D90
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0D60

	thumb_func_start sub_80F0E58
sub_80F0E58: @ 80F0E58
	push {lr}
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, =gUnknown_03001176
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	lsls r2, 2
	adds r1, r2
	ldr r2, =gUnknown_030060BC
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	bl sub_80F0E84
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0E58

	thumb_func_start sub_80F0E84
sub_80F0E84: @ 80F0E84
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	ldrb r3, [r5]
	adds r0, r3, 0
	cmp r0, 0
	bne _080F0E9A
_080F0E96:
	movs r0, 0
	b _080F0EC6
_080F0E9A:
	movs r1, 0
	adds r2, r3, 0
	adds r3, r0, 0
_080F0EA0:
	lsls r0, r1, 2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r3
	beq _080F0E96
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _080F0EA0
	lsls r0, r6, 24
	asrs r0, 22
	adds r0, r4
	strb r2, [r0]
	movs r1, 0x1
	strb r1, [r0, 0x1]
	ldrh r1, [r5, 0x2]
	strh r1, [r0, 0x2]
	movs r0, 0x1
_080F0EC6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F0E84

	thumb_func_start sub_80F0ECC
sub_80F0ECC: @ 80F0ECC
	push {lr}
	lsls r1, 24
	lsrs r2, r1, 24
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080F0EE2
	lsls r0, r2, 24
	asrs r0, 24
	b _080F0EE6
_080F0EE2:
	movs r0, 0x1
	negs r0, r0
_080F0EE6:
	pop {r1}
	bx r1
	thumb_func_end sub_80F0ECC

	thumb_func_start sub_80F0EEC
sub_80F0EEC: @ 80F0EEC
	push {r4,lr}
	movs r4, 0
_080F0EF0:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r0, r1
	ldr r1, =0x00002b50
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _080F0F08
	adds r0, r4, 0
	bl sub_80EEE78
_080F0F08:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080F0EF0
	bl sub_80EEEB8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0EEC

	thumb_func_start sub_80F0F24
sub_80F0F24: @ 80F0F24
	push {r4,r5,lr}
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080F0F50
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002b51
	movs r3, 0
_080F0F3C:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r1
	adds r0, r4
	strb r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080F0F3C
_080F0F50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F0F24

	thumb_func_start sub_80F0F64
sub_80F0F64: @ 80F0F64
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0x2C
	bl AllocZeroed
	adds r4, r0, 0
	movs r7, 0
_080F0F74:
	lsls r0, r7, 3
	adds r1, r0, r7
	lsls r1, 2
	adds r1, r6
	ldrb r1, [r1]
	subs r1, 0x1
	adds r2, r0, 0
	cmp r1, 0x28
	bls _080F0F88
	b _080F11F4
_080F0F88:
	lsls r0, r1, 2
	ldr r1, =_080F0F98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F0F98:
	.4byte _080F103C
	.4byte _080F103C
	.4byte _080F105A
	.4byte _080F11F4
	.4byte _080F1152
	.4byte _080F111E
	.4byte _080F10E6
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F1092
	.4byte _080F10C6
	.4byte _080F118A
	.4byte _080F11AA
	.4byte _080F11CA
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11F4
	.4byte _080F11EA
_080F103C:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4]
	adds r0, 0x10
	bl sub_8009228
	cmp r0, 0
	beq _080F1056
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x18]
	b _080F11F4
_080F1056:
	ldr r0, [r4]
	b _080F11F2
_080F105A:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x4]
	adds r0, 0x5
	bl sub_8009228
	cmp r0, 0
	beq _080F1074
	ldr r1, [r4, 0x4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	b _080F1078
_080F1074:
	ldr r0, [r4, 0x4]
	strb r5, [r0, 0xD]
_080F1078:
	ldr r0, [r4, 0x4]
	adds r0, 0x10
	bl sub_8009228
	cmp r0, 0
	beq _080F108C
	ldr r1, [r4, 0x4]
	movs r0, 0x1
	strb r0, [r1, 0xE]
	b _080F11F4
_080F108C:
	ldr r0, [r4, 0x4]
	strb r5, [r0, 0xE]
	b _080F11F4
_080F1092:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x18]
	adds r0, 0x13
	bl sub_8009228
	cmp r0, 0
	beq _080F10AC
	ldr r1, [r4, 0x18]
	movs r0, 0x1
	strb r0, [r1, 0x2]
	b _080F10B0
_080F10AC:
	ldr r0, [r4, 0x18]
	strb r5, [r0, 0x2]
_080F10B0:
	ldr r0, [r4, 0x18]
	adds r0, 0x4
	bl sub_8009228
	cmp r0, 0
	beq _080F10C0
	ldr r1, [r4, 0x18]
	b _080F10DA
_080F10C0:
	ldr r0, [r4, 0x18]
	strb r5, [r0, 0x3]
	b _080F11F4
_080F10C6:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x1C]
	adds r0, 0x13
	bl sub_8009228
	cmp r0, 0
	beq _080F10E0
	ldr r1, [r4, 0x1C]
_080F10DA:
	movs r0, 0x1
	strb r0, [r1, 0x3]
	b _080F11F4
_080F10E0:
	ldr r0, [r4, 0x1C]
	strb r5, [r0, 0x3]
	b _080F11F4
_080F10E6:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x14]
	adds r0, 0x2
	bl sub_8009228
	cmp r0, 0
	beq _080F1100
	ldr r1, [r4, 0x14]
	movs r0, 0x1
	strb r0, [r1, 0x1D]
	b _080F1104
_080F1100:
	ldr r0, [r4, 0x14]
	strb r5, [r0, 0x1D]
_080F1104:
	ldr r0, [r4, 0x14]
	adds r0, 0xC
	bl sub_8009228
	cmp r0, 0
	beq _080F1118
	ldr r1, [r4, 0x14]
	movs r0, 0x1
	strb r0, [r1, 0x1E]
	b _080F11F4
_080F1118:
	ldr r0, [r4, 0x14]
	strb r5, [r0, 0x1E]
	b _080F11F4
_080F111E:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x10]
	adds r0, 0x16
	bl sub_8009228
	cmp r0, 0
	beq _080F1138
	ldr r1, [r4, 0x10]
	movs r0, 0x1
	strb r0, [r1, 0x1E]
	b _080F113C
_080F1138:
	ldr r0, [r4, 0x10]
	strb r5, [r0, 0x1E]
_080F113C:
	ldr r0, [r4, 0x10]
	adds r0, 0x8
	bl sub_8009228
	cmp r0, 0
	beq _080F114C
	ldr r1, [r4, 0x10]
	b _080F117E
_080F114C:
	ldr r0, [r4, 0x10]
	strb r5, [r0, 0x1F]
	b _080F11F4
_080F1152:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0xC]
	adds r0, 0xF
	bl sub_8009228
	cmp r0, 0
	beq _080F116C
	ldr r1, [r4, 0xC]
	movs r0, 0x1
	strb r0, [r1, 0x1E]
	b _080F1170
_080F116C:
	ldr r0, [r4, 0xC]
	strb r5, [r0, 0x1E]
_080F1170:
	ldr r0, [r4, 0xC]
	adds r0, 0x4
	bl sub_8009228
	cmp r0, 0
	beq _080F1184
	ldr r1, [r4, 0xC]
_080F117E:
	movs r0, 0x1
	strb r0, [r1, 0x1F]
	b _080F11F4
_080F1184:
	ldr r0, [r4, 0xC]
	strb r5, [r0, 0x1F]
	b _080F11F4
_080F118A:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x8]
	adds r0, 0x13
	bl sub_8009228
	cmp r0, 0
	beq _080F11A4
	ldr r1, [r4, 0x8]
	movs r0, 0x1
	strb r0, [r1, 0x2]
	b _080F11F4
_080F11A4:
	ldr r0, [r4, 0x8]
	strb r5, [r0, 0x2]
	b _080F11F4
_080F11AA:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x20]
	adds r0, 0x13
	bl sub_8009228
	cmp r0, 0
	beq _080F11C4
	ldr r1, [r4, 0x20]
	movs r0, 0x1
	strb r0, [r1, 0x6]
	b _080F11F4
_080F11C4:
	ldr r0, [r4, 0x20]
	strb r5, [r0, 0x6]
	b _080F11F4
_080F11CA:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x24]
	adds r0, 0x13
	bl sub_8009228
	cmp r0, 0
	beq _080F11E4
	ldr r1, [r4, 0x24]
	movs r0, 0x1
	strb r0, [r1, 0xB]
	b _080F11F4
_080F11E4:
	ldr r0, [r4, 0x24]
	strb r5, [r0, 0xB]
	b _080F11F4
_080F11EA:
	adds r0, r2, r7
	lsls r0, 2
	adds r0, r6, r0
	str r0, [r4, 0x28]
_080F11F2:
	strb r5, [r0, 0x18]
_080F11F4:
	adds r7, 0x1
	cmp r7, 0x17
	bgt _080F11FC
	b _080F0F74
_080F11FC:
	adds r0, r4, 0
	bl Free
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F0F64

	thumb_func_start sub_80F1208
sub_80F1208: @ 80F1208
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_80F14F8
	adds r4, r5, 0
	movs r1, 0xD8
	lsls r1, 2
	adds r0, r4, r1
	cmp r4, r0
	bcs _080F124C
_080F121C:
	ldrb r0, [r4]
	cmp r0, 0x7
	bne _080F1240
	ldrb r0, [r4, 0x1D]
	cmp r0, 0x1
	bne _080F1230
	ldrb r0, [r4, 0x1E]
	cmp r0, 0x1
	bne _080F1236
	b _080F1240
_080F1230:
	ldrb r0, [r4, 0x1E]
	cmp r0, 0x1
	bne _080F1240
_080F1236:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x24
	bl memset
_080F1240:
	adds r4, 0x24
	movs r1, 0xD8
	lsls r1, 2
	adds r0, r5, r1
	cmp r4, r0
	bcc _080F121C
_080F124C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F1208

	thumb_func_start sub_80F1254
sub_80F1254: @ 80F1254
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r4, 0
	movs r1, 0xD8
	lsls r1, 2
	adds r0, r4, r1
	cmp r4, r0
	bcs _080F128A
_080F1264:
	ldrb r0, [r4]
	cmp r0, 0x7
	bne _080F127E
	adds r0, r4, 0
	adds r0, 0xC
	bl sub_8009228
	cmp r0, 0
	beq _080F127A
	movs r0, 0x1
	b _080F127C
_080F127A:
	movs r0, 0x2
_080F127C:
	strb r0, [r4, 0x1E]
_080F127E:
	adds r4, 0x24
	movs r1, 0xD8
	lsls r1, 2
	adds r0, r5, r1
	cmp r4, r0
	bcc _080F1264
_080F128A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F1254

	thumb_func_start sub_80F1290
sub_80F1290: @ 80F1290
	push {lr}
	bl sub_8009228
	movs r1, 0x2
	cmp r0, 0
	beq _080F129E
	movs r1, 0x1
_080F129E:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80F1290

	thumb_func_start sub_80F12A4
sub_80F12A4: @ 80F12A4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r4, 0
	movs r1, 0xD8
	lsls r1, 2
	adds r0, r4, r1
	cmp r4, r0
	bcc _080F12B6
	b _080F14F0
_080F12B6:
	ldrb r0, [r4]
	subs r0, 0x1
	cmp r0, 0x28
	bls _080F12C0
	b _080F14E2
_080F12C0:
	lsls r0, 2
	ldr r1, =_080F12D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F12D0:
	.4byte _080F1374
	.4byte _080F137A
	.4byte _080F1380
	.4byte _080F138E
	.4byte _080F139A
	.4byte _080F13A8
	.4byte _080F13BE
	.4byte _080F13CC
	.4byte _080F13E0
	.4byte _080F13F4
	.4byte _080F1408
	.4byte _080F1416
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F14E2
	.4byte _080F142A
	.4byte _080F1438
	.4byte _080F1444
	.4byte _080F1450
	.4byte _080F145C
	.4byte _080F14AC
	.4byte _080F1468
	.4byte _080F14B8
	.4byte _080F148C
	.4byte _080F1474
	.4byte _080F14AC
	.4byte _080F14B8
	.4byte _080F1480
	.4byte _080F148C
	.4byte _080F1498
	.4byte _080F14AC
	.4byte _080F14B8
	.4byte _080F14C4
	.4byte _080F14D8
	.4byte _080F14E2
	.4byte _080F14E2
_080F1374:
	adds r0, r4, 0
	adds r0, 0x10
	b _080F1422
_080F137A:
	adds r0, r4, 0
	adds r0, 0x10
	b _080F1422
_080F1380:
	adds r0, r4, 0x5
	bl sub_80F1290
	strb r0, [r4, 0xD]
	adds r0, r4, 0
	adds r0, 0x10
	b _080F1478
_080F138E:
	adds r0, r4, 0
	adds r0, 0xB
	bl sub_80F1290
	strb r0, [r4, 0x17]
	b _080F14E2
_080F139A:
	adds r0, r4, 0
	adds r0, 0xF
	bl sub_80F1290
	strb r0, [r4, 0x1E]
	adds r0, r4, 0x4
	b _080F13B6
_080F13A8:
	adds r0, r4, 0
	adds r0, 0x16
	bl sub_80F1290
	strb r0, [r4, 0x1E]
	adds r0, r4, 0
	adds r0, 0x8
_080F13B6:
	bl sub_80F1290
	strb r0, [r4, 0x1F]
	b _080F14E2
_080F13BE:
	adds r0, r4, 0x2
	bl sub_80F1290
	strb r0, [r4, 0x1D]
	adds r0, r4, 0
	adds r0, 0xC
	b _080F13D8
_080F13CC:
	adds r0, r4, 0
	adds r0, 0x14
	bl sub_80F1290
	strb r0, [r4, 0x1D]
	adds r0, r4, 0x4
_080F13D8:
	bl sub_80F1290
	strb r0, [r4, 0x1E]
	b _080F14E2
_080F13E0:
	adds r0, r4, 0
	adds r0, 0xC
	bl sub_80F1290
	strb r0, [r4, 0x14]
	adds r0, r4, 0x4
	bl sub_80F1290
	strb r0, [r4, 0x15]
	b _080F14E2
_080F13F4:
	adds r0, r4, 0x4
	bl sub_80F1290
	strb r0, [r4, 0x19]
	adds r0, r4, 0
	adds r0, 0xC
	bl sub_80F1290
	strb r0, [r4, 0x1A]
	b _080F14E2
_080F1408:
	adds r0, r4, 0x2
	bl sub_80F1290
	strb r0, [r4, 0x17]
	adds r0, r4, 0
	adds r0, 0xC
	b _080F1422
_080F1416:
	adds r0, r4, 0x2
	bl sub_80F1290
	strb r0, [r4, 0x17]
	adds r0, r4, 0
	adds r0, 0xB
_080F1422:
	bl sub_80F1290
	strb r0, [r4, 0x18]
	b _080F14E2
_080F142A:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x2]
	adds r0, r4, 0x4
	b _080F143C
_080F1438:
	adds r0, r4, 0
	adds r0, 0x13
_080F143C:
	bl sub_80F1290
	strb r0, [r4, 0x3]
	b _080F14E2
_080F1444:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x2]
	b _080F14E2
_080F1450:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x6]
	b _080F14E2
_080F145C:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0xB]
	b _080F14E2
_080F1468:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x9]
	b _080F14E2
_080F1474:
	adds r0, r4, 0
	adds r0, 0x13
_080F1478:
	bl sub_80F1290
	strb r0, [r4, 0xE]
	b _080F14E2
_080F1480:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x11]
	b _080F14E2
_080F148C:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x8]
	b _080F14E2
_080F1498:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0xF]
	adds r0, r4, 0x4
	bl sub_80F1290
	strb r0, [r4, 0x10]
	b _080F14E2
_080F14AC:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0xC]
	b _080F14E2
_080F14B8:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x5]
	b _080F14E2
_080F14C4:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x1B]
	adds r0, r4, 0x4
	bl sub_80F1290
	strb r0, [r4, 0x1C]
	b _080F14E2
_080F14D8:
	adds r0, r4, 0
	adds r0, 0x13
	bl sub_80F1290
	strb r0, [r4, 0x4]
_080F14E2:
	adds r4, 0x24
	movs r1, 0xD8
	lsls r1, 2
	adds r0, r5, r1
	cmp r4, r0
	bcs _080F14F0
	b _080F12B6
_080F14F0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F12A4

	thumb_func_start sub_80F14F8
sub_80F14F8: @ 80F14F8
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	movs r6, 0x17
_080F1500:
	ldrb r0, [r4]
	cmp r0, 0x17
	beq _080F151C
	cmp r0, 0x19
	bne _080F152C
	ldrb r0, [r4, 0xA]
	cmp r0, 0x58
	bls _080F152C
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x24
	bl memset
	b _080F152C
_080F151C:
	ldrb r0, [r4, 0x12]
	cmp r0, 0x58
	bls _080F152C
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x24
	bl memset
_080F152C:
	adds r4, 0x24
	adds r5, 0x24
	subs r6, 0x1
	cmp r6, 0
	bge _080F1500
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80F14F8

    .section .text.dotvshow

	thumb_func_start DoTVShowTodaysSmartShopper
DoTVShowTodaysSmartShopper: @ 80F1C0C
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	adds r2, r0, 0
	cmp r6, 0xC
	bls _080F1C34
	b _080F1E2C
_080F1C34:
	lsls r0, r6, 2
	ldr r1, =_080F1C58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F1C58:
	.4byte _080F1C8C
	.4byte _080F1CC8
	.4byte _080F1D10
	.4byte _080F1D22
	.4byte _080F1D10
	.4byte _080F1D10
	.4byte _080F1D4C
	.4byte _080F1D7C
	.4byte _080F1DAC
	.4byte _080F1DB8
	.4byte _080F1DC6
	.4byte _080F1DD8
	.4byte _080F1E1C
_080F1C8C:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x12]
	movs r2, 0
	bl GetMapName
	ldrh r0, [r5, 0xC]
	cmp r0, 0xFE
	bls _080F1CBC
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1CBC:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1CC8:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	ldr r4, =gStringVar2
	ldrh r0, [r5, 0x6]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrh r1, [r5, 0xC]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldr r4, =sTVShowState
	bl Random
	ldrb r2, [r4]
	adds r2, 0x1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r0, r2
	strb r0, [r4]
	b _080F1E2C
	.pool
_080F1D10:
	ldrh r0, [r5, 0x8]
	cmp r0, 0
	beq _080F1D1C
	movs r0, 0x6
	strb r0, [r2]
	b _080F1E2C
_080F1D1C:
	movs r0, 0xA
	strb r0, [r2]
	b _080F1E2C
_080F1D22:
	ldrh r1, [r5, 0xC]
	adds r1, 0x1
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldrh r0, [r5, 0x8]
	cmp r0, 0
	beq _080F1D40
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1D40:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1D4C:
	ldr r4, =gStringVar2
	ldrh r0, [r5, 0x8]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrh r1, [r5, 0xE]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldrh r0, [r5, 0xA]
	cmp r0, 0
	beq _080F1D94
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1D7C:
	ldr r4, =gStringVar2
	ldrh r0, [r5, 0xA]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrh r1, [r5, 0x10]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
_080F1D94:
	ldrb r0, [r5, 0x2]
	cmp r0, 0x1
	beq _080F1DFA
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1DAC:
	ldrh r0, [r5, 0xC]
	cmp r0, 0xFE
	bls _080F1DD2
	movs r0, 0xC
	strb r0, [r2]
	b _080F1E2C
_080F1DB8:
	movs r0, 0x1
	adds r1, r5, 0
	bl sub_80EF40C
	bl TVShowDone
	b _080F1E2C
_080F1DC6:
	ldrb r0, [r5, 0x2]
	cmp r0, 0x1
	bne _080F1DD2
	movs r0, 0x8
	strb r0, [r2]
	b _080F1E2C
_080F1DD2:
	movs r0, 0x9
	strb r0, [r2]
	b _080F1E2C
_080F1DD8:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	ldr r4, =gStringVar2
	ldrh r0, [r5, 0x6]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrb r0, [r5, 0x2]
	cmp r0, 0x1
	bne _080F1E10
_080F1DFA:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1E10:
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F1E2C
	.pool
_080F1E1C:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F1E2C:
	ldr r0, =gUnknown_0858D1D0
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTodaysSmartShopper

	thumb_func_start DoTVShowTheNameRaterShow
DoTVShowTheNameRaterShow: @ 80F1E48
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	adds r2, r0, 0
	cmp r6, 0x12
	bls _080F1E72
	b _080F20FE
_080F1E72:
	lsls r0, r6, 2
	ldr r1, =_080F1E94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F1E94:
	.4byte _080F1EE0
	.4byte _080F1F28
	.4byte _080F1F4A
	.4byte _080F1F28
	.4byte _080F1F28
	.4byte _080F1F28
	.4byte _080F1F28
	.4byte _080F1F28
	.4byte _080F1F28
	.4byte _080F1F90
	.4byte _080F1F90
	.4byte _080F1F90
	.4byte _080F20EC
	.4byte _080F1FCC
	.4byte _080F200C
	.4byte _080F202C
	.4byte _080F2074
	.4byte _080F20A4
	.4byte _080F20F0
_080F1EE0:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0xF
	ldrb r2, [r5, 0x1E]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1F]
	bl TVShowConvertInternationalString
	ldr r4, =sTVShowState
	adds r0, r5, 0
	bl sub_80EFBA4
	adds r0, 0x1
	strb r0, [r4]
	b _080F20FE
	.pool
_080F1F28:
	ldrb r0, [r5, 0x1A]
	cmp r0, 0
	bne _080F1F34
	movs r0, 0x9
	strb r0, [r2]
	b _080F20FE
_080F1F34:
	cmp r0, 0x1
	bne _080F1F3E
	movs r0, 0xA
	strb r0, [r2]
	b _080F20FE
_080F1F3E:
	cmp r0, 0x2
	beq _080F1F44
	b _080F20FE
_080F1F44:
	movs r0, 0xB
	strb r0, [r2]
	b _080F20FE
_080F1F4A:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0xF
	ldrb r2, [r5, 0x1E]
	bl TVShowConvertInternationalString
	ldrb r0, [r5, 0x1A]
	cmp r0, 0
	bne _080F1F6C
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F20FE
	.pool
_080F1F6C:
	cmp r0, 0x1
	bne _080F1F7C
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F20FE
	.pool
_080F1F7C:
	cmp r0, 0x2
	beq _080F1F82
	b _080F20FE
_080F1F82:
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F20FE
	.pool
_080F1F90:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1F]
	bl TVShowConvertInternationalString
	movs r4, 0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_80EFBDC
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl sub_80EFBDC
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F20FE
	.pool
_080F1FCC:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0xF
	ldrb r2, [r5, 0x1E]
	bl TVShowConvertInternationalString
	movs r4, 0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x2
	movs r3, 0
	bl sub_80EFBDC
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_80EFBDC
	ldr r1, =sTVShowState
	movs r0, 0xE
	strb r0, [r1]
	b _080F20FE
	.pool
_080F200C:
	movs r4, 0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_80EFBDC
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x3
	movs r3, 0
	b _080F20D2
_080F202C:
	movs r0, 0
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_80EFBDC
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrh r0, [r5, 0x2]
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x2
	bl sub_80EFBDC
	ldr r1, =sTVShowState
	movs r0, 0x10
	strb r0, [r1]
	b _080F20FE
	.pool
_080F2074:
	ldrh r0, [r5, 0x2]
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl sub_80EFBDC
	movs r0, 0
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_80EFBDC
	ldr r1, =sTVShowState
	movs r0, 0x11
	strb r0, [r1]
	b _080F20FE
	.pool
_080F20A4:
	movs r0, 0
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_80EFBDC
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x1C]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrh r0, [r5, 0x1C]
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x2
_080F20D2:
	bl sub_80EFBDC
	ldr r1, =sTVShowState
	movs r0, 0x12
	strb r0, [r1]
	b _080F20FE
	.pool
_080F20EC:
	movs r6, 0x12
	strb r6, [r2]
_080F20F0:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1F]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F20FE:
	ldr r0, =gUnknown_0858D338
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTheNameRaterShow

	thumb_func_start DoTVShowPokemonTodaySuccessfulCapture
DoTVShowPokemonTodaySuccessfulCapture: @ 80F211C
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	adds r2, r0, 0
	cmp r6, 0xB
	bls _080F2144
	b _080F2358
_080F2144:
	lsls r0, r6, 2
	ldr r1, =_080F2168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2168:
	.4byte _080F2198
	.4byte _080F21EC
	.4byte _080F21F2
	.4byte _080F222C
	.4byte _080F2264
	.4byte _080F226A
	.4byte _080F22A0
	.4byte _080F22F4
	.4byte _080F22F4
	.4byte _080F2324
	.4byte _080F2324
	.4byte _080F2354
_080F2198:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x2]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x10]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	ldrb r0, [r5, 0xF]
	cmp r0, 0x1
	bne _080F21E0
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F2358
	.pool
_080F21E0:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F2358
	.pool
_080F21EC:
	movs r0, 0x2
	strb r0, [r2]
	b _080F2358
_080F21F2:
	ldr r4, =gStringVar2
	ldrb r0, [r5, 0xF]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrb r1, [r5, 0x12]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldrb r0, [r5, 0x12]
	cmp r0, 0x3
	bhi _080F2220
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F2358
	.pool
_080F2220:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F2358
	.pool
_080F222C:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x2]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x10]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	b _080F2286
	.pool
_080F2264:
	movs r0, 0x6
	strb r0, [r2]
	b _080F2358
_080F226A:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x2]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x10]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
_080F2286:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F2358
	.pool
_080F22A0:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x2]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x10]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	ldr r4, =sTVShowState
	bl Random
	ldrb r2, [r4]
	adds r2, 0x1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r0, r2
	strb r0, [r4]
	b _080F2358
	.pool
_080F22F4:
	ldr r0, =gStringVar1
	ldrh r1, [r5, 0x10]
	movs r4, 0xB
	muls r1, r4
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
	ldrh r1, [r5, 0x10]
	movs r0, 0x2
	bl sub_80EF9E8
	b _080F233E
	.pool
_080F2324:
	ldr r0, =gStringVar1
	ldrh r1, [r5, 0x10]
	movs r4, 0xB
	muls r1, r4
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x3]
	bl TVShowConvertInternationalString
_080F233E:
	ldr r0, =sTVShowState
	strb r4, [r0]
	b _080F2358
	.pool
_080F2354:
	bl TVShowDone
_080F2358:
	ldr r0, =gUnknown_0858D1A0
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonTodaySuccessfulCapture

	thumb_func_start DoTVShowPokemonTodayFailedCapture
DoTVShowPokemonTodayFailedCapture: @ 80F2370
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x6
	bls _080F2396
	b _080F24C0
_080F2396:
	lsls r0, r5, 2
	ldr r1, =_080F23B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F23B8:
	.4byte _080F23D4
	.4byte _080F2408
	.4byte _080F245C
	.4byte _080F245C
	.4byte _080F24A0
	.4byte _080F24A0
	.4byte _080F24BC
_080F23D4:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x2]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0xC]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F24C0
	.pool
_080F2408:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x2]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r4, 0x12]
	movs r2, 0
	bl GetMapName
	ldr r0, =gStringVar3
	ldrh r2, [r4, 0xE]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r0, [r4, 0x11]
	cmp r0, 0x1
	bne _080F2450
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F24C0
	.pool
_080F2450:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F24C0
	.pool
_080F245C:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x2]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x10]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _080F2494
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F24C0
	.pool
_080F2494:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F24C0
	.pool
_080F24A0:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x2]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F24C0
	.pool
_080F24BC:
	bl TVShowDone
_080F24C0:
	ldr r0, =gUnknown_0858D394
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonTodayFailedCapture

	thumb_func_start DoTVShowPokemonFanClubLetter
DoTVShowPokemonFanClubLetter: @ 80F24D8
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r6, r0, 0
	cmp r7, 0x33
	bls _080F2500
	b _080F26F0
_080F2500:
	lsls r0, r7, 2
	ldr r1, =_080F2524
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2524:
	.4byte _080F25F4
	.4byte _080F2628
	.4byte _080F2654
	.4byte _080F265A
	.4byte _080F2672
	.4byte _080F2672
	.4byte _080F2672
	.4byte _080F2684
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26F0
	.4byte _080F26A6
	.4byte _080F26CC
_080F25F4:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x10
	ldrb r2, [r5, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x32
	strb r0, [r1]
	b _080F26F0
	.pool
_080F2628:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r2, r0, 0x1
	cmp r2, 0x1
	bne _080F2648
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F26F0
	.pool
_080F2648:
	ldr r1, =sTVShowState
	adds r0, r2, 0x2
	strb r0, [r1]
	b _080F26F0
	.pool
_080F2654:
	movs r0, 0x33
	strb r0, [r6]
	b _080F26F0
_080F265A:
	bl Random
	ldrb r4, [r6]
	adds r4, 0x1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r0, r4
	strb r0, [r6]
	b _080F26F0
_080F2672:
	adds r0, r5, 0
	bl sub_80EFB58
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F26F0
	.pool
_080F2684:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1F
	bl __umodsi3
	adds r0, 0x46
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0x2
	adds r1, r2, 0
	bl TV_ConvertNumberToOrdinal
	bl TVShowDone
	b _080F26F0
_080F26A6:
	ldr r4, =gStringVar4
	adds r1, r5, 0x4
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertEasyChatWordsToString
	adds r0, r4, 0
	bl ShowFieldMessage
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F26FC
	.pool
_080F26CC:
	ldr r4, =gStringVar4
	adds r1, r5, 0x4
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertEasyChatWordsToString
	adds r0, r4, 0
	bl ShowFieldMessage
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F26FC
	.pool
_080F26F0:
	ldr r0, =gUnknown_0858D150
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
_080F26FC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonFanClubLetter

	thumb_func_start DoTVShowRecentHappenings
DoTVShowRecentHappenings: @ 80F2708
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	adds r7, r0, 0
	cmp r6, 0x32
	bls _080F2730
	b _080F288C
_080F2730:
	lsls r0, r6, 2
	ldr r1, =_080F2754
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2754:
	.4byte _080F2820
	.4byte _080F2844
	.4byte _080F285C
	.4byte _080F285C
	.4byte _080F285C
	.4byte _080F2862
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F288C
	.4byte _080F2868
_080F2820:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x10
	ldrb r2, [r5, 0x18]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80EFB58
	ldr r1, =sTVShowState
	movs r0, 0x32
	strb r0, [r1]
	b _080F288C
	.pool
_080F2844:
	bl Random
	ldrb r4, [r7]
	adds r4, 0x1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r0, r4
	strb r0, [r7]
	b _080F288C
_080F285C:
	movs r0, 0x5
	strb r0, [r7]
	b _080F288C
_080F2862:
	bl TVShowDone
	b _080F288C
_080F2868:
	ldr r4, =gStringVar4
	adds r1, r5, 0x4
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertEasyChatWordsToString
	adds r0, r4, 0
	bl ShowFieldMessage
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F2898
	.pool
_080F288C:
	ldr r0, =gUnknown_0858D170
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
_080F2898:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowRecentHappenings

	thumb_func_start DoTVShowPokemonFanClubOpinions
DoTVShowPokemonFanClubOpinions: @ 80F28A4
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r6, =sTVShowState
	ldrb r5, [r6]
	cmp r5, 0x3
	bgt _080F28E8
	cmp r5, 0x1
	bge _080F2930
	cmp r5, 0
	beq _080F28EE
	b _080F297E
	.pool
_080F28E8:
	cmp r5, 0x4
	beq _080F2968
	b _080F297E
_080F28EE:
	ldr r0, =gStringVar1
	adds r1, r4, 0x5
	ldrb r2, [r4, 0xD]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0x10
	ldrb r2, [r4, 0xE]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x4]
	lsrs r0, 4
	adds r0, 0x1
	strb r0, [r6]
	b _080F297E
	.pool
_080F2930:
	ldr r0, =gStringVar1
	adds r1, r4, 0x5
	ldrb r2, [r4, 0xD]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x1C]
	bl CopyEasyChatWord
	movs r0, 0x4
	strb r0, [r6]
	b _080F297E
	.pool
_080F2968:
	ldr r0, =gStringVar1
	adds r1, r4, 0x5
	ldrb r2, [r4, 0xD]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x1E]
	bl CopyEasyChatWord
	bl TVShowDone
_080F297E:
	ldr r0, =gUnknown_0858D188
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonFanClubOpinions

	thumb_func_start DoTVShowDummiedOut
DoTVShowDummiedOut: @ 80F299C
	bx lr
	thumb_func_end DoTVShowDummiedOut

	thumb_func_start DoTVShowPokemonNewsMassOutbreak
DoTVShowPokemonNewsMassOutbreak: @ 80F29A0
	push {r4,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r4, [r2]
	adds r4, r0
	ldr r0, =gStringVar1
	ldrb r1, [r4, 0x10]
	movs r2, 0
	bl GetMapName
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0xC]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	bl TVShowDone
	bl StartMassOutbreak
	ldr r1, =gUnknown_0858D19C
	ldr r0, =sTVShowState
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonNewsMassOutbreak

	thumb_func_start DoTVShowPokemonContestLiveUpdates
DoTVShowPokemonContestLiveUpdates: @ 80F2A10
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r2, r0, 0
	cmp r7, 0x20
	bls _080F2A38
	b _080F311C
_080F2A38:
	lsls r0, r7, 2
	ldr r1, =_080F2A5C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2A5C:
	.4byte _080F2AE0
	.4byte _080F2B54
	.4byte _080F2BA2
	.4byte _080F2BC8
	.4byte _080F2BF4
	.4byte _080F2D2C
	.4byte _080F2D40
	.4byte _080F2D54
	.4byte _080F2D68
	.4byte _080F2DE8
	.4byte _080F2DFC
	.4byte _080F2E10
	.4byte _080F2E24
	.4byte _080F2E38
	.4byte _080F2E4C
	.4byte _080F2ECC
	.4byte _080F2EE0
	.4byte _080F2EF4
	.4byte _080F2F08
	.4byte _080F2F1C
	.4byte _080F2F30
	.4byte _080F2F44
	.4byte _080F2F58
	.4byte _080F2F94
	.4byte _080F3064
	.4byte _080F3080
	.4byte _080F30E0
	.4byte _080F30E0
	.4byte _080F30A8
	.4byte _080F30AE
	.4byte _080F30E0
	.4byte _080F30E0
	.4byte _080F30FC
_080F2AE0:
	ldr r0, =gStringVar1
	ldrb r1, [r6, 0x1C]
	bl sub_818E868
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r6, 0
	adds r1, 0x14
	ldrb r2, [r6, 0x1D]
	bl TVShowConvertInternationalString
	ldrb r0, [r6, 0xD]
	ldrb r1, [r6, 0xE]
	cmp r0, r1
	bne _080F2B38
	cmp r0, 0
	bne _080F2B2C
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F311C
	.pool
_080F2B2C:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F311C
	.pool
_080F2B38:
	cmp r0, r1
	bls _080F2B48
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F311C
	.pool
_080F2B48:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F311C
	.pool
_080F2B54:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r6, 0xF]
	cmp r1, 0x8
	bne _080F2B6C
	b _080F2CF0
_080F2B6C:
	cmp r1, 0x8
	bgt _080F2B88
_080F2B70:
	cmp r1, 0x2
	bne _080F2B76
	b _080F2CD8
_080F2B76:
	cmp r1, 0x2
	bgt _080F2B7C
	b _080F2C96
_080F2B7C:
	b _080F2CAC
	.pool
_080F2B88:
	cmp r1, 0x20
	bne _080F2B8E
	b _080F2D08
_080F2B8E:
	cmp r1, 0x20
	bgt _080F2B94
	b _080F2CBA
_080F2B94:
	cmp r1, 0x40
	bne _080F2B9A
	b _080F2D14
_080F2B9A:
	cmp r1, 0x80
	beq _080F2BA0
	b _080F311C
_080F2BA0:
	b _080F2D20
_080F2BA2:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
_080F2BB2:
	ldrb r1, [r6, 0xF]
	cmp r1, 0x8
	bne _080F2BBA
	b _080F2CF0
_080F2BBA:
	cmp r1, 0x8
	ble _080F2B70
	b _080F2B88
	.pool
_080F2BC8:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r6, 0
	adds r1, 0x14
	ldrb r2, [r6, 0x1D]
	bl TVShowConvertInternationalString
	b _080F2BB2
	.pool
_080F2BF4:
	ldrb r0, [r6, 0x1C]
	cmp r0, 0x4
	bhi _080F2C74
	lsls r0, 2
	ldr r1, =_080F2C08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2C08:
	.4byte _080F2C1C
	.4byte _080F2C30
	.4byte _080F2C44
	.4byte _080F2C58
	.4byte _080F2C6C
_080F2C1C:
	ldr r0, =gStringVar1
	ldr r1, =gText_Cool
	bl StringCopy
	b _080F2C74
	.pool
_080F2C30:
	ldr r0, =gStringVar1
	ldr r1, =gText_Beauty
	bl StringCopy
	b _080F2C74
	.pool
_080F2C44:
	ldr r0, =gStringVar1
	ldr r1, =gText_Cute
	bl StringCopy
	b _080F2C74
	.pool
_080F2C58:
	ldr r0, =gStringVar1
	ldr r1, =gText_Smart
	bl StringCopy
	b _080F2C74
	.pool
_080F2C6C:
	ldr r0, =gStringVar1
	ldr r1, =gText_Tough
	bl StringCopy
_080F2C74:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r6, 0xF]
	cmp r1, 0x8
	beq _080F2CF0
	cmp r1, 0x8
	bgt _080F2CB2
	cmp r1, 0x2
	beq _080F2CD8
	cmp r1, 0x2
	bgt _080F2CAC
_080F2C96:
	cmp r1, 0x1
	beq _080F2CCA
	b _080F311C
	.pool
_080F2CAC:
	cmp r1, 0x4
	beq _080F2CE4
	b _080F311C
_080F2CB2:
	cmp r1, 0x20
	beq _080F2D08
	cmp r1, 0x20
	bgt _080F2CC0
_080F2CBA:
	cmp r1, 0x10
	beq _080F2CFC
	b _080F311C
_080F2CC0:
	cmp r1, 0x40
	beq _080F2D14
	cmp r1, 0x80
	beq _080F2D20
	b _080F311C
_080F2CCA:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F311C
	.pool
_080F2CD8:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F311C
	.pool
_080F2CE4:
	ldr r1, =sTVShowState
	movs r0, 0xE
	strb r0, [r1]
	b _080F311C
	.pool
_080F2CF0:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F311C
	.pool
_080F2CFC:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F311C
	.pool
_080F2D08:
	ldr r1, =sTVShowState
	movs r0, 0x14
	strb r0, [r1]
	b _080F311C
	.pool
_080F2D14:
	ldr r1, =sTVShowState
	movs r0, 0x15
	strb r0, [r1]
	b _080F311C
	.pool
_080F2D20:
	ldr r1, =sTVShowState
	movs r0, 0x16
	strb r0, [r1]
	b _080F311C
	.pool
_080F2D2C:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2D40:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2D54:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2D68:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r0, [r6, 0x1C]
	cmp r0, 0x4
	bls _080F2D80
	b _080F311C
_080F2D80:
	lsls r0, 2
	ldr r1, =_080F2D98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2D98:
	.4byte _080F2DAC
	.4byte _080F2DB8
	.4byte _080F2DC4
	.4byte _080F2DD0
	.4byte _080F2DDC
_080F2DAC:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F311C
	.pool
_080F2DB8:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F311C
	.pool
_080F2DC4:
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F311C
	.pool
_080F2DD0:
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F311C
	.pool
_080F2DDC:
	ldr r1, =sTVShowState
	movs r0, 0xD
	strb r0, [r1]
	b _080F311C
	.pool
_080F2DE8:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2DFC:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2E10:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2E24:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2E38:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2E4C:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r0, [r6, 0x1C]
	cmp r0, 0x4
	bls _080F2E64
	b _080F311C
_080F2E64:
	lsls r0, 2
	ldr r1, =_080F2E7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F2E7C:
	.4byte _080F2E90
	.4byte _080F2E9C
	.4byte _080F2EA8
	.4byte _080F2EB4
	.4byte _080F2EC0
_080F2E90:
	ldr r1, =sTVShowState
	movs r0, 0xF
	strb r0, [r1]
	b _080F311C
	.pool
_080F2E9C:
	ldr r1, =sTVShowState
	movs r0, 0x10
	strb r0, [r1]
	b _080F311C
	.pool
_080F2EA8:
	ldr r1, =sTVShowState
	movs r0, 0x11
	strb r0, [r1]
	b _080F311C
	.pool
_080F2EB4:
	ldr r1, =sTVShowState
	movs r0, 0x12
	strb r0, [r1]
	b _080F311C
	.pool
_080F2EC0:
	ldr r1, =sTVShowState
	movs r0, 0x13
	strb r0, [r1]
	b _080F311C
	.pool
_080F2ECC:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2EE0:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2EF4:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2F08:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2F1C:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2F30:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2F44:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	b _080F2F72
	.pool
_080F2F58:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r2, [r6, 0x10]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
_080F2F72:
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x17
	strb r0, [r1]
	b _080F311C
	.pool
_080F2F94:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x12]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r6, 0x4
	ldrb r2, [r6, 0x1E]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x2]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldrb r0, [r6, 0xC]
	cmp r0, 0x8
	beq _080F3028
	cmp r0, 0x8
	bgt _080F2FEA
	cmp r0, 0x2
	beq _080F3010
	cmp r0, 0x2
	bgt _080F2FE4
	cmp r0, 0x1
	beq _080F3002
	b _080F311C
	.pool
_080F2FE4:
	cmp r0, 0x4
	beq _080F301C
	b _080F311C
_080F2FEA:
	cmp r0, 0x20
	beq _080F3040
	cmp r0, 0x20
	bgt _080F2FF8
	cmp r0, 0x10
	beq _080F3034
	b _080F311C
_080F2FF8:
	cmp r0, 0x40
	beq _080F304C
	cmp r0, 0x80
	beq _080F3058
	b _080F311C
_080F3002:
	ldr r1, =sTVShowState
	movs r0, 0x1F
	strb r0, [r1]
	b _080F311C
	.pool
_080F3010:
	ldr r1, =sTVShowState
	movs r0, 0x1E
	strb r0, [r1]
	b _080F311C
	.pool
_080F301C:
	ldr r1, =sTVShowState
	movs r0, 0x1D
	strb r0, [r1]
	b _080F311C
	.pool
_080F3028:
	ldr r1, =sTVShowState
	movs r0, 0x1C
	strb r0, [r1]
	b _080F311C
	.pool
_080F3034:
	ldr r1, =sTVShowState
	movs r0, 0x1B
	strb r0, [r1]
	b _080F311C
	.pool
_080F3040:
	ldr r1, =sTVShowState
	movs r0, 0x1A
	strb r0, [r1]
	b _080F311C
	.pool
_080F304C:
	ldr r1, =sTVShowState
	movs r0, 0x19
	strb r0, [r1]
	b _080F311C
	.pool
_080F3058:
	ldr r1, =sTVShowState
	movs r0, 0x18
	strb r0, [r1]
	b _080F311C
	.pool
_080F3064:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	b _080F30EA
	.pool
_080F3080:
	ldr r0, =gStringVar1
	adds r1, r6, 0x4
	ldrb r2, [r6, 0x1E]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	b _080F30EA
	.pool
_080F30A8:
	movs r0, 0x20
	strb r0, [r2]
	b _080F311C
_080F30AE:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x14
	ldrb r2, [r6, 0x1D]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	b _080F30E2
	.pool
_080F30E0:
	ldr r0, =gStringVar1
_080F30E2:
	adds r1, r6, 0x4
	ldrb r2, [r6, 0x1E]
	bl TVShowConvertInternationalString
_080F30EA:
	ldr r1, =sTVShowState
	movs r0, 0x20
	strb r0, [r1]
	b _080F311C
	.pool
_080F30FC:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x14
	ldrb r2, [r6, 0x1D]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x12]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	bl TVShowDone
_080F311C:
	ldr r0, =gUnknown_0858D27C
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonContestLiveUpdates

	thumb_func_start DoTVShowPokemonBattleUpdate
DoTVShowPokemonBattleUpdate: @ 80F3140
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0x7
	bls _080F3168
	b _080F3362
_080F3168:
	lsls r0, r5, 2
	ldr r1, =_080F318C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F318C:
	.4byte _080F31AC
	.4byte _080F31CA
	.4byte _080F321C
	.4byte _080F3268
	.4byte _080F329C
	.4byte _080F32C0
	.4byte _080F32EC
	.4byte _080F3338
_080F31AC:
	ldrb r1, [r4, 0x18]
	cmp r1, 0
	bge _080F31B4
	b _080F3362
_080F31B4:
	cmp r1, 0x1
	ble _080F31BE
	cmp r1, 0x2
	beq _080F31C4
	b _080F3362
_080F31BE:
	movs r0, 0x1
	strb r0, [r2]
	b _080F3362
_080F31C4:
	movs r0, 0x5
	strb r0, [r2]
	b _080F3362
_080F31CA:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x19]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x1A]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x18]
	cmp r0, 0
	bne _080F3200
	ldr r0, =gStringVar3
	ldr r1, =gText_Single
	bl StringCopy
	b _080F3208
	.pool
_080F3200:
	ldr r0, =gStringVar3
	ldr r1, =gText_Double
	bl StringCopy
_080F3208:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F3362
	.pool
_080F321C:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x19]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x16]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r2, [r4, 0x14]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F3362
	.pool
_080F3268:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x1A]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F3362
	.pool
_080F329C:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x19]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x1A]
	bl TVShowConvertInternationalString
	bl TVShowDone
	b _080F3362
	.pool
_080F32C0:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x19]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x1A]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F3362
	.pool
_080F32EC:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x19]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x16]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r2, [r4, 0x14]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F3362
	.pool
_080F3338:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x19]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x1A]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r2, [r4, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	bl TVShowDone
_080F3362:
	ldr r0, =gUnknown_0858D300
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonBattleUpdate

	thumb_func_start DoTVShow3CheersForPokeblocks
DoTVShow3CheersForPokeblocks: @ 80F3388
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x5
	bls _080F33AE
	b _080F3624
_080F33AE:
	lsls r0, r5, 2
	ldr r1, =_080F33D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F33D0:
	.4byte _080F33E8
	.4byte _080F3418
	.4byte _080F3500
	.4byte _080F350C
	.4byte _080F35F4
	.4byte _080F3620
_080F33E8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x14]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x2]
	cmp r0, 0x14
	bls _080F340C
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3624
	.pool
_080F340C:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F3624
	.pool
_080F3418:
	ldrb r0, [r4, 0x3]
	lsls r0, 29
	lsrs r0, 29
	cmp r0, 0x4
	bhi _080F349C
	lsls r0, 2
	ldr r1, =_080F3430
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3430:
	.4byte _080F3444
	.4byte _080F3458
	.4byte _080F346C
	.4byte _080F3480
	.4byte _080F3494
_080F3444:
	ldr r0, =gStringVar1
	ldr r1, =gText_Spicy2
	bl StringCopy
	b _080F349C
	.pool
_080F3458:
	ldr r0, =gStringVar1
	ldr r1, =gText_Dry2
	bl StringCopy
	b _080F349C
	.pool
_080F346C:
	ldr r0, =gStringVar1
	ldr r1, =gText_Sweet2
	bl StringCopy
	b _080F349C
	.pool
_080F3480:
	ldr r0, =gStringVar1
	ldr r1, =gText_Bitter2
	bl StringCopy
	b _080F349C
	.pool
_080F3494:
	ldr r0, =gStringVar1
	ldr r1, =gText_Sour2
	bl StringCopy
_080F349C:
	ldrb r0, [r4, 0x2]
	cmp r0, 0x18
	bls _080F34BC
	ldr r0, =gStringVar2
	ldr r1, =gText_Excellent
	bl StringCopy
	b _080F34DC
	.pool
_080F34BC:
	cmp r0, 0x16
	bls _080F34D4
	ldr r0, =gStringVar2
	ldr r1, =gText_VeryGood
	bl StringCopy
	b _080F34DC
	.pool
_080F34D4:
	ldr r0, =gStringVar2
	ldr r1, =gText_Good
	bl StringCopy
_080F34DC:
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x14]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F3624
	.pool
_080F3500:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x15]
	b _080F3606
	.pool
_080F350C:
	ldrb r0, [r4, 0x3]
	lsls r0, 29
	lsrs r0, 29
	cmp r0, 0x4
	bhi _080F3590
	lsls r0, 2
	ldr r1, =_080F3524
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3524:
	.4byte _080F3538
	.4byte _080F354C
	.4byte _080F3560
	.4byte _080F3574
	.4byte _080F3588
_080F3538:
	ldr r0, =gStringVar1
	ldr r1, =gText_Spicy2
	bl StringCopy
	b _080F3590
	.pool
_080F354C:
	ldr r0, =gStringVar1
	ldr r1, =gText_Dry2
	bl StringCopy
	b _080F3590
	.pool
_080F3560:
	ldr r0, =gStringVar1
	ldr r1, =gText_Sweet2
	bl StringCopy
	b _080F3590
	.pool
_080F3574:
	ldr r0, =gStringVar1
	ldr r1, =gText_Bitter2
	bl StringCopy
	b _080F3590
	.pool
_080F3588:
	ldr r0, =gStringVar1
	ldr r1, =gText_Sour2
	bl StringCopy
_080F3590:
	ldrb r0, [r4, 0x2]
	cmp r0, 0x10
	bls _080F35B0
	ldr r0, =gStringVar2
	ldr r1, =gText_SoSo
	bl StringCopy
	b _080F35D0
	.pool
_080F35B0:
	cmp r0, 0xD
	bls _080F35C8
	ldr r0, =gStringVar2
	ldr r1, =gText_Bad
	bl StringCopy
	b _080F35D0
	.pool
_080F35C8:
	ldr r0, =gStringVar2
	ldr r1, =gText_TheWorst
	bl StringCopy
_080F35D0:
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x14]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F3624
	.pool
_080F35F4:
	ldr r0, =gStringVar1
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x15]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x14]
_080F3606:
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F3624
	.pool
_080F3620:
	bl TVShowDone
_080F3624:
	ldr r0, =gUnknown_0858D228
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShow3CheersForPokeblocks

	thumb_func_start DoTVShowInSearchOfTrainers
DoTVShowInSearchOfTrainers: @ 80F363C
	push {r4-r7,lr}
	ldr r0, =gScriptResult
	movs r1, 0
	strh r1, [r0]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r2, r0, 0
	cmp r7, 0x8
	bls _080F3650
	b _080F37EA
_080F3650:
	lsls r0, r7, 2
	ldr r1, =_080F3668
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3668:
	.4byte _080F368C
	.4byte _080F36D4
	.4byte _080F36DA
	.4byte _080F372C
	.4byte _080F379C
	.4byte _080F379C
	.4byte _080F379C
	.4byte _080F379C
	.4byte _080F37A2
_080F368C:
	ldr r0, =gStringVar1
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	ldr r2, =0x00002bac
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl GetMapName
	ldr r0, [r4]
	ldr r1, =0x00002bad
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _080F36C8
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F37EA
	.pool
_080F36C8:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F37EA
	.pool
_080F36D4:
	movs r0, 0x2
	strb r0, [r2]
	b _080F37EA
_080F36DA:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002bae
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080F36FC
	movs r0, 0x4
	strb r0, [r2]
	b _080F37EA
	.pool
_080F36FC:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080F370A
	movs r0, 0x5
	strb r0, [r2]
	b _080F37EA
_080F370A:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080F3718
	movs r0, 0x6
	strb r0, [r2]
	b _080F37EA
_080F3718:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080F3726
	movs r0, 0x7
	strb r0, [r2]
	b _080F37EA
_080F3726:
	movs r0, 0x3
	strb r0, [r2]
	b _080F37EA
_080F372C:
	ldr r0, =gStringVar1
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	ldr r2, =0x00002ba4
	adds r1, r2
	ldrh r1, [r1]
	movs r6, 0xB
	muls r1, r6
	ldr r5, =gSpeciesNames
	adds r1, r5
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r1, [r4]
	ldr r2, =0x00002ba8
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldr r1, [r4]
	ldr r2, =0x00002ba6
	adds r1, r2
	ldrh r1, [r1]
	muls r1, r6
	adds r1, r5
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F37EA
	.pool
_080F379C:
	movs r0, 0x8
	strb r0, [r2]
	b _080F37EA
_080F37A2:
	ldr r0, =gStringVar1
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	ldr r2, =0x00002baa
	adds r1, r2
	ldrh r1, [r1]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldr r1, [r4]
	ldr r2, =0x00002ba4
	adds r1, r2
	ldrh r1, [r1]
	movs r6, 0xB
	muls r1, r6
	ldr r5, =gSpeciesNames
	adds r1, r5
	bl StringCopy
	ldr r0, =gStringVar3
	ldr r1, [r4]
	ldr r2, =0x00002ba6
	adds r1, r2
	ldrh r1, [r1]
	muls r1, r6
	adds r1, r5
	bl StringCopy
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, =sTVShowState
	movs r0, 0
	strb r0, [r1]
	bl TakeTVShowInSearchOfTrainersOffTheAir
_080F37EA:
	ldr r0, =gUnknown_0858D66C
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowInSearchOfTrainers

	thumb_func_start DoTVShowPokemonAngler
DoTVShowPokemonAngler: @ 80F3828
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r0, =gScriptResult
	movs r1, 0
	strh r1, [r0]
	ldrb r0, [r4, 0x2]
	ldrb r2, [r4, 0x3]
	cmp r0, r2
	bcs _080F3868
	ldr r0, =sTVShowState
	strb r1, [r0]
	b _080F3870
	.pool
_080F3868:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r1, 0
_080F3870:
	ldrb r5, [r0]
	cmp r5, 0
	beq _080F3880
	cmp r5, 0x1
	beq _080F38B8
	b _080F38E0
	.pool
_080F3880:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x6]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r4, 0x3]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	bl TVShowDone
	b _080F38E0
	.pool
_080F38B8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x6]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	bl TVShowDone
_080F38E0:
	ldr r0, =gUnknown_0858D3B0
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonAngler

	thumb_func_start DoTVShowTheWorldOfMasters
DoTVShowTheWorldOfMasters: @ 80F3904
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r6, =sTVShowState
	ldrb r5, [r6]
	cmp r5, 0x1
	beq _080F3974
	cmp r5, 0x1
	bgt _080F3948
	cmp r5, 0
	beq _080F394E
	b _080F39BE
	.pool
_080F3948:
	cmp r5, 0x2
	beq _080F3994
	b _080F39BE
_080F394E:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xB]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x6]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldrh r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	movs r0, 0x1
	strb r0, [r6]
	b _080F39BE
	.pool
_080F3974:
	ldr r0, =gStringVar1
	ldrh r2, [r4, 0x8]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	movs r0, 0x2
	strb r0, [r6]
	b _080F39BE
	.pool
_080F3994:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xB]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r4, 0xA]
	movs r2, 0
	bl GetMapName
	ldr r0, =gStringVar3
	ldrh r2, [r4, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	bl TVShowDone
_080F39BE:
	ldr r0, =gUnknown_0858D3B8
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTheWorldOfMasters

	thumb_func_start DoTVShowTodaysRivalTrainer
DoTVShowTodaysRivalTrainer: @ 80F39E4
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0xA
	bls _080F3A0C
	b _080F3BE8
_080F3A0C:
	lsls r0, r5, 2
	ldr r1, =_080F3A30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3A30:
	.4byte _080F3A5C
	.4byte _080F3B30
	.4byte _080F3B58
	.4byte _080F3B90
	.4byte _080F3BA2
	.4byte _080F3BC4
	.4byte _080F3BD8
	.4byte _080F3A92
	.4byte _080F3AC0
	.4byte _080F3ADC
	.4byte _080F3AF8
_080F3A5C:
	ldrb r0, [r4, 0x7]
	cmp r0, 0x56
	beq _080F3A6C
	cmp r0, 0x57
	beq _080F3A72
	movs r0, 0x7
	strb r0, [r2]
	b _080F3BE8
_080F3A6C:
	movs r0, 0x8
	strb r0, [r2]
	b _080F3BE8
_080F3A72:
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00000117
	cmp r1, r0
	bgt _080F3A8C
	subs r0, 0x2
	cmp r1, r0
	blt _080F3A8C
	movs r0, 0xA
	strb r0, [r2]
	b _080F3BE8
	.pool
_080F3A8C:
	movs r0, 0x9
	strb r0, [r2]
	b _080F3BE8
_080F3A92:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r0, =gStringVar3
	ldrb r1, [r4, 0x7]
	movs r2, 0
	bl GetMapName
_080F3AB0:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _080F3B12
	b _080F3B24
	.pool
_080F3AC0:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	b _080F3AB0
	.pool
_080F3ADC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	b _080F3AB0
	.pool
_080F3AF8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _080F3B24
_080F3B12:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B24:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B30:
	ldrb r1, [r4, 0x4]
	movs r0, 0
	bl TV_ConvertNumberToOrdinal
	ldr r0, =0x000008a8
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080F3BCC
	ldr r0, [r4, 0x4]
	ldr r1, =0x00ffff00
	ands r0, r1
	cmp r0, 0
	bne _080F3B6E
	b _080F3B84
	.pool
_080F3B58:
	ldr r0, =0x000008a8
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080F3BCC
	ldr r0, [r4, 0x4]
	ldr r1, =0x00ffff00
	ands r0, r1
	cmp r0, 0
	beq _080F3B84
_080F3B6E:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B84:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B90:
	ldrh r0, [r4, 0x8]
	cmp r0, 0
	bne _080F3B9C
	movs r0, 0x6
	strb r0, [r2]
	b _080F3BE8
_080F3B9C:
	movs r0, 0x5
	strb r0, [r2]
	b _080F3BE8
_080F3BA2:
	ldrb r1, [r4, 0x6]
	movs r0, 0
	bl TV_ConvertNumberToOrdinal
	ldrb r1, [r4, 0x5]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldrh r0, [r4, 0x8]
	cmp r0, 0
	beq _080F3BCC
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3BC4:
	ldrh r1, [r4, 0x8]
	movs r0, 0
	bl TV_ConvertNumberToOrdinal
_080F3BCC:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3BD8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F3BE8:
	ldr r0, =gUnknown_0858D3C4
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTodaysRivalTrainer

	thumb_func_start DoTVShowDewfordTrendWatcherNetwork
DoTVShowDewfordTrendWatcherNetwork: @ 80F3C04
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x6
	bls _080F3C2A
	b _080F3D54
_080F3C2A:
	lsls r0, r5, 2
	ldr r1, =_080F3C4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3C4C:
	.4byte _080F3C68
	.4byte _080F3CA0
	.4byte _080F3CA0
	.4byte _080F3CD4
	.4byte _080F3D0C
	.4byte _080F3D0C
	.4byte _080F3D40
_080F3C68:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _080F3C94
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3C94:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3CA0:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x9]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3CD4:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _080F3D00
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3D00:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3D0C:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x9]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3D40:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	bl TVShowDone
_080F3D54:
	ldr r0, =gUnknown_0858D3F0
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowDewfordTrendWatcherNetwork

	thumb_func_start DoTVShowHoennTreasureInvestigators
DoTVShowHoennTreasureInvestigators: @ 80F3D74
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r7, =sTVShowState
	ldrb r6, [r7]
	cmp r6, 0x1
	beq _080F3E02
	cmp r6, 0x1
	bgt _080F3DB8
	cmp r6, 0
	beq _080F3DBE
	b _080F3E5C
	.pool
_080F3DB8:
	cmp r6, 0x2
	beq _080F3E3C
	b _080F3E5C
_080F3DBE:
	ldr r4, =gStringVar1
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrb r0, [r5, 0x4]
	cmp r0, 0x57
	bne _080F3DFC
	ldrh r1, [r5, 0x6]
	ldr r0, =0x00000117
	cmp r1, r0
	bgt _080F3DF0
	subs r0, 0x2
	cmp r1, r0
	blt _080F3DF0
	movs r0, 0x2
	strb r0, [r7]
	b _080F3E5C
	.pool
_080F3DF0:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3E5C
	.pool
_080F3DFC:
	movs r0, 0x1
	strb r0, [r7]
	b _080F3E5C
_080F3E02:
	ldr r4, =gStringVar1
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x5]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrb r1, [r5, 0x4]
	movs r2, 0
	bl GetMapName
	bl TVShowDone
	b _080F3E5C
	.pool
_080F3E3C:
	ldr r4, =gStringVar1
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x5]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F3E5C:
	ldr r0, =gUnknown_0858D40C
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowHoennTreasureInvestigators

	thumb_func_start DoTVShowFindThatGamer
DoTVShowFindThatGamer: @ 80F3E7C
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x1
	beq _080F3F28
	cmp r5, 0x1
	bgt _080F3EC0
	cmp r5, 0
	beq _080F3ECC
	b _080F4008
	.pool
_080F3EC0:
	cmp r5, 0x2
	beq _080F3F78
	cmp r5, 0x3
	bne _080F3ECA
	b _080F3FCC
_080F3ECA:
	b _080F4008
_080F3ECC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F3EE8
	cmp r0, 0x1
	beq _080F3EFC
	b _080F3F04
	.pool
_080F3EE8:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
	b _080F3F04
	.pool
_080F3EFC:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
_080F3F04:
	ldrb r1, [r4, 0x2]
	cmp r1, 0x1
	bne _080F3F1C
	ldr r0, =sTVShowState
	strb r1, [r0]
	b _080F4008
	.pool
_080F3F1C:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4008
	.pool
_080F3F28:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F3F44
	cmp r0, 0x1
	beq _080F3F58
	b _080F3F60
	.pool
_080F3F44:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
	b _080F3F60
	.pool
_080F3F58:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
_080F3F60:
	ldrh r1, [r4, 0x4]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	bl TVShowDone
	b _080F4008
	.pool
_080F3F78:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F3F94
	cmp r0, 0x1
	beq _080F3FA8
	b _080F3FB0
	.pool
_080F3F94:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
	b _080F3FB0
	.pool
_080F3FA8:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
_080F3FB0:
	ldrh r1, [r4, 0x4]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4008
	.pool
_080F3FCC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x3]
	cmp r1, 0
	beq _080F3FE8
	cmp r1, 0x1
	beq _080F3FFC
	b _080F4004
	.pool
_080F3FE8:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
	b _080F4004
	.pool
_080F3FFC:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
_080F4004:
	bl TVShowDone
_080F4008:
	ldr r0, =gUnknown_0858D418
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowFindThatGamer

	thumb_func_start DoTVShowBreakingNewsTV
DoTVShowBreakingNewsTV: @ 80F4028
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r2, r0, 0
	cmp r7, 0xC
	bls _080F4050
	b _080F4344
_080F4050:
	lsls r0, r7, 2
	ldr r1, =_080F4074
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4074:
	.4byte _080F40A8
	.4byte _080F40BA
	.4byte _080F40FC
	.4byte _080F4140
	.4byte _080F4168
	.4byte _080F418C
	.4byte _080F41D0
	.4byte _080F4254
	.4byte _080F42C8
	.4byte _080F42F4
	.4byte _080F42F4
	.4byte _080F4334
	.4byte _080F4284
_080F40A8:
	ldrb r0, [r6, 0x5]
	cmp r0, 0
	bne _080F40B4
	movs r0, 0x1
	strb r0, [r2]
	b _080F4344
_080F40B4:
	movs r0, 0x5
	strb r0, [r2]
	b _080F4344
_080F40BA:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4344
	.pool
_080F40FC:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4344
	.pool
_080F4140:
	ldrh r1, [r6, 0x8]
	movs r0, 0
	bl TV_ConvertNumberToOrdinal
	ldr r4, =gStringVar2
	ldrh r0, [r6, 0x6]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4344
	.pool
_080F4168:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	bl TVShowDone
	b _080F4344
	.pool
_080F418C:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4344
	.pool
_080F41D0:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldrb r0, [r6, 0x5]
	cmp r0, 0x2
	beq _080F423C
	cmp r0, 0x2
	bgt _080F4218
	cmp r0, 0x1
	beq _080F421E
	b _080F4344
	.pool
_080F4218:
	cmp r0, 0x3
	beq _080F4248
	b _080F4344
_080F421E:
	ldrh r0, [r6, 0xC]
	cmp r0, 0
	bne _080F4230
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F4344
	.pool
_080F4230:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4344
	.pool
_080F423C:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4344
	.pool
_080F4248:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4344
	.pool
_080F4254:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0xC]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0xA]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	b _080F42A8
	.pool
_080F4284:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
_080F42A8:
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4344
	.pool
_080F42C8:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F4344
	.pool
_080F42F4:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r4, 0xB
	muls r1, r4
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r0, =sTVShowState
	strb r4, [r0]
	b _080F4344
	.pool
_080F4334:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F4344:
	ldr r0, =gUnknown_0858D428
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowBreakingNewsTV

	thumb_func_start DoTVShowSecretBaseVisit
DoTVShowSecretBaseVisit: @ 80F4360
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	adds r2, r0, 0
	cmp r6, 0xD
	bls _080F4388
	b _080F4588
_080F4388:
	lsls r0, r6, 2
	ldr r1, =_080F43AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F43AC:
	.4byte _080F43E4
	.4byte _080F4414
	.4byte _080F44E4
	.4byte _080F4448
	.4byte _080F44E4
	.4byte _080F449C
	.4byte _080F44C0
	.4byte _080F44E4
	.4byte _080F44EA
	.4byte _080F4538
	.4byte _080F4538
	.4byte _080F4538
	.4byte _080F4538
	.4byte _080F4584
_080F43E4:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0xC]
	bl TVShowConvertInternationalString
	ldrb r0, [r5, 0x3]
	cmp r0, 0
	bne _080F4408
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4588
	.pool
_080F4408:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4588
	.pool
_080F4414:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x4]
	lsls r1, 5
	ldr r2, =gUnknown_085A5C09
	adds r1, r2
	bl StringCopy
	ldrb r0, [r5, 0x3]
	cmp r0, 0x1
	bne _080F443C
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4588
	.pool
_080F443C:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4588
	.pool
_080F4448:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x5]
	lsls r1, 5
	ldr r2, =gUnknown_085A5C09
	adds r1, r2
	bl StringCopy
	ldrb r1, [r5, 0x3]
	cmp r1, 0x3
	beq _080F4484
	cmp r1, 0x3
	bgt _080F4470
	cmp r1, 0x2
	beq _080F4476
	b _080F4588
	.pool
_080F4470:
	cmp r1, 0x4
	beq _080F4490
	b _080F4588
_080F4476:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4588
	.pool
_080F4484:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4588
	.pool
_080F4490:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4588
	.pool
_080F449C:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x6]
	lsls r1, 5
	ldr r4, =gUnknown_085A5C09
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r5, 0x7]
	lsls r1, 5
	adds r1, r4
	b _080F44CA
	.pool
_080F44C0:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x6]
	lsls r1, 5
	ldr r2, =gUnknown_085A5C09
	adds r1, r2
_080F44CA:
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4588
	.pool
_080F44E4:
	movs r0, 0x8
	strb r0, [r2]
	b _080F4588
_080F44EA:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0xC]
	bl TVShowConvertInternationalString
	ldrb r1, [r5, 0x2]
	cmp r1, 0x18
	bhi _080F450C
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F4588
	.pool
_080F450C:
	cmp r1, 0x31
	bhi _080F451C
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F4588
	.pool
_080F451C:
	cmp r1, 0x45
	bhi _080F452C
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4588
	.pool
_080F452C:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4588
	.pool
_080F4538:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0xC]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x8]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r5, 0xA]
	movs r4, 0xD
	muls r1, r4
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =sTVShowState
	strb r4, [r0]
	b _080F4588
	.pool
_080F4584:
	bl TVShowDone
_080F4588:
	ldr r0, =gUnknown_0858D45C
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSecretBaseVisit

	thumb_func_start DoTVShowPokemonLotterWinnerFlashReport
DoTVShowPokemonLotterWinnerFlashReport: @ 80F45A0
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x5]
	bl TVShowConvertInternationalString
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	bne _080F45FC
	ldr r0, =gStringVar2
	ldr r1, =gText_Jackpot
	bl StringCopy
	b _080F4634
	.pool
_080F45FC:
	cmp r0, 0x1
	bne _080F4614
	ldr r0, =gStringVar2
	ldr r1, =gText_First
	bl StringCopy
	b _080F4634
	.pool
_080F4614:
	cmp r0, 0x2
	bne _080F462C
	ldr r0, =gStringVar2
	ldr r1, =gText_Second
	bl StringCopy
	b _080F4634
	.pool
_080F462C:
	ldr r0, =gStringVar2
	ldr r1, =gText_Third
	bl StringCopy
_080F4634:
	ldr r4, =gStringVar3
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	bl TVShowDone
	ldr r1, =gUnknown_0858D494
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonLotterWinnerFlashReport

	thumb_func_start DoTVShowThePokemonBattleSeminar
DoTVShowThePokemonBattleSeminar: @ 80F466C
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	cmp r7, 0x6
	bls _080F4692
	b _080F4858
_080F4692:
	lsls r0, r7, 2
	ldr r1, =_080F46B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F46B4:
	.4byte _080F46D0
	.4byte _080F4714
	.4byte _080F4760
	.4byte _080F47B4
	.4byte _080F47EC
	.4byte _080F4814
	.4byte _080F4838
_080F46D0:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0x11]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x4]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4858
	.pool
_080F4714:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0x11]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r2, [r6, 0x2]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4858
	.pool
_080F4760:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0x6]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r6, 0x10]
	cmp r1, 0x2
	beq _080F479C
	cmp r1, 0x2
	bgt _080F4788
	cmp r1, 0x1
	beq _080F478E
	b _080F4824
	.pool
_080F4788:
	cmp r1, 0x3
	beq _080F47A8
	b _080F4824
_080F478E:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4858
	.pool
_080F479C:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4858
	.pool
_080F47A8:
	ldr r0, =sTVShowState
	strb r1, [r0]
	b _080F4858
	.pool
_080F47B4:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x8]
	movs r5, 0xD
	muls r1, r5
	ldr r4, =gMoveNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xC]
	muls r1, r5
	adds r1, r4
	b _080F4820
	.pool
_080F47EC:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x8]
	movs r5, 0xD
	muls r1, r5
	ldr r4, =gMoveNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	b _080F4820
	.pool
_080F4814:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x8]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
_080F4820:
	bl StringCopy
_080F4824:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4858
	.pool
_080F4838:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0xE]
	movs r5, 0xD
	muls r1, r5
	ldr r4, =gMoveNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	bl TVShowDone
_080F4858:
	ldr r0, =gUnknown_0858D498
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowThePokemonBattleSeminar

	thumb_func_start DoTVShowTrainerFanClubSpecial
DoTVShowTrainerFanClubSpecial: @ 80F487C
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x5
	bls _080F48A2
	b _080F499A
_080F48A2:
	lsls r0, r5, 2
	ldr r1, =_080F48C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F48C4:
	.4byte _080F48DC
	.4byte _080F4944
	.4byte _080F4944
	.4byte _080F4944
	.4byte _080F4944
	.4byte _080F4978
_080F48DC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x14]
	bl CopyEasyChatWord
	ldrb r1, [r4, 0x16]
	cmp r1, 0x59
	bls _080F4918
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F499A
	.pool
_080F4918:
	cmp r1, 0x45
	bls _080F4928
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F499A
	.pool
_080F4928:
	cmp r1, 0x1D
	bls _080F4938
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F499A
	.pool
_080F4938:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F499A
	.pool
_080F4944:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x16]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F499A
	.pool
_080F4978:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x14]
	bl CopyEasyChatWord
	bl TVShowDone
_080F499A:
	ldr r0, =gUnknown_0858D320
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTrainerFanClubSpecial

	thumb_func_start DoTVShowTrainerFanClub
DoTVShowTrainerFanClub: @ 80F49BC
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0xB
	bls _080F49E4
	b _080F4B3A
_080F49E4:
	lsls r0, r5, 2
	ldr r1, =_080F4A08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4A08:
	.4byte _080F4A38
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B1A
_080F4A38:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	adds r0, r4, 0
	adds r0, 0x23
	ldrb r0, [r0]
	lsls r0, 8
	adds r1, r4, 0
	adds r1, 0x22
	ldrb r1, [r1]
	adds r0, r1
	movs r1, 0xA
	bl __umodsi3
	cmp r0, 0x9
	bls _080F4A60
	b _080F4B3A
_080F4A60:
	lsls r0, 2
	ldr r1, =_080F4A74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4A74:
	.4byte _080F4A9C
	.4byte _080F4AA8
	.4byte _080F4AB4
	.4byte _080F4AC0
	.4byte _080F4ACC
	.4byte _080F4AD8
	.4byte _080F4AE4
	.4byte _080F4AF0
	.4byte _080F4AFC
	.4byte _080F4B08
_080F4A9C:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AA8:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AB4:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AC0:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4ACC:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AD8:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AE4:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AF0:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AFC:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4B08:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4B14:
	movs r0, 0xB
	strb r0, [r2]
	b _080F4B3A
_080F4B1A:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	bl TVShowDone
_080F4B3A:
	ldr r0, =gUnknown_0858D4B4
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTrainerFanClub

	thumb_func_start DoTVShowSpotTheCuties
DoTVShowSpotTheCuties: @ 80F4B5C
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0xF
	bls _080F4B82
	b _080F4D84
_080F4B82:
	lsls r0, r5, 2
	ldr r1, =_080F4BA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4BA4:
	.4byte _080F4BE4
	.4byte _080F4C30
	.4byte _080F4C30
	.4byte _080F4C30
	.4byte _080F4C64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D80
_080F4BE4:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xF]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	cmp r1, 0x9
	bhi _080F4C14
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C14:
	cmp r1, 0x13
	bhi _080F4C24
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C24:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C30:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xF]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C64:
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0x18
	bls _080F4C76
	b _080F4D84
_080F4C76:
	lsls r0, 2
	ldr r1, =_080F4C88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4C88:
	.4byte _080F4CEC
	.4byte _080F4CF8
	.4byte _080F4CF8
	.4byte _080F4CF8
	.4byte _080F4CF8
	.4byte _080F4D04
	.4byte _080F4D04
	.4byte _080F4D04
	.4byte _080F4D04
	.4byte _080F4D10
	.4byte _080F4D10
	.4byte _080F4D10
	.4byte _080F4D10
	.4byte _080F4D1C
	.4byte _080F4D1C
	.4byte _080F4D1C
	.4byte _080F4D1C
	.4byte _080F4D28
	.4byte _080F4D28
	.4byte _080F4D28
	.4byte _080F4D28
	.4byte _080F4D34
	.4byte _080F4D40
	.4byte _080F4D4C
	.4byte _080F4D58
_080F4CEC:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4CF8:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D04:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D10:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D1C:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D28:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D34:
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D40:
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D4C:
	ldr r1, =sTVShowState
	movs r0, 0xD
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D58:
	ldr r1, =sTVShowState
	movs r0, 0xE
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D64:
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0xF
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D80:
	bl TVShowDone
_080F4D84:
	ldr r0, =gUnknown_0858D4E4
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSpotTheCuties

	thumb_func_start DoTVShowPokemonNewsBattleFrontier
DoTVShowPokemonNewsBattleFrontier: @ 80F4D9C
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r2, r0, 0
	cmp r7, 0x12
	bls _080F4DC4
	b _080F5014
_080F4DC4:
	lsls r0, r7, 2
	ldr r1, =_080F4DE8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4DE8:
	.4byte _080F4E34
	.4byte _080F4F18
	.4byte _080F4ECE
	.4byte _080F4EF4
	.4byte _080F4EF4
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F3C
	.4byte _080F4F74
	.4byte _080F4F9C
	.4byte _080F4FE0
	.4byte _080F5004
_080F4E34:
	ldrb r0, [r6, 0xD]
	subs r0, 0x1
	cmp r0, 0xC
	bls _080F4E3E
	b _080F5014
_080F4E3E:
	lsls r0, 2
	ldr r1, =_080F4E4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4E4C:
	.4byte _080F4E80
	.4byte _080F4E86
	.4byte _080F4E8C
	.4byte _080F4E92
	.4byte _080F4E98
	.4byte _080F4E9E
	.4byte _080F4EA4
	.4byte _080F4EAA
	.4byte _080F4EB0
	.4byte _080F4EB6
	.4byte _080F4EBC
	.4byte _080F4EC2
	.4byte _080F4EC8
_080F4E80:
	movs r0, 0x1
	strb r0, [r2]
	b _080F5014
_080F4E86:
	movs r0, 0x2
	strb r0, [r2]
	b _080F5014
_080F4E8C:
	movs r0, 0x3
	strb r0, [r2]
	b _080F5014
_080F4E92:
	movs r0, 0x4
	strb r0, [r2]
	b _080F5014
_080F4E98:
	movs r0, 0x5
	strb r0, [r2]
	b _080F5014
_080F4E9E:
	movs r0, 0x6
	strb r0, [r2]
	b _080F5014
_080F4EA4:
	movs r0, 0x7
	strb r0, [r2]
	b _080F5014
_080F4EAA:
	movs r0, 0x8
	strb r0, [r2]
	b _080F5014
_080F4EB0:
	movs r0, 0x9
	strb r0, [r2]
	b _080F5014
_080F4EB6:
	movs r0, 0xA
	strb r0, [r2]
	b _080F5014
_080F4EBC:
	movs r0, 0xB
	strb r0, [r2]
	b _080F5014
_080F4EC2:
	movs r0, 0xC
	strb r0, [r2]
	b _080F5014
_080F4EC8:
	movs r0, 0xD
	strb r0, [r2]
	b _080F5014
_080F4ECE:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x10
	strb r0, [r1]
	b _080F5014
	.pool
_080F4EF4:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0xF
	strb r0, [r1]
	b _080F5014
	.pool
_080F4F18:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0xE
	strb r0, [r1]
	b _080F5014
	.pool
_080F4F3C:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x4]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x8]
	muls r1, r5
	adds r1, r4
	b _080F4FEC
	.pool
_080F4F74:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x4]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	muls r1, r5
	adds r1, r4
	b _080F4FEC
	.pool
_080F4F9C:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x4]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x8]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x11
	strb r0, [r1]
	b _080F5014
	.pool
_080F4FE0:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0xA]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
_080F4FEC:
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x12
	strb r0, [r1]
	b _080F5014
	.pool
_080F5004:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F5014:
	ldr r0, =gUnknown_0858D524
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonNewsBattleFrontier

	thumb_func_start DoTVShowWhatsNo1InHoennToday
DoTVShowWhatsNo1InHoennToday: @ 80F5030
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x8
	bls _080F5056
	b _080F5164
_080F5056:
	lsls r0, r5, 2
	ldr r1, =_080F5078
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F5078:
	.4byte _080F509C
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5154
_080F509C:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x5]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x4]
	cmp r0, 0x6
	bhi _080F5164
	lsls r0, 2
	ldr r1, =_080F50C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F50C0:
	.4byte _080F50DC
	.4byte _080F50E8
	.4byte _080F50F4
	.4byte _080F5100
	.4byte _080F510C
	.4byte _080F5118
	.4byte _080F5124
_080F50DC:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F5164
	.pool
_080F50E8:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F5164
	.pool
_080F50F4:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F5164
	.pool
_080F5100:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F5164
	.pool
_080F510C:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F5164
	.pool
_080F5118:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F5164
	.pool
_080F5124:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F5164
	.pool
_080F5130:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x5]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F5164
	.pool
_080F5154:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x5]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F5164:
	ldr r0, =gUnknown_0858D570
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowWhatsNo1InHoennToday

	thumb_func_start sub_80F5180
sub_80F5180: @ 80F5180
	push {r4,lr}
	movs r1, 0
	movs r2, 0
	ldr r3, [r0, 0xC]
	movs r4, 0x1
_080F518A:
	adds r0, r3, 0
	lsrs r0, r1
	ands r0, r4
	cmp r0, 0
	beq _080F519A
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080F519A:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1F
	bls _080F518A
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80F5180

	thumb_func_start sub_80F51AC
sub_80F51AC: @ 80F51AC
	push {r4-r6,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	movs r2, 0
	movs r3, 0
	ldr r1, [r0, 0xC]
	movs r5, 0x1
	ldr r6, =gUnknown_0858D690
_080F51BC:
	adds r0, r1, 0
	lsrs r0, r2
	ands r0, r5
	cmp r0, 0
	beq _080F51DA
	cmp r3, r4
	bne _080F51D4
	adds r0, r2, r6
	ldrb r0, [r0]
	b _080F51E6
	.pool
_080F51D4:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_080F51DA:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _080F51BC
	movs r0, 0
_080F51E6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F51AC

	thumb_func_start DoTVShowSecretBaseSecrets
DoTVShowSecretBaseSecrets: @ 80F51EC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r2, [r0]
	mov r9, r2
	adds r2, r0, 0
	mov r0, r9
	cmp r0, 0x2B
	bls _080F521E
	b _080F552A
_080F521E:
	lsls r0, 2
	ldr r1, =_080F5240
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F5240:
	.4byte _080F52F0
	.4byte _080F5348
	.4byte _080F53C4
	.4byte _080F5444
	.4byte _080F5498
	.4byte _080F5498
	.4byte _080F5498
	.4byte _080F54C4
	.4byte _080F54E8
	.4byte _080F54EC
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F54F0
	.4byte _080F5510
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
_080F52F0:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80F5180
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _080F5328
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F552A
	.pool
_080F5328:
	movs r0, 0x1
	strb r0, [r5, 0x12]
	bl Random
	ldr r4, =gUnknown_0203A031
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	b _080F542A
	.pool
_080F5348:
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80F5180
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	beq _080F53DE
	cmp r6, 0x2
	beq _080F5370
	movs r4, 0
	b _080F538A
	.pool
_080F5370:
	strb r6, [r5, 0x12]
	ldr r0, =gUnknown_0203A031
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F5384
	adds r0, r5, 0
	movs r1, 0x1
	b _080F542C
	.pool
_080F5384:
	adds r0, r5, 0
	movs r1, 0
	b _080F542C
_080F538A:
	bl Random
	ldr r7, =gUnknown_0203A031
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	strb r0, [r7, 0x1]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r7]
	cmp r0, r1
	bne _080F53B2
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000fffe
	cmp r4, r0
	bls _080F538A
_080F53B2:
	movs r0, 0x2
	strb r0, [r5, 0x12]
	ldrb r1, [r7, 0x1]
	b _080F542A
	.pool
_080F53C4:
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80F5180
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bne _080F53F0
_080F53DE:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F552A
	.pool
_080F53F0:
	movs r4, 0
	ldr r7, =gUnknown_0203A031
	ldr r2, =0x0000fffe
	mov r8, r2
_080F53F8:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	strb r0, [r7, 0x2]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r7]
	cmp r0, r1
	beq _080F5418
	ldrb r2, [r7, 0x1]
	cmp r0, r2
	bne _080F5422
_080F5418:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r8
	bls _080F53F8
_080F5422:
	movs r0, 0x3
	strb r0, [r5, 0x12]
	ldr r0, =gUnknown_0203A031
	ldrb r1, [r0, 0x2]
_080F542A:
	adds r0, r5, 0
_080F542C:
	bl sub_80F51AC
	ldr r1, =sTVShowState
	strb r0, [r1]
	b _080F552A
	.pool
_080F5444:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	bl TV_ConvertNumberToOrdinal
	ldrh r0, [r5, 0x2]
	cmp r0, 0x1E
	bhi _080F547C
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F552A
	.pool
_080F547C:
	cmp r0, 0x64
	bhi _080F548C
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F552A
	.pool
_080F548C:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F552A
	.pool
_080F5498:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F552A
	.pool
_080F54C4:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	bl TVShowDone
	b _080F552A
	.pool
_080F54E8:
	movs r0, 0x3
	b _080F5528
_080F54EC:
	movs r0, 0x3
	b _080F5528
_080F54F0:
	ldr r4, =gStringVar2
	ldrh r0, [r5, 0x10]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =sTVShowState
	ldrb r0, [r5, 0x12]
	strb r0, [r1]
	b _080F552A
	.pool
_080F5510:
	adds r0, r5, 0
	adds r0, 0x22
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F5522
	movs r0, 0x16
	b _080F5528
_080F5522:
	movs r0, 0x15
	b _080F5528
_080F5526:
	ldrb r0, [r5, 0x12]
_080F5528:
	strb r0, [r2]
_080F552A:
	ldr r0, =gUnknown_0858D594
	mov r2, r9
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSecretBaseSecrets

	thumb_func_start DoTVShowSafariFanClub
DoTVShowSafariFanClub: @ 80F5548
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0xA
	bls _080F5570
	b _080F56BC
_080F5570:
	lsls r0, r5, 2
	ldr r1, =_080F5594
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F5594:
	.4byte _080F55C0
	.4byte _080F55DC
	.4byte _080F5614
	.4byte _080F5628
	.4byte _080F569A
	.4byte _080F562E
	.4byte _080F5650
	.4byte _080F5680
	.4byte _080F5694
	.4byte _080F569A
	.4byte _080F56B8
_080F55C0:
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080F55CC
	movs r0, 0x6
	strb r0, [r2]
	b _080F56BC
_080F55CC:
	cmp r1, 0x3
	bhi _080F55D6
	movs r0, 0x5
	strb r0, [r2]
	b _080F56BC
_080F55D6:
	movs r0, 0x1
	strb r0, [r2]
	b _080F56BC
_080F55DC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	bne _080F5608
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5608:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5614:
	ldrb r1, [r4, 0x3]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5628:
	movs r0, 0x4
	strb r0, [r2]
	b _080F56BC
_080F562E:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F5662
	b _080F5674
	.pool
_080F5650:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	bne _080F5674
_080F5662:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5674:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5680:
	ldrb r1, [r4, 0x3]
	movs r0, 0x1
	bl TV_ConvertNumberToOrdinal
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5694:
	movs r0, 0x9
	strb r0, [r2]
	b _080F56BC
_080F569A:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F56BC
	.pool
_080F56B8:
	bl TVShowDone
_080F56BC:
	ldr r0, =gUnknown_0858D640
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSafariFanClub

	thumb_func_start DoTVShowPokemonContestLiveUpdates2
DoTVShowPokemonContestLiveUpdates2: @ 80F56D4
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r6, =sTVShowState
	ldrb r5, [r6]
	cmp r5, 0x2
	bgt _080F5718
	cmp r5, 0x1
	bge _080F5744
	cmp r5, 0
	beq _080F571E
	b _080F575E
	.pool
_080F5718:
	cmp r5, 0x3
	beq _080F574E
	b _080F575E
_080F571E:
	ldr r0, =gStringVar1
	ldrb r1, [r4, 0xA]
	bl sub_818E868
	ldrb r1, [r4, 0x16]
	cmp r1, 0x1
	bne _080F5734
	strb r1, [r6]
	b _080F575E
	.pool
_080F5734:
	cmp r1, 0
	bne _080F573E
	movs r0, 0x2
	strb r0, [r6]
	b _080F575E
_080F573E:
	movs r0, 0x3
	strb r0, [r6]
	b _080F575E
_080F5744:
	ldr r0, =gStringVar3
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
_080F574E:
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xB
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F575E:
	ldr r0, =gUnknown_0858D384
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonContestLiveUpdates2

	thumb_func_start TVShowDone
TVShowDone: @ 80F577C
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, =sTVShowState
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r0, =0x000027cd
	adds r2, r0
	movs r0, 0
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end TVShowDone

	thumb_func_start ResetTVShowState
ResetTVShowState: @ 80F57B8
	ldr r1, =sTVShowState
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetTVShowState

	.align 2, 0 @ Don't pad with nop.
