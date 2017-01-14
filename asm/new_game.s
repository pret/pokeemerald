	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start write_word_to_mem
@ void write_word_to_mem(int value, int *mem)
write_word_to_mem: @ 80842CC
	strb r0, [r1]
	lsrs r2, r0, 8
	strb r2, [r1, 0x1]
	lsrs r2, r0, 16
	strb r2, [r1, 0x2]
	lsrs r0, 24
	strb r0, [r1, 0x3]
	bx lr
	thumb_func_end write_word_to_mem

	thumb_func_start sub_80842DC
sub_80842DC: @ 80842DC
	adds r2, r0, 0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	ldrb r1, [r2, 0x2]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	orrs r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	bx lr
	thumb_func_end sub_80842DC

	thumb_func_start sub_80842F4
sub_80842F4: @ 80842F4
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	movs r2, 0
_080842FC:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080842FC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80842F4

	thumb_func_start set_player_trainer_id
set_player_trainer_id: @ 8084310
	push {r4,lr}
	bl GenerateRandomNumber
	adds r4, r0, 0
	bl GetTrainerId
	lsls r4, 16
	lsls r0, 16
	lsrs r0, 16
	orrs r4, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, 0xA
	adds r0, r4, 0
	bl write_word_to_mem
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_player_trainer_id

	thumb_func_start init_options
init_options: @ 808433C
	ldr r3, =gSaveBlock2Ptr
	ldr r2, [r3]
	ldrb r1, [r2, 0x14]
	movs r0, 0x8
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldr r2, [r3]
	ldrb r1, [r2, 0x14]
	movs r0, 0x7
	ands r0, r1
	strb r0, [r2, 0x14]
	ldr r2, [r3]
	ldrb r1, [r2, 0x15]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
	ldr r2, [r3]
	ldrb r1, [r2, 0x15]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
	ldr r2, [r3]
	ldrb r1, [r2, 0x15]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
	ldr r2, [r3]
	ldrb r1, [r2, 0x15]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
	bx lr
	.pool
	thumb_func_end init_options

	thumb_func_start sub_8084390
sub_8084390: @ 8084390
	push {r4,lr}
	ldr r1, =gUnknown_030060B0
	movs r0, 0
	strb r0, [r1]
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0
	movs r2, 0x34
	bl memset
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x34
	bl memset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084390

	thumb_func_start sub_80843C0
sub_80843C0: @ 80843C0
	push {r4-r7,lr}
	bl sub_80DF040
	movs r2, 0x8
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	ldr r4, =0x00002e90
	ldr r3, =gUnknown_08339D1C
_080843D0:
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r2, 5
	adds r0, r1
	adds r0, r4
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5,r6}
	stm r0!, {r5,r6}
	adds r2, 0x1
	cmp r2, 0xC
	ble _080843D0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80843C0

	thumb_func_start sub_8084400
sub_8084400: @ 8084400
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	ldr r0, =0x0000064c
	adds r1, r0
	ldr r2, =0x05000238
	mov r0, sp
	bl CpuSet
	ldr r0, [r4]
	ldr r1, =0x00000ee1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, =0x00000ee9
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084400

	thumb_func_start sub_808444C
sub_808444C: @ 808444C
	push {lr}
	sub sp, 0x4
	movs r3, 0x1
	negs r3, r3
	str r3, [sp]
	movs r0, 0x19
	movs r1, 0x28
	adds r2, r3, 0
	bl warp1_set
	bl warp_in
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808444C

	thumb_func_start init_sav2
init_sav2: @ 808446C
	push {lr}
	bl memclr_stdsav2
	bl init_options
	pop {r0}
	bx r0
	thumb_func_end init_sav2

	thumb_func_start sub_808447C
sub_808447C: @ 808447C
	push {lr}
	ldr r1, =gUnknown_020322D4
	movs r0, 0
	strb r0, [r1]
	bl sub_80BB358
	bl zero_player_party_data
	bl zero_enemy_party_data
	bl sub_81AAB70
	bl sub_813624C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808447C

	thumb_func_start NewGameInitData
@ void NewGameInitData()
NewGameInitData: @ 80844A0
	push {r4,r5,lr}
	ldr r0, =gUnknown_03006210
	ldrh r0, [r0]
	cmp r0, 0
	beq _080844AE
	cmp r0, 0x2
	bne _080844B2
_080844AE:
	bl GameFreakRTC_Reset
_080844B2:
	ldr r1, =gUnknown_020322D4
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	adds r0, 0xAC
	movs r5, 0
	str r5, [r0]
	bl zero_player_party_data
	bl zero_enemy_party_data
	bl sub_80BB2D0
	bl sub_8084400
	bl clear_sav1
	bl sub_80D436C
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	ldr r0, [r4]
	adds r0, 0xA8
	str r5, [r0]
	bl set_player_trainer_id
	bl reset_playtime
	bl sub_8084390
	bl sub_809D300
	bl sub_80EBEE0
	bl GabbyAndTyNewGameInitData
	bl sub_80E8B28
	bl RemoveAllBerryTrees
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r1, =0x00000bb8
	bl EncryptMoney
	movs r0, 0
	bl SetCoins
	bl sub_80D766C
	bl sub_80847A8
	bl sub_80843C0
	bl sub_813C1F8
	bl sub_80F9A7C
	bl sub_80F9AD4
	ldr r0, =gUnknown_020244E9
	strb r5, [r0]
	bl zero_player_party_data
	bl sub_80C7770
	bl sub_8161B34
	bl sub_8161B60
	ldr r0, [r4]
	ldr r1, =0x00000496
	adds r0, r1
	strh r5, [r0]
	bl sub_80D7094
	bl sub_816ADF4
	bl sub_8136E88
	bl sub_81618B4
	bl sub_811F184
	bl sub_8120160
	bl sub_81224D4
	bl sub_813BA10
	bl sub_8177558
	bl sub_808444C
	ldr r0, =gUnknown_082715DE
	bl script_env_2_execute_new_script
	bl sub_80845CC
	bl copy_strings_to_sav1
	bl sub_818DA30
	bl sub_819FAA0
	bl sub_81A4B14
	bl sub_8195E10
	bl sub_801AFD8
	bl sub_800E5AC
	bl sub_81D54BC
	bl sub_80DED74
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end NewGameInitData

	thumb_func_start sub_80845CC
sub_80845CC: @ 80845CC
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	movs r5, 0
	strh r5, [r0]
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	movs r0, 0xF6
	lsls r0, 1
	adds r1, r0
	ldr r6, =0x01000008
	mov r0, sp
	adds r2, r6, 0
	bl CpuSet
	ldr r0, [r4]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_802467C
	bl sub_802E33C
	mov r0, sp
	adds r0, 0x2
	strh r5, [r0]
	ldr r1, [r4]
	movs r2, 0x83
	lsls r2, 2
	adds r1, r2
	adds r2, r6, 0
	bl CpuSet
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80845CC

	.align 2, 0 @ Don't pad with nop.
