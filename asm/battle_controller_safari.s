	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

    
	thumb_func_start nullsub_114
nullsub_114: @ 8159368
	bx lr
	thumb_func_end nullsub_114

	thumb_func_start SetBankFuncToSafariBufferRunCommand
SetBankFuncToSafariBufferRunCommand: @ 815936C
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =SafariBufferRunCommand
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end SetBankFuncToSafariBufferRunCommand

	thumb_func_start SafariBufferRunCommand
SafariBufferRunCommand: @ 8159388
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
	beq _081593D4
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _081593D0
	ldr r0, =gSafariBufferCommands
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _081593D4
	.pool
_081593D0:
	bl SafariBufferExecCompleted
_081593D4:
	pop {r0}
	bx r0
	thumb_func_end SafariBufferRunCommand

	thumb_func_start bx_battle_menu_t6_2
bx_battle_menu_t6_2: @ 81593D8
	push {r4,r5,lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08159446
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08159424
	cmp r0, 0x1
	bgt _08159414
	cmp r0, 0
	beq _0815941E
	b _08159440
	.pool
_08159414:
	cmp r0, 0x2
	beq _0815942A
	cmp r0, 0x3
	beq _08159436
	b _08159440
_0815941E:
	movs r0, 0x1
	movs r1, 0x5
	b _0815942E
_08159424:
	movs r0, 0x1
	movs r1, 0x6
	b _0815942E
_0815942A:
	movs r0, 0x1
	movs r1, 0x7
_0815942E:
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08159440
_08159436:
	movs r0, 0x1
	movs r1, 0x8
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_08159440:
	bl SafariBufferExecCompleted
	b _0815954E
_08159446:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08159484
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0815954E
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
	b _081594F2
	.pool
_08159484:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081594C0
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0815954E
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
	b _081594F2
	.pool
_081594C0:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0815950C
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0815954E
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
_081594F2:
	eors r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	b _0815954E
	.pool
_0815950C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0815954E
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0815954E
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
	eors r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
_0815954E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_battle_menu_t6_2

	thumb_func_start sub_815955C
sub_815955C: @ 815955C
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
	bne _08159580
	bl SafariBufferExecCompleted
_08159580:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815955C

	thumb_func_start bx_t6_button_a
bx_t6_button_a: @ 8159594
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _081595A6
	bl SafariBufferExecCompleted
_081595A6:
	pop {r0}
	bx r0
	thumb_func_end bx_t6_button_a

	thumb_func_start sub_81595AC
sub_81595AC: @ 81595AC
	push {lr}
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
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081595D0
	bl SafariBufferExecCompleted
_081595D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81595AC

	thumb_func_start sub_81595E4
sub_81595E4: @ 81595E4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0815960E
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
_0815960E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81595E4

	thumb_func_start bx_wait_t6
bx_wait_t6: @ 8159624
	push {lr}
	ldr r0, =gDoingBattleAnim
	ldrb r0, [r0]
	cmp r0, 0
	beq _0815964A
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
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0815964E
_0815964A:
	bl SafariBufferExecCompleted
_0815964E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_wait_t6

	thumb_func_start sub_8159660
sub_8159660: @ 8159660
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08159684
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8159698
	str r1, [r0]
	bl FreeAllWindowBuffers
	bl sub_81358F4
_08159684:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159660

	thumb_func_start sub_8159698
sub_8159698: @ 8159698
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	bne _081596BE
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081596BE
	ldr r0, =gUnknown_0203CE7C
	ldrh r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl SafariBufferExecCompleted
_081596BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159698

	thumb_func_start sub_81596D4
sub_81596D4: @ 81596D4
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
	bne _081596F6
	bl SafariBufferExecCompleted
_081596F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81596D4

	thumb_func_start SafariBufferExecCompleted
SafariBufferExecCompleted: @ 8159704
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =SafariBufferRunCommand
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08159758
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
	b _0815976A
	.pool
_08159758:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0815976A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SafariBufferExecCompleted

	thumb_func_start bx_80364D0
bx_80364D0: @ 815977C
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
	bne _0815979E
	bl SafariBufferExecCompleted
_0815979E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_80364D0

	thumb_func_start sub_81597AC
sub_81597AC: @ 81597AC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597AC

	thumb_func_start sub_81597B8
sub_81597B8: @ 81597B8
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597B8

	thumb_func_start sub_81597C4
sub_81597C4: @ 81597C4
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597C4

	thumb_func_start sub_81597D0
sub_81597D0: @ 81597D0
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597D0

	thumb_func_start sub_81597DC
sub_81597DC: @ 81597DC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597DC

	thumb_func_start sub_81597E8
sub_81597E8: @ 81597E8
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597E8

	thumb_func_start sub_81597F4
sub_81597F4: @ 81597F4
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81597F4

	thumb_func_start sub_8159800
sub_8159800: @ 8159800
	push {r4-r6,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	bl sub_805DF84
	ldr r0, [r4]
	ldrb r6, [r0, 0x8]
	ldrb r0, [r5]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r2, =gUnknown_08305D2C
	ldr r1, [r4]
	ldrb r1, [r1, 0x8]
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1]
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
	ldr r1, =sub_815955C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159800

	thumb_func_start sub_81598E0
sub_81598E0: @ 81598E0
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81598E0

	thumb_func_start sub_81598EC
sub_81598EC: @ 81598EC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81598EC

	thumb_func_start sub_81598F8
sub_81598F8: @ 81598F8
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81598F8

	thumb_func_start sub_8159904
sub_8159904: @ 8159904
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159904

	thumb_func_start sub_8159910
sub_8159910: @ 8159910
	push {r4,r5,lr}
	ldr r0, =gUnknown_020244D0
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
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x4
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t6
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159910

	thumb_func_start sub_8159964
sub_8159964: @ 8159964
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strb r1, [r0, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x4
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t6
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159964

	thumb_func_start sub_81599C4
sub_81599C4: @ 81599C4
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81599C4

	thumb_func_start sub_81599D0
sub_81599D0: @ 81599D0
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_81599D0

	thumb_func_start dp01t_10_6_message
dp01t_10_6_message: @ 81599DC
	push {r4,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	ldr r1, =gBattleBufferA + 2
	adds r0, r1
	ldrh r0, [r0]
	bl BufferStringBattle
	ldr r0, =gDisplayedStringBattle
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t6_button_a
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_10_6_message

	thumb_func_start dp01t_11_6_message_for_player_only
dp01t_11_6_message_for_player_only: @ 8159A30
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08159A4C
	bl dp01t_10_6_message
	b _08159A50
	.pool
_08159A4C:
	bl SafariBufferExecCompleted
_08159A50:
	pop {r0}
	bx r0
	thumb_func_end dp01t_11_6_message_for_player_only

	thumb_func_start sub_8159A54
sub_8159A54: @ 8159A54
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08159A7A
	ldr r0, =gUnknown_02022E14
	strh r1, [r0]
	ldr r1, =gUnknown_02022E16
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_battle_menu_t6_2
	str r1, [r0]
_08159A7A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159A54

	thumb_func_start sub_8159A94
sub_8159A94: @ 8159A94
	push {r4,lr}
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8159A54
	str r1, [r0]
	ldr r0, =gUnknown_085CCA54
	movs r1, 0x2
	bl battle_show_message_maybe
	movs r4, 0
_08159AAE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8059CF8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08159AAE
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gUnknown_085CCA04
	bl StrCpyDecodeToDisplayedStringBattle
	ldr r0, =gDisplayedStringBattle
	movs r1, 0x1
	bl battle_show_message_maybe
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159A94

	thumb_func_start sub_8159AFC
sub_8159AFC: @ 8159AFC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159AFC

	thumb_func_start sub_8159B08
sub_8159B08: @ 8159B08
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159B08

	thumb_func_start sub_8159B14
sub_8159B14: @ 8159B14
	push {lr}
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
	ldr r1, =sub_8159660
	str r1, [r0]
	ldr r1, =gUnknown_020244B8
	ldrb r0, [r2]
	strb r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159B14

	thumb_func_start sub_8159B54
sub_8159B54: @ 8159B54
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159B54

	thumb_func_start sub_8159B60
sub_8159B60: @ 8159B60
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159B60

	thumb_func_start sub_8159B6C
sub_8159B6C: @ 8159B6C
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159B6C

	thumb_func_start sub_8159B78
sub_8159B78: @ 8159B78
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159B78

	thumb_func_start sub_8159B84
sub_8159B84: @ 8159B84
	push {lr}
	ldr r0, =gUnknown_03005D70
	ldr r1, =gActiveBank
	ldrb r1, [r1]
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
	movs r2, 0xB
	bl healthbar_draw_field_maybe
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159B84

	thumb_func_start sub_8159BC0
sub_8159BC0: @ 8159BC0
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159BC0

	thumb_func_start sub_8159BCC
sub_8159BCC: @ 8159BCC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159BCC

	thumb_func_start sub_8159BD8
sub_8159BD8: @ 8159BD8
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159BD8

	thumb_func_start sub_8159BE4
sub_8159BE4: @ 8159BE4
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159BE4

	thumb_func_start sub_8159BF0
sub_8159BF0: @ 8159BF0
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159BF0

	thumb_func_start sub_8159BFC
sub_8159BFC: @ 8159BFC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159BFC

	thumb_func_start sub_8159C08
sub_8159C08: @ 8159C08
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C08

	thumb_func_start sub_8159C14
sub_8159C14: @ 8159C14
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C14

	thumb_func_start sub_8159C20
sub_8159C20: @ 8159C20
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C20

	thumb_func_start sub_8159C2C
sub_8159C2C: @ 8159C2C
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C2C

	thumb_func_start sub_8159C38
sub_8159C38: @ 8159C38
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C38

	thumb_func_start sub_8159C44
sub_8159C44: @ 8159C44
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C44

	thumb_func_start sub_8159C50
sub_8159C50: @ 8159C50
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C50

	thumb_func_start sub_8159C5C
sub_8159C5C: @ 8159C5C
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C5C

	thumb_func_start sub_8159C68
sub_8159C68: @ 8159C68
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C68

	thumb_func_start sub_8159C74
sub_8159C74: @ 8159C74
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159C74

	thumb_func_start sub_8159C80
sub_8159C80: @ 8159C80
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _08159C94
	movs r3, 0xC0
_08159C94:
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
	bl SafariBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159C80

	thumb_func_start dp01t_34_6_move_anim_start_t3
dp01t_34_6_move_anim_start_t3: @ 8159CC4
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08159D00
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
	b _08159D14
	.pool
_08159D00:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayFanfare
_08159D14:
	bl SafariBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_34_6_move_anim_start_t3

	thumb_func_start sub_8159D20
sub_8159D20: @ 8159D20
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
	bl PlayCry1
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159D20

	thumb_func_start dp01t_2E_6_battle_intro
dp01t_2E_6_battle_intro: @ 8159D5C
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
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_6_battle_intro

	thumb_func_start sub_8159D90
sub_8159D90: @ 8159D90
	push {r4,r5,lr}
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
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0xA
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81595AC
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159D90

	thumb_func_start sub_8159DEC
sub_8159DEC: @ 8159DEC
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159DEC

	thumb_func_start sub_8159DF8
sub_8159DF8: @ 8159DF8
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159DF8

	thumb_func_start sub_8159E04
sub_8159E04: @ 8159E04
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159E04

	thumb_func_start sub_8159E10
sub_8159E10: @ 8159E10
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159E10

	thumb_func_start sub_8159E1C
sub_8159E1C: @ 8159E1C
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gBattleBufferA
	ldr r6, =gActiveBank
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
	beq _08159E5C
	bl SafariBufferExecCompleted
	b _08159E68
	.pool
_08159E5C:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_81596D4
	str r0, [r1]
_08159E68:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159E1C

	thumb_func_start sub_8159E78
sub_8159E78: @ 8159E78
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159E78

	thumb_func_start sub_8159E84
sub_8159E84: @ 8159E84
	push {lr}
	bl SafariBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8159E84

	thumb_func_start sub_8159E90
sub_8159E90: @ 8159E90
	push {r4,lr}
	ldr r2, =gBattleOutcome
	ldr r1, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0x5
	bl FadeOutMapMusic
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl SafariBufferExecCompleted
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x6
	ands r0, r1
	cmp r0, 0x2
	bne _08159ECC
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_81595E4
	str r0, [r1]
_08159ECC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159E90

	thumb_func_start nullsub_115
nullsub_115: @ 8159EEC
	bx lr
	thumb_func_end nullsub_115

    
   	.align 2, 0 @ Don't pad with nop.
