	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81BAD84
sub_81BAD84: @ 81BAD84
	push {r4-r6,lr}
	movs r6, 0x80
	lsls r6, 19
	movs r2, 0
	strh r2, [r6]
	ldr r1, =0x04000010
	strh r2, [r1]
	adds r1, 0x2
	strh r2, [r1]
	adds r1, 0x3E
	strh r2, [r1]
	ldr r5, =gUnknown_08617128
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r0, r4, r5
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	adds r5, 0x8
	adds r4, r5
	ldr r0, [r4]
	movs r1, 0xA0
	lsls r1, 19
	movs r4, 0x80
	lsls r4, 1
	adds r2, r4, 0
	bl CpuSet
	ldr r1, =0x04000008
	movs r2, 0xF8
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	strh r4, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BAD84

	thumb_func_start nullsub_77
nullsub_77: @ 81BADF0
	bx lr
	thumb_func_end nullsub_77

	thumb_func_start sub_81BADF4
sub_81BADF4: @ 81BADF4
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl3
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81BADF4

	thumb_func_start bx_exec_buffer_A_ch0_tbl3
bx_exec_buffer_A_ch0_tbl3: @ 81BAE10
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
	ldr r0, =gUnknown_08617170
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _081BAE5C
	.pool
_081BAE58:
	bl dp01_tbl3_exec_completed
_081BAE5C:
	pop {r0}
	bx r0
	thumb_func_end bx_exec_buffer_A_ch0_tbl3

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
	bl dp01_tbl3_exec_completed
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
	bl obj_free_rotscale_entry
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	ldr r1, =gUnknown_03005D70
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
	ldr r5, =gUnknown_03005D70
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
	bl sub_80A36C8
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
	ldr r4, =gUnknown_03005D70
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
	ldr r5, =gUnknown_03005D70
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
	bl dp01_tbl3_exec_completed
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
	ldr r6, =gUnknown_03005D70
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl pokemon_calc_effective_stats
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
	ldr r0, =gUnknown_03005D70
	add r0, r10
	ldrb r1, [r0]
	mov r0, r9
	negs r0, r0
	str r0, [sp]
	mov r0, r10
	bl sub_807294C
	movs r0, 0x21
	bl audio_play
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
	ldr r5, =gUnknown_03005D70
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
	bl pokemon_calc_effective_stats
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
	ldr r0, =gUnknown_03005D70
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, r7, 0
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _081BB71C
	.pool
_081BB708:
	ldr r0, =gUnknown_03005D70
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
	bl rotscale_free_entry
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl3_exec_completed
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
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	ldr r0, =gUnknown_03005D70
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
	bl dp01_tbl3_exec_completed
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
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
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
	bl StartObjectImageAnim
	ldr r4, =gUnknown_03005D70
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

	thumb_func_start dp01_tbl3_exec_completed
dp01_tbl3_exec_completed: @ 81BBB8C
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl3
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081BBBE0
	bl link_get_multiplayer_id
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
	thumb_func_end dp01_tbl3_exec_completed

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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	ldr r2, =gUnknown_02023067
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
	bl dp01_tbl3_exec_completed
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
	ldr r1, =gUnknown_020244E4
	adds r2, r1
	ldrb r1, [r2]
	bl StartObjectImageAnim
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
	ldr r1, =gUnknown_020244E4
	adds r6, r1
	ldrb r1, [r6]
	bl StartObjectImageAnim
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
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl oamt_set_x3A_32
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
	bl audio_play_and_stuff
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
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BD760

	thumb_func_start sub_81BD76C
sub_81BD76C: @ 81BD76C
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BD76C

	thumb_func_start sub_81BD778
sub_81BD778: @ 81BD778
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BD778

	thumb_func_start sub_81BD784
sub_81BD784: @ 81BD784
	push {lr}
	bl dp01_tbl3_exec_completed
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
	ldr r4, =gUnknown_02038408
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
	ldr r4, =gUnknown_02038404
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
	ldr r3, =gUnknown_0203841A
	ldrb r1, [r6]
	lsls r1, 9
	mov r2, r12
	adds r2, 0xA
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r3]
	ldr r4, =gUnknown_0203841C
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
	ldr r3, =gUnknown_02038400
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
	bl dp01_tbl3_exec_completed
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
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
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
	bl dp01_tbl3_exec_completed
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
	ldr r1, =gUnknown_02023066
	adds r0, r1
	ldrh r0, [r0]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
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
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDAA0

	thumb_func_start sub_81BDAAC
sub_81BDAAC: @ 81BDAAC
	push {lr}
	bl sub_8063880
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDAAC

	thumb_func_start sub_81BDABC
sub_81BDABC: @ 81BDABC
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDABC

	thumb_func_start sub_81BDAC8
sub_81BDAC8: @ 81BDAC8
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r4, [r6]
	lsls r4, 9
	ldr r0, =gUnknown_02023068
	adds r4, r0
	movs r0, 0xF
	bl BattleAI_SetupAIData
	bl sub_8130BA4
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
	bl dp01_tbl3_exec_completed
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDAC8

	thumb_func_start sub_81BDB70
sub_81BDB70: @ 81BDB70
	push {lr}
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BDB7C

	thumb_func_start sub_81BDC04
sub_81BDC04: @ 81BDC04
	push {lr}
	bl dp01_tbl3_exec_completed
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
	ldr r1, =gUnknown_03005D70
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
	ldr r1, =gUnknown_03005D70
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
	bl dp01_tbl3_exec_completed
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
	ldr r0, =gUnknown_03005D70
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
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDE7C

	thumb_func_start sub_81BDE88
sub_81BDE88: @ 81BDE88
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDE88

	thumb_func_start sub_81BDE94
sub_81BDE94: @ 81BDE94
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDE94

	thumb_func_start sub_81BDEA0
sub_81BDEA0: @ 81BDEA0
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEA0

	thumb_func_start sub_81BDEAC
sub_81BDEAC: @ 81BDEAC
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEAC

	thumb_func_start sub_81BDEB8
sub_81BDEB8: @ 81BDEB8
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEB8

	thumb_func_start sub_81BDEC4
sub_81BDEC4: @ 81BDEC4
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDEC4

	thumb_func_start sub_81BDED0
sub_81BDED0: @ 81BDED0
	push {lr}
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BDED0

	thumb_func_start sub_81BDEDC
sub_81BDEDC: @ 81BDEDC
	push {lr}
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl audio_play_and_stuff
	bl dp01_tbl3_exec_completed
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
	bl song_play_for_text
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
	bl fanfare_play
_081BE08C:
	bl dp01_tbl3_exec_completed
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
	bl sub_80A32E4
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl oamt_set_x3A_32
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r0, =0x0000d6f9
	bl AllocObjectPalette
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
	bl dp01_tbl3_exec_completed
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
	ldr r4, =gUnknown_02023068
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE4E0

	thumb_func_start sub_81BE530
sub_81BE530: @ 81BE530
	push {lr}
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
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
	bl dp01_tbl3_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81BE604

	thumb_func_start sub_81BE610
sub_81BE610: @ 81BE610
	push {lr}
	bl dp01_tbl3_exec_completed
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
	bl sub_80A2F50
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl dp01_tbl3_exec_completed
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

	thumb_func_start sub_81BE66C
sub_81BE66C: @ 81BE66C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xD0
	lsls r0, 5
	cmp r1, r0
	bne _081BE690
	movs r0, 0xA7
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	b _081BE692
	.pool
_081BE690:
	movs r0, 0
_081BE692:
	pop {r1}
	bx r1
	thumb_func_end sub_81BE66C

	thumb_func_start sub_81BE698
sub_81BE698: @ 81BE698
	push {lr}
	ldr r0, =gUnknown_0203CF18
	ldr r0, [r0]
	adds r0, 0x4
	bl sub_8151E50
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE698

	thumb_func_start sub_81BE6AC
sub_81BE6AC: @ 81BE6AC
	ldr r1, =gUnknown_0203CF18
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81BE6AC

	thumb_func_start sub_81BE6B8
sub_81BE6B8: @ 81BE6B8
	push {r4,lr}
	ldr r4, =gUnknown_0203CF18
	ldr r0, [r4]
	cmp r0, 0
	beq _081BE6CC
	movs r0, 0
	str r0, [r4]
	b _081BE718
	.pool
_081BE6CC:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xD0
	lsls r0, 5
	cmp r1, r0
	bne _081BE718
	movs r0, 0xA7
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081BE718
	movs r0, 0xC8
	bl AllocZeroed
	str r0, [r4]
	adds r0, 0x4
	bl sub_8151B3C
	ldr r0, [r4]
	adds r0, 0x4
	ldr r1, =gUnknown_08617E18
	bl sub_8151B68
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8151CA8
	ldr r0, =sub_81BE698
	movs r1, 0xFF
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1]
_081BE718:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE6B8

	thumb_func_start sub_81BE72C
sub_81BE72C: @ 81BE72C
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xD0
	lsls r0, 5
	cmp r1, r0
	bne _081BE788
	movs r0, 0xA7
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081BE788
	ldr r4, =gUnknown_0203CF18
	ldr r0, [r4]
	cmp r0, 0
	beq _081BE788
	ldr r0, =sub_81BE698
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _081BE766
	ldr r0, [r4]
	ldrb r0, [r0]
	bl DestroyTask
_081BE766:
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8151D28
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8151C50
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_081BE788:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE72C

	thumb_func_start sub_81BE79C
sub_81BE79C: @ 81BE79C
	push {r4,lr}
	ldr r0, =0x000040cb
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _081BE7B8
	movs r0, 0xA7
	lsls r0, 1
	bl FlagReset
	b _081BE7EE
	.pool
_081BE7B8:
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	ands r4, r0
	movs r0, 0x9D
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081BE7D4
	movs r4, 0x1
_081BE7D4:
	cmp r4, 0
	beq _081BE7E6
	movs r0, 0xA7
	lsls r0, 1
	bl FlagSet
	bl sub_81BE6B8
	b _081BE7EE
_081BE7E6:
	movs r0, 0xA7
	lsls r0, 1
	bl FlagReset
_081BE7EE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81BE79C

	thumb_func_start sub_81BE7F4
sub_81BE7F4: @ 81BE7F4
	push {lr}
	ldr r0, =sub_81BE808
	movs r1, 0x8
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE7F4

	thumb_func_start sub_81BE808
sub_81BE808: @ 81BE808
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x2D
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 2
	ldr r4, =gUnknown_02037350
	adds r2, r4
	ldr r3, =gSprites
	ldrb r1, [r2, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x26]
	adds r1, 0x4
	strh r1, [r0, 0x26]
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r2, 0x4]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r4, 0x22
	ldrsh r2, [r0, r4]
	movs r4, 0x26
	ldrsh r0, [r0, r4]
	adds r2, r0
	ldrb r1, [r1, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r3, 0x22
	ldrsh r1, [r0, r3]
	movs r4, 0x26
	ldrsh r0, [r0, r4]
	adds r1, r0
	cmp r2, r1
	blt _081BE882
	adds r0, r5, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_081BE882:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE808

	thumb_func_start sp136_strengh_sound
sp136_strengh_sound: @ 81BE89C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =sub_81BE900
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r4, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r5, [r1, 0xC]
	strh r6, [r1, 0xE]
	mov r0, r8
	strh r0, [r1, 0x10]
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0xD6
	bl audio_play
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp136_strengh_sound

	thumb_func_start sub_81BE900
sub_81BE900: @ 81BE900
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _081BE95C
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	ldrh r0, [r4]
	negs r0, r0
	strh r0, [r4]
	ldrh r0, [r4, 0x8]
	negs r0, r0
	strh r0, [r4, 0x8]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	bl SetCameraPanning
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081BE95C
	bl sub_81BE968
	adds r0, r5, 0
	bl DestroyTask
	bl InstallCameraPanAheadCallback
_081BE95C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE900

	thumb_func_start sub_81BE968
sub_81BE968: @ 81BE968
	push {lr}
	ldr r0, =sub_81BE9C0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081BE988
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081BE988:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE968

	thumb_func_start sub_81BE994
sub_81BE994: @ 81BE994
	push {lr}
	ldr r0, =gUnknown_08617D94
	bl LoadObjectPics
	bl sub_81BEA20
	ldr r0, =sub_81BE9C0
	movs r1, 0x8
	bl CreateTask
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x3
	bl sp136_strengh_sound
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE994

	thumb_func_start sub_81BE9C0
sub_81BE9C0: @ 81BE9C0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r3, r1, 3
	ldr r4, =gTasks + 0x8
	adds r2, r3, r4
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	strh r0, [r2, 0x2]
	lsls r0, 16
	movs r1, 0xFA
	lsls r1, 18
	cmp r0, r1
	beq _081BE9E6
	ldrh r0, [r2]
	cmp r0, 0x11
	bne _081BE9F0
_081BE9E6:
	adds r0, r4, 0
	subs r0, 0x8
	adds r0, r3, r0
	ldr r1, =sub_81BEA00
	str r1, [r0]
_081BE9F0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BE9C0

	thumb_func_start sub_81BEA00
sub_81BEA00: @ 81BEA00
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xFA
	lsls r0, 4
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81BEA00

	thumb_func_start sub_81BEA20
sub_81BEA20: @ 81BEA20
	push {r4-r7,lr}
	movs r4, 0
	ldr r5, =gUnknown_08617D64
	adds r7, r5, 0x2
	ldr r6, =gSprites
_081BEA2A:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 1
	adds r1, r0, r5
	ldrh r1, [r1]
	adds r1, 0x78
	lsls r1, 16
	asrs r1, 16
	adds r0, r7
	movs r3, 0
	ldrsh r2, [r0, r3]
	ldr r0, =gUnknown_08617E60
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r2, [r0, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0xF
	ands r2, r1
	strb r2, [r0, 0x5]
	strh r4, [r0, 0x2E]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081BEA2A
	movs r4, 0
	ldr r5, =gUnknown_08617D64
	adds r7, r5, 0x2
	ldr r6, =gSprites
_081BEA78:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 1
	adds r1, r0, r5
	ldrh r1, [r1]
	adds r1, 0x73
	lsls r1, 16
	asrs r1, 16
	adds r0, r7
	ldrh r2, [r0]
	subs r2, 0x3
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_08617E34
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r2, [r0, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0xF
	ands r2, r1
	strb r2, [r0, 0x5]
	strh r4, [r0, 0x2E]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081BEA78
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEA20

	thumb_func_start sub_81BEAD8
sub_81BEAD8: @ 81BEAD8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0x26]
	movs r0, 0x22
	ldrsh r3, [r4, r0]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	adds r3, r0
	ldr r2, =gUnknown_08617D64
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r2, 0x4
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r3, r0
	ble _081BEB1A
	adds r0, r4, 0
	bl DestroySprite
	bl sub_81BE968
_081BEB1A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEAD8

	thumb_func_start sub_81BEB24
sub_81BEB24: @ 81BEB24
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_08617DA4
_081BEB2A:
	lsls r2, r4, 2
	adds r2, r5
	ldrb r0, [r2]
	adds r0, 0x7
	ldrb r1, [r2, 0x1]
	adds r1, 0x7
	ldrh r2, [r2, 0x2]
	bl MapGridSetMetatileIdAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x11
	bls _081BEB2A
	bl DrawWholeMapView
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB24

	thumb_func_start sub_81BEB54
sub_81BEB54: @ 81BEB54
	push {lr}
	ldr r0, =sub_81BED50
	movs r1, 0x9
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB54

	thumb_func_start sub_81BEB68
sub_81BEB68: @ 81BEB68
	push {lr}
	ldr r0, =sub_81BEBF4
	movs r1, 0x9
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB68

	thumb_func_start sub_81BEB7C
sub_81BEB7C: @ 81BEB7C
	push {lr}
	ldr r0, =sub_81BF028
	movs r1, 0x9
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB7C

	thumb_func_start sub_81BEB90
sub_81BEB90: @ 81BEB90
	push {r4,lr}
	ldr r4, =gUnknown_0203CF14
	ldr r0, [r4]
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x2]
	movs r0, 0x12
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB90

	thumb_func_start sub_81BEBB4
sub_81BEBB4: @ 81BEBB4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r1, [r2, 0x8]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _081BEBEC
	ldr r0, =gUnknown_0203CF14
	ldr r1, [r0]
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
	movs r0, 0x2
	strh r0, [r2, 0x8]
	bl sub_81BEB90
	b _081BEBF0
	.pool
_081BEBEC:
	subs r0, r1, 0x1
	strh r0, [r2, 0x8]
_081BEBF0:
	pop {r0}
	bx r0
	thumb_func_end sub_81BEBB4

	thumb_func_start sub_81BEBF4
sub_81BEBF4: @ 81BEBF4
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	bls _081BEC10
	b _081BED40
_081BEC10:
	lsls r0, 2
	ldr r1, =_081BEC24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BEC24:
	.4byte _081BEC40
	.4byte _081BEC50
	.4byte _081BEC88
	.4byte _081BECB0
	.4byte _081BECF8
	.4byte _081BED00
	.4byte _081BED1C
_081BEC40:
	bl FreeAllWindowBuffers
	movs r0, 0
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	b _081BED04
_081BEC50:
	ldr r4, =gUnknown_0203CF04
	movs r0, 0x92
	lsls r0, 4
	bl AllocZeroed
	str r0, [r4]
	ldr r4, =gUnknown_0203CF08
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	b _081BECD8
	.pool
_081BEC88:
	ldr r0, =gUnknown_08617274
	ldr r4, =gUnknown_0203CF04
	ldr r1, [r4]
	movs r2, 0x92
	lsls r2, 3
	bl CpuSet
	ldr r1, [r4]
	movs r2, 0x92
	lsls r2, 4
	movs r0, 0
	movs r3, 0
	bl LoadBgTiles
	b _081BECD8
	.pool
_081BECB0:
	ldr r0, =gUnknown_0203CF08
	ldr r1, [r0]
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08617B94
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0xC
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r2, 0xC
	movs r3, 0x1D
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_081BECD8:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _081BED40
	.pool
_081BECF8:
	movs r0, 0
	bl ShowBg
	b _081BED04
_081BED00:
	bl sub_81BEB24
_081BED04:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _081BED40
	.pool
_081BED1C:
	ldr r4, =gUnknown_0203CF14
	movs r0, 0x4
	bl Alloc
	str r0, [r4]
	movs r2, 0
	movs r1, 0x2
	strh r1, [r0]
	strh r2, [r0, 0x2]
	ldr r0, =sub_81BEBB4
	movs r1, 0xA
	bl CreateTask
	adds r0, r5, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_081BED40:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEBF4

	thumb_func_start sub_81BED50
sub_81BED50: @ 81BED50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	adds r6, r1, 0
	cmp r0, 0x7
	bls _081BED7C
	b _081BF002
_081BED7C:
	lsls r0, 2
	ldr r1, =_081BED90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BED90:
	.4byte _081BEDB0
	.4byte _081BF002
	.4byte _081BEDC4
	.4byte _081BEF64
	.4byte _081BEF94
	.4byte _081BEFD0
	.4byte _081BEFF0
	.4byte _081BEFF8
_081BEDB0:
	ldr r4, =gUnknown_0203CF10
	movs r0, 0xC0
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	b _081BF002
	.pool
_081BEDC4:
	mov r1, r10
	lsls r0, r1, 2
	adds r1, r0, r1
	lsls r1, 3
	adds r2, r1, r6
	ldrh r3, [r2, 0xE]
	movs r4, 0xE
	ldrsh r1, [r2, r4]
	str r0, [sp, 0x8]
	cmp r1, 0x5F
	bgt _081BEE8A
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	ble _081BEE7C
	lsls r0, r3, 24
	lsrs r4, r0, 24
	movs r0, 0x30
	bl Alloc
	ldr r3, =gUnknown_0203CF10
	ldr r1, [r3]
	lsls r2, r4, 3
	adds r1, r2, r1
	str r0, [r1]
	movs r5, 0
	adds r4, r2, 0
_081BEDFA:
	ldr r0, [r3]
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, r5
	strb r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x2F
	bls _081BEDFA
	movs r5, 0
	ldr r7, =gUnknown_0203CF10
	adds r6, r2, 0
_081BEE14:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x30
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x30
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r7]
	adds r1, r6, r1
	ldr r1, [r1]
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r1, r4
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r4
	strb r2, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x2F
	bls _081BEE14
	ldr r0, =gTasks
	ldr r1, [sp, 0x8]
	add r1, r10
	lsls r1, 3
	adds r2, r1, r0
	ldrh r3, [r2, 0xE]
	movs r4, 0xE
	ldrsh r1, [r2, r4]
	adds r6, r0, 0
	cmp r1, 0x5F
	bgt _081BEE78
	adds r0, r3, 0x1
	strh r0, [r2, 0xE]
_081BEE78:
	movs r0, 0
	strh r0, [r2, 0xA]
_081BEE7C:
	ldr r1, [sp, 0x8]
	add r1, r10
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_081BEE8A:
	ldr r0, [sp, 0x8]
	add r0, r10
	lsls r0, 3
	adds r0, r6
	ldrb r4, [r0, 0xE]
	ldrb r5, [r0, 0xC]
	lsls r0, r4, 16
	cmp r5, r4
	bcs _081BEF32
	str r0, [sp, 0xC]
_081BEE9E:
	movs r6, 0
	adds r0, r5, 0x1
	str r0, [sp, 0x4]
	lsls r4, r5, 3
	movs r2, 0x5F
	subs r1, r2, r5
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	mov r9, r0
_081BEEB2:
	ldr r0, =gUnknown_0203CF04
	ldr r0, [r0]
	ldr r7, =gUnknown_0203CF10
	ldr r3, [r7]
	adds r3, r4, r3
	ldrb r2, [r3, 0x4]
	adds r1, r2, 0x1
	strb r1, [r3, 0x4]
	lsls r2, 24
	lsrs r2, 24
	ldr r1, [r3]
	adds r1, r2
	ldrb r1, [r1]
	add r1, r9
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0x1
	mov r8, r2
	str r2, [sp]
	movs r2, 0
	movs r3, 0x30
	bl sub_81BF2B8
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _081BEEB2
	ldr r0, [r7]
	adds r1, r4, r0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x2F
	bls _081BEF24
	ldr r0, [r1]
	bl Free
	ldr r0, [r7]
	adds r0, r4, r0
	movs r1, 0
	str r1, [r0]
	ldr r1, [sp, 0x8]
	add r1, r10
	lsls r1, 3
	ldr r4, =gTasks
	adds r1, r4
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	mov r0, r8
	ands r5, r0
	cmp r5, 0x1
	bne _081BEF24
	ldr r0, =gUnknown_0203CF14
	ldr r1, [r0]
	ldrh r0, [r1, 0x2]
	subs r0, 0x1
	strh r0, [r1, 0x2]
_081BEF24:
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	lsrs r5, r0, 16
	ldr r2, [sp, 0xC]
	lsrs r0, r2, 16
	cmp r5, r0
	bcc _081BEE9E
_081BEF32:
	ldr r0, =gUnknown_0203CF04
	ldr r1, [r0]
	movs r2, 0x92
	lsls r2, 4
	movs r0, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_0203CF10
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 2
	adds r0, r4
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2F
	bhi _081BF002
	b _081BF014
	.pool
_081BEF64:
	movs r0, 0
	bl UnsetBgTilemapBuffer
	ldr r0, =sub_81BEBB4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _081BEF7C
	bl DestroyTask
_081BEF7C:
	ldr r0, =gUnknown_0203CF14
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1]
	strh r0, [r1, 0x2]
	bl sub_81BEB90
	b _081BF002
	.pool
_081BEF94:
	ldr r4, =gUnknown_0203CF14
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r4, =gUnknown_0203CF10
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203CF04
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203CF08
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	b _081BF002
	.pool
_081BEFD0:
	movs r0, 0xC
	movs r1, 0x2
	bl SetGpuRegBits
	movs r0, 0x8
	movs r1, 0
	bl SetGpuRegBits
	movs r0, 0
	movs r1, 0x7
	movs r2, 0
	bl SetBgAttribute
	bl sub_81971D0
	b _081BF002
_081BEFF0:
	movs r0, 0
	bl ShowBg
	b _081BF002
_081BEFF8:
	mov r0, r10
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_081BF002:
	ldr r0, =gTasks
	mov r2, r10
	lsls r1, r2, 2
	add r1, r10
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081BF014:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BED50

	thumb_func_start sub_81BF028
sub_81BF028: @ 81BF028
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _081BF04C
	b _081BF228
_081BF04C:
	lsls r0, 2
	ldr r1, =_081BF060
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BF060:
	.4byte _081BF080
	.4byte _081BF0B4
	.4byte _081BF0DC
	.4byte _081BF0F0
	.4byte _081BF148
	.4byte _081BF170
	.4byte _081BF1CC
	.4byte _081BF224
_081BF080:
	ldr r4, =gUnknown_0203CF0C
	movs r0, 0x14
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x80
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x8
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 2
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0
	strh r0, [r1, 0x10]
	b _081BF228
	.pool
_081BF0B4:
	ldr r0, =gUnknown_0203CF0C
	ldr r0, [r0]
	ldr r1, [r0]
	movs r5, 0
	ldr r2, =gUnknown_08617C44
_081BF0BE:
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r1, 0x1
	cmp r5, 0x7F
	bls _081BF0BE
	b _081BF228
	.pool
_081BF0DC:
	ldr r0, =gUnknown_0203CF0C
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x80
	strh r0, [r1, 0x4]
	b _081BF228
	.pool
_081BF0F0:
	mov r1, sp
	ldr r0, =gUnknown_08617E00
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r4, =gUnknown_0203CF0C
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	str r0, [sp, 0xC]
	movs r2, 0x10
	negs r2, r2
	mov r0, sp
	movs r1, 0x80
	movs r3, 0x1
	bl CreateSprite
	ldr r1, [r4]
	movs r3, 0
	strb r0, [r1, 0x8]
	ldr r2, =gSprites
	ldr r0, [r4]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x28
	strb r3, [r0]
	ldr r3, [r4]
	ldrb r1, [r3, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	strh r1, [r0, 0x2E]
	ldrb r1, [r3, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x30]
_081BF148:
	movs r5, 0
	ldr r2, =gUnknown_0203CF0C
_081BF14C:
	ldr r0, [r2]
	ldr r1, [r0, 0xC]
	lsls r0, r5, 1
	adds r0, r1
	strh r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xFF
	bls _081BF14C
	b _081BF228
	.pool
_081BF170:
	movs r5, 0
	movs r6, 0xFF
	ldr r0, =0x000001ff
	mov r8, r0
_081BF178:
	bl Random
	adds r4, r6, 0
	ands r4, r0
	bl Random
	adds r1, r6, 0
	ands r1, r0
	ldr r0, =gUnknown_0203CF0C
	ldr r3, [r0]
	ldr r0, [r3, 0xC]
	lsls r1, 1
	adds r1, r0
	ldrh r2, [r1]
	lsls r4, 1
	adds r4, r0
	ldrh r0, [r4]
	strh r0, [r1]
	strh r2, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bls _081BF178
	ldr r2, =gSprites
	ldrb r1, [r3, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81BF248
	str r1, [r0]
	b _081BF228
	.pool
_081BF1CC:
	ldr r3, =gSprites
	ldr r5, =gUnknown_0203CF0C
	ldr r0, [r5]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BF238
	adds r0, r2, r3
	bl DestroySprite
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0, 0xC]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x4]
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	str r4, [r0]
	bl Free
	str r4, [r5]
	b _081BF228
	.pool
_081BF224:
	bl script_env_2_enable_and_set_ctx_running
_081BF228:
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081BF238:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF028

	thumb_func_start sub_81BF248
sub_81BF248: @ 81BF248
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, =gUnknown_0203CF0C
	ldr r0, [r0]
	ldrh r0, [r0, 0x10]
	cmp r0, 0xFF
	bls _081BF268
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
	b _081BF2B0
	.pool
_081BF268:
	ldrh r1, [r5, 0x22]
	movs r2, 0x22
	ldrsh r0, [r5, r2]
	cmp r0, 0x5F
	ble _081BF2AC
	movs r4, 0
_081BF274:
	ldr r0, =gUnknown_0203CF0C
	ldr r3, [r0]
	ldr r0, [r3]
	ldrh r1, [r3, 0x10]
	adds r2, r1, 0x1
	strh r2, [r3, 0x10]
	lsls r1, 16
	ldr r2, [r3, 0xC]
	lsrs r1, 15
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0
	str r2, [sp]
	movs r3, 0x10
	bl sub_81BF2B8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _081BF274
	adds r0, r5, 0
	movs r1, 0
	bl StartObjectImageAnim
	b _081BF2B0
	.pool
_081BF2AC:
	adds r0, r1, 0x1
	strh r0, [r5, 0x22]
_081BF2B0:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81BF248

	thumb_func_start sub_81BF2B8
sub_81BF2B8: @ 81BF2B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r0, [sp]
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x28]
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	mov r8, r0
	lsrs r7, r0, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r10
	adds r1, r7, 0
	bl __divsi3
	adds r5, r0, 0
	lsls r5, 24
	lsrs r4, r5, 24
	ldr r3, =gUnknown_030012A8
	strh r4, [r3]
	mov r0, r10
	adds r1, r7, 0
	str r3, [sp, 0x4]
	bl __modsi3
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, [sp, 0x4]
	strh r2, [r3, 0x2]
	movs r1, 0x7
	ands r4, r1
	ands r2, r1
	strh r4, [r3, 0x4]
	strh r2, [r3, 0x6]
	lsrs r0, 27
	lsrs r5, 27
	strh r0, [r3, 0x8]
	strh r5, [r3, 0xA]
	mov r1, r8
	lsrs r1, 27
	lsls r1, 6
	mov r8, r1
	mov r1, r8
	muls r1, r5
	lsls r0, 6
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	strh r1, [r3, 0xC]
	lsls r4, 3
	adds r4, r2
	adds r1, r4
	lsls r4, r1, 16
	lsrs r4, 17
	strh r1, [r3, 0xE]
	movs r1, 0x1
	mov r0, r10
	ands r1, r0
	movs r2, 0x1
	eors r1, r2
	lsls r0, r1, 2
	lsls r6, r0
	eors r1, r2
	lsls r1, 2
	movs r0, 0xF
	lsls r0, r1
	orrs r6, r0
	lsls r6, 24
	lsrs r6, 24
	mov r1, r9
	lsls r1, 5
	mov r9, r1
	add r9, r4
	ldr r1, [sp]
	add r1, r9
	ldrb r0, [r1]
	ands r6, r0
	strb r6, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF2B8

	thumb_func_start sub_81BF384
sub_81BF384: @ 81BF384
	push {r4,lr}
	ldr r0, =0x0000ffff
	bl DisableInterrupts
	movs r0, 0x1
	bl EnableInterrupts
	bl m4aSoundVSyncOff
	movs r0, 0
	bl SetVBlankCallback
	bl ResetAllObjectData
	bl ResetTasks
	bl remove_some_task
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r4, =gUnknown_030012B8
	movs r0, 0x50
	bl AllocZeroed
	str r0, [r4]
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	ldr r0, =sub_81BF3DC
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF384

	thumb_func_start sub_81BF3DC
sub_81BF3DC: @ 81BF3DC
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_030012B8
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x7
	bls _081BF3EE
	b _081BF592
_081BF3EE:
	lsls r0, 2
	ldr r1, =_081BF400
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BF400:
	.4byte _081BF420
	.4byte _081BF430
	.4byte _081BF45C
	.4byte _081BF488
	.4byte _081BF4BC
	.4byte _081BF514
	.4byte _081BF552
	.4byte _081BF574
_081BF420:
	bl sub_81BF5A4
	ldr r0, =gUnknown_030012B8
	ldr r1, [r0]
	movs r0, 0x1
	b _081BF590
	.pool
_081BF430:
	movs r0, 0x5
	bl sub_81BF7A4
	cmp r0, 0x5
	beq _081BF43C
	b _081BF592
_081BF43C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081BF44A
	b _081BF592
_081BF44A:
	ldr r0, =gUnknown_030012B8
	ldr r1, [r0]
	movs r0, 0x2
	b _081BF590
	.pool
_081BF45C:
	movs r0, 0
	bl sub_81BF7A4
	cmp r0, 0
	beq _081BF468
	b _081BF592
_081BF468:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081BF476
	b _081BF592
_081BF476:
	ldr r0, =gUnknown_030012B8
	ldr r1, [r0]
	movs r0, 0x3
	b _081BF590
	.pool
_081BF488:
	movs r0, 0x1
	bl sub_81BF7A4
	cmp r0, 0x1
	beq _081BF494
	b _081BF592
_081BF494:
	ldr r4, =gUnknown_030012B8
	ldr r0, [r4]
	ldr r1, =gUnknown_089A6550
	str r1, [r0, 0x2C]
	adds r0, 0x4F
	movs r5, 0
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, 0x4
	bl MultiBootInit
	ldr r1, [r4]
	strh r5, [r1, 0x2]
	movs r0, 0x4
	b _081BF590
	.pool
_081BF4BC:
	adds r4, r5, 0
	ldr r0, [r4]
	adds r0, 0x4
	bl MultiBootMain
	ldr r4, [r4]
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	bne _081BF4D8
	ldr r0, [r4, 0x20]
	ldr r1, =0x00020200
	ands r0, r1
	cmp r0, r1
	beq _081BF4E4
_081BF4D8:
	movs r0, 0
	strh r0, [r4, 0x2]
	b _081BF592
	.pool
_081BF4E4:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB4
	bls _081BF592
	adds r0, r4, 0x4
	ldr r1, =gMultiBootProgram_BerryGlitchFix_Start
	ldr r2, =gMultiBootProgram_BerryGlitchFix_End
	subs r2, r1
	movs r3, 0x1
	str r3, [sp]
	movs r3, 0x4
	bl MultiBootStartMaster
	ldr r1, [r5]
	movs r0, 0x5
	b _081BF590
	.pool
_081BF514:
	movs r0, 0x2
	bl sub_81BF7A4
	adds r4, r0, 0
	cmp r4, 0x2
	bne _081BF592
	ldr r5, =gUnknown_030012B8
	ldr r0, [r5]
	adds r0, 0x4
	bl MultiBootMain
	ldr r0, [r5]
	adds r0, 0x4
	bl MultiBootCheckComplete
	cmp r0, 0
	beq _081BF540
	ldr r1, [r5]
	movs r0, 0x6
	b _081BF590
	.pool
_081BF540:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	ands r4, r0
	cmp r4, 0
	bne _081BF592
	movs r0, 0x7
	b _081BF590
_081BF552:
	movs r0, 0x3
	bl sub_81BF7A4
	cmp r0, 0x3
	bne _081BF592
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BF592
	bl DoSoftReset
	b _081BF592
	.pool
_081BF574:
	movs r0, 0x4
	bl sub_81BF7A4
	cmp r0, 0x4
	bne _081BF592
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BF592
	ldr r0, =gUnknown_030012B8
	ldr r1, [r0]
	movs r0, 0x1
_081BF590:
	strb r0, [r1]
_081BF592:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF3DC

	thumb_func_start sub_81BF5A4
sub_81BF5A4: @ 81BF5A4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0
	str r1, [sp, 0xC]
	ldr r4, =0x040000d4
	add r0, sp, 0xC
	str r0, [r4]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r4, 0x4]
	ldr r0, =0x85006000
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	str r0, [r4]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r4, 0x4]
	ldr r2, =0x85000100
	str r2, [r4, 0x8]
	ldr r0, [r4, 0x8]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	str r0, [r4]
	movs r0, 0xA0
	lsls r0, 19
	str r0, [r4, 0x4]
	str r2, [r4, 0x8]
	ldr r0, [r4, 0x8]
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08618108
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_08618110
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r0, =gUnknown_08618138
	str r0, [r4]
	ldr r0, =0x050001e0
	str r0, [r4, 0x4]
	ldr r0, =0x84000008
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	movs r0, 0
	movs r1, 0x40
	bl SetGpuReg
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0xAA
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_08617E9B
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r4, 0x78
	subs r0, r4, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r6, =gUnknown_0861815B
	str r6, [sp]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r3, 0x3
	bl box_print
	ldr r5, =gUnknown_08617E8D
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	subs r4, r1
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r0, r4, 0
	adds r0, 0x78
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r3, 0x3
	bl box_print
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0x70
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r3, 0
	bl box_print
	ldr r4, =gUnknown_08617E78
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xD0
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_08618158
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x2
	bl box_print
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF5A4

	thumb_func_start sub_81BF7A4
sub_81BF7A4: @ 81BF7A4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_030012B8
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	cmp r0, r4
	bne _081BF7BC
	adds r0, r4, 0
	b _081BF7DC
	.pool
_081BF7BC:
	cmp r0, 0x6
	bne _081BF7CC
	adds r0, r4, 0
	bl sub_81BF7E8
	ldr r0, [r5]
	strb r4, [r0, 0x1]
	b _081BF7D6
_081BF7CC:
	bl sub_81BF8D8
	ldr r1, [r5]
	movs r0, 0x6
	strb r0, [r1, 0x1]
_081BF7D6:
	ldr r0, =gUnknown_030012B8
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
_081BF7DC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81BF7A4

	thumb_func_start sub_81BF7E8
sub_81BF7E8: @ 81BF7E8
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	movs r1, 0xAA
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_08618158
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_08618160
	lsls r4, r6, 2
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl box_print
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	cmp r6, 0x5
	bhi _081BF87E
	ldr r0, =_081BF850
	adds r0, r4, r0
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BF850:
	.4byte _081BF868
	.4byte _081BF870
	.4byte _081BF868
	.4byte _081BF868
	.4byte _081BF868
	.4byte _081BF878
_081BF868:
	movs r0, 0x2
	bl PutWindowTilemap
	b _081BF87E
_081BF870:
	movs r0, 0x3
	bl PutWindowTilemap
	b _081BF87E
_081BF878:
	movs r0, 0
	bl PutWindowTilemap
_081BF87E:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r5, =gUnknown_08618178
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 2
	adds r0, r4, r5
	ldr r0, [r0]
	ldr r1, =0x06004000
	bl LZ77UnCompVram
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	adds r5, 0x8
	adds r4, r5
	ldr r0, [r4]
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x04000040
	bl CpuSet
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF7E8

	thumb_func_start sub_81BF8D8
sub_81BF8D8: @ 81BF8D8
	push {lr}
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	pop {r0}
	bx r0
	thumb_func_end sub_81BF8D8

	thumb_func_start sub_81BF8EC
sub_81BF8EC: @ 81BF8EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r4, =gUnknown_0203CF1C
	ldr r0, =0x000040f8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =0x000040bc
	adds r0, r1
	strb r7, [r0]
	ldr r0, [r4]
	mov r2, r8
	str r2, [r0]
	adds r1, 0x2
	adds r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, =0x000040bf
	adds r0, r2
	strb r6, [r0]
	ldr r1, [r4]
	ldr r0, [sp, 0x18]
	str r0, [r1, 0x4]
	cmp r7, 0x2
	bne _081BF94C
	subs r2, 0x2
	adds r1, r2
	movs r0, 0x1
	b _081BF952
	.pool
_081BF94C:
	ldr r0, =0x000040bd
	adds r1, r0
	movs r0, 0
_081BF952:
	strb r0, [r1]
	cmp r7, 0x1
	beq _081BF9A0
	cmp r7, 0x1
	bgt _081BF96C
	cmp r7, 0
	beq _081BF97C
	ldr r2, =gUnknown_0203CF1C
	b _081BF9EE
	.pool
_081BF96C:
	cmp r7, 0x2
	beq _081BF97C
	cmp r7, 0x3
	beq _081BF9D0
	ldr r2, =gUnknown_0203CF1C
	b _081BF9EE
	.pool
_081BF97C:
	ldr r2, =gUnknown_0203CF1C
	ldr r0, [r2]
	ldr r1, =0x000040c1
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x000040c2
	adds r0, r1
	movs r1, 0x3
	b _081BF9EC
	.pool
_081BF9A0:
	ldr r2, =gUnknown_0203CF1C
	ldr r0, [r2]
	ldr r1, =0x000040c1
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x000040c2
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x000040c8
	adds r0, r1
	strb r7, [r0]
	b _081BF9EE
	.pool
_081BF9D0:
	ldr r2, =gUnknown_0203CF1C
	ldr r0, [r2]
	ldr r1, =0x000040c1
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x000040c2
	adds r0, r1
	strb r7, [r0]
	ldr r0, [r2]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0x1
_081BF9EC:
	strb r1, [r0]
_081BF9EE:
	ldr r0, [r2]
	ldr r2, =0x000040c1
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	strb r1, [r0]
	movs r0, 0xFF
	bl sub_81C488C
	ldr r0, =gUnknown_020244D4
	ldr r0, [r0]
	cmp r0, 0
	bne _081BFA12
	movs r0, 0
	movs r1, 0
	bl sub_806F2AC
_081BFA12:
	ldr r0, =sub_81BFAE4
	bl SetMainCallback2
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF8EC

	thumb_func_start sub_81BFA38
sub_81BFA38: @ 81BFA38
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r6, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 16
	lsrs r6, 16
	str r3, [sp]
	movs r0, 0x3
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_81BF8EC
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	strh r6, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BFA38

	thumb_func_start sub_81BFA80
sub_81BFA80: @ 81BFA80
	push {r4,lr}
	sub sp, 0x4
	ldr r4, [sp, 0xC]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r4, [sp]
	bl sub_81BF8EC
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040ef
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BFA80

	thumb_func_start sub_81BFAB4
sub_81BFAB4: @ 81BFAB4
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81BFAB4

	thumb_func_start sub_81BFAD0
sub_81BFAD0: @ 81BFAD0
	push {lr}
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81BFAD0

	thumb_func_start sub_81BFAE4
sub_81BFAE4: @ 81BFAE4
	push {lr}
_081BFAE6:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081BFB0A
	bl sub_81BFB10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081BFB0A
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081BFAE6
_081BFB0A:
	pop {r0}
	bx r0
	thumb_func_end sub_81BFAE4

	thumb_func_start sub_81BFB10
sub_81BFB10: @ 81BFB10
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x18
	bls _081BFB24
	b _081BFE00
_081BFB24:
	lsls r0, 2
	ldr r1, =_081BFB38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BFB38:
	.4byte _081BFB9C
	.4byte _081BFBAA
	.4byte _081BFBBC
	.4byte _081BFBD0
	.4byte _081BFBE4
	.4byte _081BFBEA
	.4byte _081BFC04
	.4byte _081BFC20
	.4byte _081BFC26
	.4byte _081BFC38
	.4byte _081BFC58
	.4byte _081BFC7C
	.4byte _081BFC82
	.4byte _081BFC94
	.4byte _081BFCAC
	.4byte _081BFCC0
	.4byte _081BFCD8
	.4byte _081BFCF8
	.4byte _081BFD34
	.4byte _081BFD50
	.4byte _081BFD60
	.4byte _081BFD74
	.4byte _081BFD7A
	.4byte _081BFDB0
	.4byte _081BFDCC
_081BFB9C:
	bl SetVBlankHBlankCallbacksToNull
	bl sub_8121DA0
	bl clear_scheduled_bg_copies_to_vram
	b _081BFDE6
_081BFBAA:
	bl remove_some_task
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFBBC:
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	b _081BFDE4
	.pool
_081BFBD0:
	bl ResetAllObjectData
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFBE4:
	bl ResetObjectPaletteAllocator
	b _081BFDE6
_081BFBEA:
	bl sub_81BFE24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040f0
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081BFDE6
	.pool
_081BFC04:
	bl sub_81BFEB0
	lsls r0, 24
	cmp r0, 0
	bne _081BFC10
	b _081BFE18
_081BFC10:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFC20:
	bl sub_81C2554
	b _081BFDE6
_081BFC26:
	bl sub_81C1BA0
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFC38:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_81C0098
	ldr r0, [r4]
	ldr r1, =0x000040f0
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081BFDE6
	.pool
_081BFC58:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C00F0
	lsls r0, 24
	cmp r0, 0
	bne _081BFC6A
	b _081BFE18
_081BFC6A:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFC7C:
	bl sub_81C25E8
	b _081BFDE6
_081BFC82:
	bl sub_81C286C
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFC94:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C2D9C
	b _081BFDE6
	.pool
_081BFCAC:
	bl sub_81C0348
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFCC0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C2AFC
	b _081BFDE6
	.pool
_081BFCD8:
	bl sub_81C4190
	bl sub_81C42C8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040f0
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081BFDE6
	.pool
_081BFCF8:
	ldr r4, =gUnknown_0203CF1C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldr r2, =0x000040f0
	adds r1, r2
	bl sub_81C45F4
	ldr r1, [r4]
	ldr r2, =0x000040d3
	adds r1, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r2, r1, r2
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _081BFD1C
	b _081BFE18
_081BFD1C:
	ldr r0, =0x000040f0
	adds r1, r0
	movs r0, 0
	strh r0, [r1]
	b _081BFDE6
	.pool
_081BFD34:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C4984
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFD50:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C4A08
	b _081BFDE6
	.pool
_081BFD60:
	bl sub_81C4A88
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFD74:
	bl sub_81C4280
	b _081BFDE6
_081BFD7A:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _081BFDA0
	ldr r0, =sub_81C0510
	movs r1, 0
	bl CreateTask
	b _081BFDE6
	.pool
_081BFDA0:
	ldr r0, =sub_81C171C
	movs r1, 0
	bl CreateTask
	b _081BFDE6
	.pool
_081BFDB0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _081BFDEE
	.pool
_081BFDCC:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
_081BFDE4:
	strb r0, [r2, 0x8]
_081BFDE6:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_081BFDEE:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081BFE18
	.pool
_081BFE00:
	ldr r0, =sub_81BFAD0
	bl SetVBlankCallback
	ldr r0, =sub_81BFAB4
	bl SetMainCallback2
	movs r0, 0x1
	b _081BFE1A
	.pool
_081BFE18:
	movs r0, 0
_081BFE1A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81BFB10

	thumb_func_start sub_81BFE24
sub_81BFE24: @ 81BFE24
	push {r4,lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0861CBB4
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF1C
	ldr r1, [r4]
	ldr r0, =0x000020bc
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x000010bc
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	adds r1, 0xBC
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BFE24

	thumb_func_start sub_81BFEB0
sub_81BFEB0: @ 81BFEB0
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_0203CF1C
	ldr r0, [r1]
	ldr r2, =0x000040f0
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r4, r1, 0
	cmp r0, 0xC
	bls _081BFEC8
	b _081C008C
_081BFEC8:
	lsls r0, 2
	ldr r1, =_081BFEE0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BFEE0:
	.4byte _081BFF14
	.4byte _081BFF30
	.4byte _081BFF60
	.4byte _081BFF78
	.4byte _081BFF90
	.4byte _081BFFA8
	.4byte _081BFFC0
	.4byte _081BFFF0
	.4byte _081BFFFC
	.4byte _081C0018
	.4byte _081C0024
	.4byte _081C0040
	.4byte _081C0064
_081BFF14:
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08D97D0C
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081C0046
	.pool
_081BFF30:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081BFF3E
	b _081C008C
_081BFF3E:
	ldr r0, =gUnknown_08D9862C
	ldr r4, =gUnknown_0203CF1C
	ldr r1, [r4]
	adds r1, 0xBC
	bl LZDecompressWram
	ldr r1, [r4]
	ldr r2, =0x000040f0
	adds r1, r2
	b _081C004E
	.pool
_081BFF60:
	ldr r0, =gUnknown_08D98CC8
	ldr r1, [r4]
	ldr r2, =0x000008bc
	adds r1, r2
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C004A
	.pool
_081BFF78:
	ldr r0, =gUnknown_08D987FC
	ldr r1, [r4]
	ldr r2, =0x000018bc
	adds r1, r2
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C004A
	.pool
_081BFF90:
	ldr r0, =gUnknown_08D9898C
	ldr r1, [r4]
	ldr r2, =0x000028bc
	adds r1, r2
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C004A
	.pool
_081BFFA8:
	ldr r0, =gUnknown_08D98B28
	ldr r1, [r4]
	ldr r2, =0x000038bc
	adds r1, r2
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C004A
	.pool
_081BFFC0:
	ldr r0, =gUnknown_08D9853C
	movs r2, 0x80
	lsls r2, 1
	movs r1, 0
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08D85620
	movs r1, 0x81
	movs r2, 0x1E
	bl LoadPalette
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040f0
	adds r1, r2
	b _081C004E
	.pool
_081BFFF0:
	ldr r0, =gUnknown_0861CFBC
	bl LoadCompressedObjectPic
	b _081C0046
	.pool
_081BFFFC:
	ldr r0, =gUnknown_0861D074
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040f0
	adds r1, r2
	b _081C004E
	.pool
_081C0018:
	ldr r0, =gUnknown_0861D0F8
	bl LoadCompressedObjectPic
	b _081C0046
	.pool
_081C0024:
	ldr r0, =gUnknown_0861D100
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040f0
	adds r1, r2
	b _081C004E
	.pool
_081C0040:
	ldr r0, =gUnknown_0861D07C
	bl LoadCompressedObjectPalette
_081C0046:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
_081C004A:
	ldr r0, =0x000040f0
	adds r1, r0
_081C004E:
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _081C008C
	.pool
_081C0064:
	ldr r0, =gUnknown_08D97B84
	movs r1, 0xE8
	lsls r1, 1
	movs r2, 0x60
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040f0
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _081C008E
	.pool
_081C008C:
	movs r0, 0
_081C008E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81BFEB0

	thumb_func_start sub_81C0098
sub_81C0098: @ 81C0098
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bd
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C00D0
	ldr r2, [r1]
	ldr r4, =0x000040be
	adds r0, r1, r4
	ldrb r1, [r0]
	movs r0, 0x64
	muls r1, r0
	adds r1, r2
	adds r0, r3, 0
	movs r2, 0x64
	bl memcpy
	b _081C00E6
	.pool
_081C00D0:
	ldr r0, [r1]
	ldr r2, =0x000040be
	adds r1, r2
	ldrb r2, [r1]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 4
	adds r0, r1
	adds r1, r3, 0
	bl sub_8069004
_081C00E6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0098

	thumb_func_start sub_81C00F0
sub_81C00F0: @ 81C00F0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r7, [r0]
	adds r6, r7, 0
	adds r6, 0x70
	ldr r1, =0x000040f0
	adds r0, r7, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	beq _081C0198
	cmp r0, 0x1
	bgt _081C0120
	cmp r0, 0
	beq _081C012C
	b _081C0314
	.pool
_081C0120:
	cmp r0, 0x2
	beq _081C01DC
	cmp r0, 0x3
	bne _081C012A
	b _081C02A8
_081C012A:
	b _081C0314
_081C012C:
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	strh r0, [r6]
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	strh r0, [r6, 0x2]
	adds r0, r5, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [r6, 0x10]
	adds r0, r5, 0
	movs r1, 0x38
	bl GetMonData
	strb r0, [r6, 0x5]
	adds r0, r5, 0
	movs r1, 0x2E
	bl GetMonData
	strb r0, [r6, 0x8]
	adds r0, r5, 0
	movs r1, 0xC
	bl GetMonData
	strh r0, [r6, 0x2E]
	adds r0, r5, 0
	movs r1, 0
	bl GetMonData
	str r0, [r6, 0xC]
	adds r0, r5, 0
	movs r1, 0x4
	bl GetMonData
	adds r1, r7, 0
	adds r1, 0xA5
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	beq _081C018C
	movs r0, 0x1
	strb r0, [r6, 0x4]
	b _081C0322
_081C018C:
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	strb r0, [r6, 0x4]
	b _081C0322
_081C0198:
	movs r4, 0
	movs r0, 0x8C
	adds r0, r7
	mov r8, r0
	movs r1, 0xA4
	adds r1, r7
	mov r9, r1
	adds r6, r7, 0
	adds r6, 0x84
_081C01AA:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r5, 0
	bl GetMonData
	strh r0, [r6]
	adds r1, r4, 0
	adds r1, 0x11
	adds r0, r5, 0
	bl GetMonData
	mov r2, r8
	adds r1, r2, r4
	strb r0, [r1]
	adds r6, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	bls _081C01AA
	adds r0, r5, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1]
	b _081C0322
_081C01DC:
	ldr r1, [r7]
	ldr r0, =gPlayerParty
	cmp r1, r0
	beq _081C01F8
	ldr r2, =0x000040bc
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C01F8
	ldr r1, =0x000040ef
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C0254
_081C01F8:
	adds r0, r5, 0
	bl GetNature
	adds r1, r6, 0
	adds r1, 0x33
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r6, 0x20]
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r6, 0x22]
	adds r0, r5, 0
	movs r1, 0x3B
	bl GetMonData
	strh r0, [r6, 0x24]
	adds r0, r5, 0
	movs r1, 0x3C
	bl GetMonData
	strh r0, [r6, 0x26]
	adds r0, r5, 0
	movs r1, 0x3E
	bl GetMonData
	strh r0, [r6, 0x28]
	adds r0, r5, 0
	movs r1, 0x3F
	bl GetMonData
	strh r0, [r6, 0x2A]
	adds r0, r5, 0
	movs r1, 0x3D
	b _081C02A0
	.pool
_081C0254:
	adds r0, r5, 0
	bl GetNature
	adds r1, r7, 0
	adds r1, 0xA3
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r6, 0x20]
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r6, 0x22]
	adds r0, r5, 0
	movs r1, 0x54
	bl GetMonData
	strh r0, [r6, 0x24]
	adds r0, r5, 0
	movs r1, 0x55
	bl GetMonData
	strh r0, [r6, 0x26]
	adds r0, r5, 0
	movs r1, 0x57
	bl GetMonData
	strh r0, [r6, 0x28]
	adds r0, r5, 0
	movs r1, 0x58
	bl GetMonData
	strh r0, [r6, 0x2A]
	adds r0, r5, 0
	movs r1, 0x56
_081C02A0:
	bl GetMonData
	strh r0, [r6, 0x2C]
	b _081C0322
_081C02A8:
	adds r4, r7, 0
	adds r4, 0xA6
	adds r0, r5, 0
	movs r1, 0x7
	adds r2, r4, 0
	bl GetMonData
	adds r0, r5, 0
	movs r1, 0x3
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl ConvertInternationalString
	adds r0, r5, 0
	bl sub_81B205C
	strb r0, [r6, 0x7]
	adds r0, r5, 0
	movs r1, 0x31
	bl GetMonData
	adds r1, r7, 0
	adds r1, 0xA2
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [r6, 0x48]
	adds r0, r5, 0
	movs r1, 0x23
	bl GetMonData
	strb r0, [r6, 0x9]
	adds r0, r5, 0
	movs r1, 0x24
	bl GetMonData
	strb r0, [r6, 0xA]
	adds r0, r5, 0
	movs r1, 0x25
	bl GetMonData
	strb r0, [r6, 0xB]
	adds r0, r5, 0
	movs r1, 0x20
	bl GetMonData
	strh r0, [r6, 0x30]
	b _081C0322
_081C0314:
	adds r0, r5, 0
	movs r1, 0x52
	bl GetMonData
	strb r0, [r6, 0x6]
	movs r0, 0x1
	b _081C0332
_081C0322:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040f0
	adds r1, r2
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0
_081C0332:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C00F0

	thumb_func_start sub_81C0348
sub_81C0348: @ 81C0348
	push {r4-r6,lr}
	ldr r6, =gUnknown_0203CF1C
	ldr r2, [r6]
	ldr r1, =0x000040c0
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081C037C
	movs r0, 0
	movs r1, 0xFF
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0xFF
	movs r2, 0
	bl sub_81C1EFC
	b _081C03D8
	.pool
_081C037C:
	ldr r1, =0x000040c6
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 1
	adds r0, r2, 0
	adds r0, 0x84
	adds r0, r1
	ldrh r0, [r0]
	bl sub_81C240C
	ldr r0, [r6]
	ldr r5, =0x000020bc
	adds r0, r5
	movs r1, 0x3
	movs r2, 0
	bl sub_81C2194
	ldr r0, [r6]
	ldr r4, =0x000030bc
	adds r0, r4
	movs r1, 0x1
	movs r2, 0
	bl sub_81C2194
	ldr r1, [r6]
	adds r1, r4
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r6]
	adds r1, r5
	movs r0, 0x2
	bl SetBgTilemapBuffer
	movs r1, 0x80
	lsls r1, 9
	movs r0, 0x2
	movs r2, 0x1
	bl ChangeBgX
	movs r0, 0x13
	bl ClearWindowTilemap
	movs r0, 0xD
	bl ClearWindowTilemap
_081C03D8:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x77
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0400
	movs r0, 0
	movs r1, 0xFF
	bl sub_81C2074
	b _081C0416
	.pool
_081C0400:
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081C0416
	movs r0, 0xD
	bl PutWindowTilemap
_081C0416:
	bl sub_81C2524
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C2228
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0348

	thumb_func_start sub_81C0434
sub_81C0434: @ 81C0434
	push {lr}
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0434

	thumb_func_start sub_81C044C
sub_81C044C: @ 81C044C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C0484
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C044C

	thumb_func_start sub_81C0484
sub_81C0484: @ 81C0484
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C04EC
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C04EC
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	bl SetMainCallback2
	ldr r1, =gUnknown_0203CF20
	ldr r0, [r4]
	ldr r2, =0x000040be
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bl sub_81C4898
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	bl sub_80A369C
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	ldr r0, =gUnknown_020244D4
	ldr r0, [r0]
	cmp r0, 0
	bne _081C04E2
	movs r0, 0
	bl sub_806F47C
_081C04E2:
	bl sub_81C0434
	adds r0, r5, 0
	bl DestroyTask
_081C04EC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0484

	thumb_func_start sub_81C0510
sub_81C0510: @ 81C0510
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C05FE
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r2, 0x80
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _081C05FE
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C0550
	movs r1, 0x1
	negs r1, r1
	adds r0, r4, 0
	bl sub_81C0604
	b _081C05FE
	.pool
_081C0550:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _081C0562
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C0604
	b _081C05FE
_081C0562:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C0576
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C0582
_081C0576:
	movs r1, 0x1
	negs r1, r1
	adds r0, r4, 0
	bl sub_81C0A8C
	b _081C05FE
_081C0582:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C0598
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C05A2
_081C0598:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C0A8C
	b _081C05FE
_081C05A2:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C05E6
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C05FE
	cmp r0, 0
	bne _081C05D8
	bl sub_81C48F0
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81C044C
	b _081C05FE
	.pool
_081C05D8:
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81C0E48
	b _081C05FE
_081C05E6:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C05FE
	bl sub_81C48F0
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81C044C
_081C05FE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C0510

	thumb_func_start sub_81C0604
sub_81C0604: @ 81C0604
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r4, r5, 0
	ldr r1, =gUnknown_0203CF1C
	ldr r3, [r1]
	ldr r2, =0x000040c3
	adds r0, r3, r2
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0
	bne _081C06EE
	ldr r1, =0x000040bd
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, 0x1
	bne _081C0678
	adds r1, 0x3
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C0654
	lsls r1, r5, 24
	asrs r1, 24
	movs r4, 0x2
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	asrs r0, 31
	ands r4, r0
	b _081C065C
	.pool
_081C0654:
	movs r4, 0x3
	cmp r5, 0x1
	bne _081C065C
	movs r4, 0x1
_081C065C:
	ldr r2, [r6]
	ldr r0, [r2]
	ldr r3, =0x000040be
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, 0x1
	adds r2, r3
	ldrb r2, [r2]
	adds r3, r4, 0
	bl sub_80D214C
	b _081C0696
	.pool
_081C0678:
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C068E
	lsls r0, r5, 24
	asrs r0, 24
	bl sub_81C09B4
	b _081C0696
_081C068E:
	lsls r0, r4, 24
	asrs r0, 24
	bl sub_81C08F8
_081C0696:
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081C06EE
	movs r0, 0x5
	bl audio_play
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	adds r0, 0x77
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C06D4
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81C4204
	movs r0, 0xD
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0x2
	bl sub_81C2074
_081C06D4:
	ldr r0, [r5]
	ldr r1, =0x000040be
	adds r0, r1
	movs r2, 0
	strb r4, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0x8]
	ldr r1, =sub_81C0704
	str r1, [r0]
_081C06EE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0604

	thumb_func_start sub_81C0704
sub_81C0704: @ 81C0704
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r4, r1, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0xC
	bls _081C071E
	b _081C08BC
_081C071E:
	lsls r0, 2
	ldr r1, =_081C0730
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C0730:
	.4byte _081C0764
	.4byte _081C076A
	.4byte _081C0780
	.4byte _081C07A8
	.4byte _081C07C8
	.4byte _081C07E0
	.4byte _081C07F0
	.4byte _081C0800
	.4byte _081C0828
	.4byte _081C086C
	.4byte _081C0872
	.4byte _081C0878
	.4byte _081C0894
_081C0764:
	bl sub_80A369C
	b _081C08EC
_081C076A:
	bl sub_81C4898
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	b _081C0786
	.pool
_081C0780:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d4
_081C0786:
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl ResetSpriteAndFreeResources
	b _081C08EC
	.pool
_081C07A8:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_81C0098
	ldr r0, [r4]
	ldr r1, =0x000040f0
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081C08EC
	.pool
_081C07C8:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C00F0
	lsls r0, 24
	cmp r0, 0
	bne _081C07DA
	b _081C08F2
_081C07DA:
	b _081C08EC
	.pool
_081C07E0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C49E0
	b _081C08EC
	.pool
_081C07F0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C4A08
	b _081C08EC
	.pool
_081C0800:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x77
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C0816
	movs r1, 0x2
	negs r1, r1
	movs r0, 0xA
	bl sub_81C2074
_081C0816:
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_81C2228
	movs r0, 0
	strh r0, [r5, 0x2]
	b _081C08EC
	.pool
_081C0828:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0xC
	adds r1, r5, 0x2
	bl sub_81C45F4
	ldr r1, [r4]
	ldr r2, =0x000040d3
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C08F2
	ldr r2, =gSprites
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x32]
	bl sub_81C0E24
	movs r0, 0
	strh r0, [r5, 0x2]
	b _081C08EC
	.pool
_081C086C:
	bl sub_81C4280
	b _081C08EC
_081C0872:
	bl sub_81C25E8
	b _081C08EC
_081C0878:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C2D9C
	bl sub_81C2524
	b _081C08EC
	.pool
_081C0894:
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x32]
	b _081C08EC
	.pool
_081C08BC:
	bl sub_81221EC
	lsls r0, 24
	cmp r0, 0
	bne _081C08F2
	ldr r0, =sub_81C20F0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _081C08F2
	strh r0, [r5]
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r4, r0
	ldr r1, =sub_81C0510
	str r1, [r0]
	b _081C08F2
	.pool
_081C08EC:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_081C08F2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C0704

	thumb_func_start sub_81C08F8
sub_81C08F8: @ 81C08F8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0203CF1C
	ldr r2, [r1]
	ldr r7, [r2]
	ldr r3, =0x000040c0
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0
	bne _081C0960
	lsls r0, r4, 24
	asrs r3, r0, 24
	movs r1, 0x1
	negs r1, r1
	adds r6, r0, 0
	cmp r3, r1
	bne _081C0928
	ldr r1, =0x000040be
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C0988
_081C0928:
	asrs r0, r6, 24
	cmp r0, 0x1
	bne _081C0940
	ldr r0, [r5]
	ldr r2, =0x000040be
	adds r1, r0, r2
	ldr r3, =0x000040bf
	adds r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _081C0988
_081C0940:
	ldr r0, [r5]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	adds r0, r4
	lsls r0, 24
	asrs r0, 24
	b _081C09AE
	.pool
_081C0960:
	ldr r3, =0x000040be
	adds r0, r2, r3
	ldrb r5, [r0]
	lsls r6, r4, 24
_081C0968:
	lsls r0, r5, 24
	asrs r0, 24
	asrs r1, r6, 24
	adds r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	asrs r4, r0, 24
	cmp r4, 0
	blt _081C0988
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bf
	adds r0, r1
	ldrb r0, [r0]
	cmp r4, r0
	ble _081C099C
_081C0988:
	movs r0, 0x1
	negs r0, r0
	b _081C09AE
	.pool
_081C099C:
	movs r0, 0x64
	muls r0, r4
	adds r0, r7, r0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081C0968
	adds r0, r4, 0
_081C09AE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C08F8

	thumb_func_start sub_81C09B4
sub_81C09B4: @ 81C09B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	ldr r6, =gUnknown_0203CF1C
	ldr r0, [r6]
	ldr r1, [r0]
	mov r8, r1
	movs r5, 0
	movs r2, 0
	ldr r3, =gUnknown_0861CC1C
	movs r1, 0
	ldrsb r1, [r3, r1]
	ldr r4, =0x000040be
	adds r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	beq _081C09FC
	adds r7, r3, 0
	adds r3, r4, 0
_081C09E0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bhi _081C09FC
	adds r0, r2, r7
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldr r0, [r6]
	adds r0, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _081C09E0
	adds r5, r2, 0
_081C09FC:
	mov r0, r12
	lsls r6, r0, 24
	ldr r7, =gUnknown_0861CC1C
_081C0A02:
	lsls r0, r5, 24
	asrs r0, 24
	asrs r1, r6, 24
	adds r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, r5, 24
	lsrs r0, r1, 24
	cmp r0, 0x5
	bhi _081C0A40
	asrs r0, r1, 24
	adds r0, r7
	movs r4, 0
	ldrsb r4, [r0, r4]
	movs r0, 0x64
	muls r0, r4
	add r0, r8
	bl sub_81C0A50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C0A02
	adds r0, r4, 0
	b _081C0A44
	.pool
_081C0A40:
	movs r0, 0x1
	negs r0, r0
_081C0A44:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C09B4

	thumb_func_start sub_81C0A50
sub_81C0A50: @ 81C0A50
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081C0A84
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0A78
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081C0A84
_081C0A78:
	movs r0, 0x1
	b _081C0A86
	.pool
_081C0A84:
	movs r0, 0
_081C0A86:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C0A50

	thumb_func_start sub_81C0A8C
sub_81C0A8C: @ 81C0A8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	str r6, [sp]
	lsls r1, 24
	lsrs r3, r1, 24
	str r3, [sp, 0x4]
	ldr r0, =gUnknown_0203CF1C
	mov r8, r0
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x70
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r0, r7, r0
	str r0, [sp, 0x8]
	ldrb r1, [r1, 0x4]
	mov r10, r1
	cmp r1, 0
	bne _081C0B6E
	lsls r0, r3, 24
	asrs r5, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _081C0AE0
	ldr r1, =0x000040c0
	adds r0, r2, r1
	ldr r3, =0x000040c1
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081C0B6E
_081C0AE0:
	cmp r5, 0x1
	bne _081C0AF4
	ldr r1, =0x000040c0
	adds r0, r2, r1
	ldr r3, =0x000040c2
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081C0B6E
_081C0AF4:
	movs r0, 0x5
	bl audio_play
	mov r1, r8
	ldr r0, [r1]
	ldr r4, =0x000040c0
	adds r0, r4
	ldrb r0, [r0]
	bl sub_81C2C38
	mov r2, r8
	ldr r1, [r2]
	adds r1, r4
	ldrb r0, [r1]
	ldr r3, [sp, 0x4]
	adds r0, r3
	strb r0, [r1]
	mov r1, r10
	ldr r0, [sp, 0x8]
	strh r1, [r0]
	cmp r5, 0x1
	bne _081C0B4C
	ldr r1, =sub_81C0B8C
	mov r0, r9
	subs r0, 0x8
	adds r0, r7, r0
	ldr r2, [r0]
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	b _081C0B5C
	.pool
_081C0B4C:
	ldr r1, =sub_81C0CC4
	mov r0, r9
	subs r0, 0x8
	adds r0, r7, r0
	ldr r2, [r0]
	ldr r0, [sp]
	bl SetTaskFuncWithFollowupFunc
_081C0B5C:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x000040c0
	adds r0, r2
	ldrb r0, [r0]
	bl sub_81C2DE4
	bl sub_81C424C
_081C0B6E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0A8C

	thumb_func_start sub_81C0B8C
sub_81C0B8C: @ 81C0B8C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C0C2A
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r3, =0x000040c9
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0BE0
	movs r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	b _081C0BFE
	.pool
_081C0BE0:
	movs r0, 0x2
	strh r0, [r4, 0x2]
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
_081C0BFE:
	ldrb r0, [r4, 0x2]
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	ldrb r0, [r4, 0x2]
	ldr r1, =gUnknown_0203CF1C
	ldr r1, [r1]
	ldr r3, =0x000040c0
	adds r2, r1, r3
	ldrb r2, [r2]
	lsls r2, 12
	adds r2, 0xBC
	adds r1, r2
	bl SetBgTilemapBuffer
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
_081C0C2A:
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x1
	bl ChangeBgX
	ldrh r0, [r4]
	adds r0, 0x20
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081C0C52
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C0C68
	str r0, [r1]
_081C0C52:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0B8C

	thumb_func_start sub_81C0C68
sub_81C0C68: @ 81C0C68
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldr r5, =gUnknown_0203CF1C
	ldr r3, [r5]
	ldr r0, =0x000040c9
	adds r3, r0
	ldrb r0, [r3]
	movs r1, 0x1
	eors r0, r1
	movs r1, 0
	strb r0, [r3]
	strh r1, [r2, 0x2]
	strh r1, [r2]
	bl sub_81C1BA0
	ldr r0, [r5]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C2AFC
	bl sub_81C4280
	bl sub_81C0E24
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0C68

	thumb_func_start sub_81C0CC4
sub_81C0CC4: @ 81C0CC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C0D0C
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0CFC
	movs r0, 0x2
	b _081C0CFE
	.pool
_081C0CFC:
	movs r0, 0x1
_081C0CFE:
	strh r0, [r4, 0x2]
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 9
	movs r2, 0
	bl ChangeBgX
_081C0D0C:
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x2
	bl ChangeBgX
	ldrh r0, [r4]
	adds r0, 0x20
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081C0D34
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C0D44
	str r0, [r1]
_081C0D34:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0CC4

	thumb_func_start sub_81C0D44
sub_81C0D44: @ 81C0D44
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0D8C
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	b _081C0DA6
	.pool
_081C0D8C:
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_081C0DA6:
	ldr r6, =gUnknown_0203CF1C
	ldr r2, [r6]
	ldr r7, =0x000040c0
	adds r1, r2, r7
	ldrb r0, [r1]
	cmp r0, 0x1
	bls _081C0DD0
	ldrb r0, [r4, 0x2]
	ldrb r1, [r1]
	lsls r1, 12
	ldr r3, =0xfffff0bc
	adds r1, r3
	adds r1, r2, r1
	bl SetBgTilemapBuffer
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 9
	movs r2, 0
	bl ChangeBgX
_081C0DD0:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r2, [r6]
	ldr r0, =0x000040c9
	adds r2, r0
	ldrb r0, [r2]
	movs r1, 0x1
	eors r0, r1
	movs r1, 0
	strb r0, [r2]
	strh r1, [r4, 0x2]
	strh r1, [r4]
	bl sub_81C1BA0
	ldr r0, [r6]
	adds r0, r7
	ldrb r0, [r0]
	bl sub_81C2AFC
	bl sub_81C4280
	bl sub_81C0E24
	adds r0, r5, 0
	bl SwitchTaskToFollowupFunc
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0D44

	thumb_func_start sub_81C0E24
sub_81C0E24: @ 81C0E24
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C0E3C
	adds r0, r1, 0
	adds r0, 0xC
	bl sub_81C22CC
_081C0E3C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0E24

	thumb_func_start sub_81C0E48
sub_81C0E48: @ 81C0E48
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r2, =0x000040c6
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r5]
	adds r2, r1, r2
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r6, [r1]
	mov r8, r6
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C0E96
	movs r0, 0xD
	bl ClearWindowTilemap
_081C0E96:
	movs r4, 0x3
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_81C1EFC
	ldr r0, [r5]
	ldr r1, =0x000040c8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0EC4
	movs r0, 0x5
	bl ClearWindowTilemap
	movs r0, 0x6
	bl PutWindowTilemap
_081C0EC4:
	ldr r0, [r5]
	ldr r1, =0x000020bc
	adds r0, r1
	movs r1, 0x3
	movs r2, 0
	bl sub_81C2194
	ldr r0, [r5]
	ldr r1, =0x000030bc
	adds r0, r1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C2194
	mov r0, r8
	bl sub_81C3E9C
	bl sub_81C3F44
	bl sub_81C44F0
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x8
	bl sub_81C4AF8
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C0F44
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0E48

	thumb_func_start sub_81C0F44
sub_81C0F44: @ 81C0F44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C103A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C0F98
	movs r0, 0x4
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	b _081C103A
	.pool
_081C0F98:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C0FC0
	movs r0, 0x4
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	b _081C103A
	.pool
_081C0FC0:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C1026
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C0FE8
	subs r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	bne _081C1004
_081C0FE8:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81C11F4
	b _081C103A
	.pool
_081C1004:
	bl sub_81C1040
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C101E
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81C129C
	b _081C103A
_081C101E:
	movs r0, 0x20
	bl audio_play
	b _081C103A
_081C1026:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C103A
	movs r0, 0x5
	bl audio_play
	adds r0, r6, 0
	bl sub_81C11F4
_081C103A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C0F44

	thumb_func_start sub_81C1040
sub_81C1040: @ 81C1040
	push {lr}
	movs r1, 0x1
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0x84
_081C104C:
	lsls r0, r1, 1
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, 0
	beq _081C1060
	movs r0, 0x1
	b _081C106C
	.pool
_081C1060:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081C104C
	movs r0, 0
_081C106C:
	pop {r1}
	bx r1
	thumb_func_end sub_81C1040

	thumb_func_start sub_81C1070
sub_81C1070: @ 81C1070
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r4, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl audio_play
	mov r0, r8
	ldrb r6, [r0]
	movs r2, 0
	lsls r4, 24
	asrs r4, 24
	mov r12, r4
	movs r1, 0
	ldrsh r4, [r7, r1]
	ldrb r0, [r7]
	lsls r3, r0, 24
_081C109C:
	lsls r0, r6, 24
	asrs r0, 24
	add r0, r12
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r0, 24
	cmp r0, r4
	ble _081C10B0
	movs r6, 0
	b _081C10B6
_081C10B0:
	cmp r0, 0
	bge _081C10B6
	lsrs r6, r3, 24
_081C10B6:
	lsls r0, r6, 24
	asrs r1, r0, 24
	mov r9, r0
	cmp r1, 0x4
	bne _081C10C2
	b _081C11CC
_081C10C2:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	lsls r1, 1
	adds r0, 0x84
	adds r0, r1
	ldrh r5, [r0]
	cmp r5, 0
	bne _081C10E2
	lsls r0, r2, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _081C109C
_081C10E2:
	adds r0, r5, 0
	bl sub_81C240C
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C3E9C
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x4
	bne _081C1110
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081C1118
_081C1110:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	bne _081C115E
_081C1118:
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1142
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1142:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r4, 0x3
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81C1EFC
_081C115E:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _081C11A0
	mov r1, r9
	asrs r0, r1, 24
	cmp r0, 0x4
	bne _081C11A0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _081C11A0
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xF
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0x3
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	bl sub_81C1EFC
_081C11A0:
	mov r0, r8
	strb r6, [r0]
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c6
	adds r0, r1
	cmp r8, r0
	bne _081C11E0
	movs r0, 0x8
	bl sub_81C4D18
	b _081C11E6
	.pool
_081C11CC:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	ldrh r5, [r0]
	b _081C10E2
	.pool
_081C11E0:
	movs r0, 0x12
	bl sub_81C4D18
_081C11E6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C1070

	thumb_func_start sub_81C11F4
sub_81C11F4: @ 81C11F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x8
	bl sub_81C4C60
	movs r0, 0x6
	bl ClearWindowTilemap
	movs r0, 0x5
	bl PutWindowTilemap
	movs r0, 0
	bl sub_81C3E9C
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000020bc
	adds r0, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_81C2194
	ldr r0, [r4]
	ldr r1, =0x000030bc
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_81C2194
	bl sub_81C4064
	ldr r0, [r4]
	ldr r1, =0x000040c6
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _081C125E
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xF
	bl ClearWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	bl sub_81C1EFC
_081C125E:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C0510
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C11F4

	thumb_func_start sub_81C129C
sub_81C129C: @ 81C129C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x000040c6
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r2, 0x1
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C4C84
	movs r0, 0x12
	bl sub_81C4AF8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C12E4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C129C

	thumb_func_start sub_81C12E4
sub_81C12E4: @ 81C12E4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C13AA
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C1338
	movs r0, 0x3
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c7
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	b _081C13AA
	.pool
_081C1338:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C1360
	movs r0, 0x3
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c7
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	b _081C13AA
	.pool
_081C1360:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C139A
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x000040c6
	adds r1, r0, r2
	adds r2, 0x1
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _081C1390
	adds r0, r5, 0
	movs r1, 0
	bl sub_81C13B0
	b _081C13AA
	.pool
_081C1390:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C13B0
	b _081C13AA
_081C139A:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C13AA
	adds r0, r6, 0
	movs r1, 0
	bl sub_81C13B0
_081C13AA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C12E4

	thumb_func_start sub_81C13B0
sub_81C13B0: @ 81C13B0
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C4C84
	movs r0, 0x12
	bl sub_81C4C60
	cmp r4, 0x1
	bne _081C1464
	ldr r0, =gUnknown_0203CF1C
	ldr r3, [r0]
	ldr r1, =0x000040bd
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C1410
	ldr r0, [r3]
	ldr r2, =0x000040be
	adds r1, r3, r2
	ldrb r2, [r1]
	movs r1, 0x64
	muls r1, r2
	adds r0, r1
	ldr r4, =0x000040c6
	adds r1, r3, r4
	ldrb r1, [r1]
	adds r4, 0x1
	adds r2, r3, r4
	ldrb r2, [r2]
	bl sub_81C14BC
	b _081C1430
	.pool
_081C1410:
	ldr r0, [r3]
	ldr r2, =0x000040be
	adds r1, r3, r2
	ldrb r2, [r1]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 4
	adds r0, r1
	ldr r4, =0x000040c6
	adds r1, r3, r4
	ldrb r1, [r1]
	adds r4, 0x1
	adds r2, r3, r4
	ldrb r2, [r2]
	bl sub_81C15EC
_081C1430:
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	adds r0, 0xC
	bl sub_81C0098
	ldr r1, [r5]
	ldr r6, =0x000040c6
	adds r0, r1, r6
	ldrb r0, [r0]
	ldr r4, =0x000040c7
	adds r1, r4
	ldrb r1, [r1]
	bl sub_81C40A0
	ldr r1, [r5]
	adds r0, r1, r6
	ldrb r0, [r0]
	adds r1, r4
	ldrb r1, [r1]
	bl sub_81C4568
	ldr r0, [r5]
	adds r4, r0, r4
	ldrb r1, [r4]
	adds r0, r6
	strb r1, [r0]
_081C1464:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r4, [r1]
	adds r0, r4, 0
	bl sub_81C3E9C
	adds r0, r4, 0
	bl sub_81C240C
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C0F44
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C13B0

	thumb_func_start sub_81C14BC
sub_81C14BC: @ 81C14BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	lsls r0, r4, 1
	mov r10, r0
	adds r1, r2, 0
	adds r1, 0x84
	adds r0, r1, r0
	str r0, [sp, 0x8]
	ldrh r0, [r0]
	mov r3, sp
	adds r3, 0x2
	str r3, [sp, 0x1C]
	strh r0, [r3]
	lsls r0, r6, 1
	mov r9, r0
	add r1, r9
	str r1, [sp, 0xC]
	ldrh r1, [r1]
	mov r0, sp
	strh r1, [r0]
	adds r1, r2, 0
	adds r1, 0x8C
	adds r3, r1, r4
	str r3, [sp, 0x10]
	ldrb r0, [r3]
	mov r3, sp
	adds r3, 0x5
	str r3, [sp, 0x24]
	strb r0, [r3]
	adds r1, r6
	str r1, [sp, 0x14]
	ldrb r0, [r1]
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x20]
	strb r0, [r1]
	adds r2, 0xA4
	str r2, [sp, 0x18]
	ldrb r0, [r2]
	mov r5, sp
	adds r5, 0x6
	strb r0, [r5]
	ldr r1, =gUnknown_08329D22
	adds r0, r4, r1
	ldrb r0, [r0]
	mov r8, r0
	ldrb r0, [r5]
	adds r2, r0, 0
	mov r3, r8
	ands r2, r3
	mov r3, r10
	asrs r2, r3
	lsls r2, 24
	lsrs r2, 24
	adds r1, r6, r1
	ldrb r1, [r1]
	mov r12, r1
	adds r1, r0, 0
	mov r3, r12
	ands r1, r3
	mov r3, r9
	asrs r1, r3
	lsls r1, 24
	lsrs r1, 24
	mov r3, r8
	bics r0, r3
	strb r0, [r5]
	ldrb r0, [r5]
	mov r3, r12
	bics r0, r3
	strb r0, [r5]
	mov r0, r9
	lsls r2, r0
	mov r3, r10
	lsls r1, r3
	adds r2, r1
	ldrb r0, [r5]
	orrs r0, r2
	strb r0, [r5]
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r7, 0
	mov r2, sp
	bl SetMonData
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r7, 0
	ldr r2, [sp, 0x1C]
	bl SetMonData
	adds r4, 0x11
	adds r0, r7, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x20]
	bl SetMonData
	adds r6, 0x11
	adds r0, r7, 0
	adds r1, r6, 0
	ldr r2, [sp, 0x24]
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x15
	adds r2, r5, 0
	bl SetMonData
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, [sp, 0x8]
	strh r0, [r1]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	ldr r3, [sp, 0x20]
	ldrb r0, [r3]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	ldr r3, [sp, 0x24]
	ldrb r0, [r3]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	ldrb r0, [r5]
	ldr r3, [sp, 0x18]
	strb r0, [r3]
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C14BC

	thumb_func_start sub_81C15EC
sub_81C15EC: @ 81C15EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	lsls r0, r4, 1
	mov r10, r0
	adds r1, r2, 0
	adds r1, 0x84
	adds r0, r1, r0
	str r0, [sp, 0x8]
	ldrh r0, [r0]
	mov r3, sp
	adds r3, 0x2
	str r3, [sp, 0x1C]
	strh r0, [r3]
	lsls r0, r6, 1
	mov r9, r0
	add r1, r9
	str r1, [sp, 0xC]
	ldrh r1, [r1]
	mov r0, sp
	strh r1, [r0]
	adds r1, r2, 0
	adds r1, 0x8C
	adds r3, r1, r4
	str r3, [sp, 0x10]
	ldrb r0, [r3]
	mov r3, sp
	adds r3, 0x5
	str r3, [sp, 0x24]
	strb r0, [r3]
	adds r1, r6
	str r1, [sp, 0x14]
	ldrb r0, [r1]
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x20]
	strb r0, [r1]
	adds r2, 0xA4
	str r2, [sp, 0x18]
	ldrb r0, [r2]
	mov r5, sp
	adds r5, 0x6
	strb r0, [r5]
	ldr r1, =gUnknown_08329D22
	adds r0, r4, r1
	ldrb r0, [r0]
	mov r8, r0
	ldrb r0, [r5]
	adds r2, r0, 0
	mov r3, r8
	ands r2, r3
	mov r3, r10
	asrs r2, r3
	lsls r2, 24
	lsrs r2, 24
	adds r1, r6, r1
	ldrb r1, [r1]
	mov r12, r1
	adds r1, r0, 0
	mov r3, r12
	ands r1, r3
	mov r3, r9
	asrs r1, r3
	lsls r1, 24
	lsrs r1, 24
	mov r3, r8
	bics r0, r3
	strb r0, [r5]
	ldrb r0, [r5]
	mov r3, r12
	bics r0, r3
	strb r0, [r5]
	mov r0, r9
	lsls r2, r0
	mov r3, r10
	lsls r1, r3
	adds r2, r1
	ldrb r0, [r5]
	orrs r0, r2
	strb r0, [r5]
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r7, 0
	mov r2, sp
	bl SetMonData_encrypted
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r7, 0
	ldr r2, [sp, 0x1C]
	bl SetMonData_encrypted
	adds r4, 0x11
	adds r0, r7, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x20]
	bl SetMonData_encrypted
	adds r6, 0x11
	adds r0, r7, 0
	adds r1, r6, 0
	ldr r2, [sp, 0x24]
	bl SetMonData_encrypted
	adds r0, r7, 0
	movs r1, 0x15
	adds r2, r5, 0
	bl SetMonData_encrypted
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, [sp, 0x8]
	strh r0, [r1]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	ldr r3, [sp, 0x20]
	ldrb r0, [r3]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	ldr r3, [sp, 0x24]
	ldrb r0, [r3]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	ldrb r0, [r5]
	ldr r3, [sp, 0x18]
	strb r0, [r3]
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C15EC

	thumb_func_start sub_81C171C
sub_81C171C: @ 81C171C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81C44F0
	movs r0, 0x8
	bl sub_81C4AF8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C174C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C171C

	thumb_func_start sub_81C174C
sub_81C174C: @ 81C174C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C176A
	b _081C189A
_081C176A:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r2, 0x80
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _081C177A
	b _081C189A
_081C177A:
	ldr r6, =gMain
	ldrh r1, [r6, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C17B4
	movs r0, 0x4
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	b _081C189A
	.pool
_081C17B4:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _081C17DC
	movs r0, 0x4
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r1, =0x000040c6
	adds r2, r1
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	b _081C189A
	.pool
_081C17DC:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C17F0
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C17FC
_081C17F0:
	movs r1, 0x1
	negs r1, r1
	adds r0, r5, 0
	bl sub_81C0A8C
	b _081C189A
_081C17FC:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C1812
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C181C
_081C1812:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C0A8C
	b _081C189A
_081C181C:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C1876
	bl sub_81C18A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C1868
	bl sub_81C48F0
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_0203CF21
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c6
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, =gUnknown_020375E2
	ldrb r0, [r2]
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_81C044C
	b _081C189A
	.pool
_081C1868:
	movs r0, 0x20
	bl audio_play
	adds r0, r5, 0
	bl sub_81C18F4
	b _081C189A
_081C1876:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C189A
	bl sub_81C48F0
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_0203CF21
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, =gUnknown_020375E2
	movs r0, 0x4
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_81C044C
_081C189A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C174C

	thumb_func_start sub_81C18A8
sub_81C18A8: @ 81C18A8
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _081C18DA
	ldr r3, =0x000040c4
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _081C18DA
	ldrb r1, [r1]
	lsls r1, 1
	adds r0, r2, 0
	adds r0, 0x84
	adds r0, r1
	ldrh r0, [r0]
	bl sub_81B6D14
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C18EC
_081C18DA:
	movs r0, 0x1
	b _081C18EE
	.pool
_081C18EC:
	movs r0, 0
_081C18EE:
	pop {r1}
	bx r1
	thumb_func_end sub_81C18A8

	thumb_func_start sub_81C18F4
sub_81C18F4: @ 81C18F4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xF
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0x3
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	bl sub_81C1EFC
	bl sub_81C4154
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C1940
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C18F4

	thumb_func_start sub_81C1940
sub_81C1940: @ 81C1940
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	mov r8, r0
	ldr r0, =gTasks + 0x8
	mov r9, r0
	mov r4, r8
	add r4, r9
	ldr r0, =sub_81C1E20
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C196C
	b _081C1B74
_081C196C:
	ldr r6, =gMain
	ldrh r1, [r6, 0x2E]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C19B0
	movs r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x4
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	movs r0, 0
	strh r0, [r4, 0x2]
	b _081C1B6A
	.pool
_081C19B0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C19DC
	movs r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x4
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r1, =0x000040c6
	adds r2, r1
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	strh r5, [r4, 0x2]
	b _081C1B6A
	.pool
_081C19DC:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C19F0
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C1A64
_081C19F0:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r2, =0x000040c0
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C1A00
	b _081C1B74
_081C1A00:
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, [r4]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1A28
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1A28:
	ldr r1, [r4]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r5, [r1]
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_81C174C
	str r1, [r0]
	movs r1, 0x1
	negs r1, r1
	adds r0, r7, 0
	b _081C1ACE
	.pool
_081C1A64:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C1A7A
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C1B04
_081C1A7A:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _081C1B74
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, [r4]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1AB0
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1AB0:
	ldr r1, [r4]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r5, [r1]
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_81C174C
	str r1, [r0]
	adds r0, r7, 0
	movs r1, 0x1
_081C1ACE:
	bl sub_81C0A8C
	movs r4, 0x2
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81C1EFC
	b _081C1B74
	.pool
_081C1B04:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081C1B74
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1B38
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1B38:
	ldr r1, [r4]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r5, [r1]
	adds r0, r5, 0
	bl sub_81C3E9C
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r4, 0x3
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81C1EFC
_081C1B6A:
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_81C174C
	str r1, [r0]
_081C1B74:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1940

	thumb_func_start sub_81C1B94
sub_81C1B94: @ 81C1B94
	ldr r0, =gUnknown_0203CF21
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81C1B94

	thumb_func_start sub_81C1BA0
sub_81C1BA0: @ 81C1BA0
	push {r4-r7,lr}
	sub sp, 0xC
	movs r0, 0x20
	bl Alloc
	adds r4, r0, 0
	movs r5, 0
_081C1BAE:
	lsls r0, r5, 25
	lsrs r1, r0, 24
	adds r6, r1, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r3, [r0]
	ldr r2, =0x000040c1
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081C1BD8
	lsls r0, r1, 1
	adds r0, r4
	movs r1, 0x40
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x50
	b _081C1BEE
	.pool
_081C1BD8:
	ldr r7, =0x000040c2
	adds r0, r3, r7
	ldrb r2, [r0]
	cmp r5, r2
	bls _081C1BF8
	lsls r0, r1, 1
	adds r0, r4
	movs r1, 0x4A
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x5A
_081C1BEE:
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	b _081C1C78
	.pool
_081C1BF8:
	ldr r7, =0x000040c0
	adds r0, r3, r7
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081C1C1C
	lsls r1, 1
	adds r1, r4
	movs r0, 0x46
	strh r0, [r1]
	movs r0, 0x47
	strh r0, [r1, 0x2]
	movs r0, 0x56
	strh r0, [r1, 0x10]
	movs r0, 0x57
	b _081C1C76
	.pool
_081C1C1C:
	cmp r5, r0
	bne _081C1C4C
	cmp r5, r2
	beq _081C1C38
	lsls r1, 1
	adds r1, r4
	movs r0, 0x41
	strh r0, [r1]
	movs r0, 0x42
	strh r0, [r1, 0x2]
	movs r0, 0x51
	strh r0, [r1, 0x10]
	movs r0, 0x52
	b _081C1C76
_081C1C38:
	lsls r1, 1
	adds r1, r4
	movs r0, 0x4B
	strh r0, [r1]
	movs r0, 0x4C
	strh r0, [r1, 0x2]
	movs r0, 0x5B
	strh r0, [r1, 0x10]
	movs r0, 0x5C
	b _081C1C76
_081C1C4C:
	cmp r5, r2
	beq _081C1C64
	lsls r1, 1
	adds r1, r4
	movs r0, 0x43
	strh r0, [r1]
	movs r0, 0x44
	strh r0, [r1, 0x2]
	movs r0, 0x53
	strh r0, [r1, 0x10]
	movs r0, 0x54
	b _081C1C76
_081C1C64:
	lsls r1, r6, 1
	adds r1, r4
	movs r0, 0x48
	strh r0, [r1]
	movs r0, 0x49
	strh r0, [r1, 0x2]
	movs r0, 0x58
	strh r0, [r1, 0x10]
	movs r0, 0x59
_081C1C76:
	strh r0, [r1, 0x12]
_081C1C78:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _081C1BAE
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0xB
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r4, 0
	bl Free
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C1BA0

	thumb_func_start sub_81C1CB0
sub_81C1CB0: @ 81C1CB0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r5, r3, 24
	ldrb r1, [r4, 0x6]
	ldrb r0, [r4, 0x7]
	lsls r0, 1
	muls r0, r1
	bl Alloc
	adds r7, r0, 0
	mov r1, sp
	ldrh r0, [r4, 0x4]
	strh r0, [r1]
	ldrb r1, [r4, 0x7]
	ldrb r0, [r4, 0x6]
	adds r2, r1, 0
	muls r2, r0
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	adds r1, r7, 0
	bl CpuSet
	ldrb r0, [r4, 0x6]
	cmp r0, r6
	beq _081C1D60
	cmp r5, 0
	bne _081C1D30
	movs r5, 0
	ldrb r0, [r4, 0x7]
	cmp r5, r0
	bcs _081C1D60
_081C1D00:
	ldrb r2, [r4, 0x6]
	adds r1, r2, 0
	muls r1, r5
	adds r3, r6, r1
	lsls r3, 1
	ldr r0, [r4]
	adds r0, r3
	lsls r1, 1
	adds r1, r7, r1
	subs r2, r6
	ldr r3, =0x001fffff
	ands r2, r3
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r3, [r4, 0x7]
	cmp r5, r3
	bcc _081C1D00
	b _081C1D60
	.pool
_081C1D30:
	movs r5, 0
	ldrb r0, [r4, 0x7]
	cmp r5, r0
	bcs _081C1D60
_081C1D38:
	ldrb r2, [r4, 0x6]
	adds r1, r2, 0
	muls r1, r5
	lsls r3, r1, 1
	ldr r0, [r4]
	adds r0, r3
	adds r1, r6, r1
	lsls r1, 1
	adds r1, r7, r1
	subs r2, r6
	ldr r3, =0x001fffff
	ands r2, r3
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r3, [r4, 0x7]
	cmp r5, r3
	bcc _081C1D38
_081C1D60:
	movs r5, 0
	b _081C1D8A
	.pool
_081C1D68:
	ldrb r2, [r4, 0x6]
	adds r0, r2, 0
	muls r0, r5
	lsls r0, 1
	adds r0, r7, r0
	ldrb r1, [r4, 0x9]
	adds r1, r5
	lsls r1, 5
	ldrb r3, [r4, 0x8]
	adds r1, r3
	lsls r1, 1
	add r1, r8
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_081C1D8A:
	ldrb r0, [r4, 0x7]
	cmp r5, r0
	bcc _081C1D68
	adds r0, r7, 0
	bl Free
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C1CB0

	thumb_func_start sub_81C1DA4
sub_81C1DA4: @ 81C1DA4
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_0861CC04
	ldrb r2, [r3, 0x6]
	cmp r1, r2
	ble _081C1DBA
	adds r4, r2, 0
_081C1DBA:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	beq _081C1DC6
	cmp r0, r2
	bne _081C1DE8
_081C1DC6:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r0, =0x000020bc
	adds r1, r0
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_81C1CB0
	b _081C1E12
	.pool
_081C1DE8:
	ldr r5, =sub_81C1E20
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _081C1E04
	adds r0, r5, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
_081C1E04:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	strh r6, [r0, 0xA]
_081C1E12:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1DA4

	thumb_func_start sub_81C1E20
sub_81C1E20: @ 81C1E20
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _081C1E50
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r7, =gUnknown_0861CC04
	b _081C1E60
	.pool
_081C1E50:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gUnknown_0861CC04
	ldrb r2, [r0, 0x6]
	adds r7, r0, 0
	cmp r1, r2
	ble _081C1E60
	strh r2, [r4, 0x2]
_081C1E60:
	ldr r5, =gUnknown_0203CF1C
	ldr r1, [r5]
	ldr r0, =0x000020bc
	adds r1, r0
	ldrb r2, [r4, 0x2]
	adds r0, r7, 0
	movs r3, 0x1
	bl sub_81C1CB0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _081C1E80
	ldrb r7, [r7, 0x6]
	cmp r0, r7
	blt _081C1EE0
_081C1E80:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _081C1EAC
	ldr r0, [r5]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C1ED4
	movs r0, 0xE
	bl PutWindowTilemap
	b _081C1ED4
	.pool
_081C1EAC:
	ldr r2, =gSprites
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1ECE
	movs r0, 0xD
	bl PutWindowTilemap
_081C1ECE:
	movs r0, 0x13
	bl PutWindowTilemap
_081C1ED4:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl DestroyTask
_081C1EE0:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1E20

	thumb_func_start sub_81C1EFC
sub_81C1EFC: @ 81C1EFC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_0861CC10
	ldrb r2, [r3, 0x6]
	cmp r1, r2
	ble _081C1F16
	adds r4, r2, 0
_081C1F16:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	beq _081C1F22
	cmp r0, r2
	bne _081C1F44
_081C1F22:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r0, =0x000030bc
	adds r1, r0
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_81C1CB0
	b _081C1F70
	.pool
_081C1F44:
	ldr r5, =sub_81C1F80
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _081C1F60
	adds r0, r5, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
_081C1F60:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	strh r7, [r0, 0xA]
	strh r6, [r0, 0xC]
_081C1F70:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1EFC

	thumb_func_start sub_81C1F80
sub_81C1F80: @ 81C1F80
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _081C1FB0
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r7, =gUnknown_0861CC10
	b _081C1FC0
	.pool
_081C1FB0:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gUnknown_0861CC10
	ldrb r2, [r0, 0x6]
	adds r7, r0, 0
	cmp r1, r2
	ble _081C1FC0
	strh r2, [r4, 0x2]
_081C1FC0:
	ldr r5, =gUnknown_0203CF1C
	ldr r1, [r5]
	ldr r0, =0x000030bc
	adds r1, r0
	ldrb r2, [r4, 0x2]
	adds r0, r7, 0
	movs r3, 0x1
	bl sub_81C1CB0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _081C1FE0
	ldrb r7, [r7, 0x6]
	cmp r0, r7
	blt _081C2058
_081C1FE0:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _081C2024
	ldr r0, [r5]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2006
	ldr r0, =sub_81C0B8C
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _081C2006
	movs r0, 0xF
	bl PutWindowTilemap
_081C2006:
	ldrh r0, [r4, 0x4]
	bl sub_81C240C
	b _081C204C
	.pool
_081C2024:
	ldr r2, =gSprites
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C2046
	movs r0, 0xD
	bl PutWindowTilemap
_081C2046:
	movs r0, 0x13
	bl PutWindowTilemap
_081C204C:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl DestroyTask
_081C2058:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1F80

	thumb_func_start sub_81C2074
sub_81C2074: @ 81C2074
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_0861CBEC
	ldrb r2, [r3, 0x6]
	cmp r1, r2
	ble _081C208A
	adds r4, r2, 0
_081C208A:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	beq _081C2096
	cmp r0, r2
	bne _081C20C8
_081C2096:
	ldr r5, =gUnknown_0203CF1C
	ldr r1, [r5]
	adds r1, 0xBC
	lsls r4, 24
	lsrs r4, 24
	adds r0, r3, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_81C1CB0
	ldr r0, =gUnknown_0861CBF8
	ldr r1, [r5]
	adds r1, 0xBC
	adds r2, r4, 0
	movs r3, 0
	bl sub_81C1CB0
	b _081C20E2
	.pool
_081C20C8:
	ldr r0, =sub_81C20F0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	strh r5, [r1, 0xA]
_081C20E2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2074

	thumb_func_start sub_81C20F0
sub_81C20F0: @ 81C20F0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrh r0, [r5]
	ldrh r1, [r5, 0x2]
	adds r0, r1
	strh r0, [r5, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _081C2120
	movs r0, 0
	strh r0, [r5, 0x2]
	ldr r7, =gUnknown_0861CBEC
	b _081C2130
	.pool
_081C2120:
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	ldr r0, =gUnknown_0861CBEC
	ldrb r2, [r0, 0x6]
	adds r7, r0, 0
	cmp r1, r2
	ble _081C2130
	strh r2, [r5, 0x2]
_081C2130:
	ldr r4, =gUnknown_0203CF1C
	ldr r1, [r4]
	adds r1, 0xBC
	ldrb r2, [r5, 0x2]
	adds r0, r7, 0
	movs r3, 0
	bl sub_81C1CB0
	ldr r0, =gUnknown_0861CBF8
	ldr r1, [r4]
	adds r1, 0xBC
	ldrb r2, [r5, 0x2]
	movs r3, 0
	bl sub_81C1CB0
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0
	ble _081C2162
	ldrb r7, [r7, 0x6]
	cmp r0, r7
	blt _081C2180
_081C2162:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _081C217A
	bl sub_81C4A88
	movs r0, 0xD
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
_081C217A:
	adds r0, r6, 0
	bl DestroyTask
_081C2180:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C20F0

	thumb_func_start sub_81C2194
sub_81C2194: @ 81C2194
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r2, 24
	lsls r1, 28
	lsrs r4, r1, 16
	ldr r7, =0x0000056a
	cmp r2, 0
	bne _081C21E4
	movs r3, 0
	ldr r5, =gUnknown_08DC3CD4
_081C21A8:
	adds r2, r7, r3
	lsls r2, 1
	adds r2, r6
	lsls r0, r3, 1
	adds r0, r5
	ldrh r1, [r0]
	adds r1, r4, r1
	strh r1, [r2]
	adds r0, r2, 0
	adds r0, 0x40
	strh r1, [r0]
	adds r2, 0x80
	adds r0, r3, 0
	adds r0, 0x14
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _081C21A8
	b _081C221C
	.pool
_081C21E4:
	movs r3, 0
	ldr r5, =gUnknown_08DC3CD4
_081C21E8:
	adds r1, r7, r3
	lsls r1, 1
	adds r1, r6
	adds r0, r3, 0
	adds r0, 0x14
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r1]
	adds r2, r1, 0
	adds r2, 0x40
	adds r0, r3, 0
	adds r0, 0x28
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r2]
	adds r1, 0x80
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _081C21E8
_081C221C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2194

	thumb_func_start sub_81C2228
sub_81C2228: @ 81C2228
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_806DD7C
	lsls r0, 24
	cmp r0, 0
	bne _081C225C
	adds r0, r4, 0
	movs r1, 0
	bl sub_806DDE4
	lsls r0, 24
	cmp r0, 0
	beq _081C225C
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x00000502
	adds r1, r0, r2
	movs r2, 0x2C
	b _081C2266
	.pool
_081C225C:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x00000502
	adds r1, r0, r2
	ldr r2, =0x0000081a
_081C2266:
	strh r2, [r1]
	ldr r1, =0x00000d02
	adds r0, r1
	strh r2, [r0]
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2228

	thumb_func_start sub_81C228C
sub_81C228C: @ 81C228C
	push {lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081C22AC
	movs r0, 0x8
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0x8
	bl sub_8199C30
	b _081C22C0
_081C22AC:
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0x8
	bl sub_8199C30
_081C22C0:
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81C228C

	thumb_func_start sub_81C22CC
sub_81C22CC: @ 81C22CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r6, r1, 0
	adds r6, 0x70
	ldrb r1, [r6, 0x5]
	mov r8, r0
	cmp r1, 0x63
	bhi _081C2340
	ldr r5, =gExperienceTables
	adds r2, r1, 0
	adds r1, r2, 0x1
	lsls r1, 2
	ldr r4, =gBaseStats
	ldrh r3, [r6]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r4
	ldrb r3, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r3
	adds r1, r0
	adds r1, r5
	lsls r2, 2
	adds r2, r0
	adds r2, r5
	ldr r1, [r1]
	ldr r2, [r2]
	subs r1, r2
	ldr r0, [r6, 0x10]
	subs r4, r0, r2
	lsls r0, r4, 6
	bl __udivsi3
	adds r6, r0, 0
	movs r7, 0
	adds r0, r7, 0
	orrs r0, r6
	cmp r0, 0
	bne _081C2344
	cmp r4, 0
	beq _081C2344
	movs r6, 0x1
	movs r7, 0
	b _081C2344
	.pool
_081C2340:
	movs r6, 0
	movs r7, 0
_081C2344:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00001d66
	adds r2, r0
	mov r9, r2
	movs r0, 0
	mov r12, r0
	ldr r1, =0x00002062
	mov r10, r1
_081C2356:
	cmp r7, 0
	bgt _081C2362
	cmp r7, 0
	bne _081C237C
	cmp r6, 0x7
	bls _081C237C
_081C2362:
	mov r2, r12
	lsls r0, r2, 1
	add r0, r9
	ldr r2, =0x0000206a
	adds r1, r2, 0
	strh r1, [r0]
	b _081C23B6
	.pool
_081C237C:
	mov r1, r12
	lsls r0, r1, 1
	add r0, r9
	mov r8, r0
	adds r5, r7, 0
	adds r4, r6, 0
	cmp r7, 0
	bge _081C2394
	movs r4, 0x7
	movs r5, 0
	adds r4, r6
	adcs r5, r7
_081C2394:
	lsls r3, r5, 29
	lsrs r2, r4, 3
	adds r0, r3, 0
	orrs r0, r2
	asrs r1, r5, 3
	lsrs r5, r0, 29
	lsls r4, r1, 3
	adds r3, r5, 0
	orrs r3, r4
	lsls r2, r0, 3
	adds r1, r7, 0
	adds r0, r6, 0
	subs r0, r2
	sbcs r1, r3
	add r0, r10
	mov r2, r8
	strh r0, [r2]
_081C23B6:
	movs r0, 0x8
	negs r0, r0
	asrs r1, r0, 31
	adds r6, r0
	adcs r7, r1
	cmp r7, 0
	bge _081C23C8
	movs r6, 0
	movs r7, 0
_081C23C8:
	mov r0, r12
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	cmp r0, 0x7
	bls _081C2356
	movs r0, 0x1
	bl GetBgTilemapBuffer
	ldr r1, =gUnknown_0203CF1C
	ldr r1, [r1]
	ldr r2, =0x000010bc
	adds r1, r2
	cmp r0, r1
	bne _081C23F8
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	b _081C23FE
	.pool
_081C23F8:
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
_081C23FE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C22CC

	thumb_func_start sub_81C240C
sub_81C240C: @ 81C240C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000038bc
	adds r5, r0, r1
	cmp r3, 0
	beq _081C2510
	ldr r1, =gContestEffects
	ldr r2, =gContestMoves
	lsls r3, 3
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x1]
	mov r9, r1
	mov r8, r2
	mov r10, r3
	cmp r4, 0xFF
	beq _081C244C
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r4, r0, 24
_081C244C:
	movs r2, 0
	movs r6, 0x3
	movs r3, 0xF3
	lsls r3, 2
_081C2454:
	cmp r4, 0xFF
	beq _081C2484
	cmp r2, r4
	bcs _081C2484
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x0000103a
	b _081C2496
	.pool
_081C2484:
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x00001039
_081C2496:
	adds r1, r7, 0
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _081C2454
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	lsls r0, 2
	add r0, r9
	ldrb r4, [r0, 0x2]
	cmp r4, 0xFF
	beq _081C24C0
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r4, r0, 24
_081C24C0:
	movs r2, 0
	movs r6, 0x3
	ldr r3, =0x0000044c
_081C24C6:
	cmp r4, 0xFF
	beq _081C24F0
	cmp r2, r4
	bcs _081C24F0
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x0000103c
	b _081C2502
	.pool
_081C24F0:
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x0000103d
_081C2502:
	adds r1, r7, 0
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _081C24C6
_081C2510:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C240C

	thumb_func_start sub_81C2524
sub_81C2524: @ 81C2524
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x74
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C2544
	movs r1, 0x80
	lsls r1, 9
	movs r0, 0x3
	movs r2, 0
	bl ChangeBgX
	b _081C254E
	.pool
_081C2544:
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
_081C254E:
	pop {r0}
	bx r0
	thumb_func_end sub_81C2524

	thumb_func_start sub_81C2554
sub_81C2554: @ 81C2554
	push {r4,r5,lr}
	ldr r0, =gUnknown_0861CC24
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r4, 0
_081C2562:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _081C2562
	movs r4, 0
	ldr r5, =gUnknown_0203CF1C
	ldr r3, =0x000040cb
	movs r2, 0xFF
_081C257C:
	ldr r0, [r5]
	adds r0, r3
	adds r0, r4
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C257C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2554

	thumb_func_start sub_81C25A4
sub_81C25A4: @ 81C25A4
	push {r4-r6,lr}
	sub sp, 0x14
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r6, 0
	str r6, [sp]
	str r4, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861CD2C
	adds r4, r5
	str r4, [sp, 0x8]
	str r6, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C25A4

	thumb_func_start sub_81C25E8
sub_81C25E8: @ 81C25E8
	push {lr}
	movs r0, 0x11
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x12
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x13
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x74
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C2618
	bl sub_81C2628
	b _081C261C
	.pool
_081C2618:
	bl sub_81C2794
_081C261C:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C25E8

	thumb_func_start sub_81C2628
sub_81C2628: @ 81C2628
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	movs r1, 0xC
	adds r1, r0
	mov r8, r1
	adds r7, r0, 0
	adds r7, 0x70
	ldrh r0, [r7]
	bl sub_806E3C0
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _081C26CE
	ldr r6, =gStringVar1
	ldr r1, =gUnknown_085E8D4F
	adds r0, r6, 0
	bl StringCopy
	ldr r4, =gStringVar2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringAppend
	mov r0, r8
	bl sub_806EBA4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _081C26AC
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x11
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0
	bl sub_81C228C
	b _081C26C6
	.pool
_081C26AC:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0x1
	bl sub_81C228C
_081C26C6:
	movs r0, 0x11
	bl PutWindowTilemap
	b _081C26EE
_081C26CE:
	movs r0, 0x11
	bl ClearWindowTilemap
	mov r0, r8
	bl sub_806EBA4
	lsls r0, 24
	cmp r0, 0
	bne _081C26E8
	movs r0, 0
	bl sub_81C228C
	b _081C26EE
_081C26E8:
	movs r0, 0x1
	bl sub_81C228C
_081C26EE:
	ldr r4, =gStringVar1
	ldr r1, =gUnknown_085E8D4D
	adds r0, r4, 0
	bl StringCopy
	ldr r5, =gStringVar2
	ldrb r1, [r7, 0x5]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	adds r1, r5, 0
	bl StringAppend
	movs r6, 0
	str r6, [sp]
	movs r5, 0x1
	str r5, [sp, 0x4]
	movs r0, 0x13
	adds r1, r4, 0
	movs r2, 0x18
	movs r3, 0x11
	bl sub_81C25A4
	mov r0, r8
	adds r1, r4, 0
	bl GetMonNickname
	str r6, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x12
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add r1, sp, 0x8
	movs r0, 0xBA
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x9
	ldrh r2, [r7, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	str r6, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x13
	add r1, sp, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldrh r1, [r7, 0x2]
	mov r0, r8
	bl sub_81C27DC
	movs r0, 0x12
	bl PutWindowTilemap
	movs r0, 0x13
	bl PutWindowTilemap
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2628

	thumb_func_start sub_81C2794
sub_81C2794: @ 81C2794
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	ldr r4, =gStringVar1
	adds r1, r4, 0
	bl GetMonNickname
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x12
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0x12
	bl PutWindowTilemap
	movs r0, 0x11
	bl ClearWindowTilemap
	movs r0, 0x13
	bl ClearWindowTilemap
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2794

	thumb_func_start sub_81C27DC
sub_81C27DC: @ 81C27DC
	push {lr}
	sub sp, 0x8
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x20
	beq _081C282C
	cmp r1, 0x1D
	beq _081C282C
	bl pokemon_get_gender
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081C27FE
	cmp r0, 0xFE
	beq _081C2818
	b _081C282C
_081C27FE:
	ldr r1, =gUnknown_085E8D49
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x13
	movs r2, 0x39
	movs r3, 0x11
	bl sub_81C25A4
	b _081C282C
	.pool
_081C2818:
	ldr r1, =gUnknown_085E8D4B
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x13
	movs r2, 0x39
	movs r3, 0x11
	bl sub_81C25A4
_081C282C:
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C27DC

	thumb_func_start sub_81C2838
sub_81C2838: @ 81C2838
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	ldr r3, =gUnknown_0861CDD3
	cmp r1, 0
	bne _081C284A
	subs r3, 0x80
_081C284A:
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x10
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r3, 0
	movs r3, 0
	bl BlitBitmapToWindow
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2838

	thumb_func_start sub_81C286C
sub_81C286C: @ 81C286C
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, =gUnknown_085EA3CF
	movs r5, 0
	str r5, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	movs r0, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3DC
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3EB
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x2
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3F8
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x3
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r7, =gUnknown_085E8CF7
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x3E
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	adds r2, r4, 0
	subs r2, 0x10
	cmp r2, 0
	bge _081C28CC
	movs r2, 0
_081C28CC:
	movs r0, 0x4
	movs r1, 0
	bl sub_81C2838
	lsls r2, r4, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x4
	adds r1, r7, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r7, =gUnknown_085EA406
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x3E
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	adds r2, r4, 0
	subs r2, 0x10
	cmp r2, 0
	bge _081C28FE
	movs r2, 0
_081C28FE:
	movs r0, 0x5
	movs r1, 0
	bl sub_81C2838
	lsls r2, r4, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x5
	adds r1, r7, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r7, =gUnknown_085EA3C8
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x3E
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	adds r2, r4, 0
	subs r2, 0x10
	cmp r2, 0
	bge _081C2930
	movs r2, 0
_081C2930:
	movs r0, 0x6
	movs r1, 0
	bl sub_81C2838
	lsls r2, r4, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x6
	adds r1, r7, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA369
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA378
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x9
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA361
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringCenterAlignXOffset
	adds r0, 0x6
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xA
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA33C
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringCenterAlignXOffset
	adds r0, 0x6
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xA
	adds r1, r4, 0
	movs r3, 0x11
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA343
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringCenterAlignXOffset
	adds r0, 0x6
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xA
	adds r1, r4, 0
	movs r3, 0x21
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA34B
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x24
	bl GetStringCenterAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xB
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA353
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x24
	bl GetStringCenterAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xB
	adds r1, r4, 0
	movs r3, 0x11
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA35B
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x24
	bl GetStringCenterAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xB
	adds r1, r4, 0
	movs r3, 0x21
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA39F
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xC
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3AB
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xC
	movs r2, 0x6
	movs r3, 0x11
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA398
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xD
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA37E
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA384
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0
	movs r3, 0x11
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA38D
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xF
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA394
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xF
	movs r2, 0
	movs r3, 0x11
	bl sub_81C25A4
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C286C

	thumb_func_start sub_81C2AFC
sub_81C2AFC: @ 81C2AFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r0, 0
	bl ClearWindowTilemap
	movs r0, 0x1
	bl ClearWindowTilemap
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x3
	bl ClearWindowTilemap
	cmp r4, 0x1
	beq _081C2B66
	cmp r4, 0x1
	bgt _081C2B2A
	cmp r4, 0
	beq _081C2B34
	b _081C2C06
_081C2B2A:
	cmp r5, 0x2
	beq _081C2B80
	cmp r5, 0x3
	beq _081C2BC4
	b _081C2C06
_081C2B34:
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x4
	bl PutWindowTilemap
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2B58
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C2B5E
_081C2B58:
	movs r0, 0x8
	bl PutWindowTilemap
_081C2B5E:
	movs r0, 0x9
	bl PutWindowTilemap
	b _081C2C06
_081C2B66:
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0xA
	bl PutWindowTilemap
	movs r0, 0xB
	bl PutWindowTilemap
	movs r0, 0xC
	bl PutWindowTilemap
	b _081C2C06
_081C2B80:
	movs r0, 0x2
	bl PutWindowTilemap
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2BBC
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2C06
	movs r0, 0xE
	bl PutWindowTilemap
	b _081C2C06
	.pool
_081C2BBC:
	movs r0, 0x5
	bl PutWindowTilemap
	b _081C2C06
_081C2BC4:
	movs r0, 0x3
	bl PutWindowTilemap
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2C00
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2C06
	movs r0, 0xF
	bl PutWindowTilemap
	b _081C2C06
	.pool
_081C2C00:
	movs r0, 0x5
	bl PutWindowTilemap
_081C2C06:
	movs r4, 0
	ldr r5, =gUnknown_0203CF1C
_081C2C0A:
	ldr r0, [r5]
	ldr r1, =0x000040cb
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C2C0A
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2AFC

	thumb_func_start sub_81C2C38
sub_81C2C38: @ 81C2C38
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _081C2C84
	cmp r0, 0x1
	bgt _081C2C4E
	cmp r0, 0
	beq _081C2C58
	b _081C2D0E
_081C2C4E:
	cmp r1, 0x2
	beq _081C2C98
	cmp r1, 0x3
	beq _081C2CD4
	b _081C2D0E
_081C2C58:
	movs r0, 0x4
	bl ClearWindowTilemap
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2C76
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C2C7C
_081C2C76:
	movs r0, 0x8
	bl ClearWindowTilemap
_081C2C7C:
	movs r0, 0x9
	bl ClearWindowTilemap
	b _081C2D0E
_081C2C84:
	movs r0, 0xA
	bl ClearWindowTilemap
	movs r0, 0xB
	bl ClearWindowTilemap
	movs r0, 0xC
	bl ClearWindowTilemap
	b _081C2D0E
_081C2C98:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2CCC
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2D0E
	movs r0, 0xE
	bl ClearWindowTilemap
	b _081C2D0E
	.pool
_081C2CCC:
	movs r0, 0x5
	bl ClearWindowTilemap
	b _081C2D0E
_081C2CD4:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2D08
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2D0E
	movs r0, 0xF
	bl ClearWindowTilemap
	b _081C2D0E
	.pool
_081C2D08:
	movs r0, 0x5
	bl ClearWindowTilemap
_081C2D0E:
	movs r4, 0
_081C2D10:
	adds r0, r4, 0
	bl sub_81C2D68
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C2D10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C2C38

	thumb_func_start sub_81C2D2C
sub_81C2D2C: @ 81C2D2C
	push {r4,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r2, r1, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r4, =0x000040cb
	adds r1, r2, r4
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C2D56
	lsls r0, r2, 3
	adds r0, r3, r0
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
_081C2D56:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C2D2C

	thumb_func_start sub_81C2D68
sub_81C2D68: @ 81C2D68
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF1C
	ldr r2, =0x000040cb
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C2D8C
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
_081C2D8C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2D68

	thumb_func_start sub_81C2D9C
sub_81C2D9C: @ 81C2D9C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_081C2DA4:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040cb
	adds r0, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C2DBA
	movs r1, 0
	bl FillWindowPixelBuffer
_081C2DBA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x7
	bls _081C2DA4
	ldr r0, =gUnknown_0861CE54
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2D9C

	thumb_func_start sub_81C2DE4
sub_81C2DE4: @ 81C2DE4
	push {lr}
	lsls r0, 24
	ldr r1, =gUnknown_0861CE64
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x10
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2DE4

	thumb_func_start sub_81C2E00
sub_81C2E00: @ 81C2E00
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x74
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C2E24
	bl sub_81C335C
	bl sub_81C33CC
	bl sub_81C3428
	bl sub_81C349C
	b _081C2E3C
	.pool
_081C2E24:
	bl sub_81C2EC4
	bl sub_81C2F5C
	bl sub_81C2FD8
	bl sub_81C302C
	bl sub_81C307C
	bl sub_81C3194
_081C2E3C:
	pop {r0}
	bx r0
	thumb_func_end sub_81C2E00

	thumb_func_start sub_81C2E40
sub_81C2E40: @ 81C2E40
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bhi _081C2EB8
	lsls r0, 2
	ldr r1, =_081C2E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C2E70:
	.4byte _081C2E8C
	.4byte _081C2E92
	.4byte _081C2E98
	.4byte _081C2E9E
	.4byte _081C2EA4
	.4byte _081C2EAA
	.4byte _081C2EB0
_081C2E8C:
	bl sub_81C2EC4
	b _081C2EB8
_081C2E92:
	bl sub_81C2F5C
	b _081C2EB8
_081C2E98:
	bl sub_81C2FD8
	b _081C2EB8
_081C2E9E:
	bl sub_81C302C
	b _081C2EB8
_081C2EA4:
	bl sub_81C307C
	b _081C2EB8
_081C2EAA:
	bl sub_81C3194
	b _081C2EB8
_081C2EB0:
	adds r0, r2, 0
	bl DestroyTask
	b _081C2EBE
_081C2EB8:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C2EBE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C2E40

	thumb_func_start sub_81C2EC4
sub_81C2EC4: @ 81C2EC4
	push {r4-r6,lr}
	sub sp, 0x8
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2F54
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2F54
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_085EA365
	movs r6, 0
	str r6, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	adds r2, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xA2
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C2F40
	adds r1, 0xA6
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r3, 0x1
	bl sub_81C25A4
	b _081C2F54
	.pool
_081C2F40:
	adds r1, 0xA6
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r3, 0x1
	bl sub_81C25A4
_081C2F54:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C2EC4

	thumb_func_start sub_81C2F5C
sub_81C2F5C: @ 81C2F5C
	push {r4,r5,lr}
	sub sp, 0x8
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2FC0
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2FC0
	ldr r5, =gStringVar1
	ldr r1, =gUnknown_085E8D59
	adds r0, r5, 0
	bl StringCopy
	ldr r1, =gUnknown_0203CF1C
	ldr r1, [r1]
	adds r1, 0xB8
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
_081C2FC0:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2F5C

	thumb_func_start sub_81C2FD8
sub_81C2FD8: @ 81C2FD8
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x70
	ldrh r0, [r0]
	adds r1, 0x78
	ldrb r1, [r1]
	bl sub_806B694
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xD
	muls r1, r4
	ldr r2, =gAbilityNames
	adds r1, r2
	movs r2, 0
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2FD8

	thumb_func_start sub_81C302C
sub_81C302C: @ 81C302C
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x70
	ldrh r0, [r0]
	adds r1, 0x78
	ldrb r1, [r1]
	bl sub_806B694
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gAbilityDescriptionPointers
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r3, 0x11
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C302C

	thumb_func_start sub_81C307C
sub_81C307C: @ 81C307C
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x70
	bl sub_81AFBF0
	ldr r1, =gUnknown_0861CE74
	movs r0, 0
	bl sub_81AFC0C
	ldr r1, =gUnknown_0861CE7B
	movs r0, 0x1
	bl sub_81AFC0C
	bl sub_81C31C0
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C30C2
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C30C2
	bl sub_81C3304
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C30E0
_081C30C2:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085EA5DB
	bl sub_81AFC28
	b _081C3182
	.pool
_081C30E0:
	movs r0, 0x20
	bl Alloc
	adds r6, r0, 0
	movs r0, 0x20
	bl Alloc
	adds r5, r0, 0
	adds r0, r6, 0
	bl sub_81C31F0
	ldrb r0, [r4, 0x9]
	cmp r0, 0xD4
	bhi _081C310C
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_8124610
	movs r0, 0x4
	adds r1, r5, 0
	bl sub_81AFC0C
_081C310C:
	bl sub_81C3220
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C3148
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _081C3134
	ldrb r0, [r4, 0x9]
	ldr r1, =gUnknown_085EA516
	cmp r0, 0xD4
	bls _081C3170
	ldr r1, =gUnknown_085EA617
	b _081C3170
	.pool
_081C3134:
	ldrb r0, [r4, 0x9]
	ldr r1, =gUnknown_085EA4EC
	cmp r0, 0xD4
	bls _081C3170
	ldr r1, =gUnknown_085EA5EB
	b _081C3170
	.pool
_081C3148:
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _081C3158
	ldr r1, =gUnknown_085EA56A
	b _081C3170
	.pool
_081C3158:
	cmp r0, 0xFE
	beq _081C316E
	bl sub_81C32BC
	lsls r0, 24
	cmp r0, 0
	beq _081C316E
	ldrb r0, [r4, 0x9]
	ldr r1, =gUnknown_085EA5A8
	cmp r0, 0xD4
	bls _081C3170
_081C316E:
	ldr r1, =gUnknown_085EA544
_081C3170:
	ldr r0, =gStringVar4
	bl sub_81AFC28
	adds r0, r6, 0
	bl Free
	adds r0, r5, 0
	bl Free
_081C3182:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C307C

	thumb_func_start sub_81C3194
sub_81C3194: @ 81C3194
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x3
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar4
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3194

	thumb_func_start sub_81C31C0
sub_81C31C0: @ 81C31C0
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =gNatureNamePointers
	adds r0, 0xA3
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x2
	bl sub_81AFC0C
	ldr r1, =gUnknown_085EA3C0
	movs r0, 0x5
	bl sub_81AFC0C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C31C0

	thumb_func_start sub_81C31F0
sub_81C31F0: @ 81C31F0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x7A
	ldrb r1, [r0]
	cmp r1, 0
	bne _081C3202
	movs r1, 0x5
_081C3202:
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x3
	adds r1, r4, 0
	bl sub_81AFC0C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C31F0

	thumb_func_start sub_81C3220
sub_81C3220: @ 81C3220
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r6, r0, 0
	adds r6, 0x70
	ldr r1, [r0]
	ldr r0, =gEnemyParty
	cmp r1, r0
	bne _081C326C
	bl link_get_multiplayer_id
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_020229E8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldrh r4, [r0]
	adds r0, r1, r2
	ldrb r5, [r0, 0x13]
	ldr r0, =gStringVar1
	adds r2, 0x8
	adds r1, r2
	bl StringCopy
	b _081C3282
	.pool
_081C326C:
	bl sub_80F0020
	adds r4, r0, 0
	ldr r0, =0x0000ffff
	ands r4, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r5, [r1, 0x8]
	ldr r0, =gStringVar1
	bl StringCopy
_081C3282:
	adds r0, r6, 0
	adds r0, 0x32
	ldrb r0, [r0]
	cmp r5, r0
	bne _081C32A4
	ldr r0, [r6, 0x48]
	ldr r1, =0x0000ffff
	ands r0, r1
	cmp r4, r0
	bne _081C32A4
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x36
	bl StringCompareWithoutExtCtrlCodes
	cmp r0, 0
	beq _081C32B4
_081C32A4:
	movs r0, 0
	b _081C32B6
	.pool
_081C32B4:
	movs r0, 0x1
_081C32B6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C3220

	thumb_func_start sub_81C32BC
sub_81C32BC: @ 81C32BC
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x70
	ldrb r0, [r0, 0xB]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _081C32D8
	movs r0, 0
	b _081C32DA
	.pool
_081C32D8:
	movs r0, 0x1
_081C32DA:
	pop {r1}
	bx r1
	thumb_func_end sub_81C32BC

	thumb_func_start sub_81C32E0
sub_81C32E0: @ 81C32E0
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x70
	ldrb r0, [r0, 0xB]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _081C32FC
	movs r0, 0
	b _081C32FE
	.pool
_081C32FC:
	movs r0, 0x1
_081C32FE:
	pop {r1}
	bx r1
	thumb_func_end sub_81C32E0

	thumb_func_start sub_81C3304
sub_81C3304: @ 81C3304
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _081C3354
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C3354
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C333A
	cmp r0, 0x4
	beq _081C333A
	cmp r0, 0x5
	bne _081C3354
_081C333A:
	movs r0, 0x1
	b _081C3356
	.pool
_081C3354:
	movs r0, 0
_081C3356:
	pop {r1}
	bx r1
	thumb_func_end sub_81C3304

	thumb_func_start sub_81C335C
sub_81C335C: @ 81C335C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_085EA365
	mov r8, r0
	movs r0, 0x1
	mov r1, r8
	movs r2, 0
	bl GetStringWidth
	adds r5, r0, 0
	movs r0, 0
	mov r9, r0
	str r0, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085E8D38
	lsls r5, 24
	lsrs r5, 24
	mov r0, r9
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C335C

	thumb_func_start sub_81C33CC
sub_81C33CC: @ 81C33CC
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, =gStringVar1
	ldr r1, =gUnknown_085E8D59
	adds r0, r5, 0
	bl StringCopy
	ldr r1, =gUnknown_085E8D38
	adds r0, r5, 0
	bl StringAppend
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C33CC

	thumb_func_start sub_81C3428
sub_81C3428: @ 81C3428
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x70
	adds r0, 0xA5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C3448
	ldr r4, =gUnknown_085EA40B
	b _081C346C
	.pool
_081C3448:
	ldrh r0, [r1, 0x30]
	cmp r0, 0x5
	bhi _081C3458
	ldr r4, =gUnknown_085EA4A2
	b _081C346C
	.pool
_081C3458:
	cmp r0, 0xA
	bhi _081C3464
	ldr r4, =gUnknown_085EA475
	b _081C346C
	.pool
_081C3464:
	ldr r4, =gUnknown_085EA40B
	cmp r0, 0x28
	bhi _081C346C
	ldr r4, =gUnknown_085EA442
_081C346C:
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3428

	thumb_func_start sub_81C349C
sub_81C349C: @ 81C349C
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x70
	adds r0, 0xA5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C3500
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _081C34C4
	ldr r4, =gUnknown_085EA678
	b _081C3502
	.pool
_081C34C4:
	bl sub_81C32BC
	lsls r0, 24
	cmp r0, 0
	beq _081C34D8
	bl sub_81C3220
	lsls r0, 24
	cmp r0, 0
	bne _081C34E0
_081C34D8:
	ldr r4, =gUnknown_085EA6AB
	b _081C3502
	.pool
_081C34E0:
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFD
	bne _081C3500
	bl sub_81C32E0
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_085EA702
	cmp r0, 0x1
	bne _081C3502
	ldr r4, =gUnknown_085EA6D7
	b _081C3502
	.pool
_081C3500:
	ldr r4, =gUnknown_085EA647
_081C3502:
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x3
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C349C

	thumb_func_start sub_81C3530
sub_81C3530: @ 81C3530
	push {lr}
	bl sub_81C35E4
	bl sub_81C3690
	bl sub_81C3710
	bl sub_81C37D8
	bl sub_81C3808
	bl sub_81C3890
	bl sub_81C38C0
	pop {r0}
	bx r0
	thumb_func_end sub_81C3530

	thumb_func_start sub_81C3554
sub_81C3554: @ 81C3554
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _081C35D6
	lsls r0, 2
	ldr r1, =_081C3584
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C3584:
	.4byte _081C35A4
	.4byte _081C35AA
	.4byte _081C35B0
	.4byte _081C35B6
	.4byte _081C35BC
	.4byte _081C35C2
	.4byte _081C35C8
	.4byte _081C35CE
_081C35A4:
	bl sub_81C35E4
	b _081C35D6
_081C35AA:
	bl sub_81C3690
	b _081C35D6
_081C35B0:
	bl sub_81C3710
	b _081C35D6
_081C35B6:
	bl sub_81C37D8
	b _081C35D6
_081C35BC:
	bl sub_81C3808
	b _081C35D6
_081C35C2:
	bl sub_81C3890
	b _081C35D6
_081C35C8:
	bl sub_81C38C0
	b _081C35D6
_081C35CE:
	adds r0, r2, 0
	bl DestroyTask
	b _081C35DC
_081C35D6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C35DC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3554

	thumb_func_start sub_81C35E4
sub_81C35E4: @ 81C35E4
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x9E
	ldrh r0, [r0]
	cmp r0, 0xAF
	bne _081C3628
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C3628
	ldr r0, [r4]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C3614
	cmp r0, 0x4
	beq _081C3614
	cmp r0, 0x5
	bne _081C3628
_081C3614:
	movs r0, 0xAF
	bl itemid_get_item
	adds r5, r0, 0
	b _081C3650
	.pool
_081C3628:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x9E
	ldrh r0, [r1]
	cmp r0, 0
	bne _081C3644
	ldr r5, =gUnknown_085E8D26
	b _081C3650
	.pool
_081C3644:
	ldrh r0, [r1]
	ldr r4, =gStringVar1
	adds r1, r4, 0
	bl itemid_get_name
	adds r5, r4, 0
_081C3650:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x48
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	adds r4, 0x6
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C35E4

	thumb_func_start sub_81C3690
sub_81C3690: @ 81C3690
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x76
	ldrb r0, [r1]
	cmp r0, 0
	bne _081C36B0
	ldr r5, =gUnknown_085E8D26
	b _081C36C8
	.pool
_081C36B0:
	ldr r0, =gStringVar1
	ldrb r1, [r1]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EA3B4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r5, r4, 0
_081C36C8:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x46
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	adds r4, 0x6
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3690

	thumb_func_start sub_81C3710
sub_81C3710: @ 81C3710
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	movs r0, 0x8
	bl Alloc
	mov r9, r0
	movs r0, 0x8
	bl Alloc
	mov r8, r0
	movs r0, 0x8
	bl Alloc
	adds r6, r0, 0
	movs r0, 0x8
	bl Alloc
	adds r5, r0, 0
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x90
	ldrh r1, [r0]
	mov r0, r9
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x92
	ldrh r1, [r0]
	mov r0, r8
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x94
	ldrh r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x96
	ldrh r1, [r0]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	mov r1, r9
	bl sub_81AFC0C
	movs r0, 0x1
	mov r1, r8
	bl sub_81AFC0C
	movs r0, 0x2
	adds r1, r6, 0
	bl sub_81AFC0C
	movs r0, 0x3
	adds r1, r5, 0
	bl sub_81AFC0C
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0861CE82
	bl sub_81AFC28
	mov r0, r9
	bl Free
	mov r0, r8
	bl Free
	adds r0, r6, 0
	bl Free
	adds r0, r5, 0
	bl Free
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3710

	thumb_func_start sub_81C37D8
sub_81C37D8: @ 81C37D8
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar4
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x4
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C37D8

	thumb_func_start sub_81C3808
sub_81C3808: @ 81C3808
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gStringVar1
	mov r8, r0
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x98
	ldrh r1, [r0]
	mov r0, r8
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar2
	ldr r0, [r4]
	adds r0, 0x9A
	ldrh r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r5, =gStringVar3
	ldr r0, [r4]
	adds r0, 0x9C
	ldrh r1, [r0]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	mov r1, r8
	bl sub_81AFC0C
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_81AFC0C
	movs r0, 0x2
	adds r1, r5, 0
	bl sub_81AFC0C
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0861CE8E
	bl sub_81AFC28
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3808

	thumb_func_start sub_81C3890
sub_81C3890: @ 81C3890
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x3
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar4
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3890

	thumb_func_start sub_81C38C0
sub_81C38C0: @ 81C38C0
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x4
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gStringVar1
	ldr r1, [r5, 0x10]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringRightAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldrb r0, [r5, 0x5]
	cmp r0, 0x63
	bhi _081C3948
	ldr r4, =gExperienceTables
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 2
	ldr r3, =gBaseStats
	ldrh r2, [r5]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r2, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r2
	adds r1, r0
	adds r1, r4
	ldr r1, [r1]
	ldr r0, [r5, 0x10]
	subs r1, r0
	b _081C394A
	.pool
_081C3948:
	movs r1, 0
_081C394A:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringRightAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r3, 0x11
	bl sub_81C25A4
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C38C0

	thumb_func_start sub_81C3984
sub_81C3984: @ 81C3984
	push {r4,lr}
	movs r0, 0
	bl sub_81C3B08
	movs r0, 0x1
	bl sub_81C3B08
	movs r0, 0x2
	bl sub_81C3B08
	movs r0, 0x3
	bl sub_81C3B08
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C39EA
	bl sub_81C3F44
	ldr r1, [r4]
	ldr r0, =0x000040c6
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _081C39DC
	ldr r0, =0x000040c4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C39EA
	bl sub_81C3E9C
	b _081C39EA
	.pool
_081C39DC:
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r0, [r1]
	bl sub_81C3E9C
_081C39EA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3984

	thumb_func_start sub_81C39F0
sub_81C39F0: @ 81C39F0
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _081C3AFC
	lsls r0, 2
	ldr r1, =_081C3A20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C3A20:
	.4byte _081C3A40
	.4byte _081C3A48
	.4byte _081C3A50
	.4byte _081C3A58
	.4byte _081C3A60
	.4byte _081C3A7C
	.4byte _081C3ABE
	.4byte _081C3AF4
_081C3A40:
	movs r0, 0
	bl sub_81C3B08
	b _081C3AFC
_081C3A48:
	movs r0, 0x1
	bl sub_81C3B08
	b _081C3AFC
_081C3A50:
	movs r0, 0x2
	bl sub_81C3B08
	b _081C3AFC
_081C3A58:
	movs r0, 0x3
	bl sub_81C3B08
	b _081C3AFC
_081C3A60:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3AFC
	bl sub_81C3F44
	b _081C3AFC
	.pool
_081C3A7C:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3AFC
	ldr r0, =0x000040c6
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _081C3AB0
	ldr r2, =0x000040c4
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4, 0x2]
	b _081C3AFC
	.pool
_081C3AB0:
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r4, 0x2]
	b _081C3AFC
_081C3ABE:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3AFC
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C3AFC
	ldrh r0, [r4, 0x2]
	bl sub_81C3E9C
	b _081C3AFC
	.pool
_081C3AF4:
	adds r0, r2, 0
	bl DestroyTask
	b _081C3B02
_081C3AFC:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C3B02:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C39F0

	thumb_func_start sub_81C3B08
sub_81C3B08: @ 81C3B08
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	mov r10, r0
	ldr r4, =gUnknown_0861CD14
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	lsls r1, r7, 1
	mov r0, r10
	adds r0, 0x84
	adds r0, r1
	ldrh r5, [r0]
	cmp r5, 0
	beq _081C3C00
	mov r0, r10
	adds r0, 0xA4
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r2, r7, 0
	bl CalcPPWithPPUps
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	lsls r0, r7, 4
	mov r9, r0
	mov r3, r9
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r8
	movs r2, 0
	bl sub_81C25A4
	ldr r0, =gStringVar1
	mov r8, r0
	mov r5, r10
	adds r5, 0x8C
	adds r5, r7
	ldrb r1, [r5]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	mov r1, r8
	bl sub_81AFC0C
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_81AFC0C
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0861CE97
	adds r0, r4, 0
	bl sub_81AFC28
	adds r7, r4, 0
	ldrb r0, [r5]
	adds r1, r6, 0
	bl sub_814FC20
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	adds r5, 0x9
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x2C
	bl GetStringRightAlignXOffset
	mov r4, r9
	b _081C3C26
	.pool
_081C3C00:
	ldr r1, =gUnknown_085E8D40
	lsls r4, r7, 4
	adds r3, r4, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r8
	movs r2, 0
	bl sub_81C25A4
	ldr r7, =gUnknown_085E8D42
	movs r5, 0xC
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x2C
	bl GetStringCenterAlignXOffset
_081C3C26:
	lsls r2, r0, 24
	lsrs r2, 24
	adds r3, r4, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	lsls r0, r5, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x8]
	adds r1, r7, 0
	bl sub_81C25A4
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3B08

	thumb_func_start sub_81C3C5C
sub_81C3C5C: @ 81C3C5C
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C3CFC
	movs r0, 0x13
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x35
	movs r3, 0
	bl FillWindowPixelRect
	ldr r2, =gBattleMoves
	lsls r1, r5, 1
	adds r0, r1, r5
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x1]
	adds r6, r1, 0
	cmp r0, 0x1
	bhi _081C3C9C
	ldr r1, =gUnknown_085E8D45
	b _081C3CAC
	.pool
_081C3C9C:
	ldr r4, =gStringVar1
	ldrb r1, [r2, 0x1]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r1, r4, 0
_081C3CAC:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0x35
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gBattleMoves
	adds r0, r6, r5
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	bne _081C3CDC
	ldr r1, =gUnknown_085E8D45
	b _081C3CEC
	.pool
_081C3CDC:
	ldr r4, =gStringVar1
	ldrb r1, [r1, 0x3]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r1, r4, 0
_081C3CEC:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0x35
	movs r3, 0x11
	bl sub_81C25A4
_081C3CFC:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3C5C

	thumb_func_start sub_81C3D08
sub_81C3D08: @ 81C3D08
	push {r4,lr}
	movs r0, 0
	bl sub_81C3B08
	movs r0, 0x1
	bl sub_81C3B08
	movs r0, 0x2
	bl sub_81C3B08
	movs r0, 0x3
	bl sub_81C3B08
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3D40
	bl sub_81C3F44
	ldr r0, [r4]
	ldr r1, =0x000040c6
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C3E2C
_081C3D40:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3D08

	thumb_func_start sub_81C3D54
sub_81C3D54: @ 81C3D54
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bhi _081C3E20
	lsls r0, 2
	ldr r1, =_081C3D84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C3D84:
	.4byte _081C3DA0
	.4byte _081C3DA8
	.4byte _081C3DB0
	.4byte _081C3DB8
	.4byte _081C3DC0
	.4byte _081C3DDC
	.4byte _081C3E18
_081C3DA0:
	movs r0, 0
	bl sub_81C3B08
	b _081C3E20
_081C3DA8:
	movs r0, 0x1
	bl sub_81C3B08
	b _081C3E20
_081C3DB0:
	movs r0, 0x2
	bl sub_81C3B08
	b _081C3E20
_081C3DB8:
	movs r0, 0x3
	bl sub_81C3B08
	b _081C3E20
_081C3DC0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3E20
	bl sub_81C3F44
	b _081C3E20
	.pool
_081C3DDC:
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r1, =0x000040bc
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3E20
	adds r1, 0x8
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C3E20
	ldr r1, =0x000040c6
	adds r0, r2, r1
	ldrb r0, [r0]
	bl sub_81C3E2C
	b _081C3E20
	.pool
_081C3E18:
	adds r0, r2, 0
	bl DestroyTask
	b _081C3E26
_081C3E20:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C3E26:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3D54

	thumb_func_start sub_81C3E2C
sub_81C3E2C: @ 81C3E2C
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bne _081C3E48
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	b _081C3E50
	.pool
_081C3E48:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	lsls r1, 1
	adds r0, 0x84
_081C3E50:
	adds r0, r1
	ldrh r4, [r0]
	cmp r4, 0
	beq _081C3E82
	ldr r0, =gUnknown_0861CD14
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gContestEffectDescriptionPointers
	ldr r2, =gContestMoves
	lsls r1, r4, 3
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
_081C3E82:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3E2C

	thumb_func_start sub_81C3E9C
sub_81C3E9C: @ 81C3E9C
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	ldr r0, =gUnknown_0861CD14
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0
	beq _081C3F30
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C3F00
	adds r0, r4, 0
	bl sub_81C3C5C
	ldr r1, =gMoveDescriptionPointers
	subs r0, r4, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
	b _081C3F20
	.pool
_081C3F00:
	ldr r2, =gContestEffectDescriptionPointers
	ldr r1, =gContestMoves
	lsls r0, r6, 3
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
_081C3F20:
	adds r0, r5, 0
	bl PutWindowTilemap
	b _081C3F36
	.pool
_081C3F30:
	adds r0, r5, 0
	bl ClearWindowTilemap
_081C3F36:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3E9C

	thumb_func_start sub_81C3F44
sub_81C3F44: @ 81C3F44
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, =gUnknown_0861CD14
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r6, r0, 24
	adds r7, r6, 0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c4
	adds r0, r1, r2
	ldrh r2, [r0]
	cmp r2, 0
	bne _081C3F9C
	ldr r1, =gUnknown_085E8CF0
	str r2, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x41
	bl sub_81C25A4
	b _081C4044
	.pool
_081C3F9C:
	ldrh r5, [r0]
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C3FD0
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x41
	bl sub_81C25A4
	b _081C3FEC
	.pool
_081C3FD0:
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0
	movs r3, 0x41
	bl sub_81C25A4
_081C3FEC:
	ldr r4, =gStringVar1
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x4]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	adds r1, r4, 0
	bl sub_81AFC0C
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_81AFC0C
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0861CE97
	adds r0, r4, 0
	bl sub_81AFC28
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2C
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	str r0, [sp, 0x4]
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0x41
	bl sub_81C25A4
_081C4044:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3F44

	thumb_func_start sub_81C4064
sub_81C4064: @ 81C4064
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CD14
	movs r1, 0
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x48
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x42
	bl FillWindowPixelRect
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4064

	thumb_func_start sub_81C40A0
sub_81C40A0: @ 81C40A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r5, =gUnknown_0861CD14
	adds r0, r5, 0
	movs r1, 0
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C2D2C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r0, r9
	lsls r6, r0, 4
	movs r0, 0x48
	mov r8, r0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	adds r3, r6, 0
	bl FillWindowPixelRect
	mov r0, r10
	lsls r7, r0, 4
	mov r0, r8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	adds r3, r7, 0
	bl FillWindowPixelRect
	movs r4, 0x30
	str r4, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	adds r3, r6, 0
	bl FillWindowPixelRect
	str r4, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	adds r3, r7, 0
	bl FillWindowPixelRect
	mov r0, r9
	bl sub_81C3B08
	mov r0, r10
	bl sub_81C3B08
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C40A0

	thumb_func_start sub_81C4154
sub_81C4154: @ 81C4154
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CD14
	movs r1, 0x2
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085EA4CB
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4154

	thumb_func_start sub_81C4190
sub_81C4190: @ 81C4190
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gUnknown_0203CF1C
	ldr r4, =0x000040d3
	movs r3, 0xFF
_081C419A:
	ldr r0, [r5]
	adds r0, r4
	adds r0, r2
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1B
	bls _081C419A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4190

	thumb_func_start sub_81C41C0
sub_81C41C0: @ 81C41C0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C41F2
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r0, [r5]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081C41F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C41C0

	thumb_func_start sub_81C4204
sub_81C4204: @ 81C4204
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203CF1C
	ldr r2, [r2]
	ldr r4, =0x000040d3
	adds r2, r4
	adds r2, r0
	ldrb r0, [r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	adds r2, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4204

	thumb_func_start sub_81C424C
sub_81C424C: @ 81C424C
	push {r4,lr}
	movs r4, 0x3
_081C4250:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _081C4268
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C4204
_081C4268:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1B
	bls _081C4250
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C424C

	thumb_func_start sub_81C4280
sub_81C4280: @ 81C4280
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C42B0
	cmp r0, 0x2
	bgt _081C42A4
	cmp r0, 0
	beq _081C42AA
	b _081C42C2
	.pool
_081C42A4:
	cmp r0, 0x3
	beq _081C42BA
	b _081C42C2
_081C42AA:
	bl sub_81C43A0
	b _081C42C2
_081C42B0:
	bl sub_81C4420
	bl sub_81C44F0
	b _081C42C2
_081C42BA:
	bl sub_81C4484
	bl sub_81C44F0
_081C42C2:
	pop {r0}
	bx r0
	thumb_func_end sub_81C4280

	thumb_func_start sub_81C42C8
sub_81C42C8: @ 81C42C8
	push {r4,r5,lr}
	movs r4, 0x3
	ldr r5, =gUnknown_0203CF1C
_081C42CE:
	ldr r0, [r5]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C42F2
	ldr r0, =gUnknown_0861CFC4
	movs r1, 0
	movs r2, 0
	movs r3, 0x2
	bl CreateSprite
	ldr r1, [r5]
	ldr r2, =0x000040d3
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
_081C42F2:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C4204
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C42CE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C42C8

	thumb_func_start sub_81C4318
sub_81C4318: @ 81C4318
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	str r3, [sp]
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0861CFDC
	adds r5, r0
	ldrb r1, [r5]
	lsls r1, 4
	ldrb r2, [r4, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r6, 0x10
	strh r6, [r4, 0x20]
	movs r0, 0x8
	add r8, r0
	mov r1, r8
	strh r1, [r4, 0x22]
	ldr r3, [sp]
	adds r0, r3, 0
	movs r1, 0
	bl sub_81C4204
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4318

	thumb_func_start sub_81C43A0
sub_81C43A0: @ 81C43A0
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	beq _081C43CC
	movs r0, 0x9
	movs r1, 0x78
	movs r2, 0x30
	movs r3, 0x3
	bl sub_81C4318
	movs r0, 0x4
	movs r1, 0x1
	bl sub_81C4204
	b _081C4418
	.pool
_081C43CC:
	ldr r4, =gBaseStats
	ldrh r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x6]
	movs r1, 0x78
	movs r2, 0x30
	movs r3, 0x3
	bl sub_81C4318
	ldrh r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrb r0, [r1, 0x6]
	ldrb r2, [r1, 0x7]
	cmp r0, r2
	beq _081C4410
	ldrb r0, [r1, 0x7]
	movs r1, 0xA0
	movs r2, 0x30
	movs r3, 0x4
	bl sub_81C4318
	movs r0, 0x4
	movs r1, 0
	bl sub_81C4204
	b _081C4418
	.pool
_081C4410:
	movs r0, 0x4
	movs r1, 0x1
	bl sub_81C4204
_081C4418:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C43A0

	thumb_func_start sub_81C4420
sub_81C4420: @ 81C4420
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	movs r4, 0
	ldr r6, =gBattleMoves
_081C442E:
	lsls r0, r4, 1
	adds r1, r5, 0
	adds r1, 0x14
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C4468
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	lsls r2, r4, 28
	movs r1, 0x80
	lsls r1, 22
	adds r2, r1
	lsrs r2, 24
	adds r3, r4, 0x3
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x55
	bl sub_81C4318
	b _081C4474
	.pool
_081C4468:
	adds r0, r4, 0x3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81C4204
_081C4474:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081C442E
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4420

	thumb_func_start sub_81C4484
sub_81C4484: @ 81C4484
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	movs r4, 0
_081C4490:
	lsls r0, r4, 1
	adds r1, r5, 0
	adds r1, 0x14
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, 0
	beq _081C44D4
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 5
	movs r1, 0x90
	lsls r1, 21
	adds r0, r1
	lsrs r0, 24
	lsls r2, r4, 28
	movs r1, 0x80
	lsls r1, 22
	adds r2, r1
	lsrs r2, 24
	adds r3, r4, 0x3
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x55
	bl sub_81C4318
	b _081C44E0
	.pool
_081C44D4:
	adds r0, r4, 0x3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81C4204
_081C44E0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081C4490
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4484

	thumb_func_start sub_81C44F0
sub_81C44F0: @ 81C44F0
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r0, =0x000040c4
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, 0
	bne _081C4514
	movs r0, 0x7
	movs r1, 0x1
	bl sub_81C4204
	b _081C4560
	.pool
_081C4514:
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C4540
	ldr r2, =gBattleMoves
	ldrh r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	movs r1, 0x55
	movs r2, 0x60
	movs r3, 0x7
	bl sub_81C4318
	b _081C4560
	.pool
_081C4540:
	ldr r1, =gContestMoves
	ldrh r0, [r3]
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 5
	movs r1, 0x90
	lsls r1, 21
	adds r0, r1
	lsrs r0, 24
	movs r1, 0x55
	movs r2, 0x60
	movs r3, 0x7
	bl sub_81C4318
_081C4560:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C44F0

	thumb_func_start sub_81C4568
sub_81C4568: @ 81C4568
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0203CF1C
	ldr r2, [r2]
	adds r0, 0x3
	ldr r3, =0x000040d3
	adds r2, r3
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r5, =gSprites
	adds r4, r5
	adds r1, 0x3
	adds r2, r1
	ldrb r0, [r2]
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r5
	adds r5, r4, 0
	adds r5, 0x2A
	ldrb r1, [r5]
	adds r2, r3, 0
	adds r2, 0x2A
	ldrb r0, [r2]
	strb r0, [r5]
	strb r1, [r2]
	ldrb r6, [r4, 0x5]
	lsrs r5, r6, 4
	ldrb r2, [r3, 0x5]
	lsrs r2, 4
	lsls r2, 4
	movs r1, 0xF
	adds r0, r1, 0
	ands r0, r6
	orrs r0, r2
	strb r0, [r4, 0x5]
	lsls r5, 4
	ldrb r0, [r3, 0x5]
	ands r1, r0
	orrs r1, r5
	strb r1, [r3, 0x5]
	adds r4, 0x3F
	ldrb r0, [r4]
	movs r2, 0x4
	orrs r0, r2
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r4]
	adds r3, 0x3F
	ldrb r0, [r3]
	orrs r0, r2
	ands r0, r1
	strb r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4568

	thumb_func_start sub_81C45F4
sub_81C45F4: @ 81C45F4
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r6, r1, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	adds r5, r2, 0
	adds r5, 0x70
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _081C4620
	cmp r0, 0x1
	bne _081C4610
	b _081C4750
_081C4610:
	adds r0, r3, 0
	bl sub_81C47B4
	lsls r0, 24
	lsrs r0, 24
	b _081C4770
	.pool
_081C4620:
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C4680
	ldr r1, =0x000040be
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x3
	bl sub_80688F8
	lsls r0, 24
	cmp r0, 0
	beq _081C4668
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	b _081C46D6
	.pool
_081C4668:
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	b _081C46B0
	.pool
_081C4680:
	ldr r0, =gUnknown_020244D4
	ldr r3, [r0]
	adds r4, r0, 0
	cmp r3, 0
	beq _081C46E4
	ldr r1, [r2]
	ldr r0, =gPlayerParty
	cmp r1, r0
	beq _081C46A6
	ldr r1, =0x000040bc
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C46A6
	adds r1, 0x33
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C46CC
_081C46A6:
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, [r4]
_081C46B0:
	ldr r1, [r1, 0x8]
	ldr r3, [r5, 0xC]
	bl DecompressMonPic_DetectFrontOrBack_2
	b _081C4768
	.pool
_081C46CC:
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, [r3, 0x8]
_081C46D6:
	ldr r3, [r5, 0xC]
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	b _081C4768
	.pool
_081C46E4:
	ldr r1, [r2]
	ldr r0, =gPlayerParty
	cmp r1, r0
	beq _081C4700
	ldr r1, =0x000040bc
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C4700
	adds r1, 0x33
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C472C
_081C4700:
	ldrh r4, [r5, 0x2]
	lsls r4, 3
	ldr r0, =gMonFrontPicTable
	adds r4, r0
	movs r0, 0
	movs r1, 0x1
	bl sub_806F4F8
	adds r1, r0, 0
	ldrh r2, [r5, 0x2]
	ldr r3, [r5, 0xC]
	adds r0, r4, 0
	bl DecompressMonPic_DetectFrontOrBack_2
	b _081C4768
	.pool
_081C472C:
	ldrh r4, [r5, 0x2]
	lsls r4, 3
	ldr r0, =gMonFrontPicTable
	adds r4, r0
	movs r0, 0
	movs r1, 0x1
	bl sub_806F4F8
	adds r1, r0, 0
	ldrh r2, [r5, 0x2]
	ldr r3, [r5, 0xC]
	adds r0, r4, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	b _081C4768
	.pool
_081C4750:
	ldrh r0, [r5, 0x2]
	ldr r1, [r5, 0x48]
	ldr r2, [r5, 0xC]
	bl sub_806E7CC
	adds r4, r0, 0
	bl LoadCompressedObjectPalette
	ldrh r0, [r4, 0x4]
	movs r1, 0x1
	bl sub_806A068
_081C4768:
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r0, 0xFF
_081C4770:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C45F4

	thumb_func_start sub_81C4778
sub_81C4778: @ 81C4778
	push {r4,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r4, r1, 0
	adds r4, 0x70
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _081C47AE
	adds r0, r1, 0
	adds r0, 0xC
	bl sub_805F110
	cmp r0, 0x1
	bne _081C47A4
	ldrh r0, [r4, 0x2]
	movs r1, 0
	movs r2, 0
	bl sub_80A32E4
	b _081C47AE
	.pool
_081C47A4:
	ldrh r0, [r4, 0x2]
	movs r1, 0
	movs r2, 0xB
	bl sub_80A32E4
_081C47AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4778

	thumb_func_start sub_81C47B4
sub_81C47B4: @ 81C47B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_0203CF1C
	ldr r6, [r0]
	adds r6, 0x70
	ldr r0, =gUnknown_0202499C
	movs r1, 0x28
	movs r2, 0x40
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, r0, 4
	add r4, r8
	lsls r4, 2
	ldr r5, =gSprites
	adds r7, r4, r5
	adds r0, r7, 0
	bl obj_free_rotscale_entry
	ldrh r0, [r6, 0x2]
	movs r1, 0
	strh r0, [r7, 0x2E]
	strh r1, [r7, 0x32]
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_81C4844
	str r0, [r4]
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r7, 0x5]
	ldrh r0, [r6, 0x2]
	bl sub_806E840
	lsls r0, 24
	cmp r0, 0
	bne _081C4828
	adds r0, r7, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _081C4836
	.pool
_081C4828:
	adds r2, r7, 0
	adds r2, 0x3F
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081C4836:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C47B4

	thumb_func_start sub_81C4844
sub_81C4844: @ 81C4844
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C487E
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _081C487E
	ldrh r0, [r4, 0x2E]
	bl sub_806E840
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x30]
	bl sub_81C4778
	ldrh r1, [r4, 0x2E]
	ldrb r2, [r5, 0x4]
	adds r0, r4, 0
	bl sub_806EE0C
_081C487E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4844

	thumb_func_start sub_81C488C
sub_81C488C: @ 81C488C
	ldr r1, =gUnknown_0203CF24
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C488C

	thumb_func_start sub_81C4898
sub_81C4898: @ 81C4898
	push {r4,lr}
	ldr r4, =gUnknown_0203CF24
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C48AA
	bl DestroyTask
	movs r0, 0xFF
	strb r0, [r4]
_081C48AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4898

	thumb_func_start sub_81C48B4
sub_81C48B4: @ 81C48B4
	push {lr}
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
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
	beq _081C48E8
	movs r0, 0x1
	b _081C48EA
	.pool
_081C48E8:
	movs r0, 0
_081C48EA:
	pop {r1}
	bx r1
	thumb_func_end sub_81C48B4

	thumb_func_start sub_81C48F0
sub_81C48F0: @ 81C48F0
	push {r4-r6,lr}
	ldr r6, =gSprites
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r4, =0x000040d3
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	bl sub_806EE98
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	lsls r3, r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	orrs r3, r0
	movs r2, 0
	ldr r5, =gPlttBufferUnfaded
	ldr r4, =gPlttBufferFaded
_081C494C:
	adds r0, r2, r3
	lsls r0, 16
	lsrs r0, 15
	adds r1, r0, r5
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _081C494C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C48F0

	thumb_func_start sub_81C4984
sub_81C4984: @ 81C4984
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r1, =0x00007533
	ldr r2, =gUnknown_0861D120
	adds r0, r1, 0
	bl sub_811FF94
	adds r4, r0, 0
	ldr r6, =gUnknown_0203CF1C
	ldr r0, [r6]
	str r4, [r0, 0x8]
	cmp r4, 0
	beq _081C49CE
	adds r0, r5, 0
	movs r1, 0x8
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	ldr r1, [r6]
	ldr r2, [r1, 0x8]
	movs r0, 0x3C
	strh r0, [r2, 0x20]
	ldr r2, [r1, 0x8]
	movs r0, 0x1A
	strh r0, [r2, 0x22]
	ldr r2, [r1, 0x8]
	ldrb r1, [r2, 0x5]
	subs r0, 0x27
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
_081C49CE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4984

	thumb_func_start sub_81C49E0
sub_81C49E0: @ 81C49E0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl DestroySprite
	ldr r0, =0x00007533
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl sub_81C4984
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C49E0

	thumb_func_start sub_81C4A08
sub_81C4A08: @ 81C4A08
	push {r4,lr}
	movs r1, 0x26
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl ball_number_to_ball_processing_index
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8076A78
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r1, =gUnknown_0832C588
	adds r0, r1
	movs r1, 0x10
	movs r2, 0x88
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_0203CF1C
	ldr r1, [r2]
	ldr r3, =0x000040d4
	adds r1, r3
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r2, [r2]
	adds r2, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4A08

	thumb_func_start sub_81C4A88
sub_81C4A88: @ 81C4A88
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C4AA6
	ldr r0, =gUnknown_0861D108
	movs r1, 0x40
	movs r2, 0x98
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
_081C4AA6:
	ldr r0, [r5]
	adds r0, 0xC
	bl sub_81B205C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _081C4AE8
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	subs r1, r2, 0x1
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	movs r0, 0x2
	movs r1, 0
	bl sub_81C4204
	b _081C4AF0
	.pool
_081C4AE8:
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81C4204
_081C4AF0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4A88

	thumb_func_start sub_81C4AF8
sub_81C4AF8: @ 81C4AF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, =0x000040d3
	add r1, r8
	ldr r0, [r0]
	adds r7, r0, r1
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _081C4BD2
	movs r0, 0
	mov r9, r0
	mov r1, r8
	cmp r1, 0x8
	bne _081C4B2A
	movs r0, 0x1
	mov r9, r0
_081C4B2A:
	movs r5, 0
	ldr r6, =gSprites
	mov r10, r5
_081C4B30:
	lsls r1, r5, 20
	movs r0, 0xB2
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	ldr r0, =gUnknown_0861D084
	movs r2, 0x28
	mov r3, r9
	bl CreateSprite
	adds r1, r7, r5
	strb r0, [r1]
	adds r4, r1, 0
	cmp r5, 0
	bne _081C4B74
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x4
	bl StartObjectImageAnim
	b _081C4B9A
	.pool
_081C4B74:
	cmp r5, 0x9
	bne _081C4B8A
	ldrb r1, [r7, 0x9]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	bl StartObjectImageAnim
	b _081C4B9A
_081C4B8A:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x6
	bl StartObjectImageAnim
_081C4B9A:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81C4BE4
	str r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r8
	strh r1, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r10
	strh r1, [r0, 0x30]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _081C4B30
_081C4BD2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4AF8

	thumb_func_start sub_81C4BE4
sub_81C4BE4: @ 81C4BE4
	push {lr}
	adds r3, r0, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	subs r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081C4C1C
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r3, 0x30]
	cmp r0, 0x18
	ble _081C4C10
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _081C4C2A
_081C4C10:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	b _081C4C28
_081C4C1C:
	movs r0, 0
	strh r0, [r3, 0x30]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
_081C4C28:
	ands r0, r1
_081C4C2A:
	strb r0, [r2]
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0x8
	bne _081C4C44
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c6
	b _081C4C4A
	.pool
_081C4C44:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c7
_081C4C4A:
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 4
	strh r0, [r3, 0x26]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4BE4

	thumb_func_start sub_81C4C60
sub_81C4C60: @ 81C4C60
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_081C4C68:
	adds r0, r5, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_81C41C0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C4C68
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4C60

	thumb_func_start sub_81C4C84
sub_81C4C84: @ 81C4C84
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040db
	adds r5, r0, r1
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 24
	movs r4, 0
	ldr r7, =gSprites
	movs r2, 0x80
	lsls r2, 19
	adds r2, r0
	mov r9, r2
	lsrs r6, r0, 24
	movs r1, 0xA0
	lsls r1, 19
	adds r1, r0
	mov r8, r1
_081C4CB4:
	cmp r4, 0
	bne _081C4CD4
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r9
	b _081C4CE4
	.pool
_081C4CD4:
	cmp r4, 0x9
	bne _081C4CEC
	ldrb r1, [r5, 0x9]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r8
_081C4CE4:
	lsrs r1, r2, 24
	bl StartObjectImageAnim
	b _081C4D02
_081C4CEC:
	adds r0, r5, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r1, r6, 0x6
	lsls r1, 24
	lsrs r1, 24
	bl StartObjectImageAnim
_081C4D02:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C4CB4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4C84

	thumb_func_start sub_81C4D18
sub_81C4D18: @ 81C4D18
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF1C
	ldr r2, =0x000040d3
	adds r0, r2
	ldr r1, [r1]
	adds r5, r1, r0
	movs r3, 0
	ldr r4, =gSprites
	movs r7, 0x5
	negs r7, r7
	movs r6, 0
_081C4D32:
	adds r2, r5, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r6, [r0, 0x30]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x9
	bls _081C4D32
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4D18

	thumb_func_start sub_81C4D70
sub_81C4D70: @ 81C4D70
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r4, =gUnknown_0203CF28
	movs r0, 0x4
	bl Alloc
	str r0, [r4]
	ldr r1, [r5]
	lsls r0, r1, 20
	lsrs r4, r0, 30
	cmp r4, 0
	bne _081C4DDC
	lsls r0, r1, 30
	lsrs r0, 30
	movs r1, 0x8
	movs r2, 0
	bl SetBgAttribute
	ldr r3, [r5]
	lsls r0, r3, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861D1A0
	lsls r3, 22
	lsrs r3, 24
	str r4, [sp]
	movs r2, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861DEF4
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, [r5]
	lsls r1, 22
	lsrs r1, 24
	str r4, [sp]
	movs r2, 0x20
	movs r3, 0x20
	bl sub_8199D3C
	b _081C4E2E
	.pool
_081C4DDC:
	lsls r0, r1, 30
	lsrs r0, 30
	movs r1, 0x8
	movs r2, 0x2
	bl SetBgAttribute
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x9
	movs r2, 0x1
	bl SetBgAttribute
	ldr r3, [r5]
	lsls r0, r3, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861E208
	lsls r3, 22
	lsrs r3, 24
	movs r2, 0
	str r2, [sp]
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861EF64
	movs r4, 0x1
	str r4, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, [r5]
	lsls r1, 22
	lsrs r1, 24
	str r4, [sp]
	movs r2, 0x40
	movs r3, 0x40
	bl sub_8199D3C
_081C4E2E:
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x4
	movs r2, 0x1
	bl SetBgAttribute
	ldr r0, =gUnknown_0861D140
	ldr r1, =gPlttBufferUnfaded + 0xE0
	ldr r2, =0x04000018
	bl CpuSet
	ldr r0, =gUnknown_0203CF28
	ldr r1, [r0]
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4D70

	thumb_func_start sub_81C4E90
sub_81C4E90: @ 81C4E90
	push {lr}
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081C4EA0
	movs r0, 0x1
	b _081C4EAC
_081C4EA0:
	ldr r0, =gUnknown_0203CF28
	ldr r0, [r0]
	ldrb r0, [r0]
	bl ShowBg
	movs r0, 0
_081C4EAC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C4E90

	thumb_func_start sub_81C4EB4
sub_81C4EB4: @ 81C4EB4
	push {r4,lr}
	ldr r4, =gUnknown_0203CF28
	ldr r0, [r4]
	cmp r0, 0
	beq _081C4EC6
	bl Free
	movs r0, 0
	str r0, [r4]
_081C4EC6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4EB4

	thumb_func_start sub_81C4ED0
sub_81C4ED0: @ 81C4ED0
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_0203CF28
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r1, 8
	movs r2, 0
	bl ChangeBgY
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4ED0

	thumb_func_start sub_81C4EEC
sub_81C4EEC: @ 81C4EEC
	ldr r1, =gUnknown_0203CF30
	movs r0, 0
	strh r0, [r1, 0x6]
	strh r0, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end sub_81C4EEC

	thumb_func_start sub_81C4EFC
sub_81C4EFC: @ 81C4EFC
	push {lr}
	ldr r1, =sub_8086194
	movs r0, 0
	bl sub_81C4F98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4EFC

	thumb_func_start sub_81C4F10
sub_81C4F10: @ 81C4F10
	push {lr}
	ldr r1, =sub_8059D50
	movs r0, 0x1
	bl sub_81C4F98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F10

	thumb_func_start sub_81C4F24
sub_81C4F24: @ 81C4F24
	push {lr}
	bl script_env_2_enable
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r0, =sub_81C4F44
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F24

	thumb_func_start sub_81C4F44
sub_81C4F44: @ 81C4F44
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C4F6E
	bl overworld_free_bg_tilemaps
	ldr r0, =gUnknown_03005DB0
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r0]
	ldr r1, =c2_exit_to_overworld_2_switch
	movs r0, 0x3
	bl sub_81C4F98
	adds r0, r4, 0
	bl DestroyTask
_081C4F6E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F44

	thumb_func_start sub_81C4F84
sub_81C4F84: @ 81C4F84
	push {lr}
	ldr r0, =gUnknown_0203CF30
	ldr r1, [r0]
	movs r0, 0x4
	bl sub_81C4F98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F84

	thumb_func_start sub_81C4F98
sub_81C4F98: @ 81C4F98
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_0203CF2C
	ldr r0, =0x0000098c
	bl AllocZeroed
	str r0, [r6]
	cmp r4, 0x4
	beq _081C4FB2
	ldr r0, =gUnknown_0203CF30
	strb r4, [r0, 0x4]
_081C4FB2:
	cmp r5, 0
	beq _081C4FBA
	ldr r0, =gUnknown_0203CF30
	str r5, [r0]
_081C4FBA:
	ldr r0, [r6]
	movs r1, 0
	str r1, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x00000816
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x00000804
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0xB
	bl memset
	ldr r0, [r6]
	ldr r1, =0x0000080f
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0x5
	bl memset
	ldr r0, =sub_81C504C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F98

	thumb_func_start sub_81C501C
sub_81C501C: @ 81C501C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81C501C

	thumb_func_start sub_81C5038
sub_81C5038: @ 81C5038
	push {lr}
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81C5038

	thumb_func_start sub_81C504C
sub_81C504C: @ 81C504C
	push {lr}
_081C504E:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5072
	bl sub_81C5078
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5072
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C504E
_081C5072:
	pop {r0}
	bx r0
	thumb_func_end sub_81C504C

	thumb_func_start sub_81C5078
sub_81C5078: @ 81C5078
	push {lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x10
	bls _081C508C
	b _081C51BC
_081C508C:
	lsls r0, 2
	ldr r1, =_081C50A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C50A0:
	.4byte _081C50E4
	.4byte _081C50EE
	.4byte _081C50F4
	.4byte _081C50FA
	.4byte _081C510C
	.4byte _081C5112
	.4byte _081C5122
	.4byte _081C513C
	.4byte _081C5148
	.4byte _081C514E
	.4byte _081C515C
	.4byte _081C5162
	.4byte _081C5168
	.4byte _081C516E
	.4byte _081C5174
	.4byte _081C517A
	.4byte _081C5188
_081C50E4:
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	b _081C51A2
_081C50EE:
	bl remove_some_task
	b _081C51A2
_081C50F4:
	bl ResetObjectPaletteAllocator
	b _081C51A2
_081C50FA:
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	b _081C51A0
	.pool
_081C510C:
	bl ResetAllObjectData
	b _081C51A2
_081C5112:
	bl sub_81221AC
	lsls r0, 24
	cmp r0, 0
	bne _081C51A2
	bl ResetTasks
	b _081C51A2
_081C5122:
	bl sub_81C51DC
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081C51A2
	.pool
_081C513C:
	bl sub_81C5238
	lsls r0, 24
	cmp r0, 0
	beq _081C51D4
	b _081C51A2
_081C5148:
	bl sub_81C6BD8
	b _081C51A2
_081C514E:
	bl sub_81C5924
	bl sub_81C59BC
	bl sub_81C5A20
	b _081C51A2
_081C515C:
	bl sub_81C5314
	b _081C51A2
_081C5162:
	bl sub_81C56F8
	b _081C51A2
_081C5168:
	bl sub_81C6EF4
	b _081C51A2
_081C516E:
	bl sub_81C5674
	b _081C51A2
_081C5174:
	bl sub_81C700C
	b _081C51A2
_081C517A:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	b _081C51A2
_081C5188:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
_081C51A0:
	strb r0, [r2, 0x8]
_081C51A2:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081C51D4
	.pool
_081C51BC:
	ldr r0, =sub_81C5038
	bl SetVBlankCallback
	ldr r0, =sub_81C501C
	bl SetMainCallback2
	movs r0, 0x1
	b _081C51D6
	.pool
_081C51D4:
	movs r0, 0
_081C51D6:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81C5078

	thumb_func_start sub_81C51DC
sub_81C51DC: @ 81C51DC
	push {lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0861F2B4
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	adds r1, 0x4
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C51DC

	thumb_func_start sub_81C5238
sub_81C5238: @ 81C5238
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203CF2C
	ldr r0, [r4]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bhi _081C52F0
	lsls r0, 2
	ldr r1, =_081C5264
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C5264:
	.4byte _081C5278
	.4byte _081C5294
	.4byte _081C52B8
	.4byte _081C52C8
	.4byte _081C52D4
_081C5278:
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08D9A620
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081C52D8
	.pool
_081C5294:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5308
	ldr r0, =gUnknown_08D9AE04
	ldr r4, =gUnknown_0203CF2C
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C52DC
	.pool
_081C52B8:
	ldr r0, =gUnknown_08D9AF44
	movs r1, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	b _081C52D8
	.pool
_081C52C8:
	ldr r0, =gUnknown_0861F3CC
	bl LoadCompressedObjectPic
	b _081C52D8
	.pool
_081C52D4:
	bl sub_81C6E98
_081C52D8:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
_081C52DC:
	ldr r0, =0x00000984
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _081C5308
	.pool
_081C52F0:
	bl sub_8122328
	ldr r0, [r4]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _081C530A
	.pool
_081C5308:
	movs r0, 0
_081C530A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C5238

	thumb_func_start sub_81C5314
sub_81C5314: @ 81C5314
	push {r4-r7,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r3, =0x00000e2c
	adds r0, r3
	adds r7, r2, r0
	movs r6, 0
	ldr r1, =gUnknown_0203CF2C
	ldr r0, [r1]
	ldr r4, =0x00000821
	adds r0, r4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _081C5382
	adds r5, r1, 0
_081C5344:
	lsls r1, r6, 1
	adds r4, r1, r6
	lsls r4, 3
	ldr r0, =0x0000087c
	adds r4, r0
	ldr r0, [r5]
	adds r0, r4
	adds r1, r7
	ldrh r1, [r1]
	bl sub_81C540C
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x00000824
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, =0x00000828
	adds r0, r1, r4
	adds r0, r2
	str r6, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x00000821
	adds r1, r0
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r6, r0
	blt _081C5344
_081C5382:
	ldr r5, =gUnknown_0203CF2C
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	ldr r1, =0x0000087c
	adds r4, r1
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gUnknown_085E8DB4
	bl StringCopy
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x00000824
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, =0x00000828
	adds r1, r4
	adds r1, r2
	movs r0, 0x2
	negs r0, r0
	str r0, [r1]
	ldr r2, =gUnknown_03006310
	adds r1, r2, 0
	ldr r0, =gUnknown_0861F2C0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r5]
	ldr r6, =0x00000821
	adds r0, r1, r6
	ldrb r0, [r0]
	strh r0, [r2, 0xC]
	adds r3, r1, r3
	str r3, [r2]
	ldr r7, =0x00000822
	adds r1, r7
	ldrb r0, [r1]
	strh r0, [r2, 0xE]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5314

	thumb_func_start sub_81C540C
sub_81C540C: @ 81C540C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r0, r4, 0
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _081C5450
	ldr r0, =gStringVar1
	adds r1, r4, 0
	subs r1, 0x84
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar2
	adds r0, r4, 0
	bl itemid_get_name
	ldr r1, =gUnknown_085E9210
	adds r0, r5, 0
	bl StringExpandPlaceholders
	b _081C5458
	.pool
_081C5450:
	adds r0, r4, 0
	adds r1, r5, 0
	bl itemid_get_name
_081C5458:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C540C

	thumb_func_start sub_81C5460
sub_81C5460: @ 81C5460
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081C5476
	movs r0, 0x5
	bl audio_play
	bl sub_81C6F20
_081C5476:
	ldr r5, =gUnknown_0203CF2C
	ldr r1, [r5]
	ldr r2, =0x00000814
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C5504
	adds r2, 0x1
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
	bl sub_81C6FF8
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C54E0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, r4, 1
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00000e2c
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	ldr r1, [r5]
	ldr r2, =0x00000815
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81C6F90
	b _081C54EE
	.pool
_081C54E0:
	ldr r0, =0x0000ffff
	ldr r1, [r5]
	ldr r2, =0x00000815
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81C6F90
_081C54EE:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000815
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_81C55D8
_081C5504:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5460

	thumb_func_start sub_81C5518
sub_81C5518: @ 81C5518
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C55B8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _081C5560
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r1, r0
	bne _081C5558
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C5AB8
	b _081C5560
	.pool
_081C5558:
	adds r0, r5, 0
	movs r1, 0xFF
	bl sub_81C5AB8
_081C5560:
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	ldr r2, =0x00000ca9
	adds r1, r3, r2
	ldrb r2, [r1]
	lsls r2, 30
	lsrs r2, 30
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 1
	adds r1, r4, r1
	ldr r2, =0x00000e54
	adds r3, r2
	adds r3, r1
	ldrb r1, [r3]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E8DA0
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x77
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r0, 0xFF
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r4, 0
	adds r3, r5, 0
	bl sub_81C6C94
_081C55B8:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5518

	thumb_func_start sub_81C55D8
sub_81C55D8: @ 81C55D8
	push {r4,lr}
	sub sp, 0x10
	adds r3, r0, 0
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _081C561C
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, 1
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00000e2c
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	bl ItemId_GetDescription
	adds r4, r0, 0
	b _081C5638
	.pool
_081C561C:
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085E91B0
	ldr r1, =gUnknown_0203CF30
	ldrb r1, [r1, 0x4]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E91C0
	adds r0, r4, 0
	bl StringExpandPlaceholders
_081C5638:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C55D8

	thumb_func_start sub_81C5674
sub_81C5674: @ 81C5674
	push {r4,lr}
	sub sp, 0x10
	ldr r4, =gUnknown_0203CF2C
	ldr r1, [r4]
	ldr r2, =0x00000816
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C56B4
	adds r2, 0xB
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x00000b5e
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0203CF38
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xAC
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	ldr r1, [r4]
	ldr r2, =0x00000816
	adds r1, r2
	strb r0, [r1]
_081C56B4:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5674

	thumb_func_start sub_81C56CC
sub_81C56CC: @ 81C56CC
	push {r4,lr}
	ldr r4, =gUnknown_0203CF2C
	ldr r0, [r4]
	ldr r2, =0x00000816
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C56EA
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x00000816
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_081C56EA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C56CC

	thumb_func_start sub_81C56F8
sub_81C56F8: @ 81C56F8
	push {r4,lr}
	ldr r0, =sub_81C5BC8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gUnknown_03006310
	ldr r2, =gUnknown_0203CF30
	ldrh r1, [r2, 0x8]
	ldrh r2, [r2, 0x6]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C56F8

	thumb_func_start sub_81C5738
sub_81C5738: @ 81C5738
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSaveBlock2Ptr
	ldr r6, [r2]
	ldr r3, =0x00000ca9
	adds r2, r6, r3
	ldrb r3, [r2]
	lsls r3, 30
	lsrs r2, r3, 30
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 2
	ldr r2, =0x00000e2c
	adds r4, r2
	adds r4, r6, r4
	lsrs r3, 30
	lsls r2, r3, 2
	adds r2, r3
	lsls r2, 1
	ldr r3, =0x00000e54
	adds r2, r3
	adds r6, r2
	lsls r5, r0, 1
	adds r5, r4
	ldrh r2, [r5]
	mov r8, r2
	lsls r2, r1, 1
	adds r2, r4
	ldrh r3, [r2]
	strh r3, [r5]
	mov r3, r8
	strh r3, [r2]
	adds r0, r6, r0
	ldrb r2, [r0]
	adds r6, r1
	ldrb r1, [r6]
	strb r1, [r0]
	strb r2, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5738

	thumb_func_start sub_81C57A8
sub_81C57A8: @ 81C57A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r6, r3, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r3, r0
	cmp r4, r5
	beq _081C5862
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	mov r12, r0
	adds r0, r3, r4
	ldrb r0, [r0]
	mov r8, r0
	cmp r5, r4
	bls _081C5830
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, r4, 16
	cmp r4, r5
	bge _081C5854
_081C5802:
	asrs r2, 16
	lsls r0, r2, 1
	adds r0, r6
	ldrh r1, [r0, 0x2]
	strh r1, [r0]
	adds r1, r3, r2
	ldrb r0, [r1, 0x1]
	strb r0, [r1]
	adds r2, 0x1
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, r5
	blt _081C5802
	b _081C5854
	.pool
_081C5830:
	lsls r2, r7, 16
	cmp r7, r5
	ble _081C5854
_081C5836:
	asrs r2, 16
	lsls r1, r2, 1
	adds r1, r6
	subs r0, r1, 0x2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, r3, r2
	subs r0, r1, 0x1
	ldrb r0, [r0]
	strb r0, [r1]
	subs r2, 0x1
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, r5
	bgt _081C5836
_081C5854:
	lsls r0, r5, 1
	adds r0, r6
	mov r2, r12
	strh r2, [r0]
	adds r0, r3, r5
	mov r1, r8
	strb r1, [r0]
_081C5862:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C57A8

	thumb_func_start sub_81C586C
sub_81C586C: @ 81C586C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r0, r3
	mov r9, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r4, =0x00000e54
	adds r0, r4
	adds r3, r0
	mov r8, r3
	movs r5, 0
	movs r3, 0
_081C58A4:
	lsls r0, r5, 1
	mov r1, r9
	adds r2, r0, r1
	ldrh r0, [r2]
	mov r4, r8
	adds r1, r4, r5
	cmp r0, 0
	beq _081C58BA
	ldrb r0, [r1]
	cmp r0, 0
	bne _081C58BE
_081C58BA:
	strh r3, [r2]
	strb r3, [r1]
_081C58BE:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _081C58A4
	movs r5, 0
_081C58CA:
	adds r1, r5, 0x1
	lsls r0, r1, 24
	lsrs r4, r0, 24
	adds r7, r1, 0
	cmp r4, 0x9
	bhi _081C58FE
	lsls r0, r5, 1
	mov r1, r9
	adds r6, r0, r1
_081C58DC:
	ldrh r0, [r6]
	cmp r0, 0
	beq _081C58EC
	mov r2, r8
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C58F4
_081C58EC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81C5738
_081C58F4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C58DC
_081C58FE:
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, 0x8
	bls _081C58CA
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C586C

	thumb_func_start sub_81C5924
sub_81C5924: @ 81C5924
	push {r4-r6,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x00000e2c
	adds r0, r1
	adds r5, r2, r0
	bl sub_81C586C
	ldr r3, =gUnknown_0203CF2C
	ldr r0, [r3]
	ldr r2, =0x00000821
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	movs r4, 0
	adds r6, r3, 0
_081C5954:
	lsls r0, r4, 1
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, =gUnknown_0203CF2C
	cmp r0, 0
	beq _081C596A
	ldr r1, [r6]
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081C596A:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9
	bls _081C5954
	ldr r0, [r3]
	ldr r2, =0x00000821
	adds r0, r2
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r2, [r2]
	cmp r2, 0x8
	bls _081C59AC
	ldr r2, =0x00000822
	adds r1, r0, r2
	movs r0, 0x8
	strb r0, [r1]
	b _081C59B2
	.pool
_081C59AC:
	ldr r1, =0x00000822
	adds r0, r1
	strb r2, [r0]
_081C59B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5924

	thumb_func_start sub_81C59BC
sub_81C59BC: @ 81C59BC
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x8]
	adds r3, r0, 0
	ldr r4, =gUnknown_0203CF2C
	cmp r1, 0
	beq _081C59E4
	ldrh r0, [r3, 0x8]
	ldr r1, [r4]
	ldr r5, =0x00000822
	adds r2, r1, r5
	ldrb r2, [r2]
	adds r0, r2
	subs r5, 0x1
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	ble _081C59E4
	subs r0, r1, r2
	strh r0, [r3, 0x8]
_081C59E4:
	adds r2, r3, 0
	ldrh r1, [r2, 0x8]
	ldrh r0, [r2, 0x6]
	adds r1, r0
	ldr r0, [r4]
	ldr r4, =0x00000821
	adds r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _081C5A18
	adds r1, r0, 0
	cmp r1, 0
	bne _081C5A14
	strh r1, [r2, 0x6]
	b _081C5A18
	.pool
_081C5A14:
	subs r0, 0x1
	strh r0, [r3, 0x6]
_081C5A18:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C59BC

	thumb_func_start sub_81C5A20
sub_81C5A20: @ 81C5A20
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x6]
	adds r5, r0, 0
	cmp r1, 0x4
	bls _081C5A80
	movs r4, 0
	ldrh r0, [r5, 0x6]
	subs r0, 0x4
	cmp r4, r0
	bgt _081C5A80
	ldrh r2, [r5, 0x8]
	ldr r6, =gUnknown_0203CF2C
	ldr r0, [r6]
	ldr r3, =0x00000822
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, r1
	ldr r7, =0x00000821
	adds r0, r7
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C5A80
	adds r3, r5, 0
_081C5A50:
	ldrh r0, [r3, 0x6]
	subs r0, 0x1
	strh r0, [r3, 0x6]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r3, 0x6]
	subs r0, 0x4
	cmp r4, r0
	bgt _081C5A80
	ldrh r2, [r5, 0x8]
	ldr r1, [r6]
	ldr r7, =0x00000822
	adds r0, r1, r7
	ldrb r0, [r0]
	adds r2, r0
	ldr r0, =0x00000821
	adds r1, r0
	ldrb r1, [r1]
	cmp r2, r1
	bne _081C5A50
_081C5A80:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5A20

	thumb_func_start sub_81C5A98
sub_81C5A98: @ 81C5A98
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_81C5AB8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C5A98

	thumb_func_start sub_81C5AB8
sub_81C5AB8: @ 81C5AB8
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r2, 0xFF
	bne _081C5AF4
	movs r0, 0x1
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl FillWindowPixelRect
	b _081C5B08
_081C5AF4:
	ldr r1, =gUnknown_085E8D60
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0
	adds r3, r5, 0
	bl sub_81C6C3C
_081C5B08:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5AB8

	thumb_func_start sub_81C5B14
sub_81C5B14: @ 81C5B14
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C5B4C
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5B14

	thumb_func_start sub_81C5B4C
sub_81C5B4C: @ 81C5B4C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r2, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C5BBC
	ldrb r0, [r2]
	ldr r4, =gUnknown_0203CF38
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _081C5B94
	bl SetMainCallback2
	b _081C5B9E
	.pool
_081C5B94:
	adds r0, r4, 0
	subs r0, 0x8
	ldr r0, [r0]
	bl SetMainCallback2
_081C5B9E:
	bl sub_81C56CC
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
_081C5BBC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5B4C

	thumb_func_start sub_81C5BC8
sub_81C5BC8: @ 81C5BC8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C5BEA
	b _081C5D16
_081C5BEA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C5BF8
	b _081C5D16
_081C5BF8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _081C5C5C
	ldr r4, =gUnknown_0203CF30
	ldrb r0, [r4, 0x4]
	cmp r0, 0x2
	bne _081C5C12
	b _081C5D16
_081C5C12:
	ldrb r0, [r7]
	adds r1, r4, 0
	adds r1, 0x8
	adds r2, r4, 0x6
	bl get_coro_args_x18_x1A
	ldrh r1, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	adds r1, r0
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000821
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _081C5D16
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81C67CC
	b _081C5D16
	.pool
_081C5C5C:
	ldrb r0, [r7]
	bl ListMenuHandleInput
	adds r6, r0, 0
	ldrb r0, [r7]
	ldr r1, =gUnknown_0203CF38
	mov r8, r1
	mov r2, r8
	subs r2, 0x2
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081C5C88
	adds r0, 0x1
	cmp r6, r0
	bne _081C5CA0
	b _081C5D16
	.pool
_081C5C88:
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0203CE7C
	strh r4, [r0]
	adds r0, r5, 0
	bl sub_81C5B14
	b _081C5D16
	.pool
_081C5CA0:
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_0203CE7C
	mov r12, r2
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, r6, 1
	ldr r0, =0x00000ca9
	adds r4, r2, r0
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r1, =0x00000e2c
	adds r0, r2, r1
	adds r0, r3
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1]
	strh r6, [r7, 0x2]
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r6, r0
	ldr r1, =0x00000e54
	adds r2, r1
	adds r2, r0
	ldrb r0, [r2]
	strh r0, [r7, 0x4]
	mov r0, r8
	subs r0, 0x8
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2
	bne _081C5D10
	adds r0, r5, 0
	bl sub_81C674C
	b _081C5D16
	.pool
_081C5D10:
	adds r0, r5, 0
	bl sub_81C5D20
_081C5D16:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C5BC8

	thumb_func_start sub_81C5D20
sub_81C5D20: @ 81C5D20
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C56CC
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_81C5A98
	ldr r0, =gUnknown_0203CF30
	ldrb r4, [r0, 0x4]
	cmp r4, 0x1
	beq _081C5D74
	cmp r4, 0x3
	beq _081C5DC4
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F308
	str r0, [r2]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	movs r0, 0x4
	b _081C5DD8
	.pool
_081C5D74:
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemId_GetBattleUsage
	lsls r0, 24
	cmp r0, 0
	beq _081C5DA0
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F30E
	b _081C5DCE
	.pool
_081C5DA0:
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r2, r0, r1
	ldr r1, =gUnknown_0861F310
	str r1, [r2]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	strb r4, [r0]
	b _081C5DDA
	.pool
_081C5DC4:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F30C
_081C5DCE:
	str r0, [r2]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	movs r0, 0x2
_081C5DD8:
	strb r0, [r1]
_081C5DDA:
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl itemid_get_name
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E8DBE
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C5E3C
	movs r0, 0
	b _081C5E42
	.pool
_081C5E3C:
	cmp r0, 0x2
	bne _081C5E50
	movs r0, 0x1
_081C5E42:
	bl sub_81C6D24
	lsls r0, 24
	lsrs r0, 24
	bl sub_81C5EAC
	b _081C5E62
_081C5E50:
	movs r0, 0x2
	bl sub_81C6D24
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	movs r2, 0x2
	bl sub_81C5F08
_081C5E62:
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _081C5E8C
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C5FE4
	b _081C5E98
	.pool
_081C5E8C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C5F68
_081C5E98:
	str r0, [r1]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5D20

	thumb_func_start sub_81C5EAC
sub_81C5EAC: @ 81C5EAC
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	ldr r6, =gUnknown_0203CF2C
	ldr r1, [r6]
	movs r5, 0x82
	lsls r5, 4
	adds r0, r1, r5
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0861F2D8
	str r0, [sp, 0xC]
	ldr r0, =0x00000818
	adds r1, r0
	ldr r0, [r1]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl AddItemMenuActionTextPrinters
	ldr r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5EAC

	thumb_func_start sub_81C5F08
sub_81C5F08: @ 81C5F08
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x38
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	ldr r0, =gUnknown_0861F2D8
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl sub_8198DBC
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x38
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8199944
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5F08

	thumb_func_start sub_81C5F68
sub_81C5F68: @ 81C5F68
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5FD0
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C5FD0
	adds r0, 0x1
	cmp r4, r0
	bne _081C5FA8
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0861F2D8
	ldr r1, [r0, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	b _081C5FD0
	.pool
_081C5FA8:
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_0861F2D8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000818
	adds r0, r2
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	beq _081C5FD0
	adds r0, r6, 0
	bl _call_via_r1
_081C5FD0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5F68

	thumb_func_start sub_81C5FE4
sub_81C5FE4: @ 81C5FE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C5FF8
	b _081C6160
_081C5FF8:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C6040
	lsls r0, r4, 24
	asrs r0, 24
	cmp r0, 0
	bgt _081C6016
	b _081C6160
_081C6016:
	subs r0, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	bne _081C6028
	b _081C6160
_081C6028:
	movs r0, 0x5
	bl audio_play
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	bl sub_8199134
	b _081C6160
	.pool
_081C6040:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C6084
	lsls r0, r4, 24
	asrs r1, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r2, 0x82
	lsls r2, 4
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x2
	cmp r1, r0
	blt _081C6060
	b _081C6160
_081C6060:
	adds r0, r1, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	movs r1, 0x1
	bl sub_8199134
	b _081C6160
	.pool
_081C6084:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C6098
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C60C0
_081C6098:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6160
	subs r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	negs r0, r0
	b _081C60FA
_081C60C0:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C60D6
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C6102
_081C60D6:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081C6160
	adds r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
_081C60FA:
	movs r1, 0
	bl sub_8199134
	b _081C6160
_081C6102:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6148
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_0861F2D8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	lsls r1, r4, 24
	asrs r1, 24
	ldr r3, =0x00000818
	adds r0, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r2, 0x4
	adds r0, r2
	ldr r1, [r0]
	cmp r1, 0
	beq _081C6160
	adds r0, r6, 0
	bl _call_via_r1
	b _081C6160
	.pool
_081C6148:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0861F2D8
	ldr r1, [r0, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
_081C6160:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5FE4

	thumb_func_start sub_81C616C
sub_81C616C: @ 81C616C
	push {lr}
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	blt _081C61A0
	ldr r0, =gUnknown_0203CF2C
	ldr r2, [r0]
	movs r3, 0x82
	lsls r3, 4
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bgt _081C61A0
	ldr r3, =0x00000818
	adds r0, r2, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _081C61A0
	movs r0, 0x1
	b _081C61A2
	.pool
_081C61A0:
	movs r0, 0
_081C61A2:
	pop {r1}
	bx r1
	thumb_func_end sub_81C616C

	thumb_func_start sub_81C61A8
sub_81C61A8: @ 81C61A8
	push {lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C61C8
	movs r0, 0
	bl sub_81C6D6C
	b _081C61DA
	.pool
_081C61C8:
	cmp r0, 0x2
	bne _081C61D4
	movs r0, 0x1
	bl sub_81C6D6C
	b _081C61DA
_081C61D4:
	movs r0, 0x2
	bl sub_81C6D6C
_081C61DA:
	pop {r0}
	bx r0
	thumb_func_end sub_81C61A8

	thumb_func_start sub_81C61E0
sub_81C61E0: @ 81C61E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203CE7C
	ldrh r0, [r4]
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	beq _081C620C
	cmp r0, 0x2
	beq _081C620C
	cmp r0, 0x3
	beq _081C620C
	ldrh r0, [r4]
	bl itemid_is_mail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C6228
_081C620C:
	bl sub_81C61A8
	ldr r1, =gUnknown_085E8F31
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C6252
	.pool
_081C6228:
	ldrh r0, [r4]
	bl ItemId_GetFieldFunc
	cmp r0, 0
	beq _081C6252
	bl sub_81C61A8
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldrh r0, [r4]
	bl ItemId_GetFieldFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081C6252:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C61E0

	thumb_func_start sub_81C6258
sub_81C6258: @ 81C6258
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C61A8
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6258

	thumb_func_start sub_81C629C
sub_81C629C: @ 81C629C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81C5674
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C5BC8
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C629C

	thumb_func_start sub_81C62C4
sub_81C62C4: @ 81C62C4
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r6, r0, 3
	ldr r7, =gTasks + 0x8
	adds r4, r6, r7
	bl sub_81C61A8
	movs r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _081C62F4
	adds r0, r5, 0
	bl sub_81C6350
	b _081C6334
	.pool
_081C62F4:
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl itemid_get_name
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E8EE0
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	bl sub_81C6404
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81C64B4
	str r1, [r0]
_081C6334:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C62C4

	thumb_func_start sub_81C6350
sub_81C6350: @ 81C6350
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl itemid_get_name
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E8F0E
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldr r1, =gUnknown_0861F314
	adds r0, r5, 0
	bl sub_81C6DAC
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6350

	thumb_func_start sub_81C63D0
sub_81C63D0: @ 81C63D0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C63D0

	thumb_func_start sub_81C6404
sub_81C6404: @ 81C6404
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gStringVar1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E8DA0
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	bl sub_81C6CEC
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	bl Print
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6404

	thumb_func_start sub_81C645C
sub_81C645C: @ 81C645C
	push {r4,lr}
	sub sp, 0xC
	adds r1, r0, 0
	ldr r0, =gStringVar1
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E8DA0
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	bl Print
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C645C

	thumb_func_start sub_81C64B4
sub_81C64B4: @ 81C64B4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x10
	ldrh r1, [r4, 0x4]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C64E8
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	bl sub_81C645C
	b _081C6544
	.pool
_081C64E8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C651C
	movs r0, 0x5
	bl audio_play
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C6350
	b _081C6544
	.pool
_081C651C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C6544
	movs r0, 0x5
	bl audio_play
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl sub_81C63D0
_081C6544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C64B4

	thumb_func_start sub_81C654C
sub_81C654C: @ 81C654C
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl itemid_get_name
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar4
	ldr r1, =gUnknown_085E8EF9
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81C65CC
	str r0, [r4]
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C654C

	thumb_func_start sub_81C65CC
sub_81C65CC: @ 81C65CC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r6, =gUnknown_0203CF38
	subs r7, r6, 0x2
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081C662E
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	ldrh r1, [r4, 0x10]
	bl sub_80D7334
	ldrb r0, [r4]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_81AE6C8
	bl sub_81C5924
	bl sub_81C59BC
	bl sub_81C5314
	ldr r0, =gUnknown_03006310
	ldrh r1, [r6]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C629C
_081C662E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C65CC

	thumb_func_start sub_81C6648
sub_81C6648: @ 81C6648
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	bl sub_81C61A8
	ldr r5, =gUnknown_0203CE7C
	ldrh r0, [r5]
	bl itemid_is_mail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C667C
	ldr r1, =gUnknown_085E8DCE
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C66A6
	.pool
_081C667C:
	ldrh r0, [r5]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081C66A0
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =sub_81B7F60
	str r0, [r1]
	adds r0, r4, 0
	bl sub_81C5B14
	b _081C66A6
	.pool
_081C66A0:
	adds r0, r6, 0
	bl sub_81C66AC
_081C66A6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C6648

	thumb_func_start sub_81C66AC
sub_81C66AC: @ 81C66AC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl itemid_get_name
	ldr r5, =gStringVar4
	ldr r1, =gUnknown_085E8E11
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageInBattlePyramid
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C66AC

	thumb_func_start sub_81C66EC
sub_81C66EC: @ 81C66EC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C670A
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81C6714
_081C670A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C66EC

	thumb_func_start sub_81C6714
sub_81C6714: @ 81C6714
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C6E1C
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6714

	thumb_func_start sub_81C674C
sub_81C674C: @ 81C674C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r5, =gUnknown_0203CE7C
	ldrh r0, [r5]
	bl itemid_80BF6D8_mail_related
	lsls r0, 24
	cmp r0, 0
	bne _081C677C
	ldr r1, =gUnknown_085E8DCE
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C6796
	.pool
_081C677C:
	ldrh r0, [r5]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081C6790
	adds r0, r4, 0
	bl sub_81C5B14
	b _081C6796
_081C6790:
	adds r0, r6, 0
	bl sub_81C66AC
_081C6796:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C674C

	thumb_func_start sub_81C679C
sub_81C679C: @ 81C679C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203CE7C
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	cmp r0, 0
	beq _081C67C0
	bl sub_81C61A8
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081C67C0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C679C

	thumb_func_start sub_81C67CC
sub_81C67CC: @ 81C67CC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r5, r4, r0
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x6]
	ldrh r0, [r0, 0x8]
	adds r1, r0
	strh r1, [r5, 0x2]
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000814
	adds r0, r2
	movs r2, 0
	mov r8, r2
	strb r1, [r0]
	ldrb r0, [r5]
	movs r1, 0x10
	movs r2, 0x1
	bl sub_81AF15C
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	lsls r2, 1
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r0, =0x00000e2c
	adds r3, r0
	adds r3, r2
	ldrh r0, [r3]
	ldr r1, =gStringVar1
	bl itemid_get_name
	ldr r6, =gStringVar4
	ldr r1, =gUnknown_085E8DFE
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	mov r1, r8
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_81C5A98
	ldrb r0, [r5, 0x2]
	bl sub_81C704C
	movs r2, 0x8
	negs r2, r2
	add r9, r2
	add r4, r9
	ldr r0, =sub_81C68B0
	str r0, [r4]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C67CC

	thumb_func_start sub_81C68B0
sub_81C68B0: @ 81C68B0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C695C
	ldr r7, =gMain
	ldrh r1, [r7, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081C68F8
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	ldr r1, =gUnknown_0203CF38
	subs r2, r1, 0x2
	bl get_coro_args_x18_x1A
	b _081C6940
	.pool
_081C68F8:
	ldrb r0, [r4]
	bl ListMenuHandleInput
	adds r6, r0, 0
	ldrb r0, [r4]
	ldr r4, =gUnknown_0203CF38
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl get_coro_args_x18_x1A
	movs r0, 0
	bl sub_81C7028
	subs r4, 0x8
	ldrb r0, [r4, 0x6]
	bl sub_81C704C
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081C6930
	adds r0, 0x1
	cmp r6, r0
	bne _081C6950
	b _081C695C
	.pool
_081C6930:
	movs r0, 0x5
	bl audio_play
	ldrh r1, [r7, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6948
_081C6940:
	adds r0, r5, 0
	bl sub_81C6964
	b _081C695C
_081C6948:
	adds r0, r5, 0
	bl sub_81C6A14
	b _081C695C
_081C6950:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81C6964
_081C695C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C68B0

	thumb_func_start sub_81C6964
sub_81C6964: @ 81C6964
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r7, =gUnknown_0203CF38
	subs r0, r7, 0x2
	mov r8, r0
	ldrh r0, [r0]
	ldrh r1, [r7]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	cmp r1, r4
	beq _081C6996
	subs r0, r4, 0x1
	cmp r1, r0
	bne _081C69A8
_081C6996:
	adds r0, r6, 0
	bl sub_81C6A14
	b _081C69FC
	.pool
_081C69A8:
	ldrb r0, [r5, 0x2]
	lsls r1, r4, 24
	lsrs r1, 24
	bl sub_81C57A8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C7028
	ldrb r0, [r5]
	adds r1, r7, 0
	mov r2, r8
	bl sub_81AE6C8
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	cmp r0, r4
	bge _081C69E0
	adds r1, r7, 0
	subs r1, 0x8
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	strh r0, [r1, 0x6]
_081C69E0:
	bl sub_81C5314
	ldr r0, =gUnknown_03006310
	ldrh r1, [r7]
	mov r3, r8
	ldrh r2, [r3]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_81C629C
_081C69FC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6964

	thumb_func_start sub_81C6A14
sub_81C6A14: @ 81C6A14
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r5, =gUnknown_0203CF38
	subs r7, r5, 0x2
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C7028
	ldrb r0, [r4]
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_81AE6C8
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldrh r0, [r5]
	ldrh r1, [r7]
	adds r0, r1
	cmp r2, r0
	bge _081C6A5E
	adds r1, r5, 0
	subs r1, 0x8
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	strh r0, [r1, 0x6]
_081C6A5E:
	bl sub_81C5314
	ldr r0, =gUnknown_03006310
	ldrh r1, [r5]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	adds r0, r6, 0
	bl sub_81C629C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6A14

	thumb_func_start sub_81C6A94
sub_81C6A94: @ 81C6A94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r0, =gPlayerParty
	mov r9, r0
	movs r0, 0x14
	bl Alloc
	adds r7, r0, 0
	movs r0, 0xA
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	ldr r2, [r1]
	ldr r4, =0x00000ca9
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, =0x00000e2c
	adds r1, r0
	adds r0, r7, 0
	movs r2, 0x14
	bl memcpy
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	adds r1, r2
	ldr r0, =0x00000e54
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0xA
	bl memcpy
	movs r6, 0
_081C6AF8:
	movs r0, 0x64
	muls r0, r6
	add r0, r9
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	cmp r0, 0
	beq _081C6B88
	movs r1, 0x1
	bl bag_add_item
	lsls r0, 24
	cmp r0, 0
	bne _081C6B88
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x00000e2c
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x14
	bl memcpy
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r2
	ldr r1, =0x00000e54
	adds r0, r1
	adds r1, r5, 0
	movs r2, 0xA
	bl memcpy
	adds r0, r7, 0
	bl Free
	adds r0, r5, 0
	bl Free
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	strh r0, [r1]
	b _081C6BC6
	.pool
_081C6B88:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _081C6AF8
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	movs r6, 0
	movs r4, 0x64
_081C6B9C:
	adds r0, r6, 0
	muls r0, r4
	add r0, r9
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _081C6B9C
	ldr r1, =gUnknown_020375F0
	movs r0, 0
	strh r0, [r1]
	adds r0, r7, 0
	bl Free
	adds r0, r5, 0
	bl Free
_081C6BC6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6A94

	thumb_func_start sub_81C6BD8
sub_81C6BD8: @ 81C6BD8
	push {r4,lr}
	ldr r0, =gUnknown_0861F328
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_809882C
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xD0
	bl copy_textbox_border_tile_patterns_to_vram
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081C6C04:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081C6C04
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6BD8

	thumb_func_start sub_81C6C3C
sub_81C6C3C: @ 81C6C3C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	ldr r5, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861F31C
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6C3C

	thumb_func_start sub_81C6C94
sub_81C6C94: @ 81C6C94
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	ldr r5, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861F31C
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x7
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6C94

	thumb_func_start sub_81C6CEC
sub_81C6CEC: @ 81C6CEC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C6CEC

	thumb_func_start sub_81C6D08
sub_81C6D08: @ 81C6D08
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF2C
	ldr r1, [r1]
	ldr r2, =0x0000080f
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C6D08

	thumb_func_start sub_81C6D24
sub_81C6D24: @ 81C6D24
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r3, =0x0000080f
	adds r1, r2, r3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C6D58
	lsls r0, r2, 3
	ldr r1, =gUnknown_0861F350
	adds r0, r1
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_081C6D58:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C6D24

	thumb_func_start sub_81C6D6C
sub_81C6D6C: @ 81C6D6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF2C
	ldr r2, =0x0000080f
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C6D9E
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0xFF
	strb r0, [r4]
_081C6D9E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6D6C

	thumb_func_start sub_81C6DAC
sub_81C6DAC: @ 81C6DAC
	push {lr}
	sub sp, 0x10
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0861F370
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0xE
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6DAC

	thumb_func_start DisplayItemMessageInBattlePyramid
@ void DisplayItemMessageInBattlePyramid(u8 taskId, u8 *str, void ( *callback)(u8 taskId))
DisplayItemMessageInBattlePyramid: @ 81C6DD8
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0xA
	movs r3, 0xD
	bl DisplayMessageAndContinueTask
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end DisplayItemMessageInBattlePyramid

	thumb_func_start sub_81C6E1C
sub_81C6E1C: @ 81C6E1C
	push {lr}
	movs r0, 0x2
	movs r1, 0
	bl sub_8197DF8
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C6E1C

	thumb_func_start sub_81C6E38
sub_81C6E38: @ 81C6E38
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r2, =0x00000804
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _081C6E80
	ldr r0, =0x00001024
	adds r4, r0
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0xFF
	strb r0, [r5]
_081C6E80:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6E38

	thumb_func_start sub_81C6E98
sub_81C6E98: @ 81C6E98
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0x40
	bl Alloc
	adds r4, r0, 0
	ldr r0, =gUnknown_08D9ADD0
	adds r1, r4, 0
	bl LZDecompressWram
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r4, r0
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	ldr r1, =0x00001024
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadTaggedObjectPalette
	adds r0, r4, 0
	bl Free
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6E98

	thumb_func_start sub_81C6EF4
sub_81C6EF4: @ 81C6EF4
	push {r4,lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r4, [r0]
	ldr r0, =0x00000804
	adds r4, r0
	ldr r0, =gUnknown_0861F3D4
	movs r1, 0x44
	movs r2, 0x38
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6EF4

	thumb_func_start sub_81C6F20
sub_81C6F20: @ 81C6F20
	push {r4,lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000804
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081C6F50
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	ldr r0, =sub_81C6F68
	str r0, [r4, 0x1C]
_081C6F50:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F20

	thumb_func_start sub_81C6F68
sub_81C6F68: @ 81C6F68
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081C6F84
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectRotScalAnim
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081C6F84:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F68

	thumb_func_start sub_81C6F90
sub_81C6F90: @ 81C6F90
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r2, =0x00000805
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _081C6FE0
	ldr r0, =0x00001025
	adds r4, r0
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl AddItemIconObject
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081C6FE0
	strb r2, [r5]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x18
	strh r1, [r0, 0x24]
	movs r1, 0x58
	strh r1, [r0, 0x26]
_081C6FE0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F90

	thumb_func_start sub_81C6FF8
sub_81C6FF8: @ 81C6FF8
	push {lr}
	lsls r0, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 24
	bl sub_81C6E38
	pop {r0}
	bx r0
	thumb_func_end sub_81C6FF8

	thumb_func_start sub_81C700C
sub_81C700C: @ 81C700C
	push {lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	movs r1, 0x8
	bl sub_8122344
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C700C

	thumb_func_start sub_81C7028
sub_81C7028: @ 81C7028
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	movs r1, 0x8
	bl sub_81223FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7028

	thumb_func_start sub_81C704C
sub_81C704C: @ 81C704C
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	lsrs r3, 4
	movs r1, 0x80
	lsls r1, 13
	adds r3, r1
	lsrs r3, 16
	movs r1, 0x88
	movs r2, 0x78
	bl sub_8122448
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C704C

	thumb_func_start sub_81C7078
sub_81C7078: @ 81C7078
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl is_c1_link_related_active
	cmp r0, 0
	bne _081C7090
	ldr r0, =sub_81C7170
	b _081C7092
	.pool
_081C7090:
	ldr r0, =sub_81C71E4
_081C7092:
	lsls r1, r4, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =gUnknown_0203CF3C
	ldrb r1, [r2]
	strh r1, [r0, 0xE]
	ldrb r0, [r2]
	adds r1, r0, 0x1
	strb r1, [r2]
	lsls r0, 24
	lsrs r0, 8
	orrs r0, r4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7078

	thumb_func_start sub_81C70D8
sub_81C70D8: @ 81C70D8
	push {lr}
	ldr r1, =0x0000ffff
	ands r1, r0
	lsrs r3, r0, 16
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _081C711C
	ldr r2, [r1]
	ldr r0, =sub_81C7170
	cmp r2, r0
	beq _081C70FE
	ldr r0, =sub_81C71E4
	cmp r2, r0
	bne _081C711C
_081C70FE:
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, r3
	bne _081C711C
	movs r0, 0x1
	b _081C711E
	.pool
_081C711C:
	movs r0, 0
_081C711E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C70D8

	thumb_func_start sub_81C7124
sub_81C7124: @ 81C7124
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gTasks
_081C712C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _081C7160
	ldr r1, [r4]
	ldr r0, =sub_81C7170
	cmp r1, r0
	beq _081C7140
	ldr r0, =sub_81C71E4
	cmp r1, r0
	bne _081C7160
_081C7140:
	lsls r0, r5, 24
	lsrs r0, 24
	movs r1, 0x1
	bl GetWordTaskArg
	cmp r0, r6
	bne _081C7160
	movs r0, 0x1
	b _081C716A
	.pool
_081C7160:
	adds r4, 0x28
	adds r5, 0x1
	cmp r5, 0xF
	ble _081C712C
	movs r0, 0
_081C716A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7124

	thumb_func_start sub_81C7170
sub_81C7170: @ 81C7170
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r6, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r7, 0
_081C718C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r6
	cmp r0, 0x4
	bhi _081C71D6
	lsls r0, 2
	ldr r1, =_081C71AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C71AC:
	.4byte _081C71C6
	.4byte _081C71C0
	.4byte _081C71DE
	.4byte _081C71DA
	.4byte _081C71CE
_081C71C0:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C71D8
_081C71C6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081C71DE
_081C71CE:
	adds r0, r5, 0
	bl DestroyTask
	b _081C71DE
_081C71D6:
	subs r0, 0x5
_081C71D8:
	strh r0, [r4]
_081C71DA:
	cmp r7, 0
	beq _081C718C
_081C71DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7170

	thumb_func_start sub_81C71E4
sub_81C71E4: @ 81C71E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8087598
	cmp r0, 0
	bne _081C724A
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r2, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r2
	cmp r0, 0x4
	bhi _081C7246
	lsls r0, 2
	ldr r1, =_081C7224
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C7224:
	.4byte _081C7238
	.4byte _081C7238
	.4byte _081C724A
	.4byte _081C724A
	.4byte _081C723E
_081C7238:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C7248
_081C723E:
	adds r0, r5, 0
	bl DestroyTask
	b _081C724A
_081C7246:
	subs r0, 0x5
_081C7248:
	strh r0, [r4]
_081C724A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C71E4

	thumb_func_start CB2_PokeNav
CB2_PokeNav: @ 81C7250
	push {r4,lr}
	ldr r4, =gUnknown_0203CF40
	movs r0, 0x5C
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081C7270
	ldr r0, =sub_8086194
	bl SetMainCallback2
	b _081C7292
	.pool
_081C7270:
	bl sub_81C7360
	bl ResetTasks
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_81C742C
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81C7400
	bl SetMainCallback2
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
_081C7292:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_PokeNav

	thumb_func_start sub_81C72A4
sub_81C72A4: @ 81C72A4
	push {lr}
	ldr r0, =sub_81C72BC
	bl SetMainCallback2
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C72A4

	thumb_func_start sub_81C72BC
sub_81C72BC: @ 81C72BC
	push {r4,lr}
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C7320
	ldr r4, =gUnknown_0203CF40
	movs r0, 0x5C
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081C72F0
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	b _081C7320
	.pool
_081C72F0:
	bl sub_81C7360
	ldr r1, [r4]
	movs r0, 0x1
	strh r0, [r1, 0x8]
	bl ResetTasks
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_81C742C
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81C7400
	bl SetMainCallback2
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
_081C7320:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C72BC

	thumb_func_start sub_81C7334
sub_81C7334: @ 81C7334
	push {r4,lr}
	movs r4, 0
_081C7338:
	adds r0, r4, 0
	bl sub_81C7650
	adds r4, 0x1
	cmp r4, 0x12
	ble _081C7338
	ldr r4, =gUnknown_0203CF40
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	bl InitKeys
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7334

	thumb_func_start sub_81C7360
sub_81C7360: @ 81C7360
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r2, 0
	movs r1, 0x12
	adds r0, 0x58
_081C736A:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _081C736A
	movs r4, 0
	strh r4, [r5, 0x8]
	str r4, [r5, 0x4]
	bl sub_81C7388
	str r0, [r5, 0xC]
	str r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7360

	thumb_func_start sub_81C7388
sub_81C7388: @ 81C7388
	push {r4-r6,lr}
	movs r5, 0
_081C738C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081C73BA
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081C73BA
	adds r0, r4, 0
	movs r1, 0x52
	bl GetMonData
	cmp r0, 0
	bne _081C73E2
_081C73BA:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081C738C
	movs r4, 0
_081C73C2:
	movs r5, 0
	lsls r6, r4, 24
_081C73C6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80D2270
	cmp r0, 0
	beq _081C73EC
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	movs r2, 0x52
	bl get_pokemon_data_from_any_box
	cmp r0, 0
	beq _081C73EC
_081C73E2:
	movs r0, 0x1
	b _081C73FA
	.pool
_081C73EC:
	adds r5, 0x1
	cmp r5, 0x1D
	ble _081C73C6
	adds r4, 0x1
	cmp r4, 0xD
	ble _081C73C2
	movs r0, 0
_081C73FA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7388

	thumb_func_start sub_81C7400
sub_81C7400: @ 81C7400
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81C7400

	thumb_func_start sub_81C7418
sub_81C7418: @ 81C7418
	push {lr}
	bl TransferPlttBuffer
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	pop {r0}
	bx r0
	thumb_func_end sub_81C7418

	thumb_func_start sub_81C742C
sub_81C742C: @ 81C742C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r7, r1, r0
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x5
	bls _081C7446
	b _081C7562
_081C7446:
	lsls r0, 2
	ldr r1, =_081C7458
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C7458:
	.4byte _081C7470
	.4byte _081C747A
	.4byte _081C7490
	.4byte _081C749C
	.4byte _081C751E
	.4byte _081C752C
_081C7470:
	bl sub_81C76C4
	movs r0, 0x1
	strh r0, [r7]
	b _081C7562
_081C747A:
	bl sub_81C76FC
	cmp r0, 0
	bne _081C7562
	ldr r0, =0x000186a0
	bl sub_81C756C
	b _081C74E8
	.pool
_081C7490:
	bl sub_81C786C
	cmp r0, 0
	bne _081C7562
	movs r0, 0x3
	strh r0, [r7]
_081C749C:
	bl sub_81C75E0
	adds r6, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _081C74FC
	ldr r0, =0x0001869f
	cmp r6, r0
	bls _081C7506
	ldr r4, =gUnknown_0861F3EC
	ldr r5, =gUnknown_0203CF40
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r4, 0x14
	adds r0, r4
	ldr r0, [r0]
	bl _call_via_r0
	adds r0, r6, 0
	bl sub_81C756C
	cmp r0, 0
	beq _081C74FC
_081C74E8:
	movs r0, 0x4
	strh r0, [r7]
	b _081C7562
	.pool
_081C74FC:
	bl sub_81C7710
	movs r0, 0x5
	strh r0, [r7]
	b _081C7562
_081C7506:
	cmp r6, 0
	beq _081C7562
	adds r0, r6, 0
	bl sub_81C7850
	bl sub_81C786C
	cmp r0, 0
	beq _081C7562
	movs r0, 0x2
	strh r0, [r7]
	b _081C7562
_081C751E:
	bl sub_81C75D4
	cmp r0, 0
	bne _081C7562
	movs r0, 0x3
	strh r0, [r7]
	b _081C7562
_081C752C:
	bl sub_81C7738
	cmp r0, 0
	bne _081C7562
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_81C9430
	bl sub_81C7334
	cmp r4, 0
	beq _081C755C
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	b _081C7562
	.pool
_081C755C:
	ldr r0, =sub_8086194
	bl SetMainCallback2
_081C7562:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C742C

	thumb_func_start sub_81C756C
sub_81C756C: @ 81C756C
	push {r4-r6,lr}
	ldr r1, =0xfffe7960
	adds r6, r0, r1
	bl sub_81C75F4
	ldr r5, =gUnknown_0861F3EC
	lsls r0, r6, 3
	subs r0, r6
	lsls r4, r0, 2
	adds r0, r4, r5
	ldr r0, [r0]
	bl _call_via_r0
	cmp r0, 0
	beq _081C75CC
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	bl _call_via_r0
	cmp r0, 0
	beq _081C75CC
	adds r0, r5, 0
	adds r0, 0xC
	adds r0, r4, r0
	ldr r0, [r0]
	adds r1, r5, 0
	adds r1, 0x10
	adds r1, r4, r1
	ldr r1, [r1]
	bl sub_81C7834
	ldr r0, =gUnknown_0203CF40
	ldr r1, [r0]
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1]
	str r6, [r1, 0x4]
	movs r0, 0x1
	b _081C75CE
	.pool
_081C75CC:
	movs r0, 0
_081C75CE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C756C

	thumb_func_start sub_81C75D4
sub_81C75D4: @ 81C75D4
	push {lr}
	bl sub_81C786C
	pop {r1}
	bx r1
	thumb_func_end sub_81C75D4

	thumb_func_start sub_81C75E0
sub_81C75E0: @ 81C75E0
	push {lr}
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C75E0

	thumb_func_start sub_81C75F4
sub_81C75F4: @ 81C75F4
	push {lr}
	bl InitKeys
	pop {r0}
	bx r0
	thumb_func_end sub_81C75F4

	thumb_func_start c3args_set_0toR1_1to0
c3args_set_0toR1_1to0: @ 81C7600
	push {lr}
	bl SetVBlankCallback
	pop {r0}
	bx r0
	thumb_func_end c3args_set_0toR1_1to0

	thumb_func_start sub_81C760C
sub_81C760C: @ 81C760C
	push {lr}
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C760C

	thumb_func_start sub_81C761C
sub_81C761C: @ 81C761C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl Alloc
	ldr r1, =gUnknown_0203CF40
	ldr r1, [r1]
	lsls r4, 2
	adds r1, 0x10
	adds r1, r4
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C761C

	thumb_func_start sub_81C763C
sub_81C763C: @ 81C763C
	ldr r1, =gUnknown_0203CF40
	ldr r1, [r1]
	lsls r0, 2
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C763C

	thumb_func_start sub_81C7650
sub_81C7650: @ 81C7650
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203CF40
	ldr r1, [r5]
	lsls r4, r0, 2
	adds r1, 0x10
	adds r1, r4
	ldr r0, [r1]
	cmp r0, 0
	beq _081C7670
	bl Free
	ldr r0, [r5]
	adds r0, 0x10
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_081C7670:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7650

	thumb_func_start sub_81C767C
sub_81C767C: @ 81C767C
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	bx lr
	.pool
	thumb_func_end sub_81C767C

	thumb_func_start sub_81C7688
sub_81C7688: @ 81C7688
	ldr r1, =gUnknown_0203CF40
	ldr r1, [r1]
	strh r0, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end sub_81C7688

	thumb_func_start sub_81C7694
sub_81C7694: @ 81C7694
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x4
	bls _081C769E
	movs r1, 0
_081C769E:
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	strh r1, [r0, 0xA]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7694

	thumb_func_start sub_81C76AC
sub_81C76AC: @ 81C76AC
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	bx lr
	.pool
	thumb_func_end sub_81C76AC

	thumb_func_start sub_81C76B8
sub_81C76B8: @ 81C76B8
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C76B8

	thumb_func_start sub_81C76C4
sub_81C76C4: @ 81C76C4
	push {r4,lr}
	ldr r1, =0x0000082c
	movs r0, 0
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C76F4
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	ldr r0, =sub_81C7764
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C76F6
	.pool
_081C76F4:
	movs r0, 0
_081C76F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C76C4

	thumb_func_start sub_81C76FC
sub_81C76FC: @ 81C76FC
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0xC]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C76FC

	thumb_func_start sub_81C7710
sub_81C7710: @ 81C7710
	push {lr}
	sub sp, 0x4
	movs r0, 0x6F
	bl audio_play
	bl sub_81CAADC
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_81C7710

	thumb_func_start sub_81C7738
sub_81C7738: @ 81C7738
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C7750
	movs r0, 0x1
	b _081C775E
	.pool
_081C7750:
	bl sub_81C99D4
	bl sub_81C7C94
	bl FreeAllWindowBuffers
	movs r0, 0
_081C775E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C7738

	thumb_func_start sub_81C7764
sub_81C7764: @ 81C7764
	push {r4,lr}
	sub sp, 0x4
	cmp r0, 0x1
	beq _081C77B0
	cmp r0, 0x1
	bgt _081C7776
	cmp r0, 0
	beq _081C7780
	b _081C782A
_081C7776:
	cmp r0, 0x2
	beq _081C77FC
	cmp r0, 0x3
	beq _081C780E
	b _081C782A
_081C7780:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	bl FreeAllWindowBuffers
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0861FA04
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	bl sub_8199D98
	bl reset_temp_tile_data_buffers
	movs r0, 0x1
	b _081C782C
	.pool
_081C77B0:
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r1, =gUnknown_08DC7B80
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r4, 0x2C
	movs r0, 0
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DC7D84
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_08DC7B60
	movs r1, 0
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081C782C
	.pool
_081C77FC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081C7818
	bl sub_81C7B74
	movs r0, 0
	b _081C782C
_081C780E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C781C
_081C7818:
	movs r0, 0x2
	b _081C782C
_081C781C:
	bl sub_81C7C28
	bl sub_81C7D28
	movs r0, 0
	bl ShowBg
_081C782A:
	movs r0, 0x4
_081C782C:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7764

	thumb_func_start sub_81C7834
sub_81C7834: @ 81C7834
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	bl sub_81C763C
	str r4, [r0]
	str r5, [r0, 0x4]
	movs r1, 0
	str r1, [r0, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7834

	thumb_func_start sub_81C7850
sub_81C7850: @ 81C7850
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	movs r1, 0
	str r1, [r0, 0x8]
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7850

	thumb_func_start sub_81C786C
sub_81C786C: @ 81C786C
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81C786C

	thumb_func_start sub_81C7880
sub_81C7880: @ 81C7880
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =atk47_cmd47
	movs r1, 0x4
	bl sub_81C7078
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7880

	thumb_func_start sub_81C78A0
sub_81C78A0: @ 81C78A0
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =sub_81C791C
	movs r1, 0x4
	bl sub_81C7078
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C78A0

	thumb_func_start sub_81C78C0
sub_81C78C0: @ 81C78C0
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0xC]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C78C0

	thumb_func_start atk47_cmd47
atk47_cmd47: @ 81C78D4
	push {lr}
	cmp r0, 0x1
	beq _081C78EA
	cmp r0, 0x1
	bgt _081C78E4
	cmp r0, 0
	beq _081C78EA
	b _081C7914
_081C78E4:
	cmp r0, 0x2
	beq _081C78EE
	b _081C7914
_081C78EA:
	movs r0, 0
	b _081C7916
_081C78EE:
	movs r1, 0xC0
	lsls r1, 1
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgY
	ldr r1, =0x00001fff
	cmp r0, r1
	bhi _081C7908
	movs r0, 0x2
	b _081C7916
	.pool
_081C7908:
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
_081C7914:
	movs r0, 0x4
_081C7916:
	pop {r1}
	bx r1
	thumb_func_end atk47_cmd47

	thumb_func_start sub_81C791C
sub_81C791C: @ 81C791C
	push {lr}
	movs r1, 0xC0
	lsls r1, 1
	movs r0, 0
	movs r2, 0x2
	bl ChangeBgY
	cmp r0, 0
	ble _081C7932
	movs r0, 0x2
	b _081C793E
_081C7932:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x4
_081C793E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C791C

	thumb_func_start sub_81C7944
sub_81C7944: @ 81C7944
	push {lr}
	lsls r1, 1
	ldr r3, =gPlttBufferUnfaded
	adds r1, r3
	lsls r2, 10
	lsrs r2, 11
	bl CpuSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7944

	thumb_func_start sub_81C795C
sub_81C795C: @ 81C795C
	push {r4,lr}
	adds r4, r0, 0
	b _081C7974
_081C7962:
	lsls r0, r1, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r0, r2
	ldr r0, [r4]
	movs r2, 0x20
	bl sub_81C7944
	adds r4, 0x8
_081C7974:
	ldr r0, [r4]
	cmp r0, 0
	beq _081C7988
	ldrh r0, [r4, 0x4]
	bl AllocObjectPalette
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	bne _081C7962
_081C7988:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C795C

	thumb_func_start sub_81C7990
sub_81C7990: @ 81C7990
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	strh r1, [r0]
	lsls r3, 5
	ldr r0, =gPlttBufferFaded + 0x200
	adds r3, r0
	ldr r2, =0x01000010
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7990

	thumb_func_start sub_81C79BC
sub_81C79BC: @ 81C79BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r10, r2
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x2C]
	cmp r0, 0
	bne _081C79E4
	ldr r2, =0x001fffff
	mov r1, r10
	ands r2, r1
	ldr r0, [sp]
	b _081C79F4
	.pool
_081C79E4:
	ldr r2, [sp, 0x2C]
	ldr r0, [sp, 0x8]
	cmp r2, r0
	blt _081C7A00
	ldr r2, =0x001fffff
	mov r1, r10
	ands r2, r1
	ldr r0, [sp, 0x4]
_081C79F4:
	ldr r1, [sp, 0x30]
	bl CpuSet
	b _081C7AAE
	.pool
_081C7A00:
	movs r2, 0x1
	negs r2, r2
	add r10, r2
	b _081C7AA6
_081C7A08:
	ldr r1, [sp]
	ldrh r0, [r1]
	movs r2, 0x1F
	mov r9, r2
	mov r1, r9
	ands r1, r0
	mov r9, r1
	lsls r0, 16
	lsrs r2, r0, 21
	movs r1, 0x1F
	ands r1, r2
	mov r8, r1
	lsrs r7, r0, 26
	movs r2, 0x1F
	ands r7, r2
	ldr r0, [sp, 0x4]
	ldrh r4, [r0]
	movs r0, 0x1F
	ands r0, r4
	mov r1, r9
	subs r0, r1
	lsls r0, 8
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r2, [sp, 0x2C]
	adds r6, r0, 0
	muls r6, r2
	asrs r6, 8
	lsls r4, 16
	lsrs r0, r4, 21
	movs r1, 0x1F
	ands r0, r1
	mov r2, r8
	subs r0, r2
	lsls r0, 8
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r1, [sp, 0x2C]
	adds r5, r0, 0
	muls r5, r1
	asrs r5, 8
	lsrs r4, 26
	movs r2, 0x1F
	ands r4, r2
	subs r4, r7
	lsls r4, 8
	adds r0, r4, 0
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r1, [sp, 0x2C]
	muls r0, r1
	asrs r0, 8
	add r6, r9
	movs r2, 0x1F
	ands r6, r2
	add r5, r8
	ands r5, r2
	adds r0, r7, r0
	ands r0, r2
	lsls r0, 10
	lsls r5, 5
	orrs r0, r5
	orrs r0, r6
	ldr r1, [sp, 0x30]
	strh r0, [r1]
	ldr r2, [sp]
	adds r2, 0x2
	str r2, [sp]
	ldr r0, [sp, 0x4]
	adds r0, 0x2
	str r0, [sp, 0x4]
	adds r1, 0x2
	str r1, [sp, 0x30]
	movs r1, 0x1
	negs r1, r1
	add r10, r1
_081C7AA6:
	movs r0, 0x1
	negs r0, r0
	cmp r10, r0
	bne _081C7A08
_081C7AAE:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C79BC

	thumb_func_start sub_81C7AC0
sub_81C7AC0: @ 81C7AC0
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0x1
	beq _081C7AF0
	cmp r4, 0x1
	bgt _081C7ADA
	cmp r4, 0
	beq _081C7AE4
	b _081C7B2C
_081C7ADA:
	cmp r4, 0x2
	beq _081C7B04
	cmp r4, 0x3
	beq _081C7B18
	b _081C7B2C
_081C7AE4:
	ldr r0, [r0, 0x14]
	movs r1, 0x2
	negs r1, r1
	str r4, [sp]
	movs r2, 0
	b _081C7B10
_081C7AF0:
	ldr r0, [r0, 0x14]
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _081C7B2C
_081C7B04:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
_081C7B10:
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _081C7B2C
_081C7B18:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_081C7B2C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7AC0

	thumb_func_start sub_81C7B34
sub_81C7B34: @ 81C7B34
	ldr r0, =gPaletteFade
	ldrb r0, [r0, 0x7]
	lsrs r0, 7
	bx lr
	.pool
	thumb_func_end sub_81C7B34

	thumb_func_start sub_81C7B40
sub_81C7B40: @ 81C7B40
	push {lr}
	ldr r0, =0xfffefffe
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7B40

	thumb_func_start sub_81C7B54
sub_81C7B54: @ 81C7B54
	push {r4,r5,lr}
	adds r5, r0, 0
	cmp r1, 0
	ble _081C7B6C
	adds r4, r1, 0
_081C7B5E:
	adds r0, r5, 0
	adds r5, 0x4
	bl InitBgFromTemplate
	subs r4, 0x1
	cmp r4, 0
	bne _081C7B5E
_081C7B6C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7B54

	thumb_func_start sub_81C7B74
sub_81C7B74: @ 81C7B74
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =gUnknown_0861FA08
	bl InitWindows
	movs r0, 0
	str r0, [r4, 0x10]
	bl sub_81C7BF8
	ldrb r0, [r4, 0x10]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x10]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7B74

	thumb_func_start sub_81C7BA4
sub_81C7BA4: @ 81C7BA4
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, [r5, 0x10]
	bl sub_81C7BF8
	ldrb r0, [r5, 0x10]
	ldr r1, =gUnknown_0861FA48
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_0861FA18
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7BA4

	thumb_func_start sub_81C7BE8
sub_81C7BE8: @ 81C7BE8
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81C7BE8

	thumb_func_start sub_81C7BF8
sub_81C7BF8: @ 81C7BF8
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x44
	bl FillWindowPixelBuffer
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x55
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7BF8

	thumb_func_start sub_81C7C28
sub_81C7C28: @ 81C7C28
	push {r4-r6,lr}
	movs r0, 0
	bl sub_81C763C
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_0861FA4C
_081C7C36:
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081C7C36
	ldr r0, =gUnknown_0861FA54
	bl sub_81C795C
	movs r0, 0
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r0
	movs r0, 0x2
	negs r0, r0
	bics r0, r1
	str r0, [r6, 0x14]
	ldr r0, =gUnknown_0861FB04
	movs r1, 0xDC
	movs r2, 0xC
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r6, 0x18]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7C28

	thumb_func_start sub_81C7C94
sub_81C7C94: @ 81C7C94
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	bl DestroySprite
	movs r0, 0
	bl FreeObjectTilesByTag
	movs r0, 0
	bl FreeObjectPaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_81C7C94

	thumb_func_start sub_81C7CB4
sub_81C7CB4: @ 81C7CB4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	bl GetBgY
	lsrs r0, 8
	negs r0, r0
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7CB4

	thumb_func_start sub_81C7CCC
sub_81C7CCC: @ 81C7CCC
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	ldr r1, =SpriteCallbackDummy
	str r1, [r0, 0x1C]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7CCC

	thumb_func_start sub_81C7CE4
sub_81C7CE4: @ 81C7CE4
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	ldr r2, [r0, 0x18]
	movs r4, 0
	movs r1, 0xDC
	strh r1, [r2, 0x20]
	ldr r2, [r0, 0x18]
	movs r1, 0xC
	strh r1, [r2, 0x22]
	ldr r2, [r0, 0x18]
	ldr r1, =sub_81C7CB4
	str r1, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	strb r1, [r2]
	ldr r3, [r0, 0x18]
	ldrb r2, [r3, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	strb r1, [r3, 0x5]
	ldr r0, [r0, 0x18]
	adds r0, 0x43
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7CE4

	thumb_func_start sub_81C7D28
sub_81C7D28: @ 81C7D28
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	bl sub_81C763C
	adds r6, r0, 0
	ldr r0, =gUnknown_0861FA64
	bl LoadCompressedObjectPic
	movs r0, 0x1
	bl AllocObjectPalette
	movs r0, 0x2
	bl AllocObjectPalette
	movs r5, 0
	ldr r0, =gSprites
	mov r8, r0
	movs r7, 0x4
_081C7D50:
	ldr r0, =gUnknown_0861FB2C
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r4, r5, 2
	adds r2, r6, 0
	adds r2, 0x1C
	adds r2, r4
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r0, [r2]
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	ldr r1, [r2]
	lsls r0, r5, 6
	strh r0, [r1, 0x24]
	ldr r0, =gUnknown_0861FB44
	movs r1, 0
	movs r2, 0
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r6, 0
	adds r2, 0x24
	adds r2, r4
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r0, [r2]
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	ldr r1, [r2]
	lsls r0, r5, 5
	strh r0, [r1, 0x24]
	ldr r1, [r2]
	movs r0, 0x12
	strh r0, [r1, 0x26]
	ldr r3, [r2]
	ldrh r2, [r3, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	lsls r0, r5, 3
	adds r0, 0x40
	adds r1, r0
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x4]
	adds r5, 0x1
	cmp r5, 0x1
	ble _081C7D50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7D28

	thumb_func_start sub_81C7DFC
sub_81C7DFC: @ 81C7DFC
	push {lr}
	cmp r0, 0x5
	bhi _081C7E08
	bl sub_81C7E58
	b _081C7E0E
_081C7E08:
	subs r0, 0x6
	bl sub_81C7F24
_081C7E0E:
	pop {r0}
	bx r0
	thumb_func_end sub_81C7DFC

	thumb_func_start sub_81C7E14
sub_81C7E14: @ 81C7E14
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x4
	bne _081C7E30
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	ldr r3, [r5, 0x20]
	adds r0, 0x20
	b _081C7E3A
_081C7E30:
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	ldr r3, [r5, 0x20]
	adds r0, 0x40
_081C7E3A:
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r2, [r3, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7E14

	thumb_func_start sub_81C7E58
sub_81C7E58: @ 81C7E58
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	cmp r0, 0x5
	bhi _081C7F16
	movs r0, 0
	bl sub_81C763C
	adds r7, r0, 0
	ldr r0, =gUnknown_0861FA6C
	mov r1, r9
	lsls r6, r1, 3
	adds r6, r0
	ldrh r4, [r6, 0x6]
	ldr r2, [r6]
	mov r8, r2
	mov r0, r8
	bl sub_8034974
	adds r5, r0, 0
	lsls r4, 5
	ldr r0, =gUnknown_08DC7F00
	adds r4, r0
	movs r0, 0x1
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r4, =0x0201c000
	mov r0, r8
	adds r1, r4, 0
	bl LZ77UnCompWram
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 11
	ldr r2, =0x06010000
	adds r1, r2
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl RequestDma3Copy
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	ldr r3, [r7, 0x20]
	ldrh r1, [r6, 0x4]
	adds r0, r1
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r2, [r3, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
	mov r0, r9
	subs r0, 0x4
	cmp r0, 0x1
	bhi _081C7F10
	ldr r1, [r7, 0x20]
	movs r0, 0x38
	b _081C7F14
	.pool
_081C7F10:
	ldr r1, [r7, 0x20]
	movs r0, 0x40
_081C7F14:
	strh r0, [r1, 0x24]
_081C7F16:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7E58

	thumb_func_start sub_81C7F24
sub_81C7F24: @ 81C7F24
	push {r4-r6,lr}
	cmp r0, 0x6
	bhi _081C7F8A
	ldr r2, =gUnknown_0861FA9C
	lsls r1, r0, 3
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldr r4, [r0]
	adds r1, r2
	ldr r6, [r1]
	adds r0, r6, 0
	bl sub_8034974
	adds r5, r0, 0
	lsls r4, 5
	ldr r0, =gUnknown_08DC7F00
	adds r4, r0
	movs r0, 0x2
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r4, =0x0201d000
	adds r0, r6, 0
	adds r1, r4, 0
	bl LZ77UnCompWram
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 11
	ldr r0, =0x06010800
	adds r1, r0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl RequestDma3Copy
_081C7F8A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7F24

	thumb_func_start sub_81C7FA0
sub_81C7FA0: @ 81C7FA0
	push {lr}
	adds r3, r0, 0
	movs r0, 0x10
	cmp r1, 0
	bne _081C7FAC
	movs r0, 0x30
_081C7FAC:
	cmp r3, 0x5
	bhi _081C7FB8
	adds r1, r2, 0
	bl sub_81C803C
	b _081C7FBE
_081C7FB8:
	adds r1, r2, 0
	bl sub_81C8088
_081C7FBE:
	pop {r0}
	bx r0
	thumb_func_end sub_81C7FA0

	thumb_func_start sub_81C7FC4
sub_81C7FC4: @ 81C7FC4
	push {lr}
	cmp r0, 0x5
	bhi _081C7FD2
	adds r0, r1, 0
	bl sub_81C80D4
	b _081C7FD8
_081C7FD2:
	adds r0, r1, 0
	bl sub_81C8110
_081C7FD8:
	pop {r0}
	bx r0
	thumb_func_end sub_81C7FC4

	thumb_func_start sub_81C7FDC
sub_81C7FDC: @ 81C7FDC
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	movs r4, 0x4
	adds r2, r0, 0
	adds r2, 0x1C
	movs r3, 0x1
_081C7FEC:
	ldr r1, [r2]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	ldr r1, [r2, 0x8]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _081C7FEC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7FDC

	thumb_func_start sub_81C8010
sub_81C8010: @ 81C8010
	push {lr}
	movs r0, 0
	bl sub_81C763C
	adds r1, r0, 0
	ldr r0, [r1, 0x1C]
	ldr r2, [r0, 0x1C]
	ldr r0, =SpriteCallbackDummy
	cmp r2, r0
	bne _081C8034
	ldr r0, [r1, 0x24]
	ldr r0, [r0, 0x1C]
	cmp r0, r2
	bne _081C8034
	movs r0, 0
	b _081C8036
	.pool
_081C8034:
	movs r0, 0x1
_081C8036:
	pop {r1}
	bx r1
	thumb_func_end sub_81C8010

	thumb_func_start sub_81C803C
sub_81C803C: @ 81C803C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C8058
	movs r7, 0x60
	negs r7, r7
	movs r6, 0x20
	b _081C805E
_081C8058:
	movs r7, 0x80
	lsls r7, 1
	movs r6, 0xA0
_081C805E:
	adds r4, r0, 0
	adds r4, 0x1C
	movs r5, 0x1
_081C8064:
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x22]
	ldm r4!, {r0}
	adds r1, r7, 0
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r5, 0x1
	cmp r5, 0
	bge _081C8064
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C803C

	thumb_func_start sub_81C8088
sub_81C8088: @ 81C8088
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C80A4
	movs r7, 0x60
	negs r7, r7
	movs r6, 0x10
	b _081C80AA
_081C80A4:
	movs r7, 0x80
	lsls r7, 1
	movs r6, 0xC0
_081C80AA:
	adds r4, r0, 0
	adds r4, 0x24
	movs r5, 0x1
_081C80B0:
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x22]
	ldm r4!, {r0}
	adds r1, r7, 0
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r5, 0x1
	cmp r5, 0
	bge _081C80B0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8088

	thumb_func_start sub_81C80D4
sub_81C80D4: @ 81C80D4
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C80EA
	movs r6, 0x20
	movs r5, 0x60
	negs r5, r5
	b _081C80F0
_081C80EA:
	movs r6, 0xC0
	movs r5, 0x80
	lsls r5, 1
_081C80F0:
	adds r7, r0, 0
	adds r7, 0x1C
	movs r4, 0x1
_081C80F6:
	ldm r7!, {r0}
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r4, 0x1
	cmp r4, 0
	bge _081C80F6
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C80D4

	thumb_func_start sub_81C8110
sub_81C8110: @ 81C8110
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C8126
	movs r6, 0x10
	movs r5, 0x60
	negs r5, r5
	b _081C812C
_081C8126:
	movs r6, 0xC0
	movs r5, 0x80
	lsls r5, 1
_081C812C:
	adds r7, r0, 0
	adds r7, 0x24
	movs r4, 0x1
_081C8132:
	ldm r7!, {r0}
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r4, 0x1
	cmp r4, 0
	bge _081C8132
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8110

	thumb_func_start sub_81C814C
sub_81C814C: @ 81C814C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	strh r0, [r4, 0x20]
	lsls r1, r0, 4
	strh r1, [r4, 0x2E]
	subs r0, r6, r0
	lsls r0, 4
	adds r1, r5, 0
	bl __divsi3
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	strh r6, [r4, 0x3C]
	ldr r0, =sub_81C817C
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C814C

	thumb_func_start sub_81C817C
sub_81C817C: @ 81C817C
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x32]
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081C81C4
	subs r0, r1, 0x1
	strh r0, [r2, 0x32]
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x2E]
	adds r0, r1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	adds r0, 0x10
	lsls r0, 16
	movs r1, 0x88
	lsls r1, 17
	cmp r0, r1
	bls _081C81B6
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _081C81CC
_081C81B6:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _081C81CC
_081C81C4:
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081C81CC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C817C

	thumb_func_start sub_81C81D4
sub_81C81D4: @ 81C81D4
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	ldr r1, =0x000008a4
	movs r0, 0x11
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C821C
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r5, 0
	bl sub_81C9160
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_81C91AC
	cmp r0, 0
	beq _081C821C
	ldr r0, =sub_81C8254
	movs r1, 0x6
	bl sub_81C7078
	movs r0, 0x1
	b _081C821E
	.pool
_081C821C:
	movs r0, 0
_081C821E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C81D4

	thumb_func_start sub_81C8224
sub_81C8224: @ 81C8224
	push {lr}
	ldr r0, =sub_81C8254
	bl sub_81C7124
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8224

	thumb_func_start sub_81C8234
sub_81C8234: @ 81C8234
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C8FE0
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x11
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8234

	thumb_func_start sub_81C8254
sub_81C8254: @ 81C8254
	push {r4,lr}
	adds r4, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C82C0
	movs r0, 0x11
	bl sub_81C763C
	adds r2, r0, 0
	cmp r4, 0x4
	bhi _081C82D6
	lsls r0, r4, 2
	ldr r1, =_081C827C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C827C:
	.4byte _081C8290
	.4byte _081C829A
	.4byte _081C82A4
	.4byte _081C82B8
	.4byte _081C82CC
_081C8290:
	adds r0, r2, 0
	bl sub_81C82E4
	movs r0, 0
	b _081C82D8
_081C829A:
	adds r0, r2, 0
	bl sub_81C835C
	movs r0, 0
	b _081C82D8
_081C82A4:
	ldr r1, =0x00000888
	adds r0, r2, r1
	adds r1, r2, 0
	bl sub_81C837C
	movs r0, 0
	b _081C82D8
	.pool
_081C82B8:
	bl sub_81C83E0
	cmp r0, 0
	beq _081C82C4
_081C82C0:
	movs r0, 0x2
	b _081C82D8
_081C82C4:
	bl sub_81C8ED0
	movs r0, 0x1
	b _081C82D8
_081C82CC:
	ldr r1, =0x00000888
	adds r0, r2, r1
	adds r1, r2, 0
	bl sub_81C8EF8
_081C82D6:
	movs r0, 0x4
_081C82D8:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8254

	thumb_func_start sub_81C82E4
sub_81C82E4: @ 81C82E4
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldrb r4, [r5, 0x1]
	lsls r4, 12
	ldrh r0, [r5, 0x6]
	orrs r4, r0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	ldrh r2, [r5, 0x6]
	movs r1, 0x11
	movs r3, 0x1
	bl sub_8199DF0
	ldrb r0, [r5]
	ldrh r2, [r5, 0x6]
	adds r2, 0x1
	movs r1, 0x44
	movs r3, 0x1
	bl sub_8199DF0
	ldrb r0, [r5]
	adds r1, r5, 0
	adds r1, 0x88
	bl SetBgTilemapBuffer
	ldrb r0, [r5]
	movs r1, 0x20
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldrb r0, [r5]
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldrb r0, [r5]
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	ldrb r0, [r5]
	ldrb r1, [r5, 0x3]
	lsls r1, 11
	movs r2, 0x2
	bl ChangeBgY
	ldrb r0, [r5]
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C82E4

	thumb_func_start sub_81C835C
sub_81C835C: @ 81C835C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C835C

	thumb_func_start sub_81C837C
sub_81C837C: @ 81C837C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r5, r1, 0
	ldrh r0, [r3, 0x2]
	ldrh r4, [r3]
	subs r2, r0, r4
	ldrh r0, [r3, 0x8]
	cmp r2, r0
	ble _081C8392
	adds r2, r0, 0
_081C8392:
	ldr r0, [r3, 0x10]
	ldr r3, [r3, 0xC]
	movs r1, 0
	str r1, [sp]
	str r5, [sp, 0x4]
	adds r1, r4, 0
	bl sub_81C83AC
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C837C

	thumb_func_start sub_81C83AC
sub_81C83AC: @ 81C83AC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [sp, 0x10]
	cmp r2, 0
	beq _081C83D6
	adds r0, r5, 0
	muls r0, r3
	adds r0, r4, r0
	str r0, [r1, 0x1C]
	str r3, [r1, 0x18]
	movs r0, 0
	strh r0, [r1, 0xC]
	strh r2, [r1, 0xE]
	str r5, [r1, 0x14]
	ldr r0, [sp, 0xC]
	str r0, [r1, 0x10]
	ldr r0, =sub_81C83F0
	movs r1, 0x5
	bl sub_81C7078
_081C83D6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C83AC

	thumb_func_start sub_81C83E0
sub_81C83E0: @ 81C83E0
	push {lr}
	ldr r0, =sub_81C83F0
	bl sub_81C7124
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C83E0

	thumb_func_start sub_81C83F0
sub_81C83F0: @ 81C83F0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r6, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	cmp r6, 0
	beq _081C8408
	cmp r6, 0x1
	beq _081C848C
	b _081C849A
_081C8408:
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	ldr r1, [r4, 0x10]
	adds r5, r0, r1
	movs r0, 0xF
	ands r5, r0
	ldr r0, [r4, 0x1C]
	adds r7, r4, 0
	adds r7, 0x48
	ldr r2, [r4, 0x34]
	adds r1, r7, 0
	bl _call_via_r2
	ldr r3, [r4, 0x38]
	cmp r3, 0
	beq _081C8434
	ldrh r0, [r4, 0x8]
	ldr r1, [r4, 0x14]
	adds r2, r5, 0
	bl _call_via_r3
_081C8434:
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x5]
	lsls r2, r5, 4
	movs r3, 0x1
	orrs r2, r3
	str r2, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r2, r7, 0
	movs r3, 0x8
	bl Print
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0xE]
	cmp r0, r1
	bcc _081C847A
	ldr r0, [r4, 0x38]
	cmp r0, 0
	beq _081C846E
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081C8476
_081C846E:
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
_081C8476:
	movs r0, 0
	b _081C849C
_081C847A:
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r4, 0x1C]
	ldr r0, [r4, 0x14]
	adds r0, 0x1
	str r0, [r4, 0x14]
	movs r0, 0x3
	b _081C849C
_081C848C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C849A
	movs r0, 0x2
	b _081C849C
_081C849A:
	movs r0, 0x4
_081C849C:
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C83F0

	thumb_func_start sub_81C84A4
sub_81C84A4: @ 81C84A4
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x00000888
	adds r0, r1
	ldrh r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C84A4

	thumb_func_start sub_81C84C0
sub_81C84C0: @ 81C84C0
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x00000888
	adds r0, r1
	movs r3, 0
	ldrh r1, [r0]
	ldrh r2, [r0, 0x8]
	adds r1, r2
	ldrh r0, [r0, 0x2]
	cmp r1, r0
	bge _081C84DC
	movs r3, 0x1
_081C84DC:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C84C0

	thumb_func_start sub_81C84E8
sub_81C84E8: @ 81C84E8
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r4, r1, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r7, r0, 0
	ldr r0, =0x00000888
	adds r5, r7, r0
	cmp r6, 0
	bge _081C8524
	ldrh r1, [r5]
	adds r0, r1, r6
	cmp r0, 0
	bge _081C850A
	negs r6, r1
_081C850A:
	cmp r4, 0
	beq _081C854E
	ldr r0, [r5, 0x10]
	adds r1, r6
	negs r2, r6
	ldr r3, [r5, 0xC]
	str r6, [sp]
	str r7, [sp, 0x4]
	bl sub_81C83AC
	b _081C854E
	.pool
_081C8524:
	cmp r4, 0
	beq _081C854E
	ldr r2, =gUnknown_0203CF44
	ldrh r1, [r5]
	ldrh r0, [r5, 0x8]
	adds r4, r1, r0
	str r4, [r2]
	adds r0, r4, r6
	ldrh r1, [r5, 0x2]
	cmp r0, r1
	blt _081C853C
	subs r6, r1, r4
_081C853C:
	ldr r0, [r5, 0x10]
	ldr r3, [r5, 0xC]
	ldrh r1, [r5, 0x8]
	str r1, [sp]
	str r7, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_81C83AC
_081C854E:
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_81C8568
	ldrh r0, [r5]
	adds r0, r6
	strh r0, [r5]
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C84E8

	thumb_func_start sub_81C8568
sub_81C8568: @ 81C8568
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r4]
	bl GetBgY
	str r0, [r4, 0x20]
	lsls r1, r5, 12
	adds r0, r1
	str r0, [r4, 0x24]
	cmp r5, 0
	ble _081C8584
	movs r0, 0x1
	b _081C8586
_081C8584:
	movs r0, 0x2
_081C8586:
	str r0, [r4, 0x30]
	str r5, [r4, 0x2C]
	ldr r0, =sub_81C85A0
	movs r1, 0x6
	bl sub_81C7078
	str r0, [r4, 0x28]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8568

	thumb_func_start sub_81C85A0
sub_81C85A0: @ 81C85A0
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0
	beq _081C85B8
	cmp r5, 0x1
	beq _081C85C4
	movs r0, 0x4
	b _081C862A
_081C85B8:
	bl sub_81C83E0
	cmp r0, 0
	bne _081C8628
	movs r0, 0x1
	b _081C862A
_081C85C4:
	movs r6, 0
	ldrb r0, [r4]
	bl GetBgY
	adds r5, r0, 0
	ldrb r0, [r4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r4, 0x30]
	lsls r2, 24
	lsrs r2, 24
	bl ChangeBgY
	adds r1, r0, 0
	ldr r0, [r4, 0x30]
	cmp r0, 0x2
	bne _081C85F8
	ldr r2, [r4, 0x24]
	cmp r5, r2
	bgt _081C85F2
	ldr r0, [r4, 0x20]
	cmp r5, r0
	bgt _081C860A
_081C85F2:
	cmp r1, r2
	bgt _081C860A
	b _081C860E
_081C85F8:
	ldr r2, [r4, 0x24]
	cmp r5, r2
	blt _081C8604
	ldr r0, [r4, 0x20]
	cmp r5, r0
	blt _081C860A
_081C8604:
	cmp r1, r2
	blt _081C860A
	movs r6, 0x1
_081C860A:
	cmp r6, 0
	beq _081C8628
_081C860E:
	ldr r1, [r4, 0x2C]
	ldrh r0, [r4, 0xA]
	adds r0, r1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrb r0, [r4]
	adds r1, r2, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x4
	b _081C862A
_081C8628:
	movs r0, 0x2
_081C862A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C85A0

	thumb_func_start sub_81C8630
sub_81C8630: @ 81C8630
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r0, [r0, 0x28]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C8630

	thumb_func_start sub_81C8644
sub_81C8644: @ 81C8644
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x00000888
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8644

	thumb_func_start sub_81C8658
sub_81C8658: @ 81C8658
	push {lr}
	bl sub_81C8644
	adds r1, r0, 0
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	beq _081C866E
	subs r0, 0x1
	strh r0, [r1, 0x6]
	movs r0, 0x1
	b _081C8686
_081C866E:
	bl sub_81C84A4
	cmp r0, 0
	bne _081C867A
	movs r0, 0
	b _081C8686
_081C867A:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
_081C8686:
	pop {r1}
	bx r1
	thumb_func_end sub_81C8658

	thumb_func_start sub_81C868C
sub_81C868C: @ 81C868C
	push {lr}
	bl sub_81C8644
	adds r2, r0, 0
	ldrh r1, [r2]
	ldrh r3, [r2, 0x6]
	adds r1, r3
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r1, r0
	bge _081C86BA
	ldrh r0, [r2, 0x8]
	subs r0, 0x1
	cmp r3, r0
	bge _081C86B2
	adds r0, r3, 0x1
	strh r0, [r2, 0x6]
	movs r0, 0x1
	b _081C86C8
_081C86B2:
	bl sub_81C84C0
	cmp r0, 0
	bne _081C86BE
_081C86BA:
	movs r0, 0
	b _081C86C8
_081C86BE:
	movs r0, 0x1
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
_081C86C8:
	pop {r1}
	bx r1
	thumb_func_end sub_81C868C

	thumb_func_start sub_81C86CC
sub_81C86CC: @ 81C86CC
	push {r4,lr}
	bl sub_81C8644
	adds r4, r0, 0
	bl sub_81C84A4
	adds r1, r0, 0
	cmp r1, 0
	beq _081C86F8
	ldrh r0, [r4]
	ldrh r1, [r4, 0x8]
	cmp r0, r1
	bcc _081C86EA
	ldrh r0, [r4, 0x8]
	b _081C86EC
_081C86EA:
	ldrh r0, [r4]
_081C86EC:
	negs r0, r0
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
	b _081C8706
_081C86F8:
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	bne _081C8702
	movs r0, 0
	b _081C8706
_081C8702:
	strh r1, [r4, 0x6]
	movs r0, 0x1
_081C8706:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C86CC

	thumb_func_start sub_81C870C
sub_81C870C: @ 81C870C
	push {r4,lr}
	bl sub_81C8644
	adds r4, r0, 0
	bl sub_81C84C0
	cmp r0, 0
	beq _081C8736
	ldrh r0, [r4]
	ldrh r3, [r4, 0x8]
	adds r2, r0, r3
	ldrh r1, [r4, 0x4]
	subs r0, r1, r0
	cmp r2, r1
	bgt _081C872C
	adds r0, r3, 0
_081C872C:
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
	b _081C8756
_081C8736:
	ldrh r0, [r4, 0x2]
	ldrh r1, [r4, 0x8]
	cmp r0, r1
	bcc _081C8744
	ldrh r1, [r4, 0x6]
	ldrh r0, [r4, 0x8]
	b _081C8748
_081C8744:
	ldrh r1, [r4, 0x6]
	ldrh r0, [r4, 0x2]
_081C8748:
	subs r0, 0x1
	cmp r1, r0
	bge _081C8754
	strh r0, [r4, 0x6]
	movs r0, 0x1
	b _081C8756
_081C8754:
	movs r0, 0
_081C8756:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C870C

	thumb_func_start sub_81C875C
sub_81C875C: @ 81C875C
	push {lr}
	bl sub_81C8644
	adds r1, r0, 0
	ldrh r0, [r1]
	ldrh r1, [r1, 0x6]
	adds r0, r1
	pop {r1}
	bx r1
	thumb_func_end sub_81C875C

	thumb_func_start sub_81C8770
sub_81C8770: @ 81C8770
	push {lr}
	bl sub_81C8644
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81C8770

	thumb_func_start sub_81C877C
sub_81C877C: @ 81C877C
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x0000089c
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	ldr r0, =sub_81C8870
	movs r1, 0x6
	bl sub_81C7078
	movs r1, 0x8A
	lsls r1, 4
	adds r4, r1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C877C

	thumb_func_start sub_81C87AC
sub_81C87AC: @ 81C87AC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x11
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =0x00000888
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r4
	movs r2, 0
	strh r0, [r1]
	ldr r1, =0x0000089c
	adds r0, r5, r1
	str r2, [r0]
	ldr r0, =sub_81C8958
	movs r1, 0x6
	bl sub_81C7078
	movs r1, 0x8A
	lsls r1, 4
	adds r5, r1
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C87AC

	thumb_func_start sub_81C87F0
sub_81C87F0: @ 81C87F0
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x0000089c
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	ldr r0, =sub_81C8A28
	movs r1, 0x6
	bl sub_81C7078
	movs r1, 0x8A
	lsls r1, 4
	adds r4, r1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C87F0

	thumb_func_start sub_81C8820
sub_81C8820: @ 81C8820
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	movs r1, 0x8A
	lsls r1, 4
	adds r0, r1
	ldr r0, [r0]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C8820

	thumb_func_start sub_81C8838
sub_81C8838: @ 81C8838
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x00000888
	adds r2, r4, r0
	ldrh r0, [r4, 0x8]
	ldrh r1, [r2]
	ldrh r3, [r2, 0x6]
	adds r1, r3
	ldrh r2, [r4, 0xA]
	adds r2, r3
	movs r3, 0xF
	ands r2, r3
	ldr r3, [r4, 0x38]
	bl _call_via_r3
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8838

	thumb_func_start sub_81C8870
sub_81C8870: @ 81C8870
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x4
	bhi _081C894C
	lsls r0, r5, 2
	ldr r1, =_081C8890
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C8890:
	.4byte _081C88A4
	.4byte _081C88AC
	.4byte _081C88D8
	.4byte _081C8918
	.4byte _081C8938
_081C88A4:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C9008
_081C88AC:
	ldr r0, =0x0000089c
	adds r5, r4, r0
	ldr r1, =0x0000088e
	adds r0, r4, r1
	ldr r1, [r5]
	ldrh r0, [r0]
	cmp r1, r0
	beq _081C88C4
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_81C8B70
_081C88C4:
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
_081C88CA:
	movs r0, 0
	b _081C894E
	.pool
_081C88D8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C8942
	ldr r2, =0x0000089c
	adds r0, r4, r2
	subs r2, 0xC
	adds r1, r4, r2
	ldr r3, [r0]
	ldrh r1, [r1]
	cmp r3, r1
	beq _081C88FC
	movs r0, 0x6
	b _081C894E
	.pool
_081C88FC:
	ldr r0, =0x0000088e
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C88CA
	adds r2, r0, 0
	adds r0, r4, 0
	adds r1, r3, 0
	bl sub_81C8B70
	b _081C88CA
	.pool
_081C8918:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C8942
	ldr r2, =0x0000088e
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C894C
	movs r1, 0
	bl sub_81C84E8
	b _081C88CA
	.pool
_081C8938:
	bl sub_81C8630
	adds r1, r0, 0
	cmp r1, 0
	beq _081C8946
_081C8942:
	movs r0, 0x2
	b _081C894E
_081C8946:
	ldr r2, =0x0000088e
	adds r0, r4, r2
	strh r1, [r0]
_081C894C:
	movs r0, 0x4
_081C894E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8870

	thumb_func_start sub_81C8958
sub_81C8958: @ 81C8958
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C8972
	movs r0, 0x2
	b _081C8A22
_081C8972:
	cmp r5, 0x7
	bhi _081C8A1C
	lsls r0, r5, 2
	ldr r1, =_081C8984
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C8984:
	.4byte _081C89A4
	.4byte _081C89B4
	.4byte _081C89BE
	.4byte _081C89D0
	.4byte _081C89DA
	.4byte _081C89EC
	.4byte _081C89F6
	.4byte _081C8A08
_081C89A4:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	bl sub_81C8CB4
	b _081C8A20
	.pool
_081C89B4:
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C8DBC
	b _081C8A20
_081C89BE:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C89D0:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C8DBC
	b _081C8A20
_081C89DA:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C89EC:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_81C8DBC
	b _081C8A20
_081C89F6:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C8A08:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0x3
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C8A1C:
	movs r0, 0x4
	b _081C8A22
_081C8A20:
	movs r0, 0
_081C8A22:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C8958

	thumb_func_start sub_81C8A28
sub_81C8A28: @ 81C8A28
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C8AA6
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x00000888
	adds r6, r4, r0
	adds r2, r4, 0
	cmp r5, 0x6
	bls _081C8A4C
	b _081C8B64
_081C8A4C:
	lsls r0, r5, 2
	ldr r1, =_081C8A60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C8A60:
	.4byte _081C8A7C
	.4byte _081C8A88
	.4byte _081C8AE8
	.4byte _081C8AFC
	.4byte _081C8B14
	.4byte _081C8B34
	.4byte _081C8B5C
_081C8A7C:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_81C8D4C
	movs r0, 0
	b _081C8B66
_081C8A88:
	ldr r1, =0x0000089c
	adds r7, r4, r1
	ldr r0, [r7]
	adds r1, r0, 0x1
	str r1, [r7]
	movs r3, 0x89
	lsls r3, 4
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _081C8AB0
	adds r0, r2, 0
	movs r2, 0x1
	bl sub_81C8B70
_081C8AA6:
	movs r0, 0x2
	b _081C8B66
	.pool
_081C8AB0:
	movs r0, 0
	str r0, [r7]
	ldrh r0, [r6, 0x2]
	ldrh r1, [r6, 0x8]
	cmp r0, r1
	bhi _081C8AC6
	ldrh r0, [r6]
	cmp r0, 0
	beq _081C8B52
	adds r4, r0, 0
	b _081C8AD4
_081C8AC6:
	ldrh r1, [r6]
	ldrh r0, [r6, 0x8]
	adds r4, r1, r0
	ldrh r1, [r6, 0x2]
	cmp r4, r1
	ble _081C8B52
	subs r4, r1
_081C8AD4:
	negs r5, r4
	adds r0, r2, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_81C8B70
	strh r4, [r6, 0x6]
	str r5, [r7]
	movs r0, 0
	b _081C8B66
_081C8AE8:
	ldr r2, =0x0000089c
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, 0
	bl sub_81C84E8
	movs r0, 0
	b _081C8B66
	.pool
_081C8AFC:
	bl sub_81C8630
	adds r1, r0, 0
	cmp r1, 0
	bne _081C8AA6
	ldr r3, =0x0000089c
	adds r0, r4, r3
	str r1, [r0]
_081C8B0C:
	movs r0, 0x1
	b _081C8B66
	.pool
_081C8B14:
	ldr r0, [r6, 0x10]
	ldrh r1, [r6]
	ldr r3, =0x0000089c
	adds r2, r4, r3
	ldr r2, [r2]
	adds r1, r2
	ldr r3, [r6, 0xC]
	str r2, [sp]
	str r4, [sp, 0x4]
	movs r2, 0x1
	bl sub_81C83AC
	movs r0, 0
	b _081C8B66
	.pool
_081C8B34:
	bl sub_81C83E0
	cmp r0, 0
	bne _081C8AA6
	ldr r0, =0x0000089c
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldrh r1, [r6, 0x2]
	cmp r0, r1
	bge _081C8B0C
	ldrh r6, [r6, 0x8]
	cmp r0, r6
	bge _081C8B0C
_081C8B52:
	movs r0, 0x9
	b _081C8B66
	.pool
_081C8B5C:
	adds r0, r2, 0
	movs r1, 0
	bl sub_81C9008
_081C8B64:
	movs r0, 0x4
_081C8B66:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C8A28

	thumb_func_start sub_81C8B70
sub_81C8B70: @ 81C8B70
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r0
	adds r7, r1, 0
	adds r6, r2, 0
	ldrb r0, [r0, 0x8]
	movs r1, 0x7
	bl GetWindowAttribute
	mov r10, r0
	mov r1, r9
	ldrb r0, [r1, 0x4]
	lsls r3, r0, 6
	ldrh r0, [r1, 0xA]
	adds r7, r0, r7
	movs r0, 0xF
	ands r7, r0
	adds r0, r7, r6
	cmp r0, 0x10
	bgt _081C8BD4
	ldr r0, =0x11111111
	str r0, [sp]
	adds r1, r7, 0
	muls r1, r3
	add r1, r10
	adds r2, r6, 0
	muls r2, r3
	lsrs r2, 2
	ldr r0, =0x001fffff
	ands r2, r0
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	bl CpuFastSet
	mov r1, r9
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	b _081C8C1E
	.pool
_081C8BD4:
	movs r2, 0x10
	subs r2, r7
	subs r0, r6, r2
	mov r8, r0
	ldr r1, =0x11111111
	str r1, [sp, 0x4]
	add r0, sp, 0x4
	adds r1, r7, 0
	muls r1, r3
	add r1, r10
	muls r2, r3
	lsrs r2, 2
	ldr r5, =0x001fffff
	ands r2, r5
	movs r4, 0x80
	lsls r4, 17
	orrs r2, r4
	str r3, [sp, 0xC]
	bl CpuFastSet
	ldr r0, =0x11111111
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	ldr r3, [sp, 0xC]
	mov r2, r8
	muls r2, r3
	lsrs r2, 2
	ands r2, r5
	orrs r2, r4
	mov r1, r10
	bl CpuFastSet
	mov r1, r9
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
_081C8C1E:
	subs r6, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _081C8C40
	movs r5, 0xF
	adds r4, r0, 0
_081C8C2C:
	mov r1, r9
	ldrh r0, [r1, 0x8]
	adds r1, r7, 0
	bl sub_81CBD48
	adds r7, 0x1
	ands r7, r5
	subs r6, 0x1
	cmp r6, r4
	bne _081C8C2C
_081C8C40:
	mov r1, r9
	ldrb r0, [r1, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8B70

	thumb_func_start sub_81C8C64
sub_81C8C64: @ 81C8C64
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	adds r2, r0, 0
	ldrh r0, [r5, 0xA]
	lsls r0, 6
	ldrb r1, [r5, 0x2]
	adds r0, r1
	lsls r0, 1
	subs r0, 0x2
	adds r2, r0
	cmp r4, 0
	beq _081C8C98
	ldrb r0, [r5, 0x1]
	lsls r0, 12
	ldrh r1, [r5, 0x6]
	adds r1, 0x1
	b _081C8C9E
_081C8C98:
	ldrb r0, [r5, 0x1]
	lsls r0, 12
	ldrh r1, [r5, 0x6]
_081C8C9E:
	orrs r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	strh r1, [r2]
	adds r0, r2, 0
	adds r0, 0x40
	strh r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8C64

	thumb_func_start sub_81C8CB4
sub_81C8CB4: @ 81C8CB4
	push {r4-r6,lr}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, =gUnknown_0861FBE4
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldrh r1, [r5]
	ldr r0, [r5, 0xC]
	muls r1, r0
	ldr r0, [r5, 0x10]
	adds r0, r1
	adds r6, r4, 0
	adds r6, 0x48
	ldr r2, [r4, 0x34]
	adds r1, r6, 0
	bl _call_via_r2
	ldrh r0, [r4, 0x8]
	ldrh r1, [r5]
	ldrh r2, [r4, 0xA]
	ldr r3, [r4, 0x38]
	bl _call_via_r3
	ldrb r0, [r4, 0x8]
	ldrh r3, [r4, 0xA]
	lsls r3, 20
	lsrs r3, 16
	ldrb r1, [r4, 0x4]
	lsls r1, 3
	str r1, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	movs r1, 0x44
	movs r2, 0
	bl FillWindowPixelRect
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x5]
	ldrh r3, [r4, 0xA]
	lsls r3, 4
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	add r2, sp, 0xC
	str r2, [sp]
	movs r2, 0x1
	negs r2, r2
	str r2, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r2, 0x8
	bl box_print
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C8C64
	ldrh r0, [r4, 0x8]
	ldrh r3, [r4, 0xA]
	lsls r3, 1
	ldrb r1, [r4, 0x4]
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r1, 0x3
	movs r2, 0
	bl CopyWindowRectToVram
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8CB4

	thumb_func_start sub_81C8D4C
sub_81C8D4C: @ 81C8D4C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	ldrh r2, [r0]
	ldr r1, [r0, 0xC]
	muls r1, r2
	ldr r0, [r0, 0x10]
	adds r0, r1
	adds r5, r4, 0
	adds r5, 0x48
	ldr r2, [r4, 0x34]
	adds r1, r5, 0
	bl _call_via_r2
	ldrb r0, [r4, 0x8]
	ldrh r3, [r4, 0xA]
	lsls r3, 20
	lsrs r3, 16
	ldrb r1, [r4, 0x4]
	lsls r1, 3
	str r1, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x5]
	ldrh r2, [r4, 0xA]
	lsls r2, 4
	adds r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	adds r2, r5, 0
	movs r3, 0x8
	bl Print
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C8C64
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8D4C

	thumb_func_start sub_81C8DBC
sub_81C8DBC: @ 81C8DBC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x1C
	adds r6, r0, 0
	mov r8, r1
	add r1, sp, 0xC
	ldr r0, =gUnknown_0861FBE8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r0, sp, 0x18
	mov r9, r0
	ldr r1, =gUnknown_0861FBF4
	movs r2, 0x3
	bl memcpy
	ldrh r4, [r6, 0xA]
	mov r1, r8
	lsls r0, r1, 1
	adds r0, 0x1
	adds r4, r0
	movs r0, 0xF
	ands r4, r0
	ldrb r0, [r6, 0x8]
	lsls r5, r4, 4
	adds r3, r5, 0
	ldrb r1, [r6, 0x4]
	str r1, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	ldrb r0, [r6, 0x8]
	movs r1, 0x1
	orrs r5, r1
	mov r2, r9
	str r2, [sp]
	subs r1, 0x2
	str r1, [sp, 0x4]
	mov r3, r8
	lsls r3, 2
	mov r8, r3
	mov r1, sp
	add r1, r8
	adds r1, 0xC
	ldr r1, [r1]
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r2, 0x2
	adds r3, r5, 0
	bl box_print
	ldrh r0, [r6, 0x8]
	lsls r4, 1
	ldrb r1, [r6, 0x4]
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r2, 0
	adds r3, r4, 0
	bl CopyWindowRectToVram
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8DBC

	thumb_func_start sub_81C8E54
sub_81C8E54: @ 81C8E54
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	adds r1, r2, 0
	ldrh r3, [r7, 0xA]
	ldr r2, =gUnknown_0861FBF7
	adds r2, r1, r2
	ldrb r2, [r2]
	adds r6, r3, r2
	movs r2, 0xF
	ands r6, r2
	ldrh r0, [r0]
	bl sub_81CAFD8
	adds r5, r0, 0
	cmp r5, 0
	beq _081C8EC0
	ldrh r0, [r7, 0x8]
	lsls r4, r6, 1
	ldrb r3, [r7, 0x4]
	subs r3, 0x1
	movs r1, 0x2
	mov r8, r1
	str r1, [sp]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_81DB620
	ldrb r0, [r7, 0x8]
	lsls r1, r6, 4
	movs r2, 0x1
	orrs r1, r2
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0x2
	bl Print
	ldrh r0, [r7, 0x8]
	ldrb r1, [r7, 0x4]
	str r1, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	movs r1, 0x2
	movs r2, 0
	adds r3, r4, 0
	bl CopyWindowRectToVram
_081C8EC0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8E54

	thumb_func_start sub_81C8ED0
sub_81C8ED0: @ 81C8ED0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_0861FBFC
_081C8ED6:
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081C8ED6
	ldr r0, =gUnknown_0861FC04
	bl sub_81C795C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8ED0

	thumb_func_start sub_81C8EF8
sub_81C8EF8: @ 81C8EF8
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_0861FC1C
	ldrb r1, [r5, 0x2]
	lsls r1, 3
	adds r1, 0x3
	ldrb r2, [r5, 0x3]
	adds r2, 0x1
	lsls r2, 3
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	mov r8, r1
	add r0, r8
	str r0, [r5, 0x3C]
	ldrb r6, [r5, 0x2]
	lsls r6, 3
	ldrb r0, [r5, 0x4]
	subs r0, 0x1
	lsls r0, 2
	ldr r3, =gUnknown_0861FC3C
	mov r10, r3
	adds r6, r0
	ldrb r2, [r5, 0x3]
	lsls r2, 3
	ldrh r0, [r4, 0x8]
	lsls r0, 4
	adds r2, r0
	lsls r2, 16
	asrs r2, 16
	mov r0, r10
	adds r1, r6, 0
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	add r2, r8
	str r2, [r5, 0x44]
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x2
	ldr r0, =0x000003ff
	mov r9, r0
	mov r0, r9
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldr r1, [r5, 0x44]
	ldr r0, =sub_81C90A0
	str r0, [r1, 0x1C]
	ldrb r2, [r5, 0x3]
	lsls r2, 3
	mov r0, r10
	adds r1, r6, 0
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	add r1, r8
	str r1, [r5, 0x40]
	ldrh r2, [r1, 0x4]
	lsls r0, r2, 22
	lsrs r0, 22
	adds r0, 0x4
	mov r3, r9
	ands r0, r3
	ands r4, r2
	orrs r4, r0
	strh r4, [r1, 0x4]
	ldr r1, [r5, 0x40]
	ldr r0, =sub_81C90F4
	str r0, [r1, 0x1C]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8EF8

	thumb_func_start sub_81C8FE0
sub_81C8FE0: @ 81C8FE0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x3C]
	bl DestroySprite
	ldr r0, [r4, 0x40]
	bl DestroySprite
	ldr r0, [r4, 0x44]
	bl DestroySprite
	movs r0, 0xA
	bl FreeObjectTilesByTag
	movs r0, 0x14
	bl FreeObjectPaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8FE0

	thumb_func_start sub_81C9008
sub_81C9008: @ 81C9008
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _081C9028
	ldr r2, [r5, 0x3C]
	ldr r1, =SpriteCallbackDummy
	str r1, [r2, 0x1C]
	ldr r0, [r5, 0x40]
	str r1, [r0, 0x1C]
	ldr r0, [r5, 0x44]
	str r1, [r0, 0x1C]
	b _081C903A
	.pool
_081C9028:
	ldr r2, [r5, 0x3C]
	ldr r0, =sub_81C9080
	str r0, [r2, 0x1C]
	ldr r1, [r5, 0x40]
	ldr r0, =sub_81C90F4
	str r0, [r1, 0x1C]
	ldr r1, [r5, 0x44]
	ldr r0, =sub_81C90A0
	str r0, [r1, 0x1C]
_081C903A:
	adds r3, r2, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r4, r0
	lsls r4, 2
	ldrb r2, [r3]
	movs r1, 0x5
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r3]
	ldr r2, [r5, 0x40]
	adds r2, 0x3E
	ldrb r3, [r2]
	adds r0, r1, 0
	ands r0, r3
	orrs r0, r4
	strb r0, [r2]
	ldr r0, [r5, 0x44]
	adds r0, 0x3E
	ldrb r2, [r0]
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9008

	thumb_func_start sub_81C9080
sub_81C9080: @ 81C9080
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x0000088e
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 4
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9080

	thumb_func_start sub_81C90A0
sub_81C90A0: @ 81C90A0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C90C2
	bl sub_81C84C0
	cmp r0, 0
	beq _081C90C2
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	b _081C90CC
_081C90C2:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
_081C90CC:
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081C90EC
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x26]
_081C90EC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C90A0

	thumb_func_start sub_81C90F4
sub_81C90F4: @ 81C90F4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C9116
	bl sub_81C84A4
	cmp r0, 0
	beq _081C9116
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	b _081C9120
_081C9116:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
_081C9120:
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081C9142
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r4, 0x30]
	negs r0, r0
	strh r0, [r4, 0x26]
_081C9142:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C90F4

	thumb_func_start sub_81C9148
sub_81C9148: @ 81C9148
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, [r0, 0x40]
	strh r4, [r1, 0x3C]
	ldr r0, [r0, 0x44]
	strh r4, [r0, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C9148

	thumb_func_start sub_81C9160
sub_81C9160: @ 81C9160
	push {r4,r5,lr}
	adds r2, r0, 0
	ldr r0, [r1]
	str r0, [r2, 0x10]
	ldrh r4, [r1, 0x6]
	movs r5, 0
	strh r4, [r2]
	ldrh r3, [r1, 0x4]
	strh r3, [r2, 0x2]
	ldrb r0, [r1, 0x8]
	str r0, [r2, 0xC]
	ldrb r1, [r1, 0xC]
	strh r1, [r2, 0x8]
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r1, r0
	bcc _081C918A
	strh r5, [r2]
	strh r5, [r2, 0x4]
	strh r4, [r2, 0x6]
	b _081C91A6
_081C918A:
	subs r0, r3, r1
	strh r0, [r2, 0x4]
	ldrh r1, [r2]
	ldrh r0, [r2, 0x8]
	adds r1, r0
	ldrh r0, [r2, 0x2]
	cmp r1, r0
	ble _081C91A4
	subs r0, r1, r0
	strh r0, [r2, 0x6]
	subs r0, r4, r0
	strh r0, [r2]
	b _081C91A6
_081C91A4:
	strh r5, [r2, 0x6]
_081C91A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C9160

	thumb_func_start sub_81C91AC
sub_81C91AC: @ 81C91AC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	ldr r4, [r1]
	lsls r4, 30
	lsrs r0, r4, 30
	movs r1, 0
	mov r9, r1
	strb r0, [r7]
	strh r3, [r7, 0x6]
	ldr r0, [r2, 0x10]
	str r0, [r7, 0x34]
	ldr r0, [r2, 0x14]
	str r0, [r7, 0x38]
	ldrb r6, [r2, 0xD]
	strb r6, [r7, 0x1]
	ldrb r1, [r2, 0x9]
	strb r1, [r7, 0x2]
	ldrb r0, [r2, 0xB]
	strb r0, [r7, 0x3]
	ldrb r5, [r2, 0xA]
	strb r5, [r7, 0x4]
	ldrb r0, [r2, 0xE]
	strb r0, [r7, 0x5]
	lsrs r4, 30
	ldr r2, =0xffffff00
	mov r8, r2
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r4
	lsls r1, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ands r0, r2
	orrs r0, r1
	ldr r1, =0xff00ffff
	ands r0, r1
	lsls r5, 24
	ldr r1, =0x00ffffff
	ands r0, r1
	orrs r0, r5
	str r0, [sp]
	ldr r0, [sp, 0x4]
	mov r1, r8
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	lsls r6, 24
	lsrs r6, 16
	ands r0, r2
	orrs r0, r6
	adds r3, 0x2
	lsls r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r3
	str r0, [sp, 0x4]
	mov r0, sp
	bl AddWindow
	strh r0, [r7, 0x8]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _081C9258
	mov r2, r9
	strh r2, [r7, 0xA]
	mov r0, r9
	str r0, [r7, 0x3C]
	str r0, [r7, 0x40]
	str r0, [r7, 0x44]
	movs r0, 0x1
	b _081C925A
	.pool
_081C9258:
	movs r0, 0
_081C925A:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C91AC

	thumb_func_start sub_81C9268
sub_81C9268: @ 81C9268
	push {r4,lr}
	movs r4, 0
	movs r0, 0x98
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081C928A
	movs r4, 0x1
	ldr r0, =0x0000089b
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081C928A
	movs r4, 0x2
_081C928A:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C9268

	thumb_func_start sub_81C9298
sub_81C9298: @ 81C9298
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C92C4
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4]
	strh r1, [r4, 0x2]
	strh r1, [r4, 0x4]
	strh r1, [r4, 0x6]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C92C6
_081C92C4:
	movs r0, 0
_081C92C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9298

	thumb_func_start sub_81C92CC
sub_81C92CC: @ 81C92CC
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C92FA
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r1, [r4, 0x6]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C92FC
_081C92FA:
	movs r0, 0
_081C92FC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C92CC

	thumb_func_start sub_81C9304
sub_81C9304: @ 81C9304
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C932E
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0x3
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9330
_081C932E:
	movs r0, 0
_081C9330:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9304

	thumb_func_start sub_81C9338
sub_81C9338: @ 81C9338
	push {lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r2, r0, 0
	cmp r2, 0
	beq _081C9360
	movs r0, 0
	movs r1, 0x3
	strh r1, [r2]
	strh r0, [r2, 0x2]
	movs r1, 0x5
	strh r1, [r2, 0x4]
	strh r0, [r2, 0x6]
	adds r0, r2, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9362
_081C9360:
	movs r0, 0
_081C9362:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9338

	thumb_func_start sub_81C9368
sub_81C9368: @ 81C9368
	push {r4,r5,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r5, r0, 0
	cmp r5, 0
	beq _081C9394
	movs r4, 0
	movs r0, 0x4
	strh r0, [r5]
	bl sub_81C76AC
	strh r0, [r5, 0x2]
	adds r0, 0x8
	strh r0, [r5, 0x4]
	strh r4, [r5, 0x6]
	adds r0, r5, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9396
_081C9394:
	movs r0, 0
_081C9396:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9368

	thumb_func_start sub_81C939C
sub_81C939C: @ 81C939C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4]
	cmp r0, 0x4
	bhi _081C93E0
	lsls r0, 2
	ldr r1, =_081C93B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C93B4:
	.4byte _081C93C8
	.4byte _081C93CE
	.4byte _081C93CE
	.4byte _081C93D4
	.4byte _081C93DC
_081C93C8:
	movs r0, 0
	bl sub_81C7688
_081C93CE:
	bl sub_81C93EC
	b _081C93DE
_081C93D4:
	ldr r0, =sub_81C963C
	b _081C93DE
	.pool
_081C93DC:
	ldr r0, =sub_81C96FC
_081C93DE:
	str r0, [r4, 0xC]
_081C93E0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C939C

	thumb_func_start sub_81C93EC
sub_81C93EC: @ 81C93EC
	push {lr}
	bl sub_81C767C
	cmp r0, 0x1
	beq _081C9408
	cmp r0, 0x1
	bcc _081C93FE
	cmp r0, 0x2
	beq _081C9410
_081C93FE:
	ldr r0, =sub_81C943C
	b _081C9412
	.pool
_081C9408:
	ldr r0, =sub_81C9520
	b _081C9412
	.pool
_081C9410:
	ldr r0, =c2_pre_battle_1
_081C9412:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C93EC

	thumb_func_start sub_81C941C
sub_81C941C: @ 81C941C
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldr r1, [r0, 0xC]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81C941C

	thumb_func_start sub_81C9430
sub_81C9430: @ 81C9430
	push {lr}
	movs r0, 0x1
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81C9430

	thumb_func_start sub_81C943C
sub_81C943C: @ 81C943C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C944C
	movs r0, 0x1
	b _081C951A
_081C944C:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	beq _081C9508
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _081C9508
	lsls r0, 2
	ldr r1, =_081C9488
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C9488:
	.4byte _081C949C
	.4byte _081C94BC
	.4byte _081C94D4
	.4byte _081C94E0
	.4byte _081C9516
_081C949C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x15]
	movs r0, 0x8
	ands r0, r1
	movs r1, 0x1
	cmp r0, 0
	beq _081C94AE
	movs r1, 0x2
_081C94AE:
	strh r1, [r4, 0x6]
	ldr r1, =0x000186a6
	b _081C94EE
	.pool
_081C94BC:
	movs r1, 0
	movs r0, 0x3
	strh r0, [r4]
	strh r1, [r4, 0x2]
	ldrb r0, [r3, 0x12]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C963C
	str r0, [r4, 0xC]
	movs r0, 0x2
	b _081C951A
	.pool
_081C94D4:
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	b _081C94EE
	.pool
_081C94E0:
	bl sub_81C76B8
	cmp r0, 0
	beq _081C94FC
	movs r0, 0x9
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ac
_081C94EE:
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C951A
	.pool
_081C94FC:
	ldr r0, =sub_81C9600
	str r0, [r4, 0xC]
	movs r0, 0x6
	b _081C951A
	.pool
_081C9508:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081C9516
	movs r0, 0
	b _081C951A
_081C9516:
	movs r0, 0x1
	negs r0, r0
_081C951A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C943C

	thumb_func_start sub_81C9520
sub_81C9520: @ 81C9520
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9530
	movs r0, 0x1
	b _081C9580
_081C9530:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C9570
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _081C9578
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C9580
	.pool
_081C9570:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C957E
_081C9578:
	movs r0, 0x20
	bl audio_play
_081C957E:
	movs r0, 0
_081C9580:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9520

	thumb_func_start c2_pre_battle_1
c2_pre_battle_1: @ 81C9588
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9598
	movs r0, 0x1
	b _081C95F8
_081C9598:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C95E8
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _081C95D4
	cmp r0, 0x4
	beq _081C95F4
	movs r0, 0x20
	bl audio_play
	movs r0, 0
	b _081C95F8
	.pool
_081C95D4:
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C95F8
	.pool
_081C95E8:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081C95F4
	movs r0, 0
	b _081C95F8
_081C95F4:
	movs r0, 0x1
	negs r0, r0
_081C95F8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end c2_pre_battle_1

	thumb_func_start sub_81C9600
sub_81C9600: @ 81C9600
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9616
	bl sub_81C93EC
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C9634
_081C9616:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081C962C
	movs r0, 0
	b _081C9634
	.pool
_081C962C:
	bl sub_81C93EC
	str r0, [r4, 0xC]
	movs r0, 0x7
_081C9634:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9600

	thumb_func_start sub_81C963C
sub_81C963C: @ 81C963C
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_81C9814
	adds r3, r0, 0
	cmp r3, 0
	beq _081C964E
	movs r0, 0x1
	b _081C96F6
_081C964E:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _081C96B8
	ldr r5, =gUnknown_0861FC59
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	ldrh r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 1
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _081C968E
	cmp r0, 0x6
	bgt _081C9688
	cmp r0, 0x5
	beq _081C96A4
	b _081C96B8
	.pool
_081C9688:
	cmp r0, 0x7
	beq _081C96E4
	b _081C96B8
_081C968E:
	movs r0, 0x4
	strh r0, [r4]
	strh r3, [r4, 0x2]
	ldrb r0, [r5, 0x18]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C96FC
	str r0, [r4, 0xC]
	movs r0, 0x4
	b _081C96F6
	.pool
_081C96A4:
	strh r3, [r4, 0x6]
	ldr r1, =0x000186a7
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C96F6
	.pool
_081C96B8:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C96F4
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_0861FC54
	ldrh r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C96E4
	strh r0, [r4, 0x2]
	ldr r0, =sub_81C9798
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C96F6
	.pool
_081C96E4:
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81C97C0
	movs r0, 0x3
	b _081C96F6
_081C96F4:
	movs r0, 0
_081C96F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C963C

	thumb_func_start sub_81C96FC
sub_81C96FC: @ 81C96FC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C970C
	movs r0, 0x1
	b _081C9792
_081C970C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C9754
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xD
	beq _081C9780
	subs r0, 0x8
	bl sub_81C7694
	ldr r1, =0x000186a8
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x3
	strh r0, [r4, 0x6]
	movs r0, 0x8
	b _081C9792
	.pool
_081C9754:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C9790
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_0861FC54
	ldrh r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C9780
	strh r0, [r4, 0x2]
	ldr r0, =sub_81C97A4
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C9792
	.pool
_081C9780:
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81C97F8
	movs r0, 0x5
	b _081C9792
_081C9790:
	movs r0, 0
_081C9792:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C96FC

	thumb_func_start sub_81C9798
sub_81C9798: @ 81C9798
	push {lr}
	bl sub_81C97C0
	movs r0, 0x3
	pop {r1}
	bx r1
	thumb_func_end sub_81C9798

	thumb_func_start sub_81C97A4
sub_81C97A4: @ 81C97A4
	push {lr}
	bl sub_81C97F8
	movs r0, 0x5
	pop {r1}
	bx r1
	thumb_func_end sub_81C97A4

	thumb_func_start sub_81C97B0
sub_81C97B0: @ 81C97B0
	str r1, [r0, 0x8]
	ldr r1, =sub_81C97BC
	str r1, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C97B0

	thumb_func_start sub_81C97BC
sub_81C97BC: @ 81C97BC
	ldr r0, [r0, 0x8]
	bx lr
	thumb_func_end sub_81C97BC

	thumb_func_start sub_81C97C0
sub_81C97C0: @ 81C97C0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	ldr r2, =gUnknown_0861FC59
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r0, 0x1
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C943C
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C97C0

	thumb_func_start sub_81C97F8
sub_81C97F8: @ 81C97F8
	movs r1, 0x3
	strh r1, [r0]
	movs r1, 0x1
	strh r1, [r0, 0x2]
	ldr r1, =gUnknown_0861FC59
	ldrb r1, [r1, 0x13]
	strh r1, [r0, 0x4]
	ldr r1, =sub_81C963C
	str r1, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C97F8

	thumb_func_start sub_81C9814
sub_81C9814: @ 81C9814
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C9848
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	ldrh r3, [r4]
	cmp r0, 0
	bge _081C986A
	ldr r0, =gUnknown_0861FC54
	adds r0, r3, r0
	ldrb r0, [r0]
	strh r0, [r4, 0x2]
	b _081C986A
	.pool
_081C9848:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C988C
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r0, =gUnknown_0861FC54
	ldrh r1, [r4]
	adds r0, r1, r0
	adds r3, r1, 0
	ldrb r0, [r0]
	cmp r2, r0
	ble _081C986A
	strh r5, [r4, 0x2]
_081C986A:
	ldr r2, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 1
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	strh r0, [r4, 0x4]
	movs r0, 0x1
	b _081C988E
	.pool
_081C988C:
	movs r0, 0
_081C988E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9814

	thumb_func_start sub_81C9894
sub_81C9894: @ 81C9894
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81C9894

	thumb_func_start sub_81C98A4
sub_81C98A4: @ 81C98A4
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98A4

	thumb_func_start sub_81C98B4
sub_81C98B4: @ 81C98B4
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldrh r0, [r0, 0x4]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98B4

	thumb_func_start sub_81C98C4
sub_81C98C4: @ 81C98C4
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldrh r0, [r0, 0x6]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98C4

	thumb_func_start sub_81C98D4
sub_81C98D4: @ 81C98D4
	push {r4,lr}
	movs r4, 0
_081C98D8:
	adds r0, r4, 0
	bl sub_81CB0C8
	ldr r1, =gUnknown_02037318
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081C9914
	adds r0, r4, 0
	bl sub_81CAE08
	cmp r0, 0
	beq _081C9914
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C9914
	movs r0, 0x1
	b _081C991C
	.pool
_081C9914:
	adds r4, 0x1
	cmp r4, 0x4D
	ble _081C98D8
	movs r0, 0
_081C991C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C98D4

	thumb_func_start sub_81C9924
sub_81C9924: @ 81C9924
	push {lr}
	bl sub_81C9958
	adds r1, r0, 0
	cmp r1, 0
	beq _081C9938
	movs r0, 0
	strb r0, [r1, 0xD]
	movs r0, 0x1
	b _081C993A
_081C9938:
	movs r0, 0
_081C993A:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9924

	thumb_func_start sub_81C9940
sub_81C9940: @ 81C9940
	push {lr}
	bl sub_81C9958
	adds r1, r0, 0
	cmp r1, 0
	beq _081C9952
	movs r0, 0x1
	strb r0, [r1, 0xD]
	b _081C9954
_081C9952:
	movs r0, 0
_081C9954:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9940

	thumb_func_start sub_81C9958
sub_81C9958: @ 81C9958
	push {r4,lr}
	ldr r1, =0x0000088c
	movs r0, 0x2
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C997A
	movs r0, 0
	strb r0, [r4, 0xC]
	ldr r0, =sub_81C9A10
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81C99FC
	str r0, [r4]
_081C997A:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C9958

	thumb_func_start sub_81C9990
sub_81C9990: @ 81C9990
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_086201A0
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81C99FC
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9990

	thumb_func_start sub_81C99C0
sub_81C99C0: @ 81C99C0
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81C99C0

	thumb_func_start sub_81C99D4
sub_81C99D4: @ 81C99D4
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81CA7F4
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	bl sub_81C9FEC
	bl sub_81CA994
	movs r0, 0x2
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C99D4

	thumb_func_start sub_81C99FC
sub_81C99FC: @ 81C99FC
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C99FC

	thumb_func_start sub_81C9A10
sub_81C9A10: @ 81C9A10
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x9
	bls _081C9A24
	b _081C9C60
_081C9A24:
	lsls r0, r4, 2
	ldr r1, =_081C9A34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C9A34:
	.4byte _081C9A5C
	.4byte _081C9AEC
	.4byte _081C9B30
	.4byte _081C9B88
	.4byte _081C9B9E
	.4byte _081C9BA4
	.4byte _081C9BB6
	.4byte _081C9BC0
	.4byte _081C9C0E
	.4byte _081C9C4C
_081C9A5C:
	ldr r0, =gUnknown_08620194
	movs r1, 0x3
	bl sub_81C7B54
	ldr r1, =gUnknown_08DC90E0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x8C
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DC9130
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_08DC90C0
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
_081C9AD6:
	movs r0, 0
	b _081C9C62
	.pool
_081C9AEC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081C9AFA
	b _081C9C5C
_081C9AFA:
	ldr r1, =gUnknown_0861FD6C
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_0861FFF4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_0861FD4C
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	b _081C9AD6
	.pool
_081C9B30:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081C9B3E
	b _081C9C5C
_081C9B3E:
	ldr r1, =gUnknown_0861FC98
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_0861FCAC
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_0861FC78
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9B76
	bl sub_81C9894
	cmp r0, 0x4
	bne _081C9AD6
_081C9B76:
	bl sub_81CA850
	b _081C9AD6
	.pool
_081C9B88:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081C9C5C
	bl sub_81CA6E0
	bl sub_81CA7D4
_081C9B9A:
	movs r0, 0x1
	b _081C9C62
_081C9B9E:
	bl sub_81C9FC4
	b _081C9B9A
_081C9BA4:
	bl sub_81CA714
	bl sub_81CA02C
	bl sub_81CA640
	bl sub_81CA0C8
	b _081C9AD6
_081C9BB6:
	bl sub_81CA7C4
	cmp r0, 0
	bne _081C9C5C
	b _081C9B9A
_081C9BC0:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldrb r0, [r5, 0xD]
	cmp r0, 0
	beq _081C9BE0
	movs r0, 0x1
	bl sub_81C7AC0
	b _081C9BEC
_081C9BE0:
	movs r0, 0x6E
	bl audio_play
	movs r0, 0x3
	bl sub_81C7AC0
_081C9BEC:
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9BFE
	cmp r0, 0x4
	bne _081C9C06
	movs r0, 0x7
	bl sub_81C7DFC
_081C9BFE:
	movs r0, 0x1
	bl sub_81C7DFC
	b _081C9AD6
_081C9C06:
	movs r0, 0
	bl sub_81C7DFC
	b _081C9AD6
_081C9C0E:
	bl sub_81C7B34
	cmp r0, 0
	bne _081C9C5C
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9C2C
	cmp r0, 0x4
	bne _081C9C38
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
_081C9C2C:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	b _081C9C42
_081C9C38:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
_081C9C42:
	bl sub_81CA20C
	bl titlescreen_0
	b _081C9B9A
_081C9C4C:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9C5C
	bl sub_81C8010
	cmp r0, 0
	beq _081C9C60
_081C9C5C:
	movs r0, 0x2
	b _081C9C62
_081C9C60:
	movs r0, 0x4
_081C9C62:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9A10

	thumb_func_start sub_81C9C6C
sub_81C9C6C: @ 81C9C6C
	push {lr}
	cmp r0, 0
	beq _081C9C78
	cmp r0, 0x1
	beq _081C9C8E
	b _081C9CA2
_081C9C78:
	bl sub_81CAA3C
	bl sub_81CA278
	bl sub_81CA714
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	b _081C9CA4
_081C9C8E:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9C9E
	bl sub_81CA7C4
	cmp r0, 0
	beq _081C9CA2
_081C9C9E:
	movs r0, 0x2
	b _081C9CA4
_081C9CA2:
	movs r0, 0x4
_081C9CA4:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9C6C

	thumb_func_start sub_81C9CA8
sub_81C9CA8: @ 81C9CA8
	push {lr}
	cmp r0, 0x1
	beq _081C9CDC
	cmp r0, 0x1
	bgt _081C9CB8
	cmp r0, 0
	beq _081C9CC2
	b _081C9D3C
_081C9CB8:
	cmp r0, 0x2
	beq _081C9CFA
	cmp r0, 0x3
	beq _081C9D14
	b _081C9D3C
_081C9CC2:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0
	movs r1, 0
	bl sub_81C7FC4
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	b _081C9D3E
_081C9CDC:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9D34
	bl sub_81C8010
	cmp r0, 0
	bne _081C9D34
	bl sub_81CA0C8
	movs r0, 0x1
	bl sub_81C7DFC
	movs r0, 0
	b _081C9D3E
_081C9CFA:
	bl sub_81CA20C
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	bl sub_81CA818
	bl sub_81CA714
	movs r0, 0
	b _081C9D3E
_081C9D14:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9D34
	bl sub_81C8010
	cmp r0, 0
	bne _081C9D34
	bl sub_81CA89C
	cmp r0, 0
	bne _081C9D34
	bl sub_81CA7C4
	cmp r0, 0
	beq _081C9D38
_081C9D34:
	movs r0, 0x2
	b _081C9D3E
_081C9D38:
	bl sub_81CA9D8
_081C9D3C:
	movs r0, 0x4
_081C9D3E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9CA8

	thumb_func_start sub_81C9D44
sub_81C9D44: @ 81C9D44
	push {lr}
	cmp r0, 0x1
	beq _081C9D72
	cmp r0, 0x1
	bgt _081C9D54
	cmp r0, 0
	beq _081C9D5E
	b _081C9DD2
_081C9D54:
	cmp r0, 0x2
	beq _081C9D90
	cmp r0, 0x3
	beq _081C9DAA
	b _081C9DD2
_081C9D5E:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0x1
	movs r1, 0
	bl sub_81C7FC4
	movs r0, 0
	b _081C9DD4
_081C9D72:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9DCA
	bl sub_81C8010
	cmp r0, 0
	bne _081C9DCA
	bl sub_81CA0C8
	movs r0, 0
	bl sub_81C7DFC
	movs r0, 0
	b _081C9DD4
_081C9D90:
	bl sub_81CA20C
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	bl sub_81CA864
	bl sub_81CA714
	movs r0, 0
	b _081C9DD4
_081C9DAA:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9DCA
	bl sub_81C8010
	cmp r0, 0
	bne _081C9DCA
	bl sub_81CA89C
	cmp r0, 0
	bne _081C9DCA
	bl sub_81CA7C4
	cmp r0, 0
	beq _081C9DCE
_081C9DCA:
	movs r0, 0x2
	b _081C9DD4
_081C9DCE:
	bl sub_81CA9D8
_081C9DD2:
	movs r0, 0x4
_081C9DD4:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9D44

	thumb_func_start sub_81C9DD8
sub_81C9DD8: @ 81C9DD8
	push {lr}
	cmp r0, 0x1
	beq _081C9E04
	cmp r0, 0x1
	bgt _081C9DE8
	cmp r0, 0
	beq _081C9DF2
	b _081C9E50
_081C9DE8:
	cmp r0, 0x2
	beq _081C9E1A
	cmp r0, 0x3
	beq _081C9E30
	b _081C9E50
_081C9DF2:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	b _081C9E52
_081C9E04:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9E48
	movs r0, 0x7
	bl sub_81C7DFC
	bl sub_81CA0C8
	movs r0, 0
	b _081C9E52
_081C9E1A:
	bl sub_81CA20C
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	bl sub_81CA714
	movs r0, 0
	b _081C9E52
_081C9E30:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9E48
	bl sub_81C8010
	cmp r0, 0
	bne _081C9E48
	bl sub_81CA89C
	cmp r0, 0
	beq _081C9E4C
_081C9E48:
	movs r0, 0x2
	b _081C9E52
_081C9E4C:
	bl sub_81CA9D8
_081C9E50:
	movs r0, 0x4
_081C9E52:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9DD8

	thumb_func_start sub_81C9E58
sub_81C9E58: @ 81C9E58
	push {lr}
	cmp r0, 0x1
	beq _081C9E86
	cmp r0, 0x1
	bgt _081C9E68
	cmp r0, 0
	beq _081C9E72
	b _081C9EC2
_081C9E68:
	cmp r0, 0x2
	beq _081C9E9E
	cmp r0, 0x3
	beq _081C9EAA
	b _081C9EC2
_081C9E72:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0x7
	movs r1, 0
	bl sub_81C7FC4
	movs r0, 0
	b _081C9EC4
_081C9E86:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9EBA
	bl sub_81C8010
	cmp r0, 0
	bne _081C9EBA
	bl sub_81CA0C8
	movs r0, 0
	b _081C9EC4
_081C9E9E:
	bl sub_81CA20C
	bl sub_81CA714
	movs r0, 0
	b _081C9EC4
_081C9EAA:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9EBA
	bl sub_81CA89C
	cmp r0, 0
	beq _081C9EBE
_081C9EBA:
	movs r0, 0x2
	b _081C9EC4
_081C9EBE:
	bl sub_81CA9D8
_081C9EC2:
	movs r0, 0x4
_081C9EC4:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9E58

	thumb_func_start sub_81C9EC8
sub_81C9EC8: @ 81C9EC8
	push {lr}
	cmp r0, 0
	beq _081C9ED4
	cmp r0, 0x1
	beq _081C9EE2
	b _081C9EF0
_081C9ED4:
	movs r0, 0x20
	bl audio_play
	bl sub_81CA770
	movs r0, 0
	b _081C9EF2
_081C9EE2:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C9EF0
	movs r0, 0x2
	b _081C9EF2
_081C9EF0:
	movs r0, 0x4
_081C9EF2:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9EC8

	thumb_func_start sub_81C9EF8
sub_81C9EF8: @ 81C9EF8
	push {lr}
	cmp r0, 0
	beq _081C9F04
	cmp r0, 0x1
	beq _081C9F12
	b _081C9F20
_081C9F04:
	movs r0, 0x5
	bl audio_play
	bl sub_81CA714
	movs r0, 0
	b _081C9F22
_081C9F12:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C9F20
	movs r0, 0x2
	b _081C9F22
_081C9F20:
	movs r0, 0x4
_081C9F22:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9EF8

	thumb_func_start sub_81C9F28
sub_81C9F28: @ 81C9F28
	push {lr}
	cmp r0, 0x1
	beq _081C9F52
	cmp r0, 0x1
	bgt _081C9F38
	cmp r0, 0
	beq _081C9F42
	b _081C9FBC
_081C9F38:
	cmp r0, 0x2
	beq _081C9F96
	cmp r0, 0x3
	beq _081C9FB0
	b _081C9FBC
_081C9F42:
	bl sub_81C98C4
	lsls r0, 16
	lsrs r0, 16
	bl sub_81C7BA4
	movs r0, 0
	b _081C9FBE
_081C9F52:
	bl sub_81C7BE8
	cmp r0, 0
	bne _081C9FB8
	bl sub_81C7880
	bl sub_81CA9C8
	bl sub_81CA2DC
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9F7A
	cmp r0, 0x4
	bne _081C9F84
	movs r0, 0x7
	movs r1, 0
	bl sub_81C7FC4
_081C9F7A:
	movs r0, 0x1
	movs r1, 0
	bl sub_81C7FC4
	b _081C9F8C
_081C9F84:
	movs r0, 0
	movs r1, 0
	bl sub_81C7FC4
_081C9F8C:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	b _081C9FBE
_081C9F96:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9FB8
	bl sub_81C8010
	cmp r0, 0
	bne _081C9FB8
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081C9FBE
_081C9FB0:
	bl sub_81C7B34
	cmp r0, 0
	beq _081C9FBC
_081C9FB8:
	movs r0, 0x2
	b _081C9FBE
_081C9FBC:
	movs r0, 0x4
_081C9FBE:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9F28

	thumb_func_start sub_81C9FC4
sub_81C9FC4: @ 81C9FC4
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_086201C4
_081C9FCA:
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x1
	bls _081C9FCA
	ldr r0, =gUnknown_086201D4
	bl sub_81C795C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9FC4

	thumb_func_start sub_81C9FEC
sub_81C9FEC: @ 81C9FEC
	push {lr}
	movs r0, 0x3
	bl FreeObjectTilesByTag
	movs r0, 0x1
	bl FreeObjectTilesByTag
	movs r0, 0x4
	bl FreeObjectPaletteByTag
	movs r0, 0x5
	bl FreeObjectPaletteByTag
	movs r0, 0x6
	bl FreeObjectPaletteByTag
	movs r0, 0x7
	bl FreeObjectPaletteByTag
	movs r0, 0x8
	bl FreeObjectPaletteByTag
	movs r0, 0x3
	bl FreeObjectPaletteByTag
	bl sub_81CA094
	bl sub_81CA698
	pop {r0}
	bx r0
	thumb_func_end sub_81C9FEC

	thumb_func_start sub_81CA02C
sub_81CA02C: @ 81CA02C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x2
	bl sub_81C763C
	movs r2, 0
	adds r0, 0x2C
	mov r8, r0
_081CA03E:
	movs r4, 0
	lsls r0, r2, 2
	lsls r1, r2, 4
	adds r7, r2, 0x1
	adds r0, r2
	lsls r0, 18
	movs r2, 0xA0
	lsls r2, 14
	adds r5, r0, r2
	mov r0, r8
	adds r6, r1, r0
_081CA054:
	ldr r0, =gUnknown_0862034C
	movs r1, 0x8C
	asrs r2, r5, 16
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	stm r6!, {r1}
	lsls r0, r4, 5
	strh r0, [r1, 0x24]
	adds r4, 0x1
	cmp r4, 0x3
	ble _081CA054
	adds r2, r7, 0
	cmp r2, 0x5
	ble _081CA03E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA02C

	thumb_func_start sub_81CA094
sub_81CA094: @ 81CA094
	push {r4-r7,lr}
	movs r0, 0x2
	bl sub_81C763C
	movs r1, 0
	adds r7, r0, 0
	adds r7, 0x2C
_081CA0A2:
	lsls r0, r1, 4
	adds r6, r1, 0x1
	adds r4, r0, r7
	movs r5, 0x3
_081CA0AA:
	ldr r0, [r4]
	bl obj_free_rotscale_entry
	ldm r4!, {r0}
	bl DestroySprite
	subs r5, 0x1
	cmp r5, 0
	bge _081CA0AA
	adds r1, r6, 0
	cmp r1, 0x5
	ble _081CA0A2
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA094

	thumb_func_start sub_81CA0C8
sub_81CA0C8: @ 81CA0C8
	push {lr}
	bl sub_81C9894
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	ldr r1, =gUnknown_08620244
	adds r0, r2, r1
	subs r1, 0x4
	adds r2, r1
	ldrh r1, [r2]
	ldrh r2, [r2, 0x2]
	bl sub_81CA0EC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA0C8

	thumb_func_start sub_81CA0EC
sub_81CA0EC: @ 81CA0EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	str r1, [sp, 0x14]
	str r2, [sp]
	movs r0, 0x2
	bl sub_81C763C
	mov r10, r0
	movs r0, 0x3
	bl GetSpriteTileStartByTag
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	movs r1, 0
_081CA114:
	ldr r0, [r6]
	cmp r0, 0
	beq _081CA1B0
	movs r5, 0
	lsls r2, r1, 4
	mov r0, r10
	adds r0, 0x2C
	lsls r3, r1, 2
	mov r9, r3
	movs r4, 0x10
	add r4, r10
	mov r8, r4
	adds r7, r6, 0x4
	str r7, [sp, 0xC]
	ldr r3, [sp, 0x14]
	ldr r4, [sp]
	adds r3, r4
	str r3, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x10]
	adds r4, r2, r0
_081CA13E:
	ldr r3, [r4]
	ldr r0, [r6]
	ldrh r2, [r0]
	ldr r7, [sp, 0x4]
	adds r2, r7
	lsls r0, r5, 3
	adds r2, r0
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r2, r0
	ldrh r0, [r3, 0x4]
	ldr r7, =0xfffffc00
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x4]
	ldr r0, [r6]
	ldrh r0, [r0, 0x2]
	adds r0, 0x4
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfSpritePaletteTag
	ldr r3, [r4]
	lsls r0, 4
	ldrb r2, [r3, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x5]
	ldr r2, [r4]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r4]
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0x22]
	ldr r1, [r4]
	movs r0, 0x8C
	strh r0, [r1, 0x20]
	ldm r4!, {r1}
	lsls r0, r5, 5
	strh r0, [r1, 0x24]
	adds r5, 0x1
	cmp r5, 0x3
	ble _081CA13E
	mov r1, r8
	add r1, r9
	movs r0, 0x1
	b _081CA1EC
	.pool
_081CA1B0:
	lsls r2, r1, 4
	mov r0, r10
	adds r0, 0x2C
	lsls r3, r1, 2
	mov r9, r3
	movs r4, 0x10
	add r4, r10
	mov r8, r4
	adds r6, 0x4
	str r6, [sp, 0xC]
	ldr r7, [sp, 0x14]
	ldr r3, [sp]
	adds r7, r3
	str r7, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x10]
	movs r3, 0x4
	adds r2, r0
	movs r5, 0x3
_081CA1D6:
	ldm r2!, {r1}
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	subs r5, 0x1
	cmp r5, 0
	bge _081CA1D6
	mov r1, r8
	add r1, r9
	movs r0, 0
_081CA1EC:
	str r0, [r1]
	ldr r6, [sp, 0xC]
	ldr r4, [sp, 0x8]
	str r4, [sp, 0x14]
	ldr r1, [sp, 0x10]
	cmp r1, 0x5
	ble _081CA114
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA0EC

	thumb_func_start sub_81CA20C
sub_81CA20C: @ 81CA20C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x2
	bl sub_81C763C
	adds r6, r0, 0
	bl sub_81C98A4
	mov r8, r0
	movs r7, 0
	movs r5, 0
	adds r4, r6, 0
	adds r4, 0x2C
_081CA228:
	lsls r0, r5, 2
	adds r1, r6, 0
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _081CA25C
	adds r0, r7, 0
	adds r7, 0x1
	cmp r0, r8
	bne _081CA244
	movs r2, 0x82
	strb r5, [r6, 0xB]
	b _081CA246
_081CA244:
	movs r2, 0x8C
_081CA246:
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 1
	movs r3, 0xC
	bl sub_81CA35C
	adds r0, r4, 0
	movs r1, 0
	bl sub_81CA448
	b _081CA264
_081CA25C:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81CA448
_081CA264:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CA228
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA20C

	thumb_func_start sub_81CA278
sub_81CA278: @ 81CA278
	push {r4,r5,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C98A4
	adds r3, r0, 0
	movs r2, 0
	movs r5, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _081CA298
	cmp r5, r3
	beq _081CA2B2
_081CA296:
	adds r5, 0x1
_081CA298:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _081CA2B2
	lsls r0, r2, 2
	adds r1, r4, 0
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _081CA298
	cmp r5, r3
	bne _081CA296
	adds r5, r2, 0
_081CA2B2:
	ldrb r0, [r4, 0xB]
	lsls r0, 4
	adds r0, 0x2C
	adds r0, r4, r0
	movs r1, 0x82
	movs r2, 0x8C
	movs r3, 0x4
	bl sub_81CA35C
	lsls r0, r5, 4
	adds r0, 0x2C
	adds r0, r4, r0
	movs r1, 0x8C
	movs r2, 0x82
	movs r3, 0x4
	bl sub_81CA35C
	strb r5, [r4, 0xB]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA278

	thumb_func_start sub_81CA2DC
sub_81CA2DC: @ 81CA2DC
	push {r4-r6,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r6, r0, 0
	movs r5, 0
	adds r4, r6, 0
	adds r4, 0x2C
_081CA2EC:
	lsls r0, r5, 2
	adds r1, r6, 0
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _081CA316
	ldrb r0, [r6, 0xB]
	cmp r0, r5
	beq _081CA310
	adds r0, r4, 0
	movs r1, 0x8C
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0x8
	bl sub_81CA35C
	b _081CA316
_081CA310:
	adds r0, r4, 0
	bl sub_81CA3B4
_081CA316:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CA2EC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA2DC

	thumb_func_start sub_81CA324
sub_81CA324: @ 81CA324
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r3, r0, 0
	movs r2, 0
	ldr r4, =SpriteCallbackDummy
	adds r1, r3, 0
	adds r1, 0x2C
_081CA336:
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	cmp r0, r4
	bne _081CA354
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x5
	ble _081CA336
	ldrb r0, [r3, 0xC]
	cmp r0, 0
	bne _081CA354
	movs r0, 0
	b _081CA356
	.pool
_081CA354:
	movs r0, 0x1
_081CA356:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CA324

	thumb_func_start sub_81CA35C
sub_81CA35C: @ 81CA35C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r9, r2
	adds r6, r3, 0
	ldr r0, =sub_81CA474
	mov r8, r0
	subs r0, r2, r5
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	adds r3, r0, 0
	movs r1, 0x3
	lsls r2, r5, 4
_081CA380:
	ldr r0, [r4]
	strh r5, [r0, 0x20]
	ldr r0, [r4]
	strh r6, [r0, 0x2E]
	ldr r0, [r4]
	strh r3, [r0, 0x30]
	ldr r0, [r4]
	strh r2, [r0, 0x32]
	ldr r0, [r4]
	mov r7, r9
	strh r7, [r0, 0x3C]
	ldm r4!, {r0}
	mov r7, r8
	str r7, [r0, 0x1C]
	subs r1, 0x1
	cmp r1, 0
	bge _081CA380
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA35C

	thumb_func_start sub_81CA3B4
sub_81CA3B4: @ 81CA3B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	movs r0, 0x2
	bl sub_81C763C
	adds r7, r0, 0
	movs r5, 0
	mov r8, r5
_081CA3C8:
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r2, 0x1]
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r1, [r4]
	ldr r0, =sub_81CA4AC
	str r0, [r1, 0x1C]
	movs r6, 0x8
	strh r6, [r1, 0x2E]
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x30]
	ldr r0, [r4]
	strh r5, [r0, 0x3C]
	ldr r0, [r4]
	bl InitSpriteAffineAnim
	ldm r4!, {r0}
	movs r1, 0
	bl StartObjectRotScalAnim
	adds r5, 0x1
	cmp r5, 0x3
	ble _081CA3C8
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =sub_81CA580
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0x8]
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
	strb r0, [r7, 0xC]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA3B4

	thumb_func_start sub_81CA448
sub_81CA448: @ 81CA448
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x1
	ands r1, r0
	lsls r4, r1, 2
	movs r6, 0x5
	negs r6, r6
	movs r3, 0x3
_081CA458:
	ldm r5!, {r0}
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r6, 0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	subs r3, 0x1
	cmp r3, 0
	bge _081CA458
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA448

	thumb_func_start sub_81CA474
sub_81CA474: @ 81CA474
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081CA49A
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	b _081CA4A2
_081CA49A:
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081CA4A2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA474

	thumb_func_start sub_81CA4AC
sub_81CA4AC: @ 81CA4AC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081CA574
	movs r0, 0x30
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081CA4E2
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x24]
	b _081CA578
_081CA4E2:
	ldrh r0, [r4, 0x32]
	adds r0, 0x10
	strh r0, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	asrs r1, r0, 3
	adds r0, r1, 0
	subs r0, 0x20
	lsrs r1, r0, 31
	adds r0, r1
	asrs r1, r0, 1
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _081CA518
	cmp r0, 0x1
	bgt _081CA50A
	cmp r0, 0
	beq _081CA514
	b _081CA526
_081CA50A:
	cmp r0, 0x2
	beq _081CA51C
	cmp r0, 0x3
	beq _081CA520
	b _081CA526
_081CA514:
	negs r1, r1
	b _081CA520
_081CA518:
	negs r0, r1
	b _081CA524
_081CA51C:
	strh r1, [r4, 0x24]
	b _081CA526
_081CA520:
	lsls r0, r1, 1
	adds r0, r1
_081CA524:
	strh r0, [r4, 0x24]
_081CA526:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CA578
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	ldrb r1, [r4, 0x1]
	lsrs r1, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	adds r0, r4, 0
	movs r3, 0
	bl CalcCenterToCornerVec
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0xD
	negs r1, r1
	ands r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	b _081CA578
	.pool
_081CA574:
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
_081CA578:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA4AC

	thumb_func_start sub_81CA580
sub_81CA580: @ 81CA580
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, 0
	ldrsh r2, [r4, r1]
	cmp r2, 0
	bne _081CA634
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _081CA5AC
	cmp r1, 0x1
	beq _081CA5CC
	b _081CA638
	.pool
_081CA5AC:
	movs r0, 0x10
	strh r0, [r4, 0x4]
	strh r2, [r4, 0x6]
	movs r1, 0xFC
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _081CA638
_081CA5CC:
	ldrh r0, [r4, 0x8]
	ands r1, r0
	cmp r1, 0
	beq _081CA5E4
	ldrh r0, [r4, 0x4]
	subs r0, 0x3
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	bge _081CA5F6
	strh r2, [r4, 0x4]
	b _081CA5F6
_081CA5E4:
	ldrh r0, [r4, 0x6]
	adds r0, 0x3
	strh r0, [r4, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _081CA5F6
	movs r0, 0x10
	strh r0, [r4, 0x6]
_081CA5F6:
	ldrh r1, [r4, 0x6]
	lsls r1, 8
	ldrh r0, [r4, 0x4]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _081CA638
	movs r0, 0x2
	bl sub_81C763C
	ldrb r1, [r0, 0xC]
	subs r1, 0x1
	strb r1, [r0, 0xC]
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
	b _081CA638
_081CA634:
	subs r0, 0x1
	strh r0, [r4]
_081CA638:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA580

	thumb_func_start sub_81CA640
sub_81CA640: @ 81CA640
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =gUnknown_0862036C
	movs r1, 0x10
	movs r2, 0x60
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x28]
	bl sub_81C98D4
	cmp r0, 0
	beq _081CA684
	ldr r1, [r4, 0x28]
	ldr r0, =sub_81CA6AC
	str r0, [r1, 0x1C]
	b _081CA690
	.pool
_081CA684:
	ldr r0, [r4, 0x28]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_081CA690:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA640

	thumb_func_start sub_81CA698
sub_81CA698: @ 81CA698
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldr r0, [r0, 0x28]
	bl DestroySprite
	pop {r0}
	bx r0
	thumb_func_end sub_81CA698

	thumb_func_start sub_81CA6AC
sub_81CA6AC: @ 81CA6AC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _081CA6DA
	movs r0, 0
	strh r0, [r3, 0x2E]
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
_081CA6DA:
	pop {r0}
	bx r0
	thumb_func_end sub_81CA6AC

	thumb_func_start sub_81CA6E0
sub_81CA6E0: @ 81CA6E0
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =gUnknown_086202CC
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA6E0

	thumb_func_start sub_81CA714
sub_81CA714: @ 81CA714
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	bl sub_81C98B4
	ldr r1, =gUnknown_086202D4
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	movs r2, 0xC0
	subs r2, r4
	lsrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0862030C
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA714

	thumb_func_start sub_81CA770
sub_81CA770: @ 81CA770
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	ldr r6, =gUnknown_085EBD4A
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	movs r2, 0xC0
	subs r2, r4
	lsrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0862030F
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA770

	thumb_func_start sub_81CA7C4
sub_81CA7C4: @ 81CA7C4
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CA7C4

	thumb_func_start sub_81CA7D4
sub_81CA7D4: @ 81CA7D4
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =sub_81CA808
	movs r1, 0x2
	bl CreateTask
	strb r0, [r4, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA7D4

	thumb_func_start sub_81CA7F4
sub_81CA7F4: @ 81CA7F4
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldrb r0, [r0, 0xA]
	bl DestroyTask
	pop {r0}
	bx r0
	thumb_func_end sub_81CA7F4

	thumb_func_start sub_81CA808
sub_81CA808: @ 81CA808
	push {lr}
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgX
	pop {r0}
	bx r0
	thumb_func_end sub_81CA808

	thumb_func_start sub_81CA818
sub_81CA818: @ 81CA818
	push {r4,r5,lr}
	ldr r0, =sub_81CA8B0
	movs r1, 0x3
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0861FC7A
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	adds r5, 0xC
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetWordTaskArg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA818

	thumb_func_start sub_81CA850
sub_81CA850: @ 81CA850
	push {lr}
	ldr r0, =gUnknown_0861FC86
	movs r1, 0x31
	movs r2, 0x4
	bl sub_81C7944
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA850

	thumb_func_start sub_81CA864
sub_81CA864: @ 81CA864
	push {r4,r5,lr}
	ldr r0, =sub_81CA8B0
	movs r1, 0x3
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0861FC86
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	subs r5, 0xC
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetWordTaskArg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA864

	thumb_func_start sub_81CA89C
sub_81CA89C: @ 81CA89C
	push {lr}
	ldr r0, =sub_81CA8B0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CA89C

	thumb_func_start sub_81CA8B0
sub_81CA8B0: @ 81CA8B0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	adds r0, r6, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r5, r0, 0
	adds r0, r6, 0
	movs r1, 0x3
	bl GetWordTaskArg
	adds r1, r0, 0
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0xC
	bl sub_81C79BC
	add r0, sp, 0x8
	movs r1, 0x31
	movs r2, 0x4
	bl LoadPalette
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _081CA908
	adds r0, r6, 0
	bl DestroyTask
_081CA908:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA8B0

	thumb_func_start sub_81CA914
sub_81CA914: @ 81CA914
	push {lr}
	bl TransferPlttBuffer
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl sub_80BA0A8
	pop {r0}
	bx r0
	thumb_func_end sub_81CA914

	thumb_func_start titlescreen_0
titlescreen_0: @ 81CA92C
	push {lr}
	movs r0, 0x50
	movs r1, 0x90
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuRegBits
	movs r0, 0x4A
	movs r1, 0x1F
	bl SetGpuRegBits
	movs r0, 0x44
	movs r1, 0xA0
	bl SetGpuRegBits
	bl remove_some_task
	bl sub_81CAA3C
	ldr r2, =gUnknown_08620384
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80BA038
	ldr r0, =sub_81CA914
	bl c3args_set_0toR1_1to0
	ldr r0, =sub_81CA9EC
	movs r1, 0x3
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end titlescreen_0

	thumb_func_start sub_81CA994
sub_81CA994: @ 81CA994
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	bl remove_some_task
	ldr r0, =sub_81CA9EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl sub_81C760C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA994

	thumb_func_start sub_81CA9C8
sub_81CA9C8: @ 81CA9C8
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81CA9C8

	thumb_func_start sub_81CA9D8
sub_81CA9D8: @ 81CA9D8
	push {lr}
	bl sub_81CAA3C
	movs r0, 0x50
	movs r1, 0x90
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81CA9D8

	thumb_func_start sub_81CA9EC
sub_81CA9EC: @ 81CA9EC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	ble _081CAA30
	movs r0, 0
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	adds r0, 0x3
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r2, 0x2]
	ldr r1, =gSineTable
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 21
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x54
	bl SetGpuReg
_081CAA30:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA9EC

	thumb_func_start sub_81CAA3C
sub_81CAA3C: @ 81CAA3C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	bl sub_81C9894
	adds r4, r0, 0
	bl sub_81C98A4
	ldr r2, =gUnknown_08620240
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x2]
	adds r4, r2, 0
	muls r4, r0
	ldrh r1, [r1]
	adds r4, r1
	subs r4, 0x8
	mov r0, sp
	movs r6, 0
	strh r6, [r0]
	ldr r5, =gUnknown_02038C28
	ldr r0, =0x010000a0
	mov r8, r0
	mov r0, sp
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	strh r6, [r0]
	movs r1, 0xF0
	lsls r1, 3
	adds r1, r5
	mov r9, r1
	mov r2, r8
	bl CpuSet
	add r0, sp, 0x4
	ldr r1, =0x000072f0
	adds r6, r1, 0
	strh r6, [r0]
	lsls r4, 1
	adds r5, r4, r5
	ldr r1, =0x01000010
	mov r8, r1
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	mov r0, sp
	adds r0, 0x6
	strh r6, [r0]
	add r4, r9
	adds r1, r4, 0
	mov r2, r8
	bl CpuSet
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CAA3C

	thumb_func_start sub_81CAADC
sub_81CAADC: @ 81CAADC
	push {lr}
	bl sub_81CA9C8
	pop {r0}
	bx r0
	thumb_func_end sub_81CAADC

	thumb_func_start sub_81CAAE8
sub_81CAAE8: @ 81CAAE8
	push {r4,lr}
	movs r1, 0xD4
	lsls r1, 1
	movs r0, 0x5
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CAB1C
	ldr r0, =sub_81CAB44
	str r0, [r4, 0x18]
	movs r0, 0
	strh r0, [r4, 0x8]
	str r0, [r4, 0x10]
	ldr r0, =sub_81CAD20
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CAB1E
	.pool
_081CAB1C:
	movs r0, 0
_081CAB1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAAE8

	thumb_func_start sub_81CAB24
sub_81CAB24: @ 81CAB24
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldr r1, [r0, 0x18]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CAB24

	thumb_func_start sub_81CAB38
sub_81CAB38: @ 81CAB38
	push {lr}
	movs r0, 0x5
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CAB38

	thumb_func_start sub_81CAB44
sub_81CAB44: @ 81CAB44
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r3, =gMain
	ldrh r1, [r3, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CAB5C
	movs r0, 0x2
	b _081CABF4
	.pool
_081CAB5C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CAB68
	movs r0, 0x1
	b _081CABF4
_081CAB68:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CAB74
	movs r0, 0x4
	b _081CABF4
_081CAB74:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CAB84
	movs r0, 0x3
	b _081CABF4
_081CAB84:
	ldrh r1, [r3, 0x2E]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _081CABD0
	ldr r0, =sub_81CAC04
	str r0, [r4, 0x18]
	strh r2, [r4]
	bl sub_81C875C
	lsls r0, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	beq _081CABAE
	ldrh r0, [r1, 0x1E]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CABC0
_081CABAE:
	ldr r0, =gUnknown_0862250A
	str r0, [r4, 0x4]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	b _081CABC6
	.pool
_081CABC0:
	ldr r0, =gUnknown_08622508
	str r0, [r4, 0x4]
	strh r5, [r4, 0x2]
_081CABC6:
	movs r0, 0x5
	b _081CABF4
	.pool
_081CABD0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CABF2
	bl sub_81C767C
	cmp r0, 0x1
	beq _081CABEC
	ldr r0, =sub_81CABFC
	str r0, [r4, 0x18]
	movs r0, 0xF
	b _081CABF4
	.pool
_081CABEC:
	movs r0, 0x20
	bl audio_play
_081CABF2:
	movs r0, 0
_081CABF4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAB44

	thumb_func_start sub_81CABFC
sub_81CABFC: @ 81CABFC
	ldr r0, =0x000186a4
	bx lr
	.pool
	thumb_func_end sub_81CABFC

	thumb_func_start sub_81CAC04
sub_81CAC04: @ 81CAC04
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CAC24
	ldrh r0, [r4]
	cmp r0, 0
	beq _081CAC24
	subs r0, 0x1
	b _081CAC38
	.pool
_081CAC24:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CAC3E
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	cmp r0, r1
	bcs _081CAC3E
	adds r0, 0x1
_081CAC38:
	strh r0, [r4]
	movs r0, 0x6
	b _081CACAC
_081CAC3E:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CAC98
	ldrh r1, [r4]
	ldr r0, [r4, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CAC8C
	cmp r0, 0x1
	bgt _081CAC5E
	cmp r0, 0
	beq _081CAC64
	b _081CAC98
_081CAC5E:
	cmp r0, 0x2
	bne _081CAC98
	b _081CACA6
_081CAC64:
	bl sub_81C767C
	cmp r0, 0x1
	bne _081CAC72
	movs r0, 0x2
	bl sub_81C7688
_081CAC72:
	ldr r0, =sub_81CACF8
	str r0, [r4, 0x18]
	bl sub_81CB1D0
	cmp r0, 0
	beq _081CAC88
	movs r0, 0x9
	b _081CACAC
	.pool
_081CAC88:
	movs r0, 0x8
	b _081CACAC
_081CAC8C:
	ldr r0, =sub_81CACB8
	str r0, [r4, 0x18]
	movs r0, 0xB
	b _081CACAC
	.pool
_081CAC98:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CACA6
	movs r0, 0
	b _081CACAC
_081CACA6:
	ldr r0, =sub_81CAB44
	str r0, [r4, 0x18]
	movs r0, 0x7
_081CACAC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAC04

	thumb_func_start sub_81CACB8
sub_81CACB8: @ 81CACB8
	push {lr}
	adds r3, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CACD0
	movs r0, 0xC
	b _081CACF0
	.pool
_081CACD0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CACDC
	movs r0, 0xD
	b _081CACF0
_081CACDC:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CACEA
	movs r0, 0
	b _081CACF0
_081CACEA:
	ldr r0, =sub_81CAB44
	str r0, [r3, 0x18]
	movs r0, 0xE
_081CACF0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CACB8

	thumb_func_start sub_81CACF8
sub_81CACF8: @ 81CACF8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081CAD10
	movs r0, 0
	b _081CAD16
	.pool
_081CAD10:
	ldr r0, =sub_81CAB44
	str r0, [r2, 0x18]
	movs r0, 0xA
_081CAD16:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CACF8

	thumb_func_start sub_81CAD20
sub_81CAD20: @ 81CAD20
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x1
	beq _081CAD4C
	cmp r5, 0x1
	bgt _081CAD3A
	cmp r5, 0
	beq _081CAD44
	b _081CAE00
_081CAD3A:
	cmp r5, 0x2
	beq _081CAD9C
	cmp r5, 0x3
	beq _081CADFC
	b _081CAE00
_081CAD44:
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
_081CAD48:
	movs r0, 0x1
	b _081CAE02
_081CAD4C:
	movs r6, 0
	ldrh r5, [r4, 0x8]
_081CAD50:
	adds r0, r5, 0
	bl sub_81D15F4
	cmp r0, 0
	beq _081CAD80
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	strh r5, [r0, 0x1E]
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0, 0x1C]
	adds r0, r5, 0
	bl sub_81D16DC
	ldrh r1, [r4, 0xA]
	lsls r1, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1D]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_081CAD80:
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	movs r2, 0
	strh r1, [r4, 0x8]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x14
	bhi _081CADF6
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, 0x1D
	ble _081CAD50
	movs r0, 0x3
	b _081CAE02
_081CAD9C:
	movs r6, 0
	ldrh r5, [r4, 0x8]
	movs r7, 0
_081CADA2:
	ldrh r0, [r4, 0x8]
	bl sub_81D1BF8
	cmp r0, 0
	bne _081CADDC
	ldrh r0, [r4, 0x8]
	bl sub_81CAE08
	cmp r0, 0
	beq _081CADDC
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	ldrh r1, [r4, 0x8]
	strh r1, [r0, 0x1E]
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	strb r7, [r0, 0x1C]
	adds r0, r5, 0
	bl sub_81CB0C8
	ldrh r1, [r4, 0xA]
	lsls r1, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1D]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_081CADDC:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4D
	bhi _081CAD48
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, 0x1D
	ble _081CADA2
	movs r0, 0x3
	b _081CAE02
_081CADF6:
	strh r1, [r4, 0xC]
	strh r2, [r4, 0x8]
	b _081CAD48
_081CADFC:
	movs r0, 0x1
	str r0, [r4, 0x10]
_081CAE00:
	movs r0, 0x4
_081CAE02:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAD20

	thumb_func_start sub_81CAE08
sub_81CAE08: @ 81CAE08
	push {lr}
	cmp r0, 0x4D
	ble _081CAE12
	movs r0, 0
	b _081CAE24
_081CAE12:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
_081CAE24:
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE08

	thumb_func_start sub_81CAE28
sub_81CAE28: @ 81CAE28
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldr r0, [r0, 0x10]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE28

	thumb_func_start sub_81CAE38
sub_81CAE38: @ 81CAE38
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldrh r0, [r0, 0xA]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE38

	thumb_func_start sub_81CAE48
sub_81CAE48: @ 81CAE48
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldrh r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE48

	thumb_func_start sub_81CAE58
sub_81CAE58: @ 81CAE58
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	ldrh r1, [r1, 0xC]
	subs r0, r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE58

	thumb_func_start sub_81CAE6C
sub_81CAE6C: @ 81CAE6C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	adds r4, r0
	ldrh r0, [r1, 0xA]
	cmp r4, r0
	bge _081CAE8A
	lsls r0, r4, 2
	adds r0, r1, r0
	ldrh r0, [r0, 0x1E]
	b _081CAE8C
_081CAE8A:
	movs r0, 0x4E
_081CAE8C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE6C

	thumb_func_start sub_81CAE94
sub_81CAE94: @ 81CAE94
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	adds r0, 0x1C
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE94

	thumb_func_start sub_81CAEA4
sub_81CAEA4: @ 81CAEA4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r4, 2
	adds r0, r4
	ldrb r0, [r0, 0x1D]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAEA4

	thumb_func_start sub_81CAEBC
sub_81CAEBC: @ 81CAEBC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r1, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAED4
	ldrh r4, [r1, 0x1E]
	b _081CAEDC
_081CAED4:
	ldrh r0, [r1, 0x1E]
	bl sub_81D1854
	adds r4, r0, 0
_081CAEDC:
	cmp r4, 0x4E
	beq _081CAEFC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _081CAEFE
	.pool
_081CAEFC:
	movs r0, 0
_081CAEFE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAEBC

	thumb_func_start sub_81CAF04
sub_81CAF04: @ 81CAF04
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r1, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAF34
	ldrh r0, [r1, 0x1E]
	bl sub_81D15BC
	adds r4, r0, 0
	ldr r1, =gTrainers
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x3]
	b _081CAF6C
	.pool
_081CAF34:
	ldrh r5, [r1, 0x1E]
	adds r0, r5, 0
	bl sub_81D1854
	adds r4, r0, 0
	cmp r4, 0x4E
	bne _081CAF58
	adds r0, r5, 0
	bl sub_81D1BD0
	adds r4, r0, 0
	ldr r0, =gTrainerPicIndices
	adds r0, r4, r0
	ldrb r0, [r0]
	b _081CAF6C
	.pool
_081CAF58:
	adds r0, r4, 0
	bl sub_81D15BC
	adds r4, r0, 0
	ldr r0, =gTrainers
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x3]
_081CAF6C:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAF04

	thumb_func_start sub_81CAF78
sub_81CAF78: @ 81CAF78
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0
	strb r0, [r6]
	ldr r0, =gUnknown_02037318
	ldrb r0, [r0, 0x17]
	bl is_light_level_1_2_3_or_6
	lsls r0, 24
	cmp r0, 0
	bne _081CAFA4
	ldr r0, =gUnknown_085EEB0B
	b _081CAFCE
	.pool
_081CAFA4:
	lsls r0, r5, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAFC4
	ldrh r0, [r1, 0x1E]
	bl sub_81D15BC
	ldr r1, =gStringVar4
	bl sub_81967AC
	strb r0, [r6]
	b _081CAFCC
	.pool
_081CAFC4:
	ldrh r0, [r1, 0x1E]
	ldr r1, =gStringVar4
	bl sub_81D189C
_081CAFCC:
	ldr r0, =gStringVar4
_081CAFCE:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAF78

	thumb_func_start sub_81CAFD8
sub_81CAFD8: @ 81CAFD8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r4, 2
	adds r4, r0, r4
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CB004
	ldrh r0, [r4, 0x1E]
	bl sub_81D1854
	adds r1, r0, 0
	cmp r1, 0x4E
	bne _081CB006
	ldrh r0, [r4, 0x1E]
	adds r1, r5, 0
	bl sub_81D1B40
	b _081CB012
_081CB004:
	ldrh r1, [r4, 0x1E]
_081CB006:
	ldr r2, =gUnknown_08622028
	lsls r0, r5, 2
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
_081CB012:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAFD8

	thumb_func_start sub_81CB01C
sub_81CB01C: @ 81CB01C
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CB01C

	thumb_func_start sub_81CB02C
sub_81CB02C: @ 81CB02C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0x2]
	cmp r0, r4
	blt _081CB046
	ldr r0, [r1, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	b _081CB048
_081CB046:
	movs r0, 0x3
_081CB048:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB02C

	thumb_func_start sub_81CB050
sub_81CB050: @ 81CB050
	push {r4,lr}
	sub sp, 0x8
	adds r2, r0, 0
	adds r4, r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _081CB088
	ldrh r0, [r2, 0x2]
	bl sub_81D15BC
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTrainers
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	muls r0, r2
	ldr r2, =gTrainerClassNames
	adds r0, r2
	str r0, [sp]
	adds r1, 0x4
	str r1, [sp, 0x4]
	b _081CB092
	.pool
_081CB088:
	ldrh r0, [r2, 0x2]
	add r2, sp, 0x4
	mov r1, sp
	bl sub_81D1A78
_081CB092:
	ldr r2, [sp]
	cmp r2, 0
	beq _081CB0B4
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _081CB0B4
	adds r0, r4, 0
	movs r1, 0x7
	movs r3, 0x45
	bl sub_81DB494
	ldr r2, [sp, 0x4]
	movs r1, 0x7
	movs r3, 0x33
	bl sub_81DB494
	b _081CB0C0
_081CB0B4:
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0
	movs r3, 0x78
	bl sub_81DB494
_081CB0C0:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CB050

	thumb_func_start sub_81CB0C8
sub_81CB0C8: @ 81CB0C8
	push {lr}
	ldr r1, =gUnknown_085500A4
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	adds r0, r2, 0
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CB0C8

	thumb_func_start sub_81CB0E4
sub_81CB0E4: @ 81CB0E4
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r7, r0, 0
	movs r6, 0x1
	adds r5, 0x1
	ldrh r0, [r7, 0xA]
	cmp r5, r0
	bge _081CB120
	lsls r0, r5, 2
	adds r0, 0x1C
	adds r4, r0, r7
_081CB100:
	ldrb r0, [r4]
	cmp r0, 0
	beq _081CB110
	ldrh r0, [r4, 0x2]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CB114
_081CB110:
	adds r0, r6, 0
	b _081CB122
_081CB114:
	adds r6, 0x1
	adds r4, 0x4
	adds r5, 0x1
	ldrh r0, [r7, 0xA]
	cmp r5, r0
	blt _081CB100
_081CB120:
	movs r0, 0
_081CB122:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB0E4

	thumb_func_start sub_81CB128
sub_81CB128: @ 81CB128
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	movs r6, 0x1
	negs r6, r6
	subs r5, 0x1
	cmp r5, 0
	blt _081CB162
	lsls r0, r5, 2
	adds r0, 0x1C
	adds r4, r0, r1
_081CB144:
	ldrb r0, [r4]
	cmp r0, 0
	beq _081CB154
	ldrh r0, [r4, 0x2]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CB158
_081CB154:
	adds r0, r6, 0
	b _081CB164
_081CB158:
	subs r6, 0x1
	subs r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _081CB144
_081CB162:
	movs r0, 0
_081CB164:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB128

	thumb_func_start sub_81CB16C
sub_81CB16C: @ 81CB16C
	push {r4,lr}
	movs r4, 0
_081CB170:
	adds r0, r4, 0
	bl sub_81CAE08
	cmp r0, 0
	beq _081CB18A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CB1B2
_081CB18A:
	adds r4, 0x1
	cmp r4, 0x4D
	ble _081CB170
	movs r4, 0
_081CB192:
	adds r0, r4, 0
	bl sub_81D15F4
	cmp r0, 0
	beq _081CB1C0
	adds r0, r4, 0
	bl sub_81D1854
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x000009ca
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _081CB1C0
_081CB1B2:
	movs r0, 0x1
	b _081CB1C8
	.pool
_081CB1C0:
	adds r4, 0x1
	cmp r4, 0x14
	ble _081CB192
	movs r0, 0
_081CB1C8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB16C

	thumb_func_start sub_81CB1D0
sub_81CB1D0: @ 81CB1D0
	push {r4,lr}
	movs r0, 0x5
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C875C
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r4, r0
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	bne _081CB218
	adds r0, r1, 0
	bl sub_81CAEA4
	ldr r1, =gUnknown_02037318
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081CB258
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	ldrh r4, [r4, 0x1E]
	adds r0, r4
	ldrb r0, [r0]
	b _081CB246
	.pool
_081CB218:
	ldrh r0, [r4, 0x1E]
	cmp r0, 0xB
	bne _081CB258
	adds r0, r1, 0
	bl sub_81CAEA4
	ldr r1, =gUnknown_02037318
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081CB258
	ldr r0, =0x0000086b
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081CB258
	movs r0, 0x5B
	bl FlagGet
	lsls r0, 24
_081CB246:
	cmp r0, 0
	bne _081CB258
	movs r0, 0x1
	b _081CB25A
	.pool
_081CB258:
	movs r0, 0
_081CB25A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB1D0

	thumb_func_start sub_81CB260
sub_81CB260: @ 81CB260
	push {r4,lr}
	ldr r1, =0x00002048
	movs r0, 0x6
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CB294
	movs r0, 0
	strb r0, [r4, 0x19]
	ldr r0, =sub_81CB324
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CB310
	str r0, [r4]
	movs r0, 0x1
	b _081CB296
	.pool
_081CB294:
	movs r0, 0
_081CB296:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB260

	thumb_func_start sub_81CB29C
sub_81CB29C: @ 81CB29C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08622798
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CB310
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CB29C

	thumb_func_start sub_81CB2CC
sub_81CB2CC: @ 81CB2CC
	push {lr}
	movs r0, 0x6
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CB2CC

	thumb_func_start sub_81CB2E0
sub_81CB2E0: @ 81CB2E0
	push {r4,lr}
	movs r0, 0x6
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81CC2B4
	bl sub_81CBC1C
	ldrb r0, [r4, 0x12]
	bl RemoveWindow
	ldrb r0, [r4, 0x10]
	bl RemoveWindow
	ldrb r0, [r4, 0x14]
	bl RemoveWindow
	movs r0, 0x6
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CB2E0

	thumb_func_start sub_81CB310
sub_81CB310: @ 81CB310
	push {lr}
	movs r0, 0x6
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CB310

	thumb_func_start sub_81CB324
sub_81CB324: @ 81CB324
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x7
	bls _081CB338
	b _081CB504
_081CB338:
	lsls r0, r4, 2
	ldr r1, =_081CB348
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CB348:
	.4byte _081CB368
	.4byte _081CB3D4
	.4byte _081CB424
	.4byte _081CB468
	.4byte _081CB482
	.4byte _081CB494
	.4byte _081CB4A6
	.4byte _081CB4EA
_081CB368:
	ldr r0, =gUnknown_0862278C
	movs r1, 0x3
	bl sub_81C7B54
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r1, =gUnknown_08622530
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =0x00001024
	adds r1, r5, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086225D4
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_08622510
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x2
	b _081CB418
	.pool
_081CB3D4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CB3E0
	b _081CB4FA
_081CB3E0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	adds r1, r5, 0
	adds r1, 0x24
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =gUnknown_086226E0
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
_081CB418:
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081CB506
	.pool
_081CB424:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081CB4FA
	adds r0, r5, 0
	bl sub_81CC034
	ldr r1, =gUnknown_08622760
	str r4, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_08622700
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =gUnknown_08622720
	movs r1, 0x50
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0
	b _081CB506
	.pool
_081CB468:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CB4FA
	bl sub_81CAE28
	cmp r0, 0
	beq _081CB4FA
	bl sub_81CBBB8
	movs r0, 0
	b _081CB506
_081CB482:
	bl sub_81C8224
	cmp r0, 0
	bne _081CB4FA
	adds r0, r5, 0
	bl sub_81CBD78
	movs r0, 0
	b _081CB506
_081CB494:
	adds r0, r5, 0
	bl sub_81CBDC0
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
	movs r0, 0
	b _081CB506
_081CB4A6:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	bl sub_81CC214
	movs r0, 0x3
	bl sub_81C7DFC
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x1
	bl sub_81C7AC0
	movs r0, 0
	b _081CB506
_081CB4EA:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CB4FA
	bl sub_81C8010
	cmp r0, 0
	beq _081CB4FE
_081CB4FA:
	movs r0, 0x2
	b _081CB506
_081CB4FE:
	movs r0, 0x1
	bl sub_81CBC38
_081CB504:
	movs r0, 0x4
_081CB506:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB324

	thumb_func_start sub_81CB510
sub_81CB510: @ 81CB510
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB55E
	cmp r4, 0x1
	bgt _081CB52A
	cmp r4, 0
	beq _081CB534
	b _081CB580
_081CB52A:
	cmp r4, 0x2
	beq _081CB566
	cmp r4, 0x3
	beq _081CB572
	b _081CB580
_081CB534:
	bl sub_81C868C
	cmp r0, 0x1
	beq _081CB54C
	cmp r0, 0x1
	bgt _081CB546
	cmp r0, 0
	beq _081CB580
	b _081CB56E
_081CB546:
	cmp r0, 0x2
	beq _081CB556
	b _081CB56E
_081CB54C:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CB582
_081CB556:
	movs r0, 0x5
	bl audio_play
	b _081CB56E
_081CB55E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB57C
_081CB566:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB56E:
	movs r0, 0
	b _081CB582
_081CB572:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB580
_081CB57C:
	movs r0, 0x2
	b _081CB582
_081CB580:
	movs r0, 0x4
_081CB582:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB510

	thumb_func_start sub_81CB588
sub_81CB588: @ 81CB588
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB5D6
	cmp r4, 0x1
	bgt _081CB5A2
	cmp r4, 0
	beq _081CB5AC
	b _081CB5F8
_081CB5A2:
	cmp r4, 0x2
	beq _081CB5DE
	cmp r4, 0x3
	beq _081CB5EA
	b _081CB5F8
_081CB5AC:
	bl sub_81C8658
	cmp r0, 0x1
	beq _081CB5C4
	cmp r0, 0x1
	bgt _081CB5BE
	cmp r0, 0
	beq _081CB5F8
	b _081CB5E6
_081CB5BE:
	cmp r0, 0x2
	beq _081CB5CE
	b _081CB5E6
_081CB5C4:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CB5FA
_081CB5CE:
	movs r0, 0x5
	bl audio_play
	b _081CB5E6
_081CB5D6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB5F4
_081CB5DE:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB5E6:
	movs r0, 0
	b _081CB5FA
_081CB5EA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB5F8
_081CB5F4:
	movs r0, 0x2
	b _081CB5FA
_081CB5F8:
	movs r0, 0x4
_081CB5FA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB588

	thumb_func_start sub_81CB600
sub_81CB600: @ 81CB600
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB64E
	cmp r4, 0x1
	bgt _081CB61A
	cmp r4, 0
	beq _081CB624
	b _081CB670
_081CB61A:
	cmp r4, 0x2
	beq _081CB656
	cmp r4, 0x3
	beq _081CB662
	b _081CB670
_081CB624:
	bl sub_81C870C
	cmp r0, 0x1
	beq _081CB63C
	cmp r0, 0x1
	bgt _081CB636
	cmp r0, 0
	beq _081CB670
	b _081CB65E
_081CB636:
	cmp r0, 0x2
	beq _081CB646
	b _081CB65E
_081CB63C:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CB672
_081CB646:
	movs r0, 0x5
	bl audio_play
	b _081CB65E
_081CB64E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB66C
_081CB656:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB65E:
	movs r0, 0
	b _081CB672
_081CB662:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB670
_081CB66C:
	movs r0, 0x2
	b _081CB672
_081CB670:
	movs r0, 0x4
_081CB672:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB600

	thumb_func_start sub_81CB678
sub_81CB678: @ 81CB678
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB6C6
	cmp r4, 0x1
	bgt _081CB692
	cmp r4, 0
	beq _081CB69C
	b _081CB6E8
_081CB692:
	cmp r4, 0x2
	beq _081CB6CE
	cmp r4, 0x3
	beq _081CB6DA
	b _081CB6E8
_081CB69C:
	bl sub_81C86CC
	cmp r0, 0x1
	beq _081CB6B4
	cmp r0, 0x1
	bgt _081CB6AE
	cmp r0, 0
	beq _081CB6E8
	b _081CB6D6
_081CB6AE:
	cmp r0, 0x2
	beq _081CB6BE
	b _081CB6D6
_081CB6B4:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CB6EA
_081CB6BE:
	movs r0, 0x5
	bl audio_play
	b _081CB6D6
_081CB6C6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB6E4
_081CB6CE:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB6D6:
	movs r0, 0
	b _081CB6EA
_081CB6DA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB6E8
_081CB6E4:
	movs r0, 0x2
	b _081CB6EA
_081CB6E8:
	movs r0, 0x4
_081CB6EA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB678

	thumb_func_start sub_81CB6F0
sub_81CB6F0: @ 81CB6F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0
	beq _081CB706
	cmp r4, 0x1
	beq _081CB71C
	b _081CB72A
_081CB706:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81CBF60
	movs r0, 0x7
	bl sub_81C7BA4
	movs r0, 0
	b _081CB72C
_081CB71C:
	adds r0, r5, 0
	bl sub_81CBFC4
	cmp r0, 0
	beq _081CB72A
	movs r0, 0x2
	b _081CB72C
_081CB72A:
	movs r0, 0x4
_081CB72C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB6F0

	thumb_func_start sub_81CB734
sub_81CB734: @ 81CB734
	push {r4,lr}
	movs r0, 0x5
	bl audio_play
	movs r0, 0x6
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81CB01C
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_81CC344
	movs r0, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB734

	thumb_func_start sub_81CB75C
sub_81CB75C: @ 81CB75C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0
	beq _081CB772
	cmp r4, 0x1
	beq _081CB788
	b _081CB796
_081CB772:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81CBFF0
	movs r0, 0x6
	bl sub_81C7BA4
	movs r0, 0
	b _081CB798
_081CB788:
	adds r0, r5, 0
	bl sub_81CC004
	cmp r0, 0
	beq _081CB796
	movs r0, 0x2
	b _081CB798
_081CB796:
	movs r0, 0x4
_081CB798:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB75C

	thumb_func_start sub_81CB7A0
sub_81CB7A0: @ 81CB7A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB7D4
	cmp r4, 0x1
	bgt _081CB7BA
	cmp r4, 0
	beq _081CB7C4
	b _081CB81A
_081CB7BA:
	cmp r4, 0x2
	beq _081CB7F8
	cmp r4, 0x3
	beq _081CB80C
	b _081CB81A
_081CB7C4:
	movs r0, 0x1
	bl sub_81C9148
	adds r0, r5, 0
	bl sub_81CC058
	movs r0, 0
	b _081CB81C
_081CB7D4:
	adds r0, r5, 0
	bl sub_81CC0D0
	adds r4, r0, 0
	cmp r4, 0
	bne _081CB816
	adds r0, r5, 0
	bl sub_81CC0E0
	ldr r0, =0x00000107
	bl audio_play
	strb r4, [r5, 0xE]
	movs r0, 0
	b _081CB81C
	.pool
_081CB7F8:
	adds r0, r5, 0
	bl sub_81CC104
	cmp r0, 0
	bne _081CB816
	adds r0, r5, 0
	bl sub_81CC158
	movs r0, 0
	b _081CB81C
_081CB80C:
	adds r0, r5, 0
	bl sub_81CC194
	cmp r0, 0
	beq _081CB81A
_081CB816:
	movs r0, 0x2
	b _081CB81C
_081CB81A:
	movs r0, 0x4
_081CB81C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB7A0

	thumb_func_start sub_81CB824
sub_81CB824: @ 81CB824
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB85E
	cmp r4, 0x1
	bgt _081CB83E
	cmp r4, 0
	beq _081CB844
	b _081CB880
_081CB83E:
	cmp r4, 0x2
	beq _081CB872
	b _081CB880
_081CB844:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81CC09C
	movs r0, 0x1
	bl sub_81C9148
	movs r0, 0x1
	strb r0, [r5, 0xE]
	movs r0, 0
	b _081CB882
_081CB85E:
	adds r0, r5, 0
	bl sub_81CC0D0
	cmp r0, 0
	bne _081CB87C
	adds r0, r5, 0
	bl sub_81CC11C
	movs r0, 0
	b _081CB882
_081CB872:
	adds r0, r5, 0
	bl sub_81CC140
	cmp r0, 0
	beq _081CB880
_081CB87C:
	movs r0, 0x2
	b _081CB882
_081CB880:
	movs r0, 0x4
_081CB882:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB824

	thumb_func_start sub_81CB888
sub_81CB888: @ 81CB888
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r4, r0, 0
	movs r6, 0
	cmp r5, 0x6
	bhi _081CB934
	lsls r0, r5, 2
	ldr r1, =_081CB8A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CB8A8:
	.4byte _081CB8C4
	.4byte _081CB8DA
	.4byte _081CB8E2
	.4byte _081CB8F0
	.4byte _081CB8F8
	.4byte _081CB90C
	.4byte _081CB922
_081CB8C4:
	ldrb r0, [r4, 0xE]
	cmp r0, 0
	bne _081CB8D2
	movs r0, 0x84
	lsls r0, 1
	bl audio_play
_081CB8D2:
	movs r0, 0x5
	bl audio_play
	b _081CB934
_081CB8DA:
	adds r0, r4, 0
	bl sub_81CC1DC
	b _081CB934
_081CB8E2:
	adds r0, r4, 0
	bl sub_81CC204
	cmp r0, 0
	beq _081CB934
_081CB8EC:
	movs r6, 0x2
	b _081CB934
_081CB8F0:
	adds r0, r4, 0
	bl sub_81CBFF0
	b _081CB934
_081CB8F8:
	adds r0, r4, 0
	bl sub_81CC004
	cmp r0, 0
	beq _081CB904
	movs r6, 0x2
_081CB904:
	movs r0, 0x6
	bl sub_81C7BA4
	b _081CB934
_081CB90C:
	bl sub_81C7BE8
	cmp r0, 0
	bne _081CB8EC
	ldrb r0, [r4, 0xF]
	cmp r0, 0
	beq _081CB92C
	bl sub_81C8838
	movs r6, 0x1
	b _081CB934
_081CB922:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081CB8EC
_081CB92C:
	movs r0, 0
	bl sub_81C9148
	movs r6, 0x4
_081CB934:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB888

	thumb_func_start sub_81CB93C
sub_81CB93C: @ 81CB93C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB974
	cmp r4, 0x1
	bgt _081CB956
	cmp r4, 0
	beq _081CB960
	b _081CB9BE
_081CB956:
	cmp r4, 0x2
	beq _081CB990
	cmp r4, 0x3
	beq _081CB9A0
	b _081CB9BE
_081CB960:
	movs r0, 0x5
	bl audio_play
	bl sub_81C877C
	adds r0, r5, 0
	bl sub_81CC014
	movs r0, 0
	b _081CB9C0
_081CB974:
	bl sub_81C8820
	cmp r0, 0
	bne _081CB9BA
	adds r0, r5, 0
	bl sub_81CC004
	cmp r0, 0
	bne _081CB9BA
	movs r0, 0x8
	bl sub_81C7BA4
	movs r0, 0
	b _081CB9C0
_081CB990:
	movs r0, 0
	bl sub_81C87AC
	adds r0, r5, 0
	bl sub_81CC39C
	movs r0, 0
	b _081CB9C0
_081CB9A0:
	bl sub_81C8820
	cmp r0, 0
	bne _081CB9BA
	adds r0, r5, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CB9BA
	bl sub_81C7BE8
	cmp r0, 0
	beq _081CB9BE
_081CB9BA:
	movs r0, 0x2
	b _081CB9C0
_081CB9BE:
	movs r0, 0x4
_081CB9C0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB93C

	thumb_func_start sub_81CB9C8
sub_81CB9C8: @ 81CB9C8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x4
	bhi _081CBA60
	lsls r0, r5, 2
	ldr r1, =_081CB9E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CB9E8:
	.4byte _081CB9FC
	.4byte _081CBA1C
	.4byte _081CBA34
	.4byte _081CBA40
	.4byte _081CBA4A
_081CB9FC:
	bl sub_81C8770
	bl sub_81CB0E4
	adds r5, r0, 0
	cmp r5, 0
	beq _081CBA60
	movs r0, 0x5
	bl audio_play
	strh r5, [r4, 0x16]
	adds r0, r4, 0
	bl sub_81CC420
	movs r0, 0
	b _081CBA62
_081CBA1C:
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CBA5C
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, 0
	bl sub_81CBEF8
	movs r0, 0
	b _081CBA62
_081CBA34:
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	bl sub_81C87AC
	movs r0, 0
	b _081CBA62
_081CBA40:
	adds r0, r4, 0
	bl sub_81CC39C
	movs r0, 0
	b _081CBA62
_081CBA4A:
	bl sub_81C8820
	cmp r0, 0
	bne _081CBA5C
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	beq _081CBA60
_081CBA5C:
	movs r0, 0x2
	b _081CBA62
_081CBA60:
	movs r0, 0x4
_081CBA62:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB9C8

	thumb_func_start sub_81CBA68
sub_81CBA68: @ 81CBA68
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CBA9C
	cmp r4, 0x1
	bgt _081CBA82
	cmp r4, 0
	beq _081CBA88
	b _081CBACC
_081CBA82:
	cmp r4, 0x2
	beq _081CBABE
	b _081CBACC
_081CBA88:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81CC420
	bl sub_81C87F0
	movs r0, 0
	b _081CBACE
_081CBA9C:
	bl sub_81C8820
	cmp r0, 0
	bne _081CBAC8
	adds r0, r5, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CBAC8
	movs r0, 0x6
	bl sub_81C7BA4
	adds r0, r5, 0
	bl sub_81CBDC0
	movs r0, 0
	b _081CBACE
_081CBABE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CBACC
_081CBAC8:
	movs r0, 0x2
	b _081CBACE
_081CBACC:
	movs r0, 0x4
_081CBACE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CBA68

	thumb_func_start sub_81CBAD4
sub_81CBAD4: @ 81CBAD4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x6
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x4
	bhi _081CBB6C
	lsls r0, r5, 2
	ldr r1, =_081CBAF4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CBAF4:
	.4byte _081CBB08
	.4byte _081CBB28
	.4byte _081CBB40
	.4byte _081CBB4C
	.4byte _081CBB56
_081CBB08:
	bl sub_81C8770
	bl sub_81CB128
	adds r5, r0, 0
	cmp r5, 0
	beq _081CBB6C
	movs r0, 0x5
	bl audio_play
	strh r5, [r4, 0x16]
	adds r0, r4, 0
	bl sub_81CC420
	movs r0, 0
	b _081CBB6E
_081CBB28:
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CBB68
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, 0
	bl sub_81CBEF8
	movs r0, 0
	b _081CBB6E
_081CBB40:
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	bl sub_81C87AC
	movs r0, 0
	b _081CBB6E
_081CBB4C:
	adds r0, r4, 0
	bl sub_81CC39C
	movs r0, 0
	b _081CBB6E
_081CBB56:
	bl sub_81C8820
	cmp r0, 0
	bne _081CBB68
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	beq _081CBB6C
_081CBB68:
	movs r0, 0x2
	b _081CBB6E
_081CBB6C:
	movs r0, 0x4
_081CBB6E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CBAD4

	thumb_func_start sub_81CBB74
sub_81CBB74: @ 81CBB74
	push {lr}
	cmp r0, 0
	beq _081CBB80
	cmp r0, 0x1
	beq _081CBB9A
	b _081CBBB2
_081CBB80:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81CBC38
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081CBBB4
_081CBB9A:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CBBAA
	bl sub_81C78C0
	cmp r0, 0
	beq _081CBBAE
_081CBBAA:
	movs r0, 0x2
	b _081CBBB4
_081CBBAE:
	bl sub_81C7FDC
_081CBBB2:
	movs r0, 0x4
_081CBBB4:
	pop {r1}
	bx r1
	thumb_func_end sub_81CBB74

	thumb_func_start sub_81CBBB8
sub_81CBBB8: @ 81CBBB8
	push {lr}
	sub sp, 0x18
	bl sub_81CAE94
	str r0, [sp]
	bl sub_81CAE38
	mov r1, sp
	movs r2, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	mov r0, sp
	strh r2, [r0, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x10
	strb r0, [r1, 0xA]
	movs r0, 0x1
	strb r0, [r1, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x3
	strb r0, [r1, 0xD]
	movs r0, 0x7
	strb r0, [r1, 0xE]
	ldr r0, =sub_81CB050
	str r0, [sp, 0x10]
	ldr r0, =sub_81CBCEC
	str r0, [sp, 0x14]
	ldr r0, =gUnknown_08622794
	movs r2, 0x2
	bl sub_81C81D4
	ldr r0, =sub_81CBC64
	movs r1, 0x7
	bl CreateTask
	add sp, 0x18
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBBB8

	thumb_func_start sub_81CBC1C
sub_81CBC1C: @ 81CBC1C
	push {lr}
	bl sub_81C8234
	ldr r0, =sub_81CBC64
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBC1C

	thumb_func_start sub_81CBC38
sub_81CBC38: @ 81CBC38
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sub_81CBC64
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081CBC56
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x26]
_081CBC56:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBC38

	thumb_func_start sub_81CBC64
sub_81CBC64: @ 81CBC64
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	movs r1, 0x1E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _081CBCC8
	ldrh r0, [r2]
	adds r0, 0x4
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, =gSineTable
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x2]
	ldr r0, =gUnknown_08622720
	adds r1, r0, 0
	adds r1, 0x20
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	str r2, [sp]
	ldr r4, =gPlttBufferUnfaded + 0xA0
	str r4, [sp, 0x4]
	movs r2, 0x10
	movs r3, 0x10
	bl sub_81C79BC
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081CBCC8
	ldr r1, =gPlttBufferFaded + 0xA0
	ldr r2, =0x04000008
	adds r0, r4, 0
	bl CpuSet
_081CBCC8:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBC64

	thumb_func_start sub_81CBCEC
sub_81CBCEC: @ 81CBCEC
	push {r4-r6,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	adds r6, r0, 0
	lsls r4, 7
	adds r4, 0x3A
	adds r6, r4
	adds r0, r5, 0
	bl sub_81CAEBC
	cmp r0, 0
	beq _081CBD30
	movs r1, 0xA0
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r6]
	adds r1, r6, 0
	adds r1, 0x40
	ldr r2, =0x00005001
	adds r0, r2, 0
	strh r0, [r1]
	b _081CBD3C
	.pool
_081CBD30:
	ldr r0, =0x00005002
	adds r1, r0, 0
	strh r1, [r6]
	adds r0, r6, 0
	adds r0, 0x40
	strh r1, [r0]
_081CBD3C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBCEC

	thumb_func_start sub_81CBD48
sub_81CBD48: @ 81CBD48
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	lsls r4, 7
	adds r4, 0x3A
	adds r0, r4
	ldr r2, =0x00005002
	adds r1, r2, 0
	strh r1, [r0]
	adds r0, 0x40
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBD48

	thumb_func_start sub_81CBD78
sub_81CBD78: @ 81CBD78
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086227D8
	bl AddWindow
	strh r0, [r4, 0x10]
	ldr r0, =gUnknown_086227E0
	bl AddWindow
	strh r0, [r4, 0x12]
	ldrb r0, [r4, 0x10]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x10]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x12]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x10]
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBD78

	thumb_func_start sub_81CBDC0
sub_81CBDC0: @ 81CBDC0
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x12]
	bl sub_81CBDF4
	ldrh r0, [r4, 0x12]
	bl sub_81CBE0C
	ldrh r0, [r4, 0x12]
	bl sub_81CBE38
	ldrh r0, [r4, 0x12]
	bl sub_81CBE50
	ldrb r0, [r4, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBDC0

	thumb_func_start sub_81CBDF4
sub_81CBDF4: @ 81CBDF4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085EBE5F
	movs r2, 0
	bl sub_81CBE88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBDF4

	thumb_func_start sub_81CBE0C
sub_81CBE0C: @ 81CBE0C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CAE38
	adds r1, r0, 0
	mov r0, sp
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_81CBEB4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBE0C

	thumb_func_start sub_81CBE38
sub_81CBE38: @ 81CBE38
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085EBE6E
	movs r2, 0x2
	bl sub_81CBE88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBE38

	thumb_func_start sub_81CBE50
sub_81CBE50: @ 81CBE50
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x9
	bl sub_80847F8
	adds r1, r0, 0
	ldr r0, =0x0001869f
	cmp r1, r0
	ble _081CBE68
	adds r1, r0, 0
_081CBE68:
	mov r0, sp
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x3
	bl sub_81CBEB4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBE50

	thumb_func_start sub_81CBE88
sub_81CBE88: @ 81CBE88
	push {lr}
	sub sp, 0xC
	adds r3, r1, 0
	lsls r2, 4
	adds r2, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r3, 0
	movs r3, 0x2
	bl Print
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_81CBE88

	thumb_func_start sub_81CBEB4
sub_81CBEB4: @ 81CBEB4
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0x7
	movs r2, 0x56
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r4, 4
	adds r4, 0x1
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x7
	adds r2, r6, 0
	bl Print
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBEB4

	thumb_func_start sub_81CBEF8
sub_81CBEF8: @ 81CBEF8
	push {r4,r5,lr}
	sub sp, 0x2C
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_81C875C
	adds r0, r4
	bl sub_81CAEA4
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xD5
	beq _081CBF1C
	add r0, sp, 0xC
	movs r2, 0
	bl GetMapName
	b _081CBF24
_081CBF1C:
	ldr r1, =gUnknown_085EC00F
	add r0, sp, 0xC
	bl StringCopy
_081CBF24:
	movs r0, 0x7
	add r1, sp, 0xC
	movs r2, 0x58
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	ldrb r0, [r5, 0x10]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x10]
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x7
	add r2, sp, 0xC
	adds r3, r4, 0
	bl Print
	add sp, 0x2C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBEF8

	thumb_func_start sub_81CBF60
sub_81CBF60: @ 81CBF60
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	ldrb r0, [r5, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r4, 0
	movs r6, 0x80
	lsls r6, 17
	b _081CBF9C
_081CBF76:
	ldrb r0, [r5, 0x12]
	ldr r2, =gUnknown_086227E8
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	lsrs r1, r6, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0x10
	bl Print
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r4, 0x1
_081CBF9C:
	cmp r4, 0x2
	bhi _081CBFAE
	adds r0, r4, 0
	bl sub_81CB02C
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bne _081CBF76
_081CBFAE:
	ldrb r0, [r5, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBF60

	thumb_func_start sub_81CBFC4
sub_81CBFC4: @ 81CBFC4
	push {r4,lr}
	adds r4, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CBFD6
	movs r0, 0x1
	b _081CBFE8
_081CBFD6:
	bl sub_81CB01C
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_81CC2F0
	movs r0, 0
_081CBFE8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CBFC4

	thumb_func_start sub_81CBFF0
sub_81CBFF0: @ 81CBFF0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CC330
	adds r0, r4, 0
	bl sub_81CBDC0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBFF0

	thumb_func_start sub_81CC004
sub_81CC004: @ 81CC004
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CC004

	thumb_func_start sub_81CC014
sub_81CC014: @ 81CC014
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CC330
	ldrb r0, [r4, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC014

	thumb_func_start sub_81CC034
sub_81CC034: @ 81CC034
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08622808
	bl AddWindow
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_8197184
	bl sub_81C7B40
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC034

	thumb_func_start sub_81CC058
sub_81CC058: @ 81CC058
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_8197184
	ldrh r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_81971C4
	ldrb r0, [r4, 0x14]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x14]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x14]
	movs r1, 0x3
	bl CopyWindowToVram
	bl sub_81C7CCC
	movs r2, 0
	movs r1, 0x18
	strh r1, [r0, 0x20]
	movs r1, 0x70
	strh r1, [r0, 0x22]
	strh r2, [r0, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC058

	thumb_func_start sub_81CC09C
sub_81CC09C: @ 81CC09C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x40
	bl sub_809882C
	ldrb r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_8098858
	ldrb r0, [r4, 0x14]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x14]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x14]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC09C

	thumb_func_start sub_81CC0D0
sub_81CC0D0: @ 81CC0D0
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CC0D0

	thumb_func_start sub_81CC0E0
sub_81CC0E0: @ 81CC0E0
	push {lr}
	sub sp, 0xC
	ldrb r0, [r0, 0x14]
	ldr r2, =gUnknown_086227F4
	movs r1, 0x1
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x20
	bl Print
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC0E0

	thumb_func_start sub_81CC104
sub_81CC104: @ 81CC104
	push {r4,lr}
	adds r4, r0, 0
	bl RunTextPrinters
	ldrb r0, [r4, 0x14]
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC104

	thumb_func_start sub_81CC11C
sub_81CC11C: @ 81CC11C
	push {lr}
	sub sp, 0xC
	ldrb r0, [r0, 0x14]
	ldr r2, =gUnknown_085EBF95
	movs r1, 0x1
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC11C

	thumb_func_start sub_81CC140
sub_81CC140: @ 81CC140
	push {r4,lr}
	adds r4, r0, 0
	bl RunTextPrinters
	ldrb r0, [r4, 0x14]
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC140

	thumb_func_start sub_81CC158
sub_81CC158: @ 81CC158
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_81C875C
	adds r1, r4, 0
	adds r1, 0xF
	bl sub_81CAF78
	adds r5, r0, 0
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r4, 0x14]
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r2, 0
	adds r2, r5, 0
	movs r3, 0x20
	bl Print
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC158

	thumb_func_start sub_81CC194
sub_81CC194: @ 81CC194
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CC1B8
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _081CC1C4
	.pool
_081CC1B8:
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081CC1C4:
	bl RunTextPrinters
	ldrb r0, [r4, 0x14]
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC194

	thumb_func_start sub_81CC1DC
sub_81CC1DC: @ 81CC1DC
	push {lr}
	sub sp, 0x8
	bl sub_81C7CE4
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81CC1DC

	thumb_func_start sub_81CC204
sub_81CC204: @ 81CC204
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CC204

	thumb_func_start sub_81CC214
sub_81CC214: @ 81CC214
	push {r4-r6,lr}
	sub sp, 0x8
	movs r0, 0x6
	bl sub_81C763C
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_08622810
_081CC224:
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081CC224
	ldr r0, =gUnknown_08622818
	bl sub_81C795C
	movs r0, 0
	str r0, [r6, 0x1C]
	ldr r1, =0x00001828
	adds r0, r6, r1
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadObjectPic
	ldr r2, =0x00001824
	adds r1, r6, r2
	lsls r0, 16
	lsrs r0, 11
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [r1]
	movs r0, 0xD
	bl AllocObjectPalette
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r6, 0x1A]
	bl sub_81CC370
	str r0, [r6, 0x20]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC214

	thumb_func_start sub_81CC2B4
sub_81CC2B4: @ 81CC2B4
	push {r4,lr}
	movs r0, 0x6
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CC2C8
	bl DestroySprite
_081CC2C8:
	ldr r0, [r4, 0x20]
	cmp r0, 0
	beq _081CC2D2
	bl DestroySprite
_081CC2D2:
	movs r0, 0x8
	bl FreeObjectTilesByTag
	movs r0, 0x7
	bl FreeObjectTilesByTag
	movs r0, 0xC
	bl FreeObjectPaletteByTag
	movs r0, 0xD
	bl FreeObjectPaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC2B4

	thumb_func_start sub_81CC2F0
sub_81CC2F0: @ 81CC2F0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [r4, 0x1C]
	cmp r0, 0
	bne _081CC320
	ldr r0, =gUnknown_08622830
	movs r1, 0x4
	movs r2, 0x50
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81CC344
_081CC320:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC2F0

	thumb_func_start sub_81CC330
sub_81CC330: @ 81CC330
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	bl DestroySprite
	movs r0, 0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC330

	thumb_func_start sub_81CC344
sub_81CC344: @ 81CC344
	ldr r0, [r0, 0x1C]
	lsls r1, 4
	strh r1, [r0, 0x26]
	bx lr
	thumb_func_end sub_81CC344

	thumb_func_start sub_81CC34C
sub_81CC34C: @ 81CC34C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081CC36C
	movs r0, 0
	strh r0, [r2, 0x2E]
	ldrh r0, [r2, 0x24]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r2, 0x24]
_081CC36C:
	pop {r0}
	bx r0
	thumb_func_end sub_81CC34C

	thumb_func_start sub_81CC370
sub_81CC370: @ 81CC370
	push {lr}
	ldr r0, =gUnknown_08622850
	movs r1, 0x2C
	movs r2, 0x68
	movs r3, 0x6
	bl CreateSprite
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC370

	thumb_func_start sub_81CC39C
sub_81CC39C: @ 81CC39C
	push {r4-r7,lr}
	adds r7, r0, 0
	bl sub_81C875C
	bl sub_81CAF04
	cmp r0, 0
	blt _081CC400
	lsls r4, r0, 3
	ldr r0, =gTrainerFrontPicTable
	adds r0, r4, r0
	ldr r1, =0x00001828
	adds r5, r7, r1
	adds r1, r5, 0
	movs r2, 0
	bl DecompressPicFromTable
	ldr r0, =gTrainerFrontPicPaletteTable
	adds r4, r0
	ldr r0, [r4]
	ldr r1, =0x00002028
	adds r6, r7, r1
	adds r1, r6, 0
	bl LZ77UnCompWram
	ldr r1, =0x00001824
	adds r0, r7, r1
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r5, 0
	movs r3, 0x1
	bl RequestDma3Copy
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrh r1, [r7, 0x1A]
	adds r0, r6, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, [r7, 0x20]
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, [r7, 0x20]
	strh r4, [r0, 0x3C]
	ldr r1, [r7, 0x20]
	ldr r0, =sub_81CC440
	str r0, [r1, 0x1C]
_081CC400:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC39C

	thumb_func_start sub_81CC420
sub_81CC420: @ 81CC420
	ldr r1, [r0, 0x20]
	ldr r0, =sub_81CC4A4
	str r0, [r1, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_81CC420

	thumb_func_start sub_81CC42C
sub_81CC42C: @ 81CC42C
	ldr r0, [r0, 0x20]
	ldr r1, [r0, 0x1C]
	ldr r0, =SpriteCallbackDummy
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81CC42C

	thumb_func_start sub_81CC440
sub_81CC440: @ 81CC440
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081CC452
	cmp r0, 0x1
	beq _081CC484
	b _081CC498
_081CC452:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	bl CheckForSpaceForDma3Request
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081CC498
	ldr r0, =0x0000ffb0
	strh r0, [r4, 0x24]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081CC498
	.pool
_081CC484:
	ldrh r0, [r4, 0x24]
	adds r0, 0x8
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	blt _081CC498
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081CC498:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC440

	thumb_func_start sub_81CC4A4
sub_81CC4A4: @ 81CC4A4
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x24]
	subs r0, 0x8
	strh r0, [r3, 0x24]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x50
	negs r1, r1
	cmp r0, r1
	bgt _081CC4CA
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
_081CC4CA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC4A4

	thumb_func_start sub_81CC4D4
sub_81CC4D4: @ 81CC4D4
	push {r4,lr}
	movs r0, 0x3
	movs r1, 0x14
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CC4F0
	ldr r1, =0x00000884
	movs r0, 0x10
	bl sub_81C761C
	cmp r0, 0
	bne _081CC4F8
_081CC4F0:
	movs r0, 0
	b _081CC51A
	.pool
_081CC4F8:
	ldr r0, =gUnknown_02037318
	ldrb r0, [r0, 0x14]
	bl sub_8124668
	str r0, [r4, 0xC]
	cmp r0, 0
	bne _081CC514
	ldr r0, =sub_81CC568
	b _081CC516
	.pool
_081CC514:
	ldr r0, =sub_81CC5B4
_081CC516:
	str r0, [r4, 0x10]
	movs r0, 0x1
_081CC51A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC4D4

	thumb_func_start sub_81CC524
sub_81CC524: @ 81CC524
	push {lr}
	bl sub_8124658
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3, 0x15]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x15]
	movs r0, 0x10
	bl sub_81C7650
	movs r0, 0x3
	bl sub_81C7650
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC524

	thumb_func_start sub_81CC554
sub_81CC554: @ 81CC554
	push {lr}
	movs r0, 0x3
	bl sub_81C763C
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CC554

	thumb_func_start sub_81CC568
sub_81CC568: @ 81CC568
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _081CC58C
	cmp r0, 0x4
	bgt _081CC582
	cmp r0, 0x3
	beq _081CC588
	b _081CC5AC
_081CC582:
	cmp r0, 0x5
	beq _081CC59E
	b _081CC5AC
_081CC588:
	movs r0, 0x1
	b _081CC5AE
_081CC58C:
	bl sub_8124658
	lsls r0, 24
	cmp r0, 0
	bne _081CC59A
	movs r0, 0x3
	b _081CC5AE
_081CC59A:
	movs r0, 0x2
	b _081CC5AE
_081CC59E:
	ldr r0, =sub_81CC5DC
	str r0, [r4, 0x10]
	movs r0, 0x4
	b _081CC5AE
	.pool
_081CC5AC:
	movs r0, 0
_081CC5AE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC568

	thumb_func_start sub_81CC5B4
sub_81CC5B4: @ 81CC5B4
	push {lr}
	adds r2, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CC5CC
	movs r0, 0
	b _081CC5D2
	.pool
_081CC5CC:
	ldr r0, =sub_81CC5DC
	str r0, [r2, 0x10]
	movs r0, 0x4
_081CC5D2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC5B4

	thumb_func_start sub_81CC5DC
sub_81CC5DC: @ 81CC5DC
	ldr r0, =0x000186a1
	bx lr
	.pool
	thumb_func_end sub_81CC5DC

	thumb_func_start sub_81CC5E4
sub_81CC5E4: @ 81CC5E4
	push {lr}
	movs r0, 0x3
	bl sub_81C763C
	ldr r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81CC5E4

	thumb_func_start sub_81CC5F4
sub_81CC5F4: @ 81CC5F4
	push {r4,lr}
	ldr r1, =0x00001948
	movs r0, 0x4
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CC624
	ldr r0, =sub_81CC6F4
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CC6BC
	str r0, [r4]
	movs r0, 0x1
	b _081CC626
	.pool
_081CC624:
	movs r0, 0
_081CC626:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC5F4

	thumb_func_start sub_81CC62C
sub_81CC62C: @ 81CC62C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_086230E4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CC6BC
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC62C

	thumb_func_start sub_81CC65C
sub_81CC65C: @ 81CC65C
	push {lr}
	movs r0, 0x4
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CC65C

	thumb_func_start sub_81CC670
sub_81CC670: @ 81CC670
	push {r4,lr}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_812305C
	bl sub_81CC9EC
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x10
	bl sub_81C7650
	movs r0, 0x4
	bl sub_81C7650
	bl sub_81C760C
	movs r0, 0
	bl SetBgMode
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC670

	thumb_func_start sub_81CC6A4
sub_81CC6A4: @ 81CC6A4
	push {lr}
	bl TransferPlttBuffer
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl sub_81237B4
	pop {r0}
	bx r0
	thumb_func_end sub_81CC6A4

	thumb_func_start sub_81CC6BC
sub_81CC6BC: @ 81CC6BC
	push {lr}
	movs r0, 0x4
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6BC

	thumb_func_start sub_81CC6D0
sub_81CC6D0: @ 81CC6D0
	push {lr}
	bl sub_81CC5E4
	cmp r0, 0
	bne _081CC6EC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsrs r0, 3
	movs r1, 0x1
	ands r0, r1
	b _081CC6EE
	.pool
_081CC6EC:
	movs r0, 0
_081CC6EE:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6D0

	thumb_func_start sub_81CC6F4
sub_81CC6F4: @ 81CC6F4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x7
	bls _081CC706
	b _081CC83E
_081CC706:
	lsls r0, r4, 2
	ldr r1, =_081CC714
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CC714:
	.4byte _081CC734
	.4byte _081CC784
	.4byte _081CC7B6
	.4byte _081CC7BE
	.4byte _081CC7CE
	.4byte _081CC7E2
	.4byte _081CC804
	.4byte _081CC82A
_081CC734:
	movs r0, 0
	bl c3args_set_0toR1_1to0
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	bl SetBgMode
	ldr r4, =gUnknown_086230D8
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_81C7B54
	movs r0, 0x10
	bl sub_81C763C
	adds r5, r0, 0
	adds r4, 0x4
	bl sub_81CC6D0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8122CF8
	bl sub_81CC9C0
_081CC77C:
	movs r0, 0
	b _081CC840
	.pool
_081CC784:
	bl sub_8122DB0
	lsls r0, 24
	cmp r0, 0
	bne _081CC83A
	bl sub_81CC5E4
	cmp r0, 0
	bne _081CC7AC
	movs r0, 0x4
	movs r1, 0x9
	bl sub_8124288
	movs r0, 0x5
	movs r1, 0xA
	bl sub_81240D4
	bl sub_812454C
	b _081CC77C
_081CC7AC:
	movs r0, 0
	movs r1, 0x6
	bl sub_8123030
	b _081CC77C
_081CC7B6:
	bl sub_81CCD10
_081CC7BA:
	movs r0, 0x1
	b _081CC840
_081CC7BE:
	bl sub_81CCD24
	cmp r0, 0
	bne _081CC83A
	adds r0, r5, 0
	bl sub_81CCA1C
	b _081CC7BA
_081CC7CE:
	bl sub_81CCAFC
	cmp r0, 0
	bne _081CC83A
	adds r0, r5, 0
	bl sub_81CCB0C
	bl sub_81C7B40
	b _081CC77C
_081CC7E2:
	adds r0, r5, 0
	bl sub_81CCC4C
	cmp r0, 0
	bne _081CC83A
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =sub_81CC6A4
	bl c3args_set_0toR1_1to0
	b _081CC77C
	.pool
_081CC804:
	bl sub_81CC6D0
	lsls r0, 24
	movs r4, 0x5
	cmp r0, 0
	bne _081CC812
	movs r4, 0x4
_081CC812:
	adds r0, r4, 0
	bl sub_81C7DFC
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_81C7FA0
	movs r0, 0x1
	bl sub_81C7AC0
	b _081CC77C
_081CC82A:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CC83A
	bl sub_81C8010
	cmp r0, 0
	beq _081CC7BA
_081CC83A:
	movs r0, 0x2
	b _081CC840
_081CC83E:
	movs r0, 0x4
_081CC840:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6F4

	thumb_func_start sub_81CC848
sub_81CC848: @ 81CC848
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	cmp r4, 0
	beq _081CC85C
	cmp r4, 0x1
	beq _081CC864
	b _081CC870
_081CC85C:
	bl sub_81CCB0C
	movs r0, 0
	b _081CC872
_081CC864:
	bl sub_81CCC4C
	cmp r0, 0
	beq _081CC870
	movs r0, 0x2
	b _081CC872
_081CC870:
	movs r0, 0x4
_081CC872:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC848

	thumb_func_start sub_81CC878
sub_81CC878: @ 81CC878
	push {lr}
	cmp r0, 0x1
	beq _081CC8A2
	cmp r0, 0x1
	bgt _081CC888
	cmp r0, 0
	beq _081CC88E
	b _081CC8D0
_081CC888:
	cmp r0, 0x2
	beq _081CC8BE
	b _081CC8D0
_081CC88E:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81CCC5C
	bl sub_8123418
	movs r0, 0
	b _081CC8D2
_081CC8A2:
	bl sub_8123514
	lsls r0, 24
	cmp r0, 0
	bne _081CC8C6
	bl sub_81CCC88
	cmp r0, 0
	bne _081CC8C6
	movs r0, 0x1
	bl sub_81C7BA4
	movs r0, 0
	b _081CC8D2
_081CC8BE:
	bl sub_81C7BE8
	cmp r0, 0
	beq _081CC8CA
_081CC8C6:
	movs r0, 0x2
	b _081CC8D2
_081CC8CA:
	movs r0, 0x4
	bl sub_81C7E14
_081CC8D0:
	movs r0, 0x4
_081CC8D2:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC878

	thumb_func_start sub_81CC8D8
sub_81CC8D8: @ 81CC8D8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CC90C
	cmp r4, 0x1
	bgt _081CC8F2
	cmp r4, 0
	beq _081CC8FC
	b _081CC952
_081CC8F2:
	cmp r4, 0x2
	beq _081CC924
	cmp r4, 0x3
	beq _081CC940
	b _081CC952
_081CC8FC:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81CCB0C
	movs r0, 0
	b _081CC954
_081CC90C:
	adds r0, r5, 0
	bl sub_81CCC4C
	cmp r0, 0
	bne _081CC948
	movs r0, 0x1
	bl sub_81CCC5C
	bl sub_8123418
	movs r0, 0
	b _081CC954
_081CC924:
	bl sub_8123514
	lsls r0, 24
	cmp r0, 0
	bne _081CC948
	bl sub_81CCC88
	cmp r0, 0
	bne _081CC948
	movs r0, 0x2
	bl sub_81C7BA4
	movs r0, 0
	b _081CC954
_081CC940:
	bl sub_81C7BE8
	cmp r0, 0
	beq _081CC94C
_081CC948:
	movs r0, 0x2
	b _081CC954
_081CC94C:
	movs r0, 0x5
	bl sub_81C7E14
_081CC952:
	movs r0, 0x4
_081CC954:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC8D8

	thumb_func_start sub_81CC95C
sub_81CC95C: @ 81CC95C
	push {lr}
	cmp r0, 0x1
	beq _081CC982
	cmp r0, 0x1
	bgt _081CC96C
	cmp r0, 0
	beq _081CC972
	b _081CC9B8
_081CC96C:
	cmp r0, 0x2
	beq _081CC996
	b _081CC9B8
_081CC972:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081CC9BA
_081CC982:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CC99E
	bl sub_81C7FDC
	bl sub_81C78A0
	movs r0, 0
	b _081CC9BA
_081CC996:
	bl sub_81C78C0
	cmp r0, 0
	beq _081CC9A2
_081CC99E:
	movs r0, 0x2
	b _081CC9BA
_081CC9A2:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0
	b _081CC9BA
_081CC9B8:
	movs r0, 0x4
_081CC9BA:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC95C

	thumb_func_start sub_81CC9C0
sub_81CC9C0: @ 81CC9C0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_086230F8
_081CC9C6:
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081CC9C6
	ldr r0, =gUnknown_08623100
	bl sub_81C795C
	bl sub_81CCE58
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC9C0

	thumb_func_start sub_81CC9EC
sub_81CC9EC: @ 81CC9EC
	push {r4,r5,lr}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x6
	bl FreeObjectTilesByTag
	movs r0, 0xB
	bl FreeObjectPaletteByTag
	adds r5, r4, 0
	adds r5, 0xC
	movs r4, 0x2
_081CCA08:
	ldm r5!, {r0}
	bl DestroySprite
	subs r4, 0x1
	cmp r4, 0
	bge _081CCA08
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC9EC

	thumb_func_start sub_81CCA1C
sub_81CCA1C: @ 81CCA1C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x40
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0x1
	movs r1, 0x11
	movs r2, 0x41
	movs r3, 0x1
	bl sub_8199DF0
	add r1, sp, 0x4
	movs r2, 0x82
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	adds r4, r5, 0
	adds r4, 0x18
	ldr r2, =0x01000400
	adds r0, r1, 0
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0x1
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_08623110
	bl AddWindow
	movs r4, 0
	strh r0, [r5, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x42
	movs r2, 0x40
	bl box_border_load_tiles_and_pal
	ldrb r0, [r5, 0x8]
	movs r1, 0x42
	movs r2, 0x4
	bl sub_8098858
	ldr r1, =gUnknown_08622888
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldrb r0, [r5, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r5, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_08622868
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =gUnknown_08DC91E8
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	bl sub_8124658
	lsls r0, 24
	cmp r0, 0
	bne _081CCAE0
	ldr r1, =0xffffa000
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgY
	b _081CCAEA
	.pool
_081CCAE0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
_081CCAEA:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCA1C

	thumb_func_start sub_81CCAFC
sub_81CCAFC: @ 81CCAFC
	push {lr}
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CCAFC

	thumb_func_start sub_81CCB0C
sub_81CCB0C: @ 81CCB0C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0x10
	bl sub_81C763C
	adds r5, r0, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x4
	bls _081CCB22
	b _081CCC40
_081CCB22:
	lsls r0, 2
	ldr r1, =_081CCB30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CCB30:
	.4byte _081CCC1C
	.4byte _081CCBDC
	.4byte _081CCB44
	.4byte _081CCB8E
	.4byte _081CCBDC
_081CCB44:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl PutWindowRectTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl Print
	ldrh r1, [r5]
	ldrb r2, [r5, 0x3]
	adds r0, r4, 0
	bl sub_81CCD70
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl sub_81CCFA4
	b _081CCC40
_081CCB8E:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl PutWindowRectTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl Print
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x6
	bl FillBgTilemapBufferRect
	b _081CCC0C
	.pool
_081CCBDC:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl Print
	ldrh r1, [r5]
	ldrb r2, [r5, 0x3]
	adds r0, r4, 0
	bl sub_81CCDE8
_081CCC0C:
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl sub_81CCFA4
	b _081CCC40
_081CCC1C:
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xD
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x4
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl sub_81CCFA4
_081CCC40:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCB0C

	thumb_func_start sub_81CCC4C
sub_81CCC4C: @ 81CCC4C
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CCC4C

	thumb_func_start sub_81CCC5C
sub_81CCC5C: @ 81CCC5C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sub_81CCC9C
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCC5C

	thumb_func_start sub_81CCC88
sub_81CCC88: @ 81CCC88
	push {lr}
	ldr r0, =sub_81CCC9C
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCC88

	thumb_func_start sub_81CCC9C
sub_81CCC9C: @ 81CCC9C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081CCCE0
	movs r1, 0x90
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x1
	bl ChangeBgY
	cmp r0, 0
	blt _081CCCD6
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	adds r0, r4, 0
	bl DestroyTask
_081CCCD6:
	bl sub_81CCF78
	b _081CCD04
	.pool
_081CCCE0:
	movs r1, 0x90
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgY
	ldr r1, =0xffffa000
	cmp r0, r1
	bgt _081CCD00
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgY
	adds r0, r5, 0
	bl DestroyTask
_081CCD00:
	bl sub_81CCF78
_081CCD04:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCC9C

	thumb_func_start sub_81CCD10
sub_81CCD10: @ 81CCD10
	push {lr}
	ldr r0, =sub_81CCD34
	movs r1, 0x1
	bl sub_81C7078
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCD10

	thumb_func_start sub_81CCD24
sub_81CCD24: @ 81CCD24
	push {lr}
	ldr r0, =sub_81CCD34
	bl sub_81C7124
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCD24

	thumb_func_start sub_81CCD34
sub_81CCD34: @ 81CCD34
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r2, r0, 0
	cmp r4, 0x15
	ble _081CCD48
	movs r0, 0x4
	b _081CCD62
_081CCD48:
	ldr r0, =gUnknown_08623118
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	movs r1, 0xC8
	muls r1, r4
	ldr r3, =0x00000818
	adds r1, r3
	adds r1, r2, r1
	bl LZ77UnCompWram
	movs r0, 0x1
_081CCD62:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCD34

	thumb_func_start sub_81CCD70
sub_81CCD70: @ 81CCD70
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r3, r1, 0
	movs r4, 0
	ldr r0, =gUnknown_08623118
	ldrh r1, [r0]
	adds r5, r0, 0
	cmp r1, r3
	bne _081CCD8A
	ldrh r0, [r5, 0x2]
	cmp r0, r2
	beq _081CCDA0
_081CCD8A:
	adds r4, 0x1
	cmp r4, 0x15
	bgt _081CCDA0
	lsls r0, r4, 3
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, r3
	bne _081CCD8A
	ldrh r0, [r1, 0x2]
	cmp r0, r2
	bne _081CCD8A
_081CCDA0:
	cmp r4, 0x16
	beq _081CCDD4
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x6
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0xC8
	adds r1, r4, 0
	muls r1, r0
	ldr r0, =0x00000818
	adds r1, r0
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x12
	movs r3, 0x6
	bl CopyToBgTilemapBufferRect
_081CCDD4:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCD70

	thumb_func_start sub_81CCDE8
sub_81CCDE8: @ 81CCDE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	mov r9, r0
	movs r5, 0
	ldr r6, =gStringVar1
	movs r4, 0x88
	lsls r4, 21
	lsls r1, 24
	mov r8, r1
	lsls r7, r2, 24
	b _081CCE34
	.pool
_081CCE08:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	mov r1, r9
	ldrb r0, [r1, 0x8]
	lsrs r1, r4, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r6, 0
	movs r3, 0
	bl Print
	movs r0, 0x80
	lsls r0, 21
	adds r4, r0
	adds r5, 0x1
_081CCE34:
	lsls r2, r5, 24
	lsrs r2, 24
	mov r1, r8
	lsrs r0, r1, 24
	lsrs r1, r7, 24
	bl sub_8145CF4
	adds r1, r0, 0
	cmp r1, 0
	bne _081CCE08
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCDE8

	thumb_func_start sub_81CCE58
sub_81CCE58: @ 81CCE58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_8124658
	lsls r0, 24
	movs r2, 0x84
	cmp r0, 0
	bne _081CCE74
	movs r2, 0xE4
_081CCE74:
	movs r5, 0
	lsls r7, r2, 16
	adds r4, 0xC
	mov r8, r4
	movs r6, 0x98
	lsls r6, 16
_081CCE80:
	asrs r1, r6, 16
	ldr r0, =gUnknown_086231D0
	asrs r2, r7, 16
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	movs r0, 0
	strh r0, [r2, 0x2E]
	lsls r4, r5, 2
	strh r4, [r2, 0x30]
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r0, r1, 22
	adds r1, r0, 0
	strh r0, [r2, 0x32]
	movs r0, 0x96
	strh r0, [r2, 0x34]
	strh r4, [r2, 0x36]
	adds r1, r4
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r3, r0
	orrs r3, r1
	strh r3, [r2, 0x4]
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r2}
	movs r4, 0x80
	lsls r4, 14
	adds r6, r4
	adds r5, 0x1
	cmp r5, 0x2
	ble _081CCE80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCE58

	thumb_func_start sub_81CCEF4
sub_81CCEF4: @ 81CCEF4
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x34]
	movs r1, 0x34
	ldrsh r4, [r3, r1]
	cmp r4, 0
	beq _081CCF06
	subs r0, 0x1
	b _081CCF6E
_081CCF06:
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _081CCF16
	strh r4, [r3, 0x2E]
_081CCF16:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081CCF26
	strh r4, [r3, 0x30]
_081CCF26:
	ldrh r5, [r3, 0x30]
	ldrh r2, [r3, 0x32]
	adds r1, r5, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x38]
	movs r2, 0x38
	ldrsh r0, [r3, r2]
	cmp r0, 0x3
	bgt _081CCF5C
	movs r2, 0x2E
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _081CCF70
	adds r0, r1, 0x1
	strh r0, [r3, 0x38]
	b _081CCF6C
	.pool
_081CCF5C:
	lsls r0, r5, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bne _081CCF70
	strh r4, [r3, 0x38]
	strh r4, [r3, 0x2E]
_081CCF6C:
	movs r0, 0x78
_081CCF6E:
	strh r0, [r3, 0x34]
_081CCF70:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCEF4

	thumb_func_start sub_81CCF78
sub_81CCF78: @ 81CCF78
	push {r4,lr}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x1
	bl GetBgY
	asrs r0, 8
	movs r1, 0x84
	subs r1, r0
	adds r4, 0xC
	movs r2, 0x2
_081CCF92:
	ldm r4!, {r0}
	strh r1, [r0, 0x22]
	subs r2, 0x1
	cmp r2, 0
	bge _081CCF92
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCF78

	thumb_func_start sub_81CCFA4
sub_81CCFA4: @ 81CCFA4
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	movs r1, 0x1
	ands r4, r1
	lsls r5, r4, 2
	movs r6, 0x5
	negs r6, r6
	adds r4, r0, 0
	adds r4, 0xC
	movs r3, 0x2
_081CCFBE:
	ldm r4!, {r0}
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r6, 0
	ands r1, r2
	orrs r1, r5
	strb r1, [r0]
	subs r3, 0x1
	cmp r3, 0
	bge _081CCFBE
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCFA4

	thumb_func_start sub_81CCFD8
sub_81CCFD8: @ 81CCFD8
	push {r4,lr}
	ldr r1, =0x0000678c
	movs r0, 0xB
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CD01C
	ldr r1, =0x00006428
	adds r0, r4, r1
	bl sub_81D1ED4
	bl sub_81CD970
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r0, 0x1
	b _081CD01E
	.pool
_081CD01C:
	movs r0, 0
_081CD01E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CCFD8

	thumb_func_start sub_81CD024
sub_81CD024: @ 81CD024
	push {r4,lr}
	ldr r1, =0x0000678c
	movs r0, 0xB
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CD068
	ldr r1, =0x00006428
	adds r0, r4, r1
	bl sub_81D1ED4
	bl sub_81CD9F8
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r0, 0x1
	b _081CD06A
	.pool
_081CD068:
	movs r0, 0
_081CD06A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD024

	thumb_func_start sub_81CD070
sub_81CD070: @ 81CD070
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r2, =0x00006304
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD070

	thumb_func_start sub_81CD08C
sub_81CD08C: @ 81CD08C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r5, r0, 0
	adds r0, r4, 0
	bl sub_81CD1E4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _081CD100
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CD0D0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CD100
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CD0F0
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bne _081CD100
_081CD0D0:
	movs r0, 0x5
	bl audio_play
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD19C
	str r0, [r1]
	movs r2, 0x2
	b _081CD100
	.pool
_081CD0F0:
	movs r0, 0x5
	bl audio_play
	movs r2, 0x5
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD110
	str r0, [r1]
_081CD100:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD08C

	thumb_func_start sub_81CD110
sub_81CD110: @ 81CD110
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	movs r4, 0
	bl sub_811FBA4
	lsls r0, 24
	cmp r0, 0
	bne _081CD18A
	bl sub_81CEF14
	ldr r1, =0x00006786
	adds r5, r6, r1
	movs r1, 0
	ldrsb r1, [r5, r1]
	ldr r2, =0x00006783
	adds r4, r6, r2
	adds r1, r4, r1
	strb r0, [r1]
	movs r0, 0x12
	bl sub_81C763C
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	ldrb r3, [r0, 0x5]
	movs r0, 0
	ldrsb r0, [r5, r0]
	adds r4, r0
	ldrb r1, [r4]
	mov r0, sp
	strb r1, [r0]
	cmp r2, 0xE
	bne _081CD174
	movs r0, 0x64
	muls r0, r3
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x8
	mov r2, sp
	bl SetMonData
	b _081CD180
	.pool
_081CD174:
	adds r0, r2, 0
	adds r1, r3, 0
	movs r2, 0x8
	mov r3, sp
	bl set_pokemon_data_from_any_box
_081CD180:
	ldr r0, =0x00006304
	adds r1, r6, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r4, 0x6
_081CD18A:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD110

	thumb_func_start sub_81CD19C
sub_81CD19C: @ 81CD19C
	push {lr}
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD1B4
	ldr r0, =0x000186aa
	b _081CD1B6
	.pool
_081CD1B4:
	ldr r0, =0x000186a2
_081CD1B6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD19C

	thumb_func_start sub_81CD1C0
sub_81CD1C0: @ 81CD1C0
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CD1DA
	movs r0, 0x12
	bl sub_81C7650
_081CD1DA:
	movs r0, 0xB
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CD1C0

	thumb_func_start sub_81CD1E4
sub_81CD1E4: @ 81CD1E4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r2, r0, 0
	movs r3, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CD220
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD210
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	beq _081CD24E
_081CD210:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	b _081CD246
	.pool
_081CD220:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CD24E
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD23E
	ldrh r1, [r2, 0x2]
	ldrh r0, [r2]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD24E
_081CD23E:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
_081CD246:
	bl sub_81CD258
	lsls r0, 24
	lsrs r3, r0, 24
_081CD24E:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD1E4

	thumb_func_start sub_81CD258
sub_81CD258: @ 81CD258
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0xB
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r5, r0, 0
	mov r0, r8
	cmp r0, 0
	beq _081CD284
	ldr r1, =0x00006788
	adds r0, r4, r1
	b _081CD288
	.pool
_081CD284:
	ldr r2, =0x00006787
	adds r0, r4, r2
_081CD288:
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	adds r7, r0, 0
	ldr r1, =0x00006428
	adds r0, r4, r1
	ldr r2, =0x00006786
	adds r1, r4, r2
	movs r2, 0
	ldrsb r2, [r1, r2]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	ldr r3, =0x0000643c
	adds r1, r3
	adds r1, r4, r1
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 2
	adds r2, r3
	adds r2, r4, r2
	bl sub_81D1F84
	ldrh r6, [r5, 0x2]
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD2D8
	ldrh r1, [r5]
	b _081CD2DC
	.pool
_081CD2D8:
	ldrh r1, [r5]
	subs r1, 0x1
_081CD2DC:
	eors r1, r6
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	adds r6, r0, 0
	mov r0, r8
	cmp r0, 0
	beq _081CD332
	ldr r1, =0x00006787
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r1, 0x1
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, =0x00006786
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, =0x00006789
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r0, [r5, 0x2]
	cmp r0, 0
	bne _081CD312
	ldrh r0, [r5]
_081CD312:
	subs r1, r0, 0x1
	strh r1, [r5, 0x2]
	lsls r0, r1, 16
	cmp r0, 0
	beq _081CD32C
	subs r1, 0x1
	b _081CD384
	.pool
_081CD32C:
	ldrh r0, [r5]
	subs r1, r0, 0x1
	b _081CD384
_081CD332:
	ldr r0, =0x00006788
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r1, =0x00006787
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, =0x00006786
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, =0x00006789
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD370
	adds r0, r1, 0x1
	b _081CD372
	.pool
_081CD370:
	movs r0, 0
_081CD372:
	strh r0, [r5, 0x2]
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD382
	adds r1, 0x1
	b _081CD384
_081CD382:
	movs r1, 0
_081CD384:
	ldr r2, =0x00006302
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r4, [r5, 0x2]
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD39C
	ldrh r1, [r5]
	b _081CD3A0
	.pool
_081CD39C:
	ldrh r1, [r5]
	subs r1, 0x1
_081CD3A0:
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	cmp r6, 0
	bne _081CD3B0
	movs r0, 0x3
	b _081CD3BA
_081CD3B0:
	cmp r0, 0
	beq _081CD3B8
	movs r0, 0x1
	b _081CD3BA
_081CD3B8:
	movs r0, 0x4
_081CD3BA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD258

	thumb_func_start sub_81CD3C4
sub_81CD3C4: @ 81CD3C4
	push {r4,lr}
	movs r0, 0xB
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r2, r0, 0
	ldr r1, =0x0000678a
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _081CD3E2
	b _081CD530
_081CD3E2:
	lsls r0, 2
	ldr r1, =_081CD3F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CD3F4:
	.4byte _081CD41C
	.4byte _081CD428
	.4byte _081CD434
	.4byte _081CD440
	.4byte _081CD490
	.4byte _081CD4A8
	.4byte _081CD4C0
	.4byte _081CD4D8
	.4byte _081CD4F0
	.4byte _081CD508
_081CD41C:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CD824
	b _081CD530
_081CD428:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CDA1C
	b _081CD530
_081CD434:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CDB98
	b _081CD530
_081CD440:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _081CD468
	ldr r2, =0x00006786
	adds r0, r4, r2
	movs r1, 0
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, 0x1
	b _081CD53C
	.pool
_081CD468:
	ldr r0, =0x00006786
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	ldr r2, =0x00006787
	adds r1, r4, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x00006788
	adds r1, r4, r0
	movs r0, 0x2
	strb r0, [r1]
	b _081CD530
	.pool
_081CD490:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD49C
	movs r0, 0
_081CD49C:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CD824
	b _081CD530
_081CD4A8:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD4B4
	movs r0, 0
_081CD4B4:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CDA1C
	b _081CD530
_081CD4C0:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD4CC
	movs r0, 0
_081CD4CC:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CDB98
	b _081CD530
_081CD4D8:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD4E4
	ldrh r0, [r2]
	subs r0, 0x1
_081CD4E4:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CD824
	b _081CD530
_081CD4F0:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD4FC
	ldrh r0, [r2]
	subs r0, 0x1
_081CD4FC:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CDA1C
	b _081CD530
_081CD508:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD514
	ldrh r0, [r2]
	subs r0, 0x1
_081CD514:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CDB98
	ldr r2, =0x0000678a
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CD53C
	.pool
_081CD530:
	ldr r0, =0x0000678a
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
_081CD53C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD3C4

	thumb_func_start sub_81CD548
sub_81CD548: @ 81CD548
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r0, 0xB
	bl sub_81C763C
	adds r1, r0, 0
	cmp r4, 0x1
	beq _081CD588
	cmp r4, 0x1
	bgt _081CD566
	cmp r4, 0
	beq _081CD56C
	b _081CD5C4
_081CD566:
	cmp r5, 0x2
	beq _081CD5A4
	b _081CD5C4
_081CD56C:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CD824
	b _081CD5C4
	.pool
_081CD588:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CDA1C
	b _081CD5C4
	.pool
_081CD5A4:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CDB98
	movs r0, 0x1
	b _081CD5C6
	.pool
_081CD5C4:
	movs r0, 0
_081CD5C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD548

	thumb_func_start sub_81CD5CC
sub_81CD5CC: @ 81CD5CC
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081CD5E4
_081CD5D6:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081CD5E4:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081CD5D6
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081CD612
	movs r3, 0
_081CD5FE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081CD5FE
_081CD612:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD5CC

	thumb_func_start sub_81CD624
sub_81CD624: @ 81CD624
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r0, 0x12
	bl sub_81C763C
	lsls r4, 2
	adds r0, r4
	ldrb r4, [r0, 0x4]
	mov r8, r4
	ldrb r6, [r0, 0x5]
	mov r9, r6
	movs r0, 0xFC
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x4
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x8
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x9
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2D
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0
	beq _081CD690
	ldr r1, =gUnknown_085E8264
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081CD80E
	.pool
_081CD690:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_81D2C68
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81D2C68
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081CD6E0
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	bl pokemon_get_gender
	lsls r0, 24
	lsrs r6, r0, 24
	b _081CD6FE
	.pool
_081CD6E0:
	mov r0, r8
	mov r1, r9
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	bl pokemon_roll_gender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	bl sub_80690C0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_081CD6FE:
	cmp r7, 0x1D
	beq _081CD706
	cmp r7, 0x20
	bne _081CD71C
_081CD706:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081CD71C
	movs r6, 0xFF
_081CD71C:
	adds r3, r5, 0
	b _081CD726
	.pool
_081CD724:
	adds r3, 0x1
_081CD726:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081CD724
	movs r1, 0xFC
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x12
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x3C
	strb r0, [r3]
	adds r3, 0x1
	cmp r6, 0
	beq _081CD74A
	cmp r6, 0xFE
	beq _081CD76E
	movs r0, 0x77
	b _081CD790
_081CD74A:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB5
	b _081CD790
_081CD76E:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x6
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x7
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB6
_081CD790:
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x8
	strb r0, [r3]
	adds r3, 0x1
	movs r5, 0
	strb r5, [r3]
	adds r3, 0x1
	movs r0, 0x9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xBA
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xF9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	adds r4, r3, 0
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	subs r4, r3, r4
	lsls r4, 16
	lsrs r4, 16
	strb r5, [r3]
	adds r3, 0x1
	mov r0, r10
	cmp r0, 0
	bne _081CD808
	movs r0, 0x3
	subs r0, r4
	lsls r0, 16
	ldr r1, =0xffff0000
	adds r0, r1
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _081CD808
	movs r2, 0
	adds r1, r0, 0
_081CD7FA:
	strb r2, [r3]
	adds r3, 0x1
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r1
	bne _081CD7FA
_081CD808:
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081CD80E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD624

	thumb_func_start sub_81CD824
sub_81CD824: @ 81CD824
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r0, 0xB
	bl sub_81C763C
	adds r5, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r7, r0, 0
	mov r1, r8
	lsls r0, r1, 16
	asrs r4, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD85A
	ldrh r2, [r7]
	cmp r4, r2
	bne _081CD862
	b _081CD900
_081CD85A:
	ldrh r0, [r7]
	subs r0, 0x1
	cmp r4, r0
	beq _081CD900
_081CD862:
	lsls r0, r6, 6
	ldr r1, =0x00006368
	adds r0, r1
	adds r0, r5, r0
	mov r2, r8
	lsls r4, r2, 16
	lsrs r1, r4, 16
	movs r2, 0
	bl sub_81CD624
	asrs r4, 14
	adds r4, r7, r4
	ldrb r3, [r4, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r4, r0, 3
	ldr r1, =0x00006320
	adds r0, r5, r1
	adds r0, r4
	movs r2, 0
	movs r1, 0xFC
	strb r1, [r0]
	ldr r1, =0x00006321
	adds r0, r5, r1
	adds r0, r4
	movs r1, 0x4
	strb r1, [r0]
	ldr r1, =0x00006322
	adds r0, r5, r1
	adds r0, r4
	movs r1, 0x8
	strb r1, [r0]
	ldr r1, =0x00006323
	adds r0, r5, r1
	adds r0, r4
	strb r2, [r0]
	ldr r2, =0x00006324
	adds r0, r5, r2
	adds r0, r4
	movs r1, 0x9
	strb r1, [r0]
	cmp r3, 0xE
	bne _081CD8E4
	adds r0, r4, r5
	ldr r1, =0x00006325
	adds r0, r1
	ldr r1, =gUnknown_085EBFCE
	b _081CD8F4
	.pool
_081CD8E4:
	adds r4, r5
	ldr r2, =0x00006325
	adds r4, r2
	adds r0, r3, 0
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
_081CD8F4:
	movs r2, 0x8
	bl sub_81CD5CC
	b _081CD95C
	.pool
_081CD900:
	movs r1, 0
	lsls r4, r6, 6
	lsls r0, r6, 1
	mov r8, r0
	adds r3, r4, 0
	ldr r0, =0x00006368
	adds r2, r5, r0
	movs r7, 0
_081CD910:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r7, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081CD910
	adds r1, r4
	ldr r2, =0x00006368
	adds r0, r5, r2
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r1, 0
	mov r2, r8
	adds r0, r2, r6
	lsls r3, r0, 3
	ldr r0, =0x00006320
	adds r2, r5, r0
	movs r4, 0
_081CD93A:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081CD93A
	mov r2, r8
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1, r0
	ldr r2, =0x00006320
	adds r1, r5, r2
	adds r1, r0
	movs r0, 0xFF
	strb r0, [r1]
_081CD95C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD824

	thumb_func_start sub_81CD970
sub_81CD970: @ 81CD970
	push {r4-r7,lr}
	movs r0, 0xB
	bl sub_81C763C
	adds r7, r0, 0
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl sub_81C761C
	adds r6, r0, 0
	movs r0, 0xC6
	lsls r0, 7
	adds r1, r7, r0
	movs r0, 0
	strb r0, [r1]
	movs r4, 0
	movs r5, 0
	b _081CD9C4
	.pool
_081CD998:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r2, r0, 0
	cmp r2, 0
	bne _081CD9BE
	lsls r1, r5, 2
	adds r1, r6, r1
	movs r0, 0xE
	strb r0, [r1, 0x4]
	strb r4, [r1, 0x5]
	strh r2, [r1, 0x6]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_081CD9BE:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081CD9C4:
	bl calc_player_party_count
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _081CD998
	lsls r0, r5, 2
	adds r0, r6, r0
	movs r1, 0
	strb r1, [r0, 0x4]
	strb r1, [r0, 0x5]
	movs r2, 0
	strh r1, [r0, 0x6]
	strh r1, [r6, 0x2]
	adds r0, r5, 0x1
	strh r0, [r6]
	ldr r1, =0x0000678a
	adds r0, r7, r1
	strb r2, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD970

	thumb_func_start sub_81CD9F8
sub_81CD9F8: @ 81CD9F8
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	movs r1, 0xC6
	lsls r1, 7
	adds r2, r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r2]
	ldr r1, =0x0000678a
	adds r0, r1
	strb r3, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD9F8

	thumb_func_start sub_81CDA1C
sub_81CDA1C: @ 81CDA1C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0xB
	bl sub_81C763C
	mov r8, r0
	movs r0, 0x12
	bl sub_81C763C
	adds r4, r0, 0
	lsls r0, r6, 16
	asrs r5, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CDA52
	ldrh r0, [r4]
	cmp r5, r0
	bne _081CDA5A
	b _081CDB48
_081CDA52:
	ldrh r0, [r4]
	subs r0, 0x1
	cmp r5, r0
	beq _081CDB48
_081CDA5A:
	lsls r0, r6, 16
	asrs r0, 14
	adds r0, r4, r0
	ldrb r6, [r0, 0x4]
	ldrb r7, [r0, 0x5]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x16
	movs r3, 0
	bl sub_81D2C68
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	ldr r1, =0x00006428
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x2F
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x00006429
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x21
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x0000642a
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x18
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x0000642b
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x17
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x0000642c
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	movs r0, 0xCF
	lsls r0, 7
	add r0, r8
	mov r2, r9
	adds r4, r0, r2
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _081CDB10
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	movs r1, 0x1D
	bl __udivsi3
	b _081CDB12
	.pool
_081CDB10:
	movs r0, 0x9
_081CDB12:
	strb r0, [r4]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x8
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x00006783
	add r1, r8
	add r1, r9
	strb r0, [r1]
	mov r0, r9
	adds r1, r5, r0
	ldr r2, =0x00006428
	adds r0, r1, r2
	add r0, r8
	lsls r1, 2
	adds r2, 0x14
	adds r1, r2
	add r1, r8
	bl sub_81D2754
	b _081CDB80
	.pool
_081CDB48:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	add r5, r9
	ldr r4, =0x00006428
	add r4, r8
	lsls r3, r5, 2
	mov r9, r2
	ldr r7, =0x0000643c
	movs r6, 0x9B
_081CDB5C:
	adds r0, r2, r5
	adds r0, r4, r0
	mov r1, r9
	strb r1, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	adds r1, r0, r7
	strh r6, [r1]
	ldr r1, =0x0000643e
	adds r0, r1
	movs r1, 0x5B
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081CDB5C
_081CDB80:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDA1C

	thumb_func_start sub_81CDB98
sub_81CDB98: @ 81CDB98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0xB
	bl sub_81C763C
	adds r7, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r4, r0, 0
	lsls r0, r6, 16
	asrs r5, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CDBCC
	ldrh r0, [r4]
	b _081CDBD0
_081CDBCC:
	ldrh r0, [r4]
	subs r0, 0x1
_081CDBD0:
	cmp r5, r0
	beq _081CDC3E
	lsls r0, r6, 16
	asrs r0, 14
	adds r0, r4, r0
	ldrb r5, [r0, 0x4]
	ldrb r6, [r0, 0x5]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x41
	movs r3, 0
	bl sub_81D2C68
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_81D2C68
	mov r8, r0
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_81D2C68
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	mov r2, r9
	lsls r1, r2, 13
	movs r2, 0xC0
	lsls r2, 2
	adds r1, r2
	adds r1, r7, r1
	movs r2, 0x1
	str r2, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl DecompressMonPic
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl species_and_otid_get_pal
	mov r2, r9
	lsls r1, r2, 7
	adds r1, r7, r1
	bl LZ77UnCompWram
_081CDC3E:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDB98

	thumb_func_start sub_81CDC50
sub_81CDC50: @ 81CDC50
	push {lr}
	movs r0, 0x12
	bl sub_81C763C
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDC50

	thumb_func_start sub_81CDC60
sub_81CDC60: @ 81CDC60
	push {lr}
	movs r0, 0x12
	bl sub_81C763C
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDC60

	thumb_func_start sub_81CDC70
sub_81CDC70: @ 81CDC70
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006428
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC70

	thumb_func_start sub_81CDC84
sub_81CDC84: @ 81CDC84
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006786
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC84

	thumb_func_start sub_81CDC9C
sub_81CDC9C: @ 81CDC9C
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006302
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC9C

	thumb_func_start sub_81CDCB4
sub_81CDCB4: @ 81CDCB4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r4, 13
	movs r1, 0xC0
	lsls r1, 2
	adds r4, r1
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDCB4

	thumb_func_start sub_81CDCD4
sub_81CDCD4: @ 81CDCD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r4, 7
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDCD4

	thumb_func_start sub_81CDCEC
sub_81CDCEC: @ 81CDCEC
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006789
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDCEC

	thumb_func_start sub_81CDD04
sub_81CDD04: @ 81CDD04
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r4, 6
	ldr r1, =0x00006368
	adds r4, r1
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD04

	thumb_func_start sub_81CDD24
sub_81CDD24: @ 81CDD24
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	ldr r2, =0x00006320
	adds r1, r2
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD24

	thumb_func_start sub_81CDD48
sub_81CDD48: @ 81CDD48
	push {lr}
	movs r0, 0x12
	bl sub_81C763C
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDD48

	thumb_func_start sub_81CDD5C
sub_81CDD5C: @ 81CDD5C
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CDD74
	movs r0, 0
	b _081CDD76
_081CDD74:
	movs r0, 0x1
_081CDD76:
	pop {r1}
	bx r1
	thumb_func_end sub_81CDD5C

	thumb_func_start sub_81CDD7C
sub_81CDD7C: @ 81CDD7C
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	adds r2, r0, 0
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CDD96
	movs r0, 0
	b _081CDDA6
_081CDD96:
	ldr r3, =0x00006786
	adds r0, r2, r3
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r3, 0x3
	adds r0, r2, r3
	adds r0, r1
	ldrb r0, [r0]
_081CDDA6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD7C

	thumb_func_start sub_81CDDB0
sub_81CDDB0: @ 81CDDB0
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r2, =0x00006786
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r2, 0x6
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDDB0

	thumb_func_start sub_81CDDD4
sub_81CDDD4: @ 81CDDD4
	push {r4,lr}
	ldr r1, =0x000038ac
	movs r0, 0xC
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CDE24
	ldr r0, =0x00001816
	adds r1, r4, r0
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, =sub_81CDE94
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4]
	ldr r0, =0x00001810
	adds r1, r4, r0
	ldr r0, =sub_81CDE80
	str r0, [r1]
	ldr r0, =0x00002908
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CDE26
	.pool
_081CDE24:
	movs r0, 0
_081CDE26:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDDD4

	thumb_func_start sub_81CDE2C
sub_81CDE2C: @ 81CDE2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08623384
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5]
	ldr r0, =0x00001810
	adds r5, r0
	ldr r0, =sub_81CDE80
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDE2C

	thumb_func_start sub_81CDE64
sub_81CDE64: @ 81CDE64
	push {lr}
	movs r0, 0xC
	bl sub_81C763C
	ldr r1, =0x00001810
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDE64

	thumb_func_start sub_81CDE80
sub_81CDE80: @ 81CDE80
	push {lr}
	movs r0, 0xC
	bl sub_81C763C
	ldr r0, [r0]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CDE80

	thumb_func_start sub_81CDE94
sub_81CDE94: @ 81CDE94
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x14
	bls _081CDEA8
	b _081CE2C4
_081CDEA8:
	lsls r0, r4, 2
	ldr r1, =_081CDEB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CDEB8:
	.4byte _081CDF0C
	.4byte _081CDF18
	.4byte _081CDF94
	.4byte _081CDFB8
	.4byte _081CE030
	.4byte _081CE074
	.4byte _081CE0B0
	.4byte _081CE118
	.4byte _081CE120
	.4byte _081CE126
	.4byte _081CE136
	.4byte _081CE146
	.4byte _081CE156
	.4byte _081CE16C
	.4byte _081CE1C8
	.4byte _081CE1EC
	.4byte _081CE218
	.4byte _081CE23C
	.4byte _081CE24A
	.4byte _081CE25A
	.4byte _081CE262
_081CDF0C:
	bl sub_81CD3C4
	cmp r0, 0x1
	beq _081CDF16
	b _081CE2C0
_081CDF16:
	b _081CDFB0
_081CDF18:
	ldr r0, =gUnknown_08623358
	movs r1, 0x3
	bl sub_81C7B54
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r1, =0x00007940
	movs r0, 0
	bl SetGpuReg
	ldr r1, =0x00000844
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000040b
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =gUnknown_08DC6548
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	b _081CDFA8
	.pool
_081CDF94:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081CDFA2
	b _081CE2C0
_081CDFA2:
	ldr r1, =gUnknown_08623228
	str r0, [sp]
	movs r0, 0x2
_081CDFA8:
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081CDFB0:
	movs r0, 0
	b _081CE2C6
	.pool
_081CDFB8:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CDFC4
	b _081CE2C0
_081CDFC4:
	ldr r0, =gUnknown_08DC6DFC
	adds r4, r5, 0x4
	adds r1, r4, 0
	bl LZ77UnCompVram
	movs r0, 0x3
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CDFF2
	ldr r1, =gUnknown_08DC7070
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x5
	bl CopyToBgTilemapBufferRect
_081CDFF2:
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_08DC6528
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =gUnknown_08623208
	movs r1, 0xF0
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =0x00001814
	adds r1, r5, r0
	ldr r0, =0x0000ffb0
	strh r0, [r1]
	b _081CDFB0
	.pool
_081CE030:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CE03C
	b _081CE2C0
_081CE03C:
	ldr r0, =gUnknown_0862323C
	ldr r1, =0x00001004
	adds r4, r5, r1
	adds r1, r4, 0
	bl LZ77UnCompVram
	movs r0, 0x2
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_086231E8
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x2
	bl sub_81D21DC
	b _081CDFB0
	.pool
_081CE074:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0x1
	movs r1, 0x11
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r2, =0x00000804
	adds r4, r5, r2
	ldr r2, =0x05000200
	add r0, sp, 0x8
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0x1
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	b _081CDFB0
	.pool
_081CE0B0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CE0BC
	b _081CE2C0
_081CE0BC:
	ldr r0, =gUnknown_08623364
	bl AddWindow
	movs r2, 0xC1
	lsls r2, 5
	adds r1, r5, r2
	strb r0, [r1]
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CE0F6
	ldr r0, =gUnknown_0862336C
	bl AddWindow
	ldr r2, =0x00001821
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, =gUnknown_08623374
	bl AddWindow
	ldr r2, =0x00001822
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, =gUnknown_0862337C
	bl AddWindow
	ldr r2, =0x00001823
	adds r1, r5, r2
	strb r0, [r1]
_081CE0F6:
	bl DeactivateAllTextPrinters
	b _081CDFB0
	.pool
_081CE118:
	movs r0, 0
	bl sub_81CED30
	b _081CDFB0
_081CE120:
	bl sub_81CE9E4
	b _081CDFB0
_081CE126:
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE130
	b _081CDFB0
_081CE130:
	bl sub_81CE934
	b _081CDFB0
_081CE136:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE164
_081CE146:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE164
_081CE156:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE164:
	movs r2, 0x1
	bl sub_81CE754
	b _081CDFB0
_081CE16C:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0x1
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE186
	b _081CE2C0
_081CE186:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE19C
	b _081CDFB0
_081CE19C:
	ldr r2, =0x00001821
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r1, =0x00001822
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r2, =0x00001823
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	b _081CDFB0
	.pool
_081CE1C8:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl ShowBg
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE1E4
	b _081CDFB0
_081CE1E4:
	movs r0, 0x4
	bl sub_81C7BA4
	b _081CDFB0
_081CE1EC:
	movs r0, 0x1
	bl sub_81C7AC0
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CE1FC
	b _081CDFB0
_081CE1FC:
	movs r0, 0x6
	bl sub_81C7DFC
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	b _081CDFB0
_081CE218:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CE2C0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CE230
	bl sub_81C8010
	cmp r0, 0
	bne _081CE2C0
_081CE230:
	ldr r0, =sub_81CEE44
	bl c3args_set_0toR1_1to0
	b _081CDFB0
	.pool
_081CE23C:
	bl sub_81CEE90
	bl sub_81CDC70
	bl sub_81D20AC
	b _081CDFB0
_081CE24A:
	bl sub_81CDC70
	bl sub_81D20BC
	lsls r0, 24
	cmp r0, 0
	bne _081CE2C0
	b _081CDFB0
_081CE25A:
	movs r0, 0x1
	bl sub_81CEE74
	b _081CDFB0
_081CE262:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE2C0
	ldr r0, =0x000028e0
	adds r6, r5, r0
	adds r0, r6, 0
	bl sub_81D3464
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE298
	bl sub_81CDC60
	adds r4, r0, 0
	bl sub_81CDC50
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _081CE2C4
_081CE298:
	ldr r1, =0x00001816
	adds r0, r5, r1
	ldrb r4, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D3480
	b _081CE2C4
	.pool
_081CE2C0:
	movs r0, 0x2
	b _081CE2C6
_081CE2C4:
	movs r0, 0x4
_081CE2C6:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDE94

	thumb_func_start sub_81CE2D0
sub_81CE2D0: @ 81CE2D0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CE308
	cmp r4, 0x1
	bgt _081CE2EA
	cmp r4, 0
	beq _081CE2F4
	b _081CE374
_081CE2EA:
	cmp r4, 0x2
	beq _081CE328
	cmp r4, 0x3
	beq _081CE33E
	b _081CE374
_081CE2F4:
	bl sub_81CEEC8
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D3520
	movs r0, 0x1
	b _081CE376
	.pool
_081CE308:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	bne _081CE34E
	movs r0, 0
	bl sub_81CEE74
	movs r0, 0x1
	b _081CE376
	.pool
_081CE328:
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CE33A
	bl sub_81C78A0
_081CE33A:
	movs r0, 0
	b _081CE376
_081CE33E:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CE34E
	bl sub_81C78C0
	cmp r0, 0
	beq _081CE352
_081CE34E:
	movs r0, 0x2
	b _081CE376
_081CE352:
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D354C
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	b _081CE376
	.pool
_081CE374:
	movs r0, 0x4
_081CE376:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE2D0

	thumb_func_start sub_81CE37C
sub_81CE37C: @ 81CE37C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r6, r0, 0
	bl sub_81CDC70
	adds r2, r0, 0
	cmp r4, 0x9
	bls _081CE394
	b _081CE4D0
_081CE394:
	lsls r0, r4, 2
	ldr r1, =_081CE3A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE3A4:
	.4byte _081CE3CC
	.4byte _081CE3D0
	.4byte _081CE3DA
	.4byte _081CE3F0
	.4byte _081CE3F8
	.4byte _081CE418
	.4byte _081CE428
	.4byte _081CE438
	.4byte _081CE44E
	.4byte _081CE468
_081CE3CC:
	movs r0, 0
	b _081CE3D2
_081CE3D0:
	movs r0, 0x1
_081CE3D2:
	bl sub_81CD548
_081CE3D6:
	movs r0, 0x1
	b _081CE4D2
_081CE3DA:
	movs r0, 0x2
	bl sub_81CD548
	ldr r1, =0x000028e0
	adds r0, r6, r1
	bl sub_81D3520
	b _081CE3D6
	.pool
_081CE3F0:
	adds r0, r2, 0
	bl sub_81D2074
	b _081CE3D6
_081CE3F8:
	ldr r1, =0x00001814
	adds r0, r6, r1
	bl sub_81D3150
	lsls r0, 24
	cmp r0, 0
	bne _081CE4CC
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	bl sub_81CED30
	b _081CE3D6
	.pool
_081CE418:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE446
_081CE428:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE446
_081CE438:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE446:
	movs r2, 0
	bl sub_81CE754
	b _081CE3D6
_081CE44E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE3D6
	b _081CE4CC
_081CE468:
	bl sub_81CDC70
	adds r2, r0, 0
	ldr r0, =0x00001814
	adds r1, r6, r0
	adds r0, r2, 0
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE4CC
	ldr r1, =0x000028e0
	adds r0, r6, r1
	bl sub_81D3464
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE4A0
	bl sub_81CDC60
	adds r4, r0, 0
	bl sub_81CDC50
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _081CE3D6
_081CE4A0:
	ldr r0, =0x000028e0
	adds r5, r6, r0
	ldr r1, =0x00001816
	adds r0, r6, r1
	ldrb r4, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81D3480
	b _081CE3D6
	.pool
_081CE4CC:
	movs r0, 0x2
	b _081CE4D2
_081CE4D0:
	movs r0, 0x4
_081CE4D2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE37C

	thumb_func_start sub_81CE4D8
sub_81CE4D8: @ 81CE4D8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x8
	bhi _081CE5DC
	lsls r0, r4, 2
	ldr r1, =_081CE4F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE4F8:
	.4byte _081CE51C
	.4byte _081CE520
	.4byte _081CE524
	.4byte _081CE52E
	.4byte _081CE53E
	.4byte _081CE54E
	.4byte _081CE55E
	.4byte _081CE576
	.4byte _081CE592
_081CE51C:
	movs r0, 0
	b _081CE526
_081CE520:
	movs r0, 0x1
	b _081CE526
_081CE524:
	movs r0, 0x2
_081CE526:
	bl sub_81CD548
	movs r0, 0x1
	b _081CE5DE
_081CE52E:
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	bl sub_81CED30
	movs r0, 0x1
	b _081CE5DE
_081CE53E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE56C
_081CE54E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE56C
_081CE55E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE56C:
	movs r2, 0
	bl sub_81CE754
	movs r0, 0x1
	b _081CE5DE
_081CE576:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	bne _081CE5D8
	movs r0, 0x1
	b _081CE5DE
_081CE592:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE5D8
	ldr r0, =0x000028e0
	adds r4, r5, r0
	adds r0, r4, 0
	bl sub_81D3464
	ldr r1, =0x00001816
	adds r0, r5, r1
	ldrb r5, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3480
	movs r0, 0x1
	b _081CE5DE
	.pool
_081CE5D8:
	movs r0, 0x2
	b _081CE5DE
_081CE5DC:
	movs r0, 0x4
_081CE5DE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE4D8

	thumb_func_start sub_81CE5E4
sub_81CE5E4: @ 81CE5E4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x7
	bhi _081CE6B2
	lsls r0, r4, 2
	ldr r1, =_081CE604
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE604:
	.4byte _081CE624
	.4byte _081CE628
	.4byte _081CE632
	.4byte _081CE648
	.4byte _081CE660
	.4byte _081CE670
	.4byte _081CE680
	.4byte _081CE696
_081CE624:
	movs r0, 0
	b _081CE62A
_081CE628:
	movs r0, 0x1
_081CE62A:
	bl sub_81CD548
_081CE62E:
	movs r0, 0x1
	b _081CE6B4
_081CE632:
	movs r0, 0x2
	bl sub_81CD548
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D3520
	b _081CE62E
	.pool
_081CE648:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	beq _081CE62E
	b _081CE6AE
	.pool
_081CE660:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE68E
_081CE670:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE68E
_081CE680:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE68E:
	movs r2, 0
	bl sub_81CE754
	b _081CE62E
_081CE696:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE62E
_081CE6AE:
	movs r0, 0x2
	b _081CE6B4
_081CE6B2:
	movs r0, 0x4
_081CE6B4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE5E4

	thumb_func_start sub_81CE6BC
sub_81CE6BC: @ 81CE6BC
	push {lr}
	cmp r0, 0x1
	beq _081CE6E6
	cmp r0, 0x1
	bgt _081CE6CC
	cmp r0, 0
	beq _081CE6D2
	b _081CE6FA
_081CE6CC:
	cmp r0, 0x2
	beq _081CE6EE
	b _081CE6FA
_081CE6D2:
	bl sub_81CDD7C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xB0
	movs r2, 0x20
	bl sub_811FAA4
_081CE6E2:
	movs r0, 0x1
	b _081CE6FC
_081CE6E6:
	movs r0, 0x5
	bl sub_81C7BA4
	b _081CE6E2
_081CE6EE:
	bl sub_81C7BE8
	cmp r0, 0x1
	bne _081CE6E2
	movs r0, 0x2
	b _081CE6FC
_081CE6FA:
	movs r0, 0x4
_081CE6FC:
	pop {r1}
	bx r1
	thumb_func_end sub_81CE6BC

	thumb_func_start sub_81CE700
sub_81CE700: @ 81CE700
	push {lr}
	cmp r0, 0x1
	beq _081CE71E
	cmp r0, 0x1
	bgt _081CE710
	cmp r0, 0
	beq _081CE716
	b _081CE732
_081CE710:
	cmp r0, 0x2
	beq _081CE726
	b _081CE732
_081CE716:
	bl sub_811FAF8
_081CE71A:
	movs r0, 0x1
	b _081CE734
_081CE71E:
	movs r0, 0x4
	bl sub_81C7BA4
	b _081CE71A
_081CE726:
	bl sub_81C7BE8
	cmp r0, 0x1
	bne _081CE71A
	movs r0, 0x2
	b _081CE734
_081CE732:
	movs r0, 0x4
_081CE734:
	pop {r1}
	bx r1
	thumb_func_end sub_81CE700

	thumb_func_start sub_81CE738
sub_81CE738: @ 81CE738
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_085EBFD7
	bl StringCopy
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CE738

	thumb_func_start sub_81CE754
sub_81CE754: @ 81CE754
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0xC
	bl sub_81C763C
	adds r6, r0, 0
	cmp r4, 0x1
	beq _081CE7B8
	cmp r4, 0x1
	bgt _081CE782
	cmp r4, 0
	beq _081CE78E
	b _081CE924
_081CE782:
	cmp r4, 0x2
	beq _081CE800
	cmp r4, 0x3
	bne _081CE78C
	b _081CE89C
_081CE78C:
	b _081CE924
_081CE78E:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE7A6
	b _081CE924
_081CE7A6:
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	b _081CE924
	.pool
_081CE7B8:
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	bne _081CE7DA
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE7DA
	b _081CE924
_081CE7DA:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81CDD04
	adds r2, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	str r7, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	b _081CE924
_081CE800:
	bl sub_81CDD5C
	adds r7, r0, 0
	cmp r7, 0x1
	beq _081CE80C
	b _081CE924
_081CE80C:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81CDD24
	adds r2, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x11
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	add r1, sp, 0xC
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	adds r0, r1, 0
	strb r4, [r0, 0x3]
	movs r0, 0x9
	strb r0, [r1, 0x4]
	mov r5, sp
	adds r5, 0x11
	ldr r1, =gUnknown_085EBFD7
	adds r0, r5, 0
	bl StringCopy
	ldr r0, =0x00001821
	adds r6, r0
	ldrb r0, [r6]
	str r7, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x4
	bl Print
	bl sub_81CDD48
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldrb r0, [r6]
	str r7, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x1C
	bl Print
	b _081CE924
	.pool
_081CE89C:
	ldr r1, =0x00002908
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CE8B0
	cmp r0, 0x1
	beq _081CE8EC
	b _081CE924
	.pool
_081CE8B0:
	cmp r5, 0
	beq _081CE8C4
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081CE8D2
_081CE8C4:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
_081CE8D2:
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CE910
	ldr r0, =0x00002908
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081CE924
	.pool
_081CE8EC:
	cmp r5, 0
	beq _081CE904
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081CE910
	.pool
_081CE904:
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
_081CE910:
	ldr r0, =0x00002908
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CE926
	.pool
_081CE924:
	movs r0, 0
_081CE926:
	add sp, 0x2C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE754

	thumb_func_start sub_81CE934
sub_81CE934: @ 81CE934
	push {r4,lr}
	movs r0, 0xC
	bl sub_81C763C
	adds r4, r0, 0
	ldr r1, =0x00001822
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =0x00001823
	adds r4, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CE934

	thumb_func_start sub_81CE964
sub_81CE964: @ 81CE964
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	bl sub_81CDC60
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	bne _081CE982
	adds r0, r5, 0
	movs r1, 0
	bl StartObjectImageAnim
	b _081CE98A
_081CE982:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartObjectImageAnim
_081CE98A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE964

	thumb_func_start sub_81CE990
sub_81CE990: @ 81CE990
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	bne _081CE9B0
	movs r0, 0x65
	b _081CE9B2
_081CE9B0:
	movs r0, 0x66
_081CE9B2:
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r5, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE990

	thumb_func_start sub_81CE9C8
sub_81CE9C8: @ 81CE9C8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CDD7C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE9C8

	thumb_func_start sub_81CE9E4
sub_81CE9E4: @ 81CE9E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	movs r0, 0xC
	bl sub_81C763C
	adds r6, r0, 0
	add r4, sp, 0x20
	add r5, sp, 0x38
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81D321C
	bl sub_81CDD5C
	adds r7, r4, 0
	mov r10, r5
	cmp r0, 0x1
	bne _081CEA78
	ldr r1, =0x00001824
	adds r0, r6, r1
	movs r2, 0x6A
	strh r2, [r0]
	ldr r3, =0x00001826
	adds r1, r6, r3
	strh r2, [r1]
	bl sub_811F90C
	bl sub_811FA90
	ldr r2, =gUnknown_08623338
	movs r0, 0x69
	movs r1, 0x69
	bl sub_811FF94
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0xC0
	strh r1, [r0, 0x20]
	movs r1, 0x20
	strh r1, [r0, 0x22]
	ldr r1, =sub_81CE9C8
	str r1, [r0, 0x1C]
	ldr r2, =0x000028dc
	adds r1, r6, r2
	str r0, [r1]
	movs r0, 0x69
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81C7990
	add r3, sp, 0x50
	mov r8, r3
	b _081CEBC6
	.pool
_081CEA78:
	mov r0, sp
	bl LoadObjectPics
	mov r0, r10
	bl sub_81C795C
	movs r4, 0
	add r0, sp, 0x50
	mov r8, r0
	b _081CEAE8
_081CEA8C:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r1, 0x80
	lsls r1, 12
	adds r2, r1
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xE2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEAD8
	ldr r2, =0x00001806
	adds r0, r6, r2
	adds r0, r4
	strb r3, [r0]
	ldr r2, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r1, r0, r2
	strh r4, [r1, 0x2E]
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81CE964
	str r1, [r0]
	b _081CEAE2
	.pool
_081CEAD8:
	ldr r3, =0x00001806
	adds r0, r6, r3
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081CEAE2:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081CEAE8:
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	blt _081CEA8C
	movs r0, 0x67
	strh r0, [r7]
	ldr r0, =SpriteCallbackDummy
	str r0, [r7, 0x14]
	cmp r4, 0x5
	bhi _081CEB5C
	ldr r0, =0x00001806
	adds r5, r6, r0
	ldr r1, =gSprites
	mov r9, r1
_081CEB0A:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r3, 0x80
	lsls r3, 12
	adds r2, r3
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xE6
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEB4C
	adds r0, r5, r4
	strb r3, [r0]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x3]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x3]
	b _081CEB52
	.pool
_081CEB4C:
	adds r1, r5, r4
	movs r0, 0xFF
	strb r0, [r1]
_081CEB52:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x5
	bls _081CEB0A
_081CEB5C:
	movs r0, 0x66
	strh r0, [r7]
	ldr r0, =sub_81CE990
	str r0, [r7, 0x14]
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xDE
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEBBC
	ldr r1, =0x00001806
	adds r0, r6, r1
	adds r0, r4
	strb r3, [r0]
	ldr r0, =gSprites
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r0
	ldrb r3, [r2, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r3
	movs r3, 0x40
	orrs r0, r3
	strb r0, [r2, 0x1]
	ldrb r0, [r2, 0x3]
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	strb r1, [r2, 0x3]
	b _081CEBC6
	.pool
_081CEBBC:
	ldr r2, =0x00001806
	adds r0, r6, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081CEBC6:
	mov r0, r8
	mov r1, r10
	bl sub_81D32B0
	mov r0, r8
	bl LoadObjectPic
	movs r0, 0
	mov r3, r10
	str r0, [r3, 0x8]
	mov r0, r10
	bl sub_81C795C
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CE9E4

	thumb_func_start sub_81CEBF4
sub_81CEBF4: @ 81CEBF4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CEC28
	ldr r1, =0x000028dc
	adds r0, r5, r1
	ldr r0, [r0]
	bl DestroySprite
	movs r0, 0x6A
	bl FreeObjectTilesByTag
	movs r0, 0x69
	bl FreeObjectTilesByTag
	movs r0, 0x6A
	bl FreeObjectPaletteByTag
	movs r0, 0x69
	bl FreeObjectPaletteByTag
	b _081CEC68
	.pool
_081CEC28:
	movs r4, 0
_081CEC2A:
	ldr r1, =0x00001806
	adds r0, r5, r1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _081CEC2A
	movs r0, 0x65
	bl FreeObjectTilesByTag
	movs r0, 0x66
	bl FreeObjectTilesByTag
	movs r0, 0x67
	bl FreeObjectTilesByTag
	movs r0, 0x65
	bl FreeObjectPaletteByTag
	movs r0, 0x66
	bl FreeObjectPaletteByTag
_081CEC68:
	ldr r0, =0x00001816
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081CEC8E
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r0, 0x64
	bl FreeObjectTilesByTag
	movs r0, 0x64
	bl FreeObjectPaletteByTag
_081CEC8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CEBF4

	thumb_func_start sub_81CECA0
sub_81CECA0: @ 81CECA0
	push {r4,lr}
	movs r0, 0xC
	bl sub_81C763C
	adds r4, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CECEC
	ldr r1, =0x00001821
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, =0x00001822
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, =0x00001823
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	b _081CECF0
	.pool
_081CECEC:
	bl sub_81C7FDC
_081CECF0:
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_81CEBF4
	bl sub_81CEE68
	movs r0, 0xC
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CECA0

	thumb_func_start sub_81CED10
sub_81CED10: @ 81CED10
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	ldr r1, =0x00001814
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x26
	strh r0, [r4, 0x20]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CED10

	thumb_func_start sub_81CED30
sub_81CED30: @ 81CED30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0xC
	bl sub_81C763C
	mov r8, r0
	ldr r7, =0x00001816
	add r7, r8
	ldrb r0, [r7]
	cmp r0, 0xFF
	bne _081CEDFC
	add r5, sp, 0x18
	add r4, sp, 0x20
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_81D31D0
	adds r0, r6, 0
	bl sub_81CDCB4
	str r0, [sp, 0x18]
	adds r0, r6, 0
	bl sub_81CDCD4
	str r0, [sp, 0x20]
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =0x00001818
	add r4, r8
	strh r0, [r4]
	adds r0, r5, 0
	bl LoadObjectPic
	ldr r5, =0x0000181a
	add r5, r8
	strh r0, [r5]
	mov r0, sp
	movs r1, 0x26
	movs r2, 0x68
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r7]
	cmp r0, 0x40
	bne _081CEDBC
	movs r0, 0x64
	bl FreeObjectTilesByTag
	movs r0, 0x64
	bl FreeObjectPaletteByTag
	movs r0, 0xFF
	strb r0, [r7]
	b _081CEE26
	.pool
_081CEDBC:
	strb r0, [r7]
	ldr r2, =gSprites
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81CED10
	str r1, [r0]
	ldr r1, =0x0000181c
	add r1, r8
	ldrh r0, [r5]
	lsls r0, 5
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4]
	b _081CEE26
	.pool
_081CEDFC:
	adds r0, r6, 0
	bl sub_81CDCB4
	ldr r1, =0x0000181c
	add r1, r8
	ldr r2, [r1]
	ldr r1, =0x040000d4
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x80000400
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r0, r6, 0
	bl sub_81CDCD4
	ldr r1, =0x00001818
	add r1, r8
	ldrh r1, [r1]
	movs r2, 0x20
	bl LoadPalette
_081CEE26:
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CED30

	thumb_func_start sub_81CEE44
sub_81CEE44: @ 81CEE44
	push {r4,lr}
	bl sub_81CDC70
	adds r4, r0, 0
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	adds r0, r4, 0
	bl sub_81D2108
	bl sub_80BA0A8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE44

	thumb_func_start sub_81CEE68
sub_81CEE68: @ 81CEE68
	push {lr}
	bl sub_81C760C
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE68

	thumb_func_start sub_81CEE74
sub_81CEE74: @ 81CEE74
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _081CEE84
	movs r0, 0x2
	bl ShowBg
	b _081CEE8A
_081CEE84:
	movs r0, 0x2
	bl HideBg
_081CEE8A:
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE74

	thumb_func_start sub_81CEE90
sub_81CEE90: @ 81CEE90
	push {r4,lr}
	bl sub_81CDC70
	adds r4, r0, 0
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_030012BC
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x50
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r2, 0x14
	adds r2, r4, r2
	adds r0, r4, 0
	bl sub_81D1F84
	adds r0, r4, 0
	bl sub_81D2074
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CEE90

	thumb_func_start sub_81CEEC8
sub_81CEEC8: @ 81CEEC8
	push {r4,r5,lr}
	bl sub_81CDC70
	adds r5, r0, 0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CEEF0
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	beq _081CEF0C
_081CEEF0:
	bl sub_81CDC84
	lsls r0, 24
	asrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x14
	adds r1, r5, r1
	adds r2, r5, 0
	adds r2, 0x50
	adds r0, r5, 0
	bl sub_81D1F84
_081CEF0C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CEEC8

	thumb_func_start sub_81CEF14
sub_81CEF14: @ 81CEF14
	push {r4,lr}
	movs r0, 0xC
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CEF2A
	movs r0, 0
	b _081CEF30
_081CEF2A:
	ldr r1, =0x00001828
	adds r0, r4, r1
	ldrb r0, [r0]
_081CEF30:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CEF14

	thumb_func_start sub_81CEF3C
sub_81CEF3C: @ 81CEF3C
	push {r4,lr}
	movs r0, 0x7
	movs r1, 0x24
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CEF90
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl sub_81C761C
	str r0, [r4, 0x20]
	cmp r0, 0
	beq _081CEF90
	ldr r0, =sub_81CF010
	str r0, [r4]
	ldr r0, =sub_81CF11C
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	movs r0, 0
	str r0, [r4, 0x18]
	bl sub_81C76AC
	ldr r1, =gUnknown_086233A0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CEF92
	.pool
_081CEF90:
	movs r0, 0
_081CEF92:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CEF3C

	thumb_func_start sub_81CEF98
sub_81CEF98: @ 81CEF98
	push {r4,lr}
	movs r0, 0x7
	movs r1, 0x24
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CEFD4
	movs r0, 0x12
	bl sub_81C763C
	str r0, [r4, 0x20]
	ldr r0, =sub_81CF030
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0x18]
	bl sub_81C76AC
	ldr r1, =gUnknown_086233A0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CEFD6
	.pool
_081CEFD4:
	movs r0, 0
_081CEFD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CEF98

	thumb_func_start sub_81CEFDC
sub_81CEFDC: @ 81CEFDC
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CEFDC

	thumb_func_start sub_81CEFF0
sub_81CEFF0: @ 81CEFF0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	cmp r0, 0
	bne _081CF004
	movs r0, 0x12
	bl sub_81C7650
_081CF004:
	movs r0, 0x7
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CEFF0

	thumb_func_start sub_81CF010
sub_81CF010: @ 81CF010
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4]
	bl sub_81C70D8
	cmp r0, 0
	bne _081CF022
	ldr r0, =sub_81CF030
	str r0, [r4]
_081CF022:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF010

	thumb_func_start sub_81CF030
sub_81CF030: @ 81CF030
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CF048
	movs r0, 0x1
	b _081CF0A6
	.pool
_081CF048:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CF054
	movs r0, 0x2
	b _081CF0A6
_081CF054:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CF062
	movs r0, 0x3
	b _081CF0A6
_081CF062:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CF072
	movs r0, 0x4
	b _081CF0A6
_081CF072:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CF088
	str r2, [r4, 0x1C]
	ldr r0, =sub_81CF0B0
	str r0, [r4]
	movs r0, 0x5
	b _081CF0A6
	.pool
_081CF088:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081CF096
	movs r0, 0
	b _081CF0A6
_081CF096:
	bl sub_81C875C
	ldr r1, [r4, 0x20]
	strh r0, [r1, 0x2]
	str r5, [r4, 0x1C]
	ldr r0, =sub_81CF0B8
	str r0, [r4]
	movs r0, 0x6
_081CF0A6:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF030

	thumb_func_start sub_81CF0B0
sub_81CF0B0: @ 81CF0B0
	ldr r0, =0x000186a3
	bx lr
	.pool
	thumb_func_end sub_81CF0B0

	thumb_func_start sub_81CF0B8
sub_81CF0B8: @ 81CF0B8
	ldr r0, =0x000186a9
	bx lr
	.pool
	thumb_func_end sub_81CF0B8

	thumb_func_start sub_81CF0C0
sub_81CF0C0: @ 81CF0C0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0C0

	thumb_func_start sub_81CF0D0
sub_81CF0D0: @ 81CF0D0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x20]
	adds r0, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0D0

	thumb_func_start sub_81CF0E0
sub_81CF0E0: @ 81CF0E0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x20]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0E0

	thumb_func_start sub_81CF0F0
sub_81CF0F0: @ 81CF0F0
	push {r4,lr}
	movs r0, 0x7
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C875C
	ldr r1, [r4, 0x20]
	lsls r0, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0F0

	thumb_func_start sub_81CF10C
sub_81CF10C: @ 81CF10C
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x20]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF10C

	thumb_func_start sub_81CF11C
sub_81CF11C: @ 81CF11C
	push {lr}
	ldr r2, =gUnknown_086233B4
	lsls r1, r0, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF11C

	thumb_func_start sub_81CF134
sub_81CF134: @ 81CF134
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x7
	bl sub_81C763C
	adds r6, r0, 0
	ldr r0, [r6, 0x20]
	movs r1, 0
	strh r1, [r0]
	ldr r0, [r6, 0x20]
	strh r1, [r0, 0x2]
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xE
	orrs r0, r1
	str r0, [sp]
	movs r5, 0
_081CF158:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CF1AA
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CF1A4
	lsls r1, r5, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r6, 0x14]
	adds r0, r4, 0
	bl GetMonData
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CF2C4
_081CF1A4:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CF158
_081CF1AA:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF134

	thumb_func_start sub_81CF1C4
sub_81CF1C4: @ 81CF1C4
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	movs r1, 0
	str r1, [r0, 0x10]
	str r1, [r0, 0xC]
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81CF1C4

	thumb_func_start sub_81CF1D8
sub_81CF1D8: @ 81CF1D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r0, 0x7
	bl sub_81C763C
	adds r6, r0, 0
	ldr r5, [r6, 0xC]
	ldr r4, [r6, 0x10]
	movs r0, 0
	mov r8, r0
	cmp r5, 0xD
	bgt _081CF268
_081CF1F4:
	cmp r4, 0x1D
	bgt _081CF260
	lsls r0, r5, 24
	lsrs r7, r0, 24
_081CF1FC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80D2270
	cmp r0, 0
	beq _081CF23A
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r7
	lsls r1, r4, 24
	lsrs r1, 24
	lsls r3, r1, 8
	ldr r2, =0xffff00ff
	ands r0, r2
	orrs r0, r3
	str r0, [sp]
	ldr r2, [r6, 0x14]
	adds r0, r7, 0
	bl get_pokemon_data_from_any_box
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CF2C4
_081CF23A:
	movs r0, 0x1
	add r8, r0
	adds r4, 0x1
	mov r0, r8
	cmp r0, 0xE
	ble _081CF25C
	str r5, [r6, 0xC]
	str r4, [r6, 0x10]
	movs r0, 0x3
	b _081CF26A
	.pool
_081CF25C:
	cmp r4, 0x1D
	ble _081CF1FC
_081CF260:
	movs r4, 0
	adds r5, 0x1
	cmp r5, 0xD
	ble _081CF1F4
_081CF268:
	movs r0, 0x1
_081CF26A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF1D8

	thumb_func_start sub_81CF278
sub_81CF278: @ 81CF278
	push {r4-r6,lr}
	movs r0, 0x7
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, [r5, 0x20]
	ldrh r6, [r0]
	ldrh r4, [r0, 0x6]
	movs r1, 0x1
	strh r1, [r0, 0x6]
	movs r3, 0x1
	cmp r3, r6
	bge _081CF2B8
_081CF292:
	ldr r2, [r5, 0x20]
	lsls r0, r3, 2
	adds r1, r2, r0
	ldrh r0, [r1, 0x6]
	cmp r0, r4
	bne _081CF2AC
	subs r0, r3, 0x1
	lsls r0, 2
	adds r0, r2, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r1, 0x6]
	adds r0, r3, 0x1
	b _081CF2B2
_081CF2AC:
	adds r4, r0, 0
	adds r0, r3, 0x1
	strh r0, [r1, 0x6]
_081CF2B2:
	adds r3, r0, 0
	cmp r3, r6
	blt _081CF292
_081CF2B8:
	movs r0, 0x1
	str r0, [r5, 0x18]
	movs r0, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF278

	thumb_func_start sub_81CF2C4
sub_81CF2C4: @ 81CF2C4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldr r0, [r5, 0x20]
	ldrh r2, [r0]
	lsrs r3, r2, 1
	cmp r2, r3
	beq _081CF2F4
	adds r6, r0, 0
	ldrh r4, [r7, 0x2]
_081CF2DA:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x6]
	cmp r4, r0
	bls _081CF2E8
	adds r2, r3, 0
	b _081CF2EA
_081CF2E8:
	adds r1, r3, 0x1
_081CF2EA:
	subs r0, r2, r1
	lsrs r0, 1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CF2DA
_081CF2F4:
	ldr r0, [r5, 0x20]
	ldrh r2, [r0]
	lsls r6, r3, 2
	cmp r2, r3
	bls _081CF318
	lsls r0, r2, 2
	subs r4, r0, 0x4
_081CF302:
	ldr r0, [r5, 0x20]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, 0x4
	subs r2, 0x1
	cmp r2, r3
	bhi _081CF302
_081CF318:
	ldr r0, [r5, 0x20]
	adds r0, 0x4
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, 0x20]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CF2C4

	thumb_func_start sub_81CF330
sub_81CF330: @ 81CF330
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0x8
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF360
	ldr r0, =sub_81CF418
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r4]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081CF362
	.pool
_081CF360:
	movs r0, 0
_081CF362:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF330

	thumb_func_start sub_81CF368
sub_81CF368: @ 81CF368
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0x8
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF398
	ldr r0, =sub_81CF418
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0xC]
	b _081CF39A
	.pool
_081CF398:
	movs r0, 0
_081CF39A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF368

	thumb_func_start sub_81CF3A0
sub_81CF3A0: @ 81CF3A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08623598
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF3A0

	thumb_func_start sub_81CF3D0
sub_81CF3D0: @ 81CF3D0
	push {lr}
	movs r0, 0x8
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CF3D0

	thumb_func_start sub_81CF3E4
sub_81CF3E4: @ 81CF3E4
	push {lr}
	movs r0, 0x8
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CF3E4

	thumb_func_start sub_81CF3F8
sub_81CF3F8: @ 81CF3F8
	push {r4,lr}
	movs r0, 0x8
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C8234
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x8
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CF3F8

	thumb_func_start sub_81CF418
sub_81CF418: @ 81CF418
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x5
	bls _081CF42C
	b _081CF56E
_081CF42C:
	lsls r0, r4, 2
	ldr r1, =_081CF43C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CF43C:
	.4byte _081CF454
	.4byte _081CF4AC
	.4byte _081CF4C0
	.4byte _081CF4E0
	.4byte _081CF4F6
	.4byte _081CF55A
_081CF454:
	ldr r0, =gUnknown_08623590
	movs r1, 0x2
	bl sub_81C7B54
	ldr r1, =gUnknown_086233E4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x10
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086234AC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_086233C4
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081CF498:
	movs r0, 0
	b _081CF570
	.pool
_081CF4AC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	bl sub_81CF0C0
	cmp r0, 0
	beq _081CF56A
	b _081CF498
_081CF4C0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	ldr r0, =gUnknown_08623570
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	bl sub_81CF88C
	b _081CF498
	.pool
_081CF4E0:
	bl sub_81C8224
	cmp r0, 0
	bne _081CF56A
	adds r0, r5, 0
	bl sub_81CF7C8
	movs r0, 0x3
	bl sub_81C7BA4
	b _081CF498
_081CF4F6:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _081CF552
	bl sub_81C76AC
	adds r4, r0, 0
	adds r4, 0x8
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_81C7DFC
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
_081CF552:
	movs r0, 0x1
	bl sub_81C7AC0
	b _081CF498
_081CF55A:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CF56A
	bl sub_81C8010
	cmp r0, 0
	beq _081CF56E
_081CF56A:
	movs r0, 0x2
	b _081CF570
_081CF56E:
	movs r0, 0x4
_081CF570:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF418

	thumb_func_start sub_81CF578
sub_81CF578: @ 81CF578
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF5C6
	cmp r4, 0x1
	bgt _081CF592
	cmp r4, 0
	beq _081CF59C
	b _081CF5E6
_081CF592:
	cmp r4, 0x2
	beq _081CF5CE
	cmp r4, 0x3
	beq _081CF5D8
	b _081CF5E6
_081CF59C:
	bl sub_81C8658
	cmp r0, 0x1
	beq _081CF5B4
	cmp r0, 0x1
	bgt _081CF5AE
	cmp r0, 0
	beq _081CF5E6
	b _081CF5D4
_081CF5AE:
	cmp r0, 0x2
	beq _081CF5BE
	b _081CF5D4
_081CF5B4:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CF5E8
_081CF5BE:
	movs r0, 0x5
	bl audio_play
	b _081CF5D4
_081CF5C6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF5E2
_081CF5CE:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF5D4:
	movs r0, 0
	b _081CF5E8
_081CF5D8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF5E6
_081CF5E2:
	movs r0, 0x2
	b _081CF5E8
_081CF5E6:
	movs r0, 0x4
_081CF5E8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF578

	thumb_func_start sub_81CF5F0
sub_81CF5F0: @ 81CF5F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF63E
	cmp r4, 0x1
	bgt _081CF60A
	cmp r4, 0
	beq _081CF614
	b _081CF65E
_081CF60A:
	cmp r4, 0x2
	beq _081CF646
	cmp r4, 0x3
	beq _081CF650
	b _081CF65E
_081CF614:
	bl sub_81C868C
	cmp r0, 0x1
	beq _081CF62C
	cmp r0, 0x1
	bgt _081CF626
	cmp r0, 0
	beq _081CF65E
	b _081CF64C
_081CF626:
	cmp r0, 0x2
	beq _081CF636
	b _081CF64C
_081CF62C:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CF660
_081CF636:
	movs r0, 0x5
	bl audio_play
	b _081CF64C
_081CF63E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF65A
_081CF646:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF64C:
	movs r0, 0
	b _081CF660
_081CF650:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF65E
_081CF65A:
	movs r0, 0x2
	b _081CF660
_081CF65E:
	movs r0, 0x4
_081CF660:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF5F0

	thumb_func_start sub_81CF668
sub_81CF668: @ 81CF668
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF6B6
	cmp r4, 0x1
	bgt _081CF682
	cmp r4, 0
	beq _081CF68C
	b _081CF6D6
_081CF682:
	cmp r4, 0x2
	beq _081CF6BE
	cmp r4, 0x3
	beq _081CF6C8
	b _081CF6D6
_081CF68C:
	bl sub_81C86CC
	cmp r0, 0x1
	beq _081CF6A4
	cmp r0, 0x1
	bgt _081CF69E
	cmp r0, 0
	beq _081CF6D6
	b _081CF6C4
_081CF69E:
	cmp r0, 0x2
	beq _081CF6AE
	b _081CF6C4
_081CF6A4:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CF6D8
_081CF6AE:
	movs r0, 0x5
	bl audio_play
	b _081CF6C4
_081CF6B6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF6D2
_081CF6BE:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF6C4:
	movs r0, 0
	b _081CF6D8
_081CF6C8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF6D6
_081CF6D2:
	movs r0, 0x2
	b _081CF6D8
_081CF6D6:
	movs r0, 0x4
_081CF6D8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF668

	thumb_func_start sub_81CF6E0
sub_81CF6E0: @ 81CF6E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF72E
	cmp r4, 0x1
	bgt _081CF6FA
	cmp r4, 0
	beq _081CF704
	b _081CF74E
_081CF6FA:
	cmp r4, 0x2
	beq _081CF736
	cmp r4, 0x3
	beq _081CF740
	b _081CF74E
_081CF704:
	bl sub_81C870C
	cmp r0, 0x1
	beq _081CF71C
	cmp r0, 0x1
	bgt _081CF716
	cmp r0, 0
	beq _081CF74E
	b _081CF73C
_081CF716:
	cmp r0, 0x2
	beq _081CF726
	b _081CF73C
_081CF71C:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081CF750
_081CF726:
	movs r0, 0x5
	bl audio_play
	b _081CF73C
_081CF72E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF74A
_081CF736:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF73C:
	movs r0, 0
	b _081CF750
_081CF740:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF74E
_081CF74A:
	movs r0, 0x2
	b _081CF750
_081CF74E:
	movs r0, 0x4
_081CF750:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF6E0

	thumb_func_start sub_81CF758
sub_81CF758: @ 81CF758
	push {lr}
	cmp r0, 0
	beq _081CF764
	cmp r0, 0x1
	beq _081CF778
	b _081CF790
_081CF764:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081CF792
_081CF778:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CF788
	bl sub_81C78C0
	cmp r0, 0
	beq _081CF78C
_081CF788:
	movs r0, 0x2
	b _081CF792
_081CF78C:
	bl sub_81C7FDC
_081CF790:
	movs r0, 0x4
_081CF792:
	pop {r1}
	bx r1
	thumb_func_end sub_81CF758

	thumb_func_start sub_81CF798
sub_81CF798: @ 81CF798
	push {lr}
	cmp r0, 0
	beq _081CF7A4
	cmp r0, 0x1
	beq _081CF7B4
	b _081CF7C0
_081CF7A4:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081CF7C2
_081CF7B4:
	bl sub_81C7B34
	cmp r0, 0
	beq _081CF7C0
	movs r0, 0x2
	b _081CF7C2
_081CF7C0:
	movs r0, 0x4
_081CF7C2:
	pop {r1}
	bx r1
	thumb_func_end sub_81CF798

	thumb_func_start sub_81CF7C8
sub_81CF7C8: @ 81CF7C8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086235B4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	adds r0, r4, 0
	bl sub_81CF7F4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF7C8

	thumb_func_start sub_81CF7F4
sub_81CF7F4: @ 81CF7F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	bl sub_81CF0F0
	adds r7, r0, 0
	bl sub_81AFBF0
	ldr r4, =gStringVar1
	movs r0, 0
	adds r1, r4, 0
	bl sub_81AFC0C
	movs r0, 0xFF
	strb r0, [r4]
	ldr r5, =gStringVar2
	ldr r1, =gUnknown_085EC029
	adds r0, r5, 0
	bl sub_81AFC28
	mov r1, r8
	ldrb r0, [r1, 0x8]
	movs r1, 0x1
	mov r10, r1
	str r1, [sp]
	movs r1, 0xFF
	mov r9, r1
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl Print
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r1, r8
	ldrb r0, [r1, 0x8]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x22
	bl Print
	mov r1, r8
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF7F4

	thumb_func_start sub_81CF88C
sub_81CF88C: @ 81CF88C
	push {r4,lr}
	sub sp, 0x18
	bl sub_81CF0D0
	str r0, [sp]
	bl sub_81CF0E0
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_81CF10C
	mov r1, sp
	strh r0, [r1, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x11
	strb r0, [r1, 0xA]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0xD]
	mov r0, sp
	strb r2, [r0, 0xE]
	ldr r0, =sub_81CF8E4
	str r0, [sp, 0x10]
	str r4, [sp, 0x14]
	ldr r0, =gUnknown_08623594
	movs r2, 0
	bl sub_81C81D4
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF88C

	thumb_func_start sub_81CF8E4
sub_81CF8E4: @ 81CF8E4
	push {r4-r7,lr}
	adds r2, r0, 0
	adds r6, r1, 0
	ldrb r0, [r2]
	cmp r0, 0xE
	bne _081CF924
	ldrb r1, [r2, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	bl pokemon_get_gender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl level_by_exp
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMonData
	b _081CF94A
	.pool
_081CF924:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	bl pokemon_roll_gender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl sub_80690C0
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl pokemon_getattr_encrypted
_081CF94A:
	ldr r4, =gStringVar3
	adds r0, r4, 0
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3C
	bl sub_81DB494
	adds r6, r0, 0
	cmp r5, 0
	beq _081CF974
	cmp r5, 0xFE
	beq _081CF97C
	ldr r1, =gUnknown_086235D4
	b _081CF97E
	.pool
_081CF974:
	ldr r1, =gUnknown_086235BC
	b _081CF97E
	.pool
_081CF97C:
	ldr r1, =gUnknown_086235C8
_081CF97E:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x28
	bl sub_81DB494
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF8E4

	thumb_func_start sub_81CF9BC
sub_81CF9BC: @ 81CF9BC
	push {r4,lr}
	movs r0, 0x9
	movs r1, 0x20
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF9FC
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl sub_81C761C
	str r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CF9FC
	ldr r0, =sub_81CFA68
	str r0, [r4]
	ldr r0, =sub_81CFB74
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	movs r0, 0
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CF9FE
	.pool
_081CF9FC:
	movs r0, 0
_081CF9FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF9BC

	thumb_func_start sub_81CFA04
sub_81CFA04: @ 81CFA04
	push {r4,lr}
	movs r0, 0x9
	movs r1, 0x20
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFA2C
	movs r0, 0x12
	bl sub_81C763C
	str r0, [r4, 0x1C]
	ldr r0, =sub_81CFA88
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0x14]
	b _081CFA2E
	.pool
_081CFA2C:
	movs r0, 0
_081CFA2E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFA04

	thumb_func_start sub_81CFA34
sub_81CFA34: @ 81CFA34
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CFA34

	thumb_func_start sub_81CFA48
sub_81CFA48: @ 81CFA48
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	cmp r0, 0
	bne _081CFA5C
	movs r0, 0x12
	bl sub_81C7650
_081CFA5C:
	movs r0, 0x9
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CFA48

	thumb_func_start sub_81CFA68
sub_81CFA68: @ 81CFA68
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4]
	bl sub_81C70D8
	cmp r0, 0
	bne _081CFA7A
	ldr r0, =sub_81CFA88
	str r0, [r4]
_081CFA7A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFA68

	thumb_func_start sub_81CFA88
sub_81CFA88: @ 81CFA88
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CFAA0
	movs r0, 0x1
	b _081CFAFE
	.pool
_081CFAA0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CFAAC
	movs r0, 0x2
	b _081CFAFE
_081CFAAC:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CFABA
	movs r0, 0x3
	b _081CFAFE
_081CFABA:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CFACA
	movs r0, 0x4
	b _081CFAFE
_081CFACA:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CFAE0
	str r2, [r4, 0x18]
	ldr r0, =sub_81CFB08
	str r0, [r4]
	movs r0, 0x5
	b _081CFAFE
	.pool
_081CFAE0:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081CFAEE
	movs r0, 0
	b _081CFAFE
_081CFAEE:
	bl sub_81C875C
	ldr r1, [r4, 0x1C]
	strh r0, [r1, 0x2]
	str r5, [r4, 0x18]
	ldr r0, =sub_81CFB10
	str r0, [r4]
	movs r0, 0x6
_081CFAFE:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFA88

	thumb_func_start sub_81CFB08
sub_81CFB08: @ 81CFB08
	ldr r0, =0x000186a5
	bx lr
	.pool
	thumb_func_end sub_81CFB08

	thumb_func_start sub_81CFB10
sub_81CFB10: @ 81CFB10
	ldr r0, =0x000186ad
	bx lr
	.pool
	thumb_func_end sub_81CFB10

	thumb_func_start sub_81CFB18
sub_81CFB18: @ 81CFB18
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x14]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB18

	thumb_func_start sub_81CFB28
sub_81CFB28: @ 81CFB28
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	adds r0, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB28

	thumb_func_start sub_81CFB38
sub_81CFB38: @ 81CFB38
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB38

	thumb_func_start sub_81CFB48
sub_81CFB48: @ 81CFB48
	push {r4,lr}
	movs r0, 0x9
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C875C
	ldr r1, [r4, 0x1C]
	lsls r0, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB48

	thumb_func_start sub_81CFB64
sub_81CFB64: @ 81CFB64
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB64

	thumb_func_start sub_81CFB74
sub_81CFB74: @ 81CFB74
	push {lr}
	ldr r2, =gUnknown_086235D8
	lsls r1, r0, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFB74

	thumb_func_start sub_81CFB8C
sub_81CFB8C: @ 81CFB8C
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x9
	bl sub_81C763C
	adds r6, r0, 0
	ldr r0, [r6, 0x1C]
	movs r1, 0
	strh r1, [r0]
	ldr r0, [r6, 0x1C]
	strh r1, [r0, 0x2]
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xE
	orrs r0, r1
	str r0, [sp]
	movs r5, 0
_081CFBB0:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CFC10
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CFC0A
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMonData
	cmp r0, 0
	bne _081CFC0A
	adds r0, r4, 0
	movs r1, 0x52
	bl GetMonData
	adds r3, r0, 0
	cmp r3, 0
	beq _081CFC0A
	lsls r1, r5, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CFCEC
_081CFC0A:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CFBB0
_081CFC10:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFB8C

	thumb_func_start sub_81CFC2C
sub_81CFC2C: @ 81CFC2C
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	movs r1, 0
	str r1, [r0, 0x10]
	str r1, [r0, 0xC]
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81CFC2C

	thumb_func_start sub_81CFC40
sub_81CFC40: @ 81CFC40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0x9
	bl sub_81C763C
	mov r8, r0
	ldr r7, [r0, 0xC]
	ldr r6, [r0, 0x10]
	movs r0, 0
	mov r9, r0
	cmp r7, 0xD
	bgt _081CFCD4
	b _081CFCC8
_081CFC60:
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80D2270
	cmp r0, 0
	beq _081CFCA6
	lsls r0, r7, 24
	lsrs r5, r0, 24
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x52
	bl get_pokemon_data_from_any_box
	adds r3, r0, 0
	cmp r3, 0
	beq _081CFCA6
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r5
	lsls r2, r4, 8
	ldr r1, =0xffff00ff
	ands r0, r1
	orrs r0, r2
	lsls r2, r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, r8
	mov r1, sp
	bl sub_81CFCEC
_081CFCA6:
	movs r1, 0x1
	add r9, r1
	adds r6, 0x1
	mov r0, r9
	cmp r0, 0xE
	ble _081CFCC8
	mov r1, r8
	str r7, [r1, 0xC]
	str r6, [r1, 0x10]
	movs r0, 0x3
	b _081CFCDC
	.pool
_081CFCC8:
	cmp r6, 0x1D
	ble _081CFC60
	movs r6, 0
	adds r7, 0x1
	cmp r7, 0xD
	ble _081CFCC8
_081CFCD4:
	movs r0, 0x1
	mov r1, r8
	str r0, [r1, 0x14]
	movs r0, 0x4
_081CFCDC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFC40

	thumb_func_start sub_81CFCEC
sub_81CFCEC: @ 81CFCEC
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldr r0, [r5, 0x1C]
	ldrh r2, [r0]
	lsrs r3, r2, 1
	cmp r2, r3
	beq _081CFD1C
	adds r6, r0, 0
	ldrh r4, [r7, 0x2]
_081CFD02:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x6]
	cmp r4, r0
	bls _081CFD10
	adds r2, r3, 0
	b _081CFD12
_081CFD10:
	adds r1, r3, 0x1
_081CFD12:
	subs r0, r2, r1
	lsrs r0, 1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CFD02
_081CFD1C:
	ldr r0, [r5, 0x1C]
	ldrh r2, [r0]
	lsls r6, r3, 2
	cmp r2, r3
	bls _081CFD40
	lsls r0, r2, 2
	subs r4, r0, 0x4
_081CFD2A:
	ldr r0, [r5, 0x1C]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, 0x4
	subs r2, 0x1
	cmp r2, r3
	bhi _081CFD2A
_081CFD40:
	ldr r0, [r5, 0x1C]
	adds r0, 0x4
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, 0x1C]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CFCEC

	thumb_func_start sub_81CFD58
sub_81CFD58: @ 81CFD58
	push {r4-r6,lr}
	movs r5, 0
_081CFD5C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CFD8A
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CFD8A
	adds r0, r4, 0
	movs r1, 0x53
	bl GetMonData
	cmp r0, 0
	bne _081CFDB2
_081CFD8A:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CFD5C
	movs r5, 0
_081CFD92:
	movs r4, 0
	lsls r6, r5, 24
_081CFD96:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80D2270
	cmp r0, 0
	beq _081CFDBC
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	movs r2, 0x53
	bl get_pokemon_data_from_any_box
	cmp r0, 0
	beq _081CFDBC
_081CFDB2:
	movs r0, 0x1
	b _081CFDCA
	.pool
_081CFDBC:
	adds r4, 0x1
	cmp r4, 0x1D
	ble _081CFD96
	adds r5, 0x1
	cmp r5, 0xD
	ble _081CFD92
	movs r0, 0
_081CFDCA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFD58

	thumb_func_start sub_81CFDD0
sub_81CFDD0: @ 81CFDD0
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0xA
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFE00
	ldr r0, =sub_81CFEB8
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r4]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081CFE02
	.pool
_081CFE00:
	movs r0, 0
_081CFE02:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFDD0

	thumb_func_start sub_81CFE08
sub_81CFE08: @ 81CFE08
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0xA
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFE38
	ldr r0, =sub_81CFEB8
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0xC]
	b _081CFE3A
	.pool
_081CFE38:
	movs r0, 0
_081CFE3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE08

	thumb_func_start sub_81CFE40
sub_81CFE40: @ 81CFE40
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_086237B8
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CFE40

	thumb_func_start sub_81CFE70
sub_81CFE70: @ 81CFE70
	push {lr}
	movs r0, 0xA
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE70

	thumb_func_start sub_81CFE84
sub_81CFE84: @ 81CFE84
	push {lr}
	movs r0, 0xA
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE84

	thumb_func_start sub_81CFE98
sub_81CFE98: @ 81CFE98
	push {r4,lr}
	movs r0, 0xA
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C8234
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0xA
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CFE98

	thumb_func_start sub_81CFEB8
sub_81CFEB8: @ 81CFEB8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x5
	bls _081CFECC
	b _081CFFF2
_081CFECC:
	lsls r0, r4, 2
	ldr r1, =_081CFEDC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CFEDC:
	.4byte _081CFEF4
	.4byte _081CFF48
	.4byte _081CFF76
	.4byte _081CFF94
	.4byte _081CFFA4
	.4byte _081CFFDE
_081CFEF4:
	ldr r0, =gUnknown_086237B0
	movs r1, 0x2
	bl sub_81C7B54
	ldr r1, =gUnknown_08623604
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x10
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086236CC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_086235E4
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081CFF32:
	movs r0, 0
	b _081CFFF4
	.pool
_081CFF48:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	bl sub_81CFB18
	cmp r0, 0
	beq _081CFFEE
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	b _081CFF32
_081CFF76:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	ldr r0, =gUnknown_08623790
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	bl sub_81D0304
	b _081CFF32
	.pool
_081CFF94:
	bl sub_81C8224
	cmp r0, 0
	bne _081CFFEE
	adds r0, r5, 0
	bl sub_81D024C
	b _081CFF32
_081CFFA4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x9
	bl sub_81C7BA4
	movs r0, 0x1
	bl sub_81C7AC0
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _081CFF32
	movs r0, 0x2
	bl sub_81C7DFC
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	b _081CFF32
_081CFFDE:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CFFEE
	bl sub_81C8010
	cmp r0, 0
	beq _081CFFF2
_081CFFEE:
	movs r0, 0x2
	b _081CFFF4
_081CFFF2:
	movs r0, 0x4
_081CFFF4:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFEB8

	thumb_func_start sub_81CFFFC
sub_81CFFFC: @ 81CFFFC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D004A
	cmp r4, 0x1
	bgt _081D0016
	cmp r4, 0
	beq _081D0020
	b _081D006A
_081D0016:
	cmp r4, 0x2
	beq _081D0052
	cmp r4, 0x3
	beq _081D005C
	b _081D006A
_081D0020:
	bl sub_81C8658
	cmp r0, 0x1
	beq _081D0038
	cmp r0, 0x1
	bgt _081D0032
	cmp r0, 0
	beq _081D006A
	b _081D0058
_081D0032:
	cmp r0, 0x2
	beq _081D0042
	b _081D0058
_081D0038:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081D006C
_081D0042:
	movs r0, 0x5
	bl audio_play
	b _081D0058
_081D004A:
	bl sub_81C8630
	cmp r0, 0
	bne _081D0066
_081D0052:
	adds r0, r5, 0
	bl sub_81D0288
_081D0058:
	movs r0, 0
	b _081D006C
_081D005C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D006A
_081D0066:
	movs r0, 0x2
	b _081D006C
_081D006A:
	movs r0, 0x4
_081D006C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFFFC

	thumb_func_start sub_81D0074
sub_81D0074: @ 81D0074
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D00C2
	cmp r4, 0x1
	bgt _081D008E
	cmp r4, 0
	beq _081D0098
	b _081D00E2
_081D008E:
	cmp r4, 0x2
	beq _081D00CA
	cmp r4, 0x3
	beq _081D00D4
	b _081D00E2
_081D0098:
	bl sub_81C868C
	cmp r0, 0x1
	beq _081D00B0
	cmp r0, 0x1
	bgt _081D00AA
	cmp r0, 0
	beq _081D00E2
	b _081D00D0
_081D00AA:
	cmp r0, 0x2
	beq _081D00BA
	b _081D00D0
_081D00B0:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081D00E4
_081D00BA:
	movs r0, 0x5
	bl audio_play
	b _081D00D0
_081D00C2:
	bl sub_81C8630
	cmp r0, 0
	bne _081D00DE
_081D00CA:
	adds r0, r5, 0
	bl sub_81D0288
_081D00D0:
	movs r0, 0
	b _081D00E4
_081D00D4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D00E2
_081D00DE:
	movs r0, 0x2
	b _081D00E4
_081D00E2:
	movs r0, 0x4
_081D00E4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0074

	thumb_func_start sub_81D00EC
sub_81D00EC: @ 81D00EC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D013A
	cmp r4, 0x1
	bgt _081D0106
	cmp r4, 0
	beq _081D0110
	b _081D015A
_081D0106:
	cmp r4, 0x2
	beq _081D0142
	cmp r4, 0x3
	beq _081D014C
	b _081D015A
_081D0110:
	bl sub_81C86CC
	cmp r0, 0x1
	beq _081D0128
	cmp r0, 0x1
	bgt _081D0122
	cmp r0, 0
	beq _081D015A
	b _081D0148
_081D0122:
	cmp r0, 0x2
	beq _081D0132
	b _081D0148
_081D0128:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081D015C
_081D0132:
	movs r0, 0x5
	bl audio_play
	b _081D0148
_081D013A:
	bl sub_81C8630
	cmp r0, 0
	bne _081D0156
_081D0142:
	adds r0, r5, 0
	bl sub_81D0288
_081D0148:
	movs r0, 0
	b _081D015C
_081D014C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D015A
_081D0156:
	movs r0, 0x2
	b _081D015C
_081D015A:
	movs r0, 0x4
_081D015C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D00EC

	thumb_func_start sub_81D0164
sub_81D0164: @ 81D0164
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D01B2
	cmp r4, 0x1
	bgt _081D017E
	cmp r4, 0
	beq _081D0188
	b _081D01D2
_081D017E:
	cmp r4, 0x2
	beq _081D01BA
	cmp r4, 0x3
	beq _081D01C4
	b _081D01D2
_081D0188:
	bl sub_81C870C
	cmp r0, 0x1
	beq _081D01A0
	cmp r0, 0x1
	bgt _081D019A
	cmp r0, 0
	beq _081D01D2
	b _081D01C0
_081D019A:
	cmp r0, 0x2
	beq _081D01AA
	b _081D01C0
_081D01A0:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x7
	b _081D01D4
_081D01AA:
	movs r0, 0x5
	bl audio_play
	b _081D01C0
_081D01B2:
	bl sub_81C8630
	cmp r0, 0
	bne _081D01CE
_081D01BA:
	adds r0, r5, 0
	bl sub_81D0288
_081D01C0:
	movs r0, 0
	b _081D01D4
_081D01C4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D01D2
_081D01CE:
	movs r0, 0x2
	b _081D01D4
_081D01D2:
	movs r0, 0x4
_081D01D4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0164

	thumb_func_start sub_81D01DC
sub_81D01DC: @ 81D01DC
	push {lr}
	cmp r0, 0
	beq _081D01E8
	cmp r0, 0x1
	beq _081D01FC
	b _081D0214
_081D01E8:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081D0216
_081D01FC:
	bl sub_81C7B34
	cmp r0, 0
	bne _081D020C
	bl sub_81C78C0
	cmp r0, 0
	beq _081D0210
_081D020C:
	movs r0, 0x2
	b _081D0216
_081D0210:
	bl sub_81C7FDC
_081D0214:
	movs r0, 0x4
_081D0216:
	pop {r1}
	bx r1
	thumb_func_end sub_81D01DC

	thumb_func_start sub_81D021C
sub_81D021C: @ 81D021C
	push {lr}
	cmp r0, 0
	beq _081D0228
	cmp r0, 0x1
	beq _081D0238
	b _081D0244
_081D0228:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081D0246
_081D0238:
	bl sub_81C7B34
	cmp r0, 0
	beq _081D0244
	movs r0, 0x2
	b _081D0246
_081D0244:
	movs r0, 0x4
_081D0246:
	pop {r1}
	bx r1
	thumb_func_end sub_81D021C

	thumb_func_start sub_81D024C
sub_81D024C: @ 81D024C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086237D4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	bl sub_81CFB38
	adds r2, r0, 0
	ldrh r0, [r4, 0x8]
	movs r1, 0
	bl sub_81D02B0
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	adds r0, r4, 0
	bl sub_81D0288
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D024C

	thumb_func_start sub_81D0288
sub_81D0288: @ 81D0288
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81C875C
	adds r4, r0, 0
	bl sub_81CFB38
	adds r2, r0, 0
	ldrh r0, [r5, 0x8]
	adds r4, 0x1
	adds r1, r4, 0
	bl sub_81D02B0
	ldrb r0, [r5, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0288

	thumb_func_start sub_81D02B0
sub_81D02B0: @ 81D02B0
	push {r4,r5,lr}
	sub sp, 0x1C
	adds r4, r0, 0
	adds r5, r2, 0
	add r0, sp, 0xC
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl Print
	add sp, 0x1C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D02B0

	thumb_func_start sub_81D0304
sub_81D0304: @ 81D0304
	push {r4,lr}
	sub sp, 0x18
	bl sub_81CFB28
	str r0, [sp]
	bl sub_81CFB38
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_81CFB64
	mov r1, sp
	strh r0, [r1, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x11
	strb r0, [r1, 0xA]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0xD]
	mov r0, sp
	strb r2, [r0, 0xE]
	ldr r0, =sub_81D035C
	str r0, [sp, 0x10]
	str r4, [sp, 0x14]
	ldr r0, =gUnknown_086237B4
	movs r2, 0
	bl sub_81C81D4
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0304

	thumb_func_start sub_81D035C
sub_81D035C: @ 81D035C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r1, 0
	adds r7, r0, 0
	ldrb r0, [r7]
	cmp r0, 0xE
	bne _081D03A4
	ldrb r1, [r7, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	bl pokemon_get_gender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl level_by_exp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMonData
	b _081D03CC
	.pool
_081D03A4:
	ldrb r0, [r7]
	ldrb r1, [r7, 0x1]
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	bl pokemon_roll_gender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl sub_80690C0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl pokemon_getattr_encrypted
_081D03CC:
	ldr r4, =gStringVar3
	adds r0, r4, 0
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3C
	bl sub_81DB494
	adds r6, r0, 0
	cmp r5, 0
	beq _081D03F8
	cmp r5, 0xFE
	beq _081D0400
	ldr r1, =gUnknown_086237F4
	b _081D0402
	.pool
_081D03F8:
	ldr r1, =gUnknown_086237DC
	b _081D0402
	.pool
_081D0400:
	ldr r1, =gUnknown_086237E8
_081D0402:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x36
	bl sub_81DB494
	adds r6, r0, 0
	ldrh r1, [r7, 0x2]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D035C

	thumb_func_start sub_81D0450
sub_81D0450: @ 81D0450
	push {r4,lr}
	movs r0, 0xD
	movs r1, 0x9C
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081D0498
	movs r0, 0x12
	bl sub_81C763C
	str r0, [r4, 0x8]
	cmp r0, 0
	beq _081D0498
	adds r0, r4, 0
	bl sub_81D0814
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D04C4
	str r0, [r1]
	ldr r1, =gKeyRepeatContinueDelay
	movs r0, 0x3
	strh r0, [r1]
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0xA
	strh r0, [r1]
	movs r0, 0x1
	b _081D049A
	.pool
_081D0498:
	movs r0, 0
_081D049A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0450

	thumb_func_start sub_81D04A0
sub_81D04A0: @ 81D04A0
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	adds r1, r0, 0
	adds r1, 0x98
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81D04A0

	thumb_func_start sub_81D04B8
sub_81D04B8: @ 81D04B8
	push {lr}
	movs r0, 0xD
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81D04B8

	thumb_func_start sub_81D04C4
sub_81D04C4: @ 81D04C4
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081D04E4
	ldr r3, [r4, 0x8]
	ldrh r0, [r3, 0x2]
	cmp r0, 0
	beq _081D04E4
	subs r0, 0x1
	b _081D04FC
	.pool
_081D04E4:
	ldrh r1, [r2, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081D050C
	ldr r3, [r4, 0x8]
	ldrh r1, [r3, 0x2]
	ldrh r0, [r3]
	subs r0, 0x1
	cmp r1, r0
	bge _081D050C
	adds r0, r1, 0x1
_081D04FC:
	movs r1, 0
	strh r0, [r3, 0x2]
	strh r1, [r4, 0xC]
	adds r0, r4, 0
	bl sub_81D0814
	movs r0, 0x1
	b _081D053E
_081D050C:
	ldrh r2, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _081D0528
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D0548
	str r0, [r1]
	movs r0, 0x2
	b _081D053E
	.pool
_081D0528:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _081D0534
	movs r0, 0
	b _081D053E
_081D0534:
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D05D4
	str r0, [r1]
	movs r0, 0x5
_081D053E:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D04C4

	thumb_func_start sub_81D0548
sub_81D0548: @ 81D0548
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081D0562
	adds r0, r4, 0
	bl sub_81D05DC
	cmp r0, 0
	bne _081D05A4
_081D0562:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081D0578
	adds r0, r4, 0
	bl sub_81D061C
	cmp r0, 0
	bne _081D05A4
_081D0578:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081D058E
	adds r0, r4, 0
	bl sub_81D0664
	cmp r0, 0
	bne _081D05A4
_081D058E:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D05AC
	adds r0, r4, 0
	bl sub_81D0688
	cmp r0, 0
	beq _081D05AC
_081D05A4:
	movs r0, 0x3
	b _081D05CA
	.pool
_081D05AC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D05C0
	movs r0, 0
	b _081D05CA
	.pool
_081D05C0:
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D04C4
	str r0, [r1]
	movs r0, 0x4
_081D05CA:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D0548

	thumb_func_start sub_81D05D4
sub_81D05D4: @ 81D05D4
	ldr r0, =0x000186ae
	bx lr
	.pool
	thumb_func_end sub_81D05D4

	thumb_func_start sub_81D05DC
sub_81D05DC: @ 81D05DC
	push {r4,lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	adds r2, r0, 0
	cmp r2, 0x18
	bhi _081D05F0
	cmp r2, 0x8
	bls _081D0612
	subs r0, 0x9
	b _081D060C
_081D05F0:
	ldrh r3, [r1, 0x10]
	adds r2, r3, 0
	cmp r2, 0
	beq _081D0612
	ldrh r0, [r1, 0xC]
	subs r0, 0x1B
	ldrh r4, [r1, 0xE]
	adds r0, r4
	strh r0, [r1, 0xC]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r2
	bcc _081D060E
	subs r0, r3, 0x1
_081D060C:
	strh r0, [r1, 0xC]
_081D060E:
	movs r0, 0x1
	b _081D0614
_081D0612:
	movs r0, 0
_081D0614:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D05DC

	thumb_func_start sub_81D061C
sub_81D061C: @ 81D061C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0xC]
	adds r1, r0, 0
	cmp r1, 0x18
	bhi _081D065C
	ldrh r3, [r2, 0xE]
	cmp r1, r3
	bcs _081D0640
	adds r0, 0x9
	strh r0, [r2, 0xC]
	ldrh r1, [r2, 0x10]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bcc _081D0658
	subs r0, r1, 0x1
	b _081D0656
_081D0640:
	ldrh r0, [r2, 0x12]
	cmp r0, 0
	beq _081D065C
	ldrh r1, [r2, 0xC]
	ldrh r0, [r2, 0xE]
	subs r0, r1, r0
	ldrh r1, [r2, 0x12]
	cmp r0, r1
	blt _081D0654
	subs r0, r1, 0x1
_081D0654:
	adds r0, 0x1B
_081D0656:
	strh r0, [r2, 0xC]
_081D0658:
	movs r0, 0x1
	b _081D065E
_081D065C:
	movs r0, 0
_081D065E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D061C

	thumb_func_start sub_81D0664
sub_81D0664: @ 81D0664
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D067C
	movs r0, 0
	b _081D0682
_081D067C:
	subs r0, r4, 0x1
	strh r0, [r5, 0xC]
	movs r0, 0x1
_081D0682:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0664

	thumb_func_start sub_81D0688
sub_81D0688: @ 81D0688
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bgt _081D06BC
	cmp r4, 0x1A
	bhi _081D06AC
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	cmp r4, r0
	bge _081D06BC
	b _081D06B4
_081D06AC:
	ldrh r0, [r5, 0x12]
	subs r0, 0x1
	cmp r1, r0
	bge _081D06BC
_081D06B4:
	adds r0, r4, 0x1
	strh r0, [r5, 0xC]
	movs r0, 0x1
	b _081D06BE
_081D06BC:
	movs r0, 0
_081D06BE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0688

	thumb_func_start sub_81D06C4
sub_81D06C4: @ 81D06C4
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldr r0, [r0, 0x8]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81D06C4

	thumb_func_start sub_81D06D4
sub_81D06D4: @ 81D06D4
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81D06D4

	thumb_func_start sub_81D06E4
sub_81D06E4: @ 81D06E4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r0, 0xD
	bl sub_81C763C
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D0730
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl GetMonData
	adds r0, r4, 0
	bl level_by_exp
	strb r0, [r7]
	adds r0, r4, 0
	bl pokemon_get_gender
	strb r0, [r6]
	b _081D0752
	.pool
_081D0730:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	bl pokemon_roll_gender
	strb r0, [r6]
	adds r0, r4, 0
	bl sub_80690C0
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl pokemon_getattr_encrypted
_081D0752:
	adds r0, r5, 0
	bl StringGetEnd10
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D06E4

	thumb_func_start sub_81D0760
sub_81D0760: @ 81D0760
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r0, 0xD
	bl sub_81C763C
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D07AC
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r6]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	b _081D07D0
	.pool
_081D07AC:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	movs r1, 0xB
	bl pokemon_getattr_encrypted
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl pokemon_getattr_encrypted
	str r0, [r6]
	adds r0, r4, 0
	movs r1, 0x1
	bl pokemon_getattr_encrypted
_081D07D0:
	str r0, [r7]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0760

	thumb_func_start sub_81D07D8
sub_81D07D8: @ 81D07D8
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	beq _081D07FA
	ldrb r1, [r1, 0x1]
	movs r2, 0x52
	bl get_pokemon_data_from_any_box
	b _081D080A
_081D07FA:
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x52
	bl GetMonData
_081D080A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D07D8

	thumb_func_start sub_81D0814
sub_81D0814: @ 81D0814
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r1, 0x4
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D0848
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x53
	bl GetMonData
	b _081D0852
	.pool
_081D0848:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	movs r2, 0x53
	bl get_pokemon_data_from_any_box
_081D0852:
	mov r12, r0
	movs r0, 0
	strh r0, [r5, 0x10]
	strh r0, [r5, 0x12]
	movs r6, 0
	ldr r0, =gUnknown_086237F8
	mov r9, r0
	mov r10, r9
_081D0862:
	lsls r2, r6, 2
	mov r3, r9
	adds r1, r2, r3
	movs r0, 0x1
	ldrb r3, [r1]
	lsls r0, r3
	subs r4, r0, 0x1
	mov r0, r12
	ands r4, r0
	ldrb r0, [r1, 0x3]
	adds r7, r2, 0
	cmp r0, 0
	bne _081D08AC
	movs r3, 0
	adds r6, 0x1
	mov r8, r6
	cmp r3, r4
	bge _081D08D6
	adds r6, r5, 0
	adds r6, 0x14
	mov r1, r10
	adds r0, r7, r1
	ldrb r2, [r0, 0x2]
_081D0890:
	ldrh r0, [r5, 0x10]
	adds r1, r0, 0x1
	strh r1, [r5, 0x10]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r6, r0
	adds r1, r2, r3
	str r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _081D0890
	b _081D08D6
	.pool
_081D08AC:
	movs r3, 0
	adds r6, 0x1
	mov r8, r6
	cmp r3, r4
	bge _081D08D6
	adds r6, r5, 0
	adds r6, 0x78
	mov r1, r10
	adds r0, r7, r1
	ldrb r2, [r0, 0x2]
_081D08C0:
	ldrh r0, [r5, 0x12]
	adds r1, r0, 0x1
	strh r1, [r5, 0x12]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r6, r0
	adds r1, r2, r3
	str r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _081D08C0
_081D08D6:
	mov r3, r9
	adds r0, r7, r3
	mov r1, r12
	ldrb r0, [r0]
	lsrs r1, r0
	mov r12, r1
	mov r6, r8
	cmp r6, 0x10
	bls _081D0862
	ldrh r0, [r5, 0x10]
	cmp r0, 0
	beq _081D0900
	subs r0, 0x1
	movs r1, 0x9
	bl __divsi3
	lsls r1, r0, 3
	adds r1, r0
	movs r0, 0
	strh r1, [r5, 0xE]
	b _081D0904
_081D0900:
	strh r0, [r5, 0xE]
	movs r0, 0x1B
_081D0904:
	strh r0, [r5, 0xC]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0814

	thumb_func_start sub_81D0914
sub_81D0914: @ 81D0914
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xD
	bl sub_81C763C
	ldrh r1, [r0, 0x10]
	str r1, [r4]
	adds r0, 0x14
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0914

	thumb_func_start sub_81D092C
sub_81D092C: @ 81D092C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xD
	bl sub_81C763C
	ldrh r1, [r0, 0x12]
	str r1, [r4]
	adds r0, 0x78
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D092C

	thumb_func_start sub_81D0944
sub_81D0944: @ 81D0944
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldrh r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81D0944

	thumb_func_start sub_81D0954
sub_81D0954: @ 81D0954
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	cmp r0, 0x18
	ble _081D096C
	subs r0, 0x1B
	lsls r0, 2
	adds r1, 0x78
	b _081D0970
_081D096C:
	lsls r0, 2
	adds r1, 0x14
_081D0970:
	adds r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	thumb_func_end sub_81D0954

	thumb_func_start sub_81D0978
sub_81D0978: @ 81D0978
	push {r4,lr}
	ldr r1, =0x0000101c
	movs r0, 0xE
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081D09A8
	ldr r0, =sub_81D0A6C
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81D0A58
	str r0, [r4]
	movs r0, 0x1
	b _081D09AA
	.pool
_081D09A8:
	movs r0, 0
_081D09AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0978

	thumb_func_start sub_81D09B0
sub_81D09B0: @ 81D09B0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08624BA0
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81D0A58
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D09B0

	thumb_func_start sub_81D09E0
sub_81D09E0: @ 81D09E0
	push {lr}
	movs r0, 0xE
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81D09E0

	thumb_func_start sub_81D09F4
sub_81D09F4: @ 81D09F4
	push {r4,lr}
	movs r0, 0xE
	bl sub_81C763C
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl RemoveWindow
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	ldrb r0, [r4, 0xC]
	bl RemoveWindow
	ldrb r0, [r4, 0xE]
	bl RemoveWindow
	adds r0, r4, 0
	bl sub_81D1178
	movs r0, 0x9
	bl FreeObjectTilesByTag
	movs r0, 0xF
	bl FreeObjectPaletteByTag
	movs r0, 0x10
	bl FreeObjectPaletteByTag
	movs r0, 0x11
	bl FreeObjectPaletteByTag
	movs r0, 0x12
	bl FreeObjectPaletteByTag
	movs r0, 0x13
	bl FreeObjectPaletteByTag
	ldr r0, [r4, 0x14]
	bl obj_free_rotscale_entry
	ldr r0, [r4, 0x14]
	bl DestroySprite
	movs r0, 0xE
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D09F4

	thumb_func_start sub_81D0A58
sub_81D0A58: @ 81D0A58
	push {lr}
	movs r0, 0xE
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81D0A58

	thumb_func_start sub_81D0A6C
sub_81D0A6C: @ 81D0A6C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x9
	bls _081D0A80
	b _081D0C48
_081D0A80:
	lsls r0, r4, 2
	ldr r1, =_081D0A90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D0A90:
	.4byte _081D0AB8
	.4byte _081D0B04
	.4byte _081D0B74
	.4byte _081D0B88
	.4byte _081D0B9C
	.4byte _081D0BB0
	.4byte _081D0BC4
	.4byte _081D0BD8
	.4byte _081D0BE8
	.4byte _081D0C3C
_081D0AB8:
	ldr r0, =gUnknown_08624B98
	movs r1, 0x2
	bl sub_81C7B54
	ldr r1, =gUnknown_08DDE030
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x1C
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DDE12C
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_08DDE010
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	b _081D0BBA
	.pool
_081D0B04:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _081D0B12
	b _081D0C44
_081D0B12:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	ldr r1, =gUnknown_086240B8
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0x1
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =0x0000081c
	adds r1, r5, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =gUnknown_08623FF8
	movs r1, 0x20
	movs r2, 0xA0
	bl sub_81C7944
	ldr r0, =gUnknown_08624098
	movs r1, 0xA0
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	b _081D0BBC
	.pool
_081D0B74:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D0E60
	movs r0, 0
	b _081D0C4A
_081D0B88:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D0FCC
	movs r0, 0
	b _081D0C4A
_081D0B9C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D10A4
	movs r0, 0
	b _081D0C4A
_081D0BB0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
_081D0BBA:
	movs r0, 0x2
_081D0BBC:
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081D0C4A
_081D0BC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D1148
	movs r0, 0x1
	b _081D0C4A
_081D0BD8:
	adds r0, r5, 0
	bl sub_81D12D8
	movs r0, 0xA
	bl sub_81C7BA4
	movs r0, 0
	b _081D0C4A
_081D0BE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D13FC
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	bl sub_81C7AC0
	movs r0, 0
	b _081D0C4A
_081D0C3C:
	bl sub_81C7B34
	cmp r0, 0
	beq _081D0C48
_081D0C44:
	movs r0, 0x2
	b _081D0C4A
_081D0C48:
	movs r0, 0x4
_081D0C4A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0A6C

	thumb_func_start sub_81D0C54
sub_81D0C54: @ 81D0C54
	push {lr}
	cmp r0, 0
	beq _081D0C60
	cmp r0, 0x1
	beq _081D0C70
	b _081D0C7C
_081D0C60:
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081D0C7E
_081D0C70:
	bl sub_81C7B34
	cmp r0, 0
	beq _081D0C7C
	movs r0, 0x2
	b _081D0C7E
_081D0C7C:
	movs r0, 0x4
_081D0C7E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D0C54

	thumb_func_start sub_81D0C84
sub_81D0C84: @ 81D0C84
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x6
	bhi _081D0D24
	lsls r0, r5, 2
	ldr r1, =_081D0CA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D0CA4:
	.4byte _081D0CC0
	.4byte _081D0CD0
	.4byte _081D0CE4
	.4byte _081D0CEE
	.4byte _081D0CF8
	.4byte _081D0D02
	.4byte _081D0D16
_081D0CC0:
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl sub_81D11D8
	movs r0, 0
	b _081D0D26
_081D0CD0:
	adds r0, r4, 0
	bl sub_81D1234
	cmp r0, 0
	bne _081D0D20
	adds r0, r4, 0
	bl sub_81D0FF0
	movs r0, 0x1
	b _081D0D26
_081D0CE4:
	adds r0, r4, 0
	bl sub_81D12D8
	movs r0, 0x1
	b _081D0D26
_081D0CEE:
	adds r0, r4, 0
	bl sub_81D10D0
	movs r0, 0x1
	b _081D0D26
_081D0CF8:
	adds r0, r4, 0
	bl sub_81D0E84
	movs r0, 0x1
	b _081D0D26
_081D0D02:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0D20
	adds r0, r4, 0
	bl sub_81D11FC
	movs r0, 0
	b _081D0D26
_081D0D16:
	adds r0, r4, 0
	bl sub_81D1234
	cmp r0, 0
	beq _081D0D24
_081D0D20:
	movs r0, 0x2
	b _081D0D26
_081D0D24:
	movs r0, 0x4
_081D0D26:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0C84

	thumb_func_start sub_81D0D2C
sub_81D0D2C: @ 81D0D2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0D5C
	cmp r4, 0x1
	bgt _081D0D46
	cmp r4, 0
	beq _081D0D4C
	b _081D0D84
_081D0D46:
	cmp r4, 0x2
	beq _081D0D76
	b _081D0D84
_081D0D4C:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81D1448
	movs r0, 0
	b _081D0D86
_081D0D5C:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0D80
	adds r0, r5, 0
	bl sub_81D0EFC
	movs r0, 0xB
	bl sub_81C7BA4
	movs r0, 0
	b _081D0D86
_081D0D76:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0D84
_081D0D80:
	movs r0, 0x2
	b _081D0D86
_081D0D84:
	movs r0, 0x4
_081D0D86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0D2C

	thumb_func_start sub_81D0D8C
sub_81D0D8C: @ 81D0D8C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0DC0
	cmp r4, 0x1
	bgt _081D0DA6
	cmp r4, 0
	beq _081D0DB0
	b _081D0DF6
_081D0DA6:
	cmp r4, 0x2
	beq _081D0DD4
	cmp r4, 0x3
	beq _081D0DE8
	b _081D0DF6
_081D0DB0:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81D1500
	movs r0, 0
	b _081D0DF8
_081D0DC0:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0DF2
	adds r0, r5, 0
	bl sub_81D1448
	movs r0, 0
	b _081D0DF8
_081D0DD4:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0DF2
	adds r0, r5, 0
	bl sub_81D0EFC
	movs r0, 0
	b _081D0DF8
_081D0DE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0DF6
_081D0DF2:
	movs r0, 0x2
	b _081D0DF8
_081D0DF6:
	movs r0, 0x4
_081D0DF8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0D8C

	thumb_func_start sub_81D0E00
sub_81D0E00: @ 81D0E00
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0E30
	cmp r4, 0x1
	bgt _081D0E1A
	cmp r4, 0
	beq _081D0E20
	b _081D0E58
_081D0E1A:
	cmp r4, 0x2
	beq _081D0E4A
	b _081D0E58
_081D0E20:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_81D1500
	movs r0, 0
	b _081D0E5A
_081D0E30:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0E54
	adds r0, r5, 0
	bl sub_81D0E84
	movs r0, 0xA
	bl sub_81C7BA4
	movs r0, 0
	b _081D0E5A
_081D0E4A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0E58
_081D0E54:
	movs r0, 0x2
	b _081D0E5A
_081D0E58:
	movs r0, 0x4
_081D0E5A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0E00

	thumb_func_start sub_81D0E60
sub_81D0E60: @ 81D0E60
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624BB8
	bl AddWindow
	strh r0, [r4, 0xA]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	adds r0, r4, 0
	bl sub_81D0E84
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0E60

	thumb_func_start sub_81D0E84
sub_81D0E84: @ 81D0E84
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r1, =gUnknown_08624BC0
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldr r4, =gStringVar1
	bl sub_81D07D8
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	adds r1, r4, 0
	bl sub_81AFC0C
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EC030
	adds r0, r4, 0
	bl sub_81AFC28
	ldrb r0, [r5, 0xA]
	movs r1, 0x44
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0xA]
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	ldrb r0, [r5, 0xA]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0E84

	thumb_func_start sub_81D0EFC
sub_81D0EFC: @ 81D0EFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r7, r0, 0
	bl sub_81D0954
	adds r5, r0, 0
	ldr r1, =gUnknown_08624BC0
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldrb r0, [r7, 0xA]
	movs r1, 0x44
	bl FillWindowPixelBuffer
	cmp r5, 0x18
	bhi _081D0F60
	lsls r1, r5, 3
	ldr r0, =gRibbonDescriptionPointers
	adds r6, r1, r0
	movs r5, 0x80
	lsls r5, 17
	movs r4, 0x1
_081D0F2E:
	ldrb r0, [r7, 0xA]
	lsrs r3, r5, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	ldm r6!, {r1}
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl box_print
	movs r0, 0x80
	lsls r0, 21
	adds r5, r0
	subs r4, 0x1
	cmp r4, 0
	bge _081D0F2E
	b _081D0FAA
	.pool
_081D0F60:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, r5
	ldr r1, =0x0000318f
	adds r0, r1
	ldrb r5, [r0]
	cmp r5, 0
	beq _081D0FB2
	subs r5, 0x1
	movs r4, 0
	ldr r0, =gGiftRibbonDescriptionPointers
	mov r8, r0
	movs r6, 0x80
	lsls r6, 17
_081D0F7C:
	ldrb r0, [r7, 0xA]
	lsrs r3, r6, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	lsls r1, r4, 2
	lsls r2, r5, 3
	adds r1, r2
	add r1, r8
	ldr r1, [r1]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl box_print
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r4, 0x1
	cmp r4, 0x1
	ble _081D0F7C
_081D0FAA:
	ldrb r0, [r7, 0xA]
	movs r1, 0x2
	bl CopyWindowToVram
_081D0FB2:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0EFC

	thumb_func_start sub_81D0FCC
sub_81D0FCC: @ 81D0FCC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624BC4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	adds r0, r4, 0
	bl sub_81D0FF0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0FCC

	thumb_func_start sub_81D0FF0
sub_81D0FF0: @ 81D0FF0
	push {r4-r7,lr}
	sub sp, 0x10
	ldrh r7, [r0, 0x8]
	ldrb r5, [r0, 0x8]
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gStringVar3
	mov r6, sp
	adds r6, 0xD
	adds r0, r4, 0
	add r1, sp, 0xC
	adds r2, r6, 0
	bl sub_81D06E4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl Print
	ldrb r0, [r6]
	cmp r0, 0
	beq _081D1040
	cmp r0, 0xFE
	beq _081D1048
	ldr r1, =gUnknown_08624BE4
	b _081D104A
	.pool
_081D1040:
	ldr r1, =gUnknown_08624BCC
	b _081D104A
	.pool
_081D1048:
	ldr r1, =gUnknown_08624BD8
_081D104A:
	ldr r5, =gStringVar1
	adds r0, r5, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	add r1, sp, 0xC
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	lsls r4, r7, 24
	lsrs r4, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x3C
	bl Print
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0FF0

	thumb_func_start sub_81D10A4
sub_81D10A4: @ 81D10A4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624BE8
	bl AddWindow
	strh r0, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0xC]
	bl PutWindowTilemap
	adds r0, r4, 0
	bl sub_81D10D0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D10A4

	thumb_func_start sub_81D10D0
sub_81D10D0: @ 81D10D0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r8, r0
	bl sub_81D06C4
	adds r4, r0, 0
	adds r4, 0x1
	bl sub_81D06D4
	adds r6, r0, 0
	ldr r5, =gStringVar1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	mov r1, r8
	ldrb r0, [r1, 0xC]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	mov r1, r8
	ldrb r0, [r1, 0xC]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D10D0

	thumb_func_start sub_81D1148
sub_81D1148: @ 81D1148
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r1, sp, 0x4
	add r2, sp, 0x8
	mov r0, sp
	bl sub_81D0760
	bl dp13_810BB8C
	movs r0, 0x28
	movs r1, 0x68
	bl sub_81D1184
	strh r0, [r4, 0x10]
	movs r0, 0xF
	movs r1, 0
	bl sub_81C7990
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1148

	thumb_func_start sub_81D1178
sub_81D1178: @ 81D1178
	push {lr}
	ldrh r0, [r0, 0x10]
	bl sub_818D820
	pop {r0}
	bx r0
	thumb_func_end sub_81D1178

	thumb_func_start sub_81D1184
sub_81D1184: @ 81D1184
	push {lr}
	sub sp, 0x1C
	add r1, sp, 0x14
	add r2, sp, 0x18
	add r0, sp, 0x10
	bl sub_81D0760
	add r0, sp, 0x10
	ldrh r0, [r0]
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x14]
	movs r3, 0x28
	str r3, [sp]
	movs r3, 0x68
	str r3, [sp, 0x4]
	movs r3, 0xF
	str r3, [sp, 0x8]
	ldr r3, =0x0000ffff
	str r3, [sp, 0xC]
	movs r3, 0x1
	bl sub_818D7D8
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	strb r1, [r2, 0x5]
	add sp, 0x1C
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1184

	thumb_func_start sub_81D11D8
sub_81D11D8: @ 81D11D8
	push {lr}
	ldrh r1, [r0, 0x10]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0x20
	negs r2, r2
	movs r1, 0x28
	movs r3, 0x6
	bl sub_81D1258
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D11D8

	thumb_func_start sub_81D11FC
sub_81D11FC: @ 81D11FC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	bl sub_818D820
	movs r5, 0x20
	negs r5, r5
	adds r0, r5, 0
	movs r1, 0x68
	bl sub_81D1184
	strh r0, [r4, 0x10]
	ldrh r1, [r4, 0x10]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r1, r5, 0
	movs r2, 0x28
	movs r3, 0x6
	bl sub_81D1258
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D11FC

	thumb_func_start sub_81D1234
sub_81D1234: @ 81D1234
	ldr r2, =gSprites
	ldrh r1, [r0, 0x10]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81D1234

	thumb_func_start sub_81D1258
sub_81D1258: @ 81D1258
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r2, 0
	adds r5, r3, 0
	subs r0, r6, r1
	strh r1, [r4, 0x20]
	lsls r1, 4
	strh r1, [r4, 0x2E]
	lsls r0, 4
	adds r1, r5, 0
	bl __udivsi3
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	strh r6, [r4, 0x34]
	ldr r0, =sub_81D1284
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1258

	thumb_func_start sub_81D1284
sub_81D1284: @ 81D1284
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x32]
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081D12C8
	subs r0, r1, 0x1
	strh r0, [r2, 0x32]
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x2E]
	adds r0, r1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bgt _081D12BA
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _081D12D0
_081D12BA:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _081D12D0
_081D12C8:
	ldrh r0, [r2, 0x34]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081D12D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1284

	thumb_func_start sub_81D12D8
sub_81D12D8: @ 81D12D8
	push {r4-r6,lr}
	bl sub_81D1350
	ldr r5, =gUnknown_030012C0
	adds r0, r5, 0
	bl sub_81D0914
	adds r6, r0, 0
	ldr r2, =gUnknown_030012C4
	movs r1, 0
	str r1, [r2]
	ldr r0, [r5]
	cmp r1, r0
	bcs _081D130A
	adds r4, r2, 0
_081D12F6:
	ldr r0, [r4]
	ldm r6!, {r1}
	bl sub_81D1370
	ldr r1, [r4]
	adds r1, 0x1
	str r1, [r4]
	ldr r0, [r5]
	cmp r1, r0
	bcc _081D12F6
_081D130A:
	ldr r4, =gUnknown_030012C0
	adds r0, r4, 0
	bl sub_81D092C
	adds r6, r0, 0
	ldr r2, =gUnknown_030012C4
	movs r1, 0
	str r1, [r2]
	ldr r0, [r4]
	cmp r1, r0
	bcs _081D133A
	adds r4, r2, 0
_081D1322:
	ldr r0, [r4]
	adds r0, 0x1B
	ldm r6!, {r1}
	bl sub_81D1370
	ldr r1, [r4]
	adds r1, 0x1
	str r1, [r4]
	ldr r0, =gUnknown_030012C0
	ldr r0, [r0]
	cmp r1, r0
	bcc _081D1322
_081D133A:
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D12D8

	thumb_func_start sub_81D1350
sub_81D1350: @ 81D1350
	push {lr}
	sub sp, 0x8
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81D1350

	thumb_func_start sub_81D1370
sub_81D1370: @ 81D1370
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r6, r1, 0
	movs r1, 0x9
	bl __umodsi3
	adds r5, r0, 0
	lsls r5, 1
	adds r5, 0xB
	adds r0, r4, 0
	movs r1, 0x9
	bl __udivsi3
	adds r4, r0, 0
	lsls r4, 1
	adds r4, 0x4
	add r0, sp, 0x8
	adds r1, r6, 0
	bl sub_81D13BC
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	add r1, sp, 0x8
	adds r2, r5, 0
	adds r3, r4, 0
	bl CopyToBgTilemapBufferRect
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1370

	thumb_func_start sub_81D13BC
sub_81D13BC: @ 81D13BC
	push {r4,r5,lr}
	ldr r2, =gUnknown_08624BF8
	lsls r1, 2
	adds r1, r2
	ldrh r3, [r1, 0x2]
	adds r3, 0x2
	lsls r3, 16
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	lsrs r3, 4
	adds r2, r1, 0
	orrs r2, r3
	strh r2, [r0]
	movs r5, 0x80
	lsls r5, 3
	adds r4, r5, 0
	orrs r2, r4
	strh r2, [r0, 0x2]
	adds r1, 0x1
	orrs r1, r3
	strh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D13BC

	thumb_func_start sub_81D13FC
sub_81D13FC: @ 81D13FC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624C78
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08624C80
	bl sub_81C795C
	ldr r0, =gUnknown_08624D04
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x14]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D13FC

	thumb_func_start sub_81D1448
sub_81D1448: @ 81D1448
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	bl sub_81D0944
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0x9
	bl __modsi3
	adds r5, r0, 0
	lsls r5, 4
	adds r5, 0x60
	adds r0, r4, 0
	movs r1, 0x9
	bl __divsi3
	lsls r0, 4
	adds r0, 0x28
	ldr r1, [r6, 0x14]
	movs r2, 0
	mov r8, r2
	strh r5, [r1, 0x20]
	ldr r1, [r6, 0x14]
	strh r0, [r1, 0x22]
	bl sub_81D0954
	adds r4, r0, 0
	movs r0, 0x9
	bl GetSpriteTileStartByTag
	ldr r3, [r6, 0x14]
	ldr r1, =gUnknown_08624BF8
	lsls r4, 2
	adds r4, r1
	ldrh r1, [r4]
	lsls r1, 4
	adds r0, r1
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r2, [r3, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
	ldrh r0, [r4, 0x2]
	adds r0, 0xF
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfSpritePaletteTag
	ldr r3, [r6, 0x14]
	lsls r0, 4
	ldrb r2, [r3, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x5]
	ldr r0, [r6, 0x14]
	movs r1, 0x1
	bl StartObjectRotScalAnim
	ldr r1, [r6, 0x14]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r6, 0x14]
	mov r1, r8
	strh r1, [r0, 0x2E]
	ldr r1, [r6, 0x14]
	ldr r0, =sub_81D1538
	str r0, [r1, 0x1C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1448

	thumb_func_start sub_81D1500
sub_81D1500: @ 81D1500
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4, 0x14]
	movs r0, 0x1
	strh r0, [r1, 0x2E]
	ldr r0, [r4, 0x14]
	movs r1, 0x2
	bl StartObjectRotScalAnim
	ldr r1, [r4, 0x14]
	ldr r0, =sub_81D1538
	str r0, [r1, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1500

	thumb_func_start sub_81D1524
sub_81D1524: @ 81D1524
	ldr r0, [r0, 0x14]
	ldr r1, [r0, 0x1C]
	ldr r0, =SpriteCallbackDummy
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81D1524

	thumb_func_start sub_81D1538
sub_81D1538: @ 81D1538
	push {lr}
	adds r3, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081D156A
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	movs r0, 0x1
	ldrh r1, [r3, 0x2E]
	ands r1, r0
	lsls r1, 2
	mov r0, r12
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
_081D156A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1538

	thumb_func_start sub_81D1574
sub_81D1574: @ 81D1574
	push {lr}
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _081D15A4
	lsls r0, 2
	ldr r1, =_081D158C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D158C:
	.4byte _081D15A4
	.4byte _081D15A8
	.4byte _081D15AC
	.4byte _081D15B4
	.4byte _081D15B0
	.4byte _081D15A8
_081D15A4:
	movs r0, 0
	b _081D15B6
_081D15A8:
	movs r0, 0x1
	b _081D15B6
_081D15AC:
	movs r0, 0x2
	b _081D15B6
_081D15B0:
	movs r0, 0x3
	b _081D15B6
_081D15B4:
	movs r0, 0x4
_081D15B6:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1574

	thumb_func_start sub_81D15BC
sub_81D15BC: @ 81D15BC
	ldr r1, =gUnknown_085500A4
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D15BC

	thumb_func_start sub_81D15CC
sub_81D15CC: @ 81D15CC
	push {lr}
	adds r3, r0, 0
	movs r1, 0
	ldr r2, =gUnknown_085500A4
_081D15D4:
	ldrh r0, [r2]
	cmp r0, r3
	bne _081D15E4
	adds r0, r1, 0
	b _081D15F0
	.pool
_081D15E4:
	adds r2, 0x10
	adds r1, 0x1
	cmp r1, 0x4D
	ble _081D15D4
	movs r0, 0x1
	negs r0, r0
_081D15F0:
	pop {r1}
	bx r1
	thumb_func_end sub_81D15CC

	thumb_func_start sub_81D15F4
sub_81D15F4: @ 81D15F4
	push {r4,lr}
	cmp r0, 0x14
	bhi _081D1620
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_086252FC
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	b _081D1622
	.pool
_081D1620:
	movs r0, 0
_081D1622:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D15F4

	thumb_func_start sub_81D1628
sub_81D1628: @ 81D1628
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D1644
	adds r0, r1, 0
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	b _081D1646
	.pool
_081D1644:
	movs r0, 0x1
_081D1646:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1628

	thumb_func_start sub_81D164C
sub_81D164C: @ 81D164C
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D1668
	adds r0, r1, 0
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	b _081D166A
	.pool
_081D1668:
	movs r0, 0x1
_081D166A:
	pop {r1}
	bx r1
	thumb_func_end sub_81D164C

	thumb_func_start sub_81D1670
sub_81D1670: @ 81D1670
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D168C
	adds r0, r1, 0
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	b _081D168E
	.pool
_081D168C:
	movs r0, 0x1
_081D168E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1670

	thumb_func_start sub_81D1694
sub_81D1694: @ 81D1694
	push {lr}
	adds r2, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r0, [r2, 0x1]
	ldrb r1, [r1, 0x8]
	cmp r0, r1
	beq _081D16AC
	movs r0, 0
	b _081D16C6
	.pool
_081D16AC:
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D16C4
	adds r0, r1, 0
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	b _081D16C6
	.pool
_081D16C4:
	movs r0, 0x1
_081D16C6:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1694

	thumb_func_start sub_81D16CC
sub_81D16CC: @ 81D16CC
	push {lr}
	ldrh r0, [r0, 0x2]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81D16CC

	thumb_func_start sub_81D16DC
sub_81D16DC: @ 81D16DC
	push {r4,lr}
	cmp r0, 0x14
	bhi _081D170C
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_08625310
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	lsrs r0, 24
	b _081D170E
	.pool
_081D170C:
	movs r0, 0
_081D170E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D16DC

	thumb_func_start sub_81D1714
sub_81D1714: @ 81D1714
	ldrb r0, [r0, 0x1]
	bx lr
	thumb_func_end sub_81D1714

	thumb_func_start sub_81D1718
sub_81D1718: @ 81D1718
	ldrb r0, [r0, 0x1]
	bx lr
	thumb_func_end sub_81D1718

	thumb_func_start sub_81D171C
sub_81D171C: @ 81D171C
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r6, 0
	ldr r7, =0x0000ffff
	b _081D172E
	.pool
_081D172C:
	adds r6, 0x1
_081D172E:
	ldr r0, [r5, 0x10]
	lsls r4, r6, 2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r7
	beq _081D1744
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _081D172C
_081D1744:
	ldr r0, [r5, 0x10]
	adds r0, r4, r0
	ldrb r0, [r0, 0x2]
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D171C

	thumb_func_start sub_81D1750
sub_81D1750: @ 81D1750
	movs r0, 0xD5
	bx lr
	thumb_func_end sub_81D1750

	thumb_func_start sub_81D1754
sub_81D1754: @ 81D1754
	movs r0, 0xD5
	bx lr
	thumb_func_end sub_81D1754

	thumb_func_start sub_81D1758
sub_81D1758: @ 81D1758
	push {r4,lr}
	cmp r0, 0x14
	bhi _081D1784
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_08625324
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	b _081D1786
	.pool
_081D1784:
	movs r0, 0
_081D1786:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D1758

	thumb_func_start sub_81D178C
sub_81D178C: @ 81D178C
	movs r0, 0
	bx lr
	thumb_func_end sub_81D178C

	thumb_func_start sub_81D1790
sub_81D1790: @ 81D1790
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x4]
	cmp r0, 0x48
	bhi _081D17B8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000009ca
	adds r0, r2
	ldrh r1, [r1, 0x4]
	adds r0, r1
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _081D17BA
	.pool
_081D17B8:
	movs r0, 0
_081D17BA:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1790

	thumb_func_start sub_81D17C0
sub_81D17C0: @ 81D17C0
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x000009ca
	adds r1, r2
	ldrh r0, [r0, 0x4]
	adds r1, r0
	ldrb r1, [r1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81D17C0

	thumb_func_start sub_81D17E0
sub_81D17E0: @ 81D17E0
	movs r0, 0
	bx lr
	thumb_func_end sub_81D17E0

	thumb_func_start sub_81D17E4
sub_81D17E4: @ 81D17E4
	movs r0, 0
	bx lr
	thumb_func_end sub_81D17E4

	thumb_func_start sub_81D17E8
sub_81D17E8: @ 81D17E8
	push {r4,r5,lr}
	adds r5, r0, 0
	cmp r5, 0x14
	bhi _081D1832
	ldr r1, =gUnknown_086252A8
	lsls r0, r5, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	adds r2, r0, 0
	ldr r1, =gUnknown_08625338
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	cmp r0, 0
	beq _081D1820
_081D1812:
	movs r0, 0x1
	b _081D1834
	.pool
_081D1820:
	movs r2, 0
	ldr r1, =gUnknown_08625388
_081D1824:
	ldrh r0, [r1]
	cmp r0, r5
	beq _081D1812
	adds r1, 0x18
	adds r2, 0x1
	cmp r2, 0x3
	bls _081D1824
_081D1832:
	movs r0, 0
_081D1834:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D17E8

	thumb_func_start sub_81D1840
sub_81D1840: @ 81D1840
	movs r0, 0
	bx lr
	thumb_func_end sub_81D1840

	thumb_func_start sub_81D1844
sub_81D1844: @ 81D1844
	movs r0, 0x1
	bx lr
	thumb_func_end sub_81D1844

	thumb_func_start sub_81D1848
sub_81D1848: @ 81D1848
	movs r0, 0x1
	bx lr
	thumb_func_end sub_81D1848

	thumb_func_start sub_81D184C
sub_81D184C: @ 81D184C
	movs r0, 0
	bx lr
	thumb_func_end sub_81D184C

	thumb_func_start sub_81D1850
sub_81D1850: @ 81D1850
	movs r0, 0
	bx lr
	thumb_func_end sub_81D1850

	thumb_func_start sub_81D1854
sub_81D1854: @ 81D1854
	push {r4,lr}
	cmp r0, 0x14
	bhi _081D1880
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_0862534C
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	b _081D1882
	.pool
_081D1880:
	movs r0, 0x4E
_081D1882:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D1854

	thumb_func_start sub_81D1888
sub_81D1888: @ 81D1888
	movs r0, 0x4E
	bx lr
	thumb_func_end sub_81D1888

	thumb_func_start sub_81D188C
sub_81D188C: @ 81D188C
	ldrh r0, [r0, 0x4]
	bx lr
	thumb_func_end sub_81D188C

	thumb_func_start sub_81D1890
sub_81D1890: @ 81D1890
	ldrh r0, [r0, 0x4]
	bx lr
	thumb_func_end sub_81D1890

	thumb_func_start sub_81D1894
sub_81D1894: @ 81D1894
	movs r0, 0x4E
	bx lr
	thumb_func_end sub_81D1894

	thumb_func_start sub_81D1898
sub_81D1898: @ 81D1898
	movs r0, 0x4E
	bx lr
	thumb_func_end sub_81D1898

	thumb_func_start sub_81D189C
sub_81D189C: @ 81D189C
	push {r4,r5,lr}
	adds r5, r1, 0
	cmp r0, 0x14
	bhi _081D18C2
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_08625360
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
_081D18C2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D189C

	thumb_func_start sub_81D18D0
sub_81D18D0: @ 81D18D0
	push {lr}
	ldr r0, [r0, 0xC]
	bl sub_81D1920
	pop {r0}
	bx r0
	thumb_func_end sub_81D18D0

	thumb_func_start sub_81D18DC
sub_81D18DC: @ 81D18DC
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldrb r0, [r3]
	cmp r0, 0x5
	beq _081D18F0
	ldr r0, [r3, 0x10]
	bl sub_81D1920
	b _081D18F8
_081D18F0:
	ldr r0, [r3, 0x10]
	ldrh r1, [r3, 0x4]
	bl sub_81D199C
_081D18F8:
	pop {r0}
	bx r0
	thumb_func_end sub_81D18DC

	thumb_func_start sub_81D18FC
sub_81D18FC: @ 81D18FC
	push {lr}
	ldr r0, [r0, 0xC]
	bl sub_81D1920
	pop {r0}
	bx r0
	thumb_func_end sub_81D18FC

	thumb_func_start sub_81D1908
sub_81D1908: @ 81D1908
	push {lr}
	ldr r0, [r0, 0xC]
	bl sub_81D1920
	pop {r0}
	bx r0
	thumb_func_end sub_81D1908

	thumb_func_start sub_81D1914
sub_81D1914: @ 81D1914
	push {lr}
	adds r0, r1, 0
	bl sub_8197080
	pop {r0}
	bx r0
	thumb_func_end sub_81D1914

	thumb_func_start sub_81D1920
sub_81D1920: @ 81D1920
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r1
	movs r5, 0
	ldr r0, [r6]
	cmp r0, 0
	beq _081D1940
	adds r1, r6, 0
_081D1936:
	adds r1, 0x8
	adds r5, 0x1
	ldr r0, [r1]
	cmp r0, 0
	bne _081D1936
_081D1940:
	cmp r5, 0
	beq _081D1946
	subs r5, 0x1
_081D1946:
	ldr r0, =0x0000ffff
	mov r8, r0
	lsls r0, r5, 3
	adds r0, 0x4
	adds r4, r0, r6
	b _081D195C
	.pool
_081D1958:
	subs r4, 0x8
	subs r5, 0x1
_081D195C:
	lsls r7, r5, 3
	cmp r5, 0
	beq _081D1974
	ldrh r0, [r4]
	cmp r0, r8
	beq _081D1958
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D1958
_081D1974:
	adds r4, r7, r6
	ldrh r1, [r4, 0x6]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D1984
	adds r0, r1, 0
	bl FlagSet
_081D1984:
	ldr r1, [r4]
	mov r0, r9
	bl StringExpandPlaceholders
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1920

	thumb_func_start sub_81D199C
sub_81D199C: @ 81D199C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r10, r2
	lsls r1, 16
	lsrs r7, r1, 16
	movs r5, 0
	ldr r0, [r6]
	cmp r0, 0
	beq _081D19E6
	ldrh r0, [r6, 0x4]
	ldr r1, =0x0000fffe
	cmp r0, r1
	beq _081D1A24
	ldr r0, =0x0000ffff
	mov r9, r0
	mov r8, r1
	adds r4, r6, 0
_081D19C6:
	ldrh r0, [r4, 0x4]
	cmp r0, r9
	beq _081D19D6
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D19E6
_081D19D6:
	adds r4, 0x8
	adds r5, 0x1
	ldr r0, [r4]
	cmp r0, 0
	beq _081D19E6
	ldrh r0, [r4, 0x4]
	cmp r0, r8
	bne _081D19C6
_081D19E6:
	lsls r0, r5, 3
	adds r0, r6
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000fffe
	cmp r1, r0
	beq _081D1A24
	cmp r5, 0
	beq _081D19F8
	subs r5, 0x1
_081D19F8:
	lsls r0, r5, 3
	adds r4, r0, r6
	ldrh r1, [r4, 0x6]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D1A0A
	adds r0, r1, 0
	bl FlagSet
_081D1A0A:
	ldr r1, [r4]
	mov r0, r10
	bl StringExpandPlaceholders
	b _081D1A5C
	.pool
_081D1A1C:
	adds r5, 0x2
	b _081D1A50
_081D1A20:
	adds r5, 0x3
	b _081D1A50
_081D1A24:
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D1A50
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D1A1C
	adds r0, r7, 0
	bl sub_80B2318
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D1A20
	adds r5, 0x1
_081D1A50:
	lsls r0, r5, 3
	adds r0, r6
	ldr r1, [r0]
	mov r0, r10
	bl StringExpandPlaceholders
_081D1A5C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D199C

	thumb_func_start sub_81D1A78
sub_81D1A78: @ 81D1A78
	push {r4-r6,lr}
	adds r5, r1, 0
	adds r6, r2, 0
	cmp r0, 0x14
	bhi _081D1AA2
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_08625374
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl _call_via_r3
_081D1AA2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1A78

	thumb_func_start sub_81D1AB0
sub_81D1AB0: @ 81D1AB0
	ldr r3, [r0, 0x4]
	str r3, [r1]
	ldr r0, [r0, 0x8]
	str r0, [r2]
	bx lr
	thumb_func_end sub_81D1AB0

	thumb_func_start sub_81D1ABC
sub_81D1ABC: @ 81D1ABC
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0
	bne _081D1AD0
	ldrh r0, [r4, 0x4]
	bl sub_81D1B0C
	b _081D1AD2
_081D1AD0:
	str r0, [r2]
_081D1AD2:
	ldr r0, [r4, 0x8]
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1ABC

	thumb_func_start sub_81D1ADC
sub_81D1ADC: @ 81D1ADC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r0, [r4, 0x4]
	bl sub_81D1B0C
	ldr r0, [r4, 0x8]
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1ADC

	thumb_func_start sub_81D1AF4
sub_81D1AF4: @ 81D1AF4
	ldr r3, [r0, 0x4]
	str r3, [r1]
	ldr r0, [r0, 0x8]
	str r0, [r2]
	bx lr
	thumb_func_end sub_81D1AF4

	thumb_func_start sub_81D1B00
sub_81D1B00: @ 81D1B00
	ldr r3, [r0, 0x4]
	str r3, [r1]
	ldr r0, [r0, 0x8]
	str r0, [r2]
	bx lr
	thumb_func_end sub_81D1B00

	thumb_func_start sub_81D1B0C
sub_81D1B0C: @ 81D1B0C
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_81D15BC
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTrainers
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	muls r0, r2
	ldr r2, =gTrainerClassNames
	adds r0, r2
	str r0, [r4]
	adds r1, 0x4
	str r1, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1B0C

	thumb_func_start sub_81D1B40
sub_81D1B40: @ 81D1B40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	movs r5, 0
	ldr r2, =gUnknown_08625388
	movs r0, 0x8
	adds r0, r2
	mov r9, r0
_081D1B54:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D1BBC
	adds r4, r5, 0x1
	lsls r1, 2
	mov r8, r1
	cmp r4, 0x3
	bhi _081D1BA8
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D1BA8
	ldr r7, =gUnknown_08625388
_081D1B7C:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r1, r7, 0x4
	adds r0, r1
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D1BA8
	adds r5, r4, 0
	adds r4, r5, 0x1
	cmp r4, 0x3
	bhi _081D1BA8
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, r6
	beq _081D1B7C
_081D1BA8:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	add r0, r8
	add r0, r9
	ldr r0, [r0]
	b _081D1BC4
	.pool
_081D1BBC:
	adds r5, 0x1
	cmp r5, 0x3
	bls _081D1B54
	movs r0, 0
_081D1BC4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D1B40

	thumb_func_start sub_81D1BD0
sub_81D1BD0: @ 81D1BD0
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =gUnknown_08625388
_081D1BD8:
	ldrh r0, [r1]
	cmp r0, r3
	bne _081D1BE8
	ldrh r0, [r1, 0x2]
	b _081D1BF4
	.pool
_081D1BE8:
	adds r1, 0x18
	adds r2, 0x1
	cmp r2, 0x3
	bls _081D1BD8
	movs r0, 0x1
	negs r0, r0
_081D1BF4:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1BD0

	thumb_func_start sub_81D1BF8
sub_81D1BF8: @ 81D1BF8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
_081D1BFE:
	adds r0, r4, 0
	bl sub_81D1854
	cmp r0, 0x4E
	beq _081D1C10
	cmp r0, r5
	bne _081D1C10
	movs r0, 0x1
	b _081D1C18
_081D1C10:
	adds r4, 0x1
	cmp r4, 0x14
	ble _081D1BFE
	movs r0, 0
_081D1C18:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D1BF8

	thumb_func_start sub_81D1C20
sub_81D1C20: @ 81D1C20
	push {lr}
	ldr r0, =gUnknown_020375E0
	ldrh r0, [r0]
	bl sub_81D15CC
	cmp r0, 0
	blt _081D1C3C
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
_081D1C3C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1C20

	thumb_func_start sub_81D1C44
sub_81D1C44: @ 81D1C44
	push {r4,lr}
	lsls r0, 24
	ldr r4, =gUnknown_0203CF4C
	lsrs r0, 21
	adds r0, 0x8
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081D1C60
	movs r0, 0
	b _081D1C7A
	.pool
_081D1C60:
	movs r2, 0
	ldr r4, =gUnknown_0203CF48
	movs r3, 0xFF
_081D1C66:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _081D1C66
	movs r0, 0x1
_081D1C7A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1C44

	thumb_func_start sub_81D1C84
sub_81D1C84: @ 81D1C84
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_0203CF48
	adds r5, r4, r6
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _081D1CEC
	cmp r4, 0x2
	bne _081D1CD4
	ldr r0, =gUnknown_086253E8
	ldr r1, [r0, 0x14]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_085DFF04
	movs r1, 0x4
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strb r0, [r6, 0x2]
	b _081D1CE0
	.pool
_081D1CD4:
	lsls r0, r4, 3
	ldr r1, =gUnknown_086253E8
	adds r0, r1
	bl AddWindow
	strb r0, [r5]
_081D1CE0:
	ldr r0, =gUnknown_0203CF48
	adds r0, r4, r0
	ldrb r0, [r0]
	movs r1, 0
	bl SetStandardWindowBorderStyle
_081D1CEC:
	ldr r0, =gUnknown_0203CF48
	adds r0, r4, r0
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1C84

	thumb_func_start sub_81D1D04
sub_81D1D04: @ 81D1D04
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF48
	adds r4, r0
	ldrb r0, [r4]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1D04

	thumb_func_start sub_81D1D34
sub_81D1D34: @ 81D1D34
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF48
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D1D34

	thumb_func_start sub_81D1D44
sub_81D1D44: @ 81D1D44
	push {r4,r5,lr}
	sub sp, 0x34
	adds r3, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _081D1DAC
	ldr r0, =gSaveBlock1Ptr
	lsls r1, r3, 3
	adds r1, r3
	lsls r1, 2
	ldr r0, [r0]
	adds r1, r0
	ldr r0, =0x00002cca
	adds r1, r0
	add r0, sp, 0x14
	bl StringCopy
	add r0, sp, 0x14
	bl sub_81DB52C
	add r0, sp, 0x14
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081D1D8C
	add r0, sp, 0x14
	movs r1, 0x1
	bl ConvertInternationalString
_081D1D8C:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_08625400
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	add r0, sp, 0x14
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x8
	adds r3, r5, 0
	bl AddTextPrinterParametrized2
_081D1DAC:
	add sp, 0x34
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1D44

	thumb_func_start sub_81D1DC0
sub_81D1DC0: @ 81D1DC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	movs r3, 0
	ldr r7, =gUnknown_0203CF4C
	ldr r0, =gUnknown_085E8CF7
	mov r12, r0
	ldr r4, =gUnknown_03006310
	ldr r1, =gUnknown_0203CF48
	mov r8, r1
	ldr r2, =sub_81D1E7C
	mov r9, r2
	ldr r0, =sub_81D1D44
	mov r10, r0
	ldrb r1, [r5, 0x5]
	cmp r3, r1
	bcs _081D1E02
	adds r6, r7, 0
	ldr r2, =gUnknown_08625403
_081D1DEC:
	ldr r1, [r6]
	lsls r0, r3, 3
	adds r0, r1
	str r2, [r0]
	str r3, [r0, 0x4]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrb r0, [r5, 0x5]
	cmp r3, r0
	bcc _081D1DEC
_081D1E02:
	ldr r2, [r7]
	lsls r0, r3, 3
	adds r0, r2
	mov r1, r12
	str r1, [r0]
	movs r1, 0x2
	negs r1, r1
	str r1, [r0, 0x4]
	str r2, [r4]
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0xC]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	strb r0, [r4, 0x10]
	strb r1, [r4, 0x11]
	movs r0, 0x8
	strb r0, [r4, 0x12]
	strb r1, [r4, 0x13]
	strh r0, [r4, 0xE]
	movs r0, 0x29
	strb r0, [r4, 0x14]
	movs r0, 0x31
	strb r0, [r4, 0x15]
	mov r0, r9
	str r0, [r4, 0x4]
	mov r1, r10
	str r1, [r4, 0x8]
	movs r0, 0x1
	strb r0, [r4, 0x17]
	movs r0, 0
	strb r0, [r4, 0x16]
	ldrh r1, [r5, 0x2]
	ldrh r2, [r5]
	adds r0, r4, 0
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1DC0

	thumb_func_start sub_81D1E7C
sub_81D1E7C: @ 81D1E7C
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D1E8C
	movs r0, 0x5
	bl audio_play
_081D1E8C:
	pop {r0}
	bx r0
	thumb_func_end sub_81D1E7C

	thumb_func_start sub_81D1E90
sub_81D1E90: @ 81D1E90
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldrb r0, [r4, 0x5]
	ldrb r1, [r4, 0x4]
	subs r0, r1
	adds r0, 0x1
	str r0, [sp]
	movs r0, 0x6E
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xC8
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	strb r0, [r4, 0x9]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1E90

	thumb_func_start sub_81D1EC0
sub_81D1EC0: @ 81D1EC0
	push {lr}
	ldr r0, =gUnknown_0203CF4C
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1EC0

	thumb_func_start sub_81D1ED4
sub_81D1ED4: @ 81D1ED4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r3, r0, 0
	movs r6, 0
	movs r7, 0
_081D1EE6:
	movs r2, 0
	lsls r5, r6, 2
	adds r0, r6, 0x1
	mov r10, r0
	adds r4, r5, 0
_081D1EF0:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r3, r0
	adds r1, r0, 0
	adds r1, 0x64
	strh r7, [r1]
	adds r0, 0x66
	strh r7, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9
	bls _081D1EF0
	movs r2, 0
	mov r9, r2
	str r5, [sp]
	movs r1, 0x9B
	mov r8, r1
	movs r4, 0x5B
	mov r12, r4
_081D1F1C:
	lsls r0, r2, 2
	adds r0, r2
	adds r1, r6, r0
	adds r1, r3, r1
	mov r4, r9
	strb r4, [r1]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1, r0
	adds r0, r3, r0
	mov r4, r8
	strh r4, [r0, 0x14]
	mov r1, r12
	strh r1, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _081D1F1C
	adds r1, r3, r5
	movs r2, 0x96
	lsls r2, 1
	adds r0, r1, r2
	strh r7, [r0]
	movs r4, 0x97
	lsls r4, 1
	adds r0, r1, r4
	strh r7, [r0]
	mov r1, r10
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x4
	bls _081D1EE6
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r3, r2
	movs r1, 0
	strb r1, [r0]
	ldr r4, =0x00000352
	adds r0, r3, r4
	strh r1, [r0]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1ED4

	thumb_func_start sub_81D1F84
sub_81D1F84: @ 81D1F84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	str r1, [sp]
	mov r9, r2
	movs r7, 0
_081D1F98:
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r4, r1
	ldrh r1, [r0]
	lsls r5, r1, 8
	mov r2, r9
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	adds r7, 0x1
	mov r10, r7
	mov r12, r4
_081D1FBC:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	add r0, r12
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	movs r7, 0x1
	ands r1, r7
	adds r2, r1
	adds r0, 0x64
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D1FBC
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r1, r9
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r0, 0x64
	strh r1, [r0]
	ldr r7, [sp]
	adds r0, r4, r7
	ldrh r1, [r0, 0x2]
	lsls r5, r1, 8
	ldrh r0, [r2, 0x2]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	str r4, [sp, 0x4]
	movs r0, 0x1
	mov r12, r0
_081D2012:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	ldr r1, [sp, 0x4]
	adds r0, r1, r0
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	mov r7, r12
	ands r1, r7
	adds r2, r1
	adds r0, 0x66
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D2012
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r2, r9
	adds r1, r4, r2
	ldrh r1, [r1, 0x2]
	adds r0, 0x66
	strh r1, [r0]
	mov r7, r10
	lsls r0, r7, 16
	lsrs r7, r0, 16
	cmp r7, 0x4
	bls _081D1F98
	ldr r1, =0x00000352
	add r1, r8
	movs r0, 0
	strh r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1F84

	thumb_func_start sub_81D2074
sub_81D2074: @ 81D2074
	push {r4,lr}
	adds r1, r0, 0
	ldr r0, =0x00000352
	adds r4, r1, r0
	ldrh r0, [r4]
	cmp r0, 0x9
	bls _081D208C
	movs r0, 0
	b _081D20A6
	.pool
_081D208C:
	adds r0, r1, 0
	bl sub_81D2230
	ldrh r1, [r4]
	adds r1, 0x1
	strh r1, [r4]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0xA
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_081D20A6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2074

	thumb_func_start sub_81D20AC
sub_81D20AC: @ 81D20AC
	ldr r1, =0x00000355
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D20AC

	thumb_func_start sub_81D20BC
sub_81D20BC: @ 81D20BC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =0x00000355
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D20D4
	cmp r0, 0x1
	beq _081D20E2
	b _081D20FA
	.pool
_081D20D4:
	bl dp12_8087EA4
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	b _081D20FC
_081D20E2:
	mov r0, sp
	ldr r1, =gUnknown_08625404
	ldm r1!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_081D20FA:
	movs r0, 0
_081D20FC:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D20BC

	thumb_func_start sub_81D2108
sub_81D2108: @ 81D2108
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	movs r1, 0xD5
	lsls r1, 2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D21BE
	adds r0, r6, 0
	bl sub_81D24A4
	adds r0, r6, 0
	bl sub_81D2634
	movs r7, 0
	ldr r5, =gUnknown_02038C28
	mov r12, r5
	movs r0, 0xF0
	lsls r0, 3
	add r0, r12
	mov r9, r0
	movs r1, 0xA0
	lsls r1, 1
	adds r1, r6, r1
	str r1, [sp]
	ldr r5, =0x0000ffff
	mov r8, r5
	movs r0, 0xA1
	lsls r0, 1
	adds r0, r6, r0
	str r0, [sp, 0x4]
	movs r1, 0x92
	lsls r1, 2
	adds r1, r6, r1
	str r1, [sp, 0x8]
	ldr r5, =0x0000024a
	adds r5, r6
	mov r10, r5
_081D215E:
	adds r2, r7, 0
	adds r2, 0x37
	lsls r3, r2, 2
	mov r0, r9
	adds r0, r3, r0
	str r0, [sp, 0xC]
	add r3, r12
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	ldr r5, [sp, 0x4]
	adds r1, r5, r4
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r3]
	mov r1, r8
	ands r0, r1
	ldr r5, [sp, 0xC]
	strh r0, [r5]
	lsls r2, 1
	adds r2, 0x1
	lsls r2, 1
	mov r0, r9
	adds r3, r2, r0
	add r2, r12
	ldr r1, [sp, 0x8]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	add r4, r10
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r2]
	mov r5, r8
	ands r0, r5
	strh r0, [r3]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x41
	bls _081D215E
	movs r0, 0xD5
	lsls r0, 2
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_081D21BE:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2108

	thumb_func_start sub_81D21DC
sub_81D21DC: @ 81D21DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D21E8
	movs r1, 0
_081D21E8:
	movs r0, 0x1
	lsls r0, r1
	movs r5, 0x1F
	bics r5, r0
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0x9B
	bl SetGpuReg
	ldr r4, =0x00003879
	movs r0, 0x44
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x46
	adds r1, r4, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D21DC

	thumb_func_start sub_81D2230
sub_81D2230: @ 81D2230
	push {r4-r7,lr}
	mov r12, r0
	movs r4, 0
	movs r7, 0x96
	lsls r7, 1
	add r7, r12
	ldr r6, =0x00000352
	add r6, r12
	mov r5, r12
	adds r5, 0x64
_081D2244:
	lsls r2, r4, 2
	adds r3, r7, r2
	ldrh r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, r5, r2
	ldr r0, [r2]
	str r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _081D2244
	movs r1, 0xD5
	lsls r1, 2
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2230

	thumb_func_start sub_81D2278
sub_81D2278: @ 81D2278
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	adds r6, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x38]
	ldr r7, [sp, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	str r0, [sp, 0xC]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r3, 0x2]
	cmp r0, r1
	bcs _081D22B2
	adds r2, r0, 0
	mov r10, r2
	ldrh r0, [r3, 0x2]
	ldrh r1, [r5]
	lsls r4, r1, 10
	ldrh r3, [r3]
	str r3, [sp, 0x8]
	b _081D22C6
_081D22B2:
	ldrh r0, [r5, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r1, [r1, 0x2]
	mov r10, r1
	ldr r2, [sp, 0x4]
	ldrh r1, [r2]
	lsls r4, r1, 10
	ldrh r3, [r5]
	str r3, [sp, 0x8]
	mov r2, r10
_081D22C6:
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	beq _081D22DE
	subs r0, r3, r1
	lsls r0, 10
	mov r1, r8
	bl __divsi3
	str r0, [sp, 0xC]
_081D22DE:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r7, 0
	bne _081D2328
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r7, r8
	bcs _081D23B6
	movs r7, 0x1
_081D2308:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r1, [sp, 0xC]
	adds r4, r1
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2308
	b _081D23B6
_081D2328:
	ldr r2, [sp, 0xC]
	cmp r2, 0
	ble _081D23C0
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r5, r8
	bcs _081D237A
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D237A
	mov r1, r12
	str r1, [sp, 0x14]
_081D2352:
	ldr r3, [sp, 0x14]
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r3, 0x1
	ands r0, r3
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D237A
	ldr r1, =0x00026bff
	cmp r4, r1
	ble _081D2352
_081D237A:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	cmp r5, r8
	bcs _081D23B6
	mov r3, r12
	movs r7, 0x1
_081D2398:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2398
_081D23B6:
	subs r0, r6, 0x4
	b _081D248C
	.pool
_081D23C0:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	bge _081D2464
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r2, r9
	lsls r2, 1
	mov r12, r2
	ldr r3, [sp, 0x8]
	add r3, r9
	str r3, [sp, 0x10]
	cmp r5, r8
	bcs _081D241E
	adds r3, r2, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r2, 0x1
	ands r0, r2
	adds r1, r0
	add r1, r9
	strh r1, [r3]
	b _081D2414
_081D23F2:
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D241E
	mov r1, r12
	adds r3, r1, r6
	asrs r2, r4, 10
	asrs r0, r4, 9
	movs r1, 0x1
	ands r0, r1
	adds r2, r0
	add r2, r9
	strh r2, [r3]
_081D2414:
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D23F2
	movs r0, 0x9B
	strh r0, [r3]
_081D241E:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	cmp r5, r8
	bcs _081D245A
	mov r3, r12
	movs r6, 0x1
_081D243C:
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r6
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D243C
_081D245A:
	subs r0, r7, 0x4
	b _081D248C
	.pool
_081D2464:
	ldr r1, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r1, r2
	mov r3, r10
	strh r3, [r0]
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	adds r7, r0
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1]
	strh r0, [r7]
	movs r0, 0x9B
	strh r0, [r7, 0x2]
	b _081D2494
_081D248C:
	add r0, r12
	mov r2, sp
	ldrh r2, [r2, 0x10]
	strh r2, [r0]
_081D2494:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2278

	thumb_func_start sub_81D24A4
sub_81D24A4: @ 81D24A4
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x99
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcs _081D24E0
	adds r7, r0, 0
	movs r0, 0xA0
	lsls r0, 1
	adds r1, r4, r0
	movs r3, 0x96
	lsls r3, 1
	adds r2, r4, r3
	subs r0, 0x10
	adds r3, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2500
_081D24E0:
	ldrh r7, [r1]
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x96
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2500:
	movs r1, 0xA0
	lsls r1, 1
	adds r5, r4, r1
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x9A
	lsls r0, 1
	adds r6, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_81D2278
	movs r2, 0
	movs r1, 0x9B
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0x9D
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D253C
	movs r2, 0x1
_081D253C:
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	str r2, [sp]
	movs r1, 0x92
	lsls r1, 2
	adds r0, r4, r1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D2278
	movs r2, 0x38
	cmp r2, r7
	bcs _081D257E
	adds r6, r5, 0
	movs r3, 0
	movs r0, 0xA1
	lsls r0, 1
	adds r5, r4, r0
_081D2566:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r7
	bcc _081D2566
_081D257E:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r1, [r0]
	cmp r2, r1
	bhi _081D25B2
	movs r1, 0xA0
	lsls r1, 1
	adds r3, r4, r1
	movs r5, 0x9B
	adds r1, r0, 0
_081D259C:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r0, r3, r0
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r1]
	cmp r2, r0
	bls _081D259C
_081D25B2:
	movs r2, 0x9B
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _081D25C8
	adds r0, r1, 0
_081D25C8:
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bhi _081D25F8
	movs r0, 0xA0
	lsls r0, 1
	adds r6, r4, r0
	movs r3, 0
	movs r1, 0xA1
	lsls r1, 1
	adds r5, r4, r1
_081D25E0:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D25E0
_081D25F8:
	movs r2, 0x38
	movs r3, 0xA0
	lsls r3, 1
	adds r5, r4, r3
	movs r0, 0xA1
	lsls r0, 1
	adds r4, r0
	movs r6, 0x9B
_081D2608:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r1, r0, 2
	adds r3, r5, r1
	ldrh r0, [r3]
	cmp r0, 0
	bne _081D2620
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081D2620
	strh r6, [r3]
_081D2620:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D2608
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D24A4

	thumb_func_start sub_81D2634
sub_81D2634: @ 81D2634
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x9F
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r5, [r1]
	cmp r0, r5
	bcs _081D266E
	adds r6, r0, 0
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	subs r3, 0x12
	adds r2, r4, r3
	movs r5, 0x9E
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2690
_081D266E:
	ldrh r6, [r1]
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	movs r3, 0x9E
	lsls r3, 1
	adds r2, r4, r3
	movs r5, 0x96
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2690:
	movs r0, 0x92
	lsls r0, 2
	adds r5, r4, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r2, r4, r1
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D2278
	cmp r6, 0x38
	ble _081D26C8
	movs r0, 0
	adds r1, r5, 0
	adds r2, r6, 0
	subs r2, 0x38
_081D26BC:
	strh r0, [r1]
	strh r0, [r1, 0x2]
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _081D26BC
_081D26C8:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r5, [r0]
	cmp r2, r5
	bgt _081D26F6
	movs r3, 0x9B
	adds r1, r0, 0
	lsls r0, r2, 2
	movs r5, 0xB5
	lsls r5, 1
	adds r0, r5
	adds r0, r4
_081D26EA:
	strh r3, [r0]
	adds r0, 0x4
	adds r2, 0x1
	ldrh r5, [r1]
	cmp r2, r5
	ble _081D26EA
_081D26F6:
	movs r1, 0x9D
	lsls r1, 1
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r0, 0x1
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _081D270E
	adds r0, r1, 0
_081D270E:
	adds r2, r0, 0
	cmp r2, 0x79
	bgt _081D272C
	movs r1, 0
	lsls r0, r2, 2
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3
	adds r0, r4
_081D2720:
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	adds r2, 0x1
	cmp r2, 0x79
	ble _081D2720
_081D272C:
	movs r3, 0
	movs r5, 0x92
	lsls r5, 2
	adds r1, r4, r5
	movs r2, 0x41
_081D2736:
	ldrh r0, [r1]
	ldrh r4, [r1, 0x2]
	cmp r0, r4
	bcc _081D2742
	strh r3, [r1, 0x2]
	strh r3, [r1]
_081D2742:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _081D2736
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2634

	thumb_func_start sub_81D2754
sub_81D2754: @ 81D2754
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r1, =gUnknown_08625410
	ldrb r0, [r6]
	adds r0, r1
	ldrb r2, [r0]
	adds r6, 0x1
	movs r0, 0x9B
	mov r3, r8
	strh r0, [r3]
	movs r0, 0x5B
	subs r0, r2
	strh r0, [r3, 0x2]
	movs r7, 0x40
	movs r0, 0
	mov r12, r0
	movs r2, 0x1
	mov r9, r2
	ldr r3, =gSineTable
	mov r10, r3
_081D2786:
	adds r0, r7, 0
	adds r0, 0x33
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, r12
	lsls r0, r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r3, r0, 24
	mov r12, r3
	cmp r0, 0
	bge _081D27A4
	movs r0, 0x4
	mov r12, r0
_081D27A4:
	mov r1, r12
	lsls r0, r1, 24
	asrs r4, r0, 24
	cmp r4, 0x2
	bne _081D27B4
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_081D27B4:
	ldrb r0, [r6]
	ldr r2, =gUnknown_08625410
	adds r0, r2
	ldrb r2, [r0]
	adds r6, 0x1
	lsls r0, r4, 2
	mov r1, r8
	adds r3, r0, r1
	adds r0, r7, 0
	adds r0, 0x40
	lsls r0, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r2
	asrs r5, r0, 8
	adds r0, r5, 0
	adds r0, 0x9B
	strh r0, [r3]
	lsls r0, r7, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r1, r2, 0
	muls r1, r0
	asrs r1, 8
	movs r0, 0x5B
	subs r0, r1
	strh r0, [r3, 0x2]
	cmp r4, 0x2
	bgt _081D2800
	cmp r2, 0x20
	bne _081D27FA
	cmp r4, 0x2
	beq _081D2800
_081D27FA:
	adds r0, r5, 0
	adds r0, 0x9C
	strh r0, [r3]
_081D2800:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0x4
	bls _081D2786
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2754

	thumb_func_start sub_81D2824
sub_81D2824: @ 81D2824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_08625510
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_809882C
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081D284A:
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081D284A
	cmp r5, 0
	bne _081D287C
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	b _081D288E
	.pool
_081D287C:
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
_081D288E:
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x3
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	bl nullsub_79
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2824

	thumb_func_start nullsub_79
nullsub_79: @ 81D28C4
	bx lr
	thumb_func_end nullsub_79

	thumb_func_start sub_81D28C8
sub_81D28C8: @ 81D28C8
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gUnknown_03006310
	adds r2, r3, 0
	ldr r1, =gUnknown_08625548
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	strh r4, [r3, 0xC]
	str r0, [r3]
	cmp r4, 0x5
	bhi _081D28F0
	strh r4, [r3, 0xE]
	b _081D28F4
	.pool
_081D28F0:
	movs r0, 0x6
	strh r0, [r3, 0xE]
_081D28F4:
	ldrb r0, [r3, 0xE]
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D28C8

	thumb_func_start sub_81D28FC
sub_81D28FC: @ 81D28FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_085EFA31
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	mov r8, r0
	str r0, [sp, 0x4]
	movs r7, 0
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	ldr r5, =gUnknown_085EFA52
	movs r1, 0x29
	mov r10, r1
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl Print
	ldr r5, =gUnknown_085EFA56
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r1, 0x19
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	ldr r5, =gUnknown_085EFA5D
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	movs r0, 0x2
	negs r0, r0
	cmp r9, r0
	bne _081D29C4
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2AB6
	.pool
_081D29C4:
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 2
	ldr r1, =gBattleMoves
	adds r6, r0, r1
	ldrb r1, [r6, 0x2]
	lsls r0, r1, 3
	subs r0, r1
	ldr r1, =gTypeNames
	adds r5, r0, r1
	movs r0, 0x19
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl Print
	ldr r1, =gUnknown_085EFA52
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0x4
	ldrb r1, [r6, 0x4]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	lsls r3, r4, 24
	lsrs r3, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl Print
	ldrb r0, [r6, 0x1]
	cmp r0, 0x1
	bhi _081D2A3C
	ldr r5, =gUnknown_085E8D45
	b _081D2A4A
	.pool
_081D2A3C:
	ldrb r1, [r6, 0x1]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A4A:
	movs r0, 0x19
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl Print
	ldrb r0, [r6, 0x3]
	cmp r0, 0
	bne _081D2A70
	ldr r5, =gUnknown_085E8D45
	b _081D2A7E
	.pool
_081D2A70:
	ldrb r1, [r6, 0x3]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A7E:
	movs r0, 0x29
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl Print
	ldr r1, =gMoveDescriptionPointers
	mov r0, r9
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl Print
_081D2AB6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D28FC

	thumb_func_start sub_81D2ACC
sub_81D2ACC: @ 81D2ACC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_816137C
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_085EFA3E
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r7, 0xFF
	str r7, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	ldr r5, =gUnknown_085EFA67
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x19
	mov r8, r0
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	ldr r5, =gUnknown_085EFA6E
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x29
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081D2B6C
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2BB8
	.pool
_081D2B6C:
	lsls r4, 3
	ldr r0, =gContestMoves
	adds r4, r0
	ldr r1, =gContestMoveTypeTextPointers
	ldrb r0, [r4, 0x1]
	lsls r0, 29
	lsrs r0, 27
	adds r0, r1
	ldr r5, [r0]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl Print
	ldr r1, =gContestEffectDescriptionPointers
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl Print
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_081D2BB8:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2ACC

	thumb_func_start sub_81D2BD0
sub_81D2BD0: @ 81D2BD0
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D2BE2
	movs r0, 0x5
	bl audio_play
_081D2BE2:
	adds r0, r4, 0
	bl sub_81D28FC
	adds r0, r4, 0
	bl sub_81D2ACC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2BD0

	thumb_func_start sub_81D2BF4
sub_81D2BF4: @ 81D2BF4
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	bl sav2_get_text_speed
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParametrized
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2BF4

	thumb_func_start sub_81D2C3C
sub_81D2C3C: @ 81D2C3C
	push {lr}
	bl RunTextPrinters
	movs r0, 0x3
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C3C

	thumb_func_start sub_81D2C50
sub_81D2C50: @ 81D2C50
	push {lr}
	ldr r0, =gUnknown_08625540
	movs r1, 0x1
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2C50

	thumb_func_start sub_81D2C68
sub_81D2C68: @ 81D2C68
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r0, 0xE
	bne _081D2CA8
	cmp r2, 0x2
	beq _081D2C7E
	cmp r2, 0x7
	bne _081D2C94
_081D2C7E:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	adds r2, r3, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2C94:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2CA8:
	cmp r2, 0x2
	beq _081D2CB0
	cmp r2, 0x7
	bne _081D2CBE
_081D2CB0:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl sub_80D1ED0
	b _081D2CCA
_081D2CBE:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl get_pokemon_data_from_any_box
_081D2CCA:
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C68

	thumb_func_start sub_81D2CD0
sub_81D2CD0: @ 81D2CD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	movs r0, 0xFC
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x4
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x8
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x9
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2D
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0
	beq _081D2D20
	ldr r1, =gUnknown_085E8264
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081D2E70
	.pool
_081D2D20:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_81D2C68
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81D2C68
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081D2D70
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	bl pokemon_get_gender
	lsls r0, 24
	lsrs r6, r0, 24
	b _081D2D92
	.pool
_081D2D70:
	lsls r0, r4, 24
	lsrs r0, 24
	lsls r1, r6, 24
	lsrs r1, 24
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	bl pokemon_roll_gender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	bl sub_80690C0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_081D2D92:
	cmp r7, 0x1D
	beq _081D2D9A
	cmp r7, 0x20
	bne _081D2DB0
_081D2D9A:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081D2DB0
	movs r6, 0xFF
_081D2DB0:
	adds r3, r5, 0
	b _081D2DBA
	.pool
_081D2DB8:
	adds r3, 0x1
_081D2DBA:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081D2DB8
	movs r1, 0xFC
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x12
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x3C
	strb r0, [r3]
	adds r3, 0x1
	cmp r6, 0
	beq _081D2DDE
	cmp r6, 0xFE
	beq _081D2E02
	movs r0, 0
	b _081D2E24
_081D2DDE:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB5
	b _081D2E24
_081D2E02:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x6
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x7
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB6
_081D2E24:
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x8
	strb r0, [r3]
	adds r3, 0x1
	movs r4, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0x9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xBA
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xF9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	adds r0, r3, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081D2E70:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2CD0

	thumb_func_start sub_81D2E7C
sub_81D2E7C: @ 81D2E7C
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081D2E94
_081D2E86:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081D2E94:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081D2E86
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081D2EC2
	movs r3, 0
_081D2EAE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081D2EAE
_081D2EC2:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D2E7C

	thumb_func_start sub_81D2ED4
sub_81D2ED4: @ 81D2ED4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D2EFC
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2EFC:
	cmp r2, r0
	beq _081D2F42
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r3, 0
	bl sub_81D2CD0
	movs r0, 0xFC
	strb r0, [r5]
	movs r0, 0x4
	strb r0, [r5, 0x1]
	movs r0, 0x8
	strb r0, [r5, 0x2]
	movs r0, 0
	strb r0, [r5, 0x3]
	movs r0, 0x9
	strb r0, [r5, 0x4]
	cmp r7, 0xE
	bne _081D2F2C
	adds r0, r5, 0x5
	ldr r1, =gUnknown_085EBFCE
	b _081D2F3A
	.pool
_081D2F2C:
	adds r4, r5, 0x5
	lsls r0, r7, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
_081D2F3A:
	movs r2, 0x8
	bl sub_81D2E7C
	b _081D2F72
_081D2F42:
	movs r1, 0
	movs r2, 0
_081D2F46:
	adds r0, r6, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081D2F46
	adds r1, r6, r1
	movs r0, 0xFF
	strb r0, [r1]
	movs r1, 0
	movs r2, 0
_081D2F5E:
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081D2F5E
	adds r1, r5, r1
	movs r0, 0xFF
	strb r0, [r1]
_081D2F72:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2ED4

	thumb_func_start sub_81D2F78
sub_81D2F78: @ 81D2F78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r0, r4, 16
	lsls r5, 24
	cmp r5, 0
	bne _081D2FB0
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2FB0:
	cmp r2, r0
	beq _081D305C
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x16
	movs r3, 0
	bl sub_81D2C68
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	mov r2, r8
	adds r1, r2, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x2F
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x21
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x2
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x18
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x3
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x17
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x4
	adds r1, r4
	strb r0, [r1]
	mov r4, r10
	add r4, r9
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _081D3044
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	movs r1, 0x1D
	bl __udivsi3
	b _081D3046
_081D3044:
	movs r0, 0x9
_081D3046:
	strb r0, [r4]
	mov r0, r9
	adds r1, r5, r0
	mov r2, r8
	adds r0, r2, r1
	lsls r1, 2
	adds r1, 0x14
	add r1, r8
	bl sub_81D2754
	b _081D3086
_081D305C:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	adds r1, r5, r0
	movs r6, 0
	lsls r3, r1, 2
	movs r5, 0x9B
	movs r4, 0x5B
_081D306C:
	adds r0, r2, r1
	add r0, r8
	strb r6, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	strh r5, [r0, 0x14]
	strh r4, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081D306C
_081D3086:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2F78

	thumb_func_start sub_81D3094
sub_81D3094: @ 81D3094
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	mov r9, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D30C4
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D30C4:
	cmp r2, r0
	beq _081D311A
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x41
	movs r3, 0
	bl sub_81D2C68
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_81D2C68
	adds r6, r0, 0
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_81D2C68
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0x1
	str r1, [sp]
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl DecompressMonPic
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl species_and_otid_get_pal
	mov r1, r9
	bl LZ77UnCompWram
_081D311A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3094

	thumb_func_start sub_81D312C
sub_81D312C: @ 81D312C
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	adds r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	ble _081D3140
	movs r0, 0
	strh r0, [r1]
_081D3140:
	movs r0, 0
	ldrsh r1, [r1, r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D312C

	thumb_func_start sub_81D3150
sub_81D3150: @ 81D3150
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	subs r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x50
	negs r2, r2
	cmp r0, r2
	bge _081D3168
	strh r2, [r1]
_081D3168:
	movs r0, 0
	ldrsh r1, [r1, r0]
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D3150

	thumb_func_start sub_81D3178
sub_81D3178: @ 81D3178
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D312C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D319A
	cmp r0, 0
	beq _081D319C
_081D319A:
	movs r1, 0x1
_081D319C:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3178

	thumb_func_start sub_81D31A4
sub_81D31A4: @ 81D31A4
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D3150
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D31C6
	cmp r0, 0
	beq _081D31C8
_081D31C6:
	movs r1, 0x1
_081D31C8:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D31A4

	thumb_func_start sub_81D31D0
sub_81D31D0: @ 81D31D0
	push {r4-r7,lr}
	sub sp, 0x20
	ldr r3, =gUnknown_08625A48
	ldr r4, [r3]
	ldr r5, [r3, 0x4]
	str r4, [sp, 0x18]
	str r5, [sp, 0x1C]
	mov r4, sp
	ldr r3, =gUnknown_08625A50
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldr r3, =gUnknown_08625A68
	ldr r4, [r3, 0x4]
	ldr r3, [r3]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	str r5, [r0]
	str r6, [r0, 0x4]
	mov r0, sp
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	str r3, [r2]
	str r4, [r2, 0x4]
	add sp, 0x20
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D31D0

	thumb_func_start sub_81D321C
sub_81D321C: @ 81D321C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r5, r0, 0
	mov r12, r1
	mov r8, r2
	mov r1, sp
	ldr r0, =gUnknown_08625A70
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	add r3, sp, 0x20
	adds r1, r3, 0
	ldr r0, =gUnknown_08625A90
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	add r2, sp, 0x38
	adds r1, r2, 0
	ldr r0, =gUnknown_08625AA8
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	movs r4, 0
_081D3258:
	lsls r0, r4, 3
	add r0, sp
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081D3258
	mov r1, r12
	adds r0, r2, 0
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	movs r4, 0
_081D327A:
	lsls r0, r4, 3
	adds r0, r3, r0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	mov r5, r8
	adds r5, 0x8
	mov r8, r5
	subs r5, 0x8
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081D327A
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D321C

	thumb_func_start sub_81D32B0
sub_81D32B0: @ 81D32B0
	push {r4,r5,lr}
	ldr r2, =gUnknown_08625AC0
	ldr r4, [r2]
	ldr r5, [r2, 0x4]
	ldr r2, =gUnknown_08625AC8
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r4, [r0]
	str r5, [r0, 0x4]
	str r2, [r1]
	str r3, [r1, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32B0

	thumb_func_start sub_81D32D4
sub_81D32D4: @ 81D32D4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081D32F0
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r0, r1, 0
	bl sub_81D3408
_081D32F0:
	pop {r0}
	bx r0
	thumb_func_end sub_81D32D4

	thumb_func_start sub_81D32F4
sub_81D32F4: @ 81D32F4
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D330C
	movs r0, 0
	strh r0, [r2, 0x30]
	ldr r0, =sub_81D32D4
	str r0, [r2, 0x1C]
_081D330C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32F4

	thumb_func_start sub_81D3314
sub_81D3314: @ 81D3314
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r3, r1, r0
	cmp r3, 0
	beq _081D3360
	ldrh r1, [r3, 0x24]
	ldrh r2, [r3, 0x20]
	adds r1, r2
	ldr r2, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r1, [r3, 0x26]
	ldrh r3, [r3, 0x22]
	adds r1, r3
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r2, 0x2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	b _081D337E
	.pool
_081D3360:
	ldr r1, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x28
	strh r0, [r4, 0x20]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r1, 0x2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x68
_081D337E:
	strh r0, [r4, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3314

	thumb_func_start sub_81D338C
sub_81D338C: @ 81D338C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	movs r5, 0
_081D339E:
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq _081D33F0
	strh r5, [r0, 0x2E]
	ldr r1, [r4]
	lsls r0, r5, 4
	adds r0, 0x1
	strh r0, [r1, 0x30]
	ldr r0, [r4]
	strh r6, [r0, 0x32]
	ldr r0, [r4]
	strh r5, [r0, 0x34]
	cmp r7, 0
	beq _081D33C4
	cmp r6, 0x9
	beq _081D33D0
_081D33C4:
	ldr r1, [r4]
	ldr r0, =sub_81D3564
	str r0, [r1, 0x1C]
	b _081D33F0
	.pool
_081D33D0:
	ldr r0, [r4]
	bl sub_81D3314
	ldr r0, [r4]
	bl sub_81D35E8
	ldr r2, [r4]
	ldr r0, =sub_81D32F4
	str r0, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r3, 0x5
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
_081D33F0:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _081D339E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D338C

	thumb_func_start sub_81D3408
sub_81D3408: @ 81D3408
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	bge _081D3454
	ldr r5, =gSprites
	movs r7, 0x1C
	adds r7, r5
	mov r12, r7
	ldr r6, =sub_81D3564
_081D3428:
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r5
	movs r7, 0x2E
	ldrsh r0, [r2, r7]
	lsls r0, 4
	adds r0, 0x1
	strh r0, [r2, 0x30]
	add r1, r12
	str r6, [r1]
	ldrh r0, [r2, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	blt _081D3428
_081D3454:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3408

	thumb_func_start sub_81D3464
sub_81D3464: @ 81D3464
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	movs r3, 0
_081D346C:
	lsls r0, r1, 2
	adds r0, r2
	str r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _081D346C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3464

	thumb_func_start sub_81D3480
sub_81D3480: @ 81D3480
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	movs r0, 0
	mov r9, r0
	lsrs r7, r2, 24
	movs r5, 0
	adds r0, r7, 0x1
	cmp r9, r0
	bge _081D34FE
_081D34A2:
	ldr r0, =gUnknown_08625B14
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	cmp r3, 0x40
	beq _081D34FE
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r4]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	mov r1, r10
	strh r1, [r0, 0x36]
	cmp r5, 0
	beq _081D34F0
	subs r0, r4, 0x4
	ldr r0, [r0]
	strh r3, [r0, 0x38]
	b _081D34F2
	.pool
_081D34F0:
	mov r9, r6
_081D34F2:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r7, 0x1
	cmp r5, r0
	blt _081D34A2
_081D34FE:
	lsls r0, r7, 2
	add r0, r8
	ldr r0, [r0]
	mov r1, r9
	strh r1, [r0, 0x38]
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r8
	bl sub_81D338C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3480

	thumb_func_start sub_81D3520
sub_81D3520: @ 81D3520
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
_081D3526:
	cmp r5, 0x9
	bhi _081D3544
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	cmp r0, 0
	beq _081D3544
	bl DestroySprite
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _081D3526
_081D3544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3520

	thumb_func_start sub_81D354C
sub_81D354C: @ 81D354C
	push {lr}
	bl sub_81D3520
	movs r0, 0x68
	bl FreeObjectTilesByTag
	movs r0, 0x68
	bl FreeObjectPaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_81D354C

	thumb_func_start sub_81D3564
sub_81D3564: @ 81D3564
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081D3592
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _081D35DC
	adds r0, r4, 0
	movs r1, 0
	bl SeekObjectImageAnim
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081D3592:
	adds r0, r4, 0
	bl sub_81D3314
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D35DC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081D35D8
	cmp r1, 0x9
	bne _081D35D0
	adds r0, r4, 0
	bl sub_81D35E8
	ldr r0, =sub_81D32F4
	b _081D35DA
	.pool
_081D35D0:
	ldr r0, =sub_81D32D4
	b _081D35DA
	.pool
_081D35D8:
	ldr r0, =SpriteCallbackDummy
_081D35DA:
	str r0, [r4, 0x1C]
_081D35DC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3564

	thumb_func_start sub_81D35E8
sub_81D35E8: @ 81D35E8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r5, 0
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	bge _081D3636
	movs r0, 0x5
	negs r0, r0
	adds r7, r0, 0
_081D3604:
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0
	bl SeekObjectImageAnim
	adds r1, r4, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	ands r0, r7
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	blt _081D3604
_081D3636:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D35E8

	thumb_func_start sub_81D3640
sub_81D3640: @ 81D3640
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	ldr r3, [sp, 0x4C]
	ldr r0, [sp, 0x50]
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r3, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r2, sp, 0xC
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r6, 0x2]
	subs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r6, 0x4]
	subs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r5, 0x8]
	ldrh r1, [r6, 0x8]
	subs r0, r1
	strh r0, [r2, 0x6]
	ldrh r0, [r5, 0xA]
	ldrh r1, [r6, 0xA]
	subs r0, r1
	strh r0, [r2, 0x8]
	ldrh r0, [r5, 0x6]
	ldrh r1, [r6, 0x6]
	subs r0, r1
	strh r0, [r2, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	ldr r3, [sp, 0x28]
	strb r3, [r0, 0x1]
	mov r1, r9
	strb r1, [r0, 0x2]
	movs r7, 0
	mov r10, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	add r6, sp, 0x18
_081D36CA:
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl box_print
	lsls r0, r7, 1
	mov r4, sp
	adds r4, r0
	adds r4, 0xC
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r1, =gUnknown_085EEA76
	cmp r0, 0
	blt _081D3704
	ldr r1, =gUnknown_085EEA73
_081D3704:
	adds r0, r6, 0
	bl StringCopy
	mov r0, r10
	str r0, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0x38
	adds r3, r5, 0
	bl box_print
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081D372C
	negs r0, r1
_081D372C:
	movs r4, 0xC
	cmp r0, 0x9
	bgt _081D3734
	movs r4, 0x12
_081D3734:
	cmp r1, 0
	bge _081D373A
	negs r1, r1
_081D373A:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r2, r4, 0
	adds r2, 0x38
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	adds r3, r5, 0
	bl box_print
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _081D36CA
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3640

	thumb_func_start sub_81D3784
sub_81D3784: @ 81D3784
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	ldr r2, [sp, 0x4C]
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r2, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r1, sp, 0xC
	ldrh r0, [r5]
	strh r0, [r1]
	ldrh r0, [r5, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r5, 0x4]
	strh r0, [r1, 0x4]
	ldrh r0, [r5, 0x8]
	strh r0, [r1, 0x6]
	ldrh r0, [r5, 0xA]
	strh r0, [r1, 0x8]
	ldrh r0, [r5, 0x6]
	strh r0, [r1, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	strb r6, [r0, 0x1]
	ldr r2, [sp, 0x28]
	strb r2, [r0, 0x2]
	movs r6, 0
	add r1, sp, 0x18
	mov r9, r1
	mov r7, r8
	mov r10, r0
	movs r2, 0x1
	negs r2, r2
	mov r8, r2
_081D37EE:
	lsls r1, r6, 1
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r4, 0x3
	cmp r0, 0x63
	bgt _081D3808
	movs r4, 0x1
	cmp r0, 0x9
	ble _081D3808
	movs r4, 0x2
_081D3808:
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r0, r9
	movs r2, 0
	adds r3, r4, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0x4
	subs r0, r4
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 17
	lsrs r4, 16
	lsls r5, r6, 4
	subs r5, r6
	lsls r5, 24
	lsrs r5, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl box_print
	adds r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	mov r2, r10
	str r2, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl box_print
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _081D37EE
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3784

	thumb_func_start sub_81D388C
sub_81D388C: @ 81D388C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	strh r0, [r5, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	strh r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	strh r0, [r5, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	strh r0, [r5, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	strh r0, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D388C

	thumb_func_start sub_81D38D4
sub_81D38D4: @ 81D38D4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6d
	adds r0, r1
	ldrb r1, [r0]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 8
	lsls r0, 8
	subs r0, r2, r0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D38D4

	thumb_func_start sub_81D38FC
sub_81D38FC: @ 81D38FC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x9C
	lsls r5, 2
	adds r1, r5, 0
	bl CalcByteArraySum
	adds r4, r5
	ldr r1, [r4]
	cmp r0, r1
	bne _081D3916
	movs r0, 0x1
	b _081D3918
_081D3916:
	movs r0, 0
_081D3918:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D38FC

	thumb_func_start sub_81D3920
sub_81D3920: @ 81D3920
	push {r4-r7,lr}
	adds r7, r0, 0
	ldrb r6, [r7]
	subs r0, r6, 0x1
	cmp r0, 0x7
	bhi _081D3964
	movs r5, 0
	cmp r5, r6
	bcs _081D394C
	adds r4, r7, 0
	adds r4, 0x8
_081D3936:
	adds r0, r4, 0
	bl sub_81D38FC
	cmp r0, 0
	beq _081D3964
	movs r0, 0x9D
	lsls r0, 2
	adds r4, r0
	adds r5, 0x1
	cmp r5, r6
	bcc _081D3936
_081D394C:
	adds r0, r7, 0
	adds r0, 0x8
	movs r1, 0x9D
	lsls r1, 2
	muls r1, r6
	bl CalcByteArraySum
	ldr r1, [r7, 0x4]
	cmp r0, r1
	bne _081D3964
	movs r0, 0x1
	b _081D3966
_081D3964:
	movs r0, 0
_081D3966:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3920

	thumb_func_start sub_81D396C
sub_81D396C: @ 81D396C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _081D398E
	adds r0, r4, 0
	adds r0, 0x8
	movs r1, 0xEE
	lsls r1, 4
	bl CalcByteArraySum
	ldr r1, [r4, 0x4]
	cmp r0, r1
	bne _081D398E
	movs r0, 0x1
	b _081D3990
_081D398E:
	movs r0, 0
_081D3990:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D396C

	thumb_func_start sub_81D3998
sub_81D3998: @ 81D3998
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	mov r8, r1
	movs r2, 0x80
	lsls r2, 5
	mov r0, r8
	movs r1, 0
	bl memset
	ldrb r0, [r7]
	mov r1, r8
	strb r0, [r1]
	bl sub_81D38D4
	mov r2, r8
	strb r0, [r2, 0x1]
	ldrb r0, [r7]
	adds r0, 0x1
	asrs r0, 1
	strb r0, [r2, 0x2]
	movs r6, 0
	b _081D3A42
_081D39C8:
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	bne _081D3A14
	lsrs r0, r6, 31
	adds r0, r6, r0
	asrs r0, 1
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 3
	subs r4, r0
	lsls r4, 3
	add r4, r8
	movs r0, 0x9D
	lsls r0, 2
	adds r5, r6, 0
	muls r5, r0
	adds r5, r7, r5
	ldrb r0, [r5, 0x8]
	strb r0, [r4, 0x8]
	movs r1, 0xA7
	lsls r1, 2
	adds r0, r4, r1
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r5, r2
	subs r2, 0x30
	bl memcpy
	adds r4, 0xC
	adds r5, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA4
	lsls r2, 1
	bl memcpy
	b _081D3A40
_081D3A14:
	lsrs r1, r6, 31
	adds r1, r6, r1
	asrs r1, 1
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	add r0, r8
	movs r1, 0x9D
	lsls r1, 2
	muls r1, r6
	adds r1, r7, r1
	ldrb r2, [r1, 0x8]
	strb r2, [r0, 0x9]
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	adds r1, 0xC
	subs r2, 0xC
	bl memcpy
_081D3A40:
	adds r6, 0x1
_081D3A42:
	ldrb r0, [r7]
	cmp r6, r0
	blt _081D39C8
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	beq _081D3A7E
	lsrs r2, r6, 31
	adds r2, r6, r2
	asrs r2, 1
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	lsls r0, 3
	add r0, r8
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	ldr r3, =gUnknown_08625B6C
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r2
	lsls r1, 3
	adds r1, r3
	movs r2, 0xA4
	lsls r2, 1
	bl memcpy
_081D3A7E:
	mov r0, r8
	adds r0, 0x8
	movs r1, 0xEE
	lsls r1, 4
	bl CalcByteArraySum
	mov r2, r8
	str r0, [r2, 0x4]
	movs r0, 0x1E
	mov r1, r8
	bl sub_8153634
	cmp r0, 0x1
	bne _081D3AA4
	movs r0, 0x1
	b _081D3AA6
	.pool
_081D3AA4:
	movs r0, 0
_081D3AA6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3998

	thumb_func_start sub_81D3AB0
sub_81D3AB0: @ 81D3AB0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3998
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3AB0

	thumb_func_start sub_81D3AD8
sub_81D3AD8: @ 81D3AD8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0x1E
	bl sub_81535DC
	cmp r0, 0x1
	bne _081D3B04
	ldr r2, =0x00000ee8
	adds r0, r5, 0
	adds r1, r4, 0
	bl memcpy
	adds r0, r5, 0
	bl sub_81D396C
	cmp r0, 0
	beq _081D3B04
	movs r0, 0x1
	b _081D3B06
	.pool
_081D3B04:
	movs r0, 0
_081D3B06:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3AD8

	thumb_func_start sub_81D3B0C
sub_81D3B0C: @ 81D3B0C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3AD8
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3B0C

	thumb_func_start sub_81D3B34
sub_81D3B34: @ 81D3B34
	push {r4,r5,lr}
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r4, r0, 0
	bl sub_81D3B0C
	adds r5, r0, 0
	adds r0, r4, 0
	bl Free
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3B34

	thumb_func_start sub_81D3B54
sub_81D3B54: @ 81D3B54
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_81D41A0
	movs r7, 0x2
	ldr r4, =gUnknown_03003144
_081D3B64:
	bl sub_81D4170
	ldr r0, =gUnknown_030012E2
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D3B76
	strb r7, [r4]
_081D3B76:
	movs r0, 0x1
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	ldr r0, =gUnknown_030012E4
	strh r1, [r0]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D3BA0
	movs r4, 0
	b _081D3BC2
	.pool
_081D3BA0:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D3BAC
	movs r4, 0x1
	b _081D3BC2
_081D3BAC:
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081D3BC0
	strb r0, [r4]
	bl VBlankIntrWait
	b _081D3B64
_081D3BC0:
	movs r4, 0x2
_081D3BC2:
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	bl sub_81D41F4
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3B54

	thumb_func_start sub_81D3BE8
sub_81D3BE8: @ 81D3BE8
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	bl sub_81D41A0
	movs r6, 0x2
	ldr r4, =gUnknown_03003144
_081D3BF6:
	bl sub_81D4170
	ldr r0, =gUnknown_030012E2
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D3C08
	strb r6, [r4]
_081D3C08:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_81D3D70
	adds r1, r0, 0
	ldr r0, =gUnknown_030012E4
	strh r1, [r0]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D3C34
	movs r4, 0
	b _081D3C56
	.pool
_081D3C34:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D3C40
	movs r4, 0x1
	b _081D3C56
_081D3C40:
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081D3C54
	strb r0, [r4]
	bl VBlankIntrWait
	b _081D3BF6
_081D3C54:
	movs r4, 0x2
_081D3C56:
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	bl sub_81D41F4
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3BE8

	thumb_func_start sub_81D3C7C
sub_81D3C7C: @ 81D3C7C
	push {r4,lr}
	ldr r4, =0x04000208
	movs r3, 0
	strh r3, [r4]
	ldr r2, =0x04000200
	ldrh r1, [r2]
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r4]
	ldr r0, =0x04000128
	strh r3, [r0]
	subs r0, 0x1A
	strh r3, [r0]
	ldr r1, =0x04000202
	movs r0, 0xC0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3C7C

	thumb_func_start sub_81D3CBC
sub_81D3CBC: @ 81D3CBC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r5, =0x04000208
	movs r4, 0
	strh r4, [r5]
	ldr r3, =0x04000200
	ldrh r1, [r3]
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r3]
	movs r6, 0x1
	strh r6, [r5]
	ldr r0, =0x04000134
	strh r4, [r0]
	ldr r2, =0x04000128
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r7, =0x00004003
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	strh r4, [r5]
	ldrh r0, [r3]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r3]
	strh r6, [r5]
	ldr r1, =gUnknown_030012C8
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _081D3D0A
	str r0, [sp]
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
_081D3D0A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3CBC

	thumb_func_start sub_81D3D34
sub_81D3D34: @ 81D3D34
	ldr r0, =0x04000134
	movs r3, 0
	strh r3, [r0]
	ldr r2, =0x04000128
	movs r1, 0xA0
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strh r0, [r2]
	ldr r0, =gUnknown_03003144
	strb r3, [r0]
	ldr r0, =gUnknown_030012E6
	strh r3, [r0]
	ldr r1, =gUnknown_030012E8
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D3D34

	thumb_func_start sub_81D3D70
sub_81D3D70: @ 81D3D70
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030012C8
	ldrb r0, [r0, 0x1]
	cmp r0, 0x6
	bls _081D3D86
	b _081D3ECC
_081D3D86:
	lsls r0, 2
	ldr r1, =_081D3D98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D3D98:
	.4byte _081D3DB4
	.4byte _081D3DC8
	.4byte _081D3DE8
	.4byte _081D3DFC
	.4byte _081D3E74
	.4byte _081D3E84
	.4byte _081D3EBC
_081D3DB4:
	bl sub_81D3CBC
	ldr r1, =gUnknown_030012C8
	movs r0, 0x1
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3DC8:
	adds r0, r2, 0
	bl sub_81D3EE8
	lsls r0, 16
	cmp r0, 0
	beq _081D3DD8
	bl sub_81D413C
_081D3DD8:
	ldr r0, =gUnknown_03003144
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081D3DE2
	b _081D3ECC
_081D3DE2:
	b _081D3E04
	.pool
_081D3DE8:
	bl sub_81D3D34
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D3F1C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x3
	strb r0, [r1, 0x1]
_081D3DFC:
	ldr r0, =gUnknown_03003144
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081D3E18
_081D3E04:
	ldr r1, =gUnknown_030012C8
	strb r0, [r1, 0x4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3E18:
	ldr r2, =gUnknown_030012E6
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	ldr r1, =gUnknown_030012E8
	ldr r0, [r1]
	adds r3, r0, 0x1
	str r3, [r1]
	ldr r1, =gUnknown_030012C8
	ldrb r0, [r1]
	cmp r0, 0
	bne _081D3E3C
	cmp r3, 0x3C
	bls _081D3E3C
	movs r0, 0x1
	strb r0, [r1, 0x4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
_081D3E3C:
	ldr r4, =gUnknown_030012C8
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _081D3ECC
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D3E64
	ldrh r0, [r2]
	cmp r0, 0x2
	bls _081D3E64
	bl sub_81D413C
	movs r0, 0x2
	b _081D3ECA
	.pool
_081D3E64:
	bl sub_81D413C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x2
	strb r0, [r1, 0x2]
	b _081D3ECC
	.pool
_081D3E74:
	bl sub_81D3CBC
	ldr r1, =gUnknown_030012C8
	movs r0, 0x5
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3E84:
	ldr r0, =gUnknown_030012C8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081D3E98
	ldr r0, =gUnknown_030012E6
	ldrh r0, [r0]
	cmp r0, 0x2
	bls _081D3E98
	bl sub_81D413C
_081D3E98:
	ldr r1, =gUnknown_030012E6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3C
	bls _081D3ECC
	ldr r0, =gUnknown_030012C8
	movs r1, 0x1
	strb r1, [r0, 0x4]
	movs r1, 0x6
	strb r1, [r0, 0x1]
	b _081D3ECC
	.pool
_081D3EBC:
	ldr r4, =gUnknown_030012C8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _081D3ECC
	bl sub_81D3C7C
	movs r0, 0
_081D3ECA:
	strb r0, [r4, 0x2]
_081D3ECC:
	ldr r2, =gUnknown_030012C8
	ldrb r0, [r2, 0x2]
	ldrb r1, [r2, 0x4]
	lsls r1, 2
	orrs r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 4
	orrs r0, r1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3D70

	thumb_func_start sub_81D3EE8
sub_81D3EE8: @ 81D3EE8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =0x04000128
	ldr r0, [r0]
	movs r1, 0xC
	ands r0, r1
	cmp r0, 0x8
	bne _081D3F0C
	cmp r2, 0
	beq _081D3F0C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x1
	b _081D3F10
	.pool
_081D3F0C:
	ldr r1, =gUnknown_030012C8
	movs r0, 0
_081D3F10:
	strb r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3EE8

	thumb_func_start sub_81D3F1C
sub_81D3F1C: @ 81D3F1C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r3, =gUnknown_030012C8
	ldrb r0, [r3]
	cmp r0, 0
	beq _081D3F54
	ldr r2, =0x04000128
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	str r5, [r3, 0x8]
	ldr r0, =0x04000120
	str r4, [r0]
	lsrs r0, r4, 2
	adds r0, 0x1
	str r0, [r3, 0x10]
	bl sub_81D3F68
	b _081D3F5C
	.pool
_081D3F54:
	ldr r1, =0x04000128
	ldrh r0, [r1]
	strh r0, [r1]
	str r2, [r3, 0x8]
_081D3F5C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3F1C

	thumb_func_start sub_81D3F68
sub_81D3F68: @ 81D3F68
	ldr r1, =0x0400010c
	ldr r2, =0x0000fda7
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x0400010e
	movs r2, 0x40
	strh r2, [r0]
	ldr r3, =0x04000208
	movs r0, 0
	strh r0, [r3]
	adds r1, 0xF4
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	movs r0, 0x1
	strh r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_81D3F68

	thumb_func_start sub_81D3F9C
sub_81D3F9C: @ 81D3F9C
	push {lr}
	bl sub_81D414C
	bl sub_81D413C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3F9C

	thumb_func_start sub_81D3FAC
sub_81D3FAC: @ 81D3FAC
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r2, =gUnknown_030012C8
	ldrb r0, [r2, 0x1]
	adds r3, r2, 0
	cmp r0, 0x3
	beq _081D4034
	cmp r0, 0x3
	bgt _081D3FC8
	cmp r0, 0x1
	beq _081D3FD0
	b _081D412A
	.pool
_081D3FC8:
	cmp r0, 0x5
	bne _081D3FCE
	b _081D40FC
_081D3FCE:
	b _081D412A
_081D3FD0:
	ldr r1, =0x0400012a
	ldr r2, =0x0000ccd0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r2, 0
	movs r4, 0
	ldr r6, =0x0000ccd0
	ldr r5, =0x0000ffff
_081D3FEC:
	lsls r0, r1, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D4010
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	b _081D401A
	.pool
_081D4010:
	cmp r0, r5
	beq _081D401A
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081D401A:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bls _081D3FEC
	cmp r2, 0x2
	beq _081D402A
	b _081D412A
_081D402A:
	cmp r4, 0
	beq _081D4030
	b _081D412A
_081D4030:
	strb r2, [r3, 0x1]
	b _081D412A
_081D4034:
	ldr r0, =0x04000120
	ldr r4, [r0]
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _081D404A
	ldrb r0, [r2]
	cmp r0, 0
	bne _081D404A
	lsrs r0, r4, 2
	adds r0, 0x1
	str r0, [r2, 0x10]
_081D404A:
	ldrb r0, [r3]
	cmp r0, 0x1
	bne _081D4080
	ldr r1, [r3, 0xC]
	ldr r0, [r3, 0x10]
	cmp r1, r0
	bge _081D4074
	ldr r2, =0x04000120
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r3, 0x14]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r3, 0x14]
	b _081D40BA
	.pool
_081D4074:
	ldr r1, =0x04000120
	ldr r0, [r3, 0x14]
	b _081D40B8
	.pool
_081D4080:
	ldr r1, [r3, 0xC]
	cmp r1, 0
	ble _081D40A0
	ldr r0, [r3, 0x10]
	adds r0, 0x1
	cmp r1, r0
	bge _081D40A0
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	subs r1, 0x4
	str r4, [r1]
	ldr r0, [r3, 0x14]
	adds r0, r4
	str r0, [r3, 0x14]
	b _081D40B4
_081D40A0:
	ldr r0, [r3, 0xC]
	cmp r0, 0
	beq _081D40B4
	ldr r0, [r3, 0x14]
	cmp r0, r4
	bne _081D40B0
	movs r0, 0x1
	b _081D40B2
_081D40B0:
	movs r0, 0x2
_081D40B2:
	strb r0, [r3, 0x3]
_081D40B4:
	ldr r1, =gUnknown_030012E8
	movs r0, 0
_081D40B8:
	str r0, [r1]
_081D40BA:
	ldr r1, [r3, 0xC]
	adds r1, 0x1
	str r1, [r3, 0xC]
	ldr r0, [r3, 0x10]
	adds r0, 0x2
	cmp r1, r0
	bge _081D40EA
	ldrb r0, [r3]
	cmp r0, 0
	beq _081D40E4
	ldr r0, =0x0400010e
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	b _081D412A
	.pool
_081D40E4:
	bl sub_81D413C
	b _081D412A
_081D40EA:
	movs r0, 0
	movs r1, 0x4
	strb r1, [r3, 0x1]
	ldr r1, =gUnknown_030012E6
	strh r0, [r1]
	b _081D412A
	.pool
_081D40FC:
	ldrb r3, [r2]
	cmp r3, 0
	bne _081D4108
	ldr r1, =0x0400012a
	ldrb r0, [r2, 0x3]
	strh r0, [r1]
_081D4108:
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r1, [r0, 0x2]
	subs r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D412A
	cmp r3, 0x1
	bne _081D4126
	strb r1, [r2, 0x3]
_081D4126:
	movs r0, 0x6
	strb r0, [r2, 0x1]
_081D412A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3FAC

	thumb_func_start sub_81D413C
sub_81D413C: @ 81D413C
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D413C

	thumb_func_start sub_81D414C
sub_81D414C: @ 81D414C
	ldr r2, =0x0400010e
	ldrh r1, [r2]
	ldr r0, =0x0000ff7f
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0400010c
	ldr r2, =0x0000fda7
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D414C

	thumb_func_start sub_81D4170
sub_81D4170: @ 81D4170
	push {r4,lr}
	ldr r0, =0x04000130
	ldrh r0, [r0]
	ldr r2, =0x000003ff
	adds r1, r2, 0
	eors r1, r0
	ldr r4, =gUnknown_030012E2
	ldr r3, =gUnknown_030012E0
	ldrh r2, [r3]
	adds r0, r1, 0
	bics r0, r2
	strh r0, [r4]
	strh r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4170

	thumb_func_start sub_81D41A0
sub_81D41A0: @ 81D41A0
	ldr r1, =gUnknown_030012EC
	ldr r0, =0x04000208
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012EE
	ldr r0, =0x04000200
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F0
	ldr r0, =0x0400010e
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F2
	ldr r0, =0x04000128
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F4
	ldr r0, =0x04000134
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D41A0

	thumb_func_start sub_81D41F4
sub_81D41F4: @ 81D41F4
	ldr r1, =0x04000208
	ldr r0, =gUnknown_030012EC
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =gUnknown_030012EE
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, 0xF2
	ldr r0, =gUnknown_030012F0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0x1A
	ldr r0, =gUnknown_030012F2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0xC
	ldr r0, =gUnknown_030012F4
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D41F4

	thumb_func_start sub_81D4238
sub_81D4238: @ 81D4238
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4238

	thumb_func_start sub_81D4258
sub_81D4258: @ 81D4258
	push {lr}
	sub sp, 0x4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x1
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4258

	thumb_func_start sub_81D427C
sub_81D427C: @ 81D427C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r2, =gUnknown_02037350
	adds r5, r1, r2
	ldr r4, =gUnknown_030012F8
	ldr r3, =gUnknown_02037590
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x14]
	ldrh r1, [r5, 0x10]
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gUnknown_030012FA
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x16]
	ldrh r1, [r5, 0x12]
	subs r0, r1
	strh r0, [r4]
	movs r0, 0
	mov r8, r0
	ldr r2, =gUnknown_030012FC
	movs r1, 0
_081D42CA:
	mov r3, r8
	adds r0, r3, r2
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bls _081D42CA
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	movs r4, 0x14
	ldrsh r1, [r2, r4]
	movs r6, 0x10
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bne _081D4304
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	movs r3, 0x12
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _081D4356
_081D4304:
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	cmp r1, 0
	bne _081D4338
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	b _081D433E
	.pool
_081D4338:
	ldrb r0, [r5, 0x1]
	movs r1, 0x20
	orrs r0, r1
_081D433E:
	strb r0, [r5, 0x1]
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D4360
_081D4356:
	movs r0, 0
	b _081D4816
	.pool
_081D4360:
	movs r4, 0
	mov r8, r4
	ldr r6, =gUnknown_02037350
	mov r10, r6
_081D4368:
	ldr r3, =gUnknown_02037590
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r4, r0, r1
	mov r2, r8
	lsls r1, r2, 2
	ldr r6, =gUnknown_0862608C
	adds r0, r1, r6
	movs r6, 0x14
	ldrsh r2, [r4, r6]
	movs r6, 0
	ldrsh r0, [r0, r6]
	ldr r6, =gUnknown_02037350
	mov r9, r6
	mov r12, r3
	adds r7, r1, 0
	cmp r2, r0
	beq _081D4394
	b _081D449E
_081D4394:
	movs r3, 0
	ldr r1, =gUnknown_0862608E
	adds r0, r7, r1
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D43C0
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D43CA
	b _081D449E
	.pool
_081D43C0:
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D43CA
	movs r3, 0x1
_081D43CA:
	cmp r3, 0
	bne _081D449E
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4410
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
_081D4408:
	movs r0, 0x4
	b _081D4816
	.pool
_081D4410:
	cmp r0, 0
	bge _081D4446
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
	b _081D45AA
_081D4446:
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	movs r4, 0x14
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _081D449E
	ldr r0, =gUnknown_030012FA
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	ble _081D4488
	adds r0, r1, 0
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D449E
_081D447C:
	movs r0, 0x2
	b _081D4816
	.pool
_081D4488:
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	bne _081D4538
_081D449E:
	ldr r2, =gUnknown_02037590
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r3, r10
	adds r4, r0, r3
	ldr r6, =gUnknown_0862608C
	ldr r1, =gUnknown_0862608E
	adds r0, r7, r1
	movs r3, 0x16
	ldrsh r1, [r4, r3]
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r3, =gUnknown_02037350
	mov r9, r3
	mov r12, r2
	cmp r1, r0
	beq _081D44C6
	b _081D45D0
_081D44C6:
	movs r3, 0
	adds r0, r7, r6
	movs r6, 0x14
	ldrsh r1, [r4, r6]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D44F0
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D44FA
	b _081D45D0
	.pool
_081D44F0:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D44FA
	movs r3, 0x1
_081D44FA:
	cmp r3, 0
	bne _081D45D0
	ldr r0, =gUnknown_030012FA
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4540
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
_081D4538:
	movs r0, 0x1
	b _081D4816
	.pool
_081D4540:
	cmp r0, 0
	bge _081D4576
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
	b _081D447C
_081D4576:
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	movs r3, 0x16
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _081D45D0
	ldr r0, =gUnknown_030012F8
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	ble _081D45B8
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
_081D45AA:
	movs r0, 0x3
	b _081D4816
	.pool
_081D45B8:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
	b _081D4408
_081D45D0:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bhi _081D45E0
	b _081D4368
_081D45E0:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D461C
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4604
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4604:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4614
	b _081D447C
_081D4614:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D461C:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	beq _081D4658
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4640
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4640:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4650
	b _081D4538
_081D4650:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4658:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4694
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D467C
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D467C:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D468C
	b _081D4408
_081D468C:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4694:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	beq _081D46D0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D46B8
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46B8:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D46C8
	b _081D45AA
_081D46C8:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46D0:
	ldr r0, =gUnknown_030012FA
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _081D476E
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r4, 0x12
	ldrsh r1, [r0, r4]
	ldrh r2, [r5, 0x12]
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D470C
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	subs r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D470C
	b _081D447C
_081D470C:
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x12]
	movs r3, 0x12
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D473E
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	adds r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D473E
	b _081D4538
_081D473E:
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4756
	b _081D447C
_081D4756:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D476E
	b _081D4538
_081D476E:
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081D480C
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	ldrh r2, [r5, 0x10]
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	cmp r1, r0
	ble _081D47AA
	subs r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47AA
	b _081D45AA
_081D47AA:
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x10]
	movs r3, 0x10
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D47DC
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r4, 0x12
	ldrsh r1, [r5, r4]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47DC
	b _081D4408
_081D47DC:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47F4
	b _081D4408
_081D47F4:
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D480C
	b _081D45AA
_081D480C:
	movs r0, 0
	bl sub_81D4890
_081D4812:
	lsls r0, 24
	lsrs r0, 24
_081D4816:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D427C

	thumb_func_start sub_81D4834
sub_81D4834: @ 81D4834
	push {r4,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gUnknown_02037350
	ldr r1, =gUnknown_02037590
	ldrb r2, [r1, 0x5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r3
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0x12
	ldrsh r1, [r2, r0]
	lsls r0, r4, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0
	b _081D4888
	.pool
_081D4870:
	lsls r0, r3, 16
	asrs r0, 16
	lsls r1, r4, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl sub_8088E64
	lsls r0, 24
	lsrs r0, 24
_081D4888:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4834

	thumb_func_start sub_81D4890
sub_81D4890: @ 81D4890
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r4, r1, r0
	movs r1, 0
	ldr r3, =gUnknown_030012FC
	movs r2, 0
_081D48B0:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D48B0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D48E8
	cmp r6, 0x2
	beq _081D48E8
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D48E8:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4912
	cmp r6, 0x4
	beq _081D4912
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4912:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _081D493A
	cmp r6, 0x1
	beq _081D493A
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D493A:
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4964
	cmp r6, 0x3
	beq _081D4964
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x3
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4964:
	cmp r5, 0x1
	bhi _081D4974
	ldr r0, =gUnknown_030012FC
	b _081D4988
	.pool
_081D4974:
	ldr r4, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	adds r0, r4
_081D4988:
	ldrb r0, [r0]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4890

	thumb_func_start sub_81D4998
sub_81D4998: @ 81D4998
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D49E0
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000270e
	cmp r2, r0
	bls _081D49D8
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	b _081D49E0
	.pool
_081D49D8:
	adds r0, r4, 0
	adds r1, r2, 0
	bl VarSet
_081D49E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D4998

	thumb_func_start FieldObjectIsFarawayIslandMew
@ bool8 FieldObjectIsFarawayIslandMew(struct npc_state *fieldObject)
FieldObjectIsFarawayIslandMew: @ 81D49E8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A0C
	ldrb r0, [r2, 0x5]
	cmp r0, 0xE5
	bne _081D4A0C
	movs r0, 0x1
	b _081D4A0E
	.pool
_081D4A0C:
	movs r0, 0
_081D4A0E:
	pop {r1}
	bx r1
	thumb_func_end FieldObjectIsFarawayIslandMew

	thumb_func_start unown_chamber_related
unown_chamber_related: @ 81D4A14
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A50
	movs r0, 0xE5
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	ldr r0, =0x000002ce
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	movs r0, 0x1
	b _081D4A52
	.pool
_081D4A50:
	movs r0, 0
_081D4A52:
	pop {r1}
	bx r1
	thumb_func_end unown_chamber_related

	thumb_func_start sub_81D4A58
sub_81D4A58: @ 81D4A58
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _081D4A88
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _081D4A88
	movs r0, 0x1
	b _081D4A8A
	.pool
_081D4A88:
	movs r0, 0
_081D4A8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4A58

	thumb_func_start sub_81D4A90
sub_81D4A90: @ 81D4A90
	push {r4-r6,lr}
	sub sp, 0x4
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r5, r1, r0
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r0, =gUnknown_020375E0
	ldrh r4, [r0]
	cmp r4, 0x1
	bne _081D4AF8
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r3, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x43
	strb r4, [r0]
	b _081D4BC4
	.pool
_081D4AF8:
	ldr r0, =0x0000403a
	ldr r1, =0x0000ffff
	bl VarSet
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r6, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gUnknown_020375F4
	ldrh r0, [r0]
	cmp r0, 0x2
	beq _081D4B3A
	ldrb r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
_081D4B3A:
	ldr r4, =gFieldEffectObjectPaletteInfo1
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	bl sub_80ABE18
	ldrh r1, [r5, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x3C]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	ldrb r4, [r5, 0x4]
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r3, r6
	adds r3, 0x43
	ldrb r3, [r3]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSpriteAtEnd
	ldr r1, =gUnknown_0203CF50
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081D4BC4
	ldrb r0, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_081D4BC4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4A90

	thumb_func_start sub_81D4BEC
sub_81D4BEC: @ 81D4BEC
	push {lr}
	ldr r1, =gUnknown_0203CF50
	ldrb r0, [r1]
	cmp r0, 0x40
	beq _081D4C06
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_081D4C06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4BEC

	thumb_func_start sub_81D4C14
sub_81D4C14: @ 81D4C14
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4C50
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C50
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C52
	.pool
_081D4C50:
	movs r0, 0
_081D4C52:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C14

	thumb_func_start sub_81D4C58
sub_81D4C58: @ 81D4C58
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4C94
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C94
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x4
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C96
	.pool
_081D4C94:
	movs r0, 0
_081D4C96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C58

	thumb_func_start sub_81D4C9C
sub_81D4C9C: @ 81D4C9C
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4CD8
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4CD8
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	b _081D4CDA
	.pool
_081D4CD8:
	movs r0, 0
_081D4CDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C9C

	thumb_func_start sub_81D4CE0
sub_81D4CE0: @ 81D4CE0
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4D1C
	ldrh r0, [r2, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4D1C
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x3
	strb r1, [r0]
	movs r0, 0x1
	b _081D4D1E
	.pool
_081D4D1C:
	movs r0, 0
_081D4D1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4CE0

	thumb_func_start sub_81D4D24
sub_81D4D24: @ 81D4D24
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	adds r0, r5
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4D24

	thumb_func_start sub_81D4D50
sub_81D4D50: @ 81D4D50
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	ldr r1, =gIntrTable
	ldr r0, =sub_81D3FAC
	str r0, [r1, 0x4]
	ldr r0, =sub_81D3F9C
	str r0, [r1, 0x8]
	bl sub_81D41A0
	bl sub_81D4238
	ldr r2, =0x04000200
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	strh r0, [r5]
	str r6, [r5, 0x4]
	mov r0, r8
	str r0, [r5, 0x8]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4D50

	thumb_func_start sub_81D4DB8
sub_81D4DB8: @ 81D4DB8
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	bl sub_81D4238
	bl sub_81D41F4
	bl RestoreSerialTimer3IntrHandlers
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4DB8

	thumb_func_start sub_81D4DE8
sub_81D4DE8: @ 81D4DE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	movs r0, 0x1
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	strh r1, [r4]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D4E08
	movs r5, 0x1
_081D4E08:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D4E12
	movs r5, 0x2
_081D4E12:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D4E1C
	movs r5, 0x3
_081D4E1C:
	ldr r1, =gUnknown_03003144
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4DE8

	thumb_func_start sub_81D4E30
sub_81D4E30: @ 81D4E30
	push {lr}
	ldr r0, =0x0201c000
	movs r2, 0x80
	lsls r2, 6
	movs r1, 0
	bl memset
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00005503
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_8009734
	movs r0, 0x1
	bl sub_800B330
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4E30

	thumb_func_start sub_81D4E60
sub_81D4E60: @ 81D4E60
	push {lr}
	sub sp, 0xC
	mov r1, sp
	ldr r2, =0x04000208
	ldrh r0, [r2]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r2]
	ldr r0, =gUnknown_03003174
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2]
	add r2, sp, 0x4
	ldrh r1, [r2]
	ldr r0, =0x0000b9a0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ccd0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x4]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081D4EB8
	ldrh r0, [r2, 0x6]
	cmp r0, r1
	bne _081D4EB8
	movs r0, 0x1
	b _081D4EBA
	.pool
_081D4EB8:
	movs r0, 0
_081D4EBA:
	add sp, 0xC
	pop {r1}
	bx r1
	thumb_func_end sub_81D4E60

	thumb_func_start sub_81D4EC0
sub_81D4EC0: @ 81D4EC0
	push {lr}
	bl sub_800ABBC
	lsls r0, 24
	cmp r0, 0
	beq _081D4EDC
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4EDC
	movs r0, 0x1
	b _081D4EDE
_081D4EDC:
	movs r0, 0
_081D4EDE:
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EC0

	thumb_func_start sub_81D4EE4
sub_81D4EE4: @ 81D4EE4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081D4F08
	bl sub_800B33C
	lsls r0, 24
	cmp r0, 0
	beq _081D4F08
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x3
	b _081D500E
_081D4F08:
	ldrb r0, [r4]
	cmp r0, 0x5
	bls _081D4F10
	b _081D500C
_081D4F10:
	lsls r0, 2
	ldr r1, =_081D4F20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D4F20:
	.4byte _081D4F38
	.4byte _081D4F54
	.4byte _081D4F6C
	.4byte _081D4FA0
	.4byte _081D4FEC
	.4byte _081D4FF8
_081D4F38:
	bl sub_800ABBC
	lsls r0, 24
	cmp r0, 0
	beq _081D4F88
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D4F88
	movs r0, 0x1
	strb r0, [r4]
	b _081D500C
_081D4F54:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _081D500C
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x2
	strb r0, [r4]
	b _081D500C
_081D4F6C:
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4F88
	movs r0, 0x49
	bl audio_play
	bl sub_800A620
	movs r0, 0
	strh r0, [r5]
	b _081D4FE6
_081D4F88:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D500C
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x1
	b _081D500E
	.pool
_081D4FA0:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _081D4FB6
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x5
	b _081D500E
_081D4FB6:
	bl sub_800B320
	lsls r0, 24
	cmp r0, 0
	beq _081D500C
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D4FE6
	bl sub_800A23C
	lsls r0, 24
	cmp r0, 0
	beq _081D4FE0
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x2
	b _081D500E
	.pool
_081D4FE0:
	movs r0, 0x4
	strb r0, [r4]
	b _081D500C
_081D4FE6:
	movs r0, 0x3
	strb r0, [r4]
	b _081D500C
_081D4FEC:
	movs r0, 0
	bl sub_800ABF4
	movs r0, 0x5
	strb r0, [r4]
	b _081D500C
_081D4FF8:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D500C
	strb r0, [r4]
	movs r0, 0x4
	b _081D500E
	.pool
_081D500C:
	movs r0, 0
_081D500E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EE4

	thumb_func_start sub_81D5014
sub_81D5014: @ 81D5014
	push {r4,lr}
	ldr r0, =sub_81D5084
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0
	strb r0, [r4, 0x8]
	strb r0, [r4, 0x9]
	strb r0, [r4, 0xA]
	strb r0, [r4, 0xB]
	strb r0, [r4, 0xC]
	strb r0, [r4, 0xD]
	movs r1, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	strb r1, [r4, 0xE]
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5014

	thumb_func_start sub_81D505C
sub_81D505C: @ 81D505C
	movs r1, 0
	strh r1, [r0]
	bx lr
	thumb_func_end sub_81D505C

	thumb_func_start sub_81D5064
sub_81D5064: @ 81D5064
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, r1
	bhi _081D507A
	movs r0, 0
	b _081D5080
_081D507A:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
_081D5080:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5064

	thumb_func_start sub_81D5084
sub_81D5084: @ 81D5084
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1A
	bls _081D509C
	b _081D548A
_081D509C:
	lsls r0, 2
	ldr r1, =_081D50B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D50B0:
	.4byte _081D511C
	.4byte _081D5138
	.4byte _081D5148
	.4byte _081D515C
	.4byte _081D516C
	.4byte _081D5198
	.4byte _081D51D0
	.4byte _081D524C
	.4byte _081D5268
	.4byte _081D5290
	.4byte _081D52AC
	.4byte _081D52DC
	.4byte _081D52F2
	.4byte _081D5308
	.4byte _081D536A
	.4byte _081D5390
	.4byte _081D53A8
	.4byte _081D53C6
	.4byte _081D53F2
	.4byte _081D5418
	.4byte _081D5448
	.4byte _081D5454
	.4byte _081D5460
	.4byte _081D5430
	.4byte _081D548A
	.4byte _081D548A
	.4byte _081D5478
_081D511C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFD6
	bl mevent_0814257C
	cmp r0, 0
	bne _081D512C
	b _081D548A
_081D512C:
	movs r0, 0x1
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5138:
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _081D548A
_081D5148:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D5156
	b _081D548A
_081D5156:
	movs r0, 0x3
	strb r0, [r4, 0x8]
	b _081D548A
_081D515C:
	bl sub_81D4EC0
	cmp r0, 0
	beq _081D5166
	b _081D52FC
_081D5166:
	bl sub_80097E8
	b _081D525C
_081D516C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFF5
	bl mevent_0814257C
	cmp r0, 0
	bne _081D517C
	b _081D548A
_081D517C:
	ldr r0, =gUnknown_085EE014
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5198:
	adds r0, r4, 0
	movs r1, 0x5A
	bl sub_81D5064
	cmp r0, 0
	beq _081D51AE
	bl sub_81D4E30
	movs r0, 0x6
	strb r0, [r4, 0x8]
	b _081D548A
_081D51AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D51BC
	b _081D548A
_081D51BC:
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	bl audio_play
	b _081D535A
	.pool
_081D51D0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D51F4
	movs r0, 0x5
	bl audio_play
	bl sub_80097E8
	adds r0, r4, 0
	bl sub_81D505C
	b _081D535A
	.pool
_081D51F4:
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D5210
	adds r0, r4, 0
	bl sub_81D505C
	bl sub_80097E8
	movs r0, 0x7
	strb r0, [r4, 0x8]
	b _081D548A
_081D5210:
	bl sub_81D4E60
	cmp r0, 0
	beq _081D522E
	movs r0, 0x5
	bl audio_play
	bl sub_80097E8
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x8
	strb r0, [r4, 0x8]
	b _081D548A
_081D522E:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D523C
	b _081D548A
_081D523C:
	bl sub_80097E8
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	b _081D548A
_081D524C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE05C
	bl mevent_0814257C
	cmp r0, 0
	bne _081D525C
	b _081D548A
_081D525C:
	movs r0, 0x4
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5268:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	ldr r0, =gUnknown_03006370
	ldr r1, =gUnknown_089A6550
	ldr r2, =gUnknown_089A3470
	subs r1, r2
	bl sub_81D4D50
	movs r0, 0x9
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5290:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DE8
	strb r0, [r4, 0xE]
	lsls r0, 24
	cmp r0, 0
	bne _081D52A0
	b _081D548A
_081D52A0:
	movs r0, 0xA
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52AC:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DB8
	ldrb r0, [r4, 0xE]
	cmp r0, 0x3
	bne _081D52BA
	b _081D53C0
_081D52BA:
	cmp r0, 0x1
	beq _081D52C0
	b _081D546E
_081D52C0:
	adds r0, r4, 0
	bl sub_81D505C
	ldr r0, =gUnknown_085EE120
	bl sub_8018884
	movs r0, 0xB
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52DC:
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r4, 0
	bl sub_81D5064
	cmp r0, 0
	bne _081D52EC
	b _081D548A
_081D52EC:
	movs r0, 0xC
	strb r0, [r4, 0x8]
	b _081D548A
_081D52F2:
	bl sub_81D4E30
	ldr r0, =gUnknown_085EE0DC
	bl sub_8018884
_081D52FC:
	movs r0, 0xD
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5308:
	adds r0, r4, 0
	adds r0, 0x9
	adds r1, r4, 0
	bl sub_81D4EE4
	cmp r0, 0x5
	bls _081D5318
	b _081D548A
_081D5318:
	lsls r0, 2
	ldr r1, =_081D5328
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D5328:
	.4byte _081D548A
	.4byte _081D5350
	.4byte _081D5340
	.4byte _081D5374
	.4byte _081D5374
	.4byte _081D5360
_081D5340:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	movs r0, 0xE
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5350:
	movs r0, 0x5
	bl audio_play
	bl sub_80097E8
_081D535A:
	movs r0, 0x17
	strb r0, [r4, 0x8]
	b _081D548A
_081D5360:
	bl sub_80097E8
	movs r0, 0x15
	strb r0, [r4, 0x8]
	b _081D548A
_081D536A:
	bl sub_800B33C
	lsls r0, 24
	cmp r0, 0
	beq _081D537A
_081D5374:
	bl sub_80097E8
	b _081D53C0
_081D537A:
	bl sub_800A550
	lsls r0, 24
	cmp r0, 0
	bne _081D5386
	b _081D548A
_081D5386:
	bl sub_800A5B4
	movs r0, 0xF
	strb r0, [r4, 0x8]
	b _081D548A
_081D5390:
	ldr r0, =0x0201c000
	bl sub_81D3920
	strb r0, [r4, 0xE]
	ldrb r0, [r4, 0xE]
	bl sub_800ABF4
	movs r0, 0x10
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53A8:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D548A
	ldrb r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081D53C0
	movs r0, 0x11
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53C0:
	movs r0, 0x14
	strb r0, [r4, 0x8]
	b _081D548A
_081D53C6:
	ldr r0, =0x0201c000
	bl sub_81D3AB0
	cmp r0, 0
	beq _081D53EC
	ldr r0, =gUnknown_085EE0FA
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x12
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53EC:
	movs r0, 0x16
	strb r0, [r4, 0x8]
	b _081D548A
_081D53F2:
	adds r0, r4, 0
	movs r1, 0x78
	bl sub_81D5064
	cmp r0, 0
	beq _081D548A
	ldr r0, =gUnknown_085EE107
	bl sub_8018884
	movs r0, 0xB9
	lsls r0, 1
	bl fanfare_play
	movs r0, 0x13
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5418:
	bl task_is_not_running_overworld_fanfare
	lsls r0, 24
	cmp r0, 0
	beq _081D548A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	b _081D543A
	.pool
_081D5430:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE06B
	bl mevent_0814257C
_081D543A:
	cmp r0, 0
	beq _081D548A
	movs r0, 0x1A
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5448:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0A3
	b _081D5466
	.pool
_081D5454:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0BF
	b _081D5466
	.pool
_081D5460:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE12D
_081D5466:
	bl mevent_0814257C
	cmp r0, 0
	beq _081D548A
_081D546E:
	movs r0, 0
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5478:
	ldr r0, [r4, 0x10]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =sub_80186A4
	bl SetMainCallback2
_081D548A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5084

	thumb_func_start sp194_trainer_tower
sp194_trainer_tower: @ 81D5494
	push {lr}
	bl sub_81D56B0
	ldr r1, =gUnknown_0862A618
	ldr r0, =gUnknown_020375E0
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
	ldr r0, =gUnknown_02037318
	ldrb r0, [r0, 0x12]
	adds r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_81D5520

	thumb_func_start sub_81D5530
sub_81D5530: @ 81D5530
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	ldr r2, =gTrainerClassNameIndices
	ldr r1, =gUnknown_0203CF58
	ldr r1, [r1]
	adds r1, 0x16
	adds r1, r0
	ldrb r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D5530

	thumb_func_start sub_81D5554
sub_81D5554: @ 81D5554
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
	thumb_func_end sub_81D5554

	thumb_func_start sub_81D5588
sub_81D5588: @ 81D5588
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
	ldr r0, =gTrainerPicIndices
	adds r4, r0
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D5588

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
	ldr r1, =gUnknown_02037318
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

	thumb_func_start sub_81D572C
sub_81D572C: @ 81D572C
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
	bl ConvertBattleFrontierTrainerSpeechToString
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
	bl ConvertBattleFrontierTrainerSpeechToString
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
	bl ConvertBattleFrontierTrainerSpeechToString
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
	bl ConvertBattleFrontierTrainerSpeechToString
_081D580E:
	bl sub_81D5710
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D572C

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
	ldr r3, =gUnknown_020375F0
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
	ldr r1, =gUnknown_020375F0
	movs r0, 0x2
	strh r0, [r1]
	b _081D59C0
	.pool
_081D596C:
	adds r0, r5, 0
	movs r1, 0x1
	bl bag_add_item
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D59BC
	ldr r1, =gStringVar2
	adds r0, r5, 0
	bl itemid_get_name
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
	ldr r0, =gUnknown_020375F0
	strh r4, [r0]
	b _081D59C0
	.pool
_081D59BC:
	ldr r0, =gUnknown_020375F0
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
	ldr r0, =gUnknown_020375F0
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
	ldr r0, =gUnknown_020375F0
	strh r5, [r0]
	b _081D5A4E
	.pool
_081D5A48:
	ldr r1, =gUnknown_020375F0
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
	ldr r1, =gUnknown_020375F0
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
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	b _081D5B20
	.pool
_081D5B1C:
	ldr r1, =gUnknown_020375F0
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
	ldr r1, =gUnknown_020375F0
	movs r0, 0
	b _081D5BF0
	.pool
_081D5BEC:
	ldr r1, =gUnknown_020375F0
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
	ldr r1, =gUnknown_020375F0
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
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
	b _081D5C7A
	.pool
_081D5C74:
	ldr r1, =gUnknown_020375F0
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

	thumb_func_start sub_81D5C8C
sub_81D5C8C: @ 81D5C8C
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
	ldr r5, =gUnknown_085EF88A
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
	bl box_print
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
	bl box_print
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
	ldr r1, =gUnknown_085EF895
	bl StringCopy
	ldr r1, =gUnknown_085EF8A3
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
	bl box_print
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
	thumb_func_end sub_81D5C8C

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
	ldr r0, =gUnknown_082C83F0
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
	ldr r0, =gUnknown_02037318
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
	ldr r1, =gUnknown_02037318
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
	ldr r0, =gUnknown_02037318
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
	ldr r0, =gUnknown_02037318
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
	bl get_mapheader_by_bank_and_number
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
	ldr r0, =gUnknown_02037318
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
	bl get_mapheader_by_bank_and_number
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
_081D6176:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6134

	thumb_func_start battle_init
battle_init: @ 81D6180
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
	thumb_func_end battle_init

	thumb_func_start GetTrainerHillTrainerFlag
@ u8 GetTrainerHillTrainerFlag(u8 fieldObjectId)
GetTrainerHillTrainerFlag: @ 81D619C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 23
	ldr r2, =gUnknown_02037350
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
	ldr r0, =gUnknown_02038BCA
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
	ldr r5, =gUnknown_02038BCC
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
	ldr r0, =gUnknown_082C83F0
	bx lr
	.pool
	thumb_func_end sub_81D62AC

	thumb_func_start sub_81D62B4
sub_81D62B4: @ 81D62B4
	push {lr}
	ldr r0, =gUnknown_020375F2
	ldrh r1, [r0]
	movs r0, 0x5
	bl sub_81D572C
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
	bl sub_8165CB4
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
	bl zero_enemy_party_data
	ldr r0, =gUnknown_02038BCA
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
	bl zero_enemy_party_data
	ldr r0, =gUnknown_02038BCA
	ldrh r0, [r0]
	movs r1, 0
	bl sub_81D62CC
	ldr r0, =gUnknown_02038BCC
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
	ldr r0, =gTrainerClassNameIndices
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
	bl pokemon_calc_effective_stats
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
	ldr r1, =gUnknown_020375F0
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
	ldr r0, =gUnknown_020375F0
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
	ldr r1, =gUnknown_020375F0
	movs r0, 0
	b _081D6594
	.pool
_081D6590:
	ldr r1, =gUnknown_020375F0
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
	ldr r5, =gUnknown_020375E2
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
	ldr r0, =0x00000864
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

	thumb_func_start sub_81D6720
sub_81D6720: @ 81D6720
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gUnknown_0203CF60
	ldr r0, =0x00002018
	bl AllocZeroed
	str r0, [r6]
	ldr r1, =0x00002006
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0]
	ldr r1, =0x00002007
	adds r0, r1
	strb r5, [r0]
	ldr r0, =sub_81D6774
	bl SetMainCallback2
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6720

	thumb_func_start sub_81D6774
sub_81D6774: @ 81D6774
	push {lr}
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	bl remove_some_task
	bl ResetObjectPaletteAllocator
	bl ResetPaletteFade
	bl ResetAllObjectData
	bl ResetTasks
	movs r0, 0
	movs r1, 0xF0
	movs r2, 0x20
	bl FillPalette
	ldr r1, =gUnknown_0862A6A0
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r2, =0x00002006
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81D67D0
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6774

	thumb_func_start sub_81D67D0
sub_81D67D0: @ 81D67D0
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81D67D0

	thumb_func_start sub_81D67EC
sub_81D67EC: @ 81D67EC
	push {lr}
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81D67EC

	thumb_func_start sub_81D6800
sub_81D6800: @ 81D6800
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D6830
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	ldr r4, =gUnknown_0203CF60
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
_081D6830:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6800

	thumb_func_start sub_81D6840
sub_81D6840: @ 81D6840
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081D68B2
	ldr r2, =gUnknown_0203CF60
	ldr r1, [r2]
	ldr r4, =0x00002007
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081D6888
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81D6800
	b _081D68B0
	.pool
_081D6888:
	ldr r4, =0x00002006
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r2, [r2]
	ldr r1, =0x00002004
	adds r0, r2, r1
	strh r5, [r0]
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r3, =gUnknown_0862A6A0
	adds r2, r4
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
_081D68B0:
	str r0, [r1]
_081D68B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6840

	thumb_func_start sub_81D68C8
sub_81D68C8: @ 81D68C8
	push {lr}
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r1, =0x00001888
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =gPlttBufferUnfaded
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gPlttBufferFaded
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D68C8

	thumb_func_start sub_81D6904
sub_81D6904: @ 81D6904
	push {lr}
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81D6904

	thumb_func_start sub_81D691C
sub_81D691C: @ 81D691C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	bl sub_81D750C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D697E
	movs r0, 0
	ldrsh r1, [r5, r0]
	cmp r1, 0x40
	bne _081D6954
	bl sub_81D7438
	b _081D6978
	.pool
_081D6954:
	cmp r1, 0x90
	bne _081D695E
	bl sub_81D7480
	b _081D6978
_081D695E:
	cmp r1, 0x94
	beq _081D6974
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	bne _081D6978
	adds r0, r4, 0
	movs r1, 0
	bl sub_81D75B4
	b _081D697E
_081D6974:
	bl sub_81D74C8
_081D6978:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_081D697E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D691C

	thumb_func_start sub_81D6984
sub_81D6984: @ 81D6984
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0862A72C
	mov r8, r0
	movs r1, 0x58
	movs r2, 0x48
	movs r3, 0x3
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gSprites
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D6A20
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	mov r0, r8
	movs r1, 0x38
	movs r2, 0x68
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r0, =gUnknown_0862A750
	movs r1, 0x4B
	movs r2, 0x65
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2]
	ldr r0, =gUnknown_0862A774
	movs r1, 0x6D
	movs r2, 0x72
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartObjectImageAnim
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6984

	thumb_func_start sub_81D6A20
sub_81D6A20: @ 81D6A20
	push {r4,lr}
	adds r3, r0, 0
	movs r0, 0x2E
	adds r0, r3
	mov r12, r0
	ldrh r0, [r0, 0xA]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	mov r1, r12
	strh r0, [r1, 0xA]
	cmp r0, 0
	bne _081D6A84
	ldrh r1, [r3, 0x20]
	movs r2, 0x20
	ldrsh r0, [r3, r2]
	cmp r0, 0x48
	beq _081D6A84
	subs r0, r1, 0x1
	strh r0, [r3, 0x20]
	ldr r2, =gSprites
	movs r4, 0x2E
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
_081D6A84:
	adds r0, r3, 0
	adds r0, 0x2B
	ldrb r3, [r0]
	cmp r3, 0x1
	beq _081D6AE4
	cmp r3, 0x1
	bgt _081D6A9C
	cmp r3, 0
	beq _081D6AA6
	b _081D6B68
	.pool
_081D6A9C:
	cmp r3, 0x2
	beq _081D6B24
	cmp r3, 0x3
	beq _081D6AE4
	b _081D6B68
_081D6AA6:
	ldr r2, =gSprites
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	b _081D6B5E
	.pool
_081D6AE4:
	ldr r2, =gSprites
	mov r0, r12
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	mov r4, r12
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0
	strh r3, [r0, 0x26]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	negs r1, r1
	b _081D6B58
	.pool
_081D6B24:
	ldr r2, =gSprites
	mov r3, r12
	movs r4, 0x2
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x1
	strh r3, [r0, 0x26]
	mov r4, r12
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
_081D6B58:
	strh r1, [r0, 0x24]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
_081D6B5E:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
_081D6B68:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6A20

	thumb_func_start sub_81D6B7C
sub_81D6B7C: @ 81D6B7C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r5, =gUnknown_0862A81C
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gSprites
	lsls r4, r0, 4
	add r4, r8
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D6D20
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0xA8
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0xA8
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	orrs r0, r1
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0xA8
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x68
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x88
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x6]
	adds r0, r5, 0
	movs r1, 0xB8
	movs r2, 0x80
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	orrs r0, r1
	strh r0, [r4, 0x6]
	ldr r0, =gUnknown_0862A84C
	movs r1, 0xD0
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0862A864
	movs r1, 0xC8
	movs r2, 0x78
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x8]
	orrs r0, r1
	strh r0, [r4, 0x8]
	ldrh r1, [r4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartObjectImageAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	bl StartObjectImageAnim
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x3
	bl StartObjectImageAnim
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x4
	bl StartObjectImageAnim
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	bl StartObjectImageAnim
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x6
	bl StartObjectImageAnim
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x7
	bl StartObjectImageAnim
	ldrb r1, [r4, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x8
	bl StartObjectImageAnim
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6B7C

	thumb_func_start sub_81D6D20
sub_81D6D20: @ 81D6D20
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r3, r4, 0
	adds r3, 0x2E
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r3, 0xA]
	ldr r7, =gSprites
	cmp r0, 0
	bne _081D6E0E
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x98
	beq _081D6E0E
	adds r0, r1, 0x1
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r4, 0x2E]
	movs r2, 0xFF
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x2]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x4]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x6]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x8]
	ands r2, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
_081D6E0E:
	adds r6, r7, 0
	movs r5, 0xFF
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2B
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _081D6EE0
	cmp r2, 0x1
	bgt _081D6E34
	cmp r2, 0
	beq _081D6E40
	b _081D6FC8
	.pool
_081D6E34:
	cmp r2, 0x2
	bne _081D6E3A
	b _081D6F68
_081D6E3A:
	cmp r2, 0x3
	beq _081D6EE0
	b _081D6FC8
_081D6E40:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x4]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x6]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	b _081D6FC6
_081D6EE0:
	movs r2, 0x1
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x8]
	b _081D6FBE
_081D6F68:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
_081D6FBE:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
_081D6FC6:
	strh r2, [r0, 0x26]
_081D6FC8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D6D20

	thumb_func_start sub_81D6FD0
sub_81D6FD0: @ 81D6FD0
	push {lr}
	bl sub_81D67EC
	bl sub_80BA0A8
	pop {r0}
	bx r0
	thumb_func_end sub_81D6FD0

	thumb_func_start sub_81D6FE0
sub_81D6FE0: @ 81D6FE0
	push {r4,lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862A888
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000804
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001004
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6FE0

	thumb_func_start sub_81D706C
sub_81D706C: @ 81D706C
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08DA33C0
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D7082:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D7082
	ldr r0, =gUnknown_08DA3988
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA3824
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA3A88
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA37E8
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0862A8C4
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A8F8
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A924
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A9D4
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AA14
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AA34
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862A8CC
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862A9DC
	bl LoadCompressedObjectPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D706C

	thumb_func_start task_add_00_WIN0V_open_close_above_and_more
task_add_00_WIN0V_open_close_above_and_more: @ 81D7134
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r7, =gTasks + 0x8
	adds r5, r6, r7
	bl dp12_8087EA4
	bl sub_81D6FE0
	bl sub_81D706C
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r1, =gUnknown_02038C28
	ldr r2, =0x010003c0
	add r0, sp, 0x4
	bl CpuFastSet
	ldr r2, =gUnknown_0862A87C
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80BA038
	strh r4, [r5]
	ldr r0, =sub_81D7228
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x2]
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r1, =0x00002006
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D71CC
	bl sub_81D6984
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x4]
	bl sub_81D6B7C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x6]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D691C
	str r1, [r0]
	b _081D71EE
	.pool
_081D71CC:
	bl sub_81D7664
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x4]
	bl sub_81D78BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x6]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D736C
	str r1, [r0]
	bl sub_80A2F30
_081D71EE:
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_81D6FD0
	bl SetVBlankCallback
	movs r0, 0x53
	bl audio_play
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_add_00_WIN0V_open_close_above_and_more

	thumb_func_start sub_81D7228
sub_81D7228: @ 81D7228
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r3, r1, r0
	movs r1, 0x18
	ldr r7, =gUnknown_0203CF60
	ldr r4, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r4, r0
_081D7244:
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r0, 0
	cmp r1, 0x2F
	bgt _081D726C
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3]
	b _081D72CA
	.pool
_081D726C:
	cmp r1, 0x3F
	bgt _081D7280
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x2]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x2]
	b _081D72CA
_081D7280:
	cmp r1, 0x4B
	bgt _081D7294
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x4]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x4]
	b _081D72CA
_081D7294:
	cmp r1, 0x53
	bgt _081D72A8
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x6]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x6]
	b _081D72CA
_081D72A8:
	cmp r1, 0x57
	bgt _081D72BC
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0x8]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x8]
	b _081D72CA
_081D72BC:
	lsls r1, 1
	adds r2, r1, r4
	ldrh r0, [r3, 0xA]
	lsrs r0, 8
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0xA]
_081D72CA:
	lsrs r0, 8
	strh r0, [r1]
	movs r1, 0x80
	lsls r1, 9
	adds r0, r6, r1
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x5B
	ble _081D7244
	ldr r0, [r7]
	ldr r1, =0x00002006
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D7324
	movs r1, 0xE0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x2]
	adds r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x4]
	adds r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x6]
	adds r0, r1
	strh r0, [r3, 0x6]
	ldrh r0, [r3, 0x8]
	adds r0, 0xC0
	b _081D735E
	.pool
_081D7324:
	movs r1, 0xC0
	lsls r1, 2
	adds r0, r1, 0
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	movs r1, 0xA0
	lsls r1, 2
	adds r0, r1, 0
	ldrh r1, [r3, 0x2]
	adds r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	ldrh r1, [r3, 0x4]
	adds r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x6]
	adds r0, r1
	strh r0, [r3, 0x6]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r3, 0x8]
	adds r0, r1
_081D735E:
	strh r0, [r3, 0x8]
	ldrh r0, [r3, 0xA]
	adds r0, 0x80
	strh r0, [r3, 0xA]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D7228

	thumb_func_start sub_81D736C
sub_81D736C: @ 81D736C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r7, =gTasks + 0x8
	adds r4, r0, r7
	bl sub_81D750C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _081D742E
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0x20
	beq _081D739C
	cmp r1, 0x70
	bne _081D73AC
_081D739C:
	bl sub_81D7438
	b _081D7428
	.pool
_081D73AC:
	cmp r1, 0xD8
	bne _081D73B6
	bl sub_81D7480
	b _081D7428
_081D73B6:
	cmp r1, 0xDC
	bne _081D73C0
	bl sub_81D74C8
	b _081D7428
_081D73C0:
	movs r0, 0xBE
	lsls r0, 1
	cmp r1, r0
	beq _081D73D8
	adds r0, 0x20
	cmp r1, r0
	bne _081D7428
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_81D75B4
	b _081D742E
_081D73D8:
	movs r1, 0x91
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	adds r2, r7, 0
	subs r2, 0x8
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_81D752C
	str r1, [r0]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r6, [r0, 0x8]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r4, 0x4]
	strh r1, [r0, 0xC]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r4, 0x6]
	strh r1, [r0, 0xE]
	bl remove_some_task
_081D7428:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081D742E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D736C

	thumb_func_start sub_81D7438
sub_81D7438: @ 81D7438
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0x57
	bl audio_play
	ldr r0, =0x00007fff
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7438

	thumb_func_start sub_81D7480
sub_81D7480: @ 81D7480
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0x57
	bl audio_play
	ldr r0, =0x00007fff
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x10
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x10
	bl sub_80A2C44
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7480

	thumb_func_start sub_81D74C8
sub_81D74C8: @ 81D74C8
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =0x00007fff
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x4
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0x4
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D74C8

	thumb_func_start sub_81D750C
sub_81D750C: @ 81D750C
	push {lr}
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0x2
	movs r2, 0x1
	bl ChangeBgX
	movs r1, 0x80
	lsls r1, 4
	movs r0, 0x2
	movs r2, 0x2
	bl ChangeBgY
	pop {r0}
	bx r0
	thumb_func_end sub_81D750C

	thumb_func_start sub_81D752C
sub_81D752C: @ 81D752C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl sub_81D7860
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl sub_81D7D14
	movs r0, 0x1
	bl GetBgY
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	bl GetBgY
	cmp r0, 0
	beq _081D757A
	movs r0, 0x80
	lsls r0, 8
	cmp r4, r0
	bls _081D7586
_081D757A:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgY
_081D7586:
	ldrh r2, [r5]
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x10
	beq _081D75A6
	adds r2, 0x1
	strh r2, [r5]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_081D75A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D752C

	thumb_func_start sub_81D75B4
sub_81D75B4: @ 81D75B4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x54
	bl audio_play
	movs r0, 0x1
	negs r0, r0
	lsls r4, 24
	asrs r4, 24
	movs r1, 0
	str r1, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D7600
	str r1, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D75B4

	thumb_func_start sub_81D7600
sub_81D7600: @ 81D7600
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r7, =gTasks + 0x8
	adds r5, r6, r7
	bl sub_81D750C
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081D7652
	ldrb r0, [r5, 0x2]
	bl DestroyTask
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0
	bl SetVBlankCallback
	bl remove_some_task
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	strh r4, [r5]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D6840
	str r1, [r0]
_081D7652:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7600

	thumb_func_start sub_81D7664
sub_81D7664: @ 81D7664
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0862A8D4
	mov r8, r0
	movs r1, 0x62
	movs r2, 0x48
	movs r3, 0x3
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gSprites
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D7700
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	mov r0, r8
	movs r1, 0x42
	movs r2, 0x68
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r0, =gUnknown_0862A900
	movs r1, 0x55
	movs r2, 0x65
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2]
	ldr r0, =gUnknown_0862A92C
	movs r1, 0x77
	movs r2, 0x72
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartObjectImageAnim
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D7664

	thumb_func_start sub_81D7700
sub_81D7700: @ 81D7700
	push {r4,lr}
	adds r3, r0, 0
	movs r0, 0x2E
	adds r0, r3
	mov r12, r0
	ldrh r0, [r0, 0xA]
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	mov r1, r12
	strh r0, [r1, 0xA]
	movs r1, 0x7
	ands r1, r0
	cmp r1, 0
	bne _081D7768
	ldrh r1, [r3, 0x20]
	movs r2, 0x20
	ldrsh r0, [r3, r2]
	cmp r0, 0x48
	beq _081D7768
	subs r0, r1, 0x1
	strh r0, [r3, 0x20]
	ldr r2, =gSprites
	movs r4, 0x2E
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
_081D7768:
	adds r0, r3, 0
	adds r0, 0x2B
	ldrb r3, [r0]
	cmp r3, 0x1
	beq _081D77C8
	cmp r3, 0x1
	bgt _081D7780
	cmp r3, 0
	beq _081D778A
	b _081D784C
	.pool
_081D7780:
	cmp r3, 0x2
	beq _081D7808
	cmp r3, 0x3
	beq _081D77C8
	b _081D784C
_081D778A:
	ldr r2, =gSprites
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	mov r0, r12
	movs r4, 0x4
	ldrsh r1, [r0, r4]
	b _081D7842
	.pool
_081D77C8:
	ldr r2, =gSprites
	mov r0, r12
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	mov r4, r12
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0
	strh r3, [r0, 0x26]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	negs r1, r1
	b _081D783C
	.pool
_081D7808:
	ldr r2, =gSprites
	mov r3, r12
	movs r4, 0x2
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x1
	strh r3, [r0, 0x26]
	mov r4, r12
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
_081D783C:
	strh r1, [r0, 0x24]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
_081D7842:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
_081D784C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7700

	thumb_func_start sub_81D7860
sub_81D7860: @ 81D7860
	push {r4,lr}
	adds r1, r0, 0
	adds r3, r1, 0
	adds r3, 0x2E
	ldrh r2, [r1, 0x22]
	movs r4, 0x22
	ldrsh r0, [r1, r4]
	cmp r0, 0xA0
	bgt _081D78B0
	adds r0, r2, 0
	adds r0, 0x8
	strh r0, [r1, 0x22]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r1, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	movs r4, 0x2
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
_081D78B0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7860

	thumb_func_start sub_81D78BC
sub_81D78BC: @ 81D78BC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r5, =gUnknown_0862A9E4
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gSprites
	lsls r4, r0, 4
	add r4, r8
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =sub_81D7A60
	str r1, [r0]
	adds r0, r6, 0
	adds r0, 0x2E
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0x9E
	movs r2, 0x60
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x9E
	movs r2, 0x70
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	orrs r0, r1
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r1, 0x9E
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x5E
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x7E
	movs r2, 0x80
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x6]
	adds r0, r5, 0
	movs r1, 0xAE
	movs r2, 0x80
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	orrs r0, r1
	strh r0, [r4, 0x6]
	ldr r0, =gUnknown_0862AA1C
	movs r1, 0xC6
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 8
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0862AA3C
	movs r1, 0xBE
	movs r2, 0x78
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x8]
	orrs r0, r1
	strh r0, [r4, 0x8]
	ldrh r1, [r4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartObjectImageAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	bl StartObjectImageAnim
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x3
	bl StartObjectImageAnim
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x4
	bl StartObjectImageAnim
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	bl StartObjectImageAnim
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x6
	bl StartObjectImageAnim
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x7
	bl StartObjectImageAnim
	ldrb r1, [r4, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x8
	bl StartObjectImageAnim
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D78BC

	thumb_func_start sub_81D7A60
sub_81D7A60: @ 81D7A60
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r3, r4, 0
	adds r3, 0x2E
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r3, 0xA]
	movs r1, 0x7
	ands r1, r0
	ldr r7, =gSprites
	cmp r1, 0
	bne _081D7B52
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x98
	beq _081D7B52
	adds r0, r1, 0x1
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r4, 0x2E]
	movs r2, 0xFF
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x2]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x4]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x6]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0x8]
	ands r2, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
_081D7B52:
	adds r6, r7, 0
	movs r5, 0xFF
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2B
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _081D7C24
	cmp r2, 0x1
	bgt _081D7B78
	cmp r2, 0
	beq _081D7B84
	b _081D7D0C
	.pool
_081D7B78:
	cmp r2, 0x2
	bne _081D7B7E
	b _081D7CAC
_081D7B7E:
	cmp r2, 0x3
	beq _081D7C24
	b _081D7D0C
_081D7B84:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x4]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x6]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	b _081D7D0A
_081D7C24:
	movs r2, 0x1
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrb r1, [r3, 0x8]
	b _081D7D02
_081D7CAC:
	strh r2, [r4, 0x26]
	ldrh r1, [r3]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r1, [r3, 0x8]
	ands r1, r5
_081D7D02:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
_081D7D0A:
	strh r2, [r0, 0x26]
_081D7D0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D7A60

	thumb_func_start sub_81D7D14
sub_81D7D14: @ 81D7D14
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	adds r0, r2
	mov r12, r0
	ldrh r1, [r2, 0x22]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r0, 0xA0
	bgt _081D7E08
	adds r0, r1, 0
	adds r0, 0x8
	strh r0, [r2, 0x22]
	ldr r3, =gSprites
	ldrh r1, [r2, 0x2E]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	ldrh r0, [r2, 0x2E]
	movs r2, 0xFF
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x2]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x2]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x4]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x4]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x6]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x6]
	adds r1, r2, 0
	ands r1, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r0, r12
	ldrh r1, [r0, 0x8]
	lsls r1, 16
	asrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	mov r1, r12
	ldrh r0, [r1, 0x8]
	ands r2, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
_081D7E08:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7D14

	thumb_func_start sub_81D7E10
sub_81D7E10: @ 81D7E10
	push {r4,lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AA54
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000804
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001004
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7E10

	thumb_func_start sub_81D7E9C
sub_81D7E9C: @ 81D7E9C
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08DA33C0
	movs r4, 0
	str r4, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DA4F70
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DA3C94
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D7ED0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D7ED0
	ldr r0, =gUnknown_08DA3988
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA60B8
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA4DEC
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA4DA8
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0862AA90
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AA98
	bl LoadCompressedObjectPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7E9C

	thumb_func_start sub_81D7F4C
sub_81D7F4C: @ 81D7F4C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	movs r0, 0xE8
	lsls r0, 1
	bl current_map_music_set
	bl sub_81D7E10
	bl sub_81D7E9C
	movs r1, 0x94
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000808
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	ldr r0, =sub_81D81A4
	movs r1, 0
	bl CreateTask
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81D7FC0
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D7F4C

	thumb_func_start sub_81D7FC0
sub_81D7FC0: @ 81D7FC0
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _081D802A
	cmp r5, 0x1
	bgt _081D7FE8
	cmp r5, 0
	beq _081D7FF4
	b _081D815A
	.pool
_081D7FE8:
	cmp r5, 0x2
	beq _081D80A4
	cmp r5, 0x3
	bne _081D7FF2
	b _081D8124
_081D7FF2:
	b _081D815A
_081D7FF4:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _081D8024
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x4]
	movs r0, 0x1E
	strh r0, [r4, 0x6]
	strh r5, [r4, 0x8]
	movs r0, 0x7
	strh r0, [r4, 0xA]
	strh r5, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D815A
_081D8024:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _081D815A
_081D802A:
	ldrh r1, [r4, 0x6]
	ldrh r3, [r4, 0x4]
	adds r0, r1, r3
	strh r0, [r4, 0x4]
	ldrh r2, [r4, 0xA]
	ldrh r3, [r4, 0x8]
	adds r0, r2, r3
	strh r0, [r4, 0x8]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081D8046
	subs r0, r1, 0x3
	strh r0, [r4, 0x6]
_081D8046:
	lsls r0, r2, 16
	cmp r0, 0
	beq _081D8050
	subs r0, r2, 0x1
	strh r0, [r4, 0xA]
_081D8050:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _081D8078
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r4, 0x4]
	movs r1, 0
	strh r1, [r4, 0x6]
	movs r0, 0xC
	strh r0, [r4, 0xC]
	movs r3, 0x1
	negs r3, r3
	adds r0, r3, 0
	strh r0, [r4, 0xE]
	strh r1, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081D8078:
	movs r1, 0xF0
	lsls r1, 7
	movs r2, 0xC0
	lsls r2, 5
	ldrh r0, [r4, 0x8]
	adds r0, 0x20
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x4]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r3, 0x78
	bl SetBgAffine
	b _081D815A
_081D80A4:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0xF0
	lsls r1, 7
	movs r2, 0xC0
	lsls r2, 5
	ldrh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 18
	adds r0, 0x20
	ldrh r3, [r4, 0x8]
	adds r0, r3
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x4]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x8]
	movs r5, 0
	str r5, [sp, 0xC]
	movs r0, 0x2
	movs r3, 0x78
	bl SetBgAffine
	ldrh r0, [r4, 0xE]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0xC
	beq _081D80F4
	movs r0, 0xC
	negs r0, r0
	cmp r1, r0
	bne _081D815A
_081D80F4:
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	negs r0, r0
	strh r0, [r4, 0xE]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	ldr r0, =0x00000127
	cmp r1, r0
	ble _081D815A
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0x6
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _081D815A
	.pool
_081D8124:
	ldrh r0, [r4, 0x4]
	adds r0, 0x10
	strh r0, [r4, 0x4]
	movs r1, 0xF0
	lsls r1, 7
	movs r2, 0xC0
	lsls r2, 5
	ldrh r0, [r4, 0x8]
	adds r0, 0x20
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x4]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r3, 0x78
	bl SetBgAffine
	adds r0, r6, 0
	bl sub_81D8164
_081D815A:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D7FC0

	thumb_func_start sub_81D8164
sub_81D8164: @ 81D8164
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D8192
	movs r0, 0
	bl SetVBlankCallback
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81D6840
	str r0, [r1]
_081D8192:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8164

	thumb_func_start sub_81D81A4
sub_81D81A4: @ 81D81A4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r1, [r4, 0x2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081D8254
	ldr r0, =gUnknown_0862AAA0
	ldr r3, =gUnknown_0862AAB8
	movs r1, 0
	ldrsh r2, [r4, r1]
	lsls r2, 1
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 18
	movs r6, 0xF0
	lsls r6, 15
	adds r1, r6
	asrs r1, 16
	adds r3, 0x1
	adds r2, r3
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	lsls r2, 18
	movs r3, 0xA0
	lsls r3, 15
	adds r2, r3
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r1
	movs r0, 0
	ldrsb r0, [r4, r0]
	strh r0, [r3, 0x2E]
	ldrb r2, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	movs r2, 0x3
	orrs r0, r2
	strb r0, [r3, 0x1]
	ldrb r0, [r3, 0x5]
	ands r1, r0
	movs r0, 0x8
	orrs r1, r0
	strb r1, [r3, 0x5]
	adds r0, r3, 0
	bl InitSpriteAffineAnim
	ldrh r1, [r4]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r0, 0x9
	bne _081D8250
	adds r0, r5, 0
	bl DestroyTask
	b _081D825A
	.pool
_081D8250:
	adds r0, r1, 0x1
	strh r0, [r4]
_081D8254:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
_081D825A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D81A4

	thumb_func_start sub_81D8260
sub_81D8260: @ 81D8260
	push {lr}
	adds r2, r0, 0
	movs r1, 0x30
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _081D8270
	strh r0, [r2, 0x24]
	b _081D829A
_081D8270:
	ldr r1, =gUnknown_0862AAB8
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r3, [r2, 0x24]
	adds r0, r3
	strh r0, [r2, 0x24]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	adds r0, r1
_081D829A:
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r2, 0x30]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8260

	thumb_func_start sub_81D82B0
sub_81D82B0: @ 81D82B0
	push {r4,lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AACC
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000804
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001004
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001804
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D82B0

	thumb_func_start sub_81D8358
sub_81D8358: @ 81D8358
	push {r4-r7,lr}
	sub sp, 0xC
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08DA7528
	movs r4, 0
	str r4, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DA69BC
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	add r7, sp, 0x8
_081D8380:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _081D8380
	ldr r0, =gUnknown_08DA7AAC
	ldr r5, =gUnknown_0203CF60
	ldr r1, [r5]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA7784
	ldr r1, [r5]
	ldr r4, =0x00001804
	adds r1, r4
	bl LZDecompressWram
	str r6, [sp, 0x4]
	ldr r1, [r5]
	ldr r0, =0x00001004
	adds r1, r0
	ldr r2, =0x01000200
	add r0, sp, 0x4
	bl CpuFastSet
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r0, =0x00000804
	adds r1, r0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r4, 0
	bl CpuFastSet
	str r6, [sp, 0x8]
	ldr r1, [r5]
	ldr r0, =0x00000904
	adds r1, r0
	ldr r2, =0x010000d0
	adds r0, r7, 0
	bl CpuFastSet
	ldr r0, =gUnknown_08DA7744
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	ldr r0, =gPlttBufferUnfaded
	ldr r1, =0x00007fff
	strh r1, [r0]
	ldr r0, =gPlttBufferFaded
	strh r1, [r0]
	ldr r0, =gUnknown_0862AAFC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AB04
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AB0C
	bl LoadCompressedObjectPalette
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8358

	thumb_func_start sub_81D844C
sub_81D844C: @ 81D844C
	push {r4,r5,lr}
	movs r0, 0x6
	bl GetGpuReg
	lsls r0, 16
	lsrs r2, r0, 16
	adds r1, r2, 0
	subs r1, 0x18
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x6F
	bhi _081D848C
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r3, =0x00002008
	adds r0, r3
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _081D848C
	ldr r1, =0x04000052
	ldr r3, =0x00000d08
	b _081D8492
	.pool
_081D848C:
	ldr r1, =0x04000052
	movs r3, 0x80
	lsls r3, 5
_081D8492:
	adds r0, r3, 0
	strh r0, [r1]
	cmp r2, 0
	bne _081D84E0
	ldr r0, =gUnknown_0203CF60
	ldr r1, [r0]
	ldr r2, =0x00002008
	adds r3, r1, r2
	ldrh r4, [r3]
	movs r1, 0
	ldrsh r2, [r3, r1]
	ldr r1, =0x00001fff
	adds r5, r0, 0
	cmp r2, r1
	bgt _081D84D4
	cmp r2, 0x27
	bgt _081D84C8
	adds r0, r4, 0x4
	b _081D84D2
	.pool
_081D84C8:
	cmp r2, 0x4F
	bgt _081D84D0
	adds r0, r4, 0x2
	b _081D84D2
_081D84D0:
	adds r0, r4, 0x1
_081D84D2:
	strh r0, [r3]
_081D84D4:
	ldr r1, [r5]
	ldr r2, =0x0000200a
	adds r1, r2
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_081D84E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D844C

	thumb_func_start sub_81D84EC
sub_81D84EC: @ 81D84EC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	bl sub_81D82B0
	bl sub_81D8358
	ldr r1, =0x00001e41
	movs r0, 0x50
	bl SetGpuRegBits
	movs r0, 0x80
	lsls r0, 5
	mov r8, r0
	movs r0, 0x52
	mov r1, r8
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	ldr r0, =gUnknown_0203CF60
	ldr r0, [r0]
	ldr r1, =0x00002008
	adds r2, r0, r1
	movs r1, 0
	strh r1, [r2]
	ldr r2, =0x0000200a
	adds r0, r2
	strh r1, [r0]
	strh r1, [r5]
	strh r1, [r5, 0x2]
	strh r1, [r5, 0x4]
	strh r1, [r5, 0x6]
	mov r0, r8
	strh r0, [r5, 0x8]
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_81D857C
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D84EC

	thumb_func_start sub_81D857C
sub_81D857C: @ 81D857C
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bhi _081D8674
	lsls r0, 2
	ldr r1, =_081D85A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D85A8:
	.4byte _081D85BC
	.4byte _081D85DC
	.4byte _081D861A
	.4byte _081D863A
	.4byte _081D8656
_081D85BC:
	ldrh r1, [r5, 0x2]
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x8
	bne _081D8634
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r4, [r5, 0x2]
	b _081D864E
_081D85DC:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081D8674
	ldrh r2, [r5, 0x2]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	cmp r0, 0xA
	bne _081D8614
	strh r1, [r5, 0x2]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	ldr r0, =sub_81D844C
	bl SetHBlankCallback
	movs r0, 0x3
	bl EnableInterrupts
	b _081D8674
	.pool
_081D8614:
	adds r0, r2, 0x1
	strh r0, [r5, 0x2]
	b _081D8674
_081D861A:
	ldrh r1, [r5, 0x2]
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x50
	bne _081D8634
	movs r0, 0
	strh r0, [r5, 0x2]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	bl sub_81D86CC
	b _081D8674
_081D8634:
	adds r0, r1, 0x1
	strh r0, [r5, 0x2]
	b _081D8674
_081D863A:
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
	lsls r0, 16
	movs r1, 0xB8
	lsls r1, 17
	cmp r0, r1
	bne _081D8674
	movs r0, 0
	strh r0, [r5, 0x2]
_081D864E:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _081D8674
_081D8656:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D8684
	str r1, [r0]
_081D8674:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D857C

	thumb_func_start sub_81D8684
sub_81D8684: @ 81D8684
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D86B8
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81D6840
	str r0, [r1]
_081D86B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8684

	thumb_func_start sub_81D86CC
sub_81D86CC: @ 81D86CC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0862AB14
	movs r1, 0xA0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r5, r6, 4
	adds r5, r6
	lsls r5, 2
	ldr r4, =gSprites + 0x2E
	adds r0, r5, r4
	mov r8, r0
	ldr r0, =gUnknown_0862AB2C
	movs r2, 0x30
	negs r2, r2
	movs r1, 0xB8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1]
	adds r3, r4, 0
	subs r3, 0x2E
	subs r4, 0x12
	adds r4, r5, r4
	ldr r0, =sub_81D874C
	str r0, [r4]
	adds r5, r3
	ldrb r0, [r5, 0x5]
	movs r2, 0xC
	orrs r0, r2
	strb r0, [r5, 0x5]
	movs r4, 0
	ldrsh r1, [r1, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x5]
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D86CC

	thumb_func_start sub_81D874C
sub_81D874C: @ 81D874C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081D8764
	movs r0, 0xC
	strh r0, [r4, 0x6]
	movs r0, 0x8
	b _081D87C2
_081D8764:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _081D8774
	movs r0, 0x9
	strh r0, [r4, 0x6]
	movs r0, 0x7
	b _081D87C2
_081D8774:
	movs r0, 0x86
	lsls r0, 1
	cmp r1, r0
	bne _081D8784
	movs r0, 0x8
	strh r0, [r4, 0x6]
	movs r0, 0x6
	b _081D87C2
_081D8784:
	movs r0, 0x8C
	lsls r0, 1
	cmp r1, r0
	bne _081D8794
	movs r0, 0x7
	strh r0, [r4, 0x6]
	movs r0, 0x5
	b _081D87C2
_081D8794:
	movs r0, 0x92
	lsls r0, 1
	cmp r1, r0
	bne _081D87A4
	movs r0, 0x6
	strh r0, [r4, 0x6]
	movs r0, 0x4
	b _081D87C2
_081D87A4:
	movs r0, 0x98
	lsls r0, 1
	cmp r1, r0
	bne _081D87B4
	movs r0, 0x5
	strh r0, [r4, 0x6]
	movs r0, 0x3
	b _081D87C2
_081D87B4:
	movs r0, 0xA0
	lsls r0, 1
	cmp r1, r0
	bne _081D87C4
	movs r0, 0x4
	strh r0, [r4, 0x6]
	movs r0, 0x2
_081D87C2:
	strh r0, [r4, 0x8]
_081D87C4:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _081D87EE
	ldrh r0, [r5, 0x24]
	subs r0, 0x1
	strh r0, [r5, 0x24]
	ldr r2, =gSprites
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	subs r1, 0x1
	strh r1, [r0, 0x24]
_081D87EE:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _081D8818
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	ldr r2, =gSprites
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x1
	strh r1, [r0, 0x26]
_081D8818:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D874C

	thumb_func_start sub_81D8828
sub_81D8828: @ 81D8828
	push {r4,lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AB44
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000804
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001004
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001804
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8828

	thumb_func_start sub_81D88D0
sub_81D88D0: @ 81D88D0
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08DA80BC
	movs r4, 0
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DA7EAC
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DA7C30
	str r4, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D8904:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D8904
	ldr r0, =gUnknown_08DA8D6C
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA8B40
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA7FB4
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA7D6C
	ldr r1, [r4]
	ldr r2, =0x00001804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DA8E84
	movs r1, 0
	movs r2, 0x80
	bl LoadCompressedPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D88D0

	thumb_func_start sub_81D8980
sub_81D8980: @ 81D8980
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	bl sub_81D8828
	bl sub_81D88D0
	bl sub_81D68C8
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	ldr r0, =sub_81D8AD8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x4]
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81D89E0
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8980

	thumb_func_start sub_81D89E0
sub_81D89E0: @ 81D89E0
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81D8BB4
	ldrh r1, [r4, 0x6]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _081D8A16
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bgt _081D8A16
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x59
	bgt _081D8A16
	movs r0, 0x67
	bl audio_play
_081D8A16:
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
	movs r0, 0
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _081D8A5C
	cmp r5, 0x1
	bgt _081D8A34
	cmp r5, 0
	beq _081D8A3E
	b _081D8AC6
	.pool
_081D8A34:
	cmp r5, 0x2
	beq _081D8A8C
	cmp r5, 0x3
	beq _081D8AA8
	b _081D8AC6
_081D8A3E:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _081D8AA2
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x2]
	b _081D8A9A
_081D8A5C:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x7F
	bne _081D8AA2
	movs r0, 0
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldr r2, =gTasks
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_81D8B2C
	b _081D8AC4
	.pool
_081D8A8C:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0xC
	bne _081D8AA2
	movs r0, 0
	strh r0, [r4, 0x2]
_081D8A9A:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D8AC6
_081D8AA2:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _081D8AC6
_081D8AA8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D8BEC
_081D8AC4:
	str r1, [r0]
_081D8AC6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D89E0

	thumb_func_start sub_81D8AD8
sub_81D8AD8: @ 81D8AD8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	ldrh r1, [r5, 0x1E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081D8B1C
	bl Random
	movs r4, 0x7
	adds r1, r4, 0
	ands r1, r0
	subs r1, 0x4
	lsls r1, 8
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgX
	bl Random
	ands r4, r0
	subs r4, 0x4
	lsls r4, 8
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgY
_081D8B1C:
	ldrh r0, [r5, 0x1E]
	adds r0, 0x1
	strh r0, [r5, 0x1E]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8AD8

	thumb_func_start sub_81D8B2C
sub_81D8B2C: @ 81D8B2C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D8B70
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0xA
	strh r0, [r4, 0x2]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _081D8BAA
	.pool
_081D8B70:
	cmp r0, 0x1
	bne _081D8BAC
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r1, 8
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgX
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r1, 8
	movs r0, 0x1
	movs r2, 0x1
	bl ChangeBgY
	ldrh r0, [r4, 0x4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA
	negs r1, r1
	cmp r0, r1
	bne _081D8BAC
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	negs r0, r0
_081D8BAA:
	strh r0, [r4, 0x4]
_081D8BAC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D8B2C

	thumb_func_start sub_81D8BB4
sub_81D8BB4: @ 81D8BB4
	push {r4,lr}
	movs r4, 0x80
	lsls r4, 3
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgX
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	movs r4, 0x80
	lsls r4, 4
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgX
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D8BB4

	thumb_func_start sub_81D8BEC
sub_81D8BEC: @ 81D8BEC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	bl sub_81D8BB4
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081D8C26
	movs r0, 0
	bl SetVBlankCallback
	bl sub_81D6904
	ldrb r0, [r4, 0x4]
	bl DestroyTask
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_81D6840
	str r1, [r0]
_081D8C26:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8BEC

	thumb_func_start sub_81D8C38
sub_81D8C38: @ 81D8C38
	push {r4,lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0862AD08
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000804
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001004
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8C38

	thumb_func_start sub_81D8CC4
sub_81D8CC4: @ 81D8CC4
	push {r4,lr}
	sub sp, 0x4
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08DAAB24
	movs r4, 0
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DAA8B4
	str r4, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081D8CEA:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D8CEA
	ldr r0, =gUnknown_08DAAE54
	ldr r4, =gUnknown_0203CF60
	ldr r1, [r4]
	ldr r2, =0x00000804
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DAAC1C
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r0, =gUnknown_08DAAF98
	ldr r1, [r4]
	ldr r2, =0x00001004
	adds r1, r2
	bl LZDecompressWram
	ldr r0, =gUnknown_08DAAFEC
	movs r1, 0
	movs r2, 0x60
	bl LoadCompressedPalette
	ldr r0, =gUnknown_0862AC28
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC30
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC38
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC40
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC48
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC50
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862AC58
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862AC60
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862AC68
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0862AC70
	bl LoadCompressedObjectPalette
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8CC4

	thumb_func_start sub_81D8DB4
sub_81D8DB4: @ 81D8DB4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	bl sub_81D8C38
	bl sub_81D8CC4
	bl sub_81D68C8
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl ClearGpuRegBits
	ldr r1, =0x00000241
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000e09
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81D67EC
	bl SetVBlankCallback
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81D8E80
	str r0, [r4]
	ldr r0, =sub_81D8FB0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x4]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0
	strh r2, [r0, 0x8]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0xA]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0xC]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0x1
	strh r2, [r0, 0xE]
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0x10]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8DB4

	thumb_func_start sub_81D8E80
sub_81D8E80: @ 81D8E80
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r4, r7, r0
	movs r1, 0
	ldrsh r5, [r4, r1]
	cmp r5, 0x1
	beq _081D8EDE
	cmp r5, 0x1
	bgt _081D8EB0
	cmp r5, 0
	beq _081D8EBA
	b _081D8FA0
	.pool
_081D8EB0:
	cmp r5, 0x2
	beq _081D8F1E
	cmp r5, 0x3
	beq _081D8F84
	b _081D8FA0
_081D8EBA:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _081D8F18
	adds r0, r6, 0
	bl sub_81D90A8
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	strh r5, [r4, 0x2]
	b _081D8F30
_081D8EDE:
	ldr r2, =gSprites
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =sub_81D97E0
	cmp r1, r0
	bne _081D8FA0
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x40
	bne _081D8F18
	adds r0, r6, 0
	bl sub_81D94D4
	adds r0, r6, 0
	bl sub_81D93D8
	b _081D8F2C
	.pool
_081D8F18:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _081D8FA0
_081D8F1E:
	ldrh r2, [r4, 0x2]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	bne _081D8F38
_081D8F2C:
	movs r0, 0
	strh r0, [r4, 0x2]
_081D8F30:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D8FA0
_081D8F38:
	adds r0, r2, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r1, 0x90
	bl __modsi3
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	bne _081D8FA0
	ldr r0, =0x0000fffe
	ldr r1, =0x0000ffff
	str r1, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	ldr r0, =0xffff0000
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A2C44
	b _081D8FA0
	.pool
_081D8F84:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_81D9034
	str r1, [r0]
_081D8FA0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8E80

	thumb_func_start sub_81D8FB0
sub_81D8FB0: @ 81D8FB0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _081D9024
	ldrh r1, [r4, 0x2]
	adds r1, 0xE
	lsls r1, 8
	movs r2, 0xF8
	lsls r2, 5
	adds r0, r2, 0
	ands r1, r0
	ldrh r0, [r4, 0x4]
	adds r0, 0x9
	movs r2, 0xF
	ands r0, r2
	orrs r1, r0
	movs r0, 0x52
	bl SetGpuReg
	ldrh r1, [r4, 0x2]
	ldrh r0, [r4, 0x6]
	subs r1, r0
	strh r1, [r4, 0x2]
	ldrh r0, [r4, 0x8]
	ldrh r2, [r4, 0x4]
	adds r0, r2
	strh r0, [r4, 0x4]
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	beq _081D9008
	cmp r1, 0
	bne _081D9010
_081D9008:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x6]
_081D9010:
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	beq _081D901C
	cmp r0, 0
	bne _081D9024
_081D901C:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x8]
_081D9024:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D8FB0

	thumb_func_start sub_81D9034
sub_81D9034: @ 81D9034
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r7, =gTasks + 0x8
	adds r4, r6, r7
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081D90A0
	bl sub_80A2F30
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D9078
	movs r0, 0
	bl SetVBlankCallback
	bl sub_81D6904
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	ldrb r0, [r4, 0x4]
	bl DestroyTask
_081D9078:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x20
	bne _081D909C
	strh r5, [r4, 0x2]
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81D6840
	str r1, [r0]
	b _081D90A0
	.pool
_081D909C:
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
_081D90A0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9034

	thumb_func_start sub_81D90A8
sub_81D90A8: @ 81D90A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gUnknown_0862AC78
	movs r1, 0x40
	movs r2, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x6]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites + 0x2E
	mov r10, r1
	adds r7, r0, r1
	ldr r0, =gUnknown_0862AC90
	movs r1, 0x10
	movs r2, 0x82
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	movs r2, 0x2E
	negs r2, r2
	add r2, r10
	mov r8, r2
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	movs r2, 0x4
	mov r9, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r5, =gUnknown_0862ACA8
	adds r0, r5, 0
	movs r1, 0xA0
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x8]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r7, r0, r1
	adds r0, r5, 0
	movs r1, 0xC0
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	adds r0, r5, 0
	movs r1, 0xE0
	movs r2, 0x80
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x2]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x1
	bl StartObjectImageAnim
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x2
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0862ACC0
	movs r2, 0x41
	negs r2, r2
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r7, r0, r1
	ldr r0, =gUnknown_0862ACD8
	movs r2, 0x71
	negs r2, r2
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	adds r0, r6, 0
	ands r0, r2
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r1, [r0, 0x5]
	ands r6, r1
	orrs r6, r2
	strb r6, [r0, 0x5]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D90A8

	thumb_func_start sub_81D9274
sub_81D9274: @ 81D9274
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldr r3, =gSprites
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	movs r1, 0x1C
	adds r1, r3
	mov r8, r1
	add r0, r8
	ldr r6, =pokemon_alive_on_battle_side
	str r6, [r0]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r4, 0
	strh r4, [r0, 0x36]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x38]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r5, 0x4
	strh r5, [r0, 0x3A]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x3C]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r6, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x36]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x38]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r5, [r0, 0x3A]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x1
	strh r1, [r0, 0x3C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9274

	thumb_func_start pokemon_alive_on_battle_side
pokemon_alive_on_battle_side: @ 81D9338
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x36]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _081D93CC
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D9370
	ldrh r0, [r4, 0x20]
	ldrh r3, [r4, 0x3A]
	subs r0, r3
	strh r0, [r4, 0x20]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, r3
	b _081D939E
	.pool
_081D9370:
	ldrh r2, [r4, 0x3A]
	ldrh r1, [r4, 0x20]
	adds r0, r2, r1
	strh r0, [r4, 0x20]
	ldr r3, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x20]
	adds r2, r1
	strh r2, [r0, 0x20]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r4, 0x3A]
	ldrh r2, [r0, 0x20]
	adds r1, r2
_081D939E:
	strh r1, [r0, 0x20]
	ldrh r1, [r4, 0x38]
	adds r1, 0x1
	movs r2, 0
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	subs r0, r1
	strh r0, [r4, 0x3A]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3
	bne _081D93CC
	strh r2, [r4, 0x36]
	strh r2, [r4, 0x38]
	strh r2, [r4, 0x3A]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	b _081D93D2
	.pool
_081D93CC:
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
_081D93D2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemon_alive_on_battle_side

	thumb_func_start sub_81D93D8
sub_81D93D8: @ 81D93D8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldr r3, =gSprites
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81D9420
	str r1, [r0]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x1
	bl StartObjectImageAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D93D8

	thumb_func_start sub_81D9420
sub_81D9420: @ 81D9420
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081D9488
	cmp r0, 0x1
	bgt _081D9436
	cmp r0, 0
	beq _081D9440
	b _081D94C4
_081D9436:
	cmp r0, 0x2
	beq _081D9440
	cmp r0, 0x3
	beq _081D9488
	b _081D94C4
_081D9440:
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0xC
	bl __umodsi3
	lsls r0, 24
	ldr r2, =gSprites
	cmp r0, 0
	bne _081D9470
	ldrh r0, [r4, 0x20]
	subs r0, 0x2
	strh r0, [r4, 0x20]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x2
	strh r1, [r0, 0x20]
_081D9470:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x26]
	b _081D94C4
	.pool
_081D9488:
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x26]
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	lsls r1, 26
	lsrs r1, 26
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _081D94C4
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x1
	strh r1, [r0, 0x22]
_081D94C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9420

	thumb_func_start sub_81D94D4
sub_81D94D4: @ 81D94D4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	movs r0, 0x8
	ldrsh r1, [r1, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r2, =gSprites + 0x2E
	adds r4, r0, r2
	subs r2, 0x12
	adds r0, r2
	ldr r3, =sub_81D9528
	str r3, [r0]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	str r3, [r0]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	str r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D94D4

	thumb_func_start sub_81D9528
sub_81D9528: @ 81D9528
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	ldrh r1, [r7, 0x36]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081D9550
	ldrh r1, [r7, 0x24]
	movs r2, 0x24
	ldrsh r0, [r7, r2]
	cmp r0, 0x1
	bne _081D954C
	ldr r0, =0x0000ffff
	b _081D954E
	.pool
_081D954C:
	movs r0, 0x1
_081D954E:
	strh r0, [r7, 0x24]
_081D9550:
	movs r1, 0x38
	ldrsh r0, [r7, r1]
	cmp r0, 0x80
	bne _081D95CE
	ldr r2, =gUnknown_0862ACF0
	mov r8, r2
	mov r0, r8
	movs r1, 0x98
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x3C]
	ldr r5, =gSprites
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	movs r6, 0x4
	orrs r0, r6
	strb r0, [r1, 0x5]
	mov r0, r8
	movs r1, 0xE0
	movs r2, 0x84
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x3C]
	movs r2, 0x3C
	ldrsh r1, [r7, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x5]
	ands r4, r1
	orrs r4, r6
	strb r4, [r0, 0x5]
	movs r0, 0x3C
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldrh r0, [r7, 0x38]
	adds r0, 0x1
	strh r0, [r7, 0x38]
_081D95CE:
	ldrh r1, [r7, 0x38]
	movs r2, 0x38
	ldrsh r0, [r7, r2]
	cmp r0, 0x7F
	ble _081D95F8
	movs r1, 0x26
	ldrsh r0, [r7, r1]
	cmp r0, 0x20
	beq _081D95FC
	ldrh r0, [r7, 0x3A]
	adds r0, 0x1
	strh r0, [r7, 0x3A]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r7, 0x26]
	b _081D95FC
	.pool
_081D95F8:
	adds r0, r1, 0x1
	strh r0, [r7, 0x38]
_081D95FC:
	ldrh r0, [r7, 0x36]
	movs r1, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _081D960C
	movs r0, 0xA5
	bl audio_play
_081D960C:
	ldrh r0, [r7, 0x36]
	adds r0, 0x1
	strh r0, [r7, 0x36]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9528

	thumb_func_start sub_81D961C
sub_81D961C: @ 81D961C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	cmp r1, 0x40
	bgt _081D968C
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	ldr r5, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	adds r1, 0x2
	strh r1, [r0, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	beq _081D964C
	b _081D979E
_081D964C:
	movs r3, 0x30
	negs r3, r3
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_81D9868
	movs r2, 0x5
	strh r2, [r4, 0x36]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x38]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x3
	strh r1, [r0, 0x36]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x38]
	b _081D979E
	.pool
_081D968C:
	cmp r1, 0x6F
	bgt _081D96BE
	adds r0, r4, 0
	bl sub_81D97E0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081D96A4
	movs r0, 0x68
	bl audio_play
_081D96A4:
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	bne _081D979E
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0x30
	movs r3, 0x10
	bl sub_81D9868
	b _081D979E
_081D96BE:
	cmp r1, 0x70
	bne _081D96EC
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x7
	strh r1, [r0, 0x36]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strh r1, [r0, 0x38]
	b _081D96F2
	.pool
_081D96EC:
	ldr r0, =0x00000147
	cmp r1, r0
	bgt _081D9700
_081D96F2:
	adds r0, r4, 0
	bl sub_81D97E0
	b _081D979E
	.pool
_081D9700:
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	bne _081D974C
	adds r0, r4, 0
	bl sub_81D97E0
	adds r0, r4, 0
	movs r1, 0x3
	movs r2, 0x30
	movs r3, 0x10
	bl sub_81D9868
	movs r3, 0x1
	strh r3, [r4, 0x24]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	movs r0, 0xCB
	lsls r0, 1
	movs r1, 0
	bl cry_related
	ldr r0, =sub_81D98B4
	movs r1, 0
	bl CreateTask
	b _081D979E
	.pool
_081D974C:
	movs r0, 0xB0
	lsls r0, 1
	cmp r1, r0
	beq _081D9790
	adds r0, 0x18
	cmp r1, r0
	bne _081D979E
	movs r3, 0
	strh r3, [r4, 0x24]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	adds r0, r4, 0
	bl sub_81D97E0
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0x30
	movs r3, 0x10
	bl sub_81D9868
	ldr r0, =sub_81D97E0
	str r0, [r4, 0x1C]
	b _081D97D2
	.pool
_081D9790:
	ldr r0, =sub_81D8E80
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl sub_81D9274
_081D979E:
	ldrh r2, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	ble _081D97CC
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _081D97CC
	movs r1, 0x24
	ldrsh r2, [r4, r1]
	negs r2, r2
	strh r2, [r4, 0x24]
	ldr r3, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x24]
_081D97CC:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
_081D97D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D961C

	thumb_func_start sub_81D97E0
sub_81D97E0: @ 81D97E0
	push {r4-r7,lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r4, r0, r5
	ldrh r1, [r3, 0x3A]
	ldrh r0, [r4, 0x36]
	ands r0, r1
	cmp r0, 0
	bne _081D985C
	ldrh r2, [r3, 0x36]
	ldrh r1, [r3, 0x26]
	adds r0, r2, r1
	strh r0, [r3, 0x26]
	movs r7, 0x2E
	ldrsh r1, [r3, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	adds r2, r1
	strh r2, [r0, 0x26]
	ldrh r0, [r3, 0x38]
	ldrh r2, [r3, 0x36]
	adds r0, r2
	strh r0, [r3, 0x36]
	lsls r0, 16
	asrs r5, r0, 16
	ldrh r6, [r4, 0x38]
	movs r7, 0x38
	ldrsh r2, [r4, r7]
	cmp r5, r2
	bge _081D9836
	movs r0, 0x36
	ldrsh r1, [r3, r0]
	adds r0, r2, 0
	cmn r1, r0
	bgt _081D985C
_081D9836:
	cmp r5, r2
	ble _081D9844
	strh r6, [r3, 0x36]
	b _081D9854
	.pool
_081D9844:
	movs r0, 0x36
	ldrsh r1, [r3, r0]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bge _081D9854
	negs r0, r6
	strh r0, [r3, 0x36]
_081D9854:
	movs r7, 0x38
	ldrsh r0, [r3, r7]
	negs r0, r0
	strh r0, [r3, 0x38]
_081D985C:
	ldrh r0, [r3, 0x3A]
	adds r0, 0x1
	strh r0, [r3, 0x3A]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D97E0

	thumb_func_start sub_81D9868
sub_81D9868: @ 81D9868
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r5, 24
	lsrs r5, 24
	movs r4, 0x2E
	ldrsh r1, [r0, r4]
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r1, =gSprites
	adds r4, r1
	lsls r2, 16
	asrs r2, 16
	ldrh r1, [r0, 0x20]
	adds r2, r1
	strh r2, [r4, 0x20]
	lsls r3, 16
	asrs r3, 16
	ldrh r1, [r0, 0x22]
	adds r3, r1
	strh r3, [r4, 0x22]
	ldrh r1, [r0, 0x24]
	strh r1, [r4, 0x24]
	ldrh r1, [r0, 0x26]
	strh r1, [r4, 0x26]
	adds r1, r5, 0
	bl StartObjectImageAnim
	adds r0, r4, 0
	adds r1, r5, 0
	bl StartObjectImageAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9868

	thumb_func_start sub_81D98B4
sub_81D98B4: @ 81D98B4
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _081D990C
	cmp r1, 0x1
	bgt _081D98DC
	cmp r1, 0
	beq _081D98E2
	b _081D99B4
	.pool
_081D98DC:
	cmp r1, 0x2
	beq _081D99A4
	b _081D99B4
_081D98E2:
	movs r2, 0x80
	lsls r2, 7
	movs r0, 0x40
	str r0, [sp]
	adds r0, 0xC0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0x2
	adds r1, r2, 0
	movs r3, 0x78
	bl SetBgAffine
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x10
	strh r0, [r4, 0x8]
	b _081D9922
_081D990C:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bne _081D991A
	movs r0, 0x12
	bl audio_play
_081D991A:
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0x2
	bne _081D992A
_081D9922:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081D99B4
_081D992A:
	ldrh r5, [r4, 0x8]
	ldrh r1, [r4, 0x2]
	adds r0, r5, r1
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D9954
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _081D9954
	subs r0, r5, 0x2
	strh r0, [r4, 0x8]
_081D9954:
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
	movs r2, 0x80
	lsls r2, 7
	movs r0, 0x40
	str r0, [sp]
	ldrh r0, [r4, 0x2]
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x4]
	ldrh r0, [r4, 0x2]
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	str r1, [sp, 0x8]
	movs r5, 0
	str r5, [sp, 0xC]
	movs r0, 0x2
	adds r1, r2, 0
	movs r3, 0x78
	bl SetBgAffine
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _081D99B4
	strh r5, [r4, 0x2]
	strh r5, [r4, 0x6]
	strh r5, [r4, 0xA]
	movs r0, 0x10
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	b _081D99B4
_081D99A4:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl ClearGpuRegBits
	adds r0, r5, 0
	bl DestroyTask
_081D99B4:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D98B4

	thumb_func_start sub_81D99BC
sub_81D99BC: @ 81D99BC
	push {r4,lr}
	bl sub_80D2578
	cmp r0, 0
	bne _081D99DC
	ldr r4, =gStringVar1
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0x1
	b _081D99DE
	.pool
_081D99DC:
	movs r0, 0
_081D99DE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D99BC

	thumb_func_start walda_maybe
walda_maybe: @ 81D99E4
	push {r4,lr}
	sub sp, 0x8
	ldr r4, =gStringVar2
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_81D9A1C
	str r0, [sp, 0x4]
	movs r0, 0x4
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl do_choose_name_or_words_screen
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end walda_maybe

	thumb_func_start sub_81D9A1C
sub_81D9A1C: @ 81D9A1C
	push {r4,r5,lr}
	ldr r4, =gUnknown_020375E0
	ldr r5, =gStringVar2
	adds r0, r5, 0
	bl sub_81D9A98
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _081D9A68
	cmp r0, 0x1
	bgt _081D9A44
	cmp r0, 0
	beq _081D9A62
	b _081D9A68
	.pool
_081D9A44:
	cmp r0, 0x2
	bne _081D9A68
	bl sub_80D2578
	cmp r0, 0
	beq _081D9A5C
	ldr r0, =gUnknown_085EE49A
	bl sub_80D255C
	b _081D9A68
	.pool
_081D9A5C:
	movs r0, 0x1
	strh r0, [r4]
	b _081D9A68
_081D9A62:
	adds r0, r5, 0
	bl sub_80D255C
_081D9A68:
	ldr r4, =gStringVar1
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF168
	str r0, [r1]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9A1C

	thumb_func_start sub_81D9A98
sub_81D9A98: @ 81D9A98
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081D9AA6
	movs r0, 0x2
	b _081D9ABC
_081D9AA6:
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCompare
	cmp r0, 0
	beq _081D9ABA
	movs r0, 0
	b _081D9ABC
_081D9ABA:
	movs r0, 0x1
_081D9ABC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9A98

	thumb_func_start sub_81D9AC4
sub_81D9AC4: @ 81D9AC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xA
	bl sub_80842DC
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_020375F0
	mov r8, r0
	bl sub_80D2548
	mov r7, sp
	adds r7, 0xA
	add r6, sp, 0xC
	mov r5, sp
	adds r5, 0xD
	str r4, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_81D9B68
	mov r1, r8
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _081D9B1E
	ldrb r0, [r5]
	bl sub_80D24BC
	ldrb r0, [r6]
	bl sub_80D24F0
	add r0, sp, 0x8
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl sub_80D2524
_081D9B1E:
	mov r1, r8
	ldrh r0, [r1]
	bl sub_80D2480
	mov r1, r8
	ldrb r0, [r1]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D9AC4

	thumb_func_start sub_81D9B40
sub_81D9B40: @ 81D9B40
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_0862AD14
_081D9B4A:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081D9B5C
	lsls r0, r1, 24
	lsrs r0, 24
	b _081D9B64
	.pool
_081D9B5C:
	adds r1, 0x1
	cmp r1, 0x1F
	bls _081D9B4A
	movs r0, 0x20
_081D9B64:
	pop {r1}
	bx r1
	thumb_func_end sub_81D9B40

	thumb_func_start sub_81D9B68
sub_81D9B68: @ 81D9B68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r10, r0
	str r1, [sp, 0x20]
	str r2, [sp, 0x24]
	str r3, [sp, 0x28]
	ldr r0, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	adds r0, r5, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bne _081D9C7E
	movs r4, 0
	add r7, sp, 0x10
_081D9B98:
	adds r0, r5, r4
	ldrb r0, [r0]
	bl sub_81D9B40
	adds r1, r7, r4
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x20
	beq _081D9C7E
	adds r4, 0x1
	cmp r4, 0xE
	ble _081D9B98
	movs r6, 0x3
	movs r5, 0
	movs r0, 0x5
	mov r8, r0
	movs r4, 0xD
_081D9BBC:
	mov r1, r8
	str r1, [sp]
	add r0, sp, 0x4
	adds r1, r7, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_81D9D5C
	adds r6, 0x8
	adds r5, 0x5
	subs r4, 0x1
	cmp r4, 0
	bge _081D9BBC
	movs r0, 0x2
	str r0, [sp]
	add r0, sp, 0x4
	adds r1, r7, 0
	movs r2, 0x46
	movs r3, 0x73
	bl sub_81D9D5C
	add r0, sp, 0x4
	movs r1, 0
	movs r2, 0x3
	bl sub_81D9DAC
	adds r4, r0, 0
	adds r0, r7, 0
	movs r1, 0x75
	movs r2, 0x3
	bl sub_81D9DAC
	cmp r4, r0
	bne _081D9C7E
	add r0, sp, 0x4
	movs r1, 0x9
	movs r2, 0x15
	bl sub_81D9C90
	add r0, sp, 0x4
	ldrb r0, [r0, 0x8]
	movs r2, 0xF
	ands r2, r0
	add r0, sp, 0x4
	movs r1, 0x8
	bl sub_81D9C90
	add r0, sp, 0x4
	ldrb r2, [r0, 0x8]
	lsrs r2, 4
	movs r1, 0x8
	bl sub_81D9CDC
	add r0, sp, 0x4
	ldrb r2, [r0, 0x6]
	adds r1, r0, 0
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	eors r0, r1
	add r1, sp, 0x4
	ldrb r4, [r1, 0x4]
	eors r0, r4
	mov r3, r9
	lsrs r1, r3, 8
	eors r0, r1
	cmp r2, r0
	bne _081D9C7E
	add r0, sp, 0x4
	ldrb r3, [r0, 0x7]
	adds r2, r0, 0
	ldrb r1, [r0, 0x1]
	ldrb r0, [r2, 0x3]
	eors r1, r0
	adds r0, r2, 0
	ldrb r2, [r0, 0x5]
	eors r1, r2
	movs r0, 0xFF
	mov r5, r9
	ands r0, r5
	eors r1, r0
	cmp r3, r1
	bne _081D9C7E
	add r0, sp, 0x4
	ldrh r0, [r0]
	mov r1, r10
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6
	ldrh r0, [r0]
	ldr r3, [sp, 0x20]
	strh r0, [r3]
	ldr r5, [sp, 0x24]
	strb r4, [r5]
	ldr r0, [sp, 0x28]
	strb r2, [r0]
	movs r0, 0x1
	b _081D9C80
_081D9C7E:
	movs r0, 0
_081D9C80:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9B68

	thumb_func_start sub_81D9C90
sub_81D9C90: @ 81D9C90
	push {r4-r7,lr}
	adds r7, r0, 0
	mov r12, r1
	subs r3, r2, 0x1
	cmp r2, 0
	beq _081D9CD6
_081D9C9C:
	ldrb r1, [r7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 31
	mov r2, r12
	subs r2, 0x1
	subs r5, r3, 0x1
	cmp r2, 0
	blt _081D9CCC
	movs r6, 0x80
	adds r3, r2, r7
_081D9CB4:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	lsls r0, 24
	lsls r1, 1
	orrs r4, r1
	strb r4, [r3]
	lsrs r4, r0, 31
	subs r3, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _081D9CB4
_081D9CCC:
	adds r3, r5, 0
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	bne _081D9C9C
_081D9CD6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9C90

	thumb_func_start sub_81D9CDC
sub_81D9CDC: @ 81D9CDC
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r3, r2, 24
	lsls r0, r3, 4
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _081D9D04
_081D9CF4:
	adds r2, r6, r4
	ldrb r1, [r2]
	adds r0, r3, 0
	eors r0, r1
	strb r0, [r2]
	adds r4, 0x1
	cmp r4, r5
	bcc _081D9CF4
_081D9D04:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9CDC

	thumb_func_start sub_81D9D0C
sub_81D9D0C: @ 81D9D0C
	push {lr}
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	adds r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _081D9D24
	movs r0, 0x1
_081D9D24:
	pop {r1}
	bx r1
	thumb_func_end sub_81D9D0C

	thumb_func_start sub_81D9D28
sub_81D9D28: @ 81D9D28
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	lsls r1, 24
	lsrs r1, 24
	adds r0, r3
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_81D9D28

	thumb_func_start sub_81D9D40
sub_81D9D40: @ 81D9D40
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	mvns r1, r1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r3
	ldrb r2, [r0]
	ands r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_81D9D40

	thumb_func_start sub_81D9D5C
sub_81D9D5C: @ 81D9D5C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r1
	adds r1, r2, 0
	mov r8, r3
	ldr r7, [sp, 0x1C]
	movs r5, 0
	cmp r5, r7
	bcs _081D9DA0
	adds r4, r1, 0
_081D9D76:
	mov r0, r8
	adds r1, r0, r5
	mov r0, r9
	bl sub_81D9D0C
	lsls r0, 24
	cmp r0, 0
	beq _081D9D90
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D9D28
	b _081D9D98
_081D9D90:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D9D40
_081D9D98:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, r7
	bcc _081D9D76
_081D9DA0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9D5C

	thumb_func_start sub_81D9DAC
sub_81D9DAC: @ 81D9DAC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r4, 0
	movs r5, 0
	cmp r4, r6
	bcs _081D9DD6
_081D9DC0:
	lsls r4, 1
	adds r1, r7, r5
	mov r0, r8
	bl sub_81D9D0C
	lsls r0, 24
	lsrs r0, 24
	orrs r4, r0
	adds r5, 0x1
	cmp r5, r6
	bcc _081D9DC0
_081D9DD6:
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9DAC

	thumb_func_start sub_81D9DE4
sub_81D9DE4: @ 81D9DE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bhi _081D9EA4
	lsls r0, 2
	ldr r1, =_081D9E10
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D9E10:
	.4byte _081D9E24
	.4byte _081D9E44
	.4byte _081D9E64
	.4byte _081D9E84
	.4byte _081D9EA4
_081D9E24:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _081D9EB4
	.pool
_081D9E44:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _081D9EB4
	.pool
_081D9E64:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _081D9EB4
	.pool
_081D9E84:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _081D9EB4
	.pool
_081D9EA4:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_081D9EB4:
	bl GetMonData
	strb r0, [r4]
	ldr r5, =gUnknown_02039E00
	ldr r4, =gUnknown_02039F25
	ldrb r0, [r4]
	lsls r0, 6
	adds r0, r5
	ldr r1, =gUnknown_02039F31
	ldrb r1, [r1]
	adds r0, 0x2C
	strb r1, [r0]
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	lsrs r0, 31
	ldrb r1, [r4]
	lsls r1, 6
	adds r1, r5
	adds r1, 0x2D
	strb r0, [r1]
	ldr r1, =sub_81DA160
	ldr r2, =sub_81D9F14
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9DE4

	thumb_func_start sub_81D9F14
sub_81D9F14: @ 81D9F14
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_81DA244
	ldr r2, =sub_81D9F30
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F14

	thumb_func_start sub_81D9F30
sub_81D9F30: @ 81D9F30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_81DA2E8
	ldr r2, =sub_81D9F4C
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F30

	thumb_func_start sub_81D9F4C
sub_81D9F4C: @ 81D9F4C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_81DA3B8
	ldr r2, =sub_81D9F68
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F4C

	thumb_func_start sub_81D9F68
sub_81D9F68: @ 81D9F68
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r3, 0
	ldr r5, =gUnknown_02039F30
	mov r8, r5
	ldr r0, =gUnknown_020375E0
	mov r12, r0
	add r1, sp, 0x4
	mov r9, r1
	ldrb r4, [r5]
	cmp r3, r4
	bcs _081D9FB2
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 3
	ldr r7, =gTasks + 0x8
_081D9F98:
	mov r0, sp
	adds r2, r0, r3
	adds r1, r3, 0x1
	lsls r0, r1, 1
	adds r0, r4
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r3, r1, 24
	ldrb r1, [r5]
	cmp r3, r1
	bcc _081D9F98
_081D9FB2:
	movs r3, 0
	mov r4, r8
	ldrb r0, [r4]
	cmp r3, r0
	bcs _081D9FD6
	adds r4, r0, 0
	mov r2, sp
_081D9FC0:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcs _081D9FD6
	mov r7, sp
	adds r1, r7, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081D9FC0
_081D9FD6:
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bne _081D9FF4
	movs r0, 0
	mov r1, r12
	strh r0, [r1]
	b _081D9FFA
	.pool
_081D9FF4:
	movs r0, 0x1
	mov r4, r12
	strh r0, [r4]
_081D9FFA:
	movs r3, 0
	mov r7, r8
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bcs _081DA02A
	mov r4, r9
	lsls r0, r6, 2
	adds r0, r6
	lsls r2, r0, 3
	ldr r5, =gTasks + 0x8
_081DA010:
	adds r1, r4, r3
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r2
	adds r0, r5
	ldrh r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r7]
	cmp r3, r1
	bcc _081DA010
_081DA02A:
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, 0x4
	beq _081DA0B8
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _081DA0B8
	ldr r0, =gUnknown_02039E00
	adds r1, r0, 0
	adds r1, 0x2C
	ldrb r2, [r1]
	movs r3, 0x1
	ldrb r1, [r4]
	adds r5, r0, 0
	cmp r3, r1
	bcs _081DA06C
	adds r4, r5, 0
	mov r7, r8
	ldrb r1, [r7]
_081DA054:
	lsls r0, r3, 6
	adds r0, r4
	adds r0, 0x2C
	ldrb r7, [r0]
	cmp r2, r7
	bcs _081DA062
	ldrb r2, [r0]
_081DA062:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r1
	bcc _081DA054
_081DA06C:
	cmp r2, 0
	beq _081DA076
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_081DA076:
	movs r4, 0x1
	movs r3, 0
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bcs _081DA0AC
	adds r0, r5, 0
	b _081DA0A2
	.pool
_081DA090:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	mov r1, r8
	ldrb r1, [r1]
	cmp r3, r1
	bcs _081DA0AC
	lsls r0, r3, 6
	adds r0, r5
_081DA0A2:
	adds r0, 0x2D
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA090
	movs r4, 0
_081DA0AC:
	mov r0, sp
	ldrb r0, [r0]
	adds r1, r2, 0
	adds r2, r4, 0
	bl sub_80DACBC
_081DA0B8:
	mov r0, r9
	bl sub_80F86E0
	ldr r1, =gUnknown_02039F2B
	strb r0, [r1]
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r0, 0x3
	bhi _081DA0E8
	ldr r1, =sub_81DA488
	ldr r2, =sub_81DA10C
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	b _081DA0F6
	.pool
_081DA0E8:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81DA10C
	str r0, [r1]
_081DA0F6:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F68

	thumb_func_start sub_81DA10C
sub_81DA10C: @ 81DA10C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02039F2C
	ldrb r0, [r0]
	bl sub_80DB09C
	ldr r1, =sub_80FCF40
	ldr r2, =sub_81DA138
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA10C

	thumb_func_start sub_81DA138
sub_81DA138: @ 81DA138
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_80DCE58
	ldr r1, =sub_80FCFD0
	ldr r2, =sub_80F8714
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA138

	thumb_func_start sub_81DA160
sub_81DA160: @ 81DA160
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r6, r7, 2
	adds r0, r6, r7
	lsls r4, r0, 3
	ldr r5, =gTasks + 0x8
	adds r0, r4, r5
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA224
	adds r0, r5, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA1A4
	cmp r0, 0x1
	beq _081DA1D4
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
	b _081DA224
	.pool
_081DA1A4:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA224
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	lsls r0, 6
	ldr r1, =gUnknown_02039E00
	adds r0, r1
	movs r1, 0x40
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA224
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA224
	.pool
_081DA1D4:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _081DA224
	movs r5, 0
	ldr r0, =gUnknown_02039F30
	mov r8, r6
	ldrb r0, [r0]
	cmp r5, r0
	bge _081DA214
	ldr r6, =gUnknown_020229E8
_081DA1EC:
	lsls r4, r5, 6
	ldr r0, =gUnknown_02039E00
	adds r4, r0
	lsls r1, r5, 8
	ldr r0, =gUnknown_020223C4
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x40
	bl memcpy
	ldrh r1, [r6, 0x1A]
	adds r0, r4, 0
	bl sub_80DFA08
	adds r6, 0x1C
	adds r5, 0x1
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r5, r0
	blt _081DA1EC
_081DA214:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA224:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA160

	thumb_func_start sub_81DA244
sub_81DA244: @ 81DA244
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r5, r0, 3
	ldr r6, =gTasks + 0x8
	adds r0, r5, r6
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA2D4
	adds r0, r6, 0
	subs r0, 0x8
	adds r5, r0
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _081DA284
	cmp r0, 0x1
	beq _081DA2AC
	movs r0, 0
	strh r0, [r5, 0x8]
	strh r0, [r5, 0x20]
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
	b _081DA2D4
	.pool
_081DA284:
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _081DA2CE
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA2D4
	ldr r0, =gRngValue
	movs r1, 0x4
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA2D4
	b _081DA2CE
	.pool
_081DA2AC:
	movs r0, 0
	bl sub_80FC530
	lsls r0, 24
	cmp r0, 0
	beq _081DA2D4
	ldr r0, =gRngValue
	ldr r4, =gUnknown_020223C4
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
	ldr r0, =gUnknown_030060B8
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
_081DA2CE:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_081DA2D4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA244

	thumb_func_start sub_81DA2E8
sub_81DA2E8: @ 81DA2E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	mov r9, r0
	adds r0, r6
	lsls r5, r0, 3
	ldr r1, =gTasks + 0x8
	mov r8, r1
	adds r0, r5, r1
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA39E
	movs r0, 0x8
	negs r0, r0
	add r0, r8
	mov r10, r0
	adds r4, r5, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA338
	cmp r0, 0x1
	beq _081DA35A
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _081DA39E
	.pool
_081DA338:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA39E
	add r0, sp, 0x8
	movs r1, 0x6E
	strh r1, [r0]
	movs r1, 0x2
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA39E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA39E
_081DA35A:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _081DA39E
	movs r1, 0
	ldr r7, =gUnknown_02039F30
	ldrb r0, [r7]
	cmp r1, r0
	bge _081DA390
	mov r0, r8
	adds r0, 0xA
	adds r3, r5, r0
	ldr r4, =gUnknown_020223C4
	mov r2, sp
	movs r5, 0x80
	lsls r5, 1
_081DA37C:
	ldrh r0, [r4]
	strh r0, [r2]
	strh r0, [r3]
	adds r3, 0x2
	adds r4, r5
	adds r2, 0x2
	adds r1, 0x1
	ldrb r0, [r7]
	cmp r1, r0
	blt _081DA37C
_081DA390:
	mov r0, r9
	adds r1, r0, r6
	lsls r1, 3
	add r1, r10
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA39E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA2E8

	thumb_func_start sub_81DA3B8
sub_81DA3B8: @ 81DA3B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	mov r9, r0
	adds r0, r6
	lsls r5, r0, 3
	ldr r1, =gTasks + 0x8
	mov r8, r1
	adds r0, r5, r1
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA46E
	movs r0, 0x8
	negs r0, r0
	add r0, r8
	mov r10, r0
	adds r4, r5, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA408
	cmp r0, 0x1
	beq _081DA42A
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _081DA46E
	.pool
_081DA408:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA46E
	ldrh r1, [r4, 0x1A]
	add r0, sp, 0x8
	strh r1, [r0]
	movs r1, 0x2
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA46E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA46E
_081DA42A:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _081DA46E
	movs r1, 0
	ldr r7, =gUnknown_02039F30
	ldrb r0, [r7]
	cmp r1, r0
	bge _081DA460
	mov r0, r8
	adds r0, 0x2
	adds r3, r5, r0
	ldr r4, =gUnknown_020223C4
	mov r2, sp
	movs r5, 0x80
	lsls r5, 1
_081DA44C:
	ldrh r0, [r4]
	strh r0, [r2]
	strh r0, [r3]
	adds r3, 0x2
	adds r4, r5
	adds r2, 0x2
	adds r1, 0x1
	ldrb r0, [r7]
	cmp r1, r0
	blt _081DA44C
_081DA460:
	mov r0, r9
	adds r1, r0, r6
	lsls r1, 3
	add r1, r10
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA46E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA3B8

	thumb_func_start sub_81DA488
sub_81DA488: @ 81DA488
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r7, r6, 2
	adds r0, r7, r6
	lsls r4, r0, 3
	ldr r5, =gTasks + 0x8
	adds r0, r4, r5
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA55C
	adds r0, r5, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA4CC
	cmp r0, 0x1
	beq _081DA50C
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _081DA55C
	.pool
_081DA4CC:
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _081DA4FA
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA55C
	ldr r0, =gUnknown_02039F30
	ldrb r2, [r0]
	lsls r0, r2, 6
	ldr r1, =gUnknown_02039E00
	adds r0, r1
	movs r1, 0x4
	subs r1, r2
	lsls r1, 22
	lsrs r1, 16
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA55C
_081DA4FA:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA55C
	.pool
_081DA50C:
	movs r0, 0
	bl sub_80FC530
	lsls r0, 24
	cmp r0, 0
	beq _081DA55C
	ldr r4, =gUnknown_02039F30
	ldrb r3, [r4]
	lsls r0, r3, 6
	ldr r5, =gUnknown_02039E00
	adds r0, r5
	ldr r1, =gUnknown_020223C4
	movs r2, 0x4
	subs r2, r3
	lsls r2, 6
	bl memcpy
	ldrb r4, [r4]
	mov r8, r7
	cmp r4, 0x3
	bgt _081DA54C
	lsls r0, r4, 6
	adds r5, r0, r5
	ldr r7, =gUnknown_020229E8
_081DA53C:
	ldrh r1, [r7, 0x1A]
	adds r0, r5, 0
	bl sub_80DFA08
	adds r5, 0x40
	adds r4, 0x1
	cmp r4, 0x3
	ble _081DA53C
_081DA54C:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA55C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA488

	thumb_func_start sub_81DA57C
sub_81DA57C: @ 81DA57C
	push {lr}
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081DA5CA
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bhi _081DA5CA
	movs r0, 0x5B
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081DA5C0
	ldr r0, =gUnknown_0862AD34
	movs r1, 0x8
	movs r2, 0x5
	bl sub_81DA5D4
	b _081DA5CA
	.pool
_081DA5C0:
	ldr r0, =gUnknown_0862AD44
	movs r1, 0x7
	movs r2, 0x1
	bl sub_81DA5D4
_081DA5CA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA57C

	thumb_func_start sub_81DA5D4
sub_81DA5D4: @ 81DA5D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	adds r7, r1, 0
	mov r10, r2
	movs r6, 0
	movs r0, 0x5
	mov r8, r0
	movs r5, 0
	cmp r5, r7
	bcs _081DA61C
	mov r4, r9
_081DA5F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r4]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA614
	adds r0, r1, 0
	bl sub_81DA6CC
	cmp r8, r0
	ble _081DA612
	mov r8, r0
_081DA612:
	adds r6, 0x1
_081DA614:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	bcc _081DA5F4
_081DA61C:
	cmp r6, 0
	beq _081DA6BA
	cmp r8, r10
	bhi _081DA6BA
	movs r6, 0
	movs r5, 0
	cmp r5, r7
	bcs _081DA654
	mov r4, r9
_081DA62E:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r4]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA64C
	adds r0, r1, 0
	bl sub_81DA6CC
	cmp r0, r8
	bne _081DA64C
	adds r6, 0x1
_081DA64C:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	bcc _081DA62E
_081DA654:
	cmp r6, 0
	beq _081DA6BA
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	adds r6, r0, 0
	movs r5, 0
	cmp r5, r7
	bcs _081DA6BA
	ldr r2, =gSaveBlock1Ptr
	ldr r3, =0x000009ca
	mov r4, r9
_081DA674:
	ldr r0, [r2]
	ldrh r1, [r4]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA6B2
	adds r0, r1, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	bl sub_81DA6CC
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r0, r8
	bne _081DA6B2
	cmp r6, 0
	bne _081DA6B0
	ldr r0, [r2]
	adds r0, r3
	ldrh r4, [r4]
	adds r0, r4
	mov r1, r8
	strb r1, [r0]
	b _081DA6BA
	.pool
_081DA6B0:
	subs r6, 0x1
_081DA6B2:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	bcc _081DA674
_081DA6BA:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81DA5D4

	thumb_func_start sub_81DA6CC
sub_81DA6CC: @ 81DA6CC
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gUnknown_085500A4
_081DA6D4:
	lsls r0, r4, 1
	lsls r1, r5, 4
	adds r0, r1
	adds r0, r6
	ldrh r0, [r0]
	bl trainer_flag_check
	lsls r0, 24
	cmp r0, 0
	bne _081DA6F0
	adds r0, r4, 0
	b _081DA6F8
	.pool
_081DA6F0:
	adds r4, 0x1
	cmp r4, 0x4
	ble _081DA6D4
	movs r0, 0x5
_081DA6F8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DA6CC

	thumb_func_start sub_81DA700
sub_81DA700: @ 81DA700
	push {lr}
	sub sp, 0x8
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_0862AD54
	ldr r1, [sp, 0x4]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_0862AF30
	ldr r1, [sp]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_0862B53C
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0862B724
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862B72C
	bl LoadTaggedObjectPalette
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA700

	thumb_func_start sub_81DA74C
sub_81DA74C: @ 81DA74C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x24]
	ldr r1, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r4, 24
	lsrs r7, r4, 24
	ldr r0, =gUnknown_0862B758
	lsls r5, 16
	asrs r5, 16
	lsls r6, 16
	asrs r6, 16
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r7, 0x1
	beq _081DA7D0
	cmp r7, 0x1
	bgt _081DA7A8
	cmp r7, 0
	beq _081DA7B8
	b _081DA7AC
	.pool
_081DA7A8:
	cmp r7, 0x2
	beq _081DA7E4
_081DA7AC:
	ldr r6, =gSprites
	lsls r3, r5, 4
	b _081DA7F8
	.pool
_081DA7B8:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x78
	strh r1, [r0, 0x2E]
	movs r1, 0x2D
	b _081DA7F4
	.pool
_081DA7D0:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x59
	b _081DA7F0
	.pool
_081DA7E4:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x97
_081DA7F0:
	strh r1, [r0, 0x2E]
	movs r1, 0x61
_081DA7F4:
	strh r1, [r0, 0x30]
	adds r6, r2, 0
_081DA7F8:
	adds r4, r3, r5
	lsls r4, 2
	adds r0, r4, r6
	mov r2, r8
	lsls r1, r2, 24
	asrs r1, 24
	movs r2, 0
	strh r1, [r0, 0x32]
	mov r3, r9
	lsls r1, r3, 24
	asrs r1, 24
	strh r1, [r0, 0x34]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x3A]
	mov r3, r10
	strh r3, [r0, 0x3C]
	strh r2, [r0, 0x36]
	strh r2, [r0, 0x38]
	adds r1, r7, 0
	bl StartObjectImageAnim
	adds r0, r6, 0
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_81DA848
	str r0, [r4]
	adds r0, r5, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DA74C

	thumb_func_start sub_81DA848
sub_81DA848: @ 81DA848
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r2, r3, 0
	adds r2, 0x2E
	movs r0, 0x20
	ldrsh r1, [r3, r0]
	movs r4, 0x2E
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bne _081DA874
	movs r5, 0x22
	ldrsh r1, [r3, r5]
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bne _081DA874
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
	b _081DA8B4
	.pool
_081DA874:
	ldrh r4, [r2, 0x8]
	movs r5, 0x8
	ldrsh r1, [r2, r5]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _081DA890
	ldrh r0, [r2, 0x4]
	ldrh r1, [r3, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r3, 0x20]
	strh r1, [r2, 0x8]
	b _081DA894
_081DA890:
	adds r0, r4, 0x1
	strh r0, [r2, 0x8]
_081DA894:
	ldrh r4, [r2, 0xA]
	movs r5, 0xA
	ldrsh r1, [r2, r5]
	movs r5, 0xE
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _081DA8B0
	ldrh r0, [r2, 0x6]
	ldrh r1, [r3, 0x22]
	adds r0, r1
	movs r1, 0
	strh r0, [r3, 0x22]
	strh r1, [r2, 0xA]
	b _081DA8B4
_081DA8B0:
	adds r0, r4, 0x1
	strh r0, [r2, 0xA]
_081DA8B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81DA848

	thumb_func_start sub_81DA8BC
sub_81DA8BC: @ 81DA8BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r1
	ldr r0, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r7, r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0862B758
	lsls r6, 16
	asrs r6, 16
	mov r1, r8
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	adds r1, r6, 0
	mov r2, r8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r5, 0x1
	beq _081DA94C
	cmp r5, 0x1
	bgt _081DA924
	cmp r5, 0
	beq _081DA934
	b _081DA928
	.pool
_081DA924:
	cmp r5, 0x2
	beq _081DA960
_081DA928:
	ldr r2, =gSprites
	lsls r3, r6, 4
	b _081DA972
	.pool
_081DA934:
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0x78
	strh r1, [r0, 0x2E]
	movs r1, 0x2D
	b _081DA970
	.pool
_081DA94C:
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0x59
	b _081DA96C
	.pool
_081DA960:
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0x97
_081DA96C:
	strh r1, [r0, 0x2E]
	movs r1, 0x61
_081DA970:
	strh r1, [r0, 0x30]
_081DA972:
	adds r4, r3, r6
	lsls r4, 2
	adds r0, r4, r2
	mov r3, sp
	ldrh r3, [r3]
	strh r3, [r0, 0x32]
	mov r1, sp
	ldrh r1, [r1, 0x4]
	strh r1, [r0, 0x34]
	mov r3, r10
	strh r3, [r0, 0x36]
	mov r1, r9
	strh r1, [r0, 0x38]
	strh r7, [r0, 0x3A]
	adds r1, r5, 0
	str r2, [sp, 0x8]
	bl StartObjectImageAnim
	ldr r2, [sp, 0x8]
	adds r0, r2, 0
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_81DA9BC
	str r0, [r4]
	adds r0, r6, 0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DA8BC

	thumb_func_start sub_81DA9BC
sub_81DA9BC: @ 81DA9BC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	muls r0, r1
	asrs r0, 12
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r4, r3]
	muls r0, r1
	asrs r0, 12
	strh r0, [r4, 0x26]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0xB4
	lsls r1, 1
	bl __modsi3
	strh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	movs r3, 0x36
	ldrsh r1, [r4, r3]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	beq _081DAA12
	ldrh r0, [r4, 0x3A]
	adds r0, r2, r0
	strh r0, [r4, 0x36]
	b _081DAA16
_081DAA12:
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081DAA16:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA9BC

	thumb_func_start sub_81DAA20
sub_81DAA20: @ 81DAA20
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =0x00002e90
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	movs r0, 0x10
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r0, 0x12
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAA20

	thumb_func_start sub_81DAA74
sub_81DAA74: @ 81DAA74
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	movs r0, 0x10
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r2, 0
	adds r5, 0x1C
	adds r0, r5
	ldr r4, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r4, r0
	bne _081DAAC4
	movs r0, 0x12
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r2, [r0]
	cmp r2, r4
	bne _081DAAC4
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldr r0, [r1]
	cmp r0, r2
	bne _081DAAC4
	movs r0, 0x1
	b _081DAAC6
	.pool
_081DAAC4:
	movs r0, 0
_081DAAC6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAA74

	thumb_func_start sub_81DAACC
sub_81DAACC: @ 81DAACC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DAB20
	bl sub_81DA700
	ldr r1, =0x00003f41
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r1, 0xA0
	lsls r1, 3
	movs r0, 0
	movs r2, 0x2
	bl ChangeBgY
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	b _081DAB46
	.pool
_081DAB20:
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	bl ClearGpuRegBits
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
_081DAB46:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAACC

	thumb_func_start sub_81DAB4C
sub_81DAB4C: @ 81DAB4C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081DAB64
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	bl SetGpuRegBits
_081DAB64:
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bne _081DAB98
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0x1F
	bne _081DAB92
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DABB0
_081DAB92:
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _081DABB0
_081DAB98:
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	ldrh r1, [r4, 0xC]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_081DABB0:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAB4C

	thumb_func_start sub_81DABBC
sub_81DABBC: @ 81DABBC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81DAA74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081DABD2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DABD2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DABBC

	thumb_func_start sub_81DABDC
sub_81DABDC: @ 81DABDC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B770
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DABEE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DABEE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DABDC

	thumb_func_start sub_81DAC14
sub_81DAC14: @ 81DAC14
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	movs r1, 0x33
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	movs r5, 0x2
	str r5, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x78
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x10]
	movs r0, 0x7
	negs r0, r0
	str r5, [sp]
	movs r4, 0x2
	negs r4, r4
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x12]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0xF7
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x14]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAC14

	thumb_func_start sub_81DAC80
sub_81DAC80: @ 81DAC80
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DACA4
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DABDC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DACA4:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAC80

	thumb_func_start sub_81DACB4
sub_81DACB4: @ 81DACB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B784
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DACC6:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DACC6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DACB4

	thumb_func_start sub_81DACEC
sub_81DACEC: @ 81DACEC
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	movs r0, 0
	str r0, [sp]
	movs r4, 0x4
	negs r4, r4
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x78
	movs r1, 0xC5
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x10]
	str r4, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0xF1
	movs r1, 0x3B
	movs r2, 0
	movs r3, 0x1
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x4
	str r1, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x3B
	movs r2, 0
	movs r3, 0x1
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81DACEC

	thumb_func_start sub_81DAD58
sub_81DAD58: @ 81DAD58
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DAD7C
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DACB4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DAD7C:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAD58

	thumb_func_start sub_81DAD8C
sub_81DAD8C: @ 81DAD8C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B798
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DAD9E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DAD9E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAD8C

	thumb_func_start sub_81DADC4
sub_81DADC4: @ 81DADC4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	mov r8, r0
	movs r6, 0x80
	str r6, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r5, 0x4
	negs r5, r5
	str r5, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x2D
	movs r2, 0xC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x10]
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x59
	movs r1, 0x61
	movs r2, 0xFC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x12]
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x97
	movs r1, 0x61
	movs r2, 0x84
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DADC4

	thumb_func_start sub_81DAE44
sub_81DAE44: @ 81DAE44
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DAE68
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DAD8C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DAE68:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAE44

	thumb_func_start sub_81DAE78
sub_81DAE78: @ 81DAE78
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7AC
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DAE8A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DAE8A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAE78

	thumb_func_start sub_81DAEB0
sub_81DAEB0: @ 81DAEB0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	mov r8, r0
	movs r2, 0x8E
	lsls r2, 1
	movs r6, 0x83
	str r6, [sp]
	movs r5, 0x23
	str r5, [sp, 0x4]
	movs r4, 0x3
	negs r4, r4
	str r4, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x10]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r2, 0x2C
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x12]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x79
	movs r1, 0x50
	movs r2, 0xA4
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAEB0

	thumb_func_start sub_81DAF34
sub_81DAF34: @ 81DAF34
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DAF58
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DAE78
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DAF58:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAF34

	thumb_func_start sub_81DAF68
sub_81DAF68: @ 81DAF68
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7C0
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DAF7A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DAF7A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAF68

	thumb_func_start sub_81DAFA0
sub_81DAFA0: @ 81DAFA0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _081DAFCC
	movs r1, 0x33
	negs r1, r1
	str r2, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0x78
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB01A
_081DAFCC:
	cmp r2, 0x10
	bne _081DAFF2
	movs r0, 0x7
	negs r0, r0
	movs r1, 0x4
	str r1, [sp]
	subs r1, 0x8
	str r1, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB01A
_081DAFF2:
	cmp r2, 0x20
	bne _081DB01A
	movs r0, 0x4
	negs r0, r0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0xF7
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB01A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAFA0

	thumb_func_start sub_81DB02C
sub_81DB02C: @ 81DB02C
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB050
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DAF68
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB050:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB02C

	thumb_func_start sub_81DB060
sub_81DB060: @ 81DB060
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7D4
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DB072:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DB072
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB060

	thumb_func_start sub_81DB098
sub_81DB098: @ 81DB098
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081DB0C4
	str r1, [sp]
	movs r0, 0x8
	negs r0, r0
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0x78
	movs r1, 0xC5
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB112
_081DB0C4:
	cmp r1, 0x10
	bne _081DB0E8
	movs r0, 0x8
	negs r0, r0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0xF1
	movs r1, 0x4E
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB112
_081DB0E8:
	cmp r1, 0x20
	bne _081DB112
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x8
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0x4E
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB112:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB098

	thumb_func_start sub_81DB124
sub_81DB124: @ 81DB124
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB148
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DB060
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB148:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB124

	thumb_func_start sub_81DB158
sub_81DB158: @ 81DB158
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7E8
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DB16A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DB16A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB158

	thumb_func_start sub_81DB190
sub_81DB190: @ 81DB190
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081DB1BE
	movs r0, 0x80
	str r0, [sp]
	str r1, [sp, 0x4]
	subs r0, 0x84
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x2D
	movs r2, 0xC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB212
_081DB1BE:
	cmp r1, 0x10
	bne _081DB1E6
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	subs r0, 0x4
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x59
	movs r1, 0x61
	movs r2, 0xFC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB212
_081DB1E6:
	cmp r1, 0x20
	bne _081DB212
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	subs r0, 0x4
	str r0, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x97
	movs r1, 0x61
	movs r2, 0x84
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB212:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB190

	thumb_func_start sub_81DB224
sub_81DB224: @ 81DB224
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB248
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DB158
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB248:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB224

	thumb_func_start sub_81DB258
sub_81DB258: @ 81DB258
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7FC
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DB26A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DB26A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB258

	thumb_func_start sub_81DB290
sub_81DB290: @ 81DB290
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081DB2C2
	movs r2, 0x8E
	lsls r2, 1
	movs r0, 0x83
	str r0, [sp]
	movs r0, 0x23
	str r0, [sp, 0x4]
	subs r0, 0x26
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB316
_081DB2C2:
	cmp r1, 0x10
	bne _081DB2EA
	movs r0, 0x83
	str r0, [sp]
	movs r0, 0x23
	str r0, [sp, 0x4]
	subs r0, 0x26
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r2, 0x2C
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB316
_081DB2EA:
	cmp r1, 0x20
	bne _081DB316
	movs r0, 0x83
	str r0, [sp]
	movs r0, 0x23
	str r0, [sp, 0x4]
	subs r0, 0x26
	str r0, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x79
	movs r1, 0x50
	movs r2, 0xA4
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB316:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB290

	thumb_func_start sub_81DB328
sub_81DB328: @ 81DB328
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB34C
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DB258
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB34C:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB328

	thumb_func_start GetStringCenterAlignXOffset
@ s32 GetStringCenterAlignXOffset(u8 fontId, u8 *str, s32 totalWidth)
GetStringCenterAlignXOffset: @ 81DB35C
	push {lr}
	movs r3, 0
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	pop {r1}
	bx r1
	thumb_func_end GetStringCenterAlignXOffset

	thumb_func_start GetStringRightAlignXOffset
@ s32 GetStringRightAlignXOffset(u8 fontId, u8 *str, s32 totalWidth)
GetStringRightAlignXOffset: @ 81DB368
	push {lr}
	movs r3, 0
	bl GetStringWidthDifference
	pop {r1}
	bx r1
	thumb_func_end GetStringRightAlignXOffset

	thumb_func_start GetStringCenterAlignXOffsetWithLetterSpacing
@ s32 GetStringCenterAlignXOffsetWithLetterSpacing(u8 fontId, u8 *str, s32 totalWidth, s16 letterSpacing)
GetStringCenterAlignXOffsetWithLetterSpacing: @ 81DB374
	push {lr}
	bl GetStringWidthDifference
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	pop {r1}
	bx r1
	thumb_func_end GetStringCenterAlignXOffsetWithLetterSpacing

	thumb_func_start GetStringWidthDifference
@ s32 GetStringWidthDifference(u8 fontId, u8 *str, s32 totalWidth, s16 letterSpacing)
GetStringWidthDifference: @ 81DB384
	push {r4,lr}
	adds r4, r2, 0
	adds r2, r3, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	asrs r2, 16
	bl GetStringWidth
	cmp r4, r0
	bgt _081DB39E
	movs r0, 0
	b _081DB3A0
_081DB39E:
	subs r0, r4, r0
_081DB3A0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetStringWidthDifference

	thumb_func_start GetMaxWidthInMenuTable
GetMaxWidthInMenuTable: @ 81DB3A8
	push {r4-r6,lr}
	movs r6, 0
	cmp r6, r1
	bge _081DB3CC
	adds r5, r0, 0
	adds r4, r1, 0
_081DB3B4:
	ldr r1, [r5]
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	cmp r0, r6
	ble _081DB3C4
	adds r6, r0, 0
_081DB3C4:
	adds r5, 0x8
	subs r4, 0x1
	cmp r4, 0
	bne _081DB3B4
_081DB3CC:
	adds r0, r6, 0
	bl convert_pixel_width_to_tile_width
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetMaxWidthInMenuTable

	thumb_func_start sub_81DB3D8
sub_81DB3D8: @ 81DB3D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, 0
	adds r5, r2, 0
	movs r6, 0
	movs r4, 0
	cmp r6, r5
	bge _081DB40A
_081DB3EC:
	adds r0, r7, r4
	ldrb r0, [r0]
	lsls r0, 3
	add r0, r8
	ldr r1, [r0]
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	cmp r0, r6
	ble _081DB404
	adds r6, r0, 0
_081DB404:
	adds r4, 0x1
	cmp r4, r5
	blt _081DB3EC
_081DB40A:
	adds r0, r6, 0
	bl convert_pixel_width_to_tile_width
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB3D8

	thumb_func_start sub_81DB41C
sub_81DB41C: @ 81DB41C
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r1, [r4]
	movs r7, 0
	movs r6, 0
	ldrh r0, [r4, 0xC]
	cmp r7, r0
	bge _081DB44C
	adds r5, r1, 0
_081DB42E:
	ldrb r0, [r4, 0x17]
	lsls r0, 26
	lsrs r0, 26
	ldr r1, [r5]
	movs r2, 0
	bl GetStringWidth
	cmp r0, r7
	ble _081DB442
	adds r7, r0, 0
_081DB442:
	adds r5, 0x8
	adds r6, 0x1
	ldrh r0, [r4, 0xC]
	cmp r6, r0
	blt _081DB42E
_081DB44C:
	ldrb r0, [r4, 0x12]
	adds r1, r7, r0
	adds r0, r1, 0
	adds r0, 0x9
	cmp r0, 0
	bge _081DB45A
	adds r0, 0x7
_081DB45A:
	asrs r0, 3
	cmp r0, 0x1C
	ble _081DB462
	movs r0, 0x1C
_081DB462:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB41C

	thumb_func_start sub_81DB468
sub_81DB468: @ 81DB468
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	lsls r2, 5
	ldr r1, =gPokedexEntries
	adds r2, r1
	adds r1, r2, 0
	bl StringCopy
	movs r1, 0
	strb r1, [r0]
	adds r0, 0x1
	ldr r1, =gUnknown_085E8268
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB468

	thumb_func_start sub_81DB494
sub_81DB494: @ 81DB494
	push {r4-r7,lr}
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	cmp r5, 0
	beq _081DB4B6
	adds r1, r5, 0
	bl StringCopy
	adds r4, r0, 0
	lsls r0, r6, 24
	lsrs r0, 24
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	b _081DB4BA
_081DB4B6:
	adds r4, r0, 0
	movs r0, 0
_081DB4BA:
	subs r3, r7, r0
	cmp r3, 0
	ble _081DB4D4
	movs r0, 0xFC
	strb r0, [r4]
	adds r4, 0x1
	movs r0, 0x11
	strb r0, [r4]
	adds r4, 0x1
	strb r3, [r4]
	adds r4, 0x1
	movs r0, 0xFF
	strb r0, [r4]
_081DB4D4:
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB494

	thumb_func_start sub_81DB4DC
sub_81DB4DC: @ 81DB4DC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl StripExtCtrlCodes
	adds r0, r4, 0
	bl StringLength
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r5, 0xFC
	bne _081DB51A
	cmp r1, 0x5
	bhi _081DB51E
	movs r3, 0xFC
	movs r2, 0x7
_081DB4FE:
	adds r0, r4, r1
	strb r3, [r0]
	strb r2, [r0, 0x1]
	adds r0, r1, 0x2
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x5
	bls _081DB4FE
	b _081DB51E
_081DB510:
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
_081DB51A:
	cmp r1, 0x5
	bls _081DB510
_081DB51E:
	adds r1, r4, r1
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81DB4DC

	thumb_func_start sub_81DB52C
sub_81DB52C: @ 81DB52C
	push {r4,lr}
	adds r4, r0, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081DB546
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _081DB54C
_081DB546:
	adds r0, r4, 0
	bl StripExtCtrlCodes
_081DB54C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81DB52C

	thumb_func_start sub_81DB554
sub_81DB554: @ 81DB554
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081DB572
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _081DB5A4
_081DB572:
	cmp r5, 0xFC
	bne _081DB57E
	adds r0, r4, 0
	bl StripExtCtrlCodes
	b _081DB5A4
_081DB57E:
	adds r1, r4, 0
	b _081DB584
_081DB582:
	adds r1, 0x1
_081DB584:
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	bne _081DB582
	cmp r1, r4
	bcc _081DB5A4
	ldrb r0, [r1]
	cmp r0, r5
	bne _081DB5A4
	movs r2, 0xFF
_081DB596:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, r4
	bcc _081DB5A4
	ldrb r0, [r1]
	cmp r0, r5
	beq _081DB596
_081DB5A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81DB554

	thumb_func_start sub_81DB5AC
sub_81DB5AC: @ 81DB5AC
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2]
	adds r2, 0x1
	cmp r0, 0xFC
	bne _081DB5E4
	ldrb r0, [r2]
	adds r2, 0x1
	cmp r0, 0x15
	bne _081DB5E4
	b _081DB5CE
_081DB5C2:
	cmp r1, 0xFC
	bne _081DB5CC
	ldrb r0, [r2, 0x1]
	cmp r0, 0x16
	beq _081DB5E4
_081DB5CC:
	adds r2, 0x1
_081DB5CE:
	ldrb r1, [r2]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _081DB5C2
	movs r0, 0xFC
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x16
	strb r0, [r2]
	movs r0, 0xFF
	strb r0, [r2, 0x1]
_081DB5E4:
	pop {r0}
	bx r0
	thumb_func_end sub_81DB5AC

	thumb_func_start sub_81DB5E8
sub_81DB5E8: @ 81DB5E8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	bl StringCopy
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl ConvertInternationalString
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81DB5E8

	thumb_func_start sub_81DB604
sub_81DB604: @ 81DB604
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0xFC
	bne _081DB618
	ldrb r0, [r1, 0x1]
	cmp r0, 0x15
	bne _081DB618
	movs r0, 0x1
	b _081DB61A
_081DB618:
	movs r0, 0x2
_081DB61A:
	pop {r1}
	bx r1
	thumb_func_end sub_81DB604

	thumb_func_start sub_81DB620
sub_81DB620: @ 81DB620
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	ldr r0, =gWindows
	adds r4, r0
	lsls r7, r3, 5
	ldrb r0, [r4, 0x3]
	lsls r6, r0, 5
	muls r2, r6
	ldr r0, [r4, 0x8]
	adds r0, r2
	lsls r1, 5
	adds r5, r0, r1
	ldr r0, [sp, 0x18]
	cmp r0, 0
	ble _081DB66C
	adds r4, r0, 0
_081DB646:
	ldr r0, =0x11111111
	str r0, [sp]
	adds r2, r7, 0
	cmp r2, 0
	bge _081DB652
	adds r2, 0x3
_081DB652:
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	adds r1, r5, 0
	bl CpuFastSet
	adds r5, r6
	subs r4, 0x1
	cmp r4, 0
	bne _081DB646
_081DB66C:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB620

	.align 2, 0 @ Don't pad with nop.
