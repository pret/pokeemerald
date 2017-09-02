	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start PlayCryInternal
PlayCryInternal: @ 80A344C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	lsls r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	lsls r4, 24
	lsrs r1, r4, 24
	ldr r3, =0xffff0000
	adds r0, r3
	lsrs r7, r0, 16
	movs r6, 0x8C
	movs r0, 0
	mov r9, r0
	movs r5, 0
	movs r4, 0xF0
	lsls r4, 6
	mov r8, r5
	cmp r1, 0xC
	bhi _080A3562
	lsls r0, r1, 2
	ldr r1, =_080A349C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080A349C:
	.4byte _080A3562
	.4byte _080A34D0
	.4byte _080A34D6
	.4byte _080A34E4
	.4byte _080A34F8
	.4byte _080A3510
	.4byte _080A351C
	.4byte _080A352C
	.4byte _080A3536
	.4byte _080A3540
	.4byte _080A3550
	.4byte _080A3560
	.4byte _080A355C
_080A34D0:
	movs r6, 0x14
	movs r5, 0xE1
	b _080A3562
_080A34D6:
	movs r5, 0xE1
	ldr r4, =0x00003cf0
	movs r1, 0x14
	b _080A3504
	.pool
_080A34E4:
	movs r6, 0x32
	movs r5, 0xC8
	ldr r4, =0x00003db8
	movs r3, 0x14
	mov r8, r3
	movs r2, 0x5A
	b _080A3562
	.pool
_080A34F8:
	movs r6, 0x19
	movs r0, 0x1
	mov r9, r0
	movs r5, 0x64
	ldr r4, =0x00003cf0
	movs r1, 0xC0
_080A3504:
	mov r8, r1
	movs r2, 0x5A
	b _080A3562
	.pool
_080A3510:
	movs r5, 0xC8
	ldr r4, =0x00003868
	b _080A3562
	.pool
_080A351C:
	movs r5, 0xDC
	ldr r4, =0x00003cc3
	movs r3, 0xC0
	mov r8, r3
	movs r2, 0x46
	b _080A3562
	.pool
_080A352C:
	movs r6, 0xA
	movs r5, 0x64
	movs r4, 0xE8
	lsls r4, 6
	b _080A3562
_080A3536:
	movs r6, 0x3C
	movs r5, 0xE1
	movs r4, 0xF4
	lsls r4, 6
	b _080A3562
_080A3540:
	movs r6, 0xF
	movs r0, 0x1
	mov r9, r0
	movs r5, 0x7D
	ldr r4, =0x00003b60
	b _080A3562
	.pool
_080A3550:
	movs r6, 0x64
	movs r5, 0xE1
	ldr r4, =0x00003b60
	b _080A3562
	.pool
_080A355C:
	movs r6, 0x14
	movs r5, 0xE1
_080A3560:
	ldr r4, =0x00003a98
_080A3562:
	adds r0, r2, 0
	bl SetPokemonCryVolume
	mov r1, r10
	lsls r0, r1, 24
	asrs r0, 24
	bl SetPokemonCryPanpot
	adds r0, r4, 0
	bl SetPokemonCryPitch
	adds r0, r6, 0
	bl SetPokemonCryLength
	movs r0, 0
	bl SetPokemonCryProgress
	adds r0, r5, 0
	bl SetPokemonCryRelease
	mov r3, r8
	lsls r0, r3, 24
	asrs r0, 24
	bl SetPokemonCryChorus
	ldr r0, [sp]
	bl SetPokemonCryPriority
	adds r0, r7, 0
	bl speciesid_conv
	adds r7, r0, 0
	movs r1, 0x7F
	ands r1, r7
	lsrs r0, r7, 7
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	cmp r0, 0x1
	beq _080A35F0
	cmp r0, 0x1
	bgt _080A35C0
	cmp r0, 0
	beq _080A35CA
	b _080A365E
	.pool
_080A35C0:
	cmp r2, 0x2
	beq _080A3614
	cmp r2, 0x3
	beq _080A3638
	b _080A365E
_080A35CA:
	mov r0, r9
	cmp r0, 0
	beq _080A35E0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869EF24
	b _080A3654
	.pool
_080A35E0:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869DCF4
	b _080A3654
	.pool
_080A35F0:
	mov r3, r9
	cmp r3, 0
	beq _080A3604
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869F524
	b _080A3654
	.pool
_080A3604:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869E2F4
	b _080A3654
	.pool
_080A3614:
	mov r0, r9
	cmp r0, 0
	beq _080A3628
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869FB24
	b _080A3654
	.pool
_080A3628:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869E8F4
	b _080A3654
	.pool
_080A3638:
	mov r3, r9
	cmp r3, 0
	beq _080A364C
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_086A0124
	b _080A3654
	.pool
_080A364C:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0869EEF4
_080A3654:
	adds r0, r1
	bl SetPokemonCryTone
	ldr r1, =gUnknown_020383E8
	str r0, [r1]
_080A365E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayCryInternal

	thumb_func_start sub_80A3678
sub_80A3678: @ 80A3678
	push {lr}
	ldr r0, =sub_80A370C
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080A3694
	bl ClearPokemonCrySongs
	movs r0, 0x1
	b _080A3696
	.pool
_080A3694:
	movs r0, 0
_080A3696:
	pop {r1}
	bx r1
	thumb_func_end sub_80A3678

	thumb_func_start sub_80A369C
sub_80A369C: @ 80A369C
	push {lr}
	ldr r0, =gUnknown_020383E8
	ldr r0, [r0]
	bl m4aMPlayStop
	bl ClearPokemonCrySongs
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A369C

	thumb_func_start sub_80A36B4
sub_80A36B4: @ 80A36B4
	push {lr}
	ldr r0, =gUnknown_020383E8
	ldr r0, [r0]
	bl m4aMPlayStop
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A36B4

	thumb_func_start sub_80A36C8
sub_80A36C8: @ 80A36C8
	push {lr}
	ldr r0, =gUnknown_020383E8
	ldr r0, [r0]
	bl IsPokemonCryPlaying
	cmp r0, 0
	bne _080A36E4
	bl ClearPokemonCrySongs
	movs r0, 0
	b _080A36E6
	.pool
_080A36E4:
	movs r0, 0x1
_080A36E6:
	pop {r1}
	bx r1
	thumb_func_end sub_80A36C8

	thumb_func_start sub_80A36EC
sub_80A36EC: @ 80A36EC
	push {lr}
	ldr r0, =gUnknown_020383E8
	ldr r0, [r0]
	bl IsPokemonCryPlaying
	cmp r0, 0
	bne _080A3704
	movs r0, 0
	b _080A3706
	.pool
_080A3704:
	movs r0, 0x1
_080A3706:
	pop {r1}
	bx r1
	thumb_func_end sub_80A36EC

	thumb_func_start sub_80A370C
sub_80A370C: @ 80A370C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gPokemonCryBGMDuckingCounter
	ldrb r0, [r1]
	cmp r0, 0
	beq _080A3724
	subs r0, 0x1
	strb r0, [r1]
	b _080A3742
	.pool
_080A3724:
	ldr r0, =gUnknown_020383E8
	ldr r0, [r0]
	bl IsPokemonCryPlaying
	cmp r0, 0
	bne _080A3742
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	adds r0, r4, 0
	bl DestroyTask
_080A3742:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A370C

	thumb_func_start RestoreBGMVolumeAfterPokemonCry
RestoreBGMVolumeAfterPokemonCry: @ 80A3754
	push {r4,lr}
	ldr r4, =sub_80A370C
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080A376E
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
_080A376E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RestoreBGMVolumeAfterPokemonCry

	thumb_func_start PlayBGM
PlayBGM: @ 80A3778
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gDisableMusic
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A3788
	movs r1, 0
_080A3788:
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080A3790
	movs r1, 0
_080A3790:
	adds r0, r1, 0
	bl m4aSongNumStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayBGM

	thumb_func_start audio_play
audio_play: @ 80A37A4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl m4aSongNumStart
	pop {r0}
	bx r0
	thumb_func_end audio_play

	thumb_func_start audio_play_and_stuff
audio_play_and_stuff: @ 80A37B4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r4, 24
	bl m4aSongNumStart
	ldr r6, =gMPlay_SE1
	adds r0, r6, 0
	bl m4aMPlayImmInit
	ldr r0, =gMPlay_SE2
	mov r8, r0
	bl m4aMPlayImmInit
	ldr r5, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	mov r0, r8
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end audio_play_and_stuff

	thumb_func_start sub_80A3808
sub_80A3808: @ 80A3808
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r4, 24
	bl m4aSongNumStart
	ldr r5, =gMPlay_SE1
	adds r0, r5, 0
	bl m4aMPlayImmInit
	ldr r1, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r0, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3808

	thumb_func_start sub_80A383C
sub_80A383C: @ 80A383C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r4, 24
	bl m4aSongNumStart
	ldr r5, =gMPlay_SE2
	adds r0, r5, 0
	bl m4aMPlayImmInit
	ldr r1, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r0, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A383C

	thumb_func_start sub_80A3870
sub_80A3870: @ 80A3870
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gMPlay_SE1
	ldr r5, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	ldr r0, =gMPlay_SE2
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3870

	thumb_func_start mplay_has_finished_maybe
mplay_has_finished_maybe: @ 80A38A0
	push {lr}
	ldr r0, =gMPlay_SE1
	ldr r1, [r0, 0x4]
	movs r2, 0x80
	lsls r2, 24
	adds r3, r0, 0
	cmp r1, 0
	bge _080A38BA
	ldr r0, =gMPlay_SE2
	ldr r0, [r0, 0x4]
	ands r0, r2
	cmp r0, 0
	bne _080A38CC
_080A38BA:
	ldr r1, =0x0000ffff
	ldrh r0, [r3, 0x4]
	cmp r0, 0
	bne _080A38DC
	ldr r0, =gMPlay_SE2
	ldr r0, [r0, 0x4]
	ands r0, r1
	cmp r0, 0
	bne _080A38DC
_080A38CC:
	movs r0, 0
	b _080A38DE
	.pool
_080A38DC:
	movs r0, 0x1
_080A38DE:
	pop {r1}
	bx r1
	thumb_func_end mplay_has_finished_maybe

	thumb_func_start sub_80A38E4
sub_80A38E4: @ 80A38E4
	push {lr}
	ldr r0, =gMPlay_BGM
	ldr r1, [r0, 0x4]
	cmp r1, 0
	blt _080A3904
	ldr r0, =0x0000ffff
	ands r1, r0
	cmp r1, 0
	beq _080A3904
	movs r0, 0x1
	b _080A3906
	.pool
_080A3904:
	movs r0, 0
_080A3906:
	pop {r1}
	bx r1
	thumb_func_end sub_80A38E4

	thumb_func_start sub_80A390C
sub_80A390C: @ 80A390C
	push {lr}
	ldr r0, =gMPlay_SE3
	ldr r1, [r0, 0x4]
	cmp r1, 0
	blt _080A392C
	ldr r0, =0x0000ffff
	ands r1, r0
	cmp r1, 0
	beq _080A392C
	movs r0, 0x1
	b _080A392E
	.pool
_080A392C:
	movs r0, 0
_080A392E:
	pop {r1}
	bx r1
	thumb_func_end sub_80A390C

	.align 2, 0 @ Don't pad with nop.
