	thumb_func_start c2_title_menu_3
c2_title_menu_3: ; 802F6B0
	push {lr}
	bl run_active_tasks
	bl call_obj_callbacks
	bl obj_sync_something
	bl fade_and_return_progress_probably
	pop {r0}
	bx r0
	thumb_func_end c2_title_menu_3

	thumb_func_start sub_802F6C8
sub_802F6C8: ; 802F6C8
	push {lr}
	bl copy_super_sprites_to_oam
	bl copy_queue_process
	bl copy_pal_bg_faded_to_pal_ram
	pop {r0}
	bx r0
	thumb_func_end sub_802F6C8

	thumb_func_start c2_title_menu_2
; void c2_title_menu_2()
c2_title_menu_2: ; 802F6DC
	push {lr}
	movs r0, 0
	bl init_title_menu
	pop {r0}
	bx r0
	thumb_func_end c2_title_menu_2

	thumb_func_start c2_title_menu_2_dupe
; void c2_title_menu_2_dupe()
c2_title_menu_2_dupe: ; 802F6E8
	push {lr}
	movs r0, 0x1
	bl init_title_menu
	pop {r0}
	bx r0
	thumb_func_end c2_title_menu_2_dupe

	thumb_func_start init_title_menu
; void init_title_menu(int useless_param)
init_title_menu: ; 802F6F4
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl lcd_io_set
	movs r0, 0xC
	movs r1, 0
	bl lcd_io_set
	movs r0, 0xA
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x8
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x18
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x1A
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x14
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x16
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x10
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x12
	movs r1, 0
	bl lcd_io_set
	add r1, sp, 0x4
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	add r0, sp, 0x4
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r5, 0
	str r5, [sp, 0x8]
	add r0, sp, 0x8
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add r0, sp, 0x4
	strh r5, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl sub_80A1A74
	ldr r0, =gUnknown_082FF0A0
	movs r1, 0
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r0, =gUnknown_082FF0C0
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	bl remove_some_task
	bl clear_tasks
	bl reset_all_obj_data
	bl gpu_pal_allocator_reset
	cmp r4, 0
	beq @0802F7EC
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A1AD4
	b @0802F7FE
	.pool
@0802F7EC:
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A1AD4
@0802F7FE:
	movs r0, 0
	bl gpu_reset_bgs_and_dma3_busy_flags
	ldr r1, =gUnknown_082FF0E8
	movs r0, 0
	movs r2, 0x2
	bl bg_vram_setup
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl bg_change_x_offset
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl bg_change_y_offset
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl bg_change_x_offset
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl bg_change_y_offset
	ldr r0, =gUnknown_082FF038
	bl Window_InitFromTemplates
	bl TextBox_ResetSomeField
	ldr r1, =0x000001d5
	movs r0, 0
	bl unknown_title_pattern_data_to_vram
	movs r0, 0x40
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x48
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x4A
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x50
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x1
	bl enable_irqs
	ldr r0, =sub_802F6C8
	bl SetVBlankCallback
	ldr r0, =c2_title_menu_3
	bl set_callback2
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl lcd_io_set
	movs r0, 0
	bl gpu_sync_bg_show
	movs r0, 0x1
	bl gpu_sync_bg_hide
	ldr r0, =task_init_title_menu_graphics
	movs r1, 0
	bl AddTask
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end init_title_menu

	thumb_func_start task_init_title_menu_graphics
; void task_init_title_menu_graphics(int task_id)
task_init_title_menu_graphics: ; 802F8D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =0x03005e08
	mov r8, r0
	adds r4, r7, r0
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq @0802F900
	b @0802FA4E
@0802F900:
	movs r0, 0x40
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x48
	movs r1, 0x11
	bl lcd_io_set
	movs r0, 0x4A
	movs r1, 0x31
	bl lcd_io_set
	movs r0, 0x50
	movs r1, 0xC1
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0x7
	bl lcd_io_set
	bl sub_80093CC
	lsls r0, 24
	cmp r0, 0
	beq @0802F946
	movs r0, 0x1
	strh r0, [r4, 0x1E]
@0802F946:
	ldr r0, =0x03006210
	ldrh r0, [r0]
	cmp r0, 0x2
	beq @0802F990
	cmp r0, 0x2
	bgt @0802F968
	cmp r0, 0
	beq @0802F9D0
	cmp r0, 0x1
	beq @0802F972
	b @0802F9D0
	.pool
@0802F968:
	cmp r0, 0x4
	beq @0802F9EC
	cmp r0, 0xFF
	beq @0802F9A4
	b @0802F9D0
@0802F972:
	strh r0, [r4]
	bl sub_809D4C4
	cmp r0, 0
	beq @0802F982
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
@0802F982:
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =task_init_title_menu_graphics_2
	b @0802F9FC
	.pool
@0802F990:
	ldr r0, =gUnknown_085E8405
	bl draw_text_box
	strh r5, [r4]
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	b @0802F9FA
	.pool
@0802F9A4:
	ldr r0, =gUnknown_085E83C2
	bl draw_text_box
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =task_init_title_menu_save_file_corrupt
	str r1, [r0]
	movs r0, 0x1
	strh r0, [r4]
	bl sub_809D4C4
	cmp r0, 0x1
	bne @0802F9FE
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b @0802F9FE
	.pool
@0802F9D0:
	movs r0, 0
	strh r0, [r4]
	ldr r1, =0x03005e00
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_init_title_menu_graphics_2
	b @0802F9FC
	.pool
@0802F9EC:
	ldr r0, =gUnknown_085E8440
	bl draw_text_box
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	strh r5, [r0, 0x8]
@0802F9FA:
	ldr r1, =task_init_title_menu_save_file_corrupt
@0802F9FC:
	str r1, [r0]
@0802F9FE:
	ldr r2, =0x02022d06
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq @0802FA3E
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x2
	beq @0802FA36
	cmp r0, 0x2
	ble @0802FA2C
	cmp r0, 0x3
	beq @0802FA3A
	b @0802FA3E
	.pool
@0802FA2C:
	cmp r0, 0
	blt @0802FA3E
	ldrh r0, [r4]
	adds r0, 0x1
	b @0802FA3C
@0802FA36:
	movs r0, 0x3
	b @0802FA3C
@0802FA3A:
	movs r0, 0x4
@0802FA3C:
	strh r0, [r2]
@0802FA3E:
	ldrh r1, [r2]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r2]
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x2
	strh r0, [r4, 0x18]
@0802FA4E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_init_title_menu_graphics

	thumb_func_start task_init_title_menu_save_file_corrupt
task_init_title_menu_save_file_corrupt: ; 802FA5C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl run_remoboxes
	movs r0, 0x7
	bl a_pressed_maybe
	lsls r0, 16
	cmp r0, 0
	bne @0802FA98
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq @0802FA98
	movs r0, 0x7
	bl Window_FillTileMap
	ldr r0, =gUnknown_082FF070
	bl sub_8032250
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_init_title_menu_graphics_2
	str r1, [r0]
@0802FA98:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_init_title_menu_save_file_corrupt

	thumb_func_start task_init_title_menu_graphics_2
task_init_title_menu_graphics_2: ; 802FAB0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @0802FB3C
	movs r0, 0x40
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x48
	movs r1, 0x11
	bl lcd_io_set
	movs r0, 0x4A
	movs r1, 0x31
	bl lcd_io_set
	movs r0, 0x50
	movs r1, 0xC1
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0x7
	bl lcd_io_set
	bl GameFreakRTC_GetErrorFlags
	movs r1, 0xFF
	lsls r1, 4
	ands r1, r0
	cmp r1, 0
	bne @0802FB28
	ldr r0, =0x03005e00
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_init_title_menu_graphics_3
	str r0, [r1]
	b @0802FB3C
	.pool
@0802FB28:
	ldr r0, =gUnknown_085E8453
	bl draw_text_box
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_init_title_menu_battery_dry
	str r1, [r0]
@0802FB3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_init_title_menu_graphics_2

	thumb_func_start task_init_title_menu_battery_dry
task_init_title_menu_battery_dry: ; 802FB50
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl run_remoboxes
	movs r0, 0x7
	bl a_pressed_maybe
	lsls r0, 16
	cmp r0, 0
	bne @0802FB8C
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq @0802FB8C
	movs r0, 0x7
	bl Window_FillTileMap
	ldr r0, =gUnknown_082FF070
	bl sub_8032250
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_init_title_menu_graphics_3
	str r1, [r0]
@0802FB8C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_init_title_menu_battery_dry

	thumb_func_start task_init_title_menu_graphics_3
; void task_init_title_menu_graphics_3(int task_id)
task_init_title_menu_graphics_3: ; 802FBA4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =0x03005e08
	adds r6, r0, r1
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq @0802FBCE
	b @0803006C
@0802FBCE:
	movs r0, 0x40
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x48
	movs r1, 0x11
	bl lcd_io_set
	movs r0, 0x4A
	movs r1, 0x31
	bl lcd_io_set
	movs r0, 0x50
	movs r1, 0xC1
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0x7
	bl lcd_io_set
	add r0, sp, 0xC
	strh r4, [r0]
	movs r1, 0xFE
	movs r2, 0x2
	bl gpu_pal_apply
	add r1, sp, 0xC
	ldr r2, =0x00007fff
	adds r0, r2, 0
	strh r0, [r1]
	adds r0, r1, 0
	movs r1, 0xFA
	movs r2, 0x2
	bl gpu_pal_apply
	add r1, sp, 0xC
	ldr r2, =0x0000318c
	adds r0, r2, 0
	strh r0, [r1]
	adds r0, r1, 0
	movs r1, 0xFB
	movs r2, 0x2
	bl gpu_pal_apply
	add r1, sp, 0xC
	ldr r2, =0x0000675a
	adds r0, r2, 0
	strh r0, [r1]
	adds r0, r1, 0
	movs r1, 0xFC
	movs r2, 0x2
	bl gpu_pal_apply
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne @0802FC84
	add r1, sp, 0xC
	ldr r2, =0x00007e04
	adds r0, r2, 0
	strh r0, [r1]
	adds r0, r1, 0
	movs r1, 0xF1
	movs r2, 0x2
	bl gpu_pal_apply
	b @0802FC96
	.pool
@0802FC84:
	add r1, sp, 0xC
	ldr r2, =0x0000547f
	adds r0, r2, 0
	strh r0, [r1]
	adds r0, r1, 0
	movs r1, 0xF1
	movs r2, 0x2
	bl gpu_pal_apply
@0802FC96:
	ldr r0, =0x03005e00
	mov r8, r0
	lsls r1, r7, 2
	adds r0, r1, r7
	lsls r0, 3
	add r0, r8
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	mov r9, r1
	cmp r0, 0x1
	beq @0802FD44
	cmp r0, 0x1
	ble @0802FCBC
	cmp r0, 0x2
	bne @0802FCB6
	b @0802FE00
@0802FCB6:
	cmp r0, 0x3
	bne @0802FCBC
	b @0802FEFC
@0802FCBC:
	movs r0, 0
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x1
	movs r1, 0xAA
	bl Window_FastFillPixels
	ldr r5, =gUnknown_082FF0E0
	str r5, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E827C
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E828E
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	movs r0, 0
	bl Window_WriteStandardTileMap
	movs r0, 0x1
	bl Window_WriteStandardTileMap
	movs r0, 0
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x1
	movs r1, 0x2
	bl Window_CopyToVram
	ldr r4, =gUnknown_082FF038
	ldr r5, =0x000001d5
	adds r0, r4, 0
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	adds r4, 0x8
	b @0802FED4
	.pool
@0802FD44:
	movs r0, 0x2
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x3
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x4
	movs r1, 0xAA
	bl Window_FastFillPixels
	ldr r5, =gUnknown_082FF0E0
	str r5, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E8285
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E827C
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E828E
	str r0, [sp, 0x8]
	movs r0, 0x4
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	bl fmt_savegame
	movs r0, 0x2
	bl Window_WriteStandardTileMap
	movs r0, 0x3
	bl Window_WriteStandardTileMap
	movs r0, 0x4
	bl Window_WriteStandardTileMap
	movs r0, 0x2
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x3
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x4
	movs r1, 0x2
	bl Window_CopyToVram
	ldr r4, =gUnknown_082FF048
	ldr r5, =0x000001d5
	adds r0, r4, 0
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r4, 0
	adds r0, 0x8
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	adds r4, 0x10
	b @0802FED4
	.pool
@0802FE00:
	movs r0, 0x2
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x3
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x4
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x5
	movs r1, 0xAA
	bl Window_FastFillPixels
	ldr r5, =gUnknown_082FF0E0
	str r5, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E8285
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E827C
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E8295
	str r0, [sp, 0x8]
	movs r0, 0x4
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E828E
	str r0, [sp, 0x8]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	bl fmt_savegame
	movs r0, 0x2
	bl Window_WriteStandardTileMap
	movs r0, 0x3
	bl Window_WriteStandardTileMap
	movs r0, 0x4
	bl Window_WriteStandardTileMap
	movs r0, 0x5
	bl Window_WriteStandardTileMap
	movs r0, 0x2
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x3
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x4
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x5
	movs r1, 0x2
	bl Window_CopyToVram
	ldr r4, =gUnknown_082FF048
	ldr r5, =0x000001d5
	adds r0, r4, 0
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r4, 0
	adds r0, 0x8
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r4, 0
	adds r0, 0x10
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	adds r4, 0x18
@0802FED4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl write_textbox_border_to_bg_tilemap
	b @0803005E
	.pool
@0802FEFC:
	movs r0, 0x2
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x3
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x4
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x5
	movs r1, 0xAA
	bl Window_FastFillPixels
	movs r0, 0x6
	movs r1, 0xAA
	bl Window_FastFillPixels
	ldr r5, =gUnknown_082FF0E0
	str r5, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E8285
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E827C
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E82A2
	str r0, [sp, 0x8]
	movs r0, 0x4
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E82AF
	str r0, [sp, 0x8]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	str r5, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_085E828E
	str r0, [sp, 0x8]
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	bl fmt_savegame
	movs r0, 0x2
	bl Window_WriteStandardTileMap
	movs r0, 0x3
	bl Window_WriteStandardTileMap
	movs r0, 0x4
	bl Window_WriteStandardTileMap
	movs r0, 0x5
	bl Window_WriteStandardTileMap
	movs r0, 0x6
	bl Window_WriteStandardTileMap
	movs r0, 0x2
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x3
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x4
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x5
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0x6
	movs r1, 0x2
	bl Window_CopyToVram
	ldr r5, =gUnknown_082FF048
	ldr r4, =0x000001d5
	adds r0, r5, 0
	adds r1, r4, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r5, 0
	adds r0, 0x8
	adds r1, r4, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r5, 0
	adds r0, 0x10
	adds r1, r4, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r5, 0
	adds r0, 0x18
	adds r1, r4, 0
	bl write_textbox_border_to_bg_tilemap
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	bl write_textbox_border_to_bg_tilemap
	ldr r0, =gUnknown_082FF0F4
	ldr r4, =0x02022d06
	adds r1, r4, 0
	bl sub_81AF380
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x1A]
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	add r0, r8
	ldr r1, =sub_81AF59C
	str r1, [r0]
	ldrh r0, [r4]
	cmp r0, 0x4
	bne @0803005E
	movs r4, 0x80
	lsls r4, 6
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl bg_change_y_offset
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x1
	bl bg_change_y_offset
	movs r0, 0x1
	strh r0, [r6, 0x1C]
	movs r2, 0x1A
	ldrsh r1, [r6, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	add r0, r8
	movs r1, 0x1
	strh r1, [r0, 0x26]
@0803005E:
	ldr r0, =0x03005e00
	mov r2, r9
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_title_menu_highlight_selected_menu_items
	str r0, [r1]
@0803006C:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_init_title_menu_graphics_3

	thumb_func_start task_title_menu_highlight_selected_menu_items
; void task_title_menu_highlight_selected_menu_items(int task_id)
task_title_menu_highlight_selected_menu_items: ; 80300B0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x03005e00
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0xA]
	movs r3, 0x24
	ldrsh r2, [r4, r3]
	bl title_menu_highlight_selected_menu_items
	ldr r0, =task_title_menu_handle_input
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_title_menu_highlight_selected_menu_items

	thumb_func_start title_menu_handle_input
title_menu_handle_input: ; 80300E0
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r4, r1, 3
	ldr r7, =0x03005e08
	adds r5, r4, r7
	ldr r1, =0x030022c0
	ldrh r2, [r1, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq @08030130
	movs r0, 0x5
	bl audio_play
	bl sub_80093CC
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl sub_80A1AD4
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r4, r0
	ldr r1, =title_menu_handle_keypad_a_pressed
	str r1, [r0]
	b @08030240
	.pool
@08030130:
	movs r0, 0x2
	ands r0, r2
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq @08030178
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl sub_80A1AD4
	movs r0, 0x40
	movs r1, 0xF0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0xA0
	bl lcd_io_set
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r4, r0
	ldr r1, =sub_8030544
	str r1, [r0]
	b @08030240
	.pool
@08030178:
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq @080301CA
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	cmp r2, 0
	ble @080301CA
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x3
	bne @080301C4
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne @080301C4
	cmp r2, 0x1
	bne @080301C4
	movs r4, 0x80
	lsls r4, 6
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl bg_change_y_offset
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2
	bl bg_change_y_offset
	movs r2, 0x1A
	ldrsh r1, [r5, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r7, r0
	strh r6, [r5, 0x1C]
	strh r6, [r0, 0x1E]
@080301C4:
	ldrh r0, [r5, 0x2]
	subs r0, 0x1
	b @0803022C
@080301CA:
	ldrh r1, [r1, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq @08030240
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	subs r0, 0x1
	cmp r1, r0
	bge @08030240
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x3
	bne @08030228
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	cmp r0, 0x3
	bne @08030228
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne @08030228
	movs r4, 0x80
	lsls r4, 6
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl bg_change_y_offset
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x1
	bl bg_change_y_offset
	ldr r2, =0x03005e00
	movs r0, 0x1A
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x1
	strh r1, [r5, 0x1C]
	movs r1, 0x1
	strh r1, [r0, 0x26]
@08030228:
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
@0803022C:
	strh r0, [r5, 0x2]
	ldr r1, =0x02022d06
	strh r0, [r1]
	movs r0, 0x1
	b @08030242
	.pool
@08030240:
	movs r0, 0
@08030242:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end title_menu_handle_input

	thumb_func_start task_title_menu_handle_input
task_title_menu_handle_input: ; 803024C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl title_menu_handle_input
	lsls r0, 24
	cmp r0, 0
	beq @0803026C
	ldr r0, =0x03005e00
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_title_menu_highlight_selected_menu_items
	str r0, [r1]
@0803026C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_title_menu_handle_input

	thumb_func_start title_menu_handle_keypad_a_pressed
; void title_menu_handle_keypad_a_pressed(int task_id)
title_menu_handle_keypad_a_pressed: ; 803027C
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq @08030292
	b @08030536
@08030292:
	ldr r2, =0x03005e00
	lsls r1, r6, 2
	adds r0, r1, r6
	lsls r0, 3
	adds r4, r0, r2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0x3
	bne @080302B0
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl sub_81AF620
@080302B0:
	movs r0, 0
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x1
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x2
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x3
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x4
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x5
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x6
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x7
	movs r1, 0x1
	bl sub_819746C
	bl sub_80093CC
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0x8
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	beq @08030324
	cmp r0, 0x1
	ble @0803030C
	cmp r0, 0x2
	beq @08030336
	cmp r0, 0x3
	beq @08030358
@0803030C:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq @08030388
	cmp r0, 0x1
	bne @08030388
	b @080303D8
	.pool
@08030324:
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq @08030388
	cmp r0, 0x1
	ble @08030384
	cmp r0, 0x2
	bne @08030384
	b @080303D8
@08030336:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	beq @08030388
	cmp r0, 0x1
	ble @08030384
	cmp r0, 0x2
	beq @0803034C
	cmp r0, 0x3
	beq @080303D8
	b @08030384
@0803034C:
	movs r5, 0x3
	cmp r2, 0
	bne @080303DA
	movs r5, 0x6
	strh r2, [r4, 0x8]
	b @080303DA
@08030358:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi @08030384
	lsls r0, 2
	ldr r1, =@08030370
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08030370:
	.4byte @08030384
	.4byte @08030388
	.4byte @0803038C
	.4byte @080303BC
	.4byte @080303D8
@08030384:
	movs r5, 0x1
	b @080303DA
@08030388:
	movs r5, 0
	b @080303DA
@0803038C:
	ldr r0, =0x03005e00
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	movs r3, 0x26
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq @080303AC
	movs r5, 0x3
	cmp r2, 0
	bne @080303DA
	movs r5, 0x6
	strh r2, [r1, 0x8]
	b @080303DA
	.pool
@080303AC:
	cmp r2, 0
	beq @080303B8
	movs r5, 0x6
	movs r0, 0x1
	strh r0, [r1, 0x8]
	b @080303DA
@080303B8:
	movs r5, 0x5
	b @080303DA
@080303BC:
	cmp r2, 0
	beq @080303D4
	movs r5, 0x6
	ldr r0, =0x03005e00
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	strh r0, [r1, 0x8]
	b @080303DA
	.pool
@080303D4:
	movs r5, 0x4
	b @080303DA
@080303D8:
	movs r5, 0x2
@080303DA:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl bg_change_y_offset
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl bg_change_y_offset
	cmp r5, 0x6
	bhi @0803041C
	lsls r0, r5, 2
	ldr r1, =@08030400
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08030400:
	.4byte @0803041C
	.4byte @08030444
	.4byte @08030460
	.4byte @08030478
	.4byte @08030480
	.4byte @08030488
	.4byte @0803049C
@0803041C:
	ldr r0, =0x02037714
	movs r1, 0
	strh r1, [r0]
	ldr r0, =0x02037b14
	strh r1, [r0]
	ldr r1, =0x03005e00
	adds r0, r7, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_1
	str r1, [r0]
	b @08030514
	.pool
@08030444:
	ldr r0, =0x02037714
	movs r1, 0
	strh r1, [r0]
	ldr r0, =0x02037b14
	strh r1, [r0]
	ldr r0, =sub_8086230
	b @0803048A
	.pool
@08030460:
	ldr r0, =0x030022c0
	ldr r1, =c2_title_menu_2_dupe
	str r1, [r0, 0x8]
	ldr r0, =c2_options_menu
	b @0803048A
	.pool
@08030478:
	ldr r0, =c2_mystery_gift
	b @0803048A
	.pool
@08030480:
	ldr r0, =sub_8178974
	b @0803048A
	.pool
@08030488:
	ldr r0, =sub_801867C
@0803048A:
	bl set_callback2
	adds r0, r6, 0
	bl remove_task
	b @08030514
	.pool
@0803049C:
	ldr r1, =0x03005e00
	adds r0, r7, r6
	lsls r0, 3
	adds r0, r1
	movs r4, 0
	strh r4, [r0, 0xA]
	ldr r1, =sub_80305A4
	str r1, [r0]
	ldr r0, =0x02037714
	movs r2, 0xF1
	lsls r2, 1
	adds r0, r2
	ldr r1, =0x00007fff
	strh r1, [r0]
	ldr r0, =0x02037b14
	adds r0, r2
	strh r1, [r0]
	movs r0, 0x18
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x1A
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x14
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x16
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x10
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x12
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A1AD4
	b @08030536
	.pool
@08030514:
	bl Window_FreeMemory
	cmp r5, 0x2
	beq @08030528
	ldr r1, =0x02022d06
	movs r0, 0
	strh r0, [r1]
	b @08030536
	.pool
@08030528:
	ldr r0, =0x02022d06
	ldrh r1, [r0]
	movs r3, 0x80
	lsls r3, 8
	adds r2, r3, 0
	orrs r1, r2
	strh r1, [r0]
@08030536:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end title_menu_handle_keypad_a_pressed

	thumb_func_start sub_8030544
sub_8030544: ; 8030544
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r5, r2, 0
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne @0803058C
	ldr r0, =0x03005e00
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x3
	bne @08030578
	ldrh r0, [r1, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl sub_81AF620
@08030578:
	ldr r0, =0x02022d06
	strh r4, [r0]
	bl Window_FreeMemory
	ldr r0, =c2_title_screen_1
	bl set_callback2
	adds r0, r5, 0
	bl remove_task
@0803058C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030544

	thumb_func_start sub_80305A4
sub_80305A4: ; 80305A4
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq @0803063C
	cmp r1, 0x1
	bgt @080305CC
	cmp r1, 0
	beq @080305D6
	b @08030688
	.pool
@080305CC:
	cmp r1, 0x2
	beq @0803064C
	cmp r1, 0x3
	beq @08030664
	b @08030688
@080305D6:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl bg_fill_tilemap_rect
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq @08030610
	cmp r0, 0x1
	bgt @080305FC
	cmp r0, 0
	beq @08030602
	b @08030622
@080305FC:
	cmp r0, 0x2
	beq @0803061C
	b @08030622
@08030602:
	ldr r0, =gUnknown_085E82BE
	bl draw_text_box
	b @08030622
	.pool
@08030610:
	ldr r0, =gUnknown_085E82E5
	bl draw_text_box
	b @08030622
	.pool
@0803061C:
	ldr r0, =gUnknown_085E8328
	bl draw_text_box
@08030622:
	ldr r0, =0x03005e00
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b @08030688
	.pool
@0803063C:
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	b @08030658
	.pool
@0803064C:
	bl run_remoboxes
	movs r0, 0x7
	bl a_pressed_maybe
	lsls r0, 16
@08030658:
	cmp r0, 0
	bne @08030688
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b @08030688
@08030664:
	ldr r0, =0x030022c0
	ldrh r0, [r0, 0x2E]
	ands r1, r0
	cmp r1, 0
	beq @08030688
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl sub_80A1AD4
	ldr r0, =sub_8030544
	str r0, [r4]
@08030688:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80305A4

	thumb_func_start title_menu_highlight_selected_menu_items
; void title_menu_highlight_selected_menu_items(u8 a1, u8 selected_menu_item, u16 a3)
title_menu_highlight_selected_menu_items: ; 8030698
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 16
	lsrs r6, r2, 16
	ldr r1, =0x000009e7
	movs r0, 0x40
	bl lcd_io_set
	cmp r5, 0x1
	beq @080306DC
	cmp r5, 0x1
	ble @080306BE
	cmp r5, 0x2
	beq @08030700
	cmp r5, 0x3
	beq @08030728
@080306BE:
	cmp r4, 0
	beq @080306C6
	cmp r4, 0x1
	beq @080306D4
@080306C6:
	ldr r1, =0x0000011f
	b @0803078E
	.pool
@080306D4:
	ldr r1, =0x0000213f
	b @0803078E
	.pool
@080306DC:
	cmp r4, 0x1
	beq @080306F0
	cmp r4, 0x1
	ble @080306E8
	cmp r4, 0x2
	beq @080306F8
@080306E8:
	ldr r1, =0x0000013f
	b @0803078E
	.pool
@080306F0:
	ldr r1, =0x0000415f
	b @0803078E
	.pool
@080306F8:
	ldr r1, =0x0000617f
	b @0803078E
	.pool
@08030700:
	cmp r4, 0x1
	beq @08030718
	cmp r4, 0x1
	ble @08030710
	cmp r4, 0x2
	beq @08030720
	cmp r4, 0x3
	beq @0803078C
@08030710:
	ldr r1, =0x0000013f
	b @0803078E
	.pool
@08030718:
	ldr r1, =0x0000415f
	b @0803078E
	.pool
@08030720:
	ldr r1, =0x0000617f
	b @0803078E
	.pool
@08030728:
	cmp r4, 0x4
	bhi @08030750
	lsls r0, r4, 2
	ldr r1, =@0803073C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@0803073C:
	.4byte @08030750
	.4byte @08030758
	.4byte @0803076C
	.4byte @08030780
	.4byte @0803079C
@08030750:
	ldr r1, =0x0000013f
	b @0803078E
	.pool
@08030758:
	cmp r6, 0
	beq @08030764
	ldr r1, =0x0000213f
	b @0803078E
	.pool
@08030764:
	ldr r1, =0x0000415f
	b @0803078E
	.pool
@0803076C:
	cmp r6, 0
	beq @08030778
	ldr r1, =0x0000415f
	b @0803078E
	.pool
@08030778:
	ldr r1, =0x0000617f
	b @0803078E
	.pool
@08030780:
	cmp r6, 0
	beq @0803078C
	ldr r1, =0x0000617f
	b @0803078E
	.pool
@0803078C:
	ldr r1, =0x0000819f
@0803078E:
	movs r0, 0x44
	bl lcd_io_set
	b @080307A4
	.pool
@0803079C:
	ldr r1, =0x0000819f
	movs r0, 0x44
	bl lcd_io_set
@080307A4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end title_menu_highlight_selected_menu_items

	thumb_func_start task_new_game_prof_birch_speech_1
; void task_new_game_prof_birch_speech_1(int task_id)
task_new_game_prof_birch_speech_1: ; 80307B0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl lcd_io_set
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl lcd_io_set
	ldr r0, =gUnknown_082FF0F0
	bl bg_init_bg_config_2_from_bg_config_3
	movs r0, 0x40
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x48
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x4A
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x50
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0
	bl lcd_io_set
	ldr r0, =gUnknown_082FED3C
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_082FEEF0
	ldr r1, =0x06003800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_082FECFC
	movs r1, 0
	movs r2, 0x40
	bl gpu_pal_apply
	ldr r0, =gUnknown_082FF028
	movs r1, 0x1
	movs r2, 0x10
	bl gpu_pal_apply
	bl remove_some_task
	bl reset_all_obj_data
	bl gpu_pal_allocator_reset
	bl dp13_810BB8C
	adds r0, r4, 0
	bl sub_803192C
	movs r0, 0x1
	negs r0, r0
	movs r5, 0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A1AD4
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x10]
	ldr r1, =task_new_game_prof_birch_speech_2
	str r1, [r0]
	movs r1, 0xFF
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	movs r1, 0xD8
	strh r1, [r0, 0x16]
	movs r0, 0xBB
	lsls r0, 1
	bl song_play_for_text
	movs r0, 0
	bl gpu_sync_bg_show
	movs r0, 0x1
	bl gpu_sync_bg_show
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_1

	thumb_func_start task_new_game_prof_birch_speech_2
task_new_game_prof_birch_speech_2: ; 80308B0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0x16]
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq @080308D4
	subs r0, r1, 0x1
	strh r0, [r4, 0x16]
	b @0803091A
	.pool
@080308D4:
	ldrb r0, [r4, 0x18]
	ldr r2, =0x02020630
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x88
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	subs r0, 0x41
	ands r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x1]
	adds r0, r5, 0
	movs r1, 0xA
	bl sub_8031BAC
	adds r0, r5, 0
	movs r1, 0x14
	bl sub_8031D34
	movs r0, 0x50
	strh r0, [r4, 0x16]
	ldr r0, =task_new_game_prof_birch_speech_3
	str r0, [r4]
@0803091A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_2

	thumb_func_start task_new_game_prof_birch_speech_3
; int task_new_game_prof_birch_speech_3()
task_new_game_prof_birch_speech_3: ; 8030928
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq @080309B6
	ldr r2, =0x02020630
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldrh r1, [r4, 0x16]
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq @08030970
	subs r0, r1, 0x1
	strh r0, [r4, 0x16]
	b @080309B6
	.pool
@08030970:
	ldr r0, =gUnknown_082FF080
	bl Window_InitFromTemplates
	movs r0, 0
	movs r1, 0xF3
	bl unknown_title_pattern_data_to_vram
	movs r0, 0
	movs r1, 0xFC
	movs r2, 0xF0
	bl copy_textbox_border_tile_patterns_to_vram
	movs r0, 0
	movs r1, 0x1
	bl unknown_rbox_to_vram
	movs r0, 0
	bl Window_WriteStandardTileMap
	movs r0, 0
	movs r1, 0x2
	bl Window_CopyToVram
	movs r0, 0
	bl sub_8032318
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C897B
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r0, =task_new_game_prof_birch_speech_4
	str r0, [r4]
@080309B6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_3

	thumb_func_start task_new_game_prof_birch_speech_4
task_new_game_prof_birch_speech_4: ; 80309CC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08030A0A
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @08030A0A
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_5
	str r1, [r0]
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_085E8692
	bl ExpandStringRefs
	ldr r1, =sub_80323A0
	movs r0, 0x1
	bl sub_8197A9C
	ldr r0, =0x03000dd0
	strb r4, [r0]
@08030A0A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_4

	thumb_func_start task_new_game_prof_birch_speech_5
task_new_game_prof_birch_speech_5: ; 8030A2C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @08030A58
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8A1F
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_6
	str r1, [r0]
@08030A58:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_5

	thumb_func_start sub_8030A70
sub_8030A70: ; 8030A70
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =0x03005e00
	ldr r0, =0x03000dd0
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldrb r0, [r0, 0x1A]
	ldr r1, =0x02020630
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	movs r5, 0
	movs r1, 0x64
	strh r1, [r2, 0x20]
	movs r1, 0x4B
	strh r1, [r2, 0x22]
	movs r1, 0x3E
	adds r1, r2
	mov r12, r1
	ldrb r3, [r1]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	mov r3, r12
	strb r1, [r3]
	strh r5, [r2, 0x2E]
	ldrb r1, [r2, 0x5]
	lsrs r1, 4
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x20
	str r2, [sp, 0x8]
	ldr r2, =0x0000ffff
	str r2, [sp, 0xC]
	ldr r2, =0x00000127
	str r2, [sp, 0x10]
	movs r2, 0x70
	movs r3, 0x3A
	bl sub_8076438
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	ldr r1, =sub_8030B14
	str r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r5, [r0, 0x16]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030A70

	thumb_func_start sub_8030B14
sub_8030B14: ; 8030B14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =0x03005e08
	adds r5, r0, r1
	subs r1, 0x8
	mov r8, r1
	ldr r2, =0x03000dd0
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	mov r1, r8
	adds r6, r0, r1
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x02020630
	adds r3, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r7, r2, 0
	cmp r0, 0
	beq @08030B64
	cmp r0, 0x1
	beq @08030B7C
	b @08030B98
	.pool
@08030B64:
	ldr r1, [r3, 0x1C]
	ldr r0, =nullsub_12
	cmp r1, r0
	bne @08030BBA
	ldrb r1, [r3, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x1]
	b @08030B98
	.pool
@08030B7C:
	movs r1, 0x16
	ldrsh r0, [r6, r1]
	cmp r0, 0x5F
	ble @08030BBA
	adds r0, r4, 0
	bl remove_task
	ldrb r1, [r7]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	mov r1, r8
	adds r2, r0, r1
	b @08030BAA
@08030B98:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	ldr r2, =0x03005e00
	ldrb r1, [r7]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, r0, r2
@08030BAA:
	ldrh r3, [r2, 0x16]
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	ldr r0, =0x00003fff
	cmp r1, r0
	bgt @08030BBA
	adds r0, r3, 0x1
	strh r0, [r2, 0x16]
@08030BBA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030B14

	thumb_func_start task_new_game_prof_birch_speech_6
task_new_game_prof_birch_speech_6: ; 8030BCC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne @08030BFE
	ldr r0, =0x02022d04
	strb r1, [r0]
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8BD0
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_7
	str r1, [r0]
@08030BFE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_6

	thumb_func_start task_new_game_prof_birch_speech_7
task_new_game_prof_birch_speech_7: ; 8030C18
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @08030C7C
	ldr r5, =0x02020630
	ldr r0, =0x03005e00
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r3, [r1, 0x1]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1, 0x1]
	movs r0, 0x1A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	ands r2, r1
	orrs r2, r3
	strb r2, [r0, 0x1]
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8031ACC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8031C88
	movs r0, 0x40
	strh r0, [r4, 0x16]
	ldr r0, =task_new_game_prof_birch_speech_8
	str r0, [r4]
@08030C7C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_7

	thumb_func_start task_new_game_prof_birch_speech_8
task_new_game_prof_birch_speech_8: ; 8030C90
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r3, [r2, 0x10]
	movs r0, 0x10
	ldrsh r1, [r2, r0]
	movs r0, 0x3C
	negs r0, r0
	cmp r1, r0
	beq @08030CC0
	subs r0, r3, 0x2
	strh r0, [r2, 0x10]
	ldrh r1, [r2, 0x10]
	movs r0, 0x14
	bl lcd_io_set
	b @08030CC8
	.pool
@08030CC0:
	ldr r0, =0x0000ffc4
	strh r0, [r2, 0x10]
	ldr r0, =task_new_game_prof_birch_speech_9
	str r0, [r2]
@08030CC8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_8

	thumb_func_start task_new_game_prof_birch_speech_9
task_new_game_prof_birch_speech_9: ; 8030CD4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq @08030D7A
	ldr r2, =0x02020630
	movs r0, 0x18
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r7, 0x4
	orrs r1, r7
	strb r1, [r0]
	movs r0, 0x1A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	ldrh r0, [r4, 0x16]
	movs r1, 0x16
	ldrsh r6, [r4, r1]
	cmp r6, 0
	beq @08030D34
	subs r0, 0x1
	strh r0, [r4, 0x16]
	b @08030D7A
	.pool
@08030D34:
	ldrb r3, [r4, 0x1C]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	movs r0, 0xB4
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	movs r2, 0x3E
	adds r2, r1
	mov r12, r2
	ldrb r2, [r2]
	subs r0, 0x41
	ands r0, r2
	mov r2, r12
	strb r0, [r2]
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r7
	strb r0, [r1, 0x1]
	strh r3, [r4, 0xC]
	strh r6, [r4, 0x14]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_8031BAC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8031D34
	ldr r0, =task_new_game_prof_birch_speech_10
	str r0, [r4]
@08030D7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_9

	thumb_func_start task_new_game_prof_birch_speech_10
task_new_game_prof_birch_speech_10: ; 8030D84
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq @08030DB8
	ldr r2, =0x02020630
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, =task_new_game_prof_birch_speech_11
	str r0, [r3]
@08030DB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_10

	thumb_func_start task_new_game_prof_birch_speech_11
task_new_game_prof_birch_speech_11: ; 8030DC8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_8032318
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8BDD
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_12
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_11

	thumb_func_start task_new_game_prof_birch_speech_12
task_new_game_prof_birch_speech_12: ; 8030E08
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @08030E2A
	bl sub_8031D74
	ldr r0, =0x03005e00
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_new_game_prof_birch_speech_13
	str r0, [r1]
@08030E2A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_12

	thumb_func_start task_new_game_prof_birch_speech_13
task_new_game_prof_birch_speech_13: ; 8030E38
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8031DB4
	lsls r0, 24
	asrs r4, r0, 24
	cmp r4, 0
	beq @08030E52
	cmp r4, 0x1
	beq @08030E52
	lsls r4, r5, 2
	b @08030E76
@08030E52:
	movs r0, 0x5
	bl audio_play
	ldr r0, =0x03005d90
	ldr r0, [r0]
	strb r4, [r0, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl sub_80322E0
	ldr r1, =0x03005e00
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_14
	str r1, [r0]
	adds r4, r2, 0
@08030E76:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =0x03005e00
	adds r0, r4, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r3, r0
	beq @08030EB8
	strh r3, [r4, 0x14]
	ldr r2, =0x02020630
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x1]
	adds r0, r5, 0
	movs r1, 0
	bl sub_8031ACC
	ldr r0, =sub_8030ED4
	str r0, [r4]
@08030EB8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_13

	thumb_func_start sub_8030ED4
sub_8030ED4: ; 8030ED4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	ldrb r5, [r4, 0xC]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0
	bne @08030F0C
	ldr r0, =0x02020630
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x4
	strh r0, [r1, 0x20]
	b @08030F72
	.pool
@08030F0C:
	ldr r3, =0x02020630
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq @08030F30
	ldrb r5, [r4, 0x1E]
	b @08030F32
	.pool
@08030F30:
	ldrb r5, [r4, 0x1C]
@08030F32:
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	adds r2, r3
	movs r0, 0xF0
	strh r0, [r2, 0x20]
	movs r0, 0x3C
	strh r0, [r2, 0x22]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	subs r0, 0x41
	ands r0, r1
	strb r0, [r3]
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r7
	strh r5, [r4, 0xC]
	ldrb r1, [r2, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x1]
	adds r0, r6, 0
	movs r1, 0
	bl sub_8031BAC
	ldr r0, =sub_8030F7C
	str r0, [r4]
@08030F72:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030ED4

	thumb_func_start sub_8030F7C
sub_8030F7C: ; 8030F7C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	ldrb r1, [r3, 0xC]
	ldr r2, =0x02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	ldrh r1, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0xB4
	ble @08030FB0
	subs r0, r1, 0x4
	strh r0, [r2, 0x20]
	b @08030FCA
	.pool
@08030FB0:
	movs r0, 0xB4
	strh r0, [r2, 0x20]
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq @08030FCA
	ldrb r0, [r2, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	strb r1, [r2, 0x1]
	ldr r0, =task_new_game_prof_birch_speech_13
	str r0, [r3]
@08030FCA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030F7C

	thumb_func_start task_new_game_prof_birch_speech_14
task_new_game_prof_birch_speech_14: ; 8030FD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_8032318
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8BFF
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_15
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_14

	thumb_func_start task_new_game_prof_birch_speech_15
task_new_game_prof_birch_speech_15: ; 8031014
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @08031032
	ldr r0, =0x03005e00
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_new_game_prof_birch_speech_16
	str r0, [r1]
@08031032:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_15

	thumb_func_start task_new_game_prof_birch_speech_16
task_new_game_prof_birch_speech_16: ; 8031040
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne @0803105C
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq @0803107A
@0803105C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl sub_80A1AD4
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_17
	str r1, [r0]
@0803107A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_16

	thumb_func_start task_new_game_prof_birch_speech_17
task_new_game_prof_birch_speech_17: ; 8031090
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne @080310EC
	bl Window_FreeMemory
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x1A]
	bl sub_818D820
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	bl set_default_player_name
	adds r0, r4, 0
	bl remove_task
	ldr r0, =0x03005d90
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	str r5, [sp]
	ldr r0, =new_game_prof_birch_speech_part2_start
	str r0, [sp, 0x4]
	movs r0, 0
	movs r3, 0
	bl do_choose_name_or_words_screen
@080310EC:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_17

	thumb_func_start task_new_game_prof_birch_speech_part2_2
task_new_game_prof_birch_speech_part2_2: ; 8031104
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_8032318
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8C1C
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_part2_3
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_2

	thumb_func_start task_new_game_prof_birch_speech_part2_3
task_new_game_prof_birch_speech_part2_3: ; 8031144
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @08031178
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0xF3
	movs r3, 0xDF
	bl sub_80323CC
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_part2_4
	str r1, [r0]
@08031178:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_3

	thumb_func_start task_new_game_prof_birch_speech_part2_4
task_new_game_prof_birch_speech_part2_4: ; 8031188
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq @080311AE
	cmp r1, 0
	bgt @080311A8
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq @080311FC
	b @08031210
@080311A8:
	cmp r1, 0x1
	beq @080311FC
	b @08031210
@080311AE:
	movs r0, 0x5
	bl audio_play
	ldr r2, =0x02020630
	ldr r0, =0x03005e00
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x1]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_8031ACC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8031C88
	ldr r0, =task_new_game_prof_birch_speech_part2_5
	str r0, [r4]
	b @08031210
	.pool
@080311FC:
	movs r0, 0x5
	bl audio_play
	ldr r0, =0x03005e00
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_new_game_prof_birch_speech_11
	str r0, [r1]
@08031210:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_4

	thumb_func_start task_new_game_prof_birch_speech_part2_5
task_new_game_prof_birch_speech_part2_5: ; 8031220
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0x10]
	movs r3, 0x10
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq @0803124C
	adds r0, r2, 0x2
	strh r0, [r1, 0x10]
	ldrh r1, [r1, 0x10]
	movs r0, 0x14
	bl lcd_io_set
	b @08031250
	.pool
@0803124C:
	ldr r0, =task_new_game_prof_birch_speech_part2_6
	str r0, [r1]
@08031250:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_5

	thumb_func_start task_new_game_prof_birch_speech_part2_6
task_new_game_prof_birch_speech_part2_6: ; 8031258
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq @08031320
	ldr r5, =0x02020630
	movs r2, 0x1C
	ldrsh r1, [r7, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	mov r12, r3
	mov r2, r12
	orrs r1, r2
	strb r1, [r0]
	movs r3, 0x1E
	ldrsh r1, [r7, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r7, 0x18]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r0, 0x88
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r4, 0x5
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r3]
	ldrb r3, [r1, 0x1]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	mov r3, r12
	orrs r0, r3
	strb r0, [r1, 0x1]
	ldrb r1, [r7, 0x1A]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x64
	strh r1, [r0, 0x20]
	movs r1, 0x4B
	strh r1, [r0, 0x22]
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	ands r4, r1
	strb r4, [r3]
	ldrb r1, [r0, 0x1]
	ands r2, r1
	mov r1, r12
	orrs r2, r1
	strb r2, [r0, 0x1]
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8031BAC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8031D34
	movs r0, 0
	bl sub_8032318
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8C2A
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r0, =task_new_game_prof_birch_speech_part2_7
	str r0, [r7]
@08031320:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_6

	thumb_func_start task_new_game_prof_birch_speech_part2_7
task_new_game_prof_birch_speech_part2_7: ; 803133C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq @080313D2
	ldr r7, =0x02020630
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne @080313D2
	movs r0, 0x18
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r2, [r0, 0x1]
	adds r1, r6, 0
	ands r1, r2
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r0, 0x1]
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x1]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_8031ACC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8031C88
	movs r0, 0x40
	strh r0, [r4, 0x16]
	ldr r0, =task_new_game_prof_birch_speech_part2_8
	str r0, [r4]
@080313D2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_7

	thumb_func_start task_new_game_prof_birch_speech_part2_8
task_new_game_prof_birch_speech_part2_8: ; 80313E4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0
	beq @080314B0
	ldr r2, =0x02020630
	movs r3, 0x18
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r0]
	movs r0, 0x1A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	ldrh r1, [r4, 0x16]
	movs r3, 0x16
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq @08031444
	subs r0, r1, 0x1
	strh r0, [r4, 0x16]
	b @080314B0
	.pool
@08031444:
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq @08031458
	ldrb r5, [r4, 0x1E]
	b @0803145A
	.pool
@08031458:
	ldrb r5, [r4, 0x1C]
@0803145A:
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r2
	movs r0, 0x78
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	subs r0, 0x41
	ands r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x1]
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r7
	strh r5, [r4, 0xC]
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8031BAC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8031D34
	ldr r0, =0x02021fc4
	ldr r1, =gUnknown_082C8C7A
	bl ExpandStringRefs
	movs r0, 0x1
	bl get_map_name
	ldr r0, =task_new_game_prof_birch_speech_part2_9
	str r0, [r4]
@080314B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_8

	thumb_func_start task_new_game_prof_birch_speech_part2_9
task_new_game_prof_birch_speech_part2_9: ; 80314C4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	movs r1, 0x12
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq @0803155C
	ldr r7, =0x02020630
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	bl sub_8197224
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	bne @0803155C
	ldrb r0, [r6, 0xC]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r5, r4, r7
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r5, 0x1]
	adds r0, r7, 0
	adds r0, 0x10
	adds r0, r4, r0
	ldr r1, =gUnknown_082FF114
	str r1, [r0]
	adds r0, r5, 0
	bl obj_alloc_rotscale_entry
	adds r0, r5, 0
	movs r1, 0
	bl sub_8008258
	adds r0, r7, 0
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_80318D8
	str r0, [r4]
	ldr r0, =0x0000ffff
	mov r1, r8
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl sub_80A1AD4
	movs r0, 0x4
	bl play_sound_effect
	ldr r0, =task_new_game_prof_birch_speech_part2_10
	str r0, [r6]
@0803155C:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_9

	thumb_func_start task_new_game_prof_birch_speech_part2_10
task_new_game_prof_birch_speech_part2_10: ; 8031580
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	ldrb r1, [r3, 0xC]
	ldr r2, =0x02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge @080315AA
	ldr r0, =task_new_game_prof_birch_speech_part2_11
	str r0, [r3]
@080315AA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_10

	thumb_func_start task_new_game_prof_birch_speech_part2_11
task_new_game_prof_birch_speech_part2_11: ; 80315BC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @0803160A
	ldr r0, =0x03005e00
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 3
	adds r4, r0
	ldrb r2, [r4, 0xC]
	ldr r1, =0x02020630
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =nullsub_11
	str r1, [r0]
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl lcd_io_set
	ldr r0, =0xffff0000
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl sub_80A1AD4
	ldr r0, =task_new_game_prof_birch_speech_part2_12
	str r0, [r4]
@0803160A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_11

	thumb_func_start task_new_game_prof_birch_speech_part2_12
task_new_game_prof_birch_speech_part2_12: ; 8031630
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x02037fd4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08031666
	bl Window_FreeMemory
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x1A]
	bl sub_818D820
	bl dp13_810BB8C
	ldr r0, =c2_new_game
	bl set_callback2
	adds r0, r4, 0
	bl remove_task
@08031666:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_12

	thumb_func_start new_game_prof_birch_speech_part2_start
new_game_prof_birch_speech_part2_start: ; 8031678
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	bl gpu_reset_bgs_and_dma3_busy_flags
	movs r0, 0
	movs r1, 0
	bl lcd_io_set
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl lcd_io_set
	ldr r1, =gUnknown_082FF0E8
	movs r0, 0
	movs r2, 0x2
	bl bg_vram_setup
	ldr r0, =gUnknown_082FF0F0
	bl bg_init_bg_config_2_from_bg_config_3
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0xC
	movs r1, 0
	bl lcd_io_set
	movs r0, 0xA
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x8
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x18
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x1A
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x14
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x16
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x10
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x12
	movs r1, 0
	bl lcd_io_set
	add r0, sp, 0x4
	movs r4, 0
	strh r4, [r0]
	ldr r1, =0x040000d4
	str r0, [r1]
	movs r4, 0xC0
	lsls r4, 19
	str r4, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0
	str r2, [sp, 0x8]
	add r0, sp, 0x8
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add r0, sp, 0x4
	strh r2, [r0]
	str r0, [r1]
	movs r0, 0xA0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x81000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl sub_80A1A74
	ldr r0, =gUnknown_082FED3C
	adds r1, r4, 0
	bl LZ77UnCompVram
	ldr r0, =gUnknown_082FEEF0
	ldr r1, =0x06003800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_082FECFC
	movs r1, 0
	movs r2, 0x40
	bl gpu_pal_apply
	ldr r0, =gUnknown_082FF01A
	movs r1, 0x1
	movs r2, 0x10
	bl gpu_pal_apply
	bl clear_tasks
	ldr r0, =task_new_game_prof_birch_speech_part2_1
	movs r1, 0
	bl AddTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x5
	strh r0, [r4, 0x16]
	ldr r0, =0x0000ffc4
	strh r0, [r4, 0x10]
	bl remove_some_task
	bl reset_all_obj_data
	bl gpu_pal_allocator_reset
	bl dp13_810BB8C
	adds r0, r5, 0
	bl sub_803192C
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq @080317DC
	movs r0, 0x1
	strh r0, [r4, 0x14]
	ldrb r3, [r4, 0x1E]
	b @080317E0
	.pool
@080317DC:
	strh r0, [r4, 0x14]
	ldrb r3, [r4, 0x1C]
@080317E0:
	ldr r0, =0x02020630
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	movs r4, 0
	movs r0, 0xB4
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r1, 0x3E
	ldrb r2, [r1]
	subs r0, 0x41
	ands r0, r2
	strb r0, [r1]
	ldr r1, =0x03005e00
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r3, [r0, 0xC]
	ldr r1, =0x0000ffc4
	movs r0, 0x14
	bl lcd_io_set
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl sub_80A1AD4
	movs r0, 0x40
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x44
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x48
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x4A
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x50
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0
	bl lcd_io_set
	movs r0, 0
	bl gpu_sync_bg_show
	movs r0, 0x1
	bl gpu_sync_bg_show
	ldr r3, =0x04000208
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, =0x04000200
	ldrh r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	ldr r0, =sub_802F6C8
	bl SetVBlankCallback
	ldr r0, =c2_title_menu_3
	bl set_callback2
	ldr r0, =gUnknown_082FF080
	bl Window_InitFromTemplates
	movs r0, 0
	movs r1, 0xF3
	bl unknown_title_pattern_data_to_vram
	movs r0, 0
	movs r1, 0xFC
	movs r2, 0xF0
	bl copy_textbox_border_tile_patterns_to_vram
	movs r0, 0
	bl Window_WriteStandardTileMap
	movs r0, 0
	movs r1, 0x3
	bl Window_CopyToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end new_game_prof_birch_speech_part2_start

	thumb_func_start nullsub_11
nullsub_11: ; 80318D4
	bx lr
	thumb_func_end nullsub_11

	thumb_func_start sub_80318D8
sub_80318D8: ; 80318D8
	movs r2, 0x22
	ldrsh r1, [r0, r2]
	lsls r1, 16
	movs r3, 0x2E
	ldrsh r2, [r0, r3]
	adds r1, r2
	movs r2, 0xC0
	lsls r2, 8
	adds r1, r2
	lsrs r2, r1, 16
	strh r2, [r0, 0x22]
	strh r1, [r0, 0x2E]
	bx lr
	thumb_func_end sub_80318D8

	thumb_func_start sub_80318F4
sub_80318F4: ; 80318F4
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =0x00000127
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r0, 0xE
	str r0, [sp, 0x8]
	ldr r0, =0x0000ffff
	str r0, [sp, 0xC]
	adds r0, r2, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_818D3E4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x10
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80318F4

	thumb_func_start sub_803192C
sub_803192C: ; 803192C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x88
	movs r1, 0x3C
	movs r2, 0x1
	bl sub_80B5F44
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x02020630
	mov r9, r1
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	movs r3, 0x1C
	add r3, r9
	mov r8, r3
	adds r1, r2, r3
	ldr r7, =nullsub_11
	str r7, [r1]
	add r2, r9
	ldrb r3, [r2, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x4
	mov r10, r3
	mov r3, r10
	orrs r1, r3
	strb r1, [r2]
	ldr r1, =0x03005e00
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r1
	strh r0, [r5, 0x18]
	movs r0, 0x64
	movs r1, 0x4B
	bl sub_80318F4
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	mov r4, r8
	adds r1, r2, r4
	str r7, [r1]
	add r2, r9
	ldrb r3, [r2, 0x5]
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	mov r3, r10
	orrs r1, r3
	strb r1, [r2]
	strh r0, [r5, 0x1A]
	movs r0, 0x3C
	bl sub_806EFF0
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =0x0201c000
	str r4, [sp]
	movs r1, 0x78
	movs r2, 0x3C
	movs r3, 0
	bl sub_80B5E6C
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	mov r3, r8
	adds r1, r2, r3
	str r7, [r1]
	add r2, r9
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	mov r4, r10
	orrs r1, r4
	strb r1, [r3]
	ldrb r3, [r2, 0x5]
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x5]
	strh r0, [r5, 0x1C]
	movs r0, 0x3F
	bl sub_806EFF0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x0201c000
	movs r2, 0x80
	lsls r2, 4
	adds r4, r1, r2
	str r4, [sp]
	movs r1, 0x78
	movs r2, 0x3C
	movs r3, 0
	bl sub_80B5E6C
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r8, r2
	mov r3, r8
	str r7, [r3]
	add r2, r9
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	mov r4, r10
	orrs r1, r4
	strb r1, [r3]
	ldrb r1, [r2, 0x5]
	ands r6, r1
	strb r6, [r2, 0x5]
	strh r0, [r5, 0x1E]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803192C

	thumb_func_start waterfall_4_check_if_can_continue
waterfall_4_check_if_can_continue: ; 8031A5C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =0x03005e00
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r2, r0, r4
	ldrh r1, [r2, 0xA]
	movs r5, 0xA
	ldrsh r0, [r2, r5]
	cmp r0, 0
	bne @08031A94
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x1
	strh r0, [r1, 0x12]
	adds r0, r3, 0
	bl remove_task
	b @08031AC4
	.pool
@08031A94:
	ldrh r3, [r2, 0x10]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	cmp r0, 0
	beq @08031AA4
	subs r0, r3, 0x1
	strh r0, [r2, 0x10]
	b @08031AC4
@08031AA4:
	ldrh r0, [r2, 0xE]
	strh r0, [r2, 0x10]
	subs r1, 0x1
	strh r1, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	lsls r0, 8
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl lcd_io_set
@08031AC4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end waterfall_4_check_if_can_continue

	thumb_func_start sub_8031ACC
sub_8031ACC: ; 8031ACC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x94
	lsls r1, 2
	movs r0, 0x50
	bl lcd_io_set
	movs r0, 0x52
	movs r1, 0x10
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0
	bl lcd_io_set
	ldr r0, =0x03005e00
	mov r8, r0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r6, 0
	strh r6, [r0, 0x12]
	ldr r0, =waterfall_4_check_if_can_continue
	movs r1, 0
	bl AddTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	add r1, r8
	strh r4, [r1, 0x8]
	movs r0, 0x10
	strh r0, [r1, 0xA]
	strh r6, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031ACC

	thumb_func_start sub_8031B3C
sub_8031B3C: ; 8031B3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =0x03005e00
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r2, r0, r4
	ldrh r1, [r2, 0xA]
	movs r5, 0xA
	ldrsh r0, [r2, r5]
	cmp r0, 0x10
	bne @08031B74
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x1
	strh r0, [r1, 0x12]
	adds r0, r3, 0
	bl remove_task
	b @08031BA4
	.pool
@08031B74:
	ldrh r3, [r2, 0x10]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	cmp r0, 0
	beq @08031B84
	subs r0, r3, 0x1
	strh r0, [r2, 0x10]
	b @08031BA4
@08031B84:
	ldrh r0, [r2, 0xE]
	strh r0, [r2, 0x10]
	adds r1, 0x1
	strh r1, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	subs r0, 0x1
	strh r0, [r2, 0xC]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	lsls r0, 8
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl lcd_io_set
@08031BA4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8031B3C

	thumb_func_start sub_8031BAC
sub_8031BAC: ; 8031BAC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x94
	lsls r1, 2
	movs r0, 0x50
	bl lcd_io_set
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl lcd_io_set
	movs r0, 0x54
	movs r1, 0
	bl lcd_io_set
	ldr r0, =0x03005e00
	mov r8, r0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r6, 0
	strh r6, [r0, 0x12]
	ldr r0, =sub_8031B3C
	movs r1, 0
	bl AddTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	add r1, r8
	strh r4, [r1, 0x8]
	strh r6, [r1, 0xA]
	movs r0, 0x10
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031BAC

	thumb_func_start sub_8031C1C
sub_8031C1C: ; 8031C1C
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	ldrh r3, [r1, 0xC]
	movs r4, 0xC
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq @08031C40
	subs r0, r3, 0x1
	strh r0, [r1, 0xC]
	b @08031C7C
	.pool
@08031C40:
	ldrh r3, [r1, 0xA]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r0, 0x8
	bne @08031C52
	adds r0, r2, 0
	bl remove_task
	b @08031C7C
@08031C52:
	ldrh r2, [r1, 0x10]
	movs r4, 0x10
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq @08031C62
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	b @08031C7C
@08031C62:
	ldrh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	adds r0, r3, 0x1
	strh r0, [r1, 0xA]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	lsls r0, 1
	ldr r1, =gUnknown_082FF018
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x10
	bl gpu_pal_apply
@08031C7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031C1C

	thumb_func_start sub_8031C88
sub_8031C88: ; 8031C88
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sub_8031C1C
	movs r1, 0
	bl AddTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r4, [r1, 0x8]
	strh r0, [r1, 0xA]
	movs r0, 0x8
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031C88

	thumb_func_start sub_8031CC8
sub_8031CC8: ; 8031CC8
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	ldrh r3, [r1, 0xC]
	movs r4, 0xC
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq @08031CEC
	subs r0, r3, 0x1
	strh r0, [r1, 0xC]
	b @08031D28
	.pool
@08031CEC:
	ldrh r3, [r1, 0xA]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne @08031CFE
	adds r0, r2, 0
	bl remove_task
	b @08031D28
@08031CFE:
	ldrh r2, [r1, 0x10]
	movs r4, 0x10
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq @08031D0E
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	b @08031D28
@08031D0E:
	ldrh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	subs r0, r3, 0x1
	strh r0, [r1, 0xA]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	lsls r0, 1
	ldr r1, =gUnknown_082FF018
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x10
	bl gpu_pal_apply
@08031D28:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031CC8

	thumb_func_start sub_8031D34
sub_8031D34: ; 8031D34
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sub_8031CC8
	movs r1, 0
	bl AddTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	movs r0, 0x8
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031D34

	thumb_func_start sub_8031D74
sub_8031D74: ; 8031D74
	push {lr}
	ldr r0, =gUnknown_082FF088
	movs r1, 0xF3
	bl write_textbox_border_to_bg_tilemap
	movs r0, 0x1
	movs r1, 0x11
	bl Window_FastFillPixels
	ldr r2, =gUnknown_082FF118
	movs r0, 0x1
	movs r1, 0x2
	bl PrintMenuTable
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0x1
	bl Window_WriteStandardTileMap
	movs r0, 0x1
	movs r1, 0x3
	bl Window_CopyToVram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031D74

	thumb_func_start sub_8031DB4
sub_8031DB4: ; 8031DB4
	push {lr}
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8031DB4

	thumb_func_start set_default_player_name
; void set_default_player_name(int name_id)
set_default_player_name: ; 8031DC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x03005d90
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	adds r5, r1, 0
	cmp r0, 0
	bne @08031DE4
	ldr r1, =gUnknown_082FF128
	b @08031DE6
	.pool
@08031DE4:
	ldr r1, =gUnknown_082FF178
@08031DE6:
	lsls r0, r2, 2
	adds r0, r1
	ldr r3, [r0]
	movs r2, 0
	ldr r4, =0x03005d90
@08031DF0:
	ldr r1, [r4]
	adds r1, r2
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x6
	bls @08031DF0
	ldr r1, [r5]
	movs r0, 0xFF
	strb r0, [r1, 0x7]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_default_player_name

	thumb_func_start draw_text_box
; void draw_text_box(void *text_ptr)
draw_text_box: ; 8031E18
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0x7
	movs r1, 0x11
	bl Window_FastFillPixels
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x7
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl Print
	movs r0, 0x7
	bl Window_WriteStandardTileMap
	movs r0, 0x7
	movs r1, 0x2
	bl Window_CopyToVram
	ldr r0, =gUnknown_082FF070
	ldr r1, =0x000001d5
	bl write_textbox_border_to_bg_tilemap
	ldr r1, =0x000009e7
	movs r0, 0x40
	bl lcd_io_set
	ldr r1, =0x0000719f
	movs r0, 0x44
	bl lcd_io_set
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end draw_text_box

	thumb_func_start fmt_savegame
fmt_savegame: ; 8031E7C
	push {lr}
	bl fmt_time
	bl fmt_pokedex
	bl fmt_player
	bl fmt_badges
	pop {r0}
	bx r0
	thumb_func_end fmt_savegame

	thumb_func_start fmt_time
fmt_time: ; 8031E94
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r4, =0x02021fc4
	ldr r1, =gUnknown_085EDCC3
	adds r0, r4, 0
	bl ExpandStringRefs
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x11
	bl box_print
	ldr r4, =0x03005d90
	ldr r1, [r4]
	movs r0, 0x1
	movs r2, 0x64
	bl sub_81DB368
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	ldr r0, [r4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_time

	thumb_func_start fmt_player
fmt_player: ; 8031EF8
	push {r4-r6,lr}
	sub sp, 0x2C
	ldr r4, =0x02021fc4
	ldr r1, =gUnknown_085EDCCA
	adds r0, r4, 0
	bl ExpandStringRefs
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x6C
	movs r3, 0x11
	bl box_print
	ldr r4, =0x03005d90
	ldr r0, [r4]
	ldrh r1, [r0, 0xE]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalString
	movs r1, 0xF0
	strb r1, [r0]
	adds r0, 0x1
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalString
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0xD0
	bl sub_81DB368
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_player

	thumb_func_start fmt_pokedex
fmt_pokedex: ; 8031F7C
	push {r4-r7,lr}
	sub sp, 0x2C
	ldr r0, =0x00000861
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne @08031FFE
	bl sub_809D42C
	cmp r0, 0
	beq @08031FA4
	movs r0, 0x1
	bl pokedex_count
	b @08031FAA
	.pool
@08031FA4:
	movs r0, 0x1
	bl sub_80C0844
@08031FAA:
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r4, =0x02021fc4
	ldr r1, =gUnknown_085EDCCF
	adds r0, r4, 0
	bl ExpandStringRefs
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x21
	bl box_print
	add r0, sp, 0xC
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalString
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x64
	bl sub_81DB368
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x21
	bl box_print
@08031FFE:
	add sp, 0x2C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_pokedex

	thumb_func_start fmt_badges
fmt_badges: ; 8032014
	push {r4-r7,lr}
	sub sp, 0x2C
	movs r7, 0
	ldr r4, =0x00000867
@0803201C:
	lsls r0, r4, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq @08032030
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
@08032030:
	adds r4, 0x1
	ldr r0, =0x0000086e
	cmp r4, r0
	bls @0803201C
	ldr r4, =0x02021fc4
	ldr r1, =gUnknown_085EDCD7
	adds r0, r4, 0
	bl ExpandStringRefs
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x6C
	movs r3, 0x21
	bl box_print
	add r0, sp, 0xC
	adds r1, r7, 0
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalString
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0xD0
	bl sub_81DB368
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x21
	bl box_print
	add sp, 0x2C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_badges

	thumb_func_start unknown_title_pattern_data_to_vram
unknown_title_pattern_data_to_vram: ; 80320A4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =0x03005d90
	ldr r0, [r6]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8098758
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	adds r0, r4, 0
	adds r3, r5, 0
	bl gpu_copy_bg_tile_pattern_data_to_vram
	ldr r0, [r6]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8098758
	ldr r0, [r0, 0x4]
	movs r1, 0x20
	movs r2, 0x20
	bl gpu_pal_apply
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_title_pattern_data_to_vram

	thumb_func_start write_textbox_border_to_bg_tilemap
; void write_textbox_border_to_bg_tilemap(struct rbox_template *box, int base_tile_num)
write_textbox_border_to_bg_tilemap: ; 80320EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r4, r0, 0
	lsls r6, r1, 16
	movs r0, 0x80
	lsls r0, 9
	adds r0, r6
	lsrs r0, 16
	mov r9, r0
	movs r1, 0x80
	lsls r1, 10
	adds r1, r6
	lsrs r1, 16
	mov r10, r1
	movs r7, 0xC0
	lsls r7, 10
	adds r1, r6, r7
	lsrs r1, 16
	str r1, [sp, 0x18]
	movs r0, 0xA0
	lsls r0, 11
	adds r1, r6, r0
	lsrs r1, 16
	str r1, [sp, 0xC]
	movs r7, 0xC0
	lsls r7, 11
	adds r1, r6, r7
	lsrs r1, 16
	str r1, [sp, 0x10]
	movs r0, 0xE0
	lsls r0, 11
	adds r1, r6, r0
	lsrs r1, 16
	str r1, [sp, 0x14]
	lsrs r1, r6, 16
	movs r7, 0x80
	lsls r7, 12
	adds r6, r7
	lsrs r6, 16
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r7, 0x2
	mov r8, r7
	str r7, [sp, 0x8]
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r4, 0x3]
	str r1, [sp]
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	mov r1, r9
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r1, [r4, 0x1]
	adds r2, r1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	mov r1, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r1, [r4, 0x4]
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	ldr r1, [sp, 0x18]
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r7, [r4, 0x1]
	adds r2, r7
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r1, [r4, 0x4]
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	ldr r1, [sp, 0xC]
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r7, [r4, 0x2]
	adds r3, r7
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	ldr r1, [sp, 0x10]
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x4]
	ldrb r7, [r4, 0x2]
	adds r3, r7
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r4, 0x3]
	str r1, [sp]
	str r5, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	ldr r1, [sp, 0x14]
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r7, [r4, 0x1]
	adds r2, r7
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r1, [r4, 0x2]
	adds r3, r1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r7, r8
	str r7, [sp, 0x8]
	adds r1, r6, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r4]
	bl gpu_copy_wram_bg_tilemap_to_vram
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end write_textbox_border_to_bg_tilemap

	thumb_func_start sub_8032250
sub_8032250: ; 8032250
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldrb r0, [r6]
	ldrb r1, [r6, 0x1]
	subs r2, r1, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r4, [r6, 0x2]
	subs r3, r4, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r5, [r6, 0x3]
	adds r1, r5
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	ldrb r1, [r6, 0x4]
	adds r4, r1
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldrb r0, [r6]
	bl gpu_copy_wram_bg_tilemap_to_vram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8032250

	thumb_func_start sub_8032298
sub_8032298: ; 8032298
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r1, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsls r5, 24
	lsls r3, 24
	lsls r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r4, r2
	lsrs r4, 24
	adds r5, r2
	lsrs r5, 24
	movs r2, 0x80
	lsls r2, 18
	adds r3, r2
	lsrs r3, 24
	str r3, [sp]
	adds r1, r2
	lsrs r1, 24
	str r1, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8032298

	thumb_func_start sub_80322E0
sub_80322E0: ; 80322E0
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_8032298
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl Window_FastFillPixels
	adds r0, r5, 0
	bl Window_FillTileMap
	cmp r4, 0x1
	bne @0803230E
	adds r0, r5, 0
	movs r1, 0x3
	bl Window_CopyToVram
@0803230E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80322E0

	thumb_func_start sub_8032318
sub_8032318: ; 8032318
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x1
	movs r1, 0x6
	bl fbox_get_field
	mov r9, r0
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0x1
	movs r1, 0
	bl fbox_get_field
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x1
	movs r1, 0x1
	bl fbox_get_field
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0x3
	bl Window_GetField
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0x4
	bl Window_GetField
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	muls r1, r4
	str r1, [sp]
	muls r0, r5
	str r0, [sp, 0x4]
	adds r0, r6, 0
	mov r1, r9
	movs r2, 0
	movs r3, 0
	bl Window_FillPixelRect
	adds r0, r6, 0
	movs r1, 0x2
	bl Window_CopyToVram
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8032318

	thumb_func_start sub_80323A0
sub_80323A0: ; 80323A0
	push {lr}
	ldr r0, [r0]
	subs r0, 0x2
	ldrb r0, [r0]
	cmp r0, 0x8
	bne @080323C0
	ldr r1, =0x02022d04
	ldrb r0, [r1]
	cmp r0, 0
	bne @080323C0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =sub_8030A70
	movs r1, 0
	bl AddTask
@080323C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80323A0

	thumb_func_start sub_80323CC
sub_80323CC: ; 80323CC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	ldr r6, [sp, 0x34]
	ldr r1, [sp, 0x38]
	lsls r4, 24
	lsls r5, 24
	mov r0, r8
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x80
	lsls r0, 17
	adds r4, r0
	lsrs r4, 24
	adds r5, r0
	lsrs r5, 24
	movs r0, 0x5
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r3, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_8198A50
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	add r0, sp, 0x18
	mov r1, r8
	adds r2, r6, 0
	movs r3, 0
	bl sub_81996C0
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80323CC

	thumb_func_start unknown_rbox_to_vram
unknown_rbox_to_vram: ; 803243C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_8032474
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl Window_FastFillPixels
	adds r0, r5, 0
	bl Window_WriteStandardTileMap
	cmp r4, 0x1
	bne @0803246A
	adds r0, r5, 0
	movs r1, 0x3
	bl Window_CopyToVram
@0803246A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_rbox_to_vram

	thumb_func_start sub_8032474
sub_8032474: ; 8032474
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	adds r5, r2, 0
	mov r9, r3
	ldr r0, [sp, 0x40]
	ldr r6, [sp, 0x44]
	mov r2, r8
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r1, 24
	lsls r5, 24
	mov r2, r9
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r6, 24
	lsrs r6, 24
	lsrs r0, r1, 24
	str r0, [sp, 0xC]
	movs r2, 0xFE
	lsls r2, 24
	adds r1, r2
	lsrs r1, 24
	str r1, [sp, 0x14]
	lsrs r0, r5, 24
	mov r10, r0
	movs r2, 0xFF
	lsls r2, 24
	adds r5, r2
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0xFD
	ldr r2, [sp, 0x14]
	adds r3, r5, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r0, [sp, 0xC]
	subs r0, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0xFF
	adds r3, r5, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	movs r1, 0x80
	lsls r1, 1
	mov r0, r9
	str r0, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0xC]
	adds r3, r5, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x00000101
	ldr r7, [sp, 0xC]
	add r7, r9
	subs r0, r7, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r3, r5, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	movs r1, 0x81
	lsls r1, 1
	lsls r2, r7, 24
	lsrs r7, r2, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	adds r3, r5, 0
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x00000103
	str r4, [sp]
	movs r5, 0x5
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x00000105
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	movs r1, 0x83
	lsls r1, 1
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x000008fd
	ldr r2, [sp, 0x10]
	add r10, r2
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x000008ff
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	movs r1, 0x90
	lsls r1, 4
	movs r2, 0x1
	negs r2, r2
	add r9, r2
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0xC]
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x00000901
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x1C]
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	ldr r1, =0x00000902
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	mov r3, r10
	bl Bg_FillWramTileMapRectWithTileAndPalette
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8032474

	thumb_func_start task_new_game_prof_birch_speech_part2_1
task_new_game_prof_birch_speech_part2_1: ; 803261C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x16]
	subs r1, r0, 0x1
	strh r1, [r4, 0x16]
	lsls r0, 16
	cmp r0, 0
	bgt @08032644
	movs r0, 0
	movs r1, 0x1
	bl unknown_rbox_to_vram
	ldr r0, =task_new_game_prof_birch_speech_part2_2
	str r0, [r4]
@08032644:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_1
