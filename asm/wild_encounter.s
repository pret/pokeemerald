	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80B48B8
sub_80B48B8: @ 80B48B8
	ldr r1, =gUnknown_02038C00
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80B48B8

	thumb_func_start sub_80B48C4
sub_80B48C4: @ 80B48C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x4]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gUnknown_08553A7C
	lsls r1, r2, 1
	adds r1, r2
	lsls r2, r1, 1
	adds r2, r3
	adds r0, r1, 0x1
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	mov r9, r0
	adds r1, 0x2
	lsls r1, 1
	adds r1, r3
	ldrh r6, [r1]
	ldrh r5, [r2]
	cmp r5, r9
	bhi _080B496E
	ldr r0, =gUnknown_02037318
	mov r10, r0
_080B4906:
	movs r4, 0
	mov r1, r10
	ldr r0, [r1]
	ldr r0, [r0]
	cmp r4, r0
	bge _080B4964
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r0, 16
	mov r8, r0
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	asrs r7, r0, 16
_080B4920:
	adds r0, r4, 0x7
	adds r1, r5, 0x7
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl sub_8089660
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B4954
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r8, r4
	bne _080B4954
	cmp r7, r5
	bne _080B4954
	adds r0, r6, 0
	b _080B4974
	.pool
_080B4954:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	mov r1, r10
	ldr r0, [r1]
	ldr r0, [r0]
	cmp r4, r0
	blt _080B4920
_080B4964:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r9
	bls _080B4906
_080B496E:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r0, 16
_080B4974:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B48C4

	thumb_func_start sub_80B4984
sub_80B4984: @ 80B4984
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	movs r7, 0
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0x88
	lsls r0, 6
	cmp r1, r0
	bne _080B4A7A
	add r5, sp, 0xC
	mov r4, sp
	adds r4, 0xE
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	ldrh r0, [r5]
	subs r0, 0x7
	strh r0, [r5]
	ldrh r0, [r4]
	subs r0, 0x7
	strh r0, [r4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, =gUnknown_08553A7C
	mov r9, r5
	mov r8, r4
	ldrh r2, [r0, 0x6]
	cmp r1, r2
	blt _080B49D0
	ldrh r3, [r0, 0x8]
	cmp r1, r3
	bgt _080B49D0
	movs r7, 0x1
_080B49D0:
	mov r2, r8
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldrh r2, [r0, 0xC]
	cmp r1, r2
	blt _080B49E4
	ldrh r0, [r0, 0xE]
	cmp r1, r0
	bgt _080B49E4
	movs r7, 0x2
_080B49E4:
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x31
	bls _080B4A08
	b _080B4A7A
	.pool
_080B4A04:
	movs r0, 0x1
	b _080B4A7C
_080B4A08:
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	ldr r3, =0x00002e6a
	adds r0, r3
	ldrh r0, [r0]
	bl sub_80B4AB8
	movs r5, 0
	ldr r6, =0x000001bf
_080B4A1A:
	bl sub_80B4A98
	lsls r1, r5, 1
	mov r2, sp
	adds r4, r2, r1
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __umodsi3
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	bne _080B4A38
	strh r6, [r4]
_080B4A38:
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080B4A4A
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080B4A4A:
	cmp r5, 0x6
	bne _080B4A1A
	mov r3, r9
	movs r1, 0
	ldrsh r0, [r3, r1]
	mov r2, r8
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r2, r7, 0
	bl sub_80B48C4
	lsls r0, 16
	lsrs r1, r0, 16
	movs r5, 0
_080B4A66:
	lsls r0, r5, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r1, r0
	beq _080B4A04
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _080B4A66
_080B4A7A:
	movs r0, 0
_080B4A7C:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4984

	thumb_func_start sub_80B4A98
sub_80B4A98: @ 80B4A98
	ldr r2, =gUnknown_02038C04
	ldr r1, [r2]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00003039
	adds r0, r1
	str r0, [r2]
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_80B4A98

	thumb_func_start sub_80B4AB8
sub_80B4AB8: @ 80B4AB8
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_02038C04
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80B4AB8

	thumb_func_start wild_pokemon_rand_grass
wild_pokemon_rand_grass: @ 80B4AC8
	push {lr}
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x13
	bhi _080B4AE4
	movs r0, 0
	b _080B4B7E
_080B4AE4:
	adds r0, r1, 0
	subs r0, 0x14
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _080B4AF4
	movs r0, 0x1
	b _080B4B7E
_080B4AF4:
	adds r0, r1, 0
	subs r0, 0x28
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _080B4B04
	movs r0, 0x2
	b _080B4B7E
_080B4B04:
	adds r0, r1, 0
	subs r0, 0x32
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _080B4B14
	movs r0, 0x3
	b _080B4B7E
_080B4B14:
	adds r0, r1, 0
	subs r0, 0x3C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _080B4B24
	movs r0, 0x4
	b _080B4B7E
_080B4B24:
	adds r0, r1, 0
	subs r0, 0x46
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _080B4B34
	movs r0, 0x5
	b _080B4B7E
_080B4B34:
	adds r0, r1, 0
	subs r0, 0x50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080B4B44
	movs r0, 0x6
	b _080B4B7E
_080B4B44:
	adds r0, r1, 0
	subs r0, 0x55
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080B4B54
	movs r0, 0x7
	b _080B4B7E
_080B4B54:
	adds r0, r1, 0
	subs r0, 0x5A
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080B4B64
	movs r0, 0x8
	b _080B4B7E
_080B4B64:
	adds r0, r1, 0
	subs r0, 0x5E
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080B4B74
	movs r0, 0x9
	b _080B4B7E
_080B4B74:
	cmp r1, 0x62
	beq _080B4B7C
	movs r0, 0xB
	b _080B4B7E
_080B4B7C:
	movs r0, 0xA
_080B4B7E:
	pop {r1}
	bx r1
	thumb_func_end wild_pokemon_rand_grass

	thumb_func_start wild_pokemon_rand_water
wild_pokemon_rand_water: @ 80B4B84
	push {lr}
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	cmp r1, 0x3B
	bhi _080B4BA2
	movs r0, 0
	b _080B4BD4
_080B4BA2:
	adds r0, r1, 0
	subs r0, 0x3C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1D
	bhi _080B4BB2
	movs r0, 0x1
	b _080B4BD4
_080B4BB2:
	adds r0, r1, 0
	subs r0, 0x5A
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080B4BC2
	movs r0, 0x2
	b _080B4BD4
_080B4BC2:
	adds r0, r2, 0
	subs r0, 0x5F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _080B4BD2
	movs r0, 0x4
	b _080B4BD4
_080B4BD2:
	movs r0, 0x3
_080B4BD4:
	pop {r1}
	bx r1
	thumb_func_end wild_pokemon_rand_water

	thumb_func_start sub_80B4BD8
sub_80B4BD8: @ 80B4BD8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	movs r5, 0
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0x1
	beq _080B4C12
	cmp r4, 0x1
	bgt _080B4C02
	cmp r4, 0
	beq _080B4C08
	b _080B4C6C
_080B4C02:
	cmp r6, 0x2
	beq _080B4C36
	b _080B4C6C
_080B4C08:
	movs r5, 0x1
	cmp r1, 0x45
	bhi _080B4C6C
	movs r5, 0
	b _080B4C6C
_080B4C12:
	cmp r1, 0x3B
	bhi _080B4C18
	movs r5, 0x2
_080B4C18:
	adds r0, r1, 0
	subs r0, 0x3C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _080B4C26
	movs r5, 0x3
_080B4C26:
	adds r0, r1, 0
	subs r0, 0x50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _080B4C6C
	movs r5, 0x4
	b _080B4C6C
_080B4C36:
	cmp r1, 0x27
	bhi _080B4C3C
	movs r5, 0x5
_080B4C3C:
	adds r0, r1, 0
	subs r0, 0x28
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x27
	bhi _080B4C4A
	movs r5, 0x6
_080B4C4A:
	adds r0, r1, 0
	subs r0, 0x50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE
	bhi _080B4C58
	movs r5, 0x7
_080B4C58:
	adds r0, r1, 0
	subs r0, 0x5F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080B4C66
	movs r5, 0x8
_080B4C66:
	cmp r1, 0x63
	bne _080B4C6C
	movs r5, 0x9
_080B4C6C:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B4BD8

	thumb_func_start sub_80B4C74
sub_80B4C74: @ 80B4C74
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x1]
	ldrb r1, [r4]
	cmp r0, r1
	bcc _080B4C86
	ldrb r7, [r4]
	adds r6, r0, 0
	b _080B4C8A
_080B4C86:
	ldrb r7, [r4, 0x1]
	ldrb r6, [r4]
_080B4C8A:
	subs r4, r6, r7
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gUnknown_020244EC
	adds r0, r5, 0
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _080B4CEA
	adds r0, r5, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x37
	beq _080B4CC8
	cmp r0, 0x48
	beq _080B4CC8
	cmp r0, 0x2E
	bne _080B4CEA
_080B4CC8:
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B4CE0
	adds r0, r6, 0
	b _080B4CF0
	.pool
_080B4CE0:
	cmp r4, 0
	beq _080B4CEA
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080B4CEA:
	adds r0, r7, r4
	lsls r0, 24
	lsrs r0, 24
_080B4CF0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B4C74

	thumb_func_start get_wild_data_index_for_map
get_wild_data_index_for_map: @ 80B4CF8
	push {r4-r6,lr}
	movs r4, 0
	ldr r0, =gWildMonHeaders
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0xFF
	beq _080B4D6C
	ldr r6, =0x00006a18
_080B4D08:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r5
	ldrb r1, [r3]
	ldr r0, =gUnknown_03005D8C
	ldr r2, [r0]
	movs r0, 0x4
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _080B4D58
	ldrb r1, [r3, 0x1]
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _080B4D58
	ldrh r0, [r2, 0x4]
	cmp r0, r6
	bne _080B4D44
	ldr r0, =0x0000403e
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	bls _080B4D3E
	movs r0, 0
_080B4D3E:
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
_080B4D44:
	adds r0, r4, 0
	b _080B4D6E
	.pool
_080B4D58:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080B4D08
_080B4D6C:
	ldr r0, =0x0000ffff
_080B4D6E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end get_wild_data_index_for_map

	thumb_func_start sub_80B4D78
sub_80B4D78: @ 80B4D78
	push {r4-r7,lr}
	sub sp, 0x1C
	bl GetSafariZoneFlag
	cmp r0, 0x1
	bne _080B4E0E
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4F
	bhi _080B4E0E
	bl sub_80FC3B8
	adds r7, r0, 0
	cmp r7, 0
	beq _080B4E0E
	movs r5, 0
_080B4DA6:
	mov r1, sp
	adds r0, r1, r5
	strb r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x18
	bls _080B4DA6
	movs r5, 0
_080B4DB8:
	adds r1, r5, 0x1
	lsls r0, r1, 24
	lsrs r4, r0, 24
	adds r6, r1, 0
	cmp r4, 0x18
	bhi _080B4DE8
	add r5, sp
_080B4DC6:
	bl GenerateRandomNumber
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _080B4DDE
	ldrb r2, [r5]
	mov r0, sp
	adds r1, r0, r4
	ldrb r0, [r1]
	strb r0, [r5]
	strb r2, [r1]
_080B4DDE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x18
	bls _080B4DC6
_080B4DE8:
	lsls r0, r6, 24
	lsrs r5, r0, 24
	cmp r5, 0x17
	bls _080B4DB8
	movs r5, 0
_080B4DF2:
	mov r1, sp
	adds r4, r1, r5
	ldrb r0, [r4]
	adds r1, r7, 0
	bl sub_8136FE4
	lsls r0, 16
	cmp r0, 0
	bgt _080B4E48
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x18
	bls _080B4DF2
_080B4E0E:
	ldr r4, =gUnknown_020244EC
	adds r0, r4, 0
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _080B4E4C
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1C
	bne _080B4E4C
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B4E4C
	adds r0, r4, 0
	movs r1, 0
	bl pokemon_getattr
	b _080B4E54
	.pool
_080B4E48:
	ldrb r0, [r4]
	b _080B4E5E
_080B4E4C:
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
_080B4E54:
	movs r1, 0x19
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
_080B4E5E:
	add sp, 0x1C
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B4D78

	thumb_func_start sub_80B4E68
sub_80B4E68: @ 80B4E68
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	bl zero_enemy_party_data
	movs r2, 0x1
	ldr r1, =gBaseStats
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	beq _080B4E96
	cmp r0, 0
	blt _080B4E98
	cmp r0, 0xFF
	bgt _080B4E98
	cmp r0, 0xFE
	blt _080B4E98
_080B4E96:
	movs r2, 0
_080B4E98:
	cmp r2, 0
	beq _080B4F28
	ldr r5, =gUnknown_020244EC
	adds r0, r5, 0
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _080B4F28
	adds r0, r5, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x38
	bne _080B4F28
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _080B4F28
	adds r0, r5, 0
	movs r1, 0xB
	bl pokemon_getattr
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0
	bl pokemon_getattr
	adds r1, r0, 0
	adds r0, r4, 0
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFE
	bne _080B4F00
	movs r4, 0
	b _080B4F02
	.pool
_080B4F00:
	movs r4, 0xFE
_080B4F02:
	bl sub_80B4D78
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02024744
	str r4, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r1, 0
	adds r1, r6, 0
	adds r2, r7, 0
	movs r3, 0x20
	bl sub_8067EF8
	b _080B4F40
	.pool
_080B4F28:
	bl sub_80B4D78
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02024744
	str r0, [sp]
	adds r0, r1, 0
	adds r1, r6, 0
	adds r2, r7, 0
	movs r3, 0x20
	bl pokemon_make_with_nature
_080B4F40:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B4E68

	thumb_func_start sub_80B4F4C
sub_80B4F4C: @ 80B4F4C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r1, 24
	lsrs r3, r1, 24
	adds r4, r3, 0
	lsls r2, 24
	lsrs r6, r2, 24
	movs r1, 0
	mov r0, sp
	strb r1, [r0]
	cmp r3, 0x1
	beq _080B4FA0
	cmp r3, 0x1
	bgt _080B4F70
	cmp r3, 0
	beq _080B4F76
	b _080B4FBA
_080B4F70:
	cmp r4, 0x2
	beq _080B4FB2
	b _080B4FBA
_080B4F76:
	ldr r0, [r5, 0x4]
	movs r1, 0x8
	movs r2, 0x2A
	mov r3, sp
	bl TryGetAbilityInfluencedWildMonIndex
	lsls r0, 24
	cmp r0, 0
	bne _080B4FBA
	ldr r0, [r5, 0x4]
	movs r1, 0xD
	movs r2, 0x9
	mov r3, sp
	bl TryGetAbilityInfluencedWildMonIndex
	lsls r0, 24
	cmp r0, 0
	bne _080B4FBA
	bl wild_pokemon_rand_grass
	b _080B4FB6
_080B4FA0:
	ldr r0, [r5, 0x4]
	movs r1, 0xD
	movs r2, 0x9
	mov r3, sp
	bl TryGetAbilityInfluencedWildMonIndex
	lsls r0, 24
	cmp r0, 0
	bne _080B4FBA
_080B4FB2:
	bl wild_pokemon_rand_water
_080B4FB6:
	mov r1, sp
	strb r0, [r1]
_080B4FBA:
	mov r0, sp
	ldrb r1, [r0]
	lsls r1, 2
	ldr r0, [r5, 0x4]
	adds r0, r1
	bl sub_80B4C74
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	beq _080B4FE0
	adds r0, r4, 0
	bl sub_80B58CC
	lsls r0, 24
	cmp r0, 0
	beq _080B5000
_080B4FE0:
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	movs r0, 0xB3
	lsls r0, 1
	cmp r1, r0
	beq _080B5008
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080B5008
	adds r0, r4, 0
	bl DoKeenEyeIntimidateWildEncounterTest
	lsls r0, 24
	cmp r0, 0
	bne _080B5008
_080B5000:
	movs r0, 0
	b _080B501C
	.pool
_080B5008:
	mov r0, sp
	ldrb r0, [r0]
	ldr r1, [r5, 0x4]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x2]
	adds r1, r4, 0
	bl sub_80B4E68
	movs r0, 0x1
_080B501C:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B4F4C

	thumb_func_start sub_80B5024
sub_80B5024: @ 80B5024
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_80B4BD8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 22
	ldr r0, [r5, 0x4]
	adds r0, r4
	bl sub_80B4C74
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, [r5, 0x4]
	adds r0, r4, r0
	ldrh r0, [r0, 0x2]
	bl sub_80B4E68
	ldr r0, [r5, 0x4]
	adds r4, r0
	ldrh r0, [r4, 0x2]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B5024

	thumb_func_start SetUpMassOutbreakEncounter
SetUpMassOutbreakEncounter: @ 80B505C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B508C
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	ldr r1, =0x00002b94
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80B58CC
	lsls r0, 24
	cmp r0, 0
	bne _080B508C
	movs r0, 0
	b _080B50C6
	.pool
_080B508C:
	ldr r0, =gUnknown_03005D8C
	ldr r1, [r0]
	ldr r2, =0x00002b90
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r2, 0x4
	adds r1, r2
	ldrb r1, [r1]
	bl sub_80B4E68
	movs r4, 0
_080B50A2:
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	lsls r1, r4, 1
	ldr r2, =0x00002b98
	adds r0, r2
	adds r0, r1
	ldrh r1, [r0]
	lsls r2, r4, 24
	lsrs r2, 24
	ldr r0, =gUnknown_02024744
	bl sub_80691F4
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _080B50A2
	movs r0, 0x1
_080B50C6:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end SetUpMassOutbreakEncounter

	thumb_func_start DoMassOutbreakEncounterTest
DoMassOutbreakEncounterTest: @ 80B50DC
	push {r4,lr}
	ldr r4, =gUnknown_03005D8C
	ldr r2, [r4]
	ldr r1, =0x00002b90
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080B513C
	movs r1, 0x5
	ldrsb r1, [r2, r1]
	ldr r3, =0x00002b92
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _080B513C
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	adds r3, 0x1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _080B513C
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	ldr r1, [r4]
	ldr r2, =0x00002ba1
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080B513C
	movs r0, 0x1
	b _080B513E
	.pool
_080B513C:
	movs r0, 0
_080B513E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end DoMassOutbreakEncounterTest

	thumb_func_start DoWildEncounterRateDiceRoll
DoWildEncounterRateDiceRoll: @ 80B5144
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xB4
	lsls r1, 4
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bcc _080B5168
	movs r0, 0
	b _080B516A
_080B5168:
	movs r0, 0x1
_080B516A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end DoWildEncounterRateDiceRoll

	thumb_func_start DoWildEncounterRateTest
DoWildEncounterRateTest: @ 80B5170
	push {r4,lr}
	sub sp, 0x4
	str r0, [sp]
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r0, 4
	str r0, [sp]
	movs r0, 0x6
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080B519A
	ldr r1, [sp]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	movs r1, 0x64
	bl __udivsi3
	str r0, [sp]
_080B519A:
	mov r0, sp
	bl affects_encounter_rate_based_on_flags
	mov r0, sp
	bl ApplyCleanseTagWildEncounterRateReduction
	cmp r4, 0
	bne _080B5216
	ldr r4, =gUnknown_020244EC
	adds r0, r4, 0
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _080B5216
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B51E8
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	bne _080B5210
	ldr r1, [sp]
	lsls r0, r1, 1
	adds r0, r1
	lsrs r0, 2
	b _080B5214
	.pool
_080B51E8:
	cmp r0, 0x23
	bne _080B51F2
	ldr r0, [sp]
	lsls r0, 1
	b _080B5214
_080B51F2:
	cmp r0, 0x49
	beq _080B5210
	cmp r0, 0x47
	bne _080B5200
	ldr r0, [sp]
	lsls r0, 1
	b _080B5214
_080B5200:
	cmp r0, 0x8
	bne _080B5216
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	adds r0, 0x2E
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _080B5216
_080B5210:
	ldr r0, [sp]
	lsrs r0, 1
_080B5214:
	str r0, [sp]
_080B5216:
	ldr r0, [sp]
	movs r1, 0xB4
	lsls r1, 4
	cmp r0, r1
	bls _080B5222
	str r1, [sp]
_080B5222:
	ldr r0, [sp]
	lsls r0, 16
	lsrs r0, 16
	bl DoWildEncounterRateDiceRoll
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end DoWildEncounterRateTest

	thumb_func_start DoGlobalWildEncounterDiceRoll
DoGlobalWildEncounterDiceRoll: @ 80B523C
	push {lr}
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3B
	bhi _080B5258
	movs r0, 0x1
	b _080B525A
_080B5258:
	movs r0, 0
_080B525A:
	pop {r1}
	bx r1
	thumb_func_end DoGlobalWildEncounterDiceRoll

	thumb_func_start sub_80B5260
sub_80B5260: @ 80B5260
	push {lr}
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xE0
	lsls r0, 3
	cmp r1, r0
	bne _080B5280
	movs r0, 0x53
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	b _080B5282
	.pool
_080B5280:
	movs r0, 0
_080B5282:
	pop {r1}
	bx r1
	thumb_func_end sub_80B5260

	thumb_func_start is_it_battle_time_2
is_it_battle_time_2: @ 80B5288
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r6, r0, 16
	mov r9, r6
	lsls r1, 16
	lsrs r7, r1, 16
	mov r8, r7
	ldr r0, =gUnknown_02038C00
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080B52A6
	b _080B54FE
_080B52A6:
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	bne _080B539C
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	movs r0, 0xB3
	lsls r0, 1
	cmp r1, r0
	bne _080B5330
	bl sub_81A7D00
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r7, r6
	beq _080B52D8
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, 24
	cmp r0, 0
	bne _080B52D8
	b _080B54FE
_080B52D8:
	ldr r1, =gUnknown_08553A14
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 2
	adds r1, 0x4
	adds r4, r0, r1
	ldr r0, [r4]
	ldrb r0, [r0]
	movs r1, 0
	bl DoWildEncounterRateTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B52F8
	b _080B54FE
_080B52F8:
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x2
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B530C
	b _080B54FE
_080B530C:
	movs r0, 0x1
	bl sub_81A7B90
	cmp r0, 0
	bne _080B5318
	b _080B54FE
_080B5318:
	bl sub_80B06B0
	movs r0, 0x1
	b _080B5500
	.pool
_080B5330:
	ldr r0, =0x00000169
	cmp r1, r0
	beq _080B5338
	b _080B54FE
_080B5338:
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r5, [r0]
	cmp r7, r6
	beq _080B5352
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, 24
	cmp r0, 0
	bne _080B5352
	b _080B54FE
_080B5352:
	ldr r1, =gUnknown_08553894
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 2
	adds r1, 0x4
	adds r4, r0, r1
	ldr r0, [r4]
	ldrb r0, [r0]
	movs r1, 0
	bl DoWildEncounterRateTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B5372
	b _080B54FE
_080B5372:
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x2
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B5386
	b _080B54FE
_080B5386:
	bl sub_81A9C04
	b _080B54F6
	.pool
_080B539C:
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_808952C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B543C
	ldr r1, =gWildMonHeaders
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	adds r4, r2, 0
	cmp r0, 0
	bne _080B53C4
	b _080B54FE
_080B53C4:
	cmp r7, r6
	beq _080B53D4
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, 24
	cmp r0, 0
	bne _080B53D4
	b _080B54FE
_080B53D4:
	ldr r1, =gWildMonHeaders
	adds r0, r4, r5
	lsls r0, 2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	movs r1, 0
	bl DoWildEncounterRateTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B53F2
	b _080B54FE
_080B53F2:
	bl sub_8161EDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B54BA
	bl DoMassOutbreakEncounterTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B5418
	movs r0, 0x3
	bl SetUpMassOutbreakEncounter
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B54F6
_080B5418:
	ldr r1, =gWildMonHeaders
	adds r0, r4, r5
	lsls r0, 2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x3
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B54F6
	b _080B54FE
	.pool
_080B543C:
	adds r0, r4, 0
	bl sub_8089558
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B5464
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080B54FE
	adds r0, r4, 0
	bl sub_80894AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B54FE
_080B5464:
	bl sub_80B5260
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B54FE
	ldr r1, =gWildMonHeaders
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	adds r4, r2, 0
	cmp r0, 0
	beq _080B54FE
	cmp r8, r9
	beq _080B5492
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, 24
	cmp r0, 0
	beq _080B54FE
_080B5492:
	ldr r1, =gWildMonHeaders
	adds r0, r4, r5
	lsls r0, 2
	adds r1, 0x8
	adds r4, r0, r1
	ldr r0, [r4]
	ldrb r0, [r0]
	movs r1, 0
	bl DoWildEncounterRateTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B54FE
	bl sub_8161EDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B54E4
_080B54BA:
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	ldr r1, =0x000031dc
	adds r0, r1
	ldrb r0, [r0, 0xC]
	bl sub_80B58CC
	lsls r0, 24
	cmp r0, 0
	beq _080B54FE
	bl sub_80B072C
	movs r0, 0x1
	b _080B5500
	.pool
_080B54E4:
	ldr r0, [r4]
	movs r1, 0x1
	movs r2, 0x3
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B54FE
_080B54F6:
	bl sub_80B0698
	movs r0, 0x1
	b _080B5500
_080B54FE:
	movs r0, 0
_080B5500:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end is_it_battle_time_2

	thumb_func_start rock_smash_wild_pokemon_encounter
rock_smash_wild_pokemon_encounter: @ 80B550C
	push {r4,lr}
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _080B5568
	ldr r1, =gWildMonHeaders
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r1, 0xC
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _080B5554
	ldrb r0, [r4]
	movs r1, 0x1
	bl DoWildEncounterRateTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B5568
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0x3
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _080B5568
	bl sub_80B0698
_080B5554:
	ldr r0, =gUnknown_020375F0
	strh r4, [r0]
	b _080B556E
	.pool
_080B5568:
	ldr r1, =gUnknown_020375F0
	movs r0, 0
	strh r0, [r1]
_080B556E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end rock_smash_wild_pokemon_encounter

	thumb_func_start sub_80B5578
sub_80B5578: @ 80B5578
	push {r4,r5,lr}
	sub sp, 0x4
	mov r5, sp
	adds r5, 0x2
	mov r0, sp
	adds r1, r5, 0
	bl PlayerGetDestCoords
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	bne _080B562C
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	movs r0, 0xB3
	lsls r0, 1
	cmp r1, r0
	bne _080B55E4
	bl sub_81A7D00
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_08553A14
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B55CA
	b _080B56F2
_080B55CA:
	movs r0, 0
	bl sub_81A7B90
	bl sub_80B06B0
	movs r0, 0x1
	b _080B56F4
	.pool
_080B55E4:
	ldr r0, =0x00000169
	cmp r1, r0
	beq _080B55EC
	b _080B56F2
_080B55EC:
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r4, [r0]
	ldr r1, =gUnknown_08553894
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80B4F4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B56F2
	bl sub_81A9C04
	b _080B56EA
	.pool
_080B562C:
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl sub_808952C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B568C
	ldr r1, =gWildMonHeaders
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r1, 0x4
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _080B56F2
	bl sub_8161EDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B56D4
	bl DoMassOutbreakEncounterTest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B5680
	movs r0, 0
	bl SetUpMassOutbreakEncounter
	b _080B56EA
	.pool
_080B5680:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_80B4F4C
	b _080B56EA
_080B568C:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl sub_8089558
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B56F2
	bl sub_80B5260
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B56F2
	ldr r1, =gWildMonHeaders
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _080B56F2
	bl sub_8161EDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B56E0
_080B56D4:
	bl sub_80B072C
	movs r0, 0x1
	b _080B56F4
	.pool
_080B56E0:
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_80B4F4C
_080B56EA:
	bl sub_80B0698
	movs r0, 0x1
	b _080B56F4
_080B56F2:
	movs r0, 0
_080B56F4:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B5578

	thumb_func_start GetFishingWildMonListHeader
GetFishingWildMonListHeader: @ 80B56FC
	push {lr}
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _080B572C
	ldr r0, =gWildMonHeaders
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r0, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _080B572C
	movs r0, 0x1
	b _080B572E
	.pool
_080B572C:
	movs r0, 0
_080B572E:
	pop {r1}
	bx r1
	thumb_func_end GetFishingWildMonListHeader

	thumb_func_start sub_80B5734
sub_80B5734: @ 80B5734
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_80B4984
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B5764
	ldr r4, =gUnknown_08553A78
	adds r0, r4, 0
	bl sub_80B4C74
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4, 0
	bl sub_80B4E68
	b _080B5784
	.pool
_080B5764:
	ldr r4, =gWildMonHeaders
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r4, 0x10
	adds r1, r4
	ldr r0, [r1]
	adds r1, r5, 0
	bl sub_80B5024
	lsls r0, 16
	lsrs r4, r0, 16
_080B5784:
	movs r0, 0xC
	bl sav12_xor_increment
	adds r0, r4, 0
	bl sub_80EDA3C
	bl sub_80B0698
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B5734

	thumb_func_start wild_pokemon_rand_for_map
wild_pokemon_rand_for_map: @ 80B57A0
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0
	strb r0, [r6]
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _080B57D2
	ldr r2, =gWildMonHeaders
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldr r5, [r0]
	adds r2, 0x8
	adds r1, r2
	ldr r4, [r1]
	cmp r5, 0
	bne _080B57E0
	cmp r4, 0
	bne _080B57E6
_080B57D2:
	movs r0, 0
	b _080B5826
	.pool
_080B57E0:
	cmp r4, 0
	bne _080B57F4
	b _080B5818
_080B57E6:
	movs r0, 0x1
	strb r0, [r6]
	bl wild_pokemon_rand_water
	lsls r0, 24
	ldr r1, [r4, 0x4]
	b _080B5820
_080B57F4:
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4F
	bls _080B5818
	movs r0, 0x1
	strb r0, [r6]
	bl wild_pokemon_rand_water
	lsls r0, 24
	ldr r1, [r4, 0x4]
	b _080B5820
_080B5818:
	bl wild_pokemon_rand_grass
	lsls r0, 24
	ldr r1, [r5, 0x4]
_080B5820:
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0, 0x2]
_080B5826:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end wild_pokemon_rand_for_map

	thumb_func_start sub_80B582C
sub_80B582C: @ 80B582C
	push {r4,lr}
	bl get_wild_data_index_for_map
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _080B5868
	ldr r1, =gWildMonHeaders
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _080B5868
	bl wild_pokemon_rand_water
	lsls r0, 24
	ldr r1, [r4, 0x4]
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0, 0x2]
	b _080B586A
	.pool
_080B5868:
	movs r0, 0
_080B586A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B582C

	thumb_func_start sub_80B5870
sub_80B5870: @ 80B5870
	push {r4,r5,lr}
	bl InBattlePike
	lsls r0, 24
	cmp r0, 0
	bne _080B58C4
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080B58C4
	bl InUnionRoom
	cmp r0, 0x1
	beq _080B58C4
	ldr r5, =0x00004021
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080B58C4
	subs r4, r0, 0x1
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl VarSet
	cmp r4, 0
	bne _080B58C4
	ldr r0, =gUnknown_082A4B2A
	bl script_env_1_execute_new_script
	movs r0, 0x1
	b _080B58C6
	.pool
_080B58C4:
	movs r0, 0
_080B58C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B5870

	thumb_func_start sub_80B58CC
sub_80B58CC: @ 80B58CC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x00004021
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080B5912
	movs r5, 0
_080B58E0:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gUnknown_020244EC
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl pokemon_getattr
	cmp r0, 0
	beq _080B5920
	adds r0, r4, 0
	movs r1, 0x2D
	bl pokemon_getattr
	cmp r0, 0
	bne _080B5920
	adds r0, r4, 0
	movs r1, 0x38
	bl pokemon_getattr
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bcc _080B592A
_080B5912:
	movs r0, 0x1
	b _080B592C
	.pool
_080B5920:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _080B58E0
_080B592A:
	movs r0, 0
_080B592C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B58CC

	thumb_func_start DoKeenEyeIntimidateWildEncounterTest
@ _BOOL1 DoKeenEyeIntimidateWildEncounterTest(u8 wildMonLevel)
DoKeenEyeIntimidateWildEncounterTest: @ 80B5934
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_020244EC
	adds r0, r4, 0
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _080B5988
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x33
	beq _080B595A
	cmp r0, 0x16
	bne _080B5988
_080B595A:
	adds r0, r4, 0
	movs r1, 0x38
	bl pokemon_getattr
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _080B5988
	subs r0, 0x5
	cmp r5, r0
	bgt _080B5988
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B5988
	movs r0, 0
	b _080B598A
	.pool
_080B5988:
	movs r0, 0x1
_080B598A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end DoKeenEyeIntimidateWildEncounterTest

	thumb_func_start TryGetRandomWildMonIndexByType
@ _BOOL1 TryGetRandomWildMonIndexByType(WildMonEntry *mons, u8 type, u8 numMons, u8 *monIndex)
TryGetRandomWildMonIndexByType: @ 80B5990
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r7, sp
	mov r12, r0
	mov r8, r3
	lsls r1, 24
	lsrs r1, 24
	str r1, [r7]
	lsls r2, 24
	lsrs r2, 24
	mov r9, sp
	adds r0, r2, 0x3
	lsrs r0, 2
	lsls r0, 2
	mov r1, sp
	subs r1, r0
	mov sp, r1
	mov r5, sp
	movs r3, 0
	cmp r3, r2
	bcs _080B59D2
	movs r1, 0
_080B59C4:
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r2
	bcc _080B59C4
_080B59D2:
	movs r4, 0
	movs r3, 0
	cmp r4, r2
	bcs _080B5A12
	ldr r6, =gBaseStats
	mov r10, r6
_080B59DE:
	lsls r0, r3, 2
	add r0, r12
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r6, r10
	adds r1, r0, r6
	ldrb r0, [r1, 0x6]
	ldr r6, [r7]
	cmp r0, r6
	beq _080B59FC
	ldrb r0, [r1, 0x7]
	cmp r0, r6
	bne _080B5A08
_080B59FC:
	adds r1, r4, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r1, r5, r1
	strb r3, [r1]
_080B5A08:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r2
	bcc _080B59DE
_080B5A12:
	cmp r4, 0
	beq _080B5A1A
	cmp r4, r2
	bne _080B5A24
_080B5A1A:
	movs r0, 0
	b _080B5A3C
	.pool
_080B5A24:
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	adds r0, r5, r0
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	movs r0, 0x1
_080B5A3C:
	mov sp, r9
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end TryGetRandomWildMonIndexByType

	thumb_func_start TryGetAbilityInfluencedWildMonIndex
@ _BOOL1 TryGetAbilityInfluencedWildMonIndex(WildMonEntry *mons, u8 type, u8 abilityId, u8 *monIndex)
TryGetAbilityInfluencedWildMonIndex: @ 80B5A50
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	mov r8, r3
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	ldr r4, =gUnknown_020244EC
	adds r0, r4, 0
	movs r1, 0x6
	bl pokemon_getattr
	cmp r0, 0
	bne _080B5AA4
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _080B5AA4
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B5AA4
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0xC
	mov r3, r8
	bl TryGetRandomWildMonIndexByType
	lsls r0, 24
	lsrs r0, 24
	b _080B5AA6
	.pool
_080B5AA4:
	movs r0, 0
_080B5AA6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end TryGetAbilityInfluencedWildMonIndex

	thumb_func_start affects_encounter_rate_based_on_flags
@ void affects_encounter_rate_based_on_flags(u32 *val)
affects_encounter_rate_based_on_flags: @ 80B5AB0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x000008ad
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B5AD0
	ldr r0, [r4]
	lsrs r1, r0, 1
	adds r0, r1
	b _080B5AE2
	.pool
_080B5AD0:
	ldr r0, =0x000008ae
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B5AE4
	ldr r0, [r4]
	lsrs r0, 1
_080B5AE2:
	str r0, [r4]
_080B5AE4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end affects_encounter_rate_based_on_flags

	thumb_func_start ApplyCleanseTagWildEncounterRateReduction
ApplyCleanseTagWildEncounterRateReduction: @ 80B5AF0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_020244EC
	movs r1, 0xC
	bl pokemon_getattr
	cmp r0, 0xBE
	bne _080B5B0C
	ldr r0, [r4]
	lsls r0, 1
	movs r1, 0x3
	bl __udivsi3
	str r0, [r4]
_080B5B0C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ApplyCleanseTagWildEncounterRateReduction

	.align 2, 0 @ Don't pad with nop.
