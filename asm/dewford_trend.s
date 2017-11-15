	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start InitDewfordTrend
InitDewfordTrend: @ 81224D4
	push {r4-r7,lr}
	movs r6, 0
	ldr r5, =gSaveBlock1Ptr
_081224DA:
	movs r0, 0xA
	bl sub_811EE38
	ldr r1, [r5]
	lsls r4, r6, 3
	adds r1, r4
	ldr r2, =0x00002e6c
	adds r1, r2
	strh r0, [r1]
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08122514
	movs r0, 0xC
	bl sub_811EE38
	ldr r1, [r5]
	adds r1, r4
	ldr r7, =0x00002e6e
	adds r1, r7
	b _08122522
	.pool
_08122514:
	movs r0, 0xD
	bl sub_811EE38
	ldr r1, [r5]
	adds r1, r4
	ldr r2, =0x00002e6e
	adds r1, r2
_08122522:
	strh r0, [r1]
	bl Random
	ldr r3, [r5]
	adds r3, r4
	movs r2, 0x1
	ands r2, r0
	ldr r7, =0x00002e69
	adds r3, r7
	lsls r2, 6
	ldrb r0, [r3]
	movs r7, 0x41
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, =0x00002e68
	adds r1, r4, r0
	ldr r0, [r5]
	adds r0, r1
	bl sub_8122B28
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x4
	bls _081224DA
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e68
	adds r0, r1
	movs r1, 0x5
	movs r2, 0
	bl sub_8122804
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitDewfordTrend

	thumb_func_start sub_8122580
sub_8122580: @ 8122580
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08122596
	b _081226BE
_08122596:
	lsls r0, r1, 2
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	mov r10, r0
	movs r1, 0x7F
	mov r9, r1
	movs r2, 0x80
	negs r2, r2
	mov r8, r2
_081225AA:
	ldr r2, [sp]
	mov r3, r10
	lsls r0, r3, 3
	ldr r4, =0x00002e68
	adds r0, r4
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	adds r5, r1, r0
	ldrb r6, [r5, 0x1]
	movs r0, 0x40
	ands r0, r6
	cmp r0, 0
	bne _08122608
	ldrb r4, [r5]
	lsls r3, r4, 25
	lsrs r1, r3, 25
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r1, r0
	bcc _081225F8
	adds r0, r1, 0
	subs r0, r2
	mov r1, r9
	ands r0, r1
	mov r1, r8
	ands r1, r4
	orrs r1, r0
	strb r1, [r5]
	movs r0, 0x7F
	ands r1, r0
	cmp r1, 0
	bne _0812269E
	movs r0, 0x40
	orrs r0, r6
	b _0812269C
	.pool
_081225F8:
	lsrs r0, r3, 25
	subs r2, r0
	mov r0, r8
	ands r0, r4
	strb r0, [r5]
	movs r0, 0x40
	orrs r0, r6
	strb r0, [r5, 0x1]
_08122608:
	ldrb r7, [r5]
	lsls r0, r7, 25
	lsrs r0, 25
	adds r4, r0, r2
	ldrh r0, [r5]
	lsls r6, r0, 18
	lsls r0, r4, 16
	lsrs r0, 16
	lsrs r1, r6, 25
	cmp r0, r1
	bls _08122678
	adds r0, r4, 0
	bl __umodsi3
	adds r3, r0, 0
	lsrs r1, r6, 25
	adds r0, r4, 0
	str r3, [sp, 0x4]
	bl __udivsi3
	adds r4, r0, 0
	movs r0, 0x1
	eors r4, r0
	ands r4, r0
	lsls r2, r4, 6
	ldrb r0, [r5, 0x1]
	movs r4, 0x41
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x1]
	movs r1, 0x40
	ands r0, r1
	ldr r3, [sp, 0x4]
	cmp r0, 0
	beq _08122662
	adds r1, r3, 0
	mov r0, r9
	ands r1, r0
	mov r0, r8
	ands r0, r7
	orrs r0, r1
	strb r0, [r5]
	b _0812269E
_08122662:
	ldrh r0, [r5]
	lsls r0, 18
	lsrs r0, 25
	subs r0, r3
	mov r1, r9
	ands r0, r1
	mov r1, r8
	ands r1, r7
	orrs r1, r0
	strb r1, [r5]
	b _0812269E
_08122678:
	mov r2, r9
	ands r4, r2
	mov r0, r8
	ands r0, r7
	orrs r0, r4
	strb r0, [r5]
	lsls r0, 25
	ldrh r1, [r5]
	lsls r1, 18
	lsrs r0, 25
	lsrs r1, 25
	cmp r0, r1
	bne _0812269E
	ldrb r0, [r5, 0x1]
	movs r3, 0x41
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
_0812269C:
	strb r0, [r5, 0x1]
_0812269E:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	cmp r0, 0x4
	bhi _081226AE
	b _081225AA
_081226AE:
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00002e68
	adds r0, r1
	movs r1, 0x5
	movs r2, 0
	bl sub_8122804
_081226BE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8122580

	thumb_func_start sub_81226D8
sub_81226D8: @ 81226D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r8, r0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, r8
	bl sub_8122BB0
	lsls r0, 24
	cmp r0, 0
	beq _081226F8
	b _081227F2
_081226F8:
	ldr r4, =0x00000893
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08122744
	adds r0, r4, 0
	bl FlagSet
	ldr r0, =0x00000894
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08122744
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	mov r0, r8
	ldrh r2, [r0]
	ldr r3, =0x00002e6c
	adds r0, r1, r3
	strh r2, [r0]
	mov r2, r8
	ldrh r0, [r2, 0x2]
	adds r3, 0x2
	adds r1, r3
	strh r0, [r1]
	movs r0, 0x1
	b _081227F4
	.pool
_08122744:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	lsls r1, 16
	ldrh r0, [r0]
	orrs r0, r1
	str r0, [sp, 0x4]
	movs r1, 0x80
	lsls r1, 7
	ldr r0, [sp]
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_8122B28
	movs r5, 0
_08122762:
	ldr r6, =gSaveBlock1Ptr
	lsls r4, r5, 3
	ldr r1, =0x00002e68
	adds r0, r4, r1
	ldr r1, [r6]
	adds r1, r0
	mov r0, sp
	movs r2, 0
	bl atk90_changetypestoenemyattacktype
	lsls r0, 24
	adds r7, r4, 0
	cmp r0, 0
	beq _081227D4
	movs r2, 0x4
	mov r12, r6
	cmp r2, r5
	bls _081227A6
	ldr r4, =0x00002e68
_08122788:
	ldr r0, [r6]
	lsls r3, r2, 3
	adds r0, r4
	adds r3, r0, r3
	subs r2, 0x1
	lsls r1, r2, 3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, 0x4]
	lsls r2, 16
	lsrs r2, 16
	cmp r2, r5
	bhi _08122788
_081227A6:
	mov r3, r12
	ldr r2, [r3]
	ldr r0, =0x00002e68
	adds r2, r0
	adds r2, r7
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r5, 0x4
	bne _081227C2
	mov r0, r8
	bl sub_80EDC60
_081227C2:
	movs r0, 0
	cmp r5, 0
	bne _081227F4
	movs r0, 0x1
	b _081227F4
	.pool
_081227D4:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x4
	bls _08122762
	ldr r2, [r6]
	ldr r1, =0x00002e88
	adds r2, r1
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r0, r8
	bl sub_80EDC60
_081227F2:
	movs r0, 0
_081227F4:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81226D8

	thumb_func_start sub_8122804
sub_8122804: @ 8122804
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r2, 0
	cmp r2, r7
	bcs _0812286C
_08122820:
	adds r1, r2, 0x1
	lsls r0, r1, 16
	lsrs r5, r0, 16
	mov r8, r1
	cmp r5, r7
	bcs _08122862
	lsls r0, r2, 3
	mov r1, r9
	adds r6, r1, r0
_08122832:
	lsls r0, r5, 3
	mov r1, r9
	adds r4, r1, r0
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r10
	bl atk90_changetypestoenemyattacktype
	lsls r0, 24
	cmp r0, 0
	beq _08122858
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [r4]
	str r1, [r4, 0x4]
	str r2, [r6]
	str r3, [r6, 0x4]
_08122858:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r7
	bcc _08122832
_08122862:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r2, r0, 16
	cmp r2, r7
	bcc _08122820
_0812286C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8122804

	thumb_func_start sub_812287C
sub_812287C: @ 812287C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	adds r6, r1, 0
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	bl Alloc
	mov r10, r0
	cmp r0, 0
	beq _08122980
	adds r0, r4, 0
	bl Alloc
	adds r7, r0, 0
	cmp r7, 0
	bne _081228B0
	mov r0, r10
	bl Free
	b _08122980
_081228B0:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	cmp r5, r9
	bcs _081228DE
_081228C0:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	add r0, r10
	adds r1, r5, 0
	muls r1, r6
	add r1, r8
	movs r2, 0x28
	bl memcpy
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r9
	bcc _081228C0
_081228DE:
	mov r4, r10
	mov r8, r7
	movs r3, 0
	movs r5, 0
	cmp r5, r9
	bcs _08122946
_081228EA:
	movs r6, 0
_081228EC:
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r3, 0
	str r3, [sp]
	bl sub_8122C1C
	lsls r0, 16
	asrs r0, 16
	ldr r3, [sp]
	cmp r0, 0
	bge _08122918
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	mov r2, r8
	adds r2, 0x8
	mov r8, r2
	subs r2, 0x8
	stm r2!, {r0,r1}
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	b _08122930
_08122918:
	lsls r0, 3
	adds r2, r7, r0
	ldrb r1, [r2]
	lsls r1, 25
	ldrb r0, [r4]
	lsls r0, 25
	cmp r1, r0
	bcs _08122930
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
_08122930:
	adds r4, 0x8
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x4
	bls _081228EC
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r9
	bcc _081228EA
_08122946:
	adds r0, r7, 0
	adds r1, r3, 0
	movs r2, 0x2
	bl sub_8122804
	adds r4, r7, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e68
	adds r1, r0
	mov r8, r1
	movs r5, 0
_0812295E:
	ldm r4!, {r0,r1}
	mov r2, r8
	adds r2, 0x8
	mov r8, r2
	subs r2, 0x8
	stm r2!, {r0,r1}
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x4
	bls _0812295E
	mov r0, r10
	bl Free
	adds r0, r7, 0
	bl Free
_08122980:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812287C

	thumb_func_start sub_8122998
sub_8122998: @ 8122998
	push {lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r1, 3
	ldr r0, [r2]
	adds r1, r0
	ldr r0, =gStringVar1
	ldr r2, =0x00002e6c
	adds r1, r2
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertEasyChatWordsToString
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8122998

	thumb_func_start sub_81229C8
sub_81229C8: @ 81229C8
	push {r4,lr}
	movs r4, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r1, =0x00002e68
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 25
	lsrs r1, 25
	ldr r2, =0x00002e70
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, 25
	lsrs r0, 25
	subs r1, r0
	cmp r1, 0x1
	bgt _08122A0C
	ldr r1, =0x00002e69
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r2, 0x40
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08122A0C
	ldr r1, =0x00002e71
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	lsrs r4, r0, 31
_08122A0C:
	ldr r0, =gSpecialVar_Result
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81229C8

	thumb_func_start sub_8122A30
sub_8122A30: @ 8122A30
	ldr r2, =gSpecialVar_Result
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00002e6c
	adds r1, r0, r3
	adds r3, 0x2
	adds r0, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8122A30

	thumb_func_start atk90_changetypestoenemyattacktype
atk90_changetypestoenemyattacktype: @ 8122A58
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r2, 0
	cmp r2, 0x1
	beq _08122A9E
	cmp r2, 0x1
	bgt _08122A72
	cmp r2, 0
	beq _08122A78
	b _08122B1A
_08122A72:
	cmp r0, 0x2
	beq _08122ACA
	b _08122B1A
_08122A78:
	ldrb r0, [r3]
	lsls r1, r0, 25
	ldrb r0, [r5]
	lsls r0, 25
	cmp r1, r0
	bhi _08122B16
	cmp r1, r0
	bcc _08122AC6
	ldrh r0, [r3]
	lsls r3, r0, 18
	ldrh r0, [r5]
	lsls r2, r0, 18
	lsrs r1, r3, 25
	lsrs r0, r2, 25
	cmp r1, r0
	bhi _08122B16
	lsrs r1, r3, 25
	lsrs r0, r2, 25
	b _08122AC2
_08122A9E:
	ldrh r0, [r3]
	lsls r4, r0, 18
	ldrh r0, [r5]
	lsls r2, r0, 18
	lsrs r1, r4, 25
	lsrs r0, r2, 25
	cmp r1, r0
	bhi _08122B16
	lsrs r1, r4, 25
	lsrs r0, r2, 25
	cmp r1, r0
	bcc _08122AC6
	ldrb r0, [r3]
	lsls r1, r0, 25
	ldrb r0, [r5]
	lsls r0, 25
	cmp r1, r0
	bhi _08122B16
_08122AC2:
	cmp r1, r0
	bcs _08122B1A
_08122AC6:
	movs r0, 0
	b _08122B22
_08122ACA:
	ldrb r0, [r3]
	lsls r1, r0, 25
	ldrb r0, [r5]
	lsls r0, 25
	cmp r1, r0
	bhi _08122B16
	cmp r1, r0
	bcc _08122AC6
	ldrh r0, [r3]
	lsls r4, r0, 18
	ldrh r0, [r5]
	lsls r2, r0, 18
	lsrs r1, r4, 25
	lsrs r0, r2, 25
	cmp r1, r0
	bhi _08122B16
	lsrs r1, r4, 25
	lsrs r0, r2, 25
	cmp r1, r0
	bcc _08122AC6
	ldrh r1, [r3, 0x2]
	ldrh r0, [r5, 0x2]
	cmp r1, r0
	bhi _08122B16
	cmp r1, r0
	bcc _08122AC6
	ldrh r1, [r3, 0x4]
	ldrh r0, [r5, 0x4]
	cmp r1, r0
	bhi _08122B16
	cmp r1, r0
	bcc _08122AC6
	ldrh r1, [r3, 0x6]
	ldrh r0, [r5, 0x6]
	cmp r1, r0
	bhi _08122B16
	cmp r1, r0
	bcc _08122AC6
_08122B16:
	movs r0, 0x1
	b _08122B22
_08122B1A:
	bl Random
	movs r1, 0x1
	ands r0, r1
_08122B22:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end atk90_changetypestoenemyattacktype

	thumb_func_start sub_8122B28
sub_8122B28: @ 8122B28
	push {r4,r5,lr}
	adds r5, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x62
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x32
	bls _08122B6A
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x62
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x50
	bls _08122B6A
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x62
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
_08122B6A:
	adds r1, r4, 0
	adds r1, 0x1E
	movs r0, 0x7F
	ands r1, r0
	lsls r1, 7
	ldrh r2, [r5]
	ldr r0, =0xffffc07f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0x1
	bl __modsi3
	adds r0, 0x1E
	movs r1, 0x7F
	ands r0, r1
	ldrb r2, [r5]
	movs r1, 0x80
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r5]
	bl Random
	strh r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8122B28

	thumb_func_start sub_8122BB0
sub_8122BB0: @ 8122BB0
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gSaveBlock1Ptr
_08122BB8:
	lsls r1, r4, 3
	ldr r0, [r6]
	adds r1, r0
	ldr r0, =0x00002e6c
	adds r1, r0
	adds r0, r5, 0
	bl sub_8122BF0
	lsls r0, 24
	cmp r0, 0
	beq _08122BDC
	movs r0, 0x1
	b _08122BE8
	.pool
_08122BDC:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _08122BB8
	movs r0, 0
_08122BE8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8122BB0

	thumb_func_start sub_8122BF0
sub_8122BF0: @ 8122BF0
	push {r4,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	movs r4, 0
_08122BF8:
	ldrh r1, [r3]
	ldrh r0, [r2]
	adds r2, 0x2
	adds r3, 0x2
	cmp r1, r0
	beq _08122C08
	movs r0, 0
	b _08122C14
_08122C08:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _08122BF8
	movs r0, 0x1
_08122C14:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8122BF0

	thumb_func_start sub_8122C1C
sub_8122C1C: @ 8122C1C
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	lsls r2, 16
	lsrs r6, r2, 16
	movs r4, 0
	cmp r4, r6
	bge _08122C52
_08122C2C:
	adds r1, r5, 0x4
	adds r0, r7, 0x4
	bl sub_8122BF0
	lsls r0, 24
	cmp r0, 0
	beq _08122C40
	lsls r0, r4, 16
	asrs r0, 16
	b _08122C56
_08122C40:
	adds r5, 0x8
	lsls r0, r4, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, r6
	blt _08122C2C
_08122C52:
	movs r0, 0x1
	negs r0, r0
_08122C56:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8122C1C

	.align 2, 0 @ Don't pad with nop.
