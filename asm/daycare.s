	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_8070BD0
sub_8070BD0: @ 8070BD0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl _DoEggActions_CheckHatch
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
	bl GetBoxMonNick
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
	bl GetBoxMonNick
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
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	ldr r1, =gStringVar1
	bl GetBoxMonNick
	bl GetCursorSelectionMonId
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
	bl CountPokemonInDaycare
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
	bl CountPokemonInDaycare
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

	thumb_func_start GetDaycareCompatibilityScore
GetDaycareCompatibilityScore: @ 8070D4C
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
	thumb_func_end GetDaycareCompatibilityScore

	thumb_func_start daycare_relationship_score_from_savegame
daycare_relationship_score_from_savegame: @ 8070E6C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003030
	adds r0, r1
	bl GetDaycareCompatibilityScore
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
	bl GetBoxMonNick
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
	ldr r4, =gText_NewLine2
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringAppend
	adds r0, r7, 0
	mov r1, r9
	bl StringAppend
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringAppend
	ldr r1, =gText_Exit4
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
	ldr r1, =gText_Lv
	bl StringAppend
	movs r0, 0x8C
	adds r2, r5, 0
	muls r2, r0
	adds r0, r6, r2
	adds r1, r6, 0
	adds r1, 0x88
	adds r1, r2
	ldr r1, [r1]
	bl GetLevelAfterDaycareSteps
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
	ldr r1, =gText_NewLine2
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
	bl GetBoxMonNick
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
	ldr r1, =gText_Lv
	mov r0, sp
	bl StringCopy
	movs r0, 0x8C
	adds r1, r6, 0
	muls r1, r0
	adds r0, r4, r1
	adds r4, 0x88
	adds r4, r1
	ldr r1, [r4]
	bl GetLevelAfterDaycareSteps
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
	bl EnableBothScriptContexts
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
	bl EnableBothScriptContexts
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
