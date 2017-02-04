	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8084620
sub_8084620: @ 8084620
	push {r4,lr}
	ldr r0, =gUnknown_08271857
	bl script_env_2_execute_new_script
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	movs r0, 0x92
	lsls r0, 3
	adds r4, r0
	adds r0, r4, 0
	bl DecryptMoney
	adds r1, r0, 0
	lsrs r1, 1
	adds r0, r4, 0
	bl EncryptMoney
	bl sp000_heal_pokemon
	bl sub_8084720
	bl copy_saved_warp3_bank_and_enter_x_to_warp1
	bl warp_in
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084620

	thumb_func_start flag_var_implications_of_teleport_
flag_var_implications_of_teleport_: @ 8084660
	push {lr}
	bl player_avatar_init_params_reset
	ldr r0, =0x0000088b
	bl FlagReset
	ldr r0, =0x0000088d
	bl FlagReset
	ldr r0, =0x0000088c
	bl FlagReset
	ldr r0, =0x00000889
	bl FlagReset
	ldr r0, =0x00000888
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end flag_var_implications_of_teleport_

	thumb_func_start sub_808469C
sub_808469C: @ 808469C
	push {lr}
	bl player_avatar_init_params_reset
	ldr r0, =0x0000088b
	bl FlagReset
	ldr r0, =0x0000088d
	bl FlagReset
	ldr r0, =0x0000088c
	bl FlagReset
	ldr r0, =0x00000889
	bl FlagReset
	ldr r0, =0x00000888
	bl FlagReset
	ldr r0, =gUnknown_08271862
	bl script_env_2_execute_new_script
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808469C

	thumb_func_start flagmods_08054D70
flagmods_08054D70: @ 80846E4
	push {lr}
	bl player_avatar_init_params_reset
	ldr r0, =0x0000088b
	bl FlagReset
	ldr r0, =0x0000088d
	bl FlagReset
	ldr r0, =0x0000088c
	bl FlagReset
	ldr r0, =0x00000889
	bl FlagReset
	ldr r0, =0x00000888
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end flagmods_08054D70

	thumb_func_start sub_8084720
sub_8084720: @ 8084720
	push {r4,lr}
	bl player_avatar_init_params_reset
	ldr r0, =0x0000088b
	bl FlagReset
	ldr r0, =0x0000088d
	bl FlagReset
	ldr r0, =0x0000088c
	bl FlagReset
	ldr r0, =0x00000889
	bl FlagReset
	ldr r0, =0x00000888
	bl FlagReset
	ldr r4, =0x00004039
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _08084764
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	ldr r0, =0x00004037
	movs r1, 0
	bl VarSet
_08084764:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084720

	thumb_func_start sub_8084788
sub_8084788: @ 8084788
	push {lr}
	ldr r0, =0x0000088c
	bl FlagReset
	bl sub_8085B2C
	bl wild_pokemon_reroll
	bl mapnumbers_history_shift_sav1_0_2_4_out
	bl sub_8161D00
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084788

	thumb_func_start sub_80847A8
sub_80847A8: @ 80847A8
	push {r4,lr}
	movs r4, 0
_080847AC:
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0
	bl sav12_xor_set
	adds r4, 0x1
	cmp r4, 0x3F
	ble _080847AC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80847A8

	thumb_func_start sav12_xor_increment
@ void sav12_xor_increment(u8 a1)
sav12_xor_increment: @ 80847C4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x33
	bhi _080847EC
	adds r0, r4, 0
	bl sub_80847F8
	adds r1, r0, 0
	ldr r0, =0x00fffffe
	cmp r1, r0
	bhi _080847E4
	adds r1, 0x1
	b _080847E6
	.pool
_080847E4:
	ldr r1, =0x00ffffff
_080847E6:
	adds r0, r4, 0
	bl sav12_xor_set
_080847EC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sav12_xor_increment

	thumb_func_start sub_80847F8
sub_80847F8: @ 80847F8
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x33
	bhi _08084828
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	lsls r0, r1, 2
	ldr r1, =0x0000159c
	adds r2, r1
	adds r2, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, 0xAC
	ldr r0, [r2]
	ldr r1, [r1]
	eors r0, r1
	b _0808482A
	.pool
_08084828:
	movs r0, 0
_0808482A:
	pop {r1}
	bx r1
	thumb_func_end sub_80847F8

	thumb_func_start sav12_xor_set
sav12_xor_set: @ 8084830
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x33
	bhi _08084854
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r2, 2
	ldr r2, =0x0000159c
	adds r1, r2
	adds r1, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xAC
	ldr r0, [r0]
	eors r0, r3
	str r0, [r1]
_08084854:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sav12_xor_set

	thumb_func_start sub_8084864
sub_8084864: @ 8084864
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gSaveBlock1Ptr
_0808486C:
	lsls r1, r4, 2
	ldr r0, =0x0000159c
	adds r1, r0
	ldr r0, [r6]
	adds r0, r1
	adds r1, r5, 0
	bl apply_u32_xor_crypto
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3F
	bls _0808486C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084864

	thumb_func_start CopyFieldObjectTemplatesToSav1
@ void CopyFieldObjectTemplatesToSav1()
CopyFieldObjectTemplatesToSav1: @ 8084894
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r5, =gSaveBlock1Ptr
	ldr r1, [r5]
	movs r4, 0xC7
	lsls r4, 4
	adds r1, r4
	ldr r2, =0x05000180
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_02037318
	ldr r2, [r0, 0x4]
	ldr r0, [r2, 0x4]
	ldr r1, [r5]
	adds r1, r4
	ldrb r3, [r2]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 1
	movs r3, 0x80
	lsls r3, 19
	orrs r2, r3
	bl CpuSet
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyFieldObjectTemplatesToSav1

	thumb_func_start CopyFieldObjectTemplateCoordsToSav1
@ void CopyFieldObjectTemplateCoordsToSav1()
CopyFieldObjectTemplateCoordsToSav1: @ 80848E0
	push {lr}
	ldr r0, =gUnknown_02037318
	ldr r1, [r0, 0x4]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, [r1, 0x4]
	movs r3, 0xC7
	lsls r3, 4
	adds r1, r0, r3
	movs r3, 0x3F
_080848F4:
	ldr r0, [r2, 0x10]
	str r0, [r1, 0x10]
	adds r2, 0x18
	adds r1, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _080848F4
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyFieldObjectTemplateCoordsToSav1

	thumb_func_start update_saveblock1_field_object_coords
update_saveblock1_field_object_coords: @ 8084910
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0
	movs r6, 0xC7
	lsls r6, 4
	adds r3, r0, r6
_0808492A:
	ldrb r0, [r3]
	cmp r0, r5
	bne _0808493C
	strh r4, [r3, 0x4]
	strh r2, [r3, 0x6]
	b _08084944
	.pool
_0808493C:
	adds r3, 0x18
	adds r1, 0x1
	cmp r1, 0x3F
	ble _0808492A
_08084944:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end update_saveblock1_field_object_coords

	thumb_func_start update_saveblock1_field_object_movement_behavior
update_saveblock1_field_object_movement_behavior: @ 808494C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r3, 0
	movs r5, 0xC7
	lsls r5, 4
	adds r2, r0, r5
_08084962:
	ldrb r0, [r2]
	cmp r0, r4
	bne _08084970
	strb r1, [r2, 0x9]
	b _08084978
	.pool
_08084970:
	adds r2, 0x18
	adds r3, 0x1
	cmp r3, 0x3F
	ble _08084962
_08084978:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end update_saveblock1_field_object_movement_behavior

	thumb_func_start mapdata_load_assets_to_gpu_and_full_redraw
mapdata_load_assets_to_gpu_and_full_redraw: @ 8084980
	push {r4,lr}
	bl move_tilemap_camera_to_upper_left_corner
	ldr r4, =gUnknown_02037318
	ldr r0, [r4]
	bl copy_map_tileset1_tileset2_to_vram
	ldr r0, [r4]
	bl apply_map_tileset1_tileset2_palette
	bl DrawWholeMapView
	bl cur_mapheader_run_tileset_funcs_after_some_cpuset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapdata_load_assets_to_gpu_and_full_redraw

	thumb_func_start get_mapdata_header
@ mapdata_header *get_mapdata_header()
get_mapdata_header: @ 80849A8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x32]
	cmp r1, 0
	bne _080849BC
	movs r0, 0
	b _080849C6
	.pool
_080849BC:
	ldr r0, =gUnknown_08481DD4
	subs r1, 0x1
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_080849C6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end get_mapdata_header

	thumb_func_start warp_shift
@ void warp_shift()
warp_shift: @ 80849D0
	ldr r3, =gUnknown_020322DC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, [r2, 0x4]
	ldr r1, [r2, 0x8]
	str r0, [r3]
	str r1, [r3, 0x4]
	ldr r0, =gUnknown_020322E4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2, 0x4]
	str r1, [r2, 0x8]
	ldr r2, =gUnknown_020322EC
	ldr r0, =gUnknown_08339D3C
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r2, =gUnknown_020322F4
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end warp_shift

	thumb_func_start set_warp2_warp3_to_neg_1
@ void set_warp2_warp3_to_neg_1()
set_warp2_warp3_to_neg_1: @ 8084A14
	ldr r2, =gUnknown_020322EC
	ldr r0, =gUnknown_08339D3C
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r2, =gUnknown_020322F4
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end set_warp2_warp3_to_neg_1

	thumb_func_start warp_set
@ void warp_set(warpdata *warp, char bank, char map, char warpid, char enter_x, char enter_y)
warp_set: @ 8084A34
	push {r4,r5,lr}
	ldr r4, [sp, 0xC]
	ldr r5, [sp, 0x10]
	strb r1, [r0]
	strb r2, [r0, 0x1]
	strb r3, [r0, 0x2]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r0, 0x4]
	lsls r5, 24
	asrs r5, 24
	strh r5, [r0, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end warp_set

	thumb_func_start warp_data_is_not_neg_1
@ int warp_data_is_not_neg_1(warpdata *warp)
warp_data_is_not_neg_1: @ 8084A54
	push {lr}
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r1, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _08084A88
	movs r0, 0x1
	ldrsb r0, [r1, r0]
	cmp r0, r2
	bne _08084A88
	movs r2, 0x2
	ldrsb r2, [r1, r2]
	cmp r2, r0
	bne _08084A88
	movs r0, 0x4
	ldrsh r3, [r1, r0]
	cmp r3, r2
	bne _08084A88
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r0, r3
	bne _08084A88
	movs r0, 0x1
	b _08084A8A
_08084A88:
	movs r0, 0
_08084A8A:
	pop {r1}
	bx r1
	thumb_func_end warp_data_is_not_neg_1

	thumb_func_start get_mapheader_by_bank_and_number
@ struct mapheader *get_mapheader_by_bank_and_number(unsigned int bank, unsigned int num)
get_mapheader_by_bank_and_number: @ 8084A90
	lsls r0, 16
	lsls r1, 16
	ldr r2, =gUnknown_08486578
	lsrs r0, 14
	adds r0, r2
	ldr r0, [r0]
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.pool
	thumb_func_end get_mapheader_by_bank_and_number

	thumb_func_start warp1_get_mapheader
@ struct mapheader *warp1_get_mapheader()
warp1_get_mapheader: @ 8084AA8
	push {lr}
	ldr r1, =gUnknown_020322E4
	movs r0, 0
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x1]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	pop {r1}
	bx r1
	.pool
	thumb_func_end warp1_get_mapheader

	thumb_func_start set_current_map_header_from_sav1_save_old_name
@ void set_current_map_header_from_sav1_save_old_name()
set_current_map_header_from_sav1_save_old_name: @ 8084ACC
	push {r4-r6,lr}
	ldr r1, =gUnknown_020322FC
	ldr r4, =gUnknown_02037318
	ldrb r0, [r4, 0x14]
	strh r0, [r1]
	ldr r5, =gSaveBlock1Ptr
	ldr r1, [r5]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	adds r1, r4, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, [r5]
	ldrh r0, [r4, 0x12]
	strh r0, [r1, 0x32]
	bl get_mapdata_header
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_current_map_header_from_sav1_save_old_name

	thumb_func_start set_current_map_header_from_sav1
set_current_map_header_from_sav1: @ 8084B1C
	push {r4,r5,lr}
	ldr r4, =gUnknown_02037318
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	adds r1, r4, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	bl get_mapdata_header
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_current_map_header_from_sav1

	thumb_func_start update_camera_pos_from_warpid
@ void update_camera_pos_from_warpid()
update_camera_pos_from_warpid: @ 8084B5C
	push {r4,r5,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0x6
	ldrsb r1, [r2, r1]
	adds r4, r0, 0
	cmp r1, 0
	blt _08084B94
	ldr r3, =gUnknown_02037318
	ldr r0, [r3, 0x4]
	ldrb r5, [r0, 0x1]
	cmp r1, r5
	bge _08084B94
	ldr r0, [r0, 0x8]
	lsls r1, 3
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r0, [r3, 0x4]
	ldr r0, [r0, 0x8]
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	b _08084BCC
	.pool
_08084B94:
	ldr r1, [r4]
	ldrh r3, [r1, 0x8]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	blt _08084BB0
	ldrh r2, [r1, 0xA]
	movs r5, 0xA
	ldrsh r0, [r1, r5]
	cmp r0, 0
	blt _08084BB0
	strh r3, [r1]
	strh r2, [r1, 0x2]
	b _08084BCC
_08084BB0:
	ldr r3, [r4]
	ldr r2, =gUnknown_02037318
	ldr r0, [r2]
	ldr r0, [r0]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r3]
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r3, 0x2]
_08084BCC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end update_camera_pos_from_warpid

	thumb_func_start warp_in
warp_in: @ 8084BD8
	push {lr}
	bl warp_shift
	bl set_current_map_header_from_sav1_save_old_name
	bl update_camera_pos_from_warpid
	pop {r0}
	bx r0
	thumb_func_end warp_in

	thumb_func_start warp1_set
@ void warp1_set(char bank, char map, char warpid, char enter_x, char enter_y)
warp1_set: @ 8084BEC
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, =gUnknown_020322E4
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	lsls r3, 24
	asrs r3, 24
	str r3, [sp]
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl warp_set
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end warp1_set

	thumb_func_start warp1_set_2
@ void warp1_set_2(char bank, char map, char warpid)
warp1_set_2: @ 8084C28
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	asrs r0, 24
	lsls r1, 24
	asrs r1, 24
	lsls r2, 24
	asrs r2, 24
	movs r3, 0x1
	negs r3, r3
	str r3, [sp]
	bl warp1_set
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end warp1_set_2

	thumb_func_start saved_warp2_set
@ void saved_warp2_set(char bank, char map, char warpid)
saved_warp2_set: @ 8084C48
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock1Ptr
	ldr r5, [r0]
	adds r0, r5, 0
	adds r0, 0x14
	lsls r1, 24
	asrs r1, 24
	lsls r2, 24
	asrs r2, 24
	lsls r3, 24
	asrs r3, 24
	movs r4, 0
	ldrsb r4, [r5, r4]
	str r4, [sp]
	movs r4, 0x2
	ldrsb r4, [r5, r4]
	str r4, [sp, 0x4]
	bl warp_set
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end saved_warp2_set

	thumb_func_start saved_warp2_set_2
saved_warp2_set_2: @ 8084C7C
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r4, [sp, 0x14]
	ldr r5, [sp, 0x18]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x14
	lsls r1, 24
	asrs r1, 24
	lsls r2, 24
	asrs r2, 24
	lsls r3, 24
	asrs r3, 24
	lsls r4, 24
	asrs r4, 24
	str r4, [sp]
	lsls r5, 24
	asrs r5, 24
	str r5, [sp, 0x4]
	bl warp_set
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end saved_warp2_set_2

	thumb_func_start copy_saved_warp2_bank_and_enter_x_to_warp1
copy_saved_warp2_bank_and_enter_x_to_warp1: @ 8084CB4
	ldr r2, =gUnknown_020322E4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, [r0, 0x18]
	ldr r0, [r0, 0x14]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end copy_saved_warp2_bank_and_enter_x_to_warp1

	thumb_func_start sub_8084CCC
@ void sub_8084CCC(int a1)
sub_8084CCC: @ 8084CCC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8122CBC
	adds r4, r0, 0
	cmp r4, 0
	beq _08084CFA
	movs r0, 0
	ldrsb r0, [r4, r0]
	movs r1, 0x1
	ldrsb r1, [r4, r1]
	movs r2, 0x1
	negs r2, r2
	movs r3, 0x2
	ldrsb r3, [r4, r3]
	ldrb r4, [r4, 0x4]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp]
	bl warp1_set
_08084CFA:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8084CCC

	thumb_func_start copy_saved_warp3_bank_and_enter_x_to_warp1
@ void copy_saved_warp3_bank_and_enter_x_to_warp1()
copy_saved_warp3_bank_and_enter_x_to_warp1: @ 8084D04
	ldr r2, =gUnknown_020322E4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, [r0, 0x20]
	ldr r0, [r0, 0x1C]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end copy_saved_warp3_bank_and_enter_x_to_warp1

	thumb_func_start sub_8084D1C
sub_8084D1C: @ 8084D1C
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8122CBC
	adds r5, r0, 0
	cmp r5, 0
	beq _08084D50
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x1C
	movs r1, 0
	ldrsb r1, [r5, r1]
	movs r2, 0x1
	ldrsb r2, [r5, r2]
	movs r3, 0x1
	negs r3, r3
	movs r4, 0x2
	ldrsb r4, [r5, r4]
	str r4, [sp]
	movs r4, 0x4
	ldrsb r4, [r5, r4]
	str r4, [sp, 0x4]
	bl warp_set
_08084D50:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084D1C

	thumb_func_start sub_8084D5C
sub_8084D5C: @ 8084D5C
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	bl sav1_map_get_light_level
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gUnknown_020322E4
	movs r0, 0
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, 0x1]
	lsls r1, 24
	asrs r1, 24
	bl get_map_light_level_by_bank_and_number
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	cmp r0, 0
	beq _08084DC4
	adds r0, r5, 0
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08084DC4
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	subs r3, r6, 0x7
	lsls r3, 24
	asrs r3, 24
	subs r4, r7, 0x6
	lsls r4, 24
	asrs r4, 24
	str r4, [sp]
	bl sub_8084DD4
_08084DC4:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084D5C

	thumb_func_start sub_8084DD4
sub_8084DD4: @ 8084DD4
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x24
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	lsls r3, 24
	asrs r3, 24
	str r3, [sp]
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl warp_set
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084DD4

	thumb_func_start sub_8084E14
sub_8084E14: @ 8084E14
	ldr r2, =gUnknown_020322E4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, [r0, 0x28]
	ldr r0, [r0, 0x24]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end sub_8084E14

	thumb_func_start sub_8084E2C
sub_8084E2C: @ 8084E2C
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, =gUnknown_020322EC
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	lsls r3, 24
	asrs r3, 24
	str r3, [sp]
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl warp_set
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084E2C

	thumb_func_start warp1_set_to_warp2
warp1_set_to_warp2: @ 8084E68
	ldr r2, =gUnknown_020322E4
	ldr r0, =gUnknown_020322EC
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end warp1_set_to_warp2

	thumb_func_start sub_8084E80
sub_8084E80: @ 8084E80
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, =gUnknown_020322F4
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	lsls r3, 24
	asrs r3, 24
	str r3, [sp]
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl warp_set
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084E80

	thumb_func_start sub_8084EBC
sub_8084EBC: @ 8084EBC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r4, =gUnknown_020322F4
	adds r0, r4, 0
	bl warp_data_is_not_neg_1
	cmp r0, 0x1
	bne _08084EF0
	ldr r2, =gUnknown_020322E4
	ldr r0, =gUnknown_020322DC
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	b _08084F0A
	.pool
_08084EF0:
	movs r0, 0
	ldrsb r0, [r4, r0]
	movs r1, 0x1
	ldrsb r1, [r4, r1]
	movs r2, 0x1
	negs r2, r2
	lsls r3, r5, 24
	asrs r3, 24
	lsls r4, r6, 24
	asrs r4, 24
	str r4, [sp]
	bl warp1_set
_08084F0A:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8084EBC

	thumb_func_start warp1_set_to_sav1w
warp1_set_to_sav1w: @ 8084F14
	ldr r2, =gUnknown_020322E4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	ldr r0, [r0, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end warp1_set_to_sav1w

	thumb_func_start sub_8084F2C
sub_8084F2C: @ 8084F2C
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0xC
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	lsls r3, 24
	asrs r3, 24
	str r3, [sp]
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl warp_set
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084F2C

	thumb_func_start sub_8084F6C
sub_8084F6C: @ 8084F6C
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8122CBC
	adds r5, r0, 0
	cmp r5, 0
	beq _08084FA0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0xC
	movs r1, 0
	ldrsb r1, [r5, r1]
	movs r2, 0x1
	ldrsb r2, [r5, r2]
	movs r3, 0x1
	negs r3, r3
	movs r4, 0x2
	ldrsb r4, [r5, r4]
	str r4, [sp]
	movs r4, 0x4
	ldrsb r4, [r5, r4]
	str r4, [sp, 0x4]
	bl warp_set
_08084FA0:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8084F6C

	thumb_func_start sub_8084FAC
sub_8084FAC: @ 8084FAC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, [r2, 0x14]
	ldr r1, [r2, 0x18]
	str r0, [r2, 0xC]
	str r1, [r2, 0x10]
	bx lr
	.pool
	thumb_func_end sub_8084FAC

	thumb_func_start sub_8084FC0
sub_8084FC0: @ 8084FC0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02037318
	ldr r0, [r0, 0xC]
	ldr r3, [r0]
	ldr r1, [r0, 0x4]
	cmp r1, 0
	bne _08084FDC
	b _08084FF0
	.pool
_08084FD8:
	adds r0, r1, 0
	b _08084FF2
_08084FDC:
	movs r2, 0
	cmp r2, r3
	bge _08084FF0
_08084FE2:
	ldrb r0, [r1]
	cmp r0, r4
	beq _08084FD8
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _08084FE2
_08084FF0:
	movs r0, 0
_08084FF2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8084FC0

	thumb_func_start sub_8084FF8
sub_8084FF8: @ 8084FF8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	bl sub_8084FC0
	adds r1, r0, 0
	cmp r1, 0
	beq _08085030
	movs r0, 0x8
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, 0x9]
	lsls r1, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	lsls r3, r4, 24
	asrs r3, 24
	lsls r4, r5, 24
	asrs r4, 24
	str r4, [sp]
	bl warp1_set
	b _0808504C
_08085030:
	bl mapheader_run_script_with_tag_x6
	ldr r0, =gUnknown_020322EC
	bl warp_data_is_not_neg_1
	cmp r0, 0
	beq _08085048
	movs r0, 0
	b _0808504E
	.pool
_08085048:
	bl warp1_set_to_warp2
_0808504C:
	movs r0, 0x1
_0808504E:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8084FF8

	thumb_func_start sub_8085058
sub_8085058: @ 8085058
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x6
	adds r1, r3, 0
	bl sub_8084FF8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8085058

	thumb_func_start sub_8085078
sub_8085078: @ 8085078
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x5
	adds r1, r3, 0
	bl sub_8084FF8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8085078

	thumb_func_start mliX_load_map
mliX_load_map: @ 8085098
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	lsls r0, r6, 24
	asrs r0, 24
	lsls r1, r5, 24
	asrs r1, 24
	movs r3, 0x1
	negs r3, r3
	str r3, [sp]
	adds r2, r3, 0
	bl warp1_set
	ldr r4, =gUnknown_02037318
	ldrb r0, [r4, 0x14]
	cmp r0, 0x3A
	beq _080850C8
	bl sub_8085810
_080850C8:
	bl warp_shift
	bl set_current_map_header_from_sav1_save_old_name
	bl CopyFieldObjectTemplatesToSav1
	bl sav2_set_x9_depending_on_sav1_map
	bl sub_809D344
	bl wild_pokemon_reroll
	bl prev_quest_postbuffer_cursor_backup_reset
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80B21B4
	bl sub_809E7B0
	bl sub_80AEDBC
	bl sub_8085B2C
	bl update_sav1_flash_used_on_map
	bl sav1_reset_battle_music_maybe
	bl mapheader_run_script_with_tag_x3
	bl not_trainer_hill_battle_pyramid
	ldr r0, [r4]
	bl copy_map_tileset2_to_vram_2
	ldr r0, [r4]
	bl apply_map_tileset2_palette
	movs r4, 0x6
_08085116:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80ABF00
	adds r4, 0x1
	cmp r4, 0xC
	ble _08085116
	bl sub_80A0A2C
	bl mapnumbers_history_shift_sav1_0_2_4_out
	bl sub_8161D54
	bl sub_80AEE20
	bl wild_encounter_reset_coro_args
	bl mapheader_run_script_with_tag_x5
	ldr r2, =gUnknown_02037318
	ldrb r0, [r2, 0x14]
	cmp r0, 0x3A
	bne _0808514C
	ldr r1, =gUnknown_020322FC
	ldrh r1, [r1]
	cmp r0, r1
	beq _08085150
_0808514C:
	bl AddMapNamePopUpWindowTask
_08085150:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mliX_load_map

	thumb_func_start mli0_load_map
mli0_load_map: @ 8085160
	push {r4-r7,lr}
	adds r7, r0, 0
	bl set_current_map_header_from_sav1_save_old_name
	ldr r0, =gUnknown_020322D8
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080851A2
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	bne _08085190
	bl sub_81AA1D8
	b _080851A2
	.pool
_08085190:
	bl InTrainerHill
	cmp r0, 0
	beq _0808519E
	bl sub_81D5DF8
	b _080851A2
_0808519E:
	bl CopyFieldObjectTemplatesToSav1
_080851A2:
	ldr r4, =gUnknown_02037318
	ldrb r0, [r4, 0x17]
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r4, 0x17]
	bl is_light_level_8_or_9
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_80EB218
	bl sav2_set_x9_depending_on_sav1_map
	bl sub_809D344
	bl wild_pokemon_reroll
	bl prev_quest_postbuffer_cursor_backup_reset
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B21B4
	cmp r7, 0x1
	beq _080851EE
	bl sub_809E7B0
_080851EE:
	bl sub_80AEDBC
	bl sub_8085B2C
	cmp r5, 0
	beq _08085200
	ldr r0, =0x00000888
	bl FlagReset
_08085200:
	bl update_sav1_flash_used_on_map
	bl sav1_reset_battle_music_maybe
	bl mapheader_run_script_with_tag_x3
	bl mapnumbers_history_shift_sav1_0_2_4_out
	bl sub_8161D00
	ldrh r1, [r4, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	bne _08085234
	movs r0, 0
	bl battle_pyramid_map_load_related
	b _08085246
	.pool
_08085234:
	bl InTrainerHill
	cmp r0, 0
	beq _08085242
	bl trainer_hill_map_load_related
	b _08085246
_08085242:
	bl not_trainer_hill_battle_pyramid
_08085246:
	cmp r7, 0x1
	beq _0808525E
	cmp r6, 0
	beq _0808525E
	ldr r1, =gUnknown_03005DC0
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	bl UpdateTVScreensOnMap
	movs r0, 0x1
	bl sub_80E9238
_0808525E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mli0_load_map

	thumb_func_start player_avatar_init_params_reset
player_avatar_init_params_reset: @ 8085268
	ldr r1, =gUnknown_02032300
	movs r0, 0x1
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end player_avatar_init_params_reset

	thumb_func_start walkrun_find_lowest_active_bit_in_bitfield
walkrun_find_lowest_active_bit_in_bitfield: @ 8085278
	push {r4,lr}
	bl player_get_direction_lower_nybble
	ldr r4, =gUnknown_02032300
	strb r0, [r4, 0x1]
	movs r0, 0x2
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _08085298
	movs r0, 0x2
	b _080852CA
	.pool
_08085298:
	movs r0, 0x4
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080852A8
	movs r0, 0x4
	b _080852CA
_080852A8:
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080852B8
	movs r0, 0x8
	b _080852CA
_080852B8:
	movs r0, 0x10
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080852C8
	movs r0, 0x10
	b _080852CA
_080852C8:
	movs r0, 0x1
_080852CA:
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end walkrun_find_lowest_active_bit_in_bitfield

	thumb_func_start sub_80852D4
sub_80852D4: @ 80852D4
	push {r4-r7,lr}
	bl sav1_map_get_light_level
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	bl cur_mapdata_block_role_at_screen_center_acc_to_sav1
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r6, =gUnknown_02032300
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_808532C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =0xffffff00
	ands r7, r0
	orrs r7, r1
	adds r0, r6, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_808538C
	lsls r0, 24
	lsrs r0, 16
	ldr r1, =0xffff00ff
	ands r7, r1
	orrs r7, r0
	str r7, [r6]
	adds r0, r6, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80852D4

	thumb_func_start sub_808532C
sub_808532C: @ 808532C
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0x8
	beq _08085348
	ldr r0, =0x0000088d
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08085382
_08085348:
	cmp r4, 0x5
	bne _08085354
	movs r0, 0x10
	b _08085384
	.pool
_08085354:
	lsls r0, r5, 24
	lsrs r0, 24
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08085368
	movs r0, 0x8
	b _08085384
_08085368:
	bl sav1_map_is_biking_allowed
	cmp r0, 0x1
	bne _08085382
	ldrb r0, [r6]
	cmp r0, 0x2
	bne _0808537A
	movs r0, 0x2
	b _08085384
_0808537A:
	cmp r0, 0x4
	bne _08085382
	movs r0, 0x4
	b _08085384
_08085382:
	movs r0, 0x1
_08085384:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808532C

	thumb_func_start sub_808538C
sub_808538C: @ 808538C
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 24
	lsrs r5, r3, 24
	ldr r0, =0x0000088d
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080853AC
	cmp r5, 0x6
	beq _0808540C
_080853AC:
	lsls r4, 24
	lsrs r5, r4, 24
	adds r0, r5, 0
	bl sub_8088F74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080853E8
	adds r0, r5, 0
	bl sub_8088F58
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08085442
	adds r0, r5, 0
	bl sub_8088EFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08085442
	adds r0, r5, 0
	bl MetatileBehavior_IsSouthArrowWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080853F0
_080853E8:
	movs r0, 0x2
	b _08085448
	.pool
_080853F0:
	adds r0, r5, 0
	bl MetatileBehavior_IsNorthArrowWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08085442
	adds r0, r5, 0
	bl MetatileBehavior_IsWestArrowWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08085410
_0808540C:
	movs r0, 0x4
	b _08085448
_08085410:
	adds r0, r5, 0
	bl MetatileBehavior_IsEastArrowWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08085422
	movs r0, 0x3
	b _08085448
_08085422:
	ldrb r0, [r6]
	cmp r0, 0x10
	bne _0808542C
	cmp r7, 0x8
	beq _08085446
_0808542C:
	cmp r0, 0x8
	bne _08085434
	cmp r7, 0x10
	beq _08085446
_08085434:
	lsrs r0, r4, 24
	bl MetatileBehavior_IsLadder
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08085446
_08085442:
	movs r0, 0x1
	b _08085448
_08085446:
	ldrb r0, [r6, 0x1]
_08085448:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808538C

	thumb_func_start cur_mapdata_block_role_at_screen_center_acc_to_sav1
cur_mapdata_block_role_at_screen_center_acc_to_sav1: @ 8085450
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x7
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	adds r1, 0x7
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end cur_mapdata_block_role_at_screen_center_acc_to_sav1

	thumb_func_start sav1_map_is_biking_allowed
sav1_map_is_biking_allowed: @ 8085474
	push {lr}
	ldr r0, =gUnknown_02037318
	ldrb r1, [r0, 0x1A]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808548C
	movs r0, 0x1
	b _0808548E
	.pool
_0808548C:
	movs r0, 0
_0808548E:
	pop {r1}
	bx r1
	thumb_func_end sav1_map_is_biking_allowed

	thumb_func_start update_sav1_flash_used_on_map
update_sav1_flash_used_on_map: @ 8085494
	push {lr}
	ldr r0, =gUnknown_02037318
	ldrb r1, [r0, 0x15]
	cmp r1, 0
	bne _080854B0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x30
	strb r1, [r0]
	b _080854DE
	.pool
_080854B0:
	ldr r0, =0x00000888
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080854D0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x30
	movs r1, 0x1
	strb r1, [r0]
	b _080854DE
	.pool
_080854D0:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =gUnknown_0854FE78
	ldr r0, [r0]
	subs r0, 0x1
	adds r1, 0x30
	strb r0, [r1]
_080854DE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end update_sav1_flash_used_on_map

	thumb_func_start sub_80854EC
sub_80854EC: @ 80854EC
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	blt _080854FC
	ldr r0, =gUnknown_0854FE78
	ldr r0, [r0]
	cmp r1, r0
	ble _080854FE
_080854FC:
	movs r1, 0
_080854FE:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x30
	strb r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80854EC

	thumb_func_start sav1_get_flash_used_on_map
sav1_get_flash_used_on_map: @ 8085514
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x30
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sav1_get_flash_used_on_map

	thumb_func_start sub_8085524
sub_8085524: @ 8085524
	push {lr}
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	strh r0, [r1, 0x32]
	bl get_mapdata_header
	ldr r1, =gUnknown_02037318
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8085524

	thumb_func_start sub_8085540
sub_8085540: @ 8085540
	ldr r1, =gUnknown_020322D8
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8085540

	thumb_func_start sub_808554C
sub_808554C: @ 808554C
	ldr r0, =gUnknown_020322D8
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_808554C

	thumb_func_start sub_8085558
sub_8085558: @ 8085558
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x0000088a
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080855AC
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0
	bne _080855AC
	movs r0, 0x1
	ldrsb r0, [r4, r0]
	cmp r0, 0x5
	blt _08085584
	cmp r0, 0x8
	ble _0808559E
	cmp r0, 0x2B
	bgt _08085584
	cmp r0, 0x27
	bge _0808559E
_08085584:
	ldr r0, =0x0000405e
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bls _080855AC
	movs r0, 0x1
	ldrsb r0, [r4, r0]
	cmp r0, 0x2E
	bgt _080855AC
	cmp r0, 0x2C
	blt _080855AC
_0808559E:
	movs r0, 0x1
	b _080855AE
	.pool
_080855AC:
	movs r0, 0
_080855AE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8085558

	thumb_func_start sub_80855B4
sub_80855B4: @ 80855B4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x000040ca
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _080855D6
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0
	bne _080855D6
	movs r0, 0x1
	ldrsb r0, [r4, r0]
	cmp r0, 0x7
	beq _080855E0
_080855D6:
	movs r0, 0
	b _080855E2
	.pool
_080855E0:
	movs r0, 0x1
_080855E2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80855B4

	thumb_func_start sub_80855E8
sub_80855E8: @ 80855E8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x000040b3
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _08085606
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0x20
	bne _08085606
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	bls _08085610
_08085606:
	movs r0, 0
	b _08085612
	.pool
_08085610:
	movs r0, 0x1
_08085612:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80855E8

	thumb_func_start sub_8085618
sub_8085618: @ 8085618
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =0x0000405d
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _0808564C
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0808564C
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0xE
	bne _0808564C
	ldrb r0, [r5, 0x1]
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08085654
_0808564C:
	movs r0, 0
	b _08085656
	.pool
_08085654:
	movs r0, 0x1
_08085656:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8085618

	thumb_func_start warp_target_get_music
warp_target_get_music: @ 808565C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80855B4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _08085674
	ldr r0, =0x0000ffff
	b _080856CE
	.pool
_08085674:
	adds r0, r4, 0
	bl sub_8085558
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0808568C
	ldr r0, =0x000001bb
	b _080856CE
	.pool
_0808568C:
	adds r0, r4, 0
	bl sub_8085618
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _080856A4
	ldr r0, =0x000001b9
	b _080856CE
	.pool
_080856A4:
	adds r0, r4, 0
	bl sub_80855E8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	beq _080856CA
	movs r0, 0
	ldrsb r0, [r4, r0]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ldrsb r1, [r4, r1]
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	ldrh r0, [r0, 0x10]
	b _080856CE
_080856CA:
	movs r0, 0xCB
	lsls r0, 1
_080856CE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end warp_target_get_music

	thumb_func_start sav1_map_get_music
sav1_map_get_music: @ 80856D4
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xD0
	lsls r0, 5
	cmp r1, r0
	bne _080856FC
	bl sav1_get_weather_probably
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bne _080856FC
	ldr r0, =0x00000199
	b _08085730
	.pool
_080856FC:
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	adds r0, 0x4
	bl warp_target_get_music
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x00007fff
	cmp r1, r0
	beq _0808571C
	adds r0, r1, 0
	b _08085730
	.pool
_0808571C:
	ldr r0, [r4]
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x17
	ble _0808572C
	movs r0, 0xC9
	lsls r0, 1
	b _08085730
_0808572C:
	movs r0, 0xB4
	lsls r0, 1
_08085730:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sav1_map_get_music

	thumb_func_start warp1_target_get_music
warp1_target_get_music: @ 8085738
	push {lr}
	ldr r0, =gUnknown_020322E4
	bl warp_target_get_music
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x00007fff
	cmp r1, r0
	beq _08085758
	adds r0, r1, 0
	b _08085774
	.pool
_08085758:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	beq _08085770
	subs r0, 0x6E
	b _08085774
	.pool
_08085770:
	movs r0, 0xB4
	lsls r0, 1
_08085774:
	pop {r1}
	bx r1
	thumb_func_end warp1_target_get_music

	thumb_func_start call_map_music_set_to_zero
call_map_music_set_to_zero: @ 8085778
	push {lr}
	bl map_music_set_to_zero
	pop {r0}
	bx r0
	thumb_func_end call_map_music_set_to_zero

	thumb_func_start sub_8085784
sub_8085784: @ 8085784
	push {r4,lr}
	bl sav1_map_get_music
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x000001bb
	cmp r4, r0
	beq _080857D6
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _080857D6
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1, 0x2C]
	cmp r0, 0
	beq _080857B4
	adds r4, r0, 0
	b _080857D6
	.pool
_080857B4:
	bl sav1_map_get_light_level
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _080857C8
	ldr r4, =0x0000019b
	b _080857D6
	.pool
_080857C8:
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080857D6
	ldr r4, =0x0000016d
_080857D6:
	bl current_map_music_get
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	beq _080857E8
	adds r0, r4, 0
	bl current_map_music_set
_080857E8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8085784

	thumb_func_start sav1_set_battle_music_maybe
sav1_set_battle_music_maybe: @ 80857F4
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	strh r0, [r1, 0x2C]
	bx lr
	.pool
	thumb_func_end sav1_set_battle_music_maybe

	thumb_func_start sav1_reset_battle_music_maybe
sav1_reset_battle_music_maybe: @ 8085800
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x2C]
	bx lr
	.pool
	thumb_func_end sav1_reset_battle_music_maybe

	thumb_func_start sub_8085810
sub_8085810: @ 8085810
	push {r4-r6,lr}
	ldr r0, =0x00004001
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08085890
	bl warp1_target_get_music
	lsls r0, 16
	lsrs r4, r0, 16
	bl current_map_music_get
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x000001bb
	cmp r4, r0
	beq _08085856
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _08085856
	ldr r0, =0x0000019b
	cmp r5, r0
	beq _08085890
	ldr r6, =0x0000016d
	cmp r5, r6
	beq _08085890
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _08085856
	adds r4, r6, 0
_08085856:
	cmp r4, r5
	beq _08085890
	movs r0, 0x6
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _08085888
	adds r0, r4, 0
	movs r1, 0x4
	movs r2, 0x4
	bl sub_80A2FBC
	b _08085890
	.pool
_08085888:
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_80A2F88
_08085890:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8085810

	thumb_func_start sub_8085898
sub_8085898: @ 8085898
	push {r4,lr}
	bl current_map_music_get
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sav1_map_get_music
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	beq _080858BE
	bl sav1_map_get_music
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x8
	bl sub_80A2F88
_080858BE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8085898

	thumb_func_start sub_80858C4
sub_80858C4: @ 80858C4
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl current_map_music_get
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r4
	beq _080858E4
	ldr r0, =0x000001bb
	cmp r1, r0
	beq _080858E4
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_80A2F88
_080858E4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80858C4

	thumb_func_start is_warp1_light_level_8_or_9
is_warp1_light_level_8_or_9: @ 80858F0
	push {lr}
	bl warp1_get_mapheader
	ldrb r0, [r0, 0x17]
	bl is_light_level_8_or_9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08085908
	movs r0, 0x4
	b _0808590A
_08085908:
	movs r0, 0x2
_0808590A:
	pop {r1}
	bx r1
	thumb_func_end is_warp1_light_level_8_or_9

	thumb_func_start music_something
music_something: @ 8085910
	push {r4,r5,lr}
	bl current_map_music_get
	lsls r0, 16
	lsrs r5, r0, 16
	bl warp1_target_get_music
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004001
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0808597E
	bl current_map_music_get
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	beq _0808597E
	ldr r0, =0x0000016d
	cmp r5, r0
	bne _08085972
	ldr r0, =0x000040ca
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _08085972
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000ffff
	ldrh r2, [r0, 0x4]
	movs r0, 0xE0
	lsls r0, 3
	cmp r2, r0
	bne _08085972
	ldr r3, =gUnknown_020322E4
	ldrh r0, [r3]
	ands r1, r0
	cmp r1, r2
	bne _08085972
	ldr r1, [r3, 0x4]
	ldr r0, =0x0035001d
	cmp r1, r0
	beq _0808597E
_08085972:
	bl is_warp1_light_level_8_or_9
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A2F50
_0808597E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end music_something

	thumb_func_start sub_80859A0
sub_80859A0: @ 80859A0
	push {lr}
	bl sub_80A303C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80859A0

	thumb_func_start sub_80859B0
sub_80859B0: @ 80859B0
	push {lr}
	movs r0, 0x4
	bl sub_80A2F50
	pop {r0}
	bx r0
	thumb_func_end sub_80859B0

	thumb_func_start sub_80859BC
sub_80859BC: @ 80859BC
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	ldr r0, =gUnknown_02032306
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080859F0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	beq _08085A2C
_080859F0:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x58
	bl __umodsi3
	adds r4, r0, 0
	adds r4, 0xD4
	lsls r4, 24
	lsrs r4, 24
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	adds r2, r0, 0
	adds r2, 0x32
	ldr r0, =gUnknown_02032304
	ldrh r0, [r0]
	lsls r4, 24
	asrs r4, 24
	lsls r2, 24
	asrs r2, 24
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_80A32C0
_08085A2C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80859BC

	thumb_func_start wild_encounter_related
wild_encounter_related: @ 8085A3C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x4
	bhi _08085B20
	lsls r0, 2
	ldr r1, =_08085A60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08085A60:
	.4byte _08085A74
	.4byte _08085A88
	.4byte _08085AA4
	.4byte _08085B0C
	.4byte _08085B20
_08085A74:
	ldr r0, =gUnknown_02032304
	ldrh r0, [r0]
	cmp r0, 0
	bne _08085A84
	movs r0, 0x4
	b _08085B1E
	.pool
_08085A84:
	movs r0, 0x1
	b _08085B1E
_08085A88:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x96
	lsls r1, 4
	bl __umodsi3
	movs r1, 0x96
	lsls r1, 3
	adds r0, r1
	strh r0, [r7]
	movs r0, 0x3
	b _08085B1E
_08085AA4:
	movs r0, 0x1
	mov r9, r0
	bl calc_player_party_count
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	b _08085ABC
_08085AB6:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_08085ABC:
	cmp r5, r8
	bcs _08085AE4
	movs r0, 0x64
	muls r0, r5
	ldr r4, =gUnknown_020244EC
	adds r0, r4
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _08085AB6
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x44
	bne _08085AB6
	movs r1, 0x2
	mov r9, r1
_08085AE4:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r4, 0x96
	lsls r4, 3
	adds r1, r4, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, r4
	mov r1, r9
	bl __divsi3
	strh r0, [r7]
	movs r0, 0x3
	b _08085B1E
	.pool
_08085B0C:
	ldrh r0, [r7]
	subs r0, 0x1
	strh r0, [r7]
	lsls r0, 16
	cmp r0, 0
	bne _08085B20
	bl sub_80859BC
	movs r0, 0x2
_08085B1E:
	strh r0, [r6]
_08085B20:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end wild_encounter_related

	thumb_func_start sub_8085B2C
sub_8085B2C: @ 8085B2C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xB4
	lsls r0, 6
	cmp r1, r0
	bne _08085B5C
	bl sub_813793C
	lsls r0, 24
	cmp r0, 0
	bne _08085B5C
	ldr r1, =gUnknown_02032306
	movs r0, 0x1
	strb r0, [r1]
	bl sub_80B582C
	b _08085B62
	.pool
_08085B5C:
	ldr r0, =gUnknown_02032306
	bl wild_pokemon_rand_for_map
_08085B62:
	ldr r1, =gUnknown_02032304
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8085B2C

	thumb_func_start get_map_light_level_by_bank_and_number
@ int get_map_light_level_by_bank_and_number(int bank, int number)
get_map_light_level_by_bank_and_number: @ 8085B74
	push {lr}
	lsls r0, 24
	asrs r0, 8
	lsrs r0, 16
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x17]
	pop {r1}
	bx r1
	thumb_func_end get_map_light_level_by_bank_and_number

	thumb_func_start get_map_light_level_from_warp
@ int get_map_light_level_from_warp(warpdata *warp)
get_map_light_level_from_warp: @ 8085B8C
	push {lr}
	movs r2, 0
	ldrsb r2, [r0, r2]
	movs r1, 0x1
	ldrsb r1, [r0, r1]
	adds r0, r2, 0
	bl get_map_light_level_by_bank_and_number
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end get_map_light_level_from_warp

	thumb_func_start sav1_map_get_light_level
sav1_map_get_light_level: @ 8085BA4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, 0x4
	bl get_map_light_level_from_warp
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav1_map_get_light_level

	thumb_func_start get_map_light_from_warp0
get_map_light_from_warp0: @ 8085BBC
	push {lr}
	ldr r0, =gUnknown_020322DC
	bl get_map_light_level_from_warp
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end get_map_light_from_warp0

	thumb_func_start is_light_level_1_2_3_5_or_6
is_light_level_1_2_3_5_or_6: @ 8085BD0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08085BEA
	cmp r0, 0x1
	beq _08085BEA
	cmp r0, 0x5
	beq _08085BEA
	cmp r0, 0x2
	beq _08085BEA
	cmp r0, 0x6
	bne _08085BEE
_08085BEA:
	movs r0, 0x1
	b _08085BF0
_08085BEE:
	movs r0, 0
_08085BF0:
	pop {r1}
	bx r1
	thumb_func_end is_light_level_1_2_3_5_or_6

	thumb_func_start is_light_level_1_2_3_or_6
is_light_level_1_2_3_or_6: @ 8085BF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08085C0A
	cmp r0, 0x1
	beq _08085C0A
	cmp r0, 0x6
	beq _08085C0A
	cmp r0, 0x2
	bne _08085C0E
_08085C0A:
	movs r0, 0x1
	b _08085C10
_08085C0E:
	movs r0, 0
_08085C10:
	pop {r1}
	bx r1
	thumb_func_end is_light_level_1_2_3_or_6

	thumb_func_start is_light_level_8_or_9
is_light_level_8_or_9: @ 8085C14
	push {lr}
	lsls r0, 24
	movs r1, 0xF8
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _08085C28
	movs r0, 0
	b _08085C2A
_08085C28:
	movs r0, 0x1
_08085C2A:
	pop {r1}
	bx r1
	thumb_func_end is_light_level_8_or_9

	thumb_func_start sav1_saved_warp2_map_get_name
sav1_saved_warp2_map_get_name: @ 8085C30
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x14
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x15]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav1_saved_warp2_map_get_name

	thumb_func_start sav1_map_get_name
sav1_map_get_name: @ 8085C58
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav1_map_get_name

	thumb_func_start sav1_map_get_battletype
sav1_map_get_battletype: @ 8085C80
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	ldrb r0, [r0, 0x1B]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav1_map_get_battletype

	thumb_func_start overworld_bg_setup
@ void overworld_bg_setup()
overworld_bg_setup: @ 8085CA8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r1, =gUnknown_08339DAC
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r0, 0x1
	movs r1, 0x5
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x5
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x1
	bl SetBgAttribute
	ldr r0, =gUnknown_03005DA0
	mov r8, r0
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl AllocZeroed
	mov r1, r8
	str r0, [r1]
	ldr r6, =gUnknown_03005D9C
	adds r0, r4, 0
	bl AllocZeroed
	str r0, [r6]
	ldr r5, =gUnknown_03005DA4
	adds r0, r4, 0
	bl AllocZeroed
	str r0, [r5]
	mov r0, r8
	ldr r1, [r0]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r6]
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r5]
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl sub_81971D0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end overworld_bg_setup

	thumb_func_start overworld_free_bg_tilemaps
overworld_free_bg_tilemaps: @ 8085D34
	push {r4,lr}
	bl sub_81BE72C
	bl sub_81971F4
	ldr r4, =gUnknown_03005DA4
	ldr r0, [r4]
	cmp r0, 0
	beq _08085D4E
	bl Free
	movs r0, 0
	str r0, [r4]
_08085D4E:
	ldr r4, =gUnknown_03005D9C
	ldr r0, [r4]
	cmp r0, 0
	beq _08085D5E
	bl Free
	movs r0, 0
	str r0, [r4]
_08085D5E:
	ldr r4, =gUnknown_03005DA0
	ldr r0, [r4]
	cmp r0, 0
	beq _08085D6E
	bl Free
	movs r0, 0
	str r0, [r4]
_08085D6E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end overworld_free_bg_tilemaps

	thumb_func_start ResetSafariZoneFlag_
ResetSafariZoneFlag_: @ 8085D80
	push {lr}
	bl ResetSafariZoneFlag
	pop {r0}
	bx r0
	thumb_func_end ResetSafariZoneFlag_

	thumb_func_start is_c1_link_related_active
@ _BOOL4 is_c1_link_related_active()
is_c1_link_related_active: @ 8085D8C
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0]
	ldr r0, =c1_link_related
	cmp r1, r0
	beq _08085DA4
	movs r0, 0
	b _08085DA6
	.pool
_08085DA4:
	movs r0, 0x1
_08085DA6:
	pop {r1}
	bx r1
	thumb_func_end is_c1_link_related_active

	thumb_func_start c1_overworld_normal
@ void c1_overworld_normal(int buttons_new, int buttons_held)
c1_overworld_normal: @ 8085DAC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	bl sub_808B578
	mov r6, sp
	mov r0, sp
	bl sub_809BEDC
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl process_overworld_input
	bl script_env_2_is_enabled
	lsls r0, 24
	cmp r0, 0
	bne _08085DFA
	mov r0, sp
	bl sub_809C014
	cmp r0, 0x1
	bne _08085DF0
	bl script_env_2_enable
	bl HideMapNamePopUpWindow
	b _08085DFA
_08085DF0:
	ldrb r0, [r6, 0x2]
	adds r1, r5, 0
	adds r2, r4, 0
	bl player_step
_08085DFA:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end c1_overworld_normal

	thumb_func_start c1_overworld
c1_overworld: @ 8085E04
	push {lr}
	ldr r2, =gMain
	ldr r1, [r2, 0x4]
	ldr r0, =c2_overworld
	cmp r1, r0
	bne _08085E18
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x2C]
	bl c1_overworld_normal
_08085E18:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c1_overworld

	thumb_func_start c2_overworld_basic
@ void c2_overworld_basic()
c2_overworld_basic: @ 8085E24
	push {lr}
	bl script_env_2_run_current_script
	bl RunTasks
	bl CallObjectCallbacks
	bl CameraUpdate
	bl UpdateCameraPanning
	bl PrepareSpritesForOamLoad
	bl fade_and_return_progress_probably
	bl sub_80A0A38
	bl do_scheduled_bg_tilemap_copies_to_vram
	pop {r0}
	bx r0
	thumb_func_end c2_overworld_basic

	thumb_func_start sub_8085E50
sub_8085E50: @ 8085E50
	push {lr}
	bl c2_overworld_basic
	pop {r0}
	bx r0
	thumb_func_end sub_8085E50

	thumb_func_start c2_overworld
c2_overworld: @ 8085E5C
	push {r4,lr}
	ldr r0, =gUnknown_02037FD4
	ldrb r0, [r0, 0x7]
	lsrs r0, 7
	adds r4, r0, 0
	cmp r4, 0
	beq _08085E70
	movs r0, 0
	bl SetVBlankCallback
_08085E70:
	bl c2_overworld_basic
	cmp r4, 0
	beq _08085E7C
	bl SetFieldVBlankCallback
_08085E7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_overworld

	thumb_func_start set_callback1
set_callback1: @ 8085E88
	ldr r1, =gMain
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end set_callback1

	thumb_func_start sub_8085E94
sub_8085E94: @ 8085E94
	ldr r1, =gUnknown_03000E0C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8085E94

	thumb_func_start map_post_load_hook_exec
map_post_load_hook_exec: @ 8085EA0
	push {r4,lr}
	ldr r4, =gUnknown_03005DB0
	ldr r0, [r4]
	cmp r0, 0
	beq _08085ECC
	bl _call_via_r0
	lsls r0, 24
	cmp r0, 0
	bne _08085EBC
	movs r0, 0
	b _08085EEC
	.pool
_08085EBC:
	movs r1, 0
	str r1, [r4]
	ldr r0, =gUnknown_03005DAC
	str r1, [r0]
	b _08085EEA
	.pool
_08085ECC:
	ldr r0, =gUnknown_03005DAC
	ldr r0, [r0]
	cmp r0, 0
	beq _08085EE0
	bl _call_via_r0
	b _08085EE4
	.pool
_08085EE0:
	bl mapldr_default
_08085EE4:
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
_08085EEA:
	movs r0, 0x1
_08085EEC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end map_post_load_hook_exec

	thumb_func_start CB2_NewGame
CB2_NewGame: @ 8085EF8
	push {lr}
	bl sub_808631C
	bl sub_80A2F30
	bl ResetSafariZoneFlag_
	bl NewGameInitData
	bl player_avatar_init_params_reset
	bl set_max_playtime_if_appropriate
	bl script_env_1_init
	bl script_env_2_disable
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80FB4E0
	str r0, [r1]
	ldr r1, =gUnknown_03005DB0
	movs r0, 0
	str r0, [r1]
	ldr r0, =gUnknown_030026F8
	bl do_load_map_stuff_loop
	bl SetFieldVBlankCallback
	ldr r0, =c1_overworld
	bl set_callback1
	ldr r0, =c2_overworld
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_NewGame

	thumb_func_start c2_whiteout
c2_whiteout: @ 8085F58
	push {lr}
	sub sp, 0x4
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x77
	bls _08085FB0
	bl sub_808631C
	bl sub_80A2F30
	bl ResetSafariZoneFlag_
	bl sub_8084620
	bl player_avatar_init_params_reset
	bl script_env_1_init
	bl script_env_2_disable
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF3C8
	str r0, [r1]
	mov r1, sp
	movs r0, 0
	strb r0, [r1]
	mov r0, sp
	bl do_load_map_stuff_loop
	bl SetFieldVBlankCallback
	ldr r0, =c1_overworld
	bl set_callback1
	ldr r0, =c2_overworld
	bl SetMainCallback2
_08085FB0:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_whiteout

	thumb_func_start c2_load_new_map
c2_load_new_map: @ 8085FCC
	push {lr}
	bl sub_808631C
	bl script_env_1_init
	bl script_env_2_disable
	movs r0, 0
	bl set_callback1
	ldr r0, =c2_change_map
	bl SetMainCallback2
	ldr r1, =gMain
	ldr r0, =c2_load_new_map_2
	str r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_load_new_map

	thumb_func_start c2_load_new_map_2
c2_load_new_map_2: @ 8085FFC
	push {lr}
	ldr r0, =gUnknown_030026F8
	bl do_load_map_stuff_loop
	bl SetFieldVBlankCallback
	ldr r0, =c1_overworld
	bl set_callback1
	ldr r0, =c2_overworld
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_load_new_map_2

	thumb_func_start sub_8086024
sub_8086024: @ 8086024
	push {r4,lr}
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	bne _08086046
	bl sub_808631C
	bl script_env_1_init
	bl script_env_2_disable
	movs r0, 0
	bl set_callback1
_08086046:
	adds r0, r4, 0
	movs r1, 0x1
	bl load_map_stuff
	cmp r0, 0
	beq _08086062
	bl SetFieldVBlankCallback
	ldr r0, =c1_overworld
	bl set_callback1
	ldr r0, =c2_overworld
	bl SetMainCallback2
_08086062:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086024

	thumb_func_start sub_8086074
sub_8086074: @ 8086074
	push {lr}
	bl sub_808631C
	ldr r0, =gUnknown_03005DAC
	ldr r1, =sub_80AF314
	str r1, [r0]
	ldr r0, =c2_80567AC
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086074

	thumb_func_start c2_80567AC
c2_80567AC: @ 8086098
	push {lr}
	ldr r0, =gUnknown_030026F8
	bl map_loading_iteration_3
	cmp r0, 0
	beq _080860B8
	bl SetFieldVBlankCallback
	ldr r0, =c1_link_related
	bl set_callback1
	bl sub_8086C2C
	ldr r0, =c2_overworld
	bl SetMainCallback2
_080860B8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_80567AC

	thumb_func_start c2_exit_to_overworld_2_switch
c2_exit_to_overworld_2_switch: @ 80860C8
	push {lr}
	bl is_c1_link_related_active
	cmp r0, 0x1
	bne _080860E0
	ldr r0, =c2_exit_to_overworld_2_link
	bl SetMainCallback2
	b _080860EA
	.pool
_080860E0:
	bl sub_808631C
	ldr r0, =c2_exit_to_overworld_2_local
	bl SetMainCallback2
_080860EA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_exit_to_overworld_2_switch

	thumb_func_start c2_exit_to_overworld_2_local
c2_exit_to_overworld_2_local: @ 80860F4
	push {lr}
	ldr r0, =gUnknown_030026F8
	bl sub_8086638
	cmp r0, 0
	beq _0808610A
	bl SetFieldVBlankCallback
	ldr r0, =c2_overworld
	bl SetMainCallback2
_0808610A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_exit_to_overworld_2_local

	thumb_func_start c2_exit_to_overworld_2_link
c2_exit_to_overworld_2_link: @ 8086118
	push {lr}
	bl sub_8087598
	cmp r0, 0
	bne _08086132
	ldr r0, =gUnknown_030026F8
	bl map_loading_iteration_2_link
	cmp r0, 0
	beq _08086132
	ldr r0, =c2_overworld
	bl SetMainCallback2
_08086132:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_exit_to_overworld_2_link

	thumb_func_start c2_8056854
c2_8056854: @ 8086140
	push {lr}
	bl sub_808631C
	bl sub_80A2F30
	ldr r0, =c1_link_related
	bl set_callback1
	bl sub_8086C2C
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086174
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF314
	b _08086178
	.pool
_08086174:
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF214
_08086178:
	str r0, [r1]
	bl script_env_1_init
	bl script_env_2_disable
	bl c2_exit_to_overworld_2_switch
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_8056854

	thumb_func_start sub_8086194
sub_8086194: @ 8086194
	push {lr}
	bl sub_808631C
	ldr r1, =gUnknown_03005DB0
	ldr r0, =sub_80AF6A4
	str r0, [r1]
	bl c2_exit_to_overworld_2_switch
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086194

	thumb_func_start sub_80861B0
sub_80861B0: @ 80861B0
	push {lr}
	bl sub_808631C
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF188
	str r0, [r1]
	bl c2_exit_to_overworld_2_switch
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80861B0

	thumb_func_start c2_exit_to_overworld_1_continue_scripts_restart_music
c2_exit_to_overworld_1_continue_scripts_restart_music: @ 80861CC
	push {lr}
	bl sub_808631C
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF168
	str r0, [r1]
	bl c2_exit_to_overworld_2_switch
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_exit_to_overworld_1_continue_scripts_restart_music

	thumb_func_start sub_80861E8
sub_80861E8: @ 80861E8
	push {lr}
	bl sub_808631C
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF3C8
	str r0, [r1]
	bl c2_exit_to_overworld_2_switch
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80861E8

	thumb_func_start sub_8086204
sub_8086204: @ 8086204
	push {lr}
	ldr r0, =gUnknown_02037318
	ldrb r1, [r0, 0x1A]
	movs r0, 0xF8
	ands r0, r1
	cmp r0, 0x8
	bne _08086222
	bl sub_80E909C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08086222
	bl AddMapNamePopUpWindowTask
_08086222:
	bl sub_80AF3C8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086204

	thumb_func_start sub_8086230
sub_8086230: @ 8086230
	push {r4,lr}
	bl sub_808631C
	bl sub_80A2F30
	bl ResetSafariZoneFlag_
	ldr r0, =gUnknown_03006210
	ldrh r0, [r0]
	cmp r0, 0xFF
	bne _0808624A
	bl sub_81A3908
_0808624A:
	bl set_current_map_header_from_sav1
	bl set_warp2_warp3_to_neg_1
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	bne _08086278
	bl sub_81AA2F8
	b _0808628A
	.pool
_08086278:
	cmp r4, 0
	beq _08086286
	cmp r4, 0x6
	beq _08086286
	bl sub_81D5F48
	b _0808628A
_08086286:
	bl CopyFieldObjectTemplateCoordsToSav1
_0808628A:
	bl sub_809757C
	bl sub_809E7B0
	bl sub_8084788
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	bne _080862B0
	movs r0, 0x1
	bl battle_pyramid_map_load_related
	b _080862BE
	.pool
_080862B0:
	cmp r4, 0
	beq _080862BA
	bl trainer_hill_map_load_related
	b _080862BE
_080862BA:
	bl sub_8087D74
_080862BE:
	bl set_max_playtime_if_appropriate
	bl script_env_1_init
	bl script_env_2_disable
	bl sub_8195E10
	bl sav2_x1_query_bit1
	cmp r0, 0x1
	bne _080862F4
	bl sav2_x9_clear_bit1
	bl warp1_set_to_sav1w
	bl warp_in
	bl sub_80EDB44
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	b _08086308
	.pool
_080862F4:
	bl sub_80EDB44
	ldr r0, =gUnknown_03005DAC
	ldr r1, =sub_8086204
	str r1, [r0]
	ldr r0, =c1_overworld
	bl set_callback1
	bl c2_exit_to_overworld_2_switch
_08086308:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086230

	thumb_func_start sub_808631C
@ void sub_808631C()
sub_808631C: @ 808631C
	push {r4,lr}
	bl warp0_in_pokecenter
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0808632E
	bl sub_80097E8
_0808632E:
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086348
	movs r0, 0xC5
	bl EnableInterrupts
	movs r0, 0x2
	bl DisableInterrupts
	b _08086362
	.pool
_08086348:
	ldr r4, =0x04000208
	ldrh r3, [r4]
	strh r0, [r4]
	ldr r2, =0x04000200
	ldrh r1, [r2]
	ldr r0, =0x0000fffd
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4]
_08086362:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808631C

	thumb_func_start SetFieldVBlankCallback
@ void SetFieldVBlankCallback()
SetFieldVBlankCallback: @ 8086380
	push {lr}
	ldr r0, =VBlankCB_Field
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetFieldVBlankCallback

	thumb_func_start VBlankCB_Field
VBlankCB_Field: @ 8086390
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl sub_80BA0A8
	bl FieldUpdateBgTilemapScroll
	bl copy_pal_bg_faded_to_pal_ram
	bl sub_80A09D0
	pop {r0}
	bx r0
	thumb_func_end VBlankCB_Field

	thumb_func_start sub_80863B0
sub_80863B0: @ 80863B0
	push {lr}
	bl sub_81A9E6C
	lsls r0, 24
	cmp r0, 0
	beq _080863D4
	bl door_upload_tiles
	ldr r2, =gUnknown_08339DBC
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80BA038
	b _080863F0
	.pool
_080863D4:
	bl sav1_get_flash_used_on_map
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080863F0
	bl sub_80B00E8
	ldr r2, =gUnknown_08339DBC
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80BA038
_080863F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80863B0

	thumb_func_start map_loading_iteration_3
map_loading_iteration_3: @ 80863F8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0xD
	bls _08086404
	b _08086512
_08086404:
	lsls r0, 2
	ldr r1, =_08086414
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08086414:
	.4byte _0808644C
	.4byte _08086462
	.4byte _0808646A
	.4byte _08086472
	.4byte _08086484
	.4byte _08086492
	.4byte _08086498
	.4byte _080864A8
	.4byte _080864B8
	.4byte _080864D4
	.4byte _080864DA
	.4byte _080864E0
	.4byte _080864FC
	.4byte _0808650E
_0808644C:
	bl overworld_bg_setup
	bl script_env_1_init
	bl script_env_2_disable
	bl saveblock_randomize_and_relocate_
	bl sub_80867D8
	b _08086506
_08086462:
	movs r0, 0x1
	bl mli0_load_map
	b _08086506
_0808646A:
	movs r0, 0x1
	bl sub_8086988
	b _08086506
_08086472:
	bl sub_8086AE4
	bl sub_80869DC
	bl sub_8086B14
	bl sub_8086AAC
	b _08086506
_08086484:
	bl sub_80863B0
	bl map_loading_lcd_reset
	bl sub_8197200
	b _08086506
_08086492:
	bl move_tilemap_camera_to_upper_left_corner
	b _08086506
_08086498:
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl copy_map_tileset1_to_vram
	b _08086506
	.pool
_080864A8:
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl copy_map_tileset2_to_vram
	b _08086506
	.pool
_080864B8:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08086512
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl apply_map_tileset1_tileset2_palette
	b _08086506
	.pool
_080864D4:
	bl DrawWholeMapView
	b _08086506
_080864DA:
	bl cur_mapheader_run_tileset_funcs_after_some_cpuset
	b _08086506
_080864E0:
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086506
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _08086506
	.pool
_080864FC:
	bl map_post_load_hook_exec
	lsls r0, 24
	cmp r0, 0
	beq _08086512
_08086506:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _08086512
_0808650E:
	movs r0, 0x1
	b _08086514
_08086512:
	movs r0, 0
_08086514:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end map_loading_iteration_3

	thumb_func_start load_map_stuff
@ int load_map_stuff(u8 *a1, int a2)
load_map_stuff: @ 808651C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	cmp r0, 0xD
	bls _0808652A
	b _0808662E
_0808652A:
	lsls r0, 2
	ldr r1, =_08086538
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08086538:
	.4byte _08086570
	.4byte _0808657C
	.4byte _08086586
	.4byte _0808658E
	.4byte _08086598
	.4byte _080865A6
	.4byte _080865AC
	.4byte _080865BC
	.4byte _080865CC
	.4byte _080865E8
	.4byte _080865EE
	.4byte _080865F4
	.4byte _08086618
	.4byte _0808662A
_08086570:
	bl sub_808631C
	adds r0, r5, 0
	bl mli0_load_map
	b _08086622
_0808657C:
	bl saveblock_randomize_and_relocate_
	bl sub_80867D8
	b _08086622
_08086586:
	adds r0, r5, 0
	bl sub_8086988
	b _08086622
_0808658E:
	bl mli4_mapscripts_and_other
	bl sub_8086A80
	b _08086622
_08086598:
	bl sub_80863B0
	bl map_loading_lcd_reset
	bl sub_8197200
	b _08086622
_080865A6:
	bl move_tilemap_camera_to_upper_left_corner
	b _08086622
_080865AC:
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl copy_map_tileset1_to_vram
	b _08086622
	.pool
_080865BC:
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl copy_map_tileset2_to_vram
	b _08086622
	.pool
_080865CC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0808662E
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl apply_map_tileset1_tileset2_palette
	b _08086622
	.pool
_080865E8:
	bl DrawWholeMapView
	b _08086622
_080865EE:
	bl cur_mapheader_run_tileset_funcs_after_some_cpuset
	b _08086622
_080865F4:
	ldr r0, =gUnknown_02037318
	ldrb r1, [r0, 0x1A]
	movs r0, 0xF8
	ands r0, r1
	cmp r0, 0x8
	bne _08086622
	bl sub_80E909C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08086622
	bl AddMapNamePopUpWindowTask
	b _08086622
	.pool
_08086618:
	bl map_post_load_hook_exec
	lsls r0, 24
	cmp r0, 0
	beq _0808662E
_08086622:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0808662E
_0808662A:
	movs r0, 0x1
	b _08086630
_0808662E:
	movs r0, 0
_08086630:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end load_map_stuff

	thumb_func_start sub_8086638
sub_8086638: @ 8086638
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x1
	beq _0808666E
	cmp r0, 0x1
	bgt _0808664C
	cmp r0, 0
	beq _08086656
	b _0808668E
_0808664C:
	cmp r0, 0x2
	beq _08086678
	cmp r0, 0x3
	beq _0808668A
	b _0808668E
_08086656:
	bl saveblock_randomize_and_relocate_
	bl sub_80867D8
	movs r0, 0
	bl sub_8086988
	bl sub_8086A68
	bl sub_8086A80
	b _08086682
_0808666E:
	bl sub_8086860
	bl sub_81D64C0
	b _08086682
_08086678:
	bl map_post_load_hook_exec
	lsls r0, 24
	cmp r0, 0
	beq _0808668E
_08086682:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0808668E
_0808668A:
	movs r0, 0x1
	b _08086690
_0808668E:
	movs r0, 0
_08086690:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8086638

	thumb_func_start map_loading_iteration_2_link
map_loading_iteration_2_link: @ 8086698
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0xD
	bls _080866A4
	b _080867A8
_080866A4:
	lsls r0, 2
	ldr r1, =_080866B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080866B4:
	.4byte _080866EC
	.4byte _080866FA
	.4byte _08086702
	.4byte _08086710
	.4byte _0808671E
	.4byte _08086724
	.4byte _08086734
	.4byte _08086744
	.4byte _08086760
	.4byte _08086766
	.4byte _08086792
	.4byte _0808676C
	.4byte _08086788
	.4byte _0808679A
_080866EC:
	bl sub_808631C
	bl saveblock_randomize_and_relocate_
	bl sub_80867D8
	b _08086792
_080866FA:
	movs r0, 0x1
	bl sub_8086988
	b _08086792
_08086702:
	bl sub_8086B9C
	bl sub_8086A68
	bl sub_8086AC8
	b _08086792
_08086710:
	bl sub_80863B0
	bl map_loading_lcd_reset
	bl sub_8197200
	b _08086792
_0808671E:
	bl move_tilemap_camera_to_upper_left_corner
	b _08086792
_08086724:
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl copy_map_tileset1_to_vram
	b _08086792
	.pool
_08086734:
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl copy_map_tileset2_to_vram
	b _08086792
	.pool
_08086744:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080867A8
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	bl apply_map_tileset1_tileset2_palette
	b _08086792
	.pool
_08086760:
	bl DrawWholeMapView
	b _08086792
_08086766:
	bl cur_mapheader_run_tileset_funcs_after_some_cpuset
	b _08086792
_0808676C:
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086792
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _08086792
	.pool
_08086788:
	bl map_post_load_hook_exec
	lsls r0, 24
	cmp r0, 0
	beq _080867A8
_08086792:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _080867A8
_0808679A:
	bl SetFieldVBlankCallback
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	b _080867AA
_080867A8:
	movs r0, 0
_080867AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end map_loading_iteration_2_link

	thumb_func_start do_load_map_stuff_loop
do_load_map_stuff_loop: @ 80867B0
	push {r4,lr}
	adds r4, r0, 0
_080867B4:
	adds r0, r4, 0
	movs r1, 0
	bl load_map_stuff
	cmp r0, 0
	beq _080867B4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end do_load_map_stuff_loop

	thumb_func_start saveblock_randomize_and_relocate_
saveblock_randomize_and_relocate_: @ 80867C8
	push {lr}
	bl sub_81BE6AC
	bl saveblock_randomize_and_relocate
	pop {r0}
	bx r0
	thumb_func_end saveblock_randomize_and_relocate_

	thumb_func_start sub_80867D8
sub_80867D8: @ 80867D8
	push {r4-r7,lr}
	sub sp, 0x4
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	bl remove_some_task
	ldr r2, =0x05000002
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0xC0
	lsls r2, 19
	movs r3, 0xC0
	lsls r3, 9
	mov r4, sp
	movs r6, 0
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_08086816:
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r5
	subs r3, r5
	cmp r3, r5
	bhi _08086816
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x80
	bl ResetSpriteRange
	bl LoadOamFromSprites
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80867D8

	thumb_func_start sub_8086860
sub_8086860: @ 8086860
	push {lr}
	bl sub_80863B0
	bl map_loading_lcd_reset
	bl sub_8197200
	bl mapdata_load_assets_to_gpu_and_full_redraw
	pop {r0}
	bx r0
	thumb_func_end sub_8086860

	thumb_func_start map_loading_lcd_reset
map_loading_lcd_reset: @ 8086878
	push {r4,lr}
	bl clear_scheduled_bg_copies_to_vram
	bl reset_temp_tile_data_buffers
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001f1f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00000101
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0xFF
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0xFF
	bl SetGpuReg
	ldr r4, =0x0000ffff
	movs r0, 0x42
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x46
	adds r1, r4, 0
	bl SetGpuReg
	ldr r0, =gUnknown_82EC7C4
	ldrh r1, [r0, 0x2]
	ldrh r2, [r0, 0x4]
	orrs r1, r2
	ldrh r0, [r0, 0x6]
	orrs r1, r0
	movs r2, 0x82
	lsls r2, 5
	adds r0, r2, 0
	orrs r1, r0
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000070d
	movs r0, 0x52
	bl SetGpuReg
	bl overworld_bg_setup
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
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
	ldr r1, =0x00007060
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl sub_8098128
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end map_loading_lcd_reset

	thumb_func_start sub_8086988
sub_8086988: @ 8086988
	push {r4,lr}
	adds r4, r0, 0
	bl ResetTasks
	bl ResetAllObjectData
	bl sub_80A1A74
	bl dp12_8087EA4
	bl dp13_810BB8C
	bl ResetCameraUpdateInfo
	bl InstallCameraPanAheadCallback
	cmp r4, 0
	bne _080869B4
	movs r0, 0
	bl npc_paltag_set_load
	b _080869BA
_080869B4:
	movs r0, 0x1
	bl npc_paltag_set_load
_080869BA:
	bl FieldEffectActiveListClear
	bl sub_80AAFA4
	bl sub_80AEE84
	cmp r4, 0
	bne _080869CE
	bl overworld_ensure_per_step_coros_running
_080869CE:
	bl mapheader_run_script_with_tag_x5
	bl sub_81BE6B8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8086988

	thumb_func_start sub_80869DC
sub_80869DC: @ 80869DC
	push {lr}
	ldr r0, =gUnknown_03005DEC
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_03005DE8
	strh r1, [r0]
	bl sub_808D438
	movs r0, 0
	movs r1, 0
	bl SpawnFieldObjectsInView
	bl mapheader_run_first_tag4_script_list_match
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80869DC

	thumb_func_start mli4_mapscripts_and_other
mli4_mapscripts_and_other: @ 8086A04
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_03005DEC
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_03005DE8
	strh r1, [r0]
	bl sub_808D438
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sav1_camera_get_focus_coords
	bl sub_80852D4
	adds r5, r0, 0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	ldrb r2, [r5, 0x1]
	ldr r3, =gSaveBlock2Ptr
	ldr r3, [r3]
	ldrb r3, [r3, 0x8]
	bl InitPlayerAvatar
	ldrb r0, [r5]
	bl SetPlayerAvatarTransitionFlags
	bl player_avatar_init_params_reset
	movs r0, 0
	movs r1, 0
	bl SpawnFieldObjectsInView
	bl mapheader_run_first_tag4_script_list_match
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mli4_mapscripts_and_other

	thumb_func_start sub_8086A68
sub_8086A68: @ 8086A68
	push {lr}
	movs r0, 0
	movs r1, 0
	bl sub_808E16C
	bl sub_80FBED0
	bl mapheader_run_script_with_tag_x7
	pop {r0}
	bx r0
	thumb_func_end sub_8086A68

	thumb_func_start sub_8086A80
sub_8086A80: @ 8086A80
	push {lr}
	ldr r2, =gUnknown_02037350
	ldr r3, =gUnknown_02037590
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
	ldrb r0, [r3, 0x4]
	bl InitCameraUpdateCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086A80

	thumb_func_start sub_8086AAC
sub_8086AAC: @ 8086AAC
	push {lr}
	ldr r0, =gUnknown_03005DB4
	ldrb r0, [r0]
	bl sub_8087858
	lsls r0, 24
	lsrs r0, 24
	bl InitCameraUpdateCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086AAC

	thumb_func_start sub_8086AC8
sub_8086AC8: @ 8086AC8
	push {lr}
	ldr r0, =gUnknown_03005DB4
	ldrb r0, [r0]
	bl sub_8087858
	lsls r0, 24
	lsrs r0, 24
	bl InitCameraUpdateCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086AC8

	thumb_func_start sub_8086AE4
sub_8086AE4: @ 8086AE4
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sav1_camera_get_focus_coords
	mov r2, sp
	ldr r0, =gUnknown_03005DB4
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4]
	bl sub_8088B3C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086AE4

	thumb_func_start sub_8086B14
sub_8086B14: @ 8086B14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sav1_camera_get_focus_coords
	mov r3, sp
	mov r2, sp
	ldr r0, =gUnknown_03005DB4
	ldrb r1, [r0]
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r3]
	movs r6, 0
	ldr r0, =gUnknown_03005DB8
	mov r8, r4
	ldrb r0, [r0]
	cmp r6, r0
	bcs _08086B7E
	ldr r7, =gUnknown_020229E8
_08086B44:
	lsls r5, r6, 24
	lsrs r5, 24
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r6, r1
	lsls r1, 16
	asrs r1, 16
	mov r0, r8
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r4, r6, 3
	subs r4, r6
	lsls r4, 2
	adds r4, r7
	ldrb r3, [r4, 0x13]
	adds r0, r5, 0
	bl sub_80876F0
	ldrb r1, [r4]
	adds r0, r5, 0
	bl sub_8087BCC
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_03005DB8
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08086B44
_08086B7E:
	bl sub_8086C40
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086B14

	thumb_func_start sub_8086B9C
sub_8086B9C: @ 8086B9C
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_03005DB8
	ldrb r0, [r0]
	cmp r4, r0
	bcs _08086BCA
	ldr r5, =gUnknown_020229E8
_08086BAA:
	lsls r0, r4, 24
	lsrs r0, 24
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r5
	ldrb r1, [r1]
	bl sub_8087BCC
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gUnknown_03005DB8
	ldrb r0, [r0]
	cmp r4, r0
	bcc _08086BAA
_08086BCA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086B9C

	thumb_func_start c1_link_related
c1_link_related: @ 8086BD8
	push {r4,lr}
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086BF2
	bl sub_800F0B8
	cmp r0, 0
	beq _08086BF2
	bl sub_8009F3C
	cmp r0, 0
	bne _08086C14
_08086BF2:
	ldr r0, =gUnknown_03005DB4
	ldrb r4, [r0]
	ldr r0, =gUnknown_03003020
	adds r1, r4, 0
	bl sub_8086F38
	ldr r0, =gUnknown_03000E14
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 16
	lsrs r0, 16
	bl sub_8086FA0
	bl sub_8086C40
_08086C14:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c1_link_related

	thumb_func_start sub_8086C2C
sub_8086C2C: @ 8086C2C
	push {lr}
	bl sub_8086C90
	ldr r0, =sub_80870B0
	bl c1_link_related_func_set
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086C2C

	thumb_func_start sub_8086C40
sub_8086C40: @ 8086C40
	push {lr}
	ldr r0, =gUnknown_03003020
	bl sub_808709C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086C40

	thumb_func_start c1_link_related_func_set
c1_link_related_func_set: @ 8086C50
	ldr r2, =gUnknown_03000E19
	movs r1, 0
	strb r1, [r2]
	ldr r1, =gUnknown_03000E14
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end c1_link_related_func_set

	thumb_func_start sub_8086C64
sub_8086C64: @ 8086C64
	push {lr}
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086C82
	ldr r1, =gUnknown_03000E19
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3C
	bls _08086C82
	bl sub_8010198
_08086C82:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086C64

	thumb_func_start sub_8086C90
sub_8086C90: @ 8086C90
	push {lr}
	ldr r1, =gUnknown_03000E10
	movs r2, 0x80
	adds r0, r1, 0x3
_08086C98:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08086C98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086C90

	thumb_func_start sub_8086CA8
sub_8086CA8: @ 8086CA8
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_03005DB8
	ldrb r2, [r0]
	movs r1, 0
	cmp r1, r2
	bge _08086CD6
	ldr r4, =gUnknown_03000E10
_08086CBA:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r3
	beq _08086CD0
	movs r0, 0
	b _08086CD8
	.pool
_08086CD0:
	adds r1, 0x1
	cmp r1, r2
	blt _08086CBA
_08086CD6:
	movs r0, 0x1
_08086CD8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8086CA8

	thumb_func_start sub_8086CE0
sub_8086CE0: @ 8086CE0
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_03005DB8
	ldrb r2, [r0]
	movs r1, 0
	cmp r1, r2
	bge _08086D0E
	ldr r4, =gUnknown_03000E10
_08086CF2:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r3
	bne _08086D08
	movs r0, 0x1
	b _08086D10
	.pool
_08086D08:
	adds r1, 0x1
	cmp r1, r2
	blt _08086CF2
_08086D0E:
	movs r0, 0
_08086D10:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8086CE0

	thumb_func_start sub_8086D18
sub_8086D18: @ 8086D18
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r6, r2, 0
	mov r9, r3
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	ldr r0, =gUnknown_03000E10
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, 0x80
	beq _08086D38
	b _08086EB2
_08086D38:
	adds r0, r6, 0
	bl sub_8087370
	adds r4, r0, 0
	cmp r4, 0
	beq _08086D70
	bl sub_8087480
	mov r1, r9
	strh r0, [r1]
	movs r0, 0x81
	strb r0, [r5]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	bne _08086D58
	b _08086F26
_08086D58:
	ldr r0, =sub_80870F8
	bl c1_link_related_func_set
	adds r0, r4, 0
	bl sub_8087530
	b _08086F26
	.pool
_08086D70:
	movs r0, 0x83
	bl sub_8086CE0
	cmp r0, 0x1
	bne _08086D98
	movs r0, 0x81
	strb r0, [r5]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	bne _08086D86
	b _08086F26
_08086D86:
	ldr r0, =sub_80870F8
	bl c1_link_related_func_set
	bl sub_8087584
	b _08086F26
	.pool
_08086D98:
	mov r0, r8
	subs r0, 0x12
	cmp r0, 0xA
	bls _08086DA2
	b _08086EB2
_08086DA2:
	lsls r0, 2
	ldr r1, =_08086DB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08086DB0:
	.4byte _08086E08
	.4byte _08086EB2
	.4byte _08086EB2
	.4byte _08086EB2
	.4byte _08086EB2
	.4byte _08086EB2
	.4byte _08086DDC
	.4byte _08086E34
	.4byte _08086EB2
	.4byte _08086E64
	.4byte _08086E90
_08086DDC:
	adds r0, r6, 0
	bl sub_8087358
	cmp r0, 0
	beq _08086EB2
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x81
	strb r1, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08086EB2
	ldr r0, =sub_80870F8
	bl c1_link_related_func_set
	bl sub_808751C
	b _08086EB2
	.pool
_08086E08:
	adds r0, r6, 0
	bl sub_8087388
	cmp r0, 0x1
	bne _08086EB2
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x81
	strb r1, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08086EB2
	ldr r0, =sub_80870F8
	bl c1_link_related_func_set
	bl sub_808754C
	b _08086EB2
	.pool
_08086E34:
	adds r0, r6, 0
	bl sub_80873B4
	adds r4, r0, 0
	cmp r4, 0
	beq _08086EB2
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x81
	strb r1, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08086EB2
	ldr r0, =sub_80870F8
	bl c1_link_related_func_set
	adds r0, r4, 0
	bl sub_8087568
	b _08086EB2
	.pool
_08086E64:
	adds r0, r6, 0
	bl sub_8087340
	cmp r0, 0
	beq _08086EB2
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x81
	strb r1, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08086EB2
	ldr r0, =sub_808711C
	bl c1_link_related_func_set
	bl sub_8087510
	b _08086EB2
	.pool
_08086E90:
	adds r0, r6, 0
	bl sub_8087340
	cmp r0, 0
	beq _08086EB2
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x81
	strb r1, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08086EB2
	ldr r0, =sub_8087140
	bl c1_link_related_func_set
	bl sub_8087510
_08086EB2:
	mov r0, r8
	cmp r0, 0x17
	beq _08086ED8
	cmp r0, 0x17
	bgt _08086ECC
	cmp r0, 0x16
	beq _08086EE8
	b _08086F26
	.pool
_08086ECC:
	mov r1, r8
	cmp r1, 0x1A
	beq _08086EF8
	cmp r1, 0x1D
	beq _08086F18
	b _08086F26
_08086ED8:
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x83
	strb r1, [r0]
	b _08086F26
	.pool
_08086EE8:
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x82
	strb r1, [r0]
	b _08086F26
	.pool
_08086EF8:
	ldr r0, =gUnknown_03000E10
	adds r0, r7, r0
	movs r1, 0x80
	strb r1, [r0]
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08086F26
	ldr r0, =sub_80870B0
	bl c1_link_related_func_set
	b _08086F26
	.pool
_08086F18:
	ldr r0, =gUnknown_03000E10
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, 0x82
	bne _08086F26
	movs r0, 0x81
	strb r0, [r1]
_08086F26:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086D18

	thumb_func_start sub_8086F38
sub_8086F38: @ 8086F38
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r8, r1
	movs r6, 0
	add r5, sp, 0x10
	mov r9, r5
	adds r7, r0, 0
_08086F4C:
	ldrb r4, [r7]
	movs r0, 0
	strh r0, [r5]
	adds r0, r6, 0
	mov r1, r8
	mov r2, sp
	bl sub_80872D8
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	adds r3, r5, 0
	bl sub_8086D18
	ldr r0, =gUnknown_03000E10
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _08086F7C
	adds r0, r4, 0
	bl sub_8087068
	mov r1, r9
	strh r0, [r1]
_08086F7C:
	lsls r0, r6, 24
	lsrs r0, 24
	ldrb r1, [r5]
	bl sub_808796C
	adds r7, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08086F4C
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086F38

	thumb_func_start sub_8086FA0
sub_8086FA0: @ 8086FA0
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r1, =0xffef0000
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0xC
	bhi _08086FC0
	ldr r0, =gUnknown_03005DA8
	strh r4, [r0]
	b _08086FC6
	.pool
_08086FC0:
	ldr r1, =gUnknown_03005DA8
	movs r0, 0x11
	strh r0, [r1]
_08086FC6:
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08086FFC
	bl sub_8087690
	cmp r0, 0x1
	bls _08086FFC
	bl is_c1_link_related_active
	cmp r0, 0x1
	bne _08086FFC
	bl sub_8009F3C
	cmp r0, 0x1
	bne _08086FFC
	cmp r4, 0x11
	blt _08086FFC
	cmp r4, 0x15
	ble _08086FF6
	cmp r4, 0x19
	bgt _08086FFC
	cmp r4, 0x18
	blt _08086FFC
_08086FF6:
	ldr r1, =gUnknown_03005DA8
	movs r0, 0
	strh r0, [r1]
_08086FFC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8086FA0

	thumb_func_start sub_808700C
sub_808700C: @ 808700C
	push {lr}
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08087024
	movs r0, 0x13
	b _08087064
	.pool
_08087024:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08087030
	movs r0, 0x12
	b _08087064
_08087030:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0808703C
	movs r0, 0x14
	b _08087064
_0808703C:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08087048
	movs r0, 0x15
	b _08087064
_08087048:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08087056
	movs r0, 0x18
	b _08087064
_08087056:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08087062
	movs r0, 0x11
	b _08087064
_08087062:
	movs r0, 0x19
_08087064:
	pop {r1}
	bx r1
	thumb_func_end sub_808700C

	thumb_func_start sub_8087068
sub_8087068: @ 8087068
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x13
	beq _0808708E
	cmp r0, 0x13
	bgt _0808707E
	cmp r0, 0x12
	beq _08087092
	b _08087096
_0808707E:
	cmp r1, 0x14
	beq _0808708A
	cmp r1, 0x15
	bne _08087096
	movs r0, 0x4
	b _08087098
_0808708A:
	movs r0, 0x3
	b _08087098
_0808708E:
	movs r0, 0x1
	b _08087098
_08087092:
	movs r0, 0x2
	b _08087098
_08087096:
	movs r0, 0
_08087098:
	pop {r1}
	bx r1
	thumb_func_end sub_8087068

	thumb_func_start sub_808709C
sub_808709C: @ 808709C
	push {lr}
	movs r2, 0x11
	adds r1, r0, 0x6
_080870A2:
	strh r2, [r1]
	subs r1, 0x2
	cmp r1, r0
	bge _080870A2
	pop {r0}
	bx r0
	thumb_func_end sub_808709C

	thumb_func_start sub_80870B0
sub_80870B0: @ 80870B0
	push {r4,lr}
	adds r4, r0, 0
	bl script_env_2_is_enabled
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080870C4
	movs r0, 0x11
	b _080870E6
_080870C4:
	bl sub_800B4DC
	cmp r0, 0x4
	bls _080870D0
	movs r0, 0x1B
	b _080870E6
_080870D0:
	bl sub_8087690
	cmp r0, 0x4
	bls _080870DC
	movs r0, 0x1C
	b _080870E6
_080870DC:
	adds r0, r4, 0
	bl sub_808700C
	lsls r0, 16
	lsrs r0, 16
_080870E6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80870B0

	thumb_func_start sub_80870EC
sub_80870EC: @ 80870EC
	push {lr}
	bl sub_8086C64
	movs r0, 0x11
	pop {r1}
	bx r1
	thumb_func_end sub_80870EC

	thumb_func_start sub_80870F8
sub_80870F8: @ 80870F8
	push {r4,lr}
	bl script_env_2_is_enabled
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0x11
	cmp r0, 0x1
	beq _08087110
	movs r4, 0x1A
	ldr r0, =sub_80870EC
	bl c1_link_related_func_set
_08087110:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80870F8

	thumb_func_start sub_808711C
sub_808711C: @ 808711C
	push {r4,lr}
	bl sub_800B4DC
	movs r4, 0x11
	cmp r0, 0x2
	bhi _08087134
	movs r4, 0x1A
	bl script_env_2_disable
	ldr r0, =sub_80870EC
	bl c1_link_related_func_set
_08087134:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808711C

	thumb_func_start sub_8087140
sub_8087140: @ 8087140
	push {r4,lr}
	bl sub_8087690
	movs r4, 0x11
	cmp r0, 0x2
	bhi _08087158
	movs r4, 0x1A
	bl script_env_2_disable
	ldr r0, =sub_80870EC
	bl c1_link_related_func_set
_08087158:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8087140

	thumb_func_start sub_8087164
sub_8087164: @ 8087164
	push {lr}
	bl sub_8086C64
	movs r0, 0x11
	pop {r1}
	bx r1
	thumb_func_end sub_8087164

	thumb_func_start sub_8087170
sub_8087170: @ 8087170
	push {lr}
	ldr r1, =gUnknown_03000E10
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x82
	bne _080871A0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080871A4
	ldr r0, =sub_8087164
	bl c1_link_related_func_set
	movs r0, 0x1D
	b _080871A6
	.pool
_080871A0:
	bl sub_8086C64
_080871A4:
	movs r0, 0x11
_080871A6:
	pop {r1}
	bx r1
	thumb_func_end sub_8087170

	thumb_func_start sub_80871AC
sub_80871AC: @ 80871AC
	push {lr}
	ldr r0, =sub_8087170
	bl c1_link_related_func_set
	movs r0, 0x16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80871AC

	thumb_func_start sub_80871C0
sub_80871C0: @ 80871C0
	movs r0, 0x11
	bx lr
	thumb_func_end sub_80871C0

	thumb_func_start sub_80871C4
sub_80871C4: @ 80871C4
	push {lr}
	ldr r1, =gUnknown_03000E10
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x83
	beq _080871D4
	bl sub_8086C64
_080871D4:
	movs r0, 0x83
	bl sub_8086CA8
	cmp r0, 0x1
	bne _080871EA
	ldr r0, =gUnknown_08277513
	bl script_env_1_execute_new_script
	ldr r0, =sub_80871C0
	bl c1_link_related_func_set
_080871EA:
	movs r0, 0x11
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80871C4

	thumb_func_start sub_80871FC
sub_80871FC: @ 80871FC
	push {lr}
	ldr r0, =sub_80871C4
	bl c1_link_related_func_set
	movs r0, 0x17
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80871FC

	thumb_func_start sub_8087210
sub_8087210: @ 8087210
	movs r0, 0x11
	bx lr
	thumb_func_end sub_8087210

	thumb_func_start sub_8087214
sub_8087214: @ 8087214
	push {lr}
	movs r0, 0x83
	bl sub_8086CE0
	cmp r0, 0x1
	beq _08087250
	ldr r0, =gUnknown_03000E14
	ldr r2, [r0]
	ldr r1, =sub_8087170
	adds r3, r0, 0
	cmp r2, r1
	bne _0808723A
	ldr r1, =gUnknown_03000E10
	ldr r0, =gUnknown_03005DB4
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x82
	bne _08087272
_0808723A:
	ldr r1, [r3]
	ldr r0, =sub_8087164
	cmp r1, r0
	bne _08087268
	ldr r1, =gUnknown_03000E10
	ldr r0, =gUnknown_03005DB4
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x81
	bne _08087268
_08087250:
	movs r0, 0x2
	b _08087278
	.pool
_08087268:
	movs r0, 0x82
	bl sub_8086CA8
	cmp r0, 0
	bne _08087276
_08087272:
	movs r0, 0
	b _08087278
_08087276:
	movs r0, 0x1
_08087278:
	pop {r1}
	bx r1
	thumb_func_end sub_8087214

	thumb_func_start sub_808727C
sub_808727C: @ 808727C
	push {lr}
	movs r0, 0x83
	bl sub_8086CE0
	pop {r1}
	bx r1
	thumb_func_end sub_808727C

	thumb_func_start sub_8087288
sub_8087288: @ 8087288
	push {lr}
	ldr r0, =sub_80871AC
	bl c1_link_related_func_set
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8087288

	thumb_func_start sub_808729C
sub_808729C: @ 808729C
	push {lr}
	ldr r0, =sub_80870F8
	bl c1_link_related_func_set
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808729C

	thumb_func_start sub_80872B0
sub_80872B0: @ 80872B0
	push {lr}
	ldr r0, =sub_80871FC
	bl c1_link_related_func_set
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80872B0

	thumb_func_start sub_80872C4
sub_80872C4: @ 80872C4
	push {lr}
	ldr r0, =sub_8087210
	bl c1_link_related_func_set
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80872C4

	thumb_func_start sub_80872D8
sub_80872D8: @ 80872D8
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r2, 0
	strb r4, [r6]
	movs r0, 0
	cmp r4, r1
	bne _080872EA
	movs r0, 0x1
_080872EA:
	strb r0, [r6, 0x1]
	ldr r1, =gUnknown_02032308
	lsls r0, r4, 2
	adds r0, r1
	ldrb r0, [r0, 0x3]
	strb r0, [r6, 0x2]
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80878A0
	strb r0, [r6, 0x3]
	mov r5, sp
	adds r5, 0x2
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_8087878
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6, 0x4]
	ldrh r0, [r5]
	strh r0, [r6, 0x6]
	adds r0, r4, 0
	bl sub_80878C0
	strb r0, [r6, 0x8]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	strh r0, [r6, 0xC]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80872D8

	thumb_func_start sub_8087340
sub_8087340: @ 8087340
	push {lr}
	ldrb r0, [r0, 0x2]
	cmp r0, 0x2
	beq _0808734C
	cmp r0, 0
	bne _08087350
_0808734C:
	movs r0, 0x1
	b _08087352
_08087350:
	movs r0, 0
_08087352:
	pop {r1}
	bx r1
	thumb_func_end sub_8087340

	thumb_func_start sub_8087358
sub_8087358: @ 8087358
	push {lr}
	ldrb r0, [r0, 0x2]
	cmp r0, 0x2
	beq _08087364
	cmp r0, 0
	bne _08087368
_08087364:
	movs r0, 0x1
	b _0808736A
_08087368:
	movs r0, 0
_0808736A:
	pop {r1}
	bx r1
	thumb_func_end sub_8087358

	thumb_func_start sub_8087370
sub_8087370: @ 8087370
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0x2
	bne _08087382
	adds r0, r1, 0x4
	bl sub_809D0F4
	b _08087384
_08087382:
	movs r0, 0
_08087384:
	pop {r1}
	bx r1
	thumb_func_end sub_8087370

	thumb_func_start sub_8087388
sub_8087388: @ 8087388
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _08087396
	cmp r0, 0
	bne _080873AC
_08087396:
	ldrb r0, [r4, 0xC]
	bl MetatileBehavior_IsSouthArrowWarp
	lsls r0, 24
	cmp r0, 0
	beq _080873AC
	ldrb r0, [r4, 0x3]
	cmp r0, 0x1
	bne _080873AC
	movs r0, 0x1
	b _080873AE
_080873AC:
	movs r0, 0
_080873AE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8087388

	thumb_func_start sub_80873B4
sub_80873B4: @ 80873B4
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080873C8
	cmp r0, 0x2
	beq _080873C8
	movs r0, 0
	b _08087476
_080873C8:
	ldr r0, [r4, 0x4]
	ldr r1, [r4, 0x8]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r3, =gUnknown_08339D64
	ldrb r0, [r4, 0x3]
	lsls r0, 3
	adds r0, r3
	ldr r0, [r0]
	mov r1, sp
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0xffff0000
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	asrs r1, r2, 16
	ldrb r0, [r4, 0x3]
	lsls r0, 3
	adds r3, 0x4
	adds r0, r3
	ldr r0, [r0]
	adds r0, r1
	lsls r0, 16
	ldr r1, =0x0000ffff
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r2, =0xffffff00
	ldr r0, [sp, 0x4]
	ands r0, r2
	str r0, [sp, 0x4]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl sub_808790C
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	cmp r1, 0x4
	beq _0808746C
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08087434
	ldr r0, =gUnknown_03000E10
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x80
	beq _08087450
_08087434:
	ldr r0, =gUnknown_0827749C
	b _08087476
	.pool
_08087450:
	adds r0, r2, 0
	bl sub_80B39D4
	cmp r0, 0
	bne _08087464
	ldr r0, =gUnknown_0827747E
	b _08087476
	.pool
_08087464:
	ldr r0, =gUnknown_0827748D
	b _08087476
	.pool
_0808746C:
	ldrb r1, [r4, 0xC]
	ldrb r2, [r4, 0x3]
	mov r0, sp
	bl sub_809C2C8
_08087476:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80873B4

	thumb_func_start sub_8087480
sub_8087480: @ 8087480
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_08277388
	cmp r1, r0
	beq _080874C6
	ldr r0, =gUnknown_082773A3
	cmp r1, r0
	beq _08087508
	ldr r0, =gUnknown_082773BE
	cmp r1, r0
	beq _080874C6
	ldr r0, =gUnknown_082773D9
	cmp r1, r0
	beq _08087508
	ldr r0, =gUnknown_0827741D
	cmp r1, r0
	beq _080874C6
	ldr r0, =gUnknown_08277432
	cmp r1, r0
	beq _08087508
	ldr r0, =gUnknown_08277447
	cmp r1, r0
	beq _080874C6
	ldr r0, =gUnknown_0827745C
	cmp r1, r0
	beq _08087508
	ldr r0, =gUnknown_08277374
	cmp r1, r0
	beq _080874C6
	ldr r0, =gUnknown_0827737E
	cmp r1, r0
	beq _08087508
	ldr r0, =gUnknown_082773F5
	cmp r1, r0
	bne _080874F8
_080874C6:
	movs r0, 0xA
	b _0808750A
	.pool
_080874F8:
	ldr r0, =gUnknown_082773FF
	cmp r1, r0
	beq _08087508
	movs r0, 0
	b _0808750A
	.pool
_08087508:
	movs r0, 0x9
_0808750A:
	pop {r1}
	bx r1
	thumb_func_end sub_8087480

	thumb_func_start sub_8087510
sub_8087510: @ 8087510
	push {lr}
	bl script_env_2_enable
	pop {r0}
	bx r0
	thumb_func_end sub_8087510

	thumb_func_start sub_808751C
sub_808751C: @ 808751C
	push {lr}
	movs r0, 0x6
	bl audio_play
	bl sub_809FA9C
	bl script_env_2_enable
	pop {r0}
	bx r0
	thumb_func_end sub_808751C

	thumb_func_start sub_8087530
sub_8087530: @ 8087530
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl script_env_1_execute_new_script
	bl script_env_2_enable
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8087530

	thumb_func_start sub_808754C
sub_808754C: @ 808754C
	push {lr}
	movs r0, 0x6
	bl audio_play
	ldr r0, =gUnknown_082774EF
	bl script_env_1_execute_new_script
	bl script_env_2_enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808754C

	thumb_func_start sub_8087568
sub_8087568: @ 8087568
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl audio_play
	adds r0, r4, 0
	bl script_env_1_execute_new_script
	bl script_env_2_enable
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8087568

	thumb_func_start sub_8087584
sub_8087584: @ 8087584
	push {lr}
	ldr r0, =gUnknown_08277509
	bl script_env_1_execute_new_script
	bl script_env_2_enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8087584

	thumb_func_start sub_8087598
sub_8087598: @ 8087598
	push {lr}
	bl is_c1_link_related_active
	cmp r0, 0
	bne _080875A6
	movs r0, 0
	b _080875C0
_080875A6:
	bl sub_800B4DC
	cmp r0, 0x2
	bls _080875B8
	ldr r1, =gUnknown_03000E18
	movs r0, 0x1
	b _080875BC
	.pool
_080875B8:
	ldr r1, =gUnknown_03000E18
	movs r0, 0
_080875BC:
	strb r0, [r1]
	ldrb r0, [r1]
_080875C0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8087598

	thumb_func_start sub_80875C8
sub_80875C8: @ 80875C8
	push {lr}
	bl sub_800B4DC
	cmp r0, 0x1
	bls _0808762C
	bl is_c1_link_related_active
	cmp r0, 0x1
	bne _0808762C
	bl sub_8009F3C
	cmp r0, 0x1
	bne _0808762C
	ldr r0, =gUnknown_03000E14
	ldr r1, [r0]
	ldr r0, =sub_808711C
	cmp r1, r0
	beq _08087614
	ldr r0, =sub_80870F8
	cmp r1, r0
	bne _0808762C
	ldr r0, =gUnknown_03000E18
	ldrb r2, [r0]
	movs r1, 0
	strb r1, [r0]
	cmp r2, 0x1
	beq _08087614
	ldr r2, =gUnknown_02037FD4
	ldrb r1, [r2, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0808762C
	ldrb r1, [r2, 0xA]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0808762C
_08087614:
	movs r0, 0x1
	b _0808762E
	.pool
_0808762C:
	movs r0, 0
_0808762E:
	pop {r1}
	bx r1
	thumb_func_end sub_80875C8

	thumb_func_start sub_8087634
sub_8087634: @ 8087634
	push {lr}
	bl sub_8087690
	cmp r0, 0x1
	bls _08087658
	bl is_c1_link_related_active
	cmp r0, 0x1
	bne _08087658
	bl sub_8009F3C
	cmp r0, 0x1
	bne _08087658
	ldr r0, =gUnknown_03000E14
	ldr r1, [r0]
	ldr r0, =sub_8087140
	cmp r1, r0
	beq _08087664
_08087658:
	movs r0, 0
	b _08087666
	.pool
_08087664:
	movs r0, 0x1
_08087666:
	pop {r1}
	bx r1
	thumb_func_end sub_8087634

	thumb_func_start sub_808766C
sub_808766C: @ 808766C
	push {lr}
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	bne _08087688
	bl sub_8009F3C
	cmp r0, 0
	beq _08087688
	movs r0, 0x1
	b _0808768A
	.pool
_08087688:
	movs r0, 0
_0808768A:
	pop {r1}
	bx r1
	thumb_func_end sub_808766C

	thumb_func_start sub_8087690
sub_8087690: @ 8087690
	push {lr}
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080876B0
	ldr r0, =gUnknown_03003170
	ldr r1, =0x00000339
	adds r0, r1
	ldrb r0, [r0]
	b _080876B8
	.pool
_080876B0:
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c1a
	adds r0, r1
	ldrb r0, [r0]
_080876B8:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8087690

	thumb_func_start sub_80876C4
sub_80876C4: @ 80876C4
	movs r1, 0
	str r1, [r0]
	bx lr
	thumb_func_end sub_80876C4

	thumb_func_start strange_npc_table_clear
strange_npc_table_clear: @ 80876CC
	push {lr}
	ldr r0, =gUnknown_02032308
	movs r1, 0
	movs r2, 0x10
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end strange_npc_table_clear

	thumb_func_start sub_80876E0
sub_80876E0: @ 80876E0
	push {lr}
	movs r1, 0
	movs r2, 0x24
	bl memset
	pop {r0}
	bx r0
	thumb_func_end sub_80876E0

	thumb_func_start sub_80876F0
sub_80876F0: @ 80876F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r1
	mov r10, r2
	mov r8, r3
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, r9
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	mov r1, r10
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	mov r2, r8
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	bl sub_808D4F4
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r4, r7, 2
	ldr r0, =gUnknown_02032308
	adds r4, r0
	lsls r5, r6, 3
	adds r5, r6
	lsls r5, 2
	ldr r0, =gUnknown_02037350
	adds r5, r0
	adds r0, r4, 0
	bl sub_80876C4
	adds r0, r5, 0
	bl sub_80876E0
	movs r2, 0
	movs r1, 0x1
	movs r0, 0x1
	strb r0, [r4]
	strb r7, [r4, 0x1]
	strb r6, [r4, 0x2]
	strb r2, [r4, 0x3]
	ldrb r0, [r5]
	orrs r0, r1
	mov r2, r8
	ands r2, r1
	lsls r2, 1
	movs r1, 0x3
	negs r1, r1
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, 0x19]
	movs r0, 0x40
	strb r0, [r5, 0x4]
	mov r0, r9
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	mov r1, r10
	lsls r1, 16
	asrs r1, 16
	mov r10, r1
	adds r0, r5, 0
	mov r1, r9
	mov r2, r10
	bl sub_808779C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80876F0

	thumb_func_start sub_808779C
sub_808779C: @ 808779C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	strh r0, [r4, 0x10]
	strh r1, [r4, 0x12]
	strh r0, [r4, 0x14]
	strh r1, [r4, 0x16]
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	adds r2, r4, 0
	adds r2, 0xC
	adds r3, r4, 0
	adds r3, 0xE
	bl sub_8093038
	ldrh r0, [r4, 0xC]
	adds r0, 0x8
	strh r0, [r4, 0xC]
	adds r0, r4, 0
	bl FieldObjectUpdateZCoord
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_808779C

	thumb_func_start sub_80877DC
sub_80877DC: @ 80877DC
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	ldr r1, =gUnknown_02032308
	lsrs r0, 22
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	beq _080877FE
	ldrb r0, [r1, 0x2]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r1, r0
	strb r2, [r1, 0x19]
_080877FE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80877DC

	thumb_func_start sub_808780C
sub_808780C: @ 808780C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 22
	ldr r1, =gUnknown_02032308
	adds r5, r0, r1
	ldrb r1, [r5, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0x40
	beq _08087838
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
_08087838:
	movs r0, 0
	strb r0, [r5]
	ldrb r1, [r4]
	subs r0, 0x2
	ands r0, r1
	strb r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808780C

	thumb_func_start sub_8087858
sub_8087858: @ 8087858
	lsls r0, 24
	ldr r1, =gUnknown_02032308
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	ldrb r0, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_8087858

	thumb_func_start sub_8087878
sub_8087878: @ 8087878
	lsls r0, 24
	ldr r3, =gUnknown_02032308
	lsrs r0, 22
	adds r0, r3
	ldrb r3, [r0, 0x2]
	lsls r0, r3, 3
	adds r0, r3
	lsls r0, 2
	ldr r3, =gUnknown_02037350
	adds r0, r3
	ldrh r3, [r0, 0x10]
	strh r3, [r1]
	ldrh r0, [r0, 0x12]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8087878

	thumb_func_start sub_80878A0
sub_80878A0: @ 80878A0
	lsls r0, 24
	ldr r1, =gUnknown_02032308
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	ldrb r0, [r0, 0x19]
	bx lr
	.pool
	thumb_func_end sub_80878A0

	thumb_func_start sub_80878C0
sub_80878C0: @ 80878C0
	lsls r0, 24
	ldr r1, =gUnknown_02032308
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	ldrb r0, [r0, 0xB]
	lsls r0, 28
	lsrs r0, 28
	bx lr
	.pool
	thumb_func_end sub_80878C0

	thumb_func_start sub_80878E4
sub_80878E4: @ 80878E4
	lsls r0, 24
	ldr r1, =gUnknown_02032308
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	adds r0, 0x21
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x10
	subs r0, r1
	bx lr
	.pool
	thumb_func_end sub_80878E4

	thumb_func_start sub_808790C
sub_808790C: @ 808790C
	push {r4-r6,lr}
	movs r2, 0
	ldr r5, =gUnknown_02032308
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
_0808791A:
	lsls r0, r2, 2
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0
	beq _08087958
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0808792E
	cmp r0, 0x2
	bne _08087958
_0808792E:
	ldrb r1, [r1, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r1, r0, r1
	movs r6, 0x10
	ldrsh r0, [r1, r6]
	cmp r0, r4
	bne _08087958
	movs r6, 0x12
	ldrsh r0, [r1, r6]
	cmp r0, r3
	bne _08087958
	adds r0, r2, 0
	b _08087964
	.pool
_08087958:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0808791A
	movs r0, 0x4
_08087964:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808790C

	thumb_func_start sub_808796C
sub_808796C: @ 808796C
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	adds r2, r3, 0
	lsrs r0, 22
	ldr r1, =gUnknown_02032308
	adds r5, r0, r1
	ldrb r1, [r5, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r6, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _080879C8
	cmp r3, 0xA
	bls _080879A4
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6]
	b _080879C8
	.pool
_080879A4:
	ldr r4, =gUnknown_08339E00
	ldr r1, =gUnknown_08339DC8
	ldrb r0, [r5, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl _call_via_r3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl _call_via_r2
_080879C8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808796C

	thumb_func_start sub_80879D8
sub_80879D8: @ 80879D8
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	ldr r4, =gUnknown_08339DD4
	lsls r3, r2, 2
	adds r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80879D8

	thumb_func_start sub_80879F8
sub_80879F8: @ 80879F8
	movs r0, 0x1
	bx lr
	thumb_func_end sub_80879F8

	thumb_func_start sub_80879FC
sub_80879FC: @ 80879FC
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	ldr r4, =gUnknown_08339DD4
	lsls r3, r2, 2
	adds r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80879FC

	thumb_func_start sub_8087A1C
sub_8087A1C: @ 8087A1C
	movs r0, 0
	bx lr
	thumb_func_end sub_8087A1C

	thumb_func_start sub_8087A20
sub_8087A20: @ 8087A20
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r0, r2, 24
	lsrs r0, 24
	ldrb r1, [r5, 0x19]
	bl npc_something3
	strb r0, [r5, 0x19]
	ldrb r1, [r5, 0x19]
	mov r6, sp
	adds r6, 0x2
	adds r0, r5, 0
	mov r2, sp
	adds r3, r6, 0
	bl FieldObjectMoveDestCoords
	ldrb r0, [r4, 0x2]
	ldrb r1, [r5, 0x19]
	mov r2, sp
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r4, 0
	ldrsh r3, [r6, r4]
	bl npc_080587EC
	lsls r0, 24
	cmp r0, 0
	bne _08087A7E
	adds r1, r5, 0
	adds r1, 0x21
	movs r0, 0x10
	strb r0, [r1]
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0
	ldrsh r2, [r6, r3]
	adds r0, r5, 0
	bl npc_coords_shift
	adds r0, r5, 0
	bl FieldObjectUpdateZCoord
	movs r0, 0x1
	b _08087A80
_08087A7E:
	movs r0, 0
_08087A80:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8087A20

	thumb_func_start sub_8087A88
sub_8087A88: @ 8087A88
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, r2, 24
	lsrs r0, 24
	ldrb r1, [r4, 0x19]
	bl npc_something3
	strb r0, [r4, 0x19]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8087A88

	thumb_func_start sub_8087AA0
sub_8087AA0: @ 8087AA0
	movs r1, 0
	strb r1, [r0, 0x3]
	bx lr
	thumb_func_end sub_8087AA0

	thumb_func_start sub_8087AA8
sub_8087AA8: @ 8087AA8
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r4, 0
	adds r5, 0x21
	ldrb r0, [r5]
	subs r0, 0x1
	strb r0, [r5]
	movs r0, 0x1
	strb r0, [r6, 0x3]
	ldrb r0, [r4, 0x19]
	adds r1, 0xC
	adds r2, r4, 0
	adds r2, 0xE
	bl MoveCoords
	ldrb r0, [r5]
	cmp r0, 0
	bne _08087AD8
	adds r0, r4, 0
	bl npc_coords_shift_still
	movs r0, 0x2
	strb r0, [r6, 0x3]
_08087AD8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8087AA8

	thumb_func_start npc_something3
npc_something3: @ 8087AE0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	subs r0, 0x1
	cmp r0, 0x9
	bhi _08087B38
	lsls r0, 2
	ldr r1, =_08087B00
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08087B00:
	.4byte _08087B28
	.4byte _08087B2C
	.4byte _08087B30
	.4byte _08087B34
	.4byte _08087B38
	.4byte _08087B38
	.4byte _08087B28
	.4byte _08087B2C
	.4byte _08087B30
	.4byte _08087B34
_08087B28:
	movs r0, 0x2
	b _08087B3A
_08087B2C:
	movs r0, 0x1
	b _08087B3A
_08087B30:
	movs r0, 0x3
	b _08087B3A
_08087B34:
	movs r0, 0x4
	b _08087B3A
_08087B38:
	adds r0, r2, 0
_08087B3A:
	pop {r1}
	bx r1
	thumb_func_end npc_something3

	thumb_func_start npc_080587EC
npc_080587EC: @ 8087B40
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r2, 16
	lsrs r2, 16
	mov r12, r2
	lsls r3, 16
	movs r4, 0
	ldr r0, =gUnknown_02037350
	mov r9, r0
	lsrs r2, r3, 16
	mov r10, r2
	asrs r6, r3, 16
_08087B64:
	mov r7, r12
	lsls r3, r7, 16
	mov r0, r10
	lsls r5, r0, 16
	cmp r4, r8
	beq _08087BA8
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	mov r2, r9
	adds r1, r0, r2
	movs r7, 0x10
	ldrsh r0, [r1, r7]
	asrs r2, r3, 16
	cmp r0, r2
	bne _08087B8C
	movs r7, 0x12
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _08087B9E
_08087B8C:
	movs r7, 0x14
	ldrsh r0, [r1, r7]
	cmp r0, r2
	bne _08087BA8
	movs r0, 0x16
	ldrsh r1, [r1, r0]
	asrs r0, r5, 16
	cmp r1, r0
	bne _08087BA8
_08087B9E:
	movs r0, 0x1
	b _08087BBE
	.pool
_08087BA8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08087B64
	asrs r0, r3, 16
	asrs r1, r5, 16
	bl MapGridIsImpassableAt
	lsls r0, 24
	lsrs r0, 24
_08087BBE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end npc_080587EC

	thumb_func_start sub_8087BCC
sub_8087BCC: @ 8087BCC
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, r5, 2
	ldr r0, =gUnknown_02032308
	adds r2, r0
	ldrb r1, [r2, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	ldrb r0, [r2]
	cmp r0, 0
	beq _08087C7A
	subs r0, r3, 0x1
	cmp r0, 0x4
	bhi _08087C56
	lsls r0, 2
	ldr r1, =_08087C0C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08087C0C:
	.4byte _08087C2C
	.4byte _08087C2C
	.4byte _08087C38
	.4byte _08087C20
	.4byte _08087C20
_08087C20:
	ldrb r0, [r4]
	lsls r0, 30
	lsrs r0, 31
	bl sub_808BD6C
	b _08087C44
_08087C2C:
	ldrb r0, [r4]
	lsls r0, 30
	lsrs r0, 31
	bl sub_808BD7C
	b _08087C44
_08087C38:
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 31
	movs r0, 0
	bl sub_808BD3C
_08087C44:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_8087C8C
	movs r2, 0
	str r2, [sp]
	movs r3, 0
	bl AddPseudoFieldObject
	strb r0, [r4, 0x4]
_08087C56:
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	strh r5, [r0, 0x2E]
	ldrb r1, [r4]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
_08087C7A:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8087BCC

	thumb_func_start sub_8087C8C
sub_8087C8C: @ 8087C8C
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	lsls r4, 2
	ldr r0, =gUnknown_02032308
	adds r4, r0
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r6, r0, r1
	ldrh r0, [r6, 0xC]
	strh r0, [r5, 0x20]
	ldrh r0, [r6, 0xE]
	strh r0, [r5, 0x22]
	ldrb r0, [r6, 0xB]
	lsrs r0, 4
	adds r1, r5, 0
	movs r2, 0x1
	bl SetObjectSubpriorityByZCoord
	ldrb r0, [r6, 0xB]
	lsrs r0, 4
	bl ZCoordToPriority
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	bne _08087CF8
	ldrb r0, [r6, 0x19]
	bl FieldObjectDirectionToImageAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartObjectImageAnim
	b _08087D0A
	.pool
_08087CF8:
	ldrb r0, [r6, 0x19]
	bl get_go_image_anim_num
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartObjectImageAnimIfDifferent
_08087D0A:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80979D4
	ldrb r0, [r6]
	lsls r0, 29
	cmp r0, 0
	bge _08087D3C
	ldrh r0, [r5, 0x3C]
	movs r1, 0x4
	ands r1, r0
	lsls r1, 16
	adds r3, r5, 0
	adds r3, 0x3E
	lsrs r1, 18
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
_08087D3C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8087C8C

	.align 2, 0 @ Don't pad with nop.
