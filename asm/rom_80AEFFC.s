	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start palette_bg_faded_fill_white
palette_bg_faded_fill_white: @ 80AEFFC
	push {lr}
	sub sp, 0x4
	ldr r0, =0x7fff7fff
	str r0, [sp]
	ldr r1, =gPlttBufferFaded
	ldr r2, =0x01000100
	mov r0, sp
	bl CpuFastSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end palette_bg_faded_fill_white

	thumb_func_start palette_bg_faded_fill_black
palette_bg_faded_fill_black: @ 80AF020
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r1, =gPlttBufferFaded
	ldr r2, =0x01000100
	mov r0, sp
	bl CpuFastSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end palette_bg_faded_fill_black

	thumb_func_start pal_fill_for_maplights
pal_fill_for_maplights: @ 80AF040
	push {r4,lr}
	bl get_map_light_from_warp0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sav1_map_get_light_level
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl fade_type_for_given_maplight_pair
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080AF06A
	cmp r0, 0x1
	beq _080AF078
	b _080AF084
_080AF06A:
	bl palette_bg_faded_fill_black
	movs r0, 0
	movs r1, 0
	bl fade_screen
	b _080AF084
_080AF078:
	bl palette_bg_faded_fill_white
	movs r0, 0x2
	movs r1, 0
	bl fade_screen
_080AF084:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pal_fill_for_maplights

	thumb_func_start sub_80AF08C
sub_80AF08C: @ 80AF08C
	push {lr}
	bl palette_bg_faded_fill_white
	movs r0, 0x2
	movs r1, 0x8
	bl fade_screen
	pop {r0}
	bx r0
	thumb_func_end sub_80AF08C

	thumb_func_start pal_fill_black
pal_fill_black: @ 80AF0A0
	push {lr}
	bl palette_bg_faded_fill_black
	movs r0, 0
	movs r1, 0
	bl fade_screen
	pop {r0}
	bx r0
	thumb_func_end pal_fill_black

	thumb_func_start sub_80AF0B4
sub_80AF0B4: @ 80AF0B4
	push {r4,lr}
	bl sav1_map_get_light_level
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl warp1_get_mapheader
	ldrb r1, [r0, 0x17]
	adds r0, r4, 0
	bl sub_8137360
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080AF0DA
	cmp r0, 0x1
	beq _080AF0E4
	b _080AF0EC
_080AF0DA:
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	b _080AF0EC
_080AF0E4:
	movs r0, 0x3
	movs r1, 0
	bl fade_screen
_080AF0EC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF0B4

	thumb_func_start sub_80AF0F4
sub_80AF0F4: @ 80AF0F4
	push {lr}
	lsls r0, 24
	movs r1, 0
	cmp r0, 0
	bne _080AF100
	movs r1, 0x1
_080AF100:
	adds r0, r1, 0
	bl sub_808C0A8
	pop {r0}
	bx r0
	thumb_func_end sub_80AF0F4

	thumb_func_start task0A_nop_for_a_while
task0A_nop_for_a_while: @ 80AF10C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80AF71C
	cmp r0, 0x1
	bne _080AF120
	adds r0, r4, 0
	bl DestroyTask
_080AF120:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task0A_nop_for_a_while

	thumb_func_start sub_80AF128
sub_80AF128: @ 80AF128
	push {lr}
	bl script_env_2_enable
	bl sub_8085784
	bl pal_fill_black
	ldr r0, =task0A_nop_for_a_while
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF128

	thumb_func_start task0A_asap_script_env_2_enable_and_set_ctx_running
task0A_asap_script_env_2_enable_and_set_ctx_running: @ 80AF148
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80AF71C
	cmp r0, 0x1
	bne _080AF160
	adds r0, r4, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_080AF160:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task0A_asap_script_env_2_enable_and_set_ctx_running

	thumb_func_start sub_80AF168
sub_80AF168: @ 80AF168
	push {lr}
	bl script_env_2_enable
	bl sub_8085784
	bl pal_fill_black
	ldr r0, =task0A_asap_script_env_2_enable_and_set_ctx_running
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF168

	thumb_func_start sub_80AF188
sub_80AF188: @ 80AF188
	push {lr}
	bl script_env_2_enable
	bl pal_fill_black
	ldr r0, =task0A_asap_script_env_2_enable_and_set_ctx_running
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF188

	thumb_func_start task_mpl_807DD60
task_mpl_807DD60: @ 80AF1A4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r2, =gTasks
	adds r4, r0, r2
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AF1DE
	cmp r0, 0x1
	bgt _080AF1CC
	cmp r0, 0
	beq _080AF1D2
	b _080AF20E
	.pool
_080AF1CC:
	cmp r0, 0x2
	beq _080AF1FC
	b _080AF20E
_080AF1D2:
	bl sub_80B3050
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	b _080AF1F4
_080AF1DE:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	beq _080AF20E
	bl pal_fill_for_maplights
_080AF1F4:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AF20E
_080AF1FC:
	bl sub_80AF71C
	cmp r0, 0x1
	bne _080AF20E
	bl script_env_2_disable
	adds r0, r5, 0
	bl DestroyTask
_080AF20E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_mpl_807DD60

	thumb_func_start sub_80AF214
sub_80AF214: @ 80AF214
	push {lr}
	bl script_env_2_enable
	bl sub_8085784
	bl palette_bg_faded_fill_black
	ldr r0, =task_mpl_807DD60
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF214

	thumb_func_start sub_80AF234
sub_80AF234: @ 80AF234
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AF268
	cmp r0, 0x1
	bgt _080AF25C
	cmp r0, 0
	beq _080AF262
	b _080AF2AE
	.pool
_080AF25C:
	cmp r0, 0x2
	beq _080AF298
	b _080AF2AE
_080AF262:
	bl sub_800ADF8
	b _080AF290
_080AF268:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _080AF28C
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	movs r1, 0xE1
	lsls r1, 19
	cmp r0, r1
	ble _080AF2AE
	movs r0, 0xC0
	lsls r0, 7
	bl sub_8011170
	b _080AF2AE
_080AF28C:
	bl pal_fill_for_maplights
_080AF290:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AF2AE
_080AF298:
	bl sub_80AF71C
	cmp r0, 0x1
	bne _080AF2AE
	bl sub_8009F18
	bl script_env_2_disable
	adds r0, r5, 0
	bl DestroyTask
_080AF2AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF234

	thumb_func_start sub_80AF2B4
sub_80AF2B4: @ 80AF2B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AF2E8
	cmp r0, 0x1
	bgt _080AF2DC
	cmp r0, 0
	beq _080AF2E2
	b _080AF30C
	.pool
_080AF2DC:
	cmp r0, 0x2
	beq _080AF2FA
	b _080AF30C
_080AF2E2:
	bl sub_800ADF8
	b _080AF2F2
_080AF2E8:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080AF30C
_080AF2F2:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AF30C
_080AF2FA:
	bl sub_8009F18
	bl sub_8086C2C
	bl script_env_2_disable
	adds r0, r5, 0
	bl DestroyTask
_080AF30C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF2B4

	thumb_func_start sub_80AF314
sub_80AF314: @ 80AF314
	push {lr}
	bl script_env_2_enable
	bl sub_8085784
	bl palette_bg_faded_fill_black
	ldr r0, =sub_80AF234
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF314

	thumb_func_start sub_80AF334
sub_80AF334: @ 80AF334
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8088EFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080AF36C
	ldr r1, =sub_80AF438
	b _080AF37E
	.pool
_080AF36C:
	adds r0, r4, 0
	bl sub_8088F58
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =task_map_chg_seq_0807E2CC
	cmp r0, 0x1
	bne _080AF37E
	ldr r1, =task_map_chg_seq_0807E20C
_080AF37E:
	adds r0, r1, 0
	movs r1, 0xA
	bl CreateTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF334

	thumb_func_start mapldr_default
mapldr_default: @ 80AF398
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	bl sub_80AF334
	bl script_env_2_enable
	pop {r0}
	bx r0
	thumb_func_end mapldr_default

	thumb_func_start sub_80AF3B0
sub_80AF3B0: @ 80AF3B0
	push {lr}
	bl sub_8085784
	bl sub_80AF08C
	bl sub_80AF334
	bl script_env_2_enable
	pop {r0}
	bx r0
	thumb_func_end sub_80AF3B0

	thumb_func_start sub_80AF3C8
sub_80AF3C8: @ 80AF3C8
	push {lr}
	bl sub_81D6534
	cmp r0, 0
	bne _080AF3D6
	bl sub_8085784
_080AF3D6:
	bl pal_fill_black
	bl sub_80AF334
	bl script_env_2_enable
	pop {r0}
	bx r0
	thumb_func_end sub_80AF3C8

	thumb_func_start sub_80AF3E8
sub_80AF3E8: @ 80AF3E8
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	movs r0, 0x2E
	bl PlaySE
	ldr r0, =task0A_mpl_807E31C
	movs r1, 0xA
	bl CreateTask
	bl script_env_2_enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF3E8

	thumb_func_start sub_80AF40C
sub_80AF40C: @ 80AF40C
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	movs r0, 0x2E
	bl PlaySE
	ldr r0, =task_map_chg_seq_0807E2CC
	movs r1, 0xA
	bl CreateTask
	bl script_env_2_enable
	movs r0, 0xE
	bl sub_8085540
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF40C

	thumb_func_start sub_80AF438
sub_80AF438: @ 80AF438
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	adds r6, r5, 0
	adds r6, 0xC
	adds r7, r5, 0
	adds r7, 0xE
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _080AF54A
	lsls r0, 2
	ldr r1, =_080AF46C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AF46C:
	.4byte _080AF480
	.4byte _080AF4A4
	.4byte _080AF4DC
	.4byte _080AF520
	.4byte _080AF540
_080AF480:
	movs r0, 0
	bl sub_80AF0F4
	bl player_bitmagic
	adds r0, r6, 0
	adds r1, r7, 0
	bl PlayerGetDestCoords
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0
	ldrsh r1, [r7, r2]
	bl sub_808A854
	movs r0, 0x1
	strh r0, [r5, 0x8]
	b _080AF54A
_080AF4A4:
	bl sub_80AF71C
	cmp r0, 0
	beq _080AF54A
	movs r0, 0x1
	bl sub_80AF0F4
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	movs r1, 0x8
	bl FieldObjectSetSpecialAnim
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080AF54A
	.pool
_080AF4DC:
	bl walkrun_is_standing_still
	lsls r0, 24
	cmp r0, 0
	beq _080AF54A
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0
	ldrsh r1, [r7, r2]
	bl sub_808A8AC
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimFinished
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080AF54A
	.pool
_080AF520:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080AF536
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	beq _080AF54A
_080AF536:
	bl sub_809757C
	movs r0, 0x4
	strh r0, [r5, 0x8]
	b _080AF54A
_080AF540:
	bl script_env_2_disable
	adds r0, r4, 0
	bl DestroyTask
_080AF54A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF438

	thumb_func_start task_map_chg_seq_0807E20C
task_map_chg_seq_0807E20C: @ 80AF550
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	adds r6, r5, 0
	adds r6, 0xC
	adds r7, r5, 0
	adds r7, 0xE
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080AF5A2
	cmp r0, 0x1
	bgt _080AF580
	cmp r0, 0
	beq _080AF58A
	b _080AF60A
	.pool
_080AF580:
	cmp r0, 0x2
	beq _080AF5EC
	cmp r0, 0x3
	beq _080AF600
	b _080AF60A
_080AF58A:
	movs r0, 0
	bl sub_80AF0F4
	bl player_bitmagic
	adds r0, r6, 0
	adds r1, r7, 0
	bl PlayerGetDestCoords
	movs r0, 0x1
	strh r0, [r5, 0x8]
	b _080AF60A
_080AF5A2:
	bl sub_80AF71C
	cmp r0, 0
	beq _080AF60A
	movs r0, 0x1
	bl sub_80AF0F4
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gMapObjects
	adds r4, r0
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl GetGoSpeed0AnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080AF60A
	.pool
_080AF5EC:
	bl walkrun_is_standing_still
	lsls r0, 24
	cmp r0, 0
	beq _080AF60A
	bl sub_809757C
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080AF60A
_080AF600:
	bl script_env_2_disable
	adds r0, r4, 0
	bl DestroyTask
_080AF60A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end task_map_chg_seq_0807E20C

	thumb_func_start task_map_chg_seq_0807E2CC
task_map_chg_seq_0807E2CC: @ 80AF610
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080AF634
	cmp r0, 0x1
	beq _080AF644
	b _080AF65A
	.pool
_080AF634:
	bl player_bitmagic
	bl script_env_2_enable
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AF65A
_080AF644:
	bl sub_80AF71C
	cmp r0, 0
	beq _080AF65A
	bl sub_809757C
	bl script_env_2_disable
	adds r0, r5, 0
	bl DestroyTask
_080AF65A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_map_chg_seq_0807E2CC

	thumb_func_start sub_80AF660
sub_80AF660: @ 80AF660
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80AF71C
	cmp r0, 0x1
	bne _080AF67C
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =sub_809FA34
	movs r1, 0x50
	bl CreateTask
_080AF67C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF660

	thumb_func_start sub_80AF688
sub_80AF688: @ 80AF688
	push {lr}
	bl pal_fill_black
	ldr r0, =sub_80AF660
	movs r1, 0x50
	bl CreateTask
	bl script_env_2_enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF688

	thumb_func_start sub_80AF6A4
sub_80AF6A4: @ 80AF6A4
	push {lr}
	bl sub_809FA18
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80AF6A4

	thumb_func_start task_mpl_807E3C8
task_mpl_807E3C8: @ 80AF6B0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80AF71C
	cmp r0, 0x1
	bne _080AF6CC
	bl script_env_2_disable
	adds r0, r4, 0
	bl DestroyTask
	bl sub_80984F4
_080AF6CC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task_mpl_807E3C8

	thumb_func_start sub_80AF6D4
sub_80AF6D4: @ 80AF6D4
	push {lr}
	bl script_env_2_enable
	bl pal_fill_black
	ldr r0, =task_mpl_807E3C8
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF6D4

	thumb_func_start sub_80AF6F0
sub_80AF6F0: @ 80AF6F0
	push {lr}
	bl script_env_2_enable
	bl sub_8085784
	bl pal_fill_black
	ldr r0, =task_mpl_807E3C8
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF6F0

	thumb_func_start sub_80AF710
sub_80AF710: @ 80AF710
	ldr r0, =gPaletteFade
	ldrb r0, [r0, 0x7]
	lsrs r0, 7
	bx lr
	.pool
	thumb_func_end sub_80AF710

	thumb_func_start sub_80AF71C
sub_80AF71C: @ 80AF71C
	push {lr}
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080AF72E
	movs r0, 0
	b _080AF730
_080AF72E:
	movs r0, 0x1
_080AF730:
	pop {r1}
	bx r1
	thumb_func_end sub_80AF71C

	thumb_func_start sub_80AF734
sub_80AF734: @ 80AF734
	push {lr}
	bl script_env_2_enable
	bl music_something
	bl sub_80AF0B4
	bl play_some_sound
	movs r0, 0x9
	bl PlaySE
	ldr r0, =gUnknown_03005DAC
	ldr r1, =mapldr_default
	str r1, [r0]
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF734

	thumb_func_start sp13E_warp_to_last_warp
sp13E_warp_to_last_warp: @ 80AF76C
	push {lr}
	bl script_env_2_enable
	bl music_something
	bl sub_80AF0B4
	bl play_some_sound
	ldr r0, =gUnknown_03005DAC
	ldr r1, =mapldr_default
	str r1, [r0]
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp13E_warp_to_last_warp

	thumb_func_start sub_80AF79C
sub_80AF79C: @ 80AF79C
	push {lr}
	bl script_env_2_enable
	bl music_something
	movs r0, 0x3
	movs r1, 0x8
	bl fade_screen
	bl play_some_sound
	ldr r0, =gUnknown_03005DAC
	ldr r1, =sub_80AF3B0
	str r1, [r0]
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF79C

	thumb_func_start sub_80AF7D0
sub_80AF7D0: @ 80AF7D0
	push {lr}
	bl script_env_2_enable
	ldr r0, =gUnknown_03005DAC
	ldr r1, =mapldr_default
	str r1, [r0]
	ldr r0, =sub_80AFA88
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF7D0

	thumb_func_start sp13F_fall_to_last_warp
sp13F_fall_to_last_warp: @ 80AF7F4
	push {lr}
	bl sp13E_warp_to_last_warp
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80B6B68
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp13F_fall_to_last_warp

	thumb_func_start sub_80AF80C
sub_80AF80C: @ 80AF80C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl script_env_2_enable
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_80B6E4C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF80C

	thumb_func_start sub_80AF828
sub_80AF828: @ 80AF828
	push {lr}
	bl script_env_2_enable
	movs r0, 0xA
	bl sub_80B75D8
	pop {r0}
	bx r0
	thumb_func_end sub_80AF828

	thumb_func_start sub_80AF838
sub_80AF838: @ 80AF838
	push {lr}
	bl script_env_2_enable
	movs r0, 0xA
	bl sub_80B7A74
	pop {r0}
	bx r0
	thumb_func_end sub_80AF838

	thumb_func_start sub_80AF848
sub_80AF848: @ 80AF848
	push {lr}
	bl script_env_2_enable
	bl music_something
	bl sub_80AF0B4
	movs r0, 0x2D
	bl PlaySE
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF3E8
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF848

	thumb_func_start sub_80AF87C
sub_80AF87C: @ 80AF87C
	push {lr}
	movs r0, 0x1
	bl sub_8085540
	bl script_env_2_enable
	bl save_serialize_npcs
	bl music_something
	bl sub_80AF0B4
	movs r0, 0x2D
	bl PlaySE
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF40C
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF87C

	thumb_func_start sub_80AF8B8
sub_80AF8B8: @ 80AF8B8
	push {lr}
	bl script_env_2_enable
	bl sub_80AF0B4
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80FB768
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF8B8

	thumb_func_start sub_80AF8E0
sub_80AF8E0: @ 80AF8E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AF914
	cmp r0, 0x1
	bgt _080AF908
	cmp r0, 0
	beq _080AF90E
	b _080AF93E
	.pool
_080AF908:
	cmp r0, 0x2
	beq _080AF92E
	b _080AF93E
_080AF90E:
	bl script_env_2_enable
	b _080AF926
_080AF914:
	bl sub_80AF710
	cmp r0, 0
	bne _080AF93E
	bl sub_80859A0
	lsls r0, 24
	cmp r0, 0
	beq _080AF93E
_080AF926:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AF93E
_080AF92E:
	bl warp_in
	ldr r0, =sub_8086074
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_080AF93E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF8E0

	thumb_func_start sub_80AF948
sub_80AF948: @ 80AF948
	push {lr}
	bl script_env_2_enable
	bl music_something
	bl sub_80AF0B4
	movs r0, 0x9
	bl PlaySE
	ldr r0, =sub_80AF8E0
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF948

	thumb_func_start sub_80AF96C
sub_80AF96C: @ 80AF96C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AF9B2
	cmp r0, 0x1
	bgt _080AF994
	cmp r0, 0
	beq _080AF99A
	b _080AF9E8
	.pool
_080AF994:
	cmp r0, 0x2
	beq _080AF9D0
	b _080AF9E8
_080AF99A:
	bl sub_8009FAC
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	bl music_something
	movs r0, 0x9
	bl PlaySE
	b _080AF9C8
_080AF9B2:
	bl sub_80AF710
	cmp r0, 0
	bne _080AF9E8
	bl sub_80859A0
	lsls r0, 24
	cmp r0, 0
	beq _080AF9E8
	bl sub_800AC34
_080AF9C8:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080AF9E8
_080AF9D0:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AF9E8
	bl warp_in
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_080AF9E8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF96C

	thumb_func_start sub_80AF9F8
sub_80AF9F8: @ 80AF9F8
	push {lr}
	ldr r0, =sub_80AF96C
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AF9F8

	thumb_func_start sub_80AFA0C
sub_80AFA0C: @ 80AFA0C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _080AFA44
	cmp r5, 0x1
	bgt _080AFA34
	cmp r5, 0
	beq _080AFA3A
	b _080AFA7C
	.pool
_080AFA34:
	cmp r5, 0x2
	beq _080AFA6C
	b _080AFA7C
_080AFA3A:
	bl player_bitmagic
	bl script_env_2_enable
	b _080AFA64
_080AFA44:
	bl sub_80AF710
	cmp r0, 0
	bne _080AFA7C
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080AFA5A
	bl sub_81BE72C
	strh r5, [r4, 0xA]
_080AFA5A:
	bl sub_80859A0
	lsls r0, 24
	cmp r0, 0
	beq _080AFA7C
_080AFA64:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AFA7C
_080AFA6C:
	bl warp_in
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	adds r0, r6, 0
	bl DestroyTask
_080AFA7C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AFA0C

	thumb_func_start sub_80AFA88
sub_80AFA88: @ 80AFA88
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	adds r4, r5, 0
	adds r4, 0xC
	adds r6, r5, 0
	adds r6, 0xE
	movs r2, 0x8
	ldrsh r1, [r5, r2]
	adds r2, r0, 0
	cmp r1, 0x4
	bls _080AFAAC
	b _080AFBE8
_080AFAAC:
	lsls r0, r1, 2
	ldr r1, =_080AFAC0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AFAC0:
	.4byte _080AFAD4
	.4byte _080AFB10
	.4byte _080AFB6C
	.4byte _080AFBB8
	.4byte _080AFBD4
_080AFAD4:
	bl player_bitmagic
	adds r0, r4, 0
	adds r1, r6, 0
	bl PlayerGetDestCoords
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	bl cur_mapdata_get_door_sound_at
	lsls r0, 16
	lsrs r0, 16
	bl PlaySE
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	bl task_overworld_door_add_if_role_69_for_opening_door_at
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0x1
	strh r0, [r5, 0x8]
	b _080AFBE8
_080AFB10:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080AFB26
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	beq _080AFBE8
_080AFB26:
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r4, =gMapObjects
	adds r0, r4
	bl FieldObjectClearAnimIfSpecialAnimActive
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x9
	bl FieldObjectSetSpecialAnim
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080AFBE8
	.pool
_080AFB6C:
	bl walkrun_is_standing_still
	lsls r0, 24
	cmp r0, 0
	beq _080AFBE8
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r2, 0
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	bl sub_808A8AC
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimFinished
	movs r0, 0
	bl sub_80AF0F4
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080AFBE8
	.pool
_080AFBB8:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080AFBCE
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	beq _080AFBE8
_080AFBCE:
	movs r0, 0x4
	strh r0, [r5, 0x8]
	b _080AFBE8
_080AFBD4:
	bl music_something
	bl sub_80AF0B4
	bl play_some_sound
	movs r0, 0
	strh r0, [r5, 0x8]
	ldr r0, =sub_80AFA0C
	str r0, [r5]
_080AFBE8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AFA88

	thumb_func_start task0A_fade_n_map_maybe
task0A_fade_n_map_maybe: @ 80AFBF4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AFC2C
	cmp r0, 0x1
	bgt _080AFC1C
	cmp r0, 0
	beq _080AFC22
	b _080AFC56
	.pool
_080AFC1C:
	cmp r0, 0x2
	beq _080AFC46
	b _080AFC56
_080AFC22:
	bl player_bitmagic
	bl script_env_2_enable
	b _080AFC3E
_080AFC2C:
	bl sub_80AF710
	cmp r0, 0
	bne _080AFC56
	bl sub_80859A0
	lsls r0, 24
	cmp r0, 0
	beq _080AFC56
_080AFC3E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AFC56
_080AFC46:
	bl warp_in
	ldr r0, =sub_8086024
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_080AFC56:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_fade_n_map_maybe

	thumb_func_start sub_80AFC60
sub_80AFC60: @ 80AFC60
	push {lr}
	bl script_env_2_enable
	bl music_something
	bl sub_80AF0B4
	bl play_some_sound
	movs r0, 0x9
	bl PlaySE
	ldr r0, =gUnknown_03005DAC
	ldr r1, =sub_80AF3C8
	str r1, [r0]
	ldr r0, =task0A_fade_n_map_maybe
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AFC60

	thumb_func_start sub_80AFC98
sub_80AFC98: @ 80AFC98
	push {lr}
	cmp r1, 0xA0
	bhi _080AFCC0
	cmp r2, 0
	bge _080AFCA4
	movs r2, 0
_080AFCA4:
	cmp r2, 0xFF
	ble _080AFCAA
	movs r2, 0xFF
_080AFCAA:
	cmp r3, 0
	bge _080AFCB0
	movs r3, 0
_080AFCB0:
	cmp r3, 0xFF
	ble _080AFCB6
	movs r3, 0xFF
_080AFCB6:
	lsls r1, 1
	adds r1, r0
	lsls r0, r2, 8
	orrs r0, r3
	strh r0, [r1]
_080AFCC0:
	pop {r0}
	bx r0
	thumb_func_end sub_80AFC98

	thumb_func_start sub_80AFCC4
sub_80AFCC4: @ 80AFCC4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	mov r10, r1
	mov r9, r2
	adds r6, r3, 0
	mov r8, r6
	movs r7, 0
	cmp r6, 0
	blt _080AFD40
_080AFCE0:
	mov r0, r9
	subs r1, r0, r7
	mov r0, r10
	subs r4, r0, r6
	adds r5, r0, r6
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFC98
	mov r0, r9
	adds r1, r0, r7
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFC98
	mov r0, r9
	subs r1, r0, r6
	mov r0, r10
	subs r4, r0, r7
	adds r5, r0, r7
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFC98
	mov r0, r9
	adds r1, r0, r6
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFC98
	mov r1, r8
	adds r1, 0x1
	lsls r0, r7, 1
	subs r1, r0
	mov r8, r1
	adds r7, 0x1
	cmp r1, 0
	bge _080AFD3C
	subs r1, r6, 0x1
	lsls r0, r1, 1
	add r8, r0
	adds r6, r1, 0
_080AFD3C:
	cmp r6, r7
	bge _080AFCE0
_080AFD40:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AFCC4

	thumb_func_start sub_80AFD50
sub_80AFD50: @ 80AFD50
	push {lr}
	cmp r1, 0xA0
	bhi _080AFD78
	cmp r2, 0
	bge _080AFD5C
	movs r2, 0
_080AFD5C:
	cmp r2, 0xF0
	ble _080AFD62
	movs r2, 0xF0
_080AFD62:
	cmp r3, 0
	bge _080AFD68
	movs r3, 0
_080AFD68:
	cmp r3, 0xF0
	ble _080AFD6E
	movs r3, 0xF0
_080AFD6E:
	lsls r1, 1
	adds r1, r0
	lsls r0, r2, 8
	orrs r0, r3
	strh r0, [r1]
_080AFD78:
	pop {r0}
	bx r0
	thumb_func_end sub_80AFD50

	thumb_func_start sub_80AFD7C
sub_80AFD7C: @ 80AFD7C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	mov r10, r1
	mov r9, r2
	adds r6, r3, 0
	mov r8, r6
	movs r7, 0
	cmp r6, 0
	blt _080AFDF8
_080AFD98:
	mov r0, r9
	subs r1, r0, r7
	mov r0, r10
	subs r4, r0, r6
	adds r5, r0, r6
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFD50
	mov r0, r9
	adds r1, r0, r7
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFD50
	mov r0, r9
	subs r1, r0, r6
	mov r0, r10
	subs r4, r0, r7
	adds r5, r0, r7
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFD50
	mov r0, r9
	adds r1, r0, r6
	ldr r0, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80AFD50
	mov r1, r8
	adds r1, 0x1
	lsls r0, r7, 1
	subs r1, r0
	mov r8, r1
	adds r7, 0x1
	cmp r1, 0
	bge _080AFDF4
	subs r1, r6, 0x1
	lsls r0, r1, 1
	add r8, r0
	adds r6, r1, 0
_080AFDF4:
	cmp r6, r7
	bge _080AFD98
_080AFDF8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AFD7C

	thumb_func_start sub_80AFE08
sub_80AFE08: @ 80AFE08
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AFE64
	cmp r0, 0x1
	bgt _080AFE30
	cmp r0, 0
	beq _080AFE36
	b _080AFEC6
	.pool
_080AFE30:
	cmp r0, 0x2
	beq _080AFEBC
	b _080AFEC6
_080AFE36:
	ldr r0, =gUnknown_02039B28
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	ldr r1, =gUnknown_02038C28
	adds r0, r1
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r5, 0x6
	ldrsh r3, [r4, r5]
	bl sub_80AFCC4
	movs r0, 0x1
	strh r0, [r4]
	b _080AFEC6
	.pool
_080AFE64:
	ldr r0, =gUnknown_02039B28
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	ldr r1, =gUnknown_02038C28
	adds r0, r1
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r6, 0x6
	ldrsh r3, [r4, r6]
	bl sub_80AFCC4
	movs r0, 0
	strh r0, [r4]
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x6]
	adds r0, r1
	strh r0, [r4, 0x6]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _080AFEC6
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _080AFEB4
	bl remove_some_task
	movs r0, 0x2
	strh r0, [r4]
	b _080AFEC6
	.pool
_080AFEB4:
	adds r0, r5, 0
	bl DestroyTask
	b _080AFEC6
_080AFEBC:
	bl dp12_8087EA4
	adds r0, r5, 0
	bl DestroyTask
_080AFEC6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80AFE08

	thumb_func_start sub_80AFECC
sub_80AFECC: @ 80AFECC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080AFF28
	cmp r0, 0x1
	bgt _080AFEF4
	cmp r0, 0
	beq _080AFEFA
	b _080AFF8A
	.pool
_080AFEF4:
	cmp r0, 0x2
	beq _080AFF80
	b _080AFF8A
_080AFEFA:
	ldr r0, =gUnknown_02039B28
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	ldr r1, =gUnknown_02038C28
	adds r0, r1
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r5, 0x6
	ldrsh r3, [r4, r5]
	bl sub_80AFD7C
	movs r0, 0x1
	strh r0, [r4]
	b _080AFF8A
	.pool
_080AFF28:
	ldr r0, =gUnknown_02039B28
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	ldr r1, =gUnknown_02038C28
	adds r0, r1
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r6, 0x6
	ldrsh r3, [r4, r6]
	bl sub_80AFD7C
	movs r0, 0
	strh r0, [r4]
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x6]
	adds r0, r1
	strh r0, [r4, 0x6]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _080AFF8A
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _080AFF78
	bl remove_some_task
	movs r0, 0x2
	strh r0, [r4]
	b _080AFF8A
	.pool
_080AFF78:
	adds r0, r5, 0
	bl DestroyTask
	b _080AFF8A
_080AFF80:
	bl dp12_8087EA4
	adds r0, r5, 0
	bl DestroyTask
_080AFF8A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80AFECC

	thumb_func_start sub_80AFF90
sub_80AFF90: @ 80AFF90
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =sub_80AFE08
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080AFFAC
	bl script_env_2_enable_and_set_ctx_running
	adds r0, r4, 0
	bl DestroyTask
_080AFFAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AFF90

	thumb_func_start sub_80AFFB8
sub_80AFFB8: @ 80AFFB8
	push {r4,lr}
	ldr r4, =sub_80AFF90
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080AFFD0
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
_080AFFD0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AFFB8

	thumb_func_start sub_80AFFDC
sub_80AFFDC: @ 80AFFDC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	mov r9, r1
	adds r5, r2, 0
	adds r4, r3, 0
	ldr r6, [sp, 0x1C]
	ldr r0, [sp, 0x20]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =sub_80AFE08
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r1, r0, r1
	strh r5, [r1, 0x6]
	strh r4, [r1, 0x8]
	mov r0, r8
	strh r0, [r1, 0x2]
	mov r0, r9
	strh r0, [r1, 0x4]
	strh r6, [r1, 0xC]
	cmp r5, r4
	bge _080B0028
	strh r7, [r1, 0xA]
	b _080B002C
	.pool
_080B0028:
	negs r0, r7
	strh r0, [r1, 0xA]
_080B002C:
	adds r0, r2, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AFFDC

	thumb_func_start sub_80B003C
sub_80B003C: @ 80B003C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	mov r9, r1
	adds r5, r2, 0
	adds r4, r3, 0
	ldr r6, [sp, 0x1C]
	ldr r0, [sp, 0x20]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =sub_80AFECC
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r1, r0, r1
	strh r5, [r1, 0x6]
	strh r4, [r1, 0x8]
	mov r0, r8
	strh r0, [r1, 0x2]
	mov r0, r9
	strh r0, [r1, 0x4]
	strh r6, [r1, 0xC]
	cmp r5, r4
	bge _080B0088
	strh r7, [r1, 0xA]
	b _080B008C
	.pool
_080B0088:
	negs r0, r7
	strh r0, [r1, 0xA]
_080B008C:
	adds r0, r2, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B003C

	thumb_func_start sub_80B009C
sub_80B009C: @ 80B009C
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sav1_get_flash_used_on_map
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	cmp r4, 0
	bne _080B00B6
	movs r5, 0x1
_080B00B6:
	ldr r1, =gUnknown_0854FE64
	lsls r0, 1
	adds r0, r1
	ldrh r2, [r0]
	lsls r0, r4, 1
	adds r0, r1
	ldrh r3, [r0]
	str r5, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x78
	movs r1, 0x50
	bl sub_80AFFDC
	bl sub_80AFFB8
	bl script_env_2_enable
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B009C

	thumb_func_start sub_80B00E8
sub_80B00E8: @ 80B00E8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080B0116
	ldr r4, =gUnknown_02038C28
	ldr r1, =gUnknown_0854FE64
	lsls r0, 1
	adds r0, r1
	ldrh r3, [r0]
	adds r0, r4, 0
	movs r1, 0x78
	movs r2, 0x50
	bl sub_80AFCC4
	movs r0, 0xF0
	lsls r0, 3
	adds r1, r4, r0
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r4, 0
	bl CpuFastSet
_080B0116:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B00E8

	thumb_func_start door_upload_tiles
door_upload_tiles: @ 80B0124
	push {r4,lr}
	ldr r4, =gUnknown_02038C28
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e68
	adds r0, r1
	ldrb r3, [r0]
	adds r0, r4, 0
	movs r1, 0x78
	movs r2, 0x50
	bl sub_80AFCC4
	movs r0, 0xF0
	lsls r0, 3
	adds r1, r4, r0
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r4, 0
	bl CpuFastSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end door_upload_tiles

	thumb_func_start task0A_mpl_807E31C
task0A_mpl_807E31C: @ 80B0160
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080B0184
	cmp r0, 0x1
	beq _080B0198
	b _080B01B6
	.pool
_080B0184:
	bl player_bitmagic
	bl script_env_2_enable
	bl sub_808D194
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080B01B6
_080B0198:
	bl sub_80AF71C
	cmp r0, 0
	beq _080B01B6
	bl sub_808D1B4
	cmp r0, 0x1
	beq _080B01B6
	bl sub_809757C
	bl script_env_2_disable
	adds r0, r5, 0
	bl DestroyTask
_080B01B6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task0A_mpl_807E31C

	thumb_func_start sub_80B01BC
sub_80B01BC: @ 80B01BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080B0202
	cmp r0, 0x1
	bgt _080B01E4
	cmp r0, 0
	beq _080B01EE
	b _080B023A
	.pool
_080B01E4:
	cmp r0, 0x2
	beq _080B0210
	cmp r0, 0x3
	beq _080B022A
	b _080B023A
_080B01EE:
	bl player_bitmagic
	bl script_env_2_enable
	movs r0, 0x2D
	bl PlaySE
	bl sub_808D1C8
	b _080B0222
_080B0202:
	bl sub_808D1E8
	cmp r0, 0
	bne _080B023A
	bl sub_80AF0B4
	b _080B0222
_080B0210:
	bl sub_80AF710
	cmp r0, 0
	bne _080B023A
	bl sub_80859A0
	lsls r0, 24
	cmp r0, 0
	beq _080B023A
_080B0222:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080B023A
_080B022A:
	bl warp_in
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_080B023A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B01BC

	thumb_func_start sub_80B0244
sub_80B0244: @ 80B0244
	push {lr}
	bl script_env_2_enable
	ldr r0, =sub_80AFA0C
	movs r1, 0xA
	bl CreateTask
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF3E8
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B0244

	thumb_func_start sub_80B0268
sub_80B0268: @ 80B0268
	push {lr}
	bl script_env_2_enable
	ldr r0, =gUnknown_03005DAC
	ldr r1, =mapldr_default
	str r1, [r0]
	ldr r0, =sub_80B01BC
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B0268

	thumb_func_start sub_80B028C
sub_80B028C: @ 80B028C
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _080B029A
	movs r1, 0x1F
	b _080B02A0
_080B029A:
	movs r0, 0xF8
	lsls r0, 7
	adds r1, r0, 0
_080B02A0:
	mov r0, sp
	strh r1, [r0]
	movs r5, 0
	movs r4, 0xF0
	lsls r4, 16
_080B02AA:
	lsrs r1, r4, 16
	mov r0, sp
	movs r2, 0x2
	bl LoadPalette
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r5, 0x1
	cmp r5, 0xF
	ble _080B02AA
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B028C

	thumb_func_start sub_80B02C8
sub_80B02C8: @ 80B02C8
	push {r4,r5,lr}
	lsls r0, 16
	ldr r2, =0x04000052
	ldrh r1, [r2]
	lsls r1, 24
	lsrs r5, r1, 24
	ldrh r1, [r2]
	lsrs r4, r1, 8
	cmp r0, 0
	beq _080B02EC
	cmp r5, 0
	beq _080B02F6
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	b _080B02F6
	.pool
_080B02EC:
	cmp r4, 0xF
	bhi _080B02F6
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080B02F6:
	lsls r1, r4, 8
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	cmp r5, 0
	bne _080B0310
	cmp r4, 0x10
	bne _080B0310
	movs r0, 0x1
	b _080B0312
_080B0310:
	movs r0, 0
_080B0312:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B02C8

	thumb_func_start sub_80B0318
sub_80B0318: @ 80B0318
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x7
	bls _080B0334
	b _080B052C
_080B0334:
	lsls r0, 2
	ldr r1, =_080B0348
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B0348:
	.4byte _080B0368
	.4byte _080B0424
	.4byte _080B0450
	.4byte _080B046C
	.4byte _080B0482
	.4byte _080B04F2
	.4byte _080B04AC
	.4byte _080B04BA
_080B0368:
	movs r0, 0x80
	lsls r0, 19
	ldrh r0, [r0]
	strh r0, [r5, 0xC]
	ldr r0, =0x04000050
	ldrh r0, [r0]
	strh r0, [r5, 0xE]
	ldr r0, =0x04000052
	ldrh r0, [r0]
	strh r0, [r5, 0x10]
	ldr r0, =0x04000048
	ldrh r0, [r0]
	strh r0, [r5, 0x12]
	ldr r0, =0x0400004a
	ldrh r0, [r0]
	strh r0, [r5, 0x14]
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
	ldr r0, =gUnknown_82EC7CC
	ldrh r1, [r0]
	movs r0, 0x50
	bl SetGpuRegBits
	ldr r1, =0x0000070c
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x1E
	bl SetGpuReg
	movs r0, 0x14
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1E
	bl sub_8199C30
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r4, =gUnknown_02038C28
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	movs r0, 0x6
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	movs r3, 0x1
	bl sub_80AFD7C
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r4, r2
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r4, 0
	bl CpuFastSet
	ldr r2, =gUnknown_0854FE7C
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80BA038
	movs r0, 0x1
	strh r0, [r5]
	b _080B052C
	.pool
_080B0424:
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	ldrb r0, [r5, 0x2]
	bl sub_80B028C
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	movs r2, 0x1
	str r2, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	movs r3, 0xA0
	bl sub_80B003C
	strh r4, [r5]
	b _080B052C
_080B0450:
	ldr r0, =sub_80AFECC
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080B052C
	bl script_env_2_enable_and_set_ctx_running
	movs r0, 0x3
	strh r0, [r5]
	b _080B052C
	.pool
_080B046C:
	bl InstallCameraPanAheadCallback
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0
	strh r0, [r5, 0xA]
	movs r0, 0x4
	strh r0, [r5, 0x8]
	strh r0, [r5]
	b _080B052C
_080B0482:
	ldrh r0, [r5, 0x8]
	subs r0, 0x1
	strh r0, [r5, 0x8]
	lsls r0, 16
	cmp r0, 0
	bne _080B052C
	movs r0, 0x4
	strh r0, [r5, 0x8]
	ldrh r0, [r5, 0xA]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0xA]
	movs r1, 0x4
	negs r1, r1
	cmp r0, 0
	beq _080B04A4
	movs r1, 0x4
_080B04A4:
	movs r0, 0
	bl SetCameraPanning
	b _080B052C
_080B04AC:
	bl InstallCameraPanAheadCallback
	movs r0, 0x8
	strh r0, [r5, 0x8]
	movs r0, 0x7
	strh r0, [r5]
	b _080B052C
_080B04BA:
	ldrh r0, [r5, 0x8]
	subs r0, 0x1
	strh r0, [r5, 0x8]
	lsls r0, 16
	cmp r0, 0
	bne _080B052C
	movs r0, 0x8
	strh r0, [r5, 0x8]
	ldrh r0, [r5, 0xA]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0xA]
	ldrh r0, [r5, 0xA]
	bl sub_80B02C8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B052C
	movs r0, 0x5
	strh r0, [r5]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	b _080B052C
_080B04F2:
	movs r0, 0x40
	movs r1, 0xFF
	bl SetGpuReg
	ldrh r1, [r5, 0xC]
	movs r0, 0
	bl SetGpuReg
	ldrh r1, [r5, 0xE]
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r5, 0x10]
	movs r0, 0x52
	bl SetGpuReg
	ldrh r1, [r5, 0x12]
	movs r0, 0x48
	bl SetGpuReg
	ldrh r1, [r5, 0x14]
	movs r0, 0x4A
	bl SetGpuReg
	bl script_env_2_enable_and_set_ctx_running
	adds r0, r4, 0
	bl DestroyTask
_080B052C:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B0318

	thumb_func_start sub_80B0534
sub_80B0534: @ 80B0534
	push {lr}
	ldr r0, =sub_80B0318
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0
	bne _080B0568
	strh r0, [r1, 0x2]
	movs r0, 0x68
	b _080B0580
	.pool
_080B0568:
	cmp r0, 0x1
	bne _080B0572
	strh r0, [r1, 0x2]
	movs r0, 0x88
	b _080B0580
_080B0572:
	cmp r0, 0x2
	bne _080B057A
	movs r0, 0
	b _080B057C
_080B057A:
	movs r0, 0x1
_080B057C:
	strh r0, [r1, 0x2]
	movs r0, 0x78
_080B0580:
	strh r0, [r1, 0x4]
	movs r0, 0x50
	strh r0, [r1, 0x6]
	pop {r0}
	bx r0
	thumb_func_end sub_80B0534

	thumb_func_start sub_80B058C
sub_80B058C: @ 80B058C
	push {lr}
	ldr r0, =sub_80B0318
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x6
	strh r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B058C

	thumb_func_start sub_80B05B4
sub_80B05B4: @ 80B05B4
	push {lr}
	bl sub_80859B0
	ldr r0, =task50_0807F0C8
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B05B4

	thumb_func_start task50_0807F0C8
task50_0807F0C8: @ 80B05CC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80859A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B05E8
	adds r0, r4, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_080B05E8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task50_0807F0C8

	.align 2, 0 @ Don't pad with nop.
