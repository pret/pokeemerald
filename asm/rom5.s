	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_35
nullsub_35: @ 80A92F4
	bx lr
	thumb_func_end nullsub_35

	thumb_func_start sub_80A92F8
sub_80A92F8: @ 80A92F8
	push {lr}
	ldr r2, =gUnknown_02037FD4
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_02024474
	adds r2, r0, 0
	adds r2, 0x21
	movs r1, 0
	strb r1, [r2]
	adds r0, 0x22
	strb r1, [r0]
	ldr r0, =c2_80777E8
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A92F8

	thumb_func_start c2_80777E8
c2_80777E8: @ 80A933C
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_02024474
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x13
	bls _080A934C
	b _080A95A4
_080A934C:
	lsls r0, 2
	ldr r1, =_080A9360
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080A9360:
	.4byte _080A93B0
	.4byte _080A942C
	.4byte _080A9444
	.4byte _080A944A
	.4byte _080A9450
	.4byte _080A9460
	.4byte _080A9466
	.4byte _080A948E
	.4byte _080A9492
	.4byte _080A9496
	.4byte _080A949A
	.4byte _080A94B8
	.4byte _080A94C0
	.4byte _080A94C8
	.4byte _080A94D0
	.4byte _080A94D8
	.4byte _080A94E0
	.4byte _080A94E8
	.4byte _080A94F0
	.4byte _080A94F8
_080A93B0:
	bl dp12_8087EA4
	bl trs_config
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl sub_80A1A74
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r0, =gUnknown_02022E18
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r1, [r0]
	ldr r0, =gUnknown_02022E20
	strh r1, [r0]
	ldr r0, =gUnknown_02022E22
	strh r1, [r0]
	b _080A95D2
	.pool
_080A942C:
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x01006000
	add r0, sp, 0x4
	bl CpuFastSet
	b _080A95D2
	.pool
_080A9444:
	bl sub_8035AA4
	b _080A95D2
_080A944A:
	bl ResetAllObjectData
	b _080A95D2
_080A9450:
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x4
	strb r0, [r1]
	b _080A95D2
	.pool
_080A9460:
	bl sub_805E350
	b _080A95D2
_080A9466:
	ldr r5, =gUnknown_02024474
	adds r4, r5, 0
	adds r4, 0x22
	ldrb r0, [r4]
	bl sub_805E08C
	lsls r0, 24
	cmp r0, 0
	beq _080A9484
	movs r0, 0
	strb r0, [r4]
	b _080A95D2
	.pool
_080A9484:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	adds r1, r5, 0
	b _080A94AA
_080A948E:
	movs r0, 0
	b _080A949C
_080A9492:
	movs r0, 0x1
	b _080A949C
_080A9496:
	movs r0, 0x2
	b _080A949C
_080A949A:
	movs r0, 0x3
_080A949C:
	bl sub_80A9614
	lsls r0, 24
	cmp r0, 0
	beq _080A94A8
	b _080A95D2
_080A94A8:
	ldr r1, =gUnknown_02024474
_080A94AA:
	adds r1, 0x21
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	b _080A95D2
	.pool
_080A94B8:
	movs r0, 0
	bl sub_80A9708
	b _080A95D2
_080A94C0:
	movs r0, 0x1
	bl sub_80A9708
	b _080A95D2
_080A94C8:
	movs r0, 0x2
	bl sub_80A9708
	b _080A95D2
_080A94D0:
	movs r0, 0x3
	bl sub_80A9708
	b _080A95D2
_080A94D8:
	movs r0, 0
	bl sub_80A9ADC
	b _080A95D2
_080A94E0:
	movs r0, 0x1
	bl sub_80A9ADC
	b _080A95D2
_080A94E8:
	movs r0, 0x2
	bl sub_80A9ADC
	b _080A95D2
_080A94F0:
	movs r0, 0x3
	bl sub_80A9ADC
	b _080A95D2
_080A94F8:
	bl sub_805EC84
	movs r0, 0x1
	bl battle_get_side_with_given_state
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r7, =gUnknown_0202406E
	lsls r0, r4, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gUnknown_02024744
	adds r0, r5
	movs r1, 0xB
	bl pokemon_getattr
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080A955C
	movs r0, 0x3
	bl battle_get_side_with_given_state
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl pokemon_getattr
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
_080A955C:
	ldr r1, =gUnknown_020244AC
	ldr r0, =gUnknown_020244B8
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A95D2
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A95D2
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _080A95D2
	.pool
_080A95A4:
	ldr r0, =vblank_cb_08078BB4
	bl SetVBlankCallback
	bl sub_80A95F4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A27B0
	ldr r2, =gUnknown_02037FD4
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =sub_8038420
	bl SetMainCallback2
	bl sub_805EF14
_080A95D2:
	ldr r1, =gUnknown_02024474
	adds r1, 0x21
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_80777E8

	thumb_func_start sub_80A95F4
sub_80A95F4: @ 80A95F4
	ldr r3, =0x0400000a
	ldrb r2, [r3]
	movs r1, 0xD
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	ldr r2, =0x0400000c
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_80A95F4

	thumb_func_start sub_80A9614
sub_80A9614: @ 80A9614
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0202406C
	ldrb r0, [r0]
	cmp r4, r0
	bcs _080A96FC
	adds r0, r4, 0
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	beq _080A9676
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A966C
	ldr r1, =gUnknown_0202406E
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_02024744
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DC0C
	b _080A96F4
	.pool
_080A966C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_805E7DC
	b _080A96F4
_080A9676:
	ldr r0, =gUnknown_02022FEC
	ldr r1, [r0]
	movs r2, 0x80
	ands r1, r2
	cmp r1, 0
	beq _080A9698
	cmp r4, 0
	bne _080A9698
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	b _080A96AA
	.pool
_080A9698:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080A96B2
	cmp r4, 0
	bne _080A96B2
	movs r0, 0x6
_080A96AA:
	movs r1, 0
	bl sub_805DF84
	b _080A96F4
_080A96B2:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A96EC
	ldr r1, =gUnknown_0202406E
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_020244EC
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DD7C
	b _080A96F4
	.pool
_080A96EC:
	adds r0, r4, 0
	movs r1, 0
	bl sub_805E7DC
_080A96F4:
	ldr r0, =gUnknown_02024474
	adds r0, 0x22
	movs r1, 0
	strb r1, [r0]
_080A96FC:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A9614

	thumb_func_start sub_80A9708
sub_80A9708: @ 80A9708
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0202406C
	ldrb r0, [r0]
	cmp r7, r0
	bcc _080A9722
	b _080A9AA0
_080A9722:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r2, r7, 2
	adds r0, r2, r0
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	str r2, [sp]
	cmp r0, 0
	beq _080A9748
	adds r0, r7, 0
	bl sub_80A614C
	b _080A974E
	.pool
_080A9748:
	adds r0, r7, 0
	bl sub_80A6138
_080A974E:
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r7, 0
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _080A9762
	b _080A986C
_080A9762:
	ldr r1, =gUnknown_0202406E
	lsls r0, r7, 1
	adds r6, r0, r1
	ldrh r0, [r6]
	movs r1, 0x64
	mov r10, r1
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	ldr r1, =gUnknown_02024744
	mov r9, r1
	add r0, r9
	movs r1, 0x39
	bl pokemon_getattr
	cmp r0, 0
	bne _080A9786
	b _080A9AA0
_080A9786:
	ldrh r0, [r6]
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	add r0, r9
	movs r1, 0xB
	bl pokemon_getattr
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806A068
	ldr r5, =gUnknown_0202499C
	adds r0, r7, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl AddObjectToFront
	ldr r1, =gUnknown_020241E4
	adds r4, r7, r1
	strb r0, [r4]
	ldr r5, =gUnknown_02020630
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r7, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r7, [r0, 0x2E]
	ldrh r0, [r6]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r0, r9
	movs r1, 0xB
	bl pokemon_getattr
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	strh r0, [r1, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r1, r7, r1
	ldrb r1, [r1]
	bl StartObjectImageAnim
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r2, [sp]
	adds r0, r2, r0
	b _080A9A50
	.pool
_080A986C:
	ldr r0, =gUnknown_02022FEC
	ldr r1, [r0]
	movs r2, 0x80
	ands r1, r2
	cmp r1, 0
	beq _080A98D0
	cmp r7, 0
	bne _080A98D0
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldrb r4, [r0, 0x8]
	movs r0, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	ldr r1, =gUnknown_08305D2C
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r0, 0xA0
	lsls r0, 15
	adds r4, r0
	asrs r4, 16
	movs r0, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	b _080A9914
	.pool
_080A98D0:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080A9968
	cmp r7, 0
	bne _080A9968
	movs r0, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x6
	bl template_build_for_pokemon_or_trainer
	ldr r5, =gUnknown_0202499C
	ldr r0, =gUnknown_08305D2C
	ldrb r0, [r0, 0x18]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r4, r1
	asrs r4, 16
	movs r0, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
_080A9914:
	movs r1, 0x50
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r3, =gUnknown_020241E4
	strb r0, [r3]
	ldr r4, =gUnknown_02020630
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r7, [r0, 0x2E]
	b _080A9A70
	.pool
_080A9968:
	ldr r1, =gUnknown_0202406E
	lsls r0, r7, 1
	adds r6, r0, r1
	ldrh r0, [r6]
	movs r2, 0x64
	mov r10, r2
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	ldr r2, =gUnknown_020244EC
	mov r9, r2
	add r0, r9
	movs r1, 0x39
	bl pokemon_getattr
	cmp r0, 0
	bne _080A998C
	b _080A9AA0
_080A998C:
	ldrh r0, [r6]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r0, r9
	movs r1, 0xB
	bl pokemon_getattr
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806A068
	ldr r5, =gUnknown_0202499C
	adds r0, r7, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl AddObjectToFront
	ldr r1, =gUnknown_020241E4
	adds r4, r7, r1
	strb r0, [r4]
	ldr r5, =gUnknown_02020630
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r7, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r7, [r0, 0x2E]
	ldrh r0, [r6]
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	add r0, r9
	movs r1, 0xB
	bl pokemon_getattr
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	strh r0, [r1, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r1, r7, r1
	ldrb r1, [r1]
	bl StartObjectImageAnim
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, [sp]
	adds r0, r1, r0
_080A9A50:
	ldrh r1, [r0, 0x2]
	ldr r0, =0x00000181
	cmp r1, r0
	bne _080A9A70
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r0, r5, 0
	adds r0, 0x8
	adds r1, r0
	ldr r0, =gUnknown_08309AAC
	ldr r2, =0x00000604
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
_080A9A70:
	ldr r1, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, [sp]
	adds r0, r1, r0
	ldr r1, [r0]
	lsls r1, 31
	adds r2, 0x3E
	lsrs r1, 31
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_080A9AA0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A9708

	thumb_func_start sub_80A9ADC
sub_80A9ADC: @ 80A9ADC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0202406C
	ldrb r0, [r0]
	cmp r5, r0
	bcc _080A9AEC
	b _080A9C5E
_080A9AEC:
	ldr r0, =gUnknown_02022FEC
	ldr r1, [r0]
	movs r2, 0x80
	ands r1, r2
	cmp r1, 0
	beq _080A9B0C
	cmp r5, 0
	bne _080A9B0C
	bl battle_make_oam_safari_battle
	b _080A9B24
	.pool
_080A9B0C:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080A9B1E
	cmp r5, 0
	bne _080A9B1E
	b _080A9C5E
_080A9B1E:
	adds r0, r5, 0
	bl battle_make_oam_normal_battle
_080A9B24:
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_03005D70
	adds r4, r5, r0
	strb r6, [r4]
	adds r0, r5, 0
	bl sub_8072B18
	adds r0, r6, 0
	bl sub_80729D0
	adds r0, r5, 0
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	beq _080A9B6C
	ldrb r0, [r4]
	ldr r1, =gUnknown_0202406E
	lsls r4, r5, 1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gUnknown_02024744
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _080A9BB8
	.pool
_080A9B6C:
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080A9BA0
	ldrb r0, [r4]
	ldr r1, =gUnknown_0202406E
	lsls r4, r5, 1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gUnknown_020244EC
	adds r1, r2
	movs r2, 0xA
	bl healthbar_draw_field_maybe
	b _080A9BB8
	.pool
_080A9BA0:
	ldrb r0, [r4]
	ldr r1, =gUnknown_0202406E
	lsls r4, r5, 1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gUnknown_020244EC
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
_080A9BB8:
	adds r0, r5, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _080A9BD4
	adds r0, r5, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080A9BF0
_080A9BD4:
	ldr r0, =gUnknown_03005D70
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x1
	bl nullsub_30
	b _080A9BFC
	.pool
_080A9BF0:
	ldr r0, =gUnknown_03005D70
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0
	bl nullsub_30
_080A9BFC:
	adds r0, r5, 0
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	beq _080A9C34
	ldr r0, =gUnknown_0202406E
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_02024744
	adds r0, r1
	movs r1, 0x39
	bl pokemon_getattr
	cmp r0, 0
	bne _080A9C5E
	adds r0, r6, 0
	bl sub_8072984
	b _080A9C5E
	.pool
_080A9C34:
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080A9C5E
	ldr r0, =gUnknown_0202406E
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_020244EC
	adds r0, r1
	movs r1, 0x39
	bl pokemon_getattr
	cmp r0, 0
	bne _080A9C5E
	adds r0, r6, 0
	bl sub_8072984
_080A9C5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A9ADC

	thumb_func_start sub_80A9C70
sub_80A9C70: @ 80A9C70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_020241E4
	adds r0, r4, r0
	ldrb r6, [r0]
	ldr r0, =sub_80A9DB4
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_08524F84
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0852588C
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r1
	strh r4, [r1, 0x8]
	cmp r5, 0
	beq _080A9D30
	movs r0, 0x1F
	strh r0, [r1, 0xA]
	movs r5, 0
	lsls r0, r6, 4
	ldr r7, =gUnknown_02020630
	adds r0, r6
	lsls r0, 2
	adds r6, r0, r7
_080A9CC4:
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	ldrh r2, [r6, 0x22]
	adds r2, 0x20
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_0853EF60
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r7
	lsls r0, r5, 1
	adds r0, r5
	lsls r1, r0, 4
	adds r0, r1
	strh r0, [r3, 0x2E]
	movs r0, 0xFF
	lsls r0, 8
	strh r0, [r3, 0x30]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	cmp r5, 0x4
	bls _080A9D08
	movs r0, 0x15
	strh r0, [r3, 0x3A]
_080A9D08:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _080A9CC4
	b _080A9D90
	.pool
_080A9D30:
	movs r0, 0xF8
	lsls r0, 7
	strh r0, [r1, 0xA]
	movs r5, 0
	lsls r0, r6, 4
	ldr r7, =gUnknown_02020630
	adds r0, r6
	lsls r0, 2
	adds r6, r0, r7
_080A9D42:
	movs r2, 0x20
	ldrsh r1, [r6, r2]
	ldrh r2, [r6, 0x22]
	subs r2, 0x20
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_0853EF60
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r7
	lsls r0, r5, 1
	adds r0, r5
	lsls r1, r0, 4
	adds r0, r1
	strh r0, [r3, 0x2E]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r3, 0x30]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	cmp r5, 0x4
	bls _080A9D86
	movs r0, 0x15
	strh r0, [r3, 0x3A]
_080A9D86:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _080A9D42
_080A9D90:
	ldr r0, =gUnknown_02020630
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A9C70

	thumb_func_start sub_80A9DB4
sub_80A9DB4: @ 80A9DB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x2
	bne _080A9E3A
	movs r0, 0
	strh r0, [r4, 0xC]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 16
	ldrb r2, [r4, 0x10]
	ldrh r3, [r4, 0xA]
	movs r1, 0x10
	bl pal_fade_1
	ldrh r2, [r4, 0x12]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080A9E10
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _080A9E3E
	movs r0, 0x1
	eors r0, r2
	strh r0, [r4, 0x12]
	b _080A9E3E
	.pool
_080A9E10:
	ldrh r1, [r4, 0x10]
	subs r0, r1, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bge _080A9E3E
	strh r1, [r4, 0x10]
	movs r0, 0x1
	eors r0, r2
	strh r0, [r4, 0x12]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080A9E3E
	adds r0, r5, 0
	bl DestroyTask
	b _080A9E3E
_080A9E3A:
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
_080A9E3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A9DB4

	thumb_func_start sub_80A9E44
sub_80A9E44: @ 80A9E44
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _080A9E70
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r3]
	ldr r1, =sub_80A9E78
	str r1, [r2, 0x1C]
	adds r0, r2, 0
	bl _call_via_r1
	b _080A9E74
	.pool
_080A9E70:
	subs r0, r1, 0x1
	strh r0, [r2, 0x3A]
_080A9E74:
	pop {r0}
	bx r0
	thumb_func_end sub_80A9E44

	thumb_func_start sub_80A9E78
sub_80A9E78: @ 80A9E78
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl cosine
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl sine
	strh r0, [r4, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	bgt _080A9EA4
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1D
	b _080A9EAA
_080A9EA4:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1F
_080A9EAA:
	strb r0, [r1]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x34
	bne _080A9EEC
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080A9EE6
	adds r0, r4, 0
	bl RemoveObjectAndFreeResources
	b _080A9EEC
_080A9EE6:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_080A9EEC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A9E78

	thumb_func_start sub_80A9EF4
sub_80A9EF4: @ 80A9EF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	ldr r1, =0xffe00000
	adds r0, r1
	lsrs r5, r0, 16
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	ldr r1, =0xffdc0000
	adds r0, r1
	lsrs r4, r0, 16
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _080A9F32
	lsls r0, r5, 16
	ldr r1, =0xfffa0000
	adds r0, r1
	lsrs r5, r0, 16
_080A9F32:
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =gUnknown_0853EF48
	lsls r1, r5, 16
	asrs r1, 16
	lsls r2, r4, 16
	asrs r2, 16
	movs r3, 0x4
	bl AddObjectToFront
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x0000271a
	bl GetObjectTileRangeStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _080A9F7C
	ldr r1, =gUnknown_02020630
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080A9F7C:
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	ldr r1, =gUnknown_0853EF40
	bl SetSpriteOamTables_NoPriorityFromTable
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x26]
	ldr r1, =sub_80A9FD0
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A9EF4

	thumb_func_start sub_80A9FD0
sub_80A9FD0: @ 80A9FD0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	adds r2, r0, 0
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _080AA004
	ldr r0, =sub_80AA020
	str r0, [r1]
	movs r0, 0
	strh r0, [r1, 0xA]
	b _080AA01A
	.pool
_080AA004:
	lsls r0, r2, 24
	lsrs r0, 24
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_080AA01A:
	pop {r0}
	bx r0
	thumb_func_end sub_80A9FD0

	thumb_func_start sub_80AA020
sub_80AA020: @ 80AA020
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000271a
	bl IndexOfObjectPaletteTag
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0xA]
	adds r1, r0, 0x1
	strh r1, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	ble _080AA0B0
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _080AA0B0
	ldr r3, =gUnknown_02037B14
	lsls r2, 4
	mov r12, r2
	ldr r1, =0x0000010d
	add r1, r12
	lsls r1, 1
	adds r1, r3
	ldrh r4, [r1]
	movs r2, 0x87
	lsls r2, 1
	add r2, r12
	lsls r2, 1
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r0, =0x0000010f
	add r0, r12
	lsls r0, 1
	adds r0, r3
	ldrh r1, [r0]
	strh r1, [r2]
	strh r4, [r0]
	strh r6, [r5, 0xC]
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _080AA0B0
	strh r6, [r5, 0xE]
	strh r6, [r5, 0xA]
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080AA0B0
	movs r0, 0x9
	strh r0, [r5, 0xA]
	ldr r0, =sub_80AA0D0
	str r0, [r5]
_080AA0B0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA020

	thumb_func_start sub_80AA0D0
sub_80AA0D0: @ 80AA0D0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r0, [r2, 0xA]
	subs r0, 0x1
	adds r3, r0, 0
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080AA108
	ldr r0, =sub_80AA124
	str r0, [r2]
	movs r0, 0
	strh r0, [r2, 0xA]
	b _080AA11E
	.pool
_080AA108:
	lsls r0, r3, 24
	lsrs r0, 24
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_080AA11E:
	pop {r0}
	bx r0
	thumb_func_end sub_80AA0D0

	thumb_func_start sub_80AA124
sub_80AA124: @ 80AA124
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x25
	bne _080AA16C
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
	b _080AA186
	.pool
_080AA16C:
	cmp r0, 0x27
	bne _080AA186
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_task_del
_080AA186:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AA124

	thumb_func_start sub_80AA18C
sub_80AA18C: @ 80AA18C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	subs r0, 0xF
	cmp r0, 0x2B
	bls _080AA1A4
	b _080AA328
_080AA1A4:
	lsls r0, 2
	ldr r1, =_080AA1B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AA1B8:
	.4byte _080AA268
	.4byte _080AA26E
	.4byte _080AA274
	.4byte _080AA27A
	.4byte _080AA280
	.4byte _080AA286
	.4byte _080AA28C
	.4byte _080AA292
	.4byte _080AA298
	.4byte _080AA29E
	.4byte _080AA2A4
	.4byte _080AA2AA
	.4byte _080AA2B0
	.4byte _080AA2B6
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA2BC
	.4byte _080AA2C0
	.4byte _080AA2C4
	.4byte _080AA2C8
	.4byte _080AA2CC
	.4byte _080AA2D0
	.4byte _080AA2D4
	.4byte _080AA2D8
	.4byte _080AA2E0
	.4byte _080AA2E8
	.4byte _080AA2F0
	.4byte _080AA2F8
	.4byte _080AA300
	.4byte _080AA308
	.4byte _080AA328
	.4byte _080AA328
	.4byte _080AA310
	.4byte _080AA314
	.4byte _080AA318
	.4byte _080AA320
_080AA268:
	movs r5, 0
	movs r2, 0
	b _080AA330
_080AA26E:
	movs r5, 0
	movs r2, 0x1
	b _080AA330
_080AA274:
	movs r5, 0
	movs r2, 0x3
	b _080AA330
_080AA27A:
	movs r5, 0
	movs r2, 0x5
	b _080AA330
_080AA280:
	movs r5, 0
	movs r2, 0x6
	b _080AA330
_080AA286:
	movs r5, 0
	movs r2, 0x2
	b _080AA330
_080AA28C:
	movs r5, 0
	movs r2, 0x4
	b _080AA330
_080AA292:
	movs r5, 0x1
	movs r2, 0
	b _080AA330
_080AA298:
	movs r5, 0x1
	movs r2, 0x1
	b _080AA330
_080AA29E:
	movs r5, 0x1
	movs r2, 0x3
	b _080AA330
_080AA2A4:
	movs r5, 0x1
	movs r2, 0x5
	b _080AA330
_080AA2AA:
	movs r5, 0x1
	movs r2, 0x6
	b _080AA330
_080AA2B0:
	movs r5, 0x1
	movs r2, 0x2
	b _080AA330
_080AA2B6:
	movs r5, 0x1
	movs r2, 0x4
	b _080AA330
_080AA2BC:
	movs r5, 0
	b _080AA2DA
_080AA2C0:
	movs r5, 0
	b _080AA2E2
_080AA2C4:
	movs r5, 0
	b _080AA2EA
_080AA2C8:
	movs r5, 0
	b _080AA2F2
_080AA2CC:
	movs r5, 0
	b _080AA2FA
_080AA2D0:
	movs r5, 0
	b _080AA302
_080AA2D4:
	movs r5, 0
	b _080AA30A
_080AA2D8:
	movs r5, 0x1
_080AA2DA:
	movs r2, 0
	movs r3, 0x1
	b _080AA330
_080AA2E0:
	movs r5, 0x1
_080AA2E2:
	movs r2, 0x1
	movs r3, 0x1
	b _080AA330
_080AA2E8:
	movs r5, 0x1
_080AA2EA:
	movs r2, 0x3
	movs r3, 0x1
	b _080AA330
_080AA2F0:
	movs r5, 0x1
_080AA2F2:
	movs r2, 0x5
	movs r3, 0x1
	b _080AA330
_080AA2F8:
	movs r5, 0x1
_080AA2FA:
	movs r2, 0x6
	movs r3, 0x1
	b _080AA330
_080AA300:
	movs r5, 0x1
_080AA302:
	movs r2, 0x2
	movs r3, 0x1
	b _080AA330
_080AA308:
	movs r5, 0x1
_080AA30A:
	movs r2, 0x4
	movs r3, 0x1
	b _080AA330
_080AA310:
	movs r5, 0
	b _080AA31A
_080AA314:
	movs r5, 0
	b _080AA322
_080AA318:
	movs r5, 0x1
_080AA31A:
	movs r2, 0xFF
	movs r3, 0
	b _080AA330
_080AA320:
	movs r5, 0x1
_080AA322:
	movs r2, 0xFF
	movs r3, 0x1
	b _080AA330
_080AA328:
	adds r0, r4, 0
	bl move_anim_task_del
	b _080AA352
_080AA330:
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	strh r5, [r0]
	strh r2, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r3, [r0, 0x8]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8116EB4
	str r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
_080AA352:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AA18C

	thumb_func_start move_anim_start_t2
move_anim_start_t2: @ 80AA364
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02038436
	strb r4, [r0]
	ldr r0, =gUnknown_02038437
	strb r4, [r0]
	ldr r0, =gUnknown_082C92FC
	movs r2, 0
	bl move_something
	ldr r0, =task0A_80788BC
	movs r1, 0xA
	bl CreateTask
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
	thumb_func_end move_anim_start_t2

	thumb_func_start task0A_80788BC
task0A_80788BC: @ 80AA3B4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AA3F6
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	ldr r2, [r2, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_080AA3F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_80788BC

	.align 2, 0 @ Don't pad with nop.
