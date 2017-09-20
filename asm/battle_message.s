	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start BufferStringBattle
BufferStringBattle: @ 814E0C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r7, 0
	ldr r4, =gStringInfo
	ldr r0, =gActiveBank
	mov r8, r0
	ldrb r1, [r0]
	lsls r1, 9
	ldr r0, =gBattleBufferA + 4
	adds r1, r0
	str r1, [r4]
	ldr r2, =gLastUsedItem
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	ldr r2, =gLastUsedAbility
	ldrb r0, [r1, 0x6]
	strb r0, [r2]
	ldr r5, =gBattleScripting
	ldrb r0, [r1, 0x7]
	strb r0, [r5, 0x17]
	ldr r3, =gBattleStruct
	ldr r0, [r3]
	adds r0, 0x52
	ldrb r1, [r1, 0x8]
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, 0xB1
	ldr r1, [r4]
	ldrb r1, [r1, 0x9]
	strb r1, [r0]
	ldr r1, =gStringBank
	ldr r2, [r4]
	ldrb r0, [r2, 0xA]
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x8E
	ldrb r1, [r2, 0xB]
	strb r1, [r0]
	movs r2, 0
	mov r12, r8
	mov r9, r5
	ldr r1, =gBattleTextBuff1
	mov r10, r1
	ldr r3, =gAbilitiesPerBank
_0814E126:
	adds r0, r2, r3
	ldr r1, [r4]
	adds r1, 0xC
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _0814E126
	movs r2, 0
	ldr r0, =gBattleTextBuff1
	mov r8, r0
	ldr r3, =gStringInfo
	ldr r5, =gBattleTextBuff2
	ldr r4, =gBattleTextBuff3
_0814E144:
	mov r0, r8
	adds r1, r2, r0
	ldr r0, [r3]
	adds r0, 0x10
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r5
	ldr r0, [r3]
	adds r0, 0x20
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r4
	ldr r0, [r3]
	adds r0, 0x30
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0xF
	ble _0814E144
	cmp r6, 0x5
	bls _0814E176
	b _0814E6B8
_0814E176:
	lsls r0, r6, 2
	ldr r1, =_0814E1B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814E1B4:
	.4byte _0814E1CC
	.4byte _0814E2AC
	.4byte _0814E394
	.4byte _0814E430
	.4byte _0814E4F8
	.4byte _0814E55C
_0814E1CC:
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0814E26C
	ldr r0, =0x02000002
	ands r0, r2
	cmp r0, 0
	beq _0814E248
	movs r0, 0x80
	lsls r0, 16
	ands r0, r2
	cmp r0, 0
	bne _0814E260
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _0814E214
	movs r0, 0x80
	lsls r0, 17
	ands r2, r0
	ldr r7, =gText_TwoTrainersWantToBattle
	cmp r2, 0
	bne _0814E200
	b _0814E6D8
_0814E200:
	ldr r7, =gText_TwoTrainersWantToBattle3
	b _0814E6D8
	.pool
_0814E214:
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	cmp r1, r0
	bne _0814E22C
	ldr r7, =gText_TrainerXYWantsToBattle
	b _0814E6D8
	.pool
_0814E22C:
	movs r0, 0x80
	lsls r0, 17
	ands r2, r0
	ldr r7, =gText_TrainerXWantsToBattle
	cmp r2, 0
	bne _0814E23A
	b _0814E6D8
_0814E23A:
	ldr r7, =gText_TrainerWantsToBattle
	b _0814E6D8
	.pool
_0814E248:
	movs r0, 0x80
	lsls r0, 15
	ands r0, r2
	cmp r0, 0
	bne _0814E260
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	ldr r7, =gText_TrainerXYWantsToBattle
	cmp r2, 0
	bne _0814E260
	b _0814E6D8
_0814E260:
	ldr r7, =gText_TwoTrainersWantToBattle2
	b _0814E6D8
	.pool
_0814E26C:
	movs r0, 0x80
	lsls r0, 6
	ands r0, r2
	cmp r0, 0
	beq _0814E280
	ldr r7, =gText_WildPkmnAppeared2
	b _0814E6D8
	.pool
_0814E280:
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0814E290
	ldr r7, =gText_TwoWildPkmnAppeared
	b _0814E6D8
	.pool
_0814E290:
	movs r0, 0x80
	lsls r0, 2
	ands r2, r0
	ldr r7, =gText_WildPkmnAppeared
	cmp r2, 0
	bne _0814E29E
	b _0814E6D8
_0814E29E:
	ldr r7, =gText_WildPkmnAppearedPause
	b _0814E6D8
	.pool
_0814E2AC:
	mov r1, r12
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814E310
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0814E308
	movs r0, 0x80
	lsls r0, 15
	ands r0, r1
	cmp r0, 0
	beq _0814E2DC
	ldr r7, =gText_TrainerXYSentOutZGoN
	b _0814E6D8
	.pool
_0814E2DC:
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0814E2F0
	ldr r7, =gText_GoTwoPkmn
	b _0814E6D8
	.pool
_0814E2F0:
	movs r0, 0x40
	ands r1, r0
	ldr r7, =gText_GoTwoPkmn
	cmp r1, 0
	bne _0814E2FC
	b _0814E6D8
_0814E2FC:
	ldr r7, =gText_EnemySentOutPkmnGoPkmn
	b _0814E6D8
	.pool
_0814E308:
	ldr r7, =gText_GoPkmn
	b _0814E6D8
	.pool
_0814E310:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0814E368
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	bne _0814E330
	movs r0, 0x80
	lsls r0, 16
	ands r0, r1
	cmp r0, 0
	beq _0814E33C
_0814E330:
	ldr r7, =gText_TwoTrainersSentPkmn
	b _0814E6D8
	.pool
_0814E33C:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0814E34C
	ldr r7, =gText_TwoTrainersSentOutPkmn
	b _0814E6D8
	.pool
_0814E34C:
	ldr r0, =0x02000002
	ands r1, r0
	ldr r7, =gText_TrainerXYSentOutTwoPkmn
	cmp r1, 0
	bne _0814E358
	b _0814E6D8
_0814E358:
	ldr r7, =gText_TrainerXSentOutTwoPkmn
	b _0814E6D8
	.pool
_0814E368:
	ldr r0, =0x02000002
	ands r1, r0
	cmp r1, 0
	beq _0814E380
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	ldr r7, =gText_TrainerXSentOutPkmn
	cmp r1, r0
	beq _0814E380
	b _0814E6D8
_0814E380:
	ldr r7, =gText_TrainerXYSentOutPkmn
	b _0814E6D8
	.pool
_0814E394:
	mov r1, r12
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814E3EC
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB1
	ldrb r2, [r0]
	cmp r2, 0
	bne _0814E3BC
	ldr r7, =gText_PkmnThatsEnough
	b _0814E6D8
	.pool
_0814E3BC:
	cmp r2, 0x1
	beq _0814E3CC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0814E3D8
_0814E3CC:
	ldr r7, =gText_PkmnComeBack
	b _0814E6D8
	.pool
_0814E3D8:
	ldr r7, =gText_PkmnGoodComeBack
	cmp r2, 0x2
	beq _0814E3E0
	b _0814E6D8
_0814E3E0:
	ldr r7, =gText_PkmnOkComeBack
	b _0814E6D8
	.pool
_0814E3EC:
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 4
	ldr r2, =gBattleTypeFlags
	cmp r1, r0
	beq _0814E406
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _0814E428
_0814E406:
	ldr r0, [r2]
	movs r1, 0x40
	ands r0, r1
	ldr r7, =gText_TrainerXWithdrewPkmn
	cmp r0, 0
	bne _0814E414
	b _0814E6D8
_0814E414:
	ldr r7, =gText_TrainerXWithdrewPkmn2
	b _0814E6D8
	.pool
_0814E428:
	ldr r7, =gText_TrainerXYWithdrewPkmn
	b _0814E6D8
	.pool
_0814E430:
	mov r4, r9
	ldrb r0, [r4, 0x17]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814E488
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB1
	ldrb r2, [r0]
	cmp r2, 0
	beq _0814E456
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0814E468
_0814E456:
	ldr r7, =gText_GoPkmn2
	b _0814E6D8
	.pool
_0814E468:
	cmp r2, 0x1
	bne _0814E474
	ldr r7, =gText_DoItPkmn
	b _0814E6D8
	.pool
_0814E474:
	ldr r7, =gText_YourFoesWeakGetEmPkmn
	cmp r2, 0x2
	beq _0814E47C
	b _0814E6D8
_0814E47C:
	ldr r7, =gText_GoForItPkmn
	b _0814E6D8
	.pool
_0814E488:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0814E4DC
	movs r0, 0x80
	lsls r0, 16
	ands r0, r1
	cmp r0, 0
	beq _0814E4AC
	ldrb r0, [r4, 0x17]
	b _0814E4EA
	.pool
_0814E4AC:
	movs r0, 0x40
	ands r1, r0
	cmp r1, 0
	beq _0814E4BC
	ldr r7, =gText_TrainerXSentOutPkmn3
	b _0814E6D8
	.pool
_0814E4BC:
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	ldr r7, =gText_TrainerXSentOutPkmn2
	cmp r1, r0
	beq _0814E4CC
	b _0814E6D8
_0814E4CC:
	ldr r7, =gText_TrainerXYSentOutPkmn2
	b _0814E6D8
	.pool
_0814E4DC:
	movs r0, 0x80
	lsls r0, 8
	ands r1, r0
	cmp r1, 0
	beq _0814E4CC
	mov r1, r9
	ldrb r0, [r1, 0x17]
_0814E4EA:
	ldr r7, =gText_TrainerXYSentOutPkmn3
	cmp r0, 0x1
	beq _0814E4F2
	b _0814E6D8
_0814E4F2:
	b _0814E4CC
	.pool
_0814E4F8:
	mov r0, r10
	bl sub_814F8F8
	ldr r0, =gStringInfo
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bls _0814E534
	ldr r0, =gBattleTextBuff2
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r1, 0x8E
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	ldr r2, =gText_UnknownMoveTypes
	adds r1, r2
	bl StringCopy
	b _0814E544
	.pool
_0814E534:
	ldr r0, =gBattleTextBuff2
	ldrh r2, [r2]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
_0814E544:
	ldr r0, =gBattleTextBuff2
	bl sub_814F950
	ldr r7, =gText_XUsedY2
	b _0814E6D8
	.pool
_0814E55C:
	ldr r4, =gBattleTextBuff1
	ldrb r1, [r4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0814E5C4
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r4]
	mov r1, r12
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0814E58A
	ldrb r1, [r4]
	cmp r1, 0x3
	beq _0814E58A
	movs r0, 0x3
	eors r0, r1
	strb r0, [r4]
_0814E58A:
	ldr r0, =gBattleTextBuff1
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0814E5A4
	ldr r7, =gText_GotAwaySafely
	b _0814E6D8
	.pool
_0814E5A4:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	ldr r7, =gText_WildFled
	cmp r0, 0
	bne _0814E5B4
	b _0814E6D8
_0814E5B4:
	ldr r7, =gText_TwoWildFled
	b _0814E6D8
	.pool
_0814E5C4:
	mov r1, r12
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0814E5E0
	ldrb r1, [r4]
	cmp r1, 0x3
	beq _0814E5E0
	movs r0, 0x3
	eors r0, r1
	strb r0, [r4]
_0814E5E0:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0814E638
	ldr r0, =gBattleTextBuff1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0814E628
	cmp r0, 0x2
	bgt _0814E608
	cmp r0, 0x1
	beq _0814E60E
	b _0814E6D8
	.pool
_0814E608:
	cmp r0, 0x3
	beq _0814E630
	b _0814E6D8
_0814E60E:
	movs r0, 0x80
	lsls r0, 16
	ands r1, r0
	ldr r7, =gText_PlayerBeatTwo
	cmp r1, 0
	beq _0814E6D8
	ldr r7, =gText_TwoEnemiesDefeated
	b _0814E6D8
	.pool
_0814E628:
	ldr r7, =gText_PlayerLostToTwo
	b _0814E6D8
	.pool
_0814E630:
	ldr r7, =gText_PlayerBattledToDrawVsTwo
	b _0814E6D8
	.pool
_0814E638:
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	cmp r1, r0
	bne _0814E680
	ldr r0, =gBattleTextBuff1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0814E670
	cmp r0, 0x2
	bgt _0814E660
	cmp r0, 0x1
	beq _0814E666
	b _0814E6D8
	.pool
_0814E660:
	cmp r0, 0x3
	beq _0814E678
	b _0814E6D8
_0814E666:
	ldr r7, =gText_PlayerDefeatedXY
	b _0814E6D8
	.pool
_0814E670:
	ldr r7, =gText_PlayerLostAgainst2
	b _0814E6D8
	.pool
_0814E678:
	ldr r7, =gText_PlayerBattledToDraw2
	b _0814E6D8
	.pool
_0814E680:
	ldr r0, =gBattleTextBuff1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0814E6A8
	cmp r0, 0x2
	bgt _0814E698
	cmp r0, 0x1
	beq _0814E69E
	b _0814E6D8
	.pool
_0814E698:
	cmp r0, 0x3
	beq _0814E6B0
	b _0814E6D8
_0814E69E:
	ldr r7, =gText_PlayerDefeated
	b _0814E6D8
	.pool
_0814E6A8:
	ldr r7, =gText_PlayerLostAgainst
	b _0814E6D8
	.pool
_0814E6B0:
	ldr r7, =gText_PlayerBattledToDraw
	b _0814E6D8
	.pool
_0814E6B8:
	movs r0, 0xBE
	lsls r0, 1
	cmp r6, r0
	bls _0814E6CC
	ldr r1, =gDisplayedStringBattle
	movs r0, 0xFF
	strb r0, [r1]
	b _0814E6DE
	.pool
_0814E6CC:
	ldr r1, =gBattleStringsTable
	adds r0, r6, 0
	subs r0, 0xC
	lsls r0, 2
	adds r0, r1
	ldr r7, [r0]
_0814E6D8:
	adds r0, r7, 0
	bl StrCpyDecodeToDisplayedStringBattle
_0814E6DE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BufferStringBattle

	thumb_func_start StrCpyDecodeToDisplayedStringBattle
StrCpyDecodeToDisplayedStringBattle: @ 814E6F0
	push {lr}
	ldr r1, =gDisplayedStringBattle
	bl StrCpyDecodeBattle
	pop {r1}
	bx r1
	.pool
	thumb_func_end StrCpyDecodeToDisplayedStringBattle

	thumb_func_start AppendStatusString
AppendStatusString: @ 814E700
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_085CD422
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	mov r2, sp
	movs r3, 0
	b _0814E728
	.pool
_0814E71C:
	strb r1, [r2]
	adds r4, 0x1
	adds r2, 0x1
	adds r3, 0x1
	cmp r3, 0x7
	bhi _0814E730
_0814E728:
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814E71C
_0814E730:
	ldr r5, [sp]
	ldr r4, [sp, 0x4]
	movs r3, 0
	ldr r2, =gUnknown_0831BCA8
_0814E738:
	ldr r1, [r2]
	ldr r0, [r1]
	cmp r5, r0
	bne _0814E750
	ldr r0, [r1, 0x4]
	cmp r4, r0
	bne _0814E750
	ldr r0, [r2, 0x4]
	b _0814E75A
	.pool
_0814E750:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x6
	bls _0814E738
	movs r0, 0
_0814E75A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end AppendStatusString

	thumb_func_start StrCpyDecodeBattle
StrCpyDecodeBattle: @ 814E764
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x20
	mov r9, r0
	mov r8, r1
	movs r6, 0
	movs r4, 0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _0814E794
	ldr r0, =gUnknown_0203C7B4
	ldrb r7, [r0]
	b _0814E79C
	.pool
_0814E794:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r7, r0, 24
_0814E79C:
	mov r0, r9
	ldrb r1, [r0]
	bl _0814F620
_0814E7A4:
	cmp r1, 0xFD
	beq _0814E7AC
	bl _0814F610
_0814E7AC:
	movs r1, 0x1
	add r9, r1
	mov r2, r9
	ldrb r0, [r2]
	cmp r0, 0x34
	bls _0814E7BC
	bl _0814F5C0
_0814E7BC:
	lsls r0, 2
	ldr r1, =_0814E7CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814E7CC:
	.4byte _0814E8A0
	.4byte _0814E8CE
	.4byte _0814E90A
	.4byte _0814E914
	.4byte _0814E920
	.4byte _0814E92C
	.4byte _0814E960
	.4byte _0814E994
	.4byte _0814E9C8
	.4byte _0814E9FC
	.4byte _0814EA38
	.4byte _0814EA78
	.4byte _0814EAB8
	.4byte _0814EAF8
	.4byte _0814EBB0
	.4byte _0814EC38
	.4byte _0814ECD4
	.4byte _0814ED70
	.4byte _0814EE0C
	.4byte _0814EEA8
	.4byte _0814EF44
	.4byte _0814EF5C
	.4byte _0814EF98
	.4byte _0814F080
	.4byte _0814F088
	.4byte _0814F098
	.4byte _0814F0A8
	.4byte _0814F0B8
	.4byte _0814F0D8
	.4byte _0814F164
	.4byte _0814F220
	.4byte _0814F230
	.4byte _0814F244
	.4byte _0814F258
	.4byte _0814F27C
	.4byte _0814F298
	.4byte _0814F2C0
	.4byte _0814F300
	.4byte _0814F330
	.4byte _0814F3C4
	.4byte _0814F410
	.4byte _0814F418
	.4byte _0814F3E4
	.4byte _0814F3EC
	.4byte _0814F43C
	.4byte _0814F444
	.4byte _0814F468
	.4byte _0814F4B8
	.4byte _0814F508
	.4byte _0814F548
	.4byte _0814F594
	.4byte _0814F5B4
	.4byte _0814E8E4
_0814E8A0:
	ldr r5, =gBattleTextBuff1
	ldrb r0, [r5]
	cmp r0, 0xFD
	bne _0814E8B8
	ldr r4, =gStringVar1
	adds r0, r5, 0
	b _0814E8F0
	.pool
_0814E8B8:
	adds r0, r5, 0
	bl AppendStatusString
	adds r4, r0, 0
	cmp r4, 0
	beq _0814E8C8
	bl _0814F5C0
_0814E8C8:
	adds r4, r5, 0
	bl _0814F5C0
_0814E8CE:
	ldr r1, =gBattleTextBuff2
	ldrb r0, [r1]
	cmp r0, 0xFD
	bne _0814E904
	ldr r4, =gStringVar2
	b _0814E8EE
	.pool
_0814E8E4:
	ldr r1, =gBattleTextBuff3
	ldrb r0, [r1]
	cmp r0, 0xFD
	bne _0814E904
	ldr r4, =gStringVar3
_0814E8EE:
	adds r0, r1, 0
_0814E8F0:
	adds r1, r4, 0
	bl StrCpyDecodeBattleTextBuff
	bl _0814F5C0
	.pool
_0814E904:
	adds r4, r1, 0
	bl _0814F5C0
_0814E90A:
	ldr r4, =gStringVar1
	bl _0814F5C0
	.pool
_0814E914:
	ldr r4, =gStringVar2
	bl _0814F5C0
	.pool
_0814E920:
	ldr r4, =gStringVar3
	bl _0814F5C0
	.pool
_0814E92C:
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814E960:
	movs r0, 0x1
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814E994:
	movs r0, 0x2
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814E9C8:
	movs r0, 0x3
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814E9FC:
	ldr r2, =gBattlePartyID
	ldr r1, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x18]
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EA38:
	ldr r2, =gBattlePartyID
	ldr r1, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x18]
	movs r0, 0x1
	eors r0, r1
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EA78:
	ldr r2, =gBattlePartyID
	ldr r1, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x18]
	movs r0, 0x2
	eors r0, r1
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EAB8:
	ldr r2, =gBattlePartyID
	ldr r1, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x18]
	movs r0, 0x3
	eors r0, r1
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EAF8:
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	adds r2, r4, 0
	cmp r0, 0
	beq _0814EB74
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814EB36
	ldr r4, =gText_FoePkmnPrefix
	b _0814EB36
	.pool
_0814EB2C:
	mov r3, r8
	adds r0, r3, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
_0814EB36:
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814EB2C
	ldrb r0, [r2]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814EB9E
	.pool
_0814EB74:
	ldrb r0, [r2]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814EB9E:
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EBB0:
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814EBF8
	ldrb r0, [r4]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, 0x4
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814EC24
	.pool
_0814EBF8:
	ldrb r0, [r4]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	bl GetBankByPlayerAI
	ldr r1, =gBattlePartyID
	lsls r0, 24
	lsrs r0, 23
	adds r0, 0x4
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814EC24:
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EC38:
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0814ECA8
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814EC56
	ldr r4, =gText_FoePkmnPrefix
_0814EC56:
	ldrb r1, [r4]
	adds r0, r1, 0
	ldr r3, =gBattlePartyID
	ldr r2, =gEnemyParty
	mov r12, r2
	adds r2, r5, 0
	cmp r0, 0xFF
	beq _0814EC78
_0814EC66:
	mov r5, r8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814EC66
_0814EC78:
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	add r0, r12
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814ECC2
	.pool
_0814ECA8:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814ECC2:
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814ECD4:
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0814ED44
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814ECF2
	ldr r4, =gText_FoePkmnPrefix
_0814ECF2:
	ldrb r1, [r4]
	adds r0, r1, 0
	ldr r3, =gBattlePartyID
	ldr r2, =gEnemyParty
	mov r12, r2
	adds r2, r5, 0
	cmp r0, 0xFF
	beq _0814ED14
_0814ED02:
	mov r5, r8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814ED02
_0814ED14:
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	add r0, r12
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814ED5E
	.pool
_0814ED44:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814ED5E:
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814ED70:
	ldr r5, =gEffectBank
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0814EDE0
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814ED8E
	ldr r4, =gText_FoePkmnPrefix
_0814ED8E:
	ldrb r1, [r4]
	adds r0, r1, 0
	ldr r3, =gBattlePartyID
	ldr r2, =gEnemyParty
	mov r12, r2
	adds r2, r5, 0
	cmp r0, 0xFF
	beq _0814EDB0
_0814ED9E:
	mov r5, r8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814ED9E
_0814EDB0:
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	add r0, r12
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814EDFA
	.pool
_0814EDE0:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814EDFA:
	mov r0, sp
	bl StringGetEnd10
	bl _0814F5BE
	.pool
_0814EE0C:
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0814EE7C
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814EE2A
	ldr r4, =gText_FoePkmnPrefix
_0814EE2A:
	ldrb r1, [r4]
	adds r0, r1, 0
	ldr r3, =gBattlePartyID
	ldr r2, =gEnemyParty
	mov r12, r2
	adds r2, r5, 0
	cmp r0, 0xFF
	beq _0814EE4C
_0814EE3A:
	mov r5, r8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814EE3A
_0814EE4C:
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	add r0, r12
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814EE96
	.pool
_0814EE7C:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814EE96:
	mov r0, sp
	bl StringGetEnd10
	b _0814F5BE
	.pool
_0814EEA8:
	ldr r5, =gBattleScripting
	ldrb r0, [r5, 0x17]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0814EF18
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814EEC6
	ldr r4, =gText_FoePkmnPrefix
_0814EEC6:
	ldrb r1, [r4]
	adds r0, r1, 0
	ldr r3, =gBattlePartyID
	ldr r2, =gEnemyParty
	mov r12, r2
	adds r2, r5, 0
	cmp r0, 0xFF
	beq _0814EEE8
_0814EED6:
	mov r5, r8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814EED6
_0814EEE8:
	ldrb r0, [r2, 0x17]
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	add r0, r12
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814EF32
	.pool
_0814EF18:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5, 0x17]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814EF32:
	mov r0, sp
	bl StringGetEnd10
	b _0814F5BE
	.pool
_0814EF44:
	ldr r0, =gStringInfo
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bhi _0814EF6A
	ldrh r1, [r2]
	b _0814EF8A
	.pool
_0814EF5C:
	ldr r0, =gStringInfo
	ldr r2, [r0]
	ldrh r1, [r2, 0x2]
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bls _0814EF88
_0814EF6A:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	ldr r1, =gText_UnknownMoveTypes
	adds r4, r0, r1
	b _0814F5C0
	.pool
_0814EF88:
	ldrh r1, [r2, 0x2]
_0814EF8A:
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r4, r1, r0
	b _0814F5C0
	.pool
_0814EF98:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0814F06E
	ldr r2, =gLastUsedItem
	ldrh r0, [r2]
	cmp r0, 0xAF
	bne _0814F064
	movs r0, 0x40
	ands r1, r0
	cmp r1, 0
	bne _0814F014
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r0, [r0]
	cmp r0, 0
	beq _0814EFE0
	ldr r2, =gStringBank
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0814EFEC
	b _0814F05C
	.pool
_0814EFE0:
	ldr r2, =gStringBank
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0814F05C
_0814EFEC:
	ldrb r0, [r2]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r0, =gEnigmaBerries
	adds r1, r0
	mov r0, sp
	bl StringCopy
	ldr r1, =gText_BerrySuffix
	mov r0, sp
	bl StringAppend
	b _0814F5BE
	.pool
_0814F014:
	ldr r2, =gLinkPlayers
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gStringBank
	ldrb r2, [r1]
	ldrh r0, [r0, 0x18]
	cmp r0, r2
	bne _0814F05C
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, =gEnigmaBerries
	adds r1, r0
	mov r0, sp
	bl StringCopy
	ldr r1, =gText_BerrySuffix
	mov r0, sp
	bl StringAppend
	b _0814F5BE
	.pool
_0814F05C:
	ldr r4, =gText_EnigmaBerry
	b _0814F5C0
	.pool
_0814F064:
	ldrh r0, [r2]
	mov r1, sp
	bl CopyItemName
	b _0814F5BE
_0814F06E:
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	mov r1, sp
	bl CopyItemName
	b _0814F5BE
	.pool
_0814F080:
	ldr r0, =gLastUsedAbility
	b _0814F0C0
	.pool
_0814F088:
	ldr r1, =gAbilitiesPerBank
	ldr r0, =gBankAttacker
	b _0814F0BC
	.pool
_0814F098:
	ldr r1, =gAbilitiesPerBank
	ldr r0, =gBankTarget
	b _0814F0BC
	.pool
_0814F0A8:
	ldr r1, =gAbilitiesPerBank
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	b _0814F0BE
	.pool
_0814F0B8:
	ldr r1, =gAbilitiesPerBank
	ldr r0, =gEffectBank
_0814F0BC:
	ldrb r0, [r0]
_0814F0BE:
	adds r0, r1
_0814F0C0:
	ldrb r1, [r0]
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gAbilityNames
	adds r4, r1, r0
	b _0814F5C0
	.pool
_0814F0D8:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r1
	cmp r0, 0
	beq _0814F0F0
	bl GetSecretBaseTrainerNameIndex
	b _0814F59C
	.pool
_0814F0F0:
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r2, [r3]
	movs r0, 0xC0
	lsls r0, 4
	cmp r2, r0
	bne _0814F10C
	bl sub_8068BB0
	lsls r0, 16
	lsrs r0, 16
	b _0814F5A0
	.pool
_0814F10C:
	ldr r0, =0x000003fe
	cmp r2, r0
	bne _0814F11C
	bl sub_81A4D00
	b _0814F59C
	.pool
_0814F11C:
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F12C
	ldrh r0, [r3]
	b _0814F598
	.pool
_0814F12C:
	movs r0, 0x80
	lsls r0, 19
	ands r0, r1
	cmp r0, 0
	beq _0814F13E
	ldrh r0, [r3]
	bl sub_81D5530
	b _0814F59C
_0814F13E:
	movs r0, 0x80
	lsls r0, 4
	ands r1, r0
	cmp r1, 0
	beq _0814F14E
	bl sub_8165264
	b _0814F59C
_0814F14E:
	ldr r2, =gTrainers
	ldrh r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	b _0814F5A2
	.pool
_0814F164:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r1
	cmp r0, 0
	beq _0814F1AC
	movs r2, 0
	ldr r4, =gBattleResources
	ldr r3, [r4]
_0814F178:
	mov r1, sp
	adds r0, r1, r2
	ldr r1, [r3]
	adds r1, 0x2
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x6
	ble _0814F178
	mov r3, sp
	adds r1, r3, r2
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r1, [r0, 0xD]
	mov r0, sp
	bl ConvertInternationalString
	b _0814F5BE
	.pool
_0814F1AC:
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r2, [r3]
	movs r0, 0xC0
	lsls r0, 4
	cmp r2, r0
	bne _0814F1C4
	movs r1, 0x1
	adds r0, r7, 0
	eors r0, r1
	b _0814F284
	.pool
_0814F1C4:
	ldr r0, =0x000003fe
	cmp r2, r0
	bne _0814F1D8
	mov r0, sp
	bl sub_81A4D50
	b _0814F5BE
	.pool
_0814F1D8:
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F1E8
	ldrh r1, [r3]
	b _0814F5B8
	.pool
_0814F1E8:
	movs r0, 0x80
	lsls r0, 19
	ands r0, r1
	cmp r0, 0
	beq _0814F1FC
	ldrh r1, [r3]
	mov r0, sp
	bl sub_81D5554
	b _0814F5BE
_0814F1FC:
	movs r0, 0x80
	lsls r0, 4
	ands r1, r0
	cmp r1, 0
	beq _0814F20E
	mov r0, sp
	bl sub_8165284
	b _0814F5BE
_0814F20E:
	ldrh r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTrainers + 0x4 @ name offset
	adds r4, r1, r0
	b _0814F5C0
	.pool
_0814F220:
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	ldr r1, =gLinkPlayers + 8
	adds r4, r0, r1
	b _0814F5C0
	.pool
_0814F230:
	ldr r4, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x18]
	movs r0, 0x2
	b _0814F266
	.pool
_0814F244:
	ldr r4, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x18]
	movs r0, 0x1
	b _0814F266
	.pool
_0814F258:
	ldr r4, =gLinkPlayers
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x18]
	movs r0, 0x3
_0814F266:
	eors r0, r1
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r4, 0x8
	adds r4, r1, r4
	b _0814F5C0
	.pool
_0814F27C:
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	bl sub_806D864
_0814F284:
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r0, =gLinkPlayers + 8
	adds r4, r1, r0
	b _0814F5C0
	.pool
_0814F298:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _0814F2B4
	ldr r4, =gLinkPlayers + 8
	b _0814F5C0
	.pool
_0814F2B4:
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	b _0814F5C0
	.pool
_0814F2C0:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F2E0
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0x2
	b _0814F55A
	.pool
_0814F2E0:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	beq _0814F2F8
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0x4
	b _0814F584
	.pool
_0814F2F8:
	bl sub_80B1CA4
	adds r4, r0, 0
	b _0814F5C0
_0814F300:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F31C
	ldr r0, =gTrainerBattleOpponent_A
	b _0814F556
	.pool
_0814F31C:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	bne _0814F328
	b _0814F5C0
_0814F328:
	ldr r0, =gTrainerBattleOpponent_A
	b _0814F580
	.pool
_0814F330:
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0814F39C
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r1, r0
	ldr r4, =gText_WildPkmnPrefix
	cmp r1, 0
	beq _0814F34E
	ldr r4, =gText_FoePkmnPrefix
_0814F34E:
	ldrb r1, [r4]
	adds r0, r1, 0
	ldr r5, =gEnemyParty
	mov r12, r5
	ldr r2, =gBattleStruct
	cmp r0, 0xFF
	beq _0814F36E
_0814F35C:
	mov r3, r8
	adds r0, r3, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814F35C
_0814F36E:
	ldr r0, [r2]
	adds r0, 0x52
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	add r0, r12
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814F3B4
	.pool
_0814F39C:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x52
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814F3B4:
	mov r0, sp
	bl StringGetEnd10
	b _0814F5BE
	.pool
_0814F3C4:
	ldr r0, =0x000008ab
	bl FlagGet
	lsls r0, 24
	ldr r4, =gText_Someones
	cmp r0, 0
	bne _0814F3D4
	b _0814F5C0
_0814F3D4:
	ldr r4, =gText_Lanettes
	b _0814F5C0
	.pool
_0814F3E4:
	ldr r0, =gBankAttacker
	b _0814F3EE
	.pool
_0814F3EC:
	ldr r0, =gBankTarget
_0814F3EE:
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r4, =gText_FoePkmnPrefix3
	cmp r0, 0
	beq _0814F3FE
	b _0814F5C0
_0814F3FE:
	ldr r4, =gText_AllyPkmnPrefix2
	b _0814F5C0
	.pool
_0814F410:
	ldr r0, =gBankAttacker
	b _0814F41A
	.pool
_0814F418:
	ldr r0, =gBankTarget
_0814F41A:
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r4, =gText_FoePkmnPrefix2
	cmp r0, 0
	beq _0814F42A
	b _0814F5C0
_0814F42A:
	ldr r4, =gText_AllyPkmnPrefix
	b _0814F5C0
	.pool
_0814F43C:
	ldr r0, =gBankAttacker
	b _0814F446
	.pool
_0814F444:
	ldr r0, =gBankTarget
_0814F446:
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r4, =gText_FoePkmnPrefix4
	cmp r0, 0
	beq _0814F456
	b _0814F5C0
_0814F456:
	ldr r4, =gText_AllyPkmnPrefix3
	b _0814F5C0
	.pool
_0814F468:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F484
	ldr r0, =gTrainerBattleOpponent_B
	b _0814F596
	.pool
_0814F484:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	beq _0814F49C
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_81D5530
	b _0814F59C
	.pool
_0814F49C:
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	b _0814F5A2
	.pool
_0814F4B8:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F4D4
	ldr r0, =gTrainerBattleOpponent_B
	b _0814F5B6
	.pool
_0814F4D4:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	beq _0814F4F0
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	mov r0, sp
	bl sub_81D5554
	b _0814F5BE
	.pool
_0814F4F0:
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTrainers + 0x4 @ name offset
	adds r4, r0, r1
	b _0814F5C0
	.pool
_0814F508:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F528
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	movs r0, 0x2
	b _0814F55A
	.pool
_0814F528:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	beq _0814F540
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	movs r0, 0x4
	b _0814F584
	.pool
_0814F540:
	bl sub_80B1CE0
	adds r4, r0, 0
	b _0814F5C0
_0814F548:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0814F574
	ldr r0, =gTrainerBattleOpponent_B
_0814F556:
	ldrh r1, [r0]
	movs r0, 0x1
_0814F55A:
	bl sub_81A36D0
	ldr r4, =gStringVar4
	b _0814F5C0
	.pool
_0814F574:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	beq _0814F5C0
	ldr r0, =gTrainerBattleOpponent_B
_0814F580:
	ldrh r1, [r0]
	movs r0, 0x3
_0814F584:
	bl sub_81D572C
	ldr r4, =gStringVar4
	b _0814F5C0
	.pool
_0814F594:
	ldr r0, =gPartnerTrainerId
_0814F596:
	ldrh r0, [r0]
_0814F598:
	bl GetFrontierOpponentClass
_0814F59C:
	lsls r0, 24
	lsrs r0, 24
_0814F5A0:
	movs r1, 0xD
_0814F5A2:
	muls r1, r0
	ldr r0, =gTrainerClassNames
	adds r4, r1, r0
	b _0814F5C0
	.pool
_0814F5B4:
	ldr r0, =gPartnerTrainerId
_0814F5B6:
	ldrh r1, [r0]
_0814F5B8:
	mov r0, sp
	bl GetFrontierTrainerName
_0814F5BE:
	mov r4, sp
_0814F5C0:
	ldrb r1, [r4]
	adds r0, r1, 0
	mov r5, r9
	ldrb r2, [r5]
	mov r3, r9
	adds r3, 0x1
	cmp r0, 0xFF
	beq _0814F5E2
_0814F5D0:
	mov r5, r8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, 0x1
	adds r4, 0x1
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _0814F5D0
_0814F5E2:
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x24
	beq _0814F5F6
	cmp r0, 0x30
	beq _0814F5F6
	cmp r0, 0x25
	beq _0814F5F6
	cmp r0, 0x31
	bne _0814F61C
_0814F5F6:
	mov r0, r8
	adds r1, r0, r6
	movs r0, 0xFC
	strb r0, [r1]
	adds r6, 0x1
	mov r2, r8
	adds r1, r2, r6
	movs r0, 0x9
	strb r0, [r1]
	adds r6, 0x1
	b _0814F61C
	.pool
_0814F610:
	mov r3, r8
	adds r0, r3, r6
	strb r1, [r0]
	adds r6, 0x1
	mov r3, r9
	adds r3, 0x1
_0814F61C:
	mov r9, r3
	ldrb r1, [r3]
_0814F620:
	adds r0, r1, 0
	cmp r0, 0xFF
	beq _0814F62A
	bl _0814E7A4
_0814F62A:
	mov r5, r8
	adds r1, r5, r6
	mov r2, r9
	ldrb r0, [r2]
	strb r0, [r1]
	adds r6, 0x1
	adds r0, r6, 0
	add sp, 0x20
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end StrCpyDecodeBattle

	thumb_func_start StrCpyDecodeBattleTextBuff
StrCpyDecodeBattleTextBuff: @ 814F648
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r0, 0
	adds r6, r1, 0
	movs r5, 0x1
	movs r0, 0
	mov r8, r0
	movs r0, 0xFF
	strb r0, [r6]
	ldrb r0, [r7, 0x1]
	cmp r0, 0xFF
	bne _0814F666
	b _0814F8EA
_0814F666:
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0xA
	bls _0814F672
	b _0814F8E0
_0814F672:
	lsls r0, r1, 2
	ldr r1, =_0814F680
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814F680:
	.4byte _0814F6AC
	.4byte _0814F6C8
	.4byte _0814F71C
	.4byte _0814F734
	.4byte _0814F744
	.4byte _0814F7BC
	.4byte _0814F7D0
	.4byte _0814F7E2
	.4byte _0814F828
	.4byte _0814F83C
	.4byte _0814F858
_0814F6AC:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r0, =gBattleStringsTable
	subs r1, 0xC
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	b _0814F8BE
	.pool
_0814F6C8:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _0814F6E4
	cmp r0, 0x2
	bgt _0814F6D8
	cmp r0, 0x1
	beq _0814F6DE
	b _0814F706
_0814F6D8:
	cmp r0, 0x4
	beq _0814F6EC
	b _0814F706
_0814F6DE:
	ldrb r4, [r4, 0x3]
	mov r8, r4
	b _0814F706
_0814F6E4:
	ldrb r1, [r4, 0x3]
	ldrb r0, [r4, 0x4]
	lsls r0, 8
	b _0814F702
_0814F6EC:
	ldrb r0, [r4, 0x3]
	mov r8, r0
	ldrb r0, [r4, 0x4]
	lsls r0, 8
	mov r1, r8
	orrs r1, r0
	ldrb r0, [r4, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r4, 0x6]
	lsls r0, 24
_0814F702:
	orrs r1, r0
	mov r8, r1
_0814F706:
	adds r4, r5, r7
	ldrb r3, [r4, 0x2]
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0x3
	ldrb r4, [r4, 0x1]
	adds r5, r0, r4
	b _0814F8E0
_0814F71C:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	b _0814F8BE
	.pool
_0814F734:
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 3
	subs r1, r0
	ldr r0, =gTypeNames
	b _0814F846
	.pool
_0814F744:
	ldrb r0, [r4, 0x1]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814F768
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	b _0814F7A4
	.pool
_0814F768:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0814F788
	ldr r1, =gText_FoePkmnPrefix
	adds r0, r6, 0
	bl StringAppend
	b _0814F790
	.pool
_0814F788:
	ldr r1, =gText_WildPkmnPrefix
	adds r0, r6, 0
	bl StringAppend
_0814F790:
	adds r0, r5, r7
	ldrb r1, [r0, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
_0814F7A4:
	mov r0, sp
	bl StringGetEnd10
	adds r0, r6, 0
	mov r1, sp
	bl StringAppend
	b _0814F8DE
	.pool
_0814F7BC:
	ldr r1, =gStatNamesTable
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _0814F848
	.pool
_0814F7D0:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	adds r0, r6, 0
	bl GetSpeciesName
	b _0814F8DE
_0814F7E2:
	adds r4, r5, r7
	ldrb r0, [r4, 0x1]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0814F808
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
	b _0814F81A
	.pool
_0814F808:
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
_0814F81A:
	adds r0, r6, 0
	bl StringGetEnd10
	b _0814F8DE
	.pool
_0814F828:
	ldr r1, =gPokeblockWasTooXStringTable
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _0814F848
	.pool
_0814F83C:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gAbilityNames
_0814F846:
	adds r1, r0
_0814F848:
	adds r0, r6, 0
	bl StringAppend
	adds r5, 0x2
	b _0814F8E0
	.pool
_0814F858:
	adds r0, r5, r7
	ldrb r2, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r2, r0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0814F8D6
	cmp r2, 0xAF
	bne _0814F8CC
	ldr r2, =gLinkPlayers
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gStringBank
	ldrb r2, [r1]
	ldrh r0, [r0, 0x18]
	cmp r0, r2
	bne _0814F8BC
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, =gEnigmaBerries
	adds r1, r0
	adds r0, r6, 0
	bl StringCopy
	ldr r1, =gText_BerrySuffix
	b _0814F8BE
	.pool
_0814F8BC:
	ldr r1, =gText_EnigmaBerry
_0814F8BE:
	adds r0, r6, 0
	bl StringAppend
	b _0814F8DE
	.pool
_0814F8CC:
	adds r0, r2, 0
	adds r1, r6, 0
	bl CopyItemName
	b _0814F8DE
_0814F8D6:
	adds r0, r2, 0
	adds r1, r6, 0
	bl CopyItemName
_0814F8DE:
	adds r5, 0x3
_0814F8E0:
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0814F8EA
	b _0814F666
_0814F8EA:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end StrCpyDecodeBattleTextBuff

	thumb_func_start sub_814F8F8
sub_814F8F8: @ 814F8F8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r2, 0
	ldr r5, =gStringInfo
	ldr r3, =gUnknown_085CD336
_0814F902:
	cmp r2, 0x4
	beq _0814F918
	ldrh r1, [r3]
	cmp r1, 0
	bne _0814F90E
	adds r2, 0x1
_0814F90E:
	ldr r0, [r5]
	adds r3, 0x2
	ldrh r0, [r0]
	cmp r1, r0
	bne _0814F902
_0814F918:
	cmp r2, 0
	blt _0814F944
	cmp r2, 0x2
	bgt _0814F938
	ldr r1, =gText_SpaceIs
	adds r0, r4, 0
	bl StringCopy
	b _0814F944
	.pool
_0814F938:
	cmp r2, 0x4
	bgt _0814F944
	ldr r1, =gText_ApostropheS
	adds r0, r4, 0
	bl StringCopy
_0814F944:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814F8F8

	thumb_func_start sub_814F950
sub_814F950: @ 814F950
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	b _0814F95A
_0814F958:
	adds r3, 0x1
_0814F95A:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _0814F958
	ldr r1, =gUnknown_085CD336
	ldr r5, =gStringInfo
	movs r0, 0
	lsls r0, 1
	adds r2, r0, r1
_0814F96A:
	cmp r4, 0x4
	beq _0814F984
	ldrh r1, [r2]
	cmp r1, 0
	bne _0814F976
	adds r4, 0x1
_0814F976:
	ldr r0, [r5]
	adds r2, 0x2
	ldrh r0, [r0]
	cmp r1, r0
	bne _0814F96A
	cmp r4, 0x4
	bhi _0814F9E0
_0814F984:
	lsls r0, r4, 2
	ldr r1, =_0814F99C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0814F99C:
	.4byte _0814F9B0
	.4byte _0814F9B8
	.4byte _0814F9C0
	.4byte _0814F9C8
	.4byte _0814F9D8
_0814F9B0:
	ldr r1, =gText_ExclamationMark
	b _0814F9CA
	.pool
_0814F9B8:
	ldr r1, =gText_ExclamationMark2
	b _0814F9CA
	.pool
_0814F9C0:
	ldr r1, =gText_ExclamationMark3
	b _0814F9CA
	.pool
_0814F9C8:
	ldr r1, =gText_ExclamationMark4
_0814F9CA:
	adds r0, r3, 0
	bl StringCopy
	b _0814F9E0
	.pool
_0814F9D8:
	ldr r1, =gText_ExclamationMark5
	adds r0, r3, 0
	bl StringCopy
_0814F9E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814F950

	thumb_func_start battle_show_message_maybe
battle_show_message_maybe: @ 814F9EC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r1, =gUnknown_085CD660
	ldr r0, =gBattleScripting
	adds r0, 0x24
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r0, 0x80
	ands r0, r7
	cmp r0, 0
	beq _0814FA24
	movs r0, 0x7F
	ands r7, r0
	movs r0, 0
	b _0814FA36
	.pool
_0814FA24:
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	add r0, r8
	ldrb r1, [r0]
	adds r0, r7, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
_0814FA36:
	mov r9, r0
	str r4, [sp]
	mov r0, sp
	strb r7, [r0, 0x4]
	mov r1, sp
	lsls r6, r7, 1
	adds r3, r6, r7
	lsls r3, 2
	add r3, r8
	ldrb r0, [r3, 0x1]
	strb r0, [r1, 0x5]
	ldrb r0, [r3, 0x2]
	strb r0, [r1, 0x6]
	ldrb r0, [r3, 0x3]
	strb r0, [r1, 0x7]
	mov r0, sp
	ldrb r0, [r0, 0x6]
	strb r0, [r1, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	ldrb r0, [r3, 0x4]
	strb r0, [r1, 0xA]
	ldrb r0, [r3, 0x5]
	strb r0, [r1, 0xB]
	mov r4, sp
	ldrb r2, [r4, 0xC]
	movs r1, 0x10
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4, 0xC]
	mov r2, sp
	ldrb r0, [r3, 0x7]
	lsls r0, 4
	movs r5, 0xF
	strb r0, [r2, 0xC]
	ldrb r2, [r3, 0x8]
	adds r0, r5, 0
	ands r0, r2
	ldrb r2, [r4, 0xD]
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xD]
	mov r2, sp
	ldrb r0, [r3, 0x9]
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strb r1, [r2, 0xD]
	mov r0, sp
	ldrb r0, [r0, 0x6]
	cmp r0, 0xFF
	bne _0814FAC6
	ldr r0, =gBattleScripting
	adds r0, 0x24
	ldrb r0, [r0]
	adds r1, r7, 0
	bl sub_80397C4
	adds r2, r0, 0
	mov r0, sp
	ldrb r0, [r0, 0x5]
	ldr r1, [sp]
	mov r3, sp
	ldrb r3, [r3, 0xA]
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	mov r2, sp
	mov r1, sp
	strb r0, [r1, 0x8]
	strb r0, [r2, 0x6]
_0814FAC6:
	cmp r7, 0x16
	bne _0814FAE0
	ldr r0, =gTextFlags
	ldrb r2, [r0]
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	b _0814FAE8
	.pool
_0814FAE0:
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
_0814FAE8:
	strb r1, [r0]
	adds r3, r0, 0
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r2, =0x01000002
	ands r1, r2
	adds r2, r0, 0
	cmp r1, 0
	beq _0814FB10
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	b _0814FB18
	.pool
_0814FB10:
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
_0814FB18:
	strb r0, [r3]
	cmp r7, 0
	beq _0814FB22
	cmp r7, 0x16
	bne _0814FB6C
_0814FB22:
	ldr r1, [r2]
	ldr r0, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0814FB34
	movs r6, 0x1
	b _0814FB5C
	.pool
_0814FB34:
	movs r0, 0x80
	lsls r0, 17
	ands r1, r0
	cmp r1, 0
	beq _0814FB54
	ldr r4, =gUnknown_085CD668
	bl sub_8185FC4
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r6, [r0]
	b _0814FB5C
	.pool
_0814FB54:
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r6, r0, 24
_0814FB5C:
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _0814FB7E
	.pool
_0814FB6C:
	adds r0, r6, r7
	lsls r0, 2
	add r0, r8
	ldrb r6, [r0, 0x6]
	ldrb r1, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_0814FB7E:
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0
	bl AddTextPrinter
	mov r0, r9
	cmp r0, 0
	beq _0814FB9C
	adds r0, r7, 0
	bl PutWindowTilemap
	adds r0, r7, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0814FB9C:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end battle_show_message_maybe

	thumb_func_start sub_814FBAC
sub_814FBAC: @ 814FBAC
	push {r4,r5,lr}
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r1, r2, 9
	ldr r0, =gBattleBufferA + 4
	adds r1, r0
	ldr r4, =gUnknown_08D85620
	ldr r0, =gUnknown_020244B0
	adds r2, r0
	ldrb r2, [r2]
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r2
	ldrb r0, [r0]
	adds r1, 0xC
	adds r1, r2
	ldrb r1, [r1]
	bl sub_814FC20
	lsls r0, 24
	ldr r5, =gPlttBufferUnfaded
	lsrs r0, 22
	adds r0, r4
	ldrh r1, [r0]
	adds r2, r5, 0
	adds r2, 0xB8
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	adds r5, 0xB6
	strh r0, [r5]
	ldr r4, =gPlttBufferFaded + 0xB8
	adds r0, r2, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl CpuSet
	subs r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl CpuSet
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814FBAC

	thumb_func_start sub_814FC20
sub_814FC20: @ 814FC20
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, r2
	beq _0814FC68
	cmp r0, 0x2
	bhi _0814FC3A
	cmp r2, 0x1
	bhi _0814FC68
	b _0814FC42
_0814FC3A:
	cmp r0, 0x7
	bhi _0814FC4C
	cmp r2, 0x2
	bhi _0814FC68
_0814FC42:
	movs r0, 0x2
	subs r0, r2
	lsls r0, 24
	lsrs r0, 24
	b _0814FC6A
_0814FC4C:
	cmp r2, 0
	bne _0814FC54
	movs r0, 0x2
	b _0814FC6A
_0814FC54:
	lsrs r0, r1, 26
	cmp r2, r0
	bhi _0814FC5E
	movs r0, 0x1
	b _0814FC6A
_0814FC5E:
	lsrs r0, r1, 25
	cmp r3, r0
	bhi _0814FC68
	movs r0, 0
	b _0814FC6A
_0814FC68:
	movs r0, 0x3
_0814FC6A:
	pop {r1}
	bx r1
	thumb_func_end sub_814FC20

	.align 2, 0 @ Don't pad with nop.
