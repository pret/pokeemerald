	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80F97C8
sub_80F97C8: @ 80F97C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	movs r1, 0
	bl GetMonData
	lsls r0, 16
	str r0, [sp, 0x4]
	lsrs r0, 16
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x27
	bl GetMonData
	adds r7, r0, 0
	movs r6, 0xF
	ands r7, r6
	adds r0, r5, 0
	movs r1, 0x28
	bl GetMonData
	mov r8, r0
	mov r1, r8
	ands r1, r6
	mov r8, r1
	adds r0, r5, 0
	movs r1, 0x29
	bl GetMonData
	mov r9, r0
	mov r3, r9
	ands r3, r6
	mov r9, r3
	adds r0, r5, 0
	movs r1, 0x2A
	bl GetMonData
	mov r10, r0
	ands r0, r6
	mov r10, r0
	adds r0, r5, 0
	movs r1, 0x2B
	bl GetMonData
	adds r4, r0, 0
	ands r4, r6
	adds r0, r5, 0
	movs r1, 0x2C
	bl GetMonData
	adds r2, r0, 0
	ands r2, r6
	mov r1, r8
	mov r3, r9
	eors r1, r3
	mov r8, r1
	mov r0, r8
	muls r0, r7
	movs r1, 0xFF
	ldr r3, [sp]
	ands r3, r1
	eors r0, r3
	eors r4, r2
	mov r1, r10
	muls r1, r4
	ldr r3, [sp, 0x4]
	lsrs r2, r3, 24
	eors r1, r2
	lsls r0, 8
	adds r0, r1
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80F97C8

	thumb_func_start sub_80F986C
sub_80F986C: @ 80F986C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x1
	ldr r3, =gUnknown_0858D8F0
_080F9876:
	lsls r0, r1, 3
	adds r0, r3
	ldrh r0, [r0, 0x4]
	cmp r2, r0
	bcs _080F988C
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	b _080F9898
	.pool
_080F988C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xE
	bls _080F9876
	adds r0, r1, 0
_080F9898:
	pop {r1}
	bx r1
	thumb_func_end sub_80F986C

	thumb_func_start sub_80F989C
sub_80F989C: @ 80F989C
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r6, 16
	lsrs r6, 16
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_80C0630
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r6, 0
	bl sub_80F986C
	lsls r0, 24
	ldr r1, =gUnknown_0858D8F0
	lsrs r0, 21
	adds r0, r1
	ldrh r1, [r0]
	str r1, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	ldrb r2, [r0, 0x2]
	movs r3, 0
	ldrh r4, [r0, 0x4]
	movs r5, 0
	adds r0, r6, 0
	movs r1, 0
	subs r0, r4
	sbcs r1, r5
	bl __udivdi3
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	adds r2, r0
	adcs r3, r1
	str r2, [sp]
	str r3, [sp, 0x4]
	adds r0, r7, 0
	movs r1, 0
	bl __muldi3
	movs r2, 0xA
	movs r3, 0
	bl __udivdi3
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F989C

	thumb_func_start sub_80F9910
sub_80F9910: @ 80F9910
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 1
	adds r0, r4, 0
	bl __floatsidf
	cmp r4, 0
	bge _080F992C
	ldr r3, _080F9974
	ldr r2, _080F9970
	bl __adddf3
_080F992C:
	ldr r2, _080F9978
	ldr r3, _080F997C
	bl __divdf3
	bl __fixunsdfsi
	adds r4, r0, 0
	movs r1, 0xA
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x8
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	ldr r1, _080F9980
	bl StringAppend
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F9970: .4byte 0x41f00000
_080F9974: .4byte 0x00000000
_080F9978: .4byte 0x40396666
_080F997C: .4byte 0x66666666
_080F9980: .4byte gUnknown_085EED24
	thumb_func_end sub_80F9910

	thumb_func_start sub_80F9984
sub_80F9984: @ 80F9984
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r1, 0
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, =gScriptResult
	ldrh r0, [r1]
	cmp r0, 0xFF
	bne _080F99A0
	movs r0, 0
	b _080F9A0A
	.pool
_080F99A0:
	ldrh r1, [r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0x1
	beq _080F99C2
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, r6
	beq _080F99CC
_080F99C2:
	movs r0, 0x1
	b _080F9A0A
	.pool
_080F99CC:
	mov r4, sp
	adds r0, r5, 0
	bl sub_80F97C8
	strh r0, [r4]
	mov r0, sp
	ldrh r1, [r0]
	adds r0, r6, 0
	bl sub_80F989C
	adds r5, r0, 0
	ldrh r1, [r7]
	adds r0, r6, 0
	bl sub_80F989C
	adds r4, r0, 0
	ldr r0, =gStringVar2
	adds r1, r5, 0
	bl sub_80F9910
	cmp r5, r4
	bls _080F9A08
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r7]
	movs r0, 0x3
	b _080F9A0A
	.pool
_080F9A08:
	movs r0, 0x2
_080F9A0A:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80F9984

	thumb_func_start sub_80F9A14
sub_80F9A14: @ 80F9A14
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	ldrh r1, [r5]
	adds r0, r4, 0
	bl sub_80F989C
	adds r1, r0, 0
	ldr r0, =gStringVar3
	bl sub_80F9910
	ldr r0, =gStringVar1
	movs r1, 0xB
	muls r1, r4
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 8
	cmp r1, r0
	bne _080F9A64
	ldr r0, =gStringVar2
	ldr r1, =gUnknown_085ECF6B
	bl StringCopy
	b _080F9A6E
	.pool
_080F9A64:
	ldr r0, =gStringVar2
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
_080F9A6E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9A14

	thumb_func_start InitSeedotSizeRecord
InitSeedotSizeRecord: @ 80F9A7C
	push {lr}
	ldr r0, =0x00004047
	movs r1, 0x80
	lsls r1, 8
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitSeedotSizeRecord

	thumb_func_start sub_80F9A90
sub_80F9A90: @ 80F9A90
	push {lr}
	ldr r0, =0x00004047
	bl GetVarPointer
	adds r1, r0, 0
	movs r0, 0x95
	lsls r0, 1
	bl sub_80F9A14
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9A90

	thumb_func_start sub_80F9AAC
sub_80F9AAC: @ 80F9AAC
	push {r4,lr}
	ldr r0, =0x00004047
	bl GetVarPointer
	adds r1, r0, 0
	ldr r4, =gScriptResult
	movs r0, 0x95
	lsls r0, 1
	bl sub_80F9984
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9AAC

	thumb_func_start InitLotadSizeRecord
InitLotadSizeRecord: @ 80F9AD4
	push {lr}
	ldr r0, =0x0000404f
	movs r1, 0x80
	lsls r1, 8
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitLotadSizeRecord

	thumb_func_start sub_80F9AE8
sub_80F9AE8: @ 80F9AE8
	push {lr}
	ldr r0, =0x0000404f
	bl GetVarPointer
	adds r1, r0, 0
	ldr r0, =0x00000127
	bl sub_80F9A14
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9AE8

	thumb_func_start sub_80F9B04
sub_80F9B04: @ 80F9B04
	push {r4,lr}
	ldr r0, =0x0000404f
	bl GetVarPointer
	adds r1, r0, 0
	ldr r4, =gScriptResult
	ldr r0, =0x00000127
	bl sub_80F9984
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9B04

	thumb_func_start sub_80F9B30
sub_80F9B30: @ 80F9B30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r7, 0
	add r4, sp, 0x8
	movs r0, 0x1
	strb r0, [r4]
	ldr r1, =gUnknown_0858D970
	mov r0, sp
	movs r2, 0x7
	bl memcpy
	mov r8, r4
	cmp r6, 0xA
	bhi _080F9BAC
	cmp r5, 0x40
	bhi _080F9BAC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031a8
	adds r0, r1
	adds r0, r6
	strb r5, [r0]
	movs r5, 0
_080F9B6A:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _080F9B9C
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _080F9B9C
	mov r1, sp
	adds r0, r1, r6
	ldrb r1, [r0]
	adds r0, r4, 0
	mov r2, r8
	bl SetMonData
	movs r7, 0x1
_080F9B9C:
	adds r5, 0x1
	cmp r5, 0x5
	ble _080F9B6A
	cmp r7, 0
	beq _080F9BAC
	ldr r0, =0x0000089b
	bl FlagSet
_080F9BAC:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9B30

	.align 2, 0 @ Don't pad with nop.
