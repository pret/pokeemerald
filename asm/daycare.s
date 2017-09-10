	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start pokemon_get_nick
pokemon_get_nick: @ 806FA2C
	push {r4,lr}
	sub sp, 0x14
	adds r4, r1, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	adds r0, r4, 0
	mov r1, sp
	bl StringCopy10
	add sp, 0x14
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end pokemon_get_nick

	thumb_func_start pokemon_get_nick_
pokemon_get_nick_: @ 806FA4C
	push {r4,lr}
	sub sp, 0x14
	adds r4, r1, 0
	movs r1, 0x2
	mov r2, sp
	bl GetBoxMonData
	adds r0, r4, 0
	mov r1, sp
	bl StringCopy10
	add sp, 0x14
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end pokemon_get_nick_

	thumb_func_start daycare_count_pokemon
daycare_count_pokemon: @ 806FA6C
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	movs r4, 0
_0806FA74:
	movs r0, 0x8C
	muls r0, r4
	adds r0, r6, r0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _0806FA8A
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0806FA8A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0806FA74
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end daycare_count_pokemon

	thumb_func_start sub_806FA9C
sub_806FA9C: @ 806FA9C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	mov r10, r1
	movs r7, 0
	movs r5, 0
	mov r6, r10
	adds r6, 0x74
	movs r0, 0x1
	mov r8, r0
_0806FAB6:
	movs r0, 0x8C
	muls r0, r5
	mov r1, r9
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _0806FAE4
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	movs r1, 0xC
	bl GetBoxMonData
	adds r1, r0, 0
	cmp r1, 0
	bne _0806FAE4
	lsls r0, r5, 1
	adds r0, r6, r0
	b _0806FAEA
_0806FAE4:
	lsls r0, r5, 1
	adds r0, r6, r0
	mov r1, r8
_0806FAEA:
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _0806FAB6
	mov r0, r10
	str r7, [r0, 0x70]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806FA9C

	thumb_func_start daycare_empty_slot
@ u8 daycare_empty_slot(struct daycare_mon *dayCareMons)
daycare_empty_slot: @ 806FB08
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
_0806FB0E:
	movs r0, 0x8C
	muls r0, r4
	adds r0, r5, r0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	bne _0806FB24
	lsls r0, r4, 24
	asrs r0, 24
	b _0806FB32
_0806FB24:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0806FB0E
	movs r0, 0x1
	negs r0, r0
_0806FB32:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end daycare_empty_slot

	thumb_func_start sub_806FB38
@ void sub_806FB38(struct pokemon *mon, struct daycare_mon *dayCareMon)
sub_806FB38: @ 806FB38
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_80D43F0
	lsls r0, 24
	cmp r0, 0
	beq _0806FBBC
	adds r0, r5, 0
	adds r0, 0x74
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r4, r5, 0
	adds r4, 0x7C
	adds r0, r6, 0
	adds r1, r4, 0
	bl pokemon_get_nick
	adds r0, r4, 0
	bl StripExtCtrlCodes
	adds r4, 0xB
	ldrb r1, [r4]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	adds r0, r6, 0
	movs r1, 0x3
	bl GetMonData
	lsls r0, 4
	ldrb r2, [r4]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r4]
	adds r0, r6, 0
	movs r1, 0x40
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x50
	ldr r2, =0x00002be0
	adds r1, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	adds r0, r6, 0
	bl sub_80D4680
_0806FBBC:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x50
	bl memcpy
	adds r0, r5, 0
	bl BoxMonRestorePP
	adds r1, r5, 0
	adds r1, 0x88
	movs r0, 0
	str r0, [r1]
	adds r0, r6, 0
	bl ZeroMonData
	bl party_compaction
	bl CalculatePlayerPartyCount
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806FB38

	thumb_func_start daycare_send
@ void daycare_send(struct pokemon *mon, struct daycare_mon *dayCareMons)
daycare_send: @ 806FBF4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl daycare_empty_slot
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x8C
	muls r0, r1
	adds r4, r0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806FB38
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end daycare_send

	thumb_func_start daycare_send_selected_pokemon
daycare_send_selected_pokemon: @ 806FC18
	push {lr}
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x00003030
	adds r1, r2
	bl daycare_send
	pop {r0}
	bx r0
	.pool
	thumb_func_end daycare_send_selected_pokemon

	thumb_func_start sub_806FC48
sub_806FC48: @ 806FC48
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x8C
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _0806FC9E
	adds r0, r5, 0
	movs r1, 0xB
	bl GetBoxMonData
	adds r6, r0, 0
	cmp r6, 0
	bne _0806FC9E
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x50
	bl memcpy
	adds r0, r4, 0
	bl ZeroBoxMonData
	adds r4, 0x50
	adds r0, r5, 0
	adds r0, 0x50
	adds r1, r4, 0
	movs r2, 0x38
	bl memcpy
	adds r2, r5, 0
	adds r2, 0x88
	movs r0, 0x8A
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, [r1]
	str r0, [r2]
	str r6, [r1]
	adds r0, r4, 0
	bl sub_806FF80
_0806FC9E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806FC48

	thumb_func_start sub_806FCA4
sub_806FCA4: @ 806FCA4
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
	ldr r7, =0x0000ffff
_0806FCAC:
	adds r0, r4, 0
	bl TryIncrementMonLevel
	lsls r0, 24
	cmp r0, 0
	beq _0806FCE8
	movs r6, 0x1
	adds r5, 0x1
	b _0806FCD4
	.pool
_0806FCC4:
	movs r6, 0
	cmp r0, r7
	bne _0806FCD4
	ldr r0, =gMoveToLearn
	ldrh r1, [r0]
	adds r0, r4, 0
	bl DeleteFirstMoveAndGiveMoveToMon
_0806FCD4:
	adds r0, r4, 0
	adds r1, r6, 0
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _0806FCC4
	cmp r5, 0x63
	ble _0806FCAC
_0806FCE8:
	adds r0, r4, 0
	bl CalculateMonStats
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806FCA4

	thumb_func_start sub_806FCF8
sub_806FCF8: @ 806FCF8
	push {r4-r7,lr}
	sub sp, 0x68
	adds r5, r0, 0
	ldr r1, =gStringVar1
	bl pokemon_get_nick_
	adds r0, r5, 0
	movs r1, 0xB
	bl GetBoxMonData
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r5, 0
	mov r1, sp
	bl sub_8069004
	mov r0, sp
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x64
	beq _0806FD46
	mov r0, sp
	movs r1, 0x19
	bl GetMonData
	adds r1, r5, 0
	adds r1, 0x88
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x64]
	add r2, sp, 0x64
	mov r0, sp
	movs r1, 0x19
	bl SetMonData
	mov r0, sp
	bl sub_806FCA4
_0806FD46:
	ldr r0, =gPlayerParty
	movs r1, 0xFA
	lsls r1, 1
	adds r6, r0, r1
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x64
	bl memcpy
	adds r0, r5, 0
	adds r0, 0x70
	ldrh r0, [r0]
	cmp r0, 0
	beq _0806FD74
	adds r4, r5, 0
	adds r4, 0x50
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80D460C
	adds r0, r4, 0
	bl sub_806FF80
_0806FD74:
	adds r0, r5, 0
	bl ZeroBoxMonData
	adds r1, r5, 0
	adds r1, 0x88
	movs r0, 0
	str r0, [r1]
	bl party_compaction
	bl CalculatePlayerPartyCount
	adds r0, r7, 0
	add sp, 0x68
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806FCF8

	thumb_func_start sub_806FD9C
sub_806FD9C: @ 806FD9C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x8C
	muls r0, r1
	adds r0, r5, r0
	bl sub_806FCF8
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl sub_806FC48
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806FD9C

	thumb_func_start sub_806FDC4
sub_806FDC4: @ 806FDC4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	ldr r1, =gSpecialVar_0x8004
	ldrb r1, [r1]
	bl sub_806FD9C
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806FDC4

	thumb_func_start sub_806FDEC
sub_806FDEC: @ 806FDEC
	push {r4,r5,lr}
	sub sp, 0x54
	adds r4, r0, 0
	adds r5, r1, 0
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x50
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x19
	bl GetBoxMonData
	adds r0, r5
	str r0, [sp, 0x50]
	add r2, sp, 0x50
	mov r0, sp
	movs r1, 0x19
	bl SetBoxMonData
	mov r0, sp
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x54
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806FDEC

	thumb_func_start sub_806FE28
sub_806FE28: @ 806FE28
	push {r4,r5,lr}
	adds r5, r0, 0
	bl GetLevelFromBoxMonExp
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r0, 0x88
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_806FDEC
	lsls r0, 24
	lsrs r0, 24
	subs r0, r4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806FE28

	thumb_func_start sub_806FE54
sub_806FE54: @ 806FE54
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_806FE28
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gStringVar2
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl pokemon_get_nick_
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806FE54

	thumb_func_start sub_806FE88
sub_806FE88: @ 806FE88
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_806FE28
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl pokemon_get_nick_
	movs r0, 0x64
	muls r4, r0
	adds r4, 0x64
	ldr r0, =gStringVar2
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806FE88

	thumb_func_start sub_806FEC0
sub_806FEC0: @ 806FEC0
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0x8C
	muls r1, r2
	adds r0, r1
	bl sub_806FE88
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_806FEC0

	thumb_func_start sub_806FED8
sub_806FED8: @ 806FED8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	ldr r1, =gSpecialVar_0x8004
	ldrb r1, [r1]
	bl sub_806FEC0
	ldr r1, =gSpecialVar_0x8005
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806FED8

	thumb_func_start sub_806FF04
sub_806FF04: @ 806FF04
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldr r1, =0x000030b8
	adds r3, r2, r1
	ldr r1, [r3]
	adds r1, r0
	str r1, [r3]
	ldr r1, =0x00003144
	adds r2, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_806FF04

	thumb_func_start sub_806FF30
sub_806FF30: @ 806FF30
	push {r4-r6,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r5, =gSpecialVar_0x8004
	ldrh r0, [r5]
	movs r4, 0x8C
	adds r1, r0, 0
	muls r1, r4
	ldr r0, =0x00003030
	adds r1, r0
	ldr r0, [r6]
	adds r0, r1
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	bne _0806FF60
	movs r0, 0
	b _0806FF76
	.pool
_0806FF60:
	ldrh r0, [r5]
	adds r1, r0, 0
	muls r1, r4
	ldr r0, =0x00003030
	adds r1, r0
	ldr r0, [r6]
	adds r0, r1
	bl sub_806FE54
	lsls r0, 24
	lsrs r0, 24
_0806FF76:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806FF30

	thumb_func_start sub_806FF80
sub_806FF80: @ 806FF80
	push {lr}
	movs r3, 0
	movs r2, 0x7
	adds r1, r0, 0
	adds r1, 0x2B
_0806FF8A:
	strb r3, [r1]
	subs r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _0806FF8A
	adds r2, r0, 0
	adds r2, 0x2C
	movs r3, 0
	adds r1, r0, 0
	adds r1, 0x36
_0806FF9E:
	strb r3, [r1]
	subs r1, 0x1
	cmp r1, r2
	bge _0806FF9E
	bl sub_80D439C
	pop {r0}
	bx r0
	thumb_func_end sub_806FF80

	thumb_func_start sub_806FFB0
sub_806FFB0: @ 806FFB0
	push {r4,lr}
	adds r4, r0, 0
	bl ZeroBoxMonData
	adds r1, r4, 0
	adds r1, 0x88
	movs r0, 0
	str r0, [r1]
	adds r4, 0x50
	adds r0, r4, 0
	bl sub_806FF80
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806FFB0

	thumb_func_start sub_806FFD0
sub_806FFD0: @ 806FFD0
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	movs r6, 0x8C
_0806FFD8:
	adds r0, r4, 0
	muls r0, r6
	adds r0, r5, r0
	bl sub_806FFB0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0806FFD8
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806FFD0

	thumb_func_start sub_8070004
sub_8070004: @ 8070004
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0
	mov r8, r0
	ldr r0, =gEvolutionTable
	mov r12, r0
_08070016:
	movs r7, 0
	movs r6, 0x1
	movs r4, 0x80
	lsls r4, 9
	movs r5, 0x28
	mov r3, r12
	adds r3, 0x28
_08070024:
	movs r1, 0
	ldrh r0, [r3, 0x4]
	cmp r0, r2
	bne _08070034
	lsrs r2, r4, 16
	b _08070060
	.pool
_08070034:
	adds r1, 0x1
	cmp r1, 0x4
	bgt _0807004A
	lsls r0, r1, 3
	adds r0, r5
	add r0, r12
	ldrh r0, [r0, 0x4]
	cmp r0, r2
	bne _08070034
	lsrs r2, r4, 16
	movs r7, 0x1
_0807004A:
	cmp r7, 0
	bne _08070060
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r5, 0x28
	adds r3, 0x28
	adds r6, 0x1
	ldr r0, =0x0000019b
	cmp r6, r0
	ble _08070024
_08070060:
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	beq _08070072
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x4
	ble _08070016
_08070072:
	adds r0, r2, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8070004

	thumb_func_start sub_8070084
sub_8070084: @ 8070084
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r7, 0x1
	negs r7, r7
	movs r4, 0
_08070090:
	movs r0, 0x8C
	muls r0, r4
	adds r0, r6, r0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFE
	bne _080700A4
	adds r7, r4, 0
_080700A4:
	adds r4, 0x1
	cmp r4, 0x1
	ble _08070090
	movs r5, 0
	movs r4, 0
_080700AE:
	movs r0, 0x8C
	muls r0, r4
	adds r0, r6, r0
	movs r1, 0xB
	bl GetBoxMonData
	lsls r1, r4, 2
	add r1, sp
	str r0, [r1]
	cmp r0, 0x84
	bne _080700C8
	adds r5, 0x1
	adds r7, r4, 0
_080700C8:
	adds r4, 0x1
	cmp r4, 0x1
	ble _080700AE
	cmp r5, 0x2
	bne _080700E2
	bl Random
	lsls r0, 16
	ldr r1, =0x7ffe0000
	movs r7, 0x1
	cmp r0, r1
	bls _080700E2
	movs r7, 0
_080700E2:
	movs r0, 0x8C
	muls r0, r7
	adds r0, r6, r0
	movs r1, 0xC
	bl GetBoxMonData
	cmp r0, 0xC3
	bne _080700FE
	bl Random
	lsls r0, 16
	ldr r1, =0x7ffe0000
	cmp r0, r1
	bls _08070108
_080700FE:
	movs r0, 0x1
	negs r0, r0
	b _0807010A
	.pool
_08070108:
	adds r0, r7, 0
_0807010A:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8070084

	thumb_func_start sub_8070114
sub_8070114: @ 8070114
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r6, 0
	ldr r0, =gMain
	ldrh r0, [r0, 0x24]
	bl SeedRng2
	adds r0, r5, 0
	bl sub_8070084
	adds r1, r0, 0
	cmp r1, 0
	bge _08070160
	bl Random2
	adds r4, r0, 0
	bl Random
	movs r1, 0x8C
	lsls r1, 1
	adds r5, r1
	lsls r4, 16
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000fffe
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, 0x1
	orrs r4, r0
	str r4, [r5]
	b _080701AC
	.pool
_08070160:
	movs r0, 0x8C
	muls r0, r1
	adds r0, r5, r0
	movs r1, 0
	movs r2, 0
	bl GetBoxMonData
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r7, r0, 24
_08070176:
	bl Random2
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsls r0, 16
	lsrs r0, 16
	orrs r4, r0
	adds r0, r4, 0
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r7, r0
	bne _0807019A
	cmp r4, 0
	bne _080701A4
_0807019A:
	adds r6, 0x1
	movs r0, 0x96
	lsls r0, 4
	cmp r6, r0
	ble _08070176
_080701A4:
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r5, r1
	str r4, [r0]
_080701AC:
	movs r0, 0x86
	bl FlagSet
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8070114

	thumb_func_start sub_80701B8
sub_80701B8: @ 80701B8
	push {r4,lr}
	adds r4, r0, 0
	bl Random
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r1
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	orrs r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [r4]
	movs r0, 0x86
	bl FlagSet
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80701B8

	thumb_func_start sub_80701E0
sub_80701E0: @ 80701E0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_8070114
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80701E0

	thumb_func_start sub_80701FC
sub_80701FC: @ 80701FC
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_80701B8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80701FC

	thumb_func_start sub_8070218
sub_8070218: @ 8070218
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r1, r4, r1
	movs r0, 0xFF
	strb r0, [r1]
	movs r2, 0
_0807022A:
	mov r1, sp
	adds r0, r1, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x5
	ble _0807022A
	movs r3, 0
	movs r2, 0
_0807023E:
	mov r1, sp
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r0, r1, 0
	cmp r0, 0xFF
	beq _08070250
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, 0x1
_08070250:
	adds r2, 0x1
	cmp r2, 0x5
	ble _0807023E
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8070218

	thumb_func_start sub_8070260
sub_8070260: @ 8070260
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r9, r0
	mov r8, r1
	movs r5, 0
	add r1, sp, 0x4
	add r7, sp, 0xC
	adds r2, r1, 0
_08070276:
	adds r0, r2, r5
	strb r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08070276
	movs r5, 0
	adds r6, r1, 0
_08070288:
	bl Random
	mov r1, sp
	adds r4, r1, r5
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	subs r1, r5
	bl __modsi3
	adds r0, r6, r0
	ldrb r0, [r0]
	strb r0, [r4]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8070218
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _08070288
	movs r5, 0
	movs r4, 0x1
_080702B8:
	bl Random
	adds r1, r7, r5
	lsls r0, 16
	lsrs r0, 16
	ands r0, r4
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _080702B8
	movs r5, 0
_080702D2:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _080703AE
	lsls r0, 2
	ldr r1, =_080702EC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080702EC:
	.4byte _08070304
	.4byte _08070322
	.4byte _0807033C
	.4byte _08070356
	.4byte _08070370
	.4byte _08070390
_08070304:
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, 0x8C
	muls r0, r1
	add r0, r8
	movs r1, 0x27
	bl GetBoxMonData
	add r2, sp, 0x10
	strb r0, [r2]
	mov r0, r9
	movs r1, 0x27
	bl SetMonData
	b _080703AE
_08070322:
	add r4, sp, 0x10
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, 0x8C
	muls r0, r1
	add r0, r8
	movs r1, 0x28
	bl GetBoxMonData
	strb r0, [r4]
	mov r0, r9
	movs r1, 0x28
	b _08070388
_0807033C:
	add r4, sp, 0x10
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, 0x8C
	muls r0, r1
	add r0, r8
	movs r1, 0x29
	bl GetBoxMonData
	strb r0, [r4]
	mov r0, r9
	movs r1, 0x29
	b _08070388
_08070356:
	add r4, sp, 0x10
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, 0x8C
	muls r0, r1
	add r0, r8
	movs r1, 0x2A
	bl GetBoxMonData
	strb r0, [r4]
	mov r0, r9
	movs r1, 0x2A
	b _08070388
_08070370:
	add r4, sp, 0x10
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, 0x8C
	muls r0, r1
	add r0, r8
	movs r1, 0x2B
	bl GetBoxMonData
	strb r0, [r4]
	mov r0, r9
	movs r1, 0x2B
_08070388:
	adds r2, r4, 0
	bl SetMonData
	b _080703AE
_08070390:
	add r4, sp, 0x10
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, 0x8C
	muls r0, r1
	add r0, r8
	movs r1, 0x2C
	bl GetBoxMonData
	strb r0, [r4]
	mov r0, r9
	movs r1, 0x2C
	adds r2, r4, 0
	bl SetMonData
_080703AE:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _080702D2
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8070260

	thumb_func_start pokemon_get_eggmoves
pokemon_get_eggmoves: @ 80703C8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	movs r6, 0
	movs r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r5, =gEggMoves
	ldrh r1, [r5]
	ldr r7, =0x00004e20
	adds r0, r3, r7
	cmp r1, r0
	bne _080703F8
	movs r4, 0x1
	b _0807041A
	.pool
_080703F8:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x00000471
	ldr r5, =gEggMoves
	cmp r2, r0
	bhi _0807041A
	lsls r0, r2, 1
	adds r0, r5
	ldrh r1, [r0]
	ldr r7, =0x00004e20
	adds r0, r3, r7
	cmp r1, r0
	bne _080703F8
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_0807041A:
	movs r2, 0
	lsls r0, r4, 1
	adds r0, r5
	ldrh r0, [r0]
	ldr r1, =0x00004e20
	cmp r0, r1
	bhi _08070456
	adds r7, r5, 0
	adds r3, r1, 0
_0807042C:
	lsls r1, r2, 1
	add r1, r8
	adds r0, r4, r2
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9
	bhi _08070456
	adds r0, r4, r2
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	cmp r0, r3
	bls _0807042C
_08070456:
	lsls r0, r6, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pokemon_get_eggmoves

	thumb_func_start daycare_build_child_moveset
daycare_build_child_moveset: @ 8070470
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r7, r0, 0
	mov r10, r1
	mov r9, r2
	movs r0, 0
	str r0, [sp]
	movs r6, 0
	ldr r5, =gUnknown_02024A4C
	movs r2, 0
	ldr r4, =gUnknown_02024A28
	ldr r3, =gUnknown_02024A30
_08070490:
	lsls r1, r6, 1
	adds r0, r1, r5
	strh r2, [r0]
	adds r0, r1, r4
	strh r2, [r0]
	adds r1, r3
	strh r2, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x3
	bls _08070490
	movs r6, 0
	ldr r2, =gUnknown_02024A38
	movs r1, 0
_080704AE:
	lsls r0, r6, 1
	adds r0, r2
	strh r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x9
	bls _080704AE
	movs r6, 0
	ldr r2, =gUnknown_020249C4
	movs r1, 0
_080704C4:
	lsls r0, r6, 1
	adds r0, r2
	strh r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x31
	bls _080704C4
	adds r0, r7, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_020249C4
	bl GetLevelUpMovesBySpecies
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r6, 0
	ldr r1, =gUnknown_02024A28
	mov r8, r1
_080704F2:
	adds r5, r6, 0
	adds r5, 0xD
	mov r0, r10
	adds r1, r5, 0
	bl GetBoxMonData
	lsls r4, r6, 1
	mov r2, r8
	adds r1, r4, r2
	strh r0, [r1]
	mov r0, r9
	adds r1, r5, 0
	bl GetBoxMonData
	ldr r1, =gUnknown_02024A4C
	adds r4, r1
	strh r0, [r4]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x3
	bls _080704F2
	ldr r1, =gUnknown_02024A38
	adds r0, r7, 0
	bl pokemon_get_eggmoves
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r6, 0
_0807052E:
	ldr r0, =gUnknown_02024A28
	lsls r1, r6, 1
	adds r2, r1, r0
	ldrh r1, [r2]
	mov r9, r0
	cmp r1, 0
	beq _080705A4
	movs r5, 0
	cmp r5, r8
	bcs _08070596
	adds r4, r2, 0
	ldr r2, =0x0000ffff
_08070546:
	ldr r0, =gUnknown_02024A38
	lsls r1, r5, 1
	adds r1, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0807058C
	adds r1, r0, 0
	adds r0, r7, 0
	str r2, [sp, 0x8]
	bl GiveMoveToMon
	lsls r0, 16
	lsrs r0, 16
	ldr r2, [sp, 0x8]
	cmp r0, r2
	bne _08070596
	ldrh r1, [r4]
	adds r0, r7, 0
	bl DeleteFirstMoveAndGiveMoveToMon
	b _08070596
	.pool
_0807058C:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _08070546
_08070596:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r3, =gUnknown_02024A28
	mov r9, r3
	cmp r6, 0x3
	bls _0807052E
_080705A4:
	movs r6, 0
_080705A6:
	lsls r0, r6, 1
	mov r2, r9
	adds r1, r0, r2
	ldrh r1, [r1]
	adds r2, r0, 0
	adds r6, 0x1
	mov r8, r6
	cmp r1, 0
	beq _08070608
	movs r5, 0
	ldr r0, =gUnknown_02024A28
	adds r4, r2, r0
	ldr r6, =0x0000ffff
	mov r9, r0
_080705C2:
	ldr r3, =0x00000121
	adds r0, r5, r3
	lsls r0, 16
	lsrs r0, 16
	bl ItemIdToBattleMoveId
	ldrh r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bne _080705FE
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl CanMonLearnTMHM
	cmp r0, 0
	beq _080705FE
	ldrh r1, [r4]
	adds r0, r7, 0
	bl GiveMoveToMon
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r6
	bne _080705FE
	ldrh r1, [r4]
	adds r0, r7, 0
	bl DeleteFirstMoveAndGiveMoveToMon
_080705FE:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x39
	bls _080705C2
_08070608:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r6, r0, 16
	cmp r6, 0x3
	bls _080705A6
	movs r6, 0
	mov r2, r9
	ldrh r0, [r2]
	ldr r3, =gUnknown_02024A30
	mov r10, r3
	cmp r0, 0
	beq _08070672
	mov r4, r9
	ldr r0, =gUnknown_02024A4C
	mov r9, r0
	mov r12, r10
_08070628:
	movs r5, 0
	lsls r2, r6, 1
	adds r6, 0x1
	mov r8, r6
	adds r3, r2, r4
_08070632:
	lsls r0, r5, 1
	add r0, r9
	ldrh r2, [r3]
	adds r1, r2, 0
	ldrh r0, [r0]
	cmp r1, r0
	bne _08070654
	cmp r1, 0
	beq _08070654
	ldr r1, [sp]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	lsls r1, 1
	add r1, r12
	strh r2, [r1]
_08070654:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _08070632
	mov r1, r8
	lsls r0, r1, 16
	lsrs r6, r0, 16
	cmp r6, 0x3
	bhi _08070672
	lsls r0, r6, 1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08070628
_08070672:
	movs r6, 0
	mov r2, r10
	ldrh r0, [r2]
	cmp r0, 0
	beq _080706FC
_0807067C:
	movs r5, 0
	adds r3, r6, 0x1
	mov r8, r3
	ldr r0, [sp, 0x4]
	cmp r5, r0
	bcs _080706E4
	ldr r2, =0x0000ffff
_0807068A:
	ldr r1, =gUnknown_020249C4
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	cmp r1, 0
	beq _080706D8
	lsls r0, r6, 1
	mov r3, r10
	adds r4, r0, r3
	ldrh r0, [r4]
	cmp r0, r1
	bne _080706D8
	adds r1, r0, 0
	adds r0, r7, 0
	str r2, [sp, 0x8]
	bl GiveMoveToMon
	lsls r0, 16
	lsrs r0, 16
	ldr r2, [sp, 0x8]
	cmp r0, r2
	bne _080706E4
	ldrh r1, [r4]
	adds r0, r7, 0
	bl DeleteFirstMoveAndGiveMoveToMon
	b _080706E4
	.pool
_080706D8:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [sp, 0x4]
	cmp r5, r0
	bcc _0807068A
_080706E4:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r6, r0, 16
	cmp r6, 0x3
	bhi _080706FC
	ldr r0, =gUnknown_02024A30
	lsls r1, r6, 1
	adds r1, r0
	ldrh r1, [r1]
	mov r10, r0
	cmp r1, 0
	bne _0807067C
_080706FC:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end daycare_build_child_moveset

	thumb_func_start sub_8070710
sub_8070710: @ 8070710
	adds r2, r0, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r2, r1
	movs r1, 0
	str r1, [r0]
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
	bx lr
	thumb_func_end sub_8070710

	thumb_func_start sub_8070728
sub_8070728: @ 8070728
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_8070710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8070728

	thumb_func_start incense_effects
incense_effects: @ 8070744
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r1, [r4]
	movs r7, 0xB4
	lsls r7, 1
	cmp r1, r7
	beq _0807075C
	movs r0, 0xAF
	lsls r0, 1
	cmp r1, r0
	bne _0807079E
_0807075C:
	adds r0, r5, 0
	movs r1, 0xC
	bl GetBoxMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r5, 0
	adds r0, 0x8C
	movs r1, 0xC
	bl GetBoxMonData
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r4]
	cmp r0, r7
	bne _08070788
	cmp r6, 0xDD
	beq _08070788
	cmp r2, 0xDD
	beq _08070788
	movs r0, 0xCA
	strh r0, [r4]
_08070788:
	ldrh r1, [r4]
	movs r0, 0xAF
	lsls r0, 1
	cmp r1, r0
	bne _0807079E
	cmp r6, 0xDC
	beq _0807079E
	cmp r2, 0xDC
	beq _0807079E
	movs r0, 0xB7
	strh r0, [r4]
_0807079E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end incense_effects

	thumb_func_start sub_80707A4
sub_80707A4: @ 80707A4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0xC
	bl GetBoxMonData
	adds r5, r0, 0
	adds r4, 0x8C
	adds r0, r4, 0
	movs r1, 0xC
	bl GetBoxMonData
	cmp r5, 0xCA
	beq _080707C6
	cmp r0, 0xCA
	bne _080707E2
_080707C6:
	movs r4, 0xAC
	lsls r4, 1
	adds r0, r6, 0
	adds r1, r4, 0
	bl GiveMoveToMon
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _080707E2
	adds r0, r6, 0
	adds r1, r4, 0
	bl DeleteFirstMoveAndGiveMoveToMon
_080707E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80707A4

	thumb_func_start sub_80707EC
sub_80707EC: @ 80707EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	adds r6, r1, 0
	movs r4, 0
	movs r0, 0x1
	mov r8, r0
_080707FE:
	movs r0, 0x8C
	muls r0, r4
	adds r5, r7, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetBoxMonData
	lsls r1, r4, 1
	add r1, sp
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x84
	bne _08070826
	adds r0, r4, 0
	mov r1, r8
	eors r0, r1
	strb r0, [r6]
	strb r4, [r6, 0x1]
	b _0807083E
_08070826:
	adds r0, r5, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFE
	bne _0807083E
	strb r4, [r6]
	adds r0, r4, 0
	mov r1, r8
	eors r0, r1
	strb r0, [r6, 0x1]
_0807083E:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _080707FE
	ldrb r0, [r6]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	bl sub_8070004
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1D
	bne _08070870
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _08070870
	movs r4, 0x20
_08070870:
	ldr r0, =0x00000183
	cmp r4, r0
	bne _0807088C
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0807088C
	movs r4, 0xC1
	lsls r4, 1
_0807088C:
	ldrb r0, [r6, 0x1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r0, 0x84
	bne _080708B4
	ldrb r1, [r6]
	movs r0, 0x8C
	muls r0, r1
	adds r0, r7, r0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFE
	beq _080708B4
	ldrb r1, [r6, 0x1]
	ldrb r0, [r6]
	strb r0, [r6, 0x1]
	strb r1, [r6]
_080708B4:
	adds r0, r4, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80707EC

	thumb_func_start sub_80708C8
sub_80708C8: @ 80708C8
	push {r4-r6,lr}
	sub sp, 0x6C
	adds r6, r0, 0
	add r5, sp, 0x64
	adds r1, r5, 0
	bl sub_80707EC
	add r4, sp, 0x68
	strh r0, [r4]
	adds r0, r4, 0
	adds r1, r6, 0
	bl incense_effects
	ldrh r1, [r4]
	mov r0, sp
	adds r2, r6, 0
	bl sub_8070A0C
	mov r0, sp
	adds r1, r6, 0
	bl sub_8070260
	ldrb r0, [r5, 0x1]
	movs r2, 0x8C
	adds r1, r0, 0
	muls r1, r2
	adds r1, r6, r1
	ldrb r0, [r5]
	muls r2, r0
	adds r2, r6, r2
	mov r0, sp
	bl daycare_build_child_moveset
	ldrh r0, [r4]
	cmp r0, 0xAC
	bne _08070918
	mov r0, sp
	adds r1, r6, 0
	bl sub_80707A4
_08070918:
	mov r2, sp
	adds r2, 0x6A
	movs r0, 0x1
	strb r0, [r2]
	mov r0, sp
	movs r1, 0x2D
	bl SetMonData
	ldr r0, =gPlayerParty
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	mov r1, sp
	movs r2, 0x64
	bl memcpy
	bl party_compaction
	bl CalculatePlayerPartyCount
	adds r0, r6, 0
	bl sub_8070710
	add sp, 0x6C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80708C8

	thumb_func_start sub_8070954
sub_8070954: @ 8070954
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	adds r7, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r1, r5, 0
	movs r2, 0x5
	movs r3, 0x20
	bl CreateMon
	movs r0, 0x12
	add r0, sp
	mov r8, r0
	strb r4, [r0]
	movs r1, 0x4
	add r0, sp, 0x10
	strh r1, [r0]
	mov r4, sp
	adds r4, 0x13
	movs r0, 0x1
	mov r9, r0
	mov r0, r9
	strb r0, [r4]
	adds r0, r7, 0
	movs r1, 0x26
	add r2, sp, 0x10
	bl SetMonData
	ldr r2, =gEggName
	adds r0, r7, 0
	movs r1, 0x2
	bl SetMonData
	lsls r2, r5, 3
	subs r2, r5
	lsls r2, 2
	ldr r0, =gBaseStats + 0x11 @ egg cycles offset
	adds r2, r0
	adds r0, r7, 0
	movs r1, 0x20
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x24
	mov r2, r8
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x3
	adds r2, r4, 0
	bl SetMonData
	cmp r6, 0
	beq _080709E6
	add r2, sp, 0x14
	movs r0, 0xFD
	strb r0, [r2]
	adds r0, r7, 0
	movs r1, 0x23
	bl SetMonData
_080709E6:
	mov r2, sp
	adds r2, 0x15
	mov r0, r9
	strb r0, [r2]
	adds r0, r7, 0
	movs r1, 0x2D
	bl SetMonData
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8070954

	thumb_func_start sub_8070A0C
sub_8070A0C: @ 8070A0C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r0
	ldr r0, [r2]
	movs r1, 0x1
	mov r8, r1
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x5
	movs r3, 0x20
	bl CreateMon
	movs r0, 0x12
	add r0, sp
	mov r9, r0
	strb r4, [r0]
	movs r1, 0x4
	add r0, sp, 0x10
	strh r1, [r0]
	mov r4, sp
	adds r4, 0x13
	mov r1, r8
	strb r1, [r4]
	adds r0, r6, 0
	movs r1, 0x26
	add r2, sp, 0x10
	bl SetMonData
	ldr r2, =gEggName
	adds r0, r6, 0
	movs r1, 0x2
	bl SetMonData
	lsls r2, r5, 3
	subs r2, r5
	lsls r2, 2
	ldr r0, =gBaseStats + 0x11 @ egg cycles offset
	adds r2, r0
	adds r0, r6, 0
	movs r1, 0x20
	bl SetMonData
	adds r0, r6, 0
	movs r1, 0x24
	mov r2, r9
	bl SetMonData
	adds r0, r6, 0
	movs r1, 0x3
	adds r2, r4, 0
	bl SetMonData
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8070A0C

	thumb_func_start sp0B8_daycare
sp0B8_daycare: @ 8070AA8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_80708C8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp0B8_daycare

	thumb_func_start sub_8070AC4
sub_8070AC4: @ 8070AC4
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	movs r7, 0
	movs r5, 0
_08070ACE:
	movs r0, 0x8C
	adds r4, r5, 0
	muls r4, r0
	adds r0, r6, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _08070AEE
	adds r1, r6, 0
	adds r1, 0x88
	adds r1, r4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r7, 0x1
_08070AEE:
	adds r5, 0x1
	cmp r5, 0x1
	bls _08070ACE
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08070B34
	cmp r7, 0x2
	bne _08070B34
	subs r1, 0x4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08070B34
	adds r0, r6, 0
	bl daycare_relationship_score
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	muls r0, r1
	ldr r1, =0x0000ffff
	bl __udivsi3
	cmp r4, r0
	bls _08070B34
	bl sub_80701E0
_08070B34:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08070BC0
	bl sub_807228C
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	bcs _08070BC0
	ldr r4, =gPlayerParty
_08070B5C:
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	beq _08070BB4
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMonData
	cmp r0, 0
	bne _08070BB4
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	adds r1, r0, 0
	str r1, [sp]
	cmp r0, 0
	beq _08070BA8
	cmp r0, r6
	bcc _08070B98
	subs r0, r6
	b _08070B9A
	.pool
_08070B98:
	subs r0, r1, 0x1
_08070B9A:
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x20
	mov r2, sp
	bl SetMonData
	b _08070BB4
_08070BA8:
	ldr r0, =gSpecialVar_0x8004
	strh r5, [r0]
	movs r0, 0x1
	b _08070BC2
	.pool
_08070BB4:
	adds r4, 0x64
	adds r5, 0x1
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	bcc _08070B5C
_08070BC0:
	movs r0, 0
_08070BC2:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8070AC4

	thumb_func_start sub_8070BD0
sub_8070BD0: @ 8070BD0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_8070AC4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8070BD0

	thumb_func_start sub_8070BF0
sub_8070BF0: @ 8070BF0
	push {lr}
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _08070C00
	movs r0, 0x1
_08070C00:
	pop {r1}
	bx r1
	thumb_func_end sub_8070BF0

	thumb_func_start sub_8070C04
sub_8070C04: @ 8070C04
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _08070C2E
	ldr r1, =gStringVar1
	adds r0, r4, 0
	bl pokemon_get_nick_
	adds r0, r4, 0
	movs r1, 0x7
	mov r2, sp
	bl GetBoxMonData
	ldr r0, =gStringVar3
	mov r1, sp
	bl StringCopy
_08070C2E:
	adds r4, 0x8C
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _08070C44
	ldr r1, =gStringVar2
	adds r0, r4, 0
	bl pokemon_get_nick_
_08070C44:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8070C04

	thumb_func_start sub_8070C58
sub_8070C58: @ 8070C58
	push {r4,r5,lr}
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	ldr r1, =gStringVar1
	bl pokemon_get_nick_
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	muls r0, r5
	adds r0, r4
	movs r1, 0xB
	bl GetBoxMonData
	lsls r0, 16
	lsrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8070C58

	thumb_func_start sp0B5_daycare
sp0B5_daycare: @ 8070C94
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_8070C04
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp0B5_daycare

	thumb_func_start sp0B6_daycare
sp0B6_daycare: @ 8070CB0
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00003030
	adds r0, r1
	bl sub_8070BF0
	lsls r0, 24
	cmp r0, 0
	beq _08070CD0
	movs r0, 0x1
	b _08070CF2
	.pool
_08070CD0:
	ldr r0, [r4]
	ldr r1, =0x00003030
	adds r0, r1
	bl daycare_count_pokemon
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08070CEC
	movs r0, 0
	b _08070CF2
	.pool
_08070CEC:
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
_08070CF2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sp0B6_daycare

	thumb_func_start sub_8070CF8
sub_8070CF8: @ 8070CF8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl daycare_count_pokemon
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08070D10
	movs r0, 0
_08070D10:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8070CF8

	thumb_func_start sub_8070D1C
sub_8070D1C: @ 8070D1C
	push {r4-r6,lr}
	adds r5, r1, 0
	movs r4, 0
	adds r1, r0, 0
_08070D24:
	movs r3, 0
	ldrh r0, [r1]
	adds r2, r5, 0
_08070D2A:
	ldrh r6, [r2]
	cmp r0, r6
	bne _08070D34
	movs r0, 0x1
	b _08070D46
_08070D34:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x1
	ble _08070D2A
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x1
	ble _08070D24
	movs r0, 0
_08070D46:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8070D1C

	thumb_func_start daycare_relationship_score
daycare_relationship_score: @ 8070D4C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp, 0x1C]
	movs r7, 0
	mov r0, sp
	adds r0, 0x8
	str r0, [sp, 0x20]
	add r1, sp, 0xC
	mov r9, r1
	mov r2, sp
	adds r2, 0x14
	str r2, [sp, 0x24]
	subs r0, 0x6
	ldr r1, =gBaseStats
	mov r10, r1
	ldr r5, [sp, 0x20]
	mov r8, r0
	mov r6, sp
	str r2, [sp, 0x28]
	mov r2, r9
	str r2, [sp, 0x2C]
_08070D7E:
	movs r0, 0x8C
	adds r4, r7, 0
	muls r4, r0
	ldr r0, [sp, 0x1C]
	adds r4, r0, r4
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBoxMonData
	ldr r1, [sp, 0x2C]
	stm r1!, {r0}
	str r1, [sp, 0x2C]
	adds r0, r4, 0
	movs r1, 0
	bl GetBoxMonData
	adds r1, r0, 0
	ldrh r0, [r5]
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x28]
	stm r2!, {r0}
	str r2, [sp, 0x28]
	ldrh r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r10
	ldrb r0, [r0, 0x14]
	strh r0, [r6]
	ldrh r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r10
	ldrb r0, [r0, 0x15]
	mov r1, r8
	strh r0, [r1]
	adds r5, 0x2
	movs r2, 0x4
	add r8, r2
	adds r6, 0x4
	adds r7, 0x1
	cmp r7, 0x1
	bls _08070D7E
	mov r0, sp
	ldrh r1, [r0]
	cmp r1, 0xF
	beq _08070DFC
	ldrh r0, [r0, 0x4]
	cmp r0, 0xF
	beq _08070DFC
	cmp r1, 0xD
	bne _08070E04
	cmp r0, 0xD
	bne _08070E08
_08070DFC:
	movs r0, 0
	b _08070E5C
	.pool
_08070E04:
	cmp r0, 0xD
	bne _08070E14
_08070E08:
	ldr r1, [sp, 0xC]
	mov r2, r9
	ldr r0, [r2, 0x4]
	cmp r1, r0
	beq _08070E56
	b _08070E5A
_08070E14:
	ldr r0, [sp, 0x14]
	ldr r2, [sp, 0x24]
	ldr r1, [r2, 0x4]
	cmp r0, r1
	beq _08070DFC
	cmp r0, 0xFF
	beq _08070DFC
	cmp r1, 0xFF
	beq _08070DFC
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8070D1C
	lsls r0, 24
	cmp r0, 0
	beq _08070DFC
	ldr r0, [sp, 0x20]
	ldrh r1, [r0, 0x2]
	ldrh r0, [r0]
	cmp r0, r1
	bne _08070E4C
	ldr r1, [sp, 0xC]
	mov r2, r9
	ldr r0, [r2, 0x4]
	cmp r1, r0
	beq _08070E5A
	movs r0, 0x46
	b _08070E5C
_08070E4C:
	ldr r1, [sp, 0xC]
	mov r2, r9
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bne _08070E5A
_08070E56:
	movs r0, 0x14
	b _08070E5C
_08070E5A:
	movs r0, 0x32
_08070E5C:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end daycare_relationship_score

	thumb_func_start daycare_relationship_score_from_savegame
daycare_relationship_score_from_savegame: @ 8070E6C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl daycare_relationship_score
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end daycare_relationship_score_from_savegame

	thumb_func_start sp0B9_daycare_relationship_comment
sp0B9_daycare_relationship_comment: @ 8070E8C
	push {lr}
	bl daycare_relationship_score_from_savegame
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	movs r1, 0
	cmp r0, 0
	bne _08070EA0
	movs r1, 0x3
_08070EA0:
	cmp r0, 0x14
	bne _08070EA6
	movs r1, 0x2
_08070EA6:
	cmp r0, 0x32
	bne _08070EAC
	movs r1, 0x1
_08070EAC:
	cmp r2, 0x46
	bne _08070EB2
	movs r1, 0
_08070EB2:
	ldr r0, =gStringVar4
	ldr r2, =gUnknown_0832B6F8
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp0B9_daycare_relationship_comment

	thumb_func_start sub_8070ECC
sub_8070ECC: @ 8070ECC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	mov r2, sp
	mov r1, sp
	movs r0, 0
	strb r0, [r1, 0x1]
	strb r0, [r2]
	movs r3, 0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08070F10
_08070EE8:
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, 0xB5
	bne _08070EF6
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
_08070EF6:
	ldrb r0, [r1]
	cmp r0, 0xB6
	bne _08070F02
	ldrb r0, [r2, 0x1]
	adds r0, 0x1
	strb r0, [r2, 0x1]
_08070F02:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08070EE8
_08070F10:
	cmp r5, 0
	bne _08070F24
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _08070F24
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08070F38
_08070F24:
	cmp r5, 0xFE
	bne _08070F3C
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08070F3C
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _08070F3C
_08070F38:
	movs r0, 0x1
	b _08070F3E
_08070F3C:
	movs r0, 0
_08070F3E:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8070ECC

	thumb_func_start sub_8070F48
sub_8070F48: @ 8070F48
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _08070F68
	movs r1, 0
	bl sub_8070ECC
	lsls r0, 24
	cmp r0, 0
	bne _08070F84
	ldr r1, =gUnknown_0832DAC7
	b _08070F86
	.pool
_08070F68:
	cmp r1, 0xFE
	bne _08070F84
	adds r0, r4, 0
	movs r1, 0xFE
	bl sub_8070ECC
	lsls r0, 24
	cmp r0, 0
	bne _08070F84
	ldr r1, =gUnknown_0832DAC9
	b _08070F86
	.pool
_08070F84:
	ldr r1, =gUnknown_0832DACB
_08070F86:
	adds r0, r4, 0
	bl StringAppend
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8070F48

	thumb_func_start sub_8070F98
sub_8070F98: @ 8070F98
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl GetBoxMonGender
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_8070F48
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8070F98

	thumb_func_start sub_8070FB4
sub_8070FB4: @ 8070FB4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x28
	mov r8, r0
	adds r7, r1, 0
	movs r0, 0xFF
	strb r0, [r7]
	movs r6, 0
	add r0, sp, 0x14
	mov r9, r0
_08070FCC:
	movs r0, 0x8C
	adds r4, r6, 0
	muls r4, r0
	add r4, r8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	mov r1, sp
	adds r5, r1, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl pokemon_get_nick_
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8070F98
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	bls _08070FCC
	adds r0, r7, 0
	mov r1, sp
	bl StringCopy
	ldr r4, =gUnknown_085EF881
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringAppend
	adds r0, r7, 0
	mov r1, r9
	bl StringAppend
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringAppend
	ldr r1, =gUnknown_085EF883
	adds r0, r7, 0
	bl StringAppend
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8070FB4

	thumb_func_start sub_8071038
sub_8071038: @ 8071038
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r4, r1, 0
	movs r0, 0xFF
	strb r0, [r4]
	movs r5, 0
_08071046:
	adds r0, r4, 0
	ldr r1, =gUnknown_085EF888
	bl StringAppend
	movs r0, 0x8C
	adds r2, r5, 0
	muls r2, r0
	adds r0, r6, r2
	adds r1, r6, 0
	adds r1, 0x88
	adds r1, r2
	ldr r1, [r1]
	bl sub_806FDEC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	mov r1, sp
	bl StringAppend
	adds r0, r4, 0
	ldr r1, =gUnknown_085EF881
	bl StringAppend
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _08071046
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8071038

	thumb_func_start sub_807109C
sub_807109C: @ 807109C
	push {r4-r6,lr}
	sub sp, 0x10
	str r1, [sp]
	mov r1, sp
	movs r5, 0
	strb r0, [r1, 0x4]
	mov r0, sp
	movs r6, 0x1
	movs r4, 0x1
	strb r4, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r3, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r3, [r0, 0x9]
	mov r3, sp
	ldrb r1, [r3, 0xC]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	strb r0, [r3, 0xC]
	ldr r3, =gTextFlags
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	mov r0, sp
	strb r5, [r0, 0xA]
	strb r4, [r0, 0xB]
	mov r3, sp
	ldrb r1, [r3, 0xC]
	movs r4, 0xF
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r3, 0xC]
	mov r1, sp
	ldrb r0, [r1, 0xD]
	ands r2, r0
	orrs r2, r6
	strb r2, [r1, 0xD]
	ands r2, r4
	movs r0, 0x30
	orrs r2, r0
	strb r2, [r1, 0xD]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807109C

	thumb_func_start sub_8071110
sub_8071110: @ 8071110
	push {r4-r6,lr}
	sub sp, 0x14
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r3, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x8C
	muls r0, r2
	adds r5, r0
	adds r0, r5, 0
	mov r1, sp
	bl pokemon_get_nick_
	mov r0, sp
	adds r1, r5, 0
	bl sub_8070F98
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x8
	adds r3, r6, 0
	bl sub_807109C
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8071110

	thumb_func_start sub_8071148
sub_8071148: @ 8071148
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gUnknown_085EF888
	mov r0, sp
	bl StringCopy
	movs r0, 0x8C
	adds r1, r6, 0
	muls r1, r0
	adds r0, r4, r1
	adds r4, 0x88
	adds r4, r1
	ldr r1, [r4]
	bl sub_806FDEC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	add r4, sp, 0xC
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r0, sp
	adds r1, r4, 0
	bl StringAppend
	movs r0, 0x1
	mov r1, sp
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	adds r0, r5, 0
	mov r1, sp
	mov r3, r8
	bl sub_807109C
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8071148

	thumb_func_start sub_80711B8
sub_80711B8: @ 80711B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	cmp r6, 0x1
	bhi _080711F0
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r0, [r0]
	ldr r4, =0x00003030
	adds r0, r4
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_8071110
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_8071148
_080711F0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80711B8

	thumb_func_start c3_080469FC
c3_080469FC: @ 8071204
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrb r0, [r4, 0x8]
	bl ListMenuHandleInput
	adds r1, r0, 0
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08071284
	cmp r1, 0x1
	bls _0807123C
	cmp r1, 0x5
	beq _08071248
	b _0807124E
	.pool
_0807123C:
	ldr r0, =gScriptResult
	strh r1, [r0]
	b _0807124E
	.pool
_08071248:
	ldr r1, =gScriptResult
	movs r0, 0x2
	strh r0, [r1]
_0807124E:
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrb r0, [r4, 0x8]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldrb r0, [r4, 0xA]
	movs r1, 0x1
	bl sub_819746C
	ldrb r0, [r4, 0xA]
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
	b _080712B4
	.pool
_08071284:
	movs r1, 0x2
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _080712B4
	ldr r0, =gScriptResult
	strh r1, [r0]
	ldrb r0, [r4, 0x8]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldrb r0, [r4, 0xA]
	movs r1, 0x1
	bl sub_819746C
	ldrb r0, [r4, 0xA]
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_080712B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_080469FC

	thumb_func_start sub_80712C0
sub_80712C0: @ 80712C0
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r0, =gUnknown_0832B6C0
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_81973FC
	mov r1, sp
	ldr r0, =gUnknown_0832B6E0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r0, sp
	strb r4, [r0, 0x10]
	movs r1, 0
	movs r2, 0
	bl ListMenuInit
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =c3_080469FC
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	strh r4, [r1, 0xA]
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80712C0

	thumb_func_start sub_8071330
sub_8071330: @ 8071330
	push {lr}
	bl sub_81B9328
	ldr r1, =gMain
	ldr r0, =c2_exit_to_overworld_2_switch
	str r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8071330

	.align 2, 0 @ Don't pad with nop.
