	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start zero_pokemon_boxed_data
@ void zero_pokemon_boxed_data(pokemon *mon)
zero_pokemon_boxed_data: @ 8067A74
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	movs r3, 0
_08067A7C:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, 0x4F
	bls _08067A7C
	pop {r0}
	bx r0
	thumb_func_end zero_pokemon_boxed_data

	thumb_func_start zero_pokemon_struct
@ void zero_pokemon_struct(pokemon *mon)
zero_pokemon_struct: @ 8067A8C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl zero_pokemon_boxed_data
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x37
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x38
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x39
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3A
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3B
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3C
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3D
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3E
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3F
	mov r2, sp
	bl pokemon_setattr
	movs r0, 0xFF
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x40
	mov r2, sp
	bl pokemon_setattr
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end zero_pokemon_struct

	thumb_func_start zero_player_party_data
@ void zero_player_party_data()
zero_player_party_data: @ 8067B0C
	push {r4,r5,lr}
	ldr r4, =gUnknown_020244EC
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r4, r0
_08067B16:
	adds r0, r4, 0
	bl zero_pokemon_struct
	adds r4, 0x64
	cmp r4, r5
	ble _08067B16
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end zero_player_party_data

	thumb_func_start zero_enemy_party_data
zero_enemy_party_data: @ 8067B2C
	push {r4,r5,lr}
	ldr r4, =gUnknown_02024744
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r4, r0
_08067B36:
	adds r0, r4, 0
	bl zero_pokemon_struct
	adds r4, 0x64
	cmp r4, r5
	ble _08067B36
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end zero_enemy_party_data

	thumb_func_start create_pokemon_set_level
@ void create_pokemon_set_level(pokemon *mon, s16 species_num, u8 level, u8 forced_iv, char pokemon_id_is_nonrandom, int pokemon_id, u8 trainer_id_mode, int trainer_id)
create_pokemon_set_level: @ 8067B4C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x1C
	mov r8, r0
	adds r6, r1, 0
	ldr r4, [sp, 0x34]
	ldr r7, [sp, 0x38]
	ldr r5, [sp, 0x3C]
	lsls r6, 16
	lsrs r6, 16
	add r0, sp, 0x10
	strb r2, [r0]
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r0, r8
	str r3, [sp, 0x18]
	bl zero_pokemon_struct
	str r4, [sp]
	str r7, [sp, 0x4]
	str r5, [sp, 0x8]
	ldr r0, [sp, 0x40]
	str r0, [sp, 0xC]
	mov r0, r8
	adds r1, r6, 0
	add r2, sp, 0x10
	ldrb r2, [r2]
	ldr r3, [sp, 0x18]
	bl create_pokemon
	mov r0, r8
	movs r1, 0x38
	add r2, sp, 0x10
	bl pokemon_setattr
	movs r0, 0xFF
	str r0, [sp, 0x14]
	add r2, sp, 0x14
	mov r0, r8
	movs r1, 0x40
	bl pokemon_setattr
	mov r0, r8
	bl pokemon_calc_effective_stats
	add sp, 0x1C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end create_pokemon_set_level

	thumb_func_start create_pokemon
@ void create_pokemon(pokemon *mon, s16 species_num, u8 level, u8 forced_iv, char pokemon_id_is_nonrandom, int pokemon_id, u8 trainer_id_mode, int trainer_id)
create_pokemon: @ 8067BBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r7, r0, 0
	ldr r4, [sp, 0x40]
	ldr r0, [sp, 0x48]
	movs r5, 0xE
	add r5, sp
	strh r1, [r5]
	add r6, sp, 0x10
	strb r2, [r6]
	mov r5, sp
	adds r5, 0x11
	strb r3, [r5]
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	adds r0, r7, 0
	bl zero_pokemon_boxed_data
	cmp r4, 0
	beq _08067BF8
	ldr r0, [sp, 0x44]
	str r0, [sp, 0x14]
	b _08067C0C
_08067BF8:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x14]
_08067C0C:
	add r2, sp, 0x14
	adds r0, r7, 0
	movs r1, 0
	bl pokemon_setattr_encrypted
	add r0, sp, 0x18
	mov r9, r0
	add r5, sp, 0xC
	mov r1, r10
	cmp r1, 0x2
	bne _08067C64
	ldr r2, =0xffff0000
	mov r8, r2
	ldr r6, =0x0000ffff
_08067C28:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x18]
	adds r1, r4, 0
	mov r3, r8
	ands r1, r3
	lsrs r1, 16
	ands r4, r6
	eors r1, r4
	ldr r2, [sp, 0x14]
	adds r0, r2, 0
	ands r0, r3
	lsrs r0, 16
	eors r1, r0
	ands r2, r6
	eors r1, r2
	cmp r1, 0x7
	bls _08067C28
	b _08067C8A
	.pool
_08067C64:
	mov r0, r10
	cmp r0, 0x1
	bne _08067C70
	ldr r0, [sp, 0x4C]
	str r0, [sp, 0x18]
	b _08067C8A
_08067C70:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0xA]
	ldrb r0, [r2, 0xB]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0xC]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0xD]
	lsls r0, 24
	orrs r1, r0
	str r1, [sp, 0x18]
_08067C8A:
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r9
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	bl pokemon_calc_checksum
	strh r0, [r5]
	adds r0, r7, 0
	movs r1, 0x9
	adds r2, r5, 0
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	bl pokemon_encrypt
	mov r0, sp
	ldrh r1, [r0, 0xE]
	bl GetSpeciesName
	adds r0, r7, 0
	movs r1, 0x2
	mov r2, sp
	bl pokemon_setattr_encrypted
	ldr r2, =gUnknown_82E9531
	adds r0, r7, 0
	movs r1, 0x3
	bl pokemon_setattr_encrypted
	ldr r5, =gSaveBlock2Ptr
	ldr r2, [r5]
	adds r0, r7, 0
	movs r1, 0x7
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0xB
	mov r2, sp
	adds r2, 0xE
	bl pokemon_setattr_encrypted
	ldr r4, =gBaseStats
	mov r2, sp
	ldrh r1, [r2, 0xE]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	adds r2, r1, 0
	muls r2, r0
	mov r3, sp
	ldrb r0, [r3, 0x10]
	lsls r0, 2
	ldr r1, =gExperienceTables
	adds r0, r1
	adds r2, r0
	adds r0, r7, 0
	movs r1, 0x19
	bl pokemon_setattr_encrypted
	mov r1, sp
	ldrh r0, [r1, 0xE]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r4, 0x12
	adds r2, r4
	adds r0, r7, 0
	movs r1, 0x20
	bl pokemon_setattr_encrypted
	bl sav1_map_get_name
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	adds r0, r7, 0
	movs r1, 0x23
	mov r2, r9
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0x24
	add r2, sp, 0x10
	bl pokemon_setattr_encrypted
	ldr r2, =gUnknown_82E9530
	adds r0, r7, 0
	movs r1, 0x25
	bl pokemon_setattr_encrypted
	movs r0, 0x4
	str r0, [sp, 0x18]
	adds r0, r7, 0
	movs r1, 0x26
	mov r2, r9
	bl pokemon_setattr_encrypted
	ldr r2, [r5]
	adds r2, 0x8
	adds r0, r7, 0
	movs r1, 0x31
	bl pokemon_setattr_encrypted
	mov r2, sp
	ldrb r0, [r2, 0x11]
	cmp r0, 0x1F
	bhi _08067DC8
	adds r0, r7, 0
	movs r1, 0x27
	adds r2, 0x11
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0x28
	mov r2, sp
	adds r2, 0x11
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0x29
	mov r2, sp
	adds r2, 0x11
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0x2A
	mov r2, sp
	adds r2, 0x11
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0x2B
	mov r2, sp
	adds r2, 0x11
	bl pokemon_setattr_encrypted
	adds r0, r7, 0
	movs r1, 0x2C
	mov r2, sp
	adds r2, 0x11
	bl pokemon_setattr_encrypted
	b _08067E50
	.pool
_08067DC8:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
	movs r3, 0x1F
	mov r8, r3
	ands r0, r3
	str r0, [sp, 0x1C]
	add r4, sp, 0x1C
	adds r0, r7, 0
	movs r1, 0x27
	adds r2, r4, 0
	bl pokemon_setattr_encrypted
	ldr r0, [sp, 0x18]
	movs r6, 0xF8
	lsls r6, 2
	ands r0, r6
	lsrs r0, 5
	str r0, [sp, 0x1C]
	adds r0, r7, 0
	movs r1, 0x28
	adds r2, r4, 0
	bl pokemon_setattr_encrypted
	ldr r0, [sp, 0x18]
	movs r5, 0xF8
	lsls r5, 7
	ands r0, r5
	lsrs r0, 10
	str r0, [sp, 0x1C]
	adds r0, r7, 0
	movs r1, 0x29
	adds r2, r4, 0
	bl pokemon_setattr_encrypted
	bl Random
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
	mov r1, r8
	ands r0, r1
	str r0, [sp, 0x1C]
	adds r0, r7, 0
	movs r1, 0x2A
	adds r2, r4, 0
	bl pokemon_setattr_encrypted
	ldr r0, [sp, 0x18]
	ands r0, r6
	lsrs r0, 5
	str r0, [sp, 0x1C]
	adds r0, r7, 0
	movs r1, 0x2B
	adds r2, r4, 0
	bl pokemon_setattr_encrypted
	ldr r0, [sp, 0x18]
	ands r0, r5
	lsrs r0, 10
	str r0, [sp, 0x1C]
	adds r0, r7, 0
	movs r1, 0x2C
	adds r2, r4, 0
	bl pokemon_setattr_encrypted
_08067E50:
	ldr r2, =gBaseStats
	mov r3, sp
	ldrh r1, [r3, 0xE]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x17]
	cmp r0, 0
	beq _08067E76
	ldr r0, [sp, 0x14]
	movs r1, 0x1
	ands r0, r1
	str r0, [sp, 0x18]
	adds r0, r7, 0
	movs r1, 0x2E
	mov r2, r9
	bl pokemon_setattr_encrypted
_08067E76:
	adds r0, r7, 0
	bl sub_8069270
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end create_pokemon

	thumb_func_start pokemon_make_with_nature
pokemon_make_with_nature: @ 8067E90
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r9, r0
	ldr r0, [sp, 0x2C]
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	lsls r0, 24
	lsrs r5, r0, 24
_08067EB0:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	adds r0, r4, 0
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bne _08067EB0
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	mov r0, r9
	mov r1, r8
	adds r2, r7, 0
	adds r3, r6, 0
	bl create_pokemon_set_level
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemon_make_with_nature

	thumb_func_start sub_8067EF8
sub_8067EF8: @ 8067EF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	ldr r4, [sp, 0x38]
	ldr r5, [sp, 0x3C]
	ldr r0, [sp, 0x40]
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	lsls r5, 24
	lsrs r6, r5, 24
	lsls r0, 24
	lsrs r1, r0, 24
	mov r9, r1
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1B
	bhi _08067F9E
_08067F38:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r4
	lsrs r0, 18
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r4
	lsrs r1, 12
	orrs r0, r1
	movs r1, 0xC0
	lsls r1, 2
	ands r1, r4
	lsrs r1, 6
	orrs r0, r1
	movs r1, 0x3
	ands r1, r4
	orrs r0, r1
	movs r1, 0x1C
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _08067F38
	adds r0, r7, 0
	adds r1, r4, 0
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r8, r0
	bne _08067F38
	mov r0, r9
	subs r0, 0x1
	cmp r5, r0
	bne _08067F38
	b _08067FCE
_08067F9E:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	adds r0, r4, 0
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _08067F9E
	adds r0, r7, 0
	adds r1, r4, 0
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r8, r0
	bne _08067F9E
_08067FCE:
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x10]
	adds r1, r7, 0
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl create_pokemon_set_level
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8067EF8

	thumb_func_start sub_8067FF8
sub_8067FF8: @ 8067FF8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 24
	lsrs r7, r2, 24
_0806800A:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r5, r4, 16
	lsls r0, 16
	orrs r5, r0
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl pokemon_species_get_gender_info
	lsls r0, 24
	cmp r0, 0
	bne _0806800A
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	mov r0, r8
	adds r1, r6, 0
	adds r2, r7, 0
	movs r3, 0x20
	bl create_pokemon_set_level
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8067FF8

	thumb_func_start sub_8068060
sub_8068060: @ 8068060
	push {r4,lr}
	sub sp, 0x14
	adds r4, r0, 0
	str r3, [sp, 0x10]
	ldr r3, [sp, 0x1C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	str r3, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r3, 0
	bl create_pokemon_set_level
	adds r0, r4, 0
	movs r1, 0x42
	add r2, sp, 0x10
	bl pokemon_setattr
	adds r0, r4, 0
	bl pokemon_calc_effective_stats
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8068060

	thumb_func_start sub_80680A0
sub_80680A0: @ 80680A0
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r3, 0
	ldr r3, [sp, 0x1C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r3, [sp, 0xC]
	adds r0, r5, 0
	movs r3, 0
	bl create_pokemon_set_level
	adds r0, r5, 0
	movs r1, 0x27
	adds r2, r4, 0
	bl pokemon_setattr
	adds r2, r4, 0x1
	adds r0, r5, 0
	movs r1, 0x28
	bl pokemon_setattr
	adds r2, r4, 0x2
	adds r0, r5, 0
	movs r1, 0x29
	bl pokemon_setattr
	adds r2, r4, 0x3
	adds r0, r5, 0
	movs r1, 0x2A
	bl pokemon_setattr
	adds r2, r4, 0x4
	adds r0, r5, 0
	movs r1, 0x2B
	bl pokemon_setattr
	adds r4, 0x5
	adds r0, r5, 0
	movs r1, 0x2C
	adds r2, r4, 0
	bl pokemon_setattr
	adds r0, r5, 0
	bl pokemon_calc_effective_stats
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80680A0

	thumb_func_start pokemon_make_ev_something
pokemon_make_ev_something: @ 8068114
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r7, r0, 0
	ldr r0, [sp, 0x2C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r6, 0
	str r6, [sp]
	str r6, [sp, 0x4]
	str r6, [sp, 0x8]
	str r6, [sp, 0xC]
	adds r0, r7, 0
	bl create_pokemon_set_level
	mov r4, r8
	movs r1, 0x1
	movs r5, 0x5
_08068148:
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08068152
	adds r6, 0x1
_08068152:
	lsrs r4, 1
	subs r5, 0x1
	cmp r5, 0
	bge _08068148
	movs r0, 0xFF
	lsls r0, 1
	adds r1, r6, 0
	bl __divsi3
	add r1, sp, 0x10
	strh r0, [r1]
	movs r4, 0x1
	movs r5, 0
_0806816C:
	mov r0, r8
	ands r0, r4
	cmp r0, 0
	beq _08068180
	adds r1, r5, 0
	adds r1, 0x1A
	adds r0, r7, 0
	add r2, sp, 0x10
	bl pokemon_setattr
_08068180:
	lsls r0, r4, 25
	lsrs r4, r0, 24
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806816C
	adds r0, r7, 0
	bl pokemon_calc_effective_stats
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemon_make_ev_something

	thumb_func_start sub_806819C
sub_806819C: @ 806819C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x34
	adds r7, r0, 0
	adds r6, r1, 0
	ldrh r1, [r6]
	ldrb r2, [r6, 0xC]
	movs r3, 0x1
	str r3, [sp]
	ldr r0, [r6, 0x1C]
	str r0, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r0, [r6, 0x14]
	str r0, [sp, 0xC]
	adds r0, r7, 0
	movs r3, 0
	bl create_pokemon_set_level
	movs r5, 0
	add r0, sp, 0x30
	mov r9, r0
	movs r1, 0x31
	add r1, sp
	mov r8, r1
	adds r4, r6, 0x4
_080681D2:
	ldrh r1, [r4]
	lsls r2, r5, 24
	lsrs r2, 24
	adds r0, r7, 0
	bl sub_80691F4
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080681D2
	adds r2, r6, 0
	adds r2, 0xD
	adds r0, r7, 0
	movs r1, 0x15
	bl pokemon_setattr
	adds r2, r6, 0x2
	adds r0, r7, 0
	movs r1, 0xC
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0x2B
	adds r0, r7, 0
	movs r1, 0x20
	bl pokemon_setattr
	adds r1, r6, 0
	adds r1, 0x20
	add r0, sp, 0x10
	bl StringCopy
	add r0, sp, 0x10
	ldrb r0, [r0]
	cmp r0, 0xFC
	bne _08068230
	add r0, sp, 0x10
	ldrb r0, [r0, 0x1]
	cmp r0, 0x15
	bne _08068230
	movs r0, 0x1
	mov r1, r9
	strb r0, [r1]
	add r0, sp, 0x10
	bl StripExtCtrlCodes
	b _08068236
_08068230:
	movs r0, 0x2
	mov r1, r9
	strb r0, [r1]
_08068236:
	adds r0, r7, 0
	movs r1, 0x3
	mov r2, r9
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x2
	add r2, sp, 0x10
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0xE
	adds r0, r7, 0
	movs r1, 0x1A
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0xF
	adds r0, r7, 0
	movs r1, 0x1B
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0x10
	adds r0, r7, 0
	movs r1, 0x1C
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0x11
	adds r0, r7, 0
	movs r1, 0x1D
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0x12
	adds r0, r7, 0
	movs r1, 0x1E
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0x13
	adds r0, r7, 0
	movs r1, 0x1F
	bl pokemon_setattr
	ldrb r0, [r6, 0x1B]
	lsrs r0, 7
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2E
	mov r2, r8
	bl pokemon_setattr
	ldrb r0, [r6, 0x18]
	lsls r0, 27
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x27
	mov r2, r8
	bl pokemon_setattr
	ldrh r0, [r6, 0x18]
	lsls r0, 22
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x28
	mov r2, r8
	bl pokemon_setattr
	ldrb r0, [r6, 0x19]
	lsls r0, 25
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x29
	mov r2, r8
	bl pokemon_setattr
	ldr r0, [r6, 0x18]
	lsls r0, 12
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2A
	mov r2, r8
	bl pokemon_setattr
	ldrh r0, [r6, 0x1A]
	lsls r0, 23
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2B
	mov r2, r8
	bl pokemon_setattr
	ldrb r0, [r6, 0x1B]
	lsls r0, 26
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2C
	mov r2, r8
	bl pokemon_setattr
	adds r0, r7, 0
	bl sub_806E924
	adds r0, r7, 0
	bl pokemon_calc_effective_stats
	add sp, 0x34
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806819C

	thumb_func_start sub_8068338
sub_8068338: @ 8068338
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	adds r7, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08068374
	lsls r0, r1, 30
	lsrs r0, 30
	bl sub_8165C90
	lsls r0, 24
	lsrs r3, r0, 24
	b _0806837C
	.pool
_08068374:
	movs r3, 0x32
	cmp r2, 0
	bne _0806837C
	ldrb r3, [r6, 0xC]
_0806837C:
	ldrh r1, [r6]
	movs r2, 0x1
	str r2, [sp]
	ldr r0, [r6, 0x1C]
	str r0, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r0, [r6, 0x14]
	str r0, [sp, 0xC]
	adds r0, r7, 0
	adds r2, r3, 0
	movs r3, 0
	bl create_pokemon_set_level
	movs r5, 0
	movs r0, 0xD
	adds r0, r6
	mov r10, r0
	adds r1, r6, 0x2
	str r1, [sp, 0x38]
	adds r0, r6, 0
	adds r0, 0x2B
	str r0, [sp, 0x34]
	adds r1, 0x1E
	str r1, [sp, 0x54]
	add r0, sp, 0x30
	mov r9, r0
	subs r1, 0x12
	str r1, [sp, 0x3C]
	adds r0, r6, 0
	adds r0, 0xF
	str r0, [sp, 0x40]
	adds r1, 0x2
	str r1, [sp, 0x44]
	adds r0, 0x2
	str r0, [sp, 0x48]
	adds r1, 0x2
	str r1, [sp, 0x4C]
	adds r0, 0x2
	str r0, [sp, 0x50]
	movs r1, 0x31
	add r1, sp
	mov r8, r1
	adds r4, r6, 0x4
_080683D2:
	ldrh r1, [r4]
	lsls r2, r5, 24
	lsrs r2, 24
	adds r0, r7, 0
	bl sub_80691F4
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080683D2
	adds r0, r7, 0
	movs r1, 0x15
	mov r2, r10
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0xC
	ldr r2, [sp, 0x38]
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x20
	ldr r2, [sp, 0x34]
	bl pokemon_setattr
	add r0, sp, 0x10
	ldr r1, [sp, 0x54]
	bl StringCopy
	add r0, sp, 0x10
	ldrb r0, [r0]
	cmp r0, 0xFC
	bne _0806842A
	add r0, sp, 0x10
	ldrb r0, [r0, 0x1]
	cmp r0, 0x15
	bne _0806842A
	movs r0, 0x1
	mov r1, r9
	strb r0, [r1]
	add r0, sp, 0x10
	bl StripExtCtrlCodes
	b _08068430
_0806842A:
	movs r0, 0x2
	mov r1, r9
	strb r0, [r1]
_08068430:
	adds r0, r7, 0
	movs r1, 0x3
	mov r2, r9
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x2
	add r2, sp, 0x10
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x1A
	ldr r2, [sp, 0x3C]
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x1B
	ldr r2, [sp, 0x40]
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x1C
	ldr r2, [sp, 0x44]
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x1D
	ldr r2, [sp, 0x48]
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x1E
	ldr r2, [sp, 0x4C]
	bl pokemon_setattr
	adds r0, r7, 0
	movs r1, 0x1F
	ldr r2, [sp, 0x50]
	bl pokemon_setattr
	ldrb r0, [r6, 0x1B]
	lsrs r0, 7
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2E
	mov r2, r8
	bl pokemon_setattr
	ldrb r0, [r6, 0x18]
	lsls r0, 27
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x27
	mov r2, r8
	bl pokemon_setattr
	ldrh r0, [r6, 0x18]
	lsls r0, 22
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x28
	mov r2, r8
	bl pokemon_setattr
	ldrb r0, [r6, 0x19]
	lsls r0, 25
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x29
	mov r2, r8
	bl pokemon_setattr
	ldr r0, [r6, 0x18]
	lsls r0, 12
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2A
	mov r2, r8
	bl pokemon_setattr
	ldrh r0, [r6, 0x1A]
	lsls r0, 23
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2B
	mov r2, r8
	bl pokemon_setattr
	ldrb r0, [r6, 0x1B]
	lsls r0, 26
	lsrs r0, 27
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x2C
	mov r2, r8
	bl pokemon_setattr
	adds r0, r7, 0
	bl sub_806E924
	adds r0, r7, 0
	bl pokemon_calc_effective_stats
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8068338

	thumb_func_start sub_8068528
sub_8068528: @ 8068528
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r7, r0, 0
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	ldr r6, =gUnknown_08610970
	ldrb r0, [r1]
	lsls r3, r0, 27
	lsrs r1, r3, 27
	movs r5, 0x58
	muls r1, r5
	adds r1, r6
	ldrh r1, [r1, 0x30]
	mov r8, r1
	lsrs r1, r3, 27
	muls r1, r5
	adds r1, r6
	ldrh r4, [r1, 0x30]
	lsrs r4, 8
	lsrs r3, 27
	adds r1, r3, 0
	muls r1, r5
	adds r1, r6
	ldrh r3, [r1, 0x30]
	movs r1, 0xFF
	ands r1, r3
	lsls r1, 8
	lsls r5, r2, 1
	adds r5, r2
	lsls r5, 2
	mov r2, r9
	adds r6, r2, r5
	orrs r4, r1
	ldrh r1, [r6, 0x4]
	adds r4, r1
	ldrb r1, [r2, 0x2]
	adds r4, r1
	lsls r0, 25
	lsrs r0, 30
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	bl sub_8165C90
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldrh r1, [r6, 0x4]
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	adds r0, r7, 0
	movs r3, 0x1F
	bl create_pokemon_set_level
	mov r1, r9
	adds r2, r5, r1
	adds r2, 0xE
	adds r0, r7, 0
	movs r1, 0xC
	bl pokemon_setattr
	movs r4, 0
	movs r2, 0x12
	add r2, sp
	mov r8, r2
	mov r6, r9
	adds r6, 0x6
_080685BE:
	adds r0, r6, r5
	ldrh r1, [r0]
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r7, 0
	bl sub_80691F4
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _080685BE
	movs r1, 0x55
	add r0, sp, 0x10
	strh r1, [r0]
	movs r4, 0
	mov r5, r9
	adds r5, 0x3F
_080685E0:
	adds r1, r4, 0
	adds r1, 0x1A
	adds r0, r7, 0
	add r2, sp, 0x10
	bl pokemon_setattr
	adds r4, 0x1
	cmp r4, 0x5
	ble _080685E0
	ldrb r0, [r5]
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x3
	mov r2, r8
	bl pokemon_setattr
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 27
	lsrs r0, 27
	mov r2, r8
	ldrb r1, [r2]
	bl sub_81A1650
	adds r2, r0, 0
	adds r0, r7, 0
	movs r1, 0x7
	bl pokemon_setattr
	adds r0, r7, 0
	bl pokemon_calc_effective_stats
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8068528

	thumb_func_start sub_8068634
sub_8068634: @ 8068634
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r7, r0, 0
	ldr r0, [sp, 0x38]
	ldr r4, [sp, 0x3C]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x14]
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	movs r6, 0
_08068664:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	adds r0, r4, 0
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bne _08068664
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x40]
	str r0, [sp, 0xC]
	adds r0, r7, 0
	ldr r1, [sp, 0x14]
	mov r2, r10
	mov r3, r9
	bl create_pokemon_set_level
	mov r5, r8
	movs r1, 0x1
	movs r4, 0x5
_080686A2:
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080686AC
	adds r6, 0x1
_080686AC:
	lsrs r5, 1
	subs r4, 0x1
	cmp r4, 0
	bge _080686A2
	movs r0, 0xFF
	lsls r0, 1
	adds r1, r6, 0
	bl __divsi3
	add r1, sp, 0x10
	strh r0, [r1]
	movs r5, 0x1
	movs r4, 0
_080686C6:
	mov r0, r8
	ands r0, r5
	cmp r0, 0
	beq _080686DA
	adds r1, r4, 0
	adds r1, 0x1A
	adds r0, r7, 0
	add r2, sp, 0x10
	bl pokemon_setattr
_080686DA:
	lsls r0, r5, 25
	lsrs r5, r0, 24
	adds r4, 0x1
	cmp r4, 0x5
	ble _080686C6
	adds r0, r7, 0
	bl pokemon_calc_effective_stats
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8068634

	thumb_func_start sub_80686FC
sub_80686FC: @ 80686FC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r6, r1, 0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr
	strh r0, [r6]
	adds r0, r7, 0
	movs r1, 0xC
	movs r2, 0
	bl pokemon_getattr
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _08068726
	movs r0, 0
_08068726:
	strh r0, [r6, 0x2]
	movs r5, 0
	movs r0, 0x2B
	adds r0, r6
	mov r8, r0
	movs r1, 0x20
	adds r1, r6
	mov r9, r1
	adds r4, r6, 0x4
_08068738:
	adds r1, r5, 0
	adds r1, 0xD
	adds r0, r7, 0
	movs r2, 0
	bl pokemon_getattr
	strh r0, [r4]
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _08068738
	adds r0, r7, 0
	movs r1, 0x38
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0xC]
	adds r0, r7, 0
	movs r1, 0x15
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0xD]
	adds r0, r7, 0
	movs r1, 0x1
	movs r2, 0
	bl pokemon_getattr
	str r0, [r6, 0x14]
	adds r0, r7, 0
	movs r1, 0x1A
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0xE]
	adds r0, r7, 0
	movs r1, 0x1B
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0xF]
	adds r0, r7, 0
	movs r1, 0x1C
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0x10]
	adds r0, r7, 0
	movs r1, 0x1D
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0x11]
	adds r0, r7, 0
	movs r1, 0x1E
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0x12]
	adds r0, r7, 0
	movs r1, 0x1F
	movs r2, 0
	bl pokemon_getattr
	strb r0, [r6, 0x13]
	adds r0, r7, 0
	movs r1, 0x20
	movs r2, 0
	bl pokemon_getattr
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x27
	movs r2, 0
	bl pokemon_getattr
	movs r4, 0x1F
	ands r0, r4
	ldrb r2, [r6, 0x18]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x18]
	adds r0, r7, 0
	movs r1, 0x28
	movs r2, 0
	bl pokemon_getattr
	movs r5, 0x1F
	ands r0, r5
	lsls r0, 5
	ldrh r2, [r6, 0x18]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r6, 0x18]
	adds r0, r7, 0
	movs r1, 0x29
	movs r2, 0
	bl pokemon_getattr
	ands r0, r4
	lsls r0, 2
	ldrb r2, [r6, 0x19]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x19]
	adds r0, r7, 0
	movs r1, 0x2A
	movs r2, 0
	bl pokemon_getattr
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [r6, 0x18]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [r6, 0x18]
	adds r0, r7, 0
	movs r1, 0x2B
	movs r2, 0
	bl pokemon_getattr
	ands r0, r5
	lsls r0, 4
	ldrh r2, [r6, 0x1A]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r6, 0x1A]
	adds r0, r7, 0
	movs r1, 0x2C
	movs r2, 0
	bl pokemon_getattr
	ands r0, r4
	lsls r0, 1
	ldrb r2, [r6, 0x1B]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x1B]
	adds r0, r7, 0
	movs r1, 0x2E
	movs r2, 0
	bl pokemon_getattr
	lsls r0, 7
	ldrb r2, [r6, 0x1B]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x1B]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	bl pokemon_getattr
	str r0, [r6, 0x1C]
	adds r0, r7, 0
	movs r1, 0x2
	mov r2, r9
	bl pokemon_getattr
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80686FC

	thumb_func_start sub_80688A8
sub_80688A8: @ 80688A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	mov r8, r0
	ldr r4, [sp, 0x2C]
	ldr r6, [sp, 0x30]
	ldr r5, [sp, 0x34]
	ldr r7, [sp, 0x38]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r4, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	str r7, [sp, 0xC]
	mov r0, r8
	bl create_pokemon_set_level
	mov r0, r8
	movs r1, 0x50
	add r2, sp, 0x10
	bl pokemon_setattr
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80688A8

	thumb_func_start sub_80688F8
sub_80688F8: @ 80688F8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r0, 0x5
	bhi _080689CE
	lsls r0, 2
	ldr r1, =_08068914
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08068914:
	.4byte _080689CE
	.4byte _0806892C
	.4byte _08068A00
	.4byte _08068958
	.4byte _08068A00
	.4byte _08068990
_0806892C:
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080689CE
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080689CE
	b _080689B6
	.pool
_08068958:
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080689CE
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080689CE
	cmp r5, 0x1
	beq _08068A00
	cmp r5, 0x4
	beq _08068A00
	cmp r5, 0x5
	beq _08068A00
	b _080689CE
	.pool
_08068990:
	ldr r0, =gUnknown_02022FEC
	ldr r2, [r0]
	movs r3, 0x2
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _080689E4
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080689CE
	movs r0, 0x40
	ands r2, r0
	cmp r2, 0
	beq _080689F4
_080689B6:
	ldr r4, =gUnknown_020229E8
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x18]
	cmp r0, r5
	bne _08068A00
_080689CE:
	movs r0, 0
	b _08068A02
	.pool
_080689E4:
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080689CE
_080689F4:
	adds r0, r5, 0
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	beq _080689CE
_08068A00:
	movs r0, 0x1
_08068A02:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80688F8

	thumb_func_start get_pokemon_data_3
get_pokemon_data_3: @ 8068A10
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08068A34
	adds r0, r5, 0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr
	movs r1, 0xCD
	lsls r1, 1
	cmp r0, r1
	beq _08068A3C
_08068A34:
	movs r0, 0
	b _08068A9A
	.pool
_08068A3C:
	adds r1, r6, 0
	adds r1, 0x27
	adds r0, r5, 0
	movs r2, 0
	bl pokemon_getattr
	adds r4, r0, 0
	adds r1, r6, 0
	adds r1, 0x1A
	adds r0, r5, 0
	movs r2, 0
	bl pokemon_getattr
	ldr r2, =gUnknown_08329D48
	lsls r1, r6, 1
	adds r1, r2
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, r4
	cmp r0, 0
	bge _08068A68
	adds r0, 0x3
_08068A68:
	asrs r0, 2
	adds r0, r1, r0
	adds r1, r5, 0
	adds r1, 0x54
	ldrb r1, [r1]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, 0x5
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r6, 24
	lsrs r2, 24
	adds r1, r4, 0
	bl nature_stat_mod
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
_08068A9A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end get_pokemon_data_3

	thumb_func_start sub_8068AA4
sub_8068AA4: @ 8068AA4
	push {r4,r5,lr}
	sub sp, 0x4
	movs r5, 0
_08068AAA:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gUnknown_020244EC
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr
	movs r1, 0xCD
	lsls r1, 1
	cmp r0, r1
	bne _08068B34
	adds r0, r4, 0
	movs r1, 0x3B
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x3B
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3C
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x3C
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3D
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x3D
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3E
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x3E
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3F
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x3F
	mov r2, sp
	bl pokemon_setattr
_08068B34:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08068AAA
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8068AA4

	thumb_func_start sub_8068B48
sub_8068B48: @ 8068B48
	push {lr}
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _08068B6C
	ldr r0, =gUnknown_0203C7B4
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
	b _08068B78
	.pool
_08068B6C:
	bl link_get_multiplayer_id
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
_08068B78:
	ldr r3, =gUnknown_020229E8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r0, r3, 0x4
	adds r0, r1, r0
	ldr r2, [r0]
	movs r0, 0x7
	ands r2, r0
	adds r1, r3
	ldrb r0, [r1, 0x13]
	lsls r0, 3
	orrs r2, r0
	ldr r0, =gUnknown_08329D54
	lsls r2, 1
	adds r2, r0
	ldrh r0, [r2]
	bl TrainerClassToTrainerPic
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8068B48

	thumb_func_start sub_8068BB0
sub_8068BB0: @ 8068BB0
	push {lr}
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _08068BD4
	ldr r0, =gUnknown_0203C7B4
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
	b _08068BE0
	.pool
_08068BD4:
	bl link_get_multiplayer_id
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
_08068BE0:
	ldr r3, =gUnknown_020229E8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r0, r3, 0x4
	adds r0, r1, r0
	ldr r2, [r0]
	movs r0, 0x7
	ands r2, r0
	adds r1, r3
	ldrb r0, [r1, 0x13]
	lsls r0, 3
	orrs r2, r0
	ldr r1, =gTrainerClassNameIndices
	ldr r0, =gUnknown_08329D54
	lsls r2, 1
	adds r2, r0
	ldrh r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8068BB0

	thumb_func_start DoScriptedWildBattle
DoScriptedWildBattle: @ 8068C18
	push {r4-r7,lr}
	sub sp, 0x14
	ldr r0, =gUnknown_020375E0
	ldrh r5, [r0]
	ldr r0, =gUnknown_020375E2
	ldrh r4, [r0]
	ldr r0, =gUnknown_020375E4
	ldrh r6, [r0]
	bl zero_enemy_party_data
	ldr r7, =gUnknown_02024744
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x20
	bl sub_80688A8
	cmp r6, 0
	beq _08068C60
	add r0, sp, 0x10
	strb r6, [r0]
	adds r1, r0, 0
	asrs r0, r6, 8
	strb r0, [r1, 0x1]
	adds r0, r7, 0
	movs r1, 0xC
	add r2, sp, 0x10
	bl pokemon_setattr
_08068C60:
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoScriptedWildBattle

	thumb_func_start pokemon_calc_checksum
@ int pokemon_calc_checksum(pokemon *mon)
pokemon_calc_checksum: @ 8068C78
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	movs r6, 0
	ldr r1, [r4]
	movs r2, 0
	bl pokemon_data_permutator
	adds r5, r0, 0
	ldr r1, [r4]
	adds r0, r4, 0
	movs r2, 0x1
	bl pokemon_data_permutator
	adds r7, r0, 0
	ldr r1, [r4]
	adds r0, r4, 0
	movs r2, 0x2
	bl pokemon_data_permutator
	mov r8, r0
	ldr r1, [r4]
	adds r0, r4, 0
	movs r2, 0x3
	bl pokemon_data_permutator
	adds r3, r0, 0
	movs r1, 0x5
_08068CB2:
	ldrh r0, [r5]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r5, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08068CB2
	adds r2, r7, 0
	movs r1, 0x5
_08068CC6:
	ldrh r0, [r2]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08068CC6
	mov r2, r8
	movs r1, 0x5
_08068CDA:
	ldrh r0, [r2]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08068CDA
	adds r2, r3, 0
	movs r1, 0x5
_08068CEE:
	ldrh r0, [r2]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08068CEE
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end pokemon_calc_checksum

	thumb_func_start pokemon_calc_effective_stats
pokemon_calc_effective_stats: @ 8068D0C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r5, r0, 0
	movs r1, 0x3A
	movs r2, 0
	bl pokemon_getattr
	mov r8, r0
	adds r0, r5, 0
	movs r1, 0x39
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x1C]
	adds r0, r5, 0
	movs r1, 0x27
	movs r2, 0
	bl pokemon_getattr
	adds r6, r0, 0
	adds r0, r5, 0
	movs r1, 0x1A
	movs r2, 0
	bl pokemon_getattr
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x28
	movs r2, 0
	bl pokemon_getattr
	mov r10, r0
	adds r0, r5, 0
	movs r1, 0x1B
	movs r2, 0
	bl pokemon_getattr
	mov r9, r0
	adds r0, r5, 0
	movs r1, 0x29
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x20]
	adds r0, r5, 0
	movs r1, 0x1C
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x24]
	adds r0, r5, 0
	movs r1, 0x2A
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x28]
	adds r0, r5, 0
	movs r1, 0x1D
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x2C]
	adds r0, r5, 0
	movs r1, 0x2B
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x30]
	adds r0, r5, 0
	movs r1, 0x1E
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x34]
	adds r0, r5, 0
	movs r1, 0x2C
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x38]
	adds r0, r5, 0
	movs r1, 0x1F
	movs r2, 0
	bl pokemon_getattr
	str r0, [sp, 0x3C]
	adds r0, r5, 0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r5, 0
	bl level_by_exp
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x38
	mov r2, sp
	bl pokemon_setattr
	ldr r0, =0x0000012f
	cmp r7, r0
	bne _08068DF8
	movs r0, 0x1
	str r0, [sp, 0x4]
	lsls r6, r7, 3
	b _08068E26
	.pool
_08068DF8:
	ldr r1, =gBaseStats
	lsls r2, r7, 3
	subs r0, r2, r7
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, r0, r6
	adds r0, r4, 0
	adds r6, r2, 0
	cmp r0, 0
	bge _08068E12
	adds r0, 0x3
_08068E12:
	asrs r0, 2
	adds r0, r1, r0
	ldr r4, [sp]
	muls r0, r4
	movs r1, 0x64
	bl __divsi3
	adds r0, r4
	adds r0, 0xA
	str r0, [sp, 0x4]
_08068E26:
	ldr r1, =gUnknown_02024474
	add r2, sp, 0x4
	ldrb r0, [r2]
	mov r3, r8
	subs r0, r3
	adds r1, 0x23
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _08068E3E
	movs r0, 0x1
	strb r0, [r1]
_08068E3E:
	adds r0, r5, 0
	movs r1, 0x3A
	bl pokemon_setattr
	ldr r0, =gBaseStats
	subs r1, r6, r7
	lsls r1, 2
	adds r6, r1, r0
	ldrb r0, [r6, 0x1]
	lsls r0, 1
	mov r2, r10
	adds r1, r0, r2
	mov r0, r9
	cmp r0, 0
	bge _08068E5E
	adds r0, 0x3
_08068E5E:
	asrs r0, 2
	adds r0, r1, r0
	ldr r1, [sp]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, 0x5
	str r0, [sp, 0x8]
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0x8
	ldrh r1, [r4]
	movs r2, 0x1
	bl nature_stat_mod
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3B
	adds r2, r4, 0
	bl pokemon_setattr
	ldrb r0, [r6, 0x2]
	lsls r0, 1
	ldr r3, [sp, 0x20]
	adds r1, r0, r3
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bge _08068EA4
	adds r0, 0x3
_08068EA4:
	asrs r0, 2
	adds r0, r1, r0
	ldr r1, [sp]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, 0x5
	str r0, [sp, 0xC]
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0xC
	ldrh r1, [r4]
	movs r2, 0x2
	bl nature_stat_mod
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r1, 0x3C
	adds r2, r4, 0
	bl pokemon_setattr
	ldrb r0, [r6, 0x3]
	lsls r0, 1
	ldr r2, [sp, 0x28]
	adds r1, r0, r2
	ldr r0, [sp, 0x2C]
	cmp r0, 0
	bge _08068EEA
	adds r0, 0x3
_08068EEA:
	asrs r0, 2
	adds r0, r1, r0
	ldr r1, [sp]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, 0x5
	str r0, [sp, 0x10]
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0x10
	ldrh r1, [r4]
	movs r2, 0x3
	bl nature_stat_mod
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x3D
	adds r2, r4, 0
	bl pokemon_setattr
	ldrb r0, [r6, 0x4]
	lsls r0, 1
	ldr r3, [sp, 0x30]
	adds r1, r0, r3
	ldr r0, [sp, 0x34]
	cmp r0, 0
	bge _08068F30
	adds r0, 0x3
_08068F30:
	asrs r0, 2
	adds r0, r1, r0
	ldr r1, [sp]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, 0x5
	str r0, [sp, 0x14]
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0x14
	ldrh r1, [r4]
	movs r2, 0x4
	bl nature_stat_mod
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x14]
	adds r0, r5, 0
	movs r1, 0x3E
	adds r2, r4, 0
	bl pokemon_setattr
	ldrb r0, [r6, 0x5]
	lsls r0, 1
	ldr r2, [sp, 0x38]
	adds r1, r0, r2
	ldr r0, [sp, 0x3C]
	cmp r0, 0
	bge _08068F76
	adds r0, 0x3
_08068F76:
	asrs r0, 2
	adds r0, r1, r0
	ldr r1, [sp]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, 0x5
	str r0, [sp, 0x18]
	adds r0, r5, 0
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0x18
	ldrh r1, [r4]
	movs r2, 0x5
	bl nature_stat_mod
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
	adds r0, r5, 0
	movs r1, 0x3F
	adds r2, r4, 0
	bl pokemon_setattr
	ldr r0, =0x0000012f
	cmp r7, r0
	bne _08068FD0
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _08068FBE
	mov r3, r8
	cmp r3, 0
	bne _08068FF4
_08068FBE:
	movs r0, 0x1
	b _08068FE8
	.pool
_08068FD0:
	ldr r1, [sp, 0x1C]
	cmp r1, 0
	bne _08068FE0
	mov r0, r8
	cmp r0, 0
	bne _08068FF4
	ldr r0, [sp, 0x4]
	b _08068FE8
_08068FE0:
	ldr r0, [sp, 0x4]
	mov r2, r8
	subs r0, r2
	adds r0, r1, r0
_08068FE8:
	str r0, [sp, 0x1C]
	add r2, sp, 0x1C
	adds r0, r5, 0
	movs r1, 0x39
	bl pokemon_setattr
_08068FF4:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemon_calc_effective_stats

	thumb_func_start sub_8069004
sub_8069004: @ 8069004
	push {r4,lr}
	sub sp, 0x4
	adds r2, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r2, 0
	movs r2, 0x50
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x37
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x39
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3A
	mov r2, sp
	bl pokemon_setattr
	movs r0, 0xFF
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x40
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	bl pokemon_calc_effective_stats
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8069004

	thumb_func_start level_by_exp
level_by_exp: @ 8069054
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x19
	movs r2, 0
	bl pokemon_getattr
	adds r3, r0, 0
	movs r2, 0x1
	ldr r6, =gExperienceTables
	ldr r1, =gBaseStats
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x13]
	movs r5, 0xCA
	lsls r5, 1
	muls r0, r5
	adds r0, 0x4
	adds r0, r6
	ldr r0, [r0]
	cmp r0, r3
	bhi _080690AA
	adds r4, r1, 0
_08069094:
	adds r2, 0x1
	cmp r2, 0x64
	bgt _080690AA
	lsls r1, r2, 2
	ldrb r0, [r4, 0x13]
	muls r0, r5
	adds r1, r0
	adds r1, r6
	ldr r0, [r1]
	cmp r0, r3
	bls _08069094
_080690AA:
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end level_by_exp

	thumb_func_start sub_80690C0
sub_80690C0: @ 80690C0
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr_encrypted
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x19
	movs r2, 0
	bl pokemon_getattr_encrypted
	adds r3, r0, 0
	movs r2, 0x1
	ldr r6, =gExperienceTables
	ldr r1, =gBaseStats
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x13]
	movs r5, 0xCA
	lsls r5, 1
	muls r0, r5
	adds r0, 0x4
	adds r0, r6
	ldr r0, [r0]
	cmp r0, r3
	bhi _08069116
	adds r4, r1, 0
_08069100:
	adds r2, 0x1
	cmp r2, 0x64
	bgt _08069116
	lsls r1, r2, 2
	ldrb r0, [r4, 0x13]
	muls r0, r5
	adds r1, r0
	adds r1, r6
	ldr r0, [r1]
	cmp r0, r3
	bls _08069100
_08069116:
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80690C0

	thumb_func_start pokemon_moveset_pad_
pokemon_moveset_pad_: @ 806912C
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl pokemon_moveset_pad
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end pokemon_moveset_pad_

	thumb_func_start pokemon_moveset_pad
pokemon_moveset_pad: @ 8069140
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	mov r0, sp
	strh r1, [r0]
	movs r5, 0
	mov r6, sp
_0806914E:
	adds r4, r5, 0
	adds r4, 0xD
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	bl pokemon_getattr_encrypted
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _0806918C
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, sp
	bl pokemon_setattr_encrypted
	adds r1, r5, 0
	adds r1, 0x11
	ldrh r0, [r6]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	ldr r0, =gBattleMoves + 0x4 @ PP offset
	adds r2, r0
	adds r0, r7, 0
	bl pokemon_setattr_encrypted
	ldrh r0, [r6]
	b _080691A4
	.pool
_0806918C:
	ldrh r1, [r6]
	cmp r0, r1
	bne _0806919C
	ldr r0, =0x0000fffe
	b _080691A4
	.pool
_0806919C:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806914E
	ldr r0, =0x0000ffff
_080691A4:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pokemon_moveset_pad

	thumb_func_start sub_80691B0
sub_80691B0: @ 80691B0
	push {r4,r5,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	movs r3, 0
	adds r5, r0, 0
	adds r5, 0x24
	ldr r2, =gBattleMoves
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	adds r2, r1, r2
	adds r1, r0, 0
	adds r1, 0xC
_080691CA:
	ldrh r0, [r1]
	cmp r0, 0
	bne _080691E0
	strh r4, [r1]
	adds r1, r5, r3
	ldrb r0, [r2, 0x4]
	strb r0, [r1]
	adds r0, r4, 0
	b _080691EA
	.pool
_080691E0:
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _080691CA
	ldr r0, =0x0000ffff
_080691EA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80691B0

	thumb_func_start sub_80691F4
sub_80691F4: @ 80691F4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r2, 0
	mov r0, sp
	strh r1, [r0]
	lsls r4, 24
	lsrs r4, 24
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r5, 0
	mov r2, sp
	bl pokemon_setattr
	adds r4, 0x11
	mov r0, sp
	ldrh r0, [r0]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	ldr r0, =gBattleMoves + 0x4 @ PP offset
	adds r2, r0
	adds r0, r5, 0
	adds r1, r4, 0
	bl pokemon_setattr
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80691F4

	thumb_func_start sub_8069234
sub_8069234: @ 8069234
	push {r4,lr}
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r4, r2, 1
	adds r3, r0, 0
	adds r3, 0xC
	adds r3, r4
	strh r1, [r3]
	adds r0, 0x24
	adds r0, r2
	ldr r3, =gBattleMoves
	lsls r2, r1, 1
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrb r1, [r2, 0x4]
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8069234

	thumb_func_start sub_8069264
sub_8069264: @ 8069264
	push {lr}
	bl sub_8069270
	pop {r0}
	bx r0
	thumb_func_end sub_8069264

	thumb_func_start sub_8069270
sub_8069270: @ 8069270
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr_encrypted
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	bl sub_80690C0
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, =gLevelUpLearnsetPointers
	lsls r6, r4, 2
	adds r0, r6, r0
	ldr r0, [r0]
	ldrh r1, [r0]
	ldr r2, =0xffff0000
	lsrs r0, r2, 16
	cmp r1, r0
	beq _080692FC
	mov r9, r2
	movs r3, 0
_080692AE:
	ldr r0, =gLevelUpLearnsetPointers
	adds r7, r6, r0
	ldr r0, [r7]
	adds r0, r3, r0
	ldrh r2, [r0]
	movs r1, 0xFE
	lsls r1, 8
	adds r0, r1, 0
	ands r0, r2
	mov r4, r10
	lsls r1, r4, 9
	cmp r0, r1
	bgt _080692FC
	ldr r1, =0x000001ff
	adds r0, r1, 0
	adds r4, r0, 0
	ands r4, r2
	mov r0, r8
	adds r1, r4, 0
	str r3, [sp]
	bl pokemon_moveset_pad
	lsls r0, 16
	mov r1, r9
	lsrs r5, r1, 16
	ldr r3, [sp]
	cmp r0, r9
	bne _080692F0
	mov r0, r8
	adds r1, r4, 0
	bl sub_80694D0
	ldr r3, [sp]
_080692F0:
	adds r3, 0x2
	ldr r0, [r7]
	adds r0, r3, r0
	ldrh r0, [r0]
	cmp r0, r5
	bne _080692AE
_080692FC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8069270

	thumb_func_start sub_8069318
sub_8069318: @ 8069318
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	lsls r4, r1, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp]
	mov r0, r8
	movs r1, 0xB
	movs r2, 0
	bl pokemon_getattr
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	mov r0, r8
	movs r1, 0x38
	movs r2, 0
	bl pokemon_getattr
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r4, 0
	beq _080693B0
	ldr r4, =gUnknown_020244E8
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r4]
	ldr r2, =gLevelUpLearnsetPointers
	mov r5, r9
	lsls r3, r5, 2
	adds r5, r3, r2
	ldr r0, [r5]
	ldrh r1, [r0]
	movs r7, 0xFE
	lsls r7, 8
	adds r0, r7, 0
	ands r0, r1
	adds r6, r4, 0
	mov r12, r2
	mov r1, r10
	lsls r4, r1, 9
	cmp r0, r4
	beq _080693D8
	adds r2, r6, 0
	ldr r0, =0x0000ffff
	mov r12, r0
	adds r6, r7, 0
	adds r3, r5, 0
_08069384:
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldrb r0, [r2]
	ldr r1, [r3]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	cmp r1, r12
	bne _080693A8
	movs r0, 0
	b _08069404
	.pool
_080693A8:
	adds r0, r6, 0
	ands r0, r1
	cmp r0, r4
	bne _08069384
_080693B0:
	ldr r3, =gLevelUpLearnsetPointers
	mov r1, r9
	lsls r4, r1, 2
	adds r1, r4, r3
	ldr r2, =gUnknown_020244E8
	ldrb r0, [r2]
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	mov r5, r10
	lsls r1, r5, 9
	adds r6, r2, 0
	mov r12, r3
	adds r3, r4, 0
	cmp r0, r1
	bne _08069402
_080693D8:
	ldr r2, =gUnknown_020244E2
	mov r0, r12
	adds r1, r3, r0
	ldrb r0, [r6]
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x000001ff
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	ldrh r1, [r2]
	mov r0, r8
	bl pokemon_moveset_pad_
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
_08069402:
	ldr r0, [sp]
_08069404:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8069318

	thumb_func_start sub_8069424
sub_8069424: @ 8069424
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	movs r4, 0
	add r7, sp, 0x8
	add r0, sp, 0xC
	mov r9, r0
	mov r5, sp
_08069440:
	adds r1, r4, 0
	adds r1, 0xE
	adds r0, r6, 0
	movs r2, 0
	bl pokemon_getattr
	strh r0, [r5]
	adds r1, r4, 0
	adds r1, 0x12
	adds r0, r6, 0
	movs r2, 0
	bl pokemon_getattr
	adds r1, r7, r4
	strb r0, [r1]
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _08069440
	adds r0, r6, 0
	movs r1, 0x15
	movs r2, 0
	bl pokemon_getattr
	mov r1, r9
	strb r0, [r1]
	ldrb r0, [r1]
	lsrs r0, 2
	strb r0, [r1]
	mov r0, sp
	mov r2, r8
	strh r2, [r0, 0x6]
	ldr r1, =gBattleMoves
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x4]
	strb r0, [r7, 0x3]
	movs r4, 0
	mov r5, sp
_08069494:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r6, 0
	adds r2, r5, 0
	bl pokemon_setattr
	adds r1, r4, 0
	adds r1, 0x11
	adds r2, r7, r4
	adds r0, r6, 0
	bl pokemon_setattr
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _08069494
	adds r0, r6, 0
	movs r1, 0x15
	mov r2, r9
	bl pokemon_setattr
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8069424

	thumb_func_start sub_80694D0
sub_80694D0: @ 80694D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	movs r4, 0
	add r7, sp, 0x8
	add r0, sp, 0xC
	mov r9, r0
	mov r5, sp
_080694EC:
	adds r1, r4, 0
	adds r1, 0xE
	adds r0, r6, 0
	movs r2, 0
	bl pokemon_getattr_encrypted
	strh r0, [r5]
	adds r1, r4, 0
	adds r1, 0x12
	adds r0, r6, 0
	movs r2, 0
	bl pokemon_getattr_encrypted
	adds r1, r7, r4
	strb r0, [r1]
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _080694EC
	adds r0, r6, 0
	movs r1, 0x15
	movs r2, 0
	bl pokemon_getattr_encrypted
	mov r1, r9
	strb r0, [r1]
	ldrb r0, [r1]
	lsrs r0, 2
	strb r0, [r1]
	mov r0, sp
	mov r2, r8
	strh r2, [r0, 0x6]
	ldr r1, =gBattleMoves
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x4]
	strb r0, [r7, 0x3]
	movs r4, 0
	mov r5, sp
_08069540:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r6, 0
	adds r2, r5, 0
	bl pokemon_setattr_encrypted
	adds r1, r4, 0
	adds r1, 0x11
	adds r2, r7, r4
	adds r0, r6, 0
	bl pokemon_setattr_encrypted
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _08069540
	adds r0, r6, 0
	movs r1, 0x15
	mov r2, r9
	bl pokemon_setattr_encrypted
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80694D0

	.align 2, 0 @ Don't pad with nop.
