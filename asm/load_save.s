	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start CheckForFlashMemory
@ void CheckForFlashMemory()
CheckForFlashMemory: @ 8076B68
	push {lr}
	bl IdentifyFlash
	lsls r0, 16
	cmp r0, 0
	bne _08076B84
	ldr r1, =gUnknown_03005D88
	movs r0, 0x1
	str r0, [r1]
	bl StartFlashMemoryTimer
	b _08076B8A
	.pool
_08076B84:
	ldr r1, =gUnknown_03005D88
	movs r0, 0
	str r0, [r1]
_08076B8A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end CheckForFlashMemory

	thumb_func_start memclr_stdsav2
memclr_stdsav2: @ 8076B94
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02024A54
	ldr r2, =0x010007d6
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end memclr_stdsav2

	thumb_func_start clear_sav1
clear_sav1: @ 8076BB8
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02025A00
	ldr r2, =0x01001f04
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end clear_sav1

	thumb_func_start InitSaveBlockPointersWithRandomOffset
@ void InitSaveBlockPointersWithRandomOffset(u8 offset)
InitSaveBlockPointersWithRandomOffset: @ 8076BDC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r5, =gSaveBlock1Ptr
	bl Random
	adds r4, r0
	movs r0, 0x7C
	ands r4, r0
	ldr r1, =gSaveBlock2Ptr
	ldr r0, =gUnknown_02024A54
	adds r0, r4, r0
	str r0, [r1]
	ldr r0, =gUnknown_02025A00
	adds r0, r4, r0
	str r0, [r5]
	ldr r1, =gUnknown_03005D94
	ldr r0, =gUnknown_02029808
	adds r4, r0
	str r4, [r1]
	bl init_bag_pockets
	bl sub_81617F4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitSaveBlockPointersWithRandomOffset

	thumb_func_start saveblock_randomize_and_relocate
saveblock_randomize_and_relocate: @ 8076C2C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r5, =gUnknown_030022C0
	ldr r0, [r5, 0xC]
	str r0, [sp]
	ldr r1, [r5, 0x10]
	str r1, [sp, 0x4]
	movs r0, 0
	str r0, [r5, 0xC]
	str r0, [r5, 0x10]
	ldr r1, =gUnknown_0203CF5C
	str r0, [r1]
	ldr r4, =0x02000000
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r6, =0x00000f2c
	adds r0, r4, 0
	adds r2, r6, 0
	bl memcpy
	ldr r1, =gSaveBlock1Ptr
	mov r10, r1
	ldr r1, [r1]
	ldr r7, =0x00003d88
	ldr r0, =0x02000f2c
	adds r2, r7, 0
	bl memcpy
	ldr r0, =gUnknown_03005D94
	mov r8, r0
	ldr r1, [r0]
	ldr r0, =0x000083d0
	mov r9, r0
	ldr r0, =0x02004cb4
	mov r2, r9
	bl memcpy
	ldrb r1, [r4, 0xA]
	ldrb r0, [r4, 0xB]
	adds r1, r0
	ldrb r0, [r4, 0xC]
	adds r1, r0
	ldrb r0, [r4, 0xD]
	adds r0, r1
	bl InitSaveBlockPointersWithRandomOffset
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	adds r1, r4, 0
	adds r2, r6, 0
	bl memcpy
	mov r1, r10
	ldr r0, [r1]
	ldr r1, =0x02000f2c
	adds r2, r7, 0
	bl memcpy
	mov r1, r8
	ldr r0, [r1]
	ldr r1, =0x02004cb4
	mov r2, r9
	bl memcpy
	movs r1, 0xE0
	lsls r1, 9
	adds r0, r4, 0
	bl InitHeap
	ldr r0, [sp, 0x4]
	str r0, [r5, 0x10]
	ldr r1, [sp]
	str r1, [r5, 0xC]
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsls r0, 16
	lsrs r0, 16
	adds r4, r0
	adds r0, r4, 0
	bl saveblock_apply_crypto
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	adds r0, 0xAC
	str r4, [r0]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end saveblock_randomize_and_relocate

	thumb_func_start sav2_x1_query_bit1
sav2_x1_query_bit1: @ 8076D24
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x9]
	movs r0, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sav2_x1_query_bit1

	thumb_func_start sav2_x9_clear_bit1
sav2_x9_clear_bit1: @ 8076D34
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0xFE
	ands r0, r1
	strb r0, [r2, 0x9]
	bx lr
	.pool
	thumb_func_end sav2_x9_clear_bit1

	thumb_func_start sub_8076D48
sub_8076D48: @ 8076D48
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	bx lr
	.pool
	thumb_func_end sub_8076D48

	thumb_func_start sub_8076D5C
sub_8076D5C: @ 8076D5C
	push {lr}
	movs r0, 0
	bl sub_8084FAC
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076D5C

	thumb_func_start sav2_gender2_inplace_and_xFE
sav2_gender2_inplace_and_xFE: @ 8076D78
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0xFE
	ands r0, r1
	strb r0, [r2, 0x9]
	bx lr
	.pool
	thumb_func_end sav2_gender2_inplace_and_xFE

	thumb_func_start copy_player_party_to_sav1
@ void copy_player_party_to_sav1()
copy_player_party_to_sav1: @ 8076D8C
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =gUnknown_020244E9
	ldrb r1, [r1]
	movs r2, 0x8D
	lsls r2, 2
	adds r0, r2
	strb r1, [r0]
	movs r4, 0
_08076DA0:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x64
	muls r1, r4
	adds r0, r1
	movs r2, 0x8E
	lsls r2, 2
	adds r0, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	adds r4, 0x1
	cmp r4, 0x5
	ble _08076DA0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_player_party_to_sav1

	thumb_func_start copy_player_party_from_sav1
copy_player_party_from_sav1: @ 8076DD4
	push {r4,r5,lr}
	ldr r1, =gUnknown_020244E9
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r2, 0x8D
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	movs r4, 0
	ldr r5, =gPlayerParty
_08076DEA:
	movs r0, 0x64
	adds r2, r4, 0
	muls r2, r0
	adds r0, r2, r5
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	adds r1, r2
	movs r2, 0x8E
	lsls r2, 2
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	adds r4, 0x1
	cmp r4, 0x5
	ble _08076DEA
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_player_party_from_sav1

	thumb_func_start save_serialize_npcs
save_serialize_npcs: @ 8076E1C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	movs r5, 0xA3
	lsls r5, 4
	mov r8, r5
	ldr r4, =gUnknown_02037350
	movs r3, 0
	movs r2, 0xF
_08076E32:
	mov r6, r12
	ldr r1, [r6]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r4, 0x24
	adds r3, 0x24
	subs r2, 0x1
	cmp r2, 0
	bge _08076E32
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end save_serialize_npcs

	thumb_func_start save_deserialize_npcs
save_deserialize_npcs: @ 8076E64
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	movs r5, 0xA3
	lsls r5, 4
	mov r8, r5
	ldr r4, =gUnknown_02037350
	movs r3, 0
	movs r2, 0xF
_08076E7A:
	mov r6, r12
	ldr r1, [r6]
	adds r1, r3
	adds r0, r4, 0
	add r1, r8
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r4, 0x24
	adds r3, 0x24
	subs r2, 0x1
	cmp r2, 0
	bge _08076E7A
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end save_deserialize_npcs

	thumb_func_start save_serialize_game
save_serialize_game: @ 8076EAC
	push {lr}
	bl copy_player_party_to_sav1
	bl save_serialize_npcs
	pop {r0}
	bx r0
	thumb_func_end save_serialize_game

	thumb_func_start save_deserialize_game
save_deserialize_game: @ 8076EBC
	push {lr}
	bl copy_player_party_from_sav1
	bl save_deserialize_npcs
	pop {r0}
	bx r0
	thumb_func_end save_deserialize_game

	thumb_func_start copy_bags_and_unk_data_from_save_blocks
copy_bags_and_unk_data_from_save_blocks: @ 8076ECC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r2, 0
	ldr r0, =gUnknown_02032180
	mov r12, r0
	ldr r1, =gSaveBlock2Ptr
	mov r10, r1
	ldr r5, =gSaveBlock1Ptr
	movs r3, 0xAC
	lsls r3, 3
	ldr r4, =gUnknown_02031C58
_08076EE8:
	lsls r0, r2, 2
	ldr r1, [r5]
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x1D
	ble _08076EE8
	movs r2, 0
	ldr r0, =gUnknown_02031C58
	ldr r5, =gSaveBlock1Ptr
	movs r3, 0xBB
	lsls r3, 3
	adds r4, r0, 0
	adds r4, 0x78
_08076F08:
	lsls r0, r2, 2
	ldr r1, [r5]
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x1D
	ble _08076F08
	movs r2, 0
	ldr r0, =gUnknown_02031C58
	ldr r5, =gSaveBlock1Ptr
	movs r3, 0xCA
	lsls r3, 3
	adds r4, r0, 0
	adds r4, 0xF0
_08076F28:
	lsls r0, r2, 2
	ldr r1, [r5]
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0xF
	ble _08076F28
	movs r2, 0
	ldr r0, =gUnknown_02031C58
	ldr r5, =gSaveBlock1Ptr
	movs r6, 0x98
	lsls r6, 1
	adds r4, r0, r6
	movs r3, 0xD2
	lsls r3, 3
_08076F4A:
	lsls r0, r2, 2
	ldr r1, [r5]
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x3F
	ble _08076F4A
	movs r2, 0
	ldr r0, =gUnknown_02031C58
	ldr r5, =gSaveBlock1Ptr
	movs r7, 0x8C
	lsls r7, 2
	adds r4, r0, r7
	movs r3, 0xF2
	lsls r3, 3
_08076F6C:
	lsls r0, r2, 2
	ldr r1, [r5]
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x2D
	ble _08076F6C
	ldr r0, =gUnknown_02031C58
	ldr r1, =gSaveBlock1Ptr
	mov r8, r1
	movs r5, 0xBA
	lsls r5, 2
	adds r4, r0, r5
	movs r3, 0
	ldr r6, =0x00002be0
	mov r9, r6
	movs r2, 0xF
_08076F92:
	mov r7, r8
	ldr r1, [r7]
	adds r1, r3
	adds r0, r4, 0
	add r1, r9
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r4, 0x24
	adds r3, 0x24
	subs r2, 0x1
	cmp r2, 0
	bge _08076F92
	mov r1, r10
	ldr r0, [r1]
	adds r0, 0xAC
	ldr r0, [r0]
	mov r5, r12
	str r0, [r5]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_bags_and_unk_data_from_save_blocks

	thumb_func_start copy_bags_and_unk_data_to_save_blocks
copy_bags_and_unk_data_to_save_blocks: @ 8076FE0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r2, 0
	ldr r0, =gSaveBlock2Ptr
	mov r8, r0
	ldr r1, =gUnknown_02032180
	mov r12, r1
	ldr r5, =gSaveBlock1Ptr
	movs r3, 0xAC
	lsls r3, 3
	ldr r4, =gUnknown_02031C58
_08076FFC:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r3
	adds r0, r1
	ldm r4!, {r1}
	str r1, [r0]
	adds r2, 0x1
	cmp r2, 0x1D
	ble _08076FFC
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	movs r4, 0xBB
	lsls r4, 3
	ldr r0, =gUnknown_02031C58
	adds r3, r0, 0
	adds r3, 0x78
_0807701C:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, 0x1
	cmp r2, 0x1D
	ble _0807701C
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	movs r4, 0xCA
	lsls r4, 3
	ldr r0, =gUnknown_02031C58
	adds r3, r0, 0
	adds r3, 0xF0
_0807703C:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, 0x1
	cmp r2, 0xF
	ble _0807703C
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	movs r4, 0xD2
	lsls r4, 3
	ldr r0, =gUnknown_02031C58
	movs r6, 0x98
	lsls r6, 1
	adds r3, r0, r6
_0807705E:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3F
	ble _0807705E
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	movs r4, 0xF2
	lsls r4, 3
	ldr r0, =gUnknown_02031C58
	movs r7, 0x8C
	lsls r7, 2
	adds r3, r0, r7
_08077080:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, 0x1
	cmp r2, 0x2D
	ble _08077080
	ldr r0, =gSaveBlock1Ptr
	mov r9, r0
	ldr r1, =0x00002be0
	mov r10, r1
	ldr r4, =gUnknown_02031C58
	movs r3, 0
	movs r2, 0xF
_080770A0:
	mov r5, r9
	ldr r1, [r5]
	adds r1, r3
	add r1, r10
	movs r6, 0xBA
	lsls r6, 2
	adds r0, r4, r6
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r4, 0x24
	adds r3, 0x24
	subs r2, 0x1
	cmp r2, 0
	bge _080770A0
	mov r7, r8
	ldr r0, [r7]
	adds r0, 0xAC
	ldr r4, [r0]
	mov r2, r12
	ldr r1, [r2]
	str r1, [r0]
	adds r0, r4, 0
	bl encrypt_decrypt_all_item_quantities
	ldr r0, [r7]
	adds r0, 0xAC
	str r4, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_bags_and_unk_data_to_save_blocks

	thumb_func_start apply_u16_xor_crypto
apply_u16_xor_crypto: @ 8077100
	ldr r2, =gSaveBlock2Ptr
	ldr r2, [r2]
	adds r2, 0xAC
	ldr r2, [r2]
	ldrh r3, [r0]
	eors r2, r3
	eors r2, r1
	strh r2, [r0]
	bx lr
	.pool
	thumb_func_end apply_u16_xor_crypto

	thumb_func_start apply_u32_xor_crypto
apply_u32_xor_crypto: @ 8077118
	ldr r2, =gSaveBlock2Ptr
	ldr r3, [r2]
	adds r3, 0xAC
	ldr r2, [r0]
	ldr r3, [r3]
	eors r2, r3
	eors r2, r1
	str r2, [r0]
	bx lr
	.pool
	thumb_func_end apply_u32_xor_crypto

	thumb_func_start saveblock_apply_crypto
saveblock_apply_crypto: @ 8077130
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_8084864
	adds r0, r4, 0
	bl call_encrypt_decrypt_all_item_quantities
	adds r0, r4, 0
	bl sub_8024690
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	adds r1, r4, 0
	bl apply_u32_xor_crypto
	ldr r0, [r5]
	ldr r1, =0x00000494
	adds r0, r1
	adds r1, r4, 0
	bl apply_u16_xor_crypto
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end saveblock_apply_crypto

	.align 2, 0 @ Don't pad with nop.
