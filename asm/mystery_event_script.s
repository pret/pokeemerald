	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81537CC
sub_81537CC: @ 81537CC
	push {r4,lr}
	adds r4, r3, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 16
	lsrs r2, 16
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _081537FC
	ands r1, r3
	cmp r1, 0
	beq _081537FC
	movs r0, 0x4
	ands r2, r0
	cmp r2, 0
	beq _081537FC
	movs r0, 0x80
	lsls r0, 2
	ands r0, r4
	cmp r0, 0
	beq _081537FC
	movs r0, 0x1
	b _081537FE
_081537FC:
	movs r0, 0
_081537FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81537CC

	thumb_func_start sub_8153804
sub_8153804: @ 8153804
	push {lr}
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674C86
	bl StringExpandPlaceholders
	movs r0, 0x3
	bl sub_81538C4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153804

	thumb_func_start sub_8153820
sub_8153820: @ 8153820
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_082DED2C
	ldr r2, =gUnknown_082DED2C + 0x44
	bl script_env_init
	adds r0, r4, 0
	adds r1, r5, 0
	bl script_setup_bytecode_script
	str r5, [r4, 0x64]
	movs r0, 0
	str r0, [r4, 0x68]
	str r0, [r4, 0x6C]
	str r0, [r4, 0x70]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153820

	thumb_func_start sub_8153850
sub_8153850: @ 8153850
	push {r4,lr}
	adds r4, r0, 0
	bl script_main_handler
	lsls r0, 24
	cmp r0, 0
	beq _08153868
	ldr r0, [r4, 0x70]
	cmp r0, 0
	beq _08153868
	movs r0, 0x1
	b _0815386A
_08153868:
	movs r0, 0
_0815386A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8153850

	thumb_func_start sub_8153870
sub_8153870: @ 8153870
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_0203BBC0
	bl sub_8153820
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153870

	thumb_func_start sub_8153884
sub_8153884: @ 8153884
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_0203BBC0
	adds r0, r4, 0
	bl sub_8153850
	ldr r1, [r4, 0x6C]
	str r1, [r5]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153884

	thumb_func_start sub_81538A0
sub_81538A0: @ 81538A0
	push {r4,lr}
	adds r1, r0, 0
	ldr r4, =gUnknown_0203BBC0
	adds r0, r4, 0
	bl sub_8153820
_081538AC:
	adds r0, r4, 0
	bl sub_8153850
	cmp r0, 0
	bne _081538AC
	ldr r0, [r4, 0x6C]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81538A0

	thumb_func_start sub_81538C4
sub_81538C4: @ 81538C4
	ldr r1, =gUnknown_0203BBC0
	str r0, [r1, 0x6C]
	bx lr
	.pool
	thumb_func_end sub_81538C4

	thumb_func_start sub_81538D0
sub_81538D0: @ 81538D0
	push {lr}
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b18
	adds r3, r0, r1
	movs r1, 0
_081538DE:
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r2, r0
	adds r1, 0x1
	cmp r1, 0xB
	bls _081538DE
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81538D0

	thumb_func_start sub_81538F8
sub_81538F8: @ 81538F8
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r1, =0x00003b18
	adds r4, r0, r1
	bl sub_81538D0
	adds r1, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0815392A
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _0815392A
	ldrh r0, [r4, 0x2]
	cmp r0, 0
	beq _0815392A
	cmp r1, 0
	beq _0815392A
	ldr r0, [r5]
	ldr r2, =0x00003b14
	adds r0, r2
	ldr r0, [r0]
	cmp r1, r0
	beq _0815393C
_0815392A:
	movs r0, 0
	b _0815393E
	.pool
_0815393C:
	movs r0, 0x1
_0815393E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81538F8

	thumb_func_start sub_8153944
sub_8153944: @ 8153944
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003b14
	adds r1, r0
	ldr r2, =0x01000008
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153944

	thumb_func_start sub_8153970
sub_8153970: @ 8153970
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	lsls r2, 16
	lsrs r2, 16
	adds r6, r2, 0
	cmp r3, 0
	beq _08153990
	cmp r1, 0
	beq _08153990
	cmp r2, 0
	bne _08153996
_08153990:
	bl sub_8153944
	b _081539BC
_08153996:
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00003b18
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	ldr r2, =0x00003b19
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	adds r1, 0x2
	adds r0, r1
	strh r6, [r0]
	bl sub_81538D0
	ldr r1, [r4]
	ldr r2, =0x00003b14
	adds r1, r2
	str r0, [r1]
_081539BC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153970

	thumb_func_start sub_81539D4
sub_81539D4: @ 81539D4
	push {r4-r6,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r1, =0x00003b18
	adds r4, r0, r1
	bl sub_81538F8
	cmp r0, 0
	bne _081539F8
	bl sub_8153944
	movs r0, 0
	b _08153A1A
	.pool
_081539F8:
	ldrh r5, [r4, 0x2]
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	strb r0, [r4, 0x1]
	lsls r0, 24
	cmp r0, 0
	bne _08153A0C
	bl sub_8153944
	b _08153A18
_08153A0C:
	bl sub_81538D0
	ldr r1, [r6]
	ldr r2, =0x00003b14
	adds r1, r2
	str r0, [r1]
_08153A18:
	adds r0, r5, 0
_08153A1A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81539D4

	thumb_func_start script_status_stop_and_ret_1
script_status_stop_and_ret_1: @ 8153A24
	push {lr}
	bl script_stop
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end script_status_stop_and_ret_1

	thumb_func_start sub_8153A30
sub_8153A30: @ 8153A30
	push {r4-r7,lr}
	adds r7, r0, 0
	bl script_read_word
	str r0, [r7, 0x68]
	adds r0, r7, 0
	bl script_read_halfword
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r7, 0
	bl script_read_word
	adds r6, r0, 0
	adds r0, r7, 0
	bl script_read_halfword
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl script_read_word
	adds r3, r0, 0
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_81537CC
	cmp r0, 0x1
	bne _08153A74
	str r0, [r7, 0x70]
	b _08153A78
_08153A74:
	bl sub_8153804
_08153A78:
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8153A30

	thumb_func_start sub_8153A80
sub_8153A80: @ 8153A80
	movs r0, 0
	bx lr
	thumb_func_end sub_8153A80

	thumb_func_start sub_8153A84
sub_8153A84: @ 8153A84
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	str r2, [r0, 0x6C]
	movs r0, 0
	bx lr
	thumb_func_end sub_8153A84

	thumb_func_start sub_8153A94
sub_8153A94: @ 8153A94
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r5, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_word
	ldr r1, [r4, 0x68]
	subs r0, r1
	ldr r1, [r4, 0x64]
	adds r1, r0, r1
	cmp r5, 0xFF
	beq _08153AB8
	ldr r0, [r4, 0x6C]
	cmp r5, r0
	bne _08153ABE
_08153AB8:
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
_08153ABE:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153A94

	thumb_func_start sub_8153ACC
sub_8153ACC: @ 8153ACC
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	ldr r1, [r4, 0x68]
	subs r0, r1
	ldr r1, [r4, 0x64]
	adds r0, r1
	bl script_env_2_execute_new_script
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8153ACC

	thumb_func_start sub_8153AE8
sub_8153AE8: @ 8153AE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	bl sub_80E162C
	mov r8, r0
	adds r0, r7, 0
	bl script_read_word
	adds r4, r0, 0
	ldr r0, [r7, 0x68]
	subs r4, r0
	ldr r0, [r7, 0x64]
	adds r4, r0
	ldr r0, =gStringVar1
	mov r9, r0
	ldr r6, =gSaveBlock1Ptr
	ldr r1, [r6]
	ldr r5, =0x000031f8
	adds r1, r5
	movs r2, 0x7
	bl StringCopyN
	adds r0, r4, 0
	bl sub_80E15E4
	ldr r4, =gStringVar2
	ldr r1, [r6]
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0x7
	bl StringCopyN
	mov r0, r8
	cmp r0, 0
	bne _08153B54
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674AE4
	b _08153B74
	.pool
_08153B54:
	mov r0, r9
	adds r1, r4, 0
	bl StringCompare
	cmp r0, 0
	beq _08153B70
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674B16
	b _08153B74
	.pool
_08153B70:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674B42
_08153B74:
	bl StringExpandPlaceholders
	movs r0, 0x2
	str r0, [r7, 0x6C]
	bl sub_80E162C
	cmp r0, 0x1
	bne _08153B9C
	ldr r0, =0x0000402d
	movs r1, 0x1
	bl VarSet
	b _08153BA0
	.pool
_08153B9C:
	movs r0, 0x1
	str r0, [r7, 0x6C]
_08153BA0:
	movs r0, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8153AE8

	thumb_func_start sub_8153BB0
sub_8153BB0: @ 8153BB0
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, [r4, 0x8]
	ldrb r0, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	bl sub_80F9B30
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674B6A
	bl StringExpandPlaceholders
	movs r0, 0x2
	str r0, [r4, 0x6C]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153BB0

	thumb_func_start sub_8153BE4
sub_8153BE4: @ 8153BE4
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r4, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r4, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_word
	adds r5, r0, 0
	ldr r0, [r4, 0x68]
	subs r5, r0
	ldr r0, [r4, 0x64]
	adds r5, r0
	adds r0, r4, 0
	bl script_read_word
	adds r1, r0, 0
	ldr r0, [r4, 0x68]
	subs r1, r0
	ldr r0, [r4, 0x64]
	adds r1, r0
	subs r1, r5
	lsls r1, 16
	lsrs r1, 16
	str r6, [sp]
	adds r0, r5, 0
	mov r2, r9
	mov r3, r8
	bl sub_80990FC
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8153BE4

	thumb_func_start sub_8153C4C
sub_8153C4C: @ 8153C4C
	push {r4,lr}
	adds r4, r0, 0
	bl EnableNationalPokedex
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674B9E
	bl StringExpandPlaceholders
	movs r0, 0x2
	str r0, [r4, 0x6C]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153C4C

	thumb_func_start sub_8153C70
sub_8153C70: @ 8153C70
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4, 0x8]
	ldrb r0, [r1]
	adds r1, 0x1
	str r1, [r4, 0x8]
	bl sub_811EFC0
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674BD4
	bl StringExpandPlaceholders
	movs r0, 0x2
	str r0, [r4, 0x6C]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153C70

	thumb_func_start sub_8153C9C
sub_8153C9C: @ 8153C9C
	push {r4,r5,lr}
	ldr r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8153970
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8153C9C

	thumb_func_start sub_8153CC8
sub_8153CC8: @ 8153CC8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x88
	adds r6, r0, 0
	bl script_read_word
	ldr r1, [r6, 0x68]
	subs r0, r1
	ldr r1, [r6, 0x64]
	adds r5, r0, r1
	movs r0, 0x64
	adds r0, r5
	mov r8, r0
	add r4, sp, 0x24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x64
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bne _08153D18
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085E8264
	movs r2, 0xB
	bl StringCopyN
	b _08153D22
	.pool
_08153D18:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085E8268
	movs r2, 0xB
	bl StringCopyN
_08153D22:
	ldr r0, =gUnknown_020244E9
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08153D4C
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674C02
	bl StringExpandPlaceholders
	movs r0, 0x3
	b _08153DB6
	.pool
_08153D4C:
	ldr r7, =gUnknown_020246E0
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x64
	bl memcpy
	mov r0, sp
	mov r1, r8
	movs r2, 0x24
	bl memcpy
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	beq _08153D86
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0x2
	bl pokedex_flag_operation
	adds r0, r4, 0
	movs r1, 0x3
	bl pokedex_flag_operation
_08153D86:
	adds r0, r7, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl itemid_is_mail
	lsls r0, 24
	cmp r0, 0
	beq _08153DA4
	adds r0, r7, 0
	mov r1, sp
	bl sub_80D460C
_08153DA4:
	bl party_compaction
	bl calc_player_party_count
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674BF0
	bl StringExpandPlaceholders
	movs r0, 0x2
_08153DB6:
	str r0, [r6, 0x6C]
	movs r0, 0
	add sp, 0x88
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153CC8

	thumb_func_start sub_8153DD4
sub_8153DD4: @ 8153DD4
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r1, r0, 0
	ldr r0, [r4, 0x68]
	subs r1, r0
	ldr r0, [r4, 0x64]
	adds r1, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000bec
	adds r0, r2
	movs r2, 0xBC
	bl memcpy
	bl sub_81652B4
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_08674C31
	bl StringExpandPlaceholders
	movs r0, 0x2
	str r0, [r4, 0x6C]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153DD4

	thumb_func_start sub_8153E1C
sub_8153E1C: @ 8153E1C
	push {r4,lr}
	adds r4, r0, 0
	bl EnableResetRTC
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085ECAD8
	bl StringExpandPlaceholders
	movs r0, 0x2
	str r0, [r4, 0x6C]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153E1C

	thumb_func_start sub_8153E40
sub_8153E40: @ 8153E40
	push {r4-r6,lr}
	adds r6, r0, 0
	bl script_read_word
	adds r5, r0, 0
	adds r0, r6, 0
	bl script_read_word
	adds r4, r0, 0
	ldr r0, [r6, 0x68]
	subs r4, r0
	ldr r0, [r6, 0x64]
	adds r4, r0
	adds r0, r6, 0
	bl script_read_word
	adds r1, r0, 0
	ldr r0, [r6, 0x68]
	subs r1, r0
	ldr r0, [r6, 0x64]
	adds r1, r0
	subs r1, r4
	adds r0, r4, 0
	bl CalcByteArraySum
	cmp r5, r0
	beq _08153E7E
	movs r0, 0
	str r0, [r6, 0x70]
	movs r0, 0x1
	str r0, [r6, 0x6C]
_08153E7E:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8153E40

	thumb_func_start sub_8153E88
sub_8153E88: @ 8153E88
	push {r4-r6,lr}
	adds r6, r0, 0
	bl script_read_word
	adds r5, r0, 0
	adds r0, r6, 0
	bl script_read_word
	adds r4, r0, 0
	ldr r0, [r6, 0x68]
	subs r4, r0
	ldr r0, [r6, 0x64]
	adds r4, r0
	adds r0, r6, 0
	bl script_read_word
	adds r1, r0, 0
	ldr r0, [r6, 0x68]
	subs r1, r0
	ldr r0, [r6, 0x64]
	adds r1, r0
	subs r1, r4
	adds r0, r4, 0
	bl CalcCRC16
	lsls r0, 16
	lsrs r0, 16
	cmp r5, r0
	beq _08153ECA
	movs r0, 0
	str r0, [r6, 0x70]
	movs r0, 0x1
	str r0, [r6, 0x6C]
_08153ECA:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8153E88

	.align 2, 0 @ Don't pad with nop.
