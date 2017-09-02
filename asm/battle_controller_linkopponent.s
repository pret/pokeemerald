	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

  	.text
        
     
	thumb_func_start nullsub_28
nullsub_28: @ 8064390
	bx lr
	thumb_func_end nullsub_28

	thumb_func_start SetBankFuncToLinkOpponentBufferRunCommand
SetBankFuncToLinkOpponentBufferRunCommand: @ 8064394
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80643B0
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end SetBankFuncToLinkOpponentBufferRunCommand

	thumb_func_start sub_80643B0
sub_80643B0: @ 80643B0
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
	beq _080643FC
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _080643F8
	ldr r0, =gUnknown_0831C7B4
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _080643FC
	.pool
_080643F8:
	bl sub_8065068
_080643FC:
	pop {r0}
	bx r0
	thumb_func_end sub_80643B0

	thumb_func_start sub_8064400
sub_8064400: @ 8064400
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
	bne _08064424
	bl sub_8065068
_08064424:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064400

	thumb_func_start sub_8064438
sub_8064438: @ 8064438
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
	bne _0806445C
	bl sub_8065068
_0806445C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064438

	thumb_func_start sub_8064470
sub_8064470: @ 8064470
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
	bne _080644C2
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
	bl sub_8065068
_080644C2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064470

	thumb_func_start sub_80644D8
sub_80644D8: @ 80644D8
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
	bne _08064510
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl sub_8065068
_08064510:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80644D8

	thumb_func_start sub_8064520
sub_8064520: @ 8064520
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	movs r4, 0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0806454C
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08064584
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064584
_0806454C:
	ldr r2, =gSprites
	ldr r1, =gUnknown_03005D70
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
	adds r7, r3, 0
	cmp r1, r0
	bne _080645C2
	b _080645CA
	.pool
_08064584:
	ldr r3, =gSprites
	ldr r6, =gUnknown_03005D70
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
	adds r7, r2, 0
	cmp r3, r0
	bne _080645C0
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
	bne _080645C0
	movs r1, 0x1
	mov r8, r1
_080645C0:
	movs r4, 0x1
_080645C2:
	mov r0, r8
	cmp r0, 0
	bne _080645CA
	b _08064714
_080645CA:
	cmp r4, 0
	bne _080645DE
	ldrb r1, [r7]
	movs r0, 0x2
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _0806469C
_080645DE:
	ldr r1, =gUnknown_020244D0
	mov r12, r1
	ldr r0, [r1]
	ldr r7, =gActiveBank
	ldrb r2, [r7]
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
	bne _08064600
	b _08064714
_08064600:
	movs r6, 0x2
	adds r1, r6, 0
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08064714
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r1, r12
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
	mov r0, r12
	ldr r2, [r0]
	ldrb r0, [r7]
	adds r1, r6, 0
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
	ldrb r0, [r7]
	adds r1, r6, 0
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
	b _080646F2
	.pool
_0806469C:
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
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
	beq _08064714
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
	ldrb r0, [r7]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080646F2
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
_080646F2:
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
	ldr r1, =sub_80644D8
	str r1, [r0]
_08064714:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064520

	thumb_func_start sub_8064734
sub_8064734: @ 8064734
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
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
	bne _08064776
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08064776:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080647B4
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
	bne _080647B4
	ldr r0, =gBattlePartyID
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
_080647B4:
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldr r2, =gActiveBank
	ldrb r5, [r2]
	ldr r4, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r6, r0, r4
	ldrb r1, [r6]
	movs r0, 0x8
	mov r12, r0
	ands r0, r1
	mov r8, r3
	mov r9, r2
	cmp r0, 0
	bne _08064898
	movs r7, 0x2
	adds r1, r7, 0
	eors r1, r5
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	bne _08064898
	ldrb r1, [r6, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0806487A
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0806484A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0806484A
	ldr r4, =gUnknown_03005D70
	mov r1, r9
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
	mov r1, r9
	ldrb r0, [r1]
	eors r0, r7
	bl sub_8076918
	mov r1, r9
	ldrb r0, [r1]
	eors r0, r7
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_0806484A:
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
_0806487A:
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r8, r4
	mov r9, r3
_08064898:
	mov r1, r8
	ldr r0, [r1]
	mov r1, r9
	ldrb r2, [r1]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	bne _0806495A
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
	bne _0806495A
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _0806495A
	mov r1, r8
	ldr r0, [r1]
	mov r1, r9
	ldrb r2, [r1]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0806493C
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _08064930
	adds r0, r2, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0806493C
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _0806493C
	.pool
_08064930:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_0806493C:
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
	mov r10, r0
_0806495A:
	mov r1, r10
	cmp r1, 0
	bne _08064962
	b _08064AC0
_08064962:
	ldr r2, =gSprites
	ldr r0, =gUnknown_03005D7C
	ldr r5, =gActiveBank
	ldrb r3, [r5]
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
	beq _08064982
	b _08064AC0
_08064982:
	ldr r0, =gBankSpriteIds
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	beq _08064998
	b _08064AC0
_08064998:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080649E2
	adds r0, r3, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080649E2
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x9]
	adds r0, 0x1
	strb r0, [r1, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08064AC0
	ldr r0, [r3]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
_080649E2:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08064A3A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08064A3A
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
_08064A3A:
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
	ldr r1, =sub_8064520
	str r1, [r0]
_08064AC0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064734

	thumb_func_start sub_8064B04
sub_8064B04: @ 8064B04
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
	bne _08064BB6
	adds r0, r2, r4
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08064BB6
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
	bne _08064B7C
	ldr r0, =gBattlePartyID
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
	b _08064BB6
	.pool
_08064B7C:
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08064BB6
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
	bl sub_8065068
_08064BB6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064B04

	thumb_func_start sub_8064BC0
sub_8064BC0: @ 8064BC0
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
	beq _08064C08
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _08064C0C
	.pool
_08064C08:
	bl sub_8065068
_08064C0C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8064BC0

	thumb_func_start sub_8064C14
sub_8064C14: @ 8064C14
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
	bne _08064C42
	ldr r0, =gUnknown_03005D70
	adds r0, r3, r0
	ldrb r0, [r0]
	bl sub_8072984
	bl sub_8065068
_08064C42:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064C14

	thumb_func_start sub_8064C58
sub_8064C58: @ 8064C58
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
	bne _08064CB2
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
	bl sub_8065068
_08064CB2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064C58

	thumb_func_start sub_8064CCC
sub_8064CCC: @ 8064CCC
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _08064CDE
	bl sub_8065068
_08064CDE:
	pop {r0}
	bx r0
	thumb_func_end sub_8064CCC

	thumb_func_start sub_8064CE4
sub_8064CE4: @ 8064CE4
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
	bne _08064D30
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
	bl sub_8065068
	b _08064D5A
	.pool
_08064D30:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08064D54
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
_08064D54:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_08064D5A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8064CE4

	thumb_func_start sub_8064D60
sub_8064D60: @ 8064D60
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
	bne _08064DAC
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08064DA0
	adds r0, r3, 0
	adds r1, r3, 0
	adds r2, r3, 0
	movs r3, 0x6
	bl move_anim_start_t4
_08064DA0:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8064DD0
	str r0, [r1]
_08064DAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064D60

	thumb_func_start sub_8064DD0
sub_8064DD0: @ 8064DD0
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
	bne _08064E2A
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _08064E2A
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
	beq _08064E1A
	ldr r0, =nullsub_18
	cmp r1, r0
	bne _08064E2A
_08064E1A:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	bl sub_8065068
_08064E2A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064DD0

	thumb_func_start sub_8064E50
sub_8064E50: @ 8064E50
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
	beq _08064F0C
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
	bne _08064F0C
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
	ldr r1, =sub_8064D60
	str r1, [r0]
_08064F0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064E50

	thumb_func_start sub_8064F40
sub_8064F40: @ 8064F40
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
	bne _08064F72
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08064F72:
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
	bne _08064FDC
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
	bne _08064FDC
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
	ldr r1, =sub_8064E50
	str r1, [r0]
_08064FDC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064F40

	thumb_func_start sub_8065008
sub_8065008: @ 8065008
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
	bne _0806502A
	bl sub_8065068
_0806502A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065008

	thumb_func_start sub_8065038
sub_8065038: @ 8065038
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
	bne _0806505A
	bl sub_8065068
_0806505A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065038

	thumb_func_start sub_8065068
sub_8065068: @ 8065068
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80643B0
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080650BC
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
	b _080650CE
	.pool
_080650BC:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_080650CE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065068

	thumb_func_start dp01t_00_2_getattr
dp01t_00_2_getattr: @ 80650E0
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
	bne _08065118
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl dp01_getattr_by_ch1_for_opponent_pokemon
	adds r6, r0, 0
	b _0806513A
	.pool
_08065118:
	ldrb r4, [r1]
	movs r5, 0
_0806511C:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08065132
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl dp01_getattr_by_ch1_for_opponent_pokemon
	adds r6, r0
_08065132:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806511C
_0806513A:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl sub_8065068
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_2_getattr

	thumb_func_start dp01_getattr_by_ch1_for_opponent_pokemon
dp01_getattr_by_ch1_for_opponent_pokemon: @ 8065154
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
	bls _0806517E
	bl _080658EA
_0806517E:
	lsls r0, 2
	ldr r1, =_08065194
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08065194:
	.4byte _08065284
	.4byte _080654A8
	.4byte _080654B8
	.4byte _080654C8
	.4byte _08065530
	.4byte _08065530
	.4byte _08065530
	.4byte _08065530
	.4byte _0806554C
	.4byte _08065588
	.4byte _08065588
	.4byte _08065588
	.4byte _08065588
	.4byte _080658EA
	.4byte _080658EA
	.4byte _080658EA
	.4byte _080658EA
	.4byte _080655A4
	.4byte _080655B4
	.4byte _080655E4
	.4byte _080655F4
	.4byte _08065604
	.4byte _08065614
	.4byte _08065624
	.4byte _08065634
	.4byte _08065644
	.4byte _08065654
	.4byte _08065664
	.4byte _08065674
	.4byte _08065684
	.4byte _08065694
	.4byte _080656A4
	.4byte _080656F4
	.4byte _08065704
	.4byte _08065714
	.4byte _08065724
	.4byte _08065734
	.4byte _08065744
	.4byte _08065754
	.4byte _08065764
	.4byte _08065774
	.4byte _080657A8
	.4byte _080657B8
	.4byte _080657C8
	.4byte _080657D8
	.4byte _080657E8
	.4byte _080657F8
	.4byte _08065808
	.4byte _08065818
	.4byte _08065838
	.4byte _08065848
	.4byte _08065858
	.4byte _08065868
	.4byte _08065878
	.4byte _08065888
	.4byte _08065898
	.4byte _080658A8
	.4byte _080658B8
	.4byte _080658C8
	.4byte _080658D8
_08065284:
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
_080652D0:
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
	ble _080652D0
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
_08065488:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _08065488
	b _080658EA
	.pool
_080654A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	b _08065822
	.pool
_080654B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	b _08065822
	.pool
_080654C8:
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
_080654DE:
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
	ble _080654DE
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
_0806551C:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _0806551C
	b _080658EA
	.pool
_08065530:
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
	b _08065822
	.pool
_0806554C:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gEnemyParty
	mov r8, r2
_08065558:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08065558
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _080658EA
	.pool
_08065588:
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
	b _080658E2
	.pool
_080655A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1
	b _080655BE
	.pool
_080655B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x19
_080655BE:
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
	b _080658EA
	.pool
_080655E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1A
	b _080658E2
	.pool
_080655F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1B
	b _080658E2
	.pool
_08065604:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1C
	b _080658E2
	.pool
_08065614:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1D
	b _080658E2
	.pool
_08065624:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1E
	b _080658E2
	.pool
_08065634:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1F
	b _080658E2
	.pool
_08065644:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x20
	b _080658E2
	.pool
_08065654:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x22
	b _080658E2
	.pool
_08065664:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x23
	b _080658E2
	.pool
_08065674:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x24
	b _080658E2
	.pool
_08065684:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x25
	b _080658E2
	.pool
_08065694:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	b _080658E2
	.pool
_080656A4:
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
	b _080658EA
	.pool
_080656F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x27
	b _080658E2
	.pool
_08065704:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x28
	b _080658E2
	.pool
_08065714:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x29
	b _080658E2
	.pool
_08065724:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2A
	b _080658E2
	.pool
_08065734:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2B
	b _080658E2
	.pool
_08065744:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	b _080658E2
	.pool
_08065754:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0
	b _0806577E
	.pool
_08065764:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x9
	b _08065822
	.pool
_08065774:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x37
_0806577E:
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
	b _080658EA
	.pool
_080657A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x38
	b _080658E2
	.pool
_080657B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	b _08065822
	.pool
_080657C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	b _08065822
	.pool
_080657D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3B
	b _08065822
	.pool
_080657E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3C
	b _08065822
	.pool
_080657F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3D
	b _08065822
	.pool
_08065808:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3E
	b _08065822
	.pool
_08065818:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3F
_08065822:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _080658EA
	.pool
_08065838:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x16
	b _080658E2
	.pool
_08065848:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x17
	b _080658E2
	.pool
_08065858:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x18
	b _080658E2
	.pool
_08065868:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x21
	b _080658E2
	.pool
_08065878:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2F
	b _080658E2
	.pool
_08065888:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x30
	b _080658E2
	.pool
_08065898:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x32
	b _080658E2
	.pool
_080658A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x33
	b _080658E2
	.pool
_080658B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x34
	b _080658E2
	.pool
_080658C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x35
	b _080658E2
	.pool
_080658D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x36
_080658E2:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_080658EA:
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
	thumb_func_end dp01_getattr_by_ch1_for_opponent_pokemon

	thumb_func_start sub_8065900
sub_8065900: @ 8065900
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8065900

	thumb_func_start sub_806590C
sub_806590C: @ 806590C
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806593C
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8065964
	b _0806595A
	.pool
_0806593C:
	ldrb r4, [r1]
	movs r5, 0
_08065940:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0806594E
	adds r0, r5, 0
	bl sub_8065964
_0806594E:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08065940
_0806595A:
	bl sub_8065068
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806590C

	thumb_func_start sub_8065964
sub_8065964: @ 8065964
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
	bls _08065992
	bl _08066270
_08065992:
	lsls r0, 2
	ldr r1, =_080659A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080659A8:
	.4byte _08065A98
	.4byte _08065C30
	.4byte _08065C4C
	.4byte _08065C68
	.4byte _08065CBC
	.4byte _08065CBC
	.4byte _08065CBC
	.4byte _08065CBC
	.4byte _08065CDC
	.4byte _08065D44
	.4byte _08065D44
	.4byte _08065D44
	.4byte _08065D44
	.4byte _08066270
	.4byte _08066270
	.4byte _08066270
	.4byte _08066270
	.4byte _08065D6C
	.4byte _08065D88
	.4byte _08065DA4
	.4byte _08065DC0
	.4byte _08065DDC
	.4byte _08065DF8
	.4byte _08065E14
	.4byte _08065E30
	.4byte _08065E4C
	.4byte _08065E68
	.4byte _08065E84
	.4byte _08065EA0
	.4byte _08065EBC
	.4byte _08065ED8
	.4byte _08065EF4
	.4byte _08065F68
	.4byte _08065F84
	.4byte _08065FA0
	.4byte _08065FBC
	.4byte _08065FD8
	.4byte _08065FF4
	.4byte _08066010
	.4byte _0806602C
	.4byte _08066048
	.4byte _08066064
	.4byte _08066080
	.4byte _0806609C
	.4byte _080660B8
	.4byte _080660D4
	.4byte _080660F0
	.4byte _0806610C
	.4byte _08066128
	.4byte _08066144
	.4byte _08066160
	.4byte _0806617C
	.4byte _08066198
	.4byte _080661B4
	.4byte _080661D0
	.4byte _080661EC
	.4byte _08066208
	.4byte _08066224
	.4byte _08066240
	.4byte _0806625C
_08065A98:
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
_08065AFE:
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
	ble _08065AFE
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
	b _08066270
	.pool
_08065C30:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xB
	bl SetMonData
	b _08066270
	.pool
_08065C4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xC
	bl SetMonData
	b _08066270
	.pool
_08065C68:
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
_08065C80:
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
	ble _08065C80
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _08066270
	.pool
_08065CBC:
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
	b _08065D5A
	.pool
_08065CDC:
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
	b _08066270
	.pool
_08065D44:
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
_08065D5A:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _08066270
	.pool
_08065D6C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1
	bl SetMonData
	b _08066270
	.pool
_08065D88:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x19
	bl SetMonData
	b _08066270
	.pool
_08065DA4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1A
	bl SetMonData
	b _08066270
	.pool
_08065DC0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1B
	bl SetMonData
	b _08066270
	.pool
_08065DDC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1C
	bl SetMonData
	b _08066270
	.pool
_08065DF8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1D
	bl SetMonData
	b _08066270
	.pool
_08065E14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1E
	bl SetMonData
	b _08066270
	.pool
_08065E30:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1F
	bl SetMonData
	b _08066270
	.pool
_08065E4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x20
	bl SetMonData
	b _08066270
	.pool
_08065E68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x22
	bl SetMonData
	b _08066270
	.pool
_08065E84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x23
	bl SetMonData
	b _08066270
	.pool
_08065EA0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x24
	bl SetMonData
	b _08066270
	.pool
_08065EBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x25
	bl SetMonData
	b _08066270
	.pool
_08065ED8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x26
	bl SetMonData
	b _08066270
	.pool
_08065EF4:
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
	b _08066002
	.pool
_08065F68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x27
	bl SetMonData
	b _08066270
	.pool
_08065F84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x28
	bl SetMonData
	b _08066270
	.pool
_08065FA0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x29
	bl SetMonData
	b _08066270
	.pool
_08065FBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2A
	bl SetMonData
	b _08066270
	.pool
_08065FD8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2B
	bl SetMonData
	b _08066270
	.pool
_08065FF4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
_08066002:
	movs r1, 0x2C
	bl SetMonData
	b _08066270
	.pool
_08066010:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0
	bl SetMonData
	b _08066270
	.pool
_0806602C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x9
	bl SetMonData
	b _08066270
	.pool
_08066048:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x37
	bl SetMonData
	b _08066270
	.pool
_08066064:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x38
	bl SetMonData
	b _08066270
	.pool
_08066080:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x39
	bl SetMonData
	b _08066270
	.pool
_0806609C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3A
	bl SetMonData
	b _08066270
	.pool
_080660B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3B
	bl SetMonData
	b _08066270
	.pool
_080660D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3C
	bl SetMonData
	b _08066270
	.pool
_080660F0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3D
	bl SetMonData
	b _08066270
	.pool
_0806610C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3E
	bl SetMonData
	b _08066270
	.pool
_08066128:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3F
	bl SetMonData
	b _08066270
	.pool
_08066144:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x16
	bl SetMonData
	b _08066270
	.pool
_08066160:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x17
	bl SetMonData
	b _08066270
	.pool
_0806617C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x18
	bl SetMonData
	b _08066270
	.pool
_08066198:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x21
	bl SetMonData
	b _08066270
	.pool
_080661B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2F
	bl SetMonData
	b _08066270
	.pool
_080661D0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x30
	bl SetMonData
	b _08066270
	.pool
_080661EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x32
	bl SetMonData
	b _08066270
	.pool
_08066208:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x33
	bl SetMonData
	b _08066270
	.pool
_08066224:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x34
	bl SetMonData
	b _08066270
	.pool
_08066240:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x35
	bl SetMonData
	b _08066270
	.pool
_0806625C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x36
	bl SetMonData
_08066270:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065964

	thumb_func_start sub_8066284
sub_8066284: @ 8066284
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
	bcs _080662DC
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_080662BA:
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
	bcc _080662BA
_080662DC:
	bl sub_8065068
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066284

	thumb_func_start sub_80662F8
sub_80662F8: @ 80662F8
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
	ldr r1, =sub_8064B04
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80662F8

	thumb_func_start sub_8066448
sub_8066448: @ 8066448
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
	bl sub_8066494
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064F40
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066448

	thumb_func_start sub_8066494
sub_8066494: @ 8066494
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
	thumb_func_end sub_8066494

	thumb_func_start sub_8066624
sub_8066624: @ 8066624
	push {r4-r6,lr}
	ldr r1, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _0806666C
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
	ldr r1, =sub_80666BC
	str r1, [r0]
	b _080666A8
	.pool
_0806666C:
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
	bl sub_8065068
_080666A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066624

	thumb_func_start sub_80666BC
sub_80666BC: @ 80666BC
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
	beq _080666E4
	cmp r0, 0x1
	beq _08066712
	b _0806673A
	.pool
_080666E4:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080666FE
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_080666FE:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0806673A
_08066712:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0806673A
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
	ldr r1, =sub_8064C58
	str r1, [r0]
_0806673A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80666BC

	thumb_func_start sub_8066748
sub_8066748: @ 8066748
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08066840
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r1, 0x2
	ands r1, r0
	movs r7, 0xC8
	cmp r1, 0
	beq _08066770
	movs r7, 0x98
_08066770:
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _080667A8
	ldrb r0, [r5]
	cmp r0, 0x1
	bne _08066794
	ldr r0, =gUnknown_02038BCA
	b _08066796
	.pool
_08066794:
	ldr r0, =gUnknown_02038BCC
_08066796:
	ldrh r0, [r0]
	bl sub_8162AA0
	lsls r0, 24
	lsrs r0, 24
	b _0806694C
	.pool
_080667A8:
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
	beq _080667D8
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
	bne _080667F4
_080667D8:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _080668AA
	b _080668BC
	.pool
_080667F4:
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
	beq _08066822
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _08066838
_08066822:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _08066916
	b _08066924
_08066838:
	ldrb r0, [r5]
	bl sub_806D864
	b _0806693A
_08066840:
	movs r7, 0xB0
	ldr r0, =gUnknown_02038BCA
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	cmp r1, r0
	bne _08066858
	bl sub_8068B48
	b _08066948
	.pool
_08066858:
	bl link_get_multiplayer_id
	ldr r6, =gUnknown_020229E8
	movs r5, 0x1
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _08066892
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _080668C8
_08066892:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _080668BC
_080668AA:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x4F
	ldrb r0, [r0]
	b _0806694C
	.pool
_080668BC:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x4E
	ldrb r0, [r0]
	b _0806694C
	.pool
_080668C8:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080668FE
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _08066930
_080668FE:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _08066924
_08066916:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x51
	ldrb r0, [r0]
	b _0806694C
	.pool
_08066924:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x50
	ldrb r0, [r0]
	b _0806694C
	.pool
_08066930:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
_0806693A:
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	bl sub_806F000
_08066948:
	lsls r0, 16
	lsrs r0, 16
_0806694C:
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
	ldr r1, =sub_8064400
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066748

	thumb_func_start sub_8066A58
sub_8066A58: @ 8066A58
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08066A74
	ldr r0, =gUnknown_02038BCA
	b _08066A76
	.pool
_08066A74:
	ldr r0, =gUnknown_02038BCC
_08066A76:
	ldrh r0, [r0]
	bl sub_8162AA0
	lsls r0, 24
	lsrs r0, 24
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
	ldr r1, =sub_8064438
	str r1, [r0]
	bl sub_8065068
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066A58

	thumb_func_start sub_8066B94
sub_8066B94: @ 8066B94
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
	bl oamt_set_x3A_32
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064470
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066B94

	thumb_func_start sub_8066C40
sub_8066C40: @ 8066C40
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
	bne _08066C94
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08066C74
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08066C74:
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
	b _08066CD0
	.pool
_08066C94:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08066CD0
	strb r0, [r3, 0x4]
	movs r0, 0x10
	movs r1, 0x3F
	bl audio_play_and_stuff
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
	ldr r1, =sub_8064C14
	str r1, [r0]
_08066CD0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066C40

	thumb_func_start sub_8066CEC
sub_8066CEC: @ 8066CEC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066CEC

	thumb_func_start sub_8066CF8
sub_8066CF8: @ 8066CF8
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066CF8

	thumb_func_start sub_8066D04
sub_8066D04: @ 8066D04
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066D04

	thumb_func_start sub_8066D10
sub_8066D10: @ 8066D10
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066D10

	thumb_func_start sub_8066D1C
sub_8066D1C: @ 8066D1C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _08066D32
	b _08066E58
_08066D32:
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
	beq _08066E30
	bl sub_8065068
	b _08066E58
	.pool
_08066E30:
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
	ldr r1, =sub_8066E70
	str r1, [r0]
	ldrh r1, [r4]
	ldr r2, [r7]
	adds r0, r6, 0
	bl sub_817E0FC
_08066E58:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066D1C

	thumb_func_start sub_8066E70
sub_8066E70: @ 8066E70
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
	beq _08066F08
	cmp r2, 0x1
	bgt _08066EC8
	cmp r2, 0
	beq _08066ED2
	b _08066FE4
	.pool
_08066EC8:
	cmp r2, 0x2
	beq _08066F32
	cmp r2, 0x3
	beq _08066FA8
	b _08066FE4
_08066ED2:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _08066EF4
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08066EF4:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08066FE4
_08066F08:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08066FE4
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
	b _08066FE4
_08066F32:
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _08066FE4
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
	beq _08066F80
	mov r0, r8
	cmp r0, 0x1
	bhi _08066F80
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
_08066F80:
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
	b _08066FE4
	.pool
_08066FA8:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08066FE4
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
	bl sub_8065068
_08066FE4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8066E70

	thumb_func_start sub_8066FF4
sub_8066FF4: @ 8066FF4
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
	ldr r1, =sub_8064CCC
	str r1, [r0]
	ldrh r0, [r4]
	bl sub_817C95C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066FF4

	thumb_func_start sub_806704C
sub_806704C: @ 806704C
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_806704C

	thumb_func_start sub_8067058
sub_8067058: @ 8067058
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067058

	thumb_func_start sub_8067064
sub_8067064: @ 8067064
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067064

	thumb_func_start sub_8067070
sub_8067070: @ 8067070
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067070

	thumb_func_start sub_806707C
sub_806707C: @ 806707C
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_806707C

	thumb_func_start sub_8067088
sub_8067088: @ 8067088
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067088

	thumb_func_start sub_8067094
sub_8067094: @ 8067094
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067094

	thumb_func_start sub_80670A0
sub_80670A0: @ 80670A0
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
	beq _08067130
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
	b _0806715A
	.pool
_08067130:
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
_0806715A:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064BC0
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80670A0

	thumb_func_start sub_8067190
sub_8067190: @ 8067190
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067190

	thumb_func_start sub_806719C
sub_806719C: @ 806719C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _080671F0
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
	ldr r1, =sub_8065008
	str r1, [r0]
_080671F0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806719C

	thumb_func_start sub_8067214
sub_8067214: @ 8067214
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08067264
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
	ldr r1, =sub_8065008
	str r1, [r0]
_08067264:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067214

	thumb_func_start sub_806727C
sub_806727C: @ 806727C
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_806727C

	thumb_func_start sub_8067288
sub_8067288: @ 8067288
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067288

	thumb_func_start sub_8067294
sub_8067294: @ 8067294
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067294

	thumb_func_start sub_80672A0
sub_80672A0: @ 80672A0
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672A0

	thumb_func_start sub_80672AC
sub_80672AC: @ 80672AC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672AC

	thumb_func_start sub_80672B8
sub_80672B8: @ 80672B8
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672B8

	thumb_func_start sub_80672C4
sub_80672C4: @ 80672C4
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672C4

	thumb_func_start sub_80672D0
sub_80672D0: @ 80672D0
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672D0

	thumb_func_start sub_80672DC
sub_80672DC: @ 80672DC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672DC

	thumb_func_start sub_80672E8
sub_80672E8: @ 80672E8
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80672E8

	thumb_func_start sub_8067304
sub_8067304: @ 8067304
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
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067304

	thumb_func_start sub_806733C
sub_806733C: @ 806733C
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806733C

	thumb_func_start sub_8067354
sub_8067354: @ 8067354
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
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067354

	thumb_func_start sub_806737C
sub_806737C: @ 806737C
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
	bge _080673B0
	bl sub_8065068
	b _080673DA
	.pool
_080673B0:
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
	ldr r1, =sub_8064CE4
	str r1, [r0]
_080673DA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806737C

	thumb_func_start sub_80673EC
sub_80673EC: @ 80673EC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80673EC

	thumb_func_start sub_80673F8
sub_80673F8: @ 80673F8
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _0806740C
	movs r3, 0xC0
_0806740C:
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
	bl sub_8065068
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80673F8

	thumb_func_start sub_806743C
sub_806743C: @ 806743C
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067478
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
	b _0806748C
	.pool
_08067478:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_0806748C:
	bl sub_8065068
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806743C

	thumb_func_start sub_8067498
sub_8067498: @ 8067498
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
	bl sub_80A32E4
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067498

	thumb_func_start sub_80674D4
sub_80674D4: @ 80674D4
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
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80674D4

	thumb_func_start sub_8067508
sub_8067508: @ 8067508
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
	ldr r1, =sub_80676FC
	bl oamt_set_x3A_32
	ldr r0, =c3_08038DC4
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
	beq _080675CA
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_080675CA:
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
	ldr r1, =nullsub_28
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067508

	thumb_func_start c3_08038DC4
c3_08038DC4: @ 8067618
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
	beq _08067652
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08067684
_08067652:
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
	bl sub_8066494
	b _080676C4
	.pool
_08067684:
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
	bl sub_8066494
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
	bl sub_8066494
	ldrb r0, [r7]
	eors r0, r5
	strb r0, [r7]
_080676C4:
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064734
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
	thumb_func_end c3_08038DC4

	thumb_func_start sub_80676FC
sub_80676FC: @ 80676FC
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
	thumb_func_end sub_80676FC

	thumb_func_start sub_8067718
sub_8067718: @ 8067718
	push {r4-r7,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067748
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08067748
	bl sub_8065068
	b _08067812
	.pool
_08067748:
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
	beq _080677B4
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
	bhi _080677AC
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	lsls r0, 1
	movs r1, 0x1F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	b _08067812
	.pool
_080677AC:
	movs r0, 0x1F
	negs r0, r0
	ands r0, r2
	strb r0, [r3, 0x1]
_080677B4:
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
	beq _08067806
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_08067806:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_806782C
	str r0, [r1]
_08067812:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067718

	thumb_func_start sub_806782C
sub_806782C: @ 806782C
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
	bls _08067864
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl sub_8065068
_08067864:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806782C

	thumb_func_start sub_8067874
sub_8067874: @ 8067874
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
	beq _080678A6
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
_080678A6:
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067874

	thumb_func_start sub_80678C4
sub_80678C4: @ 80678C4
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80678C4

	thumb_func_start sub_80678D0
sub_80678D0: @ 80678D0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _08067916
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
_08067916:
	bl sub_8065068
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80678D0

	thumb_func_start sub_8067930
sub_8067930: @ 8067930
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08067992
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
	beq _08067980
	bl sub_8065068
	b _0806798C
	.pool
_08067980:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8065038
	str r0, [r1]
_0806798C:
	adds r0, r6, 0
	bl sub_817E32C
_08067992:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067930

	thumb_func_start sub_80679A4
sub_80679A4: @ 80679A4
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r1, =gUnknown_02023066
	adds r0, r1
	bl sub_81851A8
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80679A4

	thumb_func_start sub_80679C4
sub_80679C4: @ 80679C4
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80679C4

	thumb_func_start sub_80679D0
sub_80679D0: @ 80679D0
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gUnknown_02023068
	adds r0, r4
	bl sub_81851A8
	ldrb r0, [r5]
	lsls r0, 9
	subs r4, 0x3
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0x3
	bne _08067A00
	ldr r0, =gBattleOutcome
	strb r2, [r0]
	b _08067A08
	.pool
_08067A00:
	ldr r0, =gBattleOutcome
	movs r1, 0x3
	eors r1, r2
	strb r1, [r0]
_08067A08:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, 0x2
	adds r0, r1
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
	bl sub_8065068
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80587B0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80679D0

	thumb_func_start nullsub_92
nullsub_92: @ 8067A70
	bx lr
	thumb_func_end nullsub_92

       
   	.align 2, 0 @ Don't pad with nop.
