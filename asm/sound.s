	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sound_sources_off
sound_sources_off: @ 80A2DD4
	push {lr}
	ldr r1, =0x03005df8
	movs r0, 0
	strb r0, [r1]
	bl map_music_set_to_zero
	pop {r0}
	bx r0
	.pool
	thumb_func_end sound_sources_off

	thumb_func_start sound_something
sound_something: @ 80A2DE8
	push {r4,r5,lr}
	ldr r0, =0x03000f4c
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0x7
	bhi _080A2ECA
	lsls r0, r1, 2
	ldr r1, =_080A2E08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080A2E08:
	.4byte _080A2ECA
	.4byte _080A2E28
	.4byte _080A2ECA
	.4byte _080A2ECA
	.4byte _080A2ECA
	.4byte _080A2E3C
	.4byte _080A2E5C
	.4byte _080A2E98
_080A2E28:
	movs r0, 0x2
	strb r0, [r2]
	ldr r0, =0x03000f48
	ldrh r0, [r0]
	bl song_play_for_text
	b _080A2ECA
	.pool
_080A2E3C:
	bl sub_80A3258
	lsls r0, 24
	cmp r0, 0
	beq _080A2ECA
	ldr r0, =0x03000f4a
	movs r1, 0
	strh r1, [r0]
	ldr r0, =0x03000f4c
	strb r1, [r0]
	b _080A2ECA
	.pool
_080A2E5C:
	bl sub_80A3258
	lsls r0, 24
	cmp r0, 0
	beq _080A2ECA
	bl task_is_not_running_overworld_fanfare
	lsls r0, 24
	cmp r0, 0
	beq _080A2ECA
	ldr r2, =0x03000f48
	ldr r1, =0x03000f4a
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x03000f4c
	movs r0, 0x2
	strb r0, [r1]
	ldrh r0, [r2]
	bl song_play_for_text
	b _080A2ECA
	.pool
_080A2E98:
	bl sub_80A3258
	lsls r0, 24
	cmp r0, 0
	beq _080A2ECA
	bl task_is_not_running_overworld_fanfare
	lsls r0, 24
	cmp r0, 0
	beq _080A2ECA
	ldr r4, =0x03000f4a
	ldrh r0, [r4]
	ldr r5, =0x03000f4d
	ldrb r1, [r5]
	bl sub_80A3194
	ldr r1, =0x03000f48
	ldrh r0, [r4]
	strh r0, [r1]
	movs r2, 0
	strh r2, [r4]
	ldr r1, =0x03000f4c
	movs r0, 0x2
	strb r0, [r1]
	strb r2, [r5]
_080A2ECA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sound_something

	thumb_func_start map_music_set_to_zero
map_music_set_to_zero: @ 80A2EE0
	ldr r0, =0x03000f48
	movs r1, 0
	strh r1, [r0]
	ldr r0, =0x03000f4a
	strh r1, [r0]
	ldr r0, =0x03000f4c
	strb r1, [r0]
	ldr r0, =0x03000f4d
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end map_music_set_to_zero

	thumb_func_start current_map_music_get
current_map_music_get: @ 80A2F04
	ldr r0, =0x03000f48
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end current_map_music_get

	thumb_func_start current_map_music_set
current_map_music_set: @ 80A2F10
	ldr r1, =0x03000f48
	strh r0, [r1]
	ldr r1, =0x03000f4a
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x03000f4c
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end current_map_music_set

	thumb_func_start sub_80A2F30
sub_80A2F30: @ 80A2F30
	ldr r0, =0x03000f48
	movs r1, 0
	strh r1, [r0]
	ldr r0, =0x03000f4a
	strh r1, [r0]
	ldr r1, =0x03000f4c
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80A2F30

	thumb_func_start sub_80A2F50
sub_80A2F50: @ 80A2F50
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80A303C
	lsls r0, 24
	cmp r0, 0
	beq _080A2F66
	adds r0, r4, 0
	bl play_sound_effect
_080A2F66:
	ldr r0, =0x03000f48
	movs r1, 0
	strh r1, [r0]
	ldr r0, =0x03000f4a
	strh r1, [r0]
	ldr r1, =0x03000f4c
	movs r0, 0x5
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2F50

	thumb_func_start sub_80A2F88
sub_80A2F88: @ 80A2F88
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A2F50
	ldr r1, =0x03000f48
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x03000f4a
	strh r4, [r0]
	ldr r1, =0x03000f4c
	movs r0, 0x6
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2F88

	thumb_func_start sub_80A2FBC
sub_80A2FBC: @ 80A2FBC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r5, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 24
	lsrs r5, 24
	bl sub_80A2F50
	ldr r1, =0x03000f48
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x03000f4a
	strh r4, [r0]
	ldr r1, =0x03000f4c
	movs r0, 0x7
	strb r0, [r1]
	ldr r0, =0x03000f4d
	strb r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2FBC

	thumb_func_start sub_80A3000
sub_80A3000: @ 80A3000
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80A3194
	ldr r0, =0x03000f48
	strh r4, [r0]
	ldr r0, =0x03000f4a
	movs r2, 0
	strh r2, [r0]
	ldr r1, =0x03000f4c
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, =0x03000f4d
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3000

	thumb_func_start sub_80A303C
sub_80A303C: @ 80A303C
	push {lr}
	ldr r0, =0x03000f4c
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _080A3058
	cmp r0, 0x5
	beq _080A3058
	cmp r0, 0x7
	beq _080A3058
	movs r0, 0x1
	b _080A305A
	.pool
_080A3058:
	movs r0, 0
_080A305A:
	pop {r1}
	bx r1
	thumb_func_end sub_80A303C

	thumb_func_start pause_music_for_sound_maybe
@ void pause_music_for_sound_maybe(u8 a1)
pause_music_for_sound_maybe: @ 80A3060
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x03007420
	bl MPlayStop_rev01
	ldr r0, =gUnknown_085248BC
	lsls r4, 2
	adds r4, r0
	ldrh r0, [r4]
	ldr r2, =0x03000f4e
	ldrh r1, [r4, 0x2]
	strh r1, [r2]
	bl m4aSongNumStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pause_music_for_sound_maybe

	thumb_func_start ducking_tick
ducking_tick: @ 80A3094
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r2, =0x03000f4e
	ldrh r0, [r2]
	cmp r0, 0
	beq _080A30B0
	subs r0, 0x1
	strh r0, [r2]
	movs r0, 0
	b _080A30C8
	.pool
_080A30B0:
	cmp r1, 0
	bne _080A30C0
	ldr r0, =0x03007420
	bl m4aMPlayContinue
	b _080A30C6
	.pool
_080A30C0:
	movs r0, 0
	bl m4aSongNumStart
_080A30C6:
	movs r0, 0x1
_080A30C8:
	pop {r1}
	bx r1
	thumb_func_end ducking_tick

	thumb_func_start sub_80A30CC
sub_80A30CC: @ 80A30CC
	push {lr}
	lsls r0, 24
	ldr r1, =gUnknown_085248BC
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0]
	bl m4aSongNumStop
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A30CC

	thumb_func_start fanfare_play
@ void fanfare_play(u16 a1)
fanfare_play: @ 80A30E4
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0
	ldr r2, =gUnknown_085248BC
_080A30EE:
	ldrh r0, [r2]
	cmp r0, r3
	bne _080A3108
	lsls r0, r1, 24
	lsrs r0, 24
	bl pause_music_for_sound_maybe
	bl task_add_50_overworld_fanfare_if_not_running
	b _080A311A
	.pool
_080A3108:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0x11
	bls _080A30EE
	movs r0, 0
	bl pause_music_for_sound_maybe
	bl task_add_50_overworld_fanfare_if_not_running
_080A311A:
	pop {r0}
	bx r0
	thumb_func_end fanfare_play

	thumb_func_start task_is_not_running_overworld_fanfare
task_is_not_running_overworld_fanfare: @ 80A3120
	push {lr}
	ldr r0, =task50_overworld_fanfare
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080A3138
	movs r0, 0x1
	b _080A313A
	.pool
_080A3138:
	movs r0, 0
_080A313A:
	pop {r1}
	bx r1
	thumb_func_end task_is_not_running_overworld_fanfare

	thumb_func_start task50_overworld_fanfare
task50_overworld_fanfare: @ 80A3140
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =0x03000f4e
	ldrh r0, [r1]
	cmp r0, 0
	beq _080A3158
	subs r0, 0x1
	strh r0, [r1]
	b _080A3164
	.pool
_080A3158:
	ldr r0, =0x03007420
	bl m4aMPlayContinue
	adds r0, r4, 0
	bl DestroyTask
_080A3164:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task50_overworld_fanfare

	thumb_func_start task_add_50_overworld_fanfare_if_not_running
@ void task_add_50_overworld_fanfare_if_not_running()
task_add_50_overworld_fanfare_if_not_running: @ 80A3170
	push {r4,lr}
	ldr r4, =task50_overworld_fanfare
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080A318A
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
_080A318A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_add_50_overworld_fanfare_if_not_running

	thumb_func_start sub_80A3194
sub_80A3194: @ 80A3194
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =0x03005df8
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A31A8
	movs r5, 0
_080A31A8:
	ldr r6, =0x0000ffff
	cmp r5, r6
	bne _080A31B0
	movs r5, 0
_080A31B0:
	adds r0, r5, 0
	bl m4aSongNumStart
	ldr r4, =0x03007420
	adds r0, r4, 0
	bl m4aMPlayImmInit
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl MPlayVolumeControl
	adds r0, r5, 0
	bl m4aSongNumStop
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_82E0328
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3194

	thumb_func_start sub_80A31E8
sub_80A31E8: @ 80A31E8
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =0x03007420
	bl sub_82E0308
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A31E8

	thumb_func_start sub_80A3200
sub_80A3200: @ 80A3200
	push {lr}
	ldr r0, =0x03007420
	ldr r1, [r0, 0x4]
	cmp r1, 0
	blt _080A3220
	ldr r0, =0x0000ffff
	ands r1, r0
	cmp r1, 0
	beq _080A3220
	movs r0, 0
	b _080A3222
	.pool
_080A3220:
	movs r0, 0x1
_080A3222:
	pop {r1}
	bx r1
	thumb_func_end sub_80A3200

	thumb_func_start sub_80A3228
sub_80A3228: @ 80A3228
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =0x03007420
	bl sub_82E0328
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3228

	thumb_func_start play_sound_effect
@ void play_sound_effect(u8 a1)
play_sound_effect: @ 80A3240
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =0x03007420
	bl m4aMPlayFadeOut
	pop {r0}
	bx r0
	.pool
	thumb_func_end play_sound_effect

	thumb_func_start sub_80A3258
sub_80A3258: @ 80A3258
	push {lr}
	ldr r0, =0x03007420
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	beq _080A326C
	movs r0, 0
	b _080A326E
	.pool
_080A326C:
	movs r0, 0x1
_080A326E:
	pop {r1}
	bx r1
	thumb_func_end sub_80A3258

	thumb_func_start cry_related
cry_related: @ 80A3274
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x03007420
	ldr r1, =0x0000ffff
	movs r2, 0x55
	bl MPlayVolumeControl
	lsls r4, 24
	asrs r4, 24
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	ldr r1, =0x020383ec
	movs r0, 0x2
	strb r0, [r1]
	bl sub_80A3754
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end cry_related

	thumb_func_start sub_80A32C0
sub_80A32C0: @ 80A32C0
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r1, 24
	asrs r1, 24
	lsls r2, 24
	asrs r2, 24
	movs r4, 0
	str r4, [sp]
	bl sub_80A344C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A32C0

	thumb_func_start sub_80A32E4
sub_80A32E4: @ 80A32E4
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0x1
	bne _080A330A
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	adds r0, r6, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	b _080A332E
_080A330A:
	ldr r0, =0x03007420
	ldr r1, =0x0000ffff
	movs r2, 0x55
	bl MPlayVolumeControl
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	adds r0, r6, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	ldr r1, =0x020383ec
	movs r0, 0x2
	strb r0, [r1]
	bl sub_80A3754
_080A332E:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A32E4

	thumb_func_start sub_80A3344
sub_80A3344: @ 80A3344
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r4, r2, 0
	cmp r2, 0x1
	bne _080A336E
	lsls r1, 24
	asrs r1, 24
	str r2, [sp]
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	b _080A3394
_080A336E:
	ldr r0, =0x02022fec
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080A3384
	ldr r0, =0x03007420
	ldr r1, =0x0000ffff
	movs r2, 0x55
	bl MPlayVolumeControl
_080A3384:
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	adds r0, r6, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
_080A3394:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3344

	thumb_func_start play_cry_maybe
play_cry_maybe: @ 80A33A8
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0x1
	bne _080A33CE
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	adds r0, r6, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	b _080A33EE
_080A33CE:
	ldr r0, =0x03007420
	ldr r1, =0x0000ffff
	movs r2, 0x55
	bl MPlayVolumeControl
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	adds r0, r6, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	ldr r1, =0x020383ec
	movs r0, 0x2
	strb r0, [r1]
_080A33EE:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end play_cry_maybe

	thumb_func_start sub_80A3404
sub_80A3404: @ 80A3404
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x03007420
	ldr r1, =0x0000ffff
	movs r2, 0x55
	bl MPlayVolumeControl
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x78
	movs r3, 0xA
	bl sub_80A344C
	ldr r1, =0x020383ec
	movs r0, 0x2
	strb r0, [r1]
	bl sub_80A3754
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3404

	thumb_func_start sub_80A344C
sub_80A344C: @ 80A344C
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
	bl sub_82E1744
	mov r1, r10
	lsls r0, r1, 24
	asrs r0, 24
	bl sub_82E1758
	adds r0, r4, 0
	bl sub_82E1770
	adds r0, r6, 0
	bl sub_82E17A8
	movs r0, 0
	bl sub_82E17C0
	adds r0, r5, 0
	bl sub_82E17B4
	mov r3, r8
	lsls r0, r3, 24
	asrs r0, 24
	bl sub_82E17E4
	ldr r0, [sp]
	bl sub_82E1850
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
	bl sub_82E1674
	ldr r1, =0x020383e8
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
	thumb_func_end sub_80A344C

	thumb_func_start sub_80A3678
sub_80A3678: @ 80A3678
	push {lr}
	ldr r0, =sub_80A370C
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080A3694
	bl sub_8000964
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
	ldr r0, =0x020383e8
	ldr r0, [r0]
	bl MPlayStop_rev01
	bl sub_8000964
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A369C

	thumb_func_start sub_80A36B4
sub_80A36B4: @ 80A36B4
	push {lr}
	ldr r0, =0x020383e8
	ldr r0, [r0]
	bl MPlayStop_rev01
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A36B4

	thumb_func_start sub_80A36C8
sub_80A36C8: @ 80A36C8
	push {lr}
	ldr r0, =0x020383e8
	ldr r0, [r0]
	bl sub_82E17CC
	cmp r0, 0
	bne _080A36E4
	bl sub_8000964
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
	ldr r0, =0x020383e8
	ldr r0, [r0]
	bl sub_82E17CC
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
	ldr r1, =0x020383ec
	ldrb r0, [r1]
	cmp r0, 0
	beq _080A3724
	subs r0, 0x1
	strb r0, [r1]
	b _080A3742
	.pool
_080A3724:
	ldr r0, =0x020383e8
	ldr r0, [r0]
	bl sub_82E17CC
	cmp r0, 0
	bne _080A3742
	ldr r0, =0x03007420
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl MPlayVolumeControl
	adds r0, r4, 0
	bl DestroyTask
_080A3742:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A370C

	thumb_func_start sub_80A3754
sub_80A3754: @ 80A3754
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
	thumb_func_end sub_80A3754

	thumb_func_start song_play_for_text
song_play_for_text: @ 80A3778
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x03005df8
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
	thumb_func_end song_play_for_text

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
	ldr r6, =0x030075f0
	adds r0, r6, 0
	bl m4aMPlayImmInit
	ldr r0, =0x03007630
	mov r8, r0
	bl m4aMPlayImmInit
	ldr r5, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl MPlayPanpotControl
	mov r0, r8
	adds r1, r5, 0
	adds r2, r4, 0
	bl MPlayPanpotControl
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
	ldr r5, =0x030075f0
	adds r0, r5, 0
	bl m4aMPlayImmInit
	ldr r1, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r0, r5, 0
	adds r2, r4, 0
	bl MPlayPanpotControl
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
	ldr r5, =0x03007630
	adds r0, r5, 0
	bl m4aMPlayImmInit
	ldr r1, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r0, r5, 0
	adds r2, r4, 0
	bl MPlayPanpotControl
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A383C

	thumb_func_start sub_80A3870
sub_80A3870: @ 80A3870
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =0x030075f0
	ldr r5, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r1, r5, 0
	adds r2, r4, 0
	bl MPlayPanpotControl
	ldr r0, =0x03007630
	adds r1, r5, 0
	adds r2, r4, 0
	bl MPlayPanpotControl
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3870

	thumb_func_start mplay_has_finished_maybe
mplay_has_finished_maybe: @ 80A38A0
	push {lr}
	ldr r0, =0x030075f0
	ldr r1, [r0, 0x4]
	movs r2, 0x80
	lsls r2, 24
	adds r3, r0, 0
	cmp r1, 0
	bge _080A38BA
	ldr r0, =0x03007630
	ldr r0, [r0, 0x4]
	ands r0, r2
	cmp r0, 0
	bne _080A38CC
_080A38BA:
	ldr r1, =0x0000ffff
	ldrh r0, [r3, 0x4]
	cmp r0, 0
	bne _080A38DC
	ldr r0, =0x03007630
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
	ldr r0, =0x03007420
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
	ldr r0, =0x03007800
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
