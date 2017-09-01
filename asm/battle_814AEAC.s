	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_112
nullsub_112: @ 814AEAC
	bx lr
	thumb_func_end nullsub_112

	thumb_func_start sub_814AEB0
sub_814AEB0: @ 814AEB0
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl4
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_814AEB0

	thumb_func_start bx_exec_buffer_A_ch0_tbl4
bx_exec_buffer_A_ch0_tbl4: @ 814AECC
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
	beq _0814AF18
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _0814AF14
	ldr r0, =gUnknown_085C9A94
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _0814AF18
	.pool
_0814AF14:
	bl dp01_tbl4_exec_completed
_0814AF18:
	pop {r0}
	bx r0
	thumb_func_end bx_exec_buffer_A_ch0_tbl4

	thumb_func_start sub_814AF1C
sub_814AF1C: @ 814AF1C
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
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0814AF40
	bl dp01_tbl4_exec_completed
_0814AF40:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814AF1C

	thumb_func_start sub_814AF54
sub_814AF54: @ 814AF54
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
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0814AFA4
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
	bl dp01_tbl4_exec_completed
_0814AFA4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814AF54

	thumb_func_start sub_814AFBC
sub_814AFBC: @ 814AFBC
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
	bne _0814AFF4
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl dp01_tbl4_exec_completed
_0814AFF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814AFBC

	thumb_func_start sub_814B004
sub_814B004: @ 814B004
	push {r4-r6,lr}
	movs r6, 0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0814B028
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0814B05C
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0814B05C
_0814B028:
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
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0814B094
	b _0814B092
	.pool
_0814B05C:
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
	ldr r0, =DummyObjectCallback
	cmp r2, r0
	bne _0814B094
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
	bne _0814B094
_0814B092:
	movs r6, 0x1
_0814B094:
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	beq _0814B0A0
	movs r6, 0
_0814B0A0:
	cmp r6, 0
	beq _0814B0C6
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
	ldr r1, =sub_814AFBC
	str r1, [r0]
_0814B0C6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B004

	thumb_func_start sub_814B0E8
sub_814B0E8: @ 814B0E8
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
	beq _0814B114
	b _0814B252
_0814B114:
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
	beq _0814B136
	b _0814B252
_0814B136:
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
	ldr r0, =DummyObjectCallback
	cmp r3, r0
	bne _0814B252
	ldr r0, =gBankSpriteIds
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r3
	bne _0814B252
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0814B252
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
	beq _0814B1F0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0814B1F0
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
_0814B1F0:
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
	ldr r1, =sub_814B004
	str r1, [r0]
_0814B252:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B0E8

	thumb_func_start sub_814B290
sub_814B290: @ 814B290
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
	bge _0814B2BE
	movs r2, 0x24
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0814B2BE
	bl dp01_tbl4_exec_completed
_0814B2BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B290

	thumb_func_start bx_t4_healthbar_update
bx_t4_healthbar_update: @ 814B2D0
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
	beq _0814B318
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _0814B332
	.pool
_0814B318:
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
	bl dp01_tbl4_exec_completed
_0814B332:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_t4_healthbar_update

	thumb_func_start sub_814B340
sub_814B340: @ 814B340
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
	ble _0814B3BC
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
	bl dp01_tbl4_exec_completed
_0814B3BC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B340

	thumb_func_start sub_814B3DC
sub_814B3DC: @ 814B3DC
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
	bne _0814B430
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
	bl dp01_tbl4_exec_completed
_0814B430:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B3DC

	thumb_func_start bx_t4_button_a
bx_t4_button_a: @ 814B44C
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0814B45E
	bl dp01_tbl4_exec_completed
_0814B45E:
	pop {r0}
	bx r0
	thumb_func_end bx_t4_button_a

	thumb_func_start dp01t_0F_4_move_anim
dp01t_0F_4_move_anim: @ 814B464
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
	bne _0814B4B0
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
	bl dp01_tbl4_exec_completed
	b _0814B4DA
	.pool
_0814B4B0:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0814B4D4
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
_0814B4D4:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_0814B4DA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end dp01t_0F_4_move_anim

	thumb_func_start sub_814B4E0
sub_814B4E0: @ 814B4E0
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
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0814B532
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
	beq _0814B526
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
_0814B526:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_814B554
	str r0, [r1]
_0814B532:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B4E0

	thumb_func_start sub_814B554
sub_814B554: @ 814B554
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
	bne _0814B590
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
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0814B590
	bl dp01_tbl4_exec_completed
_0814B590:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B554

	thumb_func_start sub_814B5A8
sub_814B5A8: @ 814B5A8
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
	beq _0814B664
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
	ldr r1, =sub_814B4E0
	str r1, [r0]
_0814B664:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B5A8

	thumb_func_start sub_814B69C
sub_814B69C: @ 814B69C
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
	bne _0814B6CE
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0814B6CE:
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
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0814B714
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
	bne _0814B714
	adds r0, r3, r5
	bl DestroySprite
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_814B5A8
	str r1, [r0]
_0814B714:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B69C

	thumb_func_start dp01_tbl4_exec_completed
dp01_tbl4_exec_completed: @ 814B740
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl4
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0814B794
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
	b _0814B7A6
	.pool
_0814B794:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0814B7A6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_tbl4_exec_completed

	thumb_func_start sub_814B7B8
sub_814B7B8: @ 814B7B8
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
	bne _0814B7DA
	bl dp01_tbl4_exec_completed
_0814B7DA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B7B8

	thumb_func_start sub_814B7E8
sub_814B7E8: @ 814B7E8
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
	bne _0814B80A
	bl dp01_tbl4_exec_completed
_0814B80A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814B7E8

	thumb_func_start dp01t_00_4_getattr
dp01t_00_4_getattr: @ 814B818
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
	bne _0814B850
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl dp01_getattr_by_ch1_for_player_pokemon__
	adds r6, r0, 0
	b _0814B872
	.pool
_0814B850:
	ldrb r4, [r1]
	movs r5, 0
_0814B854:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0814B86A
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl dp01_getattr_by_ch1_for_player_pokemon__
	adds r6, r0
_0814B86A:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _0814B854
_0814B872:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl dp01_tbl4_exec_completed
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_4_getattr

	thumb_func_start dp01_getattr_by_ch1_for_player_pokemon__
dp01_getattr_by_ch1_for_player_pokemon__: @ 814B88C
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
	bls _0814B8B6
	bl _0814C022
_0814B8B6:
	lsls r0, 2
	ldr r1, =_0814B8CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814B8CC:
	.4byte _0814B9BC
	.4byte _0814BBE0
	.4byte _0814BBF0
	.4byte _0814BC00
	.4byte _0814BC68
	.4byte _0814BC68
	.4byte _0814BC68
	.4byte _0814BC68
	.4byte _0814BC84
	.4byte _0814BCC0
	.4byte _0814BCC0
	.4byte _0814BCC0
	.4byte _0814BCC0
	.4byte _0814C022
	.4byte _0814C022
	.4byte _0814C022
	.4byte _0814C022
	.4byte _0814BCDC
	.4byte _0814BCEC
	.4byte _0814BD1C
	.4byte _0814BD2C
	.4byte _0814BD3C
	.4byte _0814BD4C
	.4byte _0814BD5C
	.4byte _0814BD6C
	.4byte _0814BD7C
	.4byte _0814BD8C
	.4byte _0814BD9C
	.4byte _0814BDAC
	.4byte _0814BDBC
	.4byte _0814BDCC
	.4byte _0814BDDC
	.4byte _0814BE2C
	.4byte _0814BE3C
	.4byte _0814BE4C
	.4byte _0814BE5C
	.4byte _0814BE6C
	.4byte _0814BE7C
	.4byte _0814BE8C
	.4byte _0814BE9C
	.4byte _0814BEAC
	.4byte _0814BEE0
	.4byte _0814BEF0
	.4byte _0814BF00
	.4byte _0814BF10
	.4byte _0814BF20
	.4byte _0814BF30
	.4byte _0814BF40
	.4byte _0814BF50
	.4byte _0814BF70
	.4byte _0814BF80
	.4byte _0814BF90
	.4byte _0814BFA0
	.4byte _0814BFB0
	.4byte _0814BFC0
	.4byte _0814BFD0
	.4byte _0814BFE0
	.4byte _0814BFF0
	.4byte _0814C000
	.4byte _0814C010
_0814B9BC:
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
_0814BA08:
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
	ble _0814BA08
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
_0814BBC0:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _0814BBC0
	b _0814C022
	.pool
_0814BBE0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	b _0814BF5A
	.pool
_0814BBF0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	b _0814BF5A
	.pool
_0814BC00:
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
_0814BC16:
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
	ble _0814BC16
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
_0814BC54:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _0814BC54
	b _0814C022
	.pool
_0814BC68:
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
	b _0814BF5A
	.pool
_0814BC84:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gPlayerParty
	mov r8, r2
_0814BC90:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0814BC90
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _0814C022
	.pool
_0814BCC0:
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
	b _0814C01A
	.pool
_0814BCDC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	b _0814BCF6
	.pool
_0814BCEC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x19
_0814BCF6:
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
	b _0814C022
	.pool
_0814BD1C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1A
	b _0814C01A
	.pool
_0814BD2C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1B
	b _0814C01A
	.pool
_0814BD3C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1C
	b _0814C01A
	.pool
_0814BD4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1D
	b _0814C01A
	.pool
_0814BD5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1E
	b _0814C01A
	.pool
_0814BD6C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1F
	b _0814C01A
	.pool
_0814BD7C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x20
	b _0814C01A
	.pool
_0814BD8C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x22
	b _0814C01A
	.pool
_0814BD9C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x23
	b _0814C01A
	.pool
_0814BDAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x24
	b _0814C01A
	.pool
_0814BDBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x25
	b _0814C01A
	.pool
_0814BDCC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x26
	b _0814C01A
	.pool
_0814BDDC:
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
	b _0814C022
	.pool
_0814BE2C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x27
	b _0814C01A
	.pool
_0814BE3C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x28
	b _0814C01A
	.pool
_0814BE4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x29
	b _0814C01A
	.pool
_0814BE5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2A
	b _0814C01A
	.pool
_0814BE6C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2B
	b _0814C01A
	.pool
_0814BE7C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2C
	b _0814C01A
	.pool
_0814BE8C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	b _0814BEB6
	.pool
_0814BE9C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x9
	b _0814BF5A
	.pool
_0814BEAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x37
_0814BEB6:
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
	b _0814C022
	.pool
_0814BEE0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	b _0814C01A
	.pool
_0814BEF0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	b _0814BF5A
	.pool
_0814BF00:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	b _0814BF5A
	.pool
_0814BF10:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3B
	b _0814BF5A
	.pool
_0814BF20:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3C
	b _0814BF5A
	.pool
_0814BF30:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3D
	b _0814BF5A
	.pool
_0814BF40:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3E
	b _0814BF5A
	.pool
_0814BF50:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3F
_0814BF5A:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _0814C022
	.pool
_0814BF70:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	b _0814C01A
	.pool
_0814BF80:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	b _0814C01A
	.pool
_0814BF90:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	b _0814C01A
	.pool
_0814BFA0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	b _0814C01A
	.pool
_0814BFB0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	b _0814C01A
	.pool
_0814BFC0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	b _0814C01A
	.pool
_0814BFD0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _0814C01A
	.pool
_0814BFE0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _0814C01A
	.pool
_0814BFF0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _0814C01A
	.pool
_0814C000:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _0814C01A
	.pool
_0814C010:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_0814C01A:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_0814C022:
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
	thumb_func_end dp01_getattr_by_ch1_for_player_pokemon__

	thumb_func_start sub_814C038
sub_814C038: @ 814C038
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814C038

	thumb_func_start sub_814C044
sub_814C044: @ 814C044
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0814C074
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_814C09C
	b _0814C092
	.pool
_0814C074:
	ldrb r4, [r1]
	movs r5, 0
_0814C078:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0814C086
	adds r0, r5, 0
	bl sub_814C09C
_0814C086:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0814C078
_0814C092:
	bl dp01_tbl4_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_814C044

	thumb_func_start sub_814C09C
sub_814C09C: @ 814C09C
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
	bls _0814C0C8
	bl _0814CA62
_0814C0C8:
	lsls r0, 2
	ldr r1, =_0814C0E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814C0E0:
	.4byte _0814C1D0
	.4byte _0814C368
	.4byte _0814C388
	.4byte _0814C3A8
	.4byte _0814C400
	.4byte _0814C400
	.4byte _0814C400
	.4byte _0814C400
	.4byte _0814C428
	.4byte _0814C48C
	.4byte _0814C48C
	.4byte _0814C48C
	.4byte _0814C48C
	.4byte _0814CA62
	.4byte _0814CA62
	.4byte _0814CA62
	.4byte _0814CA62
	.4byte _0814C4BC
	.4byte _0814C4DC
	.4byte _0814C4FC
	.4byte _0814C51C
	.4byte _0814C53C
	.4byte _0814C55C
	.4byte _0814C57C
	.4byte _0814C59C
	.4byte _0814C5BC
	.4byte _0814C5DC
	.4byte _0814C5FC
	.4byte _0814C61C
	.4byte _0814C63C
	.4byte _0814C65C
	.4byte _0814C67C
	.4byte _0814C6EC
	.4byte _0814C70C
	.4byte _0814C72C
	.4byte _0814C74C
	.4byte _0814C76C
	.4byte _0814C78C
	.4byte _0814C7AC
	.4byte _0814C7CC
	.4byte _0814C7EC
	.4byte _0814C80C
	.4byte _0814C82C
	.4byte _0814C84C
	.4byte _0814C86C
	.4byte _0814C88C
	.4byte _0814C8AC
	.4byte _0814C8CC
	.4byte _0814C8EC
	.4byte _0814C90C
	.4byte _0814C92C
	.4byte _0814C94C
	.4byte _0814C96C
	.4byte _0814C98C
	.4byte _0814C9AC
	.4byte _0814C9CC
	.4byte _0814C9EC
	.4byte _0814CA0C
	.4byte _0814CA2C
	.4byte _0814CA4C
_0814C1D0:
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
_0814C236:
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
	ble _0814C236
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
	b _0814CA62
	.pool
_0814C368:
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
	b _0814CA62
	.pool
_0814C388:
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
	b _0814CA62
	.pool
_0814C3A8:
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
_0814C3C2:
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
	ble _0814C3C2
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _0814CA62
	.pool
_0814C400:
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
	b _0814C4A4
	.pool
_0814C428:
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
	b _0814CA62
	.pool
_0814C48C:
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
_0814C4A4:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _0814CA62
	.pool
_0814C4BC:
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
	b _0814CA62
	.pool
_0814C4DC:
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
	b _0814CA62
	.pool
_0814C4FC:
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
	b _0814CA62
	.pool
_0814C51C:
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
	b _0814CA62
	.pool
_0814C53C:
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
	b _0814CA62
	.pool
_0814C55C:
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
	b _0814CA62
	.pool
_0814C57C:
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
	b _0814CA62
	.pool
_0814C59C:
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
	b _0814CA62
	.pool
_0814C5BC:
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
	b _0814CA62
	.pool
_0814C5DC:
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
	b _0814CA62
	.pool
_0814C5FC:
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
	b _0814CA62
	.pool
_0814C61C:
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
	b _0814CA62
	.pool
_0814C63C:
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
	b _0814CA62
	.pool
_0814C65C:
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
	b _0814CA62
	.pool
_0814C67C:
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
	b _0814C79C
	.pool
_0814C6EC:
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
	b _0814CA62
	.pool
_0814C70C:
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
	b _0814CA62
	.pool
_0814C72C:
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
	b _0814CA62
	.pool
_0814C74C:
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
	b _0814CA62
	.pool
_0814C76C:
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
	b _0814CA62
	.pool
_0814C78C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
_0814C79C:
	movs r1, 0x2C
	bl SetMonData
	b _0814CA62
	.pool
_0814C7AC:
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
	b _0814CA62
	.pool
_0814C7CC:
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
	b _0814CA62
	.pool
_0814C7EC:
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
	b _0814CA62
	.pool
_0814C80C:
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
	b _0814CA62
	.pool
_0814C82C:
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
	b _0814CA62
	.pool
_0814C84C:
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
	b _0814CA62
	.pool
_0814C86C:
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
	b _0814CA62
	.pool
_0814C88C:
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
	b _0814CA62
	.pool
_0814C8AC:
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
	b _0814CA62
	.pool
_0814C8CC:
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
	b _0814CA62
	.pool
_0814C8EC:
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
	b _0814CA62
	.pool
_0814C90C:
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
	b _0814CA62
	.pool
_0814C92C:
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
	b _0814CA62
	.pool
_0814C94C:
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
	b _0814CA62
	.pool
_0814C96C:
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
	b _0814CA62
	.pool
_0814C98C:
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
	b _0814CA62
	.pool
_0814C9AC:
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
	b _0814CA62
	.pool
_0814C9CC:
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
	b _0814CA62
	.pool
_0814C9EC:
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
	b _0814CA62
	.pool
_0814CA0C:
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
	b _0814CA62
	.pool
_0814CA2C:
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
	b _0814CA62
	.pool
_0814CA4C:
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
_0814CA62:
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
	thumb_func_end sub_814C09C

	thumb_func_start sub_814CA98
sub_814CA98: @ 814CA98
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
	bcs _0814CAF0
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_0814CACE:
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
	bcc _0814CACE
_0814CAF0:
	bl dp01_tbl4_exec_completed
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814CA98

	thumb_func_start sub_814CB0C
sub_814CB0C: @ 814CB0C
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
	ldr r1, =sub_814B290
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814CB0C

	thumb_func_start sub_814CC28
sub_814CC28: @ 814CC28
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
	bl sub_814CC98
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_814B69C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814CC28

	thumb_func_start sub_814CC98
sub_814CC98: @ 814CC98
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
	ldr r1, =DummyObjectCallback
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
	thumb_func_end sub_814CC98

	thumb_func_start sub_814CE14
sub_814CE14: @ 814CE14
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _0814CE5C
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
	ldr r1, =sub_814CEA4
	str r1, [r0]
	b _0814CE92
	.pool
_0814CE5C:
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
	bl dp01_tbl4_exec_completed
_0814CE92:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814CE14

	thumb_func_start sub_814CEA4
sub_814CEA4: @ 814CEA4
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
	beq _0814CECC
	cmp r0, 0x1
	beq _0814CEFA
	b _0814CF22
	.pool
_0814CECC:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0814CEE6
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0814CEE6:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0814CF22
_0814CEFA:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0814CF22
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
	ldr r1, =sub_814B3DC
	str r1, [r0]
_0814CF22:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814CEA4

	thumb_func_start sub_814CF30
sub_814CF30: @ 814CF30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0814CF60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r1, 0x2
	ands r1, r0
	movs r7, 0x20
	cmp r1, 0
	beq _0814CF62
	movs r7, 0x5A
	b _0814CF62
	.pool
_0814CF60:
	movs r7, 0x50
_0814CF62:
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl sub_806D864
	ldr r6, =gUnknown_020229E8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _0814CF94
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _0814CFB0
_0814CF94:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x2
	b _0814D002
	.pool
_0814CFB0:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _0814CFDE
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _0814CFF2
_0814CFDE:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x4
	b _0814D002
_0814CFF2:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r4, [r1, 0x13]
_0814D002:
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
	mov r8, r7
	ldr r0, =gUnknown_08305D2C
	lsls r4, 2
	adds r4, r0
	ldrb r0, [r4]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r0, 0xA0
	lsls r0, 15
	adds r4, r0
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
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_814AF1C
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814CF30

	thumb_func_start sub_814D0E4
sub_814D0E4: @ 814D0E4
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D0E4

	thumb_func_start sub_814D0F0
sub_814D0F0: @ 814D0F0
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
	ldr r1, =DummyObjectCallback
	bl oamt_set_x3A_32
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_814AF54
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D0F0

	thumb_func_start sub_814D19C
sub_814D19C: @ 814D19C
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
	bne _0814D1F0
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0814D1D0
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0814D1D0:
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
	b _0814D266
	.pool
_0814D1F0:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0814D266
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
	ldr r1, =sub_814B340
	str r1, [r0]
_0814D266:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D19C

	thumb_func_start sub_814D288
sub_814D288: @ 814D288
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D288

	thumb_func_start sub_814D294
sub_814D294: @ 814D294
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D294

	thumb_func_start sub_814D2A0
sub_814D2A0: @ 814D2A0
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D2A0

	thumb_func_start sub_814D2AC
sub_814D2AC: @ 814D2AC
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D2AC

	thumb_func_start sub_814D2B8
sub_814D2B8: @ 814D2B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _0814D2CE
	b _0814D3F4
_0814D2CE:
	ldr r0, =gBattleBufferA
	mov r12, r0
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	mov r0, r12
	adds r0, 0x2
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r6, r0
	ldr r0, =gUnknown_02038432
	mov r8, r0
	mov r0, r12
	adds r0, 0x3
	adds r1, r0
	ldrb r0, [r1]
	mov r1, r8
	strb r0, [r1]
	ldr r3, =gUnknown_02038408
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x4
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x5
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	strh r2, [r3]
	ldr r3, =gUnknown_02038404
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x6
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x7
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r2, r0
	mov r0, r12
	adds r0, 0x8
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 16
	orrs r2, r0
	mov r0, r12
	adds r0, 0x9
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 24
	orrs r2, r0
	str r2, [r3]
	ldr r2, =gUnknown_0203841A
	ldrb r0, [r5]
	lsls r0, 9
	mov r1, r12
	adds r1, 0xA
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r4, =gUnknown_0203841C
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0xC
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0xD
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	strh r2, [r4]
	ldr r7, =gUnknown_02038400
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x10
	adds r1, r0
	str r1, [r7]
	ldr r2, =gUnknown_020244BC
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r1]
	str r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_805DB8C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _0814D3CC
	bl dp01_tbl4_exec_completed
	b _0814D3F4
	.pool
_0814D3CC:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x4]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_move_anim_4
	str r1, [r0]
	ldrh r1, [r4]
	ldr r2, [r7]
	adds r0, r6, 0
	bl sub_817E0FC
_0814D3F4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D2B8

	thumb_func_start bx_move_anim_4
bx_move_anim_4: @ 814D40C
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
	beq _0814D4A4
	cmp r2, 0x1
	bgt _0814D464
	cmp r2, 0
	beq _0814D46E
	b _0814D580
	.pool
_0814D464:
	cmp r2, 0x2
	beq _0814D4CE
	cmp r2, 0x3
	beq _0814D544
	b _0814D580
_0814D46E:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _0814D490
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0814D490:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0814D580
_0814D4A4:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0814D580
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
	b _0814D580
_0814D4CE:
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _0814D580
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
	beq _0814D51C
	mov r0, r8
	cmp r0, 0x1
	bhi _0814D51C
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
_0814D51C:
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
	b _0814D580
	.pool
_0814D544:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0814D580
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
	bl dp01_tbl4_exec_completed
_0814D580:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_4

	thumb_func_start sub_814D590
sub_814D590: @ 814D590
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gUnknown_02023066
	adds r4, r0
	ldrh r0, [r4]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t4_button_a
	str r1, [r0]
	ldrh r0, [r4]
	bl sub_817C95C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D590

	thumb_func_start sub_814D5E8
sub_814D5E8: @ 814D5E8
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D5E8

	thumb_func_start sub_814D5F4
sub_814D5F4: @ 814D5F4
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D5F4

	thumb_func_start sub_814D600
sub_814D600: @ 814D600
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D600

	thumb_func_start sub_814D60C
sub_814D60C: @ 814D60C
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D60C

	thumb_func_start sub_814D618
sub_814D618: @ 814D618
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D618

	thumb_func_start sub_814D624
sub_814D624: @ 814D624
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D624

	thumb_func_start sub_814D630
sub_814D630: @ 814D630
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D630

	thumb_func_start sub_814D63C
sub_814D63C: @ 814D63C
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
	beq _0814D6CC
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
	b _0814D6F6
	.pool
_0814D6CC:
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
_0814D6F6:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t4_healthbar_update
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D63C

	thumb_func_start sub_814D72C
sub_814D72C: @ 814D72C
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D72C

	thumb_func_start sub_814D738
sub_814D738: @ 814D738
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0814D78C
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
	ldr r1, =sub_814B7B8
	str r1, [r0]
_0814D78C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D738

	thumb_func_start sub_814D7B0
sub_814D7B0: @ 814D7B0
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0814D800
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
	ldr r1, =sub_814B7B8
	str r1, [r0]
_0814D800:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D7B0

	thumb_func_start sub_814D818
sub_814D818: @ 814D818
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D818

	thumb_func_start sub_814D824
sub_814D824: @ 814D824
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D824

	thumb_func_start sub_814D830
sub_814D830: @ 814D830
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D830

	thumb_func_start sub_814D83C
sub_814D83C: @ 814D83C
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D83C

	thumb_func_start sub_814D848
sub_814D848: @ 814D848
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D848

	thumb_func_start sub_814D854
sub_814D854: @ 814D854
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D854

	thumb_func_start sub_814D860
sub_814D860: @ 814D860
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D860

	thumb_func_start sub_814D86C
sub_814D86C: @ 814D86C
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D86C

	thumb_func_start sub_814D878
sub_814D878: @ 814D878
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D878

	thumb_func_start sub_814D884
sub_814D884: @ 814D884
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D884

	thumb_func_start sub_814D8A0
sub_814D8A0: @ 814D8A0
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
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D8A0

	thumb_func_start sub_814D8D8
sub_814D8D8: @ 814D8D8
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D8D8

	thumb_func_start sub_814D8F0
sub_814D8F0: @ 814D8F0
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
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D8F0

	thumb_func_start dp01t_29_4_blink
dp01t_29_4_blink: @ 814D918
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
	bge _0814D94C
	bl dp01_tbl4_exec_completed
	b _0814D976
	.pool
_0814D94C:
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
	ldr r1, =dp01t_0F_4_move_anim
	str r1, [r0]
_0814D976:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_29_4_blink

	thumb_func_start sub_814D988
sub_814D988: @ 814D988
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814D988

	thumb_func_start sub_814D994
sub_814D994: @ 814D994
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _0814D9A8
	movs r3, 0xC0
_0814D9A8:
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
	bl dp01_tbl4_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814D994

	thumb_func_start sub_814D9D8
sub_814D9D8: @ 814D9D8
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0814DA14
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
	b _0814DA28
	.pool
_0814DA14:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_0814DA28:
	bl dp01_tbl4_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_814D9D8

	thumb_func_start sub_814DA34
sub_814DA34: @ 814DA34
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
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DA34

	thumb_func_start dp01t_2E_4_battle_intro
dp01t_2E_4_battle_intro: @ 814DA74
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
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_4_battle_intro

	thumb_func_start sub_814DAA8
sub_814DAA8: @ 814DAA8
	push {r4-r7,lr}
	ldr r5, =gBankSpriteIds
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x32
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r2, [r6]
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x38]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_805CC00
	bl oamt_set_x3A_32
	ldrb r0, [r6]
	adds r0, r5
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
	lsrs r7, r0, 24
	ldrb r0, [r6]
	bl sub_806D864
	ldr r4, =gUnknown_020229E8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	movs r5, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _0814DB80
	ldrb r0, [r6]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x5
	bne _0814DBB4
_0814DB80:
	ldrb r0, [r6]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1, 0x13]
	adds r0, 0x2
	b _0814DC06
	.pool
_0814DBB4:
	ldrb r0, [r6]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x2
	beq _0814DBE2
	ldrb r0, [r6]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1]
	ands r5, r0
	cmp r5, 0x1
	bne _0814DBF6
_0814DBE2:
	ldrb r0, [r6]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1, 0x13]
	adds r0, 0x4
	b _0814DC06
_0814DBF6:
	ldrb r0, [r6]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1, 0x13]
_0814DC06:
	ldr r1, =gTrainerBackPicPaletteTable
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0]
	lsls r4, r7, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0x20
	bl LoadCompressedPalette
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
	ldr r0, =sub_814DCCC
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
	beq _0814DC80
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_0814DC80:
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
	ldr r1, =nullsub_112
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DAA8

	thumb_func_start sub_814DCCC
sub_814DCCC: @ 814DCCC
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
	bgt _0814DCF8
	adds r0, r2, 0x1
	strh r0, [r1, 0xA]
	b _0814DDB4
	.pool
_0814DCF8:
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldrh r0, [r1, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0814DD18
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0814DD48
_0814DD18:
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
	bl sub_814CC98
	b _0814DD9C
	.pool
_0814DD48:
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
	bl sub_814CC98
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
	bl sub_814CC98
	ldrb r0, [r7]
	eors r0, r6
	strb r0, [r7]
_0814DD9C:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_814B0E8
	str r1, [r0]
	mov r3, r9
	strb r3, [r2]
	mov r0, r8
	bl DestroyTask
_0814DDB4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DCCC

	thumb_func_start sub_814DDD8
sub_814DDD8: @ 814DDD8
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0814DE08
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814DE08
	bl dp01_tbl4_exec_completed
	b _0814DE7C
	.pool
_0814DE08:
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
	beq _0814DE70
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_0814DE70:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_814DE9C
	str r0, [r1]
_0814DE7C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DDD8

	thumb_func_start sub_814DE9C
sub_814DE9C: @ 814DE9C
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
	bls _0814DED4
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl dp01_tbl4_exec_completed
_0814DED4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DE9C

	thumb_func_start sub_814DEE4
sub_814DEE4: @ 814DEE4
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
	beq _0814DF16
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
_0814DF16:
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DEE4

	thumb_func_start sub_814DF34
sub_814DF34: @ 814DF34
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814DF34

	thumb_func_start sub_814DF40
sub_814DF40: @ 814DF40
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _0814DF86
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
_0814DF86:
	bl dp01_tbl4_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DF40

	thumb_func_start sub_814DFA0
sub_814DFA0: @ 814DFA0
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0814E002
	ldr r4, =gBattleBufferA
	ldrb r2, [r5]
	lsls r1, r2, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	adds r0, r4, 0x2
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r4, 0x3
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 8
	orrs r3, r0
	str r3, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	adds r3, r6, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _0814DFF0
	bl dp01_tbl4_exec_completed
	b _0814DFFC
	.pool
_0814DFF0:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_814B7E8
	str r0, [r1]
_0814DFFC:
	adds r0, r6, 0
	bl sub_817E32C
_0814E002:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814DFA0

	thumb_func_start sub_814E014
sub_814E014: @ 814E014
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r1, =gUnknown_02023066
	adds r0, r1
	bl sub_81851A8
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814E014

	thumb_func_start sub_814E034
sub_814E034: @ 814E034
	push {lr}
	bl dp01_tbl4_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_814E034

	thumb_func_start sub_814E040
sub_814E040: @ 814E040
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gUnknown_02023068
	adds r0, r4
	bl sub_81851A8
	ldr r2, =gBattleOutcome
	ldrb r0, [r5]
	lsls r0, 9
	subs r1, r4, 0x3
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldrb r0, [r5]
	lsls r0, 9
	subs r4, 0x2
	adds r0, r4
	ldrb r0, [r0]
	ldr r1, =0x00000ca9
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x5
	bl sub_80A2F50
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl dp01_tbl4_exec_completed
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80587B0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814E040

	thumb_func_start nullsub_113
nullsub_113: @ 814E0C0
	bx lr
	thumb_func_end nullsub_113

	.align 2, 0 @ Don't pad with nop.
