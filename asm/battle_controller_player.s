	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


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
	ldr r1, =HandleInputChooseMove
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
	bl EmitChoiceReturnValue
	bl PlayerBufferExecCompleted
_0805C194:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C158

	thumb_func_start PlayerHandleChooseMove
PlayerHandleChooseMove: @ 805C1A8
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
	thumb_func_end PlayerHandleChooseMove

	thumb_func_start sub_805C210
sub_805C210: @ 805C210
	push {lr}
	bl MoveSelectionDisplayMoveNames
	ldr r1, =gMultiUsePlayerCursor
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, =gMoveSelectionCursor
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl MoveSelectionCreateCursorAt
	bl MoveSelectionDisplayPpString
	bl MoveSelectionDisplayPpNumber
	bl MoveSelectionDisplayMoveType
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C210

	thumb_func_start PlayerHandleOpenBag
PlayerHandleOpenBag: @ 805C248
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
	thumb_func_end PlayerHandleOpenBag

	thumb_func_start PlayerHandleChoosePokemon
PlayerHandleChoosePokemon: @ 805C2AC
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
	bl EmitCmd34
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
	thumb_func_end PlayerHandleChoosePokemon

	thumb_func_start PlayerHandleCmd23
PlayerHandleCmd23: @ 805C3EC
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
	thumb_func_end PlayerHandleCmd23

	thumb_func_start PlayerHandleHealthBarUpdate
PlayerHandleHealthBarUpdate: @ 805C410
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl LoadBattleBarGfx
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
	bl SetBattleBarStruct
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
	bl SetBattleBarStruct
	mov r2, r9
	ldrb r0, [r2]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	movs r2, 0
	bl UpdateHpTextInHealthbox
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
	thumb_func_end PlayerHandleHealthBarUpdate

	thumb_func_start PlayerHandleExpUpdate
PlayerHandleExpUpdate: @ 805C528
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
	bl LoadBattleBarGfx
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
	thumb_func_end PlayerHandleExpUpdate

	thumb_func_start PlayerHandleStatusIconUpdate
PlayerHandleStatusIconUpdate: @ 805C5C4
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
	bl UpdateHealthboxAttribute
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
	thumb_func_end PlayerHandleStatusIconUpdate

	thumb_func_start PlayerHandleStatusAnimation
PlayerHandleStatusAnimation: @ 805C63C
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
	thumb_func_end PlayerHandleStatusAnimation

	thumb_func_start PlayerHandleStatusXor
PlayerHandleStatusXor: @ 805C6A4
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
	thumb_func_end PlayerHandleStatusXor

	thumb_func_start PlayerHandleDataTransfer
PlayerHandleDataTransfer: @ 805C710
	push {lr}
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleDataTransfer

	thumb_func_start PlayerHandleDMA3Transfer
PlayerHandleDMA3Transfer: @ 805C71C
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
	thumb_func_end PlayerHandleDMA3Transfer

	thumb_func_start PlayerHandlePlayBGM
PlayerHandlePlayBGM: @ 805C7D0
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
	thumb_func_end PlayerHandlePlayBGM

	thumb_func_start PlayerHandleCmd32
PlayerHandleCmd32: @ 805C800
	push {lr}
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleCmd32

	thumb_func_start PlayerHandleCmd33
PlayerHandleCmd33: @ 805C80C
	push {lr}
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl EmitChoiceReturnValue
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleCmd33

	thumb_func_start PlayerHandleCmd34
PlayerHandleCmd34: @ 805C820
	push {lr}
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl EmitCmd34
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleCmd34

	thumb_func_start PlayerHandleCmd35
PlayerHandleCmd35: @ 805C834
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl EmitCmd35
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleCmd35

	thumb_func_start PlayerHandleCmd36
PlayerHandleCmd36: @ 805C848
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl EmitCmd36
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleCmd36

	thumb_func_start PlayerHandleCmd37
PlayerHandleCmd37: @ 805C85C
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
	thumb_func_end PlayerHandleCmd37

	thumb_func_start PlayerHandleCmd38
PlayerHandleCmd38: @ 805C878
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
	thumb_func_end PlayerHandleCmd38

	thumb_func_start PlayerHandleCmd39
PlayerHandleCmd39: @ 805C8B0
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
	thumb_func_end PlayerHandleCmd39

	thumb_func_start PlayerHandleCmd40
PlayerHandleCmd40: @ 805C8C8
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
	thumb_func_end PlayerHandleCmd40

	thumb_func_start PlayerHandleHitAnimation
PlayerHandleHitAnimation: @ 805C8F0
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
	ldr r1, =DoHitAnimBlinkEffect
	str r1, [r0]
_0805C94E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayerHandleHitAnimation

	thumb_func_start PlayerHandleCmd42
PlayerHandleCmd42: @ 805C960
	push {lr}
	bl PlayerBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleCmd42

	thumb_func_start PlayerHandleEffectivenessSound
PlayerHandleEffectivenessSound: @ 805C96C
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
	thumb_func_end PlayerHandleEffectivenessSound

	thumb_func_start PlayerHandlePlayFanfareOrBGM
PlayerHandlePlayFanfareOrBGM: @ 805C9B0
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
	thumb_func_end PlayerHandlePlayFanfareOrBGM

	thumb_func_start PlayerHandleFaintingCry
PlayerHandleFaintingCry: @ 805CA0C
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
	thumb_func_end PlayerHandleFaintingCry

	thumb_func_start PlayerHandleIntroSlide
PlayerHandleIntroSlide: @ 805CA4C
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
	thumb_func_end PlayerHandleIntroSlide

	thumb_func_start PlayerHandleIntroTrainerBallThrow
PlayerHandleIntroTrainerBallThrow: @ 805CA80
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
	thumb_func_end PlayerHandleIntroTrainerBallThrow

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
	bl BattleLoadPlayerMonSpriteGfx
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
	bl IsDoubleBattle
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
	bl BattleLoadPlayerMonSpriteGfx
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

	thumb_func_start PlayerHandleDrawPartyStatusSummary
PlayerHandleDrawPartyStatusSummary: @ 805CD74
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
	bl CreatePartyStatusSummarySprites
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
	thumb_func_end PlayerHandleDrawPartyStatusSummary

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

	thumb_func_start PlayerHandleCmd49
PlayerHandleCmd49: @ 805CE80
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
	thumb_func_end PlayerHandleCmd49

	thumb_func_start PlayerHandleCmd50
PlayerHandleCmd50: @ 805CED0
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
	thumb_func_end PlayerHandleCmd50

	thumb_func_start PlayerHandleSpriteInvisibility
PlayerHandleSpriteInvisibility: @ 805CEF4
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl AnimBankSpriteExists
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
	thumb_func_end PlayerHandleSpriteInvisibility

	thumb_func_start PlayerHandleBattleAnimation
PlayerHandleBattleAnimation: @ 805CF54
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
	ldr r0, =sub_8059D90
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
	thumb_func_end PlayerHandleBattleAnimation

	thumb_func_start PlayerHandleLinkStandbyMsg
PlayerHandleLinkStandbyMsg: @ 805CFC8
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
	bl PrintLinkStandbyMsg
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
	bl PrintLinkStandbyMsg
_0805D020:
	bl PlayerBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end PlayerHandleLinkStandbyMsg

	thumb_func_start PlayerHandleResetActionMoveSelection
PlayerHandleResetActionMoveSelection: @ 805D02C
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
	thumb_func_end PlayerHandleResetActionMoveSelection

	thumb_func_start PlayerHandleCmd55
PlayerHandleCmd55: @ 805D094
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
	thumb_func_end PlayerHandleCmd55

	thumb_func_start nullsub_22
nullsub_22: @ 805D114
	bx lr
	thumb_func_end nullsub_22
    
   	.align 2, 0 @ Don't pad with nop.
