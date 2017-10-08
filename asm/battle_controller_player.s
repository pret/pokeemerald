	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_21
nullsub_21: @ 8057458
	bx lr
	thumb_func_end nullsub_21

	thumb_func_start SetBankFuncToPlayerBufferRunCommand
SetBankFuncToPlayerBufferRunCommand: @ 805745C
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =PlayerBufferRunCommand
	str r1, [r0]
	ldr r0, =gDoingBattleAnim
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_020244CC
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end SetBankFuncToPlayerBufferRunCommand

	thumb_func_start PlayerBufferExecCompleted
PlayerBufferExecCompleted: @ 805748C
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =PlayerBufferRunCommand
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080574E0
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
	b _080574F2
	.pool
_080574E0:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_080574F2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayerBufferExecCompleted

	thumb_func_start PlayerBufferRunCommand
PlayerBufferRunCommand: @ 8057504
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
	beq _08057550
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _0805754C
	ldr r0, =gPlayerBufferCommands
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _08057550
	.pool
_0805754C:
	bl PlayerBufferExecCompleted
_08057550:
	pop {r0}
	bx r0
	thumb_func_end PlayerBufferRunCommand

	thumb_func_start bx_0802E404
bx_0802E404: @ 8057554
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
	adds r0, r2
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08057576
	bl PlayerBufferExecCompleted
_08057576:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_0802E404

	thumb_func_start sub_8057588
sub_8057588: @ 8057588
	push {r4-r7,lr}
	ldr r3, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r2, r0, 9
	adds r1, r3, 0x2
	adds r1, r2, r1
	ldrb r5, [r1]
	adds r3, 0x3
	adds r2, r3
	ldrb r1, [r2]
	lsls r1, 8
	orrs r5, r1
	movs r1, 0x1
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	beq _080575EC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _080575EC
	ldr r1, =gUnknown_020244CC
	ldrb r0, [r1]
	adds r0, 0x1
	b _080575F0
	.pool
_080575EC:
	ldr r1, =gUnknown_020244CC
	movs r0, 0
_080575F0:
	strb r0, [r1]
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _08057658
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gActionSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08057640
	cmp r0, 0x1
	bgt _08057630
	cmp r0, 0
	beq _0805763A
	b _080577C2
	.pool
_08057630:
	cmp r0, 0x2
	beq _08057646
	cmp r0, 0x3
	beq _0805764C
	b _080577C2
_0805763A:
	movs r0, 0x1
	movs r1, 0
	b _080577BC
_08057640:
	movs r0, 0x1
	movs r1, 0x1
	b _080577BC
_08057646:
	movs r0, 0x1
	movs r1, 0x2
	b _080577BC
_0805764C:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _080577C2
_08057658:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _08057698
	ldr r5, =gActionSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08057674
	b _080577E8
_08057674:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	b _08057732
	.pool
_08057698:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _080576D8
	ldr r5, =gActionSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080576B4
	b _080577E8
_080576B4:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	b _08057732
	.pool
_080576D8:
	movs r7, 0x40
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _08057700
	ldr r5, =gActionSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080577E8
	b _0805771A
	.pool
_08057700:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _0805774C
	ldr r5, =gActionSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080577E8
_0805771A:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x2
_08057732:
	eors r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	b _080577E8
	.pool
_0805774C:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _0805775A
	ldrb r0, [r1]
	cmp r0, 0x3B
	bls _080577DC
_0805775A:
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	ands r0, r3
	cmp r0, 0
	beq _080577E8
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080577E8
	movs r0, 0
	bl GetBankByIdentity
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _080577E8
	ldr r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _080577E8
	ldr r0, =gBattleBufferA
	ldrb r1, [r6]
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _080577B2
	cmp r5, 0xC
	bhi _080577E8
	adds r0, r5, 0
	movs r1, 0x1
	bl AddBagItem
_080577B2:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	movs r1, 0xC
_080577BC:
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_080577C2:
	bl PlayerBufferExecCompleted
	b _080577E8
	.pool
_080577DC:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _080577E8
	bl sub_8073314
_080577E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8057588

	thumb_func_start sub_80577F0
sub_80577F0: @ 80577F0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	ldrb r0, [r4]
	movs r1, 0
	bl dp11b_obj_free
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057824
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80577F0

	thumb_func_start sub_8057824
sub_8057824: @ 8057824
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_0831C5F8
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	movs r1, 0x1
	movs r2, 0xF
	movs r3, 0x1
	bl dp11b_obj_instanciate
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0
	beq _08057866
_0805784A:
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	cmp r4, r0
	beq _0805785C
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0x1
	bl dp11b_obj_free
_0805785C:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0805784A
_08057866:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	beq _0805789C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _0805789C
	ldr r1, =gUnknown_020244CC
	ldrb r0, [r1]
	adds r0, 0x1
	b _080578A0
	.pool
_0805789C:
	ldr r1, =gUnknown_020244CC
	movs r0, 0
_080578A0:
	strb r0, [r1]
	ldrh r2, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08057910
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	ldr r1, =gMoveSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldrb r0, [r4]
	lsls r0, 8
	orrs r2, r0
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	bl PlayerBufferExecCompleted
	b _08057BC8
	.pool
_08057910:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _0805791E
	ldrb r0, [r1]
	cmp r0, 0x3B
	bls _0805798C
_0805791E:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r5, =gUnknown_03005D74
	ldrb r0, [r5]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
	ldrb r0, [r4]
	movs r1, 0x1
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldrb r0, [r5]
	movs r1, 0x1
	bl dp11b_obj_free
	b _08057BC8
	.pool
_0805798C:
	movs r0, 0x60
	ands r0, r2
	cmp r0, 0
	bne _08057996
	b _08057AB0
_08057996:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r3, =gUnknown_03005D74
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	adds r5, r3, 0
_080579B8:
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	mov r0, sp
	b _080579E2
	.pool
_080579D8:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080579E8
	mov r2, sp
	adds r0, r2, r4
_080579E2:
	ldrb r0, [r0]
	cmp r1, r0
	bne _080579D8
_080579E8:
	subs r4, 0x1
	cmp r4, 0
	bge _080579F0
	movs r4, 0x4
_080579F0:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetBankByIdentity
	strb r0, [r5]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _080579E8
	movs r4, 0
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08057A6E
	cmp r0, 0x1
	bgt _08057A28
	cmp r0, 0
	beq _08057A32
	b _08057A70
	.pool
_08057A28:
	cmp r0, 0x2
	beq _08057A32
	cmp r0, 0x3
	beq _08057A6E
	b _08057A70
_08057A32:
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldrb r1, [r5]
	cmp r0, r1
	bne _08057A6E
	ldr r1, =gBattlePartyID
	ldrb r2, [r2]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gMoveSelectionCursor
	adds r2, r1
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08057A70
_08057A6E:
	adds r4, 0x1
_08057A70:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	ldr r0, =gUnknown_03005D74
	cmp r1, 0
	beq _08057A88
	movs r4, 0
_08057A88:
	cmp r4, 0
	beq _080579B8
	b _08057BB0
	.pool
_08057AB0:
	movs r0, 0x90
	ands r0, r2
	cmp r0, 0
	bne _08057ABA
	b _08057BC8
_08057ABA:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r3, =gUnknown_03005D74
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	adds r5, r3, 0
_08057ADC:
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	mov r0, sp
	b _08057B06
	.pool
_08057AFC:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08057B0C
	mov r2, sp
	adds r0, r2, r4
_08057B06:
	ldrb r0, [r0]
	cmp r1, r0
	bne _08057AFC
_08057B0C:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08057B14
	movs r4, 0
_08057B14:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetBankByIdentity
	strb r0, [r5]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _08057B0C
	movs r4, 0
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08057B92
	cmp r0, 0x1
	bgt _08057B4C
	cmp r0, 0
	beq _08057B56
	b _08057B94
	.pool
_08057B4C:
	cmp r0, 0x2
	beq _08057B56
	cmp r0, 0x3
	beq _08057B92
	b _08057B94
_08057B56:
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldrb r1, [r5]
	cmp r0, r1
	bne _08057B92
	ldr r1, =gBattlePartyID
	ldrb r2, [r2]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gMoveSelectionCursor
	adds r2, r1
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08057B94
_08057B92:
	adds r4, 0x1
_08057B94:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	ldr r0, =gUnknown_03005D74
	cmp r1, 0
	beq _08057BAC
	movs r4, 0
_08057BAC:
	cmp r4, 0
	beq _08057ADC
_08057BB0:
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039AD8
	str r1, [r0]
_08057BC8:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8057824

	thumb_func_start sub_8057BFC
sub_8057BFC: @ 8057BFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	ldr r1, =gBattleBufferA + 4
	adds r6, r0, r1
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0xF0
	ands r0, r1
	adds r7, r3, 0
	cmp r0, 0
	beq _08057C44
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _08057C44
	ldr r1, =gUnknown_020244CC
	ldrb r0, [r1]
	adds r0, 0x1
	b _08057C48
	.pool
_08057C44:
	ldr r1, =gUnknown_020244CC
	movs r0, 0
_08057C48:
	strb r0, [r1]
	ldrh r2, [r2, 0x2E]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	bne _08057C58
	b _08057E04
_08057C58:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gMoveSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, 0xAE
	bne _08057C98
	ldrb r0, [r6, 0x12]
	movs r4, 0
	cmp r0, 0x7
	beq _08057CA6
	ldrb r1, [r6, 0x13]
	movs r0, 0x7
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r4, r0, 31
	movs r0, 0x10
	ands r4, r0
	b _08057CA6
	.pool
_08057C98:
	ldr r2, =gBattleMoves
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r4, [r0, 0x6]
_08057CA6:
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _08057CC4
	ldr r0, =gUnknown_03005D74
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	strb r1, [r0]
	b _08057CDE
	.pool
_08057CC4:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	bl GetBankByIdentity
	ldr r1, =gUnknown_03005D74
	strb r0, [r1]
_08057CDE:
	ldr r5, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r2, r3, 9
	adds r1, r5, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r7, r0, 0
	cmp r1, 0
	bne _08057D18
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _08057D5A
	adds r0, r5, 0x2
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08057D5A
	movs r0, 0x1
	add r8, r0
	b _08057D5A
	.pool
_08057D18:
	movs r0, 0x7D
	ands r0, r4
	cmp r0, 0
	bne _08057D24
	movs r0, 0x1
	add r8, r0
_08057D24:
	ldr r0, =gMoveSelectionCursor
	adds r0, r3, r0
	adds r1, r6, 0
	adds r1, 0x8
	ldrb r0, [r0]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08057D62
	movs r0, 0x12
	ands r0, r4
	cmp r0, 0
	bne _08057D5A
	movs r0, 0
	bl CountAliveMonsInBattle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08057D5A
	ldrb r0, [r7]
	bl sub_8069F34
	ldr r1, =gUnknown_03005D74
	strb r0, [r1]
	movs r0, 0
	mov r8, r0
_08057D5A:
	ldr r7, =gActiveBank
	mov r0, r8
	cmp r0, 0
	bne _08057D80
_08057D62:
	ldr r1, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r0, r1
	ldrb r2, [r0]
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	lsls r0, 8
	orrs r2, r0
	b _08057E1C
	.pool
_08057D80:
	ldr r1, =gBattleBankFunc
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057824
	str r1, [r0]
	movs r0, 0x12
	ands r4, r0
	cmp r4, 0
	beq _08057DA8
	ldr r1, =gUnknown_03005D74
	ldrb r0, [r7]
	b _08057DD8
	.pool
_08057DA8:
	movs r0, 0x1
	bl GetBankByIdentity
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08057DD0
	movs r0, 0x3
	b _08057DD2
	.pool
_08057DD0:
	movs r0, 0x1
_08057DD2:
	bl GetBankByIdentity
	ldr r1, =gUnknown_03005D74
_08057DD8:
	strb r0, [r1]
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039AD8
	b _08057F9C
	.pool
_08057E04:
	movs r6, 0x2
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	bne _08057E14
	ldrb r0, [r1]
	cmp r0, 0x3B
	bls _08057E30
_08057E14:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =0x0000ffff
_08057E1C:
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	bl PlayerBufferExecCompleted
	b _08057F9E
	.pool
_08057E30:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _08057E60
	ldr r4, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r2, r0, r4
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08057E4A
	b _08057F9E
_08057E4A:
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	b _08057F08
	.pool
_08057E60:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _08057EA4
	ldr r4, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r3, r0, r4
	ldrb r2, [r3]
	movs r6, 0x1
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08057E7C
	b _08057F9E
_08057E7C:
	ldr r1, =gUnknown_03005D78
	adds r0, r6, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08057E8A
	b _08057F9E
_08057E8A:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	eors r0, r6
	b _08057F08
	.pool
_08057EA4:
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08057ED4
	ldr r4, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r2, r0, r4
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08057F9E
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	movs r2, 0x2
	eors r0, r2
	b _08057F08
	.pool
_08057ED4:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _08057F30
	ldr r4, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r3, r0, r4
	ldrb r2, [r3]
	movs r5, 0x2
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	bne _08057F9E
	ldr r1, =gUnknown_03005D78
	adds r0, r5, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08057F9E
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	eors r0, r5
_08057F08:
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	bl sub_8059B3C
	bl sub_8059BB0
	b _08057F9E
	.pool
_08057F30:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _08057F9E
	ldr r0, =gUnknown_03005D78
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08057F9E
	ldr r0, =gBattleTypeFlags
	ldr r5, [r0]
	ands r5, r6
	cmp r5, 0
	bne _08057F9E
	ldr r4, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08057F78
	ldr r0, =gUnknown_03005D74
	strb r5, [r0]
	b _08057F80
	.pool
_08057F78:
	ldr r1, =gUnknown_03005D74
	adds r0, 0x1
	strb r0, [r1]
	adds r0, r1, 0
_08057F80:
	ldrb r0, [r0]
	movs r1, 0x1B
	bl battle_menu_cursor_related_2
	ldr r0, =gText_BattleSwitchWhich
	movs r1, 0xB
	bl sub_814F9EC
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058138
_08057F9C:
	str r1, [r0]
_08057F9E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8057BFC

	thumb_func_start sub_8057FBC
sub_8057FBC: @ 8057FBC
	push {r4-r7,lr}
	movs r7, 0
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08057FD6
	movs r0, 0x5
	bl PlaySE
	movs r7, 0x1
_08057FD6:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08057FF8
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gBattle_BG0_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG0_Y
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	movs r7, 0xFF
_08057FF8:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08058038
	ldr r5, =gMoveSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r2, r0, r5
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08058038
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_08058038:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08058086
	ldr r5, =gMoveSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r3, r0, r5
	ldrb r2, [r3]
	movs r6, 0x1
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _08058086
	ldr r1, =gUnknown_03005D78
	adds r0, r6, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08058086
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	eors r0, r6
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_08058086:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080580C8
	ldr r5, =gMoveSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r2, r0, r5
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080580C8
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x2
	eors r0, r2
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_080580C8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08058116
	ldr r5, =gMoveSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r3, r0, r5
	ldrb r2, [r3]
	movs r6, 0x2
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _08058116
	ldr r1, =gUnknown_03005D78
	adds r0, r6, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08058116
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	eors r0, r6
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_08058116:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8057FBC

	thumb_func_start sub_8058138
sub_8058138: @ 8058138
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x5
	ands r0, r1
	cmp r0, 0
	bne _08058152
	b _08058500
_08058152:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gMoveSelectionCursor
	mov r10, r0
	ldr r1, =gActiveBank
	mov r8, r1
	ldrb r1, [r1]
	adds r2, r1, r0
	ldr r5, =gUnknown_03005D74
	ldrb r0, [r2]
	ldrb r3, [r5]
	cmp r0, r3
	bne _08058170
	b _080584A8
_08058170:
	lsls r1, 9
	ldr r0, =gBattleBufferA + 4
	adds r1, r0
	mov r9, r1
	ldrb r1, [r2]
	lsls r1, 1
	add r1, r9
	ldrh r6, [r1]
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r9
	strh r6, [r0]
	mov r1, r8
	ldrb r0, [r1]
	add r0, r10
	ldrb r1, [r0]
	mov r7, r9
	adds r7, 0x8
	adds r1, r7, r1
	ldrb r6, [r1]
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, r7, r0
	strb r6, [r0]
	mov r2, r8
	ldrb r0, [r2]
	add r0, r10
	ldrb r1, [r0]
	mov r2, r9
	adds r2, 0xC
	adds r1, r2, r1
	ldrb r6, [r1]
	ldrb r0, [r5]
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r5]
	adds r2, r0
	strb r6, [r2]
	mov r3, r8
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r2, =gDisableStructs
	adds r6, r0, r2
	ldrb r4, [r6, 0x18]
	lsls r3, r4, 24
	lsrs r2, r3, 28
	ldr r0, =gBitTable
	mov r12, r0
	add r1, r10
	ldrb r0, [r1]
	lsls r0, 2
	add r0, r12
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _0805822A
	lsrs r1, r3, 28
	bics r1, r0
	lsls r1, 4
	movs r2, 0xF
	adds r0, r2, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r6, 0x18]
	mov r1, r8
	ldrb r0, [r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r3, =gDisableStructs
	adds r1, r3
	ldrb r4, [r1, 0x18]
	lsrs r3, r4, 4
	ldrb r0, [r5]
	lsls r0, 2
	add r0, r12
	ldr r0, [r0]
	orrs r0, r3
	lsls r0, 4
	ands r2, r4
	orrs r2, r0
	strb r2, [r1, 0x18]
_0805822A:
	bl sub_8059AAC
	movs r6, 0
	mov r12, r7
	mov r5, sp
	adds r5, 0x18
	str r5, [sp, 0x1C]
	ldr r2, =gBattleMons
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r4, r0, 0
	adds r4, 0x3B
	mov r7, r8
	mov r10, r2
	movs r5, 0x3
_0805824E:
	mov r1, sp
	adds r3, r1, r6
	ldrb r1, [r4]
	lsls r2, r6, 1
	adds r0, r5, 0
	lsls r0, r2
	ands r1, r0
	asrs r1, r2
	strb r1, [r3]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805824E
	ldr r1, =gMoveSelectionCursor
	ldrb r0, [r7]
	adds r0, r1
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
	ldr r2, [sp, 0x1C]
	strb r0, [r2]
	ldrb r0, [r7]
	adds r0, r1
	ldrb r0, [r0]
	mov r3, sp
	adds r2, r3, r0
	ldr r1, =gUnknown_03005D74
	ldrb r0, [r1]
	add r0, sp
	ldrb r0, [r0]
	movs r3, 0
	strb r0, [r2]
	ldrb r0, [r1]
	mov r5, sp
	adds r1, r5, r0
	ldr r2, [sp, 0x1C]
	ldrb r0, [r2]
	strb r0, [r1]
	strb r3, [r2]
	movs r6, 0
	ldr r2, [sp, 0x1C]
_0805829E:
	mov r3, sp
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r6, 1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805829E
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	add r0, r10
	adds r0, 0x3B
	ldr r5, [sp, 0x1C]
	ldrb r1, [r5]
	strb r1, [r0]
	movs r6, 0
	adds r4, r7, 0
	movs r3, 0x58
	movs r0, 0x24
	add r0, r10
	mov r8, r0
	mov r2, r9
	mov r7, r10
	adds r7, 0xC
	mov r5, r12
_080582D8:
	lsls r1, r6, 1
	ldrb r0, [r4]
	muls r0, r3
	adds r1, r0
	adds r1, r7
	ldrh r0, [r2]
	strh r0, [r1]
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r3
	adds r1, r6, r1
	add r1, r8
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _080582D8
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	mov r1, r10
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	beq _0805831A
	b _080584A8
_0805831A:
	movs r6, 0
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x20]
	add r3, sp, 0xC
	mov r10, r3
	ldr r5, =gBattlePartyID
	mov r9, r5
	mov r8, r2
	movs r7, 0x64
	ldr r5, =gPlayerParty
	adds r4, r1, 0
_08058332:
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r5
	adds r1, r6, 0
	adds r1, 0xD
	bl GetMonData
	strh r0, [r4]
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r5
	adds r1, r6, 0
	adds r1, 0x11
	bl GetMonData
	mov r3, r10
	adds r1, r3, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08058332
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
	movs r1, 0x15
	bl GetMonData
	ldr r5, [sp, 0x1C]
	strb r0, [r5]
	movs r6, 0
	movs r5, 0x3
	ldr r4, [sp, 0x1C]
_08058392:
	mov r0, sp
	adds r3, r0, r6
	lsls r2, r6, 1
	adds r1, r5, 0
	lsls r1, r2
	ldrb r0, [r4]
	ands r0, r1
	asrs r0, r2
	strb r0, [r3]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08058392
	ldr r4, =gMoveSelectionCursor
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	adds r0, r4
	ldrb r1, [r0]
	lsls r1, 1
	ldr r2, [sp, 0x20]
	adds r1, r2, r1
	ldrh r6, [r1]
	ldr r2, =gUnknown_03005D74
	ldrb r0, [r2]
	lsls r0, 1
	ldr r5, [sp, 0x20]
	adds r0, r5, r0
	ldrh r0, [r0]
	movs r5, 0
	strh r0, [r1]
	ldrb r0, [r2]
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r0, r1, r0
	strh r6, [r0]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r1, [r0]
	add r1, r10
	ldrb r6, [r1]
	ldrb r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	add r0, r10
	strb r6, [r0]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	mov r3, sp
	adds r1, r3, r0
	ldrb r0, [r2]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	adds r1, r3, r0
	ldr r2, [sp, 0x1C]
	ldrb r0, [r2]
	strb r0, [r1]
	strb r5, [r2]
	movs r6, 0
	ldr r2, [sp, 0x1C]
_0805841E:
	mov r3, sp
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r6, 1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805841E
	movs r6, 0
	ldr r5, =gBattlePartyID
	mov r10, r5
	ldr r0, =gActiveBank
	mov r9, r0
	movs r1, 0x64
	mov r8, r1
	ldr r7, =gPlayerParty
	ldr r5, [sp, 0x20]
	adds r5, 0x8
	ldr r4, [sp, 0x20]
_0805844A:
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r0, r7
	adds r1, r6, 0
	adds r1, 0xD
	adds r2, r4, 0
	bl SetMonData
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	adds r1, r6, 0
	adds r1, 0x11
	adds r2, r5, 0
	bl SetMonData
	adds r5, 0x1
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805844A
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
	movs r1, 0x15
	ldr r2, [sp, 0x1C]
	bl SetMonData
_080584A8:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
	ldr r3, =gMoveSelectionCursor
	ldrb r0, [r2]
	adds r0, r3
	ldr r1, =gUnknown_03005D74
	ldrb r1, [r1]
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	b _08058532
	.pool
_08058500:
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	beq _08058554
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	bl battle_menu_cursor_related
	ldr r1, =gMoveSelectionCursor
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
_08058532:
	bl sub_8059B18
	bl sub_8059B3C
	bl sub_8059BB0
	b _080586E8
	.pool
_08058554:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080585A4
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _0805856A
	b _080586E8
_0805856A:
	ldr r0, =gMoveSelectionCursor
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r5, [r1]
	cmp r2, r5
	bne _08058590
_08058578:
	ldrb r0, [r1]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	b _08058596
	.pool
_08058590:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
_08058596:
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	movs r1, 0x1
	b _0805862C
	.pool
_080585A4:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080585E8
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _080585BA
	b _080586E8
_080585BA:
	ldr r1, =gUnknown_03005D78
	movs r0, 0x1
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcc _080585C8
	b _080586E8
_080585C8:
	ldr r0, =gMoveSelectionCursor
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r0, [r1]
	cmp r2, r0
	beq _08058578
	b _08058590
	.pool
_080585E8:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805865C
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _080586E8
	ldr r0, =gMoveSelectionCursor
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r5, [r1]
	cmp r2, r5
	bne _08058620
	ldrb r0, [r1]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	b _08058626
	.pool
_08058620:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
_08058626:
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	movs r1, 0x2
_0805862C:
	eors r0, r1
	strb r0, [r4]
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gMoveSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080586CA
	ldrb r0, [r4]
	movs r1, 0x1B
	bl battle_menu_cursor_related_2
	b _080586E8
	.pool
_0805865C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080586E8
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _080586E8
	ldr r1, =gUnknown_03005D78
	movs r0, 0x2
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080586E8
	ldr r0, =gMoveSelectionCursor
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r0, [r1]
	cmp r2, r0
	bne _080586A4
	ldrb r0, [r1]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	b _080586AA
	.pool
_080586A4:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
_080586AA:
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	movs r1, 0x2
	eors r0, r1
	strb r0, [r4]
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gMoveSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	bne _080586E0
_080586CA:
	adds r0, r1, 0
	movs r1, 0
	bl battle_menu_cursor_related_2
	b _080586E8
	.pool
_080586E0:
	ldrb r0, [r4]
	movs r1, 0x1B
	bl battle_menu_cursor_related_2
_080586E8:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8058138

	thumb_func_start sub_80586F8
sub_80586F8: @ 80586F8
	push {lr}
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805875C
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _08058798
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r3, =gMain
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gPreBattleCallback1
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, =sub_8038D64
	bl SetMainCallback2
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08058738
	bl sub_817E3F4
_08058738:
	bl FreeAllWindowBuffers
	b _08058798
	.pool
_0805875C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08058798
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r3, =gMain
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gPreBattleCallback1
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, =sub_8038D64
	bl SetMainCallback2
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08058794
	bl sub_817E3F4
_08058794:
	bl FreeAllWindowBuffers
_08058798:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80586F8

	thumb_func_start sub_80587B0
sub_80587B0: @ 80587B0
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08058832
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08058810
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08058832
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080587F0
	bl sub_800AC34
	b _080587F4
	.pool
_080587F0:
	bl sub_800ADF8
_080587F4:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80586F8
	str r1, [r0]
	b _08058832
	.pool
_08058810:
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r2, =gMain
	ldr r0, =0x00000439
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r0, =gPreBattleCallback1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	bl SetMainCallback2
_08058832:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80587B0

	thumb_func_start sub_8058844
sub_8058844: @ 8058844
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
	bne _08058868
	bl PlayerBufferExecCompleted
_08058868:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058844

	thumb_func_start sub_805887C
sub_805887C: @ 805887C
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
	bne _080588A0
	bl PlayerBufferExecCompleted
_080588A0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805887C

	thumb_func_start bx_802F7A0
bx_802F7A0: @ 80588B4
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
	bne _08058908
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
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
	bl PlayerBufferExecCompleted
_08058908:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_802F7A0

	thumb_func_start sub_8058924
sub_8058924: @ 8058924
	push {r4,lr}
	ldr r4, =gBattleSpritesDataPtr
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
	bne _0805895C
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl PlayerBufferExecCompleted
_0805895C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058924

	thumb_func_start sub_805896C
sub_805896C: @ 805896C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r7, 0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058998
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080589D0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080589D0
_08058998:
	ldr r2, =gSprites
	ldr r1, =gHealthBoxesIds
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	mov r10, r3
	cmp r1, r0
	bne _08058A0A
	b _08058A0E
	.pool
_080589D0:
	ldr r3, =gSprites
	ldr r6, =gHealthBoxesIds
	ldr r2, =gActiveBank
	ldrb r4, [r2]
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r3, 0
	adds r5, 0x1C
	adds r0, r5
	ldr r3, [r0]
	ldr r0, =SpriteCallbackDummy
	mov r10, r2
	cmp r3, r0
	bne _08058A0A
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r3
	bne _08058A0A
	movs r7, 0x1
_08058A0A:
	cmp r7, 0
	beq _08058B08
_08058A0E:
	ldr r0, =gBattleSpritesDataPtr
	mov r9, r0
	ldr r0, [r0]
	mov r6, r10
	ldrb r2, [r6]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r3
	ldrb r1, [r4, 0x1]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08058B08
	movs r1, 0x2
	mov r8, r1
	mov r1, r8
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08058B08
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r2, r9
	ldr r0, [r2]
	ldrb r2, [r6]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	mov r0, r9
	ldr r2, [r0]
	ldrb r0, [r6]
	mov r1, r8
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	mov r1, r9
	ldr r2, [r1]
	ldrb r0, [r6]
	mov r1, r8
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	ands r4, r1
	strb r4, [r0, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldr r7, =gBattlePartyID
	ldrb r1, [r6]
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	bl sub_805E990
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058AE4
	ldrb r0, [r6]
	mov r1, r8
	eors r1, r0
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	bl sub_805E990
_08058AE4:
	mov r2, r9
	ldr r0, [r2]
	mov r2, r10
	ldrb r1, [r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x9]
	ldr r1, =gBattleBankFunc
	mov r2, r10
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058924
	str r1, [r0]
_08058B08:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805896C

	thumb_func_start sub_8058B40
sub_8058B40: @ 8058B40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	mov r9, r0
	mov r8, r0
	ldr r4, =gBattleSpritesDataPtr
	ldr r0, [r4]
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r5, 0x88
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058B80
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08058B80:
	ldr r1, [r4]
	ldrb r0, [r7]
	movs r6, 0x2
	adds r2, r6, 0
	eors r2, r0
	ldr r1, [r1, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058BB2
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08058BB2:
	ldr r0, [r4]
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
	bne _08058C82
	adds r1, r6, 0
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058C82
	ldrb r1, [r4, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08058C68
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058C38
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08058C38
	ldr r4, =gHealthBoxesIds
	ldrb r0, [r7]
	adds r1, r6, 0
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
	eors r0, r6
	bl sub_8076918
	ldrb r0, [r7]
	eors r0, r6
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_08058C38:
	ldr r5, =gHealthBoxesIds
	ldr r4, =gActiveBank
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
_08058C68:
	ldr r0, =gBattleSpritesDataPtr
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
_08058C82:
	ldr r5, =gBattleSpritesDataPtr
	ldr r0, [r5]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	bne _08058D32
	movs r1, 0x2
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08058D32
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _08058D32
	ldr r0, [r5]
	ldrb r1, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08058D14
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _08058D08
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _08058D14
	.pool
_08058D08:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_08058D14:
	ldr r0, =gBattleSpritesDataPtr
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r0, 0x1
	mov r9, r0
_08058D32:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058D52
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058DAC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08058DAC
_08058D52:
	ldr r2, =gSprites
	ldr r0, =gUnknown_03005D7C
	ldr r1, =gActiveBank
	ldrb r4, [r1]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r3, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r3, r0
	bne _08058E0A
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r3
	bne _08058E0A
	b _08058E06
	.pool
_08058DAC:
	ldr r2, =gSprites
	ldr r7, =gUnknown_03005D7C
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r4, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r4, r0
	bne _08058E0A
	ldr r6, =gBankSpriteIds
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r5, [r0]
	cmp r5, r4
	bne _08058E0A
	movs r0, 0x2
	eors r3, r0
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r4, [r0]
	cmp r4, r5
	bne _08058E0A
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _08058E0A
_08058E06:
	movs r0, 0x1
	mov r8, r0
_08058E0A:
	mov r0, r9
	cmp r0, 0
	beq _08058EAA
	mov r0, r8
	cmp r0, 0
	beq _08058EAA
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058E48
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08058E48
	ldr r2, =gUnknown_03005D7C
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_08058E48:
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
	ldr r3, =gBattleSpritesDataPtr
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805896C
	str r1, [r0]
_08058EAA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058B40

	thumb_func_start sub_8058EDC
sub_8058EDC: @ 8058EDC
	push {r4-r6,lr}
	ldr r2, =gSprites
	ldr r0, =gHealthBoxesIds
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r4, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r4, r0
	bne _08058F94
	ldr r5, =gBattleSpritesDataPtr
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08058F94
	ldr r0, =gBankSpriteIds
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _08058F94
	adds r0, r3, 0
	bl sub_805E408
	ldr r0, [r5]
	ldrb r2, [r6]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldrb r2, [r6]
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
	ldr r0, [r5]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08058F88
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
_08058F88:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8058FC0
	str r0, [r1]
_08058F94:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058EDC

	thumb_func_start sub_8058FC0
sub_8058FC0: @ 8058FC0
	push {r4,lr}
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805900E
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _0805900E
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	ldr r2, =gBattlePartyID
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	bl PlayerBufferExecCompleted
_0805900E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058FC0

	thumb_func_start sub_805902C
sub_805902C: @ 805902C
	push {r4-r6,lr}
	ldr r6, =gBattleSpritesDataPtr
	ldr r0, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _0805905E
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0805905E:
	ldr r4, =gSprites
	ldr r0, =gUnknown_03005D7C
	ldrb r2, [r5]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r3, r0
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _080590D2
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
	bne _080590D2
	adds r0, r3, r4
	bl DestroySprite
	ldr r4, =gHealthBoxesIds
	ldrb r1, [r5]
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
	ldrb r0, [r5]
	bl sub_8076918
	ldrb r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058EDC
	str r1, [r0]
_080590D2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805902C

	thumb_func_start c3_0802FDF4
c3_0802FDF4: @ 8059100
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _08059122
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	adds r0, r4, 0
	bl DestroyTask
_08059122:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_0802FDF4

	thumb_func_start bx_t1_healthbar_update
bx_t1_healthbar_update: @ 8059130
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
	beq _08059178
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _08059192
	.pool
_08059178:
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
	bl PlayerBufferExecCompleted
_08059192:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_t1_healthbar_update

	thumb_func_start sub_80591A0
sub_80591A0: @ 80591A0
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080591B2
	bl PlayerBufferExecCompleted
_080591B2:
	pop {r0}
	bx r0
	thumb_func_end sub_80591A0

	thumb_func_start sub_80591B8
sub_80591B8: @ 80591B8
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
	beq _080591FE
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r10, r0
	bne _080591FE
	b _08059314
_080591FE:
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
	bcc _080592EC
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
	bne _080592D4
	ldr r2, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r2
	mov r1, r10
	ldrh r0, [r0]
	cmp r1, r0
	beq _080592B2
	movs r0, 0x2
	eors r7, r0
	lsls r0, r7, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	bne _080592D4
_080592B2:
	ldr r0, =sub_8059544
	b _08059316
	.pool
_080592D4:
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_805965C
	b _08059318
	.pool
_080592EC:
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r6, 0
	movs r1, 0x19
	bl SetMonData
	ldr r1, =gBattleBankFunc
	ldr r3, [sp, 0x8]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, =sub_80591A0
	str r1, [r0]
	mov r0, r9
	bl DestroyTask
	b _0805931A
	.pool
_08059314:
	ldr r0, =sub_8059330
_08059316:
	mov r1, r8
_08059318:
	str r0, [r1]
_0805931A:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80591B8

	thumb_func_start sub_8059330
sub_8059330: @ 8059330
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
	ldr r0, =sub_8059400
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
	thumb_func_end sub_8059330

	thumb_func_start sub_8059400
sub_8059400: @ 8059400
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
	bgt _08059430
	adds r0, r1, 0x1
	strh r0, [r6, 0x1C]
	b _0805952C
	.pool
_08059430:
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
	bne _0805952C
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
	blt _08059510
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
	ldr r0, =sub_8059544
	str r0, [r6]
	b _0805952C
	.pool
_08059510:
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r5, 0
	movs r1, 0x19
	bl SetMonData
	ldr r1, =gBattleBankFunc
	lsls r0, r7, 2
	adds r0, r1
	ldr r1, =sub_80591A0
	str r1, [r0]
	mov r0, r8
	bl DestroyTask
_0805952C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059400

	thumb_func_start sub_8059544
sub_8059544: @ 8059544
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
	bne _08059578
	ldr r1, =gBattlePartyID
	movs r0, 0x2
	adds r2, r4, 0
	eors r2, r0
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	bne _08059578
	adds r4, r2, 0
_08059578:
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
	ldr r0, =sub_80595A4
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059544

	thumb_func_start sub_80595A4
sub_80595A4: @ 80595A4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r2, r0, r1
	ldrb r5, [r2, 0xC]
	ldr r0, =gBattleSpritesDataPtr
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
	bne _08059646
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
	bne _08059624
	ldr r1, =gBattlePartyID
	movs r0, 0x2
	adds r2, r5, 0
	eors r2, r0
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _08059624
	ldr r0, =gHealthBoxesIds
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, r7, 0
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _08059638
	.pool
_08059624:
	ldr r0, =gHealthBoxesIds
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x64
	muls r1, r4
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
_08059638:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_805965C
	str r0, [r1]
_08059646:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80595A4

	thumb_func_start sub_805965C
sub_805965C: @ 805965C
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
	ldr r1, =sub_80591A0
	str r1, [r0]
	adds r0, r5, 0
	bl DestroyTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805965C

	thumb_func_start sub_80596A8
sub_80596A8: @ 80596A8
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
	ble _08059724
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
	bl PlayerBufferExecCompleted
_08059724:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80596A8

	thumb_func_start sub_8059744
sub_8059744: @ 8059744
	push {r4-r6,lr}
	ldr r0, =gBattleSpritesDataPtr
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
	bne _08059798
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
	bl PlayerBufferExecCompleted
_08059798:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059744

	thumb_func_start sub_80597B4
sub_80597B4: @ 80597B4
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080597C6
	bl PlayerBufferExecCompleted
_080597C6:
	pop {r0}
	bx r0
	thumb_func_end sub_80597B4

	thumb_func_start sub_80597CC
sub_80597CC: @ 80597CC
	push {r4,lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0805980A
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8059828
	str r1, [r0]
	ldr r3, =gTasks
	ldr r1, =gUnknown_03005D7C
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	ldrb r4, [r1, 0x8]
	bl DestroyTask
	bl FreeAllWindowBuffers
	adds r0, r4, 0
	bl sub_81B89AC
_0805980A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80597CC

	thumb_func_start sub_8059828
sub_8059828: @ 8059828
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =BattleMainCB2
	cmp r1, r0
	bne _08059898
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08059898
	ldr r0, =gUnknown_0203CEE8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08059870
	ldr r0, =gUnknown_0203CEE9
	ldrb r1, [r0]
	ldr r2, =gUnknown_0203CF00
	movs r0, 0x1
	bl dp01_build_cmdbuf_x22_a_three_bytes
	b _0805987A
	.pool
_08059870:
	movs r0, 0x1
	movs r1, 0x6
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
_0805987A:
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _08059894
	bl b_link_standby_message
_08059894:
	bl PlayerBufferExecCompleted
_08059898:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059828

	thumb_func_start sub_80598A4
sub_80598A4: @ 80598A4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080598CC
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80598E0
	str r1, [r0]
	bl nullsub_35
	bl FreeAllWindowBuffers
	bl sub_81AABB0
_080598CC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80598A4

	thumb_func_start sub_80598E0
sub_80598E0: @ 80598E0
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =BattleMainCB2
	cmp r1, r0
	bne _08059906
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08059906
	ldr r0, =gScriptItemId
	ldrh r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl PlayerBufferExecCompleted
_08059906:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80598E0

	thumb_func_start bx_wait_t1
bx_wait_t1: @ 805991C
	push {lr}
	ldr r0, =gDoingBattleAnim
	ldrb r0, [r0]
	cmp r0, 0
	beq _08059942
	ldr r0, =gBattleSpritesDataPtr
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08059946
_08059942:
	bl PlayerBufferExecCompleted
_08059946:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_wait_t1

	thumb_func_start bx_blink_t1
bx_blink_t1: @ 8059958
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
	bne _080599A4
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
	bl PlayerBufferExecCompleted
	b _080599CE
	.pool
_080599A4:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080599C8
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
_080599C8:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_080599CE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t1

	thumb_func_start sub_80599D4
sub_80599D4: @ 80599D4
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08059A02
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	cmp r0, 0
	beq _08059A02
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	bl BattleDestroyCursorAt
	movs r0, 0
	strb r0, [r4]
	movs r0, 0
	bl BattleCreateCursorAt
_08059A02:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08059A2C
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	cmp r0, 0
	bne _08059A2C
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	bl BattleDestroyCursorAt
	movs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	bl BattleCreateCursorAt
_08059A2C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08059A7A
	str r2, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	cmp r0, 0
	beq _08059A6C
	movs r0, 0x1
	movs r1, 0xE
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08059A76
	.pool
_08059A6C:
	movs r0, 0x1
	movs r1, 0xD
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_08059A76:
	bl PlayerBufferExecCompleted
_08059A7A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08059AA0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x5
	bl PlaySE
	bl PlayerBufferExecCompleted
_08059AA0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80599D4

	thumb_func_start sub_8059AAC
sub_8059AAC: @ 8059AAC
	push {r4-r7,lr}
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 9
	ldr r3, =gBattleBufferA + 4
	ldr r2, =gUnknown_03005D78
	movs r0, 0
	strb r0, [r2]
	movs r5, 0
	ldr r7, =gDisplayedStringBattle
	adds r4, r1, r3
	adds r6, r2, 0
_08059AC4:
	lsls r0, r5, 24
	lsrs r0, 24
	bl battle_menu_cursor_related
	ldrh r1, [r4]
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r7, 0
	bl StringCopy
	adds r1, r5, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_814F9EC
	ldrh r0, [r4]
	cmp r0, 0
	beq _08059AF4
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_08059AF4:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _08059AC4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059AAC

	thumb_func_start sub_8059B18
sub_8059B18: @ 8059B18
	push {r4,lr}
	ldr r4, =gDisplayedStringBattle
	ldr r1, =gText_MoveInterfacePP
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0x7
	bl sub_814F9EC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059B18

	thumb_func_start sub_8059B3C
sub_8059B3C: @ 8059B3C
	push {r4-r7,lr}
	ldr r5, =gBattleBufferA
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	lsls r0, 9
	adds r1, r5, 0x2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08059B98
	bl SetPpNumbersPaletteInMoveSelection
	ldrb r1, [r7]
	lsls r4, r1, 9
	adds r0, r5, 0x4
	adds r4, r0
	ldr r6, =gDisplayedStringBattle
	ldr r5, =gMoveSelectionCursor
	adds r1, r5
	adds r0, r4, 0
	adds r0, 0x8
	ldrb r1, [r1]
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	ldrb r1, [r7]
	adds r1, r5
	adds r4, 0xC
	ldrb r1, [r1]
	adds r4, r1
	ldrb r1, [r4]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x9
	bl sub_814F9EC
_08059B98:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059B3C

	thumb_func_start sub_8059BB0
sub_8059BB0: @ 8059BB0
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gBattleBufferA + 4
	adds r4, r0
	ldr r6, =gDisplayedStringBattle
	ldr r1, =gText_MoveInterfaceType
	adds r0, r6, 0
	bl StringCopy
	movs r1, 0xFC
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x6
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	ldr r3, =gBattleMoves
	ldr r2, =gMoveSelectionCursor
	ldrb r1, [r5]
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 1
	adds r4, r1
	ldrh r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0x2]
	lsls r1, r2, 3
	subs r1, r2
	ldr r2, =gTypeNames
	adds r1, r2
	bl StringCopy
	adds r0, r6, 0
	movs r1, 0xA
	bl sub_814F9EC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059BB0

	thumb_func_start battle_menu_cursor_related_2
battle_menu_cursor_related_2: @ 8059C28
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r1, 24
	lsrs r1, 24
	add r2, sp, 0xC
	adds r0, r1, 0x1
	strh r0, [r2]
	adds r0, r2, 0
	adds r1, 0x2
	strh r1, [r0, 0x2]
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r0, 3
	adds r2, r0
	adds r2, 0x1
	movs r0, 0x2
	ands r3, r0
	adds r3, 0x37
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	thumb_func_end battle_menu_cursor_related_2

	thumb_func_start battle_menu_cursor_related
battle_menu_cursor_related: @ 8059C70
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	ldr r1, =0x00001016
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r0, 3
	adds r2, r0
	adds r2, 0x1
	movs r0, 0x2
	ands r3, r0
	adds r3, 0x37
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end battle_menu_cursor_related

	thumb_func_start sub_8059CB4
sub_8059CB4: @ 8059CB4
	push {r4,lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	movs r4, 0x1
	strh r4, [r0]
	movs r1, 0x2
	strh r1, [r0, 0x2]
	adds r0, r3, 0
	ands r0, r4
	lsls r2, r0, 3
	subs r2, r0
	adds r2, 0x10
	lsls r2, 24
	lsrs r2, 24
	ands r3, r1
	adds r3, 0x23
	str r4, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8059CB4

	thumb_func_start sub_8059CF8
sub_8059CF8: @ 8059CF8
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	ldr r1, =0x00001016
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r0, 3
	subs r2, r0
	adds r2, 0x10
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x2
	ands r3, r0
	adds r3, 0x23
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059CF8

	thumb_func_start sub_8059D40
sub_8059D40: @ 8059D40
	push {lr}
	ldr r0, =ReshowBattleScreenAfterMenu
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059D40

	thumb_func_start sub_8059D50
sub_8059D50: @ 8059D50
	push {lr}
	ldr r0, =ReshowBattleScreenAfterMenu
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059D50

	thumb_func_start sub_8059D60
sub_8059D60: @ 8059D60
	push {lr}
	ldr r0, =gBattleSpritesDataPtr
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
	bne _08059D82
	bl PlayerBufferExecCompleted
_08059D82:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059D60

	thumb_func_start bx_8030B2C
bx_8030B2C: @ 8059D90
	push {lr}
	ldr r0, =gBattleSpritesDataPtr
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
	bne _08059DB2
	bl PlayerBufferExecCompleted
_08059DB2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_8030B2C

	thumb_func_start b_link_standby_message
b_link_standby_message: @ 8059DC0
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08059DE0
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r0, =gText_LinkStandby
	movs r1, 0
	bl sub_814F9EC
_08059DE0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_link_standby_message

	thumb_func_start dp01t_00_1_getattr
dp01t_00_1_getattr: @ 8059DF4
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
	bne _08059E2C
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl dp01_getattr_by_ch1_for_player_pokemon_
	adds r6, r0, 0
	b _08059E4E
	.pool
_08059E2C:
	ldrb r4, [r1]
	movs r5, 0
_08059E30:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08059E46
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl dp01_getattr_by_ch1_for_player_pokemon_
	adds r6, r0
_08059E46:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _08059E30
_08059E4E:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl PlayerBufferExecCompleted
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_1_getattr

	thumb_func_start dp01_getattr_by_ch1_for_player_pokemon_
dp01_getattr_by_ch1_for_player_pokemon_: @ 8059E68
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
	bls _08059E92
	bl _0805A5FE
_08059E92:
	lsls r0, 2
	ldr r1, =_08059EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08059EA8:
	.4byte _08059F98
	.4byte _0805A1BC
	.4byte _0805A1CC
	.4byte _0805A1DC
	.4byte _0805A244
	.4byte _0805A244
	.4byte _0805A244
	.4byte _0805A244
	.4byte _0805A260
	.4byte _0805A29C
	.4byte _0805A29C
	.4byte _0805A29C
	.4byte _0805A29C
	.4byte _0805A5FE
	.4byte _0805A5FE
	.4byte _0805A5FE
	.4byte _0805A5FE
	.4byte _0805A2B8
	.4byte _0805A2C8
	.4byte _0805A2F8
	.4byte _0805A308
	.4byte _0805A318
	.4byte _0805A328
	.4byte _0805A338
	.4byte _0805A348
	.4byte _0805A358
	.4byte _0805A368
	.4byte _0805A378
	.4byte _0805A388
	.4byte _0805A398
	.4byte _0805A3A8
	.4byte _0805A3B8
	.4byte _0805A408
	.4byte _0805A418
	.4byte _0805A428
	.4byte _0805A438
	.4byte _0805A448
	.4byte _0805A458
	.4byte _0805A468
	.4byte _0805A478
	.4byte _0805A488
	.4byte _0805A4BC
	.4byte _0805A4CC
	.4byte _0805A4DC
	.4byte _0805A4EC
	.4byte _0805A4FC
	.4byte _0805A50C
	.4byte _0805A51C
	.4byte _0805A52C
	.4byte _0805A54C
	.4byte _0805A55C
	.4byte _0805A56C
	.4byte _0805A57C
	.4byte _0805A58C
	.4byte _0805A59C
	.4byte _0805A5AC
	.4byte _0805A5BC
	.4byte _0805A5CC
	.4byte _0805A5DC
	.4byte _0805A5EC
_08059F98:
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
_08059FE4:
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
	ble _08059FE4
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
_0805A19C:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _0805A19C
	b _0805A5FE
	.pool
_0805A1BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	b _0805A536
	.pool
_0805A1CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	b _0805A536
	.pool
_0805A1DC:
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
_0805A1F2:
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
	ble _0805A1F2
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
_0805A230:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _0805A230
	b _0805A5FE
	.pool
_0805A244:
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
	b _0805A536
	.pool
_0805A260:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gPlayerParty
	mov r8, r2
_0805A26C:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805A26C
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _0805A5FE
	.pool
_0805A29C:
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
	b _0805A5F6
	.pool
_0805A2B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	b _0805A2D2
	.pool
_0805A2C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x19
_0805A2D2:
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
	b _0805A5FE
	.pool
_0805A2F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1A
	b _0805A5F6
	.pool
_0805A308:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1B
	b _0805A5F6
	.pool
_0805A318:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1C
	b _0805A5F6
	.pool
_0805A328:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1D
	b _0805A5F6
	.pool
_0805A338:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1E
	b _0805A5F6
	.pool
_0805A348:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1F
	b _0805A5F6
	.pool
_0805A358:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x20
	b _0805A5F6
	.pool
_0805A368:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x22
	b _0805A5F6
	.pool
_0805A378:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x23
	b _0805A5F6
	.pool
_0805A388:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x24
	b _0805A5F6
	.pool
_0805A398:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x25
	b _0805A5F6
	.pool
_0805A3A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x26
	b _0805A5F6
	.pool
_0805A3B8:
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
	b _0805A5FE
	.pool
_0805A408:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x27
	b _0805A5F6
	.pool
_0805A418:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x28
	b _0805A5F6
	.pool
_0805A428:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x29
	b _0805A5F6
	.pool
_0805A438:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2A
	b _0805A5F6
	.pool
_0805A448:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2B
	b _0805A5F6
	.pool
_0805A458:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2C
	b _0805A5F6
	.pool
_0805A468:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	b _0805A492
	.pool
_0805A478:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x9
	b _0805A536
	.pool
_0805A488:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x37
_0805A492:
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
	b _0805A5FE
	.pool
_0805A4BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	b _0805A5F6
	.pool
_0805A4CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	b _0805A536
	.pool
_0805A4DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	b _0805A536
	.pool
_0805A4EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3B
	b _0805A536
	.pool
_0805A4FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3C
	b _0805A536
	.pool
_0805A50C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3D
	b _0805A536
	.pool
_0805A51C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3E
	b _0805A536
	.pool
_0805A52C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3F
_0805A536:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _0805A5FE
	.pool
_0805A54C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	b _0805A5F6
	.pool
_0805A55C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	b _0805A5F6
	.pool
_0805A56C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	b _0805A5F6
	.pool
_0805A57C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	b _0805A5F6
	.pool
_0805A58C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	b _0805A5F6
	.pool
_0805A59C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	b _0805A5F6
	.pool
_0805A5AC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _0805A5F6
	.pool
_0805A5BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _0805A5F6
	.pool
_0805A5CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _0805A5F6
	.pool
_0805A5DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _0805A5F6
	.pool
_0805A5EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_0805A5F6:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_0805A5FE:
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
	thumb_func_end dp01_getattr_by_ch1_for_player_pokemon_

	thumb_func_start sub_805A614
sub_805A614: @ 805A614
	push {r4-r7,lr}
	sub sp, 0x58
	ldr r2, =gBattlePartyID
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	adds r4, r2, 0
	muls r4, r0
	ldr r3, =gBattleBufferA
	lsls r1, 9
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r2, [r0]
	ldr r0, =gPlayerParty
	adds r0, r2, r0
	adds r6, r4, r0
	mov r0, sp
	adds r4, r0, r2
	movs r2, 0
	adds r0, r3, 0x2
	adds r1, r0
	adds r7, r5, 0
	mov r12, r3
	ldrb r1, [r1]
	cmp r2, r1
	bcs _0805A66A
	adds r3, r0, 0
_0805A650:
	adds r1, r4, r2
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r5]
	lsls r0, 9
	adds r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0805A650
_0805A66A:
	ldrb r0, [r7]
	lsls r0, 9
	mov r1, r12
	adds r1, 0x2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl PlayerBufferExecCompleted
	add sp, 0x58
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805A614

	thumb_func_start dp01t_02_1_setattr
dp01t_02_1_setattr: @ 805A69C
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805A6CC
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl dp01_setattr_by_ch1_for_player_pokemon
	b _0805A6EA
	.pool
_0805A6CC:
	ldrb r4, [r1]
	movs r5, 0
_0805A6D0:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0805A6DE
	adds r0, r5, 0
	bl dp01_setattr_by_ch1_for_player_pokemon
_0805A6DE:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0805A6D0
_0805A6EA:
	bl PlayerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_02_1_setattr

	thumb_func_start dp01_setattr_by_ch1_for_player_pokemon
dp01_setattr_by_ch1_for_player_pokemon: @ 805A6F4
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
	bls _0805A720
	bl _0805B0BA
_0805A720:
	lsls r0, 2
	ldr r1, =_0805A738
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0805A738:
	.4byte _0805A828
	.4byte _0805A9C0
	.4byte _0805A9E0
	.4byte _0805AA00
	.4byte _0805AA58
	.4byte _0805AA58
	.4byte _0805AA58
	.4byte _0805AA58
	.4byte _0805AA80
	.4byte _0805AAE4
	.4byte _0805AAE4
	.4byte _0805AAE4
	.4byte _0805AAE4
	.4byte _0805B0BA
	.4byte _0805B0BA
	.4byte _0805B0BA
	.4byte _0805B0BA
	.4byte _0805AB14
	.4byte _0805AB34
	.4byte _0805AB54
	.4byte _0805AB74
	.4byte _0805AB94
	.4byte _0805ABB4
	.4byte _0805ABD4
	.4byte _0805ABF4
	.4byte _0805AC14
	.4byte _0805AC34
	.4byte _0805AC54
	.4byte _0805AC74
	.4byte _0805AC94
	.4byte _0805ACB4
	.4byte _0805ACD4
	.4byte _0805AD44
	.4byte _0805AD64
	.4byte _0805AD84
	.4byte _0805ADA4
	.4byte _0805ADC4
	.4byte _0805ADE4
	.4byte _0805AE04
	.4byte _0805AE24
	.4byte _0805AE44
	.4byte _0805AE64
	.4byte _0805AE84
	.4byte _0805AEA4
	.4byte _0805AEC4
	.4byte _0805AEE4
	.4byte _0805AF04
	.4byte _0805AF24
	.4byte _0805AF44
	.4byte _0805AF64
	.4byte _0805AF84
	.4byte _0805AFA4
	.4byte _0805AFC4
	.4byte _0805AFE4
	.4byte _0805B004
	.4byte _0805B024
	.4byte _0805B044
	.4byte _0805B064
	.4byte _0805B084
	.4byte _0805B0A4
_0805A828:
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
_0805A88E:
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
	ble _0805A88E
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
	b _0805B0BA
	.pool
_0805A9C0:
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
	b _0805B0BA
	.pool
_0805A9E0:
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
	b _0805B0BA
	.pool
_0805AA00:
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
_0805AA1A:
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
	ble _0805AA1A
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _0805B0BA
	.pool
_0805AA58:
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
	b _0805AAFC
	.pool
_0805AA80:
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
	b _0805B0BA
	.pool
_0805AAE4:
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
_0805AAFC:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _0805B0BA
	.pool
_0805AB14:
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
	b _0805B0BA
	.pool
_0805AB34:
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
	b _0805B0BA
	.pool
_0805AB54:
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
	b _0805B0BA
	.pool
_0805AB74:
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
	b _0805B0BA
	.pool
_0805AB94:
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
	b _0805B0BA
	.pool
_0805ABB4:
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
	b _0805B0BA
	.pool
_0805ABD4:
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
	b _0805B0BA
	.pool
_0805ABF4:
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
	b _0805B0BA
	.pool
_0805AC14:
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
	b _0805B0BA
	.pool
_0805AC34:
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
	b _0805B0BA
	.pool
_0805AC54:
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
	b _0805B0BA
	.pool
_0805AC74:
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
	b _0805B0BA
	.pool
_0805AC94:
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
	b _0805B0BA
	.pool
_0805ACB4:
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
	b _0805B0BA
	.pool
_0805ACD4:
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
	b _0805ADF4
	.pool
_0805AD44:
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
	b _0805B0BA
	.pool
_0805AD64:
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
	b _0805B0BA
	.pool
_0805AD84:
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
	b _0805B0BA
	.pool
_0805ADA4:
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
	b _0805B0BA
	.pool
_0805ADC4:
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
	b _0805B0BA
	.pool
_0805ADE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
_0805ADF4:
	movs r1, 0x2C
	bl SetMonData
	b _0805B0BA
	.pool
_0805AE04:
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
	b _0805B0BA
	.pool
_0805AE24:
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
	b _0805B0BA
	.pool
_0805AE44:
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
	b _0805B0BA
	.pool
_0805AE64:
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
	b _0805B0BA
	.pool
_0805AE84:
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
	b _0805B0BA
	.pool
_0805AEA4:
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
	b _0805B0BA
	.pool
_0805AEC4:
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
	b _0805B0BA
	.pool
_0805AEE4:
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
	b _0805B0BA
	.pool
_0805AF04:
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
	b _0805B0BA
	.pool
_0805AF24:
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
	b _0805B0BA
	.pool
_0805AF44:
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
	b _0805B0BA
	.pool
_0805AF64:
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
	b _0805B0BA
	.pool
_0805AF84:
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
	b _0805B0BA
	.pool
_0805AFA4:
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
	b _0805B0BA
	.pool
_0805AFC4:
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
	b _0805B0BA
	.pool
_0805AFE4:
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
	b _0805B0BA
	.pool
_0805B004:
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
	b _0805B0BA
	.pool
_0805B024:
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
	b _0805B0BA
	.pool
_0805B044:
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
	b _0805B0BA
	.pool
_0805B064:
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
	b _0805B0BA
	.pool
_0805B084:
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
	b _0805B0BA
	.pool
_0805B0A4:
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
_0805B0BA:
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
	thumb_func_end dp01_setattr_by_ch1_for_player_pokemon

	thumb_func_start sub_805B0F0
sub_805B0F0: @ 805B0F0
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
	bcs _0805B148
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_0805B126:
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
	bcc _0805B126
_0805B148:
	bl PlayerBufferExecCompleted
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B0F0

	thumb_func_start sub_805B164
sub_805B164: @ 805B164
	push {r4,lr}
	ldr r2, =gBattlePartyID
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805DD7C
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	ldrb r3, [r4]
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_0802E404
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B164

	thumb_func_start sub_805B1CC
sub_805B1CC: @ 805B1CC
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
	movs r4, 0
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
	ldr r1, =gActionSelectionCursor
	ldrb r0, [r5]
	adds r0, r1
	strb r4, [r0]
	ldr r1, =gMoveSelectionCursor
	ldrb r0, [r5]
	adds r0, r1
	strb r4, [r0]
	ldrb r0, [r5]
	lsls r1, r0, 9
	adds r1, r6
	ldrb r1, [r1]
	bl sub_805B258
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805902C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B1CC

	thumb_func_start sub_805B258
sub_805B258: @ 805B258
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
	thumb_func_end sub_805B258

	thumb_func_start sub_805B3D4
sub_805B3D4: @ 805B3D4
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _0805B41C
	ldr r0, =gBattleSpritesDataPtr
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
	ldr r1, =sub_805B464
	str r1, [r0]
	b _0805B452
	.pool
_0805B41C:
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
	bl PlayerBufferExecCompleted
_0805B452:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B3D4

	thumb_func_start sub_805B464
sub_805B464: @ 805B464
	push {r4-r6,lr}
	ldr r6, =gBattleSpritesDataPtr
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
	beq _0805B48C
	cmp r0, 0x1
	beq _0805B4BA
	b _0805B4E2
	.pool
_0805B48C:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805B4A6
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0805B4A6:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0805B4E2
_0805B4BA:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805B4E2
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
	ldr r1, =sub_8059744
	str r1, [r0]
_0805B4E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B464

	thumb_func_start sub_805B4F0
sub_805B4F0: @ 805B4F0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805B5B4
	bl GetMultiplayerId
	ldr r5, =gLinkPlayers
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _0805B538
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _0805B558
_0805B538:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x2
	b _0805B5BA
	.pool
_0805B558:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _0805B58A
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _0805B5A0
_0805B58A:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x4
	b _0805B5BA
_0805B5A0:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r4, [r1, 0x13]
	b _0805B5BA
_0805B5B4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r4, [r0, 0x8]
_0805B5BA:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x40
	ands r1, r2
	adds r5, r0, 0
	cmp r1, 0
	beq _0805B63C
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r1, 0x2
	ands r1, r0
	movs r0, 0x20
	mov r9, r0
	cmp r1, 0
	beq _0805B5E0
	movs r1, 0x5A
	mov r9, r1
_0805B5E0:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0805B618
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	beq _0805B618
	movs r0, 0x5A
	mov r9, r0
	ldr r1, =gUnknown_083054E0
	b _0805B642
	.pool
_0805B618:
	ldr r1, =gUnknown_08305D2C
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	subs r0, r1
	lsls r0, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r0, r1
	lsrs r7, r0, 16
	ldr r5, =gBattleTypeFlags
	b _0805B656
	.pool
_0805B63C:
	movs r0, 0x50
	mov r9, r0
	ldr r1, =gUnknown_08305D2C
_0805B642:
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	subs r0, r1
	lsls r0, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r0, r1
	lsrs r7, r0, 16
_0805B656:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	bne _0805B664
	b _0805B794
_0805B664:
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _0805B670
	b _0805B794
_0805B670:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl sub_806F000
	lsls r0, 16
	lsrs r4, r0, 16
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
	b _0805B82A
	.pool
_0805B794:
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
	bl sub_806A12C
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
_0805B82A:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058844
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B4F0

	thumb_func_start dp01t_08_1_8032428
dp01t_08_1_8032428: @ 805B864
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805B920
	bl GetMultiplayerId
	ldr r5, =gLinkPlayers
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _0805B8A6
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _0805B8C4
_0805B8A6:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x2
	b _0805B926
	.pool
_0805B8C4:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _0805B8F6
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _0805B90C
_0805B8F6:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x4
	b _0805B926
_0805B90C:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r4, [r1, 0x13]
	b _0805B926
_0805B920:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r4, [r0, 0x8]
_0805B926:
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
	bl sub_806A12C
	ldr r0, =gUnknown_0202499C
	ldr r1, =gUnknown_08305D2C
	lsls r4, 2
	adds r4, r1
	ldrb r1, [r4]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r2, r1
	asrs r2, 16
	movs r1, 0x50
	movs r3, 0x1E
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
	ldr r1, =0x0000ffa0
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x2
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
	ldr r1, =sub_805887C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_08_1_8032428

	thumb_func_start sub_805B9F8
sub_805B9F8: @ 805B9F8
	push {r4-r6,lr}
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
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =SpriteCallbackDummy
	bl StoreSpriteCallbackInData6
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_802F7A0
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B9F8

	thumb_func_start sub_805BAB8
sub_805BAB8: @ 805BAB8
	push {r4-r6,lr}
	ldr r6, =gBattleSpritesDataPtr
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
	bne _0805BB0C
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805BAEC
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0805BAEC:
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
	b _0805BB82
	.pool
_0805BB0C:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805BB82
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
	ldr r1, =sub_80596A8
	str r1, [r0]
_0805BB82:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BAB8

	thumb_func_start sub_805BBA4
sub_805BBA4: @ 805BBA4
	push {lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl PlayerBufferExecCompleted
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_805BBA4

	thumb_func_start sub_805BBC4
sub_805BBC4: @ 805BBC4
	push {r4,r5,lr}
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByIdentity
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x3
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t1
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BBC4

	thumb_func_start sub_805BC18
sub_805BC18: @ 805BC18
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strb r1, [r0, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByIdentity
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x3
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t1
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BC18

	thumb_func_start sub_805BC78
sub_805BC78: @ 805BC78
	push {lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805BC96
_0805BC8C:
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805BC8C
_0805BC96:
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BC78

	thumb_func_start dp01t_0F_1_move_anim
dp01t_0F_1_move_anim: @ 805BCA8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _0805BCBE
	b _0805BDE4
_0805BCBE:
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
	ldr r3, =gMovePowerMoveAnim
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
	ldr r3, =gMoveDmgMoveAnim
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
	ldr r2, =gHappinessMoveAnim
	ldrb r0, [r5]
	lsls r0, 9
	mov r1, r12
	adds r1, 0xA
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r4, =gWeatherMoveAnim
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
	ldr r7, =gDisableStructMoveAnim
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
	beq _0805BDBC
	bl PlayerBufferExecCompleted
	b _0805BDE4
	.pool
_0805BDBC:
	ldr r0, =gBattleSpritesDataPtr
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
	ldr r1, =bx_move_anim_1
	str r1, [r0]
	ldrh r1, [r4]
	ldr r2, [r7]
	adds r0, r6, 0
	bl sub_817E0FC
_0805BDE4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_0F_1_move_anim

	thumb_func_start bx_move_anim_1
bx_move_anim_1: @ 805BDFC
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
	ldr r7, =gBattleSpritesDataPtr
	ldr r5, [r7]
	ldr r1, [r5, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _0805BE94
	cmp r2, 0x1
	bgt _0805BE54
	cmp r2, 0
	beq _0805BE5E
	b _0805BF70
	.pool
_0805BE54:
	cmp r2, 0x2
	beq _0805BEBE
	cmp r2, 0x3
	beq _0805BF34
	b _0805BF70
_0805BE5E:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _0805BE80
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0805BE80:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0805BF70
_0805BE94:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805BF70
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
	b _0805BF70
_0805BEBE:
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805BF70
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
	beq _0805BF0C
	mov r0, r8
	cmp r0, 0x1
	bhi _0805BF0C
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
_0805BF0C:
	ldr r0, =gBattleSpritesDataPtr
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
	b _0805BF70
	.pool
_0805BF34:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805BF70
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
	bl PlayerBufferExecCompleted
_0805BF70:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_1

	thumb_func_start sub_805BF80
sub_805BF80: @ 805BF80
	push {r4,r5,lr}
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gBattleBufferA + 2
	adds r4, r0
	ldrh r0, [r4]
	bl BufferStringBattle
	ldr r0, =gDisplayedStringBattle
	movs r1, 0
	bl sub_814F9EC
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80597B4
	str r1, [r0]
	ldrh r0, [r4]
	bl sub_817C95C
	ldrb r0, [r5]
	ldrh r1, [r4]
	bl sub_81A57E4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BF80

	thumb_func_start dp01t_11_1_message_for_player_only
dp01t_11_1_message_for_player_only: @ 805BFE0
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805BFFC
	bl sub_805BF80
	b _0805C000
	.pool
_0805BFFC:
	bl PlayerBufferExecCompleted
_0805C000:
	pop {r0}
	bx r0
	thumb_func_end dp01t_11_1_message_for_player_only

	thumb_func_start sub_805C004
sub_805C004: @ 805C004
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805C02A
	ldr r0, =gBattle_BG0_X
	strh r1, [r0]
	ldr r1, =gBattle_BG0_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057588
	str r1, [r0]
_0805C02A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C004

	thumb_func_start dp01t_12_6_battle_menu
dp01t_12_6_battle_menu: @ 805C044
	push {r4,lr}
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805C004
	str r1, [r0]
	bl sub_817F2A8
	ldr r0, =gText_BattleMenu
	movs r1, 0x2
	bl sub_814F9EC
	movs r4, 0
_0805C062:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8059CF8
	adds r4, 0x1
	cmp r4, 0x3
	ble _0805C062
	ldr r1, =gActionSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gText_WhatWillPkmnDo
	bl BattleStringExpandPlaceholdersToDisplayedString
	ldr r0, =gDisplayedStringBattle
	movs r1, 0x1
	bl sub_814F9EC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_12_6_battle_menu

	thumb_func_start sub_805C0B0
sub_805C0B0: @ 805C0B0
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805C108
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gText_BattleYesNoChoice
	movs r1, 0xC
	bl sub_814F9EC
	ldr r1, =gUnknown_03005D74
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	bl BattleCreateCursorAt
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80599D4
	str r1, [r0]
	b _0805C10C
	.pool
_0805C108:
	bl PlayerBufferExecCompleted
_0805C10C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_805C0B0

	thumb_func_start sub_805C114
sub_805C114: @ 805C114
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805C13E
	ldr r0, =gBattle_BG0_X
	strh r1, [r0]
	ldr r1, =gBattle_BG0_Y
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
_0805C13E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C114

	thumb_func_start sub_805C158
sub_805C158: @ 805C158
	push {lr}
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r1, r0
	movs r0, 0xA6
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _0805C194
	ldr r1, =gBattlePalaceMoveSelectionRngValue
	ldr r0, =gRngValue
	ldr r0, [r0]
	str r0, [r1]
	bl sub_805D19C
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	bl PlayerBufferExecCompleted
_0805C194:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C158

	thumb_func_start dp01t_14_5_move_menu_pokedude
dp01t_14_5_move_menu_pokedude: @ 805C1A8
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0805C1EC
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	movs r1, 0xA6
	lsls r1, 2
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805C158
	b _0805C1FC
	.pool
_0805C1EC:
	bl sub_805C210
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805C114
_0805C1FC:
	str r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_14_5_move_menu_pokedude

	thumb_func_start sub_805C210
sub_805C210: @ 805C210
	push {lr}
	bl sub_8059AAC
	ldr r1, =gUnknown_03005D74
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, =gMoveSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	bl sub_8059B18
	bl sub_8059B3C
	bl sub_8059BB0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C210

	thumb_func_start sub_805C248
sub_805C248: @ 805C248
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80598A4
	str r1, [r0]
	ldr r1, =gBankInMenu
	ldrb r0, [r2]
	strb r0, [r1]
	movs r3, 0
	ldr r5, =gUnknown_0203CF00
	ldr r4, =gBattleBufferA
_0805C276:
	adds r0, r3, r5
	ldrb r1, [r2]
	lsls r1, 9
	adds r1, 0x1
	adds r1, r3, r1
	adds r1, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0805C276
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C248

	thumb_func_start sub_805C2AC
sub_805C2AC: @ 805C2AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r3, 0
	ldr r0, =gUnknown_0203CF00
	mov r12, r0
	ldr r1, =gBattleBufferA
	mov r8, r1
	ldr r2, =gActiveBank
	ldr r7, =gBattleTypeFlags
	mov r6, r12
	mov r5, r8
	adds r4, r2, 0
_0805C2C8:
	adds r0, r3, r6
	ldrb r1, [r4]
	lsls r1, 9
	adds r1, 0x4
	adds r1, r3, r1
	adds r1, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0805C2C8
	ldr r0, [r7]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0805C330
	ldrb r3, [r2]
	lsls r0, r3, 9
	mov r1, r8
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x2
	beq _0805C330
	ldr r1, =gBattlePartyID
	lsls r0, r3, 1
	adds r0, r1
	ldrb r1, [r0]
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	mov r2, r12
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl PlayerBufferExecCompleted
	b _0805C3BC
	.pool
_0805C330:
	ldr r0, =TaskDummy
	movs r1, 0xFF
	bl CreateTask
	ldr r3, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	adds r1, r3
	movs r2, 0
	mov r8, r2
	strb r0, [r1]
	ldr r5, =gTasks
	ldrb r2, [r4]
	adds r3, r2, r3
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldr r5, =gBattleBufferA
	lsls r2, 9
	adds r6, r5, 0x1
	adds r2, r6
	ldrb r2, [r2]
	movs r0, 0xF
	ands r0, r2
	strh r0, [r1, 0x8]
	ldr r3, =gBattleStruct
	ldr r1, [r3]
	adds r1, 0x49
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r6
	ldrb r0, [r0]
	lsrs r0, 4
	strb r0, [r1]
	ldr r2, [r3]
	adds r2, 0x8B
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, r5, 0x2
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, [r3]
	adds r1, 0xB0
	ldrb r0, [r4]
	lsls r0, 9
	adds r5, 0x3
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	mov r1, r8
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80597CC
	str r1, [r0]
	ldr r1, =gBankInMenu
	ldrb r0, [r4]
	strb r0, [r1]
_0805C3BC:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C2AC

	thumb_func_start sub_805C3EC
sub_805C3EC: @ 805C3EC
	push {lr}
	sub sp, 0x4
	bl BattleMusicStop
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl PlayerBufferExecCompleted
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_805C3EC

	thumb_func_start sub_805C410
sub_805C410: @ 805C410
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
	ldrb r1, [r0]
	lsls r1, 9
	adds r0, r3, 0x2
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r3, 0x3
	adds r1, r3
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	lsls r2, 16
	asrs r7, r2, 16
	cmp r7, 0
	ble _0805C44A
	ldr r1, =gUnknown_0203CD70
	ldr r0, [r1]
	adds r0, r7
	str r0, [r1]
_0805C44A:
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _0805C4B4
	ldr r6, =gBattlePartyID
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r2, r9
	ldrb r0, [r2]
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
	b _0805C4F2
	.pool
_0805C4B4:
	ldr r1, =gBattlePartyID
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
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
	ldr r4, =gHealthBoxesIds
	adds r1, r0, r4
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
	mov r2, r9
	ldrb r0, [r2]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	movs r2, 0
	bl heathbar_draw_hp
_0805C4F2:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t1_healthbar_update
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C410

	thumb_func_start sub_805C528
sub_805C528: @ 805C528
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
	bls _0805C560
	bl PlayerBufferExecCompleted
	b _0805C5AC
	.pool
_0805C560:
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
	ldr r0, =sub_80591B8
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
_0805C5AC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C528

	thumb_func_start sub_805C5C4
sub_805C5C4: @ 805C5C4
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0805C618
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
	ldr r0, =gBattleSpritesDataPtr
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
	ldr r1, =sub_8059D60
	str r1, [r0]
_0805C618:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C5C4

	thumb_func_start sub_805C63C
sub_805C63C: @ 805C63C
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0805C68C
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
	ldr r1, =sub_8059D60
	str r1, [r0]
_0805C68C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C63C

	thumb_func_start sub_805C6A4
sub_805C6A4: @ 805C6A4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	ldr r0, =gBattlePartyID
	mov r8, r0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x37
	bl GetMonData
	ldr r2, =gBattleBufferA
	ldrb r1, [r4]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	eors r0, r1
	mov r1, sp
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x37
	mov r2, sp
	bl SetMonData
	bl PlayerBufferExecCompleted
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C6A4

	thumb_func_start sub_805C710
sub_805C710: @ 805C710
	push {lr}
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C710

	thumb_func_start sub_805C71C
sub_805C71C: @ 805C71C
	push {r4,r5,lr}
	ldr r3, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r2, 9
	adds r0, r3, 0x1
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r0, r3, 0x2
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r5, r0
	adds r0, r3, 0x3
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 16
	orrs r5, r0
	adds r0, r3, 0x4
	adds r0, r2, r0
	ldrb r4, [r0]
	lsls r4, 24
	adds r0, r3, 0x5
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r0, r3, 0x6
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	adds r3, 0x7
	adds r2, r3
	orrs r5, r4
	lsrs r4, r1, 16
	movs r0, 0x80
	lsls r0, 5
	cmp r4, r0
	bhi _0805C78C
	ldr r0, =0x040000d4
	str r2, [r0]
	str r5, [r0, 0x4]
	lsrs r1, 17
	movs r2, 0x80
	lsls r2, 24
	orrs r1, r2
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	b _0805C7B8
	.pool
_0805C78C:
	ldr r3, =0x040000d4
	str r2, [r3]
	str r5, [r3, 0x4]
	ldr r0, =0x80000800
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
	movs r0, 0x80
	lsls r0, 5
	adds r2, r0
	adds r5, r0
	ldr r1, =0xfffff000
	adds r4, r1
	cmp r4, r0
	bhi _0805C78C
	str r2, [r3]
	str r5, [r3, 0x4]
	lsrs r0, r4, 1
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
_0805C7B8:
	bl PlayerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C71C

	thumb_func_start sub_805C7D0
sub_805C7D0: @ 805C7D0
	push {lr}
	ldr r2, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayBGM
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C7D0

	thumb_func_start sub_805C800
sub_805C800: @ 805C800
	push {lr}
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C800

	thumb_func_start sub_805C80C
sub_805C80C: @ 805C80C
	push {lr}
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C80C

	thumb_func_start sub_805C820
sub_805C820: @ 805C820
	push {lr}
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C820

	thumb_func_start sub_805C834
sub_805C834: @ 805C834
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl dp01_build_cmdbuf_x23_aa_0
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C834

	thumb_func_start sub_805C848
sub_805C848: @ 805C848
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl dp01_build_cmdbuf_x24_aa_0
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C848

	thumb_func_start sub_805C85C
sub_805C85C: @ 805C85C
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C85C

	thumb_func_start sub_805C878
sub_805C878: @ 805C878
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
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C878

	thumb_func_start sub_805C8B0
sub_805C8B0: @ 805C8B0
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C8B0

	thumb_func_start sub_805C8C8
sub_805C8C8: @ 805C8C8
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
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C8C8

	thumb_func_start dp01t_29_1_blink
dp01t_29_1_blink: @ 805C8F0
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
	bge _0805C924
	bl PlayerBufferExecCompleted
	b _0805C94E
	.pool
_0805C924:
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
	ldr r1, =bx_blink_t1
	str r1, [r0]
_0805C94E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_29_1_blink

	thumb_func_start sub_805C960
sub_805C960: @ 805C960
	push {lr}
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_805C960

	thumb_func_start sub_805C96C
sub_805C96C: @ 805C96C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _0805C980
	movs r3, 0xC0
_0805C980:
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
	bl PlayerBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C96C

	thumb_func_start sub_805C9B0
sub_805C9B0: @ 805C9B0
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805C9EC
	bl BattleMusicStop
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
	b _0805CA00
	.pool
_0805C9EC:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayFanfare
_0805CA00:
	bl PlayerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_805C9B0

	thumb_func_start sub_805CA0C
sub_805CA0C: @ 805CA0C
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
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CA0C

	thumb_func_start dp01t_2E_1_battle_intro
dp01t_2E_1_battle_intro: @ 805CA4C
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
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_1_battle_intro

	thumb_func_start dp01t_2F_1_pokemon_enter
dp01t_2F_1_pokemon_enter: @ 805CA80
	push {r4-r7,lr}
	ldr r6, =gBankSpriteIds
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x32
	strh r1, [r0, 0x2E]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r7]
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
	ldrb r2, [r7]
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x38]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =sub_805CC00
	bl StoreSpriteCallbackInData6
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, =0x0000d6f8
	bl AllocSpritePalette
	adds r4, r0, 0
	lsls r4, 24
	ldr r1, =gTrainerBackPicPaletteTable
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0]
	lsrs r4, 20
	movs r2, 0x80
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0x20
	bl LoadCompressedPalette
	ldrb r0, [r7]
	adds r0, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r4
	strb r0, [r1, 0x5]
	ldr r0, =task05_08033660
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r7]
	strh r0, [r1, 0x8]
	ldr r3, =gBattleSpritesDataPtr
	ldr r0, [r3]
	ldrb r2, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805CBA2
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_0805CBA2:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_21
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2F_1_pokemon_enter

	thumb_func_start sub_805CC00
sub_805CC00: @ 805CC00
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0x38]
	lsls r4, 24
	lsrs r4, 24
	bl FreeSpriteOamMatrix
	ldrb r0, [r5, 0x5]
	lsrs r0, 4
	bl GetSpritePaletteTagByPaletteNum
	lsls r0, 16
	lsrs r0, 16
	bl FreeSpritePaletteByTag
	adds r0, r5, 0
	bl DestroySprite
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DD7C
	ldr r0, =gBankSpriteIds
	adds r4, r0
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CC00

	thumb_func_start task05_08033660
task05_08033660: @ 805CC68
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
	cmp r0, 0x1E
	bgt _0805CC94
	adds r0, r2, 0x1
	strh r0, [r1, 0xA]
	b _0805CD50
	.pool
_0805CC94:
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldrh r0, [r1, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805CCB4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805CCE4
_0805CCB4:
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
	bl sub_805B258
	b _0805CD38
	.pool
_0805CCE4:
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
	bl sub_805B258
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
	bl sub_805B258
	ldrb r0, [r7]
	eors r0, r6
	strb r0, [r7]
_0805CD38:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058B40
	str r1, [r0]
	mov r3, r9
	strb r3, [r2]
	mov r0, r8
	bl DestroyTask
_0805CD50:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task05_08033660

	thumb_func_start sub_805CD74
sub_805CD74: @ 805CD74
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805CDA4
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805CDA4
	bl PlayerBufferExecCompleted
	b _0805CE18
	.pool
_0805CDA4:
	ldr r6, =gBattleSpritesDataPtr
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
	beq _0805CE0C
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_0805CE0C:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_805CE38
	str r0, [r1]
_0805CE18:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CD74

	thumb_func_start sub_805CE38
sub_805CE38: @ 805CE38
	push {r4,lr}
	ldr r4, =gBattleSpritesDataPtr
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
	bls _0805CE70
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl PlayerBufferExecCompleted
_0805CE70:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CE38

	thumb_func_start sub_805CE80
sub_805CE80: @ 805CE80
	push {lr}
	ldr r0, =gBattleSpritesDataPtr
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
	beq _0805CEB2
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
_0805CEB2:
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CE80

	thumb_func_start sub_805CED0
sub_805CED0: @ 805CED0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	ldrb r0, [r4]
	movs r1, 0
	bl dp11b_obj_free
	bl PlayerBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CED0

	thumb_func_start dp01t_33_1_enemy_move
dp01t_33_1_enemy_move: @ 805CEF4
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _0805CF3A
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
_0805CF3A:
	bl PlayerBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_33_1_enemy_move

	thumb_func_start sub_805CF54
sub_805CF54: @ 805CF54
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0805CFB6
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
	beq _0805CFA4
	bl PlayerBufferExecCompleted
	b _0805CFB0
	.pool
_0805CFA4:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_8030B2C
	str r0, [r1]
_0805CFB0:
	adds r0, r6, 0
	bl sub_817E32C
_0805CFB6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CF54

	thumb_func_start dp01t_35_1_link_standby_message_and_free_vram
dp01t_35_1_link_standby_message_and_free_vram: @ 805CFC8
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gBattleBufferA + 2
	adds r0, r4
	bl sub_81851A8
	ldrb r0, [r5]
	lsls r0, 9
	subs r4, 0x1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0805D002
	cmp r0, 0x1
	bgt _0805CFF8
	cmp r0, 0
	beq _0805CFFE
	b _0805D020
	.pool
_0805CFF8:
	cmp r0, 0x2
	beq _0805D01C
	b _0805D020
_0805CFFE:
	bl b_link_standby_message
_0805D002:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	ldrb r0, [r4]
	movs r1, 0
	bl dp11b_obj_free
	b _0805D020
	.pool
_0805D01C:
	bl b_link_standby_message
_0805D020:
	bl PlayerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_35_1_link_standby_message_and_free_vram

	thumb_func_start sub_805D02C
sub_805D02C: @ 805D02C
	push {r4,lr}
	ldr r1, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r3, [r4]
	lsls r0, r3, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _0805D074
	cmp r2, 0x1
	bgt _0805D054
	cmp r2, 0
	beq _0805D05A
	b _0805D084
	.pool
_0805D054:
	cmp r2, 0x2
	beq _0805D07C
	b _0805D084
_0805D05A:
	ldr r0, =gActionSelectionCursor
	adds r0, r3, r0
	strb r2, [r0]
	ldr r1, =gMoveSelectionCursor
	ldrb r0, [r4]
	adds r0, r1
	strb r2, [r0]
	b _0805D084
	.pool
_0805D074:
	ldr r0, =gActionSelectionCursor
	b _0805D07E
	.pool
_0805D07C:
	ldr r0, =gMoveSelectionCursor
_0805D07E:
	adds r0, r3, r0
	movs r1, 0
	strb r1, [r0]
_0805D084:
	bl PlayerBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D02C

	thumb_func_start sub_805D094
sub_805D094: @ 805D094
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gBattleBufferA + 4
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
	bl FadeOutMapMusic
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl PlayerBufferExecCompleted
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
	thumb_func_end sub_805D094

	thumb_func_start nullsub_22
nullsub_22: @ 805D114
	bx lr
	thumb_func_end nullsub_22
    
   	.align 2, 0 @ Don't pad with nop.
