	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start nullsub_77
nullsub_77: @ 81BADF0
	bx lr
	thumb_func_end nullsub_77

	thumb_func_start SetBankFuncToPlayerPartnerBufferRunCommand
SetBankFuncToPlayerPartnerBufferRunCommand: @ 81BADF4
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =PlayerPartnerBufferRunCommand
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end SetBankFuncToPlayerPartnerBufferRunCommand

	thumb_func_start PlayerPartnerBufferRunCommand
PlayerPartnerBufferRunCommand: @ 81BAE10
	push {lr}
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _081BAE5C
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _081BAE58
	ldr r0, =gPlayerPartnerBufferCommands
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _081BAE5C
	.pool
_081BAE58:
	bl PlayerPartnerBufferExecCompleted
_081BAE5C:
	pop {r0}
	bx r0
	thumb_func_end PlayerPartnerBufferRunCommand

	thumb_func_start sub_81BAE60
sub_81BAE60: @ 81BAE60
	push {lr}
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BAE84
	bl PlayerPartnerBufferExecCompleted
_081BAE84:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BAE60

	thumb_func_start sub_81BAE98
sub_81BAE98: @ 81BAE98
	push {r4-r6,lr}
	ldr r6, =gSprites
	ldr r5, =gBankSpriteIds
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BAEE8
	movs r0, 0
	bl nullsub_25
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl FreeSpriteOamMatrix
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	bl PlayerPartnerBufferExecCompleted
_081BAEE8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BAE98

	thumb_func_start sub_81BAF00
sub_81BAF00: @ 81BAF00
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r1, [r4]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x9]
	subs r0, 0x1
	strb r0, [r1, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _081BAF38
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl PlayerPartnerBufferExecCompleted
_081BAF38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BAF00

	thumb_func_start sub_81BAF48
sub_81BAF48: @ 81BAF48
	push {r4-r6,lr}
	movs r6, 0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081BAF6C
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081BAFA0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081BAFA0
_081BAF6C:
	ldr r2, =gSprites
	ldr r1, =gHealthBoxesIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BAFD8
	b _081BAFD6
	.pool
_081BAFA0:
	ldr r2, =gSprites
	ldr r5, =gHealthBoxesIds
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	adds r0, r3, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r2, 0
	adds r4, 0x1C
	adds r0, r4
	ldr r2, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r2, r0
	bne _081BAFD8
	movs r0, 0x2
	eors r3, r0
	adds r0, r3, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	cmp r0, r2
	bne _081BAFD8
_081BAFD6:
	movs r6, 0x1
_081BAFD8:
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	beq _081BAFE4
	movs r6, 0
_081BAFE4:
	cmp r6, 0
	beq _081BB00A
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BAF00
	str r1, [r0]
_081BB00A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BAF48

	thumb_func_start sub_81BB02C
sub_81BB02C: @ 81BB02C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_020244D0
	mov r12, r0
	ldr r0, [r0]
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r3
	ldrb r1, [r4]
	movs r5, 0x8
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _081BB058
	b _081BB196
_081BB058:
	movs r1, 0x2
	mov r8, r1
	adds r1, r2, 0
	mov r0, r8
	eors r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _081BB07A
	b _081BB196
_081BB07A:
	ldr r1, =gSprites
	mov r10, r1
	ldr r0, =gUnknown_03005D7C
	mov r9, r0
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r5, r10
	adds r5, 0x1C
	adds r0, r5
	ldr r3, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r3, r0
	bne _081BB196
	ldr r0, =gBankSpriteIds
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r3
	bne _081BB196
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081BB196
	mov r1, r12
	ldr r0, [r1]
	ldrb r1, [r7]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r6, [r0, 0x9]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081BB134
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _081BB134
	ldrb r0, [r7]
	mov r1, r8
	eors r0, r1
	add r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	bl DestroySprite
	ldr r4, =gHealthBoxesIds
	ldrb r0, [r7]
	mov r1, r8
	eors r1, r0
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r7]
	mov r1, r8
	eors r0, r1
	bl sub_8076918
	ldrb r0, [r7]
	mov r1, r8
	eors r0, r1
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_081BB134:
	ldr r1, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r5, =gHealthBoxesIds
	ldrb r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r2, [r0, 0x8]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BAF48
	str r1, [r0]
_081BB196:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB02C

	thumb_func_start sub_81BB1D4
sub_81BB1D4: @ 81BB1D4
	push {lr}
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _081BB202
	movs r2, 0x24
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _081BB202
	bl PlayerPartnerBufferExecCompleted
_081BB202:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB1D4

	thumb_func_start bx_t3_healthbar_update
bx_t3_healthbar_update: @ 81BB214
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r6, =gHealthBoxesIds
	adds r1, r0, r6
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	bl sub_80729D0
	lsls r4, 16
	asrs r1, r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _081BB25C
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _081BB276
	.pool
_081BB25C:
	ldr r2, =gBattlePartyID
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	bl PlayerPartnerBufferExecCompleted
_081BB276:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_t3_healthbar_update

	thumb_func_start sub_81BB284
sub_81BB284: @ 81BB284
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _081BB296
	bl PlayerPartnerBufferExecCompleted
_081BB296:
	pop {r0}
	bx r0
	thumb_func_end sub_81BB284

	thumb_func_start sub_81BB29C
sub_81BB29C: @ 81BB29C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	mov r8, r0
	ldrb r0, [r0, 0x8]
	mov r10, r0
	mov r1, r8
	ldrb r7, [r1, 0xC]
	str r7, [sp, 0x8]
	ldrh r2, [r1, 0xA]
	str r2, [sp, 0xC]
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081BB2E2
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r10, r0
	bne _081BB2E2
	b _081BB3F8
_081BB2E2:
	movs r0, 0x64
	mov r1, r10
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r6, r1, r0
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x4]
	ldr r3, =gExperienceTables
	adds r4, 0x1
	lsls r4, 2
	ldr r2, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x13]
	movs r1, 0xCA
	lsls r1, 1
	muls r1, r2
	adds r4, r1
	adds r4, r3
	ldr r2, [r4]
	str r2, [sp]
	ldr r3, [sp, 0xC]
	lsls r1, r3, 16
	asrs r1, 16
	adds r0, r1
	cmp r0, r2
	bcc _081BB3D0
	adds r0, r6, 0
	movs r1, 0x19
	mov r2, sp
	bl SetMonData
	adds r0, r6, 0
	bl CalculateMonStats
	ldr r2, [sp]
	add r0, sp, 0x4
	ldrh r0, [r0]
	subs r2, r0
	ldr r0, [sp, 0xC]
	subs r2, r0, r2
	ldr r4, =gActiveBank
	ldrb r5, [r4]
	strb r7, [r4]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xB
	bl dp01_build_cmdbuf_x21_a_bb
	strb r5, [r4]
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081BB3B8
	ldr r2, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r2
	mov r1, r10
	ldrh r0, [r0]
	cmp r1, r0
	beq _081BB396
	movs r0, 0x2
	eors r7, r0
	lsls r0, r7, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	bne _081BB3B8
_081BB396:
	ldr r0, =sub_81BB628
	b _081BB3FA
	.pool
_081BB3B8:
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81BB740
	b _081BB3FC
	.pool
_081BB3D0:
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r6, 0
	movs r1, 0x19
	bl SetMonData
	ldr r1, =gBattleBankFunc
	ldr r3, [sp, 0x8]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, =sub_81BB284
	str r1, [r0]
	mov r0, r9
	bl DestroyTask
	b _081BB3FE
	.pool
_081BB3F8:
	ldr r0, =sub_81BB414
_081BB3FA:
	mov r1, r8
_081BB3FC:
	str r0, [r1]
_081BB3FE:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB29C

	thumb_func_start sub_81BB414
sub_81BB414: @ 81BB414
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	mov r8, r2
	add r8, r0
	mov r0, r8
	lsls r0, 3
	mov r8, r0
	add r8, r1
	mov r2, r8
	ldrb r1, [r2, 0x8]
	movs r0, 0xA
	ldrsh r2, [r2, r0]
	mov r9, r2
	mov r2, r8
	ldrb r2, [r2, 0xC]
	mov r10, r2
	movs r0, 0x64
	adds r6, r1, 0
	muls r6, r0
	ldr r0, =gPlayerParty
	adds r6, r0
	adds r0, r6, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	movs r1, 0x19
	bl GetMonData
	adds r3, r0, 0
	ldr r6, =gExperienceTables
	lsls r1, r4, 2
	ldr r2, =gBaseStats
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r2
	adds r1, r0
	adds r1, r6
	ldr r1, [r1]
	subs r3, r1
	adds r4, 0x1
	lsls r4, 2
	adds r4, r0
	adds r4, r6
	ldr r2, [r4]
	subs r2, r1
	ldr r0, =gHealthBoxesIds
	add r0, r10
	ldrb r1, [r0]
	mov r0, r9
	negs r0, r0
	str r0, [sp]
	mov r0, r10
	bl sub_807294C
	movs r0, 0x21
	bl PlaySE
	ldr r0, =sub_81BB4E4
	mov r1, r8
	str r0, [r1]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB414

	thumb_func_start sub_81BB4E4
sub_81BB4E4: @ 81BB4E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r6, r0, r1
	ldrh r1, [r6, 0x1C]
	movs r2, 0x1C
	ldrsh r0, [r6, r2]
	cmp r0, 0xC
	bgt _081BB514
	adds r0, r1, 0x1
	strh r0, [r6, 0x1C]
	b _081BB610
	.pool
_081BB514:
	ldrb r0, [r6, 0x8]
	mov r9, r0
	ldrh r2, [r6, 0xA]
	mov r10, r2
	ldrb r7, [r6, 0xC]
	ldr r5, =gHealthBoxesIds
	adds r5, r7, r5
	ldrb r1, [r5]
	adds r0, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	bl sub_80729D0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _081BB610
	movs r0, 0x21
	bl m4aSongNumStop
	movs r0, 0x64
	mov r1, r9
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r3, =gExperienceTables
	adds r4, 0x1
	lsls r4, 2
	ldr r2, =gBaseStats
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r1
	adds r4, r0
	adds r4, r3
	ldr r1, [r4]
	str r1, [sp]
	mov r2, r10
	lsls r0, r2, 16
	asrs r4, r0, 16
	ldr r0, [sp, 0x4]
	adds r0, r4
	cmp r0, r1
	blt _081BB5F4
	adds r0, r5, 0
	movs r1, 0x19
	mov r2, sp
	bl SetMonData
	adds r0, r5, 0
	bl CalculateMonStats
	ldr r2, [sp]
	add r0, sp, 0x4
	ldrh r0, [r0]
	subs r2, r0
	subs r2, r4, r2
	ldr r4, =gActiveBank
	ldrb r5, [r4]
	strb r7, [r4]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xB
	bl dp01_build_cmdbuf_x21_a_bb
	strb r5, [r4]
	ldr r0, =sub_81BB628
	str r0, [r6]
	b _081BB610
	.pool
_081BB5F4:
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r5, 0
	movs r1, 0x19
	bl SetMonData
	ldr r1, =gBattleBankFunc
	lsls r0, r7, 2
	adds r0, r1
	ldr r1, =sub_81BB284
	str r1, [r0]
	mov r0, r8
	bl DestroyTask
_081BB610:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB4E4

	thumb_func_start sub_81BB628
sub_81BB628: @ 81BB628
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrb r4, [r0, 0xC]
	ldrb r6, [r0, 0x8]
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081BB65C
	ldr r1, =gBattlePartyID
	movs r0, 0x2
	adds r2, r4, 0
	eors r2, r0
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	bne _081BB65C
	adds r4, r2, 0
_081BB65C:
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r4, 0
	movs r3, 0
	bl move_anim_start_t4
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81BB688
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB628

	thumb_func_start sub_81BB688
sub_81BB688: @ 81BB688
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r2, r0, r1
	ldrb r5, [r2, 0xC]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _081BB72A
	ldrb r4, [r2, 0x8]
	movs r0, 0x64
	adds r1, r4, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r0, r7, 0
	movs r1, 0x38
	bl GetMonData
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081BB708
	ldr r1, =gBattlePartyID
	movs r0, 0x2
	adds r2, r5, 0
	eors r2, r0
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _081BB708
	ldr r0, =gHealthBoxesIds
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, r7, 0
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _081BB71C
	.pool
_081BB708:
	ldr r0, =gHealthBoxesIds
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x64
	muls r1, r4
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
_081BB71C:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81BB740
	str r0, [r1]
_081BB72A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB688

	thumb_func_start sub_81BB740
sub_81BB740: @ 81BB740
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrb r1, [r4, 0x8]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	bl GetMonData
	ldrb r0, [r4, 0xC]
	ldr r1, =gBattleBankFunc
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB284
	str r1, [r0]
	adds r0, r5, 0
	bl DestroyTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB740

	thumb_func_start sub_81BB78C
sub_81BB78C: @ 81BB78C
	push {r4-r6,lr}
	ldr r6, =gSprites
	ldr r5, =gBankSpriteIds
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r3, 0x22
	ldrsh r1, [r0, r3]
	movs r3, 0x26
	ldrsh r0, [r0, r3]
	adds r1, r0
	cmp r1, 0xA0
	ble _081BB808
	ldr r1, =gBattlePartyID
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl nullsub_24
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	ldr r1, =gHealthBoxesIds
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl PlayerPartnerBufferExecCompleted
_081BB808:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB78C

	thumb_func_start sub_81BB828
sub_81BB828: @ 81BB828
	push {r4-r6,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _081BB87C
	ldr r5, =gBankSpriteIds
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, =gHealthBoxesIds
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl PlayerPartnerBufferExecCompleted
_081BB87C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB828

	thumb_func_start sub_81BB898
sub_81BB898: @ 81BB898
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _081BB8AA
	bl PlayerPartnerBufferExecCompleted
_081BB8AA:
	pop {r0}
	bx r0
	thumb_func_end sub_81BB898

	thumb_func_start bx_blink_t3
bx_blink_t3: @ 81BB8B0
	push {r4,lr}
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bne _081BB8FC
	movs r3, 0
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gDoingBattleAnim
	strb r3, [r0]
	bl PlayerPartnerBufferExecCompleted
	b _081BB926
	.pool
_081BB8FC:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081BB920
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_081BB920:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_081BB926:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t3

	thumb_func_start sub_81BB92C
sub_81BB92C: @ 81BB92C
	push {r4,lr}
	ldr r2, =gSprites
	ldr r0, =gHealthBoxesIds
	ldr r4, =gActiveBank
	ldrb r3, [r4]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BB97E
	adds r0, r3, 0
	bl sub_805E408
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081BB972
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
_081BB972:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =dp01t_35_3_free_vram
	str r0, [r1]
_081BB97E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB92C

	thumb_func_start dp01t_35_3_free_vram
dp01t_35_3_free_vram: @ 81BB9A0
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _081BB9DC
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BB9DC
	bl PlayerPartnerBufferExecCompleted
_081BB9DC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_35_3_free_vram

	thumb_func_start sub_81BB9F4
sub_81BB9F4: @ 81BB9F4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldr r7, =gActiveBank
	ldrb r1, [r7]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BBAB0
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldrb r2, [r7]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldr r0, =c3_0802FDF4
	movs r1, 0xA
	bl CreateTask
	ldr r0, =gBattlePartyID
	mov r8, r0
	ldrb r1, [r7]
	lsls r0, r1, 1
	add r0, r8
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	bl sub_805E990
	ldr r1, =gBankSpriteIds
	ldrb r0, [r7]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAnim
	ldr r4, =gHealthBoxesIds
	ldrb r1, [r7]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r1, 1
	add r1, r8
	ldrh r1, [r1]
	muls r1, r6
	adds r1, r5
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r7]
	bl sub_8076918
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r1, =gBattleBankFunc
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB92C
	str r1, [r0]
_081BBAB0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BB9F4

	thumb_func_start sub_81BBAE8
sub_81BBAE8: @ 81BBAE8
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _081BBB1A
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_081BBB1A:
	ldr r5, =gSprites
	ldr r0, =gUnknown_03005D7C
	ldrb r2, [r4]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r3, r0
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BBB60
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _081BBB60
	adds r0, r3, r5
	bl DestroySprite
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB9F4
	str r1, [r0]
_081BBB60:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BBAE8

	thumb_func_start PlayerPartnerBufferExecCompleted
PlayerPartnerBufferExecCompleted: @ 81BBB8C
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =PlayerPartnerBufferRunCommand
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081BBBE0
	bl GetMultiplayerId
	mov r1, sp
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	mov r2, sp
	bl PrepareBufferDataTransferLink
	ldr r1, =gBattleBufferA
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r1
	movs r1, 0x38
	strb r1, [r0]
	b _081BBBF2
	.pool
_081BBBE0:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_081BBBF2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayerPartnerBufferExecCompleted

	thumb_func_start sub_81BBC04
sub_81BBC04: @ 81BBC04
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081BBC26
	bl PlayerPartnerBufferExecCompleted
_081BBC26:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BBC04

	thumb_func_start bx_80E8A6C
bx_80E8A6C: @ 81BBC34
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081BBC56
	bl PlayerPartnerBufferExecCompleted
_081BBC56:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_80E8A6C

	thumb_func_start dp01t_00_3_getattr
dp01t_00_3_getattr: @ 81BBC64
	push {r4-r6,lr}
	sub sp, 0x100
	movs r6, 0
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _081BBC9C
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl dp01_getattr_by_ch1_for_player_pokemon
	adds r6, r0, 0
	b _081BBCBE
	.pool
_081BBC9C:
	ldrb r4, [r1]
	movs r5, 0
_081BBCA0:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _081BBCB6
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl dp01_getattr_by_ch1_for_player_pokemon
	adds r6, r0
_081BBCB6:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _081BBCA0
_081BBCBE:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl PlayerPartnerBufferExecCompleted
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_3_getattr

	thumb_func_start dp01_getattr_by_ch1_for_player_pokemon
dp01_getattr_by_ch1_for_player_pokemon: @ 81BBCD8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x90
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r2, =gBattleBufferA
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3B
	bls _081BBD02
	bl _081BC46E
_081BBD02:
	lsls r0, 2
	ldr r1, =_081BBD18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BBD18:
	.4byte _081BBE08
	.4byte _081BC02C
	.4byte _081BC03C
	.4byte _081BC04C
	.4byte _081BC0B4
	.4byte _081BC0B4
	.4byte _081BC0B4
	.4byte _081BC0B4
	.4byte _081BC0D0
	.4byte _081BC10C
	.4byte _081BC10C
	.4byte _081BC10C
	.4byte _081BC10C
	.4byte _081BC46E
	.4byte _081BC46E
	.4byte _081BC46E
	.4byte _081BC46E
	.4byte _081BC128
	.4byte _081BC138
	.4byte _081BC168
	.4byte _081BC178
	.4byte _081BC188
	.4byte _081BC198
	.4byte _081BC1A8
	.4byte _081BC1B8
	.4byte _081BC1C8
	.4byte _081BC1D8
	.4byte _081BC1E8
	.4byte _081BC1F8
	.4byte _081BC208
	.4byte _081BC218
	.4byte _081BC228
	.4byte _081BC278
	.4byte _081BC288
	.4byte _081BC298
	.4byte _081BC2A8
	.4byte _081BC2B8
	.4byte _081BC2C8
	.4byte _081BC2D8
	.4byte _081BC2E8
	.4byte _081BC2F8
	.4byte _081BC32C
	.4byte _081BC33C
	.4byte _081BC34C
	.4byte _081BC35C
	.4byte _081BC36C
	.4byte _081BC37C
	.4byte _081BC38C
	.4byte _081BC39C
	.4byte _081BC3BC
	.4byte _081BC3CC
	.4byte _081BC3DC
	.4byte _081BC3EC
	.4byte _081BC3FC
	.4byte _081BC40C
	.4byte _081BC41C
	.4byte _081BC42C
	.4byte _081BC43C
	.4byte _081BC44C
	.4byte _081BC45C
_081BBE08:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2E]
	movs r6, 0
	add r0, sp, 0x24
	mov r9, r0
	movs r1, 0x3B
	add r1, sp
	mov r10, r1
	mov r2, sp
	adds r2, 0x2B
	str r2, [sp, 0x80]
	mov r0, sp
	adds r0, 0x2A
	str r0, [sp, 0x7C]
	mov r1, sp
	adds r1, 0x68
	str r1, [sp, 0x8C]
	adds r2, 0x5
	str r2, [sp, 0x84]
	adds r0, 0x12
	str r0, [sp, 0x88]
	mov r8, r4
	add r4, sp, 0xC
_081BBE54:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r8
	bl GetMonData
	strh r0, [r4]
	adds r1, r6, 0
	adds r1, 0x11
	mov r0, r8
	bl GetMonData
	mov r2, r9
	adds r1, r2, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _081BBE54
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	mov r3, sp
	movs r5, 0x1F
	ands r0, r5
	ldrb r2, [r3, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	mov r3, sp
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 5
	ldrh r2, [r3, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r3, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [sp, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	mov r3, sp
	ands r0, r6
	lsls r0, 4
	ldrh r2, [r3, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 1
	ldrb r2, [r3, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x48]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	str r0, [sp, 0x4C]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x7C]
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, sp
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r3, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r3, sp
	lsls r0, 7
	ldrb r2, [r3, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x54]
	adds r0, r4, 0
	movs r1, 0x2
	ldr r2, [sp, 0x8C]
	bl GetMonData
	ldr r0, [sp, 0x84]
	ldr r1, [sp, 0x8C]
	bl StringCopy10
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, [sp, 0x88]
	bl GetMonData
	mov r2, sp
	movs r6, 0
_081BC00C:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _081BC00C
	b _081BC46E
	.pool
_081BC02C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	b _081BC3A6
	.pool
_081BC03C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	b _081BC3A6
	.pool
_081BC04C:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	mov r8, r9
_081BC062:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	mov r2, r10
	adds r1, r2, r6
	strb r0, [r1]
	movs r0, 0x2
	add r8, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _081BC062
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_081BC0A0:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _081BC0A0
	b _081BC46E
	.pool
_081BC0B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _081BC3A6
	.pool
_081BC0D0:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gPlayerParty
	mov r8, r2
_081BC0DC:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _081BC0DC
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _081BC46E
	.pool
_081BC10C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _081BC466
	.pool
_081BC128:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	b _081BC142
	.pool
_081BC138:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x19
_081BC142:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	movs r6, 0x3
	b _081BC46E
	.pool
_081BC168:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1A
	b _081BC466
	.pool
_081BC178:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1B
	b _081BC466
	.pool
_081BC188:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1C
	b _081BC466
	.pool
_081BC198:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1D
	b _081BC466
	.pool
_081BC1A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1E
	b _081BC466
	.pool
_081BC1B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1F
	b _081BC466
	.pool
_081BC1C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x20
	b _081BC466
	.pool
_081BC1D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x22
	b _081BC466
	.pool
_081BC1E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x23
	b _081BC466
	.pool
_081BC1F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x24
	b _081BC466
	.pool
_081BC208:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x25
	b _081BC466
	.pool
_081BC218:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x26
	b _081BC466
	.pool
_081BC228:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	strb r0, [r7, 0x1]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	strb r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	strb r0, [r7, 0x3]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	strb r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	strb r0, [r7, 0x5]
	movs r6, 0x6
	b _081BC46E
	.pool
_081BC278:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x27
	b _081BC466
	.pool
_081BC288:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x28
	b _081BC466
	.pool
_081BC298:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x29
	b _081BC466
	.pool
_081BC2A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2A
	b _081BC466
	.pool
_081BC2B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2B
	b _081BC466
	.pool
_081BC2C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2C
	b _081BC466
	.pool
_081BC2D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	b _081BC302
	.pool
_081BC2E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x9
	b _081BC3A6
	.pool
_081BC2F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x37
_081BC302:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	lsrs r0, r1, 24
	strb r0, [r7, 0x3]
	movs r6, 0x4
	b _081BC46E
	.pool
_081BC32C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	b _081BC466
	.pool
_081BC33C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	b _081BC3A6
	.pool
_081BC34C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	b _081BC3A6
	.pool
_081BC35C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3B
	b _081BC3A6
	.pool
_081BC36C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3C
	b _081BC3A6
	.pool
_081BC37C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3D
	b _081BC3A6
	.pool
_081BC38C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3E
	b _081BC3A6
	.pool
_081BC39C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3F
_081BC3A6:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _081BC46E
	.pool
_081BC3BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	b _081BC466
	.pool
_081BC3CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	b _081BC466
	.pool
_081BC3DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	b _081BC466
	.pool
_081BC3EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	b _081BC466
	.pool
_081BC3FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	b _081BC466
	.pool
_081BC40C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	b _081BC466
	.pool
_081BC41C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _081BC466
	.pool
_081BC42C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _081BC466
	.pool
_081BC43C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _081BC466
	.pool
_081BC44C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _081BC466
	.pool
_081BC45C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_081BC466:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_081BC46E:
	adds r0, r6, 0
	add sp, 0x90
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end dp01_getattr_by_ch1_for_player_pokemon

	thumb_func_start sub_81BC484
sub_81BC484: @ 81BC484
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BC484

	thumb_func_start sub_81BC490
sub_81BC490: @ 81BC490
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _081BC4C0
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_81BC4E8
	b _081BC4DE
	.pool
_081BC4C0:
	ldrb r4, [r1]
	movs r5, 0
_081BC4C4:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _081BC4D2
	adds r0, r5, 0
	bl sub_81BC4E8
_081BC4D2:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _081BC4C4
_081BC4DE:
	bl PlayerPartnerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81BC490

	thumb_func_start sub_81BC4E8
sub_81BC4E8: @ 81BC4E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r2, =gBattleBufferA + 3
	adds r3, r0, r2
	adds r6, r3, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r7, r2, 0
	cmp r0, 0x3B
	bls _081BC514
	bl _081BCEAE
_081BC514:
	lsls r0, 2
	ldr r1, =_081BC52C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BC52C:
	.4byte _081BC61C
	.4byte _081BC7B4
	.4byte _081BC7D4
	.4byte _081BC7F4
	.4byte _081BC84C
	.4byte _081BC84C
	.4byte _081BC84C
	.4byte _081BC84C
	.4byte _081BC874
	.4byte _081BC8D8
	.4byte _081BC8D8
	.4byte _081BC8D8
	.4byte _081BC8D8
	.4byte _081BCEAE
	.4byte _081BCEAE
	.4byte _081BCEAE
	.4byte _081BCEAE
	.4byte _081BC908
	.4byte _081BC928
	.4byte _081BC948
	.4byte _081BC968
	.4byte _081BC988
	.4byte _081BC9A8
	.4byte _081BC9C8
	.4byte _081BC9E8
	.4byte _081BCA08
	.4byte _081BCA28
	.4byte _081BCA48
	.4byte _081BCA68
	.4byte _081BCA88
	.4byte _081BCAA8
	.4byte _081BCAC8
	.4byte _081BCB38
	.4byte _081BCB58
	.4byte _081BCB78
	.4byte _081BCB98
	.4byte _081BCBB8
	.4byte _081BCBD8
	.4byte _081BCBF8
	.4byte _081BCC18
	.4byte _081BCC38
	.4byte _081BCC58
	.4byte _081BCC78
	.4byte _081BCC98
	.4byte _081BCCB8
	.4byte _081BCCD8
	.4byte _081BCCF8
	.4byte _081BCD18
	.4byte _081BCD38
	.4byte _081BCD58
	.4byte _081BCD78
	.4byte _081BCD98
	.4byte _081BCDB8
	.4byte _081BCDD8
	.4byte _081BCDF8
	.4byte _081BCE18
	.4byte _081BCE38
	.4byte _081BCE58
	.4byte _081BCE78
	.4byte _081BCE98
_081BC61C:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r6, 0
	bl SetMonData
	adds r2, r6, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r6
	mov r10, r0
	adds r0, r6, 0
	adds r0, 0x2B
	str r0, [sp, 0x20]
	adds r0, 0x19
	str r0, [sp, 0x28]
	adds r0, 0x4
	str r0, [sp, 0x2C]
	adds r0, 0x4
	str r0, [sp, 0x30]
	subs r0, 0x22
	str r0, [sp, 0x1C]
	subs r0, 0x2
	str r0, [sp, 0x18]
	adds r0, 0x4
	str r0, [sp, 0x24]
	adds r0, r6, 0x2
	str r0, [sp, 0x4]
	adds r0, r6, 0x4
	str r0, [sp, 0x8]
	adds r0, r6, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r7, r6, 0
	adds r7, 0x24
	adds r4, r6, 0
	adds r4, 0xC
_081BC682:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r7, 0
	bl SetMonData
	adds r7, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _081BC682
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	mov r2, r10
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x20]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x19
	ldr r2, [sp, 0x28]
	bl SetMonData
	ldrb r0, [r6, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r6, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r6, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldr r0, [r6, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r6, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r6, 0x17]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2C
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0
	ldr r2, [sp, 0x2C]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x37
	ldr r2, [sp, 0x30]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x38
	ldr r2, [sp, 0x1C]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x39
	ldr r2, [sp, 0x18]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3A
	ldr r2, [sp, 0x24]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3B
	ldr r2, [sp, 0x4]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3C
	ldr r2, [sp, 0x8]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3D
	ldr r2, [sp, 0xC]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3E
	ldr r2, [sp, 0x10]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3F
	ldr r2, [sp, 0x14]
	bl SetMonData
	b _081BCEAE
	.pool
_081BC7B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0xB
	bl SetMonData
	b _081BCEAE
	.pool
_081BC7D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0xC
	bl SetMonData
	b _081BCEAE
	.pool
_081BC7F4:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r3
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r6, r3, 0
	adds r6, 0x8
	adds r4, r3, 0
_081BC80E:
	mov r1, r8
	adds r1, 0xD
	adds r0, r7, 0
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	adds r0, r7, 0
	adds r2, r6, 0
	bl SetMonData
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _081BC80E
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _081BCEAE
	.pool
_081BC84C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gBattleBufferA
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _081BC8F0
	.pool
_081BC874:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	lsls r2, 9
	adds r2, r7
	adds r0, r4, 0
	movs r1, 0x11
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl SetMonData
	b _081BCEAE
	.pool
_081BC8D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gBattleBufferA
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_081BC8F0:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _081BCEAE
	.pool
_081BC908:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1
	bl SetMonData
	b _081BCEAE
	.pool
_081BC928:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x19
	bl SetMonData
	b _081BCEAE
	.pool
_081BC948:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1A
	bl SetMonData
	b _081BCEAE
	.pool
_081BC968:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1B
	bl SetMonData
	b _081BCEAE
	.pool
_081BC988:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1C
	bl SetMonData
	b _081BCEAE
	.pool
_081BC9A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1D
	bl SetMonData
	b _081BCEAE
	.pool
_081BC9C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1E
	bl SetMonData
	b _081BCEAE
	.pool
_081BC9E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1F
	bl SetMonData
	b _081BCEAE
	.pool
_081BCA08:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x20
	bl SetMonData
	b _081BCEAE
	.pool
_081BCA28:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x22
	bl SetMonData
	b _081BCEAE
	.pool
_081BCA48:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x23
	bl SetMonData
	b _081BCEAE
	.pool
_081BCA68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x24
	bl SetMonData
	b _081BCEAE
	.pool
_081BCA88:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x25
	bl SetMonData
	b _081BCEAE
	.pool
_081BCAA8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x26
	bl SetMonData
	b _081BCEAE
	.pool
_081BCAC8:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	lsls r2, 9
	adds r2, r7
	adds r0, r4, 0
	movs r1, 0x27
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _081BCBE8
	.pool
_081BCB38:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x27
	bl SetMonData
	b _081BCEAE
	.pool
_081BCB58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x28
	bl SetMonData
	b _081BCEAE
	.pool
_081BCB78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x29
	bl SetMonData
	b _081BCEAE
	.pool
_081BCB98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2A
	bl SetMonData
	b _081BCEAE
	.pool
_081BCBB8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2B
	bl SetMonData
	b _081BCEAE
	.pool
_081BCBD8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
_081BCBE8:
	movs r1, 0x2C
	bl SetMonData
	b _081BCEAE
	.pool
_081BCBF8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0
	bl SetMonData
	b _081BCEAE
	.pool
_081BCC18:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x9
	bl SetMonData
	b _081BCEAE
	.pool
_081BCC38:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x37
	bl SetMonData
	b _081BCEAE
	.pool
_081BCC58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x38
	bl SetMonData
	b _081BCEAE
	.pool
_081BCC78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x39
	bl SetMonData
	b _081BCEAE
	.pool
_081BCC98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3A
	bl SetMonData
	b _081BCEAE
	.pool
_081BCCB8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3B
	bl SetMonData
	b _081BCEAE
	.pool
_081BCCD8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3C
	bl SetMonData
	b _081BCEAE
	.pool
_081BCCF8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3D
	bl SetMonData
	b _081BCEAE
	.pool
_081BCD18:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3E
	bl SetMonData
	b _081BCEAE
	.pool
_081BCD38:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3F
	bl SetMonData
	b _081BCEAE
	.pool
_081BCD58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x16
	bl SetMonData
	b _081BCEAE
	.pool
_081BCD78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x17
	bl SetMonData
	b _081BCEAE
	.pool
_081BCD98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x18
	bl SetMonData
	b _081BCEAE
	.pool
_081BCDB8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x21
	bl SetMonData
	b _081BCEAE
	.pool
_081BCDD8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2F
	bl SetMonData
	b _081BCEAE
	.pool
_081BCDF8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x30
	bl SetMonData
	b _081BCEAE
	.pool
_081BCE18:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x32
	bl SetMonData
	b _081BCEAE
	.pool
_081BCE38:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x33
	bl SetMonData
	b _081BCEAE
	.pool
_081BCE58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x34
	bl SetMonData
	b _081BCEAE
	.pool
_081BCE78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x35
	bl SetMonData
	b _081BCEAE
	.pool
_081BCE98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x36
	bl SetMonData
_081BCEAE:
	ldr r2, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BC4E8

	thumb_func_start sub_81BCEE4
sub_81BCEE4: @ 81BCEE4
	push {r4-r7,lr}
	ldr r1, =gBattlePartyID
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	adds r3, r1, 0
	muls r3, r0
	ldr r4, =gBattleBufferA
	lsls r2, 9
	adds r0, r4, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r5, r3, r0
	movs r3, 0
	adds r0, r4, 0x2
	adds r2, r0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _081BCF3C
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_081BCF1A:
	adds r1, r5, r3
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, 0x3
	adds r0, r3, r0
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r3, r0
	bcc _081BCF1A
_081BCF3C:
	bl PlayerPartnerBufferExecCompleted
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BCEE4

	thumb_func_start sub_81BCF58
sub_81BCF58: @ 81BCF58
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gBattlePartyID
	mov r8, r0
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	lsls r0, r1, 1
	add r0, r8
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	bl sub_805DD7C
	ldrb r0, [r6]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0xB
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r8, r0
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r6]
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	adds r1, r5, 0
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, =gBankSpriteIds
	ldrb r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r5, =gSprites
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ff10
	strh r1, [r0, 0x24]
	ldrb r2, [r6]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x2E]
	ldrb r3, [r6]
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r2, [r6]
	adds r4, r2, r4
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gBattleMonForms
	adds r2, r1
	ldrb r1, [r2]
	bl StartSpriteAnim
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB1D4
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BCF58

	thumb_func_start sub_81BD074
sub_81BD074: @ 81BD074
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r4, =gBattleBufferA
	lsls r1, r0, 9
	adds r6, r4, 0x2
	adds r1, r6
	ldrb r1, [r1]
	bl sub_805EF84
	ldr r2, =gBattlePartyID
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r2
	lsls r0, 9
	adds r4, 0x1
	adds r0, r4
	ldrb r0, [r0]
	strh r0, [r1]
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805DD7C
	ldrb r0, [r5]
	lsls r1, r0, 9
	adds r1, r6
	ldrb r1, [r1]
	bl sub_81BD0E4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BBAE8
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD074

	thumb_func_start sub_81BD0E4
sub_81BD0E4: @ 81BD0E4
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_805EF84
	ldr r0, =gBattlePartyID
	lsls r2, r6, 1
	adds r2, r0
	ldr r0, =gBattleBufferA
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r2]
	ldrh r1, [r2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =sub_805D714
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gUnknown_03005D7C
	mov r9, r1
	add r9, r6
	mov r1, r9
	strb r0, [r1]
	adds r0, r6, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r10, r0
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r10
	adds r1, r5, 0
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, =gBankSpriteIds
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, =gSprites
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r6, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gBattleMonForms
	adds r6, r1
	ldrb r1, [r6]
	bl StartSpriteAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	movs r0, 0
	movs r1, 0xFF
	bl sub_80753E8
	mov r1, r9
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x2E]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD0E4

	thumb_func_start sub_81BD260
sub_81BD260: @ 81BD260
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _081BD2A8
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strb r3, [r0, 0x4]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BD2F0
	str r1, [r0]
	b _081BD2DE
	.pool
_081BD2A8:
	ldr r5, =gBankSpriteIds
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, =gHealthBoxesIds
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl PlayerPartnerBufferExecCompleted
_081BD2DE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD260

	thumb_func_start sub_81BD2F0
sub_81BD2F0: @ 81BD2F0
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r4, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	beq _081BD318
	cmp r0, 0x1
	beq _081BD346
	b _081BD36E
	.pool
_081BD318:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081BD332
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_081BD332:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _081BD36E
_081BD346:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _081BD36E
	strb r0, [r3, 0x4]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x1
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB828
	str r1, [r0]
_081BD36E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD2F0

	thumb_func_start sub_81BD37C
sub_81BD37C: @ 81BD37C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, =gUnknown_02038BCE
	ldrh r1, [r2]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _081BD3A8
	movs r4, 0x7
	movs r0, 0x5A
	mov r9, r0
	ldr r0, =gUnknown_08305D2C
	ldrb r1, [r0, 0x1C]
	b _081BD3BE
	.pool
_081BD3A8:
	ldrh r0, [r2]
	bl sub_8162AA0
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x20
	mov r9, r0
	ldr r1, =gUnknown_083054E0
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
_081BD3BE:
	movs r0, 0x8
	subs r0, r1
	lsls r0, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r0, r1
	lsrs r7, r0, 16
	ldr r0, =gUnknown_02038BCE
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _081BD494
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_805DF84
	ldrb r0, [r5]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	mov r8, r9
	lsls r4, r7, 16
	asrs r4, 16
	ldrb r0, [r5]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	bl CreateSprite
	ldr r6, =gBankSpriteIds
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gSprites
	ldrb r3, [r5]
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xF0
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	b _081BD57C
	.pool
_081BD494:
	adds r5, r4, 0
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	adds r0, r5, 0
	bl sub_805DF38
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806A1C0
	ldr r0, =gUnknown_0202499C
	mov r8, r0
	lsls r4, r7, 16
	asrs r4, 16
	ldrb r0, [r6]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	mov r1, r9
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, =gBankSpriteIds
	ldrb r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r0, =gTrainerFrontPicPaletteTable
	lsls r5, 3
	adds r5, r0
	ldrh r0, [r5, 0x4]
	bl IndexOfSpritePaletteTag
	ldr r5, =gSprites
	ldrb r1, [r6]
	adds r1, r4
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r5
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0xF0
	strh r1, [r0, 0x24]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x30
	strh r1, [r0, 0x26]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
_081BD57C:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BAE60
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD37C

	thumb_func_start sub_81BD5BC
sub_81BD5BC: @ 81BD5BC
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BD5BC

	thumb_func_start sub_81BD5C8
sub_81BD5C8: @ 81BD5C8
	push {r4-r6,lr}
	ldr r6, =gBankSpriteIds
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =SpriteCallbackDummy
	bl StoreSpriteCallbackInData6
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BAE98
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD5C8

	thumb_func_start sub_81BD674
sub_81BD674: @ 81BD674
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r0, [r4, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	bne _081BD6C8
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081BD6A8
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_081BD6A8:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	adds r1, 0x1
	strb r1, [r0, 0x4]
	b _081BD73E
	.pool
_081BD6C8:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081BD73E
	strb r4, [r3, 0x4]
	ldr r2, =gBattlePartyID
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	movs r1, 0x40
	negs r1, r1
	movs r0, 0x10
	bl PlaySE12WithPanning
	ldr r2, =gSprites
	ldr r3, =gBankSpriteIds
	ldrb r0, [r5]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r4, [r0, 0x30]
	ldrb r0, [r5]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x5
	strh r1, [r0, 0x32]
	ldrb r0, [r5]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039C00
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB78C
	str r1, [r0]
_081BD73E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD674

	thumb_func_start sub_81BD760
sub_81BD760: @ 81BD760
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BD760

	thumb_func_start sub_81BD76C
sub_81BD76C: @ 81BD76C
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BD76C

	thumb_func_start sub_81BD778
sub_81BD778: @ 81BD778
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BD778

	thumb_func_start sub_81BD784
sub_81BD784: @ 81BD784
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BD784

	thumb_func_start sub_81BD790
sub_81BD790: @ 81BD790
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _081BD7A2
	b _081BD8B6
_081BD7A2:
	ldr r0, =gBattleBufferA
	mov r12, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r0, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	mov r1, r12
	adds r1, 0x2
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	ldr r5, =gUnknown_02038432
	mov r1, r12
	adds r1, 0x3
	adds r2, r1
	ldrb r1, [r2]
	strb r1, [r5]
	ldr r4, =gMovePowerMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x4
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x5
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r4, =gMoveDmgMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x6
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x7
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r3, r1
	mov r1, r12
	adds r1, 0x8
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 16
	orrs r3, r1
	mov r1, r12
	adds r1, 0x9
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 24
	orrs r3, r1
	str r3, [r4]
	ldr r3, =gHappinessMoveAnim
	ldrb r1, [r6]
	lsls r1, 9
	mov r2, r12
	adds r2, 0xA
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r3]
	ldr r4, =gWeatherMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0xC
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0xD
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r3, =gDisableStructMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x10
	adds r2, r1
	str r2, [r3]
	ldr r3, =gUnknown_020244BC
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r3
	ldr r2, [r2]
	str r2, [r1]
	ldrb r1, [r5]
	bl sub_805DB8C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _081BD898
	bl PlayerPartnerBufferExecCompleted
	b _081BD8B6
	.pool
_081BD898:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x4]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_move_anim_3
	str r1, [r0]
_081BD8B6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BD790

	thumb_func_start bx_move_anim_3
bx_move_anim_3: @ 81BD8C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	lsls r1, r3, 9
	adds r0, r2, 0x1
	mov r10, r0
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, r2, 0x2
	mov r9, r5
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	adds r2, 0xB
	adds r1, r2
	ldrb r1, [r1]
	mov r8, r1
	ldr r7, =gUnknown_020244D0
	ldr r5, [r7]
	ldr r1, [r5, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _081BD960
	cmp r2, 0x1
	bgt _081BD920
	cmp r2, 0
	beq _081BD92A
	b _081BDA3C
	.pool
_081BD920:
	cmp r2, 0x2
	beq _081BD98A
	cmp r2, 0x3
	beq _081BDA00
	b _081BDA3C
_081BD92A:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _081BD94C
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_081BD94C:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _081BDA3C
_081BD960:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _081BDA3C
	movs r0, 0
	bl sub_805EB9C
	adds r0, r4, 0
	bl move_anim_start_t1
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0, 0x4]
	b _081BDA3C
_081BD98A:
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _081BDA3C
	movs r0, 0x1
	bl sub_805EB9C
	ldr r0, [r7]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081BD9D8
	mov r0, r8
	cmp r0, 0x1
	bhi _081BD9D8
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_081BD9D8:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x4]
	b _081BDA3C
	.pool
_081BDA00:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081BDA3C
	bl sub_805E394
	ldrb r0, [r6]
	lsls r2, r0, 9
	mov r3, r10
	adds r1, r2, r3
	ldrb r1, [r1]
	add r2, r9
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	bl sub_805E94C
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r4, [r0, 0x4]
	bl PlayerPartnerBufferExecCompleted
_081BDA3C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_3

	thumb_func_start sub_81BDA4C
sub_81BDA4C: @ 81BDA4C
	push {r4,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	ldr r1, =gBattleBufferA + 2
	adds r0, r1
	ldrh r0, [r0]
	bl BufferStringBattle
	ldr r0, =gDisplayedStringBattle
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB898
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDA4C

	thumb_func_start sub_81BDAA0
sub_81BDAA0: @ 81BDAA0
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDAA0

	thumb_func_start sub_81BDAAC
sub_81BDAAC: @ 81BDAAC
	push {lr}
	bl sub_8063880
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDAAC

	thumb_func_start sub_81BDABC
sub_81BDABC: @ 81BDABC
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDABC

	thumb_func_start sub_81BDAC8
sub_81BDAC8: @ 81BDAC8
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r4, [r6]
	lsls r4, 9
	ldr r0, =gBattleBufferA + 4
	adds r4, r0
	movs r0, 0xF
	bl BattleAI_SetupAIData
	bl BattleAI_ChooseMoveOrAction
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gBattleMoves
	lsls r0, r5, 1
	adds r4, r0
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x6]
	movs r0, 0x12
	ands r0, r1
	cmp r0, 0
	beq _081BDB02
	ldr r1, =gBankTarget
	ldrb r0, [r6]
	strb r0, [r1]
_081BDB02:
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x6]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081BDB3C
	movs r0, 0x1
	bl GetBankByPlayerAI
	ldr r4, =gBankTarget
	strb r0, [r4]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _081BDB3C
	movs r0, 0x3
	bl GetBankByPlayerAI
	strb r0, [r4]
_081BDB3C:
	ldr r0, =gBankTarget
	ldrb r2, [r0]
	lsls r2, 8
	orrs r2, r5
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	bl PlayerPartnerBufferExecCompleted
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDAC8

	thumb_func_start sub_81BDB70
sub_81BDB70: @ 81BDB70
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDB70

	thumb_func_start sub_81BDB7C
sub_81BDB7C: @ 81BDB7C
	push {r4-r6,lr}
	bl sub_8063A90
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bne _081BDBD0
	movs r0, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0x3
	b _081BDBA4
_081BDBA2:
	adds r4, 0x1
_081BDBA4:
	cmp r4, 0x5
	bgt _081BDBD0
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _081BDBA2
	ldr r1, =gBattlePartyID
	lsls r0, r6, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _081BDBA2
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _081BDBA2
_081BDBD0:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x5C
	strb r4, [r0]
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl PlayerPartnerBufferExecCompleted
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDB7C

	thumb_func_start sub_81BDC04
sub_81BDC04: @ 81BDC04
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDC04

	thumb_func_start sub_81BDC10
sub_81BDC10: @ 81BDC10
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl load_gfxc_health_bar
	ldr r3, =gBattleBufferA
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r4, [r0]
	lsls r2, r4, 9
	adds r0, r3, 0x2
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r3, 0x3
	adds r2, r3
	ldrb r0, [r2]
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	asrs r7, r1, 16
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _081BDCA0
	ldr r6, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gHealthBoxesIds
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_807294C
	b _081BDCCA
	.pool
_081BDCA0:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gHealthBoxesIds
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
_081BDCCA:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t3_healthbar_update
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDC10

	thumb_func_start sub_81BDD00
sub_81BDD00: @ 81BDD00
	push {r4-r7,lr}
	ldr r5, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 9
	adds r1, r5, 0x1
	adds r0, r1
	ldrb r7, [r0]
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x63
	bls _081BDD38
	bl PlayerPartnerBufferExecCompleted
	b _081BDD84
	.pool
_081BDD38:
	movs r0, 0x1
	bl load_gfxc_health_bar
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 9
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r0, r5, 0x3
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	ldr r0, =sub_81BB29C
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r7, [r1, 0x8]
	strh r4, [r1, 0xA]
	ldrb r0, [r6]
	strh r0, [r1, 0xC]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_21
	str r1, [r0]
_081BDD84:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDD00

	thumb_func_start sub_81BDD9C
sub_81BDD9C: @ 81BDD9C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _081BDDF0
	ldr r0, =gHealthBoxesIds
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0x9
	bl healthbar_draw_field_maybe
	ldrb r2, [r4]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BBC04
	str r1, [r0]
_081BDDF0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDD9C

	thumb_func_start sub_81BDE14
sub_81BDE14: @ 81BDE14
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _081BDE64
	ldr r4, =gBattleBufferA
	ldrb r3, [r5]
	lsls r3, 9
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	adds r2, r4, 0x4
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 16
	orrs r1, r2
	adds r4, 0x5
	adds r3, r4
	ldrb r2, [r3]
	lsls r2, 24
	orrs r1, r2
	bl move_anim_start_t2_for_situation
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BBC04
	str r1, [r0]
_081BDE64:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDE14

	thumb_func_start sub_81BDE7C
sub_81BDE7C: @ 81BDE7C
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDE7C

	thumb_func_start sub_81BDE88
sub_81BDE88: @ 81BDE88
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDE88

	thumb_func_start sub_81BDE94
sub_81BDE94: @ 81BDE94
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDE94

	thumb_func_start sub_81BDEA0
sub_81BDEA0: @ 81BDEA0
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEA0

	thumb_func_start sub_81BDEAC
sub_81BDEAC: @ 81BDEAC
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEAC

	thumb_func_start sub_81BDEB8
sub_81BDEB8: @ 81BDEB8
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEB8

	thumb_func_start sub_81BDEC4
sub_81BDEC4: @ 81BDEC4
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEC4

	thumb_func_start sub_81BDED0
sub_81BDED0: @ 81BDED0
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDED0

	thumb_func_start sub_81BDEDC
sub_81BDEDC: @ 81BDEDC
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEDC

	thumb_func_start sub_81BDEE8
sub_81BDEE8: @ 81BDEE8
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDEE8

	thumb_func_start sub_81BDF04
sub_81BDF04: @ 81BDF04
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x7F
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDF04

	thumb_func_start sub_81BDF3C
sub_81BDF3C: @ 81BDF3C
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDF3C

	thumb_func_start sub_81BDF54
sub_81BDF54: @ 81BDF54
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, [r3]
	lsls r1, 24
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 7
	ldrb r2, [r3]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDF54

	thumb_func_start dp01t_29_3_blink
dp01t_29_3_blink: @ 81BDF7C
	push {r4,lr}
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _081BDFB0
	bl PlayerPartnerBufferExecCompleted
	b _081BDFDA
	.pool
_081BDFB0:
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	bl sub_80769F4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_blink_t3
	str r1, [r0]
_081BDFDA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_29_3_blink

	thumb_func_start sub_81BDFEC
sub_81BDFEC: @ 81BDFEC
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BDFEC

	thumb_func_start sub_81BDFF8
sub_81BDFF8: @ 81BDFF8
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _081BE00C
	movs r3, 0xC0
_081BE00C:
	ldr r2, =gBattleBufferA
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	lsls r1, r3, 24
	asrs r1, 24
	bl PlaySE12WithPanning
	bl PlayerPartnerBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDFF8

	thumb_func_start sub_81BE03C
sub_81BE03C: @ 81BE03C
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _081BE078
	bl sub_805EA60
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, r4, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayBGM
	b _081BE08C
	.pool
_081BE078:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayFanfare
_081BE08C:
	bl PlayerPartnerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81BE03C

	thumb_func_start sub_81BE098
sub_81BE098: @ 81BE098
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	negs r1, r1
	movs r2, 0x5
	bl PlayCry3
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE098

	thumb_func_start dp01t_2E_3_battle_intro
dp01t_2E_3_battle_intro: @ 81BE0D8
	push {lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl battle_intro_launch
	ldr r2, =gUnknown_020243FC
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_3_battle_intro

	thumb_func_start sub_81BE10C
sub_81BE10C: @ 81BE10C
	push {r4-r6,lr}
	ldr r6, =gBankSpriteIds
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x32
	strh r1, [r0, 0x2E]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r2, [r5]
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x38]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_805CC00
	bl StoreSpriteCallbackInData6
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, =0x0000d6f9
	bl AllocSpritePalette
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gUnknown_02038BCE
	ldrh r1, [r2]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _081BE1FC
	ldr r0, =gTrainerBackPicPaletteTable
	ldr r0, [r0, 0x38]
	lsls r4, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0x20
	bl LoadCompressedPalette
	b _081BE21A
	.pool
_081BE1FC:
	ldrh r0, [r2]
	bl sub_8162AA0
	lsls r0, 24
	ldr r1, =gTrainerFrontPicPaletteTable
	lsrs r0, 21
	adds r0, r1
	ldr r0, [r0]
	lsls r4, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0x20
	bl LoadCompressedPalette
_081BE21A:
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r4
	strb r0, [r1, 0x5]
	ldr r0, =sub_81BE2C8
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r5]
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BE27E
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_081BE27E:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_77
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE10C

	thumb_func_start sub_81BE2C8
sub_81BE2C8: @ 81BE2C8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0x17
	bgt _081BE2F4
	adds r0, r2, 0x1
	strh r0, [r1, 0xA]
	b _081BE3B0
	.pool
_081BE2F4:
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldrh r0, [r1, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081BE314
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081BE344
_081BE314:
	ldr r0, =gBattleBufferA
	ldrb r1, [r7]
	lsls r2, r1, 9
	adds r0, 0x1
	adds r2, r0
	ldr r0, =gBattlePartyID
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strb r0, [r2]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_81BD0E4
	b _081BE398
	.pool
_081BE344:
	ldr r4, =gBattleBufferA
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r4, 0x1
	adds r1, r4
	ldr r5, =gBattlePartyID
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_81BD0E4
	ldrb r0, [r7]
	movs r6, 0x2
	eors r0, r6
	strb r0, [r7]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r4
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r1, [r7]
	lsls r0, r1, 1
	adds r0, r5
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805DD7C
	ldrb r0, [r7]
	movs r1, 0
	bl sub_81BD0E4
	ldrb r0, [r7]
	eors r0, r6
	strb r0, [r7]
_081BE398:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81BB02C
	str r1, [r0]
	mov r3, r9
	strb r3, [r2]
	mov r0, r8
	bl DestroyTask
_081BE3B0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE2C8

	thumb_func_start dp01t_30_3_80EB11C
dp01t_30_3_80EB11C: @ 81BE3D4
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081BE404
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _081BE404
	bl PlayerPartnerBufferExecCompleted
	b _081BE478
	.pool
_081BE404:
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r3, r0, 9
	ldr r4, =gBattleBufferA + 4
	adds r1, r3, r4
	subs r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	subs r4, 0x2
	adds r3, r4
	ldrb r3, [r3]
	bl sub_80735DC
	ldr r2, =gUnknown_020244B4
	ldrb r1, [r5]
	adds r1, r2
	movs r3, 0
	strb r0, [r1]
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x5]
	ldrb r2, [r5]
	lsls r0, r2, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081BE46C
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_081BE46C:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_81BE498
	str r0, [r1]
_081BE478:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_30_3_80EB11C

	thumb_func_start sub_81BE498
sub_81BE498: @ 81BE498
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	adds r2, r1, 0x1
	strb r2, [r0, 0x5]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x5C
	bls _081BE4D0
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl PlayerPartnerBufferExecCompleted
_081BE4D0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE498

	thumb_func_start sub_81BE4E0
sub_81BE4E0: @ 81BE4E0
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BE512
	ldr r2, =gTasks
	ldr r0, =gUnknown_020244B4
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_8073C30
	str r1, [r0]
_081BE512:
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE4E0

	thumb_func_start sub_81BE530
sub_81BE530: @ 81BE530
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BE530

	thumb_func_start sub_81BE53C
sub_81BE53C: @ 81BE53C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _081BE582
	ldr r3, =gSprites
	ldr r0, =gBankSpriteIds
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldr r0, =gBattleBufferA
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r1, [r1]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	bl sub_805E408
_081BE582:
	bl PlayerPartnerBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE53C

	thumb_func_start sub_81BE59C
sub_81BE59C: @ 81BE59C
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _081BE5F4
	ldr r5, =gBattleBufferA
	ldrb r2, [r6]
	lsls r1, r2, 9
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, 0x3
	adds r1, r5
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	str r4, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _081BE5E8
	bl PlayerPartnerBufferExecCompleted
	b _081BE5F4
	.pool
_081BE5E8:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_80E8A6C
	str r0, [r1]
_081BE5F4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE59C

	thumb_func_start sub_81BE604
sub_81BE604: @ 81BE604
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BE604

	thumb_func_start sub_81BE610
sub_81BE610: @ 81BE610
	push {lr}
	bl PlayerPartnerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81BE610

	thumb_func_start sub_81BE61C
sub_81BE61C: @ 81BE61C
	push {r4,lr}
	ldr r2, =gBattleOutcome
	ldr r1, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0x5
	bl FadeOutMapMusic
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl PlayerPartnerBufferExecCompleted
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80587B0
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE61C

	thumb_func_start nullsub_128
nullsub_128: @ 81BE668
	bx lr
	thumb_func_end nullsub_128

  	.align 2, 0 @ Don't pad with nop.
