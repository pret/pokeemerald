	thumb_func_start Main
Main:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0xFF
	bl RegisterRamReset
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x00007fff
	adds r0, r2, 0
	strh r0, [r1]
	bl lcd_io_copy_queue_clean
	ldr r1, =0x04000204
	ldr r3, =0x00004014
	adds r0, r3, 0
	strh r0, [r1]
	bl init_keypad_data
	bl init_irq_handler
	bl m4aSoundInit
	bl lcd_enable_vcount_irq_at_150px
	bl sub_800E6D0
	bl sub_802F21C
	bl flash_timeout_start_on_timer_2_when_flash_present
	bl init_saveblock_ptrs_and_set_copyright_callback2
	bl sound_sources_off
	bl ClearDma3Requests
	bl gpu_init_bgs
	bl fboxes_set_default_ptr
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl init_malloc
	ldr r0, =0x03002700
	movs r4, 0
	strb r4, [r0]
	ldr r0, =0x03005d88
	ldr r0, [r0]
	cmp r0, 0x1
	beq @08000414
	movs r0, 0
	bl set_callback2
@08000414:
	ldr r2, =0x030022b4
	strb r4, [r2]
	ldr r1, =0x03000000
	movs r3, 0xFC
	lsls r3, 4
	adds r0, r3, 0
	strh r0, [r1]
	ldr r7, =0x030022c0
	movs r0, 0
	mov r8, r0
	adds r6, r2, 0
@0800042A:
	bl load_keys
	ldr r0, =0x03002700
	ldrb r0, [r0]
	cmp r0, 0
	bne @08000454
	ldrh r1, [r7, 0x28]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq @08000454
	movs r0, 0xE
	ands r0, r1
	cmp r0, 0xE
	bne @08000454
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	bl do_reset
@08000454:
	bl sub_8087634
	cmp r0, 0x1
	bne @0800048C
	strb r0, [r6]
	bl call_callbacks_wrapper
	movs r0, 0
	strb r0, [r6]
	b @080004B2
	.align 2, 0
	.pool
@0800048C:
	ldr r5, =0x030022b4
	movs r0, 0
	strb r0, [r5]
	bl call_callbacks_wrapper
	bl sub_80875C8
	adds r4, r0, 0
	cmp r4, 0x1
	bne @080004B2
	movs r0, 0
	strh r0, [r7, 0x2E]
	bl copy_queue_clear
	strb r4, [r5]
	bl call_callbacks_wrapper
	mov r2, r8
	strb r2, [r5]
@080004B2:
	bl gametime_increment
	bl sound_something
	bl wait_for_vblank
	b @0800042A
	.align 2, 0
	.pool
	thumb_func_end Main

	thumb_func_start call_callbacks_wrapper
; void call_callbacks_wrapper()
call_callbacks_wrapper: ; 80004C4
	push {lr}
	bl sub_800B40C
	lsls r0, 24
	cmp r0, 0
	bne @080004D4
	bl call_callbacks
@080004D4:
	pop {r0}
	bx r0
	thumb_func_end call_callbacks_wrapper

	thumb_func_start init_saveblock_ptrs_and_set_copyright_callback2
; void init_saveblock_ptrs_and_set_copyright_callback2()
init_saveblock_ptrs_and_set_copyright_callback2: ; 80004D8
	push {lr}
	ldr r2, =0x030022c0
	movs r0, 0
	str r0, [r2, 0x20]
	ldr r1, =0x0203cf5c
	str r0, [r1]
	str r0, [r2, 0x24]
	str r0, [r2]
	ldr r0, =c2_copyright_1
	bl set_callback2
	ldr r1, =0x03005d90
	ldr r0, =0x02024a54
	str r0, [r1]
	ldr r1, =0x03005d94
	ldr r0, =0x02029808
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end init_saveblock_ptrs_and_set_copyright_callback2

	thumb_func_start call_callbacks
; void call_callbacks()
call_callbacks: ; 800051C
	push {r4,lr}
	ldr r4, =0x030022c0
	ldr r0, [r4]
	cmp r0, 0
	beq @0800052A
	bl _call_via_r0
@0800052A:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq @08000534
	bl _call_via_r0
@08000534:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end call_callbacks

	thumb_func_start set_callback2
; void set_callback2(void ( *func)())
set_callback2: ; 8000540
	ldr r1, =0x030022c0
	str r0, [r1, 0x4]
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end set_callback2

	thumb_func_start start_timer1
; void start_timer1()
start_timer1: ; 8000554
	ldr r1, =0x04000106
	movs r0, 0x80
	strh r0, [r1]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end start_timer1

	thumb_func_start set_rand_seed_and_trainer_id_hi
; void set_rand_seed_and_trainer_id_hi()
set_rand_seed_and_trainer_id_hi: ; 8000560
	push {r4,lr}
	ldr r0, =0x04000104
	ldrh r4, [r0]
	adds r0, r4, 0
	bl SeedRng
	ldr r1, =0x04000106
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x02020000
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end set_rand_seed_and_trainer_id_hi

	thumb_func_start get_trainer_id_hi
; u16 get_trainer_id_hi()
get_trainer_id_hi: ; 8000588
	ldr r0, =0x02020000
	ldrh r0, [r0]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end get_trainer_id_hi

	thumb_func_start lcd_enable_vcount_irq_at_150px
; void lcd_enable_vcount_irq_at_150px()
lcd_enable_vcount_irq_at_150px: ; 8000594
	push {lr}
	movs r0, 0x4
	bl lcd_io_get
	movs r1, 0xFF
	ands r1, r0
	movs r2, 0x96
	lsls r2, 8
	adds r0, r2, 0
	orrs r1, r0
	movs r0, 0x20
	orrs r1, r0
	movs r0, 0x4
	bl lcd_io_set
	movs r0, 0x4
	bl enable_irqs
	pop {r0}
	bx r0
	thumb_func_end lcd_enable_vcount_irq_at_150px

	thumb_func_start init_keypad_data
; void init_keypad_data()
init_keypad_data: ; 80005BC
	ldr r1, =0x030026fc
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =0x030022b0
	movs r0, 0x28
	strh r0, [r1]
	ldr r1, =0x030022c0
	movs r0, 0
	strh r0, [r1, 0x2C]
	strh r0, [r1, 0x2E]
	strh r0, [r1, 0x30]
	strh r0, [r1, 0x28]
	strh r0, [r1, 0x2A]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end init_keypad_data

	thumb_func_start load_keys
; void load_keys()
load_keys: ; 80005E4
	push {lr}
	ldr r0, =0x04000130
	ldrh r1, [r0]
	ldr r2, =0x000003ff
	adds r0, r2, 0
	adds r3, r0, 0
	eors r3, r1
	ldr r1, =0x030022c0
	ldrh r2, [r1, 0x28]
	adds r0, r3, 0
	bics r0, r2
	strh r0, [r1, 0x2A]
	strh r0, [r1, 0x2E]
	strh r0, [r1, 0x30]
	adds r2, r1, 0
	cmp r3, 0
	beq @08000630
	ldrh r0, [r2, 0x2C]
	cmp r0, r3
	bne @08000630
	ldrh r0, [r2, 0x32]
	subs r0, 0x1
	strh r0, [r2, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne @08000636
	strh r3, [r2, 0x30]
	ldr r0, =0x030026fc
	b @08000632
	.align 2, 0
	.pool
@08000630:
	ldr r0, =0x030022b0
@08000632:
	ldrh r0, [r0]
	strh r0, [r2, 0x32]
@08000636:
	strh r3, [r2, 0x28]
	strh r3, [r2, 0x2C]
	ldr r0, =0x03005d90
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne @08000668
	ldrh r1, [r2, 0x2E]
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq @08000658
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2, 0x2E]
@08000658:
	ldrh r1, [r2, 0x2C]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq @08000668
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2, 0x2C]
@08000668:
	ldrh r1, [r2, 0x2E]
	ldrh r0, [r2, 0x36]
	ands r0, r1
	cmp r0, 0
	beq @08000676
	movs r0, 0x1
	strh r0, [r2, 0x34]
@08000676:
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end load_keys

	thumb_func_start init_irq_handler
; void init_irq_handler()
init_irq_handler: ; 8000684
	push {r4,r5,lr}
	ldr r5, =InterruptMain
	ldr r4, =0x03002750
	ldr r3, =gRomInterruptTable
	ldr r2, =0x03002710
	movs r1, 0xD
@08000690:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, 0x1
	cmp r1, 0
	bge @08000690
	ldr r0, =0x040000d4
	str r5, [r0]
	str r4, [r0, 0x4]
	ldr r1, =0x84000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	ldr r0, =0x03007ffc
	str r4, [r0]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl set_serial_callback
	ldr r1, =0x04000208
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x1
	bl enable_irqs
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end init_irq_handler

	thumb_func_start SetVBlankCallback
; void SetVBlankCallback(void ( *func)())
SetVBlankCallback: ; 80006F0
	ldr r1, =0x030022c0
	str r0, [r1, 0xC]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end SetVBlankCallback

	thumb_func_start SetHBlankCallback
; void SetHBlankCallback(void ( *func)())
SetHBlankCallback: ; 80006FC
	ldr r1, =0x030022c0
	str r0, [r1, 0x10]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end SetHBlankCallback

	thumb_func_start SetVCountCallback
SetVCountCallback: ; 8000708
	ldr r1, =0x030022c0
	str r0, [r1, 0x14]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end SetVCountCallback

	thumb_func_start restore_serial_timer3_irq_handlers
; void restore_serial_timer3_irq_handlers()
restore_serial_timer3_irq_handlers: ; 8000714
	ldr r0, =0x03002710
	ldr r1, =irq_serial
	str r1, [r0, 0x4]
	ldr r1, =irq_timer3
	str r1, [r0, 0x8]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end restore_serial_timer3_irq_handlers

	thumb_func_start set_serial_callback
; void set_serial_callback(void ( *func)())
set_serial_callback: ; 800072C
	ldr r1, =0x030022c0
	str r0, [r1, 0x18]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end set_serial_callback

	thumb_func_start irq_vblank
; void irq_vblank()
irq_vblank: ; 8000738
	push {r4,lr}
	ldr r0, =0x030030fc
	ldrb r0, [r0]
	cmp r0, 0
	beq @0800074C
	bl rfu_syncVBlank__
	b @08000758
	.align 2, 0
	.pool
@0800074C:
	ldr r0, =0x03002748
	ldrb r0, [r0]
	cmp r0, 0
	bne @08000758
	bl sub_800B9B8
@08000758:
	ldr r0, =0x030022c0
	ldr r1, [r0, 0x20]
	adds r1, 0x1
	str r1, [r0, 0x20]
	ldr r1, =0x0203cf5c
	ldr r1, [r1]
	adds r4, r0, 0
	cmp r1, 0
	beq @08000778
	ldr r2, [r1]
	movs r0, 0x2
	negs r0, r0
	cmp r2, r0
	bhi @08000778
	adds r0, r2, 0x1
	str r0, [r1]
@08000778:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq @08000782
	bl _call_via_r0
@08000782:
	ldr r0, [r4, 0x24]
	adds r0, 0x1
	str r0, [r4, 0x24]
	bl lcd_io_copy_queue_process
	bl ProcessDma3Requests
	ldr r1, =0x03002f50
	ldr r0, =0x03006380
	ldrb r0, [r0, 0x4]
	strb r0, [r1]
	bl m4aSoundMain
	bl sub_8033648
	ldr r1, =0x00000439
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq @080007BA
	ldr r0, =0x02022fec
	ldr r0, [r0]
	ldr r1, =0x013f0102
	ands r0, r1
	cmp r0, 0
	bne @080007BE
@080007BA:
	bl GenerateRandomNumber
@080007BE:
	bl sub_800E174
	ldr r2, =0x03007ff8
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, =0x030022c0
	ldrh r2, [r0, 0x1C]
	ldrh r3, [r0, 0x1C]
	orrs r1, r2
	strh r1, [r0, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end irq_vblank

	thumb_func_start flash_timeout_start_on_timer_2
; void flash_timeout_start_on_timer_2()
flash_timeout_start_on_timer_2: ; 8000800
	push {lr}
	ldr r1, =0x0300272c
	movs r0, 0x2
	bl SetFlashTimerIntr
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end flash_timeout_start_on_timer_2

	thumb_func_start irq_hblank
; void irq_hblank()
irq_hblank: ; 8000814
	push {r4,lr}
	ldr r4, =0x030022c0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq @08000822
	bl _call_via_r0
@08000822:
	ldr r2, =0x03007ff8
	ldrh r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1C]
	orrs r1, r0
	strh r1, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end irq_hblank

	thumb_func_start irq_vcount
; void irq_vcount()
irq_vcount: ; 8000844
	push {r4,lr}
	ldr r4, =0x030022c0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq @08000852
	bl _call_via_r0
@08000852:
	bl SoundVSync_rev01
	ldr r2, =0x03007ff8
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1C]
	orrs r1, r0
	strh r1, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end irq_vcount

	thumb_func_start irq_serial
; void irq_serial()
irq_serial: ; 8000878
	push {r4,lr}
	ldr r4, =0x030022c0
	ldr r0, [r4, 0x18]
	cmp r0, 0
	beq @08000886
	bl _call_via_r0
@08000886:
	ldr r2, =0x03007ff8
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1C]
	orrs r1, r0
	strh r1, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end irq_serial

	thumb_func_start irq_other
; void irq_other()
irq_other: ; 80008A8
	bx lr
	thumb_func_end irq_other

	thumb_func_start wait_for_vblank
; void wait_for_vblank()
wait_for_vblank: ; 80008AC
	push {lr}
	ldr r2, =0x030022c0
	ldrh r1, [r2, 0x1C]
	ldr r0, =0x0000fffe
	ands r0, r1
	ldrh r1, [r2, 0x1C]
	strh r0, [r2, 0x1C]
	ldrh r1, [r2, 0x1C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne @080008D0
	movs r3, 0x1
@080008C6:
	ldrh r1, [r2, 0x1C]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq @080008C6
@080008D0:
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end wait_for_vblank

	thumb_func_start sub_80008DC
sub_80008DC: ; 80008DC
	ldr r1, =0x0203cf5c
	str r0, [r1]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_80008DC

	thumb_func_start sub_80008E8
sub_80008E8: ; 80008E8
	ldr r1, =0x0203cf5c
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_80008E8

	thumb_func_start do_reset
; void do_reset()
do_reset: ; 80008F4
	push {r4,lr}
	ldr r1, =0x04000208
	movs r0, 0
	strh r0, [r1]
	bl SoundVSyncOff_rev01
	bl remove_some_task
	ldr r1, =0x040000bc
	ldrh r2, [r1, 0xA]
	ldr r3, =0x0000c5ff
	adds r0, r3, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r4, [r1, 0xA]
	ldr r2, =0x00007fff
	adds r0, r2, 0
	ands r0, r4
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	adds r1, 0xC
	ldrh r4, [r1, 0xA]
	adds r0, r3, 0
	ands r0, r4
	strh r0, [r1, 0xA]
	ldrh r4, [r1, 0xA]
	adds r0, r2, 0
	ands r0, r4
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	ldr r0, =0x040000d4
	ldrh r1, [r0, 0xA]
	ands r3, r1
	strh r3, [r0, 0xA]
	ldrh r1, [r0, 0xA]
	ands r2, r1
	strh r2, [r0, 0xA]
	ldrh r0, [r0, 0xA]
	bl sub_82E2168
	movs r0, 0xFF
	bl SoftReset
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end do_reset

	thumb_func_start sub_8000964
sub_8000964: ; 8000964
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x03007330
	ldr r2, =0x01000034
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end sub_8000964
