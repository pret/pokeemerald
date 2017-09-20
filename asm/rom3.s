	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start battle_wireless_setup_if_required_maybe
battle_wireless_setup_if_required_maybe: @ 8032654
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08032686
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803266E
	bl sub_800B488
_0803266E:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803267A
	bl sub_8009734
_0803267A:
	ldr r0, =task00_08081A90
	movs r1, 0
	bl CreateTask
	bl sub_8033244
_08032686:
	pop {r0}
	bx r0
	.pool
	thumb_func_end battle_wireless_setup_if_required_maybe

	thumb_func_start sub_803269C
sub_803269C: @ 803269C
	push {r4-r7,lr}
	sub sp, 0x14
	ldr r0, =gBattleMainFunc
	ldr r1, =nullsub_20
	str r1, [r0]
	movs r0, 0
	str r0, [sp, 0x10]
	movs r1, 0
	ldr r7, =gBattleBankFunc
	ldr r6, =gUnknown_020244AC
	movs r2, 0
	ldr r5, =gUnknown_020244B0
	ldr r4, =nullsub_21
	ldr r3, =gBanksBySide
_080326B8:
	lsls r0, r1, 2
	adds r0, r7
	str r4, [r0]
	adds r1, r3
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	adds r0, r6
	strb r2, [r0]
	ldr r0, [sp, 0x10]
	adds r0, r5
	strb r2, [r0]
	ldr r0, [sp, 0x10]
	adds r0, 0x1
	str r0, [sp, 0x10]
	adds r1, r0, 0
	cmp r1, 0x3
	ble _080326B8
	bl battle_wireless_setup_if_required_maybe
	ldr r0, =gBattleExecBuffer
	movs r5, 0
	str r5, [r0]
	bl sub_80A3934
	bl ClearBattleMonForms
	movs r0, 0xF
	bl BattleAI_HandleItemUseBeforeAISetup
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08032728
	bl ZeroEnemyPartyMons
	ldr r4, =gEnemyParty
	movs r1, 0x90
	lsls r1, 1
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	str r5, [sp, 0xC]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x20
	bl CreateMon
	str r5, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0xC
	add r2, sp, 0x10
	bl SetMonData
_08032728:
	ldr r0, =gUnknown_02022FF4
	str r5, [r0]
	ldr r0, =gUnknown_0202428C
	strb r5, [r0]
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803269C

	thumb_func_start sub_8032768
sub_8032768: @ 8032768
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _08032784
	movs r0, 0x1
	bl sub_8184DA4
	b _0803278A
	.pool
_08032784:
	movs r0, 0x2
	bl sub_8184DA4
_0803278A:
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _0803279C
	bl sub_8185EB8
_0803279C:
	ldr r0, [r4]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080327B0
	bl b_setup_bx_link
	b _080327B4
	.pool
_080327B0:
	bl b_setup_bx
_080327B4:
	bl sub_8033050
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080327E2
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	cmp r4, r1
	bge _080327E2
	adds r5, r0, 0
_080327D0:
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81B8D64
	adds r4, 0x1
	ldrb r0, [r5]
	cmp r4, r0
	blt _080327D0
_080327E2:
	movs r4, 0
	ldr r3, =gBattleStruct
	movs r2, 0xD2
	lsls r2, 1
	movs r1, 0
_080327EC:
	ldr r0, [r3]
	adds r0, r4, r0
	adds r0, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x5F
	bls _080327EC
	movs r4, 0
	ldr r3, =gBattleStruct
	movs r2, 0x81
	lsls r2, 2
	movs r1, 0
_08032804:
	ldr r0, [r3]
	adds r0, r4, r0
	adds r0, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x67
	bls _08032804
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8032768

	thumb_func_start b_setup_bx
b_setup_bx: @ 8032824
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleTypeFlags
	ldr r3, [r0]
	movs r5, 0x80
	lsls r5, 15
	ands r5, r3
	cmp r5, 0
	beq _080328E4
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_8039ECC
	str r0, [r1]
	movs r4, 0x80
	lsls r4, 17
	ands r4, r3
	cmp r4, 0
	beq _08032874
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r0, [r2]
	ldr r1, =gBanksBySide
	movs r0, 0
	strb r0, [r1]
	b _0803287E
	.pool
_08032874:
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
	str r0, [r2]
	ldr r1, =gBanksBySide
	strb r4, [r1]
_0803287E:
	ldr r3, =SetBankFuncToOpponentBufferRunCommand
	str r3, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	ldr r0, =SetBankFuncToPlayerPartnerBufferRunCommand
	str r0, [r2, 0x8]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	str r3, [r2, 0xC]
	movs r0, 0x3
	strb r0, [r1, 0x3]
	ldr r1, =gNoOfAllBanks
	movs r0, 0x4
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	bl sub_81B8D64
	movs r0, 0x1
	movs r1, 0
	bl sub_81B8D64
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81B8D64
	movs r0, 0x3
	movs r1, 0x1
	bl sub_81B8D64
	ldr r0, =gBattlePartyID
	movs r1, 0
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x3
	b _08032A76
	.pool
_080328E4:
	movs r7, 0x1
	adds r0, r3, 0
	ands r0, r7
	cmp r0, 0
	beq _080328F0
	b _080329E0
_080328F0:
	ldr r0, =gBattleMainFunc
	ldr r2, =sub_8039ECC
	str r2, [r0]
	movs r1, 0x80
	ands r1, r3
	mov r12, r2
	cmp r1, 0
	beq _08032918
	ldr r1, =gBattleBankFunc
	ldr r0, =SetBankFuncToSafariBufferRunCommand
	b _08032934
	.pool
_08032918:
	movs r0, 0x80
	lsls r0, 2
	ands r3, r0
	cmp r3, 0
	beq _08032930
	ldr r1, =gBattleBankFunc
	ldr r0, =SetBankFuncToWallyBufferRunCommand
	b _08032934
	.pool
_08032930:
	ldr r1, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
_08032934:
	str r0, [r1]
	mov r10, r1
	ldr r4, =gBanksBySide
	movs r0, 0
	mov r9, r0
	mov r1, r9
	strb r1, [r4]
	mov r5, r10
	ldr r2, =SetBankFuncToOpponentBufferRunCommand
	mov r8, r2
	str r2, [r5, 0x4]
	movs r6, 0x1
	strb r6, [r4, 0x1]
	ldr r2, =gNoOfAllBanks
	movs r7, 0x2
	strb r7, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r3, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r3
	cmp r0, 0
	bne _08032964
	b _08032CB2
_08032964:
	movs r1, 0x80
	lsls r1, 18
	ands r1, r3
	cmp r1, 0
	beq _080329CC
	movs r1, 0x80
	lsls r1, 24
	ands r1, r3
	cmp r1, 0
	beq _080329B4
	mov r1, r12
	ldr r0, =gBattleMainFunc
	str r1, [r0]
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r0, [r5]
	mov r1, r9
	strb r1, [r4]
	ldr r0, =SetBankFuncToRecordedOpponentBufferRunCommand
	str r0, [r5, 0x4]
	strb r6, [r4, 0x1]
	strb r7, [r2]
	b _08032CB2
	.pool
_080329B4:
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r0, [r5, 0x4]
	strb r1, [r4, 0x1]
	ldr r0, =SetBankFuncToRecordedOpponentBufferRunCommand
	str r0, [r5]
	strb r6, [r4]
	strb r7, [r2]
	b _08032CB2
	.pool
_080329CC:
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	mov r2, r10
	str r0, [r2]
	strb r1, [r4]
	mov r0, r8
	str r0, [r2, 0x4]
	strb r6, [r4, 0x1]
	b _08032CB2
	.pool
_080329E0:
	ldr r1, =sub_8039ECC
	ldr r2, =gBattleMainFunc
	str r1, [r2]
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
	str r0, [r2]
	ldr r4, =gBanksBySide
	strb r5, [r4]
	ldr r6, =SetBankFuncToOpponentBufferRunCommand
	str r6, [r2, 0x4]
	strb r7, [r4, 0x1]
	str r0, [r2, 0x8]
	movs r0, 0x2
	mov r12, r0
	mov r1, r12
	strb r1, [r4, 0x2]
	str r6, [r2, 0xC]
	movs r0, 0x3
	mov r8, r0
	mov r1, r8
	strb r1, [r4, 0x3]
	ldr r0, =gNoOfAllBanks
	mov r10, r0
	movs r1, 0x4
	mov r9, r1
	strb r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r3
	cmp r0, 0
	bne _08032A20
	b _08032CB2
_08032A20:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, r1
	bne _08032AA0
	ldr r0, =sub_8039ECC
	ldr r1, =gBattleMainFunc
	str r0, [r1]
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r0, [r2]
	strb r5, [r4]
	str r6, [r2, 0x4]
	strb r7, [r4, 0x1]
	str r0, [r2, 0x8]
	mov r0, r12
	strb r0, [r4, 0x2]
	str r6, [r2, 0xC]
	mov r1, r8
	strb r1, [r4, 0x3]
	mov r0, r9
	mov r2, r10
	strb r0, [r2]
	movs r0, 0
	movs r1, 0
	bl sub_81B8D64
	movs r0, 0x1
	movs r1, 0
	bl sub_81B8D64
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81B8D64
	movs r0, 0x3
	movs r1, 0x1
	bl sub_81B8D64
	ldr r0, =gBattlePartyID
	strh r5, [r0]
	strh r5, [r0, 0x2]
	mov r1, r8
_08032A76:
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	b _08032CB2
	.pool
_08032AA0:
	movs r5, 0x40
	ands r5, r3
	cmp r5, 0
	bne _08032AAA
	b _08032C3C
_08032AAA:
	ldr r0, =gUnknown_0203C7B4
	ldrb r5, [r0]
	movs r0, 0
	mov r10, r0
	ldr r1, =gLinkPlayers
	mov r12, r1
	adds r7, r4, 0
	mov r8, r0
	ldr r6, =gBattlePartyID
	movs r4, 0
	movs r2, 0x3
	mov r9, r2
_08032AC2:
	mov r1, r12
	adds r0, r4, r1
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _08032AE4
	cmp r0, 0x1
	bge _08032AFC
	cmp r0, 0
	beq _08032AE8
	b _08032B06
	.pool
_08032AE4:
	cmp r0, 0x3
	bne _08032B06
_08032AE8:
	ldr r0, =gLinkPlayers
	adds r0, r4, r0
	ldrb r0, [r0, 0x18]
	movs r1, 0
	bl sub_81B8D64
	b _08032B06
	.pool
_08032AFC:
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81B8D64
_08032B06:
	cmp r10, r5
	bne _08032B56
	ldr r0, =gLinkPlayers
	adds r3, r4, r0
	ldrh r1, [r3, 0x18]
	lsls r1, 2
	ldr r2, =gBattleBankFunc
	adds r1, r2
	ldr r2, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r2, [r1]
	ldrh r1, [r3, 0x18]
	mov r12, r0
	cmp r1, 0x2
	bgt _08032B38
	cmp r1, 0x1
	bge _08032B4C
	cmp r1, 0
	beq _08032B3C
	b _08032C2C
	.pool
_08032B38:
	cmp r1, 0x3
	bne _08032C2C
_08032B3C:
	mov r1, r12
	adds r0, r4, r1
	ldrh r1, [r0, 0x18]
	adds r1, r7
	mov r2, r8
	strb r2, [r1]
	ldrh r0, [r0, 0x18]
	b _08032C12
_08032B4C:
	adds r1, r7
	movs r0, 0x2
	strb r0, [r1]
	ldrh r0, [r3, 0x18]
	b _08032C24
_08032B56:
	ldr r2, =gLinkPlayers
	adds r0, r4, r2
	ldrh r1, [r0, 0x18]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	mov r12, r2
	cmp r0, 0
	bne _08032B80
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r12
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08032B92
	b _08032BD8
	.pool
_08032B80:
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r12
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08032BD8
_08032B92:
	mov r0, r12
	adds r2, r4, r0
	ldrh r0, [r2, 0x18]
	lsls r0, 2
	ldr r1, =gBattleBankFunc
	adds r0, r1
	ldr r1, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r1, [r0]
	ldrh r1, [r2, 0x18]
	cmp r1, 0x2
	bgt _08032BBC
	cmp r1, 0x1
	bge _08032BD0
	cmp r1, 0
	beq _08032BC0
	b _08032C2C
	.pool
_08032BBC:
	cmp r1, 0x3
	bne _08032C2C
_08032BC0:
	mov r2, r12
	adds r0, r4, r2
	ldrh r1, [r0, 0x18]
	adds r1, r7
	mov r2, r8
	strb r2, [r1]
	ldrh r0, [r0, 0x18]
	b _08032C12
_08032BD0:
	adds r1, r7
	movs r0, 0x2
	strb r0, [r1]
	b _08032C22
_08032BD8:
	mov r0, r12
	adds r2, r4, r0
	ldrh r0, [r2, 0x18]
	lsls r0, 2
	ldr r1, =gBattleBankFunc
	adds r0, r1
	ldr r1, =SetBankFuncToRecordedOpponentBufferRunCommand
	str r1, [r0]
	ldrh r0, [r2, 0x18]
	cmp r0, 0x2
	bgt _08032C00
	cmp r0, 0x1
	bge _08032C1C
	cmp r0, 0
	beq _08032C04
	b _08032C2C
	.pool
_08032C00:
	cmp r0, 0x3
	bne _08032C2C
_08032C04:
	mov r0, r12
	adds r2, r4, r0
	ldrh r0, [r2, 0x18]
	adds r0, r7
	movs r1, 0x1
	strb r1, [r0]
	ldrh r0, [r2, 0x18]
_08032C12:
	lsls r0, 1
	adds r0, r6
	mov r1, r8
	strh r1, [r0]
	b _08032C2C
_08032C1C:
	adds r0, r7
	mov r1, r9
	strb r1, [r0]
_08032C22:
	ldrh r0, [r2, 0x18]
_08032C24:
	lsls r0, 1
	adds r0, r6
	mov r2, r9
	strh r2, [r0]
_08032C2C:
	adds r4, 0x1C
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x3
	bgt _08032C3A
	b _08032AC2
_08032C3A:
	b _08032CB2
_08032C3C:
	movs r1, 0x4
	ands r1, r3
	cmp r1, 0
	beq _08032C7C
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r0, [r2]
	strb r5, [r4]
	str r0, [r2, 0x8]
	mov r0, r12
	strb r0, [r4, 0x2]
	movs r0, 0x80
	lsls r0, 18
	ands r3, r0
	cmp r3, 0
	beq _08032C70
	ldr r0, =SetBankFuncToRecordedOpponentBufferRunCommand
	str r0, [r2, 0x4]
	strb r7, [r4, 0x1]
	str r0, [r2, 0xC]
	mov r1, r8
	strb r1, [r4, 0x3]
	b _08032CB2
	.pool
_08032C70:
	str r6, [r2, 0x4]
	strb r7, [r4, 0x1]
	str r6, [r2, 0xC]
	mov r2, r8
	strb r2, [r4, 0x3]
	b _08032CB2
_08032C7C:
	ldr r0, =SetBankFuncToRecordedPlayerBufferRunCommand
	str r0, [r2, 0x4]
	strb r1, [r4, 0x1]
	str r0, [r2, 0xC]
	mov r0, r12
	strb r0, [r4, 0x3]
	movs r0, 0x80
	lsls r0, 18
	ands r3, r0
	cmp r3, 0
	beq _08032CA8
	ldr r0, =SetBankFuncToRecordedOpponentBufferRunCommand
	str r0, [r2]
	strb r7, [r4]
	str r0, [r2, 0x8]
	mov r1, r8
	strb r1, [r4, 0x2]
	b _08032CB2
	.pool
_08032CA8:
	str r6, [r2]
	strb r7, [r4]
	str r6, [r2, 0x8]
	mov r2, r8
	strb r2, [r4, 0x2]
_08032CB2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end b_setup_bx

	thumb_func_start b_setup_bx_link
b_setup_bx_link: @ 8032CC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, =gBattleTypeFlags
	ldr r1, [r4]
	movs r5, 0x1
	adds r3, r1, 0
	ands r3, r5
	cmp r3, 0
	bne _08032D48
	movs r4, 0x4
	ands r4, r1
	cmp r4, 0
	beq _08032D1C
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_8039ECC
	str r0, [r1]
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
	str r0, [r2]
	ldr r1, =gBanksBySide
	strb r3, [r1]
	ldr r0, =SetBankFuncToLinkOpponentBufferRunCommand
	str r0, [r2, 0x4]
	strb r5, [r1, 0x1]
	ldr r1, =gNoOfAllBanks
	movs r0, 0x2
	b _0803303A
	.pool
_08032D1C:
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
	str r0, [r2, 0x4]
	ldr r1, =gBanksBySide
	strb r4, [r1, 0x1]
	ldr r0, =SetBankFuncToLinkOpponentBufferRunCommand
	str r0, [r2]
	strb r5, [r1]
	ldr r1, =gNoOfAllBanks
	movs r0, 0x2
	b _0803303A
	.pool
_08032D48:
	movs r0, 0x41
	ands r0, r1
	cmp r0, 0x1
	bne _08032DD0
	movs r6, 0x4
	adds r3, r6, 0
	ands r3, r1
	cmp r3, 0
	beq _08032D98
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_8039ECC
	str r0, [r1]
	ldr r2, =gBattleBankFunc
	ldr r4, =SetBankFuncToPlayerBufferRunCommand
	str r4, [r2]
	ldr r1, =gBanksBySide
	movs r0, 0
	strb r0, [r1]
	ldr r3, =SetBankFuncToLinkOpponentBufferRunCommand
	str r3, [r2, 0x4]
	strb r5, [r1, 0x1]
	str r4, [r2, 0x8]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	str r3, [r2, 0xC]
	movs r0, 0x3
	strb r0, [r1, 0x3]
	b _08032DB4
	.pool
_08032D98:
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
	str r0, [r2, 0x4]
	ldr r1, =gBanksBySide
	strb r3, [r1, 0x1]
	ldr r3, =SetBankFuncToLinkOpponentBufferRunCommand
	str r3, [r2]
	strb r5, [r1]
	str r0, [r2, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0x3]
	str r3, [r2, 0x8]
	movs r0, 0x3
	strb r0, [r1, 0x2]
_08032DB4:
	ldr r0, =gNoOfAllBanks
	strb r6, [r0]
	b _0803303C
	.pool
_08032DD0:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08032E8C
	movs r4, 0x4
	adds r3, r4, 0
	ands r3, r1
	cmp r3, 0
	beq _08032E1C
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_8039ECC
	str r0, [r1]
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
	str r0, [r2]
	ldr r1, =gBanksBySide
	movs r0, 0
	strb r0, [r1]
	ldr r3, =SetBankFuncToOpponentBufferRunCommand
	str r3, [r2, 0x4]
	strb r5, [r1, 0x1]
	ldr r0, =SetBankFuncToLinkPartnerBufferRunCommand
	b _08032E2E
	.pool
_08032E1C:
	ldr r2, =gBattleBankFunc
	ldr r0, =SetBankFuncToLinkPartnerBufferRunCommand
	str r0, [r2]
	ldr r1, =gBanksBySide
	strb r3, [r1]
	ldr r3, =SetBankFuncToLinkOpponentBufferRunCommand
	str r3, [r2, 0x4]
	strb r5, [r1, 0x1]
	ldr r0, =SetBankFuncToPlayerBufferRunCommand
_08032E2E:
	str r0, [r2, 0x8]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	str r3, [r2, 0xC]
	movs r0, 0x3
	strb r0, [r1, 0x3]
	ldr r0, =gNoOfAllBanks
	strb r4, [r0]
	movs r0, 0
	movs r1, 0
	bl sub_81B8D64
	movs r0, 0x1
	movs r1, 0
	bl sub_81B8D64
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81B8D64
	movs r0, 0x3
	movs r1, 0x1
	bl sub_81B8D64
	ldr r0, =gBattlePartyID
	movs r1, 0
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x3
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	b _0803303C
	.pool
_08032E8C:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r4]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08032EA4
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_8039ECC
	str r0, [r1]
_08032EA4:
	movs r0, 0
	mov r10, r0
	ldr r1, =gLinkPlayers
	mov r12, r1
	ldr r7, =gBanksBySide
	mov r8, r0
	ldr r6, =gBattlePartyID
	movs r4, 0
	movs r2, 0x3
	mov r9, r2
_08032EB8:
	mov r1, r12
	adds r0, r4, r1
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _08032EE0
	cmp r0, 0x1
	bge _08032EF8
	cmp r0, 0
	beq _08032EE4
	b _08032F02
	.pool
_08032EE0:
	cmp r0, 0x3
	bne _08032F02
_08032EE4:
	ldr r0, =gLinkPlayers
	adds r0, r4, r0
	ldrb r0, [r0, 0x18]
	movs r1, 0
	bl sub_81B8D64
	b _08032F02
	.pool
_08032EF8:
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81B8D64
_08032F02:
	cmp r10, r5
	bne _08032F52
	ldr r0, =gLinkPlayers
	adds r3, r4, r0
	ldrh r1, [r3, 0x18]
	lsls r1, 2
	ldr r2, =gBattleBankFunc
	adds r1, r2
	ldr r2, =SetBankFuncToPlayerBufferRunCommand
	str r2, [r1]
	ldrh r1, [r3, 0x18]
	mov r12, r0
	cmp r1, 0x2
	bgt _08032F34
	cmp r1, 0x1
	bge _08032F48
	cmp r1, 0
	beq _08032F38
	b _08033028
	.pool
_08032F34:
	cmp r1, 0x3
	bne _08033028
_08032F38:
	mov r1, r12
	adds r0, r4, r1
	ldrh r1, [r0, 0x18]
	adds r1, r7
	mov r2, r8
	strb r2, [r1]
	ldrh r0, [r0, 0x18]
	b _0803300E
_08032F48:
	adds r1, r7
	movs r0, 0x2
	strb r0, [r1]
	ldrh r0, [r3, 0x18]
	b _08033020
_08032F52:
	ldr r2, =gLinkPlayers
	adds r0, r4, r2
	ldrh r1, [r0, 0x18]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	mov r12, r2
	cmp r0, 0
	bne _08032F7C
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r12
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08032F8E
	b _08032FD4
	.pool
_08032F7C:
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r12
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08032FD4
_08032F8E:
	mov r0, r12
	adds r2, r4, r0
	ldrh r0, [r2, 0x18]
	lsls r0, 2
	ldr r1, =gBattleBankFunc
	adds r0, r1
	ldr r1, =SetBankFuncToLinkPartnerBufferRunCommand
	str r1, [r0]
	ldrh r1, [r2, 0x18]
	cmp r1, 0x2
	bgt _08032FB8
	cmp r1, 0x1
	bge _08032FCC
	cmp r1, 0
	beq _08032FBC
	b _08033028
	.pool
_08032FB8:
	cmp r1, 0x3
	bne _08033028
_08032FBC:
	mov r2, r12
	adds r0, r4, r2
	ldrh r1, [r0, 0x18]
	adds r1, r7
	mov r2, r8
	strb r2, [r1]
	ldrh r0, [r0, 0x18]
	b _0803300E
_08032FCC:
	adds r1, r7
	movs r0, 0x2
	strb r0, [r1]
	b _0803301E
_08032FD4:
	mov r0, r12
	adds r2, r4, r0
	ldrh r0, [r2, 0x18]
	lsls r0, 2
	ldr r1, =gBattleBankFunc
	adds r0, r1
	ldr r1, =SetBankFuncToLinkOpponentBufferRunCommand
	str r1, [r0]
	ldrh r0, [r2, 0x18]
	cmp r0, 0x2
	bgt _08032FFC
	cmp r0, 0x1
	bge _08033018
	cmp r0, 0
	beq _08033000
	b _08033028
	.pool
_08032FFC:
	cmp r0, 0x3
	bne _08033028
_08033000:
	mov r0, r12
	adds r2, r4, r0
	ldrh r0, [r2, 0x18]
	adds r0, r7
	movs r1, 0x1
	strb r1, [r0]
	ldrh r0, [r2, 0x18]
_0803300E:
	lsls r0, 1
	adds r0, r6
	mov r1, r8
	strh r1, [r0]
	b _08033028
_08033018:
	adds r0, r7
	mov r1, r9
	strb r1, [r0]
_0803301E:
	ldrh r0, [r2, 0x18]
_08033020:
	lsls r0, 1
	adds r0, r6
	mov r2, r9
	strh r2, [r0]
_08033028:
	adds r4, 0x1C
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x3
	bgt _08033036
	b _08032EB8
_08033036:
	ldr r1, =gNoOfAllBanks
	movs r0, 0x4
_0803303A:
	strb r0, [r1]
_0803303C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_setup_bx_link

	thumb_func_start sub_8033050
sub_8033050: @ 8033050
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08033068
	b _0803319C
_08033068:
	movs r0, 0
	mov r8, r0
	b _0803317A
	.pool
_08033074:
	movs r5, 0
	movs r0, 0x1
	add r0, r8
	mov r10, r0
	ldr r0, =gBanksBySide
	add r0, r8
	mov r9, r0
	mov r0, r8
	lsls r6, r0, 1
	movs r7, 0
_08033088:
	mov r0, r8
	cmp r0, 0x1
	bgt _080330F0
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080330A8
	ldr r0, =gPlayerParty
	b _080330AA
	.pool
_080330A8:
	ldr r0, =gEnemyParty
_080330AA:
	adds r4, r7, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08033170
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08033170
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08033170
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _08033170
	ldr r0, =gBattlePartyID
	adds r0, r6, r0
	strh r5, [r0]
	b _08033178
	.pool
_080330F0:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08033118
	ldr r0, =gPlayerParty
	adds r4, r7, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08033170
	adds r0, r4, 0
	movs r1, 0xB
	b _0803312C
	.pool
_08033118:
	ldr r0, =gEnemyParty
	adds r4, r7, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08033170
	adds r0, r4, 0
	movs r1, 0x41
_0803312C:
	bl GetMonData
	cmp r0, 0
	beq _08033170
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08033170
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _08033170
	ldr r1, =gBattlePartyID
	mov r0, r8
	subs r0, 0x2
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	beq _08033170
	adds r0, r6, r1
	strh r5, [r0]
	b _08033178
	.pool
_08033170:
	adds r7, 0x64
	adds r5, 0x1
	cmp r5, 0x5
	ble _08033088
_08033178:
	mov r8, r10
_0803317A:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r8, r0
	bge _08033184
	b _08033074
_08033184:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0803319C
	ldr r0, =gBattlePartyID
	movs r1, 0
	strh r1, [r0, 0x2]
	movs r1, 0x3
	strh r1, [r0, 0x6]
_0803319C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033050

	thumb_func_start dp01_prepare_buffer
dp01_prepare_buffer: @ 80331B8
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r3, r0, 24
	adds r5, r3, 0
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080331E4
	adds r0, r3, 0
	adds r1, r2, 0
	adds r2, r4, 0
	bl PrepareBufferDataTransferLink
	b _08033236
	.pool
_080331E4:
	cmp r5, 0
	beq _080331EE
	cmp r5, 0x1
	beq _08033218
	b _08033236
_080331EE:
	movs r3, 0
	cmp r3, r2
	bge _08033236
	ldr r6, =gBattleBufferA
	ldr r5, =gActiveBank
_080331F8:
	ldrb r0, [r5]
	lsls r0, 9
	adds r0, r3, r0
	adds r0, r6
	ldrb r1, [r4]
	strb r1, [r0]
	adds r4, 0x1
	adds r3, 0x1
	cmp r3, r2
	blt _080331F8
	b _08033236
	.pool
_08033218:
	movs r3, 0
	cmp r3, r2
	bge _08033236
	ldr r6, =gBattleBufferB
	ldr r5, =gActiveBank
_08033222:
	ldrb r0, [r5]
	lsls r0, 9
	adds r0, r3, r0
	adds r0, r6
	ldrb r1, [r4]
	strb r1, [r0]
	adds r4, 0x1
	adds r3, 0x1
	cmp r3, r2
	blt _08033222
_08033236:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_prepare_buffer

	thumb_func_start sub_8033244
sub_8033244: @ 8033244
	push {r4-r6,lr}
	ldr r0, =task00_wireless_something
	movs r1, 0
	bl CreateTask
	ldr r2, =gUnknown_02022D08
	strb r0, [r2]
	ldr r5, =gTasks
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r6, 0
	movs r4, 0
	strh r4, [r0, 0x1E]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x20]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x22]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x24]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x26]
	ldr r0, =sub_803375C
	movs r1, 0
	bl CreateTask
	ldr r2, =gUnknown_02022D09
	strb r0, [r2]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x20]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x22]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x24]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r4, [r0, 0x26]
	ldr r0, =gUnknown_02022D0A
	strb r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033244

	thumb_func_start PrepareBufferDataTransferLink
PrepareBufferDataTransferLink: @ 80332F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r2
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	movs r1, 0x3
	mov r0, r12
	bics r0, r1
	adds r0, 0x4
	mov r8, r0
	ldr r2, =gTasks
	ldr r3, =gUnknown_02022D08
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r4, r0, r2
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	add r0, r8
	adds r0, 0x9
	movs r1, 0x80
	lsls r1, 5
	adds r5, r2, 0
	cmp r0, r1
	ble _08033346
	ldrh r0, [r4, 0x24]
	movs r2, 0
	strh r0, [r4, 0x20]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0x24]
_08033346:
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0x24
	ldrsh r1, [r0, r2]
	ldr r4, =gUnknown_020244A0
	ldr r0, [r4]
	adds r0, r1
	strb r6, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r7, 0x24
	ldrsh r1, [r0, r7]
	ldr r0, [r4]
	adds r1, r0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0x24
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	adds r1, r0
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r7, 0x24
	ldrsh r1, [r0, r7]
	ldr r0, [r4]
	adds r1, r0
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r1, 0x3]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	ldr r1, [r4]
	adds r0, r1
	mov r2, r8
	strb r2, [r0, 0x4]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r7, 0x24
	ldrsh r1, [r0, r7]
	ldr r0, [r4]
	adds r1, r0
	movs r0, 0xFF
	lsls r0, 8
	mov r2, r8
	ands r0, r2
	asrs r0, 8
	strb r0, [r1, 0x5]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r7, 0x24
	ldrsh r1, [r0, r7]
	ldr r0, [r4]
	adds r1, r0
	ldr r0, =gAbsentBankFlags
	ldrb r0, [r0]
	strb r0, [r1, 0x6]
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r2, 0x24
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	adds r1, r0
	ldr r0, =gEffectBank
	ldrb r0, [r0]
	strb r0, [r1, 0x7]
	movs r2, 0
	cmp r2, r12
	bge _08033434
	mov r10, r5
	adds r6, r3, 0
_08033412:
	ldrb r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	add r0, r10
	movs r7, 0x24
	ldrsh r1, [r0, r7]
	ldr r0, [r4]
	adds r1, r2, r1
	adds r1, r0
	mov r7, r9
	adds r0, r7, r2
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	adds r2, 0x1
	cmp r2, r12
	blt _08033412
_08033434:
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldrh r0, [r1, 0x24]
	add r0, r8
	adds r0, 0x8
	strh r0, [r1, 0x24]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrepareBufferDataTransferLink

	thumb_func_start task00_wireless_something
task00_wireless_something: @ 8033474
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x1E
	ldrsh r0, [r0, r2]
	adds r7, r1, 0
	cmp r0, 0x5
	bls _08033490
	b _08033640
_08033490:
	lsls r0, 2
	ldr r1, =_080334A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080334A4:
	.4byte _080334BC
	.4byte _080334CA
	.4byte _080334E6
	.4byte _08033570
	.4byte _080335E6
	.4byte _08033624
_080334BC:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r7
	movs r1, 0x64
	strh r1, [r0, 0x1C]
	b _080334F6
_080334CA:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r7
	ldrh r0, [r1, 0x1C]
	subs r0, 0x1
	strh r0, [r1, 0x1C]
	lsls r0, 16
	cmp r0, 0
	beq _080334E0
	b _08033640
_080334E0:
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	b _0803363E
_080334E6:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _08033504
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r7
_080334F6:
	ldrh r1, [r0, 0x1E]
	adds r1, 0x1
	strh r1, [r0, 0x1E]
	b _08033640
	.pool
_08033504:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0803351C
	movs r5, 0x2
	b _0803352A
	.pool
_0803351C:
	movs r0, 0x40
	ands r1, r0
	movs r0, 0x2
	cmp r1, 0
	beq _08033528
	movs r0, 0x4
_08033528:
	adds r5, r0, 0
_0803352A:
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bcs _08033538
	b _08033640
_08033538:
	bl sub_800ABBC
	lsls r0, 24
	cmp r0, 0
	beq _0803355C
	bl sub_800A620
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	b _0803363E
	.pool
_0803355C:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	b _0803363E
	.pool
_08033570:
	lsls r1, r4, 2
	adds r0, r1, r4
	lsls r0, 3
	adds r2, r0, r7
	movs r3, 0x26
	ldrsh r5, [r2, r3]
	movs r0, 0x24
	ldrsh r6, [r2, r0]
	mov r12, r6
	cmp r5, r12
	beq _08033640
	ldrh r0, [r2, 0x22]
	movs r6, 0x22
	ldrsh r3, [r2, r6]
	cmp r3, 0
	bne _080335E0
	cmp r5, r12
	ble _080335A0
	movs r6, 0x20
	ldrsh r0, [r2, r6]
	cmp r5, r0
	bne _080335A0
	strh r3, [r2, 0x20]
	strh r3, [r2, 0x26]
_080335A0:
	adds r4, r1, r4
	lsls r4, 3
	adds r4, r7
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	ldr r5, =gUnknown_020244A0
	ldr r0, [r5]
	adds r1, r0
	ldrb r0, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	lsls r1, 8
	orrs r0, r1
	adds r0, 0x8
	lsls r0, 16
	lsrs r6, r0, 16
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x26
	ldrsh r2, [r4, r1]
	ldr r1, [r5]
	adds r1, r2
	adds r2, r6, 0
	bl link_0800A448
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	b _08033640
	.pool
_080335E0:
	subs r0, 0x1
	strh r0, [r2, 0x22]
	b _08033640
_080335E6:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08033640
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	ldr r0, =gUnknown_020244A0
	ldr r0, [r0]
	adds r2, r0
	ldrb r0, [r2, 0x4]
	ldrb r2, [r2, 0x5]
	lsls r2, 8
	movs r3, 0x1
	strh r3, [r1, 0x22]
	orrs r0, r2
	ldrh r6, [r1, 0x26]
	adds r0, r6
	adds r0, 0x8
	strh r0, [r1, 0x26]
	b _0803363C
	.pool
_08033624:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r7
	ldrh r0, [r1, 0x22]
	subs r0, 0x1
	strh r0, [r1, 0x22]
	lsls r0, 16
	cmp r0, 0
	bne _08033640
	movs r0, 0x1
	strh r0, [r1, 0x22]
_0803363C:
	movs r0, 0x3
_0803363E:
	strh r0, [r1, 0x1E]
_08033640:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end task00_wireless_something

	thumb_func_start sub_8033648
sub_8033648: @ 8033648
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _08033738
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08033738
	bl sub_8011BD0
	movs r4, 0
	ldr r0, =gUnknown_020223C4
	mov r10, r0
	b _0803372C
	.pool
_08033680:
	bl sub_800A550
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBitTable
	lsls r1, r4, 2
	adds r1, r2
	ldr r1, [r1]
	ands r0, r1
	adds r1, r4, 0x1
	mov r9, r1
	cmp r0, 0
	beq _08033726
	adds r0, r4, 0
	bl sub_800A5EC
	lsls r0, r4, 8
	mov r4, r10
	adds r3, r0, r4
	ldr r1, =gUnknown_020223C8
	adds r0, r1
	ldrh r6, [r0]
	ldr r7, =gTasks
	ldr r4, =gUnknown_02022D09
	mov r12, r4
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, r0, r7
	movs r0, 0x24
	ldrsh r1, [r2, r0]
	adds r0, r6, 0
	adds r0, 0x9
	adds r1, r0
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	ble _080336E0
	ldrh r0, [r2, 0x24]
	strh r0, [r2, 0x20]
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0
	strh r1, [r0, 0x24]
_080336E0:
	ldr r2, =gUnknown_020244A4
	mov r4, r12
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r4, 0x24
	ldrsh r1, [r0, r4]
	ldr r0, [r2]
	adds r5, r0, r1
	adds r4, r3, 0
	movs r2, 0
	adds r3, r6, 0
	adds r3, 0x8
	mov r8, r7
	mov r7, r12
	cmp r2, r3
	bge _08033714
_08033706:
	adds r0, r5, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r3
	blt _08033706
_08033714:
	ldrb r0, [r7]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	add r1, r8
	ldrh r0, [r1, 0x24]
	adds r0, r6, r0
	adds r0, 0x8
	strh r0, [r1, 0x24]
_08033726:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r4, r0, 24
_0803372C:
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _08033680
_08033738:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033648

	thumb_func_start sub_803375C
sub_803375C: @ 803375C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r3, r0, r1
	movs r0, 0x26
	ldrsh r2, [r3, r0]
	movs r4, 0x24
	ldrsh r0, [r3, r4]
	cmp r2, r0
	bne _08033780
	b _0803389C
_08033780:
	cmp r2, r0
	ble _08033792
	movs r4, 0x20
	ldrsh r0, [r3, r4]
	cmp r2, r0
	bne _08033792
	movs r0, 0
	strh r0, [r3, 0x20]
	strh r0, [r3, 0x26]
_08033792:
	lsls r2, r7, 2
	adds r0, r2, r7
	lsls r0, 3
	adds r5, r0, r1
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	ldr r3, =gUnknown_020244A4
	mov r8, r3
	ldr r0, [r3]
	adds r3, r1, r0
	ldrb r4, [r3, 0x1]
	ldrb r6, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	lsls r0, 8
	orrs r6, r0
	ldrb r0, [r3]
	mov r9, r2
	cmp r0, 0x1
	beq _0803385C
	cmp r0, 0x1
	bgt _080337CC
	cmp r0, 0
	beq _080337D2
	b _0803388A
	.pool
_080337CC:
	cmp r0, 0x2
	beq _08033874
	b _0803388A
_080337D2:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r4, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803389C
	lsls r0, r4, 9
	ldr r1, =gBattleBufferA
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x8
	adds r2, r6, 0
	bl memcpy
	adds r0, r4, 0
	bl sub_803F850
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0803388A
	ldr r2, =gBankAttacker
	movs r4, 0x26
	ldrsh r0, [r5, r4]
	mov r3, r8
	ldr r1, [r3]
	adds r0, r1
	ldrb r0, [r0, 0x2]
	strb r0, [r2]
	ldr r2, =gBankTarget
	movs r4, 0x26
	ldrsh r0, [r5, r4]
	adds r0, r1
	ldrb r0, [r0, 0x3]
	strb r0, [r2]
	ldr r2, =gAbsentBankFlags
	movs r3, 0x26
	ldrsh r0, [r5, r3]
	adds r0, r1
	ldrb r0, [r0, 0x6]
	strb r0, [r2]
	ldr r2, =gEffectBank
	movs r4, 0x26
	ldrsh r0, [r5, r4]
	adds r0, r1
	ldrb r0, [r0, 0x7]
	strb r0, [r2]
	b _0803388A
	.pool
_0803385C:
	lsls r0, r4, 9
	ldr r1, =gBattleBufferB
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x8
	adds r2, r6, 0
	bl memcpy
	b _0803388A
	.pool
_08033874:
	ldrb r2, [r3, 0x8]
	ldr r3, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r4, 2
	adds r0, r1
	lsls r2, 2
	ldr r1, [r0]
	lsls r1, r2
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
_0803388A:
	ldr r0, =gTasks
	mov r2, r9
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, r6, r0
	adds r0, 0x8
	strh r0, [r1, 0x26]
_0803389C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803375C

	thumb_func_start dp01_build_cmdbuf_x00_a_b_0
dp01_build_cmdbuf_x00_a_b_0: @ 80338B4
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r3, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x00_a_b_0

	thumb_func_start dp01_build_cmdbuf_x01_a_b_0
dp01_build_cmdbuf_x01_a_b_0: @ 80338D8
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r4, 0
	movs r3, 0x1
	strb r3, [r1]
	strb r5, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r4, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x01_a_b_0

	thumb_func_start EmitSetAttributes
EmitSetAttributes: @ 8033900
	push {r4-r6,lr}
	ldr r4, [sp, 0x10]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r3, 24
	lsrs r5, r3, 24
	ldr r0, =gUnknown_02022D10
	movs r3, 0x2
	strb r3, [r0]
	strb r1, [r0, 0x1]
	strb r2, [r0, 0x2]
	adds r1, r0, 0
	cmp r5, 0
	beq _0803392E
	adds r3, r1, 0x3
	adds r2, r5, 0
_08033920:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, 0x1
	adds r3, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _08033920
_0803392E:
	adds r2, r5, 0x3
	adds r0, r6, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitSetAttributes

	thumb_func_start sub_8033940
sub_8033940: @ 8033940
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r4, r2, 24
	ldr r0, =gUnknown_02022D10
	movs r2, 0x3
	strb r2, [r0]
	strb r1, [r0, 0x1]
	strb r4, [r0, 0x2]
	adds r5, r0, 0
	cmp r4, 0
	beq _0803396C
	adds r1, r5, 0x3
	adds r2, r4, 0
_0803395E:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, 0x1
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _0803395E
_0803396C:
	adds r2, r4, 0x3
	adds r0, r6, 0
	adds r1, r5, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033940

	thumb_func_start dp01_build_cmdbuf_x04_4_4_4
dp01_build_cmdbuf_x04_4_4_4: @ 8033980
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x4
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x04_4_4_4

	thumb_func_start dp01_build_cmdbuf_x05_a_b_c
dp01_build_cmdbuf_x05_a_b_c: @ 80339A0
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0x5
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r3, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x05_a_b_c

	thumb_func_start dp01_build_cmdbuf_x06_a
dp01_build_cmdbuf_x06_a: @ 80339C4
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x6
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x06_a

	thumb_func_start dp01_build_cmdbuf_x07_7_7_7
dp01_build_cmdbuf_x07_7_7_7: @ 80339E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x7
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x07_7_7_7

	thumb_func_start dp01_build_cmdbuf_x08_8_8_8
dp01_build_cmdbuf_x08_8_8_8: @ 8033A04
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x8
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x08_8_8_8

	thumb_func_start dp01_build_cmdbuf_x09_9_9_9
dp01_build_cmdbuf_x09_9_9_9: @ 8033A24
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x9
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x09_9_9_9

	thumb_func_start dp01_build_cmdbuf_x0A_A_A_A
dp01_build_cmdbuf_x0A_A_A_A: @ 8033A44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xA
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x0A_A_A_A

	thumb_func_start dp01_build_cmdbuf_x0B_B_B_B
dp01_build_cmdbuf_x0B_B_B_B: @ 8033A64
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xB
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x0B_B_B_B

	thumb_func_start dp01_build_cmdbuf_x0C_C_C_C
dp01_build_cmdbuf_x0C_C_C_C: @ 8033A84
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xC
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x0C_C_C_C

	thumb_func_start dp01_build_cmdbuf_x0D_a
dp01_build_cmdbuf_x0D_a: @ 8033AA4
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0xD
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x0D_a

	thumb_func_start sub_8033AC4
sub_8033AC4: @ 8033AC4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r1, =gUnknown_02022D10
	movs r0, 0xE
	strb r0, [r1]
	strb r4, [r1, 0x1]
	lsls r0, r4, 1
	adds r0, r4
	adds r5, r1, 0
	cmp r0, 0
	beq _08033AF2
	adds r1, r5, 0x2
	adds r3, r0, 0
_08033AE4:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _08033AE4
_08033AF2:
	lsls r2, r4, 1
	adds r2, r4
	adds r2, 0x2
	adds r0, r6, 0
	adds r1, r5, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033AC4

	thumb_func_start EmitMoveAnimation
EmitMoveAnimation: @ 8033B0C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r4, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r6, [sp, 0x2C]
	mov r8, r6
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r7, =gUnknown_02022D10
	movs r0, 0
	mov r12, r0
	movs r0, 0xF
	strb r0, [r7]
	strb r1, [r7, 0x1]
	lsrs r1, 8
	strb r1, [r7, 0x2]
	strb r2, [r7, 0x3]
	strb r3, [r7, 0x4]
	movs r6, 0xFF
	lsls r6, 8
	lsrs r3, 8
	strb r3, [r7, 0x5]
	strb r4, [r7, 0x6]
	adds r0, r4, 0
	ands r0, r6
	asrs r0, 8
	strb r0, [r7, 0x7]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r4
	asrs r0, 16
	strb r0, [r7, 0x8]
	lsrs r4, 24
	strb r4, [r7, 0x9]
	strb r5, [r7, 0xA]
	mov r0, r8
	strb r0, [r7, 0xB]
	mov r0, r12
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08033BAC
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08033BAC
	ldr r0, =gBattleWeather
	ldrh r0, [r0]
	strb r0, [r7, 0xC]
	ands r6, r0
	lsrs r0, r6, 8
	strb r0, [r7, 0xD]
	adds r4, r7, 0
	b _08033BB6
	.pool
_08033BAC:
	ldr r0, =gUnknown_02022D10
	movs r1, 0
	strb r1, [r0, 0xC]
	strb r1, [r0, 0xD]
	adds r4, r0, 0
_08033BB6:
	movs r0, 0
	strb r0, [r4, 0xE]
	strb r0, [r4, 0xF]
	adds r0, r4, 0
	adds r0, 0x10
	ldr r1, [sp, 0x28]
	movs r2, 0x1C
	bl memcpy
	mov r0, r9
	adds r1, r4, 0
	movs r2, 0x2C
	bl dp01_prepare_buffer
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitMoveAnimation

	thumb_func_start dp01_build_cmdbuf_x10_TODO
dp01_build_cmdbuf_x10_TODO: @ 8033BE4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_02022D10
	movs r0, 0x10
	strb r0, [r2]
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	strb r0, [r2, 0x1]
	strb r1, [r2, 0x2]
	lsrs r1, 8
	strb r1, [r2, 0x3]
	adds r0, r2, 0x4
	mov r12, r0
	ldr r4, =gCurrentMove
	ldrh r0, [r4]
	strh r0, [r2, 0x4]
	ldr r0, =gUnknown_020241EC
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1, 0x2]
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	ldr r0, =gLastUsedAbility
	ldrb r0, [r0]
	strb r0, [r1, 0x6]
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	strb r0, [r1, 0x7]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x52
	ldrb r1, [r1]
	mov r3, r12
	strb r1, [r3, 0x8]
	adds r0, 0xB1
	ldrb r0, [r0]
	strb r0, [r3, 0x9]
	ldr r0, =gStringBank
	ldrb r0, [r0]
	strb r0, [r3, 0xA]
	ldr r3, =gBattleMoves
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	mov r7, r12
	strb r0, [r7, 0xB]
	movs r3, 0
	mov r9, r2
	ldr r0, =gBattleTextBuff3
	mov r8, r0
	adds r2, 0x10
	ldr r0, =gBattleMons
	adds r4, r0, 0
	adds r4, 0x20
_08033C6A:
	adds r1, r2, r3
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, 0x58
	adds r3, 0x1
	cmp r3, 0x3
	ble _08033C6A
	movs r3, 0
	mov r5, r12
	adds r5, 0x10
	mov r4, r12
	adds r4, 0x20
	ldr r6, =gBattleTextBuff2
	mov r2, r12
	adds r2, 0x30
_08033C88:
	adds r1, r5, r3
	ldr r7, =gBattleTextBuff1
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	mov r7, r8
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0xF
	ble _08033C88
	mov r0, r10
	mov r1, r9
	movs r2, 0x44
	bl dp01_prepare_buffer
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x10_TODO

	thumb_func_start EmitPrintStringPlayerOnly
EmitPrintStringPlayerOnly: @ 8033CFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_02022D10
	movs r0, 0x11
	strb r0, [r2]
	strb r0, [r2, 0x1]
	strb r1, [r2, 0x2]
	lsrs r1, 8
	strb r1, [r2, 0x3]
	adds r0, r2, 0x4
	mov r12, r0
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	strh r0, [r2, 0x4]
	ldr r0, =gUnknown_020241EC
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1, 0x2]
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	ldr r0, =gLastUsedAbility
	ldrb r0, [r0]
	strb r0, [r1, 0x6]
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	strb r0, [r1, 0x7]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x52
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	movs r3, 0
	mov r9, r2
	ldr r7, =gBattleTextBuff3
	mov r8, r7
	mov r4, r9
	adds r4, 0x10
	ldr r0, =gBattleMons
	adds r2, r0, 0
	adds r2, 0x20
_08033D5E:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x58
	adds r3, 0x1
	cmp r3, 0x3
	ble _08033D5E
	movs r3, 0
	mov r5, r12
	adds r5, 0x10
	mov r4, r12
	adds r4, 0x20
	ldr r6, =gBattleTextBuff2
	mov r2, r12
	adds r2, 0x30
_08033D7C:
	adds r1, r5, r3
	ldr r7, =gBattleTextBuff1
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	mov r7, r8
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0xF
	ble _08033D7C
	mov r0, r10
	mov r1, r9
	movs r2, 0x44
	bl dp01_prepare_buffer
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitPrintStringPlayerOnly

	thumb_func_start dp01_build_cmdbuf_x12_a_bb
dp01_build_cmdbuf_x12_a_bb: @ 8033DE4
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gUnknown_02022D10
	movs r3, 0x12
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x12_a_bb

	thumb_func_start sub_8033E10
sub_8033E10: @ 8033E10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x13
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033E10

	thumb_func_start sub_8033E30
sub_8033E30: @ 8033E30
	push {r4-r6,lr}
	adds r5, r3, 0
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, =gUnknown_02022D10
	movs r4, 0
	movs r0, 0x14
	strb r0, [r3]
	strb r1, [r3, 0x1]
	strb r2, [r3, 0x2]
	strb r4, [r3, 0x3]
	movs r2, 0
	adds r1, r3, 0
	adds r4, r1, 0x4
_08033E4C:
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	adds r2, 0x1
	cmp r2, 0x13
	bls _08033E4C
	adds r0, r6, 0
	movs r2, 0x18
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033E30

	thumb_func_start sub_8033E6C
sub_8033E6C: @ 8033E6C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_02022D10
	movs r0, 0x15
	strb r0, [r1]
	movs r2, 0
	adds r3, r1, 0x1
_08033E7E:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2
	ble _08033E7E
	adds r0, r5, 0
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8033E6C

	thumb_func_start dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f
dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f: @ 8033EA0
	push {r4-r6,lr}
	ldr r6, [sp, 0x10]
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_02022D10
	movs r0, 0x16
	strb r0, [r4]
	strb r1, [r4, 0x1]
	strb r2, [r4, 0x2]
	strb r3, [r4, 0x3]
	movs r2, 0
	adds r1, r4, 0
	adds r3, r1, 0x4
_08033EBA:
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2
	ble _08033EBA
	adds r0, r5, 0
	movs r2, 0x8
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f

	thumb_func_start dp01_build_cmdbuf_x17_17_17_17
dp01_build_cmdbuf_x17_17_17_17: @ 8033EDC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x17
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x17_17_17_17

	thumb_func_start EmitHealthBarUpdate
EmitHealthBarUpdate: @ 8033EFC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gUnknown_02022D10
	movs r4, 0
	movs r2, 0x18
	strb r2, [r3]
	strb r4, [r3, 0x1]
	strb r1, [r3, 0x2]
	lsls r1, 16
	asrs r1, 16
	movs r2, 0xFF
	lsls r2, 8
	ands r1, r2
	asrs r1, 8
	strb r1, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitHealthBarUpdate

	thumb_func_start dp01_build_cmdbuf_x19_a_bb
dp01_build_cmdbuf_x19_a_bb: @ 8033F34
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gUnknown_02022D10
	movs r3, 0x19
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsls r2, 16
	asrs r2, 16
	movs r3, 0xFF
	lsls r3, 8
	ands r2, r3
	asrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x19_a_bb

	thumb_func_start dp01_build_cmdbuf_x1A_aaaa_bbbb
dp01_build_cmdbuf_x1A_aaaa_bbbb: @ 8033F68
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0x1A
	strb r3, [r1]
	strb r4, [r1, 0x1]
	movs r6, 0xFF
	lsls r6, 8
	adds r3, r4, 0
	ands r3, r6
	lsrs r3, 8
	strb r3, [r1, 0x2]
	movs r5, 0xFF
	lsls r5, 16
	adds r3, r4, 0
	ands r3, r5
	lsrs r3, 16
	strb r3, [r1, 0x3]
	lsrs r4, 24
	strb r4, [r1, 0x4]
	strb r2, [r1, 0x5]
	adds r3, r2, 0
	ands r3, r6
	lsrs r3, 8
	strb r3, [r1, 0x6]
	adds r3, r2, 0
	ands r3, r5
	lsrs r3, 16
	strb r3, [r1, 0x7]
	lsrs r2, 24
	strb r2, [r1, 0x8]
	movs r2, 0x9
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x1A_aaaa_bbbb

	thumb_func_start dp01_build_cmdbuf_x1B_aaaa_b
dp01_build_cmdbuf_x1B_aaaa_b: @ 8033FBC
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0x1B
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	movs r3, 0xFF
	lsls r3, 8
	ands r3, r2
	lsrs r3, 8
	strb r3, [r1, 0x3]
	movs r3, 0xFF
	lsls r3, 16
	ands r3, r2
	lsrs r3, 16
	strb r3, [r1, 0x4]
	lsrs r2, 24
	strb r2, [r1, 0x5]
	movs r2, 0x6
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x1B_aaaa_b

	thumb_func_start dp01_build_cmdbuf_x1C_a
dp01_build_cmdbuf_x1C_a: @ 8033FF8
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x1C
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x1C_a

	thumb_func_start dp01_build_cmdbuf_x1D_1D_numargs_varargs
dp01_build_cmdbuf_x1D_1D_numargs_varargs: @ 8034018
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r1, =gUnknown_02022D10
	movs r0, 0x1D
	strb r0, [r1]
	strb r0, [r1, 0x1]
	strb r4, [r1, 0x2]
	lsrs r0, r4, 8
	strb r0, [r1, 0x3]
	adds r5, r1, 0
	cmp r4, 0
	beq _08034048
	adds r1, r5, 0x4
	adds r3, r4, 0
_0803403A:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _0803403A
_08034048:
	adds r2, r4, 0x4
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x1D_1D_numargs_varargs

	thumb_func_start sub_8034060
sub_8034060: @ 8034060
	push {r4-r6,lr}
	adds r4, r3, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 16
	lsrs r5, r2, 16
	ldr r2, =gUnknown_02022D10
	movs r0, 0x1E
	strb r0, [r2]
	strb r1, [r2, 0x1]
	movs r3, 0xFF
	lsls r3, 8
	adds r0, r1, 0
	ands r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x2]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r2, 0x3]
	lsrs r1, 24
	strb r1, [r2, 0x4]
	strb r5, [r2, 0x5]
	adds r0, r5, 0
	ands r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x6]
	adds r1, r2, 0
	cmp r5, 0
	beq _080340B0
	adds r3, r1, 0x7
	adds r2, r5, 0
_080340A2:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, 0x1
	adds r3, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _080340A2
_080340B0:
	adds r2, r5, 0x7
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034060

	thumb_func_start sub_80340C8
sub_80340C8: @ 80340C8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r1, =gUnknown_02022D10
	movs r0, 0x1F
	strb r0, [r1]
	strb r4, [r1, 0x1]
	lsrs r0, r4, 8
	strb r0, [r1, 0x2]
	adds r5, r1, 0
	cmp r4, 0
	beq _080340F6
	adds r1, r5, 0x3
	adds r3, r4, 0
_080340E8:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080340E8
_080340F6:
	adds r2, r4, 0x3
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80340C8

	thumb_func_start sub_8034110
sub_8034110: @ 8034110
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r1, =gUnknown_02022D10
	movs r0, 0x20
	strb r0, [r1]
	strb r4, [r1, 0x1]
	lsrs r0, r4, 8
	strb r0, [r1, 0x2]
	adds r5, r1, 0
	cmp r4, 0
	beq _0803413E
	adds r1, r5, 0x3
	adds r3, r4, 0
_08034130:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _08034130
_0803413E:
	adds r2, r4, 0x3
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl dp01_prepare_buffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034110

	thumb_func_start dp01_build_cmdbuf_x21_a_bb
dp01_build_cmdbuf_x21_a_bb: @ 8034158
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gUnknown_02022D10
	movs r3, 0x21
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x21_a_bb

	thumb_func_start dp01_build_cmdbuf_x22_a_three_bytes
dp01_build_cmdbuf_x22_a_three_bytes: @ 8034184
	push {r4,r5,lr}
	adds r4, r2, 0
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gUnknown_02022D10
	movs r0, 0x22
	strb r0, [r2]
	strb r1, [r2, 0x1]
	movs r3, 0
	adds r1, r2, 0x2
_08034198:
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x2
	ble _08034198
	adds r0, r5, 0
	adds r1, r2, 0
	movs r2, 0x5
	bl dp01_prepare_buffer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x22_a_three_bytes

	thumb_func_start dp01_build_cmdbuf_x23_aa_0
dp01_build_cmdbuf_x23_aa_0: @ 80341BC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gUnknown_02022D10
	movs r4, 0
	movs r2, 0x23
	strb r2, [r3]
	strb r1, [r3, 0x1]
	lsrs r1, 8
	strb r1, [r3, 0x2]
	strb r4, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x23_aa_0

	thumb_func_start dp01_build_cmdbuf_x24_aa_0
dp01_build_cmdbuf_x24_aa_0: @ 80341E8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gUnknown_02022D10
	movs r4, 0
	movs r2, 0x24
	strb r2, [r3]
	strb r1, [r3, 0x1]
	lsrs r1, 8
	strb r1, [r3, 0x2]
	strb r4, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x24_aa_0

	thumb_func_start dp01_build_cmdbuf_x25_25_25_25
dp01_build_cmdbuf_x25_25_25_25: @ 8034214
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x25
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x25_25_25_25

	thumb_func_start dp01_build_cmdbuf_x26_a
dp01_build_cmdbuf_x26_a: @ 8034234
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x26
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x26_a

	thumb_func_start dp01_build_cmdbuf_x27_27_27_27
dp01_build_cmdbuf_x27_27_27_27: @ 8034254
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x27
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x27_27_27_27

	thumb_func_start dp01_build_cmdbuf_x28_28_28_28
dp01_build_cmdbuf_x28_28_28_28: @ 8034274
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x28
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x28_28_28_28

	thumb_func_start dp01_build_cmdbuf_x29_29_29_29
dp01_build_cmdbuf_x29_29_29_29: @ 8034294
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x29
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x29_29_29_29

	thumb_func_start dp01_build_cmdbuf_x2A_2A_2A_2A
dp01_build_cmdbuf_x2A_2A_2A_2A: @ 80342B4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x2A
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x2A_2A_2A_2A

	thumb_func_start EmitEffectivenessSound
EmitEffectivenessSound: @ 80342D4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =gUnknown_02022D10
	movs r4, 0
	movs r2, 0x2B
	strb r2, [r3]
	strb r1, [r3, 0x1]
	lsrs r1, 8
	strb r1, [r3, 0x2]
	strb r4, [r3, 0x3]
	adds r1, r3, 0
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EmitEffectivenessSound

	thumb_func_start sub_8034300
sub_8034300: @ 8034300
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gUnknown_02022D10
	movs r3, 0x2C
	strb r3, [r4]
	strb r1, [r4, 0x1]
	lsrs r1, 8
	strb r1, [r4, 0x2]
	strb r2, [r4, 0x3]
	adds r1, r4, 0
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034300

	thumb_func_start dp01_build_cmdbuf_x2D_2D_2D_2D
dp01_build_cmdbuf_x2D_2D_2D_2D: @ 803432C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x2D
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x2D_2D_2D_2D

	thumb_func_start dp01_build_cmdbuf_x2E_a
dp01_build_cmdbuf_x2E_a: @ 803434C
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x2E
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x2E_a

	thumb_func_start dp01_build_cmdbuf_x2F_2F_2F_2F
dp01_build_cmdbuf_x2F_2F_2F_2F: @ 803436C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x2F
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x2F_2F_2F_2F

	thumb_func_start dp01_build_cmdbuf_x30_TODO
dp01_build_cmdbuf_x30_TODO: @ 803438C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_02022D10
	movs r3, 0x30
	strb r3, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x1]
	movs r0, 0x80
	ands r0, r2
	lsls r0, 24
	lsrs r0, 31
	strb r0, [r1, 0x2]
	strb r3, [r1, 0x3]
	movs r2, 0
	adds r3, r1, 0x4
_080343B4:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2F
	ble _080343B4
	adds r0, r5, 0
	movs r2, 0x34
	bl dp01_prepare_buffer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x30_TODO

	thumb_func_start dp01_build_cmdbuf_x31_31_31_31
dp01_build_cmdbuf_x31_31_31_31: @ 80343D4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x31
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x31_31_31_31

	thumb_func_start dp01_build_cmdbuf_x32_32_32_32
dp01_build_cmdbuf_x32_32_32_32: @ 80343F4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x32
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x32_32_32_32

	thumb_func_start dp01_build_cmdbuf_x33_a_33_33
dp01_build_cmdbuf_x33_a_33_33: @ 8034414
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x33
	strb r2, [r1]
	strb r3, [r1, 0x1]
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x33_a_33_33

	thumb_func_start dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
dp01_build_cmdbuf_x34_a_bb_aka_battle_anim: @ 8034438
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gUnknown_02022D10
	movs r3, 0x34
	strb r3, [r1]
	strb r4, [r1, 0x1]
	strb r2, [r1, 0x2]
	lsrs r2, 8
	strb r2, [r1, 0x3]
	movs r2, 0x4
	bl dp01_prepare_buffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x34_a_bb_aka_battle_anim

	thumb_func_start sub_8034464
sub_8034464: @ 8034464
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r4, =gUnknown_02022D10
	movs r0, 0x35
	strb r0, [r4]
	strb r1, [r4, 0x1]
	cmp r2, 0
	beq _0803448C
	adds r0, r4, 0x4
	bl sub_81850DC
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	b _08034490
	.pool
_0803448C:
	strb r2, [r4, 0x2]
	strb r2, [r4, 0x3]
_08034490:
	ldr r1, =gUnknown_02022D10
	ldrb r2, [r1, 0x2]
	adds r2, 0x4
	adds r0, r5, 0
	bl dp01_prepare_buffer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034464

	thumb_func_start dp01_build_cmdbuf_x38_a
dp01_build_cmdbuf_x38_a: @ 80344A8
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022D10
	movs r2, 0x36
	strb r2, [r1]
	strb r3, [r1, 0x1]
	movs r2, 0x2
	bl dp01_prepare_buffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x38_a

	thumb_func_start dp01_build_cmdbuf_x37_a
dp01_build_cmdbuf_x37_a: @ 80344C8
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gUnknown_02022D10
	movs r0, 0x37
	strb r0, [r4]
	strb r1, [r4, 0x1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 31
	strb r0, [r4, 0x2]
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 31
	strb r0, [r4, 0x3]
	adds r0, r4, 0x6
	bl sub_81850DC
	strb r0, [r4, 0x4]
	strb r0, [r4, 0x5]
	ldrb r2, [r4, 0x4]
	adds r2, 0x6
	adds r0, r5, 0
	adds r1, r4, 0
	bl dp01_prepare_buffer
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_build_cmdbuf_x37_a

	.align 2, 0 @ Don't pad with nop.
