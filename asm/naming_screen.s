	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start do_choose_name_or_words_screen
@ int do_choose_name_or_words_screen(u8 type, sav2 *sav2_ptr, s16 player_gender, s16 a4, int a5, void ( *after_finishing_callback)())
do_choose_name_or_words_screen: @ 80E2D78
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r2, 16
	lsrs r5, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	ldr r4, =gUnknown_02039F94
	movs r0, 0xF2
	lsls r0, 5
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _080E2DA8
	ldr r0, [sp, 0x1C]
	bl SetMainCallback2
	b _080E2DE2
	.pool
_080E2DA8:
	ldr r1, =0x00001e2c
	adds r0, r1
	strb r7, [r0]
	ldr r0, [r4]
	ldr r2, =0x00001e34
	adds r1, r0, r2
	strh r5, [r1]
	adds r2, 0x2
	adds r1, r0, r2
	strh r6, [r1]
	ldr r1, =0x00001e38
	adds r2, r0, r1
	ldr r1, [sp, 0x18]
	str r1, [r2]
	ldr r2, =0x00001e30
	adds r1, r0, r2
	mov r2, r8
	str r2, [r1]
	ldr r1, =0x00001e3c
	adds r0, r1
	ldr r2, [sp, 0x1C]
	str r2, [r0]
	cmp r7, 0
	bne _080E2DDC
	bl StartTimer1
_080E2DDC:
	ldr r0, =c2_choose_name_or_words_screen
	bl SetMainCallback2
_080E2DE2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end do_choose_name_or_words_screen

	thumb_func_start c2_choose_name_or_words_screen
c2_choose_name_or_words_screen: @ 80E2E04
	push {lr}
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x7
	bhi _080E2E9C
	lsls r0, 2
	ldr r1, =_080E2E28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E2E28:
	.4byte _080E2E48
	.4byte _080E2E52
	.4byte _080E2E58
	.4byte _080E2E5E
	.4byte _080E2E68
	.4byte _080E2E6E
	.4byte _080E2E74
	.4byte _080E2E7A
_080E2E48:
	bl sub_80E4F70
	bl choose_name_or_words_screen_setup
	b _080E2E86
_080E2E52:
	bl choose_name_or_words_screen_init_bgs
	b _080E2E86
_080E2E58:
	bl ResetPaletteFade
	b _080E2E86
_080E2E5E:
	bl ResetSpriteData
	bl ResetObjectPaletteAllocator
	b _080E2E86
_080E2E68:
	bl ResetTasks
	b _080E2E86
_080E2E6E:
	bl choose_name_or_words_screen_apply_bg_pals
	b _080E2E86
_080E2E74:
	bl choose_name_or_words_screen_load_bg_tile_patterns
	b _080E2E86
_080E2E7A:
	bl sub_80E3CC8
	bl UpdatePaletteFade
	bl sub_80E501C
_080E2E86:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080E2EA4
	.pool
_080E2E9C:
	bl sub_80E4CB8
	bl sub_80E3194
_080E2EA4:
	pop {r0}
	bx r0
	thumb_func_end c2_choose_name_or_words_screen

	thumb_func_start choose_name_or_words_screen_setup
@ void choose_name_or_words_screen_setup()
choose_name_or_words_screen_setup: @ 80E2EA8
	push {r4-r7,lr}
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r2, 0
	strb r2, [r0]
	ldr r1, [r5]
	ldr r3, =0x00001e18
	adds r0, r1, r3
	movs r4, 0
	strh r2, [r0]
	ldr r7, =0x00001e1a
	adds r0, r1, r7
	strh r2, [r0]
	ldr r0, =0x00001e1c
	adds r2, r1, r0
	movs r3, 0x1
	movs r0, 0x1
	strh r0, [r2]
	adds r7, 0x4
	adds r2, r1, r7
	movs r0, 0x2
	strh r0, [r2]
	movs r0, 0xF1
	lsls r0, 5
	adds r1, r0
	strb r4, [r1]
	ldr r0, [r5]
	ldr r1, =0x00001e21
	adds r0, r1
	strb r3, [r0]
	ldr r1, [r5]
	ldr r6, =0x00001e28
	adds r3, r1, r6
	ldr r2, =gUnknown_0858BFD8
	ldr r4, =0x00001e2c
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [r3]
	ldrb r0, [r0, 0x4]
	ldr r2, =0x00001e22
	adds r1, r2
	strb r0, [r1]
	ldr r2, [r5]
	adds r0, r2, r6
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 3
	movs r0, 0xF0
	subs r0, r1
	asrs r3, r0, 1
	adds r0, r3, 0x6
	subs r7, 0x8
	adds r1, r2, r7
	strh r0, [r1]
	adds r2, r4
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _080E2F2C
	adds r0, r3, 0
	adds r0, 0x11
	strh r0, [r1]
_080E2F2C:
	ldr r0, [r5]
	ldr r4, =gKeyRepeatStartDelay
	ldrh r1, [r4]
	ldr r2, =0x00001e25
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	movs r3, 0xC0
	lsls r3, 5
	adds r0, r3
	movs r1, 0xFF
	movs r2, 0x10
	bl memset
	ldr r1, [r5]
	adds r0, r1, r6
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E2F64
	movs r7, 0xC0
	lsls r7, 5
	adds r0, r1, r7
	ldr r2, =0x00001e30
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
_080E2F64:
	movs r0, 0x10
	strh r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end choose_name_or_words_screen_setup

	thumb_func_start sub_80E2FA4
sub_80E2FA4: @ 80E2FA4
	push {r4,r5,lr}
	movs r3, 0
	ldr r4, =gSprites
	movs r5, 0x5
	negs r5, r5
_080E2FAE:
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r0, r4
	adds r2, r0, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	lsls r0, r1, 31
	cmp r0, 0
	beq _080E2FC8
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
_080E2FC8:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3F
	bls _080E2FAE
	movs r0, 0
	bl sub_80E3E3C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2FA4

	thumb_func_start choose_name_or_words_screen_init_bgs
choose_name_or_words_screen_init_bgs: @ 80E2FE4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0xC
	mov r8, r0
	add r2, sp, 0x8
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_080E300A:
	strh r6, [r2]
	add r0, sp, 0x8
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _080E300A
	strh r6, [r2]
	add r2, sp, 0x8
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0xC]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	add r0, sp, 0x8
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0858BE00
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	bl sub_81971D0
	bl sub_8197200
_080E30D8:
	lsls r0, r4, 3
	ldr r1, =gUnknown_0858BE10
	adds r0, r1
	bl AddWindow
	ldr r5, =gUnknown_02039F94
	ldr r1, [r5]
	ldr r2, =0x00001e11
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _080E30D8
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r1, 0xC8
	lsls r1, 3
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000080c
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, [r5]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r5]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r5]
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	movs r0, 0x3
	bl SetBgTilemapBuffer
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end choose_name_or_words_screen_init_bgs

	thumb_func_start sub_80E3194
sub_80E3194: @ 80E3194
	push {lr}
	ldr r0, =sub_80E31B0
	movs r1, 0x2
	bl CreateTask
	ldr r0, =sub_80E4F58
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3194

	thumb_func_start sub_80E31B0
sub_80E31B0: @ 80E31B0
	push {lr}
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _080E3240
	lsls r0, 2
	ldr r1, =_080E31D8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E31D8:
	.4byte _080E3200
	.4byte _080E320E
	.4byte _080E3218
	.4byte _080E3214
	.4byte _080E321E
	.4byte _080E3224
	.4byte _080E322A
	.4byte _080E3230
	.4byte _080E3236
	.4byte _080E323C
_080E3200:
	bl sub_80E3294
	bl sub_80E2FA4
	bl sub_80E4F84
	b _080E3240
_080E320E:
	bl sub_80E335C
	b _080E3240
_080E3214:
	bl sub_80E33A8
_080E3218:
	bl sub_80E3398
	b _080E3240
_080E321E:
	bl sub_80E3640
	b _080E3240
_080E3224:
	bl sub_80E3680
	b _080E3240
_080E322A:
	bl pokemon_store
	b _080E3240
_080E3230:
	bl sub_80E3604
	b _080E3240
_080E3236:
	bl sub_80E3448
	b _080E3240
_080E323C:
	bl sub_80E347C
_080E3240:
	pop {r0}
	bx r0
	thumb_func_end sub_80E31B0

	thumb_func_start sub_80E3244
sub_80E3244: @ 80E3244
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0858BEBB
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80E3244

	thumb_func_start sub_80E3254
sub_80E3254: @ 80E3254
	ldr r1, =gUnknown_0858BEBE
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r2, =0x00001e22
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80E3254

	thumb_func_start sub_80E3274
sub_80E3274: @ 80E3274
	ldr r1, =gUnknown_0858BEC1
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r2, =0x00001e22
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80E3274

	thumb_func_start sub_80E3294
sub_80E3294: @ 80E3294
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_08DD4544
	movs r0, 0x3
	bl sub_80E4CF8
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r1, =0x00001e22
	adds r0, r1
	movs r6, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, =gUnknown_08DD46E0
	movs r0, 0x2
	bl sub_80E4CF8
	ldr r1, =gUnknown_08DD4620
	movs r0, 0x1
	bl sub_80E4CF8
	ldr r0, [r5]
	ldr r1, =0x00001e12
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80E4DE4
	ldr r0, [r5]
	ldr r1, =0x00001e11
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80E4DE4
	movs r0, 0x2
	movs r1, 0
	bl nullsub_10
	movs r0, 0x1
	movs r1, 0x1
	bl nullsub_10
	bl sub_80E4D10
	bl sub_80E4964
	bl sub_80E4EF0
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, [r5]
	ldr r0, =0x00001e10
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3294

	thumb_func_start sub_80E335C
sub_80E335C: @ 80E335C
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E3384
	movs r0, 0x1
	bl sub_80E4630
	movs r0, 0x1
	bl sub_80E3E94
	ldr r0, =gUnknown_02039F94
	ldr r1, [r0]
	ldr r0, =0x00001e10
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080E3384:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E335C

	thumb_func_start sub_80E3398
sub_80E3398: @ 80E3398
	push {lr}
	bl sub_80E44BC
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80E3398

	thumb_func_start sub_80E33A8
sub_80E33A8: @ 80E33A8
	push {lr}
	bl sub_80E3F04
	lsls r0, 24
	cmp r0, 0
	beq _080E33CA
	movs r0, 0x1
	bl sub_80E4630
	bl sub_80E3E28
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
_080E33CA:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E33A8

	thumb_func_start pokemon_store
pokemon_store: @ 80E33D8
	push {r4,lr}
	bl sub_80E4BE4
	movs r0, 0
	bl sub_80E4630
	movs r0, 0
	bl sub_80E3E94
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x1
	bl sub_80E3948
	ldr r4, =gUnknown_02039F94
	ldr r0, [r4]
	ldr r1, =0x00001e2c
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080E342C
	bl calc_player_party_count
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _080E342C
	bl pokemon_transfer_to_pc_with_message
	ldr r0, [r4]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x7
	strb r1, [r0]
	movs r0, 0
	b _080E343A
	.pool
_080E342C:
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
	movs r0, 0x1
_080E343A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pokemon_store

	thumb_func_start sub_80E3448
sub_80E3448: @ 80E3448
	push {lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_02039F94
	ldr r1, [r0]
	ldr r0, =0x00001e10
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3448

	thumb_func_start sub_80E347C
sub_80E347C: @ 80E347C
	push {r4,r5,lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _080E34C6
	ldr r4, =gUnknown_02039F94
	ldr r0, [r4]
	ldr r1, =0x00001e2c
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E34A0
	bl SeedRngAndSetTrainerId
_080E34A0:
	ldr r0, [r4]
	ldr r1, =0x00001e3c
	adds r0, r1
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, =sub_80E31B0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl FreeAllWindowBuffers
	ldr r0, [r4]
	bl Free
	str r5, [r4]
_080E34C6:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E347C

	thumb_func_start pokemon_transfer_to_pc_with_message
pokemon_transfer_to_pc_with_message: @ 80E34E4
	push {r4,r5,lr}
	sub sp, 0x10
	movs r5, 0
	bl sub_813B260
	lsls r0, 24
	cmp r0, 0
	bne _080E3534
	ldr r4, =gStringVar1
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	ldr r2, =0x00001e30
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	b _080E3574
	.pool
_080E3534:
	ldr r4, =gStringVar1
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	ldr r2, =0x00001e30
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r4, =gStringVar3
	bl get_unknown_box_id
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r5, 0x2
_080E3574:
	ldr r0, =0x000008ab
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080E3586
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E3586:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0858BDB8
	lsls r0, r5, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	bl sav2_get_text_speed
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemon_transfer_to_pc_with_message

	thumb_func_start sub_80E3604
sub_80E3604: @ 80E3604
	push {lr}
	bl RunTextPrinters
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080E362E
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080E362E
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
_080E362E:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3604

	thumb_func_start sub_80E3640
sub_80E3640: @ 80E3640
	push {lr}
	movs r0, 0
	bl sub_80E4630
	bl sub_80E4050
	bl sub_80E373C
	movs r0, 0x1
	bl sub_80E3E3C
	movs r0, 0
	movs r1, 0
	movs r2, 0x1
	bl sub_80E3948
	movs r0, 0x6
	bl audio_play
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3640

	thumb_func_start sub_80E3680
sub_80E3680: @ 80E3680
	push {r4-r6,lr}
	sub sp, 0x4
	bl sub_80E3794
	lsls r0, 24
	cmp r0, 0
	beq _080E3732
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80E3DFC
	bl sub_80E3F70
	movs r5, 0
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r0, 24
	lsrs r0, 24
	adds r6, r4, 0
	cmp r1, r0
	bne _080E36B2
	movs r5, 0x1
_080E36B2:
	ldr r2, =gUnknown_02039F94
	ldr r0, [r2]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r1, [r2]
	ldr r3, =0x00001e22
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r4, [r2]
	adds r4, r3
	ldrb r0, [r4]
	movs r1, 0x3
	bl __umodsi3
	strb r0, [r4]
	cmp r5, 0
	beq _080E36F4
	mov r4, sp
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	b _080E3712
	.pool
_080E36F4:
	mov r0, sp
	movs r2, 0
	ldrsh r4, [r0, r2]
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _080E3714
	mov r4, sp
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
_080E3712:
	strh r0, [r4]
_080E3714:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl sub_80E3D78
	bl sub_80E4E5C
	movs r0, 0x1
	bl sub_80E4630
	movs r0, 0
	bl sub_80E3E3C
_080E3732:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80E3680

	thumb_func_start sub_80E373C
sub_80E373C: @ 80E373C
	push {r4,lr}
	ldr r4, =sub_80E375C
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E373C

	thumb_func_start sub_80E375C
sub_80E375C: @ 80E375C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0858BEC4
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080E376E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080E376E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E375C

	thumb_func_start sub_80E3794
sub_80E3794: @ 80E3794
	push {lr}
	ldr r0, =sub_80E375C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080E37AC
	movs r0, 0
	b _080E37AE
	.pool
_080E37AC:
	movs r0, 0x1
_080E37AE:
	pop {r1}
	bx r1
	thumb_func_end sub_80E3794

	thumb_func_start sub_80E37B4
sub_80E37B4: @ 80E37B4
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	ldr r3, =0x00001e18
	adds r2, r1, r3
	movs r3, 0
	strh r3, [r2]
	ldr r2, =0x00001e1a
	adds r1, r2
	strh r3, [r1]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	movs r0, 0
	bx lr
	.pool
	thumb_func_end sub_80E37B4

	thumb_func_start sub_80E37DC
sub_80E37DC: @ 80E37DC
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r2, =0x00001e1a
	adds r1, r0, r2
	str r1, [sp]
	ldr r1, =0x00001e18
	adds r0, r1
	str r0, [sp, 0x4]
	ldrh r0, [r4, 0xA]
	adds r0, 0x4
	strh r0, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	movs r1, 0x28
	bl Sin
	ldr r1, [r5]
	movs r2, 0xF1
	lsls r2, 5
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	strh r0, [r1]
	ldrh r0, [r4, 0xA]
	adds r0, 0x80
	movs r1, 0xFF
	ands r0, r1
	movs r1, 0x28
	bl Sin
	ldr r1, [r5]
	ldr r2, =0x00001e21
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	strh r0, [r1]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x3F
	ble _080E3852
	ldr r0, [r5]
	ldr r1, =0x00001e1c
	adds r2, r0, r1
	ldrb r3, [r2]
	adds r1, 0x2
	adds r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	strh r3, [r0]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080E3852:
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E37DC

	thumb_func_start sub_80E3870
sub_80E3870: @ 80E3870
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r2, =0x00001e1a
	adds r1, r0, r2
	str r1, [sp]
	ldr r3, =0x00001e18
	adds r0, r3
	str r0, [sp, 0x4]
	ldrh r0, [r4, 0xA]
	adds r0, 0x4
	strh r0, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r1, 0x28
	bl Sin
	ldr r1, [r5]
	movs r2, 0xF1
	lsls r2, 5
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	strh r0, [r1]
	ldrh r0, [r4, 0xA]
	adds r0, 0x80
	movs r1, 0xFF
	ands r0, r1
	movs r1, 0x28
	bl Sin
	ldr r1, [r5]
	ldr r3, =0x00001e21
	adds r1, r3
	ldrb r1, [r1]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	strh r0, [r1]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _080E38EA
	ldr r0, [r5]
	movs r2, 0xF1
	lsls r2, 5
	adds r1, r0, r2
	ldrb r2, [r1]
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r3
	strb r2, [r0]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080E38EA:
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3870

	thumb_func_start sub_80E3904
sub_80E3904: @ 80E3904
	push {lr}
	ldr r0, =sub_80E375C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3904

	thumb_func_start sub_80E3920
sub_80E3920: @ 80E3920
	push {lr}
	ldr r0, =c3_0809E58C
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x3
	strh r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3920

	thumb_func_start sub_80E3948
sub_80E3948: @ 80E3948
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =c3_0809E58C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r5, r0
	bne _080E3988
	cmp r6, 0
	bne _080E3988
	strh r7, [r4, 0xA]
	movs r0, 0x1
	strh r0, [r4, 0xC]
	b _080E39B4
	.pool
_080E3988:
	cmp r5, 0x3
	bne _080E3998
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080E3998
	cmp r6, 0
	beq _080E39B4
_080E3998:
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	beq _080E39AA
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_80E3AE8
_080E39AA:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_80E3B10
_080E39B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E3948

	thumb_func_start c3_0809E58C
c3_0809E58C: @ 80E39BC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	beq _080E3A6E
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _080E3A6E
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_80E3A74
	lsls r0, 16
	lsrs r0, 16
	ldrb r3, [r4, 0xE]
	adds r1, r3, 0
	adds r2, r3, 0
	bl sub_80B609C
	ldrh r1, [r4, 0x12]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080E3A08
	subs r0, r1, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	cmp r0, 0
	bne _080E3A6E
_080E3A08:
	movs r0, 0x2
	strh r0, [r4, 0x12]
	ldrh r1, [r4, 0x10]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r0, 0
	blt _080E3A32
	ldrh r2, [r4, 0xE]
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	cmp r0, 0xD
	bgt _080E3A28
	adds r0, r2, r1
	b _080E3A36
	.pool
_080E3A28:
	movs r0, 0x10
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	b _080E3A3C
_080E3A32:
	ldrh r3, [r4, 0xE]
	adds r0, r1, r3
_080E3A36:
	strh r0, [r4, 0xE]
	ldrh r2, [r4, 0x14]
	adds r0, r1, r2
_080E3A3C:
	strh r0, [r4, 0x14]
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, 0xE]
	cmp r0, 0x10
	bne _080E3A5C
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0x16
	bne _080E3A5C
	ldr r0, =0x0000fffc
	strh r0, [r4, 0x10]
	b _080E3A6E
	.pool
_080E3A5C:
	lsls r0, r1, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _080E3A6E
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	movs r0, 0x2
	strh r0, [r4, 0x10]
	strh r1, [r4, 0x14]
_080E3A6E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end c3_0809E58C

	thumb_func_start sub_80E3A74
sub_80E3A74: @ 80E3A74
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x4
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x87
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	add r6, sp, 0x8
	strh r0, [r6]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	adds r0, r5
	mov r1, sp
	adds r1, 0xA
	strh r0, [r1]
	movs r0, 0x7
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	adds r0, r5
	add r1, sp, 0xC
	strh r0, [r1]
	movs r0, 0x7
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	ldr r1, =0x00000101
	adds r0, r1
	mov r1, sp
	adds r1, 0xE
	strh r0, [r1]
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x8
	bl memcpy
	lsls r4, 1
	mov r1, sp
	adds r0, r1, r4
	ldrh r0, [r0]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3A74

	thumb_func_start sub_80E3AE8
sub_80E3AE8: @ 80E3AE8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_80E3A74
	lsls r0, 16
	ldr r2, =gPlttBufferFaded
	lsrs r0, 15
	adds r2, r0, r2
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3AE8

	thumb_func_start sub_80E3B10
sub_80E3B10: @ 80E3B10
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	strh r1, [r0, 0x8]
	strh r2, [r0, 0xA]
	movs r1, 0x1
	strh r1, [r0, 0xC]
	movs r2, 0x4
	strh r2, [r0, 0xE]
	movs r1, 0x2
	strh r1, [r0, 0x10]
	strh r3, [r0, 0x12]
	strh r2, [r0, 0x14]
	bx lr
	thumb_func_end sub_80E3B10

	thumb_func_start sub_80E3B30
sub_80E3B30: @ 80E3B30
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080E3B48
	adds r0, r5, 0
	movs r1, 0
	bl StartObjectImageAnim
_080E3B48:
	ldrh r0, [r5, 0x36]
	movs r1, 0xFF
	ands r1, r0
	adds r6, r5, 0
	adds r6, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r6]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080E3B7C
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6]
_080E3B7C:
	ldrb r1, [r6]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080E3BAC
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _080E3BAC
	movs r2, 0x2E
	ldrsh r1, [r5, r2]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _080E3BAC
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _080E3BB6
_080E3BAC:
	movs r0, 0
	strh r0, [r5, 0x38]
	movs r0, 0x2
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x3C]
_080E3BB6:
	ldrh r0, [r5, 0x3C]
	subs r0, 0x1
	strh r0, [r5, 0x3C]
	lsls r0, 16
	cmp r0, 0
	bne _080E3BDE
	ldrh r1, [r5, 0x3A]
	ldrh r2, [r5, 0x38]
	adds r0, r1, r2
	strh r0, [r5, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	beq _080E3BD6
	cmp r0, 0
	bne _080E3BDA
_080E3BD6:
	negs r0, r1
	strh r0, [r5, 0x3A]
_080E3BDA:
	movs r0, 0x2
	strh r0, [r5, 0x3C]
_080E3BDE:
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _080E3C14
	ldrh r4, [r5, 0x38]
	lsls r5, r4, 24
	lsrs r5, 24
	lsls r4, 16
	asrs r4, 17
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r2, =0x01010000
	adds r0, r2
	lsrs r0, 16
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r5, 0
	bl sub_80B609C
_080E3C14:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3B30

	thumb_func_start sub_80E3C20
sub_80E3C20: @ 80E3C20
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0858BED4
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080E3C44
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _080E3C52
_080E3C44:
	movs r0, 0x8
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	strh r0, [r4, 0x30]
_080E3C52:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x24]
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3C20

	thumb_func_start sub_80E3C6C
sub_80E3C6C: @ 80E3C6C
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0858BEDC
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	bl sub_80E4A60
	lsls r0, 24
	ldrh r1, [r4, 0x2E]
	lsls r1, 24
	cmp r0, r1
	beq _080E3C98
	movs r0, 0
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x30]
	b _080E3CBE
	.pool
_080E3C98:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _080E3CC0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r0, 0
_080E3CBE:
	strh r0, [r4, 0x32]
_080E3CC0:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80E3C6C

	thumb_func_start sub_80E3CC8
sub_80E3CC8: @ 80E3CC8
	push {lr}
	bl sub_80E3CE4
	bl sub_80E3F8C
	bl sub_80E4218
	bl sub_80E4290
	bl sub_80E4354
	pop {r0}
	bx r0
	thumb_func_end sub_80E3CC8

	thumb_func_start sub_80E3CE4
sub_80E3CE4: @ 80E3CE4
	push {r4-r6,lr}
	ldr r0, =gUnknown_0858C138
	movs r1, 0x26
	movs r2, 0x58
	movs r3, 0x1
	bl CreateSprite
	ldr r5, =gUnknown_02039F94
	ldr r1, [r5]
	ldr r4, =0x00001e23
	adds r1, r4
	strb r0, [r1]
	movs r0, 0x1
	bl sub_80E3E3C
	ldr r6, =gSprites
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r3, [r1, 0x5]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x1]
	ands r2, r1
	orrs r2, r3
	strb r2, [r0, 0x1]
	ldr r2, [r5]
	adds r2, r4
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	strh r1, [r0, 0x3A]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	strh r1, [r0, 0x3A]
	movs r0, 0
	movs r1, 0
	bl sub_80E3D78
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3CE4

	thumb_func_start sub_80E3D78
sub_80E3D78: @ 80E3D78
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	ldr r2, =0x00001e23
	adds r1, r2
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gSprites
	adds r5, r1, r2
	lsrs r1, r0, 16
	mov r8, r1
	asrs r6, r0, 16
	ldr r4, =gUnknown_0858BEA0
	bl sub_80E3274
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	cmp r6, r0
	bge _080E3DD8
	bl sub_80E3274
	ldr r1, =gUnknown_0858BEA3
	lsls r0, 24
	lsrs r0, 21
	adds r0, r6, r0
	adds r0, r1
	ldrb r0, [r0]
	adds r0, 0x26
	b _080E3DDA
	.pool
_080E3DD8:
	movs r0, 0
_080E3DDA:
	strh r0, [r5, 0x20]
	lsls r0, r7, 16
	asrs r0, 12
	adds r0, 0x58
	strh r0, [r5, 0x22]
	ldrh r0, [r5, 0x2E]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x30]
	strh r0, [r5, 0x34]
	mov r2, r8
	strh r2, [r5, 0x2E]
	strh r7, [r5, 0x30]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E3D78

	thumb_func_start sub_80E3DFC
sub_80E3DFC: @ 80E3DFC
	ldr r2, =gUnknown_02039F94
	ldr r2, [r2]
	ldr r3, =0x00001e23
	adds r2, r3
	ldrb r3, [r2]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	ldr r3, =gSprites
	adds r2, r3
	ldrh r3, [r2, 0x2E]
	strh r3, [r0]
	ldrh r0, [r2, 0x30]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80E3DFC

	thumb_func_start sub_80E3E28
sub_80E3E28: @ 80E3E28
	push {lr}
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80E3D78
	pop {r0}
	bx r0
	thumb_func_end sub_80E3E28

	thumb_func_start sub_80E3E3C
sub_80E3E3C: @ 80E3E3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	ldr r1, =gUnknown_02039F94
	ldr r4, [r1]
	ldr r1, =0x00001e23
	adds r4, r1
	ldrb r1, [r4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r5
	ldrh r3, [r2, 0x36]
	ldr r1, =0xffffff00
	ands r1, r3
	strh r1, [r2, 0x36]
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	ldrh r2, [r1, 0x36]
	orrs r0, r2
	strh r0, [r1, 0x36]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0
	bl StartObjectImageAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3E3C

	thumb_func_start sub_80E3E94
sub_80E3E94: @ 80E3E94
	push {r4,r5,lr}
	lsls r0, 24
	ldr r5, =gSprites
	ldr r1, =gUnknown_02039F94
	ldr r4, [r1]
	ldr r1, =0x00001e23
	adds r4, r1
	ldrb r1, [r4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r5
	ldrh r3, [r2, 0x36]
	movs r1, 0xFF
	ands r1, r3
	strh r1, [r2, 0x36]
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsrs r0, 16
	ldrh r2, [r1, 0x36]
	orrs r0, r2
	strh r0, [r1, 0x36]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3E94

	thumb_func_start sub_80E3ED8
sub_80E3ED8: @ 80E3ED8
	push {lr}
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e23
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartObjectImageAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3ED8

	thumb_func_start sub_80E3F04
sub_80E3F04: @ 80E3F04
	ldr r2, =gSprites
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e23
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_80E3F04

	thumb_func_start sub_80E3F30
sub_80E3F30: @ 80E3F30
	push {r4,r5,lr}
	sub sp, 0x4
	mov r5, sp
	adds r5, 0x2
	mov r0, sp
	adds r1, r5, 0
	bl sub_80E3DFC
	mov r0, sp
	movs r1, 0
	ldrsh r4, [r0, r1]
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _080E3F64
	ldr r0, =gUnknown_0858BEE4
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r1, r0
	ldrb r0, [r1]
	b _080E3F66
	.pool
_080E3F64:
	movs r0, 0
_080E3F66:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E3F30

	thumb_func_start sub_80E3F70
sub_80E3F70: @ 80E3F70
	push {r4,lr}
	ldr r4, =gUnknown_0858BEA0
	bl sub_80E3274
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E3F70

	thumb_func_start sub_80E3F8C
sub_80E3F8C: @ 80E3F8C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0858C0C0
	movs r1, 0xCC
	movs r2, 0x58
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	ldr r2, =0x00001e24
	adds r1, r2
	strb r0, [r1]
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r0, =gSprites
	mov r8, r0
	add r5, r8
	ldr r1, =gUnknown_0858C050
	adds r0, r5, 0
	bl SetSpriteOamTables_NoPriorityFromTable
	adds r1, r5, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r6, 0x4
	orrs r0, r6
	strb r0, [r1]
	ldr r0, =gUnknown_0858C0F0
	movs r1, 0xCC
	movs r2, 0x54
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x3A]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	add r4, r8
	ldr r1, =gUnknown_0858C058
	adds r0, r4, 0
	bl SetSpriteOamTables_NoPriorityFromTable
	adds r4, 0x3E
	ldrb r0, [r4]
	orrs r0, r6
	strb r0, [r4]
	ldr r0, =gUnknown_0858C0D8
	movs r1, 0xCC
	movs r2, 0x53
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r8
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r6
	strb r1, [r2, 0x5]
	strh r0, [r5, 0x3C]
	adds r2, 0x3E
	ldrb r0, [r2]
	orrs r0, r6
	strb r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E3F8C

	thumb_func_start sub_80E4050
sub_80E4050: @ 80E4050
	ldr r0, =gUnknown_02039F94
	ldr r2, [r0]
	ldr r1, =0x00001e24
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	ldr r1, =0x00001e22
	adds r2, r1
	ldrb r1, [r2]
	strh r1, [r0, 0x30]
	bx lr
	.pool
	thumb_func_end sub_80E4050

	thumb_func_start sub_80E4084
sub_80E4084: @ 80E4084
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_0858BEE8
_080E408A:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080E408A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4084

	thumb_func_start sub_80E40AC
sub_80E40AC: @ 80E40AC
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r1, =gSprites
	adds r5, r1
	movs r2, 0x3C
	ldrsh r0, [r6, r2]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r4, r1
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e22
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80E3244
	lsls r0, 24
	lsrs r0, 24
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80E41B8
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E40AC

	thumb_func_start sub_80E4100
sub_80E4100: @ 80E4100
	movs r0, 0
	bx lr
	thumb_func_end sub_80E4100

	thumb_func_start sub_80E4104
sub_80E4104: @ 80E4104
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r0, 0x3A
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r2, =gSprites
	adds r4, r0, r2
	movs r0, 0x3C
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r0, r2
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080E4168
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	ldr r0, =0x0000fffc
	strh r0, [r4, 0x26]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r3, 0x30]
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	bl __modsi3
	lsls r0, 24
	lsrs r0, 24
	bl sub_80E3244
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80E41B8
_080E4168:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E4104

	thumb_func_start sub_80E4178
sub_80E4178: @ 80E4178
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x26]
	adds r0, 0x1
	strh r0, [r2, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _080E41AC
	movs r0, 0
	strh r0, [r2, 0x26]
	movs r0, 0x1
	strh r0, [r4, 0x2E]
_080E41AC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E4178

	thumb_func_start sub_80E41B8
sub_80E41B8: @ 80E41B8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0858BEF8
	lsls r4, r5, 1
	adds r0, r4, r0
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	mov r1, r8
	ldrb r2, [r1, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	mov r0, r8
	strb r1, [r0, 0x5]
	ldr r0, =gUnknown_0858BEFE
	adds r4, r0
	ldrh r0, [r4]
	bl GetSpriteTileStartByTag
	adds r1, r6, 0
	adds r1, 0x40
	strh r0, [r1]
	adds r6, 0x42
	movs r1, 0x3F
	ands r1, r5
	ldrb r2, [r6]
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E41B8

	thumb_func_start sub_80E4218
sub_80E4218: @ 80E4218
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_0858C108
	movs r1, 0xCC
	movs r2, 0x74
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r6, =gSprites
	adds r4, r6
	ldr r0, =gUnknown_0858C070
	mov r8, r0
	adds r0, r4, 0
	mov r1, r8
	bl SetSpriteOamTables_NoPriorityFromTable
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r5, 0x4
	orrs r0, r5
	strb r0, [r4]
	ldr r0, =gUnknown_0858C120
	movs r1, 0xCC
	movs r2, 0x8C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r4, r6
	adds r0, r4, 0
	mov r1, r8
	bl SetSpriteOamTables_NoPriorityFromTable
	adds r4, 0x3E
	ldrb r0, [r4]
	orrs r0, r5
	strb r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4218

	thumb_func_start sub_80E4290
sub_80E4290: @ 80E4290
	push {r4-r6,lr}
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r4, =0x00001e16
	adds r0, r4
	ldrh r1, [r0]
	subs r1, 0x5
	ldr r0, =gUnknown_0858C150
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x38
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r4, r0, r4
	ldrh r1, [r4]
	movs r5, 0
	ldr r2, =0x00001e28
	adds r0, r2
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r5, r0
	bcs _080E4334
	adds r6, r3, 0
_080E42E2:
	lsls r1, 16
	asrs r4, r1, 16
	movs r0, 0xC0
	lsls r0, 10
	adds r1, r0
	asrs r1, 16
	ldr r0, =gUnknown_0858C168
	movs r2, 0x3C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	strh r5, [r0, 0x2E]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x8
	lsls r4, 16
	lsrs r1, r4, 16
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r2, =0x00001e28
	adds r0, r2
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r5, r0
	bcc _080E42E2
_080E4334:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4290

	thumb_func_start sub_80E4354
sub_80E4354: @ 80E4354
	push {lr}
	ldr r1, =gUnknown_0858BF04
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r2, =0x00001e28
	adds r0, r2
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4354

	thumb_func_start TaskDummy2
TaskDummy2: @ 80E4380
	bx lr
	thumb_func_end TaskDummy2

	thumb_func_start sub_80E4384
sub_80E4384: @ 80E4384
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e34
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0
	bl sub_808BD3C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =SpriteCallbackDummy
	movs r2, 0
	str r2, [sp]
	movs r2, 0x38
	movs r3, 0x25
	bl AddPseudoFieldObject
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x4
	bl StartObjectImageAnim
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4384

	thumb_func_start sub_80E43E0
sub_80E43E0: @ 80E43E0
	push {r4,lr}
	ldr r0, =gUnknown_0858C180
	movs r1, 0x38
	movs r2, 0x29
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldr r1, =gUnknown_0858C078
	adds r0, r4, 0
	bl SetSpriteOamTables_NoPriorityFromTable
	ldrb r0, [r4, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r4, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E43E0

	thumb_func_start sub_80E4420
sub_80E4420: @ 80E4420
	push {lr}
	sub sp, 0xC
	bl sub_80D2F04
	ldr r0, =gUnknown_02039F94
	ldr r3, [r0]
	ldr r1, =0x00001e34
	adds r0, r3, r1
	ldrh r0, [r0]
	ldr r1, =SpriteCallbackDummy
	movs r2, 0
	str r2, [sp]
	ldr r2, =0x00001e38
	adds r3, r2
	ldr r2, [r3]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0x38
	movs r3, 0x28
	bl sub_80D2CC4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x5]
	movs r2, 0xC
	orrs r0, r2
	strb r0, [r1, 0x5]
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4420

	thumb_func_start sub_80E447C
sub_80E447C: @ 80E447C
	push {lr}
	sub sp, 0x4
	ldr r1, =SpriteCallbackDummy
	movs r0, 0
	str r0, [sp]
	movs r0, 0x13
	movs r2, 0x38
	movs r3, 0x25
	bl AddPseudoFieldObject
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x4
	bl StartObjectImageAnim
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E447C

	thumb_func_start sub_80E44BC
sub_80E44BC: @ 80E44BC
	push {r4,r5,lr}
	bl sub_80E460C
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl sub_80E3F30
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0x8
	bne _080E44DA
	bl sub_80E45E0
	b _080E44F6
_080E44DA:
	cmp r4, 0x6
	bne _080E44E4
	bl sub_80E4AF8
	b _080E4504
_080E44E4:
	cmp r5, 0x9
	beq _080E4500
	ldr r1, =gUnknown_0858BF18
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
_080E44F6:
	lsls r0, 24
	lsrs r0, 24
	b _080E4506
	.pool
_080E4500:
	bl sub_80E3E28
_080E4504:
	movs r0, 0
_080E4506:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E44BC

	thumb_func_start sub_80E450C
sub_80E450C: @ 80E450C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl sub_80E3948
	cmp r4, 0x5
	bne _080E4546
	bl sub_80E4B54
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80E3ED8
	cmp r4, 0
	beq _080E4546
	movs r0, 0x2
	bl sub_80E4630
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
_080E4546:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E450C

	thumb_func_start sub_80E4558
sub_80E4558: @ 80E4558
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_80E3948
	cmp r4, 0x5
	beq _080E4572
	movs r0, 0
	b _080E457A
_080E4572:
	bl sub_80E45E0
	lsls r0, 24
	lsrs r0, 24
_080E457A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80E4558

	thumb_func_start sub_80E4580
sub_80E4580: @ 80E4580
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_80E3948
	cmp r4, 0x5
	bne _080E459A
	bl sub_80E4AF8
_080E459A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80E4580

	thumb_func_start sub_80E45A4
sub_80E45A4: @ 80E45A4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl sub_80E3948
	cmp r4, 0x5
	beq _080E45BE
	movs r0, 0
	b _080E45D2
_080E45BE:
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x6
	strb r1, [r0]
	movs r0, 0x1
_080E45D2:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E45A4

	thumb_func_start sub_80E45E0
sub_80E45E0: @ 80E45E0
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r1, =0x00001e10
	adds r0, r1
	movs r1, 0x4
	strb r1, [r0]
	movs r0, 0x1
	bx lr
	.pool
	thumb_func_end sub_80E45E0

	thumb_func_start sub_80E45F8
sub_80E45F8: @ 80E45F8
	push {lr}
	ldr r0, =sub_80E465C
	movs r1, 0x1
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E45F8

	thumb_func_start sub_80E460C
sub_80E460C: @ 80E460C
	push {lr}
	ldr r0, =sub_80E465C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0xA]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E460C

	thumb_func_start sub_80E4630
sub_80E4630: @ 80E4630
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80E465C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4630

	thumb_func_start sub_80E465C
sub_80E465C: @ 80E465C
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0858BF28
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E465C

	thumb_func_start sub_80E468C
sub_80E468C: @ 80E468C
	movs r1, 0
	strh r1, [r0, 0xA]
	bx lr
	thumb_func_end sub_80E468C

	thumb_func_start sub_80E4692
sub_80E4692: @ 80E4692
	push {lr}
	adds r2, r0, 0
	movs r0, 0
	strh r0, [r2, 0xA]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080E46B4
	movs r0, 0x5
	strh r0, [r2, 0xA]
	b _080E46E4
	.pool
_080E46B4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080E46C2
	movs r0, 0x6
	strh r0, [r2, 0xA]
	b _080E46E4
_080E46C2:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080E46D0
	movs r0, 0x8
	strh r0, [r2, 0xA]
	b _080E46E4
_080E46D0:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080E46DE
	movs r0, 0x9
	strh r0, [r2, 0xA]
	b _080E46E4
_080E46DE:
	adds r0, r2, 0
	bl sub_80E46F0
_080E46E4:
	pop {r0}
	bx r0
	thumb_func_end sub_80E4692

	thumb_func_start sub_80E46E8
sub_80E46E8: @ 80E46E8
	movs r1, 0
	strh r1, [r0, 0xA]
	bx lr
	thumb_func_end sub_80E46E8

	thumb_func_start sub_80E46F0
sub_80E46F0: @ 80E46F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	mov r9, r0
	ldr r1, =gUnknown_0858BF34
	mov r0, sp
	movs r2, 0xA
	bl memcpy
	add r0, sp, 0xC
	mov r10, r0
	ldr r1, =gUnknown_0858BF3E
	movs r2, 0xA
	bl memcpy
	mov r1, sp
	adds r1, 0x18
	str r1, [sp, 0x2C]
	ldr r1, =gUnknown_0858BF48
	ldr r0, [sp, 0x2C]
	movs r2, 0x8
	bl memcpy
	mov r2, sp
	adds r2, 0x20
	str r2, [sp, 0x30]
	ldr r1, =gUnknown_0858BF50
	adds r0, r2, 0
	movs r2, 0x6
	bl memcpy
	add r4, sp, 0x28
	mov r5, sp
	adds r5, 0x2A
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80E3DFC
	ldr r0, =gMain
	ldrh r2, [r0, 0x30]
	movs r0, 0x40
	ands r0, r2
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	lsrs r1, r0, 31
	movs r0, 0x80
	ands r0, r2
	adds r6, r4, 0
	cmp r0, 0
	beq _080E475E
	movs r1, 0x2
_080E475E:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _080E4768
	movs r1, 0x3
_080E4768:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _080E4772
	movs r1, 0x4
_080E4772:
	ldrh r0, [r6]
	mov r8, r0
	lsls r1, 1
	mov r2, sp
	adds r7, r2, r1
	ldrh r0, [r7]
	add r0, r8
	strh r0, [r6]
	add r1, r10
	ldrh r0, [r1]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bge _080E479E
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6]
_080E479E:
	movs r0, 0
	ldrsh r4, [r6, r0]
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	ble _080E47B2
	movs r0, 0
	strh r0, [r6]
_080E47B2:
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _080E481E
	movs r2, 0
	ldrsh r4, [r6, r2]
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080E47F0
	ldrh r0, [r5]
	mov r1, r9
	strh r0, [r1, 0xC]
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 1
	ldr r1, [sp, 0x2C]
	adds r0, r1, r0
	b _080E481A
	.pool
_080E47F0:
	mov r2, r8
	lsls r4, r2, 16
	asrs r4, 16
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080E481E
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080E4810
	mov r2, r9
	ldrh r0, [r2, 0xC]
	b _080E481C
_080E4810:
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r0, 1
	ldr r2, [sp, 0x30]
	adds r0, r2, r0
_080E481A:
	ldrh r0, [r0]
_080E481C:
	strh r0, [r5]
_080E481E:
	movs r0, 0
	ldrsh r4, [r6, r0]
	bl sub_80E3F70
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080E4860
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _080E483A
	movs r0, 0x2
	strh r0, [r5]
_080E483A:
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	ble _080E4846
	movs r0, 0
	strh r0, [r5]
_080E4846:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080E4856
	movs r0, 0x1
	mov r2, r9
	strh r0, [r2, 0xC]
	b _080E4878
_080E4856:
	cmp r0, 0x2
	bne _080E4878
	mov r1, r9
	strh r0, [r1, 0xC]
	b _080E4878
_080E4860:
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bge _080E486C
	movs r0, 0x3
	strh r0, [r5]
_080E486C:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x3
	ble _080E4878
	movs r0, 0
	strh r0, [r5]
_080E4878:
	movs r2, 0
	ldrsh r0, [r6, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl sub_80E3D78
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E46F0

	thumb_func_start sub_80E4894
sub_80E4894: @ 80E4894
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r4, =0x00001e14
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =0x00001e28
	adds r1, r2
	ldr r1, [r1]
	ldr r2, [r1, 0x8]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4894

	thumb_func_start sub_80E48E8
sub_80E48E8: @ 80E48E8
	push {r4,r5,lr}
	sub sp, 0x2C
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r1, =0x00001e34
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	add r0, sp, 0xC
	bl StringCopy
	ldr r0, [r5]
	ldr r1, =0x00001e28
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	add r0, sp, 0xC
	movs r2, 0xF
	bl StringAppendN
	ldr r0, [r5]
	ldr r4, =0x00001e14
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x8
	bl Print
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	add sp, 0x2C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E48E8

	thumb_func_start sub_80E4964
sub_80E4964: @ 80E4964
	push {lr}
	ldr r1, =gUnknown_0858BF58
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r2, =0x00001e2c
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4964

	thumb_func_start sub_80E498C
sub_80E498C: @ 80E498C
	push {lr}
	ldr r1, =gUnknown_0858BF6C
	ldr r0, =gUnknown_02039F94
	ldr r0, [r0]
	ldr r2, =0x00001e28
	adds r0, r2
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E498C

	thumb_func_start TaskDummy3
TaskDummy3: @ 80E49B8
	bx lr
	thumb_func_end TaskDummy3

	thumb_func_start sub_80E49BC
sub_80E49BC: @ 80E49BC
	push {r4,r5,lr}
	sub sp, 0x10
	movs r4, 0
	ldr r1, =gUnknown_085E8D49
	add r0, sp, 0xC
	bl StringCopy
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r1, =0x00001e36
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0xFF
	beq _080E4A0C
	cmp r0, 0xFE
	bne _080E49E6
	ldr r1, =gUnknown_085E8D4B
	add r0, sp, 0xC
	bl StringCopy
	movs r4, 0x1
_080E49E6:
	ldr r0, [r5]
	ldr r1, =0x00001e13
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r4, 1
	adds r1, r4
	ldr r2, =gUnknown_0858BF74
	adds r1, r2
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0x68
	movs r3, 0x1
	bl box_print
_080E4A0C:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E49BC

	thumb_func_start sub_80E4A2C
sub_80E4A2C: @ 80E4A2C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =gUnknown_0858BE40
	bl sub_80E3274
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 13
	adds r4, r5
	lsls r0, 24
	lsrs r0, 19
	adds r4, r0
	adds r4, r6
	ldrb r0, [r4]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E4A2C

	thumb_func_start sub_80E4A60
sub_80E4A60: @ 80E4A60
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, =gUnknown_02039F94
	ldr r4, [r0]
	ldr r3, =0x00001e28
	adds r1, r4, r3
	ldr r1, [r1]
	ldrb r3, [r1, 0x1]
	adds r5, r0, 0
	cmp r2, r3
	bcs _080E4A9A
	movs r0, 0xC0
	lsls r0, 5
	adds r1, r4, r0
_080E4A7C:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080E4A90
	adds r0, r2, 0
	b _080E4AAA
	.pool
_080E4A90:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r3
	bcc _080E4A7C
_080E4A9A:
	ldr r0, [r5]
	ldr r1, =0x00001e28
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
_080E4AAA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E4A60

	thumb_func_start sub_80E4AB4
sub_80E4AB4: @ 80E4AB4
	push {lr}
	ldr r0, =gUnknown_02039F94
	ldr r2, [r0]
	ldr r1, =0x00001e28
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	subs r0, 0x1
	lsls r1, r0, 24
	cmp r1, 0
	ble _080E4AF0
	movs r0, 0xC0
	lsls r0, 5
	adds r3, r2, r0
_080E4AD0:
	asrs r2, r1, 24
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080E4AE8
	lsrs r0, r1, 24
	b _080E4AF2
	.pool
_080E4AE8:
	subs r0, r2, 0x1
	lsls r1, r0, 24
	cmp r1, 0
	bgt _080E4AD0
_080E4AF0:
	movs r0, 0
_080E4AF2:
	pop {r1}
	bx r1
	thumb_func_end sub_80E4AB4

	thumb_func_start sub_80E4AF8
sub_80E4AF8: @ 80E4AF8
	push {r4-r6,lr}
	bl sub_80E4AB4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gUnknown_02039F94
	ldr r0, [r6]
	movs r5, 0xC0
	lsls r5, 5
	adds r0, r5
	adds r0, r4
	movs r1, 0
	strb r1, [r0]
	bl sub_80E4D10
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
	bl sub_80E3F30
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080E4B38
	cmp r0, 0x2
	bne _080E4B42
_080E4B38:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	bl sub_80E3948
_080E4B42:
	movs r0, 0x17
	bl audio_play
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4AF8

	thumb_func_start sub_80E4B54
sub_80E4B54: @ 80E4B54
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80E3DFC
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl sub_80E4A2C
	lsls r0, 24
	lsrs r0, 24
	bl sub_80E4BBC
	bl sub_80E4D10
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x5
	bl audio_play
	bl sub_80E4AB4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	ldr r2, =0x00001e28
	adds r1, r2
	ldr r1, [r1]
	ldrb r1, [r1, 0x1]
	subs r1, 0x1
	cmp r0, r1
	bne _080E4BB0
	movs r0, 0x1
	b _080E4BB2
	.pool
_080E4BB0:
	movs r0, 0
_080E4BB2:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80E4B54

	thumb_func_start sub_80E4BBC
sub_80E4BBC: @ 80E4BBC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80E4A60
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F94
	ldr r1, [r1]
	movs r2, 0xC0
	lsls r2, 5
	adds r1, r2
	adds r1, r0
	strb r4, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4BBC

	thumb_func_start sub_80E4BE4
sub_80E4BE4: @ 80E4BE4
	push {r4,r5,lr}
	movs r2, 0
	ldr r1, =gUnknown_02039F94
	ldr r0, [r1]
	ldr r4, =0x00001e28
	adds r0, r4
	ldr r0, [r0]
	adds r5, r1, 0
	b _080E4C44
	.pool
_080E4C00:
	ldr r1, [r1]
	movs r0, 0xC0
	lsls r0, 5
	adds r3, r1, r0
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E4C34
	cmp r0, 0xFF
	beq _080E4C34
	ldr r2, =0x00001e30
	adds r0, r1, r2
	ldr r0, [r0]
	adds r1, r4
	ldr r1, [r1]
	ldrb r2, [r1, 0x1]
	adds r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	adds r1, r3, 0
	bl StringCopyN
	b _080E4C4A
	.pool
_080E4C34:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r1, r5, 0
	ldr r0, [r1]
	ldr r4, =0x00001e28
	adds r0, r4
	ldr r0, [r0]
_080E4C44:
	ldrb r0, [r0, 0x1]
	cmp r2, r0
	bcc _080E4C00
_080E4C4A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4BE4

	thumb_func_start choose_name_or_words_screen_load_bg_tile_patterns
choose_name_or_words_screen_load_bg_tile_patterns: @ 80E4C54
	push {r4-r6,lr}
	ldr r0, =gUnknown_08DD3838
	ldr r6, =gUnknown_02039F94
	ldr r1, [r6]
	ldr r4, =0x00001810
	adds r1, r4
	bl LZ77UnCompWram
	ldr r1, [r6]
	adds r1, r4
	movs r5, 0xC0
	lsls r5, 3
	movs r0, 0x1
	adds r2, r5, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r1, [r6]
	adds r1, r4
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r1, [r6]
	adds r1, r4
	movs r0, 0x3
	adds r2, r5, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_0858C1C8
	bl LoadObjectPics
	ldr r0, =gUnknown_0858C230
	bl LoadTaggedObjectPalettes
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end choose_name_or_words_screen_load_bg_tile_patterns

	thumb_func_start sub_80E4CB8
sub_80E4CB8: @ 80E4CB8
	push {lr}
	bl sub_80E45F8
	bl sub_80E3920
	pop {r0}
	bx r0
	thumb_func_end sub_80E4CB8

	thumb_func_start choose_name_or_words_screen_apply_bg_pals
choose_name_or_words_screen_apply_bg_pals: @ 80E4CC8
	push {lr}
	ldr r0, =gUnknown_08DD3778
	movs r1, 0
	movs r2, 0xC0
	bl LoadPalette
	ldr r0, =gUnknown_0858BD78
	movs r1, 0xA0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x2
	bl stdpal_get
	movs r1, 0xB0
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end choose_name_or_words_screen_apply_bg_pals

	thumb_func_start sub_80E4CF8
sub_80E4CF8: @ 80E4CF8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_80E4CF8

	thumb_func_start nullsub_10
nullsub_10: @ 80E4D0C
	bx lr
	thumb_func_end nullsub_10

	thumb_func_start sub_80E4D10
sub_80E4D10: @ 80E4D10
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r7, =gUnknown_02039F94
	ldr r1, [r7]
	ldr r2, =0x00001e28
	adds r0, r1, r2
	ldr r0, [r0]
	ldrb r6, [r0, 0x1]
	subs r2, 0x12
	adds r0, r1, r2
	ldrh r0, [r0]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r0, =0x00001e13
	adds r1, r0
	ldrb r0, [r1]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r4, 0
	cmp r4, r6
	bcs _080E4DA6
	add r5, sp, 0xC
	mov r10, r4
	ldr r0, =gExpandedPlaceholder_Empty
	ldrb r0, [r0]
	mov r8, r0
_080E4D52:
	ldr r0, [r7]
	movs r1, 0xC0
	lsls r1, 5
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r5]
	mov r2, r8
	strb r2, [r5, 0x1]
	ldrb r0, [r5]
	bl sub_80E503C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r0, 0x1
	bne _080E4D76
	movs r1, 0x2
_080E4D76:
	ldr r0, [r7]
	ldr r2, =0x00001e13
	adds r0, r2
	ldrb r0, [r0]
	lsls r3, r4, 3
	add r3, r9
	adds r3, r1
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	bl Print
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _080E4D52
_080E4DA6:
	bl sub_80E498C
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r4, =0x00001e13
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4D10

	thumb_func_start sub_80E4DE4
sub_80E4DE4: @ 80E4DE4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_0858BF88
	adds r0, r5, r0
	ldrb r1, [r0]
	adds r0, r6, 0
	bl FillWindowPixelBuffer
	movs r4, 0
	ldr r1, =gUnknown_0858BF8C
	lsls r0, r5, 2
	adds r0, r1
	ldr r7, [r0]
	ldr r0, =gUnknown_0858C198
	mov r8, r0
_080E4E0E:
	lsls r3, r4, 4
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	lsls r0, r4, 2
	lsls r1, r5, 4
	adds r0, r1
	add r0, r8
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	movs r2, 0
	bl box_print
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _080E4E0E
	adds r0, r6, 0
	bl PutWindowTilemap
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4DE4

	thumb_func_start sub_80E4E5C
sub_80E4E5C: @ 80E4E5C
	push {r4-r6,lr}
	movs r0, 0xA
	bl GetGpuReg
	adds r4, r0, 0
	movs r5, 0x3
	ands r4, r5
	movs r0, 0xC
	bl GetGpuReg
	ands r0, r5
	cmp r4, r0
	bls _080E4E8C
	movs r5, 0x1
	movs r6, 0x1
	ldr r1, =gUnknown_02039F94
	ldr r0, [r1]
	ldr r2, =0x00001e11
	b _080E4E96
	.pool
_080E4E8C:
	movs r5, 0x2
	movs r6, 0x2
	ldr r1, =gUnknown_02039F94
	ldr r0, [r1]
	ldr r2, =0x00001e12
_080E4E96:
	adds r0, r2
	ldrb r4, [r0]
	adds r0, r1, 0
	ldr r1, =gUnknown_0858BF98
	ldr r0, [r0]
	ldr r2, =0x00001e22
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_80E4CF8
	bl sub_80E3254
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80E4DE4
	bl sub_80E3254
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl nullsub_10
	adds r0, r6, 0
	bl CopyBgTilemapBufferToVram
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4E5C

	thumb_func_start sub_80E4EF0
sub_80E4EF0: @ 80E4EF0
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r1, =gUnknown_0858BFA4
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r4, =0x00001e15
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_085EEAF6
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl box_print
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4EF0

	thumb_func_start sub_80E4F58
sub_80E4F58: @ 80E4F58
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_80E4F58

	thumb_func_start sub_80E4F70
sub_80E4F70: @ 80E4F70
	push {lr}
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	pop {r0}
	bx r0
	thumb_func_end sub_80E4F70

	thumb_func_start sub_80E4F84
sub_80E4F84: @ 80E4F84
	push {lr}
	ldr r0, =sub_80E4F94
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4F84

	thumb_func_start sub_80E4F94
sub_80E4F94: @ 80E4F94
	push {r4,r5,lr}
	bl LoadOamFromSprites
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	ldr r5, =gUnknown_02039F94
	ldr r0, [r5]
	ldr r1, =0x00001e18
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, [r5]
	ldr r1, =0x00001e1a
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	movs r0, 0xA
	bl GetGpuReg
	ldr r4, =0x0000fffc
	adds r1, r4, 0
	ands r1, r0
	movs r0, 0xA
	bl SetGpuReg
	ldr r0, [r5]
	ldr r1, =0x00001e1c
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xA
	bl SetGpuRegBits
	movs r0, 0xC
	bl GetGpuReg
	ands r4, r0
	movs r0, 0xC
	adds r1, r4, 0
	bl SetGpuReg
	ldr r0, [r5]
	ldr r1, =0x00001e1e
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xC
	bl SetGpuRegBits
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E4F94

	thumb_func_start sub_80E501C
sub_80E501C: @ 80E501C
	push {lr}
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	pop {r0}
	bx r0
	thumb_func_end sub_80E501C

	thumb_func_start sub_80E503C
sub_80E503C: @ 80E503C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r2, 0
	ldr r0, =gUnknown_0858BDC8
	ldrb r1, [r0]
	adds r3, r0, 0
	cmp r1, 0xFF
	beq _080E5066
	adds r1, r3, 0
_080E5050:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r4, r0
	beq _080E5066
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080E5050
_080E5066:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E503C

	thumb_func_start sub_80E5074
sub_80E5074: @ 80E5074
	push {lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_8086194
	str r0, [sp, 0x4]
	movs r0, 0
	movs r3, 0
	bl do_choose_name_or_words_screen
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E5074

	thumb_func_start sub_80E509C
sub_80E509C: @ 80E509C
	push {lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_8086194
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r3, 0
	bl do_choose_name_or_words_screen
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E509C

	thumb_func_start sub_80E50C4
sub_80E50C4: @ 80E50C4
	push {lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_8086194
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r3, 0
	bl do_choose_name_or_words_screen
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E50C4

	thumb_func_start sub_80E50EC
sub_80E50EC: @ 80E50EC
	push {lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_8086194
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl do_choose_name_or_words_screen
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E50EC

	.align 2, 0 @ Don't pad with nop.
