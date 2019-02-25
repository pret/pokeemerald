	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_811F01C
sub_811F01C: @ 811F01C
	push {r4-r6,lr}
	bl sub_811EFF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x21
	bne _0811F048
	b _0811F082
_0811F02C:
	adds r0, r5, 0
	bl sub_811EFC0
	ldr r0, =0x000001ff
	ands r4, r0
	movs r1, 0xA0
	lsls r1, 6
	adds r0, r1, 0
	orrs r4, r0
	adds r0, r4, 0
	b _0811F084
	.pool
_0811F048:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x21
	subs r1, r4
	bl __modsi3
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
_0811F05E:
	lsls r0, r4, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_811EF98
	lsls r0, 24
	cmp r0, 0
	bne _0811F078
	cmp r6, 0
	beq _0811F02C
	subs r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_0811F078:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x20
	bls _0811F05E
_0811F082:
	ldr r0, =0x0000ffff
_0811F084:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F01C

	thumb_func_start sub_811F090
sub_811F090: @ 811F090
	push {r4,r5,lr}
	bl sub_811EFF0
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0811F0B4
	b _0811F0EA
_0811F0A0:
	ldr r0, =0x000001ff
	ands r4, r0
	movs r1, 0xA0
	lsls r1, 6
	adds r0, r1, 0
	orrs r4, r0
	adds r0, r4, 0
	b _0811F0EC
	.pool
_0811F0B4:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	movs r4, 0
_0811F0C8:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_811EF98
	lsls r0, 24
	cmp r0, 0
	beq _0811F0E0
	cmp r5, 0
	beq _0811F0A0
	subs r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0811F0E0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x20
	bls _0811F0C8
_0811F0EA:
	ldr r0, =0x0000ffff
_0811F0EC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F090

	thumb_func_start sub_811F0F8
sub_811F0F8: @ 811F0F8
	push {lr}
	bl IsNationalPokedexEnabled
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_811F0F8

	thumb_func_start sub_811F108
sub_811F108: @ 811F108
	push {r4-r7,lr}
	movs r0, 0
	bl EasyChat_GetNumWordsInGroup
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	bne _0811F128
	b _0811F172
_0811F11A:
	ldrh r1, [r5]
	ldr r0, =0x000001ff
	ands r0, r1
	b _0811F174
	.pool
_0811F128:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gEasyChatGroups
	ldr r5, [r0]
	ldrh r7, [r0, 0x4]
	movs r6, 0
	cmp r6, r7
	bcs _0811F172
_0811F146:
	ldrh r0, [r5]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _0811F166
	cmp r4, 0
	beq _0811F11A
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_0811F166:
	adds r5, 0x2
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r7
	bcc _0811F146
_0811F172:
	ldr r0, =0x0000ffff
_0811F174:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F108

	thumb_func_start InitEasyChatPhrases
InitEasyChatPhrases: @ 811F184
	push {r4-r7,lr}
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bb0
	ldr r3, =gUnknown_0859E62C
_0811F18E:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x3
	bls _0811F18E
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bbc
	ldr r3, =gUnknown_0859E634
_0811F1AE:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0811F1AE
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bc8
	ldr r3, =gUnknown_0859E640
_0811F1CE:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0811F1CE
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bd4
	ldr r3, =gUnknown_0859E64C
_0811F1EE:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0811F1EE
	movs r2, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r6, =0x00002be0
	ldr r0, =0x0000ffff
	adds r5, r0, 0
_0811F210:
	movs r3, 0
	lsls r0, r2, 3
	adds r0, r2
	lsls r4, r0, 2
_0811F218:
	ldr r1, [r7]
	lsls r0, r3, 1
	adds r0, r4
	adds r1, r6
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _0811F218
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _0811F210
	movs r2, 0
	ldr r4, =gSaveBlock1Ptr
	ldr r3, =0x00002e20
	movs r1, 0
_0811F244:
	ldr r0, [r4]
	adds r0, r3
	adds r0, r2
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x3F
	bls _0811F244
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitEasyChatPhrases

	thumb_func_start sub_811F28C
sub_811F28C: @ 811F28C
	push {r4,lr}
	ldr r4, =gUnknown_0203A120
	ldr r0, =0x00003ba4
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _0811F2B0
	bl sub_811F2D4
	bl sub_811F46C
	movs r0, 0x1
	b _0811F2B2
	.pool
_0811F2B0:
	movs r0, 0
_0811F2B2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811F28C

	thumb_func_start sub_811F2B8
sub_811F2B8: @ 811F2B8
	push {r4,lr}
	ldr r4, =gUnknown_0203A120
	ldr r0, [r4]
	cmp r0, 0
	beq _0811F2CA
	bl Free
	movs r0, 0
	str r0, [r4]
_0811F2CA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F2B8

	thumb_func_start sub_811F2D4
sub_811F2D4: @ 811F2D4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203A120
	ldr r0, [r4]
	movs r5, 0
	strh r5, [r0]
	movs r0, 0
	bl GetNationalPokedexCount
	lsls r0, 16
	cmp r0, 0
	beq _0811F2FC
	ldr r0, [r4]
	ldrh r1, [r0]
	adds r2, r1, 0x1
	strh r2, [r0]
	lsls r1, 16
	lsrs r1, 15
	adds r0, 0x2
	adds r0, r1
	strh r5, [r0]
_0811F2FC:
	movs r3, 0x1
_0811F2FE:
	ldr r0, [r4]
	ldrh r2, [r0]
	adds r1, r2, 0x1
	strh r1, [r0]
	lsls r2, 16
	lsrs r2, 15
	adds r0, 0x2
	adds r0, r2
	strh r3, [r0]
	adds r3, 0x1
	cmp r3, 0x10
	ble _0811F2FE
	ldr r0, =0x00000864 @ = FLAG_SYS_GAME_CLEAR
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0811F358
	ldr r0, =gUnknown_0203A120
	ldr r2, [r0]
	ldrh r0, [r2]
	adds r1, r0, 0x1
	strh r1, [r2]
	lsls r0, 16
	lsrs r0, 15
	adds r3, r2, 0x2
	adds r0, r3, r0
	movs r1, 0x11
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, 0x1
	strh r1, [r2]
	lsls r0, 16
	lsrs r0, 15
	adds r0, r3, r0
	movs r1, 0x12
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, 0x1
	strh r1, [r2]
	lsls r0, 16
	lsrs r0, 15
	adds r3, r0
	movs r0, 0x13
	strh r0, [r3]
_0811F358:
	ldr r0, =0x00000866
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0811F37A
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, 0x1
	strh r2, [r0]
	lsls r1, 16
	lsrs r1, 15
	adds r0, 0x2
	adds r0, r1
	movs r1, 0x14
	strh r1, [r0]
_0811F37A:
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _0811F398
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, 0x1
	strh r2, [r0]
	lsls r1, 16
	lsrs r1, 15
	adds r0, 0x2
	adds r0, r1
	movs r1, 0x15
	strh r1, [r0]
_0811F398:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F2D4

	thumb_func_start sub_811F3AC
sub_811F3AC: @ 811F3AC
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811F3AC

	thumb_func_start sub_811F3B8
sub_811F3B8: @ 811F3B8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r2, r0
	bcs _0811F3D8
	lsls r0, r2, 1
	adds r1, 0x2
	adds r1, r0
	ldrb r0, [r1]
	b _0811F3DA
	.pool
_0811F3D8:
	movs r0, 0x16
_0811F3DA:
	pop {r1}
	bx r1
	thumb_func_end sub_811F3B8

	thumb_func_start sub_811F3E0
sub_811F3E0: @ 811F3E0
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsls r2, 16
	lsrs r5, r2, 16
	ldr r0, =gEasyChatGroupNamePointers
	lsrs r1, 22
	adds r1, r0
	ldr r1, [r1]
	adds r0, r4, 0
	bl StringCopy
	adds r1, r0, 0
	subs r4, r1, r4
	lsls r4, 16
	lsrs r0, r4, 16
	cmp r0, r5
	bcs _0811F414
	movs r2, 0
_0811F406:
	strb r2, [r1]
	adds r1, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _0811F406
_0811F414:
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F3E0

	thumb_func_start sub_811F424
sub_811F424: @ 811F424
	lsls r0, 24
	ldr r1, =gEasyChatGroupNamePointers
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811F424

	thumb_func_start CopyEasyChatWordPadded
@ char *CopyEasyChatWordPadded(char *dest, u16 groupIdWordIdPair, u16 minLength)
CopyEasyChatWordPadded: @ 811F434
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	bl CopyEasyChatWord
	adds r1, r0, 0
	subs r4, r1, r4
	lsls r4, 16
	lsrs r0, r4, 16
	cmp r0, r5
	bcs _0811F460
	movs r2, 0
_0811F452:
	strb r2, [r1]
	adds r1, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _0811F452
_0811F460:
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWordPadded

	thumb_func_start sub_811F46C
sub_811F46C: @ 811F46C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	movs r3, 0
_0811F47A:
	ldr r2, =gEasyChatWordsByLetterPointers
	lsls r1, r3, 3
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp]
	adds r1, r2
	ldr r7, [r1]
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	lsls r2, r3, 1
	adds r1, 0x2E
	adds r1, r2
	movs r0, 0
	strh r0, [r1]
	mov r10, r0
	movs r1, 0
	str r2, [sp, 0x4]
	adds r0, r3, 0x1
	str r0, [sp, 0x8]
	ldr r2, [sp]
	cmp r1, r2
	bge _0811F530
_0811F4A8:
	ldrh r0, [r7]
	ldr r2, =0x0000ffff
	cmp r0, r2
	bne _0811F4FC
	adds r7, 0x2
	ldrh r4, [r7]
	adds r7, 0x2
	adds r0, r1, 0x1
	adds r1, r0, r4
	b _0811F4FE
	.pool
_0811F4C8:
	ldr r0, =gUnknown_0203A120
	ldr r2, [r0]
	mov r0, r10
	lsls r1, r0, 1
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 3
	subs r0, r3
	lsls r0, 2
	adds r1, r0
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r1
	ldrh r1, [r5]
	strh r1, [r0]
	movs r0, 0x1
	add r10, r0
	adds r2, 0x2E
	ldr r0, [sp, 0x4]
	adds r2, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _0811F526
	.pool
_0811F4FC:
	movs r4, 0x1
_0811F4FE:
	movs r6, 0
	adds r1, 0x1
	mov r9, r1
	lsls r2, r4, 1
	mov r8, r2
	cmp r6, r4
	bge _0811F526
	adds r5, r7, 0
_0811F50E:
	ldrh r0, [r5]
	str r3, [sp, 0xC]
	bl sub_811F860
	lsls r0, 24
	ldr r3, [sp, 0xC]
	cmp r0, 0
	bne _0811F4C8
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, r4
	blt _0811F50E
_0811F526:
	add r7, r8
	mov r1, r9
	ldr r0, [sp]
	cmp r1, r0
	blt _0811F4A8
_0811F530:
	ldr r3, [sp, 0x8]
	cmp r3, 0x1A
	ble _0811F47A
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811F46C

	thumb_func_start sub_811F548
sub_811F548: @ 811F548
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	cmp r0, 0
	bne _0811F55A
	adds r0, r1, 0
	bl sub_811F5C4
	b _0811F560
_0811F55A:
	adds r0, r1, 0
	bl sub_811F6B8
_0811F560:
	ldr r1, =gUnknown_0203A120
	ldr r1, [r1]
	ldr r2, =0x00003ba0
	adds r1, r2
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F548

	thumb_func_start sub_811F578
sub_811F578: @ 811F578
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	ldr r3, =0x00003ba0
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bcs _0811F5A4
	lsls r0, r2, 1
	ldr r2, =0x00003984
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	b _0811F5A6
	.pool
_0811F5A4:
	ldr r0, =0x0000ffff
_0811F5A6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F578

	thumb_func_start sub_811F5B0
sub_811F5B0: @ 811F5B0
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldr r1, =0x00003ba0
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811F5B0

	thumb_func_start sub_811F5C4
sub_811F5C4: @ 811F5C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gEasyChatGroups
	lsls r0, r2, 3
	adds r0, r1
	ldrh r3, [r0, 0x4]
	mov r8, r3
	cmp r2, 0
	beq _0811F5EC
	cmp r2, 0x15
	beq _0811F5EC
	cmp r2, 0x12
	beq _0811F5EC
	cmp r2, 0x13
	bne _0811F64C
_0811F5EC:
	lsls r0, r2, 3
	adds r0, r1
	ldr r1, [r0]
	movs r7, 0
	movs r5, 0
	cmp r5, r8
	bcs _0811F698
	movs r0, 0x7F
	ands r0, r2
	lsls r0, 9
	mov r9, r0
	adds r4, r1, 0
	lsls r6, r2, 24
_0811F606:
	ldrh r0, [r4]
	lsrs r1, r6, 24
	bl sub_811F764
	lsls r0, 24
	cmp r0, 0
	beq _0811F630
	ldr r0, =gUnknown_0203A120
	ldr r2, [r0]
	lsls r0, r5, 1
	ldr r1, =0x00003984
	adds r2, r1
	adds r2, r0
	ldrh r0, [r4]
	ldr r3, =0x000001ff
	adds r1, r3, 0
	ands r0, r1
	mov r1, r9
	orrs r0, r1
	strh r0, [r2]
	adds r5, 0x1
_0811F630:
	adds r4, 0x2
	adds r7, 0x1
	cmp r7, r8
	bcc _0811F606
	b _0811F698
	.pool
_0811F64C:
	ldr r1, [r0]
	movs r7, 0
	movs r5, 0
	cmp r5, r8
	bcs _0811F698
	movs r0, 0x7F
	ands r0, r2
	lsls r0, 9
	mov r10, r0
	adds r6, r1, 0
	lsls r2, 24
	mov r9, r2
_0811F664:
	ldrh r4, [r6, 0x4]
	adds r0, r4, 0
	mov r2, r9
	lsrs r1, r2, 24
	bl sub_811F764
	lsls r0, 24
	cmp r0, 0
	beq _0811F690
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	lsls r0, r5, 1
	ldr r3, =0x00003984
	adds r1, r3
	adds r1, r0
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r4, r0
	mov r3, r10
	orrs r4, r3
	strh r4, [r1]
	adds r5, 0x1
_0811F690:
	adds r6, 0xC
	adds r7, 0x1
	cmp r7, r8
	bcc _0811F664
_0811F698:
	lsls r0, r5, 16
	lsrs r0, 16
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F5C4

	thumb_func_start sub_811F6B8
sub_811F6B8: @ 811F6B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r4, 0
	movs r6, 0
	ldr r3, =gUnknown_0203A120
	ldr r0, [r3]
	lsls r5, r1, 1
	adds r0, 0x2E
	adds r0, r5
	ldrh r0, [r0]
	cmp r6, r0
	bcs _0811F718
	mov r8, r3
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r7, r0, 2
	ldr r0, =0x00003984
	mov r12, r0
_0811F6E6:
	mov r0, r8
	ldr r3, [r0]
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 1
	mov r0, r12
	adds r2, r3, r0
	adds r2, r1
	lsls r1, r4, 1
	adds r1, r7
	adds r0, r3, 0
	adds r0, 0x64
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r3, 0x2E
	adds r3, r5
	ldrh r3, [r3]
	cmp r4, r3
	bcc _0811F6E6
_0811F718:
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F6B8

	thumb_func_start sub_811F72C
sub_811F72C: @ 811F72C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrh r1, [r0]
	cmp r2, r1
	bge _0811F75C
	adds r4, r3, 0
	adds r3, r1, 0
	adds r1, r0, 0x2
_0811F744:
	ldrh r0, [r1]
	cmp r0, r4
	bne _0811F754
	movs r0, 0x1
	b _0811F75E
	.pool
_0811F754:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _0811F744
_0811F75C:
	movs r0, 0
_0811F75E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811F72C

	thumb_func_start sub_811F764
sub_811F764: @ 811F764
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r2, 0x15
	bhi _0811F81A
	lsls r0, r2, 2
	ldr r1, =_0811F780
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811F780:
	.4byte _0811F7D8
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F808
	.4byte _0811F808
	.4byte _0811F80C
	.4byte _0811F7EE
_0811F7D8:
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
	lsls r0, 24
	lsrs r0, 24
	b _0811F82C
_0811F7EE:
	adds r0, r4, 0
	bl sub_811F838
	cmp r0, 0
	beq _0811F808
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
_0811F808:
	movs r0, 0x1
	b _0811F82C
_0811F80C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_811EF98
	lsls r0, 24
	lsrs r0, 24
	b _0811F82C
_0811F81A:
	ldr r1, =gEasyChatGroups
	lsls r0, r2, 3
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
_0811F82C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F764

	thumb_func_start sub_811F838
sub_811F838: @ 811F838
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r1, =gUnknown_0859E658
_0811F842:
	ldrh r0, [r1]
	cmp r0, r3
	bne _0811F850
	movs r0, 0x1
	b _0811F85A
	.pool
_0811F850:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0
	beq _0811F842
	movs r0, 0
_0811F85A:
	pop {r1}
	bx r1
	thumb_func_end sub_811F838

	thumb_func_start sub_811F860
sub_811F860: @ 811F860
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 25
	lsls r0, 7
	lsrs r4, r0, 23
	adds r0, r5, 0
	bl sub_811F72C
	lsls r0, 24
	cmp r0, 0
	beq _0811F884
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_811F764
	lsls r0, 24
	lsrs r0, 24
	b _0811F886
_0811F884:
	movs r0, 0
_0811F886:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811F860

	thumb_func_start InitializeEasyChatWordArray
InitializeEasyChatWordArray: @ 811F88C
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldr r0, =0xffff0000
	adds r1, r0
	lsrs r0, r1, 16
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0811F8AE
	adds r3, r1, 0
_0811F8A0:
	strh r3, [r2]
	adds r2, 0x2
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bne _0811F8A0
_0811F8AE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitializeEasyChatWordArray

@void sub_811F8BC() {
@	s16* v;
@	s16* ptr;
@	v = GetSaveBlock1Field3564();
@	for (ptr = v + 3; ptr >= v; ptr--) {
@		*ptr = -1;
@	}
@}
	thumb_func_start sub_811F8BC
sub_811F8BC: @ 811F8BC
	push {lr}
	bl GetSaveBlock1Field3564
	ldr r1, =0x0000ffff
	adds r2, r1, 0
	adds r1, r0, 0x6
_0811F8C8:
	strh r2, [r1]
	subs r1, 0x2
	cmp r1, r0
	bge _0811F8C8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F8BC

	thumb_func_start sub_811F8D8
sub_811F8D8: @ 811F8D8
	push {r4,r5,lr}
	asrs r4, r0, 9
	movs r1, 0x7F
	ldr r5, =0x000001ff
	ands r5, r0
	ands r4, r1
	adds r0, r4, 0
	bl sub_811EA28
	lsls r0, 24
	cmp r0, 0
	beq _0811F904
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_811F764
	lsls r0, 24
	lsrs r0, 24
	b _0811F906
	.pool
_0811F904:
	movs r0, 0
_0811F906:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811F8D8

	.align 2, 0 @ Don't pad with nop.
