	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

  	.text
    
 
	thumb_func_start nullsub_26
nullsub_26: @ 805F160
	bx lr
	thumb_func_end nullsub_26

	thumb_func_start SetBankFuncToOpponentBufferRunCommand
SetBankFuncToOpponentBufferRunCommand: @ 805F164
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =OpponentBufferRunCommand
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end SetBankFuncToOpponentBufferRunCommand

	thumb_func_start OpponentBufferRunCommand
OpponentBufferRunCommand: @ 805F180
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
	beq _0805F1CC
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _0805F1C8
	ldr r0, =gOpponentBufferCommands
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _0805F1CC
	.pool
_0805F1C8:
	bl OpponentBufferExecCompleted
_0805F1CC:
	pop {r0}
	bx r0
	thumb_func_end OpponentBufferRunCommand

	thumb_func_start sub_805F1D0
sub_805F1D0: @ 805F1D0
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
	bne _0805F1F4
	bl OpponentBufferExecCompleted
_0805F1F4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F1D0

	thumb_func_start sub_805F208
sub_805F208: @ 805F208
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
	bne _0805F22C
	bl OpponentBufferExecCompleted
_0805F22C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F208

	thumb_func_start sub_805F240
sub_805F240: @ 805F240
	push {r4-r6,lr}
	ldr r5, =gSprites
	ldr r6, =gBankSpriteIds
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _0805F292
	adds r0, r2, r5
	ldrh r0, [r0, 0x6]
	bl sub_805DFE4
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl FreeSpriteOamMatrix
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	bl OpponentBufferExecCompleted
_0805F292:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F240

	thumb_func_start sub_805F2A8
sub_805F2A8: @ 805F2A8
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
	bne _0805F2E0
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl OpponentBufferExecCompleted
_0805F2E0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F2A8

	thumb_func_start sub_805F2F0
sub_805F2F0: @ 805F2F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F32C
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F31E
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F32C
_0805F31E:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0805F368
_0805F32C:
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
	cmp r1, r0
	bne _0805F34E
	movs r1, 0x1
	mov r10, r1
_0805F34E:
	movs r6, 0
	b _0805F3A2
	.pool
_0805F368:
	ldr r3, =gSprites
	ldr r6, =gHealthBoxesIds
	ldr r2, =gActiveBank
	ldrb r4, [r2]
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r5, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r5, r0
	bne _0805F3A0
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	cmp r0, r5
	bne _0805F3A0
	movs r0, 0x1
	mov r10, r0
_0805F3A0:
	movs r6, 0x1
_0805F3A2:
	ldr r3, =gUnknown_020244D8
	ldr r1, =gUnknown_020244D0
	mov r8, r1
	ldr r2, [r1]
	ldr r7, =gActiveBank
	ldrb r1, [r7]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r5, [r2, 0x4]
	adds r0, r5, r0
	str r0, [r3]
	ldr r2, =gUnknown_020244DC
	ldrb r0, [r7]
	movs r1, 0x2
	mov r9, r1
	mov r1, r9
	eors r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5, r0
	str r0, [r2]
	mov r0, r10
	cmp r0, 0
	bne _0805F3D8
	b _0805F53C
_0805F3D8:
	cmp r6, 0x1
	bne _0805F494
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r5
	ldrb r1, [r4, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F3F2
	b _0805F53C
_0805F3F2:
	mov r0, r9
	eors r0, r2
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x1]
	ands r6, r0
	cmp r6, 0
	bne _0805F408
	b _0805F53C
_0805F408:
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r1, r8
	ldr r0, [r1]
	ldrb r2, [r7]
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
	mov r0, r8
	ldr r2, [r0]
	ldrb r0, [r7]
	mov r1, r9
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	mov r1, r8
	ldr r2, [r1]
	ldrb r0, [r7]
	mov r1, r9
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
	b _0805F51A
	.pool
_0805F494:
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805F53C
	adds r0, r2, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0805F4E4
	mov r0, r8
	ldr r2, [r0]
	ldrb r0, [r7]
	mov r1, r9
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	bne _0805F53C
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
_0805F4E4:
	mov r1, r8
	ldr r0, [r1]
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, =gActiveBank
	ldrb r2, [r1]
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
_0805F51A:
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
	ldr r1, =sub_805F2A8
	str r1, [r0]
_0805F53C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F2F0

	thumb_func_start sub_805F560
sub_805F560: @ 805F560
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	mov r10, r0
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r6, 0xC4
	lsls r6, 1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F5A6
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0805F5A6:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00008040
	ands r0, r1
	cmp r0, 0
	bne _0805F5EE
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F5EE
	ldr r2, [r5]
	ldrb r1, [r4]
	movs r0, 0x2
	adds r3, r0, 0
	eors r3, r1
	ldr r1, [r2, 0x4]
	lsls r2, r3, 1
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F5EE
	ldr r0, =gBattlePartyID
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
_0805F5EE:
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r1, =gActiveBank
	mov r8, r1
	ldrb r4, [r1]
	ldr r5, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r5
	ldrb r1, [r3]
	movs r6, 0x8
	adds r0, r6, 0
	ands r0, r1
	mov r9, r2
	cmp r0, 0
	bne _0805F6D0
	movs r7, 0x2
	adds r1, r7, 0
	eors r1, r4
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F6D0
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0805F6B4
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F684
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F684
	ldr r4, =gHealthBoxesIds
	mov r1, r8
	ldrb r0, [r1]
	adds r1, r7, 0
	eors r1, r0
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	mov r1, r8
	ldrb r0, [r1]
	eors r0, r7
	bl sub_8076918
	mov r1, r8
	ldrb r0, [r1]
	eors r0, r7
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_0805F684:
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
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
_0805F6B4:
	ldr r3, =gUnknown_020244D0
	ldr r2, [r3]
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
	mov r9, r3
_0805F6D0:
	mov r1, r9
	ldr r0, [r1]
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
	bne _0805F792
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
	bne _0805F792
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _0805F792
	mov r1, r9
	ldr r0, [r1]
	ldrb r4, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0805F774
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _0805F768
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805F774
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _0805F774
	.pool
_0805F768:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_0805F774:
	ldr r0, =gUnknown_020244D0
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
	str r0, [sp]
_0805F792:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F7B2
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F810
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805F810
_0805F7B2:
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
	bne _0805F86E
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r3
	bne _0805F86E
	movs r1, 0x1
	mov r10, r1
	b _0805F86E
	.pool
_0805F810:
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
	bne _0805F86E
	ldr r6, =gBankSpriteIds
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r5, [r0]
	cmp r5, r4
	bne _0805F86E
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
	bne _0805F86E
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _0805F86E
	movs r0, 0x1
	mov r10, r0
_0805F86E:
	ldr r1, [sp]
	cmp r1, 0
	beq _0805F958
	mov r0, r10
	cmp r0, 0
	beq _0805F958
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F8D2
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F8D2
	ldr r1, =gUnknown_03005D7C
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x2
	eors r0, r4
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldrb r0, [r5]
	eors r4, r0
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
_0805F8D2:
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
	ldrb r5, [r4]
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_805EE54
	ldr r3, =gUnknown_020244D0
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
	ldr r1, =sub_805F2F0
	str r1, [r0]
_0805F958:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F560

	thumb_func_start sub_805F994
sub_805F994: @ 805F994
	push {r4,r5,lr}
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0805F9E0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r2, r3, 1
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	bne _0805F9E0
	ldr r0, =gBattlePartyID
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
_0805F9E0:
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	ldr r5, =gActiveBank
	ldrb r3, [r5]
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
	bne _0805FA48
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805FA48
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r4]
	ldrb r2, [r5]
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
	bl OpponentBufferExecCompleted
_0805FA48:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F994

	thumb_func_start sub_805FA70
sub_805FA70: @ 805FA70
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	ldr r5, =gHealthBoxesIds
	adds r1, r0, r5
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	lsls r4, 16
	asrs r1, r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0805FAB8
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _0805FABC
	.pool
_0805FAB8:
	bl OpponentBufferExecCompleted
_0805FABC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_805FA70

	thumb_func_start sub_805FAC4
sub_805FAC4: @ 805FAC4
	push {lr}
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	bne _0805FAF2
	ldr r0, =gHealthBoxesIds
	adds r0, r3, r0
	ldrb r0, [r0]
	bl sub_8072984
	bl OpponentBufferExecCompleted
_0805FAF2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FAC4

	thumb_func_start sub_805FB08
sub_805FB08: @ 805FB08
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
	bne _0805FB62
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
	ldrb r0, [r6]
	bl sub_805EEE0
	ldr r1, =gHealthBoxesIds
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl OpponentBufferExecCompleted
_0805FB62:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FB08

	thumb_func_start bx_t7_button_a
bx_t7_button_a: @ 805FB7C
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0805FB8E
	bl OpponentBufferExecCompleted
_0805FB8E:
	pop {r0}
	bx r0
	thumb_func_end bx_t7_button_a

	thumb_func_start bx_blink_t7
bx_blink_t7: @ 805FB94
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
	bne _0805FBE0
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
	bl OpponentBufferExecCompleted
	b _0805FC0A
	.pool
_0805FBE0:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0805FC04
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
_0805FC04:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_0805FC0A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t7

	thumb_func_start sub_805FC10
sub_805FC10: @ 805FC10
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
	bne _0805FC5C
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805FC50
	adds r0, r3, 0
	adds r1, r3, 0
	adds r2, r3, 0
	movs r3, 0x6
	bl move_anim_start_t4
_0805FC50:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_803AEDC
	str r0, [r1]
_0805FC5C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FC10

	thumb_func_start bx_803AEDC
bx_803AEDC: @ 805FC80
	push {r4,lr}
	ldr r0, =gUnknown_020244D0
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
	bne _0805FCDA
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _0805FCDA
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldrb r0, [r4]
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
	beq _0805FCCA
	ldr r0, =nullsub_18
	cmp r1, r0
	bne _0805FCDA
_0805FCCA:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	bl OpponentBufferExecCompleted
_0805FCDA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_803AEDC

	thumb_func_start sub_805FD00
sub_805FD00: @ 805FD00
	push {r4-r7,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r1, [r3, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805FDBC
	ldr r7, =gSprites
	ldr r6, =gBankSpriteIds
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r7, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _0805FDBC
	ldrb r1, [r3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r4]
	ldrb r2, [r5]
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
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	bl StartSpriteAnim
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
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r5]
	bl sub_8076918
	ldrb r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
	ldrb r0, [r5]
	bl sub_805E408
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FC10
	str r1, [r0]
_0805FDBC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FD00

	thumb_func_start sub_805FDF0
sub_805FDF0: @ 805FDF0
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
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
	bne _0805FE22
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0805FE22:
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
	bne _0805FE8C
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
	bne _0805FE8C
	adds r0, r3, r4
	bl DestroySprite
	ldrb r4, [r5]
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FD00
	str r1, [r0]
_0805FE8C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FDF0

	thumb_func_start sub_805FEB8
sub_805FEB8: @ 805FEB8
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
	bne _0805FEDA
	bl OpponentBufferExecCompleted
_0805FEDA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FEB8

	thumb_func_start bx_803B0F4
bx_803B0F4: @ 805FEE8
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
	bne _0805FF0A
	bl OpponentBufferExecCompleted
_0805FF0A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_803B0F4

	thumb_func_start OpponentBufferExecCompleted
OpponentBufferExecCompleted: @ 805FF18
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =OpponentBufferRunCommand
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805FF6C
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
	b _0805FF7E
	.pool
_0805FF6C:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0805FF7E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end OpponentBufferExecCompleted

	thumb_func_start dp01t_00_7_getattr
dp01t_00_7_getattr: @ 805FF90
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
	bne _0805FFC8
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl sub_8060004
	adds r6, r0, 0
	b _0805FFEA
	.pool
_0805FFC8:
	ldrb r4, [r1]
	movs r5, 0
_0805FFCC:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0805FFE2
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl sub_8060004
	adds r6, r0
_0805FFE2:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _0805FFCC
_0805FFEA:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl OpponentBufferExecCompleted
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_7_getattr

	thumb_func_start sub_8060004
sub_8060004: @ 8060004
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
	bls _0806002E
	bl _0806079A
_0806002E:
	lsls r0, 2
	ldr r1, =_08060044
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08060044:
	.4byte _08060134
	.4byte _08060358
	.4byte _08060368
	.4byte _08060378
	.4byte _080603E0
	.4byte _080603E0
	.4byte _080603E0
	.4byte _080603E0
	.4byte _080603FC
	.4byte _08060438
	.4byte _08060438
	.4byte _08060438
	.4byte _08060438
	.4byte _0806079A
	.4byte _0806079A
	.4byte _0806079A
	.4byte _0806079A
	.4byte _08060454
	.4byte _08060464
	.4byte _08060494
	.4byte _080604A4
	.4byte _080604B4
	.4byte _080604C4
	.4byte _080604D4
	.4byte _080604E4
	.4byte _080604F4
	.4byte _08060504
	.4byte _08060514
	.4byte _08060524
	.4byte _08060534
	.4byte _08060544
	.4byte _08060554
	.4byte _080605A4
	.4byte _080605B4
	.4byte _080605C4
	.4byte _080605D4
	.4byte _080605E4
	.4byte _080605F4
	.4byte _08060604
	.4byte _08060614
	.4byte _08060624
	.4byte _08060658
	.4byte _08060668
	.4byte _08060678
	.4byte _08060688
	.4byte _08060698
	.4byte _080606A8
	.4byte _080606B8
	.4byte _080606C8
	.4byte _080606E8
	.4byte _080606F8
	.4byte _08060708
	.4byte _08060718
	.4byte _08060728
	.4byte _08060738
	.4byte _08060748
	.4byte _08060758
	.4byte _08060768
	.4byte _08060778
	.4byte _08060788
_08060134:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
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
_08060180:
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
	ble _08060180
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
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
_08060338:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _08060338
	b _0806079A
	.pool
_08060358:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	b _080606D2
	.pool
_08060368:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	b _080606D2
	.pool
_08060378:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	mov r8, r9
_0806038E:
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
	ble _0806038E
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_080603CC:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _080603CC
	b _0806079A
	.pool
_080603E0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _080606D2
	.pool
_080603FC:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gEnemyParty
	mov r8, r2
_08060408:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08060408
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _0806079A
	.pool
_08060438:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _08060792
	.pool
_08060454:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1
	b _0806046E
	.pool
_08060464:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x19
_0806046E:
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
	b _0806079A
	.pool
_08060494:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1A
	b _08060792
	.pool
_080604A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1B
	b _08060792
	.pool
_080604B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1C
	b _08060792
	.pool
_080604C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1D
	b _08060792
	.pool
_080604D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1E
	b _08060792
	.pool
_080604E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1F
	b _08060792
	.pool
_080604F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x20
	b _08060792
	.pool
_08060504:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x22
	b _08060792
	.pool
_08060514:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x23
	b _08060792
	.pool
_08060524:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x24
	b _08060792
	.pool
_08060534:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x25
	b _08060792
	.pool
_08060544:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	b _08060792
	.pool
_08060554:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
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
	b _0806079A
	.pool
_080605A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x27
	b _08060792
	.pool
_080605B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x28
	b _08060792
	.pool
_080605C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x29
	b _08060792
	.pool
_080605D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2A
	b _08060792
	.pool
_080605E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2B
	b _08060792
	.pool
_080605F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	b _08060792
	.pool
_08060604:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0
	b _0806062E
	.pool
_08060614:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x9
	b _080606D2
	.pool
_08060624:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x37
_0806062E:
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
	b _0806079A
	.pool
_08060658:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x38
	b _08060792
	.pool
_08060668:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	b _080606D2
	.pool
_08060678:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	b _080606D2
	.pool
_08060688:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3B
	b _080606D2
	.pool
_08060698:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3C
	b _080606D2
	.pool
_080606A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3D
	b _080606D2
	.pool
_080606B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3E
	b _080606D2
	.pool
_080606C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3F
_080606D2:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _0806079A
	.pool
_080606E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x16
	b _08060792
	.pool
_080606F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x17
	b _08060792
	.pool
_08060708:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x18
	b _08060792
	.pool
_08060718:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x21
	b _08060792
	.pool
_08060728:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2F
	b _08060792
	.pool
_08060738:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x30
	b _08060792
	.pool
_08060748:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x32
	b _08060792
	.pool
_08060758:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x33
	b _08060792
	.pool
_08060768:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x34
	b _08060792
	.pool
_08060778:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x35
	b _08060792
	.pool
_08060788:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x36
_08060792:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_0806079A:
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
	thumb_func_end sub_8060004

	thumb_func_start dp01t_01_2_read_pokmon_data_slice
dp01t_01_2_read_pokmon_data_slice: @ 80607B0
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
	ldr r0, =gEnemyParty
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
	bcs _08060806
	adds r3, r0, 0
_080607EC:
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
	bcc _080607EC
_08060806:
	ldrb r0, [r7]
	lsls r0, 9
	mov r1, r12
	adds r1, 0x2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl OpponentBufferExecCompleted
	add sp, 0x58
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_01_2_read_pokmon_data_slice

	thumb_func_start dp01t_02_7_setattr
dp01t_02_7_setattr: @ 8060838
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08060868
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8060890
	b _08060886
	.pool
_08060868:
	ldrb r4, [r1]
	movs r5, 0
_0806086C:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0806087A
	adds r0, r5, 0
	bl sub_8060890
_0806087A:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0806086C
_08060886:
	bl OpponentBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_02_7_setattr

	thumb_func_start sub_8060890
sub_8060890: @ 8060890
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	ldr r2, =gBattleBufferA + 3
	adds r4, r0, r2
	adds r7, r4, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r3, 0
	adds r3, r2, 0
	cmp r0, 0x3B
	bls _080608BE
	bl _0806119C
_080608BE:
	lsls r0, 2
	ldr r1, =_080608D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080608D4:
	.4byte _080609C4
	.4byte _08060B5C
	.4byte _08060B78
	.4byte _08060B94
	.4byte _08060BE8
	.4byte _08060BE8
	.4byte _08060BE8
	.4byte _08060BE8
	.4byte _08060C08
	.4byte _08060C70
	.4byte _08060C70
	.4byte _08060C70
	.4byte _08060C70
	.4byte _0806119C
	.4byte _0806119C
	.4byte _0806119C
	.4byte _0806119C
	.4byte _08060C98
	.4byte _08060CB4
	.4byte _08060CD0
	.4byte _08060CEC
	.4byte _08060D08
	.4byte _08060D24
	.4byte _08060D40
	.4byte _08060D5C
	.4byte _08060D78
	.4byte _08060D94
	.4byte _08060DB0
	.4byte _08060DCC
	.4byte _08060DE8
	.4byte _08060E04
	.4byte _08060E20
	.4byte _08060E94
	.4byte _08060EB0
	.4byte _08060ECC
	.4byte _08060EE8
	.4byte _08060F04
	.4byte _08060F20
	.4byte _08060F3C
	.4byte _08060F58
	.4byte _08060F74
	.4byte _08060F90
	.4byte _08060FAC
	.4byte _08060FC8
	.4byte _08060FE4
	.4byte _08061000
	.4byte _0806101C
	.4byte _08061038
	.4byte _08061054
	.4byte _08061070
	.4byte _0806108C
	.4byte _080610A8
	.4byte _080610C4
	.4byte _080610E0
	.4byte _080610FC
	.4byte _08061118
	.4byte _08061134
	.4byte _08061150
	.4byte _0806116C
	.4byte _08061188
_080609C4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r7, 0
	bl SetMonData
	adds r2, r7, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r7
	mov r10, r0
	adds r0, r7, 0
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
	adds r0, r7, 0x2
	str r0, [sp, 0x4]
	adds r0, r7, 0x4
	str r0, [sp, 0x8]
	adds r0, r7, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r6, r7, 0
	adds r6, 0x24
	adds r4, r7, 0
	adds r4, 0xC
_08060A2A:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r6, 0
	bl SetMonData
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08060A2A
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
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
	ldrb r0, [r7, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r7, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r7, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldr r0, [r7, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r7, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r7, 0x17]
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
	b _0806119C
	.pool
_08060B5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xB
	bl SetMonData
	b _0806119C
	.pool
_08060B78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xC
	bl SetMonData
	b _0806119C
	.pool
_08060B94:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r4
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r7, r1, r0
	adds r6, r4, 0
	adds r6, 0x8
_08060BAC:
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
	ble _08060BAC
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _0806119C
	.pool
_08060BE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r3, =gBattleBufferA
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _08060C86
	.pool
_08060C08:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x11
	str r3, [sp, 0x34]
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl SetMonData
	b _0806119C
	.pool
_08060C70:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r3, =gBattleBufferA
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_08060C86:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _0806119C
	.pool
_08060C98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1
	bl SetMonData
	b _0806119C
	.pool
_08060CB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x19
	bl SetMonData
	b _0806119C
	.pool
_08060CD0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1A
	bl SetMonData
	b _0806119C
	.pool
_08060CEC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1B
	bl SetMonData
	b _0806119C
	.pool
_08060D08:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1C
	bl SetMonData
	b _0806119C
	.pool
_08060D24:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1D
	bl SetMonData
	b _0806119C
	.pool
_08060D40:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1E
	bl SetMonData
	b _0806119C
	.pool
_08060D5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1F
	bl SetMonData
	b _0806119C
	.pool
_08060D78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x20
	bl SetMonData
	b _0806119C
	.pool
_08060D94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x22
	bl SetMonData
	b _0806119C
	.pool
_08060DB0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x23
	bl SetMonData
	b _0806119C
	.pool
_08060DCC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x24
	bl SetMonData
	b _0806119C
	.pool
_08060DE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x25
	bl SetMonData
	b _0806119C
	.pool
_08060E04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x26
	bl SetMonData
	b _0806119C
	.pool
_08060E20:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x27
	str r3, [sp, 0x34]
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _08060F2E
	.pool
_08060E94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x27
	bl SetMonData
	b _0806119C
	.pool
_08060EB0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x28
	bl SetMonData
	b _0806119C
	.pool
_08060ECC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x29
	bl SetMonData
	b _0806119C
	.pool
_08060EE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2A
	bl SetMonData
	b _0806119C
	.pool
_08060F04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2B
	bl SetMonData
	b _0806119C
	.pool
_08060F20:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
_08060F2E:
	movs r1, 0x2C
	bl SetMonData
	b _0806119C
	.pool
_08060F3C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0
	bl SetMonData
	b _0806119C
	.pool
_08060F58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x9
	bl SetMonData
	b _0806119C
	.pool
_08060F74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x37
	bl SetMonData
	b _0806119C
	.pool
_08060F90:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x38
	bl SetMonData
	b _0806119C
	.pool
_08060FAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x39
	bl SetMonData
	b _0806119C
	.pool
_08060FC8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3A
	bl SetMonData
	b _0806119C
	.pool
_08060FE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3B
	bl SetMonData
	b _0806119C
	.pool
_08061000:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3C
	bl SetMonData
	b _0806119C
	.pool
_0806101C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3D
	bl SetMonData
	b _0806119C
	.pool
_08061038:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3E
	bl SetMonData
	b _0806119C
	.pool
_08061054:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3F
	bl SetMonData
	b _0806119C
	.pool
_08061070:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x16
	bl SetMonData
	b _0806119C
	.pool
_0806108C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x17
	bl SetMonData
	b _0806119C
	.pool
_080610A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x18
	bl SetMonData
	b _0806119C
	.pool
_080610C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x21
	bl SetMonData
	b _0806119C
	.pool
_080610E0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2F
	bl SetMonData
	b _0806119C
	.pool
_080610FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x30
	bl SetMonData
	b _0806119C
	.pool
_08061118:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x32
	bl SetMonData
	b _0806119C
	.pool
_08061134:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x33
	bl SetMonData
	b _0806119C
	.pool
_08061150:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x34
	bl SetMonData
	b _0806119C
	.pool
_0806116C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x35
	bl SetMonData
	b _0806119C
	.pool
_08061188:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x36
	bl SetMonData
_0806119C:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8060890

	thumb_func_start sub_80611B0
sub_80611B0: @ 80611B0
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
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r5, r3, r0
	movs r3, 0
	adds r0, r4, 0x2
	adds r2, r0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _08061208
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_080611E6:
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
	bcc _080611E6
_08061208:
	bl OpponentBufferExecCompleted
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80611B0

	thumb_func_start sub_8061224
sub_8061224: @ 8061224
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 1
	ldr r1, =gBattlePartyID
	adds r0, r1
	ldrh r0, [r0]
	movs r7, 0x64
	muls r0, r7
	ldr r2, =gEnemyParty
	mov r10, r2
	add r0, r10
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldrb r1, [r6]
	lsls r0, r1, 1
	ldr r2, =gBattlePartyID
	adds r0, r2
	ldrh r0, [r0]
	muls r0, r7
	add r0, r10
	bl sub_805DC0C
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r9, r0
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
	mov r0, r9
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
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
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
	bl StartSpriteAnim
	ldrb r4, [r6]
	lsls r0, r4, 1
	ldr r2, =gBattlePartyID
	adds r0, r2
	ldrh r0, [r0]
	muls r0, r7
	add r0, r10
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F994
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061224

	thumb_func_start sub_806137C
sub_806137C: @ 806137C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x5C
	movs r1, 0x6
	strb r1, [r0]
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r2, r0, 1
	adds r2, r1
	ldr r3, =gBattleBufferA
	lsls r0, 9
	adds r1, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2]
	ldrb r0, [r4]
	lsls r1, r0, 9
	adds r3, 0x2
	adds r1, r3
	ldrb r1, [r1]
	bl sub_80613DC
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FDF0
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806137C

	thumb_func_start sub_80613DC
sub_80613DC: @ 80613DC
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
	lsls r4, r6, 1
	adds r4, r0
	ldr r0, =gBattleBufferA
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, 0x64
	mov r9, r1
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =sub_805D714
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gUnknown_03005D7C
	mov r10, r1
	add r10, r6
	mov r1, r10
	strb r0, [r1]
	ldrh r0, [r4]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	adds r0, r5
	adds r1, r6, 0
	bl sub_805DC0C
	adds r0, r6, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r9, r0
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
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, =gBankSpriteIds
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, =gSprites
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
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
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
	movs r1, 0xFE
	bl sub_80753E8
	mov r1, r10
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
	thumb_func_end sub_80613DC

	thumb_func_start sub_806156C
sub_806156C: @ 806156C
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _080615B4
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
	ldr r1, =sub_8061604
	str r1, [r0]
	b _080615F0
	.pool
_080615B4:
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
	ldrb r0, [r6]
	bl sub_805EEE0
	ldr r1, =gHealthBoxesIds
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl OpponentBufferExecCompleted
_080615F0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806156C

	thumb_func_start sub_8061604
sub_8061604: @ 8061604
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
	beq _0806162C
	cmp r0, 0x1
	beq _0806165A
	b _08061682
	.pool
_0806162C:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08061646
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08061646:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08061682
_0806165A:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08061682
	strb r0, [r3, 0x4]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x2
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FB08
	str r1, [r0]
_08061682:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061604

	thumb_func_start sub_8061690
sub_8061690: @ 8061690
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r2
	cmp r0, 0
	beq _080616B0
	bl GetSecretBaseTrainerPicIndex
	b _0806175A
	.pool
_080616B0:
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r1, [r3]
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _080616C8
	bl sub_81A4CB0
	b _0806175A
	.pool
_080616C8:
	movs r0, 0x80
	lsls r0, 19
	ands r0, r2
	cmp r0, 0
	beq _08061708
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _08061700
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080616F0
	ldrh r0, [r3]
	bl sub_81D5588
	b _0806175A
	.pool
_080616F0:
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_81D5588
	b _0806175A
	.pool
_08061700:
	ldrh r0, [r3]
	bl sub_81D5588
	b _0806175A
_08061708:
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _0806174C
	ldr r0, =0x00808000
	ands r2, r0
	cmp r2, 0
	beq _08061744
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08061734
	ldrh r0, [r3]
	bl sub_8162AA0
	b _0806175A
	.pool
_08061734:
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_8162AA0
	b _0806175A
	.pool
_08061744:
	ldrh r0, [r3]
	bl sub_8162AA0
	b _0806175A
_0806174C:
	movs r0, 0x80
	lsls r0, 4
	ands r0, r2
	cmp r0, 0
	beq _08061760
	bl sub_8165244
_0806175A:
	lsls r0, 24
	lsrs r4, r0, 24
	b _08061796
_08061760:
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _08061788
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08061788
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	b _0806178C
	.pool
_08061788:
	ldr r2, =gTrainers
	ldrh r1, [r3]
_0806178C:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r4, [r0, 0x3]
_08061796:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00008040
	ands r0, r1
	cmp r0, 0
	beq _080617C8
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r1, 0x2
	ands r1, r0
	movs r7, 0xC8
	cmp r1, 0
	beq _080617CA
	movs r7, 0x98
	b _080617CA
	.pool
_080617C8:
	movs r7, 0xB0
_080617CA:
	mov r8, r4
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	mov r0, r8
	bl sub_805DF38
	ldrb r0, [r5]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	mov r9, r7
	ldr r1, =gUnknown_083054E0
	mov r2, r8
	lsls r0, r2, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r0, 0xA0
	lsls r0, 14
	adds r4, r0
	asrs r4, 16
	ldrb r0, [r5]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	mov r1, r9
	adds r2, r4, 0
	bl CreateSprite
	ldr r6, =gBankSpriteIds
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gSprites
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ff10
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
	ldr r1, =gTrainerFrontPicPaletteTable
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl IndexOfSpritePaletteTag
	ldrb r1, [r5]
	adds r1, r6
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r8
	strh r1, [r0, 0x6]
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
	ldr r1, =sub_805F1D0
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061690

	thumb_func_start sub_80618D8
sub_80618D8: @ 80618D8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r2
	cmp r0, 0
	beq _080618F8
	bl GetSecretBaseTrainerPicIndex
	b _080619A2
	.pool
_080618F8:
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r1, [r3]
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _08061910
	bl sub_81A4CB0
	b _080619A2
	.pool
_08061910:
	movs r0, 0x80
	lsls r0, 19
	ands r0, r2
	cmp r0, 0
	beq _08061950
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _08061948
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08061938
	ldrh r0, [r3]
	bl sub_81D5588
	b _080619A2
	.pool
_08061938:
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_81D5588
	b _080619A2
	.pool
_08061948:
	ldrh r0, [r3]
	bl sub_81D5588
	b _080619A2
_08061950:
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _08061994
	ldr r0, =0x00808000
	ands r2, r0
	cmp r2, 0
	beq _0806198C
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806197C
	ldrh r0, [r3]
	bl sub_8162AA0
	b _080619A2
	.pool
_0806197C:
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_8162AA0
	b _080619A2
	.pool
_0806198C:
	ldrh r0, [r3]
	bl sub_8162AA0
	b _080619A2
_08061994:
	movs r0, 0x80
	lsls r0, 4
	ands r0, r2
	cmp r0, 0
	beq _080619A8
	bl sub_8165244
_080619A2:
	lsls r0, 24
	lsrs r0, 24
	b _080619DE
_080619A8:
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _080619D0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080619D0
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	b _080619D4
	.pool
_080619D0:
	ldr r2, =gTrainers
	ldrh r1, [r3]
_080619D4:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x3]
_080619DE:
	mov r8, r0
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	bl sub_805DF38
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r2, =gUnknown_083054E0
	mov r3, r8
	lsls r1, r3, 2
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 14
	adds r2, r1
	asrs r2, 16
	movs r1, 0xB0
	movs r3, 0x1E
	bl CreateSprite
	ldr r5, =gBankSpriteIds
	ldrb r1, [r6]
	adds r1, r5
	strb r0, [r1]
	ldr r4, =gSprites
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x60
	strh r1, [r0, 0x24]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x20]
	adds r1, 0x20
	strh r1, [r0, 0x20]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldr r1, =gTrainerFrontPicPaletteTable
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl IndexOfSpritePaletteTag
	ldrb r1, [r6]
	adds r1, r5
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r3, r8
	strh r3, [r0, 0x6]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F208
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80618D8

	thumb_func_start sub_8061AF0
sub_8061AF0: @ 8061AF0
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
	movs r1, 0x8C
	lsls r1, 1
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
	ldr r1, =sub_805F240
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061AF0

	thumb_func_start sub_8061B9C
sub_8061B9C: @ 8061B9C
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
	bne _08061BF0
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08061BD0
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08061BD0:
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
	b _08061C2C
	.pool
_08061BF0:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08061C2C
	strb r0, [r3, 0x4]
	movs r0, 0x10
	movs r1, 0x3F
	bl PlaySE12WithPanning
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldrb r0, [r5]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039934
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FAC4
	str r1, [r0]
_08061C2C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061B9C

	thumb_func_start sub_8061C48
sub_8061C48: @ 8061C48
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061C48

	thumb_func_start sub_8061C54
sub_8061C54: @ 8061C54
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061C54

	thumb_func_start sub_8061C60
sub_8061C60: @ 8061C60
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061C60

	thumb_func_start sub_8061C6C
sub_8061C6C: @ 8061C6C
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061C6C

	thumb_func_start sub_8061C78
sub_8061C78: @ 8061C78
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _08061C8A
	b _08061D9E
_08061C8A:
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
	beq _08061D80
	bl OpponentBufferExecCompleted
	b _08061D9E
	.pool
_08061D80:
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
	ldr r1, =bx_move_anim_7
	str r1, [r0]
_08061D9E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061C78

	thumb_func_start bx_move_anim_7
bx_move_anim_7: @ 8061DB0
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
	beq _08061E48
	cmp r2, 0x1
	bgt _08061E08
	cmp r2, 0
	beq _08061E12
	b _08061F24
	.pool
_08061E08:
	cmp r2, 0x2
	beq _08061E72
	cmp r2, 0x3
	beq _08061EE8
	b _08061F24
_08061E12:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _08061E34
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08061E34:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08061F24
_08061E48:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08061F24
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
	b _08061F24
_08061E72:
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _08061F24
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
	beq _08061EC0
	mov r0, r8
	cmp r0, 0x1
	bhi _08061EC0
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
_08061EC0:
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
	b _08061F24
	.pool
_08061EE8:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08061F24
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
	bl OpponentBufferExecCompleted
_08061F24:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_7

	thumb_func_start sub_8061F34
sub_8061F34: @ 8061F34
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
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
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t7_button_a
	str r1, [r0]
	ldrb r0, [r5]
	ldrh r1, [r4]
	bl sub_81A57E4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061F34

	thumb_func_start sub_8061F90
sub_8061F90: @ 8061F90
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061F90

	thumb_func_start sub_8061F9C
sub_8061F9C: @ 8061F9C
	push {lr}
	bl sub_8063880
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061F9C

	thumb_func_start sub_8061FAC
sub_8061FAC: @ 8061FAC
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8061FAC

	thumb_func_start sub_8061FB8
sub_8061FB8: @ 8061FB8
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 10
	ands r0, r2
	cmp r0, 0
	beq _08061FE4
	bl sub_805D19C
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xA
_08061FD6:
	bl dp01_build_cmdbuf_x21_a_bb
_08061FDA:
	bl OpponentBufferExecCompleted
	b _08062156
	.pool
_08061FE4:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r1, =gBattleBufferA + 4
	adds r5, r0, r1
	movs r0, 0x93
	lsls r0, 3
	ands r2, r0
	cmp r2, 0
	beq _080620C4
	movs r0, 0xF
	bl BattleAI_SetupAIData
	bl BattleAI_ChooseMoveOrAction
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	beq _08062022
	cmp r4, 0x5
	bgt _0806201C
	cmp r4, 0x4
	beq _08062028
	b _08062040
	.pool
_0806201C:
	cmp r4, 0x6
	beq _08062030
	b _08062040
_08062022:
	movs r0, 0x1
	movs r1, 0x4
	b _0806202C
_08062028:
	movs r0, 0x1
	movs r1, 0x3
_0806202C:
	movs r2, 0
	b _08061FD6
_08062030:
	ldr r0, =gBankTarget
	ldrb r2, [r0]
	movs r0, 0x1
	movs r1, 0xF
	b _08061FD6
	.pool
_08062040:
	ldr r3, =gBattleMoves
	lsls r0, r4, 1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x6]
	movs r0, 0x12
	ands r0, r1
	cmp r0, 0
	beq _08062062
	ldr r0, =gBankTarget
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	strb r1, [r0]
_08062062:
	ldrh r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x6]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806209C
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r5, =gBankTarget
	strb r0, [r5]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0806209C
	movs r0, 0x2
	bl GetBankByPlayerAI
	strb r0, [r5]
_0806209C:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	movs r0, 0x1
	movs r1, 0xA
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08061FDA
	.pool
_080620C4:
	movs r6, 0x3
_080620C6:
	bl Random
	adds r4, r0, 0
	ands r4, r6
	lsls r0, r4, 1
	adds r0, r5, r0
	ldrh r2, [r0]
	cmp r2, 0
	beq _080620C6
	ldr r1, =gBattleMoves
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x6]
	movs r0, 0x12
	ands r0, r1
	cmp r0, 0
	beq _08062108
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	movs r0, 0x1
	movs r1, 0xA
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08062152
	.pool
_08062108:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806213C
	bl Random
	movs r1, 0x2
	ands r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1, 0
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 16
	orrs r2, r4
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	b _08062152
	.pool
_0806213C:
	movs r0, 0
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 16
	orrs r2, r4
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
_08062152:
	bl OpponentBufferExecCompleted
_08062156:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8061FB8

	thumb_func_start sub_806215C
sub_806215C: @ 806215C
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsrs r0, 1
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC0
	ldrb r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806215C

	thumb_func_start sub_8062188
sub_8062188: @ 8062188
	push {r4-r7,lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	movs r2, 0xA5
	lsls r2, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _08062254
	bl sub_8063A90
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bne _0806225A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080621D4
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	b _080621E8
	.pool
_080621D4:
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x3
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
_080621E8:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08062214
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08062210
	movs r0, 0
	movs r6, 0x3
	b _08062218
	.pool
_08062210:
	movs r0, 0x3
	b _08062216
_08062214:
	movs r0, 0
_08062216:
	movs r6, 0x6
_08062218:
	adds r4, r0, 0
	b _0806221E
_0806221C:
	adds r4, 0x1
_0806221E:
	cmp r4, r6
	bge _0806225A
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0806221C
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0806221C
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0806221C
	b _0806225A
	.pool
_08062254:
	ldrb r4, [r1]
	movs r0, 0x6
	strb r0, [r1]
_0806225A:
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
	bl OpponentBufferExecCompleted
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062188

	thumb_func_start sub_8062288
sub_8062288: @ 8062288
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062288

	thumb_func_start sub_8062294
sub_8062294: @ 8062294
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
	adds r0, r3, 0x3
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r1, 8
	adds r3, 0x2
	adds r2, r3
	ldrb r0, [r2]
	orrs r0, r1
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _08062324
	ldr r6, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gEnemyParty
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
	b _0806234E
	.pool
_08062324:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
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
_0806234E:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FA70
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062294

	thumb_func_start sub_8062384
sub_8062384: @ 8062384
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062384

	thumb_func_start sub_8062390
sub_8062390: @ 8062390
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _080623E4
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
	ldr r2, =gEnemyParty
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
	ldr r1, =sub_805FEB8
	str r1, [r0]
_080623E4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062390

	thumb_func_start sub_8062408
sub_8062408: @ 8062408
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08062458
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
	ldr r1, =sub_805FEB8
	str r1, [r0]
_08062458:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062408

	thumb_func_start sub_8062470
sub_8062470: @ 8062470
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062470

	thumb_func_start sub_806247C
sub_806247C: @ 806247C
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_806247C

	thumb_func_start sub_8062488
sub_8062488: @ 8062488
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062488

	thumb_func_start sub_8062494
sub_8062494: @ 8062494
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062494

	thumb_func_start sub_80624A0
sub_80624A0: @ 80624A0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80624A0

	thumb_func_start sub_80624AC
sub_80624AC: @ 80624AC
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80624AC

	thumb_func_start sub_80624B8
sub_80624B8: @ 80624B8
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80624B8

	thumb_func_start sub_80624C4
sub_80624C4: @ 80624C4
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80624C4

	thumb_func_start sub_80624D0
sub_80624D0: @ 80624D0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80624D0

	thumb_func_start sub_80624DC
sub_80624DC: @ 80624DC
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80624DC

	thumb_func_start sub_80624F8
sub_80624F8: @ 80624F8
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
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80624F8

	thumb_func_start sub_8062530
sub_8062530: @ 8062530
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062530

	thumb_func_start sub_8062548
sub_8062548: @ 8062548
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
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062548

	thumb_func_start dp01t_29_7_blink
dp01t_29_7_blink: @ 8062570
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
	bge _080625A4
	bl OpponentBufferExecCompleted
	b _080625CE
	.pool
_080625A4:
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
	ldr r1, =bx_blink_t7
	str r1, [r0]
_080625CE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_29_7_blink

	thumb_func_start sub_80625E0
sub_80625E0: @ 80625E0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80625E0

	thumb_func_start sub_80625EC
sub_80625EC: @ 80625EC
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _08062600
	movs r3, 0xC0
_08062600:
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
	bl OpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80625EC

	thumb_func_start sub_8062630
sub_8062630: @ 8062630
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806266C
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
	b _08062680
	.pool
_0806266C:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayFanfare
_08062680:
	bl OpponentBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8062630

	thumb_func_start sub_806268C
sub_806268C: @ 806268C
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	movs r2, 0x5
	bl PlayCry3
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806268C

	thumb_func_start dp01t_2E_7_battle_intro
dp01t_2E_7_battle_intro: @ 80626C8
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
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_7_battle_intro

	thumb_func_start sub_80626FC
sub_80626FC: @ 80626FC
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
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x8C
	lsls r1, 1
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
	ldr r1, =sub_806280C
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_8062828
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r6]
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080627BE
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_080627BE:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_26
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80626FC

	thumb_func_start sub_806280C
sub_806280C: @ 806280C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x6]
	bl sub_805DFE4
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806280C

	thumb_func_start sub_8062828
sub_8062828: @ 8062828
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0806286C
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0806286C
	movs r0, 0x80
	lsls r0, 8
	ands r1, r0
	cmp r1, 0
	beq _080628A0
_0806286C:
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
	bl sub_80613DC
	b _080628E0
	.pool
_080628A0:
	ldr r4, =gBattleBufferA
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r4, 0x1
	adds r1, r4
	ldr r6, =gBattlePartyID
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_80613DC
	ldrb r0, [r7]
	movs r5, 0x2
	eors r0, r5
	strb r0, [r7]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r4
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_80613DC
	ldrb r0, [r7]
	eors r0, r5
	strb r0, [r7]
_080628E0:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F560
	str r1, [r0]
	mov r0, r9
	strb r0, [r2]
	mov r0, r8
	bl DestroyTask
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062828

	thumb_func_start dp01t_30_7_0803D67C
dp01t_30_7_0803D67C: @ 8062918
	push {r4-r7,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08062948
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08062948
	bl OpponentBufferExecCompleted
	b _08062A12
	.pool
_08062948:
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldr r1, =gBattleBufferA
	ldrb r2, [r3]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r7, r3, 0
	cmp r0, 0
	beq _080629B4
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r2, [r3, 0x1]
	lsls r1, r2, 27
	lsrs r0, r1, 28
	cmp r0, 0x1
	bhi _080629AC
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	lsls r0, 1
	movs r1, 0x1F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	b _08062A12
	.pool
_080629AC:
	movs r0, 0x1F
	negs r0, r0
	ands r0, r2
	strb r0, [r3, 0x1]
_080629B4:
	adds r5, r7, 0
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
	ldr r6, =gUnknown_020244D0
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
	beq _08062A06
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_08062A06:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_0803D790_t7
	str r0, [r1]
_08062A12:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_30_7_0803D67C

	thumb_func_start bx_0803D790_t7
bx_0803D790_t7: @ 8062A2C
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
	bls _08062A64
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl OpponentBufferExecCompleted
_08062A64:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_0803D790_t7

	thumb_func_start sub_8062A74
sub_8062A74: @ 8062A74
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
	beq _08062AA6
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
_08062AA6:
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062A74

	thumb_func_start sub_8062AC4
sub_8062AC4: @ 8062AC4
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062AC4

	thumb_func_start sub_8062AD0
sub_8062AD0: @ 8062AD0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _08062B16
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
_08062B16:
	bl OpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062AD0

	thumb_func_start dp01t_34_7_move_anim_start_t3
dp01t_34_7_move_anim_start_t3: @ 8062B30
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08062B88
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
	beq _08062B7C
	bl OpponentBufferExecCompleted
	b _08062B88
	.pool
_08062B7C:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_803B0F4
	str r0, [r1]
_08062B88:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_34_7_move_anim_start_t3

	thumb_func_start sub_8062B98
sub_8062B98: @ 8062B98
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062B98

	thumb_func_start sub_8062BA4
sub_8062BA4: @ 8062BA4
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8062BA4

	thumb_func_start sub_8062BB0
sub_8062BB0: @ 8062BB0
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x6
	ands r0, r1
	cmp r0, 0x2
	bne _08062BDA
	ldr r2, =gMain
	ldr r0, =0x00000439
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	bl SetMainCallback2
_08062BDA:
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062BB0

	thumb_func_start nullsub_91
nullsub_91: @ 8062BF4
	bx lr
	thumb_func_end nullsub_91

    
   	.align 2, 0 @ Don't pad with nop.
