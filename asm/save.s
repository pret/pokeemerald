	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start calls_flash_erase_block
calls_flash_erase_block: @ 8152650
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_03007860
_08152656:
	ldr r1, [r5]
	adds r0, r4, 0
	bl _call_via_r1
	adds r0, r4, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r5]
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xF
	bls _08152656
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end calls_flash_erase_block

	thumb_func_start sub_8152680
sub_8152680: @ 8152680
	ldr r0, =gUnknown_03006200
	movs r1, 0
	str r1, [r0]
	ldr r0, =gUnknown_030061F0
	strh r1, [r0]
	ldr r0, =gUnknown_030061FC
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8152680

	thumb_func_start sub_815269C
sub_815269C: @ 815269C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	movs r4, 0
	cmp r0, 0x1
	beq _081526D0
	cmp r0, 0x1
	bgt _081526B6
	cmp r0, 0
	beq _081526BC
	b _081526F4
_081526B6:
	cmp r0, 0x2
	beq _081526E4
	b _081526F4
_081526BC:
	ldr r2, =gUnknown_030061FC
	movs r1, 0x1
	lsls r1, r3
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _081526F4
	.pool
_081526D0:
	ldr r2, =gUnknown_030061FC
	adds r1, r0, 0
	lsls r1, r3
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	b _081526F4
	.pool
_081526E4:
	ldr r0, =gUnknown_030061FC
	movs r1, 0x1
	lsls r1, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _081526F4
	movs r4, 0x1
_081526F4:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_815269C

	thumb_func_start save_write_to_flash
save_write_to_flash: @ 8152700
	push {r4-r7,lr}
	adds r7, r1, 0
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gUnknown_03006204
	ldr r0, =gUnknown_0203ABBC
	str r0, [r1]
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _08152730
	adds r0, r2, 0
	adds r1, r7, 0
	bl sub_81527A0
	lsls r0, 24
	lsrs r5, r0, 24
	b _08152782
	.pool
_08152730:
	ldr r1, =gUnknown_030061F8
	ldr r5, =gUnknown_030061F0
	ldrh r0, [r5]
	strh r0, [r1]
	ldr r1, =gUnknown_030061F4
	ldr r6, =gUnknown_03006200
	ldr r4, [r6]
	str r4, [r1]
	adds r0, 0x1
	strh r0, [r5]
	ldrh r0, [r5]
	movs r1, 0xE
	bl __umodsi3
	strh r0, [r5]
	adds r4, 0x1
	str r4, [r6]
	movs r5, 0x1
	movs r4, 0
_08152756:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_81527A0
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xD
	bls _08152756
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08152782
	movs r5, 0xFF
	ldr r1, =gUnknown_030061F0
	ldr r0, =gUnknown_030061F8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03006200
	ldr r0, =gUnknown_030061F4
	ldr r0, [r0]
	str r0, [r1]
_08152782:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end save_write_to_flash

	thumb_func_start sub_81527A0
sub_81527A0: @ 81527A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_030061F0
	ldrh r0, [r0]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r5, 0
	movs r1, 0xE
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r2, =gUnknown_03006200
	ldr r1, [r2]
	movs r0, 0x1
	ands r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r6, 3
	adds r0, r4
	ldr r1, [r0]
	mov r10, r1
	ldrh r4, [r0, 0x4]
	movs r3, 0
	mov r9, r2
	ldr r2, =gUnknown_03006204
	mov r12, r2
	mov r8, r12
	movs r2, 0
	ldr r1, =0x00000fff
_081527F2:
	mov r7, r8
	ldr r0, [r7]
	adds r0, r3
	strb r2, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	bls _081527F2
	mov r0, r12
	ldr r1, [r0]
	ldr r2, =0x00000ff4
	adds r0, r1, r2
	strh r6, [r0]
	ldr r3, =0x00000ff8
	adds r2, r1, r3
	ldr r0, =0x08012025
	str r0, [r2]
	ldr r6, =0x00000ffc
	adds r1, r6
	mov r7, r9
	ldr r0, [r7]
	str r0, [r1]
	movs r3, 0
	lsls r5, 24
	cmp r3, r4
	bcs _08152840
	mov r2, r12
_0815282A:
	ldr r1, [r2]
	adds r1, r3
	mov r6, r10
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r4
	bcc _0815282A
_08152840:
	mov r0, r10
	adds r1, r4, 0
	bl sub_8153164
	ldr r1, =gUnknown_03006204
	ldr r1, [r1]
	ldr r7, =0x00000ff6
	adds r2, r1, r7
	strh r0, [r2]
	lsrs r0, r5, 24
	bl sub_8152908
	lsls r0, 24
	lsrs r0, 24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81527A0

	thumb_func_start sub_8152890
sub_8152890: @ 8152890
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gUnknown_0203ABBC
	movs r3, 0
	movs r6, 0
	ldr r1, =0x00000fff
_081528A4:
	adds r0, r4, r3
	strb r6, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	bls _081528A4
	ldr r0, =0x00000ff8
	adds r1, r4, r0
	ldr r0, =0x08012025
	str r0, [r1]
	movs r3, 0
	cmp r3, r2
	bcs _081528D2
_081528C0:
	adds r1, r4, r3
	adds r0, r5, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r2
	bcc _081528C0
_081528D2:
	adds r0, r5, 0
	adds r1, r2, 0
	bl sub_8153164
	ldr r2, =0x00000ff4
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_8152908
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152890

	thumb_func_start sub_8152908
sub_8152908: @ 8152908
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl ProgramFlashSectorsAndVerify
	cmp r0, 0
	bne _08152924
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_815269C
	movs r0, 0x1
	b _0815292E
_08152924:
	movs r0, 0
	adds r1, r4, 0
	bl sub_815269C
	movs r0, 0xFF
_0815292E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8152908

	thumb_func_start sub_8152934
sub_8152934: @ 8152934
	push {r4-r6,lr}
	ldr r1, =gUnknown_03006204
	ldr r0, =gUnknown_0203ABBC
	str r0, [r1]
	ldr r1, =gUnknown_030061F8
	ldr r5, =gUnknown_030061F0
	ldrh r0, [r5]
	strh r0, [r1]
	ldr r1, =gUnknown_030061F4
	ldr r6, =gUnknown_03006200
	ldr r4, [r6]
	str r4, [r1]
	adds r0, 0x1
	strh r0, [r5]
	ldrh r0, [r5]
	movs r1, 0xE
	bl __umodsi3
	strh r0, [r5]
	adds r4, 0x1
	str r4, [r6]
	ldr r1, =gUnknown_03006208
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_030061FC
	movs r0, 0
	str r0, [r1]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152934

	thumb_func_start sub_8152990
sub_8152990: @ 8152990
	ldr r1, =gUnknown_03006204
	ldr r0, =gUnknown_0203ABBC
	str r0, [r1]
	ldr r1, =gUnknown_030061F8
	ldr r0, =gUnknown_030061F0
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030061F4
	ldr r0, =gUnknown_03006200
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, =gUnknown_03006208
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_030061FC
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8152990

	thumb_func_start sub_81529D4
sub_81529D4: @ 81529D4
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_03006208
	ldrh r2, [r4]
	subs r0, 0x1
	cmp r2, r0
	bge _08152A28
	movs r5, 0x1
	adds r0, r2, 0
	bl sub_81527A0
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08152A2A
	movs r5, 0xFF
	ldr r1, =gUnknown_030061F0
	ldr r0, =gUnknown_030061F8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03006200
	ldr r0, =gUnknown_030061F4
	ldr r0, [r0]
	str r0, [r1]
	b _08152A2A
	.pool
_08152A28:
	movs r5, 0xFF
_08152A2A:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81529D4

	thumb_func_start sub_8152A34
sub_8152A34: @ 8152A34
	push {r4,lr}
	lsls r0, 16
	movs r4, 0x1
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r0, 16
	bl calls_flash_erase_block_2
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08152A5E
	movs r4, 0xFF
	ldr r1, =gUnknown_030061F0
	ldr r0, =gUnknown_030061F8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03006200
	ldr r0, =gUnknown_030061F4
	ldr r0, [r0]
	str r0, [r1]
_08152A5E:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152A34

	thumb_func_start calls_flash_erase_block_2
calls_flash_erase_block_2: @ 8152A80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_030061F0
	ldrh r0, [r0]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r5, 0
	movs r1, 0xE
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r2, =gUnknown_03006200
	ldr r1, [r2]
	movs r0, 0x1
	ands r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r6, 3
	adds r0, r4
	ldr r1, [r0]
	mov r10, r1
	ldrh r3, [r0, 0x4]
	movs r4, 0
	mov r9, r2
	ldr r2, =gUnknown_03006204
	mov r12, r2
	mov r8, r12
	movs r2, 0
	ldr r1, =0x00000fff
_08152AD2:
	mov r7, r8
	ldr r0, [r7]
	adds r0, r4
	strb r2, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r1
	bls _08152AD2
	mov r0, r12
	ldr r1, [r0]
	ldr r2, =0x00000ff4
	adds r0, r1, r2
	strh r6, [r0]
	ldr r6, =0x00000ff8
	adds r2, r1, r6
	ldr r0, =0x08012025
	str r0, [r2]
	ldr r7, =0x00000ffc
	adds r1, r7
	mov r2, r9
	ldr r0, [r2]
	str r0, [r1]
	movs r4, 0
	lsls r6, r5, 24
	mov r8, r6
	cmp r4, r3
	bcs _08152B22
	mov r2, r12
_08152B0C:
	ldr r1, [r2]
	adds r1, r4
	mov r7, r10
	adds r0, r7, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r3
	bcc _08152B0C
_08152B22:
	mov r0, r10
	adds r1, r3, 0
	bl sub_8153164
	ldr r1, =gUnknown_03006204
	ldr r1, [r1]
	ldr r2, =0x00000ff6
	adds r1, r2
	strh r0, [r1]
	ldr r0, =gUnknown_03007860
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
	movs r6, 0x1
	movs r4, 0
	ldr r7, =0x00000ff7
	mov r9, r7
	ldr r7, =gUnknown_03007854
	b _08152B82
	.pool
_08152B7C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08152B82:
	cmp r4, r9
	bhi _08152BA0
	ldr r0, =gUnknown_03006204
	ldr r0, [r0]
	adds r0, r4
	ldrb r2, [r0]
	ldr r3, [r7]
	adds r0, r5, 0
	adds r1, r4, 0
	bl _call_via_r3
	lsls r0, 16
	cmp r0, 0
	beq _08152B7C
	movs r6, 0xFF
_08152BA0:
	cmp r6, 0xFF
	bne _08152BB0
	mov r0, r8
	lsrs r1, r0, 24
	b _08152C08
	.pool
_08152BB0:
	movs r6, 0x1
	movs r4, 0
	ldr r1, =gUnknown_03007854
	mov r9, r1
	ldr r7, =0x00000ff9
	b _08152BCA
	.pool
_08152BC4:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08152BCA:
	cmp r4, 0x6
	bhi _08152BEC
	adds r1, r4, r7
	ldr r0, =gUnknown_03006204
	ldr r0, [r0]
	adds r0, r4, r0
	adds r0, r7
	ldrb r2, [r0]
	mov r0, r9
	ldr r3, [r0]
	adds r0, r5, 0
	bl _call_via_r3
	lsls r0, 16
	cmp r0, 0
	beq _08152BC4
	movs r6, 0xFF
_08152BEC:
	cmp r6, 0xFF
	beq _08152C04
	mov r2, r8
	lsrs r1, r2, 24
	movs r0, 0x1
	bl sub_815269C
	movs r0, 0x1
	b _08152C10
	.pool
_08152C04:
	mov r6, r8
	lsrs r1, r6, 24
_08152C08:
	movs r0, 0
	bl sub_815269C
	movs r0, 0xFF
_08152C10:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end calls_flash_erase_block_2

	thumb_func_start sav12_xor_get
sav12_xor_get: @ 8152C20
	push {r4-r6,lr}
	lsls r0, 16
	ldr r6, =gUnknown_030061F0
	lsrs r0, 16
	ldrh r1, [r6]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0xE
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r5, =gUnknown_03006200
	ldr r1, [r5]
	movs r0, 0x1
	ands r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gUnknown_03007854
	ldr r1, =0x00000ff8
	ldr r3, [r0]
	adds r0, r4, 0
	movs r2, 0x25
	bl _call_via_r3
	lsls r0, 16
	cmp r0, 0
	bne _08152C84
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x1
	bl sub_815269C
	movs r0, 0x1
	b _08152C9C
	.pool
_08152C84:
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_815269C
	ldr r0, =gUnknown_030061F8
	ldrh r0, [r0]
	strh r0, [r6]
	ldr r0, =gUnknown_030061F4
	ldr r0, [r0]
	str r0, [r5]
	movs r0, 0xFF
_08152C9C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav12_xor_get

	thumb_func_start sub_8152CAC
sub_8152CAC: @ 8152CAC
	push {r4-r6,lr}
	lsls r0, 16
	ldr r6, =gUnknown_030061F0
	lsrs r0, 16
	ldrh r1, [r6]
	adds r0, r1
	subs r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0xE
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r5, =gUnknown_03006200
	ldr r1, [r5]
	movs r0, 0x1
	ands r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r3, =gUnknown_03007854
	ldr r1, =0x00000ff8
	ldr r0, =gUnknown_03006204
	ldr r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r3, [r3]
	adds r0, r4, 0
	bl _call_via_r3
	lsls r0, 16
	cmp r0, 0
	bne _08152D1C
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x1
	bl sub_815269C
	movs r0, 0x1
	b _08152D34
	.pool
_08152D1C:
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_815269C
	ldr r0, =gUnknown_030061F8
	ldrh r0, [r0]
	strh r0, [r6]
	ldr r0, =gUnknown_030061F4
	ldr r0, [r0]
	str r0, [r5]
	movs r0, 0xFF
_08152D34:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152CAC

	thumb_func_start sub_8152D44
sub_8152D44: @ 8152D44
	push {r4-r6,lr}
	lsls r0, 16
	ldr r6, =gUnknown_030061F0
	lsrs r0, 16
	ldrh r1, [r6]
	adds r0, r1
	subs r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0xE
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r5, =gUnknown_03006200
	ldr r1, [r5]
	movs r0, 0x1
	ands r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gUnknown_03007854
	ldr r1, =0x00000ff8
	ldr r3, [r0]
	adds r0, r4, 0
	movs r2, 0x25
	bl _call_via_r3
	lsls r0, 16
	cmp r0, 0
	bne _08152DA8
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x1
	bl sub_815269C
	movs r0, 0x1
	b _08152DC0
	.pool
_08152DA8:
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_815269C
	ldr r0, =gUnknown_030061F8
	ldrh r0, [r0]
	strh r0, [r6]
	ldr r0, =gUnknown_030061F4
	ldr r0, [r0]
	str r0, [r5]
	movs r0, 0xFF
_08152DC0:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152D44

	thumb_func_start sub_8152DD0
sub_8152DD0: @ 8152DD0
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r1, =gUnknown_03006204
	ldr r0, =gUnknown_0203ABBC
	str r0, [r1]
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _08152DF4
	movs r5, 0xFF
	b _08152E06
	.pool
_08152DF4:
	adds r0, r6, 0
	bl sub_8152EC8
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8152E10
_08152E06:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8152DD0

	thumb_func_start sub_8152E10
sub_8152E10: @ 8152E10
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	ldr r0, =gUnknown_03006200
	ldr r1, [r0]
	movs r0, 0x1
	ands r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 17
	lsrs r7, r0, 16
	movs r5, 0
	ldr r6, =gUnknown_03006204
_08152E2C:
	adds r0, r5, r7
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r6]
	bl sub_815314C
	ldr r0, [r6]
	ldr r1, =0x00000ff4
	adds r0, r1
	ldrh r1, [r0]
	cmp r1, 0
	bne _08152E48
	ldr r0, =gUnknown_030061F0
	strh r5, [r0]
_08152E48:
	ldr r0, [r6]
	lsls r1, 3
	mov r2, r8
	adds r4, r1, r2
	ldrh r1, [r4, 0x4]
	bl sub_8153164
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, [r6]
	ldr r1, =0x00000ff8
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r0, =0x08012025
	adds r5, 0x1
	cmp r1, r0
	bne _08152E98
	ldr r1, =0x00000ff6
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _08152E98
	movs r2, 0
	ldrh r0, [r4, 0x4]
	cmp r2, r0
	bcs _08152E98
	adds r3, r4, 0
	ldr r4, =gUnknown_03006204
_08152E80:
	ldr r1, [r3]
	adds r1, r2
	ldr r0, [r4]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r1, [r3, 0x4]
	cmp r2, r1
	bcc _08152E80
_08152E98:
	lsls r0, r5, 16
	lsrs r5, r0, 16
	cmp r5, 0xD
	bls _08152E2C
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152E10

	thumb_func_start sub_8152EC8
sub_8152EC8: @ 8152EC8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r0
	movs r0, 0
	mov r8, r0
	mov r9, r0
	movs r6, 0
	movs r5, 0
	movs r4, 0
	ldr r7, =gUnknown_03006204
_08152EE4:
	lsls r0, r4, 24
	lsrs r0, 24
	ldr r1, [r7]
	bl sub_815314C
	ldr r2, [r7]
	ldr r1, =0x00000ff8
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r0, =0x08012025
	cmp r1, r0
	bne _08152F34
	movs r5, 0x1
	ldr r3, =0x00000ff4
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, 3
	add r0, r10
	ldrh r1, [r0, 0x4]
	adds r0, r2, 0
	bl sub_8153164
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, [r7]
	ldr r3, =0x00000ff6
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _08152F34
	ldr r2, =0x00000ffc
	adds r0, r1, r2
	ldr r0, [r0]
	mov r8, r0
	subs r3, 0x2
	adds r1, r3
	adds r0, r5, 0
	ldrh r1, [r1]
	lsls r0, r1
	orrs r6, r0
_08152F34:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xD
	bls _08152EE4
	cmp r5, 0
	beq _08152F70
	ldr r0, =0x00003fff
	movs r1, 0xFF
	str r1, [sp]
	cmp r6, r0
	bne _08152F74
	movs r2, 0x1
	str r2, [sp]
	b _08152F74
	.pool
_08152F70:
	movs r3, 0
	str r3, [sp]
_08152F74:
	movs r6, 0
	movs r5, 0
	movs r4, 0
	ldr r7, =gUnknown_03006204
_08152F7C:
	adds r0, r4, 0
	adds r0, 0xE
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r7]
	bl sub_815314C
	ldr r2, [r7]
	ldr r1, =0x00000ff8
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r0, =0x08012025
	cmp r1, r0
	bne _08152FD0
	movs r5, 0x1
	ldr r3, =0x00000ff4
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, 3
	add r0, r10
	ldrh r1, [r0, 0x4]
	adds r0, r2, 0
	bl sub_8153164
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, [r7]
	ldr r3, =0x00000ff6
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _08152FD0
	ldr r2, =0x00000ffc
	adds r0, r1, r2
	ldr r0, [r0]
	mov r9, r0
	subs r3, 0x2
	adds r1, r3
	adds r0, r5, 0
	ldrh r1, [r1]
	lsls r0, r1
	orrs r6, r0
_08152FD0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xD
	bls _08152F7C
	cmp r5, 0
	beq _08153008
	ldr r0, =0x00003fff
	movs r1, 0xFF
	cmp r6, r0
	bne _0815300A
	movs r1, 0x1
	b _0815300A
	.pool
_08153008:
	movs r1, 0
_0815300A:
	ldr r0, [sp]
	cmp r0, 0x1
	bne _0815307C
	cmp r1, 0x1
	bne _0815306C
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _08153022
	mov r1, r9
	cmp r1, 0
	beq _0815302C
_08153022:
	mov r2, r8
	cmp r2, 0
	bne _08153050
	cmp r9, r0
	bne _08153050
_0815302C:
	mov r1, r8
	adds r1, 0x1
	mov r0, r9
	adds r0, 0x1
	cmp r1, r0
	bcs _08153044
	ldr r0, =gUnknown_03006200
	mov r3, r9
	b _08153064
	.pool
_08153044:
	ldr r0, =gUnknown_03006200
	mov r1, r8
	str r1, [r0]
	b _08153094
	.pool
_08153050:
	cmp r8, r9
	bcs _08153060
	ldr r0, =gUnknown_03006200
	mov r2, r9
	str r2, [r0]
	b _08153094
	.pool
_08153060:
	ldr r0, =gUnknown_03006200
	mov r3, r8
_08153064:
	str r3, [r0]
	b _08153094
	.pool
_0815306C:
	ldr r0, =gUnknown_03006200
	mov r2, r8
	str r2, [r0]
	cmp r1, 0xFF
	beq _0815308C
	b _08153094
	.pool
_0815307C:
	cmp r1, 0x1
	bne _08153098
	ldr r0, =gUnknown_03006200
	mov r3, r9
	str r3, [r0]
	ldr r0, [sp]
	cmp r0, 0xFF
	bne _08153094
_0815308C:
	movs r0, 0xFF
	b _081530C4
	.pool
_08153094:
	movs r0, 0x1
	b _081530C4
_08153098:
	ldr r2, [sp]
	cmp r2, 0
	bne _081530B8
	cmp r1, 0
	bne _081530B8
	ldr r0, =gUnknown_03006200
	str r1, [r0]
	ldr r0, =gUnknown_030061F0
	strh r1, [r0]
	movs r0, 0
	b _081530C4
	.pool
_081530B8:
	ldr r0, =gUnknown_03006200
	movs r1, 0
	str r1, [r0]
	ldr r0, =gUnknown_030061F0
	strh r1, [r0]
	movs r0, 0x2
_081530C4:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152EC8

	thumb_func_start sub_81530DC
sub_81530DC: @ 81530DC
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r4, r2, 16
	ldr r5, =gUnknown_0203ABBC
	adds r1, r5, 0
	bl sub_815314C
	ldr r1, =0x00000ff8
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, =0x08012025
	cmp r1, r0
	bne _08153144
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8153164
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =0x00000ff4
	adds r1, r5, r2
	ldrh r1, [r1]
	cmp r1, r0
	bne _08153140
	movs r2, 0
	cmp r2, r4
	bcs _0815312A
_08153118:
	adds r1, r6, r2
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r4
	bcc _08153118
_0815312A:
	movs r0, 0x1
	b _08153146
	.pool
_08153140:
	movs r0, 0x2
	b _08153146
_08153144:
	movs r0, 0
_08153146:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81530DC

	thumb_func_start sub_815314C
sub_815314C: @ 815314C
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0x80
	lsls r3, 5
	movs r1, 0
	bl ReadFlash
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_815314C

	thumb_func_start sub_8153164
sub_8153164: @ 8153164
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	movs r2, 0
	movs r3, 0
	lsrs r1, 18
	cmp r2, r1
	bcs _08153182
_08153174:
	ldm r4!, {r0}
	adds r2, r0
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	bcc _08153174
_08153182:
	lsrs r0, r2, 16
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8153164

	thumb_func_start sub_8153190
sub_8153190: @ 8153190
	push {r4,r5,lr}
	ldr r3, =gUnknown_03006220
	ldr r0, =gUnknown_03005D90
	ldr r2, =gUnknown_085CDC00
	ldrh r1, [r2]
	ldr r0, [r0]
	adds r0, r1
	str r0, [r3]
	ldrh r0, [r2, 0x2]
	strh r0, [r3, 0x4]
	ldr r5, =gUnknown_03005D8C
	adds r3, 0x8
	adds r2, 0x4
	movs r4, 0x3
_081531AC:
	ldrh r0, [r2]
	ldr r1, [r5]
	adds r1, r0
	str r1, [r3]
	ldrh r0, [r2, 0x2]
	strh r0, [r3, 0x4]
	adds r3, 0x8
	adds r2, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _081531AC
	movs r4, 0x5
	ldr r1, =gUnknown_03006220
	ldr r5, =gUnknown_03005D94
	ldr r0, =gUnknown_085CDC00
	adds r3, r1, 0
	adds r3, 0x28
	adds r2, r0, 0
	adds r2, 0x14
_081531D2:
	ldrh r0, [r2]
	ldr r1, [r5]
	adds r1, r0
	str r1, [r3]
	ldrh r0, [r2, 0x2]
	strh r0, [r3, 0x4]
	adds r3, 0x8
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, 0xD
	ble _081531D2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153190

	thumb_func_start calls_flash_erase_block_3
calls_flash_erase_block_3: @ 8153204
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0203CF5C
	ldr r6, [r1]
	movs r0, 0
	str r0, [r1]
	bl sub_8153190
	cmp r4, 0x5
	bhi _081532AC
	lsls r0, r4, 2
	ldr r1, =_0815322C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815322C:
	.4byte _081532AC
	.4byte _081532C4
	.4byte _081532C4
	.4byte _0815325A
	.4byte _081532F8
	.4byte _08153244
_08153244:
	movs r4, 0x1C
	ldr r5, =gUnknown_03007860
_08153248:
	ldr r1, [r5]
	adds r0, r4, 0
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08153248
_0815325A:
	movs r0, 0xA
	bl sub_80847F8
	ldr r1, =0x000003e6
	cmp r0, r1
	bhi _0815326C
	movs r0, 0xA
	bl sav12_xor_increment
_0815326C:
	bl save_serialize_game
	ldr r0, =0x0000ffff
	ldr r1, =gUnknown_03006220
	bl save_write_to_flash
	ldr r4, =0x0201c000
	movs r5, 0xF8
	lsls r5, 4
	movs r0, 0x1C
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8152890
	adds r4, r5
	movs r0, 0x1D
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8152890
	b _0815331A
	.pool
_081532AC:
	bl save_serialize_game
	ldr r0, =0x0000ffff
	ldr r1, =gUnknown_03006220
	bl save_write_to_flash
	b _0815331A
	.pool
_081532C4:
	bl save_serialize_game
	movs r4, 0
_081532CA:
	adds r0, r4, 0
	ldr r1, =gUnknown_03006220
	bl calls_flash_erase_block_2
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081532CA
	movs r4, 0
_081532DE:
	adds r0, r4, 0
	ldr r1, =gUnknown_03006220
	bl sav12_xor_get
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081532DE
	b _0815331A
	.pool
_081532F8:
	movs r4, 0x1C
	ldr r5, =gUnknown_03007860
_081532FC:
	ldr r1, [r5]
	adds r0, r4, 0
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _081532FC
	bl save_serialize_game
	ldr r0, =0x0000ffff
	ldr r1, =gUnknown_03006220
	bl save_write_to_flash
_0815331A:
	ldr r0, =gUnknown_0203CF5C
	str r6, [r0]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end calls_flash_erase_block_3

	thumb_func_start save_game_when_memory_present
save_game_when_memory_present: @ 8153338
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_03005D88
	ldr r4, [r0]
	cmp r4, 0x1
	bne _0815335A
	adds r0, r5, 0
	bl calls_flash_erase_block_3
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08153370
	adds r0, r5, 0
	bl fullscreen_save_activate
_0815335A:
	ldr r1, =gUnknown_03006294
	movs r0, 0xFF
	strh r0, [r1]
	movs r0, 0xFF
	b _08153376
	.pool
_08153370:
	ldr r0, =gUnknown_03006294
	strh r4, [r0]
	movs r0, 0x1
_08153376:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end save_game_when_memory_present

	thumb_func_start sub_8153380
sub_8153380: @ 8153380
	push {lr}
	ldr r0, =gUnknown_03005D88
	ldr r0, [r0]
	cmp r0, 0x1
	bne _081533A4
	bl sub_8153190
	bl save_serialize_game
	ldr r0, =gUnknown_03006220
	bl sub_8152934
	movs r0, 0
	b _081533A6
	.pool
_081533A4:
	movs r0, 0x1
_081533A6:
	pop {r1}
	bx r1
	thumb_func_end sub_8153380

	thumb_func_start sub_81533AC
sub_81533AC: @ 81533AC
	push {r4,lr}
	ldr r1, =gUnknown_03006220
	movs r0, 0xE
	bl sub_81529D4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _081533C8
	movs r0, 0
	bl fullscreen_save_activate
_081533C8:
	cmp r4, 0xFF
	beq _081533D8
	movs r0, 0
	b _081533DA
	.pool
_081533D8:
	movs r0, 0x1
_081533DA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81533AC

	thumb_func_start sub_81533E0
sub_81533E0: @ 81533E0
	push {lr}
	ldr r1, =gUnknown_03006220
	movs r0, 0xE
	bl sub_8152A34
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _081533F8
	movs r0, 0
	bl fullscreen_save_activate
_081533F8:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81533E0

	thumb_func_start sub_8153408
sub_8153408: @ 8153408
	push {lr}
	ldr r1, =gUnknown_03006220
	movs r0, 0xE
	bl sub_8152CAC
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08153420
	movs r0, 0
	bl fullscreen_save_activate
_08153420:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153408

	thumb_func_start sub_8153430
sub_8153430: @ 8153430
	push {r4,lr}
	ldr r0, =gUnknown_03005D88
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0815346C
	bl sub_8153190
	bl save_serialize_game
	ldr r4, =gUnknown_03006220
	adds r0, r4, 0
	bl sub_8152990
	ldr r0, =gUnknown_03006208
	ldrh r0, [r0]
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl sub_8152A34
	movs r0, 0
	b _0815346E
	.pool
_0815346C:
	movs r0, 0x1
_0815346E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8153430

	thumb_func_start sub_8153474
sub_8153474: @ 8153474
	push {r4-r6,lr}
	movs r6, 0
	ldr r0, =gUnknown_03006208
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r0, r1, 16
	lsrs r5, r0, 16
	cmp r5, 0x4
	bhi _081534A8
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_03006220
	adds r1, r4, 0
	bl sub_8152A34
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8152D44
	b _081534B2
	.pool
_081534A8:
	ldr r1, =gUnknown_03006220
	adds r0, r5, 0
	bl sub_8152D44
	movs r6, 0x1
_081534B2:
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _081534C0
	movs r0, 0x1
	bl fullscreen_save_activate
_081534C0:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8153474

	thumb_func_start sub_81534D0
sub_81534D0: @ 81534D0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_03005D88
	ldr r0, [r0]
	cmp r0, 0x1
	beq _081534F0
	ldr r1, =gUnknown_03006210
	movs r0, 0x4
	strh r0, [r1]
	movs r0, 0xFF
	b _08153550
	.pool
_081534F0:
	bl sub_8153190
	cmp r4, 0
	beq _081534FC
	cmp r4, 0x3
	beq _08153528
_081534FC:
	ldr r0, =0x0000ffff
	ldr r1, =gUnknown_03006220
	bl sub_8152DD0
	lsls r0, 24
	lsrs r4, r0, 24
	bl save_deserialize_game
	ldr r0, =gUnknown_03006210
	strh r4, [r0]
	ldr r1, =gUnknown_03006214
	movs r0, 0
	str r0, [r1]
	b _0815354E
	.pool
_08153528:
	ldr r5, =0x0201c000
	movs r6, 0xF8
	lsls r6, 4
	movs r0, 0x1C
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81530DC
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0815354E
	adds r1, r5, r6
	movs r0, 0x1D
	adds r2, r6, 0
	bl sub_81530DC
	lsls r0, 24
	lsrs r4, r0, 24
_0815354E:
	adds r0, r4, 0
_08153550:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81534D0

	thumb_func_start sub_815355C
sub_815355C: @ 815355C
	push {r4-r7,lr}
	ldr r5, =gUnknown_03006204
	ldr r0, =gUnknown_0203ABBC
	str r0, [r5]
	adds r7, r0, 0
	ldr r0, =gUnknown_03005D88
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0815358C
	b _081535C8
	.pool
_0815357C:
	ldrb r1, [r7, 0xA]
	ldrb r0, [r7, 0xB]
	adds r1, r0
	ldrb r0, [r7, 0xC]
	adds r1, r0
	ldrb r0, [r7, 0xD]
	adds r0, r1
	b _081535CA
_0815358C:
	bl sub_8153190
	ldr r0, =gUnknown_03006220
	bl sub_8152EC8
	ldr r0, =gUnknown_03006200
	ldr r1, [r0]
	ands r1, r4
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 17
	lsrs r6, r0, 16
	movs r4, 0
_081535A6:
	adds r0, r4, r6
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r5]
	bl sub_815314C
	ldr r0, [r5]
	ldr r1, =0x00000ff4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0815357C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xD
	bls _081535A6
_081535C8:
	movs r0, 0
_081535CA:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_815355C

	thumb_func_start sub_81535DC
sub_81535DC: @ 81535DC
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xE2
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08153608
	ldr r4, =gUnknown_0203ABBC
	movs r3, 0x80
	lsls r3, 5
	adds r0, r1, 0
	movs r1, 0
	adds r2, r4, 0
	bl ReadFlash
	ldr r1, [r4]
	ldr r0, =0x0000b39d
	cmp r1, r0
	beq _08153614
_08153608:
	movs r0, 0xFF
	b _0815362A
	.pool
_08153614:
	movs r3, 0
	ldr r5, =0x00000ffb
	adds r2, r4, 0x4
_0815361A:
	adds r0, r6, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r5
	ble _0815361A
	movs r0, 0x1
_0815362A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81535DC

	thumb_func_start sub_8153634
sub_8153634: @ 8153634
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0xE2
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08153680
	ldr r7, =gUnknown_0203ABBC
	ldr r0, =0x0000b39d
	adds r3, r7, 0
	stm r3!, {r0}
	movs r2, 0
	ldr r4, =0x00000ffb
_08153654:
	adds r0, r3, r2
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r4
	ble _08153654
	adds r0, r6, 0
	adds r1, r7, 0
	bl ProgramFlashSectorsAndVerify
	cmp r0, 0
	bne _08153680
	movs r0, 0x1
	b _08153682
	.pool
_08153680:
	movs r0, 0xFF
_08153682:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8153634

	thumb_func_start sub_8153688
sub_8153688: @ 8153688
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xB
	bls _081536A2
	b _081537C2
_081536A2:
	lsls r0, 2
	ldr r1, =_081536B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081536B4:
	.4byte _081536E4
	.4byte _081536F4
	.4byte _081536FE
	.4byte _0815371A
	.4byte _0815372C
	.4byte _08153742
	.4byte _08153758
	.4byte _08153762
	.4byte _08153778
	.4byte _0815378C
	.4byte _08153796
	.4byte _081537A8
_081536E4:
	ldr r0, =gUnknown_03002700
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	strh r0, [r4]
	b _081537C2
	.pool
_081536F4:
	bl sub_800ADF8
	movs r0, 0x2
	strh r0, [r4]
	b _081537C2
_081536FE:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081537C2
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08153714
	bl save_serialize_map
_08153714:
	movs r0, 0x3
	strh r0, [r4]
	b _081537C2
_0815371A:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08153726
	bl sub_8076D5C
_08153726:
	bl sub_8153380
	b _08153752
_0815372C:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0x5
	bne _081537C2
	movs r0, 0
	strh r0, [r4, 0x2]
	strh r1, [r4]
	b _081537C2
_08153742:
	bl sub_81533AC
	lsls r0, 24
	cmp r0, 0
	beq _08153752
	movs r0, 0x6
	strh r0, [r4]
	b _081537C2
_08153752:
	movs r0, 0x4
	strh r0, [r4]
	b _081537C2
_08153758:
	bl sub_81533E0
	movs r0, 0x7
	strh r0, [r4]
	b _081537C2
_08153762:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815376E
	bl sav2_gender2_inplace_and_xFE
_0815376E:
	bl sub_800ADF8
	movs r0, 0x8
	strh r0, [r4]
	b _081537C2
_08153778:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081537C2
	bl sub_8153408
	movs r0, 0x9
	strh r0, [r4]
	b _081537C2
_0815378C:
	bl sub_800ADF8
	movs r0, 0xA
	strh r0, [r4]
	b _081537C2
_08153796:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081537C2
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081537C2
_081537A8:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _081537C2
	ldr r1, =gUnknown_03002700
	movs r0, 0
	strb r0, [r1]
	adds r0, r2, 0
	bl DestroyTask
_081537C2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153688

	.align 2, 0 @ Don't pad with nop.
