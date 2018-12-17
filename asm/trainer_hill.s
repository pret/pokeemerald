	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sp194_trainer_tower
sp194_trainer_tower: @ 81D5494
	push {lr}
	bl sub_81D56B0
	ldr r1, =gUnknown_0862A618
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	bl sub_81D5710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp194_trainer_tower

	thumb_func_start sub_81D54BC
sub_81D54BC: @ 81D54BC
	push {r4-r6,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	ldr r3, =0x00000ef9
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x00003d68
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	adds r6, r2, 0
	ldr r5, =0x00003718
	movs r4, 0x3
_081D54EE:
	ldr r0, [r6]
	adds r0, r5
	ldr r1, =0x00034bbf
	bl sub_81D5DF4
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _081D54EE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D54BC

	thumb_func_start sub_81D5520
sub_81D5520: @ 81D5520
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x12]
	adds r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_81D5520

	thumb_func_start GetTrainerHillOpponentClass
GetTrainerHillOpponentClass: @ 81D5530
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	ldr r2, =gFacilityClassToTrainerClass
	ldr r1, =gUnknown_0203CF58
	ldr r1, [r1]
	adds r1, 0x16
	adds r1, r0
	ldrb r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetTrainerHillOpponentClass

	thumb_func_start GetTrainerHillTrainerName
GetTrainerHillTrainerName: @ 81D5554
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	movs r0, 0xFF
	lsls r0, 24
	adds r1, r0
	lsrs r1, 24
	movs r3, 0
	ldr r0, =gUnknown_0203CF58
	ldr r2, [r0]
	movs r0, 0xB
	muls r0, r1
	adds r2, r0, r2
_081D556E:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r3, 0x1
	cmp r3, 0xA
	ble _081D556E
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetTrainerHillTrainerName

	thumb_func_start GetTrainerHillTrainerFrontSpriteId
GetTrainerHillTrainerFrontSpriteId: @ 81D5588
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81D56B0
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF54
	ldr r3, [r0]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	ldrb r2, [r3]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	ldrb r4, [r3, 0x1B]
	bl sub_81D5710
	ldr r0, =gFacilityClassToPicIndex
	adds r4, r0
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTrainerHillTrainerFrontSpriteId

	thumb_func_start sub_81D55D0
sub_81D55D0: @ 81D55D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81D56B0
	ldr r4, =gUnknown_0203CF58
	movs r0, 0x18
	bl AllocZeroed
	str r0, [r4]
	movs r6, 0
	ldr r0, =gUnknown_0203CF54
	mov r10, r0
_081D55EE:
	movs r5, 0
	lsls r1, r6, 2
	mov r8, r1
	adds r0, r6, 0x1
	mov r9, r0
	movs r0, 0xB
	adds r1, r6, 0
	muls r1, r0
	mov r12, r1
	mov r1, r8
	adds r0, r1, r6
	lsls r0, 3
	adds r0, r6
	lsls r7, r0, 3
_081D560A:
	ldr r0, =gUnknown_0203CF58
	ldr r4, [r0]
	mov r1, r12
	adds r0, r5, r1
	adds r4, r0
	mov r0, r10
	ldr r2, [r0]
	adds r3, r5, r7
	ldrb r1, [r2]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x10
	adds r2, r3
	ldrb r0, [r2]
	strb r0, [r4]
	adds r5, 0x1
	cmp r5, 0xA
	ble _081D560A
	ldr r1, =gUnknown_0203CF58
	ldr r4, [r1]
	adds r4, 0x16
	adds r4, r6
	mov r0, r10
	ldr r3, [r0]
	mov r1, r8
	adds r2, r1, r6
	lsls r2, 3
	adds r2, r6
	ldrb r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	adds r0, r2
	lsls r0, 3
	adds r3, r0
	ldrb r0, [r3, 0x1B]
	strb r0, [r4]
	mov r6, r9
	cmp r6, 0x1
	ble _081D55EE
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	ldr r1, =0x00003d64
	adds r0, r1
	bl sub_80008DC
	bl sub_81D5710
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D55D0

	thumb_func_start sub_81D5694
sub_81D5694: @ 81D5694
	push {r4,lr}
	ldr r4, =gUnknown_0203CF58
	ldr r0, [r4]
	cmp r0, 0
	beq _081D56A6
	bl Free
	movs r0, 0
	str r0, [r4]
_081D56A6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5694

	thumb_func_start sub_81D56B0
sub_81D56B0: @ 81D56B0
	push {r4,lr}
	ldr r4, =gUnknown_0203CF54
	ldr r0, [r4]
	cmp r0, 0
	bne _081D56EC
	ldr r0, =0x00000eec
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gMapHeader
	ldrb r1, [r1, 0x12]
	adds r1, 0x61
	strb r1, [r0]
	ldr r1, =gUnknown_0862A5F8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d6e
	adds r0, r2
	ldrb r0, [r0]
	lsrs r0, 6
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r4]
	adds r1, 0x4
	ldr r2, =0x040003ba
	bl CpuSet
	bl nullsub_2
_081D56EC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D56B0

	thumb_func_start sub_81D5710
sub_81D5710: @ 81D5710
	push {r4,lr}
	ldr r4, =gUnknown_0203CF54
	ldr r0, [r4]
	cmp r0, 0
	beq _081D5722
	bl Free
	movs r0, 0
	str r0, [r4]
_081D5722:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5710

	thumb_func_start CopyTrainerHillTrainerText
CopyTrainerHillTrainerText: @ 81D572C
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81D56B0
	bl sub_81D5520
	lsls r0, 24
	lsrs r2, r0, 24
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	cmp r5, 0x3
	beq _081D5790
	cmp r5, 0x3
	bgt _081D575A
	cmp r5, 0x2
	beq _081D5764
	b _081D580E
_081D575A:
	cmp r6, 0x4
	beq _081D57BC
	cmp r6, 0x5
	beq _081D57E8
	b _081D580E
_081D5764:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x10
	bl FrontierSpeechToString
	b _081D580E
	.pool
_081D5790:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x1C
	bl FrontierSpeechToString
	b _081D580E
	.pool
_081D57BC:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x28
	bl FrontierSpeechToString
	b _081D580E
	.pool
_081D57E8:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x34
	bl FrontierSpeechToString
_081D580E:
	bl sub_81D5710
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyTrainerHillTrainerText

	thumb_func_start sub_81D581C
sub_81D581C: @ 81D581C
	push {r4-r6,lr}
	bl nullsub_2
	bl sub_81D3B34
	cmp r0, 0
	bne _081D5844
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	ldr r0, =0x00003d6e
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x20
	orrs r0, r2
	b _081D5854
	.pool
_081D5844:
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	ldr r0, =0x00003d6e
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
_081D5854:
	strb r0, [r1]
	adds r6, r3, 0
	ldr r0, [r6]
	ldr r1, =0x00003d6c
	adds r0, r1
	movs r5, 0
	strb r5, [r0]
	ldr r0, [r6]
	ldr r4, =0x00003d64
	adds r0, r4
	bl sub_80008DC
	ldr r1, [r6]
	adds r4, r1, r4
	str r5, [r4]
	ldr r3, =0x00003d6e
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xEE
	lsls r1, 4
	adds r0, r1
	strb r5, [r0]
	ldr r0, =gBattleOutcome
	strb r5, [r0]
	ldr r1, [r6]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D581C

	thumb_func_start sub_81D58D8
sub_81D58D8: @ 81D58D8
	push {lr}
	bl sub_80008E8
	ldr r3, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r3]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D58FA
	movs r0, 0x1
	strh r0, [r3]
_081D58FA:
	ldrb r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x3
	bne _081D590A
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
_081D590A:
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D58D8

	thumb_func_start sub_81D5924
sub_81D5924: @ 81D5924
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_81D6640
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_0203CF54
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0x4
	bne _081D5952
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r0, [r0]
	ldr r7, =0x00003d6e
	adds r0, r7
	ldrb r0, [r0]
	movs r6, 0x1
	adds r4, r6, 0
	ands r4, r0
	cmp r4, 0
	beq _081D596C
_081D5952:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
	strh r0, [r1]
	b _081D59C0
	.pool
_081D596C:
	adds r0, r5, 0
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D59BC
	ldr r1, =gStringVar2
	adds r0, r5, 0
	bl CopyItemName
	mov r0, r8
	ldr r1, [r0]
	adds r1, r7
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ef9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gSpecialVar_Result
	strh r4, [r0]
	b _081D59C0
	.pool
_081D59BC:
	ldr r0, =gSpecialVar_Result
	strh r6, [r0]
_081D59C0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5924

	thumb_func_start sub_81D59D0
sub_81D59D0: @ 81D59D0
	push {r4-r6,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r2, [r4]
	ldr r6, =0x00003d6e
	adds r0, r2, r6
	ldrb r1, [r0]
	movs r3, 0x2
	adds r0, r3, 0
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _081D59FC
	ldr r0, =gSpecialVar_Result
	strh r3, [r0]
	b _081D5A4E
	.pool
_081D59FC:
	ldr r1, =0x00003d68
	adds r0, r2, r1
	bl free_203F458
	ldr r2, [r4]
	ldr r3, =0x00003d64
	adds r1, r2, r3
	ldr r1, [r1]
	cmp r0, r1
	bls _081D5A48
	adds r3, 0x4
	adds r0, r2, r3
	bl sub_81D5DF4
	ldr r2, [r4]
	adds r0, r2, r6
	ldrb r0, [r0]
	lsrs r0, 6
	lsls r0, 2
	ldr r3, =0x00003718
	adds r1, r2, r3
	adds r1, r0
	ldr r0, =0x00003d68
	adds r2, r0
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	b _081D5A4E
	.pool
_081D5A48:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081D5A4E:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r3, =0x00003d6e
	adds r1, r3
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D59D0

	thumb_func_start sub_81D5A70
sub_81D5A70: @ 81D5A70
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x00003d6e
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _081D5AAE
	ldr r0, =0x00003d64
	adds r2, r0
	ldr r1, [r2]
	ldr r0, =0x00034bbe
	cmp r1, r0
	bls _081D5AA8
	adds r0, 0x1
	str r0, [r2]
	b _081D5AAE
	.pool
_081D5AA8:
	adds r0, r2, 0
	bl sub_80008DC
_081D5AAE:
	pop {r0}
	bx r0
	thumb_func_end sub_81D5A70

	thumb_func_start sub_81D5AB4
sub_81D5AB4: @ 81D5AB4
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003d6e
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D5AB4

	thumb_func_start sub_81D5AD0
sub_81D5AD0: @ 81D5AD0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D5B00
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081D5B20
	.pool
_081D5B00:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D5B1C
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _081D5B20
	.pool
_081D5B1C:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
_081D5B20:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5AD0

	thumb_func_start sub_81D5B2C
sub_81D5B2C: @ 81D5B2C
	push {r4-r7,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d64
	adds r0, r1
	ldr r7, [r0]
	ldr r0, =0x00034bbe
	cmp r7, r0
	ble _081D5B40
	ldr r7, =0x00034bbf
_081D5B40:
	movs r4, 0xE1
	lsls r4, 4
	adds r0, r7, 0
	adds r1, r4, 0
	bl __divsi3
	adds r6, r0, 0
	adds r0, r7, 0
	adds r1, r4, 0
	bl __modsi3
	adds r7, r0, 0
	movs r1, 0x3C
	bl __divsi3
	adds r5, r0, 0
	adds r0, r7, 0
	movs r1, 0x3C
	bl __modsi3
	adds r7, r0, 0
	movs r0, 0xA8
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r4, r0, 0
	ldr r0, =gStringVar1
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar3
	adds r1, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5B2C

	thumb_func_start sub_81D5BBC
sub_81D5BBC: @ 81D5BBC
	push {lr}
	bl sub_81D56B0
	ldr r0, =gUnknown_0203CF54
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0x4
	beq _081D5BEC
	ldr r0, =gStringVar1
	ldrb r1, [r1, 0x6]
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081D5BF0
	.pool
_081D5BEC:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
_081D5BF0:
	strh r0, [r1]
	bl sub_81D5710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5BBC

	thumb_func_start sub_81D5C00
sub_81D5C00: @ 81D5C00
	push {lr}
	bl sub_81D56B0
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	bl sub_81D5710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5C00

	thumb_func_start sub_81D5C18
sub_81D5C18: @ 81D5C18
	push {lr}
	ldr r0, =0x000040d6
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _081D5C42
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _081D5C42
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	cmp r0, 0
	bne _081D5C54
_081D5C42:
	movs r0, 0
	b _081D5C56
	.pool
_081D5C54:
	movs r0, 0x1
_081D5C56:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5C18

	thumb_func_start sub_81D5C5C
sub_81D5C5C: @ 81D5C5C
	push {lr}
	bl sub_81D5C18
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081D5C74
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
	b _081D5C7A
	.pool
_081D5C74:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081D5C7A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5C5C

	thumb_func_start nullsub_129
nullsub_129: @ 81D5C84
	bx lr
	thumb_func_end nullsub_129

	thumb_func_start nullsub_2
nullsub_2: @ 81D5C88
	bx lr
	thumb_func_end nullsub_2

	thumb_func_start PrintOnTrainerHillRecordsWindow
PrintOnTrainerHillRecordsWindow: @ 81D5C8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	bl sub_81D56B0
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r5, =gText_TimeBoard
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r6, =gUnknown_0862A5F4
	str r6, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x2
	bl AddTextPrinterParameterized3
	movs r7, 0x12
	movs r0, 0
	mov r8, r0
	mov r10, r4
	ldr r1, =gStringVar4
	mov r9, r1
_081D5CD6:
	lsls r3, r7, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0862A5F4
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_0862A660
	mov r1, r8
	lsls r4, r1, 2
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	adds r7, 0xF
	ldr r0, =gSaveBlock1Ptr
	ldr r1, =0x00003718
	adds r4, r1
	ldr r0, [r0]
	adds r0, r4
	bl free_203F458
	adds r4, r0, 0
	movs r5, 0xE1
	lsls r5, 4
	adds r1, r5, 0
	bl __udivsi3
	adds r6, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	adds r5, r0, 0
	ldr r0, =gStringVar1
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0
	movs r1, 0x3C
	bl __udivsi3
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x3C
	bl __umodsi3
	adds r5, r0, 0
	ldr r0, =gStringVar2
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0xA8
	muls r0, r5
	movs r1, 0x64
	bl __udivsi3
	adds r1, r0, 0
	ldr r0, =gStringVar3
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	mov r0, r9
	ldr r1, =gText_TimeCleared
	bl StringCopy
	ldr r1, =gText_XMinYDotZSec
	bl StringExpandPlaceholders
	movs r0, 0x1
	mov r1, r9
	movs r2, 0xD0
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	lsls r3, r7, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0862A5F4
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	adds r7, 0x11
	movs r1, 0x1
	add r8, r1
	mov r0, r8
	cmp r0, 0x3
	ble _081D5CD6
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	bl sub_81D5710
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrintOnTrainerHillRecordsWindow

	thumb_func_start free_203F458
free_203F458: @ 81D5DF0
	ldr r0, [r0]
	bx lr
	thumb_func_end free_203F458

	thumb_func_start sub_81D5DF4
sub_81D5DF4: @ 81D5DF4
	str r1, [r0]
	bx lr
	thumb_func_end sub_81D5DF4

	thumb_func_start sub_81D5DF8
sub_81D5DF8: @ 81D5DF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r1, r0, r1
	str r1, [sp, 0x4]
	bl sub_81D5F48
	cmp r0, 0
	beq _081D5F0E
	bl sub_81D56B0
	movs r7, 0
	ldr r4, =gSaveBlock2Ptr
	ldr r3, =0x00000cb4
	ldr r0, =0x0000ffff
	adds r2, r0, 0
_081D5E26:
	ldr r1, [r4]
	lsls r0, r7, 1
	adds r1, r3
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x1
	bls _081D5E26
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0xC7
	lsls r2, 4
	adds r1, r2
	ldr r2, =0x05000180
	mov r0, sp
	bl CpuSet
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r7, 0
	ldr r3, =gUnknown_0203CF54
	mov r10, r3
_081D5E64:
	lsls r4, r7, 1
	mov r8, r4
	adds r5, r4, r7
	lsls r5, 3
	ldr r0, [sp, 0x4]
	adds r5, r0
	adds r1, r5, 0
	ldr r0, =gUnknown_0862A670
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	adds r6, r7, 0x1
	strb r6, [r5]
	mov r0, r10
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r7
	lsls r0, 3
	mov r2, r9
	lsls r4, r2, 4
	subs r4, r2
	lsls r4, 3
	subs r4, r2
	lsls r4, 3
	adds r0, r4
	adds r1, r0
	ldrb r0, [r1, 0x1B]
	bl sub_81660B8
	strb r0, [r5, 0x1]
	mov r0, r10
	ldr r3, [r0]
	adds r0, r7, r4
	movs r2, 0xF0
	lsls r2, 2
	adds r1, r3, r2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strh r0, [r5, 0x4]
	ldrb r0, [r1]
	lsrs r0, 4
	movs r1, 0xF
	ands r0, r1
	adds r0, 0x5
	strh r0, [r5, 0x6]
	lsls r1, r7, 26
	lsrs r1, 24
	adds r3, r4
	ldr r2, =0x000003c2
	adds r3, r2
	ldrb r0, [r3]
	asrs r0, r1
	movs r3, 0xF
	ands r0, r3
	adds r0, 0x7
	strb r0, [r5, 0x9]
	mov r2, r10
	ldr r0, [r2]
	adds r0, r4
	ldr r3, =0x000003c3
	adds r0, r3
	ldrb r0, [r0]
	asrs r0, r1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r5, 0xE]
	ldr r0, =EventScript_2C83F0
	str r0, [r5, 0x10]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r4, =0x00000cb4
	adds r0, r4
	add r0, r8
	strh r6, [r0]
	lsls r6, 24
	lsrs r7, r6, 24
	cmp r7, 0x1
	bls _081D5E64
	bl sub_81D5710
_081D5F0E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5DF8

	thumb_func_start sub_81D5F48
sub_81D5F48: @ 81D5F48
	push {lr}
	bl sub_81D56B0
	bl sub_81D5710
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81D5F48

	thumb_func_start sub_81D5F58
sub_81D5F58: @ 81D5F58
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_0203CF54
	ldr r4, [r4]
	mov r12, r4
	lsls r4, r2, 1
	lsls r5, r0, 4
	subs r5, r0
	lsls r5, 3
	subs r5, r0
	lsls r5, 3
	adds r4, r5
	movs r0, 0xE8
	lsls r0, 2
	add r0, r12
	adds r0, r4
	ldrh r0, [r0]
	movs r4, 0xF
	subs r4, r1
	asrs r0, r4
	movs r4, 0x1
	ands r0, r4
	muls r2, r3
	adds r2, r1
	adds r2, r5
	movs r1, 0xA8
	lsls r1, 2
	add r1, r12
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x80
	lsls r2, 2
	adds r3, r2, 0
	movs r2, 0xC0
	lsls r2, 6
	lsls r0, 10
	orrs r0, r2
	orrs r1, r3
	orrs r0, r1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D5F58

	thumb_func_start sub_81D5FB4
sub_81D5FB4: @ 81D5FB4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0x6
	bne _081D5FD2
	bl sub_8087D74
	b _081D605E
_081D5FD2:
	bl sub_81D56B0
	mov r0, r9
	cmp r0, 0x5
	bne _081D5FE6
	bl sub_8087D74
	bl sub_81D5710
	b _081D605E
_081D5FE6:
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r1, =gUnknown_03005DC0
	str r4, [r1, 0x8]
	movs r0, 0x1F
	str r0, [r1]
	movs r0, 0x23
	str r0, [r1, 0x4]
	movs r0, 0xE0
	lsls r0, 1
	adds r3, r4, r0
	movs r6, 0x4
_081D600A:
	adds r4, r2, 0
	adds r4, 0x20
	adds r1, r3, 0
	movs r5, 0xF
_081D6012:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _081D6012
	adds r3, 0x3E
	adds r2, r4, 0
	subs r6, 0x1
	cmp r6, 0
	bge _081D600A
	movs r6, 0
_081D602C:
	movs r5, 0
	adds r7, r3, 0
	adds r7, 0x3E
	adds r0, r6, 0x1
	mov r8, r0
	adds r4, r3, 0
_081D6038:
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x10
	bl sub_81D5F58
	strh r0, [r4]
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0xF
	ble _081D6038
	adds r3, r7, 0
	mov r6, r8
	cmp r6, 0xF
	ble _081D602C
	bl mapheader_run_script_with_tag_x1
	bl sub_81D5710
_081D605E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5FB4

	thumb_func_start InTrainerHill
InTrainerHill: @ 81D6074
	push {lr}
	ldr r1, =gMapHeader
	ldr r2, =0xfffffe61
	adds r0, r2, 0
	ldrh r1, [r1, 0x12]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	cmp r0, 0x3
	bhi _081D608C
	movs r1, 0x1
_081D608C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end InTrainerHill

	thumb_func_start GetCurrentTrainerHillMapId
@ u8 GetCurrentTrainerHillMapId()
GetCurrentTrainerHillMapId: @ 81D609C
	push {lr}
	ldr r0, =gMapHeader
	ldrh r2, [r0, 0x12]
	ldr r0, =0x0000019f
	cmp r2, r0
	bne _081D60B4
	movs r1, 0x1
	b _081D60F8
	.pool
_081D60B4:
	movs r0, 0xD0
	lsls r0, 1
	cmp r2, r0
	bne _081D60C0
	movs r1, 0x2
	b _081D60F8
_081D60C0:
	ldr r0, =0x000001a1
	cmp r2, r0
	bne _081D60D0
	movs r1, 0x3
	b _081D60F8
	.pool
_081D60D0:
	movs r0, 0xD1
	lsls r0, 1
	cmp r2, r0
	bne _081D60DC
	movs r1, 0x4
	b _081D60F8
_081D60DC:
	ldr r0, =0x000001a3
	cmp r2, r0
	bne _081D60EC
	movs r1, 0x5
	b _081D60F8
	.pool
_081D60EC:
	movs r0, 0xCF
	lsls r0, 1
	movs r1, 0
	cmp r2, r0
	bne _081D60F8
	movs r1, 0x6
_081D60F8:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end GetCurrentTrainerHillMapId

	thumb_func_start sub_81D6100
sub_81D6100: @ 81D6100
	push {lr}
	ldr r0, =gMapHeader
	ldrh r1, [r0, 0x12]
	ldr r0, =0x000001a3
	movs r2, 0
	cmp r1, r0
	bne _081D6110
	movs r2, 0x1
_081D6110:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6100

	thumb_func_start sub_81D6120
sub_81D6120: @ 81D6120
	push {lr}
	movs r0, 0x1A
	movs r1, 0x40
	bl Overworld_GetMapHeaderByGroupAndId
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_81D6120

	thumb_func_start sub_81D6134
sub_81D6134: @ 81D6134
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D614C
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	b _081D6176
	.pool
_081D614C:
	bl sub_81D6490
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x3
	bls _081D6162
	movs r2, 0x4
_081D6162:
	ldr r1, =gUnknown_0862A688
	subs r0, r2, 0x1
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x1A
	bl Overworld_GetMapHeaderByGroupAndId
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
_081D6176:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6134

	thumb_func_start sub_81D6180
sub_81D6180: @ 81D6180
	lsls r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	lsrs r0, 23
	adds r1, r0
	ldr r0, =0x00000cb2
	adds r1, r0
	ldrh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D6180

	thumb_func_start GetTrainerHillTrainerFlag
@ u8 GetTrainerHillTrainerFlag(u8 eventObjectId)
GetTrainerHillTrainerFlag: @ 81D619C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 23
	ldr r2, =gEventObjects
	lsls r1, r4, 3
	adds r1, r4
	lsls r1, 2
	adds r1, r2
	adds r0, 0xFF
	ldrb r1, [r1, 0x8]
	adds r0, r1
	lsls r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	movs r2, 0xEE
	lsls r2, 4
	adds r1, r2
	ldr r2, =gBitTable
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrb r1, [r1]
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTrainerHillTrainerFlag

	thumb_func_start sub_81D61E8
sub_81D61E8: @ 81D61E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_81D5520
	lsls r0, 25
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, =gTrainerBattleOpponent_A
	mov r8, r0
	ldr r6, =gSaveBlock2Ptr
	ldr r1, =gBitTable
	mov r12, r1
	adds r5, r6, 0
_081D6204:
	ldr r2, [r5]
	lsls r0, r3, 1
	ldr r7, =0x00000cb4
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	mov r1, r8
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D6240
	movs r7, 0xEE
	lsls r7, 4
	adds r2, r7
	adds r0, r4, r3
	lsls r0, 2
	add r0, r12
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _081D624A
	.pool
_081D6240:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _081D6204
_081D624A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _081D62A2
	movs r3, 0
	ldr r5, =gTrainerBattleOpponent_B
	ldr r0, =gBitTable
	mov r8, r0
_081D6260:
	ldr r2, [r6]
	lsls r0, r3, 1
	ldr r7, =0x00000cb4
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	ldrh r1, [r5]
	cmp r0, r1
	bne _081D6298
	movs r7, 0xEE
	lsls r7, 4
	adds r2, r7
	adds r0, r4, r3
	lsls r0, 2
	add r0, r8
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _081D62A2
	.pool
_081D6298:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _081D6260
_081D62A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D61E8

	thumb_func_start sub_81D62AC
sub_81D62AC: @ 81D62AC
	ldr r0, =EventScript_2C83F0
	bx lr
	.pool
	thumb_func_end sub_81D62AC

	thumb_func_start sub_81D62B4
sub_81D62B4: @ 81D62B4
	push {lr}
	ldr r0, =gSpecialVar_LastTalked
	ldrh r1, [r0]
	movs r0, 0x5
	bl CopyTrainerHillTrainerText
	bl sub_80982B8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D62B4

	thumb_func_start sub_81D62CC
sub_81D62CC: @ 81D62CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	subs r1, r0, 0x1
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D636A
	lsls r0, r1, 24
	lsrs r6, r0, 24
	bl sub_81D56B0
	bl GetHighestLevelInPlayerParty
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r5, r9
	adds r0, r5, 0x3
	cmp r5, r0
	bge _081D6366
	ldr r1, =gUnknown_0862A698
	lsls r0, r6, 1
	adds r0, r6
	adds r7, r0, r1
_081D6316:
	ldrb r2, [r7]
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	mov r1, r8
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	adds r0, 0xC
	ldr r3, =gUnknown_0203CF54
	ldr r1, [r3]
	adds r1, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r6
	lsls r0, 3
	adds r0, 0x4
	adds r1, r0
	movs r0, 0x2C
	muls r0, r2
	adds r0, 0x40
	adds r1, r0
	adds r0, r4, 0
	bl sub_806819C
	adds r0, r4, 0
	mov r1, r10
	bl sub_81D642C
	adds r5, 0x1
	adds r7, 0x1
	mov r0, r9
	adds r0, 0x3
	cmp r5, r0
	blt _081D6316
_081D6366:
	bl sub_81D5710
_081D636A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D62CC

	thumb_func_start sub_81D6384
sub_81D6384: @ 81D6384
	push {lr}
	bl ZeroEnemyPartyMons
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	movs r1, 0
	bl sub_81D62CC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6384

	thumb_func_start sub_81D639C
sub_81D639C: @ 81D639C
	push {lr}
	bl ZeroEnemyPartyMons
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	movs r1, 0
	bl sub_81D62CC
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	movs r1, 0x3
	bl sub_81D62CC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D639C

	thumb_func_start sub_81D63C4
sub_81D63C4: @ 81D63C4
	movs r0, 0x7
	bx lr
	thumb_func_end sub_81D63C4

	thumb_func_start sub_81D63C8
sub_81D63C8: @ 81D63C8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81D56B0
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF54
	ldr r3, [r0]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	ldrb r2, [r3]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	ldrb r4, [r3, 0x1B]
	bl sub_81D5710
	movs r2, 0
	ldr r0, =gFacilityClassToTrainerClass
	adds r4, r0
	ldrb r3, [r4]
	ldr r1, =gUnknown_0862A3B4
_081D6406:
	ldrb r0, [r1]
	cmp r0, r3
	bne _081D641C
	ldrb r0, [r1, 0x1]
	b _081D6426
	.pool
_081D641C:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, 0x35
	bls _081D6406
	movs r0, 0
_081D6426:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D63C8

	thumb_func_start sub_81D642C
sub_81D642C: @ 81D642C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	mov r0, sp
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gExperienceTables
	mov r1, sp
	ldrb r2, [r1]
	lsls r2, 2
	ldr r3, =gBaseStats
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r1, [r1, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r1
	adds r2, r0
	adds r2, r5
	ldr r0, [r2]
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r4, 0
	movs r1, 0x19
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x38
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	bl CalculateMonStats
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D642C

	thumb_func_start sub_81D6490
sub_81D6490: @ 81D6490
	push {r4,lr}
	bl sub_81D56B0
	ldr r0, =gUnknown_0203CF54
	ldr r0, [r0]
	ldrb r4, [r0, 0x6]
	bl sub_81D5710
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6490

	thumb_func_start sub_81D64AC
sub_81D64AC: @ 81D64AC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xEE
	lsls r1, 4
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D64AC

	thumb_func_start sub_81D64C0
sub_81D64C0: @ 81D64C0
	push {lr}
	bl sub_81D6534
	cmp r0, 0x1
	bne _081D64D4
	ldr r0, =gUnknown_0862A5D4
	movs r1, 0x70
	movs r2, 0x20
	bl LoadPalette
_081D64D4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D64C0

	thumb_func_start sub_81D64DC
sub_81D64DC: @ 81D64DC
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000ef9
	adds r0, r2
	ldrb r0, [r0]
	lsrs r0, 7
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D64DC

	thumb_func_start sub_81D64FC
sub_81D64FC: @ 81D64FC
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ef9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D64FC

	thumb_func_start sub_81D6518
sub_81D6518: @ 81D6518
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ef9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D6518

	thumb_func_start sub_81D6534
sub_81D6534: @ 81D6534
	push {lr}
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _081D6560
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _081D6560
	bl sub_81D5C00
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0
	beq _081D6560
	movs r0, 0x1
	b _081D6562
	.pool
_081D6560:
	movs r0, 0
_081D6562:
	pop {r1}
	bx r1
	thumb_func_end sub_81D6534

	thumb_func_start sub_81D6568
sub_81D6568: @ 81D6568
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D6590
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081D6594
	.pool
_081D6590:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
_081D6594:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6568

	thumb_func_start sub_81D65A0
sub_81D65A0: @ 81D65A0
	push {r4,r5,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r2, [r4]
	ldr r5, =gSpecialVar_0x8005
	ldr r0, =0x00003d6e
	adds r2, r0
	ldrb r1, [r5]
	lsls r1, 6
	ldrb r3, [r2]
	movs r0, 0x3F
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r4]
	ldr r3, =0x00003d68
	adds r2, r1, r3
	ldrh r0, [r5]
	lsls r0, 2
	ldr r3, =0x00003718
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D65A0

	thumb_func_start sub_81D65E8
sub_81D65E8: @ 81D65E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r3, 0
	movs r4, 0
	ldr r0, =gUnknown_0203CF54
	ldr r6, [r0]
	movs r5, 0x1F
_081D65F8:
	lsls r1, r4, 4
	subs r1, r4
	lsls r1, 3
	subs r1, r4
	lsls r1, 3
	adds r1, r6, r1
	ldrb r2, [r1, 0xC]
	adds r0, r5, 0
	ands r0, r2
	eors r3, r0
	ldrb r1, [r1, 0xD]
	adds r0, r5, 0
	ands r0, r1
	eors r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081D65F8
	movs r1, 0x5
	cmp r7, 0
	beq _081D662A
	movs r1, 0xA
_081D662A:
	adds r0, r3, 0
	bl __umodsi3
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r3, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D65E8

	thumb_func_start sub_81D6640
sub_81D6640: @ 81D6640
	push {r4,r5,lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gUnknown_0203CF54
	ldr r4, [r0]
_081D664A:
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	lsls r0, 3
	adds r0, r4, r0
	ldrb r1, [r0, 0xC]
	adds r1, r3, r1
	ldrb r0, [r0, 0xD]
	adds r3, r1, r0
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _081D664A
	adds r0, r3, 0
	cmp r0, 0
	bge _081D6670
	adds r0, 0xFF
_081D6670:
	asrs r4, r0, 8
	lsrs r0, 31
	adds r0, r4, r0
	asrs r0, 1
	lsls r0, 1
	subs r4, r0
	ldr r0, =0x00000864 @ = FLAG_SYS_GAME_CLEAR
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D66A0
	ldr r0, =gUnknown_0203CF54
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x8
	bne _081D66A0
	movs r0, 0x1
	b _081D66A2
	.pool
_081D66A0:
	movs r0, 0
_081D66A2:
	bl sub_81D65E8
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r5, [r0]
	ldr r1, =0x00003d6e
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0xC0
	bne _081D66C8
	adds r0, r2, 0x1
	movs r1, 0xA
	bl __modsi3
	lsls r0, 24
	lsrs r2, r0, 24
_081D66C8:
	ldr r1, =gUnknown_0862A5CC
	lsls r0, r4, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldr r4, [r0]
	ldr r1, =0x00003d64
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0xE1
	lsls r1, 4
	bl __divsi3
	movs r1, 0
	cmp r0, 0xB
	ble _081D6704
	movs r1, 0x1
	cmp r0, 0xC
	ble _081D6704
	movs r1, 0x2
	cmp r0, 0xD
	ble _081D6704
	movs r1, 0x3
	cmp r0, 0xF
	ble _081D6704
	movs r1, 0x5
	cmp r0, 0x11
	bgt _081D6704
	movs r1, 0x4
_081D6704:
	lsls r0, r1, 1
	adds r0, r4
	ldrh r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6640
