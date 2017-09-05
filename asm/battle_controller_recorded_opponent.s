	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_70
nullsub_70: @ 81864E8
	bx lr
	thumb_func_end nullsub_70

	thumb_func_start SetBankFuncToRecordedOpponentBufferRunCommand
SetBankFuncToRecordedOpponentBufferRunCommand: @ 81864EC
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =RecordedOpponentBufferRunCommand
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end SetBankFuncToRecordedOpponentBufferRunCommand

	thumb_func_start RecordedOpponentBufferRunCommand
RecordedOpponentBufferRunCommand: @ 8186508
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
	beq _08186554
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _08186550
	ldr r0, =gRecordedOpponentBufferCommands
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _08186554
	.pool
_08186550:
	bl RecordedOpponentBufferExecCompleted
_08186554:
	pop {r0}
	bx r0
	thumb_func_end RecordedOpponentBufferRunCommand

	thumb_func_start sub_8186558
sub_8186558: @ 8186558
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
	bne _0818657C
	bl RecordedOpponentBufferExecCompleted
_0818657C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186558

	thumb_func_start sub_8186590
sub_8186590: @ 8186590
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
	bne _081865B4
	bl RecordedOpponentBufferExecCompleted
_081865B4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186590

	thumb_func_start sub_81865C8
sub_81865C8: @ 81865C8
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
	bne _0818661A
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
	bl RecordedOpponentBufferExecCompleted
_0818661A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81865C8

	thumb_func_start sub_8186630
sub_8186630: @ 8186630
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
	bne _08186668
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl RecordedOpponentBufferExecCompleted
_08186668:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186630

	thumb_func_start sub_8186678
sub_8186678: @ 8186678
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	mov r9, r0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081866A4
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081866F8
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081866F8
_081866A4:
	ldr r4, =gSprites
	ldr r0, =gUnknown_03005D70
	ldr r2, =gActiveBank
	ldrb r3, [r2]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	mov r8, r2
	cmp r1, r0
	bne _08186764
	ldr r0, =gBankSpriteIds
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _08186764
	b _0818676A
	.pool
_081866F8:
	ldr r6, =gSprites
	ldr r7, =gUnknown_03005D70
	ldr r2, =gActiveBank
	ldrb r3, [r2]
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r6, 0
	adds r5, 0x1C
	adds r0, r5
	ldr r4, [r0]
	ldr r0, =SpriteCallbackDummy
	mov r8, r2
	cmp r4, r0
	bne _08186764
	movs r0, 0x2
	adds r2, r3, 0
	eors r2, r0
	adds r0, r2, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r4
	bne _08186764
	ldr r4, =gBankSpriteIds
	adds r0, r3, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _08186764
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _08186764
	movs r1, 0x1
	mov r9, r1
_08186764:
	mov r2, r9
	cmp r2, 0
	beq _0818683A
_0818676A:
	mov r6, r8
	ldrb r0, [r6]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bne _08186816
	ldr r0, =gUnknown_020244D0
	mov r12, r0
	ldr r0, [r0]
	ldrb r2, [r6]
	ldr r5, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r5
	ldrb r1, [r4, 0x1]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0818683A
	movs r7, 0x2
	adds r1, r7, 0
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0818683A
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r1, r12
	ldr r0, [r1]
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
	mov r0, r12
	ldr r2, [r0]
	ldrb r0, [r6]
	adds r1, r7, 0
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	mov r1, r12
	ldr r2, [r1]
	ldrb r0, [r6]
	adds r1, r7, 0
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
_08186816:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	mov r2, r8
	ldrb r1, [r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x9]
	ldr r1, =gBattleBankFunc
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8186630
	str r1, [r0]
_0818683A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186678

	thumb_func_start sub_818686C
sub_818686C: @ 818686C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	mov r9, r0
	mov r8, r0
	ldr r4, =gUnknown_020244D0
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
	bne _081868AC
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_081868AC:
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
	bne _081868DE
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_081868DE:
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
	bne _081869AE
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
	bne _081869AE
	ldrb r1, [r4, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08186994
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08186964
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08186964
	ldr r4, =gUnknown_03005D70
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
	ldr r2, =gEnemyParty
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
_08186964:
	ldr r5, =gUnknown_03005D70
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
_08186994:
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
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
_081869AE:
	ldr r5, =gUnknown_020244D0
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
	bne _08186A6A
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
	bne _08186A6A
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _08186A6A
	ldr r0, [r5]
	ldrb r2, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08186A4C
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _08186A40
	adds r0, r2, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08186A4C
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _08186A4C
	.pool
_08186A40:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_08186A4C:
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
	mov r9, r0
_08186A6A:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	bne _08186AC8
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
	bne _08186B26
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r3
	bne _08186B26
	b _08186B22
	.pool
_08186AC8:
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
	bne _08186B26
	ldr r6, =gBankSpriteIds
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r5, [r0]
	cmp r5, r4
	bne _08186B26
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
	bne _08186B26
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _08186B26
_08186B22:
	movs r0, 0x1
	mov r8, r0
_08186B26:
	mov r0, r9
	cmp r0, 0
	beq _08186C10
	mov r0, r8
	cmp r0, 0
	beq _08186C10
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08186B8A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08186B8A
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
_08186B8A:
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
	ldr r1, =sub_8186678
	str r1, [r0]
_08186C10:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818686C

	thumb_func_start sub_8186C48
sub_8186C48: @ 8186C48
	push {r4-r7,lr}
	ldr r4, =gSprites
	ldr r0, =gBankSpriteIds
	ldr r7, =gActiveBank
	ldrb r3, [r7]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _08186CFA
	adds r0, r2, r4
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08186CFA
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r4, r3, 1
	adds r0, r4, r3
	lsls r0, 2
	adds r2, r0, r1
	ldrb r5, [r2]
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	bne _08186CC0
	ldr r0, =gBattlePartyID
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
	b _08186CFA
	.pool
_08186CC0:
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08186CFA
	movs r0, 0x7F
	ands r0, r5
	strb r0, [r2]
	ldr r0, [r6]
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
	bl RecordedOpponentBufferExecCompleted
_08186CFA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186C48

	thumb_func_start sub_8186D04
sub_8186D04: @ 8186D04
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	ldr r5, =gUnknown_03005D70
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
	beq _08186D4C
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _08186D50
	.pool
_08186D4C:
	bl RecordedOpponentBufferExecCompleted
_08186D50:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8186D04

	thumb_func_start sub_8186D58
sub_8186D58: @ 8186D58
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
	bne _08186D86
	ldr r0, =gUnknown_03005D70
	adds r0, r3, r0
	ldrb r0, [r0]
	bl sub_8072984
	bl RecordedOpponentBufferExecCompleted
_08186D86:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186D58

	thumb_func_start sub_8186D9C
sub_8186D9C: @ 8186D9C
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
	bne _08186DF6
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
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl RecordedOpponentBufferExecCompleted
_08186DF6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186D9C

	thumb_func_start sub_8186E10
sub_8186E10: @ 8186E10
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _08186E22
	bl RecordedOpponentBufferExecCompleted
_08186E22:
	pop {r0}
	bx r0
	thumb_func_end sub_8186E10

	thumb_func_start bx_blink_t2
bx_blink_t2: @ 8186E28
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
	bne _08186E74
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
	bl RecordedOpponentBufferExecCompleted
	b _08186E9E
	.pool
_08186E74:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08186E98
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
_08186E98:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_08186E9E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t2

	thumb_func_start sub_8186EA4
sub_8186EA4: @ 8186EA4
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
	bne _08186EF0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08186EE4
	adds r0, r3, 0
	adds r1, r3, 0
	adds r2, r3, 0
	movs r3, 0x6
	bl move_anim_start_t4
_08186EE4:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8186F14
	str r0, [r1]
_08186EF0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186EA4

	thumb_func_start sub_8186F14
sub_8186F14: @ 8186F14
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
	bne _08186F6E
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _08186F6E
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
	beq _08186F5E
	ldr r0, =nullsub_18
	cmp r1, r0
	bne _08186F6E
_08186F5E:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	bl RecordedOpponentBufferExecCompleted
_08186F6E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186F14

	thumb_func_start sub_8186F94
sub_8186F94: @ 8186F94
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
	beq _08187050
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
	bne _08187050
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
	ldr r4, =gUnknown_03005D70
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
	ldr r1, =sub_8186EA4
	str r1, [r0]
_08187050:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186F94

	thumb_func_start sub_8187084
sub_8187084: @ 8187084
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
	bne _081870B6
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_081870B6:
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
	bne _08187120
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
	bne _08187120
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
	ldr r1, =sub_8186F94
	str r1, [r0]
_08187120:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8187084

	thumb_func_start sub_818714C
sub_818714C: @ 818714C
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
	bne _0818716E
	bl RecordedOpponentBufferExecCompleted
_0818716E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818714C

	thumb_func_start sub_818717C
sub_818717C: @ 818717C
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
	bne _0818719E
	bl RecordedOpponentBufferExecCompleted
_0818719E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818717C

	thumb_func_start RecordedOpponentBufferExecCompleted
RecordedOpponentBufferExecCompleted: @ 81871AC
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =RecordedOpponentBufferRunCommand
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08187200
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
	b _08187212
	.pool
_08187200:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_08187212:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RecordedOpponentBufferExecCompleted

	thumb_func_start sub_8187224
sub_8187224: @ 8187224
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
	bne _0818725C
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl sub_8187298
	adds r6, r0, 0
	b _0818727E
	.pool
_0818725C:
	ldrb r4, [r1]
	movs r5, 0
_08187260:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08187276
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl sub_8187298
	adds r6, r0
_08187276:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _08187260
_0818727E:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl RecordedOpponentBufferExecCompleted
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8187224

	thumb_func_start sub_8187298
sub_8187298: @ 8187298
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
	bls _081872C2
	bl _08187A2E
_081872C2:
	lsls r0, 2
	ldr r1, =_081872D8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081872D8:
	.4byte _081873C8
	.4byte _081875EC
	.4byte _081875FC
	.4byte _0818760C
	.4byte _08187674
	.4byte _08187674
	.4byte _08187674
	.4byte _08187674
	.4byte _08187690
	.4byte _081876CC
	.4byte _081876CC
	.4byte _081876CC
	.4byte _081876CC
	.4byte _08187A2E
	.4byte _08187A2E
	.4byte _08187A2E
	.4byte _08187A2E
	.4byte _081876E8
	.4byte _081876F8
	.4byte _08187728
	.4byte _08187738
	.4byte _08187748
	.4byte _08187758
	.4byte _08187768
	.4byte _08187778
	.4byte _08187788
	.4byte _08187798
	.4byte _081877A8
	.4byte _081877B8
	.4byte _081877C8
	.4byte _081877D8
	.4byte _081877E8
	.4byte _08187838
	.4byte _08187848
	.4byte _08187858
	.4byte _08187868
	.4byte _08187878
	.4byte _08187888
	.4byte _08187898
	.4byte _081878A8
	.4byte _081878B8
	.4byte _081878EC
	.4byte _081878FC
	.4byte _0818790C
	.4byte _0818791C
	.4byte _0818792C
	.4byte _0818793C
	.4byte _0818794C
	.4byte _0818795C
	.4byte _0818797C
	.4byte _0818798C
	.4byte _0818799C
	.4byte _081879AC
	.4byte _081879BC
	.4byte _081879CC
	.4byte _081879DC
	.4byte _081879EC
	.4byte _081879FC
	.4byte _08187A0C
	.4byte _08187A1C
_081873C8:
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
_08187414:
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
	ble _08187414
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
_081875CC:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _081875CC
	b _08187A2E
	.pool
_081875EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	b _08187966
	.pool
_081875FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	b _08187966
	.pool
_0818760C:
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
_08187622:
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
	ble _08187622
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
_08187660:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _08187660
	b _08187A2E
	.pool
_08187674:
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
	b _08187966
	.pool
_08187690:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gEnemyParty
	mov r8, r2
_0818769C:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0818769C
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _08187A2E
	.pool
_081876CC:
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
	b _08187A26
	.pool
_081876E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1
	b _08187702
	.pool
_081876F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x19
_08187702:
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
	b _08187A2E
	.pool
_08187728:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1A
	b _08187A26
	.pool
_08187738:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1B
	b _08187A26
	.pool
_08187748:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1C
	b _08187A26
	.pool
_08187758:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1D
	b _08187A26
	.pool
_08187768:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1E
	b _08187A26
	.pool
_08187778:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1F
	b _08187A26
	.pool
_08187788:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x20
	b _08187A26
	.pool
_08187798:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x22
	b _08187A26
	.pool
_081877A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x23
	b _08187A26
	.pool
_081877B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x24
	b _08187A26
	.pool
_081877C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x25
	b _08187A26
	.pool
_081877D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	b _08187A26
	.pool
_081877E8:
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
	b _08187A2E
	.pool
_08187838:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x27
	b _08187A26
	.pool
_08187848:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x28
	b _08187A26
	.pool
_08187858:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x29
	b _08187A26
	.pool
_08187868:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2A
	b _08187A26
	.pool
_08187878:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2B
	b _08187A26
	.pool
_08187888:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	b _08187A26
	.pool
_08187898:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0
	b _081878C2
	.pool
_081878A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x9
	b _08187966
	.pool
_081878B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x37
_081878C2:
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
	b _08187A2E
	.pool
_081878EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x38
	b _08187A26
	.pool
_081878FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	b _08187966
	.pool
_0818790C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	b _08187966
	.pool
_0818791C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3B
	b _08187966
	.pool
_0818792C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3C
	b _08187966
	.pool
_0818793C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3D
	b _08187966
	.pool
_0818794C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3E
	b _08187966
	.pool
_0818795C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3F
_08187966:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _08187A2E
	.pool
_0818797C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x16
	b _08187A26
	.pool
_0818798C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x17
	b _08187A26
	.pool
_0818799C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x18
	b _08187A26
	.pool
_081879AC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x21
	b _08187A26
	.pool
_081879BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2F
	b _08187A26
	.pool
_081879CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x30
	b _08187A26
	.pool
_081879DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x32
	b _08187A26
	.pool
_081879EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x33
	b _08187A26
	.pool
_081879FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x34
	b _08187A26
	.pool
_08187A0C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x35
	b _08187A26
	.pool
_08187A1C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x36
_08187A26:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_08187A2E:
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
	thumb_func_end sub_8187298

	thumb_func_start sub_8187A44
sub_8187A44: @ 8187A44
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8187A44

	thumb_func_start sub_8187A50
sub_8187A50: @ 8187A50
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08187A80
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl dp01_setattr_for_opponent_pokemon
	b _08187A9E
	.pool
_08187A80:
	ldrb r4, [r1]
	movs r5, 0
_08187A84:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08187A92
	adds r0, r5, 0
	bl dp01_setattr_for_opponent_pokemon
_08187A92:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08187A84
_08187A9E:
	bl RecordedOpponentBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8187A50

	thumb_func_start dp01_setattr_for_opponent_pokemon
dp01_setattr_for_opponent_pokemon: @ 8187AA8
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
	ldr r2, =gUnknown_02023067
	adds r4, r0, r2
	adds r7, r4, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r3, 0
	adds r3, r2, 0
	cmp r0, 0x3B
	bls _08187AD6
	bl _081883B4
_08187AD6:
	lsls r0, 2
	ldr r1, =_08187AEC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08187AEC:
	.4byte _08187BDC
	.4byte _08187D74
	.4byte _08187D90
	.4byte _08187DAC
	.4byte _08187E00
	.4byte _08187E00
	.4byte _08187E00
	.4byte _08187E00
	.4byte _08187E20
	.4byte _08187E88
	.4byte _08187E88
	.4byte _08187E88
	.4byte _08187E88
	.4byte _081883B4
	.4byte _081883B4
	.4byte _081883B4
	.4byte _081883B4
	.4byte _08187EB0
	.4byte _08187ECC
	.4byte _08187EE8
	.4byte _08187F04
	.4byte _08187F20
	.4byte _08187F3C
	.4byte _08187F58
	.4byte _08187F74
	.4byte _08187F90
	.4byte _08187FAC
	.4byte _08187FC8
	.4byte _08187FE4
	.4byte _08188000
	.4byte _0818801C
	.4byte _08188038
	.4byte _081880AC
	.4byte _081880C8
	.4byte _081880E4
	.4byte _08188100
	.4byte _0818811C
	.4byte _08188138
	.4byte _08188154
	.4byte _08188170
	.4byte _0818818C
	.4byte _081881A8
	.4byte _081881C4
	.4byte _081881E0
	.4byte _081881FC
	.4byte _08188218
	.4byte _08188234
	.4byte _08188250
	.4byte _0818826C
	.4byte _08188288
	.4byte _081882A4
	.4byte _081882C0
	.4byte _081882DC
	.4byte _081882F8
	.4byte _08188314
	.4byte _08188330
	.4byte _0818834C
	.4byte _08188368
	.4byte _08188384
	.4byte _081883A0
_08187BDC:
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
_08187C42:
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
	ble _08187C42
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
	b _081883B4
	.pool
_08187D74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xB
	bl SetMonData
	b _081883B4
	.pool
_08187D90:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xC
	bl SetMonData
	b _081883B4
	.pool
_08187DAC:
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
_08187DC4:
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
	ble _08187DC4
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _081883B4
	.pool
_08187E00:
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
	b _08187E9E
	.pool
_08187E20:
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
	b _081883B4
	.pool
_08187E88:
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
_08187E9E:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _081883B4
	.pool
_08187EB0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1
	bl SetMonData
	b _081883B4
	.pool
_08187ECC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x19
	bl SetMonData
	b _081883B4
	.pool
_08187EE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1A
	bl SetMonData
	b _081883B4
	.pool
_08187F04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1B
	bl SetMonData
	b _081883B4
	.pool
_08187F20:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1C
	bl SetMonData
	b _081883B4
	.pool
_08187F3C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1D
	bl SetMonData
	b _081883B4
	.pool
_08187F58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1E
	bl SetMonData
	b _081883B4
	.pool
_08187F74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1F
	bl SetMonData
	b _081883B4
	.pool
_08187F90:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x20
	bl SetMonData
	b _081883B4
	.pool
_08187FAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x22
	bl SetMonData
	b _081883B4
	.pool
_08187FC8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x23
	bl SetMonData
	b _081883B4
	.pool
_08187FE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x24
	bl SetMonData
	b _081883B4
	.pool
_08188000:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x25
	bl SetMonData
	b _081883B4
	.pool
_0818801C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x26
	bl SetMonData
	b _081883B4
	.pool
_08188038:
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
	b _08188146
	.pool
_081880AC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x27
	bl SetMonData
	b _081883B4
	.pool
_081880C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x28
	bl SetMonData
	b _081883B4
	.pool
_081880E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x29
	bl SetMonData
	b _081883B4
	.pool
_08188100:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2A
	bl SetMonData
	b _081883B4
	.pool
_0818811C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2B
	bl SetMonData
	b _081883B4
	.pool
_08188138:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
_08188146:
	movs r1, 0x2C
	bl SetMonData
	b _081883B4
	.pool
_08188154:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0
	bl SetMonData
	b _081883B4
	.pool
_08188170:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x9
	bl SetMonData
	b _081883B4
	.pool
_0818818C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x37
	bl SetMonData
	b _081883B4
	.pool
_081881A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x38
	bl SetMonData
	b _081883B4
	.pool
_081881C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x39
	bl SetMonData
	b _081883B4
	.pool
_081881E0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3A
	bl SetMonData
	b _081883B4
	.pool
_081881FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3B
	bl SetMonData
	b _081883B4
	.pool
_08188218:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3C
	bl SetMonData
	b _081883B4
	.pool
_08188234:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3D
	bl SetMonData
	b _081883B4
	.pool
_08188250:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3E
	bl SetMonData
	b _081883B4
	.pool
_0818826C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3F
	bl SetMonData
	b _081883B4
	.pool
_08188288:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x16
	bl SetMonData
	b _081883B4
	.pool
_081882A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x17
	bl SetMonData
	b _081883B4
	.pool
_081882C0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x18
	bl SetMonData
	b _081883B4
	.pool
_081882DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x21
	bl SetMonData
	b _081883B4
	.pool
_081882F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2F
	bl SetMonData
	b _081883B4
	.pool
_08188314:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x30
	bl SetMonData
	b _081883B4
	.pool
_08188330:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x32
	bl SetMonData
	b _081883B4
	.pool
_0818834C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x33
	bl SetMonData
	b _081883B4
	.pool
_08188368:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x34
	bl SetMonData
	b _081883B4
	.pool
_08188384:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x35
	bl SetMonData
	b _081883B4
	.pool
_081883A0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x36
	bl SetMonData
_081883B4:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_setattr_for_opponent_pokemon

	thumb_func_start sub_81883C8
sub_81883C8: @ 81883C8
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
	bcs _08188420
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_081883FE:
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
	bcc _081883FE
_08188420:
	bl RecordedOpponentBufferExecCompleted
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81883C8

	thumb_func_start sub_818843C
sub_818843C: @ 818843C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r7, =gBattlePartyID
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r1, 0x64
	mov r10, r1
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	ldr r1, =gEnemyParty
	mov r9, r1
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r1, [r6]
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	add r0, r9
	bl sub_805DC0C
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
	bl StartSpriteAnim
	ldrb r4, [r6]
	lsls r0, r4, 1
	adds r0, r7
	ldrh r0, [r0]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r0, r9
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
	ldr r1, =sub_8186C48
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818843C

	thumb_func_start sub_818858C
sub_818858C: @ 818858C
	push {r4,lr}
	ldr r1, =gBattlePartyID
	ldr r4, =gActiveBank
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
	bl sub_81885D8
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8187084
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818858C

	thumb_func_start sub_81885D8
sub_81885D8: @ 81885D8
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
	thumb_func_end sub_81885D8

	thumb_func_start sub_8188768
sub_8188768: @ 8188768
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _081887B0
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
	ldr r1, =sub_8188800
	str r1, [r0]
	b _081887EC
	.pool
_081887B0:
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
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl RecordedOpponentBufferExecCompleted
_081887EC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188768

	thumb_func_start sub_8188800
sub_8188800: @ 8188800
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
	beq _08188828
	cmp r0, 0x1
	beq _08188856
	b _0818887E
	.pool
_08188828:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08188842
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08188842:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0818887E
_08188856:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0818887E
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
	ldr r1, =sub_8186D9C
	str r1, [r0]
_0818887E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188800

	thumb_func_start sub_818888C
sub_818888C: @ 818888C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081888F6
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankIdentity
	movs r1, 0x2
	ands r1, r0
	movs r7, 0xC8
	cmp r1, 0
	beq _081888B4
	movs r7, 0x98
_081888B4:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _081888EC
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _081888D8
	ldr r0, =gTrainerBattleOpponent_A
	b _081888DA
	.pool
_081888D8:
	ldr r0, =gTrainerBattleOpponent_B
_081888DA:
	ldrh r0, [r0]
	bl sub_8162AA0
	lsls r0, 24
	lsrs r0, 24
	b _0818892C
	.pool
_081888EC:
	bl sub_8185F40
	lsls r0, 24
	lsrs r0, 24
	b _08188924
_081888F6:
	movs r7, 0xB0
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	cmp r1, r0
	bne _08188910
	bl sub_8068B48
	b _08188928
	.pool
_08188910:
	ldr r2, =gUnknown_020229E8
	ldr r0, =gUnknown_0203C7B4
	ldrb r0, [r0]
	movs r1, 0x1
	eors r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
_08188924:
	bl sub_806F000
_08188928:
	lsls r0, 16
	lsrs r0, 16
_0818892C:
	mov r8, r0
	ldr r5, =gActiveBank
	ldrb r1, [r5]
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
	ldr r1, =sub_8186558
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818888C

	thumb_func_start sub_8188A40
sub_8188A40: @ 8188A40
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188A40

	thumb_func_start sub_8188A4C
sub_8188A4C: @ 8188A4C
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
	ldr r1, =sub_81865C8
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188A4C

	thumb_func_start sub_8188AF8
sub_8188AF8: @ 8188AF8
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
	bne _08188B4C
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08188B2C
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08188B2C:
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
	b _08188B88
	.pool
_08188B4C:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08188B88
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
	ldr r1, =sub_8186D58
	str r1, [r0]
_08188B88:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188AF8

	thumb_func_start sub_8188BA4
sub_8188BA4: @ 8188BA4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188BA4

	thumb_func_start sub_8188BB0
sub_8188BB0: @ 8188BB0
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188BB0

	thumb_func_start sub_8188BBC
sub_8188BBC: @ 8188BBC
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188BBC

	thumb_func_start sub_8188BC8
sub_8188BC8: @ 8188BC8
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188BC8

	thumb_func_start sub_8188BD4
sub_8188BD4: @ 8188BD4
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _08188BE6
	b _08188CFA
_08188BE6:
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
	beq _08188CDC
	bl RecordedOpponentBufferExecCompleted
	b _08188CFA
	.pool
_08188CDC:
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
	ldr r1, =sub_8188D0C
	str r1, [r0]
_08188CFA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188BD4

	thumb_func_start sub_8188D0C
sub_8188D0C: @ 8188D0C
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
	beq _08188DA4
	cmp r2, 0x1
	bgt _08188D64
	cmp r2, 0
	beq _08188D6E
	b _08188E80
	.pool
_08188D64:
	cmp r2, 0x2
	beq _08188DCE
	cmp r2, 0x3
	beq _08188E44
	b _08188E80
_08188D6E:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _08188D90
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08188D90:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08188E80
_08188DA4:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08188E80
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
	b _08188E80
_08188DCE:
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _08188E80
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
	beq _08188E1C
	mov r0, r8
	cmp r0, 0x1
	bhi _08188E1C
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
_08188E1C:
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
	b _08188E80
	.pool
_08188E44:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08188E80
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
	bl RecordedOpponentBufferExecCompleted
_08188E80:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8188D0C

	thumb_func_start sub_8188E90
sub_8188E90: @ 8188E90
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
	bl BufferStringBattle
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8186E10
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188E90

	thumb_func_start sub_8188EE4
sub_8188EE4: @ 8188EE4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188EE4

	thumb_func_start sub_8188EF0
sub_8188EF0: @ 8188EF0
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl sub_8185054
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188EF0

	thumb_func_start sub_8188F14
sub_8188F14: @ 8188F14
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188F14

	thumb_func_start sub_8188F20
sub_8188F20: @ 8188F20
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _08188F48
	bl sub_805D19C
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	b _08188F6C
	.pool
_08188F48:
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl sub_8185054
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	bl sub_8185054
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 16
	orrs r2, r4
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
_08188F6C:
	bl RecordedOpponentBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188F20

	thumb_func_start sub_8188F7C
sub_8188F7C: @ 8188F7C
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188F7C

	thumb_func_start sub_8188F88
sub_8188F88: @ 8188F88
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_8185054
	ldrb r1, [r4]
	ldr r3, =gBattleStruct
	ldr r2, [r3]
	adds r1, r2
	adds r1, 0x5C
	strb r0, [r1]
	ldrb r0, [r4]
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0x5C
	ldrb r1, [r0]
	movs r0, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl RecordedOpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188F88

	thumb_func_start sub_8188FC4
sub_8188FC4: @ 8188FC4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8188FC4

	thumb_func_start sub_8188FD0
sub_8188FD0: @ 8188FD0
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
	beq _08189060
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
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_807294C
	b _0818908A
	.pool
_08189060:
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
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
_0818908A:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8186D04
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8188FD0

	thumb_func_start sub_81890C0
sub_81890C0: @ 81890C0
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81890C0

	thumb_func_start sub_81890CC
sub_81890CC: @ 81890CC
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08189120
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
	ldr r1, =sub_818714C
	str r1, [r0]
_08189120:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81890CC

	thumb_func_start sub_8189144
sub_8189144: @ 8189144
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08189194
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
	ldr r1, =sub_818714C
	str r1, [r0]
_08189194:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189144

	thumb_func_start sub_81891AC
sub_81891AC: @ 81891AC
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891AC

	thumb_func_start sub_81891B8
sub_81891B8: @ 81891B8
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891B8

	thumb_func_start sub_81891C4
sub_81891C4: @ 81891C4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891C4

	thumb_func_start sub_81891D0
sub_81891D0: @ 81891D0
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891D0

	thumb_func_start sub_81891DC
sub_81891DC: @ 81891DC
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891DC

	thumb_func_start sub_81891E8
sub_81891E8: @ 81891E8
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891E8

	thumb_func_start sub_81891F4
sub_81891F4: @ 81891F4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81891F4

	thumb_func_start sub_8189200
sub_8189200: @ 8189200
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8189200

	thumb_func_start sub_818920C
sub_818920C: @ 818920C
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_818920C

	thumb_func_start sub_8189218
sub_8189218: @ 8189218
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189218

	thumb_func_start sub_8189234
sub_8189234: @ 8189234
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
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189234

	thumb_func_start sub_818926C
sub_818926C: @ 818926C
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818926C

	thumb_func_start sub_8189284
sub_8189284: @ 8189284
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
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189284

	thumb_func_start sub_81892AC
sub_81892AC: @ 81892AC
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
	bge _081892E0
	bl RecordedOpponentBufferExecCompleted
	b _0818930A
	.pool
_081892E0:
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
	ldr r1, =bx_blink_t2
	str r1, [r0]
_0818930A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81892AC

	thumb_func_start sub_818931C
sub_818931C: @ 818931C
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_818931C

	thumb_func_start sub_8189328
sub_8189328: @ 8189328
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _0818933C
	movs r3, 0xC0
_0818933C:
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
	bl RecordedOpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189328

	thumb_func_start sub_818936C
sub_818936C: @ 818936C
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _081893A8
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
	b _081893BC
	.pool
_081893A8:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayFanfare
_081893BC:
	bl RecordedOpponentBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_818936C

	thumb_func_start sub_81893C8
sub_81893C8: @ 81893C8
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
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81893C8

	thumb_func_start sub_8189404
sub_8189404: @ 8189404
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
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189404

	thumb_func_start sub_8189438
sub_8189438: @ 8189438
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
	ldr r1, =sub_818962C
	bl StoreSpriteCallbackInData6
	ldr r0, =c3_0803D564
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
	beq _081894FA
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_081894FA:
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
	ldr r1, =nullsub_70
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189438

	thumb_func_start c3_0803D564
c3_0803D564: @ 8189548
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
	beq _08189582
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081895B4
_08189582:
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
	bl sub_81885D8
	b _081895F4
	.pool
_081895B4:
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
	bl sub_81885D8
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
	bl sub_81885D8
	ldrb r0, [r7]
	eors r0, r5
	strb r0, [r7]
_081895F4:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_818686C
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
	thumb_func_end c3_0803D564

	thumb_func_start sub_818962C
sub_818962C: @ 818962C
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
	thumb_func_end sub_818962C

	thumb_func_start sub_8189648
sub_8189648: @ 8189648
	push {r4-r7,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08189678
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08189678
	bl RecordedOpponentBufferExecCompleted
	b _08189742
	.pool
_08189678:
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
	beq _081896E4
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
	bhi _081896DC
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	lsls r0, 1
	movs r1, 0x1F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	b _08189742
	.pool
_081896DC:
	movs r0, 0x1F
	negs r0, r0
	ands r0, r2
	strb r0, [r3, 0x1]
_081896E4:
	adds r5, r7, 0
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
	beq _08189736
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_08189736:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_818975C
	str r0, [r1]
_08189742:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189648

	thumb_func_start sub_818975C
sub_818975C: @ 818975C
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
	bls _08189794
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl RecordedOpponentBufferExecCompleted
_08189794:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818975C

	thumb_func_start sub_81897A4
sub_81897A4: @ 81897A4
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
	beq _081897D6
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
_081897D6:
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81897A4

	thumb_func_start sub_81897F4
sub_81897F4: @ 81897F4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81897F4

	thumb_func_start sub_8189800
sub_8189800: @ 8189800
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _08189846
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
_08189846:
	bl RecordedOpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189800

	thumb_func_start sub_8189860
sub_8189860: @ 8189860
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _081898B8
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
	beq _081898AC
	bl RecordedOpponentBufferExecCompleted
	b _081898B8
	.pool
_081898AC:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_818717C
	str r0, [r1]
_081898B8:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8189860

	thumb_func_start sub_81898C8
sub_81898C8: @ 81898C8
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81898C8

	thumb_func_start sub_81898D4
sub_81898D4: @ 81898D4
	push {lr}
	bl RecordedOpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81898D4

	thumb_func_start sub_81898E0
sub_81898E0: @ 81898E0
	push {lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0x3
	bne _08189908
	ldr r0, =gBattleOutcome
	strb r2, [r0]
	b _08189910
	.pool
_08189908:
	ldr r0, =gBattleOutcome
	movs r1, 0x3
	eors r1, r2
	strb r1, [r0]
_08189910:
	movs r0, 0x5
	bl FadeOutMapMusic
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl RecordedOpponentBufferExecCompleted
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80587B0
	str r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81898E0

	thumb_func_start nullsub_119
nullsub_119: @ 8189944
	bx lr
	thumb_func_end nullsub_119

	.align 2, 0 @ Don't pad with nop.
