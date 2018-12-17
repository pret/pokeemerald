	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81B8C68
sub_81B8C68: @ 81B8C68
	push {r4,lr}
	ldr r4, =gUnknown_0203CF00
	bl sub_806D7EC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_81B8C88
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8C68

	thumb_func_start sub_81B8C88
sub_81B8C88: @ 81B8C88
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081B8CBE
	cmp r4, 0
	beq _081B8CB0
	movs r0, 0x30
	strb r0, [r6]
	movs r0, 0x45
	strb r0, [r6, 0x1]
	movs r0, 0x12
	strb r0, [r6, 0x2]
	b _081B8D58
_081B8CB0:
	movs r0, 0x3
	strb r0, [r6]
	movs r0, 0x12
	strb r0, [r6, 0x1]
	movs r0, 0x45
	strb r0, [r6, 0x2]
	b _081B8D58
_081B8CBE:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _081B8CFC
	movs r5, 0x1
	movs r0, 0
	bl GetBattlerAtPosition
	mov r2, sp
	ldr r1, =gBattlerPartyIndexes
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, 0
	mov r1, sp
_081B8CE2:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8CF0
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, 0x1
_081B8CF0:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8CE2
	b _081B8D40
	.pool
_081B8CFC:
	movs r5, 0x2
	movs r0, 0
	bl GetBattlerAtPosition
	mov r1, sp
	ldr r4, =gBattlerPartyIndexes
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r0, [r0]
	strb r0, [r1]
	movs r0, 0x2
	bl GetBattlerAtPosition
	mov r1, sp
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r0, [r0]
	strb r0, [r1, 0x1]
	movs r4, 0
_081B8D26:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8D3A
	ldrb r0, [r1, 0x1]
	cmp r4, r0
	beq _081B8D3A
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, 0x1
_081B8D3A:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8D26
_081B8D40:
	movs r4, 0
	mov r3, sp
_081B8D44:
	adds r0, r6, r4
	ldrb r1, [r3]
	lsls r1, 4
	ldrb r2, [r3, 0x1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _081B8D44
_081B8D58:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8C88

	thumb_func_start sub_81B8D64
sub_81B8D64: @ 81B8D64
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gBattleStruct
	lsls r3, r2, 1
	adds r3, r2
	adds r3, 0x60
	ldr r0, [r0]
	adds r0, r3
	bl sub_81B8D88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8D64

	thumb_func_start sub_81B8D88
sub_81B8D88: @ 81B8D88
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r0, r2, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r0, 24
	lsrs r0, 24
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _081B8DB0
	movs r0, 0
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	b _081B8DBC
_081B8DB0:
	movs r0, 0x1
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x3
_081B8DBC:
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081B8DF0
	cmp r7, 0
	beq _081B8DE2
	movs r0, 0x30
	strb r0, [r5]
	movs r0, 0x45
	strb r0, [r5, 0x1]
	movs r0, 0x12
	strb r0, [r5, 0x2]
	b _081B8E72
_081B8DE2:
	movs r0, 0x3
	strb r0, [r5]
	movs r0, 0x12
	strb r0, [r5, 0x1]
	movs r0, 0x45
	strb r0, [r5, 0x2]
	b _081B8E72
_081B8DF0:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _081B8E28
	movs r3, 0x1
	mov r2, sp
	ldr r1, =gBattlerPartyIndexes
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, 0
	mov r1, sp
_081B8E0C:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8E1A
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, 0x1
_081B8E1A:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8E0C
	b _081B8E5A
	.pool
_081B8E28:
	movs r3, 0x2
	mov r1, sp
	ldr r2, =gBattlerPartyIndexes
	lsls r0, r4, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	lsls r0, r6, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x1]
	movs r4, 0
_081B8E40:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8E54
	ldrb r0, [r1, 0x1]
	cmp r4, r0
	beq _081B8E54
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, 0x1
_081B8E54:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8E40
_081B8E5A:
	movs r4, 0
	mov r3, sp
_081B8E5E:
	adds r0, r5, r4
	ldrb r1, [r3]
	lsls r1, 4
	ldrb r2, [r3, 0x1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _081B8E5E
_081B8E72:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8D88

	thumb_func_start sub_81B8E80
sub_81B8E80: @ 81B8E80
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r7, 0
	bl sub_81B1250
	lsls r0, 24
	cmp r0, 0
	beq _081B8F2E
	ldr r0, =gBattleStruct
	lsls r1, r4, 1
	adds r1, r4
	adds r1, 0x60
	ldr r0, [r0]
	adds r4, r0, r1
	movs r2, 0
	add r6, sp
	mov r12, r6
	movs r6, 0xF
	mov r3, sp
_081B8EB2:
	adds r1, r4, r2
	ldrb r0, [r1]
	lsrs r0, 4
	strb r0, [r3]
	adds r3, 0x1
	ldrb r1, [r1]
	adds r0, r6, 0
	ands r0, r1
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2
	ble _081B8EB2
	mov r0, r12
	ldrb r3, [r0]
	movs r2, 0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, r5
	bne _081B8EE8
	mov r0, sp
	ldrb r7, [r0]
	strb r3, [r0]
	b _081B8EFC
	.pool
_081B8EE8:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _081B8EFC
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, r5
	bne _081B8EE8
	adds r7, r0, 0
	strb r3, [r1]
_081B8EFC:
	cmp r2, 0x6
	beq _081B8F2E
	mov r0, r12
	strb r7, [r0]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 4
	mov r1, sp
	ldrb r1, [r1, 0x1]
	orrs r0, r1
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	lsls r0, 4
	mov r1, sp
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	strb r0, [r4, 0x1]
	mov r0, sp
	ldrb r0, [r0, 0x4]
	lsls r0, 4
	mov r1, sp
	ldrb r1, [r1, 0x5]
	orrs r0, r1
	strb r0, [r4, 0x2]
_081B8F2E:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81B8E80

	thumb_func_start sub_81B8F38
sub_81B8F38: @ 81B8F38
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0x1
	ands r1, r2
	lsrs r2, r0, 25
	cmp r1, 0
	beq _081B8F58
	ldr r0, =gUnknown_0203CF00
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, 0xF
	ands r1, r0
	b _081B8F60
	.pool
_081B8F58:
	ldr r0, =gUnknown_0203CF00
	adds r0, r2, r0
	ldrb r0, [r0]
	lsrs r1, r0, 4
_081B8F60:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B8F38

	thumb_func_start sub_81B8F6C
sub_81B8F6C: @ 81B8F6C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r1, 0x1
	ands r1, r3
	lsrs r3, r0, 25
	cmp r1, 0
	beq _081B8F94
	ldr r0, =gUnknown_0203CF00
	adds r0, r3, r0
	ldrb r2, [r0]
	movs r1, 0xF0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	b _081B8FA4
	.pool
_081B8F94:
	ldr r2, =gUnknown_0203CF00
	adds r2, r3, r2
	ldrb r1, [r2]
	movs r0, 0xF
	ands r0, r1
	lsls r1, r4, 4
	orrs r0, r1
	strb r0, [r2]
_081B8FA4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8F6C

	thumb_func_start sub_81B8FB0
sub_81B8FB0: @ 81B8FB0
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	adds r0, r5, 0
	bl sub_81B8F38
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_81B8F38
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_81B8F6C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81B8F6C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81B8FB0

	thumb_func_start pokemon_order_func
pokemon_order_func: @ 81B8FEC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	movs r2, 0
	ldr r5, =gUnknown_0203CF00
_081B8FF8:
	adds r0, r3, r5
	ldrb r1, [r0]
	lsrs r0, r1, 4
	cmp r0, r4
	beq _081B9010
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xF
	ands r0, r1
	cmp r0, r4
	bne _081B9018
_081B9010:
	adds r0, r2, 0
	b _081B902A
	.pool
_081B9018:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _081B8FF8
	movs r0, 0
_081B902A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end pokemon_order_func

	thumb_func_start pokemon_change_order
pokemon_change_order: @ 81B9030
	push {r4-r6,lr}
	movs r4, 0x96
	lsls r4, 2
	adds r0, r4, 0
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gPlayerParty
	adds r2, r4, 0
	bl memcpy
	movs r4, 0
	movs r6, 0x64
_081B904A:
	adds r0, r4, 0
	bl pokemon_order_func
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	muls r1, r6
	adds r1, r5
	movs r2, 0x64
	bl memcpy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081B904A
	adds r0, r5, 0
	bl Free
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemon_change_order

	thumb_func_start sub_81B9080
sub_81B9080: @ 81B9080
	push {r4-r6,lr}
	movs r4, 0x96
	lsls r4, 2
	adds r0, r4, 0
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gPlayerParty
	adds r2, r4, 0
	bl memcpy
	movs r4, 0
	movs r6, 0x64
_081B909A:
	adds r0, r4, 0
	bl sub_81B8F38
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	muls r1, r6
	adds r1, r5
	movs r2, 0x64
	bl memcpy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081B909A
	adds r0, r5, 0
	bl Free
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9080

	thumb_func_start sub_81B90D0
sub_81B90D0: @ 81B90D0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0x1
	movs r7, 0x64
	ldr r0, =gPlayerParty
	mov r8, r0
_081B90DE:
	adds r0, r6, 0
	bl sub_81B8F38
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	mov r1, r8
	adds r5, r0, r1
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B912C
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _081B912C
	movs r0, 0
	bl sub_81B8F38
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	adds r1, r6, 0
	bl sub_81B8FB0
	adds r0, r4, 0
	muls r0, r7
	add r0, r8
	adds r1, r5, 0
	bl sub_81B1288
	b _081B9136
	.pool
_081B912C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _081B90DE
_081B9136:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81B90D0

	thumb_func_start sub_81B9140
sub_81B9140: @ 81B9140
	push {lr}
	ldr r0, =SetCB2ToReshowScreenAfterMenu
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9140

	thumb_func_start sub_81B9150
sub_81B9150: @ 81B9150
	push {lr}
	sub sp, 0xC
	movs r0, 0x7F
	str r0, [sp]
	ldr r0, =sub_81B917C
	str r0, [sp, 0x4]
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r0, 0x5
	movs r1, 0x3
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9150

	thumb_func_start sub_81B917C
sub_81B917C: @ 81B917C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r4, 0x8]
	bl sub_81B9294
	movs r1, 0x80
	lsls r1, 9
	movs r0, 0x2
	movs r2, 0
	bl ChangeBgX
	ldr r0, =sub_81B91B4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B917C

	thumb_func_start sub_81B91B4
sub_81B91B4: @ 81B91B4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r6, r5, 2
	adds r0, r6, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B9220
	ldrh r0, [r4]
	subs r0, 0x8
	strh r0, [r4]
	adds r0, r5, 0
	bl sub_81B9294
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081B9220
	movs r4, 0x3
	ldr r7, =gUnknown_02022FF8
_081B91E8:
	subs r0, r4, 0x3
	lsls r0, 5
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, 0
	beq _081B9204
	ldr r0, =gUnknown_0203CEDC
	ldr r1, [r0]
	lsls r0, r4, 4
	adds r0, r1
	ldrb r0, [r0, 0x9]
	movs r1, 0
	bl sub_81B5B6C
_081B9204:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081B91E8
	movs r0, 0x78
	bl PlaySE
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B9240
	str r0, [r1]
_081B9220:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B91B4

	thumb_func_start sub_81B9240
sub_81B9240: @ 81B9240
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	cmp r1, r0
	bne _081B9266
	adds r0, r2, 0
	bl sub_81B12C0
_081B9266:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9240

	thumb_func_start sub_81B9270
sub_81B9270: @ 81B9270
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 16
	lsrs r3, r1, 16
	cmp r1, 0
	blt _081B928A
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strh r3, [r0, 0x24]
_081B928A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9270

	thumb_func_start sub_81B9294
sub_81B9294: @ 81B9294
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r6, 0x3
	ldr r7, =gUnknown_0203CEDC
_081B92A8:
	ldr r0, =gUnknown_02022FF8
	subs r1, r6, 0x3
	lsls r1, 5
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081B9300
	ldr r0, [r7]
	lsls r4, r6, 4
	adds r0, r4, r0
	ldrb r0, [r0, 0x9]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, 0xA]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, 0xB]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
	ldr r0, [r7]
	adds r4, r0
	ldrb r0, [r4, 0xC]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
_081B9300:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _081B92A8
	movs r1, 0x80
	lsls r1, 4
	movs r0, 0x2
	movs r2, 0x1
	bl ChangeBgX
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9294

	thumb_func_start sub_81B9328
sub_81B9328: @ 81B9328
	push {lr}
	sub sp, 0xC
	movs r0, 0xF
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9390
	str r0, [sp, 0x8]
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9328

	thumb_func_start sub_81B9354
sub_81B9354: @ 81B9354
	push {lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gFieldCallback2
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r2]
	movs r1, 0
	str r1, [sp]
	ldr r1, =sub_81B1370
	str r1, [sp, 0x4]
	ldr r1, =CB2_ReturnToField
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9354

	thumb_func_start sub_81B9390
sub_81B9390: @ 81B9390
	push {r4,lr}
	ldr r4, =gSpecialVar_0x8004
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	cmp r0, 0x5
	bls _081B93A6
	movs r0, 0xFF
	strh r0, [r4]
_081B93A6:
	ldr r0, =gFieldCallback2
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r0]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9390

	thumb_func_start hm_add_c3_without_phase_2
hm_add_c3_without_phase_2: @ 81B93C8
	push {lr}
	bl pal_fill_black
	ldr r0, =task_hm_without_phase_2
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end hm_add_c3_without_phase_2

	thumb_func_start task_hm_without_phase_2
task_hm_without_phase_2: @ 81B93E0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsWeatherNotFadingIn
	lsls r0, 24
	cmp r0, 0
	beq _081B93FE
	adds r0, r4, 0
	bl DestroyTask
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
_081B93FE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task_hm_without_phase_2

	thumb_func_start sub_81B9404
sub_81B9404: @ 81B9404
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B9424
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9404

	thumb_func_start sub_81B9424
sub_81B9424: @ 81B9424
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B945C
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9470
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B945C:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9424

	thumb_func_start sub_81B9470
sub_81B9470: @ 81B9470
	push {lr}
	bl GetCursorSelectionMonId
	ldr r2, =gUnknown_02039F24
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _081B9486
	movs r0, 0xFF
	strb r0, [r2]
_081B9486:
	ldr r1, =gSpecialVar_0x8004
	ldrb r0, [r2]
	strh r0, [r1]
	ldr r1, =gFieldCallback2
	ldr r0, =hm_add_c3_without_phase_2
	str r0, [r1]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9470

	thumb_func_start sub_81B94B0
sub_81B94B0: @ 81B94B0
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B94D0
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B94B0

	thumb_func_start sub_81B94D0
sub_81B94D0: @ 81B94D0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B9508
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9390
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B9508:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B94D0

	thumb_func_start sub_81B951C
sub_81B951C: @ 81B951C
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B953C
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B951C

	thumb_func_start sub_81B953C
sub_81B953C: @ 81B953C
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B9574
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9588
	str r0, [sp, 0x8]
	movs r0, 0x7
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B9574:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B953C

	thumb_func_start sub_81B9588
sub_81B9588: @ 81B9588
	push {r4,r5,lr}
	ldr r5, =gSpecialVar_0x8004
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	cmp r0, 0x5
	bls _081B95A4
	movs r0, 0xFF
	strh r0, [r5]
	b _081B95BA
	.pool
_081B95A4:
	ldr r4, =gSpecialVar_0x8005
	ldrh r1, [r5]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNumberOfRelearnableMoves
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
_081B95BA:
	ldr r0, =gFieldCallback2
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r0]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9588

	thumb_func_start sub_81B95E0
sub_81B95E0: @ 81B95E0
	push {r4,r5,lr}
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	movs r4, 0
	adds r5, r1, 0
	b _081B95FA
	.pool
_081B95F4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_081B95FA:
	cmp r4, 0x2
	bhi _081B9614
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	cmp r0, 0
	beq _081B95F4
	movs r0, 0x1
	strh r0, [r5]
_081B9614:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B95E0

	thumb_func_start sub_81B9620
sub_81B9620: @ 81B9620
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B9640
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9620

	thumb_func_start sub_81B9640
sub_81B9640: @ 81B9640
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B9678
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9390
	str r0, [sp, 0x8]
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B9678:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9640

	thumb_func_start sub_81B968C
sub_81B968C: @ 81B968C
	push {lr}
	sub sp, 0x4
	ldr r1, =gPlayerParty
	ldr r0, =gSpecialVar_0x8004
	ldrb r2, [r0]
	ldr r0, =gPlayerPartyCount
	ldrb r3, [r0]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =CB2_ReturnToField
	str r0, [sp]
	movs r0, 0x3
	bl ShowPokemonSummaryScreen
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B968C

	thumb_func_start sub_81B96D0
sub_81B96D0: @ 81B96D0
	push {r4,r5,lr}
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	movs r4, 0
	adds r5, r1, 0
_081B96DC:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	adds r1, 0xD
	bl GetMonData
	cmp r0, 0
	beq _081B96FA
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_081B96FA:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081B96DC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B96D0

	thumb_func_start sub_81B9718
sub_81B9718: @ 81B9718
	push {r4,r5,lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	adds r5, r1, 0
	muls r5, r0
	ldr r0, =gPlayerParty
	adds r5, r0
	ldr r0, =gSpecialVar_0x8005
	ldrh r1, [r0]
	adds r1, 0xD
	adds r0, r5, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r4
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9718

	thumb_func_start sub_81B9770
sub_81B9770: @ 81B9770
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gSpecialVar_0x8004
	mov r8, r0
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	ldr r4, =gSpecialVar_0x8005
	ldrb r2, [r4]
	movs r1, 0
	bl SetMonMoveSlot
	mov r1, r8
	ldrh r0, [r1]
	muls r0, r6
	adds r0, r5
	ldrb r1, [r4]
	bl RemoveMonPPBonus
	ldrh r4, [r4]
	cmp r4, 0x2
	bhi _081B97C4
_081B97A2:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	lsls r1, r4, 24
	lsrs r1, 24
	adds r4, 0x1
	lsls r2, r4, 24
	lsrs r2, 24
	bl sub_81B97DC
	lsls r4, 16
	lsrs r4, 16
	cmp r4, 0x2
	bls _081B97A2
_081B97C4:
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9770

	thumb_func_start sub_81B97DC
sub_81B97DC: @ 81B97DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r0, 0xD
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r1, [sp, 0x8]
	bl GetMonData
	mov r1, sp
	adds r1, 0x2
	str r1, [sp, 0x14]
	strh r0, [r1]
	adds r3, r4, 0
	adds r3, 0xD
	str r3, [sp, 0xC]
	mov r0, r8
	adds r1, r3, 0
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r7, r5, 0
	adds r7, 0x11
	str r7, [sp, 0x10]
	mov r0, r8
	adds r1, r7, 0
	bl GetMonData
	mov r1, sp
	adds r1, 0x5
	str r1, [sp, 0x18]
	strb r0, [r1]
	adds r3, r4, 0
	adds r3, 0x11
	str r3, [sp, 0x1C]
	mov r0, r8
	adds r1, r3, 0
	bl GetMonData
	add r7, sp, 0x4
	mov r10, r7
	strb r0, [r7]
	mov r0, r8
	movs r1, 0x15
	bl GetMonData
	mov r6, sp
	adds r6, 0x6
	strb r0, [r6]
	ldr r1, =gUnknown_08329D22
	adds r0, r5, r1
	ldrb r0, [r0]
	mov r9, r0
	ldrb r0, [r6]
	adds r2, r0, 0
	mov r3, r9
	ands r2, r3
	lsls r5, 1
	asrs r2, r5
	lsls r2, 24
	lsrs r2, 24
	adds r1, r4, r1
	ldrb r3, [r1]
	adds r1, r0, 0
	ands r1, r3
	lsls r4, 1
	asrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	mov r7, r9
	bics r0, r7
	strb r0, [r6]
	ldrb r0, [r6]
	bics r0, r3
	strb r0, [r6]
	lsls r2, r4
	lsls r1, r5
	adds r2, r1
	ldrb r0, [r6]
	orrs r0, r2
	strb r0, [r6]
	mov r0, r8
	ldr r1, [sp, 0x8]
	mov r2, sp
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x14]
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, 0x10]
	mov r2, r10
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, 0x1C]
	ldr r2, [sp, 0x18]
	bl SetMonData
	mov r0, r8
	movs r1, 0x15
	adds r2, r6, 0
	bl SetMonData
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B97DC

	thumb_func_start sub_81B98DC
sub_81B98DC: @ 81B98DC
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0
	beq _081B990C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	b _081B9910
	.pool
_081B990C:
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
_081B9910:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B98DC

	thumb_func_start sub_81B9918
sub_81B9918: @ 81B9918
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	adds r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0x39
	bne _081B999C
	movs r6, 0
	b _081B9980
	.pool
_081B9958:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r6, r0
	beq _081B997E
	movs r4, 0
	movs r0, 0x64
	adds r5, r6, 0
	muls r5, r0
	ldr r7, =gPlayerParty
_081B996A:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r5, r7
	bl GetMonData
	cmp r0, 0x39
	beq _081B999C
	adds r4, 0x1
	cmp r4, 0x3
	bls _081B996A
_081B997E:
	adds r6, 0x1
_081B9980:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bcc _081B9958
	mov r0, r8
	bl sub_80D23A8
	cmp r0, 0x1
	beq _081B999C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081B999C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9918

	.align 2, 0 @ Don't pad with nop.
