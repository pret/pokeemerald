	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_801F5EC
sub_801F5EC: @ 801F5EC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	ldr r3, =gUnknown_02022C88
	ldr r0, [r3]
	lsrs r1, 21
	adds r0, r1
	ldr r2, =sub_801FDD8
	str r2, [r0]
	movs r4, 0
	adds r5, r3, 0
	adds r3, r1, 0
	mov r12, r4
	ldr r1, =gUnknown_082F2C98
	movs r7, 0x1
	adds r2, r1, 0x4
_0801F60E:
	ldrh r0, [r1]
	cmp r0, r6
	bne _0801F634
	ldr r1, [r5]
	adds r1, r3
	ldr r0, [r2]
	str r0, [r1]
	strb r7, [r1, 0x4]
	ldr r0, [r5]
	adds r0, r3
	mov r1, r12
	strb r1, [r0, 0x5]
	b _0801F63E
	.pool
_0801F634:
	adds r1, 0x8
	adds r2, 0x8
	adds r4, 0x1
	cmp r4, 0x14
	bls _0801F60E
_0801F63E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801F5EC

	thumb_func_start sub_801F644
sub_801F644: @ 801F644
	lsls r0, 24
	ldr r1, =gUnknown_02022C88
	ldr r1, [r1]
	lsrs r0, 21
	adds r1, r0
	ldrb r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_801F644

	thumb_func_start sub_801F658
sub_801F658: @ 801F658
	push {r4,lr}
	adds r4, r0, 0
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801F6EE
	ldrb r0, [r4]
	cmp r0, 0x6
	bhi _0801F6E4
	lsls r0, 2
	ldr r1, =_0801F67C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F67C:
	.4byte _0801F698
	.4byte _0801F6A2
	.4byte _0801F6A8
	.4byte _0801F6AE
	.4byte _0801F6B4
	.4byte _0801F6BA
	.4byte _0801F6CC
_0801F698:
	bl sub_8020480
	bl sub_8020538
	b _0801F6E8
_0801F6A2:
	bl sub_8020584
	b _0801F6E8
_0801F6A8:
	bl sub_80205B4
	b _0801F6E8
_0801F6AE:
	bl task_tutorial_story_unknown
	b _0801F6E8
_0801F6B4:
	bl sub_8020680
	b _0801F6E8
_0801F6BA:
	bl sub_80206A4
	bl sub_80206D0
	bl sub_8020740
	bl sub_80206E8
	b _0801F6E8
_0801F6CC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F6E8
	bl sub_80208E8
	bl sub_8020A68
	bl sub_8020B20
	b _0801F6E8
_0801F6E4:
	movs r0, 0
	b _0801F6F0
_0801F6E8:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F6EE:
	movs r0, 0x1
_0801F6F0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F658

	thumb_func_start sub_801F6F8
sub_801F6F8: @ 801F6F8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F708
	cmp r0, 0x1
	beq _0801F716
	b _0801F720
_0801F708:
	bl sub_80203B0
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F720
_0801F716:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F728
_0801F720:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F728:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F6F8

	thumb_func_start sub_801F730
sub_801F730: @ 801F730
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F740
	cmp r0, 0x1
	beq _0801F74E
	b _0801F758
_0801F740:
	bl sub_802040C
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F758
_0801F74E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F760
_0801F758:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F760:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F730

	thumb_func_start sub_801F768
sub_801F768: @ 801F768
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x1
	beq _0801F79E
	cmp r0, 0x1
	bgt _0801F77C
	cmp r0, 0
	beq _0801F782
	b _0801F7C4
_0801F77C:
	cmp r0, 0x2
	beq _0801F7AA
	b _0801F7C4
_0801F782:
	movs r0, 0x1
	bl sub_802091C
	bl sub_8020320
	cmp r0, 0
	bne _0801F7CA
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F7C4
_0801F79E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _0801F7C4
	b _0801F7CA
_0801F7AA:
	bl sub_8020368
	cmp r0, 0
	bne _0801F7CA
	bl sub_802093C
	movs r0, 0
	bl sub_802091C
	bl sub_8020B80
	movs r0, 0
	b _0801F7CC
_0801F7C4:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F7CA:
	movs r0, 0x1
_0801F7CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F768

	thumb_func_start sub_801F7D4
sub_801F7D4: @ 801F7D4
	push {lr}
	bl sub_802093C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_801F7D4

	thumb_func_start sub_801F7E0
sub_801F7E0: @ 801F7E0
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F7F0
	cmp r0, 0x1
	beq _0801F814
	b _0801F81E
_0801F7F0:
	movs r0, 0
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xB
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F81E
	.pool
_0801F814:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F826
_0801F81E:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F826:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F7E0

	thumb_func_start sub_801F82C
sub_801F82C: @ 801F82C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F83C
	cmp r0, 0x1
	beq _0801F84C
	b _0801F862
_0801F83C:
	bl sub_8020094
	bl sub_801FEBC
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	b _0801F862
_0801F84C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F868
	bl sub_80200C8
	bl sub_801FEE4
	movs r0, 0
	b _0801F86A
_0801F862:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F868:
	movs r0, 0x1
_0801F86A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F82C

	thumb_func_start sub_801F870
sub_801F870: @ 801F870
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F882
	cmp r0, 0x1
	beq _0801F8BA
	b _0801F8CC
_0801F882:
	add r1, sp, 0x8
	add r0, sp, 0x4
	bl sub_801F0EC
	ldr r0, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x8]
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0
	bl sub_80200EC
	bl sub_801F0D0
	adds r1, r0, 0
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F8CC
_0801F8BA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F8D2
	bl sub_8020B80
	movs r0, 0
	b _0801F8D4
_0801F8CC:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F8D2:
	movs r0, 0x1
_0801F8D4:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F870

	thumb_func_start sub_801F8DC
sub_801F8DC: @ 801F8DC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801F938
	cmp r0, 0x1
	bgt _0801F8F2
	cmp r0, 0
	beq _0801F8FC
	b _0801F972
_0801F8F2:
	cmp r0, 0x2
	beq _0801F95C
	cmp r0, 0x3
	beq _0801F96E
	b _0801F972
_0801F8FC:
	bl sub_801F144
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_801F114
	adds r5, r0, 0
	bl StringLength_Multibyte
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x66
	bl sub_80200EC
	movs r0, 0x5
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0x4
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F972
_0801F938:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F978
	movs r0, 0x1
	movs r1, 0x10
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F972
	.pool
_0801F95C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F978
	movs r0, 0x1
	bl sub_80209AC
	b _0801F972
_0801F96E:
	movs r0, 0
	b _0801F97A
_0801F972:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801F978:
	movs r0, 0x1
_0801F97A:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801F8DC

	thumb_func_start sub_801F984
sub_801F984: @ 801F984
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801F9E0
	cmp r0, 0x1
	bgt _0801F99A
	cmp r0, 0
	beq _0801F9A4
	b _0801FA1A
_0801F99A:
	cmp r0, 0x2
	beq _0801FA00
	cmp r0, 0x3
	beq _0801FA16
	b _0801FA1A
_0801F9A4:
	bl sub_801F144
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_801F114
	adds r5, r0, 0
	bl StringLength_Multibyte
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl sub_80200EC
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801FA1A
_0801F9E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA20
	bl sub_8020094
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801FA1A
	.pool
_0801FA00:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA20
	movs r0, 0
	bl sub_80209AC
	bl sub_80200C8
	b _0801FA1A
_0801FA16:
	movs r0, 0
	b _0801FA22
_0801FA1A:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FA20:
	movs r0, 0x1
_0801FA22:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801F984

	thumb_func_start sub_801FA2C
sub_801FA2C: @ 801FA2C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FA3C
	cmp r0, 0x1
	beq _0801FA50
	b _0801FA5E
_0801FA3C:
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FA5E
_0801FA50:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA5E
	movs r0, 0
	b _0801FA60
_0801FA5E:
	movs r0, 0x1
_0801FA60:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FA2C

	thumb_func_start sub_801FA68
sub_801FA68: @ 801FA68
	push {r4-r6,lr}
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x4
	bhi _0801FB3A
	lsls r0, 2
	ldr r1, =_0801FA80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801FA80:
	.4byte _0801FA94
	.4byte _0801FAC0
	.4byte _0801FAF0
	.4byte _0801FB14
	.4byte _0801FADE
_0801FA94:
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrh r5, [r0, 0x1A]
	bl sub_801F180
	adds r4, r0, 0
	bl sub_801F18C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8020420
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801FB34
	.pool
_0801FAC0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0801FB3A
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldrh r0, [r1, 0x1A]
	cmp r0, 0x8
	bhi _0801FAE8
	adds r0, 0x1
	strh r0, [r1, 0x1A]
	movs r0, 0x4
	strb r0, [r6]
_0801FADE:
	movs r0, 0
	b _0801FB3C
	.pool
_0801FAE8:
	strh r2, [r1, 0x1C]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FAF0:
	movs r0, 0
	movs r1, 0
	movs r2, 0x5
	movs r3, 0x11
	bl ScrollWindow
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FB14:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FB3A
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrh r0, [r0, 0x1C]
	cmp r0, 0x2
	bhi _0801FB34
	ldrb r0, [r6]
	subs r0, 0x1
	b _0801FB38
	.pool
_0801FB34:
	ldrb r0, [r6]
	adds r0, 0x1
_0801FB38:
	strb r0, [r6]
_0801FB3A:
	movs r0, 0x1
_0801FB3C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801FA68

	thumb_func_start sub_801FB44
sub_801FB44: @ 801FB44
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FB54
	cmp r0, 0x1
	beq _0801FB60
	b _0801FB66
_0801FB54:
	bl sub_80209E0
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FB66
_0801FB60:
	bl sub_8020A1C
	b _0801FB68
_0801FB66:
	movs r0, 0x1
_0801FB68:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FB44

	thumb_func_start sub_801FB70
sub_801FB70: @ 801FB70
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FB80
	cmp r0, 0x1
	beq _0801FBA0
	b _0801FBAA
_0801FB80:
	movs r0, 0x3
	movs r1, 0x10
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FBAA
	.pool
_0801FBA0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FBAC
_0801FBAA:
	movs r0, 0x1
_0801FBAC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FB70

	thumb_func_start sub_801FBB4
sub_801FBB4: @ 801FBB4
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FBC4
	cmp r0, 0x1
	beq _0801FBE4
	b _0801FBEE
_0801FBC4:
	movs r0, 0x4
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FBEE
	.pool
_0801FBE4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FBF0
_0801FBEE:
	movs r0, 0x1
_0801FBF0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FBB4

	thumb_func_start sub_801FBF8
sub_801FBF8: @ 801FBF8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FC08
	cmp r0, 0x1
	beq _0801FC38
	b _0801FC42
_0801FC08:
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_801F1D0
	adds r1, r0, 0
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x5
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FC42
	.pool
_0801FC38:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FC44
_0801FC42:
	movs r0, 0x1
_0801FC44:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FBF8

	thumb_func_start sub_801FC4C
sub_801FC4C: @ 801FC4C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FC5C
	cmp r0, 0x1
	beq _0801FC88
	b _0801FC92
_0801FC5C:
	movs r0, 0x6
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FC92
	.pool
_0801FC88:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FC94
_0801FC92:
	movs r0, 0x1
_0801FC94:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FC4C

	thumb_func_start sub_801FC9C
sub_801FC9C: @ 801FC9C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FCAC
	cmp r0, 0x1
	beq _0801FCD8
	b _0801FCE2
_0801FCAC:
	movs r0, 0x7
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FCE2
	.pool
_0801FCD8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FCE4
_0801FCE2:
	movs r0, 0x1
_0801FCE4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FC9C

	thumb_func_start sub_801FCEC
sub_801FCEC: @ 801FCEC
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FCFC
	cmp r0, 0x1
	beq _0801FD1C
	b _0801FD26
_0801FCFC:
	movs r0, 0x8
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FD26
	.pool
_0801FD1C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FD28
_0801FD26:
	movs r0, 0x1
_0801FD28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FCEC

	thumb_func_start sub_801FD30
sub_801FD30: @ 801FD30
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FD40
	cmp r0, 0x1
	beq _0801FD74
	b _0801FD7E
_0801FD40:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x9
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FD7E
	.pool
_0801FD74:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FD80
_0801FD7E:
	movs r0, 0x1
_0801FD80:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FD30

	thumb_func_start sub_801FD88
sub_801FD88: @ 801FD88
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FD98
	cmp r0, 0x1
	beq _0801FDC4
	b _0801FDCE
_0801FD98:
	movs r0, 0xA
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FDCE
	.pool
_0801FDC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FDD0
_0801FDCE:
	movs r0, 0x1
_0801FDD0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FD88

	thumb_func_start sub_801FDD8
sub_801FDD8: @ 801FDD8
	movs r0, 0
	bx lr
	thumb_func_end sub_801FDD8

	thumb_func_start sub_801FDDC
sub_801FDDC: @ 801FDDC
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsls r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r4, =0xffffff00
	ldr r2, [sp, 0xC]
	ands r2, r4
	lsrs r0, 16
	ldr r3, =0xffff00ff
	ands r2, r3
	orrs r2, r0
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r2, r0
	orrs r2, r1
	ldr r0, =0x00ffffff
	ands r2, r0
	movs r0, 0xC0
	lsls r0, 19
	orrs r2, r0
	str r2, [sp, 0xC]
	ldr r0, [sp, 0x10]
	ands r0, r4
	movs r1, 0x4
	orrs r0, r1
	ands r0, r3
	movs r1, 0xE0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xA4
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x10]
	add r0, sp, 0xC
	bl AddWindow
	adds r1, r0, 0
	ldr r5, =gUnknown_02022C88
	ldr r0, [r5]
	movs r6, 0
	strh r1, [r0, 0x18]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _0801FE94
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	ldr r2, =gText_Yes
	movs r1, 0x1
	str r1, [sp]
	movs r4, 0xFF
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	movs r1, 0x2
	adds r2, r7, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
_0801FE94:
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FDDC

	thumb_func_start sub_801FEBC
sub_801FEBC: @ 801FEBC
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x18]
	cmp r0, 0xFF
	beq _0801FEDA
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl ClearStdWindowAndFrameToTransparent
	ldr r0, [r4]
	ldrb r0, [r0, 0x18]
	bl ClearWindowTilemap
_0801FEDA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FEBC

	thumb_func_start sub_801FEE4
sub_801FEE4: @ 801FEE4
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x18]
	cmp r0, 0xFF
	beq _0801FEFE
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x18]
_0801FEFE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FEE4

	thumb_func_start sub_801FF08
sub_801FF08: @ 801FF08
	push {lr}
	bl Menu_ProcessInput
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_801FF08

	thumb_func_start sub_801FF18
sub_801FF18: @ 801FF18
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	adds r7, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r1, =0xffffff00
	ldr r3, [sp, 0x14]
	ands r3, r1
	ldr r2, =0xffff00ff
	ands r3, r2
	movs r0, 0x80
	lsls r0, 4
	orrs r3, r0
	ldr r0, =0xff00ffff
	ands r3, r0
	movs r0, 0x80
	lsls r0, 13
	orrs r3, r0
	ldr r5, =0x00ffffff
	ands r3, r5
	movs r0, 0xA8
	lsls r0, 21
	orrs r3, r0
	str r3, [sp, 0x14]
	ldr r0, [sp, 0x18]
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	ands r0, r2
	movs r1, 0xE0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xD4
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x18]
	ldr r1, =gUnknown_082F2D40
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0801FF98
	lsls r0, r3, 16
	movs r1, 0xF9
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	ands r2, r3
	orrs r2, r0
	lsrs r1, r2, 24
	adds r1, 0x7
	lsls r1, 24
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
_0801FF98:
	add r0, sp, 0x14
	bl AddWindow
	ldr r5, =gUnknown_02022C88
	ldr r1, [r5]
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x1E]
	mov r8, r0
	cmp r0, 0xFF
	beq _08020082
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0801FFE0
	adds r0, r1, 0
	adds r0, 0x22
	ldr r1, [r4]
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r5]
	adds r6, r0, 0
	adds r6, 0x22
	b _0801FFE2
	.pool
_0801FFE0:
	ldr r6, [r4]
_0801FFE2:
	mov r0, r9
	lsls r1, r0, 8
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
	mov r1, r8
	lsls r0, r1, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	ldr r1, =gUnknown_082F2D40
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0x1
	bne _08020050
	adds r0, r5, 0
	movs r1, 0xA
	movs r2, 0x2
	bl sub_80989E0
	ldrb r3, [r4, 0x5]
	adds r3, 0x8
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x6]
	adds r0, 0x8
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x7]
	str r0, [sp, 0xC]
	ldrb r0, [r4, 0x8]
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized5
	b _0802007A
	.pool
_08020050:
	adds r0, r5, 0
	movs r1, 0xA
	movs r2, 0x2
	bl sub_8098858
	ldrb r3, [r4, 0x5]
	ldrb r0, [r4, 0x6]
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x7]
	str r0, [sp, 0xC]
	ldrb r0, [r4, 0x8]
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized5
_0802007A:
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	mov r1, r8
	strh r1, [r0, 0x1E]
_08020082:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FF18

	thumb_func_start sub_8020094
sub_8020094: @ 8020094
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x1E]
	cmp r0, 0xFF
	beq _080200B2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl ClearStdWindowAndFrameToTransparent
	ldr r0, [r4]
	ldrb r0, [r0, 0x1E]
	bl ClearWindowTilemap
_080200B2:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020094

	thumb_func_start sub_80200C8
sub_80200C8: @ 80200C8
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x1E]
	cmp r0, 0xFF
	beq _080200E2
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x1E]
_080200E2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80200C8

	thumb_func_start sub_80200EC
sub_80200EC: @ 80200EC
	push {lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 19
	lsrs r3, 16
	lsls r1, 19
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	movs r0, 0x1
	adds r1, r2, 0
	adds r2, r3, 0
	movs r3, 0x1
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80200EC

	thumb_func_start sub_8020118
sub_8020118: @ 8020118
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	mov r10, r1
	ldr r1, [sp, 0x54]
	lsls r0, 16
	lsrs r5, r0, 16
	mov r9, r5
	lsls r2, 24
	lsrs r4, r2, 24
	mov r8, r4
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0
	beq _08020154
	bl sub_801F198
	adds r1, r0, 0
	subs r1, r5
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_80200EC
_08020154:
	add r0, sp, 0xC
	mov r1, r8
	strb r1, [r0]
	strb r7, [r0, 0x1]
	strb r6, [r0, 0x2]
	add r4, sp, 0x10
	movs r0, 0xFC
	strb r0, [r4]
	movs r0, 0x14
	strb r0, [r4, 0x1]
	movs r0, 0x8
	strb r0, [r4, 0x2]
	mov r0, sp
	adds r0, 0x13
	mov r1, r10
	bl StringCopy
	mov r0, r9
	lsls r2, r0, 27
	lsrs r2, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8020118

	thumb_func_start sub_80201A4
sub_80201A4: @ 80201A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	movs r0, 0x2
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	bl sub_801F0B0
	lsls r0, 24
	lsrs r2, r0, 24
	add r1, sp, 0xC
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xE
	strb r0, [r1, 0x1]
	movs r0, 0xD
	strb r0, [r1, 0x2]
	cmp r2, 0x3
	beq _08020240
	add r1, sp, 0x10
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x14
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	cmp r2, 0x2
	bne _080201EC
	movs r1, 0x6
	str r1, [sp, 0x40]
_080201EC:
	movs r7, 0
	movs r6, 0
	lsls r0, r2, 2
	ldr r1, =gUnknown_082F2BA8
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldr r0, [sp, 0x40]
	lsls r5, r0, 24
_080201FE:
	ldr r1, [r4]
	cmp r1, 0
	bne _08020206
	b _0802030C
_08020206:
	mov r0, sp
	adds r0, 0x13
	bl StringCopy
	lsls r3, r6, 24
	lsrs r3, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x44]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	lsrs r2, r5, 24
	bl AddTextPrinterParameterized3
	adds r4, 0x4
	adds r7, 0x1
	adds r0, r6, 0
	adds r0, 0xC
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r7, 0x9
	ble _080201FE
	b _0802030C
	.pool
_08020240:
	movs r1, 0x4
	str r1, [sp, 0x40]
	movs r7, 0
	movs r6, 0
_08020248:
	adds r0, r7, 0
	bl sub_801EE6C
	adds r5, r0, 0
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	cmp r0, 0x28
	bgt _08020286
	lsls r3, r6, 24
	lsrs r3, 24
	add r4, sp, 0xC
	str r4, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r4, 0x80
	lsls r4, 19
	lsrs r2, r4, 24
	bl AddTextPrinterParameterized3
	adds r0, r7, 0x1
	str r0, [sp, 0x48]
	adds r6, 0xC
	mov r10, r6
	b _08020300
_08020286:
	adds r0, r5, 0
	bl StringLength_Multibyte
	adds r4, r0, 0
	mov r1, sp
	adds r1, 0x10
	str r1, [sp, 0x44]
	ldr r0, [sp, 0x40]
	lsls r0, 24
	mov r8, r0
	lsls r1, r6, 24
	mov r9, r1
	adds r0, r7, 0x1
	str r0, [sp, 0x48]
	adds r6, 0xC
	mov r10, r6
	ldr r7, [sp, 0x40]
	adds r7, 0x23
	ldr r6, [sp, 0x44]
_080202AC:
	subs r4, 0x1
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl StringCopyN_Multibyte
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	cmp r0, 0x23
	bgt _080202AC
	mov r1, r8
	lsrs r2, r1, 24
	mov r0, r9
	lsrs r4, r0, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	str r1, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	adds r2, r7, 0
	add r0, sp, 0xC
	str r0, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	ldr r0, =gText_Ellipsis
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
_08020300:
	ldr r7, [sp, 0x48]
	mov r4, r10
	lsls r0, r4, 16
	lsrs r6, r0, 16
	cmp r7, 0x9
	ble _08020248
_0802030C:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80201A4

	thumb_func_start sub_8020320
sub_8020320: @ 8020320
	push {r4,lr}
	ldr r1, =gUnknown_02022C88
	ldr r2, [r1]
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0x37
	bgt _08020354
	adds r0, r3, 0
	adds r0, 0xC
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x37
	ble _08020348
	movs r0, 0x38
	strh r0, [r2, 0x20]
	b _08020354
	.pool
_08020348:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	bl sub_80207C0
	movs r0, 0x1
	b _08020360
_08020354:
	ldr r0, [r1]
	movs r4, 0x20
	ldrsh r0, [r0, r4]
	bl sub_8020818
	movs r0, 0
_08020360:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020320

	thumb_func_start sub_8020368
sub_8020368: @ 8020368
	push {r4,lr}
	ldr r1, =gUnknown_02022C88
	ldr r2, [r1]
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0
	ble _0802039C
	adds r0, r3, 0
	subs r0, 0xC
	strh r0, [r2, 0x20]
	lsls r0, 16
	cmp r0, 0
	bgt _08020390
	movs r0, 0
	strh r0, [r2, 0x20]
	b _0802039C
	.pool
_08020390:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	bl sub_80207C0
	movs r0, 0x1
	b _080203A8
_0802039C:
	ldr r0, [r1]
	movs r4, 0x20
	ldrsh r0, [r0, r4]
	bl sub_8020818
	movs r0, 0
_080203A8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020368

	thumb_func_start sub_80203B0
sub_80203B0: @ 80203B0
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	movs r5, 0xE
	str r5, [sp]
	movs r4, 0x5
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_082F2DC8
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0x8
	movs r3, 0x1
	bl PrintTextArray
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	str r5, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x1
	bl sub_81983AC
	movs r0, 0x3
	bl PutWindowTilemap
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80203B0

	thumb_func_start sub_802040C
sub_802040C: @ 802040C
	push {lr}
	movs r0, 0x3
	movs r1, 0
	bl ClearStdWindowAndFrameToTransparent
	movs r0, 0x3
	bl ClearWindowTilemap
	pop {r0}
	bx r0
	thumb_func_end sub_802040C

	thumb_func_start sub_8020420
sub_8020420: @ 8020420
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 24
	add r3, sp, 0xC
	movs r1, 0x1
	strb r1, [r3]
	lsrs r2, 23
	adds r1, r2, 0x2
	strb r1, [r3, 0x1]
	adds r1, r3, 0
	adds r2, 0x3
	strb r2, [r1, 0x2]
	lsls r4, r0, 4
	subs r4, r0
	lsls r3, r4, 16
	lsrs r3, 16
	movs r0, 0xA8
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	add r0, sp, 0xC
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8020420

	thumb_func_start sub_8020480
sub_8020480: @ 8020480
	push {lr}
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
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0xE0
	lsls r1, 8
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x000040f0
	movs r0, 0x40
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0x90
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3D
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020480

	thumb_func_start sub_8020538
sub_8020538: @ 8020538
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r1, [r4]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000928
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001128
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001928
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020538

	thumb_func_start sub_8020584
sub_8020584: @ 8020584
	push {lr}
	sub sp, 0x8
	movs r1, 0xC0
	lsls r1, 19
	movs r0, 0
	movs r2, 0x20
	movs r3, 0x1
	bl RequestDma3Fill
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8020584

	thumb_func_start sub_80205B4
sub_80205B4: @ 80205B4
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_08DD4BD0
	movs r1, 0x70
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08DD4BB0
	movs r1, 0xC0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_08DD4BF0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DD4C4C
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80205B4

	thumb_func_start task_tutorial_story_unknown
task_tutorial_story_unknown: @ 8020604
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gLinkMiscMenu_Pal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gLinkMiscMenu_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r5, r0, 0
	cmp r5, 0
	beq _0802064E
	movs r1, 0x88
	lsls r1, 2
	adds r0, r5, r1
	ldr r4, =gUnknown_02022C88
	ldr r1, [r4]
	ldr r2, =0x00002128
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
	movs r1, 0x84
	lsls r1, 3
	adds r0, r5, r1
	ldr r1, [r4]
	ldr r2, =0x00002148
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
_0802064E:
	ldr r1, =gLinkMiscMenu_Tilemap
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_tutorial_story_unknown

	thumb_func_start sub_8020680
sub_8020680: @ 8020680
	push {lr}
	ldr r0, =gUnknown_082F2C20
	movs r1, 0x80
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =0x06004020
	movs r0, 0
	movs r2, 0x20
	movs r3, 0x1
	bl RequestDma3Fill
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020680

	thumb_func_start sub_80206A4
sub_80206A4: @ 80206A4
	push {lr}
	ldr r0, =gUnknown_082F2C40
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80206A4

	thumb_func_start sub_80206D0
sub_80206D0: @ 80206D0
	push {lr}
	movs r0, 0x2
	bl PutWindowTilemap
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_80206D0

	thumb_func_start sub_80206E8
sub_80206E8: @ 80206E8
	push {r4,lr}
	sub sp, 0xC
	add r1, sp, 0x8
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	movs r4, 0
_080206F8:
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldr r0, =0x00002128
	adds r1, r0
	lsls r2, r4, 19
	lsrs r2, 16
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r3, 0
	bl BlitBitmapToWindow
	adds r4, 0x1
	cmp r4, 0xE
	ble _080206F8
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80206E8

	thumb_func_start sub_8020740
sub_8020740: @ 8020740
	push {lr}
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx
	movs r0, 0x3
	movs r1, 0xA
	movs r2, 0x20
	bl LoadUserWindowBorderGfx_
	ldr r0, =gUnknown_0860F074
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020740

	thumb_func_start sub_8020770
sub_8020770: @ 8020770
	push {lr}
	sub sp, 0x10
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	ldr r0, =0x04000014
	str r0, [sp]
	mov r2, sp
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x8]
	mov r0, sp
	strb r1, [r0, 0x9]
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	strh r1, [r0, 0x20]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	ldr r1, =gScanlineEffectRegBuffers
	ldr r2, =0x010003c0
	bl CpuFastSet
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020770

	thumb_func_start sub_80207C0
sub_80207C0: @ 80207C0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	ldr r5, =gScanlineEffect
	ldrb r0, [r5, 0x14]
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 7
	ldr r4, =gScanlineEffectRegBuffers
	adds r1, r4
	ldr r2, =0x01000090
	mov r0, sp
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	movs r1, 0
	strh r1, [r0]
	ldrb r2, [r5, 0x14]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 7
	movs r2, 0x90
	lsls r2, 1
	adds r4, r2
	adds r1, r4
	ldr r2, =0x01000010
	bl CpuSet
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80207C0

	thumb_func_start sub_8020818
sub_8020818: @ 8020818
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, sp
	strh r4, [r0]
	ldr r5, =gScanlineEffectRegBuffers
	ldr r0, =0x01000090
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	mov r2, r9
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	movs r6, 0
	strh r6, [r0]
	movs r2, 0x90
	lsls r2, 1
	adds r1, r5, r2
	ldr r2, =0x01000010
	mov r8, r2
	bl CpuSet
	add r0, sp, 0x4
	strh r4, [r0]
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r5, r2
	mov r2, r9
	bl CpuSet
	mov r0, sp
	adds r0, 0x6
	strh r6, [r0]
	movs r1, 0x8A
	lsls r1, 4
	adds r5, r1
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020818

	thumb_func_start sub_8020890
sub_8020890: @ 8020890
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_082F3134
_08020896:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	bls _08020896
	ldr r0, =gUnknown_082F315C
	bl LoadSpritePalette
	ldr r4, =gUnknown_02022C8C
	movs r0, 0x18
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _080208C8
	movs r0, 0x1
	b _080208CA
	.pool
_080208C8:
	movs r0, 0
_080208CA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8020890

	thumb_func_start sub_80208D0
sub_80208D0: @ 80208D0
	push {lr}
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	cmp r0, 0
	beq _080208DE
	bl Free
_080208DE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80208D0

	thumb_func_start sub_80208E8
sub_80208E8: @ 80208E8
	push {lr}
	ldr r0, =gUnknown_082F319C
	movs r1, 0xA
	movs r2, 0x18
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C8C
	ldr r2, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80208E8

	thumb_func_start sub_802091C
sub_802091C: @ 802091C
	ldr r1, =gUnknown_02022C8C
	ldr r1, [r1]
	ldr r2, [r1]
	adds r2, 0x3E
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_802091C

	thumb_func_start sub_802093C
sub_802093C: @ 802093C
	push {r4,r5,lr}
	sub sp, 0x4
	bl sub_801F0B0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r5, sp
	adds r5, 0x1
	mov r0, sp
	adds r1, r5, 0
	bl sub_801F0BC
	cmp r4, 0x3
	beq _0802097C
	ldr r4, =gUnknown_02022C8C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	ldr r1, [r4]
	ldr r2, [r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0xA
	strh r0, [r2, 0x20]
	ldr r2, [r1]
	b _08020992
	.pool
_0802097C:
	ldr r4, =gUnknown_02022C8C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	ldr r2, [r4]
	ldr r1, [r2]
	movs r0, 0x18
	strh r0, [r1, 0x20]
	ldr r2, [r2]
_08020992:
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x18
	strh r0, [r2, 0x22]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802093C

	thumb_func_start sub_80209AC
sub_80209AC: @ 80209AC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 2
	ldr r0, =gUnknown_082F2DF0+2
	adds r4, r0
	movs r0, 0
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	ldr r0, =0x01010000
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x4
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209E0
sub_80209E0: @ 80209E0
	push {lr}
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08020A00
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _08020A0C
	.pool
_08020A00:
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
_08020A0C:
	ldr r0, =gUnknown_02022C8C
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x14]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80209E0

	thumb_func_start sub_8020A1C
sub_8020A1C: @ 8020A1C
	push {r4,lr}
	ldr r4, =gUnknown_02022C8C
	ldr r1, [r4]
	ldrh r0, [r1, 0x14]
	cmp r0, 0x3
	bls _08020A30
_08020A28:
	movs r0, 0
	b _08020A62
	.pool
_08020A30:
	adds r0, 0x1
	strh r0, [r1, 0x14]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bls _08020A60
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08020A54
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	b _08020A28
_08020A54:
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	b _08020A28
_08020A60:
	movs r0, 0x1
_08020A62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020A1C

	thumb_func_start sub_8020A68
sub_8020A68: @ 8020A68
	push {r4,r5,lr}
	ldr r0, =gUnknown_082F31BC
	movs r1, 0x4C
	movs r2, 0x98
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_02022C8C
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2, 0x8]
	ldr r0, =gUnknown_082F31D4
	movs r1, 0x40
	movs r2, 0x98
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r2, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020A68

	thumb_func_start sub_8020ABC
sub_8020ABC: @ 8020ABC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_801F198
	adds r3, r0, 0
	cmp r3, 0xF
	bne _08020AD8
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08020AEC
_08020AD8:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	lsls r0, r3, 3
	adds r0, 0x4C
	strh r0, [r4, 0x20]
_08020AEC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020ABC

	thumb_func_start sub_8020AF4
sub_8020AF4: @ 8020AF4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08020B1A
	strh r2, [r1, 0x2E]
	ldrh r0, [r1, 0x24]
	adds r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08020B1A
	strh r2, [r1, 0x24]
_08020B1A:
	pop {r0}
	bx r0
	thumb_func_end sub_8020AF4

	thumb_func_start sub_8020B20
sub_8020B20: @ 8020B20
	push {r4,r5,lr}
	ldr r0, =gUnknown_082F322C
	movs r1, 0x8
	movs r2, 0x98
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_02022C8C
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2, 0xC]
	ldr r0, =gUnknown_082F3244
	movs r1, 0x20
	movs r2, 0x98
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r2, 0x10]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020B20

	thumb_func_start sub_8020B80
sub_8020B80: @ 8020B80
	push {r4,lr}
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _08020BB8
	bl sub_801F0DC
	cmp r0, 0
	beq _08020BC2
	ldr r3, =gUnknown_02022C8C
	ldr r0, [r3]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x10]
	movs r1, 0x3
	bl StartSpriteAnim
	b _08020BF6
	.pool
_08020BB8:
	bl sub_801F1A4
	adds r4, r0, 0
	cmp r4, 0x3
	bne _08020BD8
_08020BC2:
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	b _08020BF6
	.pool
_08020BD8:
	ldr r3, =gUnknown_02022C8C
	ldr r0, [r3]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x10]
	lsls r1, r4, 24
	lsrs r1, 24
	bl StartSpriteAnim
_08020BF6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020B80

	.align 2, 0 @ don't pad with nop
