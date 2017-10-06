	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

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
	bl player_id_to_dword
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

	thumb_func_start GetTVChannelByShowType
GetTVChannelByShowType: @ 80EFFE0
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
	thumb_func_end GetTVChannelByShowType

	thumb_func_start player_id_to_dword
player_id_to_dword: @ 80F0020
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
	thumb_func_end player_id_to_dword

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
	bl FindEmptyTVSlotBeyondFirstFiveShowsOfArray
	ldr r1, =sCurTVShowSlot
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
	bl DeleteTVShowInArrayByIdx
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
	bl GetTVChannelByShowType
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
	ldr r0, =sCurTVShowSlot
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
	ldr r0, =sCurTVShowSlot
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
	ldr r0, =sCurTVShowSlot
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
	bl DeleteTVShowInArrayByIdx
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
	bl GetTVChannelByShowType
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
	bl DeleteTVShowInArrayByIdx
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
	ldr r1, =sCurTVShowSlot
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
	ldr r2, =sCurTVShowSlot
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
	bl ClearPokemonNewsI
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
	ldrh r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
	ldrb r1, [r4, 0x5]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	ldr r2, =gDecorations + 1
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
	ldr r2, =gDecorations + 1
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
	ldr r4, =gDecorations + 1
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
	ldr r2, =gDecorations + 1
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
	bl TV_PrintIntToStringVar
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
